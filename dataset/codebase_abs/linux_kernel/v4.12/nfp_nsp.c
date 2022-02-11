struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
bool F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_5 ;
}
void F_3 ( struct V_2 * V_3 , bool V_5 )
{
V_3 -> V_5 = V_5 ;
}
void * F_4 ( struct V_2 * V_3 )
{
return V_3 -> V_6 ;
}
unsigned int F_5 ( struct V_2 * V_3 )
{
return V_3 -> V_7 ;
}
void
F_6 ( struct V_2 * V_3 , void * V_6 , unsigned int V_7 )
{
V_3 -> V_6 = V_6 ;
V_3 -> V_7 = V_7 ;
}
void F_7 ( struct V_2 * V_3 )
{
V_3 -> V_6 = NULL ;
V_3 -> V_7 = 0 ;
}
static void F_8 ( struct V_2 * V_3 , T_1 V_8 )
{
int V_9 ;
if ( ! V_8 )
return;
for ( V_9 = 0 ; V_9 < F_9 ( V_10 ) ; V_9 ++ )
if ( V_8 == V_10 [ V_9 ] . V_11 )
F_10 ( V_3 -> V_4 , L_1 , V_10 [ V_9 ] . V_12 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_2 V_13 , V_14 ;
T_1 V_15 ;
int V_16 ;
V_15 = F_12 ( V_3 -> V_17 ) ;
V_13 = F_13 ( V_3 -> V_17 ) + V_18 ;
V_16 = F_14 ( V_4 , V_15 , V_13 , & V_14 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_15 ( V_19 , V_14 ) != V_20 ) {
F_10 ( V_4 , L_2 ) ;
return - V_21 ;
}
V_3 -> V_22 . V_23 = F_15 ( V_24 , V_14 ) ;
V_3 -> V_22 . V_25 = F_15 ( V_26 , V_14 ) ;
if ( V_3 -> V_22 . V_23 != V_27 || V_3 -> V_22 . V_25 < V_28 ) {
F_10 ( V_4 , L_3 ,
V_3 -> V_22 . V_23 , V_3 -> V_22 . V_25 ) ;
return - V_29 ;
}
if ( V_14 & V_30 ) {
F_10 ( V_4 , L_4 ) ;
return - V_31 ;
}
return 0 ;
}
struct V_2 * F_16 ( struct V_1 * V_4 )
{
struct V_32 * V_17 ;
struct V_2 * V_3 ;
int V_16 ;
V_17 = F_17 ( V_4 , V_33 ) ;
if ( F_18 ( V_17 ) )
return ( void * ) V_17 ;
V_3 = F_19 ( sizeof( * V_3 ) , V_34 ) ;
if ( ! V_3 ) {
F_20 ( V_17 ) ;
return F_21 ( - V_35 ) ;
}
V_3 -> V_4 = V_4 ;
V_3 -> V_17 = V_17 ;
V_16 = F_11 ( V_3 ) ;
if ( V_16 ) {
F_22 ( V_3 ) ;
return F_21 ( V_16 ) ;
}
return V_3 ;
}
void F_22 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_17 ) ;
F_23 ( V_3 ) ;
}
T_3 F_24 ( struct V_2 * V_3 )
{
return V_3 -> V_22 . V_23 ;
}
T_3 F_25 ( struct V_2 * V_3 )
{
return V_3 -> V_22 . V_25 ;
}
static int
F_26 ( struct V_1 * V_4 , T_2 * V_14 ,
T_1 V_15 , T_2 V_36 , T_2 V_37 , T_2 V_38 )
{
const unsigned long V_39 = V_40 + 30 * V_41 ;
int V_16 ;
for (; ; ) {
const unsigned long V_42 = V_40 ;
V_16 = F_14 ( V_4 , V_15 , V_36 , V_14 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ( * V_14 & V_37 ) == V_38 )
return 0 ;
if ( F_27 ( 25 ) )
return - V_43 ;
if ( F_28 ( V_42 , V_39 ) )
return - V_44 ;
}
}
static int F_29 ( struct V_2 * V_3 , T_3 V_11 , T_1 V_45 ,
T_1 V_46 , T_2 V_47 )
{
T_2 V_14 , V_8 , V_48 , V_49 , V_13 , V_50 ;
struct V_1 * V_4 = V_3 -> V_4 ;
T_1 V_15 ;
int V_16 ;
V_15 = F_12 ( V_3 -> V_17 ) ;
V_48 = F_13 ( V_3 -> V_17 ) ;
V_13 = V_48 + V_18 ;
V_50 = V_48 + V_51 ;
V_49 = V_48 + V_52 ;
V_16 = F_11 ( V_3 ) ;
if ( V_16 )
return V_16 ;
if ( ! F_30 ( V_53 , V_46 >> 8 ) ||
! F_30 ( V_54 , V_47 ) ) {
F_10 ( V_4 , L_5 ,
V_46 , V_47 ) ;
return - V_29 ;
}
V_16 = F_31 ( V_4 , V_15 , V_49 ,
F_32 ( V_53 , V_46 >> 8 ) |
F_32 ( V_54 , V_47 ) ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_31 ( V_4 , V_15 , V_50 ,
F_32 ( V_55 , V_45 ) |
F_32 ( V_56 , V_11 ) |
F_32 ( V_57 , 1 ) ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_26 ( V_4 , & V_14 ,
V_15 , V_50 , V_57 , 0 ) ;
if ( V_16 ) {
F_10 ( V_4 , L_6 ,
V_16 , V_11 ) ;
return V_16 ;
}
V_16 = F_26 ( V_4 , & V_14 ,
V_15 , V_13 , V_30 , 0 ) ;
if ( V_16 ) {
F_10 ( V_4 , L_7 ,
V_16 , V_11 ) ;
return V_16 ;
}
V_16 = F_14 ( V_4 , V_15 , V_50 , & V_8 ) ;
if ( V_16 < 0 )
return V_16 ;
V_8 = F_15 ( V_55 , V_8 ) ;
V_16 = F_15 ( V_58 , V_14 ) ;
if ( V_16 ) {
F_33 ( V_4 , L_8 ,
- V_16 , ( int ) V_8 , V_11 ) ;
F_8 ( V_3 , V_8 ) ;
return - V_16 ;
}
return V_8 ;
}
static int F_34 ( struct V_2 * V_59 , T_3 V_11 , T_1 V_45 ,
const void * V_60 , unsigned int V_61 ,
void * V_62 , unsigned int V_63 )
{
struct V_1 * V_4 = V_59 -> V_4 ;
unsigned int V_64 ;
T_2 V_14 , V_65 ;
int V_66 , V_16 ;
T_1 V_67 ;
if ( V_59 -> V_22 . V_25 < 13 ) {
F_10 ( V_4 , L_9 ,
V_11 , V_59 -> V_22 . V_23 , V_59 -> V_22 . V_25 ) ;
return - V_68 ;
}
V_16 = F_14 ( V_4 , F_12 ( V_59 -> V_17 ) ,
F_13 ( V_59 -> V_17 ) +
V_69 ,
& V_14 ) ;
if ( V_16 < 0 )
return V_16 ;
V_64 = F_35 ( V_61 , V_63 ) ;
if ( F_15 ( V_70 , V_14 ) * V_71 < V_64 ) {
F_10 ( V_4 , L_10 ,
V_11 , F_15 ( V_70 , V_14 ) * V_71 ,
V_64 ) ;
return - V_29 ;
}
V_16 = F_14 ( V_4 , F_12 ( V_59 -> V_17 ) ,
F_13 ( V_59 -> V_17 ) +
V_72 ,
& V_14 ) ;
if ( V_16 < 0 )
return V_16 ;
V_67 = F_15 ( V_53 , V_14 ) << 8 ;
V_65 = F_15 ( V_54 , V_14 ) ;
if ( V_60 && V_61 ) {
V_16 = F_36 ( V_4 , V_67 , V_65 , V_60 , V_61 ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_66 = F_29 ( V_59 , V_11 , V_45 , V_67 , V_65 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( V_62 && V_63 ) {
V_16 = F_37 ( V_4 , V_67 , V_65 , V_62 , V_63 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return V_66 ;
}
int F_38 ( struct V_2 * V_3 )
{
const unsigned long V_39 = V_40 + 30 * V_41 ;
int V_16 ;
F_39 ( V_3 -> V_4 , L_11 ) ;
for (; ; ) {
const unsigned long V_42 = V_40 ;
V_16 = F_29 ( V_3 , V_73 , 0 , 0 , 0 ) ;
if ( V_16 != - V_74 )
break;
if ( F_27 ( 25 ) ) {
V_16 = - V_43 ;
break;
}
if ( F_28 ( V_42 , V_39 ) ) {
V_16 = - V_44 ;
break;
}
}
if ( V_16 )
F_10 ( V_3 -> V_4 , L_12 , V_16 ) ;
return V_16 ;
}
int F_40 ( struct V_2 * V_3 )
{
int V_16 ;
V_16 = F_29 ( V_3 , V_75 , 0 , 0 , 0 ) ;
F_41 ( V_3 -> V_4 ) ;
return V_16 ;
}
int F_42 ( struct V_2 * V_3 , const struct V_76 * V_77 )
{
return F_34 ( V_3 , V_78 , V_77 -> V_79 , V_77 -> V_80 ,
V_77 -> V_79 , NULL , 0 ) ;
}
int F_43 ( struct V_2 * V_3 , void * V_81 , unsigned int V_79 )
{
return F_34 ( V_3 , V_82 , V_79 , NULL , 0 ,
V_81 , V_79 ) ;
}
int F_44 ( struct V_2 * V_3 ,
const void * V_81 , unsigned int V_79 )
{
return F_34 ( V_3 , V_83 , V_79 , V_81 , V_79 ,
NULL , 0 ) ;
}
int F_45 ( struct V_2 * V_3 , void * V_81 , unsigned int V_79 )
{
return F_34 ( V_3 , V_84 , V_79 , NULL , 0 ,
V_81 , V_79 ) ;
}
