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
if ( V_7 -> V_13 -> type == V_14 )
V_11 -> V_15 = V_16 -> V_17 ?
V_16 -> V_17 () : 0 ;
else
V_11 -> V_15 = V_16 -> V_18 ?
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
F_7 ( F_8 ( V_29 ) ) ;
V_22 = 1 ;
}
} else {
if ( V_22 ) {
F_5 ( V_26 , L_3 ) ;
F_7 ( F_9 ( V_29 ) ) ;
V_22 = 0 ;
}
}
}
}
static void F_10 ( struct V_30 * V_31 )
{
if ( V_32 == V_33 ) {
V_32 = V_20 ;
F_11 ( V_34 ) ;
}
if ( V_35 == V_33 ) {
V_35 = V_21 ;
F_11 ( V_36 ) ;
}
}
static void F_12 ( void )
{
F_4 () ;
F_13 ( & V_37 ) ;
F_14 ( & V_37 ,
F_15 ( V_16 -> V_38 ) ) ;
}
static void F_16 ( struct V_30 * V_31 )
{
F_3 () ;
F_12 () ;
}
static T_1 F_17 ( int V_39 , void * V_6 )
{
if ( V_6 == V_34 )
V_32 = V_33 ;
else if ( V_6 == V_36 )
V_35 = V_33 ;
else
return V_40 ;
F_13 ( & V_41 ) ;
F_14 ( & V_41 ,
F_15 ( V_16 -> V_42 ) ) ;
return V_43 ;
}
static void F_18 ( struct V_30 * V_31 )
{
int V_44 = 0 ;
F_5 ( V_26 , L_4 ) ;
F_3 () ;
if ( ! V_45 && V_20 != V_32 ) {
V_32 = V_33 ;
V_44 = 1 ;
}
if ( ! V_46 && V_21 != V_35 ) {
V_35 = V_33 ;
V_44 = 1 ;
}
if ( V_44 )
F_12 () ;
F_13 ( & V_47 ) ;
F_14 ( & V_47 ,
F_15 ( V_16 -> V_48 ) ) ;
}
static int F_19 ( void )
{
return ( V_49 -> V_50 == V_51 ||
V_49 -> V_50 == V_52 ) ;
}
static int F_20 ( void )
{
return ( V_49 -> V_50 == V_53 ) ;
}
static int F_21 ( struct V_54 * V_55 ,
unsigned long V_56 , void * V_57 )
{
switch ( V_56 ) {
case V_53 :
V_32 = V_33 ;
break;
case V_51 :
case V_52 :
V_35 = V_33 ;
break;
case V_58 :
V_32 = V_33 ;
V_35 = V_33 ;
break;
default:
return V_59 ;
}
F_13 ( & V_41 ) ;
F_14 ( & V_41 ,
F_15 ( V_16 -> V_42 ) ) ;
return V_59 ;
}
static int F_22 ( struct V_60 * V_61 )
{
struct V_62 V_63 = {} ;
int V_64 = 0 ;
V_26 = & V_61 -> V_26 ;
if ( V_61 -> V_65 != - 1 ) {
F_23 ( V_26 , L_5
L_6 ) ;
V_64 = - V_19 ;
goto V_66;
}
V_16 = V_61 -> V_26 . V_67 ;
if ( V_16 -> V_68 ) {
V_64 = V_16 -> V_68 ( V_26 ) ;
if ( V_64 < 0 )
goto V_69;
}
V_29 = F_24 ( V_26 , L_7 ) ;
if ( F_25 ( V_29 ) ) {
F_5 ( V_26 , L_8 ) ;
V_29 = NULL ;
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
F_26 ( & V_41 , F_16 ) ;
F_26 ( & V_37 , F_10 ) ;
V_45 = F_27 ( V_61 , V_70 , L_9 ) ;
V_46 = F_27 ( V_61 , V_70 , L_10 ) ;
if ( V_16 -> V_71 ) {
V_63 . V_71 = V_16 -> V_71 ;
V_63 . V_72 = V_16 -> V_72 ;
} else {
V_63 . V_71 = V_73 ;
V_63 . V_72 = F_28 ( V_73 ) ;
}
#if F_29 ( V_74 )
V_49 = F_30 ( V_75 ) ;
if ( ! F_31 ( V_49 ) ) {
if ( ! V_16 -> V_18 )
V_16 -> V_18 = F_19 ;
if ( ! V_16 -> V_17 )
V_16 -> V_17 = F_20 ;
}
#endif
if ( V_16 -> V_17 ) {
V_34 = F_32 ( & V_61 -> V_26 ,
& V_76 , & V_63 ) ;
if ( F_25 ( V_34 ) ) {
F_23 ( V_26 , L_11 ,
V_76 . V_77 ) ;
V_64 = F_33 ( V_34 ) ;
goto V_78;
}
if ( V_45 ) {
V_64 = F_34 ( V_45 -> V_79 , F_17 ,
F_1 ( V_45 ) , V_45 -> V_77 ,
V_34 ) ;
if ( V_64 ) {
F_23 ( V_26 , L_12 ) ;
goto V_80;
}
} else {
V_81 = 1 ;
}
}
if ( V_16 -> V_18 ) {
V_36 = F_32 ( & V_61 -> V_26 ,
& V_82 ,
& V_63 ) ;
if ( F_25 ( V_36 ) ) {
F_23 ( V_26 , L_11 ,
V_82 . V_77 ) ;
V_64 = F_33 ( V_36 ) ;
goto V_83;
}
if ( V_46 ) {
V_64 = F_34 ( V_46 -> V_79 , F_17 ,
F_1 ( V_46 ) ,
V_46 -> V_77 , V_36 ) ;
if ( V_64 ) {
F_23 ( V_26 , L_13 ) ;
goto V_84;
}
} else {
V_81 = 1 ;
}
}
#if F_29 ( V_74 )
if ( ! F_31 ( V_49 ) && V_16 -> V_85 ) {
V_86 . V_87 = F_21 ;
V_64 = F_35 ( V_49 , & V_86 ) ;
if ( V_64 ) {
F_23 ( V_26 , L_14 ) ;
goto V_88;
}
V_81 = 0 ;
}
#endif
if ( V_81 ) {
F_5 ( V_26 , L_15 ) ;
F_26 ( & V_47 , F_18 ) ;
F_13 ( & V_47 ) ;
F_14 ( & V_47 ,
F_15 ( V_16 -> V_48 ) ) ;
}
if ( V_45 || V_46 )
F_36 ( & V_61 -> V_26 , 1 ) ;
return 0 ;
#if F_29 ( V_74 )
V_88:
if ( V_16 -> V_18 && V_46 )
F_37 ( V_46 -> V_79 , V_36 ) ;
#endif
V_84:
if ( V_16 -> V_18 )
F_38 ( V_36 ) ;
V_83:
if ( V_16 -> V_17 && V_45 )
F_37 ( V_45 -> V_79 , V_34 ) ;
#if F_29 ( V_74 )
if ( ! F_31 ( V_49 ) )
F_39 ( V_49 ) ;
#endif
V_80:
if ( V_16 -> V_17 )
F_38 ( V_34 ) ;
V_78:
if ( V_29 ) {
F_40 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_16 -> exit )
V_16 -> exit ( V_26 ) ;
V_69:
V_66:
return V_64 ;
}
static int F_41 ( struct V_60 * V_61 )
{
if ( V_16 -> V_18 && V_46 )
F_37 ( V_46 -> V_79 , V_36 ) ;
if ( V_16 -> V_17 && V_45 )
F_37 ( V_45 -> V_79 , V_34 ) ;
if ( V_81 )
F_42 ( & V_47 ) ;
F_42 ( & V_41 ) ;
F_42 ( & V_37 ) ;
if ( V_16 -> V_18 )
F_38 ( V_36 ) ;
if ( V_16 -> V_17 )
F_38 ( V_34 ) ;
#if F_29 ( V_74 )
if ( ! F_31 ( V_49 ) )
F_39 ( V_49 ) ;
#endif
if ( V_29 ) {
F_40 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_16 -> exit )
V_16 -> exit ( V_26 ) ;
return 0 ;
}
static int F_43 ( struct V_60 * V_61 , T_2 V_89 )
{
if ( V_16 -> V_90 ) {
int V_64 = V_16 -> V_90 ( V_89 ) ;
if ( V_64 )
return V_64 ;
}
if ( F_44 ( & V_61 -> V_26 ) ) {
if ( V_45 )
V_91 = ! F_45 ( V_45 -> V_79 ) ;
if ( V_46 )
V_92 = ! F_45 ( V_46 -> V_79 ) ;
}
return 0 ;
}
static int F_46 ( struct V_60 * V_61 )
{
if ( F_44 ( & V_61 -> V_26 ) ) {
if ( V_46 && V_92 )
F_47 ( V_46 -> V_79 ) ;
if ( V_45 && V_91 )
F_47 ( V_45 -> V_79 ) ;
}
if ( V_16 -> V_93 )
return V_16 -> V_93 () ;
return 0 ;
}
