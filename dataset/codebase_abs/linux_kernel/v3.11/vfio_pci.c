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
if ( V_2 -> V_8 ) {
bool V_38 = false ;
if ( F_23 ( V_4 ) ) {
if ( F_24 ( & V_4 -> V_11 ) ) {
F_25 ( V_4 ) ;
V_38 = true ;
F_26 ( & V_4 -> V_11 ) ;
}
F_27 ( V_4 ) ;
}
if ( ! V_38 )
F_28 ( L_3 ,
V_10 , F_7 ( & V_4 -> V_11 ) ) ;
}
F_29 ( V_4 ) ;
}
static void F_30 ( void * V_39 )
{
struct V_1 * V_2 = V_39 ;
if ( F_31 ( & V_2 -> V_40 ) )
F_17 ( V_2 ) ;
F_32 ( V_41 ) ;
}
static int F_33 ( void * V_39 )
{
struct V_1 * V_2 = V_39 ;
if ( ! F_34 ( V_41 ) )
return - V_42 ;
if ( F_35 ( & V_2 -> V_40 ) == 1 ) {
int V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_32 ( V_41 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_33 )
{
if ( V_33 == V_43 ) {
T_2 V_44 ;
F_37 ( V_2 -> V_4 , V_45 , & V_44 ) ;
if ( V_44 )
return 1 ;
} else if ( V_33 == V_46 ) {
T_2 V_47 ;
T_1 V_17 ;
V_47 = V_2 -> V_4 -> V_48 ;
if ( V_47 ) {
F_13 ( V_2 -> V_4 ,
V_47 + V_49 , & V_17 ) ;
return 1 << ( V_17 & V_50 ) ;
}
} else if ( V_33 == V_51 ) {
T_2 V_47 ;
T_1 V_17 ;
V_47 = V_2 -> V_4 -> V_16 ;
if ( V_47 ) {
F_13 ( V_2 -> V_4 ,
V_47 + V_19 , & V_17 ) ;
return ( V_17 & V_26 ) + 1 ;
}
} else if ( V_33 == V_52 )
if ( F_38 ( V_2 -> V_4 ) )
return 1 ;
return 0 ;
}
static long F_39 ( void * V_39 ,
unsigned int V_6 , unsigned long V_53 )
{
struct V_1 * V_2 = V_39 ;
unsigned long V_54 ;
if ( V_6 == V_55 ) {
struct V_56 V_57 ;
V_54 = F_40 ( struct V_56 , V_58 ) ;
if ( F_41 ( & V_57 , ( void V_59 * ) V_53 , V_54 ) )
return - V_60 ;
if ( V_57 . V_61 < V_54 )
return - V_62 ;
V_57 . V_17 = V_63 ;
if ( V_2 -> V_8 )
V_57 . V_17 |= V_64 ;
V_57 . V_65 = V_66 ;
V_57 . V_58 = V_67 ;
return F_42 ( ( void V_59 * ) V_53 , & V_57 , V_54 ) ;
} else if ( V_6 == V_68 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_69 V_57 ;
V_54 = F_40 ( struct V_69 , V_70 ) ;
if ( F_41 ( & V_57 , ( void V_59 * ) V_53 , V_54 ) )
return - V_60 ;
if ( V_57 . V_61 < V_54 )
return - V_62 ;
switch ( V_57 . V_71 ) {
case V_72 :
V_57 . V_70 = F_43 ( V_57 . V_71 ) ;
V_57 . V_73 = V_4 -> V_74 ;
V_57 . V_17 = V_75 |
V_76 ;
break;
case V_77 ... V_78 :
V_57 . V_70 = F_43 ( V_57 . V_71 ) ;
V_57 . V_73 = F_44 ( V_4 , V_57 . V_71 ) ;
if ( ! V_57 . V_73 ) {
V_57 . V_17 = 0 ;
break;
}
V_57 . V_17 = V_75 |
V_76 ;
if ( F_45 ( V_4 , V_57 . V_71 ) &
V_79 && V_57 . V_73 >= V_80 )
V_57 . V_17 |= V_81 ;
break;
case V_82 :
{
void T_4 * V_83 ;
T_5 V_73 ;
V_57 . V_70 = F_43 ( V_57 . V_71 ) ;
V_57 . V_17 = 0 ;
V_57 . V_73 = F_44 ( V_4 , V_57 . V_71 ) ;
if ( ! V_57 . V_73 )
break;
V_83 = F_46 ( V_4 , & V_73 ) ;
if ( ! V_83 || ! V_73 ) {
V_57 . V_73 = 0 ;
break;
}
F_47 ( V_4 , V_83 ) ;
V_57 . V_17 = V_75 ;
break;
}
case V_84 :
if ( ! V_2 -> V_29 )
return - V_62 ;
V_57 . V_70 = F_43 ( V_57 . V_71 ) ;
V_57 . V_73 = 0xc0000 ;
V_57 . V_17 = V_75 |
V_76 ;
break;
default:
return - V_62 ;
}
return F_42 ( ( void V_59 * ) V_53 , & V_57 , V_54 ) ;
} else if ( V_6 == V_85 ) {
struct V_86 V_57 ;
V_54 = F_40 ( struct V_86 , V_87 ) ;
if ( F_41 ( & V_57 , ( void V_59 * ) V_53 , V_54 ) )
return - V_60 ;
if ( V_57 . V_61 < V_54 || V_57 . V_71 >= V_67 )
return - V_62 ;
switch ( V_57 . V_71 ) {
case V_43 ... V_51 :
break;
case V_52 :
if ( F_38 ( V_2 -> V_4 ) )
break;
default:
return - V_62 ;
}
V_57 . V_17 = V_88 ;
V_57 . V_87 = F_36 ( V_2 , V_57 . V_71 ) ;
if ( V_57 . V_71 == V_43 )
V_57 . V_17 |= ( V_89 |
V_90 ) ;
else
V_57 . V_17 |= V_91 ;
return F_42 ( ( void V_59 * ) V_53 , & V_57 , V_54 ) ;
} else if ( V_6 == V_92 ) {
struct V_93 V_94 ;
T_2 * V_95 = NULL ;
int V_5 = 0 ;
V_54 = F_40 ( struct V_93 , V_87 ) ;
if ( F_41 ( & V_94 , ( void V_59 * ) V_53 , V_54 ) )
return - V_60 ;
if ( V_94 . V_61 < V_54 || V_94 . V_71 >= V_67 ||
V_94 . V_17 & ~ ( V_96 |
V_97 ) )
return - V_62 ;
if ( ! ( V_94 . V_17 & V_31 ) ) {
T_5 V_73 ;
int V_98 = F_36 ( V_2 , V_94 . V_71 ) ;
if ( V_94 . V_17 & V_99 )
V_73 = sizeof( V_100 ) ;
else if ( V_94 . V_17 & V_101 )
V_73 = sizeof( V_102 ) ;
else
return - V_62 ;
if ( V_94 . V_61 - V_54 < V_94 . V_87 * V_73 ||
V_94 . V_103 >= V_98 || V_94 . V_103 + V_94 . V_87 > V_98 )
return - V_62 ;
V_95 = F_48 ( ( void V_59 * ) ( V_53 + V_54 ) ,
V_94 . V_87 * V_73 ) ;
if ( F_49 ( V_95 ) )
return F_50 ( V_95 ) ;
}
F_51 ( & V_2 -> V_104 ) ;
V_5 = F_18 ( V_2 , V_94 . V_17 , V_94 . V_71 ,
V_94 . V_103 , V_94 . V_87 , V_95 ) ;
F_52 ( & V_2 -> V_104 ) ;
F_53 ( V_95 ) ;
return V_5 ;
} else if ( V_6 == V_105 )
return V_2 -> V_8 ?
F_3 ( V_2 -> V_4 ) : - V_62 ;
return - V_106 ;
}
static T_6 F_54 ( void * V_39 , char V_59 * V_107 ,
T_5 V_87 , T_7 * V_108 , bool V_109 )
{
unsigned int V_71 = F_55 ( * V_108 ) ;
struct V_1 * V_2 = V_39 ;
if ( V_71 >= V_66 )
return - V_62 ;
switch ( V_71 ) {
case V_72 :
return F_56 ( V_2 , V_107 , V_87 , V_108 , V_109 ) ;
case V_82 :
if ( V_109 )
return - V_62 ;
return F_57 ( V_2 , V_107 , V_87 , V_108 , false ) ;
case V_77 ... V_78 :
return F_57 ( V_2 , V_107 , V_87 , V_108 , V_109 ) ;
case V_84 :
return F_58 ( V_2 , V_107 , V_87 , V_108 , V_109 ) ;
}
return - V_62 ;
}
static T_6 F_59 ( void * V_39 , char V_59 * V_107 ,
T_5 V_87 , T_7 * V_108 )
{
if ( ! V_87 )
return 0 ;
return F_54 ( V_39 , V_107 , V_87 , V_108 , false ) ;
}
static T_6 F_60 ( void * V_39 , const char V_59 * V_107 ,
T_5 V_87 , T_7 * V_108 )
{
if ( ! V_87 )
return 0 ;
return F_54 ( V_39 , ( char V_59 * ) V_107 , V_87 , V_108 , true ) ;
}
static int F_61 ( void * V_39 , struct V_110 * V_111 )
{
struct V_1 * V_2 = V_39 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_71 ;
T_8 V_112 , V_113 , V_114 , V_115 ;
int V_5 ;
V_71 = V_111 -> V_116 >> ( V_117 - V_118 ) ;
if ( V_111 -> V_119 < V_111 -> V_120 )
return - V_62 ;
if ( ( V_111 -> V_121 & V_122 ) == 0 )
return - V_62 ;
if ( V_71 >= V_82 )
return - V_62 ;
if ( ! ( F_45 ( V_4 , V_71 ) & V_79 ) )
return - V_62 ;
V_112 = F_44 ( V_4 , V_71 ) ;
V_113 = V_111 -> V_119 - V_111 -> V_120 ;
V_114 = V_111 -> V_116 &
( ( 1U << ( V_117 - V_118 ) ) - 1 ) ;
V_115 = V_114 << V_118 ;
if ( V_112 < V_80 || V_115 + V_113 > V_112 )
return - V_62 ;
if ( V_71 == V_2 -> V_21 ) {
if ( ! ( V_115 >= V_2 -> V_23 + V_2 -> V_25 ||
V_115 + V_113 <= V_2 -> V_23 ) )
return - V_62 ;
}
if ( ! V_2 -> V_37 [ V_71 ] ) {
V_5 = F_62 ( V_4 ,
1 << V_71 , L_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_37 [ V_71 ] = F_63 ( V_4 , V_71 , 0 ) ;
}
V_111 -> V_123 = V_2 ;
V_111 -> V_124 = F_64 ( V_111 -> V_124 ) ;
V_111 -> V_116 = ( F_65 ( V_4 , V_71 ) >> V_118 ) + V_114 ;
return F_66 ( V_111 , V_111 -> V_120 , V_111 -> V_116 ,
V_113 , V_111 -> V_124 ) ;
}
static int F_67 ( struct V_3 * V_4 , const struct V_125 * V_126 )
{
T_2 type ;
struct V_1 * V_2 ;
struct V_127 * V_128 ;
int V_5 ;
F_37 ( V_4 , V_129 , & type ) ;
if ( ( type & V_129 ) != V_130 )
return - V_62 ;
V_128 = F_68 ( & V_4 -> V_11 ) ;
if ( ! V_128 )
return - V_62 ;
V_2 = F_69 ( sizeof( * V_2 ) , V_131 ) ;
if ( ! V_2 ) {
F_70 ( V_128 ) ;
return - V_132 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_33 = V_67 ;
F_71 ( & V_2 -> V_104 ) ;
F_72 ( & V_2 -> V_133 ) ;
F_73 ( & V_2 -> V_40 , 0 ) ;
V_5 = F_74 ( & V_4 -> V_11 , & V_134 , V_2 ) ;
if ( V_5 ) {
F_70 ( V_128 ) ;
F_53 ( V_2 ) ;
}
return V_5 ;
}
static void F_75 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( & V_4 -> V_11 ) ;
if ( ! V_2 )
return;
F_70 ( V_4 -> V_11 . V_127 ) ;
F_53 ( V_2 ) ;
}
static T_9 F_77 ( struct V_3 * V_4 ,
T_10 V_135 )
{
struct V_1 * V_2 ;
struct V_136 * V_137 ;
V_137 = F_78 ( & V_4 -> V_11 ) ;
if ( V_137 == NULL )
return V_138 ;
V_2 = F_79 ( V_137 ) ;
if ( V_2 == NULL ) {
F_80 ( V_137 ) ;
return V_138 ;
}
if ( V_2 -> V_139 )
F_81 ( V_2 -> V_139 , 1 ) ;
F_80 ( V_137 ) ;
return V_140 ;
}
static void T_11 F_82 ( void )
{
F_83 ( & V_141 ) ;
F_84 () ;
F_85 () ;
}
static int T_12 F_86 ( void )
{
int V_5 ;
V_5 = F_87 () ;
if ( V_5 )
return V_5 ;
V_5 = F_88 () ;
if ( V_5 )
goto V_142;
V_5 = F_89 ( & V_141 ) ;
if ( V_5 )
goto V_143;
return 0 ;
V_143:
F_84 () ;
V_142:
F_85 () ;
return V_5 ;
}
