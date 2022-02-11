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
if ( V_28 ) {
V_19 = V_1 -> V_20 [ V_3 -> V_21 ] ;
} else {
V_19 = ( unsigned int ) V_3 -> V_31 ;
}
if ( ! V_3 -> V_32 ) {
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
if ( ! V_3 -> V_32 && V_19 != V_24 )
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
static int F_29 ( unsigned V_33 , const char * V_34 , bool V_35 )
{
int V_36 ;
V_36 = F_22 ( V_33 , V_34 ) ;
if ( V_36 == 0 ) {
if ( V_35 )
V_36 = F_30 ( V_33 ) ;
else
V_36 = F_24 ( V_33 , 0 ) ;
}
return V_36 ;
}
static int F_31 ( struct V_8 * V_9 ,
const char * V_34 , T_4 * V_37 )
{
int V_36 ;
if ( V_12 != V_38 ) {
V_36 = F_29 ( V_12 , V_34 , false ) ;
if ( V_36 )
goto V_39;
} else {
* V_37 |= V_40 ;
}
if ( V_13 != V_41 ) {
V_36 = F_29 ( V_13 , V_34 , true ) ;
if ( V_36 )
goto V_42;
} else {
* V_37 |= V_43 ;
}
V_36 = F_29 ( V_11 , V_34 , false ) ;
if ( V_36 )
goto V_44;
goto V_39;
V_44:
if ( V_13 != V_41 )
F_26 ( V_13 ) ;
V_42:
if ( V_12 != V_38 )
F_26 ( V_12 ) ;
V_39:
return V_36 ;
}
static int F_32 ( struct V_45 * V_46 )
{
int V_47 ;
T_2 V_48 ;
struct V_8 * V_9 ;
struct V_27 * V_28 = V_46 -> V_29 . V_30 ;
const struct V_49 * V_50 =
F_33 ( V_51 , & V_46 -> V_29 ) ;
if ( ! V_50 )
return 0 ;
V_9 = F_34 ( & V_46 -> V_29 , sizeof( * V_9 ) , V_52 ) ;
if ( ! V_9 )
return - V_53 ;
V_47 = F_35 ( V_28 , L_1 , 0 ) ;
if ( V_47 < 0 ) {
F_36 ( & V_46 -> V_29 , L_2 ) ;
goto V_54;
}
V_9 -> V_55 = V_47 ;
V_47 = F_35 ( V_28 , L_3 , 0 ) ;
if ( V_47 < 0 ) {
F_37 ( & V_46 -> V_29 , L_4 ) ;
V_9 -> V_56 = V_41 ;
} else
V_9 -> V_56 = V_47 ;
V_47 = F_35 ( V_28 , L_5 , 0 ) ;
if ( V_47 < 0 ) {
F_37 ( & V_46 -> V_29 , L_6 ) ;
V_9 -> V_57 = V_38 ;
} else
V_9 -> V_57 = V_47 ;
V_47 = F_38 ( V_28 , L_7 , & V_48 ) ;
if ( V_47 < 0 ) {
F_36 ( & V_46 -> V_29 , L_8 ) ;
goto V_54;
}
V_9 -> V_58 = V_48 ;
V_46 -> V_29 . V_59 = V_9 ;
return 1 ;
V_54:
F_39 ( & V_46 -> V_29 , V_9 ) ;
return V_47 ;
}
static inline int F_32 ( struct V_45 * V_46 )
{
return 0 ;
}
static int F_40 ( struct V_45 * V_46 )
{
int V_26 ;
struct V_60 * V_6 ;
struct V_1 * V_1 ;
struct V_8 * V_9 ;
T_4 V_61 = 0 ;
bool V_62 = 0 ;
V_26 = F_32 ( V_46 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 > 0 )
V_62 = 1 ;
V_9 = F_41 ( & V_46 -> V_29 ) ;
#ifdef F_42
if ( ! V_9 || ! V_9 -> V_58 )
return - V_63 ;
#endif
V_26 = F_31 ( V_9 , F_23 ( & V_46 -> V_29 ) , & V_61 ) ;
if ( V_26 < 0 )
return V_26 ;
V_6 = F_43 ( & V_46 -> V_29 , sizeof( * V_1 ) +
( sizeof( int ) * V_64 ) ) ;
if ( ! V_6 ) {
V_26 = - V_53 ;
goto F_26;
}
V_1 = F_2 ( V_6 ) ;
F_44 ( V_46 , V_1 ) ;
V_1 -> V_46 = V_46 ;
if ( V_9 )
V_1 -> V_9 = * V_9 ;
V_6 -> V_65 = F_45 ( 1 , 32 ) ;
V_6 -> V_17 = V_61 ;
V_6 -> V_66 = V_46 -> V_67 ;
V_6 -> V_58 = V_64 ;
V_6 -> V_68 = F_21 ;
V_6 -> V_69 = F_27 ;
#ifdef F_46
V_6 -> V_29 . V_30 = V_46 -> V_29 . V_30 ;
if ( V_62 ) {
int V_70 ;
struct V_27 * V_28 = V_46 -> V_29 . V_30 ;
for ( V_70 = 0 ; V_70 < V_64 ; V_70 ++ )
V_1 -> V_20 [ V_70 ] =
F_35 ( V_28 , L_9 , V_70 ) ;
}
#endif
V_1 -> V_7 . V_6 = F_47 ( V_6 ) ;
V_1 -> V_7 . V_71 = F_20 ;
if ( ( V_61 & ( V_40 | V_43 ) ) == 0 ) {
V_1 -> V_7 . V_72 [ V_73 ] = F_10 ;
V_1 -> V_7 . V_72 [ V_74 ] = F_12 ;
V_1 -> V_7 . V_72 [ V_75 ] = F_14 ;
V_1 -> V_7 . V_72 [ V_76 ] = F_15 ;
} else {
V_1 -> V_7 . V_72 [ V_73 ] = F_16 ;
V_1 -> V_7 . V_72 [ V_74 ] = F_17 ;
V_1 -> V_7 . V_72 [ V_75 ] = F_18 ;
V_1 -> V_7 . V_72 [ V_76 ] = F_19 ;
}
V_1 -> V_7 . V_77 = V_78 ;
V_1 -> V_7 . V_17 = V_25 ;
V_26 = F_48 ( & V_1 -> V_7 ) ;
if ( V_26 < 0 ) {
F_49 ( V_1 -> V_7 . V_6 ) ;
F_26:
if ( V_13 != V_41 )
F_26 ( V_13 ) ;
if ( V_12 != V_38 )
F_26 ( V_12 ) ;
F_26 ( V_11 ) ;
F_49 ( V_6 ) ;
}
return V_26 ;
}
static int F_50 ( struct V_45 * V_46 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
int V_26 ;
V_1 = F_51 ( V_46 ) ;
V_9 = F_41 ( & V_46 -> V_29 ) ;
V_26 = F_52 ( & V_1 -> V_7 ) ;
F_49 ( V_1 -> V_7 . V_6 ) ;
if ( V_13 != V_41 )
F_26 ( V_13 ) ;
if ( V_12 != V_38 )
F_26 ( V_12 ) ;
F_26 ( V_11 ) ;
return V_26 ;
}
