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
if ( F_6 ( & V_4 -> V_10 , 12 ) ) {
F_7 ( V_4 ) ;
return - V_8 ;
}
if ( F_8 ( & V_4 -> V_11 , V_12 ,
V_13 ) ) {
F_9 ( & V_4 -> V_10 ) ;
F_7 ( V_4 ) ;
return - V_8 ;
}
return 0 ;
}
void
F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
F_11 ( & V_4 -> V_11 ) ;
F_9 ( & V_4 -> V_10 ) ;
F_7 ( V_4 ) ;
V_2 -> V_9 = NULL ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_14 * V_15 , T_1 V_16 )
{
F_13 ( ( V_16 & ( V_17 - 1 ) ) != 0 ) ;
V_15 -> V_2 = V_2 ;
V_15 -> V_18 = F_14 ( L_2 , V_16 , V_19 ) ;
if ( F_15 ( V_15 -> V_18 ) )
return - V_8 ;
F_16 ( & V_15 -> V_20 ) ;
F_17 ( & V_15 -> V_21 , 0 ) ;
V_15 -> V_16 = V_16 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_14 * V_15 , T_1 V_16 )
{
F_13 ( ( V_16 & ( V_17 - 1 ) ) != 0 ) ;
V_15 -> V_2 = V_2 ;
V_15 -> V_18 = NULL ;
F_16 ( & V_15 -> V_20 ) ;
F_17 ( & V_15 -> V_21 , 0 ) ;
V_15 -> V_16 = V_16 ;
return 0 ;
}
struct V_14 *
F_19 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_14 * V_15 ;
V_15 = F_4 ( sizeof( * V_15 ) , V_7 ) ;
if ( ! V_15 )
goto free;
if ( F_12 ( V_2 , V_15 , V_16 ) != 0 )
goto free;
if ( V_2 -> V_22 -> V_23 != NULL &&
V_2 -> V_22 -> V_23 ( V_15 ) != 0 ) {
goto V_24;
}
return V_15 ;
V_24:
V_24 ( V_15 -> V_18 ) ;
free:
F_7 ( V_15 ) ;
return NULL ;
}
int
F_20 ( struct V_25 * V_18 , T_2 V_26 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
F_21 ( & V_18 -> V_27 ) ;
V_15 = F_22 ( & V_18 -> V_28 , V_26 ) ;
if ( V_15 == NULL ) {
F_23 ( & V_18 -> V_27 ) ;
return - V_29 ;
}
V_2 = V_15 -> V_2 ;
F_24 ( & V_18 -> V_28 , V_26 ) ;
F_23 ( & V_18 -> V_27 ) ;
if ( V_2 -> V_22 -> V_30 )
V_2 -> V_22 -> V_30 ( V_15 , V_18 ) ;
F_25 ( V_15 ) ;
return 0 ;
}
int
F_26 ( struct V_25 * V_31 ,
struct V_14 * V_15 ,
T_2 * V_32 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
int V_33 ;
V_34:
if ( F_27 ( & V_31 -> V_28 , V_7 ) == 0 )
return - V_8 ;
F_21 ( & V_31 -> V_27 ) ;
V_33 = F_28 ( & V_31 -> V_28 , V_15 , 1 , ( int * ) V_32 ) ;
F_23 ( & V_31 -> V_27 ) ;
if ( V_33 == - V_35 )
goto V_34;
if ( V_33 != 0 )
return V_33 ;
F_29 ( V_15 ) ;
if ( V_2 -> V_22 -> V_36 ) {
V_33 = V_2 -> V_22 -> V_36 ( V_15 , V_31 ) ;
if ( V_33 ) {
F_20 ( V_31 , * V_32 ) ;
return V_33 ;
}
}
return 0 ;
}
struct V_14 *
F_30 ( struct V_1 * V_2 , struct V_25 * V_18 ,
T_2 V_26 )
{
struct V_14 * V_15 ;
F_21 ( & V_18 -> V_27 ) ;
V_15 = F_22 ( & V_18 -> V_28 , V_26 ) ;
if ( V_15 == NULL ) {
F_23 ( & V_18 -> V_27 ) ;
return NULL ;
}
F_31 ( V_15 ) ;
F_23 ( & V_18 -> V_27 ) ;
return V_15 ;
}
int
F_32 ( struct V_1 * V_2 , void * V_37 ,
struct V_25 * V_31 )
{
struct V_38 * args = V_37 ;
int V_33 ;
if ( ! ( V_2 -> V_22 -> V_39 & V_40 ) )
return - V_41 ;
V_33 = F_20 ( V_31 , args -> V_26 ) ;
return V_33 ;
}
int
F_33 ( struct V_1 * V_2 , void * V_37 ,
struct V_25 * V_31 )
{
struct V_42 * args = V_37 ;
struct V_14 * V_15 ;
int V_33 ;
if ( ! ( V_2 -> V_22 -> V_39 & V_40 ) )
return - V_41 ;
V_15 = F_30 ( V_2 , V_31 , args -> V_26 ) ;
if ( V_15 == NULL )
return - V_43 ;
V_34:
if ( F_27 ( & V_2 -> V_6 , V_7 ) == 0 ) {
V_33 = - V_8 ;
goto V_44;
}
F_21 ( & V_2 -> V_5 ) ;
if ( ! V_15 -> V_45 ) {
V_33 = F_28 ( & V_2 -> V_6 , V_15 , 1 ,
& V_15 -> V_45 ) ;
args -> V_45 = ( V_46 ) V_15 -> V_45 ;
F_23 ( & V_2 -> V_5 ) ;
if ( V_33 == - V_35 )
goto V_34;
if ( V_33 != 0 )
goto V_44;
F_31 ( V_15 ) ;
} else {
args -> V_45 = ( V_46 ) V_15 -> V_45 ;
F_23 ( & V_2 -> V_5 ) ;
V_33 = 0 ;
}
V_44:
F_34 ( V_15 ) ;
return V_33 ;
}
int
F_35 ( struct V_1 * V_2 , void * V_37 ,
struct V_25 * V_31 )
{
struct V_47 * args = V_37 ;
struct V_14 * V_15 ;
int V_33 ;
T_2 V_26 ;
if ( ! ( V_2 -> V_22 -> V_39 & V_40 ) )
return - V_41 ;
F_21 ( & V_2 -> V_5 ) ;
V_15 = F_22 ( & V_2 -> V_6 , ( int ) args -> V_45 ) ;
if ( V_15 )
F_31 ( V_15 ) ;
F_23 ( & V_2 -> V_5 ) ;
if ( ! V_15 )
return - V_43 ;
V_33 = F_26 ( V_31 , V_15 , & V_26 ) ;
F_34 ( V_15 ) ;
if ( V_33 )
return V_33 ;
args -> V_26 = V_26 ;
args -> V_16 = V_15 -> V_16 ;
return 0 ;
}
void
V_47 ( struct V_1 * V_2 , struct V_25 * V_48 )
{
F_3 ( & V_48 -> V_28 ) ;
F_2 ( & V_48 -> V_27 ) ;
}
static int
F_36 ( int V_49 , void * V_50 , void * V_37 )
{
struct V_25 * V_31 = V_37 ;
struct V_14 * V_15 = V_50 ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( V_2 -> V_22 -> V_30 )
V_2 -> V_22 -> V_30 ( V_15 , V_31 ) ;
F_25 ( V_15 ) ;
return 0 ;
}
void
F_37 ( struct V_1 * V_2 , struct V_25 * V_48 )
{
F_38 ( & V_48 -> V_28 ,
& F_36 , V_48 ) ;
F_39 ( & V_48 -> V_28 ) ;
F_40 ( & V_48 -> V_28 ) ;
}
void
F_41 ( struct V_14 * V_15 )
{
if ( V_15 -> V_18 )
V_24 ( V_15 -> V_18 ) ;
}
void
F_42 ( struct V_51 * V_51 )
{
struct V_14 * V_15 = (struct V_14 * ) V_51 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_13 ( ! F_43 ( & V_2 -> V_52 ) ) ;
if ( V_2 -> V_22 -> V_53 != NULL )
V_2 -> V_22 -> V_53 ( V_15 ) ;
}
static void F_44 ( struct V_51 * V_54 )
{
F_45 () ;
}
void F_46 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
F_21 ( & V_2 -> V_5 ) ;
if ( V_15 -> V_45 ) {
F_24 ( & V_2 -> V_6 , V_15 -> V_45 ) ;
V_15 -> V_45 = 0 ;
F_23 ( & V_2 -> V_5 ) ;
F_47 ( & V_15 -> V_20 , F_44 ) ;
} else
F_23 ( & V_2 -> V_5 ) ;
}
void F_48 ( struct V_55 * V_56 )
{
struct V_14 * V_15 = V_56 -> V_57 ;
F_31 ( V_15 ) ;
F_49 ( & V_15 -> V_2 -> V_52 ) ;
F_50 ( V_56 ) ;
F_51 ( & V_15 -> V_2 -> V_52 ) ;
}
void F_52 ( struct V_55 * V_56 )
{
struct V_14 * V_15 = V_56 -> V_57 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_49 ( & V_2 -> V_52 ) ;
F_53 ( V_56 ) ;
F_54 ( V_15 ) ;
F_51 ( & V_2 -> V_52 ) ;
}
int F_55 ( struct V_58 * V_18 , struct V_55 * V_56 )
{
struct V_25 * V_59 = V_18 -> V_60 ;
struct V_1 * V_2 = V_59 -> V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_62 * V_63 = NULL ;
struct V_14 * V_15 ;
struct V_64 * V_65 ;
int V_33 = 0 ;
F_49 ( & V_2 -> V_52 ) ;
if ( F_56 ( & V_4 -> V_10 , V_56 -> V_66 , & V_65 ) ) {
F_51 ( & V_2 -> V_52 ) ;
return F_57 ( V_18 , V_56 ) ;
}
V_63 = F_58 ( V_65 , struct V_67 , V_65 ) -> V_63 ;
if ( ! V_63 ||
( ( V_63 -> V_68 & V_69 ) && ! F_59 ( V_70 ) ) ) {
V_33 = - V_71 ;
goto V_72;
}
if ( V_63 -> V_16 < V_56 -> V_73 - V_56 -> V_74 ) {
V_33 = - V_29 ;
goto V_72;
}
V_15 = V_63 -> V_26 ;
if ( ! V_15 -> V_2 -> V_22 -> V_75 ) {
V_33 = - V_29 ;
goto V_72;
}
V_56 -> V_76 |= V_77 | V_78 | V_79 | V_80 ;
V_56 -> V_81 = V_15 -> V_2 -> V_22 -> V_75 ;
V_56 -> V_57 = V_63 -> V_26 ;
V_56 -> V_82 = F_60 ( F_61 ( V_56 -> V_76 ) ) ;
F_31 ( V_15 ) ;
V_56 -> V_83 = V_18 ;
F_50 ( V_56 ) ;
V_72:
F_51 ( & V_2 -> V_52 ) ;
return V_33 ;
}
