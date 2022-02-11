int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
V_4 = F_4 ( sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 ) {
F_5 ( L_1 ) ;
return - V_8 ;
}
V_2 -> V_4 = V_4 ;
F_6 ( V_4 ,
V_9 ,
V_10 ) ;
return 0 ;
}
void
F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_4 ) ;
F_9 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_1 V_13 )
{
struct V_14 * V_15 ;
F_11 ( V_2 , V_12 , V_13 ) ;
V_15 = F_12 ( L_2 , V_13 , V_16 ) ;
if ( F_13 ( V_15 ) )
return F_14 ( V_15 ) ;
V_12 -> V_15 = V_15 ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_1 V_13 )
{
F_15 ( ( V_13 & ( V_17 - 1 ) ) != 0 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_15 = NULL ;
F_16 ( & V_12 -> V_18 ) ;
V_12 -> V_19 = 0 ;
V_12 -> V_13 = V_13 ;
F_17 ( & V_12 -> V_20 ) ;
}
static void
F_18 ( struct V_11 * V_12 , struct V_21 * V_15 )
{
F_19 ( & V_15 -> V_22 . V_23 ) ;
if ( V_12 -> V_24 ) {
F_20 ( & V_15 -> V_22 ,
V_12 -> V_24 ) ;
}
F_21 ( & V_15 -> V_22 . V_23 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_12 -> V_25 ) {
F_23 ( & V_2 -> V_6 , V_12 -> V_25 ) ;
V_12 -> V_25 = 0 ;
}
}
static void F_24 ( struct V_11 * V_12 )
{
if ( V_12 -> V_24 ) {
F_25 ( V_12 -> V_24 ) ;
V_12 -> V_24 = NULL ;
}
}
static void
F_26 ( struct V_11 * V_12 )
{
if ( F_27 ( V_12 -> V_19 == 0 ) )
return;
F_19 ( & V_12 -> V_2 -> V_5 ) ;
if ( -- V_12 -> V_19 == 0 ) {
F_22 ( V_12 ) ;
F_24 ( V_12 ) ;
}
F_21 ( & V_12 -> V_2 -> V_5 ) ;
F_28 ( V_12 ) ;
}
int
F_29 ( struct V_21 * V_15 , T_2 V_26 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_30 ( & V_15 -> V_27 ) ;
V_12 = F_31 ( & V_15 -> V_28 , V_26 ) ;
if ( V_12 == NULL ) {
F_32 ( & V_15 -> V_27 ) ;
return - V_29 ;
}
V_2 = V_12 -> V_2 ;
F_23 ( & V_15 -> V_28 , V_26 ) ;
F_32 ( & V_15 -> V_27 ) ;
if ( F_33 ( V_2 , V_30 ) )
F_18 ( V_12 , V_15 ) ;
F_34 ( & V_12 -> V_20 , V_15 -> V_15 ) ;
if ( V_2 -> V_31 -> V_32 )
V_2 -> V_31 -> V_32 ( V_12 , V_15 ) ;
F_26 ( V_12 ) ;
return 0 ;
}
int F_35 ( struct V_21 * V_14 ,
struct V_1 * V_2 ,
T_3 V_26 )
{
return F_29 ( V_14 , V_26 ) ;
}
int
F_36 ( struct V_21 * V_33 ,
struct V_11 * V_12 ,
T_2 * V_34 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
int V_35 ;
F_27 ( ! F_37 ( & V_2 -> V_5 ) ) ;
F_38 ( V_7 ) ;
F_30 ( & V_33 -> V_27 ) ;
V_35 = F_39 ( & V_33 -> V_28 , V_12 , 1 , 0 , V_36 ) ;
F_40 ( V_12 ) ;
V_12 -> V_19 ++ ;
F_32 ( & V_33 -> V_27 ) ;
F_41 () ;
F_21 ( & V_2 -> V_5 ) ;
if ( V_35 < 0 ) {
F_26 ( V_12 ) ;
return V_35 ;
}
* V_34 = V_35 ;
V_35 = F_42 ( & V_12 -> V_20 , V_33 -> V_15 ) ;
if ( V_35 ) {
F_29 ( V_33 , * V_34 ) ;
return V_35 ;
}
if ( V_2 -> V_31 -> V_37 ) {
V_35 = V_2 -> V_31 -> V_37 ( V_12 , V_33 ) ;
if ( V_35 ) {
F_29 ( V_33 , * V_34 ) ;
return V_35 ;
}
}
return 0 ;
}
int
F_43 ( struct V_21 * V_33 ,
struct V_11 * V_12 ,
T_2 * V_34 )
{
F_19 ( & V_12 -> V_2 -> V_5 ) ;
return F_36 ( V_33 , V_12 , V_34 ) ;
}
void
F_44 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_45 ( V_2 -> V_4 , & V_12 -> V_20 ) ;
}
int
F_46 ( struct V_11 * V_12 , T_1 V_13 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
return F_47 ( V_2 -> V_4 , & V_12 -> V_20 ,
V_13 / V_17 ) ;
}
int F_48 ( struct V_11 * V_12 )
{
return F_46 ( V_12 , V_12 -> V_13 ) ;
}
struct V_38 * * F_49 ( struct V_11 * V_12 )
{
struct V_39 * V_40 ;
struct V_38 * V_41 , * * V_42 ;
int V_43 , V_44 ;
V_40 = F_50 ( V_12 -> V_15 ) -> V_45 ;
F_27 ( ( V_12 -> V_13 & ( V_17 - 1 ) ) != 0 ) ;
V_44 = V_12 -> V_13 >> V_46 ;
V_42 = F_51 ( V_44 , sizeof( struct V_38 * ) ) ;
if ( V_42 == NULL )
return F_52 ( - V_8 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_41 = F_53 ( V_40 , V_43 ) ;
if ( F_13 ( V_41 ) )
goto V_47;
V_42 [ V_43 ] = V_41 ;
F_15 ( ( F_54 ( V_40 ) & V_48 ) &&
( F_55 ( V_41 ) >= 0x00100000UL ) ) ;
}
return V_42 ;
V_47:
while ( V_43 -- )
F_56 ( V_42 [ V_43 ] ) ;
F_57 ( V_42 ) ;
return F_58 ( V_41 ) ;
}
void F_59 ( struct V_11 * V_12 , struct V_38 * * V_42 ,
bool V_49 , bool V_50 )
{
int V_43 , V_44 ;
F_27 ( ( V_12 -> V_13 & ( V_17 - 1 ) ) != 0 ) ;
V_44 = V_12 -> V_13 >> V_46 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_49 )
F_60 ( V_42 [ V_43 ] ) ;
if ( V_50 )
F_61 ( V_42 [ V_43 ] ) ;
F_56 ( V_42 [ V_43 ] ) ;
}
F_57 ( V_42 ) ;
}
struct V_11 *
F_62 ( struct V_1 * V_2 , struct V_21 * V_15 ,
T_2 V_26 )
{
struct V_11 * V_12 ;
F_30 ( & V_15 -> V_27 ) ;
V_12 = F_31 ( & V_15 -> V_28 , V_26 ) ;
if ( V_12 == NULL ) {
F_32 ( & V_15 -> V_27 ) ;
return NULL ;
}
F_40 ( V_12 ) ;
F_32 ( & V_15 -> V_27 ) ;
return V_12 ;
}
int
F_63 ( struct V_1 * V_2 , void * V_51 ,
struct V_21 * V_33 )
{
struct V_52 * args = V_51 ;
int V_35 ;
if ( ! ( V_2 -> V_31 -> V_53 & V_54 ) )
return - V_55 ;
V_35 = F_29 ( V_33 , args -> V_26 ) ;
return V_35 ;
}
int
F_64 ( struct V_1 * V_2 , void * V_51 ,
struct V_21 * V_33 )
{
struct V_56 * args = V_51 ;
struct V_11 * V_12 ;
int V_35 ;
if ( ! ( V_2 -> V_31 -> V_53 & V_54 ) )
return - V_55 ;
V_12 = F_62 ( V_2 , V_33 , args -> V_26 ) ;
if ( V_12 == NULL )
return - V_57 ;
F_19 ( & V_2 -> V_5 ) ;
F_38 ( V_7 ) ;
if ( V_12 -> V_19 == 0 ) {
V_35 = - V_57 ;
goto V_58;
}
if ( ! V_12 -> V_25 ) {
V_35 = F_39 ( & V_2 -> V_6 , V_12 , 1 , 0 , V_36 ) ;
if ( V_35 < 0 )
goto V_58;
V_12 -> V_25 = V_35 ;
}
args -> V_25 = ( V_59 ) V_12 -> V_25 ;
V_35 = 0 ;
V_58:
F_41 () ;
F_21 ( & V_2 -> V_5 ) ;
F_28 ( V_12 ) ;
return V_35 ;
}
int
F_65 ( struct V_1 * V_2 , void * V_51 ,
struct V_21 * V_33 )
{
struct V_60 * args = V_51 ;
struct V_11 * V_12 ;
int V_35 ;
T_2 V_26 ;
if ( ! ( V_2 -> V_31 -> V_53 & V_54 ) )
return - V_55 ;
F_19 ( & V_2 -> V_5 ) ;
V_12 = F_31 ( & V_2 -> V_6 , ( int ) args -> V_25 ) ;
if ( V_12 ) {
F_40 ( V_12 ) ;
} else {
F_21 ( & V_2 -> V_5 ) ;
return - V_57 ;
}
V_35 = F_36 ( V_33 , V_12 , & V_26 ) ;
F_28 ( V_12 ) ;
if ( V_35 )
return V_35 ;
args -> V_26 = V_26 ;
args -> V_13 = V_12 -> V_13 ;
return 0 ;
}
void
V_60 ( struct V_1 * V_2 , struct V_21 * V_61 )
{
F_3 ( & V_61 -> V_28 ) ;
F_66 ( & V_61 -> V_27 ) ;
}
static int
F_67 ( int V_62 , void * V_63 , void * V_51 )
{
struct V_21 * V_33 = V_51 ;
struct V_11 * V_12 = V_63 ;
struct V_1 * V_2 = V_12 -> V_2 ;
if ( F_33 ( V_2 , V_30 ) )
F_18 ( V_12 , V_33 ) ;
F_34 ( & V_12 -> V_20 , V_33 -> V_15 ) ;
if ( V_2 -> V_31 -> V_32 )
V_2 -> V_31 -> V_32 ( V_12 , V_33 ) ;
F_26 ( V_12 ) ;
return 0 ;
}
void
F_68 ( struct V_1 * V_2 , struct V_21 * V_61 )
{
F_69 ( & V_61 -> V_28 ,
& F_67 , V_61 ) ;
F_70 ( & V_61 -> V_28 ) ;
}
void
F_71 ( struct V_11 * V_12 )
{
F_27 ( V_12 -> V_24 ) ;
if ( V_12 -> V_15 )
F_72 ( V_12 -> V_15 ) ;
F_44 ( V_12 ) ;
}
void
F_73 ( struct V_64 * V_64 )
{
struct V_11 * V_12 = (struct V_11 * ) V_64 ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_15 ( ! F_37 ( & V_2 -> V_65 ) ) ;
if ( V_2 -> V_31 -> V_66 != NULL )
V_2 -> V_31 -> V_66 ( V_12 ) ;
}
void F_74 ( struct V_67 * V_68 )
{
struct V_11 * V_12 = V_68 -> V_69 ;
F_40 ( V_12 ) ;
F_19 ( & V_12 -> V_2 -> V_65 ) ;
F_75 ( V_12 -> V_2 , V_68 ) ;
F_21 ( & V_12 -> V_2 -> V_65 ) ;
}
void F_76 ( struct V_67 * V_68 )
{
struct V_11 * V_12 = V_68 -> V_69 ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_19 ( & V_2 -> V_65 ) ;
F_77 ( V_12 -> V_2 , V_68 ) ;
F_78 ( V_12 ) ;
F_21 ( & V_2 -> V_65 ) ;
}
int F_79 ( struct V_11 * V_12 , unsigned long V_70 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_80 ( & V_2 -> V_65 ) ;
if ( V_70 < V_68 -> V_71 - V_68 -> V_72 )
return - V_29 ;
if ( ! V_2 -> V_31 -> V_73 )
return - V_29 ;
V_68 -> V_74 |= V_75 | V_76 | V_77 | V_78 ;
V_68 -> V_79 = V_2 -> V_31 -> V_73 ;
V_68 -> V_69 = V_12 ;
V_68 -> V_80 = F_81 ( F_82 ( V_68 -> V_74 ) ) ;
F_40 ( V_12 ) ;
F_75 ( V_2 , V_68 ) ;
return 0 ;
}
int F_83 ( struct V_14 * V_15 , struct V_67 * V_68 )
{
struct V_21 * V_81 = V_15 -> V_82 ;
struct V_1 * V_2 = V_81 -> V_83 -> V_2 ;
struct V_11 * V_12 ;
struct V_84 * V_85 ;
int V_35 ;
if ( F_84 ( V_2 ) )
return - V_55 ;
F_19 ( & V_2 -> V_65 ) ;
V_85 = F_85 ( V_2 -> V_4 ,
V_68 -> V_86 ,
F_86 ( V_68 ) ) ;
if ( ! V_85 ) {
F_21 ( & V_2 -> V_65 ) ;
return F_87 ( V_15 , V_68 ) ;
} else if ( ! F_88 ( V_85 , V_15 ) ) {
F_21 ( & V_2 -> V_65 ) ;
return - V_87 ;
}
V_12 = F_89 ( V_85 , struct V_11 , V_20 ) ;
V_35 = F_79 ( V_12 , F_90 ( V_85 ) << V_46 , V_68 ) ;
F_21 ( & V_2 -> V_65 ) ;
return V_35 ;
}
