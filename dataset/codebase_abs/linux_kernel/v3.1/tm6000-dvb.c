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
if ( V_14 -> V_4 != 0 )
F_1 ( V_2 , 0 , V_14 -> V_4 ) ;
else if ( V_14 -> V_17 > 0 )
F_4 ( & V_2 -> V_18 -> V_19 , V_14 -> V_20 ,
V_14 -> V_17 ) ;
if ( V_2 -> V_18 -> V_21 > 0 ) {
V_15 = F_5 ( V_14 , V_22 ) ;
if ( V_15 < 0 ) {
F_6 ( V_23 L_12 , V_24 ) ;
F_7 ( V_14 -> V_20 ) ;
F_8 ( V_14 ) ;
}
}
}
int F_9 ( struct V_1 * V_2 )
{
int V_15 ;
unsigned int V_25 , V_26 ;
struct V_27 * V_18 = V_2 -> V_18 ;
F_6 ( V_28 L_13 , V_24 ) ;
if ( V_2 -> V_29 != V_30 ) {
F_10 ( V_2 ) ;
V_2 -> V_29 = V_30 ;
}
V_18 -> V_31 = F_11 ( 0 , V_32 ) ;
if ( V_18 -> V_31 == NULL ) {
F_6 ( V_23 L_14 ) ;
return - V_33 ;
}
V_25 = F_12 ( V_2 -> V_34 , V_2 -> V_35 . V_36 -> V_37 . V_38
& V_39 ) ;
V_26 = F_13 ( V_2 -> V_34 , V_25 , F_14 ( V_25 ) ) ;
V_26 = V_26 * 15 ;
V_18 -> V_31 -> V_20 = F_15 ( V_26 , V_32 ) ;
if ( V_18 -> V_31 -> V_20 == NULL ) {
F_8 ( V_18 -> V_31 ) ;
F_6 ( V_23 L_15 ) ;
return - V_33 ;
}
F_16 ( V_18 -> V_31 , V_2 -> V_34 , V_25 ,
V_18 -> V_31 -> V_20 ,
V_26 ,
F_3 , V_2 ) ;
V_15 = F_17 ( V_2 -> V_34 , V_25 ) ;
if ( V_15 < 0 ) {
F_6 ( V_23 L_16 ,
V_15 , V_24 ) ;
return V_15 ;
} else
F_6 ( V_23 L_17 ) ;
V_15 = F_5 ( V_18 -> V_31 , V_32 ) ;
if ( V_15 ) {
F_6 ( V_23 L_18 ,
V_15 ) ;
F_7 ( V_18 -> V_31 -> V_20 ) ;
F_8 ( V_18 -> V_31 ) ;
return V_15 ;
}
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_27 * V_18 = V_2 -> V_18 ;
if ( V_18 -> V_31 ) {
F_6 ( V_28 L_19 ) ;
F_19 ( V_18 -> V_31 ) ;
F_6 ( V_28 L_20 ) ;
F_7 ( V_18 -> V_31 -> V_20 ) ;
F_8 ( V_18 -> V_31 ) ;
V_18 -> V_31 = NULL ;
}
}
int F_20 ( struct V_40 * V_41 )
{
struct V_42 * V_19 = V_41 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_43 ;
struct V_27 * V_18 = V_2 -> V_18 ;
F_6 ( V_28 L_21 , V_24 ) ;
F_21 ( & V_18 -> V_44 ) ;
if ( V_18 -> V_21 == 0 ) {
V_18 -> V_21 = 1 ;
F_9 ( V_2 ) ;
} else
++ ( V_18 -> V_21 ) ;
F_22 ( & V_18 -> V_44 ) ;
return 0 ;
}
int F_23 ( struct V_40 * V_41 )
{
struct V_42 * V_19 = V_41 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_43 ;
struct V_27 * V_18 = V_2 -> V_18 ;
F_6 ( V_28 L_22 , V_24 ) ;
F_21 ( & V_18 -> V_44 ) ;
F_6 ( V_28 L_23 , V_18 -> V_21 ) ;
-- ( V_18 -> V_21 ) ;
if ( V_18 -> V_21 == 0 ) {
F_6 ( V_28 L_24 ) ;
F_18 ( V_2 ) ;
}
F_22 ( & V_18 -> V_44 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_27 * V_18 = V_2 -> V_18 ;
if ( V_2 -> V_45 . V_46 ) {
struct V_47 V_48 = {
. V_49 = V_2 -> V_50 ,
. V_51 = 1 ,
. V_52 = 1 ,
. V_53 = 45700 ,
. V_54 = 1 ,
} ;
V_18 -> V_55 = F_25 ( V_56 , & V_48 ,
& V_2 -> V_57 ) ;
} else {
F_6 ( V_23 L_25 ) ;
return - 1 ;
}
return ( ! V_18 -> V_55 ) ? - 1 : 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_15 = - 1 ;
struct V_27 * V_18 = V_2 -> V_18 ;
F_27 ( & V_18 -> V_44 ) ;
V_18 -> V_21 = 0 ;
V_15 = F_24 ( V_2 ) ;
if ( V_15 < 0 ) {
F_6 ( V_23 L_26 ) ;
goto V_58;
}
V_15 = F_28 ( & V_18 -> V_59 , L_27 ,
V_60 , & V_2 -> V_34 -> V_2 , V_61 ) ;
V_18 -> V_59 . V_43 = V_2 ;
if ( V_18 -> V_55 ) {
switch ( V_2 -> V_62 ) {
case V_63 : {
struct V_64 V_65 = {
. V_57 = & V_2 -> V_57 ,
. V_66 = V_2 -> V_67 ,
} ;
V_18 -> V_55 -> V_68 = V_69 ;
V_15 = F_29 ( & V_18 -> V_59 , V_18 -> V_55 ) ;
if ( V_15 < 0 ) {
F_6 ( V_23
L_28 ) ;
goto V_70;
}
if ( ! F_25 ( V_71 , V_18 -> V_55 , & V_65 ) ) {
F_6 ( V_23 L_29
L_30 ) ;
V_15 = - V_72 ;
goto V_73;
}
F_6 ( V_28 L_31
L_32 ) ;
break;
}
case V_74 : {
struct V_75 V_65 = {
. V_76 = V_2 -> V_67 ,
} ;
V_18 -> V_55 -> V_68 = V_77 ;
V_15 = F_29 ( & V_18 -> V_59 , V_18 -> V_55 ) ;
if ( V_15 < 0 ) {
F_6 ( V_23
L_28 ) ;
goto V_70;
}
if ( ! F_25 ( V_78 , V_18 -> V_55 , & V_2 -> V_57 , & V_65 ) ) {
F_6 ( V_23 L_29
L_33 ) ;
V_15 = - V_72 ;
goto V_73;
}
F_6 ( V_28 L_34
L_32 ) ;
break;
}
}
} else
F_6 ( V_23 L_35 ) ;
V_18 -> V_19 . V_79 . V_80 = V_81 | V_82
| V_83 ;
V_18 -> V_19 . V_43 = V_2 ;
V_18 -> V_19 . V_84 = 8 ;
V_18 -> V_19 . V_85 = 8 ;
V_18 -> V_19 . V_86 = F_20 ;
V_18 -> V_19 . V_87 = F_23 ;
V_18 -> V_19 . V_88 = NULL ;
V_15 = F_30 ( & V_18 -> V_19 ) ;
if ( V_15 < 0 ) {
F_6 ( L_36 , V_15 ) ;
goto V_73;
}
V_18 -> V_89 . V_84 = V_2 -> V_18 -> V_19 . V_84 ;
V_18 -> V_89 . V_19 = & V_2 -> V_18 -> V_19 . V_79 ;
V_18 -> V_89 . V_80 = 0 ;
V_15 = F_31 ( & V_18 -> V_89 , & V_18 -> V_59 ) ;
if ( V_15 < 0 ) {
F_6 ( L_37 , V_15 ) ;
goto V_90;
}
return 0 ;
V_90:
F_32 ( & V_18 -> V_19 ) ;
V_73:
if ( V_18 -> V_55 ) {
F_33 ( V_18 -> V_55 ) ;
F_34 ( V_18 -> V_55 ) ;
}
V_70:
F_35 ( & V_18 -> V_59 ) ;
V_58:
return V_15 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_27 * V_18 = V_2 -> V_18 ;
if ( V_18 -> V_31 != NULL ) {
struct V_14 * V_31 = V_18 -> V_31 ;
F_7 ( V_31 -> V_20 ) ;
V_31 -> V_20 = NULL ;
F_37 ( V_31 ) ;
F_8 ( V_31 ) ;
}
if ( V_18 -> V_55 ) {
F_33 ( V_18 -> V_55 ) ;
F_34 ( V_18 -> V_55 ) ;
}
F_38 ( & V_18 -> V_89 ) ;
F_32 ( & V_18 -> V_19 ) ;
F_35 ( & V_18 -> V_59 ) ;
F_39 ( & V_18 -> V_44 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_27 * V_18 ;
int V_91 ;
if ( ! V_2 )
return 0 ;
if ( ! V_2 -> V_45 . V_92 )
return 0 ;
V_18 = F_15 ( sizeof( struct V_27 ) , V_32 ) ;
if ( ! V_18 ) {
F_6 ( V_28 L_38 ) ;
return - V_33 ;
}
V_2 -> V_18 = V_18 ;
V_91 = F_26 ( V_2 ) ;
if ( V_91 < 0 ) {
F_7 ( V_18 ) ;
V_2 -> V_18 = NULL ;
return 0 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
if ( ! V_2 -> V_45 . V_92 )
return 0 ;
if ( V_2 -> V_18 ) {
F_36 ( V_2 ) ;
F_7 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
return 0 ;
}
static int T_1 F_42 ( void )
{
return F_43 ( & V_93 ) ;
}
static void T_2 F_44 ( void )
{
F_45 ( & V_93 ) ;
}
