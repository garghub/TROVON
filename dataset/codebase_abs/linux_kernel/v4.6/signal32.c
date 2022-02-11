int F_1 ( T_1 T_2 * V_1 , const T_3 * V_2 )
{
int V_3 ;
if ( ! F_2 ( V_4 , V_1 , sizeof( T_1 ) ) )
return - V_5 ;
V_3 = F_3 ( V_2 -> V_6 , & V_1 -> V_6 ) ;
V_3 |= F_3 ( V_2 -> V_7 , & V_1 -> V_7 ) ;
V_3 |= F_3 ( ( short ) V_2 -> V_8 , & V_1 -> V_8 ) ;
if ( V_2 -> V_8 < 0 )
V_3 |= F_4 ( & V_1 -> V_9 . V_10 , & V_2 -> V_9 . V_10 , V_11 ) ;
else {
switch ( V_2 -> V_8 >> 16 ) {
case V_12 >> 16 :
V_3 |= F_3 ( V_2 -> V_13 , & V_1 -> V_13 ) ;
V_3 |= F_3 ( V_2 -> V_14 , & V_1 -> V_14 ) ;
V_3 |= F_3 ( V_2 -> V_15 , & V_1 -> V_15 ) ;
break;
case V_16 >> 16 :
V_3 |= F_3 ( V_2 -> V_17 , & V_1 -> V_17 ) ;
V_3 |= F_3 ( V_2 -> V_18 , & V_1 -> V_18 ) ;
V_3 |= F_3 ( V_2 -> V_19 , & V_1 -> V_19 ) ;
default:
V_3 |= F_3 ( V_2 -> V_20 , & V_1 -> V_20 ) ;
V_3 |= F_3 ( V_2 -> V_21 , & V_1 -> V_21 ) ;
break;
case V_22 >> 16 :
V_3 |= F_3 ( V_2 -> V_23 , & V_1 -> V_23 ) ;
V_3 |= F_3 ( ( unsigned long ) V_2 -> V_24 , & V_1 -> V_24 ) ;
break;
case V_25 >> 16 :
V_3 |= F_3 ( V_2 -> V_26 , & V_1 -> V_26 ) ;
V_3 |= F_3 ( V_2 -> V_27 , & V_1 -> V_27 ) ;
break;
case V_28 >> 16 :
case V_29 >> 16 :
V_3 |= F_3 ( V_2 -> V_20 , & V_1 -> V_20 ) ;
V_3 |= F_3 ( V_2 -> V_21 , & V_1 -> V_21 ) ;
V_3 |= F_3 ( V_2 -> V_15 , & V_1 -> V_15 ) ;
break;
}
}
return V_3 ;
}
int F_5 ( T_3 * V_1 , T_1 T_2 * V_2 )
{
if ( ! F_2 ( V_4 , V_2 , sizeof( T_1 ) ) )
return - V_5 ;
if ( F_6 ( V_1 , V_2 , 3 * sizeof( int ) ) ||
F_6 ( V_1 -> V_9 . V_10 , V_2 -> V_9 . V_10 ,
V_11 ) )
return - V_5 ;
return 0 ;
}
void F_7 ( struct V_30 * V_31 )
{
struct V_32 T_2 * V_33 ;
T_4 V_34 ;
T_4 V_35 ;
unsigned int V_36 ;
unsigned int V_37 , V_38 ;
T_5 V_39 ;
T_6 V_40 ;
int V_3 , V_41 ;
V_42 -> V_43 . V_44 = V_45 ;
F_8 () ;
V_31 -> V_46 [ V_47 ] &= 0x00000000ffffffffUL ;
V_33 = (struct V_32 T_2 * ) V_31 -> V_46 [ V_47 ] ;
if ( ! F_2 ( V_48 , V_33 , sizeof( * V_33 ) ) ||
( ( ( unsigned long ) V_33 ) & 3 ) )
goto V_49;
if ( F_9 ( V_37 , & V_33 -> V_50 . V_51 . V_37 ) ||
F_10 ( V_38 , & V_33 -> V_50 . V_51 . V_38 ) )
goto V_49;
if ( ( V_37 | V_38 ) & 3 )
goto V_49;
if ( F_11 ( V_52 ) ) {
V_37 &= 0xffffffff ;
V_38 &= 0xffffffff ;
}
V_31 -> V_53 = V_37 ;
V_31 -> V_54 = V_38 ;
V_3 = F_10 ( V_31 -> V_55 , & V_33 -> V_50 . V_51 . V_55 ) ;
V_3 |= F_10 ( V_36 , & V_33 -> V_50 . V_51 . V_36 ) ;
for ( V_41 = V_56 ; V_41 <= V_57 ; V_41 ++ )
V_3 |= F_10 ( V_31 -> V_46 [ V_41 ] , & V_33 -> V_50 . V_51 . V_46 [ V_41 ] ) ;
if ( ( V_36 & ( V_58 | V_59 ) ) == V_60 ) {
V_3 |= F_10 ( V_41 , & V_33 -> V_61 . V_62 [ 0 ] ) ;
if ( V_41 == V_63 ) {
unsigned long V_64 ;
for ( V_41 = V_56 ; V_41 <= V_57 ; V_41 ++ )
V_3 |= F_10 ( ( ( V_65 * ) V_31 -> V_46 ) [ 2 * V_41 ] , & V_33 -> V_61 . V_62 [ V_41 ] ) ;
V_3 |= F_10 ( V_64 , & V_33 -> V_61 . V_64 ) ;
V_31 -> V_66 &= ~ V_67 ;
V_31 -> V_66 |= ( ( V_64 & 0xffUL ) << 24UL ) ;
}
}
V_31 -> V_66 &= ~ ( V_68 | V_69 ) ;
V_31 -> V_66 |= F_12 ( V_36 ) ;
F_13 ( V_31 ) ;
V_3 |= F_10 ( V_34 , & V_33 -> V_34 ) ;
if ( ! V_3 && V_34 )
V_3 |= F_14 ( V_31 , F_15 ( V_34 ) ) ;
V_3 |= F_10 ( V_35 , & V_33 -> V_35 ) ;
if ( ! V_3 && V_35 ) {
if ( F_16 ( F_15 ( V_35 ) ) )
goto V_49;
}
V_3 |= F_10 ( V_40 . V_70 [ 0 ] , & V_33 -> V_50 . V_71 ) ;
V_3 |= F_6 ( & V_40 . V_70 [ 1 ] , & V_33 -> V_72 ,
( V_73 - 1 ) * sizeof( unsigned int ) ) ;
if ( V_3 )
goto V_49;
V_39 . V_70 [ 0 ] = V_40 . V_70 [ 0 ] + ( ( ( long ) V_40 . V_70 [ 1 ] ) << 32 ) ;
F_17 ( & V_39 ) ;
return;
V_49:
F_18 ( V_74 , V_42 ) ;
}
T_7 void F_19 ( struct V_30 * V_31 )
{
struct V_75 T_2 * V_33 ;
unsigned int V_36 , V_37 , V_38 ;
T_4 V_34 ;
T_4 V_35 ;
T_5 V_39 ;
T_6 V_40 ;
int V_3 , V_41 ;
V_42 -> V_43 . V_44 = V_45 ;
F_8 () ;
V_31 -> V_46 [ V_47 ] &= 0x00000000ffffffffUL ;
V_33 = (struct V_75 T_2 * ) V_31 -> V_46 [ V_47 ] ;
if ( ! F_2 ( V_48 , V_33 , sizeof( * V_33 ) ) ||
( ( ( unsigned long ) V_33 ) & 3 ) )
goto V_49;
if ( F_9 ( V_37 , & V_33 -> V_31 . V_37 ) ||
F_10 ( V_38 , & V_33 -> V_31 . V_38 ) )
goto V_49;
if ( ( V_37 | V_38 ) & 3 )
goto V_49;
if ( F_11 ( V_52 ) ) {
V_37 &= 0xffffffff ;
V_38 &= 0xffffffff ;
}
V_31 -> V_53 = V_37 ;
V_31 -> V_54 = V_38 ;
V_3 = F_10 ( V_31 -> V_55 , & V_33 -> V_31 . V_55 ) ;
V_3 |= F_10 ( V_36 , & V_33 -> V_31 . V_36 ) ;
for ( V_41 = V_56 ; V_41 <= V_57 ; V_41 ++ )
V_3 |= F_10 ( V_31 -> V_46 [ V_41 ] , & V_33 -> V_31 . V_46 [ V_41 ] ) ;
if ( ( V_36 & ( V_58 | V_59 ) ) == V_60 ) {
V_3 |= F_10 ( V_41 , & V_33 -> V_61 . V_62 [ 0 ] ) ;
if ( V_41 == V_63 ) {
unsigned long V_64 ;
for ( V_41 = V_56 ; V_41 <= V_57 ; V_41 ++ )
V_3 |= F_10 ( ( ( V_65 * ) V_31 -> V_46 ) [ 2 * V_41 ] , & V_33 -> V_61 . V_62 [ V_41 ] ) ;
V_3 |= F_10 ( V_64 , & V_33 -> V_61 . V_64 ) ;
V_31 -> V_66 &= ~ V_67 ;
V_31 -> V_66 |= ( ( V_64 & 0xffUL ) << 24UL ) ;
}
}
V_31 -> V_66 &= ~ ( V_68 | V_69 ) ;
V_31 -> V_66 |= F_12 ( V_36 ) ;
F_13 ( V_31 ) ;
V_3 |= F_10 ( V_34 , & V_33 -> V_34 ) ;
if ( ! V_3 && V_34 )
V_3 |= F_14 ( V_31 , F_15 ( V_34 ) ) ;
V_3 |= F_6 ( & V_40 , & V_33 -> V_76 , sizeof( T_6 ) ) ;
V_3 |= F_20 ( & V_33 -> V_77 ) ;
if ( V_3 )
goto V_49;
V_3 |= F_10 ( V_35 , & V_33 -> V_35 ) ;
if ( ! V_3 && V_35 ) {
if ( F_16 ( F_15 ( V_35 ) ) )
goto V_49;
}
V_39 . V_70 [ 0 ] = V_40 . V_70 [ 0 ] + ( ( ( long ) V_40 . V_70 [ 1 ] ) << 32 ) ;
F_17 ( & V_39 ) ;
return;
V_49:
F_18 ( V_74 , V_42 ) ;
}
static int F_21 ( void T_2 * V_78 , int V_79 )
{
if ( ( ( ( unsigned long ) V_78 ) & 7 ) || ( ( unsigned long ) V_78 ) > 0x100000000ULL - V_79 )
return 1 ;
return 0 ;
}
static void T_2 * F_22 ( struct V_80 * V_81 , struct V_30 * V_31 , unsigned long V_82 )
{
unsigned long V_83 ;
V_31 -> V_46 [ V_47 ] &= 0x00000000ffffffffUL ;
V_83 = V_31 -> V_46 [ V_47 ] ;
if ( F_23 ( V_83 ) && ! F_24 ( F_23 ( V_83 - V_82 ) ) )
return ( void T_2 * ) - 1L ;
V_83 = F_25 ( V_83 , V_81 ) - V_82 ;
V_83 &= ~ 15UL ;
return ( void T_2 * ) V_83 ;
}
static void F_26 ( unsigned long V_84 )
{
unsigned long V_85 , V_86 ;
T_8 * V_87 , V_88 ;
T_9 * V_89 ;
T_10 * V_90 ;
T_11 * V_91 ;
F_27 () ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
__asm__ __volatile__("wrpr %0, %1, %%pstate"
: : "r" (pstate), "i" (PSTATE_IE));
V_89 = F_28 ( V_42 -> V_92 , V_84 ) ;
if ( F_29 ( * V_89 ) )
goto V_93;
V_90 = F_30 ( V_89 , V_84 ) ;
if ( F_31 ( * V_90 ) )
goto V_93;
V_91 = F_32 ( V_90 , V_84 ) ;
if ( F_33 ( * V_91 ) )
goto V_93;
V_87 = F_34 ( V_91 , V_84 ) ;
V_88 = * V_87 ;
if ( ! F_35 ( V_88 ) )
goto V_94;
V_86 = ( unsigned long ) F_36 ( F_37 ( V_88 ) ) ;
__asm__ __volatile__("flush %0 + %1"
:
: "r" (paddr),
"r" (address & (PAGE_SIZE - 1))
: "memory");
V_94:
F_38 ( V_87 ) ;
V_93:
__asm__ __volatile__("wrpr %0, 0x0, %%pstate" : : "r" (pstate));
}
static int F_39 ( struct V_80 * V_81 , struct V_30 * V_31 ,
T_5 * V_95 )
{
struct V_32 T_2 * V_33 ;
int V_41 , V_3 , V_96 ;
void T_2 * V_97 ;
int V_98 ;
V_65 V_36 ;
T_6 V_40 ;
F_8 () ;
F_40 () ;
V_96 = F_41 () ;
V_98 = sizeof( * V_33 ) ;
if ( F_42 () -> V_99 [ 0 ] & V_100 )
V_98 += sizeof( V_101 ) ;
if ( V_96 )
V_98 += sizeof( V_102 ) ;
V_33 = (struct V_32 T_2 * )
F_22 ( V_81 , V_31 , V_98 ) ;
if ( F_21 ( V_33 , V_98 ) ) {
F_43 ( V_103 ) ;
return - V_104 ;
}
V_97 = ( V_33 + 1 ) ;
if ( F_11 ( V_52 ) ) {
V_31 -> V_53 &= 0xffffffff ;
V_31 -> V_54 &= 0xffffffff ;
}
V_3 = F_44 ( V_31 -> V_53 , & V_33 -> V_50 . V_51 . V_37 ) ;
V_3 |= F_3 ( V_31 -> V_54 , & V_33 -> V_50 . V_51 . V_38 ) ;
V_3 |= F_3 ( V_31 -> V_55 , & V_33 -> V_50 . V_51 . V_55 ) ;
V_36 = F_45 ( V_31 -> V_66 ) ;
if ( F_42 () -> V_99 [ 0 ] & V_100 )
V_36 |= V_105 ;
V_3 |= F_3 ( V_36 , & V_33 -> V_50 . V_51 . V_36 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
V_3 |= F_3 ( V_31 -> V_46 [ V_41 ] , & V_33 -> V_50 . V_51 . V_46 [ V_41 ] ) ;
V_3 |= F_3 ( sizeof( V_106 ) , & V_33 -> V_107 ) ;
V_3 |= F_3 ( V_63 , & V_33 -> V_61 . V_62 [ 0 ] ) ;
for ( V_41 = 1 ; V_41 < 16 ; V_41 ++ )
V_3 |= F_3 ( ( ( V_65 * ) V_31 -> V_46 ) [ 2 * V_41 ] ,
& V_33 -> V_61 . V_62 [ V_41 ] ) ;
V_3 |= F_3 ( ( V_31 -> V_66 & V_67 ) >> 24UL ,
& V_33 -> V_61 . V_64 ) ;
if ( V_36 & V_105 ) {
V_101 T_2 * V_78 = V_97 ;
V_97 += sizeof( * V_78 ) ;
V_3 |= F_46 ( V_31 , V_78 ) ;
V_3 |= F_3 ( ( V_108 ) V_78 , & V_33 -> V_34 ) ;
} else {
V_3 |= F_3 ( 0 , & V_33 -> V_34 ) ;
}
if ( V_96 ) {
V_102 T_2 * V_109 = V_97 ;
V_97 += sizeof( * V_109 ) ;
V_3 |= F_47 ( V_96 , V_109 ) ;
V_3 |= F_3 ( ( V_108 ) V_109 , & V_33 -> V_35 ) ;
F_48 ( 0 ) ;
} else {
V_3 |= F_3 ( 0 , & V_33 -> V_35 ) ;
}
F_49 ( V_110 != 1 ) ;
F_49 ( V_73 != 2 ) ;
V_40 . V_70 [ 1 ] = ( V_95 -> V_70 [ 0 ] >> 32 ) ;
V_40 . V_70 [ 0 ] = V_95 -> V_70 [ 0 ] ;
V_3 |= F_3 ( V_40 . V_70 [ 0 ] , & V_33 -> V_50 . V_71 ) ;
V_3 |= F_4 ( V_33 -> V_72 , & V_40 . V_70 [ 1 ] ,
( V_73 - 1 ) * sizeof( unsigned int ) ) ;
if ( ! V_96 ) {
V_3 |= F_50 ( ( V_65 T_2 * ) V_33 ,
( V_65 T_2 * ) ( V_31 -> V_46 [ V_47 ] ) ,
sizeof( struct V_111 ) ) ;
} else {
struct V_112 * V_113 ;
V_113 = & F_42 () -> V_112 [ V_96 - 1 ] ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
V_3 |= F_3 ( V_113 -> V_114 [ V_41 ] , & V_33 -> V_115 . V_114 [ V_41 ] ) ;
for ( V_41 = 0 ; V_41 < 6 ; V_41 ++ )
V_3 |= F_3 ( V_113 -> V_116 [ V_41 ] , & V_33 -> V_115 . V_116 [ V_41 ] ) ;
V_3 |= F_3 ( V_113 -> V_116 [ 6 ] , & V_33 -> V_115 . V_78 ) ;
V_3 |= F_3 ( V_113 -> V_116 [ 7 ] , & V_33 -> V_115 . V_117 ) ;
}
if ( V_3 )
return V_3 ;
V_31 -> V_46 [ V_47 ] = ( unsigned long ) V_33 ;
V_31 -> V_46 [ V_118 ] = V_81 -> V_70 ;
V_31 -> V_46 [ V_119 ] = ( unsigned long ) & V_33 -> V_50 ;
V_31 -> V_46 [ V_120 ] = ( unsigned long ) & V_33 -> V_50 ;
V_31 -> V_53 = ( unsigned long ) V_81 -> V_121 . V_122 . V_123 ;
V_31 -> V_54 = ( V_31 -> V_53 + 4 ) ;
if ( F_11 ( V_52 ) ) {
V_31 -> V_53 &= 0xffffffff ;
V_31 -> V_54 &= 0xffffffff ;
}
if ( V_81 -> V_121 . V_124 ) {
V_31 -> V_46 [ V_57 ] = ( unsigned long ) V_81 -> V_121 . V_124 ;
} else {
unsigned long V_84 = ( ( unsigned long ) & ( V_33 -> V_125 [ 0 ] ) ) ;
V_31 -> V_46 [ V_57 ] = ( unsigned long ) ( & ( V_33 -> V_125 [ 0 ] ) - 2 ) ;
V_3 = F_3 ( 0x821020d8 , & V_33 -> V_125 [ 0 ] ) ;
V_3 |= F_3 ( 0x91d02010 , & V_33 -> V_125 [ 1 ] ) ;
if ( V_3 )
return V_3 ;
F_26 ( V_84 ) ;
}
return 0 ;
}
static int F_51 ( struct V_80 * V_81 , struct V_30 * V_31 ,
T_5 * V_95 )
{
struct V_75 T_2 * V_33 ;
int V_41 , V_3 , V_96 ;
void T_2 * V_97 ;
int V_98 ;
V_65 V_36 ;
T_6 V_40 ;
F_8 () ;
F_40 () ;
V_96 = F_41 () ;
V_98 = sizeof( * V_33 ) ;
if ( F_42 () -> V_99 [ 0 ] & V_100 )
V_98 += sizeof( V_101 ) ;
if ( V_96 )
V_98 += sizeof( V_102 ) ;
V_33 = (struct V_75 T_2 * )
F_22 ( V_81 , V_31 , V_98 ) ;
if ( F_21 ( V_33 , V_98 ) ) {
F_43 ( V_103 ) ;
return - V_104 ;
}
V_97 = ( V_33 + 1 ) ;
if ( F_11 ( V_52 ) ) {
V_31 -> V_53 &= 0xffffffff ;
V_31 -> V_54 &= 0xffffffff ;
}
V_3 = F_44 ( V_31 -> V_53 , & V_33 -> V_31 . V_37 ) ;
V_3 |= F_3 ( V_31 -> V_54 , & V_33 -> V_31 . V_38 ) ;
V_3 |= F_3 ( V_31 -> V_55 , & V_33 -> V_31 . V_55 ) ;
V_36 = F_45 ( V_31 -> V_66 ) ;
if ( F_42 () -> V_99 [ 0 ] & V_100 )
V_36 |= V_105 ;
V_3 |= F_3 ( V_36 , & V_33 -> V_31 . V_36 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
V_3 |= F_3 ( V_31 -> V_46 [ V_41 ] , & V_33 -> V_31 . V_46 [ V_41 ] ) ;
V_3 |= F_3 ( sizeof( V_106 ) , & V_33 -> V_107 ) ;
V_3 |= F_3 ( V_63 , & V_33 -> V_61 . V_62 [ 0 ] ) ;
for ( V_41 = 1 ; V_41 < 16 ; V_41 ++ )
V_3 |= F_3 ( ( ( V_65 * ) V_31 -> V_46 ) [ 2 * V_41 ] ,
& V_33 -> V_61 . V_62 [ V_41 ] ) ;
V_3 |= F_3 ( ( V_31 -> V_66 & V_67 ) >> 24UL ,
& V_33 -> V_61 . V_64 ) ;
if ( V_36 & V_105 ) {
V_101 T_2 * V_78 = V_97 ;
V_97 += sizeof( * V_78 ) ;
V_3 |= F_46 ( V_31 , V_78 ) ;
V_3 |= F_3 ( ( V_108 ) V_78 , & V_33 -> V_34 ) ;
} else {
V_3 |= F_3 ( 0 , & V_33 -> V_34 ) ;
}
if ( V_96 ) {
V_102 T_2 * V_109 = V_97 ;
V_97 += sizeof( * V_109 ) ;
V_3 |= F_47 ( V_96 , V_109 ) ;
V_3 |= F_3 ( ( V_108 ) V_109 , & V_33 -> V_35 ) ;
F_48 ( 0 ) ;
} else {
V_3 |= F_3 ( 0 , & V_33 -> V_35 ) ;
}
V_3 |= F_1 ( & V_33 -> V_50 , & V_81 -> V_50 ) ;
V_3 |= F_52 ( & V_33 -> V_77 , V_31 -> V_46 [ V_47 ] ) ;
V_40 . V_70 [ 1 ] = ( V_95 -> V_70 [ 0 ] >> 32 ) ;
V_40 . V_70 [ 0 ] = V_95 -> V_70 [ 0 ] ;
V_3 |= F_4 ( & V_33 -> V_76 , & V_40 , sizeof( T_6 ) ) ;
if ( ! V_96 ) {
V_3 |= F_50 ( ( V_65 T_2 * ) V_33 ,
( V_65 T_2 * ) ( V_31 -> V_46 [ V_47 ] ) ,
sizeof( struct V_111 ) ) ;
} else {
struct V_112 * V_113 ;
V_113 = & F_42 () -> V_112 [ V_96 - 1 ] ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
V_3 |= F_3 ( V_113 -> V_114 [ V_41 ] , & V_33 -> V_115 . V_114 [ V_41 ] ) ;
for ( V_41 = 0 ; V_41 < 6 ; V_41 ++ )
V_3 |= F_3 ( V_113 -> V_116 [ V_41 ] , & V_33 -> V_115 . V_116 [ V_41 ] ) ;
V_3 |= F_3 ( V_113 -> V_116 [ 6 ] , & V_33 -> V_115 . V_78 ) ;
V_3 |= F_3 ( V_113 -> V_116 [ 7 ] , & V_33 -> V_115 . V_117 ) ;
}
if ( V_3 )
return V_3 ;
V_31 -> V_46 [ V_47 ] = ( unsigned long ) V_33 ;
V_31 -> V_46 [ V_118 ] = V_81 -> V_70 ;
V_31 -> V_46 [ V_119 ] = ( unsigned long ) & V_33 -> V_50 ;
V_31 -> V_46 [ V_120 ] = ( unsigned long ) & V_33 -> V_31 ;
V_31 -> V_53 = ( unsigned long ) V_81 -> V_121 . V_122 . V_123 ;
V_31 -> V_54 = ( V_31 -> V_53 + 4 ) ;
if ( F_11 ( V_52 ) ) {
V_31 -> V_53 &= 0xffffffff ;
V_31 -> V_54 &= 0xffffffff ;
}
if ( V_81 -> V_121 . V_124 )
V_31 -> V_46 [ V_57 ] = ( unsigned long ) V_81 -> V_121 . V_124 ;
else {
unsigned long V_84 = ( ( unsigned long ) & ( V_33 -> V_125 [ 0 ] ) ) ;
V_31 -> V_46 [ V_57 ] = ( unsigned long ) ( & ( V_33 -> V_125 [ 0 ] ) - 2 ) ;
V_3 |= F_3 ( 0x82102065 , & V_33 -> V_125 [ 0 ] ) ;
V_3 |= F_3 ( 0x91d02010 , & V_33 -> V_125 [ 1 ] ) ;
if ( V_3 )
return V_3 ;
F_26 ( V_84 ) ;
}
return 0 ;
}
static inline void F_53 ( struct V_80 * V_81 ,
struct V_30 * V_31 )
{
T_5 * V_95 = F_54 () ;
int V_3 ;
if ( V_81 -> V_121 . V_122 . V_126 & V_127 )
V_3 = F_51 ( V_81 , V_31 , V_95 ) ;
else
V_3 = F_39 ( V_81 , V_31 , V_95 ) ;
F_55 ( V_3 , V_81 , 0 ) ;
}
static inline void F_56 ( unsigned long V_128 , struct V_30 * V_31 ,
struct V_129 * V_122 )
{
switch ( V_31 -> V_46 [ V_118 ] ) {
case V_130 :
case V_131 :
V_132:
V_31 -> V_46 [ V_118 ] = V_133 ;
V_31 -> V_66 |= V_134 ;
break;
case V_135 :
if ( ! ( V_122 -> V_126 & V_136 ) )
goto V_132;
case V_137 :
V_31 -> V_46 [ V_118 ] = V_128 ;
V_31 -> V_53 -= 4 ;
V_31 -> V_54 -= 4 ;
}
}
void F_57 ( struct V_30 * V_31 )
{
struct V_80 V_81 ;
unsigned long V_128 = 0 ;
int V_138 = 0 ;
bool V_139 = F_58 ( & V_81 ) ;
if ( F_59 ( V_31 ) &&
( V_31 -> V_66 & ( V_140 | V_134 ) ) ) {
V_138 = 1 ;
V_128 = V_31 -> V_46 [ V_141 ] ;
}
if ( V_139 ) {
if ( V_138 )
F_56 ( V_128 , V_31 , & V_81 . V_121 . V_122 ) ;
F_53 ( & V_81 , V_31 ) ;
} else {
if ( V_138 ) {
switch ( V_31 -> V_46 [ V_118 ] ) {
case V_131 :
case V_135 :
case V_137 :
V_31 -> V_46 [ V_118 ] = V_128 ;
V_31 -> V_53 -= 4 ;
V_31 -> V_54 -= 4 ;
F_13 ( V_31 ) ;
case V_130 :
V_31 -> V_46 [ V_56 ] = V_142 ;
V_31 -> V_53 -= 4 ;
V_31 -> V_54 -= 4 ;
F_13 ( V_31 ) ;
}
}
F_60 () ;
}
}
T_7 int F_61 ( V_65 V_143 , V_65 V_144 , unsigned long V_83 )
{
struct V_145 T_2 * V_146 =
(struct V_145 T_2 * ) ( ( unsigned long ) ( V_143 ) ) ;
struct V_145 T_2 * V_147 =
(struct V_145 T_2 * ) ( ( unsigned long ) ( V_144 ) ) ;
int V_148 = - V_5 ;
if ( V_147 ) {
if ( F_44 ( V_42 -> V_149 + V_42 -> V_150 ,
& V_147 -> V_151 ) ||
F_3 ( F_23 ( V_83 ) , & V_147 -> V_152 ) )
goto V_153;
}
if ( V_146 ) {
V_65 V_154 ;
if ( F_9 ( V_154 , & V_146 -> V_151 ) )
goto V_153;
V_148 = - V_155 ;
if ( V_42 -> V_149 && F_23 ( V_83 ) )
goto V_153;
V_42 -> V_149 = ( unsigned long ) V_154 - V_156 ;
V_42 -> V_150 = V_156 ;
}
V_148 = 0 ;
V_153:
return V_148 ;
}
