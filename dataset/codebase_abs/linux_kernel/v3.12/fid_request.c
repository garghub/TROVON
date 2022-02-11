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
GOTO ( V_43 , V_15 ) ;
V_11 = F_13 ( & V_10 -> V_20 , & V_22 ) ;
* V_4 = * V_11 ;
if ( ! F_14 ( V_4 ) ) {
F_15 ( L_1
V_44 L_2 , V_2 -> V_45 , F_16 ( V_4 ) ) ;
GOTO ( V_43 , V_15 = - V_46 ) ;
}
if ( F_17 ( V_4 ) ) {
F_15 ( L_3
V_44 L_4 , V_2 -> V_45 , F_16 ( V_4 ) ) ;
GOTO ( V_43 , V_15 = - V_46 ) ;
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
F_15 ( L_8
L_9 , V_2 -> V_45 , V_15 ) ;
return V_15 ;
} else {
F_26 ( V_38 , L_10 V_44 L_2 ,
V_2 -> V_45 , F_16 ( & V_2 -> V_24 ) ) ;
}
} else {
V_15 = 0 ;
}
F_25 ( ! F_17 ( & V_2 -> V_24 ) ) ;
* V_54 = V_2 -> V_24 . V_55 ;
V_2 -> V_24 . V_55 += 1 ;
F_26 ( V_38 , L_11 V_56 L_4 , V_2 -> V_45 ,
* V_54 ) ;
return V_15 ;
}
static int F_27 ( struct V_1 * V_2 ,
T_3 * V_57 )
{
if ( V_2 -> V_58 ) {
F_28 ( & V_2 -> V_59 , V_57 ) ;
F_29 ( V_60 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_30 ( V_57 , V_60 ) ;
F_21 ( & V_2 -> V_49 ) ;
F_31 ( & V_2 -> V_59 , V_57 ) ;
F_29 ( V_61 ) ;
return - V_53 ;
}
++ V_2 -> V_58 ;
F_22 ( & V_2 -> V_49 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_58 == 1 ) ;
F_21 ( & V_2 -> V_49 ) ;
-- V_2 -> V_58 ;
F_33 ( & V_2 -> V_59 ) ;
}
int F_34 ( const struct V_47 * V_48 ,
struct V_1 * V_2 , T_2 * V_54 )
{
T_3 V_57 ;
int V_15 ;
F_25 ( V_54 != NULL ) ;
F_21 ( & V_2 -> V_49 ) ;
F_35 ( & V_57 ) ;
while ( 1 ) {
V_15 = F_27 ( V_2 , & V_57 ) ;
if ( V_15 == 0 )
break;
}
V_15 = F_24 ( V_48 , V_2 , V_54 ) ;
if ( V_15 ) {
F_15 ( L_12
L_9 , V_2 -> V_45 , V_15 ) ;
F_32 ( V_2 ) ;
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
F_26 ( V_38 , L_13
L_14 V_62 L_15 , V_2 -> V_45 , * V_54 ) ;
if ( V_2 -> V_25 == V_26 )
V_2 -> V_63 . V_64 = V_65 ;
else
V_2 -> V_63 . V_64 = V_66 ;
V_2 -> V_63 . V_67 = * V_54 ;
V_2 -> V_63 . V_68 = 0 ;
F_32 ( V_2 ) ;
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
int F_36 ( const struct V_47 * V_48 ,
struct V_1 * V_2 , struct V_69 * V_70 )
{
T_3 V_57 ;
int V_15 ;
F_25 ( V_2 != NULL ) ;
F_25 ( V_70 != NULL ) ;
F_35 ( & V_57 ) ;
F_21 ( & V_2 -> V_49 ) ;
if ( F_37 ( V_71 ) )
V_2 -> V_63 . V_64 = V_2 -> V_72 ;
while ( 1 ) {
T_2 V_54 ;
if ( ! F_38 ( & V_2 -> V_63 ) &&
F_39 ( & V_2 -> V_63 ) < V_2 -> V_72 ) {
V_2 -> V_63 . V_64 += 1 ;
V_15 = 0 ;
break;
}
V_15 = F_27 ( V_2 , & V_57 ) ;
if ( V_15 )
continue;
V_15 = F_24 ( V_48 , V_2 , & V_54 ) ;
if ( V_15 ) {
F_15 ( L_12
L_9 , V_2 -> V_45 , V_15 ) ;
F_32 ( V_2 ) ;
F_22 ( & V_2 -> V_49 ) ;
return V_15 ;
}
F_26 ( V_38 , L_16
L_14 V_62 L_15 , V_2 -> V_45 , V_54 ) ;
V_2 -> V_63 . V_64 = V_73 ;
V_2 -> V_63 . V_67 = V_54 ;
V_2 -> V_63 . V_68 = 0 ;
V_15 = 1 ;
F_32 ( V_2 ) ;
break;
}
* V_70 = V_2 -> V_63 ;
F_22 ( & V_2 -> V_49 ) ;
F_26 ( V_38 , L_17 V_74 L_2 , V_2 -> V_45 , F_40 ( V_70 ) ) ;
return V_15 ;
}
void F_41 ( struct V_1 * V_2 )
{
T_3 V_57 ;
F_25 ( V_2 != NULL ) ;
F_35 ( & V_57 ) ;
F_21 ( & V_2 -> V_49 ) ;
while ( V_2 -> V_58 ) {
F_28 ( & V_2 -> V_59 , & V_57 ) ;
F_29 ( V_60 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_30 ( & V_57 , V_60 ) ;
F_21 ( & V_2 -> V_49 ) ;
F_31 ( & V_2 -> V_59 , & V_57 ) ;
F_29 ( V_61 ) ;
}
F_42 ( & V_2 -> V_63 ) ;
V_2 -> V_24 . V_23 = - 1 ;
F_5 ( & V_2 -> V_24 ) ;
F_22 ( & V_2 -> V_49 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
#ifdef F_44
if ( V_2 -> V_75 ) {
if ( ! F_45 ( V_2 -> V_75 ) )
F_46 ( & V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
#endif
}
static int F_47 ( struct V_1 * V_2 )
{
#ifdef F_44
int V_15 ;
V_2 -> V_75 = F_48 ( V_2 -> V_45 ,
V_76 ,
NULL , NULL ) ;
if ( F_45 ( V_2 -> V_75 ) ) {
F_15 ( L_18 ,
V_2 -> V_45 ) ;
V_15 = F_49 ( V_2 -> V_75 ) ;
return V_15 ;
}
V_15 = F_50 ( V_2 -> V_75 ,
V_77 , V_2 ) ;
if ( V_15 ) {
F_15 ( L_19
L_20 , V_2 -> V_45 , V_15 ) ;
GOTO ( V_78 , V_15 ) ;
}
return 0 ;
V_78:
F_43 ( V_2 ) ;
return V_15 ;
#else
return 0 ;
#endif
}
int F_51 ( struct V_1 * V_2 ,
struct V_7 * exp ,
enum V_79 type ,
const char * V_80 ,
struct V_81 * V_82 )
{
int V_15 ;
F_25 ( V_2 != NULL ) ;
F_25 ( V_80 != NULL ) ;
V_2 -> V_50 = V_82 ;
V_2 -> V_25 = type ;
F_52 ( & V_2 -> V_49 ) ;
if ( type == V_26 )
V_2 -> V_72 = V_65 ;
else
V_2 -> V_72 = V_66 ;
F_53 ( & V_2 -> V_59 ) ;
F_41 ( V_2 ) ;
if ( exp != NULL )
V_2 -> V_8 = F_54 ( exp ) ;
else if ( type == V_26 )
F_25 ( V_2 -> V_50 != NULL ) ;
snprintf ( V_2 -> V_45 , sizeof( V_2 -> V_45 ) ,
L_21 , V_80 ) ;
V_15 = F_47 ( V_2 ) ;
if ( V_15 )
F_55 ( V_2 ) ;
return V_15 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
if ( V_2 -> V_8 != NULL ) {
F_56 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
V_2 -> V_50 = NULL ;
}
int F_57 ( struct V_83 * V_84 ,
struct V_7 * exp , enum V_79 type )
{
struct V_85 * V_41 = & V_84 -> V_40 . V_41 ;
char * V_80 ;
int V_15 ;
F_58 ( V_41 -> V_86 ) ;
if ( V_41 -> V_86 == NULL )
return - V_19 ;
F_59 ( V_80 , V_87 + 5 ) ;
if ( V_80 == NULL )
GOTO ( V_88 , V_15 = - V_19 ) ;
snprintf ( V_80 , V_87 + 5 , L_21 , V_84 -> V_89 ) ;
V_15 = F_51 ( V_41 -> V_86 , exp , type , V_80 , NULL ) ;
F_60 ( V_80 , V_87 + 5 ) ;
if ( V_15 )
GOTO ( V_88 , V_15 ) ;
return V_15 ;
V_88:
F_61 ( V_41 -> V_86 ) ;
V_41 -> V_86 = NULL ;
return V_15 ;
}
int F_62 ( struct V_83 * V_84 )
{
struct V_85 * V_41 = & V_84 -> V_40 . V_41 ;
if ( V_41 -> V_86 != NULL ) {
F_55 ( V_41 -> V_86 ) ;
F_61 ( V_41 -> V_86 ) ;
V_41 -> V_86 = NULL ;
}
return 0 ;
}
static int T_4 F_63 ( void )
{
V_76 = F_48 ( V_90 ,
V_91 ,
NULL , NULL ) ;
if ( F_45 ( V_76 ) )
return F_49 ( V_76 ) ;
return 0 ;
}
static void T_5 F_64 ( void )
{
if ( V_76 != NULL && ! F_45 ( V_76 ) ) {
F_46 ( & V_76 ) ;
V_76 = NULL ;
}
}
