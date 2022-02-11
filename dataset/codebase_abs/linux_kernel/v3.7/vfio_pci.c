static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_1 V_6 ;
T_2 V_7 ;
V_2 -> V_8 = ( F_2 ( V_4 ) == 0 ) ;
F_3 ( V_4 ) ;
V_2 -> V_9 = F_4 ( V_4 ) ;
if ( ! V_2 -> V_9 )
F_5 ( L_1 ,
V_10 , F_6 ( & V_4 -> V_11 ) ) ;
V_5 = F_7 ( V_2 ) ;
if ( V_5 )
goto V_12;
if ( F_8 ( ! V_13 ) )
V_2 -> V_14 = F_9 ( V_4 ) ;
F_10 ( V_4 , V_15 , & V_6 ) ;
if ( V_2 -> V_14 && ( V_6 & V_16 ) ) {
V_6 &= ~ V_16 ;
F_11 ( V_4 , V_15 , V_6 ) ;
}
V_7 = F_12 ( V_4 , V_17 ) ;
if ( V_7 ) {
T_1 V_18 ;
T_3 V_19 ;
F_10 ( V_4 , V_7 + V_20 , & V_18 ) ;
F_13 ( V_4 , V_7 + V_21 , & V_19 ) ;
V_2 -> V_22 = V_19 & V_23 ;
V_2 -> V_24 = V_19 & ~ V_23 ;
V_2 -> V_25 = ( ( V_18 & V_26 ) + 1 ) * 16 ;
} else
V_2 -> V_22 = 0xFF ;
V_5 = F_14 ( V_4 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_15 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_16 ( V_2 ) ;
return V_5 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_27 ;
F_18 ( V_2 -> V_4 ) ;
F_19 ( V_2 , V_28 |
V_29 ,
V_2 -> V_30 , 0 , 0 , NULL ) ;
V_2 -> V_31 = false ;
F_16 ( V_2 ) ;
F_2 ( V_2 -> V_4 ) ;
if ( F_20 ( V_2 -> V_4 ,
& V_2 -> V_9 ) == 0 )
F_21 ( V_2 -> V_4 ) ;
else
F_22 ( L_2 ,
V_10 , F_6 ( & V_2 -> V_4 -> V_11 ) ) ;
for ( V_27 = V_32 ; V_27 <= V_33 ; V_27 ++ ) {
if ( ! V_2 -> V_34 [ V_27 ] )
continue;
F_23 ( V_2 -> V_4 , V_2 -> V_34 [ V_27 ] ) ;
F_24 ( V_2 -> V_4 , 1 << V_27 ) ;
V_2 -> V_34 [ V_27 ] = NULL ;
}
}
static void F_25 ( void * V_35 )
{
struct V_1 * V_2 = V_35 ;
if ( F_26 ( & V_2 -> V_36 ) )
F_17 ( V_2 ) ;
F_27 ( V_37 ) ;
}
static int F_28 ( void * V_35 )
{
struct V_1 * V_2 = V_35 ;
if ( ! F_29 ( V_37 ) )
return - V_38 ;
if ( F_30 ( & V_2 -> V_36 ) == 1 ) {
int V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_27 ( V_37 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_30 )
{
if ( V_30 == V_39 ) {
T_2 V_40 ;
F_32 ( V_2 -> V_4 , V_41 , & V_40 ) ;
if ( V_40 )
return 1 ;
} else if ( V_30 == V_42 ) {
T_2 V_43 ;
T_1 V_18 ;
V_43 = F_12 ( V_2 -> V_4 , V_44 ) ;
if ( V_43 ) {
F_10 ( V_2 -> V_4 ,
V_43 + V_45 , & V_18 ) ;
return 1 << ( V_18 & V_46 ) ;
}
} else if ( V_30 == V_47 ) {
T_2 V_43 ;
T_1 V_18 ;
V_43 = F_12 ( V_2 -> V_4 , V_17 ) ;
if ( V_43 ) {
F_10 ( V_2 -> V_4 ,
V_43 + V_20 , & V_18 ) ;
return ( V_18 & V_26 ) + 1 ;
}
}
return 0 ;
}
static long F_33 ( void * V_35 ,
unsigned int V_6 , unsigned long V_48 )
{
struct V_1 * V_2 = V_35 ;
unsigned long V_49 ;
if ( V_6 == V_50 ) {
struct V_51 V_52 ;
V_49 = F_34 ( struct V_51 , V_53 ) ;
if ( F_35 ( & V_52 , ( void V_54 * ) V_48 , V_49 ) )
return - V_55 ;
if ( V_52 . V_56 < V_49 )
return - V_57 ;
V_52 . V_18 = V_58 ;
if ( V_2 -> V_8 )
V_52 . V_18 |= V_59 ;
V_52 . V_60 = V_61 ;
V_52 . V_53 = V_62 ;
return F_36 ( ( void V_54 * ) V_48 , & V_52 , V_49 ) ;
} else if ( V_6 == V_63 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_64 V_52 ;
V_49 = F_34 ( struct V_64 , V_65 ) ;
if ( F_35 ( & V_52 , ( void V_54 * ) V_48 , V_49 ) )
return - V_55 ;
if ( V_52 . V_56 < V_49 )
return - V_57 ;
switch ( V_52 . V_66 ) {
case V_67 :
V_52 . V_65 = F_37 ( V_52 . V_66 ) ;
V_52 . V_68 = V_4 -> V_69 ;
V_52 . V_18 = V_70 |
V_71 ;
break;
case V_72 ... V_73 :
V_52 . V_65 = F_37 ( V_52 . V_66 ) ;
V_52 . V_68 = F_38 ( V_4 , V_52 . V_66 ) ;
if ( ! V_52 . V_68 ) {
V_52 . V_18 = 0 ;
break;
}
V_52 . V_18 = V_70 |
V_71 ;
if ( F_39 ( V_4 , V_52 . V_66 ) &
V_74 && V_52 . V_68 >= V_75 )
V_52 . V_18 |= V_76 ;
break;
case V_77 :
{
void T_4 * V_78 ;
T_5 V_68 ;
V_52 . V_65 = F_37 ( V_52 . V_66 ) ;
V_52 . V_18 = 0 ;
V_52 . V_68 = F_38 ( V_4 , V_52 . V_66 ) ;
if ( ! V_52 . V_68 )
break;
V_78 = F_40 ( V_4 , & V_68 ) ;
if ( ! V_78 || ! V_68 ) {
V_52 . V_68 = 0 ;
break;
}
F_41 ( V_4 , V_78 ) ;
V_52 . V_18 = V_70 ;
break;
}
default:
return - V_57 ;
}
return F_36 ( ( void V_54 * ) V_48 , & V_52 , V_49 ) ;
} else if ( V_6 == V_79 ) {
struct V_80 V_52 ;
V_49 = F_34 ( struct V_80 , V_81 ) ;
if ( F_35 ( & V_52 , ( void V_54 * ) V_48 , V_49 ) )
return - V_55 ;
if ( V_52 . V_56 < V_49 || V_52 . V_66 >= V_62 )
return - V_57 ;
V_52 . V_18 = V_82 ;
V_52 . V_81 = F_31 ( V_2 , V_52 . V_66 ) ;
if ( V_52 . V_66 == V_39 )
V_52 . V_18 |= ( V_83 |
V_84 ) ;
else
V_52 . V_18 |= V_85 ;
return F_36 ( ( void V_54 * ) V_48 , & V_52 , V_49 ) ;
} else if ( V_6 == V_86 ) {
struct V_87 V_88 ;
T_2 * V_89 = NULL ;
int V_5 = 0 ;
V_49 = F_34 ( struct V_87 , V_81 ) ;
if ( F_35 ( & V_88 , ( void V_54 * ) V_48 , V_49 ) )
return - V_55 ;
if ( V_88 . V_56 < V_49 || V_88 . V_66 >= V_62 ||
V_88 . V_18 & ~ ( V_90 |
V_91 ) )
return - V_57 ;
if ( ! ( V_88 . V_18 & V_28 ) ) {
T_5 V_68 ;
if ( V_88 . V_18 & V_92 )
V_68 = sizeof( V_93 ) ;
else if ( V_88 . V_18 & V_94 )
V_68 = sizeof( V_95 ) ;
else
return - V_57 ;
if ( V_88 . V_56 - V_49 < V_88 . V_81 * V_68 ||
V_88 . V_81 > F_31 ( V_2 , V_88 . V_66 ) )
return - V_57 ;
V_89 = F_42 ( V_88 . V_81 * V_68 , V_96 ) ;
if ( ! V_89 )
return - V_97 ;
if ( F_35 ( V_89 , ( void V_54 * ) ( V_48 + V_49 ) ,
V_88 . V_81 * V_68 ) ) {
F_15 ( V_89 ) ;
return - V_55 ;
}
}
F_43 ( & V_2 -> V_98 ) ;
V_5 = F_19 ( V_2 , V_88 . V_18 , V_88 . V_66 ,
V_88 . V_99 , V_88 . V_81 , V_89 ) ;
F_44 ( & V_2 -> V_98 ) ;
F_15 ( V_89 ) ;
return V_5 ;
} else if ( V_6 == V_100 )
return V_2 -> V_8 ?
F_2 ( V_2 -> V_4 ) : - V_57 ;
return - V_101 ;
}
static T_6 F_45 ( void * V_35 , char V_54 * V_102 ,
T_5 V_81 , T_7 * V_103 )
{
unsigned int V_66 = F_46 ( * V_103 ) ;
struct V_1 * V_2 = V_35 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_66 >= V_61 )
return - V_57 ;
if ( V_66 == V_67 )
return F_47 ( V_2 , V_102 , V_81 , V_103 , false ) ;
else if ( V_66 == V_77 )
return F_48 ( V_2 , V_102 , V_81 , V_103 , false ) ;
else if ( F_39 ( V_4 , V_66 ) & V_104 )
return F_49 ( V_2 , V_102 , V_81 , V_103 , false ) ;
else if ( F_39 ( V_4 , V_66 ) & V_74 )
return F_48 ( V_2 , V_102 , V_81 , V_103 , false ) ;
return - V_57 ;
}
static T_6 F_50 ( void * V_35 , const char V_54 * V_102 ,
T_5 V_81 , T_7 * V_103 )
{
unsigned int V_66 = F_46 ( * V_103 ) ;
struct V_1 * V_2 = V_35 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_66 >= V_61 )
return - V_57 ;
if ( V_66 == V_67 )
return F_47 ( V_2 , ( char V_54 * ) V_102 ,
V_81 , V_103 , true ) ;
else if ( V_66 == V_77 )
return - V_57 ;
else if ( F_39 ( V_4 , V_66 ) & V_104 )
return F_49 ( V_2 , ( char V_54 * ) V_102 ,
V_81 , V_103 , true ) ;
else if ( F_39 ( V_4 , V_66 ) & V_74 ) {
return F_48 ( V_2 , ( char V_54 * ) V_102 ,
V_81 , V_103 , true ) ;
}
return - V_57 ;
}
static int F_51 ( void * V_35 , struct V_105 * V_106 )
{
struct V_1 * V_2 = V_35 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_66 ;
T_8 V_107 , V_108 , V_109 , V_110 ;
int V_5 ;
V_66 = V_106 -> V_111 >> ( V_112 - V_113 ) ;
if ( V_106 -> V_114 < V_106 -> V_115 )
return - V_57 ;
if ( ( V_106 -> V_116 & V_117 ) == 0 )
return - V_57 ;
if ( V_66 >= V_77 )
return - V_57 ;
if ( ! ( F_39 ( V_4 , V_66 ) & V_74 ) )
return - V_57 ;
V_107 = F_38 ( V_4 , V_66 ) ;
V_108 = V_106 -> V_114 - V_106 -> V_115 ;
V_109 = V_106 -> V_111 &
( ( 1U << ( V_112 - V_113 ) ) - 1 ) ;
V_110 = V_109 << V_113 ;
if ( V_107 < V_75 || V_110 + V_108 > V_107 )
return - V_57 ;
if ( V_66 == V_2 -> V_22 ) {
if ( ! ( V_110 >= V_2 -> V_24 + V_2 -> V_25 ||
V_110 + V_108 <= V_2 -> V_24 ) )
return - V_57 ;
}
if ( ! V_2 -> V_34 [ V_66 ] ) {
V_5 = F_52 ( V_4 ,
1 << V_66 , L_3 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_34 [ V_66 ] = F_53 ( V_4 , V_66 , 0 ) ;
}
V_106 -> V_118 = V_2 ;
V_106 -> V_116 |= V_119 | V_120 | V_121 ;
V_106 -> V_122 = F_54 ( V_106 -> V_122 ) ;
V_106 -> V_111 = ( F_55 ( V_4 , V_66 ) >> V_113 ) + V_109 ;
return F_56 ( V_106 , V_106 -> V_115 , V_106 -> V_111 ,
V_108 , V_106 -> V_122 ) ;
}
static int F_57 ( struct V_3 * V_4 , const struct V_123 * V_124 )
{
T_2 type ;
struct V_1 * V_2 ;
struct V_125 * V_126 ;
int V_5 ;
F_32 ( V_4 , V_127 , & type ) ;
if ( ( type & V_127 ) != V_128 )
return - V_57 ;
V_126 = F_58 ( & V_4 -> V_11 ) ;
if ( ! V_126 )
return - V_57 ;
V_2 = F_59 ( sizeof( * V_2 ) , V_96 ) ;
if ( ! V_2 ) {
F_60 ( V_126 ) ;
return - V_97 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_30 = V_62 ;
F_61 ( & V_2 -> V_98 ) ;
F_62 ( & V_2 -> V_129 ) ;
F_63 ( & V_2 -> V_36 , 0 ) ;
V_5 = F_64 ( & V_4 -> V_11 , & V_130 , V_2 ) ;
if ( V_5 ) {
F_60 ( V_126 ) ;
F_15 ( V_2 ) ;
}
return V_5 ;
}
static void F_65 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( & V_4 -> V_11 ) ;
if ( ! V_2 )
return;
F_60 ( V_4 -> V_11 . V_125 ) ;
F_15 ( V_2 ) ;
}
static void T_9 F_67 ( void )
{
F_68 ( & V_131 ) ;
F_69 () ;
F_70 () ;
}
static int T_10 F_71 ( void )
{
int V_5 ;
V_5 = F_72 () ;
if ( V_5 )
return V_5 ;
V_5 = F_73 () ;
if ( V_5 )
goto V_132;
V_5 = F_74 ( & V_131 ) ;
if ( V_5 )
goto V_133;
return 0 ;
V_132:
F_69 () ;
V_133:
F_70 () ;
return V_5 ;
}
