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
static int F_30 ( struct V_12 * V_13 , unsigned V_8 ,
unsigned long V_33 )
{
T_2 V_26 ;
if ( F_31 ( V_33 ) != V_34 )
return - V_35 ;
V_26 = F_32 ( V_33 ) ;
return F_27 ( V_13 , V_8 , V_26 ) ;
}
static void F_33 ( struct V_36 * V_37 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
unsigned V_8 = V_37 -> V_38 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_34 ( V_37 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_35 ( V_2 ) ) ;
V_9 |= F_8 ( V_18 ) ;
F_2 ( V_9 , V_1 + F_35 ( V_2 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static void F_36 ( struct V_36 * V_37 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
unsigned V_8 = V_37 -> V_38 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_34 ( V_37 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_37 ( V_2 ) ) ;
V_9 |= F_8 ( V_18 ) ;
F_2 ( V_9 , V_1 + F_37 ( V_2 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static void F_38 ( struct V_36 * V_37 )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
unsigned V_8 = V_37 -> V_38 ;
int V_2 = F_5 ( V_8 ) ;
int V_18 = F_15 ( V_8 ) ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_34 ( V_37 ) ;
V_1 = V_7 -> V_1 ;
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_39 ( V_2 ) ) ;
V_9 |= F_8 ( V_18 ) ;
F_2 ( V_9 , V_1 + F_39 ( V_2 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
}
static int F_40 ( struct V_36 * V_37 , unsigned int type )
{
struct V_6 * V_7 ;
void T_1 * V_1 ;
unsigned V_8 = V_37 -> V_38 ;
T_2 V_39 ;
T_2 V_9 ;
unsigned long V_10 ;
V_7 = F_34 ( V_37 ) ;
V_1 = V_7 -> V_1 ;
switch ( type & V_40 ) {
case V_41 :
V_39 = V_42 ;
break;
case V_43 :
V_39 = V_44 ;
break;
case V_45 :
V_39 = V_46 ;
break;
case V_47 :
case V_48 :
default:
F_28 ( V_7 -> V_12 . V_28 ,
L_2 , type ) ;
return - V_29 ;
}
F_6 ( & V_7 -> V_11 , V_10 ) ;
V_9 = F_7 ( V_1 + F_13 ( V_8 ) ) ;
V_9 &= ~ V_49 ;
V_9 |= V_39 << V_50 ;
F_2 ( V_9 , V_1 + F_13 ( V_8 ) ) ;
F_9 ( & V_7 -> V_11 , V_10 ) ;
return 0 ;
}
static void F_41 ( struct V_51 * V_52 )
{
void T_1 * V_1 ;
int V_18 , V_2 ;
unsigned long V_53 ;
struct V_54 * V_55 = F_42 ( V_52 ) ;
struct V_56 * V_13 = F_43 ( V_52 ) ;
F_44 ( V_13 , V_52 ) ;
V_1 = V_55 -> V_7 -> V_1 ;
V_2 = V_55 -> V_57 ;
while ( ( V_53 = F_7 ( V_1 + F_35 ( V_2 ) ) &
( ~ ( F_7 ( V_1 + F_37 ( V_2 ) ) ) ) ) ) {
F_45 (bit, &sta, 32 ) {
int V_38 = V_58 * V_2 + V_18 ;
int V_59 =
F_46 ( V_55 -> V_7 -> V_25 ,
V_38 ) ;
F_2 ( F_7 ( V_1 + F_35 ( V_2 ) ) |
F_8 ( V_18 ) , V_1 + F_35 ( V_2 ) ) ;
F_47 ( V_59 ) ;
}
}
F_48 ( V_13 , V_52 ) ;
}
static int F_49 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_34 ( V_37 ) ;
if ( F_50 ( & V_7 -> V_12 , V_37 -> V_38 ) ) {
F_28 ( V_7 -> V_12 . V_28 ,
L_3 ,
V_37 -> V_38 ) ;
return - V_29 ;
}
return 0 ;
}
static void F_51 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_34 ( V_37 ) ;
F_52 ( & V_7 -> V_12 , V_37 -> V_38 ) ;
}
static int F_53 ( struct V_25 * V_37 , unsigned int V_60 ,
T_3 V_38 )
{
int V_61 ;
V_61 = F_54 ( V_60 , V_37 -> V_62 ) ;
if ( V_61 < 0 )
return V_61 ;
F_55 ( V_60 , & V_63 ) ;
F_56 ( V_60 , & V_64 , V_65 ) ;
F_57 ( V_60 ) ;
return 0 ;
}
static void F_58 ( struct V_25 * V_37 , unsigned int V_60 )
{
F_56 ( V_60 , NULL , NULL ) ;
F_54 ( V_60 , NULL ) ;
}
static void F_59 ( struct V_6 * V_7 )
{
void T_1 * V_1 ;
int V_66 ;
V_1 = V_7 -> V_1 ;
for ( V_66 = 0 ; V_66 < V_7 -> V_67 ; V_66 ++ ) {
F_1 ( V_1 , V_66 , V_68 ) ;
F_2 ( 0xffffffff , V_1 + F_37 ( V_66 ) ) ;
F_2 ( 0xffffffff , V_1 + F_35 ( V_66 ) ) ;
F_1 ( V_1 , V_66 , V_69 ) ;
}
}
static int F_60 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = & V_71 -> V_73 ;
const struct V_74 * V_75 ;
struct V_76 * V_27 ;
struct V_54 * V_55 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
int V_61 ;
int V_66 ;
V_75 = F_61 ( V_77 , V_73 ) ;
if ( ! V_75 ) {
F_28 ( V_73 , L_4 ) ;
return - V_78 ;
}
V_7 = F_62 ( V_73 , sizeof( * V_7 ) , V_79 ) ;
if ( ! V_7 )
return - V_80 ;
V_7 -> V_12 = V_81 ;
V_13 = & V_7 -> V_12 ;
V_7 -> V_67 = F_63 ( V_73 -> V_82 ) ;
if ( V_7 -> V_67 == 0 ) {
F_28 ( V_73 , L_5 ) ;
return - V_83 ;
}
if ( V_7 -> V_67 > V_84 ) {
F_28 ( V_73 , L_6 ,
V_84 ) ;
return - V_24 ;
}
V_7 -> V_85 = F_62 ( V_73 ,
V_7 -> V_67 *
sizeof( * V_7 -> V_85 ) , V_79 ) ;
if ( ! V_7 -> V_85 )
return - V_80 ;
V_7 -> V_71 = V_71 ;
F_64 ( V_71 , V_7 ) ;
V_13 -> V_82 = V_73 -> V_82 ;
V_13 -> V_23 = V_7 -> V_67 * V_58 ;
V_7 -> V_25 = F_65 ( V_73 -> V_82 ,
V_13 -> V_23 ,
& V_86 ,
V_7 ) ;
if ( ! V_7 -> V_25 ) {
F_28 ( V_73 , L_7 ) ;
return - V_24 ;
}
V_27 = F_66 ( V_71 , V_87 , 0 ) ;
V_7 -> V_1 = F_67 ( V_73 , V_27 ) ;
if ( F_68 ( V_7 -> V_1 ) ) {
V_61 = - V_24 ;
goto V_88;
}
for ( V_66 = 0 ; V_66 < V_7 -> V_67 ; V_66 ++ ) {
V_55 = & V_7 -> V_85 [ V_66 ] ;
V_55 -> V_57 = V_66 ;
V_55 -> V_60 = F_69 ( V_71 , V_66 ) ;
V_55 -> V_7 = V_7 ;
if ( V_55 -> V_60 < 0 ) {
F_28 ( V_73 , L_8 , V_66 ) ;
V_61 = - V_83 ;
goto V_88;
}
}
F_70 ( & V_71 -> V_73 , L_9 ) ;
F_59 ( V_7 ) ;
V_61 = F_71 ( V_73 , V_13 , V_7 ) ;
if ( V_61 < 0 ) {
F_28 ( V_73 , L_10 , V_61 ) ;
goto V_88;
}
for ( V_66 = 0 ; V_66 < V_7 -> V_67 ; V_66 ++ ) {
V_55 = & V_7 -> V_85 [ V_66 ] ;
F_72 ( V_55 -> V_60 ,
F_41 ,
V_55 ) ;
}
F_73 ( & V_7 -> V_11 ) ;
return 0 ;
V_88:
F_74 ( V_7 -> V_25 ) ;
return V_61 ;
}
