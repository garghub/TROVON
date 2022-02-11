static T_1 F_1 ( T_2 V_1 , char * V_2 )
{
struct V_3 V_4 = { V_5 , NULL } ;
int V_6 ;
V_6 = F_2 ( V_1 , V_7 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = sprintf ( V_2 , L_1 , ( char * ) V_4 . V_8 ) ;
F_3 ( V_4 . V_8 ) ;
return V_6 ;
}
static T_1 F_4 ( struct V_9 * V_10 , char * V_2 )
{
return F_1 ( V_10 -> V_1 , V_2 ) ;
}
static T_1 F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_2 )
{
struct V_9 * V_10 = F_6 ( V_12 ) ;
struct V_15 * V_16 = F_7 ( V_14 ) ;
return V_16 -> V_17 ? V_16 -> V_17 ( V_10 , V_2 ) : - V_18 ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = F_6 ( V_12 ) ;
F_9 ( & V_10 -> V_19 ) ;
}
static void F_10 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = & V_21 -> V_24 ;
struct V_9 * V_10 ;
if ( F_11 ( V_23 ) )
return;
F_12 (dn, list, sibling) {
int V_25 ;
F_13 ( & V_10 -> V_19 ) ;
V_25 = F_14 ( & V_10 -> V_12 , & V_26 ,
V_12 , L_2 , V_10 -> V_27 ) ;
if ( V_25 )
F_15 ( V_10 -> V_1 , L_3 , V_25 ) ;
else
F_10 ( & V_10 -> V_12 , & V_10 -> V_21 ) ;
}
}
static void F_16 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = & V_21 -> V_24 ;
struct V_9 * V_10 ;
if ( F_11 ( V_23 ) )
return;
F_17 (dn, list, sibling) {
F_16 ( & V_10 -> V_21 ) ;
F_18 ( & V_10 -> V_12 ) ;
}
}
static int F_19 ( struct V_28 * V_29 , char * V_30 ,
int V_31 )
{
int V_32 ;
int V_33 ;
struct V_34 * V_35 ;
V_33 = 0 ;
F_12 (id, &acpi_dev->pnp.ids, list)
if ( strcmp ( V_35 -> V_35 , V_36 ) )
V_33 ++ ;
if ( ! V_33 )
return 0 ;
V_32 = snprintf ( V_30 , V_31 , L_4 ) ;
if ( V_32 <= 0 )
return V_32 ;
V_31 -= V_32 ;
F_12 (id, &acpi_dev->pnp.ids, list) {
if ( ! strcmp ( V_35 -> V_35 , V_36 ) )
continue;
V_33 = snprintf ( & V_30 [ V_32 ] , V_31 , L_5 , V_35 -> V_35 ) ;
if ( V_33 < 0 )
return - V_37 ;
if ( V_33 >= V_31 )
return - V_38 ;
V_32 += V_33 ;
V_31 -= V_33 ;
}
V_30 [ V_32 ] = '\0' ;
return V_32 ;
}
static int F_20 ( struct V_28 * V_29 , char * V_30 ,
int V_31 )
{
struct V_3 V_2 = { V_5 } ;
const union V_39 * V_40 , * V_41 ;
int V_32 , V_33 ;
int V_42 , V_43 ;
char * V_44 ;
F_2 ( V_29 -> V_1 , V_45 , & V_2 ) ;
for ( V_44 = V_2 . V_8 ; * V_44 != '\0' ; V_44 ++ )
* V_44 = tolower ( * V_44 ) ;
V_32 = snprintf ( V_30 , V_31 , L_6 , ( char * ) V_2 . V_8 ) ;
F_21 ( V_2 . V_8 ) ;
if ( V_32 <= 0 )
return V_32 ;
V_40 = V_29 -> V_21 . V_40 ;
if ( V_40 -> type == V_46 ) {
V_43 = V_40 -> V_47 . V_33 ;
V_41 = V_40 -> V_47 . V_48 ;
} else {
V_43 = 1 ;
V_41 = V_40 ;
}
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ , V_41 ++ ) {
V_33 = snprintf ( & V_30 [ V_32 ] , V_31 , L_7 ,
V_41 -> string . V_8 ) ;
if ( V_33 < 0 )
return - V_37 ;
if ( V_33 >= V_31 )
return - V_38 ;
V_32 += V_33 ;
V_31 -= V_33 ;
}
V_30 [ V_32 ] = '\0' ;
return V_32 ;
}
int F_22 ( struct V_28 * V_49 ,
struct V_50 * V_51 )
{
int V_32 ;
if ( ! V_49 )
return - V_52 ;
if ( F_11 ( & V_49 -> V_53 . V_54 ) )
return 0 ;
if ( F_23 ( V_51 , L_8 ) )
return - V_38 ;
V_32 = F_19 ( V_49 , & V_51 -> V_2 [ V_51 -> V_55 - 1 ] ,
sizeof( V_51 -> V_2 ) - V_51 -> V_55 ) ;
if ( V_32 < 0 )
return V_32 ;
V_51 -> V_55 += V_32 ;
if ( ! V_49 -> V_21 . V_40 )
return 0 ;
if ( V_32 > 0 && F_23 ( V_51 , L_8 ) )
return - V_38 ;
V_32 = F_20 ( V_49 , & V_51 -> V_2 [ V_51 -> V_55 - 1 ] ,
sizeof( V_51 -> V_2 ) - V_51 -> V_55 ) ;
if ( V_32 < 0 )
return V_32 ;
V_51 -> V_55 += V_32 ;
return 0 ;
}
int F_24 ( struct V_56 * V_57 , struct V_50 * V_51 )
{
return F_22 ( F_25 ( V_57 ) , V_51 ) ;
}
static int F_26 ( struct V_28 * V_49 , char * V_2 , int V_31 )
{
int V_32 , V_33 ;
if ( ! V_49 )
return - V_52 ;
if ( F_11 ( & V_49 -> V_53 . V_54 ) )
return 0 ;
V_32 = F_19 ( V_49 , V_2 , V_31 - 1 ) ;
if ( V_32 < 0 ) {
return V_32 ;
} else if ( V_32 > 0 ) {
V_2 [ V_32 ++ ] = '\n' ;
V_31 -= V_32 ;
}
if ( ! V_49 -> V_21 . V_40 )
return V_32 ;
V_33 = F_20 ( V_49 , V_2 + V_32 , V_31 - 1 ) ;
if ( V_33 < 0 ) {
return V_33 ;
} else if ( V_33 > 0 ) {
V_32 += V_33 ;
V_2 [ V_32 ++ ] = '\n' ;
}
return V_32 ;
}
int F_27 ( struct V_56 * V_57 , char * V_2 , int V_31 )
{
return F_26 ( F_25 ( V_57 ) , V_2 , V_31 ) ;
}
static T_1
F_28 ( struct V_56 * V_57 , struct V_58 * V_14 , char * V_2 ) {
return F_26 ( F_29 ( V_57 ) , V_2 , 1024 ) ;
}
static T_1 F_30 ( struct V_56 * V_57 ,
struct V_58 * V_14 , char * V_2 )
{
struct V_28 * V_49 = F_29 ( V_57 ) ;
int V_59 ;
int V_25 ;
V_25 = F_31 ( V_49 , & V_59 ) ;
if ( V_25 )
return V_25 ;
return sprintf ( V_2 , L_1 , F_32 ( V_59 ) ) ;
}
static T_1 F_33 ( struct V_56 * V_57 ,
struct V_58 * V_14 , char * V_2 )
{
struct V_28 * V_49 = F_29 ( V_57 ) ;
return sprintf ( V_2 , L_1 , F_32 ( V_49 -> V_60 . V_59 ) ) ;
}
static T_1
F_34 ( struct V_56 * V_61 , struct V_58 * V_14 ,
const char * V_2 , T_3 V_33 )
{
struct V_28 * V_28 = F_29 ( V_61 ) ;
T_4 V_62 ;
T_5 V_63 ;
if ( ! V_33 || V_2 [ 0 ] != '1' )
return - V_37 ;
if ( ( ! V_28 -> V_64 || ! V_28 -> V_64 -> V_65 . V_66 )
&& ! V_28 -> V_67 )
return - V_52 ;
V_63 = F_35 ( V_28 -> V_1 , & V_62 ) ;
if ( F_36 ( V_63 ) || ! V_28 -> V_68 . V_69 )
return - V_52 ;
F_37 ( & V_28 -> V_57 ) ;
V_63 = F_38 ( V_28 , V_70 ) ;
if ( F_39 ( V_63 ) )
return V_33 ;
F_40 ( & V_28 -> V_57 ) ;
F_41 ( V_28 -> V_1 , V_70 ,
V_71 , NULL ) ;
return V_63 == V_72 ? - V_38 : - V_73 ;
}
static T_1
F_42 ( struct V_56 * V_57 , struct V_58 * V_14 , char * V_2 ) {
struct V_28 * V_29 = F_29 ( V_57 ) ;
return sprintf ( V_2 , L_1 , F_43 ( V_29 ) ) ;
}
static T_1 F_44 ( struct V_56 * V_57 ,
struct V_58 * V_14 , char * V_2 )
{
struct V_28 * V_29 = F_29 ( V_57 ) ;
return sprintf ( V_2 , L_1 , V_29 -> V_53 . V_74 ) ;
}
static T_1 F_45 ( struct V_56 * V_57 ,
struct V_58 * V_14 , char * V_2 )
{
struct V_28 * V_29 = F_29 ( V_57 ) ;
return sprintf ( V_2 , L_9 ,
( unsigned int ) ( V_29 -> V_53 . V_75 ) ) ;
}
static T_1 F_46 ( struct V_56 * V_57 ,
struct V_58 * V_14 , char * V_2 )
{
struct V_28 * V_29 = F_29 ( V_57 ) ;
return F_1 ( V_29 -> V_1 , V_2 ) ;
}
static T_1 F_47 ( struct V_56 * V_57 ,
struct V_58 * V_14 ,
char * V_2 ) {
struct V_28 * V_29 = F_29 ( V_57 ) ;
int V_6 ;
if ( V_29 -> V_53 . V_76 == NULL )
return 0 ;
V_6 = F_48 (
( V_77 * ) V_29 -> V_53 . V_76 -> V_78 . V_8 ,
V_29 -> V_53 . V_76 -> V_78 . V_79 ,
V_80 , V_2 ,
V_81 ) ;
V_2 [ V_6 ++ ] = '\n' ;
return V_6 ;
}
static T_1
F_49 ( struct V_56 * V_57 , struct V_58 * V_14 ,
char * V_2 ) {
struct V_28 * V_29 = F_29 ( V_57 ) ;
T_5 V_63 ;
unsigned long long V_82 ;
V_63 = F_50 ( V_29 -> V_1 , L_10 , NULL , & V_82 ) ;
if ( F_36 ( V_63 ) )
return - V_52 ;
return sprintf ( V_2 , L_11 , V_82 ) ;
}
static T_1 F_51 ( struct V_56 * V_57 , struct V_58 * V_14 ,
char * V_2 ) {
struct V_28 * V_29 = F_29 ( V_57 ) ;
T_5 V_63 ;
unsigned long long V_83 ;
V_63 = F_50 ( V_29 -> V_1 , L_12 , NULL , & V_83 ) ;
if ( F_36 ( V_63 ) )
return - V_52 ;
return sprintf ( V_2 , L_11 , V_83 ) ;
}
int F_52 ( struct V_28 * V_57 )
{
struct V_3 V_78 = { V_5 , NULL } ;
T_5 V_63 ;
int V_6 = 0 ;
if ( V_57 -> V_1 ) {
V_6 = F_53 ( & V_57 -> V_57 , & V_84 ) ;
if ( V_6 )
goto V_85;
}
if ( ! F_11 ( & V_57 -> V_53 . V_54 ) ) {
V_6 = F_53 ( & V_57 -> V_57 , & V_86 ) ;
if ( V_6 )
goto V_85;
V_6 = F_53 ( & V_57 -> V_57 , & V_87 ) ;
if ( V_6 )
goto V_85;
}
if ( F_54 ( V_57 -> V_1 , L_13 ) ) {
V_63 = F_55 ( V_57 -> V_1 , L_13 ,
NULL , & V_78 ) ;
if ( F_36 ( V_63 ) )
V_78 . V_8 = NULL ;
V_57 -> V_53 . V_76 = V_78 . V_8 ;
V_6 = F_53 ( & V_57 -> V_57 , & V_88 ) ;
if ( V_6 )
goto V_85;
}
if ( V_57 -> V_53 . type . V_75 )
V_6 = F_53 ( & V_57 -> V_57 , & V_89 ) ;
if ( V_57 -> V_53 . V_74 )
V_6 = F_53 ( & V_57 -> V_57 , & V_90 ) ;
if ( F_54 ( V_57 -> V_1 , L_10 ) ) {
V_6 = F_53 ( & V_57 -> V_57 , & V_91 ) ;
if ( V_6 )
goto V_85;
}
if ( F_54 ( V_57 -> V_1 , L_12 ) ) {
V_6 = F_53 ( & V_57 -> V_57 , & V_92 ) ;
if ( V_6 )
goto V_85;
}
if ( F_54 ( V_57 -> V_1 , L_14 ) ) {
V_6 = F_53 ( & V_57 -> V_57 , & V_93 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_57 -> V_68 . V_94 ) {
V_6 = F_53 ( & V_57 -> V_57 , & V_95 ) ;
if ( V_6 )
return V_6 ;
if ( V_57 -> V_60 . V_68 . V_96 )
V_6 = F_53 ( & V_57 -> V_57 ,
& V_97 ) ;
}
F_10 ( & V_57 -> V_57 . V_12 , & V_57 -> V_21 ) ;
V_85:
return V_6 ;
}
void F_56 ( struct V_28 * V_57 )
{
F_16 ( & V_57 -> V_21 ) ;
if ( V_57 -> V_68 . V_94 ) {
F_57 ( & V_57 -> V_57 , & V_95 ) ;
if ( V_57 -> V_60 . V_68 . V_96 )
F_57 ( & V_57 -> V_57 ,
& V_97 ) ;
}
if ( F_54 ( V_57 -> V_1 , L_13 ) ) {
F_3 ( V_57 -> V_53 . V_76 ) ;
F_57 ( & V_57 -> V_57 , & V_88 ) ;
}
if ( F_54 ( V_57 -> V_1 , L_14 ) )
F_57 ( & V_57 -> V_57 , & V_93 ) ;
if ( F_54 ( V_57 -> V_1 , L_10 ) )
F_57 ( & V_57 -> V_57 , & V_91 ) ;
if ( V_57 -> V_53 . V_74 )
F_57 ( & V_57 -> V_57 , & V_90 ) ;
if ( V_57 -> V_53 . type . V_75 )
F_57 ( & V_57 -> V_57 , & V_89 ) ;
F_57 ( & V_57 -> V_57 , & V_87 ) ;
F_57 ( & V_57 -> V_57 , & V_86 ) ;
if ( F_54 ( V_57 -> V_1 , L_12 ) )
F_57 ( & V_57 -> V_57 , & V_92 ) ;
if ( V_57 -> V_1 )
F_57 ( & V_57 -> V_57 , & V_84 ) ;
}
