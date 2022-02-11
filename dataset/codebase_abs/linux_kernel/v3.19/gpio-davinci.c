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
if ( ! V_43 )
return - V_51 ;
V_49 = F_24 ( V_26 , V_52 , 0 ) ;
V_4 = F_25 ( V_29 , V_49 ) ;
if ( F_26 ( V_4 ) )
return F_27 ( V_4 ) ;
for ( V_45 = 0 , V_46 = 0 ; V_46 < V_38 ; V_45 ++ , V_46 += 32 ) {
V_43 [ V_45 ] . V_9 . V_53 = L_6 ;
V_43 [ V_45 ] . V_9 . V_54 = F_10 ;
V_43 [ V_45 ] . V_9 . V_55 = F_12 ;
V_43 [ V_45 ] . V_9 . V_56 = F_11 ;
V_43 [ V_45 ] . V_9 . V_57 = F_13 ;
V_43 [ V_45 ] . V_9 . V_46 = V_46 ;
V_43 [ V_45 ] . V_9 . V_38 = V_38 - V_46 ;
if ( V_43 [ V_45 ] . V_9 . V_38 > 32 )
V_43 [ V_45 ] . V_9 . V_38 = 32 ;
#ifdef F_28
V_43 [ V_45 ] . V_9 . V_58 = 2 ;
V_43 [ V_45 ] . V_9 . V_59 = F_19 ;
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
static void F_33 ( struct V_60 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_2 V_18 = ( T_2 ) F_34 ( V_14 ) ;
F_8 ( V_18 , & V_6 -> V_61 ) ;
F_8 ( V_18 , & V_6 -> V_62 ) ;
}
static void F_35 ( struct V_60 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_2 V_18 = ( T_2 ) F_34 ( V_14 ) ;
unsigned V_63 = F_36 ( V_14 ) ;
V_63 &= V_64 | V_65 ;
if ( ! V_63 )
V_63 = V_64 | V_65 ;
if ( V_63 & V_64 )
F_8 ( V_18 , & V_6 -> V_66 ) ;
if ( V_63 & V_65 )
F_8 ( V_18 , & V_6 -> V_67 ) ;
}
static int F_37 ( struct V_60 * V_14 , unsigned V_68 )
{
if ( V_68 & ~ ( V_64 | V_65 ) )
return - V_44 ;
return 0 ;
}
static void
F_38 ( unsigned V_5 , struct V_69 * V_70 )
{
struct V_1 T_1 * V_6 ;
T_2 V_18 = 0xffff ;
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) F_39 ( V_70 ) ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
if ( V_5 & 1 )
V_18 <<= 16 ;
F_40 ( F_41 ( V_70 ) , V_70 ) ;
while ( 1 ) {
T_2 V_63 ;
int V_71 ;
V_63 = F_7 ( & V_6 -> V_72 ) & V_18 ;
if ( ! V_63 )
break;
F_8 ( V_63 , & V_6 -> V_72 ) ;
while ( V_63 ) {
V_71 = F_42 ( V_63 ) ;
V_63 &= ~ F_43 ( V_71 ) ;
F_44 (
F_45 ( V_14 -> V_73 ,
V_14 -> V_9 . V_46 + V_71 ) ) ;
}
}
F_46 ( F_41 ( V_70 ) , V_70 ) ;
}
static int F_47 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_14 -> V_73 )
return F_48 ( V_14 -> V_73 , V_14 -> V_9 . V_46 + V_10 ) ;
else
return - V_74 ;
}
static int F_49 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_10 < V_14 -> V_39 )
return V_14 -> V_75 + V_10 ;
else
return - V_76 ;
}
static int F_50 ( struct V_60 * V_77 , unsigned V_68 )
{
struct V_13 * V_14 ;
struct V_1 T_1 * V_6 ;
T_2 V_18 ;
V_14 = (struct V_13 * ) V_77 -> V_78 ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
V_18 = F_51 ( V_77 -> V_5 - V_14 -> V_75 ) ;
if ( V_68 & ~ ( V_64 | V_65 ) )
return - V_44 ;
F_8 ( V_18 , ( V_68 & V_64 )
? & V_6 -> V_66 : & V_6 -> V_61 ) ;
F_8 ( V_18 , ( V_68 & V_65 )
? & V_6 -> V_67 : & V_6 -> V_62 ) ;
return 0 ;
}
static int
F_52 ( struct V_73 * V_14 , unsigned int V_5 ,
T_3 V_79 )
{
struct V_1 T_1 * V_6 = F_1 ( V_79 ) ;
F_53 ( V_5 , & V_80 , V_81 ,
L_7 ) ;
F_54 ( V_5 , V_82 ) ;
F_55 ( V_5 , ( V_7 void * ) V_6 ) ;
F_56 ( V_5 , ( void * ) F_51 ( V_79 ) ) ;
F_57 ( V_5 , V_83 ) ;
return 0 ;
}
static struct V_84 * F_58 ( unsigned int V_5 )
{
static struct V_85 V_39 ;
V_39 = * F_59 ( F_60 ( V_5 ) ,
struct V_85 , V_9 ) ;
return & V_39 . V_9 ;
}
static struct V_84 * F_61 ( unsigned int V_5 )
{
static struct V_84 V_39 ;
V_39 = * F_60 ( V_5 ) ;
return & V_39 ;
}
static int F_32 ( struct V_25 * V_26 )
{
unsigned V_2 , V_86 ;
int V_5 ;
struct V_87 * V_87 ;
T_2 V_88 = 0 ;
unsigned V_38 , V_89 ;
struct V_47 * V_29 = & V_26 -> V_29 ;
struct V_48 * V_49 ;
struct V_13 * V_43 = F_62 ( V_26 ) ;
struct V_24 * V_31 = V_29 -> V_35 ;
struct V_1 T_1 * V_6 ;
struct V_73 * V_73 = NULL ;
const struct V_90 * V_91 ;
struct V_84 * V_84 ;
T_4 V_92 ;
V_92 = F_58 ;
V_91 = F_63 ( F_64 ( V_93 ) ,
V_29 ) ;
if ( V_91 )
V_92 = ( T_4 ) V_91 -> V_77 ;
V_38 = V_31 -> V_38 ;
V_49 = F_24 ( V_26 , V_94 , 0 ) ;
if ( ! V_49 ) {
F_18 ( V_29 , L_8 ) ;
return - V_95 ;
}
V_89 = V_49 -> V_96 ;
if ( ! V_89 ) {
F_18 ( V_29 , L_8 ) ;
return - V_76 ;
}
V_87 = F_65 ( V_29 , L_9 ) ;
if ( F_26 ( V_87 ) ) {
F_66 ( V_97 L_10 ,
F_27 ( V_87 ) ) ;
return F_27 ( V_87 ) ;
}
F_67 ( V_87 ) ;
if ( ! V_31 -> V_39 ) {
V_5 = F_68 ( - 1 , 0 , V_38 , 0 ) ;
if ( V_5 < 0 ) {
F_18 ( V_29 , L_11 ) ;
return V_5 ;
}
V_73 = F_69 ( NULL , V_38 , V_5 , 0 ,
& V_98 ,
V_43 ) ;
if ( ! V_73 ) {
F_18 ( V_29 , L_12 ) ;
return - V_76 ;
}
}
for ( V_2 = 0 , V_86 = 0 ; V_2 < V_38 ; V_86 ++ , V_2 += 32 ) {
V_43 [ V_86 ] . V_9 . V_99 = F_47 ;
V_43 [ V_86 ] . V_73 = V_73 ;
}
if ( V_31 -> V_39 ) {
V_43 [ 0 ] . V_9 . V_99 = F_49 ;
V_43 [ 0 ] . V_75 = V_89 ;
V_43 [ 0 ] . V_39 = V_31 -> V_39 ;
V_88 = F_43 ( 0 ) ;
V_5 = V_89 ;
V_84 = V_92 ( V_5 ) ;
V_84 -> V_100 = L_13 ;
V_84 -> V_101 = F_50 ;
V_6 = F_1 ( 0 ) ;
F_8 ( ~ 0 , & V_6 -> V_66 ) ;
F_8 ( ~ 0 , & V_6 -> V_67 ) ;
for ( V_2 = 0 ; V_2 < V_31 -> V_39 ; V_2 ++ , V_5 ++ ) {
F_70 ( V_5 , V_84 ) ;
F_56 ( V_5 , & V_43 [ V_2 / 32 ] ) ;
F_71 ( V_5 , V_102 ) ;
}
goto V_103;
}
for ( V_2 = 0 , V_86 = 0 ; V_2 < V_38 ; V_86 ++ , V_89 ++ , V_2 += 16 ) {
V_6 = F_1 ( V_2 ) ;
F_8 ( ~ 0 , & V_6 -> V_61 ) ;
F_8 ( ~ 0 , & V_6 -> V_62 ) ;
F_72 ( V_89 , F_38 ) ;
F_56 ( V_89 , & V_43 [ V_2 / 32 ] ) ;
V_88 |= F_43 ( V_86 ) ;
}
V_103:
F_8 ( V_88 , V_4 + V_104 ) ;
return 0 ;
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_105 ) ;
}
