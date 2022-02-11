const char * F_1 ( void )
{
return L_1 ;
}
void T_1 F_2 ( void )
{
unsigned char * V_1 ;
unsigned long V_2 ;
V_3 = V_4 ;
V_5 = ( char * * ) V_6 ;
V_7 = ( char * * ) V_8 ;
F_3 () ;
V_1 = F_4 ( L_2 ) ;
if ( ! V_1 || F_5 ( V_1 , 0 , & V_2 ) )
V_2 = 0x04000000 ;
F_6 ( 0 , V_2 , V_9 ) ;
}
void F_7 ( unsigned char V_10 )
{
F_8 ( V_11 , V_10 ) ;
}
static void F_9 ( char * V_10 )
{
__asm__ __volatile__("jr\t%0" : : "r"(0xbfc00000));
}
static void F_10 ( void )
{
while ( 1 )
asm volatile (
" .set mips32 \n"
" wait \n"
" .set mips0 \n");
}
void T_1 F_11 ( void )
{
#if F_12 ( V_12 )
F_13 ( 204 , 0 ) ;
#endif
F_14 ( V_13 , V_14 ) ;
F_14 ( ~ 0 , F_15 ( V_15 ) + V_16 ) ;
F_13 ( 0 , 0 ) ;
F_13 ( 3 , 1 ) ;
F_13 ( 1 , 1 ) ;
F_13 ( 5 , 0 ) ;
F_13 ( 211 , 1 ) ;
F_13 ( 212 , 0 ) ;
V_17 = F_10 ;
V_18 = F_10 ;
V_19 = F_9 ;
F_16 ( V_20 L_3 ) ;
}
static int F_17 ( unsigned int V_21 , int assert )
{
F_18 ( 1 ) ;
if ( assert && V_21 != 0 )
F_19 ( 1 , 0 ) ;
else
F_19 ( 1 , 1 ) ;
F_18 ( 1 ) ;
return 1 ;
}
static int F_20 ( const struct V_22 * V_23 , T_2 V_24 , T_2 V_25 )
{
return V_26 [ V_24 ] [ V_25 ] ;
}
static int T_1 F_21 ( void )
{
int V_27 ;
F_22 ( V_28 , V_29 ) ;
F_22 ( V_30 , V_31 ) ;
F_22 ( V_32 , V_31 ) ;
F_22 ( V_33 , V_31 ) ;
F_22 ( V_34 , V_31 ) ;
F_23 ( 0 , & V_35 ) ;
V_27 = F_24 ( V_36 [ 0 ] . V_37 ,
V_36 [ 0 ] . V_38 ) ;
if ( V_27 < 0 ) {
F_16 ( V_20 L_4 ,
V_36 [ 0 ] . V_37 ) ;
goto V_39;
}
F_25 ( V_36 [ 0 ] . V_37 ) ;
V_39:
return F_26 ( V_40 , F_27 ( V_40 ) ) ;
}
