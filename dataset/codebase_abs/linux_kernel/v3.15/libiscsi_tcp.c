static inline void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_7 = F_2 ( V_4 -> V_8 - V_5 ,
V_2 -> V_9 - V_2 -> V_10 ) ;
V_2 -> V_11 = NULL ;
}
static void F_3 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_11 != NULL || ! V_2 -> V_4 )
return;
V_4 = V_2 -> V_4 ;
F_4 ( V_2 -> V_13 ) ;
F_4 ( V_4 -> V_8 == 0 ) ;
if ( F_5 ( F_6 ( V_4 ) ) >= 1 && ! V_12 )
return;
if ( V_12 ) {
V_2 -> V_14 = true ;
V_2 -> V_13 = F_7 ( F_6 ( V_4 ) ) ;
} else {
V_2 -> V_14 = false ;
V_2 -> V_13 = F_8 ( F_6 ( V_4 ) ) ;
}
V_2 -> V_11 = V_2 -> V_13 + V_4 -> V_5 + V_2 -> V_6 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 ) {
if ( V_2 -> V_14 )
F_10 ( V_2 -> V_13 ) ;
else
F_11 ( F_6 ( V_2 -> V_4 ) ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_11 = NULL ;
}
}
static inline void
F_12 ( struct V_1 * V_2 , void * V_15 )
{
V_2 -> V_11 = V_15 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_9 += V_17 ;
V_2 -> V_7 = V_17 ;
V_2 -> V_18 = 0 ;
V_2 -> V_4 = NULL ;
V_2 -> V_19 = NULL ;
}
int F_13 ( struct V_20 * V_21 ,
struct V_1 * V_2 , int V_12 ,
unsigned V_18 )
{
struct V_3 V_4 ;
unsigned int V_22 ;
F_14 ( V_21 -> V_23 , L_1 ,
V_2 -> V_18 , V_18 , V_2 -> V_7 ,
V_12 ? L_2 : L_3 ) ;
if ( V_2 -> V_19 && V_18 ) {
F_9 ( V_2 ) ;
if ( ! V_2 -> V_11 ) {
F_15 ( & V_4 , 1 ) ;
F_16 ( & V_4 , F_6 ( V_2 -> V_4 ) , V_18 ,
V_2 -> V_18 + V_2 -> V_6 +
V_2 -> V_4 -> V_5 ) ;
} else
F_17 ( & V_4 , V_2 -> V_11 + V_2 -> V_18 ,
V_18 ) ;
F_18 ( V_2 -> V_19 , & V_4 , V_18 ) ;
}
V_2 -> V_18 += V_18 ;
if ( V_2 -> V_18 < V_2 -> V_7 ) {
F_3 ( V_2 , V_12 ) ;
return 0 ;
}
V_2 -> V_10 += V_2 -> V_18 ;
V_2 -> V_18 = 0 ;
V_2 -> V_7 = 0 ;
F_9 ( V_2 ) ;
F_14 ( V_21 -> V_23 , L_4 ,
V_2 -> V_10 , V_2 -> V_9 ) ;
if ( V_2 -> V_10 < V_2 -> V_9 ) {
F_1 ( V_2 , F_19 ( V_2 -> V_4 ) ,
0 ) ;
F_3 ( V_2 , V_12 ) ;
F_4 ( V_2 -> V_7 == 0 ) ;
return 0 ;
}
if ( ! ( V_21 -> V_23 -> V_24 -> V_25 -> V_26 & V_27 ) ) {
V_22 = F_20 ( V_2 -> V_10 ) ;
if ( V_22 != 0 ) {
F_14 ( V_21 -> V_23 ,
L_5 , V_22 ) ;
V_2 -> V_9 += V_22 ;
V_2 -> V_7 = V_22 ;
V_2 -> V_11 = V_2 -> V_28 ;
return 0 ;
}
}
if ( V_2 -> V_19 ) {
F_21 ( V_2 -> V_19 , V_2 -> V_15 ) ;
F_12 ( V_2 ,
V_12 ? V_2 -> V_29 : V_2 -> V_15 ) ;
return 0 ;
}
return 1 ;
}
static int
F_22 ( struct V_20 * V_21 ,
struct V_1 * V_2 , const void * V_30 ,
unsigned int V_31 )
{
unsigned int V_32 = 0 , V_18 = 0 ;
while ( ! F_13 ( V_21 , V_2 , 1 , V_32 ) ) {
if ( V_18 == V_31 ) {
F_14 ( V_21 -> V_23 ,
L_6 , V_31 ) ;
break;
}
V_32 = F_2 ( V_31 - V_18 , V_2 -> V_7 - V_2 -> V_18 ) ;
F_14 ( V_21 -> V_23 , L_7 , V_32 ) ;
memcpy ( V_2 -> V_11 + V_2 -> V_18 , V_30 + V_18 , V_32 ) ;
V_18 += V_32 ;
}
return V_18 ;
}
inline void
F_23 ( struct V_33 * V_19 , const void * V_34 , T_1 V_35 ,
unsigned char V_15 [ V_17 ] )
{
struct V_3 V_4 ;
F_17 ( & V_4 , V_34 , V_35 ) ;
F_24 ( V_19 , & V_4 , V_35 , V_15 ) ;
}
static inline int
F_25 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_16 )
return 1 ;
if ( memcmp ( V_2 -> V_29 , V_2 -> V_15 ,
V_2 -> V_16 ) ) {
F_14 ( V_21 -> V_23 , L_8 ) ;
return 0 ;
}
return 1 ;
}
static inline void
F_26 ( struct V_1 * V_2 , T_1 V_7 ,
T_2 * V_36 , struct V_33 * V_19 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_9 = V_7 ;
V_2 -> V_36 = V_36 ;
if ( V_19 ) {
V_2 -> V_19 = V_19 ;
F_27 ( V_19 ) ;
}
}
inline void
F_28 ( struct V_1 * V_2 , void * V_11 ,
T_1 V_7 , T_2 * V_36 ,
struct V_33 * V_19 )
{
F_26 ( V_2 , V_7 , V_36 , V_19 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_7 = V_7 ;
}
inline int
F_29 ( struct V_1 * V_2 ,
struct V_3 * V_37 , unsigned int V_38 ,
unsigned int V_5 , T_1 V_7 ,
T_2 * V_36 , struct V_33 * V_19 )
{
struct V_3 * V_4 ;
unsigned int V_39 ;
F_26 ( V_2 , V_7 , V_36 , V_19 ) ;
F_30 (sg_list, sg, sg_count, i) {
if ( V_5 < V_4 -> V_8 ) {
F_1 ( V_2 , V_4 , V_5 ) ;
return 0 ;
}
V_5 -= V_4 -> V_8 ;
}
return V_40 ;
}
void F_31 ( struct V_20 * V_21 )
{
F_14 ( V_21 -> V_23 ,
L_9 , V_21 -> V_23 -> V_41 ?
L_10 : L_11 ) ;
F_28 ( & V_21 -> V_42 . V_2 ,
V_21 -> V_42 . V_43 , sizeof( struct V_44 ) ,
V_45 , NULL ) ;
}
static int
F_32 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
struct V_23 * V_46 = V_21 -> V_23 ;
int V_47 = 0 ;
if ( ! F_25 ( V_21 , V_2 ) )
return V_48 ;
V_47 = F_33 ( V_46 , V_21 -> V_42 . V_34 ,
V_46 -> V_11 , V_21 -> V_42 . V_49 ) ;
if ( V_47 )
return V_47 ;
F_31 ( V_21 ) ;
return 0 ;
}
static void
F_34 ( struct V_20 * V_21 )
{
struct V_23 * V_46 = V_21 -> V_23 ;
struct V_33 * V_50 = NULL ;
if ( V_46 -> V_51 &&
! ( V_46 -> V_24 -> V_25 -> V_26 & V_52 ) )
V_50 = V_21 -> V_50 ;
F_28 ( & V_21 -> V_42 . V_2 ,
V_46 -> V_11 , V_21 -> V_42 . V_49 ,
F_32 , V_50 ) ;
}
void F_35 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 ;
if ( ! V_54 -> V_60 )
return;
F_36 ( & V_56 -> V_61 ) ;
while ( F_37 ( & V_56 -> V_62 , ( void * ) & V_59 , sizeof( void * ) ) ) {
F_38 ( & V_56 -> V_63 . V_64 , ( void * ) & V_59 ,
sizeof( void * ) ) ;
F_14 ( V_54 -> V_46 , L_12 ) ;
}
V_59 = V_56 -> V_59 ;
if ( V_59 != NULL ) {
F_38 ( & V_56 -> V_63 . V_64 , ( void * ) & V_59 ,
sizeof( void * ) ) ;
V_56 -> V_59 = NULL ;
}
F_39 ( & V_56 -> V_61 ) ;
}
static int F_40 ( struct V_23 * V_46 , struct V_53 * V_54 )
{
struct V_20 * V_21 = V_46 -> V_57 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_65 * V_66 = (struct V_65 * ) V_21 -> V_42 . V_34 ;
int V_67 = F_41 ( V_66 -> V_67 ) ;
unsigned V_68 = F_42 ( V_54 -> V_60 ) -> V_8 ;
if ( ! ( V_66 -> V_69 & V_70 ) )
F_43 ( V_46 -> V_24 , (struct V_71 * ) V_66 ) ;
if ( V_21 -> V_42 . V_49 == 0 )
return 0 ;
if ( V_56 -> V_72 != V_67 ) {
F_14 ( V_46 , L_13
L_14 , V_56 -> V_72 , V_67 ) ;
return V_73 ;
}
V_56 -> V_72 ++ ;
V_56 -> V_74 = F_41 ( V_66 -> V_5 ) ;
if ( V_56 -> V_74 + V_21 -> V_42 . V_49 > V_68 ) {
F_14 ( V_46 , L_15
L_16 , V_56 -> V_74 ,
V_21 -> V_42 . V_49 , V_68 ) ;
return V_40 ;
}
V_46 -> V_75 ++ ;
return 0 ;
}
static int F_44 ( struct V_23 * V_46 , struct V_53 * V_54 )
{
struct V_76 * V_24 = V_46 -> V_24 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_20 * V_21 = V_46 -> V_57 ;
struct V_77 * V_66 = (struct V_77 * ) V_21 -> V_42 . V_34 ;
struct V_58 * V_59 ;
int V_78 = F_41 ( V_66 -> V_78 ) ;
T_3 V_79 ;
T_3 V_74 ;
int V_47 ;
if ( V_21 -> V_42 . V_49 ) {
F_45 ( V_80 , V_46 ,
L_17 ,
V_21 -> V_42 . V_49 ) ;
return V_81 ;
}
if ( V_56 -> V_72 != V_78 ) {
F_14 ( V_46 , L_18 ,
V_56 -> V_72 , V_78 ) ;
return V_82 ;
}
F_43 ( V_24 , (struct V_71 * ) V_66 ) ;
if ( ! V_54 -> V_60 || V_24 -> V_83 != V_84 ) {
F_45 ( V_85 , V_46 ,
L_19 ,
V_54 -> V_86 ) ;
return 0 ;
}
V_79 = F_41 ( V_66 -> V_79 ) ;
if ( V_79 == 0 ) {
F_45 ( V_80 , V_46 ,
L_20 ) ;
return V_81 ;
}
if ( V_79 > V_24 -> V_87 )
F_14 ( V_46 , L_21
L_22 ,
V_79 , V_24 -> V_87 ) ;
V_74 = F_41 ( V_66 -> V_74 ) ;
if ( V_74 + V_79 > F_46 ( V_54 -> V_60 ) -> V_8 ) {
F_45 ( V_80 , V_46 ,
L_23
L_24 , V_79 ,
V_74 , F_46 ( V_54 -> V_60 ) -> V_8 ) ;
return V_81 ;
}
F_47 ( & V_56 -> V_88 ) ;
V_47 = F_37 ( & V_56 -> V_63 . V_64 , ( void * ) & V_59 , sizeof( void * ) ) ;
if ( ! V_47 ) {
F_45 ( V_80 , V_46 , L_25
L_26
L_27 ) ;
F_48 ( & V_56 -> V_88 ) ;
return V_89 ;
}
V_59 -> V_90 = V_66 -> V_91 ;
V_59 -> V_79 = V_79 ;
V_59 -> V_74 = V_74 ;
V_59 -> V_92 = V_66 -> V_92 ;
V_59 -> V_67 = 0 ;
V_59 -> V_93 = 0 ;
V_56 -> V_72 = V_78 + 1 ;
F_38 ( & V_56 -> V_62 , ( void * ) & V_59 , sizeof( void * ) ) ;
V_46 -> V_94 ++ ;
F_48 ( & V_56 -> V_88 ) ;
F_49 ( V_54 ) ;
return 0 ;
}
static int
F_50 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
struct V_23 * V_46 = V_21 -> V_23 ;
struct V_44 * V_34 = V_21 -> V_42 . V_34 ;
int V_47 ;
if ( ! F_25 ( V_21 , V_2 ) )
return V_48 ;
if ( V_34 -> V_69 & V_70 ) {
V_47 = F_33 ( V_46 , V_21 -> V_42 . V_34 , NULL , 0 ) ;
if ( V_47 )
return V_47 ;
}
F_31 ( V_21 ) ;
return 0 ;
}
static int
F_51 ( struct V_23 * V_46 , struct V_44 * V_34 )
{
int V_47 = 0 , V_95 , V_96 ;
struct V_20 * V_21 = V_46 -> V_57 ;
struct V_53 * V_54 ;
V_21 -> V_42 . V_49 = F_52 ( V_34 -> V_97 ) ;
if ( V_21 -> V_42 . V_49 > V_46 -> V_98 ) {
F_45 ( V_80 , V_46 ,
L_28 ,
V_21 -> V_42 . V_49 , V_46 -> V_98 ) ;
return V_81 ;
}
V_96 = V_34 -> V_99 << 2 ;
V_95 = V_34 -> V_95 & V_100 ;
V_47 = F_53 ( V_46 , V_34 -> V_86 ) ;
if ( V_47 )
return V_47 ;
F_14 ( V_46 , L_29 ,
V_95 , V_96 , V_21 -> V_42 . V_49 ) ;
switch( V_95 ) {
case V_101 :
F_47 ( & V_46 -> V_24 -> V_102 ) ;
V_54 = F_54 ( V_46 , V_34 -> V_86 ) ;
if ( ! V_54 )
V_47 = V_103 ;
else
V_47 = F_40 ( V_46 , V_54 ) ;
if ( V_47 ) {
F_48 ( & V_46 -> V_24 -> V_102 ) ;
break;
}
if ( V_21 -> V_42 . V_49 ) {
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_33 * V_50 = NULL ;
struct V_104 * V_105 = F_42 ( V_54 -> V_60 ) ;
if ( V_46 -> V_51 &&
! ( V_46 -> V_24 -> V_25 -> V_26 & V_52 ) )
V_50 = V_21 -> V_50 ;
F_14 ( V_46 , L_30
L_31 ,
V_56 -> V_74 ,
V_21 -> V_42 . V_49 ) ;
V_54 -> V_106 = V_107 ;
V_47 = F_29 ( & V_21 -> V_42 . V_2 ,
V_105 -> V_108 . V_109 ,
V_105 -> V_108 . V_110 ,
V_56 -> V_74 ,
V_21 -> V_42 . V_49 ,
F_50 ,
V_50 ) ;
F_48 ( & V_46 -> V_24 -> V_102 ) ;
return V_47 ;
}
V_47 = F_55 ( V_46 , V_34 , NULL , 0 ) ;
F_48 ( & V_46 -> V_24 -> V_102 ) ;
break;
case V_111 :
if ( V_21 -> V_42 . V_49 ) {
F_34 ( V_21 ) ;
return 0 ;
}
V_47 = F_33 ( V_46 , V_34 , NULL , 0 ) ;
break;
case V_112 :
F_47 ( & V_46 -> V_24 -> V_102 ) ;
V_54 = F_54 ( V_46 , V_34 -> V_86 ) ;
F_48 ( & V_46 -> V_24 -> V_102 ) ;
if ( ! V_54 )
V_47 = V_103 ;
else if ( V_96 )
V_47 = V_113 ;
else if ( V_54 -> V_60 -> V_114 == V_115 ) {
V_54 -> V_106 = V_107 ;
F_47 ( & V_46 -> V_24 -> V_116 ) ;
V_47 = F_44 ( V_46 , V_54 ) ;
F_48 ( & V_46 -> V_24 -> V_116 ) ;
} else
V_47 = V_89 ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( V_121 < V_21 -> V_42 . V_49 ) {
F_45 ( V_80 , V_46 ,
L_32
L_33
L_34 ,
V_21 -> V_42 . V_49 ,
V_121 , V_95 ) ;
V_47 = V_89 ;
break;
}
if ( V_21 -> V_42 . V_49 ) {
F_34 ( V_21 ) ;
return 0 ;
}
case V_122 :
case V_123 :
case V_124 :
V_47 = F_33 ( V_46 , V_34 , NULL , 0 ) ;
break;
default:
V_47 = V_125 ;
break;
}
if ( V_47 == 0 ) {
if ( V_21 -> V_42 . V_49 )
return V_89 ;
F_31 ( V_21 ) ;
}
return V_47 ;
}
static int
V_45 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
struct V_23 * V_46 = V_21 -> V_23 ;
struct V_44 * V_34 ;
V_34 = (struct V_44 * ) V_21 -> V_42 . V_43 ;
if ( V_2 -> V_18 == sizeof( struct V_44 ) && V_34 -> V_99 ) {
unsigned int V_96 = V_34 -> V_99 << 2 ;
if ( sizeof( * V_34 ) + V_96 > sizeof( V_21 -> V_42 . V_43 ) )
return V_113 ;
V_2 -> V_9 += V_96 ;
V_2 -> V_7 += V_96 ;
return 0 ;
}
if ( V_46 -> V_41 &&
! ( V_46 -> V_24 -> V_25 -> V_26 & V_52 ) ) {
if ( V_2 -> V_16 == 0 ) {
F_12 ( V_2 ,
V_2 -> V_29 ) ;
return 0 ;
}
F_23 ( V_21 -> V_50 , V_34 ,
V_2 -> V_10 - V_17 ,
V_2 -> V_15 ) ;
if ( ! F_25 ( V_21 , V_2 ) )
return V_126 ;
}
V_21 -> V_42 . V_34 = V_34 ;
return F_51 ( V_46 , V_34 ) ;
}
inline int F_56 ( struct V_20 * V_21 )
{
return V_21 -> V_42 . V_2 . V_36 == V_45 ;
}
int F_57 ( struct V_23 * V_46 , struct V_127 * V_128 ,
unsigned int V_5 , bool V_129 , int * V_130 )
{
struct V_20 * V_21 = V_46 -> V_57 ;
struct V_1 * V_2 = & V_21 -> V_42 . V_2 ;
struct V_131 V_132 ;
unsigned int V_133 = 0 ;
int V_47 = 0 ;
F_14 ( V_46 , L_35 , V_128 -> V_31 - V_5 ) ;
V_46 -> V_134 = V_107 ;
if ( F_58 ( V_46 -> V_135 ) ) {
F_14 ( V_46 , L_36 ) ;
* V_130 = V_136 ;
return 0 ;
}
if ( V_129 ) {
V_2 -> V_10 = V_2 -> V_9 ;
goto V_137;
}
F_59 ( V_128 , V_5 , V_128 -> V_31 , & V_132 ) ;
while ( 1 ) {
unsigned int V_138 ;
const T_4 * V_30 ;
V_138 = F_60 ( V_133 , & V_30 , & V_132 ) ;
if ( V_138 == 0 ) {
F_14 ( V_46 , L_37 ,
V_133 ) ;
* V_130 = V_139 ;
goto V_140;
}
F_4 ( V_2 -> V_18 >= V_2 -> V_7 ) ;
F_14 ( V_46 , L_38 , V_128 , V_30 ,
V_138 ) ;
V_47 = F_22 ( V_21 , V_2 , V_30 , V_138 ) ;
F_4 ( V_47 == 0 ) ;
V_133 += V_47 ;
if ( V_2 -> V_10 >= V_2 -> V_9 ) {
F_61 ( & V_132 ) ;
goto V_137;
}
}
V_137:
* V_130 = V_141 ;
F_14 ( V_46 , L_39 ) ;
V_47 = V_2 -> V_36 ( V_21 , V_2 ) ;
if ( V_47 != 0 ) {
* V_130 = V_142 ;
F_14 ( V_46 , L_40 , V_47 ) ;
F_62 ( V_46 , V_47 ) ;
return 0 ;
}
V_140:
V_46 -> V_143 += V_133 ;
return V_133 ;
}
int F_63 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_23 * V_46 = V_54 -> V_46 ;
struct V_144 * V_60 = V_54 -> V_60 ;
int V_145 ;
if ( ! V_60 ) {
F_14 ( V_46 , L_41 , V_54 -> V_86 ) ;
return V_46 -> V_24 -> V_25 -> V_146 ( V_54 , 0 , V_54 -> V_147 ) ;
}
F_4 ( F_64 ( & V_56 -> V_62 ) ) ;
V_56 -> V_72 = 0 ;
F_14 ( V_46 , L_42 ,
V_54 -> V_86 , V_54 -> V_148 , V_54 -> V_149 . V_79 ) ;
V_145 = V_46 -> V_24 -> V_25 -> V_146 ( V_54 , 0 , V_54 -> V_148 ) ;
if ( V_145 )
return V_145 ;
V_54 -> V_148 = 0 ;
return 0 ;
}
static struct V_58 * F_65 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = NULL ;
if ( F_66 ( V_54 ) )
V_59 = & V_54 -> V_149 ;
else {
F_36 ( & V_56 -> V_61 ) ;
if ( V_56 -> V_59 ) {
V_59 = V_56 -> V_59 ;
if ( V_59 -> V_79 <= V_59 -> V_93 ) {
F_14 ( V_54 -> V_46 ,
L_43 , V_59 ) ;
F_38 ( & V_56 -> V_63 . V_64 ,
( void * ) & V_56 -> V_59 ,
sizeof( void * ) ) ;
V_56 -> V_59 = V_59 = NULL ;
}
}
if ( V_59 == NULL ) {
if ( F_37 ( & V_56 -> V_62 ,
( void * ) & V_56 -> V_59 , sizeof( void * ) ) !=
sizeof( void * ) )
V_59 = NULL ;
else
V_59 = V_56 -> V_59 ;
}
F_39 ( & V_56 -> V_61 ) ;
}
return V_59 ;
}
int F_67 ( struct V_53 * V_54 )
{
struct V_23 * V_46 = V_54 -> V_46 ;
struct V_76 * V_24 = V_46 -> V_24 ;
struct V_58 * V_59 ;
int V_47 = 0 ;
V_150:
V_47 = V_24 -> V_25 -> V_151 ( V_54 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( ! V_54 -> V_60 ) {
if ( V_54 -> V_34 -> V_86 == V_152 )
F_68 ( V_54 ) ;
return 0 ;
}
if ( V_54 -> V_60 -> V_114 != V_115 )
return 0 ;
V_59 = F_65 ( V_54 ) ;
if ( V_59 == NULL ) {
F_14 ( V_46 , L_44 ) ;
return 0 ;
}
V_47 = V_46 -> V_24 -> V_25 -> V_153 ( V_54 , V_154 ) ;
if ( V_47 )
return V_47 ;
F_69 ( V_54 , V_59 , (struct V_155 * ) V_54 -> V_34 ) ;
F_14 ( V_46 , L_45 ,
V_59 , V_59 -> V_67 - 1 , V_54 -> V_34 -> V_86 ,
V_59 -> V_74 + V_59 -> V_93 , V_59 -> V_147 ) ;
V_47 = V_46 -> V_24 -> V_25 -> V_146 ( V_54 , V_59 -> V_74 + V_59 -> V_93 ,
V_59 -> V_147 ) ;
if ( V_47 ) {
F_62 ( V_46 , V_156 ) ;
return V_47 ;
}
V_59 -> V_93 += V_59 -> V_147 ;
goto V_150;
}
struct V_157 *
F_70 ( struct V_158 * V_159 , int V_160 ,
T_5 V_161 )
{
struct V_23 * V_46 ;
struct V_157 * V_162 ;
struct V_20 * V_21 ;
V_162 = F_71 ( V_159 ,
sizeof( * V_21 ) + V_160 , V_161 ) ;
if ( ! V_162 )
return NULL ;
V_46 = V_162 -> V_57 ;
V_46 -> V_98 = V_121 ;
V_21 = V_46 -> V_57 ;
V_21 -> V_23 = V_46 ;
V_21 -> V_57 = V_46 -> V_57 + sizeof( * V_21 ) ;
return V_162 ;
}
void F_72 ( struct V_157 * V_162 )
{
F_73 ( V_162 ) ;
}
int F_74 ( struct V_76 * V_24 )
{
int V_39 ;
int V_163 ;
for ( V_163 = 0 ; V_163 < V_24 -> V_164 ; V_163 ++ ) {
struct V_53 * V_54 = V_24 -> V_165 [ V_163 ] ;
struct V_55 * V_56 = V_54 -> V_57 ;
if ( F_75 ( & V_56 -> V_63 ,
V_24 -> V_166 * 2 , NULL ,
sizeof( struct V_58 ) ) ) {
goto V_167;
}
if ( F_76 ( & V_56 -> V_62 ,
V_24 -> V_166 * 4 * sizeof( void * ) , V_168 ) ) {
F_77 ( & V_56 -> V_63 ) ;
goto V_167;
}
F_78 ( & V_56 -> V_88 ) ;
F_78 ( & V_56 -> V_61 ) ;
}
return 0 ;
V_167:
for ( V_39 = 0 ; V_39 < V_163 ; V_39 ++ ) {
struct V_53 * V_54 = V_24 -> V_165 [ V_39 ] ;
struct V_55 * V_56 = V_54 -> V_57 ;
F_79 ( & V_56 -> V_62 ) ;
F_77 ( & V_56 -> V_63 ) ;
}
return - V_169 ;
}
void F_80 ( struct V_76 * V_24 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_24 -> V_164 ; V_39 ++ ) {
struct V_53 * V_54 = V_24 -> V_165 [ V_39 ] ;
struct V_55 * V_56 = V_54 -> V_57 ;
F_79 ( & V_56 -> V_62 ) ;
F_77 ( & V_56 -> V_63 ) ;
}
}
int F_81 ( struct V_23 * V_46 , char * V_170 )
{
struct V_76 * V_24 = V_46 -> V_24 ;
unsigned short V_171 = 0 ;
sscanf ( V_170 , L_46 , & V_171 ) ;
if ( V_24 -> V_166 == V_171 )
return 0 ;
if ( ! V_171 || ! F_82 ( V_171 ) )
return - V_172 ;
V_24 -> V_166 = V_171 ;
F_80 ( V_24 ) ;
return F_74 ( V_24 ) ;
}
void F_83 ( struct V_157 * V_162 ,
struct V_173 * V_174 )
{
struct V_23 * V_46 = V_162 -> V_57 ;
V_174 -> V_175 = V_46 -> V_175 ;
V_174 -> V_143 = V_46 -> V_143 ;
V_174 -> V_176 = V_46 -> V_177 ;
V_174 -> V_178 = V_46 -> V_179 ;
V_174 -> V_180 = V_46 -> V_181 ;
V_174 -> V_182 = V_46 -> V_75 ;
V_174 -> V_183 = V_46 -> V_94 ;
V_174 -> V_184 = V_46 -> V_185 ;
V_174 -> V_186 = V_46 -> V_187 ;
}
