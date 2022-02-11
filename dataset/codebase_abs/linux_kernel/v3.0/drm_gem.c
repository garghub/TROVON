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
struct V_14 *
F_18 ( struct V_1 * V_2 , T_1 V_16 )
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
F_19 ( struct V_25 * V_18 , T_2 V_26 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
F_20 ( & V_18 -> V_27 ) ;
V_15 = F_21 ( & V_18 -> V_28 , V_26 ) ;
if ( V_15 == NULL ) {
F_22 ( & V_18 -> V_27 ) ;
return - V_29 ;
}
V_2 = V_15 -> V_2 ;
F_23 ( & V_18 -> V_28 , V_26 ) ;
F_22 ( & V_18 -> V_27 ) ;
F_24 ( V_15 ) ;
return 0 ;
}
int
F_25 ( struct V_25 * V_30 ,
struct V_14 * V_15 ,
T_2 * V_31 )
{
int V_32 ;
V_33:
if ( F_26 ( & V_30 -> V_28 , V_7 ) == 0 )
return - V_8 ;
F_20 ( & V_30 -> V_27 ) ;
V_32 = F_27 ( & V_30 -> V_28 , V_15 , 1 , ( int * ) V_31 ) ;
F_22 ( & V_30 -> V_27 ) ;
if ( V_32 == - V_34 )
goto V_33;
if ( V_32 != 0 )
return V_32 ;
F_28 ( V_15 ) ;
return 0 ;
}
struct V_14 *
F_29 ( struct V_1 * V_2 , struct V_25 * V_18 ,
T_2 V_26 )
{
struct V_14 * V_15 ;
F_20 ( & V_18 -> V_27 ) ;
V_15 = F_21 ( & V_18 -> V_28 , V_26 ) ;
if ( V_15 == NULL ) {
F_22 ( & V_18 -> V_27 ) ;
return NULL ;
}
F_30 ( V_15 ) ;
F_22 ( & V_18 -> V_27 ) ;
return V_15 ;
}
int
F_31 ( struct V_1 * V_2 , void * V_35 ,
struct V_25 * V_30 )
{
struct V_36 * args = V_35 ;
int V_32 ;
if ( ! ( V_2 -> V_22 -> V_37 & V_38 ) )
return - V_39 ;
V_32 = F_19 ( V_30 , args -> V_26 ) ;
return V_32 ;
}
int
F_32 ( struct V_1 * V_2 , void * V_35 ,
struct V_25 * V_30 )
{
struct V_40 * args = V_35 ;
struct V_14 * V_15 ;
int V_32 ;
if ( ! ( V_2 -> V_22 -> V_37 & V_38 ) )
return - V_39 ;
V_15 = F_29 ( V_2 , V_30 , args -> V_26 ) ;
if ( V_15 == NULL )
return - V_41 ;
V_33:
if ( F_26 ( & V_2 -> V_6 , V_7 ) == 0 ) {
V_32 = - V_8 ;
goto V_42;
}
F_20 ( & V_2 -> V_5 ) ;
if ( ! V_15 -> V_43 ) {
V_32 = F_27 ( & V_2 -> V_6 , V_15 , 1 ,
& V_15 -> V_43 ) ;
args -> V_43 = ( V_44 ) V_15 -> V_43 ;
F_22 ( & V_2 -> V_5 ) ;
if ( V_32 == - V_34 )
goto V_33;
if ( V_32 != 0 )
goto V_42;
F_30 ( V_15 ) ;
} else {
args -> V_43 = ( V_44 ) V_15 -> V_43 ;
F_22 ( & V_2 -> V_5 ) ;
V_32 = 0 ;
}
V_42:
F_33 ( V_15 ) ;
return V_32 ;
}
int
F_34 ( struct V_1 * V_2 , void * V_35 ,
struct V_25 * V_30 )
{
struct V_45 * args = V_35 ;
struct V_14 * V_15 ;
int V_32 ;
T_2 V_26 ;
if ( ! ( V_2 -> V_22 -> V_37 & V_38 ) )
return - V_39 ;
F_20 ( & V_2 -> V_5 ) ;
V_15 = F_21 ( & V_2 -> V_6 , ( int ) args -> V_43 ) ;
if ( V_15 )
F_30 ( V_15 ) ;
F_22 ( & V_2 -> V_5 ) ;
if ( ! V_15 )
return - V_41 ;
V_32 = F_25 ( V_30 , V_15 , & V_26 ) ;
F_33 ( V_15 ) ;
if ( V_32 )
return V_32 ;
args -> V_26 = V_26 ;
args -> V_16 = V_15 -> V_16 ;
return 0 ;
}
void
V_45 ( struct V_1 * V_2 , struct V_25 * V_46 )
{
F_3 ( & V_46 -> V_28 ) ;
F_2 ( & V_46 -> V_27 ) ;
}
static int
F_35 ( int V_47 , void * V_48 , void * V_35 )
{
struct V_14 * V_15 = V_48 ;
F_24 ( V_15 ) ;
return 0 ;
}
void
F_36 ( struct V_1 * V_2 , struct V_25 * V_46 )
{
F_37 ( & V_46 -> V_28 ,
& F_35 , NULL ) ;
F_38 ( & V_46 -> V_28 ) ;
F_39 ( & V_46 -> V_28 ) ;
}
void
F_40 ( struct V_14 * V_15 )
{
V_24 ( V_15 -> V_18 ) ;
}
void
F_41 ( struct V_49 * V_49 )
{
struct V_14 * V_15 = (struct V_14 * ) V_49 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_13 ( ! F_42 ( & V_2 -> V_50 ) ) ;
if ( V_2 -> V_22 -> V_51 != NULL )
V_2 -> V_22 -> V_51 ( V_15 ) ;
}
static void F_43 ( struct V_49 * V_52 )
{
F_44 () ;
}
void F_45 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
F_20 ( & V_2 -> V_5 ) ;
if ( V_15 -> V_43 ) {
F_23 ( & V_2 -> V_6 , V_15 -> V_43 ) ;
V_15 -> V_43 = 0 ;
F_22 ( & V_2 -> V_5 ) ;
F_46 ( & V_15 -> V_20 , F_43 ) ;
} else
F_22 ( & V_2 -> V_5 ) ;
}
void F_47 ( struct V_53 * V_54 )
{
struct V_14 * V_15 = V_54 -> V_55 ;
F_30 ( V_15 ) ;
F_48 ( & V_15 -> V_2 -> V_50 ) ;
F_49 ( V_54 ) ;
F_50 ( & V_15 -> V_2 -> V_50 ) ;
}
void F_51 ( struct V_53 * V_54 )
{
struct V_14 * V_15 = V_54 -> V_55 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_48 ( & V_2 -> V_50 ) ;
F_52 ( V_54 ) ;
F_53 ( V_15 ) ;
F_50 ( & V_2 -> V_50 ) ;
}
int F_54 ( struct V_56 * V_18 , struct V_53 * V_54 )
{
struct V_25 * V_57 = V_18 -> V_58 ;
struct V_1 * V_2 = V_57 -> V_59 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_60 * V_61 = NULL ;
struct V_14 * V_15 ;
struct V_62 * V_63 ;
int V_32 = 0 ;
F_48 ( & V_2 -> V_50 ) ;
if ( F_55 ( & V_4 -> V_10 , V_54 -> V_64 , & V_63 ) ) {
F_50 ( & V_2 -> V_50 ) ;
return F_56 ( V_18 , V_54 ) ;
}
V_61 = F_57 ( V_63 , struct V_65 , V_63 ) -> V_61 ;
if ( ! V_61 ||
( ( V_61 -> V_66 & V_67 ) && ! F_58 ( V_68 ) ) ) {
V_32 = - V_69 ;
goto V_70;
}
if ( V_61 -> V_16 < V_54 -> V_71 - V_54 -> V_72 ) {
V_32 = - V_29 ;
goto V_70;
}
V_15 = V_61 -> V_26 ;
if ( ! V_15 -> V_2 -> V_22 -> V_73 ) {
V_32 = - V_29 ;
goto V_70;
}
V_54 -> V_74 |= V_75 | V_76 | V_77 | V_78 ;
V_54 -> V_79 = V_15 -> V_2 -> V_22 -> V_73 ;
V_54 -> V_55 = V_61 -> V_26 ;
V_54 -> V_80 = F_59 ( F_60 ( V_54 -> V_74 ) ) ;
F_30 ( V_15 ) ;
V_54 -> V_81 = V_18 ;
F_49 ( V_54 ) ;
V_70:
F_50 ( & V_2 -> V_50 ) ;
return V_32 ;
}
