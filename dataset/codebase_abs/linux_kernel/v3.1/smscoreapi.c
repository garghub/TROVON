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
struct V_10 * V_11 , * V_25 ;
int V_26 = 0 ;
V_25 = & V_31 ;
for ( V_11 = V_25 -> V_11 ; V_11 != V_25 ; V_11 = V_11 -> V_11 ) {
V_26 = ( (struct V_23 * ) V_11 ) ->
V_22 ( V_29 , V_30 , V_38 ) ;
if ( V_26 < 0 )
break;
}
return V_26 ;
}
static struct
V_39 * F_24 ( T_3 * V_40 , void * V_41 ,
T_4 V_42 )
{
struct V_39 * V_43 =
F_7 ( sizeof( struct V_39 ) , V_14 ) ;
if ( ! V_43 ) {
F_25 ( L_3 ) ;
return NULL ;
}
V_43 -> V_44 = V_40 ;
V_43 -> V_45 = V_40 - ( T_3 * ) V_41 ;
V_43 -> V_46 = V_42 + V_43 -> V_45 ;
return V_43 ;
}
int F_26 ( struct V_47 * V_48 ,
struct V_1 * * V_29 )
{
struct V_1 * V_49 ;
T_3 * V_40 ;
V_49 = F_27 ( sizeof( struct V_1 ) , V_14 ) ;
if ( ! V_49 ) {
F_25 ( L_4 ) ;
return - V_32 ;
}
F_28 ( & V_49 -> V_9 ) ;
F_28 ( & V_49 -> V_35 ) ;
F_28 ( & V_49 -> V_50 ) ;
F_29 ( & V_49 -> V_51 ) ;
F_29 ( & V_49 -> V_52 ) ;
F_30 ( & V_49 -> V_53 ) ;
F_30 ( & V_49 -> V_54 ) ;
F_30 ( & V_49 -> V_55 ) ;
F_30 ( & V_49 -> V_56 ) ;
F_30 ( & V_49 -> V_57 ) ;
F_30 ( & V_49 -> V_58 ) ;
F_30 ( & V_49 -> V_59 ) ;
F_30 ( & V_49 -> V_60 ) ;
F_30 ( & V_49 -> V_61 ) ;
F_30 ( & V_49 -> V_62 ) ;
F_31 ( & V_49 -> V_63 ) ;
V_49 -> V_64 = V_48 -> V_65 * V_48 -> V_66 ;
V_49 -> V_41 = F_32 ( NULL , V_49 -> V_64 ,
& V_49 -> V_42 ,
V_14 | V_67 ) ;
if ( ! V_49 -> V_41 ) {
F_33 ( V_49 ) ;
return - V_32 ;
}
for ( V_40 = V_49 -> V_41 ;
V_49 -> V_66 < V_48 -> V_66 ;
V_49 -> V_66 ++ , V_40 += V_48 -> V_65 ) {
struct V_39 * V_43 =
F_24 ( V_40 , V_49 -> V_41 ,
V_49 -> V_42 ) ;
if ( ! V_43 ) {
F_33 ( V_49 ) ;
return - V_32 ;
}
F_34 ( V_49 , V_43 ) ;
}
F_25 ( L_5 , V_49 -> V_66 ) ;
V_49 -> V_15 = V_68 ;
V_49 -> V_37 = V_48 -> V_37 ;
V_49 -> V_30 = V_48 -> V_30 ;
V_49 -> V_69 = V_48 -> V_69 ;
V_49 -> V_70 = V_48 -> V_70 ;
V_49 -> V_71 = V_48 -> V_71 ;
V_49 -> V_72 = V_48 -> V_72 ;
V_49 -> V_73 = V_48 -> V_73 ;
V_49 -> V_74 = V_48 -> V_21 ;
strcpy ( V_49 -> V_8 , V_48 -> V_8 ) ;
F_13 ( V_49 -> V_8 , V_48 -> V_75 ) ;
F_5 ( & V_27 ) ;
F_8 ( & V_49 -> V_9 , & V_28 ) ;
F_6 ( & V_27 ) ;
* V_29 = V_49 ;
F_25 ( L_6 , V_49 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_29 ,
void * V_40 , T_5 V_76 , struct V_77 * V_77 ) {
int V_26 = V_29 -> V_71 ( V_29 -> V_37 , V_40 , V_76 ) ;
if ( V_26 < 0 ) {
F_25 ( L_7 , V_26 ) ;
return V_26 ;
}
return F_36 ( V_77 ,
F_37 ( V_78 ) ) ?
0 : - V_79 ;
}
static int F_38 ( struct V_1 * V_29 )
{
int V_80 ;
int V_26 ;
void * V_40 ;
V_29 -> V_81 . V_49 = NULL ;
V_80 = F_39 ( F_3 ( V_29 ) ) -> V_82 . V_81 ;
if ( V_80 ) {
F_25 ( L_8 ) ;
V_26 = F_40 ( V_29 ) ;
if ( V_26 != 0 )
F_9 ( L_9 ) ;
else {
V_40 = F_7 ( sizeof( struct V_83 ) +
V_84 ,
V_14 | V_67 ) ;
if ( V_40 ) {
struct V_83 * V_85 =
(struct V_83 * )
F_41 ( V_40 ) ;
F_42 ( & V_85 -> V_86 ,
V_87 ,
sizeof( struct V_83 ) ) ;
V_85 -> V_88 [ 0 ] = V_29 -> V_81 . V_89 ;
V_85 -> V_88 [ 1 ] = V_29 -> V_81 . V_90 ;
F_43 (
(struct V_91 * ) V_85 ) ;
V_26 = F_35 ( V_29 , V_85 ,
V_85 -> V_86 . V_92 ,
& V_29 -> V_62 ) ;
F_18 ( V_40 ) ;
} else
F_9
( L_10 ) ;
}
} else
F_25 ( L_11 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_29 )
{
int V_26 = F_45 (
V_29 , F_10 ( V_29 -> V_8 ) ) ;
if ( V_26 < 0 ) {
F_25 ( L_12 , V_26 ) ;
return V_26 ;
}
F_5 ( & V_27 ) ;
V_26 = F_23 ( V_29 , V_29 -> V_30 , 1 ) ;
F_38 ( V_29 ) ;
F_25 ( L_13 , V_29 , V_26 ) ;
F_6 ( & V_27 ) ;
return V_26 ;
}
static int F_46 ( struct V_1 * V_29 ,
void * V_40 , T_5 V_76 )
{
struct V_93 * V_94 = (struct V_93 * ) V_40 ;
struct V_95 * V_85 ;
T_6 V_96 ;
T_3 * V_97 = V_94 -> V_98 ;
int V_26 = 0 ;
V_94 -> V_99 = F_47 ( V_94 -> V_99 ) ;
V_94 -> V_100 = F_47 ( V_94 -> V_100 ) ;
V_96 = V_94 -> V_99 ;
F_25 ( L_14 ,
V_96 , V_94 -> V_100 ) ;
if ( V_29 -> V_72 ) {
V_26 = V_29 -> V_72 ( V_29 -> V_37 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_85 = F_7 ( V_101 , V_14 | V_67 ) ;
if ( ! V_85 )
return - V_32 ;
if ( V_29 -> V_15 != V_68 ) {
F_48 ( L_15 ) ;
F_42 ( V_85 , V_102 ,
sizeof( struct V_95 ) ) ;
V_26 = F_35 ( V_29 , V_85 ,
V_85 -> V_92 ,
& V_29 -> V_57 ) ;
V_96 = * ( T_6 * ) & V_97 [ 20 ] ;
}
while ( V_76 && V_26 >= 0 ) {
struct V_103 * V_104 =
(struct V_103 * ) V_85 ;
int V_105 = F_49 ( ( int ) V_76 , V_106 ) ;
F_42 ( V_85 , V_107 ,
( V_108 ) ( sizeof( struct V_95 ) +
sizeof( T_6 ) + V_105 ) ) ;
V_104 -> V_109 = V_96 ;
memcpy ( V_104 -> V_98 , V_97 , V_105 ) ;
if ( ( V_29 -> V_74 & V_110 ) &&
( V_29 -> V_15 == V_68 ) )
V_26 = V_29 -> V_71 (
V_29 -> V_37 , V_104 ,
V_104 -> V_86 . V_92 ) ;
else
V_26 = F_35 (
V_29 , V_104 ,
V_104 -> V_86 . V_92 ,
& V_29 -> V_54 ) ;
V_97 += V_105 ;
V_76 -= V_105 ;
V_96 += V_105 ;
}
if ( V_26 >= 0 ) {
if ( V_29 -> V_15 == V_68 ) {
struct V_111 * V_112 =
(struct V_111 * ) V_85 ;
F_42 ( V_85 , V_113 ,
sizeof( struct V_95 ) +
sizeof( T_6 ) * 5 ) ;
V_112 -> V_88 [ 0 ] = V_94 -> V_99 ;
V_112 -> V_88 [ 1 ] = 5 ;
V_112 -> V_88 [ 2 ] = 0x200 ;
V_112 -> V_88 [ 3 ] = 0 ;
V_112 -> V_88 [ 4 ] = 4 ;
if ( V_29 -> V_74 & V_110 ) {
V_26 = V_29 -> V_71 (
V_29 -> V_37 , V_112 ,
V_112 -> V_86 . V_92 ) ;
F_50 ( 100 ) ;
} else
V_26 = F_35 (
V_29 , V_112 ,
V_112 -> V_86 . V_92 ,
& V_29 -> V_55 ) ;
} else {
F_42 ( V_85 , V_114 ,
sizeof( struct V_95 ) ) ;
V_26 = V_29 -> V_71 ( V_29 -> V_37 ,
V_85 , V_85 -> V_92 ) ;
}
F_50 ( 500 ) ;
}
F_48 ( L_16 , V_26 ,
V_29 -> V_73 ) ;
F_18 ( V_85 ) ;
return ( ( V_26 >= 0 ) && V_29 -> V_73 ) ?
V_29 -> V_73 ( V_29 -> V_37 ) :
V_26 ;
}
static int F_51 ( struct V_1 * V_29 ,
char * V_115 ,
T_7 V_116 )
{
int V_26 = - V_117 ;
const struct V_94 * V_118 ;
T_3 * V_119 ;
if ( V_116 == NULL && ! ( V_29 -> V_74 &
V_120 ) )
return - V_121 ;
V_26 = F_52 ( & V_118 , V_115 , V_29 -> V_30 ) ;
if ( V_26 < 0 ) {
F_25 ( L_17 , V_115 ) ;
return V_26 ;
}
F_25 ( L_18 , V_115 , V_118 -> V_76 ) ;
V_119 = F_7 ( F_53 ( V_118 -> V_76 , V_122 ) ,
V_14 | V_67 ) ;
if ( V_119 ) {
memcpy ( V_119 , V_118 -> V_123 , V_118 -> V_76 ) ;
V_26 = ( V_29 -> V_74 & V_120 ) ?
F_46 ( V_29 ,
V_119 ,
V_118 -> V_76 ) :
V_116 ( V_29 -> V_37 ,
V_119 , V_118 -> V_76 ) ;
F_18 ( V_119 ) ;
} else {
F_25 ( L_19 ) ;
V_26 = - V_32 ;
}
F_54 ( V_118 ) ;
return V_26 ;
}
void F_33 ( struct V_1 * V_29 )
{
struct V_39 * V_43 ;
int V_66 = 0 ;
int V_124 = 0 ;
F_5 ( & V_27 ) ;
F_55 ( V_29 ) ;
F_21 ( V_29 ) ;
F_23 ( V_29 , NULL , 0 ) ;
while ( 1 ) {
while ( ! F_22 ( & V_29 -> V_50 ) ) {
V_43 = (struct V_39 * ) V_29 -> V_50 . V_11 ;
F_20 ( & V_43 -> V_9 ) ;
F_18 ( V_43 ) ;
V_66 ++ ;
}
if ( V_66 == V_29 -> V_66 )
break;
if ( ++ V_124 > 10 ) {
F_25 ( L_20
L_21 ) ;
break;
}
F_25 ( L_22 ,
V_29 -> V_66 - V_66 ) ;
F_50 ( 100 ) ;
}
F_25 ( L_23 , V_66 ) ;
if ( V_29 -> V_41 )
F_56 ( NULL , V_29 -> V_64 ,
V_29 -> V_41 , V_29 -> V_42 ) ;
if ( V_29 -> V_125 != NULL )
F_18 ( V_29 -> V_125 ) ;
F_20 ( & V_29 -> V_9 ) ;
F_18 ( V_29 ) ;
F_6 ( & V_27 ) ;
F_25 ( L_24 , V_29 ) ;
}
static int F_57 ( struct V_1 * V_29 )
{
void * V_40 = F_7 ( sizeof( struct V_95 ) + V_84 ,
V_14 | V_67 ) ;
struct V_95 * V_85 =
(struct V_95 * ) F_41 ( V_40 ) ;
int V_26 ;
if ( ! V_40 )
return - V_32 ;
F_42 ( V_85 , V_126 ,
sizeof( struct V_95 ) ) ;
V_26 = F_35 ( V_29 , V_85 , V_85 -> V_92 ,
& V_29 -> V_53 ) ;
if ( V_26 == - V_79 ) {
F_9 ( L_25 ) ;
if ( F_36 ( & V_29 -> V_58 ,
F_37 ( 5000 ) ) ) {
V_26 = F_35 (
V_29 , V_85 , V_85 -> V_92 ,
& V_29 -> V_53 ) ;
if ( V_26 < 0 )
F_9 ( L_26
L_27 , V_26 ) ;
} else
V_26 = - V_79 ;
}
F_18 ( V_40 ) ;
return V_26 ;
}
static inline char * F_58 ( struct V_1 * V_29 ,
int V_15 , enum V_17 type )
{
char * * V_118 = F_39 ( F_3 ( V_29 ) ) -> V_118 ;
return ( V_118 && V_118 [ V_15 ] ) ? V_118 [ V_15 ] : V_127 [ V_15 ] [ type ] ;
}
int F_45 ( struct V_1 * V_29 , int V_15 )
{
void * V_40 ;
int V_26 = 0 ;
enum V_17 type ;
F_48 ( L_28 , V_15 ) ;
if ( V_29 -> V_74 & V_120 ) {
if ( V_15 < V_128 || V_15 >= V_129 ) {
F_9 ( L_29 , V_15 ) ;
return - V_121 ;
}
F_12 ( V_29 -> V_8 , V_15 ) ;
if ( ! ( V_29 -> V_74 & V_130 ) ) {
V_26 = F_57 ( V_29 ) ;
if ( V_26 < 0 ) {
F_9 ( L_30 , V_26 ) ;
return V_26 ;
}
}
if ( V_29 -> V_15 == V_15 ) {
F_25 ( L_31 , V_15 ) ;
return 0 ;
}
if ( ! ( V_29 -> V_131 & ( 1 << V_15 ) ) ) {
char * V_132 ;
type = F_11 ( V_29 -> V_8 ) ;
V_132 = F_58 ( V_29 , V_15 , type ) ;
V_26 = F_51 ( V_29 ,
V_132 , NULL ) ;
if ( V_26 < 0 ) {
F_59 ( L_32
L_33 ,
V_26 , V_132 ) ;
V_132 = V_127 [ V_15 ] [ type ] ;
V_26 = F_51 ( V_29 ,
V_132 , NULL ) ;
if ( V_26 < 0 ) {
F_59 ( L_34
L_35 , V_26 ,
V_132 ) ;
return V_26 ;
}
}
F_60 ( L_36 , V_132 ) ;
} else
F_25 ( L_37
L_38 , V_15 ) ;
V_40 = F_7 ( sizeof( struct V_111 ) +
V_84 , V_14 | V_67 ) ;
if ( V_40 ) {
struct V_111 * V_85 =
(struct V_111 * )
F_41 ( V_40 ) ;
F_42 ( & V_85 -> V_86 , V_133 ,
sizeof( struct V_111 ) ) ;
V_85 -> V_88 [ 0 ] = V_15 ;
V_26 = F_35 (
V_29 , V_85 , V_85 -> V_86 . V_92 ,
& V_29 -> V_56 ) ;
F_18 ( V_40 ) ;
} else {
F_9 ( L_39
L_40 ) ;
V_26 = - V_32 ;
}
} else {
if ( V_15 < V_128 || V_15 > V_134 ) {
F_9 ( L_29 , V_15 ) ;
return - V_121 ;
}
F_12 ( V_29 -> V_8 , V_15 ) ;
if ( V_29 -> V_70 )
V_29 -> V_70 ( V_29 -> V_37 ,
& V_29 -> V_15 ) ;
if ( V_29 -> V_15 != V_15 && V_29 -> V_69 )
V_26 = V_29 -> V_69 ( V_29 -> V_37 , V_15 ) ;
}
if ( V_26 >= 0 ) {
V_29 -> V_15 = V_15 ;
V_29 -> V_74 &= ~ V_130 ;
}
if ( V_26 < 0 )
F_9 ( L_41 , V_26 ) ;
return V_26 ;
}
int F_61 ( struct V_1 * V_29 )
{
return V_29 -> V_15 ;
}
static struct
V_33 * F_62 ( struct V_1 * V_29 ,
int V_135 , int V_3 )
{
struct V_33 * V_34 = NULL ;
struct V_10 * V_11 , * V_25 ;
unsigned long V_21 ;
struct V_10 * V_136 , * V_137 ;
F_15 ( & V_29 -> V_51 , V_21 ) ;
V_25 = & V_29 -> V_35 ;
for ( V_11 = V_25 -> V_11 ;
( V_11 != V_25 ) && ! V_34 ;
V_11 = V_11 -> V_11 ) {
V_136 = & ( (struct V_33 * ) V_11 ) -> V_138 ;
for ( V_137 = V_136 -> V_11 ;
V_137 != V_136 ;
V_137 = V_137 -> V_11 ) {
if ( ( ( (struct V_139 * ) V_137 ) -> V_3 == V_3 ) &&
( ( (struct V_139 * ) V_137 ) -> V_135 == V_135 ||
( ( (struct V_139 * ) V_137 ) -> V_135 == 0 ) ) ) {
V_34 = (struct V_33 * ) V_11 ;
break;
}
}
}
F_16 ( & V_29 -> V_51 , V_21 ) ;
return V_34 ;
}
void F_63 ( struct V_1 * V_29 ,
struct V_39 * V_43 ) {
struct V_95 * V_140 = (struct V_95 * ) ( ( T_3 * ) V_43 -> V_44
+ V_43 -> V_141 ) ;
struct V_33 * V_34 ;
int V_26 = - V_142 ;
static unsigned long V_143 ;
static int V_144 ;
unsigned long V_145 = F_64 ( V_146 ) ;
if ( ! V_143 )
V_143 = V_145 ;
if ( V_145 - V_143 > 10000 ) {
F_48 ( L_42 ,
( int ) ( ( V_144 * 1000 ) /
( V_145 - V_143 ) ) ) ;
V_143 = V_145 ;
V_144 = 0 ;
}
V_144 += V_43 -> V_76 ;
if ( ( V_140 -> V_147 == V_148 ) ||
( V_140 -> V_147 == V_149 ) ) {
if ( V_29 -> V_15 == V_134 )
V_140 -> V_150 = V_151 ;
}
V_34 = F_62 ( V_29 , V_140 -> V_147 , V_140 -> V_150 ) ;
if ( V_34 )
V_26 = V_34 -> V_152 ( V_34 -> V_37 , V_43 ) ;
if ( V_26 < 0 ) {
switch ( V_140 -> V_147 ) {
case V_153 :
{
struct V_154 * V_155 =
(struct V_154 * ) V_140 ;
F_48 ( L_43
L_44 ,
V_155 -> V_156 , V_155 -> V_157 ,
V_155 -> V_158 , V_155 -> V_159 ) ;
V_29 -> V_15 = V_155 -> V_156 == 255 ?
V_68 : V_155 -> V_156 ;
V_29 -> V_131 = V_155 -> V_157 ;
F_65 ( & V_29 -> V_53 ) ;
break;
}
case V_160 :
F_48 ( L_45 ) ;
F_65 ( & V_29 -> V_56 ) ;
break;
case V_161 :
F_48 ( L_46 ) ;
F_65 ( & V_29 -> V_57 ) ;
break;
case V_162 :
F_65 ( & V_29 -> V_54 ) ;
break;
case V_163 :
F_48 ( L_47 ) ;
break;
case V_164 :
F_48 ( L_48 ) ;
F_65 ( & V_29 -> V_55 ) ;
break;
case V_165 :
F_65 ( & V_29 -> V_58 ) ;
break;
case V_166 :
F_48 ( L_49 ) ;
F_65 ( & V_29 -> V_59 ) ;
break;
case V_167 :
F_48 ( L_50 ) ;
F_65 ( & V_29 -> V_60 ) ;
break;
case V_168 :
{
T_6 * V_169 = ( T_6 * ) V_140 ;
V_29 -> V_170 = V_169 [ 1 ] ;
F_48 ( L_51 ,
V_29 -> V_170 ) ;
F_65 ( & V_29 -> V_61 ) ;
break;
}
case V_171 :
F_65 ( & V_29 -> V_62 ) ;
break;
case V_172 :
F_66 ( V_29 ,
( const char * )
( ( char * ) V_140
+ sizeof( struct V_95 ) ) ,
( int ) V_140 -> V_92
- sizeof( struct V_95 ) ) ;
break;
default:
break;
}
F_34 ( V_29 , V_43 ) ;
}
}
struct V_39 * F_67 ( struct V_1 * V_29 )
{
struct V_39 * V_43 = NULL ;
unsigned long V_21 ;
F_15 ( & V_29 -> V_52 , V_21 ) ;
if ( ! F_22 ( & V_29 -> V_50 ) ) {
V_43 = (struct V_39 * ) V_29 -> V_50 . V_11 ;
F_20 ( & V_43 -> V_9 ) ;
}
F_16 ( & V_29 -> V_52 , V_21 ) ;
return V_43 ;
}
struct V_39 * F_68 ( struct V_1 * V_29 )
{
struct V_39 * V_43 = NULL ;
F_69 ( V_29 -> V_63 , ( V_43 = F_67 ( V_29 ) ) ) ;
return V_43 ;
}
void F_34 ( struct V_1 * V_29 ,
struct V_39 * V_43 ) {
F_70 ( & V_29 -> V_63 ) ;
F_14 ( & V_43 -> V_9 , & V_29 -> V_50 , & V_29 -> V_52 ) ;
}
static int F_71 ( struct V_1 * V_29 ,
struct V_33 * V_34 ,
int V_135 , int V_3 )
{
struct V_139 * V_173 ;
struct V_33 * V_174 ;
if ( ! V_34 ) {
F_9 ( L_52 ) ;
return - V_121 ;
}
V_174 = F_62 ( V_29 , V_135 , V_3 ) ;
if ( V_174 == V_34 )
return 0 ;
if ( V_174 ) {
F_9 ( L_53 ) ;
return - V_175 ;
}
V_173 = F_27 ( sizeof( struct V_139 ) , V_14 ) ;
if ( ! V_173 ) {
F_9 ( L_54 ) ;
return - V_32 ;
}
V_173 -> V_3 = V_3 ;
V_173 -> V_135 = V_135 ;
F_14 ( & V_173 -> V_9 , & V_34 -> V_138 ,
& V_29 -> V_51 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_29 ,
struct V_176 * V_48 ,
struct V_33 * * V_34 )
{
struct V_33 * V_177 ;
if ( F_62 ( V_29 , V_48 -> V_135 ,
V_48 -> V_178 ) ) {
F_9 ( L_55 ) ;
return - V_175 ;
}
V_177 = F_27 ( sizeof( struct V_33 ) , V_14 ) ;
if ( ! V_177 ) {
F_9 ( L_56 ) ;
return - V_32 ;
}
F_28 ( & V_177 -> V_138 ) ;
V_177 -> V_29 = V_29 ;
V_177 -> V_152 = V_48 -> V_152 ;
V_177 -> V_36 = V_48 -> V_36 ;
V_177 -> V_37 = V_48 -> V_37 ;
F_14 ( & V_177 -> V_9 , & V_29 -> V_35 ,
& V_29 -> V_51 ) ;
F_71 ( V_29 , V_177 , V_48 -> V_135 ,
V_48 -> V_178 ) ;
* V_34 = V_177 ;
F_48 ( L_57 , V_48 -> V_37 , V_48 -> V_135 ,
V_48 -> V_178 ) ;
return 0 ;
}
void F_73 ( struct V_33 * V_34 )
{
struct V_1 * V_29 = V_34 -> V_29 ;
unsigned long V_21 ;
F_15 ( & V_29 -> V_51 , V_21 ) ;
while ( ! F_22 ( & V_34 -> V_138 ) ) {
struct V_139 * V_179 =
(struct V_139 * ) V_34 -> V_138 . V_11 ;
F_20 ( & V_179 -> V_9 ) ;
F_18 ( V_179 ) ;
}
F_25 ( L_58 , V_34 -> V_37 ) ;
F_20 ( & V_34 -> V_9 ) ;
F_18 ( V_34 ) ;
F_16 ( & V_29 -> V_51 , V_21 ) ;
}
int F_74 ( struct V_33 * V_34 ,
void * V_40 , T_5 V_76 )
{
struct V_1 * V_29 ;
struct V_95 * V_140 = (struct V_95 * ) V_40 ;
int V_26 ;
if ( V_34 == NULL ) {
F_9 ( L_59 ) ;
return - V_121 ;
}
V_29 = V_34 -> V_29 ;
if ( V_29 == NULL ) {
F_9 ( L_60 ) ;
return - V_121 ;
}
V_26 = F_71 ( V_34 -> V_29 , V_34 , 0 ,
V_140 -> V_180 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_29 -> V_71 ( V_29 -> V_37 , V_40 , V_76 ) ;
}
int F_75 ( struct V_1 * V_29 , T_6 V_181 ,
struct V_182 * V_183 )
{
struct {
struct V_95 V_184 ;
T_6 V_123 [ 6 ] ;
} V_85 ;
if ( V_29 -> V_74 & V_120 ) {
V_85 . V_184 . V_180 = V_151 ;
V_85 . V_184 . V_150 = V_185 ;
V_85 . V_184 . V_186 = 0 ;
V_85 . V_184 . V_147 = V_187 ;
V_85 . V_184 . V_92 = sizeof( V_85 ) ;
V_85 . V_123 [ 0 ] = V_181 ;
V_85 . V_123 [ 1 ] = V_183 -> V_188 ;
V_85 . V_123 [ 2 ] = V_183 -> V_189 == 0 ? 3 : 0 ;
switch ( V_183 -> V_190 ) {
case V_191 :
V_85 . V_123 [ 3 ] = 7 ;
break;
case V_192 :
V_85 . V_123 [ 3 ] = 5 ;
break;
case V_193 :
V_85 . V_123 [ 3 ] = 3 ;
break;
case V_194 :
default:
V_85 . V_123 [ 3 ] = 2 ;
break;
}
V_85 . V_123 [ 4 ] = V_183 -> V_195 ;
V_85 . V_123 [ 5 ] = 0 ;
} else
return - V_121 ;
return V_29 -> V_71 ( V_29 -> V_37 ,
& V_85 , sizeof( V_85 ) ) ;
}
int F_76 ( struct V_1 * V_29 , T_6 V_181 , int V_196 )
{
struct {
struct V_95 V_184 ;
T_6 V_123 [ 3 ] ;
} V_85 ;
if ( V_181 > V_197 )
return - V_121 ;
V_85 . V_184 . V_180 = V_151 ;
V_85 . V_184 . V_150 = V_185 ;
V_85 . V_184 . V_186 = 0 ;
V_85 . V_184 . V_147 = V_198 ;
V_85 . V_184 . V_92 = sizeof( V_85 ) ;
V_85 . V_123 [ 0 ] = V_181 ;
V_85 . V_123 [ 1 ] = V_196 ? 1 : 0 ;
V_85 . V_123 [ 2 ] = 0 ;
return V_29 -> V_71 ( V_29 -> V_37 ,
& V_85 , sizeof( V_85 ) ) ;
}
static int F_77 ( T_6 V_199 , T_6 * V_200 ,
T_6 * V_201 , T_6 * V_202 ) {
* V_202 = 1 ;
if ( V_199 <= 1 ) {
* V_200 = 0 ;
* V_201 = 9 ;
* V_202 = 2 ;
} else if ( V_199 >= 2 && V_199 <= 6 ) {
* V_200 = 2 ;
* V_201 = 0 ;
* V_202 = 2 ;
} else if ( V_199 >= 7 && V_199 <= 11 ) {
* V_200 = 7 ;
* V_201 = 1 ;
} else if ( V_199 >= 12 && V_199 <= 15 ) {
* V_200 = 12 ;
* V_201 = 2 ;
* V_202 = 3 ;
} else if ( V_199 == 16 ) {
* V_200 = 16 ;
* V_201 = 23 ;
} else if ( V_199 >= 17 && V_199 <= 24 ) {
* V_200 = 17 ;
* V_201 = 3 ;
} else if ( V_199 == 25 ) {
* V_200 = 25 ;
* V_201 = 6 ;
} else if ( V_199 >= 26 && V_199 <= 28 ) {
* V_200 = 26 ;
* V_201 = 4 ;
} else if ( V_199 == 29 ) {
* V_200 = 29 ;
* V_201 = 5 ;
* V_202 = 2 ;
} else if ( V_199 == 30 ) {
* V_200 = 30 ;
* V_201 = 8 ;
} else if ( V_199 == 31 ) {
* V_200 = 31 ;
* V_201 = 17 ;
} else
return - 1 ;
* V_202 <<= 24 ;
return 0 ;
}
int F_78 ( struct V_1 * V_29 , T_3 V_199 ,
struct V_203 * V_204 ) {
T_6 V_205 ;
T_6 V_206 = 0 ;
T_6 V_207 = 0 ;
T_6 V_208 ;
T_6 V_209 ;
void * V_40 ;
int V_26 ;
struct V_210 {
struct V_95 V_86 ;
T_6 V_88 [ 6 ] ;
} * V_211 ;
if ( V_199 > V_197 )
return - V_121 ;
if ( V_204 == NULL )
return - V_121 ;
V_205 = sizeof( struct V_95 ) + ( sizeof( T_6 ) * 6 ) ;
V_40 = F_7 ( V_205 + V_84 ,
V_14 | V_67 ) ;
if ( ! V_40 )
return - V_32 ;
V_211 = (struct V_210 * ) F_41 ( V_40 ) ;
V_211 -> V_86 . V_180 = V_151 ;
V_211 -> V_86 . V_150 = V_185 ;
V_211 -> V_86 . V_186 = 0 ;
V_211 -> V_86 . V_92 = ( V_108 ) V_205 ;
V_211 -> V_88 [ 0 ] = V_199 ;
if ( ! ( V_29 -> V_74 & V_120 ) ) {
V_211 -> V_86 . V_147 = V_212 ;
if ( F_77 ( V_199 , & V_206 , & V_207 ,
& V_209 ) != 0 ) {
V_26 = - V_121 ;
goto free;
}
V_211 -> V_88 [ 1 ] = V_206 ;
V_211 -> V_88 [ 2 ] = V_207 ;
V_208 = ( V_204 -> V_213 )
| ( V_204 -> V_214 << 2 )
| ( V_204 -> V_215 << 3 )
| ( V_204 -> V_216 << 4 ) ;
V_211 -> V_88 [ 3 ] = V_208 ;
V_211 -> V_88 [ 4 ] = V_204 -> V_217 ;
V_211 -> V_88 [ 5 ] = V_209 ;
} else {
V_211 -> V_86 . V_147 = V_187 ;
V_211 -> V_88 [ 1 ] = V_204 -> V_213 ;
V_211 -> V_88 [ 2 ] = V_204 -> V_215 ;
V_211 -> V_88 [ 3 ] = V_204 -> V_216 ;
V_211 -> V_88 [ 4 ] = V_204 -> V_217 ;
V_211 -> V_88 [ 5 ] = 0 ;
}
F_43 ( (struct V_95 * ) V_211 ) ;
V_26 = F_35 ( V_29 , V_211 , V_205 ,
& V_29 -> V_59 ) ;
if ( V_26 != 0 ) {
if ( V_26 == - V_79 )
F_9 ( L_61 ) ;
else
F_9 ( L_62 ) ;
}
free:
F_18 ( V_40 ) ;
return V_26 ;
}
int F_79 ( struct V_1 * V_29 , T_3 V_199 ,
T_3 V_218 ) {
T_6 V_205 ;
int V_26 ;
void * V_40 ;
struct V_210 {
struct V_95 V_86 ;
T_6 V_88 [ 3 ] ;
} * V_211 ;
if ( ( V_218 > 1 ) || ( V_199 > V_197 ) )
return - V_121 ;
V_205 = sizeof( struct V_95 ) +
( 3 * sizeof( T_6 ) ) ;
V_40 = F_7 ( V_205 + V_84 ,
V_14 | V_67 ) ;
if ( ! V_40 )
return - V_32 ;
V_211 = (struct V_210 * ) F_41 ( V_40 ) ;
V_211 -> V_86 . V_180 = V_151 ;
V_211 -> V_86 . V_150 = V_185 ;
V_211 -> V_86 . V_186 = 0 ;
V_211 -> V_86 . V_147 = V_198 ;
V_211 -> V_86 . V_92 = ( V_108 ) V_205 ;
V_211 -> V_88 [ 0 ] = V_199 ;
V_211 -> V_88 [ 1 ] = V_218 ;
F_43 ( (struct V_95 * ) V_211 ) ;
V_26 = F_35 ( V_29 , V_211 , V_205 ,
& V_29 -> V_60 ) ;
if ( V_26 != 0 ) {
if ( V_26 == - V_79 )
F_9 ( L_63 ) ;
else
F_9 ( L_64 ) ;
}
F_18 ( V_40 ) ;
return V_26 ;
}
int F_80 ( struct V_1 * V_29 , T_3 V_199 ,
T_3 * V_196 ) {
T_6 V_205 ;
int V_26 ;
void * V_40 ;
struct V_210 {
struct V_95 V_86 ;
T_6 V_88 [ 2 ] ;
} * V_211 ;
if ( V_199 > V_197 )
return - V_121 ;
V_205 = sizeof( struct V_95 ) + ( 2 * sizeof( T_6 ) ) ;
V_40 = F_7 ( V_205 + V_84 ,
V_14 | V_67 ) ;
if ( ! V_40 )
return - V_32 ;
V_211 = (struct V_210 * ) F_41 ( V_40 ) ;
V_211 -> V_86 . V_180 = V_151 ;
V_211 -> V_86 . V_150 = V_185 ;
V_211 -> V_86 . V_186 = 0 ;
V_211 -> V_86 . V_147 = V_219 ;
V_211 -> V_86 . V_92 = ( V_108 ) V_205 ;
V_211 -> V_88 [ 0 ] = V_199 ;
V_211 -> V_88 [ 1 ] = 0 ;
F_43 ( (struct V_95 * ) V_211 ) ;
V_26 = F_35 ( V_29 , V_211 , V_205 ,
& V_29 -> V_61 ) ;
if ( V_26 != 0 ) {
if ( V_26 == - V_79 )
F_9 ( L_65 ) ;
else
F_9 ( L_66 ) ;
}
F_18 ( V_40 ) ;
* V_196 = V_29 -> V_170 ;
return V_26 ;
}
static int T_8 F_81 ( void )
{
int V_26 = 0 ;
F_28 ( & V_31 ) ;
F_28 ( & V_28 ) ;
F_82 ( & V_27 ) ;
F_28 ( & V_13 ) ;
F_82 ( & V_12 ) ;
return V_26 ;
}
static void T_9 F_83 ( void )
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
F_48 ( L_67 ) ;
}
