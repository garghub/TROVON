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
V_38 = V_37 -> V_51 ( V_37 , F_7 ( V_35 -> V_52 ) ) ;
V_30 -> V_53 = V_35 -> V_52 ;
} else if ( V_35 -> V_40 == 0 ) {
V_35 -> V_52 = V_30 -> V_53 ;
V_38 = 0 ;
}
return V_38 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_29 * V_30 = F_10 ( V_24 , struct V_29 , clock ) ;
F_16 ( & V_30 -> V_54 ) ;
F_17 ( & V_55 , V_30 -> V_16 ) ;
F_18 ( V_30 ) ;
}
struct V_29 * F_19 ( struct V_36 * V_31 ,
struct V_56 * V_57 )
{
struct V_29 * V_30 ;
int V_38 = 0 , V_16 , V_58 = F_20 ( V_59 ) ;
if ( V_31 -> V_60 > V_61 )
return F_21 ( - V_48 ) ;
V_38 = - V_62 ;
V_30 = F_22 ( sizeof( struct V_29 ) , V_63 ) ;
if ( V_30 == NULL )
goto V_64;
V_16 = F_23 ( & V_55 , 0 , V_65 + 1 , V_63 ) ;
if ( V_16 < 0 ) {
V_38 = V_16 ;
goto V_66;
}
V_30 -> clock . V_37 = V_67 ;
V_30 -> clock . V_68 = F_15 ;
V_30 -> V_31 = V_31 ;
V_30 -> V_69 = F_24 ( V_58 , V_16 ) ;
V_30 -> V_16 = V_16 ;
F_25 ( & V_30 -> V_70 . V_13 ) ;
F_26 ( & V_30 -> V_54 ) ;
F_27 ( & V_30 -> V_71 ) ;
V_30 -> V_72 = F_28 ( V_73 , V_57 , V_30 -> V_69 , V_30 ,
L_1 , V_30 -> V_16 ) ;
if ( F_29 ( V_30 -> V_72 ) )
goto V_74;
F_30 ( V_30 -> V_72 , V_30 ) ;
V_38 = F_31 ( V_30 ) ;
if ( V_38 )
goto V_75;
if ( V_31 -> V_76 ) {
struct V_77 V_76 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
snprintf ( V_76 . V_78 , V_79 , L_1 , V_16 ) ;
V_76 . V_80 = V_81 ;
V_76 . V_82 = V_31 -> V_82 ;
V_30 -> V_83 = F_32 ( & V_76 , V_84 ) ;
if ( ! V_30 -> V_83 ) {
F_33 ( L_2 ) ;
goto V_85;
}
}
V_38 = F_34 ( & V_30 -> clock , V_30 -> V_69 ) ;
if ( V_38 ) {
F_33 ( L_3 ) ;
goto V_86;
}
return V_30 ;
V_86:
if ( V_30 -> V_83 )
F_35 ( V_30 -> V_83 ) ;
V_85:
F_36 ( V_30 ) ;
V_75:
F_37 ( V_73 , V_30 -> V_69 ) ;
V_74:
F_16 ( & V_30 -> V_54 ) ;
V_66:
F_18 ( V_30 ) ;
V_64:
return F_21 ( V_38 ) ;
}
int F_38 ( struct V_29 * V_30 )
{
V_30 -> V_87 = 1 ;
F_39 ( & V_30 -> V_71 ) ;
if ( V_30 -> V_83 )
F_35 ( V_30 -> V_83 ) ;
F_36 ( V_30 ) ;
F_37 ( V_73 , V_30 -> V_69 ) ;
F_40 ( & V_30 -> clock ) ;
return 0 ;
}
void V_5 ( struct V_29 * V_30 , struct V_5 * V_88 )
{
struct V_89 V_90 ;
switch ( V_88 -> type ) {
case V_91 :
break;
case V_92 :
F_3 ( & V_30 -> V_70 , V_88 ) ;
F_39 ( & V_30 -> V_71 ) ;
break;
case V_93 :
F_41 ( & V_90 ) ;
F_42 ( V_30 -> V_83 , & V_90 , V_94 , NULL ) ;
break;
case V_95 :
F_42 ( V_30 -> V_83 , & V_88 -> V_96 ,
V_94 , NULL ) ;
break;
}
}
int F_43 ( struct V_29 * V_30 )
{
return V_30 -> V_16 ;
}
static void T_5 F_44 ( void )
{
F_45 ( V_73 ) ;
F_46 ( V_59 , V_65 + 1 ) ;
F_47 ( & V_55 ) ;
}
static int T_6 F_48 ( void )
{
int V_38 ;
V_73 = F_49 ( V_97 , L_4 ) ;
if ( F_29 ( V_73 ) ) {
F_33 ( L_5 ) ;
return F_50 ( V_73 ) ;
}
V_38 = F_51 ( & V_59 , 0 , V_65 + 1 , L_4 ) ;
if ( V_38 < 0 ) {
F_33 ( L_6 ) ;
goto V_98;
}
V_73 -> V_99 = V_100 ;
F_52 ( L_7 ) ;
return 0 ;
V_98:
F_45 ( V_73 ) ;
return V_38 ;
}
