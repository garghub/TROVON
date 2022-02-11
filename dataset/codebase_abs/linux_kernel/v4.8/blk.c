static T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - ( ( V_2 -> V_3 >= 4096 ) ? 4096 : 512 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 -> V_3 , V_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - F_1 ( V_2 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 ,
T_2 V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; V_7 ++ ) {
if ( V_5 < F_6 ( V_2 -> V_9 [ V_7 ] ) ) {
if ( V_5 + V_6 > F_6 ( V_2 -> V_9 [ V_7 ] ) ) {
F_7 ( & V_2 -> V_10 . V_11 , 1 ,
L_1 ) ;
return V_12 ;
}
return V_2 -> V_9 [ V_7 ] -> V_13 + V_5 ;
}
V_5 -= F_6 ( V_2 -> V_9 [ V_7 ] ) ;
}
F_7 ( & V_2 -> V_10 . V_11 , 1 , L_2 ) ;
return V_12 ;
}
static struct V_14 * F_8 ( struct V_1 * V_2 )
{
struct V_15 * V_15 ;
struct V_16 * V_17 ;
V_17 = V_2 -> V_10 . V_11 . V_17 ;
V_15 = F_9 ( V_17 , struct V_15 , V_11 ) ;
return F_9 ( V_15 , struct V_14 , V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_18 * V_19 , T_3 V_20 , int V_21 )
{
struct V_14 * V_22 = F_8 ( V_2 ) ;
unsigned int V_6 = F_1 ( V_2 ) ;
T_2 V_23 , V_5 ;
T_1 V_24 , V_25 ;
int V_26 = 0 ;
V_24 = F_2 ( V_2 ) ;
V_25 = F_4 ( V_2 ) ;
V_5 = V_20 * V_24 + V_25 ;
V_23 = F_5 ( V_2 , V_5 , V_6 ) ;
if ( V_23 == V_12 )
return - V_27 ;
while ( V_6 ) {
unsigned int V_28 ;
struct V_29 V_30 ;
void * V_31 ;
V_30 = F_11 ( V_19 -> V_32 , V_19 -> V_33 ) ;
V_28 = F_12 ( V_6 , V_30 . V_34 ) ;
V_31 = F_13 ( V_30 . V_35 ) ;
V_26 = V_22 -> V_36 ( V_22 , V_23 , V_31 + V_30 . V_37 ,
V_28 , V_21 ) ;
F_14 ( V_31 ) ;
if ( V_26 )
return V_26 ;
V_6 -= V_28 ;
V_23 += V_28 ;
F_15 ( V_19 -> V_32 , & V_19 -> V_33 , V_28 ) ;
}
return V_26 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_18 * V_19 , T_3 V_20 , int V_21 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_18 * V_19 , struct V_38 * V_38 ,
unsigned int V_6 , unsigned int V_39 , int V_21 , T_4 V_40 )
{
struct V_14 * V_22 = F_8 ( V_2 ) ;
T_2 V_23 , V_5 ;
T_1 V_24 , V_25 ;
int V_26 = 0 ;
void * V_31 ;
T_3 V_20 ;
V_24 = F_2 ( V_2 ) ;
V_25 = F_4 ( V_2 ) ;
while ( V_6 ) {
unsigned int V_28 ;
V_28 = V_19 ? F_12 ( V_6 , V_25 ) : V_6 ;
V_20 = F_17 ( V_40 << V_41 , V_25 ) ;
V_5 = V_20 * V_24 ;
V_23 = F_5 ( V_2 , V_5 , V_28 ) ;
if ( V_23 == V_12 )
return - V_27 ;
V_31 = F_13 ( V_38 ) ;
V_26 = V_22 -> V_36 ( V_22 , V_23 , V_31 + V_39 , V_28 , V_21 ) ;
F_14 ( V_31 ) ;
if ( V_26 )
return V_26 ;
if ( V_19 ) {
V_26 = F_10 ( V_2 , V_19 , V_20 , V_21 ) ;
if ( V_26 )
return V_26 ;
}
V_6 -= V_28 ;
V_39 += V_28 ;
V_40 += V_25 >> V_41 ;
}
return V_26 ;
}
static T_5 F_18 ( struct V_42 * V_43 , struct V_44 * V_44 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_45 V_46 ;
unsigned long V_13 ;
struct V_29 V_47 ;
int V_26 = 0 , V_21 ;
bool V_48 ;
if ( F_19 ( V_44 ) && F_20 ( V_44 ) ) {
V_44 -> V_49 = - V_27 ;
goto V_50;
}
V_19 = F_21 ( V_44 ) ;
V_2 = V_43 -> V_51 ;
V_21 = F_22 ( V_44 ) ;
V_48 = F_23 ( V_44 , & V_13 ) ;
F_24 (bvec, bio, iter) {
unsigned int V_6 = V_47 . V_34 ;
F_25 ( V_6 > V_52 ) ;
V_26 = F_16 ( V_2 , V_19 , V_47 . V_35 , V_6 ,
V_47 . V_37 , V_21 , V_46 . V_53 ) ;
if ( V_26 ) {
F_26 ( & V_2 -> V_10 . V_11 ,
L_3 ,
( V_21 == V_54 ) ? L_4 : L_5 ,
( unsigned long long ) V_46 . V_53 , V_6 ) ;
V_44 -> V_49 = V_26 ;
break;
}
}
if ( V_48 )
F_27 ( V_44 , V_13 ) ;
V_50:
F_28 ( V_44 ) ;
return V_55 ;
}
static int F_29 ( struct V_56 * V_57 ,
T_2 V_58 , void * V_31 , T_6 V_59 , int V_21 )
{
struct V_1 * V_2 = F_30 ( & V_57 -> V_11 ) ;
struct V_14 * V_22 = F_8 ( V_2 ) ;
T_2 V_23 ;
V_23 = F_5 ( V_2 , V_58 , V_59 ) ;
if ( F_31 ( V_58 + V_59 > V_2 -> V_60 ) ) {
F_7 ( & V_57 -> V_11 , 1 , L_2 ) ;
return - V_61 ;
}
if ( V_23 == V_12 )
return - V_27 ;
return V_22 -> V_36 ( V_22 , V_23 , V_31 , V_59 , V_21 ) ;
}
static void F_32 ( void * V_43 )
{
F_33 ( V_43 ) ;
}
static void F_34 ( void * V_62 )
{
F_35 ( V_62 ) ;
F_36 ( V_62 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_16 * V_11 = & V_2 -> V_10 . V_11 ;
T_2 V_63 ;
struct V_42 * V_43 ;
struct V_64 * V_62 ;
T_3 V_65 ;
V_65 = F_17 ( V_2 -> V_60 , F_2 ( V_2 ) ) ;
V_63 = V_65 * F_4 ( V_2 ) ;
V_43 = F_38 ( V_66 ) ;
if ( ! V_43 )
return - V_67 ;
if ( F_39 ( V_11 , F_32 , V_43 ) )
return - V_67 ;
F_40 ( V_43 , F_18 ) ;
F_41 ( V_43 , V_68 ) ;
F_42 ( V_43 , V_69 ) ;
F_43 ( V_43 , F_4 ( V_2 ) ) ;
F_44 ( V_70 , V_43 ) ;
V_43 -> V_51 = V_2 ;
V_62 = F_45 ( 0 ) ;
if ( ! V_62 )
return - V_67 ;
V_62 -> V_71 = 0 ;
V_62 -> V_72 = & V_73 ;
V_62 -> V_74 = V_43 ;
V_62 -> V_75 = V_76 ;
F_46 ( & V_2 -> V_10 , V_62 -> V_77 ) ;
F_47 ( V_62 , 0 ) ;
F_48 ( V_11 , V_62 ) ;
if ( F_39 ( V_11 , F_34 , V_62 ) )
return - V_67 ;
if ( F_1 ( V_2 ) ) {
int V_78 = F_49 ( V_62 , F_1 ( V_2 ) ) ;
if ( V_78 )
return V_78 ;
}
F_47 ( V_62 , V_63 >> V_41 ) ;
F_50 ( V_62 ) ;
return 0 ;
}
static int F_51 ( struct V_16 * V_11 )
{
struct V_56 * V_57 ;
struct V_1 * V_2 ;
V_57 = F_52 ( V_11 ) ;
if ( F_53 ( V_57 ) )
return F_54 ( V_57 ) ;
V_2 = F_30 ( & V_57 -> V_11 ) ;
V_2 -> V_60 = F_55 ( V_57 ) ;
F_56 ( V_11 , V_2 ) ;
V_57 -> V_79 = F_29 ;
if ( F_57 ( V_11 ) )
return F_58 ( V_57 ) ;
else if ( F_59 ( V_11 , V_57 ) == 0 ) {
return - V_80 ;
} else
return F_37 ( V_2 ) ;
}
static int F_60 ( struct V_16 * V_11 )
{
if ( F_57 ( V_11 ) )
F_61 ( F_62 ( V_11 ) ) ;
return 0 ;
}
static int T_7 F_63 ( void )
{
return F_64 ( & V_81 ) ;
}
static void T_8 F_65 ( void )
{
F_66 ( & V_81 . V_82 ) ;
}
