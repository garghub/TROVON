static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_1 V_6 ;
T_2 V_7 ;
V_5 = F_2 ( V_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_8 = ( F_3 ( V_4 ) == 0 ) ;
F_4 ( V_4 ) ;
V_2 -> V_9 = F_5 ( V_4 ) ;
if ( ! V_2 -> V_9 )
F_6 ( L_1 ,
V_10 , F_7 ( & V_4 -> V_11 ) ) ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 ) {
F_9 ( V_4 , & V_2 -> V_9 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
if ( F_11 ( ! V_12 ) )
V_2 -> V_13 = F_12 ( V_4 ) ;
F_13 ( V_4 , V_14 , & V_6 ) ;
if ( V_2 -> V_13 && ( V_6 & V_15 ) ) {
V_6 &= ~ V_15 ;
F_14 ( V_4 , V_14 , V_6 ) ;
}
V_7 = V_4 -> V_16 ;
if ( V_7 ) {
T_1 V_17 ;
T_3 V_18 ;
F_13 ( V_4 , V_7 + V_19 , & V_17 ) ;
F_15 ( V_4 , V_7 + V_20 , & V_18 ) ;
V_2 -> V_21 = V_18 & V_22 ;
V_2 -> V_23 = V_18 & V_24 ;
V_2 -> V_25 = ( ( V_17 & V_26 ) + 1 ) * 16 ;
} else
V_2 -> V_21 = 0xFF ;
#ifdef F_16
if ( ( V_4 -> V_27 >> 8 ) == V_28 )
V_2 -> V_29 = true ;
#endif
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_30 ;
F_10 ( V_4 ) ;
F_18 ( V_2 , V_31 |
V_32 ,
V_2 -> V_33 , 0 , 0 , NULL ) ;
V_2 -> V_34 = false ;
F_19 ( V_2 ) ;
for ( V_30 = V_35 ; V_30 <= V_36 ; V_30 ++ ) {
if ( ! V_2 -> V_37 [ V_30 ] )
continue;
F_20 ( V_4 , V_2 -> V_37 [ V_30 ] ) ;
F_21 ( V_4 , 1 << V_30 ) ;
V_2 -> V_37 [ V_30 ] = NULL ;
}
if ( F_9 ( V_4 , & V_2 -> V_9 ) ) {
F_22 ( L_2 ,
V_10 , F_7 ( & V_4 -> V_11 ) ) ;
if ( ! V_2 -> V_8 )
return;
F_4 ( V_4 ) ;
}
F_14 ( V_4 , V_14 , V_15 ) ;
if ( V_2 -> V_8 )
F_23 ( V_4 ) ;
F_24 ( V_4 ) ;
}
static void F_25 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
if ( F_26 ( & V_2 -> V_39 ) )
F_17 ( V_2 ) ;
F_27 ( V_40 ) ;
}
static int F_28 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
if ( ! F_29 ( V_40 ) )
return - V_41 ;
if ( F_30 ( & V_2 -> V_39 ) == 1 ) {
int V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_27 ( V_40 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_33 )
{
if ( V_33 == V_42 ) {
T_2 V_43 ;
F_32 ( V_2 -> V_4 , V_44 , & V_43 ) ;
if ( V_43 )
return 1 ;
} else if ( V_33 == V_45 ) {
T_2 V_46 ;
T_1 V_17 ;
V_46 = V_2 -> V_4 -> V_47 ;
if ( V_46 ) {
F_13 ( V_2 -> V_4 ,
V_46 + V_48 , & V_17 ) ;
return 1 << ( V_17 & V_49 ) ;
}
} else if ( V_33 == V_50 ) {
T_2 V_46 ;
T_1 V_17 ;
V_46 = V_2 -> V_4 -> V_16 ;
if ( V_46 ) {
F_13 ( V_2 -> V_4 ,
V_46 + V_19 , & V_17 ) ;
return ( V_17 & V_26 ) + 1 ;
}
} else if ( V_33 == V_51 )
if ( F_33 ( V_2 -> V_4 ) )
return 1 ;
return 0 ;
}
static long F_34 ( void * V_38 ,
unsigned int V_6 , unsigned long V_52 )
{
struct V_1 * V_2 = V_38 ;
unsigned long V_53 ;
if ( V_6 == V_54 ) {
struct V_55 V_56 ;
V_53 = F_35 ( struct V_55 , V_57 ) ;
if ( F_36 ( & V_56 , ( void V_58 * ) V_52 , V_53 ) )
return - V_59 ;
if ( V_56 . V_60 < V_53 )
return - V_61 ;
V_56 . V_17 = V_62 ;
if ( V_2 -> V_8 )
V_56 . V_17 |= V_63 ;
V_56 . V_64 = V_65 ;
V_56 . V_57 = V_66 ;
return F_37 ( ( void V_58 * ) V_52 , & V_56 , V_53 ) ;
} else if ( V_6 == V_67 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_68 V_56 ;
V_53 = F_35 ( struct V_68 , V_69 ) ;
if ( F_36 ( & V_56 , ( void V_58 * ) V_52 , V_53 ) )
return - V_59 ;
if ( V_56 . V_60 < V_53 )
return - V_61 ;
switch ( V_56 . V_70 ) {
case V_71 :
V_56 . V_69 = F_38 ( V_56 . V_70 ) ;
V_56 . V_72 = V_4 -> V_73 ;
V_56 . V_17 = V_74 |
V_75 ;
break;
case V_76 ... V_77 :
V_56 . V_69 = F_38 ( V_56 . V_70 ) ;
V_56 . V_72 = F_39 ( V_4 , V_56 . V_70 ) ;
if ( ! V_56 . V_72 ) {
V_56 . V_17 = 0 ;
break;
}
V_56 . V_17 = V_74 |
V_75 ;
if ( F_40 ( V_4 , V_56 . V_70 ) &
V_78 && V_56 . V_72 >= V_79 )
V_56 . V_17 |= V_80 ;
break;
case V_81 :
{
void T_4 * V_82 ;
T_5 V_72 ;
V_56 . V_69 = F_38 ( V_56 . V_70 ) ;
V_56 . V_17 = 0 ;
V_56 . V_72 = F_39 ( V_4 , V_56 . V_70 ) ;
if ( ! V_56 . V_72 )
break;
V_82 = F_41 ( V_4 , & V_72 ) ;
if ( ! V_82 || ! V_72 ) {
V_56 . V_72 = 0 ;
break;
}
F_42 ( V_4 , V_82 ) ;
V_56 . V_17 = V_74 ;
break;
}
case V_83 :
if ( ! V_2 -> V_29 )
return - V_61 ;
V_56 . V_69 = F_38 ( V_56 . V_70 ) ;
V_56 . V_72 = 0xc0000 ;
V_56 . V_17 = V_74 |
V_75 ;
break;
default:
return - V_61 ;
}
return F_37 ( ( void V_58 * ) V_52 , & V_56 , V_53 ) ;
} else if ( V_6 == V_84 ) {
struct V_85 V_56 ;
V_53 = F_35 ( struct V_85 , V_86 ) ;
if ( F_36 ( & V_56 , ( void V_58 * ) V_52 , V_53 ) )
return - V_59 ;
if ( V_56 . V_60 < V_53 || V_56 . V_70 >= V_66 )
return - V_61 ;
switch ( V_56 . V_70 ) {
case V_42 ... V_50 :
break;
case V_51 :
if ( F_33 ( V_2 -> V_4 ) )
break;
default:
return - V_61 ;
}
V_56 . V_17 = V_87 ;
V_56 . V_86 = F_31 ( V_2 , V_56 . V_70 ) ;
if ( V_56 . V_70 == V_42 )
V_56 . V_17 |= ( V_88 |
V_89 ) ;
else
V_56 . V_17 |= V_90 ;
return F_37 ( ( void V_58 * ) V_52 , & V_56 , V_53 ) ;
} else if ( V_6 == V_91 ) {
struct V_92 V_93 ;
T_2 * V_94 = NULL ;
int V_5 = 0 ;
V_53 = F_35 ( struct V_92 , V_86 ) ;
if ( F_36 ( & V_93 , ( void V_58 * ) V_52 , V_53 ) )
return - V_59 ;
if ( V_93 . V_60 < V_53 || V_93 . V_70 >= V_66 ||
V_93 . V_17 & ~ ( V_95 |
V_96 ) )
return - V_61 ;
if ( ! ( V_93 . V_17 & V_31 ) ) {
T_5 V_72 ;
int V_97 = F_31 ( V_2 , V_93 . V_70 ) ;
if ( V_93 . V_17 & V_98 )
V_72 = sizeof( V_99 ) ;
else if ( V_93 . V_17 & V_100 )
V_72 = sizeof( V_101 ) ;
else
return - V_61 ;
if ( V_93 . V_60 - V_53 < V_93 . V_86 * V_72 ||
V_93 . V_102 >= V_97 || V_93 . V_102 + V_93 . V_86 > V_97 )
return - V_61 ;
V_94 = F_43 ( ( void V_58 * ) ( V_52 + V_53 ) ,
V_93 . V_86 * V_72 ) ;
if ( F_44 ( V_94 ) )
return F_45 ( V_94 ) ;
}
F_46 ( & V_2 -> V_103 ) ;
V_5 = F_18 ( V_2 , V_93 . V_17 , V_93 . V_70 ,
V_93 . V_102 , V_93 . V_86 , V_94 ) ;
F_47 ( & V_2 -> V_103 ) ;
F_48 ( V_94 ) ;
return V_5 ;
} else if ( V_6 == V_104 )
return V_2 -> V_8 ?
F_3 ( V_2 -> V_4 ) : - V_61 ;
return - V_105 ;
}
static T_6 F_49 ( void * V_38 , char V_58 * V_106 ,
T_5 V_86 , T_7 * V_107 , bool V_108 )
{
unsigned int V_70 = F_50 ( * V_107 ) ;
struct V_1 * V_2 = V_38 ;
if ( V_70 >= V_65 )
return - V_61 ;
switch ( V_70 ) {
case V_71 :
return F_51 ( V_2 , V_106 , V_86 , V_107 , V_108 ) ;
case V_81 :
if ( V_108 )
return - V_61 ;
return F_52 ( V_2 , V_106 , V_86 , V_107 , false ) ;
case V_76 ... V_77 :
return F_52 ( V_2 , V_106 , V_86 , V_107 , V_108 ) ;
case V_83 :
return F_53 ( V_2 , V_106 , V_86 , V_107 , V_108 ) ;
}
return - V_61 ;
}
static T_6 F_54 ( void * V_38 , char V_58 * V_106 ,
T_5 V_86 , T_7 * V_107 )
{
if ( ! V_86 )
return 0 ;
return F_49 ( V_38 , V_106 , V_86 , V_107 , false ) ;
}
static T_6 F_55 ( void * V_38 , const char V_58 * V_106 ,
T_5 V_86 , T_7 * V_107 )
{
if ( ! V_86 )
return 0 ;
return F_49 ( V_38 , ( char V_58 * ) V_106 , V_86 , V_107 , true ) ;
}
static int F_56 ( void * V_38 , struct V_109 * V_110 )
{
struct V_1 * V_2 = V_38 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_70 ;
T_8 V_111 , V_112 , V_113 , V_114 ;
int V_5 ;
V_70 = V_110 -> V_115 >> ( V_116 - V_117 ) ;
if ( V_110 -> V_118 < V_110 -> V_119 )
return - V_61 ;
if ( ( V_110 -> V_120 & V_121 ) == 0 )
return - V_61 ;
if ( V_70 >= V_81 )
return - V_61 ;
if ( ! ( F_40 ( V_4 , V_70 ) & V_78 ) )
return - V_61 ;
V_111 = F_39 ( V_4 , V_70 ) ;
V_112 = V_110 -> V_118 - V_110 -> V_119 ;
V_113 = V_110 -> V_115 &
( ( 1U << ( V_116 - V_117 ) ) - 1 ) ;
V_114 = V_113 << V_117 ;
if ( V_111 < V_79 || V_114 + V_112 > V_111 )
return - V_61 ;
if ( V_70 == V_2 -> V_21 ) {
if ( ! ( V_114 >= V_2 -> V_23 + V_2 -> V_25 ||
V_114 + V_112 <= V_2 -> V_23 ) )
return - V_61 ;
}
if ( ! V_2 -> V_37 [ V_70 ] ) {
V_5 = F_57 ( V_4 ,
1 << V_70 , L_3 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_37 [ V_70 ] = F_58 ( V_4 , V_70 , 0 ) ;
}
V_110 -> V_122 = V_2 ;
V_110 -> V_120 |= V_123 | V_124 | V_125 ;
V_110 -> V_126 = F_59 ( V_110 -> V_126 ) ;
V_110 -> V_115 = ( F_60 ( V_4 , V_70 ) >> V_117 ) + V_113 ;
return F_61 ( V_110 , V_110 -> V_119 , V_110 -> V_115 ,
V_112 , V_110 -> V_126 ) ;
}
static int F_62 ( struct V_3 * V_4 , const struct V_127 * V_128 )
{
T_2 type ;
struct V_1 * V_2 ;
struct V_129 * V_130 ;
int V_5 ;
F_32 ( V_4 , V_131 , & type ) ;
if ( ( type & V_131 ) != V_132 )
return - V_61 ;
V_130 = F_63 ( & V_4 -> V_11 ) ;
if ( ! V_130 )
return - V_61 ;
V_2 = F_64 ( sizeof( * V_2 ) , V_133 ) ;
if ( ! V_2 ) {
F_65 ( V_130 ) ;
return - V_134 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_33 = V_66 ;
F_66 ( & V_2 -> V_103 ) ;
F_67 ( & V_2 -> V_135 ) ;
F_68 ( & V_2 -> V_39 , 0 ) ;
V_5 = F_69 ( & V_4 -> V_11 , & V_136 , V_2 ) ;
if ( V_5 ) {
F_65 ( V_130 ) ;
F_48 ( V_2 ) ;
}
return V_5 ;
}
static void F_70 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_71 ( & V_4 -> V_11 ) ;
if ( ! V_2 )
return;
F_65 ( V_4 -> V_11 . V_129 ) ;
F_48 ( V_2 ) ;
}
static T_9 F_72 ( struct V_3 * V_4 ,
T_10 V_137 )
{
struct V_1 * V_2 ;
struct V_138 * V_139 ;
V_139 = F_73 ( & V_4 -> V_11 ) ;
if ( V_139 == NULL )
return V_140 ;
V_2 = F_74 ( V_139 ) ;
if ( V_2 == NULL ) {
F_75 ( V_139 ) ;
return V_140 ;
}
if ( V_2 -> V_141 )
F_76 ( V_2 -> V_141 , 1 ) ;
F_75 ( V_139 ) ;
return V_142 ;
}
static void T_11 F_77 ( void )
{
F_78 ( & V_143 ) ;
F_79 () ;
F_80 () ;
}
static int T_12 F_81 ( void )
{
int V_5 ;
V_5 = F_82 () ;
if ( V_5 )
return V_5 ;
V_5 = F_83 () ;
if ( V_5 )
goto V_144;
V_5 = F_84 ( & V_143 ) ;
if ( V_5 )
goto V_145;
return 0 ;
V_145:
F_79 () ;
V_144:
F_80 () ;
return V_5 ;
}
