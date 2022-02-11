static inline int F_1 ( struct V_1 * V_2 )
{
return V_3 - F_2 ( V_2 ) - 1 ;
}
static void F_3 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_1 V_10 ;
T_2 V_11 ;
V_10 = F_4 ( V_6 -> V_12 , 1000000000 , & V_11 ) ;
F_5 ( & V_4 -> V_13 , V_9 ) ;
V_8 = & V_4 -> V_14 [ V_4 -> V_15 ] ;
V_8 -> V_16 = V_6 -> V_16 ;
V_8 -> V_17 . V_18 = V_10 ;
V_8 -> V_17 . V_19 = V_11 ;
if ( ! F_1 ( V_4 ) )
V_4 -> V_20 = ( V_4 -> V_20 + 1 ) % V_3 ;
V_4 -> V_15 = ( V_4 -> V_15 + 1 ) % V_3 ;
F_6 ( & V_4 -> V_13 , V_9 ) ;
}
static T_3 F_7 ( long V_21 )
{
T_1 V_22 = 1 + V_21 ;
V_22 *= 125 ;
V_22 >>= 13 ;
return ( T_3 ) V_22 ;
}
static int F_8 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
V_26 -> V_27 = 0 ;
V_26 -> V_28 = 1 ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 , const struct V_25 * V_26 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
return V_30 -> V_31 -> V_32 ( V_30 -> V_31 , V_26 ) ;
}
static int F_11 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
int V_33 ;
V_33 = V_30 -> V_31 -> V_34 ( V_30 -> V_31 , V_26 ) ;
return V_33 ;
}
static int F_12 ( struct V_23 * V_24 , struct V_35 * V_36 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
struct V_37 * V_38 ;
int V_33 = - V_39 ;
V_38 = V_30 -> V_31 ;
if ( V_36 -> V_40 & V_41 ) {
struct V_25 V_42 ;
T_4 V_43 ;
T_1 V_44 ;
V_42 . V_27 = V_36 -> time . V_27 ;
V_42 . V_28 = V_36 -> time . V_45 ;
if ( ! ( V_36 -> V_40 & V_46 ) )
V_42 . V_28 *= 1000 ;
if ( ( unsigned long ) V_42 . V_28 >= V_47 )
return - V_48 ;
V_43 = F_13 ( V_42 ) ;
V_44 = F_14 ( V_43 ) ;
V_33 = V_38 -> V_49 ( V_38 , V_44 ) ;
} else if ( V_36 -> V_40 & V_50 ) {
T_3 V_22 = F_7 ( V_36 -> V_51 ) ;
if ( V_22 > V_38 -> V_52 || V_22 < - V_38 -> V_52 )
return - V_53 ;
if ( V_38 -> V_54 )
V_33 = V_38 -> V_54 ( V_38 , V_36 -> V_51 ) ;
else
V_33 = V_38 -> V_55 ( V_38 , V_22 ) ;
V_30 -> V_56 = V_36 -> V_51 ;
} else if ( V_36 -> V_40 == 0 ) {
V_36 -> V_51 = V_30 -> V_56 ;
V_33 = 0 ;
}
return V_33 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
F_16 ( & V_30 -> V_57 ) ;
F_16 ( & V_30 -> V_58 ) ;
F_17 ( & V_59 , V_30 -> V_16 ) ;
F_18 ( V_30 ) ;
}
static void F_19 ( struct V_60 * V_61 )
{
struct V_29 * V_30 = F_10 ( V_61 , struct V_29 ,
V_62 . V_61 ) ;
struct V_37 * V_31 = V_30 -> V_31 ;
long V_63 ;
V_63 = V_31 -> V_64 ( V_31 ) ;
if ( V_63 >= 0 )
F_20 ( V_30 -> V_65 , & V_30 -> V_62 , V_63 ) ;
}
struct V_29 * F_21 ( struct V_37 * V_31 ,
struct V_66 * V_67 )
{
struct V_29 * V_30 ;
int V_33 = 0 , V_16 , V_68 = F_22 ( V_69 ) ;
if ( V_31 -> V_70 > V_71 )
return F_23 ( - V_48 ) ;
V_33 = - V_72 ;
V_30 = F_24 ( sizeof( struct V_29 ) , V_73 ) ;
if ( V_30 == NULL )
goto V_74;
V_16 = F_25 ( & V_59 , 0 , V_75 + 1 , V_73 ) ;
if ( V_16 < 0 ) {
V_33 = V_16 ;
goto V_76;
}
V_30 -> clock . V_38 = V_77 ;
V_30 -> clock . V_78 = F_15 ;
V_30 -> V_31 = V_31 ;
V_30 -> V_79 = F_26 ( V_68 , V_16 ) ;
V_30 -> V_16 = V_16 ;
F_27 ( & V_30 -> V_80 . V_13 ) ;
F_28 ( & V_30 -> V_57 ) ;
F_28 ( & V_30 -> V_58 ) ;
F_29 ( & V_30 -> V_81 ) ;
if ( V_30 -> V_31 -> V_64 ) {
char * V_82 = F_30 ( V_73 , L_1 , V_30 -> V_16 ) ;
F_31 ( & V_30 -> V_62 , F_19 ) ;
V_30 -> V_65 = F_32 ( 0 , V_82 ?
V_82 : V_31 -> V_83 ) ;
F_18 ( V_82 ) ;
if ( F_33 ( V_30 -> V_65 ) ) {
V_33 = F_34 ( V_30 -> V_65 ) ;
F_35 ( L_2 , V_33 ) ;
goto V_84;
}
}
V_33 = F_36 ( V_30 ) ;
if ( V_33 )
goto V_85;
V_30 -> V_86 = F_37 ( V_87 , V_67 , V_30 -> V_79 ,
V_30 , V_30 -> V_88 ,
L_1 , V_30 -> V_16 ) ;
if ( F_33 ( V_30 -> V_86 ) )
goto V_89;
if ( V_31 -> V_90 ) {
struct V_91 V_90 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
snprintf ( V_90 . V_83 , V_92 , L_1 , V_16 ) ;
V_90 . V_93 = V_94 ;
V_90 . V_95 = V_31 -> V_95 ;
V_30 -> V_96 = F_38 ( & V_90 , V_97 ) ;
if ( ! V_30 -> V_96 ) {
F_35 ( L_3 ) ;
goto V_98;
}
}
V_33 = F_39 ( & V_30 -> clock , V_30 -> V_79 ) ;
if ( V_33 ) {
F_35 ( L_4 ) ;
goto V_99;
}
return V_30 ;
V_99:
if ( V_30 -> V_96 )
F_40 ( V_30 -> V_96 ) ;
V_98:
F_41 ( V_87 , V_30 -> V_79 ) ;
V_89:
F_42 ( V_30 ) ;
V_85:
if ( V_30 -> V_65 )
F_43 ( V_30 -> V_65 ) ;
V_84:
F_16 ( & V_30 -> V_57 ) ;
F_16 ( & V_30 -> V_58 ) ;
F_17 ( & V_59 , V_16 ) ;
V_76:
F_18 ( V_30 ) ;
V_74:
return F_23 ( V_33 ) ;
}
int F_44 ( struct V_29 * V_30 )
{
V_30 -> V_100 = 1 ;
F_45 ( & V_30 -> V_81 ) ;
if ( V_30 -> V_65 ) {
F_46 ( & V_30 -> V_62 ) ;
F_43 ( V_30 -> V_65 ) ;
}
if ( V_30 -> V_96 )
F_40 ( V_30 -> V_96 ) ;
F_41 ( V_87 , V_30 -> V_79 ) ;
F_42 ( V_30 ) ;
F_47 ( & V_30 -> clock ) ;
return 0 ;
}
void V_5 ( struct V_29 * V_30 , struct V_5 * V_101 )
{
struct V_102 V_103 ;
switch ( V_101 -> type ) {
case V_104 :
break;
case V_105 :
F_3 ( & V_30 -> V_80 , V_101 ) ;
F_45 ( & V_30 -> V_81 ) ;
break;
case V_106 :
F_48 ( & V_103 ) ;
F_49 ( V_30 -> V_96 , & V_103 , V_107 , NULL ) ;
break;
case V_108 :
F_49 ( V_30 -> V_96 , & V_101 -> V_109 ,
V_107 , NULL ) ;
break;
}
}
int F_50 ( struct V_29 * V_30 )
{
return V_30 -> V_16 ;
}
int F_51 ( struct V_29 * V_30 ,
enum V_110 V_111 , unsigned int V_112 )
{
struct V_113 * V_114 = NULL ;
int V_115 ;
F_52 ( & V_30 -> V_58 ) ;
for ( V_115 = 0 ; V_115 < V_30 -> V_31 -> V_116 ; V_115 ++ ) {
if ( V_30 -> V_31 -> V_117 [ V_115 ] . V_111 == V_111 &&
V_30 -> V_31 -> V_117 [ V_115 ] . V_112 == V_112 ) {
V_114 = & V_30 -> V_31 -> V_117 [ V_115 ] ;
break;
}
}
F_53 ( & V_30 -> V_58 ) ;
return V_114 ? V_115 : - 1 ;
}
int F_54 ( struct V_29 * V_30 , unsigned long V_63 )
{
return F_55 ( V_30 -> V_65 , & V_30 -> V_62 , V_63 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( V_87 ) ;
F_58 ( V_69 , V_75 + 1 ) ;
F_59 ( & V_59 ) ;
}
static int T_6 F_60 ( void )
{
int V_33 ;
V_87 = F_61 ( V_118 , L_5 ) ;
if ( F_33 ( V_87 ) ) {
F_35 ( L_6 ) ;
return F_34 ( V_87 ) ;
}
V_33 = F_62 ( & V_69 , 0 , V_75 + 1 , L_5 ) ;
if ( V_33 < 0 ) {
F_35 ( L_7 ) ;
goto V_119;
}
V_87 -> V_120 = V_121 ;
F_63 ( L_8 ) ;
return 0 ;
V_119:
F_57 ( V_87 ) ;
return V_33 ;
}
