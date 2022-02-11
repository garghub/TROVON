static inline T_1 F_1 ( const T_2 * V_1 )
{
return 3 + ( ( V_1 [ 1 ] & 0x0f ) << 8 ) + V_1 [ 2 ] ;
}
static inline T_1 F_2 ( const T_2 * V_1 )
{
return ( ( V_1 [ 1 ] & 0x1f ) << 8 ) + V_1 [ 2 ] ;
}
static inline T_2 F_3 ( const T_2 * V_2 )
{
if ( ! ( V_2 [ 3 ] & 0x10 ) )
return 0 ;
if ( V_2 [ 3 ] & 0x20 ) {
if ( V_2 [ 4 ] > 183 )
return 0 ;
else
return 184 - 1 - V_2 [ 4 ] ;
}
return 184 ;
}
static T_3 F_4 ( struct V_3 * V_4 , const T_2 * V_5 , T_4 V_6 )
{
return ( V_4 -> V_7 . V_8 . V_9 = F_5 ( V_4 -> V_7 . V_8 . V_9 , V_5 , V_6 ) ) ;
}
static void F_6 ( struct V_3 * V_4 , T_2 * V_10 , const T_2 * V_11 ,
T_4 V_6 )
{
memcpy ( V_10 , V_11 , V_6 ) ;
}
static inline int F_7 ( struct V_3 * V_7 ,
const T_2 * V_1 )
{
int V_12 = F_3 ( V_1 ) ;
int V_13 ;
if ( V_12 == 0 )
return - 1 ;
V_13 = 188 - V_12 ;
if ( V_1 [ 1 ] & 0x40 )
V_7 -> V_14 = 0xfffa ;
V_7 -> V_14 += V_12 ;
return V_7 -> V_15 . V_16 ( & V_1 [ V_13 ] , V_12 , NULL , 0 , & V_7 -> V_7 . V_16 , V_17 ) ;
}
static int F_8 ( struct V_3 * V_7 ,
struct V_18 * V_4 )
{
T_2 V_19 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
T_2 V_22 = V_4 -> V_23 . V_24 [ V_20 ] ^ V_7 -> V_7 . V_8 . V_25 [ V_20 ] ;
if ( V_4 -> V_26 [ V_20 ] & V_22 )
return 0 ;
V_19 |= V_4 -> V_27 [ V_20 ] & V_22 ;
}
if ( V_4 -> V_28 && ! V_19 )
return 0 ;
return V_7 -> V_15 . V_8 ( V_7 -> V_7 . V_8 . V_25 , V_7 -> V_7 . V_8 . V_29 ,
NULL , 0 , & V_4 -> V_23 , V_17 ) ;
}
static inline int F_9 ( struct V_3 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
struct V_18 * V_4 = V_7 -> V_23 ;
struct V_32 * V_8 = & V_7 -> V_7 . V_8 ;
int V_33 ;
if ( ! V_8 -> V_34 )
return 0 ;
if ( ! V_4 )
return 0 ;
if ( V_8 -> V_35 ) {
V_33 = ( ( V_8 -> V_25 [ 1 ] & 0x80 ) != 0 ) ;
if ( V_33 &&
V_31 -> V_36 ( V_7 , V_8 -> V_25 , V_8 -> V_29 ) )
return - 1 ;
}
do {
if ( F_8 ( V_7 , V_4 ) < 0 )
return - 1 ;
} while ( ( V_4 = V_4 -> V_37 ) && V_8 -> V_34 );
V_8 -> V_29 = 0 ;
return 0 ;
}
static void F_10 ( struct V_3 * V_7 )
{
struct V_32 * V_8 = & V_7 -> V_7 . V_8 ;
#ifdef F_11
if ( V_8 -> V_38 < V_8 -> V_39 ) {
int V_20 , V_40 = V_8 -> V_39 - V_8 -> V_38 ;
if ( V_8 -> V_25 [ 0 ] != 0xff || V_8 -> V_25 [ V_40 - 1 ] != 0xff ) {
F_12 ( L_1 ,
V_40 , V_8 -> V_39 ) ;
F_12 ( L_2 ) ;
for ( V_20 = 0 ; V_20 < V_40 ; V_20 ++ )
F_12 ( L_3 , V_8 -> V_25 [ V_20 ] ) ;
F_12 ( L_4 ) ;
}
}
#endif
V_8 -> V_39 = V_8 -> V_38 = V_8 -> V_29 = 0 ;
V_8 -> V_25 = V_8 -> V_41 ;
}
static int F_13 ( struct V_3 * V_7 ,
const T_2 * V_1 , T_2 V_6 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
struct V_32 * V_8 = & V_7 -> V_7 . V_8 ;
T_1 V_42 , V_29 , V_40 ;
if ( V_8 -> V_39 >= V_43 )
return 0 ;
if ( V_8 -> V_39 + V_6 > V_43 ) {
#ifdef F_11
F_12 ( L_5 ,
V_8 -> V_39 + V_6 - V_43 ,
V_43 ) ;
#endif
V_6 = V_43 - V_8 -> V_39 ;
}
if ( V_6 <= 0 )
return 0 ;
V_31 -> V_44 ( V_7 , V_8 -> V_41 + V_8 -> V_39 , V_1 , V_6 ) ;
V_8 -> V_39 += V_6 ;
V_42 = V_8 -> V_39 ;
if ( V_42 > V_43 )
return - 1 ;
V_8 -> V_25 = V_8 -> V_41 + V_8 -> V_38 ;
for ( V_40 = 0 ; V_8 -> V_38 + 2 < V_42 ; V_40 ++ ) {
V_29 = F_1 ( V_8 -> V_25 ) ;
if ( V_29 <= 0 || V_29 > V_45
|| V_29 + V_8 -> V_38 > V_42 )
return 0 ;
V_8 -> V_29 = V_29 ;
V_8 -> V_9 = ~ 0 ;
if ( V_7 -> V_46 )
F_9 ( V_7 ) ;
#ifdef F_11
else
F_12 ( L_6 ) ;
#endif
V_8 -> V_38 += V_29 ;
V_8 -> V_25 += V_29 ;
}
return 0 ;
}
static int F_14 ( struct V_3 * V_7 ,
const T_2 * V_1 )
{
T_2 V_13 , V_12 ;
int V_47 , V_48 = 0 ;
T_2 V_49 ;
V_12 = F_3 ( V_1 ) ;
if ( V_12 == 0 )
return - 1 ;
V_13 = 188 - V_12 ;
V_49 = V_1 [ 3 ] & 0x0f ;
V_47 = ( ( V_7 -> V_49 + 1 ) & 0x0f ) == V_49 ;
V_7 -> V_49 = V_49 ;
if ( V_1 [ 3 ] & 0x20 ) {
if ( ( V_1 [ 4 ] > 0 ) && ( V_1 [ 5 ] & 0x80 ) )
V_48 = 1 ;
}
if ( ! V_47 || V_48 ) {
#ifdef F_11
F_12 ( L_7 ,
V_12 ) ;
#endif
V_7 -> V_46 = 0 ;
F_10 ( V_7 ) ;
}
if ( V_1 [ 1 ] & 0x40 ) {
if ( V_12 > 1 && V_1 [ V_13 ] < V_12 ) {
const T_2 * V_50 = & V_1 [ V_13 + 1 ] ;
T_2 V_51 = V_1 [ V_13 ] ;
const T_2 * V_52 = & V_50 [ V_51 ] ;
T_2 V_53 = V_12 - 1 - V_51 ;
F_13 ( V_7 , V_50 ,
V_51 ) ;
V_7 -> V_46 = 1 ;
F_10 ( V_7 ) ;
F_13 ( V_7 , V_52 ,
V_53 ) ;
}
#ifdef F_11
else if ( V_12 > 0 )
F_12 ( L_8 , V_12 ) ;
#endif
} else {
F_13 ( V_7 , & V_1 [ V_13 ] , V_12 ) ;
}
return 0 ;
}
static inline void F_15 ( struct V_3 * V_7 ,
const T_2 * V_1 )
{
switch ( V_7 -> type ) {
case V_54 :
if ( ! V_7 -> V_7 . V_16 . V_34 )
break;
if ( V_7 -> V_55 & V_56 ) {
if ( V_7 -> V_55 & V_57 )
F_7 ( V_7 , V_1 ) ;
else
V_7 -> V_15 . V_16 ( V_1 , 188 , NULL , 0 , & V_7 -> V_7 . V_16 ,
V_17 ) ;
}
if ( V_7 -> V_55 & V_58 )
if ( V_7 -> V_31 -> V_59 )
V_7 -> V_31 -> V_59 ( V_7 , V_1 , 188 ) ;
break;
case V_60 :
if ( ! V_7 -> V_7 . V_8 . V_34 )
break;
if ( F_14 ( V_7 , V_1 ) < 0 )
V_7 -> V_7 . V_8 . V_29 = V_7 -> V_7 . V_8 . V_38 = 0 ;
break;
default:
break;
}
}
static void F_16 ( struct V_30 * V_31 , const T_2 * V_1 )
{
struct V_3 * V_7 ;
T_1 V_61 = F_2 ( V_1 ) ;
int V_62 = 0 ;
if ( V_63 ) {
struct V_64 V_65 , V_66 ;
T_5 V_67 , V_68 ;
V_31 -> V_69 ++ ;
if ( ! ( V_31 -> V_69 % V_70 ) ) {
V_65 = F_17 () ;
if ( V_31 -> V_71 . V_72 != 0 &&
V_31 -> V_71 . V_73 != 0 ) {
V_66 = F_18 ( V_65 ,
V_31 -> V_71 ) ;
V_67 = ( T_5 ) V_31 -> V_69
* 188 * 8 ;
V_67 = 1000 * F_19 ( V_67 ,
1024 ) ;
V_68 =
( T_5 ) F_20 ( & V_66 ) ;
V_68 = F_19 ( V_68 ,
1000000 ) ;
F_12 ( V_74 L_9 ,
F_19 ( V_67 ,
V_68 ) ) ;
}
V_31 -> V_71 = V_65 ;
V_31 -> V_69 = 0 ;
}
}
if ( V_1 [ 1 ] & 0x80 ) {
F_21 ( L_10
L_11 ,
V_61 , V_1 [ 1 ] ) ;
if ( ! V_75 )
return;
} else
if ( V_31 -> V_76 && V_77 ) {
if ( V_61 < V_78 ) {
if ( V_1 [ 3 ] & 0x10 )
V_31 -> V_76 [ V_61 ] =
( V_31 -> V_76 [ V_61 ] + 1 ) & 0xf ;
if ( ( V_1 [ 3 ] & 0xf ) != V_31 -> V_76 [ V_61 ] ) {
F_21 ( L_12 ,
V_61 , V_31 -> V_76 [ V_61 ] ,
V_1 [ 3 ] & 0xf ) ;
V_31 -> V_76 [ V_61 ] = V_1 [ 3 ] & 0xf ;
}
}
}
F_22 (feed, &demux->feed_list, list_head) {
if ( ( V_7 -> V_61 != V_61 ) && ( V_7 -> V_61 != 0x2000 ) )
continue;
if ( ( F_23 ( V_7 ) ) && ( V_62 ++ ) )
continue;
if ( V_7 -> V_61 == V_61 )
F_15 ( V_7 , V_1 ) ;
else if ( V_7 -> V_61 == 0x2000 )
V_7 -> V_15 . V_16 ( V_1 , 188 , NULL , 0 , & V_7 -> V_7 . V_16 , V_17 ) ;
}
}
void F_24 ( struct V_30 * V_31 , const T_2 * V_1 ,
T_4 V_12 )
{
F_25 ( & V_31 -> V_79 ) ;
while ( V_12 -- ) {
if ( V_1 [ 0 ] == 0x47 )
F_16 ( V_31 , V_1 ) ;
V_1 += 188 ;
}
F_26 ( & V_31 -> V_79 ) ;
}
static inline int F_27 ( const T_2 * V_1 , int V_80 , T_4 V_12 ,
const int V_81 )
{
int V_82 = V_80 , V_83 ;
while ( V_80 < V_12 ) {
if ( V_1 [ V_80 ] == 0x47 ||
( V_81 == 204 && V_1 [ V_80 ] == 0xB8 ) )
break;
V_80 ++ ;
}
V_83 = V_80 - V_82 ;
if ( V_83 ) {
int V_84 = V_80 - V_81 ;
if ( V_84 >= 0 && ( V_1 [ V_84 ] == 0x47 ||
( V_81 == 204 && V_1 [ V_84 ] == 0xB8 ) ) )
return V_84 ;
}
return V_80 ;
}
static inline void F_28 ( struct V_30 * V_31 , const T_2 * V_1 ,
T_4 V_12 , const int V_81 )
{
int V_13 = 0 , V_20 , V_85 ;
const T_2 * V_86 ;
F_25 ( & V_31 -> V_79 ) ;
if ( V_31 -> V_87 ) {
V_20 = V_31 -> V_87 ;
V_85 = V_81 - V_20 ;
if ( V_12 < V_85 ) {
memcpy ( & V_31 -> V_88 [ V_20 ] , V_1 , V_12 ) ;
V_31 -> V_87 += V_12 ;
goto V_89;
}
memcpy ( & V_31 -> V_88 [ V_20 ] , V_1 , V_85 ) ;
if ( V_31 -> V_88 [ 0 ] == 0x47 )
F_16 ( V_31 , V_31 -> V_88 ) ;
V_31 -> V_87 = 0 ;
V_13 += V_85 ;
}
while ( 1 ) {
V_13 = F_27 ( V_1 , V_13 , V_12 , V_81 ) ;
if ( V_13 >= V_12 )
break;
if ( V_12 - V_13 < V_81 )
break;
V_86 = & V_1 [ V_13 ] ;
if ( V_81 == 204 && ( * V_86 == 0xB8 ) ) {
memcpy ( V_31 -> V_88 , V_86 , 188 ) ;
V_31 -> V_88 [ 0 ] = 0x47 ;
V_86 = V_31 -> V_88 ;
}
F_16 ( V_31 , V_86 ) ;
V_13 += V_81 ;
}
V_20 = V_12 - V_13 ;
if ( V_20 ) {
memcpy ( V_31 -> V_88 , & V_1 [ V_13 ] , V_20 ) ;
V_31 -> V_87 = V_20 ;
if ( V_81 == 204 && V_31 -> V_88 [ 0 ] == 0xB8 )
V_31 -> V_88 [ 0 ] = 0x47 ;
}
V_89:
F_26 ( & V_31 -> V_79 ) ;
}
void F_29 ( struct V_30 * V_31 , const T_2 * V_1 , T_4 V_12 )
{
F_28 ( V_31 , V_1 , V_12 , 188 ) ;
}
void F_30 ( struct V_30 * V_31 , const T_2 * V_1 , T_4 V_12 )
{
F_28 ( V_31 , V_1 , V_12 , 204 ) ;
}
void F_31 ( struct V_30 * V_31 , const T_2 * V_1 , T_4 V_12 )
{
F_25 ( & V_31 -> V_79 ) ;
V_31 -> V_7 -> V_15 . V_16 ( V_1 , V_12 , NULL , 0 , & V_31 -> V_7 -> V_7 . V_16 , V_17 ) ;
F_26 ( & V_31 -> V_79 ) ;
}
static struct V_18 * F_32 ( struct V_30 * V_31 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_31 -> V_90 ; V_20 ++ )
if ( V_31 -> V_23 [ V_20 ] . V_91 == V_92 )
break;
if ( V_20 == V_31 -> V_90 )
return NULL ;
V_31 -> V_23 [ V_20 ] . V_91 = V_93 ;
return & V_31 -> V_23 [ V_20 ] ;
}
static struct V_3 * F_33 ( struct V_30 * V_31 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_31 -> V_94 ; V_20 ++ )
if ( V_31 -> V_7 [ V_20 ] . V_91 == V_92 )
break;
if ( V_20 == V_31 -> V_94 )
return NULL ;
V_31 -> V_7 [ V_20 ] . V_91 = V_93 ;
return & V_31 -> V_7 [ V_20 ] ;
}
static int F_34 ( struct V_3 * V_7 )
{
struct V_3 * V_95 ;
F_22 (entry, &feed->demux->feed_list, list_head)
if ( V_95 == V_7 )
return 1 ;
return 0 ;
}
static void F_35 ( struct V_3 * V_7 )
{
F_36 ( & V_7 -> V_31 -> V_79 ) ;
if ( F_34 ( V_7 ) ) {
F_12 ( V_96 L_13 ,
V_97 , V_7 -> type , V_7 -> V_91 , V_7 -> V_61 ) ;
goto V_98;
}
F_37 ( & V_7 -> V_99 , & V_7 -> V_31 -> V_100 ) ;
V_98:
F_38 ( & V_7 -> V_31 -> V_79 ) ;
}
static void F_39 ( struct V_3 * V_7 )
{
F_36 ( & V_7 -> V_31 -> V_79 ) ;
if ( ! ( F_34 ( V_7 ) ) ) {
F_12 ( V_96 L_14 ,
V_97 , V_7 -> type , V_7 -> V_91 , V_7 -> V_61 ) ;
goto V_98;
}
F_40 ( & V_7 -> V_99 ) ;
V_98:
F_38 ( & V_7 -> V_31 -> V_79 ) ;
}
static int F_41 ( struct V_101 * V_102 , T_1 V_61 , int V_55 ,
enum V_103 V_104 ,
T_4 V_105 , struct V_64 V_106 )
{
struct V_3 * V_7 = (struct V_3 * ) V_102 ;
struct V_30 * V_31 = V_7 -> V_31 ;
if ( V_61 > V_107 )
return - V_108 ;
if ( F_42 ( & V_31 -> V_109 ) )
return - V_110 ;
if ( V_55 & V_58 ) {
if ( V_104 >= V_111 ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_108 ;
}
if ( V_31 -> V_112 [ V_104 ] &&
V_31 -> V_112 [ V_104 ] != V_7 ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_108 ;
}
V_31 -> V_112 [ V_104 ] = V_7 ;
V_31 -> V_113 [ V_104 ] = V_61 ;
}
F_35 ( V_7 ) ;
V_7 -> V_61 = V_61 ;
V_7 -> V_114 = V_105 ;
V_7 -> V_106 = V_106 ;
V_7 -> V_55 = V_55 ;
V_7 -> V_104 = V_104 ;
if ( V_7 -> V_114 ) {
#ifdef F_44
V_7 -> V_115 = NULL ;
#else
V_7 -> V_115 = F_45 ( V_7 -> V_114 ) ;
if ( ! V_7 -> V_115 ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_116 ;
}
#endif
}
V_7 -> V_91 = V_117 ;
F_43 ( & V_31 -> V_109 ) ;
return 0 ;
}
static int F_46 ( struct V_101 * V_102 )
{
struct V_3 * V_7 = (struct V_3 * ) V_102 ;
struct V_30 * V_31 = V_7 -> V_31 ;
int V_118 ;
if ( F_42 ( & V_31 -> V_109 ) )
return - V_110 ;
if ( V_7 -> V_91 != V_117 || V_7 -> type != V_54 ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_108 ;
}
if ( ! V_31 -> V_119 ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_120 ;
}
if ( ( V_118 = V_31 -> V_119 ( V_7 ) ) < 0 ) {
F_43 ( & V_31 -> V_109 ) ;
return V_118 ;
}
F_36 ( & V_31 -> V_79 ) ;
V_102 -> V_34 = 1 ;
V_7 -> V_91 = V_121 ;
F_38 ( & V_31 -> V_79 ) ;
F_43 ( & V_31 -> V_109 ) ;
return 0 ;
}
static int F_47 ( struct V_101 * V_102 )
{
struct V_3 * V_7 = (struct V_3 * ) V_102 ;
struct V_30 * V_31 = V_7 -> V_31 ;
int V_118 ;
F_48 ( & V_31 -> V_109 ) ;
if ( V_7 -> V_91 < V_121 ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_108 ;
}
if ( ! V_31 -> V_122 ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_120 ;
}
V_118 = V_31 -> V_122 ( V_7 ) ;
F_36 ( & V_31 -> V_79 ) ;
V_102 -> V_34 = 0 ;
V_7 -> V_91 = V_93 ;
F_38 ( & V_31 -> V_79 ) ;
F_43 ( & V_31 -> V_109 ) ;
return V_118 ;
}
static int F_49 ( struct V_123 * V_124 ,
struct V_101 * * V_102 ,
T_6 V_125 )
{
struct V_30 * V_31 = (struct V_30 * ) V_124 ;
struct V_3 * V_7 ;
if ( F_42 ( & V_31 -> V_109 ) )
return - V_110 ;
if ( ! ( V_7 = F_33 ( V_31 ) ) ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_126 ;
}
V_7 -> type = V_54 ;
V_7 -> V_15 . V_16 = V_125 ;
V_7 -> V_31 = V_31 ;
V_7 -> V_61 = 0xffff ;
V_7 -> V_14 = 0xfffa ;
V_7 -> V_115 = NULL ;
( * V_102 ) = & V_7 -> V_7 . V_16 ;
( * V_102 ) -> V_127 = V_124 ;
( * V_102 ) -> V_128 = NULL ;
( * V_102 ) -> V_34 = 0 ;
( * V_102 ) -> V_129 = F_46 ;
( * V_102 ) -> V_130 = F_47 ;
( * V_102 ) -> V_131 = F_41 ;
if ( ! ( V_7 -> V_23 = F_32 ( V_31 ) ) ) {
V_7 -> V_91 = V_92 ;
F_43 ( & V_31 -> V_109 ) ;
return - V_126 ;
}
V_7 -> V_23 -> type = V_54 ;
V_7 -> V_23 -> V_7 = V_7 ;
V_7 -> V_23 -> V_91 = V_117 ;
F_43 ( & V_31 -> V_109 ) ;
return 0 ;
}
static int F_50 ( struct V_123 * V_124 ,
struct V_101 * V_102 )
{
struct V_30 * V_31 = (struct V_30 * ) V_124 ;
struct V_3 * V_7 = (struct V_3 * ) V_102 ;
F_48 ( & V_31 -> V_109 ) ;
if ( V_7 -> V_91 == V_92 ) {
F_43 ( & V_31 -> V_109 ) ;
return - V_108 ;
}
#ifndef F_44
F_51 ( V_7 -> V_115 ) ;
V_7 -> V_115 = NULL ;
#endif
V_7 -> V_91 = V_92 ;
V_7 -> V_23 -> V_91 = V_92 ;
F_39 ( V_7 ) ;
V_7 -> V_61 = 0xffff ;
if ( V_7 -> V_55 & V_58 && V_7 -> V_104 < V_111 )
V_31 -> V_112 [ V_7 -> V_104 ] = NULL ;
F_43 ( & V_31 -> V_109 ) ;
return 0 ;
}
static int F_52 ( struct V_32 * V_7 ,
struct V_132 * * V_23 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_30 * V_134 = V_133 -> V_31 ;
struct V_18 * V_135 ;
if ( F_42 ( & V_134 -> V_109 ) )
return - V_110 ;
V_135 = F_32 ( V_134 ) ;
if ( ! V_135 ) {
F_43 ( & V_134 -> V_109 ) ;
return - V_126 ;
}
F_36 ( & V_134 -> V_79 ) ;
* V_23 = & V_135 -> V_23 ;
( * V_23 ) -> V_127 = V_7 ;
( * V_23 ) -> V_128 = NULL ;
V_135 -> V_7 = V_133 ;
V_135 -> type = V_60 ;
V_135 -> V_91 = V_117 ;
V_135 -> V_37 = V_133 -> V_23 ;
V_133 -> V_23 = V_135 ;
F_38 ( & V_134 -> V_79 ) ;
F_43 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_53 ( struct V_32 * V_7 ,
T_1 V_61 , T_4 V_105 ,
int V_35 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_30 * V_136 = V_133 -> V_31 ;
if ( V_61 > 0x1fff )
return - V_108 ;
if ( F_42 ( & V_136 -> V_109 ) )
return - V_110 ;
F_35 ( V_133 ) ;
V_133 -> V_61 = V_61 ;
V_133 -> V_114 = V_105 ;
V_133 -> V_7 . V_8 . V_35 = V_35 ;
#ifdef F_44
V_133 -> V_115 = NULL ;
#else
V_133 -> V_115 = F_45 ( V_133 -> V_114 ) ;
if ( ! V_133 -> V_115 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_116 ;
}
#endif
V_133 -> V_91 = V_117 ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static void F_54 ( struct V_3 * V_133 )
{
int V_20 ;
struct V_18 * V_4 ;
struct V_132 * V_137 ;
T_2 V_138 , V_139 , V_28 ;
if ( ! ( V_4 = V_133 -> V_23 ) )
return;
do {
V_137 = & V_4 -> V_23 ;
V_28 = 0 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_139 = V_137 -> V_140 [ V_20 ] ;
V_138 = V_137 -> V_141 [ V_20 ] ;
V_4 -> V_26 [ V_20 ] = V_138 & V_139 ;
V_28 |= V_4 -> V_27 [ V_20 ] = V_138 & ~ V_139 ;
}
V_4 -> V_28 = V_28 ? 1 : 0 ;
} while ( ( V_4 = V_4 -> V_37 ) );
}
static int F_55 ( struct V_32 * V_7 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_30 * V_136 = V_133 -> V_31 ;
int V_118 ;
if ( F_42 ( & V_136 -> V_109 ) )
return - V_110 ;
if ( V_7 -> V_34 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_126 ;
}
if ( ! V_133 -> V_23 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_108 ;
}
V_133 -> V_7 . V_8 . V_39 = 0 ;
V_133 -> V_7 . V_8 . V_25 = V_133 -> V_7 . V_8 . V_41 ;
V_133 -> V_7 . V_8 . V_38 = 0 ;
V_133 -> V_7 . V_8 . V_29 = 0 ;
if ( ! V_136 -> V_119 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_120 ;
}
F_54 ( V_133 ) ;
if ( ( V_118 = V_136 -> V_119 ( V_133 ) ) < 0 ) {
F_43 ( & V_136 -> V_109 ) ;
return V_118 ;
}
F_36 ( & V_136 -> V_79 ) ;
V_7 -> V_34 = 1 ;
V_133 -> V_91 = V_121 ;
F_38 ( & V_136 -> V_79 ) ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static int F_56 ( struct V_32 * V_7 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_30 * V_136 = V_133 -> V_31 ;
int V_118 ;
F_48 ( & V_136 -> V_109 ) ;
if ( ! V_136 -> V_122 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_120 ;
}
V_118 = V_136 -> V_122 ( V_133 ) ;
F_36 ( & V_136 -> V_79 ) ;
V_133 -> V_91 = V_117 ;
V_7 -> V_34 = 0 ;
F_38 ( & V_136 -> V_79 ) ;
F_43 ( & V_136 -> V_109 ) ;
return V_118 ;
}
static int F_57 ( struct V_32 * V_7 ,
struct V_132 * V_23 )
{
struct V_18 * V_135 = (struct V_18 * ) V_23 , * V_4 ;
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_30 * V_136 = V_133 -> V_31 ;
F_48 ( & V_136 -> V_109 ) ;
if ( V_135 -> V_7 != V_133 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_108 ;
}
if ( V_7 -> V_34 )
V_7 -> V_130 ( V_7 ) ;
F_36 ( & V_136 -> V_79 ) ;
V_4 = V_133 -> V_23 ;
if ( V_4 == V_135 ) {
V_133 -> V_23 = V_135 -> V_37 ;
} else {
while ( V_4 -> V_37 != V_135 )
V_4 = V_4 -> V_37 ;
V_4 -> V_37 = V_4 -> V_37 -> V_37 ;
}
V_135 -> V_91 = V_92 ;
F_38 ( & V_136 -> V_79 ) ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static int F_58 ( struct V_123 * V_31 ,
struct V_32 * * V_7 ,
T_7 V_125 )
{
struct V_30 * V_136 = (struct V_30 * ) V_31 ;
struct V_3 * V_133 ;
if ( F_42 ( & V_136 -> V_109 ) )
return - V_110 ;
if ( ! ( V_133 = F_33 ( V_136 ) ) ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_126 ;
}
V_133 -> type = V_60 ;
V_133 -> V_15 . V_8 = V_125 ;
V_133 -> V_31 = V_136 ;
V_133 -> V_61 = 0xffff ;
V_133 -> V_7 . V_8 . V_25 = V_133 -> V_7 . V_8 . V_41 ;
V_133 -> V_7 . V_8 . V_38 = V_133 -> V_7 . V_8 . V_29 = 0 ;
V_133 -> V_7 . V_8 . V_39 = 0 ;
V_133 -> V_23 = NULL ;
V_133 -> V_115 = NULL ;
( * V_7 ) = & V_133 -> V_7 . V_8 ;
( * V_7 ) -> V_34 = 0 ;
( * V_7 ) -> V_127 = V_31 ;
( * V_7 ) -> V_128 = NULL ;
( * V_7 ) -> V_131 = F_53 ;
( * V_7 ) -> V_142 = F_52 ;
( * V_7 ) -> V_129 = F_55 ;
( * V_7 ) -> V_130 = F_56 ;
( * V_7 ) -> V_143 = F_57 ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static int F_59 ( struct V_123 * V_31 ,
struct V_32 * V_7 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_30 * V_136 = (struct V_30 * ) V_31 ;
F_48 ( & V_136 -> V_109 ) ;
if ( V_133 -> V_91 == V_92 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_108 ;
}
#ifndef F_44
F_51 ( V_133 -> V_115 ) ;
V_133 -> V_115 = NULL ;
#endif
V_133 -> V_91 = V_92 ;
F_39 ( V_133 ) ;
V_133 -> V_61 = 0xffff ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static int F_60 ( struct V_123 * V_31 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
if ( V_134 -> V_144 >= V_145 )
return - V_146 ;
V_134 -> V_144 ++ ;
return 0 ;
}
static int F_61 ( struct V_123 * V_31 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
if ( V_134 -> V_144 == 0 )
return - V_120 ;
V_134 -> V_144 -- ;
return 0 ;
}
static int F_62 ( struct V_123 * V_31 , const char T_8 * V_1 , T_4 V_12 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
void * V_13 ;
if ( ( ! V_31 -> V_147 ) || ( V_31 -> V_147 -> V_148 != V_149 ) )
return - V_108 ;
V_13 = F_63 ( V_1 , V_12 ) ;
if ( F_64 ( V_13 ) )
return F_65 ( V_13 ) ;
if ( F_42 ( & V_134 -> V_109 ) ) {
F_66 ( V_13 ) ;
return - V_110 ;
}
F_29 ( V_134 , V_13 , V_12 ) ;
F_66 ( V_13 ) ;
F_43 ( & V_134 -> V_109 ) ;
if ( F_67 ( V_150 ) )
return - V_151 ;
return V_12 ;
}
static int F_68 ( struct V_123 * V_31 ,
struct V_152 * V_147 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
struct V_99 * V_153 = & V_134 -> V_154 ;
F_37 ( & ( V_147 -> V_155 ) , V_153 ) ;
return 0 ;
}
static int F_69 ( struct V_123 * V_31 ,
struct V_152 * V_147 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
struct V_99 * V_80 , * V_40 , * V_153 = & V_134 -> V_154 ;
F_70 (pos, n, head) {
if ( F_71 ( V_80 ) == V_147 ) {
F_40 ( V_80 ) ;
return 0 ;
}
}
return - V_120 ;
}
static struct V_99 * F_72 ( struct V_123 * V_31 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
if ( F_73 ( & V_134 -> V_154 ) )
return NULL ;
return & V_134 -> V_154 ;
}
static int F_74 ( struct V_123 * V_31 ,
struct V_152 * V_147 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
if ( V_31 -> V_147 )
return - V_108 ;
F_48 ( & V_134 -> V_109 ) ;
V_31 -> V_147 = V_147 ;
F_43 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_75 ( struct V_123 * V_31 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
F_48 ( & V_134 -> V_109 ) ;
V_31 -> V_147 = NULL ;
F_43 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_76 ( struct V_123 * V_31 , T_1 * V_113 )
{
struct V_30 * V_134 = (struct V_30 * ) V_31 ;
memcpy ( V_113 , V_134 -> V_113 , 5 * sizeof( T_1 ) ) ;
return 0 ;
}
int F_77 ( struct V_30 * V_134 )
{
int V_20 ;
struct V_123 * V_124 = & V_134 -> V_124 ;
V_134 -> V_76 = NULL ;
V_134 -> V_144 = 0 ;
V_134 -> V_23 = F_45 ( V_134 -> V_90 * sizeof( struct V_18 ) ) ;
if ( ! V_134 -> V_23 )
return - V_116 ;
V_134 -> V_7 = F_45 ( V_134 -> V_94 * sizeof( struct V_3 ) ) ;
if ( ! V_134 -> V_7 ) {
F_51 ( V_134 -> V_23 ) ;
V_134 -> V_23 = NULL ;
return - V_116 ;
}
for ( V_20 = 0 ; V_20 < V_134 -> V_90 ; V_20 ++ ) {
V_134 -> V_23 [ V_20 ] . V_91 = V_92 ;
V_134 -> V_23 [ V_20 ] . V_156 = V_20 ;
}
for ( V_20 = 0 ; V_20 < V_134 -> V_94 ; V_20 ++ ) {
V_134 -> V_7 [ V_20 ] . V_91 = V_92 ;
V_134 -> V_7 [ V_20 ] . V_156 = V_20 ;
}
V_134 -> V_76 = F_45 ( V_78 + 1 ) ;
if ( ! V_134 -> V_76 )
F_12 ( V_157 L_15 ) ;
F_78 ( & V_134 -> V_154 ) ;
for ( V_20 = 0 ; V_20 < V_111 ; V_20 ++ ) {
V_134 -> V_112 [ V_20 ] = NULL ;
V_134 -> V_113 [ V_20 ] = 0xffff ;
}
F_78 ( & V_134 -> V_100 ) ;
V_134 -> V_158 = 0 ;
V_134 -> V_159 = 0 ;
V_134 -> V_87 = 0 ;
if ( ! V_134 -> V_36 )
V_134 -> V_36 = F_4 ;
if ( ! V_134 -> V_44 )
V_134 -> V_44 = F_6 ;
V_124 -> V_147 = NULL ;
V_124 -> V_128 = V_134 ;
V_124 -> V_160 = F_60 ;
V_124 -> V_161 = F_61 ;
V_124 -> V_162 = F_62 ;
V_124 -> V_163 = F_49 ;
V_124 -> V_164 = F_50 ;
V_124 -> V_165 = F_58 ;
V_124 -> V_166 = F_59 ;
V_124 -> V_167 = F_68 ;
V_124 -> V_168 = F_69 ;
V_124 -> V_169 = F_72 ;
V_124 -> V_170 = F_74 ;
V_124 -> V_171 = F_75 ;
V_124 -> V_172 = F_76 ;
F_79 ( & V_134 -> V_109 ) ;
F_80 ( & V_134 -> V_79 ) ;
return 0 ;
}
void F_81 ( struct V_30 * V_134 )
{
F_51 ( V_134 -> V_76 ) ;
F_51 ( V_134 -> V_23 ) ;
F_51 ( V_134 -> V_7 ) ;
}
