static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 -> V_8 , 1 ) ;
F_4 ( & V_9 ) ;
F_5 ( & V_5 -> V_10 ) ;
F_6 ( & V_9 ) ;
if ( V_7 )
F_7 ( V_7 ) ;
}
static int F_8 ( struct V_11 * V_11 , struct V_12 * V_13 ,
struct V_12 * V_14 , struct V_1 * V_2 , int V_15 ,
int V_3 )
{
struct V_12 * V_16 [ V_17 + 1 ] ;
struct V_18 * V_19 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_20 , V_21 = 0 ;
if ( V_13 == NULL )
return - V_22 ;
V_20 = F_9 ( V_16 , V_17 , V_13 , V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_16 [ V_24 ] == NULL )
return - V_22 ;
V_19 = F_10 ( V_16 [ V_24 ] ) ;
switch ( V_19 -> V_25 ) {
case V_26 :
case V_27 :
break;
default:
return - V_22 ;
}
if ( V_19 -> V_28 ) {
V_7 = F_11 ( V_11 , V_19 -> V_28 ) ;
if ( V_7 == NULL )
return - V_29 ;
switch ( V_7 -> type ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
V_21 = 0 ;
break;
default:
V_21 = 1 ;
break;
}
} else {
V_7 = NULL ;
}
if ( ! F_12 ( V_19 -> V_36 , V_2 , V_3 ) ) {
if ( V_7 == NULL )
return - V_22 ;
V_20 = F_13 ( V_19 -> V_36 , V_14 , V_2 , sizeof( * V_5 ) ,
V_3 , true ) ;
if ( V_20 )
return V_20 ;
V_20 = V_37 ;
} else {
if ( V_3 )
return 0 ;
F_14 ( V_2 , V_3 ) ;
if ( ! V_15 )
return - V_38 ;
}
V_5 = F_2 ( V_2 ) ;
F_15 () ;
V_5 -> V_39 = V_19 -> V_40 ;
V_5 -> V_41 = V_19 -> V_25 ;
if ( V_7 != NULL ) {
V_5 -> V_42 = V_19 -> V_28 ;
if ( V_20 != V_37 )
F_7 ( F_3 ( V_5 -> V_8 , 1 ) ) ;
F_16 ( V_7 ) ;
F_17 ( V_5 -> V_8 , V_7 ) ;
V_5 -> V_43 = V_21 ;
}
if ( V_20 == V_37 ) {
F_4 ( & V_9 ) ;
F_18 ( & V_5 -> V_10 , & V_44 ) ;
F_6 ( & V_9 ) ;
F_19 ( V_2 ) ;
}
return V_20 ;
}
static int V_4 ( struct V_45 * V_46 , const struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_4 * V_5 = V_2 -> V_49 ;
struct V_6 * V_7 ;
struct V_45 * V_50 ;
int V_51 , V_52 ;
T_1 V_53 ;
F_20 ( & V_5 -> V_54 ) ;
F_21 ( F_22 ( V_5 -> V_55 . V_56 ) , V_46 ) ;
F_23 () ;
V_51 = F_24 ( V_5 -> V_39 ) ;
V_7 = F_25 ( V_5 -> V_8 ) ;
if ( F_26 ( ! V_7 ) ) {
F_27 ( L_1 ) ;
goto V_57;
}
if ( F_26 ( ! ( V_7 -> V_58 & V_59 ) ) ) {
F_28 ( L_2 ,
V_7 -> V_60 ) ;
goto V_57;
}
V_53 = F_29 ( V_46 -> V_61 ) ;
V_50 = F_30 ( V_46 , V_62 ) ;
if ( ! V_50 )
goto V_57;
if ( ! ( V_53 & V_63 ) ) {
if ( V_5 -> V_43 )
F_31 ( V_50 , V_46 -> V_64 ) ;
}
if ( V_5 -> V_41 != V_26 )
V_50 -> V_61 = F_32 ( V_50 -> V_61 , V_53 ) ;
V_50 -> V_65 = V_46 -> V_7 -> V_28 ;
V_50 -> V_7 = V_7 ;
F_33 ( V_50 ) ;
V_52 = F_34 ( V_50 ) ;
if ( V_52 ) {
V_57:
F_35 ( F_22 ( V_5 -> V_55 . V_66 ) ) ;
if ( V_5 -> V_41 != V_26 )
V_51 = V_67 ;
}
F_36 () ;
return V_51 ;
}
static int F_37 ( struct V_45 * V_46 , struct V_1 * V_2 , int V_3 , int V_68 )
{
unsigned char * V_69 = F_38 ( V_46 ) ;
struct V_4 * V_5 = V_2 -> V_49 ;
struct V_18 V_70 = {
. V_36 = V_5 -> V_71 ,
. V_40 = V_5 -> V_39 ,
. V_72 = V_5 -> V_73 - V_68 ,
. V_74 = V_5 -> V_75 - V_3 ,
. V_25 = V_5 -> V_41 ,
. V_28 = V_5 -> V_42 ,
} ;
struct V_76 V_77 ;
if ( F_39 ( V_46 , V_24 , sizeof( V_70 ) , & V_70 ) )
goto V_78;
V_77 . V_79 = F_40 ( V_80 - V_5 -> V_54 . V_79 ) ;
V_77 . V_81 = F_40 ( V_80 - V_5 -> V_54 . V_81 ) ;
V_77 . V_82 = F_40 ( V_5 -> V_54 . V_82 ) ;
if ( F_39 ( V_46 , V_83 , sizeof( V_77 ) , & V_77 ) )
goto V_78;
return V_46 -> V_84 ;
V_78:
F_41 ( V_46 , V_69 ) ;
return - 1 ;
}
static int F_42 ( struct V_85 * V_86 ,
unsigned long V_87 , void * V_88 )
{
struct V_6 * V_7 = F_43 ( V_88 ) ;
struct V_4 * V_5 ;
F_15 () ;
if ( V_87 == V_89 ) {
F_4 ( & V_9 ) ;
F_44 (m, &mirred_list, tcfm_list) {
if ( F_45 ( V_5 -> V_8 ) == V_7 ) {
F_7 ( V_7 ) ;
F_46 ( V_5 -> V_8 , NULL ) ;
}
}
F_6 ( & V_9 ) ;
}
return V_90 ;
}
static int T_2 F_47 ( void )
{
int V_52 = F_48 ( & V_91 ) ;
if ( V_52 )
return V_52 ;
F_49 ( L_3 ) ;
return F_50 ( & V_92 , V_93 ) ;
}
static void T_3 F_51 ( void )
{
F_52 ( & V_92 ) ;
F_53 ( & V_91 ) ;
}
