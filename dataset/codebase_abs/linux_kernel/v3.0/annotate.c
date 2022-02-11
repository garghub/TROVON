int F_1 ( struct V_1 * V_1 V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( & V_6 -> V_7 , NULL ) ;
return 0 ;
}
int F_4 ( struct V_3 * V_4 , int V_8 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_9 = ( sizeof( struct V_10 ) +
( V_4 -> V_11 - V_4 -> V_12 ) * sizeof( V_13 ) ) ;
V_6 -> V_14 = F_5 ( sizeof( * V_6 -> V_14 ) + V_8 * V_9 ) ;
if ( V_6 -> V_14 == NULL )
return - 1 ;
V_6 -> V_14 -> V_9 = V_9 ;
V_6 -> V_14 -> V_15 = V_8 ;
F_6 ( & V_6 -> V_14 -> V_16 ) ;
return 0 ;
}
void F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_8 ( & V_6 -> V_7 ) ;
if ( V_6 -> V_14 != NULL )
memset ( V_6 -> V_14 -> V_17 , 0 ,
V_6 -> V_14 -> V_15 * V_6 -> V_14 -> V_9 ) ;
F_9 ( & V_6 -> V_7 ) ;
}
int F_10 ( struct V_3 * V_4 , struct V_1 * V_1 ,
int V_18 , V_13 V_19 )
{
unsigned V_20 ;
struct V_5 * V_6 ;
struct V_10 * V_21 ;
V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_14 == NULL )
return - V_22 ;
F_11 ( L_1 V_23 L_2 , V_24 , V_1 -> V_25 ( V_1 , V_19 ) ) ;
if ( V_19 >= V_4 -> V_11 )
return 0 ;
V_20 = V_19 - V_4 -> V_12 ;
V_21 = F_12 ( V_6 , V_18 ) ;
V_21 -> V_26 ++ ;
V_21 -> V_19 [ V_20 ] ++ ;
F_11 ( L_3 V_23 L_4 V_23 L_5 V_23
L_6 V_27 L_2 , V_4 -> V_12 , V_4 -> V_28 ,
V_19 , V_19 - V_4 -> V_12 , V_18 , V_21 -> V_19 [ V_20 ] ) ;
return 0 ;
}
static struct V_29 * F_13 ( T_2 V_20 , char * line , T_1 V_30 )
{
struct V_29 * V_31 = malloc ( sizeof( * V_31 ) + V_30 ) ;
if ( V_31 != NULL ) {
V_31 -> V_20 = V_20 ;
V_31 -> line = line ;
}
return V_31 ;
}
void F_14 ( struct V_29 * V_31 )
{
free ( V_31 -> line ) ;
free ( V_31 ) ;
}
static void F_15 ( struct V_32 * V_33 , struct V_29 * line )
{
F_16 ( & line -> V_34 , V_33 ) ;
}
struct V_29 * F_17 ( struct V_32 * V_33 ,
struct V_29 * V_35 )
{
F_18 (pos, head, node)
if ( V_35 -> V_20 >= 0 )
return V_35 ;
return NULL ;
}
static int F_19 ( struct V_29 * V_36 , struct V_3 * V_4 ,
int V_18 , V_13 V_37 , int V_38 ,
int V_39 , int V_40 ,
struct V_29 * V_41 )
{
static const char * V_42 ;
static const char * V_43 ;
if ( V_36 -> V_20 != - 1 ) {
const char * V_44 = NULL ;
unsigned int V_45 = 0 ;
double V_46 = 0.0 ;
const char * V_47 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_48 * V_49 = V_6 -> V_14 -> V_50 ;
struct V_10 * V_21 = F_12 ( V_6 , V_18 ) ;
T_2 V_20 = V_36 -> V_20 ;
struct V_29 * V_51 ;
V_51 = F_17 ( & V_6 -> V_14 -> V_16 , V_36 ) ;
while ( V_20 < ( T_2 ) V_37 &&
( V_51 == NULL || V_20 < V_51 -> V_20 ) ) {
if ( V_49 ) {
if ( V_44 == NULL )
V_44 = V_49 [ V_20 ] . V_44 ;
V_46 += V_49 [ V_20 ] . V_46 ;
} else
V_45 += V_21 -> V_19 [ V_20 ] ;
++ V_20 ;
}
if ( V_49 == NULL && V_21 -> V_26 )
V_46 = 100.0 * V_45 / V_21 -> V_26 ;
if ( V_46 < V_38 )
return - 1 ;
if ( V_40 && V_39 >= V_40 )
return 1 ;
if ( V_41 != NULL ) {
F_20 (queue, &notes->src->source, node) {
if ( V_41 == V_36 )
break;
F_19 ( V_41 , V_4 , V_18 , V_37 ,
0 , 0 , 1 , NULL ) ;
}
}
V_47 = F_21 ( V_46 ) ;
if ( V_44 ) {
if ( ! V_42 || strcmp ( V_42 , V_44 )
|| V_47 != V_43 ) {
F_22 ( stdout , V_47 , L_7 , V_44 ) ;
V_42 = V_44 ;
V_43 = V_47 ;
}
}
F_22 ( stdout , V_47 , L_8 , V_46 ) ;
printf ( L_9 ) ;
F_22 ( stdout , V_52 , L_10 , V_36 -> line ) ;
} else if ( V_40 && V_39 >= V_40 )
return 1 ;
else {
if ( V_41 )
return - 1 ;
if ( ! * V_36 -> line )
printf ( L_11 ) ;
else
printf ( L_12 , V_36 -> line ) ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , struct V_1 * V_1 ,
T_3 * V_53 , T_1 V_30 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_29 * V_29 ;
char * line = NULL , * V_54 , * V_55 , * V_56 ;
T_1 V_57 ;
T_2 V_58 , V_20 = - 1 ;
if ( F_24 ( & line , & V_57 , V_53 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_57 != 0 && isspace ( line [ V_57 - 1 ] ) )
line [ -- V_57 ] = '\0' ;
V_56 = strchr ( line , '\n' ) ;
if ( V_56 )
* V_56 = 0 ;
V_58 = - 1 ;
V_54 = line ;
while ( * V_54 ) {
if ( * V_54 != ' ' )
break;
V_54 ++ ;
}
if ( * V_54 ) {
V_58 = F_25 ( V_54 , & V_55 , 16 ) ;
if ( * V_55 != ':' || V_54 == V_55 || V_55 [ 1 ] == '\0' )
V_58 = - 1 ;
}
if ( V_58 != - 1 ) {
V_13 V_12 = F_26 ( V_1 , V_4 -> V_12 ) ,
V_11 = F_26 ( V_1 , V_4 -> V_11 ) ;
V_20 = V_58 - V_12 ;
if ( V_20 < 0 || ( V_13 ) V_58 > V_11 )
V_20 = - 1 ;
}
V_29 = F_13 ( V_20 , line , V_30 ) ;
if ( V_29 == NULL ) {
free ( line ) ;
return - 1 ;
}
F_15 ( & V_6 -> V_14 -> V_16 , V_29 ) ;
return 0 ;
}
int F_27 ( struct V_3 * V_4 , struct V_1 * V_1 , T_1 V_30 )
{
struct V_59 * V_59 = V_1 -> V_59 ;
char * V_60 = F_28 ( V_59 , NULL , 0 ) ;
bool V_61 = true ;
char V_62 [ V_63 * 2 ] ;
T_3 * V_53 ;
int V_64 = 0 ;
char V_65 [ V_63 ] ;
if ( V_60 ) {
snprintf ( V_65 , sizeof( V_65 ) , L_13 ,
V_66 . V_67 , V_60 ) ;
}
if ( V_60 == NULL ) {
if ( V_59 -> V_68 ) {
F_29 ( L_14 ,
V_4 -> V_28 ) ;
return - V_22 ;
}
goto V_69;
} else if ( F_30 ( V_65 , V_62 , sizeof( V_62 ) ) < 0 ||
strstr ( V_62 , L_15 ) ||
F_31 ( V_65 , V_70 ) ) {
free ( V_60 ) ;
V_69:
V_60 = V_59 -> V_71 ;
snprintf ( V_65 , sizeof( V_65 ) , L_13 ,
V_66 . V_67 , V_60 ) ;
V_61 = false ;
}
if ( V_59 -> V_72 == V_73 ) {
char V_74 [ V_75 * 2 + 16 ] = L_16 ;
char * V_76 = NULL ;
if ( V_59 -> V_77 )
goto V_78;
if ( V_59 -> V_68 ) {
F_32 ( V_59 -> V_79 ,
sizeof( V_59 -> V_79 ) , V_74 + 15 ) ;
V_76 = V_74 ;
}
V_64 = - V_80 ;
V_59 -> V_77 = 1 ;
F_29 ( L_17
L_18
L_19 ,
V_4 -> V_28 , V_76 ? : L_20 ) ;
goto V_78;
}
F_33 ( L_21 V_23 L_22 V_23 L_2 , V_24 ,
V_60 , V_4 -> V_28 , V_1 -> V_25 ( V_1 , V_4 -> V_12 ) ,
V_1 -> V_25 ( V_1 , V_4 -> V_11 ) ) ;
F_33 ( L_23 ,
V_59 , V_59 -> V_71 , V_4 , V_4 -> V_28 ) ;
snprintf ( V_62 , sizeof( V_62 ) ,
L_24 V_23
L_25 V_23 L_26 ,
F_26 ( V_1 , V_4 -> V_12 ) ,
F_26 ( V_1 , V_4 -> V_11 ) ,
V_65 , V_60 ) ;
F_33 ( L_27 , V_62 ) ;
V_53 = F_34 ( V_62 , L_28 ) ;
if ( ! V_53 )
goto V_78;
while ( ! feof ( V_53 ) )
if ( F_23 ( V_4 , V_1 , V_53 , V_30 ) < 0 )
break;
F_35 ( V_53 ) ;
V_78:
if ( V_61 )
free ( V_60 ) ;
return V_64 ;
}
static void F_36 ( struct V_81 * V_82 , struct V_48 * V_49 )
{
struct V_48 * V_83 ;
struct V_84 * * V_85 = & V_82 -> V_84 ;
struct V_84 * V_86 = NULL ;
while ( * V_85 != NULL ) {
V_86 = * V_85 ;
V_83 = F_37 ( V_86 , struct V_48 , V_34 ) ;
if ( V_49 -> V_46 > V_83 -> V_46 )
V_85 = & ( * V_85 ) -> V_87 ;
else
V_85 = & ( * V_85 ) -> V_88 ;
}
F_38 ( & V_49 -> V_34 , V_86 , V_85 ) ;
F_39 ( & V_49 -> V_34 , V_82 ) ;
}
static void F_40 ( struct V_3 * V_4 , int V_37 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_48 * V_49 = V_6 -> V_14 -> V_50 ;
int V_89 ;
for ( V_89 = 0 ; V_89 < V_37 ; V_89 ++ )
free ( V_49 [ V_89 ] . V_44 ) ;
free ( V_49 ) ;
V_6 -> V_14 -> V_50 = NULL ;
}
static int F_41 ( struct V_3 * V_4 , struct V_1 * V_1 ,
int V_18 , struct V_81 * V_82 , int V_37 ,
const char * V_60 )
{
V_13 V_12 ;
int V_89 ;
char V_90 [ V_63 * 2 ] ;
struct V_48 * V_49 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_10 * V_21 = F_12 ( V_6 , V_18 ) ;
if ( ! V_21 -> V_26 )
return 0 ;
V_49 = V_6 -> V_14 -> V_50 = calloc ( V_37 , sizeof( struct V_48 ) ) ;
if ( ! V_6 -> V_14 -> V_50 )
return - 1 ;
V_12 = V_1 -> V_25 ( V_1 , V_4 -> V_12 ) ;
for ( V_89 = 0 ; V_89 < V_37 ; V_89 ++ ) {
char * V_44 = NULL ;
T_1 V_57 ;
V_13 V_20 ;
T_3 * V_91 ;
V_49 [ V_89 ] . V_46 = 100.0 * V_21 -> V_19 [ V_89 ] / V_21 -> V_26 ;
if ( V_49 [ V_89 ] . V_46 <= 0.5 )
continue;
V_20 = V_12 + V_89 ;
sprintf ( V_90 , L_29 V_23 , V_60 , V_20 ) ;
V_91 = F_34 ( V_90 , L_28 ) ;
if ( ! V_91 )
continue;
if ( F_24 ( & V_44 , & V_57 , V_91 ) < 0 || ! V_57 )
goto V_51;
V_49 [ V_89 ] . V_44 = malloc ( sizeof( char ) * V_57 + 1 ) ;
if ( ! V_49 [ V_89 ] . V_44 )
goto V_51;
strcpy ( V_49 [ V_89 ] . V_44 , V_44 ) ;
F_36 ( V_82 , & V_49 [ V_89 ] ) ;
V_51:
F_35 ( V_91 ) ;
}
return 0 ;
}
static void F_42 ( struct V_81 * V_82 , const char * V_60 )
{
struct V_48 * V_49 ;
struct V_84 * V_34 ;
printf ( L_30 , V_60 ) ;
printf ( L_31 ) ;
if ( F_43 ( V_82 ) ) {
printf ( L_32 , V_92 ) ;
return;
}
V_34 = F_44 ( V_82 ) ;
while ( V_34 ) {
double V_46 ;
const char * V_47 ;
char * V_44 ;
V_49 = F_37 ( V_34 , struct V_48 , V_34 ) ;
V_46 = V_49 -> V_46 ;
V_47 = F_21 ( V_46 ) ;
V_44 = V_49 -> V_44 ;
F_22 ( stdout , V_47 , L_33 , V_46 , V_44 ) ;
V_34 = F_45 ( V_34 ) ;
}
}
static void F_46 ( struct V_3 * V_4 , int V_18 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_10 * V_21 = F_12 ( V_6 , V_18 ) ;
V_13 V_37 = V_4 -> V_11 - V_4 -> V_12 , V_20 ;
for ( V_20 = 0 ; V_20 < V_37 ; ++ V_20 )
if ( V_21 -> V_19 [ V_20 ] != 0 )
printf ( L_34 V_23 L_35 V_27 L_2 , V_93 / 2 ,
V_4 -> V_12 + V_20 , V_21 -> V_19 [ V_20 ] ) ;
printf ( L_36 V_27 L_2 , V_93 / 2 , L_37 , V_21 -> V_26 ) ;
}
int F_47 ( struct V_3 * V_4 , struct V_1 * V_1 , int V_18 ,
bool V_94 , int V_38 , int V_40 ,
int V_95 )
{
struct V_59 * V_59 = V_1 -> V_59 ;
const char * V_60 = V_59 -> V_71 , * V_96 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_29 * V_35 , * V_41 = NULL ;
int V_39 = 2 , V_97 = 0 ;
int V_98 = 0 ;
V_13 V_37 ;
if ( V_94 )
V_96 = V_60 ;
else
V_96 = F_48 ( V_60 ) ;
V_37 = V_4 -> V_11 - V_4 -> V_12 ;
printf ( L_38 , V_96 ) ;
printf ( L_39 ) ;
if ( V_99 )
F_46 ( V_4 , V_18 ) ;
F_49 (pos, &notes->src->source, node) {
if ( V_95 && V_41 == NULL ) {
V_41 = V_35 ;
V_97 = 0 ;
}
switch ( F_19 ( V_35 , V_4 , V_18 , V_37 , V_38 ,
V_39 , V_40 , V_41 ) ) {
case 0 :
++ V_39 ;
if ( V_95 ) {
V_39 += V_97 ;
V_41 = NULL ;
V_97 = 0 ;
}
break;
case 1 :
++ V_98 ;
break;
case - 1 :
default:
if ( ! V_95 )
break;
if ( V_97 == V_95 )
V_41 = F_50 ( V_41 -> V_34 . V_51 , F_51 ( * V_41 ) , V_34 ) ;
else
++ V_97 ;
break;
}
}
return V_98 ;
}
void F_52 ( struct V_3 * V_4 , int V_18 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_10 * V_21 = F_12 ( V_6 , V_18 ) ;
memset ( V_21 , 0 , V_6 -> V_14 -> V_9 ) ;
}
void F_53 ( struct V_3 * V_4 , int V_18 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_10 * V_21 = F_12 ( V_6 , V_18 ) ;
struct V_29 * V_35 ;
int V_37 = V_4 -> V_11 - V_4 -> V_12 ;
V_21 -> V_26 = 0 ;
F_49 (pos, &notes->src->source, node) {
if ( V_35 -> V_20 != - 1 && V_35 -> V_20 < V_37 ) {
V_21 -> V_19 [ V_35 -> V_20 ] = V_21 -> V_19 [ V_35 -> V_20 ] * 7 / 8 ;
V_21 -> V_26 += V_21 -> V_19 [ V_35 -> V_20 ] ;
}
}
}
void F_54 ( struct V_32 * V_33 )
{
struct V_29 * V_35 , * V_100 ;
F_55 (pos, n, head, node) {
F_56 ( & V_35 -> V_34 ) ;
F_14 ( V_35 ) ;
}
}
int F_57 ( struct V_3 * V_4 , struct V_1 * V_1 , int V_18 ,
bool V_101 , bool V_94 , int V_38 ,
int V_40 )
{
struct V_59 * V_59 = V_1 -> V_59 ;
const char * V_60 = V_59 -> V_71 ;
struct V_81 V_48 = V_102 ;
V_13 V_37 ;
if ( F_27 ( V_4 , V_1 , 0 ) < 0 )
return - 1 ;
V_37 = V_4 -> V_11 - V_4 -> V_12 ;
if ( V_101 ) {
F_41 ( V_4 , V_1 , V_18 , & V_48 ,
V_37 , V_60 ) ;
F_42 ( & V_48 , V_60 ) ;
}
F_47 ( V_4 , V_1 , V_18 , V_94 ,
V_38 , V_40 , 0 ) ;
if ( V_101 )
F_40 ( V_4 , V_37 ) ;
F_54 ( & F_2 ( V_4 ) -> V_14 -> V_16 ) ;
return 0 ;
}
