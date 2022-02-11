char * F_1 ( enum V_1 V_2 )
{
int V_3 = V_2 - V_4 ;
char * V_5 ;
if ( V_3 < 0 || V_3 >= F_2 ( V_6 ) )
return L_1 ;
V_5 = V_6 [ V_3 ] ;
if ( ! * V_5 )
return L_1 ;
return V_5 ;
}
void F_3 ( struct V_7 * V_8 , int V_9 )
{
V_8 -> V_10 = V_9 ;
}
int F_4 ( struct V_7 * V_8 , int V_11 )
{
if ( V_11 >= 0 )
V_8 -> V_12 = V_11 ;
return V_8 -> V_12 ;
}
int F_5 ( struct V_7 * V_8 )
{
return V_8 -> V_10 ;
}
static struct V_13 * F_6 ( char * V_14 )
{
struct V_13 * V_15 ;
struct V_16 * V_17 ;
F_7 ( & V_18 ) ;
for ( V_17 = V_19 . V_17 ;
V_17 != & V_19 ;
V_17 = V_17 -> V_17 ) {
V_15 = (struct V_13 * ) V_17 ;
if ( ! strcmp ( V_15 -> V_14 , V_14 ) ) {
F_8 ( & V_18 ) ;
return V_15 ;
}
}
V_15 = F_9 ( sizeof( struct V_13 ) , V_20 ) ;
if ( V_15 ) {
V_15 -> V_21 = V_22 ;
strcpy ( V_15 -> V_14 , V_14 ) ;
F_10 ( & V_15 -> V_15 , & V_19 ) ;
} else
F_11 ( L_2 ) ;
F_8 ( & V_18 ) ;
return V_15 ;
}
int F_12 ( char * V_14 )
{
struct V_13 * V_15 ;
V_15 = F_6 ( V_14 ) ;
if ( V_15 )
return V_15 -> V_21 ;
else
F_11 ( L_3 ) ;
return V_22 ;
}
static enum V_23 F_13 ( char * V_14 )
{
struct V_13 * V_15 ;
V_15 = F_6 ( V_14 ) ;
if ( V_15 )
return V_15 -> type ;
else
F_11 ( L_3 ) ;
return - V_24 ;
}
static void F_14 ( char * V_14 , int V_21 )
{
struct V_13 * V_15 ;
V_15 = F_6 ( V_14 ) ;
if ( V_15 )
V_15 -> V_21 = V_21 ;
else
F_11 ( L_3 ) ;
}
static void F_15 ( char * V_14 ,
enum V_23 type )
{
struct V_13 * V_15 ;
V_15 = F_6 ( V_14 ) ;
if ( V_15 )
V_15 -> type = type ;
else
F_11 ( L_3 ) ;
}
static void F_16 ( struct V_16 * V_25 , struct V_16 * V_26 ,
T_1 * V_27 )
{
unsigned long V_28 ;
F_17 ( V_27 , V_28 ) ;
F_10 ( V_25 , V_26 ) ;
F_18 ( V_27 , V_28 ) ;
}
int F_19 ( T_2 V_29 )
{
struct V_30 * V_31 ;
struct V_16 * V_17 , * V_32 ;
int V_33 = 0 ;
F_7 ( & V_34 ) ;
V_31 = F_9 ( sizeof( struct V_30 ) ,
V_20 ) ;
if ( V_31 ) {
V_32 = & V_35 ;
for ( V_17 = V_32 -> V_17 ;
V_17 != V_32 && ! V_33 ;
V_17 = V_17 -> V_17 ) {
struct V_7 * V_36 =
(struct V_7 * ) V_17 ;
V_33 = V_29 ( V_36 , V_36 -> V_37 , 1 ) ;
}
if ( V_33 >= 0 ) {
V_31 -> V_29 = V_29 ;
F_10 ( & V_31 -> V_15 , & V_38 ) ;
} else
F_20 ( V_31 ) ;
} else
V_33 = - V_39 ;
F_8 ( & V_34 ) ;
return V_33 ;
}
void F_21 ( T_2 V_29 )
{
struct V_16 * V_17 , * V_32 ;
F_7 ( & V_34 ) ;
V_32 = & V_38 ;
for ( V_17 = V_32 -> V_17 ; V_17 != V_32 ; ) {
struct V_30 * V_31 =
(struct V_30 * ) V_17 ;
V_17 = V_17 -> V_17 ;
if ( V_31 -> V_29 == V_29 ) {
F_22 ( & V_31 -> V_15 ) ;
F_20 ( V_31 ) ;
}
}
F_8 ( & V_34 ) ;
}
static void F_23 ( struct V_7 * V_36 )
{
struct V_40 * V_41 ;
while ( ! F_24 ( & V_36 -> V_42 ) ) {
V_41 = (struct V_40 * ) V_36 -> V_42 . V_17 ;
V_41 -> V_43 ( V_41 -> V_44 ) ;
}
}
static int F_25 ( struct V_7 * V_36 ,
struct V_37 * V_37 , int V_45 )
{
struct V_30 * V_46 ;
int V_33 = 0 ;
F_26 (elem, &g_smscore_notifyees, entry) {
V_33 = V_46 -> V_29 ( V_36 , V_37 , V_45 ) ;
if ( V_33 < 0 )
break;
}
return V_33 ;
}
static struct
V_47 * F_27 ( T_3 * V_48 , void * V_49 ,
T_4 V_50 )
{
struct V_47 * V_51 ;
V_51 = F_28 ( sizeof( struct V_47 ) , V_20 ) ;
if ( ! V_51 ) {
F_29 ( L_4 ) ;
return NULL ;
}
V_51 -> V_52 = V_48 ;
V_51 -> V_53 = V_48 - ( T_3 * ) V_49 ;
V_51 -> V_54 = V_50 + V_51 -> V_53 ;
return V_51 ;
}
int F_30 ( struct V_55 * V_56 ,
struct V_7 * * V_36 )
{
struct V_7 * V_57 ;
T_3 * V_48 ;
V_57 = F_28 ( sizeof( struct V_7 ) , V_20 ) ;
if ( ! V_57 ) {
F_29 ( L_4 ) ;
return - V_39 ;
}
F_31 ( & V_57 -> V_15 ) ;
F_31 ( & V_57 -> V_42 ) ;
F_31 ( & V_57 -> V_58 ) ;
F_32 ( & V_57 -> V_59 ) ;
F_32 ( & V_57 -> V_60 ) ;
F_33 ( & V_57 -> V_61 ) ;
F_33 ( & V_57 -> V_62 ) ;
F_33 ( & V_57 -> V_63 ) ;
F_33 ( & V_57 -> V_64 ) ;
F_33 ( & V_57 -> V_65 ) ;
F_33 ( & V_57 -> V_66 ) ;
F_33 ( & V_57 -> V_67 ) ;
F_33 ( & V_57 -> V_68 ) ;
F_33 ( & V_57 -> V_69 ) ;
F_33 ( & V_57 -> V_70 ) ;
F_33 ( & V_57 -> V_71 ) ;
F_34 ( & V_57 -> V_72 ) ;
V_57 -> V_73 = V_56 -> V_74 * V_56 -> V_75 ;
V_57 -> V_49 = F_35 ( NULL , V_57 -> V_73 ,
& V_57 -> V_50 ,
V_20 | V_76 ) ;
if ( ! V_57 -> V_49 ) {
F_36 ( V_57 ) ;
return - V_39 ;
}
for ( V_48 = V_57 -> V_49 ;
V_57 -> V_75 < V_56 -> V_75 ;
V_57 -> V_75 ++ , V_48 += V_56 -> V_74 ) {
struct V_47 * V_51 ;
V_51 = F_27 ( V_48 , V_57 -> V_49 ,
V_57 -> V_50 ) ;
if ( ! V_51 ) {
F_36 ( V_57 ) ;
return - V_39 ;
}
F_37 ( V_57 , V_51 ) ;
}
F_29 ( L_5 , V_57 -> V_75 ) ;
V_57 -> V_21 = V_77 ;
V_57 -> V_10 = V_78 ;
V_57 -> V_44 = V_56 -> V_44 ;
V_57 -> V_37 = V_56 -> V_37 ;
V_57 -> V_79 = V_56 -> V_79 ;
V_57 -> V_80 = V_56 -> V_80 ;
V_57 -> V_81 = V_56 -> V_81 ;
V_57 -> V_82 = V_56 -> V_82 ;
V_57 -> V_83 = V_56 -> V_83 ;
V_57 -> V_84 = V_56 -> V_28 ;
strcpy ( V_57 -> V_14 , V_56 -> V_14 ) ;
F_15 ( V_57 -> V_14 , V_56 -> V_85 ) ;
F_7 ( & V_34 ) ;
F_10 ( & V_57 -> V_15 , & V_35 ) ;
F_8 ( & V_34 ) ;
* V_36 = V_57 ;
F_29 ( L_6 , V_57 ) ;
return 0 ;
}
static int F_38 ( struct V_7 * V_36 ,
void * V_48 , T_5 V_86 , struct V_87 * V_87 ) {
int V_33 ;
if ( V_87 == NULL )
return - V_24 ;
F_33 ( V_87 ) ;
V_33 = V_36 -> V_81 ( V_36 -> V_44 , V_48 , V_86 ) ;
if ( V_33 < 0 ) {
F_29 ( L_7 , V_33 ) ;
return V_33 ;
}
return F_39 ( V_87 ,
F_40 ( V_88 ) ) ?
0 : - V_89 ;
}
static int F_41 ( struct V_7 * V_36 )
{
int V_90 ;
int V_33 ;
void * V_48 ;
V_36 -> V_91 . V_57 = NULL ;
V_90 = F_42 ( F_5 ( V_36 ) ) -> V_92 . V_91 ;
if ( V_90 ) {
F_29 ( L_8 ) ;
V_33 = F_43 ( V_36 ) ;
if ( V_33 != 0 )
F_11 ( L_9 ) ;
else {
V_48 = F_9 ( sizeof( struct V_93 ) +
V_94 ,
V_20 | V_76 ) ;
if ( V_48 ) {
struct V_93 * V_5 =
(struct V_93 * )
F_44 ( V_48 ) ;
F_45 ( & V_5 -> V_95 ,
V_96 ,
sizeof( struct V_93 ) ) ;
V_5 -> V_97 [ 0 ] = V_36 -> V_91 . V_98 ;
V_5 -> V_97 [ 1 ] = V_36 -> V_91 . V_99 ;
V_33 = F_38 ( V_36 , V_5 ,
V_5 -> V_95 . V_100 ,
& V_36 -> V_71 ) ;
F_20 ( V_48 ) ;
} else
F_11
( L_10 ) ;
}
} else
F_29 ( L_11 ) ;
return 0 ;
}
static int F_46 ( struct V_7 * V_36 )
{
struct V_101 * V_102 ;
V_102 = F_42 ( V_36 -> V_10 ) ;
if ( ! V_102 ) {
F_11 ( L_12 ) ;
return - V_24 ;
}
if ( V_102 -> V_103 ) {
struct V_104 V_105 ;
F_47 ( L_13 , V_102 -> V_103 ) ;
V_105 . V_95 . V_106 = 0 ;
V_105 . V_95 . V_107 = V_108 ;
V_105 . V_95 . V_109 = 0 ;
V_105 . V_95 . V_110 = V_111 ;
V_105 . V_95 . V_100 = sizeof( V_105 ) ;
V_105 . V_97 [ 0 ] = V_102 -> V_103 ;
V_36 -> V_81 ( V_36 -> V_44 , & V_105 ,
sizeof( V_105 ) ) ;
}
if ( V_102 -> V_112 ) {
struct V_104 V_113 ;
F_47 ( L_14 , V_102 -> V_112 ) ;
F_45 ( & V_113 . V_95 ,
V_114 ,
sizeof( V_113 ) ) ;
V_113 . V_97 [ 0 ] = V_102 -> V_112 ;
V_36 -> V_81 ( V_36 -> V_44 , & V_113 ,
sizeof( V_113 ) ) ;
}
return 0 ;
}
int F_48 ( struct V_7 * V_36 )
{
int V_33 ;
int V_10 = F_5 ( V_36 ) ;
int V_21 = F_12 ( V_36 -> V_14 ) ;
if ( V_10 != V_78 && V_21 == V_77 )
V_21 = F_42 ( V_10 ) -> V_22 ;
V_33 = F_49 ( V_36 , V_21 ) ;
if ( V_33 < 0 ) {
F_29 ( L_15 , V_33 ) ;
return V_33 ;
}
V_33 = F_46 ( V_36 ) ;
if ( V_33 < 0 ) {
F_29 ( L_16 , V_33 ) ;
return V_33 ;
}
F_7 ( & V_34 ) ;
V_33 = F_25 ( V_36 , V_36 -> V_37 , 1 ) ;
F_41 ( V_36 ) ;
F_29 ( L_17 , V_36 , V_33 ) ;
F_8 ( & V_34 ) ;
return V_33 ;
}
static int F_50 ( struct V_7 * V_36 ,
void * V_48 , T_5 V_86 )
{
struct V_115 * V_116 = (struct V_115 * ) V_48 ;
struct V_117 * V_5 ;
T_6 V_118 , V_119 = 0 ;
T_6 V_3 , * V_120 ;
T_3 * V_121 = V_116 -> V_121 ;
int V_33 = 0 ;
V_116 -> V_122 = F_51 ( ( V_123 * ) & V_116 -> V_122 ) ;
V_116 -> V_124 = F_51 ( ( V_123 * ) & V_116 -> V_124 ) ;
V_118 = V_116 -> V_122 ;
F_29 ( L_18 ,
V_118 , V_116 -> V_124 ) ;
if ( V_36 -> V_82 ) {
V_33 = V_36 -> V_82 ( V_36 -> V_44 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_5 = F_9 ( V_125 , V_20 | V_76 ) ;
if ( ! V_5 )
return - V_39 ;
if ( V_36 -> V_21 != V_77 ) {
F_47 ( L_19 ) ;
F_45 ( & V_5 -> V_95 , V_126 ,
sizeof( struct V_127 ) ) ;
V_33 = F_38 ( V_36 , V_5 ,
V_5 -> V_95 . V_100 ,
& V_36 -> V_66 ) ;
if ( V_33 < 0 ) {
F_11 ( L_20 , V_33 ) ;
goto V_128;
}
V_118 = * ( T_6 * ) & V_121 [ 20 ] ;
}
for ( V_3 = 0 , V_120 = ( T_6 * ) V_116 -> V_121 ; V_3 < V_116 -> V_124 / 4 ;
V_3 ++ , V_120 ++ )
V_119 += * V_120 ;
while ( V_86 && V_33 >= 0 ) {
struct V_129 * V_130 =
(struct V_129 * ) V_5 ;
int V_131 = F_52 ( int , V_86 , V_132 ) ;
F_45 ( & V_5 -> V_95 , V_133 ,
( V_134 ) ( sizeof( struct V_127 ) +
sizeof( T_6 ) + V_131 ) ) ;
V_130 -> V_135 = V_118 ;
memcpy ( V_130 -> V_121 , V_121 , V_131 ) ;
V_33 = F_38 ( V_36 , V_130 ,
V_130 -> V_95 . V_100 ,
& V_36 -> V_62 ) ;
V_121 += V_131 ;
V_86 -= V_131 ;
V_118 += V_131 ;
}
if ( V_33 < 0 )
goto V_128;
F_47 ( L_21 ,
V_119 ) ;
F_45 ( & V_5 -> V_95 , V_136 ,
sizeof( V_5 -> V_95 ) +
sizeof( T_6 ) * 3 ) ;
V_5 -> V_97 [ 0 ] = V_116 -> V_122 ;
V_5 -> V_97 [ 1 ] = V_116 -> V_124 ;
V_5 -> V_97 [ 2 ] = 0 ;
V_33 = F_38 ( V_36 , V_5 ,
V_5 -> V_95 . V_100 ,
& V_36 -> V_63 ) ;
if ( V_33 < 0 )
goto V_128;
if ( V_36 -> V_21 == V_77 ) {
struct V_104 * V_137 =
(struct V_104 * ) V_5 ;
F_47 ( L_22 ) ;
F_45 ( & V_5 -> V_95 ,
V_138 ,
sizeof( struct V_127 ) +
sizeof( T_6 ) * 5 ) ;
V_137 -> V_97 [ 0 ] = V_116 -> V_122 ;
V_137 -> V_97 [ 1 ] = 6 ;
V_137 -> V_97 [ 2 ] = 0x200 ;
V_137 -> V_97 [ 3 ] = 0 ;
V_137 -> V_97 [ 4 ] = 4 ;
V_33 = F_38 ( V_36 , V_137 ,
V_137 -> V_95 . V_100 ,
& V_36 -> V_64 ) ;
} else {
F_45 ( & V_5 -> V_95 , V_139 ,
sizeof( struct V_127 ) ) ;
V_33 = V_36 -> V_81 ( V_36 -> V_44 , V_5 ,
V_5 -> V_95 . V_100 ) ;
}
if ( V_33 < 0 )
goto V_128;
F_53 ( 400 ) ;
V_128:
F_20 ( V_5 ) ;
if ( V_36 -> V_83 ) {
F_47 ( L_23 , V_33 , V_36 -> V_83 ) ;
if ( V_33 >= 0 )
return V_36 -> V_83 ( V_36 -> V_44 ) ;
}
F_47 ( L_24 , V_33 ) ;
return V_33 ;
}
static char * F_54 ( struct V_7 * V_36 ,
int V_21 )
{
char * * V_140 ;
int V_10 = F_5 ( V_36 ) ;
enum V_23 type ;
type = F_13 ( V_36 -> V_14 ) ;
if ( type <= V_141 || type >= V_142 )
return NULL ;
if ( V_21 <= V_77 || V_21 >= V_143 )
return NULL ;
F_47 ( L_25 ,
V_10 , V_21 ) ;
V_140 = F_42 ( V_10 ) -> V_140 ;
if ( ! V_140 || ! V_140 [ V_21 ] ) {
F_47 ( L_26 ,
V_21 , type ) ;
return V_144 [ type ] [ V_21 ] ;
}
return V_140 [ V_21 ] ;
}
static int F_55 ( struct V_7 * V_36 ,
int V_21 ,
T_7 V_145 )
{
int V_33 = - V_146 ;
T_3 * V_147 ;
T_6 V_148 ;
const struct V_116 * V_140 ;
char * V_149 = F_54 ( V_36 , V_21 ) ;
if ( ! V_149 ) {
F_11 ( L_27 , V_21 ) ;
return - V_146 ;
}
F_47 ( L_28 , V_149 ) ;
if ( V_145 == NULL && ! ( V_36 -> V_84
& V_150 ) )
return - V_24 ;
V_33 = F_56 ( & V_140 , V_149 , V_36 -> V_37 ) ;
if ( V_33 < 0 ) {
F_11 ( L_29 , V_149 ) ;
return V_33 ;
}
F_29 ( L_30 , V_149 , V_140 -> V_86 ) ;
V_147 = F_9 ( F_57 ( V_140 -> V_86 , V_151 ) ,
V_20 | V_76 ) ;
if ( ! V_147 ) {
F_11 ( L_31 ) ;
V_33 = - V_39 ;
} else {
memcpy ( V_147 , V_140 -> V_152 , V_140 -> V_86 ) ;
V_148 = V_140 -> V_86 ;
V_33 = ( V_36 -> V_84 & V_150 ) ?
F_50 ( V_36 , V_147 , V_148 )
: V_145 ( V_36 -> V_44 , V_147 ,
V_148 ) ;
}
F_20 ( V_147 ) ;
F_58 ( V_140 ) ;
return V_33 ;
}
void F_36 ( struct V_7 * V_36 )
{
struct V_47 * V_51 ;
int V_75 = 0 ;
int V_153 = 0 ;
F_7 ( & V_34 ) ;
F_59 ( V_36 ) ;
F_23 ( V_36 ) ;
F_25 ( V_36 , NULL , 0 ) ;
while ( 1 ) {
while ( ! F_24 ( & V_36 -> V_58 ) ) {
V_51 = (struct V_47 * ) V_36 -> V_58 . V_17 ;
F_22 ( & V_51 -> V_15 ) ;
F_20 ( V_51 ) ;
V_75 ++ ;
}
if ( V_75 == V_36 -> V_75 )
break;
if ( ++ V_153 > 10 ) {
F_29 ( L_32 ) ;
break;
}
F_29 ( L_33 ,
V_36 -> V_75 - V_75 ) ;
F_8 ( & V_34 ) ;
F_53 ( 100 ) ;
F_7 ( & V_34 ) ;
}
F_29 ( L_34 , V_75 ) ;
if ( V_36 -> V_49 )
F_60 ( NULL , V_36 -> V_73 ,
V_36 -> V_49 , V_36 -> V_50 ) ;
F_20 ( V_36 -> V_147 ) ;
F_22 ( & V_36 -> V_15 ) ;
F_20 ( V_36 ) ;
F_8 ( & V_34 ) ;
F_29 ( L_35 , V_36 ) ;
}
static int F_61 ( struct V_7 * V_36 )
{
void * V_48 = F_9 ( sizeof( struct V_127 ) + V_94 ,
V_20 | V_76 ) ;
struct V_127 * V_5 =
(struct V_127 * ) F_44 ( V_48 ) ;
int V_33 ;
if ( ! V_48 )
return - V_39 ;
F_45 ( V_5 , V_154 ,
sizeof( struct V_127 ) ) ;
V_33 = F_38 ( V_36 , V_5 , V_5 -> V_100 ,
& V_36 -> V_61 ) ;
if ( V_33 == - V_89 ) {
F_11 ( L_36 ) ;
if ( F_39 ( & V_36 -> V_67 ,
F_40 ( 5000 ) ) ) {
V_33 = F_38 (
V_36 , V_5 , V_5 -> V_100 ,
& V_36 -> V_61 ) ;
if ( V_33 < 0 )
F_11 ( L_37 ,
V_33 ) ;
} else
V_33 = - V_89 ;
}
F_20 ( V_48 ) ;
return V_33 ;
}
static int F_62 ( struct V_7 * V_36 , int V_21 )
{
void * V_48 ;
struct V_104 * V_5 ;
int V_33 = 0 ;
V_48 = F_9 ( sizeof( struct V_104 ) +
V_94 , V_20 | V_76 ) ;
if ( ! V_48 ) {
F_11 ( L_38 ) ;
return - V_39 ;
}
V_5 = (struct V_104 * ) F_44 ( V_48 ) ;
F_45 ( & V_5 -> V_95 , V_155 ,
sizeof( struct V_104 ) ) ;
V_5 -> V_97 [ 0 ] = V_21 ;
V_33 = F_38 ( V_36 , V_5 ,
V_5 -> V_95 . V_100 ,
& V_36 -> V_65 ) ;
F_20 ( V_48 ) ;
return V_33 ;
}
int F_49 ( struct V_7 * V_36 , int V_21 )
{
int V_33 = 0 ;
F_47 ( L_39 , V_21 ) ;
if ( V_36 -> V_84 & V_150 ) {
if ( V_21 <= V_77 || V_21 >= V_143 ) {
F_11 ( L_40 , V_21 ) ;
return - V_24 ;
}
F_14 ( V_36 -> V_14 , V_21 ) ;
if ( ! ( V_36 -> V_84 & V_156 ) ) {
V_33 = F_61 ( V_36 ) ;
if ( V_33 < 0 ) {
F_11 ( L_41 , V_33 ) ;
return V_33 ;
}
}
if ( V_36 -> V_21 == V_21 ) {
F_29 ( L_42 , V_21 ) ;
return 0 ;
}
if ( ! ( V_36 -> V_157 & ( 1 << V_21 ) ) ) {
V_33 = F_55 ( V_36 ,
V_21 , NULL ) ;
if ( V_33 >= 0 )
F_29 ( L_43 ) ;
} else {
F_29 ( L_44 ,
V_21 ) ;
}
if ( V_36 -> V_158 >= 0x800 ) {
V_33 = F_62 ( V_36 , V_21 ) ;
if ( V_33 < 0 )
F_11 ( L_45 , V_33 ) ;
}
} else {
if ( V_21 <= V_77 || V_21 >= V_143 ) {
F_11 ( L_40 , V_21 ) ;
return - V_24 ;
}
F_14 ( V_36 -> V_14 , V_21 ) ;
if ( V_36 -> V_80 )
V_36 -> V_80 ( V_36 -> V_44 ,
& V_36 -> V_21 ) ;
if ( V_36 -> V_21 != V_21 && V_36 -> V_79 )
V_33 = V_36 -> V_79 ( V_36 -> V_44 , V_21 ) ;
}
if ( V_33 >= 0 ) {
char * V_48 ;
V_36 -> V_21 = V_21 ;
V_36 -> V_84 &= ~ V_156 ;
V_48 = F_9 ( sizeof( struct V_104 ) +
V_94 , V_20 | V_76 ) ;
if ( V_48 ) {
struct V_104 * V_5 = (struct V_104 * ) F_44 ( V_48 ) ;
F_45 ( & V_5 -> V_95 , V_155 ,
sizeof( struct V_104 ) ) ;
V_5 -> V_97 [ 0 ] = V_21 ;
V_33 = F_38 (
V_36 , V_5 , V_5 -> V_95 . V_100 ,
& V_36 -> V_65 ) ;
F_20 ( V_48 ) ;
}
}
if ( V_33 < 0 )
F_11 ( L_46 , V_33 ) ;
else
F_47 ( L_47 ) ;
return V_33 ;
}
int F_63 ( struct V_7 * V_36 )
{
return V_36 -> V_21 ;
}
static struct
V_40 * F_64 ( struct V_7 * V_36 ,
int V_159 , int V_9 )
{
struct V_16 * V_32 ;
struct V_40 * V_41 ;
unsigned long V_28 ;
struct V_16 * V_160 ;
struct V_161 * V_162 ;
F_17 ( & V_36 -> V_59 , V_28 ) ;
V_32 = & V_36 -> V_42 ;
F_26 (client, first, entry) {
V_160 = & V_41 -> V_163 ;
F_26 (client_id, firstid, entry) {
if ( ( V_162 -> V_9 == V_9 ) &&
( V_162 -> V_159 == V_159 ||
( V_162 -> V_159 == 0 ) ) )
goto V_164;
}
}
V_41 = NULL ;
V_164:
F_18 ( & V_36 -> V_59 , V_28 ) ;
return V_41 ;
}
void F_65 ( struct V_7 * V_36 ,
struct V_47 * V_51 ) {
struct V_127 * V_165 = (struct V_127 * ) ( ( T_3 * ) V_51 -> V_52
+ V_51 -> V_166 ) ;
struct V_40 * V_41 ;
int V_33 = - V_167 ;
static unsigned long V_168 ;
static int V_169 ;
unsigned long V_170 = F_66 ( V_171 ) ;
if ( ! V_168 )
V_168 = V_170 ;
if ( V_170 - V_168 > 10000 ) {
F_47 ( L_48 ,
( int ) ( ( V_169 * 1000 ) /
( V_170 - V_168 ) ) ) ;
V_168 = V_170 ;
V_169 = 0 ;
}
V_169 += V_51 -> V_86 ;
if ( ( V_165 -> V_110 == V_172 ) ||
( V_165 -> V_110 == V_173 ) ) {
if ( V_36 -> V_21 == V_174 )
V_165 -> V_107 = V_175 ;
}
V_41 = F_64 ( V_36 , V_165 -> V_110 , V_165 -> V_107 ) ;
if ( V_41 )
V_33 = V_41 -> V_176 ( V_41 -> V_44 , V_51 ) ;
if ( V_33 < 0 ) {
switch ( V_165 -> V_110 ) {
case V_177 :
break;
case V_178 :
break;
case V_179 :
break;
case V_180 :
break;
case V_181 :
break;
case V_182 :
break;
case V_183 :
break;
case V_184 :
{
struct V_185 * V_186 =
(struct V_185 * ) V_165 ;
F_47 ( L_49 ,
V_186 -> V_187 , V_186 -> V_188 ,
V_186 -> V_189 , V_186 -> V_190 ) ;
V_36 -> V_21 = V_186 -> V_187 == 255 ?
V_77 : V_186 -> V_187 ;
V_36 -> V_157 = V_186 -> V_188 ;
V_36 -> V_158 = V_186 -> V_189 << 8 |
V_186 -> V_190 ;
F_67 ( & V_36 -> V_61 ) ;
break;
}
case V_191 :
F_67 ( & V_36 -> V_65 ) ;
break;
case V_192 :
F_67 ( & V_36 -> V_66 ) ;
break;
case V_193 :
{
struct V_104 * V_194 = (struct V_104 * ) V_165 ;
F_47 ( L_50 ,
V_194 -> V_97 [ 0 ] ) ;
F_67 ( & V_36 -> V_63 ) ;
break;
}
case V_195 :
F_67 ( & V_36 -> V_62 ) ;
break;
case V_196 :
break;
case V_197 :
F_67 ( & V_36 -> V_64 ) ;
break;
case V_198 :
F_67 ( & V_36 -> V_67 ) ;
break;
case V_199 :
F_67 ( & V_36 -> V_68 ) ;
break;
case V_200 :
F_67 ( & V_36 -> V_69 ) ;
break;
case V_201 :
{
T_6 * V_202 = ( T_6 * ) V_165 ;
V_36 -> V_203 = V_202 [ 1 ] ;
F_47 ( L_51 ,
V_36 -> V_203 ) ;
F_67 ( & V_36 -> V_70 ) ;
break;
}
case V_204 :
F_67 ( & V_36 -> V_71 ) ;
break;
case V_205 :
F_68 ( V_36 ,
( const char * )
( ( char * ) V_165
+ sizeof( struct V_127 ) ) ,
( int ) V_165 -> V_100
- sizeof( struct V_127 ) ) ;
break;
case V_206 :
break;
default:
F_47 ( L_52 ,
F_1 ( V_165 -> V_110 ) ,
V_165 -> V_110 ) ;
break;
}
F_37 ( V_36 , V_51 ) ;
}
}
static struct V_47 * F_69 ( struct V_7 * V_36 )
{
struct V_47 * V_51 = NULL ;
unsigned long V_28 ;
F_17 ( & V_36 -> V_60 , V_28 ) ;
if ( ! F_24 ( & V_36 -> V_58 ) ) {
V_51 = (struct V_47 * ) V_36 -> V_58 . V_17 ;
F_22 ( & V_51 -> V_15 ) ;
}
F_18 ( & V_36 -> V_60 , V_28 ) ;
return V_51 ;
}
struct V_47 * F_70 ( struct V_7 * V_36 )
{
struct V_47 * V_51 = NULL ;
F_71 ( V_36 -> V_72 , ( V_51 = F_69 ( V_36 ) ) ) ;
return V_51 ;
}
void F_37 ( struct V_7 * V_36 ,
struct V_47 * V_51 ) {
F_72 ( & V_36 -> V_72 ) ;
F_16 ( & V_51 -> V_15 , & V_36 -> V_58 , & V_36 -> V_60 ) ;
}
static int F_73 ( struct V_7 * V_36 ,
struct V_40 * V_41 ,
int V_159 , int V_9 )
{
struct V_161 * V_207 ;
struct V_40 * V_208 ;
if ( ! V_41 ) {
F_11 ( L_53 ) ;
return - V_24 ;
}
V_208 = F_64 ( V_36 , V_159 , V_9 ) ;
if ( V_208 == V_41 )
return 0 ;
if ( V_208 ) {
F_11 ( L_54 ) ;
return - V_209 ;
}
V_207 = F_28 ( sizeof( struct V_161 ) , V_20 ) ;
if ( ! V_207 ) {
F_11 ( L_55 ) ;
return - V_39 ;
}
V_207 -> V_9 = V_9 ;
V_207 -> V_159 = V_159 ;
F_16 ( & V_207 -> V_15 , & V_41 -> V_163 ,
& V_36 -> V_59 ) ;
return 0 ;
}
int F_74 ( struct V_7 * V_36 ,
struct V_210 * V_56 ,
struct V_40 * * V_41 )
{
struct V_40 * V_211 ;
if ( F_64 ( V_36 , V_56 -> V_159 ,
V_56 -> V_212 ) ) {
F_11 ( L_56 ) ;
return - V_209 ;
}
V_211 = F_28 ( sizeof( struct V_40 ) , V_20 ) ;
if ( ! V_211 ) {
F_11 ( L_57 ) ;
return - V_39 ;
}
F_31 ( & V_211 -> V_163 ) ;
V_211 -> V_36 = V_36 ;
V_211 -> V_176 = V_56 -> V_176 ;
V_211 -> V_43 = V_56 -> V_43 ;
V_211 -> V_44 = V_56 -> V_44 ;
F_16 ( & V_211 -> V_15 , & V_36 -> V_42 ,
& V_36 -> V_59 ) ;
F_73 ( V_36 , V_211 , V_56 -> V_159 ,
V_56 -> V_212 ) ;
* V_41 = V_211 ;
F_47 ( L_58 , V_56 -> V_44 , V_56 -> V_159 ,
V_56 -> V_212 ) ;
return 0 ;
}
void F_75 ( struct V_40 * V_41 )
{
struct V_7 * V_36 = V_41 -> V_36 ;
unsigned long V_28 ;
F_17 ( & V_36 -> V_59 , V_28 ) ;
while ( ! F_24 ( & V_41 -> V_163 ) ) {
struct V_161 * V_213 =
(struct V_161 * ) V_41 -> V_163 . V_17 ;
F_22 ( & V_213 -> V_15 ) ;
F_20 ( V_213 ) ;
}
F_29 ( L_59 , V_41 -> V_44 ) ;
F_22 ( & V_41 -> V_15 ) ;
F_20 ( V_41 ) ;
F_18 ( & V_36 -> V_59 , V_28 ) ;
}
int F_76 ( struct V_40 * V_41 ,
void * V_48 , T_5 V_86 )
{
struct V_7 * V_36 ;
struct V_127 * V_165 = (struct V_127 * ) V_48 ;
int V_33 ;
if ( V_41 == NULL ) {
F_11 ( L_60 ) ;
return - V_24 ;
}
V_36 = V_41 -> V_36 ;
if ( V_36 == NULL ) {
F_11 ( L_61 ) ;
return - V_24 ;
}
V_33 = F_73 ( V_41 -> V_36 , V_41 , 0 ,
V_165 -> V_106 ) ;
if ( V_33 < 0 )
return V_33 ;
return V_36 -> V_81 ( V_36 -> V_44 , V_48 , V_86 ) ;
}
int F_77 ( struct V_7 * V_36 , T_6 V_214 ,
struct V_215 * V_216 )
{
struct {
struct V_127 V_217 ;
T_6 V_152 [ 6 ] ;
} V_5 ;
if ( V_36 -> V_84 & V_150 ) {
V_5 . V_217 . V_106 = V_175 ;
V_5 . V_217 . V_107 = V_108 ;
V_5 . V_217 . V_109 = 0 ;
V_5 . V_217 . V_110 = V_218 ;
V_5 . V_217 . V_100 = sizeof( V_5 ) ;
V_5 . V_152 [ 0 ] = V_214 ;
V_5 . V_152 [ 1 ] = V_216 -> V_219 ;
V_5 . V_152 [ 2 ] = V_216 -> V_220 == 0 ? 3 : 0 ;
switch ( V_216 -> V_221 ) {
case V_222 :
V_5 . V_152 [ 3 ] = 7 ;
break;
case V_223 :
V_5 . V_152 [ 3 ] = 5 ;
break;
case V_224 :
V_5 . V_152 [ 3 ] = 3 ;
break;
case V_225 :
default:
V_5 . V_152 [ 3 ] = 2 ;
break;
}
V_5 . V_152 [ 4 ] = V_216 -> V_226 ;
V_5 . V_152 [ 5 ] = 0 ;
} else
return - V_24 ;
return V_36 -> V_81 ( V_36 -> V_44 ,
& V_5 , sizeof( V_5 ) ) ;
}
int F_78 ( struct V_7 * V_36 , T_6 V_214 , int V_227 )
{
struct {
struct V_127 V_217 ;
T_6 V_152 [ 3 ] ;
} V_5 ;
if ( V_214 > V_228 )
return - V_24 ;
V_5 . V_217 . V_106 = V_175 ;
V_5 . V_217 . V_107 = V_108 ;
V_5 . V_217 . V_109 = 0 ;
V_5 . V_217 . V_110 = V_229 ;
V_5 . V_217 . V_100 = sizeof( V_5 ) ;
V_5 . V_152 [ 0 ] = V_214 ;
V_5 . V_152 [ 1 ] = V_227 ? 1 : 0 ;
V_5 . V_152 [ 2 ] = 0 ;
return V_36 -> V_81 ( V_36 -> V_44 ,
& V_5 , sizeof( V_5 ) ) ;
}
static int F_79 ( T_6 V_230 , T_6 * V_231 ,
T_6 * V_232 , T_6 * V_233 ) {
* V_233 = 1 ;
if ( V_230 <= 1 ) {
* V_231 = 0 ;
* V_232 = 9 ;
* V_233 = 2 ;
} else if ( V_230 >= 2 && V_230 <= 6 ) {
* V_231 = 2 ;
* V_232 = 0 ;
* V_233 = 2 ;
} else if ( V_230 >= 7 && V_230 <= 11 ) {
* V_231 = 7 ;
* V_232 = 1 ;
} else if ( V_230 >= 12 && V_230 <= 15 ) {
* V_231 = 12 ;
* V_232 = 2 ;
* V_233 = 3 ;
} else if ( V_230 == 16 ) {
* V_231 = 16 ;
* V_232 = 23 ;
} else if ( V_230 >= 17 && V_230 <= 24 ) {
* V_231 = 17 ;
* V_232 = 3 ;
} else if ( V_230 == 25 ) {
* V_231 = 25 ;
* V_232 = 6 ;
} else if ( V_230 >= 26 && V_230 <= 28 ) {
* V_231 = 26 ;
* V_232 = 4 ;
} else if ( V_230 == 29 ) {
* V_231 = 29 ;
* V_232 = 5 ;
* V_233 = 2 ;
} else if ( V_230 == 30 ) {
* V_231 = 30 ;
* V_232 = 8 ;
} else if ( V_230 == 31 ) {
* V_231 = 31 ;
* V_232 = 17 ;
} else
return - 1 ;
* V_233 <<= 24 ;
return 0 ;
}
int F_80 ( struct V_7 * V_36 , T_3 V_230 ,
struct V_215 * V_234 ) {
T_6 V_235 ;
T_6 V_236 = 0 ;
T_6 V_237 = 0 ;
T_6 V_238 ;
T_6 V_239 ;
void * V_48 ;
int V_33 ;
struct V_240 {
struct V_127 V_95 ;
T_6 V_97 [ 6 ] ;
} * V_241 ;
if ( V_230 > V_228 )
return - V_24 ;
if ( V_234 == NULL )
return - V_24 ;
V_235 = sizeof( struct V_127 ) + ( sizeof( T_6 ) * 6 ) ;
V_48 = F_9 ( V_235 + V_94 ,
V_20 | V_76 ) ;
if ( ! V_48 )
return - V_39 ;
V_241 = (struct V_240 * ) F_44 ( V_48 ) ;
V_241 -> V_95 . V_106 = V_175 ;
V_241 -> V_95 . V_107 = V_108 ;
V_241 -> V_95 . V_109 = 0 ;
V_241 -> V_95 . V_100 = ( V_134 ) V_235 ;
V_241 -> V_97 [ 0 ] = V_230 ;
if ( ! ( V_36 -> V_84 & V_150 ) ) {
V_241 -> V_95 . V_110 = V_242 ;
if ( F_79 ( V_230 , & V_236 , & V_237 ,
& V_239 ) != 0 ) {
V_33 = - V_24 ;
goto free;
}
V_241 -> V_97 [ 1 ] = V_236 ;
V_241 -> V_97 [ 2 ] = V_237 ;
V_238 = ( V_234 -> V_219 )
| ( V_234 -> V_243 << 2 )
| ( V_234 -> V_220 << 3 )
| ( V_234 -> V_221 << 4 ) ;
V_241 -> V_97 [ 3 ] = V_238 ;
V_241 -> V_97 [ 4 ] = V_234 -> V_226 ;
V_241 -> V_97 [ 5 ] = V_239 ;
} else {
V_241 -> V_95 . V_110 = V_218 ;
V_241 -> V_97 [ 1 ] = V_234 -> V_219 ;
V_241 -> V_97 [ 2 ] = V_234 -> V_220 ;
V_241 -> V_97 [ 3 ] = V_234 -> V_221 ;
V_241 -> V_97 [ 4 ] = V_234 -> V_226 ;
V_241 -> V_97 [ 5 ] = 0 ;
}
V_33 = F_38 ( V_36 , V_241 , V_235 ,
& V_36 -> V_68 ) ;
if ( V_33 != 0 ) {
if ( V_33 == - V_89 )
F_11 ( L_62 ) ;
else
F_11 ( L_63 ) ;
}
free:
F_20 ( V_48 ) ;
return V_33 ;
}
int F_81 ( struct V_7 * V_36 , T_3 V_230 ,
T_3 V_244 ) {
T_6 V_235 ;
int V_33 ;
void * V_48 ;
struct V_240 {
struct V_127 V_95 ;
T_6 V_97 [ 3 ] ;
} * V_241 ;
if ( ( V_244 > 1 ) || ( V_230 > V_228 ) )
return - V_24 ;
V_235 = sizeof( struct V_127 ) +
( 3 * sizeof( T_6 ) ) ;
V_48 = F_9 ( V_235 + V_94 ,
V_20 | V_76 ) ;
if ( ! V_48 )
return - V_39 ;
V_241 = (struct V_240 * ) F_44 ( V_48 ) ;
V_241 -> V_95 . V_106 = V_175 ;
V_241 -> V_95 . V_107 = V_108 ;
V_241 -> V_95 . V_109 = 0 ;
V_241 -> V_95 . V_110 = V_229 ;
V_241 -> V_95 . V_100 = ( V_134 ) V_235 ;
V_241 -> V_97 [ 0 ] = V_230 ;
V_241 -> V_97 [ 1 ] = V_244 ;
V_33 = F_38 ( V_36 , V_241 , V_235 ,
& V_36 -> V_69 ) ;
if ( V_33 != 0 ) {
if ( V_33 == - V_89 )
F_11 ( L_64 ) ;
else
F_11 ( L_65 ) ;
}
F_20 ( V_48 ) ;
return V_33 ;
}
int F_82 ( struct V_7 * V_36 , T_3 V_230 ,
T_3 * V_227 ) {
T_6 V_235 ;
int V_33 ;
void * V_48 ;
struct V_240 {
struct V_127 V_95 ;
T_6 V_97 [ 2 ] ;
} * V_241 ;
if ( V_230 > V_228 )
return - V_24 ;
V_235 = sizeof( struct V_127 ) + ( 2 * sizeof( T_6 ) ) ;
V_48 = F_9 ( V_235 + V_94 ,
V_20 | V_76 ) ;
if ( ! V_48 )
return - V_39 ;
V_241 = (struct V_240 * ) F_44 ( V_48 ) ;
V_241 -> V_95 . V_106 = V_175 ;
V_241 -> V_95 . V_107 = V_108 ;
V_241 -> V_95 . V_109 = 0 ;
V_241 -> V_95 . V_110 = V_245 ;
V_241 -> V_95 . V_100 = ( V_134 ) V_235 ;
V_241 -> V_97 [ 0 ] = V_230 ;
V_241 -> V_97 [ 1 ] = 0 ;
V_33 = F_38 ( V_36 , V_241 , V_235 ,
& V_36 -> V_70 ) ;
if ( V_33 != 0 ) {
if ( V_33 == - V_89 )
F_11 ( L_66 ) ;
else
F_11 ( L_67 ) ;
}
F_20 ( V_48 ) ;
* V_227 = V_36 -> V_203 ;
return V_33 ;
}
static int T_8 F_83 ( void )
{
int V_33 = 0 ;
F_31 ( & V_38 ) ;
F_31 ( & V_35 ) ;
F_84 ( & V_34 ) ;
F_31 ( & V_19 ) ;
F_84 ( & V_18 ) ;
return V_33 ;
}
static void T_9 F_85 ( void )
{
F_7 ( & V_34 ) ;
while ( ! F_24 ( & V_38 ) ) {
struct V_30 * V_31 =
(struct V_30 * )
V_38 . V_17 ;
F_22 ( & V_31 -> V_15 ) ;
F_20 ( V_31 ) ;
}
F_8 ( & V_34 ) ;
F_7 ( & V_18 ) ;
while ( ! F_24 ( & V_19 ) ) {
struct V_13 * V_15 =
(struct V_13 * )
V_19 . V_17 ;
F_22 ( & V_15 -> V_15 ) ;
F_20 ( V_15 ) ;
}
F_8 ( & V_18 ) ;
F_47 ( L_68 ) ;
}
