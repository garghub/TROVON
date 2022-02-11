static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return V_3 | ( V_2 -> V_4 & V_5 ) ;
}
static int F_2 ( struct V_6 * V_7 ,
enum V_8 V_9 ,
union V_10 * V_11 )
{
switch ( V_9 ) {
case V_12 :
if ( V_7 -> type == V_13 )
V_11 -> V_14 = V_15 -> V_16 ?
V_15 -> V_16 () : 0 ;
else
V_11 -> V_14 = V_15 -> V_17 ?
V_15 -> V_17 () : 0 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static void F_3 ( void )
{
if ( V_15 -> V_16 )
V_19 = ! ! V_15 -> V_16 () ;
if ( V_15 -> V_17 )
V_20 = ! ! V_15 -> V_17 () ;
}
static void F_4 ( void )
{
static int V_21 ;
int V_22 = V_15 -> V_23 ;
if ( V_15 -> V_24 ) {
if ( V_19 > 0 ) {
F_5 ( V_25 , L_1 ) ;
V_15 -> V_24 ( V_26 ) ;
} else if ( V_20 > 0 ) {
F_5 ( V_25 , L_2 ) ;
V_15 -> V_24 ( V_27 ) ;
} else {
F_5 ( V_25 , L_3 ) ;
V_15 -> V_24 ( 0 ) ;
}
} else if ( V_28 ) {
if ( V_19 > 0 ) {
F_6 ( V_28 , V_22 , V_22 ) ;
if ( ! V_21 ) {
F_5 ( V_25 , L_1 ) ;
F_7 ( F_8 ( V_28 ) ) ;
V_21 = 1 ;
}
} else {
if ( V_21 ) {
F_5 ( V_25 , L_3 ) ;
F_7 ( F_9 ( V_28 ) ) ;
V_21 = 0 ;
}
}
}
}
static void F_10 ( unsigned long V_29 )
{
if ( V_30 == V_31 ) {
V_30 = V_19 ;
F_11 ( & V_32 ) ;
}
if ( V_33 == V_31 ) {
V_33 = V_20 ;
F_11 ( & V_34 ) ;
}
}
static void F_12 ( void )
{
F_4 () ;
F_13 ( & V_35 ,
V_36 + F_14 ( V_15 -> V_37 ) ) ;
}
static void F_15 ( unsigned long V_29 )
{
F_3 () ;
F_12 () ;
}
static T_1 F_16 ( int V_38 , void * V_6 )
{
if ( V_6 == & V_32 )
V_30 = V_31 ;
else if ( V_6 == & V_34 )
V_33 = V_31 ;
else
return V_39 ;
F_13 ( & V_40 ,
V_36 + F_14 ( V_15 -> V_41 ) ) ;
return V_42 ;
}
static void F_17 ( unsigned long V_29 )
{
int V_43 = 0 ;
F_5 ( V_25 , L_4 ) ;
F_3 () ;
if ( ! V_44 && V_19 != V_30 ) {
V_30 = V_31 ;
V_43 = 1 ;
}
if ( ! V_45 && V_20 != V_33 ) {
V_33 = V_31 ;
V_43 = 1 ;
}
if ( V_43 )
F_12 () ;
F_13 ( & V_46 ,
V_36 + F_14 ( V_15 -> V_47 ) ) ;
}
static int F_18 ( void )
{
return ( V_48 -> V_49 == V_50 ||
V_48 -> V_49 == V_51 ) ;
}
static int F_19 ( void )
{
return ( V_48 -> V_49 == V_52 ) ;
}
static int F_20 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_29 )
{
switch ( V_55 ) {
case V_52 :
V_30 = V_31 ;
break;
case V_50 :
case V_51 :
V_33 = V_31 ;
break;
case V_56 :
V_30 = V_31 ;
V_33 = V_31 ;
break;
default:
return V_57 ;
}
F_13 ( & V_40 ,
V_36 + F_14 ( V_15 -> V_41 ) ) ;
return V_57 ;
}
static int F_21 ( struct V_58 * V_59 )
{
int V_60 = 0 ;
V_25 = & V_59 -> V_25 ;
if ( V_59 -> V_61 != - 1 ) {
F_22 ( V_25 , L_5
L_6 ) ;
V_60 = - V_18 ;
goto V_62;
}
V_15 = V_59 -> V_25 . V_63 ;
if ( V_15 -> V_64 ) {
V_60 = V_15 -> V_64 ( V_25 ) ;
if ( V_60 < 0 )
goto V_65;
}
V_28 = F_23 ( V_25 , L_7 ) ;
if ( F_24 ( V_28 ) ) {
F_5 ( V_25 , L_8 ) ;
V_28 = NULL ;
}
F_3 () ;
F_4 () ;
if ( ! V_15 -> V_41 )
V_15 -> V_41 = 500 ;
if ( ! V_15 -> V_37 )
V_15 -> V_37 = 500 ;
if ( ! V_15 -> V_47 )
V_15 -> V_47 = 2000 ;
if ( ! V_15 -> V_23 )
V_15 -> V_23 = 500000 ;
F_25 ( & V_40 , F_15 , 0 ) ;
F_25 ( & V_35 , F_10 , 0 ) ;
V_44 = F_26 ( V_59 , V_66 , L_9 ) ;
V_45 = F_26 ( V_59 , V_66 , L_10 ) ;
if ( V_15 -> V_67 ) {
V_32 . V_67 = V_15 -> V_67 ;
V_32 . V_68 = V_15 -> V_68 ;
V_34 . V_67 = V_15 -> V_67 ;
V_34 . V_68 = V_15 -> V_68 ;
}
#ifdef F_27
V_48 = F_28 ( V_69 ) ;
if ( ! F_29 ( V_48 ) ) {
if ( ! V_15 -> V_17 )
V_15 -> V_17 = F_18 ;
if ( ! V_15 -> V_16 )
V_15 -> V_16 = F_19 ;
}
#endif
if ( V_15 -> V_16 ) {
V_60 = F_30 ( & V_59 -> V_25 , & V_32 ) ;
if ( V_60 ) {
F_22 ( V_25 , L_11 ,
V_32 . V_70 ) ;
goto V_71;
}
if ( V_44 ) {
V_60 = F_31 ( V_44 -> V_72 , F_16 ,
F_1 ( V_44 ) , V_44 -> V_70 ,
& V_32 ) ;
if ( V_60 ) {
F_22 ( V_25 , L_12 ) ;
goto V_73;
}
} else {
V_74 = 1 ;
}
}
if ( V_15 -> V_17 ) {
V_60 = F_30 ( & V_59 -> V_25 , & V_34 ) ;
if ( V_60 ) {
F_22 ( V_25 , L_11 ,
V_34 . V_70 ) ;
goto V_75;
}
if ( V_45 ) {
V_60 = F_31 ( V_45 -> V_72 , F_16 ,
F_1 ( V_45 ) ,
V_45 -> V_70 , & V_34 ) ;
if ( V_60 ) {
F_22 ( V_25 , L_13 ) ;
goto V_76;
}
} else {
V_74 = 1 ;
}
}
#ifdef F_27
if ( ! F_29 ( V_48 ) && V_15 -> V_77 ) {
V_78 . V_79 = F_20 ;
V_60 = F_32 ( V_48 , & V_78 ) ;
if ( V_60 ) {
F_22 ( V_25 , L_14 ) ;
goto V_80;
}
V_74 = 0 ;
}
#endif
if ( V_74 ) {
F_5 ( V_25 , L_15 ) ;
F_25 ( & V_46 , F_17 , 0 ) ;
F_13 ( & V_46 ,
V_36 + F_14 ( V_15 -> V_47 ) ) ;
}
if ( V_44 || V_45 )
F_33 ( & V_59 -> V_25 , 1 ) ;
return 0 ;
#ifdef F_27
V_80:
if ( V_15 -> V_17 && V_45 )
F_34 ( V_45 -> V_72 , & V_34 ) ;
#endif
V_76:
if ( V_15 -> V_17 )
F_35 ( & V_34 ) ;
V_75:
if ( V_15 -> V_16 && V_44 )
F_34 ( V_44 -> V_72 , & V_32 ) ;
#ifdef F_27
if ( ! F_29 ( V_48 ) )
F_36 ( V_48 ) ;
#endif
V_73:
if ( V_15 -> V_16 )
F_35 ( & V_32 ) ;
V_71:
if ( V_28 ) {
F_37 ( V_28 ) ;
V_28 = NULL ;
}
if ( V_15 -> exit )
V_15 -> exit ( V_25 ) ;
V_65:
V_62:
return V_60 ;
}
static int F_38 ( struct V_58 * V_59 )
{
if ( V_15 -> V_17 && V_45 )
F_34 ( V_45 -> V_72 , & V_34 ) ;
if ( V_15 -> V_16 && V_44 )
F_34 ( V_44 -> V_72 , & V_32 ) ;
if ( V_74 )
F_39 ( & V_46 ) ;
F_39 ( & V_40 ) ;
F_39 ( & V_35 ) ;
if ( V_15 -> V_17 )
F_35 ( & V_34 ) ;
if ( V_15 -> V_16 )
F_35 ( & V_32 ) ;
#ifdef F_27
if ( ! F_29 ( V_48 ) )
F_36 ( V_48 ) ;
#endif
if ( V_28 ) {
F_37 ( V_28 ) ;
V_28 = NULL ;
}
if ( V_15 -> exit )
V_15 -> exit ( V_25 ) ;
return 0 ;
}
static int F_40 ( struct V_58 * V_59 , T_2 V_81 )
{
if ( V_15 -> V_82 ) {
int V_60 = V_15 -> V_82 ( V_81 ) ;
if ( V_60 )
return V_60 ;
}
if ( F_41 ( & V_59 -> V_25 ) ) {
if ( V_44 )
V_83 = ! F_42 ( V_44 -> V_72 ) ;
if ( V_45 )
V_84 = ! F_42 ( V_45 -> V_72 ) ;
}
return 0 ;
}
static int F_43 ( struct V_58 * V_59 )
{
if ( F_41 ( & V_59 -> V_25 ) ) {
if ( V_45 && V_84 )
F_44 ( V_45 -> V_72 ) ;
if ( V_44 && V_83 )
F_44 ( V_44 -> V_72 ) ;
}
if ( V_15 -> V_85 )
return V_15 -> V_85 () ;
return 0 ;
}
