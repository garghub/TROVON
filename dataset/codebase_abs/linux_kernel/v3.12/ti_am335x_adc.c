static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_6 )
{
F_4 ( V_6 , V_2 -> V_4 -> V_5 + V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_7 )
{
T_1 V_8 ;
V_8 = ( ( 1 << V_7 -> V_9 ) - 1 ) ;
V_8 <<= V_10 - V_7 -> V_9 + 1 ;
return V_8 ;
}
static void F_6 ( struct V_1 * V_7 )
{
unsigned int V_11 ;
int V_12 , V_13 ;
V_13 = V_10 - V_7 -> V_9 ;
V_11 = V_14 | V_15 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_9 ; V_12 ++ ) {
int V_16 ;
V_16 = V_7 -> V_17 [ V_12 ] ;
F_3 ( V_7 , F_7 ( V_13 ) ,
V_11 | F_8 ( V_16 ) ) ;
F_3 ( V_7 , F_9 ( V_13 ) ,
V_18 ) ;
V_7 -> V_19 [ V_12 ] = V_13 ;
V_13 ++ ;
}
}
static int F_10 ( struct V_20 * V_21 , int V_9 )
{
struct V_1 * V_7 = F_11 ( V_21 ) ;
struct V_22 * V_23 ;
struct V_22 * V_16 ;
int V_12 ;
V_21 -> V_24 = V_9 ;
V_23 = F_12 ( V_9 ,
sizeof( struct V_22 ) , V_25 ) ;
if ( V_23 == NULL )
return - V_26 ;
V_16 = V_23 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ , V_16 ++ ) {
V_16 -> type = V_27 ;
V_16 -> V_28 = 1 ;
V_16 -> V_29 = V_7 -> V_17 [ V_12 ] ;
V_16 -> V_30 = F_13 ( V_31 ) ;
V_16 -> V_32 = V_33 [ V_16 -> V_29 ] ;
V_16 -> V_34 . V_35 = 'u' ;
V_16 -> V_34 . V_36 = 12 ;
V_16 -> V_34 . V_37 = 32 ;
}
V_21 -> V_9 = V_23 ;
return 0 ;
}
static void F_14 ( struct V_20 * V_21 )
{
F_15 ( V_21 -> V_9 ) ;
}
static int F_16 ( struct V_20 * V_21 ,
struct V_22 const * V_16 ,
int * V_6 , int * V_38 , long V_39 )
{
struct V_1 * V_7 = F_11 ( V_21 ) ;
int V_12 , V_40 ;
unsigned int V_41 , V_42 , V_43 ;
T_1 V_44 = V_45 ;
bool V_46 = false ;
T_1 V_8 ;
unsigned long V_47 = V_48 + F_17
( V_49 * V_7 -> V_9 ) ;
V_8 = F_5 ( V_7 ) ;
F_18 ( V_7 -> V_4 , V_8 ) ;
while ( F_1 ( V_7 , V_50 ) & V_51 ) {
if ( F_19 ( V_48 , V_47 ) )
return - V_52 ;
}
V_40 = V_16 -> V_29 + V_53 ;
for ( V_12 = 0 ; V_12 < F_20 ( V_7 -> V_19 ) ; V_12 ++ ) {
if ( V_16 -> V_29 == V_7 -> V_17 [ V_12 ] ) {
V_44 = V_7 -> V_19 [ V_12 ] ;
break;
}
}
if ( F_21 ( V_44 == V_45 ) )
return - V_54 ;
V_41 = F_1 ( V_7 , V_55 ) ;
for ( V_12 = 0 ; V_12 < V_41 ; V_12 ++ ) {
V_42 = F_1 ( V_7 , V_56 ) ;
V_43 = V_42 & V_57 ;
V_43 = V_43 >> 0x10 ;
if ( V_43 == V_40 ) {
V_42 = V_42 & V_58 ;
V_46 = true ;
* V_6 = V_42 ;
}
}
if ( V_46 == false )
return - V_59 ;
return V_60 ;
}
static int F_22 ( struct V_61 * V_62 )
{
struct V_20 * V_21 ;
struct V_1 * V_7 ;
struct V_63 * V_64 = V_62 -> V_65 . V_66 ;
struct V_67 * V_68 ;
const T_2 * V_69 ;
int V_70 ;
T_1 V_6 ;
int V_9 = 0 ;
if ( ! V_64 ) {
F_23 ( & V_62 -> V_65 , L_1 ) ;
return - V_54 ;
}
V_21 = F_24 ( & V_62 -> V_65 ,
sizeof( struct V_1 ) ) ;
if ( V_21 == NULL ) {
F_23 ( & V_62 -> V_65 , L_2 ) ;
return - V_26 ;
}
V_7 = F_11 ( V_21 ) ;
V_7 -> V_4 = F_25 ( V_62 ) ;
F_26 (node, L_3 , prop, cur, val) {
V_7 -> V_17 [ V_9 ] = V_6 ;
V_9 ++ ;
}
V_7 -> V_9 = V_9 ;
V_21 -> V_65 . V_71 = & V_62 -> V_65 ;
V_21 -> V_72 = F_27 ( & V_62 -> V_65 ) ;
V_21 -> V_73 = V_74 ;
V_21 -> V_75 = & V_76 ;
F_6 ( V_7 ) ;
V_70 = F_10 ( V_21 , V_7 -> V_9 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_28 ( V_21 ) ;
if ( V_70 )
goto V_77;
F_29 ( V_62 , V_21 ) ;
return 0 ;
V_77:
F_14 ( V_21 ) ;
return V_70 ;
}
static int F_30 ( struct V_61 * V_62 )
{
struct V_20 * V_21 = F_31 ( V_62 ) ;
struct V_1 * V_7 = F_11 ( V_21 ) ;
T_1 V_8 ;
F_32 ( V_21 ) ;
F_14 ( V_21 ) ;
V_8 = F_5 ( V_7 ) ;
F_33 ( V_7 -> V_4 , V_8 ) ;
return 0 ;
}
static int F_34 ( struct V_78 * V_65 )
{
struct V_20 * V_21 = F_35 ( V_65 ) ;
struct V_1 * V_7 = F_11 ( V_21 ) ;
struct V_79 * V_80 ;
unsigned int V_81 ;
V_80 = F_25 ( F_36 ( V_65 ) ) ;
if ( ! F_37 ( V_80 -> V_65 ) ) {
V_81 = F_1 ( V_7 , V_82 ) ;
V_81 &= ~ ( V_83 ) ;
F_3 ( V_7 , V_82 , ( V_81 |
V_84 ) ) ;
}
return 0 ;
}
static int F_38 ( struct V_78 * V_65 )
{
struct V_20 * V_21 = F_35 ( V_65 ) ;
struct V_1 * V_7 = F_11 ( V_21 ) ;
unsigned int V_85 ;
V_85 = F_1 ( V_7 , V_82 ) ;
V_85 &= ~ ( V_84 ) ;
F_3 ( V_7 , V_82 , V_85 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
