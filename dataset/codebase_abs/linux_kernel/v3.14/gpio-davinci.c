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
static struct V_24 *
F_14 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_29 . V_30 ;
struct V_24 * V_31 ;
int V_32 ;
T_2 V_33 ;
if ( ! F_15 ( V_34 ) || ! V_26 -> V_29 . V_30 )
return V_26 -> V_29 . V_35 ;
V_31 = F_16 ( & V_26 -> V_29 , sizeof( * V_31 ) , V_36 ) ;
if ( ! V_31 )
return NULL ;
V_32 = F_17 ( V_28 , L_1 , & V_33 ) ;
if ( V_32 )
goto V_37;
V_31 -> V_38 = V_33 ;
V_32 = F_17 ( V_28 , L_2 , & V_33 ) ;
if ( V_32 )
goto V_37;
V_31 -> V_39 = V_33 ;
return V_31 ;
V_37:
F_18 ( & V_26 -> V_29 , L_3 , V_32 ) ;
return NULL ;
}
static int F_19 ( struct V_25 * V_26 )
{
int V_40 , V_41 ;
unsigned V_38 ;
struct V_13 * V_42 ;
struct V_24 * V_31 ;
struct V_1 T_1 * V_15 ;
struct V_43 * V_29 = & V_26 -> V_29 ;
struct V_44 * V_45 ;
V_31 = F_14 ( V_26 ) ;
if ( ! V_31 ) {
F_18 ( V_29 , L_4 ) ;
return - V_46 ;
}
V_29 -> V_35 = V_31 ;
V_38 = V_31 -> V_38 ;
if ( V_38 == 0 ) {
F_18 ( V_29 , L_5 ) ;
return - V_46 ;
}
if ( F_20 ( V_47 < V_38 ) )
V_38 = V_47 ;
V_42 = F_16 ( V_29 ,
V_38 * sizeof( struct V_13 ) ,
V_36 ) ;
if ( ! V_42 ) {
F_18 ( V_29 , L_6 ) ;
return - V_48 ;
}
V_45 = F_21 ( V_26 , V_49 , 0 ) ;
if ( ! V_45 ) {
F_18 ( V_29 , L_7 ) ;
return - V_50 ;
}
V_4 = F_22 ( V_29 , V_45 ) ;
if ( F_23 ( V_4 ) )
return F_24 ( V_4 ) ;
for ( V_40 = 0 , V_41 = 0 ; V_41 < V_38 ; V_40 ++ , V_41 += 32 ) {
V_42 [ V_40 ] . V_9 . V_51 = L_8 ;
V_42 [ V_40 ] . V_9 . V_52 = F_10 ;
V_42 [ V_40 ] . V_9 . V_53 = F_12 ;
V_42 [ V_40 ] . V_9 . V_54 = F_11 ;
V_42 [ V_40 ] . V_9 . V_55 = F_13 ;
V_42 [ V_40 ] . V_9 . V_41 = V_41 ;
V_42 [ V_40 ] . V_9 . V_38 = V_38 - V_41 ;
if ( V_42 [ V_40 ] . V_9 . V_38 > 32 )
V_42 [ V_40 ] . V_9 . V_38 = 32 ;
#ifdef F_25
V_42 [ V_40 ] . V_9 . V_30 = V_29 -> V_30 ;
#endif
F_26 ( & V_42 [ V_40 ] . V_19 ) ;
V_15 = F_1 ( V_41 ) ;
V_42 [ V_40 ] . V_15 = V_15 ;
V_42 [ V_40 ] . V_21 = & V_15 -> V_21 ;
V_42 [ V_40 ] . V_22 = & V_15 -> V_22 ;
V_42 [ V_40 ] . V_23 = & V_15 -> V_23 ;
F_27 ( & V_42 [ V_40 ] . V_9 ) ;
}
F_28 ( V_26 , V_42 ) ;
F_29 ( V_26 ) ;
return 0 ;
}
static void F_30 ( struct V_56 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_2 V_18 = ( T_2 ) F_31 ( V_14 ) ;
F_8 ( V_18 , & V_6 -> V_57 ) ;
F_8 ( V_18 , & V_6 -> V_58 ) ;
}
static void F_32 ( struct V_56 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_2 V_18 = ( T_2 ) F_31 ( V_14 ) ;
unsigned V_59 = F_33 ( V_14 ) ;
V_59 &= V_60 | V_61 ;
if ( ! V_59 )
V_59 = V_60 | V_61 ;
if ( V_59 & V_60 )
F_8 ( V_18 , & V_6 -> V_62 ) ;
if ( V_59 & V_61 )
F_8 ( V_18 , & V_6 -> V_63 ) ;
}
static int F_34 ( struct V_56 * V_14 , unsigned V_64 )
{
if ( V_64 & ~ ( V_60 | V_61 ) )
return - V_46 ;
return 0 ;
}
static void
F_35 ( unsigned V_5 , struct V_65 * V_66 )
{
struct V_1 T_1 * V_6 ;
T_2 V_18 = 0xffff ;
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) F_36 ( V_66 ) ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
if ( V_5 & 1 )
V_18 <<= 16 ;
F_37 ( F_38 ( V_66 ) , V_66 ) ;
while ( 1 ) {
T_2 V_59 ;
int V_67 ;
V_59 = F_7 ( & V_6 -> V_68 ) & V_18 ;
if ( ! V_59 )
break;
F_8 ( V_59 , & V_6 -> V_68 ) ;
while ( V_59 ) {
V_67 = F_39 ( V_59 ) ;
V_59 &= ~ F_40 ( V_67 ) ;
F_41 (
F_42 ( V_14 -> V_69 ,
V_14 -> V_9 . V_41 + V_67 ) ) ;
}
}
F_43 ( F_38 ( V_66 ) , V_66 ) ;
}
static int F_44 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_14 -> V_69 )
return F_45 ( V_14 -> V_69 , V_14 -> V_9 . V_41 + V_10 ) ;
else
return - V_70 ;
}
static int F_46 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_10 < V_14 -> V_39 )
return V_14 -> V_71 + V_10 ;
else
return - V_72 ;
}
static int F_47 ( struct V_56 * V_73 , unsigned V_64 )
{
struct V_13 * V_14 ;
struct V_1 T_1 * V_6 ;
T_2 V_18 ;
V_14 = (struct V_13 * ) V_73 -> V_74 ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
V_18 = F_48 ( V_73 -> V_5 - V_14 -> V_71 ) ;
if ( V_64 & ~ ( V_60 | V_61 ) )
return - V_46 ;
F_8 ( V_18 , ( V_64 & V_60 )
? & V_6 -> V_62 : & V_6 -> V_57 ) ;
F_8 ( V_18 , ( V_64 & V_61 )
? & V_6 -> V_63 : & V_6 -> V_58 ) ;
return 0 ;
}
static int
F_49 ( struct V_69 * V_14 , unsigned int V_5 ,
T_3 V_75 )
{
struct V_1 T_1 * V_6 = F_1 ( V_75 ) ;
F_50 ( V_5 , & V_76 , V_77 ,
L_9 ) ;
F_51 ( V_5 , V_78 ) ;
F_52 ( V_5 , ( V_7 void * ) V_6 ) ;
F_53 ( V_5 , ( void * ) F_48 ( V_75 ) ) ;
F_54 ( V_5 , V_79 ) ;
return 0 ;
}
static int F_29 ( struct V_25 * V_26 )
{
unsigned V_2 , V_5 , V_80 ;
struct V_81 * V_81 ;
T_2 V_82 = 0 ;
unsigned V_38 , V_83 ;
struct V_43 * V_29 = & V_26 -> V_29 ;
struct V_44 * V_45 ;
struct V_13 * V_42 = F_55 ( V_26 ) ;
struct V_24 * V_31 = V_29 -> V_35 ;
struct V_1 T_1 * V_6 ;
struct V_69 * V_69 = NULL ;
V_38 = V_31 -> V_38 ;
V_45 = F_21 ( V_26 , V_84 , 0 ) ;
if ( ! V_45 ) {
F_18 ( V_29 , L_10 ) ;
return - V_50 ;
}
V_83 = V_45 -> V_85 ;
if ( ! V_83 ) {
F_18 ( V_29 , L_10 ) ;
return - V_72 ;
}
V_81 = F_56 ( V_29 , L_11 ) ;
if ( F_23 ( V_81 ) ) {
F_57 ( V_86 L_12 ,
F_24 ( V_81 ) ) ;
return F_24 ( V_81 ) ;
}
F_58 ( V_81 ) ;
if ( ! V_31 -> V_39 ) {
V_5 = F_59 ( - 1 , 0 , V_38 , 0 ) ;
if ( V_5 < 0 ) {
F_18 ( V_29 , L_13 ) ;
return V_5 ;
}
V_69 = F_60 ( NULL , V_38 , V_5 , 0 ,
& V_87 ,
V_42 ) ;
if ( ! V_69 ) {
F_18 ( V_29 , L_14 ) ;
return - V_72 ;
}
}
for ( V_2 = 0 , V_80 = 0 ; V_2 < V_38 ; V_80 ++ , V_2 += 32 ) {
V_42 [ V_80 ] . V_9 . V_88 = F_44 ;
V_42 [ V_80 ] . V_69 = V_69 ;
}
if ( V_31 -> V_39 ) {
static struct V_89 V_39 ;
V_42 [ 0 ] . V_9 . V_88 = F_46 ;
V_42 [ 0 ] . V_71 = V_83 ;
V_42 [ 0 ] . V_39 = V_31 -> V_39 ;
V_82 = F_40 ( 0 ) ;
V_5 = V_83 ;
V_39 = * F_61 ( F_62 ( V_5 ) ,
struct V_89 , V_9 ) ;
V_39 . V_9 . V_90 = L_15 ;
V_39 . V_9 . V_91 = F_47 ;
V_6 = F_1 ( 0 ) ;
F_8 ( ~ 0 , & V_6 -> V_62 ) ;
F_8 ( ~ 0 , & V_6 -> V_63 ) ;
for ( V_2 = 0 ; V_2 < V_31 -> V_39 ; V_2 ++ , V_5 ++ ) {
F_63 ( V_5 , & V_39 . V_9 ) ;
F_53 ( V_5 , & V_42 [ V_2 / 32 ] ) ;
F_64 ( V_5 , V_92 ) ;
}
goto V_93;
}
for ( V_2 = 0 , V_80 = 0 ; V_2 < V_38 ; V_80 ++ , V_83 ++ , V_2 += 16 ) {
V_6 = F_1 ( V_2 ) ;
F_8 ( ~ 0 , & V_6 -> V_57 ) ;
F_8 ( ~ 0 , & V_6 -> V_58 ) ;
F_65 ( V_83 , F_35 ) ;
F_53 ( V_83 , & V_42 [ V_2 / 32 ] ) ;
V_82 |= F_40 ( V_80 ) ;
}
V_93:
F_8 ( V_82 , V_4 + V_94 ) ;
return 0 ;
}
static int T_4 F_66 ( void )
{
return F_67 ( & V_95 ) ;
}
