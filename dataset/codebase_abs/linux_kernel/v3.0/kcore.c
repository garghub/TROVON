void
F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , int type )
{
V_2 -> V_3 = ( unsigned long ) V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
F_2 ( & V_5 ) ;
F_3 ( & V_2 -> V_6 , & V_7 ) ;
F_4 ( & V_5 ) ;
}
static T_1 F_5 ( int * V_8 , T_1 * V_9 )
{
T_1 V_10 , V_4 ;
struct V_1 * V_11 ;
* V_8 = 1 ;
V_4 = 0 ;
F_6 (m, &kclist_head, list) {
V_10 = F_7 ( ( T_1 ) V_11 -> V_3 + V_11 -> V_4 ) ;
if ( V_10 > V_4 )
V_4 = V_10 ;
* V_8 = * V_8 + 1 ;
}
* V_9 = sizeof( struct V_12 ) +
( * V_8 + 2 ) * sizeof( struct V_13 ) +
3 * ( ( sizeof( struct V_14 ) ) +
F_8 ( sizeof( V_15 ) , 4 ) ) +
F_8 ( sizeof( struct V_16 ) , 4 ) +
F_8 ( sizeof( struct V_17 ) , 4 ) +
F_8 ( sizeof( struct V_18 ) , 4 ) ;
* V_9 = F_9 ( * V_9 ) ;
return V_4 + * V_9 ;
}
static void F_10 ( struct V_19 * V_20 )
{
struct V_1 * V_21 , * V_22 ;
F_11 (pos, tmp, head, list) {
F_12 ( & V_22 -> V_6 ) ;
F_13 ( V_22 ) ;
}
}
static void F_14 ( struct V_19 * V_6 )
{
int V_8 ;
T_1 V_4 ;
struct V_1 * V_21 , * V_22 ;
F_15 ( V_23 ) ;
F_2 ( & V_5 ) ;
if ( V_24 ) {
F_11 (pos, tmp, &kclist_head, list) {
if ( V_22 -> type == V_25
|| V_22 -> type == V_26 )
F_16 ( & V_22 -> V_6 , & V_23 ) ;
}
F_17 ( V_6 , & V_7 ) ;
} else
F_18 ( V_6 , & V_23 ) ;
V_24 = 0 ;
V_27 -> V_4 = F_5 ( & V_8 , & V_4 ) ;
F_4 ( & V_5 ) ;
F_10 ( & V_23 ) ;
}
static int F_19 ( void )
{
F_15 ( V_20 ) ;
struct V_1 * V_28 ;
int V_29 = 0 ;
V_28 = F_20 ( sizeof( * V_28 ) , V_30 ) ;
if ( ! V_28 )
return - V_31 ;
V_28 -> V_3 = ( unsigned long ) F_21 ( 0 ) ;
V_28 -> V_4 = V_32 << V_33 ;
V_28 -> type = V_25 ;
F_22 ( & V_28 -> V_6 , & V_20 ) ;
F_14 ( & V_20 ) ;
return V_29 ;
}
int F_23 ( struct V_1 * V_28 , struct V_19 * V_20 )
{
unsigned long V_34 = F_24 ( V_28 -> V_3 ) >> V_33 ;
unsigned long V_35 = V_28 -> V_4 >> V_33 ;
unsigned long V_36 , V_37 ;
struct V_1 * V_38 , * V_21 ;
V_36 = ( ( unsigned long ) F_25 ( V_34 ) ) & V_39 ;
V_37 = ( ( unsigned long ) F_25 ( V_34 + V_35 ) ) - 1 ;
V_37 = F_26 ( V_37 , V_40 ) ;
F_6 (tmp, head, list) {
if ( V_21 -> type != V_26 )
continue;
if ( V_36 < V_21 -> V_3 + V_21 -> V_4 )
if ( V_37 > V_21 -> V_3 )
V_37 = V_21 -> V_3 ;
}
if ( V_36 < V_37 ) {
V_38 = F_20 ( sizeof( * V_38 ) , V_30 ) ;
if ( ! V_38 )
return 0 ;
V_38 -> V_3 = V_36 ;
V_38 -> V_4 = V_37 - V_36 ;
V_38 -> type = V_26 ;
F_3 ( & V_38 -> V_6 , V_20 ) ;
}
return 1 ;
}
int F_23 ( struct V_1 * V_28 , struct V_19 * V_20 )
{
return 1 ;
}
static int
F_27 ( unsigned long V_34 , unsigned long V_35 , void * V_41 )
{
struct V_19 * V_20 = (struct V_19 * ) V_41 ;
struct V_1 * V_28 ;
V_28 = F_20 ( sizeof( * V_28 ) , V_30 ) ;
if ( ! V_28 )
return - V_31 ;
V_28 -> V_3 = ( unsigned long ) F_21 ( ( V_34 << V_33 ) ) ;
V_28 -> V_4 = V_35 << V_33 ;
if ( V_28 -> V_3 < ( unsigned long ) F_21 ( 0 ) )
goto V_42;
if ( V_43 - V_28 -> V_3 < V_28 -> V_4 )
V_28 -> V_4 = V_43 - V_28 -> V_3 ;
if ( V_44 > ( unsigned long ) F_21 ( 0 ) ) {
if ( V_28 -> V_3 > V_44 )
goto V_42;
if ( V_44 - V_28 -> V_3 < V_28 -> V_4 )
V_28 -> V_4 = V_44 - V_28 -> V_3 ;
}
V_28 -> type = V_25 ;
F_3 ( & V_28 -> V_6 , V_20 ) ;
if ( ! F_23 ( V_28 , V_20 ) ) {
F_12 ( & V_28 -> V_6 ) ;
goto V_42;
}
return 0 ;
V_42:
F_13 ( V_28 ) ;
return 1 ;
}
static int F_19 ( void )
{
int V_45 , V_29 ;
unsigned long V_46 ;
F_15 ( V_20 ) ;
V_46 = 0 ;
F_28 (nid, N_HIGH_MEMORY) {
unsigned long V_47 ;
V_47 = F_29 ( V_45 ) -> V_48 +
F_29 ( V_45 ) -> V_49 ;
if ( V_46 < V_47 )
V_46 = V_47 ;
}
V_29 = F_30 ( 0 , V_46 , & V_20 , F_27 ) ;
if ( V_29 ) {
F_10 ( & V_20 ) ;
return - V_31 ;
}
F_14 ( & V_20 ) ;
return V_29 ;
}
static int F_31 ( struct V_50 * V_51 )
{
int V_52 ;
V_52 = sizeof( struct V_14 ) ;
V_52 += F_8 ( ( strlen ( V_51 -> V_53 ) + 1 ) , 4 ) ;
V_52 += F_8 ( V_51 -> V_54 , 4 ) ;
return V_52 ;
}
static char * F_32 ( struct V_50 * V_55 , char * V_56 )
{
struct V_14 V_51 ;
#define F_33 ( V_3 , T_2 ) do { memcpy(bufp,addr,nr); bufp += nr; } while(0)
V_51 . V_57 = strlen ( V_55 -> V_53 ) + 1 ;
V_51 . V_58 = V_55 -> V_54 ;
V_51 . V_59 = V_55 -> type ;
F_33 ( & V_51 , sizeof( V_51 ) ) ;
F_33 ( V_55 -> V_53 , V_51 . V_57 ) ;
V_56 = ( char * ) F_8 ( ( unsigned long ) V_56 , 4 ) ;
F_33 ( V_55 -> V_60 , V_55 -> V_54 ) ;
V_56 = ( char * ) F_8 ( ( unsigned long ) V_56 , 4 ) ;
#undef F_33
return V_56 ;
}
static void F_34 ( char * V_56 , int V_8 , int V_61 )
{
struct V_16 V_62 ;
struct V_17 V_63 ;
struct V_13 * V_64 , * V_65 ;
struct V_12 * V_66 ;
struct V_50 V_67 [ 3 ] ;
T_3 V_68 = 0 ;
struct V_1 * V_11 ;
V_66 = (struct V_12 * ) V_56 ;
V_56 += sizeof( struct V_12 ) ;
V_68 += sizeof( struct V_12 ) ;
memcpy ( V_66 -> V_69 , V_70 , V_71 ) ;
V_66 -> V_69 [ V_72 ] = V_73 ;
V_66 -> V_69 [ V_74 ] = V_75 ;
V_66 -> V_69 [ V_76 ] = V_77 ;
V_66 -> V_69 [ V_78 ] = V_79 ;
memset ( V_66 -> V_69 + V_80 , 0 , V_81 - V_80 ) ;
V_66 -> V_82 = V_83 ;
V_66 -> V_84 = V_85 ;
V_66 -> V_86 = V_77 ;
V_66 -> V_87 = 0 ;
V_66 -> V_88 = sizeof( struct V_12 ) ;
V_66 -> V_89 = 0 ;
V_66 -> V_90 = V_91 ;
V_66 -> V_92 = sizeof( struct V_12 ) ;
V_66 -> V_93 = sizeof( struct V_13 ) ;
V_66 -> V_94 = V_8 ;
V_66 -> V_95 = 0 ;
V_66 -> V_96 = 0 ;
V_66 -> V_97 = 0 ;
V_64 = (struct V_13 * ) V_56 ;
V_56 += sizeof( struct V_13 ) ;
V_68 += sizeof( struct V_13 ) ;
V_64 -> V_98 = V_99 ;
V_64 -> V_100 = 0 ;
V_64 -> V_101 = 0 ;
V_64 -> V_102 = 0 ;
V_64 -> V_103 = 0 ;
V_64 -> V_104 = 0 ;
V_64 -> V_105 = 0 ;
V_64 -> V_106 = 0 ;
F_6 (m, &kclist_head, list) {
V_65 = (struct V_13 * ) V_56 ;
V_56 += sizeof( struct V_13 ) ;
V_68 += sizeof( struct V_13 ) ;
V_65 -> V_98 = V_107 ;
V_65 -> V_105 = V_108 | V_109 | V_110 ;
V_65 -> V_100 = F_7 ( V_11 -> V_3 ) + V_61 ;
V_65 -> V_101 = ( T_1 ) V_11 -> V_3 ;
V_65 -> V_102 = 0 ;
V_65 -> V_103 = V_65 -> V_104 = V_11 -> V_4 ;
V_65 -> V_106 = V_40 ;
}
V_64 -> V_100 = V_68 ;
V_67 [ 0 ] . V_53 = V_15 ;
V_67 [ 0 ] . type = V_111 ;
V_67 [ 0 ] . V_54 = sizeof( struct V_16 ) ;
V_67 [ 0 ] . V_60 = & V_62 ;
memset ( & V_62 , 0 , sizeof( struct V_16 ) ) ;
V_64 -> V_103 = F_31 ( & V_67 [ 0 ] ) ;
V_56 = F_32 ( & V_67 [ 0 ] , V_56 ) ;
V_67 [ 1 ] . V_53 = V_15 ;
V_67 [ 1 ] . type = V_112 ;
V_67 [ 1 ] . V_54 = sizeof( struct V_17 ) ;
V_67 [ 1 ] . V_60 = & V_63 ;
memset ( & V_63 , 0 , sizeof( struct V_17 ) ) ;
V_63 . V_113 = 0 ;
V_63 . V_114 = 'R' ;
V_63 . V_115 = 0 ;
strcpy ( V_63 . V_116 , L_1 ) ;
strncpy ( V_63 . V_117 , V_118 , V_119 ) ;
V_64 -> V_103 += F_31 ( & V_67 [ 1 ] ) ;
V_56 = F_32 ( & V_67 [ 1 ] , V_56 ) ;
V_67 [ 2 ] . V_53 = V_15 ;
V_67 [ 2 ] . type = V_120 ;
V_67 [ 2 ] . V_54 = sizeof( struct V_18 ) ;
V_67 [ 2 ] . V_60 = V_121 ;
V_64 -> V_103 += F_31 ( & V_67 [ 2 ] ) ;
V_56 = F_32 ( & V_67 [ 2 ] , V_56 ) ;
}
static T_4
F_35 ( struct V_122 * V_122 , char T_5 * V_123 , T_1 V_124 , T_6 * V_125 )
{
T_4 V_126 = 0 ;
T_1 V_4 , V_127 ;
T_1 V_9 ;
int V_8 ;
unsigned long V_36 ;
F_36 ( & V_5 ) ;
V_4 = F_5 ( & V_8 , & V_9 ) ;
if ( V_124 == 0 || * V_125 >= V_4 ) {
F_37 ( & V_5 ) ;
return 0 ;
}
if ( V_124 > V_4 - * V_125 )
V_124 = V_4 - * V_125 ;
if ( * V_125 < V_9 ) {
char * V_128 ;
V_127 = V_9 - * V_125 ;
if ( V_124 < V_127 )
V_127 = V_124 ;
V_128 = F_38 ( V_9 , V_129 ) ;
if ( ! V_128 ) {
F_37 ( & V_5 ) ;
return - V_31 ;
}
F_34 ( V_128 , V_8 , V_9 ) ;
F_37 ( & V_5 ) ;
if ( F_39 ( V_123 , V_128 + * V_125 , V_127 ) ) {
F_13 ( V_128 ) ;
return - V_130 ;
}
F_13 ( V_128 ) ;
V_124 -= V_127 ;
* V_125 += V_127 ;
V_123 += V_127 ;
V_126 += V_127 ;
if ( V_124 == 0 )
return V_126 ;
} else
F_37 ( & V_5 ) ;
V_36 = F_40 ( * V_125 - V_9 ) ;
if ( ( V_127 = ( V_40 - ( V_36 & ~ V_39 ) ) ) > V_124 )
V_127 = V_124 ;
while ( V_124 ) {
struct V_1 * V_11 ;
F_36 ( & V_5 ) ;
F_6 (m, &kclist_head, list) {
if ( V_36 >= V_11 -> V_3 && V_36 < ( V_11 -> V_3 + V_11 -> V_4 ) )
break;
}
F_37 ( & V_5 ) ;
if ( & V_11 -> V_6 == & V_7 ) {
if ( F_41 ( V_123 , V_127 ) )
return - V_130 ;
} else if ( F_42 ( ( void * ) V_36 ) ) {
char * V_128 ;
V_128 = F_38 ( V_127 , V_30 ) ;
if ( ! V_128 )
return - V_31 ;
F_43 ( V_128 , ( char * ) V_36 , V_127 ) ;
if ( F_39 ( V_123 , V_128 , V_127 ) ) {
F_13 ( V_128 ) ;
return - V_130 ;
}
F_13 ( V_128 ) ;
} else {
if ( F_44 ( V_36 ) ) {
unsigned long V_131 ;
V_131 = F_39 ( V_123 , ( char * ) V_36 , V_127 ) ;
if ( V_131 ) {
if ( F_41 ( V_123 + V_127 - V_131 ,
V_131 ) )
return - V_130 ;
}
} else {
if ( F_41 ( V_123 , V_127 ) )
return - V_130 ;
}
}
V_124 -= V_127 ;
* V_125 += V_127 ;
V_123 += V_127 ;
V_126 += V_127 ;
V_36 += V_127 ;
V_127 = ( V_124 > V_40 ? V_40 : V_124 ) ;
}
return V_126 ;
}
static int F_45 ( struct V_132 * V_132 , struct V_122 * V_133 )
{
if ( ! F_46 ( V_134 ) )
return - V_135 ;
if ( V_24 )
F_19 () ;
if ( F_47 ( V_132 ) != V_27 -> V_4 ) {
F_48 ( & V_132 -> V_136 ) ;
F_49 ( V_132 , V_27 -> V_4 ) ;
F_50 ( & V_132 -> V_136 ) ;
}
return 0 ;
}
static int T_7 F_51 ( struct V_137 * V_138 ,
unsigned long V_139 , void * V_41 )
{
switch ( V_139 ) {
case V_140 :
case V_141 :
F_2 ( & V_5 ) ;
V_24 = 1 ;
F_4 ( & V_5 ) ;
}
return V_142 ;
}
static void T_8 F_52 ( void )
{
F_1 ( & V_143 , V_144 , V_145 - V_144 , V_146 ) ;
}
static void T_8 F_52 ( void )
{
}
static void T_8 F_53 ( void )
{
F_1 ( & V_147 , ( void * ) V_148 ,
V_149 - V_148 , V_150 ) ;
}
static void T_8 F_53 ( void )
{
}
static int T_8 F_54 ( void )
{
V_27 = F_55 ( L_2 , V_151 , NULL ,
& V_152 ) ;
if ( ! V_27 ) {
F_56 ( V_153 L_3 ) ;
return 0 ;
}
F_52 () ;
F_1 ( & V_154 , ( void * ) V_44 ,
V_155 - V_44 , V_150 ) ;
F_53 () ;
F_19 () ;
F_57 ( F_51 , 0 ) ;
return 0 ;
}
