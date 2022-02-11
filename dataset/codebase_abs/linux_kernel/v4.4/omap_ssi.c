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
T_4 V_47 ;
T_4 V_48 ;
F_38 ( & V_8 -> V_49 ) ;
V_48 = F_5 ( V_8 -> V_9 + V_18 ) ;
V_48 &= ~ F_39 ( V_16 ) ;
F_32 ( V_48 , V_8 -> V_9 + V_18 ) ;
if ( V_45 -> V_50 == V_51 ) {
V_29 = V_52 ;
V_48 = F_40 ( V_45 -> V_53 ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
} else {
V_29 = V_54 ;
V_48 = F_41 ( V_45 -> V_53 ) ;
}
F_42 ( & V_5 -> V_10 , V_45 -> V_55 . V_56 , V_45 -> V_55 . V_57 , V_29 ) ;
V_47 = F_8 ( V_8 -> V_15 + F_12 ( V_16 ) ) ;
V_8 -> V_46 [ V_16 ] . V_45 = NULL ;
F_43 ( & V_39 -> V_10 , L_24 ,
V_45 -> V_53 , V_45 -> V_50 ) ;
F_44 ( & V_8 -> V_49 ) ;
if ( V_47 & V_58 ) {
V_45 -> V_59 = V_60 ;
V_45 -> V_61 = 0 ;
F_38 ( & V_41 -> V_49 ) ;
F_45 ( & V_45 -> V_62 ) ;
F_44 ( & V_41 -> V_49 ) ;
V_45 -> V_63 ( V_45 ) ;
return;
}
F_38 ( & V_41 -> V_49 ) ;
V_48 |= F_5 ( V_8 -> V_9 + F_46 ( V_39 -> V_43 , 0 ) ) ;
F_32 ( V_48 , V_8 -> V_9 + F_46 ( V_39 -> V_43 , 0 ) ) ;
F_44 ( & V_41 -> V_49 ) ;
V_45 -> V_59 = V_64 ;
V_45 -> V_61 = F_47 ( V_45 -> V_55 . V_56 ) ;
}
static void F_48 ( unsigned long V_65 )
{
struct V_4 * V_5 = (struct V_4 * ) V_65 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
void T_2 * V_9 = V_8 -> V_9 ;
unsigned int V_16 ;
T_4 V_66 ;
F_3 ( V_5 -> V_10 . V_11 ) ;
V_66 = F_5 ( V_9 + V_17 ) ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
if ( V_66 & F_39 ( V_16 ) )
F_36 ( V_5 , V_16 ) ;
}
F_32 ( V_66 , V_9 + V_17 ) ;
V_66 = F_5 ( V_9 + V_17 ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
if ( V_66 )
F_49 ( & V_8 -> V_67 ) ;
else
F_50 ( V_8 -> V_68 ) ;
}
static T_5 F_51 ( int V_69 , void * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_49 ( & V_8 -> V_67 ) ;
F_52 ( V_69 ) ;
return V_70 ;
}
static unsigned long F_53 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
unsigned long V_71 = F_54 ( V_8 -> V_72 ) ;
return V_71 ;
}
static int T_3 F_55 ( struct V_73 * V_74 ,
const char * V_75 , void T_2 * * V_76 , T_6 * V_77 )
{
struct V_78 * V_79 ;
void T_2 * V_80 ;
struct V_4 * V_5 = F_56 ( V_74 ) ;
V_79 = F_57 ( V_74 , V_81 , V_75 ) ;
V_80 = F_58 ( & V_5 -> V_10 , V_79 ) ;
if ( F_59 ( V_80 ) )
return F_60 ( V_80 ) ;
* V_76 = V_80 ;
if ( V_77 )
* V_77 = V_79 -> V_82 ;
return 0 ;
}
static int T_3 F_61 ( struct V_4 * V_5 ,
struct V_73 * V_74 )
{
struct V_7 * V_8 ;
int V_83 ;
V_8 = F_62 ( & V_5 -> V_10 , sizeof( * V_8 ) , V_84 ) ;
if ( ! V_8 ) {
F_63 ( & V_74 -> V_65 , L_25 ) ;
return - V_30 ;
}
V_5 -> V_85 = F_64 ( & V_86 , 0 , 0 , V_84 ) ;
if ( V_5 -> V_85 < 0 ) {
V_83 = V_5 -> V_85 ;
goto V_87;
}
V_5 -> V_88 = V_89 ;
V_5 -> V_10 . V_11 = & V_74 -> V_65 ;
F_65 ( & V_5 -> V_10 , L_26 , V_5 -> V_85 ) ;
F_66 ( V_5 , V_8 ) ;
V_8 -> V_65 = & V_5 -> V_10 ;
V_83 = F_55 ( V_74 , L_27 , & V_8 -> V_9 , NULL ) ;
if ( V_83 < 0 )
goto V_87;
V_83 = F_55 ( V_74 , L_23 , & V_8 -> V_15 , NULL ) ;
if ( V_83 < 0 )
goto V_87;
V_83 = F_67 ( V_74 , L_28 ) ;
if ( V_83 < 0 ) {
F_63 ( & V_74 -> V_65 , L_29 ) ;
goto V_87;
}
V_8 -> V_68 = V_83 ;
F_68 ( & V_8 -> V_67 , F_48 ,
( unsigned long ) V_5 ) ;
V_83 = F_69 ( & V_5 -> V_10 , V_8 -> V_68 , F_51 ,
0 , L_28 , V_5 ) ;
if ( V_83 < 0 ) {
F_63 ( & V_5 -> V_10 , L_30 ,
V_8 -> V_68 , V_83 ) ;
goto V_87;
}
V_8 -> V_39 = F_62 ( & V_5 -> V_10 ,
sizeof( struct V_40 * ) * V_5 -> V_90 , V_84 ) ;
if ( ! V_8 -> V_39 ) {
V_83 = - V_30 ;
goto V_87;
}
V_8 -> V_72 = F_70 ( & V_5 -> V_10 , L_31 ) ;
if ( F_59 ( V_8 -> V_72 ) ) {
F_63 ( & V_74 -> V_65 , L_32 ,
F_60 ( V_8 -> V_72 ) ) ;
V_83 = - V_91 ;
goto V_87;
}
V_8 -> V_92 = NULL ;
V_8 -> V_93 = V_94 ;
F_71 ( & V_8 -> V_49 ) ;
V_83 = F_72 ( V_5 ) ;
if ( V_83 < 0 )
goto V_87;
return 0 ;
V_87:
F_73 ( & V_86 , V_5 -> V_85 ) ;
return V_83 ;
}
static int T_3 F_74 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
unsigned int V_95 ;
T_4 V_48 ;
int V_83 ;
V_83 = F_3 ( V_5 -> V_10 . V_11 ) ;
if ( V_83 < 0 ) {
F_63 ( & V_5 -> V_10 , L_33 , V_83 ) ;
return V_83 ;
}
F_32 ( V_96 , V_8 -> V_9 + V_13 ) ;
V_48 = F_5 ( V_8 -> V_9 + V_14 ) ;
for ( V_95 = 0 ; ( ( V_95 < 20 ) && ! ( V_48 & V_97 ) ) ; V_95 ++ ) {
F_75 ( 20 ) ;
V_48 = F_5 ( V_8 -> V_9 + V_14 ) ;
}
if ( ! ( V_48 & V_97 ) ) {
F_63 ( & V_5 -> V_10 , L_34 ) ;
F_6 ( V_5 -> V_10 . V_11 ) ;
return - V_98 ;
}
F_32 ( V_99 , V_8 -> V_15 + V_100 ) ;
V_8 -> V_101 = F_76 ( F_53 ( V_5 ) , 1000 ) ;
F_43 ( & V_5 -> V_10 , L_35 , V_8 -> V_101 ) ;
V_48 = V_102 | V_103 | V_104 ;
F_32 ( V_48 , V_8 -> V_9 + V_13 ) ;
V_8 -> V_105 = V_48 ;
F_32 ( V_106 , V_8 -> V_9 + V_23 ) ;
V_8 -> V_107 = V_106 ;
F_6 ( V_5 -> V_10 . V_11 ) ;
return 0 ;
}
static void F_77 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
int V_85 = V_5 -> V_85 ;
F_78 ( & V_8 -> V_67 ) ;
F_79 ( V_5 ) ;
F_73 ( & V_86 , V_85 ) ;
}
static inline int F_80 ( const struct V_108 * V_109 )
{
struct V_108 * V_110 ;
int V_43 = 0 ;
F_81 (np, child)
if ( F_82 ( V_110 , L_36 ) )
V_43 ++ ;
return V_43 ;
}
static int F_83 ( struct V_10 * V_65 , void * V_111 )
{
struct V_73 * V_112 = F_84 ( V_65 ) ;
F_85 ( V_112 ) ;
return 0 ;
}
static int T_3 F_86 ( struct V_73 * V_74 )
{
struct V_73 * V_113 ;
struct V_108 * V_109 = V_74 -> V_65 . V_114 ;
struct V_108 * V_110 ;
struct V_4 * V_5 ;
int V_83 ;
int V_90 ;
if ( ! V_109 ) {
F_63 ( & V_74 -> V_65 , L_37 ) ;
return - V_115 ;
}
V_90 = F_80 ( V_109 ) ;
V_5 = F_87 ( V_90 , V_84 ) ;
if ( ! V_5 ) {
F_63 ( & V_74 -> V_65 , L_38 ) ;
return - V_30 ;
}
F_88 ( V_74 , V_5 ) ;
V_83 = F_61 ( V_5 , V_74 ) ;
if ( V_83 < 0 )
goto V_116;
F_89 ( & V_74 -> V_65 ) ;
F_90 ( & V_74 -> V_65 ) ;
V_83 = F_74 ( V_5 ) ;
if ( V_83 < 0 )
goto V_117;
#ifdef F_91
V_83 = F_22 ( V_5 ) ;
if ( V_83 < 0 )
goto V_117;
#endif
F_81 (np, child) {
if ( ! F_82 ( V_110 , L_36 ) )
continue;
V_113 = F_92 ( V_110 , NULL , & V_74 -> V_65 ) ;
if ( ! V_113 ) {
V_83 = - V_91 ;
F_63 ( & V_74 -> V_65 , L_39 ) ;
goto V_118;
}
}
F_93 ( & V_74 -> V_65 , L_40 ,
V_5 -> V_85 , V_90 ) ;
return V_83 ;
V_118:
F_94 ( & V_74 -> V_65 , NULL , F_83 ) ;
V_117:
F_77 ( V_5 ) ;
V_116:
F_88 ( V_74 , NULL ) ;
F_95 ( & V_74 -> V_65 ) ;
return V_83 ;
}
static int T_7 F_96 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = F_56 ( V_74 ) ;
#ifdef F_91
F_27 ( V_5 ) ;
#endif
F_77 ( V_5 ) ;
F_88 ( V_74 , NULL ) ;
F_95 ( & V_74 -> V_65 ) ;
F_94 ( & V_74 -> V_65 , NULL , F_83 ) ;
return 0 ;
}
static int F_97 ( struct V_10 * V_65 )
{
struct V_4 * V_5 = F_98 ( V_65 ) ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_43 ( V_65 , L_41 ) ;
if ( V_8 -> V_92 )
V_8 -> V_119 =
V_8 -> V_92 ( V_5 -> V_10 . V_11 ) ;
return 0 ;
}
static int F_99 ( struct V_10 * V_65 )
{
struct V_4 * V_5 = F_98 ( V_65 ) ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
F_43 ( V_65 , L_42 ) ;
if ( ( V_8 -> V_92 ) && ( V_8 -> V_119 ==
V_8 -> V_92 ( V_5 -> V_10 . V_11 ) ) )
return 0 ;
F_32 ( V_8 -> V_107 , V_8 -> V_15 + V_23 ) ;
return 0 ;
}
