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
while ( F_36 ( & V_56 -> V_61 , ( void * ) & V_59 , sizeof( void * ) ) ) {
F_37 ( & V_56 -> V_62 . V_63 , ( void * ) & V_59 ,
sizeof( void * ) ) ;
F_14 ( V_54 -> V_46 , L_12 ) ;
}
V_59 = V_56 -> V_59 ;
if ( V_59 != NULL ) {
F_37 ( & V_56 -> V_62 . V_63 , ( void * ) & V_59 ,
sizeof( void * ) ) ;
V_56 -> V_59 = NULL ;
}
}
static int F_38 ( struct V_23 * V_46 , struct V_53 * V_54 )
{
struct V_20 * V_21 = V_46 -> V_57 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_64 * V_65 = (struct V_64 * ) V_21 -> V_42 . V_34 ;
int V_66 = F_39 ( V_65 -> V_66 ) ;
unsigned V_67 = F_40 ( V_54 -> V_60 ) -> V_8 ;
if ( ! ( V_65 -> V_68 & V_69 ) )
F_41 ( V_46 -> V_24 , (struct V_70 * ) V_65 ) ;
if ( V_21 -> V_42 . V_49 == 0 )
return 0 ;
if ( V_56 -> V_71 != V_66 ) {
F_14 ( V_46 , L_13
L_14 , V_56 -> V_71 , V_66 ) ;
return V_72 ;
}
V_56 -> V_71 ++ ;
V_56 -> V_73 = F_39 ( V_65 -> V_5 ) ;
if ( V_56 -> V_73 + V_21 -> V_42 . V_49 > V_67 ) {
F_14 ( V_46 , L_15
L_16 , V_56 -> V_73 ,
V_21 -> V_42 . V_49 , V_67 ) ;
return V_40 ;
}
V_46 -> V_74 ++ ;
return 0 ;
}
static int F_42 ( struct V_23 * V_46 , struct V_53 * V_54 )
{
struct V_75 * V_24 = V_46 -> V_24 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_20 * V_21 = V_46 -> V_57 ;
struct V_76 * V_65 = (struct V_76 * ) V_21 -> V_42 . V_34 ;
struct V_58 * V_59 ;
int V_77 = F_39 ( V_65 -> V_77 ) ;
int V_47 ;
if ( V_21 -> V_42 . V_49 ) {
F_43 ( V_78 , V_46 ,
L_17 ,
V_21 -> V_42 . V_49 ) ;
return V_79 ;
}
if ( V_56 -> V_71 != V_77 ) {
F_14 ( V_46 , L_18 ,
V_56 -> V_71 , V_77 ) ;
return V_80 ;
}
F_41 ( V_24 , (struct V_70 * ) V_65 ) ;
if ( ! V_54 -> V_60 || V_24 -> V_81 != V_82 ) {
F_43 ( V_83 , V_46 ,
L_19 ,
V_54 -> V_84 ) ;
return 0 ;
}
V_47 = F_36 ( & V_56 -> V_62 . V_63 , ( void * ) & V_59 , sizeof( void * ) ) ;
if ( ! V_47 ) {
F_43 ( V_78 , V_46 , L_20
L_21
L_22 ) ;
return V_85 ;
}
V_59 -> V_86 = V_65 -> V_87 ;
V_59 -> V_88 = F_39 ( V_65 -> V_88 ) ;
if ( V_59 -> V_88 == 0 ) {
F_43 ( V_78 , V_46 ,
L_23 ) ;
F_37 ( & V_56 -> V_62 . V_63 , ( void * ) & V_59 ,
sizeof( void * ) ) ;
return V_79 ;
}
if ( V_59 -> V_88 > V_24 -> V_89 )
F_14 ( V_46 , L_24
L_25 ,
V_59 -> V_88 , V_24 -> V_89 ) ;
V_59 -> V_73 = F_39 ( V_65 -> V_73 ) ;
if ( V_59 -> V_73 + V_59 -> V_88 > F_44 ( V_54 -> V_60 ) -> V_8 ) {
F_43 ( V_78 , V_46 ,
L_26
L_27 , V_59 -> V_88 ,
V_59 -> V_73 , F_44 ( V_54 -> V_60 ) -> V_8 ) ;
F_37 ( & V_56 -> V_62 . V_63 , ( void * ) & V_59 ,
sizeof( void * ) ) ;
return V_79 ;
}
V_59 -> V_90 = V_65 -> V_90 ;
V_59 -> V_66 = 0 ;
V_59 -> V_91 = 0 ;
V_56 -> V_71 = V_77 + 1 ;
F_37 ( & V_56 -> V_61 , ( void * ) & V_59 , sizeof( void * ) ) ;
V_46 -> V_92 ++ ;
F_45 ( V_54 ) ;
return 0 ;
}
static int
F_46 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
struct V_23 * V_46 = V_21 -> V_23 ;
struct V_44 * V_34 = V_21 -> V_42 . V_34 ;
int V_47 ;
if ( ! F_25 ( V_21 , V_2 ) )
return V_48 ;
if ( V_34 -> V_68 & V_69 ) {
V_47 = F_33 ( V_46 , V_21 -> V_42 . V_34 , NULL , 0 ) ;
if ( V_47 )
return V_47 ;
}
F_31 ( V_21 ) ;
return 0 ;
}
static int
F_47 ( struct V_23 * V_46 , struct V_44 * V_34 )
{
int V_47 = 0 , V_93 , V_94 ;
struct V_20 * V_21 = V_46 -> V_57 ;
struct V_53 * V_54 ;
V_21 -> V_42 . V_49 = F_48 ( V_34 -> V_95 ) ;
if ( V_21 -> V_42 . V_49 > V_46 -> V_96 ) {
F_43 ( V_78 , V_46 ,
L_28 ,
V_21 -> V_42 . V_49 , V_46 -> V_96 ) ;
return V_79 ;
}
V_94 = V_34 -> V_97 << 2 ;
V_93 = V_34 -> V_93 & V_98 ;
V_47 = F_49 ( V_46 , V_34 -> V_84 ) ;
if ( V_47 )
return V_47 ;
F_14 ( V_46 , L_29 ,
V_93 , V_94 , V_21 -> V_42 . V_49 ) ;
switch( V_93 ) {
case V_99 :
F_50 ( & V_46 -> V_24 -> V_100 ) ;
V_54 = F_51 ( V_46 , V_34 -> V_84 ) ;
if ( ! V_54 )
V_47 = V_101 ;
else
V_47 = F_38 ( V_46 , V_54 ) ;
if ( V_47 ) {
F_52 ( & V_46 -> V_24 -> V_100 ) ;
break;
}
if ( V_21 -> V_42 . V_49 ) {
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_33 * V_50 = NULL ;
struct V_102 * V_103 = F_40 ( V_54 -> V_60 ) ;
if ( V_46 -> V_51 &&
! ( V_46 -> V_24 -> V_25 -> V_26 & V_52 ) )
V_50 = V_21 -> V_50 ;
F_14 ( V_46 , L_30
L_31 ,
V_56 -> V_73 ,
V_21 -> V_42 . V_49 ) ;
V_54 -> V_104 = V_105 ;
V_47 = F_29 ( & V_21 -> V_42 . V_2 ,
V_103 -> V_106 . V_107 ,
V_103 -> V_106 . V_108 ,
V_56 -> V_73 ,
V_21 -> V_42 . V_49 ,
F_46 ,
V_50 ) ;
F_52 ( & V_46 -> V_24 -> V_100 ) ;
return V_47 ;
}
V_47 = F_53 ( V_46 , V_34 , NULL , 0 ) ;
F_52 ( & V_46 -> V_24 -> V_100 ) ;
break;
case V_109 :
if ( V_21 -> V_42 . V_49 ) {
F_34 ( V_21 ) ;
return 0 ;
}
V_47 = F_33 ( V_46 , V_34 , NULL , 0 ) ;
break;
case V_110 :
F_50 ( & V_46 -> V_24 -> V_100 ) ;
V_54 = F_51 ( V_46 , V_34 -> V_84 ) ;
if ( ! V_54 )
V_47 = V_101 ;
else if ( V_94 )
V_47 = V_111 ;
else if ( V_54 -> V_60 -> V_112 == V_113 ) {
V_54 -> V_104 = V_105 ;
V_47 = F_42 ( V_46 , V_54 ) ;
} else
V_47 = V_85 ;
F_52 ( & V_46 -> V_24 -> V_100 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
if ( V_118 < V_21 -> V_42 . V_49 ) {
F_43 ( V_78 , V_46 ,
L_32
L_33
L_34 ,
V_21 -> V_42 . V_49 ,
V_118 , V_93 ) ;
V_47 = V_85 ;
break;
}
if ( V_21 -> V_42 . V_49 ) {
F_34 ( V_21 ) ;
return 0 ;
}
case V_119 :
case V_120 :
case V_121 :
V_47 = F_33 ( V_46 , V_34 , NULL , 0 ) ;
break;
default:
V_47 = V_122 ;
break;
}
if ( V_47 == 0 ) {
if ( V_21 -> V_42 . V_49 )
return V_85 ;
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
if ( V_2 -> V_18 == sizeof( struct V_44 ) && V_34 -> V_97 ) {
unsigned int V_94 = V_34 -> V_97 << 2 ;
if ( sizeof( * V_34 ) + V_94 > sizeof( V_21 -> V_42 . V_43 ) )
return V_111 ;
V_2 -> V_9 += V_94 ;
V_2 -> V_7 += V_94 ;
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
return V_123 ;
}
V_21 -> V_42 . V_34 = V_34 ;
return F_47 ( V_46 , V_34 ) ;
}
inline int F_54 ( struct V_20 * V_21 )
{
return V_21 -> V_42 . V_2 . V_36 == V_45 ;
}
int F_55 ( struct V_23 * V_46 , struct V_124 * V_125 ,
unsigned int V_5 , bool V_126 , int * V_127 )
{
struct V_20 * V_21 = V_46 -> V_57 ;
struct V_1 * V_2 = & V_21 -> V_42 . V_2 ;
struct V_128 V_129 ;
unsigned int V_130 = 0 ;
int V_47 = 0 ;
F_14 ( V_46 , L_35 , V_125 -> V_31 - V_5 ) ;
V_46 -> V_131 = V_105 ;
if ( F_56 ( V_46 -> V_132 ) ) {
F_14 ( V_46 , L_36 ) ;
* V_127 = V_133 ;
return 0 ;
}
if ( V_126 ) {
V_2 -> V_10 = V_2 -> V_9 ;
goto V_134;
}
F_57 ( V_125 , V_5 , V_125 -> V_31 , & V_129 ) ;
while ( 1 ) {
unsigned int V_135 ;
const T_3 * V_30 ;
V_135 = F_58 ( V_130 , & V_30 , & V_129 ) ;
if ( V_135 == 0 ) {
F_14 ( V_46 , L_37 ,
V_130 ) ;
* V_127 = V_136 ;
F_59 ( & V_129 ) ;
goto V_137;
}
F_4 ( V_2 -> V_18 >= V_2 -> V_7 ) ;
F_14 ( V_46 , L_38 , V_125 , V_30 ,
V_135 ) ;
V_47 = F_22 ( V_21 , V_2 , V_30 , V_135 ) ;
F_4 ( V_47 == 0 ) ;
V_130 += V_47 ;
if ( V_2 -> V_10 >= V_2 -> V_9 ) {
F_59 ( & V_129 ) ;
goto V_134;
}
}
V_134:
* V_127 = V_138 ;
F_14 ( V_46 , L_39 ) ;
V_47 = V_2 -> V_36 ( V_21 , V_2 ) ;
if ( V_47 != 0 ) {
* V_127 = V_139 ;
F_14 ( V_46 , L_40 , V_47 ) ;
F_60 ( V_46 , V_47 ) ;
return 0 ;
}
V_137:
V_46 -> V_140 += V_130 ;
return V_130 ;
}
int F_61 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_23 * V_46 = V_54 -> V_46 ;
struct V_141 * V_60 = V_54 -> V_60 ;
int V_142 ;
if ( ! V_60 ) {
F_14 ( V_46 , L_41 , V_54 -> V_84 ) ;
return V_46 -> V_24 -> V_25 -> V_143 ( V_54 , 0 , V_54 -> V_144 ) ;
}
F_4 ( F_62 ( & V_56 -> V_61 ) ) ;
V_56 -> V_71 = 0 ;
F_14 ( V_46 , L_42 ,
V_54 -> V_84 , V_54 -> V_145 , V_54 -> V_146 . V_88 ) ;
V_142 = V_46 -> V_24 -> V_25 -> V_143 ( V_54 , 0 , V_54 -> V_145 ) ;
if ( V_142 )
return V_142 ;
V_54 -> V_145 = 0 ;
return 0 ;
}
static struct V_58 * F_63 ( struct V_53 * V_54 )
{
struct V_75 * V_24 = V_54 -> V_46 -> V_24 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = NULL ;
if ( F_64 ( V_54 ) )
V_59 = & V_54 -> V_146 ;
else {
F_65 ( & V_24 -> V_100 ) ;
if ( V_56 -> V_59 ) {
V_59 = V_56 -> V_59 ;
if ( V_59 -> V_88 <= V_59 -> V_91 ) {
F_14 ( V_54 -> V_46 ,
L_43 , V_59 ) ;
F_37 ( & V_56 -> V_62 . V_63 ,
( void * ) & V_56 -> V_59 ,
sizeof( void * ) ) ;
V_56 -> V_59 = V_59 = NULL ;
}
}
if ( V_59 == NULL ) {
if ( F_36 ( & V_56 -> V_61 ,
( void * ) & V_56 -> V_59 , sizeof( void * ) ) !=
sizeof( void * ) )
V_59 = NULL ;
else
V_59 = V_56 -> V_59 ;
}
F_66 ( & V_24 -> V_100 ) ;
}
return V_59 ;
}
int F_67 ( struct V_53 * V_54 )
{
struct V_23 * V_46 = V_54 -> V_46 ;
struct V_75 * V_24 = V_46 -> V_24 ;
struct V_58 * V_59 ;
int V_47 = 0 ;
V_147:
V_47 = V_24 -> V_25 -> V_148 ( V_54 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( ! V_54 -> V_60 ) {
if ( V_54 -> V_34 -> V_84 == V_149 )
F_68 ( V_54 ) ;
return 0 ;
}
if ( V_54 -> V_60 -> V_112 != V_113 )
return 0 ;
V_59 = F_63 ( V_54 ) ;
if ( V_59 == NULL ) {
F_14 ( V_46 , L_44 ) ;
return 0 ;
}
V_47 = V_46 -> V_24 -> V_25 -> V_150 ( V_54 , V_151 ) ;
if ( V_47 )
return V_47 ;
F_69 ( V_54 , V_59 , (struct V_152 * ) V_54 -> V_34 ) ;
F_14 ( V_46 , L_45 ,
V_59 , V_59 -> V_66 - 1 , V_54 -> V_34 -> V_84 ,
V_59 -> V_73 + V_59 -> V_91 , V_59 -> V_144 ) ;
V_47 = V_46 -> V_24 -> V_25 -> V_143 ( V_54 , V_59 -> V_73 + V_59 -> V_91 ,
V_59 -> V_144 ) ;
if ( V_47 ) {
F_60 ( V_46 , V_153 ) ;
return V_47 ;
}
V_59 -> V_91 += V_59 -> V_144 ;
goto V_147;
}
struct V_154 *
F_70 ( struct V_155 * V_156 , int V_157 ,
T_4 V_158 )
{
struct V_23 * V_46 ;
struct V_154 * V_159 ;
struct V_20 * V_21 ;
V_159 = F_71 ( V_156 ,
sizeof( * V_21 ) + V_157 , V_158 ) ;
if ( ! V_159 )
return NULL ;
V_46 = V_159 -> V_57 ;
V_46 -> V_96 = V_118 ;
V_21 = V_46 -> V_57 ;
V_21 -> V_23 = V_46 ;
V_21 -> V_57 = V_46 -> V_57 + sizeof( * V_21 ) ;
return V_159 ;
}
void F_72 ( struct V_154 * V_159 )
{
F_73 ( V_159 ) ;
}
int F_74 ( struct V_75 * V_24 )
{
int V_39 ;
int V_160 ;
for ( V_160 = 0 ; V_160 < V_24 -> V_161 ; V_160 ++ ) {
struct V_53 * V_54 = V_24 -> V_162 [ V_160 ] ;
struct V_55 * V_56 = V_54 -> V_57 ;
if ( F_75 ( & V_56 -> V_62 ,
V_24 -> V_163 * 2 , NULL ,
sizeof( struct V_58 ) ) ) {
goto V_164;
}
if ( F_76 ( & V_56 -> V_61 ,
V_24 -> V_163 * 4 * sizeof( void * ) , V_165 ) ) {
F_77 ( & V_56 -> V_62 ) ;
goto V_164;
}
}
return 0 ;
V_164:
for ( V_39 = 0 ; V_39 < V_160 ; V_39 ++ ) {
struct V_53 * V_54 = V_24 -> V_162 [ V_39 ] ;
struct V_55 * V_56 = V_54 -> V_57 ;
F_78 ( & V_56 -> V_61 ) ;
F_77 ( & V_56 -> V_62 ) ;
}
return - V_166 ;
}
void F_79 ( struct V_75 * V_24 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_24 -> V_161 ; V_39 ++ ) {
struct V_53 * V_54 = V_24 -> V_162 [ V_39 ] ;
struct V_55 * V_56 = V_54 -> V_57 ;
F_78 ( & V_56 -> V_61 ) ;
F_77 ( & V_56 -> V_62 ) ;
}
}
int F_80 ( struct V_23 * V_46 , char * V_167 )
{
struct V_75 * V_24 = V_46 -> V_24 ;
unsigned short V_168 = 0 ;
sscanf ( V_167 , L_46 , & V_168 ) ;
if ( V_24 -> V_163 == V_168 )
return 0 ;
if ( ! V_168 || ! F_81 ( V_168 ) )
return - V_169 ;
V_24 -> V_163 = V_168 ;
F_79 ( V_24 ) ;
return F_74 ( V_24 ) ;
}
void F_82 ( struct V_154 * V_159 ,
struct V_170 * V_171 )
{
struct V_23 * V_46 = V_159 -> V_57 ;
V_171 -> V_172 = V_46 -> V_172 ;
V_171 -> V_140 = V_46 -> V_140 ;
V_171 -> V_173 = V_46 -> V_174 ;
V_171 -> V_175 = V_46 -> V_176 ;
V_171 -> V_177 = V_46 -> V_178 ;
V_171 -> V_179 = V_46 -> V_74 ;
V_171 -> V_180 = V_46 -> V_92 ;
V_171 -> V_181 = V_46 -> V_182 ;
V_171 -> V_183 = V_46 -> V_184 ;
}
