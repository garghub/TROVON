static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 ) {
if ( V_3 )
V_2 -> V_4 -- ;
V_2 -> V_5 -- ;
if ( ! V_2 -> V_4 && V_2 -> V_5 <= 0 ) {
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 )
F_3 ( V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 , & V_9 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_5 ( struct V_10 * V_11 , struct V_10 * V_12 ,
struct V_13 * V_14 , int V_15 , int V_3 )
{
struct V_10 * V_16 [ V_17 + 1 ] ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 , V_25 = 0 ;
if ( V_11 == NULL )
return - V_26 ;
V_24 = F_6 ( V_16 , V_17 , V_11 , V_27 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_16 [ V_28 ] == NULL )
return - V_26 ;
V_19 = F_7 ( V_16 [ V_28 ] ) ;
switch ( V_19 -> V_29 ) {
case V_30 :
case V_31 :
break;
default:
return - V_26 ;
}
if ( V_19 -> V_32 ) {
V_23 = F_8 ( & V_33 , V_19 -> V_32 ) ;
if ( V_23 == NULL )
return - V_34 ;
switch ( V_23 -> type ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_25 = 0 ;
break;
default:
V_25 = 1 ;
break;
}
} else {
V_23 = NULL ;
}
V_21 = F_9 ( V_19 -> V_41 , V_14 , V_3 , & V_9 ) ;
if ( ! V_21 ) {
if ( V_23 == NULL )
return - V_26 ;
V_21 = F_10 ( V_19 -> V_41 , V_12 , V_14 , sizeof( * V_2 ) , V_3 ,
& V_42 , & V_9 ) ;
if ( F_11 ( V_21 ) )
return F_12 ( V_21 ) ;
V_24 = V_43 ;
} else {
if ( ! V_15 ) {
F_1 ( F_13 ( V_21 ) , V_3 ) ;
return - V_44 ;
}
}
V_2 = F_13 ( V_21 ) ;
F_14 ( & V_2 -> V_45 ) ;
V_2 -> V_46 = V_19 -> V_47 ;
V_2 -> V_48 = V_19 -> V_29 ;
if ( V_23 != NULL ) {
V_2 -> V_49 = V_19 -> V_32 ;
if ( V_24 != V_43 )
F_3 ( V_2 -> V_7 ) ;
F_15 ( V_23 ) ;
V_2 -> V_7 = V_23 ;
V_2 -> V_50 = V_25 ;
}
F_16 ( & V_2 -> V_45 ) ;
if ( V_24 == V_43 ) {
F_17 ( & V_2 -> V_6 , & V_51 ) ;
F_18 ( V_21 , & V_9 ) ;
}
return V_24 ;
}
static int F_19 ( struct V_13 * V_14 , int V_3 )
{
struct V_1 * V_2 = V_14 -> V_52 ;
if ( V_2 )
return F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int V_1 ( struct V_53 * V_54 , const struct V_13 * V_14 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = V_14 -> V_52 ;
struct V_22 * V_23 ;
struct V_53 * V_57 ;
T_1 V_58 ;
int V_59 , V_60 = 1 ;
F_20 ( & V_2 -> V_45 ) ;
V_2 -> V_61 . V_62 = V_63 ;
F_21 ( & V_2 -> V_64 , V_54 ) ;
V_23 = V_2 -> V_7 ;
if ( ! V_23 ) {
F_22 ( V_65 L_1 ) ;
goto V_66;
}
if ( ! ( V_23 -> V_67 & V_68 ) ) {
F_23 ( L_2 ,
V_23 -> V_69 ) ;
goto V_66;
}
V_58 = F_24 ( V_54 -> V_70 ) ;
V_57 = F_25 ( V_54 , V_71 , V_2 -> V_46 ) ;
if ( V_57 == NULL )
goto V_66;
if ( ! ( V_58 & V_72 ) ) {
if ( V_2 -> V_50 )
F_26 ( V_57 , V_57 -> V_23 -> V_73 ) ;
}
if ( V_2 -> V_48 != V_30 )
V_57 -> V_70 = F_27 ( V_57 -> V_70 , V_58 ) ;
V_57 -> V_74 = V_54 -> V_23 -> V_32 ;
V_57 -> V_23 = V_23 ;
V_60 = F_28 ( V_57 ) ;
V_66:
if ( V_60 ) {
V_2 -> V_75 . V_76 ++ ;
if ( V_2 -> V_48 != V_30 )
V_59 = V_77 ;
else
V_59 = V_2 -> V_46 ;
} else
V_59 = V_2 -> V_46 ;
F_29 ( & V_2 -> V_45 ) ;
return V_59 ;
}
static int F_30 ( struct V_53 * V_54 , struct V_13 * V_14 , int V_3 , int V_78 )
{
unsigned char * V_79 = F_31 ( V_54 ) ;
struct V_1 * V_2 = V_14 -> V_52 ;
struct V_18 V_80 = {
. V_41 = V_2 -> V_81 ,
. V_47 = V_2 -> V_46 ,
. V_82 = V_2 -> V_5 - V_78 ,
. V_83 = V_2 -> V_4 - V_3 ,
. V_29 = V_2 -> V_48 ,
. V_32 = V_2 -> V_49 ,
} ;
struct V_84 V_85 ;
if ( F_32 ( V_54 , V_28 , sizeof( V_80 ) , & V_80 ) )
goto V_86;
V_85 . V_87 = F_33 ( V_63 - V_2 -> V_61 . V_87 ) ;
V_85 . V_62 = F_33 ( V_63 - V_2 -> V_61 . V_62 ) ;
V_85 . V_88 = F_33 ( V_2 -> V_61 . V_88 ) ;
if ( F_32 ( V_54 , V_89 , sizeof( V_85 ) , & V_85 ) )
goto V_86;
return V_54 -> V_90 ;
V_86:
F_34 ( V_54 , V_79 ) ;
return - 1 ;
}
static int F_35 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
struct V_22 * V_23 = V_94 ;
struct V_1 * V_2 ;
if ( V_93 == V_95 )
F_36 (m, &mirred_list, tcfm_list) {
if ( V_2 -> V_7 == V_23 ) {
F_3 ( V_23 ) ;
V_2 -> V_7 = NULL ;
}
}
return V_96 ;
}
static int T_2 F_37 ( void )
{
int V_60 = F_38 ( & V_97 ) ;
if ( V_60 )
return V_60 ;
F_39 ( L_3 ) ;
return F_40 ( & V_98 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_97 ) ;
F_43 ( & V_98 ) ;
}
