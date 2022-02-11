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
return V_30 -> V_31 -> V_33 ( V_30 -> V_31 , V_26 ) ;
}
static int F_12 ( struct V_23 * V_24 , struct V_34 * V_35 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
struct V_36 * V_37 ;
int V_38 = - V_39 ;
V_37 = V_30 -> V_31 ;
if ( V_35 -> V_40 & V_41 ) {
struct V_25 V_42 ;
T_4 V_43 ;
T_1 V_44 ;
V_42 . V_27 = V_35 -> time . V_27 ;
V_42 . V_28 = V_35 -> time . V_45 ;
if ( ! ( V_35 -> V_40 & V_46 ) )
V_42 . V_28 *= 1000 ;
if ( ( unsigned long ) V_42 . V_28 >= V_47 )
return - V_48 ;
V_43 = F_13 ( V_42 ) ;
V_44 = F_14 ( V_43 ) ;
V_38 = V_37 -> V_49 ( V_37 , V_44 ) ;
} else if ( V_35 -> V_40 & V_50 ) {
T_3 V_22 = F_7 ( V_35 -> V_51 ) ;
if ( V_22 > V_37 -> V_52 || V_22 < - V_37 -> V_52 )
return - V_53 ;
V_38 = V_37 -> V_54 ( V_37 , V_22 ) ;
V_30 -> V_55 = V_35 -> V_51 ;
} else if ( V_35 -> V_40 == 0 ) {
V_35 -> V_51 = V_30 -> V_55 ;
V_38 = 0 ;
}
return V_38 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
F_16 ( & V_30 -> V_56 ) ;
F_16 ( & V_30 -> V_57 ) ;
F_17 ( & V_58 , V_30 -> V_16 ) ;
F_18 ( V_30 ) ;
}
struct V_29 * F_19 ( struct V_36 * V_31 ,
struct V_59 * V_60 )
{
struct V_29 * V_30 ;
int V_38 = 0 , V_16 , V_61 = F_20 ( V_62 ) ;
if ( V_31 -> V_63 > V_64 )
return F_21 ( - V_48 ) ;
V_38 = - V_65 ;
V_30 = F_22 ( sizeof( struct V_29 ) , V_66 ) ;
if ( V_30 == NULL )
goto V_67;
V_16 = F_23 ( & V_58 , 0 , V_68 + 1 , V_66 ) ;
if ( V_16 < 0 ) {
V_38 = V_16 ;
goto V_69;
}
V_30 -> clock . V_37 = V_70 ;
V_30 -> clock . V_71 = F_15 ;
V_30 -> V_31 = V_31 ;
V_30 -> V_72 = F_24 ( V_61 , V_16 ) ;
V_30 -> V_16 = V_16 ;
F_25 ( & V_30 -> V_73 . V_13 ) ;
F_26 ( & V_30 -> V_56 ) ;
F_26 ( & V_30 -> V_57 ) ;
F_27 ( & V_30 -> V_74 ) ;
V_30 -> V_75 = F_28 ( V_76 , V_60 , V_30 -> V_72 , V_30 ,
L_1 , V_30 -> V_16 ) ;
if ( F_29 ( V_30 -> V_75 ) )
goto V_77;
F_30 ( V_30 -> V_75 , V_30 ) ;
V_38 = F_31 ( V_30 ) ;
if ( V_38 )
goto V_78;
if ( V_31 -> V_79 ) {
struct V_80 V_79 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
snprintf ( V_79 . V_81 , V_82 , L_1 , V_16 ) ;
V_79 . V_83 = V_84 ;
V_79 . V_85 = V_31 -> V_85 ;
V_30 -> V_86 = F_32 ( & V_79 , V_87 ) ;
if ( ! V_30 -> V_86 ) {
F_33 ( L_2 ) ;
goto V_88;
}
}
V_38 = F_34 ( & V_30 -> clock , V_30 -> V_72 ) ;
if ( V_38 ) {
F_33 ( L_3 ) ;
goto V_89;
}
return V_30 ;
V_89:
if ( V_30 -> V_86 )
F_35 ( V_30 -> V_86 ) ;
V_88:
F_36 ( V_30 ) ;
V_78:
F_37 ( V_76 , V_30 -> V_72 ) ;
V_77:
F_16 ( & V_30 -> V_56 ) ;
F_16 ( & V_30 -> V_57 ) ;
V_69:
F_18 ( V_30 ) ;
V_67:
return F_21 ( V_38 ) ;
}
int F_38 ( struct V_29 * V_30 )
{
V_30 -> V_90 = 1 ;
F_39 ( & V_30 -> V_74 ) ;
if ( V_30 -> V_86 )
F_35 ( V_30 -> V_86 ) ;
F_36 ( V_30 ) ;
F_37 ( V_76 , V_30 -> V_72 ) ;
F_40 ( & V_30 -> clock ) ;
return 0 ;
}
void V_5 ( struct V_29 * V_30 , struct V_5 * V_91 )
{
struct V_92 V_93 ;
switch ( V_91 -> type ) {
case V_94 :
break;
case V_95 :
F_3 ( & V_30 -> V_73 , V_91 ) ;
F_39 ( & V_30 -> V_74 ) ;
break;
case V_96 :
F_41 ( & V_93 ) ;
F_42 ( V_30 -> V_86 , & V_93 , V_97 , NULL ) ;
break;
case V_98 :
F_42 ( V_30 -> V_86 , & V_91 -> V_99 ,
V_97 , NULL ) ;
break;
}
}
int F_43 ( struct V_29 * V_30 )
{
return V_30 -> V_16 ;
}
int F_44 ( struct V_29 * V_30 ,
enum V_100 V_101 , unsigned int V_102 )
{
struct V_103 * V_104 = NULL ;
int V_105 ;
F_45 ( & V_30 -> V_57 ) ;
for ( V_105 = 0 ; V_105 < V_30 -> V_31 -> V_106 ; V_105 ++ ) {
if ( V_30 -> V_31 -> V_107 [ V_105 ] . V_101 == V_101 &&
V_30 -> V_31 -> V_107 [ V_105 ] . V_102 == V_102 ) {
V_104 = & V_30 -> V_31 -> V_107 [ V_105 ] ;
break;
}
}
F_46 ( & V_30 -> V_57 ) ;
return V_104 ? V_105 : - 1 ;
}
static void T_5 F_47 ( void )
{
F_48 ( V_76 ) ;
F_49 ( V_62 , V_68 + 1 ) ;
F_50 ( & V_58 ) ;
}
static int T_6 F_51 ( void )
{
int V_38 ;
V_76 = F_52 ( V_108 , L_4 ) ;
if ( F_29 ( V_76 ) ) {
F_33 ( L_5 ) ;
return F_53 ( V_76 ) ;
}
V_38 = F_54 ( & V_62 , 0 , V_68 + 1 , L_4 ) ;
if ( V_38 < 0 ) {
F_33 ( L_6 ) ;
goto V_109;
}
V_76 -> V_110 = V_111 ;
F_55 ( L_7 ) ;
return 0 ;
V_109:
F_48 ( V_76 ) ;
return V_38 ;
}
