static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_6 ( V_9 , & V_10 -> V_9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 , T_2 V_13 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( L_1 , V_10 -> V_14 , V_13 ) ;
F_10 ( V_10 -> V_15 , V_13 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_16 * V_17 ;
T_1 V_13 = 0 ;
if ( F_12 ( ! V_10 -> V_15 ) )
return;
F_13 (plane, crtc) {
V_13 |= F_14 ( V_17 ) ;
}
V_13 |= F_15 ( V_10 -> V_18 ) ;
F_8 ( V_3 , V_13 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_21 * V_6 = V_3 -> V_6 ;
struct V_22 * V_23 ;
struct V_16 * V_17 ;
unsigned long V_24 ;
F_17 ( & V_6 -> V_25 , V_24 ) ;
V_23 = V_10 -> V_23 ;
if ( V_23 ) {
if ( ! V_20 || ( V_23 -> V_11 . V_26 == V_20 ) ) {
V_10 -> V_23 = NULL ;
F_9 ( L_2 , V_10 -> V_14 , V_23 ) ;
F_18 ( V_6 , V_10 -> V_27 , V_23 ) ;
}
}
F_19 ( & V_6 -> V_25 , V_24 ) ;
F_13 (plane, crtc) {
F_20 ( V_17 ) ;
}
if ( V_10 -> V_15 && ! V_3 -> V_28 -> V_29 ) {
F_21 ( V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
}
}
static void F_22 ( struct V_30 * V_31 , void * V_32 )
{
struct V_10 * V_10 =
F_23 ( V_31 , struct V_10 , V_33 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_24 ( V_32 , V_1 -> V_27 ) ;
F_25 ( V_32 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_27 ( V_3 ) ;
F_28 ( & V_10 -> V_33 ) ;
F_29 ( V_10 ) ;
}
static bool F_30 ( struct V_2 * V_3 ,
const struct V_34 * V_35 ,
struct V_34 * V_36 )
{
return true ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
const struct V_37 * V_38 ;
T_1 V_18 = V_10 -> V_18 , V_39 = 0 ;
unsigned long V_24 ;
#define F_32 ( T_3 ) ((stage) - STAGE_BASE)
V_38 = F_33 ( V_1 -> V_40 ) ;
F_17 ( & V_10 -> V_41 , V_24 ) ;
if ( ! V_10 -> V_15 )
goto V_42;
F_13 (plane, crtc) {
enum V_43 T_3 =
F_34 ( V_17 -> V_28 ) -> T_3 ;
F_35 ( T_3 > V_38 -> V_18 . V_44 ) ;
F_36 ( V_1 ,
F_37 ( V_18 , F_32 ( T_3 ) ) ,
F_38 ( V_45 ) |
F_39 ( V_46 ) ) ;
F_36 ( V_1 , F_40 ( V_18 ,
F_32 ( T_3 ) ) , 0xff ) ;
F_36 ( V_1 , F_41 ( V_18 ,
F_32 ( T_3 ) ) , 0x00 ) ;
V_39 |= F_42 ( F_43 ( V_17 ) , T_3 ) ;
F_9 ( L_3 , V_10 -> V_14 ,
F_44 ( F_43 ( V_17 ) ) , T_3 ) ;
}
F_9 ( L_4 , V_10 -> V_14 , V_18 , V_39 ) ;
F_45 ( V_10 -> V_15 , V_18 , V_39 ) ;
V_42:
F_19 ( & V_10 -> V_41 , V_24 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_24 ;
struct V_34 * V_35 ;
if ( F_12 ( ! V_3 -> V_28 ) )
return;
V_35 = & V_3 -> V_28 -> V_36 ;
F_9 ( L_5 ,
V_10 -> V_14 , V_35 -> V_11 . V_27 , V_35 -> V_14 ,
V_35 -> V_47 , V_35 -> clock ,
V_35 -> V_48 , V_35 -> V_49 ,
V_35 -> V_50 , V_35 -> V_51 ,
V_35 -> V_52 , V_35 -> V_53 ,
V_35 -> V_54 , V_35 -> V_55 ,
V_35 -> type , V_35 -> V_24 ) ;
F_17 ( & V_10 -> V_41 , V_24 ) ;
F_36 ( V_1 , F_47 ( V_10 -> V_18 ) ,
F_48 ( V_35 -> V_48 ) |
F_49 ( V_35 -> V_52 ) ) ;
F_19 ( & V_10 -> V_41 , V_24 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_9 ( L_6 , V_10 -> V_14 ) ;
if ( F_12 ( ! V_10 -> V_56 ) )
return;
F_45 ( V_10 -> V_15 , V_10 -> V_18 , 0x00000000 ) ;
F_51 ( & V_1 -> V_11 , & V_10 -> V_57 ) ;
F_52 ( V_1 ) ;
V_10 -> V_56 = false ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_9 ( L_6 , V_10 -> V_14 ) ;
if ( F_12 ( V_10 -> V_56 ) )
return;
F_54 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_57 ) ;
V_10 -> V_56 = true ;
}
static int F_55 ( const void * V_58 , const void * V_59 )
{
struct V_60 * V_61 = (struct V_60 * ) V_58 ;
struct V_60 * V_62 = (struct V_60 * ) V_59 ;
return V_61 -> V_28 -> V_63 - V_62 -> V_28 -> V_63 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_64 * V_28 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
struct V_21 * V_6 = V_3 -> V_6 ;
struct V_60 V_65 [ V_66 + 1 ] ;
int V_67 = 0 , V_68 ;
F_9 ( L_7 , V_10 -> V_14 ) ;
if ( V_28 -> V_29 && ! V_10 -> V_15 ) {
V_10 -> V_15 = F_57 ( V_1 -> V_69 , V_3 ) ;
if ( F_12 ( ! V_10 -> V_15 ) )
return - V_70 ;
}
F_58 (plane, state) {
struct V_71 * V_72 ;
if ( V_67 >= F_59 ( V_65 ) ) {
F_60 ( V_6 -> V_6 , L_8 ) ;
return - V_70 ;
}
V_72 = V_28 -> V_28 -> V_73 [ F_61 ( V_17 ) ] ;
if ( ! V_72 )
V_72 = V_17 -> V_28 ;
V_65 [ V_67 ] . V_17 = V_17 ;
V_65 [ V_67 ] . V_28 = F_34 ( V_72 ) ;
V_67 ++ ;
}
F_62 ( V_65 , V_67 , sizeof( V_65 [ 0 ] ) , F_55 , NULL ) ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
V_65 [ V_68 ] . V_28 -> T_3 = V_74 + V_68 ;
F_9 ( L_9 , V_10 -> V_14 ,
F_44 ( F_43 ( V_65 [ V_68 ] . V_17 ) ) ,
V_65 [ V_68 ] . V_28 -> T_3 ) ;
}
return 0 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( L_10 , V_10 -> V_14 ) ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_21 * V_6 = V_3 -> V_6 ;
unsigned long V_24 ;
F_9 ( L_11 , V_10 -> V_14 , V_3 -> V_28 -> V_23 ) ;
F_12 ( V_10 -> V_23 ) ;
F_17 ( & V_6 -> V_25 , V_24 ) ;
V_10 -> V_23 = V_3 -> V_28 -> V_23 ;
F_19 ( & V_6 -> V_25 , V_24 ) ;
if ( F_65 ( ! V_10 -> V_15 ) )
return;
F_31 ( V_3 ) ;
F_11 ( V_3 ) ;
F_4 ( V_3 , V_75 ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_76 * V_77 , T_4 V_32 )
{
return - V_70 ;
}
static void F_67 ( struct V_2 * V_3 , T_1 * V_78 , T_1 * V_79 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_80 = V_3 -> V_35 . V_48 ;
T_1 V_81 = V_3 -> V_35 . V_52 ;
* V_78 = F_68 ( V_10 -> V_82 . V_83 , V_80 -
V_10 -> V_82 . V_84 ) ;
* V_79 = F_68 ( V_10 -> V_82 . V_85 , V_81 -
V_10 -> V_82 . V_86 ) ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_19 * V_20 , T_1 V_87 ,
T_1 V_83 , T_1 V_85 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_21 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_88 * V_89 , * V_90 = NULL ;
T_1 V_91 , V_92 , V_93 ;
int V_94 , V_95 , V_18 ;
unsigned int V_96 ;
enum V_97 V_98 = V_99 ;
T_1 V_13 = F_70 ( 0 ) ;
T_1 V_78 , V_79 ;
bool V_100 = true ;
unsigned long V_24 ;
if ( ( V_83 > V_101 ) || ( V_85 > V_102 ) ) {
F_60 ( V_6 -> V_6 , L_12 , V_83 , V_85 ) ;
return - V_70 ;
}
if ( NULL == V_10 -> V_15 )
return - V_70 ;
if ( ! V_87 ) {
F_9 ( L_13 ) ;
V_100 = false ;
goto V_103;
}
V_89 = F_71 ( V_6 , V_20 , V_87 ) ;
if ( ! V_89 )
return - V_104 ;
V_94 = F_72 ( V_89 , V_1 -> V_27 , & V_92 ) ;
if ( V_94 )
return - V_70 ;
V_18 = V_10 -> V_18 ;
F_73 ( V_105 , & V_96 , & V_95 ) ;
V_93 = V_83 * ( V_95 >> 3 ) ;
F_17 ( & V_10 -> V_82 . V_106 , V_24 ) ;
V_90 = V_10 -> V_82 . V_107 ;
V_10 -> V_82 . V_107 = V_89 ;
V_10 -> V_82 . V_83 = V_83 ;
V_10 -> V_82 . V_85 = V_85 ;
F_67 ( V_3 , & V_78 , & V_79 ) ;
F_36 ( V_1 , F_74 ( V_18 ) , V_93 ) ;
F_36 ( V_1 , F_75 ( V_18 ) ,
F_76 ( V_108 ) ) ;
F_36 ( V_1 , F_77 ( V_18 ) ,
F_78 ( V_85 ) |
F_79 ( V_83 ) ) ;
F_36 ( V_1 , F_80 ( V_18 ) ,
F_81 ( V_79 ) |
F_82 ( V_78 ) ) ;
F_36 ( V_1 , F_83 ( V_18 ) , V_92 ) ;
V_91 = V_109 ;
V_91 |= F_84 ( V_98 ) ;
F_36 ( V_1 , F_85 ( V_18 ) , V_91 ) ;
F_19 ( & V_10 -> V_82 . V_106 , V_24 ) ;
V_103:
V_94 = F_86 ( V_10 -> V_15 , 0 , V_100 ) ;
if ( V_94 ) {
F_60 ( V_6 -> V_6 , L_14 ,
V_100 ? L_15 : L_16 , V_94 ) ;
goto V_110;
}
F_8 ( V_3 , V_13 ) ;
V_110:
if ( V_90 ) {
F_87 ( & V_10 -> V_33 , V_90 ) ;
F_4 ( V_3 , V_111 ) ;
}
return V_94 ;
}
static int F_88 ( struct V_2 * V_3 , int V_84 , int V_86 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_13 = F_70 ( 0 ) ;
T_1 V_78 ;
T_1 V_79 ;
unsigned long V_24 ;
if ( F_65 ( ! V_3 -> V_28 -> V_29 ) )
return 0 ;
V_10 -> V_82 . V_84 = V_84 = F_89 ( V_84 , 0 ) ;
V_10 -> V_82 . V_86 = V_86 = F_89 ( V_86 , 0 ) ;
F_67 ( V_3 , & V_78 , & V_79 ) ;
F_17 ( & V_10 -> V_82 . V_106 , V_24 ) ;
F_36 ( V_1 , F_80 ( V_10 -> V_18 ) ,
F_81 ( V_79 ) |
F_82 ( V_78 ) ) ;
F_36 ( V_1 , F_90 ( V_10 -> V_18 ) ,
F_91 ( V_86 ) |
F_92 ( V_84 ) ) ;
F_19 ( & V_10 -> V_82 . V_106 , V_24 ) ;
F_8 ( V_3 , V_13 ) ;
return 0 ;
}
static void F_93 ( struct V_112 * V_113 , T_1 V_114 )
{
struct V_10 * V_10 = F_23 ( V_113 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_51 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_94 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_75 ) {
F_16 ( V_3 , NULL ) ;
}
if ( V_9 & V_111 )
F_95 ( & V_10 -> V_33 , V_5 -> V_115 ) ;
}
static void F_96 ( struct V_112 * V_113 , T_1 V_114 )
{
struct V_10 * V_10 = F_23 ( V_113 , struct V_10 , V_57 ) ;
F_9 ( L_17 , V_10 -> V_14 , V_114 ) ;
}
T_1 F_97 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_116 ;
}
void F_98 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
F_9 ( L_18 , V_20 ) ;
F_16 ( V_3 , V_20 ) ;
}
void F_99 ( struct V_2 * V_3 , struct V_117 * V_118 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_18 = F_100 ( V_3 ) ;
V_10 -> V_57 . V_116 = F_101 ( V_118 -> V_119 ) ;
if ( V_118 -> V_35 == V_120 )
V_10 -> V_12 . V_116 = F_102 ( V_18 ) ;
else
V_10 -> V_12 . V_116 = F_103 ( V_18 , V_118 ) ;
F_104 ( & V_1 -> V_11 ) ;
F_105 ( V_10 -> V_15 , V_118 ) ;
}
int F_100 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_12 ( ! V_3 ) ? - V_70 : V_10 -> V_18 ;
}
struct V_121 * F_106 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_12 ( ! V_3 ) ? NULL : V_10 -> V_15 ;
}
struct V_2 * F_107 ( struct V_21 * V_6 ,
struct V_16 * V_17 , int V_27 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_108 ( sizeof( * V_10 ) , V_122 ) ;
if ( ! V_10 )
return F_109 ( - V_123 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_27 = V_27 ;
V_10 -> V_18 = F_110 ( V_27 ) ;
F_111 ( & V_10 -> V_41 ) ;
F_111 ( & V_10 -> V_82 . V_106 ) ;
V_10 -> V_12 . V_113 = F_93 ;
V_10 -> V_57 . V_113 = F_96 ;
snprintf ( V_10 -> V_14 , sizeof( V_10 -> V_14 ) , L_19 ,
F_44 ( F_43 ( V_17 ) ) , V_27 ) ;
F_112 ( V_6 , V_3 , V_17 , NULL , & V_124 ) ;
F_113 ( & V_10 -> V_33 ,
L_20 , F_22 ) ;
F_114 ( V_3 , & V_125 ) ;
V_17 -> V_3 = V_3 ;
F_115 ( V_17 , & V_3 -> V_11 ) ;
return V_3 ;
}
