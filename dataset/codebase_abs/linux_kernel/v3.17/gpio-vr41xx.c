static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 |= V_2 ;
F_3 ( V_1 , V_3 ) ;
return V_3 ;
}
static inline T_1 F_4 ( T_1 V_1 , T_1 V_4 )
{
T_1 V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 &= ~ V_4 ;
F_3 ( V_1 , V_3 ) ;
return V_3 ;
}
static void F_5 ( struct V_5 * V_6 )
{
F_3 ( V_7 , 1 << F_6 ( V_6 -> V_8 ) ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
F_4 ( V_9 , 1 << F_6 ( V_6 -> V_8 ) ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
unsigned int V_10 ;
V_10 = F_6 ( V_6 -> V_8 ) ;
F_4 ( V_9 , 1 << V_10 ) ;
F_3 ( V_7 , 1 << V_10 ) ;
}
static void F_9 ( struct V_5 * V_6 )
{
F_1 ( V_9 , 1 << F_6 ( V_6 -> V_8 ) ) ;
}
static unsigned int F_10 ( struct V_5 * V_3 )
{
if ( F_11 ( & V_11 , V_3 -> V_12 ) )
F_12 ( V_11 . V_13 ,
L_1 ,
V_3 -> V_12 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static void F_13 ( struct V_5 * V_3 )
{
F_7 ( V_3 ) ;
F_14 ( & V_11 , V_3 -> V_12 ) ;
}
static void F_15 ( struct V_5 * V_6 )
{
F_3 ( V_14 ,
1 << ( F_6 ( V_6 -> V_8 ) - V_15 ) ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
F_4 ( V_16 , 1 << ( F_6 ( V_6 -> V_8 ) - V_15 ) ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
unsigned int V_10 ;
V_10 = F_6 ( V_6 -> V_8 ) - V_15 ;
F_4 ( V_16 , 1 << V_10 ) ;
F_3 ( V_14 , 1 << V_10 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
F_1 ( V_16 , 1 << ( F_6 ( V_6 -> V_8 ) - V_15 ) ) ;
}
static int F_19 ( unsigned int V_8 )
{
T_1 V_17 , V_18 , V_19 , V_20 ;
int V_21 ;
V_17 = F_2 ( V_7 ) ;
V_18 = F_2 ( V_14 ) ;
V_19 = F_2 ( V_9 ) ;
V_20 = F_2 ( V_16 ) ;
V_19 &= V_17 ;
V_20 &= V_18 ;
if ( V_19 ) {
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ ) {
if ( V_19 & ( 1 << V_21 ) )
return F_20 ( V_21 ) ;
}
} else if ( V_20 ) {
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ ) {
if ( V_20 & ( 1 << V_21 ) )
return F_20 ( V_21 + V_15 ) ;
}
}
F_21 ( V_22 L_2 ,
V_19 , V_17 , V_20 , V_18 ) ;
F_22 ( & V_23 ) ;
return - V_24 ;
}
void F_23 ( unsigned int V_10 , T_2 V_25 ,
T_3 signal )
{
T_1 V_26 ;
if ( V_10 < V_15 ) {
V_26 = 1 << V_10 ;
if ( V_25 != V_27 ) {
F_1 ( V_28 , V_26 ) ;
if ( signal == V_29 )
F_1 ( V_30 , V_26 ) ;
else
F_4 ( V_30 , V_26 ) ;
if ( V_31 & V_32 ) {
switch ( V_25 ) {
case V_33 :
F_1 ( V_34 , V_26 ) ;
F_4 ( V_35 , V_26 ) ;
break;
case V_36 :
F_4 ( V_34 , V_26 ) ;
F_1 ( V_35 , V_26 ) ;
break;
default:
F_1 ( V_34 , V_26 ) ;
F_1 ( V_35 , V_26 ) ;
break;
}
}
F_24 ( F_20 ( V_10 ) ,
& V_37 ,
V_38 ) ;
} else {
F_4 ( V_28 , V_26 ) ;
F_4 ( V_30 , V_26 ) ;
F_24 ( F_20 ( V_10 ) ,
& V_37 ,
V_39 ) ;
}
F_3 ( V_7 , V_26 ) ;
} else if ( V_10 < V_40 ) {
V_26 = 1 << ( V_10 - V_15 ) ;
if ( V_25 != V_27 ) {
F_1 ( V_41 , V_26 ) ;
if ( signal == V_29 )
F_1 ( V_42 , V_26 ) ;
else
F_4 ( V_42 , V_26 ) ;
if ( V_31 & V_32 ) {
switch ( V_25 ) {
case V_33 :
F_1 ( V_43 , V_26 ) ;
F_4 ( V_44 , V_26 ) ;
break;
case V_36 :
F_4 ( V_43 , V_26 ) ;
F_1 ( V_44 , V_26 ) ;
break;
default:
F_1 ( V_43 , V_26 ) ;
F_1 ( V_44 , V_26 ) ;
break;
}
}
F_24 ( F_20 ( V_10 ) ,
& V_45 ,
V_38 ) ;
} else {
F_4 ( V_41 , V_26 ) ;
F_4 ( V_42 , V_26 ) ;
F_24 ( F_20 ( V_10 ) ,
& V_45 ,
V_39 ) ;
}
F_3 ( V_14 , V_26 ) ;
}
}
void F_25 ( unsigned int V_10 , T_4 V_46 )
{
T_1 V_26 ;
if ( V_10 < V_15 ) {
V_26 = 1 << V_10 ;
if ( V_46 == V_47 )
F_1 ( V_48 , V_26 ) ;
else
F_4 ( V_48 , V_26 ) ;
F_3 ( V_7 , V_26 ) ;
} else if ( V_10 < V_40 ) {
V_26 = 1 << ( V_10 - V_15 ) ;
if ( V_46 == V_47 )
F_1 ( V_49 , V_26 ) ;
else
F_4 ( V_49 , V_26 ) ;
F_3 ( V_14 , V_26 ) ;
}
}
static int F_26 ( struct V_50 * V_51 , unsigned V_10 , int V_52 )
{
T_1 V_1 , V_26 , V_53 ;
unsigned long V_54 ;
if ( V_10 >= V_51 -> V_55 )
return - V_24 ;
if ( V_10 < 16 ) {
V_1 = V_56 ;
V_26 = 1 << V_10 ;
} else if ( V_10 < 32 ) {
V_1 = V_57 ;
V_26 = 1 << ( V_10 - 16 ) ;
} else {
if ( V_31 & V_58 ) {
V_1 = V_59 ;
V_26 = 1 << ( V_10 - 32 ) ;
} else {
switch ( V_10 ) {
case 48 :
V_1 = V_60 ;
V_26 = V_61 ;
break;
case 49 :
V_1 = V_60 ;
V_26 = V_62 ;
break;
default:
return - V_24 ;
}
}
}
F_27 ( & V_63 , V_54 ) ;
V_53 = F_2 ( V_1 ) ;
if ( V_52 == V_64 )
V_53 |= V_26 ;
else
V_53 &= ~ V_26 ;
F_3 ( V_1 , V_53 ) ;
F_28 ( & V_63 , V_54 ) ;
return 0 ;
}
int F_29 ( unsigned int V_10 , T_5 V_65 )
{
T_1 V_53 , V_26 ;
unsigned long V_54 ;
if ( ( V_31 & V_66 ) != V_66 )
return - V_67 ;
if ( V_10 >= 15 )
return - V_24 ;
V_26 = 1 << V_10 ;
F_27 ( & V_63 , V_54 ) ;
if ( V_65 == V_68 || V_65 == V_69 ) {
V_53 = F_2 ( V_70 ) ;
if ( V_65 == V_68 )
V_53 |= V_26 ;
else
V_53 &= ~ V_26 ;
F_3 ( V_70 , V_53 ) ;
V_53 = F_2 ( V_71 ) ;
V_53 |= V_26 ;
F_3 ( V_71 , V_53 ) ;
} else {
V_53 = F_2 ( V_71 ) ;
V_53 &= ~ V_26 ;
F_3 ( V_71 , V_53 ) ;
}
F_28 ( & V_63 , V_54 ) ;
return 0 ;
}
static int F_30 ( struct V_50 * V_51 , unsigned V_10 )
{
T_1 V_53 , V_26 ;
if ( V_10 >= V_51 -> V_55 )
return - V_24 ;
if ( V_10 < 16 ) {
V_53 = F_2 ( V_72 ) ;
V_26 = 1 << V_10 ;
} else if ( V_10 < 32 ) {
V_53 = F_2 ( V_73 ) ;
V_26 = 1 << ( V_10 - 16 ) ;
} else if ( V_10 < 48 ) {
V_53 = F_2 ( V_74 ) ;
V_26 = 1 << ( V_10 - 32 ) ;
} else {
V_53 = F_2 ( V_60 ) ;
V_26 = 1 << ( V_10 - 48 ) ;
}
if ( V_53 & V_26 )
return 1 ;
return 0 ;
}
static void F_31 ( struct V_50 * V_51 , unsigned V_10 ,
int V_75 )
{
T_1 V_1 , V_26 , V_53 ;
unsigned long V_54 ;
if ( V_10 >= V_51 -> V_55 )
return;
if ( V_10 < 16 ) {
V_1 = V_72 ;
V_26 = 1 << V_10 ;
} else if ( V_10 < 32 ) {
V_1 = V_73 ;
V_26 = 1 << ( V_10 - 16 ) ;
} else if ( V_10 < 48 ) {
V_1 = V_74 ;
V_26 = 1 << ( V_10 - 32 ) ;
} else {
V_1 = V_60 ;
V_26 = 1 << ( V_10 - 48 ) ;
}
F_27 ( & V_63 , V_54 ) ;
V_53 = F_2 ( V_1 ) ;
if ( V_75 )
V_53 |= V_26 ;
else
V_53 &= ~ V_26 ;
F_3 ( V_1 , V_53 ) ;
F_28 ( & V_63 , V_54 ) ;
}
static int F_32 ( struct V_50 * V_51 , unsigned V_1 )
{
return F_26 ( V_51 , V_1 , V_76 ) ;
}
static int F_33 ( struct V_50 * V_51 , unsigned V_1 ,
int V_75 )
{
F_31 ( V_51 , V_1 , V_75 ) ;
return F_26 ( V_51 , V_1 , V_64 ) ;
}
static int F_34 ( struct V_50 * V_51 , unsigned V_1 )
{
if ( V_1 >= V_51 -> V_55 )
return - V_24 ;
return V_77 + V_1 ;
}
static int F_35 ( struct V_78 * V_79 )
{
struct V_80 * V_81 ;
unsigned int V_25 , V_21 , V_10 ;
struct V_82 * V_51 ;
int V_8 , V_83 ;
switch ( V_79 -> V_84 ) {
case V_85 :
V_31 = V_66 ;
V_11 . V_55 = 50 ;
break;
case V_86 :
V_11 . V_55 = 36 ;
break;
case V_87 :
V_31 = V_32 ;
V_11 . V_55 = 48 ;
break;
default:
F_12 ( & V_79 -> V_13 , L_3 , V_79 -> V_84 ) ;
return - V_88 ;
}
V_81 = F_36 ( V_79 , V_89 , 0 ) ;
if ( ! V_81 )
return - V_90 ;
V_91 = F_37 ( V_81 -> V_92 , F_38 ( V_81 ) ) ;
if ( ! V_91 )
return - V_93 ;
V_11 . V_13 = & V_79 -> V_13 ;
V_83 = F_39 ( & V_11 ) ;
if ( ! V_83 ) {
F_40 ( V_91 ) ;
return - V_88 ;
}
F_3 ( V_9 , 0 ) ;
F_3 ( V_16 , 0 ) ;
V_25 = F_2 ( V_41 ) << 16 ;
V_25 |= F_2 ( V_28 ) ;
for ( V_21 = V_77 ; V_21 <= V_94 ; V_21 ++ ) {
V_10 = F_6 ( V_21 ) ;
if ( V_10 < V_15 )
V_51 = & V_37 ;
else
V_51 = & V_45 ;
if ( V_25 & ( 1 << V_10 ) )
F_24 ( V_21 , V_51 , V_38 ) ;
else
F_24 ( V_21 , V_51 , V_39 ) ;
}
V_8 = F_41 ( V_79 , 0 ) ;
if ( V_8 < 0 || V_8 >= V_95 )
return - V_90 ;
return F_42 ( V_8 , F_19 ) ;
}
static int F_43 ( struct V_78 * V_79 )
{
if ( V_91 ) {
F_40 ( V_91 ) ;
V_91 = NULL ;
}
return 0 ;
}
