static unsigned char F_1 ( void )
{
T_1 V_1 = 0x00FF ;
T_2 V_2 = * ( ( T_2 * ) & V_1 ) ;
if ( V_2 == 0 )
return V_3 ;
else
return V_4 ;
}
static unsigned long F_2 ( T_3 * V_5 , unsigned long V_6 )
{
T_4 * V_7 ;
unsigned int V_8 , V_9 ;
V_7 = ( void * ) V_5 + V_5 -> V_10 ;
if ( V_5 -> V_11 == V_12 )
V_9 = V_7 [ 0 ] . V_13 ;
else
V_9 = V_5 -> V_11 ;
for ( V_8 = 1 ; V_8 < V_9 ; V_8 ++ ) {
unsigned long V_14 = V_7 [ V_8 ] . V_15 ;
unsigned long V_16 = V_14 + V_7 [ V_8 ] . V_13 ;
unsigned long V_17 = V_7 [ V_8 ] . V_18 ;
if ( V_6 >= V_14 && V_6 <= V_16 )
return V_6 - V_14 + V_17 ;
}
return 0 ;
}
static void F_3 ( T_3 * V_5 , T_5 * V_19 , char * V_20 ,
struct V_21 * V_22 )
{
char V_23 [ V_24 ] ;
char * V_25 , * V_26 , * V_27 ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = 0 ;
V_22 -> V_17 = 0 ;
if ( fseek ( V_19 , 0 , V_30 ) != 0 ) {
perror ( L_1 ) ;
exit ( V_31 ) ;
}
while ( fgets ( V_23 , V_24 , V_19 ) ) {
V_26 = strchr ( V_23 , '\n' ) ;
if ( ! V_26 ) {
F_4 ( L_2 ) ;
return;
}
V_27 = strstr ( V_23 , V_20 ) ;
if ( V_27 )
break;
}
if ( ! V_27 ) {
F_4 ( L_3 , V_20 ) ;
return;
}
V_25 = strchr ( V_23 , ' ' ) ;
if ( ! V_25 )
return;
* V_25 = '\0' ;
V_22 -> V_29 = strtoul ( V_23 , NULL , 16 ) ;
if ( V_22 -> V_29 == 0 )
return;
V_22 -> V_17 = F_2 ( V_5 , V_22 -> V_29 ) ;
V_22 -> V_20 = V_20 ;
V_22 -> V_32 = ( void * ) V_5 + V_22 -> V_17 ;
}
static T_6 * F_5 ( T_3 * V_5 , T_4 * V_33 , char * V_20 )
{
T_6 * V_21 , * V_34 ;
char * V_35 , * V_36 ;
unsigned int V_37 ;
T_4 * V_7 ;
int V_8 , V_27 ;
V_7 = ( void * ) V_5 + V_5 -> V_10 ;
V_37 = V_33 -> V_38 ;
V_34 = ( void * ) V_5 + V_33 -> V_18 ;
V_27 = V_33 -> V_13 / V_33 -> V_39 ;
V_35 = ( void * ) V_5 + V_7 [ V_37 ] . V_18 ;
for ( V_8 = 0 ; V_8 < V_27 ; V_8 ++ ) {
V_21 = & V_34 [ V_8 ] ;
V_36 = V_35 + V_21 -> V_40 ;
if ( strcmp ( V_36 , V_20 ) == 0 )
return V_21 ;
}
F_4 ( L_3 , V_20 ) ;
return NULL ;
}
static void F_6 ( T_3 * V_5 , T_4 * V_33 ,
char * V_20 , struct V_21 * V_22 )
{
T_4 * V_41 ;
int V_42 ;
T_6 * V_43 ;
T_4 * V_7 ;
V_7 = ( void * ) V_5 + V_5 -> V_10 ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = 0 ;
V_22 -> V_17 = 0 ;
V_43 = F_5 ( V_5 , V_33 , V_20 ) ;
if ( ! V_43 )
return;
V_42 = V_43 -> V_44 ;
if ( ! V_42 )
return;
V_41 = & V_7 [ V_42 ] ;
V_22 -> V_28 = V_43 -> V_45 ;
V_22 -> V_29 = V_43 -> V_46 ;
V_22 -> V_17 = V_22 -> V_29 - V_41 -> V_15
+ V_41 -> V_18 ;
V_22 -> V_20 = V_20 ;
V_22 -> V_32 = ( void * ) V_5 + V_22 -> V_17 ;
}
static T_4 * F_7 ( T_3 * V_5 )
{
T_4 * V_7 ;
unsigned int V_8 , V_9 ;
V_7 = ( void * ) V_5 + V_5 -> V_10 ;
if ( V_5 -> V_11 == V_12 )
V_9 = V_7 [ 0 ] . V_13 ;
else
V_9 = V_5 -> V_11 ;
for ( V_8 = 1 ; V_8 < V_9 ; V_8 ++ )
if ( V_7 [ V_8 ] . V_47 == V_48 )
return & V_7 [ V_8 ] ;
return NULL ;
}
static void * F_8 ( char * V_49 , int * V_28 )
{
struct V_50 V_51 ;
void * V_52 ;
int V_53 ;
V_53 = F_9 ( V_49 , V_54 ) ;
if ( V_53 < 0 ) {
perror ( V_49 ) ;
return NULL ;
}
if ( F_10 ( V_53 , & V_51 ) ) {
perror ( L_4 ) ;
F_11 ( V_53 ) ;
return NULL ;
}
* V_28 = V_51 . V_45 ;
V_52 = F_12 ( NULL , * V_28 , V_55 | V_56 , V_57 , V_53 , 0 ) ;
if ( V_52 == V_58 ) {
perror ( L_5 ) ;
F_11 ( V_53 ) ;
return NULL ;
}
F_11 ( V_53 ) ;
return V_52 ;
}
static char * F_13 ( char * V_49 , int * V_28 )
{
struct V_50 V_51 ;
char * V_59 ;
int V_53 ;
V_53 = F_9 ( V_49 , V_60 ) ;
if ( V_53 < 0 ) {
perror ( V_49 ) ;
return NULL ;
}
if ( F_10 ( V_53 , & V_51 ) ) {
perror ( L_4 ) ;
F_11 ( V_53 ) ;
return NULL ;
}
* V_28 = V_51 . V_45 ;
V_59 = malloc ( * V_28 ) ;
if ( ! V_59 ) {
perror ( L_6 ) ;
F_11 ( V_53 ) ;
return NULL ;
}
if ( F_14 ( V_53 , V_59 , * V_28 ) != * V_28 ) {
perror ( L_7 ) ;
F_11 ( V_53 ) ;
return NULL ;
}
F_11 ( V_53 ) ;
return V_59 ;
}
static void F_15 ( T_3 * V_5 , struct V_21 * V_22 )
{
F_16 ( L_8 , V_22 -> V_20 ) ;
F_16 ( L_9 , V_22 -> V_29 ) ;
F_16 ( L_10 , V_22 -> V_28 ) ;
F_16 ( L_11 , ( unsigned long ) V_22 -> V_17 ) ;
}
static void F_17 ( char * V_61 )
{
printf ( L_12 , V_61 ) ;
}
int main ( int V_62 , char * * V_63 )
{
char * V_64 = NULL ;
char * V_65 = NULL ;
char * V_66 = NULL ;
int V_67 ;
int V_68 ;
T_3 * V_5 ;
char * V_69 ;
T_5 * V_70 ;
unsigned long * V_71 ;
int * V_72 ;
int V_73 ;
T_4 * V_33 = NULL ;
struct V_21 V_74 , V_75 , V_76 ;
while ( ( V_73 = F_18 ( V_62 , V_63 , L_13 ) ) != - 1 ) {
switch ( V_73 ) {
case 's' :
V_64 = V_77 ;
break;
case 'b' :
V_65 = V_77 ;
break;
case 'c' :
V_66 = V_77 ;
break;
default:
break;
}
}
if ( ! V_65 || ! V_66 ) {
F_17 ( V_63 [ 0 ] ) ;
exit ( V_31 ) ;
}
V_69 = F_13 ( V_66 , & V_68 ) ;
if ( ! V_69 )
exit ( V_31 ) ;
V_5 = F_8 ( V_65 , & V_67 ) ;
if ( ! V_5 )
exit ( V_31 ) ;
if ( V_67 < sizeof( * V_5 ) ) {
F_4 ( L_14 ) ;
exit ( V_31 ) ;
}
if ( ( V_5 -> V_78 [ V_79 ] != V_80 ) ||
( V_5 -> V_78 [ V_81 ] != V_82 ) ||
( V_5 -> V_78 [ V_83 ] != V_84 ) ||
( V_5 -> V_78 [ V_85 ] != V_86 ) ) {
F_4 ( L_15 ) ;
exit ( V_31 ) ;
}
if ( V_5 -> V_78 [ V_87 ] != V_88 ) {
F_4 ( L_16 ) ;
exit ( V_31 ) ;
}
if ( V_5 -> V_78 [ V_89 ] != F_1 () ) {
F_4 ( L_17 ) ;
exit ( V_31 ) ;
}
if ( V_5 -> V_10 > V_67 ) {
F_4 ( L_18 ) ;
exit ( V_31 ) ;
}
V_33 = F_7 ( V_5 ) ;
if ( ! V_33 ) {
F_19 ( L_19 ) ;
if ( ! V_64 ) {
F_4 ( L_20 ) ;
F_17 ( V_63 [ 0 ] ) ;
exit ( V_31 ) ;
}
V_70 = fopen ( V_64 , L_21 ) ;
if ( ! V_70 ) {
perror ( V_64 ) ;
exit ( V_31 ) ;
}
F_3 ( V_5 , V_70 , V_90 , & V_74 ) ;
F_3 ( V_5 , V_70 , V_91 , & V_76 ) ;
F_3 ( V_5 , V_70 , V_92 , & V_75 ) ;
V_74 . V_28 = V_76 . V_29 - V_74 . V_29 ;
} else {
F_16 ( L_22 ) ;
if ( V_64 )
F_19 ( L_23 ) ;
F_6 ( V_5 , V_33 , V_90 , & V_74 ) ;
F_6 ( V_5 , V_33 , V_91 , & V_76 ) ;
F_6 ( V_5 , V_33 , V_92 , & V_75 ) ;
}
if ( ! V_74 . V_17 || ! V_75 . V_17 || ! V_76 . V_17 )
exit ( V_31 ) ;
F_15 ( V_5 , & V_74 ) ;
F_15 ( V_5 , & V_76 ) ;
F_15 ( V_5 , & V_75 ) ;
V_71 = ( unsigned long * ) V_75 . V_32 ;
V_72 = ( int * ) V_76 . V_32 ;
if ( V_74 . V_28 < V_68 ) {
F_4 ( L_24 ) ;
exit ( V_31 ) ;
}
if ( V_68 == * V_72 &&
strncmp ( V_74 . V_32 , V_69 , V_68 ) == 0 ) {
F_19 ( L_25 ) ;
exit ( V_93 ) ;
}
if ( * V_72 > 0 )
F_19 ( L_26 ) ;
memcpy ( V_74 . V_32 , V_69 , V_68 ) ;
if ( V_68 < V_74 . V_28 )
memset ( V_74 . V_32 + V_68 ,
0 , V_74 . V_28 - V_68 ) ;
* V_71 = * V_71 + V_68 - * V_72 ;
* V_72 = V_68 ;
F_16 ( L_27 , V_66 ,
V_74 . V_29 ) ;
F_16 ( L_28 , * V_72 ,
V_74 . V_28 ) ;
exit ( V_93 ) ;
}
