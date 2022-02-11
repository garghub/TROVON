void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , L_1 ,
V_2 -> V_4 ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_5 ) ;
F_2 ( V_2 , L_2 ,
& V_2 -> V_4 -> V_5 , V_3 ) ;
F_2 ( V_2 , L_3 ,
( unsigned int ) F_4 ( V_3 ) ) ;
#if 0
xhci_dbg(xhci, "// HCIVERSION: 0x%x\n",
(unsigned int) HC_VERSION(temp));
#endif
F_2 ( V_2 , L_4 , V_2 -> V_6 ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_7 ) ;
F_2 ( V_2 , L_5 ,
& V_2 -> V_4 -> V_7 ,
( unsigned int ) V_3 & V_8 ) ;
F_2 ( V_2 , L_6 , V_2 -> V_9 ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_10 ) ;
F_2 ( V_2 , L_7 , & V_2 -> V_4 -> V_10 , V_3 ) ;
F_2 ( V_2 , L_8 , V_2 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_12 ;
F_2 ( V_2 , L_9 , V_2 -> V_4 ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_5 ) ;
V_12 = F_6 ( V_3 ) ;
F_2 ( V_2 , L_10 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_11 ,
( unsigned int ) F_4 ( V_3 ) ) ;
F_2 ( V_2 , L_12 , V_12 ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_13 ) ;
F_2 ( V_2 , L_13 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_14 ,
( unsigned int ) F_7 ( V_3 ) ) ;
F_2 ( V_2 , L_15 ,
( unsigned int ) F_8 ( V_3 ) ) ;
F_2 ( V_2 , L_16 ,
( unsigned int ) F_9 ( V_3 ) ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_14 ) ;
F_2 ( V_2 , L_17 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_18 ,
( unsigned int ) F_10 ( V_3 ) ) ;
F_2 ( V_2 , L_19 ,
( unsigned int ) F_11 ( V_3 ) ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_15 ) ;
F_2 ( V_2 , L_20 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_21 ,
( unsigned int ) F_12 ( V_3 ) ) ;
F_2 ( V_2 , L_22 ,
( unsigned int ) F_13 ( V_3 ) ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_16 ) ;
F_2 ( V_2 , L_23 , ( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_24 ,
F_14 ( V_3 ) ? L_25 : L_26 ) ;
F_2 ( V_2 , L_27 ,
F_15 ( V_3 ) ? L_28 : L_29 ) ;
F_2 ( V_2 , L_30 ,
F_16 ( V_3 ) ? L_31 : L_32 ) ;
F_2 ( V_2 , L_33 ) ;
V_3 = F_3 ( & V_2 -> V_4 -> V_7 ) ;
F_2 ( V_2 , L_34 , V_3 & V_8 ) ;
if ( V_12 > 100 ) {
V_3 = F_3 ( & V_2 -> V_4 -> V_17 ) ;
F_2 ( V_2 , L_35 , ( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_36 ,
F_17 ( V_3 ) ? L_37 : L_38 ) ;
F_2 ( V_2 , L_39 ,
F_18 ( V_3 ) ? L_37 : L_38 ) ;
F_2 ( V_2 , L_40 ,
F_19 ( V_3 ) ? L_37 : L_38 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( & V_2 -> V_6 -> V_18 ) ;
F_2 ( V_2 , L_41 , V_3 ) ;
F_2 ( V_2 , L_42 ,
( V_3 & V_19 ) ? L_43 : L_44 ) ;
F_2 ( V_2 , L_45 ,
( V_3 & V_20 ) ? L_46 : L_47 ) ;
F_2 ( V_2 , L_48 ,
( V_3 & V_21 ) ? L_49 : L_50 ) ;
F_2 ( V_2 , L_51 ,
( V_3 & V_22 ) ? L_49 : L_50 ) ;
F_2 ( V_2 , L_52 ,
( V_3 & V_23 ) ? L_46 : L_47 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( & V_2 -> V_6 -> V_24 ) ;
F_2 ( V_2 , L_53 , V_3 ) ;
F_2 ( V_2 , L_54 ,
( V_3 & V_25 ) ? L_46 : L_47 ) ;
F_2 ( V_2 , L_55 ,
( V_3 & V_26 ) ? L_56 : L_57 ) ;
F_2 ( V_2 , L_42 ,
( V_3 & V_27 ) ? L_58 : L_43 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_59 , V_2 -> V_6 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_2 T_3 * V_28 ;
int V_29 , V_30 ;
int V_31 ;
char * V_32 [ V_33 ] = {
L_60 ,
L_61 ,
L_62 ,
L_63 ,
} ;
V_31 = F_9 ( V_2 -> V_13 ) ;
V_28 = & V_2 -> V_6 -> V_34 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
for ( V_30 = 0 ; V_30 < V_33 ; ++ V_30 ) {
F_2 ( V_2 , L_64 ,
V_28 , V_32 [ V_30 ] ,
( unsigned int ) F_3 ( V_28 ) ) ;
V_28 ++ ;
}
}
}
void F_24 ( struct V_1 * V_2 , int V_35 )
{
struct V_36 T_3 * V_37 = & V_2 -> V_9 -> V_37 [ V_35 ] ;
void T_3 * V_28 ;
T_1 V_3 ;
T_4 V_38 ;
V_28 = & V_37 -> V_39 ;
V_3 = F_3 ( V_28 ) ;
if ( V_3 == V_40 )
return;
F_2 ( V_2 , L_65 , V_37 , V_35 ) ;
F_2 ( V_2 , L_66 , V_28 ,
( unsigned int ) V_3 ) ;
V_28 = & V_37 -> V_41 ;
V_3 = F_3 ( V_28 ) ;
F_2 ( V_2 , L_67 , V_28 ,
( unsigned int ) V_3 ) ;
V_28 = & V_37 -> V_42 ;
V_3 = F_3 ( V_28 ) ;
F_2 ( V_2 , L_68 , V_28 ,
( unsigned int ) V_3 ) ;
V_28 = & V_37 -> V_43 ;
V_3 = F_3 ( V_28 ) ;
if ( V_3 != V_40 )
F_2 ( V_2 , L_69 ,
V_28 , ( unsigned int ) V_3 ) ;
V_28 = & V_37 -> V_44 ;
V_38 = F_25 ( V_2 , V_28 ) ;
F_2 ( V_2 , L_70 ,
V_28 , V_38 ) ;
V_28 = & V_37 -> V_45 ;
V_38 = F_25 ( V_2 , V_28 ) ;
F_2 ( V_2 , L_71 ,
V_28 , V_38 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_29 ;
F_2 ( V_2 , L_72 , V_2 -> V_9 ) ;
V_3 = F_3 ( & V_2 -> V_9 -> V_46 ) ;
F_2 ( V_2 , L_73 ,
& V_2 -> V_9 -> V_46 ,
( unsigned int ) V_3 ) ;
for ( V_29 = 0 ; V_29 < 7 ; ++ V_29 ) {
V_3 = F_3 ( & V_2 -> V_9 -> V_43 [ V_29 ] ) ;
if ( V_3 != V_40 )
F_2 ( V_2 , L_74 ,
& V_2 -> V_9 -> V_43 [ V_29 ] ,
V_29 , ( unsigned int ) V_3 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , union V_47 * V_48 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < 4 ; ++ V_29 )
F_2 ( V_2 , L_75 ,
V_29 * 4 , V_48 -> V_49 . V_50 [ V_29 ] ) ;
}
void F_29 ( struct V_1 * V_2 , union V_47 * V_48 )
{
T_4 V_51 ;
T_1 type = F_30 ( V_48 -> V_52 . V_53 ) & V_54 ;
switch ( type ) {
case F_31 ( V_55 ) :
F_2 ( V_2 , L_76 ) ;
F_28 ( V_2 , V_48 ) ;
V_51 = F_32 ( V_48 -> V_52 . V_56 ) ;
F_2 ( V_2 , L_77 , V_51 ) ;
F_2 ( V_2 , L_78 ,
F_33 ( F_30 ( V_48 -> V_52 . V_57 ) ) ) ;
F_2 ( V_2 , L_79 ,
F_30 ( V_48 -> V_52 . V_53 ) & V_58 ) ;
F_2 ( V_2 , L_80 ,
F_30 ( V_48 -> V_52 . V_53 ) & V_59 ) ;
F_2 ( V_2 , L_81 ,
F_30 ( V_48 -> V_52 . V_53 ) & V_60 ) ;
break;
case F_31 ( V_61 ) :
V_51 = F_32 ( V_48 -> V_62 . V_63 ) ;
F_2 ( V_2 , L_82 , V_51 ) ;
break;
case F_31 ( V_64 ) :
V_51 = F_32 ( V_48 -> V_65 . V_66 ) ;
F_2 ( V_2 , L_83 , V_51 ) ;
F_2 ( V_2 , L_84 ,
F_34 ( F_30 ( V_48 -> V_65 . V_24 ) ) ) ;
F_2 ( V_2 , L_85 ,
F_30 ( V_48 -> V_65 . V_67 ) ) ;
break;
default:
F_2 ( V_2 , L_86 ,
( unsigned int ) type >> 10 ) ;
F_28 ( V_2 , V_48 ) ;
break;
}
}
void F_35 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
int V_29 ;
T_4 V_28 = V_69 -> V_70 ;
union V_47 * V_48 = V_69 -> V_71 ;
for ( V_29 = 0 ; V_29 < V_72 ; ++ V_29 ) {
V_48 = & V_69 -> V_71 [ V_29 ] ;
F_2 ( V_2 , L_87 , V_28 ,
F_36 ( F_32 ( V_48 -> V_52 . V_56 ) ) ,
F_37 ( F_32 ( V_48 -> V_52 . V_56 ) ) ,
F_30 ( V_48 -> V_52 . V_57 ) ,
F_30 ( V_48 -> V_52 . V_53 ) ) ;
V_28 += sizeof( * V_48 ) ;
}
}
void F_38 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
F_2 ( V_2 , L_88 ,
V_74 -> V_75 ,
( unsigned long long ) F_39 ( V_74 -> V_76 ,
V_74 -> V_75 ) ) ;
F_2 ( V_2 , L_89 ,
V_74 -> V_77 ) ;
F_2 ( V_2 , L_90 ,
V_74 -> V_78 ,
( unsigned long long ) F_39 ( V_74 -> V_79 ,
V_74 -> V_78 ) ) ;
F_2 ( V_2 , L_91 ,
V_74 -> V_80 ) ;
}
void F_40 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_68 * V_69 ;
struct V_68 * V_81 = V_74 -> V_81 ;
F_35 ( V_2 , V_81 ) ;
if ( ! V_74 -> V_80 && ! V_74 -> V_77 ) {
F_2 ( V_2 , L_92 ) ;
return;
}
for ( V_69 = V_81 -> V_82 ; V_69 != V_81 ; V_69 = V_69 -> V_82 )
F_35 ( V_2 , V_69 ) ;
}
void F_41 ( struct V_1 * V_2 ,
unsigned int V_83 , unsigned int V_84 ,
struct V_85 * V_86 )
{
int V_29 ;
struct V_73 * V_74 ;
if ( V_86 -> V_87 & V_88 ) {
for ( V_29 = 1 ; V_29 < V_86 -> V_89 -> V_90 ; V_29 ++ ) {
V_74 = V_86 -> V_89 -> V_91 [ V_29 ] ;
F_2 ( V_2 , L_93 ,
V_83 , V_84 , V_29 ) ;
F_35 ( V_2 , V_74 -> V_76 ) ;
}
} else {
V_74 = V_86 -> V_74 ;
if ( ! V_74 )
return;
F_2 ( V_2 , L_94 ,
V_83 , V_84 ) ;
F_35 ( V_2 , V_74 -> V_76 ) ;
}
}
void F_42 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
T_4 V_28 = V_93 -> V_94 ;
int V_29 ;
struct V_95 * V_96 ;
for ( V_29 = 0 ; V_29 < V_93 -> V_97 ; ++ V_29 ) {
V_96 = & V_93 -> V_98 [ V_29 ] ;
F_2 ( V_2 , L_87 ,
V_28 ,
F_36 ( F_32 ( V_96 -> V_99 ) ) ,
F_37 ( F_32 ( V_96 -> V_99 ) ) ,
F_30 ( V_96 -> V_100 ) ,
F_30 ( V_96 -> V_43 ) ) ;
V_28 += sizeof( * V_96 ) ;
}
}
void F_43 ( struct V_1 * V_2 )
{
T_4 V_101 ;
V_101 = F_25 ( V_2 , & V_2 -> V_6 -> V_102 ) ;
F_2 ( V_2 , L_95 ,
F_36 ( V_101 ) ) ;
F_2 ( V_2 , L_96 ,
F_37 ( V_101 ) ) ;
}
static void F_44 ( struct V_1 * V_2 , T_4 * V_103 , T_5 V_70 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < 4 ; ++ V_29 ) {
F_2 ( V_2 , L_97
L_98 ,
& V_103 [ 4 + V_29 ] , ( unsigned long long ) V_70 ,
V_103 [ 4 + V_29 ] , V_29 ) ;
V_70 += 8 ;
}
}
char * F_45 ( struct V_1 * V_2 ,
struct V_104 * V_103 )
{
struct V_105 * V_106 = F_46 ( V_2 , V_103 ) ;
switch ( F_47 ( F_30 ( V_106 -> V_107 ) ) ) {
case V_108 :
return L_99 ;
case V_109 :
return L_100 ;
case V_110 :
return L_101 ;
case V_111 :
return L_102 ;
default:
return L_63 ;
}
}
static void F_48 ( struct V_1 * V_2 , struct V_104 * V_103 )
{
int V_112 = 32 / 8 ;
int V_29 ;
struct V_105 * V_106 = F_46 ( V_2 , V_103 ) ;
T_5 V_70 = V_103 -> V_70 +
( ( unsigned long ) V_106 - ( unsigned long ) V_103 -> V_113 ) ;
int V_114 = F_49 ( V_2 -> V_16 ) ;
F_2 ( V_2 , L_103 ) ;
F_2 ( V_2 , L_104 ,
& V_106 -> V_115 ,
( unsigned long long ) V_70 , V_106 -> V_115 ) ;
V_70 += V_112 ;
F_2 ( V_2 , L_105 ,
& V_106 -> V_116 ,
( unsigned long long ) V_70 , V_106 -> V_116 ) ;
V_70 += V_112 ;
F_2 ( V_2 , L_106 ,
& V_106 -> V_117 ,
( unsigned long long ) V_70 , V_106 -> V_117 ) ;
V_70 += V_112 ;
F_2 ( V_2 , L_107 ,
& V_106 -> V_107 ,
( unsigned long long ) V_70 , V_106 -> V_107 ) ;
V_70 += V_112 ;
for ( V_29 = 0 ; V_29 < 4 ; ++ V_29 ) {
F_2 ( V_2 , L_108 ,
& V_106 -> V_118 [ V_29 ] , ( unsigned long long ) V_70 ,
V_106 -> V_118 [ V_29 ] , V_29 ) ;
V_70 += V_112 ;
}
if ( V_114 )
F_44 ( V_2 , ( T_4 * ) V_106 , V_70 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_104 * V_103 ,
unsigned int V_119 )
{
int V_29 , V_30 ;
int V_120 = 31 ;
int V_112 = 32 / 8 ;
int V_114 = F_49 ( V_2 -> V_16 ) ;
if ( V_119 < 31 )
V_120 = V_119 + 1 ;
for ( V_29 = 0 ; V_29 < V_120 ; ++ V_29 ) {
unsigned int V_121 = F_51 ( V_29 ) ;
struct V_122 * V_123 = F_52 ( V_2 , V_103 , V_29 ) ;
T_5 V_70 = V_103 -> V_70 +
( ( unsigned long ) V_123 - ( unsigned long ) V_103 -> V_113 ) ;
F_2 ( V_2 , L_109 ,
F_53 ( V_121 ) ? L_110 : L_111 ,
V_121 & V_124 , V_29 ) ;
F_2 ( V_2 , L_112 ,
& V_123 -> V_125 ,
( unsigned long long ) V_70 , V_123 -> V_125 ) ;
V_70 += V_112 ;
F_2 ( V_2 , L_113 ,
& V_123 -> V_126 ,
( unsigned long long ) V_70 , V_123 -> V_126 ) ;
V_70 += V_112 ;
F_2 ( V_2 , L_114 ,
& V_123 -> V_127 ,
( unsigned long long ) V_70 , V_123 -> V_127 ) ;
V_70 += 2 * V_112 ;
F_2 ( V_2 , L_115 ,
& V_123 -> V_128 ,
( unsigned long long ) V_70 , V_123 -> V_128 ) ;
V_70 += V_112 ;
for ( V_30 = 0 ; V_30 < 3 ; ++ V_30 ) {
F_2 ( V_2 , L_108 ,
& V_123 -> V_118 [ V_30 ] ,
( unsigned long long ) V_70 ,
V_123 -> V_118 [ V_30 ] , V_30 ) ;
V_70 += V_112 ;
}
if ( V_114 )
F_44 ( V_2 , ( T_4 * ) V_123 , V_70 ) ;
}
}
void F_54 ( struct V_1 * V_2 ,
struct V_104 * V_103 ,
unsigned int V_119 )
{
int V_29 ;
int V_112 = 32 / 8 ;
T_5 V_70 = V_103 -> V_70 ;
int V_114 = F_49 ( V_2 -> V_16 ) ;
if ( V_103 -> type == V_129 ) {
struct V_130 * V_131 =
F_55 ( V_103 ) ;
if ( ! V_131 ) {
F_56 ( V_2 , L_116 ) ;
return;
}
F_2 ( V_2 , L_117 ,
& V_131 -> V_132 , ( unsigned long long ) V_70 ,
V_131 -> V_132 ) ;
V_70 += V_112 ;
F_2 ( V_2 , L_118 ,
& V_131 -> V_133 , ( unsigned long long ) V_70 ,
V_131 -> V_133 ) ;
V_70 += V_112 ;
for ( V_29 = 0 ; V_29 < 6 ; ++ V_29 ) {
F_2 ( V_2 , L_119 ,
& V_131 -> V_134 [ V_29 ] , ( unsigned long long ) V_70 ,
V_131 -> V_134 [ V_29 ] , V_29 ) ;
V_70 += V_112 ;
}
if ( V_114 )
F_44 ( V_2 , ( T_4 * ) V_131 , V_70 ) ;
}
F_48 ( V_2 , V_103 ) ;
F_50 ( V_2 , V_103 , V_119 ) ;
}
void F_57 ( struct V_1 * V_2 , void (* F_58)( struct V_135 * ) ,
const char * V_136 , ... )
{
struct V_135 V_137 ;
T_6 args ;
va_start ( args , V_136 ) ;
V_137 . V_136 = V_136 ;
V_137 . V_138 = & args ;
F_2 ( V_2 , L_120 , & V_137 ) ;
F_58 ( & V_137 ) ;
va_end ( args ) ;
}
