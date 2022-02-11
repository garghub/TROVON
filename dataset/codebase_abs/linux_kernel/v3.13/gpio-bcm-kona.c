static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static void F_3 ( void T_1 * V_4 ,
int V_5 , int V_6 )
{
F_4 ( V_7 , V_4 + V_8 ) ;
F_4 ( V_6 , V_4 + F_5 ( V_5 ) ) ;
}
static inline void F_6 ( void T_1 * V_4 , int V_5 )
{
F_3 ( V_4 , V_5 , V_9 ) ;
}
static inline void F_7 ( void T_1 * V_4 ,
int V_5 )
{
F_3 ( V_4 , V_5 , V_10 ) ;
}
static void F_8 ( struct V_2 * V_3 , unsigned V_11 , int V_12 )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
int V_5 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
T_2 V_15 , V_16 ;
unsigned long V_17 ;
V_13 = F_1 ( V_3 ) ;
V_4 = V_13 -> V_4 ;
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_13 ( V_11 ) ) ;
V_15 &= V_19 ;
if ( V_20 == V_15 )
goto V_21;
V_16 = V_12 ? F_14 ( V_5 ) : F_15 ( V_5 ) ;
V_15 = F_12 ( V_4 + V_16 ) ;
V_15 |= F_16 ( V_14 ) ;
F_4 ( V_15 , V_4 + V_16 ) ;
V_21:
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
}
static int F_18 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
int V_5 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
T_2 V_15 , V_16 ;
unsigned long V_17 ;
V_13 = F_1 ( V_3 ) ;
V_4 = V_13 -> V_4 ;
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_13 ( V_11 ) ) ;
V_15 &= V_19 ;
V_16 = ( V_20 == V_15 ) ?
F_19 ( V_5 ) : F_20 ( V_5 ) ;
V_15 = F_12 ( V_4 + V_16 ) ;
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
return ! ! ( V_15 & F_16 ( V_14 ) ) ;
}
static int F_21 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
T_2 V_15 ;
unsigned long V_17 ;
int V_5 = F_9 ( V_11 ) ;
V_13 = F_1 ( V_3 ) ;
V_4 = V_13 -> V_4 ;
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_13 ( V_11 ) ) ;
V_15 &= ~ V_19 ;
V_15 |= V_20 ;
F_4 ( V_15 , V_4 + F_13 ( V_11 ) ) ;
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
unsigned V_11 , int V_12 )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
int V_5 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
T_2 V_15 , V_16 ;
unsigned long V_17 ;
V_13 = F_1 ( V_3 ) ;
V_4 = V_13 -> V_4 ;
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_13 ( V_11 ) ) ;
V_15 &= ~ V_19 ;
V_15 |= V_22 ;
F_4 ( V_15 , V_4 + F_13 ( V_11 ) ) ;
V_16 = V_12 ? F_14 ( V_5 ) : F_15 ( V_5 ) ;
V_15 = F_12 ( V_4 + V_16 ) ;
V_15 |= F_16 ( V_14 ) ;
F_4 ( V_15 , V_4 + V_16 ) ;
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_13 ;
V_13 = F_1 ( V_3 ) ;
if ( V_11 >= V_13 -> V_2 . V_23 )
return - V_24 ;
return F_24 ( V_13 -> V_25 , V_11 ) ;
}
static int F_25 ( struct V_2 * V_3 , unsigned V_11 ,
unsigned V_26 )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
T_2 V_15 , V_27 ;
unsigned long V_17 ;
int V_5 = F_9 ( V_11 ) ;
V_13 = F_1 ( V_3 ) ;
V_4 = V_13 -> V_4 ;
if ( ( V_26 > 0 && V_26 < 1000 ) || V_26 > 128000 ) {
F_26 ( V_3 -> V_28 , L_1 ,
V_26 ) ;
return - V_29 ;
}
if ( V_26 != 0 ) {
V_26 /= 1000 ;
V_27 = F_27 ( V_26 ) - 1 ;
if ( V_27 > 0 && ( V_26 & F_16 ( V_27 - 1 ) ) )
V_27 ++ ;
}
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_13 ( V_11 ) ) ;
V_15 &= ~ V_30 ;
if ( V_26 == 0 ) {
V_15 &= ~ V_31 ;
} else {
V_15 |= V_31 |
( V_27 << V_32 ) ;
}
F_4 ( V_15 , V_4 + F_13 ( V_11 ) ) ;
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
return 0 ;
}
static void F_28 ( struct V_33 * V_34 )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
int V_11 = V_34 -> V_35 ;
int V_5 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
T_2 V_15 ;
unsigned long V_17 ;
V_13 = F_29 ( V_34 ) ;
V_4 = V_13 -> V_4 ;
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_30 ( V_5 ) ) ;
V_15 |= F_16 ( V_14 ) ;
F_4 ( V_15 , V_4 + F_30 ( V_5 ) ) ;
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
}
static void F_31 ( struct V_33 * V_34 )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
int V_11 = V_34 -> V_35 ;
int V_5 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
T_2 V_15 ;
unsigned long V_17 ;
V_13 = F_29 ( V_34 ) ;
V_4 = V_13 -> V_4 ;
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_32 ( V_5 ) ) ;
V_15 |= F_16 ( V_14 ) ;
F_4 ( V_15 , V_4 + F_32 ( V_5 ) ) ;
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
}
static void F_33 ( struct V_33 * V_34 )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
int V_11 = V_34 -> V_35 ;
int V_5 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
T_2 V_15 ;
unsigned long V_17 ;
V_13 = F_29 ( V_34 ) ;
V_4 = V_13 -> V_4 ;
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_34 ( V_5 ) ) ;
V_15 |= F_16 ( V_14 ) ;
F_4 ( V_15 , V_4 + F_34 ( V_5 ) ) ;
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
}
static int F_35 ( struct V_33 * V_34 , unsigned int type )
{
struct V_1 * V_13 ;
void T_1 * V_4 ;
int V_11 = V_34 -> V_35 ;
T_2 V_36 ;
T_2 V_15 ;
unsigned long V_17 ;
int V_5 = F_9 ( V_11 ) ;
V_13 = F_29 ( V_34 ) ;
V_4 = V_13 -> V_4 ;
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
F_26 ( V_13 -> V_2 . V_28 ,
L_2 , type ) ;
return - V_29 ;
}
F_11 ( & V_13 -> V_18 , V_17 ) ;
F_7 ( V_4 , V_5 ) ;
V_15 = F_12 ( V_4 + F_13 ( V_11 ) ) ;
V_15 &= ~ V_46 ;
V_15 |= V_36 << V_47 ;
F_4 ( V_15 , V_4 + F_13 ( V_11 ) ) ;
F_6 ( V_4 , V_5 ) ;
F_17 ( & V_13 -> V_18 , V_17 ) ;
return 0 ;
}
static void F_36 ( unsigned int V_48 , struct V_49 * V_50 )
{
void T_1 * V_4 ;
int V_14 , V_5 ;
unsigned long V_51 ;
struct V_52 * V_53 = F_37 ( V_48 ) ;
struct V_54 * V_3 = F_38 ( V_50 ) ;
F_39 ( V_3 , V_50 ) ;
V_4 = V_53 -> V_13 -> V_4 ;
V_5 = V_53 -> V_55 ;
F_7 ( V_4 , V_5 ) ;
while ( ( V_51 = F_12 ( V_4 + F_30 ( V_5 ) ) &
( ~ ( F_12 ( V_4 + F_32 ( V_5 ) ) ) ) ) ) {
F_40 (bit, &sta, 32 ) {
int V_35 = V_56 * V_5 + V_14 ;
int V_57 =
F_41 ( V_53 -> V_13 -> V_25 ,
V_35 ) ;
F_4 ( F_12 ( V_4 + F_30 ( V_5 ) ) |
F_16 ( V_14 ) , V_4 + F_30 ( V_5 ) ) ;
F_42 ( V_57 ) ;
}
}
F_6 ( V_4 , V_5 ) ;
F_43 ( V_3 , V_50 ) ;
}
static int F_44 ( struct V_25 * V_34 , unsigned int V_48 ,
T_3 V_35 )
{
int V_58 ;
V_58 = F_45 ( V_48 , V_34 -> V_59 ) ;
if ( V_58 < 0 )
return V_58 ;
F_46 ( V_48 , & V_60 ) ;
F_47 ( V_48 , & V_61 , V_62 ) ;
#ifdef F_48
F_49 ( V_48 , V_63 ) ;
#else
F_50 ( V_48 ) ;
#endif
return 0 ;
}
static void F_51 ( struct V_25 * V_34 , unsigned int V_48 )
{
F_47 ( V_48 , NULL , NULL ) ;
F_45 ( V_48 , NULL ) ;
}
static void F_52 ( struct V_1 * V_13 )
{
void T_1 * V_4 ;
int V_64 ;
V_4 = V_13 -> V_4 ;
for ( V_64 = 0 ; V_64 < V_13 -> V_65 ; V_64 ++ ) {
F_7 ( V_4 , V_64 ) ;
F_4 ( 0xffffffff , V_4 + F_32 ( V_64 ) ) ;
F_4 ( 0xffffffff , V_4 + F_30 ( V_64 ) ) ;
F_6 ( V_4 , V_64 ) ;
}
}
static int F_53 ( struct V_66 * V_67 )
{
struct V_68 * V_28 = & V_67 -> V_28 ;
const struct V_69 * V_70 ;
struct V_71 * V_27 ;
struct V_52 * V_53 ;
struct V_1 * V_13 ;
struct V_2 * V_3 ;
int V_58 ;
int V_64 ;
V_70 = F_54 ( V_72 , V_28 ) ;
if ( ! V_70 ) {
F_26 ( V_28 , L_3 ) ;
return - V_73 ;
}
V_13 = F_55 ( V_28 , sizeof( * V_13 ) , V_74 ) ;
if ( ! V_13 )
return - V_75 ;
V_13 -> V_2 = V_76 ;
V_3 = & V_13 -> V_2 ;
V_13 -> V_65 = F_56 ( V_28 -> V_77 ) ;
if ( V_13 -> V_65 == 0 ) {
F_26 ( V_28 , L_4 ) ;
return - V_78 ;
}
if ( V_13 -> V_65 > V_79 ) {
F_26 ( V_28 , L_5 ,
V_79 ) ;
return - V_24 ;
}
V_13 -> V_80 = F_55 ( V_28 ,
V_13 -> V_65 *
sizeof( * V_13 -> V_80 ) , V_74 ) ;
if ( ! V_13 -> V_80 )
return - V_75 ;
V_13 -> V_67 = V_67 ;
F_57 ( V_67 , V_13 ) ;
V_3 -> V_77 = V_28 -> V_77 ;
V_3 -> V_23 = V_13 -> V_65 * V_56 ;
V_13 -> V_25 = F_58 ( V_28 -> V_77 ,
V_3 -> V_23 ,
& V_81 ,
V_13 ) ;
if ( ! V_13 -> V_25 ) {
F_26 ( V_28 , L_6 ) ;
return - V_24 ;
}
V_27 = F_59 ( V_67 , V_82 , 0 ) ;
V_13 -> V_4 = F_60 ( V_28 , V_27 ) ;
if ( F_61 ( V_13 -> V_4 ) ) {
V_58 = - V_24 ;
goto V_83;
}
for ( V_64 = 0 ; V_64 < V_13 -> V_65 ; V_64 ++ ) {
V_53 = & V_13 -> V_80 [ V_64 ] ;
V_53 -> V_55 = V_64 ;
V_53 -> V_48 = F_62 ( V_67 , V_64 ) ;
V_53 -> V_13 = V_13 ;
if ( V_53 -> V_48 < 0 ) {
F_26 ( V_28 , L_7 , V_64 ) ;
V_58 = - V_78 ;
goto V_83;
}
}
F_63 ( & V_67 -> V_28 , L_8 ) ;
F_52 ( V_13 ) ;
V_58 = F_64 ( V_3 ) ;
if ( V_58 < 0 ) {
F_26 ( V_28 , L_9 , V_58 ) ;
goto V_83;
}
for ( V_64 = 0 ; V_64 < V_3 -> V_23 ; V_64 ++ ) {
int V_48 = F_23 ( V_3 , V_64 ) ;
F_46 ( V_48 , & V_60 ) ;
F_47 ( V_48 , & V_61 ,
V_62 ) ;
#ifdef F_48
F_49 ( V_48 , V_63 ) ;
#else
F_50 ( V_48 ) ;
#endif
}
for ( V_64 = 0 ; V_64 < V_13 -> V_65 ; V_64 ++ ) {
V_53 = & V_13 -> V_80 [ V_64 ] ;
F_65 ( V_53 -> V_48 , F_36 ) ;
F_66 ( V_53 -> V_48 , V_53 ) ;
}
F_67 ( & V_13 -> V_18 ) ;
return 0 ;
V_83:
F_68 ( V_13 -> V_25 ) ;
return V_58 ;
}
