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
F_3 ( V_2 , L_1 ) ;
return - V_13 ;
}
V_8 = V_5 -> V_16 ;
V_10 = V_5 -> V_16 ;
if ( ! V_8 ) {
F_3 ( V_2 , L_2 ) ;
return - V_13 ;
}
if ( ( F_4 ( & V_8 -> V_17 ) != V_18 ) ||
( F_4 ( & V_8 -> V_19 ) != V_20 ) ) {
if ( ( F_4 ( & V_10 -> V_17 ) != V_21 ) ||
( F_4 ( & V_10 -> V_19 ) != V_22 ) ) {
F_3 ( V_2 , L_3 ,
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
F_3 ( V_2 , L_4 ,
type , V_25 , V_14 ,
V_5 [ V_24 ] . V_14 ) ;
return - V_13 ;
}
break;
case V_32 :
case V_33 :
case V_34 :
V_14 = V_26 ;
break;
default:
continue;
}
V_2 -> V_35 [ type ] . V_26 = V_26 ;
V_2 -> V_35 [ type ] . V_16 = ( char T_1 * ) V_5 [ V_24 ] . V_16 +
V_25 ;
V_2 -> V_35 [ type ] . V_36 = V_5 [ V_24 ] . V_36 + V_25 ;
}
return 0 ;
}
unsigned int F_6 ( struct V_1 * V_2 ,
enum V_37 type )
{
return V_2 -> V_35 [ type ] . V_26 ;
}
void T_1 * F_7 ( struct V_1 * V_2 , enum V_37 type ,
unsigned int V_38 )
{
if ( ! V_2 -> V_35 [ type ] . V_16 )
return NULL ;
switch ( type ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return ( char T_1 * ) V_2 -> V_35 [ type ] . V_16 +
V_38 * V_31 ;
default:
return ( char T_1 * ) V_2 -> V_35 [ type ] . V_16 ;
}
}
static unsigned int F_8 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned int V_42 )
{
unsigned int V_43 = 32 ;
unsigned int V_44 = 16 ;
V_40 -> V_45 = 512 ;
if ( V_41 == 0 )
V_41 = 4096 ;
V_40 -> V_41 = F_9 ( V_41 , V_43 ) ;
V_40 -> V_42 = F_9 ( V_42 , V_44 ) ;
V_40 -> V_46 = V_40 -> V_41 * V_40 -> V_42 ;
V_40 -> V_47 = V_40 -> V_46 + V_40 -> V_45 ;
return V_40 -> V_47 ;
}
void F_10 ( struct V_39 * V_40 )
{
memset ( V_40 -> V_48 , 0 , V_40 -> V_46 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_39 * V_40 ,
unsigned int V_41 , unsigned int V_42 )
{
F_8 ( V_40 , V_41 , V_42 ) ;
V_40 -> V_49 = F_12 ( V_2 -> V_50 ,
V_40 -> V_47 ,
& V_40 -> V_51 ) ;
if ( ! V_40 -> V_49 ) {
F_3 ( V_2 , L_5 ,
( int ) V_40 -> V_46 ) ;
return - V_52 ;
}
V_40 -> V_53 = F_9 ( V_40 -> V_51 ,
V_40 -> V_45 ) ;
V_40 -> V_48 = ( T_2 * ) V_40 -> V_49 +
( V_40 -> V_53 - V_40 -> V_51 ) ;
F_10 ( V_40 ) ;
V_40 -> V_54 = V_40 -> V_41 - 1 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
if ( V_40 -> V_48 ) {
F_14 ( V_2 -> V_50 ,
V_40 -> V_47 ,
V_40 -> V_49 ,
V_40 -> V_51 ) ;
V_40 -> V_48 = NULL ;
}
}
static int F_15 ( struct V_1 * V_2 , enum V_55 V_56 ,
int V_57 )
{
struct V_58 T_1 * V_59 = V_2 -> V_59 ;
unsigned int V_60 ;
int V_61 ;
T_3 V_62 ;
int V_63 ;
V_62 = F_4 ( & V_59 -> V_62 ) ;
if ( V_62 == 0xFFFFFFFF ) {
return - V_64 ;
}
if ( V_62 & V_65 ) {
F_16 ( V_2 , L_6 , F_17 ( V_56 ) ) ;
return - V_66 ;
}
if ( F_18 ( V_56 ) & V_67 ) {
for ( V_60 = 0 ; V_60 < V_68 ; V_60 ++ )
F_19 ( V_2 -> args [ V_60 ] , & V_59 -> args [ V_60 ] ) ;
F_20 () ;
}
F_21 ( V_56 , & V_59 -> V_56 ) ;
if ( ( F_22 ( V_56 ) & V_69 ) )
return 0 ;
for ( V_61 = 0 ; V_61 < V_57 ; V_61 ++ ) {
F_23 ( 100 ) ;
V_62 = F_4 ( & V_59 -> V_62 ) ;
if ( V_62 == 0xFFFFFFFF ) {
return - V_64 ;
}
if ( ! ( V_62 & V_65 ) ) {
if ( V_62 & V_70 ) {
V_63 = ( int ) F_24 ( & V_59 -> args [ 0 ] ) ;
if ( V_63 == V_71 &&
V_56 == V_72 )
return - V_63 ;
if ( V_63 != V_73 ||
V_56 != V_72 )
F_16 ( V_2 , L_7 ,
V_63 , F_17 ( V_56 ) ) ;
return - V_63 ;
}
if ( F_18 ( V_56 ) & V_74 ) {
F_25 () ;
for ( V_60 = 0 ; V_60 < V_68 ; V_60 ++ )
V_2 -> args [ V_60 ] = F_24 ( & V_59 -> args [ V_60 ] ) ;
}
return 0 ;
}
}
F_16 ( V_2 , L_8 , F_17 ( V_56 ) ) ;
return - V_75 ;
}
static int F_26 ( struct V_1 * V_2 , enum V_55 V_56 ,
int V_57 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
struct V_79 * V_80 ;
T_2 V_81 ;
unsigned int V_60 ;
int V_61 , V_63 ;
T_3 V_82 , V_83 ;
T_3 V_84 = V_77 -> V_84 ;
V_82 = F_4 ( & V_77 -> V_85 -> V_82 ) ;
if ( V_82 == 0xFFFFFFFF )
return - V_64 ;
V_83 = ( V_84 + 1 ) % V_86 ;
if ( V_83 == V_82 ) {
F_16 ( V_2 , L_9 ,
F_17 ( V_56 ) , V_82 , V_84 ) ;
return - V_66 ;
}
V_77 -> V_87 [ V_84 ] . V_56 = V_56 ;
V_77 -> V_87 [ V_84 ] . V_88 = 0 ;
if ( ( F_22 ( V_56 ) & V_69 ) )
V_77 -> V_87 [ V_84 ] . V_88 |= V_89 ;
if ( F_18 ( V_56 ) & V_67 )
for ( V_60 = 0 ; V_60 < V_68 ; V_60 ++ )
V_77 -> V_87 [ V_84 ] . args [ V_60 ] = V_2 -> args [ V_60 ] ;
F_20 () ;
F_21 ( V_83 , & V_77 -> V_85 -> V_90 ) ;
V_77 -> V_84 = V_83 ;
if ( V_77 -> V_87 [ V_84 ] . V_88 & V_89 )
return 0 ;
V_80 = V_77 -> V_80 + V_77 -> V_91 ;
V_81 = V_77 -> V_81 ;
V_77 -> V_91 ++ ;
if ( V_77 -> V_91 == V_77 -> V_92 ) {
V_77 -> V_91 = 0 ;
V_77 -> V_81 = V_77 -> V_81 ? 0 : 1 ;
}
for ( V_61 = 0 ; V_61 < V_57 ; V_61 ++ ) {
if ( V_80 -> V_81 == V_81 ) {
if ( V_80 -> error ) {
V_63 = V_80 -> error ;
if ( V_63 != V_73 ||
V_56 != V_72 )
F_16 ( V_2 , L_7 ,
V_63 , F_17 ( V_56 ) ) ;
return - V_63 ;
}
if ( F_18 ( V_56 ) & V_74 )
for ( V_60 = 0 ; V_60 < V_93 ; V_60 ++ )
V_2 -> args [ V_60 ] = V_80 -> V_94 [ V_60 ] ;
return 0 ;
}
F_23 ( 100 ) ;
}
F_16 ( V_2 , L_10 , F_17 ( V_56 ) ) ;
return - V_75 ;
}
static int F_27 ( struct V_1 * V_2 )
{
V_2 -> V_59 = F_7 ( V_2 , V_33 , 0 ) ;
if ( ! V_2 -> V_59 )
return - V_64 ;
V_2 -> V_95 = F_15 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_63 ;
unsigned int V_82 ;
if ( V_2 -> V_78 )
return 0 ;
V_2 -> V_78 = F_29 ( sizeof( * V_2 -> V_78 ) , V_96 ) ;
if ( ! V_2 -> V_78 )
return - V_52 ;
V_2 -> V_78 -> V_81 = 1 ;
V_2 -> V_78 -> V_92 = V_86 ;
V_63 = F_30 ( V_2 , & V_2 -> V_78 -> V_97 , V_86 ,
V_98 ) ;
if ( V_63 )
goto V_99;
V_82 = F_4 ( & V_2 -> V_78 -> V_97 . V_100 -> V_82 ) ;
if ( V_82 == 0xFFFFFFFF ) {
F_3 ( V_2 , L_11 ) ;
V_63 = - V_64 ;
goto V_101;
}
F_31 ( & V_2 -> V_78 -> V_97 , 0 , V_82 , V_82 , 0 ,
0 ) ;
V_2 -> V_78 -> V_84 = V_82 ;
F_32 ( & V_2 -> V_78 -> V_97 ) ;
V_63 = F_11 ( V_2 , & V_2 -> V_78 -> V_102 ,
V_86 , V_98 ) ;
if ( V_63 )
goto V_103;
V_2 -> V_78 -> V_80 = V_2 -> V_78 -> V_102 . V_48 ;
V_2 -> V_78 -> V_87 = V_2 -> V_78 -> V_97 . V_40 . V_48 ;
V_2 -> V_78 -> V_85 = V_2 -> V_78 -> V_97 . V_100 ;
V_2 -> args [ 0 ] = ( V_104 ) V_2 -> V_78 -> V_102 . V_53 |
V_105 ;
V_2 -> args [ 1 ] = V_86 ;
V_63 = F_26 ( V_2 , V_106 , 1000 ) ;
if ( V_63 )
goto V_107;
V_2 -> V_95 = F_26 ;
return 0 ;
V_107:
F_13 ( V_2 , & V_2 -> V_78 -> V_102 ) ;
V_103:
F_33 ( & V_2 -> V_78 -> V_97 ) ;
V_101:
F_34 ( & V_2 -> V_78 -> V_97 ) ;
V_99:
F_35 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
return V_63 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_13 ( V_2 , & V_2 -> V_78 -> V_102 ) ;
F_33 ( & V_2 -> V_78 -> V_97 ) ;
F_34 ( & V_2 -> V_78 -> V_97 ) ;
F_35 ( V_2 -> V_78 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
enum V_55 V_108 , enum V_55 V_56 ,
V_104 * V_109 , V_104 * V_110 , int V_57 )
{
T_3 V_62 ;
int V_63 ;
memset ( V_2 -> args , 0 , sizeof( V_2 -> args ) ) ;
V_2 -> args [ 0 ] = V_2 -> V_111 ;
V_2 -> args [ 1 ] = V_56 ;
V_2 -> args [ 2 ] = * V_109 ;
V_2 -> args [ 3 ] = * V_110 ;
V_63 = V_2 -> V_95 ( V_2 , V_108 , V_57 ) ;
if ( V_63 )
return V_63 ;
V_62 = ( T_3 ) V_2 -> args [ 0 ] ;
if ( V_62 & V_70 ) {
V_63 = ( int ) V_2 -> args [ 1 ] ;
if ( V_63 != V_73 ||
V_56 != V_72 )
F_16 ( V_2 , L_12 ,
V_63 , F_17 ( V_56 ) ) ;
return V_63 ;
}
* V_109 = V_2 -> args [ 1 ] ;
* V_110 = V_2 -> args [ 2 ] ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
enum V_55 V_56 , V_104 * V_109 , V_104 * V_110 , int V_57 )
{
int V_63 ;
V_2 -> args [ 0 ] = * V_109 ;
V_2 -> args [ 1 ] = * V_110 ;
V_63 = V_2 -> V_95 ( V_2 , V_56 , V_57 ) ;
* V_109 = V_2 -> args [ 0 ] ;
* V_110 = V_2 -> args [ 1 ] ;
return V_63 ;
}
void F_39 ( struct V_1 * V_2 , T_4 V_38 )
{
V_2 -> V_112 = V_113 ;
V_2 -> V_111 = V_38 ;
}
void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_112 = V_114 ;
V_2 -> V_111 = 0 ;
}
int F_41 ( struct V_1 * V_2 , enum V_55 V_56 ,
V_104 * V_109 , V_104 * V_110 , int V_57 )
{
memset ( V_2 -> args , 0 , sizeof( V_2 -> args ) ) ;
switch ( V_2 -> V_112 ) {
case V_113 :
return F_37 ( V_2 , V_115 , V_56 ,
V_109 , V_110 , V_57 ) ;
case V_116 :
return F_37 ( V_2 , V_117 , V_56 ,
V_109 , V_110 , V_57 ) ;
case V_114 :
default:
return F_38 ( V_2 , V_56 , V_109 , V_110 , V_57 ) ;
}
}
static int F_42 ( struct V_1 * V_2 , enum V_55 V_56 )
{
V_104 V_109 = ( T_3 ) V_56 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 ;
V_63 = F_41 ( V_2 , V_72 , & V_109 , & V_110 , V_57 ) ;
return ! ( V_63 || V_109 ) ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_118 * * V_119 )
{
V_104 V_109 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 = 0 ;
if ( ! V_2 -> V_119 ) {
V_2 -> V_119 = F_44 ( V_2 -> V_50 ,
sizeof( struct V_118 ) ,
& V_2 -> V_120 ) ;
if ( ! V_2 -> V_119 )
return - V_52 ;
V_109 = V_2 -> V_120 ;
V_110 = sizeof( struct V_118 ) ;
if ( F_42 ( V_2 , V_121 ) )
V_63 = F_41 ( V_2 , V_121 ,
& V_109 , & V_110 , V_57 ) ;
else
V_63 = F_41 ( V_2 , V_122 ,
& V_109 , & V_110 , V_57 ) ;
}
* V_119 = V_2 -> V_119 ;
return V_63 ;
}
int F_45 ( struct V_1 * V_2 , unsigned int V_123 , unsigned int V_46 ,
void * V_124 )
{
V_104 V_109 , V_110 ;
int V_57 = 1000 ;
int V_63 ;
V_109 = V_123 ;
V_110 = V_46 ;
V_63 = F_41 ( V_2 , V_125 , & V_109 , & V_110 , V_57 ) ;
switch ( V_46 ) {
case 1 : * ( T_2 * ) V_124 = ( T_2 ) V_109 ; break;
case 2 : * ( T_4 * ) V_124 = ( T_4 ) V_109 ; break;
case 4 : * ( T_3 * ) V_124 = ( T_3 ) V_109 ; break;
case 8 : * ( V_104 * ) V_124 = V_109 ; break;
default: F_46 () ; break;
}
return V_63 ;
}
int F_47 ( struct V_1 * V_2 , struct V_126 * * V_127 )
{
V_104 V_109 , V_110 ;
int V_57 = 1000 ;
if ( ! V_2 -> V_127 ) {
V_2 -> V_127 = F_12 ( V_2 -> V_50 ,
sizeof( struct V_126 ) , & V_2 -> V_128 ) ;
if ( ! V_2 -> V_127 )
return - V_52 ;
}
* V_127 = V_2 -> V_127 ;
V_109 = V_2 -> V_128 ;
V_110 = sizeof( struct V_126 ) ;
return F_41 ( V_2 , V_129 , & V_109 , & V_110 , V_57 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
return F_41 ( V_2 , V_130 , & V_109 , & V_110 , V_57 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
if ( F_42 ( V_2 , V_131 ) )
return F_41 ( V_2 , V_131 , & V_109 , & V_110 , V_57 ) ;
else
return F_41 ( V_2 , V_132 , & V_109 , & V_110 , V_57 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
return F_41 ( V_2 , V_133 , & V_109 , & V_110 , V_57 ) ;
}
int F_51 ( struct V_1 * V_2 , int V_134 )
{
V_104 V_109 = ( T_3 ) V_134 , V_110 = 0 ;
int V_57 = 1000 ;
return F_41 ( V_2 , V_135 , & V_109 , & V_110 , V_57 ) ;
}
int F_52 ( struct V_1 * V_2 , int * V_136 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 ;
* V_136 = 0 ;
V_63 = F_41 ( V_2 , V_137 , & V_109 , & V_110 , V_57 ) ;
if ( V_63 )
return V_63 ;
* V_136 = ( V_109 == 0 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , int V_134 )
{
V_104 V_109 = ( T_3 ) V_134 , V_110 = 0 ;
int V_57 = 1000 ;
return F_41 ( V_2 , V_138 , & V_109 , & V_110 , V_57 ) ;
}
int F_54 ( struct V_1 * V_2 , int * V_136 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 ;
* V_136 = 0 ;
V_63 = F_41 ( V_2 , V_139 , & V_109 , & V_110 , V_57 ) ;
if ( V_63 )
return V_63 ;
* V_136 = ( V_109 == 0 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , int V_134 )
{
V_104 V_109 = ( T_3 ) V_134 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 ;
if ( F_42 ( V_2 , V_140 ) ) {
return F_41 ( V_2 , V_140 ,
& V_109 , & V_110 , V_57 ) ;
} else {
V_63 = F_53 ( V_2 , V_134 ) ;
if ( V_63 )
return V_63 ;
return F_56 ( V_2 , 0 ) ;
}
}
int F_57 ( struct V_1 * V_2 , int * V_136 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 ;
* V_136 = 0 ;
if ( F_42 ( V_2 , V_141 ) ) {
V_63 = F_41 ( V_2 , V_141 ,
& V_109 , & V_110 , V_57 ) ;
if ( V_63 )
return V_63 ;
} else {
return F_54 ( V_2 , V_136 ) ;
}
* V_136 = ( V_109 == 0 ) ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
V_104 V_109 , V_110 ;
int V_57 = 1000 ;
return F_41 ( V_2 , V_142 , & V_109 , & V_110 , V_57 ) ;
}
int F_59 ( struct V_1 * V_2 , T_2 * V_143 )
{
V_104 V_109 , V_110 ;
int V_57 = 1000 ;
int V_63 , V_60 ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ )
V_143 [ V_60 ] = 0 ;
V_63 = F_41 ( V_2 , V_145 , & V_109 , & V_110 , V_57 ) ;
if ( V_63 )
return V_63 ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ )
V_143 [ V_60 ] = ( ( T_2 * ) & V_109 ) [ V_60 ] ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 , int V_146 , int V_147 ,
int V_148 , int V_149 , int V_150 )
{
V_104 V_109 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 ;
V_109 = ( V_146 ? V_151 : 0 ) |
( V_147 ? V_152 : 0 ) |
( V_148 ? V_153 : 0 ) |
( V_149 ? V_154 : 0 ) |
( V_150 ? V_155 : 0 ) ;
V_63 = F_41 ( V_2 , V_156 , & V_109 , & V_110 , V_57 ) ;
if ( V_63 )
F_16 ( V_2 , L_13 ) ;
return V_63 ;
}
int F_61 ( struct V_1 * V_2 , const T_2 * V_157 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ )
( ( T_2 * ) & V_109 ) [ V_60 ] = V_157 [ V_60 ] ;
V_63 = F_41 ( V_2 , V_158 , & V_109 , & V_110 , V_57 ) ;
if ( V_63 )
F_16 ( V_2 , L_14 , V_157 , V_63 ) ;
return V_63 ;
}
int F_62 ( struct V_1 * V_2 , const T_2 * V_157 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
int V_63 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ )
( ( T_2 * ) & V_109 ) [ V_60 ] = V_157 [ V_60 ] ;
V_63 = F_41 ( V_2 , V_159 , & V_109 , & V_110 , V_57 ) ;
if ( V_63 )
F_16 ( V_2 , L_15 , V_157 , V_63 ) ;
return V_63 ;
}
int F_63 ( struct V_1 * V_2 ,
T_2 V_160 )
{
V_104 V_109 = V_160 , V_110 = 0 ;
int V_57 = 1000 ;
if ( F_42 ( V_2 , V_161 ) )
return F_41 ( V_2 , V_161 ,
& V_109 , & V_110 , V_57 ) ;
else
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
void * V_162 , T_5 V_163 , T_4 V_164 )
{
V_104 V_109 , V_110 ;
int V_57 = 1000 ;
int V_12 ;
memset ( V_162 , 0 , sizeof( struct V_165 ) ) ;
V_2 -> V_166 = V_162 ;
V_2 -> V_163 = V_163 ;
V_109 = ( V_104 ) V_163 ;
V_110 = ( ( V_104 ) V_164 << 32 ) & 0x0000ffff00000000ULL ;
V_110 += sizeof( struct V_165 ) ;
V_12 = F_41 ( V_2 , V_167 , & V_109 , & V_110 , V_57 ) ;
V_2 -> V_168 = ( V_12 == 0 ) ? ( T_3 ) V_110 : 0 ;
return V_12 ;
}
int F_65 ( struct V_1 * V_2 , T_4 V_164 )
{
void * V_162 ;
T_5 V_163 ;
if ( V_2 -> V_166 || V_2 -> V_163 ) {
F_16 ( V_2 , L_16 ,
V_2 -> V_166 ) ;
return - V_13 ;
}
V_162 = F_12 ( V_2 -> V_50 ,
sizeof( struct V_165 ) ,
& V_163 ) ;
if ( ! V_162 )
return - V_52 ;
return F_64 ( V_2 , V_162 , V_163 , V_164 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
V_104 V_109 , V_110 ;
int V_57 = 1000 ;
int V_63 ;
V_109 = 0 ;
V_110 = 0x0000ffff00000000ULL ;
V_110 += sizeof( struct V_165 ) ;
V_63 = F_41 ( V_2 , V_167 , & V_109 , & V_110 , V_57 ) ;
V_2 -> V_166 = NULL ;
V_2 -> V_163 = 0 ;
V_2 -> V_168 = 0 ;
return V_63 ;
}
int F_67 ( struct V_1 * V_2 )
{
if ( V_2 -> V_166 ) {
F_14 ( V_2 -> V_50 ,
sizeof( struct V_165 ) ,
V_2 -> V_166 ,
V_2 -> V_163 ) ;
}
return F_66 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
T_3 * V_169 ;
unsigned int V_170 = V_2 -> V_168 / 4 ;
unsigned int V_60 ;
T_3 V_171 ;
if ( ! V_2 -> V_166 || ! V_2 -> V_168 )
return 0 ;
do {
V_171 = 0 ;
memcpy ( & V_2 -> V_172 , V_2 -> V_166 , V_2 -> V_168 ) ;
V_169 = ( T_3 * ) & V_2 -> V_172 ;
for ( V_60 = 1 ; V_60 < V_170 ; V_60 ++ )
V_171 += V_169 [ V_60 ] ;
} while ( V_171 != V_169 [ 0 ] );
return 1 ;
}
int F_56 ( struct V_1 * V_2 , int V_134 )
{
V_104 V_109 = ( T_3 ) V_134 , V_110 = 0 ;
int V_57 = 1000 ;
int V_12 = 0 ;
if ( F_42 ( V_2 , V_173 ) )
V_12 = F_41 ( V_2 , V_173 , & V_109 , & V_110 , V_57 ) ;
else {
F_41 ( V_2 , V_174 , & V_109 , & V_110 , V_57 ) ;
if ( V_109 & V_175 ) {
F_41 ( V_2 , V_145 , & V_109 , & V_110 , V_57 ) ;
F_41 ( V_2 , V_158 , & V_109 , & V_110 , V_57 ) ;
}
}
return V_12 ;
}
int F_69 ( struct V_1 * V_2 )
{
V_104 V_109 = 0 , V_110 = 0 ;
int V_57 = 1000 ;
return F_41 ( V_2 , V_176 , & V_109 , & V_110 , V_57 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
V_2 -> V_177 . V_178 = 2 ;
V_2 -> V_177 . div = 3 ;
V_2 -> V_177 . V_179 =
F_71 ( V_2 , 0xffff ) ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_57 = 1000 ;
int V_63 ;
memset ( V_2 -> args , 0 , sizeof( V_2 -> args ) ) ;
if ( F_42 ( V_2 , V_180 ) )
V_63 = V_2 -> V_95 ( V_2 , V_180 , V_57 ) ;
else
V_63 = V_73 ;
if ( ( V_63 == V_73 ) ||
( ! V_63 && ! ( V_2 -> args [ 0 ] && V_2 -> args [ 1 ] && V_2 -> args [ 2 ] ) ) ) {
F_73 ( V_2 , L_17 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
if ( ! V_63 ) {
V_2 -> V_177 . V_178 = ( T_3 ) V_2 -> args [ 0 ] ;
V_2 -> V_177 . div = ( T_3 ) V_2 -> args [ 1 ] ;
V_2 -> V_177 . V_179 = ( T_3 ) V_2 -> args [ 2 ] ;
}
return V_63 ;
}
int F_74 ( struct V_1 * V_2 )
{
if ( ! F_68 ( V_2 ) )
return 0 ;
return V_2 -> V_172 . V_181 ;
}
T_3 F_75 ( struct V_1 * V_2 )
{
if ( ! F_68 ( V_2 ) )
return 0 ;
return V_2 -> V_172 . V_182 ;
}
T_3 F_76 ( struct V_1 * V_2 )
{
if ( ! F_68 ( V_2 ) )
return 0 ;
return V_2 -> V_172 . V_183 ;
}
T_3 F_77 ( struct V_1 * V_2 )
{
if ( ! F_68 ( V_2 ) )
return 0 ;
return V_2 -> V_172 . V_184 ;
}
void F_78 ( struct V_1 * V_2 ,
enum V_185 V_186 )
{
V_2 -> V_186 = V_186 ;
}
enum V_185 F_79 (
struct V_1 * V_2 )
{
return V_2 -> V_186 ;
}
T_3 F_80 ( struct V_1 * V_2 , T_3 V_187 )
{
return ( V_187 * V_2 -> V_177 . V_178 ) /
V_2 -> V_177 . div ;
}
T_3 F_71 ( struct V_1 * V_2 , T_3 V_188 )
{
return ( V_188 * V_2 -> V_177 . div ) /
V_2 -> V_177 . V_178 ;
}
T_3 F_81 ( struct V_1 * V_2 )
{
return V_2 -> V_177 . V_179 ;
}
void F_82 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_166 )
F_14 ( V_2 -> V_50 ,
sizeof( struct V_165 ) ,
V_2 -> V_166 ,
V_2 -> V_163 ) ;
if ( V_2 -> V_127 )
F_14 ( V_2 -> V_50 ,
sizeof( struct V_126 ) ,
V_2 -> V_127 , V_2 -> V_128 ) ;
if ( V_2 -> V_119 )
F_14 ( V_2 -> V_50 ,
sizeof( struct V_118 ) ,
V_2 -> V_119 , V_2 -> V_120 ) ;
if ( V_2 -> V_78 )
F_36 ( V_2 ) ;
F_35 ( V_2 ) ;
}
}
struct V_1 * F_83 ( struct V_1 * V_2 ,
void * V_3 , struct V_189 * V_50 , struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( ! V_2 ) {
V_2 = F_29 ( sizeof( struct V_1 ) , V_190 ) ;
if ( ! V_2 )
return NULL ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_50 = V_50 ;
if ( F_2 ( V_2 , V_5 , V_6 ) )
goto V_191;
return V_2 ;
V_191:
F_82 ( V_2 ) ;
return NULL ;
}
struct V_189 * F_84 ( struct V_1 * V_2 )
{
return V_2 -> V_50 ;
}
int F_85 ( struct V_1 * V_2 )
{
void T_1 * V_35 ;
int V_63 ;
V_35 = F_7 ( V_2 , V_34 , 0 ) ;
if ( V_35 ) {
V_63 = F_28 ( V_2 ) ;
if ( V_63 )
F_86 ( V_2 , L_18 ,
V_63 ) ;
else
return 0 ;
} else {
F_86 ( V_2 , L_19 ) ;
}
V_63 = F_27 ( V_2 ) ;
if ( V_63 )
F_3 ( V_2 , L_20 , V_63 ) ;
return V_63 ;
}
int F_87 ( struct V_1 * V_2 , T_2 * V_192 , T_3 V_14 )
{
V_104 V_109 , V_110 = V_14 ;
int V_57 = 1000 ;
T_5 V_193 ;
void * V_194 ;
int V_195 ;
V_194 = F_12 ( V_2 -> V_50 , V_14 , & V_193 ) ;
if ( ! V_194 )
return - V_52 ;
memcpy ( V_194 , V_192 , V_14 ) ;
V_109 = V_193 ;
V_195 = F_41 ( V_2 , V_196 , & V_109 , & V_110 , V_57 ) ;
F_14 ( V_2 -> V_50 , V_14 , V_194 , V_193 ) ;
return V_195 ;
}
int F_88 ( struct V_1 * V_2 , int V_197 )
{
V_104 V_109 , V_110 = 0 ;
int V_57 = 1000 ;
V_109 = ( V_197 ? V_198 : 0 ) ;
return F_41 ( V_2 , V_199 , & V_109 , & V_110 , V_57 ) ;
}
static int F_89 ( struct V_1 * V_2 , enum V_55 V_56 ,
int * V_62 )
{
V_104 V_109 = V_56 , V_110 = 0 ;
int V_57 = 1000 ;
int V_195 ;
V_195 = F_41 ( V_2 , V_200 , & V_109 , & V_110 , V_57 ) ;
if ( ! V_195 )
* V_62 = ( int ) V_109 ;
return V_195 ;
}
int F_90 ( struct V_1 * V_2 , int * V_62 )
{
return F_89 ( V_2 , V_199 , V_62 ) ;
}
int F_91 ( struct V_1 * V_2 , int * V_62 )
{
return F_89 ( V_2 , V_176 , V_62 ) ;
}
int F_92 ( struct V_1 * V_2 , T_2 * V_143 )
{
V_104 V_109 , V_110 ;
int V_57 = 1000 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ )
( ( T_2 * ) & V_109 ) [ V_60 ] = V_143 [ V_60 ] ;
return F_41 ( V_2 , V_201 , & V_109 , & V_110 , V_57 ) ;
}
int F_93 ( struct V_1 * V_2 , T_2 V_56 , T_4 * V_202 ,
struct V_203 * V_204 )
{
V_104 V_109 , V_110 ;
int V_57 = 1000 ;
T_5 V_205 ;
int V_195 = - V_13 ;
struct V_206 * V_207 , * V_208 ;
struct V_209 * V_210 ;
V_104 V_211 ;
if ( V_56 == V_212 ) {
V_211 = sizeof( struct V_203 ) +
sizeof( struct V_209 ) +
2 * sizeof( struct V_206 ) ;
V_208 = F_12 ( V_2 -> V_50 , V_211 , & V_205 ) ;
if ( ! V_208 )
return - V_52 ;
V_207 = V_208 ;
V_109 = V_205 ;
V_110 = V_211 ;
memset ( V_207 , 0 , V_211 ) ;
V_207 -> type = V_213 ;
V_207 -> V_214 = sizeof( struct V_203 ) ;
* (struct V_203 * ) & V_207 -> V_215 = * V_204 ;
V_207 = (struct V_206 * ) ( ( char * ) V_207 +
sizeof( struct V_206 ) +
sizeof( struct V_203 ) ) ;
V_207 -> type = V_216 ;
V_207 -> V_214 = sizeof( struct V_209 ) ;
V_210 = (struct V_209 * ) & V_207 -> V_215 ;
V_210 -> type = V_217 ;
V_210 -> V_218 . V_219 = * V_202 ;
V_195 = F_41 ( V_2 , V_220 , & V_109 , & V_110 , V_57 ) ;
* V_202 = ( T_4 ) V_109 ;
F_14 ( V_2 -> V_50 , V_211 , V_208 , V_205 ) ;
} else if ( V_56 == V_221 ) {
V_109 = * V_202 ;
V_195 = F_41 ( V_2 , V_222 , & V_109 , & V_110 , V_57 ) ;
}
return V_195 ;
}
int F_94 ( struct V_1 * V_2 , T_2 V_223 , T_2 V_224 )
{
V_104 V_109 = V_223 ;
V_104 V_110 = V_224 ;
int V_57 = 1000 ;
return F_41 ( V_2 , V_225 , & V_109 , & V_110 , V_57 ) ;
}
int F_95 ( struct V_1 * V_2 , T_2 V_223 ,
T_4 V_226 )
{
V_104 V_110 = V_226 ;
V_104 V_109 = V_223 ;
int V_57 = 1000 ;
return F_41 ( V_2 , V_227 , & V_109 , & V_110 , V_57 ) ;
}
int F_96 ( struct V_1 * V_2 , T_2 V_228 ,
V_104 * V_229 )
{
V_104 V_109 = V_228 ;
int V_57 = 1000 ;
V_104 V_110 = 0 ;
int V_195 ;
V_195 = F_41 ( V_2 , V_230 , & V_109 , & V_110 , V_57 ) ;
if ( ! V_195 )
* V_229 = V_109 ;
return V_195 ;
}
