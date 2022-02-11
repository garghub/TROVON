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
F_9 ( V_2 ) ;
if ( V_2 -> V_18 & V_19 ) {
T_1 T_2 * V_20 = V_2 -> V_7 -> V_21 . V_22 ;
int V_23 ;
unsigned V_24 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_25 ; ( ++ V_23 , ++ V_20 ) ) {
V_24 = F_2 ( V_2 , V_20 ) ;
if ( ( V_24 & ( V_26 | V_27 ) ) ==
V_26 )
F_4 ( V_2 , V_27 , V_20 ) ;
}
}
if ( F_10 ( V_2 ) -> V_28 . V_29 -> V_30 || V_3 ) {
V_2 -> V_6 |= V_31 ;
} else {
F_4 ( V_2 , V_32 | V_33 ,
& V_2 -> V_7 -> V_34 ) ;
V_2 -> V_6 &= ~ V_31 ;
}
V_2 -> V_6 &= ~ V_9 ;
V_2 -> V_6 |= V_14 ;
F_4 ( V_2 , V_2 -> V_6 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( ! V_3 ) {
V_2 -> V_35 = V_36 + F_11 ( 5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_37 = V_38 ;
}
V_13:
return V_5 ;
}
static inline struct V_39 * F_12 ( struct V_39 * V_39 )
{
while ( V_39 -> V_40 )
V_39 = V_39 -> V_40 ;
return V_39 ;
}
static int F_13 ( struct V_1 * V_2 )
__releases( V_2 -> V_4 )
__acquires( V_2 -> V_4 )
{
struct V_41 * V_42 = F_10 ( V_2 ) ;
T_3 V_24 , V_43 ;
int V_5 = - V_44 ;
int V_45 = V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_6 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( V_2 -> V_6 & ( V_46 | V_15 ) ) {
if ( V_2 -> V_37 != V_47 ) {
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
V_45 ? L_10 : L_11 ) ;
break;
case V_10 :
F_3 ( V_2 , L_12 ,
V_45 ? L_13 : L_14 ) ;
break;
case V_48 :
F_3 ( V_2 , L_15 ) ;
V_5 = - V_12 ;
break;
default:
F_3 ( V_2 , L_16 ) ;
V_5 = - V_12 ;
}
if ( V_5 == - V_12 ) {
if ( ! V_45 ) {
F_5 ( & V_2 -> V_4 ) ;
V_5 = F_14 ( V_2 ) ;
F_15 ( V_42 -> V_28 . V_29 ) ;
F_7 ( & V_2 -> V_4 ) ;
}
return V_5 ;
}
if ( V_5 != - V_44 )
return V_5 ;
if ( V_45 )
goto V_49;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( 20 + 12 + 1 ) ;
V_24 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
V_24 &= V_9 ;
if ( V_24 != V_10 ) {
F_16 ( V_2 , L_17 ) ;
F_7 ( & V_2 -> V_4 ) ;
return - V_12 ;
}
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_50 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_51 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_52 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_53 ) ;
F_4 ( V_2 , 0 , & V_2 -> V_7 -> V_54 ) ;
F_4 ( V_2 , ( T_3 ) V_2 -> V_55 , & V_2 -> V_7 -> V_56 ) ;
F_17 ( V_2 ) ;
V_49:
F_4 ( V_2 , V_57 , & V_2 -> V_7 -> V_58 ) ;
if ( V_2 -> V_59 )
F_4 ( V_2 , V_16 , & V_2 -> V_7 -> V_58 ) ;
F_4 ( V_2 , V_48 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( ! V_45 )
F_6 ( 3 ) ;
V_24 = V_2 -> V_6 ;
V_24 &= V_60 ;
V_24 |= V_61 | V_48 ;
V_2 -> V_6 = V_24 ;
F_4 ( V_2 , V_24 , & V_2 -> V_7 -> V_8 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( ! V_45 ) {
F_6 ( 10 ) ;
F_7 ( & V_2 -> V_4 ) ;
}
V_2 -> V_35 = V_36 + V_62 ;
V_43 = 0 ;
V_24 = 0 ;
if ( ! V_2 -> V_59 ) {
if ( V_2 -> V_63 ) {
F_4 ( V_2 ,
F_12 ( V_2 -> V_63 ) -> V_64 ,
& V_2 -> V_7 -> V_50 ) ;
V_43 |= V_65 ;
V_24 |= V_66 ;
}
if ( V_2 -> V_67 ) {
F_4 ( V_2 , F_12 ( V_2 -> V_67 ) -> V_64 ,
& V_2 -> V_7 -> V_52 ) ;
V_43 |= V_68 ;
V_24 |= V_69 ;
}
}
if ( V_42 -> V_28 . V_70 || V_42 -> V_28 . V_71 )
V_43 |= V_72 | V_73 ;
if ( V_43 ) {
F_3 ( V_2 , L_18 , V_43 ) ;
V_2 -> V_6 |= V_43 ;
F_4 ( V_2 , V_2 -> V_6 , & V_2 -> V_7 -> V_8 ) ;
if ( V_24 )
F_4 ( V_2 , V_24 , & V_2 -> V_7 -> V_74 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
}
V_2 -> V_37 = V_47 ;
return 0 ;
}
static int F_18 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_19 ( V_42 ) ;
int V_75 ;
F_7 ( & V_2 -> V_4 ) ;
if ( F_20 ( ! F_21 ( V_42 ) ) )
V_75 = - V_76 ;
else
V_75 = F_1 ( V_2 , 0 ) ;
F_5 ( & V_2 -> V_4 ) ;
if ( V_75 == 0 )
F_22 ( & V_2 -> V_77 ) ;
return V_75 ;
}
static int F_23 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_19 ( V_42 ) ;
int V_75 ;
if ( F_24 ( V_36 , V_2 -> V_35 ) )
F_6 ( 5 ) ;
F_7 ( & V_2 -> V_4 ) ;
if ( F_20 ( ! F_21 ( V_42 ) ) )
V_75 = - V_76 ;
else
V_75 = F_13 ( V_2 ) ;
F_5 ( & V_2 -> V_4 ) ;
if ( V_75 == 0 )
F_25 ( V_42 ) ;
return V_75 ;
}
static int F_26 ( struct V_1 * V_2 , int V_78 ,
int V_79 , int V_80 )
{
int V_81 = 1 ;
int V_82 ;
V_82 = F_2 ( V_2 , & V_2 -> V_7 -> V_58 ) &
V_32 ;
switch ( V_2 -> V_6 & V_9 ) {
case V_48 :
if ( ! V_82 && ! V_80 && ! V_78 ) {
V_82 = V_32 ;
F_4 ( V_2 , V_82 , & V_2 -> V_7 -> V_58 ) ;
}
if ( ! V_2 -> V_3 ) {
if ( V_79 ||
! F_27 ( & F_10 ( V_2 )
-> V_28 . V_29 -> V_83 ) ) {
if ( V_82 )
V_81 = 0 ;
} else {
V_2 -> V_3 = 1 ;
V_2 -> V_35 = V_36 + V_84 ;
}
} else {
if ( V_78 || V_79 ) {
V_2 -> V_3 = 0 ;
V_2 -> V_35 = V_36 +
V_62 ;
} else if ( F_28 ( V_36 ,
V_2 -> V_35 )
&& ! V_2 -> V_59
&& ! ( V_2 -> V_6 &
V_15 ) ) {
F_1 ( V_2 , 1 ) ;
if ( V_82 )
V_81 = 0 ;
}
}
break;
case V_14 :
case V_10 :
if ( V_78 ) {
if ( V_2 -> V_3 )
F_13 ( V_2 ) ;
else
F_29 ( F_10 ( V_2 ) ) ;
} else if ( ! V_2 -> V_3 &&
! F_10 ( V_2 ) -> V_28 . V_29 ->
V_30 ) {
V_81 = 0 ;
} else {
if ( ! V_82 && ! V_80 ) {
V_82 = V_32 ;
F_4 ( V_2 , V_82 ,
& V_2 -> V_7 -> V_58 ) ;
}
if ( V_82 )
V_81 = 0 ;
}
break;
}
return V_81 ;
}
static inline int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_78 ,
int V_79 , int V_80 )
{
if ( F_2 ( V_2 , & V_2 -> V_7 -> V_58 ) & V_32 )
return 0 ;
if ( V_78 || V_80 )
return 1 ;
F_4 ( V_2 , V_32 , & V_2 -> V_7 -> V_58 ) ;
return 0 ;
}
int F_30 ( struct V_41 * V_42 , char * V_85 )
{
struct V_1 * V_2 = F_19 ( V_42 ) ;
int V_23 , V_78 = 0 , V_86 = 1 ;
int V_79 = 0 ;
int V_80 ;
unsigned long V_18 ;
F_31 ( & V_2 -> V_4 , V_18 ) ;
if ( ! F_21 ( V_42 ) )
goto V_13;
if ( ( V_2 -> V_18 & V_87 )
&& ( F_32 ( V_2 ) & V_88 ) > V_89 ) {
F_33 ( V_2 , L_19 ,
F_2 ( V_2 , & V_2 -> V_7 -> V_21 . V_90 ) & V_88 ) ;
goto V_13;
}
if ( F_34 ( V_2 ) & ( V_91 | V_92 ) )
V_85 [ 0 ] = V_78 = 1 ;
else
V_85 [ 0 ] = 0 ;
if ( V_2 -> V_25 > 7 ) {
V_85 [ 1 ] = 0 ;
V_86 ++ ;
}
F_4 ( V_2 , V_32 , & V_2 -> V_7 -> V_17 ) ;
V_80 = F_2 ( V_2 , & V_2 -> V_7 -> V_17 ) &
V_32 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_25 ; V_23 ++ ) {
T_3 V_5 = F_35 ( V_2 , V_23 ) ;
V_79 |= ( V_5 & V_93 ) ;
if ( V_5 & ( V_94 | V_95 | V_96
| V_97 | V_98 ) ) {
V_78 = 1 ;
if ( V_23 < 7 )
V_85 [ 0 ] |= 1 << ( V_23 + 1 ) ;
else
V_85 [ 1 ] |= 1 << ( V_23 - 7 ) ;
}
}
if ( F_26 ( V_2 , V_78 ,
V_79 , V_80 ) )
F_36 ( V_99 , & V_42 -> V_18 ) ;
else
F_37 ( V_99 , & V_42 -> V_18 ) ;
V_13:
F_38 ( & V_2 -> V_4 , V_18 ) ;
return V_78 ? V_86 : 0 ;
}
static void
F_39 (
struct V_1 * V_2 ,
struct V_100 * V_101
) {
T_3 V_102 = F_32 ( V_2 ) ;
T_4 V_24 ;
V_101 -> V_103 = 0x29 ;
V_101 -> V_104 = ( V_102 & V_105 ) >> 24 ;
V_101 -> V_106 = 0 ;
V_101 -> V_107 = V_2 -> V_25 ;
V_24 = 1 + ( V_2 -> V_25 / 8 ) ;
V_101 -> V_108 = 7 + 2 * V_24 ;
V_24 = 0 ;
if ( V_102 & V_109 )
V_24 |= 0x0002 ;
if ( V_102 & V_110 )
V_24 |= 0x0001 ;
if ( V_102 & V_111 )
V_24 |= 0x0010 ;
else if ( V_102 & V_112 )
V_24 |= 0x0008 ;
V_101 -> V_113 = F_40 ( V_24 ) ;
V_102 = F_41 ( V_2 ) ;
memset ( V_101 -> V_114 . V_115 . V_116 , 0xff ,
sizeof( V_101 -> V_114 . V_115 . V_116 ) ) ;
V_101 -> V_114 . V_115 . V_116 [ 0 ] = V_102 & V_117 ;
if ( V_2 -> V_25 > 7 ) {
V_101 -> V_114 . V_115 . V_116 [ 1 ] = ( V_102 & V_117 ) >> 8 ;
V_101 -> V_114 . V_115 . V_116 [ 2 ] = 0xff ;
} else
V_101 -> V_114 . V_115 . V_116 [ 1 ] = 0xff ;
}
static int F_42 ( struct V_41 * V_42 , unsigned V_118 )
{
struct V_1 * V_2 = F_19 ( V_42 ) ;
T_3 V_5 ;
if ( ! V_118 )
return - V_119 ;
V_118 -- ;
V_5 = F_2 ( V_2 , & V_2 -> V_7 -> V_21 . V_22 [ V_118 ] ) ;
if ( ! ( V_5 & V_93 ) )
return - V_120 ;
F_4 ( V_2 , V_121 , & V_2 -> V_7 -> V_21 . V_22 [ V_118 ] ) ;
return 0 ;
}
static inline int F_43 ( struct V_1 * V_2 , unsigned V_118 )
{
T_1 T_2 * V_20 = & V_2 -> V_7 -> V_21 . V_22 [ V_118 ] ;
T_3 V_24 = 0 ;
T_4 V_122 = F_2 ( V_2 , & V_2 -> V_7 -> V_123 ) ;
T_4 V_124 = V_122 + V_125 ;
int V_126 = F_44 ( V_125 , V_127 ) ;
do {
int V_128 ;
V_128 = V_127 * 2 ;
while ( -- V_128 >= 0 ) {
V_24 = F_2 ( V_2 , V_20 ) ;
if ( V_24 == ~ ( T_3 ) 0 )
return - V_76 ;
if ( ! ( V_24 & V_121 ) )
break;
F_45 ( 500 ) ;
}
if ( V_128 < 0 ) {
F_3 ( V_2 ,
L_20 ,
V_118 , V_24 ) ;
break;
}
if ( ! ( V_24 & V_93 ) )
break;
if ( V_24 & V_98 )
F_4 ( V_2 , V_98 , V_20 ) ;
F_4 ( V_2 , V_121 , V_20 ) ;
F_6 ( V_127 ) ;
V_122 = F_2 ( V_2 , & V_2 -> V_7 -> V_123 ) ;
} while ( F_46 ( V_122 , V_124 ) && -- V_126 >= 0 );
return 0 ;
}
int F_47 (
struct V_41 * V_42 ,
T_4 V_129 ,
T_4 V_130 ,
T_4 V_131 ,
char * V_85 ,
T_4 V_132
) {
struct V_1 * V_2 = F_19 ( V_42 ) ;
int V_133 = V_2 -> V_25 ;
T_3 V_24 ;
int V_134 = 0 ;
if ( F_20 ( ! F_21 ( V_42 ) ) )
return - V_76 ;
switch ( V_129 ) {
case V_135 :
switch ( V_130 ) {
case V_136 :
F_4 ( V_2 , V_92 ,
& V_2 -> V_7 -> V_21 . V_5 ) ;
case V_137 :
break;
default:
goto error;
}
break;
case V_138 :
if ( ! V_131 || V_131 > V_133 )
goto error;
V_131 -- ;
switch ( V_130 ) {
case V_139 :
V_24 = V_93 ;
break;
case V_140 :
V_24 = V_95 ;
break;
case V_141 :
V_24 = V_142 ;
break;
case V_143 :
V_24 = V_96 ;
break;
case V_144 :
V_24 = V_145 ;
break;
case V_146 :
V_24 = V_94 ;
break;
case V_147 :
V_24 = V_97 ;
break;
case V_148 :
V_24 = V_98 ;
break;
default:
goto error;
}
F_4 ( V_2 , V_24 ,
& V_2 -> V_7 -> V_21 . V_22 [ V_131 ] ) ;
break;
case V_149 :
F_39 ( V_2 , (struct V_100 * ) V_85 ) ;
break;
case V_150 :
V_24 = F_34 ( V_2 ) & ~ ( V_151 | V_152 ) ;
F_48 ( V_24 , V_85 ) ;
break;
case V_153 :
if ( ! V_131 || V_131 > V_133 )
goto error;
V_131 -- ;
V_24 = F_35 ( V_2 , V_131 ) ;
F_48 ( V_24 , V_85 ) ;
if ( * ( T_4 * ) ( V_85 + 2 ) )
F_49 ( V_2 , L_21 , V_131 , V_24 ) ;
break;
case V_154 :
switch ( V_130 ) {
case V_136 :
case V_137 :
break;
default:
goto error;
}
break;
case V_155 :
if ( ! V_131 || V_131 > V_133 )
goto error;
V_131 -- ;
switch ( V_130 ) {
case V_141 :
#ifdef F_50
if ( V_42 -> V_28 . V_156 == ( V_131 + 1 )
&& V_42 -> V_28 . V_157 )
V_2 -> V_158 ( V_2 ) ;
else
#endif
F_4 ( V_2 , V_27 ,
& V_2 -> V_7 -> V_21 . V_22 [ V_131 ] ) ;
break;
case V_144 :
F_4 ( V_2 , V_159 ,
& V_2 -> V_7 -> V_21 . V_22 [ V_131 ] ) ;
break;
case V_160 :
V_134 = F_43 ( V_2 , V_131 ) ;
break;
default:
goto error;
}
break;
default:
error:
V_134 = - V_161 ;
}
return V_134 ;
}
