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
unsigned int V_19 , unsigned int V_20 )
{
if ( V_18 != 0 && V_19 != 0 )
F_6 ( V_19 << 16 | V_18 , V_13 -> V_8 + V_21 ) ;
F_6 ( 0x0 , V_13 -> V_8 + V_22 ) ;
F_2 ( 0x1 , V_13 -> V_8 + V_23 ) ;
F_2 ( 0x0 , V_13 -> V_8 + V_23 ) ;
}
static void F_11 ( struct V_5 * V_13 , unsigned int V_24 )
{
unsigned int V_25 ;
F_2 ( 0x1 , V_13 -> V_8 + F_12 ( V_24 ) ) ;
F_2 ( V_26 , V_13 -> V_8 + F_13 ( V_24 ) ) ;
V_25 = F_14 ( V_13 -> V_8 + V_27 ) ;
V_25 = V_25 | F_15 ( V_24 ) ;
F_2 ( V_25 , V_13 -> V_8 + V_27 ) ;
}
static void F_16 ( struct V_5 * V_13 , unsigned int V_24 )
{
unsigned int V_25 ;
V_25 = F_14 ( V_13 -> V_8 + V_27 ) ;
V_25 = V_25 & ~ F_15 ( V_24 ) ;
F_2 ( V_25 , V_13 -> V_8 + V_27 ) ;
F_2 ( 0x0 , V_13 -> V_8 + F_12 ( V_24 ) ) ;
}
static unsigned int F_17 ( unsigned int V_28 )
{
switch ( V_28 ) {
default:
case V_29 :
return V_30 ;
case V_31 :
return V_30 | V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_34 | V_32 ;
case V_36 :
case V_37 :
return V_38 ;
case V_39 :
case V_40 :
return V_38 | V_32 ;
case V_41 :
case V_42 :
return V_43 ;
case V_44 :
case V_45 :
return V_43 | V_32 ;
}
}
static void F_18 ( struct V_5 * V_13 , unsigned int V_24 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_47 -> V_49 ;
unsigned int V_50 = V_49 -> V_50 ;
unsigned int V_51 = V_49 -> V_51 & 0xffff ;
unsigned int V_28 = V_49 -> V_52 ;
unsigned int V_53 = ( V_49 -> V_54 << 16 ) | V_49 -> V_55 ;
unsigned int V_56 = ( V_49 -> V_57 << 16 ) | V_49 -> V_58 ;
unsigned int V_59 ;
if ( ! V_49 -> V_60 )
F_16 ( V_13 , V_24 ) ;
V_59 = F_17 ( V_28 ) ;
if ( V_24 != 0 )
V_59 |= V_61 | V_62 ;
F_6 ( V_59 , V_13 -> V_8 + F_19 ( V_24 ) ) ;
F_6 ( V_51 , V_13 -> V_8 + F_20 ( V_24 ) ) ;
F_6 ( V_56 , V_13 -> V_8 + F_21 ( V_24 ) ) ;
F_6 ( V_53 , V_13 -> V_8 + F_22 ( V_24 ) ) ;
F_6 ( V_50 , V_13 -> V_8 + F_23 ( V_24 ) ) ;
if ( V_49 -> V_60 )
F_11 ( V_13 , V_24 ) ;
}
static int F_24 ( struct V_63 * V_64 , struct V_63 * V_65 ,
void * V_66 )
{
struct V_3 * V_4 = F_25 ( V_64 ) ;
struct V_67 * V_68 = V_66 ;
int V_69 ;
V_69 = F_26 ( V_68 , & V_4 -> V_7 ) ;
if ( V_69 < 0 ) {
F_27 ( V_64 , L_1 ,
V_64 -> V_70 -> V_71 , V_69 ) ;
return V_69 ;
}
return 0 ;
}
static void F_28 ( struct V_63 * V_64 , struct V_63 * V_65 ,
void * V_66 )
{
struct V_3 * V_4 = F_25 ( V_64 ) ;
struct V_67 * V_68 = V_66 ;
F_29 ( V_68 , & V_4 -> V_7 ) ;
}
static int F_30 ( struct V_72 * V_73 )
{
struct V_63 * V_64 = & V_73 -> V_64 ;
struct V_3 * V_4 ;
int V_74 ;
int V_1 ;
int V_69 ;
V_4 = F_31 ( V_64 , sizeof( * V_4 ) , V_75 ) ;
if ( ! V_4 )
return - V_76 ;
V_1 = F_32 ( V_73 , 0 ) ;
if ( V_1 < 0 )
return V_1 ;
V_69 = F_33 ( V_64 , V_1 , F_1 ,
V_77 , F_34 ( V_64 ) , V_4 ) ;
if ( V_69 < 0 ) {
F_27 ( V_64 , L_2 , V_1 , V_69 ) ;
return V_69 ;
}
V_74 = F_35 ( V_64 -> V_70 , V_78 ) ;
if ( V_74 < 0 ) {
F_27 ( V_64 , L_3 , V_74 ) ;
return V_74 ;
}
V_69 = F_36 ( V_64 , V_64 -> V_70 , & V_4 -> V_7 , V_74 ,
& V_79 ) ;
if ( V_69 ) {
F_27 ( V_64 , L_4 , V_69 ) ;
return V_69 ;
}
F_37 ( V_73 , V_4 ) ;
V_69 = F_38 ( V_64 , & V_80 ) ;
if ( V_69 )
F_27 ( V_64 , L_5 , V_69 ) ;
return V_69 ;
}
static int F_39 ( struct V_72 * V_73 )
{
F_40 ( & V_73 -> V_64 , & V_80 ) ;
return 0 ;
}
