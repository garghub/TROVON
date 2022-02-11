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
static T_1 F_10 ( unsigned V_28 )
{
T_1 V_29 = 0 ;
if ( V_28 & 1 )
V_29 |= V_30 ;
if ( V_28 & 2 )
V_29 |= V_31 ;
return V_29 ;
}
static int F_11 ( struct V_5 * V_6 , int V_32 , int V_33 , bool V_34 )
{
const unsigned long V_35 = V_36 + F_12 ( V_37 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
T_1 V_38 ;
do {
V_38 = F_13 ( V_9 -> V_16 + V_32 ) ;
if ( ! V_34 )
V_38 = ~ V_38 ;
V_38 &= V_33 ;
if ( V_38 == V_33 )
return 0 ;
} while ( F_14 ( V_36 , V_35 ) );
return - V_39 ;
}
static void F_15 ( void * V_40 )
{
struct V_5 * V_6 = V_40 ;
F_16 ( & V_6 -> V_41 ) ;
}
static T_2 F_17 ( int V_42 , void * V_43 )
{
struct V_8 * V_9 = V_43 ;
F_4 ( V_9 -> V_2 , L_2 ,
V_44 , __LINE__ ,
F_18 ( V_9 -> V_16 + F_9 ( V_9 ) ) ,
F_18 ( V_9 -> V_16 + F_19 ( V_9 ) ) ) ;
return V_45 ;
}
static int F_20 ( struct V_5 * V_6 ,
unsigned char * V_46 , int V_47 ,
unsigned int V_48 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_49 * V_50 = NULL ;
const bool V_51 = F_21 ( V_46 ) ;
const int V_52 = V_51 ? V_53 : V_54 ;
const int V_55 = F_22 ( V_47 , V_52 ) ;
int V_56 ;
int F_3 , V_57 ;
T_1 V_58 ;
struct V_59 * V_60 ;
void * V_61 ;
struct {
T_1 V_62 [ 4 ] ;
struct V_63 V_64 ;
} * V_65 ;
if ( ! V_47 )
return - V_13 ;
V_65 = F_23 ( sizeof( * V_65 ) * V_55 , V_66 ) ;
if ( ! V_65 )
return - V_67 ;
F_24 ( & V_6 -> V_41 ) ;
V_58 = F_18 ( V_9 -> V_16 + V_17 ) ;
V_58 &= ~ ( V_68 | V_69 |
V_70 ) ;
V_58 |= V_71 ;
if ( ! ( V_48 & V_72 ) )
V_58 |= V_70 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
F_3 = F_3 ( V_47 , V_52 ) ;
if ( ( V_56 + 1 == V_55 ) && ( V_48 & V_73 ) )
V_58 |= V_69 ;
if ( V_9 -> V_74 == V_75 ) {
V_58 &= ~ V_68 ;
V_58 |= F_3 ;
}
V_65 [ V_56 ] . V_62 [ 0 ] = V_58 ;
V_65 [ V_56 ] . V_62 [ 3 ] = F_3 ;
if ( V_51 ) {
V_60 = F_25 ( V_46 ) ;
if ( ! V_60 ) {
V_57 = - V_67 ;
goto V_76;
}
V_61 = F_26 ( V_60 ) +
( ( V_77 ) V_46 & ~ V_78 ) ;
} else {
V_61 = V_46 ;
}
F_27 ( & V_65 [ V_56 ] . V_64 , V_61 , F_3 ) ;
V_57 = F_28 ( V_9 -> V_2 , & V_65 [ V_56 ] . V_64 , 1 ,
( V_48 & V_72 ) ? V_79 : V_80 ) ;
V_47 -= F_3 ;
V_46 += F_3 ;
V_50 = F_29 ( V_9 -> V_81 ,
(struct V_63 * ) V_65 [ V_56 ] . V_62 ,
( V_9 -> V_74 == V_75 ) ? 1 : 4 ,
V_82 ,
V_56 ? V_83 : 0 ) ;
if ( ! V_50 ) {
F_4 ( V_9 -> V_2 ,
L_3 ) ;
V_57 = - V_13 ;
goto V_84;
}
V_50 = F_29 ( V_9 -> V_81 ,
& V_65 [ V_56 ] . V_64 , 1 ,
( V_48 & V_72 ) ? V_85 : V_86 ,
V_83 | V_87 ) ;
if ( ! V_50 ) {
F_4 ( V_9 -> V_2 ,
L_4 ) ;
V_57 = - V_13 ;
goto V_84;
}
}
V_50 -> V_88 = F_15 ;
V_50 -> V_89 = V_6 ;
F_30 ( V_50 ) ;
F_31 ( V_9 -> V_81 ) ;
V_57 = F_32 ( & V_6 -> V_41 ,
F_12 ( V_37 ) ) ;
if ( ! V_57 ) {
F_4 ( V_9 -> V_2 , L_5 ) ;
V_57 = - V_39 ;
F_33 ( V_9 -> V_81 ) ;
goto V_76;
}
V_57 = 0 ;
V_76:
while ( -- V_56 >= 0 ) {
V_84:
F_34 ( V_9 -> V_2 , & V_65 [ V_56 ] . V_64 , 1 ,
( V_48 & V_72 ) ? V_79 : V_80 ) ;
}
F_35 ( V_65 ) ;
return V_57 ;
}
static int F_36 ( struct V_5 * V_6 ,
unsigned char * V_46 , int V_47 ,
unsigned int V_48 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
F_6 ( V_69 ,
V_9 -> V_16 + V_17 + V_90 ) ;
while ( V_47 -- ) {
if ( V_47 == 0 && ( V_48 & V_73 ) )
F_6 ( V_69 ,
V_9 -> V_16 + V_17 + V_18 ) ;
if ( V_9 -> V_74 == V_75 ) {
F_6 ( V_68 ,
V_9 -> V_16 + V_17 + V_90 ) ;
F_6 ( 1 ,
V_9 -> V_16 + V_17 + V_18 ) ;
} else {
F_6 ( 1 , V_9 -> V_16 + V_91 ) ;
}
if ( V_48 & V_72 )
F_6 ( V_70 ,
V_9 -> V_16 + V_17 + V_90 ) ;
else
F_6 ( V_70 ,
V_9 -> V_16 + V_17 + V_18 ) ;
F_6 ( V_92 ,
V_9 -> V_16 + V_17 + V_18 ) ;
if ( F_11 ( V_6 , V_17 , V_92 , 1 ) )
return - V_39 ;
if ( V_48 & V_72 )
F_6 ( * V_46 , V_9 -> V_16 + F_37 ( V_9 ) ) ;
F_6 ( V_71 ,
V_9 -> V_16 + V_17 + V_18 ) ;
if ( ! ( V_48 & V_72 ) ) {
if ( F_11 ( V_6 , F_19 ( V_9 ) ,
V_93 , 0 ) )
return - V_39 ;
* V_46 = ( F_18 ( V_9 -> V_16 + F_37 ( V_9 ) ) & 0xff ) ;
}
if ( F_11 ( V_6 , V_17 , V_92 , 0 ) )
return - V_39 ;
V_46 ++ ;
}
if ( V_47 <= 0 )
return 0 ;
return - V_39 ;
}
static int F_38 ( struct V_94 * V_7 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_3 * V_4 , * V_97 ;
unsigned int V_98 ;
int V_99 = 0 ;
F_6 ( V_30 | V_31 ,
V_9 -> V_16 + V_17 + V_90 ) ;
F_6 ( F_10 ( V_96 -> V_6 -> V_100 ) ,
V_9 -> V_16 + V_17 + V_18 ) ;
F_39 (t, tmp_t, &m->transfers, transfer_list) {
V_99 = F_1 ( V_96 -> V_6 , V_4 ) ;
if ( V_99 )
break;
V_98 = ( & V_4 -> V_101 == V_96 -> V_102 . V_103 ) ^ V_4 -> V_104 ?
V_73 : 0 ;
if ( V_4 -> V_47 < 32 ) {
F_6 ( V_105 ,
V_9 -> V_16 + F_9 ( V_9 ) +
V_90 ) ;
if ( V_4 -> V_106 )
V_99 = F_36 ( V_6 ,
( void * ) V_4 -> V_106 ,
V_4 -> V_47 , V_98 | V_72 ) ;
if ( V_4 -> V_107 )
V_99 = F_36 ( V_6 ,
V_4 -> V_107 , V_4 -> V_47 ,
V_98 ) ;
} else {
F_6 ( V_105 ,
V_9 -> V_16 + F_9 ( V_9 ) +
V_18 ) ;
if ( V_4 -> V_106 )
V_99 = F_20 ( V_6 ,
( void * ) V_4 -> V_106 , V_4 -> V_47 ,
V_98 | V_72 ) ;
if ( V_4 -> V_107 )
V_99 = F_20 ( V_6 ,
V_4 -> V_107 , V_4 -> V_47 ,
V_98 ) ;
}
if ( V_99 ) {
F_40 ( V_9 -> V_16 ) ;
break;
}
V_96 -> V_108 += V_4 -> V_47 ;
}
V_96 -> V_99 = V_99 ;
F_41 ( V_7 ) ;
return V_99 ;
}
static int F_42 ( struct V_109 * V_110 )
{
const struct V_111 * V_112 =
F_43 ( V_113 , & V_110 -> V_2 ) ;
struct V_114 * V_115 = V_110 -> V_2 . V_116 ;
struct V_94 * V_7 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_117 * V_118 ;
struct V_119 * V_119 ;
void T_3 * V_16 ;
int V_74 , V_120 ;
int V_57 = 0 , V_121 ;
const int V_122 = 160000000 ;
V_118 = F_44 ( V_110 , V_123 , 0 ) ;
V_121 = F_45 ( V_110 , 0 ) ;
if ( V_121 < 0 )
return - V_13 ;
V_16 = F_46 ( & V_110 -> V_2 , V_118 ) ;
if ( F_47 ( V_16 ) )
return F_48 ( V_16 ) ;
V_119 = F_49 ( & V_110 -> V_2 , NULL ) ;
if ( F_47 ( V_119 ) )
return F_48 ( V_119 ) ;
V_74 = (enum V_124 ) V_112 -> V_125 ;
V_57 = F_50 ( V_115 , L_6 ,
& V_120 ) ;
if ( V_57 )
V_120 = V_122 ;
V_7 = F_51 ( & V_110 -> V_2 , sizeof( * V_6 ) ) ;
if ( ! V_7 )
return - V_67 ;
V_7 -> V_126 = F_38 ;
V_7 -> V_127 = F_52 ( 8 ) ;
V_7 -> V_128 = V_22 | V_24 ;
V_7 -> V_129 = 3 ;
V_7 -> V_2 . V_116 = V_115 ;
V_7 -> V_48 = V_130 ;
V_6 = F_2 ( V_7 ) ;
V_9 = & V_6 -> V_9 ;
V_9 -> V_2 = & V_110 -> V_2 ;
V_9 -> V_119 = V_119 ;
V_9 -> V_16 = V_16 ;
V_9 -> V_74 = V_74 ;
F_53 ( & V_6 -> V_41 ) ;
V_57 = F_54 ( & V_110 -> V_2 , V_121 , F_17 , 0 ,
V_131 , V_9 ) ;
if ( V_57 )
goto V_132;
V_9 -> V_81 = F_55 ( & V_110 -> V_2 , L_7 ) ;
if ( ! V_9 -> V_81 ) {
F_4 ( V_9 -> V_2 , L_8 ) ;
V_57 = - V_133 ;
goto V_132;
}
V_57 = F_56 ( V_9 -> V_119 ) ;
if ( V_57 )
goto V_134;
F_57 ( V_9 -> V_119 , V_120 ) ;
V_57 = F_40 ( V_9 -> V_16 ) ;
if ( V_57 )
goto V_135;
F_58 ( V_110 , V_7 ) ;
V_57 = F_59 ( & V_110 -> V_2 , V_7 ) ;
if ( V_57 ) {
F_4 ( & V_110 -> V_2 , L_9 , V_57 ) ;
goto V_135;
}
return 0 ;
V_135:
F_60 ( V_9 -> V_119 ) ;
V_134:
F_61 ( V_9 -> V_81 ) ;
V_132:
F_62 ( V_7 ) ;
return V_57 ;
}
static int F_63 ( struct V_109 * V_110 )
{
struct V_94 * V_7 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
V_7 = F_64 ( V_110 ) ;
V_6 = F_2 ( V_7 ) ;
V_9 = & V_6 -> V_9 ;
F_60 ( V_9 -> V_119 ) ;
F_61 ( V_9 -> V_81 ) ;
return 0 ;
}
