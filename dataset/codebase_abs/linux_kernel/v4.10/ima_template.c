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
struct V_49 {
T_2 V_31 ;
T_3 V_50 [ 0 ] ;
} V_51 ;
struct V_49 * V_52 ;
int V_53 = 0 ;
int V_43 = 0 ;
int V_18 ;
* V_48 = F_22 ( sizeof( * * V_48 ) +
V_3 -> V_26 * sizeof( struct V_54 ) ,
V_55 ) ;
if ( ! * V_48 )
return - V_36 ;
( * V_48 ) -> V_3 = V_3 ;
for ( V_18 = 0 ; V_18 < V_3 -> V_26 ; V_18 ++ ) {
V_52 = V_45 + V_53 ;
if ( V_53 > ( V_46 - sizeof( * V_52 ) ) ) {
F_4 ( L_10 ) ;
V_43 = - V_32 ;
break;
}
V_53 += sizeof( * V_52 ) ;
if ( V_56 )
V_52 -> V_31 = F_25 ( V_52 -> V_31 ) ;
if ( V_53 > ( V_46 - V_52 -> V_31 ) ) {
F_4 ( L_11 ) ;
V_43 = - V_32 ;
break;
}
V_53 += V_52 -> V_31 ;
( * V_48 ) -> V_45 [ V_18 ] . V_31 = V_52 -> V_31 ;
( * V_48 ) -> V_57 += sizeof( V_52 -> V_31 ) ;
( * V_48 ) -> V_45 [ V_18 ] . V_50 =
F_22 ( V_52 -> V_31 + 1 , V_35 ) ;
if ( ! ( * V_48 ) -> V_45 [ V_18 ] . V_50 ) {
V_43 = - V_36 ;
break;
}
memcpy ( ( * V_48 ) -> V_45 [ V_18 ] . V_50 , V_52 -> V_50 ,
V_52 -> V_31 ) ;
( * V_48 ) -> V_57 += V_52 -> V_31 ;
}
if ( V_43 < 0 ) {
F_26 ( * V_48 ) ;
* V_48 = NULL ;
}
return V_43 ;
}
int F_27 ( T_4 V_58 , void * V_59 )
{
struct V_60 {
T_2 V_61 ;
T_3 V_62 [ V_63 ] ;
T_2 V_64 ;
char V_42 [ 0 ] ;
} V_51 ;
char V_42 [ V_65 ] ;
struct V_66 {
T_2 V_46 ;
char V_45 [ 0 ] ;
} V_51 ;
struct V_67 * V_68 = V_59 ;
struct V_60 * V_69 ;
struct V_66 * V_70 ;
void * V_71 = V_59 + sizeof( * V_68 ) ;
void * V_72 ;
struct V_47 * V_48 ;
struct V_2 * V_3 ;
unsigned long V_73 = 0 ;
int V_43 = 0 ;
if ( ! V_59 || V_58 < sizeof( * V_68 ) )
return 0 ;
if ( V_56 ) {
V_68 -> V_74 = F_28 ( V_68 -> V_74 ) ;
V_68 -> V_73 = F_29 ( V_68 -> V_73 ) ;
V_68 -> V_75 = F_29 ( V_68 -> V_75 ) ;
}
if ( V_68 -> V_74 != 1 ) {
F_4 ( L_12 ) ;
return - V_32 ;
}
if ( V_68 -> V_73 > V_76 - 1 ) {
F_4 ( L_13 ) ;
return - V_32 ;
}
V_72 = V_59 + V_68 -> V_75 ;
while ( ( V_71 < V_72 ) && ( V_73 ++ < V_68 -> V_73 ) ) {
V_69 = V_71 ;
if ( V_71 > ( V_72 - sizeof( * V_69 ) ) ) {
F_4 ( L_14 ) ;
V_43 = - V_32 ;
break;
}
V_71 += sizeof( * V_69 ) ;
if ( V_56 )
V_69 -> V_64 =
F_25 ( V_69 -> V_64 ) ;
if ( ( V_69 -> V_64 >= V_65 ) ||
( V_71 > ( V_72 - V_69 -> V_64 ) ) ) {
F_4 ( L_15 ) ;
V_43 = - V_32 ;
break;
}
V_70 = V_71 += ( V_77 ) V_69 -> V_64 ;
memcpy ( V_42 , V_69 -> V_42 ,
V_69 -> V_64 ) ;
V_42 [ V_69 -> V_64 ] = 0 ;
if ( strcmp ( V_42 , L_16 ) == 0 ) {
F_4 ( L_17 , V_42 ) ;
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
F_4 ( L_18 , V_3 -> V_13 ) ;
V_43 = - V_32 ;
break;
}
if ( V_71 > ( V_72 - sizeof( V_70 -> V_46 ) ) ) {
F_4 ( L_19 ) ;
V_43 = - V_32 ;
break;
}
V_71 += ( V_77 ) sizeof( V_70 -> V_46 ) ;
if ( V_56 )
V_70 -> V_46 =
F_25 ( V_70 -> V_46 ) ;
if ( V_71 > ( V_72 - V_70 -> V_46 ) ) {
F_4 ( L_20 ) ;
V_43 = - V_32 ;
break;
}
V_71 += V_70 -> V_46 ;
V_43 = F_24 ( V_3 ,
V_70 -> V_45 ,
V_70 -> V_46 ,
& V_48 ) ;
if ( V_43 < 0 )
break;
memcpy ( V_48 -> V_62 , V_69 -> V_62 , V_63 ) ;
V_48 -> V_61 =
! V_56 ? V_69 -> V_61 : F_25 ( V_69 -> V_61 ) ;
V_43 = F_30 ( V_48 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
