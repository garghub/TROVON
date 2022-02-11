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
static void F_10 ( struct V_5 * V_6 )
{
F_3 ( V_11 ,
1 << ( F_6 ( V_6 -> V_8 ) - V_12 ) ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
F_4 ( V_13 , 1 << ( F_6 ( V_6 -> V_8 ) - V_12 ) ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
unsigned int V_10 ;
V_10 = F_6 ( V_6 -> V_8 ) - V_12 ;
F_4 ( V_13 , 1 << V_10 ) ;
F_3 ( V_11 , 1 << V_10 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
F_1 ( V_13 , 1 << ( F_6 ( V_6 -> V_8 ) - V_12 ) ) ;
}
static int F_14 ( unsigned int V_8 )
{
T_1 V_14 , V_15 , V_16 , V_17 ;
int V_18 ;
V_14 = F_2 ( V_7 ) ;
V_15 = F_2 ( V_11 ) ;
V_16 = F_2 ( V_9 ) ;
V_17 = F_2 ( V_13 ) ;
V_16 &= V_14 ;
V_17 &= V_15 ;
if ( V_16 ) {
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ ) {
if ( V_16 & ( 1 << V_18 ) )
return F_15 ( V_18 ) ;
}
} else if ( V_17 ) {
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ ) {
if ( V_17 & ( 1 << V_18 ) )
return F_15 ( V_18 + V_12 ) ;
}
}
F_16 ( V_19 L_1 ,
V_16 , V_14 , V_17 , V_15 ) ;
F_17 ( & V_20 ) ;
return - V_21 ;
}
void F_18 ( unsigned int V_10 , T_2 V_22 ,
T_3 signal )
{
T_1 V_23 ;
if ( V_10 < V_12 ) {
V_23 = 1 << V_10 ;
if ( V_22 != V_24 ) {
F_1 ( V_25 , V_23 ) ;
if ( signal == V_26 )
F_1 ( V_27 , V_23 ) ;
else
F_4 ( V_27 , V_23 ) ;
if ( V_28 & V_29 ) {
switch ( V_22 ) {
case V_30 :
F_1 ( V_31 , V_23 ) ;
F_4 ( V_32 , V_23 ) ;
break;
case V_33 :
F_4 ( V_31 , V_23 ) ;
F_1 ( V_32 , V_23 ) ;
break;
default:
F_1 ( V_31 , V_23 ) ;
F_1 ( V_32 , V_23 ) ;
break;
}
}
F_19 ( F_15 ( V_10 ) ,
& V_34 ,
V_35 ) ;
} else {
F_4 ( V_25 , V_23 ) ;
F_4 ( V_27 , V_23 ) ;
F_19 ( F_15 ( V_10 ) ,
& V_34 ,
V_36 ) ;
}
F_3 ( V_7 , V_23 ) ;
} else if ( V_10 < V_37 ) {
V_23 = 1 << ( V_10 - V_12 ) ;
if ( V_22 != V_24 ) {
F_1 ( V_38 , V_23 ) ;
if ( signal == V_26 )
F_1 ( V_39 , V_23 ) ;
else
F_4 ( V_39 , V_23 ) ;
if ( V_28 & V_29 ) {
switch ( V_22 ) {
case V_30 :
F_1 ( V_40 , V_23 ) ;
F_4 ( V_41 , V_23 ) ;
break;
case V_33 :
F_4 ( V_40 , V_23 ) ;
F_1 ( V_41 , V_23 ) ;
break;
default:
F_1 ( V_40 , V_23 ) ;
F_1 ( V_41 , V_23 ) ;
break;
}
}
F_19 ( F_15 ( V_10 ) ,
& V_42 ,
V_35 ) ;
} else {
F_4 ( V_38 , V_23 ) ;
F_4 ( V_39 , V_23 ) ;
F_19 ( F_15 ( V_10 ) ,
& V_42 ,
V_36 ) ;
}
F_3 ( V_11 , V_23 ) ;
}
}
void F_20 ( unsigned int V_10 , T_4 V_43 )
{
T_1 V_23 ;
if ( V_10 < V_12 ) {
V_23 = 1 << V_10 ;
if ( V_43 == V_44 )
F_1 ( V_45 , V_23 ) ;
else
F_4 ( V_45 , V_23 ) ;
F_3 ( V_7 , V_23 ) ;
} else if ( V_10 < V_37 ) {
V_23 = 1 << ( V_10 - V_12 ) ;
if ( V_43 == V_44 )
F_1 ( V_46 , V_23 ) ;
else
F_4 ( V_46 , V_23 ) ;
F_3 ( V_11 , V_23 ) ;
}
}
static int F_21 ( struct V_47 * V_48 , unsigned V_10 , int V_49 )
{
T_1 V_1 , V_23 , V_50 ;
unsigned long V_51 ;
if ( V_10 >= V_48 -> V_52 )
return - V_21 ;
if ( V_10 < 16 ) {
V_1 = V_53 ;
V_23 = 1 << V_10 ;
} else if ( V_10 < 32 ) {
V_1 = V_54 ;
V_23 = 1 << ( V_10 - 16 ) ;
} else {
if ( V_28 & V_55 ) {
V_1 = V_56 ;
V_23 = 1 << ( V_10 - 32 ) ;
} else {
switch ( V_10 ) {
case 48 :
V_1 = V_57 ;
V_23 = V_58 ;
break;
case 49 :
V_1 = V_57 ;
V_23 = V_59 ;
break;
default:
return - V_21 ;
}
}
}
F_22 ( & V_60 , V_51 ) ;
V_50 = F_2 ( V_1 ) ;
if ( V_49 == V_61 )
V_50 |= V_23 ;
else
V_50 &= ~ V_23 ;
F_3 ( V_1 , V_50 ) ;
F_23 ( & V_60 , V_51 ) ;
return 0 ;
}
int F_24 ( unsigned int V_10 , T_5 V_62 )
{
T_1 V_50 , V_23 ;
unsigned long V_51 ;
if ( ( V_28 & V_63 ) != V_63 )
return - V_64 ;
if ( V_10 >= 15 )
return - V_21 ;
V_23 = 1 << V_10 ;
F_22 ( & V_60 , V_51 ) ;
if ( V_62 == V_65 || V_62 == V_66 ) {
V_50 = F_2 ( V_67 ) ;
if ( V_62 == V_65 )
V_50 |= V_23 ;
else
V_50 &= ~ V_23 ;
F_3 ( V_67 , V_50 ) ;
V_50 = F_2 ( V_68 ) ;
V_50 |= V_23 ;
F_3 ( V_68 , V_50 ) ;
} else {
V_50 = F_2 ( V_68 ) ;
V_50 &= ~ V_23 ;
F_3 ( V_68 , V_50 ) ;
}
F_23 ( & V_60 , V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_47 * V_48 , unsigned V_10 )
{
T_1 V_50 , V_23 ;
if ( V_10 >= V_48 -> V_52 )
return - V_21 ;
if ( V_10 < 16 ) {
V_50 = F_2 ( V_69 ) ;
V_23 = 1 << V_10 ;
} else if ( V_10 < 32 ) {
V_50 = F_2 ( V_70 ) ;
V_23 = 1 << ( V_10 - 16 ) ;
} else if ( V_10 < 48 ) {
V_50 = F_2 ( V_71 ) ;
V_23 = 1 << ( V_10 - 32 ) ;
} else {
V_50 = F_2 ( V_57 ) ;
V_23 = 1 << ( V_10 - 48 ) ;
}
if ( V_50 & V_23 )
return 1 ;
return 0 ;
}
static void F_26 ( struct V_47 * V_48 , unsigned V_10 ,
int V_72 )
{
T_1 V_1 , V_23 , V_50 ;
unsigned long V_51 ;
if ( V_10 >= V_48 -> V_52 )
return;
if ( V_10 < 16 ) {
V_1 = V_69 ;
V_23 = 1 << V_10 ;
} else if ( V_10 < 32 ) {
V_1 = V_70 ;
V_23 = 1 << ( V_10 - 16 ) ;
} else if ( V_10 < 48 ) {
V_1 = V_71 ;
V_23 = 1 << ( V_10 - 32 ) ;
} else {
V_1 = V_57 ;
V_23 = 1 << ( V_10 - 48 ) ;
}
F_22 ( & V_60 , V_51 ) ;
V_50 = F_2 ( V_1 ) ;
if ( V_72 )
V_50 |= V_23 ;
else
V_50 &= ~ V_23 ;
F_3 ( V_1 , V_50 ) ;
F_23 ( & V_60 , V_51 ) ;
}
static int F_27 ( struct V_47 * V_48 , unsigned V_1 )
{
return F_21 ( V_48 , V_1 , V_73 ) ;
}
static int F_28 ( struct V_47 * V_48 , unsigned V_1 ,
int V_72 )
{
F_26 ( V_48 , V_1 , V_72 ) ;
return F_21 ( V_48 , V_1 , V_61 ) ;
}
static int F_29 ( struct V_47 * V_48 , unsigned V_1 )
{
if ( V_1 >= V_48 -> V_52 )
return - V_21 ;
return V_74 + V_1 ;
}
static int F_30 ( struct V_75 * V_76 )
{
struct V_77 * V_78 ;
unsigned int V_22 , V_18 , V_10 ;
struct V_79 * V_48 ;
int V_8 , V_80 ;
switch ( V_76 -> V_81 ) {
case V_82 :
V_28 = V_63 ;
V_83 . V_52 = 50 ;
break;
case V_84 :
V_83 . V_52 = 36 ;
break;
case V_85 :
V_28 = V_29 ;
V_83 . V_52 = 48 ;
break;
default:
F_31 ( & V_76 -> V_86 , L_2 , V_76 -> V_81 ) ;
return - V_87 ;
}
V_78 = F_32 ( V_76 , V_88 , 0 ) ;
if ( ! V_78 )
return - V_89 ;
V_90 = F_33 ( V_78 -> V_91 , F_34 ( V_78 ) ) ;
if ( ! V_90 )
return - V_92 ;
V_83 . V_86 = & V_76 -> V_86 ;
V_80 = F_35 ( & V_83 ) ;
F_3 ( V_9 , 0 ) ;
F_3 ( V_13 , 0 ) ;
V_22 = F_2 ( V_38 ) << 16 ;
V_22 |= F_2 ( V_25 ) ;
for ( V_18 = V_74 ; V_18 <= V_93 ; V_18 ++ ) {
V_10 = F_6 ( V_18 ) ;
if ( V_10 < V_12 )
V_48 = & V_34 ;
else
V_48 = & V_42 ;
if ( V_22 & ( 1 << V_10 ) )
F_19 ( V_18 , V_48 , V_35 ) ;
else
F_19 ( V_18 , V_48 , V_36 ) ;
}
V_8 = F_36 ( V_76 , 0 ) ;
if ( V_8 < 0 || V_8 >= V_94 )
return - V_89 ;
return F_37 ( V_8 , F_14 ) ;
}
static int F_38 ( struct V_75 * V_76 )
{
if ( V_90 ) {
F_39 ( V_90 ) ;
V_90 = NULL ;
}
return 0 ;
}
