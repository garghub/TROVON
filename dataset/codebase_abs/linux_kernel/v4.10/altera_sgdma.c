int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 |
V_5 ;
V_2 -> V_6 = V_7 |
V_5 |
V_4 ;
F_2 ( & V_2 -> V_8 ) ;
F_2 ( & V_2 -> V_9 ) ;
V_2 -> V_10 = ( V_11 ) 0 ;
V_2 -> V_12 = ( V_11 ) 0 ;
V_2 -> V_10 = F_3 ( V_2 -> V_13 ,
( void V_14 * ) V_2 -> V_15 ,
V_2 -> V_16 , V_17 ) ;
if ( F_4 ( V_2 -> V_13 , V_2 -> V_10 ) ) {
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_18 , L_1 ) ;
return - V_19 ;
}
V_2 -> V_12 = F_3 ( V_2 -> V_13 ,
( void V_14 * ) V_2 -> V_20 ,
V_2 -> V_21 , V_22 ) ;
if ( F_4 ( V_2 -> V_13 , V_2 -> V_12 ) ) {
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_18 , L_2 ) ;
return - V_19 ;
}
F_7 ( V_2 -> V_20 , 0 , V_2 -> V_21 ) ;
F_7 ( V_2 -> V_15 , 0 , V_2 -> V_16 ) ;
F_8 ( V_2 -> V_13 , V_2 -> V_12 ,
V_2 -> V_21 , V_22 ) ;
F_8 ( V_2 -> V_13 , V_2 -> V_10 ,
V_2 -> V_16 , V_22 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 )
F_9 ( V_2 -> V_13 , V_2 -> V_10 ,
V_2 -> V_16 , V_17 ) ;
if ( V_2 -> V_12 )
F_9 ( V_2 -> V_13 , V_2 -> V_12 ,
V_2 -> V_21 , V_22 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_20 , 0 , V_2 -> V_21 ) ;
F_7 ( V_2 -> V_15 , 0 , V_2 -> V_16 ) ;
F_11 ( V_23 , V_2 -> V_24 , F_12 ( V_25 ) ) ;
F_11 ( 0 , V_2 -> V_24 , F_12 ( V_25 ) ) ;
F_11 ( V_23 , V_2 -> V_26 , F_12 ( V_25 ) ) ;
F_11 ( 0 , V_2 -> V_26 , F_12 ( V_25 ) ) ;
}
void F_13 ( struct V_1 * V_2 )
{
}
void F_14 ( struct V_1 * V_2 )
{
}
void F_15 ( struct V_1 * V_2 )
{
}
void F_16 ( struct V_1 * V_2 )
{
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_26 , F_12 ( V_25 ) ,
V_27 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_24 , F_12 ( V_25 ) ,
V_27 ) ;
}
int F_20 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_30 T_1 * V_31 =
(struct V_30 T_1 * ) V_2 -> V_20 ;
struct V_30 T_1 * V_32 = & V_31 [ 0 ] ;
struct V_30 T_1 * V_33 = & V_31 [ 1 ] ;
if ( F_21 ( V_2 ) )
return 0 ;
F_22 ( V_32 ,
V_33 ,
F_23 ( V_2 , V_33 ) ,
V_29 -> V_34 ,
0 ,
V_29 -> V_35 ,
V_36 ,
0 ,
V_37 ) ;
F_24 ( V_2 , V_32 ) ;
F_25 ( V_2 , V_29 ) ;
return 1 ;
}
T_2 F_26 ( struct V_1 * V_2 )
{
T_2 V_38 = 0 ;
if ( ! F_21 ( V_2 ) &&
( ( F_27 ( V_2 -> V_20 , F_28 ( V_25 ) )
& V_39 ) == 0 ) &&
( F_29 ( V_2 ) ) ) {
V_38 = 1 ;
}
return V_38 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_28 * V_40 )
{
F_33 ( V_2 , V_40 ) ;
}
T_2 F_34 ( struct V_1 * V_2 )
{
struct V_30 T_1 * V_41 =
(struct V_30 T_1 * ) V_2 -> V_15 ;
struct V_30 T_1 * V_42 = NULL ;
struct V_28 * V_40 = NULL ;
unsigned int V_43 = 0 ;
T_2 V_44 = F_35 ( V_2 -> V_26 , F_12 ( V_45 ) ) ;
V_42 = & V_41 [ 0 ] ;
if ( V_44 & V_46 ) {
unsigned int V_47 = 0 ;
unsigned int V_48 = 0 ;
F_36 ( V_2 -> V_13 ,
V_2 -> V_10 ,
V_49 ,
V_50 ) ;
V_47 = F_37 ( V_42 , F_28 ( V_51 ) ) ;
V_48 = F_27 ( V_42 , F_28 ( V_45 ) ) ;
V_43 = V_48 & ~ V_52 ;
V_43 = V_43 << 16 ;
V_43 |= ( V_47 & 0xffff ) ;
if ( V_43 ) {
F_38 ( 0 , V_42 , F_28 ( V_45 ) ) ;
V_40 = F_39 ( V_2 ) ;
if ( V_40 == NULL )
F_40 ( V_2 -> V_18 ,
L_3 ) ;
F_11 ( 0 , V_2 -> V_26 , F_12 ( V_25 ) ) ;
F_11 ( 0xf , V_2 -> V_26 , F_12 ( V_45 ) ) ;
F_31 ( V_2 ) ;
} else {
F_6 ( V_2 -> V_18 ,
L_4 ,
V_44 , F_27 ( V_42 , F_28 ( V_45 ) ) ,
V_43 ) ;
}
} else if ( V_44 == 0 ) {
F_31 ( V_2 ) ;
}
return V_43 ;
}
static void F_22 ( struct V_30 T_1 * V_42 ,
struct V_30 T_1 * V_33 ,
V_11 V_53 ,
V_11 V_54 ,
V_11 V_55 ,
T_3 V_56 ,
int V_57 ,
int V_58 ,
int V_59 )
{
T_2 V_60 = F_27 ( V_33 , F_28 ( V_25 ) ) ;
V_60 &= ~ V_39 ;
F_38 ( V_60 , V_33 , F_28 ( V_25 ) ) ;
V_60 = V_39 ;
V_60 |= V_57 ;
V_60 |= V_58 ;
V_60 |= V_59 ;
F_11 ( F_41 ( V_54 ) , V_42 , F_28 ( V_54 ) ) ;
F_11 ( F_41 ( V_55 ) , V_42 , F_28 ( V_55 ) ) ;
F_11 ( 0 , V_42 , F_28 ( V_61 ) ) ;
F_11 ( 0 , V_42 , F_28 ( V_62 ) ) ;
F_11 ( F_41 ( V_53 ) , V_42 , F_28 ( V_63 ) ) ;
F_38 ( V_60 , V_42 , F_28 ( V_25 ) ) ;
F_38 ( 0 , V_42 , F_28 ( V_45 ) ) ;
F_38 ( 0 , V_42 , F_28 ( V_64 ) ) ;
F_38 ( 0 , V_42 , F_28 ( V_65 ) ) ;
F_42 ( V_56 , V_42 , F_28 ( V_66 ) ) ;
F_42 ( 0 , V_42 , F_28 ( V_51 ) ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_30 T_1 * V_31 =
(struct V_30 T_1 * ) V_2 -> V_15 ;
struct V_30 T_1 * V_32 = & V_31 [ 0 ] ;
struct V_30 T_1 * V_33 = & V_31 [ 1 ] ;
struct V_28 * V_40 = NULL ;
if ( ! F_43 ( V_2 ) ) {
V_40 = F_44 ( V_2 ) ;
if ( V_40 == NULL ) {
F_6 ( V_2 -> V_18 , L_5 ) ;
return 0 ;
}
F_22 ( V_32 ,
V_33 ,
F_45 ( V_2 , V_33 ) ,
0 ,
V_40 -> V_34 ,
0 ,
0 ,
0 ,
0 ) ;
F_8 ( V_2 -> V_13 ,
V_2 -> V_10 ,
V_49 ,
V_22 ) ;
F_11 ( F_41 ( F_45 ( V_2 , V_32 ) ) ,
V_2 -> V_26 ,
F_12 ( V_67 ) ) ;
F_11 ( ( V_2 -> V_6 | V_68 ) ,
V_2 -> V_26 ,
F_12 ( V_25 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_30 T_1 * V_42 )
{
if ( F_21 ( V_2 ) )
return 0 ;
F_11 ( 0 , V_2 -> V_24 , F_12 ( V_25 ) ) ;
F_11 ( 0x1f , V_2 -> V_24 , F_12 ( V_45 ) ) ;
F_8 ( V_2 -> V_13 , V_2 -> V_12 ,
V_49 , V_22 ) ;
F_11 ( F_41 ( F_23 ( V_2 , V_42 ) ) ,
V_2 -> V_24 ,
F_12 ( V_67 ) ) ;
F_11 ( ( V_2 -> V_3 | V_68 ) ,
V_2 -> V_24 ,
F_12 ( V_25 ) ) ;
return 1 ;
}
static V_11
F_23 ( struct V_1 * V_2 ,
struct V_30 T_1 * V_42 )
{
V_11 V_69 = V_2 -> V_70 ;
T_4 V_71 = ( T_4 ) V_42 - ( T_4 ) V_2 -> V_20 ;
return ( V_11 ) ( ( T_4 ) V_69 + V_71 ) ;
}
static V_11
F_45 ( struct V_1 * V_2 ,
struct V_30 T_1 * V_42 )
{
V_11 V_69 = V_2 -> V_72 ;
T_4 V_71 = ( T_4 ) V_42 - ( T_4 ) V_2 -> V_15 ;
return ( V_11 ) ( ( T_4 ) V_69 + V_71 ) ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
F_46 ( & V_29 -> V_73 , & V_2 -> V_8 ) ;
}
static void
F_33 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
F_46 ( & V_29 -> V_73 , & V_2 -> V_9 ) ;
}
static struct V_28 *
F_29 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = NULL ;
F_47 ( & V_2 -> V_8 , V_29 , struct V_28 , V_73 ) ;
return V_29 ;
}
static struct V_28 *
F_39 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = NULL ;
F_47 ( & V_2 -> V_9 , V_29 , struct V_28 , V_73 ) ;
return V_29 ;
}
static struct V_28 *
F_44 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = NULL ;
F_48 ( & V_2 -> V_9 , V_29 , struct V_28 , V_73 ) ;
return V_29 ;
}
static int F_43 ( struct V_1 * V_2 )
{
return F_35 ( V_2 -> V_26 , F_12 ( V_45 ) )
& V_74 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_75 = 0 ;
while ( ( F_35 ( V_2 -> V_24 , F_12 ( V_45 ) )
& V_74 ) && ( V_75 ++ < 100 ) )
F_49 ( 1 ) ;
if ( F_35 ( V_2 -> V_24 , F_12 ( V_45 ) )
& V_74 ) {
F_6 ( V_2 -> V_18 , L_6 ) ;
return 1 ;
}
return 0 ;
}
