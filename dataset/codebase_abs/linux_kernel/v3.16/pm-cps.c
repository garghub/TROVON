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
V_18 = & V_27 [ V_8 ] ;
V_20 = & V_18 -> V_28 [ V_9 . V_29 ] ;
V_20 -> V_30 = ( unsigned long ) V_31 ;
V_20 -> V_32 = ( unsigned long ) F_21 () ;
V_20 -> V_33 = 0 ;
}
F_18 ( V_7 , & V_34 ) ;
F_22 () ;
V_13 = F_13 ( V_35 , V_8 ) ;
V_15 = F_23 ( F_24 ( V_13 ) ,
( unsigned long ) V_13 ) ;
V_15 += ( ( unsigned long ) V_13 & ~ V_36 ) ;
V_14 = V_15 ;
F_25 ( * V_14 ) = 0 ;
F_3 ( & F_13 ( V_37 , V_8 ) , V_5 ) ;
V_10 = V_16 ( V_5 , V_14 ) ;
F_26 () ;
F_27 ( V_7 , & V_34 ) ;
if ( V_6 && ( V_2 == V_38 ) && ( V_10 == V_5 ) )
F_28 ( V_11 ) ;
return 0 ;
}
static void T_5 F_29 ( T_3 * * V_39 , struct V_40 * * V_41 ,
struct V_42 * * V_43 ,
const struct V_44 * V_45 ,
unsigned V_46 , int V_47 )
{
unsigned V_48 = V_45 -> V_49 << V_45 -> V_50 ;
unsigned V_51 ;
const unsigned V_52 = 32 ;
if ( V_45 -> V_53 & V_54 )
return;
F_30 ( V_39 , V_55 , ( long ) V_56 ) ;
if ( V_48 < 0x8000 )
F_31 ( V_39 , V_57 , V_55 , V_48 ) ;
else
F_30 ( V_39 , V_57 , ( long ) ( V_56 + V_48 ) ) ;
F_32 ( V_41 , * V_39 , V_47 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ )
F_33 ( V_39 , V_46 , V_51 * V_45 -> V_58 , V_55 ) ;
F_31 ( V_39 , V_55 , V_55 , V_52 * V_45 -> V_58 ) ;
F_34 ( V_39 , V_43 , V_55 , V_57 , V_47 ) ;
F_35 ( V_39 ) ;
}
static int T_5 F_36 ( T_3 * * V_39 , struct V_40 * * V_41 ,
struct V_42 * * V_43 ,
const struct V_59 * V_60 ,
int V_47 )
{
unsigned V_51 , V_61 = 8 ;
unsigned V_62 = ( V_61 * 3 ) / 2 ;
unsigned V_63 = 2 ;
unsigned V_64 = V_60 -> V_65 . V_58 ;
unsigned V_66 , V_67 ;
unsigned V_68 = V_60 -> V_69 & V_70 ;
switch ( F_37 ( V_60 -> V_71 ) ) {
case V_72 :
V_66 = 1 ;
V_67 = 51 ;
break;
case V_73 :
if ( V_68 >= F_38 ( 1 , 1 , 0 ) )
return 0 ;
return - 1 ;
case V_74 :
return 0 ;
default:
F_39 ( 1 , L_1 ) ;
return - 1 ;
}
F_40 ( V_39 , V_75 , 25 , ( V_66 * 2 ) + 0 ) ;
F_40 ( V_39 , V_76 , 25 , ( V_66 * 2 ) + 1 ) ;
F_31 ( V_39 , V_55 , V_77 , ( V_67 << 5 ) | 0xf ) ;
F_41 ( V_39 , V_55 , 25 , ( V_66 * 2 ) + 0 ) ;
F_42 ( V_39 ) ;
F_41 ( V_39 , V_77 , 25 , ( V_66 * 2 ) + 1 ) ;
F_42 ( V_39 ) ;
F_30 ( V_39 , V_55 , ( long ) V_56 ) ;
F_32 ( V_41 , * V_39 , V_47 ) ;
for ( V_51 = 0 ; V_51 < V_62 ; V_51 ++ )
F_43 ( V_39 , V_77 , V_51 * V_64 * V_63 , V_55 ) ;
for ( V_51 = 0 ; V_51 < V_62 ; V_51 ++ ) {
F_33 ( V_39 , V_78 ,
V_51 * V_64 * V_63 , V_55 ) ;
F_33 ( V_39 , V_79 ,
V_51 * V_64 * V_63 , V_55 ) ;
}
F_44 ( V_39 , V_80 ) ;
F_42 ( V_39 ) ;
F_40 ( V_39 , V_57 , 25 , ( V_66 * 2 ) + 1 ) ;
F_45 ( V_39 , V_43 , V_57 , V_47 ) ;
F_35 ( V_39 ) ;
F_41 ( V_39 , V_75 , 25 , ( V_66 * 2 ) + 0 ) ;
F_42 ( V_39 ) ;
F_41 ( V_39 , V_76 , 25 , ( V_66 * 2 ) + 1 ) ;
F_42 ( V_39 ) ;
return 0 ;
}
static void T_5 F_46 ( T_3 * * V_39 , struct V_40 * * V_41 ,
struct V_42 * * V_43 ,
unsigned V_81 , int V_47 )
{
F_47 ( V_39 , V_55 , F_48 ( 0x80000000 ) ) ;
F_32 ( V_41 , * V_39 , V_47 ) ;
F_49 ( V_39 , V_57 , 0 , V_81 ) ;
F_50 ( V_39 , V_57 , V_57 , V_55 ) ;
F_51 ( V_39 , V_57 , 0 , V_81 ) ;
F_45 ( V_39 , V_43 , V_57 , V_47 ) ;
F_35 ( V_39 ) ;
}
static void * T_5 F_52 ( unsigned V_7 , enum V_1 V_2 )
{
struct V_40 * V_82 = V_83 ;
struct V_42 * V_84 = V_85 ;
T_3 * V_86 , * V_87 ;
const unsigned V_88 = V_89 ;
const unsigned V_90 = V_91 ;
const unsigned V_92 = V_93 ;
const unsigned V_94 = 256 ;
unsigned V_95 ;
int V_96 ;
enum {
V_97 = 1 ,
V_98 ,
V_99 ,
V_100 ,
V_101 ,
V_102 ,
V_103 ,
V_104 ,
V_105 ,
V_106 ,
V_107 ,
};
V_87 = V_86 = F_53 ( V_94 , sizeof( T_3 ) , V_108 ) ;
if ( ! V_86 )
return NULL ;
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
memset ( V_85 , 0 , sizeof( V_85 ) ) ;
if ( F_20 ( V_25 ) && V_2 == V_26 ) {
F_30 ( & V_87 , V_55 , ( long ) V_109 ) ;
F_54 ( & V_87 , V_110 , V_55 ) ;
F_35 ( & V_87 ) ;
}
F_30 ( & V_87 , V_92 , ( long ) F_55 () ) ;
if ( V_6 ) {
F_44 ( & V_87 , V_111 ) ;
F_32 ( & V_82 , V_87 , V_97 ) ;
F_49 ( & V_87 , V_57 , 0 , V_90 ) ;
F_31 ( & V_87 , V_75 , V_57 , 1 ) ;
F_51 ( & V_87 , V_75 , 0 , V_90 ) ;
F_45 ( & V_87 , & V_84 , V_75 , V_97 ) ;
F_31 ( & V_87 , V_57 , V_57 , 1 ) ;
F_44 ( & V_87 , V_111 ) ;
F_56 ( & V_87 , & V_84 , V_57 , V_88 , V_100 ) ;
F_35 ( & V_87 ) ;
if ( V_2 < V_26 ) {
F_31 ( & V_87 , V_57 , V_77 , - 1 ) ;
F_32 ( & V_82 , V_87 , V_98 ) ;
F_43 ( & V_87 , V_55 , 0 , V_90 ) ;
F_57 ( & V_87 , & V_84 , V_55 , V_106 ) ;
F_42 ( & V_87 ) ;
F_58 ( & V_87 , V_77 , V_57 ) ;
F_59 ( & V_87 , & V_84 , V_98 ) ;
F_35 ( & V_87 ) ;
} else {
F_31 ( & V_87 , V_55 , V_77 , V_112 ) ;
F_41 ( & V_87 , V_55 , 2 , 4 ) ;
F_32 ( & V_82 , V_87 , V_99 ) ;
F_59 ( & V_87 , & V_84 , V_99 ) ;
F_35 ( & V_87 ) ;
}
}
F_32 ( & V_82 , V_87 , V_100 ) ;
F_29 ( & V_87 , & V_82 , & V_84 , & V_113 [ V_7 ] . V_114 ,
V_115 , V_102 ) ;
F_29 ( & V_87 , & V_82 , & V_84 , & V_113 [ V_7 ] . V_65 ,
V_116 , V_103 ) ;
F_44 ( & V_87 , V_80 ) ;
F_42 ( & V_87 ) ;
F_31 ( & V_87 , V_55 , V_77 , 1 << V_113 [ V_7 ] . V_8 ) ;
F_60 ( & V_87 , V_55 , 0 , V_92 ) ;
F_43 ( & V_87 , V_55 , 0 , V_92 ) ;
F_44 ( & V_87 , V_117 ) ;
F_42 ( & V_87 ) ;
F_60 ( & V_87 , V_77 , 0 , V_92 ) ;
F_43 ( & V_87 , V_55 , 0 , V_92 ) ;
if ( V_2 >= V_118 ) {
V_96 = F_36 ( & V_87 , & V_82 , & V_84 , & V_113 [ V_7 ] ,
V_101 ) ;
if ( V_96 )
goto V_119;
switch ( V_2 ) {
case V_118 :
V_95 = V_120 ;
break;
case V_26 :
V_95 = V_121 ;
break;
default:
F_61 () ;
goto V_119;
}
F_30 ( & V_87 , V_55 , ( long ) F_62 () ) ;
F_31 ( & V_87 , V_57 , V_77 , V_95 ) ;
F_60 ( & V_87 , V_57 , 0 , V_55 ) ;
if ( V_2 == V_26 ) {
F_32 ( & V_82 , V_87 , V_104 ) ;
F_59 ( & V_87 , & V_84 , V_104 ) ;
F_35 ( & V_87 ) ;
goto V_122;
}
F_44 ( & V_87 , V_80 ) ;
F_42 ( & V_87 ) ;
}
if ( V_2 == V_38 ) {
if ( V_6 )
F_46 ( & V_87 , & V_82 , & V_84 , V_90 ,
V_105 ) ;
F_32 ( & V_82 , V_87 , V_106 ) ;
F_63 ( & V_87 , 0 ) ;
}
F_31 ( & V_87 , V_55 , V_77 , V_123 ) ;
F_60 ( & V_87 , V_55 , 0 , V_92 ) ;
F_43 ( & V_87 , V_55 , 0 , V_92 ) ;
F_44 ( & V_87 , V_80 ) ;
F_42 ( & V_87 ) ;
if ( V_6 && ( V_2 == V_38 ) ) {
F_32 ( & V_82 , V_87 , V_107 ) ;
F_44 ( & V_87 , V_111 ) ;
F_49 ( & V_87 , V_57 , 0 , V_90 ) ;
F_31 ( & V_87 , V_75 , V_57 , - 1 ) ;
F_51 ( & V_87 , V_75 , 0 , V_90 ) ;
F_45 ( & V_87 , & V_84 , V_75 , V_107 ) ;
F_64 ( & V_87 , V_110 , V_57 , ( 1 << F_65 ( V_124 ) ) - 1 ) ;
F_44 ( & V_87 , V_111 ) ;
}
if ( V_6 && ( V_2 == V_118 ) ) {
F_46 ( & V_87 , & V_82 , & V_84 , V_90 , V_105 ) ;
F_32 ( & V_82 , V_87 , V_106 ) ;
F_44 ( & V_87 , V_111 ) ;
}
F_66 ( & V_87 , V_125 ) ;
F_35 ( & V_87 ) ;
V_122:
F_67 ( ( V_87 - V_86 ) > V_94 ) ;
F_67 ( ( V_82 - V_83 ) > F_68 ( V_83 ) ) ;
F_67 ( ( V_84 - V_85 ) > F_68 ( V_85 ) ) ;
F_69 ( V_85 , V_83 ) ;
F_70 ( ( unsigned long ) V_86 , ( unsigned long ) V_87 ) ;
return V_86 ;
V_119:
F_71 ( V_86 ) ;
return NULL ;
}
static int T_5 F_72 ( unsigned V_7 )
{
enum V_1 V_2 ;
unsigned V_8 = V_113 [ V_7 ] . V_8 ;
unsigned V_126 = V_113 [ V_7 ] . V_65 . V_58 ;
void * V_127 , * V_128 ;
for ( V_2 = V_38 ; V_2 < V_129 ; V_2 ++ ) {
if ( F_13 ( V_21 , V_8 ) [ V_2 ] )
continue;
if ( ! F_2 ( V_2 , V_3 ) )
continue;
V_127 = F_52 ( V_7 , V_2 ) ;
if ( ! V_127 ) {
F_73 ( L_2 ,
V_8 , V_2 ) ;
F_74 ( V_2 , V_3 ) ;
}
F_13 ( V_21 , V_8 ) [ V_2 ] = V_127 ;
}
if ( ! F_13 ( V_35 , V_8 ) ) {
V_128 = F_75 ( V_126 * 2 , V_108 ) ;
if ( ! V_128 ) {
F_73 ( L_3 , V_8 ) ;
return - V_130 ;
}
F_13 ( V_131 , V_8 ) = V_128 ;
V_128 += V_126 - 1 ;
V_128 = ( void * ) ( ( unsigned long ) V_128 & ~ ( V_126 - 1 ) ) ;
F_13 ( V_35 , V_8 ) = V_128 ;
}
return 0 ;
}
static int T_5 F_76 ( void )
{
unsigned V_7 ;
int V_96 ;
switch ( V_9 . V_71 ) {
case V_72 :
case V_73 :
case V_132 :
case V_74 :
V_117 = 0x2 ;
V_80 = 0x3 ;
V_111 = 0x10 ;
break;
default:
F_77 ( L_4 ) ;
}
if ( ! F_78 () ) {
F_77 ( L_5 ) ;
goto V_133;
}
if ( V_134 == V_135 )
F_79 ( V_38 , V_3 ) ;
else
F_77 ( L_6 ) ;
if ( F_80 () ) {
if ( F_81 () & V_136 )
F_79 ( V_118 , V_3 ) ;
else
F_77 ( L_7 ) ;
if ( F_82 () )
F_79 ( V_26 , V_3 ) ;
else
F_77 ( L_8 ) ;
} else {
F_77 ( L_9 ) ;
}
F_83 (cpu) {
V_96 = F_72 ( V_7 ) ;
if ( V_96 )
return V_96 ;
}
V_133:
return 0 ;
}
