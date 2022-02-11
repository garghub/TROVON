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
static bool F_7 ( void T_2 * V_30 , int V_31 )
{
if ( ( ( ( unsigned long ) V_30 ) & 15 ) ||
( ( unsigned long ) V_30 ) > 0x100000000ULL - V_31 )
return true ;
return false ;
}
void F_8 ( struct V_32 * V_33 )
{
struct V_34 T_2 * V_35 ;
T_4 V_36 ;
T_4 V_37 ;
unsigned int V_38 , V_39 ;
unsigned int V_40 , V_41 ;
T_5 V_42 ;
T_6 V_43 ;
int V_3 , V_44 ;
V_45 -> V_46 . V_47 = V_48 ;
F_9 () ;
V_33 -> V_49 [ V_50 ] &= 0x00000000ffffffffUL ;
V_35 = (struct V_34 T_2 * ) V_33 -> V_49 [ V_50 ] ;
if ( F_7 ( V_35 , sizeof( * V_35 ) ) )
goto V_51;
if ( F_10 ( V_39 , & V_35 -> V_52 . V_53 . V_49 [ V_50 ] ) )
goto V_51;
if ( V_39 & 0x7 )
goto V_51;
if ( F_11 ( V_40 , & V_35 -> V_52 . V_53 . V_40 ) ||
F_11 ( V_41 , & V_35 -> V_52 . V_53 . V_41 ) )
goto V_51;
if ( ( V_40 | V_41 ) & 3 )
goto V_51;
if ( F_12 ( V_54 ) ) {
V_40 &= 0xffffffff ;
V_41 &= 0xffffffff ;
}
V_33 -> V_55 = V_40 ;
V_33 -> V_56 = V_41 ;
V_3 = F_11 ( V_33 -> V_57 , & V_35 -> V_52 . V_53 . V_57 ) ;
V_3 |= F_11 ( V_38 , & V_35 -> V_52 . V_53 . V_38 ) ;
for ( V_44 = V_58 ; V_44 <= V_59 ; V_44 ++ )
V_3 |= F_11 ( V_33 -> V_49 [ V_44 ] , & V_35 -> V_52 . V_53 . V_49 [ V_44 ] ) ;
if ( ( V_38 & ( V_60 | V_61 ) ) == V_62 ) {
V_3 |= F_11 ( V_44 , & V_35 -> V_63 . V_64 [ 0 ] ) ;
if ( V_44 == V_65 ) {
unsigned long V_66 ;
for ( V_44 = V_58 ; V_44 <= V_59 ; V_44 ++ )
V_3 |= F_11 ( ( ( V_67 * ) V_33 -> V_49 ) [ 2 * V_44 ] , & V_35 -> V_63 . V_64 [ V_44 ] ) ;
V_3 |= F_11 ( V_66 , & V_35 -> V_63 . V_66 ) ;
V_33 -> V_68 &= ~ V_69 ;
V_33 -> V_68 |= ( ( V_66 & 0xffUL ) << 24UL ) ;
}
}
V_33 -> V_68 &= ~ ( V_70 | V_71 ) ;
V_33 -> V_68 |= F_13 ( V_38 ) ;
F_14 ( V_33 ) ;
V_3 |= F_11 ( V_36 , & V_35 -> V_36 ) ;
if ( ! V_3 && V_36 )
V_3 |= F_15 ( V_33 , F_16 ( V_36 ) ) ;
V_3 |= F_11 ( V_37 , & V_35 -> V_37 ) ;
if ( ! V_3 && V_37 ) {
if ( F_17 ( F_16 ( V_37 ) ) )
goto V_51;
}
V_3 |= F_11 ( V_43 . V_72 [ 0 ] , & V_35 -> V_52 . V_73 ) ;
V_3 |= F_6 ( & V_43 . V_72 [ 1 ] , & V_35 -> V_74 ,
( V_75 - 1 ) * sizeof( unsigned int ) ) ;
if ( V_3 )
goto V_51;
V_42 . V_72 [ 0 ] = V_43 . V_72 [ 0 ] + ( ( ( long ) V_43 . V_72 [ 1 ] ) << 32 ) ;
F_18 ( & V_42 ) ;
return;
V_51:
F_19 ( V_76 , V_45 ) ;
}
T_7 void F_20 ( struct V_32 * V_33 )
{
struct V_77 T_2 * V_35 ;
unsigned int V_38 , V_40 , V_41 , V_39 ;
T_4 V_36 ;
T_4 V_37 ;
T_5 V_42 ;
T_6 V_43 ;
int V_3 , V_44 ;
V_45 -> V_46 . V_47 = V_48 ;
F_9 () ;
V_33 -> V_49 [ V_50 ] &= 0x00000000ffffffffUL ;
V_35 = (struct V_77 T_2 * ) V_33 -> V_49 [ V_50 ] ;
if ( F_7 ( V_35 , sizeof( * V_35 ) ) )
goto V_51;
if ( F_10 ( V_39 , & V_35 -> V_33 . V_49 [ V_50 ] ) )
goto V_51;
if ( V_39 & 0x7 )
goto V_51;
if ( F_11 ( V_40 , & V_35 -> V_33 . V_40 ) ||
F_11 ( V_41 , & V_35 -> V_33 . V_41 ) )
goto V_51;
if ( ( V_40 | V_41 ) & 3 )
goto V_51;
if ( F_12 ( V_54 ) ) {
V_40 &= 0xffffffff ;
V_41 &= 0xffffffff ;
}
V_33 -> V_55 = V_40 ;
V_33 -> V_56 = V_41 ;
V_3 = F_11 ( V_33 -> V_57 , & V_35 -> V_33 . V_57 ) ;
V_3 |= F_11 ( V_38 , & V_35 -> V_33 . V_38 ) ;
for ( V_44 = V_58 ; V_44 <= V_59 ; V_44 ++ )
V_3 |= F_11 ( V_33 -> V_49 [ V_44 ] , & V_35 -> V_33 . V_49 [ V_44 ] ) ;
if ( ( V_38 & ( V_60 | V_61 ) ) == V_62 ) {
V_3 |= F_11 ( V_44 , & V_35 -> V_63 . V_64 [ 0 ] ) ;
if ( V_44 == V_65 ) {
unsigned long V_66 ;
for ( V_44 = V_58 ; V_44 <= V_59 ; V_44 ++ )
V_3 |= F_11 ( ( ( V_67 * ) V_33 -> V_49 ) [ 2 * V_44 ] , & V_35 -> V_63 . V_64 [ V_44 ] ) ;
V_3 |= F_11 ( V_66 , & V_35 -> V_63 . V_66 ) ;
V_33 -> V_68 &= ~ V_69 ;
V_33 -> V_68 |= ( ( V_66 & 0xffUL ) << 24UL ) ;
}
}
V_33 -> V_68 &= ~ ( V_70 | V_71 ) ;
V_33 -> V_68 |= F_13 ( V_38 ) ;
F_14 ( V_33 ) ;
V_3 |= F_11 ( V_36 , & V_35 -> V_36 ) ;
if ( ! V_3 && V_36 )
V_3 |= F_15 ( V_33 , F_16 ( V_36 ) ) ;
V_3 |= F_6 ( & V_43 , & V_35 -> V_78 , sizeof( T_6 ) ) ;
V_3 |= F_21 ( & V_35 -> V_79 ) ;
if ( V_3 )
goto V_51;
V_3 |= F_11 ( V_37 , & V_35 -> V_37 ) ;
if ( ! V_3 && V_37 ) {
if ( F_17 ( F_16 ( V_37 ) ) )
goto V_51;
}
V_42 . V_72 [ 0 ] = V_43 . V_72 [ 0 ] + ( ( ( long ) V_43 . V_72 [ 1 ] ) << 32 ) ;
F_18 ( & V_42 ) ;
return;
V_51:
F_19 ( V_76 , V_45 ) ;
}
static void T_2 * F_22 ( struct V_80 * V_81 , struct V_32 * V_33 , unsigned long V_82 )
{
unsigned long V_83 ;
V_33 -> V_49 [ V_50 ] &= 0x00000000ffffffffUL ;
V_83 = V_33 -> V_49 [ V_50 ] ;
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
V_89 = F_28 ( V_45 -> V_92 , V_84 ) ;
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
static int F_39 ( struct V_80 * V_81 , struct V_32 * V_33 ,
T_5 * V_95 )
{
struct V_34 T_2 * V_35 ;
int V_44 , V_3 , V_96 ;
void T_2 * V_97 ;
int V_98 ;
V_67 V_38 ;
T_6 V_43 ;
F_9 () ;
F_40 () ;
V_96 = F_41 () ;
V_98 = sizeof( * V_35 ) ;
if ( F_42 () -> V_99 [ 0 ] & V_100 )
V_98 += sizeof( V_101 ) ;
if ( V_96 )
V_98 += sizeof( V_102 ) ;
V_35 = (struct V_34 T_2 * )
F_22 ( V_81 , V_33 , V_98 ) ;
if ( F_7 ( V_35 , V_98 ) ) {
F_43 ( V_103 ) ;
return - V_104 ;
}
V_97 = ( V_35 + 1 ) ;
if ( F_12 ( V_54 ) ) {
V_33 -> V_55 &= 0xffffffff ;
V_33 -> V_56 &= 0xffffffff ;
}
V_3 = F_44 ( V_33 -> V_55 , & V_35 -> V_52 . V_53 . V_40 ) ;
V_3 |= F_3 ( V_33 -> V_56 , & V_35 -> V_52 . V_53 . V_41 ) ;
V_3 |= F_3 ( V_33 -> V_57 , & V_35 -> V_52 . V_53 . V_57 ) ;
V_38 = F_45 ( V_33 -> V_68 ) ;
if ( F_42 () -> V_99 [ 0 ] & V_100 )
V_38 |= V_105 ;
V_3 |= F_3 ( V_38 , & V_35 -> V_52 . V_53 . V_38 ) ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_3 |= F_3 ( V_33 -> V_49 [ V_44 ] , & V_35 -> V_52 . V_53 . V_49 [ V_44 ] ) ;
V_3 |= F_3 ( sizeof( V_106 ) , & V_35 -> V_107 ) ;
V_3 |= F_3 ( V_65 , & V_35 -> V_63 . V_64 [ 0 ] ) ;
for ( V_44 = 1 ; V_44 < 16 ; V_44 ++ )
V_3 |= F_3 ( ( ( V_67 * ) V_33 -> V_49 ) [ 2 * V_44 ] ,
& V_35 -> V_63 . V_64 [ V_44 ] ) ;
V_3 |= F_3 ( ( V_33 -> V_68 & V_69 ) >> 24UL ,
& V_35 -> V_63 . V_66 ) ;
if ( V_38 & V_105 ) {
V_101 T_2 * V_30 = V_97 ;
V_97 += sizeof( * V_30 ) ;
V_3 |= F_46 ( V_33 , V_30 ) ;
V_3 |= F_3 ( ( V_108 ) V_30 , & V_35 -> V_36 ) ;
} else {
V_3 |= F_3 ( 0 , & V_35 -> V_36 ) ;
}
if ( V_96 ) {
V_102 T_2 * V_109 = V_97 ;
V_97 += sizeof( * V_109 ) ;
V_3 |= F_47 ( V_96 , V_109 ) ;
V_3 |= F_3 ( ( V_108 ) V_109 , & V_35 -> V_37 ) ;
F_48 ( 0 ) ;
} else {
V_3 |= F_3 ( 0 , & V_35 -> V_37 ) ;
}
F_49 ( V_110 != 1 ) ;
F_49 ( V_75 != 2 ) ;
V_43 . V_72 [ 1 ] = ( V_95 -> V_72 [ 0 ] >> 32 ) ;
V_43 . V_72 [ 0 ] = V_95 -> V_72 [ 0 ] ;
V_3 |= F_3 ( V_43 . V_72 [ 0 ] , & V_35 -> V_52 . V_73 ) ;
V_3 |= F_4 ( V_35 -> V_74 , & V_43 . V_72 [ 1 ] ,
( V_75 - 1 ) * sizeof( unsigned int ) ) ;
if ( ! V_96 ) {
V_3 |= F_50 ( ( V_67 T_2 * ) V_35 ,
( V_67 T_2 * ) ( V_33 -> V_49 [ V_50 ] ) ,
sizeof( struct V_111 ) ) ;
} else {
struct V_112 * V_113 ;
V_113 = & F_42 () -> V_112 [ V_96 - 1 ] ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
V_3 |= F_3 ( V_113 -> V_114 [ V_44 ] , & V_35 -> V_115 . V_114 [ V_44 ] ) ;
for ( V_44 = 0 ; V_44 < 6 ; V_44 ++ )
V_3 |= F_3 ( V_113 -> V_116 [ V_44 ] , & V_35 -> V_115 . V_116 [ V_44 ] ) ;
V_3 |= F_3 ( V_113 -> V_116 [ 6 ] , & V_35 -> V_115 . V_30 ) ;
V_3 |= F_3 ( V_113 -> V_116 [ 7 ] , & V_35 -> V_115 . V_117 ) ;
}
if ( V_3 )
return V_3 ;
V_33 -> V_49 [ V_50 ] = ( unsigned long ) V_35 ;
V_33 -> V_49 [ V_118 ] = V_81 -> V_72 ;
V_33 -> V_49 [ V_119 ] = ( unsigned long ) & V_35 -> V_52 ;
V_33 -> V_49 [ V_120 ] = ( unsigned long ) & V_35 -> V_52 ;
V_33 -> V_55 = ( unsigned long ) V_81 -> V_121 . V_122 . V_123 ;
V_33 -> V_56 = ( V_33 -> V_55 + 4 ) ;
if ( F_12 ( V_54 ) ) {
V_33 -> V_55 &= 0xffffffff ;
V_33 -> V_56 &= 0xffffffff ;
}
if ( V_81 -> V_121 . V_124 ) {
V_33 -> V_49 [ V_59 ] = ( unsigned long ) V_81 -> V_121 . V_124 ;
} else {
unsigned long V_84 = ( ( unsigned long ) & ( V_35 -> V_125 [ 0 ] ) ) ;
V_33 -> V_49 [ V_59 ] = ( unsigned long ) ( & ( V_35 -> V_125 [ 0 ] ) - 2 ) ;
V_3 = F_3 ( 0x821020d8 , & V_35 -> V_125 [ 0 ] ) ;
V_3 |= F_3 ( 0x91d02010 , & V_35 -> V_125 [ 1 ] ) ;
if ( V_3 )
return V_3 ;
F_26 ( V_84 ) ;
}
return 0 ;
}
static int F_51 ( struct V_80 * V_81 , struct V_32 * V_33 ,
T_5 * V_95 )
{
struct V_77 T_2 * V_35 ;
int V_44 , V_3 , V_96 ;
void T_2 * V_97 ;
int V_98 ;
V_67 V_38 ;
T_6 V_43 ;
F_9 () ;
F_40 () ;
V_96 = F_41 () ;
V_98 = sizeof( * V_35 ) ;
if ( F_42 () -> V_99 [ 0 ] & V_100 )
V_98 += sizeof( V_101 ) ;
if ( V_96 )
V_98 += sizeof( V_102 ) ;
V_35 = (struct V_77 T_2 * )
F_22 ( V_81 , V_33 , V_98 ) ;
if ( F_7 ( V_35 , V_98 ) ) {
F_43 ( V_103 ) ;
return - V_104 ;
}
V_97 = ( V_35 + 1 ) ;
if ( F_12 ( V_54 ) ) {
V_33 -> V_55 &= 0xffffffff ;
V_33 -> V_56 &= 0xffffffff ;
}
V_3 = F_44 ( V_33 -> V_55 , & V_35 -> V_33 . V_40 ) ;
V_3 |= F_3 ( V_33 -> V_56 , & V_35 -> V_33 . V_41 ) ;
V_3 |= F_3 ( V_33 -> V_57 , & V_35 -> V_33 . V_57 ) ;
V_38 = F_45 ( V_33 -> V_68 ) ;
if ( F_42 () -> V_99 [ 0 ] & V_100 )
V_38 |= V_105 ;
V_3 |= F_3 ( V_38 , & V_35 -> V_33 . V_38 ) ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_3 |= F_3 ( V_33 -> V_49 [ V_44 ] , & V_35 -> V_33 . V_49 [ V_44 ] ) ;
V_3 |= F_3 ( sizeof( V_106 ) , & V_35 -> V_107 ) ;
V_3 |= F_3 ( V_65 , & V_35 -> V_63 . V_64 [ 0 ] ) ;
for ( V_44 = 1 ; V_44 < 16 ; V_44 ++ )
V_3 |= F_3 ( ( ( V_67 * ) V_33 -> V_49 ) [ 2 * V_44 ] ,
& V_35 -> V_63 . V_64 [ V_44 ] ) ;
V_3 |= F_3 ( ( V_33 -> V_68 & V_69 ) >> 24UL ,
& V_35 -> V_63 . V_66 ) ;
if ( V_38 & V_105 ) {
V_101 T_2 * V_30 = V_97 ;
V_97 += sizeof( * V_30 ) ;
V_3 |= F_46 ( V_33 , V_30 ) ;
V_3 |= F_3 ( ( V_108 ) V_30 , & V_35 -> V_36 ) ;
} else {
V_3 |= F_3 ( 0 , & V_35 -> V_36 ) ;
}
if ( V_96 ) {
V_102 T_2 * V_109 = V_97 ;
V_97 += sizeof( * V_109 ) ;
V_3 |= F_47 ( V_96 , V_109 ) ;
V_3 |= F_3 ( ( V_108 ) V_109 , & V_35 -> V_37 ) ;
F_48 ( 0 ) ;
} else {
V_3 |= F_3 ( 0 , & V_35 -> V_37 ) ;
}
V_3 |= F_1 ( & V_35 -> V_52 , & V_81 -> V_52 ) ;
V_3 |= F_52 ( & V_35 -> V_79 , V_33 -> V_49 [ V_50 ] ) ;
V_43 . V_72 [ 1 ] = ( V_95 -> V_72 [ 0 ] >> 32 ) ;
V_43 . V_72 [ 0 ] = V_95 -> V_72 [ 0 ] ;
V_3 |= F_4 ( & V_35 -> V_78 , & V_43 , sizeof( T_6 ) ) ;
if ( ! V_96 ) {
V_3 |= F_50 ( ( V_67 T_2 * ) V_35 ,
( V_67 T_2 * ) ( V_33 -> V_49 [ V_50 ] ) ,
sizeof( struct V_111 ) ) ;
} else {
struct V_112 * V_113 ;
V_113 = & F_42 () -> V_112 [ V_96 - 1 ] ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
V_3 |= F_3 ( V_113 -> V_114 [ V_44 ] , & V_35 -> V_115 . V_114 [ V_44 ] ) ;
for ( V_44 = 0 ; V_44 < 6 ; V_44 ++ )
V_3 |= F_3 ( V_113 -> V_116 [ V_44 ] , & V_35 -> V_115 . V_116 [ V_44 ] ) ;
V_3 |= F_3 ( V_113 -> V_116 [ 6 ] , & V_35 -> V_115 . V_30 ) ;
V_3 |= F_3 ( V_113 -> V_116 [ 7 ] , & V_35 -> V_115 . V_117 ) ;
}
if ( V_3 )
return V_3 ;
V_33 -> V_49 [ V_50 ] = ( unsigned long ) V_35 ;
V_33 -> V_49 [ V_118 ] = V_81 -> V_72 ;
V_33 -> V_49 [ V_119 ] = ( unsigned long ) & V_35 -> V_52 ;
V_33 -> V_49 [ V_120 ] = ( unsigned long ) & V_35 -> V_33 ;
V_33 -> V_55 = ( unsigned long ) V_81 -> V_121 . V_122 . V_123 ;
V_33 -> V_56 = ( V_33 -> V_55 + 4 ) ;
if ( F_12 ( V_54 ) ) {
V_33 -> V_55 &= 0xffffffff ;
V_33 -> V_56 &= 0xffffffff ;
}
if ( V_81 -> V_121 . V_124 )
V_33 -> V_49 [ V_59 ] = ( unsigned long ) V_81 -> V_121 . V_124 ;
else {
unsigned long V_84 = ( ( unsigned long ) & ( V_35 -> V_125 [ 0 ] ) ) ;
V_33 -> V_49 [ V_59 ] = ( unsigned long ) ( & ( V_35 -> V_125 [ 0 ] ) - 2 ) ;
V_3 |= F_3 ( 0x82102065 , & V_35 -> V_125 [ 0 ] ) ;
V_3 |= F_3 ( 0x91d02010 , & V_35 -> V_125 [ 1 ] ) ;
if ( V_3 )
return V_3 ;
F_26 ( V_84 ) ;
}
return 0 ;
}
static inline void F_53 ( struct V_80 * V_81 ,
struct V_32 * V_33 )
{
T_5 * V_95 = F_54 () ;
int V_3 ;
if ( V_81 -> V_121 . V_122 . V_126 & V_127 )
V_3 = F_51 ( V_81 , V_33 , V_95 ) ;
else
V_3 = F_39 ( V_81 , V_33 , V_95 ) ;
F_55 ( V_3 , V_81 , 0 ) ;
}
static inline void F_56 ( unsigned long V_128 , struct V_32 * V_33 ,
struct V_129 * V_122 )
{
switch ( V_33 -> V_49 [ V_118 ] ) {
case V_130 :
case V_131 :
V_132:
V_33 -> V_49 [ V_118 ] = V_133 ;
V_33 -> V_68 |= V_134 ;
break;
case V_135 :
if ( ! ( V_122 -> V_126 & V_136 ) )
goto V_132;
case V_137 :
V_33 -> V_49 [ V_118 ] = V_128 ;
V_33 -> V_55 -= 4 ;
V_33 -> V_56 -= 4 ;
}
}
void F_57 ( struct V_32 * V_33 )
{
struct V_80 V_81 ;
unsigned long V_128 = 0 ;
int V_138 = 0 ;
bool V_139 = F_58 ( & V_81 ) ;
if ( F_59 ( V_33 ) &&
( V_33 -> V_68 & ( V_140 | V_134 ) ) ) {
V_138 = 1 ;
V_128 = V_33 -> V_49 [ V_141 ] ;
}
if ( V_139 ) {
if ( V_138 )
F_56 ( V_128 , V_33 , & V_81 . V_121 . V_122 ) ;
F_53 ( & V_81 , V_33 ) ;
} else {
if ( V_138 ) {
switch ( V_33 -> V_49 [ V_118 ] ) {
case V_131 :
case V_135 :
case V_137 :
V_33 -> V_49 [ V_118 ] = V_128 ;
V_33 -> V_55 -= 4 ;
V_33 -> V_56 -= 4 ;
F_14 ( V_33 ) ;
case V_130 :
V_33 -> V_49 [ V_58 ] = V_142 ;
V_33 -> V_55 -= 4 ;
V_33 -> V_56 -= 4 ;
F_14 ( V_33 ) ;
}
}
F_60 () ;
}
}
T_7 int F_61 ( V_67 V_143 , V_67 V_144 , unsigned long V_83 )
{
struct V_145 T_2 * V_146 =
(struct V_145 T_2 * ) ( ( unsigned long ) ( V_143 ) ) ;
struct V_145 T_2 * V_147 =
(struct V_145 T_2 * ) ( ( unsigned long ) ( V_144 ) ) ;
int V_148 = - V_5 ;
if ( V_147 ) {
if ( F_44 ( V_45 -> V_149 + V_45 -> V_150 ,
& V_147 -> V_151 ) ||
F_3 ( F_23 ( V_83 ) , & V_147 -> V_152 ) )
goto V_153;
}
if ( V_146 ) {
V_67 V_154 ;
if ( F_10 ( V_154 , & V_146 -> V_151 ) )
goto V_153;
V_148 = - V_155 ;
if ( V_45 -> V_149 && F_23 ( V_83 ) )
goto V_153;
V_45 -> V_149 = ( unsigned long ) V_154 - V_156 ;
V_45 -> V_150 = V_156 ;
}
V_148 = 0 ;
V_153:
return V_148 ;
}
