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
V_7 = F_15 ( V_4 , V_16 ) ;
if ( V_7 ) {
T_1 V_17 ;
T_3 V_18 ;
F_13 ( V_4 , V_7 + V_19 , & V_17 ) ;
F_16 ( V_4 , V_7 + V_20 , & V_18 ) ;
V_2 -> V_21 = V_18 & V_22 ;
V_2 -> V_23 = V_18 & ~ V_22 ;
V_2 -> V_24 = ( ( V_17 & V_25 ) + 1 ) * 16 ;
} else
V_2 -> V_21 = 0xFF ;
#ifdef F_17
if ( ( V_4 -> V_26 >> 8 ) == V_27 )
V_2 -> V_28 = true ;
#endif
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_29 ;
F_10 ( V_4 ) ;
F_19 ( V_2 , V_30 |
V_31 ,
V_2 -> V_32 , 0 , 0 , NULL ) ;
V_2 -> V_33 = false ;
F_20 ( V_2 ) ;
for ( V_29 = V_34 ; V_29 <= V_35 ; V_29 ++ ) {
if ( ! V_2 -> V_36 [ V_29 ] )
continue;
F_21 ( V_4 , V_2 -> V_36 [ V_29 ] ) ;
F_22 ( V_4 , 1 << V_29 ) ;
V_2 -> V_36 [ V_29 ] = NULL ;
}
if ( F_9 ( V_4 , & V_2 -> V_9 ) ) {
F_23 ( L_2 ,
V_10 , F_7 ( & V_4 -> V_11 ) ) ;
if ( ! V_2 -> V_8 )
return;
F_4 ( V_4 ) ;
}
F_14 ( V_4 , V_14 , V_15 ) ;
if ( V_2 -> V_8 )
F_24 ( V_4 ) ;
F_25 ( V_4 ) ;
}
static void F_26 ( void * V_37 )
{
struct V_1 * V_2 = V_37 ;
if ( F_27 ( & V_2 -> V_38 ) )
F_18 ( V_2 ) ;
F_28 ( V_39 ) ;
}
static int F_29 ( void * V_37 )
{
struct V_1 * V_2 = V_37 ;
if ( ! F_30 ( V_39 ) )
return - V_40 ;
if ( F_31 ( & V_2 -> V_38 ) == 1 ) {
int V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_28 ( V_39 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , int V_32 )
{
if ( V_32 == V_41 ) {
T_2 V_42 ;
F_33 ( V_2 -> V_4 , V_43 , & V_42 ) ;
if ( V_42 )
return 1 ;
} else if ( V_32 == V_44 ) {
T_2 V_45 ;
T_1 V_17 ;
V_45 = F_15 ( V_2 -> V_4 , V_46 ) ;
if ( V_45 ) {
F_13 ( V_2 -> V_4 ,
V_45 + V_47 , & V_17 ) ;
return 1 << ( V_17 & V_48 ) ;
}
} else if ( V_32 == V_49 ) {
T_2 V_45 ;
T_1 V_17 ;
V_45 = F_15 ( V_2 -> V_4 , V_16 ) ;
if ( V_45 ) {
F_13 ( V_2 -> V_4 ,
V_45 + V_19 , & V_17 ) ;
return ( V_17 & V_25 ) + 1 ;
}
}
return 0 ;
}
static long F_34 ( void * V_37 ,
unsigned int V_6 , unsigned long V_50 )
{
struct V_1 * V_2 = V_37 ;
unsigned long V_51 ;
if ( V_6 == V_52 ) {
struct V_53 V_54 ;
V_51 = F_35 ( struct V_53 , V_55 ) ;
if ( F_36 ( & V_54 , ( void V_56 * ) V_50 , V_51 ) )
return - V_57 ;
if ( V_54 . V_58 < V_51 )
return - V_59 ;
V_54 . V_17 = V_60 ;
if ( V_2 -> V_8 )
V_54 . V_17 |= V_61 ;
V_54 . V_62 = V_63 ;
V_54 . V_55 = V_64 ;
return F_37 ( ( void V_56 * ) V_50 , & V_54 , V_51 ) ;
} else if ( V_6 == V_65 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_66 V_54 ;
V_51 = F_35 ( struct V_66 , V_67 ) ;
if ( F_36 ( & V_54 , ( void V_56 * ) V_50 , V_51 ) )
return - V_57 ;
if ( V_54 . V_58 < V_51 )
return - V_59 ;
switch ( V_54 . V_68 ) {
case V_69 :
V_54 . V_67 = F_38 ( V_54 . V_68 ) ;
V_54 . V_70 = V_4 -> V_71 ;
V_54 . V_17 = V_72 |
V_73 ;
break;
case V_74 ... V_75 :
V_54 . V_67 = F_38 ( V_54 . V_68 ) ;
V_54 . V_70 = F_39 ( V_4 , V_54 . V_68 ) ;
if ( ! V_54 . V_70 ) {
V_54 . V_17 = 0 ;
break;
}
V_54 . V_17 = V_72 |
V_73 ;
if ( F_40 ( V_4 , V_54 . V_68 ) &
V_76 && V_54 . V_70 >= V_77 )
V_54 . V_17 |= V_78 ;
break;
case V_79 :
{
void T_4 * V_80 ;
T_5 V_70 ;
V_54 . V_67 = F_38 ( V_54 . V_68 ) ;
V_54 . V_17 = 0 ;
V_54 . V_70 = F_39 ( V_4 , V_54 . V_68 ) ;
if ( ! V_54 . V_70 )
break;
V_80 = F_41 ( V_4 , & V_70 ) ;
if ( ! V_80 || ! V_70 ) {
V_54 . V_70 = 0 ;
break;
}
F_42 ( V_4 , V_80 ) ;
V_54 . V_17 = V_72 ;
break;
}
case V_81 :
if ( ! V_2 -> V_28 )
return - V_59 ;
V_54 . V_67 = F_38 ( V_54 . V_68 ) ;
V_54 . V_70 = 0xc0000 ;
V_54 . V_17 = V_72 |
V_73 ;
break;
default:
return - V_59 ;
}
return F_37 ( ( void V_56 * ) V_50 , & V_54 , V_51 ) ;
} else if ( V_6 == V_82 ) {
struct V_83 V_54 ;
V_51 = F_35 ( struct V_83 , V_84 ) ;
if ( F_36 ( & V_54 , ( void V_56 * ) V_50 , V_51 ) )
return - V_57 ;
if ( V_54 . V_58 < V_51 || V_54 . V_68 >= V_64 )
return - V_59 ;
V_54 . V_17 = V_85 ;
V_54 . V_84 = F_32 ( V_2 , V_54 . V_68 ) ;
if ( V_54 . V_68 == V_41 )
V_54 . V_17 |= ( V_86 |
V_87 ) ;
else
V_54 . V_17 |= V_88 ;
return F_37 ( ( void V_56 * ) V_50 , & V_54 , V_51 ) ;
} else if ( V_6 == V_89 ) {
struct V_90 V_91 ;
T_2 * V_92 = NULL ;
int V_5 = 0 ;
V_51 = F_35 ( struct V_90 , V_84 ) ;
if ( F_36 ( & V_91 , ( void V_56 * ) V_50 , V_51 ) )
return - V_57 ;
if ( V_91 . V_58 < V_51 || V_91 . V_68 >= V_64 ||
V_91 . V_17 & ~ ( V_93 |
V_94 ) )
return - V_59 ;
if ( ! ( V_91 . V_17 & V_30 ) ) {
T_5 V_70 ;
int V_95 = F_32 ( V_2 , V_91 . V_68 ) ;
if ( V_91 . V_17 & V_96 )
V_70 = sizeof( V_97 ) ;
else if ( V_91 . V_17 & V_98 )
V_70 = sizeof( V_99 ) ;
else
return - V_59 ;
if ( V_91 . V_58 - V_51 < V_91 . V_84 * V_70 ||
V_91 . V_100 >= V_95 || V_91 . V_100 + V_91 . V_84 > V_95 )
return - V_59 ;
V_92 = F_43 ( ( void V_56 * ) ( V_50 + V_51 ) ,
V_91 . V_84 * V_70 ) ;
if ( F_44 ( V_92 ) )
return F_45 ( V_92 ) ;
}
F_46 ( & V_2 -> V_101 ) ;
V_5 = F_19 ( V_2 , V_91 . V_17 , V_91 . V_68 ,
V_91 . V_100 , V_91 . V_84 , V_92 ) ;
F_47 ( & V_2 -> V_101 ) ;
F_48 ( V_92 ) ;
return V_5 ;
} else if ( V_6 == V_102 )
return V_2 -> V_8 ?
F_3 ( V_2 -> V_4 ) : - V_59 ;
return - V_103 ;
}
static T_6 F_49 ( void * V_37 , char V_56 * V_104 ,
T_5 V_84 , T_7 * V_105 , bool V_106 )
{
unsigned int V_68 = F_50 ( * V_105 ) ;
struct V_1 * V_2 = V_37 ;
if ( V_68 >= V_63 )
return - V_59 ;
switch ( V_68 ) {
case V_69 :
return F_51 ( V_2 , V_104 , V_84 , V_105 , V_106 ) ;
case V_79 :
if ( V_106 )
return - V_59 ;
return F_52 ( V_2 , V_104 , V_84 , V_105 , false ) ;
case V_74 ... V_75 :
return F_52 ( V_2 , V_104 , V_84 , V_105 , V_106 ) ;
case V_81 :
return F_53 ( V_2 , V_104 , V_84 , V_105 , V_106 ) ;
}
return - V_59 ;
}
static T_6 F_54 ( void * V_37 , char V_56 * V_104 ,
T_5 V_84 , T_7 * V_105 )
{
if ( ! V_84 )
return 0 ;
return F_49 ( V_37 , V_104 , V_84 , V_105 , false ) ;
}
static T_6 F_55 ( void * V_37 , const char V_56 * V_104 ,
T_5 V_84 , T_7 * V_105 )
{
if ( ! V_84 )
return 0 ;
return F_49 ( V_37 , ( char V_56 * ) V_104 , V_84 , V_105 , true ) ;
}
static int F_56 ( void * V_37 , struct V_107 * V_108 )
{
struct V_1 * V_2 = V_37 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_68 ;
T_8 V_109 , V_110 , V_111 , V_112 ;
int V_5 ;
V_68 = V_108 -> V_113 >> ( V_114 - V_115 ) ;
if ( V_108 -> V_116 < V_108 -> V_117 )
return - V_59 ;
if ( ( V_108 -> V_118 & V_119 ) == 0 )
return - V_59 ;
if ( V_68 >= V_79 )
return - V_59 ;
if ( ! ( F_40 ( V_4 , V_68 ) & V_76 ) )
return - V_59 ;
V_109 = F_39 ( V_4 , V_68 ) ;
V_110 = V_108 -> V_116 - V_108 -> V_117 ;
V_111 = V_108 -> V_113 &
( ( 1U << ( V_114 - V_115 ) ) - 1 ) ;
V_112 = V_111 << V_115 ;
if ( V_109 < V_77 || V_112 + V_110 > V_109 )
return - V_59 ;
if ( V_68 == V_2 -> V_21 ) {
if ( ! ( V_112 >= V_2 -> V_23 + V_2 -> V_24 ||
V_112 + V_110 <= V_2 -> V_23 ) )
return - V_59 ;
}
if ( ! V_2 -> V_36 [ V_68 ] ) {
V_5 = F_57 ( V_4 ,
1 << V_68 , L_3 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_36 [ V_68 ] = F_58 ( V_4 , V_68 , 0 ) ;
}
V_108 -> V_120 = V_2 ;
V_108 -> V_118 |= V_121 | V_122 | V_123 ;
V_108 -> V_124 = F_59 ( V_108 -> V_124 ) ;
V_108 -> V_113 = ( F_60 ( V_4 , V_68 ) >> V_115 ) + V_111 ;
return F_61 ( V_108 , V_108 -> V_117 , V_108 -> V_113 ,
V_110 , V_108 -> V_124 ) ;
}
static int F_62 ( struct V_3 * V_4 , const struct V_125 * V_126 )
{
T_2 type ;
struct V_1 * V_2 ;
struct V_127 * V_128 ;
int V_5 ;
F_33 ( V_4 , V_129 , & type ) ;
if ( ( type & V_129 ) != V_130 )
return - V_59 ;
V_128 = F_63 ( & V_4 -> V_11 ) ;
if ( ! V_128 )
return - V_59 ;
V_2 = F_64 ( sizeof( * V_2 ) , V_131 ) ;
if ( ! V_2 ) {
F_65 ( V_128 ) ;
return - V_132 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_32 = V_64 ;
F_66 ( & V_2 -> V_101 ) ;
F_67 ( & V_2 -> V_133 ) ;
F_68 ( & V_2 -> V_38 , 0 ) ;
V_5 = F_69 ( & V_4 -> V_11 , & V_134 , V_2 ) ;
if ( V_5 ) {
F_65 ( V_128 ) ;
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
F_65 ( V_4 -> V_11 . V_127 ) ;
F_48 ( V_2 ) ;
}
static void T_9 F_72 ( void )
{
F_73 ( & V_135 ) ;
F_74 () ;
F_75 () ;
}
static int T_10 F_76 ( void )
{
int V_5 ;
V_5 = F_77 () ;
if ( V_5 )
return V_5 ;
V_5 = F_78 () ;
if ( V_5 )
goto V_136;
V_5 = F_79 ( & V_135 ) ;
if ( V_5 )
goto V_137;
return 0 ;
V_137:
F_74 () ;
V_136:
F_75 () ;
return V_5 ;
}
