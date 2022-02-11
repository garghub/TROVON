static int F_1 ( struct V_1 * V_2 , void * T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
void T_2 * V_9 = V_8 -> V_9 ;
F_3 ( V_5 -> V_10 . V_11 ) ;
F_4 ( V_2 , L_1 , F_5 ( V_9 + V_12 ) ) ;
F_4 ( V_2 , L_2 , F_5 ( V_9 + V_13 ) ) ;
F_4 ( V_2 , L_3 , F_5 ( V_9 + V_14 ) ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , void * T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
void T_2 * V_15 = V_8 -> V_15 ;
void T_2 * V_9 = V_8 -> V_9 ;
int V_16 ;
F_3 ( V_5 -> V_10 . V_11 ) ;
F_4 ( V_2 , L_4 ,
F_5 ( V_9 + V_17 ) ) ;
F_4 ( V_2 , L_5 ,
F_5 ( V_9 + V_18 ) ) ;
F_4 ( V_2 , L_6 ,
F_5 ( V_15 + V_19 ) ) ;
F_4 ( V_2 , L_7 ,
F_5 ( V_15 + V_20 ) ) ;
F_4 ( V_2 , L_8 ,
F_5 ( V_15 + V_21 ) ) ;
F_4 ( V_2 , L_9 ,
F_5 ( V_15 + V_22 ) ) ;
F_4 ( V_2 , L_10 ,
F_5 ( V_15 + V_23 ) ) ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
F_4 ( V_2 , L_11 , V_16 ) ;
F_4 ( V_2 , L_12 ,
F_8 ( V_15 + F_9 ( V_16 ) ) ) ;
F_4 ( V_2 , L_13 ,
F_8 ( V_15 + F_10 ( V_16 ) ) ) ;
F_4 ( V_2 , L_14 ,
F_8 ( V_15 + F_11 ( V_16 ) ) ) ;
F_4 ( V_2 , L_15 ,
F_8 ( V_15 + F_12 ( V_16 ) ) ) ;
F_4 ( V_2 , L_16 ,
F_5 ( V_15 + F_13 ( V_16 ) ) ) ;
F_4 ( V_2 , L_17 ,
F_5 ( V_15 + F_14 ( V_16 ) ) ) ;
F_4 ( V_2 , L_18 ,
F_8 ( V_15 + F_15 ( V_16 ) ) ) ;
F_4 ( V_2 , L_19 ,
F_8 ( V_15 + F_16 ( V_16 ) ) ) ;
F_4 ( V_2 , L_20 ,
F_8 ( V_15 + F_17 ( V_16 ) ) ) ;
F_4 ( V_2 , L_21 ,
F_8 ( V_15 + F_18 ( V_16 ) ) ) ;
}
F_6 ( V_5 -> V_10 . V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
return F_20 ( V_26 , F_1 , V_25 -> V_27 ) ;
}
static int F_21 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
return F_20 ( V_26 , F_7 , V_25 -> V_27 ) ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
struct V_28 * V_29 ;
V_8 -> V_29 = F_23 ( F_24 ( & V_5 -> V_10 ) , NULL ) ;
if ( ! V_8 -> V_29 )
return - V_30 ;
F_25 ( L_22 , V_31 , V_8 -> V_29 , V_5 ,
& V_32 ) ;
V_29 = F_23 ( L_23 , V_8 -> V_29 ) ;
if ( ! V_29 )
goto V_33;
F_25 ( L_22 , V_31 , V_29 , V_5 , & V_34 ) ;
return 0 ;
V_33:
F_26 ( V_8 -> V_29 ) ;
return - V_30 ;
}
static void F_27 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_26 ( V_8 -> V_29 ) ;
}
void F_28 ( struct V_35 * V_36 , unsigned int V_37 )
{
struct V_38 * V_39 = F_29 ( V_36 ) ;
struct V_40 * V_41 = F_30 ( V_39 ) ;
struct V_4 * V_5 = F_31 ( V_39 -> V_10 . V_11 ) ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
V_41 -> V_42 = ! ! V_37 ;
if ( V_41 -> V_42 ) {
F_3 ( V_5 -> V_10 . V_11 ) ;
F_32 ( F_33 ( 0 ) ,
V_8 -> V_9 + F_34 ( V_39 -> V_43 ) ) ;
} else {
F_32 ( F_33 ( 0 ) ,
V_8 -> V_9 + F_35 ( V_39 -> V_43 ) ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
}
}
static void F_36 ( struct V_4 * V_5 , unsigned int V_16 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
struct V_44 * V_45 = V_8 -> V_46 [ V_16 ] . V_45 ;
struct V_38 * V_39 = F_37 ( V_45 -> V_36 -> V_10 . V_11 ) ;
struct V_40 * V_41 = F_30 ( V_39 ) ;
unsigned int V_29 ;
T_3 V_47 ;
T_3 V_48 ;
F_38 ( & V_8 -> V_49 ) ;
V_48 = F_5 ( V_8 -> V_9 + V_18 ) ;
V_48 &= ~ F_39 ( V_16 ) ;
F_32 ( V_48 , V_8 -> V_9 + V_18 ) ;
if ( V_45 -> V_50 == V_51 ) {
V_29 = V_52 ;
V_48 = F_40 ( V_45 -> V_53 ) ;
F_6 ( V_41 -> V_54 ) ;
} else {
V_29 = V_55 ;
V_48 = F_41 ( V_45 -> V_53 ) ;
}
F_42 ( & V_5 -> V_10 , V_45 -> V_56 . V_57 , V_45 -> V_56 . V_58 , V_29 ) ;
V_47 = F_8 ( V_8 -> V_15 + F_12 ( V_16 ) ) ;
V_8 -> V_46 [ V_16 ] . V_45 = NULL ;
F_43 ( & V_39 -> V_10 , L_24 ,
V_45 -> V_53 , V_45 -> V_50 ) ;
F_44 ( & V_8 -> V_49 ) ;
if ( V_47 & V_59 ) {
V_45 -> V_60 = V_61 ;
V_45 -> V_62 = 0 ;
F_38 ( & V_41 -> V_49 ) ;
F_45 ( & V_45 -> V_63 ) ;
F_44 ( & V_41 -> V_49 ) ;
F_46 ( & V_45 -> V_63 , & V_41 -> V_64 ) ;
F_47 ( & V_41 -> V_65 , 0 ) ;
return;
}
F_38 ( & V_41 -> V_49 ) ;
V_48 |= F_5 ( V_8 -> V_9 + F_48 ( V_39 -> V_43 , 0 ) ) ;
F_32 ( V_48 , V_8 -> V_9 + F_48 ( V_39 -> V_43 , 0 ) ) ;
F_44 ( & V_41 -> V_49 ) ;
V_45 -> V_60 = V_66 ;
V_45 -> V_62 = F_49 ( V_45 -> V_56 . V_57 ) ;
}
static void F_50 ( unsigned long V_67 )
{
struct V_4 * V_5 = (struct V_4 * ) V_67 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
void T_2 * V_9 = V_8 -> V_9 ;
unsigned int V_16 ;
T_3 V_68 ;
F_51 ( V_5 -> V_10 . V_11 ) ;
if ( ! F_52 ( V_5 -> V_10 . V_11 ) ) {
F_53 ( V_5 -> V_10 . V_11 , L_25 ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
return;
}
V_68 = F_5 ( V_9 + V_17 ) ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
if ( V_68 & F_39 ( V_16 ) )
F_36 ( V_5 , V_16 ) ;
}
F_32 ( V_68 , V_9 + V_17 ) ;
V_68 = F_5 ( V_9 + V_17 ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
if ( V_68 )
F_54 ( & V_8 -> V_69 ) ;
else
F_55 ( V_8 -> V_70 ) ;
}
static T_4 F_56 ( int V_71 , void * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_54 ( & V_8 -> V_69 ) ;
F_57 ( V_71 ) ;
return V_72 ;
}
static unsigned long F_58 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
unsigned long V_73 = F_59 ( V_8 -> V_74 ) ;
return V_73 ;
}
static int F_60 ( struct V_75 * V_76 , unsigned long V_77 ,
void * V_78 )
{
struct V_7 * V_8 = F_61 ( V_76 ,
struct V_7 , V_79 ) ;
struct V_4 * V_5 = F_31 ( V_8 -> V_67 ) ;
struct V_80 * V_81 = V_78 ;
struct V_40 * V_41 ;
int V_82 ;
switch ( V_77 ) {
case V_83 :
F_43 ( & V_5 -> V_10 , L_26 ) ;
for ( V_82 = 0 ; V_82 < V_5 -> V_84 ; V_82 ++ ) {
V_41 = V_8 -> V_39 [ V_82 ] ;
if ( ! V_41 )
continue;
F_62 ( V_41 -> V_85 ) ;
F_63 ( V_41 -> V_54 ) ;
F_64 ( 1 ) ;
}
break;
case V_86 :
F_43 ( & V_5 -> V_10 , L_27 ) ;
case V_87 :
F_43 ( & V_5 -> V_10 , L_28 ,
V_81 -> V_88 , V_81 -> V_89 ) ;
V_8 -> V_90 = F_65 ( V_81 -> V_89 , 1000 ) ;
for ( V_82 = 0 ; V_82 < V_5 -> V_84 ; V_82 ++ ) {
V_41 = V_8 -> V_39 [ V_82 ] ;
if ( ! V_41 )
continue;
F_66 ( V_5 , V_41 ) ;
F_67 ( V_41 -> V_54 ) ;
F_55 ( V_41 -> V_85 ) ;
}
break;
default:
break;
}
return V_91 ;
}
static int F_68 ( struct V_92 * V_93 ,
const char * V_94 , void T_2 * * V_95 , T_5 * V_96 )
{
struct V_97 * V_98 ;
void T_2 * V_99 ;
struct V_4 * V_5 = F_69 ( V_93 ) ;
V_98 = F_70 ( V_93 , V_100 , V_94 ) ;
V_99 = F_71 ( & V_5 -> V_10 , V_98 ) ;
if ( F_72 ( V_99 ) )
return F_73 ( V_99 ) ;
* V_95 = V_99 ;
if ( V_96 )
* V_96 = V_98 -> V_101 ;
return 0 ;
}
static int F_74 ( struct V_4 * V_5 ,
struct V_92 * V_93 )
{
struct V_7 * V_8 ;
int V_102 ;
V_8 = F_75 ( & V_5 -> V_10 , sizeof( * V_8 ) , V_103 ) ;
if ( ! V_8 ) {
F_76 ( & V_93 -> V_67 , L_29 ) ;
return - V_30 ;
}
V_102 = F_77 ( & V_104 , 0 , 0 , V_103 ) ;
if ( V_102 < 0 )
goto V_105;
V_5 -> V_106 = V_102 ;
V_5 -> V_107 = V_108 ;
V_5 -> V_10 . V_11 = & V_93 -> V_67 ;
F_78 ( & V_5 -> V_10 , L_30 , V_5 -> V_106 ) ;
F_79 ( V_5 , V_8 ) ;
V_8 -> V_67 = & V_5 -> V_10 ;
V_102 = F_68 ( V_93 , L_31 , & V_8 -> V_9 , NULL ) ;
if ( V_102 < 0 )
goto V_105;
V_102 = F_68 ( V_93 , L_23 , & V_8 -> V_15 , NULL ) ;
if ( V_102 < 0 )
goto V_105;
V_102 = F_80 ( V_93 , L_32 ) ;
if ( V_102 < 0 ) {
F_76 ( & V_93 -> V_67 , L_33 ) ;
goto V_105;
}
V_8 -> V_70 = V_102 ;
F_81 ( & V_8 -> V_69 , F_50 ,
( unsigned long ) V_5 ) ;
V_102 = F_82 ( & V_5 -> V_10 , V_8 -> V_70 , F_56 ,
0 , L_32 , V_5 ) ;
if ( V_102 < 0 ) {
F_76 ( & V_5 -> V_10 , L_34 ,
V_8 -> V_70 , V_102 ) ;
goto V_105;
}
V_8 -> V_39 = F_75 ( & V_5 -> V_10 ,
sizeof( struct V_40 * ) * V_5 -> V_84 , V_103 ) ;
if ( ! V_8 -> V_39 ) {
V_102 = - V_30 ;
goto V_105;
}
V_8 -> V_74 = F_83 ( & V_5 -> V_10 , L_35 ) ;
if ( F_72 ( V_8 -> V_74 ) ) {
F_76 ( & V_93 -> V_67 , L_36 ,
F_73 ( V_8 -> V_74 ) ) ;
V_102 = - V_109 ;
goto V_105;
}
V_8 -> V_79 . V_110 = F_60 ;
V_8 -> V_79 . V_111 = V_112 ;
F_84 ( V_8 -> V_74 , & V_8 -> V_79 ) ;
V_8 -> V_113 = NULL ;
V_8 -> V_114 = V_115 ;
F_85 ( & V_8 -> V_49 ) ;
V_102 = F_86 ( V_5 ) ;
if ( V_102 < 0 )
goto V_105;
return 0 ;
V_105:
F_87 ( & V_104 , V_5 -> V_106 ) ;
return V_102 ;
}
static int F_88 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
int V_102 ;
V_102 = F_3 ( V_5 -> V_10 . V_11 ) ;
if ( V_102 < 0 ) {
F_76 ( & V_5 -> V_10 , L_37 , V_102 ) ;
return V_102 ;
}
F_32 ( V_116 , V_8 -> V_15 + V_117 ) ;
V_8 -> V_90 = F_65 ( F_58 ( V_5 ) , 1000 ) ;
F_43 ( & V_5 -> V_10 , L_38 , V_8 -> V_90 ) ;
F_32 ( V_118 , V_8 -> V_9 + V_23 ) ;
V_8 -> V_119 = V_118 ;
F_89 ( V_5 -> V_10 . V_11 ) ;
return 0 ;
}
static void F_90 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
int V_106 = V_5 -> V_106 ;
F_91 ( & V_8 -> V_69 ) ;
F_92 ( V_5 ) ;
F_93 ( V_8 -> V_74 , & V_8 -> V_79 ) ;
F_87 ( & V_104 , V_106 ) ;
}
static inline int F_94 ( const struct V_120 * V_121 )
{
struct V_120 * V_122 ;
int V_43 = 0 ;
F_95 (np, child)
if ( F_96 ( V_122 , L_39 ) )
V_43 ++ ;
return V_43 ;
}
static int F_97 ( struct V_10 * V_67 , void * V_123 )
{
struct V_92 * V_54 = F_98 ( V_67 ) ;
if ( ! V_67 -> V_124 )
return 0 ;
F_99 ( V_67 -> V_124 , V_125 ) ;
F_100 ( V_54 ) ;
return 0 ;
}
static int F_101 ( struct V_92 * V_93 )
{
struct V_92 * V_126 ;
struct V_120 * V_121 = V_93 -> V_67 . V_124 ;
struct V_120 * V_122 ;
struct V_4 * V_5 ;
int V_102 ;
int V_84 ;
if ( ! V_121 ) {
F_76 ( & V_93 -> V_67 , L_40 ) ;
return - V_127 ;
}
V_84 = F_94 ( V_121 ) ;
V_5 = F_102 ( V_84 , V_103 ) ;
if ( ! V_5 ) {
F_76 ( & V_93 -> V_67 , L_41 ) ;
return - V_30 ;
}
F_103 ( V_93 , V_5 ) ;
V_102 = F_74 ( V_5 , V_93 ) ;
if ( V_102 < 0 )
goto V_128;
F_104 ( & V_93 -> V_67 ) ;
V_102 = F_88 ( V_5 ) ;
if ( V_102 < 0 )
goto V_129;
#ifdef F_105
V_102 = F_22 ( V_5 ) ;
if ( V_102 < 0 )
goto V_129;
#endif
F_95 (np, child) {
if ( ! F_96 ( V_122 , L_39 ) )
continue;
V_126 = F_106 ( V_122 , NULL , & V_93 -> V_67 ) ;
if ( ! V_126 ) {
V_102 = - V_109 ;
F_76 ( & V_93 -> V_67 , L_42 ) ;
goto V_130;
}
}
F_107 ( & V_93 -> V_67 , L_43 ,
V_5 -> V_106 , V_84 ) ;
return V_102 ;
V_130:
F_108 ( & V_93 -> V_67 , NULL , F_97 ) ;
V_129:
F_90 ( V_5 ) ;
V_128:
F_103 ( V_93 , NULL ) ;
F_109 ( & V_93 -> V_67 ) ;
return V_102 ;
}
static int F_110 ( struct V_92 * V_93 )
{
struct V_4 * V_5 = F_69 ( V_93 ) ;
F_108 ( & V_93 -> V_67 , NULL , F_97 ) ;
#ifdef F_105
F_27 ( V_5 ) ;
#endif
F_90 ( V_5 ) ;
F_103 ( V_93 , NULL ) ;
F_109 ( & V_93 -> V_67 ) ;
return 0 ;
}
static int F_111 ( struct V_10 * V_67 )
{
struct V_4 * V_5 = F_112 ( V_67 ) ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_43 ( V_67 , L_44 ) ;
if ( V_8 -> V_113 )
V_8 -> V_131 =
V_8 -> V_113 ( V_5 -> V_10 . V_11 ) ;
return 0 ;
}
static int F_113 ( struct V_10 * V_67 )
{
struct V_4 * V_5 = F_112 ( V_67 ) ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_43 ( V_67 , L_45 ) ;
if ( ( V_8 -> V_113 ) && ( V_8 -> V_131 ==
V_8 -> V_113 ( V_5 -> V_10 . V_11 ) ) )
return 0 ;
F_32 ( V_8 -> V_119 , V_8 -> V_15 + V_23 ) ;
return 0 ;
}
static int T_6 F_114 ( void ) {
int V_132 ;
V_132 = F_115 ( & V_133 ) ;
if ( V_132 )
return V_132 ;
return F_115 ( & V_134 ) ;
}
static void T_7 F_116 ( void ) {
F_117 ( & V_134 ) ;
F_117 ( & V_133 ) ;
}
