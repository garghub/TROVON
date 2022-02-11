static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 V_5 ;
bool V_6 ;
T_1 V_7 ;
T_2 V_8 , V_9 , V_10 ;
int V_11 ;
struct V_12 * V_13 = V_2 -> V_12 + V_3 ;
if ( V_2 -> V_14 )
return;
if ( ! V_13 -> V_15 )
return;
if ( V_13 -> V_15 & V_16 )
return;
if ( V_13 -> V_15 & V_17 )
return;
F_2 ( V_2 -> V_18 , & V_5 , V_13 ) ;
V_8 = V_5 . V_19 ;
if ( V_13 -> V_15 & V_20 ) {
V_10 = ( T_2 ) V_21 ;
V_8 |= V_13 -> V_15 & ~ V_21 ;
} else if ( V_3 == V_22 ) {
V_10 = ( T_2 ) V_23 ;
} else {
V_10 = ( T_2 ) V_24 ;
V_8 |= V_13 -> V_15 & ~ V_24 ;
}
if ( V_3 < V_22 ) {
V_11 = V_25 + 4 * V_3 ;
} else if ( V_3 == V_22 ) {
if ( ! ( V_13 -> V_15 & V_26 ) )
return;
V_11 = V_2 -> V_27 ;
V_8 |= V_28 ;
} else
return;
V_6 = ( V_13 -> V_15 & V_29 ) && ! V_2 -> V_30 ;
if ( V_6 ) {
F_3 ( V_2 , V_31 , & V_7 ) ;
F_4 ( V_2 , V_31 ,
V_7 & ~ V_32 ) ;
}
F_5 ( V_2 , V_11 , V_8 ) ;
F_6 ( V_2 , V_11 , & V_9 ) ;
if ( ( V_8 ^ V_9 ) & V_10 ) {
F_7 ( & V_2 -> V_2 , L_1 ,
V_3 , V_8 , V_9 ) ;
}
if ( V_13 -> V_15 & V_29 ) {
V_8 = V_5 . V_19 >> 16 >> 16 ;
F_5 ( V_2 , V_11 + 4 , V_8 ) ;
F_6 ( V_2 , V_11 + 4 , & V_9 ) ;
if ( V_9 != V_8 ) {
F_7 ( & V_2 -> V_2 , L_2 ,
V_3 , V_8 , V_9 ) ;
}
}
if ( V_6 )
F_4 ( V_2 , V_31 , V_7 ) ;
}
void F_8 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 <= V_22 )
F_1 ( V_2 , V_3 ) ;
#ifdef F_9
else if ( V_3 >= V_33 && V_3 <= V_34 )
F_10 ( V_2 , V_3 ) ;
#endif
}
int F_11 ( struct V_1 * V_2 , int V_12 )
{
struct V_12 * V_13 = & V_2 -> V_12 [ V_12 ] ;
struct V_12 * V_35 , * V_36 ;
if ( V_13 -> V_15 & V_16 ) {
F_12 ( & V_2 -> V_2 , L_3 ,
V_12 , V_13 ) ;
return - V_37 ;
}
if ( V_13 -> V_15 & V_38 )
return 0 ;
V_35 = F_13 ( V_2 , V_13 ) ;
if ( ! V_35 ) {
F_12 ( & V_2 -> V_2 , L_4 ,
V_12 , V_13 ) ;
V_13 -> V_15 |= V_16 ;
return - V_37 ;
}
V_36 = F_14 ( V_35 , V_13 ) ;
if ( V_36 ) {
F_12 ( & V_2 -> V_2 , L_5 ,
V_12 , V_13 , V_36 -> V_39 , V_36 ) ;
V_13 -> V_15 |= V_16 ;
return - V_40 ;
}
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_2 , L_6 ) ;
F_5 ( V_2 , V_41 , 0x0000fff0 ) ;
F_5 ( V_2 , V_42 , 0 ) ;
F_5 ( V_2 , V_43 , 0x0000fff0 ) ;
F_5 ( V_2 , V_44 , 0xffffffff ) ;
}
T_3 __weak F_16 ( struct V_1 * V_2 , int V_45 )
{
return 0 ;
}
static int F_17 ( struct V_12 * V_13 , struct V_1 * V_2 ,
int V_3 , T_3 V_46 )
{
struct V_12 * V_35 , * V_36 ;
T_3 V_47 , V_19 , V_48 ;
V_47 = F_16 ( V_2 , V_3 ) ;
if ( ! V_47 )
return - V_49 ;
V_19 = V_13 -> V_19 ;
V_48 = V_13 -> V_48 ;
V_13 -> V_19 = V_47 ;
V_13 -> V_48 = V_13 -> V_19 + V_46 - 1 ;
V_13 -> V_15 &= ~ V_16 ;
V_35 = F_13 ( V_2 , V_13 ) ;
if ( ! V_35 ) {
if ( V_13 -> V_15 & V_20 )
V_35 = & V_50 ;
else
V_35 = & V_51 ;
}
F_12 ( & V_2 -> V_2 , L_7 ,
V_3 , V_13 ) ;
V_36 = F_14 ( V_35 , V_13 ) ;
if ( V_36 ) {
F_12 ( & V_2 -> V_2 , L_8 ,
V_3 , V_13 , V_36 -> V_39 , V_36 ) ;
V_13 -> V_19 = V_19 ;
V_13 -> V_48 = V_48 ;
V_13 -> V_15 |= V_16 ;
return - V_40 ;
}
return 0 ;
}
static int F_18 ( struct V_52 * V_18 , struct V_1 * V_2 ,
int V_3 , T_3 V_46 , T_3 V_53 )
{
struct V_12 * V_13 = V_2 -> V_12 + V_3 ;
T_3 V_54 ;
int V_55 ;
V_54 = ( V_13 -> V_15 & V_20 ) ? V_56 : V_57 ;
V_55 = F_19 ( V_18 , V_13 , V_46 , V_53 , V_54 ,
V_58 | V_29 ,
V_59 , V_2 ) ;
if ( V_55 == 0 )
return 0 ;
if ( ( V_13 -> V_15 & ( V_58 | V_29 ) ) ==
( V_58 | V_29 ) ) {
V_55 = F_19 ( V_18 , V_13 , V_46 , V_53 , V_54 ,
V_58 ,
V_59 , V_2 ) ;
if ( V_55 == 0 )
return 0 ;
}
if ( V_13 -> V_15 & ( V_58 | V_29 ) )
V_55 = F_19 ( V_18 , V_13 , V_46 , V_53 , V_54 , 0 ,
V_59 , V_2 ) ;
return V_55 ;
}
static int F_20 ( struct V_1 * V_2 , int V_3 ,
T_3 V_46 , T_3 V_60 )
{
struct V_52 * V_18 ;
int V_55 ;
V_18 = V_2 -> V_18 ;
while ( ( V_55 = F_18 ( V_18 , V_2 , V_3 , V_46 , V_60 ) ) ) {
if ( ! V_18 -> V_61 || ! V_18 -> V_62 -> V_63 )
break;
V_18 = V_18 -> V_61 ;
}
return V_55 ;
}
int F_21 ( struct V_1 * V_2 , int V_3 )
{
struct V_12 * V_13 = V_2 -> V_12 + V_3 ;
T_3 V_53 , V_46 ;
int V_55 ;
if ( V_13 -> V_15 & V_17 )
return 0 ;
V_13 -> V_15 |= V_16 ;
V_53 = F_22 ( V_2 , V_13 ) ;
if ( ! V_53 ) {
F_12 ( & V_2 -> V_2 , L_9 ,
V_3 , V_13 ) ;
return - V_37 ;
}
V_46 = F_23 ( V_13 ) ;
V_55 = F_20 ( V_2 , V_3 , V_46 , V_53 ) ;
if ( V_55 < 0 ) {
F_12 ( & V_2 -> V_2 , L_10 , V_3 , V_13 ) ;
V_55 = F_17 ( V_13 , V_2 , V_3 , V_46 ) ;
}
if ( V_55 < 0 ) {
F_12 ( & V_2 -> V_2 , L_11 , V_3 ,
V_13 ) ;
return V_55 ;
}
V_13 -> V_15 &= ~ V_16 ;
V_13 -> V_15 &= ~ V_64 ;
F_12 ( & V_2 -> V_2 , L_12 , V_3 , V_13 ) ;
if ( V_3 < V_65 )
F_8 ( V_2 , V_3 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , int V_3 , T_3 V_66 ,
T_3 V_60 )
{
struct V_12 * V_13 = V_2 -> V_12 + V_3 ;
unsigned long V_15 ;
T_3 V_67 ;
int V_55 ;
if ( V_13 -> V_15 & V_17 )
return 0 ;
V_15 = V_13 -> V_15 ;
V_13 -> V_15 |= V_16 ;
if ( ! V_13 -> V_61 ) {
F_12 ( & V_2 -> V_2 , L_13 ,
V_3 , V_13 ) ;
return - V_37 ;
}
V_67 = F_23 ( V_13 ) + V_66 ;
V_55 = F_20 ( V_2 , V_3 , V_67 , V_60 ) ;
if ( V_55 ) {
V_13 -> V_15 = V_15 ;
F_12 ( & V_2 -> V_2 , L_14 ,
V_3 , V_13 , ( unsigned long long ) V_66 ) ;
return V_55 ;
}
V_13 -> V_15 &= ~ V_16 ;
V_13 -> V_15 &= ~ V_64 ;
F_12 ( & V_2 -> V_2 , L_15 ,
V_3 , V_13 , ( unsigned long long ) V_66 ) ;
if ( V_3 < V_65 )
F_8 ( V_2 , V_3 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_7 , V_68 ;
int V_69 ;
struct V_12 * V_70 ;
F_3 ( V_2 , V_31 , & V_7 ) ;
V_68 = V_7 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
if ( ! ( V_10 & ( 1 << V_69 ) ) )
continue;
V_70 = & V_2 -> V_12 [ V_69 ] ;
if ( ! ( V_70 -> V_15 & ( V_20 | V_72 ) ) )
continue;
if ( ( V_69 == V_22 ) &&
( ! ( V_70 -> V_15 & V_26 ) ) )
continue;
if ( V_70 -> V_15 & V_16 ) {
F_7 ( & V_2 -> V_2 , L_16 ,
V_69 , V_70 ) ;
return - V_37 ;
}
if ( ! V_70 -> V_61 ) {
F_7 ( & V_2 -> V_2 , L_17 ,
V_69 , V_70 ) ;
return - V_37 ;
}
if ( V_70 -> V_15 & V_20 )
V_7 |= V_73 ;
if ( V_70 -> V_15 & V_72 )
V_7 |= V_32 ;
}
if ( V_7 != V_68 ) {
F_12 ( & V_2 -> V_2 , L_18 ,
V_68 , V_7 ) ;
F_4 ( V_2 , V_31 , V_7 ) ;
}
return 0 ;
}
