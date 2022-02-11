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
return 1 ;
}
static int F_9 ( struct V_23 * V_24 , const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_10 ( V_24 , struct V_27 , clock ) ;
return V_28 -> V_29 -> V_30 ( V_28 -> V_29 , V_26 ) ;
}
static int F_11 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
struct V_27 * V_28 = F_10 ( V_24 , struct V_27 , clock ) ;
return V_28 -> V_29 -> V_31 ( V_28 -> V_29 , V_26 ) ;
}
static int F_12 ( struct V_23 * V_24 , struct V_32 * V_33 )
{
struct V_27 * V_28 = F_10 ( V_24 , struct V_27 , clock ) ;
struct V_34 * V_35 ;
int V_36 = - V_37 ;
V_35 = V_28 -> V_29 ;
if ( V_33 -> V_38 & V_39 ) {
struct V_25 V_40 ;
T_4 V_41 ;
T_1 V_42 ;
V_40 . V_43 = V_33 -> time . V_43 ;
V_40 . V_44 = V_33 -> time . V_45 ;
if ( ! ( V_33 -> V_38 & V_46 ) )
V_40 . V_44 *= 1000 ;
if ( ( unsigned long ) V_40 . V_44 >= V_47 )
return - V_48 ;
V_41 = F_13 ( V_40 ) ;
V_42 = F_14 ( V_41 ) ;
V_36 = V_35 -> V_49 ( V_35 , V_42 ) ;
} else if ( V_33 -> V_38 & V_50 ) {
V_36 = V_35 -> V_51 ( V_35 , F_7 ( V_33 -> V_52 ) ) ;
}
return V_36 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_27 * V_28 = F_10 ( V_24 , struct V_27 , clock ) ;
F_16 ( & V_28 -> V_53 ) ;
F_17 ( & V_54 ) ;
F_18 ( V_28 -> V_16 , V_55 ) ;
F_19 ( & V_54 ) ;
F_20 ( V_28 ) ;
}
struct V_27 * F_21 ( struct V_34 * V_29 )
{
struct V_27 * V_28 ;
int V_36 = 0 , V_16 , V_56 = F_22 ( V_57 ) ;
if ( V_29 -> V_58 > V_59 )
return F_23 ( - V_48 ) ;
V_36 = - V_60 ;
F_17 ( & V_54 ) ;
V_16 = F_24 ( V_55 , V_61 ) ;
if ( V_16 < V_61 )
F_25 ( V_16 , V_55 ) ;
else
goto V_62;
V_36 = - V_63 ;
V_28 = F_26 ( sizeof( struct V_27 ) , V_64 ) ;
if ( V_28 == NULL )
goto V_65;
V_28 -> clock . V_35 = V_66 ;
V_28 -> clock . V_67 = F_15 ;
V_28 -> V_29 = V_29 ;
V_28 -> V_68 = F_27 ( V_56 , V_16 ) ;
V_28 -> V_16 = V_16 ;
F_28 ( & V_28 -> V_69 . V_13 ) ;
F_29 ( & V_28 -> V_53 ) ;
F_30 ( & V_28 -> V_70 ) ;
V_28 -> V_71 = F_31 ( V_72 , NULL , V_28 -> V_68 , V_28 ,
L_1 , V_28 -> V_16 ) ;
if ( F_32 ( V_28 -> V_71 ) )
goto V_73;
F_33 ( V_28 -> V_71 , V_28 ) ;
V_36 = F_34 ( V_28 ) ;
if ( V_36 )
goto V_74;
if ( V_29 -> V_75 ) {
struct V_76 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
snprintf ( V_75 . V_77 , V_78 , L_1 , V_16 ) ;
V_75 . V_79 = V_80 ;
V_75 . V_81 = V_29 -> V_81 ;
V_28 -> V_82 = F_35 ( & V_75 , V_83 ) ;
if ( ! V_28 -> V_82 ) {
F_36 ( L_2 ) ;
goto V_84;
}
}
V_36 = F_37 ( & V_28 -> clock , V_28 -> V_68 ) ;
if ( V_36 ) {
F_36 ( L_3 ) ;
goto V_85;
}
F_19 ( & V_54 ) ;
return V_28 ;
V_85:
if ( V_28 -> V_82 )
F_38 ( V_28 -> V_82 ) ;
V_84:
F_39 ( V_28 ) ;
V_74:
F_40 ( V_72 , V_28 -> V_68 ) ;
V_73:
F_16 ( & V_28 -> V_53 ) ;
F_20 ( V_28 ) ;
V_65:
F_18 ( V_16 , V_55 ) ;
V_62:
F_19 ( & V_54 ) ;
return F_23 ( V_36 ) ;
}
int F_41 ( struct V_27 * V_28 )
{
V_28 -> V_86 = 1 ;
F_42 ( & V_28 -> V_70 ) ;
if ( V_28 -> V_82 )
F_38 ( V_28 -> V_82 ) ;
F_39 ( V_28 ) ;
F_40 ( V_72 , V_28 -> V_68 ) ;
F_43 ( & V_28 -> clock ) ;
return 0 ;
}
void V_5 ( struct V_27 * V_28 , struct V_5 * V_87 )
{
struct V_88 V_89 ;
switch ( V_87 -> type ) {
case V_90 :
break;
case V_91 :
F_3 ( & V_28 -> V_69 , V_87 ) ;
F_42 ( & V_28 -> V_70 ) ;
break;
case V_92 :
F_44 ( & V_89 ) ;
F_45 ( V_28 -> V_82 , & V_89 , V_93 , NULL ) ;
break;
}
}
static void T_5 F_46 ( void )
{
F_47 ( V_72 ) ;
F_48 ( V_57 , V_61 ) ;
}
static int T_6 F_49 ( void )
{
int V_36 ;
V_72 = F_50 ( V_94 , L_4 ) ;
if ( F_32 ( V_72 ) ) {
F_36 ( L_5 ) ;
return F_51 ( V_72 ) ;
}
V_36 = F_52 ( & V_57 , 0 , V_61 , L_4 ) ;
if ( V_36 < 0 ) {
F_36 ( L_6 ) ;
goto V_95;
}
V_72 -> V_96 = V_97 ;
F_53 ( L_7 ) ;
return 0 ;
V_95:
F_47 ( V_72 ) ;
return V_36 ;
}
