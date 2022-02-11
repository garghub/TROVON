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
V_2 -> V_17 = F_10 ( V_2 -> V_7 , L_3 ) ;
if ( F_11 ( V_2 -> V_17 ) )
return - V_18 ;
F_1 ( V_2 , V_10 , 0x4 , V_11 ) ;
F_1 ( V_2 , V_10 , 0x14 , V_19 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_20 * V_7 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
unsigned long V_24 ;
int V_6 = - V_25 ;
F_14 ( & V_2 -> V_26 , V_24 ) ;
switch ( V_2 -> V_27 ) {
case V_28 :
V_6 = snprintf ( V_23 , V_29 , L_4 ) ;
break;
case V_30 :
V_6 = snprintf ( V_23 , V_29 , L_5 ) ;
break;
case V_31 :
V_6 = snprintf ( V_23 , V_29 , L_6 ) ;
break;
default:
V_6 = snprintf ( V_23 , V_29 , L_7 ) ;
}
F_15 ( & V_2 -> V_26 , V_24 ) ;
return V_6 ;
}
static T_3 F_16 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
enum V_34 V_35 = V_36 ;
T_1 V_37 , V_38 ;
int V_6 ;
V_38 = F_4 ( V_2 , V_13 , V_39 ) ;
V_37 = F_4 ( V_2 , V_40 ,
V_41 ) ;
if ( ! ( V_38 & V_42 ) ) {
if ( V_37 & V_43 ) {
V_6 = F_17 ( V_2 -> V_17 ) ;
if ( V_6 )
F_3 ( V_2 -> V_7 , L_8 ) ;
V_2 -> V_44 = 1 ;
V_35 = V_28 ;
V_2 -> V_27 = V_35 ;
V_6 = F_18 ( V_35 ) ;
if ( V_6 )
V_2 -> V_27 = V_36 ;
} else {
if ( V_2 -> V_27 != V_36 ) {
V_35 = V_31 ;
V_2 -> V_27 = V_35 ;
V_6 = F_18 ( V_35 ) ;
if ( V_6 )
V_2 -> V_27 = V_36 ;
if ( V_2 -> V_44 ) {
F_19 ( V_2 -> V_17 ) ;
V_2 -> V_44 = 0 ;
}
}
}
}
F_20 ( & V_2 -> V_7 -> V_45 , NULL , L_9 ) ;
return V_46 ;
}
static T_3 F_21 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
enum V_34 V_35 = V_36 ;
T_1 V_38 ;
int V_6 ;
V_38 = F_4 ( V_2 , V_13 , V_39 ) ;
if ( V_38 & V_42 ) {
V_6 = F_17 ( V_2 -> V_17 ) ;
if ( V_6 )
F_3 ( V_2 -> V_7 , L_8 ) ;
V_2 -> V_44 = 1 ;
F_1 ( V_2 , V_10 , 0x1 , V_47 ) ;
F_1 ( V_2 , V_10 , 0x10 , V_48 ) ;
V_35 = V_30 ;
V_2 -> V_27 = V_35 ;
V_6 = F_18 ( V_35 ) ;
if ( V_6 )
V_2 -> V_27 = V_36 ;
} else {
F_1 ( V_2 , V_10 , 0x10 , V_47 ) ;
F_1 ( V_2 , V_10 , 0x1 , V_48 ) ;
}
F_1 ( V_2 , V_10 , V_35 , V_49 ) ;
return V_46 ;
}
static void F_22 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 , struct V_1 ,
V_52 . V_51 ) ;
F_16 ( V_2 -> V_53 , V_2 ) ;
F_21 ( V_2 -> V_54 , V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 , 0x1 , V_48 ) ;
F_25 ( 0x05 , V_55 ) ;
F_25 ( 0x05 , V_56 ) ;
F_25 ( V_57 ,
V_55 ) ;
F_25 ( V_57 ,
V_56 ) ;
return 0 ;
}
static void F_26 ( struct V_50 * V_4 )
{
struct V_1 * V_2 = F_23 ( V_4 , struct V_1 ,
V_58 ) ;
if ( V_2 -> V_59 )
F_1 ( V_2 , V_40 , 0x40 ,
V_60 ) ;
else
F_1 ( V_2 , V_40 , 0x00 ,
V_60 ) ;
}
static int F_27 ( struct V_8 * V_9 , bool V_61 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
V_2 -> V_59 = V_61 ;
F_28 ( & V_2 -> V_58 ) ;
return 0 ;
}
static int F_29 ( struct V_62 * V_63 )
{
T_4 V_6 ;
struct V_1 * V_2 ;
int V_35 , V_64 ;
struct V_65 * V_66 = V_63 -> V_7 . V_67 ;
struct V_20 * V_7 = & V_63 -> V_7 ;
if ( ! V_66 ) {
F_3 ( V_7 , L_10 ) ;
return - V_25 ;
}
V_2 = F_30 ( V_7 , sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_7 = & V_63 -> V_7 ;
V_2 -> V_54 = F_31 ( V_63 , 0 ) ;
V_2 -> V_53 = F_31 ( V_63 , 1 ) ;
V_2 -> V_27 = V_36 ;
V_2 -> V_9 . V_70 = F_27 ;
V_2 -> V_9 . V_71 = F_6 ;
V_6 = F_32 ( & V_2 -> V_9 ) ;
if ( V_6 == - V_18 ) {
F_33 ( & V_63 -> V_7 , L_11 ) ;
return - V_72 ;
}
F_34 ( & V_2 -> V_26 ) ;
V_64 = F_9 ( V_2 ) ;
if ( V_64 ) {
F_3 ( & V_63 -> V_7 , L_12 ) ;
return V_64 ;
}
F_35 ( V_63 , V_2 ) ;
if ( F_36 ( & V_63 -> V_7 , & V_73 ) )
F_37 ( & V_63 -> V_7 , L_13 ) ;
F_38 ( & V_2 -> V_58 , F_26 ) ;
F_39 ( & V_2 -> V_52 , F_22 ) ;
V_35 = F_40 ( V_2 -> V_54 , NULL , F_21 ,
V_74 | V_75 | V_76 ,
L_14 , V_2 ) ;
if ( V_35 < 0 ) {
F_3 ( & V_63 -> V_7 , L_15 ,
V_2 -> V_54 , V_35 ) ;
F_41 ( V_2 -> V_7 , & V_73 ) ;
return V_35 ;
}
V_35 = F_40 ( V_2 -> V_53 , NULL , F_16 ,
V_74 | V_75 | V_76 ,
L_14 , V_2 ) ;
if ( V_35 < 0 ) {
F_3 ( & V_63 -> V_7 , L_15 ,
V_2 -> V_53 , V_35 ) ;
F_42 ( V_2 -> V_54 , V_2 ) ;
F_41 ( V_2 -> V_7 , & V_73 ) ;
return V_35 ;
}
V_2 -> V_44 = 0 ;
F_24 ( V_2 ) ;
F_43 ( & V_2 -> V_52 , V_77 ) ;
F_33 ( & V_63 -> V_7 , L_16 ) ;
return 0 ;
}
static int F_44 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
F_46 ( & V_2 -> V_52 ) ;
F_47 ( V_78 ,
V_55 ) ;
F_47 ( V_78 ,
V_56 ) ;
F_42 ( V_2 -> V_54 , V_2 ) ;
F_42 ( V_2 -> V_53 , V_2 ) ;
F_48 ( V_2 -> V_17 ) ;
F_41 ( V_2 -> V_7 , & V_73 ) ;
F_49 ( & V_2 -> V_58 ) ;
return 0 ;
}
static int T_5 F_50 ( void )
{
return F_51 ( & V_79 ) ;
}
static void T_6 F_52 ( void )
{
F_53 ( & V_79 ) ;
}
