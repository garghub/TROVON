int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
V_4 = F_4 ( sizeof( struct V_3 ) , V_7 ) ;
if ( ! V_4 ) {
F_5 ( L_1 ) ;
return - V_8 ;
}
V_2 -> V_9 = V_4 ;
F_6 ( & V_4 -> V_10 ,
V_11 ,
V_12 ) ;
return 0 ;
}
void
F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
F_8 ( & V_4 -> V_10 ) ;
F_9 ( V_4 ) ;
V_2 -> V_9 = NULL ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 , T_1 V_15 )
{
struct V_16 * V_17 ;
V_17 = F_11 ( L_2 , V_15 , V_18 ) ;
if ( F_12 ( V_17 ) )
return F_13 ( V_17 ) ;
F_14 ( V_2 , V_14 , V_15 ) ;
V_14 -> V_17 = V_17 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_13 * V_14 , T_1 V_15 )
{
F_15 ( ( V_15 & ( V_19 - 1 ) ) != 0 ) ;
V_14 -> V_2 = V_2 ;
V_14 -> V_17 = NULL ;
F_16 ( & V_14 -> V_20 ) ;
V_14 -> V_21 = 0 ;
V_14 -> V_15 = V_15 ;
F_17 ( & V_14 -> V_22 ) ;
}
static void
F_18 ( struct V_13 * V_14 , struct V_23 * V_17 )
{
F_19 ( & V_17 -> V_24 . V_25 ) ;
if ( V_14 -> V_26 ) {
F_20 ( & V_17 -> V_24 ,
V_14 -> V_26 ) ;
}
F_21 ( & V_17 -> V_24 . V_25 ) ;
}
static void F_22 ( struct V_27 * V_28 )
{
F_23 () ;
}
static void F_24 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_14 -> V_29 ) {
F_25 ( & V_2 -> V_6 , V_14 -> V_29 ) ;
V_14 -> V_29 = 0 ;
F_26 ( & V_14 -> V_20 , F_22 ) ;
}
}
static void F_27 ( struct V_13 * V_14 )
{
if ( V_14 -> V_26 ) {
F_28 ( V_14 -> V_26 ) ;
V_14 -> V_26 = NULL ;
}
}
static void
F_29 ( struct V_13 * V_14 )
{
if ( F_30 ( V_14 -> V_21 == 0 ) )
return;
F_19 ( & V_14 -> V_2 -> V_5 ) ;
if ( -- V_14 -> V_21 == 0 ) {
F_24 ( V_14 ) ;
F_27 ( V_14 ) ;
}
F_21 ( & V_14 -> V_2 -> V_5 ) ;
F_31 ( V_14 ) ;
}
int
F_32 ( struct V_23 * V_17 , T_2 V_30 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
F_33 ( & V_17 -> V_31 ) ;
V_14 = F_34 ( & V_17 -> V_32 , V_30 ) ;
if ( V_14 == NULL ) {
F_35 ( & V_17 -> V_31 ) ;
return - V_33 ;
}
V_2 = V_14 -> V_2 ;
F_25 ( & V_17 -> V_32 , V_30 ) ;
F_35 ( & V_17 -> V_31 ) ;
if ( F_36 ( V_2 , V_34 ) )
F_18 ( V_14 , V_17 ) ;
F_37 ( & V_14 -> V_22 , V_17 -> V_17 ) ;
if ( V_2 -> V_35 -> V_36 )
V_2 -> V_35 -> V_36 ( V_14 , V_17 ) ;
F_29 ( V_14 ) ;
return 0 ;
}
int F_38 ( struct V_23 * V_16 ,
struct V_1 * V_2 ,
T_3 V_30 )
{
return F_32 ( V_16 , V_30 ) ;
}
int
F_39 ( struct V_23 * V_37 ,
struct V_13 * V_14 ,
T_2 * V_38 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
int V_39 ;
F_30 ( ! F_40 ( & V_2 -> V_5 ) ) ;
F_41 ( V_7 ) ;
F_33 ( & V_37 -> V_31 ) ;
V_39 = F_42 ( & V_37 -> V_32 , V_14 , 1 , 0 , V_40 ) ;
F_43 ( V_14 ) ;
V_14 -> V_21 ++ ;
F_35 ( & V_37 -> V_31 ) ;
F_44 () ;
F_21 ( & V_2 -> V_5 ) ;
if ( V_39 < 0 ) {
F_29 ( V_14 ) ;
return V_39 ;
}
* V_38 = V_39 ;
V_39 = F_45 ( & V_14 -> V_22 , V_37 -> V_17 ) ;
if ( V_39 ) {
F_32 ( V_37 , * V_38 ) ;
return V_39 ;
}
if ( V_2 -> V_35 -> V_41 ) {
V_39 = V_2 -> V_35 -> V_41 ( V_14 , V_37 ) ;
if ( V_39 ) {
F_32 ( V_37 , * V_38 ) ;
return V_39 ;
}
}
return 0 ;
}
int
F_46 ( struct V_23 * V_37 ,
struct V_13 * V_14 ,
T_2 * V_38 )
{
F_19 ( & V_14 -> V_2 -> V_5 ) ;
return F_39 ( V_37 , V_14 , V_38 ) ;
}
void
F_47 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
F_48 ( & V_4 -> V_10 , & V_14 -> V_22 ) ;
}
int
F_49 ( struct V_13 * V_14 , T_1 V_15 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
return F_50 ( & V_4 -> V_10 , & V_14 -> V_22 ,
V_15 / V_19 ) ;
}
int F_51 ( struct V_13 * V_14 )
{
return F_49 ( V_14 , V_14 -> V_15 ) ;
}
struct V_42 * * F_52 ( struct V_13 * V_14 , T_4 V_43 )
{
struct V_44 * V_44 ;
struct V_45 * V_46 ;
struct V_42 * V_47 , * * V_48 ;
int V_49 , V_50 ;
V_44 = F_53 ( V_14 -> V_17 ) ;
V_46 = V_44 -> V_51 ;
F_30 ( ( V_14 -> V_15 & ( V_19 - 1 ) ) != 0 ) ;
V_50 = V_14 -> V_15 >> V_52 ;
V_48 = F_54 ( V_50 , sizeof( struct V_42 * ) ) ;
if ( V_48 == NULL )
return F_55 ( - V_8 ) ;
V_43 |= F_56 ( V_46 ) ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
V_47 = F_57 ( V_46 , V_49 , V_43 ) ;
if ( F_12 ( V_47 ) )
goto V_53;
V_48 [ V_49 ] = V_47 ;
F_15 ( ( V_43 & V_54 ) &&
( F_58 ( V_47 ) >= 0x00100000UL ) ) ;
}
return V_48 ;
V_53:
while ( V_49 -- )
F_59 ( V_48 [ V_49 ] ) ;
F_60 ( V_48 ) ;
return F_61 ( V_47 ) ;
}
void F_62 ( struct V_13 * V_14 , struct V_42 * * V_48 ,
bool V_55 , bool V_56 )
{
int V_49 , V_50 ;
F_30 ( ( V_14 -> V_15 & ( V_19 - 1 ) ) != 0 ) ;
V_50 = V_14 -> V_15 >> V_52 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( V_55 )
F_63 ( V_48 [ V_49 ] ) ;
if ( V_56 )
F_64 ( V_48 [ V_49 ] ) ;
F_59 ( V_48 [ V_49 ] ) ;
}
F_60 ( V_48 ) ;
}
struct V_13 *
F_65 ( struct V_1 * V_2 , struct V_23 * V_17 ,
T_2 V_30 )
{
struct V_13 * V_14 ;
F_33 ( & V_17 -> V_31 ) ;
V_14 = F_34 ( & V_17 -> V_32 , V_30 ) ;
if ( V_14 == NULL ) {
F_35 ( & V_17 -> V_31 ) ;
return NULL ;
}
F_43 ( V_14 ) ;
F_35 ( & V_17 -> V_31 ) ;
return V_14 ;
}
int
F_66 ( struct V_1 * V_2 , void * V_57 ,
struct V_23 * V_37 )
{
struct V_58 * args = V_57 ;
int V_39 ;
if ( ! ( V_2 -> V_35 -> V_59 & V_60 ) )
return - V_61 ;
V_39 = F_32 ( V_37 , args -> V_30 ) ;
return V_39 ;
}
int
F_67 ( struct V_1 * V_2 , void * V_57 ,
struct V_23 * V_37 )
{
struct V_62 * args = V_57 ;
struct V_13 * V_14 ;
int V_39 ;
if ( ! ( V_2 -> V_35 -> V_59 & V_60 ) )
return - V_61 ;
V_14 = F_65 ( V_2 , V_37 , args -> V_30 ) ;
if ( V_14 == NULL )
return - V_63 ;
F_19 ( & V_2 -> V_5 ) ;
F_41 ( V_7 ) ;
if ( V_14 -> V_21 == 0 ) {
V_39 = - V_63 ;
goto V_64;
}
if ( ! V_14 -> V_29 ) {
V_39 = F_42 ( & V_2 -> V_6 , V_14 , 1 , 0 , V_40 ) ;
if ( V_39 < 0 )
goto V_64;
V_14 -> V_29 = V_39 ;
F_43 ( V_14 ) ;
}
args -> V_29 = ( V_65 ) V_14 -> V_29 ;
V_39 = 0 ;
V_64:
F_44 () ;
F_21 ( & V_2 -> V_5 ) ;
F_31 ( V_14 ) ;
return V_39 ;
}
int
F_68 ( struct V_1 * V_2 , void * V_57 ,
struct V_23 * V_37 )
{
struct V_66 * args = V_57 ;
struct V_13 * V_14 ;
int V_39 ;
T_2 V_30 ;
if ( ! ( V_2 -> V_35 -> V_59 & V_60 ) )
return - V_61 ;
F_19 ( & V_2 -> V_5 ) ;
V_14 = F_34 ( & V_2 -> V_6 , ( int ) args -> V_29 ) ;
if ( V_14 ) {
F_43 ( V_14 ) ;
} else {
F_21 ( & V_2 -> V_5 ) ;
return - V_63 ;
}
V_39 = F_39 ( V_37 , V_14 , & V_30 ) ;
F_31 ( V_14 ) ;
if ( V_39 )
return V_39 ;
args -> V_30 = V_30 ;
args -> V_15 = V_14 -> V_15 ;
return 0 ;
}
void
V_66 ( struct V_1 * V_2 , struct V_23 * V_67 )
{
F_3 ( & V_67 -> V_32 ) ;
F_69 ( & V_67 -> V_31 ) ;
}
static int
F_70 ( int V_68 , void * V_69 , void * V_57 )
{
struct V_23 * V_37 = V_57 ;
struct V_13 * V_14 = V_69 ;
struct V_1 * V_2 = V_14 -> V_2 ;
if ( F_36 ( V_2 , V_34 ) )
F_18 ( V_14 , V_37 ) ;
F_37 ( & V_14 -> V_22 , V_37 -> V_17 ) ;
if ( V_2 -> V_35 -> V_36 )
V_2 -> V_35 -> V_36 ( V_14 , V_37 ) ;
F_29 ( V_14 ) ;
return 0 ;
}
void
F_71 ( struct V_1 * V_2 , struct V_23 * V_67 )
{
F_72 ( & V_67 -> V_32 ,
& F_70 , V_67 ) ;
F_73 ( & V_67 -> V_32 ) ;
}
void
F_74 ( struct V_13 * V_14 )
{
F_30 ( V_14 -> V_26 ) ;
if ( V_14 -> V_17 )
F_75 ( V_14 -> V_17 ) ;
}
void
F_76 ( struct V_27 * V_27 )
{
struct V_13 * V_14 = (struct V_13 * ) V_27 ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_15 ( ! F_40 ( & V_2 -> V_70 ) ) ;
if ( V_2 -> V_35 -> V_71 != NULL )
V_2 -> V_35 -> V_71 ( V_14 ) ;
}
void F_77 ( struct V_72 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_74 ;
F_43 ( V_14 ) ;
F_19 ( & V_14 -> V_2 -> V_70 ) ;
F_78 ( V_14 -> V_2 , V_73 ) ;
F_21 ( & V_14 -> V_2 -> V_70 ) ;
}
void F_79 ( struct V_72 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_74 ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_19 ( & V_2 -> V_70 ) ;
F_80 ( V_14 -> V_2 , V_73 ) ;
F_81 ( V_14 ) ;
F_21 ( & V_2 -> V_70 ) ;
}
int F_82 ( struct V_13 * V_14 , unsigned long V_75 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
F_83 ( & V_2 -> V_70 ) ;
if ( V_75 < V_73 -> V_76 - V_73 -> V_77 )
return - V_33 ;
if ( ! V_2 -> V_35 -> V_78 )
return - V_33 ;
V_73 -> V_79 |= V_80 | V_81 | V_82 | V_83 ;
V_73 -> V_84 = V_2 -> V_35 -> V_78 ;
V_73 -> V_74 = V_14 ;
V_73 -> V_85 = F_84 ( F_85 ( V_73 -> V_79 ) ) ;
F_43 ( V_14 ) ;
F_78 ( V_2 , V_73 ) ;
return 0 ;
}
int F_86 ( struct V_16 * V_17 , struct V_72 * V_73 )
{
struct V_23 * V_86 = V_17 -> V_87 ;
struct V_1 * V_2 = V_86 -> V_88 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_13 * V_14 ;
struct V_89 * V_90 ;
int V_39 = 0 ;
if ( F_87 ( V_2 ) )
return - V_61 ;
F_19 ( & V_2 -> V_70 ) ;
V_90 = F_88 ( & V_4 -> V_10 , V_73 -> V_91 ,
F_89 ( V_73 ) ) ;
if ( ! V_90 ) {
F_21 ( & V_2 -> V_70 ) ;
return F_90 ( V_17 , V_73 ) ;
} else if ( ! F_91 ( V_90 , V_17 ) ) {
F_21 ( & V_2 -> V_70 ) ;
return - V_92 ;
}
V_14 = F_92 ( V_90 , struct V_13 , V_22 ) ;
V_39 = F_82 ( V_14 , F_93 ( V_90 ) << V_52 , V_73 ) ;
F_21 ( & V_2 -> V_70 ) ;
return V_39 ;
}
