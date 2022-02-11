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
struct V_13 *
F_18 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_13 * V_14 ;
V_14 = F_4 ( sizeof( * V_14 ) , V_7 ) ;
if ( ! V_14 )
goto free;
if ( F_10 ( V_2 , V_14 , V_15 ) != 0 )
goto free;
if ( V_2 -> V_23 -> V_24 != NULL &&
V_2 -> V_23 -> V_24 ( V_14 ) != 0 ) {
goto V_25;
}
return V_14 ;
V_25:
V_25 ( V_14 -> V_17 ) ;
free:
F_9 ( V_14 ) ;
return NULL ;
}
static void
F_19 ( struct V_13 * V_14 , struct V_26 * V_17 )
{
F_20 ( & V_17 -> V_27 . V_28 ) ;
if ( V_14 -> V_29 ) {
F_21 ( & V_17 -> V_27 ,
V_14 -> V_29 ) ;
}
F_22 ( & V_17 -> V_27 . V_28 ) ;
}
static void F_23 ( struct V_30 * V_31 )
{
F_24 () ;
}
static void F_25 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_14 -> V_32 ) {
F_26 ( & V_2 -> V_6 , V_14 -> V_32 ) ;
V_14 -> V_32 = 0 ;
F_27 ( & V_14 -> V_20 , F_23 ) ;
}
}
static void F_28 ( struct V_13 * V_14 )
{
if ( V_14 -> V_29 ) {
F_29 ( V_14 -> V_29 ) ;
V_14 -> V_29 = NULL ;
}
}
static void
F_30 ( struct V_13 * V_14 )
{
if ( F_31 ( V_14 -> V_21 == 0 ) )
return;
F_20 ( & V_14 -> V_2 -> V_5 ) ;
if ( -- V_14 -> V_21 == 0 ) {
F_25 ( V_14 ) ;
F_28 ( V_14 ) ;
}
F_22 ( & V_14 -> V_2 -> V_5 ) ;
F_32 ( V_14 ) ;
}
int
F_33 ( struct V_26 * V_17 , T_2 V_33 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
F_34 ( & V_17 -> V_34 ) ;
V_14 = F_35 ( & V_17 -> V_35 , V_33 ) ;
if ( V_14 == NULL ) {
F_36 ( & V_17 -> V_34 ) ;
return - V_36 ;
}
V_2 = V_14 -> V_2 ;
F_26 ( & V_17 -> V_35 , V_33 ) ;
F_36 ( & V_17 -> V_34 ) ;
if ( F_37 ( V_2 , V_37 ) )
F_19 ( V_14 , V_17 ) ;
F_38 ( & V_14 -> V_22 , V_17 -> V_17 ) ;
if ( V_2 -> V_23 -> V_38 )
V_2 -> V_23 -> V_38 ( V_14 , V_17 ) ;
F_30 ( V_14 ) ;
return 0 ;
}
int F_39 ( struct V_26 * V_16 ,
struct V_1 * V_2 ,
T_3 V_33 )
{
return F_33 ( V_16 , V_33 ) ;
}
int
F_40 ( struct V_26 * V_39 ,
struct V_13 * V_14 ,
T_2 * V_40 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
int V_41 ;
F_31 ( ! F_41 ( & V_2 -> V_5 ) ) ;
F_42 ( V_7 ) ;
F_34 ( & V_39 -> V_34 ) ;
V_41 = F_43 ( & V_39 -> V_35 , V_14 , 1 , 0 , V_42 ) ;
F_44 ( V_14 ) ;
V_14 -> V_21 ++ ;
F_36 ( & V_39 -> V_34 ) ;
F_45 () ;
F_22 ( & V_2 -> V_5 ) ;
if ( V_41 < 0 ) {
F_30 ( V_14 ) ;
return V_41 ;
}
* V_40 = V_41 ;
V_41 = F_46 ( & V_14 -> V_22 , V_39 -> V_17 ) ;
if ( V_41 ) {
F_33 ( V_39 , * V_40 ) ;
return V_41 ;
}
if ( V_2 -> V_23 -> V_43 ) {
V_41 = V_2 -> V_23 -> V_43 ( V_14 , V_39 ) ;
if ( V_41 ) {
F_33 ( V_39 , * V_40 ) ;
return V_41 ;
}
}
return 0 ;
}
int
F_47 ( struct V_26 * V_39 ,
struct V_13 * V_14 ,
T_2 * V_40 )
{
F_20 ( & V_14 -> V_2 -> V_5 ) ;
return F_40 ( V_39 , V_14 , V_40 ) ;
}
void
F_48 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
F_49 ( & V_4 -> V_10 , & V_14 -> V_22 ) ;
}
int
F_50 ( struct V_13 * V_14 , T_1 V_15 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
return F_51 ( & V_4 -> V_10 , & V_14 -> V_22 ,
V_15 / V_19 ) ;
}
int F_52 ( struct V_13 * V_14 )
{
return F_50 ( V_14 , V_14 -> V_15 ) ;
}
struct V_44 * * F_53 ( struct V_13 * V_14 , T_4 V_45 )
{
struct V_46 * V_46 ;
struct V_47 * V_48 ;
struct V_44 * V_49 , * * V_50 ;
int V_51 , V_52 ;
V_46 = F_54 ( V_14 -> V_17 ) ;
V_48 = V_46 -> V_53 ;
F_31 ( ( V_14 -> V_15 & ( V_19 - 1 ) ) != 0 ) ;
V_52 = V_14 -> V_15 >> V_54 ;
V_50 = F_55 ( V_52 , sizeof( struct V_44 * ) ) ;
if ( V_50 == NULL )
return F_56 ( - V_8 ) ;
V_45 |= F_57 ( V_48 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_49 = F_58 ( V_48 , V_51 , V_45 ) ;
if ( F_12 ( V_49 ) )
goto V_55;
V_50 [ V_51 ] = V_49 ;
F_15 ( ( V_45 & V_56 ) &&
( F_59 ( V_49 ) >= 0x00100000UL ) ) ;
}
return V_50 ;
V_55:
while ( V_51 -- )
F_60 ( V_50 [ V_51 ] ) ;
F_61 ( V_50 ) ;
return F_62 ( V_49 ) ;
}
void F_63 ( struct V_13 * V_14 , struct V_44 * * V_50 ,
bool V_57 , bool V_58 )
{
int V_51 , V_52 ;
F_31 ( ( V_14 -> V_15 & ( V_19 - 1 ) ) != 0 ) ;
V_52 = V_14 -> V_15 >> V_54 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
if ( V_57 )
F_64 ( V_50 [ V_51 ] ) ;
if ( V_58 )
F_65 ( V_50 [ V_51 ] ) ;
F_60 ( V_50 [ V_51 ] ) ;
}
F_61 ( V_50 ) ;
}
struct V_13 *
F_66 ( struct V_1 * V_2 , struct V_26 * V_17 ,
T_2 V_33 )
{
struct V_13 * V_14 ;
F_34 ( & V_17 -> V_34 ) ;
V_14 = F_35 ( & V_17 -> V_35 , V_33 ) ;
if ( V_14 == NULL ) {
F_36 ( & V_17 -> V_34 ) ;
return NULL ;
}
F_44 ( V_14 ) ;
F_36 ( & V_17 -> V_34 ) ;
return V_14 ;
}
int
F_67 ( struct V_1 * V_2 , void * V_59 ,
struct V_26 * V_39 )
{
struct V_60 * args = V_59 ;
int V_41 ;
if ( ! ( V_2 -> V_23 -> V_61 & V_62 ) )
return - V_63 ;
V_41 = F_33 ( V_39 , args -> V_33 ) ;
return V_41 ;
}
int
F_68 ( struct V_1 * V_2 , void * V_59 ,
struct V_26 * V_39 )
{
struct V_64 * args = V_59 ;
struct V_13 * V_14 ;
int V_41 ;
if ( ! ( V_2 -> V_23 -> V_61 & V_62 ) )
return - V_63 ;
V_14 = F_66 ( V_2 , V_39 , args -> V_33 ) ;
if ( V_14 == NULL )
return - V_65 ;
F_20 ( & V_2 -> V_5 ) ;
F_42 ( V_7 ) ;
if ( V_14 -> V_21 == 0 ) {
V_41 = - V_65 ;
goto V_66;
}
if ( ! V_14 -> V_32 ) {
V_41 = F_43 ( & V_2 -> V_6 , V_14 , 1 , 0 , V_42 ) ;
if ( V_41 < 0 )
goto V_66;
V_14 -> V_32 = V_41 ;
F_44 ( V_14 ) ;
}
args -> V_32 = ( V_67 ) V_14 -> V_32 ;
V_41 = 0 ;
V_66:
F_45 () ;
F_22 ( & V_2 -> V_5 ) ;
F_32 ( V_14 ) ;
return V_41 ;
}
int
F_69 ( struct V_1 * V_2 , void * V_59 ,
struct V_26 * V_39 )
{
struct V_68 * args = V_59 ;
struct V_13 * V_14 ;
int V_41 ;
T_2 V_33 ;
if ( ! ( V_2 -> V_23 -> V_61 & V_62 ) )
return - V_63 ;
F_20 ( & V_2 -> V_5 ) ;
V_14 = F_35 ( & V_2 -> V_6 , ( int ) args -> V_32 ) ;
if ( V_14 ) {
F_44 ( V_14 ) ;
} else {
F_22 ( & V_2 -> V_5 ) ;
return - V_65 ;
}
V_41 = F_40 ( V_39 , V_14 , & V_33 ) ;
F_32 ( V_14 ) ;
if ( V_41 )
return V_41 ;
args -> V_33 = V_33 ;
args -> V_15 = V_14 -> V_15 ;
return 0 ;
}
void
V_68 ( struct V_1 * V_2 , struct V_26 * V_69 )
{
F_3 ( & V_69 -> V_35 ) ;
F_70 ( & V_69 -> V_34 ) ;
}
static int
F_71 ( int V_70 , void * V_71 , void * V_59 )
{
struct V_26 * V_39 = V_59 ;
struct V_13 * V_14 = V_71 ;
struct V_1 * V_2 = V_14 -> V_2 ;
if ( F_37 ( V_2 , V_37 ) )
F_19 ( V_14 , V_39 ) ;
F_38 ( & V_14 -> V_22 , V_39 -> V_17 ) ;
if ( V_2 -> V_23 -> V_38 )
V_2 -> V_23 -> V_38 ( V_14 , V_39 ) ;
F_30 ( V_14 ) ;
return 0 ;
}
void
F_72 ( struct V_1 * V_2 , struct V_26 * V_69 )
{
F_73 ( & V_69 -> V_35 ,
& F_71 , V_69 ) ;
F_74 ( & V_69 -> V_35 ) ;
}
void
F_75 ( struct V_13 * V_14 )
{
F_31 ( V_14 -> V_29 ) ;
if ( V_14 -> V_17 )
V_25 ( V_14 -> V_17 ) ;
}
void
F_76 ( struct V_30 * V_30 )
{
struct V_13 * V_14 = (struct V_13 * ) V_30 ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_15 ( ! F_41 ( & V_2 -> V_72 ) ) ;
if ( V_2 -> V_23 -> V_73 != NULL )
V_2 -> V_23 -> V_73 ( V_14 ) ;
}
void F_77 ( struct V_74 * V_75 )
{
struct V_13 * V_14 = V_75 -> V_76 ;
F_44 ( V_14 ) ;
F_20 ( & V_14 -> V_2 -> V_72 ) ;
F_78 ( V_14 -> V_2 , V_75 ) ;
F_22 ( & V_14 -> V_2 -> V_72 ) ;
}
void F_79 ( struct V_74 * V_75 )
{
struct V_13 * V_14 = V_75 -> V_76 ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_20 ( & V_2 -> V_72 ) ;
F_80 ( V_14 -> V_2 , V_75 ) ;
F_81 ( V_14 ) ;
F_22 ( & V_2 -> V_72 ) ;
}
int F_82 ( struct V_13 * V_14 , unsigned long V_77 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
F_83 ( & V_2 -> V_72 ) ;
if ( V_77 < V_75 -> V_78 - V_75 -> V_79 )
return - V_36 ;
if ( ! V_2 -> V_23 -> V_80 )
return - V_36 ;
V_75 -> V_81 |= V_82 | V_83 | V_84 | V_85 ;
V_75 -> V_86 = V_2 -> V_23 -> V_80 ;
V_75 -> V_76 = V_14 ;
V_75 -> V_87 = F_84 ( F_85 ( V_75 -> V_81 ) ) ;
F_44 ( V_14 ) ;
F_78 ( V_2 , V_75 ) ;
return 0 ;
}
int F_86 ( struct V_16 * V_17 , struct V_74 * V_75 )
{
struct V_26 * V_88 = V_17 -> V_89 ;
struct V_1 * V_2 = V_88 -> V_90 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_13 * V_14 ;
struct V_91 * V_92 ;
int V_41 = 0 ;
if ( F_87 ( V_2 ) )
return - V_63 ;
F_20 ( & V_2 -> V_72 ) ;
V_92 = F_88 ( & V_4 -> V_10 , V_75 -> V_93 ,
F_89 ( V_75 ) ) ;
if ( ! V_92 ) {
F_22 ( & V_2 -> V_72 ) ;
return F_90 ( V_17 , V_75 ) ;
} else if ( ! F_91 ( V_92 , V_17 ) ) {
F_22 ( & V_2 -> V_72 ) ;
return - V_94 ;
}
V_14 = F_92 ( V_92 , struct V_13 , V_22 ) ;
V_41 = F_82 ( V_14 , F_93 ( V_92 ) << V_54 , V_75 ) ;
F_22 ( & V_2 -> V_72 ) ;
return V_41 ;
}
