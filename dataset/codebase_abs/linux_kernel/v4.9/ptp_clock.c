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
V_35 = V_40 -> V_55 ( V_40 , V_22 ) ;
V_30 -> V_56 = V_38 -> V_52 ;
} else if ( V_38 -> V_42 == 0 ) {
V_38 -> V_52 = V_30 -> V_56 ;
V_35 = 0 ;
}
return V_35 ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
F_18 ( & V_30 -> V_57 ) ;
F_18 ( & V_30 -> V_58 ) ;
F_19 ( & V_59 , V_30 -> V_16 ) ;
F_20 ( V_30 ) ;
}
struct V_29 * F_21 ( struct V_39 * V_33 ,
struct V_60 * V_61 )
{
struct V_29 * V_30 ;
int V_35 = 0 , V_16 , V_62 = F_22 ( V_63 ) ;
if ( V_33 -> V_64 > V_65 )
return F_23 ( - V_49 ) ;
V_35 = - V_66 ;
V_30 = F_24 ( sizeof( struct V_29 ) , V_67 ) ;
if ( V_30 == NULL )
goto V_68;
V_16 = F_25 ( & V_59 , 0 , V_69 + 1 , V_67 ) ;
if ( V_16 < 0 ) {
V_35 = V_16 ;
goto V_70;
}
V_30 -> clock . V_40 = V_71 ;
V_30 -> clock . V_72 = F_17 ;
V_30 -> V_33 = V_33 ;
V_30 -> V_73 = F_26 ( V_62 , V_16 ) ;
V_30 -> V_16 = V_16 ;
F_27 ( & V_30 -> V_74 . V_13 ) ;
F_28 ( & V_30 -> V_57 ) ;
F_28 ( & V_30 -> V_58 ) ;
F_29 ( & V_30 -> V_75 ) ;
V_30 -> V_76 = F_30 ( V_77 , V_61 , V_30 -> V_73 , V_30 ,
L_1 , V_30 -> V_16 ) ;
if ( F_31 ( V_30 -> V_76 ) )
goto V_78;
F_32 ( V_30 -> V_76 , V_30 ) ;
V_35 = F_33 ( V_30 ) ;
if ( V_35 )
goto V_79;
if ( V_33 -> V_80 ) {
struct V_81 V_80 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
snprintf ( V_80 . V_82 , V_83 , L_1 , V_16 ) ;
V_80 . V_84 = V_85 ;
V_80 . V_86 = V_33 -> V_86 ;
V_30 -> V_87 = F_34 ( & V_80 , V_88 ) ;
if ( ! V_30 -> V_87 ) {
F_35 ( L_2 ) ;
goto V_89;
}
}
V_35 = F_36 ( & V_30 -> clock , V_30 -> V_73 ) ;
if ( V_35 ) {
F_35 ( L_3 ) ;
goto V_90;
}
return V_30 ;
V_90:
if ( V_30 -> V_87 )
F_37 ( V_30 -> V_87 ) ;
V_89:
F_38 ( V_30 ) ;
V_79:
F_39 ( V_77 , V_30 -> V_73 ) ;
V_78:
F_18 ( & V_30 -> V_57 ) ;
F_18 ( & V_30 -> V_58 ) ;
F_19 ( & V_59 , V_16 ) ;
V_70:
F_20 ( V_30 ) ;
V_68:
return F_23 ( V_35 ) ;
}
int F_40 ( struct V_29 * V_30 )
{
V_30 -> V_91 = 1 ;
F_41 ( & V_30 -> V_75 ) ;
if ( V_30 -> V_87 )
F_37 ( V_30 -> V_87 ) ;
F_38 ( V_30 ) ;
F_39 ( V_77 , V_30 -> V_73 ) ;
F_42 ( & V_30 -> clock ) ;
return 0 ;
}
void V_5 ( struct V_29 * V_30 , struct V_5 * V_92 )
{
struct V_93 V_94 ;
switch ( V_92 -> type ) {
case V_95 :
break;
case V_96 :
F_3 ( & V_30 -> V_74 , V_92 ) ;
F_41 ( & V_30 -> V_75 ) ;
break;
case V_97 :
F_43 ( & V_94 ) ;
F_44 ( V_30 -> V_87 , & V_94 , V_98 , NULL ) ;
break;
case V_99 :
F_44 ( V_30 -> V_87 , & V_92 -> V_100 ,
V_98 , NULL ) ;
break;
}
}
int F_45 ( struct V_29 * V_30 )
{
return V_30 -> V_16 ;
}
int F_46 ( struct V_29 * V_30 ,
enum V_101 V_102 , unsigned int V_103 )
{
struct V_104 * V_105 = NULL ;
int V_106 ;
F_47 ( & V_30 -> V_58 ) ;
for ( V_106 = 0 ; V_106 < V_30 -> V_33 -> V_107 ; V_106 ++ ) {
if ( V_30 -> V_33 -> V_108 [ V_106 ] . V_102 == V_102 &&
V_30 -> V_33 -> V_108 [ V_106 ] . V_103 == V_103 ) {
V_105 = & V_30 -> V_33 -> V_108 [ V_106 ] ;
break;
}
}
F_48 ( & V_30 -> V_58 ) ;
return V_105 ? V_106 : - 1 ;
}
static void T_5 F_49 ( void )
{
F_50 ( V_77 ) ;
F_51 ( V_63 , V_69 + 1 ) ;
F_52 ( & V_59 ) ;
}
static int T_6 F_53 ( void )
{
int V_35 ;
V_77 = F_54 ( V_109 , L_4 ) ;
if ( F_31 ( V_77 ) ) {
F_35 ( L_5 ) ;
return F_55 ( V_77 ) ;
}
V_35 = F_56 ( & V_63 , 0 , V_69 + 1 , L_4 ) ;
if ( V_35 < 0 ) {
F_35 ( L_6 ) ;
goto V_110;
}
V_77 -> V_111 = V_112 ;
F_57 ( L_7 ) ;
return 0 ;
V_110:
F_50 ( V_77 ) ;
return V_35 ;
}
