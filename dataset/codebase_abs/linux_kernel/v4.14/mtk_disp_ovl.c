static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( int V_5 , void * V_6 )
{
struct V_1 * V_7 = V_6 ;
struct V_2 * V_8 = & V_7 -> V_4 ;
F_4 ( 0x0 , V_8 -> V_9 + V_10 ) ;
if ( ! V_7 -> V_11 )
return V_12 ;
F_5 ( V_7 -> V_11 , V_8 ) ;
return V_13 ;
}
static void F_6 ( struct V_2 * V_3 ,
struct V_14 * V_11 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_11 = V_11 ;
F_4 ( 0x0 , V_3 -> V_9 + V_10 ) ;
F_7 ( V_15 , V_3 -> V_9 + V_16 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_11 = NULL ;
F_7 ( 0x0 , V_3 -> V_9 + V_16 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_7 ( 0x1 , V_3 -> V_9 + V_17 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_7 ( 0x0 , V_3 -> V_9 + V_17 ) ;
}
static void F_11 ( struct V_2 * V_3 , unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 ,
unsigned int V_21 )
{
if ( V_18 != 0 && V_19 != 0 )
F_7 ( V_19 << 16 | V_18 , V_3 -> V_9 + V_22 ) ;
F_7 ( 0x0 , V_3 -> V_9 + V_23 ) ;
F_4 ( 0x1 , V_3 -> V_9 + V_24 ) ;
F_4 ( 0x0 , V_3 -> V_9 + V_24 ) ;
}
static void F_12 ( struct V_2 * V_3 , unsigned int V_25 )
{
unsigned int V_26 ;
F_4 ( 0x1 , V_3 -> V_9 + F_13 ( V_25 ) ) ;
F_4 ( V_27 , V_3 -> V_9 + F_14 ( V_25 ) ) ;
V_26 = F_15 ( V_3 -> V_9 + V_28 ) ;
V_26 = V_26 | F_16 ( V_25 ) ;
F_4 ( V_26 , V_3 -> V_9 + V_28 ) ;
}
static void F_17 ( struct V_2 * V_3 , unsigned int V_25 )
{
unsigned int V_26 ;
V_26 = F_15 ( V_3 -> V_9 + V_28 ) ;
V_26 = V_26 & ~ F_16 ( V_25 ) ;
F_4 ( V_26 , V_3 -> V_9 + V_28 ) ;
F_4 ( 0x0 , V_3 -> V_9 + F_13 ( V_25 ) ) ;
}
static unsigned int F_18 ( struct V_1 * V_8 , unsigned int V_29 )
{
switch ( V_29 ) {
default:
case V_30 :
return F_19 ( V_8 ) ;
case V_31 :
return F_19 ( V_8 ) | V_32 ;
case V_33 :
return F_20 ( V_8 ) ;
case V_34 :
return F_20 ( V_8 ) | V_32 ;
case V_35 :
case V_36 :
return V_37 ;
case V_38 :
case V_39 :
return V_37 | V_32 ;
case V_40 :
case V_41 :
return V_42 ;
case V_43 :
case V_44 :
return V_42 | V_32 ;
case V_45 :
return V_46 | V_47 ;
case V_48 :
return V_49 | V_47 ;
}
}
static void F_21 ( struct V_2 * V_3 , unsigned int V_25 ,
struct V_50 * V_51 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_52 * V_53 = & V_51 -> V_53 ;
unsigned int V_54 = V_53 -> V_54 ;
unsigned int V_55 = V_53 -> V_55 & 0xffff ;
unsigned int V_29 = V_53 -> V_56 ;
unsigned int V_57 = ( V_53 -> V_58 << 16 ) | V_53 -> V_59 ;
unsigned int V_60 = ( V_53 -> V_61 << 16 ) | V_53 -> V_62 ;
unsigned int V_63 ;
if ( ! V_53 -> V_64 )
F_17 ( V_3 , V_25 ) ;
V_63 = F_18 ( V_8 , V_29 ) ;
if ( V_25 != 0 )
V_63 |= V_65 | V_66 ;
F_7 ( V_63 , V_3 -> V_9 + F_22 ( V_25 ) ) ;
F_7 ( V_55 , V_3 -> V_9 + F_23 ( V_25 ) ) ;
F_7 ( V_60 , V_3 -> V_9 + F_24 ( V_25 ) ) ;
F_7 ( V_57 , V_3 -> V_9 + F_25 ( V_25 ) ) ;
F_7 ( V_54 , V_3 -> V_9 + F_26 ( V_8 , V_25 ) ) ;
if ( V_53 -> V_64 )
F_12 ( V_3 , V_25 ) ;
}
static int F_27 ( struct V_67 * V_68 , struct V_67 * V_69 ,
void * V_70 )
{
struct V_1 * V_7 = F_28 ( V_68 ) ;
struct V_71 * V_72 = V_70 ;
int V_73 ;
V_73 = F_29 ( V_72 , & V_7 -> V_4 ) ;
if ( V_73 < 0 ) {
F_30 ( V_68 , L_1 ,
V_68 -> V_74 , V_73 ) ;
return V_73 ;
}
return 0 ;
}
static void F_31 ( struct V_67 * V_68 , struct V_67 * V_69 ,
void * V_70 )
{
struct V_1 * V_7 = F_28 ( V_68 ) ;
struct V_71 * V_72 = V_70 ;
F_32 ( V_72 , & V_7 -> V_4 ) ;
}
static int F_33 ( struct V_75 * V_76 )
{
struct V_67 * V_68 = & V_76 -> V_68 ;
struct V_1 * V_7 ;
int V_77 ;
int V_5 ;
int V_73 ;
V_7 = F_34 ( V_68 , sizeof( * V_7 ) , V_78 ) ;
if ( ! V_7 )
return - V_79 ;
V_5 = F_35 ( V_76 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_77 = F_36 ( V_68 -> V_74 , V_80 ) ;
if ( V_77 < 0 ) {
F_30 ( V_68 , L_2 , V_77 ) ;
return V_77 ;
}
V_73 = F_37 ( V_68 , V_68 -> V_74 , & V_7 -> V_4 , V_77 ,
& V_81 ) ;
if ( V_73 ) {
F_30 ( V_68 , L_3 , V_73 ) ;
return V_73 ;
}
V_7 -> V_70 = F_38 ( V_68 ) ;
F_39 ( V_76 , V_7 ) ;
V_73 = F_40 ( V_68 , V_5 , F_3 ,
V_82 , F_41 ( V_68 ) , V_7 ) ;
if ( V_73 < 0 ) {
F_30 ( V_68 , L_4 , V_5 , V_73 ) ;
return V_73 ;
}
V_73 = F_42 ( V_68 , & V_83 ) ;
if ( V_73 )
F_30 ( V_68 , L_5 , V_73 ) ;
return V_73 ;
}
static int F_43 ( struct V_75 * V_76 )
{
F_44 ( & V_76 -> V_68 , & V_83 ) ;
return 0 ;
}
