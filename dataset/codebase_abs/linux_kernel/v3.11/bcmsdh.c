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
unsigned long V_18 ;
if ( ( V_6 -> V_19 ) && ( V_6 -> V_19 -> V_20 ) ) {
F_3 ( V_21 , L_3 ,
V_6 -> V_19 -> V_22 ) ;
V_16 = F_9 ( V_6 -> V_19 -> V_22 ,
F_1 ,
V_6 -> V_19 -> V_23 ,
L_4 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
if ( V_16 != 0 ) {
F_10 ( L_5 , V_16 ) ;
return V_16 ;
}
V_6 -> V_24 = true ;
F_11 ( & V_6 -> V_25 ) ;
F_12 ( & V_6 -> V_25 , V_18 ) ;
V_6 -> V_10 = true ;
F_13 ( & V_6 -> V_25 , V_18 ) ;
V_16 = F_14 ( V_6 -> V_19 -> V_22 ) ;
if ( V_16 != 0 ) {
F_10 ( L_6 , V_16 ) ;
return V_16 ;
}
V_6 -> V_26 = true ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
V_17 = F_16 ( V_6 , V_27 , & V_16 ) ;
V_17 |= 1 << V_28 | 1 << V_29 | 1 ;
F_17 ( V_6 , V_27 , V_17 , & V_16 ) ;
V_17 = V_30 | V_31 ;
if ( V_6 -> V_19 -> V_23 & V_32 )
V_17 |= V_33 ;
F_17 ( V_6 , V_34 , V_17 , & V_16 ) ;
F_18 ( V_6 -> V_14 [ 1 ] ) ;
} else {
F_3 ( V_21 , L_7 ) ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_19 ( V_6 -> V_14 [ 1 ] , F_6 ) ;
F_19 ( V_6 -> V_14 [ 2 ] , F_7 ) ;
F_18 ( V_6 -> V_14 [ 1 ] ) ;
}
return 0 ;
}
int F_20 ( struct V_5 * V_6 )
{
F_3 ( V_21 , L_7 ) ;
if ( ( V_6 -> V_19 ) && ( V_6 -> V_19 -> V_20 ) ) {
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_17 ( V_6 , V_34 , 0 , NULL ) ;
F_17 ( V_6 , V_27 , 0 , NULL ) ;
F_18 ( V_6 -> V_14 [ 1 ] ) ;
if ( V_6 -> V_24 ) {
V_6 -> V_24 = false ;
if ( V_6 -> V_26 ) {
F_21 ( V_6 -> V_19 -> V_22 ) ;
V_6 -> V_26 = false ;
}
F_22 ( V_6 -> V_19 -> V_22 ,
& V_6 -> V_14 [ 1 ] -> V_15 ) ;
V_6 -> V_10 = false ;
}
} else {
F_15 ( V_6 -> V_14 [ 1 ] ) ;
F_23 ( V_6 -> V_14 [ 2 ] ) ;
F_23 ( V_6 -> V_14 [ 1 ] ) ;
F_18 ( V_6 -> V_14 [ 1 ] ) ;
}
return 0 ;
}
static int
F_24 ( struct V_5 * V_6 , T_3 V_35 )
{
int V_36 = 0 , V_37 ;
T_2 V_38 [ 3 ] ;
T_4 V_39 ;
V_38 [ 0 ] = ( V_35 >> 8 ) & V_40 ;
V_38 [ 1 ] = ( V_35 >> 16 ) & V_41 ;
V_38 [ 2 ] = ( V_35 >> 24 ) & V_42 ;
for ( V_37 = 0 ; V_37 < 3 ; V_37 ++ ) {
V_39 = 0 ;
do {
if ( V_39 )
F_25 ( 1000 , 2000 ) ;
V_36 = F_26 ( V_6 , V_43 ,
V_28 , V_44 + V_37 ,
& V_38 [ V_37 ] ) ;
} while ( V_36 != 0 && V_39 ++ < V_45 );
if ( V_36 ) {
F_10 ( L_8 ,
V_44 + V_37 ) ;
break;
}
}
return V_36 ;
}
static int
F_27 ( struct V_5 * V_6 , T_5 V_46 , T_3 * V_38 )
{
T_5 V_47 = * V_38 & ~ V_48 ;
int V_36 = 0 ;
if ( V_47 != V_6 -> V_49 ) {
V_36 = F_24 ( V_6 , V_47 ) ;
if ( V_36 )
return V_36 ;
V_6 -> V_49 = V_47 ;
}
* V_38 &= V_48 ;
if ( V_46 == 4 )
* V_38 |= V_50 ;
return 0 ;
}
int
F_28 ( struct V_5 * V_6 , T_3 V_38 ,
void * V_17 , bool V_51 )
{
T_2 V_52 , V_53 ;
T_4 V_39 = 0 ;
int V_16 ;
if ( ( V_38 & ~ V_54 ) == 0 ) {
V_52 = V_55 ;
V_53 = 1 ;
} else if ( ( V_38 & ~ V_56 ) == 0 ) {
V_52 = V_28 ;
V_53 = 1 ;
} else {
V_52 = V_28 ;
V_53 = 4 ;
F_27 ( V_6 , V_53 , & V_38 ) ;
}
do {
if ( ! V_51 )
memset ( V_17 , 0 , V_53 ) ;
if ( V_39 )
F_25 ( 1000 , 2000 ) ;
if ( V_53 == 1 )
V_16 = F_26 ( V_6 , V_51 ,
V_52 , V_38 , V_17 ) ;
else
V_16 = F_29 ( V_6 , V_51 ,
V_52 , V_38 , V_17 , 4 ) ;
} while ( V_16 != 0 && V_39 ++ < V_45 );
if ( V_16 != 0 )
F_10 ( L_9 , V_16 ) ;
return V_16 ;
}
T_2 F_16 ( struct V_5 * V_6 , T_3 V_38 , int * V_16 )
{
T_2 V_17 ;
int V_57 ;
F_3 ( V_21 , L_10 , V_38 ) ;
V_57 = F_28 ( V_6 , V_38 , & V_17 , false ) ;
F_3 ( V_21 , L_11 , V_17 ) ;
if ( V_16 )
* V_16 = V_57 ;
return V_17 ;
}
T_3 F_30 ( struct V_5 * V_6 , T_3 V_38 , int * V_16 )
{
T_3 V_17 ;
int V_57 ;
F_3 ( V_21 , L_10 , V_38 ) ;
V_57 = F_28 ( V_6 , V_38 , & V_17 , false ) ;
F_3 ( V_21 , L_12 , V_17 ) ;
if ( V_16 )
* V_16 = V_57 ;
return V_17 ;
}
void F_17 ( struct V_5 * V_6 , T_3 V_38 ,
T_2 V_17 , int * V_16 )
{
int V_57 ;
F_3 ( V_21 , L_13 , V_38 , V_17 ) ;
V_57 = F_28 ( V_6 , V_38 , & V_17 , true ) ;
if ( V_16 )
* V_16 = V_57 ;
}
void F_31 ( struct V_5 * V_6 , T_3 V_38 ,
T_3 V_17 , int * V_16 )
{
int V_57 ;
F_3 ( V_21 , L_14 , V_38 , V_17 ) ;
V_57 = F_28 ( V_6 , V_38 , & V_17 , true ) ;
if ( V_16 )
* V_16 = V_57 ;
}
static int F_32 ( struct V_5 * V_6 , T_5 V_58 ,
bool V_51 , T_3 V_38 , struct V_59 * V_60 )
{
unsigned int V_61 , V_62 , V_63 , V_64 , V_65 ;
unsigned int V_66 , V_67 , V_68 , V_69 ;
unsigned short V_70 , V_71 ;
unsigned char * V_72 , * V_73 , * V_74 ;
struct V_75 * V_76 = NULL , * V_77 ;
struct V_59 V_78 , * V_79 ;
struct V_80 V_81 ;
struct V_82 V_83 ;
struct V_84 V_85 ;
struct V_86 V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
int V_16 = 0 ;
if ( ! V_60 -> V_92 )
return - V_93 ;
F_33 ( V_6 , & V_6 -> V_94 ) ;
if ( F_34 ( V_6 ) )
return - V_95 ;
if ( V_60 -> V_92 == 1 ) {
V_76 = V_60 -> V_96 ;
V_61 = V_76 -> V_97 + 3 ;
V_61 &= ( T_5 ) ~ 3 ;
if ( V_51 )
return F_35 ( V_6 -> V_14 [ V_58 ] , V_38 ,
( ( T_2 * ) ( V_76 -> V_17 ) ) ,
V_61 ) ;
else if ( V_58 == 1 )
return F_36 ( V_6 -> V_14 [ V_58 ] ,
( ( T_2 * ) ( V_76 -> V_17 ) ) ,
V_38 , V_61 ) ;
else
return F_37 ( V_6 -> V_14 [ V_58 ] ,
( ( T_2 * ) ( V_76 -> V_17 ) ) , V_38 ,
V_61 ) ;
}
V_79 = V_60 ;
F_38 ( & V_78 ) ;
if ( V_6 -> V_19 && V_6 -> V_19 -> V_98 && ! V_51 ) {
V_61 = 0 ;
F_39 (pktlist, pkt_next)
V_61 += V_76 -> V_97 ;
V_61 = F_40 ( V_61 , V_6 -> V_14 [ V_58 ] -> V_99 ) ;
while ( V_61 > V_100 ) {
V_76 = F_41 ( V_100 ) ;
if ( V_76 == NULL ) {
V_16 = - V_101 ;
goto exit;
}
F_42 ( & V_78 , V_76 ) ;
V_61 -= V_100 ;
}
V_76 = F_41 ( V_61 ) ;
if ( V_76 == NULL ) {
V_16 = - V_101 ;
goto exit;
}
F_42 ( & V_78 , V_76 ) ;
V_79 = & V_78 ;
}
V_91 = V_6 -> V_14 [ V_58 ] -> V_102 -> V_91 ;
V_62 = V_6 -> V_14 [ V_58 ] -> V_99 ;
V_66 = F_43 (unsigned int, host->max_blk_count, 511u ) ;
V_67 = F_43 (unsigned int, host->max_req_size,
max_blks * func_blk_sz) ;
V_70 = F_43 (unsigned short, host->max_segs, SG_MAX_SINGLE_ALLOC) ;
V_70 = F_43 (unsigned short, max_seg_sz, target_list->qlen) ;
V_71 = V_79 -> V_92 ;
V_65 = 0 ;
V_76 = V_79 -> V_96 ;
if ( F_44 ( & V_87 , V_70 , V_103 ) ) {
V_16 = - V_101 ;
goto exit;
}
while ( V_71 ) {
V_61 = 0 ;
V_63 = 0 ;
memset ( & V_81 , 0 , sizeof( struct V_80 ) ) ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_89 = V_87 . V_89 ;
while ( V_76 != (struct V_75 * ) V_79 ) {
V_72 = V_76 -> V_17 + V_65 ;
V_64 = V_76 -> V_97 - V_65 ;
if ( V_64 > V_91 -> V_104 )
V_64 = V_91 -> V_104 ;
if ( V_64 > V_67 - V_61 )
V_64 = V_67 - V_61 ;
F_45 ( V_89 , V_72 , V_64 ) ;
V_63 ++ ;
V_89 = F_46 ( V_89 ) ;
V_61 += V_64 ;
V_65 += V_64 ;
if ( V_65 == V_76 -> V_97 ) {
V_65 = 0 ;
V_76 = V_76 -> V_96 ;
}
if ( V_61 >= V_67 || V_63 >= V_70 )
break;
}
V_71 -= V_63 ;
if ( V_61 % V_62 != 0 ) {
F_10 ( L_15 ,
V_61 , V_62 ) ;
V_16 = - V_105 ;
goto exit;
}
V_85 . V_106 = V_87 . V_89 ;
V_85 . V_107 = V_63 ;
V_85 . V_108 = V_62 ;
V_85 . V_109 = V_61 / V_62 ;
V_85 . V_18 = V_51 ? V_110 : V_111 ;
V_83 . V_112 = V_113 ;
V_83 . V_114 = V_51 ? 1 << 31 : 0 ;
V_83 . V_114 |= ( V_58 & 0x7 ) << 28 ;
V_83 . V_114 |= 1 << 27 ;
V_83 . V_114 |= ( V_58 == 1 ) ? 1 << 26 : 0 ;
V_83 . V_114 |= ( V_38 & 0x1FFFF ) << 9 ;
V_83 . V_114 |= V_85 . V_109 & 0x1FF ;
V_83 . V_18 = V_115 | V_116 | V_117 ;
V_81 . V_118 = & V_83 ;
V_81 . V_17 = & V_85 ;
if ( V_58 == 1 )
V_38 += V_61 ;
F_47 ( & V_85 , V_6 -> V_14 [ V_58 ] -> V_102 ) ;
F_48 ( V_91 , & V_81 ) ;
V_16 = V_83 . error ? V_83 . error : V_85 . error ;
if ( V_16 != 0 ) {
F_10 ( L_16 ,
V_51 ? L_17 : L_18 , V_16 ) ;
V_16 = - V_95 ;
break;
}
}
if ( V_6 -> V_19 && V_6 -> V_19 -> V_98 && ! V_51 ) {
V_77 = V_78 . V_96 ;
V_68 = 0 ;
F_39 (pktlist, pkt_next) {
V_69 = 0 ;
do {
V_61 = V_77 -> V_97 - V_68 ;
V_61 = F_43 ( T_5 , V_76 -> V_97 - V_69 ,
V_61 ) ;
V_73 = V_77 -> V_17 + V_68 ;
V_74 = V_76 -> V_17 + V_69 ;
memcpy ( V_74 , V_73 , V_61 ) ;
V_68 += V_61 ;
V_69 += V_61 ;
if ( V_68 == V_77 -> V_97 ) {
V_68 = 0 ;
V_77 = V_77 -> V_96 ;
}
if ( V_69 == V_76 -> V_97 )
break;
} while ( ! F_49 ( & V_78 ) );
}
}
exit:
F_50 ( & V_87 ) ;
while ( ( V_76 = F_51 ( & V_78 ) ) != NULL )
F_52 ( V_76 ) ;
return V_16 ;
}
int
F_53 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_58 ,
T_5 V_18 , T_2 * V_119 , T_5 V_120 )
{
struct V_75 * V_121 ;
int V_36 ;
V_121 = F_41 ( V_120 ) ;
if ( ! V_121 ) {
F_10 ( L_19 ,
V_120 ) ;
return - V_95 ;
}
V_36 = F_54 ( V_6 , V_38 , V_58 , V_18 , V_121 ) ;
if ( ! V_36 )
memcpy ( V_119 , V_121 -> V_17 , V_120 ) ;
F_52 ( V_121 ) ;
return V_36 ;
}
int
F_54 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_58 ,
T_5 V_18 , struct V_75 * V_122 )
{
T_5 V_46 ;
int V_36 = 0 ;
struct V_59 V_123 ;
F_3 ( V_21 , L_20 ,
V_58 , V_38 , V_122 -> V_97 ) ;
V_46 = ( V_18 & V_124 ) ? 4 : 2 ;
V_36 = F_27 ( V_6 , V_46 , & V_38 ) ;
if ( V_36 )
goto V_125;
F_55 ( & V_123 ) ;
F_56 ( & V_123 , V_122 ) ;
V_36 = F_32 ( V_6 , V_58 , false , V_38 , & V_123 ) ;
F_57 ( & V_123 ) ;
V_125:
return V_36 ;
}
int F_58 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_58 ,
T_5 V_18 , struct V_59 * V_126 )
{
T_5 V_127 ;
T_5 V_46 ;
int V_36 = 0 ;
F_3 ( V_21 , L_20 ,
V_58 , V_38 , V_126 -> V_92 ) ;
V_46 = ( V_18 & V_124 ) ? 4 : 2 ;
V_36 = F_27 ( V_6 , V_46 , & V_38 ) ;
if ( V_36 )
goto V_125;
V_127 = ( V_18 & V_128 ) ? V_129 : V_130 ;
V_36 = F_32 ( V_6 , V_58 , false , V_38 , V_126 ) ;
V_125:
return V_36 ;
}
int
F_59 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_58 ,
T_5 V_18 , T_2 * V_119 , T_5 V_120 )
{
struct V_75 * V_121 ;
int V_36 ;
V_121 = F_41 ( V_120 ) ;
if ( ! V_121 ) {
F_10 ( L_19 ,
V_120 ) ;
return - V_95 ;
}
memcpy ( V_121 -> V_17 , V_119 , V_120 ) ;
V_36 = F_60 ( V_6 , V_38 , V_58 , V_18 , V_121 ) ;
F_52 ( V_121 ) ;
return V_36 ;
}
int
F_60 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_58 ,
T_5 V_18 , struct V_75 * V_122 )
{
T_5 V_46 ;
int V_36 = 0 ;
struct V_59 V_123 ;
F_3 ( V_21 , L_20 ,
V_58 , V_38 , V_122 -> V_97 ) ;
V_46 = ( V_18 & V_124 ) ? 4 : 2 ;
F_27 ( V_6 , V_46 , & V_38 ) ;
F_55 ( & V_123 ) ;
F_56 ( & V_123 , V_122 ) ;
V_36 = F_32 ( V_6 , V_58 , true , V_38 , & V_123 ) ;
F_57 ( & V_123 ) ;
return V_36 ;
}
int
F_61 ( struct V_5 * V_6 , bool V_51 , T_3 V_35 ,
T_2 * V_17 , T_5 V_131 )
{
int V_132 = 0 ;
struct V_75 * V_122 ;
T_3 V_133 ;
T_5 V_134 ;
struct V_59 V_123 ;
V_134 = F_43 ( T_5 , V_135 , V_131 ) ;
V_122 = F_62 ( V_134 ) ;
if ( ! V_122 ) {
F_10 ( L_21 , V_134 ) ;
return - V_95 ;
}
V_122 -> V_136 = 0 ;
F_55 ( & V_123 ) ;
V_133 = V_35 & V_48 ;
if ( ( V_133 + V_131 ) & V_137 )
V_134 = ( V_135 - V_133 ) ;
else
V_134 = V_131 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_131 ) {
V_132 = F_24 ( V_6 , V_35 ) ;
if ( V_132 )
break;
F_3 ( V_21 , L_22 ,
V_51 ? L_17 : L_18 , V_134 ,
V_133 , V_35 & V_137 ) ;
V_133 &= V_48 ;
V_133 |= V_50 ;
F_63 ( V_122 , V_134 ) ;
if ( V_51 )
memcpy ( V_122 -> V_17 , V_17 , V_134 ) ;
F_56 ( & V_123 , V_122 ) ;
V_132 = F_32 ( V_6 , V_28 , V_51 ,
V_133 , & V_123 ) ;
F_57 ( & V_123 ) ;
if ( V_132 ) {
F_10 ( L_23 ) ;
break;
}
if ( ! V_51 )
memcpy ( V_17 , V_122 -> V_17 , V_134 ) ;
F_64 ( V_122 , V_134 ) ;
V_131 -= V_134 ;
if ( V_131 ) {
V_17 += V_134 ;
V_35 += V_134 ;
V_133 = 0 ;
V_134 = F_43 ( T_5 , V_135 , V_131 ) ;
}
}
F_65 ( V_122 ) ;
if ( F_24 ( V_6 , V_6 -> V_49 ) )
F_10 ( L_24 ,
V_6 -> V_49 ) ;
F_18 ( V_6 -> V_14 [ 1 ] ) ;
return V_132 ;
}
int F_66 ( struct V_5 * V_6 , T_5 V_58 )
{
char V_138 = ( char ) V_58 ;
F_3 ( V_21 , L_25 ) ;
F_26 ( V_6 , V_43 , V_55 ,
V_139 , & V_138 ) ;
F_3 ( V_21 , L_26 ) ;
return 0 ;
}
int F_67 ( struct V_5 * V_6 )
{
T_3 V_140 = 0 ;
int V_16 = 0 ;
V_16 = F_68 ( V_6 ) ;
if ( V_16 )
goto V_141;
V_140 = V_142 ;
V_6 -> V_11 = F_69 ( V_140 , V_6 ) ;
if ( ! V_6 -> V_11 ) {
F_10 ( L_27 ) ;
V_16 = - V_143 ;
goto V_141;
}
V_141:
if ( V_16 )
F_70 ( V_6 ) ;
return V_16 ;
}
int F_70 ( struct V_5 * V_6 )
{
V_6 -> V_4 -> V_144 = V_145 ;
if ( V_6 -> V_11 ) {
F_71 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_72 ( V_6 ) ;
V_6 -> V_49 = 0 ;
return 0 ;
}
void F_73 ( struct V_5 * V_6 , bool V_146 )
{
if ( V_146 )
F_74 ( V_6 -> V_11 , V_147 ) ;
else
F_74 ( V_6 -> V_11 , 0 ) ;
}
