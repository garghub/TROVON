static inline int F_1 ( unsigned long V_1 )
{
T_1 V_2 = F_2 ( F_3 ( V_1 ) ) ;
if( V_1 & V_3 )
F_4 ( 5 ) ;
return V_2 ;
}
static inline void F_5 ( unsigned long V_1 , T_1 V_4 )
{
F_6 ( V_4 , F_3 ( V_1 ) ) ;
if( V_1 & V_3 )
F_4 ( 5 ) ;
}
static inline T_1 F_7 ( struct V_5 * V_6 , T_1 V_7 )
{
if( V_7 )
F_5 ( V_6 -> V_8 , V_7 ) ;
return F_1 ( V_6 -> V_8 ) ;
}
static inline T_1 F_8 ( struct V_5 * V_6 )
{
T_1 V_2 ;
V_2 = F_1 ( V_6 -> V_9 ) ;
return V_2 ;
}
static inline void F_9 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_10 )
{
if( V_7 )
F_5 ( V_6 -> V_8 , V_7 ) ;
F_5 ( V_6 -> V_8 , V_10 ) ;
}
static inline void F_10 ( struct V_5 * V_6 , T_1 V_10 )
{
F_5 ( V_6 -> V_8 , V_10 ) ;
}
static inline void F_11 ( struct V_5 * V_6 , T_1 V_10 )
{
F_5 ( V_6 -> V_9 , V_10 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
F_7 ( V_6 , V_11 ) ;
F_7 ( V_6 , V_11 ) ;
F_7 ( V_6 , V_11 ) ;
F_7 ( V_6 , V_11 ) ;
if( V_6 -> V_12 -> type == V_13 )
{
F_7 ( V_6 , V_11 ) ;
F_7 ( V_6 , V_11 ) ;
F_7 ( V_6 , V_11 ) ;
F_7 ( V_6 , V_11 ) ;
}
}
static void F_13 ( struct V_5 * V_6 , int V_14 )
{
if ( V_14 )
V_6 -> V_15 [ 5 ] |= ( V_16 | V_17 ) ;
else
V_6 -> V_15 [ 5 ] &= ~ ( V_16 | V_17 ) ;
F_9 ( V_6 , V_18 , V_6 -> V_15 [ 5 ] ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
T_1 V_19 , V_20 ;
while( 1 )
{
if( ! ( F_7 ( V_6 , V_21 ) & 1 ) )
break;
V_19 = F_8 ( V_6 ) ;
V_20 = F_7 ( V_6 , V_11 ) ;
if( V_6 -> V_22 < V_6 -> V_23 )
{
* V_6 -> V_24 ++ = V_19 ;
V_6 -> V_22 ++ ;
}
if( V_20 & V_25 )
{
if( V_20 & ( V_26 | V_27 ) )
{
if( V_6 -> V_28 )
V_6 -> V_24 = V_6 -> V_28 -> V_29 ;
V_6 -> V_22 = 0 ;
if( V_20 & V_26 )
{
F_15 ( V_30 L_1 , V_6 -> V_12 -> V_31 ) ;
V_6 -> V_32 ++ ;
}
if( V_20 & V_27 )
{
V_6 -> V_33 ++ ;
}
}
else
{
F_16 ( V_6 ) ;
F_10 ( V_6 , V_34 ) ;
}
}
}
F_10 ( V_6 , V_35 ) ;
F_10 ( V_6 , V_36 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
while( V_6 -> V_37 ) {
if( ! ( F_7 ( V_6 , V_21 ) & 4 ) )
return;
V_6 -> V_37 -- ;
F_9 ( V_6 , V_38 , * V_6 -> V_39 ++ ) ;
F_10 ( V_6 , V_36 ) ;
if( V_6 -> V_37 == 0 )
{
F_10 ( V_6 , V_40 ) ;
F_9 ( V_6 , V_41 , V_6 -> V_15 [ 10 ] & ~ V_42 ) ;
}
}
F_10 ( V_6 , V_43 ) ;
F_18 ( V_6 ) ;
F_10 ( V_6 , V_36 ) ;
}
static void F_19 ( struct V_5 * V_44 )
{
T_1 V_45 , V_46 ;
V_45 = F_7 ( V_44 , V_21 ) ;
V_46 = V_44 -> V_45 ^ V_45 ;
V_44 -> V_45 = V_45 ;
if ( V_45 & V_47 ) {
V_44 -> V_48 -> V_49 . V_50 ++ ;
F_10 ( V_44 , V_35 ) ;
F_18 ( V_44 ) ;
}
if ( V_46 & V_44 -> V_51 )
{
if ( V_45 & V_44 -> V_51 ) {
F_15 ( V_52 L_2 , V_44 -> V_12 -> V_31 ) ;
F_9 ( V_44 , V_53 , V_44 -> V_15 [ 3 ] | V_54 ) ;
if ( V_44 -> V_48 )
F_20 ( V_44 -> V_48 ) ;
} else {
F_15 ( V_52 L_3 , V_44 -> V_12 -> V_31 ) ;
F_9 ( V_44 , V_53 , V_44 -> V_15 [ 3 ] & ~ V_54 ) ;
F_12 ( V_44 ) ;
if ( V_44 -> V_48 )
F_21 ( V_44 -> V_48 ) ;
}
}
F_10 ( V_44 , V_55 ) ;
F_10 ( V_44 , V_36 ) ;
}
static void F_22 ( struct V_5 * V_44 )
{
if( V_44 -> V_56 )
{
T_1 V_45 ;
F_7 ( V_44 , V_57 ) ;
F_7 ( V_44 , V_58 ) ;
V_45 = F_7 ( V_44 , V_11 ) ;
if( V_45 & V_25 )
{
F_16 ( V_44 ) ;
}
F_10 ( V_44 , V_35 ) ;
F_10 ( V_44 , V_36 ) ;
}
else
{
F_14 ( V_44 ) ;
}
}
static void F_23 ( struct V_5 * V_44 )
{
if( ! V_44 -> V_59 )
{
F_15 ( V_30 L_4 ) ;
F_17 ( V_44 ) ;
return;
}
F_15 ( V_60 L_5 ) ;
F_17 ( V_44 ) ;
}
static void F_24 ( struct V_5 * V_44 )
{
T_1 V_45 , V_46 ;
V_45 = F_7 ( V_44 , V_21 ) ;
V_46 = V_44 -> V_45 ^ V_45 ;
V_44 -> V_45 = V_45 ;
if( V_44 -> V_59 )
{
if( V_45 & V_47 )
{
unsigned long V_61 ;
V_61 = F_25 () ;
F_26 ( V_44 -> V_62 ) ;
F_27 ( V_44 -> V_62 ) ;
V_44 -> V_63 = 0 ;
F_28 ( V_61 ) ;
F_18 ( V_44 ) ;
}
}
if ( V_46 & V_44 -> V_51 )
{
if ( V_45 & V_44 -> V_51 ) {
F_15 ( V_52 L_2 , V_44 -> V_12 -> V_31 ) ;
F_9 ( V_44 , V_53 , V_44 -> V_15 [ 3 ] | V_54 ) ;
if ( V_44 -> V_48 )
F_20 ( V_44 -> V_48 ) ;
} else {
F_15 ( V_52 L_6 , V_44 -> V_12 -> V_31 ) ;
F_9 ( V_44 , V_53 , V_44 -> V_15 [ 3 ] & ~ V_54 ) ;
F_12 ( V_44 ) ;
if ( V_44 -> V_48 )
F_21 ( V_44 -> V_48 ) ;
}
}
F_10 ( V_44 , V_55 ) ;
F_10 ( V_44 , V_36 ) ;
}
static void F_29 ( struct V_5 * V_6 )
{
T_1 V_20 ;
F_8 ( V_6 ) ;
V_20 = F_7 ( V_6 , V_11 ) ;
if( V_20 & V_25 )
F_10 ( V_6 , V_34 ) ;
F_10 ( V_6 , V_35 ) ;
F_10 ( V_6 , V_36 ) ;
}
static void F_30 ( struct V_5 * V_6 )
{
F_10 ( V_6 , V_43 ) ;
F_10 ( V_6 , V_36 ) ;
}
static void F_31 ( struct V_5 * V_44 )
{
T_1 V_45 = F_7 ( V_44 , V_21 ) ;
if( V_45 & V_47 )
F_10 ( V_44 , V_35 ) ;
F_10 ( V_44 , V_55 ) ;
F_10 ( V_44 , V_36 ) ;
}
T_2 F_32 ( int V_64 , void * V_65 )
{
struct V_66 * V_12 = V_65 ;
T_1 V_67 ( V_68 ) ;
static volatile int V_69 = 0 ;
int V_70 = 0 ;
struct V_71 * V_72 ;
if( V_69 )
{
F_15 ( V_60 L_7 ) ;
return V_73 ;
}
V_69 = 1 ;
F_33 ( & V_12 -> V_74 ) ;
while( ++ V_70 < 5000 )
{
V_68 = F_7 ( & V_12 -> V_75 , V_53 ) ;
if( ! ( V_68 & ( V_76 | V_77 | V_78 | V_79 | V_80 | V_81 ) ) )
break;
V_72 = V_12 -> V_75 . V_72 ;
if( V_68 & ( V_76 | V_77 | V_78 ) )
{
if( V_68 & V_76 )
V_72 -> V_82 ( & V_12 -> V_75 ) ;
if( V_68 & V_77 )
V_72 -> V_83 ( & V_12 -> V_75 ) ;
if( V_68 & V_78 )
V_72 -> V_45 ( & V_12 -> V_75 ) ;
}
V_72 = V_12 -> V_84 . V_72 ;
if( V_68 & ( V_79 | V_80 | V_81 ) )
{
if( V_68 & V_79 )
V_72 -> V_82 ( & V_12 -> V_84 ) ;
if( V_68 & V_80 )
V_72 -> V_83 ( & V_12 -> V_84 ) ;
if( V_68 & V_81 )
V_72 -> V_45 ( & V_12 -> V_84 ) ;
}
}
F_34 ( & V_12 -> V_74 ) ;
if( V_70 == 5000 )
F_15 ( V_60 L_8 , V_12 -> V_31 , V_68 ) ;
V_69 = 0 ;
return V_85 ;
}
int F_35 ( struct V_86 * V_12 , struct V_5 * V_6 )
{
unsigned long V_61 ;
F_36 ( V_6 -> V_74 , V_61 ) ;
V_6 -> V_87 = 1 ;
V_6 -> V_88 = V_12 -> V_88 + 64 ;
V_6 -> V_22 = 0 ;
V_6 -> V_28 = NULL ;
V_6 -> V_89 = NULL ;
V_6 -> V_72 = & V_90 ;
F_16 ( V_6 ) ;
F_16 ( V_6 ) ;
F_13 ( V_6 , 1 ) ;
V_6 -> V_59 = 0 ;
V_6 -> V_15 [ V_11 ] |= V_91 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
F_9 ( V_6 , V_53 , V_6 -> V_15 [ V_53 ] | V_54 ) ;
F_37 ( V_6 -> V_74 , V_61 ) ;
return 0 ;
}
int F_38 ( struct V_86 * V_12 , struct V_5 * V_6 )
{
T_1 V_92 ;
unsigned long V_61 ;
F_36 ( V_6 -> V_74 , V_61 ) ;
V_6 -> V_72 = & V_93 ;
V_6 -> V_23 = 0 ;
V_6 -> V_87 = 0 ;
V_92 = F_7 ( V_6 , V_21 ) ;
F_9 ( V_6 , V_53 , V_6 -> V_15 [ V_53 ] ) ;
F_13 ( V_6 , 0 ) ;
F_37 ( V_6 -> V_74 , V_61 ) ;
return 0 ;
}
int F_39 ( struct V_86 * V_12 , struct V_5 * V_6 )
{
unsigned long V_94 , V_95 ;
V_6 -> V_87 = 1 ;
V_6 -> V_88 = V_12 -> V_88 + 64 ;
V_6 -> V_22 = 0 ;
V_6 -> V_28 = NULL ;
V_6 -> V_89 = NULL ;
V_6 -> V_56 = 0 ;
V_6 -> V_63 = 0 ;
if( V_6 -> V_88 > V_96 / 2 )
return - V_97 ;
V_6 -> V_98 [ 0 ] = ( void * ) F_40 ( V_99 | V_100 ) ;
if( V_6 -> V_98 [ 0 ] == NULL )
return - V_101 ;
V_6 -> V_98 [ 1 ] = V_6 -> V_98 [ 0 ] + V_96 / 2 ;
V_6 -> V_102 [ 0 ] = ( void * ) F_40 ( V_99 | V_100 ) ;
if( V_6 -> V_102 [ 0 ] == NULL )
{
F_41 ( ( unsigned long ) V_6 -> V_98 [ 0 ] ) ;
V_6 -> V_98 [ 0 ] = NULL ;
return - V_101 ;
}
V_6 -> V_102 [ 1 ] = V_6 -> V_102 [ 0 ] + V_96 / 2 ;
V_6 -> V_103 = 0 ;
V_6 -> V_59 = 1 ;
V_6 -> V_104 = 0 ;
V_6 -> V_105 = 1 ;
F_36 ( V_6 -> V_74 , V_94 ) ;
V_6 -> V_15 [ V_106 ] |= V_107 ;
F_9 ( V_6 , V_106 , V_6 -> V_15 [ V_106 ] ) ;
V_6 -> V_15 [ V_11 ] &= ~ V_91 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
V_6 -> V_15 [ V_11 ] |= V_108 ;
V_6 -> V_15 [ V_11 ] |= V_109 ;
V_6 -> V_15 [ V_11 ] |= V_110 ;
V_6 -> V_15 [ V_11 ] &= ~ V_91 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
V_6 -> V_15 [ V_11 ] |= V_111 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
V_95 = F_25 () ;
F_26 ( V_6 -> V_112 ) ;
F_27 ( V_6 -> V_112 ) ;
F_42 ( V_6 -> V_112 , V_113 | 0x10 ) ;
F_43 ( V_6 -> V_112 , F_44 ( V_6 -> V_98 [ 0 ] ) ) ;
F_45 ( V_6 -> V_112 , V_6 -> V_88 ) ;
F_46 ( V_6 -> V_112 ) ;
F_26 ( V_6 -> V_62 ) ;
F_27 ( V_6 -> V_62 ) ;
F_42 ( V_6 -> V_62 , V_114 ) ;
F_26 ( V_6 -> V_62 ) ;
F_28 ( V_95 ) ;
V_6 -> V_56 = 1 ;
V_6 -> V_63 = 1 ;
V_6 -> V_103 = 1 ;
V_6 -> V_72 = & V_115 ;
F_13 ( V_6 , 1 ) ;
F_9 ( V_6 , V_53 , V_6 -> V_15 [ V_53 ] | V_54 ) ;
F_37 ( V_6 -> V_74 , V_94 ) ;
return 0 ;
}
int F_47 ( struct V_86 * V_12 , struct V_5 * V_6 )
{
T_1 V_92 ;
unsigned long V_61 ;
V_6 -> V_72 = & V_93 ;
V_6 -> V_23 = 0 ;
V_6 -> V_87 = 0 ;
V_61 = F_25 () ;
F_26 ( V_6 -> V_112 ) ;
F_27 ( V_6 -> V_112 ) ;
V_6 -> V_56 = 0 ;
F_26 ( V_6 -> V_62 ) ;
F_27 ( V_6 -> V_62 ) ;
F_28 ( V_61 ) ;
V_6 -> V_63 = 0 ;
V_6 -> V_103 = 0 ;
F_36 ( V_6 -> V_74 , V_61 ) ;
V_6 -> V_15 [ V_11 ] &= ~ V_111 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
V_6 -> V_15 [ V_11 ] &= ~ ( V_109 | V_108 | V_110 ) ;
V_6 -> V_15 [ V_11 ] |= V_116 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
V_6 -> V_15 [ V_106 ] &= ~ V_107 ;
F_9 ( V_6 , V_106 , V_6 -> V_15 [ V_106 ] ) ;
if( V_6 -> V_98 [ 0 ] )
{
F_41 ( ( unsigned long ) V_6 -> V_98 [ 0 ] ) ;
V_6 -> V_98 [ 0 ] = NULL ;
}
if( V_6 -> V_102 [ 0 ] )
{
F_41 ( ( unsigned long ) V_6 -> V_102 [ 0 ] ) ;
V_6 -> V_102 [ 0 ] = NULL ;
}
V_92 = F_7 ( V_6 , V_21 ) ;
F_9 ( V_6 , V_53 , V_6 -> V_15 [ V_53 ] ) ;
F_13 ( V_6 , 0 ) ;
F_37 ( V_6 -> V_74 , V_61 ) ;
return 0 ;
}
int F_48 ( struct V_86 * V_12 , struct V_5 * V_6 )
{
unsigned long V_94 , V_95 ;
F_15 ( L_9 ) ;
V_6 -> V_87 = 1 ;
V_6 -> V_88 = V_12 -> V_88 + 64 ;
V_6 -> V_22 = 0 ;
V_6 -> V_28 = NULL ;
V_6 -> V_89 = NULL ;
if( V_6 -> V_88 > V_96 / 2 )
return - V_97 ;
V_6 -> V_102 [ 0 ] = ( void * ) F_40 ( V_99 | V_100 ) ;
if( V_6 -> V_102 [ 0 ] == NULL )
return - V_101 ;
V_6 -> V_102 [ 1 ] = V_6 -> V_102 [ 0 ] + V_96 / 2 ;
F_36 ( V_6 -> V_74 , V_94 ) ;
F_16 ( V_6 ) ;
F_16 ( V_6 ) ;
V_6 -> V_56 = 0 ;
V_6 -> V_63 = 0 ;
V_6 -> V_103 = 0 ;
V_6 -> V_104 = 0 ;
V_6 -> V_105 = 1 ;
V_6 -> V_59 = 1 ;
V_6 -> V_15 [ V_106 ] |= V_107 ;
F_9 ( V_6 , V_106 , V_6 -> V_15 [ V_106 ] ) ;
V_6 -> V_15 [ V_11 ] &= ~ V_91 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
V_95 = F_25 () ;
F_26 ( V_6 -> V_62 ) ;
F_27 ( V_6 -> V_62 ) ;
F_42 ( V_6 -> V_62 , V_114 ) ;
F_26 ( V_6 -> V_62 ) ;
F_28 ( V_95 ) ;
V_6 -> V_56 = 0 ;
V_6 -> V_63 = 1 ;
V_6 -> V_103 = 1 ;
V_6 -> V_72 = & V_117 ;
F_13 ( V_6 , 1 ) ;
F_9 ( V_6 , V_53 , V_6 -> V_15 [ V_53 ] | V_54 ) ;
F_37 ( V_6 -> V_74 , V_94 ) ;
return 0 ;
}
int F_49 ( struct V_86 * V_12 , struct V_5 * V_6 )
{
unsigned long V_95 , V_94 ;
T_1 V_92 ;
F_36 ( V_6 -> V_74 , V_94 ) ;
V_6 -> V_72 = & V_93 ;
V_6 -> V_23 = 0 ;
V_6 -> V_87 = 0 ;
V_95 = F_25 () ;
F_26 ( V_6 -> V_62 ) ;
F_27 ( V_6 -> V_62 ) ;
V_6 -> V_63 = 0 ;
V_6 -> V_103 = 0 ;
F_28 ( V_95 ) ;
V_6 -> V_15 [ V_11 ] &= ~ V_111 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
V_6 -> V_15 [ V_11 ] &= ~ ( V_109 | V_108 | V_110 ) ;
V_6 -> V_15 [ V_11 ] |= V_116 ;
F_9 ( V_6 , V_11 , V_6 -> V_15 [ V_11 ] ) ;
V_6 -> V_15 [ V_106 ] &= ~ V_107 ;
F_9 ( V_6 , V_106 , V_6 -> V_15 [ V_106 ] ) ;
if( V_6 -> V_102 [ 0 ] )
{
F_41 ( ( unsigned long ) V_6 -> V_102 [ 0 ] ) ;
V_6 -> V_102 [ 0 ] = NULL ;
}
V_92 = F_7 ( V_6 , V_21 ) ;
F_9 ( V_6 , V_53 , V_6 -> V_15 [ V_53 ] ) ;
F_13 ( V_6 , 0 ) ;
F_37 ( V_6 -> V_74 , V_94 ) ;
return 0 ;
}
void F_50 ( struct V_66 * V_12 , char * V_118 , unsigned long V_119 )
{
F_15 ( V_52 L_10 ,
V_12 -> V_31 ,
V_120 [ V_12 -> type ] ,
V_118 ,
F_3 ( V_119 ) ,
V_12 -> V_64 ) ;
}
static inline int F_51 ( struct V_66 * V_12 )
{
V_12 -> V_75 . V_72 = & V_93 ;
V_12 -> V_84 . V_72 = & V_93 ;
V_12 -> V_75 . V_51 = V_121 ;
V_12 -> V_84 . V_51 = V_121 ;
F_9 ( & V_12 -> V_75 , V_122 , 0xC0 ) ;
F_4 ( 200 ) ;
F_9 ( & V_12 -> V_75 , V_123 , 0xAA ) ;
if( F_7 ( & V_12 -> V_75 , V_123 ) != 0xAA )
return - V_124 ;
F_9 ( & V_12 -> V_75 , V_123 , 0x55 ) ;
if( F_7 ( & V_12 -> V_75 , V_123 ) != 0x55 )
return - V_124 ;
V_12 -> type = V_125 ;
F_9 ( & V_12 -> V_75 , V_126 , 0x01 ) ;
if( F_7 ( & V_12 -> V_75 , V_126 ) == 0x01 )
{
F_9 ( & V_12 -> V_75 , V_38 , 0 ) ;
if( F_7 ( & V_12 -> V_75 , V_21 ) & V_127 )
V_12 -> type = V_13 ;
else
V_12 -> type = V_128 ;
}
F_9 ( & V_12 -> V_75 , V_126 , 0 ) ;
memcpy ( V_12 -> V_75 . V_15 , V_129 , 16 ) ;
memcpy ( V_12 -> V_84 . V_15 , V_129 , 16 ) ;
return 0 ;
}
int F_52 ( struct V_66 * V_12 )
{
unsigned long V_61 ;
int V_130 ;
F_53 ( & V_12 -> V_74 ) ;
V_12 -> V_75 . V_74 = & V_12 -> V_74 ;
V_12 -> V_84 . V_74 = & V_12 -> V_74 ;
F_36 ( & V_12 -> V_74 , V_61 ) ;
V_130 = F_51 ( V_12 ) ;
F_37 ( & V_12 -> V_74 , V_61 ) ;
return V_130 ;
}
int F_54 ( struct V_66 * V_12 )
{
unsigned long V_61 ;
F_36 ( & V_12 -> V_74 , V_61 ) ;
V_12 -> V_75 . V_72 = & V_93 ;
V_12 -> V_84 . V_72 = & V_93 ;
F_9 ( & V_12 -> V_75 , V_122 , 0xC0 ) ;
F_4 ( 100 ) ;
F_37 ( & V_12 -> V_74 , V_61 ) ;
return 0 ;
}
int F_55 ( struct V_5 * V_6 , T_1 * V_131 )
{
unsigned long V_61 ;
F_36 ( V_6 -> V_74 , V_61 ) ;
while( * V_131 != 255 )
{
int V_7 = * V_131 ++ ;
if( V_7 > 0x0F )
F_9 ( V_6 , V_126 , V_6 -> V_15 [ 15 ] | 1 ) ;
F_9 ( V_6 , V_7 & 0x0F , * V_131 ) ;
if( V_7 > 0x0F )
F_9 ( V_6 , V_126 , V_6 -> V_15 [ 15 ] & ~ 1 ) ;
V_6 -> V_15 [ V_7 ] = * V_131 ++ ;
}
V_6 -> V_132 = V_133 ;
V_6 -> V_28 = NULL ;
V_6 -> V_134 = NULL ;
V_6 -> V_135 = NULL ;
V_6 -> V_88 = 1500 ;
V_6 -> V_23 = 0 ;
V_6 -> V_22 = 0 ;
V_6 -> V_45 = F_7 ( V_6 , V_21 ) ;
V_6 -> V_87 = 1 ;
F_9 ( V_6 , V_53 , V_6 -> V_15 [ V_53 ] | V_54 ) ;
F_37 ( V_6 -> V_74 , V_61 ) ;
return 0 ;
}
static void F_56 ( struct V_5 * V_6 )
{
unsigned long V_61 ;
if( V_6 -> V_134 )
return;
V_6 -> V_134 = V_6 -> V_135 ;
V_6 -> V_135 = NULL ;
V_6 -> V_39 = V_6 -> V_136 ;
if( V_6 -> V_134 == NULL )
{
if( V_6 -> V_59 )
{
V_61 = F_25 () ;
F_26 ( V_6 -> V_62 ) ;
if ( F_57 ( V_6 -> V_62 ) )
{
V_6 -> V_48 -> V_49 . V_137 ++ ;
V_6 -> V_48 -> V_49 . V_50 ++ ;
}
F_28 ( V_61 ) ;
}
V_6 -> V_37 = 0 ;
}
else
{
V_6 -> V_37 = V_6 -> V_134 -> V_138 ;
if( V_6 -> V_59 )
{
V_61 = F_25 () ;
F_26 ( V_6 -> V_62 ) ;
if( V_6 -> V_12 -> type != V_13 )
{
F_10 ( V_6 , V_139 ) ;
F_10 ( V_6 , V_40 ) ;
}
F_9 ( V_6 , V_41 , V_6 -> V_15 [ 10 ] & ~ V_42 ) ;
F_27 ( V_6 -> V_62 ) ;
F_43 ( V_6 -> V_62 , F_44 ( V_6 -> V_39 ) ) ;
F_45 ( V_6 -> V_62 , V_6 -> V_37 ) ;
F_46 ( V_6 -> V_62 ) ;
F_28 ( V_61 ) ;
F_10 ( V_6 , V_40 ) ;
F_9 ( V_6 , V_18 , V_6 -> V_15 [ V_18 ] | V_140 ) ;
}
else
{
F_9 ( V_6 , V_41 , V_6 -> V_15 [ 10 ] ) ;
F_10 ( V_6 , V_139 ) ;
while( V_6 -> V_37 && ( F_7 ( V_6 , V_21 ) & V_127 ) )
{
F_9 ( V_6 , V_38 , * V_6 -> V_39 ++ ) ;
V_6 -> V_37 -- ;
}
}
}
F_58 ( V_6 -> V_48 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
struct V_141 * V_28 ;
if ( V_6 -> V_134 == NULL )
return;
V_28 = V_6 -> V_134 ;
V_6 -> V_134 = NULL ;
F_56 ( V_6 ) ;
V_6 -> V_48 -> V_49 . V_142 ++ ;
V_6 -> V_48 -> V_49 . V_143 += V_28 -> V_138 ;
F_59 ( V_28 ) ;
}
void V_133 ( struct V_5 * V_6 , struct V_141 * V_28 )
{
F_60 ( V_28 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_141 * V_28 ;
int V_144 ;
if( V_6 -> V_56 )
{
int V_145 = V_6 -> V_105 ;
unsigned char * V_146 = V_6 -> V_98 [ V_6 -> V_104 ] ;
unsigned long V_61 ;
V_61 = F_25 () ;
F_26 ( V_6 -> V_112 ) ;
F_27 ( V_6 -> V_112 ) ;
V_6 -> V_56 = 0 ;
V_144 = V_6 -> V_88 - F_57 ( V_6 -> V_112 ) ;
if( V_144 < 0 )
V_144 = 2 ;
V_6 -> V_105 = 0 ;
if( V_145 )
{
V_6 -> V_104 ^= 1 ;
F_42 ( V_6 -> V_112 , V_113 | 0x10 ) ;
F_43 ( V_6 -> V_112 , F_44 ( V_6 -> V_98 [ V_6 -> V_104 ] ) ) ;
F_45 ( V_6 -> V_112 , V_6 -> V_88 ) ;
V_6 -> V_56 = 1 ;
F_46 ( V_6 -> V_112 ) ;
F_9 ( V_6 , V_21 , V_34 ) ;
}
else
F_15 ( V_30 L_11 ,
V_6 -> V_48 -> V_31 ) ;
F_28 ( V_61 ) ;
V_28 = F_61 ( V_144 ) ;
if ( V_28 == NULL ) {
V_6 -> V_48 -> V_49 . V_147 ++ ;
F_15 ( V_30 L_12 ,
V_6 -> V_48 -> V_31 ) ;
} else {
F_62 ( V_28 , V_144 ) ;
F_63 ( V_28 , V_146 , V_144 ) ;
V_6 -> V_48 -> V_49 . V_148 ++ ;
V_6 -> V_48 -> V_49 . V_149 += V_144 ;
}
V_6 -> V_105 = 1 ;
} else {
V_150 ;
V_28 = V_6 -> V_28 ;
V_144 = V_6 -> V_22 ;
V_6 -> V_28 = V_6 -> V_89 ;
V_6 -> V_22 = 0 ;
V_6 -> V_23 = V_6 -> V_88 ;
if ( V_6 -> V_28 ) {
V_6 -> V_24 = V_6 -> V_28 -> V_29 ;
V_6 -> V_23 = V_6 -> V_88 ;
} else {
V_6 -> V_22 = 0 ;
V_6 -> V_23 = 0 ;
}
V_151 ;
V_6 -> V_89 = F_61 ( V_6 -> V_88 ) ;
if ( V_6 -> V_89 == NULL )
F_15 ( V_30 L_13 ,
V_6 -> V_48 -> V_31 ) ;
else
F_62 ( V_6 -> V_89 , V_6 -> V_88 ) ;
V_6 -> V_48 -> V_49 . V_148 ++ ;
V_6 -> V_48 -> V_49 . V_149 += V_144 ;
}
if ( V_28 ) {
F_64 ( V_28 , V_144 ) ;
V_6 -> V_132 ( V_6 , V_28 ) ;
} else {
V_6 -> V_48 -> V_49 . V_147 ++ ;
F_15 ( V_60 L_14 , V_6 -> V_48 -> V_31 ) ;
}
}
static inline int F_65 ( struct V_141 * V_28 )
{
unsigned long V_152 = ( unsigned long ) V_28 -> V_29 ;
V_152 ^= ( V_152 + V_28 -> V_138 ) ;
if( V_152 & 0x00010000 )
return 1 ;
return 0 ;
}
T_3 F_66 ( struct V_5 * V_6 , struct V_141 * V_28 )
{
unsigned long V_61 ;
F_67 ( V_6 -> V_48 ) ;
if( V_6 -> V_135 )
return V_153 ;
if( V_6 -> V_59 && ( ( unsigned long ) ( F_44 ( V_28 -> V_29 + V_28 -> V_138 ) ) >= 16 * 1024 * 1024 || F_65 ( V_28 ) ) )
{
V_6 -> V_136 = V_6 -> V_102 [ V_6 -> V_103 ] ;
V_6 -> V_103 ^= 1 ;
F_68 ( V_28 , V_6 -> V_136 , V_28 -> V_138 ) ;
}
else
V_6 -> V_136 = V_28 -> V_29 ;
V_150 ;
V_6 -> V_135 = V_28 ;
V_151 ;
F_36 ( V_6 -> V_74 , V_61 ) ;
F_56 ( V_6 ) ;
F_37 ( V_6 -> V_74 , V_61 ) ;
return V_154 ;
}
static int T_4 F_69 ( void )
{
F_15 ( V_155 ) ;
return 0 ;
}
static void T_5 F_70 ( void )
{
}
