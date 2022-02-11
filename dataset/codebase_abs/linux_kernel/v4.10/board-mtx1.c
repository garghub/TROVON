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
F_14 ( ~ 0 , V_15 ) ;
F_13 ( 0 , 0 ) ;
F_13 ( 3 , 1 ) ;
F_13 ( 1 , 1 ) ;
F_13 ( 5 , 0 ) ;
F_13 ( 211 , 1 ) ;
F_13 ( 212 , 0 ) ;
V_16 = F_10 ;
V_17 = F_10 ;
V_18 = F_9 ;
F_15 ( V_19 L_3 ) ;
}
static int F_16 ( unsigned int V_20 , int assert )
{
F_17 ( 1 ) ;
if ( assert && V_20 != 0 )
F_18 ( 1 , 0 ) ;
else
F_18 ( 1 , 1 ) ;
F_17 ( 1 ) ;
return 1 ;
}
static int F_19 ( const struct V_21 * V_22 , T_2 V_23 , T_2 V_24 )
{
return V_25 [ V_23 ] [ V_24 ] ;
}
static int T_1 F_20 ( void )
{
int V_26 ;
F_21 ( V_27 , V_28 ) ;
F_21 ( V_29 , V_30 ) ;
F_21 ( V_31 , V_30 ) ;
F_21 ( V_32 , V_30 ) ;
F_21 ( V_33 , V_30 ) ;
F_22 ( 0 , & V_34 ) ;
V_26 = F_23 ( V_35 [ 0 ] . V_36 ,
V_35 [ 0 ] . V_37 ) ;
if ( V_26 < 0 ) {
F_15 ( V_19 L_4 ,
V_35 [ 0 ] . V_36 ) ;
goto V_38;
}
F_24 ( V_35 [ 0 ] . V_36 ) ;
V_38:
return F_25 ( V_39 , F_26 ( V_39 ) ) ;
}
