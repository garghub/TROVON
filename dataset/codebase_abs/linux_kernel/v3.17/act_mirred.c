static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
F_4 ( V_5 -> V_7 ) ;
}
static int F_5 ( struct V_8 * V_8 , struct V_9 * V_10 ,
struct V_9 * V_11 , struct V_1 * V_2 , int V_12 ,
int V_3 )
{
struct V_9 * V_13 [ V_14 + 1 ] ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
int V_19 , V_20 = 0 ;
if ( V_10 == NULL )
return - V_21 ;
V_19 = F_6 ( V_13 , V_14 , V_10 , V_22 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_13 [ V_23 ] == NULL )
return - V_21 ;
V_16 = F_7 ( V_13 [ V_23 ] ) ;
switch ( V_16 -> V_24 ) {
case V_25 :
case V_26 :
break;
default:
return - V_21 ;
}
if ( V_16 -> V_27 ) {
V_18 = F_8 ( V_8 , V_16 -> V_27 ) ;
if ( V_18 == NULL )
return - V_28 ;
switch ( V_18 -> type ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
V_20 = 0 ;
break;
default:
V_20 = 1 ;
break;
}
} else {
V_18 = NULL ;
}
if ( ! F_9 ( V_16 -> V_35 , V_2 , V_3 ) ) {
if ( V_18 == NULL )
return - V_21 ;
V_19 = F_10 ( V_16 -> V_35 , V_11 , V_2 , sizeof( * V_5 ) , V_3 ) ;
if ( V_19 )
return V_19 ;
V_19 = V_36 ;
} else {
if ( ! V_12 ) {
F_11 ( V_2 , V_3 ) ;
return - V_37 ;
}
}
V_5 = F_2 ( V_2 ) ;
F_12 ( & V_5 -> V_38 ) ;
V_5 -> V_39 = V_16 -> V_40 ;
V_5 -> V_41 = V_16 -> V_24 ;
if ( V_18 != NULL ) {
V_5 -> V_42 = V_16 -> V_27 ;
if ( V_19 != V_36 )
F_4 ( V_5 -> V_7 ) ;
F_13 ( V_18 ) ;
V_5 -> V_7 = V_18 ;
V_5 -> V_43 = V_20 ;
}
F_14 ( & V_5 -> V_38 ) ;
if ( V_19 == V_36 ) {
F_15 ( & V_5 -> V_6 , & V_44 ) ;
F_16 ( V_2 ) ;
}
return V_19 ;
}
static int V_4 ( struct V_45 * V_46 , const struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_4 * V_5 = V_2 -> V_49 ;
struct V_17 * V_18 ;
struct V_45 * V_50 ;
T_1 V_51 ;
int V_52 , V_53 = 1 ;
F_17 ( & V_5 -> V_38 ) ;
V_5 -> V_54 . V_55 = V_56 ;
F_18 ( & V_5 -> V_57 , V_46 ) ;
V_18 = V_5 -> V_7 ;
if ( ! V_18 ) {
F_19 ( V_58 L_1 ) ;
goto V_59;
}
if ( ! ( V_18 -> V_60 & V_61 ) ) {
F_20 ( L_2 ,
V_18 -> V_62 ) ;
goto V_59;
}
V_51 = F_21 ( V_46 -> V_63 ) ;
V_50 = F_22 ( V_46 , V_64 , V_5 -> V_39 ) ;
if ( V_50 == NULL )
goto V_59;
if ( ! ( V_51 & V_65 ) ) {
if ( V_5 -> V_43 )
F_23 ( V_50 , V_50 -> V_18 -> V_66 ) ;
}
if ( V_5 -> V_41 != V_25 )
V_50 -> V_63 = F_24 ( V_50 -> V_63 , V_51 ) ;
V_50 -> V_67 = V_46 -> V_18 -> V_27 ;
V_50 -> V_18 = V_18 ;
V_53 = F_25 ( V_50 ) ;
V_59:
if ( V_53 ) {
V_5 -> V_68 . V_69 ++ ;
if ( V_5 -> V_41 != V_25 )
V_52 = V_70 ;
else
V_52 = V_5 -> V_39 ;
} else
V_52 = V_5 -> V_39 ;
F_26 ( & V_5 -> V_38 ) ;
return V_52 ;
}
static int F_27 ( struct V_45 * V_46 , struct V_1 * V_2 , int V_3 , int V_71 )
{
unsigned char * V_72 = F_28 ( V_46 ) ;
struct V_4 * V_5 = V_2 -> V_49 ;
struct V_15 V_73 = {
. V_35 = V_5 -> V_74 ,
. V_40 = V_5 -> V_39 ,
. V_75 = V_5 -> V_76 - V_71 ,
. V_77 = V_5 -> V_78 - V_3 ,
. V_24 = V_5 -> V_41 ,
. V_27 = V_5 -> V_42 ,
} ;
struct V_79 V_80 ;
if ( F_29 ( V_46 , V_23 , sizeof( V_73 ) , & V_73 ) )
goto V_81;
V_80 . V_82 = F_30 ( V_56 - V_5 -> V_54 . V_82 ) ;
V_80 . V_55 = F_30 ( V_56 - V_5 -> V_54 . V_55 ) ;
V_80 . V_83 = F_30 ( V_5 -> V_54 . V_83 ) ;
if ( F_29 ( V_46 , V_84 , sizeof( V_80 ) , & V_80 ) )
goto V_81;
return V_46 -> V_85 ;
V_81:
F_31 ( V_46 , V_72 ) ;
return - 1 ;
}
static int F_32 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
struct V_17 * V_18 = F_33 ( V_89 ) ;
struct V_4 * V_5 ;
if ( V_88 == V_90 )
F_34 (m, &mirred_list, tcfm_list) {
F_12 ( & V_5 -> V_38 ) ;
if ( V_5 -> V_7 == V_18 ) {
F_4 ( V_18 ) ;
V_5 -> V_7 = NULL ;
}
F_14 ( & V_5 -> V_38 ) ;
}
return V_91 ;
}
static int T_2 F_35 ( void )
{
int V_53 = F_36 ( & V_92 ) ;
if ( V_53 )
return V_53 ;
F_37 ( L_3 ) ;
return F_38 ( & V_93 , V_94 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_93 ) ;
F_41 ( & V_92 ) ;
}
