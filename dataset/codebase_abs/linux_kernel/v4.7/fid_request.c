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
if ( V_2 -> V_25 == V_32 )
V_10 -> V_33 = V_10 -> V_34 = 1 ;
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
if ( V_5 != V_27 && V_2 -> V_25 == V_26 )
F_12 ( exp -> V_40 -> V_41 . V_42 . V_43 , NULL ) ;
V_15 = F_13 ( V_10 ) ;
if ( V_5 != V_27 && V_2 -> V_25 == V_26 )
F_14 ( exp -> V_40 -> V_41 . V_42 . V_43 , NULL ) ;
if ( V_15 )
goto V_44;
V_11 = F_15 ( & V_10 -> V_20 , & V_22 ) ;
* V_4 = * V_11 ;
if ( ! F_16 ( V_4 ) ) {
F_17 ( L_1
V_45 L_2 , V_2 -> V_46 , F_18 ( V_4 ) ) ;
V_15 = - V_47 ;
goto V_44;
}
if ( F_19 ( V_4 ) ) {
F_17 ( L_3
V_45 L_4 , V_2 -> V_46 , F_18 ( V_4 ) ) ;
V_15 = - V_47 ;
goto V_44;
}
F_20 ( V_14 , L_5 V_45 L_4 ,
V_2 -> V_46 , V_6 , F_18 ( V_4 ) ) ;
V_44:
F_21 ( V_10 ) ;
return V_15 ;
}
static int F_22 ( const struct V_48 * V_49 ,
struct V_1 * V_2 )
{
int V_15 ;
do {
V_15 = F_1 ( V_2 , & V_2 -> V_24 ,
V_50 , L_6 ) ;
} while ( V_15 == - V_51 || V_15 == - V_52 );
return V_15 ;
}
static int F_23 ( const struct V_48 * V_49 ,
struct V_1 * V_2 , T_2 * V_53 )
{
int V_15 ;
F_2 ( F_16 ( & V_2 -> V_24 ) ) ;
if ( F_19 ( & V_2 -> V_24 ) ) {
V_15 = F_22 ( V_49 , V_2 ) ;
if ( V_15 ) {
F_17 ( L_7 ,
V_2 -> V_46 , V_15 ) ;
return V_15 ;
}
F_24 ( V_39 , L_8 V_45 L_2 ,
V_2 -> V_46 , F_18 ( & V_2 -> V_24 ) ) ;
} else {
V_15 = 0 ;
}
F_2 ( ! F_19 ( & V_2 -> V_24 ) ) ;
* V_53 = V_2 -> V_24 . V_54 ;
V_2 -> V_24 . V_54 += 1 ;
F_24 ( V_39 , L_9 , V_2 -> V_46 ,
* V_53 ) ;
return V_15 ;
}
static int F_25 ( struct V_1 * V_2 ,
T_3 * V_55 )
{
if ( V_2 -> V_56 ) {
F_26 ( & V_2 -> V_57 , V_55 ) ;
F_27 ( V_58 ) ;
F_28 ( & V_2 -> V_59 ) ;
F_29 () ;
F_30 ( & V_2 -> V_59 ) ;
F_31 ( & V_2 -> V_57 , V_55 ) ;
F_27 ( V_60 ) ;
return - V_52 ;
}
++ V_2 -> V_56 ;
F_28 ( & V_2 -> V_59 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_56 == 1 ) ;
F_30 ( & V_2 -> V_59 ) ;
-- V_2 -> V_56 ;
F_33 ( & V_2 -> V_57 ) ;
}
int F_34 ( const struct V_48 * V_49 ,
struct V_1 * V_2 , struct V_61 * V_62 )
{
T_3 V_55 ;
int V_15 ;
F_2 ( V_2 ) ;
F_2 ( V_62 ) ;
F_35 ( & V_55 , V_63 ) ;
F_30 ( & V_2 -> V_59 ) ;
if ( F_36 ( V_64 ) )
V_2 -> V_65 . V_66 = V_2 -> V_67 ;
while ( 1 ) {
T_2 V_53 ;
if ( ! F_37 ( & V_2 -> V_65 ) &&
F_38 ( & V_2 -> V_65 ) < V_2 -> V_67 ) {
V_2 -> V_65 . V_66 += 1 ;
V_15 = 0 ;
break;
}
V_15 = F_25 ( V_2 , & V_55 ) ;
if ( V_15 )
continue;
V_15 = F_23 ( V_49 , V_2 , & V_53 ) ;
if ( V_15 ) {
F_17 ( L_10 ,
V_2 -> V_46 , V_15 ) ;
F_32 ( V_2 ) ;
F_28 ( & V_2 -> V_59 ) ;
return V_15 ;
}
F_24 ( V_39 , L_11 ,
V_2 -> V_46 , V_53 ) ;
V_2 -> V_65 . V_66 = V_68 ;
V_2 -> V_65 . V_69 = V_53 ;
V_2 -> V_65 . V_70 = 0 ;
V_15 = 1 ;
F_32 ( V_2 ) ;
break;
}
* V_62 = V_2 -> V_65 ;
F_28 ( & V_2 -> V_59 ) ;
F_24 ( V_39 , L_12 V_71 L_2 , V_2 -> V_46 , F_39 ( V_62 ) ) ;
return V_15 ;
}
void F_40 ( struct V_1 * V_2 )
{
T_3 V_55 ;
F_2 ( V_2 ) ;
F_35 ( & V_55 , V_63 ) ;
F_30 ( & V_2 -> V_59 ) ;
while ( V_2 -> V_56 ) {
F_26 ( & V_2 -> V_57 , & V_55 ) ;
F_27 ( V_58 ) ;
F_28 ( & V_2 -> V_59 ) ;
F_29 () ;
F_30 ( & V_2 -> V_59 ) ;
F_31 ( & V_2 -> V_57 , & V_55 ) ;
F_27 ( V_60 ) ;
}
F_41 ( & V_2 -> V_65 ) ;
V_2 -> V_24 . V_23 = - 1 ;
F_7 ( & V_2 -> V_24 ) ;
F_28 ( & V_2 -> V_59 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( ! F_43 ( V_2 -> V_72 ) )
F_44 ( & V_2 -> V_72 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_72 = F_46 ( V_2 -> V_46 ,
V_73 ,
NULL , NULL ) ;
if ( F_43 ( V_2 -> V_72 ) ) {
F_17 ( L_13 , V_2 -> V_46 ) ;
V_15 = V_2 -> V_72 ? F_47 ( V_2 -> V_72 )
: - V_19 ;
V_2 -> V_72 = NULL ;
return V_15 ;
}
V_15 = F_48 ( V_2 -> V_72 ,
V_74 , V_2 ) ;
if ( V_15 ) {
F_17 ( L_14 ,
V_2 -> V_46 , V_15 ) ;
goto V_75;
}
return 0 ;
V_75:
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
enum V_76 type ,
const char * V_77 )
{
int V_15 ;
F_2 ( V_2 ) ;
F_2 ( V_77 ) ;
V_2 -> V_25 = type ;
F_52 ( & V_2 -> V_59 ) ;
if ( type == V_26 )
V_2 -> V_67 = V_78 ;
else
V_2 -> V_67 = V_79 ;
F_53 ( & V_2 -> V_57 ) ;
F_40 ( V_2 ) ;
V_2 -> V_8 = F_54 ( exp ) ;
snprintf ( V_2 -> V_46 , sizeof( V_2 -> V_46 ) ,
L_15 , V_77 ) ;
V_15 = F_45 ( V_2 ) ;
if ( V_15 )
F_49 ( V_2 ) ;
return V_15 ;
}
int F_55 ( struct V_80 * V_81 ,
struct V_7 * exp , enum V_76 type )
{
struct V_82 * V_42 = & V_81 -> V_41 . V_42 ;
char * V_77 ;
int V_15 ;
V_42 -> V_83 = F_56 ( sizeof( * V_42 -> V_83 ) , V_84 ) ;
if ( ! V_42 -> V_83 )
return - V_19 ;
V_77 = F_56 ( V_85 + 5 , V_84 ) ;
if ( ! V_77 ) {
V_15 = - V_19 ;
goto V_86;
}
snprintf ( V_77 , V_85 + 5 , L_15 , V_81 -> V_87 ) ;
V_15 = F_51 ( V_42 -> V_83 , exp , type , V_77 ) ;
F_57 ( V_77 ) ;
if ( V_15 )
goto V_86;
return V_15 ;
V_86:
F_57 ( V_42 -> V_83 ) ;
V_42 -> V_83 = NULL ;
return V_15 ;
}
int F_58 ( struct V_80 * V_81 )
{
struct V_82 * V_42 = & V_81 -> V_41 . V_42 ;
if ( V_42 -> V_83 ) {
F_49 ( V_42 -> V_83 ) ;
F_57 ( V_42 -> V_83 ) ;
V_42 -> V_83 = NULL ;
}
return 0 ;
}
static int T_4 F_59 ( void )
{
V_73 = F_46 ( V_88 ,
V_89 ,
NULL , NULL ) ;
return F_60 ( V_73 ) ;
}
static void T_5 F_61 ( void )
{
if ( ! F_43 ( V_73 ) )
F_44 ( & V_73 ) ;
}
