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
static int F_19 ( struct V_8 * V_40 ,
const struct V_41 * V_42 ,
T_2 * V_16 )
{
struct V_13 * V_43 = F_20 ( V_40 -> V_29 ) ;
struct V_24 * V_31 = F_21 ( V_40 -> V_29 ) ;
if ( V_42 -> args [ 0 ] > V_31 -> V_38 )
return - V_44 ;
if ( V_40 != & V_43 [ V_42 -> args [ 0 ] / 32 ] . V_9 )
return - V_44 ;
if ( V_16 )
* V_16 = V_42 -> args [ 1 ] ;
return V_42 -> args [ 0 ] % 32 ;
}
static int F_22 ( struct V_25 * V_26 )
{
int V_45 , V_46 ;
unsigned V_38 ;
struct V_13 * V_43 ;
struct V_24 * V_31 ;
struct V_1 T_1 * V_15 ;
struct V_47 * V_29 = & V_26 -> V_29 ;
struct V_48 * V_49 ;
V_31 = F_14 ( V_26 ) ;
if ( ! V_31 ) {
F_18 ( V_29 , L_4 ) ;
return - V_44 ;
}
V_29 -> V_35 = V_31 ;
V_38 = V_31 -> V_38 ;
if ( V_38 == 0 ) {
F_18 ( V_29 , L_5 ) ;
return - V_44 ;
}
if ( F_23 ( V_50 < V_38 ) )
V_38 = V_50 ;
V_43 = F_16 ( V_29 ,
V_38 * sizeof( struct V_13 ) ,
V_36 ) ;
if ( ! V_43 ) {
F_18 ( V_29 , L_6 ) ;
return - V_51 ;
}
V_49 = F_24 ( V_26 , V_52 , 0 ) ;
if ( ! V_49 ) {
F_18 ( V_29 , L_7 ) ;
return - V_53 ;
}
V_4 = F_25 ( V_29 , V_49 ) ;
if ( F_26 ( V_4 ) )
return F_27 ( V_4 ) ;
for ( V_45 = 0 , V_46 = 0 ; V_46 < V_38 ; V_45 ++ , V_46 += 32 ) {
V_43 [ V_45 ] . V_9 . V_54 = L_8 ;
V_43 [ V_45 ] . V_9 . V_55 = F_10 ;
V_43 [ V_45 ] . V_9 . V_56 = F_12 ;
V_43 [ V_45 ] . V_9 . V_57 = F_11 ;
V_43 [ V_45 ] . V_9 . V_58 = F_13 ;
V_43 [ V_45 ] . V_9 . V_46 = V_46 ;
V_43 [ V_45 ] . V_9 . V_38 = V_38 - V_46 ;
if ( V_43 [ V_45 ] . V_9 . V_38 > 32 )
V_43 [ V_45 ] . V_9 . V_38 = 32 ;
#ifdef F_28
V_43 [ V_45 ] . V_9 . V_59 = 2 ;
V_43 [ V_45 ] . V_9 . V_60 = F_19 ;
V_43 [ V_45 ] . V_9 . V_29 = V_29 ;
V_43 [ V_45 ] . V_9 . V_30 = V_29 -> V_30 ;
#endif
F_29 ( & V_43 [ V_45 ] . V_19 ) ;
V_15 = F_1 ( V_46 ) ;
V_43 [ V_45 ] . V_15 = V_15 ;
V_43 [ V_45 ] . V_21 = & V_15 -> V_21 ;
V_43 [ V_45 ] . V_22 = & V_15 -> V_22 ;
V_43 [ V_45 ] . V_23 = & V_15 -> V_23 ;
F_30 ( & V_43 [ V_45 ] . V_9 ) ;
}
F_31 ( V_26 , V_43 ) ;
F_32 ( V_26 ) ;
return 0 ;
}
static void F_33 ( struct V_61 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_2 V_18 = ( T_2 ) F_34 ( V_14 ) ;
F_8 ( V_18 , & V_6 -> V_62 ) ;
F_8 ( V_18 , & V_6 -> V_63 ) ;
}
static void F_35 ( struct V_61 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_2 V_18 = ( T_2 ) F_34 ( V_14 ) ;
unsigned V_64 = F_36 ( V_14 ) ;
V_64 &= V_65 | V_66 ;
if ( ! V_64 )
V_64 = V_65 | V_66 ;
if ( V_64 & V_65 )
F_8 ( V_18 , & V_6 -> V_67 ) ;
if ( V_64 & V_66 )
F_8 ( V_18 , & V_6 -> V_68 ) ;
}
static int F_37 ( struct V_61 * V_14 , unsigned V_69 )
{
if ( V_69 & ~ ( V_65 | V_66 ) )
return - V_44 ;
return 0 ;
}
static void
F_38 ( unsigned V_5 , struct V_70 * V_71 )
{
struct V_1 T_1 * V_6 ;
T_2 V_18 = 0xffff ;
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) F_39 ( V_71 ) ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
if ( V_5 & 1 )
V_18 <<= 16 ;
F_40 ( F_41 ( V_71 ) , V_71 ) ;
while ( 1 ) {
T_2 V_64 ;
int V_72 ;
V_64 = F_7 ( & V_6 -> V_73 ) & V_18 ;
if ( ! V_64 )
break;
F_8 ( V_64 , & V_6 -> V_73 ) ;
while ( V_64 ) {
V_72 = F_42 ( V_64 ) ;
V_64 &= ~ F_43 ( V_72 ) ;
F_44 (
F_45 ( V_14 -> V_74 ,
V_14 -> V_9 . V_46 + V_72 ) ) ;
}
}
F_46 ( F_41 ( V_71 ) , V_71 ) ;
}
static int F_47 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_14 -> V_74 )
return F_48 ( V_14 -> V_74 , V_14 -> V_9 . V_46 + V_10 ) ;
else
return - V_75 ;
}
static int F_49 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_10 < V_14 -> V_39 )
return V_14 -> V_76 + V_10 ;
else
return - V_77 ;
}
static int F_50 ( struct V_61 * V_78 , unsigned V_69 )
{
struct V_13 * V_14 ;
struct V_1 T_1 * V_6 ;
T_2 V_18 ;
V_14 = (struct V_13 * ) V_78 -> V_79 ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
V_18 = F_51 ( V_78 -> V_5 - V_14 -> V_76 ) ;
if ( V_69 & ~ ( V_65 | V_66 ) )
return - V_44 ;
F_8 ( V_18 , ( V_69 & V_65 )
? & V_6 -> V_67 : & V_6 -> V_62 ) ;
F_8 ( V_18 , ( V_69 & V_66 )
? & V_6 -> V_68 : & V_6 -> V_63 ) ;
return 0 ;
}
static int
F_52 ( struct V_74 * V_14 , unsigned int V_5 ,
T_3 V_80 )
{
struct V_1 T_1 * V_6 = F_1 ( V_80 ) ;
F_53 ( V_5 , & V_81 , V_82 ,
L_9 ) ;
F_54 ( V_5 , V_83 ) ;
F_55 ( V_5 , ( V_7 void * ) V_6 ) ;
F_56 ( V_5 , ( void * ) F_51 ( V_80 ) ) ;
F_57 ( V_5 , V_84 ) ;
return 0 ;
}
static struct V_85 * F_58 ( unsigned int V_5 )
{
static struct V_86 V_39 ;
V_39 = * F_59 ( F_60 ( V_5 ) ,
struct V_86 , V_9 ) ;
return & V_39 . V_9 ;
}
static struct V_85 * F_61 ( unsigned int V_5 )
{
static struct V_85 V_39 ;
V_39 = * F_60 ( V_5 ) ;
return & V_39 ;
}
static int F_32 ( struct V_25 * V_26 )
{
unsigned V_2 , V_87 ;
int V_5 ;
struct V_88 * V_88 ;
T_2 V_89 = 0 ;
unsigned V_38 , V_90 ;
struct V_47 * V_29 = & V_26 -> V_29 ;
struct V_48 * V_49 ;
struct V_13 * V_43 = F_62 ( V_26 ) ;
struct V_24 * V_31 = V_29 -> V_35 ;
struct V_1 T_1 * V_6 ;
struct V_74 * V_74 = NULL ;
const struct V_91 * V_92 ;
struct V_85 * V_85 ;
T_4 V_93 ;
V_93 = F_58 ;
V_92 = F_63 ( F_64 ( V_94 ) ,
V_29 ) ;
if ( V_92 )
V_93 = ( T_4 ) V_92 -> V_78 ;
V_38 = V_31 -> V_38 ;
V_49 = F_24 ( V_26 , V_95 , 0 ) ;
if ( ! V_49 ) {
F_18 ( V_29 , L_10 ) ;
return - V_53 ;
}
V_90 = V_49 -> V_96 ;
if ( ! V_90 ) {
F_18 ( V_29 , L_10 ) ;
return - V_77 ;
}
V_88 = F_65 ( V_29 , L_11 ) ;
if ( F_26 ( V_88 ) ) {
F_66 ( V_97 L_12 ,
F_27 ( V_88 ) ) ;
return F_27 ( V_88 ) ;
}
F_67 ( V_88 ) ;
if ( ! V_31 -> V_39 ) {
V_5 = F_68 ( - 1 , 0 , V_38 , 0 ) ;
if ( V_5 < 0 ) {
F_18 ( V_29 , L_13 ) ;
return V_5 ;
}
V_74 = F_69 ( NULL , V_38 , V_5 , 0 ,
& V_98 ,
V_43 ) ;
if ( ! V_74 ) {
F_18 ( V_29 , L_14 ) ;
return - V_77 ;
}
}
for ( V_2 = 0 , V_87 = 0 ; V_2 < V_38 ; V_87 ++ , V_2 += 32 ) {
V_43 [ V_87 ] . V_9 . V_99 = F_47 ;
V_43 [ V_87 ] . V_74 = V_74 ;
}
if ( V_31 -> V_39 ) {
V_43 [ 0 ] . V_9 . V_99 = F_49 ;
V_43 [ 0 ] . V_76 = V_90 ;
V_43 [ 0 ] . V_39 = V_31 -> V_39 ;
V_89 = F_43 ( 0 ) ;
V_5 = V_90 ;
V_85 = V_93 ( V_5 ) ;
V_85 -> V_100 = L_15 ;
V_85 -> V_101 = F_50 ;
V_6 = F_1 ( 0 ) ;
F_8 ( ~ 0 , & V_6 -> V_67 ) ;
F_8 ( ~ 0 , & V_6 -> V_68 ) ;
for ( V_2 = 0 ; V_2 < V_31 -> V_39 ; V_2 ++ , V_5 ++ ) {
F_70 ( V_5 , V_85 ) ;
F_56 ( V_5 , & V_43 [ V_2 / 32 ] ) ;
F_71 ( V_5 , V_102 ) ;
}
goto V_103;
}
for ( V_2 = 0 , V_87 = 0 ; V_2 < V_38 ; V_87 ++ , V_90 ++ , V_2 += 16 ) {
V_6 = F_1 ( V_2 ) ;
F_8 ( ~ 0 , & V_6 -> V_62 ) ;
F_8 ( ~ 0 , & V_6 -> V_63 ) ;
F_72 ( V_90 , F_38 ) ;
F_56 ( V_90 , & V_43 [ V_2 / 32 ] ) ;
V_89 |= F_43 ( V_87 ) ;
}
V_103:
F_8 ( V_89 , V_4 + V_104 ) ;
return 0 ;
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_105 ) ;
}
