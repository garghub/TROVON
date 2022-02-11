void * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_4 * V_5 , unsigned int V_6 )
{
struct V_7 T_1 * V_8 ;
struct V_9 T_1 * V_10 ;
struct V_11 T_1 * V_12 ;
T_2 type ;
if ( V_6 == 0 )
return - V_13 ;
if ( V_5 -> V_14 < V_15 ) {
F_3 ( L_1 ) ;
return - V_13 ;
}
V_8 = V_5 -> V_16 ;
V_10 = V_5 -> V_16 ;
if ( ! V_8 ) {
F_3 ( L_2 ) ;
return - V_13 ;
}
if ( ( F_4 ( & V_8 -> V_17 ) != V_18 ) ||
( F_4 ( & V_8 -> V_19 ) != V_20 ) ) {
if ( ( F_4 ( & V_10 -> V_17 ) != V_21 ) ||
( F_4 ( & V_10 -> V_19 ) != V_22 ) ) {
F_3 ( L_3
L_4 ,
V_18 , V_20 ,
V_21 , V_22 ,
F_4 ( & V_8 -> V_17 ) , F_4 ( & V_8 -> V_19 ) ) ;
return - V_13 ;
}
}
if ( F_4 ( & V_10 -> V_17 ) == V_21 )
V_12 = (struct V_11 T_1 * ) ( V_10 + 1 ) ;
else
V_12 = (struct V_11 T_1 * ) ( V_8 + 1 ) ;
while ( ( type = F_5 ( & V_12 -> type ) ) != V_23 ) {
T_2 V_24 = F_5 ( & V_12 -> V_5 ) ;
T_3 V_25 = F_4 ( & V_12 -> V_25 ) ;
T_3 V_26 = F_4 ( & V_12 -> V_26 ) ;
T_3 V_14 ;
V_12 ++ ;
if ( V_24 >= V_6 )
continue;
if ( ! V_5 [ V_24 ] . V_14 || ! V_5 [ V_24 ] . V_16 )
continue;
switch ( type ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_14 = V_26 * V_31 ;
if ( V_14 + V_25 > V_5 [ V_24 ] . V_14 ) {
F_3 ( L_5
L_6
L_7 ,
type , V_25 ,
V_14 ,
V_5 [ V_24 ] . V_14 ) ;
return - V_13 ;
}
break;
case V_32 :
case V_33 :
V_14 = V_26 ;
break;
default:
continue;
}
V_2 -> V_34 [ type ] . V_26 = V_26 ;
V_2 -> V_34 [ type ] . V_16 = ( char T_1 * ) V_5 [ V_24 ] . V_16 +
V_25 ;
V_2 -> V_34 [ type ] . V_35 = V_5 [ V_24 ] . V_35 + V_25 ;
}
return 0 ;
}
unsigned int F_6 ( struct V_1 * V_2 ,
enum V_36 type )
{
return V_2 -> V_34 [ type ] . V_26 ;
}
void T_1 * F_7 ( struct V_1 * V_2 , enum V_36 type ,
unsigned int V_37 )
{
if ( ! V_2 -> V_34 [ type ] . V_16 )
return NULL ;
switch ( type ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return ( char T_1 * ) V_2 -> V_34 [ type ] . V_16 +
V_37 * V_31 ;
default:
return ( char T_1 * ) V_2 -> V_34 [ type ] . V_16 ;
}
}
static unsigned int F_8 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_42 = 32 ;
unsigned int V_43 = 16 ;
V_39 -> V_44 = 512 ;
if ( V_40 == 0 )
V_40 = 4096 ;
V_39 -> V_40 = F_9 ( V_40 , V_42 ) ;
V_39 -> V_41 = F_9 ( V_41 , V_43 ) ;
V_39 -> V_45 = V_39 -> V_40 * V_39 -> V_41 ;
V_39 -> V_46 = V_39 -> V_45 + V_39 -> V_44 ;
return V_39 -> V_46 ;
}
void F_10 ( struct V_38 * V_39 )
{
memset ( V_39 -> V_47 , 0 , V_39 -> V_45 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_38 * V_39 ,
unsigned int V_40 , unsigned int V_41 )
{
F_8 ( V_39 , V_40 , V_41 ) ;
V_39 -> V_48 = F_12 ( V_2 -> V_49 ,
V_39 -> V_46 ,
& V_39 -> V_50 ) ;
if ( ! V_39 -> V_48 ) {
F_3 ( L_8 ,
( int ) V_39 -> V_45 ) ;
return - V_51 ;
}
V_39 -> V_52 = F_9 ( V_39 -> V_50 ,
V_39 -> V_44 ) ;
V_39 -> V_47 = ( T_2 * ) V_39 -> V_48 +
( V_39 -> V_52 - V_39 -> V_50 ) ;
F_10 ( V_39 ) ;
V_39 -> V_53 = V_39 -> V_40 - 1 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
if ( V_39 -> V_47 ) {
F_14 ( V_2 -> V_49 ,
V_39 -> V_46 ,
V_39 -> V_48 ,
V_39 -> V_50 ) ;
V_39 -> V_47 = NULL ;
}
}
static int F_15 ( struct V_1 * V_2 , enum V_54 V_55 ,
int V_56 )
{
struct V_57 T_1 * V_58 = V_2 -> V_58 ;
unsigned int V_59 ;
int V_60 ;
T_3 V_61 ;
int V_62 ;
V_61 = F_4 ( & V_58 -> V_61 ) ;
if ( V_61 == 0xFFFFFFFF ) {
return - V_63 ;
}
if ( V_61 & V_64 ) {
F_3 ( L_9 , F_16 ( V_55 ) ) ;
return - V_65 ;
}
if ( F_17 ( V_55 ) & V_66 ) {
for ( V_59 = 0 ; V_59 < V_67 ; V_59 ++ )
F_18 ( V_2 -> args [ V_59 ] , & V_58 -> args [ V_59 ] ) ;
F_19 () ;
}
F_20 ( V_55 , & V_58 -> V_55 ) ;
if ( ( F_21 ( V_55 ) & V_68 ) )
return 0 ;
for ( V_60 = 0 ; V_60 < V_56 ; V_60 ++ ) {
F_22 ( 100 ) ;
V_61 = F_4 ( & V_58 -> V_61 ) ;
if ( V_61 == 0xFFFFFFFF ) {
return - V_63 ;
}
if ( ! ( V_61 & V_64 ) ) {
if ( V_61 & V_69 ) {
V_62 = ( int ) F_23 ( & V_58 -> args [ 0 ] ) ;
if ( V_62 == V_70 &&
V_55 == V_71 )
return V_62 ;
if ( V_62 != V_72 ||
V_55 != V_71 )
F_3 ( L_10 ,
V_62 , F_16 ( V_55 ) ) ;
return V_62 ;
}
if ( F_17 ( V_55 ) & V_73 ) {
F_24 () ;
for ( V_59 = 0 ; V_59 < V_67 ; V_59 ++ )
V_2 -> args [ V_59 ] = F_23 ( & V_58 -> args [ V_59 ] ) ;
}
return 0 ;
}
}
F_3 ( L_11 , F_16 ( V_55 ) ) ;
return - V_74 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_54 V_75 , enum V_54 V_55 ,
T_4 * V_76 , T_4 * V_77 , int V_56 )
{
T_3 V_61 ;
int V_62 ;
memset ( V_2 -> args , 0 , sizeof( V_2 -> args ) ) ;
V_2 -> args [ 0 ] = V_2 -> V_78 ;
V_2 -> args [ 1 ] = V_55 ;
V_2 -> args [ 2 ] = * V_76 ;
V_2 -> args [ 3 ] = * V_77 ;
V_62 = F_15 ( V_2 , V_75 , V_56 ) ;
if ( V_62 )
return V_62 ;
V_61 = ( T_3 ) V_2 -> args [ 0 ] ;
if ( V_61 & V_69 ) {
V_62 = ( int ) V_2 -> args [ 1 ] ;
if ( V_62 != V_72 ||
V_55 != V_71 )
F_3 ( L_12 , V_62 , F_16 ( V_55 ) ) ;
return V_62 ;
}
* V_76 = V_2 -> args [ 1 ] ;
* V_77 = V_2 -> args [ 2 ] ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_54 V_55 , T_4 * V_76 , T_4 * V_77 , int V_56 )
{
int V_62 ;
V_2 -> args [ 0 ] = * V_76 ;
V_2 -> args [ 1 ] = * V_77 ;
V_62 = F_15 ( V_2 , V_55 , V_56 ) ;
* V_76 = V_2 -> args [ 0 ] ;
* V_77 = V_2 -> args [ 1 ] ;
return V_62 ;
}
void F_27 ( struct V_1 * V_2 , T_5 V_37 )
{
V_2 -> V_79 = V_80 ;
V_2 -> V_78 = V_37 ;
}
void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_79 = V_81 ;
V_2 -> V_78 = 0 ;
}
int F_29 ( struct V_1 * V_2 , enum V_54 V_55 ,
T_4 * V_76 , T_4 * V_77 , int V_56 )
{
memset ( V_2 -> args , 0 , sizeof( V_2 -> args ) ) ;
switch ( V_2 -> V_79 ) {
case V_80 :
return F_25 ( V_2 , V_82 , V_55 ,
V_76 , V_77 , V_56 ) ;
case V_83 :
return F_25 ( V_2 , V_84 , V_55 ,
V_76 , V_77 , V_56 ) ;
case V_81 :
default:
return F_26 ( V_2 , V_55 , V_76 , V_77 , V_56 ) ;
}
}
static int F_30 ( struct V_1 * V_2 , enum V_54 V_55 )
{
T_4 V_76 = ( T_3 ) V_55 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 ;
V_62 = F_29 ( V_2 , V_71 , & V_76 , & V_77 , V_56 ) ;
return ! ( V_62 || V_76 ) ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_85 * * V_86 )
{
T_4 V_76 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 = 0 ;
if ( ! V_2 -> V_86 ) {
V_2 -> V_86 = F_12 ( V_2 -> V_49 ,
sizeof( struct V_85 ) ,
& V_2 -> V_87 ) ;
if ( ! V_2 -> V_86 )
return - V_51 ;
memset ( V_2 -> V_86 , 0 , sizeof( struct V_85 ) ) ;
V_76 = V_2 -> V_87 ;
V_77 = sizeof( struct V_85 ) ;
if ( F_30 ( V_2 , V_88 ) )
V_62 = F_29 ( V_2 , V_88 ,
& V_76 , & V_77 , V_56 ) ;
else
V_62 = F_29 ( V_2 , V_89 ,
& V_76 , & V_77 , V_56 ) ;
}
* V_86 = V_2 -> V_86 ;
return V_62 ;
}
int F_32 ( struct V_1 * V_2 , unsigned int V_90 , unsigned int V_45 ,
void * V_91 )
{
T_4 V_76 , V_77 ;
int V_56 = 1000 ;
int V_62 ;
V_76 = V_90 ;
V_77 = V_45 ;
V_62 = F_29 ( V_2 , V_92 , & V_76 , & V_77 , V_56 ) ;
switch ( V_45 ) {
case 1 : * ( T_2 * ) V_91 = ( T_2 ) V_76 ; break;
case 2 : * ( T_5 * ) V_91 = ( T_5 ) V_76 ; break;
case 4 : * ( T_3 * ) V_91 = ( T_3 ) V_76 ; break;
case 8 : * ( T_4 * ) V_91 = V_76 ; break;
default: F_33 () ; break;
}
return V_62 ;
}
int F_34 ( struct V_1 * V_2 , struct V_93 * * V_94 )
{
T_4 V_76 , V_77 ;
int V_56 = 1000 ;
if ( ! V_2 -> V_94 ) {
V_2 -> V_94 = F_12 ( V_2 -> V_49 ,
sizeof( struct V_93 ) , & V_2 -> V_95 ) ;
if ( ! V_2 -> V_94 )
return - V_51 ;
}
* V_94 = V_2 -> V_94 ;
V_76 = V_2 -> V_95 ;
V_77 = sizeof( struct V_93 ) ;
return F_29 ( V_2 , V_96 , & V_76 , & V_77 , V_56 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
return F_29 ( V_2 , V_97 , & V_76 , & V_77 , V_56 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
if ( F_30 ( V_2 , V_98 ) )
return F_29 ( V_2 , V_98 , & V_76 , & V_77 , V_56 ) ;
else
return F_29 ( V_2 , V_99 , & V_76 , & V_77 , V_56 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
return F_29 ( V_2 , V_100 , & V_76 , & V_77 , V_56 ) ;
}
int F_38 ( struct V_1 * V_2 , int V_101 )
{
T_4 V_76 = ( T_3 ) V_101 , V_77 = 0 ;
int V_56 = 1000 ;
return F_29 ( V_2 , V_102 , & V_76 , & V_77 , V_56 ) ;
}
int F_39 ( struct V_1 * V_2 , int * V_103 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 ;
* V_103 = 0 ;
V_62 = F_29 ( V_2 , V_104 , & V_76 , & V_77 , V_56 ) ;
if ( V_62 )
return V_62 ;
* V_103 = ( V_76 == 0 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , int V_101 )
{
T_4 V_76 = ( T_3 ) V_101 , V_77 = 0 ;
int V_56 = 1000 ;
return F_29 ( V_2 , V_105 , & V_76 , & V_77 , V_56 ) ;
}
static int F_41 ( struct V_1 * V_2 , int * V_103 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 ;
* V_103 = 0 ;
V_62 = F_29 ( V_2 , V_106 , & V_76 , & V_77 , V_56 ) ;
if ( V_62 )
return V_62 ;
* V_103 = ( V_76 == 0 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 , int V_101 )
{
T_4 V_76 = ( T_3 ) V_101 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 ;
if ( F_30 ( V_2 , V_107 ) ) {
return F_29 ( V_2 , V_107 ,
& V_76 , & V_77 , V_56 ) ;
} else {
V_62 = F_40 ( V_2 , V_101 ) ;
if ( V_62 )
return V_62 ;
return F_43 ( V_2 , 0 ) ;
}
}
int F_44 ( struct V_1 * V_2 , int * V_103 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 ;
* V_103 = 0 ;
if ( F_30 ( V_2 , V_108 ) ) {
V_62 = F_29 ( V_2 , V_108 ,
& V_76 , & V_77 , V_56 ) ;
if ( V_62 )
return V_62 ;
} else {
return F_41 ( V_2 , V_103 ) ;
}
* V_103 = ( V_76 == 0 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
T_4 V_76 , V_77 ;
int V_56 = 1000 ;
return F_29 ( V_2 , V_109 , & V_76 , & V_77 , V_56 ) ;
}
int F_46 ( struct V_1 * V_2 , T_2 * V_110 )
{
T_4 V_76 , V_77 ;
int V_56 = 1000 ;
int V_62 , V_59 ;
for ( V_59 = 0 ; V_59 < V_111 ; V_59 ++ )
V_110 [ V_59 ] = 0 ;
V_62 = F_29 ( V_2 , V_112 , & V_76 , & V_77 , V_56 ) ;
if ( V_62 )
return V_62 ;
for ( V_59 = 0 ; V_59 < V_111 ; V_59 ++ )
V_110 [ V_59 ] = ( ( T_2 * ) & V_76 ) [ V_59 ] ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int V_113 , int V_114 ,
int V_115 , int V_116 , int V_117 )
{
T_4 V_76 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 ;
V_76 = ( V_113 ? V_118 : 0 ) |
( V_114 ? V_119 : 0 ) |
( V_115 ? V_120 : 0 ) |
( V_116 ? V_121 : 0 ) |
( V_117 ? V_122 : 0 ) ;
V_62 = F_29 ( V_2 , V_123 , & V_76 , & V_77 , V_56 ) ;
if ( V_62 )
F_3 ( L_13 ) ;
return V_62 ;
}
int F_48 ( struct V_1 * V_2 , T_2 * V_124 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_111 ; V_59 ++ )
( ( T_2 * ) & V_76 ) [ V_59 ] = V_124 [ V_59 ] ;
V_62 = F_29 ( V_2 , V_125 , & V_76 , & V_77 , V_56 ) ;
if ( V_62 )
F_3 ( L_14 , V_124 , V_62 ) ;
return V_62 ;
}
int F_49 ( struct V_1 * V_2 , T_2 * V_124 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
int V_62 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_111 ; V_59 ++ )
( ( T_2 * ) & V_76 ) [ V_59 ] = V_124 [ V_59 ] ;
V_62 = F_29 ( V_2 , V_126 , & V_76 , & V_77 , V_56 ) ;
if ( V_62 )
F_3 ( L_15 , V_124 , V_62 ) ;
return V_62 ;
}
int F_50 ( struct V_1 * V_2 ,
T_2 V_127 )
{
T_4 V_76 = V_127 , V_77 = 0 ;
int V_56 = 1000 ;
if ( F_30 ( V_2 , V_128 ) )
return F_29 ( V_2 , V_128 ,
& V_76 , & V_77 , V_56 ) ;
else
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
void * V_129 , T_6 V_130 , T_5 V_131 )
{
T_4 V_76 , V_77 ;
int V_56 = 1000 ;
int V_12 ;
memset ( V_129 , 0 , sizeof( struct V_132 ) ) ;
V_2 -> V_133 = V_129 ;
V_2 -> V_130 = V_130 ;
V_76 = ( T_4 ) V_130 ;
V_77 = ( ( T_4 ) V_131 << 32 ) & 0x0000ffff00000000ULL ;
V_77 += sizeof( struct V_132 ) ;
V_12 = F_29 ( V_2 , V_134 , & V_76 , & V_77 , V_56 ) ;
V_2 -> V_135 = ( V_12 == 0 ) ? ( T_3 ) V_77 : 0 ;
return V_12 ;
}
int F_52 ( struct V_1 * V_2 , T_5 V_131 )
{
void * V_129 ;
T_6 V_130 ;
if ( V_2 -> V_133 || V_2 -> V_130 ) {
F_3 ( L_16 , V_2 -> V_133 ) ;
return - V_13 ;
}
V_129 = F_12 ( V_2 -> V_49 ,
sizeof( struct V_132 ) ,
& V_130 ) ;
if ( ! V_129 )
return - V_51 ;
return F_51 ( V_2 , V_129 , V_130 , V_131 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
T_4 V_76 , V_77 ;
int V_56 = 1000 ;
int V_62 ;
V_76 = 0 ;
V_77 = 0x0000ffff00000000ULL ;
V_77 += sizeof( struct V_132 ) ;
V_62 = F_29 ( V_2 , V_134 , & V_76 , & V_77 , V_56 ) ;
V_2 -> V_133 = NULL ;
V_2 -> V_130 = 0 ;
V_2 -> V_135 = 0 ;
return V_62 ;
}
int F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_133 ) {
F_14 ( V_2 -> V_49 ,
sizeof( struct V_132 ) ,
V_2 -> V_133 ,
V_2 -> V_130 ) ;
}
return F_53 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
T_3 * V_136 ;
unsigned int V_137 = V_2 -> V_135 / 4 ;
unsigned int V_59 ;
T_3 V_138 ;
if ( ! V_2 -> V_133 || ! V_2 -> V_135 )
return 0 ;
do {
V_138 = 0 ;
memcpy ( & V_2 -> V_139 , V_2 -> V_133 , V_2 -> V_135 ) ;
V_136 = ( T_3 * ) & V_2 -> V_139 ;
for ( V_59 = 1 ; V_59 < V_137 ; V_59 ++ )
V_138 += V_136 [ V_59 ] ;
} while ( V_138 != V_136 [ 0 ] );
return 1 ;
}
int F_43 ( struct V_1 * V_2 , int V_101 )
{
T_4 V_76 = ( T_3 ) V_101 , V_77 = 0 ;
int V_56 = 1000 ;
int V_12 = 0 ;
if ( F_30 ( V_2 , V_140 ) )
V_12 = F_29 ( V_2 , V_140 , & V_76 , & V_77 , V_56 ) ;
else {
F_29 ( V_2 , V_141 , & V_76 , & V_77 , V_56 ) ;
if ( V_76 & V_142 ) {
F_29 ( V_2 , V_112 , & V_76 , & V_77 , V_56 ) ;
F_29 ( V_2 , V_125 , & V_76 , & V_77 , V_56 ) ;
}
}
return V_12 ;
}
int F_56 ( struct V_1 * V_2 )
{
T_4 V_76 = 0 , V_77 = 0 ;
int V_56 = 1000 ;
return F_29 ( V_2 , V_143 , & V_76 , & V_77 , V_56 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
V_2 -> V_144 . V_145 = 2 ;
V_2 -> V_144 . div = 3 ;
V_2 -> V_144 . V_146 =
F_58 ( V_2 , 0xffff ) ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_56 = 1000 ;
int V_62 ;
memset ( V_2 -> args , 0 , sizeof( V_2 -> args ) ) ;
if ( F_30 ( V_2 , V_147 ) )
V_62 = F_15 ( V_2 , V_147 , V_56 ) ;
else
V_62 = V_72 ;
if ( ( V_62 == V_72 ) ||
( ! V_62 && ! ( V_2 -> args [ 0 ] && V_2 -> args [ 1 ] && V_2 -> args [ 2 ] ) ) ) {
F_60 ( L_17
L_18 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
if ( ! V_62 ) {
V_2 -> V_144 . V_145 = ( T_3 ) V_2 -> args [ 0 ] ;
V_2 -> V_144 . div = ( T_3 ) V_2 -> args [ 1 ] ;
V_2 -> V_144 . V_146 = ( T_3 ) V_2 -> args [ 2 ] ;
}
return V_62 ;
}
int F_61 ( struct V_1 * V_2 )
{
if ( ! F_55 ( V_2 ) )
return 0 ;
return V_2 -> V_139 . V_148 ;
}
T_3 F_62 ( struct V_1 * V_2 )
{
if ( ! F_55 ( V_2 ) )
return 0 ;
return V_2 -> V_139 . V_149 ;
}
T_3 F_63 ( struct V_1 * V_2 )
{
if ( ! F_55 ( V_2 ) )
return 0 ;
return V_2 -> V_139 . V_150 ;
}
T_3 F_64 ( struct V_1 * V_2 )
{
if ( ! F_55 ( V_2 ) )
return 0 ;
return V_2 -> V_139 . V_151 ;
}
void F_65 ( struct V_1 * V_2 ,
enum V_152 V_153 )
{
V_2 -> V_153 = V_153 ;
}
enum V_152 F_66 (
struct V_1 * V_2 )
{
return V_2 -> V_153 ;
}
T_3 F_67 ( struct V_1 * V_2 , T_3 V_154 )
{
return ( V_154 * V_2 -> V_144 . V_145 ) /
V_2 -> V_144 . div ;
}
T_3 F_58 ( struct V_1 * V_2 , T_3 V_155 )
{
return ( V_155 * V_2 -> V_144 . div ) /
V_2 -> V_144 . V_145 ;
}
T_3 F_68 ( struct V_1 * V_2 )
{
return V_2 -> V_144 . V_146 ;
}
void F_69 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_133 )
F_14 ( V_2 -> V_49 ,
sizeof( struct V_132 ) ,
V_2 -> V_133 ,
V_2 -> V_130 ) ;
if ( V_2 -> V_94 )
F_14 ( V_2 -> V_49 ,
sizeof( struct V_93 ) ,
V_2 -> V_94 , V_2 -> V_95 ) ;
if ( V_2 -> V_86 )
F_14 ( V_2 -> V_49 ,
sizeof( struct V_85 ) ,
V_2 -> V_86 , V_2 -> V_87 ) ;
F_70 ( V_2 ) ;
}
}
struct V_1 * F_71 ( struct V_1 * V_2 ,
void * V_3 , struct V_156 * V_49 , struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( ! V_2 ) {
V_2 = F_72 ( sizeof( struct V_1 ) , V_157 ) ;
if ( ! V_2 )
return NULL ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_49 = V_49 ;
if ( F_2 ( V_2 , V_5 , V_6 ) )
goto V_158;
V_2 -> V_58 = F_7 ( V_2 , V_33 , 0 ) ;
if ( ! V_2 -> V_58 )
goto V_158;
return V_2 ;
V_158:
F_69 ( V_2 ) ;
return NULL ;
}
int F_73 ( struct V_1 * V_2 , T_2 * V_159 , T_3 V_14 )
{
T_4 V_76 , V_77 = V_14 ;
int V_56 = 1000 ;
T_6 V_160 ;
void * V_161 ;
int V_162 ;
V_161 = F_12 ( V_2 -> V_49 , V_14 , & V_160 ) ;
if ( ! V_161 )
return - V_51 ;
memcpy ( V_161 , V_159 , V_14 ) ;
V_76 = V_160 ;
V_162 = F_29 ( V_2 , V_163 , & V_76 , & V_77 , V_56 ) ;
F_14 ( V_2 -> V_49 , V_14 , V_161 , V_160 ) ;
return V_162 ;
}
int F_74 ( struct V_1 * V_2 , int V_164 )
{
T_4 V_76 , V_77 = 0 ;
int V_56 = 1000 ;
V_76 = ( V_164 ? V_165 : 0 ) ;
return F_29 ( V_2 , V_166 , & V_76 , & V_77 , V_56 ) ;
}
static int F_75 ( struct V_1 * V_2 , enum V_54 V_55 ,
int * V_61 )
{
T_4 V_76 = V_55 , V_77 = 0 ;
int V_56 = 1000 ;
int V_162 ;
V_162 = F_29 ( V_2 , V_167 , & V_76 , & V_77 , V_56 ) ;
if ( ! V_162 )
* V_61 = ( int ) V_76 ;
return V_162 ;
}
int F_76 ( struct V_1 * V_2 , int * V_61 )
{
return F_75 ( V_2 , V_166 , V_61 ) ;
}
int F_77 ( struct V_1 * V_2 , int * V_61 )
{
return F_75 ( V_2 , V_143 , V_61 ) ;
}
int F_78 ( struct V_1 * V_2 , T_2 * V_110 )
{
T_4 V_76 , V_77 ;
int V_56 = 1000 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_111 ; V_59 ++ )
( ( T_2 * ) & V_76 ) [ V_59 ] = V_110 [ V_59 ] ;
return F_29 ( V_2 , V_168 , & V_76 , & V_77 , V_56 ) ;
}
