static int F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case 1 : case 2 : case 8 : case 9 :
case 11 : case 12 : case 13 :
F_2 ( L_1 , V_2 , V_1 ) ;
return - V_3 ;
}
return 0 ;
}
static void F_3 ( unsigned int V_1 )
{
}
void T_1 F_4 ( void )
{
F_5 ( & V_4 , 1 , V_5 ) ;
F_6 ( V_6 ) ;
F_7 ( V_7 ) ;
F_7 ( V_8 ) ;
F_8 ( 1 , V_9 ) ;
F_8 ( 0 , V_10 ) ;
}
void F_9 ( unsigned int V_11 , unsigned int V_12 )
{
if ( V_11 == 0 ) {
if ( V_13 )
V_13 = 1 ;
* V_14 = 128 ;
* V_15 = 128 ;
return;
}
if ( V_13 == 0 )
V_13 = 1000 ;
V_13 = V_12 << 1 ;
}
static T_2 F_10 ( int V_1 , void * V_16 )
{
V_17 = V_17 ? 0 : 1 ;
if ( V_13 ) {
unsigned char V_18 = ( V_13 & 1 ) ? 128 - V_19 : 128 + V_19 ;
V_13 -- ;
* V_14 = V_18 ;
* V_15 = V_18 ;
}
if ( ! V_17 )
F_11 ( V_1 , V_16 ) ;
return V_20 ;
}
void F_12 ( T_3 V_21 )
{
int V_22 ;
F_11 = V_21 ;
V_22 = V_23 ;
if ( F_13 ( V_22 , F_10 , 0 ,
L_2 , F_10 ) )
F_14 ( L_3 ) ;
F_8 ( - 1 , V_24 ) ;
F_8 ( 1 , V_25 ) ;
}
static void V_6 ( unsigned int V_1 , struct V_26 * V_27 )
{
unsigned V_28 , V_29 ;
int V_30 ;
V_28 = F_15 ( V_31 ) ;
#ifdef F_16
if ( ( V_28 & V_32 ) &&
( F_15 ( V_33 ) & V_34 ) ) {
F_17 () ;
return;
}
#endif
switch ( V_1 ) {
case 4 :
case 6 :
F_18 ( V_35 , V_27 ) ;
return;
}
if ( V_28 & V_36 ) {
F_18 ( V_23 , V_27 ) ;
F_8 ( - 1 , V_24 ) ;
}
if ( ( V_28 & V_37 ) || ( V_28 & V_32 ) ) {
V_29 = F_15 ( V_33 ) ;
for ( V_30 = 0 ; V_38 [ V_30 ] . V_39 ; V_30 ++ ) {
if ( V_29 & V_38 [ V_30 ] . V_39 ) {
V_1 = V_38 [ V_30 ] . V_1 ;
if ( V_1 > 4 && V_1 <= 15 && V_40 ) {
goto V_41;
}
if ( V_42 [ V_1 ] & V_43 ) {
#ifdef F_19
F_20 ( V_1 ) ;
V_44 = 1 ;
#else
V_27 -> V_45 = ( ( ( V_27 -> V_45 ) & ( ~ 0x700 ) ) + 0x200 ) ;
V_44 = 1 ;
#endif
goto V_41;
}
V_42 [ V_1 ] |= V_43 ;
F_18 ( V_1 , V_27 ) ;
V_42 [ V_1 ] &= ~ V_43 ;
if ( V_44 ) {
#ifdef F_19
if ( V_1 > 4 ) {
V_44 = 0 ;
F_21 ( V_1 ) ;
}
#else
V_44 = 0 ;
#endif
}
return;
}
}
if ( V_29 && V_46 > 0 && ! V_47 ) {
F_2 ( L_4 , V_29 ) ;
V_46 -- ;
}
}
V_41:
V_28 = F_15 ( V_31 ) ;
if ( V_28 & V_48 )
F_18 ( V_49 , V_27 ) ;
return;
}
void F_22 ( unsigned int V_1 )
{
if ( V_1 >= 5 && V_1 <= 15 ) {
V_40 -- ;
if ( V_40 > 0 )
F_2 ( L_5 ) ;
if ( V_40 == 0 )
F_8 ( 1 , V_9 ) ;
}
}
void F_23 ( unsigned int V_1 )
{
if ( V_1 >= 5 && V_1 <= 15 ) {
F_8 ( 0 , V_9 ) ;
V_40 ++ ;
if ( V_40 > 1 )
F_2 ( L_6 , V_40 ) ;
}
}
unsigned long F_24 ( void )
{
F_2 ( L_7 ) ;
return - 1 ;
}
int F_25 ( unsigned long V_50 )
{
return - 1 ;
}
