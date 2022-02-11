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
F_11 ( V_13 ) * V_14 ;
void * V_15 ;
if( V_10 == V_16 ) {
F_7 ( V_17 , V_18 ) ;
return NULL ;
}
if( ! ( V_11 = F_12 ( V_10 ) ) ) {
F_7 ( V_17 , V_19 ) ;
return NULL ;
}
if( V_11 -> V_20 ) {
if( * V_4 == '@' ) V_14 = F_13 ( V_1 , V_4 + 1 ) ;
else V_14 = F_14 ( V_4 ) ;
if( ! V_14 ) {
F_7 ( V_8 , V_21 ) ;
F_8 ( 4 , L_1 , F_10 ( V_10 ) , L_3 , V_4 ) ;
return NULL ;
}
V_15 = V_11 -> V_20 ( V_11 , V_2 , V_14 ) ;
if( * V_4 != '@' ) F_15 ( V_14 ,
V_22 ) ;
if( ! V_15 ) return NULL ;
} else if( V_11 -> V_23 ) {
if( ! ( V_15 = V_11 -> V_23 ( V_11 , V_2 , V_4 ) ) ) return NULL ;
} else if( V_11 -> V_24 ) {
if( ! V_2 -> V_25 ) {
F_7 ( V_8 , V_26 ) ;
return NULL ;
}
if( ! ( V_15 = V_11 -> V_24 ( V_11 , V_2 , V_4 ) ) ) return NULL ;
} else {
F_7 ( V_8 , V_27 ) ;
F_8 ( 2 , L_1 , F_10 ( V_10 ) ) ;
return NULL ;
}
V_12 = F_16 ( V_11 , V_10 , V_5 , V_15 ) ;
V_11 -> V_28 ( V_15 ) ;
return V_12 ;
}
static T_1 * F_16 ( T_4 * V_11 , int V_10 ,
int V_5 , void * V_15 )
{
unsigned char * V_29 , * V_30 ;
int V_31 ;
T_5 * V_32 ;
T_1 * V_12 ;
V_31 = V_11 -> V_33 ( V_15 , NULL ) ;
if( ! ( V_29 = Malloc ( V_31 ) ) ) goto V_34;
V_30 = V_29 ;
V_11 -> V_33 ( V_15 , & V_30 ) ;
if( ! ( V_32 = F_17 () ) ) goto V_34;
V_32 -> V_35 = V_29 ;
V_32 -> V_36 = V_31 ;
V_12 = F_18 ( NULL , V_10 , V_5 , V_32 ) ;
if( ! V_12 ) goto V_34;
F_19 ( V_32 ) ;
return V_12 ;
V_34:
F_7 ( V_37 , V_38 ) ;
return NULL ;
}
T_1 * F_20 ( int V_10 , int V_5 , void * V_15 )
{
T_4 * V_11 ;
if( ! ( V_11 = F_12 ( V_10 ) ) ) {
F_7 ( V_39 , V_19 ) ;
return NULL ;
}
return F_16 ( V_11 , V_10 , V_5 , V_15 ) ;
}
static int F_2 ( char * * V_4 )
{
char * V_30 = * V_4 ;
if( ( strlen ( V_30 ) < 9 ) || strncmp ( V_30 , L_4 , 9 ) ) return 0 ;
V_30 += 9 ;
while( isspace ( ( unsigned char ) * V_30 ) ) V_30 ++ ;
* V_4 = V_30 ;
return 1 ;
}
static int F_3 ( char * * V_4 )
{
char * V_30 = * V_4 ;
if( ( strlen ( V_30 ) < 4 ) || strncmp ( V_30 , L_5 , 4 ) ) return 0 ;
V_30 += 4 ;
while( isspace ( ( unsigned char ) * V_30 ) ) V_30 ++ ;
* V_4 = V_30 ;
return 1 ;
}
static T_1 * F_4 ( const char * V_12 , char * V_4 ,
int V_5 , int type )
{
unsigned char * V_29 = NULL ;
long V_31 ;
T_6 * V_40 = NULL ;
T_5 * V_41 = NULL ;
T_1 * V_42 = NULL ;
if( ! ( V_40 = F_21 ( V_12 , 0 ) ) ) {
F_7 ( V_43 , V_44 ) ;
F_8 ( 2 , L_1 , V_12 ) ;
goto V_45;
}
if( ! ( V_29 = F_22 ( V_4 , & V_31 ) ) ) {
F_7 ( V_43 , V_46 ) ;
F_8 ( 2 , L_6 , V_4 ) ;
goto V_45;
}
if( ! ( V_41 = F_17 () ) ) {
F_7 ( V_43 , V_38 ) ;
goto V_45;
}
V_41 -> V_35 = V_29 ;
V_41 -> V_36 = V_31 ;
V_29 = NULL ;
V_42 = F_23 ( NULL , V_40 , V_5 , V_41 ) ;
V_45:
F_24 ( V_40 ) ;
F_19 ( V_41 ) ;
if( V_29 ) Free ( V_29 ) ;
return V_42 ;
}
int F_25 ( T_2 * V_1 , T_3 * V_2 , char * V_47 ,
T_7 * V_48 )
{
T_1 * V_12 ;
F_11 ( V_13 ) * V_14 ;
V_13 * V_49 ;
int V_50 ;
if( ! ( V_14 = F_13 ( V_1 , V_47 ) ) ) return 0 ;
for( V_50 = 0 ; V_50 < F_26 ( V_14 ) ; V_50 ++ ) {
V_49 = F_27 ( V_14 , V_50 ) ;
if( ! ( V_12 = F_1 ( V_1 , V_2 , V_49 -> V_3 , V_49 -> V_4 ) ) )
return 0 ;
if( V_48 ) F_28 ( V_48 , V_12 , - 1 ) ;
F_29 ( V_12 ) ;
}
return 1 ;
}
int F_30 ( T_2 * V_1 , T_3 * V_2 , char * V_47 ,
T_8 * V_51 )
{
T_1 * V_12 ;
F_11 ( V_13 ) * V_14 ;
V_13 * V_49 ;
int V_50 ;
if( ! ( V_14 = F_13 ( V_1 , V_47 ) ) ) return 0 ;
for( V_50 = 0 ; V_50 < F_26 ( V_14 ) ; V_50 ++ ) {
V_49 = F_27 ( V_14 , V_50 ) ;
if( ! ( V_12 = F_1 ( V_1 , V_2 , V_49 -> V_3 , V_49 -> V_4 ) ) )
return 0 ;
if( V_51 ) F_31 ( V_51 , V_12 , - 1 ) ;
F_29 ( V_12 ) ;
}
return 1 ;
}
char * F_32 ( T_3 * V_2 , char * V_3 , char * V_47 )
{
if( V_2 -> V_52 -> V_53 )
return V_2 -> V_52 -> V_53 ( V_2 -> V_25 , V_3 , V_47 ) ;
return NULL ;
}
static char * F_33 ( void * V_25 , char * V_47 , char * V_4 )
{
return F_34 ( V_25 , V_47 , V_4 ) ;
}
void F_35 ( T_3 * V_2 , T_2 * V_54 )
{
V_2 -> V_52 = & V_55 ;
V_2 -> V_25 = V_54 ;
}
void F_36 ( T_3 * V_2 , T_7 * V_56 , T_7 * V_57 , T_9 * V_58 ,
T_8 * V_51 , int V_59 )
{
V_2 -> V_60 = V_56 ;
V_2 -> V_61 = V_57 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_62 = V_58 ;
V_2 -> V_59 = V_59 ;
}
