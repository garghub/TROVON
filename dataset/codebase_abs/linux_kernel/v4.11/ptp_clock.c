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
struct V_31 V_32 = F_11 ( * V_26 ) ;
return V_30 -> V_33 -> V_34 ( V_30 -> V_33 , & V_32 ) ;
}
static int F_12 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
struct V_31 V_32 ;
int V_35 ;
V_35 = V_30 -> V_33 -> V_36 ( V_30 -> V_33 , & V_32 ) ;
if ( ! V_35 )
* V_26 = F_13 ( V_32 ) ;
return V_35 ;
}
static int F_14 ( struct V_23 * V_24 , struct V_37 * V_38 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
struct V_39 * V_40 ;
int V_35 = - V_41 ;
V_40 = V_30 -> V_33 ;
if ( V_38 -> V_42 & V_43 ) {
struct V_25 V_32 ;
T_4 V_44 ;
T_1 V_45 ;
V_32 . V_27 = V_38 -> time . V_27 ;
V_32 . V_28 = V_38 -> time . V_46 ;
if ( ! ( V_38 -> V_42 & V_47 ) )
V_32 . V_28 *= 1000 ;
if ( ( unsigned long ) V_32 . V_28 >= V_48 )
return - V_49 ;
V_44 = F_15 ( V_32 ) ;
V_45 = F_16 ( V_44 ) ;
V_35 = V_40 -> V_50 ( V_40 , V_45 ) ;
} else if ( V_38 -> V_42 & V_51 ) {
T_3 V_22 = F_7 ( V_38 -> V_52 ) ;
if ( V_22 > V_40 -> V_53 || V_22 < - V_40 -> V_53 )
return - V_54 ;
if ( V_40 -> V_55 )
V_35 = V_40 -> V_55 ( V_40 , V_38 -> V_52 ) ;
else
V_35 = V_40 -> V_56 ( V_40 , V_22 ) ;
V_30 -> V_57 = V_38 -> V_52 ;
} else if ( V_38 -> V_42 == 0 ) {
V_38 -> V_52 = V_30 -> V_57 ;
V_35 = 0 ;
}
return V_35 ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
F_18 ( & V_30 -> V_58 ) ;
F_18 ( & V_30 -> V_59 ) ;
F_19 ( & V_60 , V_30 -> V_16 ) ;
F_20 ( V_30 ) ;
}
struct V_29 * F_21 ( struct V_39 * V_33 ,
struct V_61 * V_62 )
{
struct V_29 * V_30 ;
int V_35 = 0 , V_16 , V_63 = F_22 ( V_64 ) ;
if ( V_33 -> V_65 > V_66 )
return F_23 ( - V_49 ) ;
V_35 = - V_67 ;
V_30 = F_24 ( sizeof( struct V_29 ) , V_68 ) ;
if ( V_30 == NULL )
goto V_69;
V_16 = F_25 ( & V_60 , 0 , V_70 + 1 , V_68 ) ;
if ( V_16 < 0 ) {
V_35 = V_16 ;
goto V_71;
}
V_30 -> clock . V_40 = V_72 ;
V_30 -> clock . V_73 = F_17 ;
V_30 -> V_33 = V_33 ;
V_30 -> V_74 = F_26 ( V_63 , V_16 ) ;
V_30 -> V_16 = V_16 ;
F_27 ( & V_30 -> V_75 . V_13 ) ;
F_28 ( & V_30 -> V_58 ) ;
F_28 ( & V_30 -> V_59 ) ;
F_29 ( & V_30 -> V_76 ) ;
V_35 = F_30 ( V_30 ) ;
if ( V_35 )
goto V_77;
V_30 -> V_78 = F_31 ( V_79 , V_62 , V_30 -> V_74 ,
V_30 , V_30 -> V_80 ,
L_1 , V_30 -> V_16 ) ;
if ( F_32 ( V_30 -> V_78 ) )
goto V_81;
if ( V_33 -> V_82 ) {
struct V_83 V_82 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
snprintf ( V_82 . V_84 , V_85 , L_1 , V_16 ) ;
V_82 . V_86 = V_87 ;
V_82 . V_88 = V_33 -> V_88 ;
V_30 -> V_89 = F_33 ( & V_82 , V_90 ) ;
if ( ! V_30 -> V_89 ) {
F_34 ( L_2 ) ;
goto V_91;
}
}
V_35 = F_35 ( & V_30 -> clock , V_30 -> V_74 ) ;
if ( V_35 ) {
F_34 ( L_3 ) ;
goto V_92;
}
return V_30 ;
V_92:
if ( V_30 -> V_89 )
F_36 ( V_30 -> V_89 ) ;
V_91:
F_37 ( V_79 , V_30 -> V_74 ) ;
V_81:
F_38 ( V_30 ) ;
V_77:
F_18 ( & V_30 -> V_58 ) ;
F_18 ( & V_30 -> V_59 ) ;
F_19 ( & V_60 , V_16 ) ;
V_71:
F_20 ( V_30 ) ;
V_69:
return F_23 ( V_35 ) ;
}
int F_39 ( struct V_29 * V_30 )
{
V_30 -> V_93 = 1 ;
F_40 ( & V_30 -> V_76 ) ;
if ( V_30 -> V_89 )
F_36 ( V_30 -> V_89 ) ;
F_37 ( V_79 , V_30 -> V_74 ) ;
F_38 ( V_30 ) ;
F_41 ( & V_30 -> clock ) ;
return 0 ;
}
void V_5 ( struct V_29 * V_30 , struct V_5 * V_94 )
{
struct V_95 V_96 ;
switch ( V_94 -> type ) {
case V_97 :
break;
case V_98 :
F_3 ( & V_30 -> V_75 , V_94 ) ;
F_40 ( & V_30 -> V_76 ) ;
break;
case V_99 :
F_42 ( & V_96 ) ;
F_43 ( V_30 -> V_89 , & V_96 , V_100 , NULL ) ;
break;
case V_101 :
F_43 ( V_30 -> V_89 , & V_94 -> V_102 ,
V_100 , NULL ) ;
break;
}
}
int F_44 ( struct V_29 * V_30 )
{
return V_30 -> V_16 ;
}
int F_45 ( struct V_29 * V_30 ,
enum V_103 V_104 , unsigned int V_105 )
{
struct V_106 * V_107 = NULL ;
int V_108 ;
F_46 ( & V_30 -> V_59 ) ;
for ( V_108 = 0 ; V_108 < V_30 -> V_33 -> V_109 ; V_108 ++ ) {
if ( V_30 -> V_33 -> V_110 [ V_108 ] . V_104 == V_104 &&
V_30 -> V_33 -> V_110 [ V_108 ] . V_105 == V_105 ) {
V_107 = & V_30 -> V_33 -> V_110 [ V_108 ] ;
break;
}
}
F_47 ( & V_30 -> V_59 ) ;
return V_107 ? V_108 : - 1 ;
}
static void T_5 F_48 ( void )
{
F_49 ( V_79 ) ;
F_50 ( V_64 , V_70 + 1 ) ;
F_51 ( & V_60 ) ;
}
static int T_6 F_52 ( void )
{
int V_35 ;
V_79 = F_53 ( V_111 , L_4 ) ;
if ( F_32 ( V_79 ) ) {
F_34 ( L_5 ) ;
return F_54 ( V_79 ) ;
}
V_35 = F_55 ( & V_64 , 0 , V_70 + 1 , L_4 ) ;
if ( V_35 < 0 ) {
F_34 ( L_6 ) ;
goto V_112;
}
V_79 -> V_113 = V_114 ;
F_56 ( L_7 ) ;
return 0 ;
V_112:
F_49 ( V_79 ) ;
return V_35 ;
}
