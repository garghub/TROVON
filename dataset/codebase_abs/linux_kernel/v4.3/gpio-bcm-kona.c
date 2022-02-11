static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static inline void F_3 ( void T_1 * V_4 ,
int V_5 , T_2 V_6 )
{
F_4 ( V_7 , V_4 + V_8 ) ;
F_4 ( V_6 , V_4 + F_5 ( V_5 ) ) ;
}
static void F_6 ( struct V_1 * V_9 ,
unsigned V_10 )
{
T_2 V_11 ;
unsigned long V_12 ;
int V_5 = F_7 ( V_10 ) ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_9 -> V_4 + F_5 ( V_5 ) ) ;
V_11 |= F_10 ( V_10 ) ;
F_3 ( V_9 -> V_4 , V_5 , V_11 ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static void F_12 ( struct V_1 * V_9 ,
unsigned V_10 )
{
T_2 V_11 ;
unsigned long V_12 ;
int V_5 = F_7 ( V_10 ) ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_9 -> V_4 + F_5 ( V_5 ) ) ;
V_11 &= ~ F_10 ( V_10 ) ;
F_3 ( V_9 -> V_4 , V_5 , V_11 ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static int F_13 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
void T_1 * V_4 = V_9 -> V_4 ;
T_2 V_11 ;
V_11 = F_9 ( V_4 + F_14 ( V_10 ) ) & V_14 ;
return V_11 ? V_15 : V_16 ;
}
static void F_15 ( struct V_2 * V_3 , unsigned V_10 , int V_17 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
int V_5 = F_7 ( V_10 ) ;
int V_18 = F_16 ( V_10 ) ;
T_2 V_11 , V_19 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
if ( F_13 ( V_3 , V_10 ) == V_15 )
goto V_20;
V_19 = V_17 ? F_17 ( V_5 ) : F_18 ( V_5 ) ;
V_11 = F_9 ( V_4 + V_19 ) ;
V_11 |= F_10 ( V_18 ) ;
F_4 ( V_11 , V_4 + V_19 ) ;
V_20:
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static int F_19 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
int V_5 = F_7 ( V_10 ) ;
int V_18 = F_16 ( V_10 ) ;
T_2 V_11 , V_19 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
if ( F_13 ( V_3 , V_10 ) == V_15 )
V_19 = F_20 ( V_5 ) ;
else
V_19 = F_21 ( V_5 ) ;
V_11 = F_9 ( V_4 + V_19 ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return ! ! ( V_11 & F_10 ( V_18 ) ) ;
}
static int F_22 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_12 ( V_9 , V_10 ) ;
return 0 ;
}
static void F_23 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_6 ( V_9 , V_10 ) ;
}
static int F_24 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_14 ( V_10 ) ) ;
V_11 &= ~ V_14 ;
V_11 |= V_21 ;
F_4 ( V_11 , V_4 + F_14 ( V_10 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
unsigned V_10 , int V_17 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
int V_5 = F_7 ( V_10 ) ;
int V_18 = F_16 ( V_10 ) ;
T_2 V_11 , V_19 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_14 ( V_10 ) ) ;
V_11 &= ~ V_14 ;
V_11 |= V_22 ;
F_4 ( V_11 , V_4 + F_14 ( V_10 ) ) ;
V_19 = V_17 ? F_17 ( V_5 ) : F_18 ( V_5 ) ;
V_11 = F_9 ( V_4 + V_19 ) ;
V_11 |= F_10 ( V_18 ) ;
F_4 ( V_11 , V_4 + V_19 ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 ) ;
if ( V_10 >= V_9 -> V_2 . V_23 )
return - V_24 ;
return F_27 ( V_9 -> V_25 , V_10 ) ;
}
static int F_28 ( struct V_2 * V_3 , unsigned V_10 ,
unsigned V_26 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
T_2 V_11 , V_27 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
if ( ( V_26 > 0 && V_26 < 1000 ) || V_26 > 128000 ) {
F_29 ( V_3 -> V_28 , L_1 ,
V_26 ) ;
return - V_29 ;
}
if ( V_26 != 0 ) {
V_26 /= 1000 ;
V_27 = F_30 ( V_26 ) - 1 ;
if ( V_27 > 0 && ( V_26 & F_10 ( V_27 - 1 ) ) )
V_27 ++ ;
}
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_14 ( V_10 ) ) ;
V_11 &= ~ V_30 ;
if ( V_26 == 0 ) {
V_11 &= ~ V_31 ;
} else {
V_11 |= V_31 |
( V_27 << V_32 ) ;
}
F_4 ( V_11 , V_4 + F_14 ( V_10 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static void F_31 ( struct V_33 * V_34 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
unsigned V_10 = V_34 -> V_35 ;
int V_5 = F_7 ( V_10 ) ;
int V_18 = F_16 ( V_10 ) ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_32 ( V_34 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_33 ( V_5 ) ) ;
V_11 |= F_10 ( V_18 ) ;
F_4 ( V_11 , V_4 + F_33 ( V_5 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static void F_34 ( struct V_33 * V_34 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
unsigned V_10 = V_34 -> V_35 ;
int V_5 = F_7 ( V_10 ) ;
int V_18 = F_16 ( V_10 ) ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_32 ( V_34 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_35 ( V_5 ) ) ;
V_11 |= F_10 ( V_18 ) ;
F_4 ( V_11 , V_4 + F_35 ( V_5 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static void F_36 ( struct V_33 * V_34 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
unsigned V_10 = V_34 -> V_35 ;
int V_5 = F_7 ( V_10 ) ;
int V_18 = F_16 ( V_10 ) ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_32 ( V_34 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_37 ( V_5 ) ) ;
V_11 |= F_10 ( V_18 ) ;
F_4 ( V_11 , V_4 + F_37 ( V_5 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static int F_38 ( struct V_33 * V_34 , unsigned int type )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
unsigned V_10 = V_34 -> V_35 ;
T_2 V_36 ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_32 ( V_34 ) ;
V_4 = V_9 -> V_4 ;
switch ( type & V_37 ) {
case V_38 :
V_36 = V_39 ;
break;
case V_40 :
V_36 = V_41 ;
break;
case V_42 :
V_36 = V_43 ;
break;
case V_44 :
case V_45 :
default:
F_29 ( V_9 -> V_2 . V_28 ,
L_2 , type ) ;
return - V_29 ;
}
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_14 ( V_10 ) ) ;
V_11 &= ~ V_46 ;
V_11 |= V_36 << V_47 ;
F_4 ( V_11 , V_4 + F_14 ( V_10 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static void F_39 ( struct V_48 * V_49 )
{
void T_1 * V_4 ;
int V_18 , V_5 ;
unsigned long V_50 ;
struct V_51 * V_52 = F_40 ( V_49 ) ;
struct V_53 * V_3 = F_41 ( V_49 ) ;
F_42 ( V_3 , V_49 ) ;
V_4 = V_52 -> V_9 -> V_4 ;
V_5 = V_52 -> V_54 ;
while ( ( V_50 = F_9 ( V_4 + F_33 ( V_5 ) ) &
( ~ ( F_9 ( V_4 + F_35 ( V_5 ) ) ) ) ) ) {
F_43 (bit, &sta, 32 ) {
int V_35 = V_55 * V_5 + V_18 ;
int V_56 =
F_44 ( V_52 -> V_9 -> V_25 ,
V_35 ) ;
F_4 ( F_9 ( V_4 + F_33 ( V_5 ) ) |
F_10 ( V_18 ) , V_4 + F_33 ( V_5 ) ) ;
F_45 ( V_56 ) ;
}
}
F_46 ( V_3 , V_49 ) ;
}
static int F_47 ( struct V_33 * V_34 )
{
struct V_1 * V_9 = F_32 ( V_34 ) ;
if ( F_48 ( & V_9 -> V_2 , V_34 -> V_35 ) ) {
F_29 ( V_9 -> V_2 . V_28 ,
L_3 ,
V_34 -> V_35 ) ;
return - V_29 ;
}
return 0 ;
}
static void F_49 ( struct V_33 * V_34 )
{
struct V_1 * V_9 = F_32 ( V_34 ) ;
F_50 ( & V_9 -> V_2 , V_34 -> V_35 ) ;
}
static int F_51 ( struct V_25 * V_34 , unsigned int V_57 ,
T_3 V_35 )
{
int V_58 ;
V_58 = F_52 ( V_57 , V_34 -> V_59 ) ;
if ( V_58 < 0 )
return V_58 ;
F_53 ( V_57 , & V_60 ) ;
F_54 ( V_57 , & V_61 , V_62 ) ;
F_55 ( V_57 ) ;
return 0 ;
}
static void F_56 ( struct V_25 * V_34 , unsigned int V_57 )
{
F_54 ( V_57 , NULL , NULL ) ;
F_52 ( V_57 , NULL ) ;
}
static void F_57 ( struct V_1 * V_9 )
{
void T_1 * V_4 ;
int V_63 ;
V_4 = V_9 -> V_4 ;
for ( V_63 = 0 ; V_63 < V_9 -> V_64 ; V_63 ++ ) {
F_3 ( V_9 , V_63 , V_65 ) ;
F_4 ( 0xffffffff , V_4 + F_35 ( V_63 ) ) ;
F_4 ( 0xffffffff , V_4 + F_33 ( V_63 ) ) ;
F_3 ( V_9 , V_63 , V_66 ) ;
}
}
static int F_58 ( struct V_67 * V_68 )
{
struct V_69 * V_28 = & V_68 -> V_28 ;
const struct V_70 * V_71 ;
struct V_72 * V_27 ;
struct V_51 * V_52 ;
struct V_1 * V_9 ;
struct V_2 * V_3 ;
int V_58 ;
int V_63 ;
V_71 = F_59 ( V_73 , V_28 ) ;
if ( ! V_71 ) {
F_29 ( V_28 , L_4 ) ;
return - V_74 ;
}
V_9 = F_60 ( V_28 , sizeof( * V_9 ) , V_75 ) ;
if ( ! V_9 )
return - V_76 ;
V_9 -> V_2 = V_77 ;
V_3 = & V_9 -> V_2 ;
V_9 -> V_64 = F_61 ( V_28 -> V_78 ) ;
if ( V_9 -> V_64 == 0 ) {
F_29 ( V_28 , L_5 ) ;
return - V_79 ;
}
if ( V_9 -> V_64 > V_80 ) {
F_29 ( V_28 , L_6 ,
V_80 ) ;
return - V_24 ;
}
V_9 -> V_81 = F_60 ( V_28 ,
V_9 -> V_64 *
sizeof( * V_9 -> V_81 ) , V_75 ) ;
if ( ! V_9 -> V_81 )
return - V_76 ;
V_9 -> V_68 = V_68 ;
F_62 ( V_68 , V_9 ) ;
V_3 -> V_78 = V_28 -> V_78 ;
V_3 -> V_23 = V_9 -> V_64 * V_55 ;
V_9 -> V_25 = F_63 ( V_28 -> V_78 ,
V_3 -> V_23 ,
& V_82 ,
V_9 ) ;
if ( ! V_9 -> V_25 ) {
F_29 ( V_28 , L_7 ) ;
return - V_24 ;
}
V_27 = F_64 ( V_68 , V_83 , 0 ) ;
V_9 -> V_4 = F_65 ( V_28 , V_27 ) ;
if ( F_66 ( V_9 -> V_4 ) ) {
V_58 = - V_24 ;
goto V_84;
}
for ( V_63 = 0 ; V_63 < V_9 -> V_64 ; V_63 ++ ) {
V_52 = & V_9 -> V_81 [ V_63 ] ;
V_52 -> V_54 = V_63 ;
V_52 -> V_57 = F_67 ( V_68 , V_63 ) ;
V_52 -> V_9 = V_9 ;
if ( V_52 -> V_57 < 0 ) {
F_29 ( V_28 , L_8 , V_63 ) ;
V_58 = - V_79 ;
goto V_84;
}
}
F_68 ( & V_68 -> V_28 , L_9 ) ;
F_57 ( V_9 ) ;
V_58 = F_69 ( V_3 ) ;
if ( V_58 < 0 ) {
F_29 ( V_28 , L_10 , V_58 ) ;
goto V_84;
}
for ( V_63 = 0 ; V_63 < V_9 -> V_64 ; V_63 ++ ) {
V_52 = & V_9 -> V_81 [ V_63 ] ;
F_70 ( V_52 -> V_57 ,
F_39 ,
V_52 ) ;
}
F_71 ( & V_9 -> V_13 ) ;
return 0 ;
V_84:
F_72 ( V_9 -> V_25 ) ;
return V_58 ;
}
