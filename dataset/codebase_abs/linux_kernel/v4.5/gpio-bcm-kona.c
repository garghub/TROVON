static inline void F_1 ( void T_1 * V_1 ,
int V_2 , T_2 V_3 )
{
F_2 ( V_4 , V_1 + V_5 ) ;
F_2 ( V_3 , V_1 + F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_6 * V_7 ,
unsigned V_8 )
{
T_2 V_9 ;
unsigned long V_10 ;
int V_2 = F_5 ( V_8 ) ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_7 -> V_1 + F_3 ( V_2 ) ) ;
V_9 |= F_8 ( V_8 ) ;
F_1 ( V_7 -> V_1 , V_2 , V_9 ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static void F_10 ( struct V_6 * V_7 ,
unsigned V_8 )
{
T_2 V_9 ;
unsigned long V_10 ;
int V_2 = F_5 ( V_8 ) ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_7 -> V_1 + F_3 ( V_2 ) ) ;
V_9 &= ~ F_8 ( V_8 ) ;
F_1 ( V_7 -> V_1 , V_2 , V_9 ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static int F_11 ( struct V_12 * V_13 , unsigned V_8 )
{
struct V_6 * V_7 = F_12 ( V_13 ) ;
void T_1 * V_1 = V_7 -> V_1 ;
T_2 V_9 ;
V_9 = F_7 ( V_1 + F_13 ( V_8 ) ) & V_14 ;
return V_9 ? V_15 : V_16 ;
}
static void F_14 ( struct V_12 * V_13 , unsigned V_8 , int V_17 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 , V_19 ;
unsigned long V_10 ;
V_7 = F_12 ( V_13 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
if ( F_11 ( V_13 , V_8 ) == V_15 )
goto V_20;
V_19 = V_17 ? F_16 ( V_2 ) : F_17 ( V_2 ) ;
V_9 = F_7 ( V_1 + V_19 ) ;
V_9 |= F_8 ( V_18 ) ;
F_2 ( V_9 , V_1 + V_19 ) ;
V_20:
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static int F_18 ( struct V_12 * V_13 , unsigned V_8 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 , V_19 ;
unsigned long V_10 ;
V_7 = F_12 ( V_13 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
if ( F_11 ( V_13 , V_8 ) == V_15 )
V_19 = F_19 ( V_2 ) ;
else
V_19 = F_20 ( V_2 ) ;
V_9 = F_7 ( V_1 + V_19 ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
return ! ! ( V_9 & F_8 ( V_18 ) ) ;
}
static int F_21 ( struct V_12 * V_13 , unsigned V_8 )
{
struct V_6 * V_7 = F_12 ( V_13 ) ;
F_10 ( V_7 , V_8 ) ;
return 0 ;
}
static void F_22 ( struct V_12 * V_13 , unsigned V_8 )
{
struct V_6 * V_7 = F_12 ( V_13 ) ;
F_4 ( V_7 , V_8 ) ;
}
static int F_23 ( struct V_12 * V_13 , unsigned V_8 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_12 ( V_13 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_13 ( V_8 ) ) ;
V_9 &= ~ V_14 ;
V_9 |= V_21 ;
F_2 ( V_9 , V_1 + F_13 ( V_8 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
return 0 ;
}
static int F_24 ( struct V_12 * V_13 ,
unsigned V_8 , int V_17 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 , V_19 ;
unsigned long V_10 ;
V_7 = F_12 ( V_13 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_13 ( V_8 ) ) ;
V_9 &= ~ V_14 ;
V_9 |= V_22 ;
F_2 ( V_9 , V_1 + F_13 ( V_8 ) ) ;
V_19 = V_17 ? F_16 ( V_2 ) : F_17 ( V_2 ) ;
V_9 = F_7 ( V_1 + V_19 ) ;
V_9 |= F_8 ( V_18 ) ;
F_2 ( V_9 , V_1 + V_19 ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 , unsigned V_8 )
{
struct V_6 * V_7 ;
V_7 = F_12 ( V_13 ) ;
if ( V_8 >= V_7 -> V_12 . V_23 )
return - V_24 ;
return F_26 ( V_7 -> V_25 , V_8 ) ;
}
static int F_27 ( struct V_12 * V_13 , unsigned V_8 ,
unsigned V_26 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
T_2 V_9 , V_27 ;
unsigned long V_10 ;
V_7 = F_12 ( V_13 ) ;
V_1 = V_7 -> V_1 ;
if ( ( V_26 > 0 && V_26 < 1000 ) || V_26 > 128000 ) {
F_28 ( V_13 -> V_28 , L_1 ,
V_26 ) ;
return - V_29 ;
}
if ( V_26 != 0 ) {
V_26 /= 1000 ;
V_27 = F_29 ( V_26 ) - 1 ;
if ( V_27 > 0 && ( V_26 & F_8 ( V_27 - 1 ) ) )
V_27 ++ ;
}
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_13 ( V_8 ) ) ;
V_9 &= ~ V_30 ;
if ( V_26 == 0 ) {
V_9 &= ~ V_31 ;
} else {
V_9 |= V_31 |
( V_27 << V_32 ) ;
}
F_2 ( V_9 , V_1 + F_13 ( V_8 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
return 0 ;
}
static void F_30 ( struct V_33 * V_34 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
unsigned V_8 = V_34 -> V_35 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_31 ( V_34 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_32 ( V_2 ) ) ;
V_9 |= F_8 ( V_18 ) ;
F_2 ( V_9 , V_1 + F_32 ( V_2 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static void F_33 ( struct V_33 * V_34 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
unsigned V_8 = V_34 -> V_35 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_31 ( V_34 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_34 ( V_2 ) ) ;
V_9 |= F_8 ( V_18 ) ;
F_2 ( V_9 , V_1 + F_34 ( V_2 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static void F_35 ( struct V_33 * V_34 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
unsigned V_8 = V_34 -> V_35 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_31 ( V_34 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_36 ( V_2 ) ) ;
V_9 |= F_8 ( V_18 ) ;
F_2 ( V_9 , V_1 + F_36 ( V_2 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static int F_37 ( struct V_33 * V_34 , unsigned int type )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
unsigned V_8 = V_34 -> V_35 ;
T_2 V_36 ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_31 ( V_34 ) ;
V_1 = V_7 -> V_1 ;
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
F_28 ( V_7 -> V_12 . V_28 ,
L_2 , type ) ;
return - V_29 ;
}
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_13 ( V_8 ) ) ;
V_9 &= ~ V_46 ;
V_9 |= V_36 << V_47 ;
F_2 ( V_9 , V_1 + F_13 ( V_8 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
return 0 ;
}
static void F_38 ( struct V_48 * V_49 )
{
void T_1 * V_1 ;
int V_18 , V_2 ;
unsigned long V_50 ;
struct V_51 * V_52 = F_39 ( V_49 ) ;
struct V_53 * V_13 = F_40 ( V_49 ) ;
F_41 ( V_13 , V_49 ) ;
V_1 = V_52 -> V_7 -> V_1 ;
V_2 = V_52 -> V_54 ;
while ( ( V_50 = F_7 ( V_1 + F_32 ( V_2 ) ) &
( ~ ( F_7 ( V_1 + F_34 ( V_2 ) ) ) ) ) ) {
F_42 (bit, &sta, 32 ) {
int V_35 = V_55 * V_2 + V_18 ;
int V_56 =
F_43 ( V_52 -> V_7 -> V_25 ,
V_35 ) ;
F_2 ( F_7 ( V_1 + F_32 ( V_2 ) ) |
F_8 ( V_18 ) , V_1 + F_32 ( V_2 ) ) ;
F_44 ( V_56 ) ;
}
}
F_45 ( V_13 , V_49 ) ;
}
static int F_46 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = F_31 ( V_34 ) ;
if ( F_47 ( & V_7 -> V_12 , V_34 -> V_35 ) ) {
F_28 ( V_7 -> V_12 . V_28 ,
L_3 ,
V_34 -> V_35 ) ;
return - V_29 ;
}
return 0 ;
}
static void F_48 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = F_31 ( V_34 ) ;
F_49 ( & V_7 -> V_12 , V_34 -> V_35 ) ;
}
static int F_50 ( struct V_25 * V_34 , unsigned int V_57 ,
T_3 V_35 )
{
int V_58 ;
V_58 = F_51 ( V_57 , V_34 -> V_59 ) ;
if ( V_58 < 0 )
return V_58 ;
F_52 ( V_57 , & V_60 ) ;
F_53 ( V_57 , & V_61 , V_62 ) ;
F_54 ( V_57 ) ;
return 0 ;
}
static void F_55 ( struct V_25 * V_34 , unsigned int V_57 )
{
F_53 ( V_57 , NULL , NULL ) ;
F_51 ( V_57 , NULL ) ;
}
static void F_56 ( struct V_6 * V_7 )
{
void T_1 * V_1 ;
int V_63 ;
V_1 = V_7 -> V_1 ;
for ( V_63 = 0 ; V_63 < V_7 -> V_64 ; V_63 ++ ) {
F_1 ( V_7 , V_63 , V_65 ) ;
F_2 ( 0xffffffff , V_1 + F_34 ( V_63 ) ) ;
F_2 ( 0xffffffff , V_1 + F_32 ( V_63 ) ) ;
F_1 ( V_7 , V_63 , V_66 ) ;
}
}
static int F_57 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = & V_68 -> V_70 ;
const struct V_71 * V_72 ;
struct V_73 * V_27 ;
struct V_51 * V_52 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
int V_58 ;
int V_63 ;
V_72 = F_58 ( V_74 , V_70 ) ;
if ( ! V_72 ) {
F_28 ( V_70 , L_4 ) ;
return - V_75 ;
}
V_7 = F_59 ( V_70 , sizeof( * V_7 ) , V_76 ) ;
if ( ! V_7 )
return - V_77 ;
V_7 -> V_12 = V_78 ;
V_13 = & V_7 -> V_12 ;
V_7 -> V_64 = F_60 ( V_70 -> V_79 ) ;
if ( V_7 -> V_64 == 0 ) {
F_28 ( V_70 , L_5 ) ;
return - V_80 ;
}
if ( V_7 -> V_64 > V_81 ) {
F_28 ( V_70 , L_6 ,
V_81 ) ;
return - V_24 ;
}
V_7 -> V_82 = F_59 ( V_70 ,
V_7 -> V_64 *
sizeof( * V_7 -> V_82 ) , V_76 ) ;
if ( ! V_7 -> V_82 )
return - V_77 ;
V_7 -> V_68 = V_68 ;
F_61 ( V_68 , V_7 ) ;
V_13 -> V_79 = V_70 -> V_79 ;
V_13 -> V_23 = V_7 -> V_64 * V_55 ;
V_7 -> V_25 = F_62 ( V_70 -> V_79 ,
V_13 -> V_23 ,
& V_83 ,
V_7 ) ;
if ( ! V_7 -> V_25 ) {
F_28 ( V_70 , L_7 ) ;
return - V_24 ;
}
V_27 = F_63 ( V_68 , V_84 , 0 ) ;
V_7 -> V_1 = F_64 ( V_70 , V_27 ) ;
if ( F_65 ( V_7 -> V_1 ) ) {
V_58 = - V_24 ;
goto V_85;
}
for ( V_63 = 0 ; V_63 < V_7 -> V_64 ; V_63 ++ ) {
V_52 = & V_7 -> V_82 [ V_63 ] ;
V_52 -> V_54 = V_63 ;
V_52 -> V_57 = F_66 ( V_68 , V_63 ) ;
V_52 -> V_7 = V_7 ;
if ( V_52 -> V_57 < 0 ) {
F_28 ( V_70 , L_8 , V_63 ) ;
V_58 = - V_80 ;
goto V_85;
}
}
F_67 ( & V_68 -> V_70 , L_9 ) ;
F_56 ( V_7 ) ;
V_58 = F_68 ( V_13 , V_7 ) ;
if ( V_58 < 0 ) {
F_28 ( V_70 , L_10 , V_58 ) ;
goto V_85;
}
for ( V_63 = 0 ; V_63 < V_7 -> V_64 ; V_63 ++ ) {
V_52 = & V_7 -> V_82 [ V_63 ] ;
F_69 ( V_52 -> V_57 ,
F_38 ,
V_52 ) ;
}
F_70 ( & V_7 -> V_11 ) ;
return 0 ;
V_85:
F_71 ( V_7 -> V_25 ) ;
return V_58 ;
}
