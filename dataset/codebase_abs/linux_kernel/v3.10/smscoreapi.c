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
V_116 -> V_122 = F_51 ( V_116 -> V_122 ) ;
V_116 -> V_123 = F_51 ( V_116 -> V_123 ) ;
V_118 = V_116 -> V_122 ;
F_29 ( L_18 ,
V_118 , V_116 -> V_123 ) ;
if ( V_36 -> V_82 ) {
V_33 = V_36 -> V_82 ( V_36 -> V_44 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_5 = F_9 ( V_124 , V_20 | V_76 ) ;
if ( ! V_5 )
return - V_39 ;
if ( V_36 -> V_21 != V_77 ) {
F_47 ( L_19 ) ;
F_45 ( & V_5 -> V_95 , V_125 ,
sizeof( struct V_126 ) ) ;
V_33 = F_38 ( V_36 , V_5 ,
V_5 -> V_95 . V_100 ,
& V_36 -> V_66 ) ;
if ( V_33 < 0 ) {
F_11 ( L_20 , V_33 ) ;
goto V_127;
}
V_118 = * ( T_6 * ) & V_121 [ 20 ] ;
}
for ( V_3 = 0 , V_120 = ( T_6 * ) V_116 -> V_121 ; V_3 < V_116 -> V_123 / 4 ;
V_3 ++ , V_120 ++ )
V_119 += * V_120 ;
while ( V_86 && V_33 >= 0 ) {
struct V_128 * V_129 =
(struct V_128 * ) V_5 ;
int V_130 = F_52 ( int , V_86 , V_131 ) ;
F_45 ( & V_5 -> V_95 , V_132 ,
( V_133 ) ( sizeof( struct V_126 ) +
sizeof( T_6 ) + V_130 ) ) ;
V_129 -> V_134 = V_118 ;
memcpy ( V_129 -> V_121 , V_121 , V_130 ) ;
V_33 = F_38 ( V_36 , V_129 ,
V_129 -> V_95 . V_100 ,
& V_36 -> V_62 ) ;
V_121 += V_130 ;
V_86 -= V_130 ;
V_118 += V_130 ;
}
if ( V_33 < 0 )
goto V_127;
F_11 ( L_21 ,
V_119 ) ;
F_45 ( & V_5 -> V_95 , V_135 ,
sizeof( V_5 -> V_95 ) +
sizeof( T_6 ) * 3 ) ;
V_5 -> V_97 [ 0 ] = V_116 -> V_122 ;
V_5 -> V_97 [ 1 ] = V_116 -> V_123 ;
V_5 -> V_97 [ 2 ] = 0 ;
V_33 = F_38 ( V_36 , V_5 ,
V_5 -> V_95 . V_100 ,
& V_36 -> V_63 ) ;
if ( V_33 < 0 )
goto V_127;
if ( V_36 -> V_21 == V_77 ) {
struct V_104 * V_136 =
(struct V_104 * ) V_5 ;
F_47 ( L_22 ) ;
F_45 ( & V_5 -> V_95 ,
V_137 ,
sizeof( struct V_126 ) +
sizeof( T_6 ) * 5 ) ;
V_136 -> V_97 [ 0 ] = V_116 -> V_122 ;
V_136 -> V_97 [ 1 ] = 6 ;
V_136 -> V_97 [ 2 ] = 0x200 ;
V_136 -> V_97 [ 3 ] = 0 ;
V_136 -> V_97 [ 4 ] = 4 ;
V_33 = F_38 ( V_36 , V_136 ,
V_136 -> V_95 . V_100 ,
& V_36 -> V_64 ) ;
} else {
F_45 ( & V_5 -> V_95 , V_138 ,
sizeof( struct V_126 ) ) ;
V_33 = V_36 -> V_81 ( V_36 -> V_44 , V_5 ,
V_5 -> V_95 . V_100 ) ;
}
if ( V_33 < 0 )
goto V_127;
F_53 ( 400 ) ;
V_127:
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
char * * V_139 ;
int V_10 = F_5 ( V_36 ) ;
enum V_23 type ;
type = F_13 ( V_36 -> V_14 ) ;
if ( type <= V_140 || type >= V_141 )
return NULL ;
if ( V_21 <= V_77 || V_21 >= V_142 )
return NULL ;
F_47 ( L_25 ,
V_10 , V_21 ) ;
V_139 = F_42 ( V_10 ) -> V_139 ;
if ( ! V_139 || ! V_139 [ V_21 ] ) {
F_47 ( L_26 ,
V_21 , type ) ;
return V_143 [ type ] [ V_21 ] ;
}
return V_139 [ V_21 ] ;
}
static int F_55 ( struct V_7 * V_36 ,
int V_21 ,
T_7 V_144 )
{
int V_33 = - V_145 ;
T_3 * V_146 ;
T_6 V_147 ;
const struct V_116 * V_139 ;
char * V_148 = F_54 ( V_36 , V_21 ) ;
if ( ! V_148 ) {
F_29 ( L_27 , V_21 ) ;
return - V_145 ;
}
F_47 ( L_28 , V_148 ) ;
if ( V_144 == NULL && ! ( V_36 -> V_84
& V_149 ) )
return - V_24 ;
V_33 = F_56 ( & V_139 , V_148 , V_36 -> V_37 ) ;
if ( V_33 < 0 ) {
F_29 ( L_29 , V_148 ) ;
return V_33 ;
}
F_29 ( L_30 , V_148 , V_139 -> V_86 ) ;
V_146 = F_9 ( F_57 ( V_139 -> V_86 , V_150 ) ,
V_20 | V_76 ) ;
if ( ! V_146 ) {
F_29 ( L_31 ) ;
return - V_39 ;
}
memcpy ( V_146 , V_139 -> V_151 , V_139 -> V_86 ) ;
V_147 = V_139 -> V_86 ;
V_33 = ( V_36 -> V_84 & V_149 ) ?
F_50 ( V_36 , V_146 , V_147 )
: V_144 ( V_36 -> V_44 , V_146 ,
V_147 ) ;
F_20 ( V_146 ) ;
F_58 ( V_139 ) ;
return V_33 ;
}
void F_36 ( struct V_7 * V_36 )
{
struct V_47 * V_51 ;
int V_75 = 0 ;
int V_152 = 0 ;
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
if ( ++ V_152 > 10 ) {
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
F_20 ( V_36 -> V_146 ) ;
F_22 ( & V_36 -> V_15 ) ;
F_20 ( V_36 ) ;
F_8 ( & V_34 ) ;
F_29 ( L_35 , V_36 ) ;
}
static int F_61 ( struct V_7 * V_36 )
{
void * V_48 = F_9 ( sizeof( struct V_126 ) + V_94 ,
V_20 | V_76 ) ;
struct V_126 * V_5 =
(struct V_126 * ) F_44 ( V_48 ) ;
int V_33 ;
if ( ! V_48 )
return - V_39 ;
F_45 ( V_5 , V_153 ,
sizeof( struct V_126 ) ) ;
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
F_45 ( & V_5 -> V_95 , V_154 ,
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
if ( V_36 -> V_84 & V_149 ) {
if ( V_21 <= V_77 || V_21 >= V_142 ) {
F_11 ( L_40 , V_21 ) ;
return - V_24 ;
}
F_14 ( V_36 -> V_14 , V_21 ) ;
if ( ! ( V_36 -> V_84 & V_155 ) ) {
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
if ( ! ( V_36 -> V_156 & ( 1 << V_21 ) ) ) {
V_33 = F_55 ( V_36 ,
V_21 , NULL ) ;
if ( V_33 >= 0 )
F_29 ( L_43 ) ;
} else {
F_29 ( L_44 ,
V_21 ) ;
}
if ( V_36 -> V_157 >= 0x800 ) {
V_33 = F_62 ( V_36 , V_21 ) ;
if ( V_33 < 0 )
F_11 ( L_45 , V_33 ) ;
}
} else {
if ( V_21 <= V_77 || V_21 >= V_142 ) {
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
V_36 -> V_84 &= ~ V_155 ;
V_48 = F_9 ( sizeof( struct V_104 ) +
V_94 , V_20 | V_76 ) ;
if ( V_48 ) {
struct V_104 * V_5 = (struct V_104 * ) F_44 ( V_48 ) ;
F_45 ( & V_5 -> V_95 , V_154 ,
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
int V_158 , int V_9 )
{
struct V_16 * V_32 ;
struct V_40 * V_41 ;
unsigned long V_28 ;
struct V_16 * V_159 ;
struct V_160 * V_161 ;
F_17 ( & V_36 -> V_59 , V_28 ) ;
V_32 = & V_36 -> V_42 ;
F_26 (client, first, entry) {
V_159 = & V_41 -> V_162 ;
F_26 (client_id, firstid, entry) {
if ( ( V_161 -> V_9 == V_9 ) &&
( V_161 -> V_158 == V_158 ||
( V_161 -> V_158 == 0 ) ) )
goto V_163;
}
}
V_41 = NULL ;
V_163:
F_18 ( & V_36 -> V_59 , V_28 ) ;
return V_41 ;
}
void F_65 ( struct V_7 * V_36 ,
struct V_47 * V_51 ) {
struct V_126 * V_164 = (struct V_126 * ) ( ( T_3 * ) V_51 -> V_52
+ V_51 -> V_165 ) ;
struct V_40 * V_41 ;
int V_33 = - V_166 ;
static unsigned long V_167 ;
static int V_168 ;
unsigned long V_169 = F_66 ( V_170 ) ;
if ( ! V_167 )
V_167 = V_169 ;
if ( V_169 - V_167 > 10000 ) {
F_47 ( L_48 ,
( int ) ( ( V_168 * 1000 ) /
( V_169 - V_167 ) ) ) ;
V_167 = V_169 ;
V_168 = 0 ;
}
V_168 += V_51 -> V_86 ;
if ( ( V_164 -> V_110 == V_171 ) ||
( V_164 -> V_110 == V_172 ) ) {
if ( V_36 -> V_21 == V_173 )
V_164 -> V_107 = V_174 ;
}
V_41 = F_64 ( V_36 , V_164 -> V_110 , V_164 -> V_107 ) ;
if ( V_41 )
V_33 = V_41 -> V_175 ( V_41 -> V_44 , V_51 ) ;
if ( V_33 < 0 ) {
switch ( V_164 -> V_110 ) {
case V_176 :
break;
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
{
struct V_184 * V_185 =
(struct V_184 * ) V_164 ;
F_47 ( L_49 ,
V_185 -> V_186 , V_185 -> V_187 ,
V_185 -> V_188 , V_185 -> V_189 ) ;
V_36 -> V_21 = V_185 -> V_186 == 255 ?
V_77 : V_185 -> V_186 ;
V_36 -> V_156 = V_185 -> V_187 ;
V_36 -> V_157 = V_185 -> V_188 << 8 |
V_185 -> V_189 ;
F_67 ( & V_36 -> V_61 ) ;
break;
}
case V_190 :
F_67 ( & V_36 -> V_65 ) ;
break;
case V_191 :
F_67 ( & V_36 -> V_66 ) ;
break;
case V_192 :
{
struct V_104 * V_193 = (struct V_104 * ) V_164 ;
F_11 ( L_50 ,
V_193 -> V_97 [ 0 ] ) ;
F_67 ( & V_36 -> V_63 ) ;
break;
}
case V_194 :
F_67 ( & V_36 -> V_62 ) ;
break;
case V_195 :
break;
case V_196 :
F_67 ( & V_36 -> V_64 ) ;
break;
case V_197 :
F_67 ( & V_36 -> V_67 ) ;
break;
case V_198 :
F_67 ( & V_36 -> V_68 ) ;
break;
case V_199 :
F_67 ( & V_36 -> V_69 ) ;
break;
case V_200 :
{
T_6 * V_201 = ( T_6 * ) V_164 ;
V_36 -> V_202 = V_201 [ 1 ] ;
F_47 ( L_51 ,
V_36 -> V_202 ) ;
F_67 ( & V_36 -> V_70 ) ;
break;
}
case V_203 :
F_67 ( & V_36 -> V_71 ) ;
break;
case V_204 :
F_68 ( V_36 ,
( const char * )
( ( char * ) V_164
+ sizeof( struct V_126 ) ) ,
( int ) V_164 -> V_100
- sizeof( struct V_126 ) ) ;
break;
case V_205 :
break;
default:
F_47 ( L_52 ,
F_1 ( V_164 -> V_110 ) ,
V_164 -> V_110 ) ;
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
int V_158 , int V_9 )
{
struct V_160 * V_206 ;
struct V_40 * V_207 ;
if ( ! V_41 ) {
F_11 ( L_53 ) ;
return - V_24 ;
}
V_207 = F_64 ( V_36 , V_158 , V_9 ) ;
if ( V_207 == V_41 )
return 0 ;
if ( V_207 ) {
F_11 ( L_54 ) ;
return - V_208 ;
}
V_206 = F_28 ( sizeof( struct V_160 ) , V_20 ) ;
if ( ! V_206 ) {
F_11 ( L_55 ) ;
return - V_39 ;
}
V_206 -> V_9 = V_9 ;
V_206 -> V_158 = V_158 ;
F_16 ( & V_206 -> V_15 , & V_41 -> V_162 ,
& V_36 -> V_59 ) ;
return 0 ;
}
int F_74 ( struct V_7 * V_36 ,
struct V_209 * V_56 ,
struct V_40 * * V_41 )
{
struct V_40 * V_210 ;
if ( F_64 ( V_36 , V_56 -> V_158 ,
V_56 -> V_211 ) ) {
F_11 ( L_56 ) ;
return - V_208 ;
}
V_210 = F_28 ( sizeof( struct V_40 ) , V_20 ) ;
if ( ! V_210 ) {
F_11 ( L_57 ) ;
return - V_39 ;
}
F_31 ( & V_210 -> V_162 ) ;
V_210 -> V_36 = V_36 ;
V_210 -> V_175 = V_56 -> V_175 ;
V_210 -> V_43 = V_56 -> V_43 ;
V_210 -> V_44 = V_56 -> V_44 ;
F_16 ( & V_210 -> V_15 , & V_36 -> V_42 ,
& V_36 -> V_59 ) ;
F_73 ( V_36 , V_210 , V_56 -> V_158 ,
V_56 -> V_211 ) ;
* V_41 = V_210 ;
F_47 ( L_58 , V_56 -> V_44 , V_56 -> V_158 ,
V_56 -> V_211 ) ;
return 0 ;
}
void F_75 ( struct V_40 * V_41 )
{
struct V_7 * V_36 = V_41 -> V_36 ;
unsigned long V_28 ;
F_17 ( & V_36 -> V_59 , V_28 ) ;
while ( ! F_24 ( & V_41 -> V_162 ) ) {
struct V_160 * V_212 =
(struct V_160 * ) V_41 -> V_162 . V_17 ;
F_22 ( & V_212 -> V_15 ) ;
F_20 ( V_212 ) ;
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
struct V_126 * V_164 = (struct V_126 * ) V_48 ;
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
V_164 -> V_106 ) ;
if ( V_33 < 0 )
return V_33 ;
return V_36 -> V_81 ( V_36 -> V_44 , V_48 , V_86 ) ;
}
int F_77 ( struct V_7 * V_36 , T_6 V_213 ,
struct V_214 * V_215 )
{
struct {
struct V_126 V_216 ;
T_6 V_151 [ 6 ] ;
} V_5 ;
if ( V_36 -> V_84 & V_149 ) {
V_5 . V_216 . V_106 = V_174 ;
V_5 . V_216 . V_107 = V_108 ;
V_5 . V_216 . V_109 = 0 ;
V_5 . V_216 . V_110 = V_217 ;
V_5 . V_216 . V_100 = sizeof( V_5 ) ;
V_5 . V_151 [ 0 ] = V_213 ;
V_5 . V_151 [ 1 ] = V_215 -> V_218 ;
V_5 . V_151 [ 2 ] = V_215 -> V_219 == 0 ? 3 : 0 ;
switch ( V_215 -> V_220 ) {
case V_221 :
V_5 . V_151 [ 3 ] = 7 ;
break;
case V_222 :
V_5 . V_151 [ 3 ] = 5 ;
break;
case V_223 :
V_5 . V_151 [ 3 ] = 3 ;
break;
case V_224 :
default:
V_5 . V_151 [ 3 ] = 2 ;
break;
}
V_5 . V_151 [ 4 ] = V_215 -> V_225 ;
V_5 . V_151 [ 5 ] = 0 ;
} else
return - V_24 ;
return V_36 -> V_81 ( V_36 -> V_44 ,
& V_5 , sizeof( V_5 ) ) ;
}
int F_78 ( struct V_7 * V_36 , T_6 V_213 , int V_226 )
{
struct {
struct V_126 V_216 ;
T_6 V_151 [ 3 ] ;
} V_5 ;
if ( V_213 > V_227 )
return - V_24 ;
V_5 . V_216 . V_106 = V_174 ;
V_5 . V_216 . V_107 = V_108 ;
V_5 . V_216 . V_109 = 0 ;
V_5 . V_216 . V_110 = V_228 ;
V_5 . V_216 . V_100 = sizeof( V_5 ) ;
V_5 . V_151 [ 0 ] = V_213 ;
V_5 . V_151 [ 1 ] = V_226 ? 1 : 0 ;
V_5 . V_151 [ 2 ] = 0 ;
return V_36 -> V_81 ( V_36 -> V_44 ,
& V_5 , sizeof( V_5 ) ) ;
}
static int F_79 ( T_6 V_229 , T_6 * V_230 ,
T_6 * V_231 , T_6 * V_232 ) {
* V_232 = 1 ;
if ( V_229 <= 1 ) {
* V_230 = 0 ;
* V_231 = 9 ;
* V_232 = 2 ;
} else if ( V_229 >= 2 && V_229 <= 6 ) {
* V_230 = 2 ;
* V_231 = 0 ;
* V_232 = 2 ;
} else if ( V_229 >= 7 && V_229 <= 11 ) {
* V_230 = 7 ;
* V_231 = 1 ;
} else if ( V_229 >= 12 && V_229 <= 15 ) {
* V_230 = 12 ;
* V_231 = 2 ;
* V_232 = 3 ;
} else if ( V_229 == 16 ) {
* V_230 = 16 ;
* V_231 = 23 ;
} else if ( V_229 >= 17 && V_229 <= 24 ) {
* V_230 = 17 ;
* V_231 = 3 ;
} else if ( V_229 == 25 ) {
* V_230 = 25 ;
* V_231 = 6 ;
} else if ( V_229 >= 26 && V_229 <= 28 ) {
* V_230 = 26 ;
* V_231 = 4 ;
} else if ( V_229 == 29 ) {
* V_230 = 29 ;
* V_231 = 5 ;
* V_232 = 2 ;
} else if ( V_229 == 30 ) {
* V_230 = 30 ;
* V_231 = 8 ;
} else if ( V_229 == 31 ) {
* V_230 = 31 ;
* V_231 = 17 ;
} else
return - 1 ;
* V_232 <<= 24 ;
return 0 ;
}
int F_80 ( struct V_7 * V_36 , T_3 V_229 ,
struct V_214 * V_233 ) {
T_6 V_234 ;
T_6 V_235 = 0 ;
T_6 V_236 = 0 ;
T_6 V_237 ;
T_6 V_238 ;
void * V_48 ;
int V_33 ;
struct V_239 {
struct V_126 V_95 ;
T_6 V_97 [ 6 ] ;
} * V_240 ;
if ( V_229 > V_227 )
return - V_24 ;
if ( V_233 == NULL )
return - V_24 ;
V_234 = sizeof( struct V_126 ) + ( sizeof( T_6 ) * 6 ) ;
V_48 = F_9 ( V_234 + V_94 ,
V_20 | V_76 ) ;
if ( ! V_48 )
return - V_39 ;
V_240 = (struct V_239 * ) F_44 ( V_48 ) ;
V_240 -> V_95 . V_106 = V_174 ;
V_240 -> V_95 . V_107 = V_108 ;
V_240 -> V_95 . V_109 = 0 ;
V_240 -> V_95 . V_100 = ( V_133 ) V_234 ;
V_240 -> V_97 [ 0 ] = V_229 ;
if ( ! ( V_36 -> V_84 & V_149 ) ) {
V_240 -> V_95 . V_110 = V_241 ;
if ( F_79 ( V_229 , & V_235 , & V_236 ,
& V_238 ) != 0 ) {
V_33 = - V_24 ;
goto free;
}
V_240 -> V_97 [ 1 ] = V_235 ;
V_240 -> V_97 [ 2 ] = V_236 ;
V_237 = ( V_233 -> V_218 )
| ( V_233 -> V_242 << 2 )
| ( V_233 -> V_219 << 3 )
| ( V_233 -> V_220 << 4 ) ;
V_240 -> V_97 [ 3 ] = V_237 ;
V_240 -> V_97 [ 4 ] = V_233 -> V_225 ;
V_240 -> V_97 [ 5 ] = V_238 ;
} else {
V_240 -> V_95 . V_110 = V_217 ;
V_240 -> V_97 [ 1 ] = V_233 -> V_218 ;
V_240 -> V_97 [ 2 ] = V_233 -> V_219 ;
V_240 -> V_97 [ 3 ] = V_233 -> V_220 ;
V_240 -> V_97 [ 4 ] = V_233 -> V_225 ;
V_240 -> V_97 [ 5 ] = 0 ;
}
V_33 = F_38 ( V_36 , V_240 , V_234 ,
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
int F_81 ( struct V_7 * V_36 , T_3 V_229 ,
T_3 V_243 ) {
T_6 V_234 ;
int V_33 ;
void * V_48 ;
struct V_239 {
struct V_126 V_95 ;
T_6 V_97 [ 3 ] ;
} * V_240 ;
if ( ( V_243 > 1 ) || ( V_229 > V_227 ) )
return - V_24 ;
V_234 = sizeof( struct V_126 ) +
( 3 * sizeof( T_6 ) ) ;
V_48 = F_9 ( V_234 + V_94 ,
V_20 | V_76 ) ;
if ( ! V_48 )
return - V_39 ;
V_240 = (struct V_239 * ) F_44 ( V_48 ) ;
V_240 -> V_95 . V_106 = V_174 ;
V_240 -> V_95 . V_107 = V_108 ;
V_240 -> V_95 . V_109 = 0 ;
V_240 -> V_95 . V_110 = V_228 ;
V_240 -> V_95 . V_100 = ( V_133 ) V_234 ;
V_240 -> V_97 [ 0 ] = V_229 ;
V_240 -> V_97 [ 1 ] = V_243 ;
V_33 = F_38 ( V_36 , V_240 , V_234 ,
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
int F_82 ( struct V_7 * V_36 , T_3 V_229 ,
T_3 * V_226 ) {
T_6 V_234 ;
int V_33 ;
void * V_48 ;
struct V_239 {
struct V_126 V_95 ;
T_6 V_97 [ 2 ] ;
} * V_240 ;
if ( V_229 > V_227 )
return - V_24 ;
V_234 = sizeof( struct V_126 ) + ( 2 * sizeof( T_6 ) ) ;
V_48 = F_9 ( V_234 + V_94 ,
V_20 | V_76 ) ;
if ( ! V_48 )
return - V_39 ;
V_240 = (struct V_239 * ) F_44 ( V_48 ) ;
V_240 -> V_95 . V_106 = V_174 ;
V_240 -> V_95 . V_107 = V_108 ;
V_240 -> V_95 . V_109 = 0 ;
V_240 -> V_95 . V_110 = V_244 ;
V_240 -> V_95 . V_100 = ( V_133 ) V_234 ;
V_240 -> V_97 [ 0 ] = V_229 ;
V_240 -> V_97 [ 1 ] = 0 ;
V_33 = F_38 ( V_36 , V_240 , V_234 ,
& V_36 -> V_70 ) ;
if ( V_33 != 0 ) {
if ( V_33 == - V_89 )
F_11 ( L_66 ) ;
else
F_11 ( L_67 ) ;
}
F_20 ( V_48 ) ;
* V_226 = V_36 -> V_202 ;
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
