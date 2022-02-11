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
static inline void F_19 ( int V_34 )
{
F_17 ( V_34 , 0 ) ;
}
static inline void F_19 ( int V_34 ) { }
static int F_20 ( struct V_35 * V_36 , unsigned V_23 ,
unsigned V_37 , void * V_38 )
{
int V_39 , V_40 , V_41 , V_15 ;
V_39 = V_23 + V_42 ;
V_40 = V_23 + V_43 ;
V_41 = V_23 + V_44 ;
V_15 = F_21 ( V_39 , V_32 [ V_42 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_39 ) ;
goto V_45;
}
V_15 = F_21 ( V_40 , V_32 [ V_43 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_40 ) ;
goto V_46;
}
V_15 = F_21 ( V_41 , V_32 [ V_44 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_41 ) ;
goto V_47;
}
F_22 ( V_39 , 1 ) ;
F_22 ( V_40 , 1 ) ;
F_22 ( V_41 , 1 ) ;
F_18 ( V_23 ) ;
V_15 = F_23 ( & V_48 ) ;
if ( V_15 ) {
F_13 ( L_7 ) ;
goto V_49;
}
F_3 ( L_8 ) ;
F_11 () ;
F_16 ( V_39 ) ;
F_19 ( V_41 ) ;
return 0 ;
V_49:
F_24 ( V_41 ) ;
V_47:
F_24 ( V_40 ) ;
V_46:
F_24 ( V_39 ) ;
V_45:
return V_15 ;
}
static int F_25 ( struct V_35 * V_36 ,
unsigned V_23 , unsigned V_37 , void * V_38 )
{
F_26 ( & V_48 ) ;
F_17 ( V_23 + V_44 , 1 ) ;
F_17 ( V_23 + V_43 , 1 ) ;
F_17 ( V_23 + V_42 , 1 ) ;
F_24 ( V_23 + V_44 ) ;
F_24 ( V_23 + V_43 ) ;
F_24 ( V_23 + V_42 ) ;
return 0 ;
}
static void F_27 ( unsigned V_23 )
{
int V_24 ;
struct V_25 * V_26 ;
V_26 = & V_50 [ 0 ] ;
V_26 -> V_31 = ( char * )
V_51 [ V_52 ] ;
V_26 -> V_23 = V_23 + V_52 ;
for ( V_24 = 0 ; V_24 < V_53 ; V_24 ++ ) {
V_26 = & V_50 [ V_24 + 1 ] ;
V_26 -> V_29 = V_54 + V_24 ;
V_26 -> V_31 = ( char * )
V_51 [ V_55 + V_24 ] ;
V_26 -> V_23 = V_23 + V_55 + V_24 ;
}
}
static void F_28 ( unsigned V_23 )
{
int V_24 ;
struct V_56 * V_57 ;
for ( V_24 = 0 ; V_24 < V_58 ; V_24 ++ ) {
V_57 = & V_59 [ V_24 ] ;
V_57 -> V_23 = V_23 + V_60 + V_24 ;
V_57 -> V_7 =
V_51 [ V_60 + V_24 ] ;
}
}
static int F_29 ( struct V_35 * V_36 ,
unsigned V_23 , unsigned V_37 ,
void * V_38 )
{
int V_15 ;
F_27 ( V_23 ) ;
V_15 = F_23 ( & V_61 ) ;
if ( V_15 ) {
F_13 ( L_9 ) ;
goto V_62;
}
F_28 ( V_23 ) ;
V_15 = F_23 ( & V_63 ) ;
if ( V_15 ) {
F_13 ( L_10 ) ;
goto V_64;
}
return 0 ;
V_64:
F_26 ( & V_61 ) ;
V_62:
return V_15 ;
}
static int F_30 ( struct V_35 * V_36 ,
unsigned V_23 , unsigned V_37 , void * V_38 )
{
F_26 ( & V_63 ) ;
F_26 ( & V_61 ) ;
return 0 ;
}
static int F_31 ( int V_65 )
{
return F_32 ( V_66 ) ;
}
static int F_33 ( int V_65 )
{
return ! F_32 ( V_67 ) ;
}
static void F_34 ( int V_68 )
{
F_35 ( V_69 , V_68 ) ;
F_35 ( V_70 , V_68 ) ;
}
static int F_36 ( void )
{
int V_71 ;
V_71 = F_21 ( V_69 , L_11 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_21 ( V_70 , L_12 ) ;
if ( V_71 < 0 ) {
F_24 ( V_69 ) ;
return V_71 ;
}
F_22 ( V_69 , 0 ) ;
F_22 ( V_70 , 0 ) ;
F_34 ( 0 ) ;
F_34 ( 1 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
return F_38 ( 1 , V_72 ,
F_15 ( V_72 ) ) ;
}
static int T_2 F_39 ( void )
{
void T_3 * V_73 ;
int V_15 ;
T_4 V_68 ;
struct V_4 * V_21 = & V_4 ;
T_5 V_22 = V_21 -> V_5 -> V_22 ;
if ( ! F_40 () )
return 0 ;
V_73 = F_41 ( V_74 ) ;
V_68 = F_42 ( V_73 ) ;
if ( V_22 ) {
V_68 |= F_43 ( 8 ) ;
V_15 = F_12 ( V_75 ) ;
F_3 ( L_13
L_14 ) ;
} else {
V_68 &= ~ F_43 ( 8 ) ;
V_15 = F_12 ( V_76 ) ;
F_3 ( L_15
L_14 ) ;
}
if ( V_15 )
F_13 ( L_16 ,
V_15 ) ;
F_44 ( V_68 , V_73 ) ;
V_15 = F_45 ( V_77 ) ;
if ( V_15 )
F_13 ( L_17
L_18 ) ;
V_15 = F_21 ( V_78 , L_19 ) ;
if ( V_15 ) {
F_13 ( L_20 ,
V_78 ) ;
return V_15 ;
}
F_22 ( V_78 , V_22 ) ;
V_21 -> V_5 -> V_79 = V_80 ;
V_15 = F_46 () ;
if ( V_15 )
F_13 ( L_21 ,
V_15 ) ;
return 0 ;
}
static T_2 int F_47 ( void )
{
switch ( V_81 & 0xF ) {
case 3 :
V_82 = 456000 ;
break;
case 2 :
V_82 = 408000 ;
break;
case 1 :
V_82 = 372000 ;
break;
}
return F_48 ( L_22 ) ;
}
static T_2 int F_47 ( void ) { return 0 ; }
static T_2 void F_49 ( void )
{
int V_15 ;
V_15 = F_50 () ;
if ( V_15 )
F_51 ( L_23 , V_15 ) ;
V_15 = F_12 ( V_83 ) ;
if ( V_15 )
F_51 ( L_24 ,
V_15 ) ;
V_15 = F_52 ( & V_84 ) ;
if ( V_15 )
F_51 ( L_25 , V_15 ) ;
V_15 = F_12 ( V_85 ) ;
if ( V_15 )
F_51 ( L_26 ,
V_15 ) ;
V_15 = F_53 ( & V_86 ) ;
if ( V_15 )
F_51 ( L_27 , V_15 ) ;
}
static T_2 void F_49 ( void ) {}
static void F_54 ( int V_65 , bool V_87 )
{
static bool V_88 ;
F_55 ( L_28 , V_87 ? L_29 : L_30 ) ;
if ( V_87 == V_88 )
return;
V_88 = V_87 ;
if ( V_87 ) {
F_35 ( V_89 , 1 ) ;
F_56 ( 15000 , 15000 ) ;
F_35 ( V_89 , 0 ) ;
F_56 ( 1000 , 1000 ) ;
F_35 ( V_89 , 1 ) ;
F_57 ( 70 ) ;
} else {
F_35 ( V_89 , 0 ) ;
}
}
static T_2 int F_58 ( void )
{
int V_15 ;
V_15 = F_12 ( V_90 ) ;
if ( V_15 ) {
F_59 ( L_31 , V_15 ) ;
goto exit;
}
V_15 = F_60 ( & V_91 ) ;
if ( V_15 ) {
F_59 ( L_32 , V_15 ) ;
goto exit;
}
V_15 = F_61 ( V_89 , V_92 , L_33 ) ;
if ( V_15 ) {
F_59 ( L_34 , V_15 ) ;
goto exit;
}
V_15 = F_61 ( V_93 , V_94 , L_35 ) ;
if ( V_15 ) {
F_59 ( L_36 , V_15 ) ;
goto V_95;
}
V_96 . V_97 = F_62 ( V_93 ) ;
V_15 = F_63 ( & V_96 ) ;
if ( V_15 ) {
F_59 ( L_37 , V_15 ) ;
goto V_98;
}
return 0 ;
V_98:
F_24 ( V_93 ) ;
V_95:
F_24 ( V_89 ) ;
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
V_15 = F_37 () ;
if ( V_15 )
F_13 ( L_38 ,
V_15 ) ;
V_15 = F_65 ( V_99 ) ;
if ( V_15 )
F_13 ( L_39 ,
V_15 ) ;
V_15 = F_12 ( V_100 ) ;
if ( V_15 )
F_13 ( L_40 ,
V_15 ) ;
V_15 = F_66 ( 0 , & V_101 ) ;
if ( V_15 )
F_13 ( L_41 ,
V_15 ) ;
V_15 = F_67 () ;
if ( V_15 )
F_13 ( L_42 ,
V_15 ) ;
if ( V_16 ) {
V_15 = F_12 ( V_102 ) ;
if ( V_15 )
F_13 ( L_43
L_44 , V_15 ) ;
V_15 = F_21 ( V_67 , L_45 ) ;
if ( V_15 )
F_13 ( L_46 ,
V_67 ) ;
F_68 ( V_67 ) ;
V_15 = F_21 ( V_66 , L_47 ) ;
if ( V_15 )
F_13 ( L_46 ,
V_66 ) ;
F_68 ( V_66 ) ;
V_15 = F_69 ( & V_103 ) ;
if ( V_15 )
F_13 ( L_48
L_44 , V_15 ) ;
V_15 = F_58 () ;
if ( V_15 )
F_13 ( L_49
L_50 , V_15 ) ;
}
F_70 ( & V_104 ) ;
F_38 ( 1 , V_105 ,
F_15 ( V_105 ) ) ;
F_44 ( 0 , F_71 ( V_106 ) + 0x30 ) ;
F_44 ( 0 , F_71 ( V_107 ) + 0x30 ) ;
V_15 = F_12 ( V_108 ) ;
if ( V_15 )
F_13 ( L_51 ,
V_15 ) ;
V_109 . V_110 = F_72 () ;
F_73 ( 0 , & V_109 ) ;
V_15 = F_12 ( V_111 ) ;
if ( V_15 )
F_13 ( L_52 ,
V_15 ) ;
V_15 = F_74 () ;
if ( V_15 )
F_51 ( L_53 ,
V_15 ) ;
V_15 = F_12 ( V_112 ) ;
if ( V_15 )
F_13 ( L_54
L_55 , V_15 ) ;
V_15 = F_36 () ;
if ( V_15 )
F_13 ( L_56 ,
V_15 ) ;
V_113 . V_114 = F_34 ,
V_15 = F_75 ( & V_113 ) ;
if ( V_15 )
F_13 ( L_57 ,
V_15 ) ;
V_15 = F_76 () ;
if ( V_15 )
F_13 ( L_58 , V_15 ) ;
V_15 = F_47 () ;
if ( V_15 )
F_13 ( L_59 ,
V_15 ) ;
V_15 = F_77 () ;
if ( V_15 )
F_13 ( L_60 ,
V_15 ) ;
V_15 = F_78 ( & V_115 ) ;
if ( V_15 )
F_13 ( L_61 ,
V_15 ) ;
F_49 () ;
V_15 = F_79 ( 1 , V_116 ,
F_15 ( V_116 ) ) ;
if ( V_15 )
F_13 ( L_62 ,
V_15 ) ;
V_15 = F_80 ( V_117 ) ;
if ( V_15 )
F_13 ( L_63 ,
V_15 ) ;
F_4 () ;
}
static int T_2 F_81 ( void )
{
if ( ! F_40 () )
return 0 ;
return F_82 ( L_64 , 2 , L_65 ) ;
}
static void T_2 F_83 ( void )
{
F_84 () ;
}
