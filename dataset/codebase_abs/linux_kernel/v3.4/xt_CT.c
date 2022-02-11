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
static int F_5 ( const struct V_17 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_31 V_32 ;
struct V_33 * V_34 ;
struct V_8 * V_9 ;
int V_35 = 0 ;
T_1 V_26 ;
if ( V_6 -> V_36 & ~ V_37 )
return - V_38 ;
if ( V_6 -> V_36 & V_37 ) {
V_9 = F_6 () ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
goto V_39;
}
#ifndef F_7
if ( V_6 -> V_40 )
goto V_41;
#endif
V_35 = F_8 ( V_4 -> V_18 ) ;
if ( V_35 < 0 )
goto V_41;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_9 = F_9 ( V_4 -> V_42 , V_6 -> V_40 , & V_32 , & V_32 , V_43 ) ;
V_35 = F_10 ( V_9 ) ;
if ( F_11 ( V_9 ) )
goto V_44;
V_35 = 0 ;
if ( ( V_6 -> V_45 || V_6 -> V_46 ) &&
! F_12 ( V_9 , V_6 -> V_45 , V_6 -> V_46 ,
V_43 ) )
goto V_47;
if ( V_6 -> V_48 [ 0 ] ) {
V_35 = - V_49 ;
V_26 = F_4 ( V_4 ) ;
if ( ! V_26 ) {
F_13 ( L_1
L_2 ) ;
goto V_47;
}
V_35 = - V_50 ;
V_34 = F_14 ( V_9 , V_43 ) ;
if ( V_34 == NULL )
goto V_47;
V_35 = - V_49 ;
V_34 -> V_48 = F_15 ( V_6 -> V_48 ,
V_4 -> V_18 ,
V_26 ) ;
if ( V_34 -> V_48 == NULL ) {
F_13 ( L_3 , V_6 -> V_48 ) ;
goto V_47;
}
}
F_16 ( V_51 , & V_9 -> V_52 ) ;
F_16 ( V_53 , & V_9 -> V_52 ) ;
V_39:
V_6 -> V_9 = V_9 ;
return 0 ;
V_47:
F_17 ( V_9 ) ;
V_44:
F_18 ( V_4 -> V_18 ) ;
V_41:
return V_35 ;
}
static void F_19 ( struct V_54 * V_55 )
{
F_20 (nf_ct_timeout_put_hook) V_56 ;
V_56 = F_21 ( V_57 ) ;
if ( V_56 )
V_56 ( V_55 ) ;
}
static int F_22 ( const struct V_17 * V_4 )
{
struct V_16 * V_6 = V_4 -> V_7 ;
struct V_31 V_32 ;
struct V_33 * V_34 ;
struct V_8 * V_9 ;
int V_35 = 0 ;
T_1 V_26 ;
#ifdef F_23
struct V_54 * V_55 ;
#endif
if ( V_6 -> V_36 & ~ V_37 )
return - V_38 ;
if ( V_6 -> V_36 & V_37 ) {
V_9 = F_6 () ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
goto V_39;
}
#ifndef F_7
if ( V_6 -> V_40 )
goto V_41;
#endif
V_35 = F_8 ( V_4 -> V_18 ) ;
if ( V_35 < 0 )
goto V_41;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_9 = F_9 ( V_4 -> V_42 , V_6 -> V_40 , & V_32 , & V_32 , V_43 ) ;
V_35 = F_10 ( V_9 ) ;
if ( F_11 ( V_9 ) )
goto V_44;
V_35 = 0 ;
if ( ( V_6 -> V_45 || V_6 -> V_46 ) &&
! F_12 ( V_9 , V_6 -> V_45 , V_6 -> V_46 ,
V_43 ) )
goto V_47;
if ( V_6 -> V_48 [ 0 ] ) {
V_35 = - V_49 ;
V_26 = F_4 ( V_4 ) ;
if ( ! V_26 ) {
F_13 ( L_1
L_2 ) ;
goto V_47;
}
V_35 = - V_50 ;
V_34 = F_14 ( V_9 , V_43 ) ;
if ( V_34 == NULL )
goto V_47;
V_35 = - V_49 ;
V_34 -> V_48 = F_15 ( V_6 -> V_48 ,
V_4 -> V_18 ,
V_26 ) ;
if ( V_34 -> V_48 == NULL ) {
F_13 ( L_3 , V_6 -> V_48 ) ;
goto V_47;
}
}
#ifdef F_23
if ( V_6 -> V_55 [ 0 ] ) {
F_20 (nf_ct_timeout_find_get_hook) V_58 ;
struct V_59 * V_60 ;
F_24 () ;
V_58 =
F_21 ( V_61 ) ;
if ( V_58 ) {
const struct V_20 * V_21 = V_4 -> V_22 ;
struct V_62 * V_63 ;
if ( V_21 -> V_23 . V_24 & V_25 ) {
V_35 = - V_38 ;
F_13 ( L_4
L_5 ) ;
goto V_64;
}
V_55 = V_58 ( V_6 -> V_55 ) ;
if ( V_55 == NULL ) {
V_35 = - V_49 ;
F_13 ( L_6 ,
V_6 -> V_55 ) ;
goto V_64;
}
if ( V_55 -> V_65 != V_4 -> V_18 ) {
V_35 = - V_38 ;
F_13 ( L_7
L_8 ,
V_6 -> V_55 , V_55 -> V_65 ) ;
goto V_66;
}
V_63 = F_25 ( V_4 -> V_18 ,
V_21 -> V_23 . V_26 ) ;
if ( V_55 -> V_63 -> V_63 != V_63 -> V_63 ) {
V_35 = - V_38 ;
F_13 ( L_7
L_9 ,
V_6 -> V_55 ,
V_55 -> V_63 -> V_63 ) ;
goto V_66;
}
V_60 = F_26 ( V_9 , V_55 ,
V_67 ) ;
if ( V_60 == NULL ) {
V_35 = - V_50 ;
goto V_66;
}
} else {
V_35 = - V_49 ;
F_13 ( L_10 ) ;
goto V_64;
}
F_27 () ;
}
#endif
F_16 ( V_51 , & V_9 -> V_52 ) ;
F_16 ( V_53 , & V_9 -> V_52 ) ;
V_39:
V_6 -> V_9 = V_9 ;
return 0 ;
#ifdef F_23
V_66:
F_19 ( V_55 ) ;
V_64:
F_27 () ;
#endif
V_47:
F_17 ( V_9 ) ;
V_44:
F_18 ( V_4 -> V_18 ) ;
V_41:
return V_35 ;
}
static void F_28 ( const struct V_68 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_33 * V_34 ;
if ( ! F_29 ( V_9 ) ) {
V_34 = F_30 ( V_9 ) ;
if ( V_34 )
F_31 ( V_34 -> V_48 -> V_69 ) ;
F_18 ( V_4 -> V_18 ) ;
}
F_32 ( V_6 -> V_9 ) ;
}
static void F_33 ( const struct V_68 * V_4 )
{
struct V_16 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_33 * V_34 ;
#ifdef F_23
struct V_59 * V_60 ;
F_20 (nf_ct_timeout_put_hook) V_56 ;
#endif
if ( ! F_29 ( V_9 ) ) {
V_34 = F_30 ( V_9 ) ;
if ( V_34 )
F_31 ( V_34 -> V_48 -> V_69 ) ;
F_18 ( V_4 -> V_18 ) ;
#ifdef F_23
F_24 () ;
V_56 = F_21 ( V_57 ) ;
if ( V_56 ) {
V_60 = F_34 ( V_9 ) ;
if ( V_60 )
V_56 ( V_60 -> V_55 ) ;
}
F_27 () ;
#endif
}
F_32 ( V_6 -> V_9 ) ;
}
static int T_2 F_35 ( void )
{
return F_36 ( V_70 , F_37 ( V_70 ) ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( V_70 , F_37 ( V_70 ) ) ;
}
