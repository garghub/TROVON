static inline unsigned int F_1 ( int V_1 , enum V_2 V_3 )
{
unsigned int V_4 ;
int V_5 ;
if ( V_1 < V_6 )
V_5 = 0 ;
else if ( V_1 < V_6 + V_7 )
V_5 = 1 ;
else
V_5 = 2 ;
if ( V_3 == V_8 )
V_4 = V_9 + V_5 ;
else
V_4 = V_10 + V_5 ;
return V_4 ;
}
static void F_2 ( struct V_11 * V_12 , int V_1 )
{
unsigned int V_4 , V_13 ;
if ( V_1 < V_14 ) {
V_4 = V_15 ;
V_13 = F_3 ( V_1 % V_14 ) ;
} else {
V_4 = V_15 + 1 ;
V_13 = F_3 ( ( V_1 - V_14 ) % V_16 ) ;
}
if ( V_12 -> V_17 )
F_4 ( V_12 -> V_18 , V_4 , V_13 , V_13 ) ;
else
F_4 ( V_12 -> V_18 , V_4 , V_13 , 0 ) ;
}
static void F_5 ( struct V_11 * V_12 , int V_1 )
{
unsigned int V_4 = F_1 ( V_1 , V_8 ) ;
F_4 ( V_12 -> V_18 , V_4 , V_19 , V_12 -> V_20 ) ;
}
static int F_6 ( struct V_21 * V_22 , unsigned int V_1 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
return F_8 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) ,
V_24 ) ;
}
static int F_9 ( struct V_21 * V_22 , unsigned int V_1 ,
int V_25 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
return F_8 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) ,
V_26 | V_25 ) ;
}
static int F_10 ( struct V_21 * V_22 , unsigned int V_1 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
unsigned int V_27 ;
int V_28 ;
V_28 = F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) , & V_27 ) ;
if ( V_28 )
return V_28 ;
return ! ( V_27 & V_29 ) ;
}
static int F_12 ( struct V_21 * V_22 , unsigned int V_1 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
unsigned int V_27 ;
int V_28 ;
V_28 = F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_8 ) , & V_27 ) ;
if ( V_28 )
return V_28 ;
return V_27 & 0x1 ;
}
static void F_13 ( struct V_21 * V_22 ,
unsigned int V_1 , int V_25 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
if ( V_25 )
F_4 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) , 1 , 1 ) ;
else
F_4 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) , 1 , 0 ) ;
}
static int F_14 ( struct V_21 * V_22 ,
unsigned int V_1 ,
enum V_30 V_31 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
switch ( V_31 ) {
case V_32 :
return F_4 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) ,
V_33 , V_34 ) ;
case V_35 :
return F_4 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) ,
V_33 , V_36 ) ;
default:
break;
}
return - V_37 ;
}
static int F_15 ( struct V_38 * V_39 , unsigned int type )
{
struct V_21 * V_22 = F_16 ( V_39 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
switch ( type ) {
case V_40 :
V_12 -> V_20 = V_41 ;
break;
case V_42 :
V_12 -> V_20 = V_19 ;
break;
case V_43 :
V_12 -> V_20 = V_44 ;
break;
case V_45 :
V_12 -> V_20 = V_46 ;
break;
default:
return - V_47 ;
}
V_12 -> V_48 |= V_49 ;
return 0 ;
}
static void F_17 ( struct V_38 * V_39 )
{
struct V_21 * V_22 = F_16 ( V_39 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
F_18 ( & V_12 -> V_50 ) ;
}
static void F_19 ( struct V_38 * V_39 )
{
struct V_21 * V_22 = F_16 ( V_39 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
int V_1 = V_39 -> V_51 ;
if ( V_12 -> V_48 & V_49 )
F_5 ( V_12 , V_1 ) ;
if ( V_12 -> V_48 & V_52 )
F_2 ( V_12 , V_1 ) ;
V_12 -> V_48 = 0 ;
F_20 ( & V_12 -> V_50 ) ;
}
static void F_21 ( struct V_38 * V_39 )
{
struct V_21 * V_22 = F_16 ( V_39 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
V_12 -> V_17 = false ;
V_12 -> V_48 |= V_52 ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_21 * V_22 = F_16 ( V_39 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
V_12 -> V_17 = true ;
V_12 -> V_48 |= V_52 ;
}
static T_1 F_23 ( int V_53 , void * V_39 )
{
struct V_11 * V_12 = (struct V_11 * ) V_39 ;
unsigned int V_54 , V_55 , V_1 , V_13 , V_56 ;
T_2 V_57 [ 2 ] ;
if ( F_24 ( V_12 -> V_18 , V_58 , V_57 , 2 ) ) {
F_25 ( V_12 -> V_59 , L_1 ) ;
return V_60 ;
}
V_54 = V_57 [ 0 ] | ( V_57 [ 1 ] << 8 ) ;
if ( ! V_54 )
return V_60 ;
while ( V_54 ) {
F_26 (gpio, (const unsigned long *)&pending,
GROUP0_NR_IRQS) {
V_56 = ( V_1 > V_14 ) ? 1 : 0 ;
V_13 = ( V_56 == 1 ) ? F_3 ( V_1 - V_14 ) :
F_3 ( V_1 ) ;
V_55 = F_27 ( V_12 -> V_22 . V_61 , V_1 ) ;
F_28 ( V_55 ) ;
F_4 ( V_12 -> V_18 , V_58 + V_56 ,
V_13 , V_13 ) ;
}
if ( F_24 ( V_12 -> V_18 , V_58 , V_57 , 2 ) ) {
F_25 ( V_12 -> V_59 , L_2 ) ;
break;
}
V_54 = V_57 [ 0 ] | ( V_57 [ 1 ] << 8 ) ;
}
return V_62 ;
}
static void F_29 ( struct V_63 * V_64 ,
struct V_21 * V_22 )
{
unsigned int V_65 , V_66 , V_67 , V_68 ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
int V_1 , V_56 , V_69 , V_28 = 0 ;
for ( V_1 = 0 ; V_1 < V_70 ; V_1 ++ ) {
V_69 = V_1 < V_14 ? 0 : 1 ;
V_28 += F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) , & V_65 ) ;
V_28 += F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_8 ) , & V_66 ) ;
V_28 += F_11 ( V_12 -> V_18 , V_15 + V_69 ,
& V_67 ) ;
V_28 += F_11 ( V_12 -> V_18 , V_58 + V_69 ,
& V_68 ) ;
if ( V_28 ) {
F_30 ( L_3 ) ;
break;
}
V_56 = V_1 % 8 ;
F_31 ( V_64 , L_4 ,
V_1 , V_65 & V_29 ? L_5 : L_6 ,
V_66 & 0x1 ? L_7 : L_8 ,
V_66 & V_46 ? L_9 : L_10 ,
V_66 & V_44 ? L_11 : L_10 ,
V_65 ,
V_67 & F_3 ( V_56 ) ? L_12 : L_13 ,
V_68 & F_3 ( V_56 ) ? L_14 : L_15 ) ;
}
}
static int F_32 ( struct V_71 * V_72 )
{
struct V_73 * V_74 ;
struct V_11 * V_12 ;
int V_55 , V_28 , V_53 ;
struct V_75 * V_59 ;
V_74 = F_33 ( V_72 -> V_59 . V_76 ) ;
if ( ! V_74 )
return - V_77 ;
V_53 = F_34 ( V_72 , 0 ) ;
if ( V_53 < 0 )
return V_53 ;
V_59 = & V_72 -> V_59 ;
V_12 = F_35 ( V_59 , sizeof( * V_12 ) , V_78 ) ;
if ( ! V_12 )
return - V_79 ;
V_12 -> V_80 = V_74 -> V_81 ;
F_36 ( V_72 , V_12 ) ;
F_37 ( & V_12 -> V_50 ) ;
V_12 -> V_22 . V_82 = V_83 ;
V_12 -> V_22 . V_84 = F_6 ;
V_12 -> V_22 . V_85 = F_9 ;
V_12 -> V_22 . V_86 = F_10 ;
V_12 -> V_22 . V_87 = F_12 ;
V_12 -> V_22 . V_88 = F_13 ;
V_12 -> V_22 . V_89 = F_14 ,
V_12 -> V_22 . V_90 = - 1 ;
V_12 -> V_22 . V_91 = V_92 ;
V_12 -> V_22 . V_93 = true ;
V_12 -> V_22 . V_76 = V_72 -> V_59 . V_76 ;
V_12 -> V_22 . V_94 = F_29 ;
V_12 -> V_59 = V_59 ;
V_12 -> V_18 = V_74 -> V_18 ;
V_28 = F_38 ( V_59 , & V_12 -> V_22 , V_12 ) ;
if ( V_28 ) {
F_25 ( V_59 , L_16 , V_28 ) ;
return V_28 ;
}
V_28 = F_39 ( & V_12 -> V_22 , & V_95 , 0 ,
V_96 , V_40 ) ;
if ( V_28 ) {
F_25 ( V_59 , L_17 , V_28 ) ;
return V_28 ;
}
V_55 = F_40 ( V_12 -> V_80 , V_53 ) ;
if ( V_55 < 0 ) {
F_25 ( V_59 , L_18 , V_53 ) ;
return V_55 ;
}
V_28 = F_41 ( V_59 , V_55 , NULL ,
F_23 , V_97 , V_72 -> V_98 , V_12 ) ;
if ( V_28 ) {
F_25 ( V_59 , L_19 , V_55 ) ;
return V_28 ;
}
F_42 ( & V_12 -> V_22 , & V_95 , V_55 ) ;
return 0 ;
}
