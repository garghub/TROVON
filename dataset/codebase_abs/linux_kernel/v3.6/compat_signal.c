int F_1 ( T_1 T_2 * V_1 , T_3 * V_2 )
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
case V_13 >> 16 :
V_3 |= F_3 ( V_2 -> V_14 , & V_1 -> V_14 ) ;
case V_15 >> 16 :
V_3 |= F_3 ( V_2 -> V_16 , & V_1 -> V_16 ) ;
V_3 |= F_3 ( V_2 -> V_17 , & V_1 -> V_17 ) ;
break;
case V_18 >> 16 :
V_3 |= F_3 ( V_2 -> V_16 , & V_1 -> V_16 ) ;
V_3 |= F_3 ( V_2 -> V_17 , & V_1 -> V_17 ) ;
V_3 |= F_3 ( V_2 -> V_19 , & V_1 -> V_19 ) ;
V_3 |= F_3 ( V_2 -> V_20 , & V_1 -> V_20 ) ;
V_3 |= F_3 ( V_2 -> V_21 , & V_1 -> V_21 ) ;
break;
case V_22 >> 16 :
V_3 |= F_3 ( ( unsigned long ) V_2 -> V_23 ,
& V_1 -> V_23 ) ;
break;
case V_24 >> 16 :
V_3 |= F_3 ( V_2 -> V_25 , & V_1 -> V_25 ) ;
V_3 |= F_3 ( V_2 -> V_26 , & V_1 -> V_26 ) ;
break;
case V_27 >> 16 :
V_3 |= F_3 ( V_2 -> V_28 , & V_1 -> V_28 ) ;
V_3 |= F_3 ( V_2 -> V_29 , & V_1 -> V_29 ) ;
V_3 |= F_3 ( V_2 -> V_14 , & V_1 -> V_14 ) ;
break;
default:
break;
}
}
return V_3 ;
}
int F_5 ( T_3 * V_1 , T_1 T_2 * V_2 )
{
int V_3 ;
T_4 V_30 ;
if ( ! F_2 ( V_31 , V_2 , sizeof( T_1 ) ) )
return - V_5 ;
V_3 = F_6 ( V_1 -> V_6 , & V_2 -> V_6 ) ;
V_3 |= F_6 ( V_1 -> V_7 , & V_2 -> V_7 ) ;
V_3 |= F_6 ( V_1 -> V_8 , & V_2 -> V_8 ) ;
if ( V_1 -> V_8 < 0 )
V_3 |= F_7 ( & V_1 -> V_9 . V_10 , & V_2 -> V_9 . V_10 , V_11 ) ;
else {
switch ( V_1 -> V_8 >> 16 ) {
case V_12 >> 16 :
case V_13 >> 16 :
V_3 |= F_6 ( V_1 -> V_14 , & V_2 -> V_14 ) ;
case V_15 >> 16 :
V_3 |= F_6 ( V_1 -> V_16 , & V_2 -> V_16 ) ;
V_3 |= F_6 ( V_1 -> V_17 , & V_2 -> V_17 ) ;
break;
case V_18 >> 16 :
V_3 |= F_6 ( V_1 -> V_16 , & V_2 -> V_16 ) ;
V_3 |= F_6 ( V_1 -> V_17 , & V_2 -> V_17 ) ;
V_3 |= F_6 ( V_1 -> V_19 , & V_2 -> V_19 ) ;
V_3 |= F_6 ( V_1 -> V_20 , & V_2 -> V_20 ) ;
V_3 |= F_6 ( V_1 -> V_21 , & V_2 -> V_21 ) ;
break;
case V_22 >> 16 :
V_3 |= F_6 ( V_30 , & V_2 -> V_23 ) ;
V_1 -> V_23 = ( void V_32 T_2 * )
( V_33 ) ( V_30 & V_34 ) ;
break;
case V_24 >> 16 :
V_3 |= F_6 ( V_1 -> V_25 , & V_2 -> V_25 ) ;
V_3 |= F_6 ( V_1 -> V_26 , & V_2 -> V_26 ) ;
break;
case V_27 >> 16 :
V_3 |= F_6 ( V_1 -> V_28 , & V_2 -> V_28 ) ;
V_3 |= F_6 ( V_1 -> V_29 , & V_2 -> V_29 ) ;
V_3 |= F_6 ( V_1 -> V_14 , & V_2 -> V_14 ) ;
break;
default:
break;
}
}
return V_3 ;
}
T_5 long
F_8 ( int V_35 , const struct V_36 T_2 * V_37 ,
struct V_36 T_2 * V_38 )
{
struct V_39 V_40 , V_41 ;
unsigned long V_42 , V_43 ;
int V_44 ;
if ( V_37 ) {
T_6 V_45 ;
if ( ! F_2 ( V_31 , V_37 , sizeof( * V_37 ) ) ||
F_6 ( V_42 , & V_37 -> V_42 ) ||
F_6 ( V_43 , & V_37 -> V_43 ) ||
F_6 ( V_40 . V_46 . V_47 , & V_37 -> V_47 ) ||
F_6 ( V_45 , & V_37 -> V_48 ) )
return - V_5 ;
V_40 . V_46 . V_42 = ( V_49 ) V_42 ;
V_40 . V_46 . V_43 = ( void ( * ) ( void ) ) V_43 ;
F_9 ( & V_40 . V_46 . V_48 , V_45 ) ;
}
V_44 = F_10 ( V_35 , V_37 ? & V_40 : NULL , V_38 ? & V_41 : NULL ) ;
if ( ! V_44 && V_38 ) {
V_42 = ( unsigned long ) V_41 . V_46 . V_42 ;
V_43 = ( unsigned long ) V_41 . V_46 . V_43 ;
if ( ! F_2 ( V_4 , V_38 , sizeof( * V_38 ) ) ||
F_3 ( V_42 , & V_38 -> V_42 ) ||
F_3 ( V_43 , & V_38 -> V_43 ) ||
F_3 ( V_41 . V_46 . V_47 , & V_38 -> V_47 ) ||
F_3 ( V_41 . V_46 . V_48 . V_35 [ 0 ] , & V_38 -> V_48 ) )
return - V_5 ;
}
return V_44 ;
}
T_5 long
F_11 ( int V_35 , const struct V_50 T_2 * V_37 ,
struct V_50 T_2 * V_38 , T_7 V_51 )
{
struct V_39 V_40 , V_41 ;
unsigned long V_42 ;
int V_44 ;
T_8 V_52 ;
if ( V_51 != sizeof( T_8 ) )
return - V_53 ;
if ( V_37 ) {
V_44 = F_12 ( V_42 , & V_37 -> V_42 ) ;
V_44 |= F_7 ( & V_52 , & V_37 -> V_48 ,
sizeof( T_8 ) ) ;
V_40 . V_46 . V_48 . V_35 [ 0 ] =
V_52 . V_35 [ 0 ] | ( ( ( long ) V_52 . V_35 [ 1 ] ) << 32 ) ;
V_44 |= F_6 ( V_40 . V_46 . V_47 , & V_37 -> V_47 ) ;
if ( V_44 )
return - V_5 ;
V_40 . V_46 . V_42 = ( V_49 ) V_42 ;
}
V_44 = F_10 ( V_35 , V_37 ? & V_40 : NULL , V_38 ? & V_41 : NULL ) ;
if ( ! V_44 && V_38 ) {
V_52 . V_35 [ 1 ] = ( V_41 . V_46 . V_48 . V_35 [ 0 ] >> 32 ) ;
V_52 . V_35 [ 0 ] = V_41 . V_46 . V_48 . V_35 [ 0 ] ;
V_44 = F_13 ( ( unsigned long ) V_41 . V_46 . V_42 , & V_38 -> V_42 ) ;
V_44 |= F_4 ( & V_38 -> V_48 , & V_52 ,
sizeof( T_8 ) ) ;
V_44 |= F_3 ( V_41 . V_46 . V_47 , & V_38 -> V_47 ) ;
}
return V_44 ;
}
T_5 long
F_14 ( const T_9 T_2 * V_54 , T_9 T_2 * V_55 )
{
struct V_56 * V_57 = F_15 ( V_58 ) ;
T_10 V_59 , V_60 ;
unsigned long V_61 ;
int V_44 , V_3 = 0 ;
T_11 V_62 = F_16 () ;
if ( V_54 ) {
if ( ! F_2 ( V_31 , V_54 , sizeof( * V_54 ) ) )
return - V_5 ;
V_3 |= F_6 ( V_61 , & V_54 -> V_61 ) ;
V_3 |= F_6 ( V_59 . V_63 , & V_54 -> V_63 ) ;
V_3 |= F_6 ( V_59 . V_64 , & V_54 -> V_64 ) ;
if ( V_3 )
return - V_5 ;
V_59 . V_61 = ( void T_2 * ) V_61 ;
}
F_17 ( V_65 ) ;
V_44 = F_18 ( ( T_10 V_32 T_2 * ) ( V_54 ? & V_59 : NULL ) ,
( T_10 V_32 T_2 * ) ( V_55 ? & V_60 : NULL ) ,
V_57 -> V_66 [ 15 ] ) ;
F_17 ( V_62 ) ;
if ( ! V_44 && V_55 ) {
if ( ! F_2 ( V_4 , V_55 , sizeof( * V_55 ) ) )
return - V_5 ;
V_61 = ( unsigned long ) V_60 . V_61 ;
V_3 |= F_3 ( V_61 , & V_55 -> V_61 ) ;
V_3 |= F_3 ( V_60 . V_63 , & V_55 -> V_63 ) ;
V_3 |= F_3 ( V_60 . V_64 , & V_55 -> V_64 ) ;
if ( V_3 )
return - V_5 ;
}
return V_44 ;
}
static int F_19 ( struct V_56 * V_57 , T_12 T_2 * V_67 )
{
T_13 V_68 ;
int V_3 , V_69 ;
V_68 . V_70 . V_45 = V_71 |
( ( V_72 ) ( V_57 -> V_70 . V_45 >> 32 ) & V_73 ) ;
V_68 . V_70 . V_74 = ( V_72 ) V_57 -> V_70 . V_74 |
( V_72 ) ( V_57 -> V_70 . V_45 & V_75 ) ;
for ( V_69 = 0 ; V_69 < V_76 ; V_69 ++ )
V_68 . V_66 [ V_69 ] = ( V_72 ) V_57 -> V_66 [ V_69 ] ;
F_20 ( V_58 -> V_77 . V_78 ) ;
memcpy ( V_68 . V_78 , V_58 -> V_77 . V_78 , sizeof( V_68 . V_78 ) ) ;
V_3 = F_4 ( & V_67 -> V_57 , & V_68 , sizeof( V_68 ) ) ;
if ( V_3 )
return V_3 ;
F_21 ( & V_58 -> V_77 . V_79 ) ;
return F_4 ( & V_67 -> V_80 , & V_58 -> V_77 . V_79 ,
sizeof( V_81 ) ) ;
}
static int F_22 ( struct V_56 * V_57 , T_12 T_2 * V_67 )
{
T_13 V_68 ;
int V_3 , V_69 ;
F_23 () -> V_82 . V_83 = V_84 ;
V_3 = F_7 ( & V_68 , & V_67 -> V_57 , sizeof( V_68 ) ) ;
if ( V_3 )
return V_3 ;
V_57 -> V_70 . V_45 = ( V_57 -> V_70 . V_45 & ~ V_85 ) |
( V_86 ) ( V_68 . V_70 . V_45 & V_73 ) << 32 |
( V_86 ) ( V_68 . V_70 . V_74 & V_87 ) ;
V_57 -> V_70 . V_74 = ( V_86 ) ( V_68 . V_70 . V_74 & V_34 ) ;
for ( V_69 = 0 ; V_69 < V_76 ; V_69 ++ )
V_57 -> V_66 [ V_69 ] = ( V_86 ) V_68 . V_66 [ V_69 ] ;
memcpy ( V_58 -> V_77 . V_78 , V_68 . V_78 , sizeof( V_58 -> V_77 . V_78 ) ) ;
F_24 ( V_58 -> V_77 . V_78 ) ;
V_3 = F_7 ( & V_58 -> V_77 . V_79 , & V_67 -> V_80 ,
sizeof( V_81 ) ) ;
V_58 -> V_77 . V_79 . V_88 &= V_89 ;
if ( V_3 )
return V_3 ;
F_25 ( & V_58 -> V_77 . V_79 ) ;
F_26 ( V_90 ) ;
return 0 ;
}
static int F_27 ( struct V_56 * V_57 , V_72 T_2 * V_91 )
{
V_72 V_92 [ V_76 ] ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_76 ; V_69 ++ )
V_92 [ V_69 ] = V_57 -> V_66 [ V_69 ] >> 32 ;
return F_4 ( V_91 , & V_92 , sizeof( V_92 ) ) ;
}
static int F_28 ( struct V_56 * V_57 , V_72 T_2 * V_91 )
{
V_72 V_92 [ V_76 ] ;
int V_3 , V_69 ;
V_3 = F_7 ( & V_92 , V_91 , sizeof( V_92 ) ) ;
if ( V_3 )
return V_3 ;
for ( V_69 = 0 ; V_69 < V_76 ; V_69 ++ )
* ( V_72 * ) & V_57 -> V_66 [ V_69 ] = V_92 [ V_69 ] ;
return 0 ;
}
T_5 long F_29 ( void )
{
struct V_56 * V_57 = F_15 ( V_58 ) ;
T_14 T_2 * V_93 = ( T_14 T_2 * ) V_57 -> V_66 [ 15 ] ;
T_15 V_94 ;
if ( ! F_2 ( V_31 , V_93 , sizeof( * V_93 ) ) )
goto V_95;
if ( F_7 ( & V_94 . V_35 , & V_93 -> V_96 . V_97 , V_98 ) )
goto V_95;
F_30 ( & V_94 ) ;
if ( F_22 ( V_57 , & V_93 -> V_67 ) )
goto V_95;
if ( F_28 ( V_57 , V_93 -> V_92 ) )
goto V_95;
return V_57 -> V_66 [ 2 ] ;
V_95:
F_31 ( V_99 , V_58 ) ;
return 0 ;
}
T_5 long F_32 ( void )
{
struct V_56 * V_57 = F_15 ( V_58 ) ;
T_16 T_2 * V_93 = ( T_16 T_2 * ) V_57 -> V_66 [ 15 ] ;
T_15 V_94 ;
T_10 V_100 ;
V_72 V_61 ;
int V_3 ;
T_11 V_62 = F_16 () ;
if ( ! F_2 ( V_31 , V_93 , sizeof( * V_93 ) ) )
goto V_95;
if ( F_7 ( & V_94 , & V_93 -> V_101 . V_102 , sizeof( V_94 ) ) )
goto V_95;
F_30 ( & V_94 ) ;
if ( F_22 ( V_57 , & V_93 -> V_101 . V_103 ) )
goto V_95;
if ( F_28 ( V_57 , V_93 -> V_92 ) )
goto V_95;
V_3 = F_6 ( V_61 , & V_93 -> V_101 . V_104 . V_61 ) ;
V_100 . V_61 = F_33 ( V_61 ) ;
V_3 |= F_6 ( V_100 . V_63 , & V_93 -> V_101 . V_104 . V_63 ) ;
V_3 |= F_6 ( V_100 . V_64 , & V_93 -> V_101 . V_104 . V_64 ) ;
if ( V_3 )
goto V_95;
F_17 ( V_65 ) ;
F_18 ( ( T_10 V_32 T_2 * ) & V_100 , NULL , V_57 -> V_66 [ 15 ] ) ;
F_17 ( V_62 ) ;
return V_57 -> V_66 [ 2 ] ;
V_95:
F_31 ( V_99 , V_58 ) ;
return 0 ;
}
static inline void T_2 *
F_34 ( struct V_39 * V_105 , struct V_56 * V_57 , T_7 V_106 )
{
unsigned long V_107 ;
V_107 = ( unsigned long ) F_35 ( V_57 -> V_66 [ 15 ] ) ;
if ( F_36 ( V_107 ) && ! F_36 ( ( V_107 - V_106 ) & - 8UL ) )
return ( void T_2 * ) - 1UL ;
if ( V_105 -> V_46 . V_47 & V_108 ) {
if ( ! F_37 ( V_107 ) )
V_107 = V_58 -> V_109 + V_58 -> V_110 ;
}
return ( void T_2 * ) ( ( V_107 - V_106 ) & - 8ul ) ;
}
static inline int F_38 ( int V_35 )
{
if ( F_23 () -> V_111
&& F_23 () -> V_111 -> V_112
&& V_35 < 32 )
return F_23 () -> V_111 -> V_112 [ V_35 ] ;
else
return V_35 ;
}
static int F_39 ( int V_35 , struct V_39 * V_105 ,
T_15 * V_94 , struct V_56 * V_57 )
{
T_14 T_2 * V_93 = F_34 ( V_105 , V_57 , sizeof( T_14 ) ) ;
if ( ! F_2 ( V_4 , V_93 , sizeof( T_14 ) ) )
goto V_113;
if ( V_93 == ( void T_2 * ) - 1UL )
goto V_113;
if ( F_4 ( & V_93 -> V_96 . V_97 , & V_94 -> V_35 , V_98 ) )
goto V_113;
if ( F_19 ( V_57 , & V_93 -> V_67 ) )
goto V_113;
if ( F_27 ( V_57 , V_93 -> V_92 ) )
goto V_113;
if ( F_3 ( ( unsigned long ) & V_93 -> V_67 , & V_93 -> V_96 . V_67 ) )
goto V_113;
if ( V_105 -> V_46 . V_47 & V_114 ) {
V_57 -> V_66 [ 14 ] = ( V_86 ) V_105 -> V_46 . V_43 | V_87 ;
} else {
V_57 -> V_66 [ 14 ] = ( V_86 ) V_93 -> V_115 | V_87 ;
if ( F_3 ( V_116 | V_117 ,
( V_118 V_32 T_2 * ) ( V_93 -> V_115 ) ) )
goto V_113;
}
if ( F_3 ( V_57 -> V_66 [ 15 ] , ( unsigned int T_2 * ) V_93 ) )
goto V_113;
V_57 -> V_66 [ 15 ] = ( V_32 V_86 ) V_93 ;
V_57 -> V_70 . V_45 |= V_75 ;
V_57 -> V_70 . V_74 = ( V_32 V_86 ) V_105 -> V_46 . V_42 ;
V_57 -> V_66 [ 2 ] = F_38 ( V_35 ) ;
V_57 -> V_66 [ 3 ] = ( V_32 V_86 ) & V_93 -> V_96 ;
if ( V_35 == V_99 || V_35 == V_119 || V_35 == V_120 ||
V_35 == V_121 || V_35 == V_122 ) {
V_57 -> V_66 [ 4 ] = V_57 -> V_123 & 127 ;
V_57 -> V_66 [ 5 ] = V_57 -> V_124 ;
}
if ( F_3 ( V_57 -> V_66 [ 2 ] , ( int V_32 T_2 * ) & V_93 -> V_125 ) )
goto V_113;
return 0 ;
V_113:
F_40 ( V_35 , V_58 ) ;
return - V_5 ;
}
static int F_41 ( int V_35 , struct V_39 * V_105 , T_3 * V_126 ,
T_15 * V_94 , struct V_56 * V_57 )
{
int V_3 = 0 ;
T_16 T_2 * V_93 = F_34 ( V_105 , V_57 , sizeof( T_16 ) ) ;
if ( ! F_2 ( V_4 , V_93 , sizeof( T_16 ) ) )
goto V_113;
if ( V_93 == ( void T_2 * ) - 1UL )
goto V_113;
if ( F_1 ( & V_93 -> V_126 , V_126 ) )
goto V_113;
V_3 |= F_3 ( V_127 , & V_93 -> V_101 . V_128 ) ;
V_3 |= F_3 ( 0 , & V_93 -> V_101 . V_129 ) ;
V_3 |= F_3 ( V_58 -> V_109 , & V_93 -> V_101 . V_104 . V_61 ) ;
V_3 |= F_3 ( F_37 ( V_57 -> V_66 [ 15 ] ) ,
& V_93 -> V_101 . V_104 . V_64 ) ;
V_3 |= F_3 ( V_58 -> V_110 , & V_93 -> V_101 . V_104 . V_63 ) ;
V_3 |= F_19 ( V_57 , & V_93 -> V_101 . V_103 ) ;
V_3 |= F_27 ( V_57 , V_93 -> V_92 ) ;
V_3 |= F_4 ( & V_93 -> V_101 . V_102 , V_94 , sizeof( * V_94 ) ) ;
if ( V_3 )
goto V_113;
if ( V_105 -> V_46 . V_47 & V_114 ) {
V_57 -> V_66 [ 14 ] = ( V_86 ) V_105 -> V_46 . V_43 | V_87 ;
} else {
V_57 -> V_66 [ 14 ] = ( V_86 ) V_93 -> V_115 | V_87 ;
V_3 |= F_3 ( V_116 | V_130 ,
( V_118 V_32 T_2 * ) ( V_93 -> V_115 ) ) ;
}
if ( F_3 ( V_57 -> V_66 [ 15 ] , ( unsigned int V_32 T_2 * ) V_93 ) )
goto V_113;
V_57 -> V_66 [ 15 ] = ( V_32 V_86 ) V_93 ;
V_57 -> V_70 . V_45 |= V_75 ;
V_57 -> V_70 . V_74 = ( V_86 ) V_105 -> V_46 . V_42 ;
V_57 -> V_66 [ 2 ] = F_38 ( V_35 ) ;
V_57 -> V_66 [ 3 ] = ( V_32 V_86 ) & V_93 -> V_126 ;
V_57 -> V_66 [ 4 ] = ( V_32 V_86 ) & V_93 -> V_101 ;
return 0 ;
V_113:
F_40 ( V_35 , V_58 ) ;
return - V_5 ;
}
void F_42 ( unsigned long V_35 , struct V_39 * V_105 ,
T_3 * V_126 , T_15 * V_131 , struct V_56 * V_57 )
{
int V_44 ;
if ( V_105 -> V_46 . V_47 & V_132 )
V_44 = F_41 ( V_35 , V_105 , V_126 , V_131 , V_57 ) ;
else
V_44 = F_39 ( V_35 , V_105 , V_131 , V_57 ) ;
if ( V_44 )
return;
F_43 ( V_35 , V_126 , V_105 , V_57 ,
F_44 ( V_133 ) ) ;
}
