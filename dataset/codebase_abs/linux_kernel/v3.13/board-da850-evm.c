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
}
}
static inline void F_16 ( int V_21 )
{
struct V_4 * V_22 = & V_4 ;
V_22 -> V_5 -> V_23 = 1 ;
F_17 ( V_21 , 0 ) ;
}
static inline void F_16 ( int V_21 ) { }
static void F_18 ( unsigned V_24 )
{
int V_25 ;
struct V_26 * V_27 ;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ ) {
V_27 = & V_29 [ V_25 ] ;
V_27 -> V_30 = V_31 - V_25 ;
V_27 -> V_32 = ( char * )
V_33 [ V_34 + V_25 ] ;
V_27 -> V_24 = V_24 + V_34 + V_25 ;
}
}
static inline void F_19 ( int V_35 )
{
F_17 ( V_35 , 0 ) ;
}
static inline void F_19 ( int V_35 ) { }
static int F_20 ( struct V_36 * V_37 , unsigned V_24 ,
unsigned V_38 , void * V_39 )
{
int V_40 , V_41 , V_42 , V_15 ;
V_40 = V_24 + V_43 ;
V_41 = V_24 + V_44 ;
V_42 = V_24 + V_45 ;
V_15 = F_21 ( V_40 , V_33 [ V_43 ] ) ;
if ( V_15 ) {
F_13 ( L_5 , V_40 ) ;
goto V_46;
}
V_15 = F_21 ( V_41 , V_33 [ V_44 ] ) ;
if ( V_15 ) {
F_13 ( L_5 , V_41 ) ;
goto V_47;
}
V_15 = F_21 ( V_42 , V_33 [ V_45 ] ) ;
if ( V_15 ) {
F_13 ( L_5 , V_42 ) ;
goto V_48;
}
F_22 ( V_40 , 1 ) ;
F_22 ( V_41 , 1 ) ;
F_22 ( V_42 , 1 ) ;
F_18 ( V_24 ) ;
V_15 = F_23 ( & V_49 ) ;
if ( V_15 ) {
F_13 ( L_6 ) ;
goto V_50;
}
F_3 ( L_7 ) ;
F_11 () ;
F_16 ( V_40 ) ;
F_19 ( V_42 ) ;
return 0 ;
V_50:
F_24 ( V_42 ) ;
V_48:
F_24 ( V_41 ) ;
V_47:
F_24 ( V_40 ) ;
V_46:
return V_15 ;
}
static int F_25 ( struct V_36 * V_37 ,
unsigned V_24 , unsigned V_38 , void * V_39 )
{
F_26 ( & V_49 ) ;
F_17 ( V_24 + V_45 , 1 ) ;
F_17 ( V_24 + V_44 , 1 ) ;
F_17 ( V_24 + V_43 , 1 ) ;
F_24 ( V_24 + V_45 ) ;
F_24 ( V_24 + V_44 ) ;
F_24 ( V_24 + V_43 ) ;
return 0 ;
}
static void F_27 ( unsigned V_24 )
{
int V_25 ;
struct V_26 * V_27 ;
V_27 = & V_51 [ 0 ] ;
V_27 -> V_32 = ( char * )
V_52 [ V_53 ] ;
V_27 -> V_24 = V_24 + V_53 ;
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
V_27 = & V_51 [ V_25 + 1 ] ;
V_27 -> V_30 = V_55 + V_25 ;
V_27 -> V_32 = ( char * )
V_52 [ V_56 + V_25 ] ;
V_27 -> V_24 = V_24 + V_56 + V_25 ;
}
}
static void F_28 ( unsigned V_24 )
{
int V_25 ;
struct V_57 * V_58 ;
for ( V_25 = 0 ; V_25 < V_59 ; V_25 ++ ) {
V_58 = & V_60 [ V_25 ] ;
V_58 -> V_24 = V_24 + V_61 + V_25 ;
V_58 -> V_7 =
V_52 [ V_61 + V_25 ] ;
}
}
static int F_29 ( struct V_36 * V_37 ,
unsigned V_24 , unsigned V_38 ,
void * V_39 )
{
int V_15 ;
F_27 ( V_24 ) ;
V_15 = F_23 ( & V_62 ) ;
if ( V_15 ) {
F_13 ( L_8 ) ;
goto V_63;
}
F_28 ( V_24 ) ;
V_15 = F_23 ( & V_64 ) ;
if ( V_15 ) {
F_13 ( L_9 ) ;
goto V_65;
}
return 0 ;
V_65:
F_26 ( & V_62 ) ;
V_63:
return V_15 ;
}
static int F_30 ( struct V_36 * V_37 ,
unsigned V_24 , unsigned V_38 , void * V_39 )
{
F_26 ( & V_64 ) ;
F_26 ( & V_62 ) ;
return 0 ;
}
static int F_31 ( int V_66 )
{
return F_32 ( V_67 ) ;
}
static int F_33 ( int V_66 )
{
return ! F_32 ( V_68 ) ;
}
static void F_34 ( int V_69 )
{
F_35 ( V_70 , V_69 ) ;
F_35 ( V_71 , V_69 ) ;
}
static int F_36 ( void )
{
int V_72 ;
V_72 = F_21 ( V_70 , L_10 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_21 ( V_71 , L_11 ) ;
if ( V_72 < 0 ) {
F_24 ( V_70 ) ;
return V_72 ;
}
F_22 ( V_70 , 0 ) ;
F_22 ( V_71 , 0 ) ;
F_34 ( 0 ) ;
F_34 ( 1 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
return F_38 ( 1 , V_73 ,
F_15 ( V_73 ) ) ;
}
static int T_2 F_39 ( void )
{
void T_3 * V_74 ;
int V_15 ;
T_4 V_69 ;
struct V_4 * V_22 = & V_4 ;
T_5 V_23 = V_22 -> V_5 -> V_23 ;
if ( ! F_40 () )
return 0 ;
V_74 = F_41 ( V_75 ) ;
V_69 = F_42 ( V_74 ) ;
if ( V_23 ) {
V_69 |= F_43 ( 8 ) ;
V_15 = F_12 ( V_76 ) ;
F_3 ( L_12
L_13 ) ;
} else {
V_69 &= ~ F_43 ( 8 ) ;
V_15 = F_12 ( V_77 ) ;
F_3 ( L_14
L_13 ) ;
}
if ( V_15 )
F_13 ( L_15 ,
V_18 , V_15 ) ;
F_44 ( V_69 , V_74 ) ;
V_15 = F_45 ( V_78 ) ;
if ( V_15 )
F_13 ( L_16 , V_18 ) ;
V_15 = F_21 ( V_79 , L_17 ) ;
if ( V_15 ) {
F_13 ( L_18 , V_79 ) ;
return V_15 ;
}
F_22 ( V_79 , V_23 ) ;
V_22 -> V_5 -> V_80 = V_81 ;
V_15 = F_46 () ;
if ( V_15 )
F_13 ( L_19 , V_18 , V_15 ) ;
return 0 ;
}
static T_2 int F_47 ( void )
{
switch ( V_82 & 0xF ) {
case 3 :
V_83 = 456000 ;
break;
case 2 :
V_83 = 408000 ;
break;
case 1 :
V_83 = 372000 ;
break;
}
return F_48 ( L_20 ) ;
}
static T_2 int F_47 ( void ) { return 0 ; }
static T_2 void F_49 ( void )
{
int V_15 ;
V_15 = F_50 () ;
if ( V_15 )
F_13 ( L_21 , V_15 ) ;
V_15 = F_12 ( V_84 ) ;
if ( V_15 )
F_13 ( L_22 ,
V_15 ) ;
V_15 = F_51 ( & V_85 ) ;
if ( V_15 )
F_13 ( L_23 , V_15 ) ;
V_15 = F_12 ( V_86 ) ;
if ( V_15 )
F_13 ( L_24 ,
V_15 ) ;
V_15 = F_52 ( & V_87 ) ;
if ( V_15 )
F_13 ( L_25 , V_15 ) ;
}
static T_2 void F_49 ( void ) {}
static void F_53 ( int V_66 , bool V_88 )
{
static bool V_89 ;
F_54 ( L_26 , V_88 ? L_27 : L_28 ) ;
if ( V_88 == V_89 )
return;
V_89 = V_88 ;
if ( V_88 ) {
F_35 ( V_90 , 1 ) ;
F_55 ( 15000 , 15000 ) ;
F_35 ( V_90 , 0 ) ;
F_55 ( 1000 , 1000 ) ;
F_35 ( V_90 , 1 ) ;
F_56 ( 70 ) ;
} else {
F_35 ( V_90 , 0 ) ;
}
}
static T_2 int F_57 ( void )
{
int V_15 ;
V_15 = F_12 ( V_91 ) ;
if ( V_15 ) {
F_58 ( L_29 , V_15 ) ;
goto exit;
}
V_15 = F_59 ( & V_92 ) ;
if ( V_15 ) {
F_58 ( L_30 , V_15 ) ;
goto exit;
}
V_15 = F_60 ( V_90 , V_93 , L_31 ) ;
if ( V_15 ) {
F_58 ( L_32 , V_15 ) ;
goto exit;
}
V_15 = F_60 ( V_94 , V_95 , L_33 ) ;
if ( V_15 ) {
F_58 ( L_34 , V_15 ) ;
goto V_96;
}
V_97 . V_98 = F_61 ( V_94 ) ;
V_15 = F_62 ( & V_97 ) ;
if ( V_15 ) {
F_58 ( L_35 , V_15 ) ;
goto V_99;
}
return 0 ;
V_99:
F_24 ( V_94 ) ;
V_96:
F_24 ( V_90 ) ;
exit:
return V_15 ;
}
static T_2 int F_57 ( void )
{
return 0 ;
}
static T_2 void F_63 ( void )
{
int V_15 ;
V_15 = F_64 () ;
if ( V_15 )
F_13 ( L_36 , V_18 , V_15 ) ;
V_15 = F_37 () ;
if ( V_15 )
F_13 ( L_37 , V_18 , V_15 ) ;
V_15 = F_65 ( V_100 ) ;
if ( V_15 )
F_13 ( L_38 , V_18 , V_15 ) ;
V_15 = F_12 ( V_101 ) ;
if ( V_15 )
F_13 ( L_39 , V_18 , V_15 ) ;
V_15 = F_66 ( 0 , & V_102 ) ;
if ( V_15 )
F_13 ( L_40 , V_18 , V_15 ) ;
V_15 = F_67 () ;
if ( V_15 )
F_13 ( L_41 ,
V_18 , V_15 ) ;
if ( V_16 ) {
V_15 = F_12 ( V_103 ) ;
if ( V_15 )
F_13 ( L_42 ,
V_18 , V_15 ) ;
V_15 = F_21 ( V_68 , L_43 ) ;
if ( V_15 )
F_13 ( L_44 ,
V_18 , V_68 ) ;
F_68 ( V_68 ) ;
V_15 = F_21 ( V_67 , L_45 ) ;
if ( V_15 )
F_13 ( L_44 ,
V_18 , V_67 ) ;
F_68 ( V_67 ) ;
V_15 = F_69 ( & V_104 ) ;
if ( V_15 )
F_13 ( L_46 ,
V_18 , V_15 ) ;
V_15 = F_57 () ;
if ( V_15 )
F_13 ( L_47 ,
V_18 , V_15 ) ;
}
F_70 ( V_105 ) ;
F_38 ( 1 , V_106 ,
F_15 ( V_106 ) ) ;
F_44 ( 0 , F_71 ( V_107 ) + 0x30 ) ;
F_44 ( 0 , F_71 ( V_108 ) + 0x30 ) ;
V_15 = F_12 ( V_109 ) ;
if ( V_15 )
F_13 ( L_48 , V_18 , V_15 ) ;
V_110 . V_111 = F_72 () ;
F_73 ( 0 , & V_110 ) ;
V_15 = F_12 ( V_112 ) ;
if ( V_15 )
F_13 ( L_49 , V_18 , V_15 ) ;
V_15 = F_74 () ;
if ( V_15 )
F_13 ( L_50 ,
V_15 ) ;
V_15 = F_12 ( V_113 ) ;
if ( V_15 )
F_13 ( L_51 ,
V_18 , V_15 ) ;
V_15 = F_36 () ;
if ( V_15 )
F_13 ( L_52 , V_18 , V_15 ) ;
V_114 . V_115 = F_34 ,
V_15 = F_75 ( & V_114 ) ;
if ( V_15 )
F_13 ( L_53 , V_18 , V_15 ) ;
V_15 = F_76 () ;
if ( V_15 )
F_13 ( L_54 , V_18 , V_15 ) ;
V_15 = F_47 () ;
if ( V_15 )
F_13 ( L_55 , V_18 , V_15 ) ;
V_15 = F_77 () ;
if ( V_15 )
F_13 ( L_56 , V_18 , V_15 ) ;
V_15 = F_78 ( & V_116 ) ;
if ( V_15 )
F_13 ( L_57 , V_18 , V_15 ) ;
F_49 () ;
V_15 = F_79 ( V_117 ,
F_15 ( V_117 ) ) ;
if ( V_15 )
F_13 ( L_58 , V_18 ,
V_15 ) ;
V_15 = F_80 ( 1 , F_15 ( V_117 ) ) ;
if ( V_15 )
F_13 ( L_59 , V_18 , V_15 ) ;
V_15 = F_81 ( V_118 ) ;
if ( V_15 )
F_13 ( L_60 , V_18 , V_15 ) ;
F_4 () ;
V_15 = F_82 () ;
if ( V_15 )
F_13 ( L_61 ,
V_18 , V_15 ) ;
}
static int T_2 F_83 ( void )
{
if ( ! F_40 () )
return 0 ;
return F_84 ( L_62 , 2 , L_63 ) ;
}
static void T_2 F_85 ( void )
{
F_86 () ;
}
