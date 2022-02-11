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
struct V_20 * V_21 ;
int V_22 , V_23 , V_24 = 16 ;
void * V_25 ;
F_13 ( & V_2 -> V_26 ) ;
F_14 ( & V_2 -> V_27 ) ;
V_24 += F_15 ( V_2 -> V_17 . V_11 ) ;
V_24 += F_15 ( V_2 -> V_19 . V_11 ) ;
V_23 = V_24 * V_28 ;
F_16 ( L_1 ,
V_24 , V_28 , V_23 / 1024 ) ;
V_2 -> V_29 = F_17 ( V_23 , V_5 ) ;
if ( ! V_2 -> V_29 )
return - V_30 ;
for ( V_22 = 0 , V_25 = V_2 -> V_29 ;
V_22 < V_24 ;
V_22 ++ , V_25 += V_28 ) {
V_21 = V_25 ;
F_18 ( & V_21 -> V_31 , & V_2 -> V_26 ) ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_22 , V_24 = 0 ;
V_24 += F_15 ( V_2 -> V_17 . V_11 ) ;
V_24 += F_15 ( V_2 -> V_19 . V_11 ) ;
F_3 ( & V_2 -> V_27 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
if ( F_20 ( F_21 ( & V_2 -> V_26 ) ) ) {
F_5 ( & V_2 -> V_27 ) ;
return;
}
V_21 = F_22 ( & V_2 -> V_26 ,
struct V_20 , V_31 ) ;
F_23 ( & V_21 -> V_31 ) ;
}
F_5 ( & V_2 -> V_27 ) ;
F_24 ( V_2 -> V_29 ) ;
}
static struct V_20 *
F_25 ( struct V_1 * V_2 ,
int V_23 , int V_32 , void * V_33 ,
T_2 V_34 )
{
struct V_20 * V_21 ;
F_3 ( & V_2 -> V_27 ) ;
F_26 ( F_21 ( & V_2 -> V_26 ) ) ;
V_21 = F_22 ( & V_2 -> V_26 ,
struct V_20 , V_31 ) ;
F_23 ( & V_21 -> V_31 ) ;
F_5 ( & V_2 -> V_27 ) ;
memset ( V_21 , 0 , V_28 ) ;
F_26 ( V_23 > V_35 ) ;
V_21 -> V_36 = ( void * ) V_21 + sizeof( * V_21 ) ;
V_21 -> V_23 = V_23 ;
V_21 -> V_34 = V_34 ;
V_21 -> V_32 = V_32 ;
if ( V_32 <= V_37 )
V_21 -> V_33 = ( void * ) V_21 -> V_36 + V_23 ;
else
V_21 -> V_33 = V_33 ;
F_26 ( ! V_21 -> V_33 ) ;
return V_21 ;
}
static void * F_27 ( struct V_1 * V_2 ,
struct V_20 * * V_38 ,
int V_23 )
{
struct V_20 * V_21 ;
V_21 = F_25 ( V_2 , V_23 ,
sizeof( struct V_39 ) ,
NULL , NULL ) ;
if ( F_28 ( V_21 ) ) {
* V_38 = NULL ;
return F_29 ( V_21 ) ;
}
* V_38 = V_21 ;
return V_21 -> V_36 ;
}
static struct V_40 *
F_30 ( struct V_1 * V_2 ,
struct V_20 * * V_38 )
{
struct V_20 * V_21 ;
V_21 = F_25
( V_2 , sizeof( struct V_40 ) ,
0 , NULL , NULL ) ;
if ( F_28 ( V_21 ) ) {
* V_38 = NULL ;
return F_29 ( V_21 ) ;
}
* V_38 = V_21 ;
return (struct V_40 * ) V_21 -> V_36 ;
}
static void * F_31 ( struct V_1 * V_2 ,
T_2 V_41 ,
struct V_20 * * V_38 ,
int V_42 , int V_32 ,
void * V_33 )
{
struct V_20 * V_21 ;
V_21 = F_25 ( V_2 , V_42 ,
V_32 , V_33 , V_41 ) ;
if ( F_28 ( V_21 ) ) {
* V_38 = NULL ;
return F_29 ( V_21 ) ;
}
* V_38 = V_21 ;
return (struct V_43 * ) V_21 -> V_36 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
if ( V_21 -> V_32 > V_37 )
F_24 ( V_21 -> V_33 ) ;
F_24 ( V_21 -> V_44 ) ;
F_3 ( & V_2 -> V_27 ) ;
F_18 ( & V_21 -> V_31 , & V_2 -> V_26 ) ;
F_5 ( & V_2 -> V_27 ) ;
}
static void F_33 ( struct V_10 * V_11 , struct V_45 * V_46 )
{
struct V_20 * V_21 ;
unsigned int V_47 ;
int V_48 = 0 ;
while ( ( V_21 = F_34 ( V_11 , & V_47 ) ) ) {
F_35 ( & V_21 -> V_31 , V_46 ) ;
V_48 ++ ;
}
if ( V_48 == 0 )
F_36 ( L_2 ) ;
}
void F_37 ( struct V_49 * V_50 )
{
struct V_1 * V_2 =
F_38 ( V_50 , struct V_1 ,
V_17 . V_18 ) ;
struct V_45 V_46 ;
struct V_20 * V_51 , * V_52 ;
struct V_39 * V_53 ;
T_3 V_54 = 0 ;
F_13 ( & V_46 ) ;
F_3 ( & V_2 -> V_17 . V_55 ) ;
do {
F_39 ( V_2 -> V_17 . V_11 ) ;
F_33 ( V_2 -> V_17 . V_11 , & V_46 ) ;
} while ( ! F_40 ( V_2 -> V_17 . V_11 ) );
F_5 ( & V_2 -> V_17 . V_55 ) ;
F_41 (entry, tmp, &reclaim_list, list) {
V_53 = (struct V_39 * ) V_51 -> V_33 ;
if ( V_53 -> type != F_42 ( V_56 ) )
F_36 ( L_3 , F_43 ( V_53 -> type ) ) ;
if ( V_53 -> V_57 & F_42 ( V_58 ) ) {
T_3 V_59 = F_44 ( V_53 -> V_54 ) ;
if ( V_54 > V_59 ) {
F_45 ( L_4 ,
V_60 , V_54 , V_59 ) ;
} else {
V_54 = V_59 ;
}
}
if ( V_51 -> V_34 )
V_51 -> V_34 ( V_2 , V_51 ) ;
F_23 ( & V_51 -> V_31 ) ;
F_32 ( V_2 , V_51 ) ;
}
F_46 ( & V_2 -> V_17 . V_61 ) ;
if ( V_54 )
F_47 ( V_2 , V_54 ) ;
}
void F_48 ( struct V_49 * V_50 )
{
struct V_1 * V_2 =
F_38 ( V_50 , struct V_1 ,
V_19 . V_18 ) ;
struct V_45 V_46 ;
struct V_20 * V_51 , * V_52 ;
F_13 ( & V_46 ) ;
F_3 ( & V_2 -> V_19 . V_55 ) ;
do {
F_39 ( V_2 -> V_19 . V_11 ) ;
F_33 ( V_2 -> V_19 . V_11 , & V_46 ) ;
} while ( ! F_40 ( V_2 -> V_19 . V_11 ) );
F_5 ( & V_2 -> V_19 . V_55 ) ;
F_41 (entry, tmp, &reclaim_list, list) {
F_23 ( & V_51 -> V_31 ) ;
F_32 ( V_2 , V_51 ) ;
}
F_46 ( & V_2 -> V_19 . V_61 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
__releases( &vgdev->ctrlq.qlock
static int F_50 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_62 ;
F_3 ( & V_2 -> V_17 . V_55 ) ;
V_62 = F_49 ( V_2 , V_21 ) ;
F_5 ( & V_2 -> V_17 . V_55 ) ;
return V_62 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_39 * V_63 ,
struct V_64 * * V_65 )
{
struct V_10 * V_11 = V_2 -> V_17 . V_11 ;
int V_62 ;
V_66:
F_3 ( & V_2 -> V_17 . V_55 ) ;
if ( V_11 -> V_67 < 3 ) {
F_5 ( & V_2 -> V_17 . V_55 ) ;
F_52 ( V_2 -> V_17 . V_61 , V_11 -> V_67 >= 3 ) ;
goto V_66;
}
if ( V_65 )
F_53 ( V_2 , V_63 , V_65 ) ;
V_62 = F_49 ( V_2 , V_21 ) ;
F_5 ( & V_2 -> V_17 . V_55 ) ;
return V_62 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_10 * V_11 = V_2 -> V_19 . V_11 ;
struct V_68 * V_69 [ 1 ] , V_70 ;
int V_71 ;
int V_72 ;
if ( ! V_2 -> V_73 )
return - V_74 ;
F_55 ( & V_70 , V_21 -> V_36 , V_21 -> V_23 ) ;
V_69 [ 0 ] = & V_70 ;
V_72 = 1 ;
F_3 ( & V_2 -> V_19 . V_55 ) ;
V_75:
V_71 = F_56 ( V_11 , V_69 , V_72 , 0 , V_21 , V_76 ) ;
if ( V_71 == - V_77 ) {
F_5 ( & V_2 -> V_19 . V_55 ) ;
F_52 ( V_2 -> V_19 . V_61 , V_11 -> V_67 ) ;
F_3 ( & V_2 -> V_19 . V_55 ) ;
goto V_75;
} else {
F_57 ( V_11 ) ;
}
F_5 ( & V_2 -> V_19 . V_55 ) ;
if ( ! V_71 )
V_71 = V_11 -> V_67 ;
return V_71 ;
}
void F_58 ( struct V_1 * V_2 ,
T_1 V_78 ,
T_1 V_79 ,
T_1 V_80 ,
T_1 V_81 )
{
struct V_82 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_84 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_79 = F_42 ( V_79 ) ;
V_83 -> V_80 = F_42 ( V_80 ) ;
V_83 -> V_81 = F_42 ( V_81 ) ;
F_50 ( V_2 , V_21 ) ;
}
void F_59 ( struct V_1 * V_2 ,
T_1 V_78 )
{
struct V_85 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_86 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
F_50 ( V_2 , V_21 ) ;
}
void F_60 ( struct V_1 * V_2 ,
T_1 V_78 )
{
struct V_87 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_88 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
F_50 ( V_2 , V_21 ) ;
}
void F_61 ( struct V_1 * V_2 ,
T_1 V_89 , T_1 V_78 ,
T_1 V_80 , T_1 V_81 ,
T_1 V_90 , T_1 V_91 )
{
struct V_92 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_93 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_89 = F_42 ( V_89 ) ;
V_83 -> V_94 . V_80 = F_42 ( V_80 ) ;
V_83 -> V_94 . V_81 = F_42 ( V_81 ) ;
V_83 -> V_94 . V_90 = F_42 ( V_90 ) ;
V_83 -> V_94 . V_91 = F_42 ( V_91 ) ;
F_50 ( V_2 , V_21 ) ;
}
void F_62 ( struct V_1 * V_2 ,
T_1 V_78 ,
T_1 V_90 , T_1 V_91 ,
T_1 V_80 , T_1 V_81 )
{
struct V_95 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_96 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_94 . V_80 = F_42 ( V_80 ) ;
V_83 -> V_94 . V_81 = F_42 ( V_81 ) ;
V_83 -> V_94 . V_90 = F_42 ( V_90 ) ;
V_83 -> V_94 . V_91 = F_42 ( V_91 ) ;
F_50 ( V_2 , V_21 ) ;
}
void F_63 ( struct V_1 * V_2 ,
T_1 V_78 , T_4 V_97 ,
T_5 V_80 , T_5 V_81 ,
T_5 V_90 , T_5 V_91 ,
struct V_64 * * V_65 )
{
struct V_98 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_99 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_97 = F_64 ( V_97 ) ;
V_83 -> V_94 . V_80 = V_80 ;
V_83 -> V_94 . V_81 = V_81 ;
V_83 -> V_94 . V_90 = V_90 ;
V_83 -> V_94 . V_91 = V_91 ;
F_51 ( V_2 , V_21 , & V_83 -> V_63 , V_65 ) ;
}
static void
F_65 ( struct V_1 * V_2 ,
T_1 V_78 ,
struct V_100 * V_101 ,
T_1 V_102 ,
struct V_64 * * V_65 )
{
struct V_103 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_104 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_105 = F_42 ( V_102 ) ;
V_21 -> V_44 = V_101 ;
V_21 -> V_106 = sizeof( * V_101 ) * V_102 ;
F_51 ( V_2 , V_21 , & V_83 -> V_63 , V_65 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_107 * V_53 =
(struct V_107 * ) V_21 -> V_33 ;
int V_22 ;
F_3 ( & V_2 -> V_108 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_109 ; V_22 ++ ) {
V_2 -> V_110 [ V_22 ] . V_111 = V_53 -> V_112 [ V_22 ] ;
if ( V_53 -> V_112 [ V_22 ] . V_113 ) {
F_36 ( L_5 , V_22 ,
F_43 ( V_53 -> V_112 [ V_22 ] . V_94 . V_80 ) ,
F_43 ( V_53 -> V_112 [ V_22 ] . V_94 . V_81 ) ,
F_43 ( V_53 -> V_112 [ V_22 ] . V_94 . V_90 ) ,
F_43 ( V_53 -> V_112 [ V_22 ] . V_94 . V_91 ) ) ;
} else {
F_36 ( L_6 , V_22 ) ;
}
}
V_2 -> V_114 = false ;
F_5 ( & V_2 -> V_108 ) ;
F_46 ( & V_2 -> V_115 ) ;
if ( ! F_67 ( V_2 -> V_116 ) )
F_68 ( V_2 -> V_116 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_117 * V_118 =
(struct V_117 * ) V_21 -> V_36 ;
struct V_119 * V_53 =
(struct V_119 * ) V_21 -> V_33 ;
int V_22 = F_43 ( V_118 -> V_120 ) ;
F_3 ( & V_2 -> V_108 ) ;
V_2 -> V_121 [ V_22 ] . V_9 = F_43 ( V_53 -> V_122 ) ;
V_2 -> V_121 [ V_22 ] . V_123 = F_43 ( V_53 -> V_124 ) ;
V_2 -> V_121 [ V_22 ] . V_125 = F_43 ( V_53 -> V_126 ) ;
F_5 ( & V_2 -> V_108 ) ;
F_46 ( & V_2 -> V_115 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_127 * V_118 =
(struct V_127 * ) V_21 -> V_36 ;
struct V_128 * V_53 =
(struct V_128 * ) V_21 -> V_33 ;
struct V_129 * V_130 ;
F_3 ( & V_2 -> V_108 ) ;
F_71 (cache_ent, &vgdev->cap_cache, head) {
if ( V_130 -> V_131 == F_43 ( V_118 -> V_132 ) &&
V_130 -> V_9 == F_43 ( V_118 -> V_122 ) ) {
memcpy ( V_130 -> V_133 , V_53 -> V_134 ,
V_130 -> V_23 ) ;
F_72 ( & V_130 -> V_135 , 1 ) ;
break;
}
}
F_5 ( & V_2 -> V_108 ) ;
F_46 ( & V_2 -> V_115 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_39 * V_83 ;
struct V_20 * V_21 ;
void * V_33 ;
V_33 = F_17 ( sizeof( struct V_107 ) ,
V_5 ) ;
if ( ! V_33 )
return - V_30 ;
V_83 = F_31
( V_2 , & F_66 , & V_21 ,
sizeof( * V_83 ) , sizeof( struct V_107 ) ,
V_33 ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_2 -> V_114 = true ;
V_83 -> type = F_42 ( V_136 ) ;
F_50 ( V_2 , V_21 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , int V_137 )
{
struct V_117 * V_83 ;
struct V_20 * V_21 ;
void * V_33 ;
V_33 = F_17 ( sizeof( struct V_119 ) ,
V_5 ) ;
if ( ! V_33 )
return - V_30 ;
V_83 = F_31
( V_2 , & F_69 , & V_21 ,
sizeof( * V_83 ) , sizeof( struct V_119 ) ,
V_33 ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_138 ) ;
V_83 -> V_120 = F_42 ( V_137 ) ;
F_50 ( V_2 , V_21 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 ,
int V_137 , int V_131 ,
struct V_129 * * V_139 )
{
struct V_127 * V_83 ;
struct V_20 * V_21 ;
int V_125 = V_2 -> V_121 [ V_137 ] . V_125 ;
struct V_129 * V_130 ;
void * V_33 ;
if ( V_137 > V_2 -> V_140 )
return - V_141 ;
if ( V_131 > V_2 -> V_121 [ V_137 ] . V_123 )
return - V_141 ;
V_130 = F_17 ( sizeof( * V_130 ) , V_5 ) ;
if ( ! V_130 )
return - V_30 ;
V_130 -> V_133 = F_76 ( V_125 , V_5 ) ;
if ( ! V_130 -> V_133 ) {
F_24 ( V_130 ) ;
return - V_30 ;
}
V_33 = F_17 ( sizeof( struct V_128 ) + V_125 ,
V_5 ) ;
if ( ! V_33 ) {
F_24 ( V_130 -> V_133 ) ;
F_24 ( V_130 ) ;
return - V_30 ;
}
V_130 -> V_131 = V_131 ;
V_130 -> V_9 = V_2 -> V_121 [ V_137 ] . V_9 ;
F_72 ( & V_130 -> V_135 , 0 ) ;
V_130 -> V_23 = V_125 ;
F_3 ( & V_2 -> V_108 ) ;
F_35 ( & V_130 -> V_142 , & V_2 -> V_143 ) ;
F_5 ( & V_2 -> V_108 ) ;
V_83 = F_31
( V_2 , & F_70 , & V_21 , sizeof( * V_83 ) ,
sizeof( struct V_128 ) + V_125 ,
V_33 ) ;
V_83 -> V_63 . type = F_42 ( V_144 ) ;
V_83 -> V_122 = F_42 ( V_2 -> V_121 [ V_137 ] . V_9 ) ;
V_83 -> V_132 = F_42 ( V_131 ) ;
* V_139 = V_130 ;
F_50 ( V_2 , V_21 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 , T_1 V_9 ,
T_1 V_145 , const char * V_146 )
{
struct V_147 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_148 ) ;
V_83 -> V_63 . V_149 = F_42 ( V_9 ) ;
V_83 -> V_145 = F_42 ( V_145 ) ;
strncpy ( V_83 -> V_150 , V_146 , sizeof( V_83 -> V_150 ) - 1 ) ;
V_83 -> V_150 [ sizeof( V_83 -> V_150 ) - 1 ] = 0 ;
F_50 ( V_2 , V_21 ) ;
}
void F_78 ( struct V_1 * V_2 ,
T_1 V_9 )
{
struct V_151 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_152 ) ;
V_83 -> V_63 . V_149 = F_42 ( V_9 ) ;
F_50 ( V_2 , V_21 ) ;
}
void F_79 ( struct V_1 * V_2 ,
T_1 V_149 ,
T_1 V_78 )
{
struct V_153 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_154 ) ;
V_83 -> V_63 . V_149 = F_42 ( V_149 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
F_50 ( V_2 , V_21 ) ;
}
void F_80 ( struct V_1 * V_2 ,
T_1 V_149 ,
T_1 V_78 )
{
struct V_153 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_155 ) ;
V_83 -> V_63 . V_149 = F_42 ( V_149 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
F_50 ( V_2 , V_21 ) ;
}
void
F_81 ( struct V_1 * V_2 ,
struct V_156 * V_157 ,
struct V_64 * * V_65 )
{
struct V_156 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
* V_83 = * V_157 ;
V_83 -> V_63 . type = F_42 ( V_158 ) ;
V_83 -> V_63 . V_57 = 0 ;
F_51 ( V_2 , V_21 , & V_83 -> V_63 , V_65 ) ;
}
void F_82 ( struct V_1 * V_2 ,
T_1 V_78 , T_1 V_149 ,
T_4 V_97 , T_1 V_159 ,
struct V_160 * V_161 ,
struct V_64 * * V_65 )
{
struct V_162 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_163 ) ;
V_83 -> V_63 . V_149 = F_42 ( V_149 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_161 = * V_161 ;
V_83 -> V_97 = F_64 ( V_97 ) ;
V_83 -> V_159 = F_42 ( V_159 ) ;
F_51 ( V_2 , V_21 , & V_83 -> V_63 , V_65 ) ;
}
void F_83 ( struct V_1 * V_2 ,
T_1 V_78 , T_1 V_149 ,
T_4 V_97 , T_1 V_159 ,
struct V_160 * V_161 ,
struct V_64 * * V_65 )
{
struct V_162 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_63 . type = F_42 ( V_164 ) ;
V_83 -> V_63 . V_149 = F_42 ( V_149 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_161 = * V_161 ;
V_83 -> V_97 = F_64 ( V_97 ) ;
V_83 -> V_159 = F_42 ( V_159 ) ;
F_51 ( V_2 , V_21 , & V_83 -> V_63 , V_65 ) ;
}
void F_84 ( struct V_1 * V_2 ,
void * V_165 , T_1 V_106 ,
T_1 V_149 , struct V_64 * * V_65 )
{
struct F_84 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_21 -> V_44 = V_165 ;
V_21 -> V_106 = V_106 ;
V_83 -> V_63 . type = F_42 ( V_166 ) ;
V_83 -> V_63 . V_149 = F_42 ( V_149 ) ;
V_83 -> V_23 = F_42 ( V_106 ) ;
F_51 ( V_2 , V_21 , & V_83 -> V_63 , V_65 ) ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_167 * V_168 ,
T_1 V_78 ,
struct V_64 * * V_65 )
{
struct V_100 * V_101 ;
struct V_68 * V_169 ;
int V_170 ;
if ( ! V_168 -> V_171 ) {
int V_71 ;
V_71 = F_86 ( V_2 , V_168 ) ;
if ( V_71 )
return V_71 ;
}
V_101 = F_87 ( V_168 -> V_171 -> V_102 ,
sizeof( struct V_100 ) ,
V_5 ) ;
if ( ! V_101 ) {
F_45 ( L_7 ) ;
return - V_30 ;
}
F_88 (obj->pages->sgl, sg, obj->pages->nents, si) {
V_101 [ V_170 ] . V_172 = F_64 ( F_89 ( V_169 ) ) ;
V_101 [ V_170 ] . V_173 = F_42 ( V_169 -> V_173 ) ;
V_101 [ V_170 ] . V_174 = 0 ;
}
F_65 ( V_2 , V_78 ,
V_101 , V_168 -> V_171 -> V_102 ,
V_65 ) ;
V_168 -> V_175 = V_78 ;
return 0 ;
}
void F_90 ( struct V_1 * V_2 ,
struct V_176 * V_177 )
{
struct V_20 * V_21 ;
struct V_40 * V_178 ;
V_177 -> V_179 . V_180 . V_89 = F_42 ( V_177 -> V_181 ) ;
V_178 = F_30 ( V_2 , & V_21 ) ;
memcpy ( V_178 , & V_177 -> V_179 , sizeof( V_177 -> V_179 ) ) ;
F_54 ( V_2 , V_21 ) ;
}
