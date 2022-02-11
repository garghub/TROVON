static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_4 ( V_6 -> V_7 [ V_8 ] ) ;
}
static void F_5 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_6 ( V_6 -> V_7 [ V_8 ] ) ;
}
static int F_7 ( struct V_1 * V_6 ,
enum V_9 V_10 )
{
unsigned long V_11 , V_12 ;
unsigned long long V_13 ;
V_11 = F_8 ( V_6 -> V_7 [ V_8 ] ) ;
if ( ! V_11 )
return - V_14 ;
V_12 = F_8 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
if ( ! V_12 )
return - V_14 ;
switch ( V_10 ) {
case V_8 :
V_6 -> V_16 = 1 ;
break;
case V_17 :
V_13 = 2 * V_12 - 1 ;
F_9 ( V_13 , V_11 ) ;
V_6 -> V_16 = V_13 ;
break;
case V_18 :
V_13 = 4 * V_12 - 1 ;
F_9 ( V_13 , V_11 ) ;
V_6 -> V_16 = V_13 ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static unsigned long F_10 ( struct V_1 * V_6 ,
unsigned long V_19 )
{
unsigned long long V_20 , V_21 ;
V_20 = F_8 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
V_20 = V_20 * V_19 ;
F_9 ( V_20 , 1000000000UL ) ;
do {
V_21 = V_20 ;
F_9 ( V_21 , ( 1 << V_6 -> V_16 ) ) ;
if ( V_21 <= 0xFFFF )
return ( unsigned long ) V_21 ;
} while ( ++ V_6 -> V_16 < 8 );
return 0 ;
}
static unsigned long F_11 ( struct V_1 * V_6 ,
unsigned long V_19 ,
enum V_9 V_10 )
{
int V_22 ;
V_22 = F_7 ( V_6 , V_10 ) ;
if ( V_22 ) {
F_12 ( V_6 -> V_3 . V_23 ,
L_1 ,
V_22 ) ;
return 0 ;
}
return F_10 ( V_6 , V_19 ) ;
}
static unsigned long F_13 ( struct V_1 * V_6 ,
unsigned long V_19 )
{
enum V_9 V_24 , V_25 ;
unsigned long V_26 , V_27 , V_28 ;
V_28 = F_11 ( V_6 , V_19 ,
V_8 ) ;
if ( V_28 ) {
V_6 -> V_15 = V_8 ;
return V_28 ;
}
V_26 = F_8 ( V_6 -> V_7 [ V_17 ] ) ;
V_27 = F_8 ( V_6 -> V_7 [ V_18 ] ) ;
if ( V_26 > V_27 ) {
V_24 = V_17 ;
V_25 = V_18 ;
} else {
V_24 = V_18 ;
V_25 = V_17 ;
}
V_28 = F_11 ( V_6 , V_19 , V_24 ) ;
if ( V_28 ) {
V_6 -> V_15 = V_24 ;
return V_28 ;
}
V_6 -> V_15 = V_25 ;
return F_11 ( V_6 , V_19 , V_25 ) ;
}
static unsigned long F_14 ( struct V_1 * V_6 ,
unsigned long V_19 ,
unsigned long V_29 )
{
unsigned long long V_30 ;
T_1 V_31 ;
F_15 ( V_6 -> V_32 , V_33 , & V_31 ) ;
V_30 = ( unsigned long long ) V_29 * ( V_31 + 1 ) ;
F_9 ( V_30 , V_19 ) ;
return ( unsigned long ) V_30 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_29 , int V_19 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_34 , V_30 ;
F_17 ( & V_6 -> V_35 ) ;
if ( V_6 -> V_19 && V_6 -> V_19 != V_19 ) {
F_12 ( V_6 -> V_3 . V_23 ,
L_2 ,
V_5 -> V_36 ) ;
F_18 ( & V_6 -> V_35 ) ;
return - V_37 ;
}
if ( ! V_6 -> V_19 && V_29 ) {
V_34 = F_13 ( V_6 , V_19 ) ;
if ( ! V_34 ) {
F_12 ( V_6 -> V_3 . V_23 , L_3 ) ;
F_18 ( & V_6 -> V_35 ) ;
return - V_14 ;
}
F_19 ( V_6 -> V_32 , V_38 , V_39 ,
V_6 -> V_16 ) ;
F_20 ( V_6 -> V_32 , V_33 , V_34 - 1 ) ;
V_6 -> V_19 = V_19 ;
}
F_18 ( & V_6 -> V_35 ) ;
V_30 = F_14 ( V_6 , V_19 , V_29 ) ;
F_20 ( V_6 -> V_32 , F_21 ( V_5 -> V_36 ) ,
V_40 | V_41 ) ;
F_20 ( V_6 -> V_32 , F_22 ( V_5 -> V_36 ) , V_30 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
enum V_42 V_43 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_15 ( V_6 -> V_32 , V_44 , & V_31 ) ;
if ( V_43 == V_45 )
V_31 |= F_24 ( V_5 -> V_36 ) ;
else
V_31 &= ~ F_24 ( V_5 -> V_36 ) ;
F_20 ( V_6 -> V_32 , V_44 , V_31 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_6 )
{
int V_22 ;
F_19 ( V_6 -> V_32 , V_38 , V_46 ,
F_26 ( V_6 -> V_15 ) ) ;
V_22 = F_4 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
if ( V_22 )
return V_22 ;
V_22 = F_4 ( V_6 -> V_7 [ V_47 ] ) ;
if ( V_22 ) {
F_6 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
return V_22 ;
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_22 ;
F_17 ( & V_6 -> V_35 ) ;
F_19 ( V_6 -> V_32 , V_48 , F_24 ( V_5 -> V_36 ) , 0 ) ;
V_22 = F_25 ( V_6 ) ;
F_18 ( & V_6 -> V_35 ) ;
return V_22 ;
}
static void F_28 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_17 ( & V_6 -> V_35 ) ;
F_19 ( V_6 -> V_32 , V_48 , F_24 ( V_5 -> V_36 ) ,
F_24 ( V_5 -> V_36 ) ) ;
F_6 ( V_6 -> V_7 [ V_47 ] ) ;
F_6 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
F_15 ( V_6 -> V_32 , V_48 , & V_31 ) ;
if ( ( V_31 & 0xFF ) == 0xFF )
V_6 -> V_19 = 0 ;
F_18 ( & V_6 -> V_35 ) ;
}
static int F_29 ( struct V_1 * V_6 )
{
int V_22 ;
V_22 = F_4 ( V_6 -> V_7 [ V_8 ] ) ;
if ( V_22 )
return V_22 ;
F_20 ( V_6 -> V_32 , V_49 , 0x00 ) ;
F_20 ( V_6 -> V_32 , V_50 , 0x00 ) ;
F_20 ( V_6 -> V_32 , V_48 , 0xFF ) ;
F_6 ( V_6 -> V_7 [ V_8 ] ) ;
return 0 ;
}
static bool F_30 ( struct V_51 * V_23 , unsigned int V_52 )
{
switch ( V_52 ) {
case V_53 :
return true ;
}
return false ;
}
static int F_31 ( struct V_54 * V_55 )
{
struct V_1 * V_6 ;
struct V_56 * V_57 ;
void T_2 * V_58 ;
int V_22 ;
V_6 = F_32 ( & V_55 -> V_23 , sizeof( * V_6 ) , V_59 ) ;
if ( ! V_6 )
return - V_60 ;
F_33 ( & V_6 -> V_35 ) ;
V_6 -> V_3 . V_23 = & V_55 -> V_23 ;
V_57 = F_34 ( V_55 , V_61 , 0 ) ;
V_58 = F_35 ( & V_55 -> V_23 , V_57 ) ;
if ( F_36 ( V_58 ) )
return F_37 ( V_58 ) ;
V_6 -> V_32 = F_38 ( & V_55 -> V_23 , L_4 , V_58 ,
& V_62 ) ;
if ( F_36 ( V_6 -> V_32 ) ) {
F_12 ( & V_55 -> V_23 , L_5 ) ;
return F_37 ( V_6 -> V_32 ) ;
}
V_6 -> V_7 [ V_8 ] = F_39 ( & V_55 -> V_23 , L_4 ) ;
if ( F_36 ( V_6 -> V_7 [ V_8 ] ) ) {
F_12 ( & V_55 -> V_23 , L_6 ) ;
return F_37 ( V_6 -> V_7 [ V_8 ] ) ;
}
V_6 -> V_7 [ V_17 ] = F_39 ( V_6 -> V_3 . V_23 , L_7 ) ;
if ( F_36 ( V_6 -> V_7 [ V_17 ] ) )
return F_37 ( V_6 -> V_7 [ V_17 ] ) ;
V_6 -> V_7 [ V_18 ] = F_39 ( V_6 -> V_3 . V_23 , L_8 ) ;
if ( F_36 ( V_6 -> V_7 [ V_18 ] ) )
return F_37 ( V_6 -> V_7 [ V_18 ] ) ;
V_6 -> V_7 [ V_47 ] =
F_39 ( V_6 -> V_3 . V_23 , L_9 ) ;
if ( F_36 ( V_6 -> V_7 [ V_47 ] ) )
return F_37 ( V_6 -> V_7 [ V_47 ] ) ;
V_6 -> V_3 . V_63 = & V_64 ;
V_6 -> V_3 . V_65 = V_66 ;
V_6 -> V_3 . V_67 = 3 ;
V_6 -> V_3 . V_58 = - 1 ;
V_6 -> V_3 . V_68 = 8 ;
V_6 -> V_3 . V_69 = true ;
V_22 = F_40 ( & V_6 -> V_3 ) ;
if ( V_22 < 0 ) {
F_12 ( & V_55 -> V_23 , L_10 , V_22 ) ;
return V_22 ;
}
F_41 ( V_55 , V_6 ) ;
return F_29 ( V_6 ) ;
}
static int F_42 ( struct V_54 * V_55 )
{
struct V_1 * V_6 = F_43 ( V_55 ) ;
return F_44 ( & V_6 -> V_3 ) ;
}
static int F_45 ( struct V_51 * V_23 )
{
struct V_1 * V_6 = F_46 ( V_23 ) ;
int V_70 ;
F_47 ( V_6 -> V_32 , true ) ;
F_48 ( V_6 -> V_32 ) ;
for ( V_70 = 0 ; V_70 < V_6 -> V_3 . V_68 ; V_70 ++ ) {
struct V_4 * V_5 = & V_6 -> V_3 . V_71 [ V_70 ] ;
if ( ! F_49 ( V_72 , & V_5 -> V_73 ) )
continue;
F_6 ( V_6 -> V_7 [ V_8 ] ) ;
if ( ! F_50 ( V_5 ) )
continue;
F_6 ( V_6 -> V_7 [ V_47 ] ) ;
F_6 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
}
return 0 ;
}
static int F_51 ( struct V_51 * V_23 )
{
struct V_1 * V_6 = F_46 ( V_23 ) ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_6 -> V_3 . V_68 ; V_70 ++ ) {
struct V_4 * V_5 = & V_6 -> V_3 . V_71 [ V_70 ] ;
if ( ! F_49 ( V_72 , & V_5 -> V_73 ) )
continue;
F_4 ( V_6 -> V_7 [ V_8 ] ) ;
if ( ! F_50 ( V_5 ) )
continue;
F_4 ( V_6 -> V_7 [ V_6 -> V_15 ] ) ;
F_4 ( V_6 -> V_7 [ V_47 ] ) ;
}
F_47 ( V_6 -> V_32 , false ) ;
F_52 ( V_6 -> V_32 ) ;
return 0 ;
}
