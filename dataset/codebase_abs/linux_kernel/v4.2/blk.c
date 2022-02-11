static T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 - V_2 -> V_5 ;
}
static T_2 F_2 ( struct V_6 * V_3 ,
T_2 V_7 , unsigned int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_10 ; V_9 ++ ) {
if ( V_7 < F_3 ( V_3 -> V_11 [ V_9 ] ) ) {
if ( V_7 + V_8 > F_3 ( V_3 -> V_11 [ V_9 ] ) ) {
F_4 ( & V_3 -> V_12 . V_13 , 1 ,
L_1 ) ;
return V_14 ;
}
return V_3 -> V_11 [ V_9 ] -> V_15 + V_7 ;
}
V_7 -= F_3 ( V_3 -> V_11 [ V_9 ] ) ;
}
F_4 ( & V_3 -> V_12 . V_13 , 1 , L_2 ) ;
return V_14 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_3 V_18 ,
int V_19 )
{
unsigned int V_8 = F_1 ( V_2 ) ;
T_2 V_20 , V_7 ;
struct V_6 * V_3 ;
struct V_21 * V_22 ;
int V_23 = 0 ;
V_3 = V_2 -> V_3 ;
V_22 = V_2 -> V_22 ;
V_7 = V_18 * V_2 -> V_24 + V_2 -> V_5 ;
V_20 = F_2 ( V_3 , V_7 , V_8 ) ;
if ( V_20 == V_14 )
return - V_25 ;
while ( V_8 ) {
unsigned int V_26 ;
struct V_27 V_28 ;
void * V_29 ;
V_28 = F_6 ( V_17 -> V_30 , V_17 -> V_31 ) ;
V_26 = F_7 ( V_8 , V_28 . V_32 ) ;
V_29 = F_8 ( V_28 . V_33 ) ;
V_23 = V_22 -> V_34 ( V_22 , V_20 , V_29 + V_28 . V_35 ,
V_26 , V_19 ) ;
F_9 ( V_29 ) ;
if ( V_23 )
return V_23 ;
V_8 -= V_26 ;
V_20 += V_26 ;
F_10 ( V_17 -> V_30 , & V_17 -> V_31 , V_26 ) ;
}
return V_23 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_3 V_18 ,
int V_19 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_16 * V_17 , struct V_36 * V_36 ,
unsigned int V_8 , unsigned int V_37 , int V_19 ,
T_4 V_38 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_20 , V_7 ;
int V_23 = 0 ;
void * V_29 ;
T_3 V_18 ;
while ( V_8 ) {
unsigned int V_26 ;
V_26 = V_17 ? F_7 ( V_8 , V_2 -> V_5 ) : V_8 ;
V_18 = F_12 ( V_38 << V_39 , V_2 -> V_5 ) ;
V_7 = V_18 * V_2 -> V_24 ;
V_20 = F_2 ( V_2 -> V_3 , V_7 , V_26 ) ;
if ( V_20 == V_14 )
return - V_25 ;
V_29 = F_8 ( V_36 ) ;
V_23 = V_22 -> V_34 ( V_22 , V_20 , V_29 + V_37 , V_26 , V_19 ) ;
F_9 ( V_29 ) ;
if ( V_23 )
return V_23 ;
if ( V_17 ) {
V_23 = F_5 ( V_2 , V_17 , V_18 , V_19 ) ;
if ( V_23 )
return V_23 ;
}
V_8 -= V_26 ;
V_37 += V_26 ;
V_38 += V_2 -> V_5 >> V_39 ;
}
return V_23 ;
}
static void F_13 ( struct V_40 * V_41 , struct V_42 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_46 * V_47 = V_44 -> V_48 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_49 V_50 ;
unsigned long V_15 ;
struct V_27 V_51 ;
int V_23 = 0 , V_19 ;
bool V_52 ;
if ( F_14 ( V_42 ) && F_15 ( V_42 ) ) {
V_23 = - V_25 ;
goto V_53;
}
V_17 = F_16 ( V_42 ) ;
V_2 = V_47 -> V_54 ;
V_19 = F_17 ( V_42 ) ;
V_52 = F_18 ( V_42 , & V_15 ) ;
F_19 (bvec, bio, iter) {
unsigned int V_8 = V_51 . V_32 ;
F_20 ( V_8 > V_55 ) ;
V_23 = F_11 ( V_2 , V_17 , V_51 . V_33 , V_8 ,
V_51 . V_35 , V_19 , V_50 . V_56 ) ;
if ( V_23 ) {
F_21 ( & V_2 -> V_3 -> V_12 . V_13 ,
L_3 ,
( V_19 == V_57 ) ? L_4 : L_5 ,
( unsigned long long ) V_50 . V_56 , V_8 ) ;
break;
}
}
if ( V_52 )
F_22 ( V_42 , V_15 ) ;
V_53:
F_23 ( V_42 , V_23 ) ;
}
static int F_24 ( struct V_58 * V_59 ,
T_2 V_60 , void * V_29 , T_5 V_61 , int V_19 )
{
struct V_1 * V_2 = F_25 ( V_59 -> V_62 ) ;
struct V_6 * V_3 = V_2 -> V_3 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_20 ;
V_20 = F_2 ( V_3 , V_60 , V_61 ) ;
if ( F_26 ( V_60 + V_61 > V_2 -> V_63 ) ) {
F_4 ( & V_59 -> V_13 , 1 , L_2 ) ;
return - V_64 ;
}
if ( V_20 == V_14 )
return - V_25 ;
return V_22 -> V_34 ( V_22 , V_20 , V_29 , V_61 , V_19 ) ;
}
static int F_27 ( struct V_58 * V_59 ,
struct V_1 * V_2 )
{
T_2 V_65 ;
struct V_46 * V_47 ;
T_3 V_66 ;
V_66 = F_12 ( V_2 -> V_63 , V_2 -> V_24 ) ;
V_65 = V_66 * V_2 -> V_5 ;
V_2 -> V_67 = F_28 ( V_68 ) ;
if ( ! V_2 -> V_67 )
return - V_69 ;
F_29 ( V_2 -> V_67 , F_13 ) ;
F_30 ( V_2 -> V_67 , V_70 ) ;
F_31 ( V_2 -> V_67 , V_71 ) ;
F_32 ( V_2 -> V_67 , V_2 -> V_5 ) ;
F_33 ( V_72 , V_2 -> V_67 ) ;
V_47 = V_2 -> V_47 = F_34 ( 0 ) ;
if ( ! V_47 ) {
F_35 ( V_2 -> V_67 ) ;
return - V_69 ;
}
V_47 -> V_73 = & V_59 -> V_13 ;
V_47 -> V_74 = V_75 ;
V_47 -> V_76 = 0 ;
V_47 -> V_77 = & V_78 ;
V_47 -> V_54 = V_2 ;
V_47 -> V_67 = V_2 -> V_67 ;
V_47 -> V_79 = V_80 ;
F_36 ( V_59 , V_47 -> V_81 ) ;
F_37 ( V_47 , 0 ) ;
F_38 ( V_47 ) ;
if ( F_1 ( V_2 ) ) {
int V_82 = F_39 ( V_47 , F_1 ( V_2 ) ) ;
if ( V_82 ) {
F_40 ( V_47 ) ;
F_41 ( V_47 ) ;
F_35 ( V_2 -> V_67 ) ;
return V_82 ;
}
}
F_37 ( V_47 , V_65 >> V_39 ) ;
F_42 ( V_47 ) ;
return 0 ;
}
static int F_43 ( struct V_83 * V_13 )
{
struct V_58 * V_59 ;
struct V_6 * V_3 ;
struct V_1 * V_2 ;
int V_82 ;
V_59 = F_44 ( V_13 ) ;
if ( F_45 ( V_59 ) )
return F_46 ( V_59 ) ;
V_2 = F_47 ( sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_3 = F_48 ( & V_59 -> V_13 ) ;
V_2 -> V_63 = F_49 ( V_59 ) ;
V_2 -> V_22 = F_50 ( V_13 -> V_84 ) ;
V_2 -> V_3 = F_48 ( & V_59 -> V_13 ) ;
V_2 -> V_24 = F_51 ( V_3 -> V_4 ,
V_85 ) ;
V_2 -> V_5 = ( ( V_3 -> V_4 >= 4096 ) ? 4096 : 512 ) ;
F_52 ( V_13 , V_2 ) ;
V_59 -> V_86 = F_24 ;
if ( F_53 ( V_13 ) )
V_82 = F_54 ( V_59 ) ;
else if ( F_55 ( V_59 , V_2 ) == 0 ) {
V_82 = - V_87 ;
} else
V_82 = F_27 ( V_59 , V_2 ) ;
if ( V_82 )
F_56 ( V_2 ) ;
return V_82 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_40 ( V_2 -> V_47 ) ;
F_41 ( V_2 -> V_47 ) ;
F_35 ( V_2 -> V_67 ) ;
}
static int F_58 ( struct V_83 * V_13 )
{
struct V_1 * V_2 = F_25 ( V_13 ) ;
if ( F_53 ( V_13 ) )
F_59 ( F_60 ( V_13 ) -> V_59 ) ;
else
F_57 ( V_2 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int T_6 F_61 ( void )
{
int V_82 ;
V_82 = F_62 ( 0 , L_6 ) ;
if ( V_82 < 0 )
return V_82 ;
V_75 = V_82 ;
V_82 = F_63 ( & V_88 ) ;
if ( V_82 < 0 )
F_64 ( V_75 , L_6 ) ;
return V_82 ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_88 . V_89 ) ;
F_64 ( V_75 , L_6 ) ;
}
