static const inline struct V_1 * F_1 (
const struct V_2 * V_3 ,
const char * V_4 )
{
const struct V_1 * V_5 = NULL ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( ! strcmp ( V_3 -> V_8 [ V_6 ] . V_4 , V_4 ) ) {
V_5 = & V_3 -> V_8 [ V_6 ] ;
break;
}
}
return V_5 ;
}
static int F_2 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
return V_3 -> V_7 ;
}
static const char * F_4 ( struct V_9 * V_10 ,
unsigned V_13 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
return V_3 -> V_8 [ V_13 ] . V_4 ;
}
static int F_5 ( struct V_9 * V_10 , unsigned V_13 ,
const unsigned * * V_14 ,
unsigned * V_15 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
if ( V_13 >= V_3 -> V_7 )
return - V_16 ;
* V_14 = V_3 -> V_8 [ V_13 ] . V_14 ;
* V_15 = V_3 -> V_8 [ V_13 ] . V_15 ;
return 0 ;
}
static void F_6 ( struct V_9 * V_10 , struct V_17 * V_18 ,
unsigned V_19 )
{
F_7 ( V_18 , L_1 , F_8 ( V_10 -> V_20 ) ) ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_23 * * V_24 , unsigned * V_25 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_1 * V_5 ;
struct V_23 * V_26 ;
struct V_21 * V_27 ;
int V_28 = 1 ;
int V_6 , V_29 ;
V_5 = F_1 ( V_3 , V_22 -> V_4 ) ;
if ( ! V_5 ) {
F_10 ( V_3 -> V_20 , L_2 ,
V_22 -> V_4 ) ;
return - V_16 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ ) {
if ( ! ( V_5 -> V_30 [ V_6 ] & V_31 ) )
V_28 ++ ;
}
V_26 = F_11 ( sizeof( struct V_23 ) * V_28 , V_32 ) ;
if ( ! V_26 )
return - V_33 ;
* V_24 = V_26 ;
* V_25 = V_28 ;
V_27 = F_12 ( V_22 ) ;
if ( ! V_27 ) {
F_13 ( V_26 ) ;
return - V_16 ;
}
V_26 [ 0 ] . type = V_34 ;
V_26 [ 0 ] . V_35 . V_36 . V_37 = V_27 -> V_4 ;
V_26 [ 0 ] . V_35 . V_36 . V_38 = V_22 -> V_4 ;
F_14 ( V_27 ) ;
V_26 ++ ;
for ( V_6 = V_29 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ ) {
if ( ! ( V_5 -> V_30 [ V_6 ] & V_31 ) ) {
V_26 [ V_29 ] . type = V_39 ;
V_26 [ V_29 ] . V_35 . V_30 . V_40 =
F_15 ( V_10 , V_5 -> V_14 [ V_6 ] ) ;
V_26 [ V_29 ] . V_35 . V_30 . V_30 = & V_5 -> V_30 [ V_6 ] ;
V_26 [ V_29 ] . V_35 . V_30 . V_41 = 1 ;
V_29 ++ ;
}
}
F_16 ( V_10 -> V_20 , L_3 ,
( * V_24 ) -> V_35 . V_36 . V_37 , ( * V_24 ) -> V_35 . V_36 . V_38 , V_28 ) ;
return 0 ;
}
static void F_17 ( struct V_9 * V_10 ,
struct V_23 * V_24 , unsigned V_25 )
{
F_13 ( V_24 ) ;
}
static int F_18 ( struct V_9 * V_10 , unsigned V_13 ,
unsigned V_38 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_42 * V_43 ;
const unsigned * V_14 , * V_36 , * V_44 ;
T_1 * V_45 ;
unsigned int V_15 , V_46 ;
int V_6 ;
V_14 = V_3 -> V_8 [ V_38 ] . V_14 ;
V_15 = V_3 -> V_8 [ V_38 ] . V_15 ;
V_36 = V_3 -> V_8 [ V_38 ] . V_47 ;
V_44 = V_3 -> V_8 [ V_38 ] . V_44 ;
V_45 = V_3 -> V_8 [ V_38 ] . V_45 ;
F_19 ( ! V_14 || ! V_15 || ! V_36 || ! V_44 || ! V_45 ) ;
F_16 ( V_12 -> V_20 , L_4 ,
V_3 -> V_48 [ V_13 ] . V_4 , V_3 -> V_8 [ V_38 ] . V_4 ) ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
V_46 = V_14 [ V_6 ] ;
V_43 = & V_3 -> V_49 [ V_46 ] ;
if ( ! ( V_3 -> V_50 & V_51 ) && ! V_43 -> V_52 ) {
F_10 ( V_12 -> V_20 , L_5 ,
V_3 -> V_14 [ V_46 ] . V_4 ) ;
return - V_16 ;
}
if ( V_3 -> V_50 & V_53 ) {
T_2 V_54 ;
V_54 = F_20 ( V_12 -> V_55 + V_43 -> V_52 ) ;
V_54 &= ~ ( 0x7 << 20 ) ;
V_54 |= ( V_36 [ V_6 ] << 20 ) ;
F_21 ( V_54 , V_12 -> V_55 + V_43 -> V_52 ) ;
} else {
F_21 ( V_36 [ V_6 ] , V_12 -> V_55 + V_43 -> V_52 ) ;
}
F_16 ( V_12 -> V_20 , L_6 ,
V_43 -> V_52 , V_36 [ V_6 ] ) ;
if ( V_45 [ V_6 ] ) {
F_21 ( V_44 [ V_6 ] , V_12 -> V_55 + V_45 [ V_6 ] ) ;
F_16 ( V_12 -> V_20 ,
L_7 ,
V_45 [ V_6 ] , V_44 [ V_6 ] ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
return V_3 -> V_56 ;
}
static const char * F_23 ( struct V_9 * V_10 ,
unsigned V_13 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
return V_3 -> V_48 [ V_13 ] . V_4 ;
}
static int F_24 ( struct V_9 * V_10 , unsigned V_13 ,
const char * const * * V_8 ,
unsigned * const V_57 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
* V_8 = V_3 -> V_48 [ V_13 ] . V_8 ;
* V_57 = V_3 -> V_48 [ V_13 ] . V_57 ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
unsigned V_46 , unsigned long * V_58 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_42 * V_43 = & V_3 -> V_49 [ V_46 ] ;
if ( ! ( V_3 -> V_50 & V_51 ) && ! V_43 -> V_59 ) {
F_10 ( V_3 -> V_20 , L_8 ,
V_3 -> V_14 [ V_46 ] . V_4 ) ;
return - V_16 ;
}
* V_58 = F_20 ( V_12 -> V_55 + V_43 -> V_59 ) ;
if ( V_3 -> V_50 & V_53 )
* V_58 &= 0xffff ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
unsigned V_46 , unsigned long V_58 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_42 * V_43 = & V_3 -> V_49 [ V_46 ] ;
if ( ! ( V_3 -> V_50 & V_51 ) && ! V_43 -> V_59 ) {
F_10 ( V_3 -> V_20 , L_8 ,
V_3 -> V_14 [ V_46 ] . V_4 ) ;
return - V_16 ;
}
F_16 ( V_12 -> V_20 , L_9 ,
V_3 -> V_14 [ V_46 ] . V_4 ) ;
if ( V_3 -> V_50 & V_53 ) {
T_2 V_54 ;
V_54 = F_20 ( V_12 -> V_55 + V_43 -> V_59 ) ;
V_54 &= ~ 0xffff ;
V_54 |= V_58 ;
F_21 ( V_54 , V_12 -> V_55 + V_43 -> V_59 ) ;
} else {
F_21 ( V_58 , V_12 -> V_55 + V_43 -> V_59 ) ;
}
F_16 ( V_12 -> V_20 , L_10 ,
V_43 -> V_59 , V_58 ) ;
return 0 ;
}
static void F_27 ( struct V_9 * V_10 ,
struct V_17 * V_18 , unsigned V_46 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_42 * V_43 = & V_3 -> V_49 [ V_46 ] ;
unsigned long V_58 ;
if ( ! V_43 || ! V_43 -> V_59 ) {
F_7 ( V_18 , L_11 ) ;
return;
}
V_58 = F_20 ( V_12 -> V_55 + V_43 -> V_59 ) ;
F_7 ( V_18 , L_12 , V_58 ) ;
}
static void F_28 ( struct V_9 * V_10 ,
struct V_17 * V_18 , unsigned V_38 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
struct V_1 * V_5 ;
unsigned long V_58 ;
const char * V_4 ;
int V_6 , V_60 ;
if ( V_38 > V_3 -> V_7 )
return;
F_7 ( V_18 , L_13 ) ;
V_5 = & V_3 -> V_8 [ V_38 ] ;
for ( V_6 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ ) {
V_4 = F_15 ( V_10 , V_5 -> V_14 [ V_6 ] ) ;
V_60 = F_25 ( V_10 , V_5 -> V_14 [ V_6 ] , & V_58 ) ;
if ( V_60 )
return;
F_7 ( V_18 , L_14 , V_4 , V_58 ) ;
}
}
static int F_29 ( struct V_21 * V_22 ,
struct V_1 * V_5 ,
struct V_2 * V_3 ,
T_2 V_61 )
{
int V_62 , V_63 ;
const T_3 * V_64 ;
int V_6 ;
T_2 V_58 ;
F_16 ( V_3 -> V_20 , L_15 , V_61 , V_22 -> V_4 ) ;
if ( V_3 -> V_50 & V_53 )
V_63 = V_65 ;
else
V_63 = V_66 ;
V_5 -> V_4 = V_22 -> V_4 ;
V_64 = F_30 ( V_22 , L_16 , & V_62 ) ;
if ( ! V_62 || V_62 % V_63 ) {
F_10 ( V_3 -> V_20 , L_17 ) ;
return - V_16 ;
}
V_5 -> V_15 = V_62 / V_63 ;
V_5 -> V_14 = F_31 ( V_3 -> V_20 , V_5 -> V_15 * sizeof( unsigned int ) ,
V_32 ) ;
V_5 -> V_47 = F_31 ( V_3 -> V_20 , V_5 -> V_15 * sizeof( unsigned int ) ,
V_32 ) ;
V_5 -> V_45 = F_31 ( V_3 -> V_20 , V_5 -> V_15 * sizeof( T_1 ) ,
V_32 ) ;
V_5 -> V_44 = F_31 ( V_3 -> V_20 , V_5 -> V_15 * sizeof( unsigned int ) ,
V_32 ) ;
V_5 -> V_30 = F_31 ( V_3 -> V_20 , V_5 -> V_15 * sizeof( unsigned long ) ,
V_32 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ ) {
T_2 V_52 = F_32 ( * V_64 ++ ) ;
T_2 V_59 ;
unsigned int V_46 ;
struct V_42 * V_43 ;
if ( V_3 -> V_50 & V_53 )
V_59 = V_52 ;
else
V_59 = F_32 ( * V_64 ++ ) ;
V_46 = V_52 ? V_52 / 4 : V_59 / 4 ;
V_43 = & V_3 -> V_49 [ V_46 ] ;
V_5 -> V_14 [ V_6 ] = V_46 ;
V_43 -> V_52 = V_52 ;
V_43 -> V_59 = V_59 ;
V_5 -> V_45 [ V_6 ] = F_32 ( * V_64 ++ ) ;
V_5 -> V_47 [ V_6 ] = F_32 ( * V_64 ++ ) ;
V_5 -> V_44 [ V_6 ] = F_32 ( * V_64 ++ ) ;
V_58 = F_32 ( * V_64 ++ ) ;
if ( V_58 & V_67 )
V_5 -> V_47 [ V_6 ] |= V_68 ;
V_5 -> V_30 [ V_6 ] = V_58 & ~ V_67 ;
}
#ifdef F_33
F_34 ( V_3 , V_5 -> V_14 , V_5 -> V_47 , V_5 -> V_30 , V_5 -> V_15 ) ;
#endif
return 0 ;
}
static int F_35 ( struct V_21 * V_22 ,
struct V_2 * V_3 ,
T_2 V_61 )
{
struct V_21 * V_69 ;
struct V_70 * V_71 ;
struct V_1 * V_5 ;
int V_60 ;
static T_2 V_72 ;
T_2 V_6 = 0 ;
F_16 ( V_3 -> V_20 , L_18 , V_61 , V_22 -> V_4 ) ;
V_71 = & V_3 -> V_48 [ V_61 ] ;
V_71 -> V_4 = V_22 -> V_4 ;
V_71 -> V_57 = F_36 ( V_22 ) ;
if ( V_71 -> V_57 <= 0 ) {
F_10 ( V_3 -> V_20 , L_19 ) ;
return - V_16 ;
}
V_71 -> V_8 = F_31 ( V_3 -> V_20 ,
V_71 -> V_57 * sizeof( char * ) , V_32 ) ;
F_37 (np, child) {
V_71 -> V_8 [ V_6 ] = V_69 -> V_4 ;
V_5 = & V_3 -> V_8 [ V_72 ++ ] ;
V_60 = F_29 ( V_69 , V_5 , V_3 , V_6 ++ ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
static int F_38 ( struct V_73 * V_74 ,
struct V_2 * V_3 )
{
struct V_21 * V_22 = V_74 -> V_20 . V_75 ;
struct V_21 * V_69 ;
int V_60 ;
T_2 V_76 = 0 ;
T_2 V_6 = 0 ;
if ( ! V_22 )
return - V_77 ;
V_76 = F_36 ( V_22 ) ;
if ( V_76 <= 0 ) {
F_10 ( & V_74 -> V_20 , L_20 ) ;
return - V_16 ;
}
V_3 -> V_56 = V_76 ;
V_3 -> V_48 = F_31 ( & V_74 -> V_20 , V_76 * sizeof( struct V_70 ) ,
V_32 ) ;
if ( ! V_3 -> V_48 )
return - V_33 ;
V_3 -> V_7 = 0 ;
F_37 (np, child)
V_3 -> V_7 += F_36 ( V_69 ) ;
V_3 -> V_8 = F_31 ( & V_74 -> V_20 , V_3 -> V_7 * sizeof( struct V_1 ) ,
V_32 ) ;
if ( ! V_3 -> V_8 )
return - V_33 ;
F_37 (np, child) {
V_60 = F_35 ( V_69 , V_3 , V_6 ++ ) ;
if ( V_60 ) {
F_10 ( & V_74 -> V_20 , L_21 ) ;
return V_60 ;
}
}
return 0 ;
}
int F_39 ( struct V_73 * V_74 ,
struct V_2 * V_3 )
{
struct V_11 * V_12 ;
struct V_78 * V_79 ;
int V_60 ;
if ( ! V_3 || ! V_3 -> V_14 || ! V_3 -> V_15 ) {
F_10 ( & V_74 -> V_20 , L_22 ) ;
return - V_16 ;
}
V_3 -> V_20 = & V_74 -> V_20 ;
V_12 = F_31 ( & V_74 -> V_20 , sizeof( * V_12 ) , V_32 ) ;
if ( ! V_12 )
return - V_33 ;
V_3 -> V_49 = F_31 ( & V_74 -> V_20 , sizeof( * V_3 -> V_49 ) *
V_3 -> V_15 , V_32 ) ;
if ( ! V_3 -> V_49 )
return - V_33 ;
V_79 = F_40 ( V_74 , V_80 , 0 ) ;
if ( ! V_79 )
return - V_81 ;
V_12 -> V_55 = F_41 ( & V_74 -> V_20 , V_79 ) ;
if ( F_42 ( V_12 -> V_55 ) )
return F_43 ( V_12 -> V_55 ) ;
V_82 . V_4 = F_8 ( & V_74 -> V_20 ) ;
V_82 . V_14 = V_3 -> V_14 ;
V_82 . V_15 = V_3 -> V_15 ;
V_60 = F_38 ( V_74 , V_3 ) ;
if ( V_60 ) {
F_10 ( & V_74 -> V_20 , L_23 ) ;
return V_60 ;
}
V_12 -> V_3 = V_3 ;
V_12 -> V_20 = V_3 -> V_20 ;
F_44 ( V_74 , V_12 ) ;
V_12 -> V_83 = F_45 ( & V_82 , & V_74 -> V_20 , V_12 ) ;
if ( ! V_12 -> V_83 ) {
F_10 ( & V_74 -> V_20 , L_24 ) ;
return - V_16 ;
}
F_46 ( & V_74 -> V_20 , L_25 ) ;
return 0 ;
}
int F_47 ( struct V_73 * V_74 )
{
struct V_11 * V_12 = F_48 ( V_74 ) ;
F_49 ( V_12 -> V_83 ) ;
return 0 ;
}
