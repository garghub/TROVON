static int F_1 ( struct V_1 * V_2 , int V_3 )
__releases( V_2 -> V_4 )
__acquires( V_2 -> V_4 )
{
int V_5 = 0 ;
V_2 -> V_6 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
switch ( V_2 -> V_6 & V_9 ) {
case V_10 :
F_3 ( V_2 , L_1 ) ;
V_2 -> V_6 &= ~ V_9 ;
V_2 -> V_6 |= V_11 ;
F_4 ( V_2 , V_2 -> V_6 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
case V_11 :
V_5 = - V_12 ;
F_3 ( V_2 , L_2 ) ;
goto V_13;
case V_14 :
if ( ! V_2 -> V_3 ) {
F_3 ( V_2 , L_3 ) ;
goto V_13;
}
}
F_3 ( V_2 , L_4 ,
V_3 ? L_5 : L_6 ) ;
if ( ! V_3 && ( V_2 -> V_6 & V_15 ) ) {
V_2 -> V_6 &= ~ V_15 ;
F_4 ( V_2 , V_2 -> V_6 , & V_2 -> V_7 -> V_8 ) ;
V_2 -> V_6 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
F_4 ( V_2 , V_16 , & V_2 -> V_7 -> V_17 ) ;
F_3 ( V_2 , L_7 ) ;
V_2 -> V_3 = 0 ;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( 8 ) ;
F_7 ( & V_2 -> V_4 ) ;
}
F_8 ( V_2 ) ;
F_9 ( V_2 , F_10 ( V_2 ) ) ;
if ( F_11 ( V_2 ) -> V_18 . V_19 -> V_20 || V_3 ) {
V_2 -> V_6 |= V_21 ;
} else {
F_4 ( V_2 , V_22 | V_23 ,
& V_2 -> V_7 -> V_24 ) ;
V_2 -> V_6 &= ~ V_21 ;
}
V_2 -> V_6 &= ~ V_9 ;
V_2 -> V_6 |= V_14 ;
F_4 ( V_2 , V_2 -> V_6 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( ! V_3 ) {
V_2 -> V_25 = V_26 + F_12 ( 5 ) ;
V_2 -> V_3 = 0 ;
}
V_13:
return V_5 ;
}
static inline struct V_27 * F_13 ( struct V_27 * V_27 )
{
while ( V_27 -> V_28 )
V_27 = V_27 -> V_28 ;
return V_27 ;
}
static int F_14 ( struct V_1 * V_2 )
__releases( V_2 -> V_4 )
__acquires( V_2 -> V_4 )
{
struct V_29 * V_30 = F_11 ( V_2 ) ;
T_1 V_31 , V_32 ;
int V_5 = - V_33 ;
int V_34 = V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_6 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( V_2 -> V_6 & ( V_35 | V_15 ) ) {
if ( V_30 -> V_36 == V_37 ) {
F_3 ( V_2 , L_8 ,
V_2 -> V_6 ) ;
V_5 = - V_12 ;
} else {
F_3 ( V_2 , L_9 ) ;
V_5 = 0 ;
}
} else switch ( V_2 -> V_6 & V_9 ) {
case V_14 :
V_2 -> V_6 &= ~ ( V_9 | V_15 ) ;
V_2 -> V_6 |= V_10 ;
F_4 ( V_2 , V_2 -> V_6 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
F_3 ( V_2 , L_4 ,
V_34 ? L_10 : L_11 ) ;
break;
case V_10 :
F_3 ( V_2 , L_12 ,
V_34 ? L_13 : L_14 ) ;
break;
case V_38 :
F_3 ( V_2 , L_15 ) ;
V_5 = - V_12 ;
break;
default:
F_3 ( V_2 , L_16 ) ;
V_5 = - V_12 ;
}
if ( V_5 == - V_12 ) {
if ( ! V_34 ) {
F_5 ( & V_2 -> V_4 ) ;
( void ) F_15 ( V_2 ) ;
V_5 = F_16 ( V_2 ) ;
F_17 ( V_30 -> V_18 . V_19 ) ;
F_7 ( & V_2 -> V_4 ) ;
}
return V_5 ;
}
if ( V_5 != - V_33 )
return V_5 ;
if ( V_34 )
goto V_39;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( 20 + 12 + 1 ) ;
V_31 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
V_31 &= V_9 ;
if ( V_31 != V_10 ) {
F_18 ( V_2 , L_17 ) ;
F_7 ( & V_2 -> V_4 ) ;
return - V_12 ;
}
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_40 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_41 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_42 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_43 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_44 ) ;
F_4 ( V_2 , ( T_1 ) V_2 -> V_45 , & V_2 -> V_7 -> V_46 ) ;
F_19 ( V_2 ) ;
V_39:
F_4 ( V_2 , V_47 , & V_2 -> V_7 -> V_48 ) ;
if ( V_2 -> V_49 )
F_4 ( V_2 , V_16 , & V_2 -> V_7 -> V_48 ) ;
F_4 ( V_2 , V_38 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( ! V_34 )
F_6 ( 3 ) ;
V_31 = V_2 -> V_6 ;
V_31 &= V_50 ;
V_31 |= V_51 | V_38 ;
V_2 -> V_6 = V_31 ;
F_4 ( V_2 , V_31 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( ! V_34 ) {
F_6 ( 10 ) ;
F_7 ( & V_2 -> V_4 ) ;
}
V_2 -> V_25 = V_26 + V_52 ;
V_32 = 0 ;
V_31 = 0 ;
if ( ! V_2 -> V_49 ) {
if ( V_2 -> V_53 ) {
F_4 ( V_2 ,
F_13 ( V_2 -> V_53 ) -> V_54 ,
& V_2 -> V_7 -> V_40 ) ;
V_32 |= V_55 ;
V_31 |= V_56 ;
}
if ( V_2 -> V_57 ) {
F_4 ( V_2 , F_13 ( V_2 -> V_57 ) -> V_54 ,
& V_2 -> V_7 -> V_42 ) ;
V_32 |= V_58 ;
V_31 |= V_59 ;
}
}
if ( V_30 -> V_18 . V_60 || V_30 -> V_18 . V_61 )
V_32 |= V_62 | V_63 ;
if ( V_32 ) {
F_3 ( V_2 , L_18 , V_32 ) ;
V_2 -> V_6 |= V_32 ;
F_4 ( V_2 , V_2 -> V_6 , & V_2 -> V_7 -> V_8 ) ;
if ( V_31 )
F_4 ( V_2 , V_31 , & V_2 -> V_7 -> V_64 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
}
return 0 ;
}
static int F_20 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
int V_65 ;
F_7 ( & V_2 -> V_4 ) ;
if ( F_22 ( ! F_23 ( V_30 ) ) )
V_65 = - V_66 ;
else
V_65 = F_1 ( V_2 , 0 ) ;
F_5 ( & V_2 -> V_4 ) ;
return V_65 ;
}
static int F_24 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
int V_65 ;
if ( F_25 ( V_26 , V_2 -> V_25 ) )
F_6 ( 5 ) ;
F_7 ( & V_2 -> V_4 ) ;
if ( F_22 ( ! F_23 ( V_30 ) ) )
V_65 = - V_66 ;
else
V_65 = F_14 ( V_2 ) ;
F_5 ( & V_2 -> V_4 ) ;
if ( V_65 == 0 )
F_26 ( V_30 ) ;
return V_65 ;
}
static void F_27 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
int V_67 ;
bool V_68 = false ;
V_2 -> V_6 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( V_2 -> V_6 & ( V_35 | V_15 ) ) {
V_68 = true ;
} else {
switch ( V_2 -> V_6 & V_9 ) {
case V_38 :
case V_11 :
V_68 = true ;
}
}
if ( V_68 ) {
F_7 ( & V_2 -> V_4 ) ;
V_30 -> V_36 = V_37 ;
F_14 ( V_2 ) ;
V_30 -> V_36 = V_69 ;
F_1 ( V_2 , 0 ) ;
V_30 -> V_36 = V_70 ;
F_5 ( & V_2 -> V_4 ) ;
}
else {
F_3 ( V_2 , L_19 ) ;
for ( V_67 = 0 ; V_67 < V_2 -> V_71 ; V_67 ++ )
F_4 ( V_2 , V_72 ,
& V_2 -> V_7 -> V_73 . V_74 [ V_67 ] ) ;
F_4 ( V_2 , V_75 , & V_2 -> V_7 -> V_48 ) ;
F_2 ( V_2 , & V_2 -> V_7 -> V_48 ) ;
F_6 ( 20 ) ;
}
if ( F_2 ( V_2 , & V_2 -> V_7 -> V_17 ) &
( V_23 | V_22 ) )
F_28 ( V_30 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_76 ,
int V_77 , int V_78 )
{
int V_79 = 1 ;
int V_80 ;
V_80 = F_2 ( V_2 , & V_2 -> V_7 -> V_48 ) &
V_22 ;
switch ( V_2 -> V_6 & V_9 ) {
case V_38 :
if ( ! V_80 && ! V_78 && ! V_76 ) {
V_80 = V_22 ;
F_4 ( V_2 , V_80 , & V_2 -> V_7 -> V_48 ) ;
}
if ( ! V_2 -> V_3 ) {
if ( V_77 ||
! F_30 ( & F_11 ( V_2 )
-> V_18 . V_19 -> V_81 ) ) {
if ( V_80 )
V_79 = 0 ;
} else {
V_2 -> V_3 = 1 ;
V_2 -> V_25 = V_26 + V_82 ;
}
} else {
if ( V_76 || V_77 ) {
V_2 -> V_3 = 0 ;
V_2 -> V_25 = V_26 +
V_52 ;
} else if ( F_31 ( V_26 ,
V_2 -> V_25 )
&& ! V_2 -> V_49
&& ! ( V_2 -> V_6 &
V_15 ) ) {
F_1 ( V_2 , 1 ) ;
if ( V_80 )
V_79 = 0 ;
}
}
break;
case V_14 :
case V_10 :
if ( V_76 ) {
if ( V_2 -> V_3 )
F_14 ( V_2 ) ;
else
F_28 ( F_11 ( V_2 ) ) ;
} else if ( ! V_2 -> V_3 &&
! F_11 ( V_2 ) -> V_18 . V_19 ->
V_20 ) {
V_79 = 0 ;
} else {
if ( ! V_80 && ! V_78 ) {
V_80 = V_22 ;
F_4 ( V_2 , V_80 ,
& V_2 -> V_7 -> V_48 ) ;
}
if ( V_80 )
V_79 = 0 ;
}
break;
}
return V_79 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_76 ,
int V_77 , int V_78 )
{
if ( F_2 ( V_2 , & V_2 -> V_7 -> V_48 ) & V_22 )
return 0 ;
if ( V_76 || V_78 )
return 1 ;
F_4 ( V_2 , V_22 , & V_2 -> V_7 -> V_48 ) ;
return 0 ;
}
static int
F_32 ( struct V_29 * V_30 , char * V_83 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
int V_84 , V_76 = 0 , V_85 = 1 ;
int V_77 = 0 ;
int V_78 ;
unsigned long V_86 ;
F_33 ( & V_2 -> V_4 , V_86 ) ;
if ( ! F_23 ( V_30 ) )
goto V_13;
if ( ( V_2 -> V_86 & V_87 )
&& ( F_34 ( V_2 ) & V_88 ) > V_89 ) {
F_35 ( V_2 , L_20 ,
F_2 ( V_2 , & V_2 -> V_7 -> V_73 . V_90 ) & V_88 ) ;
goto V_13;
}
if ( F_36 ( V_2 ) & ( V_91 | V_92 ) )
V_83 [ 0 ] = V_76 = 1 ;
else
V_83 [ 0 ] = 0 ;
if ( V_2 -> V_71 > 7 ) {
V_83 [ 1 ] = 0 ;
V_85 ++ ;
}
F_4 ( V_2 , V_22 , & V_2 -> V_7 -> V_17 ) ;
V_78 = F_2 ( V_2 , & V_2 -> V_7 -> V_17 ) &
V_22 ;
for ( V_84 = 0 ; V_84 < V_2 -> V_71 ; V_84 ++ ) {
T_1 V_5 = F_37 ( V_2 , V_84 ) ;
V_77 |= ( V_5 & V_93 ) ;
if ( V_5 & ( V_94 | V_95 | V_96
| V_97 | V_98 ) ) {
V_76 = 1 ;
if ( V_84 < 7 )
V_83 [ 0 ] |= 1 << ( V_84 + 1 ) ;
else
V_83 [ 1 ] |= 1 << ( V_84 - 7 ) ;
}
}
if ( F_29 ( V_2 , V_76 ,
V_77 , V_78 ) )
F_38 ( V_99 , & V_30 -> V_86 ) ;
else
F_39 ( V_99 , & V_30 -> V_86 ) ;
V_13:
F_40 ( & V_2 -> V_4 , V_86 ) ;
return V_76 ? V_85 : 0 ;
}
static void
F_41 (
struct V_1 * V_2 ,
struct V_100 * V_101
) {
T_1 V_102 = F_34 ( V_2 ) ;
T_2 V_31 ;
V_101 -> V_103 = 0x29 ;
V_101 -> V_104 = ( V_102 & V_105 ) >> 24 ;
V_101 -> V_106 = 0 ;
V_101 -> V_107 = V_2 -> V_71 ;
V_31 = 1 + ( V_2 -> V_71 / 8 ) ;
V_101 -> V_108 = 7 + 2 * V_31 ;
V_31 = 0 ;
if ( V_102 & V_109 )
V_31 |= 0x0002 ;
if ( V_102 & V_110 )
V_31 |= 0x0001 ;
if ( V_102 & V_111 )
V_31 |= 0x0010 ;
else if ( V_102 & V_112 )
V_31 |= 0x0008 ;
V_101 -> V_113 = ( V_114 V_115 ) F_42 ( V_2 , V_31 ) ;
V_102 = F_43 ( V_2 ) ;
memset ( V_101 -> V_116 . V_117 . V_118 , 0xff ,
sizeof( V_101 -> V_116 . V_117 . V_118 ) ) ;
V_101 -> V_116 . V_117 . V_118 [ 0 ] = V_102 & V_119 ;
if ( V_2 -> V_71 > 7 ) {
V_101 -> V_116 . V_117 . V_118 [ 1 ] = ( V_102 & V_119 ) >> 8 ;
V_101 -> V_116 . V_117 . V_118 [ 2 ] = 0xff ;
} else
V_101 -> V_116 . V_117 . V_118 [ 1 ] = 0xff ;
}
static int F_44 ( struct V_29 * V_30 , unsigned V_67 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
T_1 V_5 ;
if ( ! V_67 )
return - V_120 ;
V_67 -- ;
V_5 = F_2 ( V_2 , & V_2 -> V_7 -> V_73 . V_74 [ V_67 ] ) ;
if ( ! ( V_5 & V_93 ) )
return - V_121 ;
F_4 ( V_2 , V_122 , & V_2 -> V_7 -> V_73 . V_74 [ V_67 ] ) ;
return 0 ;
}
static inline int F_45 ( struct V_1 * V_2 , unsigned V_67 )
{
T_3 T_4 * V_123 = & V_2 -> V_7 -> V_73 . V_74 [ V_67 ] ;
T_1 V_31 = 0 ;
T_2 V_124 = F_2 ( V_2 , & V_2 -> V_7 -> V_125 ) ;
T_2 V_126 = V_124 + V_127 ;
int V_128 = F_46 ( V_127 , V_129 ) ;
do {
int V_130 ;
V_130 = V_129 * 2 ;
while ( -- V_130 >= 0 ) {
V_31 = F_2 ( V_2 , V_123 ) ;
if ( V_31 == ~ ( T_1 ) 0 )
return - V_66 ;
if ( ! ( V_31 & V_122 ) )
break;
F_47 ( 500 ) ;
}
if ( V_130 < 0 ) {
F_3 ( V_2 ,
L_21 ,
V_67 , V_31 ) ;
break;
}
if ( ! ( V_31 & V_93 ) )
break;
if ( V_31 & V_98 )
F_4 ( V_2 , V_98 , V_123 ) ;
F_4 ( V_2 , V_122 , V_123 ) ;
F_6 ( V_129 ) ;
V_124 = F_2 ( V_2 , & V_2 -> V_7 -> V_125 ) ;
} while ( F_48 ( V_124 , V_126 ) && -- V_128 >= 0 );
return 0 ;
}
static int F_49 (
struct V_29 * V_30 ,
T_2 V_131 ,
T_2 V_132 ,
T_2 V_133 ,
char * V_83 ,
T_2 V_134
) {
struct V_1 * V_2 = F_21 ( V_30 ) ;
int V_135 = V_2 -> V_71 ;
T_1 V_31 ;
int V_136 = 0 ;
if ( F_22 ( ! F_23 ( V_30 ) ) )
return - V_66 ;
switch ( V_131 ) {
case V_137 :
switch ( V_132 ) {
case V_138 :
F_4 ( V_2 , V_92 ,
& V_2 -> V_7 -> V_73 . V_5 ) ;
case V_139 :
break;
default:
goto error;
}
break;
case V_140 :
if ( ! V_133 || V_133 > V_135 )
goto error;
V_133 -- ;
switch ( V_132 ) {
case V_141 :
V_31 = V_93 ;
break;
case V_142 :
V_31 = V_95 ;
break;
case V_143 :
V_31 = V_144 ;
break;
case V_145 :
V_31 = V_96 ;
break;
case V_146 :
V_31 = V_147 ;
break;
case V_148 :
V_31 = V_94 ;
break;
case V_149 :
V_31 = V_97 ;
break;
case V_150 :
V_31 = V_98 ;
break;
default:
goto error;
}
F_4 ( V_2 , V_31 ,
& V_2 -> V_7 -> V_73 . V_74 [ V_133 ] ) ;
break;
case V_151 :
F_41 ( V_2 , (struct V_100 * ) V_83 ) ;
break;
case V_152 :
V_31 = F_36 ( V_2 ) & ~ ( V_153 | V_154 ) ;
F_50 ( V_31 , V_83 ) ;
break;
case V_155 :
if ( ! V_133 || V_133 > V_135 )
goto error;
V_133 -- ;
V_31 = F_37 ( V_2 , V_133 ) ;
F_50 ( V_31 , V_83 ) ;
#ifndef F_51
if ( * ( T_2 * ) ( V_83 + 2 ) )
#endif
F_52 ( V_2 , L_22 , V_133 , V_31 ) ;
break;
case V_156 :
switch ( V_132 ) {
case V_138 :
case V_139 :
break;
default:
goto error;
}
break;
case V_157 :
if ( ! V_133 || V_133 > V_135 )
goto error;
V_133 -- ;
switch ( V_132 ) {
case V_143 :
#ifdef F_53
if ( V_30 -> V_18 . V_158 == ( V_133 + 1 )
&& V_30 -> V_18 . V_159 )
V_2 -> V_160 ( V_2 ) ;
else
#endif
F_4 ( V_2 , V_161 ,
& V_2 -> V_7 -> V_73 . V_74 [ V_133 ] ) ;
break;
case V_146 :
F_4 ( V_2 , V_72 ,
& V_2 -> V_7 -> V_73 . V_74 [ V_133 ] ) ;
break;
case V_162 :
V_136 = F_45 ( V_2 , V_133 ) ;
break;
default:
goto error;
}
break;
default:
error:
V_136 = - V_163 ;
}
return V_136 ;
}
