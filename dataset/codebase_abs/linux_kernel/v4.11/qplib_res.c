static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool V_5 )
{
int V_6 ;
if ( ! V_5 ) {
for ( V_6 = 0 ; V_6 < V_4 -> V_7 ; V_6 ++ ) {
if ( V_4 -> V_8 [ V_6 ] )
F_2 ( & V_2 -> V_9 , V_4 -> V_10 ,
( void * ) ( ( unsigned long )
V_4 -> V_8 [ V_6 ] &
V_11 ) ,
V_4 -> V_12 [ V_6 ] ) ;
else
F_3 ( & V_2 -> V_9 ,
L_1 ,
V_6 ) ;
V_4 -> V_8 [ V_6 ] = NULL ;
}
}
F_4 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
F_4 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
V_4 -> V_7 = 0 ;
V_4 -> V_10 = 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 , T_1 V_15 , T_1 V_10 )
{
struct V_13 * V_16 ;
bool V_5 = false ;
int V_6 ;
V_4 -> V_8 = F_6 ( V_15 , sizeof( void * ) , V_17 ) ;
if ( ! V_4 -> V_8 )
return - V_18 ;
V_4 -> V_12 = F_6 ( V_15 , sizeof( V_19 ) , V_17 ) ;
if ( ! V_4 -> V_12 ) {
F_4 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return - V_18 ;
}
V_4 -> V_7 = 0 ;
V_4 -> V_10 = V_10 ;
if ( ! V_14 ) {
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
V_4 -> V_8 [ V_6 ] = F_7 ( & V_2 -> V_9 ,
V_4 -> V_10 ,
& V_4 -> V_12 [ V_6 ] ,
V_17 ) ;
if ( ! V_4 -> V_8 [ V_6 ] )
goto V_20;
memset ( V_4 -> V_8 [ V_6 ] , 0 , V_4 -> V_10 ) ;
V_4 -> V_7 ++ ;
}
} else {
V_6 = 0 ;
V_5 = true ;
F_8 (sghead, sg, pages, i) {
V_4 -> V_12 [ V_6 ] = F_9 ( V_16 ) ;
V_4 -> V_8 [ V_6 ] = F_10 ( V_16 ) ;
if ( ! V_4 -> V_8 [ V_6 ] )
goto V_20;
V_4 -> V_7 ++ ;
}
}
return 0 ;
V_20:
F_1 ( V_2 , V_4 , V_5 ) ;
return - V_18 ;
}
void F_11 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_6 ;
if ( ! V_22 -> V_23 )
return;
if ( V_22 -> V_24 >= V_25 )
return;
for ( V_6 = 0 ; V_6 < V_22 -> V_24 + 1 ; V_6 ++ ) {
if ( V_6 == V_22 -> V_24 )
F_1 ( V_2 , & V_22 -> V_4 [ V_6 ] , V_22 -> V_26 ) ;
else
F_1 ( V_2 , & V_22 -> V_4 [ V_6 ] , false ) ;
}
V_22 -> V_24 = V_25 ;
V_22 -> V_23 = 0 ;
V_22 -> V_27 = 0 ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = 0 ;
V_22 -> V_30 = 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_13 * V_14 , int V_31 ,
T_1 * V_32 , T_1 V_27 , T_1 V_33 ,
T_1 V_10 , enum V_34 V_35 )
{
T_1 V_15 , V_36 , V_37 , V_38 = 0 , V_39 = 0 ;
V_19 * V_40 , * * V_41 ;
int V_6 , V_42 ;
V_22 -> V_24 = V_25 ;
V_36 = F_13 ( * V_32 ) ;
if ( V_33 ) {
V_39 = F_13 ( V_33 ) ;
V_38 = ( V_36 * V_39 ) / V_10 ;
if ( ( V_36 * V_39 ) % V_10 )
V_38 ++ ;
}
V_37 = F_13 ( V_27 ) ;
if ( ! V_14 ) {
V_22 -> V_26 = false ;
V_15 = ( V_36 * V_37 ) / V_10 + V_38 ;
if ( ( V_36 * V_37 ) % V_10 )
V_15 ++ ;
if ( ! V_15 )
return - V_43 ;
} else {
V_22 -> V_26 = true ;
V_15 = V_31 ;
}
if ( V_14 && ( V_15 == V_44 ) )
V_42 = F_5 ( V_2 , & V_22 -> V_4 [ V_45 ] , V_14 ,
V_15 , V_10 ) ;
else
V_42 = F_5 ( V_2 , & V_22 -> V_4 [ V_45 ] , NULL , 1 , V_10 ) ;
if ( V_42 )
goto V_20;
V_22 -> V_24 = V_45 ;
if ( V_15 > V_44 ) {
if ( V_15 > V_46 ) {
V_42 = F_5 ( V_2 , & V_22 -> V_4 [ V_47 ] , NULL ,
V_48 , V_10 ) ;
if ( V_42 )
goto V_20;
V_41 =
( V_19 * * ) V_22 -> V_4 [ V_45 ] . V_8 ;
V_40 = V_22 -> V_4 [ V_47 ] . V_12 ;
for ( V_6 = 0 ; V_6 < V_22 -> V_4 [ V_47 ] . V_7 ; V_6 ++ )
V_41 [ F_14 ( V_6 ) ] [ F_15 ( V_6 ) ] =
V_40 [ V_6 ] | V_49 ;
V_22 -> V_24 = V_47 ;
V_42 = F_5 ( V_2 , & V_22 -> V_4 [ V_50 ] , V_14 ,
V_15 , V_10 ) ;
if ( V_42 )
goto V_20;
V_41 =
( V_19 * * ) V_22 -> V_4 [ V_47 ] . V_8 ;
V_40 = V_22 -> V_4 [ V_50 ] . V_12 ;
for ( V_6 = 0 ; V_6 < V_22 -> V_4 [ V_50 ] . V_7 ; V_6 ++ ) {
V_41 [ F_14 ( V_6 ) ] [ F_15 ( V_6 ) ] =
V_40 [ V_6 ] | V_51 ;
}
if ( V_35 == V_52 ) {
V_6 = V_22 -> V_4 [ V_50 ] . V_7 ;
V_41 [ F_14 ( V_6 - 1 ) ] [ F_15 ( V_6 - 1 ) ] |=
V_53 ;
if ( V_6 > 1 )
V_41 [ F_14 ( V_6 - 2 ) ]
[ F_15 ( V_6 - 2 ) ] |=
V_54 ;
}
V_22 -> V_24 = V_50 ;
} else {
T_1 V_55 = V_35 == V_56 ? 0 :
V_51 ;
V_42 = F_5 ( V_2 , & V_22 -> V_4 [ V_47 ] , V_14 ,
V_15 , V_10 ) ;
if ( V_42 )
goto V_20;
V_41 =
( V_19 * * ) V_22 -> V_4 [ V_45 ] . V_8 ;
V_40 = V_22 -> V_4 [ V_47 ] . V_12 ;
for ( V_6 = 0 ; V_6 < V_22 -> V_4 [ V_47 ] . V_7 ; V_6 ++ ) {
V_41 [ F_14 ( V_6 ) ] [ F_15 ( V_6 ) ] =
V_40 [ V_6 ] | V_55 ;
}
if ( V_35 == V_52 ) {
V_6 = V_22 -> V_4 [ V_47 ] . V_7 ;
V_41 [ F_14 ( V_6 - 1 ) ] [ F_15 ( V_6 - 1 ) ] |=
V_53 ;
if ( V_6 > 1 )
V_41 [ F_14 ( V_6 - 2 ) ]
[ F_15 ( V_6 - 2 ) ] |=
V_54 ;
}
V_22 -> V_24 = V_47 ;
}
}
V_22 -> V_2 = V_2 ;
F_16 ( & V_22 -> V_57 ) ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = 0 ;
* V_32 = V_22 -> V_23 = V_36 ;
V_22 -> V_27 = V_37 ;
V_22 -> V_58 = V_22 -> V_4 [ V_22 -> V_24 ] . V_8 ;
V_22 -> V_59 = V_22 -> V_4 [ V_22 -> V_24 ] . V_12 ;
return 0 ;
V_20:
F_11 ( V_2 , V_22 ) ;
return - V_18 ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
int V_6 ;
F_11 ( V_2 , & V_61 -> V_62 ) ;
F_11 ( V_2 , & V_61 -> V_63 ) ;
F_11 ( V_2 , & V_61 -> V_64 ) ;
F_11 ( V_2 , & V_61 -> V_65 ) ;
F_11 ( V_2 , & V_61 -> V_66 ) ;
for ( V_6 = 0 ; V_6 < V_67 ; V_6 ++ )
F_11 ( V_2 , & V_61 -> V_68 [ V_6 ] ) ;
F_11 ( V_2 , & V_61 -> V_69 ) ;
F_18 ( V_2 , & V_61 -> V_70 ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_60 * V_61 ,
bool V_71 )
{
int V_6 , V_72 , V_73 , V_42 = 0 ;
int V_74 = - 1 ;
T_2 * * V_58 ;
if ( V_71 )
goto V_75;
V_61 -> V_62 . V_23 = V_61 -> V_76 ;
V_42 = F_12 ( V_2 , & V_61 -> V_62 , NULL , 0 ,
& V_61 -> V_62 . V_23 ,
V_77 , 0 ,
V_78 , V_79 ) ;
if ( V_42 )
goto V_20;
V_61 -> V_63 . V_23 = V_61 -> V_80 ;
V_42 = F_12 ( V_2 , & V_61 -> V_63 , NULL , 0 ,
& V_61 -> V_63 . V_23 ,
V_81 , 0 ,
V_78 , V_79 ) ;
if ( V_42 )
goto V_20;
V_61 -> V_64 . V_23 = V_61 -> V_82 ;
V_42 = F_12 ( V_2 , & V_61 -> V_64 , NULL , 0 ,
& V_61 -> V_64 . V_23 ,
V_83 , 0 ,
V_78 , V_79 ) ;
if ( V_42 )
goto V_20;
V_61 -> V_65 . V_23 = V_61 -> V_84 ;
V_42 = F_12 ( V_2 , & V_61 -> V_65 , NULL , 0 ,
& V_61 -> V_65 . V_23 ,
V_85 , 0 ,
V_78 , V_79 ) ;
if ( V_42 )
goto V_20;
V_61 -> V_69 . V_23 = 512 ;
V_42 = F_12 ( V_2 , & V_61 -> V_69 , NULL , 0 ,
& V_61 -> V_69 . V_23 , sizeof( V_86 ) ,
0 , V_78 , V_79 ) ;
if ( V_42 )
goto V_20;
for ( V_6 = 0 ; V_6 < V_67 ; V_6 ++ ) {
if ( ! V_61 -> V_87 [ V_6 ] )
continue;
V_61 -> V_68 [ V_6 ] . V_23 = V_61 -> V_76 *
V_61 -> V_87 [ V_6 ] ;
V_42 = F_12 ( V_2 , & V_61 -> V_68 [ V_6 ] , NULL , 0 ,
& V_61 -> V_68 [ V_6 ] . V_23 , 1 ,
0 , V_78 , V_79 ) ;
if ( V_42 )
goto V_20;
}
V_58 = ( T_2 * * ) V_61 -> V_69 . V_58 ;
for ( V_6 = 0 , V_72 = 0 ; V_6 < V_67 ;
V_6 ++ , V_72 += V_88 ) {
if ( ! V_61 -> V_68 [ V_6 ] . V_23 )
continue;
if ( V_74 == - 1 )
V_74 = V_6 ;
switch ( V_61 -> V_68 [ V_6 ] . V_24 ) {
case V_50 :
for ( V_73 = 0 ; V_73 < V_61 -> V_68 [ V_6 ] . V_4 [ V_47 ] . V_7 ;
V_73 ++ )
V_58 [ F_14 ( V_72 + V_73 ) ] [ F_15 ( V_72 + V_73 ) ] =
F_20 (
V_61 -> V_68 [ V_6 ] . V_4 [ V_47 ] . V_12 [ V_73 ]
| V_51 ) ;
break;
case V_47 :
case V_45 :
default:
V_58 [ F_14 ( V_72 ) ] [ F_15 ( V_72 ) ] = F_20 (
V_61 -> V_68 [ V_6 ] . V_4 [ V_45 ] . V_12 [ 0 ] |
V_51 ) ;
break;
}
}
if ( V_74 == - 1 )
V_74 = 0 ;
V_61 -> V_89 = V_61 -> V_68 [ V_74 ] . V_24 == V_50 ?
V_50 : V_61 -> V_68 [ V_74 ] . V_24 + 1 ;
V_61 -> V_66 . V_23 = V_61 -> V_76 * 16 ;
V_42 = F_12 ( V_2 , & V_61 -> V_66 , NULL , 0 ,
& V_61 -> V_66 . V_23 , 1 ,
0 , V_78 , V_79 ) ;
if ( V_42 )
goto V_20;
V_75:
V_42 = F_21 ( V_2 , & V_61 -> V_70 ) ;
if ( V_42 )
goto V_20;
return 0 ;
V_20:
F_17 ( V_2 , V_61 ) ;
return V_42 ;
}
void F_22 ( T_3 * V_90 , T_3 * V_91 )
{
T_3 V_92 [ V_93 ] ;
memcpy ( V_92 , V_90 , V_93 ) ;
V_91 [ 0 ] = V_92 [ 0 ] ^ 2 ;
V_91 [ 1 ] = V_92 [ 1 ] ;
V_91 [ 2 ] = V_92 [ 2 ] ;
V_91 [ 3 ] = 0xff ;
V_91 [ 4 ] = 0xfe ;
V_91 [ 5 ] = V_92 [ 3 ] ;
V_91 [ 6 ] = V_92 [ 4 ] ;
V_91 [ 7 ] = V_92 [ 5 ] ;
}
static void F_23 ( struct V_94 * V_95 ,
struct V_96 * V_97 )
{
F_4 ( V_97 -> V_98 ) ;
F_4 ( V_97 -> V_99 ) ;
F_4 ( V_97 -> V_61 ) ;
V_97 -> V_98 = NULL ;
V_97 -> V_99 = NULL ;
V_97 -> V_61 = NULL ;
V_97 -> V_100 = 0 ;
V_97 -> V_101 = 0 ;
}
static int F_24 ( struct V_94 * V_95 ,
struct V_96 * V_97 ,
T_4 V_100 )
{
V_97 -> V_98 = F_6 ( V_100 , sizeof( struct V_102 ) , V_17 ) ;
if ( ! V_97 -> V_98 )
return - V_18 ;
V_97 -> V_99 = F_6 ( V_100 , sizeof( T_4 ) , V_17 ) ;
if ( ! V_97 -> V_99 )
goto V_103;
V_97 -> V_61 = F_6 ( V_100 , sizeof( void * ) , V_17 ) ;
if ( ! V_97 -> V_61 )
goto V_104;
V_97 -> V_100 = V_100 ;
return 0 ;
V_104:
F_4 ( V_97 -> V_99 ) ;
V_97 -> V_99 = NULL ;
V_103:
F_4 ( V_97 -> V_98 ) ;
V_97 -> V_98 = NULL ;
return - V_18 ;
}
static void F_25 ( struct V_94 * V_95 ,
struct V_96 * V_97 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_97 -> V_100 ; V_6 ++ ) {
if ( memcmp ( & V_97 -> V_98 [ V_6 ] , & V_105 ,
sizeof( V_105 ) ) )
F_26 ( V_97 , & V_97 -> V_98 [ V_6 ] , true ) ;
}
memset ( V_97 -> V_98 , 0 , sizeof( struct V_102 ) * V_97 -> V_100 ) ;
memset ( V_97 -> V_99 , - 1 , sizeof( T_4 ) * V_97 -> V_100 ) ;
V_97 -> V_101 = 0 ;
}
static void F_27 ( struct V_96 * V_97 ,
struct V_106 * V_107 )
{
memset ( V_97 -> V_98 , 0 , sizeof( struct V_102 ) * V_97 -> V_100 ) ;
memset ( V_97 -> V_99 , - 1 , sizeof( T_4 ) * V_97 -> V_100 ) ;
}
static void F_28 ( struct V_94 * V_95 ,
struct V_108 * V_109 )
{
if ( ! V_109 -> V_98 )
F_29 ( & V_95 -> V_2 -> V_9 , L_2 ) ;
else
F_4 ( V_109 -> V_98 ) ;
V_109 -> V_98 = NULL ;
V_109 -> V_100 = 0 ;
V_109 -> V_101 = 0 ;
}
static int F_30 ( struct V_94 * V_95 ,
struct V_108 * V_109 ,
T_4 V_100 )
{
V_109 -> V_98 = F_6 ( V_100 , sizeof( T_4 ) , V_17 ) ;
if ( ! V_109 -> V_98 )
return - V_18 ;
V_109 -> V_100 = V_100 ;
return 0 ;
}
int F_31 ( struct V_110 * V_111 , struct V_112 * V_113 )
{
T_1 V_114 ;
V_114 = F_32 ( V_111 -> V_98 , V_111 -> V_100 ) ;
if ( V_114 == V_111 -> V_100 )
return - V_18 ;
F_33 ( V_114 , V_111 -> V_98 ) ;
V_113 -> V_115 = V_114 ;
return 0 ;
}
int F_34 ( struct V_94 * V_95 ,
struct V_110 * V_111 ,
struct V_112 * V_113 )
{
if ( F_35 ( V_113 -> V_115 , V_111 -> V_98 ) ) {
F_3 ( & V_95 -> V_2 -> V_9 , L_3 ,
V_113 -> V_115 ) ;
return - V_43 ;
}
V_113 -> V_115 = 0 ;
return 0 ;
}
static void F_36 ( struct V_110 * V_111 )
{
F_4 ( V_111 -> V_98 ) ;
V_111 -> V_98 = NULL ;
V_111 -> V_100 = 0 ;
}
static int F_37 ( struct V_94 * V_95 ,
struct V_110 * V_111 ,
T_1 V_100 )
{
T_1 V_116 ;
V_116 = V_100 >> 3 ;
if ( ! V_116 )
V_116 = 1 ;
V_111 -> V_98 = F_38 ( V_116 , V_17 ) ;
if ( ! V_111 -> V_98 )
return - V_18 ;
V_111 -> V_100 = V_100 ;
memset ( ( T_3 * ) V_111 -> V_98 , 0xFF , V_116 ) ;
return 0 ;
}
int F_39 ( struct V_117 * V_118 ,
struct V_119 * V_120 ,
void * V_121 )
{
T_1 V_114 ;
V_114 = F_32 ( V_118 -> V_98 , V_118 -> V_100 ) ;
if ( V_114 == V_118 -> V_100 )
return - V_18 ;
F_33 ( V_114 , V_118 -> V_98 ) ;
V_118 -> V_122 [ V_114 ] = V_121 ;
V_120 -> V_120 = V_114 ;
V_120 -> V_123 = V_118 -> V_124 + ( V_114 * V_78 ) ;
V_120 -> V_125 = V_118 -> V_126 + ( V_114 * V_78 ) ;
return 0 ;
}
int F_40 ( struct V_94 * V_95 ,
struct V_117 * V_118 ,
struct V_119 * V_120 )
{
if ( V_120 -> V_120 >= V_118 -> V_100 ) {
F_3 ( & V_95 -> V_2 -> V_9 , L_4 , V_120 -> V_120 ) ;
return - V_43 ;
}
if ( F_35 ( V_120 -> V_120 , V_118 -> V_98 ) ) {
F_3 ( & V_95 -> V_2 -> V_9 , L_5 ,
V_120 -> V_120 ) ;
return - V_43 ;
}
if ( V_118 -> V_122 )
V_118 -> V_122 [ V_120 -> V_120 ] = NULL ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
return 0 ;
}
static void F_41 ( struct V_94 * V_95 ,
struct V_117 * V_118 )
{
F_4 ( V_118 -> V_98 ) ;
F_4 ( V_118 -> V_122 ) ;
if ( V_118 -> V_124 )
F_42 ( V_95 -> V_2 , V_118 -> V_124 ) ;
memset ( V_118 , 0 , sizeof( * V_118 ) ) ;
}
static int F_43 ( struct V_94 * V_95 ,
struct V_117 * V_118 ,
T_1 V_127 )
{
T_1 V_128 = V_129 ;
T_5 V_130 ;
T_1 V_131 , V_116 ;
if ( V_118 -> V_124 ) {
F_44 ( & V_95 -> V_2 -> V_9 ,
L_6 , V_128 ) ;
return - V_132 ;
}
V_130 = F_45 ( V_95 -> V_2 , V_128 ) ;
if ( ! V_130 ) {
F_44 ( & V_95 -> V_2 -> V_9 ,
L_7 , V_128 ) ;
return - V_18 ;
}
V_131 = F_46 ( V_95 -> V_2 , V_128 ) - V_127 ;
if ( ! V_131 || ( ( V_131 & ( V_78 - 1 ) ) != 0 ) ) {
F_44 ( & V_95 -> V_2 -> V_9 , L_8 ,
V_131 ) ;
return - V_18 ;
}
V_118 -> V_124 = F_47 ( V_130 + V_127 ,
V_131 ) ;
if ( ! V_118 -> V_124 ) {
F_44 ( & V_95 -> V_2 -> V_9 ,
L_9 ,
V_128 ) ;
return - V_18 ;
}
V_118 -> V_126 = V_130 + V_127 ;
V_118 -> V_100 = V_131 / V_78 ;
V_118 -> V_122 = F_6 ( V_118 -> V_100 , sizeof( void * ) , V_17 ) ;
if ( ! V_118 -> V_122 ) {
F_42 ( V_95 -> V_2 , V_118 -> V_124 ) ;
F_44 ( & V_95 -> V_2 -> V_9 ,
L_10 ) ;
return - V_18 ;
}
V_116 = V_118 -> V_100 >> 3 ;
if ( ! V_116 )
V_116 = 1 ;
V_118 -> V_98 = F_38 ( V_116 , V_17 ) ;
if ( ! V_118 -> V_98 ) {
F_42 ( V_95 -> V_2 , V_118 -> V_124 ) ;
F_4 ( V_118 -> V_122 ) ;
V_118 -> V_122 = NULL ;
F_44 ( & V_95 -> V_2 -> V_9 ,
L_11 ,
V_116 ) ;
return - V_18 ;
}
memset ( ( T_3 * ) V_118 -> V_98 , 0xFF , V_116 ) ;
return 0 ;
}
static void F_48 ( struct V_108 * V_109 )
{
memset ( V_109 -> V_98 , 0 , sizeof( T_4 ) * V_109 -> V_100 ) ;
V_109 -> V_101 = 0 ;
}
static void F_49 ( struct V_94 * V_95 ,
struct V_108 * V_109 )
{
T_4 V_133 = 0xFFFF ;
memset ( V_109 -> V_98 , 0 , sizeof( T_4 ) * V_109 -> V_100 ) ;
F_50 ( V_95 , V_109 , & V_133 , false ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_134 * V_70 )
{
if ( V_70 -> V_135 ) {
F_2 ( & V_2 -> V_9 , V_70 -> V_37 ,
V_70 -> V_135 , V_70 -> V_136 ) ;
}
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
V_70 -> V_137 = - 1 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_134 * V_70 )
{
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
V_70 -> V_137 = - 1 ;
V_70 -> V_37 = sizeof( struct V_138 ) ;
V_70 -> V_135 = F_7 ( & V_2 -> V_9 , V_70 -> V_37 ,
& V_70 -> V_136 , V_17 ) ;
if ( ! V_70 -> V_135 ) {
F_44 ( & V_2 -> V_9 , L_12 ) ;
return - V_18 ;
}
return 0 ;
}
void F_51 ( struct V_94 * V_95 )
{
F_48 ( & V_95 -> V_109 ) ;
F_25 ( V_95 , & V_95 -> V_97 ) ;
}
int F_52 ( struct V_94 * V_95 )
{
F_27 ( & V_95 -> V_97 , V_95 -> V_107 ) ;
F_49 ( V_95 , & V_95 -> V_109 ) ;
return 0 ;
}
void F_53 ( struct V_94 * V_95 )
{
F_28 ( V_95 , & V_95 -> V_109 ) ;
F_23 ( V_95 , & V_95 -> V_97 ) ;
F_36 ( & V_95 -> V_139 ) ;
F_41 ( V_95 , & V_95 -> V_140 ) ;
V_95 -> V_107 = NULL ;
V_95 -> V_2 = NULL ;
}
int F_54 ( struct V_94 * V_95 , struct V_1 * V_2 ,
struct V_106 * V_107 ,
struct V_141 * V_142 )
{
int V_42 = 0 ;
V_95 -> V_2 = V_2 ;
V_95 -> V_107 = V_107 ;
V_42 = F_24 ( V_95 , & V_95 -> V_97 , V_142 -> V_143 ) ;
if ( V_42 )
goto V_20;
V_42 = F_30 ( V_95 , & V_95 -> V_109 , V_142 -> V_144 ) ;
if ( V_42 )
goto V_20;
V_42 = F_37 ( V_95 , & V_95 -> V_139 , V_142 -> V_145 ) ;
if ( V_42 )
goto V_20;
V_42 = F_43 ( V_95 , & V_95 -> V_140 , V_142 -> V_146 ) ;
if ( V_42 )
goto V_20;
return 0 ;
V_20:
F_53 ( V_95 ) ;
return V_42 ;
}
