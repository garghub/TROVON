static T_1 F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
T_1 V_3 ;
F_2 ( & V_4 , V_2 ) ;
V_3 = V_5 -> V_6 ( V_1 ) ;
F_3 () ;
F_4 ( & V_4 , V_2 ) ;
return V_3 ;
}
T_1 F_5 ( T_1 V_1 )
{
T_1 V_3 ;
if ( ( V_7 ) V_1 == - 1 )
return 0 ;
V_3 = F_1 ( V_1 ) ;
if ( V_3 == 0 || ( V_7 ) V_3 == - 1 )
return 0 ;
return V_3 ;
}
static T_1 F_6 ( T_1 V_1 )
{
unsigned long V_2 ;
T_1 V_3 ;
F_2 ( & V_4 , V_2 ) ;
V_3 = V_5 -> V_8 ( V_1 ) ;
F_3 () ;
F_4 ( & V_4 , V_2 ) ;
return V_3 ;
}
T_1 F_7 ( T_1 V_1 )
{
T_1 V_9 ;
if ( ( V_7 ) V_1 == - 1 )
return 0 ;
V_9 = F_6 ( V_1 ) ;
if ( V_9 == 0 || ( V_7 ) V_9 == - 1 )
return 0 ;
return V_9 ;
}
int F_8 ( T_1 V_1 , const char * V_10 )
{
int V_11 ;
unsigned long V_2 ;
if( ( ! V_1 ) || ( ! V_10 ) )
return - 1 ;
F_2 ( & V_4 , V_2 ) ;
V_11 = V_5 -> V_12 ( V_1 , V_10 ) ;
F_3 () ;
F_4 ( & V_4 , V_2 ) ;
return V_11 ;
}
int F_9 ( T_1 V_1 , const char * V_10 , char * V_13 , int V_14 )
{
int V_15 , V_11 ;
unsigned long V_2 ;
V_15 = F_8 ( V_1 , V_10 ) ;
if( ( V_15 > V_14 ) || ( V_15 == 0 ) || ( V_15 == - 1 ) )
return - 1 ;
F_2 ( & V_4 , V_2 ) ;
V_11 = V_5 -> V_16 ( V_1 , V_10 , V_13 ) ;
F_3 () ;
F_4 ( & V_4 , V_2 ) ;
return V_11 ;
}
int F_10 ( T_1 V_1 , char * V_10 )
{
static int V_17 ;
if( F_9 ( V_1 , V_10 , ( char * ) & V_17 , sizeof( int ) ) != - 1 )
return V_17 ;
return - 1 ;
}
int F_11 ( T_1 V_1 , char * V_18 , int V_19 )
{
int V_20 ;
V_20 = F_10 ( V_1 , V_18 ) ;
if( V_20 == - 1 ) return V_19 ;
return V_20 ;
}
int F_12 ( T_1 V_1 , char * V_10 )
{
int V_20 ;
V_20 = F_8 ( V_1 , V_10 ) ;
if( V_20 == - 1 ) return 0 ;
return 1 ;
}
void F_13 ( T_1 V_1 , char * V_10 , char * V_21 , int V_22 )
{
int V_23 ;
V_23 = F_9 ( V_1 , V_10 , V_21 , V_22 ) ;
if( V_23 != - 1 ) return;
V_21 [ 0 ] = 0 ;
}
T_1 F_14 ( T_1 V_24 , char * V_25 )
{
T_1 V_26 ;
int error ;
for( V_26 = V_24 ; V_26 ;
V_26 = F_7 ( V_26 ) ) {
error = F_9 ( V_26 , L_1 , V_27 ,
sizeof( V_27 ) ) ;
if( error == - 1 ) continue;
if( strcmp ( V_25 , V_27 ) == 0 ) return V_26 ;
}
return 0 ;
}
static char * F_15 ( T_1 V_1 , char * V_28 )
{
unsigned long V_2 ;
char * V_10 ;
F_2 ( & V_4 , V_2 ) ;
V_10 = V_5 -> V_29 ( V_1 , V_28 ) ;
F_3 () ;
F_4 ( & V_4 , V_2 ) ;
return V_10 ;
}
char * F_16 ( T_1 V_1 , char * V_28 , char * V_13 )
{
if ( V_1 == 0 || ( V_7 ) V_1 == - 1 )
return L_2 ;
return F_15 ( V_1 , V_28 ) ;
}
T_1 F_17 ( char * V_30 )
{
char V_31 [ 128 ] ;
char * V_32 = V_30 , * V_33 ;
T_1 V_1 = V_34 , V_35 ;
unsigned int V_36 , V_37 ;
struct V_38 V_39 [ V_40 ] ;
while ( * V_32 ++ ) {
if ( ! * V_32 ) return V_1 ;
V_1 = F_5 ( V_1 ) ;
for ( V_33 = V_31 ; * V_32 != 0 && * V_32 != '@' && * V_32 != '/' ; )
* V_33 ++ = * V_32 ++ ;
* V_33 = 0 ;
V_1 = F_14 ( V_1 , V_31 ) ;
if ( ! V_1 )
return 0 ;
if ( * V_32 == '@' ) {
if ( isxdigit ( V_32 [ 1 ] ) && V_32 [ 2 ] == ',' ) {
V_36 = F_18 ( V_32 + 1 , NULL , 16 ) ;
V_37 = F_18 ( V_32 + 3 , & V_33 , 16 ) ;
if ( V_33 != V_32 + 3 && ( ! * V_33 || * V_33 == '/' )
&& V_33 <= V_32 + 3 + 8 ) {
V_35 = V_1 ;
while ( V_35 && ( V_7 ) V_35 != - 1 ) {
if ( F_9 ( V_35 , L_3 , ( char * ) V_39 , sizeof ( V_39 ) ) > 0 ) {
if ( V_36 == V_39 [ 0 ] . V_36 && V_37 == V_39 [ 0 ] . V_37 ) {
V_1 = V_35 ;
break;
}
}
V_35 = F_7 ( V_35 ) ;
if ( ! V_35 || ( V_7 ) V_35 == - 1 )
break;
V_35 = F_14 ( F_7 ( V_35 ) , V_31 ) ;
}
}
}
while ( * V_32 != 0 && * V_32 != '/' ) V_32 ++ ;
}
}
return V_1 ;
}
int F_19 ( T_1 V_1 , const char * V_41 , char * V_42 , int V_43 )
{
unsigned long V_2 ;
int V_11 ;
if ( V_43 == 0 )
return 0 ;
if ( ( V_41 == NULL ) || ( V_42 == NULL ) )
return 0 ;
F_2 ( & V_4 , V_2 ) ;
V_11 = V_5 -> V_44 ( V_1 , V_41 , V_42 , V_43 ) ;
F_3 () ;
F_4 ( & V_4 , V_2 ) ;
return V_11 ;
}
T_1 F_20 ( int V_45 )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_4 , V_2 ) ;
V_1 = (* V_46 -> V_47 . V_48 )( V_45 ) ;
F_3 () ;
F_4 ( & V_4 , V_2 ) ;
if ( ( V_7 ) V_1 == - 1 )
return 0 ;
return V_1 ;
}
