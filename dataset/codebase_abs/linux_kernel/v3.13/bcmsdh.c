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
V_16 = F_27 ( V_6 , V_53 , & V_38 ) ;
if ( V_16 )
goto V_57;
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
V_57:
if ( V_16 != 0 )
F_10 ( L_9 , V_16 ) ;
return V_16 ;
}
T_2 F_16 ( struct V_5 * V_6 , T_3 V_38 , int * V_16 )
{
T_2 V_17 ;
int V_58 ;
F_3 ( V_21 , L_10 , V_38 ) ;
V_58 = F_28 ( V_6 , V_38 , & V_17 , false ) ;
F_3 ( V_21 , L_11 , V_17 ) ;
if ( V_16 )
* V_16 = V_58 ;
return V_17 ;
}
T_3 F_30 ( struct V_5 * V_6 , T_3 V_38 , int * V_16 )
{
T_3 V_17 ;
int V_58 ;
F_3 ( V_21 , L_10 , V_38 ) ;
V_58 = F_28 ( V_6 , V_38 , & V_17 , false ) ;
F_3 ( V_21 , L_12 , V_17 ) ;
if ( V_16 )
* V_16 = V_58 ;
return V_17 ;
}
void F_17 ( struct V_5 * V_6 , T_3 V_38 ,
T_2 V_17 , int * V_16 )
{
int V_58 ;
F_3 ( V_21 , L_13 , V_38 , V_17 ) ;
V_58 = F_28 ( V_6 , V_38 , & V_17 , true ) ;
if ( V_16 )
* V_16 = V_58 ;
}
void F_31 ( struct V_5 * V_6 , T_3 V_38 ,
T_3 V_17 , int * V_16 )
{
int V_58 ;
F_3 ( V_21 , L_14 , V_38 , V_17 ) ;
V_58 = F_28 ( V_6 , V_38 , & V_17 , true ) ;
if ( V_16 )
* V_16 = V_58 ;
}
static int F_32 ( struct V_5 * V_6 , T_5 V_59 ,
bool V_51 , T_3 V_38 , struct V_60 * V_61 )
{
unsigned int V_62 ;
F_33 ( V_6 , & V_6 -> V_63 ) ;
if ( F_34 ( V_6 ) )
return - V_64 ;
V_62 = V_61 -> V_65 + 3 ;
V_62 &= ( T_5 ) ~ 3 ;
if ( V_51 )
return F_35 ( V_6 -> V_14 [ V_59 ] , V_38 ,
( ( T_2 * ) ( V_61 -> V_17 ) ) ,
V_62 ) ;
else if ( V_59 == 1 )
return F_36 ( V_6 -> V_14 [ V_59 ] ,
( ( T_2 * ) ( V_61 -> V_17 ) ) ,
V_38 , V_62 ) ;
else
return F_37 ( V_6 -> V_14 [ V_59 ] ,
( ( T_2 * ) ( V_61 -> V_17 ) ) , V_38 ,
V_62 ) ;
}
static int F_38 ( struct V_5 * V_6 , T_5 V_59 ,
bool V_51 , T_3 V_38 ,
struct V_66 * V_67 )
{
unsigned int V_62 , V_68 , V_69 , V_70 , V_71 ;
unsigned int V_72 , V_73 , V_74 ;
unsigned short V_75 , V_76 ;
unsigned char * V_77 , * V_78 , * V_79 ;
struct V_60 * V_80 = NULL , * V_81 ;
struct V_66 V_82 , * V_83 ;
struct V_84 V_85 ;
struct V_86 V_87 ;
struct V_88 V_89 ;
struct V_90 V_91 ;
struct V_92 * V_93 ;
int V_16 = 0 ;
if ( ! V_67 -> V_94 )
return - V_95 ;
F_33 ( V_6 , & V_6 -> V_63 ) ;
if ( F_34 ( V_6 ) )
return - V_64 ;
V_83 = V_67 ;
F_39 ( & V_82 ) ;
if ( V_6 -> V_19 && V_6 -> V_19 -> V_96 && ! V_51 ) {
V_62 = 0 ;
F_40 (pktlist, pkt_next)
V_62 += V_80 -> V_65 ;
V_62 = F_41 ( V_62 , V_6 -> V_14 [ V_59 ] -> V_97 ) ;
while ( V_62 > V_98 ) {
V_80 = F_42 ( V_98 ) ;
if ( V_80 == NULL ) {
V_16 = - V_99 ;
goto exit;
}
F_43 ( & V_82 , V_80 ) ;
V_62 -= V_98 ;
}
V_80 = F_42 ( V_62 ) ;
if ( V_80 == NULL ) {
V_16 = - V_99 ;
goto exit;
}
F_43 ( & V_82 , V_80 ) ;
V_83 = & V_82 ;
}
V_68 = V_6 -> V_14 [ V_59 ] -> V_97 ;
V_72 = V_6 -> V_100 ;
V_75 = F_44 (unsigned short, sdiodev->max_segment_count,
target_list->qlen) ;
V_76 = V_83 -> V_94 ;
V_71 = 0 ;
V_80 = V_83 -> V_101 ;
if ( F_45 ( & V_91 , V_75 , V_102 ) ) {
V_16 = - V_99 ;
goto exit;
}
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
memset ( & V_87 , 0 , sizeof( struct V_86 ) ) ;
memset ( & V_89 , 0 , sizeof( struct V_88 ) ) ;
V_89 . V_103 = V_91 . V_93 ;
V_89 . V_104 = V_68 ;
V_89 . V_18 = V_51 ? V_105 : V_106 ;
V_87 . V_107 = V_108 ;
V_87 . V_109 = V_51 ? 1 << 31 : 0 ;
V_87 . V_109 |= ( V_59 & 0x7 ) << 28 ;
V_87 . V_109 |= 1 << 27 ;
V_87 . V_109 |= ( V_59 == 1 ) ? 1 << 26 : 0 ;
V_87 . V_18 = V_110 | V_111 | V_112 ;
V_85 . V_113 = & V_87 ;
V_85 . V_17 = & V_89 ;
while ( V_76 ) {
V_62 = 0 ;
V_69 = 0 ;
V_93 = V_91 . V_93 ;
while ( V_80 != (struct V_60 * ) V_83 ) {
V_77 = V_80 -> V_17 + V_71 ;
V_70 = V_80 -> V_65 - V_71 ;
if ( V_70 > V_6 -> V_114 )
V_70 = V_6 -> V_114 ;
if ( V_70 > V_72 - V_62 )
V_70 = V_72 - V_62 ;
F_46 ( V_93 , V_77 , V_70 ) ;
V_69 ++ ;
V_93 = F_47 ( V_93 ) ;
V_62 += V_70 ;
V_71 += V_70 ;
if ( V_71 == V_80 -> V_65 ) {
V_71 = 0 ;
V_80 = V_80 -> V_101 ;
}
if ( V_62 >= V_72 || V_69 >= V_75 )
break;
}
V_76 -= V_69 ;
if ( V_62 % V_68 != 0 ) {
F_10 ( L_15 ,
V_62 , V_68 ) ;
V_16 = - V_115 ;
goto exit;
}
V_89 . V_116 = V_69 ;
V_89 . V_117 = V_62 / V_68 ;
V_87 . V_109 |= ( V_38 & 0x1FFFF ) << 9 ;
V_87 . V_109 |= V_89 . V_117 & 0x1FF ;
if ( V_59 == 1 )
V_38 += V_62 ;
F_48 ( & V_89 , V_6 -> V_14 [ V_59 ] -> V_118 ) ;
F_49 ( V_6 -> V_14 [ V_59 ] -> V_118 -> V_119 , & V_85 ) ;
V_16 = V_87 . error ? V_87 . error : V_89 . error ;
if ( V_16 != 0 ) {
F_10 ( L_16 ,
V_51 ? L_17 : L_18 , V_16 ) ;
V_16 = - V_64 ;
break;
}
}
if ( V_6 -> V_19 && V_6 -> V_19 -> V_96 && ! V_51 ) {
V_81 = V_82 . V_101 ;
V_73 = 0 ;
F_40 (pktlist, pkt_next) {
V_74 = 0 ;
do {
V_62 = V_81 -> V_65 - V_73 ;
V_62 = F_44 ( T_5 , V_80 -> V_65 - V_74 ,
V_62 ) ;
V_78 = V_81 -> V_17 + V_73 ;
V_79 = V_80 -> V_17 + V_74 ;
memcpy ( V_79 , V_78 , V_62 ) ;
V_73 += V_62 ;
V_74 += V_62 ;
if ( V_73 == V_81 -> V_65 ) {
V_73 = 0 ;
V_81 = V_81 -> V_101 ;
}
if ( V_74 == V_80 -> V_65 )
break;
} while ( ! F_50 ( & V_82 ) );
}
}
exit:
F_51 ( & V_91 ) ;
while ( ( V_80 = F_52 ( & V_82 ) ) != NULL )
F_53 ( V_80 ) ;
return V_16 ;
}
int
F_54 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_59 ,
T_5 V_18 , T_2 * V_120 , T_5 V_121 )
{
struct V_60 * V_122 ;
int V_36 ;
V_122 = F_42 ( V_121 ) ;
if ( ! V_122 ) {
F_10 ( L_19 ,
V_121 ) ;
return - V_64 ;
}
V_36 = F_55 ( V_6 , V_38 , V_59 , V_18 , V_122 ) ;
if ( ! V_36 )
memcpy ( V_120 , V_122 -> V_17 , V_121 ) ;
F_53 ( V_122 ) ;
return V_36 ;
}
int
F_55 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_59 ,
T_5 V_18 , struct V_60 * V_61 )
{
T_5 V_46 ;
int V_36 = 0 ;
F_3 ( V_21 , L_20 ,
V_59 , V_38 , V_61 -> V_65 ) ;
V_46 = ( V_18 & V_123 ) ? 4 : 2 ;
V_36 = F_27 ( V_6 , V_46 , & V_38 ) ;
if ( V_36 )
goto V_57;
V_36 = F_32 ( V_6 , V_59 , false , V_38 , V_61 ) ;
V_57:
return V_36 ;
}
int F_56 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_59 ,
T_5 V_18 , struct V_66 * V_124 , T_5 V_125 )
{
struct V_60 * V_126 ;
struct V_60 * V_127 ;
T_5 V_46 ;
int V_36 = 0 ;
F_3 ( V_21 , L_20 ,
V_59 , V_38 , V_124 -> V_94 ) ;
V_46 = ( V_18 & V_123 ) ? 4 : 2 ;
V_36 = F_27 ( V_6 , V_46 , & V_38 ) ;
if ( V_36 )
goto V_57;
if ( V_124 -> V_94 == 1 )
V_36 = F_32 ( V_6 , V_59 , false , V_38 , V_124 -> V_101 ) ;
else if ( ! V_6 -> V_128 ) {
V_126 = F_42 ( V_125 ) ;
if ( ! V_126 )
return - V_99 ;
V_36 = F_32 ( V_6 , V_59 , false , V_38 , V_126 ) ;
if ( V_36 )
goto V_57;
F_40 (pktq, skb) {
memcpy ( V_127 -> V_17 , V_126 -> V_17 , V_127 -> V_65 ) ;
F_57 ( V_126 , V_127 -> V_65 ) ;
}
} else
V_36 = F_38 ( V_6 , V_59 , false , V_38 , V_124 ) ;
V_57:
return V_36 ;
}
int
F_58 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_59 ,
T_5 V_18 , T_2 * V_120 , T_5 V_121 )
{
struct V_60 * V_122 ;
T_5 V_46 ;
int V_36 ;
V_122 = F_42 ( V_121 ) ;
if ( ! V_122 ) {
F_10 ( L_19 ,
V_121 ) ;
return - V_64 ;
}
memcpy ( V_122 -> V_17 , V_120 , V_121 ) ;
V_46 = ( V_18 & V_123 ) ? 4 : 2 ;
V_36 = F_27 ( V_6 , V_46 , & V_38 ) ;
if ( ! V_36 )
V_36 = F_32 ( V_6 , V_59 , true , V_38 , V_122 ) ;
F_53 ( V_122 ) ;
return V_36 ;
}
int
F_59 ( struct V_5 * V_6 , T_3 V_38 , T_5 V_59 ,
T_5 V_18 , struct V_66 * V_124 )
{
struct V_60 * V_127 ;
T_5 V_46 ;
int V_36 ;
F_3 ( V_21 , L_20 ,
V_59 , V_38 , V_124 -> V_94 ) ;
V_46 = ( V_18 & V_123 ) ? 4 : 2 ;
V_36 = F_27 ( V_6 , V_46 , & V_38 ) ;
if ( V_36 )
return V_36 ;
if ( V_124 -> V_94 == 1 || ! V_6 -> V_128 )
F_40 (pktq, skb) {
V_36 = F_32 ( V_6 , V_59 , true , V_38 , V_127 ) ;
if ( V_36 )
break;
}
else
V_36 = F_38 ( V_6 , V_59 , true , V_38 , V_124 ) ;
return V_36 ;
}
int
F_60 ( struct V_5 * V_6 , bool V_51 , T_3 V_35 ,
T_2 * V_17 , T_5 V_129 )
{
int V_130 = 0 ;
struct V_60 * V_61 ;
T_3 V_131 ;
T_5 V_132 ;
V_132 = F_44 ( T_5 , V_133 , V_129 ) ;
V_61 = F_61 ( V_132 ) ;
if ( ! V_61 ) {
F_10 ( L_21 , V_132 ) ;
return - V_64 ;
}
V_61 -> V_134 = 0 ;
V_131 = V_35 & V_48 ;
if ( ( V_131 + V_129 ) & V_135 )
V_132 = ( V_133 - V_131 ) ;
else
V_132 = V_129 ;
F_15 ( V_6 -> V_14 [ 1 ] ) ;
while ( V_129 ) {
V_130 = F_24 ( V_6 , V_35 ) ;
if ( V_130 )
break;
F_3 ( V_21 , L_22 ,
V_51 ? L_17 : L_18 , V_132 ,
V_131 , V_35 & V_135 ) ;
V_131 &= V_48 ;
V_131 |= V_50 ;
F_62 ( V_61 , V_132 ) ;
if ( V_51 )
memcpy ( V_61 -> V_17 , V_17 , V_132 ) ;
V_130 = F_32 ( V_6 , V_28 , V_51 ,
V_131 , V_61 ) ;
if ( V_130 ) {
F_10 ( L_23 ) ;
break;
}
if ( ! V_51 )
memcpy ( V_17 , V_61 -> V_17 , V_132 ) ;
F_63 ( V_61 , V_132 ) ;
V_129 -= V_132 ;
if ( V_129 ) {
V_17 += V_132 ;
V_35 += V_132 ;
V_131 = 0 ;
V_132 = F_44 ( T_5 , V_133 , V_129 ) ;
}
}
F_64 ( V_61 ) ;
if ( F_24 ( V_6 , V_6 -> V_49 ) )
F_10 ( L_24 ,
V_6 -> V_49 ) ;
F_18 ( V_6 -> V_14 [ 1 ] ) ;
return V_130 ;
}
int F_65 ( struct V_5 * V_6 , T_5 V_59 )
{
char V_136 = ( char ) V_59 ;
F_3 ( V_21 , L_25 ) ;
F_26 ( V_6 , V_43 , V_55 ,
V_137 , & V_136 ) ;
F_3 ( V_21 , L_26 ) ;
return 0 ;
}
int F_66 ( struct V_5 * V_6 )
{
T_3 V_138 = 0 ;
int V_16 = 0 ;
V_16 = F_67 ( V_6 ) ;
if ( V_16 )
goto V_139;
V_138 = V_140 ;
V_6 -> V_11 = F_68 ( V_138 , V_6 ) ;
if ( ! V_6 -> V_11 ) {
F_10 ( L_27 ) ;
V_16 = - V_141 ;
goto V_139;
}
V_139:
if ( V_16 )
F_69 ( V_6 ) ;
return V_16 ;
}
int F_69 ( struct V_5 * V_6 )
{
V_6 -> V_4 -> V_142 = V_143 ;
if ( V_6 -> V_11 ) {
F_70 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_71 ( V_6 ) ;
V_6 -> V_49 = 0 ;
return 0 ;
}
void F_72 ( struct V_5 * V_6 , bool V_144 )
{
if ( V_144 )
F_73 ( V_6 -> V_11 , V_145 ) ;
else
F_73 ( V_6 -> V_11 , 0 ) ;
}
