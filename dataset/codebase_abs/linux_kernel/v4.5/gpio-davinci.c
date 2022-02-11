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
static inline struct V_1 T_1 * F_2 ( struct V_5 * V_6 )
{
struct V_1 T_1 * V_7 ;
V_7 = ( V_8 struct V_1 T_1 * ) F_3 ( V_6 ) ;
return V_7 ;
}
static inline int F_4 ( struct V_9 * V_10 ,
unsigned V_11 , bool V_12 , int V_13 )
{
struct V_14 * V_6 = F_5 ( V_10 ) ;
struct V_1 T_1 * V_7 = V_6 -> V_15 ;
unsigned long V_16 ;
T_2 V_17 ;
T_2 V_18 = 1 << V_11 ;
F_6 ( & V_6 -> V_19 , V_16 ) ;
V_17 = F_7 ( & V_7 -> V_20 ) ;
if ( V_12 ) {
V_17 &= ~ V_18 ;
F_8 ( V_18 , V_13 ? & V_7 -> V_21 : & V_7 -> V_22 ) ;
} else {
V_17 |= V_18 ;
}
F_8 ( V_17 , & V_7 -> V_20 ) ;
F_9 ( & V_6 -> V_19 , V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , unsigned V_11 )
{
return F_4 ( V_10 , V_11 , false , 0 ) ;
}
static int
F_11 ( struct V_9 * V_10 , unsigned V_11 , int V_13 )
{
return F_4 ( V_10 , V_11 , true , V_13 ) ;
}
static int F_12 ( struct V_9 * V_10 , unsigned V_11 )
{
struct V_14 * V_6 = F_5 ( V_10 ) ;
struct V_1 T_1 * V_7 = V_6 -> V_15 ;
return ! ! ( ( 1 << V_11 ) & F_7 ( & V_7 -> V_23 ) ) ;
}
static void
F_13 ( struct V_9 * V_10 , unsigned V_11 , int V_13 )
{
struct V_14 * V_6 = F_5 ( V_10 ) ;
struct V_1 T_1 * V_7 = V_6 -> V_15 ;
F_8 ( ( 1 << V_11 ) , V_13 ? & V_7 -> V_21 : & V_7 -> V_22 ) ;
}
static struct V_24 *
F_14 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_29 . V_30 ;
struct V_24 * V_31 ;
int V_32 ;
T_2 V_33 ;
if ( ! F_15 ( V_34 ) || ! V_26 -> V_29 . V_30 )
return F_16 ( & V_26 -> V_29 ) ;
V_31 = F_17 ( & V_26 -> V_29 , sizeof( * V_31 ) , V_35 ) ;
if ( ! V_31 )
return NULL ;
V_32 = F_18 ( V_28 , L_1 , & V_33 ) ;
if ( V_32 )
goto V_36;
V_31 -> V_37 = V_33 ;
V_32 = F_18 ( V_28 , L_2 , & V_33 ) ;
if ( V_32 )
goto V_36;
V_31 -> V_38 = V_33 ;
return V_31 ;
V_36:
F_19 ( & V_26 -> V_29 , L_3 , V_32 ) ;
return NULL ;
}
static int F_20 ( struct V_9 * V_39 ,
const struct V_40 * V_41 ,
T_2 * V_16 )
{
struct V_14 * V_42 = F_21 ( V_39 -> V_43 ) ;
struct V_24 * V_31 = F_16 ( V_39 -> V_43 ) ;
if ( V_41 -> args [ 0 ] > V_31 -> V_37 )
return - V_44 ;
if ( V_39 != & V_42 [ V_41 -> args [ 0 ] / 32 ] . V_10 )
return - V_44 ;
if ( V_16 )
* V_16 = V_41 -> args [ 1 ] ;
return V_41 -> args [ 0 ] % 32 ;
}
static int F_22 ( struct V_25 * V_26 )
{
int V_45 , V_46 ;
unsigned V_37 , V_47 ;
struct V_14 * V_42 ;
struct V_24 * V_31 ;
struct V_1 T_1 * V_15 ;
struct V_48 * V_29 = & V_26 -> V_29 ;
struct V_49 * V_50 ;
V_31 = F_14 ( V_26 ) ;
if ( ! V_31 ) {
F_19 ( V_29 , L_4 ) ;
return - V_44 ;
}
V_29 -> V_51 = V_31 ;
V_37 = V_31 -> V_37 ;
if ( V_37 == 0 ) {
F_19 ( V_29 , L_5 ) ;
return - V_44 ;
}
if ( F_23 ( V_52 < V_37 ) )
V_37 = V_52 ;
V_47 = F_24 ( V_37 , 32 ) ;
V_42 = F_17 ( V_29 ,
V_47 * sizeof( struct V_14 ) ,
V_35 ) ;
if ( ! V_42 )
return - V_53 ;
V_50 = F_25 ( V_26 , V_54 , 0 ) ;
V_4 = F_26 ( V_29 , V_50 ) ;
if ( F_27 ( V_4 ) )
return F_28 ( V_4 ) ;
for ( V_45 = 0 , V_46 = 0 ; V_46 < V_37 ; V_45 ++ , V_46 += 32 ) {
V_42 [ V_45 ] . V_10 . V_55 = L_6 ;
V_42 [ V_45 ] . V_10 . V_56 = F_10 ;
V_42 [ V_45 ] . V_10 . V_57 = F_12 ;
V_42 [ V_45 ] . V_10 . V_58 = F_11 ;
V_42 [ V_45 ] . V_10 . V_59 = F_13 ;
V_42 [ V_45 ] . V_10 . V_46 = V_46 ;
V_42 [ V_45 ] . V_10 . V_37 = V_37 - V_46 ;
if ( V_42 [ V_45 ] . V_10 . V_37 > 32 )
V_42 [ V_45 ] . V_10 . V_37 = 32 ;
#ifdef F_29
V_42 [ V_45 ] . V_10 . V_60 = 2 ;
V_42 [ V_45 ] . V_10 . V_61 = F_20 ;
V_42 [ V_45 ] . V_10 . V_43 = V_29 ;
V_42 [ V_45 ] . V_10 . V_30 = V_29 -> V_30 ;
#endif
F_30 ( & V_42 [ V_45 ] . V_19 ) ;
V_15 = F_1 ( V_46 ) ;
V_42 [ V_45 ] . V_15 = V_15 ;
V_42 [ V_45 ] . V_21 = & V_15 -> V_21 ;
V_42 [ V_45 ] . V_22 = & V_15 -> V_22 ;
V_42 [ V_45 ] . V_23 = & V_15 -> V_23 ;
F_31 ( & V_42 [ V_45 ] . V_10 , & V_42 [ V_45 ] ) ;
}
F_32 ( V_26 , V_42 ) ;
F_33 ( V_26 ) ;
return 0 ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_1 T_1 * V_7 = F_2 ( V_6 ) ;
T_2 V_18 = ( T_2 ) F_35 ( V_6 ) ;
F_8 ( V_18 , & V_7 -> V_62 ) ;
F_8 ( V_18 , & V_7 -> V_63 ) ;
}
static void F_36 ( struct V_5 * V_6 )
{
struct V_1 T_1 * V_7 = F_2 ( V_6 ) ;
T_2 V_18 = ( T_2 ) F_35 ( V_6 ) ;
unsigned V_64 = F_37 ( V_6 ) ;
V_64 &= V_65 | V_66 ;
if ( ! V_64 )
V_64 = V_65 | V_66 ;
if ( V_64 & V_65 )
F_8 ( V_18 , & V_7 -> V_67 ) ;
if ( V_64 & V_66 )
F_8 ( V_18 , & V_7 -> V_68 ) ;
}
static int F_38 ( struct V_5 * V_6 , unsigned V_69 )
{
if ( V_69 & ~ ( V_65 | V_66 ) )
return - V_44 ;
return 0 ;
}
static void F_39 ( struct V_70 * V_71 )
{
unsigned int V_72 = F_40 ( V_71 ) ;
struct V_1 T_1 * V_7 ;
T_2 V_18 = 0xffff ;
struct V_14 * V_6 ;
V_6 = (struct V_14 * ) F_41 ( V_71 ) ;
V_7 = (struct V_1 T_1 * ) V_6 -> V_15 ;
if ( V_72 & 1 )
V_18 <<= 16 ;
F_42 ( F_43 ( V_71 ) , V_71 ) ;
while ( 1 ) {
T_2 V_64 ;
int V_73 ;
V_64 = F_7 ( & V_7 -> V_74 ) & V_18 ;
if ( ! V_64 )
break;
F_8 ( V_64 , & V_7 -> V_74 ) ;
while ( V_64 ) {
V_73 = F_44 ( V_64 ) ;
V_64 &= ~ F_45 ( V_73 ) ;
F_46 (
F_47 ( V_6 -> V_75 ,
V_6 -> V_10 . V_46 + V_73 ) ) ;
}
}
F_48 ( F_43 ( V_71 ) , V_71 ) ;
}
static int F_49 ( struct V_9 * V_10 , unsigned V_11 )
{
struct V_14 * V_6 = F_5 ( V_10 ) ;
if ( V_6 -> V_75 )
return F_50 ( V_6 -> V_75 , V_6 -> V_10 . V_46 + V_11 ) ;
else
return - V_76 ;
}
static int F_51 ( struct V_9 * V_10 , unsigned V_11 )
{
struct V_14 * V_6 = F_5 ( V_10 ) ;
if ( V_11 < V_6 -> V_38 )
return V_6 -> V_77 + V_11 ;
else
return - V_78 ;
}
static int F_52 ( struct V_5 * V_79 , unsigned V_69 )
{
struct V_14 * V_6 ;
struct V_1 T_1 * V_7 ;
T_2 V_18 ;
V_6 = (struct V_14 * ) F_35 ( V_79 ) ;
V_7 = (struct V_1 T_1 * ) V_6 -> V_15 ;
V_18 = F_53 ( V_79 -> V_72 - V_6 -> V_77 ) ;
if ( V_69 & ~ ( V_65 | V_66 ) )
return - V_44 ;
F_8 ( V_18 , ( V_69 & V_65 )
? & V_7 -> V_67 : & V_7 -> V_62 ) ;
F_8 ( V_18 , ( V_69 & V_66 )
? & V_7 -> V_68 : & V_7 -> V_63 ) ;
return 0 ;
}
static int
F_54 ( struct V_75 * V_6 , unsigned int V_72 ,
T_3 V_80 )
{
struct V_1 T_1 * V_7 = F_1 ( V_80 ) ;
F_55 ( V_72 , & V_81 , V_82 ,
L_7 ) ;
F_56 ( V_72 , V_83 ) ;
F_57 ( V_72 , ( V_8 void * ) V_7 ) ;
F_58 ( V_72 , ( void * ) F_53 ( V_80 ) ) ;
return 0 ;
}
static struct V_84 * F_59 ( unsigned int V_72 )
{
static struct V_85 V_38 ;
V_38 = * F_60 ( F_61 ( V_72 ) ,
struct V_85 , V_10 ) ;
return & V_38 . V_10 ;
}
static struct V_84 * F_62 ( unsigned int V_72 )
{
static struct V_84 V_38 ;
V_38 = * F_61 ( V_72 ) ;
return & V_38 ;
}
static int F_33 ( struct V_25 * V_26 )
{
unsigned V_2 , V_86 ;
int V_72 ;
struct V_87 * V_87 ;
T_2 V_88 = 0 ;
unsigned V_37 , V_89 ;
struct V_48 * V_29 = & V_26 -> V_29 ;
struct V_49 * V_50 ;
struct V_14 * V_42 = F_63 ( V_26 ) ;
struct V_24 * V_31 = V_29 -> V_51 ;
struct V_1 T_1 * V_7 ;
struct V_75 * V_75 = NULL ;
const struct V_90 * V_91 ;
struct V_84 * V_84 ;
T_4 V_92 ;
V_92 = F_59 ;
V_91 = F_64 ( F_65 ( V_93 ) ,
V_29 ) ;
if ( V_91 )
V_92 = ( T_4 ) V_91 -> V_79 ;
V_37 = V_31 -> V_37 ;
V_50 = F_25 ( V_26 , V_94 , 0 ) ;
if ( ! V_50 ) {
F_19 ( V_29 , L_8 ) ;
return - V_95 ;
}
V_89 = V_50 -> V_96 ;
if ( ! V_89 ) {
F_19 ( V_29 , L_8 ) ;
return - V_78 ;
}
V_87 = F_66 ( V_29 , L_9 ) ;
if ( F_27 ( V_87 ) ) {
F_67 ( V_97 L_10 ,
F_28 ( V_87 ) ) ;
return F_28 ( V_87 ) ;
}
F_68 ( V_87 ) ;
if ( ! V_31 -> V_38 ) {
V_72 = F_69 ( - 1 , 0 , V_37 , 0 ) ;
if ( V_72 < 0 ) {
F_19 ( V_29 , L_11 ) ;
return V_72 ;
}
V_75 = F_70 ( V_29 -> V_30 , V_37 , V_72 , 0 ,
& V_98 ,
V_42 ) ;
if ( ! V_75 ) {
F_19 ( V_29 , L_12 ) ;
return - V_78 ;
}
}
for ( V_2 = 0 , V_86 = 0 ; V_2 < V_37 ; V_86 ++ , V_2 += 32 ) {
V_42 [ V_86 ] . V_10 . V_99 = F_49 ;
V_42 [ V_86 ] . V_75 = V_75 ;
}
if ( V_31 -> V_38 ) {
V_42 [ 0 ] . V_10 . V_99 = F_51 ;
V_42 [ 0 ] . V_77 = V_89 ;
V_42 [ 0 ] . V_38 = V_31 -> V_38 ;
V_88 = F_71 ( V_31 -> V_38 / 16 , 0 ) ;
V_72 = V_89 ;
V_84 = V_92 ( V_72 ) ;
V_84 -> V_100 = L_13 ;
V_84 -> V_101 = F_52 ;
V_7 = F_1 ( 0 ) ;
F_8 ( ~ 0 , & V_7 -> V_67 ) ;
F_8 ( ~ 0 , & V_7 -> V_68 ) ;
for ( V_2 = 0 ; V_2 < V_31 -> V_38 ; V_2 ++ , V_72 ++ ) {
F_72 ( V_72 , V_84 ) ;
F_58 ( V_72 , & V_42 [ V_2 / 32 ] ) ;
F_73 ( V_72 , V_102 ) ;
}
goto V_103;
}
for ( V_2 = 0 , V_86 = 0 ; V_2 < V_37 ; V_86 ++ , V_89 ++ , V_2 += 16 ) {
V_7 = F_1 ( V_2 ) ;
F_8 ( ~ 0 , & V_7 -> V_62 ) ;
F_8 ( ~ 0 , & V_7 -> V_63 ) ;
F_74 ( V_89 , F_39 ,
& V_42 [ V_2 / 32 ] ) ;
V_88 |= F_45 ( V_86 ) ;
}
V_103:
F_8 ( V_88 , V_4 + V_104 ) ;
return 0 ;
}
static int T_5 F_75 ( void )
{
return F_76 ( & V_105 ) ;
}
