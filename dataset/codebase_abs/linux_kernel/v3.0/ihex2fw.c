static T_1 F_1 ( const T_1 V_1 )
{
if ( V_1 >= '0' && V_1 <= '9' ) return V_1 - '0' ;
else if ( V_1 >= 'A' && V_1 <= 'F' ) return V_1 - ( 'A' - 10 ) ;
else if ( V_1 >= 'a' && V_1 <= 'f' ) return V_1 - ( 'a' - 10 ) ;
return 0 ;
}
static T_1 F_2 ( const T_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 = ( F_1 ( V_2 [ 0 ] ) << 4 ) | F_1 ( V_2 [ 1 ] ) ;
* V_3 += V_4 ;
return V_4 ;
}
static int F_3 ( void )
{
fprintf ( V_5 , L_1
L_2 ) ;
fprintf ( V_5 , L_3 ) ;
fprintf ( V_5 , L_4 ) ;
fprintf ( V_5 , L_5 ) ;
fprintf ( V_5 , L_6 ) ;
return 1 ;
}
int main ( int V_6 , char * * V_7 )
{
int V_8 , V_9 ;
struct V_10 V_11 ;
T_1 * V_2 ;
int V_12 ;
while ( ( V_12 = F_4 ( V_6 , V_7 , L_7 ) ) != - 1 ) {
switch ( V_12 ) {
case 'w' :
V_13 = 1 ;
break;
case 's' :
V_14 = 1 ;
break;
case 'j' :
V_15 = 1 ;
break;
return F_3 () ;
}
}
if ( V_16 + 2 != V_6 )
return F_3 () ;
if ( ! strcmp ( V_7 [ V_16 ] , L_8 ) )
V_8 = 0 ;
else
V_8 = F_5 ( V_7 [ V_16 ] , V_17 ) ;
if ( V_8 == - 1 ) {
fprintf ( V_5 , L_9 ,
strerror ( V_18 ) ) ;
return F_3 () ;
}
if ( F_6 ( V_8 , & V_11 ) ) {
perror ( L_10 ) ;
return 1 ;
}
V_2 = F_7 ( NULL , V_11 . V_19 , V_20 , V_21 , V_8 , 0 ) ;
if ( V_2 == V_22 ) {
perror ( L_11 ) ;
return 1 ;
}
if ( ! strcmp ( V_7 [ V_16 + 1 ] , L_8 ) )
V_9 = 1 ;
else
V_9 = F_5 ( V_7 [ V_16 + 1 ] , V_23 | V_24 | V_25 , 0644 ) ;
if ( V_9 == - 1 ) {
fprintf ( V_5 , L_12 ,
strerror ( V_18 ) ) ;
return F_3 () ;
}
if ( F_8 ( V_2 , V_11 . V_19 ) )
return 1 ;
return F_9 ( V_9 ) ;
}
static int F_8 ( T_1 * V_2 , T_2 V_26 )
{
struct V_27 * V_28 ;
T_3 V_29 = 0 ;
T_3 V_30 ;
T_1 type , V_3 = 0 , V_31 = 0 ;
int V_32 , V_33 ;
int line = 1 ;
int V_34 ;
V_32 = 0 ;
V_35:
while ( V_32 < V_26 ) {
if ( V_2 [ V_32 ] == '\n' ) line ++ ;
if ( V_2 [ V_32 ++ ] == ':' ) break;
}
if ( V_32 + 10 > V_26 ) {
fprintf ( V_5 , L_13 , line ) ;
return - V_36 ;
}
V_34 = F_2 ( V_2 + V_32 , & V_3 ) ; V_32 += 2 ;
if ( V_13 ) {
V_34 <<= 8 ;
V_34 += F_2 ( V_2 + V_32 , & V_3 ) ; V_32 += 2 ;
}
V_28 = malloc ( ( sizeof ( * V_28 ) + V_34 + 3 ) & ~ 3 ) ;
if ( ! V_28 ) {
fprintf ( V_5 , L_14 ) ;
return - V_37 ;
}
memset ( V_28 , 0 , ( sizeof( * V_28 ) + V_34 + 3 ) & ~ 3 ) ;
V_28 -> V_34 = V_34 ;
if ( V_32 + 8 + ( V_28 -> V_34 * 2 ) > V_26 ) {
fprintf ( V_5 , L_15 ,
line ) ;
return - V_36 ;
}
V_28 -> V_38 = F_2 ( V_2 + V_32 , & V_3 ) << 8 ; V_32 += 2 ;
V_28 -> V_38 |= F_2 ( V_2 + V_32 , & V_3 ) ; V_32 += 2 ;
type = F_2 ( V_2 + V_32 , & V_3 ) ; V_32 += 2 ;
for ( V_33 = 0 ; V_33 < V_28 -> V_34 ; V_33 ++ , V_32 += 2 )
V_28 -> V_2 [ V_33 ] = F_2 ( V_2 + V_32 , & V_3 ) ;
V_31 = F_2 ( V_2 + V_32 , & V_3 ) ; V_32 += 2 ;
if ( V_3 != 0 ) {
fprintf ( V_5 , L_16 ,
line , V_31 , ( unsigned char ) ( V_31 - V_3 ) ) ;
return - V_36 ;
}
switch ( type ) {
case 0 :
if ( ! V_28 -> V_34 )
break;
V_28 -> V_38 += V_29 ;
F_10 ( V_28 ) ;
goto V_35;
case 1 :
if ( V_28 -> V_38 || V_28 -> V_34 ) {
fprintf ( V_5 , L_17 ,
line ) ;
return - V_36 ;
}
break;
case 2 :
case 4 :
if ( V_28 -> V_38 || V_28 -> V_34 != 2 ) {
fprintf ( V_5 , L_18 ,
type , line ) ;
return - V_36 ;
}
V_29 = V_28 -> V_2 [ 0 ] << 8 | V_28 -> V_2 [ 1 ] ;
V_29 <<= ( type == 2 ? 4 : 16 ) ;
goto V_35;
case 3 :
case 5 :
if ( V_28 -> V_38 || V_28 -> V_34 != 4 ) {
fprintf ( V_5 , L_19 ,
type , line ) ;
return - V_36 ;
}
memcpy ( & V_30 , & V_28 -> V_2 [ 0 ] , sizeof( V_30 ) ) ;
V_30 = F_11 ( V_30 ) ;
memcpy ( & V_28 -> V_2 [ 0 ] , & V_30 , sizeof( V_30 ) ) ;
if ( V_15 )
F_10 ( V_28 ) ;
goto V_35;
default:
fprintf ( V_5 , L_20 , type ) ;
return - V_36 ;
}
return 0 ;
}
static void F_10 ( struct V_27 * V_28 )
{
struct V_27 * * V_39 = & V_40 ;
while ( ( * V_39 ) && ( ! V_14 || ( * V_39 ) -> V_38 < V_28 -> V_38 ) )
V_39 = & ( ( * V_39 ) -> V_41 ) ;
V_28 -> V_41 = * V_39 ;
* V_39 = V_28 ;
}
static int F_9 ( int V_9 )
{
unsigned char V_42 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_27 * V_39 = V_40 ;
while ( V_39 ) {
T_4 V_43 = ( V_39 -> V_34 + 9 ) & ~ 3 ;
V_39 -> V_38 = F_11 ( V_39 -> V_38 ) ;
V_39 -> V_34 = F_12 ( V_39 -> V_34 ) ;
if ( F_13 ( V_9 , & V_39 -> V_38 , V_43 ) != V_43 )
return 1 ;
V_39 = V_39 -> V_41 ;
}
if ( F_13 ( V_9 , V_42 , 6 ) != 6 )
return 1 ;
return 0 ;
}
