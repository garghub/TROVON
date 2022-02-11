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
static int T_3 F_22 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
struct V_28 * V_29 ;
V_8 -> V_29 = F_23 ( F_24 ( & V_5 -> V_10 ) , NULL ) ;
if ( F_25 ( V_8 -> V_29 ) )
return F_26 ( V_8 -> V_29 ) ;
F_27 ( L_22 , V_30 , V_8 -> V_29 , V_5 ,
& V_31 ) ;
V_29 = F_23 ( L_23 , V_8 -> V_29 ) ;
if ( F_25 ( V_29 ) )
goto V_32;
F_27 ( L_22 , V_30 , V_29 , V_5 , & V_33 ) ;
return 0 ;
V_32:
F_28 ( V_8 -> V_29 ) ;
return F_26 ( V_29 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_28 ( V_8 -> V_29 ) ;
}
void F_30 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_37 * V_38 = F_31 ( V_35 ) ;
struct V_39 * V_40 = F_32 ( V_38 ) ;
struct V_4 * V_5 = F_33 ( V_38 -> V_10 . V_11 ) ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
V_40 -> V_41 = ! ! V_36 ;
if ( V_40 -> V_41 ) {
F_3 ( V_5 -> V_10 . V_11 ) ;
F_34 ( F_35 ( 0 ) ,
V_8 -> V_9 + F_36 ( V_38 -> V_42 ) ) ;
} else {
F_34 ( F_35 ( 0 ) ,
V_8 -> V_9 + F_37 ( V_38 -> V_42 ) ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
}
}
static void F_38 ( struct V_4 * V_5 , unsigned int V_16 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
struct V_43 * V_44 = V_8 -> V_45 [ V_16 ] . V_44 ;
struct V_37 * V_38 = F_39 ( V_44 -> V_35 -> V_10 . V_11 ) ;
struct V_39 * V_40 = F_32 ( V_38 ) ;
unsigned int V_29 ;
T_4 V_46 ;
T_4 V_47 ;
F_40 ( & V_8 -> V_48 ) ;
V_47 = F_5 ( V_8 -> V_9 + V_18 ) ;
V_47 &= ~ F_41 ( V_16 ) ;
F_34 ( V_47 , V_8 -> V_9 + V_18 ) ;
if ( V_44 -> V_49 == V_50 ) {
V_29 = V_51 ;
V_47 = F_42 ( V_44 -> V_52 ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
} else {
V_29 = V_53 ;
V_47 = F_43 ( V_44 -> V_52 ) ;
}
F_44 ( & V_5 -> V_10 , V_44 -> V_54 . V_55 , V_44 -> V_54 . V_56 , V_29 ) ;
V_46 = F_8 ( V_8 -> V_15 + F_12 ( V_16 ) ) ;
V_8 -> V_45 [ V_16 ] . V_44 = NULL ;
F_45 ( & V_38 -> V_10 , L_24 ,
V_44 -> V_52 , V_44 -> V_49 ) ;
F_46 ( & V_8 -> V_48 ) ;
if ( V_46 & V_57 ) {
V_44 -> V_58 = V_59 ;
V_44 -> V_60 = 0 ;
F_40 ( & V_40 -> V_48 ) ;
F_47 ( & V_44 -> V_61 ) ;
F_46 ( & V_40 -> V_48 ) ;
V_44 -> V_62 ( V_44 ) ;
return;
}
F_40 ( & V_40 -> V_48 ) ;
V_47 |= F_5 ( V_8 -> V_9 + F_48 ( V_38 -> V_42 , 0 ) ) ;
F_34 ( V_47 , V_8 -> V_9 + F_48 ( V_38 -> V_42 , 0 ) ) ;
F_46 ( & V_40 -> V_48 ) ;
V_44 -> V_58 = V_63 ;
V_44 -> V_60 = F_49 ( V_44 -> V_54 . V_55 ) ;
}
static void F_50 ( unsigned long V_64 )
{
struct V_4 * V_5 = (struct V_4 * ) V_64 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
void T_2 * V_9 = V_8 -> V_9 ;
unsigned int V_16 ;
T_4 V_65 ;
F_3 ( V_5 -> V_10 . V_11 ) ;
V_65 = F_5 ( V_9 + V_17 ) ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
if ( V_65 & F_41 ( V_16 ) )
F_38 ( V_5 , V_16 ) ;
}
F_34 ( V_65 , V_9 + V_17 ) ;
V_65 = F_5 ( V_9 + V_17 ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
if ( V_65 )
F_51 ( & V_8 -> V_66 ) ;
else
F_52 ( V_8 -> V_67 ) ;
}
static T_5 F_53 ( int V_68 , void * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_51 ( & V_8 -> V_66 ) ;
F_54 ( V_68 ) ;
return V_69 ;
}
static unsigned long F_55 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
unsigned long V_70 = F_56 ( V_8 -> V_71 ) ;
return V_70 ;
}
static int T_3 F_57 ( struct V_72 * V_73 ,
const char * V_74 , void T_2 * * V_75 , T_6 * V_76 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
void T_2 * V_80 ;
struct V_4 * V_5 = F_58 ( V_73 ) ;
V_78 = F_59 ( V_73 , V_81 , V_74 ) ;
if ( ! V_78 ) {
F_60 ( & V_73 -> V_64 , L_25 , V_74 ) ;
return - V_82 ;
}
V_79 = F_61 ( & V_5 -> V_10 , V_78 -> V_83 ,
F_62 ( V_78 ) , F_24 ( & V_73 -> V_64 ) ) ;
if ( ! V_79 ) {
F_60 ( & V_73 -> V_64 , L_26 ,
V_78 -> V_74 ) ;
return - V_82 ;
}
V_80 = F_63 ( & V_5 -> V_10 , V_78 -> V_83 , F_62 ( V_78 ) ) ;
if ( ! V_80 ) {
F_60 ( & V_73 -> V_64 , L_27 , V_78 -> V_74 ) ;
return - V_82 ;
}
* V_75 = V_80 ;
if ( V_76 )
* V_76 = V_78 -> V_83 ;
return 0 ;
}
static int T_3 F_64 ( struct V_4 * V_5 ,
struct V_72 * V_73 )
{
struct V_7 * V_8 ;
int V_84 ;
V_8 = F_65 ( & V_5 -> V_10 , sizeof( * V_8 ) , V_85 ) ;
if ( ! V_8 ) {
F_60 ( & V_73 -> V_64 , L_28 ) ;
return - V_86 ;
}
V_5 -> V_87 = F_66 ( & V_88 , 0 , 0 , V_85 ) ;
if ( V_5 -> V_87 < 0 ) {
V_84 = V_5 -> V_87 ;
goto V_89;
}
V_5 -> V_90 = V_91 ;
V_5 -> V_10 . V_11 = & V_73 -> V_64 ;
F_67 ( & V_5 -> V_10 , L_29 , V_5 -> V_87 ) ;
F_68 ( V_5 , V_8 ) ;
V_8 -> V_64 = & V_5 -> V_10 ;
V_84 = F_57 ( V_73 , L_30 , & V_8 -> V_9 , NULL ) ;
if ( V_84 < 0 )
goto V_89;
V_84 = F_57 ( V_73 , L_23 , & V_8 -> V_15 , NULL ) ;
if ( V_84 < 0 )
goto V_89;
V_8 -> V_67 = F_69 ( V_73 , L_31 ) ;
if ( V_8 -> V_67 < 0 ) {
F_60 ( & V_73 -> V_64 , L_32 ) ;
V_84 = V_8 -> V_67 ;
goto V_89;
}
F_70 ( & V_8 -> V_66 , F_50 ,
( unsigned long ) V_5 ) ;
V_84 = F_71 ( & V_5 -> V_10 , V_8 -> V_67 , F_53 ,
0 , L_31 , V_5 ) ;
if ( V_84 < 0 ) {
F_60 ( & V_5 -> V_10 , L_33 ,
V_8 -> V_67 , V_84 ) ;
goto V_89;
}
V_8 -> V_38 = F_65 ( & V_5 -> V_10 ,
sizeof( struct V_39 * ) * V_5 -> V_92 , V_85 ) ;
if ( ! V_8 -> V_38 ) {
V_84 = - V_86 ;
goto V_89;
}
V_8 -> V_71 = F_72 ( & V_5 -> V_10 , L_34 ) ;
if ( F_25 ( V_8 -> V_71 ) ) {
F_60 ( & V_73 -> V_64 , L_35 ,
F_26 ( V_8 -> V_71 ) ) ;
V_84 = - V_93 ;
goto V_89;
}
V_8 -> V_94 = NULL ;
V_8 -> V_95 = V_96 ;
F_73 ( & V_8 -> V_48 ) ;
V_84 = F_74 ( V_5 ) ;
if ( V_84 < 0 )
goto V_89;
return 0 ;
V_89:
F_75 ( & V_88 , V_5 -> V_87 ) ;
return V_84 ;
}
static int T_3 F_76 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
unsigned int V_97 ;
T_4 V_47 ;
int V_84 ;
V_84 = F_3 ( V_5 -> V_10 . V_11 ) ;
if ( V_84 < 0 ) {
F_60 ( & V_5 -> V_10 , L_36 , V_84 ) ;
return V_84 ;
}
F_34 ( V_98 , V_8 -> V_9 + V_13 ) ;
V_47 = F_5 ( V_8 -> V_9 + V_14 ) ;
for ( V_97 = 0 ; ( ( V_97 < 20 ) && ! ( V_47 & V_99 ) ) ; V_97 ++ ) {
F_77 ( 20 ) ;
V_47 = F_5 ( V_8 -> V_9 + V_14 ) ;
}
if ( ! ( V_47 & V_99 ) ) {
F_60 ( & V_5 -> V_10 , L_37 ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
return - V_100 ;
}
F_34 ( V_101 , V_8 -> V_15 + V_102 ) ;
V_8 -> V_103 = F_78 ( F_55 ( V_5 ) , 1000 ) ;
F_45 ( & V_5 -> V_10 , L_38 , V_8 -> V_103 ) ;
V_47 = V_104 | V_105 | V_106 ;
F_34 ( V_47 , V_8 -> V_9 + V_13 ) ;
V_8 -> V_107 = V_47 ;
F_34 ( V_108 , V_8 -> V_9 + V_23 ) ;
V_8 -> V_109 = V_108 ;
F_6 ( V_5 -> V_10 . V_11 ) ;
return 0 ;
}
static void F_79 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
int V_87 = V_5 -> V_87 ;
F_80 ( & V_8 -> V_66 ) ;
F_81 ( V_5 ) ;
F_75 ( & V_88 , V_87 ) ;
}
static inline int F_82 ( const struct V_110 * V_111 )
{
struct V_110 * V_112 ;
int V_42 = 0 ;
F_83 (np, child)
if ( F_84 ( V_112 , L_39 ) )
V_42 ++ ;
return V_42 ;
}
static int F_85 ( struct V_10 * V_64 , void * V_113 )
{
struct V_72 * V_114 = F_86 ( V_64 ) ;
F_87 ( V_114 ) ;
return 0 ;
}
static int T_3 F_88 ( struct V_72 * V_73 )
{
struct V_72 * V_115 ;
struct V_110 * V_111 = V_73 -> V_64 . V_116 ;
struct V_110 * V_112 ;
struct V_4 * V_5 ;
int V_84 ;
int V_92 ;
if ( ! V_111 ) {
F_60 ( & V_73 -> V_64 , L_40 ) ;
return - V_117 ;
}
V_92 = F_82 ( V_111 ) ;
V_5 = F_89 ( V_92 , V_85 ) ;
if ( ! V_5 ) {
F_60 ( & V_73 -> V_64 , L_41 ) ;
return - V_86 ;
}
F_90 ( V_73 , V_5 ) ;
V_84 = F_64 ( V_5 , V_73 ) ;
if ( V_84 < 0 )
goto V_118;
F_91 ( & V_73 -> V_64 ) ;
F_92 ( & V_73 -> V_64 ) ;
V_84 = F_76 ( V_5 ) ;
if ( V_84 < 0 )
goto V_119;
#ifdef F_93
V_84 = F_22 ( V_5 ) ;
if ( V_84 < 0 )
goto V_119;
#endif
F_83 (np, child) {
if ( ! F_84 ( V_112 , L_39 ) )
continue;
V_115 = F_94 ( V_112 , NULL , & V_73 -> V_64 ) ;
if ( ! V_115 ) {
V_84 = - V_93 ;
F_60 ( & V_73 -> V_64 , L_42 ) ;
goto V_120;
}
}
F_95 ( & V_73 -> V_64 , L_43 ,
V_5 -> V_87 , V_92 ) ;
return V_84 ;
V_120:
F_96 ( & V_73 -> V_64 , NULL , F_85 ) ;
V_119:
F_79 ( V_5 ) ;
V_118:
F_90 ( V_73 , NULL ) ;
F_97 ( & V_73 -> V_64 ) ;
return V_84 ;
}
static int T_7 F_98 ( struct V_72 * V_73 )
{
struct V_4 * V_5 = F_58 ( V_73 ) ;
#ifdef F_93
F_29 ( V_5 ) ;
#endif
F_79 ( V_5 ) ;
F_90 ( V_73 , NULL ) ;
F_97 ( & V_73 -> V_64 ) ;
F_96 ( & V_73 -> V_64 , NULL , F_85 ) ;
return 0 ;
}
static int F_99 ( struct V_10 * V_64 )
{
struct V_4 * V_5 = F_100 ( V_64 ) ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_45 ( V_64 , L_44 ) ;
if ( V_8 -> V_94 )
V_8 -> V_121 =
V_8 -> V_94 ( V_5 -> V_10 . V_11 ) ;
return 0 ;
}
static int F_101 ( struct V_10 * V_64 )
{
struct V_4 * V_5 = F_100 ( V_64 ) ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_45 ( V_64 , L_45 ) ;
if ( ( V_8 -> V_94 ) && ( V_8 -> V_121 ==
V_8 -> V_94 ( V_5 -> V_10 . V_11 ) ) )
return 0 ;
F_34 ( V_8 -> V_109 , V_8 -> V_15 + V_23 ) ;
return 0 ;
}
