static struct V_1 T_1 * F_1 ( unsigned V_2 )
{
void T_1 * V_3 ;
if ( V_2 < 32 * 1 )
V_3 = V_4 + 0x10 ;
else if ( V_2 < 32 * 2 )
V_3 = V_4 + 0x38 ;
else if ( V_2 < 32 * 3 )
V_3 = V_4 + 0x60 ;
else if ( V_2 < 32 * 4 )
V_3 = V_4 + 0x88 ;
else if ( V_2 < 32 * 5 )
V_3 = V_4 + 0xb0 ;
else
V_3 = NULL ;
return V_3 ;
}
static inline struct V_1 T_1 * F_2 ( int V_5 )
{
struct V_1 T_1 * V_6 ;
V_6 = ( V_7 struct V_1 T_1 * ) F_3 ( V_5 ) ;
return V_6 ;
}
static inline int F_4 ( struct V_8 * V_9 ,
unsigned V_10 , bool V_11 , int V_12 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_1 T_1 * V_6 = V_14 -> V_15 ;
unsigned long V_16 ;
T_2 V_17 ;
T_2 V_18 = 1 << V_10 ;
F_6 ( & V_14 -> V_19 , V_16 ) ;
V_17 = F_7 ( & V_6 -> V_20 ) ;
if ( V_11 ) {
V_17 &= ~ V_18 ;
F_8 ( V_18 , V_12 ? & V_6 -> V_21 : & V_6 -> V_22 ) ;
} else {
V_17 |= V_18 ;
}
F_8 ( V_17 , & V_6 -> V_20 ) ;
F_9 ( & V_14 -> V_19 , V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 , unsigned V_10 )
{
return F_4 ( V_9 , V_10 , false , 0 ) ;
}
static int
F_11 ( struct V_8 * V_9 , unsigned V_10 , int V_12 )
{
return F_4 ( V_9 , V_10 , true , V_12 ) ;
}
static int F_12 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_1 T_1 * V_6 = V_14 -> V_15 ;
return ( 1 << V_10 ) & F_7 ( & V_6 -> V_23 ) ;
}
static void
F_13 ( struct V_8 * V_9 , unsigned V_10 , int V_12 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_1 T_1 * V_6 = V_14 -> V_15 ;
F_8 ( ( 1 << V_10 ) , V_12 ? & V_6 -> V_21 : & V_6 -> V_22 ) ;
}
static int F_14 ( struct V_24 * V_25 )
{
int V_26 , V_27 ;
unsigned V_28 ;
struct V_13 * V_29 ;
struct V_30 * V_31 ;
struct V_1 T_1 * V_15 ;
struct V_32 * V_33 = & V_25 -> V_33 ;
struct V_34 * V_35 ;
V_31 = V_33 -> V_36 ;
if ( ! V_31 ) {
F_15 ( V_33 , L_1 ) ;
return - V_37 ;
}
V_28 = V_31 -> V_28 ;
if ( V_28 == 0 ) {
F_15 ( V_33 , L_2 ) ;
return - V_37 ;
}
if ( F_16 ( V_38 < V_28 ) )
V_28 = V_38 ;
V_29 = F_17 ( V_33 ,
V_28 * sizeof( struct V_13 ) ,
V_39 ) ;
if ( ! V_29 ) {
F_15 ( V_33 , L_3 ) ;
return - V_40 ;
}
V_35 = F_18 ( V_25 , V_41 , 0 ) ;
if ( ! V_35 ) {
F_15 ( V_33 , L_4 ) ;
return - V_42 ;
}
V_4 = F_19 ( V_33 , V_35 ) ;
if ( F_20 ( V_4 ) )
return F_21 ( V_4 ) ;
for ( V_26 = 0 , V_27 = 0 ; V_27 < V_28 ; V_26 ++ , V_27 += 32 ) {
V_29 [ V_26 ] . V_9 . V_43 = L_5 ;
V_29 [ V_26 ] . V_9 . V_44 = F_10 ;
V_29 [ V_26 ] . V_9 . V_45 = F_12 ;
V_29 [ V_26 ] . V_9 . V_46 = F_11 ;
V_29 [ V_26 ] . V_9 . V_47 = F_13 ;
V_29 [ V_26 ] . V_9 . V_27 = V_27 ;
V_29 [ V_26 ] . V_9 . V_28 = V_28 - V_27 ;
if ( V_29 [ V_26 ] . V_9 . V_28 > 32 )
V_29 [ V_26 ] . V_9 . V_28 = 32 ;
F_22 ( & V_29 [ V_26 ] . V_19 ) ;
V_15 = F_1 ( V_27 ) ;
V_29 [ V_26 ] . V_15 = V_15 ;
V_29 [ V_26 ] . V_21 = & V_15 -> V_21 ;
V_29 [ V_26 ] . V_22 = & V_15 -> V_22 ;
V_29 [ V_26 ] . V_23 = & V_15 -> V_23 ;
F_23 ( & V_29 [ V_26 ] . V_9 ) ;
}
F_24 ( V_25 , V_29 ) ;
F_25 ( V_25 ) ;
return 0 ;
}
static void F_26 ( struct V_48 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_2 V_18 = ( T_2 ) F_27 ( V_14 ) ;
F_8 ( V_18 , & V_6 -> V_49 ) ;
F_8 ( V_18 , & V_6 -> V_50 ) ;
}
static void F_28 ( struct V_48 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_2 V_18 = ( T_2 ) F_27 ( V_14 ) ;
unsigned V_51 = F_29 ( V_14 ) ;
V_51 &= V_52 | V_53 ;
if ( ! V_51 )
V_51 = V_52 | V_53 ;
if ( V_51 & V_52 )
F_8 ( V_18 , & V_6 -> V_54 ) ;
if ( V_51 & V_53 )
F_8 ( V_18 , & V_6 -> V_55 ) ;
}
static int F_30 ( struct V_48 * V_14 , unsigned V_56 )
{
if ( V_56 & ~ ( V_52 | V_53 ) )
return - V_37 ;
return 0 ;
}
static void
F_31 ( unsigned V_5 , struct V_57 * V_58 )
{
struct V_1 T_1 * V_6 ;
T_2 V_18 = 0xffff ;
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) F_32 ( V_58 ) ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
if ( V_5 & 1 )
V_18 <<= 16 ;
V_58 -> V_48 . V_9 -> V_59 ( & V_58 -> V_48 ) ;
V_58 -> V_48 . V_9 -> V_60 ( & V_58 -> V_48 ) ;
while ( 1 ) {
T_2 V_51 ;
int V_61 ;
int V_35 ;
V_51 = F_7 ( & V_6 -> V_62 ) & V_18 ;
if ( ! V_51 )
break;
F_8 ( V_51 , & V_6 -> V_62 ) ;
V_61 = V_14 -> V_63 ;
if ( V_5 & 1 ) {
V_61 += 16 ;
V_51 >>= 16 ;
}
while ( V_51 ) {
V_35 = F_33 ( V_51 ) ;
V_61 += V_35 ;
F_34 ( V_61 - 1 ) ;
V_51 >>= V_35 ;
}
}
V_58 -> V_48 . V_9 -> V_64 ( & V_58 -> V_48 ) ;
}
static int F_35 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_14 -> V_63 >= 0 )
return V_14 -> V_63 + V_10 ;
else
return - V_65 ;
}
static int F_36 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_10 < V_14 -> V_66 )
return V_14 -> V_67 + V_10 ;
else
return - V_65 ;
}
static int F_37 ( struct V_48 * V_68 , unsigned V_56 )
{
struct V_13 * V_14 ;
struct V_1 T_1 * V_6 ;
T_2 V_18 ;
V_14 = (struct V_13 * ) V_68 -> V_69 ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
V_18 = F_38 ( V_68 -> V_5 - V_14 -> V_67 ) ;
if ( V_56 & ~ ( V_52 | V_53 ) )
return - V_37 ;
F_8 ( V_18 , ( V_56 & V_52 )
? & V_6 -> V_54 : & V_6 -> V_49 ) ;
F_8 ( V_18 , ( V_56 & V_53 )
? & V_6 -> V_55 : & V_6 -> V_50 ) ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 )
{
unsigned V_2 , V_5 , V_70 ;
struct V_71 * V_71 ;
T_2 V_72 = 0 ;
unsigned V_28 , V_73 ;
struct V_32 * V_33 = & V_25 -> V_33 ;
struct V_34 * V_35 ;
struct V_13 * V_29 = F_39 ( V_25 ) ;
struct V_30 * V_31 = V_33 -> V_36 ;
struct V_1 T_1 * V_6 ;
V_28 = V_31 -> V_28 ;
V_35 = F_18 ( V_25 , V_74 , 0 ) ;
if ( ! V_35 ) {
F_15 ( V_33 , L_6 ) ;
return - V_42 ;
}
V_73 = V_35 -> V_75 ;
if ( ! V_73 ) {
F_15 ( V_33 , L_6 ) ;
return - V_65 ;
}
V_71 = F_40 ( V_33 , L_7 ) ;
if ( F_20 ( V_71 ) ) {
F_41 ( V_76 L_8 ,
F_21 ( V_71 ) ) ;
return F_21 ( V_71 ) ;
}
F_42 ( V_71 ) ;
for ( V_2 = 0 , V_70 = 0 ; V_2 < V_28 ; V_70 ++ , V_2 += 32 ) {
V_29 [ V_70 ] . V_9 . V_77 = F_35 ;
V_29 [ V_70 ] . V_63 = V_31 -> V_66
? - V_37
: ( V_31 -> V_78 + V_2 ) ;
}
if ( V_31 -> V_66 ) {
static struct V_79 V_66 ;
V_29 [ 0 ] . V_9 . V_77 = F_36 ;
V_29 [ 0 ] . V_67 = V_73 ;
V_29 [ 0 ] . V_66 = V_31 -> V_66 ;
V_72 = F_43 ( 0 ) ;
V_5 = V_73 ;
V_66 = * F_44 ( F_45 ( V_5 ) ,
struct V_79 , V_9 ) ;
V_66 . V_9 . V_80 = L_9 ;
V_66 . V_9 . V_81 = F_37 ;
V_6 = F_1 ( 0 ) ;
F_8 ( ~ 0 , & V_6 -> V_54 ) ;
F_8 ( ~ 0 , & V_6 -> V_55 ) ;
for ( V_2 = 0 ; V_2 < V_31 -> V_66 ; V_2 ++ , V_5 ++ ) {
F_46 ( V_5 , & V_66 . V_9 ) ;
F_47 ( V_5 , & V_29 [ V_2 / 32 ] ) ;
F_48 ( V_5 , V_82 ) ;
}
goto V_83;
}
for ( V_2 = 0 , V_5 = F_49 ( 0 ) , V_70 = 0 ;
V_2 < V_28 ;
V_70 ++ , V_73 ++ ) {
unsigned V_26 ;
V_6 = F_1 ( V_2 ) ;
F_8 ( ~ 0 , & V_6 -> V_49 ) ;
F_8 ( ~ 0 , & V_6 -> V_50 ) ;
F_50 ( V_73 , F_31 ) ;
F_47 ( V_73 , & V_29 [ V_2 / 32 ] ) ;
for ( V_26 = 0 ; V_26 < 16 && V_2 < V_28 ; V_26 ++ , V_5 ++ , V_2 ++ ) {
F_46 ( V_5 , & V_84 ) ;
F_51 ( V_5 , ( V_7 void * ) V_6 ) ;
F_47 ( V_5 , ( void * ) F_38 ( V_2 ) ) ;
F_52 ( V_5 , V_85 ) ;
F_53 ( V_5 , V_86 ) ;
}
V_72 |= F_43 ( V_70 ) ;
}
V_83:
F_8 ( V_72 , V_4 + V_87 ) ;
F_41 ( V_88 L_10 , V_5 - F_49 ( 0 ) ) ;
return 0 ;
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_89 ) ;
}
