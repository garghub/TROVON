static int T_1 F_1 ( void )
{
return F_2 ( V_1 ,
F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
F_5 ( V_1 ,
F_3 ( V_1 ) ) ;
}
void T_1 F_6 ( int V_2 )
{
int V_3 = 0 ;
switch ( V_2 ) {
case V_4 :
V_3 |= F_7 ( V_5 , V_6 . V_7 ) ;
V_3 |= F_7 ( V_8 , V_6 . V_7 ) ;
V_3 |= F_7 ( V_9 , V_6 . V_7 ) ;
V_3 |= F_7 ( V_10 , V_6 . V_7 ) ;
if ( F_8 ( V_3 ) ) {
F_9 ( L_1 ) ;
return;
}
F_10 ( & V_6 ) ;
break;
case V_11 :
V_3 |= F_7 ( V_12 , V_13 . V_7 ) ;
V_3 |= F_7 ( V_14 , V_13 . V_7 ) ;
V_3 |= F_7 ( V_15 , V_13 . V_7 ) ;
V_3 |= F_7 ( V_16 , V_13 . V_7 ) ;
if ( F_8 ( V_3 ) ) {
F_9 ( L_2 ) ;
return;
}
F_10 ( & V_13 ) ;
break;
default:
F_11 () ;
}
}
void T_1 F_12 ( void )
{
F_13 ( V_17 , F_3 ( V_17 ) ) ;
F_13 ( V_18 , F_3 ( V_18 ) ) ;
F_10 ( & V_19 ) ;
}
void T_1 F_14 ( void )
{
unsigned int V_20 = 1 ;
F_15 ( V_20 ++ , 0x145f0000 , 0x14610000 ) ;
#if 0
setup_bootmem_node(nid++, 0x14df0000, 0x14e10000);
setup_bootmem_node(nid++, 0x155f0000, 0x15610000);
setup_bootmem_node(nid++, 0x15df0000, 0x15e10000);
#endif
F_15 ( V_20 ++ , 0x16000000 , 0x16020000 ) ;
}
