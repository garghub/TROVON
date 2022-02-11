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
static void F_10 ( unsigned long V_30 )
{
if ( V_31 == V_32 ) {
V_31 = V_20 ;
F_11 ( V_33 ) ;
}
if ( V_34 == V_32 ) {
V_34 = V_21 ;
F_11 ( V_35 ) ;
}
}
static void F_12 ( void )
{
F_4 () ;
F_13 ( & V_36 ,
V_37 + F_14 ( V_16 -> V_38 ) ) ;
}
static void F_15 ( unsigned long V_30 )
{
F_3 () ;
F_12 () ;
}
static T_1 F_16 ( int V_39 , void * V_6 )
{
if ( V_6 == V_33 )
V_31 = V_32 ;
else if ( V_6 == V_35 )
V_34 = V_32 ;
else
return V_40 ;
F_13 ( & V_41 ,
V_37 + F_14 ( V_16 -> V_42 ) ) ;
return V_43 ;
}
static void F_17 ( unsigned long V_30 )
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
F_12 () ;
F_13 ( & V_47 ,
V_37 + F_14 ( V_16 -> V_48 ) ) ;
}
static int F_18 ( void )
{
return ( V_49 -> V_50 == V_51 ||
V_49 -> V_50 == V_52 ) ;
}
static int F_19 ( void )
{
return ( V_49 -> V_50 == V_53 ) ;
}
static int F_20 ( struct V_54 * V_55 ,
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
F_13 ( & V_41 ,
V_37 + F_14 ( V_16 -> V_42 ) ) ;
return V_58 ;
}
static int F_21 ( struct V_59 * V_60 )
{
struct V_61 V_62 = {} ;
int V_63 = 0 ;
V_26 = & V_60 -> V_26 ;
if ( V_60 -> V_64 != - 1 ) {
F_22 ( V_26 , L_5
L_6 ) ;
V_63 = - V_19 ;
goto V_65;
}
V_16 = V_60 -> V_26 . V_66 ;
if ( V_16 -> V_67 ) {
V_63 = V_16 -> V_67 ( V_26 ) ;
if ( V_63 < 0 )
goto V_68;
}
V_29 = F_23 ( V_26 , L_7 ) ;
if ( F_24 ( V_29 ) ) {
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
F_25 ( & V_41 , F_15 , 0 ) ;
F_25 ( & V_36 , F_10 , 0 ) ;
V_45 = F_26 ( V_60 , V_69 , L_9 ) ;
V_46 = F_26 ( V_60 , V_69 , L_10 ) ;
if ( V_16 -> V_70 ) {
V_62 . V_70 = V_16 -> V_70 ;
V_62 . V_71 = V_16 -> V_71 ;
} else {
V_62 . V_70 = V_72 ;
V_62 . V_71 = F_27 ( V_72 ) ;
}
#if F_28 ( V_73 )
V_49 = F_29 ( V_74 ) ;
if ( ! F_30 ( V_49 ) ) {
if ( ! V_16 -> V_18 )
V_16 -> V_18 = F_18 ;
if ( ! V_16 -> V_17 )
V_16 -> V_17 = F_19 ;
}
#endif
if ( V_16 -> V_17 ) {
V_33 = F_31 ( & V_60 -> V_26 ,
& V_75 , & V_62 ) ;
if ( F_24 ( V_33 ) ) {
F_22 ( V_26 , L_11 ,
V_75 . V_76 ) ;
V_63 = F_32 ( V_33 ) ;
goto V_77;
}
if ( V_45 ) {
V_63 = F_33 ( V_45 -> V_78 , F_16 ,
F_1 ( V_45 ) , V_45 -> V_76 ,
V_33 ) ;
if ( V_63 ) {
F_22 ( V_26 , L_12 ) ;
goto V_79;
}
} else {
V_80 = 1 ;
}
}
if ( V_16 -> V_18 ) {
V_35 = F_31 ( & V_60 -> V_26 ,
& V_81 ,
& V_62 ) ;
if ( F_24 ( V_35 ) ) {
F_22 ( V_26 , L_11 ,
V_81 . V_76 ) ;
V_63 = F_32 ( V_35 ) ;
goto V_82;
}
if ( V_46 ) {
V_63 = F_33 ( V_46 -> V_78 , F_16 ,
F_1 ( V_46 ) ,
V_46 -> V_76 , V_35 ) ;
if ( V_63 ) {
F_22 ( V_26 , L_13 ) ;
goto V_83;
}
} else {
V_80 = 1 ;
}
}
#if F_28 ( V_73 )
if ( ! F_30 ( V_49 ) && V_16 -> V_84 ) {
V_85 . V_86 = F_20 ;
V_63 = F_34 ( V_49 , & V_85 ) ;
if ( V_63 ) {
F_22 ( V_26 , L_14 ) ;
goto V_87;
}
V_80 = 0 ;
}
#endif
if ( V_80 ) {
F_5 ( V_26 , L_15 ) ;
F_25 ( & V_47 , F_17 , 0 ) ;
F_13 ( & V_47 ,
V_37 + F_14 ( V_16 -> V_48 ) ) ;
}
if ( V_45 || V_46 )
F_35 ( & V_60 -> V_26 , 1 ) ;
return 0 ;
#if F_28 ( V_73 )
V_87:
if ( V_16 -> V_18 && V_46 )
F_36 ( V_46 -> V_78 , V_35 ) ;
#endif
V_83:
if ( V_16 -> V_18 )
F_37 ( V_35 ) ;
V_82:
if ( V_16 -> V_17 && V_45 )
F_36 ( V_45 -> V_78 , V_33 ) ;
#if F_28 ( V_73 )
if ( ! F_30 ( V_49 ) )
F_38 ( V_49 ) ;
#endif
V_79:
if ( V_16 -> V_17 )
F_37 ( V_33 ) ;
V_77:
if ( V_29 ) {
F_39 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_16 -> exit )
V_16 -> exit ( V_26 ) ;
V_68:
V_65:
return V_63 ;
}
static int F_40 ( struct V_59 * V_60 )
{
if ( V_16 -> V_18 && V_46 )
F_36 ( V_46 -> V_78 , V_35 ) ;
if ( V_16 -> V_17 && V_45 )
F_36 ( V_45 -> V_78 , V_33 ) ;
if ( V_80 )
F_41 ( & V_47 ) ;
F_41 ( & V_41 ) ;
F_41 ( & V_36 ) ;
if ( V_16 -> V_18 )
F_37 ( V_35 ) ;
if ( V_16 -> V_17 )
F_37 ( V_33 ) ;
#if F_28 ( V_73 )
if ( ! F_30 ( V_49 ) )
F_38 ( V_49 ) ;
#endif
if ( V_29 ) {
F_39 ( V_29 ) ;
V_29 = NULL ;
}
if ( V_16 -> exit )
V_16 -> exit ( V_26 ) ;
return 0 ;
}
static int F_42 ( struct V_59 * V_60 , T_2 V_88 )
{
if ( V_16 -> V_89 ) {
int V_63 = V_16 -> V_89 ( V_88 ) ;
if ( V_63 )
return V_63 ;
}
if ( F_43 ( & V_60 -> V_26 ) ) {
if ( V_45 )
V_90 = ! F_44 ( V_45 -> V_78 ) ;
if ( V_46 )
V_91 = ! F_44 ( V_46 -> V_78 ) ;
}
return 0 ;
}
static int F_45 ( struct V_59 * V_60 )
{
if ( F_43 ( & V_60 -> V_26 ) ) {
if ( V_46 && V_91 )
F_46 ( V_46 -> V_78 ) ;
if ( V_45 && V_90 )
F_46 ( V_45 -> V_78 ) ;
}
if ( V_16 -> V_92 )
return V_16 -> V_92 () ;
return 0 ;
}
