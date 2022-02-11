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
static int F_14 ( struct V_21 * V_22 , unsigned int V_1 ,
unsigned long V_30 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
switch ( F_15 ( V_30 ) ) {
case V_31 :
return F_4 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) ,
V_32 , V_33 ) ;
case V_34 :
return F_4 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) ,
V_32 , V_35 ) ;
default:
break;
}
return - V_36 ;
}
static int F_16 ( struct V_37 * V_38 , unsigned int type )
{
struct V_21 * V_22 = F_17 ( V_38 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
switch ( type ) {
case V_39 :
V_12 -> V_20 = V_40 ;
break;
case V_41 :
V_12 -> V_20 = V_19 ;
break;
case V_42 :
V_12 -> V_20 = V_43 ;
break;
case V_44 :
V_12 -> V_20 = V_45 ;
break;
default:
return - V_46 ;
}
V_12 -> V_47 |= V_48 ;
return 0 ;
}
static void F_18 ( struct V_37 * V_38 )
{
struct V_21 * V_22 = F_17 ( V_38 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
F_19 ( & V_12 -> V_49 ) ;
}
static void F_20 ( struct V_37 * V_38 )
{
struct V_21 * V_22 = F_17 ( V_38 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
int V_1 = V_38 -> V_50 ;
if ( V_12 -> V_47 & V_48 )
F_5 ( V_12 , V_1 ) ;
if ( V_12 -> V_47 & V_51 )
F_2 ( V_12 , V_1 ) ;
V_12 -> V_47 = 0 ;
F_21 ( & V_12 -> V_49 ) ;
}
static void F_22 ( struct V_37 * V_38 )
{
struct V_21 * V_22 = F_17 ( V_38 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
V_12 -> V_17 = false ;
V_12 -> V_47 |= V_51 ;
}
static void F_23 ( struct V_37 * V_38 )
{
struct V_21 * V_22 = F_17 ( V_38 ) ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
V_12 -> V_17 = true ;
V_12 -> V_47 |= V_51 ;
}
static T_1 F_24 ( int V_52 , void * V_38 )
{
struct V_11 * V_12 = (struct V_11 * ) V_38 ;
unsigned int V_53 , V_54 , V_1 , V_13 , V_55 ;
T_2 V_56 [ 2 ] ;
if ( F_25 ( V_12 -> V_18 , V_57 , V_56 , 2 ) ) {
F_26 ( V_12 -> V_58 , L_1 ) ;
return V_59 ;
}
V_53 = ( V_56 [ 0 ] & V_60 ) | ( ( V_56 [ 1 ] & V_61 ) << 7 ) ;
if ( ! V_53 )
return V_59 ;
while ( V_53 ) {
F_27 (gpio, (const unsigned long *)&pending,
WCOVE_GPIO_NUM) {
V_55 = ( V_1 > V_14 ) ? 1 : 0 ;
V_13 = ( V_55 == 1 ) ? F_3 ( V_1 - V_14 ) :
F_3 ( V_1 ) ;
V_54 = F_28 ( V_12 -> V_22 . V_62 , V_1 ) ;
F_29 ( V_54 ) ;
F_4 ( V_12 -> V_18 , V_57 + V_55 ,
V_13 , V_13 ) ;
}
if ( F_25 ( V_12 -> V_18 , V_57 , V_56 , 2 ) ) {
F_26 ( V_12 -> V_58 , L_2 ) ;
break;
}
V_53 = ( V_56 [ 0 ] & V_60 ) | ( ( V_56 [ 1 ] & V_61 ) << 7 ) ;
}
return V_63 ;
}
static void F_30 ( struct V_64 * V_65 ,
struct V_21 * V_22 )
{
unsigned int V_66 , V_67 , V_68 , V_69 ;
struct V_11 * V_12 = F_7 ( V_22 ) ;
int V_1 , V_55 , V_70 , V_28 = 0 ;
for ( V_1 = 0 ; V_1 < V_71 ; V_1 ++ ) {
V_70 = V_1 < V_14 ? 0 : 1 ;
V_28 += F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_23 ) , & V_66 ) ;
V_28 += F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_8 ) , & V_67 ) ;
V_28 += F_11 ( V_12 -> V_18 , V_15 + V_70 ,
& V_68 ) ;
V_28 += F_11 ( V_12 -> V_18 , V_57 + V_70 ,
& V_69 ) ;
if ( V_28 ) {
F_31 ( L_3 ) ;
break;
}
V_55 = V_1 % 8 ;
F_32 ( V_65 , L_4 ,
V_1 , V_66 & V_29 ? L_5 : L_6 ,
V_67 & 0x1 ? L_7 : L_8 ,
V_67 & V_45 ? L_9 : L_10 ,
V_67 & V_43 ? L_11 : L_10 ,
V_66 ,
V_68 & F_3 ( V_55 ) ? L_12 : L_13 ,
V_69 & F_3 ( V_55 ) ? L_14 : L_15 ) ;
}
}
static int F_33 ( struct V_72 * V_73 )
{
struct V_74 * V_75 ;
struct V_11 * V_12 ;
int V_54 , V_28 , V_52 ;
struct V_76 * V_58 ;
V_75 = F_34 ( V_73 -> V_58 . V_77 ) ;
if ( ! V_75 )
return - V_78 ;
V_52 = F_35 ( V_73 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
V_58 = & V_73 -> V_58 ;
V_12 = F_36 ( V_58 , sizeof( * V_12 ) , V_79 ) ;
if ( ! V_12 )
return - V_80 ;
V_12 -> V_81 = V_75 -> V_82 ;
F_37 ( V_73 , V_12 ) ;
F_38 ( & V_12 -> V_49 ) ;
V_12 -> V_22 . V_83 = V_84 ;
V_12 -> V_22 . V_85 = F_6 ;
V_12 -> V_22 . V_86 = F_9 ;
V_12 -> V_22 . V_87 = F_10 ;
V_12 -> V_22 . V_88 = F_12 ;
V_12 -> V_22 . V_89 = F_13 ;
V_12 -> V_22 . V_90 = F_14 ,
V_12 -> V_22 . V_91 = - 1 ;
V_12 -> V_22 . V_92 = V_93 ;
V_12 -> V_22 . V_94 = true ;
V_12 -> V_22 . V_77 = V_73 -> V_58 . V_77 ;
V_12 -> V_22 . V_95 = F_30 ;
V_12 -> V_58 = V_58 ;
V_12 -> V_18 = V_75 -> V_18 ;
V_28 = F_39 ( V_58 , & V_12 -> V_22 , V_12 ) ;
if ( V_28 ) {
F_26 ( V_58 , L_16 , V_28 ) ;
return V_28 ;
}
V_28 = F_40 ( & V_12 -> V_22 , & V_96 , 0 ,
V_97 , V_39 ) ;
if ( V_28 ) {
F_26 ( V_58 , L_17 , V_28 ) ;
return V_28 ;
}
V_54 = F_41 ( V_12 -> V_81 , V_52 ) ;
if ( V_54 < 0 ) {
F_26 ( V_58 , L_18 , V_52 ) ;
return V_54 ;
}
V_28 = F_42 ( V_58 , V_54 , NULL ,
F_24 , V_98 , V_73 -> V_99 , V_12 ) ;
if ( V_28 ) {
F_26 ( V_58 , L_19 , V_54 ) ;
return V_28 ;
}
F_43 ( & V_12 -> V_22 , & V_96 , V_54 ) ;
return 0 ;
}
