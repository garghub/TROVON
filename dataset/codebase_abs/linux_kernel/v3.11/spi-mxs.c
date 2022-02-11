static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
T_1 V_10 ;
T_2 V_11 = 0 ;
V_10 = V_2 -> V_10 ;
if ( V_4 && V_4 -> V_10 )
V_10 = V_4 -> V_10 ;
V_11 = V_2 -> V_12 ;
if ( V_4 && V_4 -> V_13 )
V_11 = F_3 ( V_11 , V_4 -> V_13 ) ;
if ( V_11 == 0 ) {
F_4 ( & V_2 -> V_2 , L_1 ) ;
return - V_14 ;
}
F_5 ( V_9 , V_11 ) ;
F_6 ( F_7 ( V_15 ) |
F_8
( V_16 ) |
( ( V_2 -> V_17 & V_18 ) ? V_19 : 0 ) |
( ( V_2 -> V_17 & V_20 ) ? V_21 : 0 ) ,
V_9 -> V_22 + F_9 ( V_9 ) ) ;
F_6 ( 0x0 , V_9 -> V_22 + V_23 ) ;
F_6 ( 0x0 , V_9 -> V_22 + V_24 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( ! V_2 -> V_10 )
V_2 -> V_10 = 8 ;
if ( V_2 -> V_17 & ~ ( V_18 | V_20 ) )
return - V_14 ;
V_25 = F_1 ( V_2 , NULL ) ;
if ( V_25 ) {
F_4 ( & V_2 -> V_2 ,
L_2 , V_25 ) ;
}
return V_25 ;
}
static T_2 F_11 ( unsigned V_26 )
{
T_2 V_27 = 0 ;
if ( V_26 & 1 )
V_27 |= V_28 ;
if ( V_26 & 2 )
V_27 |= V_29 ;
return V_27 ;
}
static void F_12 ( struct V_5 * V_6 , unsigned V_26 )
{
const T_2 V_30 =
V_28 | V_29 ;
T_2 V_27 ;
struct V_8 * V_9 = & V_6 -> V_9 ;
F_6 ( V_30 , V_9 -> V_22 + V_31 + V_32 ) ;
V_27 = F_11 ( V_26 ) ;
F_6 ( V_27 , V_9 -> V_22 + V_31 + V_33 ) ;
}
static inline void F_13 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
F_6 ( V_34 ,
V_9 -> V_22 + V_31 + V_33 ) ;
F_6 ( V_35 ,
V_9 -> V_22 + V_31 + V_32 ) ;
}
static inline void F_14 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
F_6 ( V_34 ,
V_9 -> V_22 + V_31 + V_32 ) ;
F_6 ( V_35 ,
V_9 -> V_22 + V_31 + V_33 ) ;
}
static int F_15 ( struct V_5 * V_6 , int V_36 , int V_30 , bool V_37 )
{
const unsigned long V_38 = V_39 + F_16 ( V_40 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
T_2 V_41 ;
do {
V_41 = F_17 ( V_9 -> V_22 + V_36 ) ;
if ( ! V_37 )
V_41 = ~ V_41 ;
V_41 &= V_30 ;
if ( V_41 == V_30 )
return 0 ;
} while ( F_18 ( V_39 , V_38 ) );
return - V_42 ;
}
static void F_19 ( void * V_43 )
{
struct V_5 * V_6 = V_43 ;
F_20 ( & V_6 -> V_44 ) ;
}
static T_3 F_21 ( int V_45 , void * V_46 )
{
struct V_8 * V_9 = V_46 ;
F_4 ( V_9 -> V_2 , L_3 ,
V_47 , __LINE__ ,
F_22 ( V_9 -> V_22 + F_9 ( V_9 ) ) ,
F_22 ( V_9 -> V_22 + F_23 ( V_9 ) ) ) ;
return V_48 ;
}
static int F_24 ( struct V_5 * V_6 , int V_26 ,
unsigned char * V_49 , int V_50 ,
int * V_51 , int * V_52 , int V_53 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_54 * V_55 = NULL ;
const bool V_56 = F_25 ( V_49 ) ;
const int V_57 = V_56 ? V_58 : V_59 ;
const int V_60 = F_26 ( V_50 , V_57 ) ;
int V_61 ;
int F_3 , V_62 ;
T_2 V_63 ;
struct V_64 * V_65 ;
void * V_66 ;
struct {
T_2 V_67 [ 4 ] ;
struct V_68 V_69 ;
} * V_70 ;
if ( ! V_50 )
return - V_14 ;
V_70 = F_27 ( sizeof( * V_70 ) * V_60 , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
F_28 ( V_6 -> V_44 ) ;
V_63 = F_22 ( V_9 -> V_22 + V_31 ) ;
V_63 &= ~ V_73 ;
V_63 |= V_74 | F_11 ( V_26 ) ;
if ( * V_51 )
V_63 |= V_34 ;
if ( ! V_53 )
V_63 |= V_75 ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
F_3 = F_3 ( V_50 , V_57 ) ;
if ( ( V_61 + 1 == V_60 ) && * V_52 )
V_63 |= V_35 ;
if ( V_9 -> V_76 == V_77 ) {
V_63 &= ~ V_73 ;
V_63 |= F_3 ;
}
V_70 [ V_61 ] . V_67 [ 0 ] = V_63 ;
V_70 [ V_61 ] . V_67 [ 3 ] = F_3 ;
if ( V_56 ) {
V_65 = F_29 ( V_49 ) ;
if ( ! V_65 ) {
V_62 = - V_72 ;
goto V_78;
}
V_66 = F_30 ( V_65 ) +
( ( V_79 ) V_49 & ~ V_80 ) ;
} else {
V_66 = V_49 ;
}
F_31 ( & V_70 [ V_61 ] . V_69 , V_66 , F_3 ) ;
V_62 = F_32 ( V_9 -> V_2 , & V_70 [ V_61 ] . V_69 , 1 ,
V_53 ? V_81 : V_82 ) ;
V_50 -= F_3 ;
V_49 += F_3 ;
V_55 = F_33 ( V_9 -> V_83 ,
(struct V_68 * ) V_70 [ V_61 ] . V_67 ,
( V_9 -> V_76 == V_77 ) ? 1 : 4 ,
V_84 ,
V_61 ? V_85 : 0 ) ;
if ( ! V_55 ) {
F_4 ( V_9 -> V_2 ,
L_4 ) ;
V_62 = - V_14 ;
goto V_86;
}
V_55 = F_33 ( V_9 -> V_83 ,
& V_70 [ V_61 ] . V_69 , 1 ,
V_53 ? V_87 : V_88 ,
V_85 | V_89 ) ;
if ( ! V_55 ) {
F_4 ( V_9 -> V_2 ,
L_5 ) ;
V_62 = - V_14 ;
goto V_86;
}
}
V_55 -> V_90 = F_19 ;
V_55 -> V_91 = V_6 ;
F_34 ( V_55 ) ;
F_35 ( V_9 -> V_83 ) ;
V_62 = F_36 ( & V_6 -> V_44 ,
F_16 ( V_40 ) ) ;
if ( ! V_62 ) {
F_4 ( V_9 -> V_2 , L_6 ) ;
V_62 = - V_42 ;
F_37 ( V_9 -> V_83 ) ;
goto V_78;
}
V_62 = 0 ;
V_78:
while ( -- V_61 >= 0 ) {
V_86:
F_38 ( V_9 -> V_2 , & V_70 [ V_61 ] . V_69 , 1 ,
V_53 ? V_81 : V_82 ) ;
}
F_39 ( V_70 ) ;
return V_62 ;
}
static int F_40 ( struct V_5 * V_6 , int V_26 ,
unsigned char * V_49 , int V_50 ,
int * V_51 , int * V_52 , int V_53 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
if ( * V_51 )
F_13 ( V_6 ) ;
F_12 ( V_6 , V_26 ) ;
while ( V_50 -- ) {
if ( * V_52 && V_50 == 0 )
F_14 ( V_6 ) ;
if ( V_9 -> V_76 == V_77 ) {
F_6 ( V_73 ,
V_9 -> V_22 + V_31 + V_32 ) ;
F_6 ( 1 ,
V_9 -> V_22 + V_31 + V_33 ) ;
} else {
F_6 ( 1 , V_9 -> V_22 + V_92 ) ;
}
if ( V_53 )
F_6 ( V_75 ,
V_9 -> V_22 + V_31 + V_32 ) ;
else
F_6 ( V_75 ,
V_9 -> V_22 + V_31 + V_33 ) ;
F_6 ( V_93 ,
V_9 -> V_22 + V_31 + V_33 ) ;
if ( F_15 ( V_6 , V_31 , V_93 , 1 ) )
return - V_42 ;
if ( V_53 )
F_6 ( * V_49 , V_9 -> V_22 + F_41 ( V_9 ) ) ;
F_6 ( V_74 ,
V_9 -> V_22 + V_31 + V_33 ) ;
if ( ! V_53 ) {
if ( F_15 ( V_6 , F_23 ( V_9 ) ,
V_94 , 0 ) )
return - V_42 ;
* V_49 = ( F_22 ( V_9 -> V_22 + F_41 ( V_9 ) ) & 0xff ) ;
}
if ( F_15 ( V_6 , V_31 , V_93 , 0 ) )
return - V_42 ;
V_49 ++ ;
}
if ( V_50 <= 0 )
return 0 ;
return - V_42 ;
}
static int F_42 ( struct V_95 * V_7 ,
struct V_96 * V_97 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
int V_51 , V_52 ;
struct V_3 * V_4 , * V_98 ;
int V_99 = 0 ;
int V_26 ;
V_51 = V_52 = 0 ;
V_26 = V_97 -> V_6 -> V_100 ;
F_43 (t, tmp_t, &m->transfers, transfer_list) {
V_99 = F_1 ( V_97 -> V_6 , V_4 ) ;
if ( V_99 )
break;
if ( & V_4 -> V_101 == V_97 -> V_102 . V_103 )
V_51 = 1 ;
if ( & V_4 -> V_101 == V_97 -> V_102 . V_104 )
V_52 = 1 ;
if ( ( V_4 -> V_105 && V_4 -> V_106 ) || ( V_4 -> V_107 && V_4 -> V_108 ) ) {
F_4 ( V_9 -> V_2 ,
L_7 ) ;
V_99 = - V_14 ;
break;
}
if ( V_4 -> V_50 < 32 ) {
F_6 ( V_109 ,
V_9 -> V_22 + F_9 ( V_9 ) +
V_32 ) ;
if ( V_4 -> V_106 )
V_99 = F_40 ( V_6 , V_26 ,
( void * ) V_4 -> V_106 ,
V_4 -> V_50 , & V_51 , & V_52 , 1 ) ;
if ( V_4 -> V_105 )
V_99 = F_40 ( V_6 , V_26 ,
V_4 -> V_105 , V_4 -> V_50 ,
& V_51 , & V_52 , 0 ) ;
} else {
F_6 ( V_109 ,
V_9 -> V_22 + F_9 ( V_9 ) +
V_33 ) ;
if ( V_4 -> V_106 )
V_99 = F_24 ( V_6 , V_26 ,
( void * ) V_4 -> V_106 , V_4 -> V_50 ,
& V_51 , & V_52 , 1 ) ;
if ( V_4 -> V_105 )
V_99 = F_24 ( V_6 , V_26 ,
V_4 -> V_105 , V_4 -> V_50 ,
& V_51 , & V_52 , 0 ) ;
}
if ( V_99 ) {
F_44 ( V_9 -> V_22 ) ;
break;
}
V_97 -> V_110 += V_4 -> V_50 ;
V_51 = V_52 = 0 ;
}
V_97 -> V_99 = V_99 ;
F_45 ( V_7 ) ;
return V_99 ;
}
static int F_46 ( struct V_111 * V_112 )
{
const struct V_113 * V_114 =
F_47 ( V_115 , & V_112 -> V_2 ) ;
struct V_116 * V_117 = V_112 -> V_2 . V_118 ;
struct V_95 * V_7 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_119 * V_120 ;
struct V_121 * V_121 ;
void T_4 * V_22 ;
int V_76 , V_122 ;
int V_62 = 0 , V_123 ;
const int V_124 = 160000000 ;
V_120 = F_48 ( V_112 , V_125 , 0 ) ;
V_123 = F_49 ( V_112 , 0 ) ;
if ( ! V_120 || V_123 < 0 )
return - V_14 ;
V_22 = F_50 ( & V_112 -> V_2 , V_120 ) ;
if ( F_51 ( V_22 ) )
return F_52 ( V_22 ) ;
V_121 = F_53 ( & V_112 -> V_2 , NULL ) ;
if ( F_51 ( V_121 ) )
return F_52 ( V_121 ) ;
V_76 = (enum V_126 ) V_114 -> V_127 ;
V_62 = F_54 ( V_117 , L_8 ,
& V_122 ) ;
if ( V_62 )
V_122 = V_124 ;
V_7 = F_55 ( & V_112 -> V_2 , sizeof( * V_6 ) ) ;
if ( ! V_7 )
return - V_72 ;
V_7 -> V_128 = F_42 ;
V_7 -> V_129 = F_10 ;
V_7 -> V_130 = F_56 ( 8 ) ;
V_7 -> V_131 = V_18 | V_20 ;
V_7 -> V_132 = 3 ;
V_7 -> V_2 . V_118 = V_117 ;
V_7 -> V_133 = V_134 ;
V_6 = F_2 ( V_7 ) ;
V_9 = & V_6 -> V_9 ;
V_9 -> V_2 = & V_112 -> V_2 ;
V_9 -> V_121 = V_121 ;
V_9 -> V_22 = V_22 ;
V_9 -> V_76 = V_76 ;
F_57 ( & V_6 -> V_44 ) ;
V_62 = F_58 ( & V_112 -> V_2 , V_123 , F_21 , 0 ,
V_135 , V_9 ) ;
if ( V_62 )
goto V_136;
V_9 -> V_83 = F_59 ( & V_112 -> V_2 , L_9 ) ;
if ( ! V_9 -> V_83 ) {
F_4 ( V_9 -> V_2 , L_10 ) ;
V_62 = - V_137 ;
goto V_136;
}
F_60 ( V_9 -> V_121 ) ;
F_61 ( V_9 -> V_121 , V_122 ) ;
V_9 -> V_138 = F_62 ( V_9 -> V_121 ) / 1000 ;
F_44 ( V_9 -> V_22 ) ;
F_63 ( V_112 , V_7 ) ;
V_62 = F_64 ( V_7 ) ;
if ( V_62 ) {
F_4 ( & V_112 -> V_2 , L_11 , V_62 ) ;
goto V_139;
}
return 0 ;
V_139:
F_65 ( V_9 -> V_83 ) ;
F_66 ( V_9 -> V_121 ) ;
V_136:
F_67 ( V_7 ) ;
return V_62 ;
}
static int F_68 ( struct V_111 * V_112 )
{
struct V_95 * V_7 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
V_7 = F_69 ( F_70 ( V_112 ) ) ;
V_6 = F_2 ( V_7 ) ;
V_9 = & V_6 -> V_9 ;
F_71 ( V_7 ) ;
F_65 ( V_9 -> V_83 ) ;
F_66 ( V_9 -> V_121 ) ;
F_67 ( V_7 ) ;
return 0 ;
}
