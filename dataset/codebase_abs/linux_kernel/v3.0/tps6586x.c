static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 , V_3 ) ;
return V_5 ;
}
* V_4 = ( T_1 ) V_5 ;
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 , int V_3 ,
int V_7 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_5 ( V_2 , V_3 , V_7 , V_4 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_2 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_3 ,
V_4 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static inline int F_8 ( struct V_1 * V_2 , int V_3 ,
int V_7 , T_1 * V_4 )
{
int V_5 , V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
V_5 = F_6 ( V_2 , V_3 + V_8 , * ( V_4 + V_8 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
int F_9 ( struct V_9 * V_6 , int V_3 , T_1 V_4 )
{
return F_6 ( F_10 ( V_6 ) , V_3 , V_4 ) ;
}
int F_11 ( struct V_9 * V_6 , int V_3 , int V_7 , T_1 * V_4 )
{
return F_8 ( F_10 ( V_6 ) , V_3 , V_7 , V_4 ) ;
}
int F_12 ( struct V_9 * V_6 , int V_3 , T_1 * V_4 )
{
return F_1 ( F_10 ( V_6 ) , V_3 , V_4 ) ;
}
int F_13 ( struct V_9 * V_6 , int V_3 , int V_7 , T_1 * V_4 )
{
return F_4 ( F_10 ( V_6 ) , V_3 , V_7 , V_4 ) ;
}
int F_14 ( struct V_9 * V_6 , int V_3 , T_1 V_10 )
{
struct V_11 * V_11 = F_15 ( V_6 ) ;
T_1 V_12 ;
int V_5 = 0 ;
F_16 ( & V_11 -> V_13 ) ;
V_5 = F_1 ( F_10 ( V_6 ) , V_3 , & V_12 ) ;
if ( V_5 )
goto V_14;
if ( ( V_12 & V_10 ) == 0 ) {
V_12 |= V_10 ;
V_5 = F_6 ( F_10 ( V_6 ) , V_3 , V_12 ) ;
}
V_14:
F_17 ( & V_11 -> V_13 ) ;
return V_5 ;
}
int F_18 ( struct V_9 * V_6 , int V_3 , T_1 V_10 )
{
struct V_11 * V_11 = F_15 ( V_6 ) ;
T_1 V_12 ;
int V_5 = 0 ;
F_16 ( & V_11 -> V_13 ) ;
V_5 = F_1 ( F_10 ( V_6 ) , V_3 , & V_12 ) ;
if ( V_5 )
goto V_14;
if ( V_12 & V_10 ) {
V_12 &= ~ V_10 ;
V_5 = F_6 ( F_10 ( V_6 ) , V_3 , V_12 ) ;
}
V_14:
F_17 ( & V_11 -> V_13 ) ;
return V_5 ;
}
int F_19 ( struct V_9 * V_6 , int V_3 , T_1 V_4 , T_1 V_15 )
{
struct V_11 * V_11 = F_15 ( V_6 ) ;
T_1 V_12 ;
int V_5 = 0 ;
F_16 ( & V_11 -> V_13 ) ;
V_5 = F_1 ( V_11 -> V_2 , V_3 , & V_12 ) ;
if ( V_5 )
goto V_14;
if ( ( V_12 & V_15 ) != V_4 ) {
V_12 = ( V_12 & ~ V_15 ) | V_4 ;
V_5 = F_6 ( V_11 -> V_2 , V_3 , V_12 ) ;
}
V_14:
F_17 ( & V_11 -> V_13 ) ;
return V_5 ;
}
static int F_20 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_11 * V_11 = F_21 ( V_17 , struct V_11 , V_19 ) ;
T_1 V_4 ;
int V_5 ;
V_5 = F_1 ( V_11 -> V_2 , V_20 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return ! ! ( V_4 & ( 1 << V_18 ) ) ;
}
static void F_22 ( struct V_16 * V_21 , unsigned V_18 ,
int V_22 )
{
struct V_11 * V_11 = F_21 ( V_21 , struct V_11 , V_19 ) ;
F_19 ( V_11 -> V_6 , V_20 ,
V_22 << V_18 , 1 << V_18 ) ;
}
static int F_23 ( struct V_16 * V_17 , unsigned V_18 ,
int V_22 )
{
struct V_11 * V_11 = F_21 ( V_17 , struct V_11 , V_19 ) ;
T_1 V_4 , V_15 ;
F_22 ( V_17 , V_18 , V_22 ) ;
V_4 = 0x1 << ( V_18 * 2 ) ;
V_15 = 0x3 << ( V_18 * 2 ) ;
return F_19 ( V_11 -> V_6 , V_23 , V_4 , V_15 ) ;
}
static int F_24 ( struct V_11 * V_11 , int V_24 )
{
if ( ! V_24 )
return 0 ;
V_11 -> V_19 . V_25 = V_26 ;
V_11 -> V_19 . V_27 = V_11 -> V_2 -> V_28 ;
V_11 -> V_19 . V_6 = V_11 -> V_6 ;
V_11 -> V_19 . V_29 = V_24 ;
V_11 -> V_19 . V_30 = 4 ;
V_11 -> V_19 . V_31 = 1 ;
V_11 -> V_19 . V_32 = F_23 ;
V_11 -> V_19 . V_33 = F_22 ;
V_11 -> V_19 . V_34 = F_20 ;
return F_25 ( & V_11 -> V_19 ) ;
}
static int F_26 ( struct V_9 * V_6 , void * V_35 )
{
F_27 ( F_28 ( V_6 ) ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_11 )
{
return F_30 ( V_11 -> V_6 , NULL , F_26 ) ;
}
static void F_31 ( struct V_36 * V_37 )
{
struct V_11 * V_11 = F_32 ( V_37 ) ;
F_16 ( & V_11 -> V_38 ) ;
}
static void F_33 ( struct V_36 * V_36 )
{
struct V_11 * V_11 = F_32 ( V_36 ) ;
unsigned int V_39 = V_36 -> V_40 - V_11 -> V_41 ;
const struct V_42 * V_37 = & V_43 [ V_39 ] ;
V_11 -> V_44 [ V_37 -> V_44 ] &= ~ V_37 -> V_45 ;
V_11 -> V_46 |= ( 1 << V_39 ) ;
}
static void F_34 ( struct V_36 * V_36 )
{
struct V_11 * V_11 = F_32 ( V_36 ) ;
unsigned int V_39 = V_36 -> V_40 - V_11 -> V_41 ;
const struct V_42 * V_37 = & V_43 [ V_39 ] ;
V_11 -> V_44 [ V_37 -> V_44 ] |= V_37 -> V_45 ;
V_11 -> V_46 &= ~ ( 1 << V_39 ) ;
}
static void F_35 ( struct V_36 * V_37 )
{
struct V_11 * V_11 = F_32 ( V_37 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_36 ( V_11 -> V_44 ) ; V_8 ++ ) {
if ( V_11 -> V_44 [ V_8 ] != V_11 -> V_47 [ V_8 ] ) {
if ( ! F_37 ( F_9 ( V_11 -> V_6 ,
V_48 + V_8 ,
V_11 -> V_44 [ V_8 ] ) ) )
V_11 -> V_47 [ V_8 ] = V_11 -> V_44 [ V_8 ] ;
}
}
F_17 ( & V_11 -> V_38 ) ;
}
static T_2 F_38 ( int V_40 , void * V_37 )
{
struct V_11 * V_11 = V_37 ;
T_3 V_49 ;
int V_5 = 0 ;
V_5 = F_13 ( V_11 -> V_6 , V_50 ,
sizeof( V_49 ) , ( T_1 * ) & V_49 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_6 , L_4 ) ;
return V_51 ;
}
V_49 = F_39 ( V_49 ) ;
while ( V_49 ) {
int V_8 = F_40 ( V_49 ) ;
if ( V_11 -> V_46 & ( 1 << V_8 ) )
F_41 ( V_11 -> V_41 + V_8 ) ;
V_49 &= ~ ( 1 << V_8 ) ;
}
return V_52 ;
}
static int T_4 F_42 ( struct V_11 * V_11 , int V_40 ,
int V_41 )
{
int V_8 , V_5 ;
T_5 V_53 [ 4 ] ;
if ( ! V_41 ) {
F_43 ( V_11 -> V_6 , L_5 ) ;
return - V_54 ;
}
F_44 ( & V_11 -> V_38 ) ;
for ( V_8 = 0 ; V_8 < 5 ; V_8 ++ ) {
V_11 -> V_47 [ V_8 ] = 0xff ;
V_11 -> V_44 [ V_8 ] = 0xff ;
F_9 ( V_11 -> V_6 , V_48 + V_8 , 0xff ) ;
}
F_13 ( V_11 -> V_6 , V_50 , sizeof( V_53 ) , V_53 ) ;
V_11 -> V_41 = V_41 ;
V_11 -> V_55 . V_28 = L_6 ;
V_11 -> V_55 . V_56 = F_33 ;
V_11 -> V_55 . V_57 = F_34 ;
V_11 -> V_55 . V_58 = F_31 ;
V_11 -> V_55 . V_59 = F_35 ;
for ( V_8 = 0 ; V_8 < F_36 ( V_43 ) ; V_8 ++ ) {
int V_39 = V_8 + V_11 -> V_41 ;
F_45 ( V_39 , V_11 ) ;
F_46 ( V_39 , & V_11 -> V_55 ,
V_60 ) ;
F_47 ( V_39 , 1 ) ;
#ifdef F_48
F_49 ( V_39 , V_61 ) ;
#endif
}
V_5 = F_50 ( V_40 , NULL , F_38 , V_62 ,
L_6 , V_11 ) ;
if ( ! V_5 ) {
F_51 ( V_11 -> V_6 , 1 ) ;
F_52 ( V_40 ) ;
}
return V_5 ;
}
static int T_4 F_53 ( struct V_11 * V_11 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int V_8 , V_5 = 0 ;
for ( V_8 = 0 ; V_8 < V_64 -> V_69 ; V_8 ++ ) {
V_66 = & V_64 -> V_70 [ V_8 ] ;
V_68 = F_54 ( V_66 -> V_28 , V_66 -> V_71 ) ;
if ( ! V_68 ) {
V_5 = - V_72 ;
goto V_73;
}
V_68 -> V_6 . V_74 = V_11 -> V_6 ;
V_68 -> V_6 . V_75 = V_66 -> V_75 ;
V_5 = F_55 ( V_68 ) ;
if ( V_5 ) {
F_56 ( V_68 ) ;
goto V_73;
}
}
return 0 ;
V_73:
F_29 ( V_11 ) ;
return V_5 ;
}
static int T_4 F_57 ( struct V_1 * V_2 ,
const struct V_76 * V_71 )
{
struct V_63 * V_64 = V_2 -> V_6 . V_75 ;
struct V_11 * V_11 ;
int V_5 ;
if ( ! V_64 ) {
F_3 ( & V_2 -> V_6 , L_7 ) ;
return - V_77 ;
}
V_5 = F_2 ( V_2 , V_78 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_8 , V_5 ) ;
return - V_79 ;
}
F_58 ( & V_2 -> V_6 , L_9 , V_5 ) ;
V_11 = F_59 ( sizeof( struct V_11 ) , V_80 ) ;
if ( V_11 == NULL )
return - V_72 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_6 = & V_2 -> V_6 ;
F_60 ( V_2 , V_11 ) ;
F_44 ( & V_11 -> V_13 ) ;
if ( V_2 -> V_40 ) {
V_5 = F_42 ( V_11 , V_2 -> V_40 ,
V_64 -> V_41 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_10 , V_5 ) ;
goto V_81;
}
}
V_5 = F_24 ( V_11 , V_64 -> V_24 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_11 , V_5 ) ;
goto V_82;
}
V_5 = F_53 ( V_11 , V_64 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_12 , V_5 ) ;
goto V_83;
}
return 0 ;
V_83:
if ( V_64 -> V_24 ) {
V_5 = F_61 ( & V_11 -> V_19 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_6 , L_13 ,
V_5 ) ;
}
V_82:
if ( V_2 -> V_40 )
F_62 ( V_2 -> V_40 , V_11 ) ;
V_81:
F_63 ( V_11 ) ;
return V_5 ;
}
static int T_6 F_64 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_65 ( V_2 ) ;
struct V_63 * V_64 = V_2 -> V_6 . V_75 ;
int V_5 ;
if ( V_2 -> V_40 )
F_62 ( V_2 -> V_40 , V_11 ) ;
if ( V_64 -> V_24 ) {
V_5 = F_61 ( & V_11 -> V_19 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_6 , L_13 ,
V_5 ) ;
}
F_29 ( V_11 ) ;
F_63 ( V_11 ) ;
return 0 ;
}
static int T_7 F_66 ( void )
{
return F_67 ( & V_84 ) ;
}
static void T_8 F_68 ( void )
{
F_69 ( & V_84 ) ;
}
