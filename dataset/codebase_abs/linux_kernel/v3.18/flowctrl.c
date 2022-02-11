static void F_1 ( T_1 V_1 , T_2 V_2 )
{
F_2 ( V_2 , V_3 + V_1 ) ;
F_3 () ;
F_4 ( V_3 + V_1 ) ;
}
T_2 F_5 ( unsigned int V_4 )
{
T_1 V_1 = V_5 [ V_4 ] ;
return F_6 ( V_3 + V_1 ) ;
}
void F_7 ( unsigned int V_4 , T_2 V_2 )
{
return F_1 ( V_5 [ V_4 ] , V_2 ) ;
}
void F_8 ( unsigned int V_4 , T_2 V_2 )
{
return F_1 ( V_6 [ V_4 ] , V_2 ) ;
}
void F_9 ( unsigned int V_4 )
{
unsigned int V_7 ;
int V_8 ;
V_7 = F_5 ( V_4 ) ;
switch ( F_10 () ) {
case V_9 :
V_7 &= ~ V_10 ;
V_7 &= ~ V_11 ;
V_7 |= V_12 << V_4 ;
break;
case V_13 :
case V_14 :
case V_15 :
V_7 &= ~ V_16 ;
V_7 &= ~ V_17 ;
V_7 |= V_18 << V_4 ;
break;
}
V_7 |= V_19 ;
V_7 |= V_20 ;
V_7 |= V_21 ;
F_7 ( V_4 , V_7 ) ;
for ( V_8 = 0 ; V_8 < F_11 () ; V_8 ++ ) {
if ( V_8 == V_4 )
continue;
V_7 = F_5 ( V_8 ) ;
V_7 |= V_20 ;
V_7 |= V_19 ;
F_7 ( V_8 , V_7 ) ;
}
}
void F_12 ( unsigned int V_4 )
{
unsigned int V_7 ;
V_7 = F_5 ( V_4 ) ;
switch ( F_10 () ) {
case V_9 :
V_7 &= ~ V_10 ;
V_7 &= ~ V_11 ;
break;
case V_13 :
case V_14 :
case V_15 :
V_7 &= ~ V_16 ;
V_7 &= ~ V_17 ;
break;
}
V_7 &= ~ V_21 ;
V_7 |= V_19 ;
V_7 |= V_20 ;
F_7 ( V_4 , V_7 ) ;
}
void T_3 F_13 ( void )
{
unsigned long V_22 = 0x60007000 ;
unsigned long V_23 = V_24 ;
struct V_25 * V_26 ;
V_26 = F_14 ( NULL , V_27 ) ;
if ( V_26 ) {
struct V_28 V_29 ;
if ( F_15 ( V_26 , 0 , & V_29 ) == 0 ) {
V_23 = F_16 ( & V_29 ) ;
V_22 = V_29 . V_30 ;
}
F_17 ( V_26 ) ;
}
V_3 = F_18 ( V_22 , V_23 ) ;
}
