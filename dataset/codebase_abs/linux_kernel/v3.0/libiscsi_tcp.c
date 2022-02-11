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
V_2 -> V_13 = F_7 ( F_6 ( V_4 ) , V_15 ) ;
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
F_10 ( V_2 -> V_13 , V_15 ) ;
else
F_11 ( F_6 ( V_2 -> V_4 ) ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_11 = NULL ;
}
}
static inline void
F_12 ( struct V_1 * V_2 , void * V_16 )
{
V_2 -> V_11 = V_16 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_9 += V_18 ;
V_2 -> V_7 = V_18 ;
V_2 -> V_19 = 0 ;
V_2 -> V_4 = NULL ;
V_2 -> V_20 = NULL ;
}
int F_13 ( struct V_21 * V_22 ,
struct V_1 * V_2 , int V_12 ,
unsigned V_19 )
{
struct V_3 V_4 ;
unsigned int V_23 ;
F_14 ( V_22 -> V_24 , L_1 ,
V_2 -> V_19 , V_19 , V_2 -> V_7 ,
V_12 ? L_2 : L_3 ) ;
if ( V_2 -> V_20 && V_19 ) {
F_9 ( V_2 ) ;
if ( ! V_2 -> V_11 ) {
F_15 ( & V_4 , 1 ) ;
F_16 ( & V_4 , F_6 ( V_2 -> V_4 ) , V_19 ,
V_2 -> V_19 + V_2 -> V_6 +
V_2 -> V_4 -> V_5 ) ;
} else
F_17 ( & V_4 , V_2 -> V_11 + V_2 -> V_19 ,
V_19 ) ;
F_18 ( V_2 -> V_20 , & V_4 , V_19 ) ;
}
V_2 -> V_19 += V_19 ;
if ( V_2 -> V_19 < V_2 -> V_7 ) {
F_3 ( V_2 , V_12 ) ;
return 0 ;
}
V_2 -> V_10 += V_2 -> V_19 ;
V_2 -> V_19 = 0 ;
V_2 -> V_7 = 0 ;
F_9 ( V_2 ) ;
F_14 ( V_22 -> V_24 , L_4 ,
V_2 -> V_10 , V_2 -> V_9 ) ;
if ( V_2 -> V_10 < V_2 -> V_9 ) {
F_1 ( V_2 , F_19 ( V_2 -> V_4 ) ,
0 ) ;
F_3 ( V_2 , V_12 ) ;
F_4 ( V_2 -> V_7 == 0 ) ;
return 0 ;
}
if ( ! ( V_22 -> V_24 -> V_25 -> V_26 -> V_27 & V_28 ) ) {
V_23 = F_20 ( V_2 -> V_10 ) ;
if ( V_23 != 0 ) {
F_14 ( V_22 -> V_24 ,
L_5 , V_23 ) ;
V_2 -> V_9 += V_23 ;
V_2 -> V_7 = V_23 ;
V_2 -> V_11 = V_2 -> V_29 ;
return 0 ;
}
}
if ( V_2 -> V_20 ) {
F_21 ( V_2 -> V_20 , V_2 -> V_16 ) ;
F_12 ( V_2 ,
V_12 ? V_2 -> V_30 : V_2 -> V_16 ) ;
return 0 ;
}
return 1 ;
}
static int
F_22 ( struct V_21 * V_22 ,
struct V_1 * V_2 , const void * V_31 ,
unsigned int V_32 )
{
unsigned int V_33 = 0 , V_19 = 0 ;
while ( ! F_13 ( V_22 , V_2 , 1 , V_33 ) ) {
if ( V_19 == V_32 ) {
F_14 ( V_22 -> V_24 ,
L_6 , V_32 ) ;
break;
}
V_33 = F_2 ( V_32 - V_19 , V_2 -> V_7 - V_2 -> V_19 ) ;
F_14 ( V_22 -> V_24 , L_7 , V_33 ) ;
memcpy ( V_2 -> V_11 + V_2 -> V_19 , V_31 + V_19 , V_33 ) ;
V_19 += V_33 ;
}
return V_19 ;
}
inline void
F_23 ( struct V_34 * V_20 , const void * V_35 , T_1 V_36 ,
unsigned char V_16 [ V_18 ] )
{
struct V_3 V_4 ;
F_17 ( & V_4 , V_35 , V_36 ) ;
F_24 ( V_20 , & V_4 , V_36 , V_16 ) ;
}
static inline int
F_25 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_17 )
return 1 ;
if ( memcmp ( V_2 -> V_30 , V_2 -> V_16 ,
V_2 -> V_17 ) ) {
F_14 ( V_22 -> V_24 , L_8 ) ;
return 0 ;
}
return 1 ;
}
static inline void
F_26 ( struct V_1 * V_2 , T_1 V_7 ,
T_2 * V_37 , struct V_34 * V_20 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_9 = V_7 ;
V_2 -> V_37 = V_37 ;
if ( V_20 ) {
V_2 -> V_20 = V_20 ;
F_27 ( V_20 ) ;
}
}
inline void
F_28 ( struct V_1 * V_2 , void * V_11 ,
T_1 V_7 , T_2 * V_37 ,
struct V_34 * V_20 )
{
F_26 ( V_2 , V_7 , V_37 , V_20 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_7 = V_7 ;
}
inline int
F_29 ( struct V_1 * V_2 ,
struct V_3 * V_38 , unsigned int V_39 ,
unsigned int V_5 , T_1 V_7 ,
T_2 * V_37 , struct V_34 * V_20 )
{
struct V_3 * V_4 ;
unsigned int V_40 ;
F_26 ( V_2 , V_7 , V_37 , V_20 ) ;
F_30 (sg_list, sg, sg_count, i) {
if ( V_5 < V_4 -> V_8 ) {
F_1 ( V_2 , V_4 , V_5 ) ;
return 0 ;
}
V_5 -= V_4 -> V_8 ;
}
return V_41 ;
}
void F_31 ( struct V_21 * V_22 )
{
F_14 ( V_22 -> V_24 ,
L_9 , V_22 -> V_24 -> V_42 ?
L_10 : L_11 ) ;
F_28 ( & V_22 -> V_43 . V_2 ,
V_22 -> V_43 . V_44 , sizeof( struct V_45 ) ,
V_46 , NULL ) ;
}
static int
F_32 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_24 * V_47 = V_22 -> V_24 ;
int V_48 = 0 ;
if ( ! F_25 ( V_22 , V_2 ) )
return V_49 ;
V_48 = F_33 ( V_47 , V_22 -> V_43 . V_35 ,
V_47 -> V_11 , V_22 -> V_43 . V_50 ) ;
if ( V_48 )
return V_48 ;
F_31 ( V_22 ) ;
return 0 ;
}
static void
F_34 ( struct V_21 * V_22 )
{
struct V_24 * V_47 = V_22 -> V_24 ;
struct V_34 * V_51 = NULL ;
if ( V_47 -> V_52 &&
! ( V_47 -> V_25 -> V_26 -> V_27 & V_53 ) )
V_51 = V_22 -> V_51 ;
F_28 ( & V_22 -> V_43 . V_2 ,
V_47 -> V_11 , V_22 -> V_43 . V_50 ,
F_32 , V_51 ) ;
}
void F_35 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = V_55 -> V_58 ;
struct V_59 * V_60 ;
if ( ! V_55 -> V_61 )
return;
while ( F_36 ( & V_57 -> V_62 , ( void * ) & V_60 , sizeof( void * ) ) ) {
F_37 ( & V_57 -> V_63 . V_64 , ( void * ) & V_60 ,
sizeof( void * ) ) ;
F_14 ( V_55 -> V_47 , L_12 ) ;
}
V_60 = V_57 -> V_60 ;
if ( V_60 != NULL ) {
F_37 ( & V_57 -> V_63 . V_64 , ( void * ) & V_60 ,
sizeof( void * ) ) ;
V_57 -> V_60 = NULL ;
}
}
static int F_38 ( struct V_24 * V_47 , struct V_54 * V_55 )
{
struct V_21 * V_22 = V_47 -> V_58 ;
struct V_56 * V_57 = V_55 -> V_58 ;
struct V_65 * V_66 = (struct V_65 * ) V_22 -> V_43 . V_35 ;
int V_67 = F_39 ( V_66 -> V_67 ) ;
unsigned V_68 = F_40 ( V_55 -> V_61 ) -> V_8 ;
if ( ! ( V_66 -> V_69 & V_70 ) )
F_41 ( V_47 -> V_25 , (struct V_71 * ) V_66 ) ;
if ( V_22 -> V_43 . V_50 == 0 )
return 0 ;
if ( V_57 -> V_72 != V_67 ) {
F_14 ( V_47 , L_13
L_14 , V_57 -> V_72 , V_67 ) ;
return V_73 ;
}
V_57 -> V_72 ++ ;
V_57 -> V_74 = F_39 ( V_66 -> V_5 ) ;
if ( V_57 -> V_74 + V_22 -> V_43 . V_50 > V_68 ) {
F_14 ( V_47 , L_15
L_16 , V_57 -> V_74 ,
V_22 -> V_43 . V_50 , V_68 ) ;
return V_41 ;
}
V_47 -> V_75 ++ ;
return 0 ;
}
static int F_42 ( struct V_24 * V_47 , struct V_54 * V_55 )
{
struct V_76 * V_25 = V_47 -> V_25 ;
struct V_56 * V_57 = V_55 -> V_58 ;
struct V_21 * V_22 = V_47 -> V_58 ;
struct V_77 * V_66 = (struct V_77 * ) V_22 -> V_43 . V_35 ;
struct V_59 * V_60 ;
int V_78 = F_39 ( V_66 -> V_78 ) ;
int V_48 ;
if ( V_22 -> V_43 . V_50 ) {
F_43 ( V_79 , V_47 ,
L_17 ,
V_22 -> V_43 . V_50 ) ;
return V_80 ;
}
if ( V_57 -> V_72 != V_78 ) {
F_14 ( V_47 , L_18 ,
V_57 -> V_72 , V_78 ) ;
return V_81 ;
}
F_41 ( V_25 , (struct V_71 * ) V_66 ) ;
if ( ! V_55 -> V_61 || V_25 -> V_82 != V_83 ) {
F_43 ( V_84 , V_47 ,
L_19 ,
V_55 -> V_85 ) ;
return 0 ;
}
V_48 = F_36 ( & V_57 -> V_63 . V_64 , ( void * ) & V_60 , sizeof( void * ) ) ;
if ( ! V_48 ) {
F_43 ( V_79 , V_47 , L_20
L_21
L_22 ) ;
return V_86 ;
}
V_60 -> V_87 = V_66 -> V_88 ;
V_60 -> V_89 = F_39 ( V_66 -> V_89 ) ;
if ( V_60 -> V_89 == 0 ) {
F_43 ( V_79 , V_47 ,
L_23 ) ;
F_37 ( & V_57 -> V_63 . V_64 , ( void * ) & V_60 ,
sizeof( void * ) ) ;
return V_80 ;
}
if ( V_60 -> V_89 > V_25 -> V_90 )
F_14 ( V_47 , L_24
L_25 ,
V_60 -> V_89 , V_25 -> V_90 ) ;
V_60 -> V_74 = F_39 ( V_66 -> V_74 ) ;
if ( V_60 -> V_74 + V_60 -> V_89 > F_44 ( V_55 -> V_61 ) -> V_8 ) {
F_43 ( V_79 , V_47 ,
L_26
L_27 , V_60 -> V_89 ,
V_60 -> V_74 , F_44 ( V_55 -> V_61 ) -> V_8 ) ;
F_37 ( & V_57 -> V_63 . V_64 , ( void * ) & V_60 ,
sizeof( void * ) ) ;
return V_80 ;
}
V_60 -> V_91 = V_66 -> V_91 ;
V_60 -> V_67 = 0 ;
V_60 -> V_92 = 0 ;
V_57 -> V_72 = V_78 + 1 ;
F_37 ( & V_57 -> V_62 , ( void * ) & V_60 , sizeof( void * ) ) ;
V_47 -> V_93 ++ ;
F_45 ( V_55 ) ;
return 0 ;
}
static int
F_46 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_24 * V_47 = V_22 -> V_24 ;
struct V_45 * V_35 = V_22 -> V_43 . V_35 ;
int V_48 ;
if ( ! F_25 ( V_22 , V_2 ) )
return V_49 ;
if ( V_35 -> V_69 & V_70 ) {
V_48 = F_33 ( V_47 , V_22 -> V_43 . V_35 , NULL , 0 ) ;
if ( V_48 )
return V_48 ;
}
F_31 ( V_22 ) ;
return 0 ;
}
static int
F_47 ( struct V_24 * V_47 , struct V_45 * V_35 )
{
int V_48 = 0 , V_94 , V_95 ;
struct V_21 * V_22 = V_47 -> V_58 ;
struct V_54 * V_55 ;
V_22 -> V_43 . V_50 = F_48 ( V_35 -> V_96 ) ;
if ( V_22 -> V_43 . V_50 > V_47 -> V_97 ) {
F_43 ( V_79 , V_47 ,
L_28 ,
V_22 -> V_43 . V_50 , V_47 -> V_97 ) ;
return V_80 ;
}
V_95 = V_35 -> V_98 << 2 ;
V_94 = V_35 -> V_94 & V_99 ;
V_48 = F_49 ( V_47 , V_35 -> V_85 ) ;
if ( V_48 )
return V_48 ;
F_14 ( V_47 , L_29 ,
V_94 , V_95 , V_22 -> V_43 . V_50 ) ;
switch( V_94 ) {
case V_100 :
F_50 ( & V_47 -> V_25 -> V_101 ) ;
V_55 = F_51 ( V_47 , V_35 -> V_85 ) ;
if ( ! V_55 )
V_48 = V_102 ;
else
V_48 = F_38 ( V_47 , V_55 ) ;
if ( V_48 ) {
F_52 ( & V_47 -> V_25 -> V_101 ) ;
break;
}
if ( V_22 -> V_43 . V_50 ) {
struct V_56 * V_57 = V_55 -> V_58 ;
struct V_34 * V_51 = NULL ;
struct V_103 * V_104 = F_40 ( V_55 -> V_61 ) ;
if ( V_47 -> V_52 &&
! ( V_47 -> V_25 -> V_26 -> V_27 & V_53 ) )
V_51 = V_22 -> V_51 ;
F_14 ( V_47 , L_30
L_31 ,
V_57 -> V_74 ,
V_22 -> V_43 . V_50 ) ;
V_55 -> V_105 = V_106 ;
V_48 = F_29 ( & V_22 -> V_43 . V_2 ,
V_104 -> V_107 . V_108 ,
V_104 -> V_107 . V_109 ,
V_57 -> V_74 ,
V_22 -> V_43 . V_50 ,
F_46 ,
V_51 ) ;
F_52 ( & V_47 -> V_25 -> V_101 ) ;
return V_48 ;
}
V_48 = F_53 ( V_47 , V_35 , NULL , 0 ) ;
F_52 ( & V_47 -> V_25 -> V_101 ) ;
break;
case V_110 :
if ( V_22 -> V_43 . V_50 ) {
F_34 ( V_22 ) ;
return 0 ;
}
V_48 = F_33 ( V_47 , V_35 , NULL , 0 ) ;
break;
case V_111 :
F_50 ( & V_47 -> V_25 -> V_101 ) ;
V_55 = F_51 ( V_47 , V_35 -> V_85 ) ;
if ( ! V_55 )
V_48 = V_102 ;
else if ( V_95 )
V_48 = V_112 ;
else if ( V_55 -> V_61 -> V_113 == V_114 ) {
V_55 -> V_105 = V_106 ;
V_48 = F_42 ( V_47 , V_55 ) ;
} else
V_48 = V_86 ;
F_52 ( & V_47 -> V_25 -> V_101 ) ;
break;
case V_115 :
case V_116 :
case V_117 :
case V_118 :
if ( V_119 < V_22 -> V_43 . V_50 ) {
F_43 ( V_79 , V_47 ,
L_32
L_33
L_34 ,
V_22 -> V_43 . V_50 ,
V_119 , V_94 ) ;
V_48 = V_86 ;
break;
}
if ( V_22 -> V_43 . V_50 ) {
F_34 ( V_22 ) ;
return 0 ;
}
case V_120 :
case V_121 :
case V_122 :
V_48 = F_33 ( V_47 , V_35 , NULL , 0 ) ;
break;
default:
V_48 = V_123 ;
break;
}
if ( V_48 == 0 ) {
if ( V_22 -> V_43 . V_50 )
return V_86 ;
F_31 ( V_22 ) ;
}
return V_48 ;
}
static int
V_46 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_24 * V_47 = V_22 -> V_24 ;
struct V_45 * V_35 ;
V_35 = (struct V_45 * ) V_22 -> V_43 . V_44 ;
if ( V_2 -> V_19 == sizeof( struct V_45 ) && V_35 -> V_98 ) {
unsigned int V_95 = V_35 -> V_98 << 2 ;
if ( sizeof( * V_35 ) + V_95 > sizeof( V_22 -> V_43 . V_44 ) )
return V_112 ;
V_2 -> V_9 += V_95 ;
V_2 -> V_7 += V_95 ;
return 0 ;
}
if ( V_47 -> V_42 &&
! ( V_47 -> V_25 -> V_26 -> V_27 & V_53 ) ) {
if ( V_2 -> V_17 == 0 ) {
F_12 ( V_2 ,
V_2 -> V_30 ) ;
return 0 ;
}
F_23 ( V_22 -> V_51 , V_35 ,
V_2 -> V_10 - V_18 ,
V_2 -> V_16 ) ;
if ( ! F_25 ( V_22 , V_2 ) )
return V_124 ;
}
V_22 -> V_43 . V_35 = V_35 ;
return F_47 ( V_47 , V_35 ) ;
}
inline int F_54 ( struct V_21 * V_22 )
{
return V_22 -> V_43 . V_2 . V_37 == V_46 ;
}
int F_55 ( struct V_24 * V_47 , struct V_125 * V_126 ,
unsigned int V_5 , bool V_127 , int * V_128 )
{
struct V_21 * V_22 = V_47 -> V_58 ;
struct V_1 * V_2 = & V_22 -> V_43 . V_2 ;
struct V_129 V_130 ;
unsigned int V_131 = 0 ;
int V_48 = 0 ;
F_14 ( V_47 , L_35 , V_126 -> V_32 - V_5 ) ;
V_47 -> V_132 = V_106 ;
if ( F_56 ( V_47 -> V_133 ) ) {
F_14 ( V_47 , L_36 ) ;
* V_128 = V_134 ;
return 0 ;
}
if ( V_127 ) {
V_2 -> V_10 = V_2 -> V_9 ;
goto V_135;
}
F_57 ( V_126 , V_5 , V_126 -> V_32 , & V_130 ) ;
while ( 1 ) {
unsigned int V_136 ;
const T_3 * V_31 ;
V_136 = F_58 ( V_131 , & V_31 , & V_130 ) ;
if ( V_136 == 0 ) {
F_14 ( V_47 , L_37 ,
V_131 ) ;
* V_128 = V_137 ;
F_59 ( & V_130 ) ;
goto V_138;
}
F_4 ( V_2 -> V_19 >= V_2 -> V_7 ) ;
F_14 ( V_47 , L_38 , V_126 , V_31 ,
V_136 ) ;
V_48 = F_22 ( V_22 , V_2 , V_31 , V_136 ) ;
F_4 ( V_48 == 0 ) ;
V_131 += V_48 ;
if ( V_2 -> V_10 >= V_2 -> V_9 ) {
F_59 ( & V_130 ) ;
goto V_135;
}
}
V_135:
* V_128 = V_139 ;
F_14 ( V_47 , L_39 ) ;
V_48 = V_2 -> V_37 ( V_22 , V_2 ) ;
if ( V_48 != 0 ) {
* V_128 = V_140 ;
F_14 ( V_47 , L_40 , V_48 ) ;
F_60 ( V_47 , V_48 ) ;
return 0 ;
}
V_138:
V_47 -> V_141 += V_131 ;
return V_131 ;
}
int F_61 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = V_55 -> V_58 ;
struct V_24 * V_47 = V_55 -> V_47 ;
struct V_142 * V_61 = V_55 -> V_61 ;
int V_143 ;
if ( ! V_61 ) {
F_14 ( V_47 , L_41 , V_55 -> V_85 ) ;
return V_47 -> V_25 -> V_26 -> V_144 ( V_55 , 0 , V_55 -> V_145 ) ;
}
F_4 ( F_62 ( & V_57 -> V_62 ) ) ;
V_57 -> V_72 = 0 ;
F_14 ( V_47 , L_42 ,
V_55 -> V_85 , V_55 -> V_146 , V_55 -> V_147 . V_89 ) ;
V_143 = V_47 -> V_25 -> V_26 -> V_144 ( V_55 , 0 , V_55 -> V_146 ) ;
if ( V_143 )
return V_143 ;
V_55 -> V_146 = 0 ;
return 0 ;
}
static struct V_59 * F_63 ( struct V_54 * V_55 )
{
struct V_76 * V_25 = V_55 -> V_47 -> V_25 ;
struct V_56 * V_57 = V_55 -> V_58 ;
struct V_59 * V_60 = NULL ;
if ( F_64 ( V_55 ) )
V_60 = & V_55 -> V_147 ;
else {
F_65 ( & V_25 -> V_101 ) ;
if ( V_57 -> V_60 ) {
V_60 = V_57 -> V_60 ;
if ( V_60 -> V_89 <= V_60 -> V_92 ) {
F_14 ( V_55 -> V_47 ,
L_43 , V_60 ) ;
F_37 ( & V_57 -> V_63 . V_64 ,
( void * ) & V_57 -> V_60 ,
sizeof( void * ) ) ;
V_57 -> V_60 = V_60 = NULL ;
}
}
if ( V_60 == NULL ) {
if ( F_36 ( & V_57 -> V_62 ,
( void * ) & V_57 -> V_60 , sizeof( void * ) ) !=
sizeof( void * ) )
V_60 = NULL ;
else
V_60 = V_57 -> V_60 ;
}
F_66 ( & V_25 -> V_101 ) ;
}
return V_60 ;
}
int F_67 ( struct V_54 * V_55 )
{
struct V_24 * V_47 = V_55 -> V_47 ;
struct V_76 * V_25 = V_47 -> V_25 ;
struct V_59 * V_60 ;
int V_48 = 0 ;
V_148:
V_48 = V_25 -> V_26 -> V_149 ( V_55 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( ! V_55 -> V_61 ) {
if ( V_55 -> V_35 -> V_85 == V_150 )
F_68 ( V_55 ) ;
return 0 ;
}
if ( V_55 -> V_61 -> V_113 != V_114 )
return 0 ;
V_60 = F_63 ( V_55 ) ;
if ( V_60 == NULL ) {
F_14 ( V_47 , L_44 ) ;
return 0 ;
}
V_48 = V_47 -> V_25 -> V_26 -> V_151 ( V_55 , V_152 ) ;
if ( V_48 )
return V_48 ;
F_69 ( V_55 , V_60 , (struct V_153 * ) V_55 -> V_35 ) ;
F_14 ( V_47 , L_45 ,
V_60 , V_60 -> V_67 - 1 , V_55 -> V_35 -> V_85 ,
V_60 -> V_74 + V_60 -> V_92 , V_60 -> V_145 ) ;
V_48 = V_47 -> V_25 -> V_26 -> V_144 ( V_55 , V_60 -> V_74 + V_60 -> V_92 ,
V_60 -> V_145 ) ;
if ( V_48 ) {
F_60 ( V_47 , V_154 ) ;
return V_48 ;
}
V_60 -> V_92 += V_60 -> V_145 ;
goto V_148;
}
struct V_155 *
F_70 ( struct V_156 * V_157 , int V_158 ,
T_4 V_159 )
{
struct V_24 * V_47 ;
struct V_155 * V_160 ;
struct V_21 * V_22 ;
V_160 = F_71 ( V_157 , sizeof( * V_22 ) , V_159 ) ;
if ( ! V_160 )
return NULL ;
V_47 = V_160 -> V_58 ;
V_47 -> V_97 = V_119 ;
V_22 = V_47 -> V_58 ;
V_22 -> V_24 = V_47 ;
V_22 -> V_58 = F_72 ( V_158 , V_161 ) ;
if ( ! V_22 -> V_58 ) {
F_73 ( V_160 ) ;
return NULL ;
}
return V_160 ;
}
void F_74 ( struct V_155 * V_160 )
{
struct V_24 * V_47 = V_160 -> V_58 ;
struct V_21 * V_22 = V_47 -> V_58 ;
F_75 ( V_22 -> V_58 ) ;
F_73 ( V_160 ) ;
}
int F_76 ( struct V_76 * V_25 )
{
int V_40 ;
int V_162 ;
for ( V_162 = 0 ; V_162 < V_25 -> V_163 ; V_162 ++ ) {
struct V_54 * V_55 = V_25 -> V_164 [ V_162 ] ;
struct V_56 * V_57 = V_55 -> V_58 ;
if ( F_77 ( & V_57 -> V_63 ,
V_25 -> V_165 * 2 , NULL ,
sizeof( struct V_59 ) ) ) {
goto V_166;
}
if ( F_78 ( & V_57 -> V_62 ,
V_25 -> V_165 * 4 * sizeof( void * ) , V_161 ) ) {
F_79 ( & V_57 -> V_63 ) ;
goto V_166;
}
}
return 0 ;
V_166:
for ( V_40 = 0 ; V_40 < V_162 ; V_40 ++ ) {
struct V_54 * V_55 = V_25 -> V_164 [ V_40 ] ;
struct V_56 * V_57 = V_55 -> V_58 ;
F_80 ( & V_57 -> V_62 ) ;
F_79 ( & V_57 -> V_63 ) ;
}
return - V_167 ;
}
void F_81 ( struct V_76 * V_25 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_25 -> V_163 ; V_40 ++ ) {
struct V_54 * V_55 = V_25 -> V_164 [ V_40 ] ;
struct V_56 * V_57 = V_55 -> V_58 ;
F_80 ( & V_57 -> V_62 ) ;
F_79 ( & V_57 -> V_63 ) ;
}
}
void F_82 ( struct V_155 * V_160 ,
struct V_168 * V_169 )
{
struct V_24 * V_47 = V_160 -> V_58 ;
V_169 -> V_170 = V_47 -> V_170 ;
V_169 -> V_141 = V_47 -> V_141 ;
V_169 -> V_171 = V_47 -> V_172 ;
V_169 -> V_173 = V_47 -> V_174 ;
V_169 -> V_175 = V_47 -> V_176 ;
V_169 -> V_177 = V_47 -> V_75 ;
V_169 -> V_178 = V_47 -> V_93 ;
V_169 -> V_179 = V_47 -> V_180 ;
V_169 -> V_181 = V_47 -> V_182 ;
}
