static inline unsigned int F_1 ( int V_1 , enum V_2 V_3 )
{
unsigned int V_4 ;
if ( V_1 >= V_5 )
return - V_6 ;
if ( V_3 == V_7 )
V_4 = V_8 + V_1 ;
else
V_4 = V_9 + V_1 ;
return V_4 ;
}
static void F_2 ( struct V_10 * V_11 , int V_1 )
{
unsigned int V_4 , V_12 ;
if ( V_1 < V_13 ) {
V_4 = V_14 ;
V_12 = F_3 ( V_1 % V_13 ) ;
} else {
V_4 = V_14 + 1 ;
V_12 = F_3 ( ( V_1 - V_13 ) % V_15 ) ;
}
if ( V_11 -> V_16 )
F_4 ( V_11 -> V_17 , V_4 , V_12 , V_12 ) ;
else
F_4 ( V_11 -> V_17 , V_4 , V_12 , 0 ) ;
}
static void F_5 ( struct V_10 * V_11 , int V_1 )
{
int V_4 = F_1 ( V_1 , V_7 ) ;
if ( V_4 < 0 )
return;
F_4 ( V_11 -> V_17 , V_4 , V_18 , V_11 -> V_19 ) ;
}
static int F_6 ( struct V_20 * V_21 , unsigned int V_1 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
int V_4 = F_1 ( V_1 , V_22 ) ;
if ( V_4 < 0 )
return 0 ;
return F_8 ( V_11 -> V_17 , V_4 , V_23 ) ;
}
static int F_9 ( struct V_20 * V_21 , unsigned int V_1 ,
int V_24 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
int V_4 = F_1 ( V_1 , V_22 ) ;
if ( V_4 < 0 )
return 0 ;
return F_8 ( V_11 -> V_17 , V_4 , V_25 | V_24 ) ;
}
static int F_10 ( struct V_20 * V_21 , unsigned int V_1 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
unsigned int V_26 ;
int V_27 , V_4 = F_1 ( V_1 , V_22 ) ;
if ( V_4 < 0 )
return 0 ;
V_27 = F_11 ( V_11 -> V_17 , V_4 , & V_26 ) ;
if ( V_27 )
return V_27 ;
return ! ( V_26 & V_28 ) ;
}
static int F_12 ( struct V_20 * V_21 , unsigned int V_1 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
unsigned int V_26 ;
int V_27 , V_4 = F_1 ( V_1 , V_7 ) ;
if ( V_4 < 0 )
return 0 ;
V_27 = F_11 ( V_11 -> V_17 , V_4 , & V_26 ) ;
if ( V_27 )
return V_27 ;
return V_26 & 0x1 ;
}
static void F_13 ( struct V_20 * V_21 ,
unsigned int V_1 , int V_24 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
int V_4 = F_1 ( V_1 , V_22 ) ;
if ( V_4 < 0 )
return;
if ( V_24 )
F_4 ( V_11 -> V_17 , V_4 , 1 , 1 ) ;
else
F_4 ( V_11 -> V_17 , V_4 , 1 , 0 ) ;
}
static int F_14 ( struct V_20 * V_21 , unsigned int V_1 ,
unsigned long V_29 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
int V_4 = F_1 ( V_1 , V_22 ) ;
if ( V_4 < 0 )
return 0 ;
switch ( F_15 ( V_29 ) ) {
case V_30 :
return F_4 ( V_11 -> V_17 , V_4 , V_31 ,
V_32 ) ;
case V_33 :
return F_4 ( V_11 -> V_17 , V_4 , V_31 ,
V_34 ) ;
default:
break;
}
return - V_35 ;
}
static int F_16 ( struct V_36 * V_37 , unsigned int type )
{
struct V_20 * V_21 = F_17 ( V_37 ) ;
struct V_10 * V_11 = F_7 ( V_21 ) ;
if ( V_37 -> V_38 >= V_5 )
return 0 ;
switch ( type ) {
case V_39 :
V_11 -> V_19 = V_40 ;
break;
case V_41 :
V_11 -> V_19 = V_18 ;
break;
case V_42 :
V_11 -> V_19 = V_43 ;
break;
case V_44 :
V_11 -> V_19 = V_45 ;
break;
default:
return - V_46 ;
}
V_11 -> V_47 |= V_48 ;
return 0 ;
}
static void F_18 ( struct V_36 * V_37 )
{
struct V_20 * V_21 = F_17 ( V_37 ) ;
struct V_10 * V_11 = F_7 ( V_21 ) ;
F_19 ( & V_11 -> V_49 ) ;
}
static void F_20 ( struct V_36 * V_37 )
{
struct V_20 * V_21 = F_17 ( V_37 ) ;
struct V_10 * V_11 = F_7 ( V_21 ) ;
int V_1 = V_37 -> V_38 ;
if ( V_11 -> V_47 & V_48 )
F_5 ( V_11 , V_1 ) ;
if ( V_11 -> V_47 & V_50 )
F_2 ( V_11 , V_1 ) ;
V_11 -> V_47 = 0 ;
F_21 ( & V_11 -> V_49 ) ;
}
static void F_22 ( struct V_36 * V_37 )
{
struct V_20 * V_21 = F_17 ( V_37 ) ;
struct V_10 * V_11 = F_7 ( V_21 ) ;
if ( V_37 -> V_38 >= V_5 )
return;
V_11 -> V_16 = false ;
V_11 -> V_47 |= V_50 ;
}
static void F_23 ( struct V_36 * V_37 )
{
struct V_20 * V_21 = F_17 ( V_37 ) ;
struct V_10 * V_11 = F_7 ( V_21 ) ;
if ( V_37 -> V_38 >= V_5 )
return;
V_11 -> V_16 = true ;
V_11 -> V_47 |= V_50 ;
}
static T_1 F_24 ( int V_51 , void * V_37 )
{
struct V_10 * V_11 = (struct V_10 * ) V_37 ;
unsigned int V_52 , V_53 , V_1 , V_12 , V_54 ;
T_2 V_55 [ 2 ] ;
if ( F_25 ( V_11 -> V_17 , V_56 , V_55 , 2 ) ) {
F_26 ( V_11 -> V_57 , L_1 ) ;
return V_58 ;
}
V_52 = ( V_55 [ 0 ] & V_59 ) | ( ( V_55 [ 1 ] & V_60 ) << 7 ) ;
if ( ! V_52 )
return V_58 ;
while ( V_52 ) {
F_27 (gpio, (const unsigned long *)&pending,
WCOVE_GPIO_NUM) {
V_54 = ( V_1 > V_13 ) ? 1 : 0 ;
V_12 = ( V_54 == 1 ) ? F_3 ( V_1 - V_13 ) :
F_3 ( V_1 ) ;
V_53 = F_28 ( V_11 -> V_21 . V_61 , V_1 ) ;
F_29 ( V_53 ) ;
F_4 ( V_11 -> V_17 , V_56 + V_54 ,
V_12 , V_12 ) ;
}
if ( F_25 ( V_11 -> V_17 , V_56 , V_55 , 2 ) ) {
F_26 ( V_11 -> V_57 , L_2 ) ;
break;
}
V_52 = ( V_55 [ 0 ] & V_59 ) | ( ( V_55 [ 1 ] & V_60 ) << 7 ) ;
}
return V_62 ;
}
static void F_30 ( struct V_63 * V_64 ,
struct V_20 * V_21 )
{
unsigned int V_65 , V_66 , V_67 , V_68 ;
struct V_10 * V_11 = F_7 ( V_21 ) ;
int V_1 , V_54 , V_69 , V_27 = 0 ;
for ( V_1 = 0 ; V_1 < V_5 ; V_1 ++ ) {
V_69 = V_1 < V_13 ? 0 : 1 ;
V_27 += F_11 ( V_11 -> V_17 , F_1 ( V_1 , V_22 ) , & V_65 ) ;
V_27 += F_11 ( V_11 -> V_17 , F_1 ( V_1 , V_7 ) , & V_66 ) ;
V_27 += F_11 ( V_11 -> V_17 , V_14 + V_69 ,
& V_67 ) ;
V_27 += F_11 ( V_11 -> V_17 , V_56 + V_69 ,
& V_68 ) ;
if ( V_27 ) {
F_31 ( L_3 ) ;
break;
}
V_54 = V_1 % 8 ;
F_32 ( V_64 , L_4 ,
V_1 , V_65 & V_28 ? L_5 : L_6 ,
V_66 & 0x1 ? L_7 : L_8 ,
V_66 & V_45 ? L_9 : L_10 ,
V_66 & V_43 ? L_11 : L_10 ,
V_65 ,
V_67 & F_3 ( V_54 ) ? L_12 : L_13 ,
V_68 & F_3 ( V_54 ) ? L_14 : L_15 ) ;
}
}
static int F_33 ( struct V_70 * V_71 )
{
struct V_72 * V_73 ;
struct V_10 * V_11 ;
int V_53 , V_27 , V_51 ;
struct V_74 * V_57 ;
V_73 = F_34 ( V_71 -> V_57 . V_75 ) ;
if ( ! V_73 )
return - V_76 ;
V_51 = F_35 ( V_71 , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
V_57 = & V_71 -> V_57 ;
V_11 = F_36 ( V_57 , sizeof( * V_11 ) , V_77 ) ;
if ( ! V_11 )
return - V_78 ;
V_11 -> V_79 = V_73 -> V_80 ;
F_37 ( V_71 , V_11 ) ;
F_38 ( & V_11 -> V_49 ) ;
V_11 -> V_21 . V_81 = V_82 ;
V_11 -> V_21 . V_83 = F_6 ;
V_11 -> V_21 . V_84 = F_9 ;
V_11 -> V_21 . V_85 = F_10 ;
V_11 -> V_21 . V_86 = F_12 ;
V_11 -> V_21 . V_87 = F_13 ;
V_11 -> V_21 . V_88 = F_14 ,
V_11 -> V_21 . V_89 = - 1 ;
V_11 -> V_21 . V_90 = V_91 ;
V_11 -> V_21 . V_92 = true ;
V_11 -> V_21 . V_75 = V_71 -> V_57 . V_75 ;
V_11 -> V_21 . V_93 = F_30 ;
V_11 -> V_57 = V_57 ;
V_11 -> V_17 = V_73 -> V_17 ;
V_27 = F_39 ( V_57 , & V_11 -> V_21 , V_11 ) ;
if ( V_27 ) {
F_26 ( V_57 , L_16 , V_27 ) ;
return V_27 ;
}
V_27 = F_40 ( & V_11 -> V_21 , & V_94 , 0 ,
V_95 , V_39 ) ;
if ( V_27 ) {
F_26 ( V_57 , L_17 , V_27 ) ;
return V_27 ;
}
V_53 = F_41 ( V_11 -> V_79 , V_51 ) ;
if ( V_53 < 0 ) {
F_26 ( V_57 , L_18 , V_51 ) ;
return V_53 ;
}
V_27 = F_42 ( V_57 , V_53 , NULL ,
F_24 , V_96 , V_71 -> V_97 , V_11 ) ;
if ( V_27 ) {
F_26 ( V_57 , L_19 , V_53 ) ;
return V_27 ;
}
F_43 ( & V_11 -> V_21 , & V_94 , V_53 ) ;
V_27 = F_4 ( V_11 -> V_17 , V_14 , V_59 ,
0x00 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_4 ( V_11 -> V_17 , V_14 + 1 , V_60 ,
0x00 ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
