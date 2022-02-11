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
F_13 ( L_3 ,
V_18 , V_15 ) ;
V_15 = F_12 ( V_19 ) ;
if ( V_15 )
F_13 ( L_4 ,
V_18 , V_15 ) ;
F_6 () ;
F_14 ( V_20 ,
F_15 ( V_20 ) ) ;
if ( F_16 ( & V_21 ) )
F_13 ( L_5 , V_18 ) ;
}
}
static inline void F_17 ( int V_22 )
{
struct V_4 * V_23 = & V_4 ;
V_23 -> V_5 -> V_24 = 1 ;
F_18 ( V_22 , 0 ) ;
}
static inline void F_17 ( int V_22 ) { }
static void F_19 ( unsigned V_25 )
{
int V_26 ;
struct V_27 * V_28 ;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
V_28 = & V_30 [ V_26 ] ;
V_28 -> V_31 = V_32 - V_26 ;
V_28 -> V_33 = ( char * )
V_34 [ V_35 + V_26 ] ;
V_28 -> V_25 = V_25 + V_35 + V_26 ;
}
}
static inline void F_20 ( int V_36 )
{
F_18 ( V_36 , 0 ) ;
}
static inline void F_20 ( int V_36 ) { }
static int F_21 ( struct V_37 * V_38 , unsigned V_25 ,
unsigned V_39 , void * V_40 )
{
int V_41 , V_42 , V_43 , V_15 ;
V_41 = V_25 + V_44 ;
V_42 = V_25 + V_45 ;
V_43 = V_25 + V_46 ;
V_15 = F_22 ( V_41 , V_34 [ V_44 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_41 ) ;
goto V_47;
}
V_15 = F_22 ( V_42 , V_34 [ V_45 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_42 ) ;
goto V_48;
}
V_15 = F_22 ( V_43 , V_34 [ V_46 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_43 ) ;
goto V_49;
}
F_23 ( V_41 , 1 ) ;
F_23 ( V_42 , 1 ) ;
F_23 ( V_43 , 1 ) ;
F_19 ( V_25 ) ;
V_15 = F_24 ( & V_50 ) ;
if ( V_15 ) {
F_13 ( L_7 ) ;
goto V_51;
}
F_3 ( L_8 ) ;
F_11 () ;
F_17 ( V_41 ) ;
F_20 ( V_43 ) ;
return 0 ;
V_51:
F_25 ( V_43 ) ;
V_49:
F_25 ( V_42 ) ;
V_48:
F_25 ( V_41 ) ;
V_47:
return V_15 ;
}
static int F_26 ( struct V_37 * V_38 ,
unsigned V_25 , unsigned V_39 , void * V_40 )
{
F_27 ( & V_50 ) ;
F_18 ( V_25 + V_46 , 1 ) ;
F_18 ( V_25 + V_45 , 1 ) ;
F_18 ( V_25 + V_44 , 1 ) ;
F_25 ( V_25 + V_46 ) ;
F_25 ( V_25 + V_45 ) ;
F_25 ( V_25 + V_44 ) ;
return 0 ;
}
static void F_28 ( unsigned V_25 )
{
int V_26 ;
struct V_27 * V_28 ;
V_28 = & V_52 [ 0 ] ;
V_28 -> V_33 = ( char * )
V_53 [ V_54 ] ;
V_28 -> V_25 = V_25 + V_54 ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
V_28 = & V_52 [ V_26 + 1 ] ;
V_28 -> V_31 = V_56 + V_26 ;
V_28 -> V_33 = ( char * )
V_53 [ V_57 + V_26 ] ;
V_28 -> V_25 = V_25 + V_57 + V_26 ;
}
}
static void F_29 ( unsigned V_25 )
{
int V_26 ;
struct V_58 * V_59 ;
for ( V_26 = 0 ; V_26 < V_60 ; V_26 ++ ) {
V_59 = & V_61 [ V_26 ] ;
V_59 -> V_25 = V_25 + V_62 + V_26 ;
V_59 -> V_7 =
V_53 [ V_62 + V_26 ] ;
}
}
static int F_30 ( struct V_37 * V_38 ,
unsigned V_25 , unsigned V_39 ,
void * V_40 )
{
int V_15 ;
F_28 ( V_25 ) ;
V_15 = F_24 ( & V_63 ) ;
if ( V_15 ) {
F_13 ( L_9 ) ;
goto V_64;
}
F_29 ( V_25 ) ;
V_15 = F_24 ( & V_65 ) ;
if ( V_15 ) {
F_13 ( L_10 ) ;
goto V_66;
}
return 0 ;
V_66:
F_27 ( & V_63 ) ;
V_64:
return V_15 ;
}
static int F_31 ( struct V_37 * V_38 ,
unsigned V_25 , unsigned V_39 , void * V_40 )
{
F_27 ( & V_65 ) ;
F_27 ( & V_63 ) ;
return 0 ;
}
static int F_32 ( int V_67 )
{
return F_33 ( V_68 ) ;
}
static int F_34 ( int V_67 )
{
return ! F_33 ( V_69 ) ;
}
static void F_35 ( int V_70 )
{
F_36 ( V_71 , V_70 ) ;
F_36 ( V_72 , V_70 ) ;
}
static int F_37 ( void )
{
int V_73 ;
V_73 = F_22 ( V_71 , L_11 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_22 ( V_72 , L_12 ) ;
if ( V_73 < 0 ) {
F_25 ( V_71 ) ;
return V_73 ;
}
F_23 ( V_71 , 0 ) ;
F_23 ( V_72 , 0 ) ;
F_35 ( 0 ) ;
F_35 ( 1 ) ;
return 0 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( 1 , V_74 ,
F_15 ( V_74 ) ) ;
}
static int T_2 F_40 ( void )
{
void T_3 * V_75 ;
int V_15 ;
T_4 V_70 ;
struct V_4 * V_23 = & V_4 ;
T_5 V_24 = V_23 -> V_5 -> V_24 ;
if ( ! F_41 () )
return 0 ;
V_75 = F_42 ( V_76 ) ;
V_70 = F_43 ( V_75 ) ;
if ( V_24 ) {
V_70 |= F_44 ( 8 ) ;
V_15 = F_12 ( V_77 ) ;
F_3 ( L_13
L_14 ) ;
} else {
V_70 &= ~ F_44 ( 8 ) ;
V_15 = F_12 ( V_78 ) ;
F_3 ( L_15
L_14 ) ;
}
if ( V_15 )
F_13 ( L_16 ,
V_18 , V_15 ) ;
F_45 ( V_70 , V_75 ) ;
V_15 = F_46 ( V_79 ) ;
if ( V_15 )
F_13 ( L_17 , V_18 ) ;
V_15 = F_22 ( V_80 , L_18 ) ;
if ( V_15 ) {
F_13 ( L_19 , V_80 ) ;
return V_15 ;
}
F_23 ( V_80 , V_24 ) ;
V_23 -> V_5 -> V_81 = V_82 ;
V_15 = F_47 () ;
if ( V_15 )
F_13 ( L_20 , V_18 , V_15 ) ;
return 0 ;
}
static T_2 int F_48 ( void )
{
switch ( V_83 & 0xF ) {
case 3 :
V_84 = 456000 ;
break;
case 2 :
V_84 = 408000 ;
break;
case 1 :
V_84 = 372000 ;
break;
}
return F_49 ( L_21 ) ;
}
static T_2 int F_48 ( void ) { return 0 ; }
static T_2 void F_50 ( void )
{
int V_15 ;
V_15 = F_51 () ;
if ( V_15 )
F_13 ( L_22 , V_15 ) ;
V_15 = F_12 ( V_85 ) ;
if ( V_15 )
F_13 ( L_23 ,
V_15 ) ;
V_15 = F_52 ( & V_86 ) ;
if ( V_15 )
F_13 ( L_24 , V_15 ) ;
V_15 = F_12 ( V_87 ) ;
if ( V_15 )
F_13 ( L_25 ,
V_15 ) ;
V_15 = F_53 ( & V_88 ) ;
if ( V_15 )
F_13 ( L_26 , V_15 ) ;
}
static T_2 void F_50 ( void ) {}
static void F_54 ( int V_67 , bool V_89 )
{
static bool V_90 ;
F_55 ( L_27 , V_89 ? L_28 : L_29 ) ;
if ( V_89 == V_90 )
return;
V_90 = V_89 ;
if ( V_89 ) {
F_36 ( V_91 , 1 ) ;
F_56 ( 15000 , 15000 ) ;
F_36 ( V_91 , 0 ) ;
F_56 ( 1000 , 1000 ) ;
F_36 ( V_91 , 1 ) ;
F_57 ( 70 ) ;
} else {
F_36 ( V_91 , 0 ) ;
}
}
static T_2 int F_58 ( void )
{
int V_15 ;
V_15 = F_12 ( V_92 ) ;
if ( V_15 ) {
F_59 ( L_30 , V_15 ) ;
goto exit;
}
V_15 = F_60 ( & V_93 ) ;
if ( V_15 ) {
F_59 ( L_31 , V_15 ) ;
goto exit;
}
V_15 = F_61 ( V_91 , V_94 , L_32 ) ;
if ( V_15 ) {
F_59 ( L_33 , V_15 ) ;
goto exit;
}
V_15 = F_61 ( V_95 , V_96 , L_34 ) ;
if ( V_15 ) {
F_59 ( L_35 , V_15 ) ;
goto V_97;
}
V_98 . V_99 = F_62 ( V_95 ) ;
V_15 = F_63 ( & V_98 ) ;
if ( V_15 ) {
F_59 ( L_36 , V_15 ) ;
goto V_100;
}
return 0 ;
V_100:
F_25 ( V_95 ) ;
V_97:
F_25 ( V_91 ) ;
exit:
return V_15 ;
}
static T_2 int F_58 ( void )
{
return 0 ;
}
static T_2 void F_64 ( void )
{
int V_15 ;
V_15 = F_65 () ;
if ( V_15 )
F_13 ( L_37 , V_18 , V_15 ) ;
F_66 ( 0 , V_101 , F_15 ( V_101 ) ) ;
V_15 = F_38 () ;
if ( V_15 )
F_13 ( L_38 , V_18 , V_15 ) ;
V_15 = F_67 ( V_102 ) ;
if ( V_15 )
F_13 ( L_39 , V_18 , V_15 ) ;
V_15 = F_12 ( V_103 ) ;
if ( V_15 )
F_13 ( L_40 , V_18 , V_15 ) ;
V_15 = F_68 ( 0 , & V_104 ) ;
if ( V_15 )
F_13 ( L_41 , V_18 , V_15 ) ;
V_15 = F_69 () ;
if ( V_15 )
F_13 ( L_42 ,
V_18 , V_15 ) ;
if ( V_16 ) {
V_15 = F_12 ( V_105 ) ;
if ( V_15 )
F_13 ( L_43 ,
V_18 , V_15 ) ;
V_15 = F_22 ( V_69 , L_44 ) ;
if ( V_15 )
F_13 ( L_45 ,
V_18 , V_69 ) ;
F_70 ( V_69 ) ;
V_15 = F_22 ( V_68 , L_46 ) ;
if ( V_15 )
F_13 ( L_45 ,
V_18 , V_68 ) ;
F_70 ( V_68 ) ;
V_15 = F_71 ( & V_106 ) ;
if ( V_15 )
F_13 ( L_47 ,
V_18 , V_15 ) ;
V_15 = F_58 () ;
if ( V_15 )
F_13 ( L_48 ,
V_18 , V_15 ) ;
}
F_72 ( V_107 ) ;
F_39 ( 1 , V_108 ,
F_15 ( V_108 ) ) ;
F_45 ( 0 , F_73 ( V_109 ) + 0x30 ) ;
F_45 ( 0 , F_73 ( V_110 ) + 0x30 ) ;
V_15 = F_12 ( V_111 ) ;
if ( V_15 )
F_13 ( L_49 , V_18 , V_15 ) ;
V_112 . V_113 = F_74 () ;
F_75 ( 0 , & V_112 ) ;
V_15 = F_12 ( V_114 ) ;
if ( V_15 )
F_13 ( L_50 , V_18 , V_15 ) ;
V_15 = F_76 () ;
if ( V_15 )
F_13 ( L_51 ,
V_15 ) ;
V_15 = F_12 ( V_115 ) ;
if ( V_15 )
F_13 ( L_52 ,
V_18 , V_15 ) ;
V_15 = F_37 () ;
if ( V_15 )
F_13 ( L_53 , V_18 , V_15 ) ;
V_116 . V_117 = F_35 ,
V_15 = F_77 ( & V_116 ) ;
if ( V_15 )
F_13 ( L_54 , V_18 , V_15 ) ;
V_15 = F_78 () ;
if ( V_15 )
F_13 ( L_55 , V_18 , V_15 ) ;
V_15 = F_48 () ;
if ( V_15 )
F_13 ( L_56 , V_18 , V_15 ) ;
V_15 = F_79 () ;
if ( V_15 )
F_13 ( L_57 , V_18 , V_15 ) ;
V_15 = F_80 ( & V_118 ) ;
if ( V_15 )
F_13 ( L_58 , V_18 , V_15 ) ;
F_50 () ;
V_15 = F_81 ( V_119 ,
F_15 ( V_119 ) ) ;
if ( V_15 )
F_13 ( L_59 , V_18 ,
V_15 ) ;
V_15 = F_82 ( 1 , F_15 ( V_119 ) ) ;
if ( V_15 )
F_13 ( L_60 , V_18 , V_15 ) ;
V_15 = F_83 ( V_120 ) ;
if ( V_15 )
F_13 ( L_61 , V_18 , V_15 ) ;
F_4 () ;
V_15 = F_84 () ;
if ( V_15 )
F_13 ( L_62 ,
V_18 , V_15 ) ;
}
static int T_2 F_85 ( void )
{
if ( ! F_41 () )
return 0 ;
return F_86 ( L_63 , 2 , L_64 ) ;
}
static void T_2 F_87 ( void )
{
F_88 () ;
}
