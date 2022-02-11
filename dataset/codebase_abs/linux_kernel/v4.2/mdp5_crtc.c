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
static void F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( & V_10 -> V_13 ) ;
}
static T_2 F_10 ( struct V_2 * V_3 , T_2 V_14 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_11 ( L_1 , V_10 -> V_15 , V_14 ) ;
return F_12 ( V_10 -> V_16 , V_14 ) ;
}
static T_2 F_13 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_17 * V_18 ;
T_1 V_14 = 0 ;
if ( F_14 ( ! V_10 -> V_16 ) )
return 0 ;
F_15 (plane, crtc) {
V_14 |= F_16 ( V_18 ) ;
}
V_14 |= F_17 ( V_10 -> V_19 ) ;
return F_10 ( V_3 , V_14 ) ;
}
static void F_18 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_23 * V_24 ;
struct V_17 * V_18 ;
unsigned long V_25 ;
F_19 ( & V_6 -> V_26 , V_25 ) ;
V_24 = V_10 -> V_24 ;
if ( V_24 ) {
if ( ! V_21 || ( V_24 -> V_11 . V_27 == V_21 ) ) {
V_10 -> V_24 = NULL ;
F_11 ( L_2 , V_10 -> V_15 , V_24 ) ;
F_20 ( V_6 , V_10 -> V_28 , V_24 ) ;
}
}
F_21 ( & V_6 -> V_26 , V_25 ) ;
F_15 (plane, crtc) {
F_22 ( V_18 ) ;
}
if ( V_10 -> V_16 && ! V_3 -> V_29 -> V_30 ) {
F_23 ( V_10 -> V_16 , V_10 -> V_19 , 0x00000000 ) ;
F_24 ( V_10 -> V_16 ) ;
V_10 -> V_16 = NULL ;
}
}
static void F_25 ( struct V_31 * V_32 , void * V_33 )
{
struct V_10 * V_10 =
F_26 ( V_32 , struct V_10 , V_34 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_27 ( V_33 , V_1 -> V_28 ) ;
F_28 ( V_33 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_30 ( V_3 ) ;
F_31 ( & V_10 -> V_34 ) ;
F_32 ( V_10 ) ;
}
static bool F_33 ( struct V_2 * V_3 ,
const struct V_35 * V_36 ,
struct V_35 * V_37 )
{
return true ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
const struct V_38 * V_39 ;
T_1 V_19 = V_10 -> V_19 , V_40 = 0 ;
unsigned long V_25 ;
#define F_35 ( T_3 ) ((stage) - STAGE_BASE)
V_39 = F_36 ( V_1 -> V_41 ) ;
F_19 ( & V_10 -> V_42 , V_25 ) ;
if ( ! V_10 -> V_16 )
goto V_43;
F_15 (plane, crtc) {
enum V_44 T_3 =
F_37 ( V_18 -> V_29 ) -> T_3 ;
F_38 ( T_3 > V_39 -> V_19 . V_45 ) ;
F_39 ( V_1 ,
F_40 ( V_19 , F_35 ( T_3 ) ) ,
F_41 ( V_46 ) |
F_42 ( V_47 ) ) ;
F_39 ( V_1 , F_43 ( V_19 ,
F_35 ( T_3 ) ) , 0xff ) ;
F_39 ( V_1 , F_44 ( V_19 ,
F_35 ( T_3 ) ) , 0x00 ) ;
V_40 |= F_45 ( F_46 ( V_18 ) , T_3 ) ;
F_11 ( L_3 , V_10 -> V_15 ,
F_47 ( F_46 ( V_18 ) ) , T_3 ) ;
}
F_11 ( L_4 , V_10 -> V_15 , V_19 , V_40 ) ;
F_23 ( V_10 -> V_16 , V_19 , V_40 ) ;
V_43:
F_21 ( & V_10 -> V_42 , V_25 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_25 ;
struct V_35 * V_36 ;
if ( F_14 ( ! V_3 -> V_29 ) )
return;
V_36 = & V_3 -> V_29 -> V_37 ;
F_11 ( L_5 ,
V_10 -> V_15 , V_36 -> V_11 . V_28 , V_36 -> V_15 ,
V_36 -> V_48 , V_36 -> clock ,
V_36 -> V_49 , V_36 -> V_50 ,
V_36 -> V_51 , V_36 -> V_52 ,
V_36 -> V_53 , V_36 -> V_54 ,
V_36 -> V_55 , V_36 -> V_56 ,
V_36 -> type , V_36 -> V_25 ) ;
F_19 ( & V_10 -> V_42 , V_25 ) ;
F_39 ( V_1 , F_49 ( V_10 -> V_19 ) ,
F_50 ( V_36 -> V_49 ) |
F_51 ( V_36 -> V_53 ) ) ;
F_21 ( & V_10 -> V_42 , V_25 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( L_6 , V_10 -> V_15 ) ;
if ( F_14 ( ! V_10 -> V_57 ) )
return;
if ( V_10 -> V_58 )
F_53 ( & V_1 -> V_11 , & V_10 -> V_59 ) ;
F_53 ( & V_1 -> V_11 , & V_10 -> V_60 ) ;
F_54 ( V_1 ) ;
V_10 -> V_57 = false ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( L_6 , V_10 -> V_15 ) ;
if ( F_14 ( V_10 -> V_57 ) )
return;
F_56 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_60 ) ;
if ( V_10 -> V_58 )
F_7 ( & V_1 -> V_11 , & V_10 -> V_59 ) ;
V_10 -> V_57 = true ;
}
static int F_57 ( const void * V_61 , const void * V_62 )
{
struct V_63 * V_64 = (struct V_63 * ) V_61 ;
struct V_63 * V_65 = (struct V_63 * ) V_62 ;
return V_64 -> V_29 -> V_66 - V_65 -> V_29 -> V_66 ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_67 * V_29 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_63 V_68 [ V_69 + 1 ] ;
int V_70 = 0 , V_71 ;
F_11 ( L_7 , V_10 -> V_15 ) ;
if ( V_29 -> V_30 && ! V_10 -> V_16 ) {
V_10 -> V_16 = F_59 ( V_1 -> V_72 , V_3 ) ;
if ( F_14 ( ! V_10 -> V_16 ) )
return - V_73 ;
}
F_60 (plane, state) {
struct V_74 * V_75 ;
if ( V_70 >= F_61 ( V_68 ) ) {
F_62 ( V_6 -> V_6 , L_8 ) ;
return - V_73 ;
}
V_75 = V_29 -> V_29 -> V_76 [ F_63 ( V_18 ) ] ;
if ( ! V_75 )
V_75 = V_18 -> V_29 ;
V_68 [ V_70 ] . V_18 = V_18 ;
V_68 [ V_70 ] . V_29 = F_37 ( V_75 ) ;
V_70 ++ ;
}
F_64 ( V_68 , V_70 , sizeof( V_68 [ 0 ] ) , F_57 , NULL ) ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
V_68 [ V_71 ] . V_29 -> T_3 = V_77 + V_71 ;
F_11 ( L_9 , V_10 -> V_15 ,
F_47 ( F_46 ( V_68 [ V_71 ] . V_18 ) ) ,
V_68 [ V_71 ] . V_29 -> T_3 ) ;
}
return 0 ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_11 ( L_10 , V_10 -> V_15 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
unsigned long V_25 ;
F_11 ( L_11 , V_10 -> V_15 , V_3 -> V_29 -> V_24 ) ;
F_14 ( V_10 -> V_24 ) ;
F_19 ( & V_6 -> V_26 , V_25 ) ;
V_10 -> V_24 = V_3 -> V_29 -> V_24 ;
F_21 ( & V_6 -> V_26 , V_25 ) ;
if ( F_67 ( ! V_10 -> V_16 ) )
return;
F_34 ( V_3 ) ;
if ( V_10 -> V_58 )
F_8 ( V_3 ) ;
V_10 -> V_78 = F_13 ( V_3 ) ;
F_4 ( V_3 , V_79 ) ;
}
static int F_68 ( struct V_2 * V_3 ,
struct V_80 * V_81 , T_4 V_33 )
{
return - V_73 ;
}
static void F_69 ( struct V_2 * V_3 , T_1 * V_82 , T_1 * V_83 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_84 = V_3 -> V_36 . V_49 ;
T_1 V_85 = V_3 -> V_36 . V_53 ;
* V_82 = F_70 ( V_10 -> V_86 . V_87 , V_84 -
V_10 -> V_86 . V_88 ) ;
* V_83 = F_70 ( V_10 -> V_86 . V_89 , V_85 -
V_10 -> V_86 . V_90 ) ;
}
static int F_71 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_91 ,
T_1 V_87 , T_1 V_89 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_92 * V_93 , * V_94 = NULL ;
T_1 V_95 , V_96 , V_97 ;
int V_98 , V_99 , V_19 ;
unsigned int V_100 ;
enum V_101 V_102 = V_103 ;
T_1 V_14 = F_72 ( 0 ) ;
T_1 V_82 , V_83 ;
bool V_104 = true ;
unsigned long V_25 ;
if ( ( V_87 > V_105 ) || ( V_89 > V_106 ) ) {
F_62 ( V_6 -> V_6 , L_12 , V_87 , V_89 ) ;
return - V_73 ;
}
if ( NULL == V_10 -> V_16 )
return - V_73 ;
if ( ! V_91 ) {
F_11 ( L_13 ) ;
V_104 = false ;
goto V_107;
}
V_93 = F_73 ( V_6 , V_21 , V_91 ) ;
if ( ! V_93 )
return - V_108 ;
V_98 = F_74 ( V_93 , V_1 -> V_28 , & V_96 ) ;
if ( V_98 )
return - V_73 ;
V_19 = V_10 -> V_19 ;
F_75 ( V_109 , & V_100 , & V_99 ) ;
V_97 = V_87 * ( V_99 >> 3 ) ;
F_19 ( & V_10 -> V_86 . V_110 , V_25 ) ;
V_94 = V_10 -> V_86 . V_111 ;
V_10 -> V_86 . V_111 = V_93 ;
V_10 -> V_86 . V_87 = V_87 ;
V_10 -> V_86 . V_89 = V_89 ;
F_69 ( V_3 , & V_82 , & V_83 ) ;
F_39 ( V_1 , F_76 ( V_19 ) , V_97 ) ;
F_39 ( V_1 , F_77 ( V_19 ) ,
F_78 ( V_112 ) ) ;
F_39 ( V_1 , F_79 ( V_19 ) ,
F_80 ( V_89 ) |
F_81 ( V_87 ) ) ;
F_39 ( V_1 , F_82 ( V_19 ) ,
F_83 ( V_83 ) |
F_84 ( V_82 ) ) ;
F_39 ( V_1 , F_85 ( V_19 ) , V_96 ) ;
V_95 = V_113 ;
V_95 |= F_86 ( V_102 ) ;
F_39 ( V_1 , F_87 ( V_19 ) , V_95 ) ;
F_21 ( & V_10 -> V_86 . V_110 , V_25 ) ;
V_107:
V_98 = F_88 ( V_10 -> V_16 , 0 , V_104 ) ;
if ( V_98 ) {
F_62 ( V_6 -> V_6 , L_14 ,
V_104 ? L_15 : L_16 , V_98 ) ;
goto V_114;
}
F_10 ( V_3 , V_14 ) ;
V_114:
if ( V_94 ) {
F_89 ( & V_10 -> V_34 , V_94 ) ;
F_4 ( V_3 , V_115 ) ;
}
return V_98 ;
}
static int F_90 ( struct V_2 * V_3 , int V_88 , int V_90 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_14 = F_72 ( 0 ) ;
T_1 V_82 ;
T_1 V_83 ;
unsigned long V_25 ;
if ( F_67 ( ! V_3 -> V_29 -> V_30 ) )
return 0 ;
V_10 -> V_86 . V_88 = V_88 = F_91 ( V_88 , 0 ) ;
V_10 -> V_86 . V_90 = V_90 = F_91 ( V_90 , 0 ) ;
F_69 ( V_3 , & V_82 , & V_83 ) ;
F_19 ( & V_10 -> V_86 . V_110 , V_25 ) ;
F_39 ( V_1 , F_82 ( V_10 -> V_19 ) ,
F_83 ( V_83 ) |
F_84 ( V_82 ) ) ;
F_39 ( V_1 , F_92 ( V_10 -> V_19 ) ,
F_93 ( V_90 ) |
F_94 ( V_88 ) ) ;
F_21 ( & V_10 -> V_86 . V_110 , V_25 ) ;
F_10 ( V_3 , V_14 ) ;
return 0 ;
}
static void F_95 ( struct V_116 * V_117 , T_1 V_118 )
{
struct V_10 * V_10 = F_26 ( V_117 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_53 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_96 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_79 ) {
F_18 ( V_3 , NULL ) ;
}
if ( V_9 & V_115 )
F_97 ( & V_10 -> V_34 , V_5 -> V_119 ) ;
}
static void F_98 ( struct V_116 * V_117 , T_1 V_118 )
{
struct V_10 * V_10 = F_26 ( V_117 , struct V_10 , V_60 ) ;
F_11 ( L_17 , V_10 -> V_15 , V_118 ) ;
}
static void F_99 ( struct V_116 * V_117 , T_1 V_118 )
{
struct V_10 * V_10 = F_26 ( V_117 , struct V_10 ,
V_59 ) ;
F_100 ( & V_10 -> V_13 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_98 ;
V_98 = F_102 ( & V_10 -> V_13 ,
F_103 ( 50 ) ) ;
if ( V_98 == 0 )
F_104 ( V_6 -> V_6 , L_18 , V_10 -> V_19 ) ;
}
static void F_105 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_98 ;
if ( ! V_10 -> V_16 )
return;
V_98 = F_106 ( V_3 ) ;
if ( V_98 )
return;
V_98 = F_107 ( V_6 -> V_12 [ F_108 ( V_3 ) ] . V_120 ,
( ( F_109 ( V_10 -> V_16 ) &
V_10 -> V_78 ) == 0 ) ,
F_103 ( 50 ) ) ;
if ( V_98 <= 0 )
F_104 ( V_6 -> V_6 , L_19 , V_10 -> V_28 ) ;
V_10 -> V_78 = 0 ;
F_110 ( V_3 ) ;
}
T_1 F_111 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_121 ;
}
void F_112 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
F_11 ( L_20 , V_21 ) ;
F_18 ( V_3 , V_21 ) ;
}
void F_113 ( struct V_2 * V_3 , struct V_122 * V_123 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_19 = F_114 ( V_3 ) ;
V_10 -> V_60 . V_121 = F_115 ( V_123 -> V_124 ) ;
V_10 -> V_12 . V_121 = F_116 ( V_19 , V_123 ) ;
if ( ( V_123 -> type == V_125 ) &&
( V_123 -> V_36 == V_126 ) ) {
V_10 -> V_59 . V_121 = F_117 ( V_19 ) ;
V_10 -> V_59 . V_117 = F_99 ;
V_10 -> V_58 = true ;
} else {
V_10 -> V_59 . V_121 = 0 ;
V_10 -> V_59 . V_117 = NULL ;
V_10 -> V_58 = false ;
}
F_118 ( & V_1 -> V_11 ) ;
F_119 ( V_10 -> V_16 , V_123 ) ;
}
int F_114 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_14 ( ! V_3 ) ? - V_73 : V_10 -> V_19 ;
}
struct V_127 * F_120 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_14 ( ! V_3 ) ? NULL : V_10 -> V_16 ;
}
void F_121 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
if ( V_10 -> V_58 )
F_101 ( V_3 ) ;
else
F_105 ( V_3 ) ;
}
struct V_2 * F_122 ( struct V_22 * V_6 ,
struct V_17 * V_18 , int V_28 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_123 ( sizeof( * V_10 ) , V_128 ) ;
if ( ! V_10 )
return F_124 ( - V_129 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_19 = F_125 ( V_28 ) ;
F_126 ( & V_10 -> V_42 ) ;
F_126 ( & V_10 -> V_86 . V_110 ) ;
F_127 ( & V_10 -> V_13 ) ;
V_10 -> V_12 . V_117 = F_95 ;
V_10 -> V_60 . V_117 = F_98 ;
snprintf ( V_10 -> V_15 , sizeof( V_10 -> V_15 ) , L_21 ,
F_47 ( F_46 ( V_18 ) ) , V_28 ) ;
F_128 ( V_6 , V_3 , V_18 , NULL , & V_130 ) ;
F_129 ( & V_10 -> V_34 ,
L_22 , F_25 ) ;
F_130 ( V_3 , & V_131 ) ;
V_18 -> V_3 = V_3 ;
F_131 ( V_18 , & V_3 -> V_11 ) ;
return V_3 ;
}
