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
static void F_13 ( struct V_2 * V_3 , unsigned V_10 , int V_14 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
int V_5 = F_7 ( V_10 ) ;
int V_15 = F_14 ( V_10 ) ;
T_2 V_11 , V_16 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_15 ( V_10 ) ) ;
V_11 &= V_17 ;
if ( V_18 == V_11 )
goto V_19;
V_16 = V_14 ? F_16 ( V_5 ) : F_17 ( V_5 ) ;
V_11 = F_9 ( V_4 + V_16 ) ;
V_11 |= F_10 ( V_15 ) ;
F_4 ( V_11 , V_4 + V_16 ) ;
V_19:
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static int F_18 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
int V_5 = F_7 ( V_10 ) ;
int V_15 = F_14 ( V_10 ) ;
T_2 V_11 , V_16 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_15 ( V_10 ) ) ;
V_11 &= V_17 ;
V_16 = ( V_18 == V_11 ) ?
F_19 ( V_5 ) : F_20 ( V_5 ) ;
V_11 = F_9 ( V_4 + V_16 ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return ! ! ( V_11 & F_10 ( V_15 ) ) ;
}
static int F_21 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_12 ( V_9 , V_10 ) ;
return 0 ;
}
static void F_22 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_6 ( V_9 , V_10 ) ;
}
static int F_23 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_15 ( V_10 ) ) ;
V_11 &= ~ V_17 ;
V_11 |= V_18 ;
F_4 ( V_11 , V_4 + F_15 ( V_10 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
unsigned V_10 , int V_14 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
int V_5 = F_7 ( V_10 ) ;
int V_15 = F_14 ( V_10 ) ;
T_2 V_11 , V_16 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_15 ( V_10 ) ) ;
V_11 &= ~ V_17 ;
V_11 |= V_20 ;
F_4 ( V_11 , V_4 + F_15 ( V_10 ) ) ;
V_16 = V_14 ? F_16 ( V_5 ) : F_17 ( V_5 ) ;
V_11 = F_9 ( V_4 + V_16 ) ;
V_11 |= F_10 ( V_15 ) ;
F_4 ( V_11 , V_4 + V_16 ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 ) ;
if ( V_10 >= V_9 -> V_2 . V_21 )
return - V_22 ;
return F_26 ( V_9 -> V_23 , V_10 ) ;
}
static int F_27 ( struct V_2 * V_3 , unsigned V_10 ,
unsigned V_24 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
T_2 V_11 , V_25 ;
unsigned long V_12 ;
V_9 = F_1 ( V_3 ) ;
V_4 = V_9 -> V_4 ;
if ( ( V_24 > 0 && V_24 < 1000 ) || V_24 > 128000 ) {
F_28 ( V_3 -> V_26 , L_1 ,
V_24 ) ;
return - V_27 ;
}
if ( V_24 != 0 ) {
V_24 /= 1000 ;
V_25 = F_29 ( V_24 ) - 1 ;
if ( V_25 > 0 && ( V_24 & F_10 ( V_25 - 1 ) ) )
V_25 ++ ;
}
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_15 ( V_10 ) ) ;
V_11 &= ~ V_28 ;
if ( V_24 == 0 ) {
V_11 &= ~ V_29 ;
} else {
V_11 |= V_29 |
( V_25 << V_30 ) ;
}
F_4 ( V_11 , V_4 + F_15 ( V_10 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static void F_30 ( struct V_31 * V_32 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
unsigned V_10 = V_32 -> V_33 ;
int V_5 = F_7 ( V_10 ) ;
int V_15 = F_14 ( V_10 ) ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_31 ( V_32 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_32 ( V_5 ) ) ;
V_11 |= F_10 ( V_15 ) ;
F_4 ( V_11 , V_4 + F_32 ( V_5 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static void F_33 ( struct V_31 * V_32 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
unsigned V_10 = V_32 -> V_33 ;
int V_5 = F_7 ( V_10 ) ;
int V_15 = F_14 ( V_10 ) ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_31 ( V_32 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_34 ( V_5 ) ) ;
V_11 |= F_10 ( V_15 ) ;
F_4 ( V_11 , V_4 + F_34 ( V_5 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static void F_35 ( struct V_31 * V_32 )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
unsigned V_10 = V_32 -> V_33 ;
int V_5 = F_7 ( V_10 ) ;
int V_15 = F_14 ( V_10 ) ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_31 ( V_32 ) ;
V_4 = V_9 -> V_4 ;
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_36 ( V_5 ) ) ;
V_11 |= F_10 ( V_15 ) ;
F_4 ( V_11 , V_4 + F_36 ( V_5 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
}
static int F_37 ( struct V_31 * V_32 , unsigned int type )
{
struct V_1 * V_9 ;
void T_1 * V_4 ;
unsigned V_10 = V_32 -> V_33 ;
T_2 V_34 ;
T_2 V_11 ;
unsigned long V_12 ;
V_9 = F_31 ( V_32 ) ;
V_4 = V_9 -> V_4 ;
switch ( type & V_35 ) {
case V_36 :
V_34 = V_37 ;
break;
case V_38 :
V_34 = V_39 ;
break;
case V_40 :
V_34 = V_41 ;
break;
case V_42 :
case V_43 :
default:
F_28 ( V_9 -> V_2 . V_26 ,
L_2 , type ) ;
return - V_27 ;
}
F_8 ( & V_9 -> V_13 , V_12 ) ;
V_11 = F_9 ( V_4 + F_15 ( V_10 ) ) ;
V_11 &= ~ V_44 ;
V_11 |= V_34 << V_45 ;
F_4 ( V_11 , V_4 + F_15 ( V_10 ) ) ;
F_11 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static void F_38 ( unsigned int V_46 , struct V_47 * V_48 )
{
void T_1 * V_4 ;
int V_15 , V_5 ;
unsigned long V_49 ;
struct V_50 * V_51 = F_39 ( V_46 ) ;
struct V_52 * V_3 = F_40 ( V_48 ) ;
F_41 ( V_3 , V_48 ) ;
V_4 = V_51 -> V_9 -> V_4 ;
V_5 = V_51 -> V_53 ;
while ( ( V_49 = F_9 ( V_4 + F_32 ( V_5 ) ) &
( ~ ( F_9 ( V_4 + F_34 ( V_5 ) ) ) ) ) ) {
F_42 (bit, &sta, 32 ) {
int V_33 = V_54 * V_5 + V_15 ;
int V_55 =
F_43 ( V_51 -> V_9 -> V_23 ,
V_33 ) ;
F_4 ( F_9 ( V_4 + F_32 ( V_5 ) ) |
F_10 ( V_15 ) , V_4 + F_32 ( V_5 ) ) ;
F_44 ( V_55 ) ;
}
}
F_45 ( V_3 , V_48 ) ;
}
static int F_46 ( struct V_31 * V_32 )
{
struct V_1 * V_9 = F_31 ( V_32 ) ;
if ( F_47 ( & V_9 -> V_2 , V_32 -> V_33 ) ) {
F_28 ( V_9 -> V_2 . V_26 ,
L_3 ,
V_32 -> V_33 ) ;
return - V_27 ;
}
return 0 ;
}
static void F_48 ( struct V_31 * V_32 )
{
struct V_1 * V_9 = F_31 ( V_32 ) ;
F_49 ( & V_9 -> V_2 , V_32 -> V_33 ) ;
}
static int F_50 ( struct V_23 * V_32 , unsigned int V_46 ,
T_3 V_33 )
{
int V_56 ;
V_56 = F_51 ( V_46 , V_32 -> V_57 ) ;
if ( V_56 < 0 )
return V_56 ;
F_52 ( V_46 , & V_58 ) ;
F_53 ( V_46 , & V_59 , V_60 ) ;
#ifdef F_54
F_55 ( V_46 , V_61 ) ;
#else
F_56 ( V_46 ) ;
#endif
return 0 ;
}
static void F_57 ( struct V_23 * V_32 , unsigned int V_46 )
{
F_53 ( V_46 , NULL , NULL ) ;
F_51 ( V_46 , NULL ) ;
}
static void F_58 ( struct V_1 * V_9 )
{
void T_1 * V_4 ;
int V_62 ;
V_4 = V_9 -> V_4 ;
for ( V_62 = 0 ; V_62 < V_9 -> V_63 ; V_62 ++ ) {
F_3 ( V_9 , V_62 , V_64 ) ;
F_4 ( 0xffffffff , V_4 + F_34 ( V_62 ) ) ;
F_4 ( 0xffffffff , V_4 + F_32 ( V_62 ) ) ;
F_3 ( V_9 , V_62 , V_65 ) ;
}
}
static int F_59 ( struct V_66 * V_67 )
{
struct V_68 * V_26 = & V_67 -> V_26 ;
const struct V_69 * V_70 ;
struct V_71 * V_25 ;
struct V_50 * V_51 ;
struct V_1 * V_9 ;
struct V_2 * V_3 ;
int V_56 ;
int V_62 ;
V_70 = F_60 ( V_72 , V_26 ) ;
if ( ! V_70 ) {
F_28 ( V_26 , L_4 ) ;
return - V_73 ;
}
V_9 = F_61 ( V_26 , sizeof( * V_9 ) , V_74 ) ;
if ( ! V_9 )
return - V_75 ;
V_9 -> V_2 = V_76 ;
V_3 = & V_9 -> V_2 ;
V_9 -> V_63 = F_62 ( V_26 -> V_77 ) ;
if ( V_9 -> V_63 == 0 ) {
F_28 ( V_26 , L_5 ) ;
return - V_78 ;
}
if ( V_9 -> V_63 > V_79 ) {
F_28 ( V_26 , L_6 ,
V_79 ) ;
return - V_22 ;
}
V_9 -> V_80 = F_61 ( V_26 ,
V_9 -> V_63 *
sizeof( * V_9 -> V_80 ) , V_74 ) ;
if ( ! V_9 -> V_80 )
return - V_75 ;
V_9 -> V_67 = V_67 ;
F_63 ( V_67 , V_9 ) ;
V_3 -> V_77 = V_26 -> V_77 ;
V_3 -> V_21 = V_9 -> V_63 * V_54 ;
V_9 -> V_23 = F_64 ( V_26 -> V_77 ,
V_3 -> V_21 ,
& V_81 ,
V_9 ) ;
if ( ! V_9 -> V_23 ) {
F_28 ( V_26 , L_7 ) ;
return - V_22 ;
}
V_25 = F_65 ( V_67 , V_82 , 0 ) ;
V_9 -> V_4 = F_66 ( V_26 , V_25 ) ;
if ( F_67 ( V_9 -> V_4 ) ) {
V_56 = - V_22 ;
goto V_83;
}
for ( V_62 = 0 ; V_62 < V_9 -> V_63 ; V_62 ++ ) {
V_51 = & V_9 -> V_80 [ V_62 ] ;
V_51 -> V_53 = V_62 ;
V_51 -> V_46 = F_68 ( V_67 , V_62 ) ;
V_51 -> V_9 = V_9 ;
if ( V_51 -> V_46 < 0 ) {
F_28 ( V_26 , L_8 , V_62 ) ;
V_56 = - V_78 ;
goto V_83;
}
}
F_69 ( & V_67 -> V_26 , L_9 ) ;
F_58 ( V_9 ) ;
V_56 = F_70 ( V_3 ) ;
if ( V_56 < 0 ) {
F_28 ( V_26 , L_10 , V_56 ) ;
goto V_83;
}
for ( V_62 = 0 ; V_62 < V_3 -> V_21 ; V_62 ++ ) {
int V_46 = F_25 ( V_3 , V_62 ) ;
F_52 ( V_46 , & V_58 ) ;
F_53 ( V_46 , & V_59 ,
V_60 ) ;
#ifdef F_54
F_55 ( V_46 , V_61 ) ;
#else
F_56 ( V_46 ) ;
#endif
}
for ( V_62 = 0 ; V_62 < V_9 -> V_63 ; V_62 ++ ) {
V_51 = & V_9 -> V_80 [ V_62 ] ;
F_71 ( V_51 -> V_46 , F_38 ) ;
F_72 ( V_51 -> V_46 , V_51 ) ;
}
F_73 ( & V_9 -> V_13 ) ;
return 0 ;
V_83:
F_74 ( V_9 -> V_23 ) ;
return V_56 ;
}
