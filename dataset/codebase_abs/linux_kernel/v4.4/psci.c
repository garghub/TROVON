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
static int F_5 ( int V_12 )
{
switch ( V_12 ) {
case V_13 :
return 0 ;
case V_14 :
return - V_15 ;
case V_16 :
case V_17 :
return - V_18 ;
case V_19 :
return - V_20 ;
} ;
return - V_18 ;
}
static T_1 F_6 ( void )
{
return F_7 ( V_21 , 0 , 0 , 0 ) ;
}
static int F_8 ( T_1 V_5 , unsigned long V_22 )
{
int V_23 ;
T_1 V_24 ;
V_24 = V_25 [ V_26 ] ;
V_23 = F_7 ( V_24 , V_5 , V_22 , 0 ) ;
return F_5 ( V_23 ) ;
}
static int F_9 ( T_1 V_5 )
{
int V_23 ;
T_1 V_24 ;
V_24 = V_25 [ V_27 ] ;
V_23 = F_7 ( V_24 , V_5 , 0 , 0 ) ;
return F_5 ( V_23 ) ;
}
static int F_10 ( unsigned long V_28 , unsigned long V_22 )
{
int V_23 ;
T_1 V_24 ;
V_24 = V_25 [ V_29 ] ;
V_23 = F_7 ( V_24 , V_28 , V_22 , 0 ) ;
return F_5 ( V_23 ) ;
}
static int F_11 ( unsigned long V_28 )
{
int V_23 ;
T_1 V_24 ;
V_24 = V_25 [ V_30 ] ;
V_23 = F_7 ( V_24 , V_28 , 0 , 0 ) ;
return F_5 ( V_23 ) ;
}
static int F_12 ( unsigned long V_31 ,
unsigned long V_32 )
{
return F_7 ( F_13 ( 0_2 , V_33 ) ,
V_31 , V_32 , 0 ) ;
}
static int F_14 ( void )
{
return F_7 ( V_34 , 0 , 0 , 0 ) ;
}
static unsigned long F_15 ( void )
{
return F_7 ( F_13 ( 0_2 , V_35 ) ,
0 , 0 , 0 ) ;
}
static int F_16 ( struct V_36 * V_37 )
{
const char * V_38 ;
F_17 ( L_1 ) ;
if ( F_18 ( V_37 , L_2 , & V_38 ) ) {
F_19 ( L_3 ) ;
return - V_39 ;
}
if ( ! strcmp ( L_4 , V_38 ) ) {
F_7 = V_40 ;
} else if ( ! strcmp ( L_5 , V_38 ) ) {
F_7 = V_41 ;
} else {
F_19 ( L_6 , V_38 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_20 ( enum V_42 V_42 , const char * V_43 )
{
F_7 ( V_44 , 0 , 0 , 0 ) ;
}
static void F_21 ( void )
{
F_7 ( V_45 , 0 , 0 , 0 ) ;
}
static int T_2 F_22 ( T_1 V_46 )
{
return F_7 ( V_47 ,
V_46 , 0 , 0 ) ;
}
static int F_23 ( unsigned long V_48 )
{
return F_7 ( F_13 ( 1_0 , V_49 ) ,
F_24 ( V_50 ) , 0 , 0 ) ;
}
static int F_25 ( T_3 V_5 )
{
return F_26 ( 0 , F_23 ) ;
}
static void T_2 F_27 ( void )
{
int V_51 ;
if ( ! F_28 ( V_52 ) )
return;
V_51 = F_22 ( F_13 ( 1_0 , V_49 ) ) ;
if ( V_51 != V_14 )
F_29 ( & V_53 ) ;
}
static void T_2 F_30 ( void )
{
int V_54 = F_22 ( V_25 [ V_26 ] ) ;
if ( V_54 != V_14 )
V_3 = V_54 ;
}
static void T_2 F_31 ( void )
{
unsigned long V_28 ;
int type , V_1 = - 1 ;
type = V_55 . V_56 () ;
if ( type == V_57 ) {
F_17 ( L_7 ) ;
return;
}
if ( type == V_14 ) {
F_17 ( L_8 ) ;
return;
}
if ( type != V_58 &&
type != V_59 ) {
F_32 ( L_9 , type ) ;
return;
}
V_28 = F_15 () ;
if ( V_28 & ~ V_60 ) {
F_19 ( L_10 ,
V_28 ) ;
return;
}
V_1 = F_33 ( V_28 ) ;
V_2 = V_1 >= 0 ? V_1 : - 1 ;
F_17 ( L_11 , V_28 ) ;
}
static void T_2 F_34 ( void )
{
F_17 ( L_12 ) ;
V_25 [ V_26 ] =
F_13 ( 0_2 , V_61 ) ;
V_55 . F_26 = F_8 ;
V_25 [ V_27 ] = V_62 ;
V_55 . V_63 = F_9 ;
V_25 [ V_29 ] = F_13 ( 0_2 , V_64 ) ;
V_55 . V_65 = F_10 ;
V_25 [ V_30 ] = F_13 ( 0_2 , V_66 ) ;
V_55 . V_67 = F_11 ;
V_55 . V_68 = F_12 ;
V_55 . V_56 = F_14 ;
V_69 = F_20 ;
V_70 = F_21 ;
}
static int T_2 F_35 ( void )
{
T_1 V_71 = F_6 () ;
F_17 ( L_13 ,
F_36 ( V_71 ) ,
F_37 ( V_71 ) ) ;
if ( F_36 ( V_71 ) == 0 && F_37 ( V_71 ) < 2 ) {
F_32 ( L_14 ) ;
return - V_18 ;
}
F_34 () ;
F_31 () ;
if ( F_36 ( V_71 ) >= 1 ) {
F_30 () ;
F_27 () ;
}
return 0 ;
}
static int T_2 F_38 ( struct V_36 * V_37 )
{
int V_23 ;
V_23 = F_16 ( V_37 ) ;
if ( V_23 )
goto V_72;
V_23 = F_35 () ;
V_72:
F_39 ( V_37 ) ;
return V_23 ;
}
static int T_2 F_40 ( struct V_36 * V_37 )
{
T_1 V_73 ;
int V_23 ;
V_23 = F_16 ( V_37 ) ;
if ( V_23 )
goto V_72;
F_17 ( L_15 ) ;
if ( ! F_41 ( V_37 , L_16 , & V_73 ) ) {
V_25 [ V_26 ] = V_73 ;
V_55 . F_26 = F_8 ;
}
if ( ! F_41 ( V_37 , L_17 , & V_73 ) ) {
V_25 [ V_27 ] = V_73 ;
V_55 . V_63 = F_9 ;
}
if ( ! F_41 ( V_37 , L_18 , & V_73 ) ) {
V_25 [ V_29 ] = V_73 ;
V_55 . V_65 = F_10 ;
}
if ( ! F_41 ( V_37 , L_19 , & V_73 ) ) {
V_25 [ V_30 ] = V_73 ;
V_55 . V_67 = F_11 ;
}
V_72:
F_39 ( V_37 ) ;
return V_23 ;
}
int T_2 F_42 ( void )
{
struct V_36 * V_37 ;
const struct V_74 * V_75 ;
T_4 V_76 ;
V_37 = F_43 ( NULL , V_77 , & V_75 ) ;
if ( ! V_37 )
return - V_78 ;
V_76 = ( T_4 ) V_75 -> V_79 ;
return V_76 ( V_37 ) ;
}
int T_2 F_44 ( void )
{
if ( ! F_45 () ) {
F_17 ( L_20 ) ;
return - V_15 ;
}
F_17 ( L_21 ) ;
if ( F_46 () )
F_7 = V_40 ;
else
F_7 = V_41 ;
return F_35 () ;
}
