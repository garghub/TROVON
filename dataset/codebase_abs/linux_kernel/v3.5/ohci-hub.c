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
static void T_2 F_27 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
int V_68 ;
bool V_69 = false ;
V_2 -> V_6 = F_2 ( V_2 , & V_2 -> V_7 -> V_8 ) ;
if ( V_2 -> V_6 & ( V_37 | V_15 ) ) {
V_69 = true ;
} else {
switch ( V_2 -> V_6 & V_9 ) {
case V_39 :
case V_11 :
V_69 = true ;
}
}
if ( V_69 ) {
F_7 ( & V_2 -> V_4 ) ;
F_14 ( V_2 ) ;
F_1 ( V_2 , 0 ) ;
F_5 ( & V_2 -> V_4 ) ;
}
else {
F_3 ( V_2 , L_19 ) ;
for ( V_68 = 0 ; V_68 < V_2 -> V_70 ; V_68 ++ )
F_4 ( V_2 , V_71 ,
& V_2 -> V_7 -> V_72 . V_73 [ V_68 ] ) ;
F_4 ( V_2 , V_74 , & V_2 -> V_7 -> V_49 ) ;
F_2 ( V_2 , & V_2 -> V_7 -> V_49 ) ;
F_6 ( 20 ) ;
}
F_28 ( V_32 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_75 ,
int V_76 , int V_77 )
{
int V_78 = 1 ;
int V_79 ;
V_79 = F_2 ( V_2 , & V_2 -> V_7 -> V_49 ) &
V_22 ;
switch ( V_2 -> V_6 & V_9 ) {
case V_39 :
if ( ! V_79 && ! V_77 && ! V_75 ) {
V_79 = V_22 ;
F_4 ( V_2 , V_79 , & V_2 -> V_7 -> V_49 ) ;
}
if ( ! V_2 -> V_3 ) {
if ( V_76 ||
! F_30 ( & F_11 ( V_2 )
-> V_18 . V_19 -> V_80 ) ) {
if ( V_79 )
V_78 = 0 ;
} else {
V_2 -> V_3 = 1 ;
V_2 -> V_25 = V_26 + V_81 ;
}
} else {
if ( V_75 || V_76 ) {
V_2 -> V_3 = 0 ;
V_2 -> V_25 = V_26 +
V_53 ;
} else if ( F_31 ( V_26 ,
V_2 -> V_25 )
&& ! V_2 -> V_50
&& ! ( V_2 -> V_6 &
V_15 ) ) {
F_1 ( V_2 , 1 ) ;
if ( V_79 )
V_78 = 0 ;
}
}
break;
case V_14 :
case V_10 :
if ( V_75 ) {
if ( V_2 -> V_3 )
F_14 ( V_2 ) ;
else
F_28 ( F_11 ( V_2 ) ) ;
} else if ( ! V_2 -> V_3 &&
! F_11 ( V_2 ) -> V_18 . V_19 ->
V_20 ) {
V_78 = 0 ;
} else {
if ( ! V_79 && ! V_77 ) {
V_79 = V_22 ;
F_4 ( V_2 , V_79 ,
& V_2 -> V_7 -> V_49 ) ;
}
if ( V_79 )
V_78 = 0 ;
}
break;
}
return V_78 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_75 ,
int V_76 , int V_77 )
{
if ( F_2 ( V_2 , & V_2 -> V_7 -> V_49 ) & V_22 )
return 0 ;
if ( V_75 || V_77 )
return 1 ;
F_4 ( V_2 , V_22 , & V_2 -> V_7 -> V_49 ) ;
return 0 ;
}
static int
F_32 ( struct V_31 * V_32 , char * V_82 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
int V_83 , V_75 = 0 , V_84 = 1 ;
int V_76 = 0 ;
int V_77 ;
unsigned long V_85 ;
F_33 ( & V_2 -> V_4 , V_85 ) ;
if ( ! F_23 ( V_32 ) )
goto V_13;
if ( ( V_2 -> V_85 & V_86 )
&& ( F_34 ( V_2 ) & V_87 ) > V_88 ) {
F_35 ( V_2 , L_20 ,
F_2 ( V_2 , & V_2 -> V_7 -> V_72 . V_89 ) & V_87 ) ;
goto V_13;
}
if ( F_36 ( V_2 ) & ( V_90 | V_91 ) )
V_82 [ 0 ] = V_75 = 1 ;
else
V_82 [ 0 ] = 0 ;
if ( V_2 -> V_70 > 7 ) {
V_82 [ 1 ] = 0 ;
V_84 ++ ;
}
F_4 ( V_2 , V_22 , & V_2 -> V_7 -> V_17 ) ;
V_77 = F_2 ( V_2 , & V_2 -> V_7 -> V_17 ) &
V_22 ;
for ( V_83 = 0 ; V_83 < V_2 -> V_70 ; V_83 ++ ) {
T_1 V_5 = F_37 ( V_2 , V_83 ) ;
V_76 |= ( V_5 & V_92 ) ;
if ( V_5 & ( V_93 | V_94 | V_95
| V_96 | V_97 ) ) {
V_75 = 1 ;
if ( V_83 < 7 )
V_82 [ 0 ] |= 1 << ( V_83 + 1 ) ;
else
V_82 [ 1 ] |= 1 << ( V_83 - 7 ) ;
}
}
if ( F_29 ( V_2 , V_75 ,
V_76 , V_77 ) )
F_38 ( V_98 , & V_32 -> V_85 ) ;
else
F_39 ( V_98 , & V_32 -> V_85 ) ;
V_13:
F_40 ( & V_2 -> V_4 , V_85 ) ;
return V_75 ? V_84 : 0 ;
}
static void
F_41 (
struct V_1 * V_2 ,
struct V_99 * V_100
) {
T_1 V_101 = F_34 ( V_2 ) ;
T_3 V_33 ;
V_100 -> V_102 = 0x29 ;
V_100 -> V_103 = ( V_101 & V_104 ) >> 24 ;
V_100 -> V_105 = 0 ;
V_100 -> V_106 = V_2 -> V_70 ;
V_33 = 1 + ( V_2 -> V_70 / 8 ) ;
V_100 -> V_107 = 7 + 2 * V_33 ;
V_33 = 0 ;
if ( V_101 & V_108 )
V_33 |= 0x0002 ;
if ( V_101 & V_109 )
V_33 |= 0x0001 ;
if ( V_101 & V_110 )
V_33 |= 0x0010 ;
else if ( V_101 & V_111 )
V_33 |= 0x0008 ;
V_100 -> V_112 = ( V_113 V_114 ) F_42 ( V_2 , V_33 ) ;
V_101 = F_43 ( V_2 ) ;
memset ( V_100 -> V_115 . V_116 . V_117 , 0xff ,
sizeof( V_100 -> V_115 . V_116 . V_117 ) ) ;
V_100 -> V_115 . V_116 . V_117 [ 0 ] = V_101 & V_118 ;
if ( V_2 -> V_70 > 7 ) {
V_100 -> V_115 . V_116 . V_117 [ 1 ] = ( V_101 & V_118 ) >> 8 ;
V_100 -> V_115 . V_116 . V_117 [ 2 ] = 0xff ;
} else
V_100 -> V_115 . V_116 . V_117 [ 1 ] = 0xff ;
}
static int F_44 ( struct V_31 * V_32 , unsigned V_68 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
T_1 V_5 ;
if ( ! V_68 )
return - V_119 ;
V_68 -- ;
V_5 = F_2 ( V_2 , & V_2 -> V_7 -> V_72 . V_73 [ V_68 ] ) ;
if ( ! ( V_5 & V_92 ) )
return - V_120 ;
F_4 ( V_2 , V_121 , & V_2 -> V_7 -> V_72 . V_73 [ V_68 ] ) ;
return 0 ;
}
static inline int F_45 ( struct V_1 * V_2 , unsigned V_68 )
{
T_4 T_5 * V_122 = & V_2 -> V_7 -> V_72 . V_73 [ V_68 ] ;
T_1 V_33 = 0 ;
T_3 V_123 = F_2 ( V_2 , & V_2 -> V_7 -> V_124 ) ;
T_3 V_125 = V_123 + V_126 ;
int V_127 = F_46 ( V_126 , V_128 ) ;
do {
int V_129 ;
V_129 = V_128 * 2 ;
while ( -- V_129 >= 0 ) {
V_33 = F_2 ( V_2 , V_122 ) ;
if ( V_33 == ~ ( T_1 ) 0 )
return - V_67 ;
if ( ! ( V_33 & V_121 ) )
break;
F_47 ( 500 ) ;
}
if ( V_129 < 0 ) {
F_3 ( V_2 ,
L_21 ,
V_68 , V_33 ) ;
break;
}
if ( ! ( V_33 & V_92 ) )
break;
if ( V_33 & V_97 )
F_4 ( V_2 , V_97 , V_122 ) ;
F_4 ( V_2 , V_121 , V_122 ) ;
F_6 ( V_128 ) ;
V_123 = F_2 ( V_2 , & V_2 -> V_7 -> V_124 ) ;
} while ( F_48 ( V_123 , V_125 ) && -- V_127 >= 0 );
return 0 ;
}
static int F_49 (
struct V_31 * V_32 ,
T_3 V_130 ,
T_3 V_131 ,
T_3 V_132 ,
char * V_82 ,
T_3 V_133
) {
struct V_1 * V_2 = F_21 ( V_32 ) ;
int V_134 = V_2 -> V_70 ;
T_1 V_33 ;
int V_135 = 0 ;
if ( F_22 ( ! F_23 ( V_32 ) ) )
return - V_67 ;
switch ( V_130 ) {
case V_136 :
switch ( V_131 ) {
case V_137 :
F_4 ( V_2 , V_91 ,
& V_2 -> V_7 -> V_72 . V_5 ) ;
case V_138 :
break;
default:
goto error;
}
break;
case V_139 :
if ( ! V_132 || V_132 > V_134 )
goto error;
V_132 -- ;
switch ( V_131 ) {
case V_140 :
V_33 = V_92 ;
break;
case V_141 :
V_33 = V_94 ;
break;
case V_142 :
V_33 = V_143 ;
break;
case V_144 :
V_33 = V_95 ;
break;
case V_145 :
V_33 = V_146 ;
break;
case V_147 :
V_33 = V_93 ;
break;
case V_148 :
V_33 = V_96 ;
break;
case V_149 :
V_33 = V_97 ;
break;
default:
goto error;
}
F_4 ( V_2 , V_33 ,
& V_2 -> V_7 -> V_72 . V_73 [ V_132 ] ) ;
break;
case V_150 :
F_41 ( V_2 , (struct V_99 * ) V_82 ) ;
break;
case V_151 :
V_33 = F_36 ( V_2 ) & ~ ( V_152 | V_153 ) ;
F_50 ( V_33 , V_82 ) ;
break;
case V_154 :
if ( ! V_132 || V_132 > V_134 )
goto error;
V_132 -- ;
V_33 = F_37 ( V_2 , V_132 ) ;
F_50 ( V_33 , V_82 ) ;
#ifndef F_51
if ( * ( T_3 * ) ( V_82 + 2 ) )
#endif
F_52 ( V_2 , L_22 , V_132 , V_33 ) ;
break;
case V_155 :
switch ( V_131 ) {
case V_137 :
case V_138 :
break;
default:
goto error;
}
break;
case V_156 :
if ( ! V_132 || V_132 > V_134 )
goto error;
V_132 -- ;
switch ( V_131 ) {
case V_142 :
#ifdef F_53
if ( V_32 -> V_18 . V_157 == ( V_132 + 1 )
&& V_32 -> V_18 . V_158 )
V_2 -> V_159 ( V_2 ) ;
else
#endif
F_4 ( V_2 , V_160 ,
& V_2 -> V_7 -> V_72 . V_73 [ V_132 ] ) ;
break;
case V_145 :
F_4 ( V_2 , V_71 ,
& V_2 -> V_7 -> V_72 . V_73 [ V_132 ] ) ;
break;
case V_161 :
V_135 = F_45 ( V_2 , V_132 ) ;
break;
default:
goto error;
}
break;
default:
error:
V_135 = - V_162 ;
}
return V_135 ;
}
