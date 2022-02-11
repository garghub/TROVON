static int F_1 ( struct V_1 * V_1 , unsigned V_2 , T_1 * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_1 -> V_5 , V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_1 -> V_6 . V_7 , L_1 ,
L_2 , V_4 ) ;
return V_4 ;
}
* V_3 = V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , unsigned V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_5 ( V_1 -> V_5 , V_2 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( V_1 -> V_6 . V_7 , L_1 ,
L_3 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_6 ( struct V_8 * V_9 , unsigned V_2 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
unsigned int V_10 = V_2 >> V_1 -> V_11 ;
unsigned int V_12 = V_2 & 7 ;
T_2 V_3 ;
int V_4 ;
V_4 = F_1 ( V_1 , F_8 ( V_1 ) + V_10 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return ( V_3 & F_9 ( V_12 ) ) ? 1 : 0 ;
}
static void F_10 ( struct V_1 * V_1 , unsigned V_2 , int V_3 )
{
unsigned int V_10 = V_2 >> V_1 -> V_11 ;
unsigned int V_12 = V_2 & 7 ;
int V_4 ;
T_2 V_13 ;
V_4 = F_1 ( V_1 , F_8 ( V_1 ) + V_10 , & V_13 ) ;
if ( V_4 < 0 )
return;
if ( V_3 )
V_13 |= F_9 ( V_12 ) ;
else
V_13 &= ~ F_9 ( V_12 ) ;
F_4 ( V_1 , F_8 ( V_1 ) + V_10 , V_13 ) ;
}
static void F_11 ( struct V_8 * V_9 , unsigned V_2 , int V_3 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
F_12 ( & V_1 -> V_14 ) ;
F_10 ( V_1 , V_2 , V_3 ) ;
F_13 ( & V_1 -> V_14 ) ;
}
static int F_14 ( struct V_8 * V_9 , unsigned V_2 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
unsigned int V_10 = V_2 >> V_1 -> V_11 ;
unsigned int V_12 = V_2 & 7 ;
T_2 V_3 ;
int V_4 ;
F_12 ( & V_1 -> V_14 ) ;
V_4 = F_1 ( V_1 , F_15 ( V_1 ) + V_10 , & V_3 ) ;
if ( V_4 < 0 )
goto V_15;
V_3 &= ~ F_9 ( V_12 ) ;
V_4 = F_4 ( V_1 , F_15 ( V_1 ) + V_10 , V_3 ) ;
if ( V_4 < 0 )
goto V_15;
V_4 = F_1 ( V_1 , F_15 ( V_1 ) + V_10 , & V_3 ) ;
if ( V_4 < 0 )
goto V_15;
if ( V_4 & F_9 ( V_12 ) )
V_4 = - V_16 ;
V_4 = 0 ;
V_15:
F_13 ( & V_1 -> V_14 ) ;
return V_4 ;
}
static int F_16 ( struct V_8 * V_9 , unsigned V_2 ,
int V_3 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
unsigned int V_10 = V_2 >> V_1 -> V_11 ;
unsigned int V_12 = V_2 & 7 ;
int V_4 ;
T_2 V_13 ;
F_12 ( & V_1 -> V_14 ) ;
V_4 = F_1 ( V_1 , F_15 ( V_1 ) + V_10 , & V_13 ) ;
if ( V_4 < 0 )
goto V_15;
V_13 |= F_9 ( V_12 ) ;
V_4 = F_4 ( V_1 , F_15 ( V_1 ) + V_10 , V_13 ) ;
if ( V_4 < 0 )
goto V_15;
V_4 = F_1 ( V_1 , F_15 ( V_1 ) + V_10 , & V_13 ) ;
if ( V_4 < 0 )
goto V_15;
if ( ! ( V_13 & F_9 ( V_12 ) ) ) {
V_4 = - V_17 ;
goto V_15;
}
F_10 ( V_1 , V_2 , V_3 ) ;
V_4 = 0 ;
V_15:
F_13 ( & V_1 -> V_14 ) ;
return V_4 ;
}
static void F_17 ( struct V_18 * V_19 , struct V_8 * V_9 )
{
struct V_1 * V_1 = F_7 ( V_9 ) ;
unsigned int V_20 = 1 << V_1 -> V_11 , V_21 , V_22 ;
int V_4 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
T_2 V_23 , V_24 , V_25 , V_26 ;
F_12 ( & V_1 -> V_14 ) ;
V_4 = F_1 ( V_1 , F_15 ( V_1 ) + V_21 , & V_23 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_1 -> V_14 ) ;
return;
}
V_4 = F_1 ( V_1 , F_8 ( V_1 ) + V_21 , & V_24 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_1 -> V_14 ) ;
return;
}
V_4 = F_1 ( V_1 , F_18 ( V_1 ) + V_21 , & V_25 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_1 -> V_14 ) ;
return;
}
V_4 = F_1 ( V_1 , F_19 ( V_1 ) + V_21 , & V_26 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_1 -> V_14 ) ;
return;
}
F_13 ( & V_1 -> V_14 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
unsigned int V_27 = ( V_21 << V_1 -> V_11 ) + V_22 ;
const char * V_28 = L_4 ;
const char * V_29 = L_5 ;
const char * V_30 = L_6 ;
const char * V_31 = L_7 ;
if ( V_23 & F_9 ( V_22 ) )
V_28 = L_8 ;
if ( V_24 & F_9 ( V_22 ) )
V_29 = L_9 ;
if ( V_25 & F_9 ( V_22 ) )
V_30 = L_10 ;
if ( V_26 & F_9 ( V_22 ) )
V_31 = L_11 ;
F_20 ( V_19 , L_12 , V_27 ,
V_28 , V_29 , V_30 , V_31 ) ;
}
}
}
static int F_21 ( struct V_1 * V_1 , unsigned int V_32 )
{
struct V_8 * V_9 = & V_1 -> V_6 ;
int V_4 ;
V_1 -> V_11 = F_22 ( V_32 ) - 3 ;
V_9 -> V_33 = F_14 ;
V_9 -> V_34 = F_16 ;
V_9 -> V_35 = F_6 ;
V_9 -> V_36 = F_11 ;
V_9 -> V_37 = true ;
if ( F_23 ( V_38 ) )
V_9 -> V_39 = F_17 ;
V_9 -> V_40 = - 1 ;
V_9 -> V_41 = V_32 ;
V_9 -> V_42 = V_1 -> V_5 -> V_43 ;
V_9 -> V_7 = & V_1 -> V_5 -> V_44 ;
V_9 -> V_45 = V_9 -> V_7 -> V_45 ;
V_9 -> V_46 = V_47 ;
V_4 = F_24 ( V_9 , V_1 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static T_3 F_25 ( int V_48 , void * V_49 )
{
struct V_1 * V_1 = V_49 ;
unsigned int V_20 , V_21 ;
V_20 = 1 << V_1 -> V_11 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
unsigned int V_40 = V_21 << V_1 -> V_11 , V_27 ;
T_2 V_50 , V_29 , V_26 , V_25 ;
unsigned long V_31 ;
int V_4 ;
F_12 ( & V_1 -> V_14 ) ;
V_4 = F_1 ( V_1 , F_8 ( V_1 ) + V_21 , & V_29 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_1 -> V_14 ) ;
continue;
}
V_4 = F_1 ( V_1 , F_19 ( V_1 ) + V_21 , & V_26 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_1 -> V_14 ) ;
continue;
}
V_4 = F_1 ( V_1 , F_18 ( V_1 ) + V_21 , & V_25 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_1 -> V_14 ) ;
continue;
}
F_13 ( & V_1 -> V_14 ) ;
V_50 = V_29 ^ V_1 -> V_51 [ V_21 ] ;
V_31 = V_50 & ( ( V_1 -> V_52 [ V_21 ] & ~ V_29 ) |
( V_1 -> V_53 [ V_21 ] & V_29 ) ) ;
V_31 |= ( V_1 -> V_54 [ V_21 ] & V_29 ) |
( V_1 -> V_55 [ V_21 ] & ~ V_29 ) ;
V_31 &= V_26 & V_25 ;
F_26 (bit, &pending, 8 ) {
unsigned int V_56 ;
V_56 = F_27 ( V_1 -> V_6 . V_57 ,
V_40 + V_27 ) ;
F_28 ( V_56 ) ;
}
}
return V_58 ;
}
static void F_29 ( struct V_59 * V_60 )
{
struct V_8 * V_61 = F_30 ( V_60 ) ;
struct V_1 * V_1 = F_7 ( V_61 ) ;
unsigned int V_10 = V_60 -> V_62 >> V_1 -> V_11 ;
unsigned int V_12 = V_60 -> V_62 & 7 ;
V_1 -> V_63 [ V_10 ] &= ~ F_9 ( V_12 ) ;
}
static void F_31 ( struct V_59 * V_60 )
{
struct V_8 * V_61 = F_30 ( V_60 ) ;
struct V_1 * V_1 = F_7 ( V_61 ) ;
unsigned int V_10 = V_60 -> V_62 >> V_1 -> V_11 ;
unsigned int V_12 = V_60 -> V_62 & 7 ;
V_1 -> V_63 [ V_10 ] |= F_9 ( V_12 ) ;
}
static int F_32 ( struct V_59 * V_60 , unsigned int type )
{
struct V_8 * V_61 = F_30 ( V_60 ) ;
struct V_1 * V_1 = F_7 ( V_61 ) ;
unsigned int V_10 = V_60 -> V_62 >> V_1 -> V_11 ;
unsigned int V_12 = V_60 -> V_62 & 7 ;
if ( type & V_64 )
V_1 -> V_53 [ V_10 ] |= F_9 ( V_12 ) ;
else
V_1 -> V_53 [ V_10 ] &= ~ F_9 ( V_12 ) ;
if ( type & V_65 )
V_1 -> V_52 [ V_10 ] |= F_9 ( V_12 ) ;
else
V_1 -> V_52 [ V_10 ] &= ~ F_9 ( V_12 ) ;
if ( type & V_66 )
V_1 -> V_54 [ V_10 ] |= F_9 ( V_12 ) ;
else
V_1 -> V_54 [ V_10 ] &= ~ F_9 ( V_12 ) ;
if ( type & V_67 )
V_1 -> V_55 [ V_10 ] |= F_9 ( V_12 ) ;
else
V_1 -> V_55 [ V_10 ] &= ~ F_9 ( V_12 ) ;
return 0 ;
}
static void F_33 ( struct V_59 * V_60 )
{
struct V_8 * V_61 = F_30 ( V_60 ) ;
struct V_1 * V_1 = F_7 ( V_61 ) ;
F_12 ( & V_1 -> V_68 ) ;
}
static void F_34 ( struct V_59 * V_60 )
{
struct V_8 * V_61 = F_30 ( V_60 ) ;
struct V_1 * V_1 = F_7 ( V_61 ) ;
unsigned int V_20 = 1 << V_1 -> V_11 , V_21 ;
F_12 ( & V_1 -> V_14 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ )
F_4 ( V_1 , F_18 ( V_1 ) + V_21 , V_1 -> V_63 [ V_21 ] ) ;
F_13 ( & V_1 -> V_14 ) ;
F_13 ( & V_1 -> V_68 ) ;
}
static int F_35 ( struct V_1 * V_1 )
{
unsigned int V_20 = 1 << V_1 -> V_11 , V_21 ;
struct V_8 * V_9 = & V_1 -> V_6 ;
int V_4 ;
F_36 ( & V_1 -> V_68 ) ;
V_1 -> V_63 = F_37 ( V_9 -> V_7 , V_20 * 6 ,
V_69 ) ;
if ( ! V_1 -> V_63 )
return - V_70 ;
V_1 -> V_51 = V_1 -> V_63 + ( V_20 * 1 ) ;
V_1 -> V_53 = V_1 -> V_63 + ( V_20 * 2 ) ;
V_1 -> V_52 = V_1 -> V_63 + ( V_20 * 3 ) ;
V_1 -> V_54 = V_1 -> V_63 + ( V_20 * 4 ) ;
V_1 -> V_55 = V_1 -> V_63 + ( V_20 * 5 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_4 = F_1 ( V_1 , F_8 ( V_1 ) + V_21 , & V_1 -> V_51 [ V_21 ] ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_1 , F_18 ( V_1 ) + V_21 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_1 -> V_63 [ V_21 ] = 0x00 ;
}
V_4 = F_38 ( V_9 -> V_7 , V_1 -> V_5 -> V_48 ,
NULL , F_25 ,
V_71 | V_72 ,
F_39 ( V_9 -> V_7 ) , V_1 ) ;
if ( V_4 != 0 ) {
F_3 ( V_9 -> V_7 , L_13 ,
V_1 -> V_5 -> V_48 , V_4 ) ;
return V_4 ;
}
V_4 = F_40 ( V_9 ,
& V_73 ,
0 ,
V_74 ,
V_75 ) ;
if ( V_4 ) {
F_3 ( V_9 -> V_7 ,
L_14 ) ;
return V_4 ;
}
return 0 ;
}
static int F_41 ( struct V_76 * V_5 ,
const struct V_77 * V_78 )
{
struct V_79 * V_80 = V_5 -> V_44 . V_45 ;
struct V_1 * V_1 ;
T_4 V_32 ;
int V_4 ;
V_4 = F_42 ( V_80 , L_15 , & V_32 ) ;
if ( V_4 < 0 )
return V_4 ;
V_5 -> V_48 = F_43 ( V_80 , 0 ) ;
if ( ! V_5 -> V_48 )
return - V_81 ;
V_1 = F_37 ( & V_5 -> V_44 , sizeof( * V_1 ) , V_69 ) ;
if ( ! V_1 )
return - V_70 ;
F_36 ( & V_1 -> V_14 ) ;
V_1 -> V_5 = V_5 ;
V_4 = F_21 ( V_1 , V_32 ) ;
if ( V_4 )
return V_4 ;
if ( F_44 ( V_80 , L_16 , NULL ) ) {
V_4 = F_35 ( V_1 ) ;
if ( V_4 )
return V_4 ;
}
F_45 ( V_5 , V_1 ) ;
return 0 ;
}
static int F_46 ( struct V_76 * V_5 )
{
struct V_1 * V_1 = F_47 ( V_5 ) ;
F_48 ( & V_1 -> V_6 ) ;
return 0 ;
}
