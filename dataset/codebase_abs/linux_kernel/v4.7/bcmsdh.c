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
}
return 0 ;
}
int F_23 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
F_3 ( V_25 , L_7 ) ;
V_17 = & V_6 -> V_23 -> V_11 . V_8 ;
if ( V_17 -> V_24 ) {
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_19 ( V_6 , V_44 , 0 , NULL ) ;
F_19 ( V_6 , V_37 , 0 , NULL ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_28 ) {
V_6 -> V_28 = false ;
if ( V_6 -> V_30 ) {
F_24 ( V_17 -> V_26 ) ;
V_6 -> V_30 = false ;
}
F_25 ( V_17 -> V_26 , & V_6 -> V_14 [ 1 ] -> V_15 ) ;
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
enum V_45 V_46 )
{
if ( V_6 -> V_46 == V_47 ||
V_46 == V_6 -> V_46 )
return;
F_3 ( V_48 , L_8 , V_6 -> V_46 , V_46 ) ;
switch ( V_6 -> V_46 ) {
case V_49 :
F_28 ( V_6 -> V_4 , V_50 ) ;
break;
case V_51 :
if ( V_46 == V_49 )
F_28 ( V_6 -> V_4 , V_52 ) ;
break;
default:
break;
}
V_6 -> V_46 = V_46 ;
}
static inline int F_29 ( struct V_13 * V_14 ,
T_4 V_53 , T_2 V_54 )
{
int V_55 ;
if ( ( V_53 == V_56 ) ||
( V_53 == V_37 ) )
F_30 ( V_14 , V_54 , V_53 , & V_55 ) ;
else
F_31 ( V_14 , V_54 , V_53 , & V_55 ) ;
return V_55 ;
}
static int F_32 ( struct V_5 * V_6 , T_2 V_57 ,
T_3 V_20 , T_2 V_58 , void * V_19 , bool V_59 )
{
struct V_13 * V_14 ;
int V_18 = - V_60 ;
F_3 ( V_25 , L_9 ,
V_59 , V_57 , V_20 , V_58 ) ;
if ( F_33 ( V_58 > 1 && ! V_57 ) )
return - V_60 ;
V_14 = V_6 -> V_14 [ V_57 ] ;
switch ( V_58 ) {
case sizeof( T_2 ) :
if ( V_59 ) {
if ( V_57 )
F_30 ( V_14 , * ( T_2 * ) V_19 , V_20 , & V_18 ) ;
else
V_18 = F_29 ( V_14 , V_20 ,
* ( T_2 * ) V_19 ) ;
} else {
if ( V_57 )
* ( T_2 * ) V_19 = F_34 ( V_14 , V_20 , & V_18 ) ;
else
* ( T_2 * ) V_19 = F_35 ( V_14 , V_20 , & V_18 ) ;
}
break;
case sizeof( V_61 ) :
if ( V_59 )
F_36 ( V_14 , * ( V_61 * ) V_19 , V_20 , & V_18 ) ;
else
* ( V_61 * ) V_19 = F_37 ( V_14 , V_20 , & V_18 ) ;
break;
case sizeof( T_3 ) :
if ( V_59 )
F_38 ( V_14 , * ( T_3 * ) V_19 , V_20 , & V_18 ) ;
else
* ( T_3 * ) V_19 = F_39 ( V_14 , V_20 , & V_18 ) ;
break;
default:
F_10 ( L_10 , V_58 ) ;
break;
}
if ( V_18 )
F_3 ( V_25 , L_11 ,
V_59 ? L_12 : L_13 , V_57 , V_20 , V_18 ) ;
return V_18 ;
}
static int F_40 ( struct V_5 * V_6 , T_3 V_20 ,
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
V_14 = V_38 ;
do {
if ( ! V_59 )
memset ( V_19 , 0 , V_58 ) ;
if ( V_62 )
F_41 ( 1000 , 2000 ) ;
V_18 = F_32 ( V_6 , V_14 , V_20 , V_58 ,
V_19 , V_59 ) ;
} while ( V_18 != 0 && V_18 != - V_63 &&
V_62 ++ < V_66 );
if ( V_18 == - V_63 )
F_27 ( V_6 , V_47 ) ;
else if ( V_18 != 0 ) {
if ( V_20 != V_67 )
F_10 ( L_11 ,
V_59 ? L_12 : L_13 , V_14 , V_20 , V_18 ) ;
else
F_3 ( V_25 , L_11 ,
V_59 ? L_12 : L_13 , V_14 , V_20 , V_18 ) ;
}
return V_18 ;
}
static int
F_42 ( struct V_5 * V_6 , T_3 V_68 )
{
int V_69 = 0 , V_70 ;
T_2 V_20 [ 3 ] ;
if ( V_6 -> V_46 == V_47 )
return - V_63 ;
V_20 [ 0 ] = ( V_68 >> 8 ) & V_71 ;
V_20 [ 1 ] = ( V_68 >> 16 ) & V_72 ;
V_20 [ 2 ] = ( V_68 >> 24 ) & V_73 ;
for ( V_70 = 0 ; V_70 < 3 ; V_70 ++ ) {
V_69 = F_40 ( V_6 ,
V_74 + V_70 ,
sizeof( T_2 ) , & V_20 [ V_70 ] , true ) ;
if ( V_69 ) {
F_10 ( L_14 ,
V_74 + V_70 ) ;
break;
}
}
return V_69 ;
}
static int
F_43 ( struct V_5 * V_6 , T_4 V_75 , T_3 * V_20 )
{
T_4 V_76 = * V_20 & ~ V_77 ;
int V_69 = 0 ;
if ( V_76 != V_6 -> V_78 ) {
V_69 = F_42 ( V_6 , V_76 ) ;
if ( V_69 )
return V_69 ;
V_6 -> V_78 = V_76 ;
}
* V_20 &= V_77 ;
if ( V_75 == 4 )
* V_20 |= V_79 ;
return 0 ;
}
T_2 F_20 ( struct V_5 * V_6 , T_3 V_20 , int * V_18 )
{
T_2 V_19 ;
int V_80 ;
F_3 ( V_25 , L_15 , V_20 ) ;
V_80 = F_40 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
false ) ;
F_3 ( V_25 , L_16 , V_19 ) ;
if ( V_18 )
* V_18 = V_80 ;
return V_19 ;
}
T_3 F_17 ( struct V_5 * V_6 , T_3 V_20 , int * V_18 )
{
T_3 V_19 ;
int V_80 ;
F_3 ( V_25 , L_15 , V_20 ) ;
V_80 = F_43 ( V_6 , sizeof( V_19 ) , & V_20 ) ;
if ( V_80 )
goto V_81;
V_80 = F_40 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
false ) ;
F_3 ( V_25 , L_17 , V_19 ) ;
V_81:
if ( V_18 )
* V_18 = V_80 ;
return V_19 ;
}
void F_19 ( struct V_5 * V_6 , T_3 V_20 ,
T_2 V_19 , int * V_18 )
{
int V_80 ;
F_3 ( V_25 , L_18 , V_20 , V_19 ) ;
V_80 = F_40 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
true ) ;
if ( V_18 )
* V_18 = V_80 ;
}
void F_18 ( struct V_5 * V_6 , T_3 V_20 ,
T_3 V_19 , int * V_18 )
{
int V_80 ;
F_3 ( V_25 , L_19 , V_20 , V_19 ) ;
V_80 = F_43 ( V_6 , sizeof( V_19 ) , & V_20 ) ;
if ( V_80 )
goto V_81;
V_80 = F_40 ( V_6 , V_20 , sizeof( V_19 ) , & V_19 ,
true ) ;
V_81:
if ( V_18 )
* V_18 = V_80 ;
}
static int F_44 ( struct V_5 * V_6 , T_4 V_57 ,
bool V_59 , T_3 V_20 , struct V_82 * V_83 )
{
unsigned int V_84 ;
int V_69 ;
V_84 = V_83 -> V_85 + 3 ;
V_84 &= ( T_4 ) ~ 3 ;
if ( V_59 )
V_69 = F_45 ( V_6 -> V_14 [ V_57 ] , V_20 ,
( ( T_2 * ) ( V_83 -> V_19 ) ) , V_84 ) ;
else if ( V_57 == 1 )
V_69 = F_46 ( V_6 -> V_14 [ V_57 ] , ( ( T_2 * ) ( V_83 -> V_19 ) ) ,
V_20 , V_84 ) ;
else
V_69 = F_47 ( V_6 -> V_14 [ V_57 ] , ( ( T_2 * ) ( V_83 -> V_19 ) ) , V_20 ,
V_84 ) ;
if ( V_69 == - V_63 )
F_27 ( V_6 , V_47 ) ;
return V_69 ;
}
static int F_48 ( struct V_5 * V_6 , T_4 V_57 ,
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
F_49 ( & V_102 ) ;
if ( ! V_59 && V_6 -> V_23 -> V_11 . V_8 . V_113 ) {
V_84 = 0 ;
F_50 (pktlist, pkt_next)
V_84 += V_100 -> V_85 ;
V_84 = F_51 ( V_84 , V_6 -> V_14 [ V_57 ] -> V_114 ) ;
while ( V_84 > V_115 ) {
V_100 = F_52 ( V_115 ) ;
if ( V_100 == NULL ) {
V_18 = - V_116 ;
goto exit;
}
F_53 ( & V_102 , V_100 ) ;
V_84 -= V_115 ;
}
V_100 = F_52 ( V_84 ) ;
if ( V_100 == NULL ) {
V_18 = - V_116 ;
goto exit;
}
F_53 ( & V_102 , V_100 ) ;
V_103 = & V_102 ;
}
V_88 = V_6 -> V_14 [ V_57 ] -> V_114 ;
V_92 = V_6 -> V_117 ;
V_95 = F_54 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_96 = V_103 -> V_112 ;
V_91 = 0 ;
V_100 = V_103 -> V_118 ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
memset ( & V_107 , 0 , sizeof( struct V_106 ) ) ;
memset ( & V_109 , 0 , sizeof( struct V_108 ) ) ;
V_109 . V_119 = V_6 -> V_120 . V_111 ;
V_109 . V_121 = V_88 ;
V_109 . V_22 = V_59 ? V_122 : V_123 ;
V_107 . V_124 = V_125 ;
V_107 . V_126 = V_59 ? 1 << 31 : 0 ;
V_107 . V_126 |= ( V_57 & 0x7 ) << 28 ;
V_107 . V_126 |= 1 << 27 ;
V_107 . V_126 |= ( V_57 == 1 ) ? 1 << 26 : 0 ;
V_107 . V_22 = V_127 | V_128 | V_129 ;
V_105 . V_130 = & V_107 ;
V_105 . V_19 = & V_109 ;
while ( V_96 ) {
V_84 = 0 ;
V_89 = 0 ;
V_111 = V_6 -> V_120 . V_111 ;
while ( V_100 != (struct V_82 * ) V_103 ) {
V_97 = V_100 -> V_19 + V_91 ;
V_90 = V_100 -> V_85 - V_91 ;
if ( V_90 > V_6 -> V_131 )
V_90 = V_6 -> V_131 ;
if ( V_90 > V_92 - V_84 )
V_90 = V_92 - V_84 ;
F_55 ( V_111 , V_97 , V_90 ) ;
V_89 ++ ;
V_111 = F_56 ( V_111 ) ;
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
F_10 ( L_20 ,
V_84 , V_88 ) ;
V_18 = - V_132 ;
goto exit;
}
V_109 . V_133 = V_89 ;
V_109 . V_134 = V_84 / V_88 ;
V_107 . V_126 |= ( V_20 & 0x1FFFF ) << 9 ;
V_107 . V_126 |= V_109 . V_134 & 0x1FF ;
if ( V_57 == 1 )
V_20 += V_84 ;
F_57 ( & V_109 , V_6 -> V_14 [ V_57 ] -> V_135 ) ;
F_58 ( V_6 -> V_14 [ V_57 ] -> V_135 -> V_136 , & V_105 ) ;
V_18 = V_107 . error ? V_107 . error : V_109 . error ;
if ( V_18 == - V_63 ) {
F_27 ( V_6 , V_47 ) ;
break;
} else if ( V_18 != 0 ) {
F_10 ( L_21 ,
V_59 ? L_12 : L_13 , V_18 ) ;
V_18 = - V_137 ;
break;
}
}
if ( ! V_59 && V_6 -> V_23 -> V_11 . V_8 . V_113 ) {
V_101 = V_102 . V_118 ;
V_93 = 0 ;
F_50 (pktlist, pkt_next) {
V_94 = 0 ;
do {
V_84 = V_101 -> V_85 - V_93 ;
V_84 = F_54 ( T_4 , V_100 -> V_85 - V_94 ,
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
} while ( ! F_59 ( & V_102 ) );
}
}
exit:
F_60 ( V_6 -> V_120 . V_111 , V_6 -> V_120 . V_138 ) ;
while ( ( V_100 = F_61 ( & V_102 ) ) != NULL )
F_62 ( V_100 ) ;
return V_18 ;
}
int F_63 ( struct V_5 * V_6 , T_2 * V_139 , T_4 V_140 )
{
struct V_82 * V_141 ;
int V_69 ;
V_141 = F_52 ( V_140 ) ;
if ( ! V_141 ) {
F_10 ( L_22 ,
V_140 ) ;
return - V_137 ;
}
V_69 = F_64 ( V_6 , V_141 ) ;
if ( ! V_69 )
memcpy ( V_139 , V_141 -> V_19 , V_140 ) ;
F_62 ( V_141 ) ;
return V_69 ;
}
int F_64 ( struct V_5 * V_6 , struct V_82 * V_83 )
{
T_3 V_20 = V_6 -> V_78 ;
int V_69 = 0 ;
F_3 ( V_25 , L_23 , V_20 , V_83 -> V_85 ) ;
V_69 = F_43 ( V_6 , 4 , & V_20 ) ;
if ( V_69 )
goto V_81;
V_69 = F_44 ( V_6 , V_39 , false , V_20 , V_83 ) ;
V_81:
return V_69 ;
}
int F_65 ( struct V_5 * V_6 ,
struct V_86 * V_142 , T_4 V_143 )
{
struct V_82 * V_144 ;
struct V_82 * V_145 ;
T_3 V_20 = V_6 -> V_78 ;
int V_69 = 0 ;
F_3 ( V_25 , L_23 ,
V_20 , V_142 -> V_112 ) ;
V_69 = F_43 ( V_6 , 4 , & V_20 ) ;
if ( V_69 )
goto V_81;
if ( V_142 -> V_112 == 1 )
V_69 = F_44 ( V_6 , V_39 , false , V_20 ,
V_142 -> V_118 ) ;
else if ( ! V_6 -> V_146 ) {
V_144 = F_52 ( V_143 ) ;
if ( ! V_144 )
return - V_116 ;
V_69 = F_44 ( V_6 , V_39 , false , V_20 ,
V_144 ) ;
if ( V_69 )
goto V_81;
F_50 (pktq, skb) {
memcpy ( V_145 -> V_19 , V_144 -> V_19 , V_145 -> V_85 ) ;
F_66 ( V_144 , V_145 -> V_85 ) ;
}
} else
V_69 = F_48 ( V_6 , V_39 , false , V_20 ,
V_142 ) ;
V_81:
return V_69 ;
}
int F_67 ( struct V_5 * V_6 , T_2 * V_139 , T_4 V_140 )
{
struct V_82 * V_141 ;
T_3 V_20 = V_6 -> V_78 ;
int V_69 ;
V_141 = F_52 ( V_140 ) ;
if ( ! V_141 ) {
F_10 ( L_22 ,
V_140 ) ;
return - V_137 ;
}
memcpy ( V_141 -> V_19 , V_139 , V_140 ) ;
V_69 = F_43 ( V_6 , 4 , & V_20 ) ;
if ( ! V_69 )
V_69 = F_44 ( V_6 , V_39 , true , V_20 ,
V_141 ) ;
F_62 ( V_141 ) ;
return V_69 ;
}
int F_68 ( struct V_5 * V_6 ,
struct V_86 * V_142 )
{
struct V_82 * V_145 ;
T_3 V_20 = V_6 -> V_78 ;
int V_69 ;
F_3 ( V_25 , L_23 , V_20 , V_142 -> V_112 ) ;
V_69 = F_43 ( V_6 , 4 , & V_20 ) ;
if ( V_69 )
return V_69 ;
if ( V_142 -> V_112 == 1 || ! V_6 -> V_146 )
F_50 (pktq, skb) {
V_69 = F_44 ( V_6 , V_39 , true ,
V_20 , V_145 ) ;
if ( V_69 )
break;
}
else
V_69 = F_48 ( V_6 , V_39 , true , V_20 ,
V_142 ) ;
return V_69 ;
}
int
F_69 ( struct V_5 * V_6 , bool V_59 , T_3 V_68 ,
T_2 * V_19 , T_4 V_147 )
{
int V_148 = 0 ;
struct V_82 * V_83 ;
T_3 V_149 ;
T_4 V_150 ;
V_150 = F_54 ( T_4 , V_151 , V_147 ) ;
V_83 = F_70 ( V_150 ) ;
if ( ! V_83 ) {
F_10 ( L_24 , V_150 ) ;
return - V_137 ;
}
V_83 -> V_152 = 0 ;
V_149 = V_68 & V_77 ;
if ( ( V_149 + V_147 ) & V_153 )
V_150 = ( V_151 - V_149 ) ;
else
V_150 = V_147 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_147 ) {
V_148 = F_42 ( V_6 , V_68 ) ;
if ( V_148 )
break;
F_3 ( V_25 , L_25 ,
V_59 ? L_12 : L_13 , V_150 ,
V_149 , V_68 & V_153 ) ;
V_149 &= V_77 ;
V_149 |= V_79 ;
F_71 ( V_83 , V_150 ) ;
if ( V_59 )
memcpy ( V_83 -> V_19 , V_19 , V_150 ) ;
V_148 = F_44 ( V_6 , V_38 , V_59 ,
V_149 , V_83 ) ;
if ( V_148 ) {
F_10 ( L_26 ) ;
break;
}
if ( ! V_59 )
memcpy ( V_19 , V_83 -> V_19 , V_150 ) ;
F_72 ( V_83 , 0 ) ;
V_147 -= V_150 ;
if ( V_147 ) {
V_19 += V_150 ;
V_68 += V_150 ;
V_149 = 0 ;
V_150 = F_54 ( T_4 , V_151 , V_147 ) ;
}
}
F_73 ( V_83 ) ;
if ( F_42 ( V_6 , V_6 -> V_78 ) )
F_10 ( L_27 ,
V_6 -> V_78 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
return V_148 ;
}
int F_74 ( struct V_5 * V_6 , T_4 V_57 )
{
char V_154 = ( char ) V_57 ;
F_3 ( V_25 , L_28 ) ;
F_32 ( V_6 , V_65 , V_56 ,
sizeof( V_154 ) , & V_154 , true ) ;
F_3 ( V_25 , L_29 ) ;
return 0 ;
}
void F_75 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_155 * V_136 ;
T_4 V_156 ;
T_4 V_157 ;
int V_69 ;
V_14 = V_6 -> V_14 [ 2 ] ;
V_136 = V_14 -> V_135 -> V_136 ;
V_6 -> V_146 = V_136 -> V_158 > 1 ;
V_156 = F_54 ( T_4 , V_136 -> V_159 , 511u ) ;
V_6 -> V_117 = F_54 ( T_4 , V_136 -> V_160 ,
V_156 * V_14 -> V_114 ) ;
V_6 -> V_161 = F_54 ( T_4 , V_136 -> V_158 ,
V_162 ) ;
V_6 -> V_131 = V_136 -> V_163 ;
if ( ! V_6 -> V_146 )
return;
V_157 = F_76 ( T_4 , V_164 ,
V_6 -> V_23 -> V_11 . V_8 . V_165 ) ;
V_157 += ( V_157 >> 4 ) + 1 ;
F_33 ( V_157 > V_6 -> V_161 ) ;
F_3 ( V_48 , L_30 , V_157 ) ;
V_69 = F_77 ( & V_6 -> V_120 , V_157 , V_166 ) ;
if ( V_69 < 0 ) {
F_10 ( L_31 ) ;
V_6 -> V_146 = false ;
}
V_6 -> V_165 = V_6 -> V_23 -> V_11 . V_8 . V_165 ;
}
static int F_78 ( struct V_5 * V_6 )
{
V_6 -> V_167 = F_79 ( sizeof( * V_6 -> V_167 ) , V_166 ) ;
if ( ! V_6 -> V_167 )
return - V_116 ;
F_80 ( & V_6 -> V_167 -> V_168 , 0 ) ;
F_80 ( & V_6 -> V_167 -> V_169 , 0 ) ;
F_81 ( & V_6 -> V_167 -> V_170 ) ;
F_82 ( & V_6 -> V_167 -> V_171 ) ;
return 0 ;
}
static void F_83 ( struct V_5 * V_6 )
{
if ( V_6 -> V_167 ) {
F_33 ( F_84 ( & V_6 -> V_167 -> V_169 ) ) ;
F_85 ( V_6 -> V_167 ) ;
}
}
static int F_86 ( struct V_5 * V_6 )
{
T_6 * V_172 = & V_6 -> V_167 -> V_168 ;
int V_173 = 0 ;
V_6 -> V_167 -> V_174 = 0 ;
F_87 ( & V_6 -> V_167 -> V_171 ) ;
F_80 ( & V_6 -> V_167 -> V_169 , 1 ) ;
F_88 ( V_6 -> V_11 ) ;
F_89 ( V_6 -> V_167 -> V_170 ,
F_84 ( V_172 ) == V_6 -> V_167 -> V_174 ) ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
V_173 = F_90 ( V_6 -> V_11 , true ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
return V_173 ;
}
static void F_91 ( struct V_5 * V_6 )
{
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_90 ( V_6 -> V_11 , false ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
F_80 ( & V_6 -> V_167 -> V_169 , 0 ) ;
F_92 ( & V_6 -> V_167 -> V_171 ) ;
}
bool F_93 ( struct V_5 * V_6 )
{
return F_84 ( & V_6 -> V_167 -> V_169 ) ;
}
void F_94 ( struct V_5 * V_6 )
{
if ( ! F_93 ( V_6 ) )
return;
V_6 -> V_167 -> V_174 ++ ;
F_95 ( & V_6 -> V_167 -> V_170 ) ;
F_96 ( & V_6 -> V_167 -> V_171 ) ;
}
void F_97 ( struct V_5 * V_6 )
{
F_98 ( & V_6 -> V_167 -> V_168 ) ;
}
void F_99 ( struct V_5 * V_6 )
{
F_100 ( & V_6 -> V_167 -> V_168 ) ;
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
V_6 -> V_46 = V_51 ;
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
F_104 ( & V_6 -> V_120 ) ;
V_6 -> V_78 = 0 ;
F_105 ( V_6 -> V_14 [ 1 ] -> V_135 -> V_136 -> V_175 ) ;
return 0 ;
}
static void F_106 ( struct V_155 * V_136 )
{
F_107 ( V_136 -> V_175 ) ;
V_136 -> V_176 |= V_177 ;
}
static int F_108 ( struct V_5 * V_6 )
{
int V_18 = 0 ;
V_6 -> V_178 = 2 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
V_18 = F_109 ( V_6 -> V_14 [ 1 ] , V_179 ) ;
if ( V_18 ) {
F_10 ( L_32 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
goto V_180;
}
V_18 = F_109 ( V_6 -> V_14 [ 2 ] , V_181 ) ;
if ( V_18 ) {
F_10 ( L_33 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
goto V_180;
}
V_6 -> V_14 [ 2 ] -> V_182 = V_183 ;
V_18 = F_110 ( V_6 -> V_14 [ 1 ] ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_18 ) {
F_10 ( L_34 , V_18 ) ;
goto V_180;
}
V_18 = F_78 ( V_6 ) ;
if ( V_18 )
goto V_180;
V_6 -> V_11 = F_111 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_18 = - V_184 ;
goto V_180;
}
F_106 ( V_6 -> V_14 [ 2 ] -> V_135 -> V_136 ) ;
V_180:
if ( V_18 )
F_101 ( V_6 ) ;
return V_18 ;
}
static void F_112 ( struct V_185 * V_15 ,
int V_186 )
{
#if F_113 ( V_187 )
struct V_188 * V_189 ;
V_189 = F_114 ( V_15 ) ;
if ( V_189 )
V_189 -> V_22 . V_190 = 0 ;
#endif
}
static int F_115 ( struct V_13 * V_14 ,
const struct V_191 * V_192 )
{
int V_69 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_185 * V_15 ;
F_3 ( V_25 , L_28 ) ;
F_3 ( V_25 , L_35 , V_14 -> V_193 ) ;
F_3 ( V_25 , L_36 , V_14 -> V_194 ) ;
F_3 ( V_25 , L_37 , V_14 -> V_185 ) ;
F_3 ( V_25 , L_38 , V_14 -> V_195 ) ;
V_15 = & V_14 -> V_15 ;
F_112 ( V_15 , 0 ) ;
if ( V_14 -> V_195 == 1 )
return 0 ;
if ( V_14 -> V_195 != 2 )
return - V_184 ;
V_4 = F_79 ( sizeof( struct V_3 ) , V_166 ) ;
if ( ! V_4 )
return - V_116 ;
V_6 = F_79 ( sizeof( struct V_5 ) , V_166 ) ;
if ( ! V_6 ) {
F_85 ( V_4 ) ;
return - V_116 ;
}
V_6 -> V_14 [ 0 ] = F_116 ( V_14 , sizeof( * V_14 ) , V_166 ) ;
V_6 -> V_14 [ 0 ] -> V_195 = 0 ;
V_6 -> V_14 [ 1 ] = V_14 -> V_135 -> V_13 [ 0 ] ;
V_6 -> V_14 [ 2 ] = V_14 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 . V_8 = V_6 ;
V_4 -> V_196 = V_197 ;
F_117 ( & V_14 -> V_15 , V_4 ) ;
F_117 ( & V_6 -> V_14 [ 1 ] -> V_15 , V_4 ) ;
V_6 -> V_15 = & V_6 -> V_14 [ 1 ] -> V_15 ;
F_27 ( V_6 , V_51 ) ;
F_3 ( V_25 , L_39 ) ;
V_69 = F_108 ( V_6 ) ;
if ( V_69 ) {
F_10 ( L_40 , V_69 ) ;
goto V_198;
}
F_3 ( V_25 , L_41 ) ;
return 0 ;
V_198:
F_117 ( & V_14 -> V_15 , NULL ) ;
F_117 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_85 ( V_6 -> V_14 [ 0 ] ) ;
F_85 ( V_6 ) ;
F_85 ( V_4 ) ;
return V_69 ;
}
static void F_118 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( V_25 , L_28 ) ;
F_3 ( V_25 , L_36 , V_14 -> V_194 ) ;
F_3 ( V_25 , L_37 , V_14 -> V_185 ) ;
F_3 ( V_25 , L_42 , V_14 -> V_195 ) ;
if ( V_14 -> V_195 != 1 )
return;
V_4 = F_2 ( & V_14 -> V_15 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_7 . V_8 ;
F_101 ( V_6 ) ;
F_117 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_117 ( & V_6 -> V_14 [ 2 ] -> V_15 , NULL ) ;
F_85 ( V_4 ) ;
F_85 ( V_6 -> V_14 [ 0 ] ) ;
F_85 ( V_6 ) ;
}
F_3 ( V_25 , L_29 ) ;
}
void F_119 ( struct V_185 * V_15 , bool V_199 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_25 , L_43 , V_199 ) ;
V_6 -> V_200 = V_199 ;
}
static int F_120 ( struct V_185 * V_15 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_7 V_201 ;
V_14 = F_121 ( V_15 , struct V_13 , V_15 ) ;
F_3 ( V_25 , L_44 , V_14 -> V_195 ) ;
if ( V_14 -> V_195 != V_38 )
return 0 ;
V_4 = F_2 ( V_15 ) ;
V_6 = V_4 -> V_7 . V_8 ;
F_86 ( V_6 ) ;
F_122 ( V_6 -> V_11 , 0 ) ;
V_201 = V_202 ;
if ( V_6 -> V_200 ) {
if ( V_6 -> V_23 -> V_11 . V_8 . V_24 )
F_14 ( V_6 -> V_23 -> V_11 . V_8 . V_26 ) ;
else
V_201 |= V_203 ;
}
if ( F_123 ( V_6 -> V_14 [ 1 ] , V_201 ) )
F_10 ( L_45 , V_201 ) ;
return 0 ;
}
static int F_124 ( struct V_185 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
struct V_13 * V_14 = F_121 ( V_15 , struct V_13 , V_15 ) ;
F_3 ( V_25 , L_44 , V_14 -> V_195 ) ;
if ( V_14 -> V_195 != V_39 )
return 0 ;
F_91 ( V_6 ) ;
return 0 ;
}
void F_125 ( void )
{
int V_18 ;
V_18 = F_126 ( & V_204 ) ;
if ( V_18 )
F_10 ( L_46 , V_18 ) ;
}
void F_127 ( void )
{
F_3 ( V_25 , L_28 ) ;
F_128 ( & V_204 ) ;
}
