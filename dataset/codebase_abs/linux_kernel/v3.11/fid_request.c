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
V_16 ;
V_10 = F_2 ( F_3 ( exp ) , & V_17 ,
V_18 , V_19 ) ;
if ( V_10 == NULL )
RETURN ( - V_20 ) ;
V_13 = F_4 ( & V_10 -> V_21 , & V_22 ) ;
* V_13 = V_5 ;
V_12 = F_4 ( & V_10 -> V_21 , & V_23 ) ;
F_5 ( V_12 ) ;
F_6 ( V_10 ) ;
V_12 -> V_24 = V_2 -> V_25 . V_24 ;
if ( V_2 -> V_26 == V_27 )
F_7 ( V_12 ) ;
else
F_8 ( V_12 ) ;
if ( V_5 == V_28 ) {
V_10 -> V_29 = V_30 ;
V_10 -> V_31 = V_32 ;
if ( V_2 -> V_26 == V_33 )
V_10 -> V_34 = V_10 -> V_35 = 1 ;
V_14 = V_36 ;
} else {
if ( V_2 -> V_26 == V_27 )
V_10 -> V_29 = V_37 ;
else
V_10 -> V_29 = V_38 ;
V_14 = V_39 ;
}
F_9 ( V_10 ) ;
if ( V_2 -> V_26 == V_27 )
F_10 ( exp -> V_40 -> V_41 . V_42 . V_43 , NULL ) ;
V_15 = F_11 ( V_10 ) ;
if ( V_2 -> V_26 == V_27 )
F_12 ( exp -> V_40 -> V_41 . V_42 . V_43 , NULL ) ;
if ( V_15 )
GOTO ( V_44 , V_15 ) ;
V_11 = F_13 ( & V_10 -> V_21 , & V_23 ) ;
* V_4 = * V_11 ;
if ( ! F_14 ( V_4 ) ) {
F_15 ( L_1
V_45 L_2 , V_2 -> V_46 , F_16 ( V_4 ) ) ;
GOTO ( V_44 , V_15 = - V_47 ) ;
}
if ( F_17 ( V_4 ) ) {
F_15 ( L_3
V_45 L_4 , V_2 -> V_46 , F_16 ( V_4 ) ) ;
GOTO ( V_44 , V_15 = - V_47 ) ;
}
F_18 ( V_14 , L_5 V_45 L_4 ,
V_2 -> V_46 , V_6 , F_16 ( V_4 ) ) ;
EXIT ;
V_44:
F_19 ( V_10 ) ;
return V_15 ;
}
int F_20 ( struct V_1 * V_2 ,
const struct V_48 * V_49 )
{
int V_15 ;
V_16 ;
F_21 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_51 ) {
F_22 ( V_49 != NULL ) ;
V_15 = F_23 ( V_2 -> V_51 , & V_2 -> V_25 ,
V_49 ) ;
} else {
if ( V_2 -> V_8 == NULL ) {
F_24 ( & V_2 -> V_50 ) ;
RETURN ( - V_52 ) ;
}
V_15 = F_1 ( V_2 , & V_2 -> V_25 ,
V_28 , L_6 ) ;
}
F_24 ( & V_2 -> V_50 ) ;
RETURN ( V_15 ) ;
}
static int F_25 ( const struct V_48 * V_49 ,
struct V_1 * V_2 )
{
int V_15 ;
V_16 ;
if ( V_2 -> V_51 ) {
F_22 ( V_49 != NULL ) ;
V_15 = F_26 ( V_2 -> V_51 , & V_2 -> V_25 , V_49 ) ;
} else {
do {
V_15 = F_1 ( V_2 , & V_2 -> V_25 ,
V_53 , L_7 ) ;
} while ( V_15 == - V_52 || V_15 == - V_54 );
}
RETURN ( V_15 ) ;
}
static int F_27 ( const struct V_48 * V_49 ,
struct V_1 * V_2 , T_2 * V_55 )
{
int V_15 ;
V_16 ;
F_22 ( F_14 ( & V_2 -> V_25 ) ) ;
if ( F_17 ( & V_2 -> V_25 ) ) {
V_15 = F_25 ( V_49 , V_2 ) ;
if ( V_15 ) {
F_15 ( L_8
L_9 , V_2 -> V_46 , V_15 ) ;
RETURN ( V_15 ) ;
} else {
F_28 ( V_39 , L_10 V_45 L_2 ,
V_2 -> V_46 , F_16 ( & V_2 -> V_25 ) ) ;
}
} else {
V_15 = 0 ;
}
F_22 ( ! F_17 ( & V_2 -> V_25 ) ) ;
* V_55 = V_2 -> V_25 . V_56 ;
V_2 -> V_25 . V_56 += 1 ;
F_28 ( V_39 , L_11 V_57 L_4 , V_2 -> V_46 ,
* V_55 ) ;
RETURN ( V_15 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
T_3 * V_58 )
{
if ( V_2 -> V_59 ) {
F_30 ( & V_2 -> V_60 , V_58 ) ;
F_31 ( V_61 ) ;
F_24 ( & V_2 -> V_50 ) ;
F_32 ( V_58 , V_61 ) ;
F_21 ( & V_2 -> V_50 ) ;
F_33 ( & V_2 -> V_60 , V_58 ) ;
F_31 ( V_62 ) ;
return - V_54 ;
}
++ V_2 -> V_59 ;
F_24 ( & V_2 -> V_50 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_59 == 1 ) ;
F_21 ( & V_2 -> V_50 ) ;
-- V_2 -> V_59 ;
F_35 ( & V_2 -> V_60 ) ;
}
int F_36 ( const struct V_48 * V_49 ,
struct V_1 * V_2 , T_2 * V_55 )
{
T_3 V_58 ;
int V_15 ;
F_22 ( V_55 != NULL ) ;
F_21 ( & V_2 -> V_50 ) ;
F_37 ( & V_58 ) ;
while ( 1 ) {
V_15 = F_29 ( V_2 , & V_58 ) ;
if ( V_15 == 0 )
break;
}
V_15 = F_27 ( V_49 , V_2 , V_55 ) ;
if ( V_15 ) {
F_15 ( L_12
L_9 , V_2 -> V_46 , V_15 ) ;
F_34 ( V_2 ) ;
F_24 ( & V_2 -> V_50 ) ;
return V_15 ;
}
F_28 ( V_39 , L_13
L_14 V_63 L_15 , V_2 -> V_46 , * V_55 ) ;
if ( V_2 -> V_26 == V_27 )
V_2 -> V_64 . V_65 = V_66 ;
else
V_2 -> V_64 . V_65 = V_67 ;
V_2 -> V_64 . V_68 = * V_55 ;
V_2 -> V_64 . V_69 = 0 ;
F_34 ( V_2 ) ;
F_24 ( & V_2 -> V_50 ) ;
return V_15 ;
}
int F_38 ( const struct V_48 * V_49 ,
struct V_1 * V_2 , struct V_70 * V_71 )
{
T_3 V_58 ;
int V_15 ;
V_16 ;
F_22 ( V_2 != NULL ) ;
F_22 ( V_71 != NULL ) ;
F_37 ( & V_58 ) ;
F_21 ( & V_2 -> V_50 ) ;
if ( F_39 ( V_72 ) )
V_2 -> V_64 . V_65 = V_2 -> V_73 ;
while ( 1 ) {
T_2 V_55 ;
if ( ! F_40 ( & V_2 -> V_64 ) &&
F_41 ( & V_2 -> V_64 ) < V_2 -> V_73 ) {
V_2 -> V_64 . V_65 += 1 ;
V_15 = 0 ;
break;
}
V_15 = F_29 ( V_2 , & V_58 ) ;
if ( V_15 )
continue;
V_15 = F_27 ( V_49 , V_2 , & V_55 ) ;
if ( V_15 ) {
F_15 ( L_12
L_9 , V_2 -> V_46 , V_15 ) ;
F_34 ( V_2 ) ;
F_24 ( & V_2 -> V_50 ) ;
RETURN ( V_15 ) ;
}
F_28 ( V_39 , L_16
L_14 V_63 L_15 , V_2 -> V_46 , V_55 ) ;
V_2 -> V_64 . V_65 = V_74 ;
V_2 -> V_64 . V_68 = V_55 ;
V_2 -> V_64 . V_69 = 0 ;
V_15 = 1 ;
F_34 ( V_2 ) ;
break;
}
* V_71 = V_2 -> V_64 ;
F_24 ( & V_2 -> V_50 ) ;
F_28 ( V_39 , L_17 V_75 L_2 , V_2 -> V_46 , F_42 ( V_71 ) ) ;
RETURN ( V_15 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
T_3 V_58 ;
F_22 ( V_2 != NULL ) ;
F_37 ( & V_58 ) ;
F_21 ( & V_2 -> V_50 ) ;
while ( V_2 -> V_59 ) {
F_30 ( & V_2 -> V_60 , & V_58 ) ;
F_31 ( V_61 ) ;
F_24 ( & V_2 -> V_50 ) ;
F_32 ( & V_58 , V_61 ) ;
F_21 ( & V_2 -> V_50 ) ;
F_33 ( & V_2 -> V_60 , & V_58 ) ;
F_31 ( V_62 ) ;
}
F_44 ( & V_2 -> V_64 ) ;
V_2 -> V_25 . V_24 = - 1 ;
F_5 ( & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_50 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_15 ;
V_16 ;
V_2 -> V_76 = F_46 ( V_2 -> V_46 ,
V_77 ,
NULL , NULL ) ;
if ( F_47 ( V_2 -> V_76 ) ) {
F_15 ( L_18 ,
V_2 -> V_46 ) ;
V_15 = F_48 ( V_2 -> V_76 ) ;
RETURN ( V_15 ) ;
}
V_15 = F_49 ( V_2 -> V_76 ,
V_78 , V_2 ) ;
if ( V_15 ) {
F_15 ( L_19
L_20 , V_2 -> V_46 , V_15 ) ;
GOTO ( V_79 , V_15 ) ;
}
RETURN ( 0 ) ;
V_79:
F_50 ( V_2 ) ;
return V_15 ;
}
static void F_50 ( struct V_1 * V_2 )
{
V_16 ;
if ( V_2 -> V_76 ) {
if ( ! F_47 ( V_2 -> V_76 ) )
F_51 ( & V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
EXIT ;
}
static int F_45 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
return;
}
int F_52 ( struct V_1 * V_2 ,
struct V_7 * exp ,
enum V_80 type ,
const char * V_81 ,
struct V_82 * V_83 )
{
int V_15 ;
V_16 ;
F_22 ( V_2 != NULL ) ;
F_22 ( V_81 != NULL ) ;
V_2 -> V_51 = V_83 ;
V_2 -> V_26 = type ;
F_53 ( & V_2 -> V_50 ) ;
if ( type == V_27 )
V_2 -> V_73 = V_66 ;
else
V_2 -> V_73 = V_67 ;
F_54 ( & V_2 -> V_60 ) ;
F_43 ( V_2 ) ;
if ( exp != NULL )
V_2 -> V_8 = F_55 ( exp ) ;
else if ( type == V_27 )
F_22 ( V_2 -> V_51 != NULL ) ;
snprintf ( V_2 -> V_46 , sizeof( V_2 -> V_46 ) ,
L_21 , V_81 ) ;
V_15 = F_45 ( V_2 ) ;
if ( V_15 )
F_56 ( V_2 ) ;
RETURN ( V_15 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
V_16 ;
F_50 ( V_2 ) ;
if ( V_2 -> V_8 != NULL ) {
F_57 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
V_2 -> V_51 = NULL ;
EXIT ;
}
