static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_4 . V_6 ;
struct V_7 * V_8 = V_3 -> V_4 . V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 , V_12 = 0 ;
if ( ! V_3 -> V_13 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_3 -> V_13 -> V_14 ; V_11 ++ ) {
const struct V_9 * V_15 = & V_3 -> V_13 -> V_16 [ V_11 ] ;
V_10 = F_4 ( V_8 , V_15 ) ;
if ( ! V_10 ) {
F_5 ( V_8 -> V_17 , L_1 ,
V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 ) ;
continue;
}
F_6 ( V_10 ) ;
F_7 ( V_6 , V_10 ) ;
V_12 ++ ;
}
V_6 -> V_21 . V_22 = V_3 -> V_13 -> V_23 . V_24 ;
V_6 -> V_21 . V_25 = V_3 -> V_13 -> V_23 . V_26 ;
return V_12 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
if ( ! V_27 -> V_28 )
return 0 ;
if ( V_27 -> V_29 ) {
V_27 -> V_29 -> V_30 . V_31 = V_32 ;
F_9 ( V_27 -> V_29 ) ;
}
if ( F_10 ( V_27 -> V_33 ) ) {
if ( V_27 -> V_34 & V_35 )
F_11 ( V_27 -> V_33 , 1 ) ;
else
F_11 ( V_27 -> V_33 , 0 ) ;
}
F_12 ( V_27 -> V_36 ) ;
V_27 -> V_28 = false ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
int V_37 ;
if ( V_27 -> V_28 )
return 0 ;
V_37 = F_14 ( V_27 -> V_36 ) ;
if ( V_37 < 0 ) {
F_5 ( V_3 -> V_17 , L_2 , V_37 ) ;
return V_37 ;
}
if ( F_10 ( V_27 -> V_33 ) ) {
if ( V_27 -> V_34 & V_35 )
F_11 ( V_27 -> V_33 , 0 ) ;
else
F_11 ( V_27 -> V_33 , 1 ) ;
}
if ( V_27 -> V_29 ) {
V_27 -> V_29 -> V_30 . V_31 = V_38 ;
F_9 ( V_27 -> V_29 ) ;
}
V_27 -> V_28 = true ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
int V_12 = 0 ;
if ( V_27 -> V_39 ) {
struct V_40 * V_40 = F_16 ( V_3 -> V_6 , V_27 -> V_39 ) ;
F_17 ( V_3 -> V_6 , V_40 ) ;
if ( V_40 ) {
V_12 += F_18 ( V_3 -> V_6 , V_40 ) ;
F_19 ( V_40 ) ;
}
}
V_12 += F_3 ( V_27 ) ;
return V_12 ;
}
static int F_20 ( struct V_41 * V_17 , const struct V_42 * V_13 )
{
struct V_43 * V_29 , * V_39 ;
struct V_1 * V_3 ;
enum V_44 V_45 ;
int V_37 ;
V_3 = F_21 ( V_17 , sizeof( * V_3 ) , V_46 ) ;
if ( ! V_3 )
return - V_47 ;
V_3 -> V_28 = false ;
V_3 -> V_13 = V_13 ;
V_3 -> V_36 = F_22 ( V_17 , L_3 ) ;
if ( F_23 ( V_3 -> V_36 ) )
return F_24 ( V_3 -> V_36 ) ;
V_3 -> V_33 = F_25 ( V_17 -> V_48 ,
L_4 , 0 ,
& V_45 ) ;
if ( F_10 ( V_3 -> V_33 ) ) {
unsigned int V_49 ;
if ( V_45 & V_50 )
V_3 -> V_34 |= V_35 ;
V_37 = F_26 ( V_3 -> V_33 , L_5 ) ;
if ( V_37 < 0 ) {
F_5 ( V_17 , L_6 ,
V_3 -> V_33 , V_37 ) ;
return V_37 ;
}
V_49 = ( V_3 -> V_34 & V_35 ) != 0 ;
V_37 = F_27 ( V_3 -> V_33 , V_49 ) ;
if ( V_37 < 0 ) {
F_5 ( V_17 , L_7 ,
V_3 -> V_33 , V_37 ) ;
goto V_51;
}
}
V_29 = F_28 ( V_17 -> V_48 , L_8 , 0 ) ;
if ( V_29 ) {
V_3 -> V_29 = F_29 ( V_29 ) ;
F_30 ( V_29 ) ;
if ( ! V_3 -> V_29 ) {
V_37 = - V_52 ;
goto V_51;
}
}
V_39 = F_28 ( V_17 -> V_48 , L_9 , 0 ) ;
if ( V_39 ) {
V_3 -> V_39 = F_31 ( V_39 ) ;
F_30 ( V_39 ) ;
if ( ! V_3 -> V_39 ) {
V_37 = - V_52 ;
goto V_53;
}
}
F_32 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_17 = V_17 ;
V_3 -> V_4 . V_54 = & V_55 ;
V_37 = F_33 ( & V_3 -> V_4 ) ;
if ( V_37 < 0 )
goto V_56;
F_34 ( V_17 , V_3 ) ;
return 0 ;
V_56:
if ( V_3 -> V_39 )
F_35 ( & V_3 -> V_39 -> V_17 ) ;
V_53:
if ( V_3 -> V_29 )
F_35 ( & V_3 -> V_29 -> V_17 ) ;
V_51:
if ( F_10 ( V_3 -> V_33 ) )
F_36 ( V_3 -> V_33 ) ;
return V_37 ;
}
static int F_37 ( struct V_41 * V_17 )
{
struct V_1 * V_3 = F_38 ( V_17 ) ;
F_39 ( & V_3 -> V_4 ) ;
F_40 ( & V_3 -> V_4 ) ;
F_8 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_39 )
F_35 ( & V_3 -> V_39 -> V_17 ) ;
if ( V_3 -> V_29 )
F_35 ( & V_3 -> V_29 -> V_17 ) ;
if ( F_10 ( V_3 -> V_33 ) )
F_36 ( V_3 -> V_33 ) ;
F_12 ( V_3 -> V_36 ) ;
return 0 ;
}
static int F_41 ( struct V_57 * V_58 )
{
const struct V_59 * V_60 ;
V_60 = F_42 ( V_61 , V_58 -> V_17 . V_48 ) ;
if ( ! V_60 )
return - V_62 ;
return F_20 ( & V_58 -> V_17 , V_60 -> V_63 ) ;
}
static int F_43 ( struct V_57 * V_58 )
{
return F_37 ( & V_58 -> V_17 ) ;
}
static int F_44 ( struct V_64 * V_65 )
{
const struct V_66 * V_13 ;
const struct V_59 * V_60 ;
int V_37 ;
V_60 = F_42 ( V_67 , V_65 -> V_17 . V_48 ) ;
if ( ! V_60 )
return - V_62 ;
V_13 = V_60 -> V_63 ;
V_37 = F_20 ( & V_65 -> V_17 , & V_13 -> V_13 ) ;
if ( V_37 < 0 )
return V_37 ;
V_65 -> V_68 = V_13 -> V_68 ;
V_65 -> V_69 = V_13 -> V_69 ;
return F_45 ( V_65 ) ;
}
static int F_46 ( struct V_64 * V_65 )
{
int V_37 ;
V_37 = F_47 ( V_65 ) ;
if ( V_37 < 0 )
F_5 ( & V_65 -> V_17 , L_10 , V_37 ) ;
return F_37 ( & V_65 -> V_17 ) ;
}
static int T_1 F_48 ( void )
{
int V_37 ;
V_37 = F_49 ( & V_70 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( F_50 ( V_71 ) ) {
V_37 = F_51 ( & V_72 ) ;
if ( V_37 < 0 )
return V_37 ;
}
return 0 ;
}
static void T_2 F_52 ( void )
{
if ( F_50 ( V_71 ) )
F_53 ( & V_72 ) ;
F_54 ( & V_70 ) ;
}
