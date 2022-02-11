static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 , T_4 * V_5 )
{
if( ! V_5 ) {
return;
}
while( V_5 -> V_4 ) {
if( V_5 -> V_4 == V_4 ) {
V_5 -> V_6 ( V_1 , V_3 , V_2 ) ;
return;
}
V_5 ++ ;
}
return;
}
static T_5 *
F_2 ( T_6 * V_7 )
{
if ( ! V_7 -> V_8 ) {
V_7 -> V_8 = F_3 ( F_4 () , T_5 ) ;
}
return ( T_5 * ) ( V_7 -> V_8 ) ;
}
void
F_5 ( void )
{
static char * V_9 = NULL ;
if ( ! V_10 ) {
return;
}
if ( V_11 == NULL ) {
return;
}
if ( V_9 && ! strcmp ( V_9 , V_11 ) ) {
return;
}
if ( V_9 != NULL ) {
F_6 ( V_9 ) ;
V_9 = NULL ;
}
V_9 = F_7 ( V_11 ) ;
F_8 ( V_9 ) ;
}
void
F_5 ( void )
{
}
static void
F_9 ( T_1 * V_1 , int V_12 , int V_13 , const char * V_14 , const char * V_15 )
{
T_7 * V_16 ;
if( V_1 -> V_17 -> V_18 . V_19 ) {
return;
}
printf ( L_1 , V_1 -> V_17 -> V_20 , V_12 , V_13 ) ;
V_16 = ( T_7 * ) F_10 ( sizeof( T_7 ) ) ;
F_11 ( V_16 -> V_21 , V_22 , L_2 , V_15 , V_1 -> V_17 -> V_20 ) ;
V_16 -> V_23 = V_1 -> V_17 -> V_20 ;
V_16 -> V_24 = V_25 ;
V_25 = V_16 ;
V_16 -> V_12 = V_12 ;
V_16 -> V_13 = V_13 ;
V_16 -> V_14 = ( char * ) F_12 ( V_14 , V_13 ) ;
}
void
F_8 ( const char * T_8 V_26 )
{
}
void
F_8 ( const char * T_8 )
{
T_9 V_27 ;
T_10 V_28 ;
T_11 V_29 ;
T_12 V_30 ;
T_7 * V_16 ;
static T_13 V_31 = TRUE ;
if ( T_8 == NULL || T_8 [ 0 ] == 0 ) {
return;
}
if( V_31 ) {
V_31 = FALSE ;
V_28 = F_13 ( & V_32 ) ;
if( V_28 && V_28 != V_33 ) {
return;
}
}
V_28 = F_14 ( V_32 , T_8 , & V_27 ) ;
if( V_28 ) {
fprintf ( V_34 , L_3 , T_8 ) ;
return;
}
V_28 = F_15 ( V_32 , V_27 , & V_30 ) ;
if( V_28 ) {
fprintf ( V_34 , L_4 , T_8 ) ;
return;
}
do{
V_16 = ( T_7 * ) F_10 ( sizeof( T_7 ) ) ;
V_16 -> V_23 = - 1 ;
V_16 -> V_24 = V_25 ;
V_28 = F_16 ( V_32 , V_27 , & V_29 , & V_30 ) ;
if( V_28 == 0 ) {
int V_35 ;
char * V_36 ;
V_36 = V_16 -> V_21 ;
V_36 += F_17 ( V_22 ,
F_11 ( V_36 , V_22 , L_5 ) ) ;
for( V_35 = 0 ; V_35 < V_29 . V_37 -> V_38 ; V_35 ++ ) {
V_36 += F_17 ( V_22 - ( V_36 - V_16 -> V_21 ) ,
F_11 ( V_36 , V_22 - ( V_36 - V_16 -> V_21 ) , L_6 , ( V_35 ? L_7 : L_8 ) , ( V_29 . V_37 -> V_39 [ V_35 ] ) . V_39 ) ) ;
}
V_36 += F_17 ( V_22 - ( V_36 - V_16 -> V_21 ) ,
F_11 ( V_36 , V_22 - ( V_36 - V_16 -> V_21 ) , L_9 , V_29 . V_37 -> V_40 . V_39 ) ) ;
* V_36 = 0 ;
V_16 -> V_12 = V_29 . V_29 . V_41 ;
V_16 -> V_13 = V_29 . V_29 . V_38 ;
V_16 -> V_14 = ( char * ) F_12 ( V_29 . V_29 . V_42 , V_29 . V_29 . V_38 ) ;
V_25 = V_16 ;
}
}while( V_28 == 0 );
V_28 = F_18 ( V_32 , V_27 , & V_30 ) ;
if( V_28 ) {
F_19 ( V_32 , V_27 ) ;
}
}
T_14 *
F_20 ( T_2 * V_2 , T_1 * V_1 ,
int V_43 ,
T_3 * V_44 ,
int V_12 ,
int * V_45 )
{
T_10 V_28 ;
T_7 * V_46 ;
T_15 V_39 = { 0 , 0 , NULL } ;
T_11 V_29 ;
int V_38 = F_21 ( V_44 ) ;
const T_14 * V_47 = F_22 ( V_44 , 0 , V_38 ) ;
if( ! V_10 || V_38 < 1 ) {
return NULL ;
}
if ( F_21 ( V_44 ) < F_23 ( V_44 ) ) {
return NULL ;
}
F_5 () ;
V_39 . V_39 = ( char * ) F_10 ( V_38 ) ;
V_39 . V_38 = V_38 ;
for( V_46 = V_25 ; V_46 ; V_46 = V_46 -> V_24 ) {
T_16 V_48 ;
if( ( V_12 != - 1 ) && ( V_46 -> V_12 != V_12 ) ) {
continue;
}
V_48 . V_41 = V_46 -> V_12 ;
V_48 . V_49 . V_38 = V_38 ;
V_48 . V_49 . V_39 = ( T_14 * ) V_47 ;
V_29 . V_29 . V_41 = V_46 -> V_12 ;
V_29 . V_29 . V_38 = V_46 -> V_13 ;
V_29 . V_29 . V_42 = V_46 -> V_14 ;
V_28 = F_24 ( V_32 , & ( V_29 . V_29 ) , V_43 , 0 , & V_48 , & V_39 ) ;
if( V_28 == 0 ) {
char * V_50 ;
F_25 ( V_1 , NULL , & V_51 ,
L_10 ,
V_46 -> V_12 , V_1 -> V_17 -> V_20 , V_46 -> V_21 ) ;
F_26 ( V_2 , NULL , 0 , 0 , L_11 , V_46 -> V_21 ) ;
V_50 = V_39 . V_39 ;
if ( V_45 ) {
* V_45 = V_39 . V_38 ;
}
return V_50 ;
}
}
F_6 ( V_39 . V_39 ) ;
return NULL ;
}
void
F_8 ( const char * T_8 )
{
T_9 V_27 ;
T_10 V_28 ;
T_11 V_29 ;
T_12 V_30 ;
T_7 * V_16 ;
static T_13 V_31 = TRUE ;
if ( T_8 == NULL || T_8 [ 0 ] == 0 ) {
return;
}
if( V_31 ) {
V_31 = FALSE ;
V_28 = F_13 ( & V_32 ) ;
if( V_28 ) {
return;
}
}
V_28 = F_14 ( V_32 , T_8 , & V_27 ) ;
if( V_28 ) {
fprintf ( V_34 , L_12 , T_8 ) ;
return;
}
V_28 = F_15 ( V_32 , V_27 , & V_30 ) ;
if( V_28 ) {
fprintf ( V_34 , L_13 , T_8 ) ;
return;
}
do{
V_16 = F_10 ( sizeof( T_7 ) ) ;
V_16 -> V_23 = - 1 ;
V_16 -> V_24 = V_25 ;
V_28 = F_16 ( V_32 , V_27 , & V_29 , & V_30 ) ;
if( V_28 == 0 ) {
unsigned int V_35 ;
char * V_36 ;
V_36 = V_16 -> V_21 ;
V_36 += F_17 ( V_22 ,
F_11 ( V_36 , V_22 , L_5 ) ) ;
for( V_35 = 0 ; V_35 < V_29 . V_37 -> V_52 . V_53 . V_54 ; V_35 ++ ) {
V_36 += F_17 ( V_22 - ( V_36 - V_16 -> V_21 ) ,
F_11 ( V_36 , V_22 - ( V_36 - V_16 -> V_21 ) , L_6 , ( V_35 ? L_7 : L_8 ) , V_29 . V_37 -> V_52 . V_53 . V_55 [ V_35 ] ) ) ;
}
V_36 += F_17 ( V_22 - ( V_36 - V_16 -> V_21 ) ,
F_11 ( V_36 , V_22 - ( V_36 - V_16 -> V_21 ) , L_9 , V_29 . V_37 -> V_40 ) ) ;
* V_36 = 0 ;
V_16 -> V_12 = V_29 . V_56 . V_12 ;
V_16 -> V_13 = V_29 . V_56 . V_14 . V_38 ;
V_16 -> V_14 = F_12 ( V_29 . V_56 . V_14 . V_39 , V_29 . V_56 . V_14 . V_38 ) ;
V_25 = V_16 ;
}
}while( V_28 == 0 );
V_28 = F_18 ( V_32 , V_27 , & V_30 ) ;
if( V_28 ) {
F_19 ( V_32 , V_27 ) ;
}
}
T_14 *
F_20 ( T_2 * V_2 , T_1 * V_1 ,
int V_43 ,
T_3 * V_44 ,
int V_12 ,
int * V_45 )
{
T_10 V_28 ;
T_15 V_39 ;
T_7 * V_46 ;
int V_38 = F_21 ( V_44 ) ;
const T_14 * V_47 = F_22 ( V_44 , 0 , V_38 ) ;
if( ! V_10 ) {
return NULL ;
}
if ( F_21 ( V_44 ) < F_23 ( V_44 ) ) {
return NULL ;
}
F_5 () ;
for( V_46 = V_25 ; V_46 ; V_46 = V_46 -> V_24 ) {
T_11 V_29 ;
T_17 V_57 ;
T_14 * V_58 ;
if( ( V_12 != - 1 ) && ( V_46 -> V_12 != V_12 ) ) {
continue;
}
V_29 . V_56 . V_12 = V_46 -> V_12 ;
V_29 . V_56 . V_14 . V_38 = V_46 -> V_13 ;
V_29 . V_56 . V_14 . V_39 = V_46 -> V_14 ;
V_28 = F_27 ( V_32 , & ( V_29 . V_56 ) , 0 , & V_57 ) ;
if( V_28 ) {
return NULL ;
}
V_58 = F_12 ( V_47 , V_38 ) ;
V_28 = F_28 ( V_32 , V_57 , V_43 ,
V_58 , V_38 ,
& V_39 ,
NULL ) ;
F_6 ( V_58 ) ;
if( ( V_28 == 0 ) && ( V_38 > 0 ) ) {
char * V_50 ;
printf ( L_14 , V_46 -> V_12 , V_1 -> V_17 -> V_20 ) ;
F_26 ( V_2 , NULL , 0 , 0 , L_11 , V_46 -> V_21 ) ;
F_29 ( V_32 , V_57 ) ;
V_50 = F_12 ( V_39 . V_39 , V_39 . V_38 ) ;
if ( V_45 ) {
* V_45 = V_39 . V_38 ;
}
return V_50 ;
}
F_29 ( V_32 , V_57 ) ;
}
return NULL ;
}
static void
F_9 ( T_1 * V_1 , int V_12 , int V_13 , const char * V_14 , const char * V_15 )
{
T_18 * V_16 ;
if( V_1 -> V_17 -> V_18 . V_19 ) {
return;
}
printf ( L_15 , V_1 -> V_17 -> V_20 ) ;
V_16 = F_10 ( sizeof( T_18 ) ) ;
V_16 -> V_59 = 0 ;
V_16 -> V_12 = V_12 ;
V_16 -> V_38 = V_13 ;
V_16 -> V_42 = F_12 ( V_14 , V_13 ) ;
F_11 ( V_16 -> V_15 , V_22 , L_2 , V_15 , V_1 -> V_17 -> V_20 ) ;
V_60 = F_30 ( V_60 , ( V_61 ) V_16 ) ;
}
static void
F_31 ( void ) {
T_19 * V_62 ;
T_18 * V_63 ;
for( V_62 = V_60 ; V_62 != NULL ; V_62 = F_32 ( V_62 ) ) {
V_63 = ( T_18 * ) V_62 -> V_39 ;
if ( V_63 ) {
F_6 ( V_63 -> V_42 ) ;
F_6 ( V_63 ) ;
}
}
F_33 ( V_60 ) ;
V_60 = NULL ;
}
static void
F_8 ( const char * V_64 )
{
T_20 * V_65 ;
T_21 V_66 ;
T_18 * V_63 ;
unsigned char V_67 [ V_68 ] ;
int V_69 = 0 , V_70 = 0 ;
if ( V_64 != NULL && F_34 ( V_64 , & V_66 ) == 0 ) {
if ( V_66 . V_71 > V_68 ) {
if ( ( V_66 . V_71 % ( V_68 + 1 ) == 0 ) ||
( V_66 . V_71 % ( V_68 + 1 ) == V_68 ) ) {
V_69 = 1 ;
} else if ( ( V_66 . V_71 % ( V_68 + 2 ) == 0 ) ||
( V_66 . V_71 % ( V_68 + 2 ) == V_68 ) ) {
V_69 = 2 ;
}
}
V_65 = F_35 ( V_64 , L_16 ) ;
if ( ! V_65 ) return;
while ( fread ( V_67 , V_68 , 1 , V_65 ) == 1 ) {
V_63 = F_10 ( sizeof( T_18 ) ) ;
V_63 -> V_59 = V_67 [ 0 ] << 8 | V_67 [ 1 ] ;
V_63 -> V_12 = V_72 ;
V_63 -> V_38 = V_73 ;
V_63 -> V_42 = F_12 ( V_67 + 2 , V_73 ) ;
F_11 ( V_63 -> V_15 , V_22 , L_17 , V_70 , ftell ( V_65 ) ) ;
V_60 = F_30 ( V_60 , ( V_61 ) V_63 ) ;
fseek ( V_65 , V_69 , V_74 ) ;
V_70 ++ ;
F_36 ( L_18 , V_63 -> V_15 ) ;
}
fclose ( V_65 ) ;
}
}
T_14 *
F_20 ( T_2 * V_2 , T_1 * V_1 ,
int V_26 V_43 ,
T_3 * V_44 ,
int V_12 ,
int * V_45 )
{
T_3 * V_75 ;
T_14 * V_76 = NULL , * V_77 = NULL ;
T_14 V_78 ;
T_13 V_79 ;
T_22 V_4 , V_80 , V_81 ;
int V_82 , V_83 ;
T_14 V_29 [ V_73 ] ;
T_14 V_84 [ V_85 ] ;
T_23 V_86 ;
T_24 V_87 [ 16 ] ;
T_24 V_88 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_24 V_89 [ 8 ] ;
T_13 V_90 ;
T_19 * V_62 ;
T_18 * V_63 ;
struct V_91 V_92 ;
int V_38 = F_21 ( V_44 ) ;
const T_14 * V_47 = F_22 ( V_44 , 0 , V_38 ) ;
if( ! V_10 ) {
return NULL ;
}
if ( F_21 ( V_44 ) < F_23 ( V_44 ) ) {
return NULL ;
}
if ( V_12 != V_72 || V_60 == NULL ) {
return NULL ;
}
V_76 = F_10 ( V_38 ) ;
for( V_62 = V_60 ; V_62 != NULL ; V_62 = F_32 ( V_62 ) ) {
T_13 V_93 = FALSE ;
V_63 = ( T_18 * ) V_62 -> V_39 ;
F_37 ( V_73 , V_29 , V_63 -> V_42 ) ;
F_38 ( & V_86 ) ;
memset ( V_84 , 0 , V_85 ) ;
F_39 ( & V_92 , V_29 ) ;
F_40 ( & V_92 , V_94 , V_85 , V_84 ,
V_38 , V_76 , V_47 ) ;
V_75 = F_41 ( V_76 , V_38 , V_38 ) ;
F_42 ( V_75 , V_89 , 0 , 8 ) ;
F_43 {
V_82 = F_44 ( V_75 , V_95 , & V_78 , & V_79 , & V_4 ) ;
V_83 = F_45 ( V_75 , V_82 , & V_80 , & V_90 ) ;
}
F_46 {
F_47 ( V_75 ) ;
V_93 = TRUE ;
}
V_96 ;
if ( V_93 ) continue;
V_81 = V_80 + V_83 - V_95 ;
if ( ( int ) V_80 + V_83 > V_38 ) {
F_47 ( V_75 ) ;
continue;
}
F_48 ( & V_86 , V_89 , 8 ) ;
F_48 ( & V_86 , V_88 , 16 ) ;
F_48 ( & V_86 , V_76 + V_95 , V_81 ) ;
F_49 ( & V_86 , V_87 ) ;
if ( F_50 ( V_75 , 8 , V_87 , 16 ) == 0 ) {
F_36 ( L_14 , V_12 , V_1 -> V_17 -> V_20 ) ;
V_77 = F_10 ( V_81 ) ;
F_42 ( V_75 , V_77 , V_95 , V_81 ) ;
F_47 ( V_75 ) ;
if ( V_45 ) {
* V_45 = V_81 ;
}
F_6 ( V_76 ) ;
return ( V_77 ) ;
}
F_47 ( V_75 ) ;
}
F_6 ( V_76 ) ;
return NULL ;
}
static int
F_51 ( T_13 T_25 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_26 V_26 )
{
T_14 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_52 ( V_3 , V_83 ) ;
V_38 = F_53 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 2 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_54 ( V_3 , V_77 , V_38 , V_38 ) ;
F_55 ( V_99 , F_6 ) ;
F_56 ( V_7 -> V_1 , V_99 , L_19 ) ;
V_83 = F_57 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_58 ( T_13 T_25 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_26 V_26 )
{
T_14 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_52 ( V_3 , V_83 ) ;
V_38 = F_53 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 7 , V_97 , V_8 -> V_98 , NULL ) ;
if( ! V_77 ) {
V_77 = F_20 ( V_2 , V_7 -> V_1 , 11 , V_97 , V_8 -> V_98 , NULL ) ;
}
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_54 ( V_3 , V_77 , V_38 , V_38 ) ;
F_55 ( V_99 , F_6 ) ;
F_56 ( V_7 -> V_1 , V_99 , L_19 ) ;
V_83 = F_57 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_59 ( T_13 T_25 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_26 V_26 )
{
T_14 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_52 ( V_3 , V_83 ) ;
V_38 = F_53 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 3 , V_97 , V_8 -> V_98 , NULL ) ;
if( ! V_77 ) {
V_77 = F_20 ( V_2 , V_7 -> V_1 , 8 , V_97 , V_8 -> V_98 , NULL ) ;
}
if( ! V_77 ) {
V_77 = F_20 ( V_2 , V_7 -> V_1 , 9 , V_97 , V_8 -> V_98 , NULL ) ;
}
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_54 ( V_3 , V_77 , V_38 , V_38 ) ;
F_55 ( V_99 , F_6 ) ;
F_56 ( V_7 -> V_1 , V_99 , L_19 ) ;
V_83 = F_57 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_60 ( T_13 T_25 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_26 V_26 )
{
T_14 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_52 ( V_3 , V_83 ) ;
V_38 = F_53 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 1 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_54 ( V_3 , V_77 , V_38 , V_38 ) ;
F_55 ( V_99 , F_6 ) ;
F_56 ( V_7 -> V_1 , V_99 , L_19 ) ;
V_83 = F_57 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_61 ( T_13 T_25 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_26 V_26 )
{
T_14 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_52 ( V_3 , V_83 ) ;
V_38 = F_53 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 12 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_54 ( V_3 , V_77 , V_38 , V_38 ) ;
F_55 ( V_99 , F_6 ) ;
F_56 ( V_7 -> V_1 , V_99 , L_19 ) ;
V_83 = F_57 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_62 ( T_13 T_25 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_26 V_26 )
{
T_14 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_52 ( V_3 , V_83 ) ;
V_38 = F_53 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 13 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_54 ( V_3 , V_77 , V_38 , V_38 ) ;
F_55 ( V_99 , F_6 ) ;
F_56 ( V_7 -> V_1 , V_99 , L_19 ) ;
V_83 = F_57 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_63 ( T_13 T_25 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_26 V_26 )
{
T_14 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_52 ( V_3 , V_83 ) ;
V_38 = F_53 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 14 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_54 ( V_3 , V_77 , V_38 , V_38 ) ;
F_55 ( V_99 , F_6 ) ;
F_56 ( V_7 -> V_1 , V_99 , L_19 ) ;
V_83 = F_57 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_64 ( T_6 * V_7 V_26 , T_2 * V_2 , T_3 * V_3 )
{
int V_83 = 0 ;
T_22 V_54 ;
T_27 V_100 ;
V_54 = F_65 ( V_3 , V_83 ) ;
F_66 ( V_2 , V_101 , V_3 , V_83 , 4 , V_102 ) ;
V_83 += 4 ;
F_66 ( V_2 , V_103 , V_3 , V_83 , V_54 , V_104 ) ;
V_83 += V_54 ;
F_66 ( V_2 , V_105 , V_3 , V_83 , 4 , V_102 ) ;
F_66 ( V_2 , V_106 , V_3 , V_83 , 4 , V_102 ) ;
F_66 ( V_2 , V_107 , V_3 , V_83 , 4 , V_102 ) ;
F_66 ( V_2 , V_108 , V_3 , V_83 , 4 , V_102 ) ;
F_66 ( V_2 , V_109 , V_3 , V_83 , 4 , V_102 ) ;
F_66 ( V_2 , V_110 , V_3 , V_83 , 4 , V_102 ) ;
F_66 ( V_2 , V_111 , V_3 , V_83 , 4 , V_102 ) ;
V_83 += 4 ;
if( F_53 ( V_3 , V_83 ) < 2 ) {
return V_83 ;
}
F_66 ( V_2 , V_112 , V_3 , V_83 , 2 , V_102 ) ;
V_83 += 2 ;
if( F_53 ( V_3 , V_83 ) < 2 ) {
return V_83 ;
}
V_100 = F_67 ( V_3 , V_83 ) ;
F_66 ( V_2 , V_113 , V_3 , V_83 , 2 , V_102 ) ;
V_83 += 2 ;
if( V_100 != F_53 ( V_3 , V_83 ) ) {
F_26 ( V_2 , V_3 , 0 , 0 , L_20 , V_100 , F_53 ( V_3 , V_83 ) ) ;
return V_83 ;
}
V_83 = F_57 ( FALSE , V_3 , V_83 , V_7 , V_2 , - 1 ) ;
return V_83 ;
}
static int
F_68 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 )
{
V_83 = F_69 ( V_7 , V_2 , V_3 , V_83 , V_114 , NULL , 0 ) ;
return V_83 ;
}
static int
F_70 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 )
{
T_22 V_115 ;
F_66 ( V_2 , V_116 , V_3 , V_83 , 4 ,
V_102 ) ;
V_115 = F_65 ( V_3 , V_83 ) ;
if( V_115 ) {
F_71 ( V_7 -> V_1 -> V_117 , V_118 ,
L_21 ,
F_72 ( V_115 , V_119 ,
L_22 ) ) ;
}
V_83 += 4 ;
F_66 ( V_2 , V_120 , V_3 , V_83 , 4 ,
V_102 ) ;
V_83 += 4 ;
F_66 ( V_2 , V_120 , V_3 , V_83 , 4 ,
V_102 ) ;
V_83 += 4 ;
return V_83 ;
}
static int
F_73 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_75 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_76 ( T_28 , V_121 ,
V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_77 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_75 ( T_28 , V_3 , V_83 , V_7 , V_2 , T_26 ) ;
return V_83 ;
}
static int
F_78 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_79 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_122 , T_26 , V_123 ) ;
return V_83 ;
}
static int
F_81 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_124 , T_26 , V_125 ) ;
return V_83 ;
}
static int
F_83 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 223 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
& ( V_8 -> V_98 ) ) ;
return V_83 ;
}
static int
F_84 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_85 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 227 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_86
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , F_51 ) ;
#else
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_89 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_126 , T_26 , V_127 ) ;
return V_83 ;
}
static int
F_90 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_128 , T_26 , V_129 ) ;
return V_83 ;
}
static int
F_91 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 1 , FALSE , F_90 ) ;
return V_83 ;
}
static int
F_93 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 284 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
& ( V_8 -> V_131 ) ) ;
return V_83 ;
}
static int
F_94 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 288 "../../asn1/kerberos/kerberos.cnf"
T_3 * V_97 ;
T_5 * V_8 = F_2 ( V_7 ) ;
switch( V_8 -> V_131 ) {
case V_132 :
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , & V_97 ) ;
F_64 ( V_7 , V_2 , V_97 ) ;
break;
default:
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , NULL ) ;
}
return V_83 ;
return V_83 ;
}
static int
F_95 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_133 , T_26 , V_134 ) ;
return V_83 ;
}
static int
F_96 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_97 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_98 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ) ;
return V_83 ;
}
static int
F_99 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_100 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 302 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
& V_135 ) ;
V_8 -> V_29 . V_12 = V_135 ;
return V_83 ;
}
static int
F_101 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 309 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_8 -> V_29 . V_13 = F_53 ( V_3 , V_83 ) ;
V_8 -> V_29 . V_14 = F_22 ( V_3 , V_83 , V_8 -> V_29 . V_13 ) ;
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_102 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 317 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_136 , T_26 , V_137 ) ;
if ( V_8 -> V_29 . V_12 != 0 ) {
#ifdef F_86
F_9 ( V_7 -> V_1 , V_8 -> V_29 . V_12 , V_8 -> V_29 . V_13 , V_8 -> V_29 . V_14 , L_23 ) ;
#endif
}
return V_83 ;
}
static int
F_103 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 328 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
& ( V_8 -> V_138 ) ) ;
return V_83 ;
}
static int
F_104 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 333 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
switch( V_8 -> V_138 ) {
case V_139 :
V_83 = F_87 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 , V_140 ) ;
break;
default:
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 , NULL ) ;
}
return V_83 ;
}
static int
F_105 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_141 , T_26 , V_142 ) ;
return V_83 ;
}
static int
F_106 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_143 , T_26 , V_144 ) ;
return V_83 ;
}
static int
F_107 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_145 , T_26 , V_146 ) ;
return V_83 ;
}
static int
F_108 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 2 , FALSE , F_107 ) ;
return V_83 ;
}
static int
F_109 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_110 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_147 , T_26 , V_148 ,
NULL ) ;
return V_83 ;
}
static int
F_111 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_112 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_149 , T_26 , V_150 ) ;
return V_83 ;
}
static int
F_113 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 344 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
& ( V_8 -> V_151 ) ) ;
return V_83 ;
}
static int
F_114 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 172 "../../asn1/kerberos/kerberos.cnf"
T_29 V_152 ;
T_13 V_79 ;
T_30 V_4 ;
T_22 V_54 ;
const char * V_153 ;
T_31 * V_154 = NULL ;
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_115 ( V_7 -> V_1 , V_2 , V_3 , V_83 , & V_152 , & V_79 , & V_4 ) ;
V_83 = F_116 ( V_7 -> V_1 , V_2 , V_3 , V_83 , & V_54 , NULL ) ;
switch( V_8 -> V_151 ) {
case V_155 :
V_154 = F_66 ( V_2 , V_156 , V_3 , V_83 , 4 , V_157 ) ;
V_153 = F_117 ( V_3 , V_83 ) ;
break;
case V_158 :
{
char V_159 [ ( V_160 - 1 ) * 4 + 1 ] ;
int V_161 ;
int V_162 = ( V_160 - 1 ) * 4 + 1 ;
V_161 = F_118 ( F_22 ( V_3 , V_83 , 16 ) , V_159 , V_162 ) ;
V_153 = F_119 ( F_4 () , L_24 , V_159 , V_161 ) ;
V_154 = F_120 ( V_2 , V_163 , V_3 , V_83 , 16 , V_159 , L_25 , V_153 , F_121 ( V_161 ) ) ;
}
break;
case V_164 :
V_154 = F_66 ( V_2 , V_165 , V_3 , V_83 , V_166 , V_104 ) ;
V_153 = F_122 ( V_3 , V_83 ) ;
break;
default:
F_26 ( V_2 , V_3 , V_83 , V_54 , L_26 ) ;
V_153 = NULL ;
}
if( V_154 && V_153 ) {
F_123 ( F_124 ( V_154 ) , L_27 , V_153 ) ;
F_123 ( F_125 ( V_154 , 2 ) , L_27 , V_153 ) ;
}
V_83 += V_54 ;
return V_83 ;
return V_83 ;
}
static int
F_126 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_167 , T_26 , V_168 ) ;
return V_83 ;
}
static int
F_127 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_169 , T_26 , V_170 ) ;
return V_83 ;
}
static int
F_128 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_171 , T_26 , V_172 ) ;
return V_83 ;
}
static int
F_129 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 3 , FALSE , F_128 ) ;
return V_83 ;
}
static int
F_130 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 66 "../../asn1/kerberos/kerberos.cnf"
T_22 V_173 ;
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
& V_173 ) ;
#line 71 "../../asn1/kerberos/kerberos.cnf"
if ( V_174 ) {
F_131 ( V_7 -> V_1 -> V_117 , V_118 ,
F_72 ( V_173 , V_175 ,
L_28 ) ) ;
}
V_174 = FALSE ;
#if 0
proto_item_append_text(tree, " %s", val_to_str(msgtype, krb5_msg_types, "Unknown:0x%x"));
#endif
return V_83 ;
}
static int
F_132 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 119 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
& ( V_8 -> V_176 ) ) ;
#line 122 "../../asn1/kerberos/kerberos.cnf"
if( V_2 ) {
F_123 ( V_2 , L_27 ,
F_72 ( V_8 -> V_176 , V_177 ,
L_29 ) ) ;
}
return V_83 ;
}
static int
F_133 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 129 "../../asn1/kerberos/kerberos.cnf"
T_2 * V_178 = V_2 ;
T_5 * V_8 = F_2 ( V_7 ) ;
if( V_7 -> V_179 ) {
V_178 = F_134 ( V_7 -> V_179 , V_180 ) ;
}
switch( V_8 -> V_176 ) {
case V_181 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , F_57 ) ;
break;
case V_182 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , V_183 ) ;
break;
case V_184 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , V_185 ) ;
break;
case V_186 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , V_187 ) ;
break;
case V_188 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , V_189 ) ;
break;
case V_190 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , F_68 ) ;
break;
case V_191 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , V_192 ) ;
break;
case V_193 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , V_194 ) ;
break;
case V_195 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , V_196 ) ;
break;
case V_197 :
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , F_70 ) ;
break;
default:
V_83 = F_87 ( FALSE , V_7 , V_178 , V_3 , V_83 , T_26 , NULL ) ;
}
return V_83 ;
}
static int
F_135 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_198 , T_26 , V_180 ) ;
return V_83 ;
}
static int
F_136 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_199 , T_26 , V_200 ) ;
return V_83 ;
}
static int
F_137 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_110 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_201 , T_26 , V_202 ,
NULL ) ;
return V_83 ;
}
static int
F_138 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_203 , T_26 , V_204 ) ;
return V_83 ;
}
static int
F_139 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 235 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_86
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , F_58 ) ;
#else
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_140 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_205 , T_26 , V_206 ) ;
return V_83 ;
}
static int
F_141 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_207 , T_26 , V_208 ) ;
return V_83 ;
}
static int
F_142 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 348 "../../asn1/kerberos/kerberos.cnf"
T_32 * V_209 ;
if ( V_7 -> V_1 -> V_210 == V_211 && V_7 -> V_1 -> V_212 == V_213 ) {
V_209 = F_143 ( V_7 -> V_1 -> V_17 -> V_20 , & V_7 -> V_1 -> V_214 , & V_7 -> V_1 -> V_215 , V_213 ,
V_7 -> V_1 -> V_216 , 0 , V_217 ) ;
if ( V_209 == NULL ) {
V_209 = F_144 ( V_7 -> V_1 -> V_17 -> V_20 , & V_7 -> V_1 -> V_214 , & V_7 -> V_1 -> V_215 , V_213 ,
V_7 -> V_1 -> V_216 , 0 , V_218 ) ;
F_145 ( V_209 , V_219 ) ;
}
}
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_220 , T_26 , V_221 ) ;
return V_83 ;
}
static int
F_146 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_222 , T_26 , V_223 ) ;
return V_83 ;
}
static int
F_147 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 10 , FALSE , F_146 ) ;
return V_83 ;
}
static int
F_148 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 243 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_86
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , F_59 ) ;
#else
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_149 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_224 , T_26 , V_225 ) ;
return V_83 ;
}
static int
F_150 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_226 , T_26 , V_227 ) ;
return V_83 ;
}
static int
F_151 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 11 , FALSE , F_150 ) ;
return V_83 ;
}
static int
F_152 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 12 , FALSE , F_146 ) ;
return V_83 ;
}
static int
F_153 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 13 , FALSE , F_150 ) ;
return V_83 ;
}
static int
F_154 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_110 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_228 , T_26 , V_229 ,
NULL ) ;
return V_83 ;
}
static int
F_155 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_230 , T_26 , V_231 ) ;
return V_83 ;
}
static int
F_156 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 14 , FALSE , F_155 ) ;
return V_83 ;
}
static int
F_157 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 259 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_86
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , F_61 ) ;
#else
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_158 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_232 , T_26 , V_233 ) ;
return V_83 ;
}
static int
F_159 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_234 , T_26 , V_235 ) ;
return V_83 ;
}
static int
F_160 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 15 , FALSE , F_159 ) ;
return V_83 ;
}
static int
F_161 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 371 "../../asn1/kerberos/kerberos.cnf"
T_3 * V_236 ;
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , & V_236 ) ;
if ( V_236 ) {
F_1 ( V_7 -> V_1 , V_2 , V_236 , V_237 , ( T_4 * ) V_7 -> V_8 ) ;
}
return V_83 ;
}
static int
F_162 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_238 , T_26 , V_239 ) ;
return V_83 ;
}
static int
F_163 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_240 , T_26 , V_241 ) ;
return V_83 ;
}
static int
F_164 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 20 , FALSE , F_163 ) ;
return V_83 ;
}
static int
F_165 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 267 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_86
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , F_62 ) ;
#else
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_166 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_242 , T_26 , V_243 ) ;
return V_83 ;
}
static int
F_167 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_244 , T_26 , V_245 ) ;
return V_83 ;
}
static int
F_168 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 21 , FALSE , F_167 ) ;
return V_83 ;
}
static int
F_169 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 275 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_86
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , F_63 ) ;
#else
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_170 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_246 , T_26 , V_247 ) ;
return V_83 ;
}
static int
F_171 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_248 , T_26 , V_249 ) ;
return V_83 ;
}
static int
F_172 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 22 , FALSE , F_171 ) ;
return V_83 ;
}
static int
F_173 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
F_174 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_250 , T_26 , V_251 ) ;
return V_83 ;
}
static int
F_175 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_252 , T_26 , V_253 ) ;
return V_83 ;
}
static int
F_176 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_254 , T_26 , V_255 ) ;
return V_83 ;
}
static int
F_177 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_256 , T_26 , V_257 ) ;
return V_83 ;
}
static int
F_178 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 25 , FALSE , F_177 ) ;
return V_83 ;
}
static int
F_179 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 26 , FALSE , F_177 ) ;
return V_83 ;
}
static int
F_180 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_258 , T_26 , V_259 ) ;
return V_83 ;
}
static int
F_181 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 27 , FALSE , F_180 ) ;
return V_83 ;
}
static int
F_182 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 378 "../../asn1/kerberos/kerberos.cnf"
T_3 * V_236 ;
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , & V_236 ) ;
if ( V_236 ) {
F_1 ( V_7 -> V_1 , V_2 , V_236 , V_260 , ( T_4 * ) V_7 -> V_8 ) ;
}
return V_83 ;
}
static int
F_183 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_261 , T_26 , V_262 ) ;
return V_83 ;
}
static int
F_184 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 28 , FALSE , F_183 ) ;
return V_83 ;
}
static int
F_185 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_263 , T_26 , V_264 ) ;
return V_83 ;
}
static int
F_186 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_265 , T_26 , V_266 ) ;
return V_83 ;
}
static int
F_187 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_267 , T_26 , V_268 ) ;
return V_83 ;
}
static int
F_188 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 29 , FALSE , F_187 ) ;
return V_83 ;
}
static int
F_189 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 84 "../../asn1/kerberos/kerberos.cnf"
V_83 = F_74 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
& V_269 ) ;
#line 87 "../../asn1/kerberos/kerberos.cnf"
if( V_269 ) {
F_190 ( V_7 -> V_1 -> V_117 , V_118 ,
L_30 ,
F_72 ( V_269 , V_270 ,
L_22 ) ) ;
}
return V_83 ;
return V_83 ;
}
static int
F_191 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 97 "../../asn1/kerberos/kerberos.cnf"
switch( V_269 ) {
case V_271 :
case V_272 :
case V_273 :
case V_274 :
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , V_275 , F_135 ) ;
break;
case V_276 :
case V_277 :
case V_278 :
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , V_275 , F_136 ) ;
break;
default:
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , V_275 , NULL ) ;
}
return V_83 ;
}
static int
F_192 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_279 , T_26 , V_280 ) ;
return V_83 ;
}
static int
F_193 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_92 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
T_26 , V_130 , 30 , FALSE , F_192 ) ;
return V_83 ;
}
static int
F_57 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_194 ( V_7 , V_2 , V_3 , V_83 ,
V_281 , T_26 , V_282 ,
NULL ) ;
return V_83 ;
}
static int
F_195 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
#line 251 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_86
V_83 = F_87 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_26 , F_60 ) ;
#else
V_83 = F_88 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
V_192 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_283 , T_26 , V_284 ) ;
return V_83 ;
}
static int
F_196 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_285 , T_26 , V_286 ) ;
return V_83 ;
}
static int
V_194 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_287 , T_26 , V_288 ) ;
return V_83 ;
}
static int
F_197 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_289 , T_26 , V_290 ) ;
return V_83 ;
}
static int
V_196 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_80 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_291 , T_26 , V_292 ) ;
return V_83 ;
}
static int
V_140 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_106 ( T_28 , V_3 , V_83 , V_7 , V_2 , T_26 ) ;
return V_83 ;
}
static int
F_198 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_76 ( T_28 , V_121 ,
V_7 , V_2 , V_3 , V_83 , T_26 ,
NULL ) ;
return V_83 ;
}
static int
V_189 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_293 , T_26 , V_294 ) ;
return V_83 ;
}
static int
F_199 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_200 ( T_28 , V_7 , V_2 , V_3 , V_83 , T_26 , NULL ) ;
return V_83 ;
}
static int
V_187 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_295 , T_26 , V_296 ) ;
return V_83 ;
}
int
F_201 ( T_13 T_28 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_26 V_26 ) {
V_83 = F_82 ( T_28 , V_7 , V_2 , V_3 , V_83 ,
V_297 , T_26 , V_298 ) ;
return V_83 ;
}
int
F_202 ( T_2 * V_2 , T_3 * V_3 , int V_83 , T_6 * V_7 V_26 )
{
return F_95 ( FALSE , V_3 , V_83 , V_7 , V_2 , V_299 ) ;
}
int
F_203 ( T_2 * V_2 , T_3 * V_3 , int V_83 , T_6 * V_7 V_26 )
{
return F_97 ( FALSE , V_3 , V_83 , V_7 , V_2 , V_300 ) ;
}
int
F_204 ( T_2 * V_2 , T_3 * V_3 , int V_83 , T_6 * V_7 V_26 )
{
return F_81 ( FALSE , V_3 , V_83 , V_7 , V_2 , V_301 ) ;
}
int
F_205 ( T_2 * V_2 , T_3 * V_3 , int V_83 , T_6 * V_7 V_26 )
{
return F_77 ( FALSE , V_3 , V_83 , V_7 , V_2 , V_302 ) ;
}
static T_33
F_206 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 ,
T_13 V_303 , T_13 V_304 , T_13 V_305 ,
T_4 * V_5 )
{
volatile int V_83 = 0 ;
T_2 * volatile V_306 = NULL ;
T_31 * volatile V_307 = NULL ;
T_6 V_308 ;
T_22 V_309 = 0 ;
T_33 V_310 = 0 ;
V_174 = V_303 ;
if ( V_305 ) {
V_309 = F_207 ( V_3 , V_83 ) ;
V_310 = F_208 ( V_309 ) ;
if ( V_310 > 10 * 1024 * 1024 ) {
return ( - 1 ) ;
}
if ( V_304 ) {
F_209 ( V_1 -> V_117 , V_311 , L_31 ) ;
}
if ( V_2 ) {
V_307 = F_66 ( V_2 , V_312 , V_3 , 0 , - 1 , V_104 ) ;
V_306 = F_134 ( V_307 , V_313 ) ;
}
F_210 ( V_306 , V_3 , V_83 , V_309 ) ;
V_83 += 4 ;
} else {
T_29 V_314 ;
T_13 V_315 ;
T_30 V_316 ;
F_44 ( V_3 , V_83 , & V_314 , & V_315 , & V_316 ) ;
if( V_314 != V_130 ) {
return 0 ;
}
switch( V_316 ) {
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
break;
default:
return 0 ;
}
if ( V_304 ) {
F_209 ( V_1 -> V_117 , V_311 , L_31 ) ;
}
if ( V_174 ) {
F_211 ( V_1 -> V_117 , V_118 ) ;
}
if ( V_2 ) {
V_307 = F_66 ( V_2 , V_312 , V_3 , 0 , - 1 , V_104 ) ;
V_306 = F_134 ( V_307 , V_313 ) ;
}
}
F_212 ( & V_308 , V_334 , TRUE , V_1 ) ;
V_308 . V_8 = V_5 ;
F_43 {
V_83 = F_57 ( FALSE , V_3 , V_83 , & V_308 , V_306 , - 1 ) ;
} F_46 {
V_335 ;
} V_96 ;
F_213 ( V_307 , V_83 ) ;
return V_83 ;
}
void
F_210 ( T_2 * V_2 , T_3 * V_3 , T_33 V_336 , T_22 V_309 )
{
T_33 V_337 ;
T_31 * V_338 ;
T_2 * V_339 ;
if ( V_2 == NULL )
return;
V_337 = F_208 ( V_309 ) ;
V_338 = F_26 ( V_2 , V_3 , V_336 , 4 ,
L_32 , V_337 , F_214 ( V_337 , L_33 , L_34 ) ) ;
V_339 = F_134 ( V_338 , V_340 ) ;
F_215 ( V_339 , V_341 , V_3 , V_336 , 4 , V_309 ) ;
F_216 ( V_339 , V_342 , V_3 , V_336 , 4 , V_309 ) ;
}
T_33
F_217 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , int V_343 , T_4 * V_5 )
{
return ( F_206 ( V_3 , V_1 , V_2 , V_343 , FALSE , FALSE , V_5 ) ) ;
}
T_22
F_218 ( void )
{
return V_135 ;
}
static T_33
F_219 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , void * V_39 V_26 )
{
if( F_21 ( V_3 ) >= 1 && F_220 ( V_3 , 0 ) <= 0x10 ) {
if( V_344 ) {
T_13 V_345 ;
V_345 = F_221 ( V_344 , V_3 , V_1 , V_2 , NULL ) ;
return V_345 ;
} else{
return 0 ;
}
}
return F_206 ( V_3 , V_1 , V_2 , TRUE , TRUE , FALSE , NULL ) ;
}
T_33
F_208 ( T_34 V_309 )
{
return ( V_309 & V_346 ) ;
}
T_34
F_222 ( T_1 * V_1 V_26 , T_3 * V_3 , int V_83 )
{
T_34 V_309 ;
T_33 V_347 ;
V_309 = F_207 ( V_3 , V_83 ) ;
V_347 = F_208 ( V_309 ) ;
return ( V_347 + 4 ) ;
}
static void
F_223 ( void ) {
#ifdef F_224
F_31 () ;
F_8 ( V_11 ) ;
#endif
}
static int
F_225 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , void * V_39 V_26 )
{
V_1 -> V_348 = TRUE ;
if ( F_206 ( V_3 , V_1 , V_2 , TRUE , TRUE , TRUE , NULL ) < 0 ) {
F_209 ( V_1 -> V_117 , V_118 , L_35 ) ;
}
return F_21 ( V_3 ) ;
}
static int
F_226 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , void * V_39 )
{
F_209 ( V_1 -> V_117 , V_311 , L_31 ) ;
F_211 ( V_1 -> V_117 , V_118 ) ;
F_227 ( V_3 , V_1 , V_2 , V_349 , 4 , F_222 ,
F_225 , V_39 ) ;
return F_21 ( V_3 ) ;
}
void F_228 ( void ) {
static T_35 V_350 [] = {
{ & V_341 , {
L_36 , L_37 , V_351 , 32 ,
& V_352 , V_353 , L_38 , V_354 } } ,
{ & V_342 , {
L_39 , L_40 , V_355 , V_356 ,
NULL , V_346 , NULL , V_354 } } ,
{ & V_114 , {
L_41 , L_42 , V_357 , V_358 ,
NULL , 0 , L_43 , V_354 } } ,
{ & V_116 ,
{ L_44 , L_45 , V_355 , V_359 ,
F_229 ( V_119 ) , 0 , L_46 , V_354 } } ,
{ & V_120 ,
{ L_47 , L_48 , V_355 , V_359 ,
NULL , 0 , NULL , V_354 } } ,
{ & V_156 , {
L_49 , L_50 , V_360 , V_358 ,
NULL , 0 , NULL , V_354 } } ,
{ & V_165 , {
L_51 , L_52 , V_361 , V_358 ,
NULL , 0 , NULL , V_354 } } ,
{ & V_163 , {
L_53 , L_54 , V_357 , V_358 ,
NULL , 0 , L_55 , V_354 } } ,
{ & V_101 , {
L_56 , L_57 , V_355 , V_356 ,
NULL , 0 , L_58 , V_354 } } ,
{ & V_103 , {
L_59 , L_60 , V_362 , V_358 ,
NULL , 0 , L_61 , V_354 } } ,
{ & V_111 , {
L_62 , L_63 , V_351 , 32 ,
F_230 ( & V_363 ) , V_364 , NULL , V_354 } } ,
{ & V_110 , {
L_64 , L_65 , V_351 , 32 ,
F_230 ( & V_365 ) , V_366 , NULL , V_354 } } ,
{ & V_109 , {
L_66 , L_67 , V_351 , 32 ,
F_230 ( & V_367 ) , V_368 , NULL , V_354 } } ,
{ & V_108 , {
L_68 , L_69 , V_351 , 32 ,
F_230 ( & V_369 ) , V_370 , NULL , V_354 } } ,
{ & V_107 , {
L_70 , L_71 , V_351 , 32 ,
F_230 ( & V_371 ) , V_372 , NULL , V_354 } } ,
{ & V_106 , {
L_72 , L_73 , V_351 , 32 ,
F_230 ( & V_373 ) , V_374 , NULL , V_354 } } ,
{ & V_105 , {
L_74 , L_75 , V_351 , 32 ,
F_230 ( & V_375 ) , V_376 , NULL , V_354 } } ,
{ & V_112 , {
L_76 , L_77 , V_377 , V_356 ,
NULL , 0 , L_78 , V_354 } } ,
{ & V_113 , {
L_79 , L_80 , V_377 , V_356 ,
NULL , 0 , L_81 , V_354 } } ,
#line 1 "../../asn1/kerberos/packet-kerberos-hfarr.c"
{ & V_378 ,
{ L_82 , L_83 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_380 ,
{ L_84 , L_85 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_381 ,
{ L_86 , L_87 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_382 ,
{ L_88 , L_89 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_383 ,
{ L_90 , L_91 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_384 ,
{ L_92 , L_93 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_385 ,
{ L_94 , L_95 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_386 ,
{ L_96 , L_97 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_387 ,
{ L_98 , L_99 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_388 ,
{ L_100 , L_101 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_389 ,
{ L_102 , L_103 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_390 ,
{ L_104 , L_105 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_391 ,
{ L_106 , L_107 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_392 ,
{ L_108 , L_109 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_393 ,
{ L_110 , L_111 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_394 ,
{ L_112 , L_113 ,
V_379 , V_358 , NULL , 0 ,
L_114 , V_354 } } ,
{ & V_395 ,
{ L_115 , L_116 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_396 ,
{ L_117 , L_118 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_397 ,
{ L_119 , L_120 ,
V_398 , V_356 , F_229 ( V_399 ) , 0 ,
NULL , V_354 } } ,
{ & V_400 ,
{ L_121 , L_122 ,
V_355 , V_356 , NULL , 0 ,
L_123 , V_354 } } ,
{ & V_401 ,
{ L_124 , L_125 ,
V_357 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_402 ,
{ L_126 , L_127 ,
V_398 , V_356 , F_229 ( V_403 ) , 0 ,
NULL , V_354 } } ,
{ & V_404 ,
{ L_128 , L_129 ,
V_362 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_405 ,
{ L_130 , L_131 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_406 ,
{ L_132 , L_133 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_407 ,
{ L_134 , L_135 ,
V_398 , V_356 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_408 ,
{ L_136 , L_137 ,
V_362 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_409 ,
{ L_138 , L_139 ,
V_398 , V_356 , F_229 ( V_410 ) , 0 ,
NULL , V_354 } } ,
{ & V_411 ,
{ L_140 , L_141 ,
V_362 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_412 ,
{ L_142 , L_143 ,
V_398 , V_356 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_413 ,
{ L_144 , L_145 ,
V_362 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_414 ,
{ L_146 , L_147 ,
V_398 , V_356 , F_229 ( V_415 ) , 0 ,
NULL , V_354 } } ,
{ & V_416 ,
{ L_148 , L_149 ,
V_362 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_417 ,
{ L_150 , L_151 ,
V_398 , V_356 , F_229 ( V_418 ) , 0 ,
L_152 , V_354 } } ,
{ & V_419 ,
{ L_153 , L_154 ,
V_355 , V_356 , NULL , 0 ,
L_155 , V_354 } } ,
{ & V_420 ,
{ L_156 , L_157 ,
V_362 , V_358 , NULL , 0 ,
L_158 , V_354 } } ,
{ & V_421 ,
{ L_156 , L_157 ,
V_362 , V_358 , NULL , 0 ,
L_159 , V_354 } } ,
{ & V_422 ,
{ L_156 , L_157 ,
V_362 , V_358 , NULL , 0 ,
L_160 , V_354 } } ,
{ & V_423 ,
{ L_156 , L_157 ,
V_362 , V_358 , NULL , 0 ,
L_161 , V_354 } } ,
{ & V_424 ,
{ L_156 , L_157 ,
V_362 , V_358 , NULL , 0 ,
L_162 , V_354 } } ,
{ & V_425 ,
{ L_156 , L_157 ,
V_362 , V_358 , NULL , 0 ,
L_163 , V_354 } } ,
{ & V_426 ,
{ L_164 , L_165 ,
V_355 , V_356 , NULL , 0 ,
L_166 , V_354 } } ,
{ & V_302 ,
{ L_167 , L_168 ,
V_357 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_427 ,
{ L_169 , L_170 ,
V_379 , V_358 , NULL , 0 ,
L_171 , V_354 } } ,
{ & V_428 ,
{ L_172 , L_173 ,
V_379 , V_358 , NULL , 0 ,
L_174 , V_354 } } ,
{ & V_429 ,
{ L_175 , L_176 ,
V_362 , V_358 , NULL , 0 ,
L_177 , V_354 } } ,
{ & V_430 ,
{ L_23 , L_178 ,
V_379 , V_358 , NULL , 0 ,
L_179 , V_354 } } ,
{ & V_431 ,
{ L_180 , L_181 ,
V_357 , V_358 , NULL , 0 ,
L_182 , V_354 } } ,
{ & V_301 ,
{ L_183 , L_184 ,
V_379 , V_358 , NULL , 0 ,
L_171 , V_354 } } ,
{ & V_432 ,
{ L_185 , L_186 ,
V_379 , V_358 , NULL , 0 ,
L_187 , V_354 } } ,
{ & V_433 ,
{ L_188 , L_189 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_434 ,
{ L_191 , L_192 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_435 ,
{ L_193 , L_194 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_436 ,
{ L_195 , L_196 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_437 ,
{ L_197 , L_198 ,
V_355 , V_356 , NULL , 0 ,
L_199 , V_354 } } ,
{ & V_438 ,
{ L_200 , L_201 ,
V_355 , V_356 , NULL , 0 ,
L_202 , V_354 } } ,
{ & V_439 ,
{ L_203 , L_204 ,
V_398 , V_356 , NULL , 0 ,
L_205 , V_354 } } ,
{ & V_440 ,
{ L_206 , L_207 ,
V_362 , V_358 , NULL , 0 ,
L_208 , V_354 } } ,
{ & V_441 ,
{ L_209 , L_210 ,
V_355 , V_356 , NULL , 0 ,
L_166 , V_354 } } ,
{ & V_442 ,
{ L_211 , L_212 ,
V_398 , V_356 , F_229 ( V_443 ) , 0 ,
L_213 , V_354 } } ,
{ & V_444 ,
{ L_214 , L_215 ,
V_355 , V_356 , NULL , 0 ,
L_216 , V_354 } } ,
{ & V_445 ,
{ L_217 , L_218 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_446 ,
{ L_219 , L_220 ,
V_379 , V_358 , NULL , 0 ,
L_221 , V_354 } } ,
{ & V_447 ,
{ L_222 , L_223 ,
V_362 , V_358 , NULL , 0 ,
L_224 , V_354 } } ,
{ & V_448 ,
{ L_225 , L_226 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_449 ,
{ L_227 , L_228 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_450 ,
{ L_229 , L_230 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_451 ,
{ L_231 , L_232 ,
V_355 , V_356 , NULL , 0 ,
L_155 , V_354 } } ,
{ & V_452 ,
{ L_150 , L_151 ,
V_355 , V_356 , NULL , 0 ,
L_233 , V_354 } } ,
{ & V_453 ,
{ L_152 , L_234 ,
V_398 , V_356 , F_229 ( V_418 ) , 0 ,
NULL , V_354 } } ,
{ & V_454 ,
{ L_235 , L_236 ,
V_355 , V_356 , NULL , 0 ,
L_199 , V_354 } } ,
{ & V_455 ,
{ L_237 , L_238 ,
V_379 , V_358 , NULL , 0 ,
L_239 , V_354 } } ,
{ & V_456 ,
{ L_240 , L_241 ,
V_355 , V_356 , NULL , 0 ,
L_242 , V_354 } } ,
{ & V_457 ,
{ L_243 , L_244 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_458 ,
{ L_172 , L_173 ,
V_379 , V_358 , NULL , 0 ,
L_245 , V_354 } } ,
{ & V_459 ,
{ L_246 , L_247 ,
V_355 , V_356 , NULL , 0 ,
L_248 , V_354 } } ,
{ & V_460 ,
{ L_249 , L_250 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_461 ,
{ L_251 , L_252 ,
V_357 , V_358 , NULL , 0 ,
L_182 , V_354 } } ,
{ & V_462 ,
{ L_253 , L_254 ,
V_355 , V_356 , NULL , 0 ,
L_255 , V_354 } } ,
{ & V_463 ,
{ L_256 , L_257 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_464 ,
{ L_258 , L_259 ,
V_398 , V_356 , F_229 ( V_465 ) , 0 ,
NULL , V_354 } } ,
{ & V_466 ,
{ L_260 , L_261 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_467 ,
{ L_262 , L_263 ,
V_362 , V_358 , NULL , 0 ,
L_264 , V_354 } } ,
{ & V_468 ,
{ L_84 , L_85 ,
V_379 , V_358 , NULL , 0 ,
L_239 , V_354 } } ,
{ & V_469 ,
{ L_265 , L_266 ,
V_355 , V_356 , NULL , 0 ,
L_166 , V_354 } } ,
{ & V_299 ,
{ L_267 , L_268 ,
V_379 , V_358 , NULL , 0 ,
L_269 , V_354 } } ,
{ & V_470 ,
{ L_270 , L_271 ,
V_355 , V_356 , NULL , 0 ,
L_272 , V_354 } } ,
{ & V_300 ,
{ L_273 , L_274 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_471 ,
{ L_275 , L_276 ,
V_379 , V_358 , NULL , 0 ,
L_179 , V_354 } } ,
{ & V_472 ,
{ L_277 , L_278 ,
V_355 , V_356 , NULL , 0 ,
L_155 , V_354 } } ,
{ & V_473 ,
{ L_172 , L_173 ,
V_379 , V_358 , NULL , 0 ,
L_279 , V_354 } } ,
{ & V_474 ,
{ L_280 , L_281 ,
V_379 , V_358 , NULL , 0 ,
L_282 , V_354 } } ,
{ & V_475 ,
{ L_283 , L_284 ,
V_362 , V_358 , NULL , 0 ,
L_285 , V_354 } } ,
{ & V_476 ,
{ L_286 , L_287 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_477 ,
{ L_288 , L_289 ,
V_355 , V_356 , NULL , 0 ,
L_272 , V_354 } } ,
{ & V_478 ,
{ L_290 , L_291 ,
V_379 , V_358 , NULL , 0 ,
L_130 , V_354 } } ,
{ & V_479 ,
{ L_292 , L_293 ,
V_379 , V_358 , NULL , 0 ,
L_130 , V_354 } } ,
{ & V_480 ,
{ L_172 , L_173 ,
V_379 , V_358 , NULL , 0 ,
L_294 , V_354 } } ,
{ & V_481 ,
{ L_283 , L_284 ,
V_362 , V_358 , NULL , 0 ,
L_295 , V_354 } } ,
{ & V_482 ,
{ L_296 , L_297 ,
V_355 , V_356 , NULL , 0 ,
L_242 , V_354 } } ,
{ & V_483 ,
{ L_243 , L_244 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_484 ,
{ L_172 , L_173 ,
V_379 , V_358 , NULL , 0 ,
L_298 , V_354 } } ,
{ & V_485 ,
{ L_299 , L_300 ,
V_355 , V_356 , NULL , 0 ,
L_301 , V_354 } } ,
{ & V_486 ,
{ L_302 , L_303 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_487 ,
{ L_304 , L_305 ,
V_357 , V_358 , NULL , 0 ,
L_182 , V_354 } } ,
{ & V_488 ,
{ L_306 , L_307 ,
V_379 , V_358 , NULL , 0 ,
L_171 , V_354 } } ,
{ & V_489 ,
{ L_308 , L_309 ,
V_357 , V_358 , NULL , 0 ,
L_190 , V_354 } } ,
{ & V_490 ,
{ L_310 , L_311 ,
V_355 , V_356 , NULL , 0 ,
L_272 , V_354 } } ,
{ & V_491 ,
{ L_312 , L_313 ,
V_398 , V_356 , F_229 ( V_492 ) , 0 ,
NULL , V_354 } } ,
{ & V_493 ,
{ L_314 , L_315 ,
V_357 , V_358 , NULL , 0 ,
L_124 , V_354 } } ,
{ & V_275 ,
{ L_316 , L_317 ,
V_362 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_494 ,
{ L_318 , L_319 ,
V_379 , V_358 , NULL , 0 ,
L_269 , V_354 } } ,
{ & V_495 ,
{ L_217 , L_218 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_496 ,
{ L_156 , L_157 ,
V_362 , V_358 , NULL , 0 ,
L_320 , V_354 } } ,
{ & V_497 ,
{ L_321 , L_322 ,
V_362 , V_358 , NULL , 0 ,
L_208 , V_354 } } ,
{ & V_498 ,
{ L_323 , L_324 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_499 ,
{ L_321 , L_322 ,
V_357 , V_358 , NULL , 0 ,
L_124 , V_354 } } ,
{ & V_500 ,
{ L_325 , L_326 ,
V_362 , V_358 , NULL , 0 ,
L_208 , V_354 } } ,
{ & V_501 ,
{ L_327 , L_328 ,
V_379 , V_358 , NULL , 0 ,
NULL , V_354 } } ,
{ & V_502 ,
{ L_329 , L_330 ,
V_379 , V_358 , NULL , 0 ,
L_171 , V_354 } } ,
{ & V_503 ,
{ L_331 , L_332 ,
V_357 , V_358 , NULL , 0 ,
L_333 , V_354 } } ,
{ & V_504 ,
{ L_334 , L_335 ,
V_351 , V_358 , NULL , 0 ,
L_336 , V_354 } } ,
{ & V_505 ,
{ L_337 , L_338 ,
V_362 , V_358 , NULL , 0 ,
L_208 , V_354 } } ,
{ & V_506 ,
{ L_339 , L_340 ,
V_379 , V_358 , NULL , 0 ,
L_171 , V_354 } } ,
{ & V_507 ,
{ L_341 , L_342 ,
V_357 , V_358 , NULL , 0 ,
L_182 , V_354 } } ,
{ & V_508 ,
{ L_343 , L_344 ,
V_351 , 8 , NULL , 0x80 ,
NULL , V_354 } } ,
{ & V_509 ,
{ L_345 , L_346 ,
V_351 , 8 , NULL , 0x40 ,
NULL , V_354 } } ,
{ & V_510 ,
{ L_347 , L_348 ,
V_351 , 8 , NULL , 0x20 ,
NULL , V_354 } } ,
{ & V_511 ,
{ L_343 , L_344 ,
V_351 , 8 , NULL , 0x80 ,
NULL , V_354 } } ,
{ & V_512 ,
{ L_349 , L_350 ,
V_351 , 8 , NULL , 0x40 ,
NULL , V_354 } } ,
{ & V_513 ,
{ L_351 , L_352 ,
V_351 , 8 , NULL , 0x20 ,
NULL , V_354 } } ,
{ & V_514 ,
{ L_353 , L_354 ,
V_351 , 8 , NULL , 0x10 ,
NULL , V_354 } } ,
{ & V_515 ,
{ L_355 , L_356 ,
V_351 , 8 , NULL , 0x08 ,
NULL , V_354 } } ,
{ & V_516 ,
{ L_357 , L_358 ,
V_351 , 8 , NULL , 0x04 ,
NULL , V_354 } } ,
{ & V_517 ,
{ L_359 , L_360 ,
V_351 , 8 , NULL , 0x02 ,
NULL , V_354 } } ,
{ & V_518 ,
{ L_361 , L_362 ,
V_351 , 8 , NULL , 0x01 ,
NULL , V_354 } } ,
{ & V_519 ,
{ L_363 , L_364 ,
V_351 , 8 , NULL , 0x80 ,
NULL , V_354 } } ,
{ & V_520 ,
{ L_365 , L_366 ,
V_351 , 8 , NULL , 0x40 ,
NULL , V_354 } } ,
{ & V_521 ,
{ L_367 , L_368 ,
V_351 , 8 , NULL , 0x20 ,
NULL , V_354 } } ,
{ & V_522 ,
{ L_369 , L_370 ,
V_351 , 8 , NULL , 0x10 ,
NULL , V_354 } } ,
{ & V_523 ,
{ L_371 , L_372 ,
V_351 , 8 , NULL , 0x08 ,
NULL , V_354 } } ,
{ & V_524 ,
{ L_373 , L_374 ,
V_351 , 8 , NULL , 0x04 ,
NULL , V_354 } } ,
{ & V_525 ,
{ L_375 , L_376 ,
V_351 , 8 , NULL , 0x02 ,
NULL , V_354 } } ,
{ & V_526 ,
{ L_343 , L_344 ,
V_351 , 8 , NULL , 0x80 ,
NULL , V_354 } } ,
{ & V_527 ,
{ L_349 , L_350 ,
V_351 , 8 , NULL , 0x40 ,
NULL , V_354 } } ,
{ & V_528 ,
{ L_351 , L_352 ,
V_351 , 8 , NULL , 0x20 ,
NULL , V_354 } } ,
{ & V_529 ,
{ L_353 , L_354 ,
V_351 , 8 , NULL , 0x10 ,
NULL , V_354 } } ,
{ & V_530 ,
{ L_355 , L_356 ,
V_351 , 8 , NULL , 0x08 ,
NULL , V_354 } } ,
{ & V_531 ,
{ L_377 , L_378 ,
V_351 , 8 , NULL , 0x04 ,
NULL , V_354 } } ,
{ & V_532 ,
{ L_359 , L_360 ,
V_351 , 8 , NULL , 0x02 ,
NULL , V_354 } } ,
{ & V_533 ,
{ L_379 , L_380 ,
V_351 , 8 , NULL , 0x01 ,
NULL , V_354 } } ,
{ & V_534 ,
{ L_363 , L_364 ,
V_351 , 8 , NULL , 0x80 ,
NULL , V_354 } } ,
{ & V_535 ,
{ L_381 , L_382 ,
V_351 , 8 , NULL , 0x40 ,
NULL , V_354 } } ,
{ & V_536 ,
{ L_383 , L_384 ,
V_351 , 8 , NULL , 0x20 ,
NULL , V_354 } } ,
{ & V_537 ,
{ L_385 , L_386 ,
V_351 , 8 , NULL , 0x10 ,
NULL , V_354 } } ,
{ & V_538 ,
{ L_387 , L_388 ,
V_351 , 8 , NULL , 0x02 ,
NULL , V_354 } } ,
{ & V_539 ,
{ L_389 , L_390 ,
V_351 , 8 , NULL , 0x01 ,
NULL , V_354 } } ,
{ & V_540 ,
{ L_391 , L_392 ,
V_351 , 8 , NULL , 0x80 ,
NULL , V_354 } } ,
{ & V_541 ,
{ L_393 , L_394 ,
V_351 , 8 , NULL , 0x20 ,
NULL , V_354 } } ,
{ & V_542 ,
{ L_395 , L_396 ,
V_351 , 8 , NULL , 0x10 ,
NULL , V_354 } } ,
{ & V_543 ,
{ L_397 , L_398 ,
V_351 , 8 , NULL , 0x08 ,
NULL , V_354 } } ,
{ & V_544 ,
{ L_399 , L_400 ,
V_351 , 8 , NULL , 0x02 ,
NULL , V_354 } } ,
{ & V_545 ,
{ L_401 , L_402 ,
V_351 , 8 , NULL , 0x01 ,
NULL , V_354 } } ,
#line 1962 "../../asn1/kerberos/packet-kerberos-template.c"
} ;
static T_33 * V_546 [] = {
& V_313 ,
& V_340 ,
#line 1 "../../asn1/kerberos/packet-kerberos-ettarr.c"
& V_282 ,
& V_125 ,
& V_123 ,
& V_168 ,
& V_170 ,
& V_144 ,
& V_142 ,
& V_180 ,
& V_137 ,
& V_134 ,
& V_127 ,
& V_206 ,
& V_225 ,
& V_233 ,
& V_243 ,
& V_247 ,
& V_129 ,
& V_172 ,
& V_150 ,
& V_223 ,
& V_200 ,
& V_221 ,
& V_204 ,
& V_208 ,
& V_227 ,
& V_257 ,
& V_253 ,
& V_251 ,
& V_231 ,
& V_146 ,
& V_235 ,
& V_259 ,
& V_241 ,
& V_239 ,
& V_245 ,
& V_262 ,
& V_249 ,
& V_268 ,
& V_266 ,
& V_264 ,
& V_280 ,
& V_255 ,
& V_284 ,
& V_286 ,
& V_288 ,
& V_290 ,
& V_292 ,
& V_229 ,
& V_148 ,
& V_202 ,
& V_294 ,
& V_296 ,
& V_298 ,
#line 1969 "../../asn1/kerberos/packet-kerberos-template.c"
} ;
static T_36 V_547 [] = {
{ & V_51 , { L_403 , V_548 , V_549 , L_404 , V_550 } } ,
} ;
T_37 * V_551 ;
T_38 * V_552 ;
V_312 = F_231 ( L_405 , L_31 , L_406 ) ;
F_232 ( V_312 , V_350 , F_233 ( V_350 ) ) ;
F_234 ( V_546 , F_233 ( V_546 ) ) ;
V_551 = F_235 ( V_312 ) ;
F_236 ( V_551 , V_547 , F_233 ( V_547 ) ) ;
V_552 = F_237 ( V_312 , F_223 ) ;
F_238 ( V_552 , L_407 ,
L_408 ,
L_409
L_410 ,
& V_349 ) ;
#ifdef F_86
F_238 ( V_552 , L_411 ,
L_412 ,
L_413
L_414
L_415 , & V_10 ) ;
F_239 ( V_552 , L_416 ,
L_417 ,
L_418 ,
& V_11 ) ;
#endif
}
static int F_240 ( T_3 * V_3 , int V_83 , T_1 * V_1 ,
T_2 * V_2 , T_39 * T_40 V_26 , T_14 * T_41 V_26 )
{
T_3 * V_553 ;
V_553 = F_52 ( V_3 , V_83 ) ;
F_217 ( V_553 , V_1 , V_2 , FALSE , NULL ) ;
return F_53 ( V_3 , V_83 ) ;
}
void
F_241 ( void )
{
T_42 V_554 ;
V_344 = F_242 ( L_419 ) ;
V_219 = F_243 ( F_219 ,
V_312 ) ;
V_554 = F_243 ( F_226 ,
V_312 ) ;
F_244 ( L_420 , V_211 , V_219 ) ;
F_244 ( L_421 , V_555 , V_554 ) ;
F_245 ( V_556 ,
V_557 ,
& V_558 ) ;
F_245 ( V_559 ,
V_557 ,
& V_560 ) ;
F_245 ( V_561 ,
V_557 ,
& V_562 ) ;
}
