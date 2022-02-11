static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
V_4 = F_3 ( & V_3 -> V_7 , struct V_1 , V_8 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_3 -> V_6 , V_5 ) ;
F_6 ( & V_4 -> V_9 ) ;
return V_4 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_10 , * V_11 ;
V_3 -> V_12 ++ ;
F_8 ( & V_4 -> V_8 , & V_3 -> V_7 ) ;
F_9 (child, next, &desc->tx_list, node) {
V_3 -> V_12 ++ ;
F_10 ( & V_10 -> V_8 , & V_3 -> V_7 ) ;
}
}
static void F_11 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_1 * V_4 , * V_11 ;
F_9 (desc, next, list, node)
F_7 ( V_3 , V_4 ) ;
}
static void F_12 ( struct V_15 * V_4 ,
T_1 V_16 , T_1 V_17 , T_2 V_18 ,
T_3 V_19 )
{
V_4 -> V_20 = F_13 ( V_17 ) ;
V_4 -> V_21 = F_13 ( V_16 ) ;
V_4 -> V_22 = F_14 ( V_17 ) ;
V_4 -> V_23 = F_14 ( V_16 ) ;
V_4 -> V_18 = V_18 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_26 | V_27 |
V_28 ;
}
static void F_15 ( struct V_15 * V_4 )
{
V_4 -> V_25 |= V_29 ;
}
static T_4 F_16 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 -> V_32 ) ;
struct V_1 * V_33 ;
T_4 V_34 ;
unsigned long V_5 ;
V_33 = F_18 ( V_31 ) ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
V_34 = F_19 ( V_31 ) ;
F_8 ( & V_33 -> V_8 , & V_3 -> V_35 ) ;
F_5 ( & V_3 -> V_6 , V_5 ) ;
return V_34 ;
}
static struct V_30 *
F_20 ( struct V_36 * V_37 , T_1 V_38 ,
T_1 V_39 , T_2 V_18 , T_5 V_5 )
{
struct V_2 * V_3 = F_17 ( V_37 ) ;
struct V_1 * V_33 , * V_40 = NULL ;
struct V_15 * V_4 ;
T_2 V_41 ;
T_3 V_42 ;
unsigned long V_43 ;
V_42 = F_21 ( V_18 , V_44 ) ;
F_2 ( & V_3 -> V_6 , V_43 ) ;
if ( V_42 > V_3 -> V_12 ) {
F_5 ( & V_3 -> V_6 , V_43 ) ;
F_22 ( V_3 -> V_45 , L_1 , V_3 ) ;
return NULL ;
}
V_3 -> V_12 -= V_42 ;
F_5 ( & V_3 -> V_6 , V_43 ) ;
do {
V_33 = F_1 ( V_3 ) ;
V_41 = F_23 ( T_2 , V_18 , V_44 ) ;
V_4 = & V_33 -> V_46 ;
F_12 ( V_4 , V_38 , V_39 , V_41 ,
V_47 ) ;
V_18 -= V_41 ;
V_39 += V_41 ;
V_38 += V_41 ;
if ( ! V_40 )
V_40 = V_33 ;
else
F_8 ( & V_33 -> V_8 , & V_40 -> V_9 ) ;
} while ( V_18 );
F_15 ( V_4 ) ;
F_24 ( & V_40 -> V_48 ) ;
V_40 -> V_48 . V_5 = V_5 ;
return & V_40 -> V_48 ;
}
static struct V_30 *
F_25 ( struct V_36 * V_37 , struct V_49 * V_50 ,
unsigned int V_51 , enum V_52 V_53 ,
unsigned long V_5 , void * V_54 )
{
struct V_2 * V_3 = F_17 ( V_37 ) ;
struct V_55 * V_56 = & V_3 -> V_57 ;
struct V_1 * V_33 , * V_40 = NULL ;
void * V_4 = NULL ;
T_2 V_18 , V_58 ;
T_1 V_38 , V_39 ;
T_3 V_42 = 0 , V_59 ;
struct V_49 * V_60 ;
T_3 V_19 ;
unsigned long V_43 ;
F_26 (sgl, sg, sg_len, i)
V_42 += F_21 ( F_27 ( V_60 ) , V_44 ) ;
F_2 ( & V_3 -> V_6 , V_43 ) ;
if ( V_42 > V_3 -> V_12 ) {
F_5 ( & V_3 -> V_6 , V_43 ) ;
F_22 ( V_3 -> V_45 , L_1 , V_3 ) ;
return NULL ;
}
V_3 -> V_12 -= V_42 ;
F_5 ( & V_3 -> V_6 , V_43 ) ;
V_58 = F_27 ( V_50 ) ;
while ( true ) {
V_33 = F_1 ( V_3 ) ;
V_4 = & V_33 -> V_46 ;
V_18 = F_23 ( T_2 , V_58 , V_44 ) ;
if ( V_53 == V_61 ) {
V_39 = F_28 ( V_50 ) + F_27 ( V_50 ) - V_58 ;
V_38 = V_56 -> V_62 ;
V_19 = V_63 ;
} else {
V_39 = V_56 -> V_64 ;
V_38 = F_28 ( V_50 ) + F_27 ( V_50 ) - V_58 ;
V_19 = V_65 ;
}
F_12 ( V_4 , V_38 , V_39 , V_18 , V_19 ) ;
V_58 -= V_18 ;
if ( ! V_40 )
V_40 = V_33 ;
else
F_8 ( & V_33 -> V_8 , & V_40 -> V_9 ) ;
if ( V_58 == 0 ) {
if ( V_51 == 0 )
break;
V_50 = F_29 ( V_50 ) ;
if ( V_50 == NULL )
break;
V_51 -- ;
V_58 = F_27 ( V_50 ) ;
}
}
F_15 ( V_4 ) ;
V_40 -> V_48 . V_5 = V_5 ;
return & V_40 -> V_48 ;
}
static int F_30 ( struct V_36 * V_37 ,
struct V_55 * V_66 )
{
struct V_2 * V_3 = F_17 ( V_37 ) ;
memcpy ( & V_3 -> V_57 , V_66 , sizeof( * V_66 ) ) ;
return 0 ;
}
static void F_31 ( struct V_2 * V_3 )
{
T_3 V_67 ;
int V_68 ;
F_32 ( V_69 , V_3 -> V_70 + V_71 ) ;
F_32 ( V_72 , V_3 -> V_70 + V_73 ) ;
V_68 = F_33 ( V_3 -> V_70 + V_71 , V_67 ,
( V_67 & V_74 ) == 0 ,
1 , 10000 ) ;
if ( V_68 )
F_34 ( V_3 -> V_45 , L_2 ) ;
F_32 ( V_69 , V_3 -> V_70 + V_71 ) ;
F_32 ( V_75 | V_76 |
V_77 , V_3 -> V_70 + V_73 ) ;
V_3 -> V_78 = true ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
void T_6 * V_46 = V_3 -> V_4 ;
while ( F_36 ( V_3 -> V_70 + V_71 ) &
V_79 )
F_37 ( 1 ) ;
memcpy ( ( void V_80 * ) V_46 , & V_4 -> V_46 ,
sizeof( V_4 -> V_46 ) - sizeof( T_3 ) ) ;
V_3 -> V_78 = false ;
F_38 () ;
F_32 ( V_4 -> V_46 . V_25 , V_46 +
F_39 ( struct V_15 , V_25 ) ) ;
F_38 () ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_81 , * V_11 ;
F_35 ( V_3 , V_4 ) ;
F_9 (sdesc, next, &desc->tx_list, node)
F_35 ( V_3 , V_81 ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 -> V_78 )
return;
V_4 = F_42 ( & V_3 -> V_35 ,
struct V_1 , V_8 ) ;
if ( ! V_4 )
return;
F_43 ( & V_3 -> V_35 , & V_3 -> V_82 ) ;
F_40 ( V_3 , V_4 ) ;
}
static void F_44 ( struct V_36 * V_32 )
{
struct V_2 * V_3 = F_17 ( V_32 ) ;
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
F_41 ( V_3 ) ;
F_5 ( & V_3 -> V_6 , V_5 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_11 ;
F_9 (desc, next, &mdev->done_list, node) {
T_7 V_83 ;
void * V_84 ;
F_4 ( & V_4 -> V_8 ) ;
V_83 = V_4 -> V_48 . V_83 ;
V_84 = V_4 -> V_48 . V_84 ;
if ( V_83 ) {
F_46 ( & V_3 -> V_6 ) ;
V_83 ( V_84 ) ;
F_47 ( & V_3 -> V_6 ) ;
}
F_7 ( V_3 , V_4 ) ;
}
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_42 ( & V_3 -> V_82 ,
struct V_1 , V_8 ) ;
if ( ! V_4 )
return;
F_4 ( & V_4 -> V_8 ) ;
F_49 ( & V_4 -> V_48 ) ;
F_8 ( & V_4 -> V_8 , & V_3 -> V_85 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_11 ( V_3 , & V_3 -> V_82 ) ;
F_11 ( V_3 , & V_3 -> V_35 ) ;
F_11 ( V_3 , & V_3 -> V_85 ) ;
}
static void F_51 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_37 ) ;
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
F_50 ( V_3 ) ;
F_5 ( & V_3 -> V_6 , V_5 ) ;
F_52 ( V_3 -> V_86 ) ;
}
static int F_53 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_37 ) ;
struct V_1 * V_4 ;
int V_59 ;
V_3 -> V_86 = F_54 ( V_87 , sizeof( * V_4 ) , V_88 ) ;
if ( ! V_3 -> V_86 )
return - V_89 ;
V_3 -> V_78 = true ;
V_3 -> V_12 = V_87 ;
F_6 ( & V_3 -> V_7 ) ;
for ( V_59 = 0 ; V_59 < V_87 ; V_59 ++ ) {
V_4 = V_3 -> V_86 + V_59 ;
F_55 ( & V_4 -> V_48 , & V_3 -> V_90 ) ;
V_4 -> V_48 . V_91 = F_16 ;
F_8 ( & V_4 -> V_8 , & V_3 -> V_7 ) ;
}
return V_87 ;
}
static void F_56 ( unsigned long V_92 )
{
struct V_2 * V_3 = (struct V_2 * ) V_92 ;
T_3 V_93 ;
T_3 T_8 V_94 ;
T_3 T_8 V_95 ;
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
V_93 = F_36 ( V_3 -> V_70 + V_96 ) ;
F_22 ( V_3 -> V_45 , L_3 ,
V_97 , __LINE__ , V_93 ) ;
while ( V_93 -- ) {
V_94 = F_36 ( V_3 -> V_98 + V_99 ) ;
V_95 = F_36 ( V_3 -> V_98 + V_100 ) ;
F_48 ( V_3 ) ;
F_45 ( V_3 ) ;
}
F_5 ( & V_3 -> V_6 , V_5 ) ;
}
static T_9 F_57 ( int V_101 , void * V_92 )
{
struct V_2 * V_3 = V_92 ;
T_3 V_95 ;
V_95 = F_36 ( V_3 -> V_70 + V_71 ) ;
if ( ( V_95 & V_102 ) == 0 ) {
F_47 ( & V_3 -> V_6 ) ;
V_3 -> V_78 = true ;
F_41 ( V_3 ) ;
F_46 ( & V_3 -> V_6 ) ;
}
F_58 ( & V_3 -> V_103 ) ;
F_32 ( V_104 , V_3 -> V_70 + V_71 ) ;
return V_105 ;
}
static void F_59 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_60 ( V_3 -> V_45 , V_3 -> V_101 , V_3 ) ;
F_61 ( & V_3 -> V_103 ) ;
F_4 ( & V_3 -> V_90 . V_106 ) ;
}
static int F_62 ( struct V_107 * V_108 , const char * V_109 ,
struct V_110 * * V_111 , void T_6 * * V_112 )
{
struct V_110 * V_113 ;
struct V_114 * V_114 = & V_108 -> V_45 ;
* V_111 = F_63 ( V_108 , V_115 , V_109 ) ;
if ( * V_111 == NULL ) {
F_34 ( V_114 , L_4 , V_109 ) ;
return - V_116 ;
}
V_113 = F_64 ( V_114 , ( * V_111 ) -> V_117 ,
F_65 ( * V_111 ) , F_66 ( V_114 ) ) ;
if ( V_113 == NULL ) {
F_34 ( V_114 , L_5 , V_109 ) ;
return - V_118 ;
}
* V_112 = F_67 ( V_114 , V_113 -> V_117 ,
F_65 ( V_113 ) ) ;
if ( * V_112 == NULL ) {
F_34 ( V_114 , L_6 , V_109 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_68 ( struct V_107 * V_108 )
{
struct V_2 * V_3 ;
struct V_119 * V_120 ;
struct V_110 * V_121 ;
int V_68 ;
V_3 = F_69 ( & V_108 -> V_45 , sizeof( * V_3 ) , V_88 ) ;
if ( ! V_3 )
return - V_89 ;
V_3 -> V_45 = & V_108 -> V_45 ;
V_68 = F_62 ( V_108 , L_7 , & V_121 , & V_3 -> V_70 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_62 ( V_108 , L_8 , & V_121 , & V_3 -> V_4 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_62 ( V_108 , L_9 , & V_121 , & V_3 -> V_98 ) ;
if ( V_68 )
return V_68 ;
F_70 ( V_108 , V_3 ) ;
V_3 -> V_101 = F_71 ( V_108 , 0 ) ;
if ( V_3 -> V_101 < 0 )
return - V_122 ;
V_68 = F_72 ( & V_108 -> V_45 , V_3 -> V_101 , F_57 ,
0 , F_66 ( & V_108 -> V_45 ) , V_3 ) ;
if ( V_68 )
return V_68 ;
F_73 ( & V_3 -> V_103 , F_56 , ( unsigned long ) V_3 ) ;
F_74 ( & V_3 -> V_90 ) ;
F_75 ( & V_3 -> V_6 ) ;
F_6 ( & V_3 -> V_82 ) ;
F_6 ( & V_3 -> V_35 ) ;
F_6 ( & V_3 -> V_85 ) ;
F_6 ( & V_3 -> V_7 ) ;
V_120 = & V_3 -> V_123 ;
F_76 ( V_120 -> V_124 ) ;
F_77 ( V_125 , V_120 -> V_124 ) ;
F_77 ( V_126 , V_120 -> V_124 ) ;
V_120 -> V_127 = F_78 ( V_128 ) ;
V_120 -> V_129 = F_78 ( V_128 ) ;
V_120 -> V_130 = F_78 ( V_61 ) | F_78 ( V_131 ) |
F_78 ( V_132 ) ;
V_120 -> V_133 = V_134 ;
F_6 ( & V_120 -> V_135 ) ;
V_120 -> V_136 = V_137 ;
V_120 -> V_138 = F_44 ;
V_120 -> V_45 = & V_108 -> V_45 ;
V_120 -> V_139 = V_140 ;
V_120 -> V_141 = F_20 ;
V_120 -> V_142 = F_25 ;
V_120 -> V_143 = F_30 ;
V_120 -> V_144 = F_53 ;
V_120 -> V_145 = F_51 ;
V_3 -> V_90 . V_114 = V_120 ;
F_8 ( & V_3 -> V_90 . V_106 , & V_120 -> V_135 ) ;
V_68 = F_79 ( & V_108 -> V_45 , F_80 ( 64 ) ) ;
if ( V_68 ) {
F_81 ( & V_108 -> V_45 , L_10 ) ;
V_68 = F_79 ( & V_108 -> V_45 , F_80 ( 32 ) ) ;
if ( V_68 )
goto V_146;
}
F_31 ( V_3 ) ;
V_68 = F_82 ( V_120 ) ;
if ( V_68 )
goto V_146;
F_83 ( & V_108 -> V_45 , L_11 ) ;
return 0 ;
V_146:
F_59 ( V_3 ) ;
return V_68 ;
}
static int F_84 ( struct V_107 * V_108 )
{
struct V_2 * V_3 = F_85 ( V_108 ) ;
F_86 ( & V_3 -> V_123 ) ;
F_59 ( V_3 ) ;
F_83 ( & V_108 -> V_45 , L_12 ) ;
return 0 ;
}
