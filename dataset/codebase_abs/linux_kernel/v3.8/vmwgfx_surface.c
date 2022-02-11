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
return & ( F_39 ( V_93 , struct V_94 , V_93 ) -> V_2 . V_22 ) ;
}
static void F_40 ( struct V_69 * V_22 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
struct V_94 * V_95 =
F_39 ( V_2 , struct V_94 , V_2 ) ;
struct V_70 * V_71 = V_2 -> V_22 . V_71 ;
T_1 V_13 = V_95 -> V_13 ;
F_41 ( V_2 -> V_42 ) ;
F_41 ( V_2 -> V_30 ) ;
F_41 ( V_2 -> V_96 . V_97 ) ;
F_42 ( V_95 , V_93 ) ;
F_43 ( F_44 ( V_71 ) , V_13 ) ;
}
static void F_45 ( struct V_92 * * V_98 )
{
struct V_92 * V_93 = * V_98 ;
struct V_94 * V_95 =
F_39 ( V_93 , struct V_94 , V_93 ) ;
struct V_69 * V_22 = & V_95 -> V_2 . V_22 ;
* V_98 = NULL ;
F_46 ( & V_22 ) ;
}
int F_47 ( struct V_99 * V_100 , void * V_101 ,
struct V_102 * V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_101 ;
struct V_106 * V_107 = F_48 ( V_103 ) -> V_107 ;
return F_49 ( V_107 , V_105 -> V_15 , V_108 ) ;
}
int F_50 ( struct V_99 * V_100 , void * V_101 ,
struct V_102 * V_103 )
{
struct V_70 * V_71 = F_51 ( V_100 ) ;
struct V_94 * V_95 ;
struct V_1 * V_2 ;
struct V_69 * V_22 ;
struct V_69 * V_109 ;
union V_110 * V_105 =
(union V_110 * ) V_101 ;
struct V_111 * V_112 = & V_105 -> V_112 ;
struct V_104 * V_113 = & V_105 -> V_113 ;
struct V_106 * V_107 = F_48 ( V_103 ) -> V_107 ;
struct V_16 T_8 * V_114 ;
int V_76 ;
int V_20 , V_115 ;
T_1 V_116 ;
struct V_16 * V_43 ;
struct V_40 * V_41 ;
T_1 V_3 ;
T_1 V_13 ;
struct V_117 * V_118 = V_117 ( V_103 -> V_119 ) ;
const struct V_36 * V_37 ;
if ( F_13 ( V_120 == 0 ) )
V_120 = F_52 ( sizeof( * V_95 ) ) +
128 ;
V_3 = 0 ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 )
V_3 += V_112 -> V_29 [ V_20 ] ;
if ( V_3 > V_26 *
V_121 )
return - V_122 ;
V_13 = V_120 + 128 +
F_52 ( V_3 * sizeof( struct V_16 ) ) +
F_52 ( V_3 * sizeof( struct V_40 ) ) ;
V_37 = F_8 ( V_112 -> V_25 ) ;
if ( F_13 ( V_37 -> V_123 == V_124 ) ) {
F_14 ( L_7 ) ;
return - V_122 ;
}
V_76 = F_53 ( & V_118 -> V_125 , true ) ;
if ( F_13 ( V_76 != 0 ) )
return V_76 ;
V_76 = F_54 ( F_44 ( V_71 ) ,
V_13 , false , true ) ;
if ( F_13 ( V_76 != 0 ) ) {
if ( V_76 != - V_126 )
F_14 ( L_8
L_9 ) ;
goto V_127;
}
V_95 = F_55 ( sizeof( * V_95 ) , V_128 ) ;
if ( F_13 ( V_95 == NULL ) ) {
V_76 = - V_82 ;
goto V_129;
}
V_2 = & V_95 -> V_2 ;
V_22 = & V_2 -> V_22 ;
V_2 -> V_24 = V_112 -> V_24 ;
V_2 -> V_25 = V_112 -> V_25 ;
V_2 -> V_130 = V_112 -> V_130 ;
memcpy ( V_2 -> V_29 , V_112 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
V_2 -> V_3 = V_3 ;
V_95 -> V_13 = V_13 ;
V_2 -> V_30 = F_56 ( V_2 -> V_3 * sizeof( * V_2 -> V_30 ) , V_128 ) ;
if ( F_13 ( V_2 -> V_30 == NULL ) ) {
V_76 = - V_82 ;
goto V_131;
}
V_2 -> V_42 = F_56 ( V_2 -> V_3 * sizeof( * V_2 -> V_42 ) ,
V_128 ) ;
if ( F_13 ( V_2 -> V_30 == NULL ) ) {
V_76 = - V_82 ;
goto V_132;
}
V_114 = (struct V_16 T_8 * ) ( unsigned long )
V_112 -> V_133 ;
V_76 = F_57 ( V_2 -> V_30 , V_114 ,
V_2 -> V_3 * sizeof( * V_2 -> V_30 ) ) ;
if ( F_13 ( V_76 != 0 ) ) {
V_76 = - V_134 ;
goto V_135;
}
V_2 -> V_136 = * V_2 -> V_30 ;
V_2 -> V_137 = V_138 ;
V_2 -> V_139 = 1 ;
V_116 = 0 ;
V_41 = V_2 -> V_42 ;
V_43 = V_2 -> V_30 ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 ) {
for ( V_115 = 0 ; V_115 < V_2 -> V_29 [ V_20 ] ; ++ V_115 ) {
T_1 V_140 = F_9
( V_37 , V_43 ) ;
V_41 -> V_27 = V_20 ;
V_41 -> V_51 = V_115 ;
V_41 -> V_47 = V_116 ;
V_116 += F_10
( V_37 , V_43 , V_140 ) ;
++ V_41 ;
++ V_43 ;
}
}
V_22 -> V_74 = V_116 ;
if ( V_2 -> V_130 &&
V_2 -> V_3 == 1 &&
V_2 -> V_30 [ 0 ] . V_31 == 64 &&
V_2 -> V_30 [ 0 ] . V_32 == 64 &&
V_2 -> V_25 == V_141 ) {
V_2 -> V_96 . V_97 = F_56 ( 64 * 64 * 4 , V_128 ) ;
if ( V_2 -> V_96 . V_97 ) {
memset ( V_2 -> V_96 . V_97 , 0x00 , 64 * 64 * 4 ) ;
} else {
F_14 ( L_10 ) ;
V_76 = - V_82 ;
goto V_135;
}
} else {
V_2 -> V_96 . V_97 = NULL ;
}
V_2 -> V_96 . V_142 = NULL ;
V_95 -> V_93 . V_143 = false ;
V_95 -> V_93 . V_107 = NULL ;
V_76 = F_33 ( V_71 , V_2 , F_40 ) ;
if ( F_13 ( V_76 != 0 ) )
goto V_127;
V_109 = F_58 ( & V_2 -> V_22 ) ;
V_76 = F_59 ( V_107 , & V_95 -> V_93 ,
V_112 -> V_143 , V_144 ,
& F_45 , NULL ) ;
if ( F_13 ( V_76 != 0 ) ) {
F_46 ( & V_109 ) ;
F_46 ( & V_22 ) ;
goto V_127;
}
V_113 -> V_15 = V_95 -> V_93 . V_145 . V_146 ;
F_46 ( & V_22 ) ;
F_60 ( & V_118 -> V_125 ) ;
return 0 ;
V_135:
F_41 ( V_2 -> V_42 ) ;
V_132:
F_41 ( V_2 -> V_30 ) ;
V_131:
F_42 ( V_95 , V_93 ) ;
V_129:
F_43 ( F_44 ( V_71 ) , V_13 ) ;
V_127:
F_60 ( & V_118 -> V_125 ) ;
return V_76 ;
}
int F_61 ( struct V_99 * V_100 , void * V_101 ,
struct V_102 * V_103 )
{
union V_147 * V_105 =
(union V_147 * ) V_101 ;
struct V_104 * V_112 = & V_105 -> V_112 ;
struct V_111 * V_113 = & V_105 -> V_113 ;
struct V_106 * V_107 = F_48 ( V_103 ) -> V_107 ;
struct V_1 * V_2 ;
struct V_94 * V_95 ;
struct V_16 T_8 * V_114 ;
struct V_92 * V_93 ;
int V_76 = - V_122 ;
V_93 = F_62 ( V_107 , V_112 -> V_15 ) ;
if ( F_13 ( V_93 == NULL ) ) {
F_14 ( L_11 ) ;
return - V_122 ;
}
if ( F_13 ( V_93 -> V_148 != V_144 ) )
goto V_149;
V_95 = F_39 ( V_93 , struct V_94 , V_93 ) ;
V_2 = & V_95 -> V_2 ;
V_76 = F_63 ( V_107 , & V_95 -> V_93 , V_108 , NULL ) ;
if ( F_13 ( V_76 != 0 ) ) {
F_14 ( L_12 ) ;
goto V_150;
}
V_113 -> V_24 = V_2 -> V_24 ;
V_113 -> V_25 = V_2 -> V_25 ;
memcpy ( V_113 -> V_29 , V_2 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
V_114 = (struct V_16 T_8 * ) ( unsigned long )
V_113 -> V_133 ;
if ( V_114 )
V_76 = F_64 ( V_114 , V_2 -> V_30 ,
V_2 -> V_3 * sizeof( * V_2 -> V_30 ) ) ;
if ( F_13 ( V_76 != 0 ) ) {
F_14 ( L_13 ,
V_114 , V_2 -> V_3 ) ;
V_76 = - V_134 ;
}
V_149:
V_150:
F_65 ( & V_93 ) ;
return V_76 ;
}
