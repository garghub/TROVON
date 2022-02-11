static T_1 F_1 ( T_2 V_1 )
{
switch ( V_1 & V_2 ) {
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
case V_15 :
return V_16 | V_17 ;
case V_18 :
return V_14 ;
default:
return V_19 ;
}
}
static int F_2 ( T_1 V_20 )
{
if ( V_20 == V_10 )
return V_21 ;
if ( V_20 == V_6 )
return V_22 ;
if ( V_20 == V_17 )
return V_23 ;
if ( V_20 == V_8 )
return V_24 ;
if ( V_20 == V_16 )
return V_25 ;
if ( V_20 & V_12 )
return V_26 ;
if ( V_20 & V_4 )
return V_27 ;
if ( V_20 & V_14 )
return V_28 ;
return - V_29 ;
}
static T_3 F_3 ( T_2 V_1 )
{
if ( ! ( V_1 & V_30 ) )
return V_31 ;
return 0 ;
}
static int F_4 ( struct V_32 * V_33 , T_3 * V_34 ,
T_1 * V_20 )
{
int V_1 = F_5 ( V_33 , V_35 ) ;
if ( V_1 < 0 )
return V_1 ;
if ( V_34 )
* V_34 = F_3 ( V_1 ) ;
if ( V_20 )
* V_20 = F_1 ( V_1 ) ;
return 0 ;
}
static inline struct V_36 * F_6 ( struct V_37 * V_38 )
{
return F_7 ( V_38 , struct V_36 , V_38 ) ;
}
static int F_8 ( struct V_37 * V_38 , T_1 * V_20 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_40 = F_9 ( & V_39 -> V_41 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_39 -> V_42 || V_39 -> V_43 > 0 )
* V_20 = V_39 -> V_44 ;
else
V_40 = F_4 ( F_10 ( V_38 ) , NULL , V_20 ) ;
F_11 ( & V_39 -> V_41 ) ;
return V_40 ;
}
static int F_12 ( struct V_37 * V_38 , T_3 * V_34 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_45 = F_9 ( & V_39 -> V_41 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_4 ( F_10 ( V_38 ) , V_34 , NULL ) ;
F_11 ( & V_39 -> V_41 ) ;
return V_45 ;
}
static int F_13 ( struct V_37 * V_38 ,
struct V_46 * V_47 )
{
struct V_32 * V_33 = F_10 ( V_38 ) ;
return F_14 ( V_33 , V_47 , V_48 , 0 ) ;
}
static int F_15 ( struct V_37 * V_38 , T_1 V_20 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
struct V_32 * V_33 = F_10 ( V_38 ) ;
int V_45 = F_9 ( & V_39 -> V_41 ) ;
if ( V_45 )
return V_45 ;
if ( V_20 == V_49 ) {
V_45 = F_16 ( V_33 ,
V_50 ,
V_51 ) ;
if ( V_45 < 0 )
goto V_52;
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
V_39 -> V_42 = true ;
} else {
V_45 = F_2 ( V_20 ) ;
if ( V_45 < 0 )
goto V_52;
V_45 = F_16 ( V_33 ,
V_50 , V_45 ) ;
if ( V_45 < 0 )
goto V_52;
V_39 -> V_44 = V_20 ;
V_39 -> V_42 = false ;
}
V_45 = 0 ;
V_52:
F_11 ( & V_39 -> V_41 ) ;
return V_45 ;
}
static void F_17 ( struct V_53 * V_54 )
{
struct V_36 * V_39 = F_7 ( V_54 , struct V_36 ,
V_54 ) ;
struct V_32 * V_33 = F_10 ( & V_39 -> V_38 ) ;
T_2 V_55 ;
F_18 ( & V_39 -> V_41 ) ;
F_16 ( V_33 , V_56 ,
V_57 ) ;
V_55 = F_5 ( V_33 , V_58 ) ;
F_16 ( V_33 , V_59 , V_55 ) ;
F_16 ( V_33 , V_56 , 0 ) ;
if ( V_55 & V_60 && V_39 -> V_42 )
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
F_11 ( & V_39 -> V_41 ) ;
F_19 ( V_39 -> V_43 ) ;
}
static T_4 F_20 ( int V_43 , void * V_61 )
{
struct V_36 * V_39 = V_61 ;
F_21 ( & V_39 -> V_54 ) ;
F_22 ( V_39 -> V_43 ) ;
return V_62 ;
}
static T_5 int F_23 ( struct V_32 * V_33 ,
const struct V_63 * V_64 )
{
struct V_36 * V_39 ;
struct V_37 * V_38 ;
int V_45 ;
if ( ! F_24 ( V_33 -> V_65 , V_66 ) )
return - V_67 ;
F_25 ( V_33 , L_1 ,
V_33 -> V_68 << 1 , V_33 -> V_65 -> V_69 ) ;
V_39 = F_26 ( sizeof( struct V_36 ) , V_70 ) ;
if ( V_39 == NULL ) {
V_45 = - V_71 ;
goto V_40;
}
V_39 -> V_43 = V_33 -> V_43 ;
F_27 ( & V_39 -> V_54 , F_17 ) ;
F_28 ( & V_39 -> V_41 ) ;
V_39 -> V_42 = true ;
V_38 = & V_39 -> V_38 ;
F_29 ( V_38 , V_33 , & V_72 ) ;
V_45 = F_16 ( V_33 , V_50 ,
V_51 ) ;
if ( V_45 < 0 )
goto V_73;
V_45 = F_16 ( V_33 , V_74 ,
V_75 ) ;
if ( V_45 < 0 )
goto V_73;
V_45 = F_16 ( V_33 ,
V_76 ,
V_77 ) ;
if ( V_45 < 0 )
goto V_73;
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
if ( V_39 -> V_43 > 0 ) {
V_45 = F_30 ( V_39 -> V_43 , F_20 , 0 , V_78 ,
V_39 ) ;
if ( V_45 )
goto V_73;
V_45 = F_16 ( V_33 , V_56 ,
V_57 ) ;
if ( V_45 < 0 )
goto V_73;
V_45 = F_16 ( V_33 , V_79 ,
V_80 | V_81 ) ;
if ( V_45 < 0 )
goto V_73;
V_45 = F_16 ( V_33 , V_82 , 0 ) ;
if ( V_45 < 0 )
goto V_73;
V_45 = F_16 ( V_33 , V_83 , 0 ) ;
if ( V_45 < 0 )
goto V_73;
V_45 = F_16 ( V_33 , V_84 ,
V_60 ) ;
if ( V_45 < 0 )
goto V_73;
V_45 = F_16 ( V_33 , V_85 , 0 ) ;
if ( V_45 < 0 )
goto V_73;
V_45 = F_16 ( V_33 , V_56 ,
0 ) ;
if ( V_45 < 0 )
goto V_73;
}
return 0 ;
V_73:
F_31 ( & V_39 -> V_41 ) ;
F_32 ( V_38 ) ;
F_33 ( V_39 ) ;
V_40:
F_34 (KERN_ERR DRIVER_NAME L_2 , ret) ;
return V_45 ;
}
static T_6 int F_35 ( struct V_32 * V_33 )
{
struct V_37 * V_38 = F_36 ( V_33 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
if ( V_39 -> V_43 > 0 ) {
F_37 ( V_33 -> V_43 , V_39 ) ;
if ( F_38 ( & V_39 -> V_54 ) ) {
F_19 ( V_39 -> V_43 ) ;
}
}
F_31 ( & V_39 -> V_41 ) ;
F_32 ( V_38 ) ;
F_33 ( F_6 ( V_38 ) ) ;
return 0 ;
}
static T_7 int F_39 ( void )
{
return F_40 ( & V_86 ) ;
}
static T_8 void F_41 ( void )
{
F_42 ( & V_86 ) ;
}
