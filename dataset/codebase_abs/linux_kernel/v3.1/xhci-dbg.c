void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , L_1 ,
V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_5 ) ;
F_2 ( V_2 , L_2 ,
& V_2 -> V_4 -> V_5 , V_3 ) ;
F_2 ( V_2 , L_3 ,
( unsigned int ) F_4 ( V_3 ) ) ;
#if 0
xhci_dbg(xhci, "// HCIVERSION: 0x%x\n",
(unsigned int) HC_VERSION(temp));
#endif
F_2 ( V_2 , L_4 , V_2 -> V_6 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_7 ) ;
F_2 ( V_2 , L_5 ,
& V_2 -> V_4 -> V_7 ,
( unsigned int ) V_3 & V_8 ) ;
F_2 ( V_2 , L_6 , V_2 -> V_9 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_10 ) ;
F_2 ( V_2 , L_7 , & V_2 -> V_4 -> V_10 , V_3 ) ;
F_2 ( V_2 , L_8 , V_2 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , L_9 , V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_5 ) ;
F_2 ( V_2 , L_10 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_11 ,
( unsigned int ) F_4 ( V_3 ) ) ;
F_2 ( V_2 , L_12 ,
( unsigned int ) F_6 ( V_3 ) ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_12 ) ;
F_2 ( V_2 , L_13 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_14 ,
( unsigned int ) F_7 ( V_3 ) ) ;
F_2 ( V_2 , L_15 ,
( unsigned int ) F_8 ( V_3 ) ) ;
F_2 ( V_2 , L_16 ,
( unsigned int ) F_9 ( V_3 ) ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_13 ) ;
F_2 ( V_2 , L_17 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_18 ,
( unsigned int ) F_10 ( V_3 ) ) ;
F_2 ( V_2 , L_19 ,
( unsigned int ) F_11 ( V_3 ) ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_14 ) ;
F_2 ( V_2 , L_20 ,
( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_21 ,
( unsigned int ) F_12 ( V_3 ) ) ;
F_2 ( V_2 , L_22 ,
( unsigned int ) F_13 ( V_3 ) ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_15 ) ;
F_2 ( V_2 , L_23 , ( unsigned int ) V_3 ) ;
F_2 ( V_2 , L_24 ,
F_14 ( V_3 ) ? L_25 : L_26 ) ;
F_2 ( V_2 , L_27 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_4 -> V_7 ) ;
F_2 ( V_2 , L_28 , V_3 & V_8 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , & V_2 -> V_6 -> V_16 ) ;
F_2 ( V_2 , L_29 , V_3 ) ;
F_2 ( V_2 , L_30 ,
( V_3 & V_17 ) ? L_31 : L_32 ) ;
F_2 ( V_2 , L_33 ,
( V_3 & V_18 ) ? L_34 : L_35 ) ;
F_2 ( V_2 , L_36 ,
( V_3 & V_19 ) ? L_37 : L_38 ) ;
F_2 ( V_2 , L_39 ,
( V_3 & V_19 ) ? L_37 : L_38 ) ;
F_2 ( V_2 , L_40 ,
( V_3 & V_20 ) ? L_34 : L_35 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , & V_2 -> V_6 -> V_21 ) ;
F_2 ( V_2 , L_41 , V_3 ) ;
F_2 ( V_2 , L_42 ,
( V_3 & V_22 ) ? L_34 : L_35 ) ;
F_2 ( V_2 , L_43 ,
( V_3 & V_23 ) ? L_44 : L_45 ) ;
F_2 ( V_2 , L_30 ,
( V_3 & V_24 ) ? L_46 : L_31 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_47 , V_2 -> V_6 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 T_3 * V_25 ;
int V_26 , V_27 ;
int V_28 ;
char * V_29 [ V_30 ] = {
L_48 ,
L_49 ,
L_50 ,
L_51 ,
} ;
V_28 = F_9 ( V_2 -> V_12 ) ;
V_25 = & V_2 -> V_6 -> V_31 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
for ( V_27 = 0 ; V_27 < V_30 ; ++ V_27 ) {
F_2 ( V_2 , L_52 ,
V_25 , V_29 [ V_27 ] ,
( unsigned int ) F_3 ( V_2 , V_25 ) ) ;
V_25 ++ ;
}
}
}
void F_19 ( struct V_1 * V_2 , int V_32 )
{
struct V_33 T_3 * V_34 = & V_2 -> V_9 -> V_34 [ V_32 ] ;
void T_3 * V_25 ;
T_1 V_3 ;
T_4 V_35 ;
V_25 = & V_34 -> V_36 ;
V_3 = F_3 ( V_2 , V_25 ) ;
if ( V_3 == V_37 )
return;
F_2 ( V_2 , L_53 , V_34 , V_32 ) ;
F_2 ( V_2 , L_54 , V_25 ,
( unsigned int ) V_3 ) ;
V_25 = & V_34 -> V_38 ;
V_3 = F_3 ( V_2 , V_25 ) ;
F_2 ( V_2 , L_55 , V_25 ,
( unsigned int ) V_3 ) ;
V_25 = & V_34 -> V_39 ;
V_3 = F_3 ( V_2 , V_25 ) ;
F_2 ( V_2 , L_56 , V_25 ,
( unsigned int ) V_3 ) ;
V_25 = & V_34 -> V_40 ;
V_3 = F_3 ( V_2 , V_25 ) ;
if ( V_3 != V_37 )
F_2 ( V_2 , L_57 ,
V_25 , ( unsigned int ) V_3 ) ;
V_25 = & V_34 -> V_41 ;
V_35 = F_20 ( V_2 , V_25 ) ;
F_2 ( V_2 , L_58 ,
V_25 , V_35 ) ;
V_25 = & V_34 -> V_42 ;
V_35 = F_20 ( V_2 , V_25 ) ;
F_2 ( V_2 , L_59 ,
V_25 , V_35 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_26 ;
F_2 ( V_2 , L_60 , V_2 -> V_9 ) ;
V_3 = F_3 ( V_2 , & V_2 -> V_9 -> V_43 ) ;
F_2 ( V_2 , L_61 ,
& V_2 -> V_9 -> V_43 ,
( unsigned int ) V_3 ) ;
for ( V_26 = 0 ; V_26 < 7 ; ++ V_26 ) {
V_3 = F_3 ( V_2 , & V_2 -> V_9 -> V_40 [ V_26 ] ) ;
if ( V_3 != V_37 )
F_2 ( V_2 , L_62 ,
& V_2 -> V_9 -> V_40 [ V_26 ] ,
V_26 , ( unsigned int ) V_3 ) ;
}
}
void F_22 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 , union V_44 * V_45 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 )
F_2 ( V_2 , L_63 ,
V_26 * 4 , V_45 -> V_46 . V_47 [ V_26 ] ) ;
}
void F_24 ( struct V_1 * V_2 , union V_44 * V_45 )
{
T_4 V_48 ;
T_1 type = F_25 ( V_45 -> V_49 . V_50 ) & V_51 ;
switch ( type ) {
case F_26 ( V_52 ) :
F_2 ( V_2 , L_64 ) ;
F_23 ( V_2 , V_45 ) ;
V_48 = F_27 ( V_45 -> V_49 . V_53 ) ;
F_2 ( V_2 , L_65 , V_48 ) ;
F_2 ( V_2 , L_66 ,
F_28 ( F_25 ( V_45 -> V_49 . V_54 ) ) ) ;
F_2 ( V_2 , L_67 ,
F_25 ( V_45 -> V_49 . V_50 ) & V_55 ) ;
F_2 ( V_2 , L_68 ,
F_25 ( V_45 -> V_49 . V_50 ) & V_56 ) ;
F_2 ( V_2 , L_69 ,
F_25 ( V_45 -> V_49 . V_50 ) & V_57 ) ;
break;
case F_26 ( V_58 ) :
V_48 = F_27 ( V_45 -> V_59 . V_60 ) ;
F_2 ( V_2 , L_70 , V_48 ) ;
break;
case F_26 ( V_61 ) :
V_48 = F_27 ( V_45 -> V_62 . V_63 ) ;
F_2 ( V_2 , L_71 , V_48 ) ;
F_2 ( V_2 , L_72 ,
F_29 ( F_25 ( V_45 -> V_62 . V_21 ) ) ) ;
F_2 ( V_2 , L_73 ,
F_25 ( V_45 -> V_62 . V_64 ) ) ;
break;
default:
F_2 ( V_2 , L_74 ,
( unsigned int ) type >> 10 ) ;
F_23 ( V_2 , V_45 ) ;
break;
}
}
void F_30 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
int V_26 ;
T_4 V_25 = V_66 -> V_67 ;
union V_44 * V_45 = V_66 -> V_68 ;
for ( V_26 = 0 ; V_26 < V_69 ; ++ V_26 ) {
V_45 = & V_66 -> V_68 [ V_26 ] ;
F_2 ( V_2 , L_75 , V_25 ,
F_31 ( F_27 ( V_45 -> V_49 . V_53 ) ) ,
F_32 ( F_27 ( V_45 -> V_49 . V_53 ) ) ,
F_25 ( V_45 -> V_49 . V_54 ) ,
F_25 ( V_45 -> V_49 . V_50 ) ) ;
V_25 += sizeof( * V_45 ) ;
}
}
void F_33 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
F_2 ( V_2 , L_76 ,
V_71 -> V_72 ,
( unsigned long long ) F_34 ( V_71 -> V_73 ,
V_71 -> V_72 ) ) ;
F_2 ( V_2 , L_77 ,
V_71 -> V_74 ) ;
F_2 ( V_2 , L_78 ,
V_71 -> V_75 ,
( unsigned long long ) F_34 ( V_71 -> V_76 ,
V_71 -> V_75 ) ) ;
F_2 ( V_2 , L_79 ,
V_71 -> V_77 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
struct V_65 * V_66 ;
struct V_65 * V_78 = V_71 -> V_78 ;
F_30 ( V_2 , V_78 ) ;
if ( ! V_71 -> V_77 && ! V_71 -> V_74 ) {
F_2 ( V_2 , L_80 ) ;
return;
}
for ( V_66 = V_78 -> V_79 ; V_66 != V_78 ; V_66 = V_66 -> V_79 )
F_30 ( V_2 , V_66 ) ;
}
void F_36 ( struct V_1 * V_2 ,
unsigned int V_80 , unsigned int V_81 ,
struct V_82 * V_83 )
{
int V_26 ;
struct V_70 * V_71 ;
if ( V_83 -> V_84 & V_85 ) {
for ( V_26 = 1 ; V_26 < V_83 -> V_86 -> V_87 ; V_26 ++ ) {
V_71 = V_83 -> V_86 -> V_88 [ V_26 ] ;
F_2 ( V_2 , L_81 ,
V_80 , V_81 , V_26 ) ;
F_30 ( V_2 , V_71 -> V_73 ) ;
}
} else {
V_71 = V_83 -> V_71 ;
if ( ! V_71 )
return;
F_2 ( V_2 , L_82 ,
V_80 , V_81 ) ;
F_30 ( V_2 , V_71 -> V_73 ) ;
}
}
void F_37 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
T_4 V_25 = V_90 -> V_91 ;
int V_26 ;
struct V_92 * V_93 ;
for ( V_26 = 0 ; V_26 < V_90 -> V_94 ; ++ V_26 ) {
V_93 = & V_90 -> V_95 [ V_26 ] ;
F_2 ( V_2 , L_75 ,
V_25 ,
F_31 ( F_27 ( V_93 -> V_96 ) ) ,
F_32 ( F_27 ( V_93 -> V_96 ) ) ,
F_25 ( V_93 -> V_97 ) ,
F_25 ( V_93 -> V_40 ) ) ;
V_25 += sizeof( * V_93 ) ;
}
}
void F_38 ( struct V_1 * V_2 )
{
T_4 V_98 ;
V_98 = F_20 ( V_2 , & V_2 -> V_6 -> V_99 ) ;
F_2 ( V_2 , L_83 ,
F_31 ( V_98 ) ) ;
F_2 ( V_2 , L_84 ,
F_32 ( V_98 ) ) ;
}
static void F_39 ( struct V_1 * V_2 , T_4 * V_100 , T_5 V_67 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 ) {
F_2 ( V_2 , L_85
L_86 ,
& V_100 [ 4 + V_26 ] , ( unsigned long long ) V_67 ,
V_100 [ 4 + V_26 ] , V_26 ) ;
V_67 += 8 ;
}
}
char * F_40 ( struct V_1 * V_2 ,
struct V_101 * V_100 )
{
struct V_102 * V_103 = F_41 ( V_2 , V_100 ) ;
switch ( F_42 ( F_25 ( V_103 -> V_104 ) ) ) {
case V_105 :
return L_87 ;
case V_106 :
return L_88 ;
case V_107 :
return L_89 ;
case V_108 :
return L_90 ;
default:
return L_51 ;
}
}
static void F_43 ( struct V_1 * V_2 , struct V_101 * V_100 )
{
int V_109 = 32 / 8 ;
int V_26 ;
struct V_102 * V_103 = F_41 ( V_2 , V_100 ) ;
T_5 V_67 = V_100 -> V_67 +
( ( unsigned long ) V_103 - ( unsigned long ) V_100 -> V_110 ) ;
int V_111 = F_44 ( V_2 -> V_15 ) ;
F_2 ( V_2 , L_91 ) ;
F_2 ( V_2 , L_92 ,
& V_103 -> V_112 ,
( unsigned long long ) V_67 , V_103 -> V_112 ) ;
V_67 += V_109 ;
F_2 ( V_2 , L_93 ,
& V_103 -> V_113 ,
( unsigned long long ) V_67 , V_103 -> V_113 ) ;
V_67 += V_109 ;
F_2 ( V_2 , L_94 ,
& V_103 -> V_114 ,
( unsigned long long ) V_67 , V_103 -> V_114 ) ;
V_67 += V_109 ;
F_2 ( V_2 , L_95 ,
& V_103 -> V_104 ,
( unsigned long long ) V_67 , V_103 -> V_104 ) ;
V_67 += V_109 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 ) {
F_2 ( V_2 , L_96 ,
& V_103 -> V_115 [ V_26 ] , ( unsigned long long ) V_67 ,
V_103 -> V_115 [ V_26 ] , V_26 ) ;
V_67 += V_109 ;
}
if ( V_111 )
F_39 ( V_2 , ( T_4 * ) V_103 , V_67 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_101 * V_100 ,
unsigned int V_116 )
{
int V_26 , V_27 ;
int V_117 = 31 ;
int V_109 = 32 / 8 ;
int V_111 = F_44 ( V_2 -> V_15 ) ;
if ( V_116 < 31 )
V_117 = V_116 + 1 ;
for ( V_26 = 0 ; V_26 < V_117 ; ++ V_26 ) {
struct V_118 * V_119 = F_46 ( V_2 , V_100 , V_26 ) ;
T_5 V_67 = V_100 -> V_67 +
( ( unsigned long ) V_119 - ( unsigned long ) V_100 -> V_110 ) ;
F_2 ( V_2 , L_97 , V_26 ) ;
F_2 ( V_2 , L_98 ,
& V_119 -> V_120 ,
( unsigned long long ) V_67 , V_119 -> V_120 ) ;
V_67 += V_109 ;
F_2 ( V_2 , L_99 ,
& V_119 -> V_121 ,
( unsigned long long ) V_67 , V_119 -> V_121 ) ;
V_67 += V_109 ;
F_2 ( V_2 , L_100 ,
& V_119 -> V_122 ,
( unsigned long long ) V_67 , V_119 -> V_122 ) ;
V_67 += 2 * V_109 ;
F_2 ( V_2 , L_101 ,
& V_119 -> V_123 ,
( unsigned long long ) V_67 , V_119 -> V_123 ) ;
V_67 += V_109 ;
for ( V_27 = 0 ; V_27 < 3 ; ++ V_27 ) {
F_2 ( V_2 , L_96 ,
& V_119 -> V_115 [ V_27 ] ,
( unsigned long long ) V_67 ,
V_119 -> V_115 [ V_27 ] , V_27 ) ;
V_67 += V_109 ;
}
if ( V_111 )
F_39 ( V_2 , ( T_4 * ) V_119 , V_67 ) ;
}
}
void F_47 ( struct V_1 * V_2 ,
struct V_101 * V_100 ,
unsigned int V_116 )
{
int V_26 ;
int V_109 = 32 / 8 ;
struct V_102 * V_103 ;
T_5 V_67 = V_100 -> V_67 ;
int V_111 = F_44 ( V_2 -> V_15 ) ;
if ( V_100 -> type == V_124 ) {
struct V_125 * V_126 =
F_48 ( V_2 , V_100 ) ;
F_2 ( V_2 , L_102 ,
& V_126 -> V_127 , ( unsigned long long ) V_67 ,
V_126 -> V_127 ) ;
V_67 += V_109 ;
F_2 ( V_2 , L_103 ,
& V_126 -> V_128 , ( unsigned long long ) V_67 ,
V_126 -> V_128 ) ;
V_67 += V_109 ;
for ( V_26 = 0 ; V_26 < 6 ; ++ V_26 ) {
F_2 ( V_2 , L_104 ,
& V_126 -> V_129 [ V_26 ] , ( unsigned long long ) V_67 ,
V_126 -> V_129 [ V_26 ] , V_26 ) ;
V_67 += V_109 ;
}
if ( V_111 )
F_39 ( V_2 , ( T_4 * ) V_126 , V_67 ) ;
}
V_103 = F_41 ( V_2 , V_100 ) ;
F_43 ( V_2 , V_100 ) ;
F_45 ( V_2 , V_100 , V_116 ) ;
}
