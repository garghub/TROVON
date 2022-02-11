bool F_1 ( int V_1 )
{
return V_1 == V_2 ;
}
static inline bool F_2 ( void )
{
return V_3 &
V_4 ;
}
static inline bool F_3 ( T_1 V_5 )
{
const T_1 V_6 = F_2 () ?
V_7 :
V_8 ;
return V_5 & V_6 ;
}
static inline bool F_4 ( T_1 V_5 )
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
static int F_27 ( struct V_43 * V_53 , int V_1 )
{
int V_54 , V_55 , V_56 = 0 ;
T_1 * V_57 ;
struct V_43 * V_58 ;
while ( ( V_58 = F_28 ( V_53 , L_7 ,
V_56 ) ) ) {
V_56 ++ ;
F_29 ( V_58 ) ;
}
if ( ! V_56 )
return - V_59 ;
V_57 = F_30 ( V_56 , sizeof( * V_57 ) , V_60 ) ;
if ( ! V_57 )
return - V_61 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
T_1 V_5 ;
V_58 = F_28 ( V_53 , L_7 , V_54 ) ;
V_55 = F_31 ( V_58 ,
L_8 ,
& V_5 ) ;
if ( V_55 ) {
F_23 ( L_9 ,
V_58 -> V_62 ) ;
F_29 ( V_58 ) ;
goto V_63;
}
F_29 ( V_58 ) ;
F_32 ( L_10 , V_5 , V_54 ) ;
if ( ! F_4 ( V_5 ) ) {
F_23 ( L_11 , V_5 ) ;
V_55 = - V_25 ;
goto V_63;
}
V_57 [ V_54 ] = V_5 ;
}
F_33 ( V_64 , V_1 ) = V_57 ;
return 0 ;
V_63:
F_34 ( V_57 ) ;
return V_55 ;
}
static int T_3 F_35 ( unsigned int V_1 )
{
int V_54 , V_56 ;
T_1 * V_57 ;
struct V_65 * V_66 ;
struct V_67 * V_68 = F_33 ( V_69 , V_1 ) ;
if ( F_36 ( ! V_68 || ! V_68 -> V_70 . V_71 ) )
return - V_25 ;
V_56 = V_68 -> V_72 . V_56 - 1 ;
if ( V_56 <= 0 )
return - V_59 ;
V_57 = F_30 ( V_56 , sizeof( * V_57 ) , V_60 ) ;
if ( ! V_57 )
return - V_61 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
T_1 V_5 ;
V_66 = & V_68 -> V_72 . V_73 [ V_54 + 1 ] ;
V_5 = V_66 -> V_74 ;
if ( ! F_4 ( V_5 ) ) {
F_23 ( L_11 , V_5 ) ;
F_34 ( V_57 ) ;
return - V_25 ;
}
V_57 [ V_54 ] = V_5 ;
}
F_33 ( V_64 , V_1 ) = V_57 ;
return 0 ;
}
static int T_3 F_35 ( unsigned int V_1 )
{
return - V_25 ;
}
int F_37 ( unsigned int V_1 )
{
struct V_43 * V_53 ;
int V_55 ;
if ( ! V_75 . V_76 )
return - V_22 ;
if ( ! V_77 )
return F_35 ( V_1 ) ;
V_53 = F_38 ( V_1 , NULL ) ;
if ( ! V_53 )
return - V_59 ;
V_55 = F_27 ( V_53 , V_1 ) ;
F_29 ( V_53 ) ;
return V_55 ;
}
static int F_39 ( unsigned long V_78 )
{
T_1 * V_5 = F_40 ( V_64 ) ;
return V_75 . V_76 ( V_5 [ V_78 - 1 ] ,
F_41 ( V_79 ) ) ;
}
int F_42 ( unsigned long V_78 )
{
int V_55 ;
T_1 * V_5 = F_40 ( V_64 ) ;
if ( F_43 ( ! V_78 ) )
return - V_25 ;
if ( ! F_3 ( V_5 [ V_78 - 1 ] ) )
V_55 = V_75 . V_76 ( V_5 [ V_78 - 1 ] , 0 ) ;
else
V_55 = V_76 ( V_78 , F_39 ) ;
return V_55 ;
}
static int F_44 ( unsigned long V_80 )
{
return F_11 ( F_17 ( 1_0 , V_81 ) ,
F_41 ( V_79 ) , 0 , 0 ) ;
}
static int F_45 ( T_4 V_5 )
{
return V_76 ( 0 , F_44 ) ;
}
static void T_2 F_46 ( void )
{
int V_55 ;
if ( ! F_47 ( V_82 ) )
return;
V_55 = F_26 ( F_17 ( 1_0 , V_81 ) ) ;
if ( V_55 != V_21 )
F_48 ( & V_83 ) ;
}
static void T_2 F_49 ( void )
{
int V_84 = F_26 ( V_32 [ V_33 ] ) ;
if ( V_84 != V_21 )
V_3 = V_84 ;
}
static void T_2 F_50 ( void )
{
unsigned long V_35 ;
int type , V_1 = - 1 ;
type = V_75 . V_85 () ;
if ( type == V_86 ) {
F_21 ( L_12 ) ;
return;
}
if ( type == V_21 ) {
F_21 ( L_13 ) ;
return;
}
if ( type != V_87 &&
type != V_88 ) {
F_51 ( L_14 , type ) ;
return;
}
V_35 = F_19 () ;
if ( V_35 & ~ V_89 ) {
F_23 ( L_15 ,
V_35 ) ;
return;
}
V_1 = F_52 ( V_35 ) ;
V_2 = V_1 >= 0 ? V_1 : - 1 ;
F_21 ( L_16 , V_35 ) ;
}
static void T_2 F_53 ( void )
{
F_21 ( L_17 ) ;
V_32 [ V_33 ] =
F_17 ( 0_2 , V_90 ) ;
V_75 . V_76 = F_12 ;
V_32 [ V_34 ] = V_91 ;
V_75 . V_92 = F_13 ;
V_32 [ V_36 ] = F_17 ( 0_2 , V_93 ) ;
V_75 . V_94 = F_14 ;
V_32 [ V_37 ] = F_17 ( 0_2 , V_95 ) ;
V_75 . V_96 = F_15 ;
V_75 . V_97 = F_16 ;
V_75 . V_85 = F_18 ;
V_98 = F_24 ;
V_99 = F_25 ;
}
static int T_2 F_54 ( void )
{
T_1 V_100 = F_10 () ;
F_21 ( L_18 ,
F_55 ( V_100 ) ,
F_56 ( V_100 ) ) ;
if ( F_55 ( V_100 ) == 0 && F_56 ( V_100 ) < 2 ) {
F_51 ( L_19 ) ;
return - V_25 ;
}
F_53 () ;
F_50 () ;
if ( F_55 ( V_100 ) >= 1 ) {
F_49 () ;
F_46 () ;
}
return 0 ;
}
static int T_2 F_57 ( struct V_43 * V_44 )
{
int V_30 ;
V_30 = F_20 ( V_44 ) ;
if ( V_30 )
goto V_101;
V_30 = F_54 () ;
V_101:
F_29 ( V_44 ) ;
return V_30 ;
}
static int T_2 F_58 ( struct V_43 * V_44 )
{
T_1 V_102 ;
int V_30 ;
V_30 = F_20 ( V_44 ) ;
if ( V_30 )
goto V_101;
F_21 ( L_20 ) ;
if ( ! F_31 ( V_44 , L_21 , & V_102 ) ) {
V_32 [ V_33 ] = V_102 ;
V_75 . V_76 = F_12 ;
}
if ( ! F_31 ( V_44 , L_22 , & V_102 ) ) {
V_32 [ V_34 ] = V_102 ;
V_75 . V_92 = F_13 ;
}
if ( ! F_31 ( V_44 , L_23 , & V_102 ) ) {
V_32 [ V_36 ] = V_102 ;
V_75 . V_94 = F_14 ;
}
if ( ! F_31 ( V_44 , L_24 , & V_102 ) ) {
V_32 [ V_37 ] = V_102 ;
V_75 . V_96 = F_15 ;
}
V_101:
F_29 ( V_44 ) ;
return V_30 ;
}
int T_2 F_59 ( void )
{
struct V_43 * V_44 ;
const struct V_103 * V_104 ;
T_5 V_105 ;
V_44 = F_60 ( NULL , V_106 , & V_104 ) ;
if ( ! V_44 || ! F_61 ( V_44 ) )
return - V_59 ;
V_105 = ( T_5 ) V_104 -> V_107 ;
return V_105 ( V_44 ) ;
}
int T_2 F_62 ( void )
{
if ( ! F_63 () ) {
F_21 ( L_25 ) ;
return - V_22 ;
}
F_21 ( L_26 ) ;
if ( F_64 () )
F_11 = F_5 ;
else
F_11 = F_7 ;
return F_54 () ;
}
