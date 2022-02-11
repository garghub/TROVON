static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & ~ V_7 )
return - V_8 ;
if ( V_4 -> V_9 >= 8 )
return - V_8 ;
V_4 -> V_10 [ V_11 - 1 ] = '\0' ;
return 0 ;
}
static void
F_2 ( const struct V_12 * V_13 , T_1 V_14 , int V_15 )
{
if ( V_14 == V_16 ||
V_14 == V_17 ||
V_14 == V_18 ||
V_14 == V_19 ||
V_14 == V_20 ) {
const struct V_21 * V_22 ;
struct V_21 V_23 ;
V_22 = F_3 ( V_13 , V_15 ,
sizeof( V_23 ) , & V_23 ) ;
if ( V_22 == NULL ) {
F_4 ( L_1 ) ;
return;
}
F_4 ( L_2 , F_5 ( V_22 -> V_24 ) , F_5 ( V_22 -> V_25 ) ) ;
}
}
static void
F_6 ( T_2 V_26 , unsigned int V_27 ,
const struct V_12 * V_13 , const struct V_28 * V_29 ,
const struct V_28 * V_30 , const struct V_31 * V_32 ,
const char * V_10 )
{
unsigned int V_6 ;
F_7 ( & V_33 ) ;
F_4 ( V_34 L_3 ,
'0' + V_32 -> V_35 . log . V_36 , V_10 ,
V_29 ? V_29 -> V_37 : L_4 , V_30 ? V_30 -> V_37 : L_4 ,
F_8 ( V_13 ) -> V_38 , F_8 ( V_13 ) -> V_39 ,
F_5 ( F_8 ( V_13 ) -> V_40 ) ) ;
if ( V_32 -> type == V_41 )
V_6 = V_32 -> V_35 . log . V_42 ;
else
V_6 = V_43 ;
if ( ( V_6 & V_44 ) && F_8 ( V_13 ) -> V_40 ==
F_9 ( V_45 ) ) {
const struct V_46 * V_47 ;
struct V_46 V_48 ;
V_47 = F_3 ( V_13 , 0 , sizeof( V_48 ) , & V_48 ) ;
if ( V_47 == NULL ) {
F_4 ( L_5 ) ;
goto V_30;
}
F_4 ( L_6 ,
& V_47 -> V_49 , & V_47 -> V_50 , V_47 -> V_51 , V_47 -> V_14 ) ;
F_2 ( V_13 , V_47 -> V_14 , V_47 -> V_52 * 4 ) ;
goto V_30;
}
#if F_10 ( V_53 )
if ( ( V_6 & V_54 ) && F_8 ( V_13 ) -> V_40 ==
F_9 ( V_55 ) ) {
const struct V_56 * V_47 ;
struct V_56 V_48 ;
T_1 V_57 ;
T_3 V_58 ;
int V_59 ;
V_47 = F_3 ( V_13 , 0 , sizeof( V_48 ) , & V_48 ) ;
if ( V_47 == NULL ) {
F_4 ( L_7 ) ;
goto V_30;
}
F_4 ( L_8 ,
& V_47 -> V_49 , & V_47 -> V_50 , V_47 -> V_60 , V_47 -> V_57 ) ;
V_57 = V_47 -> V_57 ;
V_59 = F_11 ( V_13 , sizeof( V_48 ) , & V_57 , & V_58 ) ;
if ( V_59 == - 1 )
goto V_30;
F_2 ( V_13 , V_57 , V_59 ) ;
goto V_30;
}
#endif
if ( ( V_6 & V_61 ) &&
( ( F_8 ( V_13 ) -> V_40 == F_9 ( V_62 ) ) ||
( F_8 ( V_13 ) -> V_40 == F_9 ( V_63 ) ) ) ) {
const struct V_64 * V_65 ;
struct V_64 V_66 ;
V_65 = F_3 ( V_13 , 0 , sizeof( V_66 ) , & V_66 ) ;
if ( V_65 == NULL ) {
F_4 ( L_9 ) ;
goto V_30;
}
F_4 ( L_10 ,
F_5 ( V_65 -> V_67 ) , F_5 ( V_65 -> V_68 ) ,
F_5 ( V_65 -> V_69 ) ) ;
if ( V_65 -> V_67 == F_9 ( 1 ) &&
V_65 -> V_70 == V_71 &&
V_65 -> V_72 == sizeof( V_73 ) ) {
const struct V_74 * V_75 ;
struct V_74 V_76 ;
V_75 = F_3 ( V_13 , sizeof( V_66 ) ,
sizeof( V_76 ) , & V_76 ) ;
if ( V_75 == NULL ) {
F_4 ( L_11 ) ;
goto V_30;
}
F_4 ( L_12 ,
V_75 -> V_77 , V_75 -> V_78 , V_75 -> V_79 , V_75 -> V_80 ) ;
}
}
V_30:
F_4 ( L_13 ) ;
F_12 ( & V_33 ) ;
}
static unsigned int
F_13 ( struct V_12 * V_13 , const struct V_81 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 V_82 ;
V_82 . type = V_41 ;
V_82 . V_35 . log . V_36 = V_4 -> V_9 ;
V_82 . V_35 . log . V_42 = V_4 -> V_6 ;
if ( V_4 -> V_6 & V_83 )
F_14 ( V_84 , V_2 -> V_27 , V_13 , V_2 -> V_29 ,
V_2 -> V_30 , & V_82 , L_14 , V_4 -> V_10 ) ;
else
F_6 ( V_84 , V_2 -> V_27 , V_13 , V_2 -> V_29 ,
V_2 -> V_30 , & V_82 , V_4 -> V_10 ) ;
return V_85 ;
}
static int T_4 F_15 ( void )
{
int V_86 ;
V_86 = F_16 ( & V_87 ) ;
if ( V_86 < 0 )
return V_86 ;
F_17 ( V_84 , & V_88 ) ;
return 0 ;
}
static void T_5 F_18 ( void )
{
F_19 ( & V_88 ) ;
F_20 ( & V_87 ) ;
}
