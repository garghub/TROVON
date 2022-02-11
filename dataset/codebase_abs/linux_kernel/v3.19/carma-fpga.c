static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
}
static int F_5 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_7 -> V_12 = F_6 ( V_8 << V_13 ) ;
if ( NULL == V_7 -> V_12 ) {
F_7 ( L_1 , V_8 ) ;
return - V_14 ;
}
F_7 ( L_2 ,
( unsigned long ) V_7 -> V_12 ,
V_8 << V_13 ) ;
memset ( V_7 -> V_12 , 0 , V_8 << V_13 ) ;
V_7 -> V_8 = V_8 ;
V_7 -> V_15 = F_8 ( V_7 -> V_8 * sizeof( * V_7 -> V_15 ) ) ;
if ( NULL == V_7 -> V_15 )
goto V_16;
F_9 ( V_7 -> V_15 , V_7 -> V_8 ) ;
for ( V_11 = 0 ; V_11 < V_7 -> V_8 ; V_11 ++ ) {
V_10 = F_10 ( V_7 -> V_12 + V_11 * V_17 ) ;
if ( NULL == V_10 )
goto V_18;
F_11 ( & V_7 -> V_15 [ V_11 ] , V_10 , V_17 , 0 ) ;
}
return 0 ;
V_18:
F_12 ( V_7 -> V_15 ) ;
V_7 -> V_15 = NULL ;
V_16:
F_12 ( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
return - V_14 ;
}
static int F_13 ( struct V_19 * V_20 , struct V_6 * V_7 )
{
V_7 -> V_21 = F_14 ( V_20 , V_7 -> V_15 ,
V_7 -> V_8 , V_22 ) ;
if ( 0 == V_7 -> V_21 ) {
F_15 ( L_3 , V_23 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_16 ( struct V_19 * V_20 , struct V_6 * V_7 )
{
if ( ! V_7 -> V_21 )
return 0 ;
F_17 ( V_20 , V_7 -> V_15 , V_7 -> V_21 , V_22 ) ;
V_7 -> V_21 = 0 ;
return 0 ;
}
static void F_18 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_12 ( V_7 -> V_15 ) ;
F_12 ( V_7 -> V_12 ) ;
F_4 ( V_7 ) ;
}
static struct V_6 * F_19 ( const T_1 V_24 )
{
unsigned int V_8 ;
struct V_6 * V_7 ;
int V_25 ;
V_8 = F_20 ( V_24 , V_17 ) ;
V_7 = F_21 ( sizeof( * V_7 ) , V_26 ) ;
if ( ! V_7 )
goto V_27;
F_22 ( & V_7 -> V_28 ) ;
V_7 -> V_29 = V_24 ;
V_25 = F_5 ( V_7 , V_8 ) ;
if ( V_25 )
goto V_30;
return V_7 ;
V_30:
F_4 ( V_7 ) ;
V_27:
return NULL ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_6 * V_7 , * V_31 ;
F_24 ( V_4 -> V_32 != NULL ) ;
F_25 (buf, tmp, &priv->free, entry) {
F_26 ( & V_7 -> V_28 ) ;
F_16 ( V_4 -> V_20 , V_7 ) ;
F_18 ( V_7 ) ;
}
F_25 (buf, tmp, &priv->used, entry) {
F_26 ( & V_7 -> V_28 ) ;
F_16 ( V_4 -> V_20 , V_7 ) ;
F_18 ( V_7 ) ;
}
V_4 -> V_33 = 0 ;
V_4 -> V_34 = 0 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_11 , V_25 ;
for ( V_11 = 0 ; V_11 < V_35 ; V_11 ++ ) {
V_7 = F_19 ( V_4 -> V_34 ) ;
if ( ! V_7 )
break;
V_25 = F_13 ( V_4 -> V_20 , V_7 ) ;
if ( V_25 ) {
F_18 ( V_7 ) ;
break;
}
F_28 ( & V_7 -> V_28 , & V_4 -> free ) ;
V_4 -> V_33 ++ ;
}
if ( V_4 -> V_33 < V_36 ) {
F_29 ( V_4 -> V_20 , L_4 ) ;
F_23 ( V_4 ) ;
return - V_14 ;
}
if ( V_4 -> V_33 < V_35 ) {
F_30 ( V_4 -> V_20 ,
L_5 ,
V_35 , V_11 ) ;
}
return 0 ;
}
static T_2 F_31 ( struct V_3 * V_4 , unsigned int V_37 )
{
return V_4 -> V_38 + 0x400000 + ( 0x80000 * V_37 ) ;
}
static T_2 F_32 ( struct V_3 * V_4 , unsigned int V_37 ,
unsigned int V_39 )
{
return F_31 ( V_4 , V_37 ) + ( 0x10000 * ( 1 + V_39 ) ) ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_40 * V_41 = & V_4 -> V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
int V_11 , V_47 , V_25 ;
V_4 -> V_48 = ( 1 + V_49 ) * V_50 ;
for ( V_11 = 0 ; V_11 < V_49 ; V_11 ++ )
V_4 -> V_48 += V_4 -> V_46 [ V_11 ] . V_51 ;
V_25 = F_34 ( V_41 , V_4 -> V_48 , V_26 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_6 ) ;
return V_25 ;
}
V_44 = V_41 -> V_52 ;
for ( V_11 = 0 ; V_11 < V_49 ; V_11 ++ ) {
F_35 ( V_44 ) = F_31 ( V_4 , V_11 ) ;
F_36 ( V_44 ) = V_50 ;
V_44 = F_37 ( V_44 ) ;
}
F_35 ( V_44 ) = V_53 ;
F_36 ( V_44 ) = V_50 ;
V_44 = F_37 ( V_44 ) ;
for ( V_11 = 0 ; V_11 < V_49 ; V_11 ++ ) {
V_46 = & V_4 -> V_46 [ V_11 ] ;
for ( V_47 = 0 ; V_47 < V_46 -> V_51 ; V_47 ++ ) {
F_35 ( V_44 ) = F_32 ( V_4 , V_11 , V_47 ) ;
F_36 ( V_44 ) = V_46 -> V_54 ;
V_44 = F_37 ( V_44 ) ;
}
}
return 0 ;
}
static void F_38 ( struct V_3 * V_4 , unsigned int V_37 ,
unsigned int V_55 , T_3 V_56 )
{
const int V_57 = V_58 + ( V_37 * V_59 ) ;
F_39 ( V_56 , V_4 -> V_60 + V_57 + V_55 ) ;
}
static T_3 F_40 ( struct V_3 * V_4 , unsigned int V_37 ,
unsigned int V_55 )
{
const int V_57 = V_58 + ( V_37 * V_59 ) ;
return F_41 ( V_4 -> V_60 + V_57 + V_55 ) ;
}
static int F_42 ( struct V_3 * V_4 )
{
T_3 V_61 , V_62 , V_63 , V_64 , V_65 ;
T_3 V_66 , V_67 , V_68 ;
T_3 V_51 , V_54 ;
int V_11 ;
V_4 -> V_34 = ( 1 + V_49 ) * V_50 ;
for ( V_11 = 0 ; V_11 < V_49 ; V_11 ++ ) {
V_68 = F_40 ( V_4 , V_11 , V_69 ) ;
V_66 = F_40 ( V_4 , V_11 , V_70 ) ;
V_67 = F_40 ( V_4 , V_11 , V_71 ) ;
if ( ( V_68 & 0x000000FF ) >= 2 ) {
V_61 = ( V_66 & 0x000000F0 ) >> 4 ;
V_65 = ( V_66 & 0x00000F00 ) >> 8 ;
V_62 = ( V_66 & 0x00FFF000 ) >> 12 ;
V_63 = ( V_66 & 0x7F000000 ) >> 24 ;
V_64 = ( V_67 & 0x00000FFF ) >> 0 ;
} else {
V_61 = ( V_66 & 0x000000F0 ) >> 4 ;
V_65 = 1 ;
V_62 = ( V_66 & 0x000FFF00 ) >> 8 ;
V_63 = ( V_66 & 0x7FF00000 ) >> 20 ;
V_64 = ( V_67 & 0x00000FFF ) >> 0 ;
}
V_51 = ( V_61 + V_65 - 1 ) / V_65 ;
V_54 = ( ( V_65 * V_62 ) + V_63 + V_64 ) * 8 ;
V_4 -> V_46 [ V_11 ] . V_51 = V_51 ;
V_4 -> V_46 [ V_11 ] . V_54 = V_54 ;
V_4 -> V_34 += V_51 * V_54 ;
F_43 ( V_4 -> V_20 , L_7 , V_11 , V_61 ) ;
F_43 ( V_4 -> V_20 , L_8 , V_11 , V_65 ) ;
F_43 ( V_4 -> V_20 , L_9 , V_11 , V_62 ) ;
F_43 ( V_4 -> V_20 , L_10 , V_11 , V_63 ) ;
F_43 ( V_4 -> V_20 , L_11 , V_11 , V_64 ) ;
F_43 ( V_4 -> V_20 , L_12 , V_11 , V_54 ) ;
}
F_43 ( V_4 -> V_20 , L_13 , V_4 -> V_34 ) ;
return 0 ;
}
static void F_44 ( struct V_3 * V_4 )
{
F_39 ( 0x2F , V_4 -> V_60 + V_72 ) ;
}
static void F_45 ( struct V_3 * V_4 )
{
F_38 ( V_4 , 0 , V_73 , 0x0 ) ;
F_38 ( V_4 , 1 , V_73 , 0x0 ) ;
F_38 ( V_4 , 2 , V_73 , 0x0 ) ;
F_38 ( V_4 , 3 , V_73 , 0x0 ) ;
F_40 ( V_4 , 0 , V_73 ) ;
F_40 ( V_4 , 1 , V_73 ) ;
F_40 ( V_4 , 2 , V_73 ) ;
F_40 ( V_4 , 3 , V_73 ) ;
F_39 ( 0x3F , V_4 -> V_60 + V_72 ) ;
}
static void F_46 ( void * V_74 )
{
struct V_3 * V_4 = V_74 ;
unsigned long V_75 ;
F_47 ( & V_4 -> V_76 , V_75 ) ;
F_24 ( V_4 -> V_32 == NULL ) ;
F_48 ( & V_4 -> V_32 -> V_28 , & V_4 -> V_77 ) ;
V_4 -> V_32 = NULL ;
if ( V_4 -> V_78 )
F_45 ( V_4 ) ;
F_49 ( & V_4 -> V_76 , V_75 ) ;
F_50 ( & V_4 -> V_79 ) ;
}
static int F_51 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
struct V_43 * V_80 , * V_81 ;
unsigned int V_82 , V_83 ;
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_86 * V_87 ;
T_4 V_88 ;
T_2 V_89 , V_90 ;
unsigned long V_91 = 0 ;
V_80 = V_7 -> V_15 ;
V_82 = V_7 -> V_21 ;
V_81 = V_4 -> V_42 . V_52 ;
V_83 = V_4 -> V_48 ;
V_87 = V_85 -> V_19 -> V_92 ( V_85 ,
V_80 , V_82 ,
V_81 , V_83 ,
0 ) ;
if ( ! V_87 ) {
F_29 ( V_4 -> V_20 , L_14 ) ;
return - V_14 ;
}
V_88 = V_87 -> V_93 ( V_87 ) ;
if ( F_52 ( V_88 ) ) {
F_29 ( V_4 -> V_20 , L_15 ) ;
return - V_14 ;
}
V_89 = F_35 ( V_80 ) + ( V_49 * V_50 ) ;
V_90 = V_53 ;
V_87 = V_85 -> V_19 -> V_94 ( V_85 , V_89 , V_90 ,
V_50 ,
V_91 ) ;
if ( ! V_87 ) {
F_29 ( V_4 -> V_20 , L_16 ) ;
return - V_14 ;
}
V_87 -> V_95 = F_46 ;
V_87 -> V_96 = V_4 ;
V_88 = V_87 -> V_93 ( V_87 ) ;
if ( F_52 ( V_88 ) ) {
F_29 ( V_4 -> V_20 , L_17 ) ;
return - V_14 ;
}
return 0 ;
}
static T_5 F_53 ( int V_97 , void * V_98 )
{
struct V_3 * V_4 = V_98 ;
bool V_99 = false ;
struct V_6 * V_7 ;
T_3 V_100 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_100 = F_40 ( V_4 , V_11 , V_73 ) ;
if ( ! ( V_100 & ( V_101 | V_102 ) ) ) {
F_29 ( V_4 -> V_20 , L_18 ) ;
return V_103 ;
}
}
V_100 = F_41 ( V_4 -> V_60 + V_104 ) ;
if ( V_100 & V_105 ) {
F_29 ( V_4 -> V_20 , L_19 ) ;
return V_103 ;
}
F_54 ( & V_4 -> V_76 ) ;
F_24 ( V_4 -> V_32 != NULL ) ;
F_44 ( V_4 ) ;
if ( F_55 ( & V_4 -> free ) ) {
V_4 -> V_106 ++ ;
goto V_107;
}
V_7 = F_56 ( & V_4 -> free , struct V_6 , V_28 ) ;
F_26 ( & V_7 -> V_28 ) ;
F_24 ( V_7 -> V_29 != V_4 -> V_34 ) ;
if ( F_51 ( V_4 , V_7 ) ) {
F_29 ( V_4 -> V_20 , L_20 ) ;
F_48 ( & V_7 -> V_28 , & V_4 -> free ) ;
goto V_107;
}
V_4 -> V_32 = V_7 ;
V_99 = true ;
F_57 ( V_4 -> V_85 ) ;
V_107:
if ( ! V_99 )
F_45 ( V_4 ) ;
F_58 ( & V_4 -> V_76 ) ;
return V_108 ;
}
static int F_59 ( struct V_3 * V_4 )
{
bool V_78 ;
T_3 V_56 ;
int V_25 ;
F_60 ( & V_4 -> V_76 ) ;
V_78 = V_4 -> V_78 ;
F_61 ( & V_4 -> V_76 ) ;
if ( V_78 )
return 0 ;
V_56 = F_41 ( V_4 -> V_60 + V_109 ) ;
if ( ! ( V_56 & ( 1 << 18 ) ) ) {
F_29 ( V_4 -> V_20 , L_21 ) ;
return - V_110 ;
}
V_25 = F_42 ( V_4 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_22 ) ;
goto V_111;
}
V_25 = F_27 ( V_4 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_23 ) ;
goto V_111;
}
V_25 = F_33 ( V_4 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_24 ) ;
goto V_111;
}
F_44 ( V_4 ) ;
V_25 = F_62 ( V_4 -> V_97 , F_53 , V_112 , V_113 , V_4 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_25 ) ;
goto V_111;
}
F_60 ( & V_4 -> V_76 ) ;
V_4 -> V_78 = true ;
F_61 ( & V_4 -> V_76 ) ;
F_45 ( V_4 ) ;
return 0 ;
V_111:
F_63 ( & V_4 -> V_42 ) ;
V_4 -> V_48 = 0 ;
F_23 ( V_4 ) ;
return V_25 ;
}
static int F_64 ( struct V_3 * V_4 )
{
F_60 ( & V_4 -> V_76 ) ;
if ( ! V_4 -> V_78 ) {
F_61 ( & V_4 -> V_76 ) ;
return 0 ;
}
V_4 -> V_78 = false ;
F_44 ( V_4 ) ;
while ( V_4 -> V_32 != NULL ) {
F_61 ( & V_4 -> V_76 ) ;
F_65 ( V_4 -> V_79 , V_4 -> V_32 == NULL ) ;
F_60 ( & V_4 -> V_76 ) ;
}
F_61 ( & V_4 -> V_76 ) ;
F_66 ( V_4 -> V_97 , V_4 ) ;
F_63 ( & V_4 -> V_42 ) ;
V_4 -> V_48 = 0 ;
F_23 ( V_4 ) ;
return 0 ;
}
static unsigned int F_67 ( struct V_114 * V_115 )
{
struct V_114 * V_28 ;
unsigned int V_25 = 0 ;
F_68 (entry, list)
V_25 ++ ;
return V_25 ;
}
static int F_69 ( struct V_116 * V_117 , void * V_118 )
{
struct V_3 * V_4 = V_117 -> V_119 ;
F_60 ( & V_4 -> V_76 ) ;
F_70 ( V_117 , L_26 , V_4 -> V_78 ) ;
F_70 ( V_117 , L_27 , V_4 -> V_34 ) ;
F_70 ( V_117 , L_28 , V_4 -> V_33 ) ;
F_70 ( V_117 , L_29 , F_67 ( & V_4 -> free ) ) ;
F_70 ( V_117 , L_30 , V_4 -> V_32 != NULL ) ;
F_70 ( V_117 , L_31 , F_67 ( & V_4 -> V_77 ) ) ;
F_70 ( V_117 , L_32 , V_4 -> V_106 ) ;
F_61 ( & V_4 -> V_76 ) ;
return 0 ;
}
static int F_71 ( struct V_120 * V_120 , struct V_121 * V_121 )
{
return F_72 ( V_121 , F_69 , V_120 -> V_122 ) ;
}
static int F_73 ( struct V_3 * V_4 )
{
V_4 -> V_123 = F_74 ( V_113 , V_124 , NULL , V_4 ,
& V_125 ) ;
return F_75 ( V_4 -> V_123 ) ;
}
static void F_76 ( struct V_3 * V_4 )
{
F_77 ( V_4 -> V_123 ) ;
}
static inline int F_73 ( struct V_3 * V_4 )
{
return 0 ;
}
static inline void F_76 ( struct V_3 * V_4 )
{
}
static T_6 F_78 ( struct V_19 * V_20 , struct V_126 * V_127 ,
char * V_7 )
{
struct V_3 * V_4 = F_79 ( V_20 ) ;
int V_25 ;
F_60 ( & V_4 -> V_76 ) ;
V_25 = snprintf ( V_7 , V_17 , L_33 , V_4 -> V_78 ) ;
F_61 ( & V_4 -> V_76 ) ;
return V_25 ;
}
static T_6 F_80 ( struct V_19 * V_20 , struct V_126 * V_127 ,
const char * V_7 , T_1 V_128 )
{
struct V_3 * V_4 = F_79 ( V_20 ) ;
unsigned long V_129 ;
int V_25 ;
V_25 = F_81 ( V_7 , 0 , & V_129 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_34 ) ;
return V_25 ;
}
V_25 = F_82 ( & V_4 -> V_5 ) ;
if ( V_25 )
return V_25 ;
if ( V_129 )
V_25 = F_59 ( V_4 ) ;
else
V_25 = F_64 ( V_4 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_35 ,
V_129 ? L_36 : L_37 ) ;
V_128 = V_25 ;
goto V_130;
}
V_130:
F_83 ( & V_4 -> V_5 ) ;
return V_128 ;
}
static int F_84 ( struct V_120 * V_120 , struct V_121 * V_131 )
{
struct V_3 * V_4 = F_2 ( V_131 -> V_132 ,
struct V_3 , V_133 ) ;
struct V_134 * V_135 ;
int V_25 ;
V_135 = F_21 ( sizeof( * V_135 ) , V_26 ) ;
if ( ! V_135 )
return - V_14 ;
V_135 -> V_4 = V_4 ;
V_135 -> V_7 = NULL ;
V_131 -> V_132 = V_135 ;
V_25 = F_85 ( V_120 , V_131 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_38 ) ;
F_4 ( V_135 ) ;
return V_25 ;
}
F_86 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_120 * V_120 , struct V_121 * V_131 )
{
struct V_134 * V_135 = V_131 -> V_132 ;
struct V_3 * V_4 = V_135 -> V_4 ;
F_18 ( V_135 -> V_7 ) ;
F_4 ( V_135 ) ;
V_131 -> V_132 = NULL ;
F_88 ( & V_4 -> V_2 , F_1 ) ;
return 0 ;
}
static T_6 F_89 ( struct V_121 * V_131 , char T_7 * V_136 , T_1 V_128 ,
T_8 * V_137 )
{
struct V_134 * V_135 = V_131 -> V_132 ;
struct V_3 * V_4 = V_135 -> V_4 ;
struct V_114 * V_77 = & V_4 -> V_77 ;
bool V_138 = false ;
struct V_6 * V_139 ;
T_1 V_140 ;
void * V_74 ;
int V_25 ;
if ( V_135 -> V_7 ) {
V_139 = V_135 -> V_7 ;
goto V_141;
}
F_60 ( & V_4 -> V_76 ) ;
while ( F_55 ( V_77 ) ) {
F_61 ( & V_4 -> V_76 ) ;
if ( V_131 -> V_142 & V_143 )
return - V_144 ;
V_25 = F_90 ( V_4 -> V_79 , ! F_55 ( V_77 ) ) ;
if ( V_25 )
return V_25 ;
F_60 ( & V_4 -> V_76 ) ;
}
V_139 = F_56 ( V_77 , struct V_6 , V_28 ) ;
F_26 ( & V_139 -> V_28 ) ;
F_61 ( & V_4 -> V_76 ) ;
F_16 ( V_4 -> V_20 , V_139 ) ;
V_135 -> V_7 = V_139 ;
V_135 -> V_145 = 0 ;
V_141:
V_140 = V_139 -> V_29 - V_135 -> V_145 ;
V_74 = V_139 -> V_12 + V_135 -> V_145 ;
V_128 = F_91 ( V_128 , V_140 ) ;
if ( F_92 ( V_136 , V_74 , V_128 ) )
return - V_146 ;
V_140 -= V_128 ;
if ( V_140 > 0 ) {
V_135 -> V_145 += V_128 ;
V_135 -> V_7 = V_139 ;
return V_128 ;
}
V_25 = F_13 ( V_4 -> V_20 , V_139 ) ;
if ( V_25 ) {
F_29 ( V_4 -> V_20 , L_39 ) ;
return - V_146 ;
}
F_60 ( & V_4 -> V_76 ) ;
V_135 -> V_7 = NULL ;
if ( ! V_4 -> V_78 || V_139 -> V_29 != V_4 -> V_34 ) {
V_138 = true ;
goto V_130;
}
F_28 ( & V_139 -> V_28 , & V_4 -> free ) ;
V_130:
F_61 ( & V_4 -> V_76 ) ;
if ( V_138 ) {
F_16 ( V_4 -> V_20 , V_139 ) ;
F_18 ( V_139 ) ;
}
return V_128 ;
}
static unsigned int F_93 ( struct V_121 * V_131 , struct V_147 * V_148 )
{
struct V_134 * V_135 = V_131 -> V_132 ;
struct V_3 * V_4 = V_135 -> V_4 ;
unsigned int V_149 = 0 ;
F_94 ( V_131 , & V_4 -> V_79 , V_148 ) ;
if ( ! F_55 ( & V_4 -> V_77 ) )
V_149 |= V_150 | V_151 ;
return V_149 ;
}
static int F_95 ( struct V_121 * V_131 , struct V_152 * V_153 )
{
struct V_134 * V_135 = V_131 -> V_132 ;
struct V_3 * V_4 = V_135 -> V_4 ;
unsigned long V_118 , V_154 , V_155 , V_156 ;
V_118 = V_153 -> V_157 << V_13 ;
V_154 = V_153 -> V_158 - V_153 -> V_159 ;
V_155 = V_4 -> V_160 - V_118 ;
V_156 = ( V_4 -> V_38 + V_118 ) >> V_13 ;
if ( V_154 > V_155 ) {
F_29 ( V_4 -> V_20 , L_40 ) ;
return - V_161 ;
}
V_153 -> V_162 = F_96 ( V_153 -> V_162 ) ;
return F_97 ( V_153 , V_153 -> V_159 , V_156 , V_154 ,
V_153 -> V_162 ) ;
}
static bool F_98 ( struct V_84 * V_85 , void * V_74 )
{
if ( V_85 -> V_163 == 0 && V_85 -> V_19 -> V_98 == 0 )
return false ;
return true ;
}
static int F_99 ( struct V_164 * V_165 )
{
struct V_166 * V_167 = V_165 -> V_20 . V_167 ;
struct V_19 * V_168 ;
struct V_3 * V_4 ;
struct V_169 V_170 ;
T_9 V_149 ;
int V_25 ;
V_4 = F_21 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 ) {
F_29 ( & V_165 -> V_20 , L_41 ) ;
V_25 = - V_14 ;
goto V_27;
}
F_100 ( V_165 , V_4 ) ;
V_4 -> V_20 = & V_165 -> V_20 ;
F_101 ( & V_4 -> V_2 ) ;
F_102 ( & V_4 -> V_5 ) ;
F_103 ( V_4 -> V_20 , V_4 ) ;
F_104 ( & V_4 -> V_76 ) ;
F_22 ( & V_4 -> free ) ;
F_22 ( & V_4 -> V_77 ) ;
F_105 ( & V_4 -> V_79 ) ;
V_4 -> V_133 . V_171 = V_172 ;
V_4 -> V_133 . V_173 = V_113 ;
V_4 -> V_133 . V_174 = & V_175 ;
V_25 = F_106 ( V_167 , 0 , & V_170 ) ;
if ( V_25 ) {
F_29 ( & V_165 -> V_20 , L_42 ) ;
V_25 = - V_176 ;
goto V_177;
}
V_4 -> V_38 = V_170 . V_178 ;
V_4 -> V_160 = F_107 ( & V_170 ) ;
V_4 -> V_60 = F_108 ( V_167 , 0 ) ;
if ( ! V_4 -> V_60 ) {
F_29 ( & V_165 -> V_20 , L_43 ) ;
V_25 = - V_14 ;
goto V_177;
}
F_109 ( V_149 ) ;
F_110 ( V_179 , V_149 ) ;
F_110 ( V_180 , V_149 ) ;
F_110 ( V_181 , V_149 ) ;
F_110 ( V_182 , V_149 ) ;
V_4 -> V_85 = F_111 ( V_149 , F_98 , NULL ) ;
if ( ! V_4 -> V_85 ) {
F_29 ( & V_165 -> V_20 , L_44 ) ;
V_25 = - V_176 ;
goto V_183;
}
V_4 -> V_97 = F_112 ( V_167 , 0 ) ;
if ( V_4 -> V_97 == V_184 ) {
F_29 ( & V_165 -> V_20 , L_45 ) ;
V_25 = - V_176 ;
goto V_185;
}
F_39 ( V_105 , V_4 -> V_60 + V_186 ) ;
V_25 = F_113 ( & V_4 -> V_133 ) ;
if ( V_25 ) {
F_29 ( & V_165 -> V_20 , L_46 ) ;
goto V_187;
}
V_25 = F_73 ( V_4 ) ;
if ( V_25 ) {
F_29 ( & V_165 -> V_20 , L_47 ) ;
goto V_188;
}
V_168 = V_4 -> V_133 . V_168 ;
F_103 ( V_168 , V_4 ) ;
V_25 = F_114 ( & V_168 -> V_189 , & V_190 ) ;
if ( V_25 ) {
F_29 ( & V_165 -> V_20 , L_48 ) ;
goto V_191;
}
F_115 ( & V_165 -> V_20 , L_49 ) ;
return 0 ;
V_191:
F_76 ( V_4 ) ;
V_188:
F_116 ( & V_4 -> V_133 ) ;
V_187:
F_117 ( V_4 -> V_97 ) ;
V_185:
F_118 ( V_4 -> V_85 ) ;
V_183:
F_119 ( V_4 -> V_60 ) ;
V_177:
F_88 ( & V_4 -> V_2 , F_1 ) ;
V_27:
return V_25 ;
}
static int F_120 ( struct V_164 * V_165 )
{
struct V_3 * V_4 = F_121 ( V_165 ) ;
struct V_19 * V_168 = V_4 -> V_133 . V_168 ;
F_122 ( & V_168 -> V_189 , & V_190 ) ;
F_76 ( V_4 ) ;
F_64 ( V_4 ) ;
F_116 ( & V_4 -> V_133 ) ;
F_117 ( V_4 -> V_97 ) ;
F_118 ( V_4 -> V_85 ) ;
F_119 ( V_4 -> V_60 ) ;
F_88 ( & V_4 -> V_2 , F_1 ) ;
return 0 ;
}
