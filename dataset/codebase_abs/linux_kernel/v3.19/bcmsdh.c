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
static bool F_8 ( struct V_5 * V_6 )
{
bool V_16 = false ;
#ifdef F_9
V_16 = F_10 ( & V_6 -> V_17 ) ;
#endif
return V_16 ;
}
static void F_11 ( struct V_5 * V_6 ,
T_2 * V_18 )
{
#ifdef F_9
int V_19 = 0 ;
while ( F_10 ( & V_6 -> V_17 ) && V_19 ++ != 30 )
F_12 ( * V_18 , false , V_20 / 100 ) ;
#endif
}
int F_13 ( struct V_5 * V_6 )
{
int V_21 = 0 ;
T_3 V_22 ;
T_4 V_23 , V_24 ;
unsigned long V_25 ;
if ( ( V_6 -> V_26 ) && ( V_6 -> V_26 -> V_27 ) ) {
F_3 ( V_28 , L_3 ,
V_6 -> V_26 -> V_29 ) ;
V_21 = F_14 ( V_6 -> V_26 -> V_29 ,
F_1 ,
V_6 -> V_26 -> V_30 ,
L_4 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
if ( V_21 != 0 ) {
F_15 ( L_5 , V_21 ) ;
return V_21 ;
}
V_6 -> V_31 = true ;
F_16 ( & V_6 -> V_32 ) ;
F_17 ( & V_6 -> V_32 , V_25 ) ;
V_6 -> V_10 = true ;
F_18 ( & V_6 -> V_32 , V_25 ) ;
V_21 = F_19 ( V_6 -> V_26 -> V_29 ) ;
if ( V_21 != 0 ) {
F_15 ( L_6 , V_21 ) ;
return V_21 ;
}
V_6 -> V_33 = true ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_4 -> V_34 == V_35 ) {
V_23 = F_21 ( V_36 , V_24 ) ;
V_24 = F_22 ( V_6 , V_23 , & V_21 ) ;
V_24 |= 0x2 ;
F_23 ( V_6 , V_23 , V_24 , & V_21 ) ;
F_24 ( V_6 , V_37 , 0xf ,
& V_21 ) ;
F_24 ( V_6 , V_38 , 0 , & V_21 ) ;
F_24 ( V_6 , V_39 , 0x2 , & V_21 ) ;
}
V_22 = F_25 ( V_6 , V_40 , & V_21 ) ;
V_22 |= 1 << V_41 | 1 << V_42 | 1 ;
F_24 ( V_6 , V_40 , V_22 , & V_21 ) ;
V_22 = V_43 | V_44 ;
if ( V_6 -> V_26 -> V_30 & V_45 )
V_22 |= V_46 ;
F_24 ( V_6 , V_47 , V_22 , & V_21 ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
} else {
F_3 ( V_28 , L_7 ) ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_27 ( V_6 -> V_14 [ 1 ] , F_6 ) ;
F_27 ( V_6 -> V_14 [ 2 ] , F_7 ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
}
return 0 ;
}
int F_28 ( struct V_5 * V_6 )
{
F_3 ( V_28 , L_7 ) ;
if ( ( V_6 -> V_26 ) && ( V_6 -> V_26 -> V_27 ) ) {
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_24 ( V_6 , V_47 , 0 , NULL ) ;
F_24 ( V_6 , V_40 , 0 , NULL ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_31 ) {
V_6 -> V_31 = false ;
if ( V_6 -> V_33 ) {
F_29 ( V_6 -> V_26 -> V_29 ) ;
V_6 -> V_33 = false ;
}
F_30 ( V_6 -> V_26 -> V_29 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
V_6 -> V_10 = false ;
}
} else {
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_31 ( V_6 -> V_14 [ 2 ] ) ;
F_31 ( V_6 -> V_14 [ 1 ] ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
}
return 0 ;
}
static inline int F_32 ( struct V_13 * V_14 ,
T_5 V_48 , T_3 V_49 )
{
int V_50 ;
if ( ( V_48 == V_51 ) ||
( V_48 == V_40 ) )
F_33 ( V_14 , V_49 , V_48 , & V_50 ) ;
else
F_34 ( V_14 , V_49 , V_48 , & V_50 ) ;
return V_50 ;
}
static int F_35 ( struct V_5 * V_6 , T_3 V_52 ,
T_4 V_23 , T_3 V_53 , void * V_22 , bool V_54 )
{
struct V_13 * V_14 ;
int V_21 ;
F_3 ( V_28 , L_8 ,
V_54 , V_52 , V_23 , V_53 ) ;
F_11 ( V_6 , & V_6 -> V_55 ) ;
if ( F_8 ( V_6 ) )
return - V_56 ;
if ( F_36 ( V_53 > 1 && ! V_52 ) )
return - V_57 ;
V_14 = V_6 -> V_14 [ V_52 ] ;
switch ( V_53 ) {
case sizeof( T_3 ) :
if ( V_54 ) {
if ( V_52 )
F_33 ( V_14 , * ( T_3 * ) V_22 , V_23 , & V_21 ) ;
else
V_21 = F_32 ( V_14 , V_23 ,
* ( T_3 * ) V_22 ) ;
} else {
if ( V_52 )
* ( T_3 * ) V_22 = F_37 ( V_14 , V_23 , & V_21 ) ;
else
* ( T_3 * ) V_22 = F_38 ( V_14 , V_23 , & V_21 ) ;
}
break;
case sizeof( V_58 ) :
if ( V_54 )
F_39 ( V_14 , * ( V_58 * ) V_22 , V_23 , & V_21 ) ;
else
* ( V_58 * ) V_22 = F_40 ( V_14 , V_23 , & V_21 ) ;
break;
case sizeof( T_4 ) :
if ( V_54 )
F_41 ( V_14 , * ( T_4 * ) V_22 , V_23 , & V_21 ) ;
else
* ( T_4 * ) V_22 = F_42 ( V_14 , V_23 , & V_21 ) ;
break;
default:
F_15 ( L_9 , V_53 ) ;
break;
}
if ( V_21 )
F_3 ( V_28 , L_10 ,
V_54 ? L_11 : L_12 , V_52 , V_23 , V_21 ) ;
return V_21 ;
}
static int F_43 ( struct V_5 * V_6 , T_4 V_23 ,
T_3 V_53 , void * V_22 , bool V_54 )
{
T_3 V_14 ;
T_6 V_19 = 0 ;
int V_21 ;
if ( V_6 -> V_4 -> V_59 == V_60 )
return - V_61 ;
if ( ( V_23 & ~ V_62 ) == 0 )
V_14 = V_63 ;
else
V_14 = V_41 ;
do {
if ( ! V_54 )
memset ( V_22 , 0 , V_53 ) ;
if ( V_19 )
F_44 ( 1000 , 2000 ) ;
V_21 = F_35 ( V_6 , V_14 , V_23 , V_53 ,
V_22 , V_54 ) ;
} while ( V_21 != 0 && V_21 != - V_61 &&
V_19 ++ < V_64 );
if ( V_21 == - V_61 )
F_45 ( V_6 -> V_4 , V_60 ) ;
else if ( V_21 != 0 ) {
if ( V_23 != V_65 )
F_15 ( L_10 ,
V_54 ? L_11 : L_12 , V_14 , V_23 , V_21 ) ;
else
F_3 ( V_28 , L_10 ,
V_54 ? L_11 : L_12 , V_14 , V_23 , V_21 ) ;
}
return V_21 ;
}
static int
F_46 ( struct V_5 * V_6 , T_4 V_66 )
{
int V_67 = 0 , V_68 ;
T_3 V_23 [ 3 ] ;
if ( V_6 -> V_4 -> V_59 == V_60 )
return - V_61 ;
V_23 [ 0 ] = ( V_66 >> 8 ) & V_69 ;
V_23 [ 1 ] = ( V_66 >> 16 ) & V_70 ;
V_23 [ 2 ] = ( V_66 >> 24 ) & V_71 ;
for ( V_68 = 0 ; V_68 < 3 ; V_68 ++ ) {
V_67 = F_43 ( V_6 ,
V_72 + V_68 ,
sizeof( T_3 ) , & V_23 [ V_68 ] , true ) ;
if ( V_67 ) {
F_15 ( L_13 ,
V_72 + V_68 ) ;
break;
}
}
return V_67 ;
}
static int
F_47 ( struct V_5 * V_6 , T_5 V_73 , T_4 * V_23 )
{
T_5 V_74 = * V_23 & ~ V_75 ;
int V_67 = 0 ;
if ( V_74 != V_6 -> V_76 ) {
V_67 = F_46 ( V_6 , V_74 ) ;
if ( V_67 )
return V_67 ;
V_6 -> V_76 = V_74 ;
}
* V_23 &= V_75 ;
if ( V_73 == 4 )
* V_23 |= V_77 ;
return 0 ;
}
T_3 F_25 ( struct V_5 * V_6 , T_4 V_23 , int * V_21 )
{
T_3 V_22 ;
int V_78 ;
F_3 ( V_28 , L_14 , V_23 ) ;
V_78 = F_43 ( V_6 , V_23 , sizeof( V_22 ) , & V_22 ,
false ) ;
F_3 ( V_28 , L_15 , V_22 ) ;
if ( V_21 )
* V_21 = V_78 ;
return V_22 ;
}
T_4 F_22 ( struct V_5 * V_6 , T_4 V_23 , int * V_21 )
{
T_4 V_22 ;
int V_78 ;
F_3 ( V_28 , L_14 , V_23 ) ;
V_78 = F_47 ( V_6 , sizeof( V_22 ) , & V_23 ) ;
if ( V_78 )
goto V_79;
V_78 = F_43 ( V_6 , V_23 , sizeof( V_22 ) , & V_22 ,
false ) ;
F_3 ( V_28 , L_16 , V_22 ) ;
V_79:
if ( V_21 )
* V_21 = V_78 ;
return V_22 ;
}
void F_24 ( struct V_5 * V_6 , T_4 V_23 ,
T_3 V_22 , int * V_21 )
{
int V_78 ;
F_3 ( V_28 , L_17 , V_23 , V_22 ) ;
V_78 = F_43 ( V_6 , V_23 , sizeof( V_22 ) , & V_22 ,
true ) ;
if ( V_21 )
* V_21 = V_78 ;
}
void F_23 ( struct V_5 * V_6 , T_4 V_23 ,
T_4 V_22 , int * V_21 )
{
int V_78 ;
F_3 ( V_28 , L_18 , V_23 , V_22 ) ;
V_78 = F_47 ( V_6 , sizeof( V_22 ) , & V_23 ) ;
if ( V_78 )
goto V_79;
V_78 = F_43 ( V_6 , V_23 , sizeof( V_22 ) , & V_22 ,
true ) ;
V_79:
if ( V_21 )
* V_21 = V_78 ;
}
static int F_48 ( struct V_5 * V_6 , T_5 V_52 ,
bool V_54 , T_4 V_23 , struct V_80 * V_81 )
{
unsigned int V_82 ;
int V_67 ;
F_11 ( V_6 , & V_6 -> V_83 ) ;
if ( F_8 ( V_6 ) )
return - V_56 ;
V_82 = V_81 -> V_84 + 3 ;
V_82 &= ( T_5 ) ~ 3 ;
if ( V_54 )
V_67 = F_49 ( V_6 -> V_14 [ V_52 ] , V_23 ,
( ( T_3 * ) ( V_81 -> V_22 ) ) , V_82 ) ;
else if ( V_52 == 1 )
V_67 = F_50 ( V_6 -> V_14 [ V_52 ] , ( ( T_3 * ) ( V_81 -> V_22 ) ) ,
V_23 , V_82 ) ;
else
V_67 = F_51 ( V_6 -> V_14 [ V_52 ] , ( ( T_3 * ) ( V_81 -> V_22 ) ) , V_23 ,
V_82 ) ;
if ( V_67 == - V_61 )
F_45 ( V_6 -> V_4 , V_60 ) ;
return V_67 ;
}
static int F_52 ( struct V_5 * V_6 , T_5 V_52 ,
bool V_54 , T_4 V_23 ,
struct V_85 * V_86 )
{
unsigned int V_82 , V_87 , V_88 , V_89 , V_90 ;
unsigned int V_91 , V_92 , V_93 ;
unsigned short V_94 , V_95 ;
unsigned char * V_96 , * V_97 , * V_98 ;
struct V_80 * V_99 = NULL , * V_100 ;
struct V_85 V_101 , * V_102 ;
struct V_103 V_104 ;
struct V_105 V_106 ;
struct V_107 V_108 ;
struct V_109 * V_110 ;
int V_21 = 0 ;
if ( ! V_86 -> V_111 )
return - V_57 ;
F_11 ( V_6 , & V_6 -> V_83 ) ;
if ( F_8 ( V_6 ) )
return - V_56 ;
V_102 = V_86 ;
F_53 ( & V_101 ) ;
if ( V_6 -> V_26 && V_6 -> V_26 -> V_112 && ! V_54 ) {
V_82 = 0 ;
F_54 (pktlist, pkt_next)
V_82 += V_99 -> V_84 ;
V_82 = F_55 ( V_82 , V_6 -> V_14 [ V_52 ] -> V_113 ) ;
while ( V_82 > V_114 ) {
V_99 = F_56 ( V_114 ) ;
if ( V_99 == NULL ) {
V_21 = - V_115 ;
goto exit;
}
F_57 ( & V_101 , V_99 ) ;
V_82 -= V_114 ;
}
V_99 = F_56 ( V_82 ) ;
if ( V_99 == NULL ) {
V_21 = - V_115 ;
goto exit;
}
F_57 ( & V_101 , V_99 ) ;
V_102 = & V_101 ;
}
V_87 = V_6 -> V_14 [ V_52 ] -> V_113 ;
V_91 = V_6 -> V_116 ;
V_94 = F_58 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_95 = V_102 -> V_111 ;
V_90 = 0 ;
V_99 = V_102 -> V_117 ;
memset ( & V_104 , 0 , sizeof( struct V_103 ) ) ;
memset ( & V_106 , 0 , sizeof( struct V_105 ) ) ;
memset ( & V_108 , 0 , sizeof( struct V_107 ) ) ;
V_108 . V_118 = V_6 -> V_119 . V_110 ;
V_108 . V_120 = V_87 ;
V_108 . V_25 = V_54 ? V_121 : V_122 ;
V_106 . V_123 = V_124 ;
V_106 . V_125 = V_54 ? 1 << 31 : 0 ;
V_106 . V_125 |= ( V_52 & 0x7 ) << 28 ;
V_106 . V_125 |= 1 << 27 ;
V_106 . V_125 |= ( V_52 == 1 ) ? 1 << 26 : 0 ;
V_106 . V_25 = V_126 | V_127 | V_128 ;
V_104 . V_129 = & V_106 ;
V_104 . V_22 = & V_108 ;
while ( V_95 ) {
V_82 = 0 ;
V_88 = 0 ;
V_110 = V_6 -> V_119 . V_110 ;
while ( V_99 != (struct V_80 * ) V_102 ) {
V_96 = V_99 -> V_22 + V_90 ;
V_89 = V_99 -> V_84 - V_90 ;
if ( V_89 > V_6 -> V_130 )
V_89 = V_6 -> V_130 ;
if ( V_89 > V_91 - V_82 )
V_89 = V_91 - V_82 ;
F_59 ( V_110 , V_96 , V_89 ) ;
V_88 ++ ;
V_110 = F_60 ( V_110 ) ;
V_82 += V_89 ;
V_90 += V_89 ;
if ( V_90 == V_99 -> V_84 ) {
V_90 = 0 ;
V_99 = V_99 -> V_117 ;
}
if ( V_82 >= V_91 || V_88 >= V_94 )
break;
}
V_95 -= V_88 ;
if ( V_82 % V_87 != 0 ) {
F_15 ( L_19 ,
V_82 , V_87 ) ;
V_21 = - V_131 ;
goto exit;
}
V_108 . V_132 = V_88 ;
V_108 . V_133 = V_82 / V_87 ;
V_106 . V_125 |= ( V_23 & 0x1FFFF ) << 9 ;
V_106 . V_125 |= V_108 . V_133 & 0x1FF ;
if ( V_52 == 1 )
V_23 += V_82 ;
F_61 ( & V_108 , V_6 -> V_14 [ V_52 ] -> V_134 ) ;
F_62 ( V_6 -> V_14 [ V_52 ] -> V_134 -> V_135 , & V_104 ) ;
V_21 = V_106 . error ? V_106 . error : V_108 . error ;
if ( V_21 == - V_61 ) {
F_45 ( V_6 -> V_4 ,
V_60 ) ;
break;
} else if ( V_21 != 0 ) {
F_15 ( L_20 ,
V_54 ? L_11 : L_12 , V_21 ) ;
V_21 = - V_56 ;
break;
}
}
if ( V_6 -> V_26 && V_6 -> V_26 -> V_112 && ! V_54 ) {
V_100 = V_101 . V_117 ;
V_92 = 0 ;
F_54 (pktlist, pkt_next) {
V_93 = 0 ;
do {
V_82 = V_100 -> V_84 - V_92 ;
V_82 = F_58 ( T_5 , V_99 -> V_84 - V_93 ,
V_82 ) ;
V_97 = V_100 -> V_22 + V_92 ;
V_98 = V_99 -> V_22 + V_93 ;
memcpy ( V_98 , V_97 , V_82 ) ;
V_92 += V_82 ;
V_93 += V_82 ;
if ( V_92 == V_100 -> V_84 ) {
V_92 = 0 ;
V_100 = V_100 -> V_117 ;
}
if ( V_93 == V_99 -> V_84 )
break;
} while ( ! F_63 ( & V_101 ) );
}
}
exit:
F_64 ( V_6 -> V_119 . V_110 , V_6 -> V_119 . V_136 ) ;
while ( ( V_99 = F_65 ( & V_101 ) ) != NULL )
F_66 ( V_99 ) ;
return V_21 ;
}
int F_67 ( struct V_5 * V_6 , T_3 * V_137 , T_5 V_138 )
{
struct V_80 * V_139 ;
int V_67 ;
V_139 = F_56 ( V_138 ) ;
if ( ! V_139 ) {
F_15 ( L_21 ,
V_138 ) ;
return - V_56 ;
}
V_67 = F_68 ( V_6 , V_139 ) ;
if ( ! V_67 )
memcpy ( V_137 , V_139 -> V_22 , V_138 ) ;
F_66 ( V_139 ) ;
return V_67 ;
}
int F_68 ( struct V_5 * V_6 , struct V_80 * V_81 )
{
T_4 V_23 = V_6 -> V_76 ;
int V_67 = 0 ;
F_3 ( V_28 , L_22 , V_23 , V_81 -> V_84 ) ;
V_67 = F_47 ( V_6 , 4 , & V_23 ) ;
if ( V_67 )
goto V_79;
V_67 = F_48 ( V_6 , V_42 , false , V_23 , V_81 ) ;
V_79:
return V_67 ;
}
int F_69 ( struct V_5 * V_6 ,
struct V_85 * V_140 , T_5 V_141 )
{
struct V_80 * V_142 ;
struct V_80 * V_143 ;
T_4 V_23 = V_6 -> V_76 ;
int V_67 = 0 ;
F_3 ( V_28 , L_22 ,
V_23 , V_140 -> V_111 ) ;
V_67 = F_47 ( V_6 , 4 , & V_23 ) ;
if ( V_67 )
goto V_79;
if ( V_140 -> V_111 == 1 )
V_67 = F_48 ( V_6 , V_42 , false , V_23 ,
V_140 -> V_117 ) ;
else if ( ! V_6 -> V_144 ) {
V_142 = F_56 ( V_141 ) ;
if ( ! V_142 )
return - V_115 ;
V_67 = F_48 ( V_6 , V_42 , false , V_23 ,
V_142 ) ;
if ( V_67 )
goto V_79;
F_54 (pktq, skb) {
memcpy ( V_143 -> V_22 , V_142 -> V_22 , V_143 -> V_84 ) ;
F_70 ( V_142 , V_143 -> V_84 ) ;
}
} else
V_67 = F_52 ( V_6 , V_42 , false , V_23 ,
V_140 ) ;
V_79:
return V_67 ;
}
int F_71 ( struct V_5 * V_6 , T_3 * V_137 , T_5 V_138 )
{
struct V_80 * V_139 ;
T_4 V_23 = V_6 -> V_76 ;
int V_67 ;
V_139 = F_56 ( V_138 ) ;
if ( ! V_139 ) {
F_15 ( L_21 ,
V_138 ) ;
return - V_56 ;
}
memcpy ( V_139 -> V_22 , V_137 , V_138 ) ;
V_67 = F_47 ( V_6 , 4 , & V_23 ) ;
if ( ! V_67 )
V_67 = F_48 ( V_6 , V_42 , true , V_23 ,
V_139 ) ;
F_66 ( V_139 ) ;
return V_67 ;
}
int F_72 ( struct V_5 * V_6 ,
struct V_85 * V_140 )
{
struct V_80 * V_143 ;
T_4 V_23 = V_6 -> V_76 ;
int V_67 ;
F_3 ( V_28 , L_22 , V_23 , V_140 -> V_111 ) ;
V_67 = F_47 ( V_6 , 4 , & V_23 ) ;
if ( V_67 )
return V_67 ;
if ( V_140 -> V_111 == 1 || ! V_6 -> V_144 )
F_54 (pktq, skb) {
V_67 = F_48 ( V_6 , V_42 , true ,
V_23 , V_143 ) ;
if ( V_67 )
break;
}
else
V_67 = F_52 ( V_6 , V_42 , true , V_23 ,
V_140 ) ;
return V_67 ;
}
int
F_73 ( struct V_5 * V_6 , bool V_54 , T_4 V_66 ,
T_3 * V_22 , T_5 V_145 )
{
int V_146 = 0 ;
struct V_80 * V_81 ;
T_4 V_147 ;
T_5 V_148 ;
V_148 = F_58 ( T_5 , V_149 , V_145 ) ;
V_81 = F_74 ( V_148 ) ;
if ( ! V_81 ) {
F_15 ( L_23 , V_148 ) ;
return - V_56 ;
}
V_81 -> V_150 = 0 ;
V_147 = V_66 & V_75 ;
if ( ( V_147 + V_145 ) & V_151 )
V_148 = ( V_149 - V_147 ) ;
else
V_148 = V_145 ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_145 ) {
V_146 = F_46 ( V_6 , V_66 ) ;
if ( V_146 )
break;
F_3 ( V_28 , L_24 ,
V_54 ? L_11 : L_12 , V_148 ,
V_147 , V_66 & V_151 ) ;
V_147 &= V_75 ;
V_147 |= V_77 ;
F_75 ( V_81 , V_148 ) ;
if ( V_54 )
memcpy ( V_81 -> V_22 , V_22 , V_148 ) ;
V_146 = F_48 ( V_6 , V_41 , V_54 ,
V_147 , V_81 ) ;
if ( V_146 ) {
F_15 ( L_25 ) ;
break;
}
if ( ! V_54 )
memcpy ( V_22 , V_81 -> V_22 , V_148 ) ;
F_76 ( V_81 , 0 ) ;
V_145 -= V_148 ;
if ( V_145 ) {
V_22 += V_148 ;
V_66 += V_148 ;
V_147 = 0 ;
V_148 = F_58 ( T_5 , V_149 , V_145 ) ;
}
}
F_77 ( V_81 ) ;
if ( F_46 ( V_6 , V_6 -> V_76 ) )
F_15 ( L_26 ,
V_6 -> V_76 ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
return V_146 ;
}
int F_78 ( struct V_5 * V_6 , T_5 V_52 )
{
char V_152 = ( char ) V_52 ;
F_3 ( V_28 , L_27 ) ;
F_35 ( V_6 , V_63 , V_51 ,
sizeof( V_152 ) , & V_152 , true ) ;
F_3 ( V_28 , L_28 ) ;
return 0 ;
}
static void F_79 ( struct V_5 * V_6 )
{
T_5 V_153 ;
int V_67 ;
if ( ! V_6 -> V_144 )
return;
V_153 = F_80 ( T_5 , V_154 , V_155 ) ;
V_153 += ( V_153 >> 4 ) + 1 ;
F_36 ( V_153 > V_6 -> V_156 ) ;
F_3 ( V_157 , L_29 , V_153 ) ;
V_67 = F_81 ( & V_6 -> V_119 , V_153 , V_158 ) ;
if ( V_67 < 0 ) {
F_15 ( L_30 ) ;
V_6 -> V_144 = false ;
}
V_6 -> V_159 = V_155 ;
}
static int F_82 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 ) {
F_83 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_20 ( V_6 -> V_14 [ 2 ] ) ;
F_84 ( V_6 -> V_14 [ 2 ] ) ;
F_26 ( V_6 -> V_14 [ 2 ] ) ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_84 ( V_6 -> V_14 [ 1 ] ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
F_85 ( & V_6 -> V_119 ) ;
V_6 -> V_76 = 0 ;
return 0 ;
}
static int F_86 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_160 * V_135 ;
T_5 V_161 ;
int V_21 = 0 ;
V_6 -> V_162 = 2 ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
V_21 = F_87 ( V_6 -> V_14 [ 1 ] , V_163 ) ;
if ( V_21 ) {
F_15 ( L_31 ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
goto V_164;
}
V_21 = F_87 ( V_6 -> V_14 [ 2 ] , V_165 ) ;
if ( V_21 ) {
F_15 ( L_32 ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
goto V_164;
}
V_6 -> V_14 [ 2 ] -> V_166 = V_167 ;
V_21 = F_88 ( V_6 -> V_14 [ 1 ] ) ;
F_26 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_21 ) {
F_15 ( L_33 , V_21 ) ;
goto V_164;
}
V_14 = V_6 -> V_14 [ 2 ] ;
V_135 = V_14 -> V_134 -> V_135 ;
V_6 -> V_144 = V_135 -> V_168 > 1 ;
V_161 = F_58 ( T_5 , V_135 -> V_169 , 511u ) ;
V_6 -> V_116 = F_58 ( T_5 , V_135 -> V_170 ,
V_161 * V_14 -> V_113 ) ;
V_6 -> V_156 = F_58 ( T_5 , V_135 -> V_168 ,
V_171 ) ;
V_6 -> V_130 = V_135 -> V_172 ;
F_79 ( V_6 ) ;
V_6 -> V_11 = F_89 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_21 = - V_173 ;
goto V_164;
}
V_164:
if ( V_21 )
F_82 ( V_6 ) ;
return V_21 ;
}
static int F_90 ( struct V_13 * V_14 ,
const struct V_174 * V_175 )
{
int V_67 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
F_3 ( V_28 , L_27 ) ;
F_3 ( V_28 , L_34 , V_14 -> V_176 ) ;
F_3 ( V_28 , L_35 , V_14 -> V_177 ) ;
F_3 ( V_28 , L_36 , V_14 -> V_178 ) ;
F_3 ( V_28 , L_37 , V_14 -> V_179 ) ;
if ( V_14 -> V_179 == 1 )
return 0 ;
if ( V_14 -> V_179 != 2 )
return - V_173 ;
V_4 = F_91 ( sizeof( struct V_3 ) , V_158 ) ;
if ( ! V_4 )
return - V_115 ;
V_6 = F_91 ( sizeof( struct V_5 ) , V_158 ) ;
if ( ! V_6 ) {
F_92 ( V_4 ) ;
return - V_115 ;
}
V_6 -> V_14 [ 0 ] = F_93 ( V_14 , sizeof( * V_14 ) , V_158 ) ;
V_6 -> V_14 [ 0 ] -> V_179 = 0 ;
V_6 -> V_14 [ 1 ] = V_14 -> V_134 -> V_13 [ 0 ] ;
V_6 -> V_14 [ 2 ] = V_14 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 . V_8 = V_6 ;
V_4 -> V_180 = V_181 ;
F_94 ( & V_14 -> V_15 , V_4 ) ;
F_94 ( & V_6 -> V_14 [ 1 ] -> V_15 , V_4 ) ;
V_6 -> V_15 = & V_6 -> V_14 [ 1 ] -> V_15 ;
V_6 -> V_26 = V_182 ;
if ( ! V_6 -> V_26 )
F_95 ( V_6 ) ;
#ifdef F_9
if ( ( F_96 ( V_6 -> V_14 [ 1 ] ) & V_183 ) &&
( ( F_96 ( V_6 -> V_14 [ 1 ] ) & V_184 ) ||
( V_6 -> V_26 && V_6 -> V_26 -> V_27 ) ) )
V_4 -> V_185 = true ;
#endif
F_97 ( & V_6 -> V_17 , false ) ;
F_98 ( & V_6 -> V_55 ) ;
F_98 ( & V_6 -> V_83 ) ;
F_3 ( V_28 , L_38 ) ;
V_67 = F_86 ( V_6 ) ;
if ( V_67 ) {
F_15 ( L_39 , V_67 ) ;
goto V_186;
}
F_3 ( V_28 , L_40 ) ;
return 0 ;
V_186:
F_94 ( & V_14 -> V_15 , NULL ) ;
F_94 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_92 ( V_6 -> V_14 [ 0 ] ) ;
F_92 ( V_6 ) ;
F_92 ( V_4 ) ;
return V_67 ;
}
static void F_99 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( V_28 , L_27 ) ;
F_3 ( V_28 , L_35 , V_14 -> V_177 ) ;
F_3 ( V_28 , L_36 , V_14 -> V_178 ) ;
F_3 ( V_28 , L_41 , V_14 -> V_179 ) ;
if ( V_14 -> V_179 != 1 && V_14 -> V_179 != 2 )
return;
V_4 = F_2 ( & V_14 -> V_15 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_7 . V_8 ;
F_82 ( V_6 ) ;
F_94 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_94 ( & V_6 -> V_14 [ 2 ] -> V_15 , NULL ) ;
F_92 ( V_4 ) ;
F_92 ( V_6 -> V_14 [ 0 ] ) ;
F_92 ( V_6 ) ;
}
F_3 ( V_28 , L_28 ) ;
}
void F_100 ( struct V_178 * V_15 , bool V_187 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_28 , L_42 , V_187 ) ;
V_6 -> V_188 = V_187 ;
}
static int F_101 ( struct V_178 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
T_7 V_189 ;
F_3 ( V_28 , L_27 ) ;
F_97 ( & V_6 -> V_17 , true ) ;
if ( V_6 -> V_188 ) {
V_189 = V_183 ;
if ( V_6 -> V_26 -> V_27 )
F_19 ( V_6 -> V_26 -> V_29 ) ;
else
V_189 = V_184 ;
if ( F_102 ( V_6 -> V_14 [ 1 ] , V_189 ) )
F_15 ( L_43 , V_189 ) ;
}
F_103 ( V_6 -> V_11 , 0 ) ;
return 0 ;
}
static int F_104 ( struct V_178 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_28 , L_27 ) ;
if ( V_6 -> V_26 && V_6 -> V_26 -> V_27 )
F_29 ( V_6 -> V_26 -> V_29 ) ;
F_103 ( V_6 -> V_11 , V_190 ) ;
F_97 ( & V_6 -> V_17 , false ) ;
return 0 ;
}
static int T_8 F_105 ( struct V_191 * V_192 )
{
F_3 ( V_28 , L_27 ) ;
V_182 = F_106 ( & V_192 -> V_15 ) ;
if ( V_182 -> V_193 )
V_182 -> V_193 () ;
return 0 ;
}
static int F_107 ( struct V_191 * V_192 )
{
F_3 ( V_28 , L_27 ) ;
if ( V_182 -> V_194 )
V_182 -> V_194 () ;
F_108 ( & V_195 ) ;
return 0 ;
}
void F_109 ( void )
{
int V_21 ;
V_21 = F_110 ( & V_195 ) ;
if ( V_21 )
F_15 ( L_44 , V_21 ) ;
}
void F_111 ( void )
{
F_3 ( V_28 , L_27 ) ;
if ( V_182 )
F_112 ( & V_196 ) ;
else
F_108 ( & V_195 ) ;
}
void T_8 F_113 ( void )
{
int V_21 ;
F_3 ( V_28 , L_27 ) ;
V_21 = F_114 ( & V_196 , F_105 ) ;
if ( V_21 == - V_173 )
F_3 ( V_28 , L_45 ) ;
}
