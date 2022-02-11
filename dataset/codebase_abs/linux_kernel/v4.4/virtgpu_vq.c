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
int V_22 , V_23 , V_24 = 0 ;
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
if ( F_20 ( F_21 ( & V_2 -> V_26 ) ) )
return;
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
{
struct V_10 * V_11 = V_2 -> V_17 . V_11 ;
struct V_62 * V_63 [ 3 ] , V_64 , V_65 , V_66 ;
int V_67 = 0 , V_68 = 0 ;
int V_69 ;
if ( ! V_2 -> V_70 )
return - V_71 ;
F_50 ( & V_64 , V_21 -> V_36 , V_21 -> V_23 ) ;
V_63 [ V_67 + V_68 ] = & V_64 ;
V_67 ++ ;
if ( V_21 -> V_72 ) {
F_50 ( & V_65 , V_21 -> V_44 , V_21 -> V_72 ) ;
V_63 [ V_67 + V_68 ] = & V_65 ;
V_67 ++ ;
}
if ( V_21 -> V_32 ) {
F_50 ( & V_66 , V_21 -> V_33 , V_21 -> V_32 ) ;
V_63 [ V_67 + V_68 ] = & V_66 ;
V_68 ++ ;
}
V_73:
V_69 = F_51 ( V_11 , V_63 , V_67 , V_68 , V_21 , V_74 ) ;
if ( V_69 == - V_75 ) {
F_5 ( & V_2 -> V_17 . V_55 ) ;
F_52 ( V_2 -> V_17 . V_61 , V_11 -> V_76 ) ;
F_3 ( & V_2 -> V_17 . V_55 ) ;
goto V_73;
} else {
F_53 ( V_11 ) ;
}
if ( ! V_69 )
V_69 = V_11 -> V_76 ;
return V_69 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_77 ;
F_3 ( & V_2 -> V_17 . V_55 ) ;
V_77 = F_49 ( V_2 , V_21 ) ;
F_5 ( & V_2 -> V_17 . V_55 ) ;
return V_77 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_39 * V_78 ,
struct V_79 * * V_80 )
{
struct V_10 * V_11 = V_2 -> V_17 . V_11 ;
int V_77 ;
V_81:
F_3 ( & V_2 -> V_17 . V_55 ) ;
if ( V_11 -> V_76 < 3 ) {
F_5 ( & V_2 -> V_17 . V_55 ) ;
F_52 ( V_2 -> V_17 . V_61 , V_11 -> V_76 >= 3 ) ;
goto V_81;
}
if ( V_80 )
F_56 ( V_2 , V_78 , V_80 ) ;
V_77 = F_49 ( V_2 , V_21 ) ;
F_5 ( & V_2 -> V_17 . V_55 ) ;
return V_77 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_10 * V_11 = V_2 -> V_19 . V_11 ;
struct V_62 * V_63 [ 1 ] , V_82 ;
int V_69 ;
int V_67 ;
if ( ! V_2 -> V_70 )
return - V_71 ;
F_50 ( & V_82 , V_21 -> V_36 , V_21 -> V_23 ) ;
V_63 [ 0 ] = & V_82 ;
V_67 = 1 ;
F_3 ( & V_2 -> V_19 . V_55 ) ;
V_73:
V_69 = F_51 ( V_11 , V_63 , V_67 , 0 , V_21 , V_74 ) ;
if ( V_69 == - V_75 ) {
F_5 ( & V_2 -> V_19 . V_55 ) ;
F_52 ( V_2 -> V_19 . V_61 , V_11 -> V_76 ) ;
F_3 ( & V_2 -> V_19 . V_55 ) ;
goto V_73;
} else {
F_53 ( V_11 ) ;
}
F_5 ( & V_2 -> V_19 . V_55 ) ;
if ( ! V_69 )
V_69 = V_11 -> V_76 ;
return V_69 ;
}
void F_58 ( struct V_1 * V_2 ,
T_1 V_83 ,
T_1 V_84 ,
T_1 V_85 ,
T_1 V_86 )
{
struct V_87 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_89 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
V_88 -> V_84 = F_42 ( V_84 ) ;
V_88 -> V_85 = F_42 ( V_85 ) ;
V_88 -> V_86 = F_42 ( V_86 ) ;
F_54 ( V_2 , V_21 ) ;
}
void F_59 ( struct V_1 * V_2 ,
T_1 V_83 )
{
struct V_90 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_91 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
F_54 ( V_2 , V_21 ) ;
}
void F_60 ( struct V_1 * V_2 ,
T_1 V_83 )
{
struct V_92 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_93 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
F_54 ( V_2 , V_21 ) ;
}
void F_61 ( struct V_1 * V_2 ,
T_1 V_94 , T_1 V_83 ,
T_1 V_85 , T_1 V_86 ,
T_1 V_95 , T_1 V_96 )
{
struct V_97 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_98 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
V_88 -> V_94 = F_42 ( V_94 ) ;
V_88 -> V_99 . V_85 = F_42 ( V_85 ) ;
V_88 -> V_99 . V_86 = F_42 ( V_86 ) ;
V_88 -> V_99 . V_95 = F_42 ( V_95 ) ;
V_88 -> V_99 . V_96 = F_42 ( V_96 ) ;
F_54 ( V_2 , V_21 ) ;
}
void F_62 ( struct V_1 * V_2 ,
T_1 V_83 ,
T_1 V_95 , T_1 V_96 ,
T_1 V_85 , T_1 V_86 )
{
struct V_100 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_101 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
V_88 -> V_99 . V_85 = F_42 ( V_85 ) ;
V_88 -> V_99 . V_86 = F_42 ( V_86 ) ;
V_88 -> V_99 . V_95 = F_42 ( V_95 ) ;
V_88 -> V_99 . V_96 = F_42 ( V_96 ) ;
F_54 ( V_2 , V_21 ) ;
}
void F_63 ( struct V_1 * V_2 ,
T_1 V_83 , T_4 V_102 ,
T_5 V_85 , T_5 V_86 ,
T_5 V_95 , T_5 V_96 ,
struct V_79 * * V_80 )
{
struct V_103 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_104 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
V_88 -> V_102 = F_64 ( V_102 ) ;
V_88 -> V_99 . V_85 = V_85 ;
V_88 -> V_99 . V_86 = V_86 ;
V_88 -> V_99 . V_95 = V_95 ;
V_88 -> V_99 . V_96 = V_96 ;
F_55 ( V_2 , V_21 , & V_88 -> V_78 , V_80 ) ;
}
static void
F_65 ( struct V_1 * V_2 ,
T_1 V_83 ,
struct V_105 * V_106 ,
T_1 V_107 ,
struct V_79 * * V_80 )
{
struct V_108 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_109 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
V_88 -> V_110 = F_42 ( V_107 ) ;
V_21 -> V_44 = V_106 ;
V_21 -> V_72 = sizeof( * V_106 ) * V_107 ;
F_55 ( V_2 , V_21 , & V_88 -> V_78 , V_80 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_111 * V_53 =
(struct V_111 * ) V_21 -> V_33 ;
int V_22 ;
F_3 ( & V_2 -> V_112 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_113 ; V_22 ++ ) {
V_2 -> V_114 [ V_22 ] . V_115 = V_53 -> V_116 [ V_22 ] ;
if ( V_53 -> V_116 [ V_22 ] . V_117 ) {
F_36 ( L_5 , V_22 ,
F_43 ( V_53 -> V_116 [ V_22 ] . V_99 . V_85 ) ,
F_43 ( V_53 -> V_116 [ V_22 ] . V_99 . V_86 ) ,
F_43 ( V_53 -> V_116 [ V_22 ] . V_99 . V_95 ) ,
F_43 ( V_53 -> V_116 [ V_22 ] . V_99 . V_96 ) ) ;
} else {
F_36 ( L_6 , V_22 ) ;
}
}
V_2 -> V_118 = false ;
F_5 ( & V_2 -> V_112 ) ;
F_46 ( & V_2 -> V_119 ) ;
if ( ! F_67 ( V_2 -> V_120 ) )
F_68 ( V_2 -> V_120 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_121 * V_122 =
(struct V_121 * ) V_21 -> V_36 ;
struct V_123 * V_53 =
(struct V_123 * ) V_21 -> V_33 ;
int V_22 = F_43 ( V_122 -> V_124 ) ;
F_3 ( & V_2 -> V_112 ) ;
V_2 -> V_125 [ V_22 ] . V_9 = F_43 ( V_53 -> V_126 ) ;
V_2 -> V_125 [ V_22 ] . V_127 = F_43 ( V_53 -> V_128 ) ;
V_2 -> V_125 [ V_22 ] . V_129 = F_43 ( V_53 -> V_130 ) ;
F_5 ( & V_2 -> V_112 ) ;
F_46 ( & V_2 -> V_119 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_131 * V_122 =
(struct V_131 * ) V_21 -> V_36 ;
struct V_132 * V_53 =
(struct V_132 * ) V_21 -> V_33 ;
struct V_133 * V_134 ;
F_3 ( & V_2 -> V_112 ) ;
F_71 (cache_ent, &vgdev->cap_cache, head) {
if ( V_134 -> V_135 == F_43 ( V_122 -> V_136 ) &&
V_134 -> V_9 == F_43 ( V_122 -> V_126 ) ) {
memcpy ( V_134 -> V_137 , V_53 -> V_138 ,
V_134 -> V_23 ) ;
F_72 ( & V_134 -> V_139 , 1 ) ;
break;
}
}
F_5 ( & V_2 -> V_112 ) ;
F_46 ( & V_2 -> V_119 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_39 * V_88 ;
struct V_20 * V_21 ;
void * V_33 ;
V_33 = F_17 ( sizeof( struct V_111 ) ,
V_5 ) ;
if ( ! V_33 )
return - V_30 ;
V_88 = F_31
( V_2 , & F_66 , & V_21 ,
sizeof( * V_88 ) , sizeof( struct V_111 ) ,
V_33 ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_2 -> V_118 = true ;
V_88 -> type = F_42 ( V_140 ) ;
F_54 ( V_2 , V_21 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , int V_141 )
{
struct V_121 * V_88 ;
struct V_20 * V_21 ;
void * V_33 ;
V_33 = F_17 ( sizeof( struct V_123 ) ,
V_5 ) ;
if ( ! V_33 )
return - V_30 ;
V_88 = F_31
( V_2 , & F_69 , & V_21 ,
sizeof( * V_88 ) , sizeof( struct V_123 ) ,
V_33 ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_142 ) ;
V_88 -> V_124 = F_42 ( V_141 ) ;
F_54 ( V_2 , V_21 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 ,
int V_141 , int V_135 ,
struct V_133 * * V_143 )
{
struct V_131 * V_88 ;
struct V_20 * V_21 ;
int V_129 = V_2 -> V_125 [ V_141 ] . V_129 ;
struct V_133 * V_134 ;
void * V_33 ;
if ( V_141 > V_2 -> V_144 )
return - V_145 ;
if ( V_135 > V_2 -> V_125 [ V_141 ] . V_127 )
return - V_145 ;
V_134 = F_17 ( sizeof( * V_134 ) , V_5 ) ;
if ( ! V_134 )
return - V_30 ;
V_134 -> V_137 = F_76 ( V_129 , V_5 ) ;
if ( ! V_134 -> V_137 ) {
F_24 ( V_134 ) ;
return - V_30 ;
}
V_33 = F_17 ( sizeof( struct V_132 ) + V_129 ,
V_5 ) ;
if ( ! V_33 ) {
F_24 ( V_134 -> V_137 ) ;
F_24 ( V_134 ) ;
return - V_30 ;
}
V_134 -> V_135 = V_135 ;
V_134 -> V_9 = V_2 -> V_125 [ V_141 ] . V_9 ;
F_72 ( & V_134 -> V_139 , 0 ) ;
V_134 -> V_23 = V_129 ;
F_3 ( & V_2 -> V_112 ) ;
F_35 ( & V_134 -> V_146 , & V_2 -> V_147 ) ;
F_5 ( & V_2 -> V_112 ) ;
V_88 = F_31
( V_2 , & F_70 , & V_21 , sizeof( * V_88 ) ,
sizeof( struct V_132 ) + V_129 ,
V_33 ) ;
V_88 -> V_78 . type = F_42 ( V_148 ) ;
V_88 -> V_126 = F_42 ( V_2 -> V_125 [ V_141 ] . V_9 ) ;
V_88 -> V_136 = F_42 ( V_135 ) ;
* V_143 = V_134 ;
F_54 ( V_2 , V_21 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 , T_1 V_9 ,
T_1 V_149 , const char * V_150 )
{
struct V_151 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_152 ) ;
V_88 -> V_78 . V_153 = F_42 ( V_9 ) ;
V_88 -> V_149 = F_42 ( V_149 ) ;
strncpy ( V_88 -> V_154 , V_150 , sizeof( V_88 -> V_154 ) - 1 ) ;
V_88 -> V_154 [ sizeof( V_88 -> V_154 ) - 1 ] = 0 ;
F_54 ( V_2 , V_21 ) ;
}
void F_78 ( struct V_1 * V_2 ,
T_1 V_9 )
{
struct V_155 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_156 ) ;
V_88 -> V_78 . V_153 = F_42 ( V_9 ) ;
F_54 ( V_2 , V_21 ) ;
}
void F_79 ( struct V_1 * V_2 ,
T_1 V_153 ,
T_1 V_83 )
{
struct V_157 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_158 ) ;
V_88 -> V_78 . V_153 = F_42 ( V_153 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
F_54 ( V_2 , V_21 ) ;
}
void F_80 ( struct V_1 * V_2 ,
T_1 V_153 ,
T_1 V_83 )
{
struct V_157 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_159 ) ;
V_88 -> V_78 . V_153 = F_42 ( V_153 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
F_54 ( V_2 , V_21 ) ;
}
void
F_81 ( struct V_1 * V_2 ,
struct V_160 * V_161 ,
struct V_79 * * V_80 )
{
struct V_160 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
* V_88 = * V_161 ;
V_88 -> V_78 . type = F_42 ( V_162 ) ;
V_88 -> V_78 . V_57 = 0 ;
F_55 ( V_2 , V_21 , & V_88 -> V_78 , V_80 ) ;
}
void F_82 ( struct V_1 * V_2 ,
T_1 V_83 , T_1 V_153 ,
T_4 V_102 , T_1 V_163 ,
struct V_164 * V_165 ,
struct V_79 * * V_80 )
{
struct V_166 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_167 ) ;
V_88 -> V_78 . V_153 = F_42 ( V_153 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
V_88 -> V_165 = * V_165 ;
V_88 -> V_102 = F_64 ( V_102 ) ;
V_88 -> V_163 = F_42 ( V_163 ) ;
F_55 ( V_2 , V_21 , & V_88 -> V_78 , V_80 ) ;
}
void F_83 ( struct V_1 * V_2 ,
T_1 V_83 , T_1 V_153 ,
T_4 V_102 , T_1 V_163 ,
struct V_164 * V_165 ,
struct V_79 * * V_80 )
{
struct V_166 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_78 . type = F_42 ( V_168 ) ;
V_88 -> V_78 . V_153 = F_42 ( V_153 ) ;
V_88 -> V_83 = F_42 ( V_83 ) ;
V_88 -> V_165 = * V_165 ;
V_88 -> V_102 = F_64 ( V_102 ) ;
V_88 -> V_163 = F_42 ( V_163 ) ;
F_55 ( V_2 , V_21 , & V_88 -> V_78 , V_80 ) ;
}
void F_84 ( struct V_1 * V_2 ,
void * V_169 , T_1 V_72 ,
T_1 V_153 , struct V_79 * * V_80 )
{
struct F_84 * V_88 ;
struct V_20 * V_21 ;
V_88 = F_27 ( V_2 , & V_21 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_21 -> V_44 = V_169 ;
V_21 -> V_72 = V_72 ;
V_88 -> V_78 . type = F_42 ( V_170 ) ;
V_88 -> V_78 . V_153 = F_42 ( V_153 ) ;
V_88 -> V_23 = F_42 ( V_72 ) ;
F_55 ( V_2 , V_21 , & V_88 -> V_78 , V_80 ) ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_171 * V_172 ,
T_1 V_83 ,
struct V_79 * * V_80 )
{
struct V_105 * V_106 ;
struct V_62 * V_173 ;
int V_174 ;
if ( ! V_172 -> V_175 ) {
int V_69 ;
V_69 = F_86 ( V_2 , V_172 ) ;
if ( V_69 )
return V_69 ;
}
V_106 = F_87 ( V_172 -> V_175 -> V_107 ,
sizeof( struct V_105 ) ,
V_5 ) ;
if ( ! V_106 ) {
F_45 ( L_7 ) ;
return - V_30 ;
}
F_88 (obj->pages->sgl, sg, obj->pages->nents, si) {
V_106 [ V_174 ] . V_176 = F_64 ( F_89 ( V_173 ) ) ;
V_106 [ V_174 ] . V_177 = F_42 ( V_173 -> V_177 ) ;
V_106 [ V_174 ] . V_178 = 0 ;
}
F_65 ( V_2 , V_83 ,
V_106 , V_172 -> V_175 -> V_107 ,
V_80 ) ;
V_172 -> V_179 = V_83 ;
return 0 ;
}
void F_90 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
struct V_20 * V_21 ;
struct V_40 * V_182 ;
V_181 -> V_183 . V_184 . V_94 = F_42 ( V_181 -> V_185 ) ;
V_182 = F_30 ( V_2 , & V_21 ) ;
memcpy ( V_182 , & V_181 -> V_183 , sizeof( V_181 -> V_183 ) ) ;
F_57 ( V_2 , V_21 ) ;
}
