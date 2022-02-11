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
return F_16 ( V_15 -> V_18 ) ;
F_17 ( & V_15 -> V_20 ) ;
F_18 ( & V_15 -> V_21 , 0 ) ;
V_15 -> V_16 = V_16 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_14 * V_15 , T_1 V_16 )
{
F_13 ( ( V_16 & ( V_17 - 1 ) ) != 0 ) ;
V_15 -> V_2 = V_2 ;
V_15 -> V_18 = NULL ;
F_17 ( & V_15 -> V_20 ) ;
F_18 ( & V_15 -> V_21 , 0 ) ;
V_15 -> V_16 = V_16 ;
return 0 ;
}
struct V_14 *
F_20 ( struct V_1 * V_2 , T_1 V_16 )
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
static void
F_21 ( struct V_14 * V_15 , struct V_25 * V_18 )
{
if ( V_15 -> V_26 ) {
F_22 ( & V_18 -> V_27 ,
V_15 -> V_26 -> V_28 ) ;
}
if ( V_15 -> V_29 ) {
F_22 ( & V_18 -> V_27 ,
V_15 -> V_29 ) ;
}
}
int
F_23 ( struct V_25 * V_18 , T_2 V_30 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
F_24 ( & V_18 -> V_31 ) ;
V_15 = F_25 ( & V_18 -> V_32 , V_30 ) ;
if ( V_15 == NULL ) {
F_26 ( & V_18 -> V_31 ) ;
return - V_33 ;
}
V_2 = V_15 -> V_2 ;
F_27 ( & V_18 -> V_32 , V_30 ) ;
F_26 ( & V_18 -> V_31 ) ;
F_21 ( V_15 , V_18 ) ;
if ( V_2 -> V_22 -> V_34 )
V_2 -> V_22 -> V_34 ( V_15 , V_18 ) ;
F_28 ( V_15 ) ;
return 0 ;
}
int
F_29 ( struct V_25 * V_35 ,
struct V_14 * V_15 ,
T_2 * V_36 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
int V_37 ;
V_38:
if ( F_30 ( & V_35 -> V_32 , V_7 ) == 0 )
return - V_8 ;
F_24 ( & V_35 -> V_31 ) ;
V_37 = F_31 ( & V_35 -> V_32 , V_15 , 1 , ( int * ) V_36 ) ;
F_26 ( & V_35 -> V_31 ) ;
if ( V_37 == - V_39 )
goto V_38;
else if ( V_37 )
return V_37 ;
F_32 ( V_15 ) ;
if ( V_2 -> V_22 -> V_40 ) {
V_37 = V_2 -> V_22 -> V_40 ( V_15 , V_35 ) ;
if ( V_37 ) {
F_23 ( V_35 , * V_36 ) ;
return V_37 ;
}
}
return 0 ;
}
void
F_33 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_41 * V_42 = & V_15 -> V_43 ;
F_34 ( & V_4 -> V_10 , & V_42 -> V_44 ) ;
F_35 ( V_42 -> V_45 ) ;
F_7 ( V_42 -> V_46 ) ;
V_42 -> V_46 = NULL ;
}
int
F_36 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_41 * V_42 ;
struct V_47 * V_46 ;
int V_37 ;
V_42 = & V_15 -> V_43 ;
V_42 -> V_46 = F_4 ( sizeof( struct V_41 ) , V_7 ) ;
if ( ! V_42 -> V_46 )
return - V_8 ;
V_46 = V_42 -> V_46 ;
V_46 -> type = V_48 ;
V_46 -> V_16 = V_15 -> V_16 ;
V_46 -> V_30 = V_15 ;
V_42 -> V_45 = F_37 ( & V_4 -> V_11 ,
V_15 -> V_16 / V_17 , 0 , false ) ;
if ( ! V_42 -> V_45 ) {
F_5 ( L_3 , V_15 -> V_49 ) ;
V_37 = - V_50 ;
goto V_51;
}
V_42 -> V_45 = F_38 ( V_42 -> V_45 ,
V_15 -> V_16 / V_17 , 0 ) ;
if ( ! V_42 -> V_45 ) {
V_37 = - V_8 ;
goto V_51;
}
V_42 -> V_44 . V_52 = V_42 -> V_45 -> V_53 ;
V_37 = F_39 ( & V_4 -> V_10 , & V_42 -> V_44 ) ;
if ( V_37 ) {
F_5 ( L_4 ) ;
goto V_54;
}
return 0 ;
V_54:
F_35 ( V_42 -> V_45 ) ;
V_51:
F_7 ( V_42 -> V_46 ) ;
V_42 -> V_46 = NULL ;
return V_37 ;
}
struct V_14 *
F_40 ( struct V_1 * V_2 , struct V_25 * V_18 ,
T_2 V_30 )
{
struct V_14 * V_15 ;
F_24 ( & V_18 -> V_31 ) ;
V_15 = F_25 ( & V_18 -> V_32 , V_30 ) ;
if ( V_15 == NULL ) {
F_26 ( & V_18 -> V_31 ) ;
return NULL ;
}
F_41 ( V_15 ) ;
F_26 ( & V_18 -> V_31 ) ;
return V_15 ;
}
int
F_42 ( struct V_1 * V_2 , void * V_55 ,
struct V_25 * V_35 )
{
struct V_56 * args = V_55 ;
int V_37 ;
if ( ! ( V_2 -> V_22 -> V_57 & V_58 ) )
return - V_59 ;
V_37 = F_23 ( V_35 , args -> V_30 ) ;
return V_37 ;
}
int
F_43 ( struct V_1 * V_2 , void * V_55 ,
struct V_25 * V_35 )
{
struct V_60 * args = V_55 ;
struct V_14 * V_15 ;
int V_37 ;
if ( ! ( V_2 -> V_22 -> V_57 & V_58 ) )
return - V_59 ;
V_15 = F_40 ( V_2 , V_35 , args -> V_30 ) ;
if ( V_15 == NULL )
return - V_61 ;
V_38:
if ( F_30 ( & V_2 -> V_6 , V_7 ) == 0 ) {
V_37 = - V_8 ;
goto V_62;
}
F_24 ( & V_2 -> V_5 ) ;
if ( ! V_15 -> V_49 ) {
V_37 = F_31 ( & V_2 -> V_6 , V_15 , 1 ,
& V_15 -> V_49 ) ;
args -> V_49 = ( V_63 ) V_15 -> V_49 ;
F_26 ( & V_2 -> V_5 ) ;
if ( V_37 == - V_39 )
goto V_38;
else if ( V_37 )
goto V_62;
F_41 ( V_15 ) ;
} else {
args -> V_49 = ( V_63 ) V_15 -> V_49 ;
F_26 ( & V_2 -> V_5 ) ;
V_37 = 0 ;
}
V_62:
F_44 ( V_15 ) ;
return V_37 ;
}
int
F_45 ( struct V_1 * V_2 , void * V_55 ,
struct V_25 * V_35 )
{
struct V_64 * args = V_55 ;
struct V_14 * V_15 ;
int V_37 ;
T_2 V_30 ;
if ( ! ( V_2 -> V_22 -> V_57 & V_58 ) )
return - V_59 ;
F_24 ( & V_2 -> V_5 ) ;
V_15 = F_25 ( & V_2 -> V_6 , ( int ) args -> V_49 ) ;
if ( V_15 )
F_41 ( V_15 ) ;
F_26 ( & V_2 -> V_5 ) ;
if ( ! V_15 )
return - V_61 ;
V_37 = F_29 ( V_35 , V_15 , & V_30 ) ;
F_44 ( V_15 ) ;
if ( V_37 )
return V_37 ;
args -> V_30 = V_30 ;
args -> V_16 = V_15 -> V_16 ;
return 0 ;
}
void
V_64 ( struct V_1 * V_2 , struct V_25 * V_65 )
{
F_3 ( & V_65 -> V_32 ) ;
F_2 ( & V_65 -> V_31 ) ;
}
static int
F_46 ( int V_66 , void * V_67 , void * V_55 )
{
struct V_25 * V_35 = V_55 ;
struct V_14 * V_15 = V_67 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_21 ( V_15 , V_35 ) ;
if ( V_2 -> V_22 -> V_34 )
V_2 -> V_22 -> V_34 ( V_15 , V_35 ) ;
F_28 ( V_15 ) ;
return 0 ;
}
void
F_47 ( struct V_1 * V_2 , struct V_25 * V_65 )
{
F_48 ( & V_65 -> V_32 ,
& F_46 , V_65 ) ;
F_49 ( & V_65 -> V_32 ) ;
F_50 ( & V_65 -> V_32 ) ;
}
void
F_51 ( struct V_14 * V_15 )
{
if ( V_15 -> V_18 )
V_24 ( V_15 -> V_18 ) ;
}
void
F_52 ( struct V_68 * V_68 )
{
struct V_14 * V_15 = (struct V_14 * ) V_68 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_13 ( ! F_53 ( & V_2 -> V_69 ) ) ;
if ( V_2 -> V_22 -> V_70 != NULL )
V_2 -> V_22 -> V_70 ( V_15 ) ;
}
static void F_54 ( struct V_68 * V_71 )
{
F_55 () ;
}
void F_56 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
F_24 ( & V_2 -> V_5 ) ;
if ( V_15 -> V_49 ) {
F_27 ( & V_2 -> V_6 , V_15 -> V_49 ) ;
V_15 -> V_49 = 0 ;
F_26 ( & V_2 -> V_5 ) ;
F_57 ( & V_15 -> V_20 , F_54 ) ;
} else
F_26 ( & V_2 -> V_5 ) ;
}
void F_58 ( struct V_72 * V_73 )
{
struct V_14 * V_15 = V_73 -> V_74 ;
F_41 ( V_15 ) ;
F_59 ( & V_15 -> V_2 -> V_69 ) ;
F_60 ( V_15 -> V_2 , V_73 ) ;
F_61 ( & V_15 -> V_2 -> V_69 ) ;
}
void F_62 ( struct V_72 * V_73 )
{
struct V_14 * V_15 = V_73 -> V_74 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_59 ( & V_2 -> V_69 ) ;
F_63 ( V_15 -> V_2 , V_73 ) ;
F_64 ( V_15 ) ;
F_61 ( & V_2 -> V_69 ) ;
}
int F_65 ( struct V_75 * V_18 , struct V_72 * V_73 )
{
struct V_25 * V_76 = V_18 -> V_77 ;
struct V_1 * V_2 = V_76 -> V_78 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_47 * V_46 = NULL ;
struct V_14 * V_15 ;
struct V_79 * V_44 ;
int V_37 = 0 ;
if ( F_66 ( V_2 ) )
return - V_59 ;
F_59 ( & V_2 -> V_69 ) ;
if ( F_67 ( & V_4 -> V_10 , V_73 -> V_80 , & V_44 ) ) {
F_61 ( & V_2 -> V_69 ) ;
return F_68 ( V_18 , V_73 ) ;
}
V_46 = F_69 ( V_44 , struct V_41 , V_44 ) -> V_46 ;
if ( ! V_46 ||
( ( V_46 -> V_81 & V_82 ) && ! F_70 ( V_83 ) ) ) {
V_37 = - V_84 ;
goto V_85;
}
if ( V_46 -> V_16 < V_73 -> V_86 - V_73 -> V_87 ) {
V_37 = - V_33 ;
goto V_85;
}
V_15 = V_46 -> V_30 ;
if ( ! V_15 -> V_2 -> V_22 -> V_88 ) {
V_37 = - V_33 ;
goto V_85;
}
V_73 -> V_89 |= V_90 | V_91 | V_92 | V_93 ;
V_73 -> V_94 = V_15 -> V_2 -> V_22 -> V_88 ;
V_73 -> V_74 = V_46 -> V_30 ;
V_73 -> V_95 = F_71 ( F_72 ( V_73 -> V_89 ) ) ;
F_41 ( V_15 ) ;
F_60 ( V_2 , V_73 ) ;
V_85:
F_61 ( & V_2 -> V_69 ) ;
return V_37 ;
}
