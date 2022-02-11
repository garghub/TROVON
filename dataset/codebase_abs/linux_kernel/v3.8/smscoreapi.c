void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = V_3 ;
}
int F_2 ( struct V_1 * V_2 , int V_5 )
{
if ( V_5 >= 0 )
V_2 -> V_6 = V_5 ;
return V_2 -> V_6 ;
}
int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 ;
}
static struct V_7 * F_4 ( char * V_8 )
{
struct V_7 * V_9 ;
struct V_10 * V_11 ;
F_5 ( & V_12 ) ;
for ( V_11 = V_13 . V_11 ;
V_11 != & V_13 ;
V_11 = V_11 -> V_11 ) {
V_9 = (struct V_7 * ) V_11 ;
if ( ! strcmp ( V_9 -> V_8 , V_8 ) ) {
F_6 ( & V_12 ) ;
return V_9 ;
}
}
V_9 = F_7 ( sizeof( struct V_7 ) , V_14 ) ;
if ( V_9 ) {
V_9 -> V_15 = V_16 ;
strcpy ( V_9 -> V_8 , V_8 ) ;
F_8 ( & V_9 -> V_9 , & V_13 ) ;
} else
F_9 ( L_1 ) ;
F_6 ( & V_12 ) ;
return V_9 ;
}
int F_10 ( char * V_8 )
{
struct V_7 * V_9 ;
V_9 = F_4 ( V_8 ) ;
if ( V_9 )
return V_9 -> V_15 ;
else
F_9 ( L_2 ) ;
return V_16 ;
}
static enum V_17 F_11 ( char * V_8 )
{
struct V_7 * V_9 ;
V_9 = F_4 ( V_8 ) ;
if ( V_9 )
return V_9 -> type ;
else
F_9 ( L_2 ) ;
return - 1 ;
}
void F_12 ( char * V_8 , int V_15 )
{
struct V_7 * V_9 ;
V_9 = F_4 ( V_8 ) ;
if ( V_9 )
V_9 -> V_15 = V_15 ;
else
F_9 ( L_2 ) ;
}
static void F_13 ( char * V_8 ,
enum V_17 type )
{
struct V_7 * V_9 ;
V_9 = F_4 ( V_8 ) ;
if ( V_9 )
V_9 -> type = type ;
else
F_9 ( L_2 ) ;
}
static void F_14 ( struct V_10 * V_18 , struct V_10 * V_19 ,
T_1 * V_20 )
{
unsigned long V_21 ;
F_15 ( V_20 , V_21 ) ;
F_8 ( V_18 , V_19 ) ;
F_16 ( V_20 , V_21 ) ;
}
int F_17 ( T_2 V_22 )
{
struct V_23 * V_24 ;
struct V_10 * V_11 , * V_25 ;
int V_26 = 0 ;
F_5 ( & V_27 ) ;
V_24 = F_7 ( sizeof( struct V_23 ) ,
V_14 ) ;
if ( V_24 ) {
V_25 = & V_28 ;
for ( V_11 = V_25 -> V_11 ;
V_11 != V_25 && ! V_26 ;
V_11 = V_11 -> V_11 ) {
struct V_1 * V_29 =
(struct V_1 * ) V_11 ;
V_26 = V_22 ( V_29 , V_29 -> V_30 , 1 ) ;
}
if ( V_26 >= 0 ) {
V_24 -> V_22 = V_22 ;
F_8 ( & V_24 -> V_9 , & V_31 ) ;
} else
F_18 ( V_24 ) ;
} else
V_26 = - V_32 ;
F_6 ( & V_27 ) ;
return V_26 ;
}
void F_19 ( T_2 V_22 )
{
struct V_10 * V_11 , * V_25 ;
F_5 ( & V_27 ) ;
V_25 = & V_31 ;
for ( V_11 = V_25 -> V_11 ; V_11 != V_25 ; ) {
struct V_23 * V_24 =
(struct V_23 * ) V_11 ;
V_11 = V_11 -> V_11 ;
if ( V_24 -> V_22 == V_22 ) {
F_20 ( & V_24 -> V_9 ) ;
F_18 ( V_24 ) ;
}
}
F_6 ( & V_27 ) ;
}
static void F_21 ( struct V_1 * V_29 )
{
struct V_33 * V_34 ;
while ( ! F_22 ( & V_29 -> V_35 ) ) {
V_34 = (struct V_33 * ) V_29 -> V_35 . V_11 ;
V_34 -> V_36 ( V_34 -> V_37 ) ;
}
}
static int F_23 ( struct V_1 * V_29 ,
struct V_30 * V_30 , int V_38 )
{
struct V_23 * V_39 ;
int V_26 = 0 ;
F_24 (elem, &g_smscore_notifyees, entry) {
V_26 = V_39 -> V_22 ( V_29 , V_30 , V_38 ) ;
if ( V_26 < 0 )
break;
}
return V_26 ;
}
static struct
V_40 * F_25 ( T_3 * V_41 , void * V_42 ,
T_4 V_43 )
{
struct V_40 * V_44 =
F_7 ( sizeof( struct V_40 ) , V_14 ) ;
if ( ! V_44 ) {
F_26 ( L_3 ) ;
return NULL ;
}
V_44 -> V_45 = V_41 ;
V_44 -> V_46 = V_41 - ( T_3 * ) V_42 ;
V_44 -> V_47 = V_43 + V_44 -> V_46 ;
return V_44 ;
}
int F_27 ( struct V_48 * V_49 ,
struct V_1 * * V_29 )
{
struct V_1 * V_50 ;
T_3 * V_41 ;
V_50 = F_28 ( sizeof( struct V_1 ) , V_14 ) ;
if ( ! V_50 ) {
F_26 ( L_4 ) ;
return - V_32 ;
}
F_29 ( & V_50 -> V_9 ) ;
F_29 ( & V_50 -> V_35 ) ;
F_29 ( & V_50 -> V_51 ) ;
F_30 ( & V_50 -> V_52 ) ;
F_30 ( & V_50 -> V_53 ) ;
F_31 ( & V_50 -> V_54 ) ;
F_31 ( & V_50 -> V_55 ) ;
F_31 ( & V_50 -> V_56 ) ;
F_31 ( & V_50 -> V_57 ) ;
F_31 ( & V_50 -> V_58 ) ;
F_31 ( & V_50 -> V_59 ) ;
F_31 ( & V_50 -> V_60 ) ;
F_31 ( & V_50 -> V_61 ) ;
F_31 ( & V_50 -> V_62 ) ;
F_31 ( & V_50 -> V_63 ) ;
F_32 ( & V_50 -> V_64 ) ;
V_50 -> V_65 = V_49 -> V_66 * V_49 -> V_67 ;
V_50 -> V_42 = F_33 ( NULL , V_50 -> V_65 ,
& V_50 -> V_43 ,
V_14 | V_68 ) ;
if ( ! V_50 -> V_42 ) {
F_34 ( V_50 ) ;
return - V_32 ;
}
for ( V_41 = V_50 -> V_42 ;
V_50 -> V_67 < V_49 -> V_67 ;
V_50 -> V_67 ++ , V_41 += V_49 -> V_66 ) {
struct V_40 * V_44 =
F_25 ( V_41 , V_50 -> V_42 ,
V_50 -> V_43 ) ;
if ( ! V_44 ) {
F_34 ( V_50 ) ;
return - V_32 ;
}
F_35 ( V_50 , V_44 ) ;
}
F_26 ( L_5 , V_50 -> V_67 ) ;
V_50 -> V_15 = V_69 ;
V_50 -> V_37 = V_49 -> V_37 ;
V_50 -> V_30 = V_49 -> V_30 ;
V_50 -> V_70 = V_49 -> V_70 ;
V_50 -> V_71 = V_49 -> V_71 ;
V_50 -> V_72 = V_49 -> V_72 ;
V_50 -> V_73 = V_49 -> V_73 ;
V_50 -> V_74 = V_49 -> V_74 ;
V_50 -> V_75 = V_49 -> V_21 ;
strcpy ( V_50 -> V_8 , V_49 -> V_8 ) ;
F_13 ( V_50 -> V_8 , V_49 -> V_76 ) ;
F_5 ( & V_27 ) ;
F_8 ( & V_50 -> V_9 , & V_28 ) ;
F_6 ( & V_27 ) ;
* V_29 = V_50 ;
F_26 ( L_6 , V_50 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_29 ,
void * V_41 , T_5 V_77 , struct V_78 * V_78 ) {
int V_26 = V_29 -> V_72 ( V_29 -> V_37 , V_41 , V_77 ) ;
if ( V_26 < 0 ) {
F_26 ( L_7 , V_26 ) ;
return V_26 ;
}
return F_37 ( V_78 ,
F_38 ( V_79 ) ) ?
0 : - V_80 ;
}
static int F_39 ( struct V_1 * V_29 )
{
int V_81 ;
int V_26 ;
void * V_41 ;
V_29 -> V_82 . V_50 = NULL ;
V_81 = F_40 ( F_3 ( V_29 ) ) -> V_83 . V_82 ;
if ( V_81 ) {
F_26 ( L_8 ) ;
V_26 = F_41 ( V_29 ) ;
if ( V_26 != 0 )
F_9 ( L_9 ) ;
else {
V_41 = F_7 ( sizeof( struct V_84 ) +
V_85 ,
V_14 | V_68 ) ;
if ( V_41 ) {
struct V_84 * V_86 =
(struct V_84 * )
F_42 ( V_41 ) ;
F_43 ( & V_86 -> V_87 ,
V_88 ,
sizeof( struct V_84 ) ) ;
V_86 -> V_89 [ 0 ] = V_29 -> V_82 . V_90 ;
V_86 -> V_89 [ 1 ] = V_29 -> V_82 . V_91 ;
F_44 (
(struct V_92 * ) V_86 ) ;
V_26 = F_36 ( V_29 , V_86 ,
V_86 -> V_87 . V_93 ,
& V_29 -> V_63 ) ;
F_18 ( V_41 ) ;
} else
F_9
( L_10 ) ;
}
} else
F_26 ( L_11 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_29 )
{
int V_26 = F_46 (
V_29 , F_10 ( V_29 -> V_8 ) ) ;
if ( V_26 < 0 ) {
F_26 ( L_12 , V_26 ) ;
return V_26 ;
}
F_5 ( & V_27 ) ;
V_26 = F_23 ( V_29 , V_29 -> V_30 , 1 ) ;
F_39 ( V_29 ) ;
F_26 ( L_13 , V_29 , V_26 ) ;
F_6 ( & V_27 ) ;
return V_26 ;
}
static int F_47 ( struct V_1 * V_29 ,
void * V_41 , T_5 V_77 )
{
struct V_94 * V_95 = (struct V_94 * ) V_41 ;
struct V_96 * V_86 ;
T_6 V_97 ;
T_3 * V_98 = V_95 -> V_99 ;
int V_26 = 0 ;
V_95 -> V_100 = F_48 ( V_95 -> V_100 ) ;
V_95 -> V_101 = F_48 ( V_95 -> V_101 ) ;
V_97 = V_95 -> V_100 ;
F_26 ( L_14 ,
V_97 , V_95 -> V_101 ) ;
if ( V_29 -> V_73 ) {
V_26 = V_29 -> V_73 ( V_29 -> V_37 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_86 = F_7 ( V_102 , V_14 | V_68 ) ;
if ( ! V_86 )
return - V_32 ;
if ( V_29 -> V_15 != V_69 ) {
F_49 ( L_15 ) ;
F_43 ( V_86 , V_103 ,
sizeof( struct V_96 ) ) ;
V_26 = F_36 ( V_29 , V_86 ,
V_86 -> V_93 ,
& V_29 -> V_58 ) ;
V_97 = * ( T_6 * ) & V_98 [ 20 ] ;
}
while ( V_77 && V_26 >= 0 ) {
struct V_104 * V_105 =
(struct V_104 * ) V_86 ;
int V_106 = F_50 ( ( int ) V_77 , V_107 ) ;
F_43 ( V_86 , V_108 ,
( V_109 ) ( sizeof( struct V_96 ) +
sizeof( T_6 ) + V_106 ) ) ;
V_105 -> V_110 = V_97 ;
memcpy ( V_105 -> V_99 , V_98 , V_106 ) ;
if ( ( V_29 -> V_75 & V_111 ) &&
( V_29 -> V_15 == V_69 ) )
V_26 = V_29 -> V_72 (
V_29 -> V_37 , V_105 ,
V_105 -> V_87 . V_93 ) ;
else
V_26 = F_36 (
V_29 , V_105 ,
V_105 -> V_87 . V_93 ,
& V_29 -> V_55 ) ;
V_98 += V_106 ;
V_77 -= V_106 ;
V_97 += V_106 ;
}
if ( V_26 >= 0 ) {
if ( V_29 -> V_15 == V_69 ) {
struct V_112 * V_113 =
(struct V_112 * ) V_86 ;
F_43 ( V_86 , V_114 ,
sizeof( struct V_96 ) +
sizeof( T_6 ) * 5 ) ;
V_113 -> V_89 [ 0 ] = V_95 -> V_100 ;
V_113 -> V_89 [ 1 ] = 5 ;
V_113 -> V_89 [ 2 ] = 0x200 ;
V_113 -> V_89 [ 3 ] = 0 ;
V_113 -> V_89 [ 4 ] = 4 ;
if ( V_29 -> V_75 & V_111 ) {
V_26 = V_29 -> V_72 (
V_29 -> V_37 , V_113 ,
V_113 -> V_87 . V_93 ) ;
F_51 ( 100 ) ;
} else
V_26 = F_36 (
V_29 , V_113 ,
V_113 -> V_87 . V_93 ,
& V_29 -> V_56 ) ;
} else {
F_43 ( V_86 , V_115 ,
sizeof( struct V_96 ) ) ;
V_26 = V_29 -> V_72 ( V_29 -> V_37 ,
V_86 , V_86 -> V_93 ) ;
}
F_51 ( 500 ) ;
}
F_49 ( L_16 , V_26 ,
V_29 -> V_74 ) ;
F_18 ( V_86 ) ;
return ( ( V_26 >= 0 ) && V_29 -> V_74 ) ?
V_29 -> V_74 ( V_29 -> V_37 ) :
V_26 ;
}
static int F_52 ( struct V_1 * V_29 ,
char * V_116 ,
T_7 V_117 )
{
int V_26 = - V_118 ;
const struct V_95 * V_119 ;
T_3 * V_120 ;
if ( V_117 == NULL && ! ( V_29 -> V_75 &
V_121 ) )
return - V_122 ;
V_26 = F_53 ( & V_119 , V_116 , V_29 -> V_30 ) ;
if ( V_26 < 0 ) {
F_26 ( L_17 , V_116 ) ;
return V_26 ;
}
F_26 ( L_18 , V_116 , V_119 -> V_77 ) ;
V_120 = F_7 ( F_54 ( V_119 -> V_77 , V_123 ) ,
V_14 | V_68 ) ;
if ( V_120 ) {
memcpy ( V_120 , V_119 -> V_124 , V_119 -> V_77 ) ;
V_26 = ( V_29 -> V_75 & V_121 ) ?
F_47 ( V_29 ,
V_120 ,
V_119 -> V_77 ) :
V_117 ( V_29 -> V_37 ,
V_120 , V_119 -> V_77 ) ;
F_18 ( V_120 ) ;
} else {
F_26 ( L_19 ) ;
V_26 = - V_32 ;
}
F_55 ( V_119 ) ;
return V_26 ;
}
void F_34 ( struct V_1 * V_29 )
{
struct V_40 * V_44 ;
int V_67 = 0 ;
int V_125 = 0 ;
F_5 ( & V_27 ) ;
F_56 ( V_29 ) ;
F_21 ( V_29 ) ;
F_23 ( V_29 , NULL , 0 ) ;
while ( 1 ) {
while ( ! F_22 ( & V_29 -> V_51 ) ) {
V_44 = (struct V_40 * ) V_29 -> V_51 . V_11 ;
F_20 ( & V_44 -> V_9 ) ;
F_18 ( V_44 ) ;
V_67 ++ ;
}
if ( V_67 == V_29 -> V_67 )
break;
if ( ++ V_125 > 10 ) {
F_26 ( L_20
L_21 ) ;
break;
}
F_26 ( L_22 ,
V_29 -> V_67 - V_67 ) ;
F_51 ( 100 ) ;
}
F_26 ( L_23 , V_67 ) ;
if ( V_29 -> V_42 )
F_57 ( NULL , V_29 -> V_65 ,
V_29 -> V_42 , V_29 -> V_43 ) ;
if ( V_29 -> V_126 != NULL )
F_18 ( V_29 -> V_126 ) ;
F_20 ( & V_29 -> V_9 ) ;
F_18 ( V_29 ) ;
F_6 ( & V_27 ) ;
F_26 ( L_24 , V_29 ) ;
}
static int F_58 ( struct V_1 * V_29 )
{
void * V_41 = F_7 ( sizeof( struct V_96 ) + V_85 ,
V_14 | V_68 ) ;
struct V_96 * V_86 =
(struct V_96 * ) F_42 ( V_41 ) ;
int V_26 ;
if ( ! V_41 )
return - V_32 ;
F_43 ( V_86 , V_127 ,
sizeof( struct V_96 ) ) ;
V_26 = F_36 ( V_29 , V_86 , V_86 -> V_93 ,
& V_29 -> V_54 ) ;
if ( V_26 == - V_80 ) {
F_9 ( L_25 ) ;
if ( F_37 ( & V_29 -> V_59 ,
F_38 ( 5000 ) ) ) {
V_26 = F_36 (
V_29 , V_86 , V_86 -> V_93 ,
& V_29 -> V_54 ) ;
if ( V_26 < 0 )
F_9 ( L_26
L_27 , V_26 ) ;
} else
V_26 = - V_80 ;
}
F_18 ( V_41 ) ;
return V_26 ;
}
static inline char * F_59 ( struct V_1 * V_29 ,
int V_15 , enum V_17 type )
{
char * * V_119 = F_40 ( F_3 ( V_29 ) ) -> V_119 ;
return ( V_119 && V_119 [ V_15 ] ) ? V_119 [ V_15 ] : V_128 [ V_15 ] [ type ] ;
}
int F_46 ( struct V_1 * V_29 , int V_15 )
{
void * V_41 ;
int V_26 = 0 ;
enum V_17 type ;
F_49 ( L_28 , V_15 ) ;
if ( V_29 -> V_75 & V_121 ) {
if ( V_15 < V_129 || V_15 >= V_130 ) {
F_9 ( L_29 , V_15 ) ;
return - V_122 ;
}
F_12 ( V_29 -> V_8 , V_15 ) ;
if ( ! ( V_29 -> V_75 & V_131 ) ) {
V_26 = F_58 ( V_29 ) ;
if ( V_26 < 0 ) {
F_9 ( L_30 , V_26 ) ;
return V_26 ;
}
}
if ( V_29 -> V_15 == V_15 ) {
F_26 ( L_31 , V_15 ) ;
return 0 ;
}
if ( ! ( V_29 -> V_132 & ( 1 << V_15 ) ) ) {
char * V_133 ;
type = F_11 ( V_29 -> V_8 ) ;
V_133 = F_59 ( V_29 , V_15 , type ) ;
V_26 = F_52 ( V_29 ,
V_133 , NULL ) ;
if ( V_26 < 0 ) {
F_60 ( L_32
L_33 ,
V_26 , V_133 ) ;
V_133 = V_128 [ V_15 ] [ type ] ;
V_26 = F_52 ( V_29 ,
V_133 , NULL ) ;
if ( V_26 < 0 ) {
F_60 ( L_34
L_35 , V_26 ,
V_133 ) ;
return V_26 ;
}
}
F_61 ( L_36 , V_133 ) ;
} else
F_26 ( L_37
L_38 , V_15 ) ;
V_41 = F_7 ( sizeof( struct V_112 ) +
V_85 , V_14 | V_68 ) ;
if ( V_41 ) {
struct V_112 * V_86 =
(struct V_112 * )
F_42 ( V_41 ) ;
F_43 ( & V_86 -> V_87 , V_134 ,
sizeof( struct V_112 ) ) ;
V_86 -> V_89 [ 0 ] = V_15 ;
V_26 = F_36 (
V_29 , V_86 , V_86 -> V_87 . V_93 ,
& V_29 -> V_57 ) ;
F_18 ( V_41 ) ;
} else {
F_9 ( L_39
L_40 ) ;
V_26 = - V_32 ;
}
} else {
if ( V_15 < V_129 || V_15 > V_135 ) {
F_9 ( L_29 , V_15 ) ;
return - V_122 ;
}
F_12 ( V_29 -> V_8 , V_15 ) ;
if ( V_29 -> V_71 )
V_29 -> V_71 ( V_29 -> V_37 ,
& V_29 -> V_15 ) ;
if ( V_29 -> V_15 != V_15 && V_29 -> V_70 )
V_26 = V_29 -> V_70 ( V_29 -> V_37 , V_15 ) ;
}
if ( V_26 >= 0 ) {
V_29 -> V_15 = V_15 ;
V_29 -> V_75 &= ~ V_131 ;
}
if ( V_26 < 0 )
F_9 ( L_41 , V_26 ) ;
return V_26 ;
}
int F_62 ( struct V_1 * V_29 )
{
return V_29 -> V_15 ;
}
static struct
V_33 * F_63 ( struct V_1 * V_29 ,
int V_136 , int V_3 )
{
struct V_10 * V_25 ;
struct V_33 * V_34 ;
unsigned long V_21 ;
struct V_10 * V_137 ;
struct V_138 * V_139 ;
F_15 ( & V_29 -> V_52 , V_21 ) ;
V_25 = & V_29 -> V_35 ;
F_24 (client, first, entry) {
V_137 = & V_34 -> V_140 ;
F_24 (client_id, firstid, entry) {
if ( ( V_139 -> V_3 == V_3 ) &&
( V_139 -> V_136 == V_136 ||
( V_139 -> V_136 == 0 ) ) )
goto V_141;
}
}
V_34 = NULL ;
V_141:
F_16 ( & V_29 -> V_52 , V_21 ) ;
return V_34 ;
}
void F_64 ( struct V_1 * V_29 ,
struct V_40 * V_44 ) {
struct V_96 * V_142 = (struct V_96 * ) ( ( T_3 * ) V_44 -> V_45
+ V_44 -> V_143 ) ;
struct V_33 * V_34 ;
int V_26 = - V_144 ;
static unsigned long V_145 ;
static int V_146 ;
unsigned long V_147 = F_65 ( V_148 ) ;
if ( ! V_145 )
V_145 = V_147 ;
if ( V_147 - V_145 > 10000 ) {
F_49 ( L_42 ,
( int ) ( ( V_146 * 1000 ) /
( V_147 - V_145 ) ) ) ;
V_145 = V_147 ;
V_146 = 0 ;
}
V_146 += V_44 -> V_77 ;
if ( ( V_142 -> V_149 == V_150 ) ||
( V_142 -> V_149 == V_151 ) ) {
if ( V_29 -> V_15 == V_135 )
V_142 -> V_152 = V_153 ;
}
V_34 = F_63 ( V_29 , V_142 -> V_149 , V_142 -> V_152 ) ;
if ( V_34 )
V_26 = V_34 -> V_154 ( V_34 -> V_37 , V_44 ) ;
if ( V_26 < 0 ) {
switch ( V_142 -> V_149 ) {
case V_155 :
{
struct V_156 * V_157 =
(struct V_156 * ) V_142 ;
F_49 ( L_43
L_44 ,
V_157 -> V_158 , V_157 -> V_159 ,
V_157 -> V_160 , V_157 -> V_161 ) ;
V_29 -> V_15 = V_157 -> V_158 == 255 ?
V_69 : V_157 -> V_158 ;
V_29 -> V_132 = V_157 -> V_159 ;
F_66 ( & V_29 -> V_54 ) ;
break;
}
case V_162 :
F_49 ( L_45 ) ;
F_66 ( & V_29 -> V_57 ) ;
break;
case V_163 :
F_49 ( L_46 ) ;
F_66 ( & V_29 -> V_58 ) ;
break;
case V_164 :
F_66 ( & V_29 -> V_55 ) ;
break;
case V_165 :
F_49 ( L_47 ) ;
break;
case V_166 :
F_49 ( L_48 ) ;
F_66 ( & V_29 -> V_56 ) ;
break;
case V_167 :
F_66 ( & V_29 -> V_59 ) ;
break;
case V_168 :
F_49 ( L_49 ) ;
F_66 ( & V_29 -> V_60 ) ;
break;
case V_169 :
F_49 ( L_50 ) ;
F_66 ( & V_29 -> V_61 ) ;
break;
case V_170 :
{
T_6 * V_171 = ( T_6 * ) V_142 ;
V_29 -> V_172 = V_171 [ 1 ] ;
F_49 ( L_51 ,
V_29 -> V_172 ) ;
F_66 ( & V_29 -> V_62 ) ;
break;
}
case V_173 :
F_66 ( & V_29 -> V_63 ) ;
break;
case V_174 :
F_67 ( V_29 ,
( const char * )
( ( char * ) V_142
+ sizeof( struct V_96 ) ) ,
( int ) V_142 -> V_93
- sizeof( struct V_96 ) ) ;
break;
default:
break;
}
F_35 ( V_29 , V_44 ) ;
}
}
static struct V_40 * F_68 ( struct V_1 * V_29 )
{
struct V_40 * V_44 = NULL ;
unsigned long V_21 ;
F_15 ( & V_29 -> V_53 , V_21 ) ;
if ( ! F_22 ( & V_29 -> V_51 ) ) {
V_44 = (struct V_40 * ) V_29 -> V_51 . V_11 ;
F_20 ( & V_44 -> V_9 ) ;
}
F_16 ( & V_29 -> V_53 , V_21 ) ;
return V_44 ;
}
struct V_40 * F_69 ( struct V_1 * V_29 )
{
struct V_40 * V_44 = NULL ;
F_70 ( V_29 -> V_64 , ( V_44 = F_68 ( V_29 ) ) ) ;
return V_44 ;
}
void F_35 ( struct V_1 * V_29 ,
struct V_40 * V_44 ) {
F_71 ( & V_29 -> V_64 ) ;
F_14 ( & V_44 -> V_9 , & V_29 -> V_51 , & V_29 -> V_53 ) ;
}
static int F_72 ( struct V_1 * V_29 ,
struct V_33 * V_34 ,
int V_136 , int V_3 )
{
struct V_138 * V_175 ;
struct V_33 * V_176 ;
if ( ! V_34 ) {
F_9 ( L_52 ) ;
return - V_122 ;
}
V_176 = F_63 ( V_29 , V_136 , V_3 ) ;
if ( V_176 == V_34 )
return 0 ;
if ( V_176 ) {
F_9 ( L_53 ) ;
return - V_177 ;
}
V_175 = F_28 ( sizeof( struct V_138 ) , V_14 ) ;
if ( ! V_175 ) {
F_9 ( L_54 ) ;
return - V_32 ;
}
V_175 -> V_3 = V_3 ;
V_175 -> V_136 = V_136 ;
F_14 ( & V_175 -> V_9 , & V_34 -> V_140 ,
& V_29 -> V_52 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_29 ,
struct V_178 * V_49 ,
struct V_33 * * V_34 )
{
struct V_33 * V_179 ;
if ( F_63 ( V_29 , V_49 -> V_136 ,
V_49 -> V_180 ) ) {
F_9 ( L_55 ) ;
return - V_177 ;
}
V_179 = F_28 ( sizeof( struct V_33 ) , V_14 ) ;
if ( ! V_179 ) {
F_9 ( L_56 ) ;
return - V_32 ;
}
F_29 ( & V_179 -> V_140 ) ;
V_179 -> V_29 = V_29 ;
V_179 -> V_154 = V_49 -> V_154 ;
V_179 -> V_36 = V_49 -> V_36 ;
V_179 -> V_37 = V_49 -> V_37 ;
F_14 ( & V_179 -> V_9 , & V_29 -> V_35 ,
& V_29 -> V_52 ) ;
F_72 ( V_29 , V_179 , V_49 -> V_136 ,
V_49 -> V_180 ) ;
* V_34 = V_179 ;
F_49 ( L_57 , V_49 -> V_37 , V_49 -> V_136 ,
V_49 -> V_180 ) ;
return 0 ;
}
void F_74 ( struct V_33 * V_34 )
{
struct V_1 * V_29 = V_34 -> V_29 ;
unsigned long V_21 ;
F_15 ( & V_29 -> V_52 , V_21 ) ;
while ( ! F_22 ( & V_34 -> V_140 ) ) {
struct V_138 * V_181 =
(struct V_138 * ) V_34 -> V_140 . V_11 ;
F_20 ( & V_181 -> V_9 ) ;
F_18 ( V_181 ) ;
}
F_26 ( L_58 , V_34 -> V_37 ) ;
F_20 ( & V_34 -> V_9 ) ;
F_18 ( V_34 ) ;
F_16 ( & V_29 -> V_52 , V_21 ) ;
}
int F_75 ( struct V_33 * V_34 ,
void * V_41 , T_5 V_77 )
{
struct V_1 * V_29 ;
struct V_96 * V_142 = (struct V_96 * ) V_41 ;
int V_26 ;
if ( V_34 == NULL ) {
F_9 ( L_59 ) ;
return - V_122 ;
}
V_29 = V_34 -> V_29 ;
if ( V_29 == NULL ) {
F_9 ( L_60 ) ;
return - V_122 ;
}
V_26 = F_72 ( V_34 -> V_29 , V_34 , 0 ,
V_142 -> V_182 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_29 -> V_72 ( V_29 -> V_37 , V_41 , V_77 ) ;
}
int F_76 ( struct V_1 * V_29 , T_6 V_183 ,
struct V_184 * V_185 )
{
struct {
struct V_96 V_186 ;
T_6 V_124 [ 6 ] ;
} V_86 ;
if ( V_29 -> V_75 & V_121 ) {
V_86 . V_186 . V_182 = V_153 ;
V_86 . V_186 . V_152 = V_187 ;
V_86 . V_186 . V_188 = 0 ;
V_86 . V_186 . V_149 = V_189 ;
V_86 . V_186 . V_93 = sizeof( V_86 ) ;
V_86 . V_124 [ 0 ] = V_183 ;
V_86 . V_124 [ 1 ] = V_185 -> V_190 ;
V_86 . V_124 [ 2 ] = V_185 -> V_191 == 0 ? 3 : 0 ;
switch ( V_185 -> V_192 ) {
case V_193 :
V_86 . V_124 [ 3 ] = 7 ;
break;
case V_194 :
V_86 . V_124 [ 3 ] = 5 ;
break;
case V_195 :
V_86 . V_124 [ 3 ] = 3 ;
break;
case V_196 :
default:
V_86 . V_124 [ 3 ] = 2 ;
break;
}
V_86 . V_124 [ 4 ] = V_185 -> V_197 ;
V_86 . V_124 [ 5 ] = 0 ;
} else
return - V_122 ;
return V_29 -> V_72 ( V_29 -> V_37 ,
& V_86 , sizeof( V_86 ) ) ;
}
int F_77 ( struct V_1 * V_29 , T_6 V_183 , int V_198 )
{
struct {
struct V_96 V_186 ;
T_6 V_124 [ 3 ] ;
} V_86 ;
if ( V_183 > V_199 )
return - V_122 ;
V_86 . V_186 . V_182 = V_153 ;
V_86 . V_186 . V_152 = V_187 ;
V_86 . V_186 . V_188 = 0 ;
V_86 . V_186 . V_149 = V_200 ;
V_86 . V_186 . V_93 = sizeof( V_86 ) ;
V_86 . V_124 [ 0 ] = V_183 ;
V_86 . V_124 [ 1 ] = V_198 ? 1 : 0 ;
V_86 . V_124 [ 2 ] = 0 ;
return V_29 -> V_72 ( V_29 -> V_37 ,
& V_86 , sizeof( V_86 ) ) ;
}
static int F_78 ( T_6 V_201 , T_6 * V_202 ,
T_6 * V_203 , T_6 * V_204 ) {
* V_204 = 1 ;
if ( V_201 <= 1 ) {
* V_202 = 0 ;
* V_203 = 9 ;
* V_204 = 2 ;
} else if ( V_201 >= 2 && V_201 <= 6 ) {
* V_202 = 2 ;
* V_203 = 0 ;
* V_204 = 2 ;
} else if ( V_201 >= 7 && V_201 <= 11 ) {
* V_202 = 7 ;
* V_203 = 1 ;
} else if ( V_201 >= 12 && V_201 <= 15 ) {
* V_202 = 12 ;
* V_203 = 2 ;
* V_204 = 3 ;
} else if ( V_201 == 16 ) {
* V_202 = 16 ;
* V_203 = 23 ;
} else if ( V_201 >= 17 && V_201 <= 24 ) {
* V_202 = 17 ;
* V_203 = 3 ;
} else if ( V_201 == 25 ) {
* V_202 = 25 ;
* V_203 = 6 ;
} else if ( V_201 >= 26 && V_201 <= 28 ) {
* V_202 = 26 ;
* V_203 = 4 ;
} else if ( V_201 == 29 ) {
* V_202 = 29 ;
* V_203 = 5 ;
* V_204 = 2 ;
} else if ( V_201 == 30 ) {
* V_202 = 30 ;
* V_203 = 8 ;
} else if ( V_201 == 31 ) {
* V_202 = 31 ;
* V_203 = 17 ;
} else
return - 1 ;
* V_204 <<= 24 ;
return 0 ;
}
int F_79 ( struct V_1 * V_29 , T_3 V_201 ,
struct V_205 * V_206 ) {
T_6 V_207 ;
T_6 V_208 = 0 ;
T_6 V_209 = 0 ;
T_6 V_210 ;
T_6 V_211 ;
void * V_41 ;
int V_26 ;
struct V_212 {
struct V_96 V_87 ;
T_6 V_89 [ 6 ] ;
} * V_213 ;
if ( V_201 > V_199 )
return - V_122 ;
if ( V_206 == NULL )
return - V_122 ;
V_207 = sizeof( struct V_96 ) + ( sizeof( T_6 ) * 6 ) ;
V_41 = F_7 ( V_207 + V_85 ,
V_14 | V_68 ) ;
if ( ! V_41 )
return - V_32 ;
V_213 = (struct V_212 * ) F_42 ( V_41 ) ;
V_213 -> V_87 . V_182 = V_153 ;
V_213 -> V_87 . V_152 = V_187 ;
V_213 -> V_87 . V_188 = 0 ;
V_213 -> V_87 . V_93 = ( V_109 ) V_207 ;
V_213 -> V_89 [ 0 ] = V_201 ;
if ( ! ( V_29 -> V_75 & V_121 ) ) {
V_213 -> V_87 . V_149 = V_214 ;
if ( F_78 ( V_201 , & V_208 , & V_209 ,
& V_211 ) != 0 ) {
V_26 = - V_122 ;
goto free;
}
V_213 -> V_89 [ 1 ] = V_208 ;
V_213 -> V_89 [ 2 ] = V_209 ;
V_210 = ( V_206 -> V_215 )
| ( V_206 -> V_216 << 2 )
| ( V_206 -> V_217 << 3 )
| ( V_206 -> V_218 << 4 ) ;
V_213 -> V_89 [ 3 ] = V_210 ;
V_213 -> V_89 [ 4 ] = V_206 -> V_219 ;
V_213 -> V_89 [ 5 ] = V_211 ;
} else {
V_213 -> V_87 . V_149 = V_189 ;
V_213 -> V_89 [ 1 ] = V_206 -> V_215 ;
V_213 -> V_89 [ 2 ] = V_206 -> V_217 ;
V_213 -> V_89 [ 3 ] = V_206 -> V_218 ;
V_213 -> V_89 [ 4 ] = V_206 -> V_219 ;
V_213 -> V_89 [ 5 ] = 0 ;
}
F_44 ( (struct V_96 * ) V_213 ) ;
V_26 = F_36 ( V_29 , V_213 , V_207 ,
& V_29 -> V_60 ) ;
if ( V_26 != 0 ) {
if ( V_26 == - V_80 )
F_9 ( L_61 ) ;
else
F_9 ( L_62 ) ;
}
free:
F_18 ( V_41 ) ;
return V_26 ;
}
int F_80 ( struct V_1 * V_29 , T_3 V_201 ,
T_3 V_220 ) {
T_6 V_207 ;
int V_26 ;
void * V_41 ;
struct V_212 {
struct V_96 V_87 ;
T_6 V_89 [ 3 ] ;
} * V_213 ;
if ( ( V_220 > 1 ) || ( V_201 > V_199 ) )
return - V_122 ;
V_207 = sizeof( struct V_96 ) +
( 3 * sizeof( T_6 ) ) ;
V_41 = F_7 ( V_207 + V_85 ,
V_14 | V_68 ) ;
if ( ! V_41 )
return - V_32 ;
V_213 = (struct V_212 * ) F_42 ( V_41 ) ;
V_213 -> V_87 . V_182 = V_153 ;
V_213 -> V_87 . V_152 = V_187 ;
V_213 -> V_87 . V_188 = 0 ;
V_213 -> V_87 . V_149 = V_200 ;
V_213 -> V_87 . V_93 = ( V_109 ) V_207 ;
V_213 -> V_89 [ 0 ] = V_201 ;
V_213 -> V_89 [ 1 ] = V_220 ;
F_44 ( (struct V_96 * ) V_213 ) ;
V_26 = F_36 ( V_29 , V_213 , V_207 ,
& V_29 -> V_61 ) ;
if ( V_26 != 0 ) {
if ( V_26 == - V_80 )
F_9 ( L_63 ) ;
else
F_9 ( L_64 ) ;
}
F_18 ( V_41 ) ;
return V_26 ;
}
int F_81 ( struct V_1 * V_29 , T_3 V_201 ,
T_3 * V_198 ) {
T_6 V_207 ;
int V_26 ;
void * V_41 ;
struct V_212 {
struct V_96 V_87 ;
T_6 V_89 [ 2 ] ;
} * V_213 ;
if ( V_201 > V_199 )
return - V_122 ;
V_207 = sizeof( struct V_96 ) + ( 2 * sizeof( T_6 ) ) ;
V_41 = F_7 ( V_207 + V_85 ,
V_14 | V_68 ) ;
if ( ! V_41 )
return - V_32 ;
V_213 = (struct V_212 * ) F_42 ( V_41 ) ;
V_213 -> V_87 . V_182 = V_153 ;
V_213 -> V_87 . V_152 = V_187 ;
V_213 -> V_87 . V_188 = 0 ;
V_213 -> V_87 . V_149 = V_221 ;
V_213 -> V_87 . V_93 = ( V_109 ) V_207 ;
V_213 -> V_89 [ 0 ] = V_201 ;
V_213 -> V_89 [ 1 ] = 0 ;
F_44 ( (struct V_96 * ) V_213 ) ;
V_26 = F_36 ( V_29 , V_213 , V_207 ,
& V_29 -> V_62 ) ;
if ( V_26 != 0 ) {
if ( V_26 == - V_80 )
F_9 ( L_65 ) ;
else
F_9 ( L_66 ) ;
}
F_18 ( V_41 ) ;
* V_198 = V_29 -> V_172 ;
return V_26 ;
}
static int T_8 F_82 ( void )
{
int V_26 = 0 ;
F_29 ( & V_31 ) ;
F_29 ( & V_28 ) ;
F_83 ( & V_27 ) ;
F_29 ( & V_13 ) ;
F_83 ( & V_12 ) ;
return V_26 ;
}
static void T_9 F_84 ( void )
{
F_5 ( & V_27 ) ;
while ( ! F_22 ( & V_31 ) ) {
struct V_23 * V_24 =
(struct V_23 * )
V_31 . V_11 ;
F_20 ( & V_24 -> V_9 ) ;
F_18 ( V_24 ) ;
}
F_6 ( & V_27 ) ;
F_5 ( & V_12 ) ;
while ( ! F_22 ( & V_13 ) ) {
struct V_7 * V_9 =
(struct V_7 * )
V_13 . V_11 ;
F_20 ( & V_9 -> V_9 ) ;
F_18 ( V_9 ) ;
}
F_6 ( & V_12 ) ;
F_49 ( L_67 ) ;
}
