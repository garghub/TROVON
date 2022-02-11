int F_1 ( struct V_1 * V_1 V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( & V_6 -> V_7 , NULL ) ;
return 0 ;
}
int F_4 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
const T_1 V_8 = V_4 -> V_9 - V_4 -> V_10 + 1 ;
T_1 V_11 = ( sizeof( struct V_12 ) + V_8 * sizeof( V_13 ) ) ;
V_6 -> V_14 = F_5 ( sizeof( * V_6 -> V_14 ) + V_15 . V_16 * V_11 ) ;
if ( V_6 -> V_14 == NULL )
return - 1 ;
V_6 -> V_14 -> V_11 = V_11 ;
V_6 -> V_14 -> V_17 = V_15 . V_16 ;
F_6 ( & V_6 -> V_14 -> V_18 ) ;
return 0 ;
}
void F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_8 ( & V_6 -> V_7 ) ;
if ( V_6 -> V_14 != NULL )
memset ( V_6 -> V_14 -> V_19 , 0 ,
V_6 -> V_14 -> V_17 * V_6 -> V_14 -> V_11 ) ;
F_9 ( & V_6 -> V_7 ) ;
}
int F_10 ( struct V_3 * V_4 , struct V_1 * V_1 ,
int V_20 , V_13 V_21 )
{
unsigned V_22 ;
struct V_5 * V_6 ;
struct V_12 * V_23 ;
V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_14 == NULL )
return - V_24 ;
F_11 ( L_1 V_25 L_2 , V_26 , V_1 -> V_27 ( V_1 , V_21 ) ) ;
if ( V_21 < V_4 -> V_10 || V_21 > V_4 -> V_9 )
return - V_28 ;
V_22 = V_21 - V_4 -> V_10 ;
V_23 = F_12 ( V_6 , V_20 ) ;
V_23 -> V_29 ++ ;
V_23 -> V_21 [ V_22 ] ++ ;
F_11 ( L_3 V_25 L_4 V_25 L_5 V_25
L_6 V_30 L_2 , V_4 -> V_10 , V_4 -> V_31 ,
V_21 , V_21 - V_4 -> V_10 , V_20 , V_23 -> V_21 [ V_22 ] ) ;
return 0 ;
}
static struct V_32 * F_13 ( T_2 V_22 , char * line , T_1 V_33 )
{
struct V_32 * V_34 = malloc ( sizeof( * V_34 ) + V_33 ) ;
if ( V_34 != NULL ) {
V_34 -> V_22 = V_22 ;
V_34 -> line = line ;
}
return V_34 ;
}
void F_14 ( struct V_32 * V_34 )
{
free ( V_34 -> line ) ;
free ( V_34 ) ;
}
static void F_15 ( struct V_35 * V_36 , struct V_32 * line )
{
F_16 ( & line -> V_37 , V_36 ) ;
}
struct V_32 * F_17 ( struct V_35 * V_36 ,
struct V_32 * V_38 )
{
F_18 (pos, head, node)
if ( V_38 -> V_22 >= 0 )
return V_38 ;
return NULL ;
}
static int F_19 ( struct V_32 * V_39 , struct V_3 * V_4 ,
int V_20 , V_13 V_40 , int V_41 ,
int V_42 , int V_43 ,
struct V_32 * V_44 )
{
static const char * V_45 ;
static const char * V_46 ;
if ( V_39 -> V_22 != - 1 ) {
const char * V_47 = NULL ;
unsigned int V_48 = 0 ;
double V_49 = 0.0 ;
const char * V_50 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_51 * V_52 = V_6 -> V_14 -> V_53 ;
struct V_12 * V_23 = F_12 ( V_6 , V_20 ) ;
T_2 V_22 = V_39 -> V_22 ;
struct V_32 * V_54 ;
V_54 = F_17 ( & V_6 -> V_14 -> V_18 , V_39 ) ;
while ( V_22 < ( T_2 ) V_40 &&
( V_54 == NULL || V_22 < V_54 -> V_22 ) ) {
if ( V_52 ) {
if ( V_47 == NULL )
V_47 = V_52 [ V_22 ] . V_47 ;
V_49 += V_52 [ V_22 ] . V_49 ;
} else
V_48 += V_23 -> V_21 [ V_22 ] ;
++ V_22 ;
}
if ( V_52 == NULL && V_23 -> V_29 )
V_49 = 100.0 * V_48 / V_23 -> V_29 ;
if ( V_49 < V_41 )
return - 1 ;
if ( V_43 && V_42 >= V_43 )
return 1 ;
if ( V_44 != NULL ) {
F_20 (queue, &notes->src->source, node) {
if ( V_44 == V_39 )
break;
F_19 ( V_44 , V_4 , V_20 , V_40 ,
0 , 0 , 1 , NULL ) ;
}
}
V_50 = F_21 ( V_49 ) ;
if ( V_47 ) {
if ( ! V_45 || strcmp ( V_45 , V_47 )
|| V_50 != V_46 ) {
F_22 ( stdout , V_50 , L_7 , V_47 ) ;
V_45 = V_47 ;
V_46 = V_50 ;
}
}
F_22 ( stdout , V_50 , L_8 , V_49 ) ;
printf ( L_9 ) ;
F_22 ( stdout , V_55 , L_10 , V_39 -> line ) ;
} else if ( V_43 && V_42 >= V_43 )
return 1 ;
else {
if ( V_44 )
return - 1 ;
if ( ! * V_39 -> line )
printf ( L_11 ) ;
else
printf ( L_12 , V_39 -> line ) ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , struct V_1 * V_1 ,
T_3 * V_56 , T_1 V_33 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_32 * V_32 ;
char * line = NULL , * V_57 , * V_58 , * V_59 ;
T_1 V_60 ;
T_2 V_61 , V_22 = - 1 ;
if ( F_24 ( & line , & V_60 , V_56 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_60 != 0 && isspace ( line [ V_60 - 1 ] ) )
line [ -- V_60 ] = '\0' ;
V_59 = strchr ( line , '\n' ) ;
if ( V_59 )
* V_59 = 0 ;
V_61 = - 1 ;
V_57 = line ;
while ( * V_57 ) {
if ( * V_57 != ' ' )
break;
V_57 ++ ;
}
if ( * V_57 ) {
V_61 = F_25 ( V_57 , & V_58 , 16 ) ;
if ( * V_58 != ':' || V_57 == V_58 || V_58 [ 1 ] == '\0' )
V_61 = - 1 ;
}
if ( V_61 != - 1 ) {
V_13 V_10 = F_26 ( V_1 , V_4 -> V_10 ) ,
V_9 = F_26 ( V_1 , V_4 -> V_9 ) ;
V_22 = V_61 - V_10 ;
if ( V_22 < 0 || ( V_13 ) V_61 > V_9 )
V_22 = - 1 ;
}
V_32 = F_13 ( V_22 , line , V_33 ) ;
if ( V_32 == NULL ) {
free ( line ) ;
return - 1 ;
}
F_15 ( & V_6 -> V_14 -> V_18 , V_32 ) ;
return 0 ;
}
int F_27 ( struct V_3 * V_4 , struct V_1 * V_1 , T_1 V_33 )
{
struct V_62 * V_62 = V_1 -> V_62 ;
char * V_63 = F_28 ( V_62 , NULL , 0 ) ;
bool V_64 = true ;
char V_65 [ V_66 * 2 ] ;
T_3 * V_56 ;
int V_67 = 0 ;
char V_68 [ V_66 ] ;
if ( V_63 ) {
snprintf ( V_68 , sizeof( V_68 ) , L_13 ,
V_15 . V_69 , V_63 ) ;
}
if ( V_63 == NULL ) {
if ( V_62 -> V_70 ) {
F_29 ( L_14 ,
V_4 -> V_31 ) ;
return - V_24 ;
}
goto V_71;
} else if ( F_30 ( V_68 , V_65 , sizeof( V_65 ) ) < 0 ||
strstr ( V_65 , L_15 ) ||
F_31 ( V_68 , V_72 ) ) {
free ( V_63 ) ;
V_71:
V_63 = V_62 -> V_73 ;
snprintf ( V_68 , sizeof( V_68 ) , L_13 ,
V_15 . V_69 , V_63 ) ;
V_64 = false ;
}
if ( V_62 -> V_74 == V_75 ) {
char V_76 [ V_77 * 2 + 16 ] = L_16 ;
char * V_78 = NULL ;
if ( V_62 -> V_79 )
goto V_80;
if ( V_62 -> V_70 ) {
F_32 ( V_62 -> V_81 ,
sizeof( V_62 -> V_81 ) , V_76 + 15 ) ;
V_78 = V_76 ;
}
V_67 = - V_82 ;
V_62 -> V_79 = 1 ;
F_29 ( L_17
L_18
L_19
L_20
L_21
L_22 ,
V_4 -> V_31 , V_78 ? : L_23 ) ;
goto V_80;
}
F_33 ( L_24 V_25 L_25 V_25 L_2 , V_26 ,
V_63 , V_4 -> V_31 , V_1 -> V_27 ( V_1 , V_4 -> V_10 ) ,
V_1 -> V_27 ( V_1 , V_4 -> V_9 ) ) ;
F_33 ( L_26 ,
V_62 , V_62 -> V_73 , V_4 , V_4 -> V_31 ) ;
snprintf ( V_65 , sizeof( V_65 ) ,
L_27 V_25
L_28 V_25
L_29 ,
V_83 ? L_30 : L_23 ,
V_83 ? V_83 : L_23 ,
F_26 ( V_1 , V_4 -> V_10 ) ,
F_26 ( V_1 , V_4 -> V_9 + 1 ) ,
V_15 . V_84 ? L_23 : L_31 ,
V_15 . V_85 ? L_32 : L_23 ,
V_68 , V_63 ) ;
F_33 ( L_33 , V_65 ) ;
V_56 = F_34 ( V_65 , L_34 ) ;
if ( ! V_56 )
goto V_80;
while ( ! feof ( V_56 ) )
if ( F_23 ( V_4 , V_1 , V_56 , V_33 ) < 0 )
break;
F_35 ( V_56 ) ;
V_80:
if ( V_64 )
free ( V_63 ) ;
return V_67 ;
}
static void F_36 ( struct V_86 * V_87 , struct V_51 * V_52 )
{
struct V_51 * V_88 ;
struct V_89 * * V_90 = & V_87 -> V_89 ;
struct V_89 * V_91 = NULL ;
while ( * V_90 != NULL ) {
V_91 = * V_90 ;
V_88 = F_37 ( V_91 , struct V_51 , V_37 ) ;
if ( V_52 -> V_49 > V_88 -> V_49 )
V_90 = & ( * V_90 ) -> V_92 ;
else
V_90 = & ( * V_90 ) -> V_93 ;
}
F_38 ( & V_52 -> V_37 , V_91 , V_90 ) ;
F_39 ( & V_52 -> V_37 , V_87 ) ;
}
static void F_40 ( struct V_3 * V_4 , int V_40 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_51 * V_52 = V_6 -> V_14 -> V_53 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_40 ; V_94 ++ )
free ( V_52 [ V_94 ] . V_47 ) ;
free ( V_52 ) ;
V_6 -> V_14 -> V_53 = NULL ;
}
static int F_41 ( struct V_3 * V_4 , struct V_1 * V_1 ,
int V_20 , struct V_86 * V_87 , int V_40 ,
const char * V_63 )
{
V_13 V_10 ;
int V_94 ;
char V_95 [ V_66 * 2 ] ;
struct V_51 * V_52 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_12 * V_23 = F_12 ( V_6 , V_20 ) ;
if ( ! V_23 -> V_29 )
return 0 ;
V_52 = V_6 -> V_14 -> V_53 = calloc ( V_40 , sizeof( struct V_51 ) ) ;
if ( ! V_6 -> V_14 -> V_53 )
return - 1 ;
V_10 = F_26 ( V_1 , V_4 -> V_10 ) ;
for ( V_94 = 0 ; V_94 < V_40 ; V_94 ++ ) {
char * V_47 = NULL ;
T_1 V_60 ;
V_13 V_22 ;
T_3 * V_96 ;
V_52 [ V_94 ] . V_49 = 100.0 * V_23 -> V_21 [ V_94 ] / V_23 -> V_29 ;
if ( V_52 [ V_94 ] . V_49 <= 0.5 )
continue;
V_22 = V_10 + V_94 ;
sprintf ( V_95 , L_35 V_25 , V_63 , V_22 ) ;
V_96 = F_34 ( V_95 , L_34 ) ;
if ( ! V_96 )
continue;
if ( F_24 ( & V_47 , & V_60 , V_96 ) < 0 || ! V_60 )
goto V_54;
V_52 [ V_94 ] . V_47 = malloc ( sizeof( char ) * V_60 + 1 ) ;
if ( ! V_52 [ V_94 ] . V_47 )
goto V_54;
strcpy ( V_52 [ V_94 ] . V_47 , V_47 ) ;
F_36 ( V_87 , & V_52 [ V_94 ] ) ;
V_54:
F_35 ( V_96 ) ;
}
return 0 ;
}
static void F_42 ( struct V_86 * V_87 , const char * V_63 )
{
struct V_51 * V_52 ;
struct V_89 * V_37 ;
printf ( L_36 , V_63 ) ;
printf ( L_37 ) ;
if ( F_43 ( V_87 ) ) {
printf ( L_38 , V_97 ) ;
return;
}
V_37 = F_44 ( V_87 ) ;
while ( V_37 ) {
double V_49 ;
const char * V_50 ;
char * V_47 ;
V_52 = F_37 ( V_37 , struct V_51 , V_37 ) ;
V_49 = V_52 -> V_49 ;
V_50 = F_21 ( V_49 ) ;
V_47 = V_52 -> V_47 ;
F_22 ( stdout , V_50 , L_39 , V_49 , V_47 ) ;
V_37 = F_45 ( V_37 ) ;
}
}
static void F_46 ( struct V_3 * V_4 , int V_20 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_12 * V_23 = F_12 ( V_6 , V_20 ) ;
V_13 V_40 = V_4 -> V_9 - V_4 -> V_10 , V_22 ;
for ( V_22 = 0 ; V_22 < V_40 ; ++ V_22 )
if ( V_23 -> V_21 [ V_22 ] != 0 )
printf ( L_40 V_25 L_41 V_30 L_2 , V_98 / 2 ,
V_4 -> V_10 + V_22 , V_23 -> V_21 [ V_22 ] ) ;
printf ( L_42 V_30 L_2 , V_98 / 2 , L_43 , V_23 -> V_29 ) ;
}
int F_47 ( struct V_3 * V_4 , struct V_1 * V_1 , int V_20 ,
bool V_99 , int V_41 , int V_43 ,
int V_100 )
{
struct V_62 * V_62 = V_1 -> V_62 ;
const char * V_63 = V_62 -> V_73 , * V_101 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_32 * V_38 , * V_44 = NULL ;
int V_42 = 2 , V_102 = 0 ;
int V_103 = 0 ;
V_13 V_40 ;
if ( V_99 )
V_101 = V_63 ;
else
V_101 = F_48 ( V_63 ) ;
V_40 = V_4 -> V_9 - V_4 -> V_10 ;
printf ( L_44 , V_101 ) ;
printf ( L_45 ) ;
if ( V_104 )
F_46 ( V_4 , V_20 ) ;
F_49 (pos, &notes->src->source, node) {
if ( V_100 && V_44 == NULL ) {
V_44 = V_38 ;
V_102 = 0 ;
}
switch ( F_19 ( V_38 , V_4 , V_20 , V_40 , V_41 ,
V_42 , V_43 , V_44 ) ) {
case 0 :
++ V_42 ;
if ( V_100 ) {
V_42 += V_102 ;
V_44 = NULL ;
V_102 = 0 ;
}
break;
case 1 :
++ V_103 ;
break;
case - 1 :
default:
if ( ! V_100 )
break;
if ( V_102 == V_100 )
V_44 = F_50 ( V_44 -> V_37 . V_54 , F_51 ( * V_44 ) , V_37 ) ;
else
++ V_102 ;
break;
}
}
return V_103 ;
}
void F_52 ( struct V_3 * V_4 , int V_20 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_12 * V_23 = F_12 ( V_6 , V_20 ) ;
memset ( V_23 , 0 , V_6 -> V_14 -> V_11 ) ;
}
void F_53 ( struct V_3 * V_4 , int V_20 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_12 * V_23 = F_12 ( V_6 , V_20 ) ;
int V_40 = V_4 -> V_9 - V_4 -> V_10 , V_22 ;
V_23 -> V_29 = 0 ;
for ( V_22 = 0 ; V_22 < V_40 ; ++ V_22 ) {
V_23 -> V_21 [ V_22 ] = V_23 -> V_21 [ V_22 ] * 7 / 8 ;
V_23 -> V_29 += V_23 -> V_21 [ V_22 ] ;
}
}
void F_54 ( struct V_35 * V_36 )
{
struct V_32 * V_38 , * V_105 ;
F_55 (pos, n, head, node) {
F_56 ( & V_38 -> V_37 ) ;
F_14 ( V_38 ) ;
}
}
int F_57 ( struct V_3 * V_4 , struct V_1 * V_1 , int V_20 ,
bool V_106 , bool V_99 , int V_41 ,
int V_43 )
{
struct V_62 * V_62 = V_1 -> V_62 ;
const char * V_63 = V_62 -> V_73 ;
struct V_86 V_51 = V_107 ;
V_13 V_40 ;
if ( F_27 ( V_4 , V_1 , 0 ) < 0 )
return - 1 ;
V_40 = V_4 -> V_9 - V_4 -> V_10 ;
if ( V_106 ) {
F_41 ( V_4 , V_1 , V_20 , & V_51 ,
V_40 , V_63 ) ;
F_42 ( & V_51 , V_63 ) ;
}
F_47 ( V_4 , V_1 , V_20 , V_99 ,
V_41 , V_43 , 0 ) ;
if ( V_106 )
F_40 ( V_4 , V_40 ) ;
F_54 ( & F_2 ( V_4 ) -> V_14 -> V_18 ) ;
return 0 ;
}
