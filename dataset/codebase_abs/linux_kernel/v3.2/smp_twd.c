static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
switch ( V_2 ) {
case V_6 :
V_5 = V_7 | V_8
| V_9 ;
F_2 ( V_10 / V_11 , V_12 + V_13 ) ;
break;
case V_14 :
V_5 = V_8 | V_15 ;
break;
case V_16 :
case V_17 :
default:
V_5 = 0 ;
}
F_2 ( V_5 , V_12 + V_18 ) ;
}
static int F_3 ( unsigned long V_19 ,
struct V_3 * V_20 )
{
unsigned long V_5 = F_4 ( V_12 + V_18 ) ;
V_5 |= V_7 ;
F_2 ( V_19 , V_12 + V_21 ) ;
F_2 ( V_5 , V_12 + V_18 ) ;
return 0 ;
}
int F_5 ( void )
{
if ( F_4 ( V_12 + V_22 ) ) {
F_2 ( 1 , V_12 + V_22 ) ;
return 1 ;
}
return 0 ;
}
void F_6 ( struct V_3 * V_4 )
{
F_1 ( V_16 , V_4 ) ;
F_7 ( V_4 -> V_23 ) ;
}
static void T_1 F_8 ( void )
{
unsigned long V_24 ;
T_2 V_25 ;
if ( V_10 == 0 ) {
F_9 ( V_26 L_1 ) ;
V_25 = F_10 () + 1 ;
while ( F_10 () < V_25 )
F_11 ( 10 ) ;
V_25 += 5 ;
F_2 ( 0x1 , V_12 + V_18 ) ;
F_2 ( 0xFFFFFFFFU , V_12 + V_21 ) ;
while ( F_10 () < V_25 )
F_11 ( 10 ) ;
V_24 = F_4 ( V_12 + V_21 ) ;
V_10 = ( 0xFFFFFFFFU - V_24 ) * ( V_11 / 5 ) ;
F_9 ( L_2 , V_10 / 1000000 ,
( V_10 / 10000 ) % 100 ) ;
}
}
static T_3 F_12 ( int V_23 , void * V_27 )
{
struct V_3 * V_19 = * (struct V_3 * * ) V_27 ;
if ( F_5 () ) {
V_19 -> V_28 ( V_19 ) ;
return V_29 ;
}
return V_30 ;
}
void T_1 F_13 ( struct V_3 * V_4 )
{
struct V_3 * * V_31 ;
if ( ! V_32 ) {
int V_33 ;
V_32 = F_14 ( struct V_3 * ) ;
if ( ! V_32 ) {
F_15 ( L_3 ) ;
return;
}
V_33 = F_16 ( V_4 -> V_23 , F_12 ,
L_4 , V_32 ) ;
if ( V_33 ) {
F_15 ( L_5 ,
V_4 -> V_23 , V_33 ) ;
return;
}
}
F_8 () ;
V_4 -> V_34 = L_6 ;
V_4 -> V_35 = V_36 | V_37 |
V_38 ;
V_4 -> V_39 = 350 ;
V_4 -> V_40 = F_1 ;
V_4 -> V_41 = F_3 ;
V_4 -> V_42 = 20 ;
V_4 -> V_43 = F_17 ( V_10 , V_44 , V_4 -> V_42 ) ;
V_4 -> V_45 = F_18 ( 0xffffffff , V_4 ) ;
V_4 -> V_46 = F_18 ( 0xf , V_4 ) ;
V_31 = F_19 ( V_32 ) ;
* V_31 = V_4 ;
F_20 ( V_4 ) ;
F_21 ( V_4 -> V_23 , 0 ) ;
}
