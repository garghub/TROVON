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
V_5 |= F_4 ( ( short ) V_4 -> V_8 , & V_3 -> V_8 ) ;
if ( V_4 -> V_8 < 0 )
V_5 |= F_5 ( & V_3 -> V_9 . V_10 , & V_4 -> V_9 . V_10 , V_11 ) ;
else {
switch ( V_4 -> V_8 >> 16 ) {
case V_12 >> 16 :
case V_13 >> 16 :
V_5 |= F_4 ( V_4 -> V_14 , & V_3 -> V_14 ) ;
case V_15 >> 16 :
V_5 |= F_4 ( V_4 -> V_16 , & V_3 -> V_16 ) ;
V_5 |= F_4 ( V_4 -> V_17 , & V_3 -> V_17 ) ;
break;
case V_18 >> 16 :
V_5 |= F_4 ( V_4 -> V_16 , & V_3 -> V_16 ) ;
V_5 |= F_4 ( V_4 -> V_17 , & V_3 -> V_17 ) ;
V_5 |= F_4 ( V_4 -> V_19 , & V_3 -> V_19 ) ;
V_5 |= F_4 ( V_4 -> V_20 , & V_3 -> V_20 ) ;
V_5 |= F_4 ( V_4 -> V_21 , & V_3 -> V_21 ) ;
break;
case V_22 >> 16 :
V_5 |= F_4 ( ( unsigned long ) V_4 -> V_23 ,
& V_3 -> V_23 ) ;
break;
case V_24 >> 16 :
V_5 |= F_4 ( V_4 -> V_25 , & V_3 -> V_25 ) ;
V_5 |= F_4 ( V_4 -> V_26 , & V_3 -> V_26 ) ;
break;
case V_27 >> 16 :
V_5 |= F_4 ( V_4 -> V_28 , & V_3 -> V_28 ) ;
V_5 |= F_4 ( V_4 -> V_29 , & V_3 -> V_29 ) ;
V_5 |= F_4 ( V_4 -> V_14 , & V_3 -> V_14 ) ;
break;
default:
break;
}
}
return V_5 ? - V_30 : 0 ;
}
int F_6 ( T_4 * V_3 , T_2 T_3 * V_4 )
{
int V_5 ;
T_5 V_31 ;
V_5 = F_7 ( V_3 -> V_6 , & V_4 -> V_6 ) ;
V_5 |= F_7 ( V_3 -> V_7 , & V_4 -> V_7 ) ;
V_5 |= F_7 ( V_3 -> V_8 , & V_4 -> V_8 ) ;
if ( V_3 -> V_8 < 0 )
V_5 |= F_8 ( & V_3 -> V_9 . V_10 , & V_4 -> V_9 . V_10 , V_11 ) ;
else {
switch ( V_3 -> V_8 >> 16 ) {
case V_12 >> 16 :
case V_13 >> 16 :
V_5 |= F_7 ( V_3 -> V_14 , & V_4 -> V_14 ) ;
case V_15 >> 16 :
V_5 |= F_7 ( V_3 -> V_16 , & V_4 -> V_16 ) ;
V_5 |= F_7 ( V_3 -> V_17 , & V_4 -> V_17 ) ;
break;
case V_18 >> 16 :
V_5 |= F_7 ( V_3 -> V_16 , & V_4 -> V_16 ) ;
V_5 |= F_7 ( V_3 -> V_17 , & V_4 -> V_17 ) ;
V_5 |= F_7 ( V_3 -> V_19 , & V_4 -> V_19 ) ;
V_5 |= F_7 ( V_3 -> V_20 , & V_4 -> V_20 ) ;
V_5 |= F_7 ( V_3 -> V_21 , & V_4 -> V_21 ) ;
break;
case V_22 >> 16 :
V_5 |= F_7 ( V_31 , & V_4 -> V_23 ) ;
V_3 -> V_23 = ( void V_32 T_3 * )
( V_33 ) ( V_31 & V_34 ) ;
break;
case V_24 >> 16 :
V_5 |= F_7 ( V_3 -> V_25 , & V_4 -> V_25 ) ;
V_5 |= F_7 ( V_3 -> V_26 , & V_4 -> V_26 ) ;
break;
case V_27 >> 16 :
V_5 |= F_7 ( V_3 -> V_28 , & V_4 -> V_28 ) ;
V_5 |= F_7 ( V_3 -> V_29 , & V_4 -> V_29 ) ;
V_5 |= F_7 ( V_3 -> V_14 , & V_4 -> V_14 ) ;
break;
default:
break;
}
}
return V_5 ? - V_30 : 0 ;
}
static void F_9 ( void )
{
F_10 ( V_35 -> V_36 . V_37 ) ;
F_11 () ;
}
static void F_12 ( void )
{
F_13 ( V_35 -> V_36 . V_37 ) ;
}
static int F_14 ( struct V_38 * V_39 , T_6 T_3 * V_40 )
{
T_6 V_41 ;
int V_42 ;
V_41 . V_39 . V_43 . V_44 = ( V_45 ) ( V_39 -> V_43 . V_44 >> 32 ) ;
V_41 . V_39 . V_43 . V_44 &= V_46 | V_47 ;
V_41 . V_39 . V_43 . V_44 |= V_48 ;
V_41 . V_39 . V_43 . V_49 = ( V_45 ) V_39 -> V_43 . V_49 |
( V_45 ) ( V_39 -> V_43 . V_44 & V_50 ) ;
for ( V_42 = 0 ; V_42 < V_51 ; V_42 ++ )
V_41 . V_39 . V_52 [ V_42 ] = ( V_45 ) V_39 -> V_52 [ V_42 ] ;
memcpy ( & V_41 . V_39 . V_37 , V_35 -> V_36 . V_37 ,
sizeof( V_41 . V_39 . V_37 ) ) ;
F_15 ( ( V_53 * ) & V_41 . V_54 , & V_35 -> V_36 . V_55 ) ;
if ( F_5 ( V_40 , & V_41 , sizeof( T_6 ) ) )
return - V_30 ;
return 0 ;
}
static int F_16 ( struct V_38 * V_39 , T_6 T_3 * V_40 )
{
T_6 V_41 ;
int V_42 ;
V_35 -> V_56 . V_57 = V_58 ;
if ( F_8 ( & V_41 , & V_40 -> V_39 , sizeof( V_41 ) ) )
return - V_30 ;
if ( ! F_17 ( V_35 ) && ( V_41 . V_39 . V_43 . V_44 & V_47 ) )
return - V_59 ;
if ( F_18 ( V_41 . V_54 . V_60 ) )
return - V_59 ;
V_39 -> V_43 . V_44 = ( V_39 -> V_43 . V_44 & ~ ( V_61 | V_62 ) ) |
( V_63 ) ( V_41 . V_39 . V_43 . V_44 & V_46 ) << 32 |
( V_63 ) ( V_41 . V_39 . V_43 . V_44 & V_47 ) << 32 |
( V_63 ) ( V_41 . V_39 . V_43 . V_49 & V_64 ) ;
if ( ( V_39 -> V_43 . V_44 & V_65 ) == V_66 )
V_39 -> V_43 . V_44 = V_67 |
( V_39 -> V_43 . V_44 & ~ V_65 ) ;
V_39 -> V_43 . V_49 = ( V_63 ) ( V_41 . V_39 . V_43 . V_49 & V_34 ) ;
for ( V_42 = 0 ; V_42 < V_51 ; V_42 ++ )
V_39 -> V_52 [ V_42 ] = ( V_63 ) V_41 . V_39 . V_52 [ V_42 ] ;
memcpy ( & V_35 -> V_36 . V_37 , & V_41 . V_39 . V_37 ,
sizeof( V_35 -> V_36 . V_37 ) ) ;
F_19 ( ( V_53 * ) & V_41 . V_54 , & V_35 -> V_36 . V_55 ) ;
F_20 ( V_39 , V_68 ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_39 ,
T_7 T_3 * V_69 )
{
V_45 V_70 [ V_51 ] ;
V_63 V_71 [ V_72 ] ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_51 ; V_42 ++ )
V_70 [ V_42 ] = V_39 -> V_52 [ V_42 ] >> 32 ;
if ( F_5 ( & V_69 -> V_70 , & V_70 ,
sizeof( V_69 -> V_70 ) ) )
return - V_30 ;
if ( V_73 ) {
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ )
V_71 [ V_42 ] = * ( ( V_63 * ) ( V_35 -> V_36 . V_55 . V_71 + V_42 ) + 1 ) ;
if ( F_5 ( & V_69 -> V_74 , V_71 ,
sizeof( V_69 -> V_74 ) ) ||
F_5 ( & V_69 -> V_75 ,
V_35 -> V_36 . V_55 . V_71 + V_72 ,
sizeof( V_69 -> V_75 ) ) )
return - V_30 ;
}
return 0 ;
}
static int F_22 ( struct V_38 * V_39 ,
T_7 T_3 * V_69 )
{
V_45 V_70 [ V_51 ] ;
V_63 V_71 [ V_72 ] ;
int V_42 ;
if ( F_8 ( & V_70 , & V_69 -> V_70 ,
sizeof( V_69 -> V_70 ) ) )
return - V_30 ;
for ( V_42 = 0 ; V_42 < V_51 ; V_42 ++ )
* ( V_45 * ) & V_39 -> V_52 [ V_42 ] = V_70 [ V_42 ] ;
if ( V_73 ) {
if ( F_8 ( V_71 , & V_69 -> V_74 ,
sizeof( V_69 -> V_74 ) ) ||
F_8 ( V_35 -> V_36 . V_55 . V_71 + V_72 ,
& V_69 -> V_75 ,
sizeof( V_69 -> V_75 ) ) )
return - V_30 ;
for ( V_42 = 0 ; V_42 < V_72 ; V_42 ++ )
* ( ( V_63 * ) ( V_35 -> V_36 . V_55 . V_71 + V_42 ) + 1 ) = V_71 [ V_42 ] ;
}
return 0 ;
}
static inline void T_3 *
F_23 ( struct V_76 * V_77 , struct V_38 * V_39 , T_8 V_78 )
{
unsigned long V_79 ;
V_79 = ( unsigned long ) F_24 ( V_39 -> V_52 [ 15 ] ) ;
if ( F_25 ( V_79 ) && ! F_25 ( ( V_79 - V_78 ) & - 8UL ) )
return ( void T_3 * ) - 1UL ;
if ( V_77 -> V_80 . V_81 & V_82 ) {
if ( ! F_26 ( V_79 ) )
V_79 = V_35 -> V_83 + V_35 -> V_84 ;
}
return ( void T_3 * ) ( ( V_79 - V_78 ) & - 8ul ) ;
}
static int F_27 ( struct V_85 * V_86 , T_9 * V_87 ,
struct V_38 * V_39 )
{
int V_88 = V_86 -> V_88 ;
T_10 T_3 * V_89 ;
struct V_90 V_91 ;
unsigned long V_92 ;
T_8 V_78 ;
V_78 = sizeof( * V_89 ) - sizeof( V_89 -> V_69 . V_93 ) ;
if ( ! V_73 )
V_78 -= sizeof( V_89 -> V_69 . V_74 ) +
sizeof( V_89 -> V_69 . V_75 ) ;
V_89 = F_23 ( & V_86 -> V_77 , V_39 , V_78 ) ;
if ( V_89 == ( void T_3 * ) - 1UL )
return - V_30 ;
if ( F_4 ( V_39 -> V_52 [ 15 ] , ( unsigned int T_3 * ) V_89 ) )
return - V_30 ;
F_1 ( V_87 -> V_88 , V_91 . V_94 ) ;
V_91 . V_40 = ( V_45 ) ( unsigned long V_32 ) & V_89 -> V_40 ;
if ( F_5 ( & V_89 -> V_91 , & V_91 , sizeof( V_89 -> V_91 ) ) )
return - V_30 ;
F_9 () ;
if ( F_14 ( V_39 , & V_89 -> V_40 ) )
return - V_30 ;
if ( F_4 ( V_39 -> V_52 [ 2 ] , ( int V_32 T_3 * ) & V_89 -> V_95 ) )
return - V_30 ;
if ( F_21 ( V_39 , & V_89 -> V_69 ) )
return - V_30 ;
if ( V_86 -> V_77 . V_80 . V_81 & V_96 ) {
V_92 = ( unsigned long V_32 )
V_86 -> V_77 . V_80 . V_97 | V_64 ;
} else {
T_11 T_3 * V_98 = ( void T_3 * ) V_89 + V_78 - 2 ;
if ( F_4 ( V_99 | V_100 , V_98 ) )
return - V_30 ;
V_92 = ( unsigned long V_32 ) V_98 | V_64 ;
}
V_39 -> V_52 [ 14 ] = V_92 ;
V_39 -> V_52 [ 15 ] = ( V_32 V_63 ) V_89 ;
V_39 -> V_43 . V_44 = V_50 |
( V_101 & V_65 ) |
( V_39 -> V_43 . V_44 & ~ V_65 ) ;
V_39 -> V_43 . V_49 = ( V_32 V_63 ) V_86 -> V_77 . V_80 . V_102 ;
V_39 -> V_52 [ 2 ] = V_88 ;
V_39 -> V_52 [ 3 ] = ( V_32 V_63 ) & V_89 -> V_91 ;
if ( V_88 == V_103 || V_88 == V_104 || V_88 == V_105 ||
V_88 == V_106 || V_88 == V_107 ) {
V_39 -> V_52 [ 4 ] = V_39 -> V_108 & 127 ;
V_39 -> V_52 [ 5 ] = V_39 -> V_109 ;
V_39 -> V_52 [ 6 ] = F_28 ( V_35 ) -> V_110 ;
}
return 0 ;
}
static int F_29 ( struct V_85 * V_86 , T_9 * V_87 ,
struct V_38 * V_39 )
{
T_12 V_111 ;
T_13 T_3 * V_89 ;
unsigned long V_92 ;
T_8 V_78 ;
T_5 V_112 ;
V_78 = sizeof( * V_89 ) -
sizeof( V_89 -> V_113 . V_114 . V_93 ) ;
V_112 = V_115 ;
if ( V_73 ) {
V_112 |= V_116 ;
} else
V_78 -= sizeof( V_89 -> V_113 . V_114 . V_74 ) +
sizeof( V_89 -> V_113 . V_114 . V_75 ) ;
V_89 = F_23 ( & V_86 -> V_77 , V_39 , V_78 ) ;
if ( V_89 == ( void T_3 * ) - 1UL )
return - V_30 ;
if ( F_4 ( V_39 -> V_52 [ 15 ] , ( unsigned int V_32 T_3 * ) V_89 ) )
return - V_30 ;
if ( V_86 -> V_77 . V_80 . V_81 & V_96 ) {
V_92 = ( unsigned long V_32 )
V_86 -> V_77 . V_80 . V_97 | V_64 ;
} else {
T_11 T_3 * V_98 = & V_89 -> V_117 ;
if ( F_4 ( V_99 | V_118 , V_98 ) )
return - V_30 ;
V_92 = ( unsigned long V_32 ) V_98 | V_64 ;
}
if ( F_3 ( & V_89 -> V_119 , & V_86 -> V_119 ) )
return - V_30 ;
F_9 () ;
F_1 ( V_87 -> V_88 , V_111 . V_88 ) ;
if ( F_4 ( V_112 , & V_89 -> V_113 . V_112 ) ||
F_4 ( 0 , & V_89 -> V_113 . V_120 ) ||
F_30 ( & V_89 -> V_113 . V_121 , V_39 -> V_52 [ 15 ] ) ||
F_14 ( V_39 , & V_89 -> V_113 . V_122 ) ||
F_5 ( & V_89 -> V_113 . V_123 , & V_111 , sizeof( V_111 ) ) ||
F_21 ( V_39 , & V_89 -> V_113 . V_114 ) )
return - V_30 ;
V_39 -> V_52 [ 14 ] = V_92 ;
V_39 -> V_52 [ 15 ] = ( V_32 V_63 ) V_89 ;
V_39 -> V_43 . V_44 = V_50 |
( V_101 & V_65 ) |
( V_39 -> V_43 . V_44 & ~ V_65 ) ;
V_39 -> V_43 . V_49 = ( V_63 V_32 ) V_86 -> V_77 . V_80 . V_102 ;
V_39 -> V_52 [ 2 ] = V_86 -> V_88 ;
V_39 -> V_52 [ 3 ] = ( V_32 V_63 ) & V_89 -> V_119 ;
V_39 -> V_52 [ 4 ] = ( V_32 V_63 ) & V_89 -> V_113 ;
V_39 -> V_52 [ 5 ] = F_28 ( V_35 ) -> V_110 ;
return 0 ;
}
void F_31 ( struct V_85 * V_86 , T_9 * V_124 ,
struct V_38 * V_39 )
{
int V_125 ;
if ( V_86 -> V_77 . V_80 . V_81 & V_126 )
V_125 = F_29 ( V_86 , V_124 , V_39 ) ;
else
V_125 = F_27 ( V_86 , V_124 , V_39 ) ;
F_32 ( V_125 , V_86 , F_33 ( V_127 ) ) ;
}
