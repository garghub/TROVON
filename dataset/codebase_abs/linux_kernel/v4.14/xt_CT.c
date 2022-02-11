static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 != 0 )
return V_6 ;
if ( V_4 ) {
F_2 ( & V_4 -> V_7 . V_8 ) ;
F_3 ( V_2 , V_4 , V_9 ) ;
} else {
F_3 ( V_2 , V_4 , V_10 ) ;
}
return V_6 ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
const struct V_13 * V_14 = V_12 -> V_15 ;
struct V_3 * V_4 = V_14 -> V_4 ;
return F_1 ( V_2 , V_4 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
const struct V_16 * V_14 = V_12 -> V_15 ;
struct V_3 * V_4 = V_14 -> V_4 ;
return F_1 ( V_2 , V_4 ) ;
}
static T_1 F_6 ( const struct V_17 * V_12 )
{
if ( V_12 -> V_18 == V_19 ) {
const struct V_20 * V_21 = V_12 -> V_22 ;
if ( V_21 -> V_23 . V_24 & V_25 )
return 0 ;
return V_21 -> V_23 . V_26 ;
} else if ( V_12 -> V_18 == V_27 ) {
const struct V_28 * V_21 = V_12 -> V_22 ;
if ( V_21 -> V_29 . V_24 & V_30 )
return 0 ;
return V_21 -> V_29 . V_26 ;
} else
return 0 ;
}
static int
F_7 ( struct V_3 * V_4 , const char * V_31 ,
const struct V_17 * V_12 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_1 V_26 ;
V_26 = F_6 ( V_12 ) ;
if ( ! V_26 ) {
F_8 ( L_1
L_2 ) ;
return - V_36 ;
}
V_33 = F_9 ( V_31 , V_12 -> V_18 ,
V_26 ) ;
if ( V_33 == NULL ) {
F_8 ( L_3 , V_31 ) ;
return - V_36 ;
}
V_35 = F_10 ( V_4 , V_33 , V_37 ) ;
if ( V_35 == NULL ) {
F_11 ( V_33 ) ;
return - V_38 ;
}
V_35 -> V_33 = V_33 ;
return 0 ;
}
static void F_12 ( struct V_39 * V_40 )
{
F_13 (nf_ct_timeout_put_hook) V_41 ;
V_41 = F_14 ( V_42 ) ;
if ( V_41 )
V_41 ( V_40 ) ;
}
static int
F_15 ( struct V_3 * V_4 , const struct V_17 * V_12 ,
const char * V_43 )
{
#ifdef F_16
F_13 (nf_ct_timeout_find_get_hook) V_44 ;
const struct V_45 * V_46 ;
struct V_39 * V_40 ;
struct V_47 * V_48 ;
int V_49 = 0 ;
T_1 V_26 ;
F_17 () ;
V_44 = F_14 ( V_50 ) ;
if ( V_44 == NULL ) {
V_49 = - V_36 ;
F_8 ( L_4 ) ;
goto V_51;
}
V_26 = F_6 ( V_12 ) ;
if ( ! V_26 ) {
V_49 = - V_52 ;
F_8 ( L_1
L_2 ) ;
goto V_51;
}
V_40 = V_44 ( V_12 -> V_53 , V_43 ) ;
if ( V_40 == NULL ) {
V_49 = - V_36 ;
F_8 ( L_5 , V_43 ) ;
goto V_51;
}
if ( V_40 -> V_54 != V_12 -> V_18 ) {
V_49 = - V_52 ;
F_8 ( L_6
L_7 , V_43 , V_40 -> V_54 ) ;
goto V_55;
}
V_46 = F_18 ( V_12 -> V_18 , V_26 ) ;
if ( V_40 -> V_46 -> V_46 != V_46 -> V_46 ) {
V_49 = - V_52 ;
F_8 ( L_8
L_7 ,
V_43 , V_40 -> V_46 -> V_46 ) ;
goto V_55;
}
V_48 = F_19 ( V_4 , V_40 , V_56 ) ;
if ( ! V_48 ) {
V_49 = - V_38 ;
goto V_55;
}
F_20 () ;
return V_49 ;
V_55:
F_12 ( V_40 ) ;
V_51:
F_20 () ;
return V_49 ;
#else
return - V_57 ;
#endif
}
static T_2 F_21 ( const struct V_16 * V_14 )
{
switch ( V_14 -> V_58 & ( V_59 |
V_60 ) ) {
case V_59 :
return V_61 ;
case V_60 :
return V_62 ;
default:
return V_63 ;
}
}
static int F_22 ( const struct V_17 * V_12 ,
struct V_16 * V_14 )
{
struct V_64 V_65 ;
struct V_34 * V_35 ;
struct V_3 * V_4 ;
int V_49 = - V_57 ;
if ( V_14 -> V_58 & V_66 ) {
V_4 = NULL ;
goto V_51;
}
#ifndef F_23
if ( V_14 -> V_65 || V_14 -> V_58 & ( V_59 |
V_60 |
V_67 ) )
goto V_68;
#endif
V_49 = F_24 ( V_12 -> V_53 , V_12 -> V_18 ) ;
if ( V_49 < 0 )
goto V_68;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_69 = V_14 -> V_65 ;
V_65 . V_70 = F_21 ( V_14 ) ;
if ( V_14 -> V_58 & V_67 )
V_65 . V_58 |= V_71 ;
V_4 = F_25 ( V_12 -> V_53 , & V_65 , V_37 ) ;
if ( ! V_4 ) {
V_49 = - V_38 ;
goto V_72;
}
V_49 = 0 ;
if ( ( V_14 -> V_73 || V_14 -> V_74 ) &&
! F_26 ( V_4 , V_14 -> V_73 , V_14 -> V_74 ,
V_37 ) ) {
V_49 = - V_52 ;
goto V_75;
}
if ( V_14 -> V_33 [ 0 ] ) {
V_49 = F_7 ( V_4 , V_14 -> V_33 , V_12 ) ;
if ( V_49 < 0 )
goto V_75;
}
if ( V_14 -> V_40 [ 0 ] ) {
V_49 = F_15 ( V_4 , V_12 , V_14 -> V_40 ) ;
if ( V_49 < 0 )
goto V_76;
}
F_27 ( V_77 , & V_4 -> V_78 ) ;
F_28 ( & V_4 -> V_7 ) ;
V_51:
V_14 -> V_4 = V_4 ;
return 0 ;
V_76:
V_35 = F_29 ( V_4 ) ;
if ( V_35 )
F_11 ( V_35 -> V_33 ) ;
V_75:
F_30 ( V_4 ) ;
V_72:
F_31 ( V_12 -> V_53 , V_12 -> V_18 ) ;
V_68:
return V_49 ;
}
static int F_32 ( const struct V_17 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 V_79 = {
. V_58 = V_14 -> V_58 ,
. V_65 = V_14 -> V_65 ,
. V_73 = V_14 -> V_73 ,
. V_74 = V_14 -> V_74 ,
} ;
int V_49 ;
if ( V_14 -> V_58 & ~ V_66 )
return - V_52 ;
memcpy ( V_79 . V_33 , V_14 -> V_33 , sizeof( V_14 -> V_33 ) ) ;
V_49 = F_22 ( V_12 , & V_79 ) ;
if ( V_49 < 0 )
return V_49 ;
V_14 -> V_4 = V_79 . V_4 ;
return V_49 ;
}
static int F_33 ( const struct V_17 * V_12 )
{
struct V_16 * V_14 = V_12 -> V_15 ;
if ( V_14 -> V_58 & ~ V_66 )
return - V_52 ;
return F_22 ( V_12 , V_12 -> V_15 ) ;
}
static int F_34 ( const struct V_17 * V_12 )
{
struct V_16 * V_14 = V_12 -> V_15 ;
if ( V_14 -> V_58 & ~ V_80 )
return - V_52 ;
return F_22 ( V_12 , V_12 -> V_15 ) ;
}
static void F_35 ( struct V_3 * V_4 )
{
#ifdef F_16
struct V_47 * V_48 ;
F_13 (nf_ct_timeout_put_hook) V_41 ;
F_17 () ;
V_41 = F_14 ( V_42 ) ;
if ( V_41 ) {
V_48 = F_36 ( V_4 ) ;
if ( V_48 ) {
V_41 ( V_48 -> V_40 ) ;
F_37 ( V_48 -> V_40 , NULL ) ;
}
}
F_20 () ;
#endif
}
static void F_38 ( const struct V_81 * V_12 ,
struct V_16 * V_14 )
{
struct V_3 * V_4 = V_14 -> V_4 ;
struct V_34 * V_35 ;
if ( V_4 ) {
V_35 = F_29 ( V_4 ) ;
if ( V_35 )
F_11 ( V_35 -> V_33 ) ;
F_31 ( V_12 -> V_53 , V_12 -> V_18 ) ;
F_35 ( V_4 ) ;
F_39 ( V_14 -> V_4 ) ;
}
}
static void F_40 ( const struct V_81 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 V_79 = {
. V_58 = V_14 -> V_58 ,
. V_65 = V_14 -> V_65 ,
. V_73 = V_14 -> V_73 ,
. V_74 = V_14 -> V_74 ,
. V_4 = V_14 -> V_4 ,
} ;
memcpy ( V_79 . V_33 , V_14 -> V_33 , sizeof( V_14 -> V_33 ) ) ;
F_38 ( V_12 , & V_79 ) ;
}
static void F_41 ( const struct V_81 * V_12 )
{
F_38 ( V_12 , V_12 -> V_15 ) ;
}
static unsigned int
F_42 ( struct V_1 * V_2 , const struct V_11 * V_12 )
{
if ( V_2 -> V_5 != 0 )
return V_6 ;
F_3 ( V_2 , NULL , V_10 ) ;
return V_6 ;
}
static int F_43 ( const struct V_17 * V_12 )
{
if ( ! V_12 -> V_53 -> V_82 . V_83 ) {
F_8 ( L_9
L_10 ) ;
V_12 -> V_53 -> V_82 . V_83 = true ;
}
return 0 ;
}
static int T_3 F_44 ( void )
{
int V_49 ;
V_49 = F_45 ( & V_84 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_46 ( V_85 , F_47 ( V_85 ) ) ;
if ( V_49 < 0 ) {
F_48 ( & V_84 ) ;
return V_49 ;
}
return 0 ;
}
static void T_4 F_49 ( void )
{
F_50 ( V_85 , F_47 ( V_85 ) ) ;
F_48 ( & V_84 ) ;
}
