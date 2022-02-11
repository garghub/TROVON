unsigned long F_1 ( unsigned long V_1 , unsigned long * V_2 )
{
unsigned int V_3 ;
unsigned int V_4 , V_5 , V_6 ;
unsigned int V_7 ;
unsigned int V_8 , V_9 , V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
V_10 = 0 ;
if ( V_13 )
F_2 ( V_14 L_1 ) ;
V_3 = F_3 () ;
if ( ! ( V_3 ) ) {
if ( V_13 )
F_2 ( V_14 L_2 ) ;
return 0 ;
}
if ( ! F_4 ( F_5 ( V_3 ) ) ) {
if ( V_13 )
F_2 ( V_14
L_3 ,
F_5 ( V_3 ) ) ;
return 0 ;
}
V_11 = F_6 () ;
if ( V_13 )
F_2 ( V_14 L_4 , V_11 ) ;
V_4 = F_7 ( V_3 + ( V_11 * 4 ) ) ;
if ( ( ( V_4 & V_15 ) == V_16 ) ) {
if ( V_13 )
F_2 ( V_14 L_5 ) ;
V_8 = 3 ;
V_9 = V_4 ;
V_10 = V_4 & V_17 ;
goto V_18;
}
if ( ( ( V_4 & V_15 ) != V_19 ) ) {
if ( V_13 )
F_2 ( V_14 L_6 ) ;
return 0 ;
}
if ( V_13 )
F_2 ( V_14 L_7 , V_4 ) ;
V_7 = ( V_4 & V_20 ) << 4 ;
V_7 += ( ( ( ( V_1 ) >> V_21 ) & V_22 ) * 4 ) ;
if ( ! F_4 ( F_5 ( V_7 ) ) )
return 0 ;
V_5 = F_7 ( V_7 ) ;
if ( ( ( V_5 & V_15 ) == V_16 ) ) {
if ( V_13 )
F_2 ( V_14 L_8 ) ;
V_8 = 2 ;
V_9 = V_5 ;
V_10 = V_5 & V_17 ;
goto V_18;
}
if ( ( ( V_5 & V_15 ) != V_19 ) ) {
if ( V_13 )
F_2 ( V_14 L_9 ) ;
return 0 ;
}
if ( V_13 )
F_2 ( V_14 L_10 , V_5 ) ;
V_7 = ( V_5 & V_20 ) << 4 ;
V_7 += ( ( ( V_1 >> V_23 ) & V_24 ) * 4 ) ;
if ( ! F_4 ( F_5 ( V_7 ) ) ) {
if ( V_13 )
F_2 ( V_14 L_3 ,
F_5 ( V_7 ) ) ;
return 0 ;
}
V_6 = F_7 ( V_7 ) ;
if ( ( ( V_6 & V_15 ) == V_16 ) ) {
if ( V_13 )
F_2 ( V_14 L_11 ) ;
V_8 = 1 ;
V_9 = V_6 ;
V_10 = V_6 & V_17 ;
goto V_18;
}
if ( ( ( V_6 & V_15 ) != V_19 ) ) {
if ( V_13 )
F_2 ( V_14 L_12 ) ;
return 0 ;
}
if ( V_13 )
F_2 ( V_14 L_13 , V_6 ) ;
V_7 = ( V_6 & V_20 ) << 4 ;
V_7 += ( ( ( V_1 >> V_25 ) & V_26 ) * 4 ) ;
if ( ! F_4 ( F_5 ( V_7 ) ) )
return 0 ;
V_7 = F_7 ( V_7 ) ;
if ( ( ( V_7 & V_15 ) == V_16 ) ) {
if ( V_13 )
F_2 ( V_14 L_14 ) ;
V_8 = 0 ;
V_9 = V_7 ;
V_10 = V_7 & V_17 ;
goto V_18;
}
if ( V_13 )
F_2 ( V_14 L_15 ) ;
return 0 ;
V_18:
switch ( V_8 ) {
case 0 :
V_12 =
( V_1 & ~ ( - 1 << V_25 ) ) | ( ( V_9 & ~ 0xff ) << 4 ) ;
break;
case 1 :
V_12 =
( V_1 & ~ ( - 1 << V_23 ) ) | ( ( V_9 & ~ 0xff ) << 4 ) ;
break;
case 2 :
V_12 =
( V_1 & ~ ( - 1 << V_21 ) ) | ( ( V_9 & ~ 0xff ) << 4 ) ;
break;
default:
case 3 :
V_12 = V_1 ;
break;
}
if ( V_13 )
F_2 ( V_14 L_16 , V_12 ) ;
if ( V_2 )
* V_2 = V_12 ;
return V_10 ;
}
void F_8 ( void )
{
__asm__ __volatile__(" flush ");
}
void F_9 ( void )
{
__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
"i"(ASI_LEON_DFLUSH) : "memory");
}
void F_10 ( struct V_27 * V_28 , unsigned long V_29 )
{
if ( V_28 -> V_30 & V_31 )
F_8 () ;
F_9 () ;
}
void F_11 ( void )
{
__asm__ __volatile__(" flush ");
__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
"i"(ASI_LEON_DFLUSH) : "memory");
}
void F_12 ( void )
{
F_11 () ;
__asm__ __volatile__("sta %%g0, [%0] %1\n\t" : : "r"(0x400),
"i"(ASI_LEON_MMUFLUSH) : "memory");
}
void F_13 ( struct V_32 * V_33 )
{
unsigned long V_34 , V_35 , V_36 ;
if ( ! V_33 )
return;
__asm__ __volatile__("lda [%%g0] %3, %0\n\t"
"mov 0x08, %%g1\n\t"
"lda [%%g1] %3, %1\n\t"
"mov 0x0c, %%g1\n\t"
"lda [%%g1] %3, %2\n\t"
: "=r"(ccr), "=r"(iccr), "=r"(dccr)
: "i"(ASI_LEON_CACHEREGS)
: "g1"
);
V_33 -> V_34 = V_34 ;
V_33 -> V_35 = V_35 ;
V_33 -> V_36 = V_36 ;
}
int T_1 F_14 ( void )
{
int V_37 = - 1 ;
unsigned int V_38 , V_39 ;
char * V_40 [ 4 ] =
{ L_17 , L_18 , L_19 ,
L_20
} ;
struct V_32 V_41 ;
F_13 ( & V_41 ) ;
V_39 = ( V_41 . V_36 & V_42 ) >> 24 ;
V_38 = 1 << ( ( V_41 . V_36 & V_43 ) >> 20 ) ;
F_2 ( V_14 L_21 ,
V_39 > 3 ? L_22 : V_40 [ V_39 ] , V_38 ) ;
if ( ( V_38 <= ( V_44 / 1024 ) ) && ( V_39 == 0 ) ) {
V_37 = 0 ;
F_2 ( V_14 L_23 ) ;
}
return V_37 ;
}
void F_15 ( void )
{
F_16 ( ( void * ) 0 ) ;
if ( V_45 )
F_11 () ;
}
