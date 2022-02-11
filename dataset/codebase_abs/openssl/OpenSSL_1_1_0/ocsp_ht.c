T_1 * F_1 ( T_2 * V_1 , int V_2 )
{
T_1 * V_3 = F_2 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL )
return NULL ;
V_3 -> V_4 = V_5 ;
V_3 -> V_6 = V_7 ;
V_3 -> V_8 = F_3 ( F_4 () ) ;
V_3 -> V_1 = V_1 ;
if ( V_2 > 0 )
V_3 -> V_9 = V_2 ;
else
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = F_5 ( V_3 -> V_9 ) ;
if ( V_3 -> V_11 == NULL || V_3 -> V_8 == NULL ) {
F_6 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
void F_6 ( T_1 * V_3 )
{
if ( ! V_3 )
return;
F_7 ( V_3 -> V_8 ) ;
F_8 ( V_3 -> V_11 ) ;
F_8 ( V_3 ) ;
}
T_2 * F_9 ( T_1 * V_3 )
{
return V_3 -> V_8 ;
}
void F_10 ( T_1 * V_3 , unsigned long V_12 )
{
if ( V_12 == 0 )
V_3 -> V_6 = V_7 ;
else
V_3 -> V_6 = V_12 ;
}
int F_11 ( T_1 * V_3 , const T_3 * V_13 , T_4 * V_14 )
{
static const char V_15 [] =
L_1
L_2 ;
int V_16 = F_12 ( V_14 , NULL , V_13 ) ;
if ( F_13 ( V_3 -> V_8 , V_15 , V_16 ) <= 0 )
return 0 ;
if ( F_14 ( V_13 , V_3 -> V_8 , V_14 ) <= 0 )
return 0 ;
V_3 -> V_4 = V_17 ;
return 1 ;
}
int F_15 ( T_1 * V_3 ,
T_4 * * V_18 , const T_3 * V_13 )
{
int V_19 , V_12 ;
const unsigned char * V_20 ;
V_19 = F_16 ( V_3 ) ;
if ( V_19 != 1 )
return V_19 ;
V_12 = F_17 ( V_3 -> V_8 , & V_20 ) ;
* V_18 = F_18 ( NULL , & V_20 , V_12 , V_13 ) ;
if ( * V_18 == NULL ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
return 1 ;
}
int F_19 ( T_1 * V_3 , const char * V_21 , const char * V_22 )
{
static const char V_23 [] = L_3 ;
if ( ! V_22 )
V_22 = L_4 ;
if ( F_13 ( V_3 -> V_8 , V_23 , V_21 , V_22 ) <= 0 )
return 0 ;
V_3 -> V_4 = V_24 ;
return 1 ;
}
int F_20 ( T_1 * V_3 , T_5 * V_25 )
{
return F_11 ( V_3 , F_21 ( T_5 ) ,
( T_4 * ) V_25 ) ;
}
int F_22 ( T_1 * V_3 ,
const char * V_26 , const char * V_27 )
{
if ( ! V_26 )
return 0 ;
if ( F_23 ( V_3 -> V_8 , V_26 ) <= 0 )
return 0 ;
if ( V_27 ) {
if ( F_24 ( V_3 -> V_8 , L_5 , 2 ) != 2 )
return 0 ;
if ( F_23 ( V_3 -> V_8 , V_27 ) <= 0 )
return 0 ;
}
if ( F_24 ( V_3 -> V_8 , L_6 , 2 ) != 2 )
return 0 ;
V_3 -> V_4 = V_24 ;
return 1 ;
}
T_1 * F_25 ( T_2 * V_1 , const char * V_22 , T_5 * V_25 ,
int V_2 )
{
T_1 * V_3 = NULL ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
if ( ! F_19 ( V_3 , L_7 , V_22 ) )
goto V_28;
if ( V_25 && ! F_20 ( V_3 , V_25 ) )
goto V_28;
return V_3 ;
V_28:
F_6 ( V_3 ) ;
return NULL ;
}
static int F_26 ( char * line )
{
int V_29 ;
char * V_20 , * V_30 , * V_31 ;
for ( V_20 = line ; * V_20 && ! isspace ( ( unsigned char ) * V_20 ) ; V_20 ++ )
continue;
if ( ! * V_20 ) {
F_27 ( V_32 , V_33 ) ;
return 0 ;
}
while ( * V_20 && isspace ( ( unsigned char ) * V_20 ) )
V_20 ++ ;
if ( ! * V_20 ) {
F_27 ( V_32 , V_33 ) ;
return 0 ;
}
for ( V_30 = V_20 ; * V_30 && ! isspace ( ( unsigned char ) * V_30 ) ; V_30 ++ )
continue;
if ( ! * V_30 ) {
F_27 ( V_32 , V_33 ) ;
return 0 ;
}
* V_30 ++ = 0 ;
V_29 = strtoul ( V_20 , & V_31 , 10 ) ;
if ( * V_31 )
return 0 ;
while ( * V_30 && isspace ( ( unsigned char ) * V_30 ) )
V_30 ++ ;
if ( * V_30 ) {
for ( V_31 = V_30 + strlen ( V_30 ) - 1 ; isspace ( ( unsigned char ) * V_31 ) ; V_31 -- )
* V_31 = 0 ;
}
if ( V_29 != 200 ) {
F_27 ( V_32 , V_34 ) ;
if ( ! * V_30 )
F_28 ( 2 , L_8 , V_20 ) ;
else
F_28 ( 4 , L_8 , V_20 , L_9 , V_30 ) ;
return 0 ;
}
return 1 ;
}
int F_16 ( T_1 * V_3 )
{
int V_35 , V_36 ;
const unsigned char * V_20 ;
V_37:
if ( ! ( V_3 -> V_4 & V_38 ) ) {
V_36 = F_29 ( V_3 -> V_1 , V_3 -> V_11 , V_3 -> V_9 ) ;
if ( V_36 <= 0 ) {
if ( F_30 ( V_3 -> V_1 ) )
return - 1 ;
return 0 ;
}
if ( F_24 ( V_3 -> V_8 , V_3 -> V_11 , V_36 ) != V_36 )
return 0 ;
}
switch ( V_3 -> V_4 ) {
case V_24 :
if ( F_24 ( V_3 -> V_8 , L_6 , 2 ) != 2 ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
V_3 -> V_4 = V_17 ;
case V_17 :
V_3 -> V_39 = F_17 ( V_3 -> V_8 , NULL ) ;
V_3 -> V_4 = V_40 ;
case V_40 :
V_36 = F_17 ( V_3 -> V_8 , & V_20 ) ;
V_35 = F_24 ( V_3 -> V_1 , V_20 + ( V_36 - V_3 -> V_39 ) , V_3 -> V_39 ) ;
if ( V_35 <= 0 ) {
if ( F_30 ( V_3 -> V_1 ) )
return - 1 ;
V_3 -> V_4 = V_5 ;
return 0 ;
}
V_3 -> V_39 -= V_35 ;
if ( V_3 -> V_39 > 0 )
goto V_37;
V_3 -> V_4 = V_41 ;
( void ) F_31 ( V_3 -> V_8 ) ;
case V_41 :
V_35 = F_32 ( V_3 -> V_1 ) ;
if ( V_35 > 0 ) {
V_3 -> V_4 = V_42 ;
goto V_37;
}
if ( F_30 ( V_3 -> V_1 ) )
return - 1 ;
V_3 -> V_4 = V_5 ;
return 0 ;
case V_5 :
return 0 ;
case V_42 :
case V_43 :
V_44:
V_36 = F_17 ( V_3 -> V_8 , & V_20 ) ;
if ( ( V_36 <= 0 ) || ! memchr ( V_20 , '\n' , V_36 ) ) {
if ( V_36 >= V_3 -> V_9 ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
goto V_37;
}
V_36 = F_33 ( V_3 -> V_8 , ( char * ) V_3 -> V_11 , V_3 -> V_9 ) ;
if ( V_36 <= 0 ) {
if ( F_30 ( V_3 -> V_8 ) )
goto V_37;
V_3 -> V_4 = V_5 ;
return 0 ;
}
if ( V_36 == V_3 -> V_9 ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
if ( V_3 -> V_4 == V_42 ) {
if ( F_26 ( ( char * ) V_3 -> V_11 ) ) {
V_3 -> V_4 = V_43 ;
goto V_44;
} else {
V_3 -> V_4 = V_5 ;
return 0 ;
}
} else {
for ( V_20 = V_3 -> V_11 ; * V_20 ; V_20 ++ ) {
if ( ( * V_20 != '\r' ) && ( * V_20 != '\n' ) )
break;
}
if ( * V_20 )
goto V_44;
V_3 -> V_4 = V_45 ;
}
case V_45 :
V_36 = F_17 ( V_3 -> V_8 , & V_20 ) ;
if ( V_36 < 2 )
goto V_37;
if ( * V_20 ++ != ( V_46 | V_47 ) ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
if ( * V_20 & 0x80 ) {
if ( V_36 < 6 )
goto V_37;
V_36 = * V_20 & 0x7F ;
if ( ! V_36 || ( V_36 > 4 ) ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
V_20 ++ ;
V_3 -> V_39 = 0 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_3 -> V_39 <<= 8 ;
V_3 -> V_39 |= * V_20 ++ ;
}
if ( V_3 -> V_39 > V_3 -> V_6 ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
V_3 -> V_39 += V_36 + 2 ;
} else
V_3 -> V_39 = * V_20 + 2 ;
V_3 -> V_4 = V_48 ;
case V_48 :
V_36 = F_17 ( V_3 -> V_8 , NULL ) ;
if ( V_36 < ( int ) V_3 -> V_39 )
goto V_37;
V_3 -> V_4 = V_49 ;
return 1 ;
case V_49 :
return 1 ;
}
return 0 ;
}
int F_34 ( T_6 * * V_50 , T_1 * V_3 )
{
return F_15 ( V_3 ,
( T_4 * * ) V_50 ,
F_21 ( T_6 ) ) ;
}
T_6 * F_35 ( T_2 * V_51 , const char * V_22 , T_5 * V_25 )
{
T_6 * V_52 = NULL ;
T_1 * V_53 ;
int V_19 ;
V_53 = F_25 ( V_51 , V_22 , V_25 , - 1 ) ;
if ( V_53 == NULL )
return NULL ;
do {
V_19 = F_34 ( & V_52 , V_53 ) ;
} while ( ( V_19 == - 1 ) && F_30 ( V_51 ) );
F_6 ( V_53 ) ;
if ( V_19 )
return V_52 ;
return NULL ;
}
