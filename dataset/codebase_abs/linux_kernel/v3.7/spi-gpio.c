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
unsigned int V_19 = V_1 -> V_20 [ V_3 -> V_21 ] ;
if ( V_18 )
F_5 ( V_3 , V_3 -> V_22 & V_23 ) ;
if ( V_19 != V_24 ) {
F_6 ( V_19 , ( V_3 -> V_22 & V_25 ) ? V_18 : ! V_18 ) ;
}
}
static int F_21 ( struct V_2 * V_3 )
{
unsigned int V_19 ;
int V_26 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_27 * V_28 = V_3 -> V_6 -> V_29 . V_30 ;
if ( V_3 -> V_31 > 32 )
return - V_32 ;
if ( V_28 ) {
V_19 = V_1 -> V_20 [ V_3 -> V_21 ] ;
} else {
V_19 = ( unsigned int ) V_3 -> V_33 ;
}
if ( ! V_3 -> V_34 ) {
if ( V_19 != V_24 ) {
V_26 = F_22 ( V_19 , F_23 ( & V_3 -> V_29 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_24 ( V_19 ,
! ( V_3 -> V_22 & V_25 ) ) ;
}
}
if ( ! V_26 ) {
V_26 = F_25 ( V_3 ) ;
V_1 -> V_20 [ V_3 -> V_21 ] = V_19 ;
}
if ( V_26 ) {
if ( ! V_3 -> V_34 && V_19 != V_24 )
F_26 ( V_19 ) ;
}
return V_26 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_19 = V_1 -> V_20 [ V_3 -> V_21 ] ;
if ( V_19 != V_24 )
F_26 ( V_19 ) ;
F_28 ( V_3 ) ;
}
static int T_4 F_29 ( unsigned V_35 , const char * V_36 , bool V_37 )
{
int V_38 ;
V_38 = F_22 ( V_35 , V_36 ) ;
if ( V_38 == 0 ) {
if ( V_37 )
V_38 = F_30 ( V_35 ) ;
else
V_38 = F_24 ( V_35 , 0 ) ;
}
return V_38 ;
}
static int T_4
F_31 ( struct V_8 * V_9 , const char * V_36 ,
T_5 * V_39 )
{
int V_38 ;
if ( V_12 != V_40 ) {
V_38 = F_29 ( V_12 , V_36 , false ) ;
if ( V_38 )
goto V_41;
} else {
* V_39 |= V_42 ;
}
if ( V_13 != V_43 ) {
V_38 = F_29 ( V_13 , V_36 , true ) ;
if ( V_38 )
goto V_44;
} else {
* V_39 |= V_45 ;
}
V_38 = F_29 ( V_11 , V_36 , false ) ;
if ( V_38 )
goto V_46;
goto V_41;
V_46:
if ( V_13 != V_43 )
F_26 ( V_13 ) ;
V_44:
if ( V_12 != V_40 )
F_26 ( V_12 ) ;
V_41:
return V_38 ;
}
static int F_32 ( struct V_47 * V_48 )
{
int V_49 ;
T_2 V_50 ;
struct V_8 * V_9 ;
struct V_27 * V_28 = V_48 -> V_29 . V_30 ;
const struct V_51 * V_52 =
F_33 ( V_53 , & V_48 -> V_29 ) ;
if ( ! V_52 )
return 0 ;
V_9 = F_34 ( & V_48 -> V_29 , sizeof( * V_9 ) , V_54 ) ;
if ( ! V_9 )
return - V_55 ;
V_9 -> V_56 = F_35 ( V_28 , L_1 , 0 ) ;
V_9 -> V_57 = F_35 ( V_28 , L_2 , 0 ) ;
V_9 -> V_58 = F_35 ( V_28 , L_3 , 0 ) ;
V_49 = F_36 ( V_28 , L_4 , & V_50 ) ;
if ( V_49 < 0 ) {
F_37 ( & V_48 -> V_29 , L_5 ) ;
goto V_59;
}
V_9 -> V_60 = V_50 ;
V_48 -> V_29 . V_61 = V_9 ;
return 1 ;
V_59:
F_38 ( & V_48 -> V_29 , V_9 ) ;
return V_49 ;
}
static inline int F_32 ( struct V_47 * V_48 )
{
return 0 ;
}
static int T_4 F_39 ( struct V_47 * V_48 )
{
int V_26 ;
struct V_62 * V_6 ;
struct V_1 * V_1 ;
struct V_8 * V_9 ;
T_5 V_63 = 0 ;
bool V_64 = 0 ;
V_26 = F_32 ( V_48 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 > 0 )
V_64 = 1 ;
V_9 = V_48 -> V_29 . V_61 ;
#ifdef F_40
if ( ! V_9 || ! V_9 -> V_60 )
return - V_65 ;
#endif
V_26 = F_31 ( V_9 , F_23 ( & V_48 -> V_29 ) , & V_63 ) ;
if ( V_26 < 0 )
return V_26 ;
V_6 = F_41 ( & V_48 -> V_29 , sizeof( * V_1 ) +
( sizeof( int ) * V_66 ) ) ;
if ( ! V_6 ) {
V_26 = - V_55 ;
goto F_26;
}
V_1 = F_2 ( V_6 ) ;
F_42 ( V_48 , V_1 ) ;
V_1 -> V_48 = V_48 ;
if ( V_9 )
V_1 -> V_9 = * V_9 ;
V_6 -> V_17 = V_63 ;
V_6 -> V_67 = V_48 -> V_68 ;
V_6 -> V_60 = V_66 ;
V_6 -> V_69 = F_21 ;
V_6 -> V_70 = F_27 ;
#ifdef F_43
V_6 -> V_29 . V_30 = V_48 -> V_29 . V_30 ;
if ( V_64 ) {
int V_71 ;
struct V_27 * V_28 = V_48 -> V_29 . V_30 ;
for ( V_71 = 0 ; V_71 < V_66 ; V_71 ++ )
V_1 -> V_20 [ V_71 ] =
F_35 ( V_28 , L_6 , V_71 ) ;
}
#endif
V_1 -> V_7 . V_6 = F_44 ( V_6 ) ;
V_1 -> V_7 . V_72 = F_20 ;
if ( ( V_63 & ( V_42 | V_45 ) ) == 0 ) {
V_1 -> V_7 . V_73 [ V_74 ] = F_10 ;
V_1 -> V_7 . V_73 [ V_75 ] = F_12 ;
V_1 -> V_7 . V_73 [ V_76 ] = F_14 ;
V_1 -> V_7 . V_73 [ V_77 ] = F_15 ;
} else {
V_1 -> V_7 . V_73 [ V_74 ] = F_16 ;
V_1 -> V_7 . V_73 [ V_75 ] = F_17 ;
V_1 -> V_7 . V_73 [ V_76 ] = F_18 ;
V_1 -> V_7 . V_73 [ V_77 ] = F_19 ;
}
V_1 -> V_7 . V_78 = V_79 ;
V_1 -> V_7 . V_17 = V_25 ;
V_26 = F_45 ( & V_1 -> V_7 ) ;
if ( V_26 < 0 ) {
F_46 ( V_1 -> V_7 . V_6 ) ;
F_26:
if ( V_13 != V_43 )
F_26 ( V_13 ) ;
if ( V_12 != V_40 )
F_26 ( V_12 ) ;
F_26 ( V_11 ) ;
F_46 ( V_6 ) ;
}
return V_26 ;
}
static int T_6 F_47 ( struct V_47 * V_48 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
int V_26 ;
V_1 = F_48 ( V_48 ) ;
V_9 = V_48 -> V_29 . V_61 ;
V_26 = F_49 ( & V_1 -> V_7 ) ;
F_46 ( V_1 -> V_7 . V_6 ) ;
F_42 ( V_48 , NULL ) ;
if ( V_13 != V_43 )
F_26 ( V_13 ) ;
if ( V_12 != V_40 )
F_26 ( V_12 ) ;
F_26 ( V_11 ) ;
return V_26 ;
}
