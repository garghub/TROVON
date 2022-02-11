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
struct V_29 * F_19 ( struct V_37 * V_31 ,
struct V_60 * V_61 )
{
struct V_29 * V_30 ;
int V_33 = 0 , V_16 , V_62 = F_20 ( V_63 ) ;
if ( V_31 -> V_64 > V_65 )
return F_21 ( - V_48 ) ;
V_33 = - V_66 ;
V_30 = F_22 ( sizeof( struct V_29 ) , V_67 ) ;
if ( V_30 == NULL )
goto V_68;
V_16 = F_23 ( & V_59 , 0 , V_69 + 1 , V_67 ) ;
if ( V_16 < 0 ) {
V_33 = V_16 ;
goto V_70;
}
V_30 -> clock . V_38 = V_71 ;
V_30 -> clock . V_72 = F_15 ;
V_30 -> V_31 = V_31 ;
V_30 -> V_73 = F_24 ( V_62 , V_16 ) ;
V_30 -> V_16 = V_16 ;
F_25 ( & V_30 -> V_74 . V_13 ) ;
F_26 ( & V_30 -> V_57 ) ;
F_26 ( & V_30 -> V_58 ) ;
F_27 ( & V_30 -> V_75 ) ;
V_33 = F_28 ( V_30 ) ;
if ( V_33 )
goto V_76;
V_30 -> V_77 = F_29 ( V_78 , V_61 , V_30 -> V_73 ,
V_30 , V_30 -> V_79 ,
L_1 , V_30 -> V_16 ) ;
if ( F_30 ( V_30 -> V_77 ) )
goto V_80;
if ( V_31 -> V_81 ) {
struct V_82 V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
snprintf ( V_81 . V_83 , V_84 , L_1 , V_16 ) ;
V_81 . V_85 = V_86 ;
V_81 . V_87 = V_31 -> V_87 ;
V_30 -> V_88 = F_31 ( & V_81 , V_89 ) ;
if ( ! V_30 -> V_88 ) {
F_32 ( L_2 ) ;
goto V_90;
}
}
V_33 = F_33 ( & V_30 -> clock , V_30 -> V_73 ) ;
if ( V_33 ) {
F_32 ( L_3 ) ;
goto V_91;
}
return V_30 ;
V_91:
if ( V_30 -> V_88 )
F_34 ( V_30 -> V_88 ) ;
V_90:
F_35 ( V_78 , V_30 -> V_73 ) ;
V_80:
F_36 ( V_30 ) ;
V_76:
F_16 ( & V_30 -> V_57 ) ;
F_16 ( & V_30 -> V_58 ) ;
F_17 ( & V_59 , V_16 ) ;
V_70:
F_18 ( V_30 ) ;
V_68:
return F_21 ( V_33 ) ;
}
int F_37 ( struct V_29 * V_30 )
{
V_30 -> V_92 = 1 ;
F_38 ( & V_30 -> V_75 ) ;
if ( V_30 -> V_88 )
F_34 ( V_30 -> V_88 ) ;
F_35 ( V_78 , V_30 -> V_73 ) ;
F_36 ( V_30 ) ;
F_39 ( & V_30 -> clock ) ;
return 0 ;
}
void V_5 ( struct V_29 * V_30 , struct V_5 * V_93 )
{
struct V_94 V_95 ;
switch ( V_93 -> type ) {
case V_96 :
break;
case V_97 :
F_3 ( & V_30 -> V_74 , V_93 ) ;
F_38 ( & V_30 -> V_75 ) ;
break;
case V_98 :
F_40 ( & V_95 ) ;
F_41 ( V_30 -> V_88 , & V_95 , V_99 , NULL ) ;
break;
case V_100 :
F_41 ( V_30 -> V_88 , & V_93 -> V_101 ,
V_99 , NULL ) ;
break;
}
}
int F_42 ( struct V_29 * V_30 )
{
return V_30 -> V_16 ;
}
int F_43 ( struct V_29 * V_30 ,
enum V_102 V_103 , unsigned int V_104 )
{
struct V_105 * V_106 = NULL ;
int V_107 ;
F_44 ( & V_30 -> V_58 ) ;
for ( V_107 = 0 ; V_107 < V_30 -> V_31 -> V_108 ; V_107 ++ ) {
if ( V_30 -> V_31 -> V_109 [ V_107 ] . V_103 == V_103 &&
V_30 -> V_31 -> V_109 [ V_107 ] . V_104 == V_104 ) {
V_106 = & V_30 -> V_31 -> V_109 [ V_107 ] ;
break;
}
}
F_45 ( & V_30 -> V_58 ) ;
return V_106 ? V_107 : - 1 ;
}
static void T_5 F_46 ( void )
{
F_47 ( V_78 ) ;
F_48 ( V_63 , V_69 + 1 ) ;
F_49 ( & V_59 ) ;
}
static int T_6 F_50 ( void )
{
int V_33 ;
V_78 = F_51 ( V_110 , L_4 ) ;
if ( F_30 ( V_78 ) ) {
F_32 ( L_5 ) ;
return F_52 ( V_78 ) ;
}
V_33 = F_53 ( & V_63 , 0 , V_69 + 1 , L_4 ) ;
if ( V_33 < 0 ) {
F_32 ( L_6 ) ;
goto V_111;
}
V_78 -> V_112 = V_113 ;
F_54 ( L_7 ) ;
return 0 ;
V_111:
F_47 ( V_78 ) ;
return V_33 ;
}
