static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 * sizeof( struct V_4 ) ;
}
static inline T_1 F_2 ( const struct V_1 * V_2 )
{
return sizeof( struct V_5 ) + V_2 -> V_3 *
sizeof( V_6 ) ;
}
static inline T_1 F_3 ( void )
{
return sizeof( struct V_7 ) ;
}
static void F_4 ( T_1 V_8 ,
void * V_9 )
{
struct V_7 * V_10 = (struct V_7 * )
V_9 ;
V_10 -> V_11 . V_8 = V_12 ;
V_10 -> V_11 . V_13 = sizeof( V_10 -> V_14 ) ;
V_10 -> V_14 . V_15 = V_8 ;
}
static void F_5 ( const struct V_1 * V_2 ,
void * V_9 )
{
struct V_5 * V_10 = (struct V_5 * )
V_9 ;
struct V_16 * V_17 ;
V_6 * V_18 ;
T_1 V_19 ;
int V_20 ;
V_19 = sizeof( V_10 -> V_14 ) + V_2 -> V_3 * sizeof( V_6 ) ;
V_10 -> V_11 . V_8 = V_21 ;
V_10 -> V_11 . V_13 = V_19 ;
V_10 -> V_14 . V_15 = V_2 -> V_22 . V_8 ;
V_10 -> V_14 . V_23 = V_2 -> V_24 ;
V_10 -> V_14 . V_25 = F_6 ( V_2 -> V_25 ) ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 )
V_10 -> V_14 . V_27 [ V_20 ] . V_28 = V_2 -> V_29 [ V_20 ] ;
V_10 += 1 ;
V_18 = ( V_6 * ) V_10 ;
V_17 = V_2 -> V_30 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_3 ; ++ V_20 , V_18 ++ , V_17 ++ ) {
V_18 -> V_31 = V_17 -> V_31 ;
V_18 -> V_32 = V_17 -> V_32 ;
V_18 -> V_33 = V_17 -> V_33 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
void * V_9 ,
const T_2 * V_34 ,
bool V_35 )
{
T_1 V_20 ;
struct V_4 * V_10 = (struct V_4 * ) V_9 ;
const struct V_36 * V_37 =
F_8 ( V_2 -> V_25 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_3 ; ++ V_20 ) {
T_3 * V_11 = & V_10 -> V_11 ;
T_4 * V_14 = & V_10 -> V_14 ;
T_5 * V_38 = & V_10 -> V_38 ;
T_6 * V_39 = & V_10 -> V_39 ;
const struct V_40 * V_41 = & V_2 -> V_42 [ V_20 ] ;
const struct V_16 * V_43 = & V_2 -> V_30 [ V_20 ] ;
V_11 -> V_8 = V_44 ;
V_11 -> V_13 = sizeof( * V_14 ) + sizeof( * V_38 ) + sizeof( * V_39 ) ;
V_14 -> V_45 . V_34 = * V_34 ;
V_14 -> V_45 . V_34 . V_46 += V_41 -> V_47 ;
V_14 -> V_45 . V_48 = F_9 ( V_37 ,
V_43 ) ;
V_14 -> V_49 . V_15 = V_2 -> V_22 . V_8 ;
V_14 -> V_49 . V_27 = V_41 -> V_27 ;
V_14 -> V_49 . V_50 = V_41 -> V_51 ;
V_14 -> V_52 = ( ( V_35 ) ? V_53 :
V_54 ) ;
V_38 -> V_55 = 0 ;
V_38 -> V_56 = 0 ;
V_38 -> V_57 = 0 ;
V_38 -> V_58 = 0 ;
V_38 -> V_59 = 0 ;
V_38 -> V_60 = 0 ;
V_38 -> V_61 = V_43 -> V_31 ;
V_38 -> V_62 = V_43 -> V_32 ;
V_38 -> V_63 = V_43 -> V_33 ;
V_39 -> V_64 = sizeof( * V_39 ) ;
V_39 -> V_65 =
F_10 ( V_37 , V_43 ,
V_14 -> V_45 . V_48 ) ;
V_39 -> V_24 . V_66 = 0 ;
V_39 -> V_24 . V_67 = 0 ;
V_39 -> V_24 . V_68 = 0 ;
++ V_10 ;
}
}
static void F_11 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct V_1 * V_2 ;
void * V_10 ;
if ( V_22 -> V_8 != - 1 ) {
V_10 = F_12 ( V_71 , F_3 () ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_2 ) ;
return;
}
F_4 ( V_22 -> V_8 , V_10 ) ;
F_15 ( V_71 , F_3 () ) ;
F_16 ( & V_71 -> V_72 ) ;
V_2 = F_17 ( V_22 ) ;
V_71 -> V_73 -= V_22 -> V_74 ;
F_18 ( & V_71 -> V_72 ) ;
}
F_19 ( V_71 , false ) ;
}
static int F_20 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct V_1 * V_2 ;
T_1 V_75 ;
T_7 * V_10 ;
int V_76 ;
if ( F_21 ( V_22 -> V_8 != - 1 ) )
return 0 ;
V_2 = F_17 ( V_22 ) ;
if ( F_13 ( V_71 -> V_73 + V_22 -> V_74 >=
V_71 -> V_77 ) )
return - V_78 ;
V_76 = F_22 ( V_22 ) ;
if ( F_13 ( V_76 != 0 ) ) {
F_14 ( L_3 ) ;
goto V_79;
}
if ( F_13 ( V_22 -> V_8 >= V_80 ) ) {
V_76 = - V_78 ;
goto V_81;
}
V_75 = F_2 ( V_2 ) ;
V_10 = F_12 ( V_71 , V_75 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_4 ) ;
V_76 = - V_82 ;
goto V_81;
}
F_5 ( V_2 , V_10 ) ;
F_15 ( V_71 , V_75 ) ;
V_71 -> V_73 += V_22 -> V_74 ;
return 0 ;
V_81:
F_23 ( V_22 ) ;
V_79:
return V_76 ;
}
static int F_24 ( struct V_69 * V_22 ,
struct V_83 * V_84 ,
bool V_85 )
{
T_2 V_34 ;
struct V_86 * V_87 ;
T_1 V_75 ;
struct V_1 * V_2 = F_17 ( V_22 ) ;
T_7 * V_10 ;
struct V_70 * V_71 = V_22 -> V_71 ;
F_25 ( V_84 -> V_88 == NULL ) ;
V_75 = F_1 ( V_2 ) ;
V_10 = F_12 ( V_71 , V_75 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_5 ) ;
return - V_82 ;
}
F_26 ( V_84 -> V_88 , & V_34 ) ;
F_7 ( V_2 , V_10 , & V_34 , V_85 ) ;
F_15 ( V_71 , V_75 ) ;
( void ) F_27 ( NULL , V_71 ,
& V_87 , NULL ) ;
F_28 ( V_84 -> V_88 , V_87 ) ;
if ( F_21 ( V_87 != NULL ) )
F_29 ( & V_87 ) ;
return 0 ;
}
static int F_30 ( struct V_69 * V_22 ,
struct V_83 * V_84 )
{
if ( ! V_22 -> V_89 )
return 0 ;
return F_24 ( V_22 , V_84 , true ) ;
}
static int F_31 ( struct V_69 * V_22 ,
bool V_90 ,
struct V_83 * V_84 )
{
if ( F_13 ( V_90 ) )
return F_24 ( V_22 , V_84 , false ) ;
return 0 ;
}
static int F_32 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
T_1 V_75 ;
T_7 * V_10 ;
F_25 ( V_22 -> V_8 == - 1 ) ;
V_75 = F_3 () ;
V_10 = F_12 ( V_71 , V_75 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_6 ) ;
return - V_82 ;
}
F_4 ( V_22 -> V_8 , V_10 ) ;
F_15 ( V_71 , V_75 ) ;
V_71 -> V_73 -= V_22 -> V_74 ;
F_23 ( V_22 ) ;
return 0 ;
}
static int F_33 ( struct V_70 * V_71 ,
struct V_1 * V_2 ,
void (* F_34) ( struct V_69 * V_22 ) )
{
int V_76 ;
struct V_69 * V_22 = & V_2 -> V_22 ;
F_25 ( F_34 == NULL ) ;
( void ) F_35 ( V_71 , false ) ;
V_76 = F_36 ( V_71 , V_22 , true , F_34 ,
& V_91 ) ;
if ( F_13 ( V_76 != 0 ) ) {
F_19 ( V_71 , false ) ;
F_34 ( V_22 ) ;
return V_76 ;
}
F_37 ( V_22 , F_11 ) ;
return V_76 ;
}
static struct V_69 *
F_38 ( struct V_92 * V_93 )
{
return & ( F_39 ( V_93 , struct V_94 ,
V_95 . V_93 ) -> V_2 . V_22 ) ;
}
static void F_40 ( struct V_69 * V_22 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
struct V_94 * V_96 =
F_39 ( V_2 , struct V_94 , V_2 ) ;
struct V_70 * V_71 = V_2 -> V_22 . V_71 ;
T_1 V_13 = V_96 -> V_13 ;
F_41 ( V_2 -> V_42 ) ;
F_41 ( V_2 -> V_30 ) ;
F_41 ( V_2 -> V_97 . V_98 ) ;
F_42 ( V_96 , V_95 ) ;
F_43 ( F_44 ( V_71 ) , V_13 ) ;
}
static void F_45 ( struct V_92 * * V_99 )
{
struct V_92 * V_93 = * V_99 ;
struct V_94 * V_96 =
F_39 ( V_93 , struct V_94 , V_95 . V_93 ) ;
struct V_69 * V_22 = & V_96 -> V_2 . V_22 ;
* V_99 = NULL ;
F_46 ( & V_22 ) ;
}
int F_47 ( struct V_100 * V_101 , void * V_102 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 = (struct V_105 * ) V_102 ;
struct V_107 * V_108 = F_48 ( V_104 ) -> V_108 ;
return F_49 ( V_108 , V_106 -> V_15 , V_109 ) ;
}
int F_50 ( struct V_100 * V_101 , void * V_102 ,
struct V_103 * V_104 )
{
struct V_70 * V_71 = F_51 ( V_101 ) ;
struct V_94 * V_96 ;
struct V_1 * V_2 ;
struct V_69 * V_22 ;
struct V_69 * V_110 ;
union V_111 * V_106 =
(union V_111 * ) V_102 ;
struct V_112 * V_113 = & V_106 -> V_113 ;
struct V_105 * V_114 = & V_106 -> V_114 ;
struct V_107 * V_108 = F_48 ( V_104 ) -> V_108 ;
struct V_16 T_8 * V_115 ;
int V_76 ;
int V_20 , V_116 ;
T_1 V_117 ;
struct V_16 * V_43 ;
struct V_40 * V_41 ;
T_1 V_3 ;
T_1 V_13 ;
struct V_118 * V_119 = V_118 ( V_104 -> V_120 ) ;
const struct V_36 * V_37 ;
if ( F_13 ( V_121 == 0 ) )
V_121 = F_52 ( sizeof( * V_96 ) ) +
128 ;
V_3 = 0 ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 )
V_3 += V_113 -> V_29 [ V_20 ] ;
if ( V_3 > V_26 *
V_122 )
return - V_123 ;
V_13 = V_121 + 128 +
F_52 ( V_3 * sizeof( struct V_16 ) ) +
F_52 ( V_3 * sizeof( struct V_40 ) ) ;
V_37 = F_8 ( V_113 -> V_25 ) ;
if ( F_13 ( V_37 -> V_124 == V_125 ) ) {
F_14 ( L_7 ) ;
return - V_123 ;
}
V_76 = F_53 ( & V_119 -> V_126 , true ) ;
if ( F_13 ( V_76 != 0 ) )
return V_76 ;
V_76 = F_54 ( F_44 ( V_71 ) ,
V_13 , false , true ) ;
if ( F_13 ( V_76 != 0 ) ) {
if ( V_76 != - V_127 )
F_14 ( L_8
L_9 ) ;
goto V_128;
}
V_96 = F_55 ( sizeof( * V_96 ) , V_129 ) ;
if ( F_13 ( V_96 == NULL ) ) {
V_76 = - V_82 ;
goto V_130;
}
V_2 = & V_96 -> V_2 ;
V_22 = & V_2 -> V_22 ;
V_2 -> V_24 = V_113 -> V_24 ;
V_2 -> V_25 = V_113 -> V_25 ;
V_2 -> V_131 = V_113 -> V_131 ;
memcpy ( V_2 -> V_29 , V_113 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
V_2 -> V_3 = V_3 ;
V_96 -> V_13 = V_13 ;
V_2 -> V_30 = F_56 ( V_2 -> V_3 * sizeof( * V_2 -> V_30 ) , V_129 ) ;
if ( F_13 ( V_2 -> V_30 == NULL ) ) {
V_76 = - V_82 ;
goto V_132;
}
V_2 -> V_42 = F_56 ( V_2 -> V_3 * sizeof( * V_2 -> V_42 ) ,
V_129 ) ;
if ( F_13 ( V_2 -> V_30 == NULL ) ) {
V_76 = - V_82 ;
goto V_133;
}
V_115 = (struct V_16 T_8 * ) ( unsigned long )
V_113 -> V_134 ;
V_76 = F_57 ( V_2 -> V_30 , V_115 ,
V_2 -> V_3 * sizeof( * V_2 -> V_30 ) ) ;
if ( F_13 ( V_76 != 0 ) ) {
V_76 = - V_135 ;
goto V_136;
}
V_2 -> V_137 = * V_2 -> V_30 ;
V_2 -> V_138 = V_139 ;
V_2 -> V_140 = 1 ;
V_117 = 0 ;
V_41 = V_2 -> V_42 ;
V_43 = V_2 -> V_30 ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 ) {
for ( V_116 = 0 ; V_116 < V_2 -> V_29 [ V_20 ] ; ++ V_116 ) {
T_1 V_141 = F_9
( V_37 , V_43 ) ;
V_41 -> V_27 = V_20 ;
V_41 -> V_51 = V_116 ;
V_41 -> V_47 = V_117 ;
V_117 += F_10
( V_37 , V_43 , V_141 ) ;
++ V_41 ;
++ V_43 ;
}
}
V_22 -> V_74 = V_117 ;
if ( V_2 -> V_131 &&
V_2 -> V_3 == 1 &&
V_2 -> V_30 [ 0 ] . V_31 == 64 &&
V_2 -> V_30 [ 0 ] . V_32 == 64 &&
V_2 -> V_25 == V_142 ) {
V_2 -> V_97 . V_98 = F_56 ( 64 * 64 * 4 , V_129 ) ;
if ( V_2 -> V_97 . V_98 ) {
memset ( V_2 -> V_97 . V_98 , 0x00 , 64 * 64 * 4 ) ;
} else {
F_14 ( L_10 ) ;
V_76 = - V_82 ;
goto V_136;
}
} else {
V_2 -> V_97 . V_98 = NULL ;
}
V_2 -> V_97 . V_143 = NULL ;
V_96 -> V_95 . V_93 . V_144 = false ;
V_96 -> V_95 . V_93 . V_108 = NULL ;
V_76 = F_33 ( V_71 , V_2 , F_40 ) ;
if ( F_13 ( V_76 != 0 ) )
goto V_128;
V_110 = F_58 ( & V_2 -> V_22 ) ;
V_76 = F_59 ( V_108 , V_22 -> V_74 , & V_96 -> V_95 ,
V_113 -> V_144 , V_145 ,
& F_45 , NULL ) ;
if ( F_13 ( V_76 != 0 ) ) {
F_46 ( & V_110 ) ;
F_46 ( & V_22 ) ;
goto V_128;
}
V_114 -> V_15 = V_96 -> V_95 . V_93 . V_146 . V_147 ;
F_46 ( & V_22 ) ;
F_60 ( & V_119 -> V_126 ) ;
return 0 ;
V_136:
F_41 ( V_2 -> V_42 ) ;
V_133:
F_41 ( V_2 -> V_30 ) ;
V_132:
F_42 ( V_96 , V_95 ) ;
V_130:
F_43 ( F_44 ( V_71 ) , V_13 ) ;
V_128:
F_60 ( & V_119 -> V_126 ) ;
return V_76 ;
}
int F_61 ( struct V_100 * V_101 , void * V_102 ,
struct V_103 * V_104 )
{
union V_148 * V_106 =
(union V_148 * ) V_102 ;
struct V_105 * V_113 = & V_106 -> V_113 ;
struct V_112 * V_114 = & V_106 -> V_114 ;
struct V_107 * V_108 = F_48 ( V_104 ) -> V_108 ;
struct V_1 * V_2 ;
struct V_94 * V_96 ;
struct V_16 T_8 * V_115 ;
struct V_92 * V_93 ;
int V_76 = - V_123 ;
V_93 = F_62 ( V_108 , V_113 -> V_15 ) ;
if ( F_13 ( V_93 == NULL ) ) {
F_14 ( L_11 ) ;
return - V_123 ;
}
if ( F_13 ( F_63 ( V_93 ) != V_145 ) )
goto V_149;
V_96 = F_39 ( V_93 , struct V_94 , V_95 . V_93 ) ;
V_2 = & V_96 -> V_2 ;
V_76 = F_64 ( V_108 , & V_96 -> V_95 . V_93 ,
V_109 , NULL ) ;
if ( F_13 ( V_76 != 0 ) ) {
F_14 ( L_12 ) ;
goto V_150;
}
V_114 -> V_24 = V_2 -> V_24 ;
V_114 -> V_25 = V_2 -> V_25 ;
memcpy ( V_114 -> V_29 , V_2 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
V_115 = (struct V_16 T_8 * ) ( unsigned long )
V_114 -> V_134 ;
if ( V_115 )
V_76 = F_65 ( V_115 , V_2 -> V_30 ,
V_2 -> V_3 * sizeof( * V_2 -> V_30 ) ) ;
if ( F_13 ( V_76 != 0 ) ) {
F_14 ( L_13 ,
V_115 , V_2 -> V_3 ) ;
V_76 = - V_135 ;
}
V_149:
V_150:
F_66 ( & V_93 ) ;
return V_76 ;
}
