static void F_1 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 1 ;
struct V_7 V_8 ;
struct V_9 V_10 ;
int V_11 ;
V_2 -> V_12 = F_3 ( & V_13 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_5 , L_1 , V_14 ) ;
goto V_15;
}
V_8 . V_16 = 0 ;
V_8 . V_17 =
( ( V_18 ) 1 << F_5 ( 8 * sizeof( V_18 ) , ( V_19 ) 36 ) ) - 1 ;
V_8 . V_20 = true ;
V_11 = F_6 ( V_2 -> V_12 , V_21 ,
& V_8 ) ;
if ( V_11 < 0 ) {
F_4 ( V_5 , L_2 , V_14 ,
V_11 ) ;
goto V_22;
}
V_11 = F_6 ( V_2 -> V_12 , V_23 ,
& V_6 ) ;
if ( V_11 < 0 ) {
F_4 ( V_5 , L_2 , V_14 ,
V_11 ) ;
goto V_22;
}
V_10 . V_3 = V_3 ;
V_10 . V_24 = V_25 ;
V_11 = F_6 ( V_2 -> V_12 ,
V_26 ,
& V_10 ) ;
if ( V_11 < 0 ) {
F_4 ( V_5 , L_2 ,
V_14 , V_11 ) ;
goto V_22;
}
V_11 = F_7 ( V_2 -> V_12 , 0 , 0 , 1ULL << 36 ,
V_27 | V_28 ) ;
if ( V_11 < 0 ) {
F_4 ( V_5 , L_3 ,
V_14 , V_11 ) ;
goto V_22;
}
V_11 = F_8 ( V_2 -> V_12 , V_5 ) ;
if ( V_11 < 0 ) {
F_4 ( V_5 , L_4 , V_14 ,
V_11 ) ;
goto V_22;
}
V_11 = F_6 ( V_2 -> V_12 ,
V_29 ,
& V_6 ) ;
if ( V_11 < 0 ) {
F_4 ( V_5 , L_2 , V_14 ,
V_11 ) ;
goto V_30;
}
V_15:
#endif
F_9 ( V_2 -> V_31 , V_3 ) ;
return;
#ifdef F_2
V_30:
F_10 ( V_2 -> V_12 , NULL ) ;
V_22:
F_11 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
#endif
}
static struct V_32 * F_12 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
T_1 V_34 = 0 ;
F_13 ( V_2 -> V_31 ) ;
V_2 -> V_12 = NULL ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_33 = F_14 ( V_2 , NULL ) ;
if ( ! V_33 ) {
F_15 ( V_2 -> V_5 , L_5 ,
V_14 , V_2 -> V_3 ) ;
return NULL ;
}
#ifdef F_16
V_34 |= V_35 | V_36 | V_37 |
V_38 ;
#endif
#ifdef F_17
V_34 |= V_39 ;
#endif
F_18 ( V_33 , V_34 ) ;
F_19 ( & V_40 ) ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_21 () ;
}
if ( ! V_43 )
V_43 = V_33 ;
F_22 ( & V_40 ) ;
F_23 ( V_2 -> V_5 , L_6 , V_2 -> V_3 ) ;
return V_33 ;
}
static void F_24 ( const struct V_1 * V_2 ,
unsigned int V_3 )
{
#ifdef F_2
struct V_9 V_10 ;
int V_11 ;
if ( V_2 -> V_12 ) {
V_10 . V_3 = V_3 ;
V_10 . V_24 = V_25 ;
V_11 = F_6 ( V_2 -> V_12 ,
V_26 , & V_10 ) ;
if ( V_11 < 0 ) {
F_4 ( V_2 -> V_5 ,
L_7 ) ;
return;
}
}
#endif
F_9 ( V_2 -> V_31 , V_3 ) ;
}
static int F_25 ( unsigned int V_3 )
{
struct V_32 * V_33 ;
const struct V_1 * V_2 ;
V_33 = V_44 [ V_3 ] ;
if ( V_33 ) {
V_2 = F_26 ( V_33 ) ;
if ( V_2 ) {
F_27 ( V_2 -> V_45 , F_28 ( 0 ) ) ;
F_24 ( V_2 , 0 ) ;
}
}
return 0 ;
}
static int F_29 ( unsigned int V_3 )
{
struct V_32 * V_33 ;
const struct V_1 * V_2 ;
V_33 = V_44 [ V_3 ] ;
if ( V_33 ) {
V_2 = F_26 ( V_33 ) ;
if ( V_2 ) {
F_27 ( V_2 -> V_45 , F_28 ( V_3 ) ) ;
F_24 ( V_2 , V_3 ) ;
}
}
return 0 ;
}
static int F_30 ( struct V_46 * V_47 )
{
struct V_4 * V_5 = & V_47 -> V_5 ;
struct V_48 * V_49 = V_5 -> V_50 ;
struct V_1 * V_2 ;
struct V_51 * V_52 [ 2 ] ;
void T_2 * V_53 ;
int V_45 , V_3 , V_54 ;
T_1 V_55 ;
V_2 = F_31 ( V_5 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_5 = V_5 ;
V_52 [ 0 ] = F_32 ( V_47 , V_58 ,
V_59 ) ;
if ( ! V_52 [ 0 ] ) {
F_4 ( V_5 , L_8 ,
V_49 -> V_60 ) ;
return - V_61 ;
}
V_52 [ 1 ] = F_32 ( V_47 , V_58 ,
V_62 ) ;
if ( ! V_52 [ 1 ] ) {
F_4 ( V_5 , L_9 ,
V_49 -> V_60 ) ;
return - V_61 ;
}
V_54 = F_33 ( V_49 , L_10 , & V_55 ) ;
if ( V_54 ) {
F_4 ( V_5 , L_11 ,
V_49 -> V_60 ) ;
return V_54 ;
}
V_2 -> V_31 = V_55 ;
V_2 -> V_3 = - 1 ;
V_45 = F_34 ( V_47 , 0 ) ;
if ( V_45 <= 0 ) {
F_4 ( V_5 , L_12 , V_49 -> V_60 ) ;
return - V_61 ;
}
V_2 -> V_45 = V_45 ;
V_53 = F_35 ( V_52 [ 0 ] -> V_63 , F_36 ( V_52 [ 0 ] ) , 0 ) ;
if ( ! V_53 ) {
F_4 ( V_5 , L_13 ) ;
goto V_64;
}
V_2 -> V_65 [ V_59 ] = V_53 ;
V_53 = F_35 ( V_52 [ 1 ] -> V_63 , F_36 ( V_52 [ 1 ] ) ,
V_66 | V_67 ) ;
if ( ! V_53 ) {
F_4 ( V_5 , L_14 ) ;
goto V_68;
}
V_2 -> V_65 [ V_62 ] = V_53 ;
V_2 -> V_69 = F_37 () ;
F_19 ( & V_40 ) ;
V_3 = F_38 ( - 1 , & V_41 ) ;
if ( V_3 >= V_70 ) {
F_22 ( & V_40 ) ;
return 0 ;
}
F_39 ( V_3 , & V_41 ) ;
F_22 ( & V_40 ) ;
V_2 -> V_3 = V_3 ;
if ( F_40 ( V_5 , F_41 ( 40 ) ) ) {
F_4 ( V_5 , L_15 ) ;
goto V_71;
}
if ( ! F_12 ( V_2 ) ) {
F_4 ( V_5 , L_16 ) ;
goto V_71;
}
if ( ! F_42 ( V_3 ) )
F_25 ( V_3 ) ;
return 0 ;
V_71:
F_43 ( V_2 -> V_65 [ V_62 ] ) ;
V_68:
F_43 ( V_2 -> V_65 [ V_59 ] ) ;
V_64:
return - V_61 ;
}
static int T_3 F_44 ( struct V_72 * V_73 )
{
int V_11 ;
V_11 = F_45 ( V_73 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_46 ( V_74 ,
L_17 ,
F_29 , F_25 ) ;
if ( V_11 < 0 ) {
F_47 ( L_18 ) ;
F_48 ( V_73 ) ;
return V_11 ;
}
return 0 ;
}
