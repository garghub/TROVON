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
if ( V_2 -> V_50 ) {
V_15 = 0 ;
} else {
if ( V_2 -> V_8 == NULL ) {
F_22 ( & V_2 -> V_49 ) ;
return - V_51 ;
}
V_15 = F_1 ( V_2 , & V_2 -> V_24 ,
V_27 , L_6 ) ;
}
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
static int F_23 ( const struct V_47 * V_48 ,
struct V_1 * V_2 )
{
int V_15 ;
if ( V_2 -> V_50 ) {
V_15 = 0 ;
} else {
do {
V_15 = F_1 ( V_2 , & V_2 -> V_24 ,
V_52 , L_7 ) ;
} while ( V_15 == - V_51 || V_15 == - V_53 );
}
return V_15 ;
}
static int F_24 ( const struct V_47 * V_48 ,
struct V_1 * V_2 , T_2 * V_54 )
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
* V_54 = V_2 -> V_24 . V_55 ;
V_2 -> V_24 . V_55 += 1 ;
F_26 ( V_38 , L_10 , V_2 -> V_45 ,
* V_54 ) ;
return V_15 ;
}
static int F_27 ( struct V_1 * V_2 ,
T_3 * V_56 )
{
if ( V_2 -> V_57 ) {
F_28 ( & V_2 -> V_58 , V_56 ) ;
F_29 ( V_59 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_30 () ;
F_21 ( & V_2 -> V_49 ) ;
F_31 ( & V_2 -> V_58 , V_56 ) ;
F_29 ( V_60 ) ;
return - V_53 ;
}
++ V_2 -> V_57 ;
F_22 ( & V_2 -> V_49 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_57 == 1 ) ;
F_21 ( & V_2 -> V_49 ) ;
-- V_2 -> V_57 ;
F_33 ( & V_2 -> V_58 ) ;
}
int F_34 ( const struct V_47 * V_48 ,
struct V_1 * V_2 , T_2 * V_54 )
{
T_3 V_56 ;
int V_15 ;
F_25 ( V_54 != NULL ) ;
F_21 ( & V_2 -> V_49 ) ;
F_35 ( & V_56 , V_61 ) ;
while ( 1 ) {
V_15 = F_27 ( V_2 , & V_56 ) ;
if ( V_15 == 0 )
break;
}
V_15 = F_24 ( V_48 , V_2 , V_54 ) ;
if ( V_15 ) {
F_15 ( L_11 ,
V_2 -> V_45 , V_15 ) ;
F_32 ( V_2 ) ;
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
F_26 ( V_38 , L_12 ,
V_2 -> V_45 , * V_54 ) ;
if ( V_2 -> V_25 == V_26 )
V_2 -> V_62 . V_63 = V_64 ;
else
V_2 -> V_62 . V_63 = V_65 ;
V_2 -> V_62 . V_66 = * V_54 ;
V_2 -> V_62 . V_67 = 0 ;
F_32 ( V_2 ) ;
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
int F_36 ( const struct V_47 * V_48 ,
struct V_1 * V_2 , struct V_68 * V_69 )
{
T_3 V_56 ;
int V_15 ;
F_25 ( V_2 != NULL ) ;
F_25 ( V_69 != NULL ) ;
F_35 ( & V_56 , V_61 ) ;
F_21 ( & V_2 -> V_49 ) ;
if ( F_37 ( V_70 ) )
V_2 -> V_62 . V_63 = V_2 -> V_71 ;
while ( 1 ) {
T_2 V_54 ;
if ( ! F_38 ( & V_2 -> V_62 ) &&
F_39 ( & V_2 -> V_62 ) < V_2 -> V_71 ) {
V_2 -> V_62 . V_63 += 1 ;
V_15 = 0 ;
break;
}
V_15 = F_27 ( V_2 , & V_56 ) ;
if ( V_15 )
continue;
V_15 = F_24 ( V_48 , V_2 , & V_54 ) ;
if ( V_15 ) {
F_15 ( L_11 ,
V_2 -> V_45 , V_15 ) ;
F_32 ( V_2 ) ;
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
F_26 ( V_38 , L_13 ,
V_2 -> V_45 , V_54 ) ;
V_2 -> V_62 . V_63 = V_72 ;
V_2 -> V_62 . V_66 = V_54 ;
V_2 -> V_62 . V_67 = 0 ;
V_15 = 1 ;
F_32 ( V_2 ) ;
break;
}
* V_69 = V_2 -> V_62 ;
F_22 ( & V_2 -> V_49 ) ;
F_26 ( V_38 , L_14 V_73 L_2 , V_2 -> V_45 , F_40 ( V_69 ) ) ;
return V_15 ;
}
void F_41 ( struct V_1 * V_2 )
{
T_3 V_56 ;
F_25 ( V_2 != NULL ) ;
F_35 ( & V_56 , V_61 ) ;
F_21 ( & V_2 -> V_49 ) ;
while ( V_2 -> V_57 ) {
F_28 ( & V_2 -> V_58 , & V_56 ) ;
F_29 ( V_59 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_30 () ;
F_21 ( & V_2 -> V_49 ) ;
F_31 ( & V_2 -> V_58 , & V_56 ) ;
F_29 ( V_60 ) ;
}
F_42 ( & V_2 -> V_62 ) ;
V_2 -> V_24 . V_23 = - 1 ;
F_5 ( & V_2 -> V_24 ) ;
F_22 ( & V_2 -> V_49 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( ! F_44 ( V_2 -> V_74 ) )
F_45 ( & V_2 -> V_74 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_74 = F_47 ( V_2 -> V_45 ,
V_75 ,
NULL , NULL ) ;
if ( F_44 ( V_2 -> V_74 ) ) {
F_15 ( L_15 , V_2 -> V_45 ) ;
V_15 = V_2 -> V_74 ? F_48 ( V_2 -> V_74 )
: - V_19 ;
V_2 -> V_74 = NULL ;
return V_15 ;
}
V_15 = F_49 ( V_2 -> V_74 ,
V_76 , V_2 ) ;
if ( V_15 ) {
F_15 ( L_16 ,
V_2 -> V_45 , V_15 ) ;
goto V_77;
}
return 0 ;
V_77:
F_43 ( V_2 ) ;
return V_15 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_7 * exp ,
enum V_78 type ,
const char * V_79 ,
struct V_80 * V_81 )
{
int V_15 ;
F_25 ( V_2 != NULL ) ;
F_25 ( V_79 != NULL ) ;
V_2 -> V_50 = V_81 ;
V_2 -> V_25 = type ;
F_51 ( & V_2 -> V_49 ) ;
if ( type == V_26 )
V_2 -> V_71 = V_64 ;
else
V_2 -> V_71 = V_65 ;
F_52 ( & V_2 -> V_58 ) ;
F_41 ( V_2 ) ;
if ( exp != NULL )
V_2 -> V_8 = F_53 ( exp ) ;
else if ( type == V_26 )
F_25 ( V_2 -> V_50 != NULL ) ;
snprintf ( V_2 -> V_45 , sizeof( V_2 -> V_45 ) ,
L_17 , V_79 ) ;
V_15 = F_46 ( V_2 ) ;
if ( V_15 )
F_54 ( V_2 ) ;
return V_15 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
if ( V_2 -> V_8 != NULL ) {
F_55 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
V_2 -> V_50 = NULL ;
}
int F_56 ( struct V_82 * V_83 ,
struct V_7 * exp , enum V_78 type )
{
struct V_84 * V_41 = & V_83 -> V_40 . V_41 ;
char * V_79 ;
int V_15 ;
V_41 -> V_85 = F_57 ( sizeof( * V_41 -> V_85 ) , V_86 ) ;
if ( V_41 -> V_85 == NULL )
return - V_19 ;
V_79 = F_57 ( V_87 + 5 , V_86 ) ;
if ( V_79 == NULL ) {
V_15 = - V_19 ;
goto V_88;
}
snprintf ( V_79 , V_87 + 5 , L_17 , V_83 -> V_89 ) ;
V_15 = F_50 ( V_41 -> V_85 , exp , type , V_79 , NULL ) ;
F_58 ( V_79 ) ;
if ( V_15 )
goto V_88;
return V_15 ;
V_88:
F_58 ( V_41 -> V_85 ) ;
V_41 -> V_85 = NULL ;
return V_15 ;
}
int F_59 ( struct V_82 * V_83 )
{
struct V_84 * V_41 = & V_83 -> V_40 . V_41 ;
if ( V_41 -> V_85 != NULL ) {
F_54 ( V_41 -> V_85 ) ;
F_58 ( V_41 -> V_85 ) ;
V_41 -> V_85 = NULL ;
}
return 0 ;
}
static int T_4 F_60 ( void )
{
V_75 = F_47 ( V_90 ,
V_91 ,
NULL , NULL ) ;
return F_61 ( V_75 ) ;
}
static void T_5 F_62 ( void )
{
if ( ! F_44 ( V_75 ) )
F_45 ( & V_75 ) ;
}
