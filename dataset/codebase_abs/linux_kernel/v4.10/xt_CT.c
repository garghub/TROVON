static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 != NULL )
return V_6 ;
if ( ! V_4 )
V_4 = F_2 () ;
F_3 ( & V_4 -> V_7 . V_8 ) ;
V_2 -> V_5 = & V_4 -> V_7 ;
V_2 -> V_9 = V_10 ;
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
F_11 ( V_33 -> V_38 ) ;
return - V_39 ;
}
V_35 -> V_33 = V_33 ;
return 0 ;
}
static void F_12 ( struct V_40 * V_41 )
{
F_13 (nf_ct_timeout_put_hook) V_42 ;
V_42 = F_14 ( V_43 ) ;
if ( V_42 )
V_42 ( V_41 ) ;
}
static int
F_15 ( struct V_3 * V_4 , const struct V_17 * V_12 ,
const char * V_44 )
{
#ifdef F_16
F_13 (nf_ct_timeout_find_get_hook) V_45 ;
struct V_40 * V_41 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 = 0 ;
T_1 V_26 ;
F_17 () ;
V_45 = F_14 ( V_51 ) ;
if ( V_45 == NULL ) {
V_50 = - V_36 ;
F_8 ( L_4 ) ;
goto V_52;
}
V_26 = F_6 ( V_12 ) ;
if ( ! V_26 ) {
V_50 = - V_53 ;
F_8 ( L_1
L_2 ) ;
goto V_52;
}
V_41 = V_45 ( V_12 -> V_54 , V_44 ) ;
if ( V_41 == NULL ) {
V_50 = - V_36 ;
F_8 ( L_5 , V_44 ) ;
goto V_52;
}
if ( V_41 -> V_55 != V_12 -> V_18 ) {
V_50 = - V_53 ;
F_8 ( L_6
L_7 , V_44 , V_41 -> V_55 ) ;
goto V_56;
}
V_49 = F_18 ( V_12 -> V_18 , V_26 ) ;
if ( V_41 -> V_49 -> V_49 != V_49 -> V_49 ) {
V_50 = - V_53 ;
F_8 ( L_8
L_7 ,
V_44 , V_41 -> V_49 -> V_49 ) ;
goto V_56;
}
V_47 = F_19 ( V_4 , V_41 , V_57 ) ;
if ( V_47 == NULL )
V_50 = - V_39 ;
F_20 () ;
return V_50 ;
V_56:
F_12 ( V_41 ) ;
V_52:
F_20 () ;
return V_50 ;
#else
return - V_58 ;
#endif
}
static T_2 F_21 ( const struct V_16 * V_14 )
{
switch ( V_14 -> V_59 & ( V_60 |
V_61 ) ) {
case V_60 :
return V_62 ;
case V_61 :
return V_63 ;
default:
return V_64 ;
}
}
static int F_22 ( const struct V_17 * V_12 ,
struct V_16 * V_14 )
{
struct V_65 V_66 ;
struct V_3 * V_4 ;
int V_50 = - V_58 ;
if ( V_14 -> V_59 & V_67 ) {
V_4 = NULL ;
goto V_52;
}
#ifndef F_23
if ( V_14 -> V_66 || V_14 -> V_59 & ( V_60 |
V_61 |
V_68 ) )
goto V_69;
#endif
V_50 = F_24 ( V_12 -> V_54 , V_12 -> V_18 ) ;
if ( V_50 < 0 )
goto V_69;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_70 = V_14 -> V_66 ;
V_66 . V_71 = F_21 ( V_14 ) ;
if ( V_14 -> V_59 & V_68 )
V_66 . V_59 |= V_72 ;
V_4 = F_25 ( V_12 -> V_54 , & V_66 , V_37 ) ;
if ( ! V_4 ) {
V_50 = - V_39 ;
goto V_73;
}
V_50 = 0 ;
if ( ( V_14 -> V_74 || V_14 -> V_75 ) &&
! F_26 ( V_4 , V_14 -> V_74 , V_14 -> V_75 ,
V_37 ) ) {
V_50 = - V_53 ;
goto V_76;
}
if ( V_14 -> V_33 [ 0 ] ) {
V_50 = F_7 ( V_4 , V_14 -> V_33 , V_12 ) ;
if ( V_50 < 0 )
goto V_76;
}
if ( V_14 -> V_41 [ 0 ] ) {
V_50 = F_15 ( V_4 , V_12 , V_14 -> V_41 ) ;
if ( V_50 < 0 )
goto V_76;
}
F_27 ( V_77 , & V_4 -> V_78 ) ;
F_28 ( & V_4 -> V_7 ) ;
V_52:
V_14 -> V_4 = V_4 ;
return 0 ;
V_76:
F_29 ( V_4 ) ;
V_73:
F_30 ( V_12 -> V_54 , V_12 -> V_18 ) ;
V_69:
return V_50 ;
}
static int F_31 ( const struct V_17 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 V_79 = {
. V_59 = V_14 -> V_59 ,
. V_66 = V_14 -> V_66 ,
. V_74 = V_14 -> V_74 ,
. V_75 = V_14 -> V_75 ,
} ;
int V_50 ;
if ( V_14 -> V_59 & ~ V_67 )
return - V_53 ;
memcpy ( V_79 . V_33 , V_14 -> V_33 , sizeof( V_14 -> V_33 ) ) ;
V_50 = F_22 ( V_12 , & V_79 ) ;
if ( V_50 < 0 )
return V_50 ;
V_14 -> V_4 = V_79 . V_4 ;
return V_50 ;
}
static int F_32 ( const struct V_17 * V_12 )
{
struct V_16 * V_14 = V_12 -> V_15 ;
if ( V_14 -> V_59 & ~ V_67 )
return - V_53 ;
return F_22 ( V_12 , V_12 -> V_15 ) ;
}
static int F_33 ( const struct V_17 * V_12 )
{
struct V_16 * V_14 = V_12 -> V_15 ;
if ( V_14 -> V_59 & ~ V_80 )
return - V_53 ;
return F_22 ( V_12 , V_12 -> V_15 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
#ifdef F_16
struct V_46 * V_47 ;
F_13 (nf_ct_timeout_put_hook) V_42 ;
F_17 () ;
V_42 = F_14 ( V_43 ) ;
if ( V_42 ) {
V_47 = F_35 ( V_4 ) ;
if ( V_47 ) {
V_42 ( V_47 -> V_41 ) ;
F_36 ( V_47 -> V_41 , NULL ) ;
}
}
F_20 () ;
#endif
}
static void F_37 ( const struct V_81 * V_12 ,
struct V_16 * V_14 )
{
struct V_3 * V_4 = V_14 -> V_4 ;
struct V_34 * V_35 ;
if ( V_4 && ! F_38 ( V_4 ) ) {
V_35 = F_39 ( V_4 ) ;
if ( V_35 )
F_11 ( V_35 -> V_33 -> V_38 ) ;
F_30 ( V_12 -> V_54 , V_12 -> V_18 ) ;
F_34 ( V_4 ) ;
F_40 ( V_14 -> V_4 ) ;
}
}
static void F_41 ( const struct V_81 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 V_79 = {
. V_59 = V_14 -> V_59 ,
. V_66 = V_14 -> V_66 ,
. V_74 = V_14 -> V_74 ,
. V_75 = V_14 -> V_75 ,
. V_4 = V_14 -> V_4 ,
} ;
memcpy ( V_79 . V_33 , V_14 -> V_33 , sizeof( V_14 -> V_33 ) ) ;
F_37 ( V_12 , & V_79 ) ;
}
static void F_42 ( const struct V_81 * V_12 )
{
F_37 ( V_12 , V_12 -> V_15 ) ;
}
static unsigned int
F_43 ( struct V_1 * V_2 , const struct V_11 * V_12 )
{
if ( V_2 -> V_5 != NULL )
return V_6 ;
V_2 -> V_5 = & F_2 () -> V_7 ;
V_2 -> V_9 = V_10 ;
F_28 ( V_2 -> V_5 ) ;
return V_6 ;
}
static int F_44 ( const struct V_17 * V_12 )
{
if ( ! V_12 -> V_54 -> V_82 . V_83 ) {
F_8 ( L_9
L_10 ) ;
V_12 -> V_54 -> V_82 . V_83 = true ;
}
return 0 ;
}
static int T_3 F_45 ( void )
{
int V_50 ;
V_50 = F_46 ( & V_84 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_47 ( V_85 , F_48 ( V_85 ) ) ;
if ( V_50 < 0 ) {
F_49 ( & V_84 ) ;
return V_50 ;
}
return 0 ;
}
static void T_4 F_50 ( void )
{
F_51 ( V_85 , F_48 ( V_85 ) ) ;
F_49 ( & V_84 ) ;
}
