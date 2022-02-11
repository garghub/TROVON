static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 != 0 )
return V_6 ;
if ( ! V_4 )
V_4 = F_2 () ;
F_3 ( & V_4 -> V_7 . V_8 ) ;
F_4 ( V_2 , V_4 , V_9 ) ;
return V_6 ;
}
static unsigned int F_5 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
const struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 = V_13 -> V_4 ;
return F_1 ( V_2 , V_4 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
const struct V_15 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 = V_13 -> V_4 ;
return F_1 ( V_2 , V_4 ) ;
}
static T_1 F_7 ( const struct V_16 * V_11 )
{
if ( V_11 -> V_17 == V_18 ) {
const struct V_19 * V_20 = V_11 -> V_21 ;
if ( V_20 -> V_22 . V_23 & V_24 )
return 0 ;
return V_20 -> V_22 . V_25 ;
} else if ( V_11 -> V_17 == V_26 ) {
const struct V_27 * V_20 = V_11 -> V_21 ;
if ( V_20 -> V_28 . V_23 & V_29 )
return 0 ;
return V_20 -> V_28 . V_25 ;
} else
return 0 ;
}
static int
F_8 ( struct V_3 * V_4 , const char * V_30 ,
const struct V_16 * V_11 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_1 V_25 ;
V_25 = F_7 ( V_11 ) ;
if ( ! V_25 ) {
F_9 ( L_1
L_2 ) ;
return - V_35 ;
}
V_32 = F_10 ( V_30 , V_11 -> V_17 ,
V_25 ) ;
if ( V_32 == NULL ) {
F_9 ( L_3 , V_30 ) ;
return - V_35 ;
}
V_34 = F_11 ( V_4 , V_32 , V_36 ) ;
if ( V_34 == NULL ) {
F_12 ( V_32 -> V_37 ) ;
return - V_38 ;
}
V_34 -> V_32 = V_32 ;
return 0 ;
}
static void F_13 ( struct V_39 * V_40 )
{
F_14 (nf_ct_timeout_put_hook) V_41 ;
V_41 = F_15 ( V_42 ) ;
if ( V_41 )
V_41 ( V_40 ) ;
}
static int
F_16 ( struct V_3 * V_4 , const struct V_16 * V_11 ,
const char * V_43 )
{
#ifdef F_17
F_14 (nf_ct_timeout_find_get_hook) V_44 ;
struct V_39 * V_40 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_49 = 0 ;
T_1 V_25 ;
F_18 () ;
V_44 = F_15 ( V_50 ) ;
if ( V_44 == NULL ) {
V_49 = - V_35 ;
F_9 ( L_4 ) ;
goto V_51;
}
V_25 = F_7 ( V_11 ) ;
if ( ! V_25 ) {
V_49 = - V_52 ;
F_9 ( L_1
L_2 ) ;
goto V_51;
}
V_40 = V_44 ( V_11 -> V_53 , V_43 ) ;
if ( V_40 == NULL ) {
V_49 = - V_35 ;
F_9 ( L_5 , V_43 ) ;
goto V_51;
}
if ( V_40 -> V_54 != V_11 -> V_17 ) {
V_49 = - V_52 ;
F_9 ( L_6
L_7 , V_43 , V_40 -> V_54 ) ;
goto V_55;
}
V_48 = F_19 ( V_11 -> V_17 , V_25 ) ;
if ( V_40 -> V_48 -> V_48 != V_48 -> V_48 ) {
V_49 = - V_52 ;
F_9 ( L_8
L_7 ,
V_43 , V_40 -> V_48 -> V_48 ) ;
goto V_55;
}
V_46 = F_20 ( V_4 , V_40 , V_56 ) ;
if ( V_46 == NULL )
V_49 = - V_38 ;
F_21 () ;
return V_49 ;
V_55:
F_13 ( V_40 ) ;
V_51:
F_21 () ;
return V_49 ;
#else
return - V_57 ;
#endif
}
static T_2 F_22 ( const struct V_15 * V_13 )
{
switch ( V_13 -> V_58 & ( V_59 |
V_60 ) ) {
case V_59 :
return V_61 ;
case V_60 :
return V_62 ;
default:
return V_63 ;
}
}
static int F_23 ( const struct V_16 * V_11 ,
struct V_15 * V_13 )
{
struct V_64 V_65 ;
struct V_3 * V_4 ;
int V_49 = - V_57 ;
if ( V_13 -> V_58 & V_66 ) {
V_4 = NULL ;
goto V_51;
}
#ifndef F_24
if ( V_13 -> V_65 || V_13 -> V_58 & ( V_59 |
V_60 |
V_67 ) )
goto V_68;
#endif
V_49 = F_25 ( V_11 -> V_53 , V_11 -> V_17 ) ;
if ( V_49 < 0 )
goto V_68;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_69 = V_13 -> V_65 ;
V_65 . V_70 = F_22 ( V_13 ) ;
if ( V_13 -> V_58 & V_67 )
V_65 . V_58 |= V_71 ;
V_4 = F_26 ( V_11 -> V_53 , & V_65 , V_36 ) ;
if ( ! V_4 ) {
V_49 = - V_38 ;
goto V_72;
}
V_49 = 0 ;
if ( ( V_13 -> V_73 || V_13 -> V_74 ) &&
! F_27 ( V_4 , V_13 -> V_73 , V_13 -> V_74 ,
V_36 ) ) {
V_49 = - V_52 ;
goto V_75;
}
if ( V_13 -> V_32 [ 0 ] ) {
V_49 = F_8 ( V_4 , V_13 -> V_32 , V_11 ) ;
if ( V_49 < 0 )
goto V_75;
}
if ( V_13 -> V_40 [ 0 ] ) {
V_49 = F_16 ( V_4 , V_11 , V_13 -> V_40 ) ;
if ( V_49 < 0 )
goto V_75;
}
F_28 ( V_76 , & V_4 -> V_77 ) ;
F_29 ( & V_4 -> V_7 ) ;
V_51:
V_13 -> V_4 = V_4 ;
return 0 ;
V_75:
F_30 ( V_4 ) ;
V_72:
F_31 ( V_11 -> V_53 , V_11 -> V_17 ) ;
V_68:
return V_49 ;
}
static int F_32 ( const struct V_16 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 V_78 = {
. V_58 = V_13 -> V_58 ,
. V_65 = V_13 -> V_65 ,
. V_73 = V_13 -> V_73 ,
. V_74 = V_13 -> V_74 ,
} ;
int V_49 ;
if ( V_13 -> V_58 & ~ V_66 )
return - V_52 ;
memcpy ( V_78 . V_32 , V_13 -> V_32 , sizeof( V_13 -> V_32 ) ) ;
V_49 = F_23 ( V_11 , & V_78 ) ;
if ( V_49 < 0 )
return V_49 ;
V_13 -> V_4 = V_78 . V_4 ;
return V_49 ;
}
static int F_33 ( const struct V_16 * V_11 )
{
struct V_15 * V_13 = V_11 -> V_14 ;
if ( V_13 -> V_58 & ~ V_66 )
return - V_52 ;
return F_23 ( V_11 , V_11 -> V_14 ) ;
}
static int F_34 ( const struct V_16 * V_11 )
{
struct V_15 * V_13 = V_11 -> V_14 ;
if ( V_13 -> V_58 & ~ V_79 )
return - V_52 ;
return F_23 ( V_11 , V_11 -> V_14 ) ;
}
static void F_35 ( struct V_3 * V_4 )
{
#ifdef F_17
struct V_45 * V_46 ;
F_14 (nf_ct_timeout_put_hook) V_41 ;
F_18 () ;
V_41 = F_15 ( V_42 ) ;
if ( V_41 ) {
V_46 = F_36 ( V_4 ) ;
if ( V_46 ) {
V_41 ( V_46 -> V_40 ) ;
F_37 ( V_46 -> V_40 , NULL ) ;
}
}
F_21 () ;
#endif
}
static void F_38 ( const struct V_80 * V_11 ,
struct V_15 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_4 ;
struct V_33 * V_34 ;
if ( V_4 && ! F_39 ( V_4 ) ) {
V_34 = F_40 ( V_4 ) ;
if ( V_34 )
F_12 ( V_34 -> V_32 -> V_37 ) ;
F_31 ( V_11 -> V_53 , V_11 -> V_17 ) ;
F_35 ( V_4 ) ;
F_41 ( V_13 -> V_4 ) ;
}
}
static void F_42 ( const struct V_80 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 V_78 = {
. V_58 = V_13 -> V_58 ,
. V_65 = V_13 -> V_65 ,
. V_73 = V_13 -> V_73 ,
. V_74 = V_13 -> V_74 ,
. V_4 = V_13 -> V_4 ,
} ;
memcpy ( V_78 . V_32 , V_13 -> V_32 , sizeof( V_13 -> V_32 ) ) ;
F_38 ( V_11 , & V_78 ) ;
}
static void F_43 ( const struct V_80 * V_11 )
{
F_38 ( V_11 , V_11 -> V_14 ) ;
}
static unsigned int
F_44 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
if ( V_2 -> V_5 != 0 )
return V_6 ;
F_4 ( V_2 , F_2 () , V_9 ) ;
F_29 ( F_45 ( V_2 ) ) ;
return V_6 ;
}
static int F_46 ( const struct V_16 * V_11 )
{
if ( ! V_11 -> V_53 -> V_81 . V_82 ) {
F_9 ( L_9
L_10 ) ;
V_11 -> V_53 -> V_81 . V_82 = true ;
}
return 0 ;
}
static int T_3 F_47 ( void )
{
int V_49 ;
V_49 = F_48 ( & V_83 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_49 ( V_84 , F_50 ( V_84 ) ) ;
if ( V_49 < 0 ) {
F_51 ( & V_83 ) ;
return V_49 ;
}
return 0 ;
}
static void T_4 F_52 ( void )
{
F_53 ( V_84 , F_50 ( V_84 ) ) ;
F_51 ( & V_83 ) ;
}
