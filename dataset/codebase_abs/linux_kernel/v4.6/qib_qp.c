static inline unsigned F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_5 )
{
return ( V_4 - V_2 -> V_4 ) * V_6 + V_5 ;
}
static inline unsigned F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_5 ,
unsigned V_7 )
{
if ( V_8 ) {
V_5 ++ ;
if ( ( ( V_5 & V_8 ) >> 1 ) >= V_7 )
V_5 = ( V_5 | V_8 ) + 2 ;
} else {
V_5 = F_3 ( V_4 -> V_9 , V_6 , V_5 ) ;
}
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_10 )
{
unsigned long V_9 = F_5 ( V_10 ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( V_4 -> V_9 )
F_7 ( V_9 ) ;
else
V_4 -> V_9 = ( void * ) V_9 ;
F_8 ( & V_2 -> V_11 ) ;
}
int F_9 ( struct V_12 * V_13 , struct V_1 * V_2 ,
enum V_14 type , T_2 V_15 , T_1 V_10 )
{
T_3 V_16 , V_17 , V_18 , V_19 ;
struct V_3 * V_4 ;
T_3 V_20 ;
struct V_21 * V_22 = F_10 ( V_13 , struct V_21 , V_13 ) ;
struct V_23 * V_24 = F_10 ( V_22 , struct V_23 ,
V_22 ) ;
if ( type == V_25 || type == V_26 ) {
unsigned V_7 ;
V_20 = type == V_26 ;
V_7 = 1 << ( V_20 + 2 * ( V_15 - 1 ) ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_27 & V_7 )
V_20 = - V_28 ;
else
V_2 -> V_27 |= V_7 ;
F_8 ( & V_2 -> V_11 ) ;
goto V_29;
}
V_19 = V_2 -> V_30 + 2 ;
if ( V_19 >= V_31 )
V_19 = 2 ;
if ( V_8 && ( ( V_19 & V_8 ) >> 1 ) >= V_24 -> V_32 )
V_19 = ( V_19 | V_8 ) + 2 ;
V_17 = V_19 & V_33 ;
V_4 = & V_2 -> V_4 [ V_19 / V_6 ] ;
V_18 = V_2 -> V_34 - ! V_17 ;
for ( V_16 = 0 ; ; ) {
if ( F_11 ( ! V_4 -> V_9 ) ) {
F_4 ( V_2 , V_4 , V_10 ) ;
if ( F_11 ( ! V_4 -> V_9 ) )
break;
}
do {
if ( ! F_12 ( V_17 , V_4 -> V_9 ) ) {
V_2 -> V_30 = V_19 ;
V_20 = V_19 ;
goto V_29;
}
V_17 = F_2 ( V_2 , V_4 , V_17 ,
V_24 -> V_32 ) ;
V_19 = F_1 ( V_2 , V_4 , V_17 ) ;
} while ( V_17 < V_6 && V_19 < V_31 );
if ( ++ V_16 > V_18 ) {
if ( V_2 -> V_34 == V_35 )
break;
V_4 = & V_2 -> V_4 [ V_2 -> V_34 ++ ] ;
V_17 = 0 ;
} else if ( V_4 < & V_2 -> V_4 [ V_2 -> V_34 ] ) {
++ V_4 ;
V_17 = 0 ;
} else {
V_4 = & V_2 -> V_4 [ 0 ] ;
V_17 = 2 ;
}
V_19 = F_1 ( V_2 , V_4 , V_17 ) ;
}
V_20 = - V_36 ;
V_29:
return V_20 ;
}
unsigned F_13 ( struct V_12 * V_13 )
{
struct V_21 * V_22 = F_10 ( V_13 , struct V_21 , V_13 ) ;
struct V_23 * V_24 = F_10 ( V_22 , struct V_23 ,
V_22 ) ;
unsigned V_7 , V_37 = 0 ;
for ( V_7 = 0 ; V_7 < V_24 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 = & V_24 -> V_41 [ V_7 ] . V_42 ;
F_14 () ;
if ( F_15 ( V_40 -> V_43 . V_44 [ 0 ] ) )
V_37 ++ ;
if ( F_15 ( V_40 -> V_43 . V_44 [ 1 ] ) )
V_37 ++ ;
F_16 () ;
}
return V_37 ;
}
void F_17 ( struct V_45 * V_44 )
{
struct V_46 * V_47 = V_44 -> V_47 ;
F_18 ( & V_47 -> V_48 , 0 ) ;
}
void F_19 ( struct V_45 * V_44 )
{
struct V_46 * V_47 = V_44 -> V_47 ;
struct V_21 * V_49 = F_20 ( V_44 -> V_50 . V_51 ) ;
F_6 ( & V_49 -> V_13 . V_52 ) ;
if ( ! F_21 ( & V_47 -> V_53 ) && ! ( V_44 -> V_54 & V_55 ) ) {
V_44 -> V_54 &= ~ V_56 ;
F_22 ( & V_47 -> V_53 ) ;
}
F_8 ( & V_49 -> V_13 . V_52 ) ;
if ( ! ( V_44 -> V_54 & V_55 ) ) {
V_44 -> V_57 = 0 ;
if ( V_44 -> V_58 ) {
F_23 ( V_44 -> V_58 ) ;
V_44 -> V_58 = NULL ;
}
if ( V_47 -> V_59 ) {
F_24 ( V_47 -> V_59 ) ;
V_47 -> V_59 = NULL ;
}
}
}
static int F_25 ( T_3 V_60 )
{
int V_61 ;
switch ( V_60 ) {
case 4096 :
V_61 = V_62 ;
break;
case 2048 :
V_61 = V_63 ;
break;
case 1024 :
V_61 = V_64 ;
break;
case 512 :
V_61 = V_65 ;
break;
case 256 :
V_61 = V_66 ;
break;
default:
V_61 = V_63 ;
}
return V_61 ;
}
int F_26 ( struct V_12 * V_13 , struct V_45 * V_44 ,
struct V_67 * V_68 )
{
int V_60 , V_69 , V_70 = V_44 -> V_71 - 1 ;
struct V_21 * V_22 = F_10 ( V_13 , struct V_21 , V_13 ) ;
struct V_23 * V_24 = F_10 ( V_22 , struct V_23 ,
V_22 ) ;
V_60 = F_27 ( V_68 -> V_72 ) ;
if ( V_60 == - 1 )
return - V_28 ;
if ( V_60 > V_24 -> V_41 [ V_70 ] . V_73 )
V_69 = F_25 ( V_24 -> V_41 [ V_70 ] . V_73 ) ;
else
V_69 = V_68 -> V_72 ;
return V_69 ;
}
int F_28 ( T_3 V_60 )
{
return F_25 ( V_60 ) ;
}
T_3 F_29 ( struct V_12 * V_13 , struct V_45 * V_44 , T_3 V_69 )
{
return F_27 ( V_69 ) ;
}
T_4 F_30 ( struct V_45 * V_44 )
{
T_3 V_74 = V_44 -> V_75 & V_76 ;
if ( V_44 -> V_50 . V_77 ) {
V_74 |= V_78 << V_79 ;
} else {
T_3 V_80 , V_81 , V_82 ;
T_3 V_83 ;
struct V_84 * V_85 = V_44 -> V_86 . V_85 ;
T_3 V_87 ;
T_3 V_88 ;
V_87 = V_85 -> V_87 ;
if ( V_87 >= V_44 -> V_86 . V_89 )
V_87 = 0 ;
V_88 = V_85 -> V_88 ;
if ( V_88 >= V_44 -> V_86 . V_89 )
V_88 = 0 ;
V_83 = V_87 - V_88 ;
if ( ( int ) V_83 < 0 )
V_83 += V_44 -> V_86 . V_89 ;
V_80 = 0 ;
V_81 = 31 ;
for (; ; ) {
V_82 = ( V_80 + V_81 ) / 2 ;
if ( V_90 [ V_82 ] == V_83 )
break;
if ( V_90 [ V_82 ] > V_83 )
V_81 = V_82 ;
else if ( V_80 == V_82 )
break;
else
V_80 = V_82 ;
}
V_74 |= V_82 << V_79 ;
}
return F_31 ( V_74 ) ;
}
void * F_32 ( struct V_12 * V_13 , struct V_45 * V_44 , T_1 V_10 )
{
struct V_46 * V_47 ;
V_47 = F_33 ( sizeof( * V_47 ) , V_10 ) ;
if ( ! V_47 )
return F_34 ( - V_36 ) ;
V_47 -> V_91 = V_44 ;
V_47 -> V_92 = F_33 ( sizeof( * V_47 -> V_92 ) , V_10 ) ;
if ( ! V_47 -> V_92 ) {
F_35 ( V_47 ) ;
return F_34 ( - V_36 ) ;
}
F_36 ( & V_47 -> V_93 ) ;
F_37 ( & V_47 -> V_94 , V_95 ) ;
F_38 ( & V_47 -> V_53 ) ;
return V_47 ;
}
void F_39 ( struct V_12 * V_13 , struct V_45 * V_44 )
{
struct V_46 * V_47 = V_44 -> V_47 ;
F_35 ( V_47 -> V_92 ) ;
F_35 ( V_47 ) ;
}
void F_40 ( struct V_45 * V_44 )
{
struct V_46 * V_47 = V_44 -> V_47 ;
F_41 ( & V_47 -> V_94 ) ;
F_42 ( & V_44 -> V_96 ) ;
}
void F_43 ( struct V_45 * V_44 )
{
struct V_46 * V_47 = V_44 -> V_47 ;
F_44 ( V_47 -> V_93 , ! F_45 ( & V_47 -> V_48 ) ) ;
if ( V_47 -> V_59 ) {
F_24 ( V_47 -> V_59 ) ;
V_47 -> V_59 = NULL ;
}
}
void F_46 ( struct V_45 * V_44 )
{
struct V_46 * V_47 = V_44 -> V_47 ;
struct V_21 * V_49 = F_20 ( V_44 -> V_50 . V_51 ) ;
F_6 ( & V_49 -> V_13 . V_52 ) ;
if ( ! F_21 ( & V_47 -> V_53 ) )
F_22 ( & V_47 -> V_53 ) ;
F_8 ( & V_49 -> V_13 . V_52 ) ;
}
void F_47 ( struct V_45 * V_44 , T_3 V_74 )
{
T_3 V_97 = ( V_74 >> V_79 ) & V_98 ;
if ( V_97 == V_78 ) {
if ( ! ( V_44 -> V_54 & V_99 ) ) {
V_44 -> V_54 |= V_99 ;
if ( V_44 -> V_54 & V_100 ) {
V_44 -> V_54 &= ~ V_100 ;
F_48 ( V_44 ) ;
}
}
} else if ( ! ( V_44 -> V_54 & V_99 ) ) {
V_97 = ( V_74 + V_90 [ V_97 ] ) & V_76 ;
if ( F_49 ( V_97 , V_44 -> V_101 ) > 0 ) {
V_44 -> V_101 = V_97 ;
if ( V_44 -> V_54 & V_100 ) {
V_44 -> V_54 &= ~ V_100 ;
F_48 ( V_44 ) ;
}
}
}
}
int F_50 ( struct V_45 * V_44 ,
struct V_102 * V_103 )
{
struct V_104 * V_105 ;
int V_20 = 0 ;
switch ( V_44 -> V_50 . V_106 ) {
case V_107 :
case V_108 :
if ( V_103 -> V_109 > 0x80000000U )
return - V_28 ;
break;
case V_25 :
case V_26 :
case V_110 :
V_105 = F_51 ( V_103 -> V_111 . V_105 ) ;
if ( V_103 -> V_109 > ( 1 << V_105 -> V_112 ) )
return - V_28 ;
V_20 = 1 ;
break;
default:
break;
}
return V_20 ;
}
struct V_113 * F_52 ( struct V_21 * V_49 )
{
struct V_113 * V_114 ;
V_114 = F_33 ( sizeof( * V_114 ) , V_115 ) ;
if ( ! V_114 )
return NULL ;
V_114 -> V_49 = V_49 ;
if ( F_53 ( V_114 ) ) {
F_35 ( V_114 ) ;
return NULL ;
}
return V_114 ;
}
int F_53 ( struct V_113 * V_114 )
{
struct V_21 * V_49 = V_114 -> V_49 ;
int V_7 = V_114 -> V_7 ;
int V_20 = 1 ;
struct V_45 * V_116 = V_114 -> V_44 ;
struct V_45 * V_44 ;
for (; V_7 < V_49 -> V_13 . V_117 -> V_118 ; V_7 ++ ) {
if ( V_116 )
V_44 = F_15 ( V_116 -> V_119 ) ;
else
V_44 = F_15 ( V_49 -> V_13 . V_117 -> V_120 [ V_7 ] ) ;
V_116 = V_44 ;
if ( V_44 ) {
V_114 -> V_44 = V_44 ;
V_114 -> V_7 = V_7 ;
return 0 ;
}
}
return V_20 ;
}
void F_54 ( struct V_121 * V_122 , struct V_113 * V_114 )
{
struct V_102 * V_103 ;
struct V_45 * V_44 = V_114 -> V_44 ;
struct V_46 * V_47 = V_44 -> V_47 ;
V_103 = F_55 ( V_44 , V_44 -> V_123 ) ;
F_56 ( V_122 ,
L_1 ,
V_114 -> V_7 ,
V_44 -> V_50 . V_124 ,
V_125 [ V_44 -> V_50 . V_106 ] ,
V_44 -> V_126 ,
V_103 -> V_127 . V_128 ,
V_44 -> V_57 ,
V_44 -> V_54 ,
F_45 ( & V_47 -> V_48 ) ,
! F_21 ( & V_47 -> V_53 ) ,
V_44 -> V_129 ,
V_103 -> V_130 ,
V_44 -> V_101 ,
V_44 -> V_131 ,
V_44 -> V_132 , V_44 -> V_133 ,
V_44 -> V_134 , V_44 -> V_135 ,
V_44 -> V_123 , V_44 -> V_136 , V_44 -> V_137 ,
V_44 -> V_138 , V_44 -> V_139 , V_44 -> V_140 ,
V_44 -> V_141 ,
V_44 -> V_142 . V_143 ) ;
}
