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
F_4 ( L_3 ,
'0' + V_32 -> V_34 . log . V_35 , V_10 ,
V_29 ? V_29 -> V_36 : L_4 , V_30 ? V_30 -> V_36 : L_4 ,
F_8 ( V_13 ) -> V_37 , F_8 ( V_13 ) -> V_38 ,
F_5 ( F_8 ( V_13 ) -> V_39 ) ) ;
if ( V_32 -> type == V_40 )
V_6 = V_32 -> V_34 . log . V_41 ;
else
V_6 = V_42 ;
if ( ( V_6 & V_43 ) && F_8 ( V_13 ) -> V_39 ==
F_9 ( V_44 ) ) {
const struct V_45 * V_46 ;
struct V_45 V_47 ;
V_46 = F_3 ( V_13 , 0 , sizeof( V_47 ) , & V_47 ) ;
if ( V_46 == NULL ) {
F_4 ( L_5 ) ;
goto V_30;
}
F_4 ( L_6 ,
& V_46 -> V_48 , & V_46 -> V_49 , V_46 -> V_50 , V_46 -> V_14 ) ;
F_2 ( V_13 , V_46 -> V_14 , V_46 -> V_51 * 4 ) ;
goto V_30;
}
#if F_10 ( V_52 )
if ( ( V_6 & V_53 ) && F_8 ( V_13 ) -> V_39 ==
F_9 ( V_54 ) ) {
const struct V_55 * V_46 ;
struct V_55 V_47 ;
T_1 V_56 ;
T_3 V_57 ;
int V_58 ;
V_46 = F_3 ( V_13 , 0 , sizeof( V_47 ) , & V_47 ) ;
if ( V_46 == NULL ) {
F_4 ( L_7 ) ;
goto V_30;
}
F_4 ( L_8 ,
& V_46 -> V_48 , & V_46 -> V_49 , V_46 -> V_59 , V_46 -> V_56 ) ;
V_56 = V_46 -> V_56 ;
V_58 = F_11 ( V_13 , sizeof( V_47 ) , & V_56 , & V_57 ) ;
if ( V_58 == - 1 )
goto V_30;
F_2 ( V_13 , V_56 , V_58 ) ;
goto V_30;
}
#endif
if ( ( V_6 & V_60 ) &&
( ( F_8 ( V_13 ) -> V_39 == F_9 ( V_61 ) ) ||
( F_8 ( V_13 ) -> V_39 == F_9 ( V_62 ) ) ) ) {
const struct V_63 * V_64 ;
struct V_63 V_65 ;
V_64 = F_3 ( V_13 , 0 , sizeof( V_65 ) , & V_65 ) ;
if ( V_64 == NULL ) {
F_4 ( L_9 ) ;
goto V_30;
}
F_4 ( L_10 ,
F_5 ( V_64 -> V_66 ) , F_5 ( V_64 -> V_67 ) ,
F_5 ( V_64 -> V_68 ) ) ;
if ( V_64 -> V_66 == F_9 ( 1 ) &&
V_64 -> V_69 == V_70 &&
V_64 -> V_71 == sizeof( V_72 ) ) {
const struct V_73 * V_74 ;
struct V_73 V_75 ;
V_74 = F_3 ( V_13 , sizeof( V_65 ) ,
sizeof( V_75 ) , & V_75 ) ;
if ( V_74 == NULL ) {
F_4 ( L_11 ) ;
goto V_30;
}
F_4 ( L_12 ,
V_74 -> V_76 , V_74 -> V_77 , V_74 -> V_78 , V_74 -> V_79 ) ;
}
}
V_30:
F_4 ( L_13 ) ;
F_12 ( & V_33 ) ;
}
static unsigned int
F_13 ( struct V_12 * V_13 , const struct V_80 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 V_81 ;
V_81 . type = V_40 ;
V_81 . V_34 . log . V_35 = V_4 -> V_9 ;
V_81 . V_34 . log . V_41 = V_4 -> V_6 ;
if ( V_4 -> V_6 & V_82 )
F_14 ( V_83 , V_2 -> V_27 , V_13 , V_2 -> V_29 ,
V_2 -> V_30 , & V_81 , L_14 , V_4 -> V_10 ) ;
else
F_6 ( V_83 , V_2 -> V_27 , V_13 , V_2 -> V_29 ,
V_2 -> V_30 , & V_81 , V_4 -> V_10 ) ;
return V_84 ;
}
static int T_4 F_15 ( void )
{
int V_85 ;
V_85 = F_16 ( & V_86 ) ;
if ( V_85 < 0 )
return V_85 ;
F_17 ( V_83 , & V_87 ) ;
return 0 ;
}
static void T_5 F_18 ( void )
{
F_19 ( & V_87 ) ;
F_20 ( & V_86 ) ;
}
