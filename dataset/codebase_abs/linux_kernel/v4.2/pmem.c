static void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned int V_4 , unsigned int V_5 , int V_6 ,
T_1 V_7 )
{
void * V_8 = F_2 ( V_3 ) ;
T_2 V_9 = V_7 << 9 ;
void T_3 * V_10 = V_2 -> V_11 + V_9 ;
if ( V_6 == V_12 ) {
F_3 ( V_8 + V_5 , V_10 , V_4 ) ;
F_4 ( V_3 ) ;
} else {
F_4 ( V_3 ) ;
F_5 ( V_10 , V_8 + V_5 , V_4 ) ;
}
F_6 ( V_8 ) ;
}
static void F_7 ( struct V_13 * V_14 , struct V_15 * V_15 )
{
bool V_16 ;
unsigned long V_17 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
struct V_22 * V_23 = V_15 -> V_24 ;
struct V_1 * V_2 = V_23 -> V_25 -> V_26 ;
V_16 = F_8 ( V_15 , & V_17 ) ;
F_9 (bvec, bio, iter)
F_1 ( V_2 , V_19 . V_27 , V_19 . V_28 , V_19 . V_29 ,
F_10 ( V_15 ) , V_21 . V_30 ) ;
if ( V_16 )
F_11 ( V_15 , V_17 ) ;
if ( F_10 ( V_15 ) )
F_12 () ;
F_13 ( V_15 , 0 ) ;
}
static int F_14 ( struct V_22 * V_23 , T_1 V_7 ,
struct V_3 * V_3 , int V_6 )
{
struct V_1 * V_2 = V_23 -> V_25 -> V_26 ;
F_1 ( V_2 , V_3 , V_31 , 0 , V_6 , V_7 ) ;
F_15 ( V_3 , V_6 & V_32 , 0 ) ;
return 0 ;
}
static long F_16 ( struct V_22 * V_23 , T_1 V_7 ,
void * * V_33 , unsigned long * V_34 , long V_35 )
{
struct V_1 * V_2 = V_23 -> V_25 -> V_26 ;
T_2 V_36 = V_7 << 9 ;
if ( ! V_2 )
return - V_37 ;
* V_33 = ( void V_38 * ) V_2 -> V_11 + V_36 ;
* V_34 = ( V_2 -> V_39 + V_36 ) >> V_40 ;
return V_2 -> V_35 - V_36 ;
}
static struct V_1 * F_17 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return F_19 ( - V_47 ) ;
V_2 -> V_39 = V_44 -> V_17 ;
V_2 -> V_35 = F_20 ( V_44 ) ;
if ( ! F_21 () )
F_22 ( V_42 , L_1 ) ;
if ( ! F_23 ( V_2 -> V_39 , V_2 -> V_35 , F_24 ( V_42 ) ) ) {
F_22 ( V_42 , L_2 ,
& V_2 -> V_39 , V_2 -> V_35 ) ;
F_25 ( V_2 ) ;
return F_19 ( - V_48 ) ;
}
V_2 -> V_11 = F_26 ( V_2 -> V_39 , V_2 -> V_35 ) ;
if ( ! V_2 -> V_11 ) {
F_27 ( V_2 -> V_39 , V_2 -> V_35 ) ;
F_25 ( V_2 ) ;
return F_19 ( - V_49 ) ;
}
return V_2 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_50 ) ;
F_30 ( V_2 -> V_50 ) ;
F_31 ( V_2 -> V_51 ) ;
}
static int F_32 ( struct V_52 * V_53 ,
struct V_1 * V_2 )
{
struct V_54 * V_55 ;
V_2 -> V_51 = F_33 ( V_46 ) ;
if ( ! V_2 -> V_51 )
return - V_47 ;
F_34 ( V_2 -> V_51 , F_7 ) ;
F_35 ( V_2 -> V_51 , V_56 ) ;
F_36 ( V_2 -> V_51 , V_57 ) ;
F_37 ( V_58 , V_2 -> V_51 ) ;
V_55 = F_38 ( 0 ) ;
if ( ! V_55 ) {
F_31 ( V_2 -> V_51 ) ;
return - V_47 ;
}
V_55 -> V_59 = V_60 ;
V_55 -> V_61 = 0 ;
V_55 -> V_62 = & V_63 ;
V_55 -> V_26 = V_2 ;
V_55 -> V_64 = V_2 -> V_51 ;
V_55 -> V_65 = V_66 ;
F_39 ( V_53 , V_55 -> V_67 ) ;
V_55 -> V_68 = & V_53 -> V_42 ;
F_40 ( V_55 , V_2 -> V_35 >> 9 ) ;
V_2 -> V_50 = V_55 ;
F_41 ( V_55 ) ;
F_42 ( V_55 ) ;
return 0 ;
}
static int F_43 ( struct V_52 * V_53 ,
T_4 V_36 , void * V_69 , T_2 V_35 , int V_6 )
{
struct V_1 * V_2 = F_44 ( V_53 -> V_70 ) ;
if ( F_45 ( V_36 + V_35 > V_2 -> V_35 ) ) {
F_46 ( & V_53 -> V_42 , 1 , L_3 ) ;
return - V_71 ;
}
if ( V_6 == V_12 )
F_3 ( V_69 , V_2 -> V_11 + V_36 , V_35 ) ;
else {
F_5 ( V_2 -> V_11 + V_36 , V_69 , V_35 ) ;
F_12 () ;
}
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_11 ) ;
F_27 ( V_2 -> V_39 , V_2 -> V_35 ) ;
F_25 ( V_2 ) ;
}
static int F_49 ( struct V_41 * V_42 )
{
struct V_72 * V_72 = F_50 ( V_42 -> V_73 ) ;
struct V_52 * V_53 ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
int V_76 ;
V_53 = F_51 ( V_42 ) ;
if ( F_52 ( V_53 ) )
return F_53 ( V_53 ) ;
V_75 = F_54 ( & V_53 -> V_42 ) ;
V_2 = F_17 ( V_42 , & V_75 -> V_44 , V_72 -> V_45 ) ;
if ( F_52 ( V_2 ) )
return F_53 ( V_2 ) ;
F_55 ( V_42 , V_2 ) ;
V_53 -> V_77 = F_43 ;
if ( F_56 ( V_42 ) )
V_76 = F_57 ( V_53 ) ;
else if ( F_58 ( V_53 , V_2 ) == 0 ) {
V_76 = - V_49 ;
} else
V_76 = F_32 ( V_53 , V_2 ) ;
if ( V_76 )
F_47 ( V_2 ) ;
return V_76 ;
}
static int F_59 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_44 ( V_42 ) ;
if ( F_56 ( V_42 ) )
F_60 ( F_61 ( V_42 ) -> V_53 ) ;
else
F_28 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int T_5 F_62 ( void )
{
int error ;
V_60 = F_63 ( 0 , L_4 ) ;
if ( V_60 < 0 )
return V_60 ;
error = F_64 ( & V_78 ) ;
if ( error ) {
F_65 ( V_60 , L_4 ) ;
return error ;
}
return 0 ;
}
static void F_66 ( void )
{
F_67 ( & V_78 . V_79 ) ;
F_65 ( V_60 , L_4 ) ;
}
