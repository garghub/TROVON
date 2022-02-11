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
if ( ! F_7 ( V_26 , & V_34 ) )
return;
F_8 ( & V_35 ) ;
F_4 ( V_36 L_3 ,
'0' + V_33 -> V_37 . log . V_38 , V_10 ,
V_30 ? V_30 -> V_39 : L_4 , V_31 ? V_31 -> V_39 : L_4 ,
F_9 ( V_13 ) -> V_40 , F_9 ( V_13 ) -> V_41 ,
F_5 ( F_9 ( V_13 ) -> V_42 ) ) ;
if ( V_33 -> type == V_43 )
V_6 = V_33 -> V_37 . log . V_44 ;
else
V_6 = V_45 ;
if ( ( V_6 & V_46 ) && F_9 ( V_13 ) -> V_42 ==
F_10 ( V_47 ) ) {
const struct V_48 * V_49 ;
struct V_48 V_50 ;
V_49 = F_3 ( V_13 , 0 , sizeof( V_50 ) , & V_50 ) ;
if ( V_49 == NULL ) {
F_4 ( L_5 ) ;
goto V_31;
}
F_4 ( L_6 ,
& V_49 -> V_51 , & V_49 -> V_52 , V_49 -> V_53 , V_49 -> V_14 ) ;
F_2 ( V_13 , V_49 -> V_14 , V_49 -> V_54 * 4 ) ;
goto V_31;
}
#if F_11 ( V_55 )
if ( ( V_6 & V_56 ) && F_9 ( V_13 ) -> V_42 ==
F_10 ( V_57 ) ) {
const struct V_58 * V_49 ;
struct V_58 V_50 ;
T_1 V_59 ;
T_3 V_60 ;
int V_61 ;
V_49 = F_3 ( V_13 , 0 , sizeof( V_50 ) , & V_50 ) ;
if ( V_49 == NULL ) {
F_4 ( L_7 ) ;
goto V_31;
}
F_4 ( L_8 ,
& V_49 -> V_51 , & V_49 -> V_52 , V_49 -> V_62 , V_49 -> V_59 ) ;
V_59 = V_49 -> V_59 ;
V_61 = F_12 ( V_13 , sizeof( V_50 ) , & V_59 , & V_60 ) ;
if ( V_61 == - 1 )
goto V_31;
F_2 ( V_13 , V_59 , V_61 ) ;
goto V_31;
}
#endif
if ( ( V_6 & V_63 ) &&
( ( F_9 ( V_13 ) -> V_42 == F_10 ( V_64 ) ) ||
( F_9 ( V_13 ) -> V_42 == F_10 ( V_65 ) ) ) ) {
const struct V_66 * V_67 ;
struct V_66 V_68 ;
V_67 = F_3 ( V_13 , 0 , sizeof( V_68 ) , & V_68 ) ;
if ( V_67 == NULL ) {
F_4 ( L_9 ) ;
goto V_31;
}
F_4 ( L_10 ,
F_5 ( V_67 -> V_69 ) , F_5 ( V_67 -> V_70 ) ,
F_5 ( V_67 -> V_71 ) ) ;
if ( V_67 -> V_69 == F_10 ( 1 ) &&
V_67 -> V_72 == V_73 &&
V_67 -> V_74 == sizeof( V_75 ) ) {
const struct V_76 * V_77 ;
struct V_76 V_78 ;
V_77 = F_3 ( V_13 , sizeof( V_68 ) ,
sizeof( V_78 ) , & V_78 ) ;
if ( V_77 == NULL ) {
F_4 ( L_11 ) ;
goto V_31;
}
F_4 ( L_12 ,
V_77 -> V_79 , V_77 -> V_80 , V_77 -> V_81 , V_77 -> V_82 ) ;
}
}
V_31:
F_4 ( L_13 ) ;
F_13 ( & V_35 ) ;
}
static unsigned int
F_14 ( struct V_12 * V_13 , const struct V_83 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 V_84 ;
struct V_26 * V_26 = V_2 -> V_26 ;
V_84 . type = V_43 ;
V_84 . V_37 . log . V_38 = V_4 -> V_9 ;
V_84 . V_37 . log . V_44 = V_4 -> V_6 ;
if ( V_4 -> V_6 & V_85 )
F_15 ( V_26 , V_86 , V_2 -> V_28 , V_13 ,
V_2 -> V_30 , V_2 -> V_31 , & V_84 , L_14 , V_4 -> V_10 ) ;
else
F_6 ( V_26 , V_86 , V_2 -> V_28 , V_13 , V_2 -> V_30 ,
V_2 -> V_31 , & V_84 , V_4 -> V_10 ) ;
return V_87 ;
}
static int T_4 F_16 ( void )
{
return F_17 ( & V_88 ) ;
}
static void T_5 F_18 ( void )
{
F_19 ( & V_88 ) ;
}
