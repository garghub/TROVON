static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
int V_6 = 0 ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_4 = & V_2 -> V_7 [ V_6 ] ;
V_4 -> V_2 = V_2 ;
V_4 -> V_8 = & V_2 -> V_9 [ V_6 ] ;
V_4 -> V_8 -> V_10 =
( V_11 << V_12 )
| V_13 ;
V_4 -> V_8 -> V_14 = V_15 ;
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ 0 ] ) ;
if ( V_6 ) {
V_5 |= V_17
| ( V_18
<< V_19 ) ;
} else {
V_5 |= V_20
| ( V_18
<< V_21 ) ;
}
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ 0 ] ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ 0 ] ) ;
V_5 |= V_22 | V_23 ;
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ 0 ] ) ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 ;
}
static int F_5 ( struct V_1 * V_2 , int V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_35 , V_36 ;
int V_6 , V_37 ;
int V_38 = 0 ;
T_1 V_39 ;
T_1 V_40 ;
V_34 = & V_2 -> V_9 [ V_28 ] ;
V_37 = V_28 % 2 ;
V_32 = V_30 -> V_41 ;
V_35 = V_30 -> V_42 . V_43 ;
for ( V_6 = 0 ; V_6 < V_30 -> V_44 ; V_6 ++ ) {
if ( V_32 -> V_45 & V_46 ) {
F_6 ( & V_2 -> V_47 -> V_47 , L_1 ,
V_2 -> V_7 [ V_28 ] . V_48 ) ;
return 1 ;
}
V_39 = V_32 -> V_45 & V_49 ;
if ( ! V_39 ) {
V_36 =
( V_32 -> V_45 & V_50 )
>> V_51 ;
V_35 -= V_36 ;
if ( V_36 ) {
if ( V_37 ) {
F_6 ( & V_2 -> V_47 -> V_47 ,
L_2 ) ;
V_38 = - V_52 ;
break;
} else
break;
}
} else {
F_7 ( & V_2 -> V_47 -> V_47 ,
L_3 ,
V_28 >> 1 , V_37 ? L_4 : L_5 ,
V_39 ) ;
if ( V_39 & V_53 ) {
V_34 -> V_54 &= ~ V_39 ;
V_38 = - V_55 ;
} else if ( V_39 & V_56 ) {
V_38 = - V_52 ;
} else if ( V_39 & V_57 ) {
V_38 = - V_58 ;
}
}
if ( V_6 != V_30 -> V_44 - 1 )
V_32 = (struct V_31 * ) V_32 -> V_59 ;
}
if ( V_38 )
return V_38 ;
if ( V_37 == V_27 )
V_40 = 1 << V_30 -> V_4 -> V_60 ;
else
V_40 = 1 << ( 16 + V_30 -> V_4 -> V_60 ) ;
while ( ( V_34 -> V_61 == V_32 -> V_62 ) ) {
if ( V_32 -> V_63 == V_15 ) {
while ( F_2 ( & V_2 -> V_16 -> V_64 ) & V_40 )
F_8 ( 1 ) ;
break;
}
F_8 ( 1 ) ;
}
V_30 -> V_42 . V_35 = V_35 ;
return 0 ;
}
static void F_9 ( struct V_3 * V_4 , struct V_29 * V_42 , int V_65 )
__releases( &ep->udc->lock
static int F_10 ( struct V_3 * V_4 , struct V_29 * V_42 )
{
struct V_1 * V_2 ;
struct V_33 * V_8 ;
T_1 V_40 , V_37 ;
T_1 V_66 , V_64 ;
unsigned int V_67 ;
int V_38 = 0 ;
V_2 = V_4 -> V_2 ;
V_37 = F_11 ( V_4 ) ;
V_8 = & ( V_2 -> V_9 [ V_4 -> V_60 * 2 + V_37 ] ) ;
V_40 = 1 << ( ( ( V_37 == V_27 ) ? 0 : 16 ) + V_4 -> V_60 ) ;
if ( ! ( F_12 ( & V_4 -> V_68 ) ) ) {
struct V_29 * V_69 ;
V_69 = F_13 ( V_4 -> V_68 . V_70 , struct V_29 , V_68 ) ;
V_69 -> V_71 -> V_63 =
V_42 -> V_41 -> V_62 & V_72 ;
F_14 () ;
if ( F_2 ( & V_2 -> V_16 -> V_73 ) & V_40 )
goto F_9;
V_67 = F_15 ( V_74 ) ;
while ( 1 ) {
V_66 = F_2 ( & V_2 -> V_16 -> V_66 ) ;
V_66 |= V_75 ;
F_3 ( V_66 , & V_2 -> V_16 -> V_66 ) ;
V_64 = F_2 ( & V_2 -> V_16 -> V_64 ) & V_40 ;
if ( F_2 ( & V_2 -> V_16 -> V_66 )
& V_75 )
break;
V_67 -- ;
if ( V_67 == 0 ) {
F_16 ( & V_2 -> V_47 -> V_47 ,
L_6 ) ;
V_38 = - V_76 ;
goto F_9;
}
F_8 ( V_77 ) ;
}
V_66 = F_2 ( & V_2 -> V_16 -> V_66 ) ;
V_66 &= V_78 ;
F_3 ( V_66 , & V_2 -> V_16 -> V_66 ) ;
if ( V_64 )
goto F_9;
}
V_8 -> V_14 = V_42 -> V_41 -> V_62
& V_72 ;
V_8 -> V_54 &= ~ ( V_46 | V_53 ) ;
F_14 () ;
F_3 ( V_40 , & V_2 -> V_16 -> V_73 ) ;
F_9:
return V_38 ;
}
static struct V_31 * F_17 ( struct V_29 * V_42 , unsigned * V_43 ,
T_2 * V_79 , int * V_80 )
{
struct V_31 * V_81 ;
struct V_1 * V_2 ;
struct V_33 * V_8 ;
T_1 V_82 , V_83 = 0 ;
if ( F_18 ( V_42 -> V_4 -> V_4 . V_84 ) ) {
V_8 = V_42 -> V_4 -> V_8 ;
V_83 = ( V_8 -> V_10 >> V_85 )
& 0x3 ;
* V_43 = F_19 ( V_42 -> V_42 . V_43 - V_42 -> V_42 . V_35 ,
( unsigned ) ( V_83 * V_42 -> V_4 -> V_4 . V_86 ) ) ;
} else
* V_43 = F_19 ( V_42 -> V_42 . V_43 - V_42 -> V_42 . V_35 ,
( unsigned ) V_87 ) ;
V_2 = V_42 -> V_4 -> V_2 ;
V_81 = F_20 ( V_2 -> V_88 , V_89 , V_79 ) ;
if ( V_81 == NULL )
return V_81 ;
V_81 -> V_62 = * V_79 ;
V_82 = ( T_1 ) ( V_42 -> V_42 . V_79 + V_42 -> V_42 . V_35 ) ;
V_81 -> V_90 = F_21 ( V_82 ) ;
V_82 &= ~ 0xFFF ;
V_81 -> V_91 = F_21 ( V_82 + 0x1000 ) ;
V_81 -> V_92 = F_21 ( V_82 + 0x2000 ) ;
V_81 -> V_93 = F_21 ( V_82 + 0x3000 ) ;
V_81 -> V_94 = F_21 ( V_82 + 0x4000 ) ;
V_42 -> V_42 . V_35 += * V_43 ;
if ( V_42 -> V_42 . V_95 ) {
if ( * V_43 == 0 || ( * V_43 % V_42 -> V_4 -> V_4 . V_86 ) != 0 )
* V_80 = 1 ;
else
* V_80 = 0 ;
} else if ( V_42 -> V_42 . V_43 == V_42 -> V_42 . V_35 )
* V_80 = 1 ;
else
* V_80 = 0 ;
V_82 = ( ( * V_43 << V_51 ) | V_46 ) ;
if ( * V_80 && ! V_42 -> V_42 . V_96 )
V_82 |= V_97 ;
V_82 |= V_83 << 10 ;
V_81 -> V_45 = V_82 ;
F_22 () ;
return V_81 ;
}
static int F_23 ( struct V_29 * V_42 )
{
unsigned V_98 ;
int V_80 , V_99 = 1 ;
struct V_31 * V_81 , * V_100 = NULL ;
T_2 V_79 ;
do {
V_81 = F_17 ( V_42 , & V_98 , & V_79 , & V_80 ) ;
if ( V_81 == NULL )
return - V_101 ;
if ( V_99 ) {
V_99 = 0 ;
V_42 -> V_41 = V_81 ;
} else {
V_100 -> V_63 = V_79 ;
V_100 -> V_59 = V_81 ;
}
V_100 = V_81 ;
V_42 -> V_44 ++ ;
} while ( ! V_80 );
V_81 -> V_63 = V_102 ;
V_42 -> V_71 = V_81 ;
return 0 ;
}
static int F_24 ( struct V_103 * V_104 ,
const struct V_105 * V_84 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_33 * V_8 ;
T_3 V_106 = 0 ;
T_1 V_40 , V_5 , V_37 ;
const unsigned char V_107 = 1 ;
unsigned char V_108 , V_83 ;
unsigned long V_109 ;
V_4 = F_25 ( V_104 , struct V_3 , V_4 ) ;
V_2 = V_4 -> V_2 ;
if ( ! V_104 || ! V_84
|| V_84 -> V_110 != V_111 )
return - V_112 ;
if ( ! V_2 -> V_113 || V_2 -> V_114 . V_115 == V_116 )
return - V_117 ;
V_37 = F_11 ( V_4 ) ;
V_106 = F_26 ( V_84 ) ;
V_40 = 1 << ( ( V_37 == V_27 ? 0 : 16 ) + V_4 -> V_60 ) ;
if ( ( F_2 ( & V_2 -> V_16 -> V_73 ) & V_40 )
|| ( F_2 ( & V_2 -> V_16 -> V_64 ) & V_40 ) ) {
F_7 ( & V_2 -> V_47 -> V_47 ,
L_7
L_8 ,
( unsigned ) V_4 -> V_60 , V_37 ? L_4 : L_5 ,
( unsigned ) F_2 ( & V_2 -> V_16 -> V_73 ) ,
( unsigned ) F_2 ( & V_2 -> V_16 -> V_64 ) ,
( unsigned ) V_40 ) ;
goto V_118;
}
V_108 = 0 ;
V_83 = 0 ;
switch ( V_84 -> V_119 & V_120 ) {
case V_121 :
case V_122 :
break;
case V_18 :
V_108 = 1 ;
break;
case V_123 :
V_83 = F_27 ( V_84 ) ;
if ( V_83 > 3 )
goto V_118;
break;
default:
goto V_118;
}
F_28 ( & V_2 -> V_124 , V_109 ) ;
V_8 = V_4 -> V_8 ;
V_8 -> V_10 = ( V_106 << V_12 )
| ( V_83 << V_85 )
| ( V_107 ? V_125 : 0 )
| ( V_108 ? V_13 : 0 ) ;
V_8 -> V_14 = 1 ;
V_8 -> V_54 = 0 ;
V_4 -> V_4 . V_86 = V_106 ;
V_4 -> V_4 . V_84 = V_84 ;
V_4 -> V_126 = 0 ;
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
if ( V_37 == V_127 ) {
V_5 &= ~ V_128 ;
V_5 |= V_17 | V_129
| ( ( V_84 -> V_119 & V_120 )
<< V_19 ) ;
} else {
V_5 &= ~ V_130 ;
V_5 |= V_20 | V_131
| ( ( V_84 -> V_119 & V_120 )
<< V_21 ) ;
}
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
if ( ( V_5 & V_20 ) == 0 ) {
V_5 |= ( V_121
<< V_21 ) ;
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
}
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
if ( ( V_5 & V_17 ) == 0 ) {
V_5 |= ( V_121
<< V_19 ) ;
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
}
F_29 ( & V_2 -> V_124 , V_109 ) ;
return 0 ;
V_118:
return - V_112 ;
}
static int F_30 ( struct V_103 * V_104 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_33 * V_8 ;
T_1 V_5 , V_37 ;
unsigned long V_109 ;
V_4 = F_25 ( V_104 , struct V_3 , V_4 ) ;
if ( ( V_104 == NULL ) || ! V_4 -> V_4 . V_84 )
return - V_112 ;
V_2 = V_4 -> V_2 ;
V_8 = V_4 -> V_8 ;
F_28 ( & V_2 -> V_124 , V_109 ) ;
V_37 = F_11 ( V_4 ) ;
V_8 -> V_10 = 0 ;
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
V_5 &= ~ ( ( V_37 == V_127 )
? ( V_17 | V_132 )
: ( V_20 | V_133 ) ) ;
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
F_31 ( V_4 , - V_117 ) ;
V_4 -> V_4 . V_84 = NULL ;
V_4 -> V_126 = 1 ;
F_29 ( & V_2 -> V_124 , V_109 ) ;
return 0 ;
}
static struct V_134 *
F_32 ( struct V_103 * V_104 , T_4 V_135 )
{
struct V_29 * V_42 = NULL ;
V_42 = F_33 ( sizeof *V_42 , V_135 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_42 . V_79 = V_136 ;
F_34 ( & V_42 -> V_68 ) ;
return & V_42 -> V_42 ;
}
static void F_35 ( struct V_103 * V_104 , struct V_134 * V_137 )
{
struct V_29 * V_42 = NULL ;
V_42 = F_25 ( V_137 , struct V_29 , V_42 ) ;
if ( V_137 )
F_36 ( V_42 ) ;
}
static void F_37 ( struct V_103 * V_104 )
{
struct V_1 * V_2 ;
T_1 V_40 , V_37 ;
struct V_3 * V_4 ;
unsigned int V_67 ;
if ( ! V_104 )
return;
V_4 = F_25 ( V_104 , struct V_3 , V_4 ) ;
if ( ! V_4 -> V_4 . V_84 )
return;
V_2 = V_4 -> V_2 ;
V_37 = F_11 ( V_4 ) ;
if ( V_4 -> V_60 == 0 )
V_40 = ( 1 << 16 ) | 1 ;
else if ( V_37 == V_27 )
V_40 = 1 << V_4 -> V_60 ;
else
V_40 = 1 << ( 16 + V_4 -> V_60 ) ;
V_67 = F_15 ( V_138 ) ;
do {
unsigned int V_139 ;
if ( V_67 == 0 ) {
F_16 ( & V_2 -> V_47 -> V_47 ,
L_9 ,
( unsigned ) F_2 ( & V_2 -> V_16 -> V_64 ) ,
( unsigned ) V_40 ) ;
return;
}
F_3 ( V_40 , & V_2 -> V_16 -> V_140 ) ;
V_139 = F_15 ( V_141 ) ;
while ( F_2 ( & V_2 -> V_16 -> V_140 ) ) {
if ( V_139 == 0 ) {
F_16 ( & V_2 -> V_47 -> V_47 ,
L_10
L_11 ,
( unsigned ) F_2 ( & V_2 -> V_16 -> V_140 ) ,
( unsigned ) V_40 ) ;
return;
}
V_139 -- ;
F_8 ( V_77 ) ;
}
V_67 -- ;
} while ( F_2 ( & V_2 -> V_16 -> V_64 ) & V_40 );
}
static int
F_38 ( struct V_103 * V_104 , struct V_134 * V_137 , T_4 V_135 )
{
struct V_3 * V_4 = F_25 ( V_104 , struct V_3 , V_4 ) ;
struct V_29 * V_42 = F_25 ( V_137 , struct V_29 , V_42 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_109 ;
int V_38 ;
if ( ! V_137 || ! V_42 -> V_42 . V_142 || ! V_42 -> V_42 . V_143
|| ! F_12 ( & V_42 -> V_68 ) ) {
F_16 ( & V_2 -> V_47 -> V_47 , L_12 , V_144 ) ;
return - V_112 ;
}
if ( F_39 ( ! V_104 || ! V_4 -> V_4 . V_84 ) ) {
F_16 ( & V_2 -> V_47 -> V_47 , L_13 , V_144 ) ;
return - V_112 ;
}
V_2 = V_4 -> V_2 ;
if ( ! V_2 -> V_113 || V_2 -> V_114 . V_115 == V_116 )
return - V_117 ;
V_42 -> V_4 = V_4 ;
V_38 = F_40 ( & V_2 -> V_114 , V_137 , F_11 ( V_4 ) ) ;
if ( V_38 )
return V_38 ;
V_42 -> V_42 . V_65 = - V_145 ;
V_42 -> V_42 . V_35 = 0 ;
V_42 -> V_44 = 0 ;
F_28 ( & V_2 -> V_124 , V_109 ) ;
if ( ! F_23 ( V_42 ) ) {
V_38 = F_10 ( V_4 , V_42 ) ;
if ( V_38 ) {
F_29 ( & V_2 -> V_124 , V_109 ) ;
F_16 ( & V_2 -> V_47 -> V_47 , L_14 ) ;
goto V_146;
}
} else {
F_29 ( & V_2 -> V_124 , V_109 ) ;
F_16 ( & V_2 -> V_47 -> V_47 , L_15 ) ;
V_38 = - V_101 ;
goto V_146;
}
if ( V_4 -> V_60 == 0 )
V_2 -> V_24 = V_147 ;
F_41 ( & V_42 -> V_68 , & V_4 -> V_68 ) ;
F_29 ( & V_2 -> V_124 , V_109 ) ;
return 0 ;
V_146:
F_42 ( & V_2 -> V_114 , V_137 , F_11 ( V_4 ) ) ;
return V_38 ;
}
static void F_43 ( struct V_3 * V_4 , struct V_29 * V_42 )
{
struct V_33 * V_8 = V_4 -> V_8 ;
T_1 V_40 ;
V_8 -> V_14 = V_42 -> V_41 -> V_62
& V_72 ;
V_8 -> V_54 &= ~ ( V_46 | V_53 ) ;
F_14 () ;
V_40 = 1 << ( ( ( F_11 ( V_4 ) == V_27 ) ? 0 : 16 ) + V_4 -> V_60 ) ;
F_3 ( V_40 , & V_4 -> V_2 -> V_16 -> V_73 ) ;
}
static int F_44 ( struct V_103 * V_104 , struct V_134 * V_137 )
{
struct V_3 * V_4 = F_25 ( V_104 , struct V_3 , V_4 ) ;
struct V_29 * V_42 ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_109 ;
int V_126 , V_148 = 0 ;
T_1 V_5 ;
if ( ! V_104 || ! V_137 )
return - V_112 ;
F_28 ( & V_4 -> V_2 -> V_124 , V_109 ) ;
V_126 = V_4 -> V_126 ;
V_4 -> V_126 = 1 ;
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
if ( F_11 ( V_4 ) == V_127 )
V_5 &= ~ V_17 ;
else
V_5 &= ~ V_20 ;
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
F_45 (req, &ep->queue, queue) {
if ( & V_42 -> V_42 == V_137 )
break;
}
if ( & V_42 -> V_42 != V_137 ) {
V_148 = - V_112 ;
goto V_149;
}
if ( V_4 -> V_68 . V_150 == & V_42 -> V_68 ) {
V_137 -> V_65 = - V_151 ;
F_37 ( V_104 ) ;
if ( V_42 -> V_68 . V_150 != & V_4 -> V_68 ) {
struct V_29 * V_152 ;
V_152 = F_13 ( V_42 -> V_68 . V_150 ,
struct V_29 , V_68 ) ;
F_43 ( V_4 , V_152 ) ;
} else {
struct V_33 * V_153 ;
V_153 = V_4 -> V_8 ;
V_153 -> V_14 = 1 ;
V_153 -> V_54 = 0 ;
}
} else {
struct V_29 * V_154 ;
V_154 = F_13 ( V_42 -> V_68 . V_70 , struct V_29 , V_68 ) ;
F_3 ( F_2 ( & V_42 -> V_71 -> V_63 ) ,
& V_154 -> V_71 -> V_63 ) ;
}
F_9 ( V_4 , V_42 , - V_151 ) ;
V_149:
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
if ( F_11 ( V_4 ) == V_127 )
V_5 |= V_17 ;
else
V_5 |= V_20 ;
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ V_4 -> V_60 ] ) ;
V_4 -> V_126 = V_126 ;
F_29 ( & V_4 -> V_2 -> V_124 , V_109 ) ;
return V_148 ;
}
static void F_46 ( struct V_1 * V_2 , T_5 V_60 , T_5 V_37 , int V_155 )
{
T_1 V_5 ;
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ V_60 ] ) ;
if ( V_155 ) {
if ( V_37 == V_127 )
V_5 |= V_23 ;
else
V_5 |= V_22 ;
} else {
if ( V_37 == V_127 ) {
V_5 &= ~ V_23 ;
V_5 |= V_129 ;
} else {
V_5 &= ~ V_22 ;
V_5 |= V_131 ;
}
}
F_3 ( V_5 , & V_2 -> V_16 -> V_5 [ V_60 ] ) ;
}
static int F_47 ( struct V_1 * V_2 , T_5 V_60 , T_5 V_37 )
{
T_1 V_5 ;
V_5 = F_2 ( & V_2 -> V_16 -> V_5 [ V_60 ] ) ;
if ( V_37 == V_27 )
return ( V_5 & V_22 ) ? 1 : 0 ;
else
return ( V_5 & V_23 ) ? 1 : 0 ;
}
static int F_48 ( struct V_103 * V_104 , int V_156 , int V_157 )
{
struct V_3 * V_4 ;
unsigned long V_109 = 0 ;
int V_65 = 0 ;
struct V_1 * V_2 ;
V_4 = F_25 ( V_104 , struct V_3 , V_4 ) ;
V_2 = V_4 -> V_2 ;
if ( ! V_104 || ! V_4 -> V_4 . V_84 ) {
V_65 = - V_112 ;
goto V_149;
}
if ( V_4 -> V_4 . V_84 -> V_119 == V_123 ) {
V_65 = - V_158 ;
goto V_149;
}
if ( V_156 && ( F_11 ( V_4 ) == V_127 ) && ! F_12 ( & V_4 -> V_68 ) ) {
V_65 = - V_159 ;
goto V_149;
}
F_28 ( & V_4 -> V_2 -> V_124 , V_109 ) ;
F_46 ( V_2 , V_4 -> V_60 , F_11 ( V_4 ) , V_156 ) ;
if ( V_156 && V_157 )
V_4 -> V_157 = 1 ;
else if ( ! V_156 )
V_4 -> V_157 = 0 ;
F_29 ( & V_4 -> V_2 -> V_124 , V_109 ) ;
if ( V_4 -> V_60 == 0 ) {
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 ;
}
V_149:
return V_65 ;
}
static int F_49 ( struct V_103 * V_104 , int V_156 )
{
return F_48 ( V_104 , V_156 , 0 ) ;
}
static int F_50 ( struct V_103 * V_104 )
{
return F_48 ( V_104 , 1 , 1 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
return F_52 ( V_2 -> V_160 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 -> V_160 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_1 V_161 ;
V_161 = F_2 ( & V_2 -> V_16 -> V_162 ) ;
V_161 &= ~ ( V_163 | V_164 |
V_165 | V_166 ) ;
F_3 ( V_161 , & V_2 -> V_16 -> V_162 ) ;
V_2 -> V_126 = 1 ;
V_161 = F_2 ( & V_2 -> V_16 -> V_66 ) ;
V_161 &= ~ V_167 ;
F_3 ( V_161 , & V_2 -> V_16 -> V_66 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_1 V_162 ;
V_162 = V_163 | V_164
| V_165
| V_166 | V_168 ;
F_3 ( V_162 , & V_2 -> V_16 -> V_162 ) ;
V_2 -> V_126 = 0 ;
F_3 ( V_167 , & V_2 -> V_16 -> V_66 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
unsigned int V_67 ;
T_1 V_161 , V_169 ;
V_161 = F_2 ( & V_2 -> V_16 -> V_66 ) ;
V_161 &= ~ V_167 ;
F_3 ( V_161 , & V_2 -> V_16 -> V_66 ) ;
F_3 ( V_170 , & V_2 -> V_16 -> V_66 ) ;
V_67 = F_15 ( V_171 ) ;
while ( F_2 ( & V_2 -> V_16 -> V_66 ) & V_170 ) {
if ( V_67 == 0 ) {
F_16 ( & V_2 -> V_47 -> V_47 ,
L_16 ) ;
return - V_172 ;
}
V_67 -- ;
F_8 ( V_77 ) ;
}
V_161 = F_2 ( & V_2 -> V_16 -> V_173 ) ;
V_161 |= V_174 ;
V_161 |= V_175 ;
F_3 ( V_161 , & V_2 -> V_16 -> V_173 ) ;
F_3 ( 0x0 , & V_2 -> V_16 -> V_176 ) ;
F_3 ( V_2 -> V_177 & V_178 ,
& V_2 -> V_16 -> V_179 ) ;
V_169 = F_2 ( & V_2 -> V_16 -> V_169 [ 0 ] ) ;
if ( F_2 ( & V_2 -> V_180 -> V_181 ) & V_182 )
V_169 &= ( ~ V_183 | ~ V_184 ) ;
if ( V_2 -> V_185 )
V_169 |= V_186 ;
else
V_169 &= ( ~ V_186 ) ;
F_3 ( V_169 , & V_2 -> V_16 -> V_169 [ 0 ] ) ;
V_161 = F_2 ( & V_2 -> V_16 -> V_5 [ 0 ] ) ;
V_161 &= ~ ( V_23 | V_22 ) ;
F_3 ( V_161 , & V_2 -> V_16 -> V_5 [ 0 ] ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_38 ;
if ( V_2 -> V_187 )
return 0 ;
F_6 ( & V_2 -> V_47 -> V_47 , L_17 ) ;
V_38 = F_51 ( V_2 ) ;
if ( V_38 )
return V_38 ;
if ( V_2 -> V_188 -> V_189 ) {
V_38 = V_2 -> V_188 -> V_189 ( V_2 -> V_190 ) ;
if ( V_38 ) {
F_16 ( & V_2 -> V_47 -> V_47 ,
L_18 , V_38 ) ;
F_53 ( V_2 ) ;
return V_38 ;
}
}
V_2 -> V_187 = 1 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_191 )
return F_58 ( V_2 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_187 ) {
F_6 ( & V_2 -> V_47 -> V_47 , L_19 ) ;
if ( V_2 -> V_188 -> V_192 )
V_2 -> V_188 -> V_192 ( V_2 -> V_190 ) ;
F_53 ( V_2 ) ;
V_2 -> V_187 = 0 ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_191 )
F_60 ( V_2 ) ;
}
static int F_62 ( struct V_193 * V_114 )
{
struct V_1 * V_2 ;
T_3 V_38 ;
if ( ! V_114 )
return - V_194 ;
V_2 = F_25 ( V_114 , struct V_1 , V_114 ) ;
V_38 = F_2 ( & V_2 -> V_16 -> V_195 ) & V_196 ;
return V_38 ;
}
static int F_63 ( struct V_193 * V_114 )
{
struct V_1 * V_2 = F_25 ( V_114 , struct V_1 , V_114 ) ;
T_1 V_169 ;
if ( ! V_2 -> V_197 )
return - V_198 ;
V_169 = F_2 ( & V_2 -> V_16 -> V_169 ) ;
if ( ! ( V_169 & V_199 ) )
return 0 ;
V_169 |= V_200 ;
F_3 ( V_169 , & V_2 -> V_16 -> V_169 [ 0 ] ) ;
return 0 ;
}
static int F_64 ( struct V_193 * V_114 , int V_201 )
{
struct V_1 * V_2 ;
unsigned long V_109 ;
int V_38 = 0 ;
V_2 = F_25 ( V_114 , struct V_1 , V_114 ) ;
F_28 ( & V_2 -> V_124 , V_109 ) ;
V_2 -> V_202 = ( V_201 != 0 ) ;
F_6 ( & V_2 -> V_47 -> V_47 , L_20 ,
V_144 , V_2 -> V_203 , V_2 -> V_202 ) ;
if ( V_2 -> V_113 && V_2 -> V_203 && V_2 -> V_202 ) {
V_38 = F_59 ( V_2 ) ;
if ( V_38 == 0 ) {
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
F_56 ( V_2 ) ;
}
} else if ( V_2 -> V_113 && V_2 -> V_203 ) {
if ( ! V_2 -> V_187 )
goto V_149;
F_65 ( V_2 , V_2 -> V_113 ) ;
F_55 ( V_2 ) ;
F_61 ( V_2 ) ;
}
V_149:
F_29 ( & V_2 -> V_124 , V_109 ) ;
return V_38 ;
}
static int F_66 ( struct V_193 * V_114 , int V_204 )
{
struct V_1 * V_2 ;
unsigned long V_109 ;
int V_38 = 0 ;
V_2 = F_25 ( V_114 , struct V_1 , V_114 ) ;
F_28 ( & V_2 -> V_124 , V_109 ) ;
V_2 -> V_203 = ( V_204 != 0 ) ;
F_6 ( & V_2 -> V_47 -> V_47 , L_20 ,
V_144 , V_2 -> V_203 , V_2 -> V_202 ) ;
if ( V_2 -> V_113 && V_2 -> V_203 && V_2 -> V_202 ) {
V_38 = F_59 ( V_2 ) ;
if ( V_38 == 0 ) {
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
F_56 ( V_2 ) ;
}
} else if ( V_2 -> V_113 && V_2 -> V_202 ) {
F_65 ( V_2 , V_2 -> V_113 ) ;
F_55 ( V_2 ) ;
F_61 ( V_2 ) ;
}
F_29 ( & V_2 -> V_124 , V_109 ) ;
return V_38 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
char V_48 [ 14 ] ;
int V_6 ;
V_4 = & V_2 -> V_7 [ 0 ] ;
V_4 -> V_2 = V_2 ;
strncpy ( V_4 -> V_48 , L_21 , sizeof( V_4 -> V_48 ) ) ;
V_4 -> V_4 . V_48 = V_4 -> V_48 ;
V_4 -> V_4 . V_205 = & V_206 ;
V_4 -> V_157 = 0 ;
V_4 -> V_126 = 0 ;
F_68 ( & V_4 -> V_4 , V_11 ) ;
V_4 -> V_4 . V_207 . V_208 = true ;
V_4 -> V_4 . V_207 . V_209 = true ;
V_4 -> V_4 . V_207 . V_210 = true ;
V_4 -> V_60 = 0 ;
V_4 -> V_4 . V_84 = & V_211 ;
F_34 ( & V_4 -> V_68 ) ;
V_4 -> V_212 = V_18 ;
for ( V_6 = 2 ; V_6 < V_2 -> V_213 * 2 ; V_6 ++ ) {
V_4 = & V_2 -> V_7 [ V_6 ] ;
if ( V_6 % 2 ) {
snprintf ( V_48 , sizeof( V_48 ) , L_22 , V_6 / 2 ) ;
V_4 -> V_37 = V_127 ;
V_4 -> V_4 . V_207 . V_209 = true ;
} else {
snprintf ( V_48 , sizeof( V_48 ) , L_23 , V_6 / 2 ) ;
V_4 -> V_37 = V_27 ;
V_4 -> V_4 . V_207 . V_210 = true ;
}
V_4 -> V_2 = V_2 ;
strncpy ( V_4 -> V_48 , V_48 , sizeof( V_4 -> V_48 ) ) ;
V_4 -> V_4 . V_48 = V_4 -> V_48 ;
V_4 -> V_4 . V_207 . V_214 = true ;
V_4 -> V_4 . V_207 . V_215 = true ;
V_4 -> V_4 . V_207 . V_216 = true ;
V_4 -> V_4 . V_205 = & V_206 ;
V_4 -> V_126 = 0 ;
F_68 ( & V_4 -> V_4 , ( unsigned short ) ~ 0 ) ;
V_4 -> V_60 = V_6 / 2 ;
F_34 ( & V_4 -> V_68 ) ;
F_41 ( & V_4 -> V_4 . V_217 , & V_2 -> V_114 . V_217 ) ;
V_4 -> V_8 = & V_2 -> V_9 [ V_6 ] ;
}
return 0 ;
}
static void F_31 ( struct V_3 * V_4 , int V_65 )
{
V_4 -> V_126 = 1 ;
F_37 ( & V_4 -> V_4 ) ;
while ( ! F_12 ( & V_4 -> V_68 ) ) {
struct V_29 * V_42 = NULL ;
V_42 = F_13 ( V_4 -> V_68 . V_150 , struct V_29 , V_68 ) ;
F_9 ( V_4 , V_42 , V_65 ) ;
}
}
static void F_69 ( struct V_1 * V_2 , struct V_218 * V_113 )
{
struct V_3 * V_4 ;
F_31 ( & V_2 -> V_7 [ 0 ] , - V_117 ) ;
F_45 (ep, &udc->gadget.ep_list, ep.ep_list) {
F_31 ( V_4 , - V_117 ) ;
}
if ( V_113 ) {
F_70 ( & V_2 -> V_124 ) ;
F_71 ( & V_2 -> V_114 , V_113 ) ;
F_72 ( & V_2 -> V_124 ) ;
}
}
static void F_65 ( struct V_1 * V_2 , struct V_218 * V_113 )
{
struct V_3 * V_4 ;
F_31 ( & V_2 -> V_7 [ 0 ] , - V_117 ) ;
F_45 (ep, &udc->gadget.ep_list, ep.ep_list) {
F_31 ( V_4 , - V_117 ) ;
}
if ( V_113 ) {
F_70 ( & V_2 -> V_124 ) ;
V_113 -> V_219 ( & V_2 -> V_114 ) ;
F_72 ( & V_2 -> V_124 ) ;
}
}
static int F_73 ( struct V_193 * V_114 ,
struct V_218 * V_113 )
{
struct V_1 * V_2 ;
int V_38 = 0 ;
unsigned long V_109 ;
V_2 = F_25 ( V_114 , struct V_1 , V_114 ) ;
if ( V_2 -> V_113 )
return - V_220 ;
F_28 ( & V_2 -> V_124 , V_109 ) ;
V_113 -> V_113 . V_221 = NULL ;
V_2 -> V_113 = V_113 ;
V_2 -> V_222 = V_223 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 ;
F_29 ( & V_2 -> V_124 , V_109 ) ;
if ( V_2 -> V_224 ) {
V_38 = F_74 ( V_2 -> V_224 -> V_225 ,
& V_2 -> V_114 ) ;
if ( V_38 ) {
F_16 ( & V_2 -> V_47 -> V_47 ,
L_24 ) ;
V_2 -> V_113 = NULL ;
return V_38 ;
}
}
if ( V_2 -> V_226 )
F_75 ( V_2 -> V_226 , & V_2 -> V_227 ) ;
return 0 ;
}
static int F_76 ( struct V_193 * V_114 )
{
struct V_1 * V_2 ;
unsigned long V_109 ;
V_2 = F_25 ( V_114 , struct V_1 , V_114 ) ;
F_28 ( & V_2 -> V_124 , V_109 ) ;
F_59 ( V_2 ) ;
F_55 ( V_2 ) ;
V_2 -> V_114 . V_115 = V_116 ;
F_65 ( V_2 , NULL ) ;
F_61 ( V_2 ) ;
F_29 ( & V_2 -> V_124 , V_109 ) ;
V_2 -> V_113 = NULL ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 , T_1 V_228 )
{
T_1 V_169 ;
V_169 = F_2 ( & V_2 -> V_16 -> V_169 [ 0 ] ) ;
V_169 |= V_228 << 16 ;
F_3 ( V_169 , & V_2 -> V_16 -> V_169 [ 0 ] ) ;
}
static void F_78 ( struct V_103 * V_4 , struct V_134 * V_137 )
{
struct V_3 * V_229 = F_25 ( V_4 , struct V_3 , V_4 ) ;
struct V_29 * V_42 = F_25 ( V_137 , struct V_29 , V_42 ) ;
struct V_1 * V_2 ;
unsigned long V_109 ;
V_2 = V_229 -> V_2 ;
F_7 ( & V_2 -> V_47 -> V_47 , L_25 , V_42 -> V_230 ) ;
F_28 ( & V_2 -> V_124 , V_109 ) ;
if ( V_42 -> V_230 ) {
F_77 ( V_2 , V_42 -> V_230 ) ;
V_42 -> V_230 = 0 ;
}
F_29 ( & V_2 -> V_124 , V_109 ) ;
}
static int
F_79 ( struct V_1 * V_2 , T_5 V_37 , T_3 V_65 , bool V_231 )
{
int V_38 = 0 ;
struct V_29 * V_42 ;
struct V_3 * V_4 ;
V_4 = & V_2 -> V_7 [ 0 ] ;
V_2 -> V_26 = V_37 ;
V_2 -> V_24 = V_232 ;
V_42 = V_2 -> V_233 ;
if ( V_231 == false ) {
* ( ( T_3 * ) V_42 -> V_42 . V_143 ) = F_80 ( V_65 ) ;
V_42 -> V_42 . V_43 = 2 ;
} else
V_42 -> V_42 . V_43 = 0 ;
V_42 -> V_4 = V_4 ;
V_42 -> V_42 . V_65 = - V_145 ;
V_42 -> V_42 . V_35 = 0 ;
if ( V_2 -> V_230 ) {
V_42 -> V_42 . V_142 = F_78 ;
V_42 -> V_230 = V_2 -> V_230 ;
V_2 -> V_230 = 0 ;
} else
V_42 -> V_42 . V_142 = NULL ;
V_42 -> V_44 = 0 ;
if ( V_42 -> V_42 . V_79 == V_136 ) {
V_42 -> V_42 . V_79 = F_81 ( V_4 -> V_2 -> V_114 . V_47 . V_234 ,
V_42 -> V_42 . V_143 , V_42 -> V_42 . V_43 ,
F_11 ( V_4 ) ? V_235 : V_236 ) ;
V_42 -> V_237 = 1 ;
}
if ( ! F_23 ( V_42 ) ) {
V_38 = F_10 ( V_4 , V_42 ) ;
if ( V_38 ) {
F_16 ( & V_2 -> V_47 -> V_47 ,
L_26 ) ;
goto V_149;
}
} else{
V_38 = - V_101 ;
F_16 ( & V_2 -> V_47 -> V_47 ,
L_27 ) ;
goto V_149;
}
F_41 ( & V_42 -> V_68 , & V_4 -> V_68 ) ;
return 0 ;
V_149:
F_42 ( & V_2 -> V_114 , & V_42 -> V_42 , F_11 ( V_4 ) ) ;
return V_38 ;
}
static void F_82 ( struct V_1 * V_2 , T_3 V_28 )
{
if ( V_28 <= V_238 ) {
V_2 -> V_230 = V_28 ;
if ( F_79 ( V_2 , V_127 , 0 , true ) )
F_4 ( V_2 ) ;
} else
F_16 ( & V_2 -> V_47 -> V_47 ,
L_28 , V_28 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_239 * V_240 )
{
V_2 -> V_241 = ( T_5 ) V_240 -> V_242 ;
V_2 -> V_222 = V_243 ;
if ( F_79 ( V_2 , V_127 , 0 , true ) )
F_4 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 , T_5 V_60 ,
struct V_239 * V_240 )
{
T_3 V_65 = 0 ;
int V_38 ;
if ( ( V_240 -> V_244 & ( V_245 | V_246 ) )
!= ( V_245 | V_247 ) )
return;
if ( ( V_240 -> V_244 & V_248 ) == V_249 ) {
V_65 = 1 << V_250 ;
V_65 |= V_2 -> V_197 << V_251 ;
} else if ( ( V_240 -> V_244 & V_248 )
== V_252 ) {
V_65 = 0 ;
} else if ( ( V_240 -> V_244 & V_248 )
== V_253 ) {
T_5 V_60 , V_37 ;
V_60 = V_240 -> V_254 & V_255 ;
V_37 = ( V_240 -> V_254 & V_256 )
? V_127 : V_27 ;
V_65 = F_47 ( V_2 , V_60 , V_37 )
<< V_257 ;
}
V_38 = F_79 ( V_2 , V_127 , V_65 , false ) ;
if ( V_38 )
F_4 ( V_2 ) ;
else
V_2 -> V_24 = V_147 ;
}
static void F_85 ( struct V_1 * V_2 , struct V_239 * V_240 )
{
T_5 V_60 ;
T_5 V_37 ;
struct V_3 * V_4 ;
if ( ( V_240 -> V_244 & ( V_246 | V_248 ) )
== ( ( V_247 | V_249 ) ) ) {
switch ( V_240 -> V_242 ) {
case V_251 :
V_2 -> V_197 = 0 ;
break;
default:
goto V_149;
}
} else if ( ( V_240 -> V_244 & ( V_246 | V_248 ) )
== ( ( V_247 | V_253 ) ) ) {
switch ( V_240 -> V_242 ) {
case V_257 :
V_60 = V_240 -> V_254 & V_255 ;
V_37 = ( V_240 -> V_254 & V_256 )
? V_127 : V_27 ;
if ( V_240 -> V_242 != 0 || V_240 -> V_258 != 0
|| V_60 > V_2 -> V_213 )
goto V_149;
V_4 = & V_2 -> V_7 [ V_60 * 2 + V_37 ] ;
if ( V_4 -> V_157 == 1 )
break;
F_70 ( & V_2 -> V_124 ) ;
F_46 ( V_2 , V_60 , V_37 , 0 ) ;
F_72 ( & V_2 -> V_124 ) ;
break;
default:
goto V_149;
}
} else
goto V_149;
if ( F_79 ( V_2 , V_127 , 0 , true ) )
F_4 ( V_2 ) ;
V_149:
return;
}
static void F_86 ( struct V_1 * V_2 , struct V_239 * V_240 )
{
T_5 V_60 ;
T_5 V_37 ;
if ( ( V_240 -> V_244 & ( V_246 | V_248 ) )
== ( ( V_247 | V_249 ) ) ) {
switch ( V_240 -> V_242 ) {
case V_251 :
V_2 -> V_197 = 1 ;
break;
case V_259 :
if ( V_240 -> V_254 & 0xFF
|| V_2 -> V_114 . V_115 != V_260 )
F_4 ( V_2 ) ;
if ( V_2 -> V_222 != V_261
&& V_2 -> V_222 != V_243
&& V_2 -> V_222 != V_262 )
F_4 ( V_2 ) ;
F_82 ( V_2 , ( V_240 -> V_254 >> 8 ) ) ;
goto V_149;
default:
goto V_149;
}
} else if ( ( V_240 -> V_244 & ( V_246 | V_248 ) )
== ( ( V_247 | V_253 ) ) ) {
switch ( V_240 -> V_242 ) {
case V_257 :
V_60 = V_240 -> V_254 & V_255 ;
V_37 = ( V_240 -> V_254 & V_256 )
? V_127 : V_27 ;
if ( V_240 -> V_242 != 0 || V_240 -> V_258 != 0
|| V_60 > V_2 -> V_213 )
goto V_149;
F_70 ( & V_2 -> V_124 ) ;
F_46 ( V_2 , V_60 , V_37 , 1 ) ;
F_72 ( & V_2 -> V_124 ) ;
break;
default:
goto V_149;
}
} else
goto V_149;
if ( F_79 ( V_2 , V_127 , 0 , true ) )
F_4 ( V_2 ) ;
V_149:
return;
}
static void F_87 ( struct V_1 * V_2 , T_5 V_60 ,
struct V_239 * V_240 )
__releases( &ep->udc->lock
static void F_88 ( struct V_1 * V_2 ,
struct V_3 * V_263 , struct V_29 * V_42 )
{
T_1 V_264 ;
if ( V_2 -> V_222 == V_243 ) {
V_264 = ( T_1 ) V_2 -> V_241 ;
F_3 ( V_264 << V_265 ,
& V_2 -> V_16 -> V_266 ) ;
}
F_9 ( V_263 , V_42 , 0 ) ;
switch ( V_2 -> V_24 ) {
case V_147 :
if ( F_79 ( V_2 , V_27 , 0 , true ) )
F_4 ( V_2 ) ;
break;
case V_267 :
if ( F_79 ( V_2 , V_127 , 0 , true ) )
F_4 ( V_2 ) ;
break;
case V_232 :
V_2 -> V_24 = V_25 ;
break;
case V_25 :
F_16 ( & V_2 -> V_47 -> V_47 , L_29 ) ;
break;
default:
F_4 ( V_2 ) ;
break;
}
}
static void F_89 ( struct V_1 * V_2 , T_5 V_60 , T_5 * V_268 )
{
T_1 V_82 ;
struct V_33 * V_8 ;
V_8 = & V_2 -> V_9 [ V_60 * 2 + V_27 ] ;
F_3 ( ( 1 << V_60 ) , & V_2 -> V_16 -> V_176 ) ;
do {
V_82 = F_2 ( & V_2 -> V_16 -> V_66 ) ;
F_3 ( V_82 | V_269 , & V_2 -> V_16 -> V_66 ) ;
memcpy ( V_268 , ( T_5 * ) V_8 -> V_270 , 8 ) ;
} while ( ! ( F_2 ( & V_2 -> V_16 -> V_66 ) & V_269 ) );
V_82 = F_2 ( & V_2 -> V_16 -> V_66 ) ;
F_3 ( V_82 & ~ V_269 , & V_2 -> V_16 -> V_66 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
T_1 V_161 , V_40 ;
int V_6 , V_60 = 0 , V_37 = 0 ;
struct V_3 * V_271 ;
struct V_29 * V_30 , * V_272 ;
int V_65 ;
V_161 = F_2 ( & V_2 -> V_16 -> V_176 ) ;
if ( V_161 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_213 ; V_6 ++ ) {
if ( V_161 & ( 1 << V_6 ) ) {
F_89 ( V_2 , V_6 ,
( T_5 * ) ( & V_2 -> V_273 ) ) ;
F_87 ( V_2 , V_6 ,
& V_2 -> V_273 ) ;
}
}
}
V_161 = F_2 ( & V_2 -> V_16 -> V_274 ) ;
if ( ! V_161 )
return;
F_3 ( V_161 , & V_2 -> V_16 -> V_274 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_213 * 2 ; V_6 ++ ) {
V_60 = V_6 >> 1 ;
V_37 = V_6 % 2 ;
V_40 = 1 << ( V_60 + 16 * V_37 ) ;
if ( ! ( V_40 & V_161 ) )
continue;
if ( V_6 == 1 )
V_271 = & V_2 -> V_7 [ 0 ] ;
else
V_271 = & V_2 -> V_7 [ V_6 ] ;
F_91 (curr_req, temp_req,
&curr_ep->queue, queue) {
V_65 = F_5 ( V_2 , V_6 , V_30 ) ;
if ( V_65 )
break;
V_30 -> V_42 . V_65 = V_65 ;
if ( V_60 == 0 ) {
F_88 ( V_2 , V_271 , V_30 ) ;
break;
} else {
F_9 ( V_271 , V_30 , V_65 ) ;
}
}
}
}
static void F_92 ( struct V_1 * V_2 )
{
T_1 V_161 ;
unsigned int V_67 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_197 = 0 ;
V_161 = F_2 ( & V_2 -> V_16 -> V_266 ) ;
V_161 &= ~ ( V_275 ) ;
F_3 ( V_161 , & V_2 -> V_16 -> V_266 ) ;
V_161 = F_2 ( & V_2 -> V_16 -> V_176 ) ;
F_3 ( V_161 , & V_2 -> V_16 -> V_176 ) ;
V_161 = F_2 ( & V_2 -> V_16 -> V_274 ) ;
F_3 ( V_161 , & V_2 -> V_16 -> V_274 ) ;
V_67 = F_15 ( V_276 ) ;
while ( F_2 ( & V_2 -> V_16 -> V_73 ) & 0xFFFFFFFF ) {
if ( V_67 == 0 ) {
F_16 ( & V_2 -> V_47 -> V_47 ,
L_30 ,
F_2 ( & V_2 -> V_16 -> V_73 ) ) ;
break;
}
V_67 -- ;
F_8 ( V_77 ) ;
}
F_3 ( ( T_1 ) ~ 0 , & V_2 -> V_16 -> V_140 ) ;
if ( F_2 ( & V_2 -> V_16 -> V_169 [ 0 ] ) & V_277 ) {
F_7 ( & V_2 -> V_47 -> V_47 , L_31 ) ;
V_2 -> V_222 = V_262 ;
F_69 ( V_2 , V_2 -> V_113 ) ;
} else {
F_7 ( & V_2 -> V_47 -> V_47 , L_32 ,
F_2 ( & V_2 -> V_16 -> V_169 ) ) ;
F_57 ( V_2 ) ;
F_65 ( V_2 , V_2 -> V_113 ) ;
F_1 ( V_2 ) ;
F_56 ( V_2 ) ;
V_2 -> V_222 = V_223 ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
V_2 -> V_222 = V_2 -> V_278 ;
V_2 -> V_278 = 0 ;
if ( V_2 -> V_113 ) {
if ( V_2 -> V_113 -> V_279 ) {
F_70 ( & V_2 -> V_124 ) ;
V_2 -> V_113 -> V_279 ( & V_2 -> V_114 ) ;
F_72 ( & V_2 -> V_124 ) ;
}
}
}
static void F_94 ( struct V_1 * V_2 )
{
V_2 -> V_278 = V_2 -> V_222 ;
V_2 -> V_222 = V_280 ;
if ( V_2 -> V_113 -> V_281 ) {
F_70 ( & V_2 -> V_124 ) ;
V_2 -> V_113 -> V_281 ( & V_2 -> V_114 ) ;
F_72 ( & V_2 -> V_124 ) ;
}
}
static void F_95 ( struct V_1 * V_2 )
{
T_1 V_169 ;
V_169 = F_2 ( & V_2 -> V_16 -> V_169 [ 0 ] ) ;
if ( ! ( V_169 & V_277 ) ) {
T_1 V_115 = V_169 & V_282 ;
switch ( V_115 ) {
case V_283 :
V_2 -> V_114 . V_115 = V_260 ;
break;
case V_284 :
V_2 -> V_114 . V_115 = V_285 ;
break;
case V_286 :
V_2 -> V_114 . V_115 = V_287 ;
break;
default:
V_2 -> V_114 . V_115 = V_116 ;
break;
}
}
if ( V_169 & V_199 ) {
V_2 -> V_278 = V_2 -> V_222 ;
V_2 -> V_222 = V_280 ;
if ( V_2 -> V_113 -> V_281 ) {
F_70 ( & V_2 -> V_124 ) ;
V_2 -> V_113 -> V_281 ( & V_2 -> V_114 ) ;
F_72 ( & V_2 -> V_124 ) ;
}
}
if ( ! ( V_169 & V_199 )
&& V_2 -> V_222 == V_280 ) {
F_93 ( V_2 ) ;
}
if ( ! V_2 -> V_278 )
V_2 -> V_222 = V_262 ;
}
static void F_96 ( struct V_1 * V_2 )
{
V_2 -> V_39 ++ ;
}
static T_6 F_97 ( int V_288 , void * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_47 ;
T_1 V_65 , V_289 ;
if ( V_2 -> V_126 )
return V_290 ;
F_72 ( & V_2 -> V_124 ) ;
V_65 = F_2 ( & V_2 -> V_16 -> V_291 ) ;
V_289 = F_2 ( & V_2 -> V_16 -> V_162 ) ;
V_65 &= V_289 ;
if ( V_65 == 0 ) {
F_70 ( & V_2 -> V_124 ) ;
return V_290 ;
}
F_3 ( V_65 , & V_2 -> V_16 -> V_291 ) ;
if ( V_65 & V_292 )
F_96 ( V_2 ) ;
if ( V_65 & V_293 )
F_92 ( V_2 ) ;
if ( V_65 & V_294 )
F_95 ( V_2 ) ;
if ( V_65 & V_295 )
F_90 ( V_2 ) ;
if ( V_65 & V_296 )
F_94 ( V_2 ) ;
F_70 ( & V_2 -> V_124 ) ;
return V_297 ;
}
static T_6 F_98 ( int V_288 , void * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_47 ;
if ( V_2 -> V_226 )
F_75 ( V_2 -> V_226 , & V_2 -> V_227 ) ;
return V_297 ;
}
static void F_99 ( struct V_298 * V_299 )
{
struct V_1 * V_2 ;
unsigned int V_300 ;
V_2 = F_25 ( V_299 , struct V_1 , V_227 ) ;
if ( ! V_2 -> V_188 -> V_300 )
return;
V_300 = V_2 -> V_188 -> V_300 -> V_301 () ;
F_7 ( & V_2 -> V_47 -> V_47 , L_33 , V_300 ) ;
if ( V_300 == V_302 )
F_64 ( & V_2 -> V_114 , 1 ) ;
else if ( V_300 == V_303 )
F_64 ( & V_2 -> V_114 , 0 ) ;
}
static void F_100 ( struct V_304 * V_305 )
{
struct V_1 * V_2 ;
V_2 = F_101 ( V_305 ) ;
V_142 ( V_2 -> F_9 ) ;
}
static int F_102 ( struct V_306 * V_307 )
{
struct V_1 * V_2 ;
V_2 = F_103 ( V_307 ) ;
F_104 ( & V_2 -> V_114 ) ;
if ( V_2 -> V_226 ) {
F_105 ( V_2 -> V_226 ) ;
F_106 ( V_2 -> V_226 ) ;
}
F_107 ( V_2 -> V_88 ) ;
if ( V_2 -> V_9 )
F_108 ( & V_307 -> V_47 , V_2 -> V_308 ,
V_2 -> V_9 , V_2 -> V_177 ) ;
F_61 ( V_2 ) ;
F_109 ( V_2 -> F_9 ) ;
return 0 ;
}
static int F_110 ( struct V_306 * V_307 )
{
struct V_309 * V_188 = F_111 ( & V_307 -> V_47 ) ;
struct V_1 * V_2 ;
int V_38 = 0 ;
struct V_310 * V_311 ;
T_7 V_312 ;
if ( V_188 == NULL ) {
F_16 ( & V_307 -> V_47 , L_34 ) ;
return - V_194 ;
}
V_2 = F_112 ( & V_307 -> V_47 , sizeof( * V_2 ) , V_313 ) ;
if ( V_2 == NULL )
return - V_101 ;
V_2 -> F_9 = & V_314 ;
V_2 -> V_188 = F_111 ( & V_307 -> V_47 ) ;
F_113 ( & V_2 -> V_124 ) ;
V_2 -> V_47 = V_307 ;
if ( V_188 -> V_228 == V_315 ) {
V_2 -> V_224 = F_114 ( & V_307 -> V_47 ,
V_316 ) ;
if ( F_115 ( V_2 -> V_224 ) ) {
V_38 = F_116 ( V_2 -> V_224 ) ;
if ( V_38 == - V_317 )
return V_38 ;
V_2 -> V_224 = NULL ;
return - V_318 ;
}
}
V_2 -> V_160 = F_117 ( & V_307 -> V_47 , NULL ) ;
if ( F_115 ( V_2 -> V_160 ) )
return F_116 ( V_2 -> V_160 ) ;
V_311 = F_118 ( V_2 -> V_47 , V_319 , L_35 ) ;
if ( V_311 == NULL ) {
F_16 ( & V_307 -> V_47 , L_36 ) ;
return - V_194 ;
}
V_2 -> V_180 = (struct V_320 V_321 * )
F_119 ( & V_307 -> V_47 , V_311 -> V_322 , F_120 ( V_311 ) ) ;
if ( V_2 -> V_180 == NULL ) {
F_16 ( & V_307 -> V_47 , L_37 ) ;
return - V_220 ;
}
V_311 = F_118 ( V_2 -> V_47 , V_319 , L_38 ) ;
if ( V_311 == NULL ) {
F_16 ( & V_307 -> V_47 , L_39 ) ;
return - V_194 ;
}
V_2 -> V_190 = F_119 ( & V_307 -> V_47 , V_311 -> V_322 , F_120 ( V_311 ) ) ;
if ( V_2 -> V_190 == NULL ) {
F_16 ( & V_307 -> V_47 , L_40 ) ;
return - V_220 ;
}
V_38 = F_58 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_16 =
(struct V_323 V_321 * ) ( ( unsigned long ) V_2 -> V_180
+ ( F_2 ( & V_2 -> V_180 -> V_324 )
& V_325 ) ) ;
V_2 -> V_213 = F_2 ( & V_2 -> V_180 -> V_326 ) & V_327 ;
F_55 ( V_2 ) ;
F_3 ( 0xFFFFFFFF , & V_2 -> V_16 -> V_291 ) ;
V_312 = V_2 -> V_213 * sizeof( struct V_33 ) * 2 ;
V_312 = ( V_312 + V_328 - 1 ) & ~ ( V_328 - 1 ) ;
V_2 -> V_9 = F_121 ( & V_307 -> V_47 , V_312 ,
& V_2 -> V_177 , V_313 ) ;
if ( V_2 -> V_9 == NULL ) {
F_16 ( & V_307 -> V_47 , L_41 ) ;
V_38 = - V_101 ;
goto V_329;
}
V_2 -> V_308 = V_312 ;
V_2 -> V_88 = F_122 ( L_42 ,
& V_307 -> V_47 ,
sizeof( struct V_31 ) ,
V_330 ,
V_331 ) ;
if ( ! V_2 -> V_88 ) {
V_38 = - V_101 ;
goto V_332;
}
V_312 = V_2 -> V_213 * sizeof( struct V_3 ) * 2 ;
V_2 -> V_7 = F_112 ( & V_307 -> V_47 , V_312 , V_313 ) ;
if ( V_2 -> V_7 == NULL ) {
V_38 = - V_101 ;
goto V_333;
}
V_2 -> V_233 = F_112 ( & V_307 -> V_47 , sizeof( struct V_29 ) ,
V_313 ) ;
if ( ! V_2 -> V_233 ) {
V_38 = - V_101 ;
goto V_333;
}
F_34 ( & V_2 -> V_233 -> V_68 ) ;
V_2 -> V_233 -> V_42 . V_143 = F_33 ( 8 , V_313 ) ;
V_2 -> V_233 -> V_42 . V_79 = V_136 ;
V_2 -> V_278 = V_334 ;
V_2 -> V_222 = V_335 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_197 = 0 ;
V_311 = F_123 ( V_2 -> V_47 , V_336 , 0 ) ;
if ( V_311 == NULL ) {
F_16 ( & V_307 -> V_47 , L_43 ) ;
V_38 = - V_194 ;
goto V_333;
}
V_2 -> V_288 = V_311 -> V_322 ;
if ( F_124 ( & V_307 -> V_47 , V_2 -> V_288 , F_97 ,
V_337 , V_338 , V_2 ) ) {
F_16 ( & V_307 -> V_47 , L_44 ,
V_2 -> V_288 ) ;
V_38 = - V_194 ;
goto V_333;
}
V_2 -> V_114 . V_205 = & V_339 ;
V_2 -> V_114 . V_263 = & V_2 -> V_7 [ 0 ] . V_4 ;
F_34 ( & V_2 -> V_114 . V_217 ) ;
V_2 -> V_114 . V_115 = V_116 ;
V_2 -> V_114 . V_340 = V_260 ;
V_2 -> V_114 . V_48 = V_338 ;
F_67 ( V_2 ) ;
if ( V_2 -> V_224 )
V_2 -> V_191 = 1 ;
else if ( V_188 -> V_300 ) {
V_2 -> V_191 = 1 ;
V_38 = F_125 ( & V_307 -> V_47 ,
V_188 -> V_300 -> V_288 , NULL ,
F_98 , V_341 , L_45 , V_2 ) ;
if ( V_38 ) {
F_7 ( & V_307 -> V_47 ,
L_46
L_47 ) ;
V_2 -> V_191 = 0 ;
}
V_2 -> V_226 = F_126 ( L_48 ) ;
if ( ! V_2 -> V_226 ) {
F_16 ( & V_307 -> V_47 , L_49 ) ;
V_38 = - V_101 ;
goto V_333;
}
F_127 ( & V_2 -> V_227 , F_99 ) ;
}
if ( V_2 -> V_191 )
F_60 ( V_2 ) ;
else
V_2 -> V_202 = 1 ;
V_38 = F_128 ( & V_307 -> V_47 , & V_2 -> V_114 ,
F_100 ) ;
if ( V_38 )
goto V_342;
F_129 ( V_307 , V_2 ) ;
F_7 ( & V_307 -> V_47 , L_50 ,
V_2 -> V_191 ? L_51 : L_52 ) ;
return 0 ;
V_342:
F_106 ( V_2 -> V_226 ) ;
V_333:
F_107 ( V_2 -> V_88 ) ;
V_332:
F_108 ( & V_307 -> V_47 , V_2 -> V_308 ,
V_2 -> V_9 , V_2 -> V_177 ) ;
V_329:
F_60 ( V_2 ) ;
return V_38 ;
}
static int F_130 ( struct V_304 * V_47 )
{
struct V_1 * V_2 ;
V_2 = F_101 ( V_47 ) ;
if ( V_2 -> V_224 )
return 0 ;
if ( V_2 -> V_188 -> V_300 && V_2 -> V_188 -> V_300 -> V_301 )
if ( V_2 -> V_188 -> V_300 -> V_301 () == V_302 ) {
F_7 ( & V_2 -> V_47 -> V_47 , L_53 ) ;
return - V_159 ;
}
if ( ! V_2 -> V_191 ) {
F_55 ( V_2 ) ;
F_131 ( & V_2 -> V_124 ) ;
F_65 ( V_2 , V_2 -> V_113 ) ;
F_132 ( & V_2 -> V_124 ) ;
F_60 ( V_2 ) ;
}
return 0 ;
}
static int F_133 ( struct V_304 * V_47 )
{
struct V_1 * V_2 ;
int V_38 ;
V_2 = F_101 ( V_47 ) ;
if ( V_2 -> V_224 )
return 0 ;
if ( ! V_2 -> V_191 ) {
V_38 = F_58 ( V_2 ) ;
if ( V_38 )
return V_38 ;
if ( V_2 -> V_113 && V_2 -> V_203 ) {
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
F_56 ( V_2 ) ;
}
}
return 0 ;
}
static void F_134 ( struct V_306 * V_307 )
{
struct V_1 * V_2 ;
T_1 V_228 ;
V_2 = F_103 ( V_307 ) ;
F_59 ( V_2 ) ;
V_228 = F_2 ( & V_2 -> V_16 -> V_173 ) ;
V_228 &= ~ 3 ;
F_3 ( V_228 , & V_2 -> V_16 -> V_173 ) ;
F_61 ( V_2 ) ;
}
