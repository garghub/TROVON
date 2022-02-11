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
if ( V_21 )
F_3 ( V_26 , L_10 ,
V_47 ? L_11 : L_12 , V_44 , V_45 , V_21 ) ;
return V_21 ;
}
static int F_40 ( struct V_5 * V_6 , T_5 V_45 ,
T_3 V_46 , void * V_22 , bool V_47 )
{
T_3 V_14 ;
T_6 V_19 = 0 ;
int V_21 ;
if ( V_6 -> V_4 -> V_52 == V_53 )
return - V_54 ;
if ( ( V_45 & ~ V_55 ) == 0 )
V_14 = V_56 ;
else
V_14 = V_33 ;
do {
if ( ! V_47 )
memset ( V_22 , 0 , V_46 ) ;
if ( V_19 )
F_41 ( 1000 , 2000 ) ;
V_21 = F_32 ( V_6 , V_14 , V_45 , V_46 ,
V_22 , V_47 ) ;
} while ( V_21 != 0 && V_21 != - V_54 &&
V_19 ++ < V_57 );
if ( V_21 == - V_54 )
F_42 ( V_6 -> V_4 , V_53 ) ;
else if ( V_21 != 0 ) {
if ( V_45 != V_58 )
F_15 ( L_10 ,
V_47 ? L_11 : L_12 , V_14 , V_45 , V_21 ) ;
else
F_3 ( V_26 , L_10 ,
V_47 ? L_11 : L_12 , V_14 , V_45 , V_21 ) ;
}
return V_21 ;
}
static int
F_43 ( struct V_5 * V_6 , T_5 V_59 )
{
int V_60 = 0 , V_61 ;
T_3 V_45 [ 3 ] ;
if ( V_6 -> V_4 -> V_52 == V_53 )
return - V_54 ;
V_45 [ 0 ] = ( V_59 >> 8 ) & V_62 ;
V_45 [ 1 ] = ( V_59 >> 16 ) & V_63 ;
V_45 [ 2 ] = ( V_59 >> 24 ) & V_64 ;
for ( V_61 = 0 ; V_61 < 3 ; V_61 ++ ) {
V_60 = F_40 ( V_6 ,
V_65 + V_61 ,
sizeof( T_3 ) , & V_45 [ V_61 ] , true ) ;
if ( V_60 ) {
F_15 ( L_13 ,
V_65 + V_61 ) ;
break;
}
}
return V_60 ;
}
static int
F_44 ( struct V_5 * V_6 , T_4 V_66 , T_5 * V_45 )
{
T_4 V_67 = * V_45 & ~ V_68 ;
int V_60 = 0 ;
if ( V_67 != V_6 -> V_69 ) {
V_60 = F_43 ( V_6 , V_67 ) ;
if ( V_60 )
return V_60 ;
V_6 -> V_69 = V_67 ;
}
* V_45 &= V_68 ;
if ( V_66 == 4 )
* V_45 |= V_70 ;
return 0 ;
}
T_3 F_21 ( struct V_5 * V_6 , T_5 V_45 , int * V_21 )
{
T_3 V_22 ;
int V_71 ;
F_3 ( V_26 , L_14 , V_45 ) ;
V_71 = F_40 ( V_6 , V_45 , sizeof( V_22 ) , & V_22 ,
false ) ;
F_3 ( V_26 , L_15 , V_22 ) ;
if ( V_21 )
* V_21 = V_71 ;
return V_22 ;
}
T_5 F_45 ( struct V_5 * V_6 , T_5 V_45 , int * V_21 )
{
T_5 V_22 ;
int V_71 ;
F_3 ( V_26 , L_14 , V_45 ) ;
V_71 = F_44 ( V_6 , sizeof( V_22 ) , & V_45 ) ;
if ( V_71 )
goto V_72;
V_71 = F_40 ( V_6 , V_45 , sizeof( V_22 ) , & V_22 ,
false ) ;
F_3 ( V_26 , L_16 , V_22 ) ;
V_72:
if ( V_21 )
* V_21 = V_71 ;
return V_22 ;
}
void F_22 ( struct V_5 * V_6 , T_5 V_45 ,
T_3 V_22 , int * V_21 )
{
int V_71 ;
F_3 ( V_26 , L_17 , V_45 , V_22 ) ;
V_71 = F_40 ( V_6 , V_45 , sizeof( V_22 ) , & V_22 ,
true ) ;
if ( V_21 )
* V_21 = V_71 ;
}
void F_46 ( struct V_5 * V_6 , T_5 V_45 ,
T_5 V_22 , int * V_21 )
{
int V_71 ;
F_3 ( V_26 , L_18 , V_45 , V_22 ) ;
V_71 = F_44 ( V_6 , sizeof( V_22 ) , & V_45 ) ;
if ( V_71 )
goto V_72;
V_71 = F_40 ( V_6 , V_45 , sizeof( V_22 ) , & V_22 ,
true ) ;
V_72:
if ( V_21 )
* V_21 = V_71 ;
}
static int F_47 ( struct V_5 * V_6 , T_4 V_44 ,
bool V_47 , T_5 V_45 , struct V_73 * V_74 )
{
unsigned int V_75 ;
int V_60 ;
F_11 ( V_6 , & V_6 -> V_76 ) ;
if ( F_8 ( V_6 ) )
return - V_49 ;
V_75 = V_74 -> V_77 + 3 ;
V_75 &= ( T_4 ) ~ 3 ;
if ( V_47 )
V_60 = F_48 ( V_6 -> V_14 [ V_44 ] , V_45 ,
( ( T_3 * ) ( V_74 -> V_22 ) ) , V_75 ) ;
else if ( V_44 == 1 )
V_60 = F_49 ( V_6 -> V_14 [ V_44 ] , ( ( T_3 * ) ( V_74 -> V_22 ) ) ,
V_45 , V_75 ) ;
else
V_60 = F_50 ( V_6 -> V_14 [ V_44 ] , ( ( T_3 * ) ( V_74 -> V_22 ) ) , V_45 ,
V_75 ) ;
if ( V_60 == - V_54 )
F_42 ( V_6 -> V_4 , V_53 ) ;
return V_60 ;
}
static int F_51 ( struct V_5 * V_6 , T_4 V_44 ,
bool V_47 , T_5 V_45 ,
struct V_78 * V_79 )
{
unsigned int V_75 , V_80 , V_81 , V_82 , V_83 ;
unsigned int V_84 , V_85 , V_86 ;
unsigned short V_87 , V_88 ;
unsigned char * V_89 , * V_90 , * V_91 ;
struct V_73 * V_92 = NULL , * V_93 ;
struct V_78 V_94 , * V_95 ;
struct V_96 V_97 ;
struct V_98 V_99 ;
struct V_100 V_101 ;
struct V_102 * V_103 ;
int V_21 = 0 ;
if ( ! V_79 -> V_104 )
return - V_50 ;
F_11 ( V_6 , & V_6 -> V_76 ) ;
if ( F_8 ( V_6 ) )
return - V_49 ;
V_95 = V_79 ;
F_52 ( & V_94 ) ;
if ( V_6 -> V_24 && V_6 -> V_24 -> V_105 && ! V_47 ) {
V_75 = 0 ;
F_53 (pktlist, pkt_next)
V_75 += V_92 -> V_77 ;
V_75 = F_54 ( V_75 , V_6 -> V_14 [ V_44 ] -> V_106 ) ;
while ( V_75 > V_107 ) {
V_92 = F_55 ( V_107 ) ;
if ( V_92 == NULL ) {
V_21 = - V_108 ;
goto exit;
}
F_56 ( & V_94 , V_92 ) ;
V_75 -= V_107 ;
}
V_92 = F_55 ( V_75 ) ;
if ( V_92 == NULL ) {
V_21 = - V_108 ;
goto exit;
}
F_56 ( & V_94 , V_92 ) ;
V_95 = & V_94 ;
}
V_80 = V_6 -> V_14 [ V_44 ] -> V_106 ;
V_84 = V_6 -> V_109 ;
V_87 = F_57 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_88 = V_95 -> V_104 ;
V_83 = 0 ;
V_92 = V_95 -> V_110 ;
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
memset ( & V_99 , 0 , sizeof( struct V_98 ) ) ;
memset ( & V_101 , 0 , sizeof( struct V_100 ) ) ;
V_101 . V_111 = V_6 -> V_112 . V_103 ;
V_101 . V_113 = V_80 ;
V_101 . V_23 = V_47 ? V_114 : V_115 ;
V_99 . V_116 = V_117 ;
V_99 . V_118 = V_47 ? 1 << 31 : 0 ;
V_99 . V_118 |= ( V_44 & 0x7 ) << 28 ;
V_99 . V_118 |= 1 << 27 ;
V_99 . V_118 |= ( V_44 == 1 ) ? 1 << 26 : 0 ;
V_99 . V_23 = V_119 | V_120 | V_121 ;
V_97 . V_122 = & V_99 ;
V_97 . V_22 = & V_101 ;
while ( V_88 ) {
V_75 = 0 ;
V_81 = 0 ;
V_103 = V_6 -> V_112 . V_103 ;
while ( V_92 != (struct V_73 * ) V_95 ) {
V_89 = V_92 -> V_22 + V_83 ;
V_82 = V_92 -> V_77 - V_83 ;
if ( V_82 > V_6 -> V_123 )
V_82 = V_6 -> V_123 ;
if ( V_82 > V_84 - V_75 )
V_82 = V_84 - V_75 ;
F_58 ( V_103 , V_89 , V_82 ) ;
V_81 ++ ;
V_103 = F_59 ( V_103 ) ;
V_75 += V_82 ;
V_83 += V_82 ;
if ( V_83 == V_92 -> V_77 ) {
V_83 = 0 ;
V_92 = V_92 -> V_110 ;
}
if ( V_75 >= V_84 || V_81 >= V_87 )
break;
}
V_88 -= V_81 ;
if ( V_75 % V_80 != 0 ) {
F_15 ( L_19 ,
V_75 , V_80 ) ;
V_21 = - V_124 ;
goto exit;
}
V_101 . V_125 = V_81 ;
V_101 . V_126 = V_75 / V_80 ;
V_99 . V_118 |= ( V_45 & 0x1FFFF ) << 9 ;
V_99 . V_118 |= V_101 . V_126 & 0x1FF ;
if ( V_44 == 1 )
V_45 += V_75 ;
F_60 ( & V_101 , V_6 -> V_14 [ V_44 ] -> V_127 ) ;
F_61 ( V_6 -> V_14 [ V_44 ] -> V_127 -> V_128 , & V_97 ) ;
V_21 = V_99 . error ? V_99 . error : V_101 . error ;
if ( V_21 == - V_54 ) {
F_42 ( V_6 -> V_4 ,
V_53 ) ;
break;
} else if ( V_21 != 0 ) {
F_15 ( L_20 ,
V_47 ? L_11 : L_12 , V_21 ) ;
V_21 = - V_49 ;
break;
}
}
if ( V_6 -> V_24 && V_6 -> V_24 -> V_105 && ! V_47 ) {
V_93 = V_94 . V_110 ;
V_85 = 0 ;
F_53 (pktlist, pkt_next) {
V_86 = 0 ;
do {
V_75 = V_93 -> V_77 - V_85 ;
V_75 = F_57 ( T_4 , V_92 -> V_77 - V_86 ,
V_75 ) ;
V_90 = V_93 -> V_22 + V_85 ;
V_91 = V_92 -> V_22 + V_86 ;
memcpy ( V_91 , V_90 , V_75 ) ;
V_85 += V_75 ;
V_86 += V_75 ;
if ( V_85 == V_93 -> V_77 ) {
V_85 = 0 ;
V_93 = V_93 -> V_110 ;
}
if ( V_86 == V_92 -> V_77 )
break;
} while ( ! F_62 ( & V_94 ) );
}
}
exit:
F_63 ( V_6 -> V_112 . V_103 , V_6 -> V_112 . V_129 ) ;
while ( ( V_92 = F_64 ( & V_94 ) ) != NULL )
F_65 ( V_92 ) ;
return V_21 ;
}
int F_66 ( struct V_5 * V_6 , T_3 * V_130 , T_4 V_131 )
{
struct V_73 * V_132 ;
int V_60 ;
V_132 = F_55 ( V_131 ) ;
if ( ! V_132 ) {
F_15 ( L_21 ,
V_131 ) ;
return - V_49 ;
}
V_60 = F_67 ( V_6 , V_132 ) ;
if ( ! V_60 )
memcpy ( V_130 , V_132 -> V_22 , V_131 ) ;
F_65 ( V_132 ) ;
return V_60 ;
}
int F_67 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
T_5 V_45 = V_6 -> V_69 ;
int V_60 = 0 ;
F_3 ( V_26 , L_22 , V_45 , V_74 -> V_77 ) ;
V_60 = F_44 ( V_6 , 4 , & V_45 ) ;
if ( V_60 )
goto V_72;
V_60 = F_47 ( V_6 , V_34 , false , V_45 , V_74 ) ;
V_72:
return V_60 ;
}
int F_68 ( struct V_5 * V_6 ,
struct V_78 * V_133 , T_4 V_134 )
{
struct V_73 * V_135 ;
struct V_73 * V_136 ;
T_5 V_45 = V_6 -> V_69 ;
int V_60 = 0 ;
F_3 ( V_26 , L_22 ,
V_45 , V_133 -> V_104 ) ;
V_60 = F_44 ( V_6 , 4 , & V_45 ) ;
if ( V_60 )
goto V_72;
if ( V_133 -> V_104 == 1 )
V_60 = F_47 ( V_6 , V_34 , false , V_45 ,
V_133 -> V_110 ) ;
else if ( ! V_6 -> V_137 ) {
V_135 = F_55 ( V_134 ) ;
if ( ! V_135 )
return - V_108 ;
V_60 = F_47 ( V_6 , V_34 , false , V_45 ,
V_135 ) ;
if ( V_60 )
goto V_72;
F_53 (pktq, skb) {
memcpy ( V_136 -> V_22 , V_135 -> V_22 , V_136 -> V_77 ) ;
F_69 ( V_135 , V_136 -> V_77 ) ;
}
} else
V_60 = F_51 ( V_6 , V_34 , false , V_45 ,
V_133 ) ;
V_72:
return V_60 ;
}
int F_70 ( struct V_5 * V_6 , T_3 * V_130 , T_4 V_131 )
{
struct V_73 * V_132 ;
T_5 V_45 = V_6 -> V_69 ;
int V_60 ;
V_132 = F_55 ( V_131 ) ;
if ( ! V_132 ) {
F_15 ( L_21 ,
V_131 ) ;
return - V_49 ;
}
memcpy ( V_132 -> V_22 , V_130 , V_131 ) ;
V_60 = F_44 ( V_6 , 4 , & V_45 ) ;
if ( ! V_60 )
V_60 = F_47 ( V_6 , V_34 , true , V_45 ,
V_132 ) ;
F_65 ( V_132 ) ;
return V_60 ;
}
int F_71 ( struct V_5 * V_6 ,
struct V_78 * V_133 )
{
struct V_73 * V_136 ;
T_5 V_45 = V_6 -> V_69 ;
int V_60 ;
F_3 ( V_26 , L_22 , V_45 , V_133 -> V_104 ) ;
V_60 = F_44 ( V_6 , 4 , & V_45 ) ;
if ( V_60 )
return V_60 ;
if ( V_133 -> V_104 == 1 || ! V_6 -> V_137 )
F_53 (pktq, skb) {
V_60 = F_47 ( V_6 , V_34 , true ,
V_45 , V_136 ) ;
if ( V_60 )
break;
}
else
V_60 = F_51 ( V_6 , V_34 , true , V_45 ,
V_133 ) ;
return V_60 ;
}
int
F_72 ( struct V_5 * V_6 , bool V_47 , T_5 V_59 ,
T_3 * V_22 , T_4 V_138 )
{
int V_139 = 0 ;
struct V_73 * V_74 ;
T_5 V_140 ;
T_4 V_141 ;
V_141 = F_57 ( T_4 , V_142 , V_138 ) ;
V_74 = F_73 ( V_141 ) ;
if ( ! V_74 ) {
F_15 ( L_23 , V_141 ) ;
return - V_49 ;
}
V_74 -> V_143 = 0 ;
V_140 = V_59 & V_68 ;
if ( ( V_140 + V_138 ) & V_144 )
V_141 = ( V_142 - V_140 ) ;
else
V_141 = V_138 ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_138 ) {
V_139 = F_43 ( V_6 , V_59 ) ;
if ( V_139 )
break;
F_3 ( V_26 , L_24 ,
V_47 ? L_11 : L_12 , V_141 ,
V_140 , V_59 & V_144 ) ;
V_140 &= V_68 ;
V_140 |= V_70 ;
F_74 ( V_74 , V_141 ) ;
if ( V_47 )
memcpy ( V_74 -> V_22 , V_22 , V_141 ) ;
V_139 = F_47 ( V_6 , V_33 , V_47 ,
V_140 , V_74 ) ;
if ( V_139 ) {
F_15 ( L_25 ) ;
break;
}
if ( ! V_47 )
memcpy ( V_22 , V_74 -> V_22 , V_141 ) ;
F_75 ( V_74 , 0 ) ;
V_138 -= V_141 ;
if ( V_138 ) {
V_22 += V_141 ;
V_59 += V_141 ;
V_140 = 0 ;
V_141 = F_57 ( T_4 , V_142 , V_138 ) ;
}
}
F_76 ( V_74 ) ;
if ( F_43 ( V_6 , V_6 -> V_69 ) )
F_15 ( L_26 ,
V_6 -> V_69 ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
return V_139 ;
}
int F_77 ( struct V_5 * V_6 , T_4 V_44 )
{
char V_145 = ( char ) V_44 ;
F_3 ( V_26 , L_27 ) ;
F_32 ( V_6 , V_56 , V_43 ,
sizeof( V_145 ) , & V_145 , true ) ;
F_3 ( V_26 , L_28 ) ;
return 0 ;
}
static void F_78 ( struct V_5 * V_6 )
{
T_4 V_146 ;
int V_60 ;
if ( ! V_6 -> V_137 )
return;
V_146 = F_79 ( T_4 , V_147 , V_148 ) ;
V_146 += ( V_146 >> 4 ) + 1 ;
F_33 ( V_146 > V_6 -> V_149 ) ;
F_3 ( V_150 , L_29 , V_146 ) ;
V_60 = F_80 ( & V_6 -> V_112 , V_146 , V_151 ) ;
if ( V_60 < 0 ) {
F_15 ( L_30 ) ;
V_6 -> V_137 = false ;
}
V_6 -> V_152 = V_148 ;
}
static int F_81 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 ) {
F_82 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_20 ( V_6 -> V_14 [ 2 ] ) ;
F_83 ( V_6 -> V_14 [ 2 ] ) ;
F_23 ( V_6 -> V_14 [ 2 ] ) ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
F_83 ( V_6 -> V_14 [ 1 ] ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
F_84 ( & V_6 -> V_112 ) ;
V_6 -> V_69 = 0 ;
return 0 ;
}
static int F_85 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_153 * V_128 ;
T_4 V_154 ;
int V_21 = 0 ;
V_6 -> V_155 = 2 ;
F_20 ( V_6 -> V_14 [ 1 ] ) ;
V_21 = F_86 ( V_6 -> V_14 [ 1 ] , V_156 ) ;
if ( V_21 ) {
F_15 ( L_31 ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
goto V_157;
}
V_21 = F_86 ( V_6 -> V_14 [ 2 ] , V_158 ) ;
if ( V_21 ) {
F_15 ( L_32 ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
goto V_157;
}
V_6 -> V_14 [ 2 ] -> V_159 = V_160 ;
V_21 = F_87 ( V_6 -> V_14 [ 1 ] ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_21 ) {
F_15 ( L_33 , V_21 ) ;
goto V_157;
}
V_14 = V_6 -> V_14 [ 2 ] ;
V_128 = V_14 -> V_127 -> V_128 ;
V_6 -> V_137 = V_128 -> V_161 > 1 ;
V_154 = F_57 ( T_4 , V_128 -> V_162 , 511u ) ;
V_6 -> V_109 = F_57 ( T_4 , V_128 -> V_163 ,
V_154 * V_14 -> V_106 ) ;
V_6 -> V_149 = F_57 ( T_4 , V_128 -> V_161 ,
V_164 ) ;
V_6 -> V_123 = V_128 -> V_165 ;
F_78 ( V_6 ) ;
V_6 -> V_11 = F_88 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_21 = - V_166 ;
goto V_157;
}
V_157:
if ( V_21 )
F_81 ( V_6 ) ;
return V_21 ;
}
static int F_89 ( struct V_13 * V_14 ,
const struct V_167 * V_168 )
{
int V_60 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
F_3 ( V_26 , L_27 ) ;
F_3 ( V_26 , L_34 , V_14 -> V_169 ) ;
F_3 ( V_26 , L_35 , V_14 -> V_170 ) ;
F_3 ( V_26 , L_36 , V_14 -> V_171 ) ;
F_3 ( V_26 , L_37 , V_14 -> V_172 ) ;
if ( V_14 -> V_172 == 1 )
return 0 ;
if ( V_14 -> V_172 != 2 )
return - V_166 ;
V_4 = F_90 ( sizeof( struct V_3 ) , V_151 ) ;
if ( ! V_4 )
return - V_108 ;
V_6 = F_90 ( sizeof( struct V_5 ) , V_151 ) ;
if ( ! V_6 ) {
F_91 ( V_4 ) ;
return - V_108 ;
}
V_6 -> V_14 [ 0 ] = F_92 ( V_14 , sizeof( * V_14 ) , V_151 ) ;
V_6 -> V_14 [ 0 ] -> V_172 = 0 ;
V_6 -> V_14 [ 1 ] = V_14 -> V_127 -> V_13 [ 0 ] ;
V_6 -> V_14 [ 2 ] = V_14 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 . V_8 = V_6 ;
V_4 -> V_173 = V_174 ;
F_93 ( & V_14 -> V_15 , V_4 ) ;
F_93 ( & V_6 -> V_14 [ 1 ] -> V_15 , V_4 ) ;
V_6 -> V_15 = & V_6 -> V_14 [ 1 ] -> V_15 ;
V_6 -> V_24 = V_175 ;
F_94 ( & V_6 -> V_17 , false ) ;
F_95 ( & V_6 -> V_48 ) ;
F_95 ( & V_6 -> V_76 ) ;
F_3 ( V_26 , L_38 ) ;
V_60 = F_85 ( V_6 ) ;
if ( V_60 ) {
F_15 ( L_39 , V_60 ) ;
goto V_176;
}
F_3 ( V_26 , L_40 ) ;
return 0 ;
V_176:
F_93 ( & V_14 -> V_15 , NULL ) ;
F_93 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_91 ( V_6 -> V_14 [ 0 ] ) ;
F_91 ( V_6 ) ;
F_91 ( V_4 ) ;
return V_60 ;
}
static void F_96 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_3 ( V_26 , L_27 ) ;
F_3 ( V_26 , L_35 , V_14 -> V_170 ) ;
F_3 ( V_26 , L_36 , V_14 -> V_171 ) ;
F_3 ( V_26 , L_41 , V_14 -> V_172 ) ;
if ( V_14 -> V_172 != 1 && V_14 -> V_172 != 2 )
return;
V_4 = F_2 ( & V_14 -> V_15 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_7 . V_8 ;
F_81 ( V_6 ) ;
F_93 ( & V_6 -> V_14 [ 1 ] -> V_15 , NULL ) ;
F_93 ( & V_6 -> V_14 [ 2 ] -> V_15 , NULL ) ;
F_91 ( V_4 ) ;
F_91 ( V_6 -> V_14 [ 0 ] ) ;
F_91 ( V_6 ) ;
}
F_3 ( V_26 , L_28 ) ;
}
static int F_97 ( struct V_171 * V_15 )
{
T_7 V_177 ;
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
int V_21 = 0 ;
F_3 ( V_26 , L_27 ) ;
V_177 = F_98 ( V_6 -> V_14 [ 1 ] ) ;
if ( ! ( V_177 & V_178 ) ) {
F_15 ( L_42 ) ;
return - V_50 ;
}
F_94 ( & V_6 -> V_17 , true ) ;
V_21 = F_99 ( V_6 -> V_14 [ 1 ] , V_178 ) ;
if ( V_21 ) {
F_15 ( L_43 ) ;
F_94 ( & V_6 -> V_17 , false ) ;
return V_21 ;
}
F_100 ( V_6 -> V_11 , 0 ) ;
return V_21 ;
}
static int F_101 ( struct V_171 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_26 , L_27 ) ;
F_100 ( V_6 -> V_11 , V_179 ) ;
F_94 ( & V_6 -> V_17 , false ) ;
return 0 ;
}
static int T_8 F_102 ( struct V_180 * V_181 )
{
F_3 ( V_26 , L_27 ) ;
V_175 = F_103 ( & V_181 -> V_15 ) ;
if ( V_175 -> V_182 )
V_175 -> V_182 () ;
return 0 ;
}
static int F_104 ( struct V_180 * V_181 )
{
F_3 ( V_26 , L_27 ) ;
if ( V_175 -> V_183 )
V_175 -> V_183 () ;
F_105 ( & V_184 ) ;
return 0 ;
}
void F_106 ( void )
{
int V_21 ;
V_21 = F_107 ( & V_184 ) ;
if ( V_21 )
F_15 ( L_44 , V_21 ) ;
}
void F_108 ( void )
{
F_3 ( V_26 , L_27 ) ;
if ( V_175 )
F_109 ( & V_185 ) ;
else
F_105 ( & V_184 ) ;
}
void T_8 F_110 ( void )
{
int V_21 ;
F_3 ( V_26 , L_27 ) ;
V_21 = F_111 ( & V_185 , F_102 ) ;
if ( V_21 == - V_166 )
F_3 ( V_26 , L_45 ) ;
}
