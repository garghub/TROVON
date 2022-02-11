static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
const char * V_6 )
{
struct V_7 * exp = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_3 * V_11 , * V_12 ;
T_1 * V_13 ;
unsigned int V_14 ;
int V_15 ;
V_10 = F_2 ( F_3 ( exp ) , & V_16 ,
V_17 , V_18 ) ;
if ( V_10 == NULL )
return - V_19 ;
V_13 = F_4 ( & V_10 -> V_20 , & V_21 ) ;
* V_13 = V_5 ;
V_12 = F_4 ( & V_10 -> V_20 , & V_22 ) ;
F_5 ( V_12 ) ;
F_6 ( V_10 ) ;
V_12 -> V_23 = V_2 -> V_24 . V_23 ;
if ( V_2 -> V_25 == V_26 )
F_7 ( V_12 ) ;
else
F_8 ( V_12 ) ;
if ( V_5 == V_27 ) {
V_10 -> V_28 = V_29 ;
V_10 -> V_30 = V_31 ;
if ( V_2 -> V_25 == V_32 )
V_10 -> V_33 = V_10 -> V_34 = 1 ;
V_14 = V_35 ;
} else {
if ( V_2 -> V_25 == V_26 )
V_10 -> V_28 = V_36 ;
else
V_10 -> V_28 = V_37 ;
V_14 = V_38 ;
}
F_9 ( V_10 ) ;
if ( V_2 -> V_25 == V_26 )
F_10 ( exp -> V_39 -> V_40 . V_41 . V_42 , NULL ) ;
V_15 = F_11 ( V_10 ) ;
if ( V_2 -> V_25 == V_26 )
F_12 ( exp -> V_39 -> V_40 . V_41 . V_42 , NULL ) ;
if ( V_15 )
goto V_43;
V_11 = F_13 ( & V_10 -> V_20 , & V_22 ) ;
* V_4 = * V_11 ;
if ( ! F_14 ( V_4 ) ) {
F_15 ( L_1
V_44 L_2 , V_2 -> V_45 , F_16 ( V_4 ) ) ;
V_15 = - V_46 ;
goto V_43;
}
if ( F_17 ( V_4 ) ) {
F_15 ( L_3
V_44 L_4 , V_2 -> V_45 , F_16 ( V_4 ) ) ;
V_15 = - V_46 ;
goto V_43;
}
F_18 ( V_14 , L_5 V_44 L_4 ,
V_2 -> V_45 , V_6 , F_16 ( V_4 ) ) ;
V_43:
F_19 ( V_10 ) ;
return V_15 ;
}
int F_20 ( struct V_1 * V_2 ,
const struct V_47 * V_48 )
{
int V_15 ;
F_21 ( & V_2 -> V_49 ) ;
if ( ! V_2 -> V_8 ) {
F_22 ( & V_2 -> V_49 ) ;
return - V_50 ;
}
V_15 = F_1 ( V_2 , & V_2 -> V_24 ,
V_27 , L_6 ) ;
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
static int F_23 ( const struct V_47 * V_48 ,
struct V_1 * V_2 )
{
int V_15 ;
do {
V_15 = F_1 ( V_2 , & V_2 -> V_24 ,
V_51 , L_7 ) ;
} while ( V_15 == - V_50 || V_15 == - V_52 );
return V_15 ;
}
static int F_24 ( const struct V_47 * V_48 ,
struct V_1 * V_2 , T_2 * V_53 )
{
int V_15 ;
F_25 ( F_14 ( & V_2 -> V_24 ) ) ;
if ( F_17 ( & V_2 -> V_24 ) ) {
V_15 = F_23 ( V_48 , V_2 ) ;
if ( V_15 ) {
F_15 ( L_8 ,
V_2 -> V_45 , V_15 ) ;
return V_15 ;
}
F_26 ( V_38 , L_9 V_44 L_2 ,
V_2 -> V_45 , F_16 ( & V_2 -> V_24 ) ) ;
} else {
V_15 = 0 ;
}
F_25 ( ! F_17 ( & V_2 -> V_24 ) ) ;
* V_53 = V_2 -> V_24 . V_54 ;
V_2 -> V_24 . V_54 += 1 ;
F_26 ( V_38 , L_10 , V_2 -> V_45 ,
* V_53 ) ;
return V_15 ;
}
static int F_27 ( struct V_1 * V_2 ,
T_3 * V_55 )
{
if ( V_2 -> V_56 ) {
F_28 ( & V_2 -> V_57 , V_55 ) ;
F_29 ( V_58 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_30 () ;
F_21 ( & V_2 -> V_49 ) ;
F_31 ( & V_2 -> V_57 , V_55 ) ;
F_29 ( V_59 ) ;
return - V_52 ;
}
++ V_2 -> V_56 ;
F_22 ( & V_2 -> V_49 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_56 == 1 ) ;
F_21 ( & V_2 -> V_49 ) ;
-- V_2 -> V_56 ;
F_33 ( & V_2 -> V_57 ) ;
}
int F_34 ( const struct V_47 * V_48 ,
struct V_1 * V_2 , struct V_60 * V_61 )
{
T_3 V_55 ;
int V_15 ;
F_25 ( V_2 != NULL ) ;
F_25 ( V_61 != NULL ) ;
F_35 ( & V_55 , V_62 ) ;
F_21 ( & V_2 -> V_49 ) ;
if ( F_36 ( V_63 ) )
V_2 -> V_64 . V_65 = V_2 -> V_66 ;
while ( 1 ) {
T_2 V_53 ;
if ( ! F_37 ( & V_2 -> V_64 ) &&
F_38 ( & V_2 -> V_64 ) < V_2 -> V_66 ) {
V_2 -> V_64 . V_65 += 1 ;
V_15 = 0 ;
break;
}
V_15 = F_27 ( V_2 , & V_55 ) ;
if ( V_15 )
continue;
V_15 = F_24 ( V_48 , V_2 , & V_53 ) ;
if ( V_15 ) {
F_15 ( L_11 ,
V_2 -> V_45 , V_15 ) ;
F_32 ( V_2 ) ;
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
F_26 ( V_38 , L_12 ,
V_2 -> V_45 , V_53 ) ;
V_2 -> V_64 . V_65 = V_67 ;
V_2 -> V_64 . V_68 = V_53 ;
V_2 -> V_64 . V_69 = 0 ;
V_15 = 1 ;
F_32 ( V_2 ) ;
break;
}
* V_61 = V_2 -> V_64 ;
F_22 ( & V_2 -> V_49 ) ;
F_26 ( V_38 , L_13 V_70 L_2 , V_2 -> V_45 , F_39 ( V_61 ) ) ;
return V_15 ;
}
void F_40 ( struct V_1 * V_2 )
{
T_3 V_55 ;
F_25 ( V_2 != NULL ) ;
F_35 ( & V_55 , V_62 ) ;
F_21 ( & V_2 -> V_49 ) ;
while ( V_2 -> V_56 ) {
F_28 ( & V_2 -> V_57 , & V_55 ) ;
F_29 ( V_58 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_30 () ;
F_21 ( & V_2 -> V_49 ) ;
F_31 ( & V_2 -> V_57 , & V_55 ) ;
F_29 ( V_59 ) ;
}
F_41 ( & V_2 -> V_64 ) ;
V_2 -> V_24 . V_23 = - 1 ;
F_5 ( & V_2 -> V_24 ) ;
F_22 ( & V_2 -> V_49 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( ! F_43 ( V_2 -> V_71 ) )
F_44 ( & V_2 -> V_71 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_71 = F_46 ( V_2 -> V_45 ,
V_72 ,
NULL , NULL ) ;
if ( F_43 ( V_2 -> V_71 ) ) {
F_15 ( L_14 , V_2 -> V_45 ) ;
V_15 = V_2 -> V_71 ? F_47 ( V_2 -> V_71 )
: - V_19 ;
V_2 -> V_71 = NULL ;
return V_15 ;
}
V_15 = F_48 ( V_2 -> V_71 ,
V_73 , V_2 ) ;
if ( V_15 ) {
F_15 ( L_15 ,
V_2 -> V_45 , V_15 ) ;
goto V_74;
}
return 0 ;
V_74:
F_42 ( V_2 ) ;
return V_15 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
if ( V_2 -> V_8 ) {
F_50 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
}
static int F_51 ( struct V_1 * V_2 ,
struct V_7 * exp ,
enum V_75 type ,
const char * V_76 )
{
int V_15 ;
F_25 ( V_2 != NULL ) ;
F_25 ( V_76 != NULL ) ;
V_2 -> V_25 = type ;
F_52 ( & V_2 -> V_49 ) ;
if ( type == V_26 )
V_2 -> V_66 = V_77 ;
else
V_2 -> V_66 = V_78 ;
F_53 ( & V_2 -> V_57 ) ;
F_40 ( V_2 ) ;
V_2 -> V_8 = F_54 ( exp ) ;
snprintf ( V_2 -> V_45 , sizeof( V_2 -> V_45 ) ,
L_16 , V_76 ) ;
V_15 = F_45 ( V_2 ) ;
if ( V_15 )
F_49 ( V_2 ) ;
return V_15 ;
}
int F_55 ( struct V_79 * V_80 ,
struct V_7 * exp , enum V_75 type )
{
struct V_81 * V_41 = & V_80 -> V_40 . V_41 ;
char * V_76 ;
int V_15 ;
V_41 -> V_82 = F_56 ( sizeof( * V_41 -> V_82 ) , V_83 ) ;
if ( ! V_41 -> V_82 )
return - V_19 ;
V_76 = F_56 ( V_84 + 5 , V_83 ) ;
if ( ! V_76 ) {
V_15 = - V_19 ;
goto V_85;
}
snprintf ( V_76 , V_84 + 5 , L_16 , V_80 -> V_86 ) ;
V_15 = F_51 ( V_41 -> V_82 , exp , type , V_76 ) ;
F_57 ( V_76 ) ;
if ( V_15 )
goto V_85;
return V_15 ;
V_85:
F_57 ( V_41 -> V_82 ) ;
V_41 -> V_82 = NULL ;
return V_15 ;
}
int F_58 ( struct V_79 * V_80 )
{
struct V_81 * V_41 = & V_80 -> V_40 . V_41 ;
if ( V_41 -> V_82 != NULL ) {
F_49 ( V_41 -> V_82 ) ;
F_57 ( V_41 -> V_82 ) ;
V_41 -> V_82 = NULL ;
}
return 0 ;
}
static int T_4 F_59 ( void )
{
V_72 = F_46 ( V_87 ,
V_88 ,
NULL , NULL ) ;
return F_60 ( V_72 ) ;
}
static void T_5 F_61 ( void )
{
if ( ! F_43 ( V_72 ) )
F_44 ( & V_72 ) ;
}
