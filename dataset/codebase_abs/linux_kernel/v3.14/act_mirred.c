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
static int F_5 ( struct V_10 * V_10 , struct V_11 * V_12 ,
struct V_11 * V_13 , struct V_14 * V_15 , int V_16 ,
int V_3 )
{
struct V_11 * V_17 [ V_18 + 1 ] ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 , V_26 = 0 ;
if ( V_12 == NULL )
return - V_27 ;
V_25 = F_6 ( V_17 , V_18 , V_12 , V_28 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_17 [ V_29 ] == NULL )
return - V_27 ;
V_20 = F_7 ( V_17 [ V_29 ] ) ;
switch ( V_20 -> V_30 ) {
case V_31 :
case V_32 :
break;
default:
return - V_27 ;
}
if ( V_20 -> V_33 ) {
V_24 = F_8 ( V_10 , V_20 -> V_33 ) ;
if ( V_24 == NULL )
return - V_34 ;
switch ( V_24 -> type ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_26 = 0 ;
break;
default:
V_26 = 1 ;
break;
}
} else {
V_24 = NULL ;
}
V_22 = F_9 ( V_20 -> V_41 , V_15 , V_3 ) ;
if ( ! V_22 ) {
if ( V_24 == NULL )
return - V_27 ;
V_22 = F_10 ( V_20 -> V_41 , V_13 , V_15 , sizeof( * V_2 ) , V_3 ) ;
if ( F_11 ( V_22 ) )
return F_12 ( V_22 ) ;
V_25 = V_42 ;
} else {
if ( ! V_16 ) {
F_1 ( F_13 ( V_22 ) , V_3 ) ;
return - V_43 ;
}
}
V_2 = F_13 ( V_22 ) ;
F_14 ( & V_2 -> V_44 ) ;
V_2 -> V_45 = V_20 -> V_46 ;
V_2 -> V_47 = V_20 -> V_30 ;
if ( V_24 != NULL ) {
V_2 -> V_48 = V_20 -> V_33 ;
if ( V_25 != V_42 )
F_3 ( V_2 -> V_7 ) ;
F_15 ( V_24 ) ;
V_2 -> V_7 = V_24 ;
V_2 -> V_49 = V_26 ;
}
F_16 ( & V_2 -> V_44 ) ;
if ( V_25 == V_42 ) {
F_17 ( & V_2 -> V_6 , & V_50 ) ;
F_18 ( V_22 , V_15 -> V_51 -> V_52 ) ;
}
return V_25 ;
}
static int F_19 ( struct V_14 * V_15 , int V_3 )
{
struct V_1 * V_2 = V_15 -> V_53 ;
if ( V_2 )
return F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int V_1 ( struct V_54 * V_55 , const struct V_14 * V_15 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = V_15 -> V_53 ;
struct V_23 * V_24 ;
struct V_54 * V_58 ;
T_1 V_59 ;
int V_60 , V_61 = 1 ;
F_20 ( & V_2 -> V_44 ) ;
V_2 -> V_62 . V_63 = V_64 ;
F_21 ( & V_2 -> V_65 , V_55 ) ;
V_24 = V_2 -> V_7 ;
if ( ! V_24 ) {
F_22 ( V_66 L_1 ) ;
goto V_67;
}
if ( ! ( V_24 -> V_68 & V_69 ) ) {
F_23 ( L_2 ,
V_24 -> V_70 ) ;
goto V_67;
}
V_59 = F_24 ( V_55 -> V_71 ) ;
V_58 = F_25 ( V_55 , V_72 , V_2 -> V_45 ) ;
if ( V_58 == NULL )
goto V_67;
if ( ! ( V_59 & V_73 ) ) {
if ( V_2 -> V_49 )
F_26 ( V_58 , V_58 -> V_24 -> V_74 ) ;
}
if ( V_2 -> V_47 != V_31 )
V_58 -> V_71 = F_27 ( V_58 -> V_71 , V_59 ) ;
V_58 -> V_75 = V_55 -> V_24 -> V_33 ;
V_58 -> V_24 = V_24 ;
V_61 = F_28 ( V_58 ) ;
V_67:
if ( V_61 ) {
V_2 -> V_76 . V_77 ++ ;
if ( V_2 -> V_47 != V_31 )
V_60 = V_78 ;
else
V_60 = V_2 -> V_45 ;
} else
V_60 = V_2 -> V_45 ;
F_29 ( & V_2 -> V_44 ) ;
return V_60 ;
}
static int F_30 ( struct V_54 * V_55 , struct V_14 * V_15 , int V_3 , int V_79 )
{
unsigned char * V_80 = F_31 ( V_55 ) ;
struct V_1 * V_2 = V_15 -> V_53 ;
struct V_19 V_81 = {
. V_41 = V_2 -> V_82 ,
. V_46 = V_2 -> V_45 ,
. V_83 = V_2 -> V_5 - V_79 ,
. V_84 = V_2 -> V_4 - V_3 ,
. V_30 = V_2 -> V_47 ,
. V_33 = V_2 -> V_48 ,
} ;
struct V_85 V_86 ;
if ( F_32 ( V_55 , V_29 , sizeof( V_81 ) , & V_81 ) )
goto V_87;
V_86 . V_88 = F_33 ( V_64 - V_2 -> V_62 . V_88 ) ;
V_86 . V_63 = F_33 ( V_64 - V_2 -> V_62 . V_63 ) ;
V_86 . V_89 = F_33 ( V_2 -> V_62 . V_89 ) ;
if ( F_32 ( V_55 , V_90 , sizeof( V_86 ) , & V_86 ) )
goto V_87;
return V_55 -> V_91 ;
V_87:
F_34 ( V_55 , V_80 ) ;
return - 1 ;
}
static int F_35 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
struct V_23 * V_24 = F_36 ( V_95 ) ;
struct V_1 * V_2 ;
if ( V_94 == V_96 )
F_37 (m, &mirred_list, tcfm_list) {
if ( V_2 -> V_7 == V_24 ) {
F_3 ( V_24 ) ;
V_2 -> V_7 = NULL ;
}
}
return V_97 ;
}
static int T_2 F_38 ( void )
{
int V_61 = F_39 ( & V_98 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_40 ( & V_9 , V_99 ) ;
if ( V_61 ) {
F_41 ( & V_98 ) ;
return V_61 ;
}
F_42 ( L_3 ) ;
return F_43 ( & V_100 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_100 ) ;
F_46 ( & V_9 ) ;
F_41 ( & V_98 ) ;
}
