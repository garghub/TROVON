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
F_3 ( V_7 , L_14 , F_9 ( V_4 ) , V_4 -> V_17 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_2 )
{
return F_11 ( V_2 -> V_18 ) & V_19 ;
}
static inline T_1 F_12 ( T_1 V_20 , T_1 V_21 )
{
return ( V_20 + V_21 ) & V_19 ;
}
static inline int F_13 ( T_1 V_20 , T_1 V_21 )
{
return ( ( V_19 + V_20 - V_21 ) & V_19 ) <
( V_19 / 2 ) ;
}
static inline int F_14 ( T_1 V_20 , T_1 V_21 )
{
return ( ( V_19 + 1 + V_20 - V_21 ) & V_19 ) <
( V_19 / 2 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_3 * V_4 ;
struct V_22 * V_23 ;
F_16 ( ! V_9 ) ;
V_2 -> V_24 -- ;
if ( F_17 ( V_9 -> V_10 ) == V_25 ) {
V_2 -> V_26 -- ;
if ( V_2 -> V_26 == 0 )
V_2 -> V_27 = V_28 ;
}
F_18 (td, &c67x00->td_list, td_list)
if ( V_9 == V_4 -> V_9 )
V_4 -> V_9 = NULL ;
V_23 = V_9 -> V_29 ;
V_9 -> V_29 = NULL ;
F_19 ( & V_23 -> V_30 ) ;
F_20 ( V_23 ) ;
}
static struct V_31 *
F_21 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_32 * V_33 = V_9 -> V_34 ;
struct V_31 * V_35 ;
int type ;
V_2 -> V_36 = F_10 ( V_2 ) ;
if ( V_33 -> V_29 ) {
V_35 = V_33 -> V_29 ;
if ( F_13 ( V_2 -> V_36 , V_35 -> V_37 ) )
V_35 -> V_37 =
F_12 ( V_2 -> V_36 , 1 ) ;
return V_33 -> V_29 ;
}
V_35 = F_22 ( sizeof( * V_35 ) , V_38 ) ;
if ( ! V_35 )
return NULL ;
F_23 ( & V_35 -> V_39 ) ;
F_23 ( & V_35 -> V_40 ) ;
V_35 -> V_33 = V_33 ;
V_35 -> V_7 = F_24 ( V_9 -> V_7 ) ;
V_33 -> V_29 = V_35 ;
V_35 -> V_37 = F_12 ( V_2 -> V_36 , 1 ) ;
type = F_17 ( V_9 -> V_10 ) ;
if ( F_25 ( & V_35 -> V_40 ) ) {
F_26 ( & V_35 -> V_40 , & V_2 -> V_41 [ type ] ) ;
} else {
struct V_31 * V_42 ;
F_18 (prev, &c67x00->list[type], node) {
if ( V_42 -> V_33 -> V_43 . V_44 >
V_33 -> V_43 . V_44 ) {
F_26 ( & V_35 -> V_40 , V_42 -> V_40 . V_42 ) ;
break;
}
}
}
return V_35 ;
}
static int F_27 ( struct V_32 * V_33 )
{
struct V_31 * V_35 = V_33 -> V_29 ;
if ( ! V_35 )
return 0 ;
if ( ! F_25 ( & V_35 -> V_39 ) )
return - V_45 ;
F_28 ( V_35 -> V_7 ) ;
F_19 ( & V_35 -> V_39 ) ;
F_19 ( & V_35 -> V_40 ) ;
F_20 ( V_35 ) ;
V_33 -> V_29 = NULL ;
return 0 ;
}
void F_29 ( struct V_46 * V_47 , struct V_32 * V_34 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned long V_48 ;
if ( ! F_25 ( & V_34 -> V_49 ) )
F_31 ( F_2 ( V_2 ) , L_15 ) ;
F_32 ( & V_2 -> V_50 , V_48 ) ;
while ( F_27 ( V_34 ) ) {
F_33 ( & V_2 -> V_50 , V_48 ) ;
F_34 ( & V_2 -> V_51 ) ;
F_35 ( V_2 ) ;
F_36 ( & V_2 -> V_51 , 1 * V_52 ) ;
F_32 ( & V_2 -> V_50 , V_48 ) ;
}
F_33 ( & V_2 -> V_50 , V_48 ) ;
}
static inline int F_37 ( struct V_53 * V_7 )
{
while ( V_7 -> V_54 -> V_54 )
V_7 = V_7 -> V_54 ;
return V_7 -> V_55 ;
}
int F_38 ( struct V_46 * V_47 ,
struct V_9 * V_9 , T_2 V_56 )
{
int V_57 ;
unsigned long V_48 ;
struct V_22 * V_23 ;
struct V_1 * V_2 = F_30 ( V_47 ) ;
int V_58 = F_37 ( V_9 -> V_7 ) - 1 ;
V_23 = F_22 ( sizeof( * V_23 ) , V_56 ) ;
if ( ! V_23 ) {
V_57 = - V_59 ;
goto V_60;
}
F_32 ( & V_2 -> V_50 , V_48 ) ;
if ( ! F_39 ( V_47 -> V_61 ) ) {
V_57 = - V_62 ;
goto V_63;
}
V_57 = F_40 ( V_47 , V_9 ) ;
if ( V_57 )
goto V_63;
F_23 ( & V_23 -> V_30 ) ;
V_23 -> V_9 = V_9 ;
V_23 -> V_58 = V_58 ;
V_23 -> V_35 = F_21 ( V_2 , V_9 ) ;
if ( ! V_23 -> V_35 ) {
V_57 = - V_59 ;
goto V_64;
}
V_9 -> V_29 = V_23 ;
V_9 -> V_65 = 0 ;
switch ( F_17 ( V_9 -> V_10 ) ) {
case V_66 :
V_9 -> V_67 = V_68 ;
break;
case V_69 :
break;
case V_70 :
break;
case V_25 :
if ( V_2 -> V_26 == 0 )
V_2 -> V_27 = V_71 ;
V_2 -> V_26 ++ ;
if ( F_25 ( & V_23 -> V_35 -> V_39 ) )
V_9 -> V_72 = V_23 -> V_35 -> V_37 ;
else {
struct V_9 * V_73 ;
V_73 = F_41 ( V_23 -> V_35 -> V_39 . V_42 ,
struct V_22 ,
V_30 ) -> V_9 ;
V_9 -> V_72 =
F_12 ( V_73 -> V_72 ,
V_73 -> V_74 *
V_73 -> V_67 ) ;
}
V_23 -> V_75 = 0 ;
break;
}
F_42 ( & V_23 -> V_30 , & V_23 -> V_35 -> V_39 ) ;
if ( ! V_2 -> V_24 ++ )
F_43 ( V_2 -> V_18 ) ;
F_35 ( V_2 ) ;
F_33 ( & V_2 -> V_50 , V_48 ) ;
return 0 ;
V_64:
F_44 ( V_47 , V_9 ) ;
V_63:
F_33 ( & V_2 -> V_50 , V_48 ) ;
F_20 ( V_23 ) ;
V_60:
return V_57 ;
}
int F_45 ( struct V_46 * V_47 , struct V_9 * V_9 , int V_14 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned long V_48 ;
int V_76 ;
F_32 ( & V_2 -> V_50 , V_48 ) ;
V_76 = F_46 ( V_47 , V_9 , V_14 ) ;
if ( V_76 )
goto V_77;
F_15 ( V_2 , V_9 ) ;
F_44 ( V_47 , V_9 ) ;
F_47 ( & V_2 -> V_50 ) ;
F_48 ( V_47 , V_9 , V_14 ) ;
F_49 ( & V_2 -> V_50 ) ;
F_33 ( & V_2 -> V_50 , V_48 ) ;
return 0 ;
V_77:
F_33 ( & V_2 -> V_50 , V_48 ) ;
return V_76 ;
}
static void
F_50 ( struct V_1 * V_2 , struct V_9 * V_9 , int V_14 )
{
struct V_22 * V_23 ;
if ( ! V_9 )
return;
V_23 = V_9 -> V_29 ;
V_23 -> V_14 = V_14 ;
F_51 ( & V_23 -> V_30 ) ;
F_15 ( V_2 , V_9 ) ;
F_44 ( F_52 ( V_2 ) , V_9 ) ;
F_47 ( & V_2 -> V_50 ) ;
F_48 ( F_52 ( V_2 ) , V_9 , V_23 -> V_14 ) ;
F_49 ( & V_2 -> V_50 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_9 * V_9 ,
int V_78 , int V_79 )
{
struct V_22 * V_23 = V_9 -> V_29 ;
int V_80 ;
if ( V_23 -> V_35 -> V_7 -> V_81 == V_82 ) {
if ( F_54 ( V_9 -> V_10 ) )
V_80 = 80240 + 7578 * V_78 ;
else
V_80 = 80260 + 7467 * V_78 ;
} else {
if ( F_55 ( V_9 -> V_10 ) )
V_80 = F_54 ( V_9 -> V_10 ) ? 9050 : 7840 ;
else
V_80 = 11250 ;
V_80 += 936 * V_78 ;
}
V_80 = ( ( V_80 + 50 ) / 100 ) + 106 ;
if ( F_56 ( V_80 + V_2 -> V_83 >=
V_2 -> V_27 ) )
return - V_84 ;
if ( F_56 ( V_2 -> V_85 + V_86 >=
V_2 -> V_87 + V_88 ) )
return - V_84 ;
if ( F_56 ( V_2 -> V_89 + V_78 >=
V_2 -> V_90 + V_91 ) )
return - V_84 ;
if ( V_79 ) {
if ( F_56 ( V_80 + V_2 -> V_92 >=
F_57 ( V_2 -> V_27 ) ) )
return - V_84 ;
V_2 -> V_92 += V_80 ;
}
V_2 -> V_83 += V_80 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_17 , int V_78 , int V_93 , int V_94 ,
unsigned long V_95 )
{
struct V_3 * V_4 ;
struct V_22 * V_23 = V_9 -> V_29 ;
const T_3 V_96 = 1 , V_15 = 3 ;
T_3 V_97 = 0 ;
int V_98 = 0 ;
if ( F_53 ( V_2 , V_9 , V_78 , F_55 ( V_9 -> V_10 )
|| F_59 ( V_9 -> V_10 ) ) )
return - V_84 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 )
return - V_59 ;
V_4 -> V_10 = V_9 -> V_10 ;
V_4 -> V_35 = V_23 -> V_35 ;
if ( ( F_60 ( V_4 ) -> V_81 == V_82 ) &&
! ( V_2 -> V_99 & ( 1 << V_23 -> V_58 ) ) )
V_97 |= V_100 ;
switch ( F_17 ( V_4 -> V_10 ) ) {
case V_25 :
V_98 = V_101 ;
V_97 |= V_102 ;
break;
case V_66 :
V_98 = V_103 ;
break;
case V_70 :
V_98 = V_104 ;
break;
case V_69 :
V_98 = V_105 ;
break;
}
if ( V_94 )
V_97 |= V_106 ;
V_97 |= V_107 ;
V_4 -> V_8 = V_2 -> V_85 ;
V_2 -> V_85 = V_2 -> V_85 + V_86 ;
V_4 -> V_108 = F_61 ( V_2 -> V_89 ) ;
V_4 -> V_109 = F_61 ( ( V_2 -> V_18 -> V_110 << 15 ) |
( V_23 -> V_58 << 14 ) | ( V_78 & 0x3FF ) ) ;
V_4 -> V_11 = ( ( V_93 & 0xF ) << V_111 ) |
( F_4 ( V_4 -> V_10 ) & 0xF ) ;
V_4 -> V_12 = F_62 ( V_4 -> V_10 ) & 0x7F ;
V_4 -> V_13 = V_97 ;
V_4 -> V_14 = 0 ;
V_4 -> V_15 = ( V_98 << V_112 ) | ( V_96 << 4 ) | V_15 ;
V_4 -> V_16 = 0 ;
V_4 -> V_85 = F_61 ( V_2 -> V_85 ) ;
V_4 -> V_17 = V_17 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_95 = V_95 ;
V_2 -> V_89 += ( V_78 + 1 ) & ~ 0x01 ;
F_42 ( & V_4 -> V_113 , & V_2 -> V_113 ) ;
return 0 ;
}
static inline void F_63 ( struct V_3 * V_4 )
{
F_51 ( & V_4 -> V_113 ) ;
F_20 ( V_4 ) ;
}
static int F_64 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_114 ;
int V_94 ;
int V_93 ;
int V_57 = 0 ;
int V_115 ;
int V_116 ;
V_94 = F_65 ( V_9 -> V_7 , F_4 ( V_9 -> V_10 ) ,
F_5 ( V_9 -> V_10 ) ) ;
V_114 = V_9 -> V_117 - V_9 -> V_65 ;
V_115 = F_66 ( V_9 -> V_7 , V_9 -> V_10 , F_5 ( V_9 -> V_10 ) ) ;
V_116 = ( V_9 -> V_118 & V_119 ) &&
F_5 ( V_9 -> V_10 ) && ! ( V_114 % V_115 ) ;
while ( V_114 || V_116 ) {
int V_78 ;
char * V_120 ;
V_78 = ( V_114 > V_115 ) ? V_115 : V_114 ;
if ( ! V_78 )
V_116 = 0 ;
V_93 = F_5 ( V_9 -> V_10 ) ? V_121 : V_122 ;
V_120 = V_9 -> V_123 + V_9 -> V_117 -
V_114 ;
V_57 = F_58 ( V_2 , V_9 , V_120 , V_78 , V_93 , V_94 ,
V_124 ) ;
if ( V_57 )
return V_57 ;
V_94 ^= 1 ;
V_114 -= V_78 ;
if ( F_67 ( V_9 -> V_10 ) )
break;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_57 ;
int V_93 ;
switch ( V_9 -> V_67 ) {
default:
case V_68 :
V_57 = F_58 ( V_2 , V_9 , V_9 -> V_125 ,
8 , V_126 , 0 , V_68 ) ;
if ( V_57 )
return V_57 ;
V_9 -> V_67 = V_68 ;
F_69 ( V_9 -> V_7 , F_4 ( V_9 -> V_10 ) ,
F_5 ( V_9 -> V_10 ) , 1 ) ;
break;
case V_124 :
if ( V_9 -> V_117 ) {
V_57 = F_64 ( V_2 , V_9 ) ;
if ( V_57 )
return V_57 ;
break;
}
case V_127 :
V_93 = ! F_5 ( V_9 -> V_10 ) ? V_121 : V_122 ;
V_57 = F_58 ( V_2 , V_9 , NULL , 0 , V_93 , 1 ,
V_127 ) ;
if ( V_57 )
return V_57 ;
break;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_22 * V_23 = V_9 -> V_29 ;
if ( F_14 ( V_2 -> V_36 , V_23 -> V_35 -> V_37 ) ) {
V_23 -> V_35 -> V_37 =
F_12 ( V_23 -> V_35 -> V_37 , V_9 -> V_67 ) ;
return F_64 ( V_2 , V_9 ) ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_22 * V_23 = V_9 -> V_29 ;
if ( F_14 ( V_2 -> V_36 , V_23 -> V_35 -> V_37 ) ) {
char * V_120 ;
int V_78 , V_93 , V_57 ;
F_16 ( V_23 -> V_75 >= V_9 -> V_74 ) ;
V_120 = V_9 -> V_123 +
V_9 -> V_128 [ V_23 -> V_75 ] . V_129 ;
V_78 = V_9 -> V_128 [ V_23 -> V_75 ] . V_130 ;
V_93 = F_5 ( V_9 -> V_10 ) ? V_121 : V_122 ;
V_57 = F_58 ( V_2 , V_9 , V_120 , V_78 , V_93 , 0 ,
V_23 -> V_75 ) ;
if ( V_57 ) {
F_3 ( F_2 ( V_2 ) , L_16 ,
V_57 ) ;
V_9 -> V_128 [ V_23 -> V_75 ] . V_65 = 0 ;
V_9 -> V_128 [ V_23 -> V_75 ] . V_14 = V_57 ;
if ( V_23 -> V_75 + 1 == V_9 -> V_74 )
F_50 ( V_2 , V_9 , 0 ) ;
}
V_23 -> V_35 -> V_37 =
F_12 ( V_23 -> V_35 -> V_37 , V_9 -> V_67 ) ;
V_23 -> V_75 ++ ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 , int type ,
int (* F_73)( struct V_1 * , struct V_9 * ) )
{
struct V_31 * V_35 ;
struct V_9 * V_9 ;
F_18 (ep_data, &c67x00->list[type], node) {
if ( ! F_25 ( & V_35 -> V_39 ) ) {
V_9 = F_41 ( V_35 -> V_39 . V_131 ,
struct V_22 ,
V_30 ) -> V_9 ;
F_73 ( V_2 , V_9 ) ;
}
}
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_132 ;
if ( ! F_25 ( & V_2 -> V_113 ) ) {
F_31 ( F_2 ( V_2 ) ,
L_17 ) ;
F_75 (td, ttd, &c67x00->td_list, td_list) {
F_1 ( V_2 , V_4 , L_18 ) ;
F_63 ( V_4 ) ;
}
}
V_2 -> V_83 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_85 = V_2 -> V_87 ;
V_2 -> V_89 = V_2 -> V_90 ;
F_72 ( V_2 , V_25 , F_71 ) ;
F_72 ( V_2 , V_69 , F_70 ) ;
F_72 ( V_2 , V_66 , F_68 ) ;
F_72 ( V_2 , V_70 , F_64 ) ;
}
static inline void
F_76 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_77 ( V_2 -> V_18 -> V_7 ,
V_4 -> V_8 , V_4 , V_86 ) ;
if ( F_54 ( V_4 -> V_10 ) && F_78 ( V_4 ) )
F_77 ( V_2 -> V_18 -> V_7 , F_6 ( V_4 ) ,
V_4 -> V_17 , F_78 ( V_4 ) ) ;
}
static int F_79 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_14 & V_133 ) {
F_1 ( V_2 , V_4 , L_19 ) ;
return - V_134 ;
}
if ( V_4 -> V_14 & V_135 ) {
return - V_136 ;
}
if ( V_4 -> V_14 & V_137 ) {
F_1 ( V_2 , V_4 , L_20 ) ;
return - V_138 ;
}
return 0 ;
}
static inline int F_80 ( struct V_3 * V_4 )
{
int V_115 , V_116 , V_114 ;
struct V_9 * V_9 = V_4 -> V_9 ;
int V_139 ;
V_139 = F_78 ( V_4 ) ;
if ( F_56 ( ! V_139 ) )
return 1 ;
V_115 = F_66 ( F_60 ( V_4 ) , V_4 -> V_10 , F_5 ( V_4 -> V_10 ) ) ;
if ( F_56 ( V_139 < V_115 ) )
return 1 ;
V_114 = V_9 -> V_117 - V_9 -> V_65 ;
V_116 = ( V_9 -> V_118 & V_119 ) &&
F_5 ( V_9 -> V_10 ) && ! ( V_114 % V_115 ) ;
if ( F_56 ( ! V_114 && ! V_116 ) )
return 1 ;
return 0 ;
}
static inline void F_81 ( struct V_1 * V_2 ,
struct V_3 * V_140 )
{
struct V_3 * V_4 , * V_141 ;
V_4 = V_140 ;
V_141 = V_140 ;
while ( V_4 -> V_113 . V_131 != & V_2 -> V_113 ) {
V_4 = F_41 ( V_4 -> V_113 . V_131 , struct V_3 , V_113 ) ;
if ( V_4 -> V_10 == V_140 -> V_10 ) {
F_63 ( V_4 ) ;
V_4 = V_141 ;
}
V_141 = V_4 ;
}
}
static void F_82 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_9 = V_4 -> V_9 ;
if ( ! V_9 )
return;
V_9 -> V_65 += F_78 ( V_4 ) ;
switch ( F_17 ( V_4 -> V_10 ) ) {
case V_66 :
switch ( V_4 -> V_95 ) {
case V_68 :
V_9 -> V_67 =
V_9 -> V_117 ?
V_124 : V_127 ;
V_9 -> V_65 = 0 ;
break;
case V_124 :
if ( F_80 ( V_4 ) ) {
V_9 -> V_67 = V_127 ;
F_81 ( V_2 , V_4 ) ;
}
break;
case V_127 :
V_9 -> V_67 = 0 ;
F_50 ( V_2 , V_9 , 0 ) ;
break;
}
break;
case V_69 :
case V_70 :
if ( F_56 ( F_80 ( V_4 ) ) ) {
F_81 ( V_2 , V_4 ) ;
F_50 ( V_2 , V_9 , 0 ) ;
}
break;
}
}
static void F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_9 = V_4 -> V_9 ;
struct V_22 * V_23 ;
int V_75 ;
if ( ! V_9 )
return;
V_23 = V_9 -> V_29 ;
V_75 = V_4 -> V_95 ;
if ( V_4 -> V_14 & V_142 )
V_9 -> V_143 ++ ;
V_9 -> V_128 [ V_75 ] . V_65 = F_78 ( V_4 ) ;
V_9 -> V_128 [ V_75 ] . V_14 = F_79 ( V_2 , V_4 ) ;
if ( V_75 + 1 == V_9 -> V_74 )
F_50 ( V_2 , V_9 , 0 ) ;
}
static inline void F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_141 ;
struct V_9 * V_9 ;
int V_144 ;
int V_145 ;
F_75 (td, tmp, &c67x00->td_list, td_list) {
F_76 ( V_2 , V_4 ) ;
V_9 = V_4 -> V_9 ;
V_144 = 0 ;
V_145 = 1 ;
if ( F_55 ( V_4 -> V_10 ) ) {
V_145 = 0 ;
F_83 ( V_2 , V_4 ) ;
goto V_146;
}
if ( V_4 -> V_14 & V_142 ) {
F_50 ( V_2 , V_9 ,
F_79 ( V_2 , V_4 ) ) ;
goto V_146;
}
if ( ( V_4 -> V_14 & V_147 ) || ! F_85 ( V_4 ) ||
! F_86 ( V_4 ) )
goto V_146;
V_144 = 1 ;
if ( F_56 ( V_4 -> V_14 & V_148 ) ) {
if ( F_87 ( V_4 ) & V_149 ) {
F_50 ( V_2 , V_9 , - V_150 ) ;
goto V_146;
}
}
V_145 = 0 ;
F_82 ( V_2 , V_4 ) ;
V_146:
if ( V_145 )
F_81 ( V_2 , V_4 ) ;
if ( V_144 )
F_69 ( F_60 ( V_4 ) , F_4 ( V_4 -> V_10 ) ,
F_5 ( V_4 -> V_10 ) ,
! ( V_4 -> V_13 & V_106 ) ) ;
V_141 = F_41 ( V_4 -> V_113 . V_131 , F_88 ( * V_4 ) , V_113 ) ;
F_63 ( V_4 ) ;
}
}
static inline int F_89 ( struct V_1 * V_2 )
{
return ! F_90 ( V_2 -> V_18 ) ;
}
static void F_91 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_78 = F_9 ( V_4 ) ;
if ( V_78 && ( ( V_4 -> V_11 & V_151 ) != V_152 ) )
F_92 ( V_2 -> V_18 -> V_7 , F_6 ( V_4 ) ,
V_4 -> V_17 , V_78 ) ;
F_92 ( V_2 -> V_18 -> V_7 ,
V_4 -> V_8 , V_4 , V_86 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( F_25 ( & V_2 -> V_113 ) )
F_31 ( F_2 ( V_2 ) ,
L_21 ,
V_153 ) ;
F_18 (td, &c67x00->td_list, td_list) {
if ( V_4 -> V_113 . V_131 == & V_2 -> V_113 )
V_4 -> V_85 = 0 ;
F_91 ( V_2 , V_4 ) ;
}
F_94 ( V_2 -> V_18 , V_2 -> V_87 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_49 ( & V_2 -> V_50 ) ;
if ( ! F_89 ( V_2 ) )
goto V_154;
F_84 ( V_2 ) ;
F_96 ( & V_2 -> V_51 ) ;
if ( ! F_25 ( & V_2 -> V_113 ) )
goto V_154;
V_2 -> V_36 = F_10 ( V_2 ) ;
if ( V_2 -> V_36 == V_2 -> V_155 )
goto V_154;
V_2 -> V_155 = V_2 -> V_36 ;
if ( ! V_2 -> V_24 ) {
F_97 ( V_2 -> V_18 ) ;
goto V_154;
}
F_74 ( V_2 ) ;
if ( ! F_25 ( & V_2 -> V_113 ) )
F_93 ( V_2 ) ;
V_154:
F_47 ( & V_2 -> V_50 ) ;
}
static void F_98 ( unsigned long V_156 )
{
struct V_1 * V_2 = (struct V_1 * ) V_156 ;
F_95 ( V_2 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_99 ( & V_2 -> V_157 ) ;
}
int F_100 ( struct V_1 * V_2 )
{
F_101 ( & V_2 -> V_157 , F_98 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_157 ) ;
}
