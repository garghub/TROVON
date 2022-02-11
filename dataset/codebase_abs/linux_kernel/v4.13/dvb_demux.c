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
#ifdef F_8
int V_14 ;
T_2 V_15 ;
#endif
if ( V_12 == 0 )
return - 1 ;
V_13 = 188 - V_12 ;
#ifdef F_8
V_15 = V_1 [ 3 ] & 0x0f ;
V_14 = ( ( V_7 -> V_15 + 1 ) & 0x0f ) == V_15 ;
V_7 -> V_15 = V_15 ;
if ( ! V_14 )
F_9 ( L_1 ) ;
#endif
if ( V_1 [ 1 ] & 0x40 )
V_7 -> V_16 = 0xfffa ;
V_7 -> V_16 += V_12 ;
return V_7 -> V_17 . V_18 ( & V_1 [ V_13 ] , V_12 , NULL , 0 , & V_7 -> V_7 . V_18 ) ;
}
static int F_10 ( struct V_3 * V_7 ,
struct V_19 * V_4 )
{
T_2 V_20 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
T_2 V_23 = V_4 -> V_24 . V_25 [ V_21 ] ^ V_7 -> V_7 . V_8 . V_26 [ V_21 ] ;
if ( V_4 -> V_27 [ V_21 ] & V_23 )
return 0 ;
V_20 |= V_4 -> V_28 [ V_21 ] & V_23 ;
}
if ( V_4 -> V_29 && ! V_20 )
return 0 ;
return V_7 -> V_17 . V_8 ( V_7 -> V_7 . V_8 . V_26 , V_7 -> V_7 . V_8 . V_30 ,
NULL , 0 , & V_4 -> V_24 ) ;
}
static inline int F_11 ( struct V_3 * V_7 )
{
struct V_31 * V_32 = V_7 -> V_32 ;
struct V_19 * V_4 = V_7 -> V_24 ;
struct V_33 * V_8 = & V_7 -> V_7 . V_8 ;
int V_34 ;
if ( ! V_8 -> V_35 )
return 0 ;
if ( ! V_4 )
return 0 ;
if ( V_8 -> V_36 ) {
V_34 = ( ( V_8 -> V_26 [ 1 ] & 0x80 ) != 0 ) ;
if ( V_34 &&
V_32 -> V_37 ( V_7 , V_8 -> V_26 , V_8 -> V_30 ) )
return - 1 ;
}
do {
if ( F_10 ( V_7 , V_4 ) < 0 )
return - 1 ;
} while ( ( V_4 = V_4 -> V_38 ) && V_8 -> V_35 );
V_8 -> V_30 = 0 ;
return 0 ;
}
static void F_12 ( struct V_3 * V_7 )
{
struct V_33 * V_8 = & V_7 -> V_7 . V_8 ;
#ifdef F_8
if ( V_8 -> V_39 < V_8 -> V_40 ) {
int V_21 , V_41 = V_8 -> V_40 - V_8 -> V_39 ;
if ( V_8 -> V_26 [ 0 ] != 0xff || V_8 -> V_26 [ V_41 - 1 ] != 0xff ) {
F_9 ( L_2 ,
V_41 , V_8 -> V_40 ) ;
F_9 ( L_3 ) ;
for ( V_21 = 0 ; V_21 < V_41 ; V_21 ++ )
F_13 ( L_4 , V_8 -> V_26 [ V_21 ] ) ;
F_13 ( L_5 ) ;
}
}
#endif
V_8 -> V_40 = V_8 -> V_39 = V_8 -> V_30 = 0 ;
V_8 -> V_26 = V_8 -> V_42 ;
}
static int F_14 ( struct V_3 * V_7 ,
const T_2 * V_1 , T_2 V_6 )
{
struct V_31 * V_32 = V_7 -> V_32 ;
struct V_33 * V_8 = & V_7 -> V_7 . V_8 ;
T_1 V_43 , V_30 , V_41 ;
if ( V_8 -> V_40 >= V_44 )
return 0 ;
if ( V_8 -> V_40 + V_6 > V_44 ) {
#ifdef F_8
F_9 ( L_6 ,
V_8 -> V_40 + V_6 - V_44 ,
V_44 ) ;
#endif
V_6 = V_44 - V_8 -> V_40 ;
}
if ( V_6 <= 0 )
return 0 ;
V_32 -> V_45 ( V_7 , V_8 -> V_42 + V_8 -> V_40 , V_1 , V_6 ) ;
V_8 -> V_40 += V_6 ;
V_43 = V_8 -> V_40 ;
if ( V_43 > V_44 )
return - 1 ;
V_8 -> V_26 = V_8 -> V_42 + V_8 -> V_39 ;
for ( V_41 = 0 ; V_8 -> V_39 + 2 < V_43 ; V_41 ++ ) {
V_30 = F_1 ( V_8 -> V_26 ) ;
if ( V_30 <= 0 || V_30 > V_46
|| V_30 + V_8 -> V_39 > V_43 )
return 0 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_9 = ~ 0 ;
if ( V_7 -> V_47 )
F_11 ( V_7 ) ;
#ifdef F_8
else
F_9 ( L_7 ) ;
#endif
V_8 -> V_39 += V_30 ;
V_8 -> V_26 += V_30 ;
}
return 0 ;
}
static int F_15 ( struct V_3 * V_7 ,
const T_2 * V_1 )
{
T_2 V_13 , V_12 ;
int V_14 , V_48 = 0 ;
T_2 V_15 ;
V_12 = F_3 ( V_1 ) ;
if ( V_12 == 0 )
return - 1 ;
V_13 = 188 - V_12 ;
V_15 = V_1 [ 3 ] & 0x0f ;
V_14 = ( ( V_7 -> V_15 + 1 ) & 0x0f ) == V_15 ;
V_7 -> V_15 = V_15 ;
if ( V_1 [ 3 ] & 0x20 ) {
if ( ( V_1 [ 4 ] > 0 ) && ( V_1 [ 5 ] & 0x80 ) )
V_48 = 1 ;
}
if ( ! V_14 || V_48 ) {
#ifdef F_8
F_9 ( L_8 ,
V_12 ) ;
#endif
V_7 -> V_47 = 0 ;
F_12 ( V_7 ) ;
}
if ( V_1 [ 1 ] & 0x40 ) {
if ( V_12 > 1 && V_1 [ V_13 ] < V_12 ) {
const T_2 * V_49 = & V_1 [ V_13 + 1 ] ;
T_2 V_50 = V_1 [ V_13 ] ;
const T_2 * V_51 = & V_49 [ V_50 ] ;
T_2 V_52 = V_12 - 1 - V_50 ;
F_14 ( V_7 , V_49 ,
V_50 ) ;
V_7 -> V_47 = 1 ;
F_12 ( V_7 ) ;
F_14 ( V_7 , V_51 ,
V_52 ) ;
}
#ifdef F_8
else if ( V_12 > 0 )
F_9 ( L_9 ,
V_12 ) ;
#endif
} else {
F_14 ( V_7 , & V_1 [ V_13 ] , V_12 ) ;
}
return 0 ;
}
static inline void F_16 ( struct V_3 * V_7 ,
const T_2 * V_1 )
{
switch ( V_7 -> type ) {
case V_53 :
if ( ! V_7 -> V_7 . V_18 . V_35 )
break;
if ( V_7 -> V_54 & V_55 ) {
if ( V_7 -> V_54 & V_56 )
F_7 ( V_7 , V_1 ) ;
else
V_7 -> V_17 . V_18 ( V_1 , 188 , NULL , 0 , & V_7 -> V_7 . V_18 ) ;
}
if ( V_7 -> V_54 & V_57 )
if ( V_7 -> V_32 -> V_58 )
V_7 -> V_32 -> V_58 ( V_7 , V_1 , 188 ) ;
break;
case V_59 :
if ( ! V_7 -> V_7 . V_8 . V_35 )
break;
if ( F_15 ( V_7 , V_1 ) < 0 )
V_7 -> V_7 . V_8 . V_30 = V_7 -> V_7 . V_8 . V_39 = 0 ;
break;
default:
break;
}
}
static void F_17 ( struct V_31 * V_32 , const T_2 * V_1 )
{
struct V_3 * V_7 ;
T_1 V_60 = F_2 ( V_1 ) ;
int V_61 = 0 ;
if ( V_62 ) {
T_5 V_63 ;
T_6 V_64 , V_65 ;
V_32 -> V_66 ++ ;
if ( ! ( V_32 -> V_66 % V_67 ) ) {
V_63 = F_18 () ;
if ( F_19 ( V_32 -> V_68 ) != 0 ) {
V_64 = ( T_6 ) V_32 -> V_66
* 188 * 8 ;
V_64 = 1000 * F_20 ( V_64 ,
1024 ) ;
V_65 = F_21 ( V_63 ,
V_32 -> V_68 ) ;
F_9 ( L_10 ,
F_20 ( V_64 ,
V_65 ) ) ;
}
V_32 -> V_68 = V_63 ;
V_32 -> V_66 = 0 ;
}
}
if ( V_1 [ 1 ] & 0x80 ) {
F_22 ( L_11 ,
V_60 , V_1 [ 1 ] ) ;
if ( ! V_69 )
return;
} else
if ( V_32 -> V_70 && V_71 ) {
if ( V_60 < V_72 ) {
if ( V_1 [ 3 ] & 0x10 )
V_32 -> V_70 [ V_60 ] =
( V_32 -> V_70 [ V_60 ] + 1 ) & 0xf ;
if ( ( V_1 [ 3 ] & 0xf ) != V_32 -> V_70 [ V_60 ] ) {
F_22 ( L_12 ,
V_60 , V_32 -> V_70 [ V_60 ] ,
V_1 [ 3 ] & 0xf ) ;
V_32 -> V_70 [ V_60 ] = V_1 [ 3 ] & 0xf ;
}
}
}
F_23 (feed, &demux->feed_list, list_head) {
if ( ( V_7 -> V_60 != V_60 ) && ( V_7 -> V_60 != 0x2000 ) )
continue;
if ( ( F_24 ( V_7 ) ) && ( V_61 ++ ) )
continue;
if ( V_7 -> V_60 == V_60 )
F_16 ( V_7 , V_1 ) ;
else if ( V_7 -> V_60 == 0x2000 )
V_7 -> V_17 . V_18 ( V_1 , 188 , NULL , 0 , & V_7 -> V_7 . V_18 ) ;
}
}
void F_25 ( struct V_31 * V_32 , const T_2 * V_1 ,
T_4 V_12 )
{
unsigned long V_73 ;
F_26 ( & V_32 -> V_74 , V_73 ) ;
while ( V_12 -- ) {
if ( V_1 [ 0 ] == 0x47 )
F_17 ( V_32 , V_1 ) ;
V_1 += 188 ;
}
F_27 ( & V_32 -> V_74 , V_73 ) ;
}
static inline int F_28 ( const T_2 * V_1 , int V_75 , T_4 V_12 ,
const int V_76 )
{
int V_77 = V_75 , V_78 ;
while ( V_75 < V_12 ) {
if ( V_1 [ V_75 ] == 0x47 ||
( V_76 == 204 && V_1 [ V_75 ] == 0xB8 ) )
break;
V_75 ++ ;
}
V_78 = V_75 - V_77 ;
if ( V_78 ) {
int V_79 = V_75 - V_76 ;
if ( V_79 >= 0 && ( V_1 [ V_79 ] == 0x47 ||
( V_76 == 204 && V_1 [ V_79 ] == 0xB8 ) ) )
return V_79 ;
}
return V_75 ;
}
static inline void F_29 ( struct V_31 * V_32 , const T_2 * V_1 ,
T_4 V_12 , const int V_76 )
{
int V_13 = 0 , V_21 , V_80 ;
const T_2 * V_81 ;
unsigned long V_73 ;
F_26 ( & V_32 -> V_74 , V_73 ) ;
if ( V_32 -> V_82 ) {
V_21 = V_32 -> V_82 ;
V_80 = V_76 - V_21 ;
if ( V_12 < V_80 ) {
memcpy ( & V_32 -> V_83 [ V_21 ] , V_1 , V_12 ) ;
V_32 -> V_82 += V_12 ;
goto V_84;
}
memcpy ( & V_32 -> V_83 [ V_21 ] , V_1 , V_80 ) ;
if ( V_32 -> V_83 [ 0 ] == 0x47 )
F_17 ( V_32 , V_32 -> V_83 ) ;
V_32 -> V_82 = 0 ;
V_13 += V_80 ;
}
while ( 1 ) {
V_13 = F_28 ( V_1 , V_13 , V_12 , V_76 ) ;
if ( V_13 >= V_12 )
break;
if ( V_12 - V_13 < V_76 )
break;
V_81 = & V_1 [ V_13 ] ;
if ( V_76 == 204 && ( * V_81 == 0xB8 ) ) {
memcpy ( V_32 -> V_83 , V_81 , 188 ) ;
V_32 -> V_83 [ 0 ] = 0x47 ;
V_81 = V_32 -> V_83 ;
}
F_17 ( V_32 , V_81 ) ;
V_13 += V_76 ;
}
V_21 = V_12 - V_13 ;
if ( V_21 ) {
memcpy ( V_32 -> V_83 , & V_1 [ V_13 ] , V_21 ) ;
V_32 -> V_82 = V_21 ;
if ( V_76 == 204 && V_32 -> V_83 [ 0 ] == 0xB8 )
V_32 -> V_83 [ 0 ] = 0x47 ;
}
V_84:
F_27 ( & V_32 -> V_74 , V_73 ) ;
}
void F_30 ( struct V_31 * V_32 , const T_2 * V_1 , T_4 V_12 )
{
F_29 ( V_32 , V_1 , V_12 , 188 ) ;
}
void F_31 ( struct V_31 * V_32 , const T_2 * V_1 , T_4 V_12 )
{
F_29 ( V_32 , V_1 , V_12 , 204 ) ;
}
void F_32 ( struct V_31 * V_32 , const T_2 * V_1 , T_4 V_12 )
{
unsigned long V_73 ;
F_26 ( & V_32 -> V_74 , V_73 ) ;
V_32 -> V_7 -> V_17 . V_18 ( V_1 , V_12 , NULL , 0 , & V_32 -> V_7 -> V_7 . V_18 ) ;
F_27 ( & V_32 -> V_74 , V_73 ) ;
}
static struct V_19 * F_33 ( struct V_31 * V_32 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_32 -> V_85 ; V_21 ++ )
if ( V_32 -> V_24 [ V_21 ] . V_86 == V_87 )
break;
if ( V_21 == V_32 -> V_85 )
return NULL ;
V_32 -> V_24 [ V_21 ] . V_86 = V_88 ;
return & V_32 -> V_24 [ V_21 ] ;
}
static struct V_3 * F_34 ( struct V_31 * V_32 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_32 -> V_89 ; V_21 ++ )
if ( V_32 -> V_7 [ V_21 ] . V_86 == V_87 )
break;
if ( V_21 == V_32 -> V_89 )
return NULL ;
V_32 -> V_7 [ V_21 ] . V_86 = V_88 ;
return & V_32 -> V_7 [ V_21 ] ;
}
static int F_35 ( struct V_3 * V_7 )
{
struct V_3 * V_90 ;
F_23 (entry, &feed->demux->feed_list, list_head)
if ( V_90 == V_7 )
return 1 ;
return 0 ;
}
static void F_36 ( struct V_3 * V_7 )
{
F_37 ( & V_7 -> V_32 -> V_74 ) ;
if ( F_35 ( V_7 ) ) {
F_38 ( L_13 ,
V_91 , V_7 -> type , V_7 -> V_86 , V_7 -> V_60 ) ;
goto V_92;
}
F_39 ( & V_7 -> V_93 , & V_7 -> V_32 -> V_94 ) ;
V_92:
F_40 ( & V_7 -> V_32 -> V_74 ) ;
}
static void F_41 ( struct V_3 * V_7 )
{
F_37 ( & V_7 -> V_32 -> V_74 ) ;
if ( ! ( F_35 ( V_7 ) ) ) {
F_38 ( L_14 ,
V_91 , V_7 -> type , V_7 -> V_86 , V_7 -> V_60 ) ;
goto V_92;
}
F_42 ( & V_7 -> V_93 ) ;
V_92:
F_40 ( & V_7 -> V_32 -> V_74 ) ;
}
static int F_43 ( struct V_95 * V_96 , T_1 V_60 , int V_54 ,
enum V_97 V_98 , T_5 V_99 )
{
struct V_3 * V_7 = (struct V_3 * ) V_96 ;
struct V_31 * V_32 = V_7 -> V_32 ;
if ( V_60 > V_100 )
return - V_101 ;
if ( F_44 ( & V_32 -> V_102 ) )
return - V_103 ;
if ( V_54 & V_57 ) {
if ( V_98 >= V_104 ) {
F_45 ( & V_32 -> V_102 ) ;
return - V_101 ;
}
if ( V_32 -> V_105 [ V_98 ] &&
V_32 -> V_105 [ V_98 ] != V_7 ) {
F_45 ( & V_32 -> V_102 ) ;
return - V_101 ;
}
V_32 -> V_105 [ V_98 ] = V_7 ;
V_32 -> V_106 [ V_98 ] = V_60 ;
}
F_36 ( V_7 ) ;
V_7 -> V_60 = V_60 ;
V_7 -> V_99 = V_99 ;
V_7 -> V_54 = V_54 ;
V_7 -> V_98 = V_98 ;
V_7 -> V_86 = V_107 ;
F_45 ( & V_32 -> V_102 ) ;
return 0 ;
}
static int F_46 ( struct V_95 * V_96 )
{
struct V_3 * V_7 = (struct V_3 * ) V_96 ;
struct V_31 * V_32 = V_7 -> V_32 ;
int V_108 ;
if ( F_44 ( & V_32 -> V_102 ) )
return - V_103 ;
if ( V_7 -> V_86 != V_107 || V_7 -> type != V_53 ) {
F_45 ( & V_32 -> V_102 ) ;
return - V_101 ;
}
if ( ! V_32 -> V_109 ) {
F_45 ( & V_32 -> V_102 ) ;
return - V_110 ;
}
if ( ( V_108 = V_32 -> V_109 ( V_7 ) ) < 0 ) {
F_45 ( & V_32 -> V_102 ) ;
return V_108 ;
}
F_37 ( & V_32 -> V_74 ) ;
V_96 -> V_35 = 1 ;
V_7 -> V_86 = V_111 ;
F_40 ( & V_32 -> V_74 ) ;
F_45 ( & V_32 -> V_102 ) ;
return 0 ;
}
static int F_47 ( struct V_95 * V_96 )
{
struct V_3 * V_7 = (struct V_3 * ) V_96 ;
struct V_31 * V_32 = V_7 -> V_32 ;
int V_108 ;
F_48 ( & V_32 -> V_102 ) ;
if ( V_7 -> V_86 < V_111 ) {
F_45 ( & V_32 -> V_102 ) ;
return - V_101 ;
}
if ( ! V_32 -> V_112 ) {
F_45 ( & V_32 -> V_102 ) ;
return - V_110 ;
}
V_108 = V_32 -> V_112 ( V_7 ) ;
F_37 ( & V_32 -> V_74 ) ;
V_96 -> V_35 = 0 ;
V_7 -> V_86 = V_88 ;
F_40 ( & V_32 -> V_74 ) ;
F_45 ( & V_32 -> V_102 ) ;
return V_108 ;
}
static int F_49 ( struct V_113 * V_114 ,
struct V_95 * * V_96 ,
T_7 V_115 )
{
struct V_31 * V_32 = (struct V_31 * ) V_114 ;
struct V_3 * V_7 ;
if ( F_44 ( & V_32 -> V_102 ) )
return - V_103 ;
if ( ! ( V_7 = F_34 ( V_32 ) ) ) {
F_45 ( & V_32 -> V_102 ) ;
return - V_116 ;
}
V_7 -> type = V_53 ;
V_7 -> V_17 . V_18 = V_115 ;
V_7 -> V_32 = V_32 ;
V_7 -> V_60 = 0xffff ;
V_7 -> V_16 = 0xfffa ;
( * V_96 ) = & V_7 -> V_7 . V_18 ;
( * V_96 ) -> V_117 = V_114 ;
( * V_96 ) -> V_118 = NULL ;
( * V_96 ) -> V_35 = 0 ;
( * V_96 ) -> V_119 = F_46 ;
( * V_96 ) -> V_120 = F_47 ;
( * V_96 ) -> V_121 = F_43 ;
if ( ! ( V_7 -> V_24 = F_33 ( V_32 ) ) ) {
V_7 -> V_86 = V_87 ;
F_45 ( & V_32 -> V_102 ) ;
return - V_116 ;
}
V_7 -> V_24 -> type = V_53 ;
V_7 -> V_24 -> V_7 = V_7 ;
V_7 -> V_24 -> V_86 = V_107 ;
F_45 ( & V_32 -> V_102 ) ;
return 0 ;
}
static int F_50 ( struct V_113 * V_114 ,
struct V_95 * V_96 )
{
struct V_31 * V_32 = (struct V_31 * ) V_114 ;
struct V_3 * V_7 = (struct V_3 * ) V_96 ;
F_48 ( & V_32 -> V_102 ) ;
if ( V_7 -> V_86 == V_87 ) {
F_45 ( & V_32 -> V_102 ) ;
return - V_101 ;
}
V_7 -> V_86 = V_87 ;
V_7 -> V_24 -> V_86 = V_87 ;
F_41 ( V_7 ) ;
V_7 -> V_60 = 0xffff ;
if ( V_7 -> V_54 & V_57 && V_7 -> V_98 < V_104 )
V_32 -> V_105 [ V_7 -> V_98 ] = NULL ;
F_45 ( & V_32 -> V_102 ) ;
return 0 ;
}
static int F_51 ( struct V_33 * V_7 ,
struct V_122 * * V_24 )
{
struct V_3 * V_123 = (struct V_3 * ) V_7 ;
struct V_31 * V_124 = V_123 -> V_32 ;
struct V_19 * V_125 ;
if ( F_44 ( & V_124 -> V_102 ) )
return - V_103 ;
V_125 = F_33 ( V_124 ) ;
if ( ! V_125 ) {
F_45 ( & V_124 -> V_102 ) ;
return - V_116 ;
}
F_37 ( & V_124 -> V_74 ) ;
* V_24 = & V_125 -> V_24 ;
( * V_24 ) -> V_117 = V_7 ;
( * V_24 ) -> V_118 = NULL ;
V_125 -> V_7 = V_123 ;
V_125 -> type = V_59 ;
V_125 -> V_86 = V_107 ;
V_125 -> V_38 = V_123 -> V_24 ;
V_123 -> V_24 = V_125 ;
F_40 ( & V_124 -> V_74 ) ;
F_45 ( & V_124 -> V_102 ) ;
return 0 ;
}
static int F_52 ( struct V_33 * V_7 ,
T_1 V_60 , int V_36 )
{
struct V_3 * V_123 = (struct V_3 * ) V_7 ;
struct V_31 * V_126 = V_123 -> V_32 ;
if ( V_60 > 0x1fff )
return - V_101 ;
if ( F_44 ( & V_126 -> V_102 ) )
return - V_103 ;
F_36 ( V_123 ) ;
V_123 -> V_60 = V_60 ;
V_123 -> V_7 . V_8 . V_36 = V_36 ;
V_123 -> V_86 = V_107 ;
F_45 ( & V_126 -> V_102 ) ;
return 0 ;
}
static void F_53 ( struct V_3 * V_123 )
{
int V_21 ;
struct V_19 * V_4 ;
struct V_122 * V_127 ;
T_2 V_128 , V_129 , V_29 ;
if ( ! ( V_4 = V_123 -> V_24 ) )
return;
do {
V_127 = & V_4 -> V_24 ;
V_29 = 0 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
V_129 = V_127 -> V_130 [ V_21 ] ;
V_128 = V_127 -> V_131 [ V_21 ] ;
V_4 -> V_27 [ V_21 ] = V_128 & V_129 ;
V_29 |= V_4 -> V_28 [ V_21 ] = V_128 & ~ V_129 ;
}
V_4 -> V_29 = V_29 ? 1 : 0 ;
} while ( ( V_4 = V_4 -> V_38 ) );
}
static int F_54 ( struct V_33 * V_7 )
{
struct V_3 * V_123 = (struct V_3 * ) V_7 ;
struct V_31 * V_126 = V_123 -> V_32 ;
int V_108 ;
if ( F_44 ( & V_126 -> V_102 ) )
return - V_103 ;
if ( V_7 -> V_35 ) {
F_45 ( & V_126 -> V_102 ) ;
return - V_116 ;
}
if ( ! V_123 -> V_24 ) {
F_45 ( & V_126 -> V_102 ) ;
return - V_101 ;
}
V_123 -> V_7 . V_8 . V_40 = 0 ;
V_123 -> V_7 . V_8 . V_26 = V_123 -> V_7 . V_8 . V_42 ;
V_123 -> V_7 . V_8 . V_39 = 0 ;
V_123 -> V_7 . V_8 . V_30 = 0 ;
if ( ! V_126 -> V_109 ) {
F_45 ( & V_126 -> V_102 ) ;
return - V_110 ;
}
F_53 ( V_123 ) ;
if ( ( V_108 = V_126 -> V_109 ( V_123 ) ) < 0 ) {
F_45 ( & V_126 -> V_102 ) ;
return V_108 ;
}
F_37 ( & V_126 -> V_74 ) ;
V_7 -> V_35 = 1 ;
V_123 -> V_86 = V_111 ;
F_40 ( & V_126 -> V_74 ) ;
F_45 ( & V_126 -> V_102 ) ;
return 0 ;
}
static int F_55 ( struct V_33 * V_7 )
{
struct V_3 * V_123 = (struct V_3 * ) V_7 ;
struct V_31 * V_126 = V_123 -> V_32 ;
int V_108 ;
F_48 ( & V_126 -> V_102 ) ;
if ( ! V_126 -> V_112 ) {
F_45 ( & V_126 -> V_102 ) ;
return - V_110 ;
}
V_108 = V_126 -> V_112 ( V_123 ) ;
F_37 ( & V_126 -> V_74 ) ;
V_123 -> V_86 = V_107 ;
V_7 -> V_35 = 0 ;
F_40 ( & V_126 -> V_74 ) ;
F_45 ( & V_126 -> V_102 ) ;
return V_108 ;
}
static int F_56 ( struct V_33 * V_7 ,
struct V_122 * V_24 )
{
struct V_19 * V_125 = (struct V_19 * ) V_24 , * V_4 ;
struct V_3 * V_123 = (struct V_3 * ) V_7 ;
struct V_31 * V_126 = V_123 -> V_32 ;
F_48 ( & V_126 -> V_102 ) ;
if ( V_125 -> V_7 != V_123 ) {
F_45 ( & V_126 -> V_102 ) ;
return - V_101 ;
}
if ( V_7 -> V_35 ) {
F_45 ( & V_126 -> V_102 ) ;
V_7 -> V_120 ( V_7 ) ;
F_48 ( & V_126 -> V_102 ) ;
}
F_37 ( & V_126 -> V_74 ) ;
V_4 = V_123 -> V_24 ;
if ( V_4 == V_125 ) {
V_123 -> V_24 = V_125 -> V_38 ;
} else {
while ( V_4 -> V_38 != V_125 )
V_4 = V_4 -> V_38 ;
V_4 -> V_38 = V_4 -> V_38 -> V_38 ;
}
V_125 -> V_86 = V_87 ;
F_40 ( & V_126 -> V_74 ) ;
F_45 ( & V_126 -> V_102 ) ;
return 0 ;
}
static int F_57 ( struct V_113 * V_32 ,
struct V_33 * * V_7 ,
T_8 V_115 )
{
struct V_31 * V_126 = (struct V_31 * ) V_32 ;
struct V_3 * V_123 ;
if ( F_44 ( & V_126 -> V_102 ) )
return - V_103 ;
if ( ! ( V_123 = F_34 ( V_126 ) ) ) {
F_45 ( & V_126 -> V_102 ) ;
return - V_116 ;
}
V_123 -> type = V_59 ;
V_123 -> V_17 . V_8 = V_115 ;
V_123 -> V_32 = V_126 ;
V_123 -> V_60 = 0xffff ;
V_123 -> V_7 . V_8 . V_26 = V_123 -> V_7 . V_8 . V_42 ;
V_123 -> V_7 . V_8 . V_39 = V_123 -> V_7 . V_8 . V_30 = 0 ;
V_123 -> V_7 . V_8 . V_40 = 0 ;
V_123 -> V_24 = NULL ;
( * V_7 ) = & V_123 -> V_7 . V_8 ;
( * V_7 ) -> V_35 = 0 ;
( * V_7 ) -> V_117 = V_32 ;
( * V_7 ) -> V_118 = NULL ;
( * V_7 ) -> V_121 = F_52 ;
( * V_7 ) -> V_132 = F_51 ;
( * V_7 ) -> V_119 = F_54 ;
( * V_7 ) -> V_120 = F_55 ;
( * V_7 ) -> V_133 = F_56 ;
F_45 ( & V_126 -> V_102 ) ;
return 0 ;
}
static int F_58 ( struct V_113 * V_32 ,
struct V_33 * V_7 )
{
struct V_3 * V_123 = (struct V_3 * ) V_7 ;
struct V_31 * V_126 = (struct V_31 * ) V_32 ;
F_48 ( & V_126 -> V_102 ) ;
if ( V_123 -> V_86 == V_87 ) {
F_45 ( & V_126 -> V_102 ) ;
return - V_101 ;
}
V_123 -> V_86 = V_87 ;
F_41 ( V_123 ) ;
V_123 -> V_60 = 0xffff ;
F_45 ( & V_126 -> V_102 ) ;
return 0 ;
}
static int F_59 ( struct V_113 * V_32 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
if ( V_124 -> V_134 >= V_135 )
return - V_136 ;
V_124 -> V_134 ++ ;
return 0 ;
}
static int F_60 ( struct V_113 * V_32 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
if ( V_124 -> V_134 == 0 )
return - V_110 ;
V_124 -> V_134 -- ;
return 0 ;
}
static int F_61 ( struct V_113 * V_32 , const char T_9 * V_1 , T_4 V_12 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
void * V_13 ;
if ( ( ! V_32 -> V_137 ) || ( V_32 -> V_137 -> V_138 != V_139 ) )
return - V_101 ;
V_13 = F_62 ( V_1 , V_12 ) ;
if ( F_63 ( V_13 ) )
return F_64 ( V_13 ) ;
if ( F_44 ( & V_124 -> V_102 ) ) {
F_65 ( V_13 ) ;
return - V_103 ;
}
F_30 ( V_124 , V_13 , V_12 ) ;
F_65 ( V_13 ) ;
F_45 ( & V_124 -> V_102 ) ;
if ( F_66 ( V_140 ) )
return - V_141 ;
return V_12 ;
}
static int F_67 ( struct V_113 * V_32 ,
struct V_142 * V_137 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
struct V_93 * V_143 = & V_124 -> V_144 ;
F_39 ( & ( V_137 -> V_145 ) , V_143 ) ;
return 0 ;
}
static int F_68 ( struct V_113 * V_32 ,
struct V_142 * V_137 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
struct V_93 * V_75 , * V_41 , * V_143 = & V_124 -> V_144 ;
F_69 (pos, n, head) {
if ( F_70 ( V_75 ) == V_137 ) {
F_42 ( V_75 ) ;
return 0 ;
}
}
return - V_110 ;
}
static struct V_93 * F_71 ( struct V_113 * V_32 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
if ( F_72 ( & V_124 -> V_144 ) )
return NULL ;
return & V_124 -> V_144 ;
}
static int F_73 ( struct V_113 * V_32 ,
struct V_142 * V_137 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
if ( V_32 -> V_137 )
return - V_101 ;
F_48 ( & V_124 -> V_102 ) ;
V_32 -> V_137 = V_137 ;
F_45 ( & V_124 -> V_102 ) ;
return 0 ;
}
static int F_74 ( struct V_113 * V_32 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
F_48 ( & V_124 -> V_102 ) ;
V_32 -> V_137 = NULL ;
F_45 ( & V_124 -> V_102 ) ;
return 0 ;
}
static int F_75 ( struct V_113 * V_32 , T_1 * V_106 )
{
struct V_31 * V_124 = (struct V_31 * ) V_32 ;
memcpy ( V_106 , V_124 -> V_106 , 5 * sizeof( T_1 ) ) ;
return 0 ;
}
int F_76 ( struct V_31 * V_124 )
{
int V_21 ;
struct V_113 * V_114 = & V_124 -> V_114 ;
V_124 -> V_70 = NULL ;
V_124 -> V_134 = 0 ;
V_124 -> V_24 = F_77 ( V_124 -> V_85 * sizeof( struct V_19 ) ) ;
if ( ! V_124 -> V_24 )
return - V_146 ;
V_124 -> V_7 = F_77 ( V_124 -> V_89 * sizeof( struct V_3 ) ) ;
if ( ! V_124 -> V_7 ) {
F_78 ( V_124 -> V_24 ) ;
V_124 -> V_24 = NULL ;
return - V_146 ;
}
for ( V_21 = 0 ; V_21 < V_124 -> V_85 ; V_21 ++ ) {
V_124 -> V_24 [ V_21 ] . V_86 = V_87 ;
V_124 -> V_24 [ V_21 ] . V_147 = V_21 ;
}
for ( V_21 = 0 ; V_21 < V_124 -> V_89 ; V_21 ++ ) {
V_124 -> V_7 [ V_21 ] . V_86 = V_87 ;
V_124 -> V_7 [ V_21 ] . V_147 = V_21 ;
}
V_124 -> V_70 = F_77 ( V_72 + 1 ) ;
if ( ! V_124 -> V_70 )
F_79 ( L_15 ) ;
F_80 ( & V_124 -> V_144 ) ;
for ( V_21 = 0 ; V_21 < V_104 ; V_21 ++ ) {
V_124 -> V_105 [ V_21 ] = NULL ;
V_124 -> V_106 [ V_21 ] = 0xffff ;
}
F_80 ( & V_124 -> V_94 ) ;
V_124 -> V_148 = 0 ;
V_124 -> V_149 = 0 ;
V_124 -> V_82 = 0 ;
if ( ! V_124 -> V_37 )
V_124 -> V_37 = F_4 ;
if ( ! V_124 -> V_45 )
V_124 -> V_45 = F_6 ;
V_114 -> V_137 = NULL ;
V_114 -> V_118 = V_124 ;
V_114 -> V_150 = F_59 ;
V_114 -> V_151 = F_60 ;
V_114 -> V_152 = F_61 ;
V_114 -> V_153 = F_49 ;
V_114 -> V_154 = F_50 ;
V_114 -> V_155 = F_57 ;
V_114 -> V_156 = F_58 ;
V_114 -> V_157 = F_67 ;
V_114 -> V_158 = F_68 ;
V_114 -> V_159 = F_71 ;
V_114 -> V_160 = F_73 ;
V_114 -> V_161 = F_74 ;
V_114 -> V_162 = F_75 ;
F_81 ( & V_124 -> V_102 ) ;
F_82 ( & V_124 -> V_74 ) ;
return 0 ;
}
void F_83 ( struct V_31 * V_124 )
{
F_78 ( V_124 -> V_70 ) ;
F_78 ( V_124 -> V_24 ) ;
F_78 ( V_124 -> V_7 ) ;
}
