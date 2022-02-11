static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_9 , L_1 ) ;
if ( V_6 -> V_10 ) {
F_4 ( V_1 ) ;
V_6 -> V_10 = false ;
}
F_5 ( V_6 -> V_11 ) ;
return V_12 ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_2 ( & V_14 -> V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_9 , L_2 ) ;
F_5 ( V_6 -> V_11 ) ;
}
static void F_7 ( struct V_13 * V_14 )
{
}
int F_8 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
int V_18 = 0 ;
T_2 V_19 ;
T_3 V_20 , V_21 ;
V_17 = & V_6 -> V_22 -> V_11 . V_8 ;
if ( V_17 -> V_23 ) {
F_3 ( V_24 , L_3 ,
V_17 -> V_25 ) ;
F_9 ( & V_6 -> V_26 ) ;
V_6 -> V_10 = true ;
V_18 = F_10 ( V_17 -> V_25 , F_1 ,
V_17 -> V_27 , L_4 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
if ( V_18 != 0 ) {
F_11 ( L_5 , V_18 ) ;
return V_18 ;
}
V_6 -> V_28 = true ;
V_18 = F_12 ( V_17 -> V_25 ) ;
if ( V_18 != 0 ) {
F_11 ( L_6 , V_18 ) ;
return V_18 ;
}
V_6 -> V_29 = true ;
F_13 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_4 -> V_30 == V_31 ) {
V_20 = F_14 ( V_32 , V_21 ) ;
V_21 = F_15 ( V_6 , V_20 , & V_18 ) ;
V_21 |= 0x2 ;
F_16 ( V_6 , V_20 , V_21 , & V_18 ) ;
F_17 ( V_6 , V_33 , 0xf ,
& V_18 ) ;
F_17 ( V_6 , V_34 , 0 , & V_18 ) ;
F_17 ( V_6 , V_35 , 0x2 , & V_18 ) ;
}
V_19 = F_18 ( V_6 , V_36 , & V_18 ) ;
V_19 |= 1 << V_37 | 1 << V_38 | 1 ;
F_17 ( V_6 , V_36 , V_19 , & V_18 ) ;
V_19 = V_39 | V_40 ;
if ( V_17 -> V_27 & V_41 )
V_19 |= V_42 ;
F_17 ( V_6 , V_43 , V_19 , & V_18 ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
} else {
F_3 ( V_24 , L_7 ) ;
F_13 ( V_6 -> V_14 [ 1 ] ) ;
F_20 ( V_6 -> V_14 [ 1 ] , F_6 ) ;
F_20 ( V_6 -> V_14 [ 2 ] , F_7 ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
V_6 -> V_44 = true ;
}
return 0 ;
}
void F_21 ( struct V_5 * V_6 )
{
F_3 ( V_24 , L_8 ,
V_6 -> V_28 ,
V_6 -> V_44 ) ;
if ( V_6 -> V_28 ) {
struct V_16 * V_17 ;
V_17 = & V_6 -> V_22 -> V_11 . V_8 ;
F_13 ( V_6 -> V_14 [ 1 ] ) ;
F_17 ( V_6 , V_43 , 0 , NULL ) ;
F_17 ( V_6 , V_36 , 0 , NULL ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
V_6 -> V_28 = false ;
if ( V_6 -> V_29 ) {
F_22 ( V_17 -> V_25 ) ;
V_6 -> V_29 = false ;
}
F_23 ( V_17 -> V_25 , & V_6 -> V_14 [ 1 ] -> V_15 ) ;
V_6 -> V_10 = false ;
V_6 -> V_28 = false ;
}
if ( V_6 -> V_44 ) {
F_13 ( V_6 -> V_14 [ 1 ] ) ;
F_24 ( V_6 -> V_14 [ 2 ] ) ;
F_24 ( V_6 -> V_14 [ 1 ] ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
V_6 -> V_44 = false ;
}
}
void F_25 ( struct V_5 * V_6 ,
enum V_45 V_46 )
{
if ( V_6 -> V_46 == V_47 ||
V_46 == V_6 -> V_46 )
return;
F_3 ( V_48 , L_9 , V_6 -> V_46 , V_46 ) ;
switch ( V_6 -> V_46 ) {
case V_49 :
F_26 ( V_6 -> V_4 , V_50 ) ;
break;
case V_51 :
if ( V_46 == V_49 )
F_26 ( V_6 -> V_4 , V_52 ) ;
break;
default:
break;
}
V_6 -> V_46 = V_46 ;
}
static inline int F_27 ( struct V_13 * V_14 ,
T_4 V_53 , T_2 V_54 )
{
int V_55 ;
if ( ( V_53 == V_56 ) ||
( V_53 == V_36 ) )
F_28 ( V_14 , V_54 , V_53 , & V_55 ) ;
else
F_29 ( V_14 , V_54 , V_53 , & V_55 ) ;
return V_55 ;
}
static int F_30 ( struct V_5 * V_6 , T_2 V_57 ,
T_3 V_20 , T_2 V_58 , void * V_19 , bool V_59 )
{
struct V_13 * V_14 ;
int V_18 = - V_60 ;
F_3 ( V_24 , L_10 ,
V_59 , V_57 , V_20 , V_58 ) ;
if ( F_31 ( V_58 > 1 && ! V_57 ) )
return - V_60 ;
V_14 = V_6 -> V_14 [ V_57 ] ;
switch ( V_58 ) {
case sizeof( T_2 ) :
if ( V_59 ) {
if ( V_57 )
F_28 ( V_14 , * ( T_2 * ) V_19 , V_20 , & V_18 ) ;
else
V_18 = F_27 ( V_14 , V_20 ,
* ( T_2 * ) V_19 ) ;
} else {
if ( V_57 )
* ( T_2 * ) V_19 = F_32 ( V_14 , V_20 , & V_18 ) ;
else
* ( T_2 * ) V_19 = F_33 ( V_14 , V_20 , & V_18 ) ;
}
break;
case sizeof( V_61 ) :
if ( V_59 )
F_34 ( V_14 , * ( V_61 * ) V_19 , V_20 , & V_18 ) ;
else
* ( V_61 * ) V_19 = F_35 ( V_14 , V_20 , & V_18 ) ;
break;
case sizeof( T_3 ) :
if ( V_59 )
F_36 ( V_14 , * ( T_3 * ) V_19 , V_20 , & V_18 ) ;
else
* ( T_3 * ) V_19 = F_37 ( V_14 , V_20 , & V_18 ) ;
break;
default:
F_11 ( L_11 , V_58 ) ;
break;
}
if ( V_18 )
F_3 ( V_24 , L_12 ,
V_59 ? L_13 : L_14 , V_57 , V_20 , V_18 ) ;
return V_18 ;
}
static int F_38 ( struct V_5 * V_6 , T_3 V_20 ,
T_2 V_58 , void * V_19 , bool V_59 )
{
T_2 V_14 ;
T_5 V_62 = 0 ;
int V_18 ;
if ( V_6 -> V_46 == V_47 )
return - V_63 ;
if ( ( V_20 & ~ V_64 ) == 0 )
V_14 = V_65 ;
else
V_14 = V_37 ;
do {
if ( ! V_59 )
memset ( V_19 , 0 , V_58 ) ;
if ( V_62 )
F_39 ( 1000 , 2000 ) ;
V_18 = F_30 ( V_6 , V_14 , V_20 , V_58 ,
V_19 , V_59 ) ;
} while ( V_18 != 0 && V_18 != - V_63 &&
V_62 ++ < V_66 );
if ( V_18 == - V_63 )
F_25 ( V_6 , V_47 ) ;
else if ( V_18 != 0 ) {
if ( V_20 != V_67 )
F_11 ( L_12 ,
V_59 ? L_13 : L_14 , V_14 , V_20 , V_18 ) ;
else
F_3 ( V_24 , L_12 ,
V_59 ? L_13 : L_14 , V_14 , V_20 , V_18 ) ;
}
return V_18 ;
}
static int
F_40 ( struct V_5 * V_6 , T_3 V_68 )
{
int V_69 = 0 , V_70 ;
T_2 V_20 [ 3 ] ;
if ( V_6 -> V_46 == V_47 )
return - V_63 ;
V_20 [ 0 ] = ( V_68 >> 8 ) & V_71 ;
V_20 [ 1 ] = ( V_68 >> 16 ) & V_72 ;
V_20 [ 2 ] = ( V_68 >> 24 ) & V_73 ;
for ( V_70 = 0 ; V_70 < 3 ; V_70 ++ ) {
V_69 = F_38 ( V_6 ,
V_74 + V_70 ,
sizeof( T_2 ) , & V_20 [ V_70 ] , true ) ;
if ( V_69 ) {
F_11 ( L_15 ,
V_74 + V_70 ) ;
break;
}
}
return V_69 ;
}
static int
F_41 ( struct V_5 * V_6 , T_4 V_75 , T_3 * V_20 )
{
T_4 V_76 = * V_20 & ~ V_77 ;
int V_69 = 0 ;
if ( V_76 != V_6 -> V_78 ) {
V_69 = F_40 ( V_6 , V_76 ) ;
if ( V_69 )
return V_69 ;
V_6 -> V_78 = V_76 ;
}
* V_20 &= V_77 ;
if ( V_75 == 4 )
* V_20 |= V_79 ;
return 0 ;
}
T_2 F_18 ( struct V_5 * V_6 , T_3 V_20 , int * V_18 )
{
T_2 V_19 ;
int V_80 ;
F_3 ( V_24 , L_16 , V_20 ) ;
V_80 = F_38 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
false ) ;
F_3 ( V_24 , L_17 , V_19 ) ;
if ( V_18 )
* V_18 = V_80 ;
return V_19 ;
}
T_3 F_15 ( struct V_5 * V_6 , T_3 V_20 , int * V_18 )
{
T_3 V_19 = 0 ;
int V_80 ;
F_3 ( V_24 , L_16 , V_20 ) ;
V_80 = F_41 ( V_6 , sizeof( V_19 ) , & V_20 ) ;
if ( V_80 )
goto V_81;
V_80 = F_38 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
false ) ;
F_3 ( V_24 , L_18 , V_19 ) ;
V_81:
if ( V_18 )
* V_18 = V_80 ;
return V_19 ;
}
void F_17 ( struct V_5 * V_6 , T_3 V_20 ,
T_2 V_19 , int * V_18 )
{
int V_80 ;
F_3 ( V_24 , L_19 , V_20 , V_19 ) ;
V_80 = F_38 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
true ) ;
if ( V_18 )
* V_18 = V_80 ;
}
void F_16 ( struct V_5 * V_6 , T_3 V_20 ,
T_3 V_19 , int * V_18 )
{
int V_80 ;
F_3 ( V_24 , L_20 , V_20 , V_19 ) ;
V_80 = F_41 ( V_6 , sizeof( V_19 ) , & V_20 ) ;
if ( V_80 )
goto V_81;
V_80 = F_38 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
true ) ;
V_81:
if ( V_18 )
* V_18 = V_80 ;
}
static int F_42 ( struct V_5 * V_6 , T_4 V_57 ,
bool V_59 , T_3 V_20 , struct V_82 * V_83 )
{
unsigned int V_84 ;
int V_69 ;
V_84 = V_83 -> V_85 + 3 ;
V_84 &= ( T_4 ) ~ 3 ;
if ( V_59 )
V_69 = F_43 ( V_6 -> V_14 [ V_57 ] , V_20 ,
( ( T_2 * ) ( V_83 -> V_19 ) ) , V_84 ) ;
else if ( V_57 == 1 )
V_69 = F_44 ( V_6 -> V_14 [ V_57 ] , ( ( T_2 * ) ( V_83 -> V_19 ) ) ,
V_20 , V_84 ) ;
else
V_69 = F_45 ( V_6 -> V_14 [ V_57 ] , ( ( T_2 * ) ( V_83 -> V_19 ) ) , V_20 ,
V_84 ) ;
if ( V_69 == - V_63 )
F_25 ( V_6 , V_47 ) ;
return V_69 ;
}
static int F_46 ( struct V_5 * V_6 , T_4 V_57 ,
bool V_59 , T_3 V_20 ,
struct V_86 * V_87 )
{
unsigned int V_84 , V_88 , V_89 , V_90 , V_91 ;
unsigned int V_92 , V_93 , V_94 ;
unsigned short V_95 , V_96 ;
unsigned char * V_97 , * V_98 , * V_99 ;
struct V_82 * V_100 = NULL , * V_101 ;
struct V_86 V_102 , * V_103 ;
struct V_104 V_105 ;
struct V_106 V_107 ;
struct V_108 V_109 ;
struct V_110 * V_111 ;
int V_18 = 0 ;
if ( ! V_87 -> V_112 )
return - V_60 ;
V_103 = V_87 ;
F_47 ( & V_102 ) ;
if ( ! V_59 && V_6 -> V_22 -> V_11 . V_8 . V_113 ) {
V_84 = 0 ;
F_48 (pktlist, pkt_next)
V_84 += V_100 -> V_85 ;
V_84 = F_49 ( V_84 , V_6 -> V_14 [ V_57 ] -> V_114 ) ;
while ( V_84 > V_115 ) {
V_100 = F_50 ( V_115 ) ;
if ( V_100 == NULL ) {
V_18 = - V_116 ;
goto exit;
}
F_51 ( & V_102 , V_100 ) ;
V_84 -= V_115 ;
}
V_100 = F_50 ( V_84 ) ;
if ( V_100 == NULL ) {
V_18 = - V_116 ;
goto exit;
}
F_51 ( & V_102 , V_100 ) ;
V_103 = & V_102 ;
}
V_88 = V_6 -> V_14 [ V_57 ] -> V_114 ;
V_92 = V_6 -> V_117 ;
V_95 = F_52 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_96 = V_103 -> V_112 ;
V_91 = 0 ;
V_100 = V_103 -> V_118 ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
memset ( & V_107 , 0 , sizeof( struct V_106 ) ) ;
memset ( & V_109 , 0 , sizeof( struct V_108 ) ) ;
V_109 . V_119 = V_6 -> V_120 . V_111 ;
V_109 . V_121 = V_88 ;
V_109 . V_122 = V_59 ? V_123 : V_124 ;
V_107 . V_125 = V_126 ;
V_107 . V_127 = V_59 ? 1 << 31 : 0 ;
V_107 . V_127 |= ( V_57 & 0x7 ) << 28 ;
V_107 . V_127 |= 1 << 27 ;
V_107 . V_127 |= ( V_57 == 1 ) ? 1 << 26 : 0 ;
V_107 . V_122 = V_128 | V_129 | V_130 ;
V_105 . V_131 = & V_107 ;
V_105 . V_19 = & V_109 ;
while ( V_96 ) {
V_84 = 0 ;
V_89 = 0 ;
V_111 = V_6 -> V_120 . V_111 ;
while ( V_100 != (struct V_82 * ) V_103 ) {
V_97 = V_100 -> V_19 + V_91 ;
V_90 = V_100 -> V_85 - V_91 ;
if ( V_90 > V_6 -> V_132 )
V_90 = V_6 -> V_132 ;
if ( V_90 > V_92 - V_84 )
V_90 = V_92 - V_84 ;
F_53 ( V_111 , V_97 , V_90 ) ;
V_89 ++ ;
V_111 = F_54 ( V_111 ) ;
V_84 += V_90 ;
V_91 += V_90 ;
if ( V_91 == V_100 -> V_85 ) {
V_91 = 0 ;
V_100 = V_100 -> V_118 ;
}
if ( V_84 >= V_92 || V_89 >= V_95 )
break;
}
V_96 -= V_89 ;
if ( V_84 % V_88 != 0 ) {
F_11 ( L_21 ,
V_84 , V_88 ) ;
V_18 = - V_133 ;
goto exit;
}
V_109 . V_134 = V_89 ;
V_109 . V_135 = V_84 / V_88 ;
V_107 . V_127 |= ( V_20 & 0x1FFFF ) << 9 ;
V_107 . V_127 |= V_109 . V_135 & 0x1FF ;
if ( V_57 == 1 )
V_20 += V_84 ;
F_55 ( & V_109 , V_6 -> V_14 [ V_57 ] -> V_136 ) ;
F_56 ( V_6 -> V_14 [ V_57 ] -> V_136 -> V_137 , & V_105 ) ;
V_18 = V_107 . error ? V_107 . error : V_109 . error ;
if ( V_18 == - V_63 ) {
F_25 ( V_6 , V_47 ) ;
break;
} else if ( V_18 != 0 ) {
F_11 ( L_22 ,
V_59 ? L_13 : L_14 , V_18 ) ;
V_18 = - V_138 ;
break;
}
}
if ( ! V_59 && V_6 -> V_22 -> V_11 . V_8 . V_113 ) {
V_101 = V_102 . V_118 ;
V_93 = 0 ;
F_48 (pktlist, pkt_next) {
V_94 = 0 ;
do {
V_84 = V_101 -> V_85 - V_93 ;
V_84 = F_52 ( T_4 , V_100 -> V_85 - V_94 ,
V_84 ) ;
V_98 = V_101 -> V_19 + V_93 ;
V_99 = V_100 -> V_19 + V_94 ;
memcpy ( V_99 , V_98 , V_84 ) ;
V_93 += V_84 ;
V_94 += V_84 ;
if ( V_93 == V_101 -> V_85 ) {
V_93 = 0 ;
V_101 = V_101 -> V_118 ;
}
if ( V_94 == V_100 -> V_85 )
break;
} while ( ! F_57 ( & V_102 ) );
}
}
exit:
F_58 ( V_6 -> V_120 . V_111 , V_6 -> V_120 . V_139 ) ;
while ( ( V_100 = F_59 ( & V_102 ) ) != NULL )
F_60 ( V_100 ) ;
return V_18 ;
}
int F_61 ( struct V_5 * V_6 , T_2 * V_140 , T_4 V_141 )
{
struct V_82 * V_142 ;
int V_69 ;
V_142 = F_50 ( V_141 ) ;
if ( ! V_142 ) {
F_11 ( L_23 ,
V_141 ) ;
return - V_138 ;
}
V_69 = F_62 ( V_6 , V_142 ) ;
if ( ! V_69 )
memcpy ( V_140 , V_142 -> V_19 , V_141 ) ;
F_60 ( V_142 ) ;
return V_69 ;
}
int F_62 ( struct V_5 * V_6 , struct V_82 * V_83 )
{
T_3 V_20 = V_6 -> V_78 ;
int V_69 = 0 ;
F_3 ( V_24 , L_24 , V_20 , V_83 -> V_85 ) ;
V_69 = F_41 ( V_6 , 4 , & V_20 ) ;
if ( V_69 )
goto V_81;
V_69 = F_42 ( V_6 , V_38 , false , V_20 , V_83 ) ;
V_81:
return V_69 ;
}
int F_63 ( struct V_5 * V_6 ,
struct V_86 * V_143 , T_4 V_144 )
{
struct V_82 * V_145 = NULL ;
struct V_82 * V_146 ;
T_3 V_20 = V_6 -> V_78 ;
int V_69 = 0 ;
F_3 ( V_24 , L_24 ,
V_20 , V_143 -> V_112 ) ;
V_69 = F_41 ( V_6 , 4 , & V_20 ) ;
if ( V_69 )
goto V_81;
if ( V_143 -> V_112 == 1 )
V_69 = F_42 ( V_6 , V_38 , false , V_20 ,
V_143 -> V_118 ) ;
else if ( ! V_6 -> V_147 ) {
V_145 = F_50 ( V_144 ) ;
if ( ! V_145 )
return - V_116 ;
V_69 = F_42 ( V_6 , V_38 , false , V_20 ,
V_145 ) ;
if ( V_69 )
goto V_81;
F_48 (pktq, skb) {
memcpy ( V_146 -> V_19 , V_145 -> V_19 , V_146 -> V_85 ) ;
F_64 ( V_145 , V_146 -> V_85 ) ;
}
} else
V_69 = F_46 ( V_6 , V_38 , false , V_20 ,
V_143 ) ;
V_81:
F_60 ( V_145 ) ;
return V_69 ;
}
int F_65 ( struct V_5 * V_6 , T_2 * V_140 , T_4 V_141 )
{
struct V_82 * V_142 ;
T_3 V_20 = V_6 -> V_78 ;
int V_69 ;
V_142 = F_50 ( V_141 ) ;
if ( ! V_142 ) {
F_11 ( L_23 ,
V_141 ) ;
return - V_138 ;
}
memcpy ( V_142 -> V_19 , V_140 , V_141 ) ;
V_69 = F_41 ( V_6 , 4 , & V_20 ) ;
if ( ! V_69 )
V_69 = F_42 ( V_6 , V_38 , true , V_20 ,
V_142 ) ;
F_60 ( V_142 ) ;
return V_69 ;
}
int F_66 ( struct V_5 * V_6 ,
struct V_86 * V_143 )
{
struct V_82 * V_146 ;
T_3 V_20 = V_6 -> V_78 ;
int V_69 ;
F_3 ( V_24 , L_24 , V_20 , V_143 -> V_112 ) ;
V_69 = F_41 ( V_6 , 4 , & V_20 ) ;
if ( V_69 )
return V_69 ;
if ( V_143 -> V_112 == 1 || ! V_6 -> V_147 )
F_48 (pktq, skb) {
V_69 = F_42 ( V_6 , V_38 , true ,
V_20 , V_146 ) ;
if ( V_69 )
break;
}
else
V_69 = F_46 ( V_6 , V_38 , true , V_20 ,
V_143 ) ;
return V_69 ;
}
int
F_67 ( struct V_5 * V_6 , bool V_59 , T_3 V_68 ,
T_2 * V_19 , T_4 V_148 )
{
int V_149 = 0 ;
struct V_82 * V_83 ;
T_3 V_150 ;
T_4 V_151 ;
V_151 = F_52 ( T_4 , V_152 , V_148 ) ;
V_83 = F_68 ( V_151 ) ;
if ( ! V_83 ) {
F_11 ( L_25 , V_151 ) ;
return - V_138 ;
}
V_83 -> V_153 = 0 ;
V_150 = V_68 & V_77 ;
if ( ( V_150 + V_148 ) & V_154 )
V_151 = ( V_152 - V_150 ) ;
else
V_151 = V_148 ;
F_13 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_148 ) {
V_149 = F_40 ( V_6 , V_68 ) ;
if ( V_149 )
break;
F_3 ( V_24 , L_26 ,
V_59 ? L_13 : L_14 , V_151 ,
V_150 , V_68 & V_154 ) ;
V_150 &= V_77 ;
V_150 |= V_79 ;
F_69 ( V_83 , V_151 ) ;
if ( V_59 )
memcpy ( V_83 -> V_19 , V_19 , V_151 ) ;
V_149 = F_42 ( V_6 , V_37 , V_59 ,
V_150 , V_83 ) ;
if ( V_149 ) {
F_11 ( L_27 ) ;
break;
}
if ( ! V_59 )
memcpy ( V_19 , V_83 -> V_19 , V_151 ) ;
F_70 ( V_83 , 0 ) ;
V_148 -= V_151 ;
if ( V_148 ) {
V_19 += V_151 ;
V_68 += V_151 ;
V_150 = 0 ;
V_151 = F_52 ( T_4 , V_152 , V_148 ) ;
}
}
F_71 ( V_83 ) ;
if ( F_40 ( V_6 , V_6 -> V_78 ) )
F_11 ( L_28 ,
V_6 -> V_78 ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
return V_149 ;
}
int F_72 ( struct V_5 * V_6 , T_4 V_57 )
{
char V_155 = ( char ) V_57 ;
F_3 ( V_24 , L_29 ) ;
F_30 ( V_6 , V_65 , V_56 ,
sizeof( V_155 ) , & V_155 , true ) ;
F_3 ( V_24 , L_30 ) ;
return 0 ;
}
void F_73 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_156 * V_137 ;
T_4 V_157 ;
T_4 V_158 ;
int V_69 ;
V_14 = V_6 -> V_14 [ 2 ] ;
V_137 = V_14 -> V_136 -> V_137 ;
V_6 -> V_147 = V_137 -> V_159 > 1 ;
V_157 = F_52 ( T_4 , V_137 -> V_160 , 511u ) ;
V_6 -> V_117 = F_52 ( T_4 , V_137 -> V_161 ,
V_157 * V_14 -> V_114 ) ;
V_6 -> V_162 = F_52 ( T_4 , V_137 -> V_159 ,
V_163 ) ;
V_6 -> V_132 = V_137 -> V_164 ;
if ( ! V_6 -> V_147 )
return;
V_158 = F_74 ( T_4 , V_165 ,
V_6 -> V_22 -> V_11 . V_8 . V_166 ) ;
V_158 += ( V_158 >> 4 ) + 1 ;
F_31 ( V_158 > V_6 -> V_162 ) ;
F_3 ( V_48 , L_31 , V_158 ) ;
V_69 = F_75 ( & V_6 -> V_120 , V_158 , V_167 ) ;
if ( V_69 < 0 ) {
F_11 ( L_32 ) ;
V_6 -> V_147 = false ;
}
V_6 -> V_166 = V_6 -> V_22 -> V_11 . V_8 . V_166 ;
}
static int F_76 ( struct V_5 * V_6 )
{
V_6 -> V_168 = F_77 ( sizeof( * V_6 -> V_168 ) , V_167 ) ;
if ( ! V_6 -> V_168 )
return - V_116 ;
F_78 ( & V_6 -> V_168 -> V_169 , 0 ) ;
F_78 ( & V_6 -> V_168 -> V_170 , 0 ) ;
F_79 ( & V_6 -> V_168 -> V_171 ) ;
F_80 ( & V_6 -> V_168 -> V_172 ) ;
return 0 ;
}
static void F_81 ( struct V_5 * V_6 )
{
if ( V_6 -> V_168 ) {
F_31 ( F_82 ( & V_6 -> V_168 -> V_170 ) ) ;
F_83 ( V_6 -> V_168 ) ;
}
}
static int F_84 ( struct V_5 * V_6 )
{
T_6 * V_173 = & V_6 -> V_168 -> V_169 ;
int V_174 = 0 ;
V_6 -> V_168 -> V_175 = 0 ;
F_85 ( & V_6 -> V_168 -> V_172 ) ;
F_78 ( & V_6 -> V_168 -> V_170 , 1 ) ;
F_86 ( V_6 -> V_11 ) ;
F_87 ( V_6 -> V_168 -> V_171 ,
F_82 ( V_173 ) == V_6 -> V_168 -> V_175 ) ;
F_13 ( V_6 -> V_14 [ 1 ] ) ;
V_174 = F_88 ( V_6 -> V_11 , true ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
return V_174 ;
}
static void F_89 ( struct V_5 * V_6 )
{
F_13 ( V_6 -> V_14 [ 1 ] ) ;
F_88 ( V_6 -> V_11 , false ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
F_78 ( & V_6 -> V_168 -> V_170 , 0 ) ;
F_90 ( & V_6 -> V_168 -> V_172 ) ;
}
bool F_91 ( struct V_5 * V_6 )
{
return F_82 ( & V_6 -> V_168 -> V_170 ) ;
}
void F_92 ( struct V_5 * V_6 )
{
if ( ! F_91 ( V_6 ) )
return;
V_6 -> V_168 -> V_175 ++ ;
F_93 ( & V_6 -> V_168 -> V_171 ) ;
F_94 ( & V_6 -> V_168 -> V_172 ) ;
}
void F_95 ( struct V_5 * V_6 )
{
F_96 ( & V_6 -> V_168 -> V_169 ) ;
}
void F_97 ( struct V_5 * V_6 )
{
F_98 ( & V_6 -> V_168 -> V_169 ) ;
}
static int F_76 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_81 ( struct V_5 * V_6 )
{
}
static int F_99 ( struct V_5 * V_6 )
{
V_6 -> V_46 = V_51 ;
if ( V_6 -> V_11 ) {
F_100 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_81 ( V_6 ) ;
F_13 ( V_6 -> V_14 [ 2 ] ) ;
F_101 ( V_6 -> V_14 [ 2 ] ) ;
F_19 ( V_6 -> V_14 [ 2 ] ) ;
F_13 ( V_6 -> V_14 [ 1 ] ) ;
F_101 ( V_6 -> V_14 [ 1 ] ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
F_102 ( & V_6 -> V_120 ) ;
V_6 -> V_78 = 0 ;
F_103 ( V_6 -> V_14 [ 1 ] -> V_136 -> V_137 -> V_176 ) ;
return 0 ;
}
static void F_104 ( struct V_156 * V_137 )
{
F_105 ( V_137 -> V_176 ) ;
V_137 -> V_177 |= V_178 ;
}
static int F_106 ( struct V_5 * V_6 )
{
int V_18 = 0 ;
V_6 -> V_179 = 2 ;
F_13 ( V_6 -> V_14 [ 1 ] ) ;
V_18 = F_107 ( V_6 -> V_14 [ 1 ] , V_180 ) ;
if ( V_18 ) {
F_11 ( L_33 ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
goto V_181;
}
V_18 = F_107 ( V_6 -> V_14 [ 2 ] , V_182 ) ;
if ( V_18 ) {
F_11 ( L_34 ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
goto V_181;
}
V_6 -> V_14 [ 2 ] -> V_183 = V_184 ;
V_18 = F_108 ( V_6 -> V_14 [ 1 ] ) ;
F_19 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_18 ) {
F_11 ( L_35 , V_18 ) ;
goto V_181;
}
V_18 = F_76 ( V_6 ) ;
if ( V_18 )
goto V_181;
V_6 -> V_11 = F_109 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_18 = - V_185 ;
goto V_181;
}
F_104 ( V_6 -> V_14 [ 2 ] -> V_136 -> V_137 ) ;
V_181:
if ( V_18 )
F_99 ( V_6 ) ;
return V_18 ;
}
static void F_110 ( struct V_186 * V_15 ,
int V_187 )
{
#if F_111 ( V_188 )
struct V_189 * V_190 ;
V_190 = F_112 ( V_15 ) ;
if ( V_190 )
V_190 -> V_122 . V_191 = 0 ;
#endif
}
static int F_113 ( struct V_13 * V_14 ,
const struct V_192 * V_193 )
{
int V_69 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_186 * V_15 ;
F_3 ( V_24 , L_29 ) ;
F_3 ( V_24 , L_36 , V_14 -> V_194 ) ;
F_3 ( V_24 , L_37 , V_14 -> V_195 ) ;
F_3 ( V_24 , L_38 , V_14 -> V_186 ) ;
F_3 ( V_24 , L_39 , V_14 -> V_196 ) ;
V_15 = & V_14 -> V_15 ;
F_110 ( V_15 , 0 ) ;
if ( V_14 -> V_196 == 1 )
return 0 ;
if ( V_14 -> V_196 != 2 )
return - V_185 ;
V_4 = F_77 ( sizeof( struct V_3 ) , V_167 ) ;
if ( ! V_4 )
return - V_116 ;
V_6 = F_77 ( sizeof( struct V_5 ) , V_167 ) ;
if ( ! V_6 ) {
F_83 ( V_4 ) ;
return - V_116 ;
}
V_6 -> V_14 [ 0 ] = F_114 ( V_14 , sizeof( * V_14 ) , V_167 ) ;
V_6 -> V_14 [ 0 ] -> V_196 = 0 ;
V_6 -> V_14 [ 1 ] = V_14 -> V_136 -> V_13 [ 0 ] ;
V_6 -> V_14 [ 2 ] = V_14 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 . V_8 = V_6 ;
V_4 -> V_197 = V_198 ;
F_115 ( & V_14 -> V_15 , V_4 ) ;
F_115 ( & V_6 -> V_14 [ 1 ] -> V_15 , V_4 ) ;
V_6 -> V_15 = & V_6 -> V_14 [ 1 ] -> V_15 ;
F_25 ( V_6 , V_51 ) ;
F_3 ( V_24 , L_40 ) ;
V_69 = F_106 ( V_6 ) ;
if ( V_69 ) {
F_11 ( L_41 , V_69 ) ;
goto V_199;
}
F_3 ( V_24 , L_42 ) ;
return 0 ;
V_199:
F_115 ( & V_14 -> V_15 , NULL ) ;
F_115 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_83 ( V_6 -> V_14 [ 0 ] ) ;
F_83 ( V_6 ) ;
F_83 ( V_4 ) ;
return V_69 ;
}
static void F_116 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( V_24 , L_29 ) ;
F_3 ( V_24 , L_37 , V_14 -> V_195 ) ;
F_3 ( V_24 , L_38 , V_14 -> V_186 ) ;
F_3 ( V_24 , L_43 , V_14 -> V_196 ) ;
V_4 = F_2 ( & V_14 -> V_15 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_7 . V_8 ;
F_21 ( V_6 ) ;
if ( V_14 -> V_196 != 1 )
return;
F_99 ( V_6 ) ;
F_115 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_115 ( & V_6 -> V_14 [ 2 ] -> V_15 , NULL ) ;
F_83 ( V_4 ) ;
F_83 ( V_6 -> V_14 [ 0 ] ) ;
F_83 ( V_6 ) ;
}
F_3 ( V_24 , L_30 ) ;
}
void F_117 ( struct V_186 * V_15 , bool V_200 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_24 , L_44 , V_200 ) ;
V_6 -> V_201 = V_200 ;
}
static int F_118 ( struct V_186 * V_15 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_7 V_202 ;
V_14 = F_119 ( V_15 , struct V_13 , V_15 ) ;
F_3 ( V_24 , L_45 , V_14 -> V_196 ) ;
if ( V_14 -> V_196 != V_37 )
return 0 ;
V_4 = F_2 ( V_15 ) ;
V_6 = V_4 -> V_7 . V_8 ;
F_84 ( V_6 ) ;
F_120 ( V_6 -> V_11 , 0 ) ;
V_202 = V_203 ;
if ( V_6 -> V_201 ) {
if ( V_6 -> V_22 -> V_11 . V_8 . V_23 )
F_12 ( V_6 -> V_22 -> V_11 . V_8 . V_25 ) ;
else
V_202 |= V_204 ;
}
if ( F_121 ( V_6 -> V_14 [ 1 ] , V_202 ) )
F_11 ( L_46 , V_202 ) ;
return 0 ;
}
static int F_122 ( struct V_186 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
struct V_13 * V_14 = F_119 ( V_15 , struct V_13 , V_15 ) ;
F_3 ( V_24 , L_45 , V_14 -> V_196 ) ;
if ( V_14 -> V_196 != V_38 )
return 0 ;
F_89 ( V_6 ) ;
return 0 ;
}
void F_123 ( void )
{
int V_18 ;
V_18 = F_124 ( & V_205 ) ;
if ( V_18 )
F_11 ( L_47 , V_18 ) ;
}
void F_125 ( void )
{
F_3 ( V_24 , L_29 ) ;
F_126 ( & V_205 ) ;
}
