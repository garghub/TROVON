static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_1 , unsigned V_5 , T_1 * V_6 )
{
int V_7 ;
V_7 = F_4 ( V_1 -> V_8 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_1 -> V_4 . V_9 , L_1 ,
L_2 , V_7 ) ;
return V_7 ;
}
* V_6 = V_7 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , unsigned V_5 , T_1 V_6 )
{
int V_7 ;
V_7 = F_7 ( V_1 -> V_8 , V_5 , V_6 ) ;
if ( V_7 < 0 ) {
F_5 ( V_1 -> V_4 . V_9 , L_1 ,
L_3 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_10 = V_5 >> V_1 -> V_11 ;
unsigned int V_12 = V_5 & 7 ;
T_2 V_6 ;
int V_7 ;
V_7 = F_3 ( V_1 , F_9 ( V_1 ) + V_10 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
return ( V_6 & F_10 ( V_12 ) ) ? 1 : 0 ;
}
static void F_11 ( struct V_1 * V_1 , unsigned V_5 , int V_6 )
{
unsigned int V_10 = V_5 >> V_1 -> V_11 ;
unsigned int V_12 = V_5 & 7 ;
int V_7 ;
T_2 V_13 ;
V_7 = F_3 ( V_1 , F_9 ( V_1 ) + V_10 , & V_13 ) ;
if ( V_7 < 0 )
return;
if ( V_6 )
V_13 |= F_10 ( V_12 ) ;
else
V_13 &= ~ F_10 ( V_12 ) ;
F_6 ( V_1 , F_9 ( V_1 ) + V_10 , V_13 ) ;
}
static void F_12 ( struct V_2 * V_3 , unsigned V_5 , int V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( & V_1 -> V_14 ) ;
F_11 ( V_1 , V_5 , V_6 ) ;
F_14 ( & V_1 -> V_14 ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_10 = V_5 >> V_1 -> V_11 ;
unsigned int V_12 = V_5 & 7 ;
T_2 V_6 ;
int V_7 ;
F_13 ( & V_1 -> V_14 ) ;
V_7 = F_3 ( V_1 , F_16 ( V_1 ) + V_10 , & V_6 ) ;
if ( V_7 < 0 )
goto V_15;
V_6 &= ~ F_10 ( V_12 ) ;
V_7 = F_6 ( V_1 , F_16 ( V_1 ) + V_10 , V_6 ) ;
if ( V_7 < 0 )
goto V_15;
V_7 = F_3 ( V_1 , F_16 ( V_1 ) + V_10 , & V_6 ) ;
if ( V_7 < 0 )
goto V_15;
if ( V_7 & F_10 ( V_12 ) )
V_7 = - V_16 ;
V_7 = 0 ;
V_15:
F_14 ( & V_1 -> V_14 ) ;
return V_7 ;
}
static int F_17 ( struct V_2 * V_3 , unsigned V_5 ,
int V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_10 = V_5 >> V_1 -> V_11 ;
unsigned int V_12 = V_5 & 7 ;
int V_7 ;
T_2 V_13 ;
F_13 ( & V_1 -> V_14 ) ;
V_7 = F_3 ( V_1 , F_16 ( V_1 ) + V_10 , & V_13 ) ;
if ( V_7 < 0 )
goto V_15;
V_13 |= F_10 ( V_12 ) ;
V_7 = F_6 ( V_1 , F_16 ( V_1 ) + V_10 , V_13 ) ;
if ( V_7 < 0 )
goto V_15;
V_7 = F_3 ( V_1 , F_16 ( V_1 ) + V_10 , & V_13 ) ;
if ( V_7 < 0 )
goto V_15;
if ( ! ( V_13 & F_10 ( V_12 ) ) ) {
V_7 = - V_17 ;
goto V_15;
}
F_11 ( V_1 , V_5 , V_6 ) ;
V_7 = 0 ;
V_15:
F_14 ( & V_1 -> V_14 ) ;
return V_7 ;
}
static void F_18 ( struct V_18 * V_19 , struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_20 = 1 << V_1 -> V_11 , V_21 , V_22 ;
int V_7 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
T_2 V_23 , V_24 , V_25 , V_26 ;
F_13 ( & V_1 -> V_14 ) ;
V_7 = F_3 ( V_1 , F_16 ( V_1 ) + V_21 , & V_23 ) ;
if ( V_7 < 0 ) {
F_14 ( & V_1 -> V_14 ) ;
return;
}
V_7 = F_3 ( V_1 , F_9 ( V_1 ) + V_21 , & V_24 ) ;
if ( V_7 < 0 ) {
F_14 ( & V_1 -> V_14 ) ;
return;
}
V_7 = F_3 ( V_1 , F_19 ( V_1 ) + V_21 , & V_25 ) ;
if ( V_7 < 0 ) {
F_14 ( & V_1 -> V_14 ) ;
return;
}
V_7 = F_3 ( V_1 , F_20 ( V_1 ) + V_21 , & V_26 ) ;
if ( V_7 < 0 ) {
F_14 ( & V_1 -> V_14 ) ;
return;
}
F_14 ( & V_1 -> V_14 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
unsigned int V_27 = ( V_21 << V_1 -> V_11 ) + V_22 ;
const char * V_28 = L_4 ;
const char * V_29 = L_5 ;
const char * V_30 = L_6 ;
const char * V_31 = L_7 ;
if ( V_23 & F_10 ( V_22 ) )
V_28 = L_8 ;
if ( V_24 & F_10 ( V_22 ) )
V_29 = L_9 ;
if ( V_25 & F_10 ( V_22 ) )
V_30 = L_10 ;
if ( V_26 & F_10 ( V_22 ) )
V_31 = L_11 ;
F_21 ( V_19 , L_12 , V_27 ,
V_28 , V_29 , V_30 , V_31 ) ;
}
}
}
static int F_22 ( struct V_1 * V_1 , unsigned int V_32 )
{
struct V_2 * V_3 = & V_1 -> V_4 ;
V_1 -> V_11 = F_23 ( V_32 ) - 3 ;
V_3 -> V_33 = F_15 ;
V_3 -> V_34 = F_17 ;
V_3 -> V_35 = F_8 ;
V_3 -> V_36 = F_12 ;
V_3 -> V_37 = true ;
if ( F_24 ( V_38 ) )
V_3 -> V_39 = F_18 ;
V_3 -> V_40 = - 1 ;
V_3 -> V_41 = V_32 ;
V_3 -> V_42 = V_1 -> V_8 -> V_43 ;
V_3 -> V_9 = & V_1 -> V_8 -> V_9 ;
V_3 -> V_44 = V_3 -> V_9 -> V_44 ;
V_3 -> V_45 = V_46 ;
return 0 ;
}
static T_3 F_25 ( int V_47 , void * V_48 )
{
struct V_1 * V_1 = V_48 ;
unsigned int V_20 , V_21 ;
V_20 = 1 << V_1 -> V_11 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
unsigned int V_40 = V_21 << V_1 -> V_11 , V_27 ;
T_2 V_49 , V_29 , V_26 , V_25 ;
unsigned long V_31 ;
int V_7 ;
F_13 ( & V_1 -> V_14 ) ;
V_7 = F_3 ( V_1 , F_9 ( V_1 ) + V_21 , & V_29 ) ;
if ( V_7 < 0 ) {
F_14 ( & V_1 -> V_14 ) ;
continue;
}
V_7 = F_3 ( V_1 , F_20 ( V_1 ) + V_21 , & V_26 ) ;
if ( V_7 < 0 ) {
F_14 ( & V_1 -> V_14 ) ;
continue;
}
V_7 = F_3 ( V_1 , F_19 ( V_1 ) + V_21 , & V_25 ) ;
if ( V_7 < 0 ) {
F_14 ( & V_1 -> V_14 ) ;
continue;
}
F_14 ( & V_1 -> V_14 ) ;
V_49 = V_29 ^ V_1 -> V_50 [ V_21 ] ;
V_31 = V_49 & ( ( V_1 -> V_51 [ V_21 ] & ~ V_29 ) |
( V_1 -> V_52 [ V_21 ] & V_29 ) ) ;
V_31 |= ( V_1 -> V_53 [ V_21 ] & V_29 ) |
( V_1 -> V_54 [ V_21 ] & ~ V_29 ) ;
V_31 &= V_26 & V_25 ;
F_26 (bit, &pending, 8 ) {
unsigned int V_55 ;
V_55 = F_27 ( V_1 -> V_56 , V_40 + V_27 ) ;
F_28 ( V_55 ) ;
}
}
return V_57 ;
}
static int F_29 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_30 ( V_1 -> V_56 , V_5 ) ;
}
static void F_31 ( struct V_58 * V_48 )
{
struct V_1 * V_1 = F_32 ( V_48 ) ;
unsigned int V_10 = V_48 -> V_59 >> V_1 -> V_11 ;
unsigned int V_12 = V_48 -> V_59 & 7 ;
V_1 -> V_60 [ V_10 ] &= ~ F_10 ( V_12 ) ;
}
static void F_33 ( struct V_58 * V_48 )
{
struct V_1 * V_1 = F_32 ( V_48 ) ;
unsigned int V_10 = V_48 -> V_59 >> V_1 -> V_11 ;
unsigned int V_12 = V_48 -> V_59 & 7 ;
V_1 -> V_60 [ V_10 ] |= F_10 ( V_12 ) ;
}
static int F_34 ( struct V_58 * V_48 , unsigned int type )
{
struct V_1 * V_1 = F_32 ( V_48 ) ;
unsigned int V_10 = V_48 -> V_59 >> V_1 -> V_11 ;
unsigned int V_12 = V_48 -> V_59 & 7 ;
if ( type & V_61 )
V_1 -> V_52 [ V_10 ] |= F_10 ( V_12 ) ;
else
V_1 -> V_52 [ V_10 ] &= ~ F_10 ( V_12 ) ;
if ( type & V_62 )
V_1 -> V_51 [ V_10 ] |= F_10 ( V_12 ) ;
else
V_1 -> V_51 [ V_10 ] &= ~ F_10 ( V_12 ) ;
if ( type & V_63 )
V_1 -> V_53 [ V_10 ] |= F_10 ( V_12 ) ;
else
V_1 -> V_53 [ V_10 ] &= ~ F_10 ( V_12 ) ;
if ( type & V_64 )
V_1 -> V_54 [ V_10 ] |= F_10 ( V_12 ) ;
else
V_1 -> V_54 [ V_10 ] &= ~ F_10 ( V_12 ) ;
return 0 ;
}
static void F_35 ( struct V_58 * V_48 )
{
struct V_1 * V_1 = F_32 ( V_48 ) ;
F_13 ( & V_1 -> V_65 ) ;
}
static void F_36 ( struct V_58 * V_48 )
{
struct V_1 * V_1 = F_32 ( V_48 ) ;
unsigned int V_20 = 1 << V_1 -> V_11 , V_21 ;
F_13 ( & V_1 -> V_14 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ )
F_6 ( V_1 , F_19 ( V_1 ) + V_21 , V_1 -> V_60 [ V_21 ] ) ;
F_14 ( & V_1 -> V_14 ) ;
F_14 ( & V_1 -> V_65 ) ;
}
static unsigned int F_37 ( struct V_58 * V_48 )
{
struct V_1 * V_1 = F_32 ( V_48 ) ;
if ( F_38 ( & V_1 -> V_4 , V_48 -> V_59 ) )
F_5 ( V_1 -> V_4 . V_9 ,
L_13 ,
V_48 -> V_59 ) ;
F_33 ( V_48 ) ;
return 0 ;
}
static void F_39 ( struct V_58 * V_48 )
{
struct V_1 * V_1 = F_32 ( V_48 ) ;
F_31 ( V_48 ) ;
F_40 ( & V_1 -> V_4 , V_48 -> V_59 ) ;
}
static int F_41 ( struct V_66 * V_56 , unsigned int V_47 ,
T_4 V_59 )
{
F_42 ( V_47 , V_56 -> V_67 ) ;
F_43 ( V_47 , & V_68 ) ;
F_44 ( V_47 , true ) ;
#ifdef F_45
F_46 ( V_47 , V_69 ) ;
#else
F_47 ( V_47 ) ;
#endif
return 0 ;
}
static int F_48 ( struct V_1 * V_1 )
{
unsigned int V_20 = 1 << V_1 -> V_11 , V_21 ;
struct V_2 * V_3 = & V_1 -> V_4 ;
int V_7 ;
F_49 ( & V_1 -> V_65 ) ;
V_1 -> V_60 = F_50 ( V_3 -> V_9 , V_20 * 6 , V_70 ) ;
if ( ! V_1 -> V_60 )
return - V_71 ;
V_1 -> V_50 = V_1 -> V_60 + ( V_20 * 1 ) ;
V_1 -> V_52 = V_1 -> V_60 + ( V_20 * 2 ) ;
V_1 -> V_51 = V_1 -> V_60 + ( V_20 * 3 ) ;
V_1 -> V_53 = V_1 -> V_60 + ( V_20 * 4 ) ;
V_1 -> V_54 = V_1 -> V_60 + ( V_20 * 5 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_7 = F_3 ( V_1 , F_9 ( V_1 ) + V_21 , & V_1 -> V_50 [ V_21 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_1 , F_19 ( V_1 ) + V_21 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_1 -> V_60 [ V_21 ] = 0x00 ;
}
V_1 -> V_56 = F_51 ( V_3 -> V_44 , V_3 -> V_41 ,
& V_72 , V_1 ) ;
V_7 = F_52 ( V_1 -> V_8 -> V_47 , NULL , F_25 ,
V_73 | V_74 ,
F_53 ( V_3 -> V_9 ) , V_1 ) ;
if ( V_7 != 0 ) {
F_5 ( V_3 -> V_9 , L_14 ,
V_1 -> V_8 -> V_47 , V_7 ) ;
return V_7 ;
}
V_3 -> V_75 = F_29 ;
return 0 ;
}
static void F_54 ( struct V_1 * V_1 )
{
unsigned int V_47 , V_21 ;
F_55 ( V_1 -> V_8 -> V_47 , V_1 ) ;
for ( V_21 = 0 ; V_21 < V_1 -> V_4 . V_41 ; V_21 ++ ) {
V_47 = F_27 ( V_1 -> V_56 , V_21 ) ;
if ( V_47 > 0 )
F_56 ( V_47 ) ;
}
F_57 ( V_1 -> V_56 ) ;
}
static int F_58 ( struct V_76 * V_8 ,
const struct V_77 * V_78 )
{
struct V_79 * V_80 = V_8 -> V_9 . V_44 ;
struct V_1 * V_1 ;
T_5 V_32 ;
int V_7 ;
V_7 = F_59 ( V_80 , L_15 , & V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 -> V_47 = F_60 ( V_80 , 0 ) ;
if ( ! V_8 -> V_47 )
return - V_81 ;
V_1 = F_50 ( & V_8 -> V_9 , sizeof( * V_1 ) , V_70 ) ;
if ( ! V_1 )
return - V_71 ;
F_49 ( & V_1 -> V_14 ) ;
V_1 -> V_8 = V_8 ;
V_7 = F_22 ( V_1 , V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_61 ( V_80 , L_16 , NULL ) ) {
V_7 = F_48 ( V_1 ) ;
if ( V_7 < 0 )
goto V_82;
}
V_7 = F_62 ( & V_1 -> V_4 ) ;
if ( V_7 < 0 )
goto V_82;
F_63 ( V_8 , V_1 ) ;
return 0 ;
V_82:
if ( F_61 ( V_80 , L_16 , NULL ) )
F_54 ( V_1 ) ;
return V_7 ;
}
static int F_64 ( struct V_76 * V_8 )
{
struct V_1 * V_1 = F_65 ( V_8 ) ;
struct V_79 * V_80 = V_8 -> V_9 . V_44 ;
int V_7 ;
V_7 = F_66 ( & V_1 -> V_4 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_8 -> V_9 , L_1 , L_17 ,
V_7 ) ;
return V_7 ;
}
if ( F_61 ( V_80 , L_16 , NULL ) )
F_54 ( V_1 ) ;
return 0 ;
}
