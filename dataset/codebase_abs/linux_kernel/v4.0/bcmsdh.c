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
static inline int F_27 ( struct V_13 * V_14 ,
T_4 V_43 , T_2 V_44 )
{
int V_45 ;
if ( ( V_43 == V_46 ) ||
( V_43 == V_35 ) )
F_28 ( V_14 , V_44 , V_43 , & V_45 ) ;
else
F_29 ( V_14 , V_44 , V_43 , & V_45 ) ;
return V_45 ;
}
static int F_30 ( struct V_5 * V_6 , T_2 V_47 ,
T_3 V_18 , T_2 V_48 , void * V_17 , bool V_49 )
{
struct V_13 * V_14 ;
int V_16 ;
F_3 ( V_23 , L_8 ,
V_49 , V_47 , V_18 , V_48 ) ;
if ( F_31 ( V_48 > 1 && ! V_47 ) )
return - V_50 ;
V_14 = V_6 -> V_14 [ V_47 ] ;
switch ( V_48 ) {
case sizeof( T_2 ) :
if ( V_49 ) {
if ( V_47 )
F_28 ( V_14 , * ( T_2 * ) V_17 , V_18 , & V_16 ) ;
else
V_16 = F_27 ( V_14 , V_18 ,
* ( T_2 * ) V_17 ) ;
} else {
if ( V_47 )
* ( T_2 * ) V_17 = F_32 ( V_14 , V_18 , & V_16 ) ;
else
* ( T_2 * ) V_17 = F_33 ( V_14 , V_18 , & V_16 ) ;
}
break;
case sizeof( V_51 ) :
if ( V_49 )
F_34 ( V_14 , * ( V_51 * ) V_17 , V_18 , & V_16 ) ;
else
* ( V_51 * ) V_17 = F_35 ( V_14 , V_18 , & V_16 ) ;
break;
case sizeof( T_3 ) :
if ( V_49 )
F_36 ( V_14 , * ( T_3 * ) V_17 , V_18 , & V_16 ) ;
else
* ( T_3 * ) V_17 = F_37 ( V_14 , V_18 , & V_16 ) ;
break;
default:
F_10 ( L_9 , V_48 ) ;
break;
}
if ( V_16 )
F_3 ( V_23 , L_10 ,
V_49 ? L_11 : L_12 , V_47 , V_18 , V_16 ) ;
return V_16 ;
}
static void F_38 ( struct V_5 * V_6 )
{
V_6 -> V_52 = V_53 ;
F_39 ( V_6 -> V_4 , V_54 ) ;
}
static int F_40 ( struct V_5 * V_6 , T_3 V_18 ,
T_2 V_48 , void * V_17 , bool V_49 )
{
T_2 V_14 ;
T_5 V_55 = 0 ;
int V_16 ;
if ( V_6 -> V_52 == V_53 )
return - V_56 ;
if ( ( V_18 & ~ V_57 ) == 0 )
V_14 = V_58 ;
else
V_14 = V_36 ;
do {
if ( ! V_49 )
memset ( V_17 , 0 , V_48 ) ;
if ( V_55 )
F_41 ( 1000 , 2000 ) ;
V_16 = F_30 ( V_6 , V_14 , V_18 , V_48 ,
V_17 , V_49 ) ;
} while ( V_16 != 0 && V_16 != - V_56 &&
V_55 ++ < V_59 );
if ( V_16 == - V_56 )
F_38 ( V_6 ) ;
else if ( V_16 != 0 ) {
if ( V_18 != V_60 )
F_10 ( L_10 ,
V_49 ? L_11 : L_12 , V_14 , V_18 , V_16 ) ;
else
F_3 ( V_23 , L_10 ,
V_49 ? L_11 : L_12 , V_14 , V_18 , V_16 ) ;
}
return V_16 ;
}
static int
F_42 ( struct V_5 * V_6 , T_3 V_61 )
{
int V_62 = 0 , V_63 ;
T_2 V_18 [ 3 ] ;
if ( V_6 -> V_52 == V_53 )
return - V_56 ;
V_18 [ 0 ] = ( V_61 >> 8 ) & V_64 ;
V_18 [ 1 ] = ( V_61 >> 16 ) & V_65 ;
V_18 [ 2 ] = ( V_61 >> 24 ) & V_66 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
V_62 = F_40 ( V_6 ,
V_67 + V_63 ,
sizeof( T_2 ) , & V_18 [ V_63 ] , true ) ;
if ( V_62 ) {
F_10 ( L_13 ,
V_67 + V_63 ) ;
break;
}
}
return V_62 ;
}
static int
F_43 ( struct V_5 * V_6 , T_4 V_68 , T_3 * V_18 )
{
T_4 V_69 = * V_18 & ~ V_70 ;
int V_62 = 0 ;
if ( V_69 != V_6 -> V_71 ) {
V_62 = F_42 ( V_6 , V_69 ) ;
if ( V_62 )
return V_62 ;
V_6 -> V_71 = V_69 ;
}
* V_18 &= V_70 ;
if ( V_68 == 4 )
* V_18 |= V_72 ;
return 0 ;
}
T_2 F_20 ( struct V_5 * V_6 , T_3 V_18 , int * V_16 )
{
T_2 V_17 ;
int V_73 ;
F_3 ( V_23 , L_14 , V_18 ) ;
V_73 = F_40 ( V_6 , V_18 , sizeof( V_17 ) , & V_17 ,
false ) ;
F_3 ( V_23 , L_15 , V_17 ) ;
if ( V_16 )
* V_16 = V_73 ;
return V_17 ;
}
T_3 F_17 ( struct V_5 * V_6 , T_3 V_18 , int * V_16 )
{
T_3 V_17 ;
int V_73 ;
F_3 ( V_23 , L_14 , V_18 ) ;
V_73 = F_43 ( V_6 , sizeof( V_17 ) , & V_18 ) ;
if ( V_73 )
goto V_74;
V_73 = F_40 ( V_6 , V_18 , sizeof( V_17 ) , & V_17 ,
false ) ;
F_3 ( V_23 , L_16 , V_17 ) ;
V_74:
if ( V_16 )
* V_16 = V_73 ;
return V_17 ;
}
void F_19 ( struct V_5 * V_6 , T_3 V_18 ,
T_2 V_17 , int * V_16 )
{
int V_73 ;
F_3 ( V_23 , L_17 , V_18 , V_17 ) ;
V_73 = F_40 ( V_6 , V_18 , sizeof( V_17 ) , & V_17 ,
true ) ;
if ( V_16 )
* V_16 = V_73 ;
}
void F_18 ( struct V_5 * V_6 , T_3 V_18 ,
T_3 V_17 , int * V_16 )
{
int V_73 ;
F_3 ( V_23 , L_18 , V_18 , V_17 ) ;
V_73 = F_43 ( V_6 , sizeof( V_17 ) , & V_18 ) ;
if ( V_73 )
goto V_74;
V_73 = F_40 ( V_6 , V_18 , sizeof( V_17 ) , & V_17 ,
true ) ;
V_74:
if ( V_16 )
* V_16 = V_73 ;
}
static int F_44 ( struct V_5 * V_6 , T_4 V_47 ,
bool V_49 , T_3 V_18 , struct V_75 * V_76 )
{
unsigned int V_77 ;
int V_62 ;
V_77 = V_76 -> V_78 + 3 ;
V_77 &= ( T_4 ) ~ 3 ;
if ( V_49 )
V_62 = F_45 ( V_6 -> V_14 [ V_47 ] , V_18 ,
( ( T_2 * ) ( V_76 -> V_17 ) ) , V_77 ) ;
else if ( V_47 == 1 )
V_62 = F_46 ( V_6 -> V_14 [ V_47 ] , ( ( T_2 * ) ( V_76 -> V_17 ) ) ,
V_18 , V_77 ) ;
else
V_62 = F_47 ( V_6 -> V_14 [ V_47 ] , ( ( T_2 * ) ( V_76 -> V_17 ) ) , V_18 ,
V_77 ) ;
if ( V_62 == - V_56 )
F_38 ( V_6 ) ;
return V_62 ;
}
static int F_48 ( struct V_5 * V_6 , T_4 V_47 ,
bool V_49 , T_3 V_18 ,
struct V_79 * V_80 )
{
unsigned int V_77 , V_81 , V_82 , V_83 , V_84 ;
unsigned int V_85 , V_86 , V_87 ;
unsigned short V_88 , V_89 ;
unsigned char * V_90 , * V_91 , * V_92 ;
struct V_75 * V_93 = NULL , * V_94 ;
struct V_79 V_95 , * V_96 ;
struct V_97 V_98 ;
struct V_99 V_100 ;
struct V_101 V_102 ;
struct V_103 * V_104 ;
int V_16 = 0 ;
if ( ! V_80 -> V_105 )
return - V_50 ;
V_96 = V_80 ;
F_49 ( & V_95 ) ;
if ( V_6 -> V_21 && V_6 -> V_21 -> V_106 && ! V_49 ) {
V_77 = 0 ;
F_50 (pktlist, pkt_next)
V_77 += V_93 -> V_78 ;
V_77 = F_51 ( V_77 , V_6 -> V_14 [ V_47 ] -> V_107 ) ;
while ( V_77 > V_108 ) {
V_93 = F_52 ( V_108 ) ;
if ( V_93 == NULL ) {
V_16 = - V_109 ;
goto exit;
}
F_53 ( & V_95 , V_93 ) ;
V_77 -= V_108 ;
}
V_93 = F_52 ( V_77 ) ;
if ( V_93 == NULL ) {
V_16 = - V_109 ;
goto exit;
}
F_53 ( & V_95 , V_93 ) ;
V_96 = & V_95 ;
}
V_81 = V_6 -> V_14 [ V_47 ] -> V_107 ;
V_85 = V_6 -> V_110 ;
V_88 = F_54 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_89 = V_96 -> V_105 ;
V_84 = 0 ;
V_93 = V_96 -> V_111 ;
memset ( & V_98 , 0 , sizeof( struct V_97 ) ) ;
memset ( & V_100 , 0 , sizeof( struct V_99 ) ) ;
memset ( & V_102 , 0 , sizeof( struct V_101 ) ) ;
V_102 . V_112 = V_6 -> V_113 . V_104 ;
V_102 . V_114 = V_81 ;
V_102 . V_20 = V_49 ? V_115 : V_116 ;
V_100 . V_117 = V_118 ;
V_100 . V_119 = V_49 ? 1 << 31 : 0 ;
V_100 . V_119 |= ( V_47 & 0x7 ) << 28 ;
V_100 . V_119 |= 1 << 27 ;
V_100 . V_119 |= ( V_47 == 1 ) ? 1 << 26 : 0 ;
V_100 . V_20 = V_120 | V_121 | V_122 ;
V_98 . V_123 = & V_100 ;
V_98 . V_17 = & V_102 ;
while ( V_89 ) {
V_77 = 0 ;
V_82 = 0 ;
V_104 = V_6 -> V_113 . V_104 ;
while ( V_93 != (struct V_75 * ) V_96 ) {
V_90 = V_93 -> V_17 + V_84 ;
V_83 = V_93 -> V_78 - V_84 ;
if ( V_83 > V_6 -> V_124 )
V_83 = V_6 -> V_124 ;
if ( V_83 > V_85 - V_77 )
V_83 = V_85 - V_77 ;
F_55 ( V_104 , V_90 , V_83 ) ;
V_82 ++ ;
V_104 = F_56 ( V_104 ) ;
V_77 += V_83 ;
V_84 += V_83 ;
if ( V_84 == V_93 -> V_78 ) {
V_84 = 0 ;
V_93 = V_93 -> V_111 ;
}
if ( V_77 >= V_85 || V_82 >= V_88 )
break;
}
V_89 -= V_82 ;
if ( V_77 % V_81 != 0 ) {
F_10 ( L_19 ,
V_77 , V_81 ) ;
V_16 = - V_125 ;
goto exit;
}
V_102 . V_126 = V_82 ;
V_102 . V_127 = V_77 / V_81 ;
V_100 . V_119 |= ( V_18 & 0x1FFFF ) << 9 ;
V_100 . V_119 |= V_102 . V_127 & 0x1FF ;
if ( V_47 == 1 )
V_18 += V_77 ;
F_57 ( & V_102 , V_6 -> V_14 [ V_47 ] -> V_128 ) ;
F_58 ( V_6 -> V_14 [ V_47 ] -> V_128 -> V_129 , & V_98 ) ;
V_16 = V_100 . error ? V_100 . error : V_102 . error ;
if ( V_16 == - V_56 ) {
F_38 ( V_6 ) ;
break;
} else if ( V_16 != 0 ) {
F_10 ( L_20 ,
V_49 ? L_11 : L_12 , V_16 ) ;
V_16 = - V_130 ;
break;
}
}
if ( V_6 -> V_21 && V_6 -> V_21 -> V_106 && ! V_49 ) {
V_94 = V_95 . V_111 ;
V_86 = 0 ;
F_50 (pktlist, pkt_next) {
V_87 = 0 ;
do {
V_77 = V_94 -> V_78 - V_86 ;
V_77 = F_54 ( T_4 , V_93 -> V_78 - V_87 ,
V_77 ) ;
V_91 = V_94 -> V_17 + V_86 ;
V_92 = V_93 -> V_17 + V_87 ;
memcpy ( V_92 , V_91 , V_77 ) ;
V_86 += V_77 ;
V_87 += V_77 ;
if ( V_86 == V_94 -> V_78 ) {
V_86 = 0 ;
V_94 = V_94 -> V_111 ;
}
if ( V_87 == V_93 -> V_78 )
break;
} while ( ! F_59 ( & V_95 ) );
}
}
exit:
F_60 ( V_6 -> V_113 . V_104 , V_6 -> V_113 . V_131 ) ;
while ( ( V_93 = F_61 ( & V_95 ) ) != NULL )
F_62 ( V_93 ) ;
return V_16 ;
}
int F_63 ( struct V_5 * V_6 , T_2 * V_132 , T_4 V_133 )
{
struct V_75 * V_134 ;
int V_62 ;
V_134 = F_52 ( V_133 ) ;
if ( ! V_134 ) {
F_10 ( L_21 ,
V_133 ) ;
return - V_130 ;
}
V_62 = F_64 ( V_6 , V_134 ) ;
if ( ! V_62 )
memcpy ( V_132 , V_134 -> V_17 , V_133 ) ;
F_62 ( V_134 ) ;
return V_62 ;
}
int F_64 ( struct V_5 * V_6 , struct V_75 * V_76 )
{
T_3 V_18 = V_6 -> V_71 ;
int V_62 = 0 ;
F_3 ( V_23 , L_22 , V_18 , V_76 -> V_78 ) ;
V_62 = F_43 ( V_6 , 4 , & V_18 ) ;
if ( V_62 )
goto V_74;
V_62 = F_44 ( V_6 , V_37 , false , V_18 , V_76 ) ;
V_74:
return V_62 ;
}
int F_65 ( struct V_5 * V_6 ,
struct V_79 * V_135 , T_4 V_136 )
{
struct V_75 * V_137 ;
struct V_75 * V_138 ;
T_3 V_18 = V_6 -> V_71 ;
int V_62 = 0 ;
F_3 ( V_23 , L_22 ,
V_18 , V_135 -> V_105 ) ;
V_62 = F_43 ( V_6 , 4 , & V_18 ) ;
if ( V_62 )
goto V_74;
if ( V_135 -> V_105 == 1 )
V_62 = F_44 ( V_6 , V_37 , false , V_18 ,
V_135 -> V_111 ) ;
else if ( ! V_6 -> V_139 ) {
V_137 = F_52 ( V_136 ) ;
if ( ! V_137 )
return - V_109 ;
V_62 = F_44 ( V_6 , V_37 , false , V_18 ,
V_137 ) ;
if ( V_62 )
goto V_74;
F_50 (pktq, skb) {
memcpy ( V_138 -> V_17 , V_137 -> V_17 , V_138 -> V_78 ) ;
F_66 ( V_137 , V_138 -> V_78 ) ;
}
} else
V_62 = F_48 ( V_6 , V_37 , false , V_18 ,
V_135 ) ;
V_74:
return V_62 ;
}
int F_67 ( struct V_5 * V_6 , T_2 * V_132 , T_4 V_133 )
{
struct V_75 * V_134 ;
T_3 V_18 = V_6 -> V_71 ;
int V_62 ;
V_134 = F_52 ( V_133 ) ;
if ( ! V_134 ) {
F_10 ( L_21 ,
V_133 ) ;
return - V_130 ;
}
memcpy ( V_134 -> V_17 , V_132 , V_133 ) ;
V_62 = F_43 ( V_6 , 4 , & V_18 ) ;
if ( ! V_62 )
V_62 = F_44 ( V_6 , V_37 , true , V_18 ,
V_134 ) ;
F_62 ( V_134 ) ;
return V_62 ;
}
int F_68 ( struct V_5 * V_6 ,
struct V_79 * V_135 )
{
struct V_75 * V_138 ;
T_3 V_18 = V_6 -> V_71 ;
int V_62 ;
F_3 ( V_23 , L_22 , V_18 , V_135 -> V_105 ) ;
V_62 = F_43 ( V_6 , 4 , & V_18 ) ;
if ( V_62 )
return V_62 ;
if ( V_135 -> V_105 == 1 || ! V_6 -> V_139 )
F_50 (pktq, skb) {
V_62 = F_44 ( V_6 , V_37 , true ,
V_18 , V_138 ) ;
if ( V_62 )
break;
}
else
V_62 = F_48 ( V_6 , V_37 , true , V_18 ,
V_135 ) ;
return V_62 ;
}
int
F_69 ( struct V_5 * V_6 , bool V_49 , T_3 V_61 ,
T_2 * V_17 , T_4 V_140 )
{
int V_141 = 0 ;
struct V_75 * V_76 ;
T_3 V_142 ;
T_4 V_143 ;
V_143 = F_54 ( T_4 , V_144 , V_140 ) ;
V_76 = F_70 ( V_143 ) ;
if ( ! V_76 ) {
F_10 ( L_23 , V_143 ) ;
return - V_130 ;
}
V_76 -> V_145 = 0 ;
V_142 = V_61 & V_70 ;
if ( ( V_142 + V_140 ) & V_146 )
V_143 = ( V_144 - V_142 ) ;
else
V_143 = V_140 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_140 ) {
V_141 = F_42 ( V_6 , V_61 ) ;
if ( V_141 )
break;
F_3 ( V_23 , L_24 ,
V_49 ? L_11 : L_12 , V_143 ,
V_142 , V_61 & V_146 ) ;
V_142 &= V_70 ;
V_142 |= V_72 ;
F_71 ( V_76 , V_143 ) ;
if ( V_49 )
memcpy ( V_76 -> V_17 , V_17 , V_143 ) ;
V_141 = F_44 ( V_6 , V_36 , V_49 ,
V_142 , V_76 ) ;
if ( V_141 ) {
F_10 ( L_25 ) ;
break;
}
if ( ! V_49 )
memcpy ( V_17 , V_76 -> V_17 , V_143 ) ;
F_72 ( V_76 , 0 ) ;
V_140 -= V_143 ;
if ( V_140 ) {
V_17 += V_143 ;
V_61 += V_143 ;
V_142 = 0 ;
V_143 = F_54 ( T_4 , V_144 , V_140 ) ;
}
}
F_73 ( V_76 ) ;
if ( F_42 ( V_6 , V_6 -> V_71 ) )
F_10 ( L_26 ,
V_6 -> V_71 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
return V_141 ;
}
int F_74 ( struct V_5 * V_6 , T_4 V_47 )
{
char V_147 = ( char ) V_47 ;
F_3 ( V_23 , L_27 ) ;
F_30 ( V_6 , V_58 , V_46 ,
sizeof( V_147 ) , & V_147 , true ) ;
F_3 ( V_23 , L_28 ) ;
return 0 ;
}
static void F_75 ( struct V_5 * V_6 )
{
T_4 V_148 ;
int V_62 ;
if ( ! V_6 -> V_139 )
return;
V_148 = F_76 ( T_4 , V_149 , V_150 ) ;
V_148 += ( V_148 >> 4 ) + 1 ;
F_31 ( V_148 > V_6 -> V_151 ) ;
F_3 ( V_152 , L_29 , V_148 ) ;
V_62 = F_77 ( & V_6 -> V_113 , V_148 , V_153 ) ;
if ( V_62 < 0 ) {
F_10 ( L_30 ) ;
V_6 -> V_139 = false ;
}
V_6 -> V_154 = V_150 ;
}
static int F_78 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 ) {
F_79 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_15 ( V_6 -> V_14 [ 2 ] ) ;
F_80 ( V_6 -> V_14 [ 2 ] ) ;
F_21 ( V_6 -> V_14 [ 2 ] ) ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_80 ( V_6 -> V_14 [ 1 ] ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
F_81 ( & V_6 -> V_113 ) ;
V_6 -> V_71 = 0 ;
return 0 ;
}
static int F_82 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_155 * V_129 ;
T_4 V_156 ;
int V_16 = 0 ;
V_6 -> V_157 = 2 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
V_16 = F_83 ( V_6 -> V_14 [ 1 ] , V_158 ) ;
if ( V_16 ) {
F_10 ( L_31 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
goto V_159;
}
V_16 = F_83 ( V_6 -> V_14 [ 2 ] , V_160 ) ;
if ( V_16 ) {
F_10 ( L_32 ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
goto V_159;
}
V_6 -> V_14 [ 2 ] -> V_161 = V_162 ;
V_16 = F_84 ( V_6 -> V_14 [ 1 ] ) ;
F_21 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_16 ) {
F_10 ( L_33 , V_16 ) ;
goto V_159;
}
V_14 = V_6 -> V_14 [ 2 ] ;
V_129 = V_14 -> V_128 -> V_129 ;
V_6 -> V_139 = V_129 -> V_163 > 1 ;
V_156 = F_54 ( T_4 , V_129 -> V_164 , 511u ) ;
V_6 -> V_110 = F_54 ( T_4 , V_129 -> V_165 ,
V_156 * V_14 -> V_107 ) ;
V_6 -> V_151 = F_54 ( T_4 , V_129 -> V_163 ,
V_166 ) ;
V_6 -> V_124 = V_129 -> V_167 ;
F_75 ( V_6 ) ;
V_6 -> V_11 = F_85 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_16 = - V_168 ;
goto V_159;
}
V_159:
if ( V_16 )
F_78 ( V_6 ) ;
return V_16 ;
}
static int F_86 ( struct V_13 * V_14 ,
const struct V_169 * V_170 )
{
int V_62 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
F_3 ( V_23 , L_27 ) ;
F_3 ( V_23 , L_34 , V_14 -> V_171 ) ;
F_3 ( V_23 , L_35 , V_14 -> V_172 ) ;
F_3 ( V_23 , L_36 , V_14 -> V_173 ) ;
F_3 ( V_23 , L_37 , V_14 -> V_174 ) ;
if ( V_14 -> V_174 == 1 )
return 0 ;
if ( V_14 -> V_174 != 2 )
return - V_168 ;
V_4 = F_87 ( sizeof( struct V_3 ) , V_153 ) ;
if ( ! V_4 )
return - V_109 ;
V_6 = F_87 ( sizeof( struct V_5 ) , V_153 ) ;
if ( ! V_6 ) {
F_88 ( V_4 ) ;
return - V_109 ;
}
V_6 -> V_14 [ 0 ] = F_89 ( V_14 , sizeof( * V_14 ) , V_153 ) ;
V_6 -> V_14 [ 0 ] -> V_174 = 0 ;
V_6 -> V_14 [ 1 ] = V_14 -> V_128 -> V_13 [ 0 ] ;
V_6 -> V_14 [ 2 ] = V_14 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 . V_8 = V_6 ;
V_4 -> V_175 = V_176 ;
F_90 ( & V_14 -> V_15 , V_4 ) ;
F_90 ( & V_6 -> V_14 [ 1 ] -> V_15 , V_4 ) ;
V_6 -> V_15 = & V_6 -> V_14 [ 1 ] -> V_15 ;
V_6 -> V_21 = V_177 ;
if ( ! V_6 -> V_21 )
F_91 ( V_6 ) ;
#ifdef F_92
if ( ( F_93 ( V_6 -> V_14 [ 1 ] ) & V_178 ) &&
( ( F_93 ( V_6 -> V_14 [ 1 ] ) & V_179 ) ||
( V_6 -> V_21 && V_6 -> V_21 -> V_22 ) ) )
V_4 -> V_180 = true ;
#endif
V_6 -> V_181 = false ;
F_94 ( & V_6 -> V_182 , false ) ;
F_95 ( & V_6 -> V_183 ) ;
F_3 ( V_23 , L_38 ) ;
V_62 = F_82 ( V_6 ) ;
if ( V_62 ) {
F_10 ( L_39 , V_62 ) ;
goto V_184;
}
F_3 ( V_23 , L_40 ) ;
return 0 ;
V_184:
F_90 ( & V_14 -> V_15 , NULL ) ;
F_90 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_88 ( V_6 -> V_14 [ 0 ] ) ;
F_88 ( V_6 ) ;
F_88 ( V_4 ) ;
return V_62 ;
}
static void F_96 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( V_23 , L_27 ) ;
F_3 ( V_23 , L_35 , V_14 -> V_172 ) ;
F_3 ( V_23 , L_36 , V_14 -> V_173 ) ;
F_3 ( V_23 , L_41 , V_14 -> V_174 ) ;
if ( V_14 -> V_174 != 1 && V_14 -> V_174 != 2 )
return;
V_4 = F_2 ( & V_14 -> V_15 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_7 . V_8 ;
F_78 ( V_6 ) ;
F_90 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_90 ( & V_6 -> V_14 [ 2 ] -> V_15 , NULL ) ;
F_88 ( V_4 ) ;
F_88 ( V_6 -> V_14 [ 0 ] ) ;
F_88 ( V_6 ) ;
}
F_3 ( V_23 , L_28 ) ;
}
void F_97 ( struct V_173 * V_15 , bool V_185 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_23 , L_42 , V_185 ) ;
V_6 -> V_186 = V_185 ;
}
static int F_98 ( struct V_173 * V_15 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_6 V_187 ;
F_3 ( V_23 , L_27 ) ;
V_4 = F_2 ( V_15 ) ;
V_6 = V_4 -> V_7 . V_8 ;
if ( F_99 ( V_6 -> V_183 , V_6 -> V_181 ,
F_100 ( 3 * V_188 ) ) == 0 ) {
F_10 ( L_43 ) ;
return - V_189 ;
}
F_101 ( V_6 -> V_11 , 0 ) ;
F_94 ( & V_6 -> V_182 , true ) ;
if ( V_6 -> V_186 ) {
V_187 = V_178 ;
if ( V_6 -> V_21 -> V_22 )
F_14 ( V_6 -> V_21 -> V_24 ) ;
else
V_187 = V_179 ;
if ( F_102 ( V_6 -> V_14 [ 1 ] , V_187 ) )
F_10 ( L_44 , V_187 ) ;
}
return 0 ;
}
static int F_103 ( struct V_173 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_23 , L_27 ) ;
if ( V_6 -> V_21 && V_6 -> V_21 -> V_22 )
F_24 ( V_6 -> V_21 -> V_24 ) ;
F_101 ( V_6 -> V_11 , V_188 ) ;
F_94 ( & V_6 -> V_182 , false ) ;
return 0 ;
}
static int T_7 F_104 ( struct V_190 * V_191 )
{
F_3 ( V_23 , L_27 ) ;
V_177 = F_105 ( & V_191 -> V_15 ) ;
if ( V_177 -> V_192 )
V_177 -> V_192 () ;
return 0 ;
}
static int F_106 ( struct V_190 * V_191 )
{
F_3 ( V_23 , L_27 ) ;
if ( V_177 -> V_193 )
V_177 -> V_193 () ;
F_107 ( & V_194 ) ;
return 0 ;
}
void F_108 ( void )
{
int V_16 ;
V_16 = F_109 ( & V_194 ) ;
if ( V_16 )
F_10 ( L_45 , V_16 ) ;
}
void F_110 ( void )
{
F_3 ( V_23 , L_27 ) ;
if ( V_177 )
F_111 ( & V_195 ) ;
else
F_107 ( & V_194 ) ;
}
void T_7 F_112 ( void )
{
int V_16 ;
F_3 ( V_23 , L_27 ) ;
V_16 = F_113 ( & V_195 , F_104 ) ;
if ( V_16 == - V_168 )
F_3 ( V_23 , L_46 ) ;
}
