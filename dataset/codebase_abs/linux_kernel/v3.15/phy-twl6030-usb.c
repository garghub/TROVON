static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
int V_6 = 0 ;
V_6 = F_2 ( V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( V_2 -> V_7 ,
L_1 , V_5 , V_6 ) ;
return V_6 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
T_1 V_4 ;
int V_6 ;
V_6 = F_5 ( V_3 , & V_4 , V_5 ) ;
if ( V_6 >= 0 )
V_6 = V_4 ;
else
F_3 ( V_2 -> V_7 ,
L_2 ,
V_3 , V_5 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_1 ( V_2 , V_10 , 0x24 , V_11 ) ;
F_1 ( V_2 , V_10 , 0x84 , V_11 ) ;
F_8 ( 100 ) ;
F_1 ( V_2 , V_10 , 0xa0 , V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_13 , 0x1 , V_14 ) ;
F_1 ( V_2 , V_13 , 0x1 , V_15 ) ;
F_1 ( V_2 , V_13 , 0x10 , V_16 ) ;
V_2 -> V_17 = F_10 ( V_2 -> V_7 , V_2 -> V_18 ) ;
if ( F_11 ( V_2 -> V_17 ) )
return - V_19 ;
F_1 ( V_2 , V_10 , 0x4 , V_11 ) ;
F_1 ( V_2 , V_10 , 0x14 , V_20 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_21 * V_7 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
unsigned long V_25 ;
int V_6 = - V_26 ;
F_14 ( & V_2 -> V_27 , V_25 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
V_6 = snprintf ( V_24 , V_30 , L_3 ) ;
break;
case V_31 :
V_6 = snprintf ( V_24 , V_30 , L_4 ) ;
break;
case V_32 :
V_6 = snprintf ( V_24 , V_30 , L_5 ) ;
break;
default:
V_6 = snprintf ( V_24 , V_30 , L_6 ) ;
}
F_15 ( & V_2 -> V_27 , V_25 ) ;
return V_6 ;
}
static T_3 F_16 ( int V_33 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
enum V_35 V_36 = V_37 ;
T_1 V_38 , V_39 ;
int V_6 ;
V_39 = F_4 ( V_2 , V_13 , V_40 ) ;
V_38 = F_4 ( V_2 , V_41 ,
V_42 ) ;
if ( ! ( V_39 & V_43 ) ) {
if ( V_38 & V_44 ) {
V_6 = F_17 ( V_2 -> V_17 ) ;
if ( V_6 )
F_3 ( V_2 -> V_7 , L_7 ) ;
V_2 -> V_45 = 1 ;
V_36 = V_29 ;
V_2 -> V_28 = V_36 ;
F_18 ( V_36 ) ;
} else {
if ( V_2 -> V_28 != V_37 ) {
V_36 = V_32 ;
V_2 -> V_28 = V_36 ;
F_18 ( V_36 ) ;
if ( V_2 -> V_45 ) {
F_19 ( V_2 -> V_17 ) ;
V_2 -> V_45 = 0 ;
}
}
}
}
F_20 ( & V_2 -> V_7 -> V_46 , NULL , L_8 ) ;
return V_47 ;
}
static T_3 F_21 ( int V_33 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
enum V_35 V_36 = V_37 ;
T_1 V_39 ;
int V_6 ;
V_39 = F_4 ( V_2 , V_13 , V_40 ) ;
if ( V_39 & V_43 ) {
V_6 = F_17 ( V_2 -> V_17 ) ;
if ( V_6 )
F_3 ( V_2 -> V_7 , L_7 ) ;
V_2 -> V_45 = 1 ;
F_1 ( V_2 , V_10 , 0x1 , V_48 ) ;
F_1 ( V_2 , V_10 , 0x10 , V_49 ) ;
V_36 = V_31 ;
V_2 -> V_28 = V_36 ;
F_18 ( V_36 ) ;
} else {
F_1 ( V_2 , V_10 , 0x10 , V_48 ) ;
F_1 ( V_2 , V_10 , 0x1 , V_49 ) ;
}
F_1 ( V_2 , V_10 , V_36 , V_50 ) ;
return V_47 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 , 0x1 , V_49 ) ;
F_23 ( 0x05 , V_51 ) ;
F_23 ( 0x05 , V_52 ) ;
F_23 ( V_53 ,
V_51 ) ;
F_23 ( V_53 ,
V_52 ) ;
F_16 ( V_2 -> V_54 , V_2 ) ;
F_21 ( V_2 -> V_55 , V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_56 * V_4 )
{
struct V_1 * V_2 = F_25 ( V_4 , struct V_1 ,
V_57 ) ;
if ( V_2 -> V_58 )
F_1 ( V_2 , V_41 , 0x40 ,
V_59 ) ;
else
F_1 ( V_2 , V_41 , 0x00 ,
V_59 ) ;
}
static int F_26 ( struct V_8 * V_9 , bool V_60 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
V_2 -> V_58 = V_60 ;
F_27 ( & V_2 -> V_57 ) ;
return 0 ;
}
static int F_28 ( struct V_61 * V_62 )
{
T_4 V_6 ;
struct V_1 * V_2 ;
int V_36 , V_63 ;
struct V_64 * V_65 = V_62 -> V_7 . V_66 ;
struct V_21 * V_7 = & V_62 -> V_7 ;
struct V_67 * V_68 = F_29 ( V_7 ) ;
V_2 = F_30 ( V_7 , sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
V_2 -> V_7 = & V_62 -> V_7 ;
V_2 -> V_55 = F_31 ( V_62 , 0 ) ;
V_2 -> V_54 = F_31 ( V_62 , 1 ) ;
V_2 -> V_28 = V_37 ;
V_2 -> V_9 . V_71 = F_26 ;
V_2 -> V_9 . V_72 = F_6 ;
V_6 = F_32 ( & V_2 -> V_9 ) ;
if ( V_6 == - V_19 ) {
F_33 ( & V_62 -> V_7 , L_9 ) ;
return - V_73 ;
}
if ( V_65 ) {
V_2 -> V_18 = L_10 ;
} else if ( V_68 ) {
if ( V_68 -> V_74 & V_75 )
V_2 -> V_18 = L_11 ;
else
V_2 -> V_18 = L_12 ;
} else {
F_3 ( & V_62 -> V_7 , L_13 ) ;
return - V_26 ;
}
F_34 ( & V_2 -> V_27 ) ;
V_63 = F_9 ( V_2 ) ;
if ( V_63 ) {
F_3 ( & V_62 -> V_7 , L_14 ) ;
return V_63 ;
}
F_35 ( V_62 , V_2 ) ;
if ( F_36 ( & V_62 -> V_7 , & V_76 ) )
F_37 ( & V_62 -> V_7 , L_15 ) ;
F_38 ( & V_2 -> V_57 , F_24 ) ;
V_2 -> V_77 = true ;
V_36 = F_39 ( V_2 -> V_55 , NULL , F_21 ,
V_78 | V_79 | V_80 ,
L_16 , V_2 ) ;
if ( V_36 < 0 ) {
F_3 ( & V_62 -> V_7 , L_17 ,
V_2 -> V_55 , V_36 ) ;
F_40 ( V_2 -> V_7 , & V_76 ) ;
return V_36 ;
}
V_36 = F_39 ( V_2 -> V_54 , NULL , F_16 ,
V_78 | V_79 | V_80 ,
L_16 , V_2 ) ;
if ( V_36 < 0 ) {
F_3 ( & V_62 -> V_7 , L_17 ,
V_2 -> V_54 , V_36 ) ;
F_41 ( V_2 -> V_55 , V_2 ) ;
F_40 ( V_2 -> V_7 , & V_76 ) ;
return V_36 ;
}
V_2 -> V_45 = 0 ;
F_22 ( V_2 ) ;
F_33 ( & V_62 -> V_7 , L_18 ) ;
return 0 ;
}
static int F_42 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_43 ( V_62 ) ;
F_44 ( V_81 ,
V_51 ) ;
F_44 ( V_81 ,
V_52 ) ;
F_41 ( V_2 -> V_55 , V_2 ) ;
F_41 ( V_2 -> V_54 , V_2 ) ;
F_45 ( V_2 -> V_17 ) ;
F_40 ( V_2 -> V_7 , & V_76 ) ;
F_46 ( & V_2 -> V_57 ) ;
return 0 ;
}
static int T_5 F_47 ( void )
{
return F_48 ( & V_82 ) ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_82 ) ;
}
