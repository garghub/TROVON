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
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_26 ;
F_10 ( V_4 ) ;
F_18 ( V_2 , V_27 |
V_28 ,
V_2 -> V_29 , 0 , 0 , NULL ) ;
V_2 -> V_30 = false ;
F_19 ( V_2 ) ;
for ( V_26 = V_31 ; V_26 <= V_32 ; V_26 ++ ) {
if ( ! V_2 -> V_33 [ V_26 ] )
continue;
F_20 ( V_4 , V_2 -> V_33 [ V_26 ] ) ;
F_21 ( V_4 , 1 << V_26 ) ;
V_2 -> V_33 [ V_26 ] = NULL ;
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
static void F_25 ( void * V_34 )
{
struct V_1 * V_2 = V_34 ;
if ( F_26 ( & V_2 -> V_35 ) )
F_17 ( V_2 ) ;
F_27 ( V_36 ) ;
}
static int F_28 ( void * V_34 )
{
struct V_1 * V_2 = V_34 ;
if ( ! F_29 ( V_36 ) )
return - V_37 ;
if ( F_30 ( & V_2 -> V_35 ) == 1 ) {
int V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_27 ( V_36 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_29 )
{
if ( V_29 == V_38 ) {
T_2 V_39 ;
F_32 ( V_2 -> V_4 , V_40 , & V_39 ) ;
if ( V_39 )
return 1 ;
} else if ( V_29 == V_41 ) {
T_2 V_42 ;
T_1 V_17 ;
V_42 = F_15 ( V_2 -> V_4 , V_43 ) ;
if ( V_42 ) {
F_13 ( V_2 -> V_4 ,
V_42 + V_44 , & V_17 ) ;
return 1 << ( V_17 & V_45 ) ;
}
} else if ( V_29 == V_46 ) {
T_2 V_42 ;
T_1 V_17 ;
V_42 = F_15 ( V_2 -> V_4 , V_16 ) ;
if ( V_42 ) {
F_13 ( V_2 -> V_4 ,
V_42 + V_19 , & V_17 ) ;
return ( V_17 & V_25 ) + 1 ;
}
}
return 0 ;
}
static long F_33 ( void * V_34 ,
unsigned int V_6 , unsigned long V_47 )
{
struct V_1 * V_2 = V_34 ;
unsigned long V_48 ;
if ( V_6 == V_49 ) {
struct V_50 V_51 ;
V_48 = F_34 ( struct V_50 , V_52 ) ;
if ( F_35 ( & V_51 , ( void V_53 * ) V_47 , V_48 ) )
return - V_54 ;
if ( V_51 . V_55 < V_48 )
return - V_56 ;
V_51 . V_17 = V_57 ;
if ( V_2 -> V_8 )
V_51 . V_17 |= V_58 ;
V_51 . V_59 = V_60 ;
V_51 . V_52 = V_61 ;
return F_36 ( ( void V_53 * ) V_47 , & V_51 , V_48 ) ;
} else if ( V_6 == V_62 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_63 V_51 ;
V_48 = F_34 ( struct V_63 , V_64 ) ;
if ( F_35 ( & V_51 , ( void V_53 * ) V_47 , V_48 ) )
return - V_54 ;
if ( V_51 . V_55 < V_48 )
return - V_56 ;
switch ( V_51 . V_65 ) {
case V_66 :
V_51 . V_64 = F_37 ( V_51 . V_65 ) ;
V_51 . V_67 = V_4 -> V_68 ;
V_51 . V_17 = V_69 |
V_70 ;
break;
case V_71 ... V_72 :
V_51 . V_64 = F_37 ( V_51 . V_65 ) ;
V_51 . V_67 = F_38 ( V_4 , V_51 . V_65 ) ;
if ( ! V_51 . V_67 ) {
V_51 . V_17 = 0 ;
break;
}
V_51 . V_17 = V_69 |
V_70 ;
if ( F_39 ( V_4 , V_51 . V_65 ) &
V_73 && V_51 . V_67 >= V_74 )
V_51 . V_17 |= V_75 ;
break;
case V_76 :
{
void T_4 * V_77 ;
T_5 V_67 ;
V_51 . V_64 = F_37 ( V_51 . V_65 ) ;
V_51 . V_17 = 0 ;
V_51 . V_67 = F_38 ( V_4 , V_51 . V_65 ) ;
if ( ! V_51 . V_67 )
break;
V_77 = F_40 ( V_4 , & V_67 ) ;
if ( ! V_77 || ! V_67 ) {
V_51 . V_67 = 0 ;
break;
}
F_41 ( V_4 , V_77 ) ;
V_51 . V_17 = V_69 ;
break;
}
default:
return - V_56 ;
}
return F_36 ( ( void V_53 * ) V_47 , & V_51 , V_48 ) ;
} else if ( V_6 == V_78 ) {
struct V_79 V_51 ;
V_48 = F_34 ( struct V_79 , V_80 ) ;
if ( F_35 ( & V_51 , ( void V_53 * ) V_47 , V_48 ) )
return - V_54 ;
if ( V_51 . V_55 < V_48 || V_51 . V_65 >= V_61 )
return - V_56 ;
V_51 . V_17 = V_81 ;
V_51 . V_80 = F_31 ( V_2 , V_51 . V_65 ) ;
if ( V_51 . V_65 == V_38 )
V_51 . V_17 |= ( V_82 |
V_83 ) ;
else
V_51 . V_17 |= V_84 ;
return F_36 ( ( void V_53 * ) V_47 , & V_51 , V_48 ) ;
} else if ( V_6 == V_85 ) {
struct V_86 V_87 ;
T_2 * V_88 = NULL ;
int V_5 = 0 ;
V_48 = F_34 ( struct V_86 , V_80 ) ;
if ( F_35 ( & V_87 , ( void V_53 * ) V_47 , V_48 ) )
return - V_54 ;
if ( V_87 . V_55 < V_48 || V_87 . V_65 >= V_61 ||
V_87 . V_17 & ~ ( V_89 |
V_90 ) )
return - V_56 ;
if ( ! ( V_87 . V_17 & V_27 ) ) {
T_5 V_67 ;
if ( V_87 . V_17 & V_91 )
V_67 = sizeof( V_92 ) ;
else if ( V_87 . V_17 & V_93 )
V_67 = sizeof( V_94 ) ;
else
return - V_56 ;
if ( V_87 . V_55 - V_48 < V_87 . V_80 * V_67 ||
V_87 . V_80 > F_31 ( V_2 , V_87 . V_65 ) )
return - V_56 ;
V_88 = F_42 ( ( void V_53 * ) ( V_47 + V_48 ) ,
V_87 . V_80 * V_67 ) ;
if ( F_43 ( V_88 ) )
return F_44 ( V_88 ) ;
}
F_45 ( & V_2 -> V_95 ) ;
V_5 = F_18 ( V_2 , V_87 . V_17 , V_87 . V_65 ,
V_87 . V_96 , V_87 . V_80 , V_88 ) ;
F_46 ( & V_2 -> V_95 ) ;
F_47 ( V_88 ) ;
return V_5 ;
} else if ( V_6 == V_97 )
return V_2 -> V_8 ?
F_3 ( V_2 -> V_4 ) : - V_56 ;
return - V_98 ;
}
static T_6 F_48 ( void * V_34 , char V_53 * V_99 ,
T_5 V_80 , T_7 * V_100 )
{
unsigned int V_65 = F_49 ( * V_100 ) ;
struct V_1 * V_2 = V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_65 >= V_60 )
return - V_56 ;
if ( V_65 == V_66 )
return F_50 ( V_2 , V_99 , V_80 , V_100 , false ) ;
else if ( V_65 == V_76 )
return F_51 ( V_2 , V_99 , V_80 , V_100 , false ) ;
else if ( F_39 ( V_4 , V_65 ) & V_101 )
return F_52 ( V_2 , V_99 , V_80 , V_100 , false ) ;
else if ( F_39 ( V_4 , V_65 ) & V_73 )
return F_51 ( V_2 , V_99 , V_80 , V_100 , false ) ;
return - V_56 ;
}
static T_6 F_53 ( void * V_34 , const char V_53 * V_99 ,
T_5 V_80 , T_7 * V_100 )
{
unsigned int V_65 = F_49 ( * V_100 ) ;
struct V_1 * V_2 = V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_65 >= V_60 )
return - V_56 ;
if ( V_65 == V_66 )
return F_50 ( V_2 , ( char V_53 * ) V_99 ,
V_80 , V_100 , true ) ;
else if ( V_65 == V_76 )
return - V_56 ;
else if ( F_39 ( V_4 , V_65 ) & V_101 )
return F_52 ( V_2 , ( char V_53 * ) V_99 ,
V_80 , V_100 , true ) ;
else if ( F_39 ( V_4 , V_65 ) & V_73 ) {
return F_51 ( V_2 , ( char V_53 * ) V_99 ,
V_80 , V_100 , true ) ;
}
return - V_56 ;
}
static int F_54 ( void * V_34 , struct V_102 * V_103 )
{
struct V_1 * V_2 = V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_65 ;
T_8 V_104 , V_105 , V_106 , V_107 ;
int V_5 ;
V_65 = V_103 -> V_108 >> ( V_109 - V_110 ) ;
if ( V_103 -> V_111 < V_103 -> V_112 )
return - V_56 ;
if ( ( V_103 -> V_113 & V_114 ) == 0 )
return - V_56 ;
if ( V_65 >= V_76 )
return - V_56 ;
if ( ! ( F_39 ( V_4 , V_65 ) & V_73 ) )
return - V_56 ;
V_104 = F_38 ( V_4 , V_65 ) ;
V_105 = V_103 -> V_111 - V_103 -> V_112 ;
V_106 = V_103 -> V_108 &
( ( 1U << ( V_109 - V_110 ) ) - 1 ) ;
V_107 = V_106 << V_110 ;
if ( V_104 < V_74 || V_107 + V_105 > V_104 )
return - V_56 ;
if ( V_65 == V_2 -> V_21 ) {
if ( ! ( V_107 >= V_2 -> V_23 + V_2 -> V_24 ||
V_107 + V_105 <= V_2 -> V_23 ) )
return - V_56 ;
}
if ( ! V_2 -> V_33 [ V_65 ] ) {
V_5 = F_55 ( V_4 ,
1 << V_65 , L_3 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_33 [ V_65 ] = F_56 ( V_4 , V_65 , 0 ) ;
}
V_103 -> V_115 = V_2 ;
V_103 -> V_113 |= V_116 | V_117 | V_118 ;
V_103 -> V_119 = F_57 ( V_103 -> V_119 ) ;
V_103 -> V_108 = ( F_58 ( V_4 , V_65 ) >> V_110 ) + V_106 ;
return F_59 ( V_103 , V_103 -> V_112 , V_103 -> V_108 ,
V_105 , V_103 -> V_119 ) ;
}
static int F_60 ( struct V_3 * V_4 , const struct V_120 * V_121 )
{
T_2 type ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
int V_5 ;
F_32 ( V_4 , V_124 , & type ) ;
if ( ( type & V_124 ) != V_125 )
return - V_56 ;
V_123 = F_61 ( & V_4 -> V_11 ) ;
if ( ! V_123 )
return - V_56 ;
V_2 = F_62 ( sizeof( * V_2 ) , V_126 ) ;
if ( ! V_2 ) {
F_63 ( V_123 ) ;
return - V_127 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_29 = V_61 ;
F_64 ( & V_2 -> V_95 ) ;
F_65 ( & V_2 -> V_128 ) ;
F_66 ( & V_2 -> V_35 , 0 ) ;
V_5 = F_67 ( & V_4 -> V_11 , & V_129 , V_2 ) ;
if ( V_5 ) {
F_63 ( V_123 ) ;
F_47 ( V_2 ) ;
}
return V_5 ;
}
static void F_68 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_69 ( & V_4 -> V_11 ) ;
if ( ! V_2 )
return;
F_63 ( V_4 -> V_11 . V_122 ) ;
F_47 ( V_2 ) ;
}
static void T_9 F_70 ( void )
{
F_71 ( & V_130 ) ;
F_72 () ;
F_73 () ;
}
static int T_10 F_74 ( void )
{
int V_5 ;
V_5 = F_75 () ;
if ( V_5 )
return V_5 ;
V_5 = F_76 () ;
if ( V_5 )
goto V_131;
V_5 = F_77 ( & V_130 ) ;
if ( V_5 )
goto V_132;
return 0 ;
V_132:
F_72 () ;
V_131:
F_73 () ;
return V_5 ;
}
