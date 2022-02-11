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
F_23 ( V_45 L_1 ) ;
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
F_23 ( L_2 , V_10 / 1000000 ,
( V_10 / 10000 ) % 100 ) ;
}
}
static T_2 F_26 ( int V_24 , void * V_46 )
{
struct V_3 * V_19 = V_46 ;
if ( F_6 () ) {
V_19 -> V_47 ( V_19 ) ;
return V_48 ;
}
return V_49 ;
}
static void F_27 ( struct V_50 * V_51 )
{
int V_52 ;
if ( V_51 )
V_34 = F_28 ( V_51 , 0 ) ;
else
V_34 = F_29 ( L_3 , NULL ) ;
if ( F_15 ( V_34 ) ) {
F_30 ( L_4 , ( int ) F_31 ( V_34 ) ) ;
return;
}
V_52 = F_32 ( V_34 ) ;
if ( V_52 ) {
F_30 ( L_5 , V_52 ) ;
F_33 ( V_34 ) ;
return;
}
V_10 = F_17 ( V_34 ) ;
}
static void F_34 ( void )
{
struct V_3 * V_4 = F_8 ( V_23 ) ;
int V_40 = F_35 () ;
if ( F_36 ( V_53 , V_40 ) ) {
F_2 ( 0 , V_12 + V_18 ) ;
F_37 ( V_4 ) ;
F_38 ( V_4 -> V_24 , 0 ) ;
return;
}
F_36 ( V_53 , V_40 ) = true ;
F_22 () ;
F_2 ( 0 , V_12 + V_18 ) ;
V_4 -> V_54 = L_6 ;
V_4 -> V_55 = V_56 | V_57 |
V_58 ;
V_4 -> V_59 = 350 ;
V_4 -> V_60 = F_1 ;
V_4 -> V_61 = F_4 ;
V_4 -> V_24 = V_62 ;
V_4 -> V_63 = F_39 ( V_40 ) ;
F_40 ( V_4 , V_10 ,
0xf , 0xffffffff ) ;
F_38 ( V_4 -> V_24 , 0 ) ;
}
static int F_41 ( struct V_26 * V_64 ,
unsigned long V_65 , void * V_66 )
{
switch ( V_65 & ~ V_67 ) {
case V_68 :
F_34 () ;
break;
case V_69 :
F_7 () ;
break;
}
return V_33 ;
}
static int T_3 F_42 ( struct V_50 * V_51 )
{
int V_52 ;
V_23 = F_43 ( struct V_3 ) ;
if ( ! V_23 ) {
V_52 = - V_70 ;
goto V_71;
}
V_52 = F_44 ( V_62 , F_26 , L_7 , V_23 ) ;
if ( V_52 ) {
F_30 ( L_8 , V_62 , V_52 ) ;
goto V_71;
}
V_52 = F_45 ( & V_72 ) ;
if ( V_52 )
goto V_73;
F_27 ( V_51 ) ;
if ( V_10 )
F_34 () ;
else
V_74 = F_34 ;
return 0 ;
V_73:
F_46 ( V_62 , V_23 ) ;
V_71:
F_47 ( V_12 ) ;
V_12 = NULL ;
F_48 ( V_23 ) ;
return V_52 ;
}
int T_3 F_49 ( struct V_75 * V_76 )
{
if ( V_12 || V_23 )
return - V_77 ;
V_62 = V_76 -> V_78 [ 1 ] . V_79 ;
V_12 = F_50 ( V_76 -> V_78 [ 0 ] . V_79 , F_51 ( & V_76 -> V_78 [ 0 ] ) ) ;
if ( ! V_12 )
return - V_70 ;
return F_42 ( NULL ) ;
}
static void T_3 F_52 ( struct V_50 * V_51 )
{
int V_52 ;
if ( ! F_53 () || ! V_80 )
return;
V_62 = F_54 ( V_51 , 0 ) ;
if ( ! V_62 ) {
V_52 = - V_81 ;
goto V_82;
}
V_12 = F_55 ( V_51 , 0 ) ;
if ( ! V_12 ) {
V_52 = - V_70 ;
goto V_82;
}
V_52 = F_42 ( V_51 ) ;
V_82:
F_56 ( V_52 , L_9 , V_52 ) ;
}
