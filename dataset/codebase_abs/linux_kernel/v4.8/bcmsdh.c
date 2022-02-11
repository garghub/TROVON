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
unsigned long V_22 ;
V_17 = & V_6 -> V_23 -> V_11 . V_8 ;
if ( V_17 -> V_24 ) {
F_3 ( V_25 , L_3 ,
V_17 -> V_26 ) ;
V_18 = F_9 ( V_17 -> V_26 , F_1 ,
V_17 -> V_27 , L_4 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
if ( V_18 != 0 ) {
F_10 ( L_5 , V_18 ) ;
return V_18 ;
}
V_6 -> V_28 = true ;
F_11 ( & V_6 -> V_29 ) ;
F_12 ( & V_6 -> V_29 , V_22 ) ;
V_6 -> V_10 = true ;
F_13 ( & V_6 -> V_29 , V_22 ) ;
V_18 = F_14 ( V_17 -> V_26 ) ;
if ( V_18 != 0 ) {
F_10 ( L_6 , V_18 ) ;
return V_18 ;
}
V_6 -> V_30 = true ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_4 -> V_31 == V_32 ) {
V_20 = F_16 ( V_33 , V_21 ) ;
V_21 = F_17 ( V_6 , V_20 , & V_18 ) ;
V_21 |= 0x2 ;
F_18 ( V_6 , V_20 , V_21 , & V_18 ) ;
F_19 ( V_6 , V_34 , 0xf ,
& V_18 ) ;
F_19 ( V_6 , V_35 , 0 , & V_18 ) ;
F_19 ( V_6 , V_36 , 0x2 , & V_18 ) ;
}
V_19 = F_20 ( V_6 , V_37 , & V_18 ) ;
V_19 |= 1 << V_38 | 1 << V_39 | 1 ;
F_19 ( V_6 , V_37 , V_19 , & V_18 ) ;
V_19 = V_40 | V_41 ;
if ( V_17 -> V_27 & V_42 )
V_19 |= V_43 ;
F_19 ( V_6 , V_44 , V_19 , & V_18 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
} else {
F_3 ( V_25 , L_7 ) ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_22 ( V_6 -> V_14 [ 1 ] , F_6 ) ;
F_22 ( V_6 -> V_14 [ 2 ] , F_7 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
V_6 -> V_45 = true ;
}
return 0 ;
}
void F_23 ( struct V_5 * V_6 )
{
F_3 ( V_25 , L_8 ,
V_6 -> V_28 ,
V_6 -> V_45 ) ;
if ( V_6 -> V_28 ) {
struct V_16 * V_17 ;
V_17 = & V_6 -> V_23 -> V_11 . V_8 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_19 ( V_6 , V_44 , 0 , NULL ) ;
F_19 ( V_6 , V_37 , 0 , NULL ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
V_6 -> V_28 = false ;
if ( V_6 -> V_30 ) {
F_24 ( V_17 -> V_26 ) ;
V_6 -> V_30 = false ;
}
F_25 ( V_17 -> V_26 , & V_6 -> V_14 [ 1 ] -> V_15 ) ;
V_6 -> V_10 = false ;
V_6 -> V_28 = false ;
}
if ( V_6 -> V_45 ) {
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_26 ( V_6 -> V_14 [ 2 ] ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
V_6 -> V_45 = false ;
}
}
void F_27 ( struct V_5 * V_6 ,
enum V_46 V_47 )
{
if ( V_6 -> V_47 == V_48 ||
V_47 == V_6 -> V_47 )
return;
F_3 ( V_49 , L_9 , V_6 -> V_47 , V_47 ) ;
switch ( V_6 -> V_47 ) {
case V_50 :
F_28 ( V_6 -> V_4 , V_51 ) ;
break;
case V_52 :
if ( V_47 == V_50 )
F_28 ( V_6 -> V_4 , V_53 ) ;
break;
default:
break;
}
V_6 -> V_47 = V_47 ;
}
static inline int F_29 ( struct V_13 * V_14 ,
T_4 V_54 , T_2 V_55 )
{
int V_56 ;
if ( ( V_54 == V_57 ) ||
( V_54 == V_37 ) )
F_30 ( V_14 , V_55 , V_54 , & V_56 ) ;
else
F_31 ( V_14 , V_55 , V_54 , & V_56 ) ;
return V_56 ;
}
static int F_32 ( struct V_5 * V_6 , T_2 V_58 ,
T_3 V_20 , T_2 V_59 , void * V_19 , bool V_60 )
{
struct V_13 * V_14 ;
int V_18 = - V_61 ;
F_3 ( V_25 , L_10 ,
V_60 , V_58 , V_20 , V_59 ) ;
if ( F_33 ( V_59 > 1 && ! V_58 ) )
return - V_61 ;
V_14 = V_6 -> V_14 [ V_58 ] ;
switch ( V_59 ) {
case sizeof( T_2 ) :
if ( V_60 ) {
if ( V_58 )
F_30 ( V_14 , * ( T_2 * ) V_19 , V_20 , & V_18 ) ;
else
V_18 = F_29 ( V_14 , V_20 ,
* ( T_2 * ) V_19 ) ;
} else {
if ( V_58 )
* ( T_2 * ) V_19 = F_34 ( V_14 , V_20 , & V_18 ) ;
else
* ( T_2 * ) V_19 = F_35 ( V_14 , V_20 , & V_18 ) ;
}
break;
case sizeof( V_62 ) :
if ( V_60 )
F_36 ( V_14 , * ( V_62 * ) V_19 , V_20 , & V_18 ) ;
else
* ( V_62 * ) V_19 = F_37 ( V_14 , V_20 , & V_18 ) ;
break;
case sizeof( T_3 ) :
if ( V_60 )
F_38 ( V_14 , * ( T_3 * ) V_19 , V_20 , & V_18 ) ;
else
* ( T_3 * ) V_19 = F_39 ( V_14 , V_20 , & V_18 ) ;
break;
default:
F_10 ( L_11 , V_59 ) ;
break;
}
if ( V_18 )
F_3 ( V_25 , L_12 ,
V_60 ? L_13 : L_14 , V_58 , V_20 , V_18 ) ;
return V_18 ;
}
static int F_40 ( struct V_5 * V_6 , T_3 V_20 ,
T_2 V_59 , void * V_19 , bool V_60 )
{
T_2 V_14 ;
T_5 V_63 = 0 ;
int V_18 ;
if ( V_6 -> V_47 == V_48 )
return - V_64 ;
if ( ( V_20 & ~ V_65 ) == 0 )
V_14 = V_66 ;
else
V_14 = V_38 ;
do {
if ( ! V_60 )
memset ( V_19 , 0 , V_59 ) ;
if ( V_63 )
F_41 ( 1000 , 2000 ) ;
V_18 = F_32 ( V_6 , V_14 , V_20 , V_59 ,
V_19 , V_60 ) ;
} while ( V_18 != 0 && V_18 != - V_64 &&
V_63 ++ < V_67 );
if ( V_18 == - V_64 )
F_27 ( V_6 , V_48 ) ;
else if ( V_18 != 0 ) {
if ( V_20 != V_68 )
F_10 ( L_12 ,
V_60 ? L_13 : L_14 , V_14 , V_20 , V_18 ) ;
else
F_3 ( V_25 , L_12 ,
V_60 ? L_13 : L_14 , V_14 , V_20 , V_18 ) ;
}
return V_18 ;
}
static int
F_42 ( struct V_5 * V_6 , T_3 V_69 )
{
int V_70 = 0 , V_71 ;
T_2 V_20 [ 3 ] ;
if ( V_6 -> V_47 == V_48 )
return - V_64 ;
V_20 [ 0 ] = ( V_69 >> 8 ) & V_72 ;
V_20 [ 1 ] = ( V_69 >> 16 ) & V_73 ;
V_20 [ 2 ] = ( V_69 >> 24 ) & V_74 ;
for ( V_71 = 0 ; V_71 < 3 ; V_71 ++ ) {
V_70 = F_40 ( V_6 ,
V_75 + V_71 ,
sizeof( T_2 ) , & V_20 [ V_71 ] , true ) ;
if ( V_70 ) {
F_10 ( L_15 ,
V_75 + V_71 ) ;
break;
}
}
return V_70 ;
}
static int
F_43 ( struct V_5 * V_6 , T_4 V_76 , T_3 * V_20 )
{
T_4 V_77 = * V_20 & ~ V_78 ;
int V_70 = 0 ;
if ( V_77 != V_6 -> V_79 ) {
V_70 = F_42 ( V_6 , V_77 ) ;
if ( V_70 )
return V_70 ;
V_6 -> V_79 = V_77 ;
}
* V_20 &= V_78 ;
if ( V_76 == 4 )
* V_20 |= V_80 ;
return 0 ;
}
T_2 F_20 ( struct V_5 * V_6 , T_3 V_20 , int * V_18 )
{
T_2 V_19 ;
int V_81 ;
F_3 ( V_25 , L_16 , V_20 ) ;
V_81 = F_40 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
false ) ;
F_3 ( V_25 , L_17 , V_19 ) ;
if ( V_18 )
* V_18 = V_81 ;
return V_19 ;
}
T_3 F_17 ( struct V_5 * V_6 , T_3 V_20 , int * V_18 )
{
T_3 V_19 ;
int V_81 ;
F_3 ( V_25 , L_16 , V_20 ) ;
V_81 = F_43 ( V_6 , sizeof( V_19 ) , & V_20 ) ;
if ( V_81 )
goto V_82;
V_81 = F_40 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
false ) ;
F_3 ( V_25 , L_18 , V_19 ) ;
V_82:
if ( V_18 )
* V_18 = V_81 ;
return V_19 ;
}
void F_19 ( struct V_5 * V_6 , T_3 V_20 ,
T_2 V_19 , int * V_18 )
{
int V_81 ;
F_3 ( V_25 , L_19 , V_20 , V_19 ) ;
V_81 = F_40 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
true ) ;
if ( V_18 )
* V_18 = V_81 ;
}
void F_18 ( struct V_5 * V_6 , T_3 V_20 ,
T_3 V_19 , int * V_18 )
{
int V_81 ;
F_3 ( V_25 , L_20 , V_20 , V_19 ) ;
V_81 = F_43 ( V_6 , sizeof( V_19 ) , & V_20 ) ;
if ( V_81 )
goto V_82;
V_81 = F_40 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
true ) ;
V_82:
if ( V_18 )
* V_18 = V_81 ;
}
static int F_44 ( struct V_5 * V_6 , T_4 V_58 ,
bool V_60 , T_3 V_20 , struct V_83 * V_84 )
{
unsigned int V_85 ;
int V_70 ;
V_85 = V_84 -> V_86 + 3 ;
V_85 &= ( T_4 ) ~ 3 ;
if ( V_60 )
V_70 = F_45 ( V_6 -> V_14 [ V_58 ] , V_20 ,
( ( T_2 * ) ( V_84 -> V_19 ) ) , V_85 ) ;
else if ( V_58 == 1 )
V_70 = F_46 ( V_6 -> V_14 [ V_58 ] , ( ( T_2 * ) ( V_84 -> V_19 ) ) ,
V_20 , V_85 ) ;
else
V_70 = F_47 ( V_6 -> V_14 [ V_58 ] , ( ( T_2 * ) ( V_84 -> V_19 ) ) , V_20 ,
V_85 ) ;
if ( V_70 == - V_64 )
F_27 ( V_6 , V_48 ) ;
return V_70 ;
}
static int F_48 ( struct V_5 * V_6 , T_4 V_58 ,
bool V_60 , T_3 V_20 ,
struct V_87 * V_88 )
{
unsigned int V_85 , V_89 , V_90 , V_91 , V_92 ;
unsigned int V_93 , V_94 , V_95 ;
unsigned short V_96 , V_97 ;
unsigned char * V_98 , * V_99 , * V_100 ;
struct V_83 * V_101 = NULL , * V_102 ;
struct V_87 V_103 , * V_104 ;
struct V_105 V_106 ;
struct V_107 V_108 ;
struct V_109 V_110 ;
struct V_111 * V_112 ;
int V_18 = 0 ;
if ( ! V_88 -> V_113 )
return - V_61 ;
V_104 = V_88 ;
F_49 ( & V_103 ) ;
if ( ! V_60 && V_6 -> V_23 -> V_11 . V_8 . V_114 ) {
V_85 = 0 ;
F_50 (pktlist, pkt_next)
V_85 += V_101 -> V_86 ;
V_85 = F_51 ( V_85 , V_6 -> V_14 [ V_58 ] -> V_115 ) ;
while ( V_85 > V_116 ) {
V_101 = F_52 ( V_116 ) ;
if ( V_101 == NULL ) {
V_18 = - V_117 ;
goto exit;
}
F_53 ( & V_103 , V_101 ) ;
V_85 -= V_116 ;
}
V_101 = F_52 ( V_85 ) ;
if ( V_101 == NULL ) {
V_18 = - V_117 ;
goto exit;
}
F_53 ( & V_103 , V_101 ) ;
V_104 = & V_103 ;
}
V_89 = V_6 -> V_14 [ V_58 ] -> V_115 ;
V_93 = V_6 -> V_118 ;
V_96 = F_54 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_97 = V_104 -> V_113 ;
V_92 = 0 ;
V_101 = V_104 -> V_119 ;
memset ( & V_106 , 0 , sizeof( struct V_105 ) ) ;
memset ( & V_108 , 0 , sizeof( struct V_107 ) ) ;
memset ( & V_110 , 0 , sizeof( struct V_109 ) ) ;
V_110 . V_120 = V_6 -> V_121 . V_112 ;
V_110 . V_122 = V_89 ;
V_110 . V_22 = V_60 ? V_123 : V_124 ;
V_108 . V_125 = V_126 ;
V_108 . V_127 = V_60 ? 1 << 31 : 0 ;
V_108 . V_127 |= ( V_58 & 0x7 ) << 28 ;
V_108 . V_127 |= 1 << 27 ;
V_108 . V_127 |= ( V_58 == 1 ) ? 1 << 26 : 0 ;
V_108 . V_22 = V_128 | V_129 | V_130 ;
V_106 . V_131 = & V_108 ;
V_106 . V_19 = & V_110 ;
while ( V_97 ) {
V_85 = 0 ;
V_90 = 0 ;
V_112 = V_6 -> V_121 . V_112 ;
while ( V_101 != (struct V_83 * ) V_104 ) {
V_98 = V_101 -> V_19 + V_92 ;
V_91 = V_101 -> V_86 - V_92 ;
if ( V_91 > V_6 -> V_132 )
V_91 = V_6 -> V_132 ;
if ( V_91 > V_93 - V_85 )
V_91 = V_93 - V_85 ;
F_55 ( V_112 , V_98 , V_91 ) ;
V_90 ++ ;
V_112 = F_56 ( V_112 ) ;
V_85 += V_91 ;
V_92 += V_91 ;
if ( V_92 == V_101 -> V_86 ) {
V_92 = 0 ;
V_101 = V_101 -> V_119 ;
}
if ( V_85 >= V_93 || V_90 >= V_96 )
break;
}
V_97 -= V_90 ;
if ( V_85 % V_89 != 0 ) {
F_10 ( L_21 ,
V_85 , V_89 ) ;
V_18 = - V_133 ;
goto exit;
}
V_110 . V_134 = V_90 ;
V_110 . V_135 = V_85 / V_89 ;
V_108 . V_127 |= ( V_20 & 0x1FFFF ) << 9 ;
V_108 . V_127 |= V_110 . V_135 & 0x1FF ;
if ( V_58 == 1 )
V_20 += V_85 ;
F_57 ( & V_110 , V_6 -> V_14 [ V_58 ] -> V_136 ) ;
F_58 ( V_6 -> V_14 [ V_58 ] -> V_136 -> V_137 , & V_106 ) ;
V_18 = V_108 . error ? V_108 . error : V_110 . error ;
if ( V_18 == - V_64 ) {
F_27 ( V_6 , V_48 ) ;
break;
} else if ( V_18 != 0 ) {
F_10 ( L_22 ,
V_60 ? L_13 : L_14 , V_18 ) ;
V_18 = - V_138 ;
break;
}
}
if ( ! V_60 && V_6 -> V_23 -> V_11 . V_8 . V_114 ) {
V_102 = V_103 . V_119 ;
V_94 = 0 ;
F_50 (pktlist, pkt_next) {
V_95 = 0 ;
do {
V_85 = V_102 -> V_86 - V_94 ;
V_85 = F_54 ( T_4 , V_101 -> V_86 - V_95 ,
V_85 ) ;
V_99 = V_102 -> V_19 + V_94 ;
V_100 = V_101 -> V_19 + V_95 ;
memcpy ( V_100 , V_99 , V_85 ) ;
V_94 += V_85 ;
V_95 += V_85 ;
if ( V_94 == V_102 -> V_86 ) {
V_94 = 0 ;
V_102 = V_102 -> V_119 ;
}
if ( V_95 == V_101 -> V_86 )
break;
} while ( ! F_59 ( & V_103 ) );
}
}
exit:
F_60 ( V_6 -> V_121 . V_112 , V_6 -> V_121 . V_139 ) ;
while ( ( V_101 = F_61 ( & V_103 ) ) != NULL )
F_62 ( V_101 ) ;
return V_18 ;
}
int F_63 ( struct V_5 * V_6 , T_2 * V_140 , T_4 V_141 )
{
struct V_83 * V_142 ;
int V_70 ;
V_142 = F_52 ( V_141 ) ;
if ( ! V_142 ) {
F_10 ( L_23 ,
V_141 ) ;
return - V_138 ;
}
V_70 = F_64 ( V_6 , V_142 ) ;
if ( ! V_70 )
memcpy ( V_140 , V_142 -> V_19 , V_141 ) ;
F_62 ( V_142 ) ;
return V_70 ;
}
int F_64 ( struct V_5 * V_6 , struct V_83 * V_84 )
{
T_3 V_20 = V_6 -> V_79 ;
int V_70 = 0 ;
F_3 ( V_25 , L_24 , V_20 , V_84 -> V_86 ) ;
V_70 = F_43 ( V_6 , 4 , & V_20 ) ;
if ( V_70 )
goto V_82;
V_70 = F_44 ( V_6 , V_39 , false , V_20 , V_84 ) ;
V_82:
return V_70 ;
}
int F_65 ( struct V_5 * V_6 ,
struct V_87 * V_143 , T_4 V_144 )
{
struct V_83 * V_145 ;
struct V_83 * V_146 ;
T_3 V_20 = V_6 -> V_79 ;
int V_70 = 0 ;
F_3 ( V_25 , L_24 ,
V_20 , V_143 -> V_113 ) ;
V_70 = F_43 ( V_6 , 4 , & V_20 ) ;
if ( V_70 )
goto V_82;
if ( V_143 -> V_113 == 1 )
V_70 = F_44 ( V_6 , V_39 , false , V_20 ,
V_143 -> V_119 ) ;
else if ( ! V_6 -> V_147 ) {
V_145 = F_52 ( V_144 ) ;
if ( ! V_145 )
return - V_117 ;
V_70 = F_44 ( V_6 , V_39 , false , V_20 ,
V_145 ) ;
if ( V_70 ) {
F_62 ( V_145 ) ;
goto V_82;
}
F_50 (pktq, skb) {
memcpy ( V_146 -> V_19 , V_145 -> V_19 , V_146 -> V_86 ) ;
F_66 ( V_145 , V_146 -> V_86 ) ;
}
} else
V_70 = F_48 ( V_6 , V_39 , false , V_20 ,
V_143 ) ;
V_82:
return V_70 ;
}
int F_67 ( struct V_5 * V_6 , T_2 * V_140 , T_4 V_141 )
{
struct V_83 * V_142 ;
T_3 V_20 = V_6 -> V_79 ;
int V_70 ;
V_142 = F_52 ( V_141 ) ;
if ( ! V_142 ) {
F_10 ( L_23 ,
V_141 ) ;
return - V_138 ;
}
memcpy ( V_142 -> V_19 , V_140 , V_141 ) ;
V_70 = F_43 ( V_6 , 4 , & V_20 ) ;
if ( ! V_70 )
V_70 = F_44 ( V_6 , V_39 , true , V_20 ,
V_142 ) ;
F_62 ( V_142 ) ;
return V_70 ;
}
int F_68 ( struct V_5 * V_6 ,
struct V_87 * V_143 )
{
struct V_83 * V_146 ;
T_3 V_20 = V_6 -> V_79 ;
int V_70 ;
F_3 ( V_25 , L_24 , V_20 , V_143 -> V_113 ) ;
V_70 = F_43 ( V_6 , 4 , & V_20 ) ;
if ( V_70 )
return V_70 ;
if ( V_143 -> V_113 == 1 || ! V_6 -> V_147 )
F_50 (pktq, skb) {
V_70 = F_44 ( V_6 , V_39 , true ,
V_20 , V_146 ) ;
if ( V_70 )
break;
}
else
V_70 = F_48 ( V_6 , V_39 , true , V_20 ,
V_143 ) ;
return V_70 ;
}
int
F_69 ( struct V_5 * V_6 , bool V_60 , T_3 V_69 ,
T_2 * V_19 , T_4 V_148 )
{
int V_149 = 0 ;
struct V_83 * V_84 ;
T_3 V_150 ;
T_4 V_151 ;
V_151 = F_54 ( T_4 , V_152 , V_148 ) ;
V_84 = F_70 ( V_151 ) ;
if ( ! V_84 ) {
F_10 ( L_25 , V_151 ) ;
return - V_138 ;
}
V_84 -> V_153 = 0 ;
V_150 = V_69 & V_78 ;
if ( ( V_150 + V_148 ) & V_154 )
V_151 = ( V_152 - V_150 ) ;
else
V_151 = V_148 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_148 ) {
V_149 = F_42 ( V_6 , V_69 ) ;
if ( V_149 )
break;
F_3 ( V_25 , L_26 ,
V_60 ? L_13 : L_14 , V_151 ,
V_150 , V_69 & V_154 ) ;
V_150 &= V_78 ;
V_150 |= V_80 ;
F_71 ( V_84 , V_151 ) ;
if ( V_60 )
memcpy ( V_84 -> V_19 , V_19 , V_151 ) ;
V_149 = F_44 ( V_6 , V_38 , V_60 ,
V_150 , V_84 ) ;
if ( V_149 ) {
F_10 ( L_27 ) ;
break;
}
if ( ! V_60 )
memcpy ( V_19 , V_84 -> V_19 , V_151 ) ;
F_72 ( V_84 , 0 ) ;
V_148 -= V_151 ;
if ( V_148 ) {
V_19 += V_151 ;
V_69 += V_151 ;
V_150 = 0 ;
V_151 = F_54 ( T_4 , V_152 , V_148 ) ;
}
}
F_73 ( V_84 ) ;
if ( F_42 ( V_6 , V_6 -> V_79 ) )
F_10 ( L_28 ,
V_6 -> V_79 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
return V_149 ;
}
int F_74 ( struct V_5 * V_6 , T_4 V_58 )
{
char V_155 = ( char ) V_58 ;
F_3 ( V_25 , L_29 ) ;
F_32 ( V_6 , V_66 , V_57 ,
sizeof( V_155 ) , & V_155 , true ) ;
F_3 ( V_25 , L_30 ) ;
return 0 ;
}
void F_75 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_156 * V_137 ;
T_4 V_157 ;
T_4 V_158 ;
int V_70 ;
V_14 = V_6 -> V_14 [ 2 ] ;
V_137 = V_14 -> V_136 -> V_137 ;
V_6 -> V_147 = V_137 -> V_159 > 1 ;
V_157 = F_54 ( T_4 , V_137 -> V_160 , 511u ) ;
V_6 -> V_118 = F_54 ( T_4 , V_137 -> V_161 ,
V_157 * V_14 -> V_115 ) ;
V_6 -> V_162 = F_54 ( T_4 , V_137 -> V_159 ,
V_163 ) ;
V_6 -> V_132 = V_137 -> V_164 ;
if ( ! V_6 -> V_147 )
return;
V_158 = F_76 ( T_4 , V_165 ,
V_6 -> V_23 -> V_11 . V_8 . V_166 ) ;
V_158 += ( V_158 >> 4 ) + 1 ;
F_33 ( V_158 > V_6 -> V_162 ) ;
F_3 ( V_49 , L_31 , V_158 ) ;
V_70 = F_77 ( & V_6 -> V_121 , V_158 , V_167 ) ;
if ( V_70 < 0 ) {
F_10 ( L_32 ) ;
V_6 -> V_147 = false ;
}
V_6 -> V_166 = V_6 -> V_23 -> V_11 . V_8 . V_166 ;
}
static int F_78 ( struct V_5 * V_6 )
{
V_6 -> V_168 = F_79 ( sizeof( * V_6 -> V_168 ) , V_167 ) ;
if ( ! V_6 -> V_168 )
return - V_117 ;
F_80 ( & V_6 -> V_168 -> V_169 , 0 ) ;
F_80 ( & V_6 -> V_168 -> V_170 , 0 ) ;
F_81 ( & V_6 -> V_168 -> V_171 ) ;
F_82 ( & V_6 -> V_168 -> V_172 ) ;
return 0 ;
}
static void F_83 ( struct V_5 * V_6 )
{
if ( V_6 -> V_168 ) {
F_33 ( F_84 ( & V_6 -> V_168 -> V_170 ) ) ;
F_85 ( V_6 -> V_168 ) ;
}
}
static int F_86 ( struct V_5 * V_6 )
{
T_6 * V_173 = & V_6 -> V_168 -> V_169 ;
int V_174 = 0 ;
V_6 -> V_168 -> V_175 = 0 ;
F_87 ( & V_6 -> V_168 -> V_172 ) ;
F_80 ( & V_6 -> V_168 -> V_170 , 1 ) ;
F_88 ( V_6 -> V_11 ) ;
F_89 ( V_6 -> V_168 -> V_171 ,
F_84 ( V_173 ) == V_6 -> V_168 -> V_175 ) ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
V_174 = F_90 ( V_6 -> V_11 , true ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
return V_174 ;
}
static void F_91 ( struct V_5 * V_6 )
{
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_90 ( V_6 -> V_11 , false ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
F_80 ( & V_6 -> V_168 -> V_170 , 0 ) ;
F_92 ( & V_6 -> V_168 -> V_172 ) ;
}
bool F_93 ( struct V_5 * V_6 )
{
return F_84 ( & V_6 -> V_168 -> V_170 ) ;
}
void F_94 ( struct V_5 * V_6 )
{
if ( ! F_93 ( V_6 ) )
return;
V_6 -> V_168 -> V_175 ++ ;
F_95 ( & V_6 -> V_168 -> V_171 ) ;
F_96 ( & V_6 -> V_168 -> V_172 ) ;
}
void F_97 ( struct V_5 * V_6 )
{
F_98 ( & V_6 -> V_168 -> V_169 ) ;
}
void F_99 ( struct V_5 * V_6 )
{
F_100 ( & V_6 -> V_168 -> V_169 ) ;
}
static int F_78 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_83 ( struct V_5 * V_6 )
{
}
static int F_101 ( struct V_5 * V_6 )
{
V_6 -> V_47 = V_52 ;
if ( V_6 -> V_11 ) {
F_102 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_83 ( V_6 ) ;
F_15 ( V_6 -> V_14 [ 2 ] ) ;
F_103 ( V_6 -> V_14 [ 2 ] ) ;
F_21 ( V_6 -> V_14 [ 2 ] ) ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_103 ( V_6 -> V_14 [ 1 ] ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
F_104 ( & V_6 -> V_121 ) ;
V_6 -> V_79 = 0 ;
F_105 ( V_6 -> V_14 [ 1 ] -> V_136 -> V_137 -> V_176 ) ;
return 0 ;
}
static void F_106 ( struct V_156 * V_137 )
{
F_107 ( V_137 -> V_176 ) ;
V_137 -> V_177 |= V_178 ;
}
static int F_108 ( struct V_5 * V_6 )
{
int V_18 = 0 ;
V_6 -> V_179 = 2 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
V_18 = F_109 ( V_6 -> V_14 [ 1 ] , V_180 ) ;
if ( V_18 ) {
F_10 ( L_33 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
goto V_181;
}
V_18 = F_109 ( V_6 -> V_14 [ 2 ] , V_182 ) ;
if ( V_18 ) {
F_10 ( L_34 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
goto V_181;
}
V_6 -> V_14 [ 2 ] -> V_183 = V_184 ;
V_18 = F_110 ( V_6 -> V_14 [ 1 ] ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_18 ) {
F_10 ( L_35 , V_18 ) ;
goto V_181;
}
V_18 = F_78 ( V_6 ) ;
if ( V_18 )
goto V_181;
V_6 -> V_11 = F_111 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_18 = - V_185 ;
goto V_181;
}
F_106 ( V_6 -> V_14 [ 2 ] -> V_136 -> V_137 ) ;
V_181:
if ( V_18 )
F_101 ( V_6 ) ;
return V_18 ;
}
static void F_112 ( struct V_186 * V_15 ,
int V_187 )
{
#if F_113 ( V_188 )
struct V_189 * V_190 ;
V_190 = F_114 ( V_15 ) ;
if ( V_190 )
V_190 -> V_22 . V_191 = 0 ;
#endif
}
static int F_115 ( struct V_13 * V_14 ,
const struct V_192 * V_193 )
{
int V_70 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_186 * V_15 ;
F_3 ( V_25 , L_29 ) ;
F_3 ( V_25 , L_36 , V_14 -> V_194 ) ;
F_3 ( V_25 , L_37 , V_14 -> V_195 ) ;
F_3 ( V_25 , L_38 , V_14 -> V_186 ) ;
F_3 ( V_25 , L_39 , V_14 -> V_196 ) ;
V_15 = & V_14 -> V_15 ;
F_112 ( V_15 , 0 ) ;
if ( V_14 -> V_196 == 1 )
return 0 ;
if ( V_14 -> V_196 != 2 )
return - V_185 ;
V_4 = F_79 ( sizeof( struct V_3 ) , V_167 ) ;
if ( ! V_4 )
return - V_117 ;
V_6 = F_79 ( sizeof( struct V_5 ) , V_167 ) ;
if ( ! V_6 ) {
F_85 ( V_4 ) ;
return - V_117 ;
}
V_6 -> V_14 [ 0 ] = F_116 ( V_14 , sizeof( * V_14 ) , V_167 ) ;
V_6 -> V_14 [ 0 ] -> V_196 = 0 ;
V_6 -> V_14 [ 1 ] = V_14 -> V_136 -> V_13 [ 0 ] ;
V_6 -> V_14 [ 2 ] = V_14 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 . V_8 = V_6 ;
V_4 -> V_197 = V_198 ;
F_117 ( & V_14 -> V_15 , V_4 ) ;
F_117 ( & V_6 -> V_14 [ 1 ] -> V_15 , V_4 ) ;
V_6 -> V_15 = & V_6 -> V_14 [ 1 ] -> V_15 ;
F_27 ( V_6 , V_52 ) ;
F_3 ( V_25 , L_40 ) ;
V_70 = F_108 ( V_6 ) ;
if ( V_70 ) {
F_10 ( L_41 , V_70 ) ;
goto V_199;
}
F_3 ( V_25 , L_42 ) ;
return 0 ;
V_199:
F_117 ( & V_14 -> V_15 , NULL ) ;
F_117 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_85 ( V_6 -> V_14 [ 0 ] ) ;
F_85 ( V_6 ) ;
F_85 ( V_4 ) ;
return V_70 ;
}
static void F_118 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( V_25 , L_29 ) ;
F_3 ( V_25 , L_37 , V_14 -> V_195 ) ;
F_3 ( V_25 , L_38 , V_14 -> V_186 ) ;
F_3 ( V_25 , L_43 , V_14 -> V_196 ) ;
V_4 = F_2 ( & V_14 -> V_15 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_7 . V_8 ;
F_23 ( V_6 ) ;
if ( V_14 -> V_196 != 1 )
return;
F_101 ( V_6 ) ;
F_117 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_117 ( & V_6 -> V_14 [ 2 ] -> V_15 , NULL ) ;
F_85 ( V_4 ) ;
F_85 ( V_6 -> V_14 [ 0 ] ) ;
F_85 ( V_6 ) ;
}
F_3 ( V_25 , L_30 ) ;
}
void F_119 ( struct V_186 * V_15 , bool V_200 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_25 , L_44 , V_200 ) ;
V_6 -> V_201 = V_200 ;
}
static int F_120 ( struct V_186 * V_15 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_7 V_202 ;
V_14 = F_121 ( V_15 , struct V_13 , V_15 ) ;
F_3 ( V_25 , L_45 , V_14 -> V_196 ) ;
if ( V_14 -> V_196 != V_38 )
return 0 ;
V_4 = F_2 ( V_15 ) ;
V_6 = V_4 -> V_7 . V_8 ;
F_86 ( V_6 ) ;
F_122 ( V_6 -> V_11 , 0 ) ;
V_202 = V_203 ;
if ( V_6 -> V_201 ) {
if ( V_6 -> V_23 -> V_11 . V_8 . V_24 )
F_14 ( V_6 -> V_23 -> V_11 . V_8 . V_26 ) ;
else
V_202 |= V_204 ;
}
if ( F_123 ( V_6 -> V_14 [ 1 ] , V_202 ) )
F_10 ( L_46 , V_202 ) ;
return 0 ;
}
static int F_124 ( struct V_186 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
struct V_13 * V_14 = F_121 ( V_15 , struct V_13 , V_15 ) ;
F_3 ( V_25 , L_45 , V_14 -> V_196 ) ;
if ( V_14 -> V_196 != V_39 )
return 0 ;
F_91 ( V_6 ) ;
return 0 ;
}
void F_125 ( void )
{
int V_18 ;
V_18 = F_126 ( & V_205 ) ;
if ( V_18 )
F_10 ( L_47 , V_18 ) ;
}
void F_127 ( void )
{
F_3 ( V_25 , L_29 ) ;
F_128 ( & V_205 ) ;
}
