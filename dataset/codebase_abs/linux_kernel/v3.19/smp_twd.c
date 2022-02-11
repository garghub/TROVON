static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
switch ( V_2 ) {
case V_6 :
V_5 = V_7 | V_8
| V_9 ;
F_2 ( F_3 ( V_10 , V_11 ) ,
V_12 + V_13 ) ;
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
static int F_4 ( unsigned long V_19 ,
struct V_3 * V_20 )
{
unsigned long V_5 = F_5 ( V_12 + V_18 ) ;
V_5 |= V_7 ;
F_2 ( V_19 , V_12 + V_21 ) ;
F_2 ( V_5 , V_12 + V_18 ) ;
return 0 ;
}
static int F_6 ( void )
{
if ( F_5 ( V_12 + V_22 ) ) {
F_2 ( 1 , V_12 + V_22 ) ;
return 1 ;
}
return 0 ;
}
static void F_7 ( void )
{
struct V_3 * V_4 = F_8 ( V_23 ) ;
F_1 ( V_16 , V_4 ) ;
F_9 ( V_4 -> V_24 ) ;
}
static void F_10 ( void * V_25 )
{
V_10 = * ( ( unsigned long * ) V_25 ) ;
F_11 ( F_8 ( V_23 ) , V_10 ) ;
}
static int F_12 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
if ( V_28 == V_32 )
F_13 ( F_10 ,
( void * ) & V_31 -> V_25 , 1 ) ;
return V_33 ;
}
static int F_14 ( void )
{
if ( V_23 && F_8 ( V_23 ) && ! F_15 ( V_34 ) )
return F_16 ( V_34 , & V_35 ) ;
return 0 ;
}
static void F_10 ( void * V_29 )
{
V_10 = F_17 ( V_34 ) ;
F_11 ( F_8 ( V_23 ) , V_10 ) ;
}
static int F_18 ( struct V_26 * V_27 ,
unsigned long V_36 , void * V_29 )
{
struct V_37 * V_38 = V_29 ;
if ( V_36 == V_39 )
F_19 ( V_38 -> V_40 , F_10 ,
NULL , 1 ) ;
return V_33 ;
}
static int F_20 ( void )
{
if ( V_23 && F_8 ( V_23 ) && ! F_15 ( V_34 ) )
return F_21 ( & V_41 ,
V_42 ) ;
return 0 ;
}
static void F_22 ( void )
{
unsigned long V_43 ;
T_1 V_44 ;
if ( V_10 == 0 ) {
F_23 ( L_1 ) ;
V_44 = F_24 () + 1 ;
while ( F_24 () < V_44 )
F_25 ( 10 ) ;
V_44 += 5 ;
F_2 ( 0x1 , V_12 + V_18 ) ;
F_2 ( 0xFFFFFFFFU , V_12 + V_21 ) ;
while ( F_24 () < V_44 )
F_25 ( 10 ) ;
V_43 = F_5 ( V_12 + V_21 ) ;
V_10 = ( 0xFFFFFFFFU - V_43 ) * ( V_11 / 5 ) ;
F_26 ( L_2 , V_10 / 1000000 ,
( V_10 / 10000 ) % 100 ) ;
}
}
static T_2 F_27 ( int V_24 , void * V_45 )
{
struct V_3 * V_19 = V_45 ;
if ( F_6 () ) {
V_19 -> V_46 ( V_19 ) ;
return V_47 ;
}
return V_48 ;
}
static void F_28 ( struct V_49 * V_50 )
{
int V_51 ;
if ( V_50 )
V_34 = F_29 ( V_50 , 0 ) ;
else
V_34 = F_30 ( L_3 , NULL ) ;
if ( F_15 ( V_34 ) ) {
F_31 ( L_4 , ( int ) F_32 ( V_34 ) ) ;
return;
}
V_51 = F_33 ( V_34 ) ;
if ( V_51 ) {
F_31 ( L_5 , V_51 ) ;
F_34 ( V_34 ) ;
return;
}
V_10 = F_17 ( V_34 ) ;
}
static void F_35 ( void )
{
struct V_3 * V_4 = F_8 ( V_23 ) ;
int V_40 = F_36 () ;
if ( F_37 ( V_52 , V_40 ) ) {
F_2 ( 0 , V_12 + V_18 ) ;
F_38 ( V_4 ) ;
F_39 ( V_4 -> V_24 , 0 ) ;
return;
}
F_37 ( V_52 , V_40 ) = true ;
F_22 () ;
F_2 ( 0 , V_12 + V_18 ) ;
V_4 -> V_53 = L_6 ;
V_4 -> V_54 = V_55 | V_56 |
V_57 ;
V_4 -> V_58 = 350 ;
V_4 -> V_59 = F_1 ;
V_4 -> V_60 = F_4 ;
V_4 -> V_24 = V_61 ;
V_4 -> V_62 = F_40 ( V_40 ) ;
F_41 ( V_4 , V_10 ,
0xf , 0xffffffff ) ;
F_39 ( V_4 -> V_24 , 0 ) ;
}
static int F_42 ( struct V_26 * V_63 ,
unsigned long V_64 , void * V_65 )
{
switch ( V_64 & ~ V_66 ) {
case V_67 :
F_35 () ;
break;
case V_68 :
F_7 () ;
break;
}
return V_33 ;
}
static int T_3 F_43 ( struct V_49 * V_50 )
{
int V_51 ;
V_23 = F_44 ( struct V_3 ) ;
if ( ! V_23 ) {
V_51 = - V_69 ;
goto V_70;
}
V_51 = F_45 ( V_61 , F_27 , L_7 , V_23 ) ;
if ( V_51 ) {
F_31 ( L_8 , V_61 , V_51 ) ;
goto V_70;
}
V_51 = F_46 ( & V_71 ) ;
if ( V_51 )
goto V_72;
F_28 ( V_50 ) ;
if ( V_10 )
F_35 () ;
else
V_73 = F_35 ;
return 0 ;
V_72:
F_47 ( V_61 , V_23 ) ;
V_70:
F_48 ( V_12 ) ;
V_12 = NULL ;
F_49 ( V_23 ) ;
return V_51 ;
}
int T_3 F_50 ( struct V_74 * V_75 )
{
if ( V_12 || V_23 )
return - V_76 ;
V_61 = V_75 -> V_77 [ 1 ] . V_78 ;
V_12 = F_51 ( V_75 -> V_77 [ 0 ] . V_78 , F_52 ( & V_75 -> V_77 [ 0 ] ) ) ;
if ( ! V_12 )
return - V_69 ;
return F_43 ( NULL ) ;
}
static void T_3 F_53 ( struct V_49 * V_50 )
{
int V_51 ;
if ( ! F_54 () || ! V_79 )
return;
V_61 = F_55 ( V_50 , 0 ) ;
if ( ! V_61 ) {
V_51 = - V_80 ;
goto V_81;
}
V_12 = F_56 ( V_50 , 0 ) ;
if ( ! V_12 ) {
V_51 = - V_69 ;
goto V_81;
}
V_51 = F_43 ( V_50 ) ;
V_81:
F_57 ( V_51 , L_9 , V_51 ) ;
}
