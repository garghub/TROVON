static inline void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
if ( V_4 < V_3 ) {
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_1 ,
V_5 , V_3 , V_4 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , unsigned * V_8 )
{
F_2 ( & V_2 -> V_6 ) ;
F_7 ( V_8 , F_3 ( & V_2 -> V_7 ) ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static void F_8 ( struct V_9 * V_10 , struct V_11 * V_11 )
{
int V_12 = 4 ;
unsigned V_13 ;
int V_14 ;
char V_15 [ 10 ] ;
snprintf ( V_15 , 10 , L_2 , 1 << V_12 ) ;
F_9 ( V_10 , L_3 , L_4 , V_15 ) ;
for ( V_14 = V_12 + 1 ; V_14 < V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , 1 << V_14 ) ;
++ V_12 ;
for ( V_14 = 0 , V_13 = 0 ; V_14 <= V_12 ; ++ V_14 )
V_13 += V_11 -> V_17 [ V_14 ] ;
F_9 ( V_10 , L_6 , L_7 , V_13 ) ;
for ( V_14 = V_12 + 1 ; V_14 <= V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , V_11 -> V_17 [ V_14 ] ) ;
for ( V_14 = 0 , V_13 = 0 ; V_14 <= V_12 ; ++ V_14 )
V_13 += V_11 -> V_18 [ V_14 ] ;
F_9 ( V_10 , L_6 , L_8 , V_13 ) ;
for ( V_14 = V_12 + 1 ; V_14 <= V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , V_11 -> V_18 [ V_14 ] ) ;
for ( V_14 = 0 , V_13 = 0 ; V_14 <= V_12 ; ++ V_14 )
V_13 += V_11 -> V_19 [ V_14 ] ;
F_9 ( V_10 , L_6 , L_9 , V_13 ) ;
for ( V_14 = V_12 + 1 ; V_14 <= V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , V_11 -> V_19 [ V_14 ] ) ;
for ( V_14 = 0 , V_13 = 0 ; V_14 <= V_12 ; ++ V_14 )
V_13 += V_11 -> V_20 [ V_14 ] ;
F_9 ( V_10 , L_6 , L_10 , V_13 ) ;
for ( V_14 = V_12 + 1 ; V_14 <= V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , V_11 -> V_20 [ V_14 ] ) ;
}
static inline int F_10 ( struct V_21 * V_21 )
{
return F_11 ( 2 << V_21 -> V_22 , 4096 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_23 )
{
switch ( V_23 ) {
case V_24 :
F_13 ( V_2 , L_11 ) ;
break;
case V_25 :
F_13 ( V_2 , L_12 ) ;
break;
case V_26 :
F_13 ( V_2 , L_13 ) ;
break;
case V_27 :
F_13 ( V_2 , L_14 ) ;
break;
case V_28 :
F_13 ( V_2 , L_15 ) ;
break;
default:
F_13 ( V_2 , L_16 , V_23 ) ;
}
}
static void F_14 ( void * V_29 )
{
struct V_30 * V_31 = V_29 ;
F_15 ( & V_31 -> V_32 . V_33 ) ;
}
static void F_16 ( struct V_34 * V_35 , int V_23 ,
void * V_36 , T_1 V_37 , void * V_38 )
{
struct V_30 * V_31 = V_38 ;
struct V_1 * V_2 = V_31 -> V_2 ;
if ( V_2 && V_23 != V_39 )
F_12 ( V_2 , V_23 ) ;
if ( V_31 -> V_40 )
V_31 -> V_40 ( V_35 , V_23 , V_36 , V_37 , V_31 ) ;
F_17 ( V_41 , V_31 ) ;
}
static int F_18 ( struct V_42 * V_43 , int V_44 ,
unsigned long long V_45 , void * V_36 ,
T_1 V_37 , T_2 V_40 ,
struct V_1 * V_2 )
{
struct V_30 * V_31 ;
int V_46 ;
V_31 = F_19 ( V_41 , V_47 ) ;
if ( ! V_31 )
return - V_48 ;
V_31 -> V_40 = V_40 ;
V_31 -> V_2 = V_2 ;
V_46 = V_43 -> V_46 ;
F_20 () ;
F_21 ( V_43 -> V_49 -> V_35 , & V_31 -> V_32 , V_44 ,
V_43 -> V_50 , V_46 , V_43 -> V_51 , V_45 , V_36 ,
V_37 , F_16 , V_31 ) ;
return 0 ;
}
static void F_22 ( struct V_42 * V_43 ,
struct V_30 * V_31 , int V_44 ,
unsigned long long V_45 , void * V_36 ,
T_1 V_37 , T_2 V_40 ,
struct V_1 * V_2 )
{
int V_46 ;
V_31 -> V_40 = V_40 ;
V_31 -> V_2 = V_2 ;
V_46 = V_43 -> V_46 ;
F_20 () ;
F_21 ( V_43 -> V_49 -> V_35 , & V_31 -> V_32 , V_44 ,
V_43 -> V_50 , V_46 , V_43 -> V_51 , V_45 , V_36 ,
V_37 , F_16 , V_31 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_37 , V_5 ;
V_37 = F_24 ( & V_2 -> V_7 ) ;
if ( V_37 )
F_25 ( & V_2 -> V_52 , 0 ) ;
V_5 = F_3 ( & V_2 -> V_7 ) ;
F_5 ( V_2 , L_17 , V_37 , V_5 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_6 ) ;
F_23 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static void F_27 ( struct V_1 * V_2 , unsigned V_53 )
{
unsigned V_54 ;
struct V_55 * V_56 ;
V_53 &= ~ V_57 ;
V_54 = ( V_2 -> V_58 ^ V_53 ) & ~ V_57 ;
V_54 &= ~ ( V_53 & V_59 ) ;
V_2 -> V_58 = V_53 ;
if ( V_54 & V_59 )
++ V_2 -> V_60 . V_61 ;
if ( V_54 & V_62 )
++ V_2 -> V_60 . V_63 ;
if ( V_54 & V_64 )
++ V_2 -> V_60 . V_65 ;
if ( V_54 & V_66 )
++ V_2 -> V_60 . V_67 ;
F_5 ( V_2 , L_18 , V_53 , V_54 ) ;
if ( V_54 & V_64 ) {
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 && ! F_29 ( V_56 ) ) {
if ( V_53 & V_64 )
F_30 ( & V_2 -> V_2 . V_68 ) ;
else
F_31 ( & V_2 -> V_69 ) ;
}
F_32 ( V_56 ) ;
}
if ( V_54 & V_66 ) {
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 && F_33 ( V_56 ) ) {
if ( V_56 -> V_70 ) {
if ( V_53 & V_66 ) {
V_56 -> V_70 = 0 ;
if ( V_2 -> V_71 )
F_23 ( V_2 ) ;
else
F_26 ( V_2 ) ;
}
} else {
if ( ~ V_53 & V_66 )
V_56 -> V_70 = 1 ;
}
}
F_32 ( V_56 ) ;
} else if ( V_54 & V_72 ) {
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 ) {
if ( V_56 -> V_70 ) {
if ( ~ V_53 & V_72 ) {
V_56 -> V_70 = 0 ;
if ( V_2 -> V_71 )
F_23 ( V_2 ) ;
else
F_26 ( V_2 ) ;
}
} else {
if ( V_53 & V_72 )
V_56 -> V_70 = 1 ;
}
}
F_32 ( V_56 ) ;
}
if ( V_54 & ( V_73 << 24 ) ) {
if ( V_53 & ( V_73 << 24 ) ) {
V_2 -> V_74 = V_75 ;
F_25 ( & V_2 -> V_76 , 0 ) ;
} else {
F_34 ( V_77 , & V_2 -> V_76 , 0 ) ;
}
}
if ( V_54 & ( V_62 | V_64 | V_66 | V_59 ) )
F_30 ( & V_2 -> V_2 . V_78 ) ;
}
static unsigned F_35 ( struct V_1 * V_2 )
{
unsigned V_53 = 0 ;
if ( V_2 -> V_79 & V_80 )
V_53 |= V_62 | V_64 ;
if ( V_2 -> V_79 & V_81 )
V_53 |= V_66 ;
if ( V_2 -> V_79 & V_82 )
V_53 |= V_72 ;
if ( V_2 -> V_83 )
V_53 |= V_73 << 24 ;
return V_53 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
int V_84 = - V_85 ;
unsigned V_53 = F_35 ( V_2 ) ;
F_37 () ;
V_43 = F_38 ( V_2 -> V_43 ) ;
if ( V_43 ) {
V_84 = F_18 ( V_43 , V_86 ,
V_43 -> V_87 , & V_53 ,
sizeof( V_53 ) , NULL , V_2 ) ;
}
F_39 () ;
return V_84 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_84 ;
F_2 ( & V_2 -> V_6 ) ;
V_84 = F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_84 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
unsigned V_88 ;
V_88 = V_2 -> V_79 ;
V_2 -> V_79 |= V_82 ;
if ( F_33 ( V_56 ) )
V_2 -> V_79 &= ~ V_81 ;
if ( ~ V_88 & V_82 )
F_36 ( V_2 ) ;
}
static void F_42 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_43 ( V_90 , V_69 ) ;
struct V_55 * V_56 ;
F_44 ( F_45 ( 50 ) ) ;
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 )
F_46 ( V_56 ) ;
F_32 ( V_56 ) ;
}
static void F_47 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_43 ( F_48 ( V_90 ) , V_76 ) ;
static const char V_91 [ 16 ] ;
unsigned long V_92 = V_75 ;
unsigned long V_93 = V_92 - V_2 -> V_74 ;
int V_4 , V_15 , V_3 , V_94 = 0 ;
V_4 = ( V_93 * V_2 -> V_95 ) / V_96 + 1 ;
V_2 -> V_74 = V_92 ;
F_5 ( V_2 , L_19 , V_4 ) ;
while ( V_4 ) {
V_15 = F_11 ( V_4 , 16 ) ;
V_3 = F_49 ( & V_2 -> V_2 , V_91 ,
V_97 , V_15 ) ;
V_4 -= V_3 ;
V_94 += V_3 ;
if ( V_3 < V_15 )
break;
}
F_50 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_58 & ( V_73 << 24 ) )
F_25 ( & V_2 -> V_76 , V_98 ) ;
V_2 -> V_60 . V_94 += V_94 ;
}
static void F_51 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_43 ( V_90 , V_99 ) ;
struct V_55 * V_56 ;
struct V_100 * V_91 , * V_101 ;
int V_4 , V_3 = 0 ;
F_2 ( & V_2 -> V_6 ) ;
F_52 (buf, next, &port->buf_list, list) {
V_4 = F_49 ( & V_2 -> V_2 , V_91 -> V_102 ,
V_103 , V_91 -> V_4 ) ;
V_3 += V_4 ;
V_2 -> V_104 -= V_4 ;
if ( V_4 < V_91 -> V_4 ) {
if ( V_4 > 0 ) {
memmove ( V_91 -> V_102 , V_91 -> V_102 + V_4 , V_91 -> V_4 - V_4 ) ;
V_91 -> V_4 -= V_4 ;
}
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 ) {
F_41 ( V_2 , V_56 ) ;
F_32 ( V_56 ) ;
}
break;
} else {
F_53 ( & V_91 -> V_105 ) ;
F_54 ( V_91 ) ;
}
}
if ( V_3 > 0 )
F_50 ( & V_2 -> V_2 ) ;
if ( F_55 ( & V_2 -> V_106 ) )
F_56 ( V_107 , & V_2 -> V_108 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static int F_57 ( struct V_1 * V_2 , unsigned char * V_109 , T_1 V_4 )
{
struct V_100 * V_91 ;
T_1 V_110 = ( V_4 + sizeof( struct V_100 ) + 0xFF ) & ~ 0xFF ;
if ( V_2 -> V_104 + V_4 > V_111 ) {
F_13 ( V_2 , L_20 ,
V_2 -> V_104 , V_4 , V_111 ) ;
return 0 ;
}
V_91 = F_58 ( V_110 , V_47 ) ;
if ( ! V_91 )
return 0 ;
F_59 ( & V_91 -> V_105 ) ;
V_91 -> V_4 = V_4 ;
memcpy ( V_91 -> V_102 , V_109 , V_4 ) ;
F_2 ( & V_2 -> V_6 ) ;
F_60 ( & V_91 -> V_105 , & V_2 -> V_106 ) ;
V_2 -> V_104 += V_4 ;
if ( V_2 -> V_104 > V_2 -> V_11 . V_112 )
V_2 -> V_11 . V_112 = V_2 -> V_104 ;
F_61 ( V_107 , & V_2 -> V_108 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_4 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned char * V_102 , T_1 V_37 )
{
struct V_55 * V_56 ;
int V_3 , V_4 = V_37 ;
unsigned V_113 ;
int V_84 = 0 ;
F_5 ( V_2 , L_21 , V_4 ) ;
F_7 ( V_2 -> V_11 . V_17 , V_4 ) ;
if ( V_2 -> V_114 ) {
V_4 = 0 ;
goto V_115;
}
V_113 = ( V_2 -> V_58 >> 24 ) & ~ V_73 ;
if ( V_2 -> V_116 )
V_113 |= V_117 ;
if ( V_113 & V_117 )
++ V_2 -> V_60 . V_116 ;
V_113 &= V_2 -> V_118 ;
if ( V_113 & ~ V_2 -> V_119 & V_117 ) {
if ( ! F_63 ( & V_2 -> V_2 , 0 , V_120 ) ) {
V_84 = - V_121 ;
goto V_115;
}
}
V_2 -> V_116 = false ;
if ( V_113 & V_2 -> V_119 & ~ V_117 ) {
V_4 = 0 ;
goto V_115;
}
if ( ! F_64 ( V_107 , & V_2 -> V_108 ) ) {
V_3 = F_49 ( & V_2 -> V_2 , V_102 ,
V_103 , V_4 ) ;
if ( V_3 > 0 )
F_50 ( & V_2 -> V_2 ) ;
V_4 -= V_3 ;
if ( V_4 ) {
V_4 -= F_57 ( V_2 , & V_102 [ V_3 ] , V_4 ) ;
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 ) {
F_2 ( & V_2 -> V_6 ) ;
F_41 ( V_2 , V_56 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_32 ( V_56 ) ;
}
}
} else
V_4 -= F_57 ( V_2 , V_102 , V_4 ) ;
if ( V_4 ) {
V_2 -> V_116 = true ;
V_84 = - V_121 ;
}
V_115:
V_2 -> V_60 . V_122 += V_37 ;
V_2 -> V_11 . V_123 += V_4 ;
return V_84 ;
}
static void F_65 ( struct V_34 * V_35 ,
struct V_124 * V_125 ,
int V_44 , int V_126 , int V_127 ,
int V_46 ,
unsigned long long V_45 ,
void * V_102 , T_1 V_37 ,
void * V_128 )
{
struct V_1 * V_2 = V_128 ;
struct V_42 * V_43 ;
int V_84 ;
int V_23 ;
F_37 () ;
V_43 = F_66 ( V_35 , V_46 , V_127 ) ;
F_39 () ;
if ( ! V_43 || V_43 != F_67 ( V_2 -> V_43 ) ) {
V_23 = V_25 ;
F_13 ( V_2 , L_22 ) ;
goto V_129;
}
switch ( V_44 ) {
case V_86 :
if ( V_45 != V_2 -> V_130 . V_131 || V_37 != 4 )
V_23 = V_25 ;
else {
F_27 ( V_2 , * ( unsigned * ) V_102 ) ;
V_23 = V_39 ;
}
break;
case V_132 :
if ( V_45 != V_2 -> V_130 . V_131 + 4 ||
V_37 > V_2 -> V_130 . V_133 - 4 ) {
V_23 = V_25 ;
} else {
V_84 = F_62 ( V_2 , V_102 , V_37 ) ;
switch ( V_84 ) {
case 0 :
V_23 = V_39 ;
break;
case - V_121 :
V_23 = V_26 ;
break;
default:
V_23 = V_134 ;
break;
}
}
break;
default:
V_23 = V_135 ;
}
V_129:
F_68 ( V_35 , V_125 , V_23 ) ;
}
static void F_69 ( struct V_34 * V_35 , int V_23 ,
void * V_102 , T_1 V_133 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
int V_37 ;
F_5 ( V_2 , L_23 , V_23 ) ;
switch ( V_23 ) {
case V_39 :
F_2 ( & V_2 -> V_6 ) ;
F_70 ( & V_2 -> V_7 , & V_31 -> V_136 ) ;
V_37 = F_71 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
V_2 -> V_60 . V_137 += V_31 -> V_136 . V_37 ;
break;
default:
F_2 ( & V_2 -> V_6 ) ;
F_70 ( & V_2 -> V_7 , & V_31 -> V_136 ) ;
V_37 = F_71 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
V_2 -> V_11 . V_138 += V_31 -> V_136 . V_37 ;
}
if ( V_37 < V_139 )
F_72 ( & V_2 -> V_2 ) ;
}
static int F_73 ( struct V_1 * V_2 , bool V_52 )
{
struct V_42 * V_43 ;
struct V_30 * V_31 ;
struct V_55 * V_56 ;
int V_4 , V_37 ;
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( ! V_56 )
return - V_85 ;
F_37 () ;
V_43 = F_38 ( V_2 -> V_43 ) ;
if ( ! V_43 ) {
V_4 = - V_121 ;
goto V_115;
}
if ( F_74 ( V_140 , & V_2 -> V_108 ) ) {
V_4 = - V_141 ;
goto V_115;
}
V_4 = - V_142 ;
while ( ! V_56 -> V_143 && ! V_56 -> V_70 &&
! F_64 ( V_144 , & V_2 -> V_108 ) ) {
V_31 = F_19 ( V_41 , V_47 ) ;
if ( ! V_31 ) {
V_4 = - V_48 ;
break;
}
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_75 ( & V_2 -> V_7 , & V_31 -> V_136 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_24 , V_31 -> V_136 . V_37 , V_4 ) ;
if ( V_4 < 0 ) {
F_17 ( V_41 , V_31 ) ;
if ( V_4 == - V_142 )
++ V_2 -> V_11 . V_145 ;
else if ( V_4 == - V_146 )
F_7 ( V_2 -> V_11 . V_19 , 0 ) ;
else {
++ V_2 -> V_11 . V_147 ;
F_13 ( V_2 , L_25 ,
V_4 ) ;
}
break;
}
F_7 ( V_2 -> V_11 . V_19 , V_31 -> V_136 . V_37 ) ;
F_22 ( V_43 , V_31 , V_132 ,
V_43 -> V_148 , V_31 -> V_136 . V_102 ,
V_31 -> V_136 . V_37 , F_69 ,
V_2 ) ;
++ V_2 -> V_11 . V_149 ;
if ( V_4 == 0 || ( ! V_52 && V_4 < V_150 ) )
break;
}
if ( V_4 >= 0 || V_4 == - V_142 || V_4 == - V_48 || V_4 == - V_146 ) {
F_2 ( & V_2 -> V_6 ) ;
V_37 = F_24 ( & V_2 -> V_7 ) ;
if ( V_37 ) {
unsigned long V_151 = ( V_4 == - V_48 ) ? V_96 : 1 ;
F_25 ( & V_2 -> V_52 , V_151 ) ;
}
V_37 = F_71 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_52 && V_37 < V_139 )
F_76 ( V_56 ) ;
}
F_56 ( V_140 , & V_2 -> V_108 ) ;
F_30 ( & V_2 -> V_152 ) ;
V_115:
F_39 () ;
F_32 ( V_56 ) ;
return V_4 ;
}
static void F_77 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_43 ( F_48 ( V_90 ) , V_52 ) ;
F_73 ( V_2 , true ) ;
}
static void F_78 ( struct V_1 * V_2 , char V_153 )
{
struct V_42 * V_43 ;
++ V_2 -> V_11 . V_154 ;
F_5 ( V_2 , L_26 , V_153 ) ;
F_37 () ;
V_43 = F_38 ( V_2 -> V_43 ) ;
if ( V_43 ) {
F_18 ( V_43 , V_132 ,
V_43 -> V_148 , & V_153 , sizeof( V_153 ) ,
NULL , V_2 ) ;
}
F_39 () ;
}
struct V_1 * F_79 ( unsigned V_155 )
{
struct V_1 * V_2 ;
if ( V_155 >= V_156 )
return NULL ;
F_80 ( & V_157 ) ;
V_2 = V_158 [ V_155 ] ;
if ( V_2 )
F_81 ( & V_2 -> V_49 -> V_159 ) ;
F_82 ( & V_157 ) ;
return V_2 ;
}
static int F_83 ( struct V_160 * V_49 )
{
int V_84 = - V_161 ;
int V_162 , V_14 ;
if ( V_163 )
return V_84 ;
F_80 ( & V_157 ) ;
for ( V_162 = 0 ; V_162 + V_164 <= V_156 ; V_162 += V_164 ) {
if ( ! V_158 [ V_162 ] ) {
for ( V_14 = 0 ; V_14 < V_164 ; ++ V_162 , ++ V_14 ) {
V_49 -> V_165 [ V_14 ] -> V_155 = V_162 ;
V_158 [ V_162 ] = V_49 -> V_165 [ V_14 ] ;
}
V_84 = 0 ;
break;
}
}
F_82 ( & V_157 ) ;
return V_84 ;
}
static void F_84 ( struct V_159 * V_159 )
{
struct V_160 * V_49 = F_85 ( V_159 , V_159 ) ;
struct V_1 * * V_165 = V_49 -> V_165 ;
int V_14 , V_162 = V_165 [ 0 ] -> V_155 ;
F_86 () ;
F_80 ( & V_157 ) ;
for ( V_14 = 0 ; V_14 < V_164 ; ++ V_162 , ++ V_14 ) {
V_163 |= V_158 [ V_162 ] != V_165 [ V_14 ] ;
F_87 ( V_163 , L_27 ,
V_162 , V_158 [ V_162 ] , V_14 , V_165 [ V_14 ] ) ;
V_158 [ V_162 ] = NULL ;
}
F_82 ( & V_157 ) ;
for ( V_14 = 0 ; V_14 < V_164 ; ++ V_14 ) {
F_88 ( & V_165 [ V_14 ] -> V_130 ) ;
F_89 ( & V_165 [ V_14 ] -> V_2 ) ;
F_54 ( V_165 [ V_14 ] ) ;
}
F_54 ( V_49 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
F_91 ( & V_2 -> V_49 -> V_159 , F_84 ) ;
}
static void F_92 ( struct V_166 * V_166 , int V_167 )
{
struct V_1 * V_2 = F_43 ( V_166 , V_2 ) ;
F_5 ( V_2 , L_28 , V_167 ) ;
F_2 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_2 . V_168 ) {
if ( V_167 )
V_2 -> V_79 |= V_80 | V_81 ;
else
V_2 -> V_79 &= ~ ( V_80 | V_81 ) ;
}
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static int F_93 ( struct V_166 * V_166 )
{
struct V_1 * V_2 = F_43 ( V_166 , V_2 ) ;
int V_169 ;
V_169 = ( V_2 -> V_58 & V_64 ) ;
F_5 ( V_2 , L_21 , V_169 ) ;
return V_169 ;
}
static unsigned F_94 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
unsigned V_170 , V_171 ;
V_170 = F_95 ( & V_56 -> V_172 ) ;
F_96 ( & V_56 -> V_172 , V_170 , V_170 ) ;
V_171 = 12 + ( ( F_97 ( V_56 ) ) ? 4 : 2 ) + ( ( F_98 ( V_56 ) ) ? 2 : 0 ) ;
switch ( F_99 ( V_56 ) ) {
case V_173 :
V_171 -= ( F_97 ( V_56 ) ) ? 1 : 0 ;
break;
case V_174 :
V_171 += 2 ;
break;
case V_175 :
V_171 += 4 ;
break;
case V_176 :
V_171 += 6 ;
break;
}
V_2 -> V_95 = ( V_170 << 1 ) / V_171 ;
V_2 -> V_118 = V_117 ;
if ( F_100 ( V_56 , V_177 | V_178 ) )
V_2 -> V_118 |= V_73 ;
V_2 -> V_119 = 0 ;
if ( F_101 ( V_56 ) ) {
V_2 -> V_119 |= V_73 ;
if ( F_102 ( V_56 ) )
V_2 -> V_119 |= V_117 ;
}
V_2 -> V_114 = ! F_103 ( V_56 ) ;
if ( V_2 -> V_71 ) {
V_56 -> V_172 . V_179 &= ~ ( V_180 | V_181 | V_182 | V_183 |
V_184 | V_185 | V_186 ) ;
V_56 -> V_172 . V_187 &= ~ V_188 ;
}
return V_170 ;
}
static int F_104 ( struct V_166 * V_166 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_43 ( V_166 , V_2 ) ;
unsigned V_170 ;
int V_84 ;
F_61 ( V_189 , & V_56 -> V_108 ) ;
V_84 = F_105 ( & V_2 -> V_7 , V_190 ,
F_106 () ,
V_2 -> V_191 ,
V_192 ,
V_193 ) ;
if ( V_84 )
return V_84 ;
F_2 ( & V_2 -> V_6 ) ;
V_170 = F_94 ( V_2 , V_56 ) ;
if ( ! V_2 -> V_2 . V_168 ) {
V_2 -> V_79 = 0 ;
if ( V_170 != 0 )
V_2 -> V_79 = V_80 | V_81 ;
}
if ( F_33 ( V_56 ) && ~ V_2 -> V_58 & V_66 )
V_56 -> V_70 = 1 ;
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_56 ( V_189 , & V_56 -> V_108 ) ;
return 0 ;
}
static void F_107 ( struct V_166 * V_166 )
{
struct V_1 * V_2 = F_43 ( V_166 , V_2 ) ;
struct V_100 * V_91 , * V_101 ;
F_108 ( & V_2 -> V_76 ) ;
F_108 ( & V_2 -> V_52 ) ;
F_109 ( & V_2 -> V_99 ) ;
F_2 ( & V_2 -> V_6 ) ;
F_52 (buf, next, &port->buf_list, list) {
F_53 ( & V_91 -> V_105 ) ;
F_54 ( V_91 ) ;
}
V_2 -> V_104 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_83 = 0 ;
V_2 -> V_116 = 0 ;
F_36 ( V_2 ) ;
F_110 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static int F_111 ( struct V_55 * V_56 , struct V_194 * V_195 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
return F_112 ( & V_2 -> V_2 , V_56 , V_195 ) ;
}
static void F_113 ( struct V_55 * V_56 , struct V_194 * V_195 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
F_114 ( & V_2 -> V_2 , V_56 , V_195 ) ;
}
static void F_115 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
F_116 ( & V_2 -> V_2 ) ;
}
static void F_117 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
V_56 -> V_196 = NULL ;
F_90 ( V_2 ) ;
}
static int F_118 ( struct V_197 * V_198 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_79 ( V_56 -> V_155 ) ;
int V_84 ;
V_84 = F_119 ( V_198 , V_56 ) ;
if ( ! V_84 )
V_56 -> V_196 = V_2 ;
else
F_90 ( V_2 ) ;
return V_84 ;
}
static int F_120 ( struct V_197 * V_198 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_79 ( F_121 ( V_56 -> V_155 ) ) ;
int V_84 ;
V_84 = F_119 ( V_198 , V_56 ) ;
if ( ! V_84 )
V_56 -> V_196 = V_2 ;
else
F_90 ( V_2 ) ;
return V_84 ;
}
static int F_122 ( struct V_55 * V_56 , const unsigned char * V_91 , int V_3 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
int V_4 , V_37 ;
F_5 ( V_2 , L_21 , V_3 ) ;
F_7 ( V_2 -> V_11 . V_18 , V_3 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_123 ( & V_2 -> V_7 , V_91 , V_3 ) ;
V_37 = F_24 ( & V_2 -> V_7 ) ;
if ( V_37 < V_199 )
F_25 ( & V_2 -> V_52 , 1 ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_37 >= V_199 )
F_73 ( V_2 , false ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
return ( V_4 < 0 ) ? 0 : V_4 ;
}
static int F_124 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
int V_4 ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_21 , V_4 ) ;
return V_4 ;
}
static int F_125 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
int V_4 ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_71 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_21 , V_4 ) ;
return V_4 ;
}
static void F_126 ( struct V_55 * V_56 , char V_153 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
F_5 ( V_2 , L_26 , V_153 ) ;
F_78 ( V_2 , V_153 ) ;
}
static void F_127 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
++ V_2 -> V_11 . V_200 ;
}
static void F_128 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
F_5 ( V_2 , L_29 , ( F_33 ( V_56 ) != 0 ) ) ;
F_6 ( V_2 , V_2 -> V_11 . V_20 ) ;
F_31 ( & V_2 -> V_99 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_79 &= ~ V_82 ;
if ( F_33 ( V_56 ) )
V_2 -> V_79 |= V_81 ;
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static int F_129 ( struct V_1 * V_2 , unsigned long V_201 ,
struct V_202 * V_203 )
{
struct V_202 V_92 ;
int V_54 ;
V_92 = V_2 -> V_60 ;
V_54 = ( ( V_201 & V_59 && V_203 -> V_61 != V_92 . V_61 ) ||
( V_201 & V_62 && V_203 -> V_63 != V_92 . V_63 ) ||
( V_201 & V_64 && V_203 -> V_65 != V_92 . V_65 ) ||
( V_201 & V_66 && V_203 -> V_67 != V_92 . V_67 ) ) ;
* V_203 = V_92 ;
return V_54 ;
}
static int F_130 ( struct V_1 * V_2 , unsigned long V_201 )
{
struct V_202 V_203 ;
V_203 = V_2 -> V_60 ;
return F_131 ( V_2 -> V_2 . V_78 ,
F_129 ( V_2 , V_201 , & V_203 ) ) ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_204 T_3 * V_205 )
{
struct V_204 V_206 ;
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
V_206 . type = V_207 ;
V_206 . line = V_2 -> V_2 . V_56 -> V_155 ;
V_206 . V_108 = V_2 -> V_2 . V_108 ;
V_206 . V_208 = V_190 ;
V_206 . V_209 = 400000000 ;
V_206 . V_210 = V_2 -> V_2 . V_210 ;
return ( F_133 ( V_205 , & V_206 , sizeof( * V_205 ) ) ) ? - V_211 : 0 ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_204 T_3 * V_205 )
{
struct V_204 V_206 ;
if ( F_135 ( & V_206 , V_205 , sizeof( V_206 ) ) )
return - V_211 ;
if ( V_206 . V_212 != 0 || V_206 . V_2 != 0 || V_206 . V_213 != 0 ||
V_206 . V_209 != 400000000 )
return - V_214 ;
if ( ! F_136 ( V_215 ) ) {
if ( ( ( V_206 . V_108 & ~ V_216 ) !=
( V_2 -> V_2 . V_108 & ~ V_216 ) ) )
return - V_214 ;
} else
V_2 -> V_2 . V_210 = V_206 . V_210 * V_96 / 100 ;
return 0 ;
}
static int F_137 ( struct V_55 * V_56 , unsigned V_217 ,
unsigned long V_218 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
int V_84 ;
switch ( V_217 ) {
case V_219 :
F_80 ( & V_2 -> V_2 . V_220 ) ;
V_84 = F_132 ( V_2 , ( void T_3 * ) V_218 ) ;
F_82 ( & V_2 -> V_2 . V_220 ) ;
break;
case V_221 :
F_80 ( & V_2 -> V_2 . V_220 ) ;
V_84 = F_134 ( V_2 , ( void T_3 * ) V_218 ) ;
F_82 ( & V_2 -> V_2 . V_220 ) ;
break;
case V_222 :
V_84 = F_130 ( V_2 , V_218 ) ;
break;
default:
V_84 = - V_223 ;
}
return V_84 ;
}
static void F_138 ( struct V_55 * V_56 , struct V_224 * V_88 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
unsigned V_170 ;
F_2 ( & V_2 -> V_6 ) ;
V_170 = F_94 ( V_2 , V_56 ) ;
if ( ( V_170 == 0 ) && ( V_88 -> V_225 & V_226 ) )
V_2 -> V_79 &= ~ ( V_80 | V_81 ) ;
else if ( ( V_170 != 0 ) && ! ( V_88 -> V_225 & V_226 ) ) {
if ( F_33 ( V_56 ) || ! F_64 ( V_227 , & V_56 -> V_108 ) )
V_2 -> V_79 |= V_80 | V_81 ;
else
V_2 -> V_79 |= V_80 ;
}
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_88 -> V_225 & V_228 ) {
if ( ! F_33 ( V_56 ) ) {
V_56 -> V_70 = 0 ;
F_26 ( V_2 ) ;
}
} else if ( F_33 ( V_56 ) && ~ V_2 -> V_58 & V_66 ) {
V_56 -> V_70 = 1 ;
}
}
static int F_139 ( struct V_55 * V_56 , int V_229 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
long V_230 ;
F_5 ( V_2 , L_21 , V_229 ) ;
if ( V_229 == - 1 ) {
F_61 ( V_144 , & V_2 -> V_108 ) ;
V_230 = F_140 ( V_2 -> V_152 ,
! F_64 ( V_140 , & V_2 -> V_108 ) ,
10 ) ;
if ( V_230 == 0 || V_230 == - V_231 ) {
F_56 ( V_144 , & V_2 -> V_108 ) ;
F_26 ( V_2 ) ;
return - V_232 ;
}
}
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_83 = ( V_229 == - 1 ) ;
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_229 == 0 ) {
F_2 ( & V_2 -> V_6 ) ;
F_141 ( & V_2 -> V_7 ) ;
F_56 ( V_144 , & V_2 -> V_108 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
return 0 ;
}
static int F_142 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
unsigned V_233 ;
F_2 ( & V_2 -> V_6 ) ;
V_233 = ( V_2 -> V_79 & V_57 ) | ( V_2 -> V_58 & ~ V_57 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_30 , V_233 ) ;
return V_233 ;
}
static int F_143 ( struct V_55 * V_56 , unsigned V_234 , unsigned V_235 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
F_5 ( V_2 , L_31 , V_234 , V_235 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_79 &= ~ ( V_235 & V_57 & 0xffff ) ;
V_2 -> V_79 |= V_234 & V_57 & 0xffff ;
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_144 ( struct V_55 * V_56 ,
struct V_236 * V_60 )
{
struct V_1 * V_2 = V_56 -> V_196 ;
struct V_11 V_11 ;
memcpy ( & V_11 , & V_2 -> V_11 , sizeof( V_11 ) ) ;
if ( V_2 -> V_2 . V_168 )
(* V_2 -> V_237 -> V_11 )( & V_11 , V_2 -> V_238 ) ;
V_60 -> V_67 = V_2 -> V_60 . V_67 ;
V_60 -> V_63 = V_2 -> V_60 . V_63 ;
V_60 -> V_61 = V_2 -> V_60 . V_61 ;
V_60 -> V_65 = V_2 -> V_60 . V_65 ;
V_60 -> V_122 = V_2 -> V_60 . V_122 ;
V_60 -> V_137 = V_2 -> V_60 . V_137 + V_11 . V_154 ;
V_60 -> V_171 = V_2 -> V_60 . V_171 ;
V_60 -> V_116 = V_2 -> V_60 . V_116 ;
V_60 -> V_239 = V_2 -> V_60 . V_239 ;
V_60 -> V_94 = V_2 -> V_60 . V_94 ;
V_60 -> V_240 = V_2 -> V_60 . V_116 ;
return 0 ;
}
static void F_145 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 V_11 ;
memcpy ( & V_11 , & V_2 -> V_11 , sizeof( V_11 ) ) ;
if ( V_2 -> V_2 . V_168 )
(* V_2 -> V_237 -> V_11 )( & V_11 , V_2 -> V_238 ) ;
F_9 ( V_10 , L_32 , V_2 -> V_130 . V_131 ,
V_2 -> V_60 . V_137 + V_11 . V_154 , V_2 -> V_60 . V_122 ) ;
F_9 ( V_10 , L_33 , V_2 -> V_60 . V_67 ,
V_2 -> V_60 . V_63 , V_2 -> V_60 . V_61 , V_2 -> V_60 . V_65 ) ;
F_9 ( V_10 , L_34 , V_2 -> V_60 . V_171 ,
V_2 -> V_60 . V_116 , V_2 -> V_60 . V_239 , V_2 -> V_60 . V_94 ) ;
}
static void F_146 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 V_11 ;
memcpy ( & V_11 , & V_2 -> V_11 , sizeof( V_11 ) ) ;
if ( V_2 -> V_2 . V_168 )
(* V_2 -> V_237 -> V_11 )( & V_11 , V_2 -> V_238 ) ;
F_9 ( V_10 , L_35 , V_11 . V_138 ,
V_11 . V_145 , V_11 . V_147 , V_11 . V_123 ) ;
F_9 ( V_10 , L_36 , V_11 . V_149 , V_11 . V_200 ,
V_11 . V_112 ) ;
if ( V_2 -> V_2 . V_168 ) {
F_147 ( V_10 , L_37 ) ;
(* V_2 -> V_237 -> V_241 )( V_10 , V_2 -> V_238 ) ;
}
F_8 ( V_10 , & V_2 -> V_11 ) ;
}
static void F_148 ( struct V_9 * V_10 , struct V_42 * V_43 )
{
int V_46 = V_43 -> V_46 ;
F_20 () ;
F_9 ( V_10 , L_38 , F_149 ( & V_43 -> V_242 -> V_243 ) ) ;
F_9 ( V_10 , L_39 , V_43 -> V_50 , V_46 ) ;
F_9 ( V_10 , L_40 , V_43 -> V_51 ,
V_43 -> V_191 , ( unsigned long long ) V_43 -> V_244 ) ;
F_9 ( V_10 , L_41 , ( unsigned long long ) V_43 -> V_245 ) ;
F_9 ( V_10 , L_42 , ( unsigned long long ) V_43 -> V_87 ) ;
F_150 ( V_10 , '\n' ) ;
}
static int F_151 ( struct V_9 * V_10 , void * V_246 )
{
struct V_1 * V_2 ;
int V_162 ;
F_147 ( V_10 , L_43 ) ;
for ( V_162 = 0 ; V_162 < V_156 && ( V_2 = F_79 ( V_162 ) ) ; ++ V_162 ) {
F_9 ( V_10 , L_44 , V_162 ) ;
if ( F_136 ( V_215 ) )
F_145 ( V_10 , V_2 ) ;
F_90 ( V_2 ) ;
F_147 ( V_10 , L_45 ) ;
}
return 0 ;
}
static int F_152 ( struct V_9 * V_10 , void * V_246 )
{
struct V_160 * V_49 = V_10 -> V_247 ;
struct V_1 * V_2 ;
int V_162 ;
for ( V_162 = 0 ; V_162 < V_164 ; ++ V_162 ) {
V_2 = F_79 ( V_49 -> V_165 [ V_162 ] -> V_155 ) ;
if ( V_2 ) {
F_9 ( V_10 , L_44 , V_2 -> V_155 ) ;
F_145 ( V_10 , V_2 ) ;
F_146 ( V_10 , V_2 ) ;
F_90 ( V_2 ) ;
F_147 ( V_10 , L_45 ) ;
}
}
return 0 ;
}
static int F_153 ( struct V_9 * V_10 , void * V_246 )
{
struct V_160 * V_49 = V_10 -> V_247 ;
struct V_42 * V_43 ;
F_37 () ;
F_9 ( V_10 , L_46 ,
F_149 ( V_49 -> V_35 -> V_243 ) ,
( unsigned long long ) V_49 -> V_35 -> V_244 ) ;
F_154 (peer, &serial->peer_list, list)
F_148 ( V_10 , V_43 ) ;
F_39 () ;
return 0 ;
}
static int F_155 ( struct V_248 * V_248 , struct V_194 * V_195 )
{
return F_156 ( V_195 , F_151 , NULL ) ;
}
static int F_157 ( struct V_248 * V_248 , struct V_194 * V_195 )
{
return F_156 ( V_195 , F_152 , V_248 -> V_249 ) ;
}
static int F_158 ( struct V_248 * V_248 , struct V_194 * V_195 )
{
return F_156 ( V_195 , F_153 , V_248 -> V_249 ) ;
}
static inline int F_159 ( T_4 V_250 )
{
static const struct V_251 V_252 ;
switch ( F_160 ( V_250 ) ) {
case V_253 :
return sizeof( V_252 . V_254 ) + sizeof( V_252 . V_255 ) ;
case V_256 :
return sizeof( V_252 . V_254 ) + sizeof( V_252 . V_257 ) ;
case V_258 :
case V_259 :
case V_256 | V_260 :
case V_259 | V_260 :
return sizeof( V_252 . V_254 ) ;
default:
return - 1 ;
}
}
static inline void F_161 ( struct V_261 * V_262 ,
struct V_1 * V_2 )
{
T_5 V_87 = V_2 -> V_130 . V_131 ;
T_5 V_148 = V_2 -> V_130 . V_131 + 4 ;
T_1 V_263 = V_2 -> V_130 . V_133 - 4 ;
V_262 -> V_264 = F_162 ( V_87 >> 32 ) ;
V_262 -> V_265 = F_162 ( V_87 ) ;
V_262 -> V_266 = F_162 ( V_148 >> 32 ) ;
V_262 -> V_267 = F_162 ( V_148 ) ;
V_262 -> V_263 = F_162 ( V_263 ) ;
}
static inline void F_163 ( struct V_251 * V_252 ,
struct V_1 * V_2 )
{
V_252 -> V_254 . V_250 = F_164 ( V_253 ) ;
V_252 -> V_254 . V_37 = F_164 ( F_159 ( V_252 -> V_254 . V_250 ) ) ;
F_161 ( & V_252 -> V_255 , V_2 ) ;
}
static inline void F_165 ( struct V_251 * V_252 ,
struct V_1 * V_2 )
{
V_252 -> V_254 . V_250 = F_164 ( V_256 ) ;
V_252 -> V_254 . V_37 = F_164 ( F_159 ( V_252 -> V_254 . V_250 ) ) ;
F_161 ( & V_252 -> V_257 , V_2 ) ;
}
static inline void F_166 ( struct V_251 * V_252 )
{
V_252 -> V_254 . V_250 = F_164 ( V_256 | V_260 ) ;
V_252 -> V_254 . V_37 = F_164 ( F_159 ( V_252 -> V_254 . V_250 ) ) ;
}
static inline void F_167 ( struct V_251 * V_252 )
{
V_252 -> V_254 . V_250 = F_164 ( V_258 ) ;
V_252 -> V_254 . V_37 = F_164 ( F_159 ( V_252 -> V_254 . V_250 ) ) ;
}
static inline void F_168 ( struct V_251 * V_252 )
{
V_252 -> V_254 . V_250 = F_164 ( V_259 | V_260 ) ;
V_252 -> V_254 . V_37 = F_164 ( F_159 ( V_252 -> V_254 . V_250 ) ) ;
}
static inline void F_169 ( struct V_251 * V_252 )
{
V_252 -> V_254 . V_250 = F_164 ( V_259 ) ;
V_252 -> V_254 . V_37 = F_164 ( F_159 ( V_252 -> V_254 . V_250 ) ) ;
}
static void F_170 ( struct V_42 * V_43 ,
struct V_261 * V_262 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
V_43 -> V_87 = F_171 ( V_262 -> V_264 , V_262 -> V_265 ) ;
V_43 -> V_148 = F_171 ( V_262 -> V_266 , V_262 -> V_267 ) ;
V_43 -> V_263 = F_172 ( V_262 -> V_263 ) ;
F_173 ( V_43 , V_268 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_191 = F_11 ( V_43 -> V_191 , V_43 -> V_263 ) ;
F_174 ( & V_2 -> V_7 , V_2 -> V_191 ) ;
F_4 ( & V_43 -> V_2 -> V_6 ) ;
if ( V_2 -> V_2 . V_168 && V_2 -> V_237 -> V_269 != NULL )
(* V_2 -> V_237 -> V_269 )( V_270 , V_2 -> V_238 ) ;
F_175 ( & V_43 -> V_242 , L_47 ,
( unsigned long long ) V_43 -> V_244 , F_149 ( V_2 -> V_243 ) ) ;
}
static inline int F_176 ( struct V_42 * V_43 ,
struct V_251 * V_252 )
{
int V_46 ;
int V_23 , V_271 = 5 ;
do {
V_46 = V_43 -> V_46 ;
F_20 () ;
V_23 = F_177 ( V_43 -> V_49 -> V_35 ,
V_132 ,
V_43 -> V_50 ,
V_46 , V_43 -> V_51 ,
V_43 -> V_245 ,
V_252 , F_160 ( V_252 -> V_254 . V_37 ) ) ;
if ( V_23 == V_28 || V_23 == V_24 ||
V_23 == V_272 ) {
F_5 ( & V_43 -> V_242 , L_48 , V_23 ) ;
continue;
} else
break;
} while ( -- V_271 > 0 );
return V_23 ;
}
static struct V_1 * F_178 ( struct V_42 * V_43 ,
int V_155 )
{
struct V_1 * V_2 ;
if ( V_155 < 0 || V_155 >= V_164 )
return F_179 ( - V_273 ) ;
F_86 () ;
V_2 = V_43 -> V_49 -> V_165 [ V_155 ] ;
F_2 ( & V_2 -> V_6 ) ;
if ( ! F_67 ( V_2 -> V_43 ) )
F_180 ( V_2 -> V_43 , V_43 ) ;
else
V_2 = F_179 ( - V_161 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_2 ;
}
static struct V_1 * F_181 ( struct V_42 * V_43 )
{
struct V_1 * * V_165 = V_43 -> V_49 -> V_165 ;
int V_162 ;
F_86 () ;
for ( V_162 = 0 ; V_162 < V_274 ; ++ V_162 ) {
F_2 ( & V_165 [ V_162 ] -> V_6 ) ;
if ( ! V_165 [ V_162 ] -> V_43 ) {
F_180 ( V_165 [ V_162 ] -> V_43 , V_43 ) ;
F_4 ( & V_165 [ V_162 ] -> V_6 ) ;
return V_165 [ V_162 ] ;
}
F_4 ( & V_165 [ V_162 ] -> V_6 ) ;
}
return NULL ;
}
static void F_182 ( struct V_1 * V_2 , bool V_275 )
{
if ( V_275 )
F_27 ( V_2 , 0 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_191 = F_183 ( V_276 ) ;
F_174 ( & V_2 -> V_7 , V_2 -> V_191 ) ;
F_180 ( V_2 -> V_43 , NULL ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_2 . V_168 && V_2 -> V_237 -> V_269 != NULL )
(* V_2 -> V_237 -> V_269 )( V_277 , V_2 -> V_238 ) ;
}
static void F_184 ( unsigned long V_102 )
{
struct V_42 * V_43 = (struct V_42 * ) V_102 ;
struct V_1 * V_2 ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_229 != V_278 ) {
F_4 ( & V_43 -> V_6 ) ;
return;
}
V_2 = F_185 ( V_43 ) ;
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_182 ( V_2 , false ) ;
}
static int F_186 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_251 * V_252 ;
int V_84 , V_23 ;
V_252 = F_58 ( sizeof( * V_252 ) , V_193 ) ;
if ( ! V_252 )
return - V_48 ;
V_2 = F_181 ( V_43 ) ;
if ( ! V_2 ) {
F_187 ( & V_43 -> V_242 , L_49 ) ;
V_84 = - V_161 ;
goto V_279;
}
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_229 != V_280 ) {
V_84 = - V_161 ;
goto V_281;
}
V_43 -> V_2 = V_2 ;
F_173 ( V_43 , V_278 ) ;
F_163 ( V_252 , V_43 -> V_2 ) ;
F_188 ( & V_43 -> V_282 , F_184 , ( unsigned long ) V_43 ) ;
F_189 ( & V_43 -> V_282 , V_75 + V_283 ) ;
F_4 ( & V_43 -> V_6 ) ;
V_23 = F_176 ( V_43 , V_252 ) ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_229 == V_278 && V_23 != V_39 ) {
if ( V_23 == V_134 )
V_84 = - V_142 ;
else
V_84 = - V_121 ;
goto V_284;
}
F_4 ( & V_43 -> V_6 ) ;
F_54 ( V_252 ) ;
return 0 ;
V_284:
F_190 ( & V_43 -> V_282 ) ;
F_185 ( V_43 ) ;
V_281:
F_4 ( & V_43 -> V_6 ) ;
F_182 ( V_2 , false ) ;
V_279:
F_54 ( V_252 ) ;
return V_84 ;
}
static void F_191 ( struct V_197 * V_198 ,
struct V_1 * V_2 )
{
struct V_55 * V_56 ;
F_80 ( & V_2 -> V_2 . V_220 ) ;
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 ) {
F_46 ( V_56 ) ;
F_32 ( V_56 ) ;
}
F_82 ( & V_2 -> V_2 . V_220 ) ;
if ( V_198 == V_285 )
F_192 ( V_198 , F_193 ( V_2 ) ) ;
else
F_192 ( V_198 , V_2 -> V_155 ) ;
}
static struct V_160 * F_194 ( struct V_34 * V_35 )
{
struct V_160 * V_49 ;
F_195 (serial, &fwserial_list, list) {
if ( V_35 == V_49 -> V_35 )
return V_49 ;
}
return NULL ;
}
static struct V_160 * F_196 ( struct V_34 * V_35 )
{
struct V_160 * V_49 ;
F_154 (serial, &fwserial_list, list) {
if ( V_35 == V_49 -> V_35 )
return V_49 ;
}
return NULL ;
}
static struct V_42 * F_66 ( struct V_34 * V_35 ,
int V_46 , int V_286 )
{
struct V_160 * V_49 ;
struct V_42 * V_43 ;
V_49 = F_196 ( V_35 ) ;
if ( ! V_49 ) {
F_187 ( V_35 , L_50 ,
( unsigned long long ) V_35 -> V_244 ) ;
return NULL ;
}
F_154 (peer, &serial->peer_list, list) {
int V_287 = V_43 -> V_46 ;
F_20 () ;
if ( V_46 == V_287 && V_286 == V_43 -> V_50 )
return V_43 ;
}
return NULL ;
}
static void F_197 ( struct V_34 * V_35 )
{
struct V_160 * V_49 ;
struct V_42 * V_43 ;
V_49 = F_196 ( V_35 ) ;
if ( ! V_49 )
return;
F_154 (peer, &serial->peer_list, list) {
int V_287 = V_43 -> V_46 ;
F_20 () ;
F_5 ( V_35 , L_51 ,
V_287 , V_43 -> V_50 , ( unsigned long long ) V_43 -> V_244 ) ;
}
}
static void F_198 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_199 ( F_48 ( V_90 ) , V_288 ) ;
int V_84 ;
V_84 = F_186 ( V_43 ) ;
if ( V_84 == - V_142 && ++ V_43 -> V_289 < V_290 )
F_25 ( & V_43 -> V_288 , V_291 ) ;
}
static int F_200 ( struct V_160 * V_49 , struct V_292 * V_242 )
{
struct V_243 * V_293 = & V_242 -> V_243 ;
struct V_21 * V_294 = F_201 ( V_242 ) ;
struct V_42 * V_43 ;
struct V_295 V_296 ;
int V_297 , V_298 ;
int V_46 ;
V_43 = F_202 ( sizeof( * V_43 ) , V_193 ) ;
if ( ! V_43 )
return - V_48 ;
F_173 ( V_43 , V_280 ) ;
F_203 ( V_293 , V_43 ) ;
V_43 -> V_242 = V_242 ;
V_43 -> V_244 = ( T_5 ) V_294 -> V_299 [ 3 ] << 32 | V_294 -> V_299 [ 4 ] ;
V_43 -> V_51 = V_294 -> V_300 ;
V_43 -> V_191 = F_11 ( F_10 ( V_294 ) ,
F_183 ( V_43 -> V_51 ) ) ;
V_46 = V_294 -> V_46 ;
F_20 () ;
V_43 -> V_50 = V_294 -> V_50 ;
F_204 () ;
V_43 -> V_46 = V_46 ;
F_205 ( & V_296 , V_242 -> V_301 ) ;
while ( F_206 ( & V_296 , & V_297 , & V_298 ) ) {
if ( V_297 == ( V_302 | V_303 ) ) {
V_43 -> V_245 = V_304 + 4 * V_298 ;
break;
}
}
if ( V_43 -> V_245 == 0ULL ) {
F_173 ( V_43 , V_305 ) ;
}
F_207 ( & V_43 -> V_6 ) ;
V_43 -> V_2 = NULL ;
F_15 ( & V_43 -> V_282 ) ;
F_208 ( & V_43 -> V_90 , NULL ) ;
F_209 ( & V_43 -> V_288 , F_198 ) ;
V_43 -> V_49 = V_49 ;
F_210 ( & V_43 -> V_105 , & V_49 -> V_306 ) ;
F_175 ( & V_43 -> V_242 , L_52 ,
( unsigned long long ) V_43 -> V_244 ) ;
if ( V_294 -> V_307 ) {
V_49 -> V_308 = V_43 ;
if ( V_309 ) {
struct V_1 * V_2 ;
V_2 = F_178 ( V_43 , V_274 ) ;
if ( ! F_211 ( V_2 ) ) {
struct V_261 V_262 ;
F_2 ( & V_43 -> V_6 ) ;
V_43 -> V_2 = V_2 ;
F_161 ( & V_262 , V_2 ) ;
F_170 ( V_43 , & V_262 ) ;
F_4 ( & V_43 -> V_6 ) ;
F_40 ( V_2 ) ;
}
}
} else if ( V_310 ) {
F_25 ( & V_43 -> V_288 , 1 ) ;
}
return 0 ;
}
static void F_212 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
F_2 ( & V_43 -> V_6 ) ;
F_173 ( V_43 , V_311 ) ;
F_4 ( & V_43 -> V_6 ) ;
F_108 ( & V_43 -> V_288 ) ;
F_109 ( & V_43 -> V_90 ) ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 == V_43 -> V_49 -> V_308 )
V_43 -> V_49 -> V_308 = NULL ;
F_190 ( & V_43 -> V_282 ) ;
V_2 = V_43 -> V_2 ;
V_43 -> V_2 = NULL ;
F_213 ( & V_43 -> V_105 ) ;
F_175 ( & V_43 -> V_242 , L_53 ,
( unsigned long long ) V_43 -> V_244 ) ;
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_182 ( V_2 , true ) ;
F_86 () ;
F_54 ( V_43 ) ;
}
static int F_214 ( struct V_292 * V_242 )
{
struct V_21 * V_294 = F_201 ( V_242 ) ;
struct V_34 * V_35 = V_294 -> V_35 ;
struct V_160 * V_49 ;
struct V_1 * V_2 ;
struct V_243 * V_312 ;
int V_162 , V_14 ;
int V_84 ;
V_49 = F_202 ( sizeof( * V_49 ) , V_193 ) ;
if ( ! V_49 )
return - V_48 ;
F_215 ( & V_49 -> V_159 ) ;
V_49 -> V_35 = V_35 ;
F_59 ( & V_49 -> V_306 ) ;
for ( V_162 = 0 ; V_162 < V_164 ; ++ V_162 ) {
V_2 = F_202 ( sizeof( * V_2 ) , V_193 ) ;
if ( ! V_2 ) {
V_84 = - V_48 ;
goto V_313;
}
F_216 ( & V_2 -> V_2 ) ;
V_2 -> V_155 = V_314 ;
V_2 -> V_2 . V_315 = & V_316 ;
V_2 -> V_49 = V_49 ;
F_207 ( & V_2 -> V_6 ) ;
F_209 ( & V_2 -> V_52 , F_77 ) ;
F_209 ( & V_2 -> V_76 , F_47 ) ;
F_208 ( & V_2 -> V_69 , F_42 ) ;
F_208 ( & V_2 -> V_99 , F_51 ) ;
F_59 ( & V_2 -> V_106 ) ;
F_217 ( & V_2 -> V_152 ) ;
V_2 -> V_191 = F_183 ( V_276 ) ;
F_218 ( & V_2 -> V_7 ) ;
F_180 ( V_2 -> V_43 , NULL ) ;
V_49 -> V_165 [ V_162 ] = V_2 ;
V_2 -> V_130 . V_133 = V_317 + 4 ;
V_2 -> V_130 . V_318 = F_65 ;
V_2 -> V_130 . V_128 = V_2 ;
V_84 = F_219 ( & V_2 -> V_130 ,
& V_319 ) ;
if ( V_84 ) {
F_54 ( V_2 ) ;
goto V_313;
}
}
V_84 = F_83 ( V_49 ) ;
if ( V_84 ) {
F_187 ( & V_242 , L_54 ) ;
goto V_313;
}
for ( V_14 = 0 ; V_14 < V_274 ; ++ V_14 ) {
V_312 = F_220 ( & V_49 -> V_165 [ V_14 ] -> V_2 ,
V_320 ,
V_49 -> V_165 [ V_14 ] -> V_155 ,
V_35 -> V_243 ) ;
if ( F_211 ( V_312 ) ) {
V_84 = F_221 ( V_312 ) ;
F_187 ( & V_242 , L_55 ,
V_84 ) ;
goto V_321;
}
V_49 -> V_165 [ V_14 ] -> V_243 = V_312 ;
}
if ( V_309 ) {
struct V_243 * V_322 ;
V_322 = F_220 ( & V_49 -> V_165 [ V_14 ] -> V_2 ,
V_285 ,
F_193 ( V_49 -> V_165 [ V_14 ] ) ,
V_35 -> V_243 ) ;
if ( F_211 ( V_322 ) ) {
V_84 = F_221 ( V_322 ) ;
F_187 ( & V_242 , L_56 ,
V_84 ) ;
goto V_321;
}
V_49 -> V_165 [ V_14 ] -> V_243 = V_322 ;
V_49 -> V_165 [ V_14 ] -> V_71 = true ;
}
if ( ! F_222 ( V_323 ) ) {
V_49 -> V_324 = F_223 ( F_149 ( & V_242 -> V_243 ) ,
V_323 ) ;
if ( ! F_222 ( V_49 -> V_324 ) ) {
F_224 ( L_57 , 0444 , V_49 -> V_324 ,
V_49 , & V_325 ) ;
F_224 ( L_58 , 0444 , V_49 -> V_324 ,
V_49 , & V_326 ) ;
}
}
F_210 ( & V_49 -> V_105 , & V_327 ) ;
F_225 ( & V_242 , L_59 ,
F_149 ( V_35 -> V_243 ) , ( unsigned long long ) V_35 -> V_244 ) ;
V_84 = F_200 ( V_49 , V_242 ) ;
if ( ! V_84 )
return 0 ;
F_187 ( & V_242 , L_60 , V_84 ) ;
F_226 ( V_49 -> V_324 ) ;
F_213 ( & V_49 -> V_105 ) ;
if ( V_309 )
F_192 ( V_285 ,
F_193 ( V_49 -> V_165 [ V_14 ] ) ) ;
V_321:
for ( -- V_14 ; V_14 >= 0 ; -- V_14 )
F_192 ( V_320 , V_49 -> V_165 [ V_14 ] -> V_155 ) ;
F_91 ( & V_49 -> V_159 , F_84 ) ;
return V_84 ;
V_313:
for ( -- V_162 ; V_162 >= 0 ; -- V_162 ) {
F_89 ( & V_49 -> V_165 [ V_162 ] -> V_2 ) ;
F_54 ( V_49 -> V_165 [ V_162 ] ) ;
}
F_54 ( V_49 ) ;
return V_84 ;
}
static int F_227 ( struct V_292 * V_242 ,
const struct V_328 * V_286 )
{
struct V_160 * V_49 ;
int V_84 ;
F_80 ( & V_329 ) ;
V_49 = F_194 ( F_201 ( V_242 ) -> V_35 ) ;
if ( ! V_49 )
V_84 = F_214 ( V_242 ) ;
else
V_84 = F_200 ( V_49 , V_242 ) ;
F_82 ( & V_329 ) ;
return V_84 ;
}
static void F_228 ( struct V_292 * V_242 )
{
struct V_42 * V_43 = F_229 ( & V_242 -> V_243 ) ;
struct V_160 * V_49 = V_43 -> V_49 ;
int V_162 ;
F_80 ( & V_329 ) ;
F_212 ( V_43 ) ;
if ( F_55 ( & V_49 -> V_306 ) ) {
F_213 ( & V_49 -> V_105 ) ;
F_226 ( V_49 -> V_324 ) ;
for ( V_162 = 0 ; V_162 < V_274 ; ++ V_162 )
F_191 ( V_320 , V_49 -> V_165 [ V_162 ] ) ;
if ( V_309 )
F_191 ( V_285 , V_49 -> V_165 [ V_162 ] ) ;
F_91 ( & V_49 -> V_159 , F_84 ) ;
}
F_82 ( & V_329 ) ;
}
static void F_230 ( struct V_292 * V_242 )
{
struct V_21 * V_294 = F_201 ( V_242 ) ;
struct V_42 * V_43 = F_229 ( & V_242 -> V_243 ) ;
int V_46 ;
V_46 = V_294 -> V_46 ;
F_20 () ;
V_43 -> V_50 = V_294 -> V_50 ;
F_204 () ;
V_43 -> V_46 = V_46 ;
}
static void F_231 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_199 ( V_90 , V_90 ) ;
struct V_261 * V_255 = & V_43 -> V_330 . V_255 ;
struct V_1 * V_2 ;
struct V_251 * V_252 ;
int V_23 ;
V_252 = F_58 ( sizeof( * V_252 ) , V_193 ) ;
if ( ! V_252 )
return;
V_2 = F_181 ( V_43 ) ;
F_2 ( & V_43 -> V_6 ) ;
switch ( V_43 -> V_229 ) {
case V_280 :
if ( ! V_2 ) {
F_187 ( & V_43 -> V_242 , L_61 ) ;
F_166 ( V_252 ) ;
} else {
V_43 -> V_2 = V_2 ;
F_165 ( V_252 , V_43 -> V_2 ) ;
F_173 ( V_43 , V_331 ) ;
V_2 = NULL ;
}
break;
case V_278 :
if ( V_43 -> V_49 -> V_35 -> V_244 > V_43 -> V_244 )
goto V_332;
F_190 ( & V_43 -> V_282 ) ;
F_165 ( V_252 , V_43 -> V_2 ) ;
F_173 ( V_43 , V_331 ) ;
break;
default:
F_166 ( V_252 ) ;
}
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_182 ( V_2 , false ) ;
V_23 = F_176 ( V_43 , V_252 ) ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_229 == V_331 ) {
if ( V_23 == V_39 ) {
struct V_1 * V_206 = V_43 -> V_2 ;
F_170 ( V_43 , V_255 ) ;
F_4 ( & V_43 -> V_6 ) ;
F_40 ( V_206 ) ;
F_2 ( & V_43 -> V_6 ) ;
} else {
F_187 ( & V_43 -> V_242 , L_62 , V_23 ) ;
V_2 = F_185 ( V_43 ) ;
}
}
V_332:
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_182 ( V_2 , false ) ;
F_54 ( V_252 ) ;
return;
}
static void F_232 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_199 ( V_90 , V_90 ) ;
struct V_1 * V_2 = NULL ;
struct V_251 * V_252 ;
int V_23 ;
V_252 = F_58 ( sizeof( * V_252 ) , V_193 ) ;
if ( ! V_252 )
return;
F_2 ( & V_43 -> V_6 ) ;
switch ( V_43 -> V_229 ) {
case V_268 :
F_169 ( V_252 ) ;
F_173 ( V_43 , V_333 ) ;
break;
case V_334 :
if ( V_43 -> V_49 -> V_35 -> V_244 > V_43 -> V_244 )
goto V_332;
F_190 ( & V_43 -> V_282 ) ;
F_169 ( V_252 ) ;
F_173 ( V_43 , V_333 ) ;
break;
default:
F_168 ( V_252 ) ;
}
F_4 ( & V_43 -> V_6 ) ;
V_23 = F_176 ( V_43 , V_252 ) ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_229 == V_333 ) {
if ( V_23 != V_39 )
F_187 ( & V_43 -> V_242 , L_63 ,
V_23 ) ;
V_2 = F_185 ( V_43 ) ;
}
V_332:
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_182 ( V_2 , true ) ;
F_54 ( V_252 ) ;
return;
}
static int F_233 ( struct V_42 * V_43 ,
struct V_251 * V_252 ,
unsigned long long V_45 ,
T_1 V_37 )
{
struct V_1 * V_2 = NULL ;
bool V_275 = false ;
int V_23 ;
if ( V_45 != V_335 . V_131 || V_37 < sizeof( V_252 -> V_254 ) )
return V_25 ;
if ( V_37 != F_160 ( V_252 -> V_254 . V_37 ) ||
V_37 != F_159 ( V_252 -> V_254 . V_250 ) )
return V_26 ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_229 == V_311 ) {
F_187 ( & V_43 -> V_242 , L_64 ) ;
F_4 ( & V_43 -> V_6 ) ;
return V_25 ;
}
V_23 = V_39 ;
F_5 ( & V_43 -> V_242 , L_65 , V_252 -> V_254 . V_250 ) ;
switch ( F_160 ( V_252 -> V_254 . V_250 ) & V_336 ) {
case V_253 :
if ( F_234 ( & V_43 -> V_90 ) ) {
F_187 ( & V_43 -> V_242 , L_66 ) ;
V_23 = V_134 ;
} else {
V_43 -> V_330 . V_255 = V_252 -> V_255 ;
F_235 ( & V_43 -> V_90 , F_231 ) ;
F_236 ( V_337 , & V_43 -> V_90 ) ;
}
break;
case V_256 :
if ( V_43 -> V_229 != V_278 ) {
V_23 = V_134 ;
} else if ( F_160 ( V_252 -> V_254 . V_250 ) & V_260 ) {
F_225 ( & V_43 -> V_242 , L_67 ) ;
V_2 = F_185 ( V_43 ) ;
} else {
struct V_1 * V_206 = V_43 -> V_2 ;
F_170 ( V_43 , & V_252 -> V_257 ) ;
F_4 ( & V_43 -> V_6 ) ;
F_40 ( V_206 ) ;
F_2 ( & V_43 -> V_6 ) ;
}
break;
case V_258 :
if ( F_234 ( & V_43 -> V_90 ) ) {
F_187 ( & V_43 -> V_242 , L_68 ) ;
V_23 = V_134 ;
} else {
F_235 ( & V_43 -> V_90 , F_232 ) ;
F_236 ( V_337 , & V_43 -> V_90 ) ;
}
break;
case V_259 :
if ( V_43 -> V_229 != V_334 )
V_23 = V_134 ;
else {
if ( F_160 ( V_252 -> V_254 . V_250 ) & V_260 )
F_225 ( & V_43 -> V_242 , L_69 ) ;
V_2 = F_185 ( V_43 ) ;
V_275 = true ;
}
break;
default:
F_187 ( & V_43 -> V_242 , L_70 ,
F_160 ( V_252 -> V_254 . V_250 ) ) ;
V_23 = V_26 ;
}
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_182 ( V_2 , V_275 ) ;
return V_23 ;
}
static void F_237 ( struct V_34 * V_35 ,
struct V_124 * V_125 ,
int V_44 , int V_126 , int V_127 ,
int V_46 ,
unsigned long long V_45 ,
void * V_102 , T_1 V_37 ,
void * V_128 )
{
struct V_251 * V_252 = V_102 ;
struct V_42 * V_43 ;
int V_23 ;
F_37 () ;
V_43 = F_66 ( V_35 , V_46 , V_127 ) ;
if ( ! V_43 ) {
F_5 ( V_35 , L_71 , V_46 , V_127 ) ;
F_197 ( V_35 ) ;
V_23 = V_134 ;
} else {
switch ( V_44 ) {
case V_132 :
V_23 = F_233 ( V_43 , V_252 , V_45 , V_37 ) ;
break;
default:
V_23 = V_135 ;
}
}
F_39 () ;
F_68 ( V_35 , V_125 , V_23 ) ;
}
static int T_6 F_238 ( void )
{
int V_84 , V_338 = ! ! ( V_309 ) ;
V_323 = F_223 ( V_339 , NULL ) ;
if ( V_274 + V_338 > V_340 )
V_274 = V_340 - V_338 ;
V_164 = V_274 + V_338 ;
V_320 = F_239 ( V_156 , V_341
| V_342 ) ;
if ( F_211 ( V_320 ) ) {
V_84 = F_221 ( V_320 ) ;
return V_84 ;
}
V_320 -> V_343 = V_339 ;
V_320 -> V_344 = V_345 ;
V_320 -> V_346 = 0 ;
V_320 -> V_347 = 0 ;
V_320 -> type = V_348 ;
V_320 -> V_349 = V_350 ;
V_320 -> V_351 = V_352 ;
V_320 -> V_351 . V_225 |= V_353 ;
F_240 ( V_320 , & V_354 ) ;
V_84 = F_241 ( V_320 ) ;
if ( V_84 ) {
F_242 ( L_72 , V_84 ) ;
goto V_355;
}
if ( V_309 ) {
V_285 = F_239 ( V_156 / V_164 ,
V_341
| V_342 ) ;
if ( F_211 ( V_285 ) ) {
V_84 = F_221 ( V_285 ) ;
goto V_356;
}
V_285 -> V_343 = V_339 L_73 ;
V_285 -> V_344 = V_357 ;
V_285 -> V_346 = 0 ;
V_285 -> V_347 = 0 ;
V_285 -> type = V_348 ;
V_285 -> V_349 = V_350 ;
V_285 -> V_351 = V_352 ;
V_285 -> V_351 . V_225 |= V_353 ;
F_240 ( V_285 , & V_358 ) ;
V_84 = F_241 ( V_285 ) ;
if ( V_84 ) {
F_242 ( L_74 , V_84 ) ;
goto V_359;
}
}
V_41 = F_243 ( L_75 ,
sizeof( struct V_30 ) ,
0 , 0 , F_14 ) ;
if ( ! V_41 ) {
V_84 = - V_48 ;
goto V_360;
}
V_335 . V_133 = sizeof( struct V_251 ) ;
V_335 . V_318 = F_237 ;
V_84 = F_219 ( & V_335 ,
& V_361 ) ;
if ( V_84 ) {
F_242 ( L_76 , V_84 ) ;
goto V_362;
}
V_363 . V_364 =
F_244 ( V_335 . V_131 ) ;
V_84 = F_245 ( & V_365 ) ;
if ( V_84 ) {
F_242 ( L_77 , V_84 ) ;
goto V_366;
}
V_84 = F_246 ( & V_367 . V_198 ) ;
if ( V_84 ) {
F_242 ( L_78 , V_84 ) ;
goto V_368;
}
return 0 ;
V_368:
F_247 ( & V_365 ) ;
V_366:
F_88 ( & V_335 ) ;
V_362:
F_248 ( V_41 ) ;
V_360:
if ( V_309 )
F_249 ( V_285 ) ;
V_359:
if ( V_309 )
F_250 ( V_285 ) ;
V_356:
F_249 ( V_320 ) ;
V_355:
F_250 ( V_320 ) ;
F_226 ( V_323 ) ;
return V_84 ;
}
static void T_7 F_251 ( void )
{
F_252 ( & V_367 . V_198 ) ;
F_247 ( & V_365 ) ;
F_88 ( & V_335 ) ;
F_248 ( V_41 ) ;
if ( V_309 ) {
F_249 ( V_285 ) ;
F_250 ( V_285 ) ;
}
F_249 ( V_320 ) ;
F_250 ( V_320 ) ;
F_226 ( V_323 ) ;
}
