int init_proc()
{
  int (**v0)(void); // rax@1

  v0 = &_gmon_start__;
  if ( &_gmon_start__ )
    LODWORD(v0) = _gmon_start__();
  return (unsigned __int64)v0;
}
int deregister_tm_clones()
{
  signed __int64 v0; // rax@1

  v0 = &unk_601037 - (_UNKNOWN *)&_bss_start;
  if ( (unsigned __int64)(&unk_601037 - (_UNKNOWN *)&_bss_start) > 0xE )
    LODWORD(v0) = 0;
  return v0;
}
int register_tm_clones()
{
  return 0;
}
int _do_global_dtors_aux()
{
  int result; // eax@2

  if ( !_bss_start )
  {
    result = deregister_tm_clones();
    _bss_start = 1;
  }
  return result;
}
int frame_dummy()
{
  return register_tm_clones();
}

signed __int64 __fastcall tick1(__int64 a1)
{
  return a1 - 1;
}
signed __int64 __fastcall tick2(__int64 a1)
{
  return a1 + 1;
}

__int64 __fastcall tick3(__int64 a1, __int64 a2)
{
  __int64 v3; // [sp+10h] [bp-10h]@1
  __int64 i; // [sp+18h] [bp-8h]@1

  v3 = tick6(0LL, a1);
  for ( i = 0LL; i < a2; ++i )
    v3 = tick1(v3);
  return v3;
}

__int64 __fastcall tick4(__int64 a1, __int64 a2)
{
  __int64 v3; // [sp+10h] [bp-10h]@1
  __int64 v4; // [sp+18h] [bp-8h]@1

  v4 = a1;
  v3 = 0LL;
  while ( v4 >= a2 )
  {
    v4 = tick3(v4, a2);
    ++v3;
  }
  return v3;
}
signed __int64 __fastcall tick5(__int64 a1, __int64 a2)
{
  signed __int64 v3; // [sp+10h] [bp-10h]@1
  __int64 i; // [sp+18h] [bp-8h]@1

  v3 = 1LL;
  for ( i = 0LL; i < a1; ++i )
    v3 = tick7(v3, a2);
  return v3;
}
__int64 __fastcall tick6(__int64 a1, __int64 a2)
{
  __int64 v3; // [sp+18h] [bp-18h]@1
  __int64 i; // [sp+20h] [bp-10h]@1
  __int64 j; // [sp+28h] [bp-8h]@4

  v3 = 0LL;
  for ( i = 0LL; i < a1; ++i )
    v3 = tick2(v3);
  for ( j = 0LL; j < a2; ++j )
    v3 = tick2(v3);
  return v3;
}

__int64 __fastcall tick7(__int64 a1, __int64 a2)
{
  __int64 v3; // [sp+10h] [bp-10h]@1
  __int64 i; // [sp+18h] [bp-8h]@1

  v3 = 0LL;
  for ( i = 0LL; i < a1; ++i )
    v3 = tick6(v3, a2);
  return v3;
}
__int64 __fastcall tick8(__int64 a1, __int64 a2)
{
  __int128 v2; // tt@1
  __int64 v3; // ST10_8@1

  *(_QWORD *)&v2 = a1;
  *((_QWORD *)&v2 + 1) = (unsigned __int128)a1 >> 64;
  v3 = tick7(v2 / a2, a2);
  return tick3(a1, v3);
}

int __cdecl main(int argc, const char **argv, const char **envp)
{
  __int64 v4; // [sp+0h] [bp-30h]@0
  __int64 v5; // [sp+8h] [bp-28h]@0
  __int64 v6; // [sp+10h] [bp-20h]@0
  __int64 v7; // [sp+18h] [bp-18h]@0
  __int64 v8; // [sp+20h] [bp-10h]@1
  __int64 i; // [sp+28h] [bp-8h]@1

  printf(
    "This is your ticket to travel to Canda !\n"
    "All what you have to do is to wait until the flag is displayed !\n"
    "Trust me !",
    argv,
    envp);
  v8 = 0LL;
  for ( i = 0LL; i <= 1193046; ++i )
  {
    v7 = tick4(i, 41LL);
    v6 = tick5(v7, 3LL);
    v5 = tick6(v6, v8);
    v4 = tick7(v5, i);
    v8 = tick8(v4, -81986143110479071LL);
  }
  printf("Thank you for your patience ! Here is the flag: hackfest{%u}\n", v8, v4, v5, v6, v7);
  return 0;
}
