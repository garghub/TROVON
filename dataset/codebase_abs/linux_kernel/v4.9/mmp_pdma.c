static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 = ( V_2 -> V_5 << 4 ) + V_6 ;
F_2 ( V_3 , V_2 -> V_7 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_4 , V_8 ;
if ( ! V_2 -> V_9 )
return;
V_4 = F_4 ( V_2 -> V_9 -> V_10 ) ;
F_2 ( V_11 | V_2 -> V_5 , V_2 -> V_7 + V_4 ) ;
V_8 = F_5 ( V_2 -> V_7 + V_12 ) ;
if ( V_2 -> V_9 -> V_13 )
V_8 |= 1 << V_2 -> V_5 ;
else
V_8 &= ~ ( 1 << V_2 -> V_5 ) ;
F_2 ( V_8 , V_2 -> V_7 + V_12 ) ;
V_4 = ( V_2 -> V_5 << 2 ) + V_14 ;
F_2 ( F_5 ( V_2 -> V_7 + V_4 ) | V_15 , V_2 -> V_7 + V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_2 V_4 ;
if ( ! V_2 )
return;
V_4 = ( V_2 -> V_5 << 2 ) + V_14 ;
F_2 ( F_5 ( V_2 -> V_7 + V_4 ) & ~ V_15 , V_2 -> V_7 + V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_2 V_16 ;
T_2 V_17 = F_5 ( V_2 -> V_7 + V_18 ) ;
T_2 V_4 = ( V_2 -> V_5 << 2 ) + V_14 ;
if ( ! ( V_17 & F_8 ( V_2 -> V_5 ) ) )
return - V_19 ;
V_16 = F_5 ( V_2 -> V_7 + V_4 ) ;
F_2 ( V_16 , V_2 -> V_7 + V_4 ) ;
if ( ( V_16 & V_20 ) && ( V_2 -> V_9 ) )
F_9 ( V_2 -> V_9 -> V_21 , L_1 ) ;
return 0 ;
}
static T_3 F_10 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
if ( F_7 ( V_2 ) != 0 )
return V_24 ;
F_11 ( & V_2 -> V_9 -> V_25 ) ;
return V_26 ;
}
static T_3 F_12 ( int V_22 , void * V_23 )
{
struct V_27 * V_28 = V_23 ;
struct V_1 * V_2 ;
T_2 V_17 = F_5 ( V_28 -> V_7 + V_18 ) ;
int V_29 , V_30 ;
int V_31 = 0 ;
while ( V_17 ) {
V_29 = F_13 ( V_17 ) ;
if ( V_29 >= V_28 -> V_32 )
break;
V_17 &= ( V_17 - 1 ) ;
V_2 = & V_28 -> V_2 [ V_29 ] ;
V_30 = F_10 ( V_22 , V_2 ) ;
if ( V_30 == V_26 )
V_31 ++ ;
}
if ( V_31 )
return V_26 ;
return V_24 ;
}
static struct V_1 * F_14 ( struct V_33 * V_34 )
{
int V_35 , V_29 ;
struct V_27 * V_28 = F_15 ( V_34 -> V_36 . V_37 ) ;
struct V_1 * V_2 , * V_38 = NULL ;
unsigned long V_39 ;
F_16 ( & V_28 -> V_40 , V_39 ) ;
for ( V_35 = 0 ; V_35 <= ( ( V_28 -> V_32 - 1 ) & 0xf ) >> 2 ; V_35 ++ ) {
for ( V_29 = 0 ; V_29 < V_28 -> V_32 ; V_29 ++ ) {
if ( V_35 != ( V_29 & 0xf ) >> 2 )
continue;
V_2 = & V_28 -> V_2 [ V_29 ] ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_9 = V_34 ;
V_38 = V_2 ;
goto V_41;
}
}
}
V_41:
F_17 ( & V_28 -> V_40 , V_39 ) ;
return V_38 ;
}
static void F_18 ( struct V_33 * V_34 )
{
struct V_27 * V_28 = F_15 ( V_34 -> V_36 . V_37 ) ;
unsigned long V_39 ;
T_2 V_4 ;
if ( ! V_34 -> V_2 )
return;
V_4 = F_4 ( V_34 -> V_10 ) ;
F_2 ( 0 , V_34 -> V_2 -> V_7 + V_4 ) ;
F_16 ( & V_28 -> V_40 , V_39 ) ;
V_34 -> V_2 -> V_9 = NULL ;
V_34 -> V_2 = NULL ;
F_17 ( & V_28 -> V_40 , V_39 ) ;
}
static void F_19 ( struct V_33 * V_36 )
{
struct V_42 * V_43 ;
if ( ! V_36 -> V_44 ) {
F_20 ( V_36 -> V_21 , L_2 ) ;
return;
}
if ( F_21 ( & V_36 -> V_45 ) ) {
F_18 ( V_36 ) ;
F_20 ( V_36 -> V_21 , L_3 ) ;
return;
}
if ( ! V_36 -> V_2 ) {
V_36 -> V_2 = F_14 ( V_36 ) ;
if ( ! V_36 -> V_2 ) {
F_20 ( V_36 -> V_21 , L_4 ) ;
return;
}
}
V_43 = F_22 ( & V_36 -> V_45 ,
struct V_42 , V_46 ) ;
F_23 ( & V_36 -> V_45 , & V_36 -> V_47 ) ;
F_1 ( V_36 -> V_2 , V_43 -> V_48 . V_49 ) ;
F_3 ( V_36 -> V_2 ) ;
V_36 -> V_44 = false ;
}
static T_4 F_24 ( struct V_50 * V_51 )
{
struct V_33 * V_36 = F_25 ( V_51 -> V_36 ) ;
struct V_42 * V_43 = F_26 ( V_51 ) ;
struct V_42 * V_52 ;
unsigned long V_39 ;
T_4 V_53 = - V_54 ;
F_16 ( & V_36 -> V_55 , V_39 ) ;
F_27 (child, &desc->tx_list, node) {
V_53 = F_28 ( & V_52 -> V_48 ) ;
}
F_23 ( & V_43 -> V_56 , & V_36 -> V_45 ) ;
F_17 ( & V_36 -> V_55 , V_39 ) ;
return V_53 ;
}
static struct V_42 *
F_29 ( struct V_33 * V_36 )
{
struct V_42 * V_43 ;
T_1 V_57 ;
V_43 = F_30 ( V_36 -> V_58 , V_59 , & V_57 ) ;
if ( ! V_43 ) {
F_31 ( V_36 -> V_21 , L_5 ) ;
return NULL ;
}
F_32 ( & V_43 -> V_56 ) ;
F_33 ( & V_43 -> V_48 , & V_36 -> V_36 ) ;
V_43 -> V_48 . V_60 = F_24 ;
V_43 -> V_48 . V_49 = V_57 ;
return V_43 ;
}
static int F_34 ( struct V_61 * V_62 )
{
struct V_33 * V_36 = F_25 ( V_62 ) ;
if ( V_36 -> V_58 )
return 1 ;
V_36 -> V_58 = F_35 ( F_36 ( & V_62 -> V_21 -> V_37 ) ,
V_36 -> V_21 ,
sizeof( struct V_42 ) ,
F_37 ( struct V_42 ) ,
0 ) ;
if ( ! V_36 -> V_58 ) {
F_31 ( V_36 -> V_21 , L_6 ) ;
return - V_63 ;
}
F_18 ( V_36 ) ;
V_36 -> V_44 = true ;
V_36 -> V_64 = 0 ;
return 1 ;
}
static void F_38 ( struct V_33 * V_36 ,
struct V_65 * V_66 )
{
struct V_42 * V_43 , * V_67 ;
F_39 (desc, _desc, list, node) {
F_40 ( & V_43 -> V_46 ) ;
F_41 ( V_36 -> V_58 , V_43 , V_43 -> V_48 . V_49 ) ;
}
}
static void F_42 ( struct V_61 * V_62 )
{
struct V_33 * V_36 = F_25 ( V_62 ) ;
unsigned long V_39 ;
F_16 ( & V_36 -> V_55 , V_39 ) ;
F_38 ( V_36 , & V_36 -> V_45 ) ;
F_38 ( V_36 , & V_36 -> V_47 ) ;
F_17 ( & V_36 -> V_55 , V_39 ) ;
F_43 ( V_36 -> V_58 ) ;
V_36 -> V_58 = NULL ;
V_36 -> V_44 = true ;
V_36 -> V_64 = 0 ;
F_18 ( V_36 ) ;
return;
}
static struct V_50 *
F_44 ( struct V_61 * V_62 ,
T_1 V_68 , T_1 V_69 ,
T_5 V_70 , unsigned long V_39 )
{
struct V_33 * V_36 ;
struct V_42 * V_71 = NULL , * V_72 = NULL , * V_73 ;
T_5 V_74 = 0 ;
if ( ! V_62 )
return NULL ;
if ( ! V_70 )
return NULL ;
V_36 = F_25 ( V_62 ) ;
V_36 -> V_13 = false ;
if ( ! V_36 -> V_75 ) {
V_36 -> V_75 = V_76 ;
V_36 -> V_77 = V_78 | V_79 ;
V_36 -> V_77 |= V_80 ;
}
do {
V_73 = F_29 ( V_36 ) ;
if ( ! V_73 ) {
F_31 ( V_36 -> V_21 , L_7 ) ;
goto V_81;
}
V_74 = F_45 ( T_5 , V_70 , V_82 ) ;
if ( V_69 & 0x7 || V_68 & 0x7 )
V_36 -> V_13 = true ;
V_73 -> V_43 . V_77 = V_36 -> V_77 | ( V_83 & V_74 ) ;
V_73 -> V_43 . V_84 = V_69 ;
V_73 -> V_43 . V_85 = V_68 ;
if ( ! V_71 )
V_71 = V_73 ;
else
V_72 -> V_43 . V_86 = V_73 -> V_48 . V_49 ;
V_73 -> V_48 . V_53 = 0 ;
F_46 ( & V_73 -> V_48 ) ;
V_72 = V_73 ;
V_70 -= V_74 ;
if ( V_36 -> V_75 == V_87 ) {
V_69 += V_74 ;
} else if ( V_36 -> V_75 == V_88 ) {
V_68 += V_74 ;
} else if ( V_36 -> V_75 == V_76 ) {
V_69 += V_74 ;
V_68 += V_74 ;
}
F_47 ( & V_73 -> V_46 , & V_71 -> V_56 ) ;
} while ( V_70 );
V_71 -> V_48 . V_39 = V_39 ;
V_71 -> V_48 . V_53 = - V_54 ;
V_73 -> V_43 . V_86 = V_89 ;
V_73 -> V_43 . V_77 |= V_90 ;
V_36 -> V_91 = NULL ;
return & V_71 -> V_48 ;
V_81:
if ( V_71 )
F_38 ( V_36 , & V_71 -> V_56 ) ;
return NULL ;
}
static struct V_50 *
F_48 ( struct V_61 * V_62 , struct V_92 * V_93 ,
unsigned int V_94 , enum V_95 V_75 ,
unsigned long V_39 , void * V_96 )
{
struct V_33 * V_36 = F_25 ( V_62 ) ;
struct V_42 * V_71 = NULL , * V_72 = NULL , * V_73 = NULL ;
T_5 V_70 , V_97 ;
struct V_92 * V_98 ;
T_1 V_3 ;
int V_29 ;
if ( ( V_93 == NULL ) || ( V_94 == 0 ) )
return NULL ;
V_36 -> V_13 = false ;
F_49 (sgl, sg, sg_len, i) {
V_3 = F_50 ( V_98 ) ;
V_97 = F_51 ( V_93 ) ;
do {
V_70 = F_45 ( T_5 , V_97 , V_82 ) ;
if ( V_3 & 0x7 )
V_36 -> V_13 = true ;
V_73 = F_29 ( V_36 ) ;
if ( ! V_73 ) {
F_31 ( V_36 -> V_21 , L_7 ) ;
goto V_81;
}
V_73 -> V_43 . V_77 = V_36 -> V_77 | ( V_83 & V_70 ) ;
if ( V_75 == V_87 ) {
V_73 -> V_43 . V_84 = V_3 ;
V_73 -> V_43 . V_85 = V_36 -> V_64 ;
} else {
V_73 -> V_43 . V_84 = V_36 -> V_64 ;
V_73 -> V_43 . V_85 = V_3 ;
}
if ( ! V_71 )
V_71 = V_73 ;
else
V_72 -> V_43 . V_86 = V_73 -> V_48 . V_49 ;
V_73 -> V_48 . V_53 = 0 ;
F_46 ( & V_73 -> V_48 ) ;
V_72 = V_73 ;
F_47 ( & V_73 -> V_46 , & V_71 -> V_56 ) ;
V_3 += V_70 ;
V_97 -= V_70 ;
} while ( V_97 );
}
V_71 -> V_48 . V_53 = - V_54 ;
V_71 -> V_48 . V_39 = V_39 ;
V_73 -> V_43 . V_86 = V_89 ;
V_73 -> V_43 . V_77 |= V_90 ;
V_36 -> V_75 = V_75 ;
V_36 -> V_91 = NULL ;
return & V_71 -> V_48 ;
V_81:
if ( V_71 )
F_38 ( V_36 , & V_71 -> V_56 ) ;
return NULL ;
}
static struct V_50 *
F_52 ( struct V_61 * V_62 ,
T_1 V_99 , T_5 V_70 , T_5 V_100 ,
enum V_95 V_101 ,
unsigned long V_39 )
{
struct V_33 * V_36 ;
struct V_42 * V_71 = NULL , * V_72 = NULL , * V_73 ;
T_1 V_69 , V_68 ;
if ( ! V_62 || ! V_70 || ! V_100 )
return NULL ;
if ( V_70 % V_100 != 0 )
return NULL ;
if ( V_100 > V_82 )
return NULL ;
V_36 = F_25 ( V_62 ) ;
switch ( V_101 ) {
case V_87 :
V_69 = V_99 ;
V_68 = V_36 -> V_64 ;
break;
case V_88 :
V_68 = V_99 ;
V_69 = V_36 -> V_64 ;
break;
default:
F_31 ( V_36 -> V_21 , L_8 ) ;
return NULL ;
}
V_36 -> V_75 = V_101 ;
do {
V_73 = F_29 ( V_36 ) ;
if ( ! V_73 ) {
F_31 ( V_36 -> V_21 , L_7 ) ;
goto V_81;
}
V_73 -> V_43 . V_77 = ( V_36 -> V_77 | V_90 |
( V_83 & V_100 ) ) ;
V_73 -> V_43 . V_84 = V_69 ;
V_73 -> V_43 . V_85 = V_68 ;
if ( ! V_71 )
V_71 = V_73 ;
else
V_72 -> V_43 . V_86 = V_73 -> V_48 . V_49 ;
V_73 -> V_48 . V_53 = 0 ;
F_46 ( & V_73 -> V_48 ) ;
V_72 = V_73 ;
V_70 -= V_100 ;
if ( V_36 -> V_75 == V_87 )
V_69 += V_100 ;
else
V_68 += V_100 ;
F_47 ( & V_73 -> V_46 , & V_71 -> V_56 ) ;
} while ( V_70 );
V_71 -> V_48 . V_39 = V_39 ;
V_71 -> V_48 . V_53 = - V_54 ;
V_73 -> V_43 . V_86 = V_71 -> V_48 . V_49 ;
V_36 -> V_91 = V_71 ;
return & V_71 -> V_48 ;
V_81:
if ( V_71 )
F_38 ( V_36 , & V_71 -> V_56 ) ;
return NULL ;
}
static int F_53 ( struct V_61 * V_62 ,
struct V_102 * V_103 )
{
struct V_33 * V_36 = F_25 ( V_62 ) ;
T_2 V_104 = 0 , V_3 = 0 ;
enum V_105 V_106 = V_107 ;
if ( ! V_62 )
return - V_108 ;
if ( V_103 -> V_101 == V_88 ) {
V_36 -> V_77 = V_78 | V_109 ;
V_104 = V_103 -> V_110 ;
V_106 = V_103 -> V_111 ;
V_3 = V_103 -> V_112 ;
} else if ( V_103 -> V_101 == V_87 ) {
V_36 -> V_77 = V_79 | V_113 ;
V_104 = V_103 -> V_114 ;
V_106 = V_103 -> V_115 ;
V_3 = V_103 -> V_116 ;
}
if ( V_106 == V_117 )
V_36 -> V_77 |= V_118 ;
else if ( V_106 == V_119 )
V_36 -> V_77 |= V_120 ;
else if ( V_106 == V_121 )
V_36 -> V_77 |= V_122 ;
if ( V_104 == 8 )
V_36 -> V_77 |= V_123 ;
else if ( V_104 == 16 )
V_36 -> V_77 |= V_124 ;
else if ( V_104 == 32 )
V_36 -> V_77 |= V_80 ;
V_36 -> V_75 = V_103 -> V_101 ;
V_36 -> V_64 = V_3 ;
if ( V_103 -> V_125 )
V_36 -> V_10 = V_103 -> V_125 ;
return 0 ;
}
static int F_54 ( struct V_61 * V_62 )
{
struct V_33 * V_36 = F_25 ( V_62 ) ;
unsigned long V_39 ;
if ( ! V_62 )
return - V_108 ;
F_6 ( V_36 -> V_2 ) ;
F_18 ( V_36 ) ;
F_16 ( & V_36 -> V_55 , V_39 ) ;
F_38 ( V_36 , & V_36 -> V_45 ) ;
F_38 ( V_36 , & V_36 -> V_47 ) ;
F_17 ( & V_36 -> V_55 , V_39 ) ;
V_36 -> V_44 = true ;
return 0 ;
}
static unsigned int F_55 ( struct V_33 * V_36 ,
T_4 V_53 )
{
struct V_42 * V_126 ;
T_2 V_127 , V_128 = 0 ;
bool V_129 = false ;
bool V_130 = V_36 -> V_91 != NULL ;
if ( ! V_36 -> V_2 )
return 0 ;
if ( V_36 -> V_75 == V_88 )
V_127 = F_5 ( V_36 -> V_2 -> V_7 + F_56 ( V_36 -> V_2 -> V_5 ) ) ;
else
V_127 = F_5 ( V_36 -> V_2 -> V_7 + F_57 ( V_36 -> V_2 -> V_5 ) ) ;
F_27 (sw, &chan->chain_running, node) {
T_2 V_131 , V_132 , V_70 ;
if ( V_36 -> V_75 == V_88 )
V_131 = V_126 -> V_43 . V_85 ;
else
V_131 = V_126 -> V_43 . V_84 ;
V_70 = V_126 -> V_43 . V_77 & V_83 ;
V_132 = V_131 + V_70 ;
if ( V_129 ) {
V_128 += V_70 ;
} else if ( V_127 >= V_131 && V_127 <= V_132 ) {
V_128 += V_132 - V_127 ;
V_129 = true ;
}
if ( V_130 || ! ( V_126 -> V_43 . V_77 & V_90 ) )
continue;
if ( V_126 -> V_48 . V_53 == V_53 ) {
return V_128 ;
} else {
V_128 = 0 ;
V_129 = false ;
}
}
return V_128 ;
}
static enum V_133 F_58 ( struct V_61 * V_62 ,
T_4 V_53 ,
struct V_134 * V_135 )
{
struct V_33 * V_36 = F_25 ( V_62 ) ;
enum V_133 V_30 ;
V_30 = F_59 ( V_62 , V_53 , V_135 ) ;
if ( F_60 ( V_30 != V_136 ) )
F_61 ( V_135 , F_55 ( V_36 , V_53 ) ) ;
return V_30 ;
}
static void F_62 ( struct V_61 * V_62 )
{
struct V_33 * V_36 = F_25 ( V_62 ) ;
unsigned long V_39 ;
F_16 ( & V_36 -> V_55 , V_39 ) ;
F_19 ( V_36 ) ;
F_17 ( & V_36 -> V_55 , V_39 ) ;
}
static void F_63 ( unsigned long V_137 )
{
struct V_33 * V_36 = (struct V_33 * ) V_137 ;
struct V_42 * V_43 , * V_67 ;
F_64 ( V_138 ) ;
unsigned long V_39 ;
struct V_139 V_140 ;
if ( V_36 -> V_91 ) {
F_16 ( & V_36 -> V_55 , V_39 ) ;
V_43 = V_36 -> V_91 ;
F_65 ( & V_43 -> V_48 , & V_140 ) ;
F_17 ( & V_36 -> V_55 , V_39 ) ;
F_66 ( & V_140 , NULL ) ;
return;
}
F_16 ( & V_36 -> V_55 , V_39 ) ;
F_39 (desc, _desc, &chan->chain_running, node) {
F_67 ( & V_43 -> V_46 , & V_138 ) ;
if ( V_43 -> V_43 . V_77 & V_90 ) {
T_4 V_53 = V_43 -> V_48 . V_53 ;
F_68 ( & V_43 -> V_48 ) ;
F_20 ( V_36 -> V_21 , L_9 , V_53 ) ;
break;
}
}
V_36 -> V_44 = F_21 ( & V_36 -> V_47 ) ;
F_19 ( V_36 ) ;
F_17 ( & V_36 -> V_55 , V_39 ) ;
F_39 (desc, _desc, &chain_cleanup, node) {
struct V_50 * V_141 = & V_43 -> V_48 ;
F_40 ( & V_43 -> V_46 ) ;
F_65 ( V_141 , & V_140 ) ;
F_66 ( & V_140 , NULL ) ;
F_41 ( V_36 -> V_58 , V_43 , V_141 -> V_49 ) ;
}
}
static int F_69 ( struct V_142 * V_143 )
{
struct V_27 * V_28 = F_70 ( V_143 ) ;
struct V_1 * V_2 ;
int V_29 , V_22 = 0 , V_31 = 0 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_32 ; V_29 ++ ) {
if ( F_71 ( V_143 , V_29 ) > 0 )
V_31 ++ ;
}
if ( V_31 != V_28 -> V_32 ) {
V_22 = F_71 ( V_143 , 0 ) ;
F_72 ( & V_143 -> V_21 , V_22 , V_28 ) ;
} else {
for ( V_29 = 0 ; V_29 < V_28 -> V_32 ; V_29 ++ ) {
V_2 = & V_28 -> V_2 [ V_29 ] ;
V_22 = F_71 ( V_143 , V_29 ) ;
F_72 ( & V_143 -> V_21 , V_22 , V_2 ) ;
}
}
F_73 ( & V_28 -> V_37 ) ;
return 0 ;
}
static int F_74 ( struct V_27 * V_28 , int V_5 , int V_22 )
{
struct V_1 * V_2 = & V_28 -> V_2 [ V_5 ] ;
struct V_33 * V_36 ;
int V_30 ;
V_36 = F_75 ( V_28 -> V_21 , sizeof( * V_36 ) , V_144 ) ;
if ( V_36 == NULL )
return - V_63 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_28 -> V_7 ;
if ( V_22 ) {
V_30 = F_76 ( V_28 -> V_21 , V_22 , F_10 ,
V_145 , L_10 , V_2 ) ;
if ( V_30 ) {
F_31 ( V_28 -> V_21 , L_11 ) ;
return V_30 ;
}
}
F_77 ( & V_36 -> V_55 ) ;
V_36 -> V_21 = V_28 -> V_21 ;
V_36 -> V_36 . V_37 = & V_28 -> V_37 ;
F_78 ( & V_36 -> V_25 , F_63 , ( unsigned long ) V_36 ) ;
F_32 ( & V_36 -> V_45 ) ;
F_32 ( & V_36 -> V_47 ) ;
F_47 ( & V_36 -> V_36 . V_146 , & V_28 -> V_37 . V_147 ) ;
return 0 ;
}
static struct V_61 * F_79 ( struct V_148 * V_149 ,
struct V_150 * V_151 )
{
struct V_27 * V_152 = V_151 -> V_153 ;
struct V_61 * V_36 ;
V_36 = F_80 ( & V_152 -> V_37 ) ;
if ( ! V_36 )
return NULL ;
F_25 ( V_36 ) -> V_10 = V_149 -> args [ 0 ] ;
return V_36 ;
}
static int F_81 ( struct V_142 * V_143 )
{
struct V_27 * V_28 ;
const struct V_154 * V_155 ;
struct V_156 * V_157 = F_82 ( & V_143 -> V_21 ) ;
struct V_158 * V_159 ;
int V_29 , V_30 , V_22 = 0 ;
int V_32 = 0 , V_31 = 0 ;
const enum V_105 V_160 =
V_117 | V_119 |
V_121 ;
V_28 = F_75 ( & V_143 -> V_21 , sizeof( * V_28 ) , V_144 ) ;
if ( ! V_28 )
return - V_63 ;
V_28 -> V_21 = & V_143 -> V_21 ;
F_77 ( & V_28 -> V_40 ) ;
V_159 = F_83 ( V_143 , V_161 , 0 ) ;
V_28 -> V_7 = F_84 ( V_28 -> V_21 , V_159 ) ;
if ( F_85 ( V_28 -> V_7 ) )
return F_86 ( V_28 -> V_7 ) ;
V_155 = F_87 ( V_162 , V_28 -> V_21 ) ;
if ( V_155 )
F_88 ( V_28 -> V_21 -> V_163 , L_12 ,
& V_32 ) ;
else if ( V_157 && V_157 -> V_32 )
V_32 = V_157 -> V_32 ;
else
V_32 = 32 ;
V_28 -> V_32 = V_32 ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
if ( F_71 ( V_143 , V_29 ) > 0 )
V_31 ++ ;
}
V_28 -> V_2 = F_89 ( V_28 -> V_21 , V_32 , sizeof( * V_28 -> V_2 ) ,
V_144 ) ;
if ( V_28 -> V_2 == NULL )
return - V_63 ;
F_32 ( & V_28 -> V_37 . V_147 ) ;
if ( V_31 != V_32 ) {
V_22 = F_71 ( V_143 , 0 ) ;
V_30 = F_76 ( V_28 -> V_21 , V_22 , F_12 ,
V_145 , L_10 , V_28 ) ;
if ( V_30 )
return V_30 ;
}
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
V_22 = ( V_31 != V_32 ) ? 0 : F_71 ( V_143 , V_29 ) ;
V_30 = F_74 ( V_28 , V_29 , V_22 ) ;
if ( V_30 )
return V_30 ;
}
F_90 ( V_164 , V_28 -> V_37 . V_165 ) ;
F_90 ( V_166 , V_28 -> V_37 . V_165 ) ;
F_90 ( V_167 , V_28 -> V_37 . V_165 ) ;
F_90 ( V_168 , V_28 -> V_37 . V_165 ) ;
V_28 -> V_37 . V_21 = & V_143 -> V_21 ;
V_28 -> V_37 . V_169 = F_34 ;
V_28 -> V_37 . V_170 = F_42 ;
V_28 -> V_37 . V_171 = F_58 ;
V_28 -> V_37 . V_172 = F_44 ;
V_28 -> V_37 . V_173 = F_48 ;
V_28 -> V_37 . V_174 = F_52 ;
V_28 -> V_37 . V_175 = F_62 ;
V_28 -> V_37 . V_176 = F_53 ;
V_28 -> V_37 . V_177 = F_54 ;
V_28 -> V_37 . V_178 = V_179 ;
V_28 -> V_37 . V_180 = V_160 ;
V_28 -> V_37 . V_181 = V_160 ;
V_28 -> V_37 . V_182 = F_8 ( V_87 ) | F_8 ( V_88 ) ;
V_28 -> V_37 . V_183 = V_184 ;
if ( V_28 -> V_21 -> V_185 )
F_91 ( V_28 -> V_21 , V_28 -> V_21 -> V_185 ) ;
else
F_91 ( V_28 -> V_21 , F_92 ( 64 ) ) ;
V_30 = F_93 ( & V_28 -> V_37 ) ;
if ( V_30 ) {
F_31 ( V_28 -> V_37 . V_21 , L_13 ) ;
return V_30 ;
}
if ( V_143 -> V_21 . V_163 ) {
V_30 = F_94 ( V_143 -> V_21 . V_163 ,
F_79 , V_28 ) ;
if ( V_30 < 0 ) {
F_31 ( & V_143 -> V_21 , L_14 ) ;
return V_30 ;
}
}
F_95 ( V_143 , V_28 ) ;
F_96 ( V_28 -> V_37 . V_21 , L_15 , V_32 ) ;
return 0 ;
}
bool F_97 ( struct V_61 * V_36 , void * V_186 )
{
struct V_33 * V_187 = F_25 ( V_36 ) ;
if ( V_36 -> V_37 -> V_21 -> V_188 != & V_189 . V_188 )
return false ;
V_187 -> V_10 = * ( unsigned int * ) V_186 ;
return true ;
}
