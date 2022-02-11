bool F_1 ( enum V_1 V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( T_1 * V_4 , unsigned V_5 )
{
if ( ! V_6 )
return;
F_4 () ;
F_5 ( V_4 ) ;
while ( F_6 ( V_4 ) < V_5 )
F_7 () ;
if ( F_8 ( V_4 ) == V_5 * 2 ) {
F_9 ( V_4 , 0 ) ;
return;
}
while ( F_6 ( V_4 ) > V_5 )
F_7 () ;
}
int F_10 ( enum V_1 V_2 )
{
unsigned V_7 = F_11 () ;
unsigned V_8 = V_9 . V_8 ;
unsigned V_5 , V_10 ;
T_2 * V_11 = F_12 ( & V_12 ) ;
T_3 * V_13 , * V_14 ;
void * V_15 ;
T_4 V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
V_16 = F_13 ( V_21 , V_8 ) [ V_2 ] ;
if ( ! V_16 )
return - V_22 ;
#ifdef F_14
if ( F_15 ( V_7 ) ) {
F_16 ( V_11 , V_23 ,
& V_24 [ V_7 ] ) ;
V_5 = F_17 ( V_11 ) ;
F_18 ( V_7 , V_11 ) ;
} else
#endif
{
F_19 ( V_11 ) ;
V_5 = 1 ;
}
if ( F_20 ( V_25 ) && V_2 == V_26 ) {
if ( ! F_21 () )
return - V_22 ;
V_18 = & V_27 [ V_8 ] ;
V_20 = & V_18 -> V_28 [ F_22 ( & V_9 ) ] ;
V_20 -> V_29 = ( unsigned long ) V_30 ;
V_20 -> V_31 = ( unsigned long ) F_23 () ;
V_20 -> V_32 = 0 ;
}
F_18 ( V_7 , & V_33 ) ;
F_24 () ;
V_13 = F_13 ( V_34 , V_8 ) ;
V_15 = F_25 ( F_26 ( V_13 ) ,
( unsigned long ) V_13 ) ;
V_15 += ( ( unsigned long ) V_13 & ~ V_35 ) ;
V_14 = V_15 ;
F_27 ( * V_14 ) = 0 ;
F_3 ( & F_13 ( V_36 , V_8 ) , V_5 ) ;
V_10 = V_16 ( V_5 , V_14 ) ;
F_28 () ;
F_29 ( V_7 , & V_33 ) ;
if ( V_6 && ( V_2 == V_37 ) && ( V_10 == V_5 ) )
F_30 ( V_11 ) ;
return 0 ;
}
static void T_5 F_31 ( T_3 * * V_38 , struct V_39 * * V_40 ,
struct V_41 * * V_42 ,
const struct V_43 * V_44 ,
unsigned V_45 , int V_46 )
{
unsigned V_47 = V_44 -> V_48 << V_44 -> V_49 ;
unsigned V_50 ;
const unsigned V_51 = 32 ;
if ( V_44 -> V_52 & V_53 )
return;
F_32 ( V_38 , V_54 , ( long ) V_55 ) ;
if ( V_47 < 0x8000 )
F_33 ( V_38 , V_56 , V_54 , V_47 ) ;
else
F_32 ( V_38 , V_56 , ( long ) ( V_55 + V_47 ) ) ;
F_34 ( V_40 , * V_38 , V_46 ) ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ )
F_35 ( V_38 , V_45 , V_50 * V_44 -> V_57 , V_54 ) ;
F_33 ( V_38 , V_54 , V_54 , V_51 * V_44 -> V_57 ) ;
F_36 ( V_38 , V_42 , V_54 , V_56 , V_46 ) ;
F_37 ( V_38 ) ;
}
static int T_5 F_38 ( T_3 * * V_38 , struct V_39 * * V_40 ,
struct V_41 * * V_42 ,
const struct V_58 * V_59 ,
int V_46 )
{
unsigned V_50 , V_60 = 8 ;
unsigned V_61 = ( V_60 * 3 ) / 2 ;
unsigned V_62 = 2 ;
unsigned V_63 = V_59 -> V_64 . V_57 ;
unsigned V_65 , V_66 ;
unsigned V_67 = V_59 -> V_68 & V_69 ;
switch ( F_39 ( V_59 -> V_70 ) ) {
case V_71 :
V_65 = 1 ;
V_66 = 51 ;
break;
case V_72 :
if ( V_67 >= F_40 ( 1 , 1 , 0 ) )
return 0 ;
return - 1 ;
case V_73 :
return 0 ;
default:
F_41 ( 1 , L_1 ) ;
return - 1 ;
}
F_42 ( V_38 , V_74 , 25 , ( V_65 * 2 ) + 0 ) ;
F_42 ( V_38 , V_75 , 25 , ( V_65 * 2 ) + 1 ) ;
F_33 ( V_38 , V_54 , V_76 , ( V_66 << 5 ) | 0xf ) ;
F_43 ( V_38 , V_54 , 25 , ( V_65 * 2 ) + 0 ) ;
F_44 ( V_38 ) ;
F_43 ( V_38 , V_76 , 25 , ( V_65 * 2 ) + 1 ) ;
F_44 ( V_38 ) ;
F_32 ( V_38 , V_54 , ( long ) V_55 ) ;
F_34 ( V_40 , * V_38 , V_46 ) ;
for ( V_50 = 0 ; V_50 < V_61 ; V_50 ++ )
F_45 ( V_38 , V_76 , V_50 * V_63 * V_62 , V_54 ) ;
for ( V_50 = 0 ; V_50 < V_61 ; V_50 ++ ) {
F_35 ( V_38 , V_77 ,
V_50 * V_63 * V_62 , V_54 ) ;
F_35 ( V_38 , V_78 ,
V_50 * V_63 * V_62 , V_54 ) ;
}
F_46 ( V_38 , V_79 ) ;
F_44 ( V_38 ) ;
F_42 ( V_38 , V_56 , 25 , ( V_65 * 2 ) + 1 ) ;
F_47 ( V_38 , V_42 , V_56 , V_46 ) ;
F_37 ( V_38 ) ;
F_43 ( V_38 , V_74 , 25 , ( V_65 * 2 ) + 0 ) ;
F_44 ( V_38 ) ;
F_43 ( V_38 , V_75 , 25 , ( V_65 * 2 ) + 1 ) ;
F_44 ( V_38 ) ;
return 0 ;
}
static void T_5 F_48 ( T_3 * * V_38 , struct V_39 * * V_40 ,
struct V_41 * * V_42 ,
unsigned V_80 , int V_46 )
{
F_49 ( V_38 , V_54 , F_50 ( 0x80000000 ) ) ;
F_34 ( V_40 , * V_38 , V_46 ) ;
F_51 ( V_38 , V_56 , 0 , V_80 ) ;
F_52 ( V_38 , V_56 , V_56 , V_54 ) ;
F_53 ( V_38 , V_56 , 0 , V_80 ) ;
F_47 ( V_38 , V_42 , V_56 , V_46 ) ;
F_37 ( V_38 ) ;
}
static void * T_5 F_54 ( unsigned V_7 , enum V_1 V_2 )
{
struct V_39 * V_81 = V_82 ;
struct V_41 * V_83 = V_84 ;
T_3 * V_85 , * V_86 ;
const unsigned V_87 = V_88 ;
const unsigned V_89 = V_90 ;
const unsigned V_91 = V_92 ;
const unsigned V_93 = 256 ;
unsigned V_94 ;
int V_95 ;
enum {
V_96 = 1 ,
V_97 ,
V_98 ,
V_99 ,
V_100 ,
V_101 ,
V_102 ,
V_103 ,
V_104 ,
V_105 ,
V_106 ,
};
V_86 = V_85 = F_55 ( V_93 , sizeof( T_3 ) , V_107 ) ;
if ( ! V_85 )
return NULL ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
memset ( V_84 , 0 , sizeof( V_84 ) ) ;
if ( F_20 ( V_25 ) && V_2 == V_26 ) {
if ( ! F_21 () )
goto V_108;
F_32 ( & V_86 , V_54 , ( long ) V_109 ) ;
F_56 ( & V_86 , V_110 , V_54 ) ;
F_37 ( & V_86 ) ;
}
F_32 ( & V_86 , V_91 , ( long ) F_57 () ) ;
if ( V_6 ) {
F_46 ( & V_86 , V_111 ) ;
F_34 ( & V_81 , V_86 , V_96 ) ;
F_51 ( & V_86 , V_56 , 0 , V_89 ) ;
F_33 ( & V_86 , V_74 , V_56 , 1 ) ;
F_53 ( & V_86 , V_74 , 0 , V_89 ) ;
F_47 ( & V_86 , & V_83 , V_74 , V_96 ) ;
F_33 ( & V_86 , V_56 , V_56 , 1 ) ;
F_46 ( & V_86 , V_111 ) ;
F_58 ( & V_86 , & V_83 , V_56 , V_87 , V_99 ) ;
F_37 ( & V_86 ) ;
if ( V_2 < V_26 ) {
F_33 ( & V_86 , V_56 , V_76 , - 1 ) ;
F_34 ( & V_81 , V_86 , V_97 ) ;
F_45 ( & V_86 , V_54 , 0 , V_89 ) ;
F_59 ( & V_86 , & V_83 , V_54 , V_105 ) ;
F_44 ( & V_86 ) ;
F_60 ( & V_86 , V_76 , V_56 ) ;
F_61 ( & V_86 , & V_83 , V_97 ) ;
F_37 ( & V_86 ) ;
} else {
F_33 ( & V_86 , V_54 , V_76 , V_112 ) ;
F_43 ( & V_86 , V_54 , 2 , 4 ) ;
F_34 ( & V_81 , V_86 , V_98 ) ;
F_61 ( & V_86 , & V_83 , V_98 ) ;
F_37 ( & V_86 ) ;
}
}
F_34 ( & V_81 , V_86 , V_99 ) ;
F_31 ( & V_86 , & V_81 , & V_83 , & V_113 [ V_7 ] . V_114 ,
V_115 , V_101 ) ;
F_31 ( & V_86 , & V_81 , & V_83 , & V_113 [ V_7 ] . V_64 ,
V_116 , V_102 ) ;
F_46 ( & V_86 , V_79 ) ;
F_44 ( & V_86 ) ;
F_33 ( & V_86 , V_54 , V_76 , 1 << V_113 [ V_7 ] . V_8 ) ;
F_62 ( & V_86 , V_54 , 0 , V_91 ) ;
F_45 ( & V_86 , V_54 , 0 , V_91 ) ;
F_46 ( & V_86 , V_117 ) ;
F_44 ( & V_86 ) ;
F_62 ( & V_86 , V_76 , 0 , V_91 ) ;
F_45 ( & V_86 , V_54 , 0 , V_91 ) ;
if ( V_2 >= V_118 ) {
V_95 = F_38 ( & V_86 , & V_81 , & V_83 , & V_113 [ V_7 ] ,
V_100 ) ;
if ( V_95 )
goto V_108;
switch ( V_2 ) {
case V_118 :
V_94 = V_119 ;
break;
case V_26 :
V_94 = V_120 ;
break;
default:
F_63 () ;
goto V_108;
}
F_32 ( & V_86 , V_54 , ( long ) F_64 () ) ;
F_33 ( & V_86 , V_56 , V_76 , V_94 ) ;
F_62 ( & V_86 , V_56 , 0 , V_54 ) ;
if ( V_2 == V_26 ) {
F_34 ( & V_81 , V_86 , V_103 ) ;
F_61 ( & V_86 , & V_83 , V_103 ) ;
F_37 ( & V_86 ) ;
goto V_121;
}
F_46 ( & V_86 , V_79 ) ;
F_44 ( & V_86 ) ;
}
if ( V_2 == V_37 ) {
if ( V_6 )
F_48 ( & V_86 , & V_81 , & V_83 , V_89 ,
V_104 ) ;
F_34 ( & V_81 , V_86 , V_105 ) ;
F_65 ( & V_86 , 0 ) ;
}
F_33 ( & V_86 , V_54 , V_76 , V_122 ) ;
F_62 ( & V_86 , V_54 , 0 , V_91 ) ;
F_45 ( & V_86 , V_54 , 0 , V_91 ) ;
F_46 ( & V_86 , V_79 ) ;
F_44 ( & V_86 ) ;
if ( V_6 && ( V_2 == V_37 ) ) {
F_34 ( & V_81 , V_86 , V_106 ) ;
F_46 ( & V_86 , V_111 ) ;
F_51 ( & V_86 , V_56 , 0 , V_89 ) ;
F_33 ( & V_86 , V_74 , V_56 , - 1 ) ;
F_53 ( & V_86 , V_74 , 0 , V_89 ) ;
F_47 ( & V_86 , & V_83 , V_74 , V_106 ) ;
F_66 ( & V_86 , V_110 , V_56 , ( 1 << F_67 ( V_123 ) ) - 1 ) ;
F_46 ( & V_86 , V_111 ) ;
}
if ( V_6 && ( V_2 == V_118 ) ) {
F_48 ( & V_86 , & V_81 , & V_83 , V_89 , V_104 ) ;
F_34 ( & V_81 , V_86 , V_105 ) ;
F_46 ( & V_86 , V_111 ) ;
}
F_68 ( & V_86 , V_124 ) ;
F_37 ( & V_86 ) ;
V_121:
F_69 ( ( V_86 - V_85 ) > V_93 ) ;
F_69 ( ( V_81 - V_82 ) > F_70 ( V_82 ) ) ;
F_69 ( ( V_83 - V_84 ) > F_70 ( V_84 ) ) ;
F_71 ( V_84 , V_82 ) ;
F_72 ( ( unsigned long ) V_85 , ( unsigned long ) V_86 ) ;
return V_85 ;
V_108:
F_73 ( V_85 ) ;
return NULL ;
}
static int T_5 F_74 ( unsigned V_7 )
{
enum V_1 V_2 ;
unsigned V_8 = V_113 [ V_7 ] . V_8 ;
unsigned V_125 = V_113 [ V_7 ] . V_64 . V_57 ;
void * V_126 , * V_127 ;
for ( V_2 = V_37 ; V_2 < V_128 ; V_2 ++ ) {
if ( F_13 ( V_21 , V_8 ) [ V_2 ] )
continue;
if ( ! F_2 ( V_2 , V_3 ) )
continue;
V_126 = F_54 ( V_7 , V_2 ) ;
if ( ! V_126 ) {
F_75 ( L_2 ,
V_8 , V_2 ) ;
F_76 ( V_2 , V_3 ) ;
}
F_13 ( V_21 , V_8 ) [ V_2 ] = V_126 ;
}
if ( ! F_13 ( V_34 , V_8 ) ) {
V_127 = F_77 ( V_125 * 2 , V_107 ) ;
if ( ! V_127 ) {
F_75 ( L_3 , V_8 ) ;
return - V_129 ;
}
F_13 ( V_130 , V_8 ) = V_127 ;
V_127 += V_125 - 1 ;
V_127 = ( void * ) ( ( unsigned long ) V_127 & ~ ( V_125 - 1 ) ) ;
F_13 ( V_34 , V_8 ) = V_127 ;
}
return 0 ;
}
static int T_5 F_78 ( void )
{
unsigned V_7 ;
int V_95 ;
switch ( V_9 . V_70 ) {
case V_71 :
case V_72 :
case V_131 :
case V_73 :
V_117 = 0x2 ;
V_79 = 0x3 ;
V_111 = 0x10 ;
break;
default:
F_79 ( L_4 ) ;
}
if ( ! F_80 () ) {
F_79 ( L_5 ) ;
goto V_132;
}
if ( V_133 == V_134 )
F_81 ( V_37 , V_3 ) ;
else
F_79 ( L_6 ) ;
if ( F_82 () ) {
if ( F_83 () & V_135 )
F_81 ( V_118 , V_3 ) ;
else
F_79 ( L_7 ) ;
if ( F_21 () )
F_81 ( V_26 , V_3 ) ;
else
F_79 ( L_8 ) ;
} else {
F_79 ( L_9 ) ;
}
F_84 (cpu) {
V_95 = F_74 ( V_7 ) ;
if ( V_95 )
return V_95 ;
}
V_132:
return 0 ;
}
