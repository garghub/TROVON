void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
int V_4 ;
F_2 ( V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
V_4 = F_4 ( & V_2 -> V_7 , NULL , 1 , 0 , V_8 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_6 () ;
* V_3 = V_4 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
F_3 ( & V_2 -> V_6 ) ;
F_8 ( & V_2 -> V_7 , V_9 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
void F_9 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
struct V_1 * V_2 = V_13 -> V_16 ;
F_10 ( & V_2 -> V_17 . V_18 ) ;
}
void F_11 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
struct V_1 * V_2 = V_13 -> V_16 ;
F_10 ( & V_2 -> V_19 . V_18 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
V_2 -> V_20 = F_13 ( L_1 ,
V_21 ,
F_14 ( struct V_22 ) ,
0 , NULL ) ;
if ( ! V_2 -> V_20 )
return - V_23 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
}
static struct V_22 *
F_17 ( struct V_1 * V_2 ,
int V_24 , int V_25 , void * V_26 ,
T_2 V_27 )
{
struct V_22 * V_28 ;
V_28 = F_18 ( V_2 -> V_20 , V_5 ) ;
if ( ! V_28 )
return F_19 ( - V_23 ) ;
memset ( V_28 , 0 , V_21 ) ;
F_20 ( V_24 > V_29 ) ;
V_28 -> V_30 = ( void * ) V_28 + sizeof( * V_28 ) ;
V_28 -> V_24 = V_24 ;
V_28 -> V_27 = V_27 ;
V_28 -> V_25 = V_25 ;
if ( V_25 <= V_31 )
V_28 -> V_26 = ( void * ) V_28 -> V_30 + V_24 ;
else
V_28 -> V_26 = V_26 ;
F_20 ( ! V_28 -> V_26 ) ;
return V_28 ;
}
static void * F_21 ( struct V_1 * V_2 ,
struct V_22 * * V_32 ,
int V_24 )
{
struct V_22 * V_28 ;
V_28 = F_17 ( V_2 , V_24 ,
sizeof( struct V_33 ) ,
NULL , NULL ) ;
if ( F_22 ( V_28 ) ) {
* V_32 = NULL ;
return F_23 ( V_28 ) ;
}
* V_32 = V_28 ;
return V_28 -> V_30 ;
}
static struct V_34 *
F_24 ( struct V_1 * V_2 ,
struct V_22 * * V_32 )
{
struct V_22 * V_28 ;
V_28 = F_17
( V_2 , sizeof( struct V_34 ) ,
0 , NULL , NULL ) ;
if ( F_22 ( V_28 ) ) {
* V_32 = NULL ;
return F_23 ( V_28 ) ;
}
* V_32 = V_28 ;
return (struct V_34 * ) V_28 -> V_30 ;
}
static void * F_25 ( struct V_1 * V_2 ,
T_2 V_35 ,
struct V_22 * * V_32 ,
int V_36 , int V_25 ,
void * V_26 )
{
struct V_22 * V_28 ;
V_28 = F_17 ( V_2 , V_36 ,
V_25 , V_26 , V_35 ) ;
if ( F_22 ( V_28 ) ) {
* V_32 = NULL ;
return F_23 ( V_28 ) ;
}
* V_32 = V_28 ;
return (struct V_37 * ) V_28 -> V_30 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_22 * V_28 )
{
if ( V_28 -> V_25 > V_31 )
F_27 ( V_28 -> V_26 ) ;
F_27 ( V_28 -> V_38 ) ;
F_28 ( V_2 -> V_20 , V_28 ) ;
}
static void F_29 ( struct V_10 * V_11 , struct V_39 * V_40 )
{
struct V_22 * V_28 ;
unsigned int V_41 ;
int V_42 = 0 ;
while ( ( V_28 = F_30 ( V_11 , & V_41 ) ) ) {
F_31 ( & V_28 -> V_43 , V_40 ) ;
V_42 ++ ;
}
if ( V_42 == 0 )
F_32 ( L_2 ) ;
}
void F_33 ( struct V_44 * V_45 )
{
struct V_1 * V_2 =
F_34 ( V_45 , struct V_1 ,
V_17 . V_18 ) ;
struct V_39 V_40 ;
struct V_22 * V_46 , * V_47 ;
struct V_33 * V_48 ;
T_3 V_49 = 0 ;
F_35 ( & V_40 ) ;
F_3 ( & V_2 -> V_17 . V_50 ) ;
do {
F_36 ( V_2 -> V_17 . V_11 ) ;
F_29 ( V_2 -> V_17 . V_11 , & V_40 ) ;
} while ( ! F_37 ( V_2 -> V_17 . V_11 ) );
F_5 ( & V_2 -> V_17 . V_50 ) ;
F_38 (entry, tmp, &reclaim_list, list) {
V_48 = (struct V_33 * ) V_46 -> V_26 ;
if ( V_48 -> type != F_39 ( V_51 ) )
F_32 ( L_3 , F_40 ( V_48 -> type ) ) ;
if ( V_48 -> V_52 & F_39 ( V_53 ) ) {
T_3 V_54 = F_41 ( V_48 -> V_49 ) ;
if ( V_49 > V_54 ) {
F_42 ( L_4 ,
V_55 , V_49 , V_54 ) ;
} else {
V_49 = V_54 ;
}
}
if ( V_46 -> V_27 )
V_46 -> V_27 ( V_2 , V_46 ) ;
F_43 ( & V_46 -> V_43 ) ;
F_26 ( V_2 , V_46 ) ;
}
F_44 ( & V_2 -> V_17 . V_56 ) ;
if ( V_49 )
F_45 ( V_2 , V_49 ) ;
}
void F_46 ( struct V_44 * V_45 )
{
struct V_1 * V_2 =
F_34 ( V_45 , struct V_1 ,
V_19 . V_18 ) ;
struct V_39 V_40 ;
struct V_22 * V_46 , * V_47 ;
F_35 ( & V_40 ) ;
F_3 ( & V_2 -> V_19 . V_50 ) ;
do {
F_36 ( V_2 -> V_19 . V_11 ) ;
F_29 ( V_2 -> V_19 . V_11 , & V_40 ) ;
} while ( ! F_37 ( V_2 -> V_19 . V_11 ) );
F_5 ( & V_2 -> V_19 . V_50 ) ;
F_38 (entry, tmp, &reclaim_list, list) {
F_43 ( & V_46 -> V_43 ) ;
F_26 ( V_2 , V_46 ) ;
}
F_44 ( & V_2 -> V_19 . V_56 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_22 * V_28 )
__releases( &vgdev->ctrlq.qlock
static int F_48 ( struct V_1 * V_2 ,
struct V_22 * V_28 )
{
int V_57 ;
F_3 ( & V_2 -> V_17 . V_50 ) ;
V_57 = F_47 ( V_2 , V_28 ) ;
F_5 ( & V_2 -> V_17 . V_50 ) ;
return V_57 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_22 * V_28 ,
struct V_33 * V_58 ,
struct V_59 * * V_60 )
{
struct V_10 * V_11 = V_2 -> V_17 . V_11 ;
int V_57 ;
V_61:
F_3 ( & V_2 -> V_17 . V_50 ) ;
if ( V_11 -> V_62 < 3 ) {
F_5 ( & V_2 -> V_17 . V_50 ) ;
F_50 ( V_2 -> V_17 . V_56 , V_11 -> V_62 >= 3 ) ;
goto V_61;
}
if ( V_60 )
F_51 ( V_2 , V_58 , V_60 ) ;
V_57 = F_47 ( V_2 , V_28 ) ;
F_5 ( & V_2 -> V_17 . V_50 ) ;
return V_57 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_22 * V_28 )
{
struct V_10 * V_11 = V_2 -> V_19 . V_11 ;
struct V_63 * V_64 [ 1 ] , V_65 ;
int V_66 ;
int V_67 ;
if ( ! V_2 -> V_68 )
return - V_69 ;
F_53 ( & V_65 , V_28 -> V_30 , V_28 -> V_24 ) ;
V_64 [ 0 ] = & V_65 ;
V_67 = 1 ;
F_3 ( & V_2 -> V_19 . V_50 ) ;
V_70:
V_66 = F_54 ( V_11 , V_64 , V_67 , 0 , V_28 , V_71 ) ;
if ( V_66 == - V_72 ) {
F_5 ( & V_2 -> V_19 . V_50 ) ;
F_50 ( V_2 -> V_19 . V_56 , V_11 -> V_62 ) ;
F_3 ( & V_2 -> V_19 . V_50 ) ;
goto V_70;
} else {
F_55 ( V_11 ) ;
}
F_5 ( & V_2 -> V_19 . V_50 ) ;
if ( ! V_66 )
V_66 = V_11 -> V_62 ;
return V_66 ;
}
void F_56 ( struct V_1 * V_2 ,
T_1 V_73 ,
T_1 V_74 ,
T_1 V_75 ,
T_1 V_76 )
{
struct V_77 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_79 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
V_78 -> V_74 = F_39 ( V_74 ) ;
V_78 -> V_75 = F_39 ( V_75 ) ;
V_78 -> V_76 = F_39 ( V_76 ) ;
F_48 ( V_2 , V_28 ) ;
}
void F_57 ( struct V_1 * V_2 ,
T_1 V_73 )
{
struct V_80 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_81 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
F_48 ( V_2 , V_28 ) ;
}
void F_58 ( struct V_1 * V_2 ,
T_1 V_73 )
{
struct V_82 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_83 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
F_48 ( V_2 , V_28 ) ;
}
void F_59 ( struct V_1 * V_2 ,
T_1 V_84 , T_1 V_73 ,
T_1 V_75 , T_1 V_76 ,
T_1 V_85 , T_1 V_86 )
{
struct V_87 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_88 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
V_78 -> V_84 = F_39 ( V_84 ) ;
V_78 -> V_89 . V_75 = F_39 ( V_75 ) ;
V_78 -> V_89 . V_76 = F_39 ( V_76 ) ;
V_78 -> V_89 . V_85 = F_39 ( V_85 ) ;
V_78 -> V_89 . V_86 = F_39 ( V_86 ) ;
F_48 ( V_2 , V_28 ) ;
}
void F_60 ( struct V_1 * V_2 ,
T_1 V_73 ,
T_1 V_85 , T_1 V_86 ,
T_1 V_75 , T_1 V_76 )
{
struct V_90 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_91 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
V_78 -> V_89 . V_75 = F_39 ( V_75 ) ;
V_78 -> V_89 . V_76 = F_39 ( V_76 ) ;
V_78 -> V_89 . V_85 = F_39 ( V_85 ) ;
V_78 -> V_89 . V_86 = F_39 ( V_86 ) ;
F_48 ( V_2 , V_28 ) ;
}
void F_61 ( struct V_1 * V_2 ,
T_1 V_73 , T_4 V_92 ,
T_5 V_75 , T_5 V_76 ,
T_5 V_85 , T_5 V_86 ,
struct V_59 * * V_60 )
{
struct V_93 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_94 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
V_78 -> V_92 = F_62 ( V_92 ) ;
V_78 -> V_89 . V_75 = V_75 ;
V_78 -> V_89 . V_76 = V_76 ;
V_78 -> V_89 . V_85 = V_85 ;
V_78 -> V_89 . V_86 = V_86 ;
F_49 ( V_2 , V_28 , & V_78 -> V_58 , V_60 ) ;
}
static void
F_63 ( struct V_1 * V_2 ,
T_1 V_73 ,
struct V_95 * V_96 ,
T_1 V_97 ,
struct V_59 * * V_60 )
{
struct V_98 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_99 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
V_78 -> V_100 = F_39 ( V_97 ) ;
V_28 -> V_38 = V_96 ;
V_28 -> V_101 = sizeof( * V_96 ) * V_97 ;
F_49 ( V_2 , V_28 , & V_78 -> V_58 , V_60 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_22 * V_28 )
{
struct V_102 * V_48 =
(struct V_102 * ) V_28 -> V_26 ;
int V_103 ;
F_3 ( & V_2 -> V_104 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_105 ; V_103 ++ ) {
V_2 -> V_106 [ V_103 ] . V_107 = V_48 -> V_108 [ V_103 ] ;
if ( V_48 -> V_108 [ V_103 ] . V_109 ) {
F_32 ( L_5 , V_103 ,
F_40 ( V_48 -> V_108 [ V_103 ] . V_89 . V_75 ) ,
F_40 ( V_48 -> V_108 [ V_103 ] . V_89 . V_76 ) ,
F_40 ( V_48 -> V_108 [ V_103 ] . V_89 . V_85 ) ,
F_40 ( V_48 -> V_108 [ V_103 ] . V_89 . V_86 ) ) ;
} else {
F_32 ( L_6 , V_103 ) ;
}
}
V_2 -> V_110 = false ;
F_5 ( & V_2 -> V_104 ) ;
F_44 ( & V_2 -> V_111 ) ;
if ( ! F_65 ( V_2 -> V_112 ) )
F_66 ( V_2 -> V_112 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_22 * V_28 )
{
struct V_113 * V_114 =
(struct V_113 * ) V_28 -> V_30 ;
struct V_115 * V_48 =
(struct V_115 * ) V_28 -> V_26 ;
int V_103 = F_40 ( V_114 -> V_116 ) ;
F_3 ( & V_2 -> V_104 ) ;
V_2 -> V_117 [ V_103 ] . V_9 = F_40 ( V_48 -> V_118 ) ;
V_2 -> V_117 [ V_103 ] . V_119 = F_40 ( V_48 -> V_120 ) ;
V_2 -> V_117 [ V_103 ] . V_121 = F_40 ( V_48 -> V_122 ) ;
F_5 ( & V_2 -> V_104 ) ;
F_44 ( & V_2 -> V_111 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_22 * V_28 )
{
struct V_123 * V_114 =
(struct V_123 * ) V_28 -> V_30 ;
struct V_124 * V_48 =
(struct V_124 * ) V_28 -> V_26 ;
struct V_125 * V_126 ;
F_3 ( & V_2 -> V_104 ) ;
F_69 (cache_ent, &vgdev->cap_cache, head) {
if ( V_126 -> V_127 == F_40 ( V_114 -> V_128 ) &&
V_126 -> V_9 == F_40 ( V_114 -> V_118 ) ) {
memcpy ( V_126 -> V_129 , V_48 -> V_130 ,
V_126 -> V_24 ) ;
F_70 ( & V_126 -> V_131 , 1 ) ;
break;
}
}
F_5 ( & V_2 -> V_104 ) ;
F_44 ( & V_2 -> V_111 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_33 * V_78 ;
struct V_22 * V_28 ;
void * V_26 ;
V_26 = F_72 ( sizeof( struct V_102 ) ,
V_5 ) ;
if ( ! V_26 )
return - V_23 ;
V_78 = F_25
( V_2 , & F_64 , & V_28 ,
sizeof( * V_78 ) , sizeof( struct V_102 ) ,
V_26 ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_2 -> V_110 = true ;
V_78 -> type = F_39 ( V_132 ) ;
F_48 ( V_2 , V_28 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 , int V_133 )
{
struct V_113 * V_78 ;
struct V_22 * V_28 ;
void * V_26 ;
V_26 = F_72 ( sizeof( struct V_115 ) ,
V_5 ) ;
if ( ! V_26 )
return - V_23 ;
V_78 = F_25
( V_2 , & F_67 , & V_28 ,
sizeof( * V_78 ) , sizeof( struct V_115 ) ,
V_26 ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_134 ) ;
V_78 -> V_116 = F_39 ( V_133 ) ;
F_48 ( V_2 , V_28 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 ,
int V_133 , int V_127 ,
struct V_125 * * V_135 )
{
struct V_123 * V_78 ;
struct V_22 * V_28 ;
int V_121 = V_2 -> V_117 [ V_133 ] . V_121 ;
struct V_125 * V_126 ;
void * V_26 ;
if ( V_133 > V_2 -> V_136 )
return - V_137 ;
if ( V_127 > V_2 -> V_117 [ V_133 ] . V_119 )
return - V_137 ;
V_126 = F_72 ( sizeof( * V_126 ) , V_5 ) ;
if ( ! V_126 )
return - V_23 ;
V_126 -> V_129 = F_75 ( V_121 , V_5 ) ;
if ( ! V_126 -> V_129 ) {
F_27 ( V_126 ) ;
return - V_23 ;
}
V_26 = F_72 ( sizeof( struct V_124 ) + V_121 ,
V_5 ) ;
if ( ! V_26 ) {
F_27 ( V_126 -> V_129 ) ;
F_27 ( V_126 ) ;
return - V_23 ;
}
V_126 -> V_127 = V_127 ;
V_126 -> V_9 = V_2 -> V_117 [ V_133 ] . V_9 ;
F_70 ( & V_126 -> V_131 , 0 ) ;
V_126 -> V_24 = V_121 ;
F_3 ( & V_2 -> V_104 ) ;
F_31 ( & V_126 -> V_138 , & V_2 -> V_139 ) ;
F_5 ( & V_2 -> V_104 ) ;
V_78 = F_25
( V_2 , & F_68 , & V_28 , sizeof( * V_78 ) ,
sizeof( struct V_124 ) + V_121 ,
V_26 ) ;
V_78 -> V_58 . type = F_39 ( V_140 ) ;
V_78 -> V_118 = F_39 ( V_2 -> V_117 [ V_133 ] . V_9 ) ;
V_78 -> V_128 = F_39 ( V_127 ) ;
* V_135 = V_126 ;
F_48 ( V_2 , V_28 ) ;
return 0 ;
}
void F_76 ( struct V_1 * V_2 , T_1 V_9 ,
T_1 V_141 , const char * V_142 )
{
struct V_143 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_144 ) ;
V_78 -> V_58 . V_145 = F_39 ( V_9 ) ;
V_78 -> V_141 = F_39 ( V_141 ) ;
strncpy ( V_78 -> V_146 , V_142 , sizeof( V_78 -> V_146 ) - 1 ) ;
V_78 -> V_146 [ sizeof( V_78 -> V_146 ) - 1 ] = 0 ;
F_48 ( V_2 , V_28 ) ;
}
void F_77 ( struct V_1 * V_2 ,
T_1 V_9 )
{
struct V_147 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_148 ) ;
V_78 -> V_58 . V_145 = F_39 ( V_9 ) ;
F_48 ( V_2 , V_28 ) ;
}
void F_78 ( struct V_1 * V_2 ,
T_1 V_145 ,
T_1 V_73 )
{
struct V_149 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_150 ) ;
V_78 -> V_58 . V_145 = F_39 ( V_145 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
F_48 ( V_2 , V_28 ) ;
}
void F_79 ( struct V_1 * V_2 ,
T_1 V_145 ,
T_1 V_73 )
{
struct V_149 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_151 ) ;
V_78 -> V_58 . V_145 = F_39 ( V_145 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
F_48 ( V_2 , V_28 ) ;
}
void
F_80 ( struct V_1 * V_2 ,
struct V_152 * V_153 ,
struct V_59 * * V_60 )
{
struct V_152 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
* V_78 = * V_153 ;
V_78 -> V_58 . type = F_39 ( V_154 ) ;
V_78 -> V_58 . V_52 = 0 ;
F_49 ( V_2 , V_28 , & V_78 -> V_58 , V_60 ) ;
}
void F_81 ( struct V_1 * V_2 ,
T_1 V_73 , T_1 V_145 ,
T_4 V_92 , T_1 V_155 ,
struct V_156 * V_157 ,
struct V_59 * * V_60 )
{
struct V_158 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_159 ) ;
V_78 -> V_58 . V_145 = F_39 ( V_145 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
V_78 -> V_157 = * V_157 ;
V_78 -> V_92 = F_62 ( V_92 ) ;
V_78 -> V_155 = F_39 ( V_155 ) ;
F_49 ( V_2 , V_28 , & V_78 -> V_58 , V_60 ) ;
}
void F_82 ( struct V_1 * V_2 ,
T_1 V_73 , T_1 V_145 ,
T_4 V_92 , T_1 V_155 ,
struct V_156 * V_157 ,
struct V_59 * * V_60 )
{
struct V_158 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_78 -> V_58 . type = F_39 ( V_160 ) ;
V_78 -> V_58 . V_145 = F_39 ( V_145 ) ;
V_78 -> V_73 = F_39 ( V_73 ) ;
V_78 -> V_157 = * V_157 ;
V_78 -> V_92 = F_62 ( V_92 ) ;
V_78 -> V_155 = F_39 ( V_155 ) ;
F_49 ( V_2 , V_28 , & V_78 -> V_58 , V_60 ) ;
}
void F_83 ( struct V_1 * V_2 ,
void * V_161 , T_1 V_101 ,
T_1 V_145 , struct V_59 * * V_60 )
{
struct F_83 * V_78 ;
struct V_22 * V_28 ;
V_78 = F_21 ( V_2 , & V_28 , sizeof( * V_78 ) ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_28 -> V_38 = V_161 ;
V_28 -> V_101 = V_101 ;
V_78 -> V_58 . type = F_39 ( V_162 ) ;
V_78 -> V_58 . V_145 = F_39 ( V_145 ) ;
V_78 -> V_24 = F_39 ( V_101 ) ;
F_49 ( V_2 , V_28 , & V_78 -> V_58 , V_60 ) ;
}
int F_84 ( struct V_1 * V_2 ,
struct V_163 * V_164 ,
T_1 V_73 ,
struct V_59 * * V_60 )
{
struct V_95 * V_96 ;
struct V_63 * V_165 ;
int V_166 ;
if ( ! V_164 -> V_167 ) {
int V_66 ;
V_66 = F_85 ( V_2 , V_164 ) ;
if ( V_66 )
return V_66 ;
}
V_96 = F_86 ( V_164 -> V_167 -> V_97 ,
sizeof( struct V_95 ) ,
V_5 ) ;
if ( ! V_96 ) {
F_42 ( L_7 ) ;
return - V_23 ;
}
F_87 (obj->pages->sgl, sg, obj->pages->nents, si) {
V_96 [ V_166 ] . V_168 = F_62 ( F_88 ( V_165 ) ) ;
V_96 [ V_166 ] . V_169 = F_39 ( V_165 -> V_169 ) ;
V_96 [ V_166 ] . V_170 = 0 ;
}
F_63 ( V_2 , V_73 ,
V_96 , V_164 -> V_167 -> V_97 ,
V_60 ) ;
V_164 -> V_171 = V_73 ;
return 0 ;
}
void F_89 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_22 * V_28 ;
struct V_34 * V_174 ;
V_173 -> V_175 . V_176 . V_84 = F_39 ( V_173 -> V_177 ) ;
V_174 = F_24 ( V_2 , & V_28 ) ;
memcpy ( V_174 , & V_173 -> V_175 , sizeof( V_173 -> V_175 ) ) ;
F_52 ( V_2 , V_28 ) ;
}
