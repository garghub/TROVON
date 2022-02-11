static unsigned int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
if ( V_2 -> V_10 != NULL )
return V_11 ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
V_2 -> V_10 = & V_9 -> V_12 ;
V_2 -> V_14 = V_15 ;
return V_11 ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_16 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
if ( V_2 -> V_10 != NULL )
return V_11 ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
V_2 -> V_10 = & V_9 -> V_12 ;
V_2 -> V_14 = V_15 ;
return V_11 ;
}
static T_1 F_4 ( const struct V_17 * V_4 )
{
if ( V_4 -> V_18 == V_19 ) {
const struct V_20 * V_21 = V_4 -> V_22 ;
if ( V_21 -> V_23 . V_24 & V_25 )
return 0 ;
return V_21 -> V_23 . V_26 ;
} else if ( V_4 -> V_18 == V_27 ) {
const struct V_28 * V_21 = V_4 -> V_22 ;
if ( V_21 -> V_29 . V_24 & V_30 )
return 0 ;
return V_21 -> V_29 . V_26 ;
} else
return 0 ;
}
static int
F_5 ( struct V_8 * V_9 , const char * V_31 ,
const struct V_17 * V_4 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_1 V_26 ;
V_26 = F_4 ( V_4 ) ;
if ( ! V_26 ) {
F_6 ( L_1
L_2 ) ;
return - V_36 ;
}
V_33 = F_7 ( V_31 , V_4 -> V_18 ,
V_26 ) ;
if ( V_33 == NULL ) {
F_6 ( L_3 , V_31 ) ;
return - V_36 ;
}
V_35 = F_8 ( V_9 , V_33 , V_37 ) ;
if ( V_35 == NULL ) {
F_9 ( V_33 -> V_38 ) ;
return - V_39 ;
}
V_35 -> V_33 = V_33 ;
return 0 ;
}
static int F_10 ( const struct V_17 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_40 V_41 ;
struct V_8 * V_9 ;
int V_42 = - V_43 ;
if ( V_6 -> V_44 & ~ V_45 )
return - V_46 ;
if ( V_6 -> V_44 & V_45 ) {
V_9 = F_11 () ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
goto V_47;
}
#ifndef F_12
if ( V_6 -> V_48 )
goto V_49;
#endif
V_42 = F_13 ( V_4 -> V_18 ) ;
if ( V_42 < 0 )
goto V_49;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_9 = F_14 ( V_4 -> V_50 , V_6 -> V_48 , & V_41 , & V_41 , V_37 ) ;
V_42 = F_15 ( V_9 ) ;
if ( F_16 ( V_9 ) )
goto V_51;
V_42 = 0 ;
if ( ( V_6 -> V_52 || V_6 -> V_53 ) &&
! F_17 ( V_9 , V_6 -> V_52 , V_6 -> V_53 ,
V_37 ) )
goto V_54;
if ( V_6 -> V_33 [ 0 ] ) {
V_42 = F_5 ( V_9 , V_6 -> V_33 , V_4 ) ;
if ( V_42 < 0 )
goto V_54;
}
F_18 ( V_55 , & V_9 -> V_56 ) ;
F_18 ( V_57 , & V_9 -> V_56 ) ;
F_19 ( & V_9 -> V_58 [ V_59 ] . V_60 ,
& V_4 -> V_50 -> V_9 . V_61 ) ;
V_47:
V_6 -> V_9 = V_9 ;
return 0 ;
V_54:
F_20 ( V_9 ) ;
V_51:
F_21 ( V_4 -> V_18 ) ;
V_49:
return V_42 ;
}
static void F_22 ( struct V_62 * V_63 )
{
F_23 (nf_ct_timeout_put_hook) V_64 ;
V_64 = F_24 ( V_65 ) ;
if ( V_64 )
V_64 ( V_63 ) ;
}
static int
F_25 ( struct V_8 * V_9 , const struct V_17 * V_4 ,
const char * V_66 )
{
#ifdef F_26
F_23 (nf_ct_timeout_find_get_hook) V_67 ;
struct V_62 * V_63 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_42 = 0 ;
T_1 V_26 ;
F_27 () ;
V_67 = F_24 ( V_72 ) ;
if ( V_67 == NULL ) {
V_42 = - V_36 ;
F_6 ( L_4 ) ;
goto V_47;
}
V_26 = F_4 ( V_4 ) ;
if ( ! V_26 ) {
V_42 = - V_46 ;
F_6 ( L_1
L_2 ) ;
goto V_47;
}
V_63 = V_67 ( V_66 ) ;
if ( V_63 == NULL ) {
V_42 = - V_36 ;
F_6 ( L_5 , V_66 ) ;
goto V_47;
}
if ( V_63 -> V_73 != V_4 -> V_18 ) {
V_42 = - V_46 ;
F_6 ( L_6
L_7 , V_66 , V_63 -> V_73 ) ;
goto V_74;
}
V_71 = F_28 ( V_4 -> V_18 , V_26 ) ;
if ( V_63 -> V_71 -> V_71 != V_71 -> V_71 ) {
V_42 = - V_46 ;
F_6 ( L_8
L_7 ,
V_66 , V_63 -> V_71 -> V_71 ) ;
goto V_74;
}
V_69 = F_29 ( V_9 , V_63 , V_75 ) ;
if ( V_69 == NULL )
V_42 = - V_39 ;
V_74:
F_22 ( V_63 ) ;
V_47:
F_30 () ;
return V_42 ;
#else
return - V_43 ;
#endif
}
static int F_31 ( const struct V_17 * V_4 )
{
struct V_16 * V_6 = V_4 -> V_7 ;
struct V_40 V_41 ;
struct V_8 * V_9 ;
int V_42 = - V_43 ;
if ( V_6 -> V_44 & ~ V_45 )
return - V_46 ;
if ( V_6 -> V_44 & V_45 ) {
V_9 = F_11 () ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
goto V_47;
}
#ifndef F_12
if ( V_6 -> V_48 )
goto V_49;
#endif
V_42 = F_13 ( V_4 -> V_18 ) ;
if ( V_42 < 0 )
goto V_49;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_9 = F_14 ( V_4 -> V_50 , V_6 -> V_48 , & V_41 , & V_41 , V_37 ) ;
V_42 = F_15 ( V_9 ) ;
if ( F_16 ( V_9 ) )
goto V_51;
V_42 = 0 ;
if ( ( V_6 -> V_52 || V_6 -> V_53 ) &&
! F_17 ( V_9 , V_6 -> V_52 , V_6 -> V_53 ,
V_37 ) )
goto V_54;
if ( V_6 -> V_33 [ 0 ] ) {
V_42 = F_5 ( V_9 , V_6 -> V_33 , V_4 ) ;
if ( V_42 < 0 )
goto V_54;
}
if ( V_6 -> V_63 [ 0 ] ) {
V_42 = F_25 ( V_9 , V_4 , V_6 -> V_63 ) ;
if ( V_42 < 0 )
goto V_54;
}
F_18 ( V_55 , & V_9 -> V_56 ) ;
F_18 ( V_57 , & V_9 -> V_56 ) ;
F_19 ( & V_9 -> V_58 [ V_59 ] . V_60 ,
& V_4 -> V_50 -> V_9 . V_61 ) ;
V_47:
V_6 -> V_9 = V_9 ;
return 0 ;
V_54:
F_20 ( V_9 ) ;
V_51:
F_21 ( V_4 -> V_18 ) ;
V_49:
return V_42 ;
}
static void F_32 ( const struct V_76 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_34 * V_35 ;
if ( ! F_33 ( V_9 ) ) {
V_35 = F_34 ( V_9 ) ;
if ( V_35 )
F_9 ( V_35 -> V_33 -> V_38 ) ;
F_21 ( V_4 -> V_18 ) ;
}
F_35 ( V_6 -> V_9 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
#ifdef F_26
struct V_68 * V_69 ;
F_23 (nf_ct_timeout_put_hook) V_64 ;
F_27 () ;
V_64 = F_24 ( V_65 ) ;
if ( V_64 ) {
V_69 = F_37 ( V_9 ) ;
if ( V_69 )
V_64 ( V_69 -> V_63 ) ;
}
F_30 () ;
#endif
}
static void F_38 ( const struct V_76 * V_4 )
{
struct V_16 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_34 * V_35 ;
if ( ! F_33 ( V_9 ) ) {
V_35 = F_34 ( V_9 ) ;
if ( V_35 )
F_9 ( V_35 -> V_33 -> V_38 ) ;
F_21 ( V_4 -> V_18 ) ;
F_36 ( V_9 ) ;
}
F_35 ( V_6 -> V_9 ) ;
}
static unsigned int
F_39 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( V_2 -> V_10 != NULL )
return V_11 ;
V_2 -> V_10 = & F_11 () -> V_12 ;
V_2 -> V_14 = V_15 ;
F_40 ( V_2 -> V_10 ) ;
return V_11 ;
}
static int F_41 ( const struct V_17 * V_4 )
{
if ( ! V_4 -> V_50 -> V_77 . V_78 ) {
F_6 ( L_9
L_10 ) ;
V_4 -> V_50 -> V_77 . V_78 = true ;
}
return 0 ;
}
static int T_2 F_42 ( void )
{
int V_42 ;
V_42 = F_43 ( & V_79 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_44 ( V_80 , F_45 ( V_80 ) ) ;
if ( V_42 < 0 ) {
F_46 ( & V_79 ) ;
return V_42 ;
}
return 0 ;
}
static void T_3 F_47 ( void )
{
F_48 ( V_80 , F_45 ( V_80 ) ) ;
F_46 ( & V_79 ) ;
}
