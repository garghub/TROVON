T_1 void F_1 ( struct V_1 * V_2 )
{
struct V_3 T_2 * V_4 = (struct V_3 T_2 * )
V_2 -> V_5 [ V_6 ] ;
T_3 T_2 * V_7 ;
unsigned long V_8 , V_9 , V_10 ;
unsigned long V_11 , V_12 ;
unsigned char V_13 ;
int V_14 ;
F_2 () ;
if ( F_3 () ||
( ( ( unsigned long ) V_4 ) & (sizeof( unsigned long ) - 1 ) ) ||
( ! F_4 ( V_4 , sizeof( * V_4 ) ) ) )
goto V_15;
V_7 = & V_4 -> V_16 . V_17 ;
V_14 = F_5 ( V_8 , & ( ( * V_7 ) [ V_18 ] ) ) ;
V_14 |= F_5 ( V_9 , & ( ( * V_7 ) [ V_19 ] ) ) ;
if ( V_14 || ( ( V_8 | V_9 ) & 3 ) )
goto V_15;
if ( V_2 -> V_5 [ V_20 ] ) {
T_4 V_21 ;
if ( V_22 == 1 ) {
if ( F_5 ( V_21 . V_23 [ 0 ] , & V_4 -> V_24 . V_23 [ 0 ] ) )
goto V_15;
} else {
if ( F_6 ( & V_21 , & V_4 -> V_24 , sizeof( T_4 ) ) )
goto V_15;
}
F_7 ( & V_21 , ~ V_25 ) ;
F_8 ( & V_21 ) ;
}
if ( F_9 ( V_26 ) ) {
V_8 &= 0xffffffff ;
V_9 &= 0xffffffff ;
}
V_2 -> V_27 = V_8 ;
V_2 -> V_28 = V_9 ;
V_14 |= F_5 ( V_2 -> V_29 , & ( ( * V_7 ) [ V_30 ] ) ) ;
V_14 |= F_5 ( V_10 , & ( ( * V_7 ) [ V_31 ] ) ) ;
V_2 -> V_10 &= ~ ( V_32 | V_33 | V_34 ) ;
V_2 -> V_10 |= ( V_10 & ( V_32 | V_33 | V_34 ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_35 ] , ( & ( * V_7 ) [ V_36 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_37 ] , ( & ( * V_7 ) [ V_38 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_39 ] , ( & ( * V_7 ) [ V_40 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_41 ] , ( & ( * V_7 ) [ V_42 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_43 ] , ( & ( * V_7 ) [ V_44 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_45 ] , ( & ( * V_7 ) [ V_46 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_6 ] , ( & ( * V_7 ) [ V_47 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_20 ] , ( & ( * V_7 ) [ V_48 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_49 ] , ( & ( * V_7 ) [ V_50 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_51 ] , ( & ( * V_7 ) [ V_52 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_53 ] , ( & ( * V_7 ) [ V_54 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_55 ] , ( & ( * V_7 ) [ V_56 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_57 ] , ( & ( * V_7 ) [ V_58 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_59 ] , ( & ( * V_7 ) [ V_60 ] ) ) ;
V_14 |= F_5 ( V_11 , & ( V_4 -> V_16 . V_61 ) ) ;
V_14 |= F_5 ( V_12 , & ( V_4 -> V_16 . V_62 ) ) ;
V_14 |= F_10 ( V_11 ,
( & ( ( (struct V_63 T_2 * ) ( V_64 + V_2 -> V_5 [ V_57 ] ) ) -> V_65 [ 6 ] ) ) ) ;
V_14 |= F_10 ( V_12 ,
( & ( ( (struct V_63 T_2 * ) ( V_64 + V_2 -> V_5 [ V_57 ] ) ) -> V_65 [ 7 ] ) ) ) ;
V_14 |= F_5 ( V_13 , & ( V_4 -> V_16 . V_66 . V_67 ) ) ;
if ( V_13 ) {
unsigned long * V_68 = F_11 () -> V_68 ;
unsigned long V_69 ;
F_12 ( 0 ) ;
V_14 |= F_5 ( V_69 , & ( V_4 -> V_16 . V_66 . V_70 ) ) ;
if ( V_69 & V_71 )
V_14 |= F_13 ( V_68 ,
& ( V_4 -> V_16 . V_66 . V_72 ) ,
(sizeof( unsigned int ) * 32 ) ) ;
if ( V_69 & V_73 )
V_14 |= F_13 ( V_68 + 16 ,
( ( unsigned long T_2 * ) & ( V_4 -> V_16 . V_66 . V_72 ) ) + 16 ,
(sizeof( unsigned int ) * 32 ) ) ;
V_14 |= F_5 ( F_11 () -> V_74 [ 0 ] ,
& ( V_4 -> V_16 . V_66 . V_75 ) ) ;
V_14 |= F_5 ( F_11 () -> V_76 [ 0 ] ,
& ( V_4 -> V_16 . V_66 . V_77 ) ) ;
V_2 -> V_10 &= ~ V_78 ;
}
if ( V_14 )
goto V_15;
return;
V_15:
F_14 ( V_79 , V_80 ) ;
}
T_1 void F_15 ( struct V_1 * V_2 )
{
struct V_3 T_2 * V_4 = (struct V_3 T_2 * )
V_2 -> V_5 [ V_6 ] ;
T_3 T_2 * V_7 ;
T_5 T_2 * V_81 ;
unsigned long V_11 , V_12 ;
unsigned char V_13 ;
int V_14 ;
F_16 () ;
if ( F_3 () || F_17 ( V_4 , sizeof( * V_4 ) ) )
goto V_15;
#if 1
V_13 = 0 ;
#else
V_13 = ( F_11 () -> V_82 [ 0 ] & V_83 ) ;
#endif
V_81 = & V_4 -> V_16 ;
V_7 = & V_81 -> V_17 ;
if ( F_9 ( V_26 ) ) {
V_2 -> V_27 = ( V_2 -> V_28 & 0xffffffff ) ;
V_2 -> V_28 = ( V_2 -> V_28 + 4 ) & 0xffffffff ;
} else {
V_2 -> V_27 = V_2 -> V_28 ;
V_2 -> V_28 += 4 ;
}
V_14 = 0 ;
if ( V_22 == 1 )
V_14 |= F_10 ( V_80 -> V_84 . V_23 [ 0 ] ,
( unsigned long T_2 * ) & V_4 -> V_24 ) ;
else
V_14 |= F_18 ( & V_4 -> V_24 , & V_80 -> V_84 ,
sizeof( T_4 ) ) ;
V_14 |= F_10 ( V_2 -> V_10 , & ( ( * V_7 ) [ V_31 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_27 , & ( ( * V_7 ) [ V_18 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_28 , & ( ( * V_7 ) [ V_19 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_29 , & ( ( * V_7 ) [ V_30 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_35 ] , & ( ( * V_7 ) [ V_36 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_37 ] , & ( ( * V_7 ) [ V_38 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_39 ] , & ( ( * V_7 ) [ V_40 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_41 ] , & ( ( * V_7 ) [ V_42 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_43 ] , & ( ( * V_7 ) [ V_44 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_45 ] , & ( ( * V_7 ) [ V_46 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_85 ] , & ( ( * V_7 ) [ V_86 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_6 ] , & ( ( * V_7 ) [ V_47 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_20 ] , & ( ( * V_7 ) [ V_48 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_49 ] , & ( ( * V_7 ) [ V_50 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_51 ] , & ( ( * V_7 ) [ V_52 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_53 ] , & ( ( * V_7 ) [ V_54 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_55 ] , & ( ( * V_7 ) [ V_56 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_57 ] , & ( ( * V_7 ) [ V_58 ] ) ) ;
V_14 |= F_10 ( V_2 -> V_5 [ V_59 ] , & ( ( * V_7 ) [ V_60 ] ) ) ;
V_14 |= F_5 ( V_11 ,
( & ( ( (struct V_63 T_2 * ) ( V_64 + V_2 -> V_5 [ V_57 ] ) ) -> V_65 [ 6 ] ) ) ) ;
V_14 |= F_5 ( V_12 ,
( & ( ( (struct V_63 T_2 * ) ( V_64 + V_2 -> V_5 [ V_57 ] ) ) -> V_65 [ 7 ] ) ) ) ;
V_14 |= F_10 ( V_11 , & ( V_81 -> V_61 ) ) ;
V_14 |= F_10 ( V_12 , & ( V_81 -> V_62 ) ) ;
V_14 |= F_10 ( V_13 , & ( V_81 -> V_66 . V_67 ) ) ;
if ( V_13 ) {
unsigned long * V_68 = F_11 () -> V_68 ;
unsigned long V_69 ;
V_69 = F_11 () -> V_82 [ 0 ] ;
if ( V_69 & V_71 )
V_14 |= F_19 ( & ( V_81 -> V_66 . V_72 ) , V_68 ,
(sizeof( unsigned int ) * 32 ) ) ;
if ( V_69 & V_73 )
V_14 |= F_19 (
( ( unsigned long T_2 * ) & ( V_81 -> V_66 . V_72 ) ) + 16 , V_68 + 16 ,
(sizeof( unsigned int ) * 32 ) ) ;
V_14 |= F_10 ( F_11 () -> V_74 [ 0 ] , & ( V_81 -> V_66 . V_75 ) ) ;
V_14 |= F_10 ( F_11 () -> V_76 [ 0 ] , & ( V_81 -> V_66 . V_77 ) ) ;
V_14 |= F_10 ( V_69 , & ( V_81 -> V_66 . V_70 ) ) ;
}
if ( V_14 )
goto V_15;
return;
V_15:
F_14 ( V_79 , V_80 ) ;
}
static long F_20 ( T_6 V_21 )
{
T_4 V_84 ;
V_80 -> V_87 = V_80 -> V_84 ;
V_21 &= V_25 ;
F_21 ( & V_84 , V_21 ) ;
F_8 ( & V_84 ) ;
V_80 -> V_88 = V_89 ;
F_22 () ;
F_23 () ;
return - V_90 ;
}
T_1 long F_24 ( unsigned int V_21 )
{
return F_20 ( V_21 ) ;
}
T_1 long F_25 ( T_6 V_21 )
{
return F_20 ( V_21 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_91 T_2 * V_92 ;
unsigned long V_27 , V_28 , V_10 ;
T_7 T_2 * V_93 ;
T_8 T_2 * V_94 ;
T_4 V_21 ;
int V_14 ;
F_11 () -> V_95 . V_96 = V_97 ;
F_16 () ;
V_92 = (struct V_91 T_2 * )
( V_2 -> V_5 [ V_98 ] + V_64 ) ;
if ( ( ( unsigned long ) V_92 ) & 3 )
goto V_99;
V_14 = F_27 ( V_27 , & V_92 -> V_2 . V_27 ) ;
V_14 |= F_5 ( V_28 , & V_92 -> V_2 . V_28 ) ;
if ( F_9 ( V_26 ) ) {
V_27 &= 0xffffffff ;
V_28 &= 0xffffffff ;
}
V_14 |= ( ( V_27 | V_28 ) & 3 ) ;
V_14 |= F_5 ( V_2 -> V_29 , & V_92 -> V_2 . V_29 ) ;
V_14 |= F_5 ( V_10 , & V_92 -> V_2 . V_10 ) ;
V_14 |= F_13 ( V_2 -> V_5 , V_92 -> V_2 . V_5 , sizeof( V_2 -> V_5 ) ) ;
V_2 -> V_10 &= ~ ( V_32 | V_33 | V_34 ) ;
V_2 -> V_10 |= ( V_10 & ( V_32 | V_33 | V_34 ) ) ;
V_14 |= F_5 ( V_93 , & V_92 -> V_93 ) ;
if ( ! V_14 && V_93 )
V_14 |= F_28 ( V_2 , V_93 ) ;
V_14 |= F_6 ( & V_21 , & V_92 -> V_100 , sizeof( T_4 ) ) ;
V_14 |= F_29 ( & V_92 -> V_101 , NULL , ( unsigned long ) V_92 ) ;
if ( V_14 )
goto V_99;
V_14 |= F_5 ( V_94 , & V_92 -> V_94 ) ;
if ( ! V_14 && V_94 ) {
if ( F_30 ( V_94 ) )
goto V_99;
}
V_2 -> V_27 = V_27 ;
V_2 -> V_28 = V_28 ;
F_31 ( V_2 ) ;
F_7 ( & V_21 , ~ V_25 ) ;
F_8 ( & V_21 ) ;
return;
V_99:
F_14 ( V_79 , V_80 ) ;
}
static int F_32 ( void T_2 * V_11 )
{
if ( ( ( unsigned long ) V_11 ) & 15 )
return 1 ;
return 0 ;
}
static inline void T_2 * F_33 ( struct V_102 * V_103 , struct V_1 * V_2 , unsigned long V_104 )
{
unsigned long V_105 = V_2 -> V_5 [ V_98 ] + V_64 ;
if ( F_34 ( V_105 ) && ! F_35 ( F_34 ( V_105 - V_104 ) ) )
return ( void T_2 * ) - 1L ;
if ( V_103 -> V_106 . V_107 & V_108 ) {
if ( F_36 ( V_105 ) == 0 )
V_105 = V_80 -> V_109 + V_80 -> V_110 ;
}
V_105 -= V_104 ;
V_105 &= ~ 15UL ;
return ( void T_2 * ) V_105 ;
}
static inline int
F_37 ( struct V_102 * V_103 , struct V_1 * V_2 ,
int V_111 , T_4 * V_112 , T_9 * V_113 )
{
struct V_91 T_2 * V_92 ;
int V_114 , V_14 , V_115 ;
void T_2 * V_116 ;
F_16 () ;
F_38 () ;
V_114 = F_3 () ;
V_115 = sizeof( struct V_91 ) ;
if ( F_11 () -> V_82 [ 0 ] & V_83 )
V_115 += sizeof( T_7 ) ;
if ( V_114 )
V_115 += sizeof( T_8 ) ;
V_92 = (struct V_91 T_2 * )
F_33 ( V_103 , V_2 , V_115 ) ;
if ( F_32 ( V_92 ) )
goto V_117;
V_116 = ( V_92 + 1 ) ;
V_14 = F_19 ( & V_92 -> V_2 , V_2 , sizeof ( * V_2 ) ) ;
if ( F_11 () -> V_82 [ 0 ] & V_83 ) {
T_7 T_2 * V_93 = V_116 ;
V_116 += sizeof( T_7 ) ;
V_14 |= F_39 ( V_2 , V_93 ) ;
V_14 |= F_10 ( ( V_118 ) V_93 , & V_92 -> V_93 ) ;
} else {
V_14 |= F_10 ( 0 , & V_92 -> V_93 ) ;
}
if ( V_114 ) {
T_8 T_2 * V_94 = V_116 ;
V_116 += sizeof( T_8 ) ;
V_14 |= F_40 ( V_114 , V_94 ) ;
V_14 |= F_10 ( ( V_118 ) V_94 , & V_92 -> V_94 ) ;
F_41 ( 0 ) ;
} else {
V_14 |= F_10 ( 0 , & V_92 -> V_94 ) ;
}
V_14 |= F_10 ( V_80 -> V_109 , & V_92 -> V_101 . V_119 ) ;
V_14 |= F_10 ( F_36 ( V_2 -> V_5 [ V_98 ] ) , & V_92 -> V_101 . V_120 ) ;
V_14 |= F_10 ( V_80 -> V_110 , & V_92 -> V_101 . V_121 ) ;
V_14 |= F_19 ( & V_92 -> V_100 , V_112 , sizeof( T_4 ) ) ;
if ( ! V_114 ) {
V_14 |= F_42 ( ( V_118 T_2 * ) V_92 ,
( V_118 T_2 * ) ( V_2 -> V_5 [ V_98 ] +
V_64 ) ,
sizeof( struct V_63 ) ) ;
} else {
struct V_63 * V_122 ;
V_122 = & F_11 () -> V_63 [ V_114 - 1 ] ;
V_14 |= F_19 ( V_92 , V_122 , sizeof( struct V_63 ) ) ;
}
if ( V_113 )
V_14 |= F_43 ( & V_92 -> V_113 , V_113 ) ;
else {
V_14 |= F_10 ( V_111 , & V_92 -> V_113 . V_123 ) ;
V_14 |= F_10 ( V_124 , & V_92 -> V_113 . V_125 ) ;
}
if ( V_14 )
goto V_126;
V_2 -> V_5 [ V_98 ] = ( ( unsigned long ) V_92 ) - V_64 ;
V_2 -> V_5 [ V_6 ] = V_111 ;
V_2 -> V_5 [ V_20 ] = ( unsigned long ) & V_92 -> V_113 ;
V_2 -> V_5 [ V_49 ] = ( unsigned long ) & V_92 -> V_113 ;
V_2 -> V_27 = ( unsigned long ) V_103 -> V_106 . V_127 ;
V_2 -> V_28 = ( V_2 -> V_27 + 4 ) ;
if ( F_9 ( V_26 ) ) {
V_2 -> V_27 &= 0xffffffff ;
V_2 -> V_28 &= 0xffffffff ;
}
V_2 -> V_5 [ V_59 ] = ( unsigned long ) V_103 -> V_128 ;
return 0 ;
V_117:
F_44 ( V_129 ) ;
return - V_130 ;
V_126:
F_45 ( V_111 , V_80 ) ;
return - V_131 ;
}
static inline int F_46 ( unsigned long V_132 , struct V_102 * V_103 ,
T_9 * V_113 ,
T_4 * V_112 , struct V_1 * V_2 )
{
T_4 V_84 ;
int V_14 ;
V_14 = F_37 ( V_103 , V_2 , V_132 , V_112 ,
( V_103 -> V_106 . V_107 & V_133 ) ? V_113 : NULL ) ;
if ( V_14 )
return V_14 ;
F_47 ( & V_84 , & V_80 -> V_84 , & V_103 -> V_106 . V_134 ) ;
if ( ! ( V_103 -> V_106 . V_107 & V_135 ) )
F_48 ( & V_84 , V_132 ) ;
F_8 ( & V_84 ) ;
F_49 ( V_132 , V_113 , V_103 , V_2 , 0 ) ;
return 0 ;
}
static inline void F_50 ( unsigned long V_136 , struct V_1 * V_2 ,
struct V_137 * V_106 )
{
switch ( V_2 -> V_5 [ V_6 ] ) {
case V_138 :
case V_90 :
V_139:
V_2 -> V_5 [ V_6 ] = V_140 ;
V_2 -> V_10 |= ( V_141 | V_142 ) ;
break;
case V_143 :
if ( ! ( V_106 -> V_107 & V_144 ) )
goto V_139;
case V_145 :
V_2 -> V_5 [ V_6 ] = V_136 ;
V_2 -> V_27 -= 4 ;
V_2 -> V_28 -= 4 ;
}
}
static void F_51 ( struct V_1 * V_2 , unsigned long V_136 )
{
struct V_102 V_103 ;
int V_146 ;
T_4 * V_112 ;
T_9 V_113 ;
int V_132 ;
if ( F_52 ( V_2 ) &&
( V_2 -> V_10 & ( V_142 | V_141 ) ) ) {
V_146 = 1 ;
} else
V_146 = 0 ;
if ( F_11 () -> V_147 & V_148 )
V_112 = & V_80 -> V_87 ;
else
V_112 = & V_80 -> V_84 ;
#ifdef F_53
if ( F_9 ( V_26 ) ) {
extern void V_149 ( T_4 * , struct V_1 * ,
int V_146 ,
unsigned long V_136 ) ;
V_149 ( V_112 , V_2 , V_146 , V_136 ) ;
return;
}
#endif
V_132 = F_54 ( & V_113 , & V_103 , V_2 , NULL ) ;
if ( V_146 && ! F_52 ( V_2 ) )
V_146 = 0 ;
if ( V_132 > 0 ) {
if ( V_146 )
F_50 ( V_136 , V_2 , & V_103 . V_106 ) ;
if ( F_46 ( V_132 , & V_103 , & V_113 , V_112 , V_2 ) == 0 ) {
F_11 () -> V_147 &= ~ V_148 ;
}
return;
}
if ( V_146 &&
( V_2 -> V_5 [ V_6 ] == V_90 ||
V_2 -> V_5 [ V_6 ] == V_143 ||
V_2 -> V_5 [ V_6 ] == V_145 ) ) {
V_2 -> V_5 [ V_6 ] = V_136 ;
V_2 -> V_27 -= 4 ;
V_2 -> V_28 -= 4 ;
F_31 ( V_2 ) ;
}
if ( V_146 &&
V_2 -> V_5 [ V_6 ] == V_138 ) {
V_2 -> V_5 [ V_35 ] = V_150 ;
V_2 -> V_27 -= 4 ;
V_2 -> V_28 -= 4 ;
F_31 ( V_2 ) ;
}
if ( F_11 () -> V_147 & V_148 ) {
F_11 () -> V_147 &= ~ V_148 ;
F_8 ( & V_80 -> V_87 ) ;
}
}
void F_55 ( struct V_1 * V_2 , unsigned long V_136 , unsigned long V_151 )
{
if ( V_151 & V_152 )
F_51 ( V_2 , V_136 ) ;
if ( V_151 & V_153 ) {
F_56 ( V_154 ) ;
F_57 ( V_2 ) ;
if ( V_80 -> V_155 )
F_58 () ;
}
}
