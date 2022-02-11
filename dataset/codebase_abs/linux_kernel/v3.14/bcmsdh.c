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
unsigned long V_23 ;
if ( ( V_6 -> V_24 ) && ( V_6 -> V_24 -> V_25 ) ) {
F_3 ( V_26 , L_3 ,
V_6 -> V_24 -> V_27 ) ;
V_21 = F_14 ( V_6 -> V_24 -> V_27 ,
F_1 ,
V_6 -> V_24 -> V_28 ,
L_4 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
if ( V_21 != 0 ) {
F_15 ( L_5 , V_21 ) ;
return V_21 ;
}
V_6 -> V_29 = true ;
F_16 ( & V_6 -> V_30 ) ;
F_17 ( & V_6 -> V_30 , V_23 ) ;
V_6 -> V_10 = true ;
F_18 ( & V_6 -> V_30 , V_23 ) ;
V_21 = F_19 ( V_6 -> V_24 -> V_27 ) ;
if ( V_21 != 0 ) {
F_15 ( L_6 , V_21 ) ;
return V_21 ;
}
V_6 -> V_31 = true ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
V_22 = F_21 ( V_6 , V_32 , & V_21 ) ;
V_22 |= 1 << V_33 | 1 << V_34 | 1 ;
F_22 ( V_6 , V_32 , V_22 , & V_21 ) ;
V_22 = V_35 | V_36 ;
if ( V_6 -> V_24 -> V_28 & V_37 )
V_22 |= V_38 ;
F_22 ( V_6 , V_39 , V_22 , & V_21 ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
} else {
F_3 ( V_26 , L_7 ) ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_24 ( V_6 -> V_14 [ 1 ] , F_6 ) ;
F_24 ( V_6 -> V_14 [ 2 ] , F_7 ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
}
return 0 ;
}
int F_25 ( struct V_5 * V_6 )
{
F_3 ( V_26 , L_7 ) ;
if ( ( V_6 -> V_24 ) && ( V_6 -> V_24 -> V_25 ) ) {
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_22 ( V_6 , V_39 , 0 , NULL ) ;
F_22 ( V_6 , V_32 , 0 , NULL ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_29 ) {
V_6 -> V_29 = false ;
if ( V_6 -> V_31 ) {
F_26 ( V_6 -> V_24 -> V_27 ) ;
V_6 -> V_31 = false ;
}
F_27 ( V_6 -> V_24 -> V_27 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
V_6 -> V_10 = false ;
}
} else {
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_28 ( V_6 -> V_14 [ 2 ] ) ;
F_28 ( V_6 -> V_14 [ 1 ] ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
}
return 0 ;
}
static inline int F_29 ( struct V_13 * V_14 ,
T_4 V_40 , T_3 V_41 )
{
int V_42 ;
if ( ( V_40 == V_43 ) ||
( V_40 == V_32 ) )
F_30 ( V_14 , V_41 , V_40 , & V_42 ) ;
else
F_31 ( V_14 , V_41 , V_40 , & V_42 ) ;
return V_42 ;
}
static int F_32 ( struct V_5 * V_6 , T_3 V_44 ,
T_5 V_45 , T_3 V_46 , void * V_22 , bool V_47 )
{
struct V_13 * V_14 ;
int V_21 ;
F_3 ( V_26 , L_8 ,
V_47 , V_44 , V_45 , V_46 ) ;
F_11 ( V_6 , & V_6 -> V_48 ) ;
if ( F_8 ( V_6 ) )
return - V_49 ;
if ( F_33 ( V_46 > 1 && ! V_44 ) )
return - V_50 ;
V_14 = V_6 -> V_14 [ V_44 ] ;
switch ( V_46 ) {
case sizeof( T_3 ) :
if ( V_47 ) {
if ( V_44 )
F_30 ( V_14 , * ( T_3 * ) V_22 , V_45 , & V_21 ) ;
else
V_21 = F_29 ( V_14 , V_45 ,
* ( T_3 * ) V_22 ) ;
} else {
if ( V_44 )
* ( T_3 * ) V_22 = F_34 ( V_14 , V_45 , & V_21 ) ;
else
* ( T_3 * ) V_22 = F_35 ( V_14 , V_45 , & V_21 ) ;
}
break;
case sizeof( V_51 ) :
if ( V_47 )
F_36 ( V_14 , * ( V_51 * ) V_22 , V_45 , & V_21 ) ;
else
* ( V_51 * ) V_22 = F_37 ( V_14 , V_45 , & V_21 ) ;
break;
case sizeof( T_5 ) :
if ( V_47 )
F_38 ( V_14 , * ( T_5 * ) V_22 , V_45 , & V_21 ) ;
else
* ( T_5 * ) V_22 = F_39 ( V_14 , V_45 , & V_21 ) ;
break;
default:
F_15 ( L_9 , V_46 ) ;
break;
}
if ( V_21 ) {
if ( V_45 != V_52 )
F_15 ( L_10 ,
V_47 ? L_11 : L_12 , V_44 , V_45 , V_21 ) ;
else
F_3 ( V_26 , L_10 ,
V_47 ? L_11 : L_12 , V_44 , V_45 , V_21 ) ;
}
return V_21 ;
}
static int F_40 ( struct V_5 * V_6 , T_5 V_45 ,
T_3 V_46 , void * V_22 , bool V_47 )
{
T_3 V_53 ;
T_6 V_19 = 0 ;
int V_21 ;
if ( V_6 -> V_4 -> V_54 == V_55 )
return - V_56 ;
if ( ( V_45 & ~ V_57 ) == 0 )
V_53 = V_58 ;
else
V_53 = V_33 ;
do {
if ( ! V_47 )
memset ( V_22 , 0 , V_46 ) ;
if ( V_19 )
F_41 ( 1000 , 2000 ) ;
V_21 = F_32 ( V_6 , V_53 , V_45 , V_46 ,
V_22 , V_47 ) ;
} while ( V_21 != 0 && V_21 != - V_56 &&
V_19 ++ < V_59 );
if ( V_21 == - V_56 )
F_42 ( V_6 -> V_4 , V_55 ) ;
else if ( V_21 != 0 )
F_15 ( L_13 , V_21 ) ;
return V_21 ;
}
static int
F_43 ( struct V_5 * V_6 , T_5 V_60 )
{
int V_61 = 0 , V_62 ;
T_3 V_45 [ 3 ] ;
if ( V_6 -> V_4 -> V_54 == V_55 )
return - V_56 ;
V_45 [ 0 ] = ( V_60 >> 8 ) & V_63 ;
V_45 [ 1 ] = ( V_60 >> 16 ) & V_64 ;
V_45 [ 2 ] = ( V_60 >> 24 ) & V_65 ;
for ( V_62 = 0 ; V_62 < 3 ; V_62 ++ ) {
V_61 = F_40 ( V_6 ,
V_66 + V_62 ,
sizeof( T_3 ) , & V_45 [ V_62 ] , true ) ;
if ( V_61 ) {
F_15 ( L_14 ,
V_66 + V_62 ) ;
break;
}
}
return V_61 ;
}
static int
F_44 ( struct V_5 * V_6 , T_4 V_67 , T_5 * V_45 )
{
T_4 V_68 = * V_45 & ~ V_69 ;
int V_61 = 0 ;
if ( V_68 != V_6 -> V_70 ) {
V_61 = F_43 ( V_6 , V_68 ) ;
if ( V_61 )
return V_61 ;
V_6 -> V_70 = V_68 ;
}
* V_45 &= V_69 ;
if ( V_67 == 4 )
* V_45 |= V_71 ;
return 0 ;
}
T_3 F_21 ( struct V_5 * V_6 , T_5 V_45 , int * V_21 )
{
T_3 V_22 ;
int V_72 ;
F_3 ( V_26 , L_15 , V_45 ) ;
V_72 = F_40 ( V_6 , V_45 , sizeof( V_22 ) , & V_22 ,
false ) ;
F_3 ( V_26 , L_16 , V_22 ) ;
if ( V_21 )
* V_21 = V_72 ;
return V_22 ;
}
T_5 F_45 ( struct V_5 * V_6 , T_5 V_45 , int * V_21 )
{
T_5 V_22 ;
int V_72 ;
F_3 ( V_26 , L_15 , V_45 ) ;
V_72 = F_44 ( V_6 , sizeof( V_22 ) , & V_45 ) ;
if ( V_72 )
goto V_73;
V_72 = F_40 ( V_6 , V_45 , sizeof( V_22 ) , & V_22 ,
false ) ;
F_3 ( V_26 , L_17 , V_22 ) ;
V_73:
if ( V_21 )
* V_21 = V_72 ;
return V_22 ;
}
void F_22 ( struct V_5 * V_6 , T_5 V_45 ,
T_3 V_22 , int * V_21 )
{
int V_72 ;
F_3 ( V_26 , L_18 , V_45 , V_22 ) ;
V_72 = F_40 ( V_6 , V_45 , sizeof( V_22 ) , & V_22 ,
true ) ;
if ( V_21 )
* V_21 = V_72 ;
}
void F_46 ( struct V_5 * V_6 , T_5 V_45 ,
T_5 V_22 , int * V_21 )
{
int V_72 ;
F_3 ( V_26 , L_19 , V_45 , V_22 ) ;
V_72 = F_44 ( V_6 , sizeof( V_22 ) , & V_45 ) ;
if ( V_72 )
goto V_73;
V_72 = F_40 ( V_6 , V_45 , sizeof( V_22 ) , & V_22 ,
true ) ;
V_73:
if ( V_21 )
* V_21 = V_72 ;
}
static int F_47 ( struct V_5 * V_6 , T_4 V_44 ,
bool V_47 , T_5 V_45 , struct V_74 * V_75 )
{
unsigned int V_76 ;
int V_61 ;
F_11 ( V_6 , & V_6 -> V_77 ) ;
if ( F_8 ( V_6 ) )
return - V_49 ;
V_76 = V_75 -> V_78 + 3 ;
V_76 &= ( T_4 ) ~ 3 ;
if ( V_47 )
V_61 = F_48 ( V_6 -> V_14 [ V_44 ] , V_45 ,
( ( T_3 * ) ( V_75 -> V_22 ) ) , V_76 ) ;
else if ( V_44 == 1 )
V_61 = F_49 ( V_6 -> V_14 [ V_44 ] , ( ( T_3 * ) ( V_75 -> V_22 ) ) ,
V_45 , V_76 ) ;
else
V_61 = F_50 ( V_6 -> V_14 [ V_44 ] , ( ( T_3 * ) ( V_75 -> V_22 ) ) , V_45 ,
V_76 ) ;
if ( V_61 == - V_56 )
F_42 ( V_6 -> V_4 , V_55 ) ;
return V_61 ;
}
static int F_51 ( struct V_5 * V_6 , T_4 V_44 ,
bool V_47 , T_5 V_45 ,
struct V_79 * V_80 )
{
unsigned int V_76 , V_81 , V_82 , V_83 , V_84 ;
unsigned int V_85 , V_86 , V_87 ;
unsigned short V_88 , V_89 ;
unsigned char * V_90 , * V_91 , * V_92 ;
struct V_74 * V_93 = NULL , * V_94 ;
struct V_79 V_95 , * V_96 ;
struct V_97 V_98 ;
struct V_99 V_100 ;
struct V_101 V_102 ;
struct V_103 V_104 ;
struct V_105 * V_106 ;
int V_21 = 0 ;
if ( ! V_80 -> V_107 )
return - V_50 ;
F_11 ( V_6 , & V_6 -> V_77 ) ;
if ( F_8 ( V_6 ) )
return - V_49 ;
V_96 = V_80 ;
F_52 ( & V_95 ) ;
if ( V_6 -> V_24 && V_6 -> V_24 -> V_108 && ! V_47 ) {
V_76 = 0 ;
F_53 (pktlist, pkt_next)
V_76 += V_93 -> V_78 ;
V_76 = F_54 ( V_76 , V_6 -> V_14 [ V_44 ] -> V_109 ) ;
while ( V_76 > V_110 ) {
V_93 = F_55 ( V_110 ) ;
if ( V_93 == NULL ) {
V_21 = - V_111 ;
goto exit;
}
F_56 ( & V_95 , V_93 ) ;
V_76 -= V_110 ;
}
V_93 = F_55 ( V_76 ) ;
if ( V_93 == NULL ) {
V_21 = - V_111 ;
goto exit;
}
F_56 ( & V_95 , V_93 ) ;
V_96 = & V_95 ;
}
V_81 = V_6 -> V_14 [ V_44 ] -> V_109 ;
V_85 = V_6 -> V_112 ;
V_88 = F_57 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_89 = V_96 -> V_107 ;
V_84 = 0 ;
V_93 = V_96 -> V_113 ;
if ( F_58 ( & V_104 , V_88 , V_114 ) ) {
V_21 = - V_111 ;
goto exit;
}
memset ( & V_98 , 0 , sizeof( struct V_97 ) ) ;
memset ( & V_100 , 0 , sizeof( struct V_99 ) ) ;
memset ( & V_102 , 0 , sizeof( struct V_101 ) ) ;
V_102 . V_115 = V_104 . V_106 ;
V_102 . V_116 = V_81 ;
V_102 . V_23 = V_47 ? V_117 : V_118 ;
V_100 . V_119 = V_120 ;
V_100 . V_121 = V_47 ? 1 << 31 : 0 ;
V_100 . V_121 |= ( V_44 & 0x7 ) << 28 ;
V_100 . V_121 |= 1 << 27 ;
V_100 . V_121 |= ( V_44 == 1 ) ? 1 << 26 : 0 ;
V_100 . V_23 = V_122 | V_123 | V_124 ;
V_98 . V_125 = & V_100 ;
V_98 . V_22 = & V_102 ;
while ( V_89 ) {
V_76 = 0 ;
V_82 = 0 ;
V_106 = V_104 . V_106 ;
while ( V_93 != (struct V_74 * ) V_96 ) {
V_90 = V_93 -> V_22 + V_84 ;
V_83 = V_93 -> V_78 - V_84 ;
if ( V_83 > V_6 -> V_126 )
V_83 = V_6 -> V_126 ;
if ( V_83 > V_85 - V_76 )
V_83 = V_85 - V_76 ;
F_59 ( V_106 , V_90 , V_83 ) ;
V_82 ++ ;
V_106 = F_60 ( V_106 ) ;
V_76 += V_83 ;
V_84 += V_83 ;
if ( V_84 == V_93 -> V_78 ) {
V_84 = 0 ;
V_93 = V_93 -> V_113 ;
}
if ( V_76 >= V_85 || V_82 >= V_88 )
break;
}
V_89 -= V_82 ;
if ( V_76 % V_81 != 0 ) {
F_15 ( L_20 ,
V_76 , V_81 ) ;
V_21 = - V_127 ;
goto exit;
}
V_102 . V_128 = V_82 ;
V_102 . V_129 = V_76 / V_81 ;
V_100 . V_121 |= ( V_45 & 0x1FFFF ) << 9 ;
V_100 . V_121 |= V_102 . V_129 & 0x1FF ;
if ( V_44 == 1 )
V_45 += V_76 ;
F_61 ( & V_102 , V_6 -> V_14 [ V_44 ] -> V_130 ) ;
F_62 ( V_6 -> V_14 [ V_44 ] -> V_130 -> V_131 , & V_98 ) ;
V_21 = V_100 . error ? V_100 . error : V_102 . error ;
if ( V_21 == - V_56 ) {
F_42 ( V_6 -> V_4 ,
V_55 ) ;
break;
} else if ( V_21 != 0 ) {
F_15 ( L_21 ,
V_47 ? L_11 : L_12 , V_21 ) ;
V_21 = - V_49 ;
break;
}
}
if ( V_6 -> V_24 && V_6 -> V_24 -> V_108 && ! V_47 ) {
V_94 = V_95 . V_113 ;
V_86 = 0 ;
F_53 (pktlist, pkt_next) {
V_87 = 0 ;
do {
V_76 = V_94 -> V_78 - V_86 ;
V_76 = F_57 ( T_4 , V_93 -> V_78 - V_87 ,
V_76 ) ;
V_91 = V_94 -> V_22 + V_86 ;
V_92 = V_93 -> V_22 + V_87 ;
memcpy ( V_92 , V_91 , V_76 ) ;
V_86 += V_76 ;
V_87 += V_76 ;
if ( V_86 == V_94 -> V_78 ) {
V_86 = 0 ;
V_94 = V_94 -> V_113 ;
}
if ( V_87 == V_93 -> V_78 )
break;
} while ( ! F_63 ( & V_95 ) );
}
}
exit:
F_64 ( & V_104 ) ;
while ( ( V_93 = F_65 ( & V_95 ) ) != NULL )
F_66 ( V_93 ) ;
return V_21 ;
}
int F_67 ( struct V_5 * V_6 , T_3 * V_132 , T_4 V_133 )
{
struct V_74 * V_134 ;
int V_61 ;
V_134 = F_55 ( V_133 ) ;
if ( ! V_134 ) {
F_15 ( L_22 ,
V_133 ) ;
return - V_49 ;
}
V_61 = F_68 ( V_6 , V_134 ) ;
if ( ! V_61 )
memcpy ( V_132 , V_134 -> V_22 , V_133 ) ;
F_66 ( V_134 ) ;
return V_61 ;
}
int F_68 ( struct V_5 * V_6 , struct V_74 * V_75 )
{
T_5 V_45 = V_6 -> V_70 ;
int V_61 = 0 ;
F_3 ( V_26 , L_23 , V_45 , V_75 -> V_78 ) ;
V_61 = F_44 ( V_6 , 4 , & V_45 ) ;
if ( V_61 )
goto V_73;
V_61 = F_47 ( V_6 , V_34 , false , V_45 , V_75 ) ;
V_73:
return V_61 ;
}
int F_69 ( struct V_5 * V_6 ,
struct V_79 * V_135 , T_4 V_136 )
{
struct V_74 * V_137 ;
struct V_74 * V_138 ;
T_5 V_45 = V_6 -> V_70 ;
int V_61 = 0 ;
F_3 ( V_26 , L_23 ,
V_45 , V_135 -> V_107 ) ;
V_61 = F_44 ( V_6 , 4 , & V_45 ) ;
if ( V_61 )
goto V_73;
if ( V_135 -> V_107 == 1 )
V_61 = F_47 ( V_6 , V_34 , false , V_45 ,
V_135 -> V_113 ) ;
else if ( ! V_6 -> V_139 ) {
V_137 = F_55 ( V_136 ) ;
if ( ! V_137 )
return - V_111 ;
V_61 = F_47 ( V_6 , V_34 , false , V_45 ,
V_137 ) ;
if ( V_61 )
goto V_73;
F_53 (pktq, skb) {
memcpy ( V_138 -> V_22 , V_137 -> V_22 , V_138 -> V_78 ) ;
F_70 ( V_137 , V_138 -> V_78 ) ;
}
} else
V_61 = F_51 ( V_6 , V_34 , false , V_45 ,
V_135 ) ;
V_73:
return V_61 ;
}
int F_71 ( struct V_5 * V_6 , T_3 * V_132 , T_4 V_133 )
{
struct V_74 * V_134 ;
T_5 V_45 = V_6 -> V_70 ;
int V_61 ;
V_134 = F_55 ( V_133 ) ;
if ( ! V_134 ) {
F_15 ( L_22 ,
V_133 ) ;
return - V_49 ;
}
memcpy ( V_134 -> V_22 , V_132 , V_133 ) ;
V_61 = F_44 ( V_6 , 4 , & V_45 ) ;
if ( ! V_61 )
V_61 = F_47 ( V_6 , V_34 , true , V_45 ,
V_134 ) ;
F_66 ( V_134 ) ;
return V_61 ;
}
int F_72 ( struct V_5 * V_6 ,
struct V_79 * V_135 )
{
struct V_74 * V_138 ;
T_5 V_45 = V_6 -> V_70 ;
int V_61 ;
F_3 ( V_26 , L_23 , V_45 , V_135 -> V_107 ) ;
V_61 = F_44 ( V_6 , 4 , & V_45 ) ;
if ( V_61 )
return V_61 ;
if ( V_135 -> V_107 == 1 || ! V_6 -> V_139 )
F_53 (pktq, skb) {
V_61 = F_47 ( V_6 , V_34 , true ,
V_45 , V_138 ) ;
if ( V_61 )
break;
}
else
V_61 = F_51 ( V_6 , V_34 , true , V_45 ,
V_135 ) ;
return V_61 ;
}
int
F_73 ( struct V_5 * V_6 , bool V_47 , T_5 V_60 ,
T_3 * V_22 , T_4 V_140 )
{
int V_141 = 0 ;
struct V_74 * V_75 ;
T_5 V_142 ;
T_4 V_143 ;
V_143 = F_57 ( T_4 , V_144 , V_140 ) ;
V_75 = F_74 ( V_143 ) ;
if ( ! V_75 ) {
F_15 ( L_24 , V_143 ) ;
return - V_49 ;
}
V_75 -> V_145 = 0 ;
V_142 = V_60 & V_69 ;
if ( ( V_142 + V_140 ) & V_146 )
V_143 = ( V_144 - V_142 ) ;
else
V_143 = V_140 ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_140 ) {
V_141 = F_43 ( V_6 , V_60 ) ;
if ( V_141 )
break;
F_3 ( V_26 , L_25 ,
V_47 ? L_11 : L_12 , V_143 ,
V_142 , V_60 & V_146 ) ;
V_142 &= V_69 ;
V_142 |= V_71 ;
F_75 ( V_75 , V_143 ) ;
if ( V_47 )
memcpy ( V_75 -> V_22 , V_22 , V_143 ) ;
V_141 = F_47 ( V_6 , V_33 , V_47 ,
V_142 , V_75 ) ;
if ( V_141 ) {
F_15 ( L_26 ) ;
break;
}
if ( ! V_47 )
memcpy ( V_22 , V_75 -> V_22 , V_143 ) ;
F_76 ( V_75 , V_143 ) ;
V_140 -= V_143 ;
if ( V_140 ) {
V_22 += V_143 ;
V_60 += V_143 ;
V_142 = 0 ;
V_143 = F_57 ( T_4 , V_144 , V_140 ) ;
}
}
F_77 ( V_75 ) ;
if ( F_43 ( V_6 , V_6 -> V_70 ) )
F_15 ( L_27 ,
V_6 -> V_70 ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
return V_141 ;
}
int F_78 ( struct V_5 * V_6 , T_4 V_44 )
{
char V_147 = ( char ) V_44 ;
F_3 ( V_26 , L_28 ) ;
F_32 ( V_6 , V_58 , V_43 ,
sizeof( V_147 ) , & V_147 , true ) ;
F_3 ( V_26 , L_29 ) ;
return 0 ;
}
static int F_79 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 ) {
F_80 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_20 ( V_6 -> V_14 [ 2 ] ) ;
F_81 ( V_6 -> V_14 [ 2 ] ) ;
F_23 ( V_6 -> V_14 [ 2 ] ) ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_81 ( V_6 -> V_14 [ 1 ] ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
V_6 -> V_70 = 0 ;
return 0 ;
}
static int F_82 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_148 * V_131 ;
T_4 V_149 ;
int V_21 = 0 ;
V_6 -> V_150 = 2 ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
V_21 = F_83 ( V_6 -> V_14 [ 1 ] , V_151 ) ;
if ( V_21 ) {
F_15 ( L_30 ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
goto V_152;
}
V_21 = F_83 ( V_6 -> V_14 [ 2 ] , V_153 ) ;
if ( V_21 ) {
F_15 ( L_31 ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
goto V_152;
}
V_6 -> V_14 [ 2 ] -> V_154 = V_155 ;
V_21 = F_84 ( V_6 -> V_14 [ 1 ] ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_21 ) {
F_15 ( L_32 , V_21 ) ;
goto V_152;
}
V_14 = V_6 -> V_14 [ 2 ] ;
V_131 = V_14 -> V_130 -> V_131 ;
V_6 -> V_139 = V_131 -> V_156 > 1 ;
V_149 = F_57 ( T_4 , V_131 -> V_157 , 511u ) ;
V_6 -> V_112 = F_57 ( T_4 , V_131 -> V_158 ,
V_149 * V_14 -> V_109 ) ;
V_6 -> V_159 = F_57 ( T_4 , V_131 -> V_156 ,
V_160 ) ;
V_6 -> V_126 = V_131 -> V_161 ;
V_6 -> V_11 = F_85 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_21 = - V_162 ;
goto V_152;
}
V_152:
if ( V_21 )
F_79 ( V_6 ) ;
return V_21 ;
}
static int F_86 ( struct V_13 * V_14 ,
const struct V_163 * V_164 )
{
int V_61 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
F_3 ( V_26 , L_28 ) ;
F_3 ( V_26 , L_33 , V_14 -> V_165 ) ;
F_3 ( V_26 , L_34 , V_14 -> V_166 ) ;
F_3 ( V_26 , L_35 , V_14 -> V_167 ) ;
F_3 ( V_26 , L_36 , V_14 -> V_168 ) ;
if ( V_14 -> V_168 == 1 )
return 0 ;
if ( V_14 -> V_168 != 2 )
return - V_162 ;
V_4 = F_87 ( sizeof( struct V_3 ) , V_114 ) ;
if ( ! V_4 )
return - V_111 ;
V_6 = F_87 ( sizeof( struct V_5 ) , V_114 ) ;
if ( ! V_6 ) {
F_88 ( V_4 ) ;
return - V_111 ;
}
V_6 -> V_14 [ 0 ] = F_89 ( V_14 , sizeof( * V_14 ) , V_114 ) ;
V_6 -> V_14 [ 0 ] -> V_168 = 0 ;
V_6 -> V_14 [ 1 ] = V_14 -> V_130 -> V_13 [ 0 ] ;
V_6 -> V_14 [ 2 ] = V_14 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 . V_8 = V_6 ;
V_4 -> V_169 = V_170 ;
F_90 ( & V_14 -> V_15 , V_4 ) ;
F_90 ( & V_6 -> V_14 [ 1 ] -> V_15 , V_4 ) ;
V_6 -> V_15 = & V_6 -> V_14 [ 1 ] -> V_15 ;
V_6 -> V_24 = V_171 ;
F_91 ( & V_6 -> V_17 , false ) ;
F_92 ( & V_6 -> V_48 ) ;
F_92 ( & V_6 -> V_77 ) ;
F_3 ( V_26 , L_37 ) ;
V_61 = F_82 ( V_6 ) ;
if ( V_61 ) {
F_15 ( L_38 , V_61 ) ;
goto V_172;
}
F_3 ( V_26 , L_39 ) ;
return 0 ;
V_172:
F_90 ( & V_14 -> V_15 , NULL ) ;
F_90 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_88 ( V_6 -> V_14 [ 0 ] ) ;
F_88 ( V_6 ) ;
F_88 ( V_4 ) ;
return V_61 ;
}
static void F_93 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( V_26 , L_28 ) ;
F_3 ( V_26 , L_34 , V_14 -> V_166 ) ;
F_3 ( V_26 , L_35 , V_14 -> V_167 ) ;
F_3 ( V_26 , L_40 , V_14 -> V_168 ) ;
if ( V_14 -> V_168 != 1 && V_14 -> V_168 != 2 )
return;
V_4 = F_2 ( & V_14 -> V_15 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_7 . V_8 ;
F_79 ( V_6 ) ;
F_90 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_90 ( & V_6 -> V_14 [ 2 ] -> V_15 , NULL ) ;
F_88 ( V_4 ) ;
F_88 ( V_6 -> V_14 [ 0 ] ) ;
F_88 ( V_6 ) ;
}
F_3 ( V_26 , L_29 ) ;
}
static int F_94 ( struct V_167 * V_15 )
{
T_7 V_173 ;
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
int V_21 = 0 ;
F_3 ( V_26 , L_41 ) ;
F_91 ( & V_6 -> V_17 , true ) ;
V_173 = F_95 ( V_6 -> V_14 [ 1 ] ) ;
if ( ! ( V_173 & V_174 ) ) {
F_15 ( L_42 ) ;
return - V_50 ;
}
V_21 = F_96 ( V_6 -> V_14 [ 1 ] , V_174 ) ;
if ( V_21 ) {
F_15 ( L_43 ) ;
return V_21 ;
}
F_97 ( V_6 -> V_11 , 0 ) ;
return V_21 ;
}
static int F_98 ( struct V_167 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_97 ( V_6 -> V_11 , V_175 ) ;
F_91 ( & V_6 -> V_17 , false ) ;
return 0 ;
}
static int F_99 ( struct V_176 * V_177 )
{
F_3 ( V_26 , L_28 ) ;
V_171 = F_100 ( & V_177 -> V_15 ) ;
if ( V_171 -> V_178 )
V_171 -> V_178 () ;
return 0 ;
}
static int F_101 ( struct V_176 * V_177 )
{
F_3 ( V_26 , L_28 ) ;
if ( V_171 -> V_179 )
V_171 -> V_179 () ;
F_102 ( & V_180 ) ;
return 0 ;
}
void F_103 ( void )
{
int V_21 ;
V_21 = F_104 ( & V_180 ) ;
if ( V_21 )
F_15 ( L_44 , V_21 ) ;
}
void F_105 ( void )
{
F_3 ( V_26 , L_28 ) ;
if ( V_171 )
F_106 ( & V_181 ) ;
else
F_102 ( & V_180 ) ;
}
void T_8 F_107 ( void )
{
int V_21 ;
F_3 ( V_26 , L_28 ) ;
V_21 = F_108 ( & V_181 , F_99 ) ;
if ( V_21 == - V_162 )
F_3 ( V_26 , L_45 ) ;
}
