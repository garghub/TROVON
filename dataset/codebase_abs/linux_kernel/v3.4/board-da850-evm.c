static void F_1 ( struct V_1 * V_2 )
{
char * V_3 = V_4 . V_5 -> V_3 ;
T_1 V_6 ;
if ( ! strcmp ( V_2 -> V_7 , L_1 ) ) {
F_2 ( V_2 , 0 , V_8 , & V_6 , V_3 ) ;
if ( V_6 == V_8 )
F_3 ( L_2 ,
V_3 ) ;
}
}
static void F_4 ( void )
{
F_5 ( & V_9 ) ;
}
static void F_4 ( void ) { }
static void T_2 F_6 ( void )
{
void T_3 * V_10 ;
V_10 = F_7 ( V_11 , V_12 ) ;
F_8 ( F_9 ( V_10 + V_13 ) |
V_14 ,
V_10 + V_13 ) ;
F_10 ( V_10 ) ;
}
static inline void F_11 ( void )
{
int V_15 = 0 ;
if ( ! V_16 ) {
V_15 = F_12 ( V_17 ) ;
if ( V_15 )
F_13 ( L_3
L_4 , V_15 ) ;
V_15 = F_12 ( V_18 ) ;
if ( V_15 )
F_13 ( L_5 ,
V_15 ) ;
F_6 () ;
F_14 ( V_19 ,
F_15 ( V_19 ) ) ;
}
}
static inline void F_16 ( int V_20 )
{
struct V_4 * V_21 = & V_4 ;
V_21 -> V_5 -> V_22 = 1 ;
F_17 ( V_20 , 0 ) ;
}
static inline void F_16 ( int V_20 ) { }
static void F_18 ( unsigned V_23 )
{
int V_24 ;
struct V_25 * V_26 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_26 = & V_28 [ V_24 ] ;
V_26 -> V_29 = V_30 - V_24 ;
V_26 -> V_31 = ( char * )
V_32 [ V_33 + V_24 ] ;
V_26 -> V_23 = V_23 + V_33 + V_24 ;
}
}
static int F_19 ( struct V_34 * V_35 , unsigned V_23 ,
unsigned V_36 , void * V_37 )
{
int V_38 , V_39 , V_40 , V_15 ;
V_38 = V_23 + V_41 ;
V_39 = V_23 + V_42 ;
V_40 = V_23 + V_43 ;
V_15 = F_20 ( V_38 , V_32 [ V_41 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_38 ) ;
goto V_44;
}
V_15 = F_20 ( V_39 , V_32 [ V_42 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_39 ) ;
goto V_45;
}
V_15 = F_20 ( V_40 , V_32 [ V_43 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_40 ) ;
goto V_46;
}
F_21 ( V_38 , 1 ) ;
F_21 ( V_39 , 1 ) ;
F_21 ( V_40 , 1 ) ;
F_18 ( V_23 ) ;
V_15 = F_22 ( & V_47 ) ;
if ( V_15 ) {
F_13 ( L_7 ) ;
goto V_48;
}
F_3 ( L_8 ) ;
F_11 () ;
F_16 ( V_38 ) ;
return 0 ;
V_48:
F_23 ( V_40 ) ;
V_46:
F_23 ( V_39 ) ;
V_45:
F_23 ( V_38 ) ;
V_44:
return V_15 ;
}
static int F_24 ( struct V_34 * V_35 ,
unsigned V_23 , unsigned V_36 , void * V_37 )
{
F_25 ( & V_47 ) ;
F_17 ( V_23 + V_43 , 1 ) ;
F_17 ( V_23 + V_42 , 1 ) ;
F_17 ( V_23 + V_41 , 1 ) ;
F_23 ( V_23 + V_43 ) ;
F_23 ( V_23 + V_42 ) ;
F_23 ( V_23 + V_41 ) ;
return 0 ;
}
static void F_26 ( unsigned V_23 )
{
int V_24 ;
struct V_25 * V_26 ;
V_26 = & V_49 [ 0 ] ;
V_26 -> V_31 = ( char * )
V_50 [ V_51 ] ;
V_26 -> V_23 = V_23 + V_51 ;
for ( V_24 = 0 ; V_24 < V_52 ; V_24 ++ ) {
V_26 = & V_49 [ V_24 + 1 ] ;
V_26 -> V_29 = V_53 + V_24 ;
V_26 -> V_31 = ( char * )
V_50 [ V_54 + V_24 ] ;
V_26 -> V_23 = V_23 + V_54 + V_24 ;
}
}
static void F_27 ( unsigned V_23 )
{
int V_24 ;
struct V_55 * V_56 ;
for ( V_24 = 0 ; V_24 < V_57 ; V_24 ++ ) {
V_56 = & V_58 [ V_24 ] ;
V_56 -> V_23 = V_23 + V_59 + V_24 ;
V_56 -> V_7 =
V_50 [ V_59 + V_24 ] ;
}
}
static int F_28 ( struct V_34 * V_35 ,
unsigned V_23 , unsigned V_36 ,
void * V_37 )
{
int V_15 ;
F_26 ( V_23 ) ;
V_15 = F_22 ( & V_60 ) ;
if ( V_15 ) {
F_13 ( L_9 ) ;
goto V_61;
}
F_27 ( V_23 ) ;
V_15 = F_22 ( & V_62 ) ;
if ( V_15 ) {
F_13 ( L_10 ) ;
goto V_63;
}
return 0 ;
V_63:
F_25 ( & V_60 ) ;
V_61:
return V_15 ;
}
static int F_29 ( struct V_34 * V_35 ,
unsigned V_23 , unsigned V_36 , void * V_37 )
{
F_25 ( & V_62 ) ;
F_25 ( & V_60 ) ;
return 0 ;
}
static int F_30 ( int V_64 )
{
return F_31 ( V_65 ) ;
}
static int F_32 ( int V_64 )
{
return ! F_31 ( V_66 ) ;
}
static void F_33 ( int V_67 )
{
F_34 ( V_68 , V_67 ) ;
F_34 ( V_69 , V_67 ) ;
}
static int F_35 ( void )
{
int V_70 ;
V_70 = F_20 ( V_68 , L_11 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_20 ( V_69 , L_12 ) ;
if ( V_70 < 0 ) {
F_23 ( V_68 ) ;
return V_70 ;
}
F_21 ( V_68 , 0 ) ;
F_21 ( V_69 , 0 ) ;
F_33 ( 0 ) ;
F_33 ( 1 ) ;
return 0 ;
}
static int T_2 F_36 ( void )
{
return F_37 ( 1 , V_71 ,
F_15 ( V_71 ) ) ;
}
static int T_2 F_38 ( void )
{
void T_3 * V_72 ;
int V_15 ;
T_4 V_67 ;
struct V_4 * V_21 = & V_4 ;
T_5 V_22 = V_21 -> V_5 -> V_22 ;
if ( ! F_39 () )
return 0 ;
V_72 = F_40 ( V_73 ) ;
V_67 = F_41 ( V_72 ) ;
if ( V_22 ) {
V_67 |= F_42 ( 8 ) ;
V_15 = F_12 ( V_74 ) ;
F_3 ( L_13
L_14 ) ;
} else {
V_67 &= ~ F_42 ( 8 ) ;
V_15 = F_12 ( V_75 ) ;
F_3 ( L_15
L_14 ) ;
}
if ( V_15 )
F_13 ( L_16 ,
V_15 ) ;
F_43 ( V_67 , V_72 ) ;
V_15 = F_44 ( V_76 ) ;
if ( V_15 )
F_13 ( L_17
L_18 ) ;
V_15 = F_20 ( V_77 , L_19 ) ;
if ( V_15 ) {
F_13 ( L_20 ,
V_77 ) ;
return V_15 ;
}
F_21 ( V_77 , V_22 ) ;
V_21 -> V_5 -> V_78 = V_79 ;
V_15 = F_45 () ;
if ( V_15 )
F_13 ( L_21 ,
V_15 ) ;
return 0 ;
}
static T_2 int F_46 ( void )
{
switch ( V_80 & 0xF ) {
case 3 :
V_81 = 456000 ;
break;
case 2 :
V_81 = 408000 ;
break;
case 1 :
V_81 = 372000 ;
break;
}
return F_47 ( L_22 ) ;
}
static T_2 int F_46 ( void ) { return 0 ; }
static void F_48 ( int V_64 , bool V_82 )
{
static bool V_83 ;
F_49 ( L_23 , V_82 ? L_24 : L_25 ) ;
if ( V_82 == V_83 )
return;
V_83 = V_82 ;
if ( V_82 ) {
F_34 ( V_84 , 1 ) ;
F_50 ( 15000 , 15000 ) ;
F_34 ( V_84 , 0 ) ;
F_50 ( 1000 , 1000 ) ;
F_34 ( V_84 , 1 ) ;
F_51 ( 70 ) ;
} else {
F_34 ( V_84 , 0 ) ;
}
}
static T_2 int F_52 ( void )
{
int V_15 ;
V_15 = F_12 ( V_85 ) ;
if ( V_15 ) {
F_53 ( L_26 , V_15 ) ;
goto exit;
}
V_15 = F_54 ( & V_86 ) ;
if ( V_15 ) {
F_53 ( L_27 , V_15 ) ;
goto exit;
}
V_15 = F_55 ( V_84 , V_87 , L_28 ) ;
if ( V_15 ) {
F_53 ( L_29 , V_15 ) ;
goto exit;
}
V_15 = F_55 ( V_88 , V_89 , L_30 ) ;
if ( V_15 ) {
F_53 ( L_31 , V_15 ) ;
goto V_90;
}
V_91 . V_92 = F_56 ( V_88 ) ;
V_15 = F_57 ( & V_91 ) ;
if ( V_15 ) {
F_53 ( L_32 , V_15 ) ;
goto V_93;
}
return 0 ;
V_93:
F_23 ( V_88 ) ;
V_90:
F_23 ( V_84 ) ;
exit:
return V_15 ;
}
static T_2 int F_52 ( void )
{
return 0 ;
}
static T_2 void F_58 ( void )
{
int V_15 ;
V_15 = F_36 () ;
if ( V_15 )
F_13 ( L_33 ,
V_15 ) ;
V_15 = F_59 ( V_94 ) ;
if ( V_15 )
F_13 ( L_34 ,
V_15 ) ;
V_15 = F_12 ( V_95 ) ;
if ( V_15 )
F_13 ( L_35 ,
V_15 ) ;
V_15 = F_60 ( 0 , & V_96 ) ;
if ( V_15 )
F_13 ( L_36 ,
V_15 ) ;
V_15 = F_61 () ;
if ( V_15 )
F_13 ( L_37 ,
V_15 ) ;
if ( V_16 ) {
V_15 = F_12 ( V_97 ) ;
if ( V_15 )
F_13 ( L_38
L_39 , V_15 ) ;
V_15 = F_20 ( V_66 , L_40 ) ;
if ( V_15 )
F_13 ( L_41 ,
V_66 ) ;
F_62 ( V_66 ) ;
V_15 = F_20 ( V_65 , L_42 ) ;
if ( V_15 )
F_13 ( L_41 ,
V_65 ) ;
F_62 ( V_65 ) ;
V_15 = F_63 ( & V_98 ) ;
if ( V_15 )
F_13 ( L_43
L_39 , V_15 ) ;
V_15 = F_52 () ;
if ( V_15 )
F_13 ( L_44
L_45 , V_15 ) ;
}
F_64 ( & V_99 ) ;
F_37 ( 1 , V_100 ,
F_15 ( V_100 ) ) ;
F_43 ( 0 , F_65 ( V_101 ) + 0x30 ) ;
F_43 ( 0 , F_65 ( V_102 ) + 0x30 ) ;
V_15 = F_12 ( V_103 ) ;
if ( V_15 )
F_13 ( L_46 ,
V_15 ) ;
F_66 ( 0 , & V_104 ) ;
V_15 = F_12 ( V_105 ) ;
if ( V_15 )
F_13 ( L_47 ,
V_15 ) ;
V_15 = F_12 ( V_106 ) ;
if ( V_15 )
F_13 ( L_48
L_49 , V_15 ) ;
V_15 = F_35 () ;
if ( V_15 )
F_13 ( L_50 ,
V_15 ) ;
V_107 . V_108 = F_33 ,
V_15 = F_67 ( & V_107 ) ;
if ( V_15 )
F_13 ( L_51 ,
V_15 ) ;
V_15 = F_68 () ;
if ( V_15 )
F_13 ( L_52 , V_15 ) ;
V_15 = F_46 () ;
if ( V_15 )
F_13 ( L_53 ,
V_15 ) ;
V_15 = F_69 () ;
if ( V_15 )
F_13 ( L_54 ,
V_15 ) ;
V_15 = F_70 ( & V_109 ) ;
if ( V_15 )
F_13 ( L_55 ,
V_15 ) ;
V_15 = F_71 ( 1 , V_110 ,
F_15 ( V_110 ) ) ;
if ( V_15 )
F_13 ( L_56 ,
V_15 ) ;
V_15 = F_72 ( V_111 ) ;
if ( V_15 )
F_13 ( L_57 ,
V_15 ) ;
F_4 () ;
}
static int T_2 F_73 ( void )
{
if ( ! F_39 () )
return 0 ;
return F_74 ( L_58 , 2 , L_59 ) ;
}
static void T_2 F_75 ( void )
{
F_76 () ;
}
