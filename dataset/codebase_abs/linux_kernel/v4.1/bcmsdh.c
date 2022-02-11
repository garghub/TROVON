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
int V_16 = 0 ;
T_2 V_17 ;
T_3 V_18 , V_19 ;
unsigned long V_20 ;
if ( ( V_6 -> V_21 ) && ( V_6 -> V_21 -> V_22 ) ) {
F_3 ( V_23 , L_3 ,
V_6 -> V_21 -> V_24 ) ;
V_16 = F_9 ( V_6 -> V_21 -> V_24 ,
F_1 ,
V_6 -> V_21 -> V_25 ,
L_4 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
if ( V_16 != 0 ) {
F_10 ( L_5 , V_16 ) ;
return V_16 ;
}
V_6 -> V_26 = true ;
F_11 ( & V_6 -> V_27 ) ;
F_12 ( & V_6 -> V_27 , V_20 ) ;
V_6 -> V_10 = true ;
F_13 ( & V_6 -> V_27 , V_20 ) ;
V_16 = F_14 ( V_6 -> V_21 -> V_24 ) ;
if ( V_16 != 0 ) {
F_10 ( L_6 , V_16 ) ;
return V_16 ;
}
V_6 -> V_28 = true ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_4 -> V_29 == V_30 ) {
V_18 = F_16 ( V_31 , V_19 ) ;
V_19 = F_17 ( V_6 , V_18 , & V_16 ) ;
V_19 |= 0x2 ;
F_18 ( V_6 , V_18 , V_19 , & V_16 ) ;
F_19 ( V_6 , V_32 , 0xf ,
& V_16 ) ;
F_19 ( V_6 , V_33 , 0 , & V_16 ) ;
F_19 ( V_6 , V_34 , 0x2 , & V_16 ) ;
}
V_17 = F_20 ( V_6 , V_35 , & V_16 ) ;
V_17 |= 1 << V_36 | 1 << V_37 | 1 ;
F_19 ( V_6 , V_35 , V_17 , & V_16 ) ;
V_17 = V_38 | V_39 ;
if ( V_6 -> V_21 -> V_25 & V_40 )
V_17 |= V_41 ;
F_19 ( V_6 , V_42 , V_17 , & V_16 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
} else {
F_3 ( V_23 , L_7 ) ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_22 ( V_6 -> V_14 [ 1 ] , F_6 ) ;
F_22 ( V_6 -> V_14 [ 2 ] , F_7 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
}
return 0 ;
}
int F_23 ( struct V_5 * V_6 )
{
F_3 ( V_23 , L_7 ) ;
if ( ( V_6 -> V_21 ) && ( V_6 -> V_21 -> V_22 ) ) {
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_19 ( V_6 , V_42 , 0 , NULL ) ;
F_19 ( V_6 , V_35 , 0 , NULL ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_26 ) {
V_6 -> V_26 = false ;
if ( V_6 -> V_28 ) {
F_24 ( V_6 -> V_21 -> V_24 ) ;
V_6 -> V_28 = false ;
}
F_25 ( V_6 -> V_21 -> V_24 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
V_6 -> V_10 = false ;
}
} else {
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_26 ( V_6 -> V_14 [ 2 ] ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
}
return 0 ;
}
void F_27 ( struct V_5 * V_6 ,
enum V_43 V_44 )
{
if ( V_6 -> V_44 == V_45 ||
V_44 == V_6 -> V_44 )
return;
F_3 ( V_46 , L_8 , V_6 -> V_44 , V_44 ) ;
switch ( V_6 -> V_44 ) {
case V_47 :
F_28 ( V_6 -> V_4 , V_48 ) ;
break;
case V_49 :
if ( V_44 == V_47 )
F_28 ( V_6 -> V_4 , V_50 ) ;
break;
default:
break;
}
V_6 -> V_44 = V_44 ;
}
static inline int F_29 ( struct V_13 * V_14 ,
T_4 V_51 , T_2 V_52 )
{
int V_53 ;
if ( ( V_51 == V_54 ) ||
( V_51 == V_35 ) )
F_30 ( V_14 , V_52 , V_51 , & V_53 ) ;
else
F_31 ( V_14 , V_52 , V_51 , & V_53 ) ;
return V_53 ;
}
static int F_32 ( struct V_5 * V_6 , T_2 V_55 ,
T_3 V_18 , T_2 V_56 , void * V_17 , bool V_57 )
{
struct V_13 * V_14 ;
int V_16 ;
F_3 ( V_23 , L_9 ,
V_57 , V_55 , V_18 , V_56 ) ;
if ( F_33 ( V_56 > 1 && ! V_55 ) )
return - V_58 ;
V_14 = V_6 -> V_14 [ V_55 ] ;
switch ( V_56 ) {
case sizeof( T_2 ) :
if ( V_57 ) {
if ( V_55 )
F_30 ( V_14 , * ( T_2 * ) V_17 , V_18 , & V_16 ) ;
else
V_16 = F_29 ( V_14 , V_18 ,
* ( T_2 * ) V_17 ) ;
} else {
if ( V_55 )
* ( T_2 * ) V_17 = F_34 ( V_14 , V_18 , & V_16 ) ;
else
* ( T_2 * ) V_17 = F_35 ( V_14 , V_18 , & V_16 ) ;
}
break;
case sizeof( V_59 ) :
if ( V_57 )
F_36 ( V_14 , * ( V_59 * ) V_17 , V_18 , & V_16 ) ;
else
* ( V_59 * ) V_17 = F_37 ( V_14 , V_18 , & V_16 ) ;
break;
case sizeof( T_3 ) :
if ( V_57 )
F_38 ( V_14 , * ( T_3 * ) V_17 , V_18 , & V_16 ) ;
else
* ( T_3 * ) V_17 = F_39 ( V_14 , V_18 , & V_16 ) ;
break;
default:
F_10 ( L_10 , V_56 ) ;
break;
}
if ( V_16 )
F_3 ( V_23 , L_11 ,
V_57 ? L_12 : L_13 , V_55 , V_18 , V_16 ) ;
return V_16 ;
}
static int F_40 ( struct V_5 * V_6 , T_3 V_18 ,
T_2 V_56 , void * V_17 , bool V_57 )
{
T_2 V_14 ;
T_5 V_60 = 0 ;
int V_16 ;
if ( V_6 -> V_44 == V_45 )
return - V_61 ;
if ( ( V_18 & ~ V_62 ) == 0 )
V_14 = V_63 ;
else
V_14 = V_36 ;
do {
if ( ! V_57 )
memset ( V_17 , 0 , V_56 ) ;
if ( V_60 )
F_41 ( 1000 , 2000 ) ;
V_16 = F_32 ( V_6 , V_14 , V_18 , V_56 ,
V_17 , V_57 ) ;
} while ( V_16 != 0 && V_16 != - V_61 &&
V_60 ++ < V_64 );
if ( V_16 == - V_61 )
F_27 ( V_6 , V_45 ) ;
else if ( V_16 != 0 ) {
if ( V_18 != V_65 )
F_10 ( L_11 ,
V_57 ? L_12 : L_13 , V_14 , V_18 , V_16 ) ;
else
F_3 ( V_23 , L_11 ,
V_57 ? L_12 : L_13 , V_14 , V_18 , V_16 ) ;
}
return V_16 ;
}
static int
F_42 ( struct V_5 * V_6 , T_3 V_66 )
{
int V_67 = 0 , V_68 ;
T_2 V_18 [ 3 ] ;
if ( V_6 -> V_44 == V_45 )
return - V_61 ;
V_18 [ 0 ] = ( V_66 >> 8 ) & V_69 ;
V_18 [ 1 ] = ( V_66 >> 16 ) & V_70 ;
V_18 [ 2 ] = ( V_66 >> 24 ) & V_71 ;
for ( V_68 = 0 ; V_68 < 3 ; V_68 ++ ) {
V_67 = F_40 ( V_6 ,
V_72 + V_68 ,
sizeof( T_2 ) , & V_18 [ V_68 ] , true ) ;
if ( V_67 ) {
F_10 ( L_14 ,
V_72 + V_68 ) ;
break;
}
}
return V_67 ;
}
static int
F_43 ( struct V_5 * V_6 , T_4 V_73 , T_3 * V_18 )
{
T_4 V_74 = * V_18 & ~ V_75 ;
int V_67 = 0 ;
if ( V_74 != V_6 -> V_76 ) {
V_67 = F_42 ( V_6 , V_74 ) ;
if ( V_67 )
return V_67 ;
V_6 -> V_76 = V_74 ;
}
* V_18 &= V_75 ;
if ( V_73 == 4 )
* V_18 |= V_77 ;
return 0 ;
}
T_2 F_20 ( struct V_5 * V_6 , T_3 V_18 , int * V_16 )
{
T_2 V_17 ;
int V_78 ;
F_3 ( V_23 , L_15 , V_18 ) ;
V_78 = F_40 ( V_6 , V_18 , sizeof( V_17 ) , & V_17 ,
false ) ;
F_3 ( V_23 , L_16 , V_17 ) ;
if ( V_16 )
* V_16 = V_78 ;
return V_17 ;
}
T_3 F_17 ( struct V_5 * V_6 , T_3 V_18 , int * V_16 )
{
T_3 V_17 ;
int V_78 ;
F_3 ( V_23 , L_15 , V_18 ) ;
V_78 = F_43 ( V_6 , sizeof( V_17 ) , & V_18 ) ;
if ( V_78 )
goto V_79;
V_78 = F_40 ( V_6 , V_18 , sizeof( V_17 ) , & V_17 ,
false ) ;
F_3 ( V_23 , L_17 , V_17 ) ;
V_79:
if ( V_16 )
* V_16 = V_78 ;
return V_17 ;
}
void F_19 ( struct V_5 * V_6 , T_3 V_18 ,
T_2 V_17 , int * V_16 )
{
int V_78 ;
F_3 ( V_23 , L_18 , V_18 , V_17 ) ;
V_78 = F_40 ( V_6 , V_18 , sizeof( V_17 ) , & V_17 ,
true ) ;
if ( V_16 )
* V_16 = V_78 ;
}
void F_18 ( struct V_5 * V_6 , T_3 V_18 ,
T_3 V_17 , int * V_16 )
{
int V_78 ;
F_3 ( V_23 , L_19 , V_18 , V_17 ) ;
V_78 = F_43 ( V_6 , sizeof( V_17 ) , & V_18 ) ;
if ( V_78 )
goto V_79;
V_78 = F_40 ( V_6 , V_18 , sizeof( V_17 ) , & V_17 ,
true ) ;
V_79:
if ( V_16 )
* V_16 = V_78 ;
}
static int F_44 ( struct V_5 * V_6 , T_4 V_55 ,
bool V_57 , T_3 V_18 , struct V_80 * V_81 )
{
unsigned int V_82 ;
int V_67 ;
V_82 = V_81 -> V_83 + 3 ;
V_82 &= ( T_4 ) ~ 3 ;
if ( V_57 )
V_67 = F_45 ( V_6 -> V_14 [ V_55 ] , V_18 ,
( ( T_2 * ) ( V_81 -> V_17 ) ) , V_82 ) ;
else if ( V_55 == 1 )
V_67 = F_46 ( V_6 -> V_14 [ V_55 ] , ( ( T_2 * ) ( V_81 -> V_17 ) ) ,
V_18 , V_82 ) ;
else
V_67 = F_47 ( V_6 -> V_14 [ V_55 ] , ( ( T_2 * ) ( V_81 -> V_17 ) ) , V_18 ,
V_82 ) ;
if ( V_67 == - V_61 )
F_27 ( V_6 , V_45 ) ;
return V_67 ;
}
static int F_48 ( struct V_5 * V_6 , T_4 V_55 ,
bool V_57 , T_3 V_18 ,
struct V_84 * V_85 )
{
unsigned int V_82 , V_86 , V_87 , V_88 , V_89 ;
unsigned int V_90 , V_91 , V_92 ;
unsigned short V_93 , V_94 ;
unsigned char * V_95 , * V_96 , * V_97 ;
struct V_80 * V_98 = NULL , * V_99 ;
struct V_84 V_100 , * V_101 ;
struct V_102 V_103 ;
struct V_104 V_105 ;
struct V_106 V_107 ;
struct V_108 * V_109 ;
int V_16 = 0 ;
if ( ! V_85 -> V_110 )
return - V_58 ;
V_101 = V_85 ;
F_49 ( & V_100 ) ;
if ( V_6 -> V_21 && V_6 -> V_21 -> V_111 && ! V_57 ) {
V_82 = 0 ;
F_50 (pktlist, pkt_next)
V_82 += V_98 -> V_83 ;
V_82 = F_51 ( V_82 , V_6 -> V_14 [ V_55 ] -> V_112 ) ;
while ( V_82 > V_113 ) {
V_98 = F_52 ( V_113 ) ;
if ( V_98 == NULL ) {
V_16 = - V_114 ;
goto exit;
}
F_53 ( & V_100 , V_98 ) ;
V_82 -= V_113 ;
}
V_98 = F_52 ( V_82 ) ;
if ( V_98 == NULL ) {
V_16 = - V_114 ;
goto exit;
}
F_53 ( & V_100 , V_98 ) ;
V_101 = & V_100 ;
}
V_86 = V_6 -> V_14 [ V_55 ] -> V_112 ;
V_90 = V_6 -> V_115 ;
V_93 = F_54 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_94 = V_101 -> V_110 ;
V_89 = 0 ;
V_98 = V_101 -> V_116 ;
memset ( & V_103 , 0 , sizeof( struct V_102 ) ) ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
memset ( & V_107 , 0 , sizeof( struct V_106 ) ) ;
V_107 . V_117 = V_6 -> V_118 . V_109 ;
V_107 . V_119 = V_86 ;
V_107 . V_20 = V_57 ? V_120 : V_121 ;
V_105 . V_122 = V_123 ;
V_105 . V_124 = V_57 ? 1 << 31 : 0 ;
V_105 . V_124 |= ( V_55 & 0x7 ) << 28 ;
V_105 . V_124 |= 1 << 27 ;
V_105 . V_124 |= ( V_55 == 1 ) ? 1 << 26 : 0 ;
V_105 . V_20 = V_125 | V_126 | V_127 ;
V_103 . V_128 = & V_105 ;
V_103 . V_17 = & V_107 ;
while ( V_94 ) {
V_82 = 0 ;
V_87 = 0 ;
V_109 = V_6 -> V_118 . V_109 ;
while ( V_98 != (struct V_80 * ) V_101 ) {
V_95 = V_98 -> V_17 + V_89 ;
V_88 = V_98 -> V_83 - V_89 ;
if ( V_88 > V_6 -> V_129 )
V_88 = V_6 -> V_129 ;
if ( V_88 > V_90 - V_82 )
V_88 = V_90 - V_82 ;
F_55 ( V_109 , V_95 , V_88 ) ;
V_87 ++ ;
V_109 = F_56 ( V_109 ) ;
V_82 += V_88 ;
V_89 += V_88 ;
if ( V_89 == V_98 -> V_83 ) {
V_89 = 0 ;
V_98 = V_98 -> V_116 ;
}
if ( V_82 >= V_90 || V_87 >= V_93 )
break;
}
V_94 -= V_87 ;
if ( V_82 % V_86 != 0 ) {
F_10 ( L_20 ,
V_82 , V_86 ) ;
V_16 = - V_130 ;
goto exit;
}
V_107 . V_131 = V_87 ;
V_107 . V_132 = V_82 / V_86 ;
V_105 . V_124 |= ( V_18 & 0x1FFFF ) << 9 ;
V_105 . V_124 |= V_107 . V_132 & 0x1FF ;
if ( V_55 == 1 )
V_18 += V_82 ;
F_57 ( & V_107 , V_6 -> V_14 [ V_55 ] -> V_133 ) ;
F_58 ( V_6 -> V_14 [ V_55 ] -> V_133 -> V_134 , & V_103 ) ;
V_16 = V_105 . error ? V_105 . error : V_107 . error ;
if ( V_16 == - V_61 ) {
F_27 ( V_6 , V_45 ) ;
break;
} else if ( V_16 != 0 ) {
F_10 ( L_21 ,
V_57 ? L_12 : L_13 , V_16 ) ;
V_16 = - V_135 ;
break;
}
}
if ( V_6 -> V_21 && V_6 -> V_21 -> V_111 && ! V_57 ) {
V_99 = V_100 . V_116 ;
V_91 = 0 ;
F_50 (pktlist, pkt_next) {
V_92 = 0 ;
do {
V_82 = V_99 -> V_83 - V_91 ;
V_82 = F_54 ( T_4 , V_98 -> V_83 - V_92 ,
V_82 ) ;
V_96 = V_99 -> V_17 + V_91 ;
V_97 = V_98 -> V_17 + V_92 ;
memcpy ( V_97 , V_96 , V_82 ) ;
V_91 += V_82 ;
V_92 += V_82 ;
if ( V_91 == V_99 -> V_83 ) {
V_91 = 0 ;
V_99 = V_99 -> V_116 ;
}
if ( V_92 == V_98 -> V_83 )
break;
} while ( ! F_59 ( & V_100 ) );
}
}
exit:
F_60 ( V_6 -> V_118 . V_109 , V_6 -> V_118 . V_136 ) ;
while ( ( V_98 = F_61 ( & V_100 ) ) != NULL )
F_62 ( V_98 ) ;
return V_16 ;
}
int F_63 ( struct V_5 * V_6 , T_2 * V_137 , T_4 V_138 )
{
struct V_80 * V_139 ;
int V_67 ;
V_139 = F_52 ( V_138 ) ;
if ( ! V_139 ) {
F_10 ( L_22 ,
V_138 ) ;
return - V_135 ;
}
V_67 = F_64 ( V_6 , V_139 ) ;
if ( ! V_67 )
memcpy ( V_137 , V_139 -> V_17 , V_138 ) ;
F_62 ( V_139 ) ;
return V_67 ;
}
int F_64 ( struct V_5 * V_6 , struct V_80 * V_81 )
{
T_3 V_18 = V_6 -> V_76 ;
int V_67 = 0 ;
F_3 ( V_23 , L_23 , V_18 , V_81 -> V_83 ) ;
V_67 = F_43 ( V_6 , 4 , & V_18 ) ;
if ( V_67 )
goto V_79;
V_67 = F_44 ( V_6 , V_37 , false , V_18 , V_81 ) ;
V_79:
return V_67 ;
}
int F_65 ( struct V_5 * V_6 ,
struct V_84 * V_140 , T_4 V_141 )
{
struct V_80 * V_142 ;
struct V_80 * V_143 ;
T_3 V_18 = V_6 -> V_76 ;
int V_67 = 0 ;
F_3 ( V_23 , L_23 ,
V_18 , V_140 -> V_110 ) ;
V_67 = F_43 ( V_6 , 4 , & V_18 ) ;
if ( V_67 )
goto V_79;
if ( V_140 -> V_110 == 1 )
V_67 = F_44 ( V_6 , V_37 , false , V_18 ,
V_140 -> V_116 ) ;
else if ( ! V_6 -> V_144 ) {
V_142 = F_52 ( V_141 ) ;
if ( ! V_142 )
return - V_114 ;
V_67 = F_44 ( V_6 , V_37 , false , V_18 ,
V_142 ) ;
if ( V_67 )
goto V_79;
F_50 (pktq, skb) {
memcpy ( V_143 -> V_17 , V_142 -> V_17 , V_143 -> V_83 ) ;
F_66 ( V_142 , V_143 -> V_83 ) ;
}
} else
V_67 = F_48 ( V_6 , V_37 , false , V_18 ,
V_140 ) ;
V_79:
return V_67 ;
}
int F_67 ( struct V_5 * V_6 , T_2 * V_137 , T_4 V_138 )
{
struct V_80 * V_139 ;
T_3 V_18 = V_6 -> V_76 ;
int V_67 ;
V_139 = F_52 ( V_138 ) ;
if ( ! V_139 ) {
F_10 ( L_22 ,
V_138 ) ;
return - V_135 ;
}
memcpy ( V_139 -> V_17 , V_137 , V_138 ) ;
V_67 = F_43 ( V_6 , 4 , & V_18 ) ;
if ( ! V_67 )
V_67 = F_44 ( V_6 , V_37 , true , V_18 ,
V_139 ) ;
F_62 ( V_139 ) ;
return V_67 ;
}
int F_68 ( struct V_5 * V_6 ,
struct V_84 * V_140 )
{
struct V_80 * V_143 ;
T_3 V_18 = V_6 -> V_76 ;
int V_67 ;
F_3 ( V_23 , L_23 , V_18 , V_140 -> V_110 ) ;
V_67 = F_43 ( V_6 , 4 , & V_18 ) ;
if ( V_67 )
return V_67 ;
if ( V_140 -> V_110 == 1 || ! V_6 -> V_144 )
F_50 (pktq, skb) {
V_67 = F_44 ( V_6 , V_37 , true ,
V_18 , V_143 ) ;
if ( V_67 )
break;
}
else
V_67 = F_48 ( V_6 , V_37 , true , V_18 ,
V_140 ) ;
return V_67 ;
}
int
F_69 ( struct V_5 * V_6 , bool V_57 , T_3 V_66 ,
T_2 * V_17 , T_4 V_145 )
{
int V_146 = 0 ;
struct V_80 * V_81 ;
T_3 V_147 ;
T_4 V_148 ;
V_148 = F_54 ( T_4 , V_149 , V_145 ) ;
V_81 = F_70 ( V_148 ) ;
if ( ! V_81 ) {
F_10 ( L_24 , V_148 ) ;
return - V_135 ;
}
V_81 -> V_150 = 0 ;
V_147 = V_66 & V_75 ;
if ( ( V_147 + V_145 ) & V_151 )
V_148 = ( V_149 - V_147 ) ;
else
V_148 = V_145 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_145 ) {
V_146 = F_42 ( V_6 , V_66 ) ;
if ( V_146 )
break;
F_3 ( V_23 , L_25 ,
V_57 ? L_12 : L_13 , V_148 ,
V_147 , V_66 & V_151 ) ;
V_147 &= V_75 ;
V_147 |= V_77 ;
F_71 ( V_81 , V_148 ) ;
if ( V_57 )
memcpy ( V_81 -> V_17 , V_17 , V_148 ) ;
V_146 = F_44 ( V_6 , V_36 , V_57 ,
V_147 , V_81 ) ;
if ( V_146 ) {
F_10 ( L_26 ) ;
break;
}
if ( ! V_57 )
memcpy ( V_17 , V_81 -> V_17 , V_148 ) ;
F_72 ( V_81 , 0 ) ;
V_145 -= V_148 ;
if ( V_145 ) {
V_17 += V_148 ;
V_66 += V_148 ;
V_147 = 0 ;
V_148 = F_54 ( T_4 , V_149 , V_145 ) ;
}
}
F_73 ( V_81 ) ;
if ( F_42 ( V_6 , V_6 -> V_76 ) )
F_10 ( L_27 ,
V_6 -> V_76 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
return V_146 ;
}
int F_74 ( struct V_5 * V_6 , T_4 V_55 )
{
char V_152 = ( char ) V_55 ;
F_3 ( V_23 , L_28 ) ;
F_32 ( V_6 , V_63 , V_54 ,
sizeof( V_152 ) , & V_152 , true ) ;
F_3 ( V_23 , L_29 ) ;
return 0 ;
}
static void F_75 ( struct V_5 * V_6 )
{
T_4 V_153 ;
int V_67 ;
if ( ! V_6 -> V_144 )
return;
V_153 = F_76 ( T_4 , V_154 , V_155 ) ;
V_153 += ( V_153 >> 4 ) + 1 ;
F_33 ( V_153 > V_6 -> V_156 ) ;
F_3 ( V_46 , L_30 , V_153 ) ;
V_67 = F_77 ( & V_6 -> V_118 , V_153 , V_157 ) ;
if ( V_67 < 0 ) {
F_10 ( L_31 ) ;
V_6 -> V_144 = false ;
}
V_6 -> V_158 = V_155 ;
}
static int F_78 ( struct V_5 * V_6 )
{
V_6 -> V_159 = F_79 ( sizeof( * V_6 -> V_159 ) , V_157 ) ;
if ( ! V_6 -> V_159 )
return - V_114 ;
F_80 ( & V_6 -> V_159 -> V_160 , 0 ) ;
F_80 ( & V_6 -> V_159 -> V_161 , 0 ) ;
F_81 ( & V_6 -> V_159 -> V_162 ) ;
F_82 ( & V_6 -> V_159 -> V_163 ) ;
return 0 ;
}
static void F_83 ( struct V_5 * V_6 )
{
if ( V_6 -> V_159 ) {
F_33 ( F_84 ( & V_6 -> V_159 -> V_161 ) ) ;
F_85 ( V_6 -> V_159 ) ;
}
}
static int F_86 ( struct V_5 * V_6 )
{
T_6 * V_164 = & V_6 -> V_159 -> V_160 ;
int V_165 = 0 ;
V_6 -> V_159 -> V_166 = 0 ;
F_87 ( & V_6 -> V_159 -> V_163 ) ;
F_80 ( & V_6 -> V_159 -> V_161 , 1 ) ;
F_88 ( V_6 -> V_11 ) ;
F_89 ( V_6 -> V_159 -> V_162 ,
F_84 ( V_164 ) == V_6 -> V_159 -> V_166 ) ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
V_165 = F_90 ( V_6 -> V_11 , true ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
return V_165 ;
}
static void F_91 ( struct V_5 * V_6 )
{
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_90 ( V_6 -> V_11 , false ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
F_80 ( & V_6 -> V_159 -> V_161 , 0 ) ;
F_92 ( & V_6 -> V_159 -> V_163 ) ;
}
bool F_93 ( struct V_5 * V_6 )
{
return F_84 ( & V_6 -> V_159 -> V_161 ) ;
}
void F_94 ( struct V_5 * V_6 )
{
if ( ! F_93 ( V_6 ) )
return;
V_6 -> V_159 -> V_166 ++ ;
F_95 ( & V_6 -> V_159 -> V_162 ) ;
F_96 ( & V_6 -> V_159 -> V_163 ) ;
}
void F_97 ( struct V_5 * V_6 )
{
F_98 ( & V_6 -> V_159 -> V_160 ) ;
}
void F_99 ( struct V_5 * V_6 )
{
F_100 ( & V_6 -> V_159 -> V_160 ) ;
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
F_104 ( & V_6 -> V_118 ) ;
V_6 -> V_76 = 0 ;
F_105 ( V_6 -> V_14 [ 1 ] -> V_133 -> V_134 -> V_167 ) ;
return 0 ;
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_168 * V_134 ;
T_4 V_169 ;
int V_16 = 0 ;
V_6 -> V_170 = 2 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
V_16 = F_107 ( V_6 -> V_14 [ 1 ] , V_171 ) ;
if ( V_16 ) {
F_10 ( L_32 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
goto V_172;
}
V_16 = F_107 ( V_6 -> V_14 [ 2 ] , V_173 ) ;
if ( V_16 ) {
F_10 ( L_33 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
goto V_172;
}
V_6 -> V_14 [ 2 ] -> V_174 = V_175 ;
V_16 = F_108 ( V_6 -> V_14 [ 1 ] ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_16 ) {
F_10 ( L_34 , V_16 ) ;
goto V_172;
}
V_14 = V_6 -> V_14 [ 2 ] ;
V_134 = V_14 -> V_133 -> V_134 ;
V_6 -> V_144 = V_134 -> V_176 > 1 ;
V_169 = F_54 ( T_4 , V_134 -> V_177 , 511u ) ;
V_6 -> V_115 = F_54 ( T_4 , V_134 -> V_178 ,
V_169 * V_14 -> V_112 ) ;
V_6 -> V_156 = F_54 ( T_4 , V_134 -> V_176 ,
V_179 ) ;
V_6 -> V_129 = V_134 -> V_180 ;
F_75 ( V_6 ) ;
V_16 = F_78 ( V_6 ) ;
if ( V_16 )
goto V_172;
V_6 -> V_11 = F_109 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_16 = - V_181 ;
goto V_172;
}
F_110 ( V_134 -> V_167 ) ;
V_172:
if ( V_16 )
F_101 ( V_6 ) ;
return V_16 ;
}
static int F_111 ( struct V_13 * V_14 ,
const struct V_182 * V_183 )
{
int V_67 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
F_3 ( V_23 , L_28 ) ;
F_3 ( V_23 , L_35 , V_14 -> V_184 ) ;
F_3 ( V_23 , L_36 , V_14 -> V_185 ) ;
F_3 ( V_23 , L_37 , V_14 -> V_186 ) ;
F_3 ( V_23 , L_38 , V_14 -> V_187 ) ;
if ( V_14 -> V_187 == 1 )
return 0 ;
if ( V_14 -> V_187 != 2 )
return - V_181 ;
V_4 = F_79 ( sizeof( struct V_3 ) , V_157 ) ;
if ( ! V_4 )
return - V_114 ;
V_6 = F_79 ( sizeof( struct V_5 ) , V_157 ) ;
if ( ! V_6 ) {
F_85 ( V_4 ) ;
return - V_114 ;
}
V_6 -> V_14 [ 0 ] = F_112 ( V_14 , sizeof( * V_14 ) , V_157 ) ;
V_6 -> V_14 [ 0 ] -> V_187 = 0 ;
V_6 -> V_14 [ 1 ] = V_14 -> V_133 -> V_13 [ 0 ] ;
V_6 -> V_14 [ 2 ] = V_14 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 . V_8 = V_6 ;
V_4 -> V_188 = V_189 ;
F_113 ( & V_14 -> V_15 , V_4 ) ;
F_113 ( & V_6 -> V_14 [ 1 ] -> V_15 , V_4 ) ;
V_6 -> V_15 = & V_6 -> V_14 [ 1 ] -> V_15 ;
V_6 -> V_21 = V_190 ;
if ( ! V_6 -> V_21 )
F_114 ( V_6 ) ;
#ifdef F_115
if ( ( F_116 ( V_6 -> V_14 [ 1 ] ) & V_191 ) &&
( ( F_116 ( V_6 -> V_14 [ 1 ] ) & V_192 ) ||
( V_6 -> V_21 && V_6 -> V_21 -> V_22 ) ) )
V_4 -> V_193 = true ;
#endif
F_27 ( V_6 , V_49 ) ;
F_3 ( V_23 , L_39 ) ;
V_67 = F_106 ( V_6 ) ;
if ( V_67 ) {
F_10 ( L_40 , V_67 ) ;
goto V_194;
}
F_3 ( V_23 , L_41 ) ;
return 0 ;
V_194:
F_113 ( & V_14 -> V_15 , NULL ) ;
F_113 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_85 ( V_6 -> V_14 [ 0 ] ) ;
F_85 ( V_6 ) ;
F_85 ( V_4 ) ;
return V_67 ;
}
static void F_117 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( V_23 , L_28 ) ;
F_3 ( V_23 , L_36 , V_14 -> V_185 ) ;
F_3 ( V_23 , L_37 , V_14 -> V_186 ) ;
F_3 ( V_23 , L_42 , V_14 -> V_187 ) ;
if ( V_14 -> V_187 != 1 )
return;
V_4 = F_2 ( & V_14 -> V_15 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_7 . V_8 ;
F_101 ( V_6 ) ;
F_113 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_113 ( & V_6 -> V_14 [ 2 ] -> V_15 , NULL ) ;
F_85 ( V_4 ) ;
F_85 ( V_6 -> V_14 [ 0 ] ) ;
F_85 ( V_6 ) ;
}
F_3 ( V_23 , L_29 ) ;
}
void F_118 ( struct V_186 * V_15 , bool V_195 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_23 , L_43 , V_195 ) ;
V_6 -> V_196 = V_195 ;
}
static int F_119 ( struct V_186 * V_15 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_7 V_197 ;
V_14 = F_120 ( V_15 , struct V_13 , V_15 ) ;
F_3 ( V_23 , L_44 , V_14 -> V_187 ) ;
if ( V_14 -> V_187 != V_36 )
return 0 ;
V_4 = F_2 ( V_15 ) ;
V_6 = V_4 -> V_7 . V_8 ;
F_86 ( V_6 ) ;
F_121 ( V_6 -> V_11 , 0 ) ;
if ( V_6 -> V_196 ) {
V_197 = V_191 ;
if ( V_6 -> V_21 -> V_22 )
F_14 ( V_6 -> V_21 -> V_24 ) ;
else
V_197 = V_192 ;
if ( F_122 ( V_6 -> V_14 [ 1 ] , V_197 ) )
F_10 ( L_45 , V_197 ) ;
}
return 0 ;
}
static int F_123 ( struct V_186 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
struct V_13 * V_14 = F_120 ( V_15 , struct V_13 , V_15 ) ;
F_3 ( V_23 , L_44 , V_14 -> V_187 ) ;
if ( V_14 -> V_187 != V_37 )
return 0 ;
F_91 ( V_6 ) ;
return 0 ;
}
static int T_8 F_124 ( struct V_198 * V_199 )
{
F_3 ( V_23 , L_28 ) ;
V_190 = F_125 ( & V_199 -> V_15 ) ;
if ( V_190 -> V_200 )
V_190 -> V_200 () ;
return 0 ;
}
static int F_126 ( struct V_198 * V_199 )
{
F_3 ( V_23 , L_28 ) ;
if ( V_190 -> V_201 )
V_190 -> V_201 () ;
F_127 ( & V_202 ) ;
return 0 ;
}
void F_128 ( void )
{
int V_16 ;
V_16 = F_129 ( & V_202 ) ;
if ( V_16 )
F_10 ( L_46 , V_16 ) ;
}
void F_130 ( void )
{
F_3 ( V_23 , L_28 ) ;
if ( V_190 )
F_131 ( & V_203 ) ;
else
F_127 ( & V_202 ) ;
}
void T_8 F_132 ( void )
{
int V_16 ;
F_3 ( V_23 , L_28 ) ;
V_16 = F_133 ( & V_203 , F_124 ) ;
if ( V_16 == - V_181 )
F_3 ( V_23 , L_47 ) ;
}
