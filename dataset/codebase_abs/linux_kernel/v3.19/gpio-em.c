static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < V_4 )
return F_2 ( V_2 -> V_5 + V_3 ) ;
else
return F_2 ( V_2 -> V_6 + ( V_3 - V_4 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_7 )
{
if ( V_3 < V_4 )
F_4 ( V_7 , V_2 -> V_5 + V_3 ) ;
else
F_4 ( V_7 , V_2 -> V_6 + ( V_3 - V_4 ) ) ;
}
static void F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_3 ( V_2 , V_10 , F_7 ( F_8 ( V_9 ) ) ) ;
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_3 ( V_2 , V_11 , F_7 ( F_8 ( V_9 ) ) ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( F_11 ( & V_2 -> V_12 , F_8 ( V_9 ) ) ) {
F_12 ( V_2 -> V_12 . V_13 ,
L_1 ,
F_8 ( V_9 ) ) ;
return - V_14 ;
}
return 0 ;
}
static void F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_14 ( & V_2 -> V_12 , F_8 ( V_9 ) ) ;
}
static int F_15 ( struct V_8 * V_9 , unsigned int type )
{
unsigned char V_7 = V_15 [ type & V_16 ] ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_17 , V_18 , V_19 ;
unsigned long V_20 ;
unsigned long V_21 ;
if ( ! V_7 )
return - V_14 ;
V_18 = F_8 ( V_9 ) ;
F_16 ( L_2 , V_18 , V_7 ) ;
V_17 = F_17 ( V_18 >> 3 ) ;
V_19 = ( V_18 & 0x07 ) << 4 ;
F_18 ( & V_2 -> V_22 , V_20 ) ;
V_21 = F_1 ( V_2 , V_23 ) ;
V_21 &= ~ F_7 ( V_18 ) ;
F_3 ( V_2 , V_23 , V_21 ) ;
V_21 = F_1 ( V_2 , V_17 ) ;
V_21 &= ~ ( 0xf << V_19 ) ;
V_21 |= V_7 << V_19 ;
F_3 ( V_2 , V_17 , V_21 ) ;
F_3 ( V_2 , V_24 , F_7 ( V_18 ) ) ;
V_21 = F_1 ( V_2 , V_23 ) ;
V_21 |= F_7 ( V_18 ) ;
F_3 ( V_2 , V_23 , V_21 ) ;
F_19 ( & V_2 -> V_22 , V_20 ) ;
return 0 ;
}
static T_1 F_20 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
unsigned long V_27 ;
unsigned int V_18 , V_28 = 0 ;
while ( ( V_27 = F_1 ( V_2 , V_29 ) ) ) {
V_18 = F_21 ( V_27 ) ;
F_3 ( V_2 , V_24 , F_7 ( V_18 ) ) ;
F_22 ( F_23 ( V_2 -> V_30 , V_18 ) ) ;
V_28 ++ ;
}
return V_28 ? V_31 : V_32 ;
}
static inline struct V_1 * F_24 ( struct V_12 * V_33 )
{
return F_25 ( V_33 , struct V_1 , V_12 ) ;
}
static int F_26 ( struct V_12 * V_33 , unsigned V_18 )
{
F_3 ( F_24 ( V_33 ) , V_34 , F_7 ( V_18 ) ) ;
return 0 ;
}
static int F_27 ( struct V_12 * V_33 , unsigned V_18 )
{
return ( int ) ( F_1 ( F_24 ( V_33 ) , V_35 ) & F_7 ( V_18 ) ) ;
}
static void F_28 ( struct V_12 * V_33 , unsigned int V_17 ,
unsigned V_19 , int V_7 )
{
F_3 ( F_24 ( V_33 ) , V_17 ,
( F_7 ( V_19 + 16 ) ) | ( V_7 << V_19 ) ) ;
}
static void F_29 ( struct V_12 * V_33 , unsigned V_18 , int V_7 )
{
if ( V_18 < 16 )
F_28 ( V_33 , V_36 , V_18 , V_7 ) ;
else
F_28 ( V_33 , V_37 , V_18 - 16 , V_7 ) ;
}
static int F_30 ( struct V_12 * V_33 , unsigned V_18 ,
int V_7 )
{
F_29 ( V_33 , V_18 , V_7 ) ;
F_3 ( F_24 ( V_33 ) , V_38 , F_7 ( V_18 ) ) ;
return 0 ;
}
static int F_31 ( struct V_12 * V_33 , unsigned V_18 )
{
return F_32 ( F_24 ( V_33 ) -> V_30 , V_18 ) ;
}
static int F_33 ( struct V_12 * V_33 , unsigned V_18 )
{
return F_34 ( V_33 -> V_39 + V_18 ) ;
}
static void F_35 ( struct V_12 * V_33 , unsigned V_18 )
{
F_36 ( V_33 -> V_39 + V_18 ) ;
F_26 ( V_33 , V_18 ) ;
}
static int F_37 ( struct V_30 * V_40 , unsigned int V_25 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_40 -> V_42 ;
F_16 ( L_3 , ( int ) V_41 , V_25 ) ;
F_38 ( V_25 , V_40 -> V_42 ) ;
F_39 ( V_25 , & V_2 -> V_43 , V_44 ) ;
F_40 ( V_25 , V_45 ) ;
return 0 ;
}
static int F_41 ( struct V_46 * V_47 )
{
struct V_48 V_49 ;
struct V_48 * V_50 = F_42 ( & V_47 -> V_13 ) ;
struct V_1 * V_2 ;
struct V_51 * V_52 [ 2 ] , * V_25 [ 2 ] ;
struct V_12 * V_12 ;
struct V_43 * V_43 ;
const char * V_53 = F_43 ( & V_47 -> V_13 ) ;
int V_54 ;
V_2 = F_44 ( & V_47 -> V_13 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 ) {
V_54 = - V_56 ;
goto V_57;
}
V_2 -> V_47 = V_47 ;
F_45 ( V_47 , V_2 ) ;
F_46 ( & V_2 -> V_22 ) ;
V_52 [ 0 ] = F_47 ( V_47 , V_58 , 0 ) ;
V_52 [ 1 ] = F_47 ( V_47 , V_58 , 1 ) ;
V_25 [ 0 ] = F_47 ( V_47 , V_59 , 0 ) ;
V_25 [ 1 ] = F_47 ( V_47 , V_59 , 1 ) ;
if ( ! V_52 [ 0 ] || ! V_52 [ 1 ] || ! V_25 [ 0 ] || ! V_25 [ 1 ] ) {
F_12 ( & V_47 -> V_13 , L_4 ) ;
V_54 = - V_14 ;
goto V_57;
}
V_2 -> V_5 = F_48 ( & V_47 -> V_13 , V_52 [ 0 ] -> V_60 ,
F_49 ( V_52 [ 0 ] ) ) ;
if ( ! V_2 -> V_5 ) {
F_12 ( & V_47 -> V_13 , L_5 ) ;
V_54 = - V_61 ;
goto V_57;
}
V_2 -> V_6 = F_48 ( & V_47 -> V_13 , V_52 [ 1 ] -> V_60 ,
F_49 ( V_52 [ 1 ] ) ) ;
if ( ! V_2 -> V_6 ) {
F_12 ( & V_47 -> V_13 , L_6 ) ;
V_54 = - V_61 ;
goto V_57;
}
if ( ! V_50 ) {
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_50 = & V_49 ;
if ( F_50 ( V_47 -> V_13 . V_62 , L_7 ,
& V_50 -> V_63 ) ) {
F_12 ( & V_47 -> V_13 , L_8 ) ;
V_54 = - V_14 ;
goto V_57;
}
V_50 -> V_64 = - 1 ;
}
V_12 = & V_2 -> V_12 ;
V_12 -> V_62 = V_47 -> V_13 . V_62 ;
V_12 -> V_65 = F_26 ;
V_12 -> V_66 = F_27 ;
V_12 -> V_67 = F_30 ;
V_12 -> V_68 = F_29 ;
V_12 -> V_69 = F_31 ;
V_12 -> V_70 = F_33 ;
V_12 -> free = F_35 ;
V_12 -> V_71 = V_53 ;
V_12 -> V_13 = & V_47 -> V_13 ;
V_12 -> V_72 = V_73 ;
V_12 -> V_39 = V_50 -> V_64 ;
V_12 -> V_74 = V_50 -> V_63 ;
V_43 = & V_2 -> V_43 ;
V_43 -> V_53 = V_53 ;
V_43 -> V_75 = F_5 ;
V_43 -> V_76 = F_9 ;
V_43 -> V_77 = F_15 ;
V_43 -> V_78 = F_10 ;
V_43 -> V_79 = F_13 ;
V_43 -> V_20 = V_80 | V_81 ;
V_2 -> V_30 = F_51 ( V_47 -> V_13 . V_62 ,
V_50 -> V_63 ,
V_50 -> V_82 ,
& V_83 , V_2 ) ;
if ( ! V_2 -> V_30 ) {
V_54 = - V_61 ;
F_12 ( & V_47 -> V_13 , L_9 ) ;
goto V_57;
}
if ( F_52 ( & V_47 -> V_13 , V_25 [ 0 ] -> V_60 ,
F_20 , 0 , V_53 , V_2 ) ) {
F_12 ( & V_47 -> V_13 , L_10 ) ;
V_54 = - V_84 ;
goto V_85;
}
if ( F_52 ( & V_47 -> V_13 , V_25 [ 1 ] -> V_60 ,
F_20 , 0 , V_53 , V_2 ) ) {
F_12 ( & V_47 -> V_13 , L_11 ) ;
V_54 = - V_84 ;
goto V_85;
}
V_54 = F_53 ( V_12 ) ;
if ( V_54 ) {
F_12 ( & V_47 -> V_13 , L_12 ) ;
goto V_85;
}
if ( V_50 -> V_86 ) {
V_54 = F_54 ( V_12 , V_50 -> V_86 , 0 ,
V_12 -> V_39 , V_12 -> V_74 ) ;
if ( V_54 < 0 )
F_55 ( & V_47 -> V_13 , L_13 ) ;
}
return 0 ;
V_85:
F_56 ( V_2 -> V_30 ) ;
V_57:
return V_54 ;
}
static int F_57 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_58 ( V_47 ) ;
F_59 ( & V_2 -> V_12 ) ;
F_56 ( V_2 -> V_30 ) ;
return 0 ;
}
static int T_3 F_60 ( void )
{
return F_61 ( & V_87 ) ;
}
static void T_4 F_62 ( void )
{
F_63 ( & V_87 ) ;
}
