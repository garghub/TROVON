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
* V_20 = F_23 ( F_21 , 1 ) ;
return 0 ;
}
static int F_24 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
unsigned int V_24 ;
if ( F_21 ( V_5 , & V_24 ) )
return - V_23 ;
* V_20 = V_24 / 1024 ;
return 0 ;
}
static int F_25 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
const T_1 * V_25 ;
int V_26 , V_27 ;
V_27 = F_26 ( V_6 [ V_5 -> type ] . V_28 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
const char * V_21 ;
V_21 = V_6 [ V_5 -> type ] . V_28 [ V_26 ] ;
V_25 = F_22 ( V_5 -> V_10 , V_21 , NULL ) ;
if ( V_25 )
break;
}
if ( ! V_25 )
return - V_23 ;
* V_20 = F_23 ( V_25 , 1 ) ;
return 0 ;
}
static int F_27 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
const char * V_21 ;
const T_1 * V_29 ;
V_21 = V_6 [ V_5 -> type ] . V_30 ;
V_29 = F_22 ( V_5 -> V_10 , V_21 , NULL ) ;
if ( ! V_29 )
return - V_23 ;
* V_20 = F_23 ( V_29 , 1 ) ;
return 0 ;
}
static int F_28 ( const struct V_5 * V_5 , unsigned int * V_20 )
{
unsigned int V_25 ;
unsigned int V_29 ;
unsigned int V_24 ;
if ( F_27 ( V_5 , & V_29 ) )
goto V_31;
if ( V_29 == 1 ) {
* V_20 = 0 ;
return 0 ;
}
if ( F_25 ( V_5 , & V_25 ) )
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
static struct V_5 * F_29 ( struct V_5 * V_5 )
{
struct V_5 * V_14 ;
if ( V_5 -> type == V_32 ||
V_5 -> type == V_33 )
return V_5 ;
F_11 (iter, &cache_list, list)
if ( V_14 -> V_10 == V_5 -> V_10 && V_14 -> V_15 == V_5 )
return V_14 ;
return V_5 ;
}
static struct V_5 * F_30 ( const struct V_9 * V_34 )
{
struct V_5 * V_5 = NULL ;
struct V_5 * V_14 ;
F_11 (iter, &cache_list, list) {
if ( V_14 -> V_10 != V_34 )
continue;
V_5 = F_29 ( V_14 ) ;
break;
}
return V_5 ;
}
static bool F_31 ( const struct V_9 * V_35 )
{
return F_22 ( V_35 , L_4 , NULL ) ;
}
static int F_32 ( const struct V_9 * V_35 )
{
return F_22 ( V_35 ,
V_6 [ V_33 ] . V_22 , NULL ) ?
V_33 : V_32 ;
}
static struct V_5 * F_33 ( struct V_9 * V_34 , int V_8 )
{
F_14 ( L_5 , V_8 , V_34 -> V_16 ) ;
return F_8 ( F_32 ( V_34 ) , V_8 , V_34 ) ;
}
static struct V_5 * F_34 ( struct V_9 * V_34 ,
int V_8 )
{
struct V_5 * V_36 , * V_37 ;
F_14 ( L_6 , V_8 ,
V_34 -> V_16 ) ;
V_36 = F_8 ( V_38 , V_8 , V_34 ) ;
V_37 = F_8 ( V_39 , V_8 , V_34 ) ;
if ( ! V_36 || ! V_37 )
goto V_31;
V_36 -> V_15 = V_37 ;
return V_36 ;
V_31:
F_13 ( V_36 ) ;
F_13 ( V_37 ) ;
return NULL ;
}
static struct V_5 * F_35 ( struct V_9 * V_34 , int V_8 )
{
struct V_5 * V_5 ;
if ( F_31 ( V_34 ) )
V_5 = F_33 ( V_34 , V_8 ) ;
else
V_5 = F_34 ( V_34 , V_8 ) ;
return V_5 ;
}
static struct V_5 * F_36 ( struct V_9 * V_34 ,
int V_8 )
{
struct V_5 * V_5 ;
V_5 = F_30 ( V_34 ) ;
F_12 ( V_5 && V_5 -> V_8 != V_8 ,
L_7 ,
V_5 -> V_8 , V_8 ) ;
if ( ! V_5 )
V_5 = F_35 ( V_34 , V_8 ) ;
return V_5 ;
}
static void F_37 ( struct V_5 * V_40 , struct V_5 * V_41 )
{
while ( V_40 -> V_15 ) {
if ( V_40 -> V_15 == V_41 )
return;
V_40 = V_40 -> V_15 ;
}
V_40 -> V_15 = V_41 ;
}
static void F_38 ( struct V_5 * V_5 )
{
F_39 ( V_5 -> V_8 != 1 ) ;
F_39 ( strcmp ( V_5 -> V_10 -> type , L_8 ) ) ;
}
static void F_40 ( struct V_5 * V_5 )
{
struct V_9 * V_42 ;
int V_8 = V_5 -> V_8 ;
F_38 ( V_5 ) ;
while ( ( V_42 = F_41 ( V_5 -> V_10 ) ) ) {
struct V_5 * V_43 ;
V_8 ++ ;
V_43 = F_36 ( V_42 , V_8 ) ;
F_16 ( V_42 ) ;
if ( ! V_43 )
break;
F_37 ( V_5 , V_43 ) ;
V_5 = V_43 ;
}
}
static struct V_5 * F_42 ( unsigned int V_44 )
{
struct V_9 * V_45 ;
struct V_5 * V_46 = NULL ;
F_14 ( L_9 , V_44 ) ;
V_45 = F_43 ( V_44 , NULL ) ;
F_12 ( ! V_45 , L_10 , V_44 ) ;
if ( ! V_45 )
goto V_47;
V_46 = F_36 ( V_45 , 1 ) ;
if ( ! V_46 )
goto V_47;
F_40 ( V_46 ) ;
F_18 ( V_46 , V_44 ) ;
V_47:
F_16 ( V_45 ) ;
return V_46 ;
}
static struct V_48 * F_44 ( unsigned int V_44 )
{
struct V_48 * V_48 ;
struct V_49 * V_50 ;
struct V_2 * V_4 = NULL ;
V_50 = F_45 ( V_44 ) ;
F_12 ( ! V_50 , L_11 , V_44 ) ;
if ( ! V_50 )
goto V_31;
V_4 = F_46 ( L_12 , & V_50 -> V_4 ) ;
if ( ! V_4 )
goto V_31;
V_48 = F_9 ( sizeof( * V_48 ) , V_13 ) ;
if ( ! V_48 )
goto V_31;
V_48 -> V_4 = V_4 ;
F_39 ( F_47 ( V_51 , V_44 ) != NULL ) ;
F_47 ( V_51 , V_44 ) = V_48 ;
return V_48 ;
V_31:
F_48 ( V_4 ) ;
return NULL ;
}
static void F_49 ( struct V_2 * V_4 )
{
struct V_1 * V_52 ;
V_52 = F_1 ( V_4 ) ;
F_14 ( L_13 ,
V_52 -> V_5 -> V_8 , F_3 ( V_52 -> V_5 ) ) ;
F_17 ( V_52 ) ;
}
static T_2 F_50 ( struct V_2 * V_3 , struct V_53 * V_54 , char * V_55 )
{
struct V_56 * V_57 ;
V_57 = F_2 ( V_54 , struct V_56 , V_54 ) ;
return V_57 -> V_58 ( V_3 , V_57 , V_55 ) ;
}
static struct V_5 * F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_52 ;
V_52 = F_1 ( V_3 ) ;
return V_52 -> V_5 ;
}
static T_2 F_52 ( struct V_2 * V_3 , struct V_56 * V_54 , char * V_55 )
{
unsigned int V_59 ;
struct V_5 * V_5 ;
V_5 = F_51 ( V_3 ) ;
if ( F_24 ( V_5 , & V_59 ) )
return - V_23 ;
return sprintf ( V_55 , L_14 , V_59 ) ;
}
static T_2 F_53 ( struct V_2 * V_3 , struct V_56 * V_54 , char * V_55 )
{
unsigned int V_25 ;
struct V_5 * V_5 ;
V_5 = F_51 ( V_3 ) ;
if ( F_25 ( V_5 , & V_25 ) )
return - V_23 ;
return sprintf ( V_55 , L_15 , V_25 ) ;
}
static T_2 F_54 ( struct V_2 * V_3 , struct V_56 * V_54 , char * V_55 )
{
unsigned int V_29 ;
struct V_5 * V_5 ;
V_5 = F_51 ( V_3 ) ;
if ( F_27 ( V_5 , & V_29 ) )
return - V_23 ;
return sprintf ( V_55 , L_15 , V_29 ) ;
}
static T_2 F_55 ( struct V_2 * V_3 , struct V_56 * V_54 , char * V_55 )
{
unsigned int V_60 ;
struct V_5 * V_5 ;
V_5 = F_51 ( V_3 ) ;
if ( F_28 ( V_5 , & V_60 ) )
return - V_23 ;
return sprintf ( V_55 , L_15 , V_60 ) ;
}
static T_2 F_56 ( struct V_2 * V_3 , struct V_56 * V_54 , char * V_55 )
{
struct V_5 * V_5 ;
V_5 = F_51 ( V_3 ) ;
return sprintf ( V_55 , L_16 , F_3 ( V_5 ) ) ;
}
static T_2 F_57 ( struct V_2 * V_3 , struct V_56 * V_54 , char * V_55 )
{
struct V_1 * V_52 ;
struct V_5 * V_5 ;
V_52 = F_1 ( V_3 ) ;
V_5 = V_52 -> V_5 ;
return sprintf ( V_55 , L_17 , V_5 -> V_8 ) ;
}
static T_2 F_58 ( struct V_2 * V_3 , struct V_56 * V_54 , char * V_55 )
{
struct V_1 * V_52 ;
struct V_5 * V_5 ;
int V_20 ;
V_52 = F_1 ( V_3 ) ;
V_5 = V_52 -> V_5 ;
V_20 = F_59 ( V_55 , V_61 - 1 , L_18 ,
F_60 ( & V_5 -> V_19 ) ) ;
V_55 [ V_20 ++ ] = '\n' ;
V_55 [ V_20 ] = '\0' ;
return V_20 ;
}
static void F_61 ( struct V_1 * V_62 )
{
const char * V_63 ;
const char * V_64 ;
struct V_5 * V_5 ;
char * V_55 ;
int V_26 ;
V_55 = F_62 ( V_61 , V_13 ) ;
if ( ! V_55 )
return;
V_5 = V_62 -> V_5 ;
V_63 = V_5 -> V_10 -> V_16 ;
V_64 = F_3 ( V_5 ) ;
for ( V_26 = 0 ; V_26 < F_26 ( V_65 ) ; V_26 ++ ) {
struct V_56 * V_54 ;
T_2 V_66 ;
V_54 = V_65 [ V_26 ] ;
V_66 = V_54 -> V_58 ( & V_62 -> V_4 , V_54 , V_55 ) ;
if ( V_66 <= 0 ) {
F_14 ( L_19
L_20 ,
V_54 -> V_54 . V_7 , V_63 ,
V_64 , V_66 ) ;
continue;
}
if ( F_63 ( & V_62 -> V_4 , & V_54 -> V_54 ) )
F_14 ( L_21 ,
V_54 -> V_54 . V_7 , V_63 , V_64 ) ;
}
F_17 ( V_55 ) ;
}
static void F_64 ( struct V_5 * V_5 , int V_52 ,
struct V_48 * V_48 )
{
struct V_1 * V_67 ;
int V_66 ;
V_67 = F_9 ( sizeof( * V_67 ) , V_13 ) ;
if ( ! V_67 )
goto V_31;
V_67 -> V_5 = V_5 ;
V_66 = F_65 ( & V_67 -> V_4 , & V_68 ,
V_48 -> V_4 , L_22 , V_52 ) ;
if ( V_66 )
goto V_31;
V_67 -> V_18 = V_48 -> V_52 ;
V_48 -> V_52 = V_67 ;
F_61 ( V_67 ) ;
return;
V_31:
F_17 ( V_67 ) ;
}
static void F_66 ( unsigned int V_44 ,
struct V_5 * V_12 )
{
struct V_48 * V_48 ;
struct V_5 * V_5 ;
int V_52 = 0 ;
V_48 = F_44 ( V_44 ) ;
if ( ! V_48 )
return;
V_5 = V_12 ;
while ( V_5 ) {
F_64 ( V_5 , V_52 , V_48 ) ;
V_52 ++ ;
V_5 = V_5 -> V_15 ;
}
}
void F_67 ( unsigned int V_44 )
{
struct V_5 * V_5 ;
V_5 = F_42 ( V_44 ) ;
if ( ! V_5 )
return;
F_66 ( V_44 , V_5 ) ;
}
static struct V_5 * F_68 ( unsigned int V_44 )
{
struct V_9 * V_45 ;
struct V_5 * V_5 ;
V_45 = F_43 ( V_44 , NULL ) ;
F_12 ( ! V_45 , L_10 , V_44 ) ;
if ( ! V_45 )
return NULL ;
V_5 = F_30 ( V_45 ) ;
F_16 ( V_45 ) ;
return V_5 ;
}
static void F_69 ( struct V_48 * V_48 )
{
struct V_1 * V_52 ;
V_52 = V_48 -> V_52 ;
while ( V_52 ) {
struct V_1 * V_18 ;
V_18 = V_52 -> V_18 ;
F_48 ( & V_52 -> V_4 ) ;
V_52 = V_18 ;
}
}
static void F_70 ( struct V_48 * V_48 )
{
F_69 ( V_48 ) ;
F_71 ( V_48 -> V_4 ) ;
F_48 ( V_48 -> V_4 ) ;
F_17 ( V_48 ) ;
}
static void F_72 ( struct V_5 * V_5 , int V_17 )
{
while ( V_5 ) {
struct V_5 * V_18 = V_5 -> V_15 ;
F_12 ( ! F_19 ( V_17 , & V_5 -> V_19 ) ,
L_23 ,
V_17 , V_5 -> V_10 -> V_16 ,
F_3 ( V_5 ) ) ;
F_73 ( V_17 , & V_5 -> V_19 ) ;
if ( F_74 ( & V_5 -> V_19 ) )
F_13 ( V_5 ) ;
V_5 = V_18 ;
}
}
void F_75 ( unsigned int V_44 )
{
struct V_48 * V_48 ;
struct V_5 * V_5 ;
V_48 = F_47 ( V_51 , V_44 ) ;
if ( V_48 )
F_70 ( V_48 ) ;
F_47 ( V_51 , V_44 ) = NULL ;
V_5 = F_68 ( V_44 ) ;
if ( V_5 )
F_72 ( V_5 , V_44 ) ;
}
