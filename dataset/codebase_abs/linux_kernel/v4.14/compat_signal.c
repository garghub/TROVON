static inline void F_1 ( unsigned long * V_1 ,
T_1 * V_2 )
{
V_2 [ 0 ] = ( T_1 ) V_1 [ 0 ] ;
V_2 [ 1 ] = ( T_1 ) ( V_1 [ 0 ] >> 32 ) ;
}
static inline void F_2 ( T_1 * V_2 ,
unsigned long * V_1 )
{
V_1 [ 0 ] = ( unsigned long ) V_2 [ 0 ] | ( ( unsigned long ) V_2 [ 1 ] << 32 ) ;
}
int F_3 ( T_2 T_3 * V_3 , const T_4 * V_4 )
{
int V_5 ;
V_5 = F_4 ( V_4 -> V_6 , & V_3 -> V_6 ) ;
V_5 |= F_4 ( V_4 -> V_7 , & V_3 -> V_7 ) ;
V_5 |= F_4 ( V_4 -> V_8 , & V_3 -> V_8 ) ;
if ( V_4 -> V_8 < 0 )
V_5 |= F_5 ( & V_3 -> V_9 . V_10 , & V_4 -> V_9 . V_10 , V_11 ) ;
else {
switch ( F_6 ( V_4 -> V_6 , V_4 -> V_8 ) ) {
case V_12 :
V_5 |= F_4 ( V_4 -> V_13 , & V_3 -> V_13 ) ;
case V_14 :
V_5 |= F_4 ( V_4 -> V_15 , & V_3 -> V_15 ) ;
V_5 |= F_4 ( V_4 -> V_16 , & V_3 -> V_16 ) ;
break;
case V_17 :
V_5 |= F_4 ( V_4 -> V_15 , & V_3 -> V_15 ) ;
V_5 |= F_4 ( V_4 -> V_16 , & V_3 -> V_16 ) ;
V_5 |= F_4 ( V_4 -> V_18 , & V_3 -> V_18 ) ;
V_5 |= F_4 ( V_4 -> V_19 , & V_3 -> V_19 ) ;
V_5 |= F_4 ( V_4 -> V_20 , & V_3 -> V_20 ) ;
break;
case V_21 :
V_5 |= F_4 ( ( unsigned long ) V_4 -> V_22 ,
& V_3 -> V_22 ) ;
break;
case V_23 :
V_5 |= F_4 ( V_4 -> V_24 , & V_3 -> V_24 ) ;
V_5 |= F_4 ( V_4 -> V_25 , & V_3 -> V_25 ) ;
break;
case V_26 :
V_5 |= F_4 ( V_4 -> V_27 , & V_3 -> V_27 ) ;
V_5 |= F_4 ( V_4 -> V_28 , & V_3 -> V_28 ) ;
V_5 |= F_4 ( V_4 -> V_13 , & V_3 -> V_13 ) ;
break;
default:
break;
}
}
return V_5 ? - V_29 : 0 ;
}
int F_7 ( T_4 * V_3 , T_2 T_3 * V_4 )
{
int V_5 ;
T_5 V_30 ;
V_5 = F_8 ( V_3 -> V_6 , & V_4 -> V_6 ) ;
V_5 |= F_8 ( V_3 -> V_7 , & V_4 -> V_7 ) ;
V_5 |= F_8 ( V_3 -> V_8 , & V_4 -> V_8 ) ;
if ( V_3 -> V_8 < 0 )
V_5 |= F_9 ( & V_3 -> V_9 . V_10 , & V_4 -> V_9 . V_10 , V_11 ) ;
else {
switch ( F_6 ( V_3 -> V_6 , V_3 -> V_8 ) ) {
case V_12 :
V_5 |= F_8 ( V_3 -> V_13 , & V_4 -> V_13 ) ;
case V_14 :
V_5 |= F_8 ( V_3 -> V_15 , & V_4 -> V_15 ) ;
V_5 |= F_8 ( V_3 -> V_16 , & V_4 -> V_16 ) ;
break;
case V_17 :
V_5 |= F_8 ( V_3 -> V_15 , & V_4 -> V_15 ) ;
V_5 |= F_8 ( V_3 -> V_16 , & V_4 -> V_16 ) ;
V_5 |= F_8 ( V_3 -> V_18 , & V_4 -> V_18 ) ;
V_5 |= F_8 ( V_3 -> V_19 , & V_4 -> V_19 ) ;
V_5 |= F_8 ( V_3 -> V_20 , & V_4 -> V_20 ) ;
break;
case V_21 :
V_5 |= F_8 ( V_30 , & V_4 -> V_22 ) ;
V_3 -> V_22 = ( void V_31 T_3 * )
( V_32 ) ( V_30 & V_33 ) ;
break;
case V_23 :
V_5 |= F_8 ( V_3 -> V_24 , & V_4 -> V_24 ) ;
V_5 |= F_8 ( V_3 -> V_25 , & V_4 -> V_25 ) ;
break;
case V_26 :
V_5 |= F_8 ( V_3 -> V_27 , & V_4 -> V_27 ) ;
V_5 |= F_8 ( V_3 -> V_28 , & V_4 -> V_28 ) ;
V_5 |= F_8 ( V_3 -> V_13 , & V_4 -> V_13 ) ;
break;
default:
break;
}
}
return V_5 ? - V_29 : 0 ;
}
static void F_10 ( void )
{
F_11 ( V_34 -> V_35 . V_36 ) ;
F_12 () ;
}
static void F_13 ( void )
{
F_14 ( V_34 -> V_35 . V_36 ) ;
}
static int F_15 ( struct V_37 * V_38 , T_6 T_3 * V_39 )
{
T_6 V_40 ;
int V_41 ;
V_40 . V_38 . V_42 . V_43 = ( V_44 ) ( V_38 -> V_42 . V_43 >> 32 ) ;
V_40 . V_38 . V_42 . V_43 &= V_45 | V_46 ;
V_40 . V_38 . V_42 . V_43 |= V_47 ;
V_40 . V_38 . V_42 . V_48 = ( V_44 ) V_38 -> V_42 . V_48 |
( V_44 ) ( V_38 -> V_42 . V_43 & V_49 ) ;
for ( V_41 = 0 ; V_41 < V_50 ; V_41 ++ )
V_40 . V_38 . V_51 [ V_41 ] = ( V_44 ) V_38 -> V_51 [ V_41 ] ;
memcpy ( & V_40 . V_38 . V_36 , V_34 -> V_35 . V_36 ,
sizeof( V_40 . V_38 . V_36 ) ) ;
F_16 ( ( V_52 * ) & V_40 . V_53 , & V_34 -> V_35 . V_54 ) ;
if ( F_5 ( V_39 , & V_40 , sizeof( T_6 ) ) )
return - V_29 ;
return 0 ;
}
static int F_17 ( struct V_37 * V_38 , T_6 T_3 * V_39 )
{
T_6 V_40 ;
int V_41 ;
V_34 -> V_55 . V_56 = V_57 ;
if ( F_9 ( & V_40 , & V_39 -> V_38 , sizeof( V_40 ) ) )
return - V_29 ;
if ( ! F_18 ( V_34 ) && ( V_40 . V_38 . V_42 . V_43 & V_46 ) )
return - V_58 ;
if ( F_19 ( V_40 . V_53 . V_59 ) )
return - V_58 ;
V_38 -> V_42 . V_43 = ( V_38 -> V_42 . V_43 & ~ ( V_60 | V_61 ) ) |
( V_62 ) ( V_40 . V_38 . V_42 . V_43 & V_45 ) << 32 |
( V_62 ) ( V_40 . V_38 . V_42 . V_43 & V_46 ) << 32 |
( V_62 ) ( V_40 . V_38 . V_42 . V_48 & V_63 ) ;
if ( ( V_38 -> V_42 . V_43 & V_64 ) == V_65 )
V_38 -> V_42 . V_43 = V_66 |
( V_38 -> V_42 . V_43 & ~ V_64 ) ;
V_38 -> V_42 . V_48 = ( V_62 ) ( V_40 . V_38 . V_42 . V_48 & V_33 ) ;
for ( V_41 = 0 ; V_41 < V_50 ; V_41 ++ )
V_38 -> V_51 [ V_41 ] = ( V_62 ) V_40 . V_38 . V_51 [ V_41 ] ;
memcpy ( & V_34 -> V_35 . V_36 , & V_40 . V_38 . V_36 ,
sizeof( V_34 -> V_35 . V_36 ) ) ;
F_20 ( ( V_52 * ) & V_40 . V_53 , & V_34 -> V_35 . V_54 ) ;
F_21 ( V_38 , V_67 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_38 ,
T_7 T_3 * V_68 )
{
V_44 V_69 [ V_50 ] ;
V_62 V_70 [ V_71 ] ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_50 ; V_41 ++ )
V_69 [ V_41 ] = V_38 -> V_51 [ V_41 ] >> 32 ;
if ( F_5 ( & V_68 -> V_69 , & V_69 ,
sizeof( V_68 -> V_69 ) ) )
return - V_29 ;
if ( V_72 ) {
for ( V_41 = 0 ; V_41 < V_71 ; V_41 ++ )
V_70 [ V_41 ] = * ( ( V_62 * ) ( V_34 -> V_35 . V_54 . V_70 + V_41 ) + 1 ) ;
if ( F_5 ( & V_68 -> V_73 , V_70 ,
sizeof( V_68 -> V_73 ) ) ||
F_5 ( & V_68 -> V_74 ,
V_34 -> V_35 . V_54 . V_70 + V_71 ,
sizeof( V_68 -> V_74 ) ) )
return - V_29 ;
}
return 0 ;
}
static int F_23 ( struct V_37 * V_38 ,
T_7 T_3 * V_68 )
{
V_44 V_69 [ V_50 ] ;
V_62 V_70 [ V_71 ] ;
int V_41 ;
if ( F_9 ( & V_69 , & V_68 -> V_69 ,
sizeof( V_68 -> V_69 ) ) )
return - V_29 ;
for ( V_41 = 0 ; V_41 < V_50 ; V_41 ++ )
* ( V_44 * ) & V_38 -> V_51 [ V_41 ] = V_69 [ V_41 ] ;
if ( V_72 ) {
if ( F_9 ( V_70 , & V_68 -> V_73 ,
sizeof( V_68 -> V_73 ) ) ||
F_9 ( V_34 -> V_35 . V_54 . V_70 + V_71 ,
& V_68 -> V_74 ,
sizeof( V_68 -> V_74 ) ) )
return - V_29 ;
for ( V_41 = 0 ; V_41 < V_71 ; V_41 ++ )
* ( ( V_62 * ) ( V_34 -> V_35 . V_54 . V_70 + V_41 ) + 1 ) = V_70 [ V_41 ] ;
}
return 0 ;
}
static inline void T_3 *
F_24 ( struct V_75 * V_76 , struct V_37 * V_38 , T_8 V_77 )
{
unsigned long V_78 ;
V_78 = ( unsigned long ) F_25 ( V_38 -> V_51 [ 15 ] ) ;
if ( F_26 ( V_78 ) && ! F_26 ( ( V_78 - V_77 ) & - 8UL ) )
return ( void T_3 * ) - 1UL ;
if ( V_76 -> V_79 . V_80 & V_81 ) {
if ( ! F_27 ( V_78 ) )
V_78 = V_34 -> V_82 + V_34 -> V_83 ;
}
return ( void T_3 * ) ( ( V_78 - V_77 ) & - 8ul ) ;
}
static int F_28 ( struct V_84 * V_85 , T_9 * V_86 ,
struct V_37 * V_38 )
{
int V_87 = V_85 -> V_87 ;
T_10 T_3 * V_88 ;
struct V_89 V_90 ;
unsigned long V_91 ;
T_8 V_77 ;
V_77 = sizeof( * V_88 ) - sizeof( V_88 -> V_68 . V_92 ) ;
if ( ! V_72 )
V_77 -= sizeof( V_88 -> V_68 . V_73 ) +
sizeof( V_88 -> V_68 . V_74 ) ;
V_88 = F_24 ( & V_85 -> V_76 , V_38 , V_77 ) ;
if ( V_88 == ( void T_3 * ) - 1UL )
return - V_29 ;
if ( F_4 ( V_38 -> V_51 [ 15 ] , ( unsigned int T_3 * ) V_88 ) )
return - V_29 ;
F_1 ( V_86 -> V_87 , V_90 . V_93 ) ;
V_90 . V_39 = ( V_44 ) ( unsigned long V_31 ) & V_88 -> V_39 ;
if ( F_5 ( & V_88 -> V_90 , & V_90 , sizeof( V_88 -> V_90 ) ) )
return - V_29 ;
F_10 () ;
if ( F_15 ( V_38 , & V_88 -> V_39 ) )
return - V_29 ;
if ( F_4 ( V_38 -> V_51 [ 2 ] , ( int V_31 T_3 * ) & V_88 -> V_94 ) )
return - V_29 ;
if ( F_22 ( V_38 , & V_88 -> V_68 ) )
return - V_29 ;
if ( V_85 -> V_76 . V_79 . V_80 & V_95 ) {
V_91 = ( unsigned long V_31 )
V_85 -> V_76 . V_79 . V_96 | V_63 ;
} else {
T_11 T_3 * V_97 = ( void T_3 * ) V_88 + V_77 - 2 ;
if ( F_4 ( V_98 | V_99 , V_97 ) )
return - V_29 ;
V_91 = ( unsigned long V_31 ) V_97 | V_63 ;
}
V_38 -> V_51 [ 14 ] = V_91 ;
V_38 -> V_51 [ 15 ] = ( V_31 V_62 ) V_88 ;
V_38 -> V_42 . V_43 = V_49 |
( V_100 & V_64 ) |
( V_38 -> V_42 . V_43 & ~ V_64 ) ;
V_38 -> V_42 . V_48 = ( V_31 V_62 ) V_85 -> V_76 . V_79 . V_101 ;
V_38 -> V_51 [ 2 ] = V_87 ;
V_38 -> V_51 [ 3 ] = ( V_31 V_62 ) & V_88 -> V_90 ;
if ( V_87 == V_102 || V_87 == V_103 || V_87 == V_104 ||
V_87 == V_105 || V_87 == V_106 ) {
V_38 -> V_51 [ 4 ] = V_38 -> V_107 & 127 ;
V_38 -> V_51 [ 5 ] = V_38 -> V_108 ;
V_38 -> V_51 [ 6 ] = V_34 -> V_35 . V_109 ;
}
return 0 ;
}
static int F_29 ( struct V_84 * V_85 , T_9 * V_86 ,
struct V_37 * V_38 )
{
T_12 V_110 ;
T_13 T_3 * V_88 ;
unsigned long V_91 ;
T_8 V_77 ;
T_5 V_111 ;
V_77 = sizeof( * V_88 ) -
sizeof( V_88 -> V_112 . V_113 . V_92 ) ;
V_111 = V_114 ;
if ( V_72 ) {
V_111 |= V_115 ;
} else
V_77 -= sizeof( V_88 -> V_112 . V_113 . V_73 ) +
sizeof( V_88 -> V_112 . V_113 . V_74 ) ;
V_88 = F_24 ( & V_85 -> V_76 , V_38 , V_77 ) ;
if ( V_88 == ( void T_3 * ) - 1UL )
return - V_29 ;
if ( F_4 ( V_38 -> V_51 [ 15 ] , ( unsigned int V_31 T_3 * ) V_88 ) )
return - V_29 ;
if ( V_85 -> V_76 . V_79 . V_80 & V_95 ) {
V_91 = ( unsigned long V_31 )
V_85 -> V_76 . V_79 . V_96 | V_63 ;
} else {
T_11 T_3 * V_97 = & V_88 -> V_116 ;
if ( F_4 ( V_98 | V_117 , V_97 ) )
return - V_29 ;
V_91 = ( unsigned long V_31 ) V_97 | V_63 ;
}
if ( F_3 ( & V_88 -> V_118 , & V_85 -> V_118 ) )
return - V_29 ;
F_10 () ;
F_1 ( V_86 -> V_87 , V_110 . V_87 ) ;
if ( F_4 ( V_111 , & V_88 -> V_112 . V_111 ) ||
F_4 ( 0 , & V_88 -> V_112 . V_119 ) ||
F_30 ( & V_88 -> V_112 . V_120 , V_38 -> V_51 [ 15 ] ) ||
F_15 ( V_38 , & V_88 -> V_112 . V_121 ) ||
F_5 ( & V_88 -> V_112 . V_122 , & V_110 , sizeof( V_110 ) ) ||
F_22 ( V_38 , & V_88 -> V_112 . V_113 ) )
return - V_29 ;
V_38 -> V_51 [ 14 ] = V_91 ;
V_38 -> V_51 [ 15 ] = ( V_31 V_62 ) V_88 ;
V_38 -> V_42 . V_43 = V_49 |
( V_100 & V_64 ) |
( V_38 -> V_42 . V_43 & ~ V_64 ) ;
V_38 -> V_42 . V_48 = ( V_62 V_31 ) V_85 -> V_76 . V_79 . V_101 ;
V_38 -> V_51 [ 2 ] = V_85 -> V_87 ;
V_38 -> V_51 [ 3 ] = ( V_31 V_62 ) & V_88 -> V_118 ;
V_38 -> V_51 [ 4 ] = ( V_31 V_62 ) & V_88 -> V_112 ;
V_38 -> V_51 [ 5 ] = V_34 -> V_35 . V_109 ;
return 0 ;
}
void F_31 ( struct V_84 * V_85 , T_9 * V_123 ,
struct V_37 * V_38 )
{
int V_124 ;
if ( V_85 -> V_76 . V_79 . V_80 & V_125 )
V_124 = F_29 ( V_85 , V_123 , V_38 ) ;
else
V_124 = F_28 ( V_85 , V_123 , V_38 ) ;
F_32 ( V_124 , V_85 , F_33 ( V_126 ) ) ;
}
