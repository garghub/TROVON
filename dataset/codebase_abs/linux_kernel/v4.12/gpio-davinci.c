static inline struct V_1 T_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_4 ;
V_4 = ( V_5 struct V_1 T_1 * ) F_2 ( V_3 ) ;
return V_4 ;
}
static inline int F_3 ( struct V_6 * V_7 ,
unsigned V_8 , bool V_9 , int V_10 )
{
struct V_11 * V_3 = F_4 ( V_7 ) ;
struct V_1 T_1 * V_4 ;
unsigned long V_12 ;
T_2 V_13 ;
int V_14 = V_8 / 32 ;
T_2 V_15 = F_5 ( V_8 ) ;
V_4 = V_3 -> V_16 [ V_14 ] ;
F_6 ( & V_3 -> V_17 , V_12 ) ;
V_13 = F_7 ( & V_4 -> V_18 ) ;
if ( V_9 ) {
V_13 &= ~ V_15 ;
F_8 ( V_15 , V_10 ? & V_4 -> V_19 : & V_4 -> V_20 ) ;
} else {
V_13 |= V_15 ;
}
F_8 ( V_13 , & V_4 -> V_18 ) ;
F_9 ( & V_3 -> V_17 , V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , unsigned V_8 )
{
return F_3 ( V_7 , V_8 , false , 0 ) ;
}
static int
F_11 ( struct V_6 * V_7 , unsigned V_8 , int V_10 )
{
return F_3 ( V_7 , V_8 , true , V_10 ) ;
}
static int F_12 ( struct V_6 * V_7 , unsigned V_8 )
{
struct V_11 * V_3 = F_4 ( V_7 ) ;
struct V_1 T_1 * V_4 ;
int V_14 = V_8 / 32 ;
V_4 = V_3 -> V_16 [ V_14 ] ;
return ! ! ( F_5 ( V_8 ) & F_7 ( & V_4 -> V_21 ) ) ;
}
static void
F_13 ( struct V_6 * V_7 , unsigned V_8 , int V_10 )
{
struct V_11 * V_3 = F_4 ( V_7 ) ;
struct V_1 T_1 * V_4 ;
int V_14 = V_8 / 32 ;
V_4 = V_3 -> V_16 [ V_14 ] ;
F_8 ( F_5 ( V_8 ) ,
V_10 ? & V_4 -> V_19 : & V_4 -> V_20 ) ;
}
static struct V_22 *
F_14 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 . V_28 ;
struct V_22 * V_29 ;
int V_30 ;
T_2 V_31 ;
if ( ! F_15 ( V_32 ) || ! V_24 -> V_27 . V_28 )
return F_16 ( & V_24 -> V_27 ) ;
V_29 = F_17 ( & V_24 -> V_27 , sizeof( * V_29 ) , V_33 ) ;
if ( ! V_29 )
return NULL ;
V_30 = F_18 ( V_26 , L_1 , & V_31 ) ;
if ( V_30 )
goto V_34;
V_29 -> V_35 = V_31 ;
V_30 = F_18 ( V_26 , L_2 , & V_31 ) ;
if ( V_30 )
goto V_34;
V_29 -> V_36 = V_31 ;
return V_29 ;
V_34:
F_19 ( & V_24 -> V_27 , L_3 , V_30 ) ;
return NULL ;
}
static int F_20 ( struct V_23 * V_24 )
{
static int V_37 , V_38 ;
int V_39 , V_14 ;
unsigned V_35 , V_40 ;
struct V_11 * V_41 ;
struct V_22 * V_29 ;
struct V_42 * V_27 = & V_24 -> V_27 ;
struct V_43 * V_44 ;
char V_45 [ V_46 ] ;
V_29 = F_14 ( V_24 ) ;
if ( ! V_29 ) {
F_19 ( V_27 , L_4 ) ;
return - V_47 ;
}
V_27 -> V_48 = V_29 ;
V_35 = V_29 -> V_35 ;
if ( V_35 == 0 ) {
F_19 ( V_27 , L_5 ) ;
return - V_47 ;
}
if ( F_21 ( V_49 < V_35 ) )
V_35 = V_49 ;
V_40 = F_22 ( V_35 , 32 ) ;
V_41 = F_17 ( V_27 ,
V_40 * sizeof( struct V_11 ) ,
V_33 ) ;
if ( ! V_41 )
return - V_50 ;
V_44 = F_23 ( V_24 , V_51 , 0 ) ;
V_52 = F_24 ( V_27 , V_44 ) ;
if ( F_25 ( V_52 ) )
return F_26 ( V_52 ) ;
snprintf ( V_45 , V_46 , L_6 , V_37 ++ ) ;
V_41 -> V_7 . V_45 = F_27 ( V_27 , V_45 , V_33 ) ;
if ( ! V_41 -> V_7 . V_45 )
return - V_50 ;
V_41 -> V_7 . V_53 = F_10 ;
V_41 -> V_7 . V_54 = F_12 ;
V_41 -> V_7 . V_55 = F_11 ;
V_41 -> V_7 . V_56 = F_13 ;
V_41 -> V_7 . V_35 = V_35 ;
V_41 -> V_7 . V_57 = V_38 ;
#ifdef F_28
V_41 -> V_7 . V_58 = 2 ;
V_41 -> V_7 . V_59 = V_27 ;
V_41 -> V_7 . V_28 = V_27 -> V_28 ;
#endif
F_29 ( & V_41 -> V_17 ) ;
V_38 += V_35 ;
for ( V_39 = 0 , V_14 = 0 ; V_39 < V_35 ; V_39 += 32 , V_14 ++ )
V_41 -> V_16 [ V_14 ] = V_52 + V_60 [ V_14 ] ;
F_30 ( & V_41 -> V_7 , V_41 ) ;
F_31 ( V_24 , V_41 ) ;
F_32 ( V_24 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_15 = ( T_2 ) F_34 ( V_3 ) ;
F_8 ( V_15 , & V_4 -> V_61 ) ;
F_8 ( V_15 , & V_4 -> V_62 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_15 = ( T_2 ) F_34 ( V_3 ) ;
unsigned V_63 = F_36 ( V_3 ) ;
V_63 &= V_64 | V_65 ;
if ( ! V_63 )
V_63 = V_64 | V_65 ;
if ( V_63 & V_64 )
F_8 ( V_15 , & V_4 -> V_66 ) ;
if ( V_63 & V_65 )
F_8 ( V_15 , & V_4 -> V_67 ) ;
}
static int F_37 ( struct V_2 * V_3 , unsigned V_68 )
{
if ( V_68 & ~ ( V_64 | V_65 ) )
return - V_47 ;
return 0 ;
}
static void F_38 ( struct V_69 * V_70 )
{
struct V_1 T_1 * V_4 ;
T_2 V_15 = 0xffff ;
int V_71 ;
struct V_11 * V_3 ;
struct V_72 * V_73 ;
V_73 = (struct V_72 * ) F_39 ( V_70 ) ;
V_71 = V_73 -> V_71 ;
V_4 = V_73 -> V_16 ;
V_3 = V_73 -> V_7 ;
if ( ( V_71 % 2 ) == 1 )
V_15 <<= 16 ;
F_40 ( F_41 ( V_70 ) , V_70 ) ;
while ( 1 ) {
T_2 V_63 ;
int V_74 ;
T_3 V_75 ;
V_63 = F_7 ( & V_4 -> V_76 ) & V_15 ;
if ( ! V_63 )
break;
F_8 ( V_63 , & V_4 -> V_76 ) ;
while ( V_63 ) {
V_74 = F_42 ( V_63 ) ;
V_63 &= ~ F_43 ( V_74 ) ;
V_75 = ( V_71 / 2 ) * 32 + V_74 ;
F_44 (
F_45 ( V_3 -> V_77 , V_75 ) ) ;
}
}
F_46 ( F_41 ( V_70 ) , V_70 ) ;
}
static int F_47 ( struct V_6 * V_7 , unsigned V_8 )
{
struct V_11 * V_3 = F_4 ( V_7 ) ;
if ( V_3 -> V_77 )
return F_48 ( V_3 -> V_77 , V_8 ) ;
else
return - V_78 ;
}
static int F_49 ( struct V_6 * V_7 , unsigned V_8 )
{
struct V_11 * V_3 = F_4 ( V_7 ) ;
if ( V_8 < V_3 -> V_36 )
return V_3 -> V_79 + V_8 ;
else
return - V_80 ;
}
static int F_50 ( struct V_2 * V_81 , unsigned V_68 )
{
struct V_11 * V_3 ;
struct V_1 T_1 * V_4 ;
T_2 V_15 ;
V_3 = (struct V_11 * ) F_34 ( V_81 ) ;
V_4 = (struct V_1 T_1 * ) V_3 -> V_16 ;
V_15 = F_5 ( V_81 -> V_82 - V_3 -> V_79 ) ;
if ( V_68 & ~ ( V_64 | V_65 ) )
return - V_47 ;
F_8 ( V_15 , ( V_68 & V_64 )
? & V_4 -> V_66 : & V_4 -> V_61 ) ;
F_8 ( V_15 , ( V_68 & V_65 )
? & V_4 -> V_67 : & V_4 -> V_62 ) ;
return 0 ;
}
static int
F_51 ( struct V_77 * V_3 , unsigned int V_82 ,
T_3 V_83 )
{
struct V_11 * V_41 =
(struct V_11 * ) V_3 -> V_84 ;
struct V_1 T_1 * V_4 = V_41 -> V_16 [ V_83 / 32 ] ;
F_52 ( V_82 , & V_85 , V_86 ,
L_7 ) ;
F_53 ( V_82 , V_87 ) ;
F_54 ( V_82 , ( V_5 void * ) V_4 ) ;
F_55 ( V_82 , ( void * ) F_5 ( V_83 ) ) ;
return 0 ;
}
static struct V_88 * F_56 ( unsigned int V_82 )
{
static struct V_89 V_36 ;
V_36 = * F_57 ( F_58 ( V_82 ) ) ;
return & V_36 . V_7 ;
}
static struct V_88 * F_59 ( unsigned int V_82 )
{
static struct V_88 V_36 ;
V_36 = * F_60 ( V_82 ) ;
return & V_36 ;
}
static int F_32 ( struct V_23 * V_24 )
{
unsigned V_39 , V_14 ;
int V_82 ;
struct V_90 * V_90 ;
T_2 V_91 = 0 ;
unsigned V_35 , V_92 ;
struct V_42 * V_27 = & V_24 -> V_27 ;
struct V_43 * V_44 ;
struct V_11 * V_41 = F_61 ( V_24 ) ;
struct V_22 * V_29 = V_27 -> V_48 ;
struct V_1 T_1 * V_4 ;
struct V_77 * V_77 = NULL ;
const struct V_93 * V_94 ;
struct V_88 * V_88 ;
struct V_72 * V_73 ;
T_4 V_95 ;
V_95 = F_56 ;
V_94 = F_62 ( F_63 ( V_96 ) ,
V_27 ) ;
if ( V_94 )
V_95 = ( T_4 ) V_94 -> V_81 ;
V_35 = V_29 -> V_35 ;
V_44 = F_23 ( V_24 , V_97 , 0 ) ;
if ( ! V_44 ) {
F_19 ( V_27 , L_8 ) ;
return - V_98 ;
}
V_92 = V_44 -> V_99 ;
if ( ! V_92 ) {
F_19 ( V_27 , L_8 ) ;
return - V_80 ;
}
V_90 = F_64 ( V_27 , L_9 ) ;
if ( F_25 ( V_90 ) ) {
F_65 ( V_100 L_10 ,
F_26 ( V_90 ) ) ;
return F_26 ( V_90 ) ;
}
F_66 ( V_90 ) ;
if ( ! V_29 -> V_36 ) {
V_82 = F_67 ( V_27 , - 1 , 0 , V_35 , 0 ) ;
if ( V_82 < 0 ) {
F_19 ( V_27 , L_11 ) ;
return V_82 ;
}
V_77 = F_68 ( V_27 -> V_28 , V_35 , V_82 , 0 ,
& V_101 ,
V_41 ) ;
if ( ! V_77 ) {
F_19 ( V_27 , L_12 ) ;
return - V_80 ;
}
}
V_41 -> V_7 . V_102 = F_47 ;
V_41 -> V_77 = V_77 ;
if ( V_29 -> V_36 ) {
V_41 -> V_7 . V_102 = F_49 ;
V_41 -> V_79 = V_92 ;
V_41 -> V_36 = V_29 -> V_36 ;
V_91 = F_69 ( V_29 -> V_36 / 16 , 0 ) ;
V_82 = V_92 ;
V_88 = V_95 ( V_82 ) ;
V_88 -> V_103 = L_13 ;
V_88 -> V_104 = F_50 ;
V_4 = V_41 -> V_16 [ 0 ] ;
F_8 ( ~ 0 , & V_4 -> V_66 ) ;
F_8 ( ~ 0 , & V_4 -> V_67 ) ;
for ( V_39 = 0 ; V_39 < V_29 -> V_36 ; V_39 ++ , V_82 ++ ) {
F_70 ( V_82 , V_88 ) ;
F_55 ( V_82 , V_41 ) ;
F_71 ( V_82 , V_105 ) ;
}
goto V_106;
}
for ( V_39 = 0 , V_14 = 0 ; V_39 < V_35 ; V_14 ++ , V_92 ++ , V_39 += 16 ) {
V_4 = V_41 -> V_16 [ V_14 / 2 ] ;
F_8 ( ~ 0 , & V_4 -> V_61 ) ;
F_8 ( ~ 0 , & V_4 -> V_62 ) ;
V_73 = F_17 ( & V_24 -> V_27 ,
sizeof( struct
V_72 ) ,
V_33 ) ;
if ( ! V_73 )
return - V_50 ;
V_73 -> V_16 = V_4 ;
V_73 -> V_71 = V_14 ;
V_73 -> V_7 = V_41 ;
F_72 ( V_92 , F_38 ,
V_73 ) ;
V_91 |= F_43 ( V_14 ) ;
}
V_106:
F_8 ( V_91 , V_52 + V_107 ) ;
return 0 ;
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_108 ) ;
}
