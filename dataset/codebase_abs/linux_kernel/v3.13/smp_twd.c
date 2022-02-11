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
if ( V_36 == V_39 || V_36 == V_40 )
F_19 ( V_38 -> V_41 , F_10 ,
NULL , 1 ) ;
return V_33 ;
}
static int F_20 ( void )
{
if ( V_23 && F_8 ( V_23 ) && ! F_15 ( V_34 ) )
return F_21 ( & V_42 ,
V_43 ) ;
return 0 ;
}
static void F_22 ( void )
{
unsigned long V_44 ;
T_1 V_45 ;
if ( V_10 == 0 ) {
F_23 ( V_46 L_1 ) ;
V_45 = F_24 () + 1 ;
while ( F_24 () < V_45 )
F_25 ( 10 ) ;
V_45 += 5 ;
F_2 ( 0x1 , V_12 + V_18 ) ;
F_2 ( 0xFFFFFFFFU , V_12 + V_21 ) ;
while ( F_24 () < V_45 )
F_25 ( 10 ) ;
V_44 = F_5 ( V_12 + V_21 ) ;
V_10 = ( 0xFFFFFFFFU - V_44 ) * ( V_11 / 5 ) ;
F_23 ( L_2 , V_10 / 1000000 ,
( V_10 / 10000 ) % 100 ) ;
}
}
static T_2 F_26 ( int V_24 , void * V_47 )
{
struct V_3 * V_19 = V_47 ;
if ( F_6 () ) {
V_19 -> V_48 ( V_19 ) ;
return V_49 ;
}
return V_50 ;
}
static void F_27 ( struct V_51 * V_52 )
{
int V_53 ;
if ( V_52 )
V_34 = F_28 ( V_52 , 0 ) ;
else
V_34 = F_29 ( L_3 , NULL ) ;
if ( F_15 ( V_34 ) ) {
F_30 ( L_4 , ( int ) F_31 ( V_34 ) ) ;
return;
}
V_53 = F_32 ( V_34 ) ;
if ( V_53 ) {
F_30 ( L_5 , V_53 ) ;
F_33 ( V_34 ) ;
return;
}
V_10 = F_17 ( V_34 ) ;
}
static void F_34 ( void )
{
struct V_3 * V_4 = F_8 ( V_23 ) ;
int V_41 = F_35 () ;
if ( F_36 ( V_54 , V_41 ) ) {
F_2 ( 0 , V_12 + V_18 ) ;
F_37 ( V_4 ) ;
F_38 ( V_4 -> V_24 , 0 ) ;
return;
}
F_36 ( V_54 , V_41 ) = true ;
F_22 () ;
F_2 ( 0 , V_12 + V_18 ) ;
V_4 -> V_55 = L_6 ;
V_4 -> V_56 = V_57 | V_58 |
V_59 ;
V_4 -> V_60 = 350 ;
V_4 -> V_61 = F_1 ;
V_4 -> V_62 = F_4 ;
V_4 -> V_24 = V_63 ;
V_4 -> V_64 = F_39 ( V_41 ) ;
F_40 ( V_4 , V_10 ,
0xf , 0xffffffff ) ;
F_38 ( V_4 -> V_24 , 0 ) ;
}
static int F_41 ( struct V_26 * V_65 ,
unsigned long V_66 , void * V_67 )
{
switch ( V_66 & ~ V_68 ) {
case V_69 :
F_34 () ;
break;
case V_70 :
F_7 () ;
break;
}
return V_33 ;
}
static int T_3 F_42 ( struct V_51 * V_52 )
{
int V_53 ;
V_23 = F_43 ( struct V_3 ) ;
if ( ! V_23 ) {
V_53 = - V_71 ;
goto V_72;
}
V_53 = F_44 ( V_63 , F_26 , L_7 , V_23 ) ;
if ( V_53 ) {
F_30 ( L_8 , V_63 , V_53 ) ;
goto V_72;
}
V_53 = F_45 ( & V_73 ) ;
if ( V_53 )
goto V_74;
F_27 ( V_52 ) ;
if ( V_10 )
F_34 () ;
else
V_75 = F_34 ;
return 0 ;
V_74:
F_46 ( V_63 , V_23 ) ;
V_72:
F_47 ( V_12 ) ;
V_12 = NULL ;
F_48 ( V_23 ) ;
return V_53 ;
}
int T_3 F_49 ( struct V_76 * V_77 )
{
if ( V_12 || V_23 )
return - V_78 ;
V_63 = V_77 -> V_79 [ 1 ] . V_80 ;
V_12 = F_50 ( V_77 -> V_79 [ 0 ] . V_80 , F_51 ( & V_77 -> V_79 [ 0 ] ) ) ;
if ( ! V_12 )
return - V_71 ;
return F_42 ( NULL ) ;
}
static void T_3 F_52 ( struct V_51 * V_52 )
{
int V_53 ;
if ( ! F_53 () || ! V_81 )
return;
V_63 = F_54 ( V_52 , 0 ) ;
if ( ! V_63 ) {
V_53 = - V_82 ;
goto V_83;
}
V_12 = F_55 ( V_52 , 0 ) ;
if ( ! V_12 ) {
V_53 = - V_71 ;
goto V_83;
}
V_53 = F_42 ( V_52 ) ;
V_83:
F_56 ( V_53 , L_9 , V_53 ) ;
}
