static int T_1 F_1 ( char * V_1 )
{
struct V_2 * V_3 ;
int V_4 = strlen ( V_1 ) ;
if ( V_5 )
return 1 ;
F_2 () ;
V_3 = F_3 ( V_1 ) ;
if ( ! V_3 ) {
F_4 ( L_1 ,
V_1 , V_6 ) ;
return 1 ;
}
if ( V_4 == 3 && strcmp ( V_1 , V_7 ) == 0 &&
V_8 != V_9 && V_8 != V_10 ) {
F_4 ( L_2 ) ;
return 1 ;
}
V_5 = V_3 ;
return 1 ;
}
static int T_1 F_5 ( char * V_1 )
{
int V_11 = F_6 ( V_12 ) ;
if ( V_5 )
return 1 ;
if ( F_7 ( V_1 , NULL , NULL ) < 0 ) {
F_4 ( L_3 ,
V_1 , V_6 ) ;
return 1 ;
}
V_12 [ V_11 - 1 ] . V_13 = V_1 ;
V_5 = V_12 + V_11 - 1 ;
return 1 ;
}
static struct V_2 * F_3 ( const char * V_14 )
{
struct V_2 * V_3 ;
int V_15 = 0 ;
F_8 () ;
F_9 (template_desc, &defined_templates, list) {
if ( ( strcmp ( V_3 -> V_14 , V_14 ) == 0 ) ||
( strcmp ( V_3 -> V_13 , V_14 ) == 0 ) ) {
V_15 = 1 ;
break;
}
}
F_10 () ;
return V_15 ? V_3 : NULL ;
}
static struct V_16 * F_11 ( const char * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_6 ( V_19 ) ; V_18 ++ )
if ( strncmp ( V_19 [ V_18 ] . V_17 , V_17 ,
V_20 ) == 0 )
return & V_19 [ V_18 ] ;
return NULL ;
}
static int F_12 ( const char * V_21 )
{
char V_22 ;
int V_23 = strlen ( V_21 ) ;
int V_18 = 0 , V_24 = 0 ;
while ( V_18 < V_23 ) {
V_22 = V_21 [ V_18 ] ;
if ( V_22 == '|' )
V_24 ++ ;
V_18 ++ ;
}
return V_24 + 1 ;
}
static int F_7 ( const char * V_21 ,
struct V_16 * * * V_25 ,
int * V_26 )
{
const char * V_27 ;
struct V_16 * V_28 [ V_29 ] ;
int V_30 ;
int V_18 , V_31 ;
if ( V_26 && * V_26 > 0 )
return 0 ;
V_30 = F_12 ( V_21 ) ;
if ( V_30 > V_29 ) {
F_4 ( L_4 ,
V_21 ) ;
return - V_32 ;
}
for ( V_18 = 0 , V_27 = V_21 ; V_18 < V_30 ;
V_18 ++ , V_27 += V_31 + 1 ) {
char V_33 [ V_20 + 1 ] ;
V_31 = F_13 ( V_27 , '|' ) - V_27 ;
if ( V_31 == 0 || V_31 > V_20 ) {
F_4 ( L_5 , V_31 ) ;
return - V_32 ;
}
memcpy ( V_33 , V_27 , V_31 ) ;
V_33 [ V_31 ] = '\0' ;
V_28 [ V_18 ] = F_11 ( V_33 ) ;
if ( ! V_28 [ V_18 ] ) {
F_4 ( L_6 , V_33 ) ;
return - V_34 ;
}
}
if ( V_25 && V_26 ) {
* V_25 = F_14 ( V_18 , sizeof( * V_25 ) , V_35 ) ;
if ( * V_25 == NULL )
return - V_36 ;
memcpy ( * V_25 , V_28 , V_18 * sizeof( * V_25 ) ) ;
* V_26 = V_18 ;
}
return 0 ;
}
void F_2 ( void )
{
int V_18 ;
if ( ! F_15 ( & V_37 ) )
return;
F_16 ( & V_38 ) ;
for ( V_18 = 0 ; V_18 < F_6 ( V_12 ) ; V_18 ++ ) {
F_17 ( & V_12 [ V_18 ] . V_39 ,
& V_37 ) ;
}
F_18 ( & V_38 ) ;
}
struct V_2 * F_19 ( void )
{
if ( ! V_5 ) {
F_2 () ;
V_5 =
F_3 ( V_6 ) ;
}
return V_5 ;
}
int T_1 F_20 ( void )
{
struct V_2 * V_40 = F_19 () ;
int V_41 ;
V_41 = F_7 ( V_40 -> V_13 ,
& ( V_40 -> V_25 ) ,
& ( V_40 -> V_26 ) ) ;
if ( V_41 < 0 )
F_4 ( L_7 ,
( strlen ( V_40 -> V_14 ) ?
V_40 -> V_14 : V_40 -> V_13 ) , V_41 ) ;
return V_41 ;
}
static struct V_2 * F_21 ( char * V_42 )
{
struct V_2 * V_3 = NULL ;
int V_43 ;
V_43 = F_7 ( V_42 , NULL , NULL ) ;
if ( V_43 < 0 ) {
F_4 ( L_8 ,
V_42 ) ;
goto V_44;
}
V_3 = F_22 ( sizeof( * V_3 ) , V_35 ) ;
if ( ! V_3 )
goto V_44;
V_3 -> V_14 = L_9 ;
V_3 -> V_13 = F_23 ( V_42 , V_35 ) ;
if ( ! V_3 -> V_13 )
goto V_44;
F_16 ( & V_38 ) ;
F_17 ( & V_3 -> V_39 , & V_37 ) ;
F_18 ( & V_38 ) ;
V_44:
return V_3 ;
}
static int F_24 ( struct V_2 * V_3 ,
void * V_45 ,
int V_46 ,
struct V_47 * * V_48 )
{
int V_43 = 0 ;
int V_18 ;
* V_48 = F_22 ( sizeof( * * V_48 ) +
V_3 -> V_26 * sizeof( struct V_49 ) ,
V_50 ) ;
if ( ! * V_48 )
return - V_36 ;
V_43 = F_25 ( V_45 , V_45 + V_46 ,
NULL , V_3 -> V_26 ,
( * V_48 ) -> V_45 , NULL , NULL ,
V_51 | V_52 , L_10 ) ;
if ( V_43 < 0 ) {
F_26 ( * V_48 ) ;
return V_43 ;
}
( * V_48 ) -> V_3 = V_3 ;
for ( V_18 = 0 ; V_18 < V_3 -> V_26 ; V_18 ++ ) {
struct V_49 * V_53 = & ( * V_48 ) -> V_45 [ V_18 ] ;
T_2 * V_54 = V_53 -> V_54 ;
( * V_48 ) -> V_45 [ V_18 ] . V_54 =
F_22 ( V_53 -> V_31 + 1 , V_35 ) ;
if ( ! ( * V_48 ) -> V_45 [ V_18 ] . V_54 ) {
V_43 = - V_36 ;
break;
}
memcpy ( ( * V_48 ) -> V_45 [ V_18 ] . V_54 , V_54 , V_53 -> V_31 ) ;
( * V_48 ) -> V_55 += sizeof( V_53 -> V_31 ) ;
( * V_48 ) -> V_55 += V_53 -> V_31 ;
}
if ( V_43 < 0 ) {
F_27 ( * V_48 ) ;
* V_48 = NULL ;
}
return V_43 ;
}
int F_28 ( T_3 V_56 , void * V_57 )
{
char V_42 [ V_58 ] ;
struct V_59 * V_60 = V_57 ;
struct V_49 V_61 [ V_62 ] = {
[ V_63 ] = { . V_31 = sizeof( V_64 ) } ,
[ V_65 ] = { . V_31 = V_66 } ,
} ;
void * V_67 = V_57 + sizeof( * V_60 ) ;
void * V_68 ;
struct V_47 * V_48 ;
struct V_2 * V_3 ;
F_29 ( V_69 , V_62 ) ;
unsigned long V_70 = 0 ;
int V_43 = 0 ;
if ( ! V_57 || V_56 < sizeof( * V_60 ) )
return 0 ;
if ( V_71 ) {
V_60 -> V_72 = F_30 ( V_60 -> V_72 ) ;
V_60 -> V_70 = F_31 ( V_60 -> V_70 ) ;
V_60 -> V_73 = F_31 ( V_60 -> V_73 ) ;
}
if ( V_60 -> V_72 != 1 ) {
F_4 ( L_11 ) ;
return - V_32 ;
}
if ( V_60 -> V_70 > V_74 - 1 ) {
F_4 ( L_12 ) ;
return - V_32 ;
}
F_32 ( V_69 , V_62 ) ;
F_33 ( V_69 , V_63 , 1 ) ;
F_33 ( V_69 , V_65 , 1 ) ;
V_68 = V_57 + V_60 -> V_73 ;
while ( ( V_67 < V_68 ) && ( V_70 ++ < V_60 -> V_70 ) ) {
int V_75 = V_51 ;
V_75 |= ( V_70 == V_60 -> V_70 ) ? V_52 : 0 ;
V_43 = F_25 ( V_67 , V_68 , & V_67 , V_62 , V_61 , NULL ,
V_69 , V_75 , L_13 ) ;
if ( V_43 < 0 )
break;
if ( V_61 [ V_76 ] . V_31 >= V_58 ) {
F_4 ( L_14 ) ;
V_43 = - V_32 ;
break;
}
memcpy ( V_42 , V_61 [ V_76 ] . V_54 ,
V_61 [ V_76 ] . V_31 ) ;
V_42 [ V_61 [ V_76 ] . V_31 ] = 0 ;
if ( strcmp ( V_42 , L_15 ) == 0 ) {
F_4 ( L_16 , V_42 ) ;
V_43 = - V_32 ;
break;
}
V_3 = F_3 ( V_42 ) ;
if ( ! V_3 ) {
V_3 = F_21 ( V_42 ) ;
if ( ! V_3 )
break;
}
V_43 = F_7 ( V_3 -> V_13 ,
& ( V_3 -> V_25 ) ,
& ( V_3 -> V_26 ) ) ;
if ( V_43 < 0 ) {
F_4 ( L_17 , V_3 -> V_13 ) ;
V_43 = - V_32 ;
break;
}
V_43 = F_24 ( V_3 ,
V_61 [ V_77 ] . V_54 ,
V_61 [ V_77 ] . V_31 ,
& V_48 ) ;
if ( V_43 < 0 )
break;
memcpy ( V_48 -> V_78 , V_61 [ V_65 ] . V_54 ,
V_61 [ V_65 ] . V_31 ) ;
V_48 -> V_79 = ! V_71 ? * ( V_61 [ V_63 ] . V_54 ) :
F_34 ( * ( V_61 [ V_63 ] . V_54 ) ) ;
V_43 = F_35 ( V_48 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
