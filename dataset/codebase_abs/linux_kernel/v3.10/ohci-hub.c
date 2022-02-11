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
V_2 -> V_27 = V_28 ;
}
V_13:
return V_5 ;
}
static inline struct V_29 * F_13 ( struct V_29 * V_29 )
{
while ( V_29 -> V_30 )
V_29 = V_29 -> V_30 ;
return V_29 ;
}
static int F_14 ( struct V_1 * V_2 )
__releases( V_2 -> V_4 )
__acquires( V_2 -> V_4 )
{
struct V_31 * V_32 = F_11 ( V_2 ) ;
T_1 V_33 , V_34 ;
int V_5 = - V_35 ;
int V_36 = V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_6 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( V_2 -> V_6 & ( V_37 | V_15 ) ) {
if ( V_2 -> V_27 != V_38 ) {
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
V_36 ? L_10 : L_11 ) ;
break;
case V_10 :
F_3 ( V_2 , L_12 ,
V_36 ? L_13 : L_14 ) ;
break;
case V_39 :
F_3 ( V_2 , L_15 ) ;
V_5 = - V_12 ;
break;
default:
F_3 ( V_2 , L_16 ) ;
V_5 = - V_12 ;
}
if ( V_5 == - V_12 ) {
if ( ! V_36 ) {
F_5 ( & V_2 -> V_4 ) ;
( void ) F_15 ( V_2 ) ;
V_5 = F_16 ( V_2 ) ;
F_17 ( V_32 -> V_18 . V_19 ) ;
F_7 ( & V_2 -> V_4 ) ;
}
return V_5 ;
}
if ( V_5 != - V_35 )
return V_5 ;
if ( V_36 )
goto V_40;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( 20 + 12 + 1 ) ;
V_33 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
V_33 &= V_9 ;
if ( V_33 != V_10 ) {
F_18 ( V_2 , L_17 ) ;
F_7 ( & V_2 -> V_4 ) ;
return - V_12 ;
}
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_41 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_42 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_43 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_44 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_45 ) ;
F_4 ( V_2 , ( T_1 ) V_2 -> V_46 , & V_2 -> V_7 -> V_47 ) ;
F_19 ( V_2 ) ;
V_40:
F_4 ( V_2 , V_48 , & V_2 -> V_7 -> V_49 ) ;
if ( V_2 -> V_50 )
F_4 ( V_2 , V_16 , & V_2 -> V_7 -> V_49 ) ;
F_4 ( V_2 , V_39 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( ! V_36 )
F_6 ( 3 ) ;
V_33 = V_2 -> V_6 ;
V_33 &= V_51 ;
V_33 |= V_52 | V_39 ;
V_2 -> V_6 = V_33 ;
F_4 ( V_2 , V_33 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( ! V_36 ) {
F_6 ( 10 ) ;
F_7 ( & V_2 -> V_4 ) ;
}
V_2 -> V_25 = V_26 + V_53 ;
V_34 = 0 ;
V_33 = 0 ;
if ( ! V_2 -> V_50 ) {
if ( V_2 -> V_54 ) {
F_4 ( V_2 ,
F_13 ( V_2 -> V_54 ) -> V_55 ,
& V_2 -> V_7 -> V_41 ) ;
V_34 |= V_56 ;
V_33 |= V_57 ;
}
if ( V_2 -> V_58 ) {
F_4 ( V_2 , F_13 ( V_2 -> V_58 ) -> V_55 ,
& V_2 -> V_7 -> V_43 ) ;
V_34 |= V_59 ;
V_33 |= V_60 ;
}
}
if ( V_32 -> V_18 . V_61 || V_32 -> V_18 . V_62 )
V_34 |= V_63 | V_64 ;
if ( V_34 ) {
F_3 ( V_2 , L_18 , V_34 ) ;
V_2 -> V_6 |= V_34 ;
F_4 ( V_2 , V_2 -> V_6 , & V_2 -> V_7 -> V_8 ) ;
if ( V_33 )
F_4 ( V_2 , V_33 , & V_2 -> V_7 -> V_65 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
}
V_2 -> V_27 = V_38 ;
return 0 ;
}
static int F_20 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
int V_66 ;
F_7 ( & V_2 -> V_4 ) ;
if ( F_22 ( ! F_23 ( V_32 ) ) )
V_66 = - V_67 ;
else
V_66 = F_1 ( V_2 , 0 ) ;
F_5 ( & V_2 -> V_4 ) ;
return V_66 ;
}
static int F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
int V_66 ;
if ( F_25 ( V_26 , V_2 -> V_25 ) )
F_6 ( 5 ) ;
F_7 ( & V_2 -> V_4 ) ;
if ( F_22 ( ! F_23 ( V_32 ) ) )
V_66 = - V_67 ;
else
V_66 = F_14 ( V_2 ) ;
F_5 ( & V_2 -> V_4 ) ;
if ( V_66 == 0 )
F_26 ( V_32 ) ;
return V_66 ;
}
static int F_27 ( struct V_1 * V_2 , int V_68 ,
int V_69 , int V_70 )
{
int V_71 = 1 ;
int V_72 ;
V_72 = F_2 ( V_2 , & V_2 -> V_7 -> V_49 ) &
V_22 ;
switch ( V_2 -> V_6 & V_9 ) {
case V_39 :
if ( ! V_72 && ! V_70 && ! V_68 ) {
V_72 = V_22 ;
F_4 ( V_2 , V_72 , & V_2 -> V_7 -> V_49 ) ;
}
if ( ! V_2 -> V_3 ) {
if ( V_69 ||
! F_28 ( & F_11 ( V_2 )
-> V_18 . V_19 -> V_73 ) ) {
if ( V_72 )
V_71 = 0 ;
} else {
V_2 -> V_3 = 1 ;
V_2 -> V_25 = V_26 + V_74 ;
}
} else {
if ( V_68 || V_69 ) {
V_2 -> V_3 = 0 ;
V_2 -> V_25 = V_26 +
V_53 ;
} else if ( F_29 ( V_26 ,
V_2 -> V_25 )
&& ! V_2 -> V_50
&& ! ( V_2 -> V_6 &
V_15 ) ) {
F_1 ( V_2 , 1 ) ;
if ( V_72 )
V_71 = 0 ;
}
}
break;
case V_14 :
case V_10 :
if ( V_68 ) {
if ( V_2 -> V_3 )
F_14 ( V_2 ) ;
else
F_30 ( F_11 ( V_2 ) ) ;
} else if ( ! V_2 -> V_3 &&
! F_11 ( V_2 ) -> V_18 . V_19 ->
V_20 ) {
V_71 = 0 ;
} else {
if ( ! V_72 && ! V_70 ) {
V_72 = V_22 ;
F_4 ( V_2 , V_72 ,
& V_2 -> V_7 -> V_49 ) ;
}
if ( V_72 )
V_71 = 0 ;
}
break;
}
return V_71 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_68 ,
int V_69 , int V_70 )
{
if ( F_2 ( V_2 , & V_2 -> V_7 -> V_49 ) & V_22 )
return 0 ;
if ( V_68 || V_70 )
return 1 ;
F_4 ( V_2 , V_22 , & V_2 -> V_7 -> V_49 ) ;
return 0 ;
}
static int
F_31 ( struct V_31 * V_32 , char * V_75 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
int V_76 , V_68 = 0 , V_77 = 1 ;
int V_69 = 0 ;
int V_70 ;
unsigned long V_78 ;
F_32 ( & V_2 -> V_4 , V_78 ) ;
if ( ! F_23 ( V_32 ) )
goto V_13;
if ( ( V_2 -> V_78 & V_79 )
&& ( F_33 ( V_2 ) & V_80 ) > V_81 ) {
F_34 ( V_2 , L_19 ,
F_2 ( V_2 , & V_2 -> V_7 -> V_82 . V_83 ) & V_80 ) ;
goto V_13;
}
if ( F_35 ( V_2 ) & ( V_84 | V_85 ) )
V_75 [ 0 ] = V_68 = 1 ;
else
V_75 [ 0 ] = 0 ;
if ( V_2 -> V_86 > 7 ) {
V_75 [ 1 ] = 0 ;
V_77 ++ ;
}
F_4 ( V_2 , V_22 , & V_2 -> V_7 -> V_17 ) ;
V_70 = F_2 ( V_2 , & V_2 -> V_7 -> V_17 ) &
V_22 ;
for ( V_76 = 0 ; V_76 < V_2 -> V_86 ; V_76 ++ ) {
T_1 V_5 = F_36 ( V_2 , V_76 ) ;
V_69 |= ( V_5 & V_87 ) ;
if ( V_5 & ( V_88 | V_89 | V_90
| V_91 | V_92 ) ) {
V_68 = 1 ;
if ( V_76 < 7 )
V_75 [ 0 ] |= 1 << ( V_76 + 1 ) ;
else
V_75 [ 1 ] |= 1 << ( V_76 - 7 ) ;
}
}
if ( F_27 ( V_2 , V_68 ,
V_69 , V_70 ) )
F_37 ( V_93 , & V_32 -> V_78 ) ;
else
F_38 ( V_93 , & V_32 -> V_78 ) ;
V_13:
F_39 ( & V_2 -> V_4 , V_78 ) ;
return V_68 ? V_77 : 0 ;
}
static void
F_40 (
struct V_1 * V_2 ,
struct V_94 * V_95
) {
T_1 V_96 = F_33 ( V_2 ) ;
T_2 V_33 ;
V_95 -> V_97 = 0x29 ;
V_95 -> V_98 = ( V_96 & V_99 ) >> 24 ;
V_95 -> V_100 = 0 ;
V_95 -> V_101 = V_2 -> V_86 ;
V_33 = 1 + ( V_2 -> V_86 / 8 ) ;
V_95 -> V_102 = 7 + 2 * V_33 ;
V_33 = 0 ;
if ( V_96 & V_103 )
V_33 |= 0x0002 ;
if ( V_96 & V_104 )
V_33 |= 0x0001 ;
if ( V_96 & V_105 )
V_33 |= 0x0010 ;
else if ( V_96 & V_106 )
V_33 |= 0x0008 ;
V_95 -> V_107 = ( V_108 V_109 ) F_41 ( V_2 , V_33 ) ;
V_96 = F_42 ( V_2 ) ;
memset ( V_95 -> V_110 . V_111 . V_112 , 0xff ,
sizeof( V_95 -> V_110 . V_111 . V_112 ) ) ;
V_95 -> V_110 . V_111 . V_112 [ 0 ] = V_96 & V_113 ;
if ( V_2 -> V_86 > 7 ) {
V_95 -> V_110 . V_111 . V_112 [ 1 ] = ( V_96 & V_113 ) >> 8 ;
V_95 -> V_110 . V_111 . V_112 [ 2 ] = 0xff ;
} else
V_95 -> V_110 . V_111 . V_112 [ 1 ] = 0xff ;
}
static int F_43 ( struct V_31 * V_32 , unsigned V_114 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
T_1 V_5 ;
if ( ! V_114 )
return - V_115 ;
V_114 -- ;
V_5 = F_2 ( V_2 , & V_2 -> V_7 -> V_82 . V_116 [ V_114 ] ) ;
if ( ! ( V_5 & V_87 ) )
return - V_117 ;
F_4 ( V_2 , V_118 , & V_2 -> V_7 -> V_82 . V_116 [ V_114 ] ) ;
return 0 ;
}
static inline int F_44 ( struct V_1 * V_2 , unsigned V_114 )
{
T_3 T_4 * V_119 = & V_2 -> V_7 -> V_82 . V_116 [ V_114 ] ;
T_1 V_33 = 0 ;
T_2 V_120 = F_2 ( V_2 , & V_2 -> V_7 -> V_121 ) ;
T_2 V_122 = V_120 + V_123 ;
int V_124 = F_45 ( V_123 , V_125 ) ;
do {
int V_126 ;
V_126 = V_125 * 2 ;
while ( -- V_126 >= 0 ) {
V_33 = F_2 ( V_2 , V_119 ) ;
if ( V_33 == ~ ( T_1 ) 0 )
return - V_67 ;
if ( ! ( V_33 & V_118 ) )
break;
F_46 ( 500 ) ;
}
if ( V_126 < 0 ) {
F_3 ( V_2 ,
L_20 ,
V_114 , V_33 ) ;
break;
}
if ( ! ( V_33 & V_87 ) )
break;
if ( V_33 & V_92 )
F_4 ( V_2 , V_92 , V_119 ) ;
F_4 ( V_2 , V_118 , V_119 ) ;
F_6 ( V_125 ) ;
V_120 = F_2 ( V_2 , & V_2 -> V_7 -> V_121 ) ;
} while ( F_47 ( V_120 , V_122 ) && -- V_124 >= 0 );
return 0 ;
}
static int F_48 (
struct V_31 * V_32 ,
T_2 V_127 ,
T_2 V_128 ,
T_2 V_129 ,
char * V_75 ,
T_2 V_130
) {
struct V_1 * V_2 = F_21 ( V_32 ) ;
int V_131 = V_2 -> V_86 ;
T_1 V_33 ;
int V_132 = 0 ;
if ( F_22 ( ! F_23 ( V_32 ) ) )
return - V_67 ;
switch ( V_127 ) {
case V_133 :
switch ( V_128 ) {
case V_134 :
F_4 ( V_2 , V_85 ,
& V_2 -> V_7 -> V_82 . V_5 ) ;
case V_135 :
break;
default:
goto error;
}
break;
case V_136 :
if ( ! V_129 || V_129 > V_131 )
goto error;
V_129 -- ;
switch ( V_128 ) {
case V_137 :
V_33 = V_87 ;
break;
case V_138 :
V_33 = V_89 ;
break;
case V_139 :
V_33 = V_140 ;
break;
case V_141 :
V_33 = V_90 ;
break;
case V_142 :
V_33 = V_143 ;
break;
case V_144 :
V_33 = V_88 ;
break;
case V_145 :
V_33 = V_91 ;
break;
case V_146 :
V_33 = V_92 ;
break;
default:
goto error;
}
F_4 ( V_2 , V_33 ,
& V_2 -> V_7 -> V_82 . V_116 [ V_129 ] ) ;
break;
case V_147 :
F_40 ( V_2 , (struct V_94 * ) V_75 ) ;
break;
case V_148 :
V_33 = F_35 ( V_2 ) & ~ ( V_149 | V_150 ) ;
F_49 ( V_33 , V_75 ) ;
break;
case V_151 :
if ( ! V_129 || V_129 > V_131 )
goto error;
V_129 -- ;
V_33 = F_36 ( V_2 , V_129 ) ;
F_49 ( V_33 , V_75 ) ;
#ifndef F_50
if ( * ( T_2 * ) ( V_75 + 2 ) )
#endif
F_51 ( V_2 , L_21 , V_129 , V_33 ) ;
break;
case V_152 :
switch ( V_128 ) {
case V_134 :
case V_135 :
break;
default:
goto error;
}
break;
case V_153 :
if ( ! V_129 || V_129 > V_131 )
goto error;
V_129 -- ;
switch ( V_128 ) {
case V_139 :
#ifdef F_52
if ( V_32 -> V_18 . V_154 == ( V_129 + 1 )
&& V_32 -> V_18 . V_155 )
V_2 -> V_156 ( V_2 ) ;
else
#endif
F_4 ( V_2 , V_157 ,
& V_2 -> V_7 -> V_82 . V_116 [ V_129 ] ) ;
break;
case V_142 :
F_4 ( V_2 , V_158 ,
& V_2 -> V_7 -> V_82 . V_116 [ V_129 ] ) ;
break;
case V_159 :
V_132 = F_44 ( V_2 , V_129 ) ;
break;
default:
goto error;
}
break;
default:
error:
V_132 = - V_160 ;
}
return V_132 ;
}
