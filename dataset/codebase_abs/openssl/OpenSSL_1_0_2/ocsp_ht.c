T_1 * F_1 ( T_2 * V_1 , int V_2 )
{
T_1 * V_3 ;
V_3 = F_2 ( sizeof( T_1 ) ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_4 = V_5 ;
V_3 -> V_6 = V_7 ;
V_3 -> V_8 = F_3 ( F_4 () ) ;
V_3 -> V_1 = V_1 ;
V_3 -> V_9 = 0 ;
if ( V_2 > 0 )
V_3 -> V_10 = V_2 ;
else
V_3 -> V_10 = V_11 ;
V_3 -> V_12 = F_2 ( V_3 -> V_10 ) ;
if ( ! V_3 -> V_12 || ! V_3 -> V_8 ) {
F_5 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
void F_5 ( T_1 * V_3 )
{
if ( V_3 -> V_8 )
F_6 ( V_3 -> V_8 ) ;
if ( V_3 -> V_12 )
F_7 ( V_3 -> V_12 ) ;
F_7 ( V_3 ) ;
}
T_2 * F_8 ( T_1 * V_3 )
{
return V_3 -> V_8 ;
}
void F_9 ( T_1 * V_3 , unsigned long V_13 )
{
if ( V_13 == 0 )
V_3 -> V_6 = V_7 ;
else
V_3 -> V_6 = V_13 ;
}
int F_10 ( T_1 * V_3 , const T_3 * V_14 , T_4 * V_15 )
{
static const char V_16 [] =
L_1
L_2 ;
int V_17 = F_11 ( V_15 , NULL , V_14 ) ;
if ( F_12 ( V_3 -> V_8 , V_16 , V_17 ) <= 0 )
return 0 ;
if ( F_13 ( V_14 , V_3 -> V_8 , V_15 ) <= 0 )
return 0 ;
V_3 -> V_4 = V_18 ;
return 1 ;
}
int F_14 ( T_1 * V_3 ,
T_4 * * V_19 , const T_3 * V_14 )
{
int V_20 , V_13 ;
const unsigned char * V_21 ;
V_20 = F_15 ( V_3 ) ;
if ( V_20 != 1 )
return V_20 ;
V_13 = F_16 ( V_3 -> V_8 , & V_21 ) ;
* V_19 = F_17 ( NULL , & V_21 , V_13 , V_14 ) ;
if ( * V_19 == NULL ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
return 1 ;
}
int F_18 ( T_1 * V_3 , const char * V_22 , const char * V_23 )
{
static const char V_24 [] = L_3 ;
if ( ! V_23 )
V_23 = L_4 ;
if ( F_12 ( V_3 -> V_8 , V_24 , V_22 , V_23 ) <= 0 )
return 0 ;
V_3 -> V_4 = V_25 ;
return 1 ;
}
int F_19 ( T_1 * V_3 , T_5 * V_26 )
{
return F_10 ( V_3 , F_20 ( T_5 ) ,
( T_4 * ) V_26 ) ;
}
int F_21 ( T_1 * V_3 ,
const char * V_27 , const char * V_28 )
{
if ( ! V_27 )
return 0 ;
if ( F_22 ( V_3 -> V_8 , V_27 ) <= 0 )
return 0 ;
if ( V_28 ) {
if ( F_23 ( V_3 -> V_8 , L_5 , 2 ) != 2 )
return 0 ;
if ( F_22 ( V_3 -> V_8 , V_28 ) <= 0 )
return 0 ;
}
if ( F_23 ( V_3 -> V_8 , L_6 , 2 ) != 2 )
return 0 ;
V_3 -> V_4 = V_25 ;
return 1 ;
}
T_1 * F_24 ( T_2 * V_1 , const char * V_23 , T_5 * V_26 ,
int V_2 )
{
T_1 * V_3 = NULL ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( ! V_3 )
return NULL ;
if ( ! F_18 ( V_3 , L_7 , V_23 ) )
goto V_29;
if ( V_26 && ! F_19 ( V_3 , V_26 ) )
goto V_29;
return V_3 ;
V_29:
F_5 ( V_3 ) ;
return NULL ;
}
static int F_25 ( char * line )
{
int V_30 ;
char * V_21 , * V_31 , * V_32 ;
for ( V_21 = line ; * V_21 && ! isspace ( ( unsigned char ) * V_21 ) ; V_21 ++ )
continue;
if ( ! * V_21 ) {
F_26 ( V_33 , V_34 ) ;
return 0 ;
}
while ( * V_21 && isspace ( ( unsigned char ) * V_21 ) )
V_21 ++ ;
if ( ! * V_21 ) {
F_26 ( V_33 , V_34 ) ;
return 0 ;
}
for ( V_31 = V_21 ; * V_31 && ! isspace ( ( unsigned char ) * V_31 ) ; V_31 ++ )
continue;
if ( ! * V_31 ) {
F_26 ( V_33 , V_34 ) ;
return 0 ;
}
* V_31 ++ = 0 ;
V_30 = strtoul ( V_21 , & V_32 , 10 ) ;
if ( * V_32 )
return 0 ;
while ( * V_31 && isspace ( ( unsigned char ) * V_31 ) )
V_31 ++ ;
if ( * V_31 ) {
for ( V_32 = V_31 + strlen ( V_31 ) - 1 ; isspace ( ( unsigned char ) * V_32 ) ; V_32 -- )
* V_32 = 0 ;
}
if ( V_30 != 200 ) {
F_26 ( V_33 , V_35 ) ;
if ( ! * V_31 )
F_27 ( 2 , L_8 , V_21 ) ;
else
F_27 ( 4 , L_8 , V_21 , L_9 , V_31 ) ;
return 0 ;
}
return 1 ;
}
int F_15 ( T_1 * V_3 )
{
int V_36 , V_37 ;
const unsigned char * V_21 ;
V_38:
if ( ! ( V_3 -> V_4 & V_39 ) ) {
V_37 = F_28 ( V_3 -> V_1 , V_3 -> V_12 , V_3 -> V_10 ) ;
if ( V_37 <= 0 ) {
if ( F_29 ( V_3 -> V_1 ) )
return - 1 ;
return 0 ;
}
if ( F_23 ( V_3 -> V_8 , V_3 -> V_12 , V_37 ) != V_37 )
return 0 ;
}
switch ( V_3 -> V_4 ) {
case V_25 :
if ( F_23 ( V_3 -> V_8 , L_6 , 2 ) != 2 ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
V_3 -> V_4 = V_18 ;
case V_18 :
V_3 -> V_9 = F_16 ( V_3 -> V_8 , NULL ) ;
V_3 -> V_4 = V_40 ;
case V_40 :
V_37 = F_16 ( V_3 -> V_8 , & V_21 ) ;
V_36 = F_23 ( V_3 -> V_1 , V_21 + ( V_37 - V_3 -> V_9 ) , V_3 -> V_9 ) ;
if ( V_36 <= 0 ) {
if ( F_29 ( V_3 -> V_1 ) )
return - 1 ;
V_3 -> V_4 = V_5 ;
return 0 ;
}
V_3 -> V_9 -= V_36 ;
if ( V_3 -> V_9 > 0 )
goto V_38;
V_3 -> V_4 = V_41 ;
( void ) F_30 ( V_3 -> V_8 ) ;
case V_41 :
V_36 = F_31 ( V_3 -> V_1 ) ;
if ( V_36 > 0 ) {
V_3 -> V_4 = V_42 ;
goto V_38;
}
if ( F_29 ( V_3 -> V_1 ) )
return - 1 ;
V_3 -> V_4 = V_5 ;
return 0 ;
case V_5 :
return 0 ;
case V_42 :
case V_43 :
V_44:
V_37 = F_16 ( V_3 -> V_8 , & V_21 ) ;
if ( ( V_37 <= 0 ) || ! memchr ( V_21 , '\n' , V_37 ) ) {
if ( V_37 >= V_3 -> V_10 ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
goto V_38;
}
V_37 = F_32 ( V_3 -> V_8 , ( char * ) V_3 -> V_12 , V_3 -> V_10 ) ;
if ( V_37 <= 0 ) {
if ( F_29 ( V_3 -> V_8 ) )
goto V_38;
V_3 -> V_4 = V_5 ;
return 0 ;
}
if ( V_37 == V_3 -> V_10 ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
if ( V_3 -> V_4 == V_42 ) {
if ( F_25 ( ( char * ) V_3 -> V_12 ) ) {
V_3 -> V_4 = V_43 ;
goto V_44;
} else {
V_3 -> V_4 = V_5 ;
return 0 ;
}
} else {
for ( V_21 = V_3 -> V_12 ; * V_21 ; V_21 ++ ) {
if ( ( * V_21 != '\r' ) && ( * V_21 != '\n' ) )
break;
}
if ( * V_21 )
goto V_44;
V_3 -> V_4 = V_45 ;
}
case V_45 :
V_37 = F_16 ( V_3 -> V_8 , & V_21 ) ;
if ( V_37 < 2 )
goto V_38;
if ( * V_21 ++ != ( V_46 | V_47 ) ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
if ( * V_21 & 0x80 ) {
if ( V_37 < 6 )
goto V_38;
V_37 = * V_21 & 0x7F ;
if ( ! V_37 || ( V_37 > 4 ) ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
V_21 ++ ;
V_3 -> V_9 = 0 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_3 -> V_9 <<= 8 ;
V_3 -> V_9 |= * V_21 ++ ;
}
if ( V_3 -> V_9 > V_3 -> V_6 ) {
V_3 -> V_4 = V_5 ;
return 0 ;
}
V_3 -> V_9 += V_37 + 2 ;
} else
V_3 -> V_9 = * V_21 + 2 ;
V_3 -> V_4 = V_48 ;
case V_48 :
V_37 = F_16 ( V_3 -> V_8 , NULL ) ;
if ( V_37 < ( int ) V_3 -> V_9 )
goto V_38;
V_3 -> V_4 = V_49 ;
return 1 ;
break;
case V_49 :
return 1 ;
}
return 0 ;
}
int F_33 ( T_6 * * V_50 , T_1 * V_3 )
{
return F_14 ( V_3 ,
( T_4 * * ) V_50 ,
F_20 ( T_6 ) ) ;
}
T_6 * F_34 ( T_2 * V_51 , const char * V_23 , T_5 * V_26 )
{
T_6 * V_52 = NULL ;
T_1 * V_53 ;
int V_20 ;
V_53 = F_24 ( V_51 , V_23 , V_26 , - 1 ) ;
if ( ! V_53 )
return NULL ;
do {
V_20 = F_33 ( & V_52 , V_53 ) ;
} while ( ( V_20 == - 1 ) && F_29 ( V_51 ) );
F_5 ( V_53 ) ;
if ( V_20 )
return V_52 ;
return NULL ;
}
