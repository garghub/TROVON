static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 = V_3 -> V_5 - 1 ;
if ( V_4 >= 0 ) {
int V_6 ;
struct V_7 * V_7 ;
for ( V_6 = 0 ; V_6 <= V_4 ; V_6 ++ ) {
V_7 = V_3 -> V_7 [ V_6 ] ;
if ( V_7 )
F_2 ( V_2 , V_7 ) ;
}
}
F_3 ( & V_3 -> V_8 ) ;
F_4 ( V_3 ) ;
}
static void
F_5 ( struct V_1 * V_9 , struct V_10 * V_10 , int V_11 )
__releases( V_9 -> V_12 )
__acquires( V_9 -> V_12 )
{
struct V_13 * V_14 = F_6 ( V_9 ) -> V_15 . V_16 ;
struct V_17 * V_18 = V_10 -> V_18 ;
struct V_3 * V_3 ;
V_19:
F_1 ( V_9 , V_10 -> V_20 ) ;
V_10 -> V_20 = NULL ;
if ( F_7 ( V_11 == - V_21 ) )
V_11 = 0 ;
switch ( F_8 ( V_10 -> V_22 ) ) {
case V_23 :
F_6 ( V_9 ) -> V_15 . V_24 -- ;
if ( F_6 ( V_9 ) -> V_15 . V_24 == 0 ) {
if ( F_9 ( V_9 ) )
F_10 () ;
if ( F_11 ( V_9 ) )
F_12 ( V_14 , 0 ) ;
}
break;
case V_25 :
F_6 ( V_9 ) -> V_15 . V_26 -- ;
break;
}
#ifdef F_13
F_14 ( V_10 , L_1 , F_15 ( V_10 -> V_22 ) , V_11 ) ;
#endif
F_16 ( F_6 ( V_9 ) , V_10 ) ;
F_17 ( & V_9 -> V_12 ) ;
F_18 ( F_6 ( V_9 ) , V_10 , V_11 ) ;
F_19 ( & V_9 -> V_12 ) ;
if ( F_6 ( V_9 ) -> V_15 . V_24 == 0
&& F_6 ( V_9 ) -> V_15 . V_26 == 0 ) {
V_9 -> V_27 &= ~ ( V_28 | V_29 ) ;
F_20 ( V_9 , V_9 -> V_27 , & V_9 -> V_30 -> V_31 ) ;
}
if ( ! F_21 ( & V_18 -> V_32 ) ) {
V_10 = F_22 ( & V_18 -> V_32 , struct V_10 , V_32 ) ;
V_3 = V_10 -> V_20 ;
if ( V_3 -> V_33 > V_3 -> V_5 ) {
V_11 = 0 ;
goto V_19;
}
}
}
static int F_23 ( struct V_1 * V_9 , int V_34 , int V_35 )
{
int V_6 , V_36 = - V_37 ;
if ( V_34 > V_38 )
V_34 = V_38 ;
for ( V_6 = 0 ; V_6 < V_34 ; V_6 ++ ) {
if ( V_36 < 0 || V_9 -> V_35 [ V_36 ] > V_9 -> V_35 [ V_6 ] ) {
int V_39 ;
for ( V_39 = V_6 ; V_39 < V_38 ; V_39 += V_34 ) {
if ( ( V_9 -> V_35 [ V_39 ] + V_35 ) > 900 )
break;
}
if ( V_39 < V_38 )
continue;
V_36 = V_6 ;
}
}
return V_36 ;
}
static void F_24 ( struct V_1 * V_9 , struct V_40 * V_40 )
{
unsigned V_6 ;
F_25 ( V_9 , L_2 ,
( V_40 -> V_41 & F_26 ( V_9 , V_42 ) ) ? L_3 : L_4 ,
V_40 , V_40 -> V_36 , V_40 -> V_35 , V_40 -> V_34 ) ;
for ( V_6 = V_40 -> V_36 ; V_6 < V_38 ; V_6 += V_40 -> V_34 ) {
struct V_40 * * V_43 = & V_9 -> V_44 [ V_6 ] ;
T_2 * V_45 = & V_9 -> V_46 -> V_47 [ V_6 ] ;
struct V_40 * V_48 = * V_43 ;
while ( V_48 && V_40 != V_48 ) {
if ( V_40 -> V_34 > V_48 -> V_34 )
break;
V_43 = & V_48 -> V_49 ;
V_45 = & V_48 -> V_50 ;
V_48 = * V_43 ;
}
if ( V_40 != V_48 ) {
V_40 -> V_49 = V_48 ;
if ( V_48 )
V_40 -> V_50 = * V_45 ;
F_27 () ;
* V_43 = V_40 ;
* V_45 = F_26 ( V_9 , V_40 -> V_51 ) ;
F_27 () ;
}
V_9 -> V_35 [ V_6 ] += V_40 -> V_35 ;
}
F_6 ( V_9 ) -> V_15 . V_52 += V_40 -> V_35 / V_40 -> V_34 ;
}
static int F_28 ( struct V_1 * V_9 , struct V_40 * V_40 )
{
int V_36 ;
V_40 -> V_53 = V_54 ;
V_40 -> V_55 = NULL ;
V_40 -> V_49 = NULL ;
V_40 -> V_50 = 0 ;
if ( F_29 ( V_9 )
&& ( V_40 -> type == V_25 )
&& ! ( V_9 -> V_56 ++ ) )
F_30 ( & V_9 -> V_57 , F_31 ( V_58 + V_59 ) ) ;
F_27 () ;
switch ( V_40 -> type ) {
case V_60 :
if ( V_9 -> V_61 == NULL ) {
F_32 ( V_9 -> V_27 & V_62 ) ;
F_20 ( V_9 , V_40 -> V_51 ,
& V_9 -> V_30 -> V_63 ) ;
} else {
V_9 -> V_61 -> V_49 = V_40 ;
V_9 -> V_61 -> V_50 = F_26 ( V_9 ,
V_40 -> V_51 ) ;
}
V_40 -> V_55 = V_9 -> V_61 ;
if ( ! V_9 -> V_61 && ! V_9 -> V_64 ) {
F_27 () ;
V_9 -> V_27 |= V_62 ;
F_20 ( V_9 , 0 , & V_9 -> V_30 -> V_65 ) ;
F_20 ( V_9 , V_9 -> V_27 ,
& V_9 -> V_30 -> V_31 ) ;
}
V_9 -> V_61 = V_40 ;
break;
case V_66 :
if ( V_9 -> V_67 == NULL ) {
F_32 ( V_9 -> V_27 & V_68 ) ;
F_20 ( V_9 , V_40 -> V_51 , & V_9 -> V_30 -> V_69 ) ;
} else {
V_9 -> V_67 -> V_49 = V_40 ;
V_9 -> V_67 -> V_50 = F_26 ( V_9 ,
V_40 -> V_51 ) ;
}
V_40 -> V_55 = V_9 -> V_67 ;
if ( ! V_9 -> V_67 && ! V_9 -> V_64 ) {
F_27 () ;
V_9 -> V_27 |= V_68 ;
F_20 ( V_9 , 0 , & V_9 -> V_30 -> V_70 ) ;
F_20 ( V_9 , V_9 -> V_27 ,
& V_9 -> V_30 -> V_31 ) ;
}
V_9 -> V_67 = V_40 ;
break;
default:
V_36 = F_23 ( V_9 , V_40 -> V_34 , V_40 -> V_35 ) ;
if ( V_36 < 0 ) {
F_33 ( V_9 ,
L_5 ,
V_36 , V_40 -> V_34 , V_40 -> V_35 ) ;
return V_36 ;
}
V_40 -> V_36 = V_36 ;
F_24 ( V_9 , V_40 ) ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_9 , struct V_40 * V_40 )
{
int V_6 ;
for ( V_6 = V_40 -> V_36 ; V_6 < V_38 ; V_6 += V_40 -> V_34 ) {
struct V_40 * V_71 ;
struct V_40 * * V_43 = & V_9 -> V_44 [ V_6 ] ;
T_2 * V_45 = & V_9 -> V_46 -> V_47 [ V_6 ] ;
while ( * V_43 && ( V_71 = * V_43 ) != V_40 ) {
V_45 = & V_71 -> V_50 ;
V_43 = & V_71 -> V_49 ;
}
if ( * V_43 ) {
* V_45 = V_40 -> V_50 ;
* V_43 = V_40 -> V_49 ;
}
V_9 -> V_35 [ V_6 ] -= V_40 -> V_35 ;
}
F_6 ( V_9 ) -> V_15 . V_52 -= V_40 -> V_35 / V_40 -> V_34 ;
F_25 ( V_9 , L_6 ,
( V_40 -> V_41 & F_26 ( V_9 , V_42 ) ) ? L_3 : L_4 ,
V_40 , V_40 -> V_36 , V_40 -> V_35 , V_40 -> V_34 ) ;
}
static void F_35 ( struct V_1 * V_9 , struct V_40 * V_40 )
{
V_40 -> V_41 |= F_26 ( V_9 , V_72 ) ;
F_27 () ;
V_40 -> V_53 = V_73 ;
switch ( V_40 -> type ) {
case V_60 :
if ( V_40 -> V_55 == NULL ) {
if ( ! V_40 -> V_50 ) {
V_9 -> V_27 &= ~ V_62 ;
F_20 ( V_9 , V_9 -> V_27 ,
& V_9 -> V_30 -> V_31 ) ;
} else
F_20 ( V_9 ,
F_36 ( V_9 , & V_40 -> V_50 ) ,
& V_9 -> V_30 -> V_63 ) ;
} else {
V_40 -> V_55 -> V_49 = V_40 -> V_49 ;
V_40 -> V_55 -> V_50 = V_40 -> V_50 ;
}
if ( V_9 -> V_61 == V_40 ) {
V_9 -> V_61 = V_40 -> V_55 ;
if ( V_9 -> V_61 )
V_9 -> V_61 -> V_49 = NULL ;
} else if ( V_40 -> V_49 ) {
V_40 -> V_49 -> V_55 = V_40 -> V_55 ;
}
break;
case V_66 :
if ( V_40 -> V_55 == NULL ) {
if ( ! V_40 -> V_50 ) {
V_9 -> V_27 &= ~ V_68 ;
F_20 ( V_9 , V_9 -> V_27 ,
& V_9 -> V_30 -> V_31 ) ;
} else
F_20 ( V_9 ,
F_36 ( V_9 , & V_40 -> V_50 ) ,
& V_9 -> V_30 -> V_69 ) ;
} else {
V_40 -> V_55 -> V_49 = V_40 -> V_49 ;
V_40 -> V_55 -> V_50 = V_40 -> V_50 ;
}
if ( V_9 -> V_67 == V_40 ) {
V_9 -> V_67 = V_40 -> V_55 ;
if ( V_9 -> V_67 )
V_9 -> V_67 -> V_49 = NULL ;
} else if ( V_40 -> V_49 ) {
V_40 -> V_49 -> V_55 = V_40 -> V_55 ;
}
break;
default:
F_34 ( V_9 , V_40 ) ;
break;
}
}
static struct V_40 * F_37 (
struct V_1 * V_9 ,
struct V_17 * V_18 ,
struct V_74 * V_75 ,
unsigned int V_22 ,
int V_34
) {
struct V_40 * V_40 ;
unsigned long V_76 ;
F_38 ( & V_9 -> V_12 , V_76 ) ;
if ( ! ( V_40 = V_18 -> V_20 ) ) {
struct V_7 * V_7 ;
int V_77 ;
T_3 V_78 ;
V_40 = F_39 ( V_9 , V_79 ) ;
if ( ! V_40 ) {
goto V_80;
}
V_7 = F_40 ( V_9 , V_79 ) ;
if ( ! V_7 ) {
F_41 ( V_9 , V_40 ) ;
V_40 = NULL ;
goto V_80;
}
V_40 -> V_81 = V_7 ;
V_40 -> V_82 = F_26 ( V_9 , V_7 -> V_83 ) ;
V_40 -> V_84 = V_40 -> V_82 ;
V_40 -> V_53 = V_85 ;
V_77 = ! ( V_18 -> V_86 . V_87 & V_88 ) ;
V_78 = F_42 ( V_22 ) ;
V_40 -> type = F_8 ( V_22 ) ;
V_78 |= ( V_18 -> V_86 . V_87 & ~ V_88 ) << 7 ;
V_78 |= F_43 ( & V_18 -> V_86 ) << 16 ;
if ( V_75 -> V_89 == V_90 )
V_78 |= V_91 ;
if ( V_40 -> type != V_60 ) {
V_78 |= V_77 ? V_92 : V_93 ;
if ( V_40 -> type != V_66 ) {
if ( V_40 -> type == V_23 )
V_78 |= V_42 ;
else if ( V_34 > 32 )
V_34 = 32 ;
V_40 -> V_34 = V_34 ;
V_40 -> V_35 = F_44 (
V_75 -> V_89 , ! V_77 ,
V_40 -> type == V_23 ,
F_43 ( & V_18 -> V_86 ) )
/ 1000 ;
}
}
V_40 -> V_41 = F_26 ( V_9 , V_78 ) ;
V_18 -> V_20 = V_40 ;
}
V_80:
F_45 ( & V_9 -> V_12 , V_76 ) ;
return V_40 ;
}
static void F_46 ( struct V_1 * V_9 , struct V_40 * V_40 )
{
V_40 -> V_41 |= F_26 ( V_9 , V_94 ) ;
F_35 ( V_9 , V_40 ) ;
V_40 -> V_49 = V_9 -> V_64 ;
V_40 -> V_55 = NULL ;
V_9 -> V_64 = V_40 ;
F_20 ( V_9 , V_95 , & V_9 -> V_30 -> V_96 ) ;
F_20 ( V_9 , V_95 , & V_9 -> V_30 -> V_97 ) ;
( void ) F_47 ( V_9 , & V_9 -> V_30 -> V_31 ) ;
V_40 -> V_98 = F_48 ( V_9 ) + 1 ;
}
static void
F_49 ( struct V_1 * V_9 , T_3 V_78 ,
T_4 V_99 , int V_100 ,
struct V_10 * V_10 , int V_101 )
{
struct V_7 * V_7 , * V_102 ;
struct V_3 * V_3 = V_10 -> V_20 ;
int V_103 = V_78 & V_104 ;
int V_105 ;
if ( V_101 != ( V_3 -> V_5 - 1 )
|| ( V_10 -> V_106 & V_107 ) )
V_78 |= F_50 ( 6 ) ;
V_102 = V_3 -> V_7 [ V_101 ] ;
V_7 = V_3 -> V_7 [ V_101 ] = V_3 -> V_40 -> V_81 ;
V_3 -> V_40 -> V_81 = V_102 ;
V_7 -> V_40 = V_3 -> V_40 ;
V_7 -> V_108 = NULL ;
V_7 -> V_101 = V_101 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_109 = V_99 ;
if ( ! V_100 )
V_99 = 0 ;
V_7 -> V_41 = F_26 ( V_9 , V_78 ) ;
if ( V_103 ) {
V_7 -> V_110 = F_26 ( V_9 , V_99 & 0xFFFFF000 ) ;
* F_51 ( V_9 , V_7 , 0 ) = F_52 ( V_9 ,
( V_99 & 0x0FFF ) | 0xE000 ) ;
} else {
V_7 -> V_110 = F_26 ( V_9 , V_99 ) ;
}
if ( V_99 )
V_7 -> V_111 = F_26 ( V_9 , V_99 + V_100 - 1 ) ;
else
V_7 -> V_111 = 0 ;
V_7 -> V_112 = F_26 ( V_9 , V_102 -> V_83 ) ;
F_53 ( & V_7 -> V_113 , & V_7 -> V_40 -> V_113 ) ;
V_105 = F_54 ( V_7 -> V_83 ) ;
V_7 -> V_114 = V_9 -> V_114 [ V_105 ] ;
V_9 -> V_114 [ V_105 ] = V_7 ;
F_27 () ;
V_7 -> V_40 -> V_82 = V_7 -> V_112 ;
}
static void F_55 (
struct V_1 * V_9 ,
struct V_10 * V_10
) {
struct V_3 * V_3 = V_10 -> V_20 ;
struct V_13 * V_14 = F_6 ( V_9 ) -> V_15 . V_16 ;
T_4 V_99 ;
int V_115 = V_10 -> V_116 ;
int V_117 = 0 ;
T_3 V_78 = 0 ;
int V_77 = F_15 ( V_10 -> V_22 ) ;
int V_44 = 0 ;
if ( ! F_56 ( V_10 -> V_14 , F_57 ( V_10 -> V_22 ) , V_77 ) ) {
F_58 ( V_10 -> V_14 , F_57 ( V_10 -> V_22 ) ,
V_77 , 1 ) ;
V_3 -> V_40 -> V_84 &= ~ F_26 ( V_9 , V_118 ) ;
}
F_59 ( & V_3 -> V_8 , & V_9 -> V_8 ) ;
if ( V_115 )
V_99 = V_10 -> V_119 ;
else
V_99 = 0 ;
switch ( V_3 -> V_40 -> type ) {
case V_25 :
V_44 = F_6 ( V_9 ) -> V_15 . V_26 ++ == 0
&& F_6 ( V_9 ) -> V_15 . V_24 == 0 ;
case V_66 :
V_78 = V_77
? V_120 | V_121 | V_122
: V_120 | V_121 | V_123 ;
while ( V_115 > 4096 ) {
F_49 ( V_9 , V_78 , V_99 , 4096 , V_10 , V_117 ) ;
V_99 += 4096 ;
V_115 -= 4096 ;
V_117 ++ ;
}
if ( ! ( V_10 -> V_106 & V_124 ) )
V_78 |= V_125 ;
F_49 ( V_9 , V_78 , V_99 , V_115 , V_10 , V_117 ) ;
V_117 ++ ;
if ( ( V_10 -> V_106 & V_126 )
&& V_117 < V_3 -> V_5 ) {
F_49 ( V_9 , V_78 , 0 , 0 , V_10 , V_117 ) ;
V_117 ++ ;
}
if ( V_3 -> V_40 -> type == V_66 ) {
F_27 () ;
F_20 ( V_9 , V_127 , & V_9 -> V_30 -> V_128 ) ;
}
break;
case V_60 :
V_78 = V_121 | V_129 | V_130 ;
F_49 ( V_9 , V_78 , V_10 -> V_131 , 8 , V_10 , V_117 ++ ) ;
if ( V_115 > 0 ) {
V_78 = V_121 | V_125 | V_132 ;
V_78 |= V_77 ? V_122 : V_123 ;
F_49 ( V_9 , V_78 , V_99 , V_115 , V_10 , V_117 ++ ) ;
}
V_78 = ( V_77 || V_115 == 0 )
? V_121 | V_123 | V_132
: V_121 | V_122 | V_132 ;
F_49 ( V_9 , V_78 , V_99 , 0 , V_10 , V_117 ++ ) ;
F_27 () ;
F_20 ( V_9 , V_133 , & V_9 -> V_30 -> V_128 ) ;
break;
case V_23 :
for ( V_117 = V_3 -> V_33 ; V_117 < V_10 -> V_134 ;
V_117 ++ ) {
int V_135 = V_10 -> V_136 ;
V_135 += V_117 * V_10 -> V_34 ;
V_135 &= 0xffff ;
F_49 ( V_9 , V_121 | V_104 | V_135 ,
V_99 + V_10 -> V_137 [ V_117 ] . V_138 ,
V_10 -> V_137 [ V_117 ] . V_5 , V_10 , V_117 ) ;
}
if ( F_6 ( V_9 ) -> V_15 . V_24 == 0 ) {
if ( F_9 ( V_9 ) )
F_60 () ;
if ( F_11 ( V_9 ) )
F_12 ( V_14 , 1 ) ;
}
V_44 = F_6 ( V_9 ) -> V_15 . V_24 ++ == 0
&& F_6 ( V_9 ) -> V_15 . V_26 == 0 ;
break;
}
if ( V_44 ) {
F_27 () ;
V_9 -> V_27 |= V_28 | V_29 ;
F_20 ( V_9 , V_9 -> V_27 , & V_9 -> V_30 -> V_31 ) ;
}
}
static int F_61 ( struct V_1 * V_9 , struct V_10 * V_10 , struct V_7 * V_7 )
{
T_3 V_139 = F_36 ( V_9 , & V_7 -> V_41 ) ;
int V_140 = 0 ;
int V_11 = - V_21 ;
F_3 ( & V_7 -> V_113 ) ;
if ( V_139 & V_104 ) {
T_5 V_141 = F_62 ( V_9 , V_7 , 0 ) ;
int V_142 = 0 ;
V_140 = ( V_141 >> 12 ) & 0xF ;
if ( V_139 & V_121 )
return V_11 ;
if ( F_15 ( V_10 -> V_22 ) )
V_142 = V_10 -> V_137 [ V_7 -> V_101 ] . V_5 ;
else {
if ( V_140 == V_143 )
V_140 = V_144 ;
V_142 = V_141 & 0x3ff ;
}
V_10 -> V_145 += V_142 ;
V_10 -> V_137 [ V_7 -> V_101 ] . V_145 = V_142 ;
V_10 -> V_137 [ V_7 -> V_101 ] . V_11 = V_146 [ V_140 ] ;
if ( V_140 != V_144 )
F_25 ( V_9 ,
L_7 ,
V_10 , V_7 , 1 + V_7 -> V_101 , V_142 , V_140 ) ;
} else {
int type = F_8 ( V_10 -> V_22 ) ;
T_3 V_147 = F_36 ( V_9 , & V_7 -> V_111 ) ;
V_140 = F_63 ( V_139 ) ;
if ( V_140 == V_143
&& ! ( V_10 -> V_106 & V_124 ) )
V_140 = V_144 ;
if ( V_140 != V_144 && V_140 < 0x0E )
V_11 = V_146 [ V_140 ] ;
if ( ( type != V_60 || V_7 -> V_101 != 0 ) && V_147 != 0 ) {
if ( V_7 -> V_110 == 0 )
V_10 -> V_145 += V_147 - V_7 -> V_109 + 1 ;
else
V_10 -> V_145 +=
F_36 ( V_9 , & V_7 -> V_110 )
- V_7 -> V_109 ;
}
if ( V_140 != V_144 && V_140 < 0x0E )
F_25 ( V_9 ,
L_8 ,
V_10 , V_7 , 1 + V_7 -> V_101 , V_140 ,
V_10 -> V_145 ,
V_10 -> V_116 ) ;
}
return V_11 ;
}
static void F_64 ( struct V_1 * V_9 , struct V_7 * V_7 , int V_140 )
{
struct V_10 * V_10 = V_7 -> V_10 ;
T_1 * V_3 = V_10 -> V_20 ;
struct V_40 * V_40 = V_7 -> V_40 ;
struct V_148 * V_149 = V_7 -> V_113 . V_150 ;
T_2 V_151 = V_40 -> V_84 & F_26 ( V_9 , V_118 ) ;
V_40 -> V_41 |= F_26 ( V_9 , V_72 ) ;
F_27 () ;
V_40 -> V_84 &= ~ F_26 ( V_9 , V_152 ) ;
while ( V_149 != & V_40 -> V_113 ) {
struct V_7 * V_150 ;
V_150 = F_65 ( V_149 , struct V_7 , V_113 ) ;
V_149 = V_150 -> V_113 . V_150 ;
if ( V_150 -> V_10 != V_10 )
break;
F_3 ( & V_150 -> V_113 ) ;
V_3 -> V_33 ++ ;
V_40 -> V_84 = V_150 -> V_112 | V_151 ;
}
switch ( V_140 ) {
case V_143 :
if ( ( V_10 -> V_106 & V_124 ) == 0 )
break;
case V_153 :
if ( F_66 ( V_10 -> V_22 ) )
break;
default:
F_33 ( V_9 ,
L_9 ,
V_10 , V_10 -> V_14 -> V_154 ,
F_57 ( V_10 -> V_22 ) ,
F_67 ( V_10 -> V_22 ) ? L_10 : L_11 ,
F_68 ( V_9 , V_7 -> V_41 ) ,
V_140 , V_146 [ V_140 ] ) ;
}
}
static struct V_7 * F_69 ( struct V_1 * V_9 )
{
T_3 V_83 ;
struct V_7 * V_155 = NULL ;
struct V_7 * V_7 = NULL ;
V_83 = F_36 ( V_9 , & V_9 -> V_46 -> V_156 ) ;
V_9 -> V_46 -> V_156 = 0 ;
F_27 () ;
while ( V_83 ) {
int V_140 ;
V_7 = F_70 ( V_9 , V_83 ) ;
if ( ! V_7 ) {
F_71 ( V_9 , L_12 , V_83 ) ;
break;
}
V_7 -> V_41 |= F_26 ( V_9 , V_157 ) ;
V_140 = F_63 ( F_36 ( V_9 , & V_7 -> V_41 ) ) ;
if ( V_140 != V_144
&& ( V_7 -> V_40 -> V_84 & F_26 ( V_9 , V_152 ) ) )
F_64 ( V_9 , V_7 , V_140 ) ;
V_7 -> V_108 = V_155 ;
V_155 = V_7 ;
V_83 = F_36 ( V_9 , & V_7 -> V_112 ) ;
}
return V_155 ;
}
static void
F_72 ( struct V_1 * V_9 , T_5 V_98 )
{
struct V_40 * V_40 , * * V_4 ;
V_158:
for ( V_4 = & V_9 -> V_64 , V_40 = * V_4 ; V_40 != NULL ; V_40 = * V_4 ) {
struct V_148 * V_159 , * V_149 ;
int V_160 , V_161 ;
T_2 * V_43 ;
if ( F_7 ( V_9 -> V_162 == V_163 ) ) {
if ( F_73 ( V_98 , V_40 -> V_98 ) ) {
V_164:
V_4 = & V_40 -> V_49 ;
continue;
}
if ( ! F_21 ( & V_40 -> V_113 ) ) {
struct V_7 * V_7 ;
T_3 V_165 ;
V_7 = F_65 ( V_40 -> V_113 . V_150 , struct V_7 ,
V_113 ) ;
V_165 = F_68 ( V_9 , V_40 -> V_84 ) &
V_166 ;
if ( V_7 -> V_83 != V_165 ) {
if ( V_40 == V_9 -> V_167 )
V_9 -> V_167 = NULL ;
else
goto V_164;
}
}
}
* V_4 = V_40 -> V_49 ;
V_40 -> V_49 = NULL ;
V_161 = 0 ;
V_168:
V_160 = 0 ;
V_43 = & V_40 -> V_84 ;
F_74 (entry, tmp, &ed->td_list) {
struct V_7 * V_7 ;
struct V_10 * V_10 ;
T_1 * V_3 ;
T_2 V_169 ;
T_3 V_139 ;
V_7 = F_65 ( V_159 , struct V_7 , V_113 ) ;
V_10 = V_7 -> V_10 ;
V_3 = V_7 -> V_10 -> V_20 ;
if ( ! V_10 -> V_170 ) {
V_43 = & V_7 -> V_112 ;
continue;
}
V_169 = * V_43 & ~ F_26 ( V_9 , V_166 ) ;
* V_43 = V_7 -> V_112 | V_169 ;
V_139 = F_36 ( V_9 , & V_7 -> V_41 ) ;
if ( ( V_139 & V_171 ) == V_130 )
V_40 -> V_84 &= ~ F_26 ( V_9 , V_118 ) ;
else if ( ( V_139 & V_171 ) == V_132 )
V_40 -> V_84 |= F_26 ( V_9 , V_118 ) ;
F_61 ( V_9 , V_10 , V_7 ) ;
V_3 -> V_33 ++ ;
if ( V_3 -> V_33 >= V_3 -> V_5 ) {
V_161 = V_160 = 1 ;
F_5 ( V_9 , V_10 , 0 ) ;
}
}
if ( V_160 && ! F_21 ( & V_40 -> V_113 ) )
goto V_168;
V_40 -> V_53 = V_85 ;
if ( F_29 ( V_9 ) && V_40 -> type == V_25 )
V_9 -> V_56 -- ;
V_40 -> V_84 &= ~ F_26 ( V_9 , V_152 ) ;
V_40 -> V_50 = 0 ;
F_27 () ;
V_40 -> V_41 &= ~ F_26 ( V_9 , V_72 | V_94 ) ;
if ( ! F_21 ( & V_40 -> V_113 ) ) {
if ( V_9 -> V_162 == V_163 )
F_28 ( V_9 , V_40 ) ;
}
if ( V_161 )
goto V_158;
}
if ( V_9 -> V_162 == V_163 && ! V_9 -> V_64 ) {
T_3 V_172 = 0 , V_31 = 0 ;
if ( V_9 -> V_61 ) {
V_172 |= V_133 ;
if ( F_29 ( V_9 ) )
F_75 ( 1 ) ;
if ( ! ( V_9 -> V_27 & V_62 ) ) {
V_31 |= V_62 ;
F_20 ( V_9 , 0 ,
& V_9 -> V_30 -> V_65 ) ;
}
}
if ( V_9 -> V_67 ) {
V_172 |= V_127 ;
if ( F_29 ( V_9 ) )
F_75 ( 1 ) ;
if ( ! ( V_9 -> V_27 & V_68 ) ) {
V_31 |= V_68 ;
F_20 ( V_9 , 0 ,
& V_9 -> V_30 -> V_70 ) ;
}
}
if ( V_31 ) {
V_9 -> V_27 |= V_31 ;
if ( F_29 ( V_9 ) )
F_75 ( 1 ) ;
F_20 ( V_9 , V_9 -> V_27 ,
& V_9 -> V_30 -> V_31 ) ;
}
if ( V_172 ) {
if ( F_29 ( V_9 ) )
F_75 ( 1 ) ;
F_20 ( V_9 , V_172 , & V_9 -> V_30 -> V_128 ) ;
}
}
}
static void F_76 ( struct V_1 * V_9 , struct V_7 * V_7 )
{
struct V_10 * V_10 = V_7 -> V_10 ;
T_1 * V_3 = V_10 -> V_20 ;
struct V_40 * V_40 = V_7 -> V_40 ;
int V_11 ;
V_11 = F_61 ( V_9 , V_10 , V_7 ) ;
V_3 -> V_33 ++ ;
if ( V_3 -> V_33 >= V_3 -> V_5 )
F_5 ( V_9 , V_10 , V_11 ) ;
if ( F_21 ( & V_40 -> V_113 ) ) {
if ( V_40 -> V_53 == V_54 )
F_46 ( V_9 , V_40 ) ;
} else if ( ( V_40 -> V_41 & F_26 ( V_9 , V_72 | V_94 ) )
== F_26 ( V_9 , V_72 ) ) {
V_7 = F_65 ( V_40 -> V_113 . V_150 , struct V_7 , V_113 ) ;
if ( ! ( V_7 -> V_41 & F_26 ( V_9 , V_157 ) ) ) {
V_40 -> V_41 &= ~ F_26 ( V_9 , V_72 ) ;
switch ( V_40 -> type ) {
case V_60 :
F_20 ( V_9 , V_133 ,
& V_9 -> V_30 -> V_128 ) ;
break;
case V_66 :
F_20 ( V_9 , V_127 ,
& V_9 -> V_30 -> V_128 ) ;
break;
}
}
}
}
static void
F_77 ( struct V_1 * V_9 )
{
struct V_7 * V_7 = F_69 ( V_9 ) ;
while ( V_7 ) {
struct V_7 * V_173 = V_7 -> V_108 ;
struct V_40 * V_40 = V_7 -> V_40 ;
for (; ; ) {
struct V_7 * V_174 ;
V_174 = F_22 ( & V_40 -> V_113 , struct V_7 ,
V_113 ) ;
if ( V_174 == V_7 )
break;
F_76 ( V_9 , V_174 ) ;
}
F_76 ( V_9 , V_7 ) ;
V_7 = V_173 ;
}
}
