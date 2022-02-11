static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
switch ( V_3 ) {
case 1 : case 2 : case 8 : case 9 :
case 11 : case 12 : case 13 :
F_2 ( L_1 , V_4 ,
V_3 ) ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
void T_1 F_4 ( void )
{
F_5 ( & V_5 , V_6 , 1 ,
V_7 ) ;
F_6 ( V_8 ) ;
F_7 ( V_9 ) ;
F_7 ( V_10 ) ;
F_8 ( 1 , V_11 ) ;
F_8 ( 0 , V_12 ) ;
}
void F_9 ( unsigned int V_13 , unsigned int V_14 )
{
if ( V_13 == 0 ) {
if ( V_15 )
V_15 = 1 ;
* V_16 = 128 ;
* V_17 = 128 ;
return;
}
if ( V_15 == 0 )
V_15 = 1000 ;
V_15 = V_14 << 1 ;
}
static T_2 F_10 ( int V_3 , void * V_18 )
{
V_19 = V_19 ? 0 : 1 ;
if ( V_15 ) {
unsigned char V_20 = ( V_15 & 1 ) ? 128 - V_21 : 128 + V_21 ;
V_15 -- ;
* V_16 = V_20 ;
* V_17 = V_20 ;
}
if ( ! V_19 )
F_11 ( V_3 , V_18 ) ;
return V_22 ;
}
void F_12 ( T_3 V_23 )
{
int V_24 ;
F_11 = V_23 ;
V_24 = V_25 ;
if ( F_13 ( V_24 , F_10 , 0 ,
L_2 , F_10 ) )
F_14 ( L_3 ) ;
F_8 ( - 1 , V_26 ) ;
F_8 ( 1 , V_27 ) ;
}
static void V_8 ( unsigned int V_3 , struct V_28 * V_29 )
{
unsigned V_30 , V_31 ;
int V_32 ;
V_30 = F_15 ( V_33 ) ;
#ifdef F_16
if ( ( V_30 & V_34 ) &&
( F_15 ( V_35 ) & V_36 ) ) {
F_17 () ;
return;
}
#endif
switch ( V_3 ) {
case 4 :
case 6 :
F_18 ( V_37 , V_29 ) ;
return;
}
if ( V_30 & V_38 ) {
F_18 ( V_25 , V_29 ) ;
F_8 ( - 1 , V_26 ) ;
}
if ( ( V_30 & V_39 ) || ( V_30 & V_34 ) ) {
V_31 = F_15 ( V_35 ) ;
for ( V_32 = 0 ; V_40 [ V_32 ] . V_41 ; V_32 ++ ) {
if ( V_31 & V_40 [ V_32 ] . V_41 ) {
V_3 = V_40 [ V_32 ] . V_3 ;
if ( V_3 > 4 && V_3 <= 15 && V_42 ) {
goto V_43;
}
if ( V_44 [ V_3 ] & V_45 ) {
#ifdef F_19
F_20 ( V_3 ) ;
V_46 = 1 ;
#else
V_29 -> V_47 = ( ( ( V_29 -> V_47 ) & ( ~ 0x700 ) ) + 0x200 ) ;
V_46 = 1 ;
#endif
goto V_43;
}
V_44 [ V_3 ] |= V_45 ;
F_18 ( V_3 , V_29 ) ;
V_44 [ V_3 ] &= ~ V_45 ;
if ( V_46 ) {
#ifdef F_19
if ( V_3 > 4 ) {
V_46 = 0 ;
F_21 ( V_3 ) ;
}
#else
V_46 = 0 ;
#endif
}
return;
}
}
if ( V_31 && V_48 > 0 && ! V_49 ) {
F_2 ( L_4 ,
V_31 ) ;
V_48 -- ;
}
}
V_43:
V_30 = F_15 ( V_33 ) ;
if ( V_30 & V_50 )
F_18 ( V_51 , V_29 ) ;
return;
}
void F_22 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 >= 5 && V_3 <= 15 ) {
V_42 -- ;
if ( V_42 > 0 )
F_2 ( L_5 ) ;
if ( V_42 == 0 )
F_8 ( 1 , V_11 ) ;
}
}
void F_23 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 >= 5 && V_3 <= 15 ) {
F_8 ( 0 , V_11 ) ;
V_42 ++ ;
if ( V_42 > 1 )
F_24 ( L_6 ,
V_42 ) ;
}
}
