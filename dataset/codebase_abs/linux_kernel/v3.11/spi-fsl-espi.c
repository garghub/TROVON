static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_1 T_2 * V_11 = & V_10 -> V_12 [ V_2 -> V_13 ] ;
T_1 T_2 * V_14 = & V_10 -> V_11 ;
T_3 V_15 ;
unsigned long V_16 ;
F_3 ( V_16 ) ;
V_15 = F_4 ( V_14 ) ;
F_5 ( V_14 , V_15 & ~ V_17 ) ;
F_5 ( V_11 , V_7 -> V_18 ) ;
F_5 ( V_14 , V_15 ) ;
F_6 ( V_16 ) ;
}
static T_3 F_7 ( struct V_3 * V_3 )
{
T_3 V_19 ;
T_4 V_20 ;
T_4 V_21 ;
const T_3 * V_22 = V_3 -> V_22 ;
if ( ! V_22 )
return 0 ;
V_19 = * V_22 ++ << V_3 -> V_23 ;
V_21 = V_19 & 0xffff ;
V_20 = ( V_19 >> 16 ) & 0xffff ;
F_8 ( & V_21 ) ;
F_8 ( & V_20 ) ;
V_19 = V_20 | V_21 ;
V_3 -> V_22 = V_22 ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
int V_26 = 0 ;
T_5 V_27 ;
T_3 V_28 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_25 ) {
V_26 = V_25 -> V_26 ;
V_28 = V_25 -> V_29 ;
}
if ( ! V_26 )
V_26 = V_2 -> V_26 ;
if ( ! V_28 )
V_28 = V_2 -> V_30 ;
V_7 -> V_31 = 0 ;
V_7 -> V_23 = 0 ;
V_7 -> V_32 = V_33 ;
V_7 -> V_34 = V_35 ;
if ( V_26 <= 8 ) {
V_7 -> V_31 = 8 - V_26 ;
} else {
V_7 -> V_31 = 16 - V_26 ;
if ( V_2 -> V_11 & V_36 )
V_7 -> V_34 = F_7 ;
}
V_3 -> V_31 = V_7 -> V_31 ;
V_3 -> V_23 = V_7 -> V_23 ;
V_3 -> V_32 = V_7 -> V_32 ;
V_3 -> V_34 = V_7 -> V_34 ;
V_26 = V_26 - 1 ;
V_7 -> V_18 &= ~ ( F_10 ( 0xF ) | V_37 | F_11 ( 0xF ) ) ;
V_7 -> V_18 |= F_10 ( V_26 ) ;
if ( ( V_3 -> V_38 / V_28 ) > 64 ) {
V_7 -> V_18 |= V_37 ;
V_27 = F_12 ( V_3 -> V_38 , V_28 * 16 * 4 ) ;
F_13 ( V_27 > 33 , L_1
L_2 , F_14 ( & V_2 -> V_39 ) ,
V_28 , V_3 -> V_38 / ( 4 * 16 * ( 32 + 1 ) ) ) ;
if ( V_27 > 33 )
V_27 = 33 ;
} else {
V_27 = F_12 ( V_3 -> V_38 , V_28 * 4 ) ;
}
if ( V_27 )
V_27 -- ;
if ( V_27 < 2 )
V_27 = 2 ;
V_7 -> V_18 |= F_11 ( V_27 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , struct V_24 * V_25 ,
unsigned int V_40 )
{
T_3 V_41 ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_4 -> V_42 = V_40 ;
F_5 ( & V_10 -> V_43 , V_44 ) ;
V_41 = V_4 -> V_34 ( V_4 ) ;
F_5 ( & V_10 -> V_45 , V_41 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
unsigned int V_40 = V_25 -> V_40 ;
T_5 V_26 ;
int V_46 ;
V_26 = V_2 -> V_26 ;
if ( V_25 -> V_26 )
V_26 = V_25 -> V_26 ;
V_3 -> V_40 = V_25 -> V_40 ;
V_40 = F_17 ( V_40 , 4 ) / 4 ;
V_3 -> V_22 = V_25 -> V_47 ;
V_3 -> V_48 = V_25 -> V_49 ;
F_18 ( V_3 -> V_50 ) ;
if ( ( V_25 -> V_40 - 1 ) > V_51 ) {
F_19 ( V_3 -> V_39 , L_3
L_4 , V_25 -> V_40 ) ;
return - V_52 ;
}
F_5 ( & V_10 -> V_53 ,
( F_20 ( V_2 -> V_13 ) | F_21 ( V_25 -> V_40 - 1 ) ) ) ;
V_46 = F_15 ( V_3 , V_25 , V_40 ) ;
if ( V_46 )
return V_46 ;
F_22 ( & V_3 -> V_50 ) ;
F_5 ( & V_10 -> V_43 , 0 ) ;
return V_3 -> V_42 ;
}
static inline void F_23 ( unsigned int V_54 , T_5 * V_55 )
{
if ( V_55 ) {
V_55 [ 1 ] = ( T_5 ) ( V_54 >> 16 ) ;
V_55 [ 2 ] = ( T_5 ) ( V_54 >> 8 ) ;
V_55 [ 3 ] = ( T_5 ) ( V_54 >> 0 ) ;
}
}
static inline unsigned int F_24 ( T_5 * V_55 )
{
if ( V_55 )
return V_55 [ 1 ] << 16 | V_55 [ 2 ] << 8 | V_55 [ 3 ] << 0 ;
return 0 ;
}
static void F_25 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_58 * V_60 = V_59 ;
struct V_56 V_61 ;
struct V_24 * V_25 , * V_62 , V_63 ;
int V_64 = 0 ;
F_26 ( & V_61 ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_62 = F_27 ( & V_57 -> V_65 , struct V_24 ,
V_66 ) ;
F_28 (t, &m->transfers, transfer_list) {
if ( ( V_62 -> V_26 != V_25 -> V_26 ) ||
( V_62 -> V_29 != V_25 -> V_29 ) ) {
V_60 -> V_64 = - V_52 ;
F_19 ( V_4 -> V_39 , L_5
L_6 ) ;
return;
}
V_63 . V_29 = V_25 -> V_29 ;
V_63 . V_26 = V_25 -> V_26 ;
V_63 . V_67 = F_29 ( V_62 -> V_67 , V_25 -> V_67 ) ;
}
V_63 . V_40 = V_60 -> V_40 ;
V_63 . V_47 = V_60 -> V_47 ;
V_63 . V_49 = V_60 -> V_49 ;
F_30 ( & V_63 , & V_61 ) ;
F_28 (t, &message.transfers, transfer_list) {
if ( V_25 -> V_26 || V_25 -> V_29 ) {
V_64 = - V_52 ;
V_64 = F_9 ( V_2 , V_25 ) ;
if ( V_64 < 0 )
break;
}
if ( V_25 -> V_40 )
V_64 = F_16 ( V_2 , V_25 ) ;
if ( V_64 ) {
V_64 = - V_68 ;
break;
}
if ( V_25 -> V_67 )
F_31 ( V_25 -> V_67 ) ;
}
V_60 -> V_64 = V_64 ;
F_9 ( V_2 , NULL ) ;
}
static void F_32 ( struct V_56 * V_57 ,
struct V_58 * V_63 , T_5 * V_69 )
{
struct V_24 * V_25 ;
T_5 * V_70 ;
int V_71 = 0 ;
struct V_58 * V_60 = V_63 ;
V_70 = F_33 ( V_51 , V_72 ) ;
if ( ! V_70 ) {
V_60 -> V_64 = - V_73 ;
return;
}
F_28 (t, &m->transfers, transfer_list) {
if ( V_25 -> V_47 ) {
memcpy ( V_70 + V_71 , V_25 -> V_47 , V_25 -> V_40 ) ;
V_71 += V_25 -> V_40 ;
}
}
V_60 -> V_47 = V_70 ;
V_60 -> V_49 = V_70 + V_60 -> V_74 ;
F_25 ( V_57 , V_60 ) ;
V_60 -> V_75 = V_60 -> V_40 ;
F_34 ( V_70 ) ;
}
static void F_35 ( struct V_56 * V_57 ,
struct V_58 * V_63 , T_5 * V_69 )
{
struct V_58 * V_60 = V_63 ;
unsigned int V_74 = V_60 -> V_74 ;
unsigned int V_76 = V_60 -> V_76 ;
struct V_24 * V_25 ;
T_5 * V_70 ;
T_5 * V_49 = V_69 ;
unsigned int V_77 ;
unsigned int V_54 ;
int V_71 , V_78 , V_79 ;
V_70 = F_33 ( V_51 , V_72 ) ;
if ( ! V_70 ) {
V_60 -> V_64 = - V_73 ;
return;
}
for ( V_78 = 0 , V_79 = 0 ; V_78 < V_76 ; V_78 += V_77 , V_79 ++ ) {
V_77 = V_76 - V_78 ;
if ( V_77 > V_51 - V_74 )
V_77 = V_51 - V_74 ;
V_71 = 0 ;
F_28 (t, &m->transfers, transfer_list) {
if ( V_25 -> V_47 ) {
memcpy ( V_70 + V_71 , V_25 -> V_47 , V_25 -> V_40 ) ;
V_71 += V_25 -> V_40 ;
}
}
if ( V_78 > 0 ) {
V_54 = F_24 ( V_70 ) ;
V_54 += V_78 ;
F_23 ( V_54 , V_70 ) ;
}
V_60 -> V_74 = V_74 ;
V_60 -> V_76 = V_77 ;
V_60 -> V_40 = V_77 + V_74 ;
V_60 -> V_47 = V_70 ;
V_60 -> V_49 = V_70 + V_74 ;
F_25 ( V_57 , V_60 ) ;
memcpy ( V_49 + V_78 , V_60 -> V_49 + V_74 , V_77 ) ;
if ( V_79 > 0 )
V_60 -> V_75 += V_60 -> V_40 - V_74 ;
else
V_60 -> V_75 += V_60 -> V_40 ;
}
F_34 ( V_70 ) ;
}
static void F_36 ( struct V_56 * V_57 )
{
struct V_24 * V_25 ;
T_5 * V_49 = NULL ;
unsigned int V_74 = 0 ;
unsigned int V_76 = 0 ;
struct V_58 V_60 ;
F_28 (t, &m->transfers, transfer_list) {
if ( V_25 -> V_47 )
V_74 += V_25 -> V_40 ;
if ( V_25 -> V_49 ) {
V_76 += V_25 -> V_40 ;
V_49 = V_25 -> V_49 ;
}
}
V_60 . V_74 = V_74 ;
V_60 . V_76 = V_76 ;
V_60 . V_40 = V_74 + V_76 ;
V_60 . V_75 = 0 ;
V_60 . V_64 = 0 ;
if ( ! V_49 )
F_32 ( V_57 , & V_60 , NULL ) ;
else
F_35 ( V_57 , & V_60 , V_49 ) ;
V_57 -> V_75 = V_60 . V_75 ;
V_57 -> V_64 = V_60 . V_64 ;
V_57 -> V_80 ( V_57 -> V_81 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_9 * V_10 ;
int V_82 ;
T_3 V_18 ;
T_3 V_83 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_2 -> V_30 )
return - V_52 ;
if ( ! V_7 ) {
V_7 = F_33 ( sizeof *V_7 , V_72 ) ;
if ( ! V_7 )
return - V_73 ;
V_2 -> V_8 = V_7 ;
}
V_3 = F_2 ( V_2 -> V_5 ) ;
V_10 = V_3 -> V_10 ;
V_18 = V_7 -> V_18 ;
V_7 -> V_18 = F_4 (
& V_10 -> V_12 [ V_2 -> V_13 ] ) ;
V_7 -> V_18 &= ~ ( V_84 | V_85
| V_86 ) ;
if ( V_2 -> V_11 & V_87 )
V_7 -> V_18 |= V_84 ;
if ( V_2 -> V_11 & V_88 )
V_7 -> V_18 |= V_85 ;
if ( ! ( V_2 -> V_11 & V_36 ) )
V_7 -> V_18 |= V_86 ;
V_83 = F_4 ( & V_10 -> V_11 ) ;
V_83 &= ~ V_89 ;
if ( V_2 -> V_11 & V_90 )
V_83 |= V_89 ;
F_5 ( & V_10 -> V_11 , V_83 ) ;
V_82 = F_9 ( V_2 , NULL ) ;
if ( V_82 < 0 ) {
V_7 -> V_18 = V_18 ;
return V_82 ;
}
return 0 ;
}
void F_38 ( struct V_3 * V_4 , T_3 V_91 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_91 & V_92 ) {
T_3 V_93 , V_15 ;
T_5 V_94 ;
while ( F_39 ( V_91 ) < F_40 ( 4 , V_4 -> V_40 ) ) {
F_41 () ;
V_91 = F_4 ( & V_10 -> V_95 ) ;
}
if ( V_4 -> V_40 >= 4 ) {
V_93 = F_4 ( & V_10 -> V_96 ) ;
} else {
V_15 = V_4 -> V_40 ;
V_93 = 0 ;
while ( V_15 -- ) {
V_94 = F_42 ( ( T_5 * ) & V_10 -> V_96 ) ;
V_93 |= ( V_94 << ( V_15 * 8 ) ) ;
}
V_93 <<= ( 4 - V_4 -> V_40 ) * 8 ;
}
V_4 -> V_40 -= 4 ;
if ( V_4 -> V_48 )
V_4 -> V_32 ( V_93 , V_4 ) ;
}
if ( ! ( V_91 & V_97 ) ) {
int V_46 ;
V_46 = F_43 ( ( ( V_91 = F_4 (
& V_10 -> V_95 ) ) & V_97 ) == 0 , 1000 , 0 ) ;
if ( ! V_46 ) {
F_19 ( V_4 -> V_39 , L_7 ) ;
return;
}
}
F_5 ( & V_10 -> V_95 , V_91 ) ;
V_4 -> V_42 -= 1 ;
if ( V_4 -> V_42 ) {
T_3 V_41 = V_4 -> V_34 ( V_4 ) ;
F_5 ( & V_10 -> V_45 , V_41 ) ;
} else {
V_80 ( & V_4 -> V_50 ) ;
}
}
static T_6 F_44 ( T_7 V_98 , void * V_99 )
{
struct V_3 * V_4 = V_99 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_6 V_46 = V_100 ;
T_3 V_91 ;
V_91 = F_4 ( & V_10 -> V_95 ) ;
if ( V_91 )
V_46 = V_101 ;
F_45 ( V_4 -> V_39 , L_8 , V_102 , V_91 ) ;
F_38 ( V_4 , V_91 ) ;
return V_46 ;
}
static void F_46 ( struct V_3 * V_4 )
{
F_47 ( V_4 -> V_10 ) ;
}
static struct V_103 * F_48 ( struct V_104 * V_39 ,
struct V_105 * V_106 , unsigned int V_98 )
{
struct V_107 * V_108 = V_39 -> V_109 ;
struct V_103 * V_5 ;
struct V_3 * V_3 ;
struct V_9 * V_10 ;
T_3 V_110 ;
int V_71 , V_46 = 0 ;
V_5 = F_49 ( V_39 , sizeof( struct V_3 ) ) ;
if ( ! V_5 ) {
V_46 = - V_73 ;
goto V_111;
}
F_50 ( V_39 , V_5 ) ;
V_46 = F_51 ( V_39 , V_106 , V_98 ) ;
if ( V_46 )
goto V_112;
V_5 -> V_113 = F_52 ( 4 , 16 ) ;
V_5 -> V_114 = F_37 ;
V_3 = F_2 ( V_5 ) ;
V_3 -> V_115 = F_36 ;
V_3 -> V_116 = F_46 ;
V_3 -> V_10 = F_53 ( V_106 -> V_117 , F_54 ( V_106 ) ) ;
if ( ! V_3 -> V_10 ) {
V_46 = - V_73 ;
goto V_112;
}
V_10 = V_3 -> V_10 ;
V_46 = F_55 ( V_3 -> V_98 , F_44 ,
0 , L_9 , V_3 ) ;
if ( V_46 )
goto V_118;
if ( V_3 -> V_16 & V_119 ) {
V_3 -> V_31 = 16 ;
V_3 -> V_23 = 24 ;
}
F_5 ( & V_10 -> V_11 , 0 ) ;
F_5 ( & V_10 -> V_43 , 0 ) ;
F_5 ( & V_10 -> V_53 , 0 ) ;
F_5 ( & V_10 -> V_95 , 0xffffffff ) ;
for ( V_71 = 0 ; V_71 < V_108 -> V_120 ; V_71 ++ )
F_5 ( & V_10 -> V_12 [ V_71 ] , V_121 ) ;
V_110 = V_108 -> V_122 | V_123 | V_17 ;
F_5 ( & V_10 -> V_11 , V_110 ) ;
V_46 = F_56 ( V_5 ) ;
if ( V_46 < 0 )
goto V_124;
F_57 ( V_39 , L_10 , V_10 , V_3 -> V_98 ) ;
return V_5 ;
V_124:
V_118 ( V_3 -> V_98 , V_3 ) ;
V_118:
F_47 ( V_3 -> V_10 ) ;
V_112:
F_58 ( V_5 ) ;
V_111:
return F_59 ( V_46 ) ;
}
static int F_60 ( struct V_104 * V_39 )
{
struct V_125 * V_126 = V_39 -> V_127 ;
struct V_107 * V_108 = V_39 -> V_109 ;
const T_3 * V_128 ;
int V_40 ;
V_128 = F_61 ( V_126 , L_11 , & V_40 ) ;
if ( ! V_128 || V_40 < sizeof( * V_128 ) ) {
F_19 ( V_39 , L_12 ) ;
return - V_52 ;
}
V_108 -> V_120 = * V_128 ;
V_108 -> V_129 = NULL ;
return 0 ;
}
static int F_62 ( struct V_130 * V_131 )
{
struct V_104 * V_39 = & V_131 -> V_39 ;
struct V_125 * V_126 = V_131 -> V_39 . V_127 ;
struct V_103 * V_5 ;
struct V_105 V_106 ;
struct V_105 V_98 ;
int V_46 = - V_73 ;
V_46 = F_63 ( V_131 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_60 ( V_39 ) ;
if ( V_46 )
goto V_111;
V_46 = F_64 ( V_126 , 0 , & V_106 ) ;
if ( V_46 )
goto V_111;
V_46 = F_65 ( V_126 , 0 , & V_98 ) ;
if ( ! V_46 ) {
V_46 = - V_52 ;
goto V_111;
}
V_5 = F_48 ( V_39 , & V_106 , V_98 . V_117 ) ;
if ( F_66 ( V_5 ) ) {
V_46 = F_67 ( V_5 ) ;
goto V_111;
}
return 0 ;
V_111:
return V_46 ;
}
static int F_68 ( struct V_130 * V_39 )
{
return F_69 ( & V_39 -> V_39 ) ;
}
