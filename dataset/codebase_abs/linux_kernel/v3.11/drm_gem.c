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
F_8 ( & V_4 -> V_11 , V_12 ,
V_13 ) ;
return 0 ;
}
void
F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
F_10 ( & V_4 -> V_11 ) ;
F_11 ( & V_4 -> V_10 ) ;
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
F_30 ( V_7 ) ;
F_24 ( & V_35 -> V_31 ) ;
V_37 = F_31 ( & V_35 -> V_32 , V_15 , 1 , 0 , V_38 ) ;
F_26 ( & V_35 -> V_31 ) ;
F_32 () ;
if ( V_37 < 0 )
return V_37 ;
* V_36 = V_37 ;
F_33 ( V_15 ) ;
if ( V_2 -> V_22 -> V_39 ) {
V_37 = V_2 -> V_22 -> V_39 ( V_15 , V_35 ) ;
if ( V_37 ) {
F_23 ( V_35 , * V_36 ) ;
return V_37 ;
}
}
return 0 ;
}
void
F_34 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_40 * V_41 = & V_15 -> V_42 ;
F_35 ( & V_4 -> V_10 , & V_41 -> V_43 ) ;
F_36 ( V_41 -> V_44 ) ;
F_7 ( V_41 -> V_45 ) ;
V_41 -> V_45 = NULL ;
}
int
F_37 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_40 * V_41 ;
struct V_46 * V_45 ;
int V_37 ;
V_41 = & V_15 -> V_42 ;
V_41 -> V_45 = F_4 ( sizeof( struct V_40 ) , V_7 ) ;
if ( ! V_41 -> V_45 )
return - V_8 ;
V_45 = V_41 -> V_45 ;
V_45 -> type = V_47 ;
V_45 -> V_16 = V_15 -> V_16 ;
V_45 -> V_30 = V_15 ;
V_41 -> V_44 = F_38 ( & V_4 -> V_11 ,
V_15 -> V_16 / V_17 , 0 , false ) ;
if ( ! V_41 -> V_44 ) {
F_5 ( L_3 , V_15 -> V_48 ) ;
V_37 = - V_49 ;
goto V_50;
}
V_41 -> V_44 = F_39 ( V_41 -> V_44 ,
V_15 -> V_16 / V_17 , 0 ) ;
if ( ! V_41 -> V_44 ) {
V_37 = - V_8 ;
goto V_50;
}
V_41 -> V_43 . V_51 = V_41 -> V_44 -> V_52 ;
V_37 = F_40 ( & V_4 -> V_10 , & V_41 -> V_43 ) ;
if ( V_37 ) {
F_5 ( L_4 ) ;
goto V_53;
}
return 0 ;
V_53:
F_36 ( V_41 -> V_44 ) ;
V_50:
F_7 ( V_41 -> V_45 ) ;
V_41 -> V_45 = NULL ;
return V_37 ;
}
struct V_14 *
F_41 ( struct V_1 * V_2 , struct V_25 * V_18 ,
T_2 V_30 )
{
struct V_14 * V_15 ;
F_24 ( & V_18 -> V_31 ) ;
V_15 = F_25 ( & V_18 -> V_32 , V_30 ) ;
if ( V_15 == NULL ) {
F_26 ( & V_18 -> V_31 ) ;
return NULL ;
}
F_42 ( V_15 ) ;
F_26 ( & V_18 -> V_31 ) ;
return V_15 ;
}
int
F_43 ( struct V_1 * V_2 , void * V_54 ,
struct V_25 * V_35 )
{
struct V_55 * args = V_54 ;
int V_37 ;
if ( ! ( V_2 -> V_22 -> V_56 & V_57 ) )
return - V_58 ;
V_37 = F_23 ( V_35 , args -> V_30 ) ;
return V_37 ;
}
int
F_44 ( struct V_1 * V_2 , void * V_54 ,
struct V_25 * V_35 )
{
struct V_59 * args = V_54 ;
struct V_14 * V_15 ;
int V_37 ;
if ( ! ( V_2 -> V_22 -> V_56 & V_57 ) )
return - V_58 ;
V_15 = F_41 ( V_2 , V_35 , args -> V_30 ) ;
if ( V_15 == NULL )
return - V_60 ;
F_30 ( V_7 ) ;
F_24 ( & V_2 -> V_5 ) ;
if ( ! V_15 -> V_48 ) {
V_37 = F_31 ( & V_2 -> V_6 , V_15 , 1 , 0 , V_38 ) ;
if ( V_37 < 0 )
goto V_61;
V_15 -> V_48 = V_37 ;
F_42 ( V_15 ) ;
}
args -> V_48 = ( V_62 ) V_15 -> V_48 ;
V_37 = 0 ;
V_61:
F_26 ( & V_2 -> V_5 ) ;
F_32 () ;
F_45 ( V_15 ) ;
return V_37 ;
}
int
F_46 ( struct V_1 * V_2 , void * V_54 ,
struct V_25 * V_35 )
{
struct V_63 * args = V_54 ;
struct V_14 * V_15 ;
int V_37 ;
T_2 V_30 ;
if ( ! ( V_2 -> V_22 -> V_56 & V_57 ) )
return - V_58 ;
F_24 ( & V_2 -> V_5 ) ;
V_15 = F_25 ( & V_2 -> V_6 , ( int ) args -> V_48 ) ;
if ( V_15 )
F_42 ( V_15 ) ;
F_26 ( & V_2 -> V_5 ) ;
if ( ! V_15 )
return - V_60 ;
V_37 = F_29 ( V_35 , V_15 , & V_30 ) ;
F_45 ( V_15 ) ;
if ( V_37 )
return V_37 ;
args -> V_30 = V_30 ;
args -> V_16 = V_15 -> V_16 ;
return 0 ;
}
void
V_63 ( struct V_1 * V_2 , struct V_25 * V_64 )
{
F_3 ( & V_64 -> V_32 ) ;
F_2 ( & V_64 -> V_31 ) ;
}
static int
F_47 ( int V_65 , void * V_66 , void * V_54 )
{
struct V_25 * V_35 = V_54 ;
struct V_14 * V_15 = V_66 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_21 ( V_15 , V_35 ) ;
if ( V_2 -> V_22 -> V_34 )
V_2 -> V_22 -> V_34 ( V_15 , V_35 ) ;
F_28 ( V_15 ) ;
return 0 ;
}
void
F_48 ( struct V_1 * V_2 , struct V_25 * V_64 )
{
F_49 ( & V_64 -> V_32 ,
& F_47 , V_64 ) ;
F_50 ( & V_64 -> V_32 ) ;
}
void
F_51 ( struct V_14 * V_15 )
{
if ( V_15 -> V_18 )
V_24 ( V_15 -> V_18 ) ;
}
void
F_52 ( struct V_67 * V_67 )
{
struct V_14 * V_15 = (struct V_14 * ) V_67 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_13 ( ! F_53 ( & V_2 -> V_68 ) ) ;
if ( V_2 -> V_22 -> V_69 != NULL )
V_2 -> V_22 -> V_69 ( V_15 ) ;
}
static void F_54 ( struct V_67 * V_70 )
{
F_55 () ;
}
void F_56 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
F_24 ( & V_2 -> V_5 ) ;
if ( V_15 -> V_48 ) {
F_27 ( & V_2 -> V_6 , V_15 -> V_48 ) ;
V_15 -> V_48 = 0 ;
F_26 ( & V_2 -> V_5 ) ;
F_57 ( & V_15 -> V_20 , F_54 ) ;
} else
F_26 ( & V_2 -> V_5 ) ;
}
void F_58 ( struct V_71 * V_72 )
{
struct V_14 * V_15 = V_72 -> V_73 ;
F_42 ( V_15 ) ;
F_59 ( & V_15 -> V_2 -> V_68 ) ;
F_60 ( V_15 -> V_2 , V_72 ) ;
F_61 ( & V_15 -> V_2 -> V_68 ) ;
}
void F_62 ( struct V_71 * V_72 )
{
struct V_14 * V_15 = V_72 -> V_73 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_59 ( & V_2 -> V_68 ) ;
F_63 ( V_15 -> V_2 , V_72 ) ;
F_64 ( V_15 ) ;
F_61 ( & V_2 -> V_68 ) ;
}
int F_65 ( struct V_14 * V_15 , unsigned long V_74 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
F_66 ( & V_2 -> V_68 ) ;
if ( V_74 < V_72 -> V_75 - V_72 -> V_76 )
return - V_33 ;
if ( ! V_2 -> V_22 -> V_77 )
return - V_33 ;
V_72 -> V_78 |= V_79 | V_80 | V_81 | V_82 ;
V_72 -> V_83 = V_2 -> V_22 -> V_77 ;
V_72 -> V_73 = V_15 ;
V_72 -> V_84 = F_67 ( F_68 ( V_72 -> V_78 ) ) ;
F_42 ( V_15 ) ;
F_60 ( V_2 , V_72 ) ;
return 0 ;
}
int F_69 ( struct V_85 * V_18 , struct V_71 * V_72 )
{
struct V_25 * V_86 = V_18 -> V_87 ;
struct V_1 * V_2 = V_86 -> V_88 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_46 * V_45 = NULL ;
struct V_89 * V_43 ;
int V_37 = 0 ;
if ( F_70 ( V_2 ) )
return - V_58 ;
F_59 ( & V_2 -> V_68 ) ;
if ( F_71 ( & V_4 -> V_10 , V_72 -> V_90 , & V_43 ) ) {
F_61 ( & V_2 -> V_68 ) ;
return F_72 ( V_18 , V_72 ) ;
}
V_45 = F_73 ( V_43 , struct V_40 , V_43 ) -> V_45 ;
if ( ! V_45 ||
( ( V_45 -> V_91 & V_92 ) && ! F_74 ( V_93 ) ) ) {
V_37 = - V_94 ;
goto V_95;
}
V_37 = F_65 ( V_45 -> V_30 , V_45 -> V_16 , V_72 ) ;
V_95:
F_61 ( & V_2 -> V_68 ) ;
return V_37 ;
}
