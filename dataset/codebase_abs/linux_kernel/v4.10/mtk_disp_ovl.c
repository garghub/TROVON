static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
F_2 ( 0x0 , V_6 -> V_8 + V_9 ) ;
if ( ! V_4 -> V_10 )
return V_11 ;
F_3 ( V_4 -> V_10 , V_6 ) ;
return V_12 ;
}
static void F_4 ( struct V_5 * V_13 ,
struct V_14 * V_10 )
{
struct V_3 * V_4 = F_5 ( V_13 , struct V_3 ,
V_7 ) ;
V_4 -> V_10 = V_10 ;
F_2 ( 0x0 , V_13 -> V_8 + V_9 ) ;
F_6 ( V_15 , V_13 -> V_8 + V_16 ) ;
}
static void F_7 ( struct V_5 * V_13 )
{
struct V_3 * V_4 = F_5 ( V_13 , struct V_3 ,
V_7 ) ;
V_4 -> V_10 = NULL ;
F_6 ( 0x0 , V_13 -> V_8 + V_16 ) ;
}
static void F_8 ( struct V_5 * V_13 )
{
F_6 ( 0x1 , V_13 -> V_8 + V_17 ) ;
}
static void F_9 ( struct V_5 * V_13 )
{
F_6 ( 0x0 , V_13 -> V_8 + V_17 ) ;
}
static void F_10 ( struct V_5 * V_13 , unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 ,
unsigned int V_21 )
{
if ( V_18 != 0 && V_19 != 0 )
F_6 ( V_19 << 16 | V_18 , V_13 -> V_8 + V_22 ) ;
F_6 ( 0x0 , V_13 -> V_8 + V_23 ) ;
F_2 ( 0x1 , V_13 -> V_8 + V_24 ) ;
F_2 ( 0x0 , V_13 -> V_8 + V_24 ) ;
}
static void F_11 ( struct V_5 * V_13 , unsigned int V_25 )
{
unsigned int V_26 ;
F_2 ( 0x1 , V_13 -> V_8 + F_12 ( V_25 ) ) ;
F_2 ( V_27 , V_13 -> V_8 + F_13 ( V_25 ) ) ;
V_26 = F_14 ( V_13 -> V_8 + V_28 ) ;
V_26 = V_26 | F_15 ( V_25 ) ;
F_2 ( V_26 , V_13 -> V_8 + V_28 ) ;
}
static void F_16 ( struct V_5 * V_13 , unsigned int V_25 )
{
unsigned int V_26 ;
V_26 = F_14 ( V_13 -> V_8 + V_28 ) ;
V_26 = V_26 & ~ F_15 ( V_25 ) ;
F_2 ( V_26 , V_13 -> V_8 + V_28 ) ;
F_2 ( 0x0 , V_13 -> V_8 + F_12 ( V_25 ) ) ;
}
static unsigned int F_17 ( unsigned int V_29 )
{
switch ( V_29 ) {
default:
case V_30 :
return V_31 ;
case V_32 :
return V_31 | V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_35 | V_33 ;
case V_37 :
case V_38 :
return V_39 ;
case V_40 :
case V_41 :
return V_39 | V_33 ;
case V_42 :
case V_43 :
return V_44 ;
case V_45 :
case V_46 :
return V_44 | V_33 ;
}
}
static void F_18 ( struct V_5 * V_13 , unsigned int V_25 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = & V_48 -> V_50 ;
unsigned int V_51 = V_50 -> V_51 ;
unsigned int V_52 = V_50 -> V_52 & 0xffff ;
unsigned int V_29 = V_50 -> V_53 ;
unsigned int V_54 = ( V_50 -> V_55 << 16 ) | V_50 -> V_56 ;
unsigned int V_57 = ( V_50 -> V_58 << 16 ) | V_50 -> V_59 ;
unsigned int V_60 ;
if ( ! V_50 -> V_61 )
F_16 ( V_13 , V_25 ) ;
V_60 = F_17 ( V_29 ) ;
if ( V_25 != 0 )
V_60 |= V_62 | V_63 ;
F_6 ( V_60 , V_13 -> V_8 + F_19 ( V_25 ) ) ;
F_6 ( V_52 , V_13 -> V_8 + F_20 ( V_25 ) ) ;
F_6 ( V_57 , V_13 -> V_8 + F_21 ( V_25 ) ) ;
F_6 ( V_54 , V_13 -> V_8 + F_22 ( V_25 ) ) ;
F_6 ( V_51 , V_13 -> V_8 + F_23 ( V_25 ) ) ;
if ( V_50 -> V_61 )
F_11 ( V_13 , V_25 ) ;
}
static int F_24 ( struct V_64 * V_65 , struct V_64 * V_66 ,
void * V_67 )
{
struct V_3 * V_4 = F_25 ( V_65 ) ;
struct V_68 * V_69 = V_67 ;
int V_70 ;
V_70 = F_26 ( V_69 , & V_4 -> V_7 ) ;
if ( V_70 < 0 ) {
F_27 ( V_65 , L_1 ,
V_65 -> V_71 -> V_72 , V_70 ) ;
return V_70 ;
}
return 0 ;
}
static void F_28 ( struct V_64 * V_65 , struct V_64 * V_66 ,
void * V_67 )
{
struct V_3 * V_4 = F_25 ( V_65 ) ;
struct V_68 * V_69 = V_67 ;
F_29 ( V_69 , & V_4 -> V_7 ) ;
}
static int F_30 ( struct V_73 * V_74 )
{
struct V_64 * V_65 = & V_74 -> V_65 ;
struct V_3 * V_4 ;
int V_75 ;
int V_1 ;
int V_70 ;
V_4 = F_31 ( V_65 , sizeof( * V_4 ) , V_76 ) ;
if ( ! V_4 )
return - V_77 ;
V_1 = F_32 ( V_74 , 0 ) ;
if ( V_1 < 0 )
return V_1 ;
V_75 = F_33 ( V_65 -> V_71 , V_78 ) ;
if ( V_75 < 0 ) {
F_27 ( V_65 , L_2 , V_75 ) ;
return V_75 ;
}
V_70 = F_34 ( V_65 , V_65 -> V_71 , & V_4 -> V_7 , V_75 ,
& V_79 ) ;
if ( V_70 ) {
F_27 ( V_65 , L_3 , V_70 ) ;
return V_70 ;
}
F_35 ( V_74 , V_4 ) ;
V_70 = F_36 ( V_65 , V_1 , F_1 ,
V_80 , F_37 ( V_65 ) , V_4 ) ;
if ( V_70 < 0 ) {
F_27 ( V_65 , L_4 , V_1 , V_70 ) ;
return V_70 ;
}
V_70 = F_38 ( V_65 , & V_81 ) ;
if ( V_70 )
F_27 ( V_65 , L_5 , V_70 ) ;
return V_70 ;
}
static int F_39 ( struct V_73 * V_74 )
{
F_40 ( & V_74 -> V_65 , & V_81 ) ;
return 0 ;
}
