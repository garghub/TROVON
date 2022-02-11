static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
T_1 V_5 = V_3 -> V_6 ;
struct V_1 * V_7 = V_3 -> V_8 ;
T_2 V_9 = ( V_4 - V_5 ) / sizeof( * V_7 ) ;
if ( V_9 >= V_10 )
return NULL ;
return V_7 + V_9 ;
}
static T_1 F_2 ( struct V_2 * V_3 ,
struct V_1 * V_11 )
{
T_1 V_5 = V_3 -> V_6 ;
struct V_1 * V_7 = V_3 -> V_8 ;
T_2 V_9 ;
V_9 = V_11 - V_7 ;
if ( V_9 >= V_10 )
return 0 ;
return V_5 + ( V_9 * sizeof( * V_11 ) ) ;
}
static void F_3 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
V_3 -> V_8 = V_11 ;
V_3 -> V_12 = V_11 ;
V_3 -> V_13 = V_11 ;
V_3 -> V_14 = V_11 + V_10 - 1 ;
}
static void F_4 ( struct V_15 * V_16 )
{
struct V_2 * V_3 = & V_16 -> V_17 ;
struct V_1 * V_11 = V_3 -> V_8 ;
if ( V_11 ) {
V_11 -> V_18 &= ~ V_19 ;
F_3 ( V_3 , V_11 ) ;
}
}
int F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_11 ;
struct V_2 * V_3 = & V_16 -> V_17 ;
V_11 = F_6 ( V_16 -> V_20 -> V_21 , V_22 , & V_3 -> V_6 ) ;
if ( V_11 == NULL )
return - V_23 ;
F_3 ( V_3 , V_11 ) ;
return 0 ;
}
void F_7 ( struct V_15 * V_16 )
{
struct V_2 * V_3 = & V_16 -> V_17 ;
F_8 ( V_16 -> V_20 -> V_21 ,
V_3 -> V_8 , V_3 -> V_6 ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
}
static T_3 T_4 F_9 ( T_4 * V_24 )
{
T_4 V_25 = 0 ;
int V_26 ;
V_24 [ 1 ] = 0x0 ;
F_10 () ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
V_25 += V_24 [ V_26 ] ;
V_25 += 1 ;
return 0xFF - V_25 ;
}
void F_11 ( struct V_15 * V_16 )
{
struct V_28 * V_20 = V_16 -> V_20 ;
void T_5 * V_29 = V_20 -> V_30 ;
int V_31 = V_16 -> V_31 ;
T_2 V_9 ;
V_9 = V_16 -> V_32 ? F_12 ( V_31 ) : F_13 ( V_31 ) ;
F_14 ( V_29 , V_9 , V_33 ) ;
if ( ! ( F_15 ( V_29 , V_9 ) & V_34 ) )
F_14 ( V_29 , V_9 , V_33 ) ;
}
static struct V_1 * F_16 ( struct V_2 * V_3 )
{
if ( V_3 -> V_12 < V_3 -> V_14 )
V_3 -> V_12 ++ ;
else
V_3 -> V_12 = V_3 -> V_8 ;
return V_3 -> V_12 ;
}
static struct V_1 * F_17 ( struct V_2 * V_3 )
{
if ( V_3 -> V_13 < V_3 -> V_14 )
V_3 -> V_13 ++ ;
else
V_3 -> V_13 = V_3 -> V_8 ;
return V_3 -> V_13 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_35 = V_3 -> V_12 ;
struct V_1 * V_36 ;
if ( V_3 -> V_12 < V_3 -> V_14 )
V_36 = V_35 + 1 ;
else
V_36 = V_3 -> V_8 ;
return V_36 == V_3 -> V_13 ;
}
int F_19 ( struct V_15 * V_16 )
{
return F_18 ( & V_16 -> V_17 ) ;
}
static int F_20 ( struct V_15 * V_16 , struct V_37 * V_38 )
{
struct V_1 * V_35 ;
struct V_2 * V_3 = & V_16 -> V_17 ;
struct V_1 * V_11 = V_3 -> V_12 ;
struct V_39 * V_40 = & V_38 -> V_41 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_42 = F_21 ( ( T_2 ) V_40 -> V_6 ) ;
V_11 -> V_43 = F_22 ( V_40 -> V_44 ) ;
V_11 -> V_18 |= V_45 ;
V_35 = F_16 ( V_3 ) ;
F_23 ( V_16 -> V_20 -> V_46 , L_1 ,
V_16 -> V_31 , V_11 , V_35 ) ;
V_35 -> V_18 &= ~ V_19 ;
V_11 -> V_47 = F_21 ( ( T_2 ) F_2 ( V_3 , V_35 ) ) ;
if ( V_40 -> V_48 )
V_11 -> V_49 |= V_50 ;
V_11 -> V_25 = F_9 ( ( T_4 * ) V_11 ) ;
V_11 -> V_18 |= V_19 ;
V_38 -> V_11 = V_11 ;
return 0 ;
}
static int F_24 ( struct V_15 * V_16 , struct V_37 * V_38 )
{
struct V_1 * V_35 ;
struct V_2 * V_3 = & V_16 -> V_17 ;
struct V_1 * V_11 = V_3 -> V_12 ;
struct V_39 * V_40 = & V_38 -> V_41 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_42 = F_21 ( ( T_2 ) V_40 -> V_6 ) ;
V_11 -> V_51 = F_22 ( V_40 -> V_44 ) ;
V_11 -> V_18 |= V_45 ;
V_35 = F_16 ( V_3 ) ;
F_23 ( V_16 -> V_20 -> V_46 , L_2 ,
V_16 -> V_31 , V_11 , V_35 ) ;
V_35 -> V_18 &= ~ V_19 ;
V_11 -> V_47 = F_21 ( ( T_2 ) F_2 ( V_3 , V_35 ) ) ;
V_11 -> V_25 = F_9 ( ( T_4 * ) V_11 ) ;
V_11 -> V_18 |= V_19 ;
V_38 -> V_11 = V_11 ;
return 0 ;
}
void F_25 ( struct V_15 * V_16 , struct V_37 * V_38 )
{
if ( V_16 -> V_32 )
F_20 ( V_16 , V_38 ) ;
else
F_24 ( V_16 , V_38 ) ;
}
int F_26 ( struct V_15 * V_16 )
{
struct V_28 * V_20 = V_16 -> V_20 ;
void T_5 * V_29 = V_20 -> V_30 ;
struct V_2 * V_3 = & V_16 -> V_17 ;
T_4 V_31 = V_16 -> V_31 ;
if ( V_16 -> V_32 ) {
F_14 ( V_29 , F_27 ( V_16 -> V_31 ) , V_3 -> V_6 ) ;
F_28 ( V_29 , F_29 ( V_16 -> V_31 ) , V_52 ) ;
F_28 ( V_29 , V_53 , F_30 ( V_31 ) ) ;
F_28 ( V_29 , V_54 , F_31 ( V_31 ) ) ;
F_14 ( V_29 , V_55 ,
F_32 ( V_31 ) | F_33 ( V_31 ) ) ;
if ( F_15 ( V_29 , F_12 ( V_31 ) ) & V_34 ) {
F_34 ( V_20 -> V_46 , L_3 , V_31 ) ;
return 0 ;
}
F_14 ( V_29 , F_12 ( V_31 ) , V_56 ) ;
} else {
F_14 ( V_29 , F_35 ( V_16 -> V_31 ) , V_3 -> V_6 ) ;
F_28 ( V_29 , F_36 ( V_16 -> V_31 ) , V_57 ) ;
F_28 ( V_29 , V_53 , F_37 ( V_31 ) ) ;
F_38 ( V_29 , V_58 , F_39 ( V_31 ) ) ;
F_28 ( V_29 , V_58 , F_40 ( V_31 ) ) ;
F_14 ( V_29 , V_59 ,
F_41 ( V_31 ) | F_42 ( V_31 ) ) ;
F_14 ( V_29 , V_60 , F_43 ( V_31 ) ) ;
if ( F_15 ( V_29 , F_13 ( V_31 ) ) & V_34 ) {
F_34 ( V_20 -> V_46 , L_4 , V_31 ) ;
return 0 ;
}
F_14 ( V_29 , F_13 ( V_31 ) , V_56 ) ;
}
return 0 ;
}
void F_44 ( struct V_15 * V_16 )
{
struct V_28 * V_20 = V_16 -> V_20 ;
void T_5 * V_29 = V_20 -> V_30 ;
int V_31 = V_16 -> V_31 ;
T_2 V_61 = 0 ;
T_2 V_62 ;
int V_63 ;
V_62 = V_16 -> V_32 ? F_12 ( V_31 ) : F_13 ( V_31 ) ;
if ( ! ( F_15 ( V_29 , V_62 ) & V_34 ) ) {
F_23 ( V_20 -> V_46 , L_5 , V_16 -> V_64 ) ;
return;
}
F_14 ( V_29 , V_62 , V_65 ) ;
V_63 = F_45 ( V_29 + V_62 , V_61 ,
! ( V_61 & V_34 ) , 1 , 1000 ) ;
if ( V_63 ) {
F_46 ( V_20 -> V_46 , L_6 , V_16 -> V_64 ) ;
return;
}
F_23 ( V_20 -> V_46 , L_7 , V_16 -> V_64 ) ;
}
void F_47 ( struct V_15 * V_16 )
{
F_23 ( V_16 -> V_20 -> V_46 , L_8 , V_66 ,
( ( V_16 -> V_32 ) ? L_9 : L_10 ) ) ;
F_44 ( V_16 ) ;
F_4 ( V_16 ) ;
}
static void F_48 ( struct V_28 * V_20 , T_4 V_31 )
{
struct V_15 * V_16 = V_20 -> V_67 + V_31 ;
struct V_2 * V_3 = & V_16 -> V_17 ;
void T_5 * V_29 = V_20 -> V_30 ;
struct V_1 * V_68 = NULL ;
T_1 V_69 = F_15 ( V_29 , F_49 ( V_31 ) ) ;
struct V_39 * V_40 = NULL ;
struct V_37 * V_38 ;
T_2 V_70 = 0 ;
int V_63 ;
V_38 = F_50 ( V_16 ) ;
if ( V_38 && V_38 -> V_41 . V_44 == 0 )
V_40 = & V_38 -> V_41 ;
else
return;
V_68 = F_1 ( V_3 , V_69 ) ;
if ( F_51 ( V_68 -> V_43 ) != 0 ) {
F_46 ( V_20 -> V_46 , L_11 , V_31 ) ;
return;
}
F_23 ( V_20 -> V_46 , L_12 , V_66 , V_38 ) ;
F_38 ( V_29 , F_29 ( V_16 -> V_31 ) , V_52 ) ;
V_63 = F_45 ( V_29 + F_29 ( V_16 -> V_31 ) ,
V_70 , ! ( V_70 & V_71 ) , 1 , 1000 ) ;
if ( V_63 ) {
F_46 ( V_20 -> V_46 , L_13 , V_66 ) ;
return;
}
F_28 ( V_29 , F_29 ( V_16 -> V_31 ) , V_72 ) ;
V_68 -> V_18 |= V_73 ;
V_68 -> V_25 = F_9 ( ( T_4 * ) V_68 ) ;
V_68 -> V_18 |= V_19 ;
F_28 ( V_29 , F_29 ( V_16 -> V_31 ) , V_52 ) ;
F_11 ( V_16 ) ;
}
static void F_52 ( struct V_28 * V_20 , T_4 V_31 )
{
struct V_15 * V_16 = V_20 -> V_67 + V_31 ;
struct V_2 * V_3 = & V_16 -> V_17 ;
void T_5 * V_29 = V_20 -> V_30 ;
struct V_1 * V_11 = V_3 -> V_13 ;
struct V_1 * V_68 = NULL ;
T_1 V_69 = F_15 ( V_29 , F_49 ( V_31 ) ) ;
struct V_39 * V_41 = NULL ;
struct V_37 * V_38 ;
V_68 = F_1 ( V_3 , V_69 ) ;
F_23 ( V_20 -> V_46 , L_14 ,
V_66 , V_31 , V_11 , V_68 , V_3 -> V_12 ) ;
while ( V_11 != V_68 && ! ( V_11 -> V_18 & V_19 ) ) {
V_38 = F_50 ( V_16 ) ;
if ( V_38 == NULL || V_38 -> V_11 != V_11 ) {
F_46 ( V_20 -> V_46 , L_15 ) ;
break;
}
V_41 = & V_38 -> V_41 ;
V_41 -> V_74 = F_51 ( V_11 -> V_43 ) ;
F_53 ( V_16 , V_41 , 0 ) ;
V_11 = F_17 ( V_3 ) ;
}
F_23 ( V_20 -> V_46 , L_16 ,
V_66 , V_31 , V_3 -> V_13 , V_3 -> V_12 ) ;
}
static void F_54 ( struct V_28 * V_20 , T_4 V_31 )
{
struct V_15 * V_16 = V_20 -> V_75 + V_31 ;
struct V_2 * V_3 = & V_16 -> V_17 ;
void T_5 * V_29 = V_20 -> V_30 ;
struct V_1 * V_11 = V_3 -> V_13 ;
struct V_1 * V_68 = NULL ;
T_1 V_69 = F_15 ( V_29 , F_55 ( V_31 ) ) ;
struct V_39 * V_40 = NULL ;
struct V_37 * V_38 ;
V_68 = F_1 ( V_3 , V_69 ) ;
F_23 ( V_20 -> V_46 , L_14 ,
V_66 , V_31 , V_11 , V_68 , V_3 -> V_12 ) ;
while ( V_11 != V_68 && ! ( V_11 -> V_18 & V_19 ) ) {
V_38 = F_50 ( V_16 ) ;
if ( V_38 == NULL || V_38 -> V_11 != V_11 ) {
F_46 ( V_20 -> V_46 , L_17 ) ;
break;
}
V_40 = & V_38 -> V_41 ;
V_40 -> V_74 = F_51 ( V_11 -> V_43 ) ;
F_53 ( V_16 , V_40 , 0 ) ;
V_11 = F_17 ( V_3 ) ;
}
F_23 ( V_20 -> V_46 , L_16 ,
V_66 , V_31 , V_3 -> V_13 , V_3 -> V_12 ) ;
}
static void F_56 ( struct V_28 * V_20 , T_2 V_76 )
{
int V_26 ;
for ( V_26 = 1 ; V_26 < V_20 -> V_77 ; V_26 ++ ) {
if ( V_76 & F_57 ( V_26 ) )
F_54 ( V_20 , V_26 ) ;
if ( V_76 & F_58 ( V_26 ) )
F_52 ( V_20 , V_26 ) ;
}
}
static void F_59 ( struct V_28 * V_20 , T_2 V_78 )
{
void T_5 * V_29 = V_20 -> V_30 ;
T_2 V_79 ;
int V_26 ;
if ( ( V_78 & V_80 ) || ( V_78 & V_81 ) ) {
V_79 = F_15 ( V_29 , V_82 ) ;
for ( V_26 = 1 ; V_26 < V_20 -> V_77 ; V_26 ++ ) {
if ( V_79 & F_42 ( V_26 ) )
F_46 ( V_20 -> V_46 , L_18 , V_26 ) ;
if ( V_79 & F_41 ( V_26 ) )
F_46 ( V_20 -> V_46 , L_19 , V_26 ) ;
}
F_14 ( V_29 , V_82 , V_79 ) ;
}
if ( V_78 & V_83 ) {
V_79 = F_15 ( V_29 , V_84 ) ;
for ( V_26 = 1 ; V_26 < V_20 -> V_77 ; V_26 ++ ) {
if ( V_79 & F_43 ( V_26 ) )
F_23 ( V_20 -> V_46 , L_20 , V_26 ) ;
}
F_14 ( V_29 , V_84 , V_79 ) ;
}
if ( ( V_78 & V_85 ) || ( V_78 & V_86 ) ) {
V_79 = F_15 ( V_29 , V_87 ) ;
for ( V_26 = 1 ; V_26 < V_20 -> V_77 ; V_26 ++ ) {
if ( V_79 & F_33 ( V_26 ) )
F_46 ( V_20 -> V_46 , L_21 , V_26 ) ;
if ( V_79 & F_32 ( V_26 ) )
F_48 ( V_20 , V_26 ) ;
}
F_14 ( V_29 , V_87 , V_79 ) ;
}
}
T_6 F_60 ( struct V_28 * V_20 )
{
void T_5 * V_29 = V_20 -> V_30 ;
T_2 V_78 ;
T_2 V_88 ;
V_78 = F_15 ( V_29 , V_89 ) ;
V_78 &= F_15 ( V_29 , V_90 ) ;
V_88 = F_15 ( V_29 , V_91 ) ;
V_88 &= F_15 ( V_29 , V_92 ) ;
F_14 ( V_29 , V_91 , V_88 ) ;
F_23 ( V_20 -> V_46 , L_22 ,
( V_88 & 0xFFFF ) , V_88 >> 16 ,
V_78 ) ;
if ( V_88 )
F_56 ( V_20 , V_88 ) ;
if ( V_78 )
F_59 ( V_20 , V_78 ) ;
return V_93 ;
}
int F_61 ( struct V_28 * V_20 )
{
F_62 ( V_94 == 16 , L_23 ) ;
V_20 -> V_21 = F_63 ( L_24 , V_20 -> V_46 ,
V_95 , V_94 , 0 ) ;
if ( ! V_20 -> V_21 )
return - V_23 ;
return 0 ;
}
void F_64 ( struct V_28 * V_20 )
{
F_65 ( V_20 -> V_21 ) ;
}
