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
return V_7 -> V_15 . V_16 ( & V_1 [ V_13 ] , V_12 , NULL , 0 , & V_7 -> V_7 . V_16 ) ;
}
static int F_8 ( struct V_3 * V_7 ,
struct V_17 * V_4 )
{
T_2 V_18 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
T_2 V_21 = V_4 -> V_22 . V_23 [ V_19 ] ^ V_7 -> V_7 . V_8 . V_24 [ V_19 ] ;
if ( V_4 -> V_25 [ V_19 ] & V_21 )
return 0 ;
V_18 |= V_4 -> V_26 [ V_19 ] & V_21 ;
}
if ( V_4 -> V_27 && ! V_18 )
return 0 ;
return V_7 -> V_15 . V_8 ( V_7 -> V_7 . V_8 . V_24 , V_7 -> V_7 . V_8 . V_28 ,
NULL , 0 , & V_4 -> V_22 ) ;
}
static inline int F_9 ( struct V_3 * V_7 )
{
struct V_29 * V_30 = V_7 -> V_30 ;
struct V_17 * V_4 = V_7 -> V_22 ;
struct V_31 * V_8 = & V_7 -> V_7 . V_8 ;
int V_32 ;
if ( ! V_8 -> V_33 )
return 0 ;
if ( ! V_4 )
return 0 ;
if ( V_8 -> V_34 ) {
V_32 = ( ( V_8 -> V_24 [ 1 ] & 0x80 ) != 0 ) ;
if ( V_32 &&
V_30 -> V_35 ( V_7 , V_8 -> V_24 , V_8 -> V_28 ) )
return - 1 ;
}
do {
if ( F_8 ( V_7 , V_4 ) < 0 )
return - 1 ;
} while ( ( V_4 = V_4 -> V_36 ) && V_8 -> V_33 );
V_8 -> V_28 = 0 ;
return 0 ;
}
static void F_10 ( struct V_3 * V_7 )
{
struct V_31 * V_8 = & V_7 -> V_7 . V_8 ;
#ifdef F_11
if ( V_8 -> V_37 < V_8 -> V_38 ) {
int V_19 , V_39 = V_8 -> V_38 - V_8 -> V_37 ;
if ( V_8 -> V_24 [ 0 ] != 0xff || V_8 -> V_24 [ V_39 - 1 ] != 0xff ) {
F_12 ( L_1 ,
V_39 , V_8 -> V_38 ) ;
F_12 ( L_2 ) ;
for ( V_19 = 0 ; V_19 < V_39 ; V_19 ++ )
F_12 ( L_3 , V_8 -> V_24 [ V_19 ] ) ;
F_12 ( L_4 ) ;
}
}
#endif
V_8 -> V_38 = V_8 -> V_37 = V_8 -> V_28 = 0 ;
V_8 -> V_24 = V_8 -> V_40 ;
}
static int F_13 ( struct V_3 * V_7 ,
const T_2 * V_1 , T_2 V_6 )
{
struct V_29 * V_30 = V_7 -> V_30 ;
struct V_31 * V_8 = & V_7 -> V_7 . V_8 ;
T_1 V_41 , V_28 , V_39 ;
if ( V_8 -> V_38 >= V_42 )
return 0 ;
if ( V_8 -> V_38 + V_6 > V_42 ) {
#ifdef F_11
F_12 ( L_5 ,
V_8 -> V_38 + V_6 - V_42 ,
V_42 ) ;
#endif
V_6 = V_42 - V_8 -> V_38 ;
}
if ( V_6 <= 0 )
return 0 ;
V_30 -> V_43 ( V_7 , V_8 -> V_40 + V_8 -> V_38 , V_1 , V_6 ) ;
V_8 -> V_38 += V_6 ;
V_41 = V_8 -> V_38 ;
if ( V_41 > V_42 )
return - 1 ;
V_8 -> V_24 = V_8 -> V_40 + V_8 -> V_37 ;
for ( V_39 = 0 ; V_8 -> V_37 + 2 < V_41 ; V_39 ++ ) {
V_28 = F_1 ( V_8 -> V_24 ) ;
if ( V_28 <= 0 || V_28 > V_44
|| V_28 + V_8 -> V_37 > V_41 )
return 0 ;
V_8 -> V_28 = V_28 ;
V_8 -> V_9 = ~ 0 ;
if ( V_7 -> V_45 )
F_9 ( V_7 ) ;
#ifdef F_11
else
F_12 ( L_6 ) ;
#endif
V_8 -> V_37 += V_28 ;
V_8 -> V_24 += V_28 ;
}
return 0 ;
}
static int F_14 ( struct V_3 * V_7 ,
const T_2 * V_1 )
{
T_2 V_13 , V_12 ;
int V_46 , V_47 = 0 ;
T_2 V_48 ;
V_12 = F_3 ( V_1 ) ;
if ( V_12 == 0 )
return - 1 ;
V_13 = 188 - V_12 ;
V_48 = V_1 [ 3 ] & 0x0f ;
V_46 = ( ( V_7 -> V_48 + 1 ) & 0x0f ) == V_48 ;
V_7 -> V_48 = V_48 ;
if ( V_1 [ 3 ] & 0x20 ) {
if ( ( V_1 [ 4 ] > 0 ) && ( V_1 [ 5 ] & 0x80 ) )
V_47 = 1 ;
}
if ( ! V_46 || V_47 ) {
#ifdef F_11
F_12 ( L_7 ,
V_12 ) ;
#endif
V_7 -> V_45 = 0 ;
F_10 ( V_7 ) ;
}
if ( V_1 [ 1 ] & 0x40 ) {
if ( V_12 > 1 && V_1 [ V_13 ] < V_12 ) {
const T_2 * V_49 = & V_1 [ V_13 + 1 ] ;
T_2 V_50 = V_1 [ V_13 ] ;
const T_2 * V_51 = & V_49 [ V_50 ] ;
T_2 V_52 = V_12 - 1 - V_50 ;
F_13 ( V_7 , V_49 ,
V_50 ) ;
V_7 -> V_45 = 1 ;
F_10 ( V_7 ) ;
F_13 ( V_7 , V_51 ,
V_52 ) ;
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
case V_53 :
if ( ! V_7 -> V_7 . V_16 . V_33 )
break;
if ( V_7 -> V_54 & V_55 ) {
if ( V_7 -> V_54 & V_56 )
F_7 ( V_7 , V_1 ) ;
else
V_7 -> V_15 . V_16 ( V_1 , 188 , NULL , 0 , & V_7 -> V_7 . V_16 ) ;
}
if ( V_7 -> V_54 & V_57 )
if ( V_7 -> V_30 -> V_58 )
V_7 -> V_30 -> V_58 ( V_7 , V_1 , 188 ) ;
break;
case V_59 :
if ( ! V_7 -> V_7 . V_8 . V_33 )
break;
if ( F_14 ( V_7 , V_1 ) < 0 )
V_7 -> V_7 . V_8 . V_28 = V_7 -> V_7 . V_8 . V_37 = 0 ;
break;
default:
break;
}
}
static void F_16 ( struct V_29 * V_30 , const T_2 * V_1 )
{
struct V_3 * V_7 ;
T_1 V_60 = F_2 ( V_1 ) ;
int V_61 = 0 ;
if ( V_62 ) {
struct V_63 V_64 , V_65 ;
T_5 V_66 , V_67 ;
V_30 -> V_68 ++ ;
if ( ! ( V_30 -> V_68 % V_69 ) ) {
V_64 = F_17 () ;
if ( V_30 -> V_70 . V_71 != 0 &&
V_30 -> V_70 . V_72 != 0 ) {
V_65 = F_18 ( V_64 ,
V_30 -> V_70 ) ;
V_66 = ( T_5 ) V_30 -> V_68
* 188 * 8 ;
V_66 = 1000 * F_19 ( V_66 ,
1024 ) ;
V_67 =
( T_5 ) F_20 ( & V_65 ) ;
V_67 = F_19 ( V_67 ,
1000000 ) ;
F_12 ( V_73 L_9 ,
F_19 ( V_66 ,
V_67 ) ) ;
}
V_30 -> V_70 = V_64 ;
V_30 -> V_68 = 0 ;
}
}
if ( V_1 [ 1 ] & 0x80 ) {
F_21 ( L_10
L_11 ,
V_60 , V_1 [ 1 ] ) ;
if ( ! V_74 )
return;
} else
if ( V_30 -> V_75 && V_76 ) {
if ( V_60 < V_77 ) {
if ( V_1 [ 3 ] & 0x10 )
V_30 -> V_75 [ V_60 ] =
( V_30 -> V_75 [ V_60 ] + 1 ) & 0xf ;
if ( ( V_1 [ 3 ] & 0xf ) != V_30 -> V_75 [ V_60 ] ) {
F_21 ( L_12 ,
V_60 , V_30 -> V_75 [ V_60 ] ,
V_1 [ 3 ] & 0xf ) ;
V_30 -> V_75 [ V_60 ] = V_1 [ 3 ] & 0xf ;
}
}
}
F_22 (feed, &demux->feed_list, list_head) {
if ( ( V_7 -> V_60 != V_60 ) && ( V_7 -> V_60 != 0x2000 ) )
continue;
if ( ( F_23 ( V_7 ) ) && ( V_61 ++ ) )
continue;
if ( V_7 -> V_60 == V_60 )
F_15 ( V_7 , V_1 ) ;
else if ( V_7 -> V_60 == 0x2000 )
V_7 -> V_15 . V_16 ( V_1 , 188 , NULL , 0 , & V_7 -> V_7 . V_16 ) ;
}
}
void F_24 ( struct V_29 * V_30 , const T_2 * V_1 ,
T_4 V_12 )
{
unsigned long V_78 ;
F_25 ( & V_30 -> V_79 , V_78 ) ;
while ( V_12 -- ) {
if ( V_1 [ 0 ] == 0x47 )
F_16 ( V_30 , V_1 ) ;
V_1 += 188 ;
}
F_26 ( & V_30 -> V_79 , V_78 ) ;
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
static inline void F_28 ( struct V_29 * V_30 , const T_2 * V_1 ,
T_4 V_12 , const int V_81 )
{
int V_13 = 0 , V_19 , V_85 ;
const T_2 * V_86 ;
unsigned long V_78 ;
F_25 ( & V_30 -> V_79 , V_78 ) ;
if ( V_30 -> V_87 ) {
V_19 = V_30 -> V_87 ;
V_85 = V_81 - V_19 ;
if ( V_12 < V_85 ) {
memcpy ( & V_30 -> V_88 [ V_19 ] , V_1 , V_12 ) ;
V_30 -> V_87 += V_12 ;
goto V_89;
}
memcpy ( & V_30 -> V_88 [ V_19 ] , V_1 , V_85 ) ;
if ( V_30 -> V_88 [ 0 ] == 0x47 )
F_16 ( V_30 , V_30 -> V_88 ) ;
V_30 -> V_87 = 0 ;
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
memcpy ( V_30 -> V_88 , V_86 , 188 ) ;
V_30 -> V_88 [ 0 ] = 0x47 ;
V_86 = V_30 -> V_88 ;
}
F_16 ( V_30 , V_86 ) ;
V_13 += V_81 ;
}
V_19 = V_12 - V_13 ;
if ( V_19 ) {
memcpy ( V_30 -> V_88 , & V_1 [ V_13 ] , V_19 ) ;
V_30 -> V_87 = V_19 ;
if ( V_81 == 204 && V_30 -> V_88 [ 0 ] == 0xB8 )
V_30 -> V_88 [ 0 ] = 0x47 ;
}
V_89:
F_26 ( & V_30 -> V_79 , V_78 ) ;
}
void F_29 ( struct V_29 * V_30 , const T_2 * V_1 , T_4 V_12 )
{
F_28 ( V_30 , V_1 , V_12 , 188 ) ;
}
void F_30 ( struct V_29 * V_30 , const T_2 * V_1 , T_4 V_12 )
{
F_28 ( V_30 , V_1 , V_12 , 204 ) ;
}
void F_31 ( struct V_29 * V_30 , const T_2 * V_1 , T_4 V_12 )
{
unsigned long V_78 ;
F_25 ( & V_30 -> V_79 , V_78 ) ;
V_30 -> V_7 -> V_15 . V_16 ( V_1 , V_12 , NULL , 0 , & V_30 -> V_7 -> V_7 . V_16 ) ;
F_26 ( & V_30 -> V_79 , V_78 ) ;
}
static struct V_17 * F_32 ( struct V_29 * V_30 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_30 -> V_90 ; V_19 ++ )
if ( V_30 -> V_22 [ V_19 ] . V_91 == V_92 )
break;
if ( V_19 == V_30 -> V_90 )
return NULL ;
V_30 -> V_22 [ V_19 ] . V_91 = V_93 ;
return & V_30 -> V_22 [ V_19 ] ;
}
static struct V_3 * F_33 ( struct V_29 * V_30 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_30 -> V_94 ; V_19 ++ )
if ( V_30 -> V_7 [ V_19 ] . V_91 == V_92 )
break;
if ( V_19 == V_30 -> V_94 )
return NULL ;
V_30 -> V_7 [ V_19 ] . V_91 = V_93 ;
return & V_30 -> V_7 [ V_19 ] ;
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
F_36 ( & V_7 -> V_30 -> V_79 ) ;
if ( F_34 ( V_7 ) ) {
F_12 ( V_96 L_13 ,
V_97 , V_7 -> type , V_7 -> V_91 , V_7 -> V_60 ) ;
goto V_98;
}
F_37 ( & V_7 -> V_99 , & V_7 -> V_30 -> V_100 ) ;
V_98:
F_38 ( & V_7 -> V_30 -> V_79 ) ;
}
static void F_39 ( struct V_3 * V_7 )
{
F_36 ( & V_7 -> V_30 -> V_79 ) ;
if ( ! ( F_34 ( V_7 ) ) ) {
F_12 ( V_96 L_14 ,
V_97 , V_7 -> type , V_7 -> V_91 , V_7 -> V_60 ) ;
goto V_98;
}
F_40 ( & V_7 -> V_99 ) ;
V_98:
F_38 ( & V_7 -> V_30 -> V_79 ) ;
}
static int F_41 ( struct V_101 * V_102 , T_1 V_60 , int V_54 ,
enum V_103 V_104 ,
T_4 V_105 , struct V_63 V_106 )
{
struct V_3 * V_7 = (struct V_3 * ) V_102 ;
struct V_29 * V_30 = V_7 -> V_30 ;
if ( V_60 > V_107 )
return - V_108 ;
if ( F_42 ( & V_30 -> V_109 ) )
return - V_110 ;
if ( V_54 & V_57 ) {
if ( V_104 >= V_111 ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_108 ;
}
if ( V_30 -> V_112 [ V_104 ] &&
V_30 -> V_112 [ V_104 ] != V_7 ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_108 ;
}
V_30 -> V_112 [ V_104 ] = V_7 ;
V_30 -> V_113 [ V_104 ] = V_60 ;
}
F_35 ( V_7 ) ;
V_7 -> V_60 = V_60 ;
V_7 -> V_114 = V_105 ;
V_7 -> V_106 = V_106 ;
V_7 -> V_54 = V_54 ;
V_7 -> V_104 = V_104 ;
if ( V_7 -> V_114 ) {
#ifdef F_44
V_7 -> V_115 = NULL ;
#else
V_7 -> V_115 = F_45 ( V_7 -> V_114 ) ;
if ( ! V_7 -> V_115 ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_116 ;
}
#endif
}
V_7 -> V_91 = V_117 ;
F_43 ( & V_30 -> V_109 ) ;
return 0 ;
}
static int F_46 ( struct V_101 * V_102 )
{
struct V_3 * V_7 = (struct V_3 * ) V_102 ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_118 ;
if ( F_42 ( & V_30 -> V_109 ) )
return - V_110 ;
if ( V_7 -> V_91 != V_117 || V_7 -> type != V_53 ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_108 ;
}
if ( ! V_30 -> V_119 ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_120 ;
}
if ( ( V_118 = V_30 -> V_119 ( V_7 ) ) < 0 ) {
F_43 ( & V_30 -> V_109 ) ;
return V_118 ;
}
F_36 ( & V_30 -> V_79 ) ;
V_102 -> V_33 = 1 ;
V_7 -> V_91 = V_121 ;
F_38 ( & V_30 -> V_79 ) ;
F_43 ( & V_30 -> V_109 ) ;
return 0 ;
}
static int F_47 ( struct V_101 * V_102 )
{
struct V_3 * V_7 = (struct V_3 * ) V_102 ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_118 ;
F_48 ( & V_30 -> V_109 ) ;
if ( V_7 -> V_91 < V_121 ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_108 ;
}
if ( ! V_30 -> V_122 ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_120 ;
}
V_118 = V_30 -> V_122 ( V_7 ) ;
F_36 ( & V_30 -> V_79 ) ;
V_102 -> V_33 = 0 ;
V_7 -> V_91 = V_93 ;
F_38 ( & V_30 -> V_79 ) ;
F_43 ( & V_30 -> V_109 ) ;
return V_118 ;
}
static int F_49 ( struct V_123 * V_124 ,
struct V_101 * * V_102 ,
T_6 V_125 )
{
struct V_29 * V_30 = (struct V_29 * ) V_124 ;
struct V_3 * V_7 ;
if ( F_42 ( & V_30 -> V_109 ) )
return - V_110 ;
if ( ! ( V_7 = F_33 ( V_30 ) ) ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_126 ;
}
V_7 -> type = V_53 ;
V_7 -> V_15 . V_16 = V_125 ;
V_7 -> V_30 = V_30 ;
V_7 -> V_60 = 0xffff ;
V_7 -> V_14 = 0xfffa ;
V_7 -> V_115 = NULL ;
( * V_102 ) = & V_7 -> V_7 . V_16 ;
( * V_102 ) -> V_127 = V_124 ;
( * V_102 ) -> V_128 = NULL ;
( * V_102 ) -> V_33 = 0 ;
( * V_102 ) -> V_129 = F_46 ;
( * V_102 ) -> V_130 = F_47 ;
( * V_102 ) -> V_131 = F_41 ;
if ( ! ( V_7 -> V_22 = F_32 ( V_30 ) ) ) {
V_7 -> V_91 = V_92 ;
F_43 ( & V_30 -> V_109 ) ;
return - V_126 ;
}
V_7 -> V_22 -> type = V_53 ;
V_7 -> V_22 -> V_7 = V_7 ;
V_7 -> V_22 -> V_91 = V_117 ;
F_43 ( & V_30 -> V_109 ) ;
return 0 ;
}
static int F_50 ( struct V_123 * V_124 ,
struct V_101 * V_102 )
{
struct V_29 * V_30 = (struct V_29 * ) V_124 ;
struct V_3 * V_7 = (struct V_3 * ) V_102 ;
F_48 ( & V_30 -> V_109 ) ;
if ( V_7 -> V_91 == V_92 ) {
F_43 ( & V_30 -> V_109 ) ;
return - V_108 ;
}
#ifndef F_44
F_51 ( V_7 -> V_115 ) ;
V_7 -> V_115 = NULL ;
#endif
V_7 -> V_91 = V_92 ;
V_7 -> V_22 -> V_91 = V_92 ;
F_39 ( V_7 ) ;
V_7 -> V_60 = 0xffff ;
if ( V_7 -> V_54 & V_57 && V_7 -> V_104 < V_111 )
V_30 -> V_112 [ V_7 -> V_104 ] = NULL ;
F_43 ( & V_30 -> V_109 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_7 ,
struct V_132 * * V_22 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_29 * V_134 = V_133 -> V_30 ;
struct V_17 * V_135 ;
if ( F_42 ( & V_134 -> V_109 ) )
return - V_110 ;
V_135 = F_32 ( V_134 ) ;
if ( ! V_135 ) {
F_43 ( & V_134 -> V_109 ) ;
return - V_126 ;
}
F_36 ( & V_134 -> V_79 ) ;
* V_22 = & V_135 -> V_22 ;
( * V_22 ) -> V_127 = V_7 ;
( * V_22 ) -> V_128 = NULL ;
V_135 -> V_7 = V_133 ;
V_135 -> type = V_59 ;
V_135 -> V_91 = V_117 ;
V_135 -> V_36 = V_133 -> V_22 ;
V_133 -> V_22 = V_135 ;
F_38 ( & V_134 -> V_79 ) ;
F_43 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_7 ,
T_1 V_60 , T_4 V_105 ,
int V_34 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_29 * V_136 = V_133 -> V_30 ;
if ( V_60 > 0x1fff )
return - V_108 ;
if ( F_42 ( & V_136 -> V_109 ) )
return - V_110 ;
F_35 ( V_133 ) ;
V_133 -> V_60 = V_60 ;
V_133 -> V_114 = V_105 ;
V_133 -> V_7 . V_8 . V_34 = V_34 ;
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
int V_19 ;
struct V_17 * V_4 ;
struct V_132 * V_137 ;
T_2 V_138 , V_139 , V_27 ;
if ( ! ( V_4 = V_133 -> V_22 ) )
return;
do {
V_137 = & V_4 -> V_22 ;
V_27 = 0 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_139 = V_137 -> V_140 [ V_19 ] ;
V_138 = V_137 -> V_141 [ V_19 ] ;
V_4 -> V_25 [ V_19 ] = V_138 & V_139 ;
V_27 |= V_4 -> V_26 [ V_19 ] = V_138 & ~ V_139 ;
}
V_4 -> V_27 = V_27 ? 1 : 0 ;
} while ( ( V_4 = V_4 -> V_36 ) );
}
static int F_55 ( struct V_31 * V_7 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_29 * V_136 = V_133 -> V_30 ;
int V_118 ;
if ( F_42 ( & V_136 -> V_109 ) )
return - V_110 ;
if ( V_7 -> V_33 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_126 ;
}
if ( ! V_133 -> V_22 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_108 ;
}
V_133 -> V_7 . V_8 . V_38 = 0 ;
V_133 -> V_7 . V_8 . V_24 = V_133 -> V_7 . V_8 . V_40 ;
V_133 -> V_7 . V_8 . V_37 = 0 ;
V_133 -> V_7 . V_8 . V_28 = 0 ;
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
V_7 -> V_33 = 1 ;
V_133 -> V_91 = V_121 ;
F_38 ( & V_136 -> V_79 ) ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static int F_56 ( struct V_31 * V_7 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_29 * V_136 = V_133 -> V_30 ;
int V_118 ;
F_48 ( & V_136 -> V_109 ) ;
if ( ! V_136 -> V_122 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_120 ;
}
V_118 = V_136 -> V_122 ( V_133 ) ;
F_36 ( & V_136 -> V_79 ) ;
V_133 -> V_91 = V_117 ;
V_7 -> V_33 = 0 ;
F_38 ( & V_136 -> V_79 ) ;
F_43 ( & V_136 -> V_109 ) ;
return V_118 ;
}
static int F_57 ( struct V_31 * V_7 ,
struct V_132 * V_22 )
{
struct V_17 * V_135 = (struct V_17 * ) V_22 , * V_4 ;
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_29 * V_136 = V_133 -> V_30 ;
F_48 ( & V_136 -> V_109 ) ;
if ( V_135 -> V_7 != V_133 ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_108 ;
}
if ( V_7 -> V_33 ) {
F_43 ( & V_136 -> V_109 ) ;
V_7 -> V_130 ( V_7 ) ;
F_48 ( & V_136 -> V_109 ) ;
}
F_36 ( & V_136 -> V_79 ) ;
V_4 = V_133 -> V_22 ;
if ( V_4 == V_135 ) {
V_133 -> V_22 = V_135 -> V_36 ;
} else {
while ( V_4 -> V_36 != V_135 )
V_4 = V_4 -> V_36 ;
V_4 -> V_36 = V_4 -> V_36 -> V_36 ;
}
V_135 -> V_91 = V_92 ;
F_38 ( & V_136 -> V_79 ) ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static int F_58 ( struct V_123 * V_30 ,
struct V_31 * * V_7 ,
T_7 V_125 )
{
struct V_29 * V_136 = (struct V_29 * ) V_30 ;
struct V_3 * V_133 ;
if ( F_42 ( & V_136 -> V_109 ) )
return - V_110 ;
if ( ! ( V_133 = F_33 ( V_136 ) ) ) {
F_43 ( & V_136 -> V_109 ) ;
return - V_126 ;
}
V_133 -> type = V_59 ;
V_133 -> V_15 . V_8 = V_125 ;
V_133 -> V_30 = V_136 ;
V_133 -> V_60 = 0xffff ;
V_133 -> V_7 . V_8 . V_24 = V_133 -> V_7 . V_8 . V_40 ;
V_133 -> V_7 . V_8 . V_37 = V_133 -> V_7 . V_8 . V_28 = 0 ;
V_133 -> V_7 . V_8 . V_38 = 0 ;
V_133 -> V_22 = NULL ;
V_133 -> V_115 = NULL ;
( * V_7 ) = & V_133 -> V_7 . V_8 ;
( * V_7 ) -> V_33 = 0 ;
( * V_7 ) -> V_127 = V_30 ;
( * V_7 ) -> V_128 = NULL ;
( * V_7 ) -> V_131 = F_53 ;
( * V_7 ) -> V_142 = F_52 ;
( * V_7 ) -> V_129 = F_55 ;
( * V_7 ) -> V_130 = F_56 ;
( * V_7 ) -> V_143 = F_57 ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static int F_59 ( struct V_123 * V_30 ,
struct V_31 * V_7 )
{
struct V_3 * V_133 = (struct V_3 * ) V_7 ;
struct V_29 * V_136 = (struct V_29 * ) V_30 ;
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
V_133 -> V_60 = 0xffff ;
F_43 ( & V_136 -> V_109 ) ;
return 0 ;
}
static int F_60 ( struct V_123 * V_30 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
if ( V_134 -> V_144 >= V_145 )
return - V_146 ;
V_134 -> V_144 ++ ;
return 0 ;
}
static int F_61 ( struct V_123 * V_30 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
if ( V_134 -> V_144 == 0 )
return - V_120 ;
V_134 -> V_144 -- ;
return 0 ;
}
static int F_62 ( struct V_123 * V_30 , const char T_8 * V_1 , T_4 V_12 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
void * V_13 ;
if ( ( ! V_30 -> V_147 ) || ( V_30 -> V_147 -> V_148 != V_149 ) )
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
static int F_68 ( struct V_123 * V_30 ,
struct V_152 * V_147 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
struct V_99 * V_153 = & V_134 -> V_154 ;
F_37 ( & ( V_147 -> V_155 ) , V_153 ) ;
return 0 ;
}
static int F_69 ( struct V_123 * V_30 ,
struct V_152 * V_147 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
struct V_99 * V_80 , * V_39 , * V_153 = & V_134 -> V_154 ;
F_70 (pos, n, head) {
if ( F_71 ( V_80 ) == V_147 ) {
F_40 ( V_80 ) ;
return 0 ;
}
}
return - V_120 ;
}
static struct V_99 * F_72 ( struct V_123 * V_30 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
if ( F_73 ( & V_134 -> V_154 ) )
return NULL ;
return & V_134 -> V_154 ;
}
static int F_74 ( struct V_123 * V_30 ,
struct V_152 * V_147 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
if ( V_30 -> V_147 )
return - V_108 ;
F_48 ( & V_134 -> V_109 ) ;
V_30 -> V_147 = V_147 ;
F_43 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_75 ( struct V_123 * V_30 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
F_48 ( & V_134 -> V_109 ) ;
V_30 -> V_147 = NULL ;
F_43 ( & V_134 -> V_109 ) ;
return 0 ;
}
static int F_76 ( struct V_123 * V_30 , T_1 * V_113 )
{
struct V_29 * V_134 = (struct V_29 * ) V_30 ;
memcpy ( V_113 , V_134 -> V_113 , 5 * sizeof( T_1 ) ) ;
return 0 ;
}
int F_77 ( struct V_29 * V_134 )
{
int V_19 ;
struct V_123 * V_124 = & V_134 -> V_124 ;
V_134 -> V_75 = NULL ;
V_134 -> V_144 = 0 ;
V_134 -> V_22 = F_45 ( V_134 -> V_90 * sizeof( struct V_17 ) ) ;
if ( ! V_134 -> V_22 )
return - V_116 ;
V_134 -> V_7 = F_45 ( V_134 -> V_94 * sizeof( struct V_3 ) ) ;
if ( ! V_134 -> V_7 ) {
F_51 ( V_134 -> V_22 ) ;
V_134 -> V_22 = NULL ;
return - V_116 ;
}
for ( V_19 = 0 ; V_19 < V_134 -> V_90 ; V_19 ++ ) {
V_134 -> V_22 [ V_19 ] . V_91 = V_92 ;
V_134 -> V_22 [ V_19 ] . V_156 = V_19 ;
}
for ( V_19 = 0 ; V_19 < V_134 -> V_94 ; V_19 ++ ) {
V_134 -> V_7 [ V_19 ] . V_91 = V_92 ;
V_134 -> V_7 [ V_19 ] . V_156 = V_19 ;
}
V_134 -> V_75 = F_45 ( V_77 + 1 ) ;
if ( ! V_134 -> V_75 )
F_12 ( V_157 L_15 ) ;
F_78 ( & V_134 -> V_154 ) ;
for ( V_19 = 0 ; V_19 < V_111 ; V_19 ++ ) {
V_134 -> V_112 [ V_19 ] = NULL ;
V_134 -> V_113 [ V_19 ] = 0xffff ;
}
F_78 ( & V_134 -> V_100 ) ;
V_134 -> V_158 = 0 ;
V_134 -> V_159 = 0 ;
V_134 -> V_87 = 0 ;
if ( ! V_134 -> V_35 )
V_134 -> V_35 = F_4 ;
if ( ! V_134 -> V_43 )
V_134 -> V_43 = F_6 ;
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
void F_81 ( struct V_29 * V_134 )
{
F_51 ( V_134 -> V_75 ) ;
F_51 ( V_134 -> V_22 ) ;
F_51 ( V_134 -> V_7 ) ;
}
