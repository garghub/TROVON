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
int V_42 ;
if ( V_6 -> V_43 & ~ V_44 )
return - V_45 ;
if ( V_6 -> V_43 & V_44 ) {
V_9 = F_11 () ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
goto V_46;
}
#ifndef F_12
if ( V_6 -> V_47 )
goto V_48;
#endif
V_42 = F_13 ( V_4 -> V_18 ) ;
if ( V_42 < 0 )
goto V_48;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_9 = F_14 ( V_4 -> V_49 , V_6 -> V_47 , & V_41 , & V_41 , V_37 ) ;
V_42 = F_15 ( V_9 ) ;
if ( F_16 ( V_9 ) )
goto V_50;
V_42 = 0 ;
if ( ( V_6 -> V_51 || V_6 -> V_52 ) &&
! F_17 ( V_9 , V_6 -> V_51 , V_6 -> V_52 ,
V_37 ) )
goto V_53;
if ( V_6 -> V_33 [ 0 ] ) {
V_42 = F_5 ( V_9 , V_6 -> V_33 , V_4 ) ;
if ( V_42 < 0 )
goto V_53;
}
F_18 ( V_54 , & V_9 -> V_55 ) ;
F_18 ( V_56 , & V_9 -> V_55 ) ;
V_46:
V_6 -> V_9 = V_9 ;
return 0 ;
V_53:
F_19 ( V_9 ) ;
V_50:
F_20 ( V_4 -> V_18 ) ;
V_48:
return V_42 ;
}
static void F_21 ( struct V_57 * V_58 )
{
F_22 (nf_ct_timeout_put_hook) V_59 ;
V_59 = F_23 ( V_60 ) ;
if ( V_59 )
V_59 ( V_58 ) ;
}
static int
F_24 ( struct V_8 * V_9 , const struct V_17 * V_4 ,
const char * V_61 )
{
#ifdef F_25
F_22 (nf_ct_timeout_find_get_hook) V_62 ;
struct V_57 * V_58 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int V_42 = 0 ;
T_1 V_26 ;
F_26 () ;
V_62 = F_23 ( V_67 ) ;
if ( V_62 == NULL ) {
V_42 = - V_36 ;
F_6 ( L_4 ) ;
goto V_46;
}
V_26 = F_4 ( V_4 ) ;
if ( ! V_26 ) {
V_42 = - V_45 ;
F_6 ( L_1
L_2 ) ;
goto V_46;
}
V_58 = V_62 ( V_61 ) ;
if ( V_58 == NULL ) {
V_42 = - V_36 ;
F_6 ( L_5 , V_61 ) ;
goto V_46;
}
if ( V_58 -> V_68 != V_4 -> V_18 ) {
V_42 = - V_45 ;
F_6 ( L_6
L_7 , V_61 , V_58 -> V_68 ) ;
goto V_69;
}
V_66 = F_27 ( V_4 -> V_18 , V_26 ) ;
if ( V_58 -> V_66 -> V_66 != V_66 -> V_66 ) {
V_42 = - V_45 ;
F_6 ( L_8
L_7 ,
V_61 , V_58 -> V_66 -> V_66 ) ;
goto V_69;
}
V_64 = F_28 ( V_9 , V_58 , V_70 ) ;
if ( V_64 == NULL )
V_42 = - V_39 ;
V_69:
F_21 ( V_58 ) ;
V_46:
F_29 () ;
return V_42 ;
#else
return - V_71 ;
#endif
}
static int F_30 ( const struct V_17 * V_4 )
{
struct V_16 * V_6 = V_4 -> V_7 ;
struct V_40 V_41 ;
struct V_8 * V_9 ;
int V_42 ;
if ( V_6 -> V_43 & ~ V_44 )
return - V_45 ;
if ( V_6 -> V_43 & V_44 ) {
V_9 = F_11 () ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
goto V_46;
}
#ifndef F_12
if ( V_6 -> V_47 )
goto V_48;
#endif
V_42 = F_13 ( V_4 -> V_18 ) ;
if ( V_42 < 0 )
goto V_48;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_9 = F_14 ( V_4 -> V_49 , V_6 -> V_47 , & V_41 , & V_41 , V_37 ) ;
V_42 = F_15 ( V_9 ) ;
if ( F_16 ( V_9 ) )
goto V_50;
V_42 = 0 ;
if ( ( V_6 -> V_51 || V_6 -> V_52 ) &&
! F_17 ( V_9 , V_6 -> V_51 , V_6 -> V_52 ,
V_37 ) )
goto V_53;
if ( V_6 -> V_33 [ 0 ] ) {
V_42 = F_5 ( V_9 , V_6 -> V_33 , V_4 ) ;
if ( V_42 < 0 )
goto V_53;
}
if ( V_6 -> V_58 [ 0 ] ) {
V_42 = F_24 ( V_9 , V_4 , V_6 -> V_58 ) ;
if ( V_42 < 0 )
goto V_53;
}
F_18 ( V_54 , & V_9 -> V_55 ) ;
F_18 ( V_56 , & V_9 -> V_55 ) ;
V_46:
V_6 -> V_9 = V_9 ;
return 0 ;
V_53:
F_19 ( V_9 ) ;
V_50:
F_20 ( V_4 -> V_18 ) ;
V_48:
return V_42 ;
}
static void F_31 ( const struct V_72 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_34 * V_35 ;
if ( ! F_32 ( V_9 ) ) {
V_35 = F_33 ( V_9 ) ;
if ( V_35 )
F_9 ( V_35 -> V_33 -> V_38 ) ;
F_20 ( V_4 -> V_18 ) ;
}
F_34 ( V_6 -> V_9 ) ;
}
static void F_35 ( struct V_8 * V_9 )
{
#ifdef F_25
struct V_63 * V_64 ;
F_22 (nf_ct_timeout_put_hook) V_59 ;
F_26 () ;
V_59 = F_23 ( V_60 ) ;
if ( V_59 ) {
V_64 = F_36 ( V_9 ) ;
if ( V_64 )
V_59 ( V_64 -> V_58 ) ;
}
F_29 () ;
#endif
}
static void F_37 ( const struct V_72 * V_4 )
{
struct V_16 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_34 * V_35 ;
if ( ! F_32 ( V_9 ) ) {
V_35 = F_33 ( V_9 ) ;
if ( V_35 )
F_9 ( V_35 -> V_33 -> V_38 ) ;
F_20 ( V_4 -> V_18 ) ;
F_35 ( V_9 ) ;
}
F_34 ( V_6 -> V_9 ) ;
}
static int T_2 F_38 ( void )
{
return F_39 ( V_73 , F_40 ( V_73 ) ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( V_73 , F_40 ( V_73 ) ) ;
}
