static void F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
F_2 ( V_2 , V_1 ) ;
}
static unsigned long F_3 ( void T_1 * V_1 )
{
return F_4 ( V_1 ) ;
}
static unsigned long F_5 ( unsigned long V_3 )
{
if ( V_3 < 8 )
return V_3 + 16 ;
else
return V_3 - 8 ;
}
static void F_6 ( struct V_4 * V_5 , unsigned long V_6 )
{
void T_1 * V_7 ;
unsigned long V_8 , V_9 ;
V_9 = F_5 ( V_5 -> V_3 ) ;
if ( V_9 / 16 )
V_7 = V_5 -> V_10 + V_11 ;
else
V_7 = V_5 -> V_10 + V_12 ;
V_8 = F_3 ( V_7 ) ;
V_8 &= ~ ( V_13 << F_7 ( V_9 % 16 ) ) ;
V_8 |= ( V_6 << F_7 ( V_9 % 16 ) ) ;
F_1 ( V_7 , V_8 ) ;
}
static void F_8 ( struct V_14 * V_15 ,
enum V_16 V_6 )
{
struct V_4 * V_5 =
F_9 ( V_15 , struct V_4 , V_17 ) ;
unsigned long V_18 ;
F_10 ( V_5 -> V_19 , V_18 ) ;
* ( V_5 -> V_20 ) &= ~ F_11 ( V_5 -> V_3 ) ;
if ( ( V_5 -> V_21 && V_6 == V_22 ) ||
( ! V_5 -> V_21 && V_6 != V_22 ) )
F_6 ( V_5 , V_23 ) ;
else
F_6 ( V_5 , V_24 ) ;
F_12 ( V_5 -> V_19 , V_18 ) ;
}
static int F_13 ( struct V_14 * V_15 ,
unsigned long * V_25 , unsigned long * V_26 )
{
struct V_4 * V_5 =
F_9 ( V_15 , struct V_4 , V_17 ) ;
unsigned long V_27 , V_18 ;
if ( ! * V_25 )
* V_25 = V_28 ;
if ( ! * V_26 )
* V_26 = V_28 ;
if ( * V_25 != * V_26 ) {
F_14 ( V_15 -> V_29 ,
L_1 ) ;
return - V_30 ;
}
V_27 = * V_25 / V_31 ;
if ( V_27 == 0 )
V_27 = 1 ;
else if ( V_27 > V_32 ) {
F_14 ( V_15 -> V_29 ,
L_2 ,
V_32 * V_31 ) ;
return - V_30 ;
}
F_10 ( V_5 -> V_19 , V_18 ) ;
if ( * ( V_5 -> V_20 ) == 0 ||
* ( V_5 -> V_20 ) == F_11 ( V_5 -> V_3 ) ||
* ( V_5 -> V_33 ) == V_27 ) {
unsigned long V_8 ;
* ( V_5 -> V_20 ) |= F_11 ( V_5 -> V_3 ) ;
* ( V_5 -> V_33 ) = V_27 ;
V_8 = F_3 ( V_5 -> V_10 + V_34 ) ;
V_8 &= ~ V_35 ;
V_8 |= ( V_27 << V_36 ) ;
F_1 ( V_5 -> V_10 + V_34 , V_8 ) ;
F_6 ( V_5 , V_37 ) ;
F_12 ( V_5 -> V_19 , V_18 ) ;
} else {
F_12 ( V_5 -> V_19 , V_18 ) ;
F_14 ( V_15 -> V_29 ,
L_3 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_15 ( struct V_38 * V_29 , struct V_39 * V_40 , T_2 V_1 ,
void T_1 * V_10 , T_3 * V_19 )
{
int V_41 , V_42 ;
unsigned long V_18 , V_8 ;
F_10 ( V_19 , V_18 ) ;
V_8 = F_3 ( V_10 + V_43 ) ;
V_8 &= ~ F_11 ( V_1 ) ;
F_1 ( V_10 + V_43 , V_8 ) ;
F_12 ( V_19 , V_18 ) ;
if ( V_1 >= 8 )
return 0 ;
V_42 = F_16 ( V_40 , L_4 ,
sizeof( T_2 ) ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
T_2 V_44 ;
void T_1 * V_45 ;
if ( V_1 < 4 )
V_45 = V_10 + V_46 ;
else
V_45 = V_10 + V_47 ;
F_17 ( V_40 , L_4 , V_41 ,
& V_44 ) ;
if ( V_1 / 4 != V_44 / 4 ) {
F_18 ( V_29 , L_5 ) ;
continue;
}
F_10 ( V_19 , V_18 ) ;
V_8 = F_3 ( V_45 ) ;
V_8 |= ( F_11 ( V_1 ) << ( ( ( V_44 % 4 ) * 4 ) + 16 ) ) ;
F_1 ( V_45 , V_8 ) ;
F_12 ( V_19 , V_18 ) ;
}
V_42 = F_16 ( V_40 ,
L_6 ,
sizeof( T_2 ) ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
T_2 V_44 ;
void T_1 * V_45 ;
if ( V_1 < 4 )
V_45 = V_10 + V_46 ;
else
V_45 = V_10 + V_47 ;
F_17 ( V_40 , L_6 ,
V_41 , & V_44 ) ;
if ( V_1 / 4 != V_44 / 4 ) {
F_18 ( V_29 , L_7 ) ;
continue;
}
F_10 ( V_19 , V_18 ) ;
V_8 = F_3 ( V_45 ) ;
V_8 |= ( F_11 ( V_1 ) << ( ( V_44 % 4 ) * 4 ) ) ;
F_1 ( V_45 , V_8 ) ;
F_12 ( V_19 , V_18 ) ;
}
return 0 ;
}
static int V_4 ( struct V_38 * V_29 , struct V_39 * V_40 , T_2 V_1 ,
void T_1 * V_10 , T_3 * V_19 ,
unsigned long * V_20 , unsigned long * V_33 )
{
struct V_4 * V_5 ;
unsigned long V_18 ;
const char * V_48 ;
int V_49 ;
V_5 = F_19 ( V_29 , sizeof( * V_5 ) , V_50 ) ;
if ( ! V_5 )
return - V_51 ;
V_5 -> V_3 = V_1 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_19 = V_19 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_33 = V_33 ;
if ( F_20 ( V_40 , L_8 ) )
V_5 -> V_21 = true ;
V_5 -> V_17 . V_52 = F_21 ( V_40 , L_9 , NULL ) ? : V_40 -> V_52 ;
V_5 -> V_17 . V_53 = F_21 ( V_40 ,
L_10 ,
NULL ) ;
F_10 ( V_19 , V_18 ) ;
if ( ! F_22 ( V_40 , L_11 , & V_48 ) ) {
if ( ! strcmp ( V_48 , L_12 ) ) {
V_5 -> V_17 . V_54 = V_55 ;
} else if ( ! strcmp ( V_48 , L_13 ) ) {
void T_1 * V_7 ;
unsigned long V_8 , V_9 ;
V_9 = F_5 ( V_5 -> V_3 ) ;
if ( V_9 / 16 )
V_7 = V_10 + V_11 ;
else
V_7 = V_10 + V_12 ;
V_8 = F_3 ( V_7 ) >>
F_7 ( V_9 % 16 ) ;
V_8 &= V_13 ;
if ( ( V_5 -> V_21 && V_8 == V_24 ) ||
( ! V_5 -> V_21 && V_8 == V_23 ) )
V_5 -> V_17 . V_54 = V_55 ;
else
V_5 -> V_17 . V_54 = V_22 ;
} else {
V_5 -> V_17 . V_54 = V_22 ;
}
} else {
V_5 -> V_17 . V_54 = V_22 ;
}
if ( ( V_5 -> V_21 && V_5 -> V_17 . V_54 == V_55 ) ||
( ! V_5 -> V_21 && V_5 -> V_17 . V_54 == V_22 ) )
F_6 ( V_5 , V_24 ) ;
else
F_6 ( V_5 , V_23 ) ;
F_12 ( V_19 , V_18 ) ;
V_5 -> V_17 . V_56 = F_8 ;
V_5 -> V_17 . V_57 = F_13 ;
V_49 = F_23 ( V_29 , & V_5 -> V_17 ) ;
if ( V_49 < 0 )
return V_49 ;
F_14 ( V_29 , L_14 , V_5 -> V_17 . V_52 ) ;
return 0 ;
}
static int F_24 ( struct V_58 * V_59 )
{
struct V_38 * V_29 = & V_59 -> V_29 ;
struct V_39 * V_60 = V_59 -> V_29 . V_61 ;
struct V_39 * V_62 ;
struct V_63 * V_64 ;
void T_1 * V_10 ;
T_3 * V_19 ;
unsigned long V_8 , * V_20 , * V_33 ;
V_64 = F_25 ( V_59 , V_65 , 0 ) ;
if ( ! V_64 )
return - V_30 ;
V_10 = F_26 ( V_29 , V_64 ) ;
if ( F_27 ( V_10 ) )
return F_28 ( V_10 ) ;
V_19 = F_19 ( V_29 , sizeof( * V_19 ) , V_50 ) ;
if ( ! V_19 )
return - V_51 ;
V_20 = F_19 ( V_29 , sizeof( * V_20 ) , V_50 ) ;
if ( ! V_20 )
return - V_51 ;
V_33 = F_19 ( V_29 , sizeof( * V_33 ) , V_50 ) ;
if ( ! V_33 )
return - V_51 ;
F_29 ( V_19 ) ;
F_1 ( V_10 + V_43 , ~ 0 ) ;
F_1 ( V_10 + V_47 , 0 ) ;
F_1 ( V_10 + V_46 , 0 ) ;
V_8 = F_3 ( V_10 + V_34 ) ;
V_8 &= ~ ( V_66 ) ;
if ( F_20 ( V_60 , L_15 ) )
V_8 |= V_67 ;
if ( F_20 ( V_60 , L_16 ) )
V_8 |= V_68 ;
if ( F_20 ( V_60 , L_17 ) )
V_8 |= V_69 ;
if ( ! F_20 ( V_60 , L_18 ) )
V_8 |= V_70 ;
if ( ! F_20 ( V_60 , L_19 ) )
V_8 |= V_71 ;
F_1 ( V_10 + V_34 , V_8 ) ;
F_30 (np, child) {
int V_49 ;
T_2 V_1 ;
if ( F_31 ( V_62 , L_20 , & V_1 ) )
continue;
if ( V_1 >= V_72 ) {
F_32 ( V_29 , L_21 , V_1 ,
V_72 ) ;
continue;
}
if ( F_20 ( V_62 , L_22 ) )
V_49 = F_15 ( V_29 , V_62 , V_1 , V_10 , V_19 ) ;
else
V_49 = V_4 ( V_29 , V_62 , V_1 , V_10 , V_19 ,
V_20 , V_33 ) ;
if ( V_49 < 0 ) {
F_33 ( V_62 ) ;
return V_49 ;
}
}
return 0 ;
}
