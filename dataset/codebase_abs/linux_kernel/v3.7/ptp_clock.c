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
F_17 ( & V_55 ) ;
F_18 ( V_30 -> V_16 , V_56 ) ;
F_19 ( & V_55 ) ;
F_20 ( V_30 ) ;
}
struct V_29 * F_21 ( struct V_36 * V_31 ,
struct V_57 * V_58 )
{
struct V_29 * V_30 ;
int V_38 = 0 , V_16 , V_59 = F_22 ( V_60 ) ;
if ( V_31 -> V_61 > V_62 )
return F_23 ( - V_48 ) ;
V_38 = - V_63 ;
F_17 ( & V_55 ) ;
V_16 = F_24 ( V_56 , V_64 ) ;
if ( V_16 < V_64 )
F_25 ( V_16 , V_56 ) ;
else
goto V_65;
V_38 = - V_66 ;
V_30 = F_26 ( sizeof( struct V_29 ) , V_67 ) ;
if ( V_30 == NULL )
goto V_68;
V_30 -> clock . V_37 = V_69 ;
V_30 -> clock . V_70 = F_15 ;
V_30 -> V_31 = V_31 ;
V_30 -> V_71 = F_27 ( V_59 , V_16 ) ;
V_30 -> V_16 = V_16 ;
F_28 ( & V_30 -> V_72 . V_13 ) ;
F_29 ( & V_30 -> V_54 ) ;
F_30 ( & V_30 -> V_73 ) ;
V_30 -> V_74 = F_31 ( V_75 , V_58 , V_30 -> V_71 , V_30 ,
L_1 , V_30 -> V_16 ) ;
if ( F_32 ( V_30 -> V_74 ) )
goto V_76;
F_33 ( V_30 -> V_74 , V_30 ) ;
V_38 = F_34 ( V_30 ) ;
if ( V_38 )
goto V_77;
if ( V_31 -> V_78 ) {
struct V_79 V_78 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
snprintf ( V_78 . V_80 , V_81 , L_1 , V_16 ) ;
V_78 . V_82 = V_83 ;
V_78 . V_84 = V_31 -> V_84 ;
V_30 -> V_85 = F_35 ( & V_78 , V_86 ) ;
if ( ! V_30 -> V_85 ) {
F_36 ( L_2 ) ;
goto V_87;
}
}
V_38 = F_37 ( & V_30 -> clock , V_30 -> V_71 ) ;
if ( V_38 ) {
F_36 ( L_3 ) ;
goto V_88;
}
F_19 ( & V_55 ) ;
return V_30 ;
V_88:
if ( V_30 -> V_85 )
F_38 ( V_30 -> V_85 ) ;
V_87:
F_39 ( V_30 ) ;
V_77:
F_40 ( V_75 , V_30 -> V_71 ) ;
V_76:
F_16 ( & V_30 -> V_54 ) ;
F_20 ( V_30 ) ;
V_68:
F_18 ( V_16 , V_56 ) ;
V_65:
F_19 ( & V_55 ) ;
return F_23 ( V_38 ) ;
}
int F_41 ( struct V_29 * V_30 )
{
V_30 -> V_89 = 1 ;
F_42 ( & V_30 -> V_73 ) ;
if ( V_30 -> V_85 )
F_38 ( V_30 -> V_85 ) ;
F_39 ( V_30 ) ;
F_40 ( V_75 , V_30 -> V_71 ) ;
F_43 ( & V_30 -> clock ) ;
return 0 ;
}
void V_5 ( struct V_29 * V_30 , struct V_5 * V_90 )
{
struct V_91 V_92 ;
switch ( V_90 -> type ) {
case V_93 :
break;
case V_94 :
F_3 ( & V_30 -> V_72 , V_90 ) ;
F_42 ( & V_30 -> V_73 ) ;
break;
case V_95 :
F_44 ( & V_92 ) ;
F_45 ( V_30 -> V_85 , & V_92 , V_96 , NULL ) ;
break;
case V_97 :
F_45 ( V_30 -> V_85 , & V_90 -> V_98 ,
V_96 , NULL ) ;
break;
}
}
int F_46 ( struct V_29 * V_30 )
{
return V_30 -> V_16 ;
}
static void T_5 F_47 ( void )
{
F_48 ( V_75 ) ;
F_49 ( V_60 , V_64 ) ;
}
static int T_6 F_50 ( void )
{
int V_38 ;
V_75 = F_51 ( V_99 , L_4 ) ;
if ( F_32 ( V_75 ) ) {
F_36 ( L_5 ) ;
return F_52 ( V_75 ) ;
}
V_38 = F_53 ( & V_60 , 0 , V_64 , L_4 ) ;
if ( V_38 < 0 ) {
F_36 ( L_6 ) ;
goto V_100;
}
V_75 -> V_101 = V_102 ;
F_54 ( L_7 ) ;
return 0 ;
V_100:
F_48 ( V_75 ) ;
return V_38 ;
}
