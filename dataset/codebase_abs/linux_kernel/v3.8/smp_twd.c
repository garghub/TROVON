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
static struct V_4 * F_27 ( void )
{
struct V_4 * V_4 ;
int V_51 ;
V_4 = F_28 ( L_3 , NULL ) ;
if ( F_15 ( V_4 ) ) {
F_29 ( L_4 , ( int ) F_30 ( V_4 ) ) ;
return V_4 ;
}
V_51 = F_31 ( V_4 ) ;
if ( V_51 ) {
F_29 ( L_5 , V_51 ) ;
F_32 ( V_4 ) ;
return F_33 ( V_51 ) ;
}
return V_4 ;
}
static int T_1 F_34 ( struct V_3 * V_4 )
{
struct V_3 * * V_52 ;
int V_41 = F_35 () ;
if ( F_36 ( V_53 , V_41 ) ) {
F_2 ( 0 , V_12 + V_18 ) ;
F_37 ( * F_11 ( V_25 ) ) ;
F_38 ( V_4 -> V_23 , 0 ) ;
return 0 ;
}
F_36 ( V_53 , V_41 ) = true ;
if ( ! V_54 ) {
V_34 = F_27 () ;
if ( ! F_39 ( V_34 ) )
V_10 = F_17 ( V_34 ) ;
else
F_22 () ;
V_54 = true ;
}
F_2 ( 0 , V_12 + V_18 ) ;
V_4 -> V_55 = L_6 ;
V_4 -> V_56 = V_57 | V_58 |
V_59 ;
V_4 -> V_60 = 350 ;
V_4 -> V_61 = F_1 ;
V_4 -> V_62 = F_4 ;
V_4 -> V_23 = V_63 ;
V_52 = F_11 ( V_25 ) ;
* V_52 = V_4 ;
F_40 ( V_4 , V_10 ,
0xf , 0xffffffff ) ;
F_38 ( V_4 -> V_23 , 0 ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
int V_51 ;
V_25 = F_42 ( struct V_3 * ) ;
if ( ! V_25 ) {
V_51 = - V_64 ;
goto V_65;
}
V_51 = F_43 ( V_63 , F_26 , L_7 , V_25 ) ;
if ( V_51 ) {
F_29 ( L_8 , V_63 , V_51 ) ;
goto V_65;
}
V_51 = F_44 ( & V_66 ) ;
if ( V_51 )
goto V_67;
return 0 ;
V_67:
F_45 ( V_63 , V_25 ) ;
V_65:
F_46 ( V_12 ) ;
V_12 = NULL ;
F_47 ( V_25 ) ;
return V_51 ;
}
int T_4 F_48 ( struct V_68 * V_69 )
{
if ( V_12 || V_25 )
return - V_70 ;
V_63 = V_69 -> V_71 [ 1 ] . V_72 ;
V_12 = F_49 ( V_69 -> V_71 [ 0 ] . V_72 , F_50 ( & V_69 -> V_71 [ 0 ] ) ) ;
if ( ! V_12 )
return - V_64 ;
return F_41 () ;
}
void T_4 F_51 ( void )
{
struct V_73 * V_74 ;
int V_51 ;
V_74 = F_52 ( NULL , V_75 ) ;
if ( ! V_74 )
return;
V_63 = F_53 ( V_74 , 0 ) ;
if ( ! V_63 ) {
V_51 = - V_76 ;
goto V_77;
}
V_12 = F_54 ( V_74 , 0 ) ;
if ( ! V_12 ) {
V_51 = - V_64 ;
goto V_77;
}
V_51 = F_41 () ;
V_77:
F_55 ( V_51 , L_9 , V_51 ) ;
}
