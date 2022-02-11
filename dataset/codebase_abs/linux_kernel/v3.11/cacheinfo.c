static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static const char * F_3 ( const struct V_5 * V_5 )
{
return V_6 [ V_5 -> type ] . V_7 ;
}
static void F_4 ( struct V_5 * V_5 , int type , int V_8 ,
struct V_9 * V_10 )
{
V_5 -> type = type ;
V_5 -> V_8 = V_8 ;
V_5 -> V_10 = F_5 ( V_10 ) ;
F_6 ( & V_5 -> V_11 ) ;
F_7 ( & V_5 -> V_11 , & V_12 ) ;
}
static struct V_5 * F_8 ( int type , int V_8 , struct V_9 * V_10 )
{
struct V_5 * V_5 ;
V_5 = F_9 ( sizeof( * V_5 ) , V_13 ) ;
if ( V_5 )
F_4 ( V_5 , type , V_8 , V_10 ) ;
return V_5 ;
}
static void F_10 ( struct V_5 * V_5 )
{
struct V_5 * V_14 ;
F_11 (iter, &cache_list, list)
F_12 ( V_14 -> V_15 == V_5 ,
L_1 ,
V_14 -> V_10 -> V_16 ,
F_3 ( V_14 ) ,
V_5 -> V_10 -> V_16 ,
F_3 ( V_5 ) ) ;
}
static void F_13 ( struct V_5 * V_5 )
{
if ( ! V_5 )
return;
F_14 ( L_2 , V_5 -> V_8 ,
F_3 ( V_5 ) , V_5 -> V_10 -> V_16 ) ;
F_10 ( V_5 ) ;
F_15 ( & V_5 -> V_11 ) ;
F_16 ( V_5 -> V_10 ) ;
F_17 ( V_5 ) ;
}
static void F_18 ( struct V_5 * V_5 , int V_17 )
{
struct V_5 * V_18 = V_5 ;
while ( V_18 ) {
F_12 ( F_19 ( V_17 , & V_18 -> V_19 ) ,
L_3 ,
V_17 , V_18 -> V_10 -> V_16 ,
F_3 ( V_18 ) ) ;
F_20 ( V_17 , & V_18 -> V_19 ) ;
V_18 = V_18 -> V_15 ;
}
}
static int F_21 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
const char * V_21 ;
const T_1 * F_21 ;
V_21 = V_6 [ V_5 -> type ] . V_22 ;
F_21 = F_22 ( V_5 -> V_10 , V_21 , NULL ) ;
if ( ! F_21 )
return - V_23 ;
* V_20 = * F_21 ;
return 0 ;
}
static int F_23 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
unsigned int V_24 ;
if ( F_21 ( V_5 , & V_24 ) )
return - V_23 ;
* V_20 = V_24 / 1024 ;
return 0 ;
}
static int F_24 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
const T_1 * V_25 ;
int V_26 , V_27 ;
V_27 = F_25 ( V_6 [ V_5 -> type ] . V_28 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
const char * V_21 ;
V_21 = V_6 [ V_5 -> type ] . V_28 [ V_26 ] ;
V_25 = F_22 ( V_5 -> V_10 , V_21 , NULL ) ;
if ( V_25 )
break;
}
if ( ! V_25 )
return - V_23 ;
* V_20 = * V_25 ;
return 0 ;
}
static int F_26 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
const char * V_21 ;
const T_1 * V_29 ;
V_21 = V_6 [ V_5 -> type ] . V_30 ;
V_29 = F_22 ( V_5 -> V_10 , V_21 , NULL ) ;
if ( ! V_29 )
return - V_23 ;
* V_20 = * V_29 ;
return 0 ;
}
static int F_27 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
unsigned int V_25 ;
unsigned int V_29 ;
unsigned int V_24 ;
if ( F_26 ( V_5 , & V_29 ) )
goto V_31;
if ( V_29 == 1 ) {
* V_20 = 0 ;
return 0 ;
}
if ( F_24 ( V_5 , & V_25 ) )
goto V_31;
if ( F_21 ( V_5 , & V_24 ) )
goto V_31;
if ( ! ( V_29 > 0 && V_24 > 0 && V_25 > 0 ) )
goto V_31;
* V_20 = ( V_24 / V_29 ) / V_25 ;
return 0 ;
V_31:
return - V_23 ;
}
static struct V_5 * F_28 ( struct V_5 * V_5 )
{
struct V_5 * V_14 ;
if ( V_5 -> type == V_32 )
return V_5 ;
F_11 (iter, &cache_list, list)
if ( V_14 -> V_10 == V_5 -> V_10 && V_14 -> V_15 == V_5 )
return V_14 ;
return V_5 ;
}
static struct V_5 * F_29 ( const struct V_9 * V_33 )
{
struct V_5 * V_5 = NULL ;
struct V_5 * V_14 ;
F_11 (iter, &cache_list, list) {
if ( V_14 -> V_10 != V_33 )
continue;
V_5 = F_28 ( V_14 ) ;
break;
}
return V_5 ;
}
static bool F_30 ( const struct V_9 * V_34 )
{
return F_22 ( V_34 , L_4 , NULL ) ;
}
static struct V_5 * F_31 ( struct V_9 * V_33 ,
int V_8 )
{
struct V_5 * V_5 ;
F_14 ( L_5 , V_8 , V_33 -> V_16 ) ;
V_5 = F_8 ( V_32 , V_8 , V_33 ) ;
return V_5 ;
}
static struct V_5 * F_32 ( struct V_9 * V_33 ,
int V_8 )
{
struct V_5 * V_35 , * V_36 ;
F_14 ( L_6 , V_8 ,
V_33 -> V_16 ) ;
V_35 = F_8 ( V_37 , V_8 , V_33 ) ;
V_36 = F_8 ( V_38 , V_8 , V_33 ) ;
if ( ! V_35 || ! V_36 )
goto V_31;
V_35 -> V_15 = V_36 ;
return V_35 ;
V_31:
F_13 ( V_35 ) ;
F_13 ( V_36 ) ;
return NULL ;
}
static struct V_5 * F_33 ( struct V_9 * V_33 , int V_8 )
{
struct V_5 * V_5 ;
if ( F_30 ( V_33 ) )
V_5 = F_31 ( V_33 , V_8 ) ;
else
V_5 = F_32 ( V_33 , V_8 ) ;
return V_5 ;
}
static struct V_5 * F_34 ( struct V_9 * V_33 ,
int V_8 )
{
struct V_5 * V_5 ;
V_5 = F_29 ( V_33 ) ;
F_12 ( V_5 && V_5 -> V_8 != V_8 ,
L_7 ,
V_5 -> V_8 , V_8 ) ;
if ( ! V_5 )
V_5 = F_33 ( V_33 , V_8 ) ;
return V_5 ;
}
static void F_35 ( struct V_5 * V_39 , struct V_5 * V_40 )
{
while ( V_39 -> V_15 ) {
if ( V_39 -> V_15 == V_40 )
return;
V_39 = V_39 -> V_15 ;
}
V_39 -> V_15 = V_40 ;
}
static void F_36 ( struct V_5 * V_5 )
{
F_37 ( V_5 -> V_8 != 1 ) ;
F_37 ( strcmp ( V_5 -> V_10 -> type , L_8 ) ) ;
}
static void F_38 ( struct V_5 * V_5 )
{
struct V_9 * V_41 ;
int V_8 = V_5 -> V_8 ;
F_36 ( V_5 ) ;
while ( ( V_41 = F_39 ( V_5 -> V_10 ) ) ) {
struct V_5 * V_42 ;
V_8 ++ ;
V_42 = F_34 ( V_41 , V_8 ) ;
F_16 ( V_41 ) ;
if ( ! V_42 )
break;
F_35 ( V_5 , V_42 ) ;
V_5 = V_42 ;
}
}
static struct V_5 * F_40 ( unsigned int V_43 )
{
struct V_9 * V_44 ;
struct V_5 * V_45 = NULL ;
F_14 ( L_9 , V_43 ) ;
V_44 = F_41 ( V_43 , NULL ) ;
F_12 ( ! V_44 , L_10 , V_43 ) ;
if ( ! V_44 )
goto V_46;
V_45 = F_34 ( V_44 , 1 ) ;
if ( ! V_45 )
goto V_46;
F_38 ( V_45 ) ;
F_18 ( V_45 , V_43 ) ;
V_46:
F_16 ( V_44 ) ;
return V_45 ;
}
static struct V_47 * F_42 ( unsigned int V_43 )
{
struct V_47 * V_47 ;
struct V_48 * V_49 ;
struct V_2 * V_4 = NULL ;
V_49 = F_43 ( V_43 ) ;
F_12 ( ! V_49 , L_11 , V_43 ) ;
if ( ! V_49 )
goto V_31;
V_4 = F_44 ( L_12 , & V_49 -> V_4 ) ;
if ( ! V_4 )
goto V_31;
V_47 = F_9 ( sizeof( * V_47 ) , V_13 ) ;
if ( ! V_47 )
goto V_31;
V_47 -> V_4 = V_4 ;
F_37 ( F_45 ( V_50 , V_43 ) != NULL ) ;
F_45 ( V_50 , V_43 ) = V_47 ;
return V_47 ;
V_31:
F_46 ( V_4 ) ;
return NULL ;
}
static void F_47 ( struct V_2 * V_4 )
{
struct V_1 * V_51 ;
V_51 = F_1 ( V_4 ) ;
F_14 ( L_13 ,
V_51 -> V_5 -> V_8 , F_3 ( V_51 -> V_5 ) ) ;
F_17 ( V_51 ) ;
}
static T_2 F_48 ( struct V_2 * V_3 , struct V_52 * V_53 , char * V_54 )
{
struct V_55 * V_56 ;
V_56 = F_2 ( V_53 , struct V_55 , V_53 ) ;
return V_56 -> V_57 ( V_3 , V_56 , V_54 ) ;
}
static struct V_5 * F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_51 ;
V_51 = F_1 ( V_3 ) ;
return V_51 -> V_5 ;
}
static T_2 F_50 ( struct V_2 * V_3 , struct V_55 * V_53 , char * V_54 )
{
unsigned int V_58 ;
struct V_5 * V_5 ;
V_5 = F_49 ( V_3 ) ;
if ( F_23 ( V_5 , & V_58 ) )
return - V_23 ;
return sprintf ( V_54 , L_14 , V_58 ) ;
}
static T_2 F_51 ( struct V_2 * V_3 , struct V_55 * V_53 , char * V_54 )
{
unsigned int V_25 ;
struct V_5 * V_5 ;
V_5 = F_49 ( V_3 ) ;
if ( F_24 ( V_5 , & V_25 ) )
return - V_23 ;
return sprintf ( V_54 , L_15 , V_25 ) ;
}
static T_2 F_52 ( struct V_2 * V_3 , struct V_55 * V_53 , char * V_54 )
{
unsigned int V_29 ;
struct V_5 * V_5 ;
V_5 = F_49 ( V_3 ) ;
if ( F_26 ( V_5 , & V_29 ) )
return - V_23 ;
return sprintf ( V_54 , L_15 , V_29 ) ;
}
static T_2 F_53 ( struct V_2 * V_3 , struct V_55 * V_53 , char * V_54 )
{
unsigned int V_59 ;
struct V_5 * V_5 ;
V_5 = F_49 ( V_3 ) ;
if ( F_27 ( V_5 , & V_59 ) )
return - V_23 ;
return sprintf ( V_54 , L_15 , V_59 ) ;
}
static T_2 F_54 ( struct V_2 * V_3 , struct V_55 * V_53 , char * V_54 )
{
struct V_5 * V_5 ;
V_5 = F_49 ( V_3 ) ;
return sprintf ( V_54 , L_16 , F_3 ( V_5 ) ) ;
}
static T_2 F_55 ( struct V_2 * V_3 , struct V_55 * V_53 , char * V_54 )
{
struct V_1 * V_51 ;
struct V_5 * V_5 ;
V_51 = F_1 ( V_3 ) ;
V_5 = V_51 -> V_5 ;
return sprintf ( V_54 , L_17 , V_5 -> V_8 ) ;
}
static T_2 F_56 ( struct V_2 * V_3 , struct V_55 * V_53 , char * V_54 )
{
struct V_1 * V_51 ;
struct V_5 * V_5 ;
int V_60 ;
int V_61 = 0 ;
V_51 = F_1 ( V_3 ) ;
V_5 = V_51 -> V_5 ;
V_60 = V_62 - 2 ;
if ( V_60 > 1 ) {
V_61 = F_57 ( V_54 , V_60 , & V_5 -> V_19 ) ;
V_54 [ V_61 ++ ] = '\n' ;
V_54 [ V_61 ] = '\0' ;
}
return V_61 ;
}
static void F_58 ( struct V_1 * V_63 )
{
const char * V_64 ;
const char * V_65 ;
struct V_5 * V_5 ;
char * V_54 ;
int V_26 ;
V_54 = F_59 ( V_62 , V_13 ) ;
if ( ! V_54 )
return;
V_5 = V_63 -> V_5 ;
V_64 = V_5 -> V_10 -> V_16 ;
V_65 = F_3 ( V_5 ) ;
for ( V_26 = 0 ; V_26 < F_25 ( V_66 ) ; V_26 ++ ) {
struct V_55 * V_53 ;
T_2 V_67 ;
V_53 = V_66 [ V_26 ] ;
V_67 = V_53 -> V_57 ( & V_63 -> V_4 , V_53 , V_54 ) ;
if ( V_67 <= 0 ) {
F_14 ( L_18
L_19 ,
V_53 -> V_53 . V_7 , V_64 ,
V_65 , V_67 ) ;
continue;
}
if ( F_60 ( & V_63 -> V_4 , & V_53 -> V_53 ) )
F_14 ( L_20 ,
V_53 -> V_53 . V_7 , V_64 , V_65 ) ;
}
F_17 ( V_54 ) ;
}
static void F_61 ( struct V_5 * V_5 , int V_51 ,
struct V_47 * V_47 )
{
struct V_1 * V_68 ;
int V_67 ;
V_68 = F_9 ( sizeof( * V_68 ) , V_13 ) ;
if ( ! V_68 )
goto V_31;
V_68 -> V_5 = V_5 ;
V_67 = F_62 ( & V_68 -> V_4 , & V_69 ,
V_47 -> V_4 , L_21 , V_51 ) ;
if ( V_67 )
goto V_31;
V_68 -> V_18 = V_47 -> V_51 ;
V_47 -> V_51 = V_68 ;
F_58 ( V_68 ) ;
return;
V_31:
F_17 ( V_68 ) ;
}
static void F_63 ( unsigned int V_43 ,
struct V_5 * V_12 )
{
struct V_47 * V_47 ;
struct V_5 * V_5 ;
int V_51 = 0 ;
V_47 = F_42 ( V_43 ) ;
if ( ! V_47 )
return;
V_5 = V_12 ;
while ( V_5 ) {
F_61 ( V_5 , V_51 , V_47 ) ;
V_51 ++ ;
V_5 = V_5 -> V_15 ;
}
}
void F_64 ( unsigned int V_43 )
{
struct V_5 * V_5 ;
V_5 = F_40 ( V_43 ) ;
if ( ! V_5 )
return;
F_63 ( V_43 , V_5 ) ;
}
static struct V_5 * F_65 ( unsigned int V_43 )
{
struct V_9 * V_44 ;
struct V_5 * V_5 ;
V_44 = F_41 ( V_43 , NULL ) ;
F_12 ( ! V_44 , L_10 , V_43 ) ;
if ( ! V_44 )
return NULL ;
V_5 = F_29 ( V_44 ) ;
F_16 ( V_44 ) ;
return V_5 ;
}
static void F_66 ( struct V_47 * V_47 )
{
struct V_1 * V_51 ;
V_51 = V_47 -> V_51 ;
while ( V_51 ) {
struct V_1 * V_18 ;
V_18 = V_51 -> V_18 ;
F_46 ( & V_51 -> V_4 ) ;
V_51 = V_18 ;
}
}
static void F_67 ( struct V_47 * V_47 )
{
F_66 ( V_47 ) ;
F_46 ( V_47 -> V_4 ) ;
F_17 ( V_47 ) ;
}
static void F_68 ( struct V_5 * V_5 , int V_17 )
{
while ( V_5 ) {
struct V_5 * V_18 = V_5 -> V_15 ;
F_12 ( ! F_19 ( V_17 , & V_5 -> V_19 ) ,
L_22 ,
V_17 , V_5 -> V_10 -> V_16 ,
F_3 ( V_5 ) ) ;
F_69 ( V_17 , & V_5 -> V_19 ) ;
if ( F_70 ( & V_5 -> V_19 ) )
F_13 ( V_5 ) ;
V_5 = V_18 ;
}
}
void F_71 ( unsigned int V_43 )
{
struct V_47 * V_47 ;
struct V_5 * V_5 ;
V_47 = F_45 ( V_50 , V_43 ) ;
if ( V_47 )
F_67 ( V_47 ) ;
F_45 ( V_50 , V_43 ) = NULL ;
V_5 = F_65 ( V_43 ) ;
if ( V_5 )
F_68 ( V_5 , V_43 ) ;
}
