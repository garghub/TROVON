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
char V_51 [ V_52 ] ;
V_31 = F_14 ( V_26 ) ;
if ( ! V_31 ) {
F_19 ( V_29 , L_4 ) ;
return - V_44 ;
}
V_29 -> V_53 = V_31 ;
V_37 = V_31 -> V_37 ;
if ( V_37 == 0 ) {
F_19 ( V_29 , L_5 ) ;
return - V_44 ;
}
if ( F_23 ( V_54 < V_37 ) )
V_37 = V_54 ;
V_47 = F_24 ( V_37 , 32 ) ;
V_42 = F_17 ( V_29 ,
V_47 * sizeof( struct V_14 ) ,
V_35 ) ;
if ( ! V_42 )
return - V_55 ;
V_50 = F_25 ( V_26 , V_56 , 0 ) ;
V_4 = F_26 ( V_29 , V_50 ) ;
if ( F_27 ( V_4 ) )
return F_28 ( V_4 ) ;
for ( V_45 = 0 , V_46 = 0 ; V_46 < V_37 ; V_45 ++ , V_46 += 32 ) {
snprintf ( V_51 , V_52 , L_6 , V_45 ) ;
V_42 [ V_45 ] . V_10 . V_51 = F_29 ( V_29 , V_51 , V_35 ) ;
if ( ! V_42 [ V_45 ] . V_10 . V_51 )
return - V_55 ;
V_42 [ V_45 ] . V_10 . V_57 = F_10 ;
V_42 [ V_45 ] . V_10 . V_58 = F_12 ;
V_42 [ V_45 ] . V_10 . V_59 = F_11 ;
V_42 [ V_45 ] . V_10 . V_60 = F_13 ;
V_42 [ V_45 ] . V_10 . V_46 = V_46 ;
V_42 [ V_45 ] . V_10 . V_37 = V_37 - V_46 ;
if ( V_42 [ V_45 ] . V_10 . V_37 > 32 )
V_42 [ V_45 ] . V_10 . V_37 = 32 ;
#ifdef F_30
V_42 [ V_45 ] . V_10 . V_61 = 2 ;
V_42 [ V_45 ] . V_10 . V_62 = F_20 ;
V_42 [ V_45 ] . V_10 . V_43 = V_29 ;
V_42 [ V_45 ] . V_10 . V_30 = V_29 -> V_30 ;
#endif
F_31 ( & V_42 [ V_45 ] . V_19 ) ;
V_15 = F_1 ( V_46 ) ;
if ( ! V_15 )
return - V_63 ;
V_42 [ V_45 ] . V_15 = V_15 ;
V_42 [ V_45 ] . V_21 = & V_15 -> V_21 ;
V_42 [ V_45 ] . V_22 = & V_15 -> V_22 ;
V_42 [ V_45 ] . V_23 = & V_15 -> V_23 ;
F_32 ( & V_42 [ V_45 ] . V_10 , & V_42 [ V_45 ] ) ;
}
F_33 ( V_26 , V_42 ) ;
F_34 ( V_26 ) ;
return 0 ;
}
static void F_35 ( struct V_5 * V_6 )
{
struct V_1 T_1 * V_7 = F_2 ( V_6 ) ;
T_2 V_18 = ( T_2 ) F_36 ( V_6 ) ;
F_8 ( V_18 , & V_7 -> V_64 ) ;
F_8 ( V_18 , & V_7 -> V_65 ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
struct V_1 T_1 * V_7 = F_2 ( V_6 ) ;
T_2 V_18 = ( T_2 ) F_36 ( V_6 ) ;
unsigned V_66 = F_38 ( V_6 ) ;
V_66 &= V_67 | V_68 ;
if ( ! V_66 )
V_66 = V_67 | V_68 ;
if ( V_66 & V_67 )
F_8 ( V_18 , & V_7 -> V_69 ) ;
if ( V_66 & V_68 )
F_8 ( V_18 , & V_7 -> V_70 ) ;
}
static int F_39 ( struct V_5 * V_6 , unsigned V_71 )
{
if ( V_71 & ~ ( V_67 | V_68 ) )
return - V_44 ;
return 0 ;
}
static void F_40 ( struct V_72 * V_73 )
{
unsigned int V_74 = F_41 ( V_73 ) ;
struct V_1 T_1 * V_7 ;
T_2 V_18 = 0xffff ;
struct V_14 * V_6 ;
V_6 = (struct V_14 * ) F_42 ( V_73 ) ;
V_7 = (struct V_1 T_1 * ) V_6 -> V_15 ;
if ( V_74 & 1 )
V_18 <<= 16 ;
F_43 ( F_44 ( V_73 ) , V_73 ) ;
while ( 1 ) {
T_2 V_66 ;
int V_75 ;
V_66 = F_7 ( & V_7 -> V_76 ) & V_18 ;
if ( ! V_66 )
break;
F_8 ( V_66 , & V_7 -> V_76 ) ;
while ( V_66 ) {
V_75 = F_45 ( V_66 ) ;
V_66 &= ~ F_46 ( V_75 ) ;
F_47 (
F_48 ( V_6 -> V_77 ,
V_6 -> V_10 . V_46 + V_75 ) ) ;
}
}
F_49 ( F_44 ( V_73 ) , V_73 ) ;
}
static int F_50 ( struct V_9 * V_10 , unsigned V_11 )
{
struct V_14 * V_6 = F_5 ( V_10 ) ;
if ( V_6 -> V_77 )
return F_51 ( V_6 -> V_77 , V_6 -> V_10 . V_46 + V_11 ) ;
else
return - V_63 ;
}
static int F_52 ( struct V_9 * V_10 , unsigned V_11 )
{
struct V_14 * V_6 = F_5 ( V_10 ) ;
if ( V_11 < V_6 -> V_38 )
return V_6 -> V_78 + V_11 ;
else
return - V_79 ;
}
static int F_53 ( struct V_5 * V_80 , unsigned V_71 )
{
struct V_14 * V_6 ;
struct V_1 T_1 * V_7 ;
T_2 V_18 ;
V_6 = (struct V_14 * ) F_36 ( V_80 ) ;
V_7 = (struct V_1 T_1 * ) V_6 -> V_15 ;
V_18 = F_54 ( V_80 -> V_74 - V_6 -> V_78 ) ;
if ( V_71 & ~ ( V_67 | V_68 ) )
return - V_44 ;
F_8 ( V_18 , ( V_71 & V_67 )
? & V_7 -> V_69 : & V_7 -> V_64 ) ;
F_8 ( V_18 , ( V_71 & V_68 )
? & V_7 -> V_70 : & V_7 -> V_65 ) ;
return 0 ;
}
static int
F_55 ( struct V_77 * V_6 , unsigned int V_74 ,
T_3 V_81 )
{
struct V_1 T_1 * V_7 = F_1 ( V_81 ) ;
F_56 ( V_74 , & V_82 , V_83 ,
L_7 ) ;
F_57 ( V_74 , V_84 ) ;
F_58 ( V_74 , ( V_8 void * ) V_7 ) ;
F_59 ( V_74 , ( void * ) F_54 ( V_81 ) ) ;
return 0 ;
}
static struct V_85 * F_60 ( unsigned int V_74 )
{
static struct V_86 V_38 ;
V_38 = * F_61 ( F_62 ( V_74 ) ) ;
return & V_38 . V_10 ;
}
static struct V_85 * F_63 ( unsigned int V_74 )
{
static struct V_85 V_38 ;
V_38 = * F_64 ( V_74 ) ;
return & V_38 ;
}
static int F_34 ( struct V_25 * V_26 )
{
unsigned V_2 , V_87 ;
int V_74 ;
struct V_88 * V_88 ;
T_2 V_89 = 0 ;
unsigned V_37 , V_90 ;
struct V_48 * V_29 = & V_26 -> V_29 ;
struct V_49 * V_50 ;
struct V_14 * V_42 = F_65 ( V_26 ) ;
struct V_24 * V_31 = V_29 -> V_53 ;
struct V_1 T_1 * V_7 ;
struct V_77 * V_77 = NULL ;
const struct V_91 * V_92 ;
struct V_85 * V_85 ;
T_4 V_93 ;
V_93 = F_60 ;
V_92 = F_66 ( F_67 ( V_94 ) ,
V_29 ) ;
if ( V_92 )
V_93 = ( T_4 ) V_92 -> V_80 ;
V_37 = V_31 -> V_37 ;
V_50 = F_25 ( V_26 , V_95 , 0 ) ;
if ( ! V_50 ) {
F_19 ( V_29 , L_8 ) ;
return - V_96 ;
}
V_90 = V_50 -> V_97 ;
if ( ! V_90 ) {
F_19 ( V_29 , L_8 ) ;
return - V_79 ;
}
V_88 = F_68 ( V_29 , L_9 ) ;
if ( F_27 ( V_88 ) ) {
F_69 ( V_98 L_10 ,
F_28 ( V_88 ) ) ;
return F_28 ( V_88 ) ;
}
F_70 ( V_88 ) ;
if ( ! V_31 -> V_38 ) {
V_74 = F_71 ( - 1 , 0 , V_37 , 0 ) ;
if ( V_74 < 0 ) {
F_19 ( V_29 , L_11 ) ;
return V_74 ;
}
V_77 = F_72 ( V_29 -> V_30 , V_37 , V_74 , 0 ,
& V_99 ,
V_42 ) ;
if ( ! V_77 ) {
F_19 ( V_29 , L_12 ) ;
return - V_79 ;
}
}
for ( V_2 = 0 , V_87 = 0 ; V_2 < V_37 ; V_87 ++ , V_2 += 32 ) {
V_42 [ V_87 ] . V_10 . V_100 = F_50 ;
V_42 [ V_87 ] . V_77 = V_77 ;
}
if ( V_31 -> V_38 ) {
V_42 [ 0 ] . V_10 . V_100 = F_52 ;
V_42 [ 0 ] . V_78 = V_90 ;
V_42 [ 0 ] . V_38 = V_31 -> V_38 ;
V_89 = F_73 ( V_31 -> V_38 / 16 , 0 ) ;
V_74 = V_90 ;
V_85 = V_93 ( V_74 ) ;
V_85 -> V_101 = L_13 ;
V_85 -> V_102 = F_53 ;
V_7 = F_1 ( 0 ) ;
F_8 ( ~ 0 , & V_7 -> V_69 ) ;
F_8 ( ~ 0 , & V_7 -> V_70 ) ;
for ( V_2 = 0 ; V_2 < V_31 -> V_38 ; V_2 ++ , V_74 ++ ) {
F_74 ( V_74 , V_85 ) ;
F_59 ( V_74 , & V_42 [ V_2 / 32 ] ) ;
F_75 ( V_74 , V_103 ) ;
}
goto V_104;
}
for ( V_2 = 0 , V_87 = 0 ; V_2 < V_37 ; V_87 ++ , V_90 ++ , V_2 += 16 ) {
V_7 = F_1 ( V_2 ) ;
F_8 ( ~ 0 , & V_7 -> V_64 ) ;
F_8 ( ~ 0 , & V_7 -> V_65 ) ;
F_76 ( V_90 , F_40 ,
& V_42 [ V_2 / 32 ] ) ;
V_89 |= F_46 ( V_87 ) ;
}
V_104:
F_8 ( V_89 , V_4 + V_105 ) ;
return 0 ;
}
static int T_5 F_77 ( void )
{
return F_78 ( & V_106 ) ;
}
