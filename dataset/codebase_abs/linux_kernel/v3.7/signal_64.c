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
F_7 ( & V_21 ) ;
}
if ( F_8 ( V_25 ) ) {
V_8 &= 0xffffffff ;
V_9 &= 0xffffffff ;
}
V_2 -> V_26 = V_8 ;
V_2 -> V_27 = V_9 ;
V_14 |= F_5 ( V_2 -> V_28 , & ( ( * V_7 ) [ V_29 ] ) ) ;
V_14 |= F_5 ( V_10 , & ( ( * V_7 ) [ V_30 ] ) ) ;
V_2 -> V_10 &= ~ ( V_31 | V_32 | V_33 ) ;
V_2 -> V_10 |= ( V_10 & ( V_31 | V_32 | V_33 ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_34 ] , ( & ( * V_7 ) [ V_35 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_36 ] , ( & ( * V_7 ) [ V_37 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_38 ] , ( & ( * V_7 ) [ V_39 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_40 ] , ( & ( * V_7 ) [ V_41 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_42 ] , ( & ( * V_7 ) [ V_43 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_44 ] , ( & ( * V_7 ) [ V_45 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_6 ] , ( & ( * V_7 ) [ V_46 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_20 ] , ( & ( * V_7 ) [ V_47 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_48 ] , ( & ( * V_7 ) [ V_49 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_50 ] , ( & ( * V_7 ) [ V_51 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_52 ] , ( & ( * V_7 ) [ V_53 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_54 ] , ( & ( * V_7 ) [ V_55 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_56 ] , ( & ( * V_7 ) [ V_57 ] ) ) ;
V_14 |= F_5 ( V_2 -> V_5 [ V_58 ] , ( & ( * V_7 ) [ V_59 ] ) ) ;
V_14 |= F_5 ( V_11 , & ( V_4 -> V_16 . V_60 ) ) ;
V_14 |= F_5 ( V_12 , & ( V_4 -> V_16 . V_61 ) ) ;
V_14 |= F_9 ( V_11 ,
( & ( ( (struct V_62 T_2 * ) ( V_63 + V_2 -> V_5 [ V_56 ] ) ) -> V_64 [ 6 ] ) ) ) ;
V_14 |= F_9 ( V_12 ,
( & ( ( (struct V_62 T_2 * ) ( V_63 + V_2 -> V_5 [ V_56 ] ) ) -> V_64 [ 7 ] ) ) ) ;
V_14 |= F_5 ( V_13 , & ( V_4 -> V_16 . V_65 . V_66 ) ) ;
if ( V_13 ) {
unsigned long * V_67 = F_10 () -> V_67 ;
unsigned long V_68 ;
F_11 ( 0 ) ;
V_14 |= F_5 ( V_68 , & ( V_4 -> V_16 . V_65 . V_69 ) ) ;
if ( V_68 & V_70 )
V_14 |= F_12 ( V_67 ,
& ( V_4 -> V_16 . V_65 . V_71 ) ,
(sizeof( unsigned int ) * 32 ) ) ;
if ( V_68 & V_72 )
V_14 |= F_12 ( V_67 + 16 ,
( ( unsigned long T_2 * ) & ( V_4 -> V_16 . V_65 . V_71 ) ) + 16 ,
(sizeof( unsigned int ) * 32 ) ) ;
V_14 |= F_5 ( F_10 () -> V_73 [ 0 ] ,
& ( V_4 -> V_16 . V_65 . V_74 ) ) ;
V_14 |= F_5 ( F_10 () -> V_75 [ 0 ] ,
& ( V_4 -> V_16 . V_65 . V_76 ) ) ;
V_2 -> V_10 &= ~ V_77 ;
}
if ( V_14 )
goto V_15;
return;
V_15:
F_13 ( V_78 , V_79 ) ;
}
T_1 void F_14 ( struct V_1 * V_2 )
{
struct V_3 T_2 * V_4 = (struct V_3 T_2 * )
V_2 -> V_5 [ V_6 ] ;
T_3 T_2 * V_7 ;
T_5 T_2 * V_80 ;
unsigned long V_11 , V_12 ;
unsigned char V_13 ;
int V_14 ;
F_15 () ;
if ( F_3 () || F_16 ( V_4 , sizeof( * V_4 ) ) )
goto V_15;
#if 1
V_13 = 0 ;
#else
V_13 = ( F_10 () -> V_81 [ 0 ] & V_82 ) ;
#endif
V_80 = & V_4 -> V_16 ;
V_7 = & V_80 -> V_17 ;
if ( F_8 ( V_25 ) ) {
V_2 -> V_26 = ( V_2 -> V_27 & 0xffffffff ) ;
V_2 -> V_27 = ( V_2 -> V_27 + 4 ) & 0xffffffff ;
} else {
V_2 -> V_26 = V_2 -> V_27 ;
V_2 -> V_27 += 4 ;
}
V_14 = 0 ;
if ( V_22 == 1 )
V_14 |= F_9 ( V_79 -> V_83 . V_23 [ 0 ] ,
( unsigned long T_2 * ) & V_4 -> V_24 ) ;
else
V_14 |= F_17 ( & V_4 -> V_24 , & V_79 -> V_83 ,
sizeof( T_4 ) ) ;
V_14 |= F_9 ( V_2 -> V_10 , & ( ( * V_7 ) [ V_30 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_26 , & ( ( * V_7 ) [ V_18 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_27 , & ( ( * V_7 ) [ V_19 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_28 , & ( ( * V_7 ) [ V_29 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_34 ] , & ( ( * V_7 ) [ V_35 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_36 ] , & ( ( * V_7 ) [ V_37 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_38 ] , & ( ( * V_7 ) [ V_39 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_40 ] , & ( ( * V_7 ) [ V_41 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_42 ] , & ( ( * V_7 ) [ V_43 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_44 ] , & ( ( * V_7 ) [ V_45 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_84 ] , & ( ( * V_7 ) [ V_85 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_6 ] , & ( ( * V_7 ) [ V_46 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_20 ] , & ( ( * V_7 ) [ V_47 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_48 ] , & ( ( * V_7 ) [ V_49 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_50 ] , & ( ( * V_7 ) [ V_51 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_52 ] , & ( ( * V_7 ) [ V_53 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_54 ] , & ( ( * V_7 ) [ V_55 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_56 ] , & ( ( * V_7 ) [ V_57 ] ) ) ;
V_14 |= F_9 ( V_2 -> V_5 [ V_58 ] , & ( ( * V_7 ) [ V_59 ] ) ) ;
V_14 |= F_5 ( V_11 ,
( & ( ( (struct V_62 T_2 * ) ( V_63 + V_2 -> V_5 [ V_56 ] ) ) -> V_64 [ 6 ] ) ) ) ;
V_14 |= F_5 ( V_12 ,
( & ( ( (struct V_62 T_2 * ) ( V_63 + V_2 -> V_5 [ V_56 ] ) ) -> V_64 [ 7 ] ) ) ) ;
V_14 |= F_9 ( V_11 , & ( V_80 -> V_60 ) ) ;
V_14 |= F_9 ( V_12 , & ( V_80 -> V_61 ) ) ;
V_14 |= F_9 ( V_13 , & ( V_80 -> V_65 . V_66 ) ) ;
if ( V_13 ) {
unsigned long * V_67 = F_10 () -> V_67 ;
unsigned long V_68 ;
V_68 = F_10 () -> V_81 [ 0 ] ;
if ( V_68 & V_70 )
V_14 |= F_18 ( & ( V_80 -> V_65 . V_71 ) , V_67 ,
(sizeof( unsigned int ) * 32 ) ) ;
if ( V_68 & V_72 )
V_14 |= F_18 (
( ( unsigned long T_2 * ) & ( V_80 -> V_65 . V_71 ) ) + 16 , V_67 + 16 ,
(sizeof( unsigned int ) * 32 ) ) ;
V_14 |= F_9 ( F_10 () -> V_73 [ 0 ] , & ( V_80 -> V_65 . V_74 ) ) ;
V_14 |= F_9 ( F_10 () -> V_75 [ 0 ] , & ( V_80 -> V_65 . V_76 ) ) ;
V_14 |= F_9 ( V_68 , & ( V_80 -> V_65 . V_69 ) ) ;
}
if ( V_14 )
goto V_15;
return;
V_15:
F_13 ( V_78 , V_79 ) ;
}
static long F_19 ( T_6 V_21 )
{
T_4 V_83 ;
F_20 ( & V_83 , V_21 ) ;
return F_21 ( & V_83 ) ;
}
T_1 long F_22 ( unsigned int V_21 )
{
return F_19 ( V_21 ) ;
}
T_1 long F_23 ( T_6 V_21 )
{
return F_19 ( V_21 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_86 T_2 * V_87 ;
unsigned long V_26 , V_27 , V_10 ;
T_7 T_2 * V_88 ;
T_8 T_2 * V_89 ;
T_4 V_21 ;
int V_14 ;
F_10 () -> V_90 . V_91 = V_92 ;
F_15 () ;
V_87 = (struct V_86 T_2 * )
( V_2 -> V_5 [ V_93 ] + V_63 ) ;
if ( ( ( unsigned long ) V_87 ) & 3 )
goto V_94;
V_14 = F_25 ( V_26 , & V_87 -> V_2 . V_26 ) ;
V_14 |= F_5 ( V_27 , & V_87 -> V_2 . V_27 ) ;
if ( F_8 ( V_25 ) ) {
V_26 &= 0xffffffff ;
V_27 &= 0xffffffff ;
}
V_14 |= ( ( V_26 | V_27 ) & 3 ) ;
V_14 |= F_5 ( V_2 -> V_28 , & V_87 -> V_2 . V_28 ) ;
V_14 |= F_5 ( V_10 , & V_87 -> V_2 . V_10 ) ;
V_14 |= F_12 ( V_2 -> V_5 , V_87 -> V_2 . V_5 , sizeof( V_2 -> V_5 ) ) ;
V_2 -> V_10 &= ~ ( V_31 | V_32 | V_33 ) ;
V_2 -> V_10 |= ( V_10 & ( V_31 | V_32 | V_33 ) ) ;
V_14 |= F_5 ( V_88 , & V_87 -> V_88 ) ;
if ( ! V_14 && V_88 )
V_14 |= F_26 ( V_2 , V_88 ) ;
V_14 |= F_6 ( & V_21 , & V_87 -> V_95 , sizeof( T_4 ) ) ;
if ( V_14 || F_27 ( & V_87 -> V_96 , NULL , ( unsigned long ) V_87 ) == - V_97 )
goto V_94;
V_14 |= F_5 ( V_89 , & V_87 -> V_89 ) ;
if ( ! V_14 && V_89 ) {
if ( F_28 ( V_89 ) )
goto V_94;
}
V_2 -> V_26 = V_26 ;
V_2 -> V_27 = V_27 ;
F_29 ( V_2 ) ;
F_7 ( & V_21 ) ;
return;
V_94:
F_13 ( V_78 , V_79 ) ;
}
static int F_30 ( void T_2 * V_11 )
{
if ( ( ( unsigned long ) V_11 ) & 15 )
return 1 ;
return 0 ;
}
static inline void T_2 * F_31 ( struct V_98 * V_99 , struct V_1 * V_2 , unsigned long V_100 )
{
unsigned long V_101 = V_2 -> V_5 [ V_93 ] + V_63 ;
if ( F_32 ( V_101 ) && ! F_33 ( F_32 ( V_101 - V_100 ) ) )
return ( void T_2 * ) - 1L ;
if ( V_99 -> V_102 . V_103 & V_104 ) {
if ( F_34 ( V_101 ) == 0 )
V_101 = V_79 -> V_105 + V_79 -> V_106 ;
}
V_101 -= V_100 ;
V_101 &= ~ 15UL ;
return ( void T_2 * ) V_101 ;
}
static inline int
F_35 ( struct V_98 * V_99 , struct V_1 * V_2 ,
int V_107 , T_4 * V_108 , T_9 * V_109 )
{
struct V_86 T_2 * V_87 ;
int V_110 , V_14 , V_111 ;
void T_2 * V_112 ;
F_15 () ;
F_36 () ;
V_110 = F_3 () ;
V_111 = sizeof( struct V_86 ) ;
if ( F_10 () -> V_81 [ 0 ] & V_82 )
V_111 += sizeof( T_7 ) ;
if ( V_110 )
V_111 += sizeof( T_8 ) ;
V_87 = (struct V_86 T_2 * )
F_31 ( V_99 , V_2 , V_111 ) ;
if ( F_30 ( V_87 ) )
goto V_113;
V_112 = ( V_87 + 1 ) ;
V_14 = F_18 ( & V_87 -> V_2 , V_2 , sizeof ( * V_2 ) ) ;
if ( F_10 () -> V_81 [ 0 ] & V_82 ) {
T_7 T_2 * V_88 = V_112 ;
V_112 += sizeof( T_7 ) ;
V_14 |= F_37 ( V_2 , V_88 ) ;
V_14 |= F_9 ( ( V_114 ) V_88 , & V_87 -> V_88 ) ;
} else {
V_14 |= F_9 ( 0 , & V_87 -> V_88 ) ;
}
if ( V_110 ) {
T_8 T_2 * V_89 = V_112 ;
V_112 += sizeof( T_8 ) ;
V_14 |= F_38 ( V_110 , V_89 ) ;
V_14 |= F_9 ( ( V_114 ) V_89 , & V_87 -> V_89 ) ;
F_39 ( 0 ) ;
} else {
V_14 |= F_9 ( 0 , & V_87 -> V_89 ) ;
}
V_14 |= F_9 ( V_79 -> V_105 , & V_87 -> V_96 . V_115 ) ;
V_14 |= F_9 ( F_34 ( V_2 -> V_5 [ V_93 ] ) , & V_87 -> V_96 . V_116 ) ;
V_14 |= F_9 ( V_79 -> V_106 , & V_87 -> V_96 . V_117 ) ;
V_14 |= F_18 ( & V_87 -> V_95 , V_108 , sizeof( T_4 ) ) ;
if ( ! V_110 ) {
V_14 |= F_40 ( ( V_114 T_2 * ) V_87 ,
( V_114 T_2 * ) ( V_2 -> V_5 [ V_93 ] +
V_63 ) ,
sizeof( struct V_62 ) ) ;
} else {
struct V_62 * V_118 ;
V_118 = & F_10 () -> V_62 [ V_110 - 1 ] ;
V_14 |= F_18 ( V_87 , V_118 , sizeof( struct V_62 ) ) ;
}
if ( V_109 )
V_14 |= F_41 ( & V_87 -> V_109 , V_109 ) ;
else {
V_14 |= F_9 ( V_107 , & V_87 -> V_109 . V_119 ) ;
V_14 |= F_9 ( V_120 , & V_87 -> V_109 . V_121 ) ;
}
if ( V_14 )
goto V_122;
V_2 -> V_5 [ V_93 ] = ( ( unsigned long ) V_87 ) - V_63 ;
V_2 -> V_5 [ V_6 ] = V_107 ;
V_2 -> V_5 [ V_20 ] = ( unsigned long ) & V_87 -> V_109 ;
V_2 -> V_5 [ V_48 ] = ( unsigned long ) & V_87 -> V_109 ;
V_2 -> V_26 = ( unsigned long ) V_99 -> V_102 . V_123 ;
V_2 -> V_27 = ( V_2 -> V_26 + 4 ) ;
if ( F_8 ( V_25 ) ) {
V_2 -> V_26 &= 0xffffffff ;
V_2 -> V_27 &= 0xffffffff ;
}
V_2 -> V_5 [ V_58 ] = ( unsigned long ) V_99 -> V_124 ;
return 0 ;
V_113:
F_42 ( V_125 ) ;
return - V_126 ;
V_122:
F_43 ( V_107 , V_79 ) ;
return - V_97 ;
}
static inline void F_44 ( unsigned long V_127 , struct V_98 * V_99 ,
T_9 * V_109 ,
T_4 * V_108 , struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_35 ( V_99 , V_2 , V_127 , V_108 ,
( V_99 -> V_102 . V_103 & V_128 ) ? V_109 : NULL ) ;
if ( V_14 )
return;
F_45 ( V_127 , V_109 , V_99 , V_2 , 0 ) ;
}
static inline void F_46 ( unsigned long V_129 , struct V_1 * V_2 ,
struct V_130 * V_102 )
{
switch ( V_2 -> V_5 [ V_6 ] ) {
case V_131 :
case V_132 :
V_133:
V_2 -> V_5 [ V_6 ] = V_134 ;
V_2 -> V_10 |= ( V_135 | V_136 ) ;
break;
case V_137 :
if ( ! ( V_102 -> V_103 & V_138 ) )
goto V_133;
case V_139 :
V_2 -> V_5 [ V_6 ] = V_129 ;
V_2 -> V_26 -= 4 ;
V_2 -> V_27 -= 4 ;
}
}
static void F_47 ( struct V_1 * V_2 , unsigned long V_129 )
{
struct V_98 V_99 ;
int V_140 ;
T_4 * V_108 = F_48 () ;
T_9 V_109 ;
int V_127 ;
if ( F_49 ( V_2 ) &&
( V_2 -> V_10 & ( V_136 | V_135 ) ) )
V_2 -> V_5 [ V_44 ] = V_129 ;
#ifdef F_50
if ( F_8 ( V_25 ) ) {
extern void V_141 ( T_4 * , struct V_1 * ) ;
V_141 ( V_108 , V_2 ) ;
return;
}
#endif
V_127 = F_51 ( & V_109 , & V_99 , V_2 , NULL ) ;
V_140 = 0 ;
if ( F_49 ( V_2 ) &&
( V_2 -> V_10 & ( V_136 | V_135 ) ) ) {
V_140 = 1 ;
V_129 = V_2 -> V_5 [ V_44 ] ;
}
if ( V_127 > 0 ) {
if ( V_140 )
F_46 ( V_129 , V_2 , & V_99 . V_102 ) ;
F_44 ( V_127 , & V_99 , & V_109 , V_108 , V_2 ) ;
return;
}
if ( V_140 &&
( V_2 -> V_5 [ V_6 ] == V_132 ||
V_2 -> V_5 [ V_6 ] == V_137 ||
V_2 -> V_5 [ V_6 ] == V_139 ) ) {
V_2 -> V_5 [ V_6 ] = V_129 ;
V_2 -> V_26 -= 4 ;
V_2 -> V_27 -= 4 ;
F_29 ( V_2 ) ;
}
if ( V_140 &&
V_2 -> V_5 [ V_6 ] == V_131 ) {
V_2 -> V_5 [ V_34 ] = V_142 ;
V_2 -> V_26 -= 4 ;
V_2 -> V_27 -= 4 ;
F_29 ( V_2 ) ;
}
F_52 () ;
}
void F_53 ( struct V_1 * V_2 , unsigned long V_129 , unsigned long V_143 )
{
if ( V_143 & V_144 )
F_47 ( V_2 , V_129 ) ;
if ( V_143 & V_145 ) {
F_54 ( V_146 ) ;
F_55 ( V_2 ) ;
}
}
