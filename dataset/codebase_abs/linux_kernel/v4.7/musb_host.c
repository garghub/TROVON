struct V_1 * F_1 ( struct V_2 * V_3 )
{
return * (struct V_1 * * ) V_3 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
void T_1 * V_7 = V_6 -> V_8 ;
T_2 V_9 ;
int V_10 = 1000 ;
V_9 = F_3 ( V_7 , V_11 ) ;
while ( V_9 & V_12 ) {
V_9 |= V_13 | V_14 ;
F_4 ( V_7 , V_11 , V_9 ) ;
V_9 = F_3 ( V_7 , V_11 ) ;
if ( F_5 ( V_1 -> V_15 , V_10 -- < 1 ,
L_1 ,
V_6 -> V_16 , V_9 ) )
return;
}
}
static void F_6 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
T_2 V_9 ;
int V_10 = 5 ;
do {
V_9 = F_3 ( V_7 , V_11 ) ;
if ( ! ( V_9 & ( V_17 | V_18 ) ) )
break;
F_4 ( V_7 , V_11 , V_19 ) ;
V_9 = F_3 ( V_7 , V_11 ) ;
F_7 ( 10 ) ;
} while ( -- V_10 );
F_8 ( ! V_10 , L_1 ,
V_6 -> V_16 , V_9 ) ;
F_4 ( V_7 , V_11 , 0 ) ;
}
static inline void F_9 ( struct V_5 * V_6 )
{
T_2 V_20 ;
if ( V_6 -> V_16 ) {
V_20 = F_3 ( V_6 -> V_8 , V_11 ) ;
V_20 |= V_14 | V_21 ;
F_4 ( V_6 -> V_8 , V_11 , V_20 ) ;
} else {
V_20 = V_22 | V_17 ;
F_4 ( V_6 -> V_8 , V_23 , V_20 ) ;
}
}
static inline void F_10 ( struct V_5 * V_6 )
{
T_2 V_20 ;
V_20 = F_3 ( V_6 -> V_8 , V_11 ) ;
V_20 |= V_24 | V_21 ;
if ( F_11 ( V_6 -> V_1 ) )
V_20 |= V_25 ;
F_4 ( V_6 -> V_8 , V_11 , V_20 ) ;
}
static void F_12 ( struct V_5 * V_6 , int V_26 , struct V_27 * V_28 )
{
if ( V_26 != 0 || V_6 -> V_29 )
V_6 -> V_30 = V_28 ;
if ( V_26 == 0 || V_6 -> V_29 )
V_6 -> V_31 = V_28 ;
}
static struct V_27 * F_13 ( struct V_5 * V_6 , int V_26 )
{
return V_26 ? V_6 -> V_30 : V_6 -> V_31 ;
}
static void
F_14 ( struct V_1 * V_1 , int V_26 , struct V_27 * V_28 )
{
T_2 V_32 ;
T_3 V_33 ;
void T_1 * V_34 = V_1 -> V_35 ;
struct V_36 * V_36 = F_15 ( V_28 ) ;
void * V_37 = V_36 -> V_38 ;
T_3 V_39 = 0 ;
struct V_5 * V_40 = V_28 -> V_40 ;
unsigned V_41 = V_36 -> V_41 ;
T_4 V_42 = F_16 ( V_41 ) ;
int V_16 = V_40 -> V_16 ;
V_28 -> V_39 = 0 ;
V_28 -> V_43 = 0 ;
switch ( V_28 -> type ) {
case V_44 :
V_26 = 0 ;
V_1 -> V_45 = V_46 ;
V_37 = V_36 -> V_47 ;
V_33 = 8 ;
break;
case V_48 :
V_28 -> V_49 = 0 ;
V_28 -> V_32 = 0 ;
V_39 = V_36 -> V_50 [ 0 ] . V_39 ;
V_33 = V_36 -> V_50 [ 0 ] . V_51 ;
break;
default:
V_37 = V_36 -> V_38 + V_36 -> V_52 ;
V_33 = V_36 -> V_53 - V_36 -> V_52 ;
}
F_17 (musb->controller, L_2 ,
qh, urb, address, qh->epnum,
is_in ? L_3 : L_4 ,
({char *s; switch (qh->type) {
case USB_ENDPOINT_XFER_CONTROL: s = L_5; break;
case USB_ENDPOINT_XFER_BULK: s = L_6; break;
case USB_ENDPOINT_XFER_ISOC: s = L_7; break;
default: s = L_8; break;
} s; }),
epnum, buf + offset, len) ;
F_12 ( V_40 , V_26 , V_28 ) ;
F_18 ( V_1 , V_16 , V_36 , ! V_26 , V_37 , V_39 , V_33 ) ;
if ( V_26 )
return;
switch ( V_28 -> type ) {
case V_48 :
case V_54 :
F_17 ( V_1 -> V_15 , L_9 ) ;
V_32 = F_3 ( V_34 , V_55 ) ;
if ( 1 ) {
V_28 -> V_32 = 0 ;
goto V_56;
} else {
V_28 -> V_32 = V_36 -> V_57 ;
F_17 ( V_1 -> V_15 , L_10 , V_16 ) ;
#if 1
F_19 ( V_34 , V_58 , 0xff ) ;
#endif
}
break;
default:
V_56:
F_17 ( V_1 -> V_15 , L_11 , V_16 ,
V_40 -> V_59 ? L_12 : L_13 ) ;
if ( ! V_40 -> V_59 )
F_9 ( V_40 ) ;
else if ( F_11 ( V_1 ) || F_20 ( V_1 ) )
F_10 ( V_40 ) ;
}
}
static void F_21 ( struct V_1 * V_1 , struct V_36 * V_36 , int V_60 )
__releases( V_1 -> V_61 )
__acquires( V_1 -> V_61 )
{
F_17 ( V_1 -> V_15 ,
L_14 ,
V_36 , V_36 -> V_62 , V_60 ,
F_16 ( V_36 -> V_41 ) ,
F_22 ( V_36 -> V_41 ) ,
F_23 ( V_36 -> V_41 ) ? L_3 : L_4 ,
V_36 -> V_52 , V_36 -> V_53
) ;
F_24 ( V_1 -> V_3 , V_36 ) ;
F_25 ( & V_1 -> V_61 ) ;
F_26 ( V_1 -> V_3 , V_36 , V_60 ) ;
F_27 ( & V_1 -> V_61 ) ;
}
static inline void F_28 ( struct V_27 * V_28 , int V_26 ,
struct V_36 * V_36 )
{
void T_1 * V_7 = V_28 -> V_40 -> V_8 ;
T_2 V_9 ;
if ( V_26 )
V_9 = F_3 ( V_7 , V_63 ) & V_64 ;
else
V_9 = F_3 ( V_7 , V_11 ) & V_65 ;
F_29 ( V_36 -> V_66 , V_28 -> V_16 , ! V_26 , V_9 ? 1 : 0 ) ;
}
static void F_30 ( struct V_1 * V_1 , struct V_36 * V_36 ,
struct V_5 * V_40 , int V_26 )
{
struct V_27 * V_28 = F_13 ( V_40 , V_26 ) ;
struct V_5 * V_6 = V_28 -> V_40 ;
int V_67 = V_28 -> V_68 ;
int V_60 ;
V_60 = ( V_36 -> V_60 == - V_69 ) ? 0 : V_36 -> V_60 ;
switch ( V_28 -> type ) {
case V_70 :
case V_54 :
F_28 ( V_28 , V_26 , V_36 ) ;
break;
case V_48 :
if ( V_60 == 0 && V_36 -> V_71 )
V_60 = - V_72 ;
break;
}
V_28 -> V_68 = 0 ;
F_21 ( V_1 , V_36 , V_60 ) ;
V_28 -> V_68 = V_67 ;
if ( F_31 ( & V_28 -> V_73 -> V_74 ) ) {
struct V_75 * V_76 ;
struct V_77 * V_78 = V_1 -> V_77 ;
if ( V_26 ) {
V_6 -> V_79 = 1 ;
if ( V_6 -> V_80 ) {
V_78 -> V_81 ( V_6 -> V_80 ) ;
V_6 -> V_80 = NULL ;
}
} else {
V_6 -> V_82 = 1 ;
if ( V_6 -> V_59 ) {
V_78 -> V_81 ( V_6 -> V_59 ) ;
V_6 -> V_59 = NULL ;
}
}
F_12 ( V_6 , V_26 , NULL ) ;
V_28 -> V_73 -> V_83 = NULL ;
switch ( V_28 -> type ) {
case V_44 :
case V_70 :
if ( V_28 -> V_84 == 1 ) {
V_76 = V_28 -> V_85 . V_86 ;
F_32 ( & V_28 -> V_85 ) ;
F_33 ( V_28 ) ;
V_28 = F_34 ( V_76 ) ;
break;
}
case V_48 :
case V_54 :
F_33 ( V_28 ) ;
V_28 = NULL ;
break;
}
}
if ( ( ! V_60 || ! V_26 ) && V_28 && V_28 -> V_68 ) {
F_17 ( V_1 -> V_15 , L_15 ,
V_40 -> V_16 , V_26 ? 'R' : 'T' , F_15 ( V_28 ) ) ;
F_14 ( V_1 , V_26 , V_28 ) ;
}
}
static T_2 F_35 ( struct V_5 * V_40 , T_2 V_9 )
{
V_9 |= V_87 | V_88 ;
V_9 &= ~ ( V_89
| V_90
| V_91 ) ;
F_4 ( V_40 -> V_8 , V_63 , V_9 ) ;
F_4 ( V_40 -> V_8 , V_63 , V_9 ) ;
return F_3 ( V_40 -> V_8 , V_63 ) ;
}
static bool
F_36 ( struct V_1 * V_1 , struct V_36 * V_36 , T_4 V_16 , T_4 V_92 )
{
T_2 V_93 ;
T_4 * V_37 ;
T_2 V_9 ;
bool V_94 = false ;
T_3 V_51 ;
int V_95 = 0 ;
struct V_5 * V_40 = V_1 -> V_96 + V_16 ;
void T_1 * V_7 = V_40 -> V_8 ;
struct V_27 * V_28 = V_40 -> V_30 ;
int V_41 = V_36 -> V_41 ;
void * V_97 = V_36 -> V_38 ;
V_93 = F_3 ( V_7 , V_98 ) ;
F_17 ( V_1 -> V_15 , L_16 , V_16 , V_93 ,
V_36 -> V_38 , V_28 -> V_39 ,
V_36 -> V_53 ) ;
if ( F_37 ( V_41 ) ) {
int V_60 = 0 ;
struct V_99 * V_100 ;
if ( V_92 ) {
V_60 = - V_101 ;
V_36 -> V_71 ++ ;
}
V_100 = V_36 -> V_50 + V_28 -> V_49 ;
V_37 = V_97 + V_100 -> V_39 ;
V_51 = V_100 -> V_51 ;
if ( V_93 > V_51 ) {
if ( V_60 == 0 ) {
V_60 = - V_102 ;
V_36 -> V_71 ++ ;
}
F_17 ( V_1 -> V_15 , L_17 , V_93 , V_51 ) ;
V_95 = 1 ;
} else
V_51 = V_93 ;
V_36 -> V_52 += V_51 ;
V_100 -> V_52 = V_51 ;
V_100 -> V_60 = V_60 ;
V_94 = ( ++ V_28 -> V_49 >= V_36 -> V_103 ) ;
} else {
V_37 = V_97 + V_28 -> V_39 ;
V_51 = V_36 -> V_53 - V_28 -> V_39 ;
if ( V_93 > V_51 ) {
if ( V_36 -> V_60 == - V_69 )
V_36 -> V_60 = - V_102 ;
F_17 ( V_1 -> V_15 , L_17 , V_93 , V_51 ) ;
V_95 = 1 ;
} else
V_51 = V_93 ;
V_36 -> V_52 += V_51 ;
V_28 -> V_39 += V_51 ;
V_94 = ( V_36 -> V_52 == V_36 -> V_53 )
|| ( V_93 < V_28 -> V_104 )
|| ( V_36 -> V_60 != - V_69 ) ;
if ( V_94
&& ( V_36 -> V_60 == - V_69 )
&& ( V_36 -> V_105 & V_106 )
&& ( V_36 -> V_52
< V_36 -> V_53 ) )
V_36 -> V_60 = - V_107 ;
}
F_38 ( V_40 , V_51 , V_37 ) ;
V_9 = F_3 ( V_7 , V_63 ) ;
V_9 |= V_108 ;
if ( F_39 ( V_95 ) )
F_35 ( V_40 , V_9 ) ;
else {
V_9 &= ~ ( V_88 | V_89 ) ;
if ( ! V_94 )
V_9 |= V_89 ;
F_4 ( V_7 , V_63 , V_9 ) ;
}
return V_94 ;
}
static void
F_40 ( struct V_1 * V_1 , struct V_27 * V_28 , T_4 V_16 )
{
struct V_5 * V_6 = V_1 -> V_96 + V_16 ;
T_2 V_9 ;
if ( V_6 -> V_29 ) {
V_9 = F_3 ( V_6 -> V_8 , V_11 ) ;
if ( V_9 & V_109 ) {
F_2 ( V_6 ) ;
V_9 = F_3 ( V_6 -> V_8 , V_11 ) ;
F_4 ( V_6 -> V_8 , V_11 ,
V_9 | V_110 ) ;
}
if ( V_9 & V_25 )
F_4 ( V_6 -> V_8 , V_11 , V_25 ) ;
F_4 ( V_6 -> V_8 , V_11 , 0 ) ;
}
V_9 = F_3 ( V_6 -> V_8 , V_63 ) ;
if ( V_9 & V_88 )
F_41 ( L_18 , V_6 -> V_16 ,
F_3 ( V_6 -> V_8 , V_98 ) ) ;
F_35 ( V_6 , V_111 ) ;
if ( V_1 -> V_112 ) {
F_42 ( V_1 , V_16 , V_28 -> V_113 ) ;
F_43 ( V_1 , V_16 , V_28 -> V_114 ) ;
F_44 ( V_1 , V_16 , V_28 -> V_115 ) ;
} else
F_19 ( V_1 -> V_35 , V_116 , V_28 -> V_113 ) ;
F_19 ( V_6 -> V_8 , V_117 , V_28 -> V_118 ) ;
F_19 ( V_6 -> V_8 , V_119 , V_28 -> V_120 ) ;
if ( V_1 -> V_121 )
F_4 ( V_6 -> V_8 , V_122 , V_6 -> V_123 ) ;
else
F_4 ( V_6 -> V_8 , V_122 ,
V_28 -> V_104 | ( ( V_28 -> V_124 - 1 ) << 11 ) ) ;
V_6 -> V_79 = 0 ;
}
static void F_45 ( struct V_77 * V_78 ,
struct V_5 * V_40 , struct V_27 * V_28 ,
struct V_36 * V_36 , T_3 V_39 ,
T_3 * V_51 , T_4 * V_125 )
{
struct V_126 * V_127 = V_40 -> V_59 ;
void T_1 * V_7 = V_40 -> V_8 ;
T_2 V_128 = V_28 -> V_104 ;
T_2 V_9 ;
if ( * V_51 > V_127 -> V_129 )
* V_51 = V_127 -> V_129 ;
V_9 = F_3 ( V_7 , V_11 ) ;
if ( * V_51 > V_128 ) {
* V_125 = 1 ;
V_9 |= V_25 | V_24 ;
if ( V_28 -> V_124 == 1 || ( V_28 -> V_124 > 1 &&
F_46 ( V_40 -> V_1 , V_28 -> type ) ) )
V_9 |= V_130 ;
} else {
* V_125 = 0 ;
V_9 &= ~ ( V_130 | V_25 ) ;
V_9 |= V_24 ;
}
V_127 -> V_131 = * V_125 ;
F_4 ( V_7 , V_11 , V_9 ) ;
}
static void F_47 ( struct V_77 * V_78 ,
struct V_5 * V_40 ,
struct V_27 * V_28 ,
struct V_36 * V_36 ,
T_3 V_39 ,
T_3 * V_51 ,
T_4 * V_125 )
{
struct V_126 * V_127 = V_40 -> V_59 ;
V_127 -> V_132 = 0 ;
* V_125 = ( V_36 -> V_105 & V_133 ) ? 1 : 0 ;
}
static bool F_48 ( struct V_77 * V_78 ,
struct V_5 * V_40 , struct V_27 * V_28 ,
struct V_36 * V_36 , T_3 V_39 , T_3 V_51 )
{
struct V_126 * V_127 = V_40 -> V_59 ;
T_2 V_128 = V_28 -> V_104 ;
T_4 V_125 ;
if ( F_49 ( V_40 -> V_1 ) || F_50 ( V_40 -> V_1 ) )
F_45 ( V_78 , V_40 , V_28 , V_36 , V_39 ,
& V_51 , & V_125 ) ;
else if ( F_11 ( V_40 -> V_1 ) || F_20 ( V_40 -> V_1 ) )
F_47 ( V_78 , V_40 , V_28 , V_36 , V_39 ,
& V_51 , & V_125 ) ;
else
return false ;
V_28 -> V_43 = V_51 ;
F_51 () ;
if ( ! V_78 -> V_134 ( V_127 , V_128 , V_125 ,
V_36 -> V_135 + V_39 , V_51 ) ) {
void T_1 * V_7 = V_40 -> V_8 ;
T_2 V_9 ;
V_78 -> V_81 ( V_127 ) ;
V_40 -> V_59 = NULL ;
V_9 = F_3 ( V_7 , V_11 ) ;
V_9 &= ~ ( V_130 | V_24 ) ;
F_4 ( V_7 , V_11 , V_9 | V_21 ) ;
return false ;
}
return true ;
}
static void F_18 ( struct V_1 * V_1 , T_4 V_16 ,
struct V_36 * V_36 , int V_136 ,
T_4 * V_37 , T_3 V_39 , T_3 V_33 )
{
struct V_77 * V_77 ;
struct V_126 * V_126 ;
T_4 V_137 ;
void T_1 * V_34 = V_1 -> V_35 ;
struct V_5 * V_40 = V_1 -> V_96 + V_16 ;
void T_1 * V_7 = V_40 -> V_8 ;
struct V_27 * V_28 = F_13 ( V_40 , ! V_136 ) ;
T_2 V_138 = V_28 -> V_104 ;
T_4 V_139 = 1 ;
T_2 V_9 ;
F_17 ( V_1 -> V_15 , L_19
L_20 ,
V_136 ? L_21 : L_22 ,
V_16 , V_36 , V_36 -> V_66 -> V_140 ,
V_28 -> V_113 , V_28 -> V_16 , V_136 ? L_4 : L_3 ,
V_28 -> V_114 , V_28 -> V_115 ,
V_33 ) ;
F_52 ( V_34 , V_16 ) ;
if ( V_136 && ! V_33 ) {
V_139 = 0 ;
V_9 = F_3 ( V_7 , V_11 ) ;
V_9 &= ~ V_24 ;
F_4 ( V_7 , V_11 , V_9 ) ;
V_40 -> V_59 = NULL ;
}
V_77 = V_1 -> V_77 ;
if ( V_139 && F_53 () && V_16 && V_77 ) {
V_126 = V_136 ? V_40 -> V_59 : V_40 -> V_80 ;
if ( ! V_126 ) {
V_126 = V_77 -> V_141 (
V_77 , V_40 , V_136 ) ;
if ( V_136 )
V_40 -> V_59 = V_126 ;
else
V_40 -> V_80 = V_126 ;
}
} else
V_126 = NULL ;
if ( V_136 ) {
T_2 V_9 ;
T_2 V_142 ;
T_2 V_143 ;
V_9 = F_3 ( V_7 , V_11 ) ;
V_142 = V_1 -> V_144 ;
F_4 ( V_34 , V_145 , V_142 & ~ ( 1 << V_16 ) ) ;
if ( V_16 ) {
if ( ! V_40 -> V_146 )
F_2 ( V_40 ) ;
V_9 &= ~ ( V_147
| V_130
| V_24
| V_110
| V_148
| V_149
| V_14
) ;
V_9 |= V_109 ;
if ( ! V_40 -> V_146 ) {
if ( F_54 ( V_36 -> V_66 , V_28 -> V_16 , 1 ) )
V_9 |= V_150
| V_65 ;
else
V_9 |= V_151 ;
}
F_4 ( V_7 , V_11 , V_9 ) ;
V_9 &= ~ V_25 ;
F_4 ( V_7 , V_11 , V_9 ) ;
V_9 = F_3 ( V_7 , V_11 ) ;
} else {
F_6 ( V_40 ) ;
}
if ( V_1 -> V_112 ) {
F_55 ( V_1 , V_16 , V_28 -> V_113 ) ;
F_56 ( V_1 , V_16 , V_28 -> V_114 ) ;
F_57 ( V_1 , V_16 , V_28 -> V_115 ) ;
} else
F_19 ( V_34 , V_116 , V_28 -> V_113 ) ;
if ( V_16 ) {
F_19 ( V_7 , V_152 , V_28 -> V_118 ) ;
if ( V_1 -> V_121 ) {
F_4 ( V_7 , V_153 ,
V_40 -> V_154 ) ;
} else if ( F_46 ( V_1 , V_28 -> type ) ) {
V_28 -> V_124 = V_40 -> V_154
/ V_138 ;
F_4 ( V_7 , V_153 , V_138
| ( ( V_28 -> V_124 ) - 1 ) << 11 ) ;
} else {
F_4 ( V_7 , V_153 ,
V_28 -> V_104 |
( ( V_28 -> V_124 - 1 ) << 11 ) ) ;
}
F_19 ( V_7 , V_155 , V_28 -> V_120 ) ;
} else {
F_19 ( V_7 , V_156 , V_28 -> V_120 ) ;
if ( V_1 -> V_112 )
F_19 ( V_7 , V_157 ,
V_28 -> V_118 ) ;
}
if ( F_46 ( V_1 , V_28 -> type ) )
V_143 = F_58 ( ( T_3 ) V_40 -> V_154 ,
V_33 ) ;
else
V_143 = F_58 ( ( T_3 ) V_138 , V_33 ) ;
if ( V_126 && F_48 ( V_77 ,
V_40 , V_28 , V_36 , V_39 , V_33 ) )
V_143 = 0 ;
if ( V_143 ) {
V_28 -> V_43 = V_143 ;
if ( ! V_37 ) {
F_59 ( & V_28 -> V_158 , V_36 -> V_159 , 1 ,
V_160
| V_161 ) ;
if ( ! F_60 ( & V_28 -> V_158 ) ) {
F_61 ( V_1 -> V_15 ,
L_23
L_24 ) ;
F_62 ( & V_28 -> V_158 ) ;
goto V_162;
}
V_37 = V_28 -> V_158 . V_163 + V_36 -> V_159 -> V_39 +
V_36 -> V_52 ;
V_143 = F_63 ( T_3 , V_143 ,
V_28 -> V_158 . V_51 ) ;
F_64 ( V_40 , V_143 , V_37 ) ;
V_28 -> V_158 . V_164 = V_143 ;
F_62 ( & V_28 -> V_158 ) ;
} else
F_64 ( V_40 , V_143 , V_37 ) ;
}
V_162:
F_4 ( V_34 , V_145 , V_142 ) ;
} else {
T_2 V_9 ;
if ( V_40 -> V_79 ) {
F_40 ( V_1 , V_28 , V_16 ) ;
if ( F_54 ( V_36 -> V_66 , V_28 -> V_16 , 0 ) )
V_9 = V_165
| V_64 ;
else
V_9 = 0 ;
if ( V_28 -> type == V_54 )
V_9 |= V_166 ;
} else {
V_9 = F_3 ( V_40 -> V_8 , V_63 ) ;
if ( V_9 & ( V_88
| V_167
| V_89 ) )
F_65 ( L_25 ,
V_40 -> V_16 , V_9 ) ;
V_9 &= V_166 ;
}
if ( ( F_11 ( V_1 ) || F_20 ( V_1 ) ) && V_126 ) {
V_126 -> V_132 = 0L ;
V_28 -> V_43 = V_33 ;
F_4 ( V_40 -> V_8 , V_63 , V_9 ) ;
V_9 = F_3 ( V_40 -> V_8 , V_63 ) ;
V_137 = V_77 -> V_134 ( V_126 ,
V_138 , ! ( V_36 -> V_105 &
V_106 ) ,
V_36 -> V_135 + V_39 ,
V_28 -> V_43 ) ;
if ( ! V_137 ) {
V_77 -> V_81 ( V_126 ) ;
V_40 -> V_80 = V_126 = NULL ;
} else
V_9 |= V_167 ;
}
V_9 |= V_89 ;
F_17 ( V_1 -> V_15 , L_26 , V_16 , V_9 ) ;
F_4 ( V_40 -> V_8 , V_63 , V_9 ) ;
V_9 = F_3 ( V_40 -> V_8 , V_63 ) ;
}
}
static void F_66 ( struct V_1 * V_1 , struct V_5 * V_6 ,
int V_26 )
{
struct V_126 * V_78 ;
struct V_36 * V_36 ;
void T_1 * V_34 = V_1 -> V_35 ;
void T_1 * V_7 = V_6 -> V_8 ;
struct V_27 * V_168 , * V_169 ;
T_2 V_170 , V_171 ;
F_52 ( V_34 , V_6 -> V_16 ) ;
if ( V_26 ) {
V_78 = F_53 () ? V_6 -> V_80 : NULL ;
V_170 = F_3 ( V_7 , V_63 ) ;
V_170 |= V_108 ;
V_170 &= ~ V_89 ;
F_4 ( V_7 , V_63 , V_170 ) ;
V_170 &= ~ V_172 ;
F_4 ( V_7 , V_63 , V_170 ) ;
V_168 = F_34 ( & V_1 -> V_173 ) ;
} else {
V_78 = F_53 () ? V_6 -> V_59 : NULL ;
V_171 = F_3 ( V_7 , V_11 ) ;
V_171 |= V_21 ;
V_171 &= ~ V_147 ;
F_4 ( V_7 , V_11 , V_171 ) ;
V_168 = F_34 ( & V_1 -> V_174 ) ;
}
if ( V_168 ) {
V_36 = F_15 ( V_168 ) ;
if ( F_67 ( V_78 ) == V_175 ) {
V_78 -> V_60 = V_176 ;
V_1 -> V_77 -> V_177 ( V_78 ) ;
V_36 -> V_52 += V_78 -> V_132 ;
V_78 -> V_132 = 0L ;
}
F_28 ( V_168 , V_26 , V_36 ) ;
if ( V_26 ) {
F_68 ( & V_168 -> V_85 , & V_1 -> V_173 ) ;
V_169 = F_34 ( & V_1 -> V_173 ) ;
V_6 -> V_79 = 1 ;
} else {
F_68 ( & V_168 -> V_85 , & V_1 -> V_174 ) ;
V_169 = F_34 ( & V_1 -> V_174 ) ;
V_6 -> V_82 = 1 ;
}
F_14 ( V_1 , V_26 , V_169 ) ;
}
}
static bool F_69 ( struct V_1 * V_1 , T_2 V_33 , struct V_36 * V_36 )
{
bool V_178 = false ;
T_4 * V_179 = NULL ;
T_2 V_180 = 0 ;
struct V_5 * V_40 = V_1 -> V_181 ;
struct V_27 * V_28 = V_40 -> V_30 ;
struct V_182 * V_183 ;
switch ( V_1 -> V_45 ) {
case V_184 :
V_179 = V_36 -> V_38 + V_36 -> V_52 ;
V_180 = F_63 ( V_185 , V_33 , V_36 -> V_53 -
V_36 -> V_52 ) ;
if ( V_180 < V_33 )
V_36 -> V_60 = - V_102 ;
F_38 ( V_40 , V_180 , V_179 ) ;
V_36 -> V_52 += V_180 ;
if ( V_33 < V_28 -> V_104 ) {
} else if ( V_36 -> V_52 <
V_36 -> V_53 )
V_178 = true ;
break;
case V_46 :
V_183 = (struct V_182 * ) V_36 -> V_47 ;
if ( ! V_183 -> V_186 ) {
F_17 ( V_1 -> V_15 , L_27 ) ;
break;
} else if ( V_183 -> V_187 & V_188 ) {
F_17 ( V_1 -> V_15 , L_28 ) ;
V_1 -> V_45 = V_184 ;
V_178 = true ;
break;
} else {
F_17 ( V_1 -> V_15 , L_29 ) ;
V_1 -> V_45 = V_189 ;
V_178 = true ;
}
case V_189 :
V_180 = F_63 ( V_185 , V_28 -> V_104 ,
V_36 -> V_53 -
V_36 -> V_52 ) ;
if ( V_180 ) {
V_179 = ( T_4 * ) ( V_36 -> V_38
+ V_36 -> V_52 ) ;
F_17 ( V_1 -> V_15 , L_30 ,
V_180 ,
( V_180 == 1 ) ? L_5 : L_31 ,
V_179 ) ;
F_64 ( V_40 , V_180 , V_179 ) ;
V_36 -> V_52 += V_180 ;
V_178 = true ;
}
break;
default:
F_65 ( L_32 , V_1 -> V_45 ) ;
break;
}
return V_178 ;
}
T_5 F_70 ( struct V_1 * V_1 )
{
struct V_36 * V_36 ;
T_2 V_9 , V_33 ;
int V_60 = 0 ;
void T_1 * V_34 = V_1 -> V_35 ;
struct V_5 * V_40 = V_1 -> V_181 ;
void T_1 * V_7 = V_40 -> V_8 ;
struct V_27 * V_28 = V_40 -> V_30 ;
bool V_62 = false ;
T_5 V_190 = V_191 ;
V_36 = F_15 ( V_28 ) ;
F_52 ( V_34 , 0 ) ;
V_9 = F_3 ( V_7 , V_23 ) ;
V_33 = ( V_9 & V_18 )
? F_71 ( V_7 , V_192 )
: 0 ;
F_17 ( V_1 -> V_15 , L_33 ,
V_9 , V_28 , V_33 , V_36 , V_1 -> V_45 ) ;
if ( V_193 == V_1 -> V_45 ) {
V_190 = V_194 ;
V_62 = true ;
}
if ( V_9 & V_195 ) {
F_17 ( V_1 -> V_15 , L_34 ) ;
V_60 = - V_196 ;
} else if ( V_9 & V_197 ) {
F_17 ( V_1 -> V_15 , L_35 , V_9 ) ;
V_60 = - V_198 ;
} else if ( V_9 & V_199 ) {
F_17 ( V_1 -> V_15 , L_36 ) ;
F_4 ( V_7 , V_23 , 0 ) ;
V_190 = V_194 ;
}
if ( V_60 ) {
F_17 ( V_1 -> V_15 , L_37 ) ;
V_190 = V_194 ;
if ( V_36 )
V_36 -> V_60 = V_60 ;
V_62 = true ;
if ( V_9 & V_200 ) {
V_9 &= ~ V_200 ;
F_4 ( V_7 , V_23 , V_9 ) ;
V_9 &= ~ V_199 ;
F_4 ( V_7 , V_23 , V_9 ) ;
} else {
F_6 ( V_40 ) ;
}
F_19 ( V_7 , V_156 , 0 ) ;
F_4 ( V_7 , V_23 , 0 ) ;
}
if ( F_39 ( ! V_36 ) ) {
F_65 ( L_38 ) ;
F_6 ( V_40 ) ;
goto V_94;
}
if ( ! V_62 ) {
if ( F_69 ( V_1 , V_33 , V_36 ) ) {
V_9 = ( V_184 == V_1 -> V_45 )
? V_200 : V_17 ;
} else {
if ( F_72 ( V_36 -> V_41 )
|| ! V_36 -> V_53 )
V_9 = V_201
| V_200 ;
else
V_9 = V_201
| V_17 ;
V_9 |= V_202 ;
V_1 -> V_45 = V_193 ;
F_17 ( V_1 -> V_15 , L_39 , V_9 ) ;
}
F_4 ( V_7 , V_23 , V_9 ) ;
V_190 = V_194 ;
} else
V_1 -> V_45 = V_203 ;
if ( V_62 )
F_30 ( V_1 , V_36 , V_40 , 1 ) ;
V_94:
return V_190 ;
}
void F_73 ( struct V_1 * V_1 , T_4 V_16 )
{
int V_41 ;
bool V_94 = false ;
T_2 V_171 ;
V_185 V_51 = 0 ;
V_185 V_39 = 0 ;
struct V_5 * V_40 = V_1 -> V_96 + V_16 ;
void T_1 * V_7 = V_40 -> V_8 ;
struct V_27 * V_28 = V_40 -> V_31 ;
struct V_36 * V_36 = F_15 ( V_28 ) ;
T_3 V_60 = 0 ;
void T_1 * V_34 = V_1 -> V_35 ;
struct V_126 * V_78 ;
bool V_204 = false ;
F_52 ( V_34 , V_16 ) ;
V_171 = F_3 ( V_7 , V_11 ) ;
if ( ! V_36 ) {
F_17 ( V_1 -> V_15 , L_40 , V_16 , V_171 ) ;
return;
}
V_41 = V_36 -> V_41 ;
V_78 = F_53 () ? V_40 -> V_59 : NULL ;
F_17 ( V_1 -> V_15 , L_41 , V_16 , V_171 ,
V_78 ? L_42 : L_5 ) ;
if ( V_171 & V_148 ) {
F_17 ( V_1 -> V_15 , L_43 , V_16 ) ;
V_60 = - V_196 ;
} else if ( V_171 & V_149 ) {
F_17 ( V_1 -> V_15 , L_44 , V_16 ) ;
V_60 = - V_205 ;
} else if ( V_171 & V_147 ) {
if ( V_70 == V_28 -> type && V_28 -> V_84 == 1
&& ! F_74 ( & V_1 -> V_174 ) ) {
F_17 ( V_1 -> V_15 ,
L_45 , V_16 ) ;
F_66 ( V_1 , V_40 , 0 ) ;
} else {
F_17 ( V_1 -> V_15 ,
L_46 , V_16 ) ;
F_52 ( V_34 , V_16 ) ;
F_4 ( V_7 , V_11 ,
V_21
| V_14 ) ;
}
return;
}
V_94:
if ( V_60 ) {
if ( F_67 ( V_78 ) == V_175 ) {
V_78 -> V_60 = V_176 ;
V_1 -> V_77 -> V_177 ( V_78 ) ;
}
F_2 ( V_40 ) ;
V_171 &= ~ ( V_130
| V_24
| V_149
| V_148
| V_147
) ;
F_52 ( V_34 , V_16 ) ;
F_4 ( V_7 , V_11 , V_171 ) ;
F_4 ( V_7 , V_11 , V_171 ) ;
F_19 ( V_7 , V_155 , 0 ) ;
V_94 = true ;
}
if ( F_67 ( V_78 ) == V_175 ) {
F_17 ( V_1 -> V_15 , L_40 , V_16 , V_171 ) ;
return;
}
if ( F_53 () && V_78 && ! V_60 ) {
if ( V_171 & V_25 ) {
V_171 &= F_3 ( V_7 , V_11 ) ;
if ( V_171 & V_14 ) {
V_171 &= ~ ( V_24 |
V_14 ) ;
F_4 ( V_7 , V_11 ,
V_171 | V_21 ) ;
}
V_171 &= ~ ( V_25 |
V_14 ) ;
F_4 ( V_7 , V_11 ,
V_171 | V_21 ) ;
V_171 = F_3 ( V_7 , V_11 ) ;
}
if ( V_171 & ( V_12 | V_14 ) ) {
F_17 ( V_1 -> V_15 , L_47
L_48 , V_171 ) ;
return;
}
}
if ( ! V_60 || V_78 || F_37 ( V_41 ) ) {
if ( V_78 )
V_51 = V_78 -> V_132 ;
else
V_51 = V_28 -> V_43 ;
V_28 -> V_39 += V_51 ;
if ( F_37 ( V_41 ) ) {
struct V_99 * V_100 ;
V_100 = V_36 -> V_50 + V_28 -> V_49 ;
V_100 -> V_52 = V_51 ;
V_100 -> V_60 = V_60 ;
if ( ++ V_28 -> V_49 >= V_36 -> V_103 ) {
V_94 = true ;
} else {
V_100 ++ ;
V_39 = V_100 -> V_39 ;
V_51 = V_100 -> V_51 ;
}
} else if ( V_78 && V_36 -> V_53 == V_28 -> V_39 ) {
V_94 = true ;
} else {
if ( V_28 -> V_43 < V_28 -> V_104 )
V_94 = true ;
else if ( V_28 -> V_39 == V_36 -> V_53
&& ! ( V_36 -> V_105
& V_133 ) )
V_94 = true ;
if ( ! V_94 ) {
V_39 = V_28 -> V_39 ;
V_51 = V_36 -> V_53 - V_39 ;
V_204 = true ;
}
}
}
if ( V_36 -> V_60 != - V_69 ) {
V_94 = true ;
if ( V_60 == 0 )
V_60 = V_36 -> V_60 ;
}
if ( V_94 ) {
V_36 -> V_60 = V_60 ;
V_36 -> V_52 = V_28 -> V_39 ;
F_30 ( V_1 , V_36 , V_40 , V_206 ) ;
return;
} else if ( ( F_37 ( V_41 ) || V_204 ) && V_78 ) {
if ( F_48 ( V_1 -> V_77 , V_40 , V_28 , V_36 ,
V_39 , V_51 ) ) {
if ( F_11 ( V_1 ) || F_20 ( V_1 ) )
F_10 ( V_40 ) ;
return;
}
} else if ( V_171 & V_24 ) {
F_17 ( V_1 -> V_15 , L_49 ) ;
return;
}
if ( V_51 > V_28 -> V_104 )
V_51 = V_28 -> V_104 ;
F_75 ( V_1 -> V_3 , V_36 ) ;
if ( ! V_36 -> V_38 )
V_28 -> V_207 = true ;
if ( V_28 -> V_207 ) {
if ( ! F_60 ( & V_28 -> V_158 ) ) {
F_61 ( V_1 -> V_15 , L_50 ) ;
F_62 ( & V_28 -> V_158 ) ;
V_60 = - V_208 ;
goto V_94;
}
V_36 -> V_38 = V_28 -> V_158 . V_163 ;
V_51 = F_63 ( T_3 , V_51 , V_28 -> V_158 . V_51 ) ;
F_64 ( V_40 , V_51 , V_36 -> V_38 ) ;
V_28 -> V_158 . V_164 = V_51 ;
F_62 ( & V_28 -> V_158 ) ;
} else {
F_64 ( V_40 , V_51 , V_36 -> V_38 + V_39 ) ;
}
V_28 -> V_43 = V_51 ;
if ( V_28 -> V_207 ) {
if ( V_39 + V_51 >= V_36 -> V_53 )
V_28 -> V_207 = false ;
}
F_52 ( V_34 , V_16 ) ;
F_4 ( V_7 , V_11 ,
V_21 | V_14 ) ;
}
static int F_76 ( struct V_77 * V_78 ,
struct V_5 * V_40 ,
struct V_27 * V_28 ,
struct V_36 * V_36 ,
V_185 V_33 )
{
struct V_126 * V_127 = V_40 -> V_80 ;
void T_1 * V_7 = V_40 -> V_8 ;
T_6 * V_37 ;
T_3 V_51 , V_209 ;
T_2 V_210 ;
V_37 = ( void * ) V_36 -> V_50 [ V_28 -> V_49 ] . V_39 +
( T_3 ) V_36 -> V_135 ;
V_51 = V_36 -> V_50 [ V_28 -> V_49 ] . V_51 ;
V_210 = F_3 ( V_7 , V_63 ) ;
V_210 |= V_167 ;
F_4 ( V_40 -> V_8 , V_63 , V_210 ) ;
V_209 = V_78 -> V_134 ( V_127 , V_28 -> V_104 , 0 ,
( T_3 ) V_37 , V_51 ) ;
return V_209 ;
}
static inline int F_76 ( struct V_77 * V_78 ,
struct V_5 * V_40 ,
struct V_27 * V_28 ,
struct V_36 * V_36 ,
V_185 V_33 )
{
return false ;
}
static int F_77 ( struct V_77 * V_78 ,
struct V_5 * V_40 ,
struct V_27 * V_28 ,
struct V_36 * V_36 ,
V_185 V_33 )
{
struct V_126 * V_127 = V_40 -> V_80 ;
void T_1 * V_7 = V_40 -> V_8 ;
T_2 V_210 ;
int V_41 ;
bool V_94 ;
V_41 = V_36 -> V_41 ;
if ( F_37 ( V_41 ) ) {
struct V_99 * V_100 ;
V_100 = V_36 -> V_50 + V_28 -> V_49 ;
V_100 -> V_52 = V_33 ;
if ( V_100 -> V_60 != - V_101 && V_100 -> V_60 != - V_102 )
V_100 -> V_60 = 0 ;
if ( ++ V_28 -> V_49 >= V_36 -> V_103 ) {
V_94 = true ;
} else {
if ( F_78 ( V_40 -> V_1 ) )
V_94 = F_76 ( V_78 , V_40 , V_28 ,
V_36 , V_33 ) ;
V_94 = false ;
}
} else {
V_94 = ( V_36 -> V_52 + V_33 >=
V_36 -> V_53
|| V_127 -> V_132 < V_28 -> V_104
|| V_127 -> V_211 ) ;
}
if ( ! V_94 ) {
V_210 = F_3 ( V_7 , V_63 ) ;
V_210 |= V_89 ;
F_4 ( V_7 , V_63 , V_108 | V_210 ) ;
}
return V_94 ;
}
static int F_79 ( struct V_77 * V_78 ,
struct V_5 * V_40 ,
struct V_27 * V_28 ,
struct V_36 * V_36 ,
V_185 V_33 ,
T_4 V_92 )
{
struct V_1 * V_1 = V_40 -> V_1 ;
void T_1 * V_7 = V_40 -> V_8 ;
struct V_126 * V_127 = V_40 -> V_80 ;
T_2 V_93 , V_210 ;
int V_51 , V_41 , V_94 ;
T_6 V_37 ;
V_93 = F_3 ( V_7 , V_98 ) ;
V_41 = V_36 -> V_41 ;
if ( F_37 ( V_41 ) ) {
int V_212 = 0 ;
struct V_99 * V_100 ;
V_100 = V_36 -> V_50 + V_28 -> V_49 ;
if ( V_92 ) {
V_212 = - V_101 ;
V_36 -> V_71 ++ ;
}
if ( V_93 > V_100 -> V_51 ) {
if ( V_212 == 0 ) {
V_212 = - V_102 ;
V_36 -> V_71 ++ ;
}
F_17 ( V_1 -> V_15 , L_17 ,
V_93 , V_100 -> V_51 ) ;
V_51 = V_100 -> V_51 ;
} else
V_51 = V_93 ;
V_100 -> V_60 = V_212 ;
V_37 = V_36 -> V_135 + V_100 -> V_39 ;
} else {
V_51 = V_93 ;
V_37 = V_36 -> V_135 + V_36 -> V_52 ;
}
V_127 -> V_131 = 0 ;
#ifdef F_80
if ( ( V_36 -> V_105 & V_106 )
&& ( V_36 -> V_53 - V_36 -> V_52 )
> V_28 -> V_104 )
V_127 -> V_131 = 1 ;
if ( V_93 < V_40 -> V_123 ) {
V_51 = V_93 ;
V_127 -> V_131 = 0 ;
} else {
V_51 = V_36 -> V_53 ;
}
#endif
V_210 = F_3 ( V_7 , V_63 ) ;
V_210 &= ~ V_89 ;
if ( V_127 -> V_131 == 0 )
V_210 &= ~ V_90 ;
else
V_210 |= V_90 ;
V_210 |= V_167 ;
if ( V_28 -> V_124 == 1 )
V_210 |= V_91 ;
F_4 ( V_7 , V_63 , V_108 | V_210 ) ;
V_94 = V_78 -> V_134 ( V_127 , V_28 -> V_104 ,
V_127 -> V_131 ,
V_37 , V_51 ) ;
if ( ! V_94 ) {
V_78 -> V_81 ( V_127 ) ;
V_40 -> V_80 = NULL ;
V_127 = NULL ;
V_210 = F_3 ( V_7 , V_63 ) ;
V_210 &= ~ ( V_167
| V_90
| V_91 ) ;
F_4 ( V_7 , V_63 , V_210 ) ;
}
return V_94 ;
}
static inline int F_77 ( struct V_77 * V_78 ,
struct V_5 * V_40 ,
struct V_27 * V_28 ,
struct V_36 * V_36 ,
V_185 V_33 )
{
return false ;
}
static inline int F_79 ( struct V_77 * V_78 ,
struct V_5 * V_40 ,
struct V_27 * V_28 ,
struct V_36 * V_36 ,
V_185 V_33 ,
T_4 V_92 )
{
return false ;
}
void F_81 ( struct V_1 * V_1 , T_4 V_16 )
{
struct V_36 * V_36 ;
struct V_5 * V_40 = V_1 -> V_96 + V_16 ;
struct V_77 * V_213 = V_1 -> V_77 ;
void T_1 * V_7 = V_40 -> V_8 ;
struct V_27 * V_28 = V_40 -> V_30 ;
V_185 V_214 ;
void T_1 * V_34 = V_1 -> V_35 ;
int V_41 ;
T_2 V_170 , V_210 ;
bool V_92 = false ;
bool V_94 = false ;
T_3 V_60 ;
struct V_126 * V_78 ;
unsigned int V_215 = V_160 | V_216 ;
F_52 ( V_34 , V_16 ) ;
V_36 = F_15 ( V_28 ) ;
V_78 = F_53 () ? V_40 -> V_80 : NULL ;
V_60 = 0 ;
V_214 = 0 ;
V_170 = F_3 ( V_7 , V_63 ) ;
V_210 = V_170 ;
if ( F_39 ( ! V_36 ) ) {
F_17 ( V_1 -> V_15 , L_51 , V_16 , V_210 ,
F_3 ( V_7 , V_98 ) ) ;
F_35 ( V_40 , V_111 ) ;
return;
}
V_41 = V_36 -> V_41 ;
F_17 ( V_1 -> V_15 , L_52 ,
V_16 , V_170 , V_36 -> V_52 ,
V_78 ? V_78 -> V_132 : 0 ) ;
if ( V_170 & V_217 ) {
F_17 ( V_1 -> V_15 , L_53 , V_16 ) ;
V_60 = - V_196 ;
} else if ( V_170 & V_218 ) {
F_17 ( V_1 -> V_15 , L_54 , V_16 ) ;
V_60 = - V_198 ;
F_19 ( V_7 , V_119 , 0 ) ;
V_170 &= ~ V_218 ;
F_4 ( V_7 , V_63 , V_170 ) ;
} else if ( V_170 & V_172 ) {
if ( V_48 != V_28 -> type ) {
F_17 ( V_1 -> V_15 , L_55 , V_16 ) ;
if ( F_82 ( V_36 -> V_41 )
&& V_28 -> V_84 == 1
&& ! F_74 ( & V_1 -> V_173 ) ) {
F_66 ( V_1 , V_40 , 1 ) ;
return;
}
F_52 ( V_34 , V_16 ) ;
V_170 |= V_108 ;
V_170 &= ~ V_172 ;
F_4 ( V_7 , V_63 , V_170 ) ;
goto V_162;
} else {
F_17 ( V_1 -> V_15 , L_56 , V_16 ) ;
V_92 = true ;
}
} else if ( V_170 & V_219 ) {
F_17 ( V_1 -> V_15 , L_57 ,
V_16 ) ;
V_60 = - V_198 ;
}
if ( V_60 ) {
if ( F_67 ( V_78 ) == V_175 ) {
V_78 -> V_60 = V_176 ;
V_1 -> V_77 -> V_177 ( V_78 ) ;
V_214 = V_78 -> V_132 ;
}
F_35 ( V_40 , V_111 ) ;
F_19 ( V_7 , V_119 , 0 ) ;
V_94 = true ;
goto V_162;
}
if ( F_39 ( F_67 ( V_78 ) == V_175 ) ) {
F_65 ( L_58 , V_16 , V_170 ) ;
goto V_162;
}
if ( ! F_49 ( V_1 ) && ! F_50 ( V_1 ) &&
( V_170 & V_89 ) ) {
if ( F_67 ( V_78 ) == V_175 ) {
V_78 -> V_60 = V_176 ;
V_1 -> V_77 -> V_177 ( V_78 ) ;
V_214 = V_78 -> V_132 ;
V_94 = true ;
}
F_17 ( V_1 -> V_15 , L_59 , V_16 , V_170 ,
V_214 , V_78 ? L_42 : L_5 ) ;
V_170 &= ~ V_89 ;
F_52 ( V_34 , V_16 ) ;
F_4 ( V_7 , V_63 ,
V_108 | V_170 ) ;
}
if ( V_78 && ( V_170 & V_167 ) ) {
V_214 = V_78 -> V_132 ;
V_210 &= ~ ( V_167
| V_90
| V_91
| V_88 ) ;
F_4 ( V_40 -> V_8 , V_63 , V_210 ) ;
if ( F_49 ( V_1 ) || F_50 ( V_1 ) ||
F_78 ( V_1 ) ) {
V_94 = F_77 ( V_213 , V_40 , V_28 , V_36 , V_214 ) ;
F_17 ( V_40 -> V_1 -> V_15 ,
L_60 ,
V_16 , V_94 ? L_61 : L_62 ,
F_3 ( V_7 , V_63 ) ,
F_3 ( V_7 , V_98 ) ) ;
} else {
V_94 = true ;
}
} else if ( V_36 -> V_60 == - V_69 ) {
if ( F_39 ( ! ( V_170 & V_88 ) ) ) {
V_60 = - V_198 ;
F_65 ( L_63 ) ;
F_52 ( V_34 , V_16 ) ;
V_210 &= ~ V_89 ;
F_4 ( V_7 , V_63 , V_210 ) ;
goto V_162;
}
if ( ( F_49 ( V_1 ) || F_50 ( V_1 ) ||
F_78 ( V_1 ) ) && V_78 ) {
F_17 ( V_40 -> V_1 -> V_15 ,
L_64 ,
V_16 , F_3 ( V_7 , V_98 ) ,
( unsigned long long ) V_36 -> V_135
+ V_36 -> V_52 ,
V_28 -> V_39 ,
V_36 -> V_53 ) ;
if ( F_79 ( V_213 , V_40 , V_28 , V_36 ,
V_214 , V_92 ) )
goto V_162;
else
F_61 ( V_1 -> V_15 , L_65 ) ;
}
if ( ! V_78 ) {
unsigned int V_220 ;
F_75 ( V_1 -> V_3 , V_36 ) ;
if ( ! V_36 -> V_38 ) {
V_28 -> V_207 = true ;
F_59 ( & V_28 -> V_158 , V_36 -> V_159 , 1 ,
V_215 ) ;
}
if ( V_28 -> V_207 ) {
if ( ! F_60 ( & V_28 -> V_158 ) ) {
F_61 ( V_1 -> V_15 , L_50 ) ;
F_62 ( & V_28 -> V_158 ) ;
V_60 = - V_208 ;
V_94 = true ;
goto V_162;
}
V_36 -> V_38 = V_28 -> V_158 . V_163 ;
V_220 = V_36 -> V_52 ;
V_28 -> V_39 = 0x0 ;
V_94 = F_36 ( V_1 , V_36 , V_16 ,
V_92 ) ;
V_220 = V_36 -> V_52 -
V_220 ;
V_28 -> V_158 . V_164 = V_220 ;
F_62 ( & V_28 -> V_158 ) ;
} else {
V_94 = F_36 ( V_1 , V_36 ,
V_16 , V_92 ) ;
}
F_17 ( V_1 -> V_15 , L_66 , V_94 ? L_67 : L_5 ) ;
}
}
V_162:
V_36 -> V_52 += V_214 ;
V_28 -> V_39 += V_214 ;
if ( V_94 ) {
if ( V_28 -> V_207 )
V_28 -> V_207 = false ;
if ( V_36 -> V_60 == - V_69 )
V_36 -> V_60 = V_60 ;
F_30 ( V_1 , V_36 , V_40 , V_188 ) ;
}
}
static int F_83 (
struct V_1 * V_1 ,
struct V_27 * V_28 ,
int V_26 )
{
int V_221 = 0 ;
int V_222 ;
int V_223 , V_16 ;
struct V_5 * V_40 = NULL ;
struct V_75 * V_76 = NULL ;
T_4 V_224 ;
T_4 V_225 ;
struct V_36 * V_36 = F_15 ( V_28 ) ;
if ( V_28 -> type == V_44 ) {
V_76 = & V_1 -> V_226 ;
V_40 = V_1 -> V_181 ;
goto V_227;
}
V_222 = 4096 ;
V_223 = - 1 ;
for ( V_16 = 1 , V_40 = V_1 -> V_96 + 1 ;
V_16 < V_1 -> V_228 ;
V_16 ++ , V_40 ++ ) {
int V_229 ;
if ( F_13 ( V_40 , V_26 ) != NULL )
continue;
if ( V_40 == V_1 -> V_230 )
continue;
if ( V_26 )
V_229 = V_40 -> V_123 ;
else
V_229 = V_40 -> V_154 ;
V_229 -= ( V_28 -> V_104 * V_28 -> V_124 ) ;
if ( V_229 >= 0 && V_222 > V_229 ) {
V_40 = V_1 -> V_96 + V_16 ;
V_224 = F_54 ( V_36 -> V_66 , V_28 -> V_16 , ! V_26 ) ;
V_225 = ( F_71 ( V_40 -> V_8 , V_152 )
>> 4 ) & 0x3 ;
if ( ! V_26 && ( V_28 -> type == V_70 ) &&
V_224 && ( V_225 == V_48 ) )
continue;
V_222 = V_229 ;
V_223 = V_16 ;
}
}
if ( V_223 < 0 && V_28 -> type == V_70 ) {
V_40 = V_1 -> V_230 ;
if ( V_26 )
V_76 = & V_1 -> V_173 ;
else
V_76 = & V_1 -> V_174 ;
if ( V_28 -> V_66 )
V_28 -> V_120 =
( V_231 == V_28 -> V_66 -> V_140 ) ? 8 : 4 ;
goto V_227;
} else if ( V_223 < 0 ) {
return - V_232 ;
}
V_221 = 1 ;
V_28 -> V_84 = 0 ;
V_40 = V_1 -> V_96 + V_223 ;
F_17 ( V_1 -> V_15 , L_68 , V_28 , V_223 ) ;
V_227:
if ( V_76 ) {
V_221 = F_31 ( V_76 ) ;
F_84 ( & V_28 -> V_85 , V_76 ) ;
V_28 -> V_84 = 1 ;
}
V_28 -> V_40 = V_40 ;
V_28 -> V_73 -> V_83 = V_28 ;
if ( V_221 )
F_14 ( V_1 , V_26 , V_28 ) ;
return 0 ;
}
static int F_85 (
struct V_2 * V_3 ,
struct V_36 * V_36 ,
T_7 V_233 )
{
unsigned long V_234 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_235 * V_73 = V_36 -> V_6 ;
struct V_27 * V_28 ;
struct V_236 * V_237 = & V_73 -> V_238 ;
int V_239 ;
unsigned V_118 ;
unsigned V_240 ;
if ( ! F_86 ( V_1 ) || ! V_1 -> V_241 )
return - V_242 ;
F_87 ( & V_1 -> V_61 , V_234 ) ;
V_239 = F_88 ( V_3 , V_36 ) ;
V_28 = V_239 ? NULL : V_73 -> V_83 ;
if ( V_28 )
V_36 -> V_83 = V_28 ;
F_89 ( & V_1 -> V_61 , V_234 ) ;
if ( V_28 || V_239 )
return V_239 ;
V_28 = F_90 ( sizeof *V_28 , V_233 ) ;
if ( ! V_28 ) {
F_87 ( & V_1 -> V_61 , V_234 ) ;
F_24 ( V_3 , V_36 ) ;
F_89 ( & V_1 -> V_61 , V_234 ) ;
return - V_243 ;
}
V_28 -> V_73 = V_73 ;
V_28 -> V_66 = V_36 -> V_66 ;
F_91 ( & V_28 -> V_85 ) ;
V_28 -> V_68 = 1 ;
V_28 -> V_104 = F_92 ( V_237 ) ;
V_28 -> type = F_93 ( V_237 ) ;
V_28 -> V_124 = 1 + ( ( V_28 -> V_104 >> 11 ) & 0x03 ) ;
if ( V_28 -> V_124 > 1 ) {
int V_244 = ( V_28 -> type == V_48 ) ;
if ( V_244 )
V_244 = ( F_23 ( V_36 -> V_41 ) && V_1 -> V_245 )
|| ( F_72 ( V_36 -> V_41 ) && V_1 -> V_246 ) ;
if ( ! V_244 ) {
V_239 = - V_247 ;
goto V_94;
}
V_28 -> V_104 &= 0x7ff ;
}
V_28 -> V_16 = F_94 ( V_237 ) ;
V_28 -> V_113 = ( T_4 ) F_16 ( V_36 -> V_41 ) ;
V_118 = ( V_28 -> type << 4 ) | V_28 -> V_16 ;
switch ( V_36 -> V_66 -> V_140 ) {
case V_248 :
V_118 |= 0xc0 ;
break;
case V_249 :
V_118 |= 0x80 ;
break;
default:
V_118 |= 0x40 ;
}
V_28 -> V_118 = V_118 ;
switch ( V_28 -> type ) {
case V_54 :
if ( V_36 -> V_66 -> V_140 <= V_249 ) {
V_240 = F_95 ( T_4 , V_237 -> V_250 , 1 ) ;
break;
}
case V_48 :
V_240 = F_63 ( T_4 , V_237 -> V_250 , 16 ) ;
break;
default:
V_240 = 0 ;
}
V_28 -> V_120 = V_240 ;
if ( V_1 -> V_112 ) {
struct V_251 * V_252 = V_36 -> V_66 -> V_252 ;
if ( V_252 != V_3 -> V_253 . V_254 ) {
V_28 -> V_114 = ( T_4 ) V_252 -> V_255 ;
if ( V_36 -> V_66 -> V_256 ) {
V_28 -> V_115 = ( T_4 ) V_36 -> V_66 -> V_257 ;
if ( V_36 -> V_66 -> V_256 -> V_258 )
V_28 -> V_114 =
( T_4 ) V_36 -> V_66 -> V_256 -> V_258 -> V_255 ;
if ( V_36 -> V_66 -> V_256 -> V_259 )
V_28 -> V_114 |= 0x80 ;
}
}
}
F_87 ( & V_1 -> V_61 , V_234 ) ;
if ( V_73 -> V_83 || ! F_15 ( V_28 ) ) {
F_33 ( V_28 ) ;
V_28 = NULL ;
V_239 = 0 ;
} else
V_239 = F_83 ( V_1 , V_28 ,
V_237 -> V_260 & V_261 ) ;
if ( V_239 == 0 ) {
V_36 -> V_83 = V_28 ;
}
F_89 ( & V_1 -> V_61 , V_234 ) ;
V_94:
if ( V_239 != 0 ) {
F_87 ( & V_1 -> V_61 , V_234 ) ;
F_24 ( V_3 , V_36 ) ;
F_89 ( & V_1 -> V_61 , V_234 ) ;
F_33 ( V_28 ) ;
}
return V_239 ;
}
static int F_96 ( struct V_36 * V_36 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_28 -> V_40 ;
struct V_1 * V_1 = V_6 -> V_1 ;
void T_1 * V_7 = V_6 -> V_8 ;
unsigned V_262 = V_6 -> V_16 ;
void T_1 * V_8 = V_6 -> V_1 -> V_35 ;
int V_26 = F_23 ( V_36 -> V_41 ) ;
int V_60 = 0 ;
T_2 V_9 ;
F_52 ( V_8 , V_262 ) ;
if ( F_53 () ) {
struct V_126 * V_78 ;
V_78 = V_26 ? V_6 -> V_80 : V_6 -> V_59 ;
if ( V_78 ) {
V_60 = V_6 -> V_1 -> V_77 -> V_177 ( V_78 ) ;
F_17 ( V_1 -> V_15 ,
L_69 ,
V_26 ? 'R' : 'T' , V_6 -> V_16 ,
V_36 , V_60 ) ;
V_36 -> V_52 += V_78 -> V_132 ;
}
}
if ( V_6 -> V_16 && V_26 ) {
V_9 = F_35 ( V_6 , 0 ) ;
} else if ( V_6 -> V_16 ) {
F_2 ( V_6 ) ;
V_9 = F_3 ( V_7 , V_11 ) ;
V_9 &= ~ ( V_130
| V_24
| V_148
| V_147
| V_149
| V_14 ) ;
F_4 ( V_7 , V_11 , V_9 ) ;
F_4 ( V_7 , V_11 , V_9 ) ;
V_9 = F_3 ( V_7 , V_11 ) ;
} else {
F_6 ( V_6 ) ;
}
if ( V_60 == 0 )
F_30 ( V_6 -> V_1 , V_36 , V_6 , V_26 ) ;
return V_60 ;
}
static int F_97 ( struct V_2 * V_3 , struct V_36 * V_36 , int V_60 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_27 * V_28 ;
unsigned long V_234 ;
int V_26 = F_23 ( V_36 -> V_41 ) ;
int V_239 ;
F_17 ( V_1 -> V_15 , L_70 , V_36 ,
F_16 ( V_36 -> V_41 ) ,
F_22 ( V_36 -> V_41 ) ,
V_26 ? L_3 : L_4 ) ;
F_87 ( & V_1 -> V_61 , V_234 ) ;
V_239 = F_98 ( V_3 , V_36 , V_60 ) ;
if ( V_239 )
goto V_94;
V_28 = V_36 -> V_83 ;
if ( ! V_28 )
goto V_94;
if ( ! V_28 -> V_68
|| V_36 -> V_74 . V_86 != & V_28 -> V_73 -> V_74
|| F_13 ( V_28 -> V_40 , V_26 ) != V_28 ) {
int V_67 = V_28 -> V_68 ;
V_28 -> V_68 = 0 ;
F_21 ( V_1 , V_36 , 0 ) ;
V_28 -> V_68 = V_67 ;
if ( V_67 && F_31 ( & V_28 -> V_73 -> V_74 ) ) {
V_28 -> V_73 -> V_83 = NULL ;
F_32 ( & V_28 -> V_85 ) ;
F_33 ( V_28 ) ;
}
} else
V_239 = F_96 ( V_36 , V_28 ) ;
V_94:
F_89 ( & V_1 -> V_61 , V_234 ) ;
return V_239 ;
}
static void
F_99 ( struct V_2 * V_3 , struct V_235 * V_73 )
{
T_4 V_26 = V_73 -> V_238 . V_260 & V_188 ;
unsigned long V_234 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_27 * V_28 ;
struct V_36 * V_36 ;
F_87 ( & V_1 -> V_61 , V_234 ) ;
V_28 = V_73 -> V_83 ;
if ( V_28 == NULL )
goto exit;
V_28 -> V_68 = 0 ;
if ( F_13 ( V_28 -> V_40 , V_26 ) == V_28 ) {
V_36 = F_15 ( V_28 ) ;
if ( ! V_36 -> V_263 )
V_36 -> V_60 = - V_264 ;
F_96 ( V_36 , V_28 ) ;
while ( ! F_31 ( & V_73 -> V_74 ) ) {
V_36 = F_15 ( V_28 ) ;
V_36 -> V_60 = - V_264 ;
F_30 ( V_1 , V_36 , V_28 -> V_40 , V_26 ) ;
}
} else {
while ( ! F_31 ( & V_73 -> V_74 ) )
F_21 ( V_1 , F_15 ( V_28 ) , - V_264 ) ;
V_73 -> V_83 = NULL ;
F_32 ( & V_28 -> V_85 ) ;
F_33 ( V_28 ) ;
}
exit:
F_89 ( & V_1 -> V_61 , V_234 ) ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_3 ( V_1 -> V_35 , V_55 ) ;
}
static int F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_3 -> V_265 = V_266 ;
V_1 -> V_267 = 0 ;
return 0 ;
}
static void F_102 ( struct V_2 * V_3 )
{
F_103 ( F_1 ( V_3 ) ) ;
V_3 -> V_265 = V_268 ;
}
static int F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_4 V_269 ;
F_105 ( V_1 , true ) ;
if ( ! F_86 ( V_1 ) )
return 0 ;
switch ( V_1 -> V_270 -> V_271 -> V_265 ) {
case V_272 :
return 0 ;
case V_273 :
V_269 = F_71 ( V_1 -> V_35 , V_274 ) ;
if ( ( V_269 & V_275 ) == V_275 )
V_1 -> V_270 -> V_271 -> V_265 = V_276 ;
break;
default:
break;
}
if ( V_1 -> V_241 ) {
F_41 ( L_71 ,
F_106 ( V_1 -> V_270 -> V_271 -> V_265 ) ) ;
return - V_277 ;
} else
return 0 ;
}
static int F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_278 &&
V_1 -> V_278 -> V_279 )
F_108 ( V_1 , false ) ;
return 0 ;
}
static void F_109 ( struct V_36 * V_36 )
{
enum V_280 V_281 ;
struct V_282 * V_283 ;
V_185 V_51 ;
if ( ! ( V_36 -> V_105 & V_284 ) )
return;
V_281 = F_110 ( V_36 ) ? V_285 : V_286 ;
V_283 = F_111 ( V_36 -> V_38 , struct V_282 ,
V_287 ) ;
if ( V_281 == V_285 ) {
if ( F_37 ( V_36 -> V_41 ) )
V_51 = V_36 -> V_53 ;
else
V_51 = V_36 -> V_52 ;
memcpy ( V_283 -> V_288 , V_283 -> V_287 , V_51 ) ;
}
V_36 -> V_38 = V_283 -> V_288 ;
F_33 ( V_283 -> V_289 ) ;
V_36 -> V_105 &= ~ V_284 ;
}
static int F_112 ( struct V_36 * V_36 , T_7 V_233 )
{
enum V_280 V_281 ;
struct V_282 * V_283 ;
void * V_289 ;
V_185 V_290 ;
if ( V_36 -> V_291 || V_36 -> V_159 ||
V_36 -> V_53 == 0 ||
! ( ( V_292 ) V_36 -> V_38 & ( V_293 - 1 ) ) )
return 0 ;
V_281 = F_110 ( V_36 ) ? V_285 : V_286 ;
V_290 = V_36 -> V_53 +
sizeof( struct V_282 ) + V_293 - 1 ;
V_289 = F_113 ( V_290 , V_233 ) ;
if ( ! V_289 )
return - V_243 ;
V_283 = F_114 ( V_289 , V_293 ) ;
V_283 -> V_289 = V_289 ;
V_283 -> V_288 = V_36 -> V_38 ;
if ( V_281 == V_286 )
memcpy ( V_283 -> V_287 , V_36 -> V_38 ,
V_36 -> V_53 ) ;
V_36 -> V_38 = V_283 -> V_287 ;
V_36 -> V_105 |= V_284 ;
return 0 ;
}
static int F_115 ( struct V_2 * V_3 , struct V_36 * V_36 ,
T_7 V_233 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_239 ;
if ( V_1 -> V_294 < V_295 )
return F_116 ( V_3 , V_36 , V_233 ) ;
V_239 = F_112 ( V_36 , V_233 ) ;
if ( V_239 )
return V_239 ;
V_239 = F_116 ( V_3 , V_36 , V_233 ) ;
if ( V_239 )
F_109 ( V_36 ) ;
return V_239 ;
}
static void F_117 ( struct V_2 * V_3 , struct V_36 * V_36 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_75 ( V_3 , V_36 ) ;
if ( V_1 -> V_294 < V_295 )
return;
F_109 ( V_36 ) ;
}
int F_118 ( struct V_1 * V_1 )
{
struct V_296 * V_66 = V_1 -> V_15 ;
V_1 -> V_3 = F_119 ( & V_297 , V_66 , F_120 ( V_66 ) ) ;
if ( ! V_1 -> V_3 )
return - V_208 ;
* V_1 -> V_3 -> V_4 = ( unsigned long ) V_1 ;
V_1 -> V_3 -> V_253 . V_298 = 1 ;
V_1 -> V_3 -> V_299 = 1 ;
V_1 -> V_3 -> V_300 = 1 ;
return 0 ;
}
void F_121 ( struct V_1 * V_1 )
{
if ( V_1 -> V_301 == V_302 )
return;
F_122 ( V_1 -> V_3 ) ;
}
void F_123 ( struct V_1 * V_1 )
{
F_124 ( V_1 -> V_3 ) ;
}
int F_125 ( struct V_1 * V_1 , int V_303 )
{
int V_239 ;
struct V_2 * V_3 = V_1 -> V_3 ;
F_126 ( V_1 ) ;
V_1 -> V_270 -> V_271 -> V_304 = 1 ;
V_1 -> V_270 -> V_271 -> V_265 = V_305 ;
F_127 ( V_1 -> V_270 -> V_271 , & V_3 -> V_253 ) ;
V_3 -> V_253 . V_306 = 1 ;
V_1 -> V_270 -> V_271 -> V_307 = & V_3 -> V_253 ;
V_3 -> V_303 = 2 * ( V_303 ? : 250 ) ;
V_239 = F_128 ( V_3 , 0 , 0 ) ;
if ( V_239 < 0 )
return V_239 ;
F_129 ( V_3 -> V_253 . V_15 ) ;
return 0 ;
}
void F_130 ( struct V_1 * V_1 )
{
F_131 ( V_1 -> V_3 ) ;
}
void F_132 ( struct V_1 * V_1 )
{
F_126 ( V_1 ) ;
if ( V_1 -> V_3 -> V_308 )
F_133 ( V_1 -> V_3 ) ;
else
F_131 ( V_1 -> V_3 ) ;
}
