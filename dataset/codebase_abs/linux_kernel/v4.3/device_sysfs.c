static int F_1 ( struct V_1 * V_2 , char * V_3 ,
int V_4 )
{
int V_5 ;
int V_6 ;
struct V_7 * V_8 ;
V_6 = 0 ;
F_2 (id, &acpi_dev->pnp.ids, list)
if ( strcmp ( V_8 -> V_8 , V_9 ) )
V_6 ++ ;
if ( ! V_6 )
return 0 ;
V_5 = snprintf ( V_3 , V_4 , L_1 ) ;
if ( V_5 <= 0 )
return V_5 ;
V_4 -= V_5 ;
F_2 (id, &acpi_dev->pnp.ids, list) {
if ( ! strcmp ( V_8 -> V_8 , V_9 ) )
continue;
V_6 = snprintf ( & V_3 [ V_5 ] , V_4 , L_2 , V_8 -> V_8 ) ;
if ( V_6 < 0 )
return - V_10 ;
if ( V_6 >= V_4 )
return - V_11 ;
V_5 += V_6 ;
V_4 -= V_6 ;
}
V_3 [ V_5 ] = '\0' ;
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 , char * V_3 ,
int V_4 )
{
struct V_12 V_13 = { V_14 } ;
const union V_15 * V_16 , * V_17 ;
int V_5 , V_6 ;
int V_18 , V_19 ;
char * V_20 ;
F_4 ( V_2 -> V_21 , V_22 , & V_13 ) ;
for ( V_20 = V_13 . V_23 ; * V_20 != '\0' ; V_20 ++ )
* V_20 = tolower ( * V_20 ) ;
V_5 = snprintf ( V_3 , V_4 , L_3 , ( char * ) V_13 . V_23 ) ;
F_5 ( V_13 . V_23 ) ;
if ( V_5 <= 0 )
return V_5 ;
V_16 = V_2 -> V_24 . V_16 ;
if ( V_16 -> type == V_25 ) {
V_19 = V_16 -> V_26 . V_6 ;
V_17 = V_16 -> V_26 . V_27 ;
} else {
V_19 = 1 ;
V_17 = V_16 ;
}
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ , V_17 ++ ) {
V_6 = snprintf ( & V_3 [ V_5 ] , V_4 , L_4 ,
V_17 -> string . V_23 ) ;
if ( V_6 < 0 )
return - V_10 ;
if ( V_6 >= V_4 )
return - V_11 ;
V_5 += V_6 ;
V_4 -= V_6 ;
}
V_3 [ V_5 ] = '\0' ;
return V_5 ;
}
int F_6 ( struct V_1 * V_28 ,
struct V_29 * V_30 )
{
int V_5 ;
if ( ! V_28 )
return - V_31 ;
if ( F_7 ( & V_28 -> V_32 . V_33 ) )
return 0 ;
if ( F_8 ( V_30 , L_5 ) )
return - V_11 ;
V_5 = F_1 ( V_28 , & V_30 -> V_13 [ V_30 -> V_34 - 1 ] ,
sizeof( V_30 -> V_13 ) - V_30 -> V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
V_30 -> V_34 += V_5 ;
if ( ! V_28 -> V_24 . V_16 )
return 0 ;
if ( V_5 > 0 && F_8 ( V_30 , L_5 ) )
return - V_11 ;
V_5 = F_3 ( V_28 , & V_30 -> V_13 [ V_30 -> V_34 - 1 ] ,
sizeof( V_30 -> V_13 ) - V_30 -> V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
V_30 -> V_34 += V_5 ;
return 0 ;
}
int F_9 ( struct V_35 * V_36 , struct V_29 * V_30 )
{
return F_6 ( F_10 ( V_36 ) , V_30 ) ;
}
static int F_11 ( struct V_1 * V_28 , char * V_13 , int V_4 )
{
int V_5 , V_6 ;
if ( ! V_28 )
return - V_31 ;
if ( F_7 ( & V_28 -> V_32 . V_33 ) )
return 0 ;
V_5 = F_1 ( V_28 , V_13 , V_4 - 1 ) ;
if ( V_5 < 0 ) {
return V_5 ;
} else if ( V_5 > 0 ) {
V_13 [ V_5 ++ ] = '\n' ;
V_4 -= V_5 ;
}
if ( ! V_28 -> V_24 . V_16 )
return V_5 ;
V_6 = F_3 ( V_28 , V_13 + V_5 , V_4 - 1 ) ;
if ( V_6 < 0 ) {
return V_6 ;
} else if ( V_6 > 0 ) {
V_5 += V_6 ;
V_13 [ V_5 ++ ] = '\n' ;
}
return V_5 ;
}
int F_12 ( struct V_35 * V_36 , char * V_13 , int V_4 )
{
return F_11 ( F_10 ( V_36 ) , V_13 , V_4 ) ;
}
static T_1
F_13 ( struct V_35 * V_36 , struct V_37 * V_38 , char * V_13 ) {
return F_11 ( F_14 ( V_36 ) , V_13 , 1024 ) ;
}
static T_1 F_15 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_13 )
{
struct V_1 * V_28 = F_14 ( V_36 ) ;
int V_39 ;
int V_40 ;
V_40 = F_16 ( V_28 , & V_39 ) ;
if ( V_40 )
return V_40 ;
return sprintf ( V_13 , L_6 , F_17 ( V_39 ) ) ;
}
static T_1 F_18 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_13 )
{
struct V_1 * V_28 = F_14 ( V_36 ) ;
return sprintf ( V_13 , L_6 , F_17 ( V_28 -> V_41 . V_39 ) ) ;
}
static T_1
F_19 ( struct V_35 * V_42 , struct V_37 * V_38 ,
const char * V_13 , T_2 V_6 )
{
struct V_1 * V_1 = F_14 ( V_42 ) ;
T_3 V_43 ;
T_4 V_44 ;
if ( ! V_6 || V_13 [ 0 ] != '1' )
return - V_10 ;
if ( ( ! V_1 -> V_45 || ! V_1 -> V_45 -> V_46 . V_47 )
&& ! V_1 -> V_48 )
return - V_31 ;
V_44 = F_20 ( V_1 -> V_21 , & V_43 ) ;
if ( F_21 ( V_44 ) || ! V_1 -> V_49 . V_50 )
return - V_31 ;
F_22 ( & V_1 -> V_36 ) ;
V_44 = F_23 ( V_1 , V_51 ) ;
if ( F_24 ( V_44 ) )
return V_6 ;
F_25 ( & V_1 -> V_36 ) ;
F_26 ( V_1 -> V_21 , V_51 ,
V_52 , NULL ) ;
return V_44 == V_53 ? - V_11 : - V_54 ;
}
static T_1
F_27 ( struct V_35 * V_36 , struct V_37 * V_38 , char * V_13 ) {
struct V_1 * V_2 = F_14 ( V_36 ) ;
return sprintf ( V_13 , L_6 , F_28 ( V_2 ) ) ;
}
static T_1 F_29 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_13 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
return sprintf ( V_13 , L_6 , V_2 -> V_32 . V_55 ) ;
}
static T_1 F_30 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_13 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
return sprintf ( V_13 , L_7 ,
( unsigned int ) ( V_2 -> V_32 . V_56 ) ) ;
}
static T_1
F_31 ( struct V_35 * V_36 , struct V_37 * V_38 , char * V_13 ) {
struct V_1 * V_2 = F_14 ( V_36 ) ;
struct V_12 V_57 = { V_14 , NULL } ;
int V_58 ;
V_58 = F_4 ( V_2 -> V_21 , V_59 , & V_57 ) ;
if ( V_58 )
goto V_60;
V_58 = sprintf ( V_13 , L_6 , ( char * ) V_57 . V_23 ) ;
F_32 ( V_57 . V_23 ) ;
V_60:
return V_58 ;
}
static T_1 F_33 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_13 ) {
struct V_1 * V_2 = F_14 ( V_36 ) ;
int V_58 ;
if ( V_2 -> V_32 . V_61 == NULL )
return 0 ;
V_58 = F_34 (
( V_62 * ) V_2 -> V_32 . V_61 -> V_63 . V_23 ,
V_2 -> V_32 . V_61 -> V_63 . V_64 ,
V_65 , V_13 ,
V_66 ) ;
V_13 [ V_58 ++ ] = '\n' ;
return V_58 ;
}
static T_1
F_35 ( struct V_35 * V_36 , struct V_37 * V_38 ,
char * V_13 ) {
struct V_1 * V_2 = F_14 ( V_36 ) ;
T_4 V_44 ;
unsigned long long V_67 ;
V_44 = F_36 ( V_2 -> V_21 , L_8 , NULL , & V_67 ) ;
if ( F_21 ( V_44 ) )
return - V_31 ;
return sprintf ( V_13 , L_9 , V_67 ) ;
}
static T_1 F_37 ( struct V_35 * V_36 , struct V_37 * V_38 ,
char * V_13 ) {
struct V_1 * V_2 = F_14 ( V_36 ) ;
T_4 V_44 ;
unsigned long long V_68 ;
V_44 = F_36 ( V_2 -> V_21 , L_10 , NULL , & V_68 ) ;
if ( F_21 ( V_44 ) )
return - V_31 ;
return sprintf ( V_13 , L_9 , V_68 ) ;
}
int F_38 ( struct V_1 * V_36 )
{
struct V_12 V_63 = { V_14 , NULL } ;
T_4 V_44 ;
int V_58 = 0 ;
if ( V_36 -> V_21 ) {
V_58 = F_39 ( & V_36 -> V_36 , & V_69 ) ;
if ( V_58 )
goto V_60;
}
if ( ! F_7 ( & V_36 -> V_32 . V_33 ) ) {
V_58 = F_39 ( & V_36 -> V_36 , & V_70 ) ;
if ( V_58 )
goto V_60;
V_58 = F_39 ( & V_36 -> V_36 , & V_71 ) ;
if ( V_58 )
goto V_60;
}
if ( F_40 ( V_36 -> V_21 , L_11 ) ) {
V_44 = F_41 ( V_36 -> V_21 , L_11 ,
NULL , & V_63 ) ;
if ( F_21 ( V_44 ) )
V_63 . V_23 = NULL ;
V_36 -> V_32 . V_61 = V_63 . V_23 ;
V_58 = F_39 ( & V_36 -> V_36 , & V_72 ) ;
if ( V_58 )
goto V_60;
}
if ( V_36 -> V_32 . type . V_56 )
V_58 = F_39 ( & V_36 -> V_36 , & V_73 ) ;
if ( V_36 -> V_32 . V_55 )
V_58 = F_39 ( & V_36 -> V_36 , & V_74 ) ;
if ( F_40 ( V_36 -> V_21 , L_8 ) ) {
V_58 = F_39 ( & V_36 -> V_36 , & V_75 ) ;
if ( V_58 )
goto V_60;
}
if ( F_40 ( V_36 -> V_21 , L_10 ) ) {
V_58 = F_39 ( & V_36 -> V_36 , & V_76 ) ;
if ( V_58 )
goto V_60;
}
if ( F_40 ( V_36 -> V_21 , L_12 ) ) {
V_58 = F_39 ( & V_36 -> V_36 , & V_77 ) ;
if ( V_58 )
return V_58 ;
}
if ( V_36 -> V_49 . V_78 ) {
V_58 = F_39 ( & V_36 -> V_36 , & V_79 ) ;
if ( V_58 )
return V_58 ;
if ( V_36 -> V_41 . V_49 . V_80 )
V_58 = F_39 ( & V_36 -> V_36 ,
& V_81 ) ;
}
V_60:
return V_58 ;
}
void F_42 ( struct V_1 * V_36 )
{
if ( V_36 -> V_49 . V_78 ) {
F_43 ( & V_36 -> V_36 , & V_79 ) ;
if ( V_36 -> V_41 . V_49 . V_80 )
F_43 ( & V_36 -> V_36 ,
& V_81 ) ;
}
if ( F_40 ( V_36 -> V_21 , L_11 ) ) {
F_32 ( V_36 -> V_32 . V_61 ) ;
F_43 ( & V_36 -> V_36 , & V_72 ) ;
}
if ( F_40 ( V_36 -> V_21 , L_12 ) )
F_43 ( & V_36 -> V_36 , & V_77 ) ;
if ( F_40 ( V_36 -> V_21 , L_8 ) )
F_43 ( & V_36 -> V_36 , & V_75 ) ;
if ( V_36 -> V_32 . V_55 )
F_43 ( & V_36 -> V_36 , & V_74 ) ;
if ( V_36 -> V_32 . type . V_56 )
F_43 ( & V_36 -> V_36 , & V_73 ) ;
F_43 ( & V_36 -> V_36 , & V_71 ) ;
F_43 ( & V_36 -> V_36 , & V_70 ) ;
if ( F_40 ( V_36 -> V_21 , L_10 ) )
F_43 ( & V_36 -> V_36 , & V_76 ) ;
if ( V_36 -> V_21 )
F_43 ( & V_36 -> V_36 , & V_69 ) ;
}
