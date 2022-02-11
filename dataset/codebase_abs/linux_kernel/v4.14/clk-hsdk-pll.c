static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
const struct V_6 * V_7 )
{
T_1 V_4 = 0 ;
V_4 |= V_7 -> V_8 << V_9 ;
V_4 |= V_7 -> V_10 << V_11 ;
V_4 |= V_7 -> V_12 << V_13 ;
V_4 |= V_7 -> V_14 << V_15 ;
F_6 ( V_2 -> V_16 , L_1 , V_4 ) ;
F_1 ( V_2 , V_17 , V_4 ) ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return ! ! ( F_3 ( V_2 , V_18 ) & V_19 ) ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
return ! ! ( F_3 ( V_2 , V_18 ) & V_20 ) ;
}
static inline struct V_1 * F_9 ( struct V_21 * V_22 )
{
return F_10 ( V_22 , struct V_1 , V_22 ) ;
}
static unsigned long F_11 ( struct V_21 * V_22 ,
unsigned long V_23 )
{
T_1 V_4 ;
T_2 V_24 ;
T_1 V_8 , V_10 , V_12 ;
struct V_1 * V_2 = F_9 ( V_22 ) ;
V_4 = F_3 ( V_2 , V_17 ) ;
F_6 ( V_2 -> V_16 , L_2 , V_4 ) ;
if ( V_4 & V_25 )
return 0 ;
if ( V_4 & V_26 )
return V_23 ;
V_8 = 1 + ( ( V_4 & V_27 ) >> V_9 ) ;
V_10 = 2 * ( 1 + ( ( V_4 & V_28 ) >> V_11 ) ) ;
V_12 = 1 << ( ( V_4 & V_29 ) >> V_13 ) ;
V_24 = ( T_2 ) V_23 * V_10 ;
F_12 ( V_24 , V_8 * V_12 ) ;
return V_24 ;
}
static long F_13 ( struct V_21 * V_22 , unsigned long V_24 ,
unsigned long * V_30 )
{
int V_31 ;
unsigned long V_32 ;
struct V_1 * V_2 = F_9 ( V_22 ) ;
const struct V_6 * V_33 = V_2 -> V_34 -> V_33 ;
if ( V_33 [ 0 ] . V_24 == 0 )
return - V_35 ;
V_32 = V_33 [ 0 ] . V_24 ;
for ( V_31 = 1 ; V_33 [ V_31 ] . V_24 != 0 ; V_31 ++ ) {
if ( abs ( V_24 - V_33 [ V_31 ] . V_24 ) < abs ( V_24 - V_32 ) )
V_32 = V_33 [ V_31 ] . V_24 ;
}
F_6 ( V_2 -> V_16 , L_3 , V_32 ) ;
return V_32 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned long V_24 ,
const struct V_6 * V_7 )
{
F_5 ( V_2 , V_7 ) ;
F_15 ( V_36 ) ;
if ( ! F_7 ( V_2 ) )
return - V_37 ;
if ( F_8 ( V_2 ) )
return - V_35 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned long V_24 ,
const struct V_6 * V_7 )
{
if ( V_24 > V_38 )
F_2 ( V_39 , V_2 -> V_40 ) ;
F_5 ( V_2 , V_7 ) ;
F_15 ( V_36 ) ;
if ( ! F_7 ( V_2 ) )
return - V_37 ;
if ( F_8 ( V_2 ) )
return - V_35 ;
if ( V_24 <= V_38 )
F_2 ( V_41 , V_2 -> V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_21 * V_22 , unsigned long V_24 ,
unsigned long V_23 )
{
int V_31 ;
struct V_1 * V_2 = F_9 ( V_22 ) ;
const struct V_6 * V_33 = V_2 -> V_34 -> V_33 ;
for ( V_31 = 0 ; V_33 [ V_31 ] . V_24 != 0 ; V_31 ++ ) {
if ( V_33 [ V_31 ] . V_24 == V_24 ) {
return V_2 -> V_34 -> V_42 ( V_2 , V_24 ,
& V_33 [ V_31 ] ) ;
}
}
F_18 ( V_2 -> V_16 , L_4 , V_24 ,
V_23 ) ;
return - V_35 ;
}
static int F_19 ( struct V_43 * V_44 )
{
int V_45 ;
struct V_46 * V_47 ;
const char * V_48 ;
unsigned int V_49 ;
struct V_1 * V_50 ;
struct V_51 V_52 = { } ;
struct V_53 * V_16 = & V_44 -> V_16 ;
V_50 = F_20 ( V_16 , sizeof( * V_50 ) , V_54 ) ;
if ( ! V_50 )
return - V_55 ;
V_47 = F_21 ( V_44 , V_56 , 0 ) ;
V_50 -> V_5 = F_22 ( V_16 , V_47 ) ;
if ( F_23 ( V_50 -> V_5 ) )
return F_24 ( V_50 -> V_5 ) ;
V_52 . V_57 = V_16 -> V_58 -> V_57 ;
V_52 . V_59 = & V_60 ;
V_48 = F_25 ( V_16 -> V_58 , 0 ) ;
V_52 . V_61 = & V_48 ;
V_49 = F_26 ( V_16 -> V_58 ) ;
if ( V_49 == 0 || V_49 > V_62 ) {
F_18 ( V_16 , L_5 , V_49 ) ;
return - V_35 ;
}
V_52 . V_49 = V_49 ;
V_50 -> V_22 . V_52 = & V_52 ;
V_50 -> V_16 = V_16 ;
V_50 -> V_34 = F_27 ( V_16 ) ;
if ( ! V_50 -> V_34 ) {
F_18 ( V_16 , L_6 ) ;
return - V_35 ;
}
V_45 = F_28 ( V_16 , & V_50 -> V_22 ) ;
if ( V_45 ) {
F_18 ( V_16 , L_7 , V_52 . V_57 ) ;
return V_45 ;
}
return F_29 ( V_16 -> V_58 , V_63 ,
& V_50 -> V_22 ) ;
}
static int F_30 ( struct V_43 * V_44 )
{
F_31 ( V_44 -> V_16 . V_58 ) ;
return 0 ;
}
static void T_3 F_32 ( struct V_64 * V_65 )
{
int V_45 ;
const char * V_48 ;
unsigned int V_49 ;
struct V_1 * V_50 ;
struct V_51 V_52 = { } ;
V_50 = F_33 ( sizeof( * V_50 ) , V_54 ) ;
if ( ! V_50 )
return;
V_50 -> V_5 = F_34 ( V_65 , 0 ) ;
if ( ! V_50 -> V_5 ) {
F_35 ( L_8 ) ;
goto V_66;
}
V_50 -> V_40 = F_34 ( V_65 , 1 ) ;
if ( ! V_50 -> V_40 ) {
F_35 ( L_8 ) ;
goto V_67;
}
V_52 . V_57 = V_65 -> V_57 ;
V_52 . V_59 = & V_60 ;
V_48 = F_25 ( V_65 , 0 ) ;
V_52 . V_61 = & V_48 ;
V_49 = F_26 ( V_65 ) ;
if ( V_49 > V_62 ) {
F_35 ( L_9 , V_49 ) ;
goto V_68;
}
V_52 . V_49 = V_49 ;
V_50 -> V_22 . V_52 = & V_52 ;
V_50 -> V_34 = & V_69 ;
V_45 = F_36 ( NULL , & V_50 -> V_22 ) ;
if ( V_45 ) {
F_35 ( L_7 , V_65 -> V_57 ) ;
goto V_68;
}
V_45 = F_29 ( V_65 , V_63 , & V_50 -> V_22 ) ;
if ( V_45 ) {
F_35 ( L_10 , V_65 -> V_57 ) ;
goto V_68;
}
return;
V_68:
F_37 ( V_50 -> V_40 ) ;
V_67:
F_37 ( V_50 -> V_5 ) ;
V_66:
F_38 ( V_50 ) ;
}
