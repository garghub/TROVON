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
V_2 -> V_23 . V_13 = V_13 ;
V_14 = F_23 ( & V_2 -> V_23 , & V_2 -> V_6 ) ;
if ( V_14 ) {
F_16 ( L_3 , V_25 ) ;
goto V_26;
}
V_2 -> V_4 = true ;
return 0 ;
V_26:
F_2 ( & V_9 ) ;
F_9 ( V_2 -> V_10 , V_11 ) ;
F_3 ( & V_9 ) ;
return V_14 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 || V_2 -> V_29 ) {
F_3 ( & V_2 -> V_3 ) ;
return;
}
F_25 (fh, &devnode->fhs, list)
F_26 ( & V_28 -> V_30 ) ;
V_2 -> V_4 = false ;
V_2 -> V_29 = true ;
F_3 ( & V_2 -> V_3 ) ;
F_27 ( & V_2 -> V_23 , & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
static void F_28 ( struct V_31 * V_32 , T_2 V_33 )
{
F_29 ( V_32 , V_33 , false ) ;
}
void F_30 ( struct V_31 * V_32 ,
struct V_34 * V_35 )
{
if ( F_31 ( ! V_32 -> V_2 . V_4 ) )
return;
V_32 -> V_35 = V_35 ;
F_32 ( V_32 -> V_35 , V_32 , F_28 ) ;
}
struct V_31 * F_33 ( const struct V_36 * V_37 ,
void * V_38 , const char * V_39 , T_3 V_40 ,
T_4 V_41 )
{
struct V_31 * V_32 ;
int V_42 ;
#ifndef F_34
V_40 &= ~ V_43 ;
#endif
if ( F_31 ( ! V_40 ) )
return F_35 ( - V_44 ) ;
if ( F_31 ( ! V_37 ) )
return F_35 ( - V_44 ) ;
if ( F_31 ( ! V_41 || V_41 > V_45 ) )
return F_35 ( - V_44 ) ;
V_32 = F_36 ( sizeof( * V_32 ) , V_46 ) ;
if ( ! V_32 )
return F_35 ( - V_47 ) ;
F_37 ( V_32 -> V_39 , V_39 , sizeof( V_32 -> V_39 ) ) ;
V_32 -> V_48 = V_49 ;
V_32 -> V_50 = true ;
V_32 -> V_51 . V_52 = V_53 ;
V_32 -> V_51 . V_54 = V_55 ;
V_32 -> V_56 = V_40 ;
V_32 -> V_57 = V_40 & V_58 ;
V_32 -> V_59 = V_41 ;
V_32 -> V_60 = 0 ;
V_32 -> V_37 = V_37 ;
V_32 -> V_38 = V_38 ;
memset ( V_32 -> V_61 , 0xff , sizeof( V_32 -> V_61 ) ) ;
F_14 ( & V_32 -> V_3 ) ;
F_13 ( & V_32 -> V_62 ) ;
F_13 ( & V_32 -> V_63 ) ;
F_38 ( & V_32 -> V_64 ) ;
V_32 -> V_65 = F_39 ( V_66 , V_32 , L_4 , V_39 ) ;
if ( F_40 ( V_32 -> V_65 ) ) {
F_16 ( L_5 , V_39 ) ;
V_42 = F_41 ( V_32 -> V_65 ) ;
F_42 ( V_32 ) ;
return F_35 ( V_42 ) ;
}
#ifdef F_34
if ( ! ( V_40 & V_43 ) )
return V_32 ;
V_32 -> V_67 = F_43 ( V_68 ) ;
if ( ! V_32 -> V_67 ) {
F_16 ( L_6 ,
V_39 ) ;
F_44 ( V_32 -> V_65 ) ;
F_42 ( V_32 ) ;
return F_35 ( - V_47 ) ;
}
snprintf ( V_32 -> V_69 , sizeof( V_32 -> V_69 ) ,
L_7 , V_39 ) ;
snprintf ( V_32 -> V_70 , sizeof( V_32 -> V_70 ) ,
L_8 , V_39 ) ;
V_32 -> V_67 -> V_69 = V_32 -> V_69 ;
V_32 -> V_67 -> V_70 = V_32 -> V_70 ;
V_32 -> V_67 -> V_71 . V_72 = V_73 ;
V_32 -> V_67 -> V_71 . V_74 = 0 ;
V_32 -> V_67 -> V_71 . V_75 = 0 ;
V_32 -> V_67 -> V_71 . V_76 = 1 ;
V_32 -> V_67 -> V_77 = V_78 ;
V_32 -> V_67 -> V_79 = V_80 ;
V_32 -> V_67 -> V_81 = V_80 ;
V_32 -> V_67 -> V_38 = V_32 ;
V_32 -> V_67 -> V_82 = V_83 ;
V_32 -> V_67 -> V_84 = F_45 ( 100 ) ;
V_32 -> V_85 = - 1 ;
#endif
return V_32 ;
}
int F_46 ( struct V_31 * V_32 ,
struct V_7 * V_86 )
{
int V_42 ;
if ( F_47 ( V_32 ) )
return 0 ;
if ( F_31 ( ! V_86 ) )
return - V_44 ;
V_32 -> V_13 = V_86 -> V_87 -> V_13 ;
V_32 -> V_2 . V_6 . V_86 = V_86 ;
#ifdef F_34
if ( V_32 -> V_56 & V_43 ) {
V_32 -> V_67 -> V_6 . V_86 = V_86 ;
V_42 = F_48 ( V_32 -> V_67 ) ;
if ( V_42 ) {
F_16 ( L_9 ,
V_32 -> V_39 ) ;
F_49 ( V_32 -> V_67 ) ;
V_32 -> V_67 = NULL ;
return V_42 ;
}
V_32 -> V_67 -> V_88 -> V_89 [ V_90 ] =
V_32 -> V_67 -> V_88 -> V_89 [ V_91 ] ;
}
#endif
V_42 = F_12 ( & V_32 -> V_2 , V_32 -> V_13 ) ;
if ( V_42 ) {
#ifdef F_34
F_50 ( V_32 -> V_67 ) ;
V_32 -> V_67 = NULL ;
#endif
return V_42 ;
}
F_51 ( & V_32 -> V_2 . V_6 , V_32 ) ;
#ifdef F_52
if ( ! V_92 )
return 0 ;
V_32 -> V_93 = F_53 ( F_54 ( & V_32 -> V_2 . V_6 ) , V_92 ) ;
if ( F_47 ( V_32 -> V_93 ) ) {
F_55 ( L_10 , V_32 -> V_39 ) ;
return 0 ;
}
V_32 -> V_94 = F_56 ( & V_32 -> V_2 . V_6 ,
L_11 , V_32 -> V_93 , V_95 ) ;
if ( F_47 ( V_32 -> V_94 ) ) {
F_55 ( L_12 , V_32 -> V_39 ) ;
F_57 ( V_32 -> V_93 ) ;
V_32 -> V_93 = NULL ;
}
#endif
return 0 ;
}
void F_58 ( struct V_31 * V_32 )
{
if ( F_47 ( V_32 ) )
return;
#ifdef F_34
F_50 ( V_32 -> V_67 ) ;
V_32 -> V_67 = NULL ;
#endif
F_57 ( V_32 -> V_93 ) ;
#ifdef F_59
if ( V_32 -> V_35 )
F_60 ( V_32 -> V_35 ) ;
#endif
F_24 ( & V_32 -> V_2 ) ;
}
void F_10 ( struct V_31 * V_32 )
{
if ( F_47 ( V_32 ) )
return;
F_2 ( & V_32 -> V_3 ) ;
F_61 ( V_32 , V_49 , false ) ;
F_3 ( & V_32 -> V_3 ) ;
F_44 ( V_32 -> V_65 ) ;
if ( V_32 -> V_96 )
F_44 ( V_32 -> V_96 ) ;
if ( V_32 -> V_37 -> V_97 )
V_32 -> V_37 -> V_97 ( V_32 ) ;
#ifdef F_34
F_49 ( V_32 -> V_67 ) ;
#endif
F_42 ( V_32 ) ;
}
static int T_5 F_62 ( void )
{
int V_14 = F_63 ( & V_21 , 0 , V_16 , V_78 ) ;
if ( V_14 < 0 ) {
F_55 ( L_13 ) ;
return V_14 ;
}
#ifdef F_52
V_92 = F_53 ( L_14 , NULL ) ;
if ( F_47 ( V_92 ) ) {
F_55 ( L_15 ) ;
V_92 = NULL ;
}
#endif
V_14 = F_64 ( & V_19 ) ;
if ( V_14 < 0 ) {
F_65 ( V_21 , V_16 ) ;
F_55 ( L_16 ) ;
return - V_98 ;
}
return 0 ;
}
static void T_6 F_66 ( void )
{
F_57 ( V_92 ) ;
F_67 ( & V_19 ) ;
F_65 ( V_21 , V_16 ) ;
}
