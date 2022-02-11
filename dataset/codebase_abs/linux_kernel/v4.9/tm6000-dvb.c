static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
char * V_5 = L_1 ;
switch ( V_4 ) {
case - V_6 :
V_5 = L_2 ;
break;
case - V_7 :
V_5 = L_3 ;
break;
case - V_8 :
V_5 = L_4 ;
break;
case - V_9 :
V_5 = L_5 ;
break;
case - V_10 :
V_5 = L_6 ;
break;
case - V_11 :
V_5 = L_7 ;
break;
case - V_12 :
V_5 = L_8 ;
break;
case - V_13 :
V_5 = L_9 ;
break;
}
if ( V_3 < 0 ) {
F_2 ( V_2 , 1 , L_10 ,
V_4 , V_5 ) ;
} else {
F_2 ( V_2 , 1 , L_11 ,
V_3 , V_4 , V_5 ) ;
}
}
static void F_3 ( struct V_14 * V_14 )
{
int V_15 ;
struct V_1 * V_2 = V_14 -> V_16 ;
switch ( V_14 -> V_4 ) {
case 0 :
case - V_17 :
break;
case - V_6 :
case - V_7 :
case - V_18 :
return;
default:
F_1 ( V_2 , 0 , V_14 -> V_4 ) ;
}
if ( V_14 -> V_19 > 0 )
F_4 ( & V_2 -> V_20 -> V_21 , V_14 -> V_22 ,
V_14 -> V_19 ) ;
if ( V_2 -> V_20 -> V_23 > 0 ) {
V_15 = F_5 ( V_14 , V_24 ) ;
if ( V_15 < 0 ) {
F_6 ( V_25 L_12 , V_26 ) ;
F_7 ( V_14 -> V_22 ) ;
F_8 ( V_14 ) ;
}
}
}
static int F_9 ( struct V_1 * V_2 )
{
int V_15 ;
unsigned int V_27 , V_28 ;
struct V_29 * V_20 = V_2 -> V_20 ;
F_6 ( V_30 L_13 , V_26 ) ;
if ( V_2 -> V_31 != V_32 ) {
F_10 ( V_2 ) ;
V_2 -> V_31 = V_32 ;
}
V_20 -> V_33 = F_11 ( 0 , V_34 ) ;
if ( V_20 -> V_33 == NULL )
return - V_35 ;
V_27 = F_12 ( V_2 -> V_36 , V_2 -> V_37 . V_38 -> V_39 . V_40
& V_41 ) ;
V_28 = F_13 ( V_2 -> V_36 , V_27 , F_14 ( V_27 ) ) ;
V_28 = V_28 * 15 ;
V_20 -> V_33 -> V_22 = F_15 ( V_28 , V_34 ) ;
if ( V_20 -> V_33 -> V_22 == NULL ) {
F_8 ( V_20 -> V_33 ) ;
F_6 ( V_25 L_14 ) ;
return - V_35 ;
}
F_16 ( V_20 -> V_33 , V_2 -> V_36 , V_27 ,
V_20 -> V_33 -> V_22 ,
V_28 ,
F_3 , V_2 ) ;
V_15 = F_17 ( V_2 -> V_36 , V_27 ) ;
if ( V_15 < 0 ) {
F_6 ( V_25 L_15 ,
V_15 , V_26 ) ;
return V_15 ;
} else
F_6 ( V_25 L_16 ) ;
V_15 = F_5 ( V_20 -> V_33 , V_24 ) ;
if ( V_15 ) {
F_6 ( V_25 L_17 ,
V_15 ) ;
F_7 ( V_20 -> V_33 -> V_22 ) ;
F_8 ( V_20 -> V_33 ) ;
return V_15 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_29 * V_20 = V_2 -> V_20 ;
if ( V_20 -> V_33 ) {
F_6 ( V_30 L_18 ) ;
F_19 ( V_20 -> V_33 ) ;
F_6 ( V_30 L_19 ) ;
F_7 ( V_20 -> V_33 -> V_22 ) ;
F_8 ( V_20 -> V_33 ) ;
V_20 -> V_33 = NULL ;
}
}
static int F_20 ( struct V_42 * V_43 )
{
struct V_44 * V_21 = V_43 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_45 ;
struct V_29 * V_20 = V_2 -> V_20 ;
F_6 ( V_30 L_20 , V_26 ) ;
F_21 ( & V_20 -> V_46 ) ;
if ( V_20 -> V_23 == 0 ) {
V_20 -> V_23 = 1 ;
F_9 ( V_2 ) ;
} else
++ ( V_20 -> V_23 ) ;
F_22 ( & V_20 -> V_46 ) ;
return 0 ;
}
static int F_23 ( struct V_42 * V_43 )
{
struct V_44 * V_21 = V_43 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_45 ;
struct V_29 * V_20 = V_2 -> V_20 ;
F_6 ( V_30 L_21 , V_26 ) ;
F_21 ( & V_20 -> V_46 ) ;
F_6 ( V_30 L_22 , V_20 -> V_23 ) ;
-- ( V_20 -> V_23 ) ;
if ( V_20 -> V_23 == 0 ) {
F_6 ( V_30 L_23 ) ;
F_18 ( V_2 ) ;
}
F_22 ( & V_20 -> V_46 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_29 * V_20 = V_2 -> V_20 ;
if ( V_2 -> V_47 . V_48 ) {
struct V_49 V_50 = {
. V_51 = V_2 -> V_52 ,
. V_53 = 1 ,
. V_54 = 1 ,
. V_55 = 45700 ,
. V_56 = 1 ,
} ;
V_20 -> V_57 = F_25 ( V_58 , & V_50 ,
& V_2 -> V_59 ) ;
} else {
F_6 ( V_25 L_24 ) ;
return - 1 ;
}
return ( ! V_20 -> V_57 ) ? - 1 : 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_15 = - 1 ;
struct V_29 * V_20 = V_2 -> V_20 ;
F_27 ( & V_20 -> V_46 ) ;
V_20 -> V_23 = 0 ;
V_15 = F_24 ( V_2 ) ;
if ( V_15 < 0 ) {
F_6 ( V_25 L_25 ) ;
goto V_60;
}
V_15 = F_28 ( & V_20 -> V_61 , L_26 ,
V_62 , & V_2 -> V_36 -> V_2 , V_63 ) ;
V_20 -> V_61 . V_45 = V_2 ;
if ( V_20 -> V_57 ) {
switch ( V_2 -> V_64 ) {
case V_65 : {
struct V_66 V_67 = {
. V_59 = & V_2 -> V_59 ,
. V_68 = V_2 -> V_69 ,
} ;
V_20 -> V_57 -> V_70 = V_71 ;
V_15 = F_29 ( & V_20 -> V_61 , V_20 -> V_57 ) ;
if ( V_15 < 0 ) {
F_6 ( V_25
L_27 ) ;
goto V_72;
}
if ( ! F_25 ( V_73 , V_20 -> V_57 , & V_67 ) ) {
F_6 ( V_25 L_28
L_29 ) ;
V_15 = - V_74 ;
goto V_75;
}
F_6 ( V_30 L_30
L_31 ) ;
break;
}
case V_76 : {
struct V_77 V_67 = {
. V_78 = V_2 -> V_69 ,
} ;
V_20 -> V_57 -> V_70 = V_79 ;
V_15 = F_29 ( & V_20 -> V_61 , V_20 -> V_57 ) ;
if ( V_15 < 0 ) {
F_6 ( V_25
L_27 ) ;
goto V_72;
}
if ( ! F_25 ( V_80 , V_20 -> V_57 , & V_2 -> V_59 , & V_67 ) ) {
F_6 ( V_25 L_28
L_32 ) ;
V_15 = - V_74 ;
goto V_75;
}
F_6 ( V_30 L_33
L_31 ) ;
break;
}
}
} else
F_6 ( V_25 L_34 ) ;
V_20 -> V_21 . V_81 . V_82 = V_83 | V_84
| V_85 ;
V_20 -> V_21 . V_45 = V_2 ;
V_20 -> V_21 . V_86 = 8 ;
V_20 -> V_21 . V_87 = 8 ;
V_20 -> V_21 . V_88 = F_20 ;
V_20 -> V_21 . V_89 = F_23 ;
V_20 -> V_21 . V_90 = NULL ;
V_15 = F_30 ( & V_20 -> V_21 ) ;
if ( V_15 < 0 ) {
F_6 ( V_25 L_35 , V_15 ) ;
goto V_75;
}
V_20 -> V_91 . V_86 = V_2 -> V_20 -> V_21 . V_86 ;
V_20 -> V_91 . V_21 = & V_2 -> V_20 -> V_21 . V_81 ;
V_20 -> V_91 . V_82 = 0 ;
V_15 = F_31 ( & V_20 -> V_91 , & V_20 -> V_61 ) ;
if ( V_15 < 0 ) {
F_6 ( V_25 L_36 , V_15 ) ;
goto V_92;
}
return 0 ;
V_92:
F_32 ( & V_20 -> V_21 ) ;
V_75:
if ( V_20 -> V_57 ) {
F_33 ( V_20 -> V_57 ) ;
F_34 ( V_20 -> V_57 ) ;
}
V_72:
F_35 ( & V_20 -> V_61 ) ;
V_60:
return V_15 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_29 * V_20 = V_2 -> V_20 ;
if ( V_20 -> V_33 != NULL ) {
struct V_14 * V_33 = V_20 -> V_33 ;
F_7 ( V_33 -> V_22 ) ;
V_33 -> V_22 = NULL ;
F_37 ( V_33 ) ;
F_8 ( V_33 ) ;
}
if ( V_20 -> V_57 ) {
F_33 ( V_20 -> V_57 ) ;
F_34 ( V_20 -> V_57 ) ;
}
F_38 ( & V_20 -> V_91 ) ;
F_32 ( & V_20 -> V_21 ) ;
F_35 ( & V_20 -> V_61 ) ;
F_39 ( & V_20 -> V_46 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_29 * V_20 ;
int V_93 ;
if ( ! V_2 )
return 0 ;
if ( ! V_2 -> V_47 . V_94 )
return 0 ;
if ( V_2 -> V_36 -> V_95 == V_96 ) {
F_6 ( V_30 L_37 ) ;
return 0 ;
}
V_20 = F_15 ( sizeof( struct V_29 ) , V_34 ) ;
if ( ! V_20 ) {
F_6 ( V_30 L_38 ) ;
return - V_35 ;
}
V_2 -> V_20 = V_20 ;
V_93 = F_26 ( V_2 ) ;
if ( V_93 < 0 ) {
F_7 ( V_20 ) ;
V_2 -> V_20 = NULL ;
return 0 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
if ( ! V_2 -> V_47 . V_94 )
return 0 ;
if ( V_2 -> V_20 ) {
F_36 ( V_2 ) ;
F_7 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
}
return 0 ;
}
static int T_1 F_42 ( void )
{
return F_43 ( & V_97 ) ;
}
static void T_2 F_44 ( void )
{
F_45 ( & V_97 ) ;
}
