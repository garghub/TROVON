bool F_1 ( int V_1 )
{
return V_1 == V_2 ;
}
static inline bool F_2 ( void )
{
return V_3 &
V_4 ;
}
bool F_3 ( T_1 V_5 )
{
const T_1 V_6 = F_2 () ?
V_7 :
V_8 ;
return V_5 & V_6 ;
}
bool F_4 ( T_1 V_5 )
{
const T_1 V_9 = F_2 () ?
V_10 :
V_11 ;
return ! ( V_5 & ~ V_9 ) ;
}
static unsigned long F_5 ( unsigned long V_12 ,
unsigned long V_13 , unsigned long V_14 ,
unsigned long V_15 )
{
struct V_16 V_17 ;
F_6 ( V_12 , V_13 , V_14 , V_15 , 0 , 0 , 0 , 0 , & V_17 ) ;
return V_17 . V_18 ;
}
static unsigned long F_7 ( unsigned long V_12 ,
unsigned long V_13 , unsigned long V_14 ,
unsigned long V_15 )
{
struct V_16 V_17 ;
F_8 ( V_12 , V_13 , V_14 , V_15 , 0 , 0 , 0 , 0 , & V_17 ) ;
return V_17 . V_18 ;
}
static int F_9 ( int V_19 )
{
switch ( V_19 ) {
case V_20 :
return 0 ;
case V_21 :
return - V_22 ;
case V_23 :
case V_24 :
return - V_25 ;
case V_26 :
return - V_27 ;
} ;
return - V_25 ;
}
static T_1 F_10 ( void )
{
return F_11 ( V_28 , 0 , 0 , 0 ) ;
}
static int F_12 ( T_1 V_5 , unsigned long V_29 )
{
int V_30 ;
T_1 V_31 ;
V_31 = V_32 [ V_33 ] ;
V_30 = F_11 ( V_31 , V_5 , V_29 , 0 ) ;
return F_9 ( V_30 ) ;
}
static int F_13 ( T_1 V_5 )
{
int V_30 ;
T_1 V_31 ;
V_31 = V_32 [ V_34 ] ;
V_30 = F_11 ( V_31 , V_5 , 0 , 0 ) ;
return F_9 ( V_30 ) ;
}
static int F_14 ( unsigned long V_35 , unsigned long V_29 )
{
int V_30 ;
T_1 V_31 ;
V_31 = V_32 [ V_36 ] ;
V_30 = F_11 ( V_31 , V_35 , V_29 , 0 ) ;
return F_9 ( V_30 ) ;
}
static int F_15 ( unsigned long V_35 )
{
int V_30 ;
T_1 V_31 ;
V_31 = V_32 [ V_37 ] ;
V_30 = F_11 ( V_31 , V_35 , 0 , 0 ) ;
return F_9 ( V_30 ) ;
}
static int F_16 ( unsigned long V_38 ,
unsigned long V_39 )
{
return F_11 ( F_17 ( 0_2 , V_40 ) ,
V_38 , V_39 , 0 ) ;
}
static int F_18 ( void )
{
return F_11 ( V_41 , 0 , 0 , 0 ) ;
}
static unsigned long F_19 ( void )
{
return F_11 ( F_17 ( 0_2 , V_42 ) ,
0 , 0 , 0 ) ;
}
static int F_20 ( struct V_43 * V_44 )
{
const char * V_45 ;
F_21 ( L_1 ) ;
if ( F_22 ( V_44 , L_2 , & V_45 ) ) {
F_23 ( L_3 ) ;
return - V_46 ;
}
if ( ! strcmp ( L_4 , V_45 ) ) {
F_11 = F_5 ;
} else if ( ! strcmp ( L_5 , V_45 ) ) {
F_11 = F_7 ;
} else {
F_23 ( L_6 , V_45 ) ;
return - V_25 ;
}
return 0 ;
}
static void F_24 ( enum V_47 V_47 , const char * V_48 )
{
F_11 ( V_49 , 0 , 0 , 0 ) ;
}
static void F_25 ( void )
{
F_11 ( V_50 , 0 , 0 , 0 ) ;
}
static int T_2 F_26 ( T_1 V_51 )
{
return F_11 ( V_52 ,
V_51 , 0 , 0 ) ;
}
static int F_27 ( unsigned long V_53 )
{
return F_11 ( F_17 ( 1_0 , V_54 ) ,
F_28 ( V_55 ) , 0 , 0 ) ;
}
static int F_29 ( T_3 V_5 )
{
return F_30 ( 0 , F_27 ) ;
}
static void T_2 F_31 ( void )
{
int V_56 ;
if ( ! F_32 ( V_57 ) )
return;
V_56 = F_26 ( F_17 ( 1_0 , V_54 ) ) ;
if ( V_56 != V_21 )
F_33 ( & V_58 ) ;
}
static void T_2 F_34 ( void )
{
int V_59 = F_26 ( V_32 [ V_33 ] ) ;
if ( V_59 != V_21 )
V_3 = V_59 ;
}
static void T_2 F_35 ( void )
{
unsigned long V_35 ;
int type , V_1 = - 1 ;
type = V_60 . V_61 () ;
if ( type == V_62 ) {
F_21 ( L_7 ) ;
return;
}
if ( type == V_21 ) {
F_21 ( L_8 ) ;
return;
}
if ( type != V_63 &&
type != V_64 ) {
F_36 ( L_9 , type ) ;
return;
}
V_35 = F_19 () ;
if ( V_35 & ~ V_65 ) {
F_23 ( L_10 ,
V_35 ) ;
return;
}
V_1 = F_37 ( V_35 ) ;
V_2 = V_1 >= 0 ? V_1 : - 1 ;
F_21 ( L_11 , V_35 ) ;
}
static void T_2 F_38 ( void )
{
F_21 ( L_12 ) ;
V_32 [ V_33 ] =
F_17 ( 0_2 , V_66 ) ;
V_60 . F_30 = F_12 ;
V_32 [ V_34 ] = V_67 ;
V_60 . V_68 = F_13 ;
V_32 [ V_36 ] = F_17 ( 0_2 , V_69 ) ;
V_60 . V_70 = F_14 ;
V_32 [ V_37 ] = F_17 ( 0_2 , V_71 ) ;
V_60 . V_72 = F_15 ;
V_60 . V_73 = F_16 ;
V_60 . V_61 = F_18 ;
V_74 = F_24 ;
V_75 = F_25 ;
}
static int T_2 F_39 ( void )
{
T_1 V_76 = F_10 () ;
F_21 ( L_13 ,
F_40 ( V_76 ) ,
F_41 ( V_76 ) ) ;
if ( F_40 ( V_76 ) == 0 && F_41 ( V_76 ) < 2 ) {
F_36 ( L_14 ) ;
return - V_25 ;
}
F_38 () ;
F_35 () ;
if ( F_40 ( V_76 ) >= 1 ) {
F_34 () ;
F_31 () ;
}
return 0 ;
}
static int T_2 F_42 ( struct V_43 * V_44 )
{
int V_30 ;
V_30 = F_20 ( V_44 ) ;
if ( V_30 )
goto V_77;
V_30 = F_39 () ;
V_77:
F_43 ( V_44 ) ;
return V_30 ;
}
static int T_2 F_44 ( struct V_43 * V_44 )
{
T_1 V_78 ;
int V_30 ;
V_30 = F_20 ( V_44 ) ;
if ( V_30 )
goto V_77;
F_21 ( L_15 ) ;
if ( ! F_45 ( V_44 , L_16 , & V_78 ) ) {
V_32 [ V_33 ] = V_78 ;
V_60 . F_30 = F_12 ;
}
if ( ! F_45 ( V_44 , L_17 , & V_78 ) ) {
V_32 [ V_34 ] = V_78 ;
V_60 . V_68 = F_13 ;
}
if ( ! F_45 ( V_44 , L_18 , & V_78 ) ) {
V_32 [ V_36 ] = V_78 ;
V_60 . V_70 = F_14 ;
}
if ( ! F_45 ( V_44 , L_19 , & V_78 ) ) {
V_32 [ V_37 ] = V_78 ;
V_60 . V_72 = F_15 ;
}
V_77:
F_43 ( V_44 ) ;
return V_30 ;
}
int T_2 F_46 ( void )
{
struct V_43 * V_44 ;
const struct V_79 * V_80 ;
T_4 V_81 ;
V_44 = F_47 ( NULL , V_82 , & V_80 ) ;
if ( ! V_44 )
return - V_83 ;
V_81 = ( T_4 ) V_80 -> V_84 ;
return V_81 ( V_44 ) ;
}
int T_2 F_48 ( void )
{
if ( ! F_49 () ) {
F_21 ( L_20 ) ;
return - V_22 ;
}
F_21 ( L_21 ) ;
if ( F_50 () )
F_11 = F_5 ;
else
F_11 = F_7 ;
return F_39 () ;
}
