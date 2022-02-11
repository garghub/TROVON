static int F_1 ( const void * V_1 , int V_2 ,
const char * V_3 , int V_4 )
{
const char * V_5 = F_2 ( V_1 , V_2 + V_6 , V_4 + 1 ) ;
if ( ! V_5 )
return 0 ;
if ( memcmp ( V_5 , V_3 , V_4 ) != 0 )
return 0 ;
if ( V_5 [ V_4 ] == '\0' )
return 1 ;
else if ( ! memchr ( V_3 , '@' , V_4 ) && ( V_5 [ V_4 ] == '@' ) )
return 1 ;
else
return 0 ;
}
const char * F_3 ( const void * V_1 , int V_7 )
{
return ( const char * ) V_1 + F_4 ( V_1 ) + V_7 ;
}
int F_5 ( const void * V_1 , int V_8 , T_1 * V_9 , T_1 * V_10 )
{
F_6 ( V_1 ) ;
* V_9 = F_7 ( F_8 ( V_1 , V_8 ) -> V_9 ) ;
* V_10 = F_7 ( F_8 ( V_1 , V_8 ) -> V_10 ) ;
return 0 ;
}
int F_9 ( const void * V_1 )
{
int V_11 = 0 ;
while ( F_7 ( F_8 ( V_1 , V_11 ) -> V_10 ) != 0 )
V_11 ++ ;
return V_11 ;
}
int F_10 ( const void * V_1 , int V_2 ,
const char * V_12 , int V_13 )
{
int V_14 ;
F_6 ( V_1 ) ;
for ( V_14 = 0 , V_2 = F_11 ( V_1 , V_2 , & V_14 ) ;
( V_2 >= 0 ) && ( V_14 > 0 ) ;
V_2 = F_11 ( V_1 , V_2 , & V_14 ) ) {
if ( V_14 < 0 )
return - V_15 ;
else if ( ( V_14 == 1 )
&& F_1 ( V_1 , V_2 , V_12 , V_13 ) )
return V_2 ;
}
if ( V_2 < 0 )
return V_2 ;
else
return - V_15 ;
}
int F_12 ( const void * V_1 , int V_16 ,
const char * V_12 )
{
return F_10 ( V_1 , V_16 , V_12 , strlen ( V_12 ) ) ;
}
int F_13 ( const void * V_1 , const char * V_17 )
{
const char * V_18 = V_17 + strlen ( V_17 ) ;
const char * V_5 = V_17 ;
int V_2 = 0 ;
F_6 ( V_1 ) ;
if ( * V_17 != '/' )
return - V_19 ;
while ( * V_5 ) {
const char * V_20 ;
while ( * V_5 == '/' )
V_5 ++ ;
if ( ! * V_5 )
return V_2 ;
V_20 = strchr ( V_5 , '/' ) ;
if ( ! V_20 )
V_20 = V_18 ;
V_2 = F_10 ( V_1 , V_2 , V_5 , V_20 - V_5 ) ;
if ( V_2 < 0 )
return V_2 ;
V_5 = V_20 ;
}
return V_2 ;
}
const char * F_14 ( const void * V_1 , int V_21 , int * V_4 )
{
const struct V_22 * V_23 = F_15 ( V_1 , V_21 ) ;
int V_24 ;
if ( ( ( V_24 = F_16 ( V_1 ) ) != 0 )
|| ( ( V_24 = F_17 ( V_1 , V_21 ) ) < 0 ) )
goto V_25;
if ( V_4 )
* V_4 = strlen ( V_23 -> V_12 ) ;
return V_23 -> V_12 ;
V_25:
if ( V_4 )
* V_4 = V_24 ;
return NULL ;
}
const struct V_26 * F_18 ( const void * V_1 ,
int V_21 ,
const char * V_12 , int * V_27 )
{
T_2 V_28 ;
const struct V_26 * V_29 ;
int V_30 ;
int V_2 , V_31 ;
int V_24 ;
if ( ( ( V_24 = F_16 ( V_1 ) ) != 0 )
|| ( ( V_24 = F_17 ( V_1 , V_21 ) ) < 0 ) )
goto V_25;
V_31 = V_24 ;
do {
V_2 = V_31 ;
V_28 = F_19 ( V_1 , V_2 , & V_31 ) ;
switch ( V_28 ) {
case V_32 :
V_24 = - V_33 ;
goto V_25;
case V_34 :
case V_35 :
case V_36 :
break;
case V_37 :
V_24 = - V_38 ;
V_29 = F_2 ( V_1 , V_2 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
goto V_25;
V_30 = F_20 ( V_29 -> V_39 ) ;
if ( strcmp ( F_3 ( V_1 , V_30 ) , V_12 ) == 0 ) {
int V_4 = F_20 ( V_29 -> V_4 ) ;
V_29 = F_2 ( V_1 , V_2 ,
sizeof( * V_29 ) + V_4 ) ;
if ( ! V_29 )
goto V_25;
if ( V_27 )
* V_27 = V_4 ;
return V_29 ;
}
break;
default:
V_24 = - V_38 ;
goto V_25;
}
} while ( ( V_28 != V_34 ) && ( V_28 != V_35 ) );
V_24 = - V_15 ;
V_25:
if ( V_27 )
* V_27 = V_24 ;
return NULL ;
}
const void * F_21 ( const void * V_1 , int V_21 ,
const char * V_12 , int * V_27 )
{
const struct V_26 * V_29 ;
V_29 = F_18 ( V_1 , V_21 , V_12 , V_27 ) ;
if ( ! V_29 )
return NULL ;
return V_29 -> V_40 ;
}
T_2 F_22 ( const void * V_1 , int V_21 )
{
const T_2 * V_41 ;
int V_4 ;
V_41 = F_21 ( V_1 , V_21 , L_1 , & V_4 ) ;
if ( ! V_41 || ( V_4 != sizeof( * V_41 ) ) )
return 0 ;
return F_20 ( * V_41 ) ;
}
int F_23 ( const void * V_1 , int V_21 , char * V_42 , int V_43 )
{
int V_44 = 0 , V_5 = 0 ;
int V_2 , V_14 , V_13 ;
const char * V_12 ;
F_6 ( V_1 ) ;
if ( V_43 < 2 )
return - V_45 ;
for ( V_2 = 0 , V_14 = 0 ;
( V_2 >= 0 ) && ( V_2 <= V_21 ) ;
V_2 = F_11 ( V_1 , V_2 , & V_14 ) ) {
if ( V_44 < V_14 )
continue;
while ( V_44 > V_14 ) {
do {
V_5 -- ;
} while ( V_42 [ V_5 - 1 ] != '/' );
V_44 -- ;
}
V_12 = F_14 ( V_1 , V_2 , & V_13 ) ;
if ( ! V_12 )
return V_13 ;
if ( ( V_5 + V_13 + 1 ) <= V_43 ) {
memcpy ( V_42 + V_5 , V_12 , V_13 ) ;
V_5 += V_13 ;
V_42 [ V_5 ++ ] = '/' ;
V_44 ++ ;
}
if ( V_2 == V_21 ) {
if ( V_44 < ( V_14 + 1 ) )
return - V_45 ;
if ( V_5 > 1 )
V_5 -- ;
V_42 [ V_5 ] = '\0' ;
return V_5 ;
}
}
if ( ( V_2 == - V_15 ) || ( V_2 >= 0 ) )
return - V_46 ;
else if ( V_2 == - V_46 )
return - V_38 ;
return V_2 ;
}
int F_24 ( const void * V_1 , int V_21 ,
int V_47 , int * V_48 )
{
int V_2 , V_14 ;
int V_49 = - V_50 ;
F_6 ( V_1 ) ;
if ( V_47 < 0 )
return - V_15 ;
for ( V_2 = 0 , V_14 = 0 ;
( V_2 >= 0 ) && ( V_2 <= V_21 ) ;
V_2 = F_11 ( V_1 , V_2 , & V_14 ) ) {
if ( V_14 == V_47 )
V_49 = V_2 ;
if ( V_2 == V_21 ) {
if ( V_48 )
* V_48 = V_14 ;
if ( V_47 > V_14 )
return - V_15 ;
else
return V_49 ;
}
}
if ( ( V_2 == - V_15 ) || ( V_2 >= 0 ) )
return - V_46 ;
else if ( V_2 == - V_46 )
return - V_38 ;
return V_2 ;
}
int F_25 ( const void * V_1 , int V_21 )
{
int V_48 ;
int V_24 ;
V_24 = F_24 ( V_1 , V_21 , 0 , & V_48 ) ;
if ( V_24 )
return ( V_24 < 0 ) ? V_24 : - V_50 ;
return V_48 ;
}
int F_26 ( const void * V_1 , int V_21 )
{
int V_48 = F_25 ( V_1 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
return F_24 ( V_1 , V_21 ,
V_48 - 1 , NULL ) ;
}
int F_27 ( const void * V_1 , int V_51 ,
const char * V_52 ,
const void * V_53 , int V_54 )
{
int V_2 ;
const void * V_55 ;
int V_4 ;
F_6 ( V_1 ) ;
for ( V_2 = F_11 ( V_1 , V_51 , NULL ) ;
V_2 >= 0 ;
V_2 = F_11 ( V_1 , V_2 , NULL ) ) {
V_55 = F_21 ( V_1 , V_2 , V_52 , & V_4 ) ;
if ( V_55 && ( V_4 == V_54 )
&& ( memcmp ( V_55 , V_53 , V_4 ) == 0 ) )
return V_2 ;
}
return V_2 ;
}
int F_28 ( const void * V_1 , T_2 V_56 )
{
if ( ( V_56 == 0 ) || ( V_56 == - 1 ) )
return - V_57 ;
V_56 = F_29 ( V_56 ) ;
return F_27 ( V_1 , - 1 , L_1 ,
& V_56 , sizeof( V_56 ) ) ;
}
static int F_30 ( const char * V_58 , int V_59 , const char * V_60 )
{
int V_4 = strlen ( V_60 ) ;
const char * V_5 ;
while ( V_59 >= V_4 ) {
if ( memcmp ( V_60 , V_58 , V_4 + 1 ) == 0 )
return 1 ;
V_5 = memchr ( V_58 , '\0' , V_59 ) ;
if ( ! V_5 )
return 0 ;
V_59 -= ( V_5 - V_58 ) + 1 ;
V_58 = V_5 + 1 ;
}
return 0 ;
}
int F_31 ( const void * V_1 , int V_21 ,
const char * V_61 )
{
const void * V_29 ;
int V_4 ;
V_29 = F_21 ( V_1 , V_21 , L_2 , & V_4 ) ;
if ( ! V_29 )
return V_4 ;
if ( F_30 ( V_29 , V_4 , V_61 ) )
return 0 ;
else
return 1 ;
}
int F_32 ( const void * V_1 , int V_51 ,
const char * V_61 )
{
int V_2 , V_24 ;
F_6 ( V_1 ) ;
for ( V_2 = F_11 ( V_1 , V_51 , NULL ) ;
V_2 >= 0 ;
V_2 = F_11 ( V_1 , V_2 , NULL ) ) {
V_24 = F_31 ( V_1 , V_2 , V_61 ) ;
if ( ( V_24 < 0 ) && ( V_24 != - V_15 ) )
return V_24 ;
else if ( V_24 == 0 )
return V_2 ;
}
return V_2 ;
}
