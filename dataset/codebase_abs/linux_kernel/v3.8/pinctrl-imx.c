static const struct V_1 * F_1 (
const struct V_2 * V_3 ,
unsigned V_4 , bool V_5 , unsigned V_6 )
{
const struct V_1 * V_7 = NULL ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_9 ; V_8 ++ ) {
V_7 = & V_3 -> V_10 [ V_8 ] ;
if ( V_7 -> V_11 != V_4 )
continue;
if ( ! V_5 )
break;
else if ( V_7 -> V_12 == ( V_6 & V_13 ) )
break;
}
if ( V_8 == V_3 -> V_9 ) {
F_2 ( V_3 -> V_14 , L_1 ,
V_3 -> V_15 [ V_4 ] . V_16 ) ;
return NULL ;
}
return V_7 ;
}
static const inline struct V_17 * F_3 (
const struct V_2 * V_3 ,
const char * V_16 )
{
const struct V_17 * V_18 = NULL ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_19 ; V_8 ++ ) {
if ( ! strcmp ( V_3 -> V_20 [ V_8 ] . V_16 , V_16 ) ) {
V_18 = & V_3 -> V_20 [ V_8 ] ;
break;
}
}
return V_18 ;
}
static int F_4 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
return V_3 -> V_19 ;
}
static const char * F_6 ( struct V_21 * V_22 ,
unsigned V_25 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
return V_3 -> V_20 [ V_25 ] . V_16 ;
}
static int F_7 ( struct V_21 * V_22 , unsigned V_25 ,
const unsigned * * V_15 ,
unsigned * V_26 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
if ( V_25 >= V_3 -> V_19 )
return - V_27 ;
* V_15 = V_3 -> V_20 [ V_25 ] . V_15 ;
* V_26 = V_3 -> V_20 [ V_25 ] . V_26 ;
return 0 ;
}
static void F_8 ( struct V_21 * V_22 , struct V_28 * V_29 ,
unsigned V_30 )
{
F_9 ( V_29 , L_2 , F_10 ( V_22 -> V_14 ) ) ;
}
static int F_11 ( struct V_21 * V_22 ,
struct V_31 * V_32 ,
struct V_33 * * V_34 , unsigned * V_35 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
const struct V_17 * V_18 ;
struct V_33 * V_36 ;
struct V_31 * V_37 ;
int V_38 = 1 ;
int V_8 , V_39 ;
V_18 = F_3 ( V_3 , V_32 -> V_16 ) ;
if ( ! V_18 ) {
F_2 ( V_3 -> V_14 , L_3 ,
V_32 -> V_16 ) ;
return - V_27 ;
}
for ( V_8 = 0 ; V_8 < V_18 -> V_26 ; V_8 ++ ) {
if ( ! ( V_18 -> V_40 [ V_8 ] & V_41 ) )
V_38 ++ ;
}
V_36 = F_12 ( sizeof( struct V_33 ) * V_38 , V_42 ) ;
if ( ! V_36 )
return - V_43 ;
* V_34 = V_36 ;
* V_35 = V_38 ;
V_37 = F_13 ( V_32 ) ;
if ( ! V_37 ) {
F_14 ( V_36 ) ;
return - V_27 ;
}
V_36 [ 0 ] . type = V_44 ;
V_36 [ 0 ] . V_45 . V_6 . V_46 = V_37 -> V_16 ;
V_36 [ 0 ] . V_45 . V_6 . V_47 = V_32 -> V_16 ;
F_15 ( V_37 ) ;
V_36 ++ ;
for ( V_8 = V_39 = 0 ; V_8 < V_18 -> V_26 ; V_8 ++ ) {
if ( ! ( V_18 -> V_40 [ V_8 ] & V_41 ) ) {
V_36 [ V_39 ] . type = V_48 ;
V_36 [ V_39 ] . V_45 . V_40 . V_49 =
F_16 ( V_22 , V_18 -> V_15 [ V_8 ] ) ;
V_36 [ V_39 ] . V_45 . V_40 . V_40 = & V_18 -> V_40 [ V_8 ] ;
V_36 [ V_39 ] . V_45 . V_40 . V_50 = 1 ;
V_39 ++ ;
}
}
F_17 ( V_22 -> V_14 , L_4 ,
( * V_34 ) -> V_45 . V_6 . V_46 , ( * V_34 ) -> V_45 . V_6 . V_47 , V_38 ) ;
return 0 ;
}
static void F_18 ( struct V_21 * V_22 ,
struct V_33 * V_34 , unsigned V_35 )
{
F_14 ( V_34 ) ;
}
static int F_19 ( struct V_21 * V_22 , unsigned V_25 ,
unsigned V_47 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
const struct V_1 * V_7 ;
const unsigned * V_15 , * V_6 ;
unsigned int V_26 , V_51 ;
int V_8 ;
V_15 = V_3 -> V_20 [ V_47 ] . V_15 ;
V_26 = V_3 -> V_20 [ V_47 ] . V_26 ;
V_6 = V_3 -> V_20 [ V_47 ] . V_12 ;
F_20 ( ! V_15 || ! V_26 || ! V_6 ) ;
F_17 ( V_24 -> V_14 , L_5 ,
V_3 -> V_52 [ V_25 ] . V_16 , V_3 -> V_20 [ V_47 ] . V_16 ) ;
for ( V_8 = 0 ; V_8 < V_26 ; V_8 ++ ) {
V_51 = V_15 [ V_8 ] ;
V_7 = F_1 ( V_3 , V_51 , 1 , V_6 [ V_8 ] ) ;
if ( ! V_7 )
return - V_27 ;
if ( ! V_7 -> V_53 ) {
F_2 ( V_24 -> V_14 , L_6 ,
V_3 -> V_15 [ V_51 ] . V_16 ) ;
return - V_27 ;
}
F_21 ( V_6 [ V_8 ] , V_24 -> V_54 + V_7 -> V_53 ) ;
F_17 ( V_24 -> V_14 , L_7 ,
V_7 -> V_53 , V_6 [ V_8 ] ) ;
if ( V_7 -> V_55 ) {
F_21 ( V_7 -> V_56 , V_24 -> V_54 + V_7 -> V_55 ) ;
F_17 ( V_24 -> V_14 ,
L_8 ,
V_7 -> V_55 , V_7 -> V_56 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
return V_3 -> V_57 ;
}
static const char * F_23 ( struct V_21 * V_22 ,
unsigned V_25 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
return V_3 -> V_52 [ V_25 ] . V_16 ;
}
static int F_24 ( struct V_21 * V_22 , unsigned V_25 ,
const char * const * * V_20 ,
unsigned * const V_58 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
* V_20 = V_3 -> V_52 [ V_25 ] . V_20 ;
* V_58 = V_3 -> V_52 [ V_25 ] . V_58 ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 ,
unsigned V_51 , unsigned long * V_59 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_51 , 0 , 0 ) ;
if ( ! V_7 )
return - V_27 ;
if ( ! V_7 -> V_60 ) {
F_2 ( V_3 -> V_14 , L_9 ,
V_3 -> V_15 [ V_51 ] . V_16 ) ;
return - V_27 ;
}
* V_59 = F_26 ( V_24 -> V_54 + V_7 -> V_60 ) ;
return 0 ;
}
static int F_27 ( struct V_21 * V_22 ,
unsigned V_51 , unsigned long V_59 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_51 , 0 , 0 ) ;
if ( ! V_7 )
return - V_27 ;
if ( ! V_7 -> V_60 ) {
F_2 ( V_3 -> V_14 , L_9 ,
V_3 -> V_15 [ V_51 ] . V_16 ) ;
return - V_27 ;
}
F_17 ( V_24 -> V_14 , L_10 ,
V_3 -> V_15 [ V_51 ] . V_16 ) ;
F_21 ( V_59 , V_24 -> V_54 + V_7 -> V_60 ) ;
F_17 ( V_24 -> V_14 , L_11 ,
V_7 -> V_60 , V_59 ) ;
return 0 ;
}
static void F_28 ( struct V_21 * V_22 ,
struct V_28 * V_29 , unsigned V_51 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
const struct V_1 * V_7 ;
unsigned long V_59 ;
V_7 = F_1 ( V_3 , V_51 , 0 , 0 ) ;
if ( ! V_7 || ! V_7 -> V_60 ) {
F_9 ( V_29 , L_12 ) ;
return;
}
V_59 = F_26 ( V_24 -> V_54 + V_7 -> V_60 ) ;
F_9 ( V_29 , L_13 , V_59 ) ;
}
static void F_29 ( struct V_21 * V_22 ,
struct V_28 * V_29 , unsigned V_47 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
const struct V_2 * V_3 = V_24 -> V_3 ;
struct V_17 * V_18 ;
unsigned long V_59 ;
const char * V_16 ;
int V_8 , V_61 ;
if ( V_47 > V_3 -> V_19 )
return;
F_9 ( V_29 , L_14 ) ;
V_18 = & V_3 -> V_20 [ V_47 ] ;
for ( V_8 = 0 ; V_8 < V_18 -> V_26 ; V_8 ++ ) {
V_16 = F_16 ( V_22 , V_18 -> V_15 [ V_8 ] ) ;
V_61 = F_25 ( V_22 , V_18 -> V_15 [ V_8 ] , & V_59 ) ;
if ( V_61 )
return;
F_9 ( V_29 , L_15 , V_16 , V_59 ) ;
}
}
static int F_30 ( const struct V_2 * V_3 ,
unsigned int V_62 , unsigned int * V_51 ,
unsigned int * V_6 )
{
if ( V_62 > V_3 -> V_9 )
return - V_27 ;
* V_51 = V_3 -> V_10 [ V_62 ] . V_11 ;
* V_6 = V_3 -> V_10 [ V_62 ] . V_12 ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_2 * V_3 ,
T_1 V_63 )
{
unsigned int V_62 ;
int V_61 , V_64 ;
const T_2 * V_65 ;
int V_8 , V_39 ;
T_1 V_59 ;
F_17 ( V_3 -> V_14 , L_16 , V_63 , V_32 -> V_16 ) ;
V_18 -> V_16 = V_32 -> V_16 ;
V_65 = F_32 ( V_32 , L_17 , & V_64 ) ;
V_64 /= sizeof( * V_65 ) ;
if ( ! V_64 || V_64 % 2 ) {
F_2 ( V_3 -> V_14 , L_18 ) ;
return - V_27 ;
}
V_18 -> V_26 = V_64 / 2 ;
V_18 -> V_15 = F_33 ( V_3 -> V_14 , V_18 -> V_26 * sizeof( unsigned int ) ,
V_42 ) ;
V_18 -> V_12 = F_33 ( V_3 -> V_14 , V_18 -> V_26 * sizeof( unsigned int ) ,
V_42 ) ;
V_18 -> V_40 = F_33 ( V_3 -> V_14 , V_18 -> V_26 * sizeof( unsigned long ) ,
V_42 ) ;
for ( V_8 = 0 , V_39 = 0 ; V_8 < V_64 ; V_8 += 2 , V_39 ++ ) {
V_62 = F_34 ( * V_65 ++ ) ;
V_61 = F_30 ( V_3 , V_62 ,
& V_18 -> V_15 [ V_39 ] , & V_18 -> V_12 [ V_39 ] ) ;
if ( V_61 ) {
F_2 ( V_3 -> V_14 , L_19 ) ;
return - V_27 ;
}
V_59 = F_34 ( * V_65 ++ ) ;
if ( V_59 & V_66 )
V_18 -> V_12 [ V_39 ] |= V_67 ;
V_18 -> V_40 [ V_39 ] = V_59 & ~ V_66 ;
}
#ifdef F_35
F_36 ( V_3 , V_18 -> V_15 , V_18 -> V_12 , V_18 -> V_40 , V_18 -> V_26 ) ;
#endif
return 0 ;
}
static int F_37 ( struct V_31 * V_32 ,
struct V_2 * V_3 ,
T_1 V_63 )
{
struct V_31 * V_68 ;
struct V_69 * V_70 ;
struct V_17 * V_18 ;
int V_61 ;
static T_1 V_71 ;
T_1 V_8 = 0 ;
F_17 ( V_3 -> V_14 , L_20 , V_63 , V_32 -> V_16 ) ;
V_70 = & V_3 -> V_52 [ V_63 ] ;
V_70 -> V_16 = V_32 -> V_16 ;
V_70 -> V_58 = F_38 ( V_32 ) ;
if ( V_70 -> V_58 <= 0 ) {
F_2 ( V_3 -> V_14 , L_21 ) ;
return - V_27 ;
}
V_70 -> V_20 = F_33 ( V_3 -> V_14 ,
V_70 -> V_58 * sizeof( char * ) , V_42 ) ;
F_39 (np, child) {
V_70 -> V_20 [ V_8 ] = V_68 -> V_16 ;
V_18 = & V_3 -> V_20 [ V_71 ++ ] ;
V_61 = F_31 ( V_68 , V_18 , V_3 , V_8 ++ ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static int F_40 ( struct V_72 * V_73 ,
struct V_2 * V_3 )
{
struct V_31 * V_32 = V_73 -> V_14 . V_74 ;
struct V_31 * V_68 ;
int V_61 ;
T_1 V_75 = 0 ;
T_1 V_8 = 0 ;
if ( ! V_32 )
return - V_76 ;
V_75 = F_38 ( V_32 ) ;
if ( V_75 <= 0 ) {
F_2 ( & V_73 -> V_14 , L_22 ) ;
return - V_27 ;
}
V_3 -> V_57 = V_75 ;
V_3 -> V_52 = F_33 ( & V_73 -> V_14 , V_75 * sizeof( struct V_69 ) ,
V_42 ) ;
if ( ! V_3 -> V_52 )
return - V_43 ;
V_3 -> V_19 = 0 ;
F_39 (np, child)
V_3 -> V_19 += F_38 ( V_68 ) ;
V_3 -> V_20 = F_33 ( & V_73 -> V_14 , V_3 -> V_19 * sizeof( struct V_17 ) ,
V_42 ) ;
if ( ! V_3 -> V_20 )
return - V_43 ;
F_39 (np, child) {
V_61 = F_37 ( V_68 , V_3 , V_8 ++ ) ;
if ( V_61 ) {
F_2 ( & V_73 -> V_14 , L_23 ) ;
return V_61 ;
}
}
return 0 ;
}
int F_41 ( struct V_72 * V_73 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 ;
struct V_77 * V_78 ;
int V_61 ;
if ( ! V_3 || ! V_3 -> V_15 || ! V_3 -> V_26
|| ! V_3 -> V_10 || ! V_3 -> V_9 ) {
F_2 ( & V_73 -> V_14 , L_24 ) ;
return - V_27 ;
}
V_3 -> V_14 = & V_73 -> V_14 ;
V_24 = F_33 ( & V_73 -> V_14 , sizeof( * V_24 ) , V_42 ) ;
if ( ! V_24 )
return - V_43 ;
V_78 = F_42 ( V_73 , V_79 , 0 ) ;
if ( ! V_78 )
return - V_80 ;
V_24 -> V_54 = F_43 ( & V_73 -> V_14 , V_78 ) ;
if ( ! V_24 -> V_54 )
return - V_81 ;
V_82 . V_16 = F_10 ( & V_73 -> V_14 ) ;
V_82 . V_15 = V_3 -> V_15 ;
V_82 . V_26 = V_3 -> V_26 ;
V_61 = F_40 ( V_73 , V_3 ) ;
if ( V_61 ) {
F_2 ( & V_73 -> V_14 , L_25 ) ;
return V_61 ;
}
V_24 -> V_3 = V_3 ;
V_24 -> V_14 = V_3 -> V_14 ;
F_44 ( V_73 , V_24 ) ;
V_24 -> V_83 = F_45 ( & V_82 , & V_73 -> V_14 , V_24 ) ;
if ( ! V_24 -> V_83 ) {
F_2 ( & V_73 -> V_14 , L_26 ) ;
return - V_27 ;
}
F_46 ( & V_73 -> V_14 , L_27 ) ;
return 0 ;
}
int F_47 ( struct V_72 * V_73 )
{
struct V_23 * V_24 = F_48 ( V_73 ) ;
F_49 ( V_24 -> V_83 ) ;
return 0 ;
}
