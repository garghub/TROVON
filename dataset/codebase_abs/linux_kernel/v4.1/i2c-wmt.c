static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = V_4 + V_5 ;
while ( ! ( F_2 ( V_2 -> V_6 + V_7 ) & V_8 ) ) {
if ( F_3 ( V_4 , V_3 ) ) {
F_4 ( V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
F_5 ( 20 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
if ( V_2 -> V_12 & V_13 )
V_11 = - V_14 ;
if ( V_2 -> V_12 & V_15 )
V_11 = - V_16 ;
return V_11 ;
}
static int F_7 ( struct V_17 * V_18 , struct V_19 * V_20 ,
int V_21 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
T_1 V_22 , V_23 ;
int V_11 ;
unsigned long V_24 ;
int V_25 = 0 ;
if ( ! ( V_20 -> V_26 & V_27 ) ) {
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_20 -> V_28 == 0 ) {
V_25 = - 1 ;
F_9 ( 0 , V_2 -> V_6 + V_29 ) ;
} else {
F_9 ( V_20 -> V_30 [ 0 ] & 0xFF , V_2 -> V_6 + V_29 ) ;
}
if ( ! ( V_20 -> V_26 & V_27 ) ) {
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 &= ~ V_32 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 |= V_33 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
}
F_10 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_35 == V_36 )
V_23 = V_37 ;
else
V_23 = V_38 ;
V_23 |= ( V_39 | ( V_20 -> V_40 & V_41 ) ) ;
F_9 ( V_23 , V_2 -> V_6 + V_42 ) ;
if ( V_20 -> V_26 & V_27 ) {
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 |= V_33 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
}
while ( V_25 < V_20 -> V_28 ) {
V_24 = F_11 ( & V_2 -> V_34 ,
F_12 ( 500 ) ) ;
if ( V_24 == 0 )
return - V_16 ;
V_11 = F_6 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_25 ++ ;
V_22 = F_2 ( V_2 -> V_6 + V_7 ) ;
if ( ( V_22 & V_43 ) == V_44 ) {
F_13 ( V_2 -> V_9 , L_2 ) ;
return - V_14 ;
}
if ( V_20 -> V_28 == 0 ) {
V_22 = V_32 | V_33 | V_45 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
break;
}
if ( V_25 == V_20 -> V_28 ) {
if ( V_21 != 1 )
F_9 ( V_45 , V_2 -> V_6 + V_31 ) ;
} else {
F_9 ( V_20 -> V_30 [ V_25 ] & 0xFF , V_2 -> V_6 +
V_29 ) ;
F_9 ( V_33 | V_45 , V_2 -> V_6 + V_31 ) ;
}
}
return 0 ;
}
static int F_14 ( struct V_17 * V_18 , struct V_19 * V_20 ,
int V_21 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
T_1 V_22 , V_23 ;
int V_11 ;
unsigned long V_24 ;
T_2 V_25 = 0 ;
if ( ! ( V_20 -> V_26 & V_27 ) ) {
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 &= ~ V_32 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 &= ~ V_46 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
if ( ! ( V_20 -> V_26 & V_27 ) ) {
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 |= V_33 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
}
if ( V_20 -> V_28 == 1 ) {
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 |= V_46 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
}
F_10 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_35 == V_36 )
V_23 = V_37 ;
else
V_23 = V_38 ;
V_23 |= V_47 | ( V_20 -> V_40 & V_41 ) ;
F_9 ( V_23 , V_2 -> V_6 + V_42 ) ;
if ( V_20 -> V_26 & V_27 ) {
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 |= V_33 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
}
while ( V_25 < V_20 -> V_28 ) {
V_24 = F_11 ( & V_2 -> V_34 ,
F_12 ( 500 ) ) ;
if ( ! V_24 )
return - V_16 ;
V_11 = F_6 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_20 -> V_30 [ V_25 ] = F_2 ( V_2 -> V_6 + V_29 ) >> 8 ;
V_25 ++ ;
if ( V_25 == V_20 -> V_28 - 1 ) {
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 |= ( V_46 | V_33 ) ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
} else {
V_22 = F_2 ( V_2 -> V_6 + V_31 ) ;
V_22 |= V_33 ;
F_9 ( V_22 , V_2 -> V_6 + V_31 ) ;
}
}
return 0 ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_19 V_48 [] ,
int V_49 )
{
struct V_19 * V_20 ;
int V_50 , V_51 ;
int V_11 = 0 ;
for ( V_50 = 0 ; V_11 >= 0 && V_50 < V_49 ; V_50 ++ ) {
V_51 = ( ( V_50 + 1 ) == V_49 ) ;
V_20 = & V_48 [ V_50 ] ;
if ( V_20 -> V_26 & V_52 )
V_11 = F_14 ( V_18 , V_20 , V_51 ) ;
else
V_11 = F_7 ( V_18 , V_20 , V_51 ) ;
}
return ( V_11 < 0 ) ? V_11 : V_50 ;
}
static T_2 F_16 ( struct V_17 * V_18 )
{
return V_53 | V_54 | V_55 ;
}
static T_3 F_17 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
V_2 -> V_12 = F_2 ( V_2 -> V_6 + V_58 ) ;
F_9 ( V_2 -> V_12 , V_2 -> V_6 + V_58 ) ;
V_34 ( & V_2 -> V_34 ) ;
return V_59 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_60 ;
V_60 = F_19 ( V_2 -> V_61 ) ;
if ( V_60 ) {
F_20 ( V_2 -> V_9 , L_3 ) ;
return V_60 ;
}
V_60 = F_21 ( V_2 -> V_61 , 20000000 ) ;
if ( V_60 ) {
F_20 ( V_2 -> V_9 , L_4 ) ;
F_22 ( V_2 -> V_61 ) ;
return V_60 ;
}
F_9 ( 0 , V_2 -> V_6 + V_31 ) ;
F_9 ( V_62 , V_2 -> V_6 + V_63 ) ;
F_9 ( V_64 , V_2 -> V_6 + V_58 ) ;
F_9 ( V_65 , V_2 -> V_6 + V_66 ) ;
F_9 ( V_45 , V_2 -> V_6 + V_31 ) ;
F_2 ( V_2 -> V_6 + V_7 ) ;
F_9 ( V_64 , V_2 -> V_6 + V_58 ) ;
if ( V_2 -> V_35 == V_36 )
F_9 ( F_23 ( 128 ) | V_67 , V_2 -> V_6 + V_68 ) ;
else
F_9 ( F_23 ( 128 ) | V_69 , V_2 -> V_6 + V_68 ) ;
return 0 ;
}
static int F_24 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = V_71 -> V_9 . V_74 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_75 * V_76 ;
int V_60 ;
T_2 V_77 ;
V_2 = F_25 ( & V_71 -> V_9 , sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_76 = F_26 ( V_71 , V_80 , 0 ) ;
V_2 -> V_6 = F_27 ( & V_71 -> V_9 , V_76 ) ;
if ( F_28 ( V_2 -> V_6 ) )
return F_29 ( V_2 -> V_6 ) ;
V_2 -> V_56 = F_30 ( V_73 , 0 ) ;
if ( ! V_2 -> V_56 ) {
F_20 ( & V_71 -> V_9 , L_5 ) ;
return - V_81 ;
}
V_2 -> V_61 = F_31 ( V_73 , 0 ) ;
if ( F_28 ( V_2 -> V_61 ) ) {
F_20 ( & V_71 -> V_9 , L_6 ) ;
return F_29 ( V_2 -> V_61 ) ;
}
V_2 -> V_35 = V_36 ;
V_60 = F_32 ( V_73 , L_7 , & V_77 ) ;
if ( ( ! V_60 ) && ( V_77 == 400000 ) )
V_2 -> V_35 = V_82 ;
V_2 -> V_9 = & V_71 -> V_9 ;
V_60 = F_33 ( & V_71 -> V_9 , V_2 -> V_56 , F_17 , 0 ,
L_8 , V_2 ) ;
if ( V_60 ) {
F_20 ( & V_71 -> V_9 , L_9 , V_2 -> V_56 ) ;
return V_60 ;
}
V_18 = & V_2 -> V_83 ;
F_34 ( V_18 , V_2 ) ;
F_35 ( V_18 -> V_84 , L_10 , sizeof( V_18 -> V_84 ) ) ;
V_18 -> V_85 = V_86 ;
V_18 -> V_87 = & V_88 ;
V_18 -> V_9 . V_89 = & V_71 -> V_9 ;
V_18 -> V_9 . V_74 = V_71 -> V_9 . V_74 ;
F_36 ( & V_2 -> V_34 ) ;
V_60 = F_18 ( V_2 ) ;
if ( V_60 ) {
F_20 ( & V_71 -> V_9 , L_11 ) ;
return V_60 ;
}
V_60 = F_37 ( V_18 ) ;
if ( V_60 ) {
F_20 ( & V_71 -> V_9 , L_12 ) ;
return V_60 ;
}
F_38 ( V_71 , V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_40 ( V_71 ) ;
F_9 ( 0 , V_2 -> V_6 + V_66 ) ;
F_22 ( V_2 -> V_61 ) ;
F_41 ( & V_2 -> V_83 ) ;
return 0 ;
}
