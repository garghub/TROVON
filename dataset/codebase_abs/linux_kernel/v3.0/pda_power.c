static inline unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_4 | V_5 ;
V_3 |= V_2 -> V_3 & V_6 ;
return V_3 ;
}
static int F_2 ( struct V_7 * V_8 ,
enum V_9 V_10 ,
union V_11 * V_12 )
{
switch ( V_10 ) {
case V_13 :
if ( V_8 -> type == V_14 )
V_12 -> V_15 = V_16 -> V_17 ?
V_16 -> V_17 () : 0 ;
else
V_12 -> V_15 = V_16 -> V_18 ?
V_16 -> V_18 () : 0 ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static void F_3 ( void )
{
if ( V_16 -> V_17 )
V_20 = ! ! V_16 -> V_17 () ;
if ( V_16 -> V_18 )
V_21 = ! ! V_16 -> V_18 () ;
}
static void F_4 ( void )
{
static int V_22 ;
int V_23 = V_16 -> V_24 ;
if ( V_16 -> V_25 ) {
if ( V_20 > 0 ) {
F_5 ( V_26 , L_1 ) ;
V_16 -> V_25 ( V_27 ) ;
} else if ( V_21 > 0 ) {
F_5 ( V_26 , L_2 ) ;
V_16 -> V_25 ( V_28 ) ;
} else {
F_5 ( V_26 , L_3 ) ;
V_16 -> V_25 ( 0 ) ;
}
} else if ( V_29 ) {
if ( V_20 > 0 ) {
F_6 ( V_29 , V_23 , V_23 ) ;
if ( ! V_22 ) {
F_5 ( V_26 , L_1 ) ;
F_7 ( V_29 ) ;
V_22 = 1 ;
}
} else {
if ( V_22 ) {
F_5 ( V_26 , L_3 ) ;
F_8 ( V_29 ) ;
V_22 = 0 ;
}
}
}
}
static void F_9 ( unsigned long V_30 )
{
if ( V_31 == V_32 ) {
V_31 = V_20 ;
F_10 ( & V_33 ) ;
}
if ( V_34 == V_32 ) {
V_34 = V_21 ;
F_10 ( & V_35 ) ;
}
}
static void F_11 ( void )
{
F_4 () ;
F_12 ( & V_36 ,
V_37 + F_13 ( V_16 -> V_38 ) ) ;
}
static void F_14 ( unsigned long V_30 )
{
F_3 () ;
F_11 () ;
}
static T_1 F_15 ( int V_39 , void * V_7 )
{
if ( V_7 == & V_33 )
V_31 = V_32 ;
else if ( V_7 == & V_35 )
V_34 = V_32 ;
else
return V_40 ;
F_12 ( & V_41 ,
V_37 + F_13 ( V_16 -> V_42 ) ) ;
return V_43 ;
}
static void F_16 ( unsigned long V_30 )
{
int V_44 = 0 ;
F_5 ( V_26 , L_4 ) ;
F_3 () ;
if ( ! V_45 && V_20 != V_31 ) {
V_31 = V_32 ;
V_44 = 1 ;
}
if ( ! V_46 && V_21 != V_34 ) {
V_34 = V_32 ;
V_44 = 1 ;
}
if ( V_44 )
F_11 () ;
F_12 ( & V_47 ,
V_37 + F_13 ( V_16 -> V_48 ) ) ;
}
static int F_17 ( void )
{
return ( V_49 -> V_50 == V_51 ) ;
}
static int F_18 ( struct V_52 * V_53 )
{
int V_54 = 0 ;
V_26 = & V_53 -> V_26 ;
if ( V_53 -> V_55 != - 1 ) {
F_19 ( V_26 , L_5
L_6 ) ;
V_54 = - V_19 ;
goto V_56;
}
V_16 = V_53 -> V_26 . V_57 ;
if ( V_16 -> V_58 ) {
V_54 = V_16 -> V_58 ( V_26 ) ;
if ( V_54 < 0 )
goto V_59;
}
F_3 () ;
F_4 () ;
if ( ! V_16 -> V_42 )
V_16 -> V_42 = 500 ;
if ( ! V_16 -> V_38 )
V_16 -> V_38 = 500 ;
if ( ! V_16 -> V_48 )
V_16 -> V_48 = 2000 ;
if ( ! V_16 -> V_24 )
V_16 -> V_24 = 500000 ;
F_20 ( & V_41 , F_14 , 0 ) ;
F_20 ( & V_36 , F_9 , 0 ) ;
V_45 = F_21 ( V_53 , V_60 , L_7 ) ;
V_46 = F_21 ( V_53 , V_60 , L_8 ) ;
if ( V_16 -> V_61 ) {
V_33 . V_61 = V_16 -> V_61 ;
V_33 . V_62 = V_16 -> V_62 ;
V_35 . V_61 = V_16 -> V_61 ;
V_35 . V_62 = V_16 -> V_62 ;
}
V_29 = F_22 ( V_26 , L_9 ) ;
if ( F_23 ( V_29 ) ) {
F_5 ( V_26 , L_10 ) ;
V_29 = NULL ;
V_54 = F_24 ( V_29 ) ;
}
if ( V_16 -> V_17 ) {
V_54 = F_25 ( & V_53 -> V_26 , & V_33 ) ;
if ( V_54 ) {
F_19 ( V_26 , L_11 ,
V_33 . V_63 ) ;
goto V_64;
}
if ( V_45 ) {
V_54 = F_26 ( V_45 -> V_65 , F_15 ,
F_1 ( V_45 ) , V_45 -> V_63 ,
& V_33 ) ;
if ( V_54 ) {
F_19 ( V_26 , L_12 ) ;
goto V_66;
}
} else {
V_67 = 1 ;
}
}
#ifdef F_27
V_49 = F_28 () ;
if ( V_49 && ! V_16 -> V_18 ) {
V_16 -> V_18 = F_17 ;
}
#endif
if ( V_16 -> V_18 ) {
V_54 = F_25 ( & V_53 -> V_26 , & V_35 ) ;
if ( V_54 ) {
F_19 ( V_26 , L_11 ,
V_35 . V_63 ) ;
goto V_68;
}
if ( V_46 ) {
V_54 = F_26 ( V_46 -> V_65 , F_15 ,
F_1 ( V_46 ) ,
V_46 -> V_63 , & V_35 ) ;
if ( V_54 ) {
F_19 ( V_26 , L_13 ) ;
goto V_69;
}
} else {
V_67 = 1 ;
}
}
if ( V_67 ) {
F_5 ( V_26 , L_14 ) ;
F_20 ( & V_47 , F_16 , 0 ) ;
F_12 ( & V_47 ,
V_37 + F_13 ( V_16 -> V_48 ) ) ;
}
if ( V_45 || V_46 )
F_29 ( & V_53 -> V_26 , 1 ) ;
return 0 ;
V_69:
if ( V_16 -> V_18 )
F_30 ( & V_35 ) ;
V_68:
if ( V_16 -> V_17 && V_45 )
F_31 ( V_45 -> V_65 , & V_33 ) ;
#ifdef F_27
if ( V_49 )
F_32 ( V_49 ) ;
#endif
V_66:
if ( V_16 -> V_17 )
F_30 ( & V_33 ) ;
V_64:
if ( V_29 ) {
F_33 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_16 -> exit )
V_16 -> exit ( V_26 ) ;
V_59:
V_56:
return V_54 ;
}
static int F_34 ( struct V_52 * V_53 )
{
if ( V_16 -> V_18 && V_46 )
F_31 ( V_46 -> V_65 , & V_35 ) ;
if ( V_16 -> V_17 && V_45 )
F_31 ( V_45 -> V_65 , & V_33 ) ;
if ( V_67 )
F_35 ( & V_47 ) ;
F_35 ( & V_41 ) ;
F_35 ( & V_36 ) ;
if ( V_16 -> V_18 )
F_30 ( & V_35 ) ;
if ( V_16 -> V_17 )
F_30 ( & V_33 ) ;
#ifdef F_27
if ( V_49 )
F_32 ( V_49 ) ;
#endif
if ( V_29 ) {
F_33 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_16 -> exit )
V_16 -> exit ( V_26 ) ;
return 0 ;
}
static int F_36 ( struct V_52 * V_53 , T_2 V_50 )
{
if ( V_16 -> V_70 ) {
int V_54 = V_16 -> V_70 ( V_50 ) ;
if ( V_54 )
return V_54 ;
}
if ( F_37 ( & V_53 -> V_26 ) ) {
if ( V_45 )
V_71 = ! F_38 ( V_45 -> V_65 ) ;
if ( V_46 )
V_72 = ! F_38 ( V_46 -> V_65 ) ;
}
return 0 ;
}
static int F_39 ( struct V_52 * V_53 )
{
if ( F_37 ( & V_53 -> V_26 ) ) {
if ( V_46 && V_72 )
F_40 ( V_46 -> V_65 ) ;
if ( V_45 && V_71 )
F_40 ( V_45 -> V_65 ) ;
}
if ( V_16 -> V_73 )
return V_16 -> V_73 () ;
return 0 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_74 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_74 ) ;
}
