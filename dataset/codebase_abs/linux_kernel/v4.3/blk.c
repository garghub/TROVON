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
V_42 -> V_53 = - V_25 ;
goto V_54;
}
V_17 = F_16 ( V_42 ) ;
V_2 = V_47 -> V_55 ;
V_19 = F_17 ( V_42 ) ;
V_52 = F_18 ( V_42 , & V_15 ) ;
F_19 (bvec, bio, iter) {
unsigned int V_8 = V_51 . V_32 ;
F_20 ( V_8 > V_56 ) ;
V_23 = F_11 ( V_2 , V_17 , V_51 . V_33 , V_8 ,
V_51 . V_35 , V_19 , V_50 . V_57 ) ;
if ( V_23 ) {
F_21 ( & V_2 -> V_3 -> V_12 . V_13 ,
L_3 ,
( V_19 == V_58 ) ? L_4 : L_5 ,
( unsigned long long ) V_50 . V_57 , V_8 ) ;
V_42 -> V_53 = V_23 ;
break;
}
}
if ( V_52 )
F_22 ( V_42 , V_15 ) ;
V_54:
F_23 ( V_42 ) ;
}
static int F_24 ( struct V_59 * V_60 ,
T_2 V_61 , void * V_29 , T_5 V_62 , int V_19 )
{
struct V_1 * V_2 = F_25 ( V_60 -> V_63 ) ;
struct V_6 * V_3 = V_2 -> V_3 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_20 ;
V_20 = F_2 ( V_3 , V_61 , V_62 ) ;
if ( F_26 ( V_61 + V_62 > V_2 -> V_64 ) ) {
F_4 ( & V_60 -> V_13 , 1 , L_2 ) ;
return - V_65 ;
}
if ( V_20 == V_14 )
return - V_25 ;
return V_22 -> V_34 ( V_22 , V_20 , V_29 , V_62 , V_19 ) ;
}
static int F_27 ( struct V_59 * V_60 ,
struct V_1 * V_2 )
{
T_2 V_66 ;
struct V_46 * V_47 ;
T_3 V_67 ;
V_67 = F_12 ( V_2 -> V_64 , V_2 -> V_24 ) ;
V_66 = V_67 * V_2 -> V_5 ;
V_2 -> V_68 = F_28 ( V_69 ) ;
if ( ! V_2 -> V_68 )
return - V_70 ;
F_29 ( V_2 -> V_68 , F_13 ) ;
F_30 ( V_2 -> V_68 , V_71 ) ;
F_31 ( V_2 -> V_68 , V_72 ) ;
F_32 ( V_2 -> V_68 , V_2 -> V_5 ) ;
F_33 ( V_73 , V_2 -> V_68 ) ;
V_47 = V_2 -> V_47 = F_34 ( 0 ) ;
if ( ! V_47 ) {
F_35 ( V_2 -> V_68 ) ;
return - V_70 ;
}
V_47 -> V_74 = & V_60 -> V_13 ;
V_47 -> V_75 = V_76 ;
V_47 -> V_77 = 0 ;
V_47 -> V_78 = & V_79 ;
V_47 -> V_55 = V_2 ;
V_47 -> V_68 = V_2 -> V_68 ;
V_47 -> V_80 = V_81 ;
F_36 ( V_60 , V_47 -> V_82 ) ;
F_37 ( V_47 , 0 ) ;
F_38 ( V_47 ) ;
if ( F_1 ( V_2 ) ) {
int V_83 = F_39 ( V_47 , F_1 ( V_2 ) ) ;
if ( V_83 ) {
F_40 ( V_47 ) ;
F_41 ( V_47 ) ;
F_35 ( V_2 -> V_68 ) ;
return V_83 ;
}
}
F_37 ( V_47 , V_66 >> V_39 ) ;
F_42 ( V_47 ) ;
return 0 ;
}
static int F_43 ( struct V_84 * V_13 )
{
struct V_59 * V_60 ;
struct V_6 * V_3 ;
struct V_1 * V_2 ;
int V_83 ;
V_60 = F_44 ( V_13 ) ;
if ( F_45 ( V_60 ) )
return F_46 ( V_60 ) ;
V_2 = F_47 ( sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
V_3 = F_48 ( & V_60 -> V_13 ) ;
V_2 -> V_64 = F_49 ( V_60 ) ;
V_2 -> V_22 = F_50 ( V_13 -> V_85 ) ;
V_2 -> V_3 = F_48 ( & V_60 -> V_13 ) ;
V_2 -> V_24 = F_51 ( V_3 -> V_4 ,
V_86 ) ;
V_2 -> V_5 = ( ( V_3 -> V_4 >= 4096 ) ? 4096 : 512 ) ;
F_52 ( V_13 , V_2 ) ;
V_60 -> V_87 = F_24 ;
if ( F_53 ( V_13 ) )
V_83 = F_54 ( V_60 ) ;
else if ( F_55 ( V_60 , V_2 ) == 0 ) {
V_83 = - V_88 ;
} else
V_83 = F_27 ( V_60 , V_2 ) ;
if ( V_83 )
F_56 ( V_2 ) ;
return V_83 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_40 ( V_2 -> V_47 ) ;
F_41 ( V_2 -> V_47 ) ;
F_35 ( V_2 -> V_68 ) ;
}
static int F_58 ( struct V_84 * V_13 )
{
struct V_1 * V_2 = F_25 ( V_13 ) ;
if ( F_53 ( V_13 ) )
F_59 ( F_60 ( V_13 ) -> V_60 ) ;
else
F_57 ( V_2 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int T_6 F_61 ( void )
{
int V_83 ;
V_83 = F_62 ( 0 , L_6 ) ;
if ( V_83 < 0 )
return V_83 ;
V_76 = V_83 ;
V_83 = F_63 ( & V_89 ) ;
if ( V_83 < 0 )
F_64 ( V_76 , L_6 ) ;
return V_83 ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_89 . V_90 ) ;
F_64 ( V_76 , L_6 ) ;
}
