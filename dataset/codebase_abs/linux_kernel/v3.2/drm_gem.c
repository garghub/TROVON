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
void
F_30 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_37 * V_38 = & V_15 -> V_39 ;
F_31 ( & V_4 -> V_10 , & V_38 -> V_40 ) ;
F_32 ( V_38 -> V_41 ) ;
F_7 ( V_38 -> V_42 ) ;
V_38 -> V_42 = NULL ;
}
int
F_33 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_37 * V_38 ;
struct V_43 * V_42 ;
int V_33 = 0 ;
V_38 = & V_15 -> V_39 ;
V_38 -> V_42 = F_4 ( sizeof( struct V_37 ) , V_7 ) ;
if ( ! V_38 -> V_42 )
return - V_8 ;
V_42 = V_38 -> V_42 ;
V_42 -> type = V_44 ;
V_42 -> V_16 = V_15 -> V_16 ;
V_42 -> V_26 = V_15 ;
V_38 -> V_41 = F_34 ( & V_4 -> V_11 ,
V_15 -> V_16 / V_17 , 0 , 0 ) ;
if ( ! V_38 -> V_41 ) {
F_5 ( L_3 , V_15 -> V_45 ) ;
V_33 = - V_46 ;
goto V_47;
}
V_38 -> V_41 = F_35 ( V_38 -> V_41 ,
V_15 -> V_16 / V_17 , 0 ) ;
if ( ! V_38 -> V_41 ) {
V_33 = - V_8 ;
goto V_47;
}
V_38 -> V_40 . V_48 = V_38 -> V_41 -> V_49 ;
V_33 = F_36 ( & V_4 -> V_10 , & V_38 -> V_40 ) ;
if ( V_33 ) {
F_5 ( L_4 ) ;
goto V_50;
}
return 0 ;
V_50:
F_32 ( V_38 -> V_41 ) ;
V_47:
F_7 ( V_38 -> V_42 ) ;
V_38 -> V_42 = NULL ;
return V_33 ;
}
struct V_14 *
F_37 ( struct V_1 * V_2 , struct V_25 * V_18 ,
T_2 V_26 )
{
struct V_14 * V_15 ;
F_21 ( & V_18 -> V_27 ) ;
V_15 = F_22 ( & V_18 -> V_28 , V_26 ) ;
if ( V_15 == NULL ) {
F_23 ( & V_18 -> V_27 ) ;
return NULL ;
}
F_38 ( V_15 ) ;
F_23 ( & V_18 -> V_27 ) ;
return V_15 ;
}
int
F_39 ( struct V_1 * V_2 , void * V_51 ,
struct V_25 * V_31 )
{
struct V_52 * args = V_51 ;
int V_33 ;
if ( ! ( V_2 -> V_22 -> V_53 & V_54 ) )
return - V_55 ;
V_33 = F_20 ( V_31 , args -> V_26 ) ;
return V_33 ;
}
int
F_40 ( struct V_1 * V_2 , void * V_51 ,
struct V_25 * V_31 )
{
struct V_56 * args = V_51 ;
struct V_14 * V_15 ;
int V_33 ;
if ( ! ( V_2 -> V_22 -> V_53 & V_54 ) )
return - V_55 ;
V_15 = F_37 ( V_2 , V_31 , args -> V_26 ) ;
if ( V_15 == NULL )
return - V_57 ;
V_34:
if ( F_27 ( & V_2 -> V_6 , V_7 ) == 0 ) {
V_33 = - V_8 ;
goto V_58;
}
F_21 ( & V_2 -> V_5 ) ;
if ( ! V_15 -> V_45 ) {
V_33 = F_28 ( & V_2 -> V_6 , V_15 , 1 ,
& V_15 -> V_45 ) ;
args -> V_45 = ( V_59 ) V_15 -> V_45 ;
F_23 ( & V_2 -> V_5 ) ;
if ( V_33 == - V_35 )
goto V_34;
if ( V_33 != 0 )
goto V_58;
F_38 ( V_15 ) ;
} else {
args -> V_45 = ( V_59 ) V_15 -> V_45 ;
F_23 ( & V_2 -> V_5 ) ;
V_33 = 0 ;
}
V_58:
F_41 ( V_15 ) ;
return V_33 ;
}
int
F_42 ( struct V_1 * V_2 , void * V_51 ,
struct V_25 * V_31 )
{
struct V_60 * args = V_51 ;
struct V_14 * V_15 ;
int V_33 ;
T_2 V_26 ;
if ( ! ( V_2 -> V_22 -> V_53 & V_54 ) )
return - V_55 ;
F_21 ( & V_2 -> V_5 ) ;
V_15 = F_22 ( & V_2 -> V_6 , ( int ) args -> V_45 ) ;
if ( V_15 )
F_38 ( V_15 ) ;
F_23 ( & V_2 -> V_5 ) ;
if ( ! V_15 )
return - V_57 ;
V_33 = F_26 ( V_31 , V_15 , & V_26 ) ;
F_41 ( V_15 ) ;
if ( V_33 )
return V_33 ;
args -> V_26 = V_26 ;
args -> V_16 = V_15 -> V_16 ;
return 0 ;
}
void
V_60 ( struct V_1 * V_2 , struct V_25 * V_61 )
{
F_3 ( & V_61 -> V_28 ) ;
F_2 ( & V_61 -> V_27 ) ;
}
static int
F_43 ( int V_62 , void * V_63 , void * V_51 )
{
struct V_25 * V_31 = V_51 ;
struct V_14 * V_15 = V_63 ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( V_2 -> V_22 -> V_30 )
V_2 -> V_22 -> V_30 ( V_15 , V_31 ) ;
F_25 ( V_15 ) ;
return 0 ;
}
void
F_44 ( struct V_1 * V_2 , struct V_25 * V_61 )
{
F_45 ( & V_61 -> V_28 ,
& F_43 , V_61 ) ;
F_46 ( & V_61 -> V_28 ) ;
F_47 ( & V_61 -> V_28 ) ;
}
void
F_48 ( struct V_14 * V_15 )
{
if ( V_15 -> V_18 )
V_24 ( V_15 -> V_18 ) ;
}
void
F_49 ( struct V_64 * V_64 )
{
struct V_14 * V_15 = (struct V_14 * ) V_64 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_13 ( ! F_50 ( & V_2 -> V_65 ) ) ;
if ( V_2 -> V_22 -> V_66 != NULL )
V_2 -> V_22 -> V_66 ( V_15 ) ;
}
static void F_51 ( struct V_64 * V_67 )
{
F_52 () ;
}
void F_53 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
F_21 ( & V_2 -> V_5 ) ;
if ( V_15 -> V_45 ) {
F_24 ( & V_2 -> V_6 , V_15 -> V_45 ) ;
V_15 -> V_45 = 0 ;
F_23 ( & V_2 -> V_5 ) ;
F_54 ( & V_15 -> V_20 , F_51 ) ;
} else
F_23 ( & V_2 -> V_5 ) ;
}
void F_55 ( struct V_68 * V_69 )
{
struct V_14 * V_15 = V_69 -> V_70 ;
F_38 ( V_15 ) ;
F_56 ( & V_15 -> V_2 -> V_65 ) ;
F_57 ( V_69 ) ;
F_58 ( & V_15 -> V_2 -> V_65 ) ;
}
void F_59 ( struct V_68 * V_69 )
{
struct V_14 * V_15 = V_69 -> V_70 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_56 ( & V_2 -> V_65 ) ;
F_60 ( V_69 ) ;
F_61 ( V_15 ) ;
F_58 ( & V_2 -> V_65 ) ;
}
int F_62 ( struct V_71 * V_18 , struct V_68 * V_69 )
{
struct V_25 * V_72 = V_18 -> V_73 ;
struct V_1 * V_2 = V_72 -> V_74 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_43 * V_42 = NULL ;
struct V_14 * V_15 ;
struct V_75 * V_40 ;
int V_33 = 0 ;
F_56 ( & V_2 -> V_65 ) ;
if ( F_63 ( & V_4 -> V_10 , V_69 -> V_76 , & V_40 ) ) {
F_58 ( & V_2 -> V_65 ) ;
return F_64 ( V_18 , V_69 ) ;
}
V_42 = F_65 ( V_40 , struct V_37 , V_40 ) -> V_42 ;
if ( ! V_42 ||
( ( V_42 -> V_77 & V_78 ) && ! F_66 ( V_79 ) ) ) {
V_33 = - V_80 ;
goto V_81;
}
if ( V_42 -> V_16 < V_69 -> V_82 - V_69 -> V_83 ) {
V_33 = - V_29 ;
goto V_81;
}
V_15 = V_42 -> V_26 ;
if ( ! V_15 -> V_2 -> V_22 -> V_84 ) {
V_33 = - V_29 ;
goto V_81;
}
V_69 -> V_85 |= V_86 | V_87 | V_88 | V_89 ;
V_69 -> V_90 = V_15 -> V_2 -> V_22 -> V_84 ;
V_69 -> V_70 = V_42 -> V_26 ;
V_69 -> V_91 = F_67 ( F_68 ( V_69 -> V_85 ) ) ;
F_38 ( V_15 ) ;
V_69 -> V_92 = V_18 ;
F_57 ( V_69 ) ;
V_81:
F_58 ( & V_2 -> V_65 ) ;
return V_33 ;
}
