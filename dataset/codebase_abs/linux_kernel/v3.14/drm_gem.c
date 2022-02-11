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
struct V_38 * * F_49 ( struct V_11 * V_12 , T_4 V_39 )
{
struct V_40 * V_40 ;
struct V_41 * V_42 ;
struct V_38 * V_43 , * * V_44 ;
int V_45 , V_46 ;
V_40 = F_50 ( V_12 -> V_15 ) ;
V_42 = V_40 -> V_47 ;
F_27 ( ( V_12 -> V_13 & ( V_17 - 1 ) ) != 0 ) ;
V_46 = V_12 -> V_13 >> V_48 ;
V_44 = F_51 ( V_46 , sizeof( struct V_38 * ) ) ;
if ( V_44 == NULL )
return F_52 ( - V_8 ) ;
V_39 |= F_53 ( V_42 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
V_43 = F_54 ( V_42 , V_45 , V_39 ) ;
if ( F_13 ( V_43 ) )
goto V_49;
V_44 [ V_45 ] = V_43 ;
F_15 ( ( V_39 & V_50 ) &&
( F_55 ( V_43 ) >= 0x00100000UL ) ) ;
}
return V_44 ;
V_49:
while ( V_45 -- )
F_56 ( V_44 [ V_45 ] ) ;
F_57 ( V_44 ) ;
return F_58 ( V_43 ) ;
}
void F_59 ( struct V_11 * V_12 , struct V_38 * * V_44 ,
bool V_51 , bool V_52 )
{
int V_45 , V_46 ;
F_27 ( ( V_12 -> V_13 & ( V_17 - 1 ) ) != 0 ) ;
V_46 = V_12 -> V_13 >> V_48 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
if ( V_51 )
F_60 ( V_44 [ V_45 ] ) ;
if ( V_52 )
F_61 ( V_44 [ V_45 ] ) ;
F_56 ( V_44 [ V_45 ] ) ;
}
F_57 ( V_44 ) ;
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
F_63 ( struct V_1 * V_2 , void * V_53 ,
struct V_21 * V_33 )
{
struct V_54 * args = V_53 ;
int V_35 ;
if ( ! ( V_2 -> V_31 -> V_55 & V_56 ) )
return - V_57 ;
V_35 = F_29 ( V_33 , args -> V_26 ) ;
return V_35 ;
}
int
F_64 ( struct V_1 * V_2 , void * V_53 ,
struct V_21 * V_33 )
{
struct V_58 * args = V_53 ;
struct V_11 * V_12 ;
int V_35 ;
if ( ! ( V_2 -> V_31 -> V_55 & V_56 ) )
return - V_57 ;
V_12 = F_62 ( V_2 , V_33 , args -> V_26 ) ;
if ( V_12 == NULL )
return - V_59 ;
F_19 ( & V_2 -> V_5 ) ;
F_38 ( V_7 ) ;
if ( V_12 -> V_19 == 0 ) {
V_35 = - V_59 ;
goto V_60;
}
if ( ! V_12 -> V_25 ) {
V_35 = F_39 ( & V_2 -> V_6 , V_12 , 1 , 0 , V_36 ) ;
if ( V_35 < 0 )
goto V_60;
V_12 -> V_25 = V_35 ;
}
args -> V_25 = ( V_61 ) V_12 -> V_25 ;
V_35 = 0 ;
V_60:
F_41 () ;
F_21 ( & V_2 -> V_5 ) ;
F_28 ( V_12 ) ;
return V_35 ;
}
int
F_65 ( struct V_1 * V_2 , void * V_53 ,
struct V_21 * V_33 )
{
struct V_62 * args = V_53 ;
struct V_11 * V_12 ;
int V_35 ;
T_2 V_26 ;
if ( ! ( V_2 -> V_31 -> V_55 & V_56 ) )
return - V_57 ;
F_19 ( & V_2 -> V_5 ) ;
V_12 = F_31 ( & V_2 -> V_6 , ( int ) args -> V_25 ) ;
if ( V_12 ) {
F_40 ( V_12 ) ;
} else {
F_21 ( & V_2 -> V_5 ) ;
return - V_59 ;
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
V_62 ( struct V_1 * V_2 , struct V_21 * V_63 )
{
F_3 ( & V_63 -> V_28 ) ;
F_66 ( & V_63 -> V_27 ) ;
}
static int
F_67 ( int V_64 , void * V_65 , void * V_53 )
{
struct V_21 * V_33 = V_53 ;
struct V_11 * V_12 = V_65 ;
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
F_68 ( struct V_1 * V_2 , struct V_21 * V_63 )
{
F_69 ( & V_63 -> V_28 ,
& F_67 , V_63 ) ;
F_70 ( & V_63 -> V_28 ) ;
}
void
F_71 ( struct V_11 * V_12 )
{
F_27 ( V_12 -> V_24 ) ;
if ( V_12 -> V_15 )
F_72 ( V_12 -> V_15 ) ;
}
void
F_73 ( struct V_66 * V_66 )
{
struct V_11 * V_12 = (struct V_11 * ) V_66 ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_15 ( ! F_37 ( & V_2 -> V_67 ) ) ;
if ( V_2 -> V_31 -> V_68 != NULL )
V_2 -> V_31 -> V_68 ( V_12 ) ;
}
void F_74 ( struct V_69 * V_70 )
{
struct V_11 * V_12 = V_70 -> V_71 ;
F_40 ( V_12 ) ;
F_19 ( & V_12 -> V_2 -> V_67 ) ;
F_75 ( V_12 -> V_2 , V_70 ) ;
F_21 ( & V_12 -> V_2 -> V_67 ) ;
}
void F_76 ( struct V_69 * V_70 )
{
struct V_11 * V_12 = V_70 -> V_71 ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_19 ( & V_2 -> V_67 ) ;
F_77 ( V_12 -> V_2 , V_70 ) ;
F_78 ( V_12 ) ;
F_21 ( & V_2 -> V_67 ) ;
}
int F_79 ( struct V_11 * V_12 , unsigned long V_72 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_80 ( & V_2 -> V_67 ) ;
if ( V_72 < V_70 -> V_73 - V_70 -> V_74 )
return - V_29 ;
if ( ! V_2 -> V_31 -> V_75 )
return - V_29 ;
V_70 -> V_76 |= V_77 | V_78 | V_79 | V_80 ;
V_70 -> V_81 = V_2 -> V_31 -> V_75 ;
V_70 -> V_71 = V_12 ;
V_70 -> V_82 = F_81 ( F_82 ( V_70 -> V_76 ) ) ;
F_40 ( V_12 ) ;
F_75 ( V_2 , V_70 ) ;
return 0 ;
}
int F_83 ( struct V_14 * V_15 , struct V_69 * V_70 )
{
struct V_21 * V_83 = V_15 -> V_84 ;
struct V_1 * V_2 = V_83 -> V_85 -> V_2 ;
struct V_11 * V_12 ;
struct V_86 * V_87 ;
int V_35 = 0 ;
if ( F_84 ( V_2 ) )
return - V_57 ;
F_19 ( & V_2 -> V_67 ) ;
V_87 = F_85 ( V_2 -> V_4 ,
V_70 -> V_88 ,
F_86 ( V_70 ) ) ;
if ( ! V_87 ) {
F_21 ( & V_2 -> V_67 ) ;
return F_87 ( V_15 , V_70 ) ;
} else if ( ! F_88 ( V_87 , V_15 ) ) {
F_21 ( & V_2 -> V_67 ) ;
return - V_89 ;
}
V_12 = F_89 ( V_87 , struct V_11 , V_20 ) ;
V_35 = F_79 ( V_12 , F_90 ( V_87 ) << V_48 , V_70 ) ;
F_21 ( & V_2 -> V_67 ) ;
return V_35 ;
}
