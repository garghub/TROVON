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
static int
F_23 ( struct V_1 * V_28 , struct V_19 * V_20 )
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
static int
F_23 ( struct V_1 * V_28 , struct V_19 * V_20 )
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
F_28 (nid, N_MEMORY) {
unsigned long V_47 ;
V_47 = F_29 ( V_45 ) ;
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
static int F_31 ( struct V_48 * V_49 )
{
int V_50 ;
V_50 = sizeof( struct V_14 ) ;
V_50 += F_8 ( ( strlen ( V_49 -> V_51 ) + 1 ) , 4 ) ;
V_50 += F_8 ( V_49 -> V_52 , 4 ) ;
return V_50 ;
}
static char * F_32 ( struct V_48 * V_53 , char * V_54 )
{
struct V_14 V_49 ;
#define F_33 ( V_3 , T_2 ) do { memcpy(bufp,addr,nr); bufp += nr; } while(0)
V_49 . V_55 = strlen ( V_53 -> V_51 ) + 1 ;
V_49 . V_56 = V_53 -> V_52 ;
V_49 . V_57 = V_53 -> type ;
F_33 ( & V_49 , sizeof( V_49 ) ) ;
F_33 ( V_53 -> V_51 , V_49 . V_55 ) ;
V_54 = ( char * ) F_8 ( ( unsigned long ) V_54 , 4 ) ;
F_33 ( V_53 -> V_58 , V_53 -> V_52 ) ;
V_54 = ( char * ) F_8 ( ( unsigned long ) V_54 , 4 ) ;
#undef F_33
return V_54 ;
}
static void F_34 ( char * V_54 , int V_8 , int V_59 )
{
struct V_16 V_60 ;
struct V_17 V_61 ;
struct V_13 * V_62 , * V_63 ;
struct V_12 * V_64 ;
struct V_48 V_65 [ 3 ] ;
T_3 V_66 = 0 ;
struct V_1 * V_11 ;
V_64 = (struct V_12 * ) V_54 ;
V_54 += sizeof( struct V_12 ) ;
V_66 += sizeof( struct V_12 ) ;
memcpy ( V_64 -> V_67 , V_68 , V_69 ) ;
V_64 -> V_67 [ V_70 ] = V_71 ;
V_64 -> V_67 [ V_72 ] = V_73 ;
V_64 -> V_67 [ V_74 ] = V_75 ;
V_64 -> V_67 [ V_76 ] = V_77 ;
memset ( V_64 -> V_67 + V_78 , 0 , V_79 - V_78 ) ;
V_64 -> V_80 = V_81 ;
V_64 -> V_82 = V_83 ;
V_64 -> V_84 = V_75 ;
V_64 -> V_85 = 0 ;
V_64 -> V_86 = sizeof( struct V_12 ) ;
V_64 -> V_87 = 0 ;
V_64 -> V_88 = V_89 ;
V_64 -> V_90 = sizeof( struct V_12 ) ;
V_64 -> V_91 = sizeof( struct V_13 ) ;
V_64 -> V_92 = V_8 ;
V_64 -> V_93 = 0 ;
V_64 -> V_94 = 0 ;
V_64 -> V_95 = 0 ;
V_62 = (struct V_13 * ) V_54 ;
V_54 += sizeof( struct V_13 ) ;
V_66 += sizeof( struct V_13 ) ;
V_62 -> V_96 = V_97 ;
V_62 -> V_98 = 0 ;
V_62 -> V_99 = 0 ;
V_62 -> V_100 = 0 ;
V_62 -> V_101 = 0 ;
V_62 -> V_102 = 0 ;
V_62 -> V_103 = 0 ;
V_62 -> V_104 = 0 ;
F_6 (m, &kclist_head, list) {
V_63 = (struct V_13 * ) V_54 ;
V_54 += sizeof( struct V_13 ) ;
V_66 += sizeof( struct V_13 ) ;
V_63 -> V_96 = V_105 ;
V_63 -> V_103 = V_106 | V_107 | V_108 ;
V_63 -> V_98 = F_7 ( V_11 -> V_3 ) + V_59 ;
V_63 -> V_99 = ( T_1 ) V_11 -> V_3 ;
V_63 -> V_100 = 0 ;
V_63 -> V_101 = V_63 -> V_102 = V_11 -> V_4 ;
V_63 -> V_104 = V_40 ;
}
V_62 -> V_98 = V_66 ;
V_65 [ 0 ] . V_51 = V_15 ;
V_65 [ 0 ] . type = V_109 ;
V_65 [ 0 ] . V_52 = sizeof( struct V_16 ) ;
V_65 [ 0 ] . V_58 = & V_60 ;
memset ( & V_60 , 0 , sizeof( struct V_16 ) ) ;
V_62 -> V_101 = F_31 ( & V_65 [ 0 ] ) ;
V_54 = F_32 ( & V_65 [ 0 ] , V_54 ) ;
V_65 [ 1 ] . V_51 = V_15 ;
V_65 [ 1 ] . type = V_110 ;
V_65 [ 1 ] . V_52 = sizeof( struct V_17 ) ;
V_65 [ 1 ] . V_58 = & V_61 ;
memset ( & V_61 , 0 , sizeof( struct V_17 ) ) ;
V_61 . V_111 = 0 ;
V_61 . V_112 = 'R' ;
V_61 . V_113 = 0 ;
strcpy ( V_61 . V_114 , L_1 ) ;
F_35 ( V_61 . V_115 , V_116 , sizeof( V_61 . V_115 ) ) ;
V_62 -> V_101 += F_31 ( & V_65 [ 1 ] ) ;
V_54 = F_32 ( & V_65 [ 1 ] , V_54 ) ;
V_65 [ 2 ] . V_51 = V_15 ;
V_65 [ 2 ] . type = V_117 ;
V_65 [ 2 ] . V_52 = sizeof( struct V_18 ) ;
V_65 [ 2 ] . V_58 = V_118 ;
V_62 -> V_101 += F_31 ( & V_65 [ 2 ] ) ;
V_54 = F_32 ( & V_65 [ 2 ] , V_54 ) ;
}
static T_4
F_36 ( struct V_119 * V_119 , char T_5 * V_120 , T_1 V_121 , T_6 * V_122 )
{
T_4 V_123 = 0 ;
T_1 V_4 , V_124 ;
T_1 V_9 ;
int V_8 ;
unsigned long V_36 ;
F_37 ( & V_5 ) ;
V_4 = F_5 ( & V_8 , & V_9 ) ;
if ( V_121 == 0 || * V_122 >= V_4 ) {
F_38 ( & V_5 ) ;
return 0 ;
}
if ( V_121 > V_4 - * V_122 )
V_121 = V_4 - * V_122 ;
if ( * V_122 < V_9 ) {
char * V_125 ;
V_124 = V_9 - * V_122 ;
if ( V_121 < V_124 )
V_124 = V_121 ;
V_125 = F_39 ( V_9 , V_126 ) ;
if ( ! V_125 ) {
F_38 ( & V_5 ) ;
return - V_31 ;
}
F_34 ( V_125 , V_8 , V_9 ) ;
F_38 ( & V_5 ) ;
if ( F_40 ( V_120 , V_125 + * V_122 , V_124 ) ) {
F_13 ( V_125 ) ;
return - V_127 ;
}
F_13 ( V_125 ) ;
V_121 -= V_124 ;
* V_122 += V_124 ;
V_120 += V_124 ;
V_123 += V_124 ;
if ( V_121 == 0 )
return V_123 ;
} else
F_38 ( & V_5 ) ;
V_36 = F_41 ( * V_122 - V_9 ) ;
if ( ( V_124 = ( V_40 - ( V_36 & ~ V_39 ) ) ) > V_121 )
V_124 = V_121 ;
while ( V_121 ) {
struct V_1 * V_11 ;
F_37 ( & V_5 ) ;
F_6 (m, &kclist_head, list) {
if ( V_36 >= V_11 -> V_3 && V_36 < ( V_11 -> V_3 + V_11 -> V_4 ) )
break;
}
F_38 ( & V_5 ) ;
if ( & V_11 -> V_6 == & V_7 ) {
if ( F_42 ( V_120 , V_124 ) )
return - V_127 ;
} else if ( F_43 ( ( void * ) V_36 ) ) {
char * V_125 ;
V_125 = F_39 ( V_124 , V_30 ) ;
if ( ! V_125 )
return - V_31 ;
F_44 ( V_125 , ( char * ) V_36 , V_124 ) ;
if ( F_40 ( V_120 , V_125 , V_124 ) ) {
F_13 ( V_125 ) ;
return - V_127 ;
}
F_13 ( V_125 ) ;
} else {
if ( F_45 ( V_36 ) ) {
unsigned long V_128 ;
V_128 = F_40 ( V_120 , ( char * ) V_36 , V_124 ) ;
if ( V_128 ) {
if ( F_42 ( V_120 + V_124 - V_128 ,
V_128 ) )
return - V_127 ;
}
} else {
if ( F_42 ( V_120 , V_124 ) )
return - V_127 ;
}
}
V_121 -= V_124 ;
* V_122 += V_124 ;
V_120 += V_124 ;
V_123 += V_124 ;
V_36 += V_124 ;
V_124 = ( V_121 > V_40 ? V_40 : V_121 ) ;
}
return V_123 ;
}
static int F_46 ( struct V_129 * V_129 , struct V_119 * V_130 )
{
if ( ! F_47 ( V_131 ) )
return - V_132 ;
if ( V_24 )
F_19 () ;
if ( F_48 ( V_129 ) != V_27 -> V_4 ) {
F_49 ( & V_129 -> V_133 ) ;
F_50 ( V_129 , V_27 -> V_4 ) ;
F_51 ( & V_129 -> V_133 ) ;
}
return 0 ;
}
static int T_7 F_52 ( struct V_134 * V_135 ,
unsigned long V_136 , void * V_41 )
{
switch ( V_136 ) {
case V_137 :
case V_138 :
F_2 ( & V_5 ) ;
V_24 = 1 ;
F_4 ( & V_5 ) ;
}
return V_139 ;
}
static void T_8 F_53 ( void )
{
F_1 ( & V_140 , V_141 , V_142 - V_141 , V_143 ) ;
}
static void T_8 F_53 ( void )
{
}
static void T_8 F_54 ( void )
{
F_1 ( & V_144 , ( void * ) V_145 ,
V_146 - V_145 , V_147 ) ;
}
static void T_8 F_54 ( void )
{
}
static int T_8 F_55 ( void )
{
V_27 = F_56 ( L_2 , V_148 , NULL ,
& V_149 ) ;
if ( ! V_27 ) {
F_57 ( L_3 ) ;
return 0 ;
}
F_53 () ;
F_1 ( & V_150 , ( void * ) V_44 ,
V_151 - V_44 , V_147 ) ;
F_54 () ;
F_19 () ;
F_58 ( & V_152 ) ;
return 0 ;
}
