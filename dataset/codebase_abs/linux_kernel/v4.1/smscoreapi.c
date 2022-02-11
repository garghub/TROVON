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
if ( ! V_51 )
return NULL ;
V_51 -> V_52 = V_48 ;
V_51 -> V_53 = V_48 - ( T_3 * ) V_49 ;
V_51 -> V_54 = V_50 + V_51 -> V_53 ;
return V_51 ;
}
int F_29 ( struct V_55 * V_56 ,
struct V_7 * * V_36 ,
void * V_57 )
{
struct V_7 * V_58 ;
T_3 * V_48 ;
V_58 = F_28 ( sizeof( struct V_7 ) , V_20 ) ;
if ( ! V_58 )
return - V_39 ;
#ifdef F_30
V_58 -> V_59 = V_57 ;
#endif
F_31 ( & V_58 -> V_15 ) ;
F_31 ( & V_58 -> V_42 ) ;
F_31 ( & V_58 -> V_60 ) ;
F_32 ( & V_58 -> V_61 ) ;
F_32 ( & V_58 -> V_62 ) ;
F_33 ( & V_58 -> V_63 ) ;
F_33 ( & V_58 -> V_64 ) ;
F_33 ( & V_58 -> V_65 ) ;
F_33 ( & V_58 -> V_66 ) ;
F_33 ( & V_58 -> V_67 ) ;
F_33 ( & V_58 -> V_68 ) ;
F_33 ( & V_58 -> V_69 ) ;
F_33 ( & V_58 -> V_70 ) ;
F_33 ( & V_58 -> V_71 ) ;
F_33 ( & V_58 -> V_72 ) ;
F_33 ( & V_58 -> V_73 ) ;
F_34 ( & V_58 -> V_74 ) ;
V_58 -> V_75 = V_56 -> V_76 * V_56 -> V_77 ;
V_58 -> V_49 = F_35 ( NULL , V_58 -> V_75 ,
& V_58 -> V_50 ,
V_20 | V_78 ) ;
if ( ! V_58 -> V_49 ) {
F_36 ( V_58 ) ;
return - V_39 ;
}
for ( V_48 = V_58 -> V_49 ;
V_58 -> V_77 < V_56 -> V_77 ;
V_58 -> V_77 ++ , V_48 += V_56 -> V_76 ) {
struct V_47 * V_51 ;
V_51 = F_27 ( V_48 , V_58 -> V_49 ,
V_58 -> V_50 ) ;
if ( ! V_51 ) {
F_36 ( V_58 ) ;
return - V_39 ;
}
F_37 ( V_58 , V_51 ) ;
}
F_38 ( L_4 , V_58 -> V_77 ) ;
V_58 -> V_21 = V_79 ;
V_58 -> V_10 = V_80 ;
V_58 -> V_44 = V_56 -> V_44 ;
V_58 -> V_37 = V_56 -> V_37 ;
V_58 -> V_81 = V_56 -> V_81 ;
V_58 -> V_82 = V_56 -> V_82 ;
V_58 -> V_83 = V_56 -> V_83 ;
V_58 -> V_84 = V_56 -> V_84 ;
V_58 -> V_85 = V_56 -> V_85 ;
V_58 -> V_86 = V_56 -> V_28 ;
strcpy ( V_58 -> V_14 , V_56 -> V_14 ) ;
F_15 ( V_58 -> V_14 , V_56 -> V_87 ) ;
F_7 ( & V_34 ) ;
F_10 ( & V_58 -> V_15 , & V_35 ) ;
F_8 ( & V_34 ) ;
* V_36 = V_58 ;
F_38 ( L_5 , V_58 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_36 ,
void * V_48 , T_5 V_88 , struct V_89 * V_89 ) {
int V_33 ;
if ( V_89 == NULL )
return - V_24 ;
F_33 ( V_89 ) ;
V_33 = V_36 -> V_83 ( V_36 -> V_44 , V_48 , V_88 ) ;
if ( V_33 < 0 ) {
F_40 ( L_6 , V_33 ) ;
return V_33 ;
}
return F_41 ( V_89 ,
F_42 ( V_90 ) ) ?
0 : - V_91 ;
}
static int F_43 ( struct V_7 * V_36 )
{
int V_92 ;
int V_33 ;
void * V_48 ;
V_36 -> V_93 . V_58 = NULL ;
V_92 = F_44 ( F_5 ( V_36 ) ) -> V_94 . V_93 ;
if ( V_92 ) {
F_38 ( L_7 ) ;
V_33 = F_45 ( V_36 ) ;
if ( V_33 != 0 )
F_11 ( L_8 ) ;
else {
V_48 = F_9 ( sizeof( struct V_95 ) +
V_96 ,
V_20 | V_78 ) ;
if ( V_48 ) {
struct V_95 * V_5 =
(struct V_95 * )
F_46 ( V_48 ) ;
F_47 ( & V_5 -> V_97 ,
V_98 ,
sizeof( struct V_95 ) ) ;
V_5 -> V_99 [ 0 ] = V_36 -> V_93 . V_100 ;
V_5 -> V_99 [ 1 ] = V_36 -> V_93 . V_101 ;
V_33 = F_39 ( V_36 , V_5 ,
V_5 -> V_97 . V_102 ,
& V_36 -> V_73 ) ;
F_20 ( V_48 ) ;
} else
F_11 ( L_9 ) ;
}
} else
F_40 ( L_10 ) ;
return 0 ;
}
static int F_48 ( struct V_7 * V_36 )
{
struct V_103 * V_104 ;
V_104 = F_44 ( V_36 -> V_10 ) ;
if ( ! V_104 ) {
F_11 ( L_11 ) ;
return - V_24 ;
}
if ( V_104 -> V_105 ) {
struct V_106 V_107 ;
F_38 ( L_12 , V_104 -> V_105 ) ;
V_107 . V_97 . V_108 = 0 ;
V_107 . V_97 . V_109 = V_110 ;
V_107 . V_97 . V_111 = 0 ;
V_107 . V_97 . V_112 = V_113 ;
V_107 . V_97 . V_102 = sizeof( V_107 ) ;
V_107 . V_99 [ 0 ] = V_104 -> V_105 ;
V_36 -> V_83 ( V_36 -> V_44 , & V_107 ,
sizeof( V_107 ) ) ;
}
if ( V_104 -> V_114 ) {
struct V_106 V_115 ;
F_38 ( L_13 , V_104 -> V_114 ) ;
F_47 ( & V_115 . V_97 ,
V_116 ,
sizeof( V_115 ) ) ;
V_115 . V_99 [ 0 ] = V_104 -> V_114 ;
V_36 -> V_83 ( V_36 -> V_44 , & V_115 ,
sizeof( V_115 ) ) ;
}
return 0 ;
}
int F_49 ( struct V_7 * V_36 )
{
int V_33 ;
int V_10 = F_5 ( V_36 ) ;
int V_21 = F_12 ( V_36 -> V_14 ) ;
if ( V_10 != V_80 && V_21 == V_79 )
V_21 = F_44 ( V_10 ) -> V_22 ;
V_33 = F_50 ( V_36 , V_21 ) ;
if ( V_33 < 0 ) {
F_40 ( L_14 , V_33 ) ;
return V_33 ;
}
V_33 = F_48 ( V_36 ) ;
if ( V_33 < 0 ) {
F_40 ( L_15 , V_33 ) ;
return V_33 ;
}
F_7 ( & V_34 ) ;
V_33 = F_25 ( V_36 , V_36 -> V_37 , 1 ) ;
F_43 ( V_36 ) ;
F_38 ( L_16 , V_36 , V_33 ) ;
F_8 ( & V_34 ) ;
return V_33 ;
}
static int F_51 ( struct V_7 * V_36 ,
void * V_48 , T_5 V_88 )
{
struct V_117 * V_118 = (struct V_117 * ) V_48 ;
struct V_119 * V_5 ;
T_6 V_120 , V_121 = 0 ;
T_6 V_3 , * V_122 ;
T_3 * V_123 = V_118 -> V_123 ;
int V_33 = 0 ;
V_118 -> V_124 = F_52 ( ( V_125 * ) & V_118 -> V_124 ) ;
V_118 -> V_126 = F_52 ( ( V_125 * ) & V_118 -> V_126 ) ;
V_120 = V_118 -> V_124 ;
F_38 ( L_17 ,
V_120 , V_118 -> V_126 ) ;
if ( V_36 -> V_84 ) {
V_33 = V_36 -> V_84 ( V_36 -> V_44 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_5 = F_9 ( V_127 , V_20 | V_78 ) ;
if ( ! V_5 )
return - V_39 ;
if ( V_36 -> V_21 != V_79 ) {
F_38 ( L_18 ) ;
F_47 ( & V_5 -> V_97 , V_128 ,
sizeof( struct V_129 ) ) ;
V_33 = F_39 ( V_36 , V_5 ,
V_5 -> V_97 . V_102 ,
& V_36 -> V_68 ) ;
if ( V_33 < 0 ) {
F_11 ( L_19 , V_33 ) ;
goto V_130;
}
V_120 = * ( T_6 * ) & V_123 [ 20 ] ;
}
for ( V_3 = 0 , V_122 = ( T_6 * ) V_118 -> V_123 ; V_3 < V_118 -> V_126 / 4 ;
V_3 ++ , V_122 ++ )
V_121 += * V_122 ;
while ( V_88 && V_33 >= 0 ) {
struct V_131 * V_132 =
(struct V_131 * ) V_5 ;
int V_133 = F_53 ( int , V_88 , V_134 ) ;
F_47 ( & V_5 -> V_97 , V_135 ,
( V_136 ) ( sizeof( struct V_129 ) +
sizeof( T_6 ) + V_133 ) ) ;
V_132 -> V_137 = V_120 ;
memcpy ( V_132 -> V_123 , V_123 , V_133 ) ;
V_33 = F_39 ( V_36 , V_132 ,
V_132 -> V_97 . V_102 ,
& V_36 -> V_64 ) ;
V_123 += V_133 ;
V_88 -= V_133 ;
V_120 += V_133 ;
}
if ( V_33 < 0 )
goto V_130;
F_38 ( L_20 ,
V_121 ) ;
F_47 ( & V_5 -> V_97 , V_138 ,
sizeof( V_5 -> V_97 ) +
sizeof( T_6 ) * 3 ) ;
V_5 -> V_99 [ 0 ] = V_118 -> V_124 ;
V_5 -> V_99 [ 1 ] = V_118 -> V_126 ;
V_5 -> V_99 [ 2 ] = 0 ;
V_33 = F_39 ( V_36 , V_5 ,
V_5 -> V_97 . V_102 ,
& V_36 -> V_65 ) ;
if ( V_33 < 0 )
goto V_130;
if ( V_36 -> V_21 == V_79 ) {
struct V_106 * V_139 =
(struct V_106 * ) V_5 ;
F_38 ( L_21 ) ;
F_47 ( & V_5 -> V_97 ,
V_140 ,
sizeof( struct V_129 ) +
sizeof( T_6 ) * 5 ) ;
V_139 -> V_99 [ 0 ] = V_118 -> V_124 ;
V_139 -> V_99 [ 1 ] = 6 ;
V_139 -> V_99 [ 2 ] = 0x200 ;
V_139 -> V_99 [ 3 ] = 0 ;
V_139 -> V_99 [ 4 ] = 4 ;
V_33 = F_39 ( V_36 , V_139 ,
V_139 -> V_97 . V_102 ,
& V_36 -> V_66 ) ;
} else {
F_47 ( & V_5 -> V_97 , V_141 ,
sizeof( struct V_129 ) ) ;
V_33 = V_36 -> V_83 ( V_36 -> V_44 , V_5 ,
V_5 -> V_97 . V_102 ) ;
}
if ( V_33 < 0 )
goto V_130;
F_54 ( 400 ) ;
V_130:
F_20 ( V_5 ) ;
if ( V_36 -> V_85 ) {
F_38 ( L_22 ,
V_33 , V_36 -> V_85 ) ;
if ( V_33 >= 0 )
return V_36 -> V_85 ( V_36 -> V_44 ) ;
}
F_38 ( L_23 , V_33 ) ;
return V_33 ;
}
static char * F_55 ( struct V_7 * V_36 ,
int V_21 )
{
char * * V_142 ;
int V_10 = F_5 ( V_36 ) ;
enum V_23 type ;
type = F_13 ( V_36 -> V_14 ) ;
if ( type <= V_143 || type >= V_144 )
return NULL ;
if ( V_21 <= V_79 || V_21 >= V_145 )
return NULL ;
F_38 ( L_24 ,
V_10 , V_21 ) ;
V_142 = F_44 ( V_10 ) -> V_142 ;
if ( ! V_142 || ! V_142 [ V_21 ] ) {
F_38 ( L_25 ,
V_21 , type ) ;
return V_146 [ type ] [ V_21 ] ;
}
return V_142 [ V_21 ] ;
}
static int F_56 ( struct V_7 * V_36 ,
int V_21 ,
T_7 V_147 )
{
int V_33 = - V_148 ;
T_3 * V_149 ;
T_6 V_150 ;
const struct V_118 * V_142 ;
char * V_151 = F_55 ( V_36 , V_21 ) ;
if ( ! V_151 ) {
F_11 ( L_26 , V_21 ) ;
return - V_148 ;
}
F_38 ( L_27 , V_151 ) ;
if ( V_147 == NULL && ! ( V_36 -> V_86
& V_152 ) )
return - V_24 ;
V_33 = F_57 ( & V_142 , V_151 , V_36 -> V_37 ) ;
if ( V_33 < 0 ) {
F_11 ( L_28 , V_151 ) ;
return V_33 ;
}
F_38 ( L_29 , V_151 , V_142 -> V_88 ) ;
V_149 = F_9 ( F_58 ( V_142 -> V_88 , V_153 ) ,
V_20 | V_78 ) ;
if ( ! V_149 ) {
F_11 ( L_30 ) ;
V_33 = - V_39 ;
} else {
memcpy ( V_149 , V_142 -> V_154 , V_142 -> V_88 ) ;
V_150 = V_142 -> V_88 ;
V_33 = ( V_36 -> V_86 & V_152 ) ?
F_51 ( V_36 , V_149 , V_150 )
: V_147 ( V_36 -> V_44 , V_149 ,
V_150 ) ;
}
F_20 ( V_149 ) ;
F_59 ( V_142 ) ;
return V_33 ;
}
void F_36 ( struct V_7 * V_36 )
{
struct V_47 * V_51 ;
int V_77 = 0 ;
int V_155 = 0 ;
F_7 ( & V_34 ) ;
F_60 ( V_36 ) ;
F_23 ( V_36 ) ;
F_25 ( V_36 , NULL , 0 ) ;
while ( 1 ) {
while ( ! F_24 ( & V_36 -> V_60 ) ) {
V_51 = (struct V_47 * ) V_36 -> V_60 . V_17 ;
F_22 ( & V_51 -> V_15 ) ;
F_20 ( V_51 ) ;
V_77 ++ ;
}
if ( V_77 == V_36 -> V_77 )
break;
if ( ++ V_155 > 10 ) {
F_40 ( L_31 ) ;
break;
}
F_38 ( L_32 ,
V_36 -> V_77 - V_77 ) ;
F_8 ( & V_34 ) ;
F_54 ( 100 ) ;
F_7 ( & V_34 ) ;
}
F_38 ( L_33 , V_77 ) ;
if ( V_36 -> V_49 )
F_61 ( NULL , V_36 -> V_75 ,
V_36 -> V_49 , V_36 -> V_50 ) ;
F_20 ( V_36 -> V_149 ) ;
F_22 ( & V_36 -> V_15 ) ;
F_20 ( V_36 ) ;
F_8 ( & V_34 ) ;
F_38 ( L_34 , V_36 ) ;
}
static int F_62 ( struct V_7 * V_36 )
{
void * V_48 = F_9 ( sizeof( struct V_129 ) + V_96 ,
V_20 | V_78 ) ;
struct V_129 * V_5 =
(struct V_129 * ) F_46 ( V_48 ) ;
int V_33 ;
if ( ! V_48 )
return - V_39 ;
F_47 ( V_5 , V_156 ,
sizeof( struct V_129 ) ) ;
V_33 = F_39 ( V_36 , V_5 , V_5 -> V_102 ,
& V_36 -> V_63 ) ;
if ( V_33 == - V_91 ) {
F_11 ( L_35 ) ;
if ( F_41 ( & V_36 -> V_69 ,
F_42 ( 5000 ) ) ) {
V_33 = F_39 (
V_36 , V_5 , V_5 -> V_102 ,
& V_36 -> V_63 ) ;
if ( V_33 < 0 )
F_11 ( L_36 ,
V_33 ) ;
} else
V_33 = - V_91 ;
}
F_20 ( V_48 ) ;
return V_33 ;
}
static int F_63 ( struct V_7 * V_36 , int V_21 )
{
void * V_48 ;
struct V_106 * V_5 ;
int V_33 = 0 ;
V_48 = F_9 ( sizeof( struct V_106 ) +
V_96 , V_20 | V_78 ) ;
if ( ! V_48 ) {
F_11 ( L_37 ) ;
return - V_39 ;
}
V_5 = (struct V_106 * ) F_46 ( V_48 ) ;
F_47 ( & V_5 -> V_97 , V_157 ,
sizeof( struct V_106 ) ) ;
V_5 -> V_99 [ 0 ] = V_21 ;
V_33 = F_39 ( V_36 , V_5 ,
V_5 -> V_97 . V_102 ,
& V_36 -> V_67 ) ;
F_20 ( V_48 ) ;
return V_33 ;
}
int F_50 ( struct V_7 * V_36 , int V_21 )
{
int V_33 = 0 ;
F_38 ( L_38 , V_21 ) ;
if ( V_36 -> V_86 & V_152 ) {
if ( V_21 <= V_79 || V_21 >= V_145 ) {
F_11 ( L_39 , V_21 ) ;
return - V_24 ;
}
F_14 ( V_36 -> V_14 , V_21 ) ;
if ( ! ( V_36 -> V_86 & V_158 ) ) {
V_33 = F_62 ( V_36 ) ;
if ( V_33 < 0 ) {
F_11 ( L_40 , V_33 ) ;
return V_33 ;
}
}
if ( V_36 -> V_21 == V_21 ) {
F_38 ( L_41 , V_21 ) ;
return 0 ;
}
if ( ! ( V_36 -> V_159 & ( 1 << V_21 ) ) ) {
V_33 = F_56 ( V_36 ,
V_21 , NULL ) ;
if ( V_33 >= 0 )
F_38 ( L_42 ) ;
} else {
F_38 ( L_43 ,
V_21 ) ;
}
if ( V_36 -> V_160 >= 0x800 ) {
V_33 = F_63 ( V_36 , V_21 ) ;
if ( V_33 < 0 )
F_11 ( L_44 , V_33 ) ;
}
} else {
if ( V_21 <= V_79 || V_21 >= V_145 ) {
F_11 ( L_39 , V_21 ) ;
return - V_24 ;
}
F_14 ( V_36 -> V_14 , V_21 ) ;
if ( V_36 -> V_82 )
V_36 -> V_82 ( V_36 -> V_44 ,
& V_36 -> V_21 ) ;
if ( V_36 -> V_21 != V_21 && V_36 -> V_81 )
V_33 = V_36 -> V_81 ( V_36 -> V_44 , V_21 ) ;
}
if ( V_33 >= 0 ) {
char * V_48 ;
V_36 -> V_21 = V_21 ;
V_36 -> V_86 &= ~ V_158 ;
V_48 = F_9 ( sizeof( struct V_106 ) +
V_96 , V_20 | V_78 ) ;
if ( V_48 ) {
struct V_106 * V_5 = (struct V_106 * ) F_46 ( V_48 ) ;
F_47 ( & V_5 -> V_97 , V_157 ,
sizeof( struct V_106 ) ) ;
V_5 -> V_99 [ 0 ] = V_21 ;
V_33 = F_39 (
V_36 , V_5 , V_5 -> V_97 . V_102 ,
& V_36 -> V_67 ) ;
F_20 ( V_48 ) ;
}
}
if ( V_33 < 0 )
F_11 ( L_45 , V_33 ) ;
else
F_38 ( L_46 ) ;
return V_33 ;
}
int F_64 ( struct V_7 * V_36 )
{
return V_36 -> V_21 ;
}
static struct
V_40 * F_65 ( struct V_7 * V_36 ,
int V_161 , int V_9 )
{
struct V_16 * V_32 ;
struct V_40 * V_41 ;
unsigned long V_28 ;
struct V_16 * V_162 ;
struct V_163 * V_164 ;
F_17 ( & V_36 -> V_61 , V_28 ) ;
V_32 = & V_36 -> V_42 ;
F_26 (client, first, entry) {
V_162 = & V_41 -> V_165 ;
F_26 (client_id, firstid, entry) {
if ( ( V_164 -> V_9 == V_9 ) &&
( V_164 -> V_161 == V_161 ||
( V_164 -> V_161 == 0 ) ) )
goto V_166;
}
}
V_41 = NULL ;
V_166:
F_18 ( & V_36 -> V_61 , V_28 ) ;
return V_41 ;
}
void F_66 ( struct V_7 * V_36 ,
struct V_47 * V_51 ) {
struct V_129 * V_167 = (struct V_129 * ) ( ( T_3 * ) V_51 -> V_52
+ V_51 -> V_168 ) ;
struct V_40 * V_41 ;
int V_33 = - V_169 ;
static unsigned long V_170 ;
static int V_171 ;
unsigned long V_172 = F_67 ( V_173 ) ;
if ( ! V_170 )
V_170 = V_172 ;
if ( V_172 - V_170 > 10000 ) {
F_38 ( L_47 ,
( int ) ( ( V_171 * 1000 ) /
( V_172 - V_170 ) ) ) ;
V_170 = V_172 ;
V_171 = 0 ;
}
V_171 += V_51 -> V_88 ;
if ( ( V_167 -> V_112 == V_174 ) ||
( V_167 -> V_112 == V_175 ) ) {
if ( V_36 -> V_21 == V_176 )
V_167 -> V_109 = V_177 ;
}
V_41 = F_65 ( V_36 , V_167 -> V_112 , V_167 -> V_109 ) ;
if ( V_41 )
V_33 = V_41 -> V_178 ( V_41 -> V_44 , V_51 ) ;
if ( V_33 < 0 ) {
switch ( V_167 -> V_112 ) {
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
break;
case V_185 :
break;
case V_186 :
{
struct V_187 * V_188 =
(struct V_187 * ) V_167 ;
F_38 ( L_48 ,
V_188 -> V_189 , V_188 -> V_190 ,
V_188 -> V_191 , V_188 -> V_192 ) ;
V_36 -> V_21 = V_188 -> V_189 == 255 ?
V_79 : V_188 -> V_189 ;
V_36 -> V_159 = V_188 -> V_190 ;
V_36 -> V_160 = V_188 -> V_191 << 8 |
V_188 -> V_192 ;
F_68 ( & V_36 -> V_63 ) ;
break;
}
case V_193 :
F_68 ( & V_36 -> V_67 ) ;
break;
case V_194 :
F_68 ( & V_36 -> V_68 ) ;
break;
case V_195 :
{
struct V_106 * V_196 = (struct V_106 * ) V_167 ;
F_38 ( L_49 ,
V_196 -> V_99 [ 0 ] ) ;
F_68 ( & V_36 -> V_65 ) ;
break;
}
case V_197 :
F_68 ( & V_36 -> V_64 ) ;
break;
case V_198 :
break;
case V_199 :
F_68 ( & V_36 -> V_66 ) ;
break;
case V_200 :
F_68 ( & V_36 -> V_69 ) ;
break;
case V_201 :
F_68 ( & V_36 -> V_70 ) ;
break;
case V_202 :
F_68 ( & V_36 -> V_71 ) ;
break;
case V_203 :
{
T_6 * V_204 = ( T_6 * ) V_167 ;
V_36 -> V_205 = V_204 [ 1 ] ;
F_38 ( L_50 ,
V_36 -> V_205 ) ;
F_68 ( & V_36 -> V_72 ) ;
break;
}
case V_206 :
F_68 ( & V_36 -> V_73 ) ;
break;
case V_207 :
F_69 ( V_36 ,
( const char * )
( ( char * ) V_167
+ sizeof( struct V_129 ) ) ,
( int ) V_167 -> V_102
- sizeof( struct V_129 ) ) ;
break;
case V_208 :
break;
default:
F_38 ( L_51 ,
F_1 ( V_167 -> V_112 ) ,
V_167 -> V_112 ) ;
break;
}
F_37 ( V_36 , V_51 ) ;
}
}
static struct V_47 * F_70 ( struct V_7 * V_36 )
{
struct V_47 * V_51 = NULL ;
unsigned long V_28 ;
F_17 ( & V_36 -> V_62 , V_28 ) ;
if ( ! F_24 ( & V_36 -> V_60 ) ) {
V_51 = (struct V_47 * ) V_36 -> V_60 . V_17 ;
F_22 ( & V_51 -> V_15 ) ;
}
F_18 ( & V_36 -> V_62 , V_28 ) ;
return V_51 ;
}
struct V_47 * F_71 ( struct V_7 * V_36 )
{
struct V_47 * V_51 = NULL ;
F_72 ( V_36 -> V_74 , ( V_51 = F_70 ( V_36 ) ) ) ;
return V_51 ;
}
void F_37 ( struct V_7 * V_36 ,
struct V_47 * V_51 ) {
F_73 ( & V_36 -> V_74 ) ;
F_16 ( & V_51 -> V_15 , & V_36 -> V_60 , & V_36 -> V_62 ) ;
}
static int F_74 ( struct V_7 * V_36 ,
struct V_40 * V_41 ,
int V_161 , int V_9 )
{
struct V_163 * V_209 ;
struct V_40 * V_210 ;
if ( ! V_41 ) {
F_11 ( L_52 ) ;
return - V_24 ;
}
V_210 = F_65 ( V_36 , V_161 , V_9 ) ;
if ( V_210 == V_41 )
return 0 ;
if ( V_210 ) {
F_11 ( L_53 ) ;
return - V_211 ;
}
V_209 = F_28 ( sizeof( struct V_163 ) , V_20 ) ;
if ( ! V_209 ) {
F_11 ( L_54 ) ;
return - V_39 ;
}
V_209 -> V_9 = V_9 ;
V_209 -> V_161 = V_161 ;
F_16 ( & V_209 -> V_15 , & V_41 -> V_165 ,
& V_36 -> V_61 ) ;
return 0 ;
}
int F_75 ( struct V_7 * V_36 ,
struct V_212 * V_56 ,
struct V_40 * * V_41 )
{
struct V_40 * V_213 ;
if ( F_65 ( V_36 , V_56 -> V_161 ,
V_56 -> V_214 ) ) {
F_11 ( L_55 ) ;
return - V_211 ;
}
V_213 = F_28 ( sizeof( struct V_40 ) , V_20 ) ;
if ( ! V_213 ) {
F_11 ( L_56 ) ;
return - V_39 ;
}
F_31 ( & V_213 -> V_165 ) ;
V_213 -> V_36 = V_36 ;
V_213 -> V_178 = V_56 -> V_178 ;
V_213 -> V_43 = V_56 -> V_43 ;
V_213 -> V_44 = V_56 -> V_44 ;
F_16 ( & V_213 -> V_15 , & V_36 -> V_42 ,
& V_36 -> V_61 ) ;
F_74 ( V_36 , V_213 , V_56 -> V_161 ,
V_56 -> V_214 ) ;
* V_41 = V_213 ;
F_38 ( L_57 , V_56 -> V_44 , V_56 -> V_161 ,
V_56 -> V_214 ) ;
return 0 ;
}
void F_76 ( struct V_40 * V_41 )
{
struct V_7 * V_36 = V_41 -> V_36 ;
unsigned long V_28 ;
F_17 ( & V_36 -> V_61 , V_28 ) ;
while ( ! F_24 ( & V_41 -> V_165 ) ) {
struct V_163 * V_215 =
(struct V_163 * ) V_41 -> V_165 . V_17 ;
F_22 ( & V_215 -> V_15 ) ;
F_20 ( V_215 ) ;
}
F_38 ( L_58 , V_41 -> V_44 ) ;
F_22 ( & V_41 -> V_15 ) ;
F_20 ( V_41 ) ;
F_18 ( & V_36 -> V_61 , V_28 ) ;
}
int F_77 ( struct V_40 * V_41 ,
void * V_48 , T_5 V_88 )
{
struct V_7 * V_36 ;
struct V_129 * V_167 = (struct V_129 * ) V_48 ;
int V_33 ;
if ( V_41 == NULL ) {
F_11 ( L_59 ) ;
return - V_24 ;
}
V_36 = V_41 -> V_36 ;
if ( V_36 == NULL ) {
F_11 ( L_60 ) ;
return - V_24 ;
}
V_33 = F_74 ( V_41 -> V_36 , V_41 , 0 ,
V_167 -> V_108 ) ;
if ( V_33 < 0 )
return V_33 ;
return V_36 -> V_83 ( V_36 -> V_44 , V_48 , V_88 ) ;
}
int F_78 ( struct V_7 * V_36 , T_6 V_216 ,
struct V_217 * V_218 )
{
struct {
struct V_129 V_219 ;
T_6 V_154 [ 6 ] ;
} V_5 ;
if ( V_36 -> V_86 & V_152 ) {
V_5 . V_219 . V_108 = V_177 ;
V_5 . V_219 . V_109 = V_110 ;
V_5 . V_219 . V_111 = 0 ;
V_5 . V_219 . V_112 = V_220 ;
V_5 . V_219 . V_102 = sizeof( V_5 ) ;
V_5 . V_154 [ 0 ] = V_216 ;
V_5 . V_154 [ 1 ] = V_218 -> V_221 ;
V_5 . V_154 [ 2 ] = V_218 -> V_222 == 0 ? 3 : 0 ;
switch ( V_218 -> V_223 ) {
case V_224 :
V_5 . V_154 [ 3 ] = 7 ;
break;
case V_225 :
V_5 . V_154 [ 3 ] = 5 ;
break;
case V_226 :
V_5 . V_154 [ 3 ] = 3 ;
break;
case V_227 :
default:
V_5 . V_154 [ 3 ] = 2 ;
break;
}
V_5 . V_154 [ 4 ] = V_218 -> V_228 ;
V_5 . V_154 [ 5 ] = 0 ;
} else
return - V_24 ;
return V_36 -> V_83 ( V_36 -> V_44 ,
& V_5 , sizeof( V_5 ) ) ;
}
int F_79 ( struct V_7 * V_36 , T_6 V_216 , int V_229 )
{
struct {
struct V_129 V_219 ;
T_6 V_154 [ 3 ] ;
} V_5 ;
if ( V_216 > V_230 )
return - V_24 ;
V_5 . V_219 . V_108 = V_177 ;
V_5 . V_219 . V_109 = V_110 ;
V_5 . V_219 . V_111 = 0 ;
V_5 . V_219 . V_112 = V_231 ;
V_5 . V_219 . V_102 = sizeof( V_5 ) ;
V_5 . V_154 [ 0 ] = V_216 ;
V_5 . V_154 [ 1 ] = V_229 ? 1 : 0 ;
V_5 . V_154 [ 2 ] = 0 ;
return V_36 -> V_83 ( V_36 -> V_44 ,
& V_5 , sizeof( V_5 ) ) ;
}
static int F_80 ( T_6 V_232 , T_6 * V_233 ,
T_6 * V_234 , T_6 * V_235 ) {
* V_235 = 1 ;
if ( V_232 <= 1 ) {
* V_233 = 0 ;
* V_234 = 9 ;
* V_235 = 2 ;
} else if ( V_232 >= 2 && V_232 <= 6 ) {
* V_233 = 2 ;
* V_234 = 0 ;
* V_235 = 2 ;
} else if ( V_232 >= 7 && V_232 <= 11 ) {
* V_233 = 7 ;
* V_234 = 1 ;
} else if ( V_232 >= 12 && V_232 <= 15 ) {
* V_233 = 12 ;
* V_234 = 2 ;
* V_235 = 3 ;
} else if ( V_232 == 16 ) {
* V_233 = 16 ;
* V_234 = 23 ;
} else if ( V_232 >= 17 && V_232 <= 24 ) {
* V_233 = 17 ;
* V_234 = 3 ;
} else if ( V_232 == 25 ) {
* V_233 = 25 ;
* V_234 = 6 ;
} else if ( V_232 >= 26 && V_232 <= 28 ) {
* V_233 = 26 ;
* V_234 = 4 ;
} else if ( V_232 == 29 ) {
* V_233 = 29 ;
* V_234 = 5 ;
* V_235 = 2 ;
} else if ( V_232 == 30 ) {
* V_233 = 30 ;
* V_234 = 8 ;
} else if ( V_232 == 31 ) {
* V_233 = 31 ;
* V_234 = 17 ;
} else
return - 1 ;
* V_235 <<= 24 ;
return 0 ;
}
int F_81 ( struct V_7 * V_36 , T_3 V_232 ,
struct V_217 * V_236 ) {
T_6 V_237 ;
T_6 V_238 = 0 ;
T_6 V_239 = 0 ;
T_6 V_240 ;
T_6 V_241 ;
void * V_48 ;
int V_33 ;
struct V_242 {
struct V_129 V_97 ;
T_6 V_99 [ 6 ] ;
} * V_243 ;
if ( V_232 > V_230 )
return - V_24 ;
if ( V_236 == NULL )
return - V_24 ;
V_237 = sizeof( struct V_129 ) + ( sizeof( T_6 ) * 6 ) ;
V_48 = F_9 ( V_237 + V_96 ,
V_20 | V_78 ) ;
if ( ! V_48 )
return - V_39 ;
V_243 = (struct V_242 * ) F_46 ( V_48 ) ;
V_243 -> V_97 . V_108 = V_177 ;
V_243 -> V_97 . V_109 = V_110 ;
V_243 -> V_97 . V_111 = 0 ;
V_243 -> V_97 . V_102 = ( V_136 ) V_237 ;
V_243 -> V_99 [ 0 ] = V_232 ;
if ( ! ( V_36 -> V_86 & V_152 ) ) {
V_243 -> V_97 . V_112 = V_244 ;
if ( F_80 ( V_232 , & V_238 , & V_239 ,
& V_241 ) != 0 ) {
V_33 = - V_24 ;
goto free;
}
V_243 -> V_99 [ 1 ] = V_238 ;
V_243 -> V_99 [ 2 ] = V_239 ;
V_240 = ( V_236 -> V_221 )
| ( V_236 -> V_245 << 2 )
| ( V_236 -> V_222 << 3 )
| ( V_236 -> V_223 << 4 ) ;
V_243 -> V_99 [ 3 ] = V_240 ;
V_243 -> V_99 [ 4 ] = V_236 -> V_228 ;
V_243 -> V_99 [ 5 ] = V_241 ;
} else {
V_243 -> V_97 . V_112 = V_220 ;
V_243 -> V_99 [ 1 ] = V_236 -> V_221 ;
V_243 -> V_99 [ 2 ] = V_236 -> V_222 ;
V_243 -> V_99 [ 3 ] = V_236 -> V_223 ;
V_243 -> V_99 [ 4 ] = V_236 -> V_228 ;
V_243 -> V_99 [ 5 ] = 0 ;
}
V_33 = F_39 ( V_36 , V_243 , V_237 ,
& V_36 -> V_70 ) ;
if ( V_33 != 0 ) {
if ( V_33 == - V_91 )
F_11 ( L_61 ) ;
else
F_11 ( L_62 ) ;
}
free:
F_20 ( V_48 ) ;
return V_33 ;
}
int F_82 ( struct V_7 * V_36 , T_3 V_232 ,
T_3 V_246 ) {
T_6 V_237 ;
int V_33 ;
void * V_48 ;
struct V_242 {
struct V_129 V_97 ;
T_6 V_99 [ 3 ] ;
} * V_243 ;
if ( ( V_246 > 1 ) || ( V_232 > V_230 ) )
return - V_24 ;
V_237 = sizeof( struct V_129 ) +
( 3 * sizeof( T_6 ) ) ;
V_48 = F_9 ( V_237 + V_96 ,
V_20 | V_78 ) ;
if ( ! V_48 )
return - V_39 ;
V_243 = (struct V_242 * ) F_46 ( V_48 ) ;
V_243 -> V_97 . V_108 = V_177 ;
V_243 -> V_97 . V_109 = V_110 ;
V_243 -> V_97 . V_111 = 0 ;
V_243 -> V_97 . V_112 = V_231 ;
V_243 -> V_97 . V_102 = ( V_136 ) V_237 ;
V_243 -> V_99 [ 0 ] = V_232 ;
V_243 -> V_99 [ 1 ] = V_246 ;
V_33 = F_39 ( V_36 , V_243 , V_237 ,
& V_36 -> V_71 ) ;
if ( V_33 != 0 ) {
if ( V_33 == - V_91 )
F_11 ( L_63 ) ;
else
F_11 ( L_64 ) ;
}
F_20 ( V_48 ) ;
return V_33 ;
}
int F_83 ( struct V_7 * V_36 , T_3 V_232 ,
T_3 * V_229 ) {
T_6 V_237 ;
int V_33 ;
void * V_48 ;
struct V_242 {
struct V_129 V_97 ;
T_6 V_99 [ 2 ] ;
} * V_243 ;
if ( V_232 > V_230 )
return - V_24 ;
V_237 = sizeof( struct V_129 ) + ( 2 * sizeof( T_6 ) ) ;
V_48 = F_9 ( V_237 + V_96 ,
V_20 | V_78 ) ;
if ( ! V_48 )
return - V_39 ;
V_243 = (struct V_242 * ) F_46 ( V_48 ) ;
V_243 -> V_97 . V_108 = V_177 ;
V_243 -> V_97 . V_109 = V_110 ;
V_243 -> V_97 . V_111 = 0 ;
V_243 -> V_97 . V_112 = V_247 ;
V_243 -> V_97 . V_102 = ( V_136 ) V_237 ;
V_243 -> V_99 [ 0 ] = V_232 ;
V_243 -> V_99 [ 1 ] = 0 ;
V_33 = F_39 ( V_36 , V_243 , V_237 ,
& V_36 -> V_72 ) ;
if ( V_33 != 0 ) {
if ( V_33 == - V_91 )
F_11 ( L_65 ) ;
else
F_11 ( L_66 ) ;
}
F_20 ( V_48 ) ;
* V_229 = V_36 -> V_205 ;
return V_33 ;
}
static int T_8 F_84 ( void )
{
F_31 ( & V_38 ) ;
F_31 ( & V_35 ) ;
F_85 ( & V_34 ) ;
F_31 ( & V_19 ) ;
F_85 ( & V_18 ) ;
return 0 ;
}
static void T_9 F_86 ( void )
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
F_38 ( L_67 ) ;
}
