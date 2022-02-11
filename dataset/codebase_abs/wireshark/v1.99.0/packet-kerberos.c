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
T_9
void
F_8 ( const char * T_8 )
{
T_10 V_27 ;
T_11 V_28 ;
T_12 V_29 ;
T_13 V_30 ;
T_7 * V_16 ;
static T_14 V_31 = TRUE ;
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
T_15 *
F_20 ( T_2 * V_2 V_26 , T_1 * V_1 ,
int V_43 ,
T_3 * V_44 ,
int V_12 ,
int * V_45 )
{
T_11 V_28 ;
T_7 * V_46 ;
T_16 V_39 = { 0 , 0 , NULL } ;
T_12 V_29 ;
int V_38 = F_21 ( V_44 ) ;
const T_15 * V_47 = F_22 ( V_44 , 0 , V_38 ) ;
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
T_17 V_48 ;
if( ( V_12 != - 1 ) && ( V_46 -> V_12 != V_12 ) ) {
continue;
}
V_48 . V_41 = V_46 -> V_12 ;
V_48 . V_49 . V_38 = V_38 ;
V_48 . V_49 . V_39 = ( T_15 * ) V_47 ;
V_29 . V_29 . V_41 = V_46 -> V_12 ;
V_29 . V_29 . V_38 = V_46 -> V_13 ;
V_29 . V_29 . V_42 = V_46 -> V_14 ;
V_28 = F_24 ( V_32 , & ( V_29 . V_29 ) , V_43 , 0 , & V_48 , & V_39 ) ;
if( V_28 == 0 ) {
char * V_50 ;
F_25 ( V_1 , NULL , & V_51 ,
L_10 ,
V_46 -> V_12 , V_1 -> V_17 -> V_20 , V_46 -> V_21 ) ;
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
T_9
void
F_8 ( const char * T_8 )
{
T_10 V_27 ;
T_11 V_28 ;
T_12 V_29 ;
T_13 V_30 ;
T_7 * V_16 ;
static T_14 V_31 = TRUE ;
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
fprintf ( V_34 , L_11 , T_8 ) ;
return;
}
V_28 = F_15 ( V_32 , V_27 , & V_30 ) ;
if( V_28 ) {
fprintf ( V_34 , L_12 , T_8 ) ;
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
T_18
T_15 *
F_20 ( T_2 * V_2 , T_1 * V_1 ,
int V_43 ,
T_3 * V_44 ,
int V_12 ,
int * V_45 )
{
T_11 V_28 ;
T_16 V_39 ;
T_7 * V_46 ;
int V_38 = F_21 ( V_44 ) ;
const T_15 * V_47 = F_22 ( V_44 , 0 , V_38 ) ;
if( ! V_10 ) {
return NULL ;
}
if ( F_21 ( V_44 ) < F_23 ( V_44 ) ) {
return NULL ;
}
F_5 () ;
for( V_46 = V_25 ; V_46 ; V_46 = V_46 -> V_24 ) {
T_12 V_29 ;
T_19 V_57 ;
T_15 * V_58 ;
if( ( V_12 != - 1 ) && ( V_46 -> V_12 != V_12 ) ) {
continue;
}
V_29 . V_56 . V_12 = V_46 -> V_12 ;
V_29 . V_56 . V_14 . V_38 = V_46 -> V_13 ;
V_29 . V_56 . V_14 . V_39 = V_46 -> V_14 ;
V_28 = F_26 ( V_32 , & ( V_29 . V_56 ) , 0 , & V_57 ) ;
if( V_28 ) {
return NULL ;
}
V_58 = F_12 ( V_47 , V_38 ) ;
V_28 = F_27 ( V_32 , V_57 , V_43 ,
V_58 , V_38 ,
& V_39 ,
NULL ) ;
F_6 ( V_58 ) ;
if( ( V_28 == 0 ) && ( V_38 > 0 ) ) {
char * V_50 ;
F_25 ( V_1 , NULL , & V_51 ,
L_10 ,
V_46 -> V_12 , V_1 -> V_17 -> V_20 , V_46 -> V_21 ) ;
F_28 ( V_32 , V_57 ) ;
V_50 = F_12 ( V_39 . V_39 , V_39 . V_38 ) ;
if ( V_45 ) {
* V_45 = V_39 . V_38 ;
}
return V_50 ;
}
F_28 ( V_32 , V_57 ) ;
}
return NULL ;
}
static void
F_9 ( T_1 * V_1 , int V_12 , int V_13 , const char * V_14 , const char * V_15 )
{
T_20 * V_16 ;
if( V_1 -> V_17 -> V_18 . V_19 ) {
return;
}
printf ( L_13 , V_1 -> V_17 -> V_20 ) ;
V_16 = F_10 ( sizeof( T_20 ) ) ;
V_16 -> V_59 = 0 ;
V_16 -> V_12 = V_12 ;
V_16 -> V_38 = V_13 ;
V_16 -> V_42 = F_12 ( V_14 , V_13 ) ;
F_11 ( V_16 -> V_15 , V_22 , L_2 , V_15 , V_1 -> V_17 -> V_20 ) ;
V_60 = F_29 ( V_60 , ( V_61 ) V_16 ) ;
}
static void
F_30 ( void ) {
T_21 * V_62 ;
T_20 * V_63 ;
for( V_62 = V_60 ; V_62 != NULL ; V_62 = F_31 ( V_62 ) ) {
V_63 = ( T_20 * ) V_62 -> V_39 ;
if ( V_63 ) {
F_6 ( V_63 -> V_42 ) ;
F_6 ( V_63 ) ;
}
}
F_32 ( V_60 ) ;
V_60 = NULL ;
}
static void
F_8 ( const char * V_64 )
{
T_22 * V_65 ;
T_23 V_66 ;
T_20 * V_63 ;
unsigned char V_67 [ V_68 ] ;
int V_69 = 0 , V_70 = 0 ;
if ( V_64 != NULL && F_33 ( V_64 , & V_66 ) == 0 ) {
if ( V_66 . V_71 > V_68 ) {
if ( ( V_66 . V_71 % ( V_68 + 1 ) == 0 ) ||
( V_66 . V_71 % ( V_68 + 1 ) == V_68 ) ) {
V_69 = 1 ;
} else if ( ( V_66 . V_71 % ( V_68 + 2 ) == 0 ) ||
( V_66 . V_71 % ( V_68 + 2 ) == V_68 ) ) {
V_69 = 2 ;
}
}
V_65 = F_34 ( V_64 , L_14 ) ;
if ( ! V_65 ) return;
while ( fread ( V_67 , V_68 , 1 , V_65 ) == 1 ) {
V_63 = F_10 ( sizeof( T_20 ) ) ;
V_63 -> V_59 = V_67 [ 0 ] << 8 | V_67 [ 1 ] ;
V_63 -> V_12 = V_72 ;
V_63 -> V_38 = V_73 ;
V_63 -> V_42 = F_12 ( V_67 + 2 , V_73 ) ;
F_11 ( V_63 -> V_15 , V_22 , L_15 , V_70 , ftell ( V_65 ) ) ;
V_60 = F_29 ( V_60 , ( V_61 ) V_63 ) ;
fseek ( V_65 , V_69 , V_74 ) ;
V_70 ++ ;
F_35 ( L_16 , V_63 -> V_15 ) ;
}
fclose ( V_65 ) ;
}
}
T_15 *
F_20 ( T_2 * V_2 , T_1 * V_1 ,
int V_26 V_43 ,
T_3 * V_44 ,
int V_12 ,
int * V_45 )
{
T_3 * V_75 ;
T_15 * V_76 = NULL , * V_77 = NULL ;
T_15 V_78 ;
T_14 V_79 ;
T_24 V_4 , V_80 , V_81 ;
int V_82 , V_83 ;
T_15 V_29 [ V_73 ] ;
T_15 V_84 [ V_85 ] ;
T_25 V_86 ;
T_26 V_87 [ 16 ] ;
T_26 V_88 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_26 V_89 [ 8 ] ;
T_14 V_90 ;
T_21 * V_62 ;
T_20 * V_63 ;
struct V_91 V_92 ;
int V_38 = F_21 ( V_44 ) ;
const T_15 * V_47 = F_22 ( V_44 , 0 , V_38 ) ;
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
for( V_62 = V_60 ; V_62 != NULL ; V_62 = F_31 ( V_62 ) ) {
T_14 V_93 = FALSE ;
V_63 = ( T_20 * ) V_62 -> V_39 ;
F_36 ( V_73 , V_29 , V_63 -> V_42 ) ;
F_37 ( & V_86 ) ;
memset ( V_84 , 0 , V_85 ) ;
F_38 ( & V_92 , V_29 ) ;
F_39 ( & V_92 , V_94 , V_85 , V_84 ,
V_38 , V_76 , V_47 ) ;
V_75 = F_40 ( V_76 , V_38 , V_38 ) ;
F_41 ( V_75 , V_89 , 0 , 8 ) ;
F_42 {
V_82 = F_43 ( V_75 , V_95 , & V_78 , & V_79 , & V_4 ) ;
V_83 = F_44 ( V_75 , V_82 , & V_80 , & V_90 ) ;
}
F_45 {
F_46 ( V_75 ) ;
V_93 = TRUE ;
}
V_96 ;
if ( V_93 ) continue;
V_81 = V_80 + V_83 - V_95 ;
if ( ( int ) V_80 + V_83 > V_38 ) {
F_46 ( V_75 ) ;
continue;
}
F_47 ( & V_86 , V_89 , 8 ) ;
F_47 ( & V_86 , V_88 , 16 ) ;
F_47 ( & V_86 , V_76 + V_95 , V_81 ) ;
F_48 ( & V_86 , V_87 ) ;
if ( F_49 ( V_75 , 8 , V_87 , 16 ) == 0 ) {
F_35 ( L_17 , V_12 , V_1 -> V_17 -> V_20 ) ;
V_77 = F_10 ( V_81 ) ;
F_41 ( V_75 , V_77 , V_95 , V_81 ) ;
F_46 ( V_75 ) ;
if ( V_45 ) {
* V_45 = V_81 ;
}
F_6 ( V_76 ) ;
return ( V_77 ) ;
}
F_46 ( V_75 ) ;
}
F_6 ( V_76 ) ;
return NULL ;
}
static int
F_50 ( T_14 T_27 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_28 V_26 )
{
T_15 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_51 ( V_3 , V_83 ) ;
V_38 = F_52 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 2 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_53 ( V_3 , V_77 , V_38 , V_38 ) ;
F_54 ( V_99 , F_6 ) ;
F_55 ( V_7 -> V_1 , V_99 , L_18 ) ;
V_83 = F_56 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_57 ( T_14 T_27 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_28 V_26 )
{
T_15 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_51 ( V_3 , V_83 ) ;
V_38 = F_52 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 7 , V_97 , V_8 -> V_98 , NULL ) ;
if( ! V_77 ) {
V_77 = F_20 ( V_2 , V_7 -> V_1 , 11 , V_97 , V_8 -> V_98 , NULL ) ;
}
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_53 ( V_3 , V_77 , V_38 , V_38 ) ;
F_54 ( V_99 , F_6 ) ;
F_55 ( V_7 -> V_1 , V_99 , L_18 ) ;
V_83 = F_56 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_58 ( T_14 T_27 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_28 V_26 )
{
T_15 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_51 ( V_3 , V_83 ) ;
V_38 = F_52 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 3 , V_97 , V_8 -> V_98 , NULL ) ;
if( ! V_77 ) {
V_77 = F_20 ( V_2 , V_7 -> V_1 , 8 , V_97 , V_8 -> V_98 , NULL ) ;
}
if( ! V_77 ) {
V_77 = F_20 ( V_2 , V_7 -> V_1 , 9 , V_97 , V_8 -> V_98 , NULL ) ;
}
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_53 ( V_3 , V_77 , V_38 , V_38 ) ;
F_54 ( V_99 , F_6 ) ;
F_55 ( V_7 -> V_1 , V_99 , L_18 ) ;
V_83 = F_56 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_59 ( T_14 T_27 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_28 V_26 )
{
T_15 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_51 ( V_3 , V_83 ) ;
V_38 = F_52 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 1 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_53 ( V_3 , V_77 , V_38 , V_38 ) ;
F_54 ( V_99 , F_6 ) ;
F_55 ( V_7 -> V_1 , V_99 , L_18 ) ;
V_83 = F_56 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_60 ( T_14 T_27 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_28 V_26 )
{
T_15 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_51 ( V_3 , V_83 ) ;
V_38 = F_52 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 12 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_53 ( V_3 , V_77 , V_38 , V_38 ) ;
F_54 ( V_99 , F_6 ) ;
F_55 ( V_7 -> V_1 , V_99 , L_18 ) ;
V_83 = F_56 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_61 ( T_14 T_27 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_28 V_26 )
{
T_15 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_51 ( V_3 , V_83 ) ;
V_38 = F_52 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 13 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_53 ( V_3 , V_77 , V_38 , V_38 ) ;
F_54 ( V_99 , F_6 ) ;
F_55 ( V_7 -> V_1 , V_99 , L_18 ) ;
V_83 = F_56 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_62 ( T_14 T_27 V_26 , T_3 * V_3 , int V_83 , T_6 * V_7 ,
T_2 * V_2 , int T_28 V_26 )
{
T_15 * V_77 ;
int V_38 ;
T_5 * V_8 = F_2 ( V_7 ) ;
T_3 * V_97 ;
V_97 = F_51 ( V_3 , V_83 ) ;
V_38 = F_52 ( V_3 , V_83 ) ;
V_77 = F_20 ( V_2 , V_7 -> V_1 , 14 , V_97 , V_8 -> V_98 , NULL ) ;
if( V_77 ) {
T_3 * V_99 ;
V_99 = F_53 ( V_3 , V_77 , V_38 , V_38 ) ;
F_54 ( V_99 , F_6 ) ;
F_55 ( V_7 -> V_1 , V_99 , L_18 ) ;
V_83 = F_56 ( FALSE , V_99 , 0 , V_7 , V_2 , - 1 ) ;
}
return V_83 ;
}
static int
F_63 ( T_6 * V_7 V_26 , T_2 * V_2 , T_3 * V_3 )
{
int V_83 = 0 ;
T_24 V_54 ;
T_29 V_100 ;
V_54 = F_64 ( V_3 , V_83 ) ;
F_65 ( V_2 , V_101 , V_3 , V_83 , 4 , V_102 ) ;
V_83 += 4 ;
F_65 ( V_2 , V_103 , V_3 , V_83 , V_54 , V_104 ) ;
V_83 += V_54 ;
F_65 ( V_2 , V_105 , V_3 , V_83 , 4 , V_102 ) ;
F_65 ( V_2 , V_106 , V_3 , V_83 , 4 , V_102 ) ;
F_65 ( V_2 , V_107 , V_3 , V_83 , 4 , V_102 ) ;
F_65 ( V_2 , V_108 , V_3 , V_83 , 4 , V_102 ) ;
F_65 ( V_2 , V_109 , V_3 , V_83 , 4 , V_102 ) ;
F_65 ( V_2 , V_110 , V_3 , V_83 , 4 , V_102 ) ;
F_65 ( V_2 , V_111 , V_3 , V_83 , 4 , V_102 ) ;
V_83 += 4 ;
if( F_66 ( V_3 , V_83 ) < 2 ) {
return V_83 ;
}
F_65 ( V_2 , V_112 , V_3 , V_83 , 2 , V_102 ) ;
V_83 += 2 ;
if( F_66 ( V_3 , V_83 ) < 2 ) {
return V_83 ;
}
V_100 = F_67 ( V_3 , V_83 ) ;
F_65 ( V_2 , V_113 , V_3 , V_83 , 2 , V_102 ) ;
V_83 += 2 ;
if( V_100 != F_66 ( V_3 , V_83 ) ) {
F_68 ( V_2 , V_7 -> V_1 , & V_114 , V_3 , 0 , 0 ,
L_19 , V_100 , F_52 ( V_3 , V_83 ) ) ;
return V_83 ;
}
V_83 = F_56 ( FALSE , V_3 , V_83 , V_7 , V_2 , - 1 ) ;
return V_83 ;
}
static int
F_69 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 )
{
V_83 = F_70 ( V_7 , V_2 , V_3 , V_83 , V_115 , NULL , 0 ) ;
return V_83 ;
}
static int
F_71 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 )
{
T_24 V_116 ;
F_65 ( V_2 , V_117 , V_3 , V_83 , 4 ,
V_102 ) ;
V_116 = F_64 ( V_3 , V_83 ) ;
if( V_116 ) {
F_72 ( V_7 -> V_1 -> V_118 , V_119 ,
L_20 ,
F_73 ( V_116 , V_120 ,
L_21 ) ) ;
}
V_83 += 4 ;
F_65 ( V_2 , V_121 , V_3 , V_83 , 4 ,
V_102 ) ;
V_83 += 4 ;
F_65 ( V_2 , V_121 , V_3 , V_83 , 4 ,
V_102 ) ;
V_83 += 4 ;
return V_83 ;
}
static int
F_74 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_76 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_77 ( T_30 , V_122 ,
V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_78 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_76 ( T_30 , V_3 , V_83 , V_7 , V_2 , T_28 ) ;
return V_83 ;
}
static int
F_79 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_80 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_123 , T_28 , V_124 ) ;
return V_83 ;
}
static int
F_82 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_125 , T_28 , V_126 ) ;
return V_83 ;
}
static int
F_84 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 223 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
& ( V_8 -> V_98 ) ) ;
return V_83 ;
}
static int
F_85 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_86 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 227 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_87
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , F_50 ) ;
#else
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_90 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_127 , T_28 , V_128 ) ;
return V_83 ;
}
static int
F_91 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_129 , T_28 , V_130 ) ;
return V_83 ;
}
static int
F_92 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 1 , FALSE , F_91 ) ;
return V_83 ;
}
static int
F_94 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 284 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
& ( V_8 -> V_132 ) ) ;
return V_83 ;
}
static int
F_95 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 288 "../../asn1/kerberos/kerberos.cnf"
T_3 * V_97 ;
T_5 * V_8 = F_2 ( V_7 ) ;
switch( V_8 -> V_132 ) {
case V_133 :
V_83 = F_89 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , & V_97 ) ;
F_63 ( V_7 , V_2 , V_97 ) ;
break;
default:
V_83 = F_89 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , NULL ) ;
}
return V_83 ;
return V_83 ;
}
static int
F_96 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_134 , T_28 , V_135 ) ;
return V_83 ;
}
static int
F_97 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_98 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_99 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ) ;
return V_83 ;
}
static int
F_100 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_101 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 302 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
& V_136 ) ;
V_8 -> V_29 . V_12 = V_136 ;
return V_83 ;
}
static int
F_102 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 309 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_8 -> V_29 . V_13 = F_103 ( V_3 , V_83 ) ;
V_8 -> V_29 . V_14 = F_22 ( V_3 , V_83 , V_8 -> V_29 . V_13 ) ;
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_104 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 317 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_137 , T_28 , V_138 ) ;
if ( V_8 -> V_29 . V_12 != 0 ) {
#ifdef F_87
F_9 ( V_7 -> V_1 , V_8 -> V_29 . V_12 , V_8 -> V_29 . V_13 , V_8 -> V_29 . V_14 , L_22 ) ;
#endif
}
return V_83 ;
}
static int
F_105 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 328 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
& ( V_8 -> V_139 ) ) ;
return V_83 ;
}
static int
F_106 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 333 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
switch( V_8 -> V_139 ) {
case V_140 :
V_83 = F_88 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 , V_141 ) ;
break;
default:
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 , NULL ) ;
}
return V_83 ;
}
static int
F_107 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_142 , T_28 , V_143 ) ;
return V_83 ;
}
static int
F_108 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_144 , T_28 , V_145 ) ;
return V_83 ;
}
static int
F_109 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_146 , T_28 , V_147 ) ;
return V_83 ;
}
static int
F_110 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 2 , FALSE , F_109 ) ;
return V_83 ;
}
static int
F_111 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_112 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_148 , T_28 , V_149 ,
NULL ) ;
return V_83 ;
}
static int
F_113 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_114 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_150 , T_28 , V_151 ) ;
return V_83 ;
}
static int
F_115 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 344 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
& ( V_8 -> V_152 ) ) ;
return V_83 ;
}
static int
F_116 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 172 "../../asn1/kerberos/kerberos.cnf"
T_31 V_153 ;
T_14 V_79 ;
T_32 V_4 ;
T_24 V_54 ;
const char * V_154 ;
T_33 * V_155 = NULL ;
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_117 ( V_7 -> V_1 , V_2 , V_3 , V_83 , & V_153 , & V_79 , & V_4 ) ;
V_83 = F_118 ( V_7 -> V_1 , V_2 , V_3 , V_83 , & V_54 , NULL ) ;
switch( V_8 -> V_152 ) {
case V_156 :
V_155 = F_65 ( V_2 , V_157 , V_3 , V_83 , 4 , V_158 ) ;
V_154 = F_119 ( V_3 , V_83 ) ;
break;
case V_159 :
{
char V_160 [ ( V_161 - 1 ) * 4 + 1 ] ;
int V_162 ;
int V_163 = ( V_161 - 1 ) * 4 + 1 ;
V_162 = F_120 ( F_22 ( V_3 , V_83 , 16 ) , V_160 , V_163 ) ;
V_154 = F_121 ( F_4 () , L_23 , V_160 , V_162 ) ;
V_155 = F_122 ( V_2 , V_164 , V_3 , V_83 , 16 , V_160 , L_24 , V_154 , F_123 ( V_162 ) ) ;
}
break;
case V_165 :
V_155 = F_65 ( V_2 , V_166 , V_3 , V_83 , V_167 , V_104 ) ;
V_154 = F_124 ( V_3 , V_83 ) ;
break;
default:
F_125 ( V_2 , V_7 -> V_1 , & V_168 , V_3 , V_83 , V_54 ) ;
V_154 = NULL ;
}
if( V_155 && V_154 ) {
F_126 ( F_127 ( V_155 ) , L_25 , V_154 ) ;
F_126 ( F_128 ( V_155 , 2 ) , L_25 , V_154 ) ;
}
V_83 += V_54 ;
return V_83 ;
return V_83 ;
}
static int
F_129 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_169 , T_28 , V_170 ) ;
return V_83 ;
}
static int
F_130 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_171 , T_28 , V_172 ) ;
return V_83 ;
}
static int
F_131 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_173 , T_28 , V_174 ) ;
return V_83 ;
}
static int
F_132 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 3 , FALSE , F_131 ) ;
return V_83 ;
}
static int
F_133 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 66 "../../asn1/kerberos/kerberos.cnf"
T_24 V_175 ;
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
& V_175 ) ;
#line 71 "../../asn1/kerberos/kerberos.cnf"
if ( V_176 ) {
F_134 ( V_7 -> V_1 -> V_118 , V_119 ,
F_73 ( V_175 , V_177 ,
L_26 ) ) ;
}
V_176 = FALSE ;
#if 0
proto_item_append_text(tree, " %s", val_to_str(msgtype, krb5_msg_types, "Unknown:0x%x"));
#endif
return V_83 ;
}
static int
F_135 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 119 "../../asn1/kerberos/kerberos.cnf"
T_5 * V_8 = F_2 ( V_7 ) ;
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
& ( V_8 -> V_178 ) ) ;
#line 122 "../../asn1/kerberos/kerberos.cnf"
if( V_2 ) {
F_126 ( V_2 , L_25 ,
F_73 ( V_8 -> V_178 , V_179 ,
L_27 ) ) ;
}
return V_83 ;
}
static int
F_136 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 129 "../../asn1/kerberos/kerberos.cnf"
T_2 * V_180 = V_2 ;
T_5 * V_8 = F_2 ( V_7 ) ;
if( V_7 -> V_181 ) {
V_180 = F_137 ( V_7 -> V_181 , V_182 ) ;
}
switch( V_8 -> V_178 ) {
case V_183 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , F_56 ) ;
break;
case V_184 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , V_185 ) ;
break;
case V_186 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , V_187 ) ;
break;
case V_188 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , V_189 ) ;
break;
case V_190 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , V_191 ) ;
break;
case V_192 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , F_69 ) ;
break;
case V_193 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , V_194 ) ;
break;
case V_195 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , V_196 ) ;
break;
case V_197 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , V_198 ) ;
break;
case V_199 :
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , F_71 ) ;
break;
default:
V_83 = F_88 ( FALSE , V_7 , V_180 , V_3 , V_83 , T_28 , NULL ) ;
}
return V_83 ;
}
static int
F_138 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_200 , T_28 , V_182 ) ;
return V_83 ;
}
static int
F_139 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_201 , T_28 , V_202 ) ;
return V_83 ;
}
static int
F_140 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_112 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_203 , T_28 , V_204 ,
NULL ) ;
return V_83 ;
}
static int
F_141 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_205 , T_28 , V_206 ) ;
return V_83 ;
}
static int
F_142 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 235 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_87
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , F_57 ) ;
#else
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_143 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_207 , T_28 , V_208 ) ;
return V_83 ;
}
static int
F_144 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_209 , T_28 , V_210 ) ;
return V_83 ;
}
static int
F_145 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 348 "../../asn1/kerberos/kerberos.cnf"
T_34 * V_211 ;
if ( V_7 -> V_1 -> V_212 == V_213 && V_7 -> V_1 -> V_214 == V_215 ) {
V_211 = F_146 ( V_7 -> V_1 -> V_17 -> V_20 , & V_7 -> V_1 -> V_216 , & V_7 -> V_1 -> V_217 , V_215 ,
V_7 -> V_1 -> V_218 , 0 , V_219 ) ;
if ( V_211 == NULL ) {
V_211 = F_147 ( V_7 -> V_1 -> V_17 -> V_20 , & V_7 -> V_1 -> V_216 , & V_7 -> V_1 -> V_217 , V_215 ,
V_7 -> V_1 -> V_218 , 0 , V_220 ) ;
F_148 ( V_211 , V_221 ) ;
}
}
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_222 , T_28 , V_223 ) ;
return V_83 ;
}
static int
F_149 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_224 , T_28 , V_225 ) ;
return V_83 ;
}
static int
F_150 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 10 , FALSE , F_149 ) ;
return V_83 ;
}
static int
F_151 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 243 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_87
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , F_58 ) ;
#else
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_152 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_226 , T_28 , V_227 ) ;
return V_83 ;
}
static int
F_153 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_228 , T_28 , V_229 ) ;
return V_83 ;
}
static int
F_154 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 11 , FALSE , F_153 ) ;
return V_83 ;
}
static int
F_155 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 12 , FALSE , F_149 ) ;
return V_83 ;
}
static int
F_156 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 13 , FALSE , F_153 ) ;
return V_83 ;
}
static int
F_157 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_112 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_230 , T_28 , V_231 ,
NULL ) ;
return V_83 ;
}
static int
F_158 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_232 , T_28 , V_233 ) ;
return V_83 ;
}
static int
F_159 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 14 , FALSE , F_158 ) ;
return V_83 ;
}
static int
F_160 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 259 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_87
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , F_60 ) ;
#else
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_161 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_234 , T_28 , V_235 ) ;
return V_83 ;
}
static int
F_162 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_236 , T_28 , V_237 ) ;
return V_83 ;
}
static int
F_163 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 15 , FALSE , F_162 ) ;
return V_83 ;
}
static int
F_164 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 371 "../../asn1/kerberos/kerberos.cnf"
T_3 * V_238 ;
V_83 = F_89 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , & V_238 ) ;
if ( V_238 ) {
F_1 ( V_7 -> V_1 , V_2 , V_238 , V_239 , ( T_4 * ) V_7 -> V_8 ) ;
}
return V_83 ;
}
static int
F_165 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_240 , T_28 , V_241 ) ;
return V_83 ;
}
static int
F_166 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_242 , T_28 , V_243 ) ;
return V_83 ;
}
static int
F_167 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 20 , FALSE , F_166 ) ;
return V_83 ;
}
static int
F_168 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 267 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_87
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , F_61 ) ;
#else
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_169 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_244 , T_28 , V_245 ) ;
return V_83 ;
}
static int
F_170 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_246 , T_28 , V_247 ) ;
return V_83 ;
}
static int
F_171 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 21 , FALSE , F_170 ) ;
return V_83 ;
}
static int
F_172 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 275 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_87
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , F_62 ) ;
#else
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
F_173 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_248 , T_28 , V_249 ) ;
return V_83 ;
}
static int
F_174 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_250 , T_28 , V_251 ) ;
return V_83 ;
}
static int
F_175 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 22 , FALSE , F_174 ) ;
return V_83 ;
}
static int
F_176 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
F_177 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_252 , T_28 , V_253 ) ;
return V_83 ;
}
static int
F_178 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_254 , T_28 , V_255 ) ;
return V_83 ;
}
static int
F_179 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_256 , T_28 , V_257 ) ;
return V_83 ;
}
static int
F_180 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_258 , T_28 , V_259 ) ;
return V_83 ;
}
static int
F_181 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 25 , FALSE , F_180 ) ;
return V_83 ;
}
static int
F_182 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 26 , FALSE , F_180 ) ;
return V_83 ;
}
static int
F_183 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_260 , T_28 , V_261 ) ;
return V_83 ;
}
static int
F_184 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 27 , FALSE , F_183 ) ;
return V_83 ;
}
static int
F_185 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 378 "../../asn1/kerberos/kerberos.cnf"
T_3 * V_238 ;
V_83 = F_89 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , & V_238 ) ;
if ( V_238 ) {
F_1 ( V_7 -> V_1 , V_2 , V_238 , V_262 , ( T_4 * ) V_7 -> V_8 ) ;
}
return V_83 ;
}
static int
F_186 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_263 , T_28 , V_264 ) ;
return V_83 ;
}
static int
F_187 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 28 , FALSE , F_186 ) ;
return V_83 ;
}
static int
F_188 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_265 , T_28 , V_266 ) ;
return V_83 ;
}
static int
F_189 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_267 , T_28 , V_268 ) ;
return V_83 ;
}
static int
F_190 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_269 , T_28 , V_270 ) ;
return V_83 ;
}
static int
F_191 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 29 , FALSE , F_190 ) ;
return V_83 ;
}
static int
F_192 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 84 "../../asn1/kerberos/kerberos.cnf"
V_83 = F_75 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
& V_271 ) ;
#line 87 "../../asn1/kerberos/kerberos.cnf"
if( V_271 ) {
F_193 ( V_7 -> V_1 -> V_118 , V_119 ,
L_28 ,
F_73 ( V_271 , V_272 ,
L_21 ) ) ;
}
return V_83 ;
return V_83 ;
}
static int
F_194 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 97 "../../asn1/kerberos/kerberos.cnf"
switch( V_271 ) {
case V_273 :
case V_274 :
case V_275 :
case V_276 :
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , V_277 , F_138 ) ;
break;
case V_278 :
case V_279 :
case V_280 :
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , V_277 , F_139 ) ;
break;
default:
V_83 = F_89 ( FALSE , V_7 , V_2 , V_3 , V_83 , V_277 , NULL ) ;
}
return V_83 ;
}
static int
F_195 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_281 , T_28 , V_282 ) ;
return V_83 ;
}
static int
F_196 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_93 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
T_28 , V_131 , 30 , FALSE , F_195 ) ;
return V_83 ;
}
static int
F_56 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_197 ( V_7 , V_2 , V_3 , V_83 ,
V_283 , T_28 , V_284 ,
NULL ) ;
return V_83 ;
}
static int
F_198 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
#line 251 "../../asn1/kerberos/kerberos.cnf"
#ifdef F_87
V_83 = F_88 ( FALSE , V_7 , V_2 , V_3 , V_83 , T_28 , F_59 ) ;
#else
V_83 = F_89 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
#endif
return V_83 ;
return V_83 ;
}
static int
V_194 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_285 , T_28 , V_286 ) ;
return V_83 ;
}
static int
F_199 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_287 , T_28 , V_288 ) ;
return V_83 ;
}
static int
V_196 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_289 , T_28 , V_290 ) ;
return V_83 ;
}
static int
F_200 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_291 , T_28 , V_292 ) ;
return V_83 ;
}
static int
V_198 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_81 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_293 , T_28 , V_294 ) ;
return V_83 ;
}
static int
V_141 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_108 ( T_30 , V_3 , V_83 , V_7 , V_2 , T_28 ) ;
return V_83 ;
}
static int
F_201 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_77 ( T_30 , V_122 ,
V_7 , V_2 , V_3 , V_83 , T_28 ,
NULL ) ;
return V_83 ;
}
static int
V_191 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_295 , T_28 , V_296 ) ;
return V_83 ;
}
static int
F_202 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_203 ( T_30 , V_7 , V_2 , V_3 , V_83 , T_28 , NULL ) ;
return V_83 ;
}
static int
V_189 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_297 , T_28 , V_298 ) ;
return V_83 ;
}
int
F_204 ( T_14 T_30 V_26 , T_3 * V_3 V_26 , int V_83 V_26 , T_6 * V_7 V_26 , T_2 * V_2 V_26 , int T_28 V_26 ) {
V_83 = F_83 ( T_30 , V_7 , V_2 , V_3 , V_83 ,
V_299 , T_28 , V_300 ) ;
return V_83 ;
}
int
F_205 ( T_2 * V_2 , T_3 * V_3 , int V_83 , T_6 * V_7 V_26 )
{
return F_96 ( FALSE , V_3 , V_83 , V_7 , V_2 , V_301 ) ;
}
int
F_206 ( T_2 * V_2 , T_3 * V_3 , int V_83 , T_6 * V_7 V_26 )
{
return F_98 ( FALSE , V_3 , V_83 , V_7 , V_2 , V_302 ) ;
}
int
F_207 ( T_2 * V_2 , T_3 * V_3 , int V_83 , T_6 * V_7 V_26 )
{
return F_82 ( FALSE , V_3 , V_83 , V_7 , V_2 , V_303 ) ;
}
int
F_208 ( T_2 * V_2 , T_3 * V_3 , int V_83 , T_6 * V_7 V_26 )
{
return F_78 ( FALSE , V_3 , V_83 , V_7 , V_2 , V_304 ) ;
}
static T_35
F_209 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 ,
T_14 V_305 , T_14 V_306 , T_14 V_307 ,
T_4 * V_5 )
{
volatile int V_83 = 0 ;
T_2 * volatile V_308 = NULL ;
T_33 * volatile V_309 = NULL ;
T_6 V_310 ;
T_24 V_311 = 0 ;
T_35 V_312 = 0 ;
V_176 = V_305 ;
if ( V_307 ) {
V_311 = F_210 ( V_3 , V_83 ) ;
V_312 = F_211 ( V_311 ) ;
if ( V_312 > 10 * 1024 * 1024 ) {
return ( - 1 ) ;
}
if ( V_306 ) {
F_212 ( V_1 -> V_118 , V_313 , L_29 ) ;
}
if ( V_2 ) {
V_309 = F_65 ( V_2 , V_314 , V_3 , 0 , - 1 , V_104 ) ;
V_308 = F_137 ( V_309 , V_315 ) ;
}
F_213 ( V_308 , V_3 , V_83 , V_311 ) ;
V_83 += 4 ;
} else {
T_31 V_316 ;
T_14 V_317 ;
T_32 V_318 ;
F_43 ( V_3 , V_83 , & V_316 , & V_317 , & V_318 ) ;
if( V_316 != V_131 ) {
return 0 ;
}
switch( V_318 ) {
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
case V_334 :
case V_335 :
break;
default:
return 0 ;
}
if ( V_306 ) {
F_212 ( V_1 -> V_118 , V_313 , L_29 ) ;
}
if ( V_176 ) {
F_214 ( V_1 -> V_118 , V_119 ) ;
}
if ( V_2 ) {
V_309 = F_65 ( V_2 , V_314 , V_3 , 0 , - 1 , V_104 ) ;
V_308 = F_137 ( V_309 , V_315 ) ;
}
}
F_215 ( & V_310 , V_336 , TRUE , V_1 ) ;
V_310 . V_8 = V_5 ;
F_42 {
V_83 = F_56 ( FALSE , V_3 , V_83 , & V_310 , V_308 , - 1 ) ;
} F_45 {
V_337 ;
} V_96 ;
F_216 ( V_309 , V_83 ) ;
return V_83 ;
}
void
F_213 ( T_2 * V_2 , T_3 * V_3 , T_35 V_338 , T_24 V_311 )
{
T_35 V_339 ;
T_2 * V_340 ;
if ( V_2 == NULL )
return;
V_339 = F_211 ( V_311 ) ;
V_340 = F_217 ( V_2 , V_3 , V_338 , 4 , V_341 , NULL ,
L_30 , V_339 , F_218 ( V_339 , L_31 , L_32 ) ) ;
F_219 ( V_340 , V_342 , V_3 , V_338 , 4 , V_311 ) ;
F_220 ( V_340 , V_343 , V_3 , V_338 , 4 , V_311 ) ;
}
T_35
F_221 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , int V_344 , T_4 * V_5 )
{
return ( F_209 ( V_3 , V_1 , V_2 , V_344 , FALSE , FALSE , V_5 ) ) ;
}
T_24
F_222 ( void )
{
return V_136 ;
}
static T_35
F_223 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , void * V_39 V_26 )
{
if( F_21 ( V_3 ) >= 1 && F_224 ( V_3 , 0 ) <= 0x10 ) {
if( V_345 ) {
T_14 V_346 ;
V_346 = F_225 ( V_345 , V_3 , V_1 , V_2 , NULL ) ;
return V_346 ;
} else{
return 0 ;
}
}
return F_209 ( V_3 , V_1 , V_2 , TRUE , TRUE , FALSE , NULL ) ;
}
T_35
F_211 ( T_36 V_311 )
{
return ( V_311 & V_347 ) ;
}
T_36
F_226 ( T_1 * V_1 V_26 , T_3 * V_3 , int V_83 )
{
T_36 V_311 ;
T_35 V_348 ;
V_311 = F_210 ( V_3 , V_83 ) ;
V_348 = F_211 ( V_311 ) ;
return ( V_348 + 4 ) ;
}
static void
F_227 ( void ) {
#ifdef F_228
F_30 () ;
F_8 ( V_11 ) ;
#endif
}
static int
F_229 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , void * V_39 V_26 )
{
V_1 -> V_349 = TRUE ;
if ( F_209 ( V_3 , V_1 , V_2 , TRUE , TRUE , TRUE , NULL ) < 0 ) {
F_212 ( V_1 -> V_118 , V_119 , L_33 ) ;
}
return F_21 ( V_3 ) ;
}
static int
F_230 ( T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , void * V_39 )
{
F_212 ( V_1 -> V_118 , V_313 , L_29 ) ;
F_214 ( V_1 -> V_118 , V_119 ) ;
F_231 ( V_3 , V_1 , V_2 , V_350 , 4 , F_226 ,
F_229 , V_39 ) ;
return F_21 ( V_3 ) ;
}
void F_232 ( void ) {
static T_37 V_351 [] = {
{ & V_342 , {
L_34 , L_35 , V_352 , 32 ,
F_233 ( & V_353 ) , V_354 , L_36 , V_355 } } ,
{ & V_343 , {
L_37 , L_38 , V_356 , V_357 ,
NULL , V_347 , NULL , V_355 } } ,
{ & V_115 , {
L_39 , L_40 , V_358 , V_359 ,
NULL , 0 , L_41 , V_355 } } ,
{ & V_117 ,
{ L_42 , L_43 , V_356 , V_360 ,
F_234 ( V_120 ) , 0 , L_44 , V_355 } } ,
{ & V_121 ,
{ L_45 , L_46 , V_356 , V_360 ,
NULL , 0 , NULL , V_355 } } ,
{ & V_157 , {
L_47 , L_48 , V_361 , V_359 ,
NULL , 0 , NULL , V_355 } } ,
{ & V_166 , {
L_49 , L_50 , V_362 , V_359 ,
NULL , 0 , NULL , V_355 } } ,
{ & V_164 , {
L_51 , L_52 , V_358 , V_359 ,
NULL , 0 , L_53 , V_355 } } ,
{ & V_101 , {
L_54 , L_55 , V_356 , V_357 ,
NULL , 0 , L_56 , V_355 } } ,
{ & V_103 , {
L_57 , L_58 , V_363 , V_359 ,
NULL , 0 , L_59 , V_355 } } ,
{ & V_111 , {
L_60 , L_61 , V_352 , 32 ,
F_233 ( & V_364 ) , V_365 , NULL , V_355 } } ,
{ & V_110 , {
L_62 , L_63 , V_352 , 32 ,
F_233 ( & V_366 ) , V_367 , NULL , V_355 } } ,
{ & V_109 , {
L_64 , L_65 , V_352 , 32 ,
F_233 ( & V_368 ) , V_369 , NULL , V_355 } } ,
{ & V_108 , {
L_66 , L_67 , V_352 , 32 ,
F_233 ( & V_370 ) , V_371 , NULL , V_355 } } ,
{ & V_107 , {
L_68 , L_69 , V_352 , 32 ,
F_233 ( & V_372 ) , V_373 , NULL , V_355 } } ,
{ & V_106 , {
L_70 , L_71 , V_352 , 32 ,
F_233 ( & V_374 ) , V_375 , NULL , V_355 } } ,
{ & V_105 , {
L_72 , L_73 , V_352 , 32 ,
F_233 ( & V_376 ) , V_377 , NULL , V_355 } } ,
{ & V_112 , {
L_74 , L_75 , V_378 , V_357 ,
NULL , 0 , L_76 , V_355 } } ,
{ & V_113 , {
L_77 , L_78 , V_378 , V_357 ,
NULL , 0 , L_79 , V_355 } } ,
#line 1 "../../asn1/kerberos/packet-kerberos-hfarr.c"
{ & V_379 ,
{ L_80 , L_81 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_381 ,
{ L_82 , L_83 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_382 ,
{ L_84 , L_85 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_383 ,
{ L_86 , L_87 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_384 ,
{ L_88 , L_89 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_385 ,
{ L_90 , L_91 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_386 ,
{ L_92 , L_93 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_387 ,
{ L_94 , L_95 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_388 ,
{ L_96 , L_97 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_389 ,
{ L_98 , L_99 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_390 ,
{ L_100 , L_101 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_391 ,
{ L_102 , L_103 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_392 ,
{ L_104 , L_105 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_393 ,
{ L_106 , L_107 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_394 ,
{ L_108 , L_109 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_395 ,
{ L_110 , L_111 ,
V_380 , V_359 , NULL , 0 ,
L_112 , V_355 } } ,
{ & V_396 ,
{ L_113 , L_114 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_397 ,
{ L_115 , L_116 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_398 ,
{ L_117 , L_118 ,
V_399 , V_357 , F_234 ( V_400 ) , 0 ,
NULL , V_355 } } ,
{ & V_401 ,
{ L_119 , L_120 ,
V_356 , V_357 , NULL , 0 ,
L_121 , V_355 } } ,
{ & V_402 ,
{ L_122 , L_123 ,
V_358 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_403 ,
{ L_124 , L_125 ,
V_399 , V_357 , F_234 ( V_404 ) , 0 ,
NULL , V_355 } } ,
{ & V_405 ,
{ L_126 , L_127 ,
V_363 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_406 ,
{ L_128 , L_129 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_407 ,
{ L_130 , L_131 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_408 ,
{ L_132 , L_133 ,
V_399 , V_357 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_409 ,
{ L_134 , L_135 ,
V_363 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_410 ,
{ L_136 , L_137 ,
V_399 , V_357 , F_234 ( V_411 ) , 0 ,
NULL , V_355 } } ,
{ & V_412 ,
{ L_138 , L_139 ,
V_363 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_413 ,
{ L_140 , L_141 ,
V_399 , V_357 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_414 ,
{ L_142 , L_143 ,
V_363 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_415 ,
{ L_144 , L_145 ,
V_399 , V_357 , F_234 ( V_416 ) , 0 ,
NULL , V_355 } } ,
{ & V_417 ,
{ L_146 , L_147 ,
V_363 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_418 ,
{ L_148 , L_149 ,
V_399 , V_357 , F_234 ( V_419 ) , 0 ,
L_150 , V_355 } } ,
{ & V_420 ,
{ L_151 , L_152 ,
V_356 , V_357 , NULL , 0 ,
L_153 , V_355 } } ,
{ & V_421 ,
{ L_154 , L_155 ,
V_363 , V_359 , NULL , 0 ,
L_156 , V_355 } } ,
{ & V_422 ,
{ L_154 , L_155 ,
V_363 , V_359 , NULL , 0 ,
L_157 , V_355 } } ,
{ & V_423 ,
{ L_154 , L_155 ,
V_363 , V_359 , NULL , 0 ,
L_158 , V_355 } } ,
{ & V_424 ,
{ L_154 , L_155 ,
V_363 , V_359 , NULL , 0 ,
L_159 , V_355 } } ,
{ & V_425 ,
{ L_154 , L_155 ,
V_363 , V_359 , NULL , 0 ,
L_160 , V_355 } } ,
{ & V_426 ,
{ L_154 , L_155 ,
V_363 , V_359 , NULL , 0 ,
L_161 , V_355 } } ,
{ & V_427 ,
{ L_162 , L_163 ,
V_356 , V_357 , NULL , 0 ,
L_164 , V_355 } } ,
{ & V_304 ,
{ L_165 , L_166 ,
V_358 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_428 ,
{ L_167 , L_168 ,
V_380 , V_359 , NULL , 0 ,
L_169 , V_355 } } ,
{ & V_429 ,
{ L_170 , L_171 ,
V_380 , V_359 , NULL , 0 ,
L_172 , V_355 } } ,
{ & V_430 ,
{ L_173 , L_174 ,
V_363 , V_359 , NULL , 0 ,
L_175 , V_355 } } ,
{ & V_431 ,
{ L_22 , L_176 ,
V_380 , V_359 , NULL , 0 ,
L_177 , V_355 } } ,
{ & V_432 ,
{ L_178 , L_179 ,
V_358 , V_359 , NULL , 0 ,
L_180 , V_355 } } ,
{ & V_303 ,
{ L_181 , L_182 ,
V_380 , V_359 , NULL , 0 ,
L_169 , V_355 } } ,
{ & V_433 ,
{ L_183 , L_184 ,
V_380 , V_359 , NULL , 0 ,
L_185 , V_355 } } ,
{ & V_434 ,
{ L_186 , L_187 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_435 ,
{ L_189 , L_190 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_436 ,
{ L_191 , L_192 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_437 ,
{ L_193 , L_194 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_438 ,
{ L_195 , L_196 ,
V_356 , V_357 , NULL , 0 ,
L_197 , V_355 } } ,
{ & V_439 ,
{ L_198 , L_199 ,
V_356 , V_357 , NULL , 0 ,
L_200 , V_355 } } ,
{ & V_440 ,
{ L_201 , L_202 ,
V_399 , V_357 , NULL , 0 ,
L_203 , V_355 } } ,
{ & V_441 ,
{ L_204 , L_205 ,
V_363 , V_359 , NULL , 0 ,
L_206 , V_355 } } ,
{ & V_442 ,
{ L_207 , L_208 ,
V_356 , V_357 , NULL , 0 ,
L_164 , V_355 } } ,
{ & V_443 ,
{ L_209 , L_210 ,
V_399 , V_357 , F_234 ( V_444 ) , 0 ,
L_211 , V_355 } } ,
{ & V_445 ,
{ L_212 , L_213 ,
V_356 , V_357 , NULL , 0 ,
L_214 , V_355 } } ,
{ & V_446 ,
{ L_215 , L_216 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_447 ,
{ L_217 , L_218 ,
V_380 , V_359 , NULL , 0 ,
L_219 , V_355 } } ,
{ & V_448 ,
{ L_220 , L_221 ,
V_363 , V_359 , NULL , 0 ,
L_222 , V_355 } } ,
{ & V_449 ,
{ L_223 , L_224 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_450 ,
{ L_225 , L_226 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_451 ,
{ L_227 , L_228 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_452 ,
{ L_229 , L_230 ,
V_356 , V_357 , NULL , 0 ,
L_153 , V_355 } } ,
{ & V_453 ,
{ L_148 , L_149 ,
V_356 , V_357 , NULL , 0 ,
L_231 , V_355 } } ,
{ & V_454 ,
{ L_150 , L_232 ,
V_399 , V_357 , F_234 ( V_419 ) , 0 ,
NULL , V_355 } } ,
{ & V_455 ,
{ L_233 , L_234 ,
V_356 , V_357 , NULL , 0 ,
L_197 , V_355 } } ,
{ & V_456 ,
{ L_235 , L_236 ,
V_380 , V_359 , NULL , 0 ,
L_237 , V_355 } } ,
{ & V_457 ,
{ L_238 , L_239 ,
V_356 , V_357 , NULL , 0 ,
L_240 , V_355 } } ,
{ & V_458 ,
{ L_241 , L_242 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_459 ,
{ L_170 , L_171 ,
V_380 , V_359 , NULL , 0 ,
L_243 , V_355 } } ,
{ & V_460 ,
{ L_244 , L_245 ,
V_356 , V_357 , NULL , 0 ,
L_246 , V_355 } } ,
{ & V_461 ,
{ L_247 , L_248 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_462 ,
{ L_249 , L_250 ,
V_358 , V_359 , NULL , 0 ,
L_180 , V_355 } } ,
{ & V_463 ,
{ L_251 , L_252 ,
V_356 , V_357 , NULL , 0 ,
L_253 , V_355 } } ,
{ & V_464 ,
{ L_254 , L_255 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_465 ,
{ L_256 , L_257 ,
V_399 , V_357 , F_234 ( V_466 ) , 0 ,
NULL , V_355 } } ,
{ & V_467 ,
{ L_258 , L_259 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_468 ,
{ L_260 , L_261 ,
V_363 , V_359 , NULL , 0 ,
L_262 , V_355 } } ,
{ & V_469 ,
{ L_82 , L_83 ,
V_380 , V_359 , NULL , 0 ,
L_237 , V_355 } } ,
{ & V_470 ,
{ L_263 , L_264 ,
V_356 , V_357 , NULL , 0 ,
L_164 , V_355 } } ,
{ & V_301 ,
{ L_265 , L_266 ,
V_380 , V_359 , NULL , 0 ,
L_267 , V_355 } } ,
{ & V_471 ,
{ L_268 , L_269 ,
V_356 , V_357 , NULL , 0 ,
L_270 , V_355 } } ,
{ & V_302 ,
{ L_271 , L_272 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_472 ,
{ L_273 , L_274 ,
V_380 , V_359 , NULL , 0 ,
L_177 , V_355 } } ,
{ & V_473 ,
{ L_275 , L_276 ,
V_356 , V_357 , NULL , 0 ,
L_153 , V_355 } } ,
{ & V_474 ,
{ L_170 , L_171 ,
V_380 , V_359 , NULL , 0 ,
L_277 , V_355 } } ,
{ & V_475 ,
{ L_278 , L_279 ,
V_380 , V_359 , NULL , 0 ,
L_280 , V_355 } } ,
{ & V_476 ,
{ L_281 , L_282 ,
V_363 , V_359 , NULL , 0 ,
L_283 , V_355 } } ,
{ & V_477 ,
{ L_284 , L_285 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_478 ,
{ L_286 , L_287 ,
V_356 , V_357 , NULL , 0 ,
L_270 , V_355 } } ,
{ & V_479 ,
{ L_288 , L_289 ,
V_380 , V_359 , NULL , 0 ,
L_128 , V_355 } } ,
{ & V_480 ,
{ L_290 , L_291 ,
V_380 , V_359 , NULL , 0 ,
L_128 , V_355 } } ,
{ & V_481 ,
{ L_170 , L_171 ,
V_380 , V_359 , NULL , 0 ,
L_292 , V_355 } } ,
{ & V_482 ,
{ L_281 , L_282 ,
V_363 , V_359 , NULL , 0 ,
L_293 , V_355 } } ,
{ & V_483 ,
{ L_294 , L_295 ,
V_356 , V_357 , NULL , 0 ,
L_240 , V_355 } } ,
{ & V_484 ,
{ L_241 , L_242 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_485 ,
{ L_170 , L_171 ,
V_380 , V_359 , NULL , 0 ,
L_296 , V_355 } } ,
{ & V_486 ,
{ L_297 , L_298 ,
V_356 , V_357 , NULL , 0 ,
L_299 , V_355 } } ,
{ & V_487 ,
{ L_300 , L_301 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_488 ,
{ L_302 , L_303 ,
V_358 , V_359 , NULL , 0 ,
L_180 , V_355 } } ,
{ & V_489 ,
{ L_304 , L_305 ,
V_380 , V_359 , NULL , 0 ,
L_169 , V_355 } } ,
{ & V_490 ,
{ L_306 , L_307 ,
V_358 , V_359 , NULL , 0 ,
L_188 , V_355 } } ,
{ & V_491 ,
{ L_308 , L_309 ,
V_356 , V_357 , NULL , 0 ,
L_270 , V_355 } } ,
{ & V_492 ,
{ L_310 , L_311 ,
V_399 , V_357 , F_234 ( V_493 ) , 0 ,
NULL , V_355 } } ,
{ & V_494 ,
{ L_312 , L_313 ,
V_358 , V_359 , NULL , 0 ,
L_122 , V_355 } } ,
{ & V_277 ,
{ L_314 , L_315 ,
V_363 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_495 ,
{ L_316 , L_317 ,
V_380 , V_359 , NULL , 0 ,
L_267 , V_355 } } ,
{ & V_496 ,
{ L_215 , L_216 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_497 ,
{ L_154 , L_155 ,
V_363 , V_359 , NULL , 0 ,
L_318 , V_355 } } ,
{ & V_498 ,
{ L_319 , L_320 ,
V_363 , V_359 , NULL , 0 ,
L_206 , V_355 } } ,
{ & V_499 ,
{ L_321 , L_322 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_500 ,
{ L_319 , L_320 ,
V_358 , V_359 , NULL , 0 ,
L_122 , V_355 } } ,
{ & V_501 ,
{ L_323 , L_324 ,
V_363 , V_359 , NULL , 0 ,
L_206 , V_355 } } ,
{ & V_502 ,
{ L_325 , L_326 ,
V_380 , V_359 , NULL , 0 ,
NULL , V_355 } } ,
{ & V_503 ,
{ L_327 , L_328 ,
V_380 , V_359 , NULL , 0 ,
L_169 , V_355 } } ,
{ & V_504 ,
{ L_329 , L_330 ,
V_358 , V_359 , NULL , 0 ,
L_331 , V_355 } } ,
{ & V_505 ,
{ L_332 , L_333 ,
V_352 , V_359 , NULL , 0 ,
L_334 , V_355 } } ,
{ & V_506 ,
{ L_335 , L_336 ,
V_363 , V_359 , NULL , 0 ,
L_206 , V_355 } } ,
{ & V_507 ,
{ L_337 , L_338 ,
V_380 , V_359 , NULL , 0 ,
L_169 , V_355 } } ,
{ & V_508 ,
{ L_339 , L_340 ,
V_358 , V_359 , NULL , 0 ,
L_180 , V_355 } } ,
{ & V_509 ,
{ L_341 , L_342 ,
V_352 , 8 , NULL , 0x80 ,
NULL , V_355 } } ,
{ & V_510 ,
{ L_343 , L_344 ,
V_352 , 8 , NULL , 0x40 ,
NULL , V_355 } } ,
{ & V_511 ,
{ L_345 , L_346 ,
V_352 , 8 , NULL , 0x20 ,
NULL , V_355 } } ,
{ & V_512 ,
{ L_341 , L_342 ,
V_352 , 8 , NULL , 0x80 ,
NULL , V_355 } } ,
{ & V_513 ,
{ L_347 , L_348 ,
V_352 , 8 , NULL , 0x40 ,
NULL , V_355 } } ,
{ & V_514 ,
{ L_349 , L_350 ,
V_352 , 8 , NULL , 0x20 ,
NULL , V_355 } } ,
{ & V_515 ,
{ L_351 , L_352 ,
V_352 , 8 , NULL , 0x10 ,
NULL , V_355 } } ,
{ & V_516 ,
{ L_353 , L_354 ,
V_352 , 8 , NULL , 0x08 ,
NULL , V_355 } } ,
{ & V_517 ,
{ L_355 , L_356 ,
V_352 , 8 , NULL , 0x04 ,
NULL , V_355 } } ,
{ & V_518 ,
{ L_357 , L_358 ,
V_352 , 8 , NULL , 0x02 ,
NULL , V_355 } } ,
{ & V_519 ,
{ L_359 , L_360 ,
V_352 , 8 , NULL , 0x01 ,
NULL , V_355 } } ,
{ & V_520 ,
{ L_361 , L_362 ,
V_352 , 8 , NULL , 0x80 ,
NULL , V_355 } } ,
{ & V_521 ,
{ L_363 , L_364 ,
V_352 , 8 , NULL , 0x40 ,
NULL , V_355 } } ,
{ & V_522 ,
{ L_365 , L_366 ,
V_352 , 8 , NULL , 0x20 ,
NULL , V_355 } } ,
{ & V_523 ,
{ L_367 , L_368 ,
V_352 , 8 , NULL , 0x10 ,
NULL , V_355 } } ,
{ & V_524 ,
{ L_369 , L_370 ,
V_352 , 8 , NULL , 0x08 ,
NULL , V_355 } } ,
{ & V_525 ,
{ L_371 , L_372 ,
V_352 , 8 , NULL , 0x04 ,
NULL , V_355 } } ,
{ & V_526 ,
{ L_373 , L_374 ,
V_352 , 8 , NULL , 0x02 ,
NULL , V_355 } } ,
{ & V_527 ,
{ L_341 , L_342 ,
V_352 , 8 , NULL , 0x80 ,
NULL , V_355 } } ,
{ & V_528 ,
{ L_347 , L_348 ,
V_352 , 8 , NULL , 0x40 ,
NULL , V_355 } } ,
{ & V_529 ,
{ L_349 , L_350 ,
V_352 , 8 , NULL , 0x20 ,
NULL , V_355 } } ,
{ & V_530 ,
{ L_351 , L_352 ,
V_352 , 8 , NULL , 0x10 ,
NULL , V_355 } } ,
{ & V_531 ,
{ L_353 , L_354 ,
V_352 , 8 , NULL , 0x08 ,
NULL , V_355 } } ,
{ & V_532 ,
{ L_375 , L_376 ,
V_352 , 8 , NULL , 0x04 ,
NULL , V_355 } } ,
{ & V_533 ,
{ L_357 , L_358 ,
V_352 , 8 , NULL , 0x02 ,
NULL , V_355 } } ,
{ & V_534 ,
{ L_377 , L_378 ,
V_352 , 8 , NULL , 0x01 ,
NULL , V_355 } } ,
{ & V_535 ,
{ L_361 , L_362 ,
V_352 , 8 , NULL , 0x80 ,
NULL , V_355 } } ,
{ & V_536 ,
{ L_379 , L_380 ,
V_352 , 8 , NULL , 0x40 ,
NULL , V_355 } } ,
{ & V_537 ,
{ L_381 , L_382 ,
V_352 , 8 , NULL , 0x20 ,
NULL , V_355 } } ,
{ & V_538 ,
{ L_383 , L_384 ,
V_352 , 8 , NULL , 0x10 ,
NULL , V_355 } } ,
{ & V_539 ,
{ L_385 , L_386 ,
V_352 , 8 , NULL , 0x02 ,
NULL , V_355 } } ,
{ & V_540 ,
{ L_387 , L_388 ,
V_352 , 8 , NULL , 0x01 ,
NULL , V_355 } } ,
{ & V_541 ,
{ L_389 , L_390 ,
V_352 , 8 , NULL , 0x80 ,
NULL , V_355 } } ,
{ & V_542 ,
{ L_391 , L_392 ,
V_352 , 8 , NULL , 0x20 ,
NULL , V_355 } } ,
{ & V_543 ,
{ L_393 , L_394 ,
V_352 , 8 , NULL , 0x10 ,
NULL , V_355 } } ,
{ & V_544 ,
{ L_395 , L_396 ,
V_352 , 8 , NULL , 0x08 ,
NULL , V_355 } } ,
{ & V_545 ,
{ L_397 , L_398 ,
V_352 , 8 , NULL , 0x02 ,
NULL , V_355 } } ,
{ & V_546 ,
{ L_399 , L_400 ,
V_352 , 8 , NULL , 0x01 ,
NULL , V_355 } } ,
#line 1957 "../../asn1/kerberos/packet-kerberos-template.c"
} ;
static T_35 * V_547 [] = {
& V_315 ,
& V_341 ,
#line 1 "../../asn1/kerberos/packet-kerberos-ettarr.c"
& V_284 ,
& V_126 ,
& V_124 ,
& V_170 ,
& V_172 ,
& V_145 ,
& V_143 ,
& V_182 ,
& V_138 ,
& V_135 ,
& V_128 ,
& V_208 ,
& V_227 ,
& V_235 ,
& V_245 ,
& V_249 ,
& V_130 ,
& V_174 ,
& V_151 ,
& V_225 ,
& V_202 ,
& V_223 ,
& V_206 ,
& V_210 ,
& V_229 ,
& V_259 ,
& V_255 ,
& V_253 ,
& V_233 ,
& V_147 ,
& V_237 ,
& V_261 ,
& V_243 ,
& V_241 ,
& V_247 ,
& V_264 ,
& V_251 ,
& V_270 ,
& V_268 ,
& V_266 ,
& V_282 ,
& V_257 ,
& V_286 ,
& V_288 ,
& V_290 ,
& V_292 ,
& V_294 ,
& V_231 ,
& V_149 ,
& V_204 ,
& V_296 ,
& V_298 ,
& V_300 ,
#line 1964 "../../asn1/kerberos/packet-kerberos-template.c"
} ;
static T_38 V_548 [] = {
{ & V_51 , { L_401 , V_549 , V_550 , L_402 , V_551 } } ,
{ & V_168 , { L_403 , V_552 , V_553 , L_404 , V_551 } } ,
{ & V_114 , { L_405 , V_554 , V_555 , L_406 , V_551 } } ,
} ;
T_39 * V_556 ;
T_40 * V_557 ;
V_314 = F_235 ( L_407 , L_29 , L_408 ) ;
F_236 ( V_314 , V_351 , F_237 ( V_351 ) ) ;
F_238 ( V_547 , F_237 ( V_547 ) ) ;
V_556 = F_239 ( V_314 ) ;
F_240 ( V_556 , V_548 , F_237 ( V_548 ) ) ;
V_557 = F_241 ( V_314 , F_227 ) ;
F_242 ( V_557 , L_409 ,
L_410 ,
L_411
L_412 ,
& V_350 ) ;
#ifdef F_87
F_242 ( V_557 , L_413 ,
L_414 ,
L_415
L_416
L_417 , & V_10 ) ;
F_243 ( V_557 , L_418 ,
L_419 ,
L_420 ,
& V_11 ) ;
#endif
}
static int F_244 ( T_3 * V_3 , int V_83 , T_1 * V_1 ,
T_2 * V_2 , T_41 * T_42 V_26 , T_15 * T_43 V_26 )
{
T_3 * V_558 ;
V_558 = F_51 ( V_3 , V_83 ) ;
F_221 ( V_558 , V_1 , V_2 , FALSE , NULL ) ;
return F_52 ( V_3 , V_83 ) ;
}
void
F_245 ( void )
{
T_44 V_559 ;
V_345 = F_246 ( L_421 ) ;
V_221 = F_247 ( F_223 ,
V_314 ) ;
V_559 = F_247 ( F_230 ,
V_314 ) ;
F_248 ( L_422 , V_213 , V_221 ) ;
F_248 ( L_423 , V_560 , V_559 ) ;
F_249 ( V_561 ,
V_562 ,
& V_563 ) ;
F_249 ( V_564 ,
V_562 ,
& V_565 ) ;
F_249 ( V_566 ,
V_562 ,
& V_567 ) ;
}
