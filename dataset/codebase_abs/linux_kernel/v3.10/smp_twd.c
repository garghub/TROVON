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
static void F_7 ( struct V_3 * V_4 )
{
F_1 ( V_16 , V_4 ) ;
F_8 ( V_4 -> V_23 ) ;
}
static void F_9 ( void * V_24 )
{
V_10 = * ( ( unsigned long * ) V_24 ) ;
F_10 ( * F_11 ( V_25 ) , V_10 ) ;
}
static int F_12 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
if ( V_28 == V_32 )
F_13 ( F_9 ,
( void * ) & V_31 -> V_24 , 1 ) ;
return V_33 ;
}
static int F_14 ( void )
{
if ( V_25 && * F_11 ( V_25 ) && ! F_15 ( V_34 ) )
return F_16 ( V_34 , & V_35 ) ;
return 0 ;
}
static void F_9 ( void * V_29 )
{
V_10 = F_17 ( V_34 ) ;
F_10 ( * F_11 ( V_25 ) , V_10 ) ;
}
static int F_18 ( struct V_26 * V_27 ,
unsigned long V_36 , void * V_29 )
{
struct V_37 * V_38 = V_29 ;
if ( V_36 == V_39 || V_36 == V_40 )
F_19 ( V_38 -> V_41 , F_9 ,
NULL , 1 ) ;
return V_33 ;
}
static int F_20 ( void )
{
if ( V_25 && * F_11 ( V_25 ) && ! F_15 ( V_34 ) )
return F_21 ( & V_42 ,
V_43 ) ;
return 0 ;
}
static void T_1 F_22 ( void )
{
unsigned long V_44 ;
T_2 V_45 ;
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
static T_3 F_26 ( int V_23 , void * V_47 )
{
struct V_3 * V_19 = * (struct V_3 * * ) V_47 ;
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
static int T_1 F_34 ( struct V_3 * V_4 )
{
struct V_3 * * V_54 ;
int V_41 = F_35 () ;
if ( F_36 ( V_55 , V_41 ) ) {
F_2 ( 0 , V_12 + V_18 ) ;
F_37 ( * F_11 ( V_25 ) ) ;
F_38 ( V_4 -> V_23 , 0 ) ;
return 0 ;
}
F_36 ( V_55 , V_41 ) = true ;
F_22 () ;
F_2 ( 0 , V_12 + V_18 ) ;
V_4 -> V_56 = L_6 ;
V_4 -> V_57 = V_58 | V_59 |
V_60 ;
V_4 -> V_61 = 350 ;
V_4 -> V_62 = F_1 ;
V_4 -> V_63 = F_4 ;
V_4 -> V_23 = V_64 ;
V_54 = F_11 ( V_25 ) ;
* V_54 = V_4 ;
F_39 ( V_4 , V_10 ,
0xf , 0xffffffff ) ;
F_38 ( V_4 -> V_23 , 0 ) ;
return 0 ;
}
static int T_4 F_40 ( struct V_51 * V_52 )
{
int V_53 ;
V_25 = F_41 ( struct V_3 * ) ;
if ( ! V_25 ) {
V_53 = - V_65 ;
goto V_66;
}
V_53 = F_42 ( V_64 , F_26 , L_7 , V_25 ) ;
if ( V_53 ) {
F_30 ( L_8 , V_64 , V_53 ) ;
goto V_66;
}
V_53 = F_43 ( & V_67 ) ;
if ( V_53 )
goto V_68;
F_27 ( V_52 ) ;
return 0 ;
V_68:
F_44 ( V_64 , V_25 ) ;
V_66:
F_45 ( V_12 ) ;
V_12 = NULL ;
F_46 ( V_25 ) ;
return V_53 ;
}
int T_4 F_47 ( struct V_69 * V_70 )
{
if ( V_12 || V_25 )
return - V_71 ;
V_64 = V_70 -> V_72 [ 1 ] . V_73 ;
V_12 = F_48 ( V_70 -> V_72 [ 0 ] . V_73 , F_49 ( & V_70 -> V_72 [ 0 ] ) ) ;
if ( ! V_12 )
return - V_65 ;
return F_40 ( NULL ) ;
}
static void T_4 F_50 ( struct V_51 * V_52 )
{
int V_53 ;
if ( ! F_51 () || ! V_74 )
return;
V_64 = F_52 ( V_52 , 0 ) ;
if ( ! V_64 ) {
V_53 = - V_75 ;
goto V_76;
}
V_12 = F_53 ( V_52 , 0 ) ;
if ( ! V_12 ) {
V_53 = - V_65 ;
goto V_76;
}
V_53 = F_40 ( V_52 ) ;
V_76:
F_54 ( V_53 , L_9 , V_53 ) ;
}
