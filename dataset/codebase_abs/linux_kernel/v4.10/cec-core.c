int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 ) {
F_3 ( & V_2 -> V_3 ) ;
return - V_5 ;
}
F_4 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_3 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_6 ) ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
F_2 ( & V_9 ) ;
F_9 ( V_2 -> V_10 , V_11 ) ;
F_3 ( & V_9 ) ;
F_10 ( F_11 ( V_2 ) ) ;
}
static int T_1 F_12 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_10 ;
int V_14 ;
F_13 ( & V_2 -> V_15 ) ;
F_14 ( & V_2 -> V_3 ) ;
F_2 ( & V_9 ) ;
V_10 = F_15 ( V_11 , V_16 , 0 ) ;
if ( V_10 == V_16 ) {
F_3 ( & V_9 ) ;
F_16 ( L_1 ) ;
return - V_17 ;
}
F_17 ( V_10 , V_11 ) ;
F_3 ( & V_9 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_6 . V_18 = & V_19 ;
V_2 -> V_6 . V_20 = F_18 ( F_19 ( V_21 ) , V_10 ) ;
V_2 -> V_6 . V_22 = F_7 ;
F_20 ( & V_2 -> V_6 , L_2 , V_2 -> V_10 ) ;
F_21 ( & V_2 -> V_6 ) ;
F_22 ( & V_2 -> V_23 , & V_24 ) ;
V_2 -> V_23 . V_25 . V_26 = & V_2 -> V_6 . V_25 ;
V_2 -> V_23 . V_13 = V_13 ;
V_14 = F_23 ( & V_2 -> V_23 , V_2 -> V_6 . V_20 , 1 ) ;
if ( V_14 < 0 ) {
F_16 ( L_3 , V_27 ) ;
goto V_28;
}
V_14 = F_24 ( & V_2 -> V_6 ) ;
if ( V_14 )
goto V_29;
V_2 -> V_4 = true ;
return 0 ;
V_29:
V_29 ( & V_2 -> V_23 ) ;
V_28:
F_2 ( & V_9 ) ;
F_9 ( V_2 -> V_10 , V_11 ) ;
F_3 ( & V_9 ) ;
return V_14 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 || V_2 -> V_32 ) {
F_3 ( & V_2 -> V_3 ) ;
return;
}
F_26 (fh, &devnode->fhs, list)
F_27 ( & V_31 -> V_33 ) ;
V_2 -> V_4 = false ;
V_2 -> V_32 = true ;
F_3 ( & V_2 -> V_3 ) ;
F_28 ( & V_2 -> V_6 ) ;
V_29 ( & V_2 -> V_23 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
struct V_34 * F_29 ( const struct V_35 * V_36 ,
void * V_37 , const char * V_38 , T_2 V_39 ,
T_3 V_40 )
{
struct V_34 * V_41 ;
int V_42 ;
if ( F_30 ( ! V_39 ) )
return F_31 ( - V_43 ) ;
if ( F_30 ( ! V_36 ) )
return F_31 ( - V_43 ) ;
if ( F_30 ( ! V_40 || V_40 > V_44 ) )
return F_31 ( - V_43 ) ;
V_41 = F_32 ( sizeof( * V_41 ) , V_45 ) ;
if ( ! V_41 )
return F_31 ( - V_46 ) ;
F_33 ( V_41 -> V_38 , V_38 , sizeof( V_41 -> V_38 ) ) ;
V_41 -> V_47 = V_48 ;
V_41 -> V_49 . V_50 = V_51 ;
V_41 -> V_49 . V_52 = V_53 ;
V_41 -> V_54 = V_39 ;
V_41 -> V_55 = V_40 ;
V_41 -> V_56 = 0 ;
V_41 -> V_36 = V_36 ;
V_41 -> V_37 = V_37 ;
memset ( V_41 -> V_57 , 0xff , sizeof( V_41 -> V_57 ) ) ;
F_14 ( & V_41 -> V_3 ) ;
F_13 ( & V_41 -> V_58 ) ;
F_13 ( & V_41 -> V_59 ) ;
F_34 ( & V_41 -> V_60 ) ;
V_41 -> V_61 = F_35 ( V_62 , V_41 , L_4 , V_38 ) ;
if ( F_36 ( V_41 -> V_61 ) ) {
F_16 ( L_5 , V_38 ) ;
V_42 = F_37 ( V_41 -> V_61 ) ;
F_38 ( V_41 ) ;
return F_31 ( V_42 ) ;
}
if ( ! ( V_39 & V_63 ) )
return V_41 ;
#if F_39 ( V_64 )
V_41 -> V_65 = F_40 () ;
if ( ! V_41 -> V_65 ) {
F_16 ( L_6 ,
V_38 ) ;
F_41 ( V_41 -> V_61 ) ;
F_38 ( V_41 ) ;
return F_31 ( - V_46 ) ;
}
snprintf ( V_41 -> V_66 , sizeof( V_41 -> V_66 ) ,
L_7 , V_38 ) ;
snprintf ( V_41 -> V_67 , sizeof( V_41 -> V_67 ) ,
L_8 , V_38 ) ;
V_41 -> V_65 -> V_66 = V_41 -> V_66 ;
V_41 -> V_65 -> V_67 = V_41 -> V_67 ;
V_41 -> V_65 -> V_68 . V_69 = V_70 ;
V_41 -> V_65 -> V_68 . V_71 = 0 ;
V_41 -> V_65 -> V_68 . V_72 = 0 ;
V_41 -> V_65 -> V_68 . V_73 = 1 ;
V_41 -> V_65 -> V_74 = V_75 ;
V_41 -> V_65 -> V_76 = V_77 ;
V_41 -> V_65 -> V_78 = V_79 ;
V_41 -> V_65 -> V_37 = V_41 ;
V_41 -> V_65 -> V_80 = V_81 ;
V_41 -> V_65 -> V_82 = F_42 ( 100 ) ;
#else
V_41 -> V_54 &= ~ V_63 ;
#endif
return V_41 ;
}
int F_43 ( struct V_34 * V_41 ,
struct V_7 * V_26 )
{
int V_42 ;
if ( F_44 ( V_41 ) )
return 0 ;
if ( F_30 ( ! V_26 ) )
return - V_43 ;
V_41 -> V_13 = V_26 -> V_83 -> V_13 ;
V_41 -> V_2 . V_6 . V_26 = V_26 ;
#if F_39 ( V_64 )
V_41 -> V_65 -> V_6 . V_26 = V_26 ;
if ( V_41 -> V_54 & V_63 ) {
V_42 = F_45 ( V_41 -> V_65 ) ;
if ( V_42 ) {
F_16 ( L_9 ,
V_41 -> V_38 ) ;
F_46 ( V_41 -> V_65 ) ;
V_41 -> V_65 = NULL ;
return V_42 ;
}
}
#endif
V_42 = F_12 ( & V_41 -> V_2 , V_41 -> V_13 ) ;
if ( V_42 ) {
#if F_39 ( V_64 )
F_47 ( V_41 -> V_65 ) ;
V_41 -> V_65 = NULL ;
#endif
return V_42 ;
}
F_48 ( & V_41 -> V_2 . V_6 , V_41 ) ;
#ifdef F_49
if ( ! V_84 )
return 0 ;
V_41 -> V_85 = F_50 ( F_51 ( & V_41 -> V_2 . V_6 ) , V_84 ) ;
if ( F_44 ( V_41 -> V_85 ) ) {
F_52 ( L_10 , V_41 -> V_38 ) ;
return 0 ;
}
V_41 -> V_86 = F_53 ( & V_41 -> V_2 . V_6 ,
L_11 , V_41 -> V_85 , V_87 ) ;
if ( F_44 ( V_41 -> V_86 ) ) {
F_52 ( L_12 , V_41 -> V_38 ) ;
F_54 ( V_41 -> V_85 ) ;
V_41 -> V_85 = NULL ;
}
#endif
return 0 ;
}
void F_55 ( struct V_34 * V_41 )
{
if ( F_44 ( V_41 ) )
return;
#if F_39 ( V_64 )
F_47 ( V_41 -> V_65 ) ;
V_41 -> V_65 = NULL ;
#endif
F_54 ( V_41 -> V_85 ) ;
F_25 ( & V_41 -> V_2 ) ;
}
void F_10 ( struct V_34 * V_41 )
{
if ( F_44 ( V_41 ) )
return;
F_2 ( & V_41 -> V_3 ) ;
F_56 ( V_41 , V_48 , false ) ;
F_3 ( & V_41 -> V_3 ) ;
F_41 ( V_41 -> V_61 ) ;
if ( V_41 -> V_88 )
F_41 ( V_41 -> V_88 ) ;
#if F_39 ( V_64 )
F_46 ( V_41 -> V_65 ) ;
#endif
F_38 ( V_41 ) ;
}
static int T_4 F_57 ( void )
{
int V_14 ;
F_58 ( L_13 ) ;
V_14 = F_59 ( & V_21 , 0 , V_16 ,
V_77 ) ;
if ( V_14 < 0 ) {
F_52 ( L_14 ) ;
return V_14 ;
}
#ifdef F_49
V_84 = F_50 ( L_15 , NULL ) ;
if ( F_44 ( V_84 ) ) {
F_52 ( L_16 ) ;
V_84 = NULL ;
}
#endif
V_14 = F_60 ( & V_19 ) ;
if ( V_14 < 0 ) {
F_61 ( V_21 , V_16 ) ;
F_52 ( L_17 ) ;
return - V_89 ;
}
return 0 ;
}
static void T_5 F_62 ( void )
{
F_54 ( V_84 ) ;
F_63 ( & V_19 ) ;
F_61 ( V_21 , V_16 ) ;
}
