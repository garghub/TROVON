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
static void F_8 ( void * V_24 )
{
V_10 = F_9 ( V_25 ) ;
F_10 ( * F_11 ( V_26 ) , V_10 ) ;
}
static int F_12 ( struct V_27 * V_28 ,
unsigned long V_29 , void * V_24 )
{
struct V_30 * V_31 = V_24 ;
if ( V_29 == V_32 || V_29 == V_33 )
F_13 ( V_31 -> V_34 , F_8 ,
NULL , 1 ) ;
return V_35 ;
}
static int F_14 ( void )
{
if ( V_26 && * F_11 ( V_26 ) && ! F_15 ( V_25 ) )
return F_16 ( & V_36 ,
V_37 ) ;
return 0 ;
}
static void T_1 F_17 ( void )
{
unsigned long V_38 ;
T_2 V_39 ;
if ( V_10 == 0 ) {
F_18 ( V_40 L_1 ) ;
V_39 = F_19 () + 1 ;
while ( F_19 () < V_39 )
F_20 ( 10 ) ;
V_39 += 5 ;
F_2 ( 0x1 , V_12 + V_18 ) ;
F_2 ( 0xFFFFFFFFU , V_12 + V_21 ) ;
while ( F_19 () < V_39 )
F_20 ( 10 ) ;
V_38 = F_4 ( V_12 + V_21 ) ;
V_10 = ( 0xFFFFFFFFU - V_38 ) * ( V_11 / 5 ) ;
F_18 ( L_2 , V_10 / 1000000 ,
( V_10 / 10000 ) % 100 ) ;
}
}
static T_3 F_21 ( int V_23 , void * V_41 )
{
struct V_3 * V_19 = * (struct V_3 * * ) V_41 ;
if ( F_5 () ) {
V_19 -> V_42 ( V_19 ) ;
return V_43 ;
}
return V_44 ;
}
static struct V_4 * F_22 ( void )
{
struct V_4 * V_4 ;
int V_45 ;
V_4 = F_23 ( L_3 , NULL ) ;
if ( F_15 ( V_4 ) ) {
F_24 ( L_4 , ( int ) F_25 ( V_4 ) ) ;
return V_4 ;
}
V_45 = F_26 ( V_4 ) ;
if ( V_45 ) {
F_24 ( L_5 , V_45 ) ;
F_27 ( V_4 ) ;
return F_28 ( V_45 ) ;
}
V_45 = F_29 ( V_4 ) ;
if ( V_45 ) {
F_24 ( L_6 , V_45 ) ;
F_30 ( V_4 ) ;
F_27 ( V_4 ) ;
return F_28 ( V_45 ) ;
}
return V_4 ;
}
void T_1 F_31 ( struct V_3 * V_4 )
{
struct V_3 * * V_46 ;
if ( ! V_26 ) {
int V_45 ;
V_26 = F_32 ( struct V_3 * ) ;
if ( ! V_26 ) {
F_24 ( L_7 ) ;
return;
}
V_45 = F_33 ( V_4 -> V_23 , F_21 ,
L_8 , V_26 ) ;
if ( V_45 ) {
F_24 ( L_9 ,
V_4 -> V_23 , V_45 ) ;
return;
}
}
if ( ! V_25 )
V_25 = F_22 () ;
if ( ! F_34 ( V_25 ) )
V_10 = F_9 ( V_25 ) ;
else
F_17 () ;
F_2 ( 0 , V_12 + V_18 ) ;
V_4 -> V_47 = L_10 ;
V_4 -> V_48 = V_49 | V_50 |
V_51 ;
V_4 -> V_52 = 350 ;
V_4 -> V_53 = F_1 ;
V_4 -> V_54 = F_3 ;
V_46 = F_11 ( V_26 ) ;
* V_46 = V_4 ;
F_35 ( V_4 , V_10 ,
0xf , 0xffffffff ) ;
F_36 ( V_4 -> V_23 , 0 ) ;
}
