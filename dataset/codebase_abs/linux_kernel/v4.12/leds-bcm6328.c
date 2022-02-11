static void F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
#ifdef F_2
F_3 ( V_2 , V_1 ) ;
#else
F_4 ( V_2 , V_1 ) ;
#endif
}
static unsigned long F_5 ( void T_1 * V_1 )
{
#ifdef F_2
return F_6 ( V_1 ) ;
#else
return F_7 ( V_1 ) ;
#endif
}
static unsigned long F_8 ( unsigned long V_3 )
{
if ( V_3 < 8 )
return V_3 + 16 ;
else
return V_3 - 8 ;
}
static void F_9 ( struct V_4 * V_5 , unsigned long V_6 )
{
void T_1 * V_7 ;
unsigned long V_8 , V_9 ;
V_9 = F_8 ( V_5 -> V_3 ) ;
if ( V_9 / 16 )
V_7 = V_5 -> V_10 + V_11 ;
else
V_7 = V_5 -> V_10 + V_12 ;
V_8 = F_5 ( V_7 ) ;
V_8 &= ~ ( V_13 << F_10 ( V_9 % 16 ) ) ;
V_8 |= ( V_6 << F_10 ( V_9 % 16 ) ) ;
F_1 ( V_7 , V_8 ) ;
}
static void F_11 ( struct V_14 * V_15 ,
enum V_16 V_6 )
{
struct V_4 * V_5 =
F_12 ( V_15 , struct V_4 , V_17 ) ;
unsigned long V_18 ;
F_13 ( V_5 -> V_19 , V_18 ) ;
* ( V_5 -> V_20 ) &= ~ F_14 ( V_5 -> V_3 ) ;
if ( ( V_5 -> V_21 && V_6 == V_22 ) ||
( ! V_5 -> V_21 && V_6 != V_22 ) )
F_9 ( V_5 , V_23 ) ;
else
F_9 ( V_5 , V_24 ) ;
F_15 ( V_5 -> V_19 , V_18 ) ;
}
static unsigned long F_16 ( unsigned long V_25 )
{
unsigned long V_26 ;
V_26 = V_25 + V_27 / 2 ;
V_26 = V_26 / V_27 ;
if ( V_26 == 0 )
V_26 = 1 ;
return V_26 ;
}
static int F_17 ( struct V_14 * V_15 ,
unsigned long * V_28 , unsigned long * V_29 )
{
struct V_4 * V_5 =
F_12 ( V_15 , struct V_4 , V_17 ) ;
unsigned long V_25 , V_18 ;
int V_30 ;
if ( ! * V_28 )
* V_28 = V_31 ;
if ( ! * V_29 )
* V_29 = V_31 ;
V_25 = F_16 ( * V_28 ) ;
if ( V_25 != F_16 ( * V_29 ) ) {
F_18 ( V_15 -> V_32 ,
L_1 ) ;
return - V_33 ;
}
if ( V_25 > V_34 ) {
F_18 ( V_15 -> V_32 ,
L_2 ,
V_34 * V_27 ) ;
return - V_33 ;
}
F_13 ( V_5 -> V_19 , V_18 ) ;
if ( * ( V_5 -> V_20 ) == 0 ||
* ( V_5 -> V_20 ) == F_14 ( V_5 -> V_3 ) ||
* ( V_5 -> V_35 ) == V_25 ) {
unsigned long V_8 ;
* ( V_5 -> V_20 ) |= F_14 ( V_5 -> V_3 ) ;
* ( V_5 -> V_35 ) = V_25 ;
V_8 = F_5 ( V_5 -> V_10 + V_36 ) ;
V_8 &= ~ V_37 ;
V_8 |= ( V_25 << V_38 ) ;
F_1 ( V_5 -> V_10 + V_36 , V_8 ) ;
F_9 ( V_5 , V_39 ) ;
V_30 = 0 ;
} else {
F_18 ( V_15 -> V_32 ,
L_3 ) ;
V_30 = - V_33 ;
}
F_15 ( V_5 -> V_19 , V_18 ) ;
return V_30 ;
}
static int F_19 ( struct V_40 * V_32 , struct V_41 * V_42 , T_2 V_1 ,
void T_1 * V_10 , T_3 * V_19 )
{
int V_43 , V_44 ;
unsigned long V_18 , V_8 ;
F_13 ( V_19 , V_18 ) ;
V_8 = F_5 ( V_10 + V_45 ) ;
V_8 &= ~ F_14 ( V_1 ) ;
F_1 ( V_10 + V_45 , V_8 ) ;
F_15 ( V_19 , V_18 ) ;
if ( V_1 >= 8 )
return 0 ;
V_44 = F_20 ( V_42 , L_4 ,
sizeof( T_2 ) ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
T_2 V_46 ;
void T_1 * V_47 ;
if ( V_1 < 4 )
V_47 = V_10 + V_48 ;
else
V_47 = V_10 + V_49 ;
F_21 ( V_42 , L_4 , V_43 ,
& V_46 ) ;
if ( V_1 / 4 != V_46 / 4 ) {
F_22 ( V_32 , L_5 ) ;
continue;
}
F_13 ( V_19 , V_18 ) ;
V_8 = F_5 ( V_47 ) ;
V_8 |= ( F_14 ( V_1 % 4 ) << ( ( ( V_46 % 4 ) * 4 ) + 16 ) ) ;
F_1 ( V_47 , V_8 ) ;
F_15 ( V_19 , V_18 ) ;
}
V_44 = F_20 ( V_42 ,
L_6 ,
sizeof( T_2 ) ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
T_2 V_46 ;
void T_1 * V_47 ;
if ( V_1 < 4 )
V_47 = V_10 + V_48 ;
else
V_47 = V_10 + V_49 ;
F_21 ( V_42 , L_6 ,
V_43 , & V_46 ) ;
if ( V_1 / 4 != V_46 / 4 ) {
F_22 ( V_32 , L_7 ) ;
continue;
}
F_13 ( V_19 , V_18 ) ;
V_8 = F_5 ( V_47 ) ;
V_8 |= ( F_14 ( V_1 % 4 ) << ( ( V_46 % 4 ) * 4 ) ) ;
F_1 ( V_47 , V_8 ) ;
F_15 ( V_19 , V_18 ) ;
}
return 0 ;
}
static int V_4 ( struct V_40 * V_32 , struct V_41 * V_42 , T_2 V_1 ,
void T_1 * V_10 , T_3 * V_19 ,
unsigned long * V_20 , unsigned long * V_35 )
{
struct V_4 * V_5 ;
const char * V_50 ;
int V_30 ;
V_5 = F_23 ( V_32 , sizeof( * V_5 ) , V_51 ) ;
if ( ! V_5 )
return - V_52 ;
V_5 -> V_3 = V_1 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_19 = V_19 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_35 = V_35 ;
if ( F_24 ( V_42 , L_8 ) )
V_5 -> V_21 = true ;
V_5 -> V_17 . V_53 = F_25 ( V_42 , L_9 , NULL ) ? : V_42 -> V_53 ;
V_5 -> V_17 . V_54 = F_25 ( V_42 ,
L_10 ,
NULL ) ;
if ( ! F_26 ( V_42 , L_11 , & V_50 ) ) {
if ( ! strcmp ( V_50 , L_12 ) ) {
V_5 -> V_17 . V_55 = V_56 ;
} else if ( ! strcmp ( V_50 , L_13 ) ) {
void T_1 * V_7 ;
unsigned long V_8 , V_9 ;
V_9 = F_8 ( V_5 -> V_3 ) ;
if ( V_9 / 16 )
V_7 = V_10 + V_11 ;
else
V_7 = V_10 + V_12 ;
V_8 = F_5 ( V_7 ) >>
F_10 ( V_9 % 16 ) ;
V_8 &= V_13 ;
if ( ( V_5 -> V_21 && V_8 == V_24 ) ||
( ! V_5 -> V_21 && V_8 == V_23 ) )
V_5 -> V_17 . V_55 = V_56 ;
else
V_5 -> V_17 . V_55 = V_22 ;
} else {
V_5 -> V_17 . V_55 = V_22 ;
}
} else {
V_5 -> V_17 . V_55 = V_22 ;
}
F_11 ( & V_5 -> V_17 , V_5 -> V_17 . V_55 ) ;
V_5 -> V_17 . V_57 = F_11 ;
V_5 -> V_17 . V_58 = F_17 ;
V_30 = F_27 ( V_32 , & V_5 -> V_17 ) ;
if ( V_30 < 0 )
return V_30 ;
F_18 ( V_32 , L_14 , V_5 -> V_17 . V_53 ) ;
return 0 ;
}
static int F_28 ( struct V_59 * V_60 )
{
struct V_40 * V_32 = & V_60 -> V_32 ;
struct V_41 * V_61 = V_60 -> V_32 . V_62 ;
struct V_41 * V_63 ;
struct V_64 * V_65 ;
void T_1 * V_10 ;
T_3 * V_19 ;
unsigned long V_8 , * V_20 , * V_35 ;
V_65 = F_29 ( V_60 , V_66 , 0 ) ;
if ( ! V_65 )
return - V_33 ;
V_10 = F_30 ( V_32 , V_65 ) ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
V_19 = F_23 ( V_32 , sizeof( * V_19 ) , V_51 ) ;
if ( ! V_19 )
return - V_52 ;
V_20 = F_23 ( V_32 , sizeof( * V_20 ) , V_51 ) ;
if ( ! V_20 )
return - V_52 ;
V_35 = F_23 ( V_32 , sizeof( * V_35 ) , V_51 ) ;
if ( ! V_35 )
return - V_52 ;
F_33 ( V_19 ) ;
F_1 ( V_10 + V_45 , ~ 0 ) ;
F_1 ( V_10 + V_49 , 0 ) ;
F_1 ( V_10 + V_48 , 0 ) ;
V_8 = F_5 ( V_10 + V_36 ) ;
V_8 &= ~ ( V_67 ) ;
if ( F_24 ( V_61 , L_15 ) )
V_8 |= V_68 ;
if ( F_24 ( V_61 , L_16 ) )
V_8 |= V_69 ;
if ( F_24 ( V_61 , L_17 ) )
V_8 |= V_70 ;
if ( ! F_24 ( V_61 , L_18 ) )
V_8 |= V_71 ;
if ( ! F_24 ( V_61 , L_19 ) )
V_8 |= V_72 ;
F_1 ( V_10 + V_36 , V_8 ) ;
F_34 (np, child) {
int V_30 ;
T_2 V_1 ;
if ( F_35 ( V_63 , L_20 , & V_1 ) )
continue;
if ( V_1 >= V_73 ) {
F_36 ( V_32 , L_21 , V_1 ,
V_73 ) ;
continue;
}
if ( F_24 ( V_63 , L_22 ) )
V_30 = F_19 ( V_32 , V_63 , V_1 , V_10 , V_19 ) ;
else
V_30 = V_4 ( V_32 , V_63 , V_1 , V_10 , V_19 ,
V_20 , V_35 ) ;
if ( V_30 < 0 ) {
F_37 ( V_63 ) ;
return V_30 ;
}
}
return 0 ;
}
