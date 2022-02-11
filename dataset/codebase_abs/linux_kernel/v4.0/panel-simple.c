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
V_6 -> V_21 . V_22 = V_3 -> V_13 -> V_22 ;
V_6 -> V_21 . V_23 = V_3 -> V_13 -> V_24 . V_25 ;
V_6 -> V_21 . V_26 = V_3 -> V_13 -> V_24 . V_27 ;
if ( V_3 -> V_13 -> V_28 )
F_8 ( & V_6 -> V_21 ,
& V_3 -> V_13 -> V_28 , 1 ) ;
return V_12 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
if ( ! V_29 -> V_30 )
return 0 ;
if ( V_29 -> V_31 ) {
V_29 -> V_31 -> V_32 . V_33 = V_34 ;
F_10 ( V_29 -> V_31 ) ;
}
if ( V_29 -> V_13 -> V_35 . V_36 )
F_11 ( V_29 -> V_13 -> V_35 . V_36 ) ;
V_29 -> V_30 = false ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
if ( ! V_29 -> V_37 )
return 0 ;
if ( V_29 -> V_38 )
F_13 ( V_29 -> V_38 , 0 ) ;
F_14 ( V_29 -> V_39 ) ;
if ( V_29 -> V_13 -> V_35 . V_40 )
F_11 ( V_29 -> V_13 -> V_35 . V_40 ) ;
V_29 -> V_37 = false ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
int V_41 ;
if ( V_29 -> V_37 )
return 0 ;
V_41 = F_16 ( V_29 -> V_39 ) ;
if ( V_41 < 0 ) {
F_5 ( V_3 -> V_17 , L_2 , V_41 ) ;
return V_41 ;
}
if ( V_29 -> V_38 )
F_13 ( V_29 -> V_38 , 1 ) ;
if ( V_29 -> V_13 -> V_35 . V_42 )
F_11 ( V_29 -> V_13 -> V_35 . V_42 ) ;
V_29 -> V_37 = true ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
if ( V_29 -> V_30 )
return 0 ;
if ( V_29 -> V_13 -> V_35 . V_43 )
F_11 ( V_29 -> V_13 -> V_35 . V_43 ) ;
if ( V_29 -> V_31 ) {
V_29 -> V_31 -> V_32 . V_33 = V_44 ;
F_10 ( V_29 -> V_31 ) ;
}
V_29 -> V_30 = true ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
int V_12 = 0 ;
if ( V_29 -> V_45 ) {
struct V_46 * V_46 = F_19 ( V_3 -> V_6 , V_29 -> V_45 ) ;
F_20 ( V_3 -> V_6 , V_46 ) ;
if ( V_46 ) {
V_12 += F_21 ( V_3 -> V_6 , V_46 ) ;
F_22 ( V_46 ) ;
}
}
V_12 += F_3 ( V_29 ) ;
return V_12 ;
}
static int F_23 ( struct V_47 * V_17 , const struct V_48 * V_13 )
{
struct V_49 * V_31 , * V_45 ;
struct V_1 * V_3 ;
int V_41 ;
V_3 = F_24 ( V_17 , sizeof( * V_3 ) , V_50 ) ;
if ( ! V_3 )
return - V_51 ;
V_3 -> V_30 = false ;
V_3 -> V_37 = false ;
V_3 -> V_13 = V_13 ;
V_3 -> V_39 = F_25 ( V_17 , L_3 ) ;
if ( F_26 ( V_3 -> V_39 ) )
return F_27 ( V_3 -> V_39 ) ;
V_3 -> V_38 = F_28 ( V_17 , L_4 ,
V_52 ) ;
if ( F_26 ( V_3 -> V_38 ) ) {
V_41 = F_27 ( V_3 -> V_38 ) ;
F_5 ( V_17 , L_5 , V_41 ) ;
return V_41 ;
}
V_31 = F_29 ( V_17 -> V_53 , L_6 , 0 ) ;
if ( V_31 ) {
V_3 -> V_31 = F_30 ( V_31 ) ;
F_31 ( V_31 ) ;
if ( ! V_3 -> V_31 )
return - V_54 ;
}
V_45 = F_29 ( V_17 -> V_53 , L_7 , 0 ) ;
if ( V_45 ) {
V_3 -> V_45 = F_32 ( V_45 ) ;
F_31 ( V_45 ) ;
if ( ! V_3 -> V_45 ) {
V_41 = - V_54 ;
goto V_55;
}
}
F_33 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_17 = V_17 ;
V_3 -> V_4 . V_56 = & V_57 ;
V_41 = F_34 ( & V_3 -> V_4 ) ;
if ( V_41 < 0 )
goto V_58;
F_35 ( V_17 , V_3 ) ;
return 0 ;
V_58:
if ( V_3 -> V_45 )
F_36 ( & V_3 -> V_45 -> V_17 ) ;
V_55:
if ( V_3 -> V_31 )
F_36 ( & V_3 -> V_31 -> V_17 ) ;
return V_41 ;
}
static int F_37 ( struct V_47 * V_17 )
{
struct V_1 * V_3 = F_38 ( V_17 ) ;
F_39 ( & V_3 -> V_4 ) ;
F_40 ( & V_3 -> V_4 ) ;
F_9 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_45 )
F_36 ( & V_3 -> V_45 -> V_17 ) ;
if ( V_3 -> V_31 )
F_36 ( & V_3 -> V_31 -> V_17 ) ;
return 0 ;
}
static void F_41 ( struct V_47 * V_17 )
{
struct V_1 * V_3 = F_38 ( V_17 ) ;
F_9 ( & V_3 -> V_4 ) ;
}
static int F_42 ( struct V_59 * V_60 )
{
const struct V_61 * V_62 ;
V_62 = F_43 ( V_63 , V_60 -> V_17 . V_53 ) ;
if ( ! V_62 )
return - V_64 ;
return F_23 ( & V_60 -> V_17 , V_62 -> V_65 ) ;
}
static int F_44 ( struct V_59 * V_60 )
{
return F_37 ( & V_60 -> V_17 ) ;
}
static void F_45 ( struct V_59 * V_60 )
{
F_41 ( & V_60 -> V_17 ) ;
}
static int F_46 ( struct V_66 * V_67 )
{
const struct V_68 * V_13 ;
const struct V_61 * V_62 ;
int V_41 ;
V_62 = F_43 ( V_69 , V_67 -> V_17 . V_53 ) ;
if ( ! V_62 )
return - V_64 ;
V_13 = V_62 -> V_65 ;
V_41 = F_23 ( & V_67 -> V_17 , & V_13 -> V_13 ) ;
if ( V_41 < 0 )
return V_41 ;
V_67 -> V_70 = V_13 -> V_71 ;
V_67 -> V_72 = V_13 -> V_72 ;
V_67 -> V_73 = V_13 -> V_73 ;
return F_47 ( V_67 ) ;
}
static int F_48 ( struct V_66 * V_67 )
{
int V_41 ;
V_41 = F_49 ( V_67 ) ;
if ( V_41 < 0 )
F_5 ( & V_67 -> V_17 , L_8 , V_41 ) ;
return F_37 ( & V_67 -> V_17 ) ;
}
static void F_50 ( struct V_66 * V_67 )
{
F_41 ( & V_67 -> V_17 ) ;
}
static int T_1 F_51 ( void )
{
int V_41 ;
V_41 = F_52 ( & V_74 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( F_53 ( V_75 ) ) {
V_41 = F_54 ( & V_76 ) ;
if ( V_41 < 0 )
return V_41 ;
}
return 0 ;
}
static void T_2 F_55 ( void )
{
if ( F_53 ( V_75 ) )
F_56 ( & V_76 ) ;
F_57 ( & V_74 ) ;
}
