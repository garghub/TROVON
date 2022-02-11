static struct V_1 T_1 T_2 * F_1 ( unsigned V_2 )
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
T_3 V_17 ;
T_3 V_18 = 1 << V_10 ;
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
static int T_2 F_14 ( void )
{
int V_24 , V_25 ;
unsigned V_26 ;
struct V_27 * V_28 = & V_27 ;
struct V_1 * V_15 ;
if ( V_28 -> V_29 != V_30 )
return 0 ;
V_26 = V_28 -> V_31 ;
if ( V_26 == 0 ) {
F_15 ( L_1 ) ;
return - V_32 ;
}
if ( F_16 ( V_33 < V_26 ) )
V_26 = V_33 ;
V_4 = F_17 ( V_28 -> V_4 , V_34 ) ;
if ( F_16 ( ! V_4 ) )
return - V_35 ;
for ( V_24 = 0 , V_25 = 0 ; V_25 < V_26 ; V_24 ++ , V_25 += 32 ) {
V_36 [ V_24 ] . V_9 . V_37 = L_2 ;
V_36 [ V_24 ] . V_9 . V_38 = F_10 ;
V_36 [ V_24 ] . V_9 . V_39 = F_12 ;
V_36 [ V_24 ] . V_9 . V_40 = F_11 ;
V_36 [ V_24 ] . V_9 . V_41 = F_13 ;
V_36 [ V_24 ] . V_9 . V_25 = V_25 ;
V_36 [ V_24 ] . V_9 . V_26 = V_26 - V_25 ;
if ( V_36 [ V_24 ] . V_9 . V_26 > 32 )
V_36 [ V_24 ] . V_9 . V_26 = 32 ;
F_18 ( & V_36 [ V_24 ] . V_19 ) ;
V_15 = F_1 ( V_25 ) ;
V_36 [ V_24 ] . V_15 = V_15 ;
V_36 [ V_24 ] . V_21 = & V_15 -> V_21 ;
V_36 [ V_24 ] . V_22 = & V_15 -> V_22 ;
V_36 [ V_24 ] . V_23 = & V_15 -> V_23 ;
F_19 ( & V_36 [ V_24 ] . V_9 ) ;
}
V_28 -> V_42 = V_36 ;
V_28 -> V_43 = F_20 ( V_26 , 32 ) ;
F_21 () ;
return 0 ;
}
static void F_22 ( struct V_44 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_3 V_18 = ( T_3 ) F_23 ( V_14 ) ;
F_8 ( V_18 , & V_6 -> V_45 ) ;
F_8 ( V_18 , & V_6 -> V_46 ) ;
}
static void F_24 ( struct V_44 * V_14 )
{
struct V_1 T_1 * V_6 = F_2 ( V_14 -> V_5 ) ;
T_3 V_18 = ( T_3 ) F_23 ( V_14 ) ;
unsigned V_47 = F_25 ( V_14 ) ;
V_47 &= V_48 | V_49 ;
if ( ! V_47 )
V_47 = V_48 | V_49 ;
if ( V_47 & V_48 )
F_8 ( V_18 , & V_6 -> V_50 ) ;
if ( V_47 & V_49 )
F_8 ( V_18 , & V_6 -> V_51 ) ;
}
static int F_26 ( struct V_44 * V_14 , unsigned V_52 )
{
if ( V_52 & ~ ( V_48 | V_49 ) )
return - V_32 ;
return 0 ;
}
static void
F_27 ( unsigned V_5 , struct V_53 * V_54 )
{
struct V_1 T_1 * V_6 ;
T_3 V_18 = 0xffff ;
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) F_28 ( V_54 ) ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
if ( V_5 & 1 )
V_18 <<= 16 ;
V_54 -> V_44 . V_9 -> V_55 ( & V_54 -> V_44 ) ;
V_54 -> V_44 . V_9 -> V_56 ( & V_54 -> V_44 ) ;
while ( 1 ) {
T_3 V_47 ;
int V_57 ;
int V_58 ;
V_47 = F_7 ( & V_6 -> V_59 ) & V_18 ;
if ( ! V_47 )
break;
F_8 ( V_47 , & V_6 -> V_59 ) ;
V_57 = V_14 -> V_60 ;
if ( V_5 & 1 ) {
V_57 += 16 ;
V_47 >>= 16 ;
}
while ( V_47 ) {
V_58 = F_29 ( V_47 ) ;
V_57 += V_58 ;
F_30 ( V_57 - 1 ) ;
V_47 >>= V_58 ;
}
}
V_54 -> V_44 . V_9 -> V_61 ( & V_54 -> V_44 ) ;
}
static int F_31 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
if ( V_14 -> V_60 >= 0 )
return V_14 -> V_60 + V_10 ;
else
return - V_62 ;
}
static int F_32 ( struct V_8 * V_9 , unsigned V_10 )
{
struct V_27 * V_28 = & V_27 ;
if ( V_10 < V_28 -> V_63 )
return V_28 -> V_64 + V_10 ;
else
return - V_62 ;
}
static int F_33 ( struct V_44 * V_65 , unsigned V_52 )
{
struct V_13 * V_14 ;
struct V_1 T_1 * V_6 ;
struct V_27 * V_28 = & V_27 ;
T_3 V_18 ;
V_14 = (struct V_13 * ) V_65 -> V_66 ;
V_6 = (struct V_1 T_1 * ) V_14 -> V_15 ;
V_18 = F_34 ( V_65 -> V_5 - V_28 -> V_64 ) ;
if ( V_52 & ~ ( V_48 | V_49 ) )
return - V_32 ;
F_8 ( V_18 , ( V_52 & V_48 )
? & V_6 -> V_50 : & V_6 -> V_45 ) ;
F_8 ( V_18 , ( V_52 & V_49 )
? & V_6 -> V_51 : & V_6 -> V_46 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
unsigned V_2 , V_5 , V_67 ;
struct V_68 * V_68 ;
T_3 V_69 = 0 ;
unsigned V_26 , V_70 ;
struct V_27 * V_28 = & V_27 ;
struct V_1 T_1 * V_6 ;
V_26 = V_28 -> V_31 ;
V_70 = V_28 -> V_64 ;
if ( V_70 == 0 ) {
F_35 ( V_71 L_3 ) ;
return - V_32 ;
}
V_68 = F_36 ( NULL , L_4 ) ;
if ( F_37 ( V_68 ) ) {
F_35 ( V_71 L_5 ,
F_38 ( V_68 ) ) ;
return F_38 ( V_68 ) ;
}
F_39 ( V_68 ) ;
for ( V_2 = 0 , V_67 = 0 ; V_2 < V_26 ; V_67 ++ , V_2 += 32 ) {
V_36 [ V_67 ] . V_9 . V_72 = F_31 ;
V_36 [ V_67 ] . V_60 = V_28 -> V_63
? - V_32
: ( V_28 -> V_73 + V_2 ) ;
}
if ( V_28 -> V_63 ) {
static struct V_74 V_63 ;
V_36 [ 0 ] . V_9 . V_72 = F_32 ;
V_69 = F_40 ( 0 ) ;
V_5 = V_70 ;
V_63 = * F_41 ( F_42 ( V_5 ) ,
struct V_74 , V_9 ) ;
V_63 . V_9 . V_75 = L_6 ;
V_63 . V_9 . V_76 = F_33 ;
V_6 = F_1 ( 0 ) ;
F_8 ( ~ 0 , & V_6 -> V_50 ) ;
F_8 ( ~ 0 , & V_6 -> V_51 ) ;
for ( V_2 = 0 ; V_2 < V_28 -> V_63 ; V_2 ++ , V_5 ++ ) {
F_43 ( V_5 , & V_63 . V_9 ) ;
F_44 ( V_5 , & V_36 [ V_2 / 32 ] ) ;
F_45 ( V_5 , V_77 ) ;
}
goto V_78;
}
for ( V_2 = 0 , V_5 = F_46 ( 0 ) , V_67 = 0 ;
V_2 < V_26 ;
V_67 ++ , V_70 ++ ) {
unsigned V_24 ;
V_6 = F_1 ( V_2 ) ;
F_8 ( ~ 0 , & V_6 -> V_45 ) ;
F_8 ( ~ 0 , & V_6 -> V_46 ) ;
F_47 ( V_70 , F_27 ) ;
F_44 ( V_70 , & V_36 [ V_2 / 32 ] ) ;
for ( V_24 = 0 ; V_24 < 16 && V_2 < V_26 ; V_24 ++ , V_5 ++ , V_2 ++ ) {
F_43 ( V_5 , & V_79 ) ;
F_48 ( V_5 , ( V_7 void * ) V_6 ) ;
F_44 ( V_5 , ( void * ) F_34 ( V_2 ) ) ;
F_49 ( V_5 , V_80 ) ;
F_50 ( V_5 , V_81 ) ;
}
V_69 |= F_40 ( V_67 ) ;
}
V_78:
F_8 ( V_69 , V_4 + 0x08 ) ;
F_35 ( V_82 L_7 , V_5 - F_46 ( 0 ) ) ;
return 0 ;
}
