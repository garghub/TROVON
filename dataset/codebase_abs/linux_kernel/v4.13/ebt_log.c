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
F_6 ( struct V_26 * V_26 , T_2 V_27 , unsigned int V_28 ,
const struct V_12 * V_13 , const struct V_29 * V_30 ,
const struct V_29 * V_31 , const struct V_32 * V_33 ,
const char * V_10 )
{
unsigned int V_6 ;
if ( ! F_7 ( V_26 , & V_34 ) && ! V_35 )
return;
F_8 ( & V_36 ) ;
F_9 ( V_37 L_3 ,
'0' + V_33 -> V_38 . log . V_39 , V_10 ,
V_30 ? V_30 -> V_40 : L_4 , V_31 ? V_31 -> V_40 : L_4 ,
F_10 ( V_13 ) -> V_41 , F_10 ( V_13 ) -> V_42 ,
F_5 ( F_10 ( V_13 ) -> V_43 ) ) ;
if ( V_33 -> type == V_44 )
V_6 = V_33 -> V_38 . log . V_45 ;
else
V_6 = V_46 ;
if ( ( V_6 & V_47 ) && F_10 ( V_13 ) -> V_43 ==
F_11 ( V_48 ) ) {
const struct V_49 * V_50 ;
struct V_49 V_51 ;
V_50 = F_3 ( V_13 , 0 , sizeof( V_51 ) , & V_51 ) ;
if ( V_50 == NULL ) {
F_4 ( L_5 ) ;
goto V_31;
}
F_4 ( L_6 ,
& V_50 -> V_52 , & V_50 -> V_53 , V_50 -> V_54 , V_50 -> V_14 ) ;
F_2 ( V_13 , V_50 -> V_14 , V_50 -> V_55 * 4 ) ;
goto V_31;
}
#if F_12 ( V_56 )
if ( ( V_6 & V_57 ) && F_10 ( V_13 ) -> V_43 ==
F_11 ( V_58 ) ) {
const struct V_59 * V_50 ;
struct V_59 V_51 ;
T_1 V_60 ;
T_3 V_61 ;
int V_62 ;
V_50 = F_3 ( V_13 , 0 , sizeof( V_51 ) , & V_51 ) ;
if ( V_50 == NULL ) {
F_4 ( L_7 ) ;
goto V_31;
}
F_4 ( L_8 ,
& V_50 -> V_52 , & V_50 -> V_53 , V_50 -> V_63 , V_50 -> V_60 ) ;
V_60 = V_50 -> V_60 ;
V_62 = F_13 ( V_13 , sizeof( V_51 ) , & V_60 , & V_61 ) ;
if ( V_62 == - 1 )
goto V_31;
F_2 ( V_13 , V_60 , V_62 ) ;
goto V_31;
}
#endif
if ( ( V_6 & V_64 ) &&
( ( F_10 ( V_13 ) -> V_43 == F_11 ( V_65 ) ) ||
( F_10 ( V_13 ) -> V_43 == F_11 ( V_66 ) ) ) ) {
const struct V_67 * V_68 ;
struct V_67 V_69 ;
V_68 = F_3 ( V_13 , 0 , sizeof( V_69 ) , & V_69 ) ;
if ( V_68 == NULL ) {
F_4 ( L_9 ) ;
goto V_31;
}
F_4 ( L_10 ,
F_5 ( V_68 -> V_70 ) , F_5 ( V_68 -> V_71 ) ,
F_5 ( V_68 -> V_72 ) ) ;
if ( V_68 -> V_70 == F_11 ( 1 ) &&
V_68 -> V_73 == V_74 &&
V_68 -> V_75 == sizeof( V_76 ) ) {
const struct V_77 * V_78 ;
struct V_77 V_79 ;
V_78 = F_3 ( V_13 , sizeof( V_69 ) ,
sizeof( V_79 ) , & V_79 ) ;
if ( V_78 == NULL ) {
F_4 ( L_11 ) ;
goto V_31;
}
F_4 ( L_12 ,
V_78 -> V_80 , V_78 -> V_81 ,
V_78 -> V_82 , V_78 -> V_83 ) ;
}
}
V_31:
F_4 ( L_13 ) ;
F_14 ( & V_36 ) ;
}
static unsigned int
F_15 ( struct V_12 * V_13 , const struct V_84 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 V_85 ;
struct V_26 * V_26 = F_16 ( V_2 ) ;
V_85 . type = V_44 ;
V_85 . V_38 . log . V_39 = V_4 -> V_9 ;
V_85 . V_38 . log . V_45 = V_4 -> V_6 ;
if ( V_4 -> V_6 & V_86 )
F_17 ( V_26 , V_87 , F_18 ( V_2 ) , V_13 ,
F_19 ( V_2 ) , F_20 ( V_2 ) , & V_85 , L_14 ,
V_4 -> V_10 ) ;
else
F_6 ( V_26 , V_87 , F_18 ( V_2 ) , V_13 ,
F_19 ( V_2 ) , F_20 ( V_2 ) , & V_85 , V_4 -> V_10 ) ;
return V_88 ;
}
static int T_4 F_21 ( void )
{
return F_22 ( & V_89 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_89 ) ;
}
