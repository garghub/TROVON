int F_1 ( struct V_1 * V_1 V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( & V_6 -> V_7 , NULL ) ;
return 0 ;
}
int F_4 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_8 = ( sizeof( struct V_9 ) +
( V_4 -> V_10 - V_4 -> V_11 ) * sizeof( V_12 ) ) ;
V_6 -> V_13 = F_5 ( sizeof( * V_6 -> V_13 ) + V_14 . V_15 * V_8 ) ;
if ( V_6 -> V_13 == NULL )
return - 1 ;
V_6 -> V_13 -> V_8 = V_8 ;
V_6 -> V_13 -> V_16 = V_14 . V_15 ;
F_6 ( & V_6 -> V_13 -> V_17 ) ;
return 0 ;
}
void F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_8 ( & V_6 -> V_7 ) ;
if ( V_6 -> V_13 != NULL )
memset ( V_6 -> V_13 -> V_18 , 0 ,
V_6 -> V_13 -> V_16 * V_6 -> V_13 -> V_8 ) ;
F_9 ( & V_6 -> V_7 ) ;
}
int F_10 ( struct V_3 * V_4 , struct V_1 * V_1 ,
int V_19 , V_12 V_20 )
{
unsigned V_21 ;
struct V_5 * V_6 ;
struct V_9 * V_22 ;
V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_13 == NULL )
return - V_23 ;
F_11 ( L_1 V_24 L_2 , V_25 , V_1 -> V_26 ( V_1 , V_20 ) ) ;
if ( V_20 >= V_4 -> V_10 )
return 0 ;
V_21 = V_20 - V_4 -> V_11 ;
V_22 = F_12 ( V_6 , V_19 ) ;
V_22 -> V_27 ++ ;
V_22 -> V_20 [ V_21 ] ++ ;
F_11 ( L_3 V_24 L_4 V_24 L_5 V_24
L_6 V_28 L_2 , V_4 -> V_11 , V_4 -> V_29 ,
V_20 , V_20 - V_4 -> V_11 , V_19 , V_22 -> V_20 [ V_21 ] ) ;
return 0 ;
}
static struct V_30 * F_13 ( T_2 V_21 , char * line , T_1 V_31 )
{
struct V_30 * V_32 = malloc ( sizeof( * V_32 ) + V_31 ) ;
if ( V_32 != NULL ) {
V_32 -> V_21 = V_21 ;
V_32 -> line = line ;
}
return V_32 ;
}
void F_14 ( struct V_30 * V_32 )
{
free ( V_32 -> line ) ;
free ( V_32 ) ;
}
static void F_15 ( struct V_33 * V_34 , struct V_30 * line )
{
F_16 ( & line -> V_35 , V_34 ) ;
}
struct V_30 * F_17 ( struct V_33 * V_34 ,
struct V_30 * V_36 )
{
F_18 (pos, head, node)
if ( V_36 -> V_21 >= 0 )
return V_36 ;
return NULL ;
}
static int F_19 ( struct V_30 * V_37 , struct V_3 * V_4 ,
int V_19 , V_12 V_38 , int V_39 ,
int V_40 , int V_41 ,
struct V_30 * V_42 )
{
static const char * V_43 ;
static const char * V_44 ;
if ( V_37 -> V_21 != - 1 ) {
const char * V_45 = NULL ;
unsigned int V_46 = 0 ;
double V_47 = 0.0 ;
const char * V_48 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_49 * V_50 = V_6 -> V_13 -> V_51 ;
struct V_9 * V_22 = F_12 ( V_6 , V_19 ) ;
T_2 V_21 = V_37 -> V_21 ;
struct V_30 * V_52 ;
V_52 = F_17 ( & V_6 -> V_13 -> V_17 , V_37 ) ;
while ( V_21 < ( T_2 ) V_38 &&
( V_52 == NULL || V_21 < V_52 -> V_21 ) ) {
if ( V_50 ) {
if ( V_45 == NULL )
V_45 = V_50 [ V_21 ] . V_45 ;
V_47 += V_50 [ V_21 ] . V_47 ;
} else
V_46 += V_22 -> V_20 [ V_21 ] ;
++ V_21 ;
}
if ( V_50 == NULL && V_22 -> V_27 )
V_47 = 100.0 * V_46 / V_22 -> V_27 ;
if ( V_47 < V_39 )
return - 1 ;
if ( V_41 && V_40 >= V_41 )
return 1 ;
if ( V_42 != NULL ) {
F_20 (queue, &notes->src->source, node) {
if ( V_42 == V_37 )
break;
F_19 ( V_42 , V_4 , V_19 , V_38 ,
0 , 0 , 1 , NULL ) ;
}
}
V_48 = F_21 ( V_47 ) ;
if ( V_45 ) {
if ( ! V_43 || strcmp ( V_43 , V_45 )
|| V_48 != V_44 ) {
F_22 ( stdout , V_48 , L_7 , V_45 ) ;
V_43 = V_45 ;
V_44 = V_48 ;
}
}
F_22 ( stdout , V_48 , L_8 , V_47 ) ;
printf ( L_9 ) ;
F_22 ( stdout , V_53 , L_10 , V_37 -> line ) ;
} else if ( V_41 && V_40 >= V_41 )
return 1 ;
else {
if ( V_42 )
return - 1 ;
if ( ! * V_37 -> line )
printf ( L_11 ) ;
else
printf ( L_12 , V_37 -> line ) ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , struct V_1 * V_1 ,
T_3 * V_54 , T_1 V_31 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_30 * V_30 ;
char * line = NULL , * V_55 , * V_56 , * V_57 ;
T_1 V_58 ;
T_2 V_59 , V_21 = - 1 ;
if ( F_24 ( & line , & V_58 , V_54 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_58 != 0 && isspace ( line [ V_58 - 1 ] ) )
line [ -- V_58 ] = '\0' ;
V_57 = strchr ( line , '\n' ) ;
if ( V_57 )
* V_57 = 0 ;
V_59 = - 1 ;
V_55 = line ;
while ( * V_55 ) {
if ( * V_55 != ' ' )
break;
V_55 ++ ;
}
if ( * V_55 ) {
V_59 = F_25 ( V_55 , & V_56 , 16 ) ;
if ( * V_56 != ':' || V_55 == V_56 || V_56 [ 1 ] == '\0' )
V_59 = - 1 ;
}
if ( V_59 != - 1 ) {
V_12 V_11 = F_26 ( V_1 , V_4 -> V_11 ) ,
V_10 = F_26 ( V_1 , V_4 -> V_10 ) ;
V_21 = V_59 - V_11 ;
if ( V_21 < 0 || ( V_12 ) V_59 > V_10 )
V_21 = - 1 ;
}
V_30 = F_13 ( V_21 , line , V_31 ) ;
if ( V_30 == NULL ) {
free ( line ) ;
return - 1 ;
}
F_15 ( & V_6 -> V_13 -> V_17 , V_30 ) ;
return 0 ;
}
int F_27 ( struct V_3 * V_4 , struct V_1 * V_1 , T_1 V_31 )
{
struct V_60 * V_60 = V_1 -> V_60 ;
char * V_61 = F_28 ( V_60 , NULL , 0 ) ;
bool V_62 = true ;
char V_63 [ V_64 * 2 ] ;
T_3 * V_54 ;
int V_65 = 0 ;
char V_66 [ V_64 ] ;
if ( V_61 ) {
snprintf ( V_66 , sizeof( V_66 ) , L_13 ,
V_14 . V_67 , V_61 ) ;
}
if ( V_61 == NULL ) {
if ( V_60 -> V_68 ) {
F_29 ( L_14 ,
V_4 -> V_29 ) ;
return - V_23 ;
}
goto V_69;
} else if ( F_30 ( V_66 , V_63 , sizeof( V_63 ) ) < 0 ||
strstr ( V_63 , L_15 ) ||
F_31 ( V_66 , V_70 ) ) {
free ( V_61 ) ;
V_69:
V_61 = V_60 -> V_71 ;
snprintf ( V_66 , sizeof( V_66 ) , L_13 ,
V_14 . V_67 , V_61 ) ;
V_62 = false ;
}
if ( V_60 -> V_72 == V_73 ) {
char V_74 [ V_75 * 2 + 16 ] = L_16 ;
char * V_76 = NULL ;
if ( V_60 -> V_77 )
goto V_78;
if ( V_60 -> V_68 ) {
F_32 ( V_60 -> V_79 ,
sizeof( V_60 -> V_79 ) , V_74 + 15 ) ;
V_76 = V_74 ;
}
V_65 = - V_80 ;
V_60 -> V_77 = 1 ;
F_29 ( L_17
L_18
L_19
L_20
L_21
L_22 ,
V_4 -> V_29 , V_76 ? : L_23 ) ;
goto V_78;
}
F_33 ( L_24 V_24 L_25 V_24 L_2 , V_25 ,
V_61 , V_4 -> V_29 , V_1 -> V_26 ( V_1 , V_4 -> V_11 ) ,
V_1 -> V_26 ( V_1 , V_4 -> V_10 ) ) ;
F_33 ( L_26 ,
V_60 , V_60 -> V_71 , V_4 , V_4 -> V_29 ) ;
snprintf ( V_63 , sizeof( V_63 ) ,
L_27 V_24
L_28 V_24
L_29 ,
V_81 ? L_30 : L_23 ,
V_81 ? V_81 : L_23 ,
F_26 ( V_1 , V_4 -> V_11 ) ,
F_26 ( V_1 , V_4 -> V_10 + 1 ) ,
V_14 . V_82 ? L_23 : L_31 ,
V_14 . V_83 ? L_32 : L_23 ,
V_66 , V_61 ) ;
F_33 ( L_33 , V_63 ) ;
V_54 = F_34 ( V_63 , L_34 ) ;
if ( ! V_54 )
goto V_78;
while ( ! feof ( V_54 ) )
if ( F_23 ( V_4 , V_1 , V_54 , V_31 ) < 0 )
break;
F_35 ( V_54 ) ;
V_78:
if ( V_62 )
free ( V_61 ) ;
return V_65 ;
}
static void F_36 ( struct V_84 * V_85 , struct V_49 * V_50 )
{
struct V_49 * V_86 ;
struct V_87 * * V_88 = & V_85 -> V_87 ;
struct V_87 * V_89 = NULL ;
while ( * V_88 != NULL ) {
V_89 = * V_88 ;
V_86 = F_37 ( V_89 , struct V_49 , V_35 ) ;
if ( V_50 -> V_47 > V_86 -> V_47 )
V_88 = & ( * V_88 ) -> V_90 ;
else
V_88 = & ( * V_88 ) -> V_91 ;
}
F_38 ( & V_50 -> V_35 , V_89 , V_88 ) ;
F_39 ( & V_50 -> V_35 , V_85 ) ;
}
static void F_40 ( struct V_3 * V_4 , int V_38 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_49 * V_50 = V_6 -> V_13 -> V_51 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_38 ; V_92 ++ )
free ( V_50 [ V_92 ] . V_45 ) ;
free ( V_50 ) ;
V_6 -> V_13 -> V_51 = NULL ;
}
static int F_41 ( struct V_3 * V_4 , struct V_1 * V_1 ,
int V_19 , struct V_84 * V_85 , int V_38 ,
const char * V_61 )
{
V_12 V_11 ;
int V_92 ;
char V_93 [ V_64 * 2 ] ;
struct V_49 * V_50 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_9 * V_22 = F_12 ( V_6 , V_19 ) ;
if ( ! V_22 -> V_27 )
return 0 ;
V_50 = V_6 -> V_13 -> V_51 = calloc ( V_38 , sizeof( struct V_49 ) ) ;
if ( ! V_6 -> V_13 -> V_51 )
return - 1 ;
V_11 = V_1 -> V_26 ( V_1 , V_4 -> V_11 ) ;
for ( V_92 = 0 ; V_92 < V_38 ; V_92 ++ ) {
char * V_45 = NULL ;
T_1 V_58 ;
V_12 V_21 ;
T_3 * V_94 ;
V_50 [ V_92 ] . V_47 = 100.0 * V_22 -> V_20 [ V_92 ] / V_22 -> V_27 ;
if ( V_50 [ V_92 ] . V_47 <= 0.5 )
continue;
V_21 = V_11 + V_92 ;
sprintf ( V_93 , L_35 V_24 , V_61 , V_21 ) ;
V_94 = F_34 ( V_93 , L_34 ) ;
if ( ! V_94 )
continue;
if ( F_24 ( & V_45 , & V_58 , V_94 ) < 0 || ! V_58 )
goto V_52;
V_50 [ V_92 ] . V_45 = malloc ( sizeof( char ) * V_58 + 1 ) ;
if ( ! V_50 [ V_92 ] . V_45 )
goto V_52;
strcpy ( V_50 [ V_92 ] . V_45 , V_45 ) ;
F_36 ( V_85 , & V_50 [ V_92 ] ) ;
V_52:
F_35 ( V_94 ) ;
}
return 0 ;
}
static void F_42 ( struct V_84 * V_85 , const char * V_61 )
{
struct V_49 * V_50 ;
struct V_87 * V_35 ;
printf ( L_36 , V_61 ) ;
printf ( L_37 ) ;
if ( F_43 ( V_85 ) ) {
printf ( L_38 , V_95 ) ;
return;
}
V_35 = F_44 ( V_85 ) ;
while ( V_35 ) {
double V_47 ;
const char * V_48 ;
char * V_45 ;
V_50 = F_37 ( V_35 , struct V_49 , V_35 ) ;
V_47 = V_50 -> V_47 ;
V_48 = F_21 ( V_47 ) ;
V_45 = V_50 -> V_45 ;
F_22 ( stdout , V_48 , L_39 , V_47 , V_45 ) ;
V_35 = F_45 ( V_35 ) ;
}
}
static void F_46 ( struct V_3 * V_4 , int V_19 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_9 * V_22 = F_12 ( V_6 , V_19 ) ;
V_12 V_38 = V_4 -> V_10 - V_4 -> V_11 , V_21 ;
for ( V_21 = 0 ; V_21 < V_38 ; ++ V_21 )
if ( V_22 -> V_20 [ V_21 ] != 0 )
printf ( L_40 V_24 L_41 V_28 L_2 , V_96 / 2 ,
V_4 -> V_11 + V_21 , V_22 -> V_20 [ V_21 ] ) ;
printf ( L_42 V_28 L_2 , V_96 / 2 , L_43 , V_22 -> V_27 ) ;
}
int F_47 ( struct V_3 * V_4 , struct V_1 * V_1 , int V_19 ,
bool V_97 , int V_39 , int V_41 ,
int V_98 )
{
struct V_60 * V_60 = V_1 -> V_60 ;
const char * V_61 = V_60 -> V_71 , * V_99 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_30 * V_36 , * V_42 = NULL ;
int V_40 = 2 , V_100 = 0 ;
int V_101 = 0 ;
V_12 V_38 ;
if ( V_97 )
V_99 = V_61 ;
else
V_99 = F_48 ( V_61 ) ;
V_38 = V_4 -> V_10 - V_4 -> V_11 ;
printf ( L_44 , V_99 ) ;
printf ( L_45 ) ;
if ( V_102 )
F_46 ( V_4 , V_19 ) ;
F_49 (pos, &notes->src->source, node) {
if ( V_98 && V_42 == NULL ) {
V_42 = V_36 ;
V_100 = 0 ;
}
switch ( F_19 ( V_36 , V_4 , V_19 , V_38 , V_39 ,
V_40 , V_41 , V_42 ) ) {
case 0 :
++ V_40 ;
if ( V_98 ) {
V_40 += V_100 ;
V_42 = NULL ;
V_100 = 0 ;
}
break;
case 1 :
++ V_101 ;
break;
case - 1 :
default:
if ( ! V_98 )
break;
if ( V_100 == V_98 )
V_42 = F_50 ( V_42 -> V_35 . V_52 , F_51 ( * V_42 ) , V_35 ) ;
else
++ V_100 ;
break;
}
}
return V_101 ;
}
void F_52 ( struct V_3 * V_4 , int V_19 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_9 * V_22 = F_12 ( V_6 , V_19 ) ;
memset ( V_22 , 0 , V_6 -> V_13 -> V_8 ) ;
}
void F_53 ( struct V_3 * V_4 , int V_19 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_9 * V_22 = F_12 ( V_6 , V_19 ) ;
struct V_30 * V_36 ;
int V_38 = V_4 -> V_10 - V_4 -> V_11 ;
V_22 -> V_27 = 0 ;
F_49 (pos, &notes->src->source, node) {
if ( V_36 -> V_21 != - 1 && V_36 -> V_21 < V_38 ) {
V_22 -> V_20 [ V_36 -> V_21 ] = V_22 -> V_20 [ V_36 -> V_21 ] * 7 / 8 ;
V_22 -> V_27 += V_22 -> V_20 [ V_36 -> V_21 ] ;
}
}
}
void F_54 ( struct V_33 * V_34 )
{
struct V_30 * V_36 , * V_103 ;
F_55 (pos, n, head, node) {
F_56 ( & V_36 -> V_35 ) ;
F_14 ( V_36 ) ;
}
}
int F_57 ( struct V_3 * V_4 , struct V_1 * V_1 , int V_19 ,
bool V_104 , bool V_97 , int V_39 ,
int V_41 )
{
struct V_60 * V_60 = V_1 -> V_60 ;
const char * V_61 = V_60 -> V_71 ;
struct V_84 V_49 = V_105 ;
V_12 V_38 ;
if ( F_27 ( V_4 , V_1 , 0 ) < 0 )
return - 1 ;
V_38 = V_4 -> V_10 - V_4 -> V_11 ;
if ( V_104 ) {
F_41 ( V_4 , V_1 , V_19 , & V_49 ,
V_38 , V_61 ) ;
F_42 ( & V_49 , V_61 ) ;
}
F_47 ( V_4 , V_1 , V_19 , V_97 ,
V_39 , V_41 , 0 ) ;
if ( V_104 )
F_40 ( V_4 , V_38 ) ;
F_54 ( & F_2 ( V_4 ) -> V_13 -> V_17 ) ;
return 0 ;
}
