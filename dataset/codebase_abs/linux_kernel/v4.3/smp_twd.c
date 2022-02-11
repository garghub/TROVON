static int F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_3 + V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_2 ( V_5 | V_6 ,
V_3 + V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned long V_7 = V_8 |
V_5 |
V_9 ;
F_2 ( F_5 ( V_10 , V_11 ) ,
V_3 + V_12 ) ;
F_2 ( V_7 , V_3 + V_4 ) ;
return 0 ;
}
static int F_6 ( unsigned long V_13 ,
struct V_1 * V_14 )
{
unsigned long V_7 = F_7 ( V_3 + V_4 ) ;
V_7 |= V_8 ;
F_2 ( V_13 , V_3 + V_15 ) ;
F_2 ( V_7 , V_3 + V_4 ) ;
return 0 ;
}
static int F_8 ( void )
{
if ( F_7 ( V_3 + V_16 ) ) {
F_2 ( 1 , V_3 + V_16 ) ;
return 1 ;
}
return 0 ;
}
static void F_9 ( void )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 -> V_18 ) ;
}
static void F_12 ( void * V_19 )
{
V_10 = * ( ( unsigned long * ) V_19 ) ;
F_13 ( F_10 ( V_17 ) , V_10 ) ;
}
static int F_14 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
struct V_24 * V_25 = V_23 ;
if ( V_22 == V_26 )
F_15 ( F_12 ,
( void * ) & V_25 -> V_19 , 1 ) ;
return V_27 ;
}
static int F_16 ( void )
{
if ( V_17 && F_10 ( V_17 ) && ! F_17 ( V_28 ) )
return F_18 ( V_28 , & V_29 ) ;
return 0 ;
}
static void F_12 ( void * V_23 )
{
V_10 = F_19 ( V_28 ) ;
F_13 ( F_10 ( V_17 ) , V_10 ) ;
}
static int F_20 ( struct V_20 * V_21 ,
unsigned long V_30 , void * V_23 )
{
struct V_31 * V_32 = V_23 ;
if ( V_30 == V_33 )
F_21 ( V_32 -> V_34 , F_12 ,
NULL , 1 ) ;
return V_27 ;
}
static int F_22 ( void )
{
if ( V_17 && F_10 ( V_17 ) && ! F_17 ( V_28 ) )
return F_23 ( & V_35 ,
V_36 ) ;
return 0 ;
}
static void F_24 ( void )
{
unsigned long V_37 ;
T_1 V_38 ;
if ( V_10 == 0 ) {
F_25 ( L_1 ) ;
V_38 = F_26 () + 1 ;
while ( F_26 () < V_38 )
F_27 ( 10 ) ;
V_38 += 5 ;
F_2 ( 0x1 , V_3 + V_4 ) ;
F_2 ( 0xFFFFFFFFU , V_3 + V_15 ) ;
while ( F_26 () < V_38 )
F_27 ( 10 ) ;
V_37 = F_7 ( V_3 + V_15 ) ;
V_10 = ( 0xFFFFFFFFU - V_37 ) * ( V_11 / 5 ) ;
F_28 ( L_2 , V_10 / 1000000 ,
( V_10 / 10000 ) % 100 ) ;
}
}
static T_2 F_29 ( int V_18 , void * V_39 )
{
struct V_1 * V_13 = V_39 ;
if ( F_8 () ) {
V_13 -> V_40 ( V_13 ) ;
return V_41 ;
}
return V_42 ;
}
static void F_30 ( struct V_43 * V_44 )
{
int V_45 ;
if ( V_44 )
V_28 = F_31 ( V_44 , 0 ) ;
else
V_28 = F_32 ( L_3 , NULL ) ;
if ( F_17 ( V_28 ) ) {
F_33 ( L_4 , ( int ) F_34 ( V_28 ) ) ;
return;
}
V_45 = F_35 ( V_28 ) ;
if ( V_45 ) {
F_33 ( L_5 , V_45 ) ;
F_36 ( V_28 ) ;
return;
}
V_10 = F_19 ( V_28 ) ;
}
static void F_37 ( void )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
int V_34 = F_38 () ;
if ( F_39 ( V_46 , V_34 ) ) {
F_2 ( 0 , V_3 + V_4 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 -> V_18 , 0 ) ;
return;
}
F_39 ( V_46 , V_34 ) = true ;
F_24 () ;
F_2 ( 0 , V_3 + V_4 ) ;
V_2 -> V_47 = L_6 ;
V_2 -> V_48 = V_49 | V_50 |
V_51 ;
V_2 -> V_52 = 350 ;
V_2 -> V_53 = F_1 ;
V_2 -> V_54 = F_4 ;
V_2 -> V_55 = F_3 ;
V_2 -> V_56 = F_1 ;
V_2 -> V_57 = F_6 ;
V_2 -> V_18 = V_58 ;
V_2 -> V_59 = F_42 ( V_34 ) ;
F_43 ( V_2 , V_10 ,
0xf , 0xffffffff ) ;
F_41 ( V_2 -> V_18 , 0 ) ;
}
static int F_44 ( struct V_20 * V_60 ,
unsigned long V_61 , void * V_62 )
{
switch ( V_61 & ~ V_63 ) {
case V_64 :
F_37 () ;
break;
case V_65 :
F_9 () ;
break;
}
return V_27 ;
}
static int T_3 F_45 ( struct V_43 * V_44 )
{
int V_45 ;
V_17 = F_46 ( struct V_1 ) ;
if ( ! V_17 ) {
V_45 = - V_66 ;
goto V_67;
}
V_45 = F_47 ( V_58 , F_29 , L_7 , V_17 ) ;
if ( V_45 ) {
F_33 ( L_8 , V_58 , V_45 ) ;
goto V_67;
}
V_45 = F_48 ( & V_68 ) ;
if ( V_45 )
goto V_69;
F_30 ( V_44 ) ;
if ( V_10 )
F_37 () ;
else
V_70 = F_37 ;
return 0 ;
V_69:
F_49 ( V_58 , V_17 ) ;
V_67:
F_50 ( V_3 ) ;
V_3 = NULL ;
F_51 ( V_17 ) ;
return V_45 ;
}
int T_3 F_52 ( struct V_71 * V_72 )
{
if ( V_3 || V_17 )
return - V_73 ;
V_58 = V_72 -> V_74 [ 1 ] . V_75 ;
V_3 = F_53 ( V_72 -> V_74 [ 0 ] . V_75 , F_54 ( & V_72 -> V_74 [ 0 ] ) ) ;
if ( ! V_3 )
return - V_66 ;
return F_45 ( NULL ) ;
}
static void T_3 F_55 ( struct V_43 * V_44 )
{
int V_45 ;
if ( ! F_56 () || ! V_76 )
return;
V_58 = F_57 ( V_44 , 0 ) ;
if ( ! V_58 ) {
V_45 = - V_77 ;
goto V_78;
}
V_3 = F_58 ( V_44 , 0 ) ;
if ( ! V_3 ) {
V_45 = - V_66 ;
goto V_78;
}
V_45 = F_45 ( V_44 ) ;
V_78:
F_59 ( V_45 , L_9 , V_45 ) ;
}
