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
F_2 ( exp && ! F_3 ( exp ) ) ;
V_10 = F_4 ( F_5 ( exp ) , & V_16 ,
V_17 , V_18 ) ;
if ( ! V_10 )
return - V_19 ;
V_13 = F_6 ( & V_10 -> V_20 , & V_21 ) ;
* V_13 = V_5 ;
V_12 = F_6 ( & V_10 -> V_20 , & V_22 ) ;
F_7 ( V_12 ) ;
F_8 ( V_10 ) ;
V_12 -> V_23 = V_2 -> V_24 . V_23 ;
if ( V_2 -> V_25 == V_26 )
F_9 ( V_12 ) ;
else
F_10 ( V_12 ) ;
if ( V_5 == V_27 ) {
V_10 -> V_28 = V_29 ;
V_10 -> V_30 = V_31 ;
if ( V_2 -> V_25 == V_32 ) {
V_10 -> V_33 = 1 ;
V_10 -> V_34 = 1 ;
}
V_14 = V_35 ;
} else {
if ( V_2 -> V_25 == V_26 ) {
V_10 -> V_30 = V_31 ;
V_10 -> V_28 = V_36 ;
} else {
V_10 -> V_30 = V_37 ;
V_10 -> V_28 = V_38 ;
}
V_14 = V_39 ;
}
F_11 ( V_10 ) ;
V_15 = F_12 ( V_10 ) ;
if ( V_15 )
goto V_40;
V_11 = F_13 ( & V_10 -> V_20 , & V_22 ) ;
* V_4 = * V_11 ;
if ( ! F_14 ( V_4 ) ) {
F_15 ( L_1
V_41 L_2 , V_2 -> V_42 , F_16 ( V_4 ) ) ;
V_15 = - V_43 ;
goto V_40;
}
if ( F_17 ( V_4 ) ) {
F_15 ( L_3
V_41 L_4 , V_2 -> V_42 , F_16 ( V_4 ) ) ;
V_15 = - V_43 ;
goto V_40;
}
F_18 ( V_14 , L_5 V_41 L_4 ,
V_2 -> V_42 , V_6 , F_16 ( V_4 ) ) ;
V_40:
F_19 ( V_10 ) ;
return V_15 ;
}
static int F_20 ( const struct V_44 * V_45 ,
struct V_1 * V_2 )
{
int V_15 ;
do {
V_15 = F_1 ( V_2 , & V_2 -> V_24 ,
V_46 , L_6 ) ;
} while ( V_15 == - V_47 || V_15 == - V_48 );
return V_15 ;
}
static int F_21 ( const struct V_44 * V_45 ,
struct V_1 * V_2 , T_2 * V_49 )
{
int V_15 ;
F_2 ( F_14 ( & V_2 -> V_24 ) ) ;
if ( F_17 ( & V_2 -> V_24 ) ) {
V_15 = F_20 ( V_45 , V_2 ) ;
if ( V_15 ) {
F_15 ( L_7 ,
V_2 -> V_42 , V_15 ) ;
return V_15 ;
}
F_22 ( V_39 , L_8 V_41 L_2 ,
V_2 -> V_42 , F_16 ( & V_2 -> V_24 ) ) ;
} else {
V_15 = 0 ;
}
F_2 ( ! F_17 ( & V_2 -> V_24 ) ) ;
* V_49 = V_2 -> V_24 . V_50 ;
V_2 -> V_24 . V_50 += 1 ;
F_22 ( V_39 , L_9 , V_2 -> V_42 ,
* V_49 ) ;
return V_15 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_3 * V_51 )
{
if ( V_2 -> V_52 ) {
F_24 ( & V_2 -> V_53 , V_51 ) ;
F_25 ( V_54 ) ;
F_26 ( & V_2 -> V_55 ) ;
F_27 () ;
F_28 ( & V_2 -> V_55 ) ;
F_29 ( & V_2 -> V_53 , V_51 ) ;
F_25 ( V_56 ) ;
return - V_48 ;
}
++ V_2 -> V_52 ;
F_26 ( & V_2 -> V_55 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_52 == 1 ) ;
F_28 ( & V_2 -> V_55 ) ;
-- V_2 -> V_52 ;
F_31 ( & V_2 -> V_53 ) ;
}
int F_32 ( const struct V_44 * V_45 ,
struct V_1 * V_2 , struct V_57 * V_58 )
{
T_3 V_51 ;
int V_15 ;
F_2 ( V_2 ) ;
F_2 ( V_58 ) ;
F_33 ( & V_51 , V_59 ) ;
F_28 ( & V_2 -> V_55 ) ;
if ( F_34 ( V_60 ) )
V_2 -> V_61 . V_62 = V_2 -> V_63 ;
while ( 1 ) {
T_2 V_49 ;
if ( ! F_35 ( & V_2 -> V_61 ) &&
F_36 ( & V_2 -> V_61 ) < V_2 -> V_63 ) {
V_2 -> V_61 . V_62 += 1 ;
V_15 = 0 ;
break;
}
V_15 = F_23 ( V_2 , & V_51 ) ;
if ( V_15 )
continue;
V_15 = F_21 ( V_45 , V_2 , & V_49 ) ;
if ( V_15 ) {
F_15 ( L_10 ,
V_2 -> V_42 , V_15 ) ;
F_30 ( V_2 ) ;
F_26 ( & V_2 -> V_55 ) ;
return V_15 ;
}
F_22 ( V_39 , L_11 ,
V_2 -> V_42 , V_49 ) ;
V_2 -> V_61 . V_62 = V_64 ;
V_2 -> V_61 . V_65 = V_49 ;
V_2 -> V_61 . V_66 = 0 ;
V_15 = 1 ;
F_30 ( V_2 ) ;
break;
}
* V_58 = V_2 -> V_61 ;
F_26 ( & V_2 -> V_55 ) ;
F_22 ( V_39 , L_12 V_67 L_2 , V_2 -> V_42 , F_37 ( V_58 ) ) ;
return V_15 ;
}
void F_38 ( struct V_1 * V_2 )
{
T_3 V_51 ;
F_2 ( V_2 ) ;
F_33 ( & V_51 , V_59 ) ;
F_28 ( & V_2 -> V_55 ) ;
while ( V_2 -> V_52 ) {
F_24 ( & V_2 -> V_53 , & V_51 ) ;
F_25 ( V_54 ) ;
F_26 ( & V_2 -> V_55 ) ;
F_27 () ;
F_28 ( & V_2 -> V_55 ) ;
F_29 ( & V_2 -> V_53 , & V_51 ) ;
F_25 ( V_56 ) ;
}
F_39 ( & V_2 -> V_61 ) ;
V_2 -> V_24 . V_23 = - 1 ;
F_7 ( & V_2 -> V_24 ) ;
F_26 ( & V_2 -> V_55 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( ! F_41 ( V_2 -> V_68 ) )
F_42 ( & V_2 -> V_68 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_68 = F_44 ( V_2 -> V_42 ,
V_69 ,
NULL , NULL ) ;
if ( F_41 ( V_2 -> V_68 ) ) {
F_15 ( L_13 , V_2 -> V_42 ) ;
V_15 = V_2 -> V_68 ? F_45 ( V_2 -> V_68 )
: - V_19 ;
V_2 -> V_68 = NULL ;
return V_15 ;
}
V_15 = F_46 ( V_2 -> V_68 ,
V_70 , V_2 ) ;
if ( V_15 ) {
F_15 ( L_14 ,
V_2 -> V_42 , V_15 ) ;
goto V_71;
}
return 0 ;
V_71:
F_40 ( V_2 ) ;
return V_15 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
if ( V_2 -> V_8 ) {
F_48 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
}
static int F_49 ( struct V_1 * V_2 ,
struct V_7 * exp ,
enum V_72 type ,
const char * V_73 )
{
int V_15 ;
F_2 ( V_2 ) ;
F_2 ( V_73 ) ;
V_2 -> V_25 = type ;
F_50 ( & V_2 -> V_55 ) ;
if ( type == V_26 )
V_2 -> V_63 = V_74 ;
else
V_2 -> V_63 = V_75 ;
F_51 ( & V_2 -> V_53 ) ;
F_38 ( V_2 ) ;
V_2 -> V_8 = F_52 ( exp ) ;
snprintf ( V_2 -> V_42 , sizeof( V_2 -> V_42 ) ,
L_15 , V_73 ) ;
V_15 = F_43 ( V_2 ) ;
if ( V_15 )
F_47 ( V_2 ) ;
return V_15 ;
}
int F_53 ( struct V_76 * V_77 ,
struct V_7 * exp , enum V_72 type )
{
struct V_78 * V_79 = & V_77 -> V_80 . V_79 ;
char * V_73 ;
int V_15 ;
V_79 -> V_81 = F_54 ( sizeof( * V_79 -> V_81 ) , V_82 ) ;
if ( ! V_79 -> V_81 )
return - V_19 ;
V_73 = F_54 ( V_83 + 5 , V_82 ) ;
if ( ! V_73 ) {
V_15 = - V_19 ;
goto V_84;
}
snprintf ( V_73 , V_83 + 5 , L_15 , V_77 -> V_85 ) ;
V_15 = F_49 ( V_79 -> V_81 , exp , type , V_73 ) ;
F_55 ( V_73 ) ;
if ( V_15 )
goto V_84;
return V_15 ;
V_84:
F_55 ( V_79 -> V_81 ) ;
V_79 -> V_81 = NULL ;
return V_15 ;
}
int F_56 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = & V_77 -> V_80 . V_79 ;
if ( V_79 -> V_81 ) {
F_47 ( V_79 -> V_81 ) ;
F_55 ( V_79 -> V_81 ) ;
V_79 -> V_81 = NULL ;
}
return 0 ;
}
static int T_4 F_57 ( void )
{
V_69 = F_44 ( V_86 ,
V_87 ,
NULL , NULL ) ;
return F_58 ( V_69 ) ;
}
static void T_5 F_59 ( void )
{
if ( ! F_41 ( V_69 ) )
F_42 ( & V_69 ) ;
}
