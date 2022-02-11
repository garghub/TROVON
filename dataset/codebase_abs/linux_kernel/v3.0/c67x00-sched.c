static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( V_7 , L_1 , V_5 , V_4 -> V_8 ) ;
F_3 ( V_7 , L_2 , V_4 -> V_9 ) ;
F_3 ( V_7 , L_3 , F_4 ( V_4 -> V_10 ) ) ;
F_3 ( V_7 , L_4 , F_5 ( V_4 -> V_10 ) ) ;
F_3 ( V_7 , L_5 , F_6 ( V_4 ) ) ;
F_3 ( V_7 , L_6 , F_7 ( V_4 ) ) ;
F_3 ( V_7 , L_7 , V_4 -> V_11 ) ;
F_3 ( V_7 , L_8 , V_4 -> V_12 ) ;
F_3 ( V_7 , L_9 , V_4 -> V_13 ) ;
F_3 ( V_7 , L_10 , V_4 -> V_14 ) ;
F_3 ( V_7 , L_11 , V_4 -> V_15 ) ;
F_3 ( V_7 , L_12 , V_4 -> V_16 ) ;
F_3 ( V_7 , L_13 , F_8 ( V_4 ) ) ;
F_3 ( V_7 , L_14 ) ;
F_9 ( V_17 , L_15 , V_18 , 16 , 1 ,
V_4 -> V_19 , F_10 ( V_4 ) , 1 ) ;
}
static inline void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 ) { }
static inline T_1 F_11 ( struct V_1 * V_2 )
{
return F_12 ( V_2 -> V_20 ) & V_21 ;
}
static inline T_1 F_13 ( T_1 V_22 , T_1 V_23 )
{
return ( V_22 + V_23 ) & V_21 ;
}
static inline int F_14 ( T_1 V_22 , T_1 V_23 )
{
return ( ( V_21 + V_22 - V_23 ) & V_21 ) <
( V_21 / 2 ) ;
}
static inline int F_15 ( T_1 V_22 , T_1 V_23 )
{
return ( ( V_21 + 1 + V_22 - V_23 ) & V_21 ) <
( V_21 / 2 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_3 * V_4 ;
struct V_24 * V_25 ;
F_17 ( ! V_9 ) ;
V_2 -> V_26 -- ;
if ( F_18 ( V_9 -> V_10 ) == V_27 ) {
V_2 -> V_28 -- ;
if ( V_2 -> V_28 == 0 )
V_2 -> V_29 = V_30 ;
}
F_19 (td, &c67x00->td_list, td_list)
if ( V_9 == V_4 -> V_9 )
V_4 -> V_9 = NULL ;
V_25 = V_9 -> V_31 ;
V_9 -> V_31 = NULL ;
F_20 ( & V_25 -> V_32 ) ;
F_21 ( V_25 ) ;
}
static struct V_33 *
F_22 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_34 * V_35 = V_9 -> V_36 ;
struct V_33 * V_37 ;
int type ;
V_2 -> V_38 = F_11 ( V_2 ) ;
if ( V_35 -> V_31 ) {
V_37 = V_35 -> V_31 ;
if ( F_14 ( V_2 -> V_38 , V_37 -> V_39 ) )
V_37 -> V_39 =
F_13 ( V_2 -> V_38 , 1 ) ;
return V_35 -> V_31 ;
}
V_37 = F_23 ( sizeof( * V_37 ) , V_40 ) ;
if ( ! V_37 )
return NULL ;
F_24 ( & V_37 -> V_41 ) ;
F_24 ( & V_37 -> V_42 ) ;
V_37 -> V_35 = V_35 ;
V_37 -> V_7 = F_25 ( V_9 -> V_7 ) ;
V_35 -> V_31 = V_37 ;
V_37 -> V_39 = F_13 ( V_2 -> V_38 , 1 ) ;
type = F_18 ( V_9 -> V_10 ) ;
if ( F_26 ( & V_37 -> V_42 ) ) {
F_27 ( & V_37 -> V_42 , & V_2 -> V_43 [ type ] ) ;
} else {
struct V_33 * V_44 ;
F_19 (prev, &c67x00->list[type], node) {
if ( V_44 -> V_35 -> V_45 . V_46 >
V_35 -> V_45 . V_46 ) {
F_27 ( & V_37 -> V_42 , V_44 -> V_42 . V_44 ) ;
break;
}
}
}
return V_37 ;
}
static int F_28 ( struct V_34 * V_35 )
{
struct V_33 * V_37 = V_35 -> V_31 ;
if ( ! V_37 )
return 0 ;
if ( ! F_26 ( & V_37 -> V_41 ) )
return - V_47 ;
F_29 ( V_37 -> V_7 ) ;
F_20 ( & V_37 -> V_41 ) ;
F_20 ( & V_37 -> V_42 ) ;
F_21 ( V_37 ) ;
V_35 -> V_31 = NULL ;
return 0 ;
}
void F_30 ( struct V_48 * V_49 , struct V_34 * V_36 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
unsigned long V_50 ;
if ( ! F_26 ( & V_36 -> V_51 ) )
F_32 ( F_2 ( V_2 ) , L_16 ) ;
F_33 ( & V_2 -> V_52 , V_50 ) ;
while ( F_28 ( V_36 ) ) {
F_34 ( & V_2 -> V_52 , V_50 ) ;
F_35 ( V_2 -> V_53 ) ;
F_36 ( V_2 ) ;
F_37 ( & V_2 -> V_53 , 1 * V_54 ) ;
F_33 ( & V_2 -> V_52 , V_50 ) ;
}
F_34 ( & V_2 -> V_52 , V_50 ) ;
}
static inline int F_38 ( struct V_55 * V_7 )
{
while ( V_7 -> V_56 -> V_56 )
V_7 = V_7 -> V_56 ;
return V_7 -> V_57 ;
}
int F_39 ( struct V_48 * V_49 ,
struct V_9 * V_9 , T_2 V_58 )
{
int V_59 ;
unsigned long V_50 ;
struct V_24 * V_25 ;
struct V_1 * V_2 = F_31 ( V_49 ) ;
int V_60 = F_38 ( V_9 -> V_7 ) - 1 ;
F_33 ( & V_2 -> V_52 , V_50 ) ;
if ( ! F_40 ( V_49 -> V_61 ) ) {
V_59 = - V_62 ;
goto V_63;
}
V_59 = F_41 ( V_49 , V_9 ) ;
if ( V_59 )
goto V_63;
V_25 = F_23 ( sizeof( * V_25 ) , V_58 ) ;
if ( ! V_25 ) {
V_59 = - V_64 ;
goto V_65;
}
F_24 ( & V_25 -> V_32 ) ;
V_25 -> V_9 = V_9 ;
V_25 -> V_60 = V_60 ;
V_25 -> V_37 = F_22 ( V_2 , V_9 ) ;
if ( ! V_25 -> V_37 ) {
V_59 = - V_64 ;
goto V_66;
}
V_9 -> V_31 = V_25 ;
V_9 -> V_67 = 0 ;
switch ( F_18 ( V_9 -> V_10 ) ) {
case V_68 :
V_9 -> V_69 = V_70 ;
break;
case V_71 :
break;
case V_72 :
break;
case V_27 :
if ( V_2 -> V_28 == 0 )
V_2 -> V_29 = V_73 ;
V_2 -> V_28 ++ ;
if ( F_26 ( & V_25 -> V_37 -> V_41 ) )
V_9 -> V_74 = V_25 -> V_37 -> V_39 ;
else {
struct V_9 * V_75 ;
V_75 = F_42 ( V_25 -> V_37 -> V_41 . V_44 ,
struct V_24 ,
V_32 ) -> V_9 ;
V_9 -> V_74 =
F_13 ( V_75 -> V_74 ,
V_75 -> V_76 *
V_75 -> V_69 ) ;
}
V_25 -> V_77 = 0 ;
break;
}
F_43 ( & V_25 -> V_32 , & V_25 -> V_37 -> V_41 ) ;
if ( ! V_2 -> V_26 ++ )
F_44 ( V_2 -> V_20 ) ;
F_36 ( V_2 ) ;
F_34 ( & V_2 -> V_52 , V_50 ) ;
return 0 ;
V_66:
F_21 ( V_25 ) ;
V_65:
F_45 ( V_49 , V_9 ) ;
V_63:
F_34 ( & V_2 -> V_52 , V_50 ) ;
return V_59 ;
}
int F_46 ( struct V_48 * V_49 , struct V_9 * V_9 , int V_14 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
unsigned long V_50 ;
int V_78 ;
F_33 ( & V_2 -> V_52 , V_50 ) ;
V_78 = F_47 ( V_49 , V_9 , V_14 ) ;
if ( V_78 )
goto V_79;
F_16 ( V_2 , V_9 ) ;
F_45 ( V_49 , V_9 ) ;
F_48 ( & V_2 -> V_52 ) ;
F_49 ( V_49 , V_9 , V_14 ) ;
F_50 ( & V_2 -> V_52 ) ;
F_34 ( & V_2 -> V_52 , V_50 ) ;
return 0 ;
V_79:
F_34 ( & V_2 -> V_52 , V_50 ) ;
return V_78 ;
}
static void
F_51 ( struct V_1 * V_2 , struct V_9 * V_9 , int V_14 )
{
struct V_24 * V_25 ;
if ( ! V_9 )
return;
V_25 = V_9 -> V_31 ;
V_25 -> V_14 = V_14 ;
F_52 ( & V_25 -> V_32 ) ;
F_16 ( V_2 , V_9 ) ;
F_45 ( F_53 ( V_2 ) , V_9 ) ;
F_48 ( & V_2 -> V_52 ) ;
F_49 ( F_53 ( V_2 ) , V_9 , V_25 -> V_14 ) ;
F_50 ( & V_2 -> V_52 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_9 * V_9 ,
int V_80 , int V_81 )
{
struct V_24 * V_25 = V_9 -> V_31 ;
int V_82 ;
if ( V_25 -> V_37 -> V_7 -> V_83 == V_84 ) {
if ( F_55 ( V_9 -> V_10 ) )
V_82 = 80240 + 7578 * V_80 ;
else
V_82 = 80260 + 7467 * V_80 ;
} else {
if ( F_56 ( V_9 -> V_10 ) )
V_82 = F_55 ( V_9 -> V_10 ) ? 9050 : 7840 ;
else
V_82 = 11250 ;
V_82 += 936 * V_80 ;
}
V_82 = ( ( V_82 + 50 ) / 100 ) + 106 ;
if ( F_57 ( V_82 + V_2 -> V_85 >=
V_2 -> V_29 ) )
return - V_86 ;
if ( F_57 ( V_2 -> V_87 + V_88 >=
V_2 -> V_89 + V_90 ) )
return - V_86 ;
if ( F_57 ( V_2 -> V_91 + V_80 >=
V_2 -> V_92 + V_93 ) )
return - V_86 ;
if ( V_81 ) {
if ( F_57 ( V_82 + V_2 -> V_94 >=
F_58 ( V_2 -> V_29 ) ) )
return - V_86 ;
V_2 -> V_94 += V_82 ;
}
V_2 -> V_85 += V_82 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_19 , int V_80 , int V_95 , int V_96 ,
unsigned long V_97 )
{
struct V_3 * V_4 ;
struct V_24 * V_25 = V_9 -> V_31 ;
const T_3 V_98 = 1 , V_15 = 1 ;
T_3 V_99 = 0 ;
int V_100 = 0 ;
if ( F_54 ( V_2 , V_9 , V_80 , F_56 ( V_9 -> V_10 )
|| F_60 ( V_9 -> V_10 ) ) )
return - V_86 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
return - V_64 ;
V_4 -> V_10 = V_9 -> V_10 ;
V_4 -> V_37 = V_25 -> V_37 ;
if ( ( F_61 ( V_4 ) -> V_83 == V_84 ) &&
! ( V_2 -> V_101 & ( 1 << V_25 -> V_60 ) ) )
V_99 |= V_102 ;
switch ( F_18 ( V_4 -> V_10 ) ) {
case V_27 :
V_100 = V_103 ;
V_99 |= V_104 ;
break;
case V_68 :
V_100 = V_105 ;
break;
case V_72 :
V_100 = V_106 ;
break;
case V_71 :
V_100 = V_107 ;
break;
}
if ( V_96 )
V_99 |= V_108 ;
V_99 |= V_109 ;
V_4 -> V_8 = V_2 -> V_87 ;
V_2 -> V_87 = V_2 -> V_87 + V_88 ;
V_4 -> V_110 = F_62 ( V_2 -> V_91 ) ;
V_4 -> V_111 = F_62 ( ( V_2 -> V_20 -> V_112 << 15 ) |
( V_25 -> V_60 << 14 ) | ( V_80 & 0x3FF ) ) ;
V_4 -> V_11 = ( ( V_95 & 0xF ) << V_113 ) |
( F_4 ( V_4 -> V_10 ) & 0xF ) ;
V_4 -> V_12 = F_63 ( V_4 -> V_10 ) & 0x7F ;
V_4 -> V_13 = V_99 ;
V_4 -> V_14 = 0 ;
V_4 -> V_15 = ( V_100 << V_114 ) | ( V_98 << 4 ) | V_15 ;
V_4 -> V_16 = 0 ;
V_4 -> V_87 = F_62 ( V_2 -> V_87 ) ;
V_4 -> V_19 = V_19 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_97 = V_97 ;
V_2 -> V_91 += ( V_80 + 1 ) & ~ 0x01 ;
F_43 ( & V_4 -> V_115 , & V_2 -> V_115 ) ;
return 0 ;
}
static inline void F_64 ( struct V_3 * V_4 )
{
F_52 ( & V_4 -> V_115 ) ;
F_21 ( V_4 ) ;
}
static int F_65 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_116 ;
int V_96 ;
int V_95 ;
int V_59 = 0 ;
int V_117 ;
int V_118 ;
V_96 = F_66 ( V_9 -> V_7 , F_4 ( V_9 -> V_10 ) ,
F_5 ( V_9 -> V_10 ) ) ;
V_116 = V_9 -> V_119 - V_9 -> V_67 ;
V_117 = F_67 ( V_9 -> V_7 , V_9 -> V_10 , F_5 ( V_9 -> V_10 ) ) ;
V_118 = ( V_9 -> V_120 & V_121 ) &&
F_5 ( V_9 -> V_10 ) && ! ( V_116 % V_117 ) ;
while ( V_116 || V_118 ) {
int V_80 ;
char * V_122 ;
V_80 = ( V_116 > V_117 ) ? V_117 : V_116 ;
if ( ! V_80 )
V_118 = 0 ;
V_95 = F_5 ( V_9 -> V_10 ) ? V_123 : V_124 ;
V_122 = V_9 -> V_125 + V_9 -> V_119 -
V_116 ;
V_59 = F_59 ( V_2 , V_9 , V_122 , V_80 , V_95 , V_96 ,
V_126 ) ;
if ( V_59 )
return V_59 ;
V_96 ^= 1 ;
V_116 -= V_80 ;
if ( F_68 ( V_9 -> V_10 ) )
break;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_59 ;
int V_95 ;
switch ( V_9 -> V_69 ) {
default:
case V_70 :
V_59 = F_59 ( V_2 , V_9 , V_9 -> V_127 ,
8 , V_128 , 0 , V_70 ) ;
if ( V_59 )
return V_59 ;
V_9 -> V_69 = V_70 ;
F_70 ( V_9 -> V_7 , F_4 ( V_9 -> V_10 ) ,
F_5 ( V_9 -> V_10 ) , 1 ) ;
break;
case V_126 :
if ( V_9 -> V_119 ) {
V_59 = F_65 ( V_2 , V_9 ) ;
if ( V_59 )
return V_59 ;
break;
}
case V_129 :
V_95 = ! F_5 ( V_9 -> V_10 ) ? V_123 : V_124 ;
V_59 = F_59 ( V_2 , V_9 , NULL , 0 , V_95 , 1 ,
V_129 ) ;
if ( V_59 )
return V_59 ;
break;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_24 * V_25 = V_9 -> V_31 ;
if ( F_15 ( V_2 -> V_38 , V_25 -> V_37 -> V_39 ) ) {
V_25 -> V_37 -> V_39 =
F_13 ( V_25 -> V_37 -> V_39 , V_9 -> V_69 ) ;
return F_65 ( V_2 , V_9 ) ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_24 * V_25 = V_9 -> V_31 ;
if ( F_15 ( V_2 -> V_38 , V_25 -> V_37 -> V_39 ) ) {
char * V_122 ;
int V_80 , V_95 , V_59 ;
F_17 ( V_25 -> V_77 >= V_9 -> V_76 ) ;
V_122 = V_9 -> V_125 +
V_9 -> V_130 [ V_25 -> V_77 ] . V_131 ;
V_80 = V_9 -> V_130 [ V_25 -> V_77 ] . V_132 ;
V_95 = F_5 ( V_9 -> V_10 ) ? V_123 : V_124 ;
V_59 = F_59 ( V_2 , V_9 , V_122 , V_80 , V_95 , 0 ,
V_25 -> V_77 ) ;
if ( V_59 ) {
F_73 ( V_17 L_17 , V_59 ) ;
V_9 -> V_130 [ V_25 -> V_77 ] . V_67 = 0 ;
V_9 -> V_130 [ V_25 -> V_77 ] . V_14 = V_59 ;
if ( V_25 -> V_77 + 1 == V_9 -> V_76 )
F_51 ( V_2 , V_9 , 0 ) ;
}
V_25 -> V_37 -> V_39 =
F_13 ( V_25 -> V_37 -> V_39 , V_9 -> V_69 ) ;
V_25 -> V_77 ++ ;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 , int type ,
int (* F_75)( struct V_1 * , struct V_9 * ) )
{
struct V_33 * V_37 ;
struct V_9 * V_9 ;
F_19 (ep_data, &c67x00->list[type], node) {
if ( ! F_26 ( & V_37 -> V_41 ) ) {
V_9 = F_42 ( V_37 -> V_41 . V_133 ,
struct V_24 ,
V_32 ) -> V_9 ;
F_75 ( V_2 , V_9 ) ;
}
}
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_134 ;
if ( ! F_26 ( & V_2 -> V_115 ) ) {
F_32 ( F_2 ( V_2 ) ,
L_18 ) ;
F_77 (td, ttd, &c67x00->td_list, td_list) {
F_1 ( V_2 , V_4 , L_19 ) ;
F_64 ( V_4 ) ;
}
}
V_2 -> V_85 = 0 ;
V_2 -> V_94 = 0 ;
V_2 -> V_87 = V_2 -> V_89 ;
V_2 -> V_91 = V_2 -> V_92 ;
F_74 ( V_2 , V_27 , F_72 ) ;
F_74 ( V_2 , V_71 , F_71 ) ;
F_74 ( V_2 , V_68 , F_69 ) ;
F_74 ( V_2 , V_72 , F_65 ) ;
}
static inline void
F_78 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_79 ( V_2 -> V_20 -> V_7 ,
V_4 -> V_8 , V_4 , V_88 ) ;
if ( F_55 ( V_4 -> V_10 ) && F_80 ( V_4 ) )
F_79 ( V_2 -> V_20 -> V_7 , F_6 ( V_4 ) ,
V_4 -> V_19 , F_80 ( V_4 ) ) ;
}
static int F_81 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_14 & V_135 ) {
F_1 ( V_2 , V_4 , L_20 ) ;
return - V_136 ;
}
if ( V_4 -> V_14 & V_137 ) {
return - V_138 ;
}
if ( V_4 -> V_14 & V_139 ) {
F_1 ( V_2 , V_4 , L_21 ) ;
return - V_140 ;
}
return 0 ;
}
static inline int F_82 ( struct V_3 * V_4 )
{
int V_117 , V_118 , V_116 ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_141 ;
V_141 = F_80 ( V_4 ) ;
if ( F_57 ( ! V_141 ) )
return 1 ;
V_117 = F_67 ( F_61 ( V_4 ) , V_4 -> V_10 , F_5 ( V_4 -> V_10 ) ) ;
if ( F_57 ( V_141 < V_117 ) )
return 1 ;
V_116 = V_9 -> V_119 - V_9 -> V_67 ;
V_118 = ( V_9 -> V_120 & V_121 ) &&
F_5 ( V_9 -> V_10 ) && ! ( V_116 % V_117 ) ;
if ( F_57 ( ! V_116 && ! V_118 ) )
return 1 ;
return 0 ;
}
static inline void F_83 ( struct V_1 * V_2 ,
struct V_3 * V_142 )
{
struct V_3 * V_4 , * V_143 ;
V_4 = V_142 ;
V_143 = V_142 ;
while ( V_4 -> V_115 . V_133 != & V_2 -> V_115 ) {
V_4 = F_42 ( V_4 -> V_115 . V_133 , struct V_3 , V_115 ) ;
if ( V_4 -> V_10 == V_142 -> V_10 ) {
F_64 ( V_4 ) ;
V_4 = V_143 ;
}
V_143 = V_4 ;
}
}
static void F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_9 = V_4 -> V_9 ;
if ( ! V_9 )
return;
V_9 -> V_67 += F_80 ( V_4 ) ;
switch ( F_18 ( V_4 -> V_10 ) ) {
case V_68 :
switch ( V_4 -> V_97 ) {
case V_70 :
V_9 -> V_69 =
V_9 -> V_119 ?
V_126 : V_129 ;
V_9 -> V_67 = 0 ;
break;
case V_126 :
if ( F_82 ( V_4 ) ) {
V_9 -> V_69 = V_129 ;
F_83 ( V_2 , V_4 ) ;
}
break;
case V_129 :
V_9 -> V_69 = 0 ;
F_51 ( V_2 , V_9 , 0 ) ;
break;
}
break;
case V_71 :
case V_72 :
if ( F_57 ( F_82 ( V_4 ) ) ) {
F_83 ( V_2 , V_4 ) ;
F_51 ( V_2 , V_9 , 0 ) ;
}
break;
}
}
static void F_85 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_9 = V_4 -> V_9 ;
struct V_24 * V_25 ;
int V_77 ;
if ( ! V_9 )
return;
V_25 = V_9 -> V_31 ;
V_77 = V_4 -> V_97 ;
if ( V_4 -> V_14 & V_144 )
V_9 -> V_145 ++ ;
V_9 -> V_130 [ V_77 ] . V_67 = F_80 ( V_4 ) ;
V_9 -> V_130 [ V_77 ] . V_14 = F_81 ( V_2 , V_4 ) ;
if ( V_77 + 1 == V_9 -> V_76 )
F_51 ( V_2 , V_9 , 0 ) ;
}
static inline void F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_143 ;
struct V_9 * V_9 ;
int V_146 ;
int V_147 ;
F_77 (td, tmp, &c67x00->td_list, td_list) {
F_78 ( V_2 , V_4 ) ;
V_9 = V_4 -> V_9 ;
V_146 = 0 ;
V_147 = 1 ;
if ( F_56 ( V_4 -> V_10 ) ) {
V_147 = 0 ;
F_85 ( V_2 , V_4 ) ;
goto V_148;
}
if ( V_4 -> V_14 & V_144 ) {
F_51 ( V_2 , V_9 ,
F_81 ( V_2 , V_4 ) ) ;
goto V_148;
}
if ( ( V_4 -> V_14 & V_149 ) || ! F_87 ( V_4 ) ||
! F_88 ( V_4 ) )
goto V_148;
V_146 = 1 ;
if ( F_57 ( V_4 -> V_14 & V_150 ) ) {
if ( F_89 ( V_4 ) & V_151 ) {
F_51 ( V_2 , V_9 , - V_152 ) ;
goto V_148;
}
}
V_147 = 0 ;
F_84 ( V_2 , V_4 ) ;
V_148:
if ( V_147 )
F_83 ( V_2 , V_4 ) ;
if ( V_146 )
F_70 ( F_61 ( V_4 ) , F_4 ( V_4 -> V_10 ) ,
F_5 ( V_4 -> V_10 ) ,
! ( V_4 -> V_13 & V_108 ) ) ;
V_143 = F_42 ( V_4 -> V_115 . V_133 , F_90 ( * V_4 ) , V_115 ) ;
F_64 ( V_4 ) ;
}
}
static inline int F_91 ( struct V_1 * V_2 )
{
return ! F_92 ( V_2 -> V_20 ) ;
}
static void F_93 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_80 = F_10 ( V_4 ) ;
if ( V_80 && ( ( V_4 -> V_11 & V_153 ) != V_154 ) )
F_94 ( V_2 -> V_20 -> V_7 , F_6 ( V_4 ) ,
V_4 -> V_19 , V_80 ) ;
F_94 ( V_2 -> V_20 -> V_7 ,
V_4 -> V_8 , V_4 , V_88 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( F_26 ( & V_2 -> V_115 ) )
F_32 ( F_2 ( V_2 ) ,
L_22 ,
V_155 ) ;
F_19 (td, &c67x00->td_list, td_list) {
if ( V_4 -> V_115 . V_133 == & V_2 -> V_115 )
V_4 -> V_87 = 0 ;
F_93 ( V_2 , V_4 ) ;
}
F_96 ( V_2 -> V_20 , V_2 -> V_89 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_52 ) ;
if ( ! F_91 ( V_2 ) )
goto V_156;
F_86 ( V_2 ) ;
F_98 ( & V_2 -> V_53 ) ;
if ( ! F_26 ( & V_2 -> V_115 ) )
goto V_156;
V_2 -> V_38 = F_11 ( V_2 ) ;
if ( V_2 -> V_38 == V_2 -> V_157 )
goto V_156;
V_2 -> V_157 = V_2 -> V_38 ;
if ( ! V_2 -> V_26 ) {
F_99 ( V_2 -> V_20 ) ;
goto V_156;
}
F_76 ( V_2 ) ;
if ( ! F_26 ( & V_2 -> V_115 ) )
F_95 ( V_2 ) ;
V_156:
F_48 ( & V_2 -> V_52 ) ;
}
static void F_100 ( unsigned long V_158 )
{
struct V_1 * V_2 = (struct V_1 * ) V_158 ;
F_97 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_101 ( & V_2 -> V_159 ) ;
}
int F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_159 , F_100 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_159 ) ;
}
