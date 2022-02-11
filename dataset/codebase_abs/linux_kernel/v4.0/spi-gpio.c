static inline struct V_1 * T_1
F_1 ( const struct V_2 * V_3 )
{
const struct V_4 * V_5 ;
struct V_1 * V_1 ;
V_5 = F_2 ( V_3 -> V_6 ) ;
V_1 = F_3 ( V_5 , struct V_1 , V_7 ) ;
return V_1 ;
}
static inline struct V_8 * T_1
F_4 ( const struct V_2 * V_3 )
{
return & F_1 ( V_3 ) -> V_9 ;
}
static inline void F_5 ( const struct V_2 * V_3 , int V_10 )
{
F_6 ( V_11 , V_10 ) ;
}
static inline void F_7 ( const struct V_2 * V_3 , int V_10 )
{
F_6 ( V_12 , V_10 ) ;
}
static inline int F_8 ( const struct V_2 * V_3 )
{
return ! ! F_9 ( V_13 ) ;
}
static T_2 F_10 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
return F_11 ( V_3 , V_14 , 0 , 0 , V_15 , V_16 ) ;
}
static T_2 F_12 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
return F_13 ( V_3 , V_14 , 0 , 0 , V_15 , V_16 ) ;
}
static T_2 F_14 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
return F_11 ( V_3 , V_14 , 1 , 0 , V_15 , V_16 ) ;
}
static T_2 F_15 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
return F_13 ( V_3 , V_14 , 1 , 0 , V_15 , V_16 ) ;
}
static T_2 F_16 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
unsigned V_17 = V_3 -> V_6 -> V_17 ;
return F_11 ( V_3 , V_14 , 0 , V_17 , V_15 , V_16 ) ;
}
static T_2 F_17 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
unsigned V_17 = V_3 -> V_6 -> V_17 ;
return F_13 ( V_3 , V_14 , 0 , V_17 , V_15 , V_16 ) ;
}
static T_2 F_18 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
unsigned V_17 = V_3 -> V_6 -> V_17 ;
return F_11 ( V_3 , V_14 , 1 , V_17 , V_15 , V_16 ) ;
}
static T_2 F_19 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
unsigned V_17 = V_3 -> V_6 -> V_17 ;
return F_13 ( V_3 , V_14 , 1 , V_17 , V_15 , V_16 ) ;
}
static void F_20 ( struct V_2 * V_3 , int V_18 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_19 = V_1 -> V_20 [ V_3 -> V_21 ] ;
if ( V_18 )
F_5 ( V_3 , V_3 -> V_22 & V_23 ) ;
if ( V_19 != V_24 ) {
F_6 ( V_19 , ( V_3 -> V_22 & V_25 ) ? V_18 : ! V_18 ) ;
}
}
static int F_21 ( struct V_2 * V_3 )
{
unsigned long V_19 ;
int V_26 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_27 * V_28 = V_3 -> V_6 -> V_29 . V_30 ;
if ( V_28 ) {
V_19 = V_1 -> V_20 [ V_3 -> V_21 ] ;
} else {
V_19 = ( V_31 ) V_3 -> V_32 ;
}
if ( ! V_3 -> V_33 ) {
if ( V_19 != V_24 ) {
V_26 = F_22 ( V_19 , F_23 ( & V_3 -> V_29 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_24 ( V_19 ,
! ( V_3 -> V_22 & V_25 ) ) ;
}
}
if ( ! V_26 ) {
V_1 -> V_20 [ V_3 -> V_21 ] = V_19 ;
V_26 = F_25 ( V_3 ) ;
}
if ( V_26 ) {
if ( ! V_3 -> V_33 && V_19 != V_24 )
F_26 ( V_19 ) ;
}
return V_26 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_19 = V_1 -> V_20 [ V_3 -> V_21 ] ;
if ( V_19 != V_24 )
F_26 ( V_19 ) ;
F_28 ( V_3 ) ;
}
static int F_29 ( unsigned V_34 , const char * V_35 , bool V_36 )
{
int V_37 ;
V_37 = F_22 ( V_34 , V_35 ) ;
if ( V_37 == 0 ) {
if ( V_36 )
V_37 = F_30 ( V_34 ) ;
else
V_37 = F_24 ( V_34 , 0 ) ;
}
return V_37 ;
}
static int F_31 ( struct V_8 * V_9 ,
const char * V_35 , T_4 * V_38 )
{
int V_37 ;
if ( V_12 != V_39 ) {
V_37 = F_29 ( V_12 , V_35 , false ) ;
if ( V_37 )
goto V_40;
} else {
* V_38 |= V_41 ;
}
if ( V_13 != V_42 ) {
V_37 = F_29 ( V_13 , V_35 , true ) ;
if ( V_37 )
goto V_43;
} else {
* V_38 |= V_44 ;
}
V_37 = F_29 ( V_11 , V_35 , false ) ;
if ( V_37 )
goto V_45;
goto V_40;
V_45:
if ( V_13 != V_42 )
F_26 ( V_13 ) ;
V_43:
if ( V_12 != V_39 )
F_26 ( V_12 ) ;
V_40:
return V_37 ;
}
static int F_32 ( struct V_46 * V_47 )
{
int V_48 ;
T_2 V_49 ;
struct V_8 * V_9 ;
struct V_27 * V_28 = V_47 -> V_29 . V_30 ;
const struct V_50 * V_51 =
F_33 ( V_52 , & V_47 -> V_29 ) ;
if ( ! V_51 )
return 0 ;
V_9 = F_34 ( & V_47 -> V_29 , sizeof( * V_9 ) , V_53 ) ;
if ( ! V_9 )
return - V_54 ;
V_48 = F_35 ( V_28 , L_1 , 0 ) ;
if ( V_48 < 0 ) {
F_36 ( & V_47 -> V_29 , L_2 ) ;
goto V_55;
}
V_9 -> V_56 = V_48 ;
V_48 = F_35 ( V_28 , L_3 , 0 ) ;
if ( V_48 < 0 ) {
F_37 ( & V_47 -> V_29 , L_4 ) ;
V_9 -> V_57 = V_42 ;
} else
V_9 -> V_57 = V_48 ;
V_48 = F_35 ( V_28 , L_5 , 0 ) ;
if ( V_48 < 0 ) {
F_37 ( & V_47 -> V_29 , L_6 ) ;
V_9 -> V_58 = V_39 ;
} else
V_9 -> V_58 = V_48 ;
V_48 = F_38 ( V_28 , L_7 , & V_49 ) ;
if ( V_48 < 0 ) {
F_36 ( & V_47 -> V_29 , L_8 ) ;
goto V_55;
}
V_9 -> V_59 = V_49 ;
V_47 -> V_29 . V_60 = V_9 ;
return 1 ;
V_55:
F_39 ( & V_47 -> V_29 , V_9 ) ;
return V_48 ;
}
static inline int F_32 ( struct V_46 * V_47 )
{
return 0 ;
}
static int F_40 ( struct V_46 * V_47 )
{
int V_26 ;
struct V_61 * V_6 ;
struct V_1 * V_1 ;
struct V_8 * V_9 ;
T_4 V_62 = 0 ;
bool V_63 = 0 ;
int V_64 ;
V_26 = F_32 ( V_47 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 > 0 )
V_63 = 1 ;
V_9 = F_41 ( & V_47 -> V_29 ) ;
#ifdef F_42
if ( ! V_9 || ( ! V_63 && ! V_9 -> V_59 ) )
return - V_65 ;
#endif
if ( V_63 && ! V_66 )
V_64 = 1 ;
else
V_64 = V_66 ;
V_26 = F_31 ( V_9 , F_23 ( & V_47 -> V_29 ) , & V_62 ) ;
if ( V_26 < 0 )
return V_26 ;
V_6 = F_43 ( & V_47 -> V_29 , sizeof( * V_1 ) +
(sizeof( unsigned long ) * V_64 ) ) ;
if ( ! V_6 ) {
V_26 = - V_54 ;
goto F_26;
}
V_1 = F_2 ( V_6 ) ;
F_44 ( V_47 , V_1 ) ;
V_1 -> V_47 = V_47 ;
if ( V_9 )
V_1 -> V_9 = * V_9 ;
V_6 -> V_67 = F_45 ( 1 , 32 ) ;
V_6 -> V_17 = V_62 ;
V_6 -> V_68 = V_47 -> V_69 ;
V_6 -> V_59 = V_64 ;
V_6 -> V_70 = F_21 ;
V_6 -> V_71 = F_27 ;
#ifdef F_46
V_6 -> V_29 . V_30 = V_47 -> V_29 . V_30 ;
if ( V_63 ) {
int V_72 ;
struct V_27 * V_28 = V_47 -> V_29 . V_30 ;
if ( ! V_66 )
V_1 -> V_20 [ 0 ] = V_24 ;
else
for ( V_72 = 0 ; V_72 < V_66 ; V_72 ++ ) {
V_26 = F_35 ( V_28 , L_9 , V_72 ) ;
if ( V_26 < 0 ) {
F_36 ( & V_47 -> V_29 ,
L_10 ) ;
goto F_26;
}
V_1 -> V_20 [ V_72 ] = V_26 ;
}
}
#endif
V_1 -> V_7 . V_6 = V_6 ;
V_1 -> V_7 . V_73 = F_20 ;
if ( ( V_62 & ( V_41 | V_44 ) ) == 0 ) {
V_1 -> V_7 . V_74 [ V_75 ] = F_10 ;
V_1 -> V_7 . V_74 [ V_76 ] = F_12 ;
V_1 -> V_7 . V_74 [ V_77 ] = F_14 ;
V_1 -> V_7 . V_74 [ V_78 ] = F_15 ;
} else {
V_1 -> V_7 . V_74 [ V_75 ] = F_16 ;
V_1 -> V_7 . V_74 [ V_76 ] = F_17 ;
V_1 -> V_7 . V_74 [ V_77 ] = F_18 ;
V_1 -> V_7 . V_74 [ V_78 ] = F_19 ;
}
V_1 -> V_7 . V_79 = V_80 ;
V_1 -> V_7 . V_17 = V_25 ;
V_26 = F_47 ( & V_1 -> V_7 ) ;
if ( V_26 < 0 ) {
F_26:
if ( V_13 != V_42 )
F_26 ( V_13 ) ;
if ( V_12 != V_39 )
F_26 ( V_12 ) ;
F_26 ( V_11 ) ;
F_48 ( V_6 ) ;
}
return V_26 ;
}
static int F_49 ( struct V_46 * V_47 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
V_1 = F_50 ( V_47 ) ;
V_9 = F_41 ( & V_47 -> V_29 ) ;
F_51 ( & V_1 -> V_7 ) ;
if ( V_13 != V_42 )
F_26 ( V_13 ) ;
if ( V_12 != V_39 )
F_26 ( V_12 ) ;
F_26 ( V_11 ) ;
F_48 ( V_1 -> V_7 . V_6 ) ;
return 0 ;
}
