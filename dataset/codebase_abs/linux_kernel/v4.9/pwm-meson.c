static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
int V_10 ;
if ( ! V_7 )
return - V_11 ;
if ( V_7 -> V_12 ) {
V_10 = F_5 ( V_7 -> V_13 , V_7 -> V_12 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 , L_1 ,
F_7 ( V_7 -> V_12 ) ,
F_7 ( V_7 -> V_13 ) , V_10 ) ;
return V_10 ;
}
}
V_10 = F_8 ( V_7 -> V_13 ) ;
if ( V_10 < 0 ) {
F_6 ( V_9 , L_2 ,
F_7 ( V_7 -> V_13 ) , V_10 ) ;
return V_10 ;
}
V_3 -> V_14 -> V_15 ( V_3 , V_5 , & V_7 -> V_16 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
if ( V_7 )
F_10 ( V_7 -> V_13 ) ;
}
static int F_11 ( struct V_1 * V_17 ,
struct V_6 * V_7 , unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 )
{
unsigned int V_21 , V_22 , V_23 ;
unsigned long V_24 = - 1 , V_25 ;
if ( ~ ( V_17 -> V_26 >> V_18 ) & 0x1 )
V_19 = V_20 - V_19 ;
if ( V_20 == V_7 -> V_16 . V_20 &&
V_19 == V_7 -> V_16 . V_27 )
return 0 ;
V_24 = F_12 ( V_7 -> V_13 ) ;
if ( V_24 == 0 ) {
F_6 ( V_17 -> V_3 . V_9 , L_3 ) ;
return - V_28 ;
}
F_13 ( V_17 -> V_3 . V_9 , L_4 , V_24 ) ;
V_25 = V_29 / V_24 ;
for ( V_21 = 0 ; V_21 < V_30 ; V_21 ++ ) {
V_22 = F_14 ( V_20 , V_25 * ( V_21 + 1 ) ) ;
F_13 ( V_17 -> V_3 . V_9 , L_5 ,
V_25 , V_21 , V_22 ) ;
if ( V_22 <= 0xffff )
break;
}
if ( V_21 == V_30 ) {
F_6 ( V_17 -> V_3 . V_9 , L_6 ) ;
return - V_28 ;
}
F_13 ( V_17 -> V_3 . V_9 , L_7 , V_20 ,
V_21 , V_22 ) ;
if ( V_19 == V_20 ) {
V_7 -> V_21 = V_21 ;
V_7 -> V_31 = V_22 ;
V_7 -> V_32 = 0 ;
} else if ( V_19 == 0 ) {
V_7 -> V_21 = V_21 ;
V_7 -> V_31 = 0 ;
V_7 -> V_32 = V_22 ;
} else {
V_23 = F_14 ( V_19 , V_25 * ( V_21 + 1 ) ) ;
if ( V_23 > 0xffff ) {
F_6 ( V_17 -> V_3 . V_9 , L_8 ) ;
return - V_28 ;
}
F_13 ( V_17 -> V_3 . V_9 , L_9 ,
V_19 , V_21 , V_23 ) ;
V_7 -> V_21 = V_21 ;
V_7 -> V_31 = V_23 ;
V_7 -> V_32 = V_22 - V_23 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_17 ,
struct V_6 * V_7 ,
unsigned int V_18 )
{
T_1 V_33 , V_34 , V_35 , V_36 ;
unsigned int V_37 ;
switch ( V_18 ) {
case 0 :
V_34 = V_38 ;
V_35 = V_39 ;
V_36 = V_40 ;
V_37 = V_41 ;
break;
case 1 :
V_34 = V_42 ;
V_35 = V_43 ;
V_36 = V_44 ;
V_37 = V_45 ;
break;
default:
return;
}
V_33 = F_16 ( V_17 -> V_46 + V_47 ) ;
V_33 &= ~ ( V_30 << V_34 ) ;
V_33 |= V_7 -> V_21 << V_34 ;
V_33 |= V_35 ;
F_17 ( V_33 , V_17 -> V_46 + V_47 ) ;
V_33 = ( V_7 -> V_31 << V_48 ) | V_7 -> V_32 ;
F_17 ( V_33 , V_17 -> V_46 + V_37 ) ;
V_33 = F_16 ( V_17 -> V_46 + V_47 ) ;
V_33 |= V_36 ;
F_17 ( V_33 , V_17 -> V_46 + V_47 ) ;
}
static void F_18 ( struct V_1 * V_17 , unsigned int V_18 )
{
T_1 V_33 , V_36 ;
switch ( V_18 ) {
case 0 :
V_36 = V_40 ;
break;
case 1 :
V_36 = V_44 ;
break;
default:
return;
}
V_33 = F_16 ( V_17 -> V_46 + V_47 ) ;
V_33 &= ~ V_36 ;
F_17 ( V_33 , V_17 -> V_46 + V_47 ) ;
}
static int F_19 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_49 * V_16 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned long V_50 ;
int V_10 = 0 ;
if ( ! V_16 )
return - V_28 ;
F_20 ( & V_17 -> V_51 , V_50 ) ;
if ( ! V_16 -> V_52 ) {
F_18 ( V_17 , V_5 -> V_53 ) ;
V_7 -> V_16 . V_52 = false ;
goto V_54;
}
if ( V_16 -> V_20 != V_7 -> V_16 . V_20 ||
V_16 -> V_27 != V_7 -> V_16 . V_27 ||
V_16 -> V_55 != V_7 -> V_16 . V_55 ) {
if ( V_7 -> V_16 . V_52 ) {
F_18 ( V_17 , V_5 -> V_53 ) ;
V_7 -> V_16 . V_52 = false ;
}
if ( V_16 -> V_55 != V_7 -> V_16 . V_55 ) {
if ( V_16 -> V_55 == V_56 )
V_17 -> V_26 |= F_21 ( V_5 -> V_53 ) ;
else
V_17 -> V_26 &= ~ F_21 ( V_5 -> V_53 ) ;
}
V_10 = F_11 ( V_17 , V_7 , V_5 -> V_53 ,
V_16 -> V_27 , V_16 -> V_20 ) ;
if ( V_10 < 0 )
goto V_54;
V_7 -> V_16 . V_55 = V_16 -> V_55 ;
V_7 -> V_16 . V_20 = V_16 -> V_20 ;
V_7 -> V_16 . V_27 = V_16 -> V_27 ;
}
if ( V_16 -> V_52 && ! V_7 -> V_16 . V_52 ) {
F_15 ( V_17 , V_7 , V_5 -> V_53 ) ;
V_7 -> V_16 . V_52 = true ;
}
V_54:
F_22 ( & V_17 -> V_51 , V_50 ) ;
return V_10 ;
}
static void F_23 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_49 * V_16 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
T_1 V_33 , V_57 ;
if ( ! V_16 )
return;
switch ( V_5 -> V_53 ) {
case 0 :
V_57 = V_40 ;
break;
case 1 :
V_57 = V_44 ;
break;
default:
return;
}
V_33 = F_16 ( V_17 -> V_46 + V_47 ) ;
V_16 -> V_52 = ( V_33 & V_57 ) != 0 ;
}
static int F_24 ( struct V_1 * V_17 ,
struct V_6 * V_58 )
{
struct V_8 * V_9 = V_17 -> V_3 . V_9 ;
struct V_59 * V_60 = V_9 -> V_61 ;
struct V_62 V_63 ;
unsigned int V_64 ;
char V_65 [ 255 ] ;
int V_10 ;
for ( V_64 = 0 ; V_64 < V_17 -> V_3 . V_66 ; V_64 ++ ) {
struct V_6 * V_7 = & V_58 [ V_64 ] ;
snprintf ( V_65 , sizeof( V_65 ) , L_10 , V_60 -> V_67 , V_64 ) ;
V_63 . V_65 = V_65 ;
V_63 . V_14 = & V_68 ;
V_63 . V_50 = V_69 ;
V_63 . V_70 = V_17 -> V_71 -> V_70 ;
V_63 . V_72 = 1 << V_73 ;
V_7 -> V_74 . V_75 = V_17 -> V_46 + V_47 ;
V_7 -> V_74 . V_76 = V_77 [ V_64 ] ;
V_7 -> V_74 . V_57 = F_21 ( V_73 ) - 1 ;
V_7 -> V_74 . V_50 = 0 ;
V_7 -> V_74 . V_51 = & V_17 -> V_51 ;
V_7 -> V_74 . V_78 = NULL ;
V_7 -> V_74 . V_79 . V_63 = & V_63 ;
V_7 -> V_13 = F_25 ( V_9 , & V_7 -> V_74 . V_79 ) ;
if ( F_26 ( V_7 -> V_13 ) ) {
V_10 = F_27 ( V_7 -> V_13 ) ;
F_6 ( V_9 , L_11 , V_65 , V_10 ) ;
return V_10 ;
}
snprintf ( V_65 , sizeof( V_65 ) , L_12 , V_64 ) ;
V_7 -> V_12 = F_28 ( V_9 , V_65 ) ;
if ( F_26 ( V_7 -> V_12 ) ) {
V_10 = F_27 ( V_7 -> V_12 ) ;
if ( V_10 == - V_80 )
return V_10 ;
V_7 -> V_12 = NULL ;
}
}
return 0 ;
}
static void F_29 ( struct V_1 * V_17 ,
struct V_6 * V_58 )
{
unsigned int V_64 ;
for ( V_64 = 0 ; V_64 < V_17 -> V_3 . V_66 ; V_64 ++ )
F_30 ( & V_17 -> V_3 . V_81 [ V_64 ] , & V_58 [ V_64 ] ) ;
}
static int F_31 ( struct V_82 * V_83 )
{
struct V_6 * V_58 ;
struct V_1 * V_17 ;
struct V_84 * V_85 ;
int V_10 ;
V_17 = F_32 ( & V_83 -> V_9 , sizeof( * V_17 ) , V_86 ) ;
if ( ! V_17 )
return - V_87 ;
V_85 = F_33 ( V_83 , V_88 , 0 ) ;
V_17 -> V_46 = F_34 ( & V_83 -> V_9 , V_85 ) ;
if ( F_26 ( V_17 -> V_46 ) )
return F_27 ( V_17 -> V_46 ) ;
F_35 ( & V_17 -> V_51 ) ;
V_17 -> V_3 . V_9 = & V_83 -> V_9 ;
V_17 -> V_3 . V_14 = & V_89 ;
V_17 -> V_3 . V_46 = - 1 ;
V_17 -> V_3 . V_66 = 2 ;
V_17 -> V_3 . V_90 = V_91 ;
V_17 -> V_3 . V_92 = 3 ;
V_17 -> V_71 = F_36 ( & V_83 -> V_9 ) ;
V_17 -> V_26 = F_21 ( V_17 -> V_3 . V_66 ) - 1 ;
V_58 = F_37 ( & V_83 -> V_9 , V_17 -> V_3 . V_66 , sizeof( * V_17 ) ,
V_86 ) ;
if ( ! V_58 )
return - V_87 ;
V_10 = F_24 ( V_17 , V_58 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_38 ( & V_17 -> V_3 ) ;
if ( V_10 < 0 ) {
F_6 ( & V_83 -> V_9 , L_13 , V_10 ) ;
return V_10 ;
}
F_29 ( V_17 , V_58 ) ;
F_39 ( V_83 , V_17 ) ;
return 0 ;
}
static int F_40 ( struct V_82 * V_83 )
{
struct V_1 * V_17 = F_41 ( V_83 ) ;
return F_42 ( & V_17 -> V_3 ) ;
}
