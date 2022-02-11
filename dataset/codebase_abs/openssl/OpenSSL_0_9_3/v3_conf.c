T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 , char * V_3 ,
char * V_4 )
{
int V_5 ;
int V_6 ;
T_1 * V_7 ;
V_5 = F_2 ( & V_4 ) ;
if( ( V_6 = F_3 ( & V_4 ) ) )
return F_4 ( V_3 , V_4 , V_5 , V_6 ) ;
V_7 = F_5 ( V_1 , V_2 , F_6 ( V_3 ) , V_5 , V_4 ) ;
if( ! V_7 ) {
F_7 ( V_8 , V_9 ) ;
F_8 ( 4 , L_1 , V_3 , L_2 , V_4 ) ;
}
return V_7 ;
}
T_1 * F_9 ( T_2 * V_1 , T_3 * V_2 , int V_10 ,
char * V_4 )
{
int V_5 ;
int V_6 ;
V_5 = F_2 ( & V_4 ) ;
if( ( V_6 = F_3 ( & V_4 ) ) )
return F_4 ( F_10 ( V_10 ) ,
V_4 , V_5 , V_6 ) ;
return F_5 ( V_1 , V_2 , V_10 , V_5 , V_4 ) ;
}
static T_1 * F_5 ( T_2 * V_1 , T_3 * V_2 , int V_10 ,
int V_5 , char * V_4 )
{
T_4 * V_11 ;
T_1 * V_12 ;
T_5 * V_13 ;
void * V_14 ;
if( V_10 == V_15 ) {
F_7 ( V_16 , V_17 ) ;
return NULL ;
}
if( ! ( V_11 = F_11 ( V_10 ) ) ) {
F_7 ( V_16 , V_18 ) ;
return NULL ;
}
if( V_11 -> V_19 ) {
if( * V_4 == '@' ) V_13 = F_12 ( V_1 , V_4 + 1 ) ;
else V_13 = F_13 ( V_4 ) ;
if( ! V_13 ) {
F_7 ( V_8 , V_20 ) ;
F_8 ( 4 , L_1 , F_10 ( V_10 ) , L_3 , V_4 ) ;
return NULL ;
}
V_14 = V_11 -> V_19 ( V_11 , V_2 , V_13 ) ;
if( * V_4 != '@' ) F_14 ( V_13 , V_21 ) ;
if( ! V_14 ) return NULL ;
} else if( V_11 -> V_22 ) {
if( ! ( V_14 = V_11 -> V_22 ( V_11 , V_2 , V_4 ) ) ) return NULL ;
} else if( V_11 -> V_23 ) {
if( ! V_2 -> V_24 ) {
F_7 ( V_8 , V_25 ) ;
return NULL ;
}
if( ! ( V_14 = V_11 -> V_23 ( V_11 , V_2 , V_4 ) ) ) return NULL ;
} else {
F_7 ( V_8 , V_26 ) ;
F_8 ( 2 , L_1 , F_10 ( V_10 ) ) ;
return NULL ;
}
V_12 = F_15 ( V_11 , V_10 , V_5 , V_14 ) ;
V_11 -> V_27 ( V_14 ) ;
return V_12 ;
}
static T_1 * F_15 ( T_4 * V_11 , int V_10 ,
int V_5 , void * V_14 )
{
unsigned char * V_28 , * V_29 ;
int V_30 ;
T_6 * V_31 ;
T_1 * V_12 ;
V_30 = V_11 -> V_32 ( V_14 , NULL ) ;
if( ! ( V_28 = Malloc ( V_30 ) ) ) goto V_33;
V_29 = V_28 ;
V_11 -> V_32 ( V_14 , & V_29 ) ;
if( ! ( V_31 = F_16 () ) ) goto V_33;
V_31 -> V_34 = V_28 ;
V_31 -> V_35 = V_30 ;
V_12 = F_17 ( NULL , V_10 , V_5 , V_31 ) ;
if( ! V_12 ) goto V_33;
F_18 ( V_31 ) ;
return V_12 ;
V_33:
F_7 ( V_36 , V_37 ) ;
return NULL ;
}
T_1 * F_19 ( int V_10 , int V_5 , void * V_14 )
{
T_4 * V_11 ;
if( ! ( V_11 = F_11 ( V_10 ) ) ) {
F_7 ( V_38 , V_18 ) ;
return NULL ;
}
return F_15 ( V_11 , V_10 , V_5 , V_14 ) ;
}
static int F_2 ( char * * V_4 )
{
char * V_29 = * V_4 ;
if( ( strlen ( V_29 ) < 9 ) || strncmp ( V_29 , L_4 , 9 ) ) return 0 ;
V_29 += 9 ;
while( isspace ( ( unsigned char ) * V_29 ) ) V_29 ++ ;
* V_4 = V_29 ;
return 1 ;
}
static int F_3 ( char * * V_4 )
{
char * V_29 = * V_4 ;
if( ( strlen ( V_29 ) < 4 ) || strncmp ( V_29 , L_5 , 4 ) ) return 0 ;
V_29 += 4 ;
while( isspace ( ( unsigned char ) * V_29 ) ) V_29 ++ ;
* V_4 = V_29 ;
return 1 ;
}
static T_1 * F_4 ( const char * V_12 , char * V_4 ,
int V_5 , int type )
{
unsigned char * V_28 = NULL ;
long V_30 ;
T_7 * V_39 = NULL ;
T_6 * V_40 = NULL ;
T_1 * V_41 = NULL ;
if( ! ( V_39 = F_20 ( V_12 , 0 ) ) ) {
F_7 ( V_42 , V_43 ) ;
F_8 ( 2 , L_1 , V_12 ) ;
goto V_44;
}
if( ! ( V_28 = F_21 ( V_4 , & V_30 ) ) ) {
F_7 ( V_42 , V_45 ) ;
F_8 ( 2 , L_6 , V_4 ) ;
goto V_44;
}
if( ! ( V_40 = F_16 () ) ) {
F_7 ( V_42 , V_37 ) ;
goto V_44;
}
V_40 -> V_34 = V_28 ;
V_40 -> V_35 = V_30 ;
V_28 = NULL ;
V_41 = F_22 ( NULL , V_39 , V_5 , V_40 ) ;
V_44:
F_23 ( V_39 ) ;
F_18 ( V_40 ) ;
if( V_28 ) Free ( V_28 ) ;
return V_41 ;
}
int F_24 ( T_2 * V_1 , T_3 * V_2 , char * V_46 ,
T_8 * V_47 )
{
T_1 * V_12 ;
T_5 * V_13 ;
T_9 * V_48 ;
int V_49 ;
if( ! ( V_13 = F_12 ( V_1 , V_46 ) ) ) return 0 ;
for( V_49 = 0 ; V_49 < F_25 ( V_13 ) ; V_49 ++ ) {
V_48 = ( T_9 * ) F_26 ( V_13 , V_49 ) ;
if( ! ( V_12 = F_1 ( V_1 , V_2 , V_48 -> V_3 , V_48 -> V_4 ) ) )
return 0 ;
if( V_47 ) F_27 ( V_47 , V_12 , - 1 ) ;
F_28 ( V_12 ) ;
}
return 1 ;
}
int F_29 ( T_2 * V_1 , T_3 * V_2 , char * V_46 ,
T_10 * V_50 )
{
T_1 * V_12 ;
T_5 * V_13 ;
T_9 * V_48 ;
int V_49 ;
if( ! ( V_13 = F_12 ( V_1 , V_46 ) ) ) return 0 ;
for( V_49 = 0 ; V_49 < F_25 ( V_13 ) ; V_49 ++ ) {
V_48 = ( T_9 * ) F_26 ( V_13 , V_49 ) ;
if( ! ( V_12 = F_1 ( V_1 , V_2 , V_48 -> V_3 , V_48 -> V_4 ) ) )
return 0 ;
if( V_50 ) F_30 ( V_50 , V_12 , - 1 ) ;
F_28 ( V_12 ) ;
}
return 1 ;
}
char * F_31 ( T_3 * V_2 , char * V_3 , char * V_46 )
{
if( V_2 -> V_51 -> V_52 )
return V_2 -> V_51 -> V_52 ( V_2 -> V_24 , V_3 , V_46 ) ;
return NULL ;
}
T_5 * F_32 ( T_3 * V_2 , char * V_46 )
{
if( V_2 -> V_51 -> V_53 )
return V_2 -> V_51 -> V_53 ( V_2 -> V_24 , V_46 ) ;
return NULL ;
}
void F_33 ( T_3 * V_2 , char * V_54 )
{
if( ! V_54 ) return;
if( V_2 -> V_51 -> V_55 )
V_2 -> V_51 -> V_55 ( V_2 -> V_24 , V_54 ) ;
}
void F_34 ( T_3 * V_2 , T_5 * V_46 )
{
if( ! V_46 ) return;
if( V_2 -> V_51 -> V_56 )
V_2 -> V_51 -> V_56 ( V_2 -> V_24 , V_46 ) ;
}
static char * F_35 ( void * V_24 , char * V_46 , char * V_4 )
{
return F_36 ( V_24 , V_46 , V_4 ) ;
}
static T_5 * F_37 ( void * V_24 , char * V_46 )
{
return F_12 ( V_24 , V_46 ) ;
}
void F_38 ( T_3 * V_2 , T_2 * V_57 )
{
V_2 -> V_51 = & V_58 ;
V_2 -> V_24 = V_57 ;
}
void F_39 ( T_3 * V_2 , T_8 * V_59 , T_8 * V_60 , T_11 * V_61 ,
T_10 * V_50 , int V_62 )
{
V_2 -> V_63 = V_59 ;
V_2 -> V_64 = V_60 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_65 = V_61 ;
V_2 -> V_62 = V_62 ;
}
