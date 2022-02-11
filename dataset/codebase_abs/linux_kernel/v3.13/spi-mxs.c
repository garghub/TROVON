static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
const unsigned int V_10 = F_3 ( V_2 -> V_11 , V_4 -> V_12 ) ;
if ( V_10 == 0 ) {
F_4 ( & V_2 -> V_2 , L_1 ) ;
return - V_13 ;
}
if ( V_10 != V_6 -> V_14 ) {
F_5 ( V_9 , V_10 ) ;
V_6 -> V_14 = V_10 ;
}
F_6 ( V_15 ,
V_9 -> V_16 + V_17 + V_18 ) ;
F_6 ( F_7 ( V_19 ) |
F_8 ( V_20 ) |
( ( V_2 -> V_21 & V_22 ) ? V_23 : 0 ) |
( ( V_2 -> V_21 & V_24 ) ? V_25 : 0 ) ,
V_9 -> V_16 + F_9 ( V_9 ) ) ;
F_6 ( 0x0 , V_9 -> V_16 + V_26 ) ;
F_6 ( 0x0 , V_9 -> V_16 + V_27 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_28 )
V_2 -> V_28 = 8 ;
return 0 ;
}
static T_1 F_11 ( unsigned V_29 )
{
T_1 V_30 = 0 ;
if ( V_29 & 1 )
V_30 |= V_31 ;
if ( V_29 & 2 )
V_30 |= V_32 ;
return V_30 ;
}
static int F_12 ( struct V_5 * V_6 , int V_33 , int V_34 , bool V_35 )
{
const unsigned long V_36 = V_37 + F_13 ( V_38 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
T_1 V_39 ;
do {
V_39 = F_14 ( V_9 -> V_16 + V_33 ) ;
if ( ! V_35 )
V_39 = ~ V_39 ;
V_39 &= V_34 ;
if ( V_39 == V_34 )
return 0 ;
} while ( F_15 ( V_37 , V_36 ) );
return - V_40 ;
}
static void F_16 ( void * V_41 )
{
struct V_5 * V_6 = V_41 ;
F_17 ( & V_6 -> V_42 ) ;
}
static T_2 F_18 ( int V_43 , void * V_44 )
{
struct V_8 * V_9 = V_44 ;
F_4 ( V_9 -> V_2 , L_2 ,
V_45 , __LINE__ ,
F_19 ( V_9 -> V_16 + F_9 ( V_9 ) ) ,
F_19 ( V_9 -> V_16 + F_20 ( V_9 ) ) ) ;
return V_46 ;
}
static int F_21 ( struct V_5 * V_6 ,
unsigned char * V_47 , int V_48 ,
unsigned int V_49 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_50 * V_51 = NULL ;
const bool V_52 = F_22 ( V_47 ) ;
const int V_53 = V_52 ? V_54 : V_55 ;
const int V_56 = F_23 ( V_48 , V_53 ) ;
int V_57 ;
int F_3 , V_58 ;
T_1 V_59 ;
struct V_60 * V_61 ;
void * V_62 ;
struct {
T_1 V_63 [ 4 ] ;
struct V_64 V_65 ;
} * V_66 ;
if ( ! V_48 )
return - V_13 ;
V_66 = F_24 ( sizeof( * V_66 ) * V_56 , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
F_25 ( & V_6 -> V_42 ) ;
V_59 = F_19 ( V_9 -> V_16 + V_17 ) ;
V_59 &= ~ ( V_69 | V_70 |
V_71 ) ;
V_59 |= V_72 ;
if ( ! ( V_49 & V_73 ) )
V_59 |= V_71 ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
F_3 = F_3 ( V_48 , V_53 ) ;
if ( ( V_57 + 1 == V_56 ) && ( V_49 & V_74 ) )
V_59 |= V_70 ;
if ( V_9 -> V_75 == V_76 ) {
V_59 &= ~ V_69 ;
V_59 |= F_3 ;
}
V_66 [ V_57 ] . V_63 [ 0 ] = V_59 ;
V_66 [ V_57 ] . V_63 [ 3 ] = F_3 ;
if ( V_52 ) {
V_61 = F_26 ( V_47 ) ;
if ( ! V_61 ) {
V_58 = - V_68 ;
goto V_77;
}
V_62 = F_27 ( V_61 ) +
( ( V_78 ) V_47 & ~ V_79 ) ;
} else {
V_62 = V_47 ;
}
F_28 ( & V_66 [ V_57 ] . V_65 , V_62 , F_3 ) ;
V_58 = F_29 ( V_9 -> V_2 , & V_66 [ V_57 ] . V_65 , 1 ,
( V_49 & V_73 ) ? V_80 : V_81 ) ;
V_48 -= F_3 ;
V_47 += F_3 ;
V_51 = F_30 ( V_9 -> V_82 ,
(struct V_64 * ) V_66 [ V_57 ] . V_63 ,
( V_9 -> V_75 == V_76 ) ? 1 : 4 ,
V_83 ,
V_57 ? V_84 : 0 ) ;
if ( ! V_51 ) {
F_4 ( V_9 -> V_2 ,
L_3 ) ;
V_58 = - V_13 ;
goto V_85;
}
V_51 = F_30 ( V_9 -> V_82 ,
& V_66 [ V_57 ] . V_65 , 1 ,
( V_49 & V_73 ) ? V_86 : V_87 ,
V_84 | V_88 ) ;
if ( ! V_51 ) {
F_4 ( V_9 -> V_2 ,
L_4 ) ;
V_58 = - V_13 ;
goto V_85;
}
}
V_51 -> V_89 = F_16 ;
V_51 -> V_90 = V_6 ;
F_31 ( V_51 ) ;
F_32 ( V_9 -> V_82 ) ;
V_58 = F_33 ( & V_6 -> V_42 ,
F_13 ( V_38 ) ) ;
if ( ! V_58 ) {
F_4 ( V_9 -> V_2 , L_5 ) ;
V_58 = - V_40 ;
F_34 ( V_9 -> V_82 ) ;
goto V_77;
}
V_58 = 0 ;
V_77:
while ( -- V_57 >= 0 ) {
V_85:
F_35 ( V_9 -> V_2 , & V_66 [ V_57 ] . V_65 , 1 ,
( V_49 & V_73 ) ? V_80 : V_81 ) ;
}
F_36 ( V_66 ) ;
return V_58 ;
}
static int F_37 ( struct V_5 * V_6 ,
unsigned char * V_47 , int V_48 ,
unsigned int V_49 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
F_6 ( V_70 ,
V_9 -> V_16 + V_17 + V_91 ) ;
while ( V_48 -- ) {
if ( V_48 == 0 && ( V_49 & V_74 ) )
F_6 ( V_70 ,
V_9 -> V_16 + V_17 + V_18 ) ;
if ( V_9 -> V_75 == V_76 ) {
F_6 ( V_69 ,
V_9 -> V_16 + V_17 + V_91 ) ;
F_6 ( 1 ,
V_9 -> V_16 + V_17 + V_18 ) ;
} else {
F_6 ( 1 , V_9 -> V_16 + V_92 ) ;
}
if ( V_49 & V_73 )
F_6 ( V_71 ,
V_9 -> V_16 + V_17 + V_91 ) ;
else
F_6 ( V_71 ,
V_9 -> V_16 + V_17 + V_18 ) ;
F_6 ( V_93 ,
V_9 -> V_16 + V_17 + V_18 ) ;
if ( F_12 ( V_6 , V_17 , V_93 , 1 ) )
return - V_40 ;
if ( V_49 & V_73 )
F_6 ( * V_47 , V_9 -> V_16 + F_38 ( V_9 ) ) ;
F_6 ( V_72 ,
V_9 -> V_16 + V_17 + V_18 ) ;
if ( ! ( V_49 & V_73 ) ) {
if ( F_12 ( V_6 , F_20 ( V_9 ) ,
V_94 , 0 ) )
return - V_40 ;
* V_47 = ( F_19 ( V_9 -> V_16 + F_38 ( V_9 ) ) & 0xff ) ;
}
if ( F_12 ( V_6 , V_17 , V_93 , 0 ) )
return - V_40 ;
V_47 ++ ;
}
if ( V_48 <= 0 )
return 0 ;
return - V_40 ;
}
static int F_39 ( struct V_95 * V_7 ,
struct V_96 * V_97 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_3 * V_4 , * V_98 ;
unsigned int V_99 ;
int V_100 = 0 ;
F_6 ( V_31 | V_32 ,
V_9 -> V_16 + V_17 + V_91 ) ;
F_6 ( F_11 ( V_97 -> V_6 -> V_101 ) ,
V_9 -> V_16 + V_17 + V_18 ) ;
F_40 (t, tmp_t, &m->transfers, transfer_list) {
V_100 = F_1 ( V_97 -> V_6 , V_4 ) ;
if ( V_100 )
break;
V_99 = ( & V_4 -> V_102 == V_97 -> V_103 . V_104 ) ^ V_4 -> V_105 ?
V_74 : 0 ;
if ( V_4 -> V_48 < 32 ) {
F_6 ( V_106 ,
V_9 -> V_16 + F_9 ( V_9 ) +
V_91 ) ;
if ( V_4 -> V_107 )
V_100 = F_37 ( V_6 ,
( void * ) V_4 -> V_107 ,
V_4 -> V_48 , V_99 | V_73 ) ;
if ( V_4 -> V_108 )
V_100 = F_37 ( V_6 ,
V_4 -> V_108 , V_4 -> V_48 ,
V_99 ) ;
} else {
F_6 ( V_106 ,
V_9 -> V_16 + F_9 ( V_9 ) +
V_18 ) ;
if ( V_4 -> V_107 )
V_100 = F_21 ( V_6 ,
( void * ) V_4 -> V_107 , V_4 -> V_48 ,
V_99 | V_73 ) ;
if ( V_4 -> V_108 )
V_100 = F_21 ( V_6 ,
V_4 -> V_108 , V_4 -> V_48 ,
V_99 ) ;
}
if ( V_100 ) {
F_41 ( V_9 -> V_16 ) ;
break;
}
V_97 -> V_109 += V_4 -> V_48 ;
}
V_97 -> V_100 = V_100 ;
F_42 ( V_7 ) ;
return V_100 ;
}
static int F_43 ( struct V_110 * V_111 )
{
const struct V_112 * V_113 =
F_44 ( V_114 , & V_111 -> V_2 ) ;
struct V_115 * V_116 = V_111 -> V_2 . V_117 ;
struct V_95 * V_7 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_118 * V_119 ;
struct V_120 * V_120 ;
void T_3 * V_16 ;
int V_75 , V_121 ;
int V_58 = 0 , V_122 ;
const int V_123 = 160000000 ;
V_119 = F_45 ( V_111 , V_124 , 0 ) ;
V_122 = F_46 ( V_111 , 0 ) ;
if ( V_122 < 0 )
return - V_13 ;
V_16 = F_47 ( & V_111 -> V_2 , V_119 ) ;
if ( F_48 ( V_16 ) )
return F_49 ( V_16 ) ;
V_120 = F_50 ( & V_111 -> V_2 , NULL ) ;
if ( F_48 ( V_120 ) )
return F_49 ( V_120 ) ;
V_75 = (enum V_125 ) V_113 -> V_126 ;
V_58 = F_51 ( V_116 , L_6 ,
& V_121 ) ;
if ( V_58 )
V_121 = V_123 ;
V_7 = F_52 ( & V_111 -> V_2 , sizeof( * V_6 ) ) ;
if ( ! V_7 )
return - V_68 ;
V_7 -> V_127 = F_39 ;
V_7 -> V_128 = F_10 ;
V_7 -> V_129 = F_53 ( 8 ) ;
V_7 -> V_130 = V_22 | V_24 ;
V_7 -> V_131 = 3 ;
V_7 -> V_2 . V_117 = V_116 ;
V_7 -> V_49 = V_132 ;
V_6 = F_2 ( V_7 ) ;
V_9 = & V_6 -> V_9 ;
V_9 -> V_2 = & V_111 -> V_2 ;
V_9 -> V_120 = V_120 ;
V_9 -> V_16 = V_16 ;
V_9 -> V_75 = V_75 ;
F_54 ( & V_6 -> V_42 ) ;
V_58 = F_55 ( & V_111 -> V_2 , V_122 , F_18 , 0 ,
V_133 , V_9 ) ;
if ( V_58 )
goto V_134;
V_9 -> V_82 = F_56 ( & V_111 -> V_2 , L_7 ) ;
if ( ! V_9 -> V_82 ) {
F_4 ( V_9 -> V_2 , L_8 ) ;
V_58 = - V_135 ;
goto V_134;
}
V_58 = F_57 ( V_9 -> V_120 ) ;
if ( V_58 )
goto V_136;
F_58 ( V_9 -> V_120 , V_121 ) ;
V_58 = F_41 ( V_9 -> V_16 ) ;
if ( V_58 )
goto V_137;
F_59 ( V_111 , V_7 ) ;
V_58 = F_60 ( & V_111 -> V_2 , V_7 ) ;
if ( V_58 ) {
F_4 ( & V_111 -> V_2 , L_9 , V_58 ) ;
goto V_137;
}
return 0 ;
V_137:
F_61 ( V_9 -> V_120 ) ;
V_136:
F_62 ( V_9 -> V_82 ) ;
V_134:
F_63 ( V_7 ) ;
return V_58 ;
}
static int F_64 ( struct V_110 * V_111 )
{
struct V_95 * V_7 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
V_7 = F_65 ( V_111 ) ;
V_6 = F_2 ( V_7 ) ;
V_9 = & V_6 -> V_9 ;
F_61 ( V_9 -> V_120 ) ;
F_62 ( V_9 -> V_82 ) ;
return 0 ;
}
