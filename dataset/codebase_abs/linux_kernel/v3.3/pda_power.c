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
return ( V_49 -> V_50 == V_51 ||
V_49 -> V_50 == V_52 ) ;
}
static int F_18 ( void )
{
return ( V_49 -> V_50 == V_53 ) ;
}
static int F_19 ( struct V_54 * V_55 ,
unsigned long V_56 , void * V_30 )
{
switch ( V_56 ) {
case V_53 :
V_31 = V_32 ;
break;
case V_51 :
case V_52 :
V_34 = V_32 ;
break;
case V_57 :
V_31 = V_32 ;
V_34 = V_32 ;
break;
default:
return V_58 ;
}
F_12 ( & V_41 ,
V_37 + F_13 ( V_16 -> V_42 ) ) ;
return V_58 ;
}
static int F_20 ( struct V_59 * V_60 )
{
int V_61 = 0 ;
V_26 = & V_60 -> V_26 ;
if ( V_60 -> V_62 != - 1 ) {
F_21 ( V_26 , L_5
L_6 ) ;
V_61 = - V_19 ;
goto V_63;
}
V_16 = V_60 -> V_26 . V_64 ;
if ( V_16 -> V_65 ) {
V_61 = V_16 -> V_65 ( V_26 ) ;
if ( V_61 < 0 )
goto V_66;
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
F_22 ( & V_41 , F_14 , 0 ) ;
F_22 ( & V_36 , F_9 , 0 ) ;
V_45 = F_23 ( V_60 , V_67 , L_7 ) ;
V_46 = F_23 ( V_60 , V_67 , L_8 ) ;
if ( V_16 -> V_68 ) {
V_33 . V_68 = V_16 -> V_68 ;
V_33 . V_69 = V_16 -> V_69 ;
V_35 . V_68 = V_16 -> V_68 ;
V_35 . V_69 = V_16 -> V_69 ;
}
V_29 = F_24 ( V_26 , L_9 ) ;
if ( F_25 ( V_29 ) ) {
F_5 ( V_26 , L_10 ) ;
V_29 = NULL ;
V_61 = F_26 ( V_29 ) ;
}
#ifdef F_27
V_49 = F_28 () ;
if ( V_49 && ! V_16 -> V_18 ) {
V_16 -> V_18 = F_17 ;
}
if ( V_49 && ! V_16 -> V_17 ) {
V_16 -> V_17 = F_18 ;
}
#endif
if ( V_16 -> V_17 ) {
V_61 = F_29 ( & V_60 -> V_26 , & V_33 ) ;
if ( V_61 ) {
F_21 ( V_26 , L_11 ,
V_33 . V_70 ) ;
goto V_71;
}
if ( V_45 ) {
V_61 = F_30 ( V_45 -> V_72 , F_15 ,
F_1 ( V_45 ) , V_45 -> V_70 ,
& V_33 ) ;
if ( V_61 ) {
F_21 ( V_26 , L_12 ) ;
goto V_73;
}
} else {
V_74 = 1 ;
}
}
if ( V_16 -> V_18 ) {
V_61 = F_29 ( & V_60 -> V_26 , & V_35 ) ;
if ( V_61 ) {
F_21 ( V_26 , L_11 ,
V_35 . V_70 ) ;
goto V_75;
}
if ( V_46 ) {
V_61 = F_30 ( V_46 -> V_72 , F_15 ,
F_1 ( V_46 ) ,
V_46 -> V_70 , & V_35 ) ;
if ( V_61 ) {
F_21 ( V_26 , L_13 ) ;
goto V_76;
}
} else {
V_74 = 1 ;
}
}
#ifdef F_27
if ( V_49 && V_16 -> V_77 ) {
V_78 . V_79 = F_19 ;
V_61 = F_31 ( V_49 , & V_78 ) ;
if ( V_61 ) {
F_21 ( V_26 , L_14 ) ;
goto V_80;
}
V_74 = 0 ;
}
#endif
if ( V_74 ) {
F_5 ( V_26 , L_15 ) ;
F_22 ( & V_47 , F_16 , 0 ) ;
F_12 ( & V_47 ,
V_37 + F_13 ( V_16 -> V_48 ) ) ;
}
if ( V_45 || V_46 )
F_32 ( & V_60 -> V_26 , 1 ) ;
return 0 ;
#ifdef F_27
V_80:
if ( V_16 -> V_18 && V_46 )
F_33 ( V_46 -> V_72 , & V_35 ) ;
#endif
V_76:
if ( V_16 -> V_18 )
F_34 ( & V_35 ) ;
V_75:
if ( V_16 -> V_17 && V_45 )
F_33 ( V_45 -> V_72 , & V_33 ) ;
#ifdef F_27
if ( V_49 )
F_35 ( V_49 ) ;
#endif
V_73:
if ( V_16 -> V_17 )
F_34 ( & V_33 ) ;
V_71:
if ( V_29 ) {
F_36 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_16 -> exit )
V_16 -> exit ( V_26 ) ;
V_66:
V_63:
return V_61 ;
}
static int F_37 ( struct V_59 * V_60 )
{
if ( V_16 -> V_18 && V_46 )
F_33 ( V_46 -> V_72 , & V_35 ) ;
if ( V_16 -> V_17 && V_45 )
F_33 ( V_45 -> V_72 , & V_33 ) ;
if ( V_74 )
F_38 ( & V_47 ) ;
F_38 ( & V_41 ) ;
F_38 ( & V_36 ) ;
if ( V_16 -> V_18 )
F_34 ( & V_35 ) ;
if ( V_16 -> V_17 )
F_34 ( & V_33 ) ;
#ifdef F_27
if ( V_49 )
F_35 ( V_49 ) ;
#endif
if ( V_29 ) {
F_36 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_16 -> exit )
V_16 -> exit ( V_26 ) ;
return 0 ;
}
static int F_39 ( struct V_59 * V_60 , T_2 V_81 )
{
if ( V_16 -> V_82 ) {
int V_61 = V_16 -> V_82 ( V_81 ) ;
if ( V_61 )
return V_61 ;
}
if ( F_40 ( & V_60 -> V_26 ) ) {
if ( V_45 )
V_83 = ! F_41 ( V_45 -> V_72 ) ;
if ( V_46 )
V_84 = ! F_41 ( V_46 -> V_72 ) ;
}
return 0 ;
}
static int F_42 ( struct V_59 * V_60 )
{
if ( F_40 ( & V_60 -> V_26 ) ) {
if ( V_46 && V_84 )
F_43 ( V_46 -> V_72 ) ;
if ( V_45 && V_83 )
F_43 ( V_45 -> V_72 ) ;
}
if ( V_16 -> V_85 )
return V_16 -> V_85 () ;
return 0 ;
}
