void F_1 ( struct V_1 V_2 )
{
struct V_3 * V_4 , * V_5 ;
V_4 = V_2 . V_6 ;
while ( V_4 ) {
V_5 = V_4 -> V_7 ;
free ( V_4 -> V_8 ) ;
free ( V_4 ) ;
V_4 = V_5 ;
}
if ( V_2 . V_9 )
free ( V_2 . V_9 ) ;
}
struct V_1 F_2 ( struct V_1 V_2 , int V_10 )
{
struct V_1 V_11 ;
int V_12 ;
if ( V_10 == 0 )
return V_2 ;
V_11 = V_2 ;
V_12 = V_10 ;
while ( ( V_2 . V_13 + V_10 ) > V_12 )
V_12 *= 2 ;
V_11 . V_9 = F_3 ( V_2 . V_9 , V_12 ) ;
return V_11 ;
}
struct V_1 F_4 ( const char * V_14 , int V_13 )
{
struct V_1 V_2 ;
V_2 = F_2 ( V_15 , V_13 ) ;
V_2 . V_13 = V_13 ;
memcpy ( V_2 . V_9 , V_14 , V_13 ) ;
return V_2 ;
}
static char F_5 ( const char * V_16 , int * V_17 )
{
char V_18 [ 4 ] ;
char * V_19 ;
long V_9 ;
V_18 [ 3 ] = '\0' ;
strncpy ( V_18 , V_16 + * V_17 , 3 ) ;
V_9 = strtol ( V_18 , & V_19 , 8 ) ;
assert ( V_19 > V_18 ) ;
( * V_17 ) += V_19 - V_18 ;
return V_9 ;
}
static char F_6 ( const char * V_16 , int * V_17 )
{
char V_18 [ 3 ] ;
char * V_19 ;
long V_9 ;
V_18 [ 2 ] = '\0' ;
strncpy ( V_18 , V_16 + * V_17 , 2 ) ;
V_9 = strtol ( V_18 , & V_19 , 16 ) ;
if ( ! ( V_19 > V_18 ) )
F_7 ( L_1 ) ;
( * V_17 ) += V_19 - V_18 ;
return V_9 ;
}
struct V_1 F_8 ( const char * V_16 , int V_13 )
{
int V_17 = 0 ;
struct V_1 V_2 ;
char * V_20 ;
V_2 = F_2 ( V_15 , strlen ( V_16 ) + 1 ) ;
V_20 = V_2 . V_9 ;
while ( V_17 < V_13 ) {
char V_21 = V_16 [ V_17 ++ ] ;
if ( V_21 != '\\' ) {
V_20 [ V_2 . V_13 ++ ] = V_21 ;
continue;
}
V_21 = V_16 [ V_17 ++ ] ;
assert ( V_21 ) ;
switch ( V_21 ) {
case 'a' :
V_20 [ V_2 . V_13 ++ ] = '\a' ;
break;
case 'b' :
V_20 [ V_2 . V_13 ++ ] = '\b' ;
break;
case 't' :
V_20 [ V_2 . V_13 ++ ] = '\t' ;
break;
case 'n' :
V_20 [ V_2 . V_13 ++ ] = '\n' ;
break;
case 'v' :
V_20 [ V_2 . V_13 ++ ] = '\v' ;
break;
case 'f' :
V_20 [ V_2 . V_13 ++ ] = '\f' ;
break;
case 'r' :
V_20 [ V_2 . V_13 ++ ] = '\r' ;
break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
V_17 -- ;
V_20 [ V_2 . V_13 ++ ] = F_5 ( V_16 , & V_17 ) ;
break;
case 'x' :
V_20 [ V_2 . V_13 ++ ] = F_6 ( V_16 , & V_17 ) ;
break;
default:
V_20 [ V_2 . V_13 ++ ] = V_21 ;
}
}
V_20 [ V_2 . V_13 ++ ] = '\0' ;
return V_2 ;
}
struct V_1 F_9 ( T_1 * V_22 , T_2 V_23 )
{
struct V_1 V_2 = V_15 ;
while ( ! feof ( V_22 ) && ( V_2 . V_13 < V_23 ) ) {
T_2 V_24 , V_25 ;
if ( V_23 == - 1 )
V_24 = 4096 ;
else
V_24 = V_23 - V_2 . V_13 ;
V_2 = F_2 ( V_2 , V_24 ) ;
V_25 = fread ( V_2 . V_9 + V_2 . V_13 , 1 , V_24 , V_22 ) ;
if ( ferror ( V_22 ) )
F_7 ( L_2 , strerror ( V_26 ) ) ;
if ( V_2 . V_13 + V_25 < V_2 . V_13 )
F_7 ( L_3 ) ;
V_2 . V_13 += V_25 ;
}
return V_2 ;
}
struct V_1 F_10 ( struct V_1 V_2 , const void * V_27 , int V_13 )
{
V_2 = F_2 ( V_2 , V_13 ) ;
memcpy ( V_2 . V_9 + V_2 . V_13 , V_27 , V_13 ) ;
V_2 . V_13 += V_13 ;
return V_2 ;
}
struct V_1 F_11 ( struct V_1 V_2 , struct V_3 * V_4 ,
const void * V_27 , int V_13 )
{
V_2 = F_2 ( V_2 , V_13 ) ;
memmove ( V_2 . V_9 + V_4 -> V_28 + V_13 , V_2 . V_9 + V_4 -> V_28 , V_2 . V_13 - V_4 -> V_28 ) ;
memcpy ( V_2 . V_9 + V_4 -> V_28 , V_27 , V_13 ) ;
V_2 . V_13 += V_13 ;
V_4 = V_4 -> V_7 ;
F_12 (m)
V_4 -> V_28 += V_13 ;
return V_2 ;
}
static struct V_1 F_13 ( struct V_1 V_2 , struct V_3 * V_4 )
{
struct V_3 * * V_29 = & V_2 . V_6 ;
while ( * V_29 )
V_29 = & ( ( * V_29 ) -> V_7 ) ;
* V_29 = V_4 ;
return V_2 ;
}
struct V_1 F_14 ( struct V_1 V_30 , struct V_1 V_31 )
{
struct V_1 V_2 ;
struct V_3 * V_32 = V_31 . V_6 ;
V_2 = F_13 ( F_10 ( V_30 , V_31 . V_9 , V_31 . V_13 ) , V_32 ) ;
F_12 (m2)
V_32 -> V_28 += V_30 . V_13 ;
V_31 . V_6 = NULL ;
F_1 ( V_31 ) ;
return V_2 ;
}
struct V_1 F_15 ( struct V_1 V_2 , T_3 V_33 )
{
T_3 V_34 = F_16 ( V_33 ) ;
return F_10 ( V_2 , & V_34 , sizeof( V_34 ) ) ;
}
struct V_1 F_17 ( struct V_1 V_2 , const struct V_35 * V_36 )
{
struct V_35 V_37 ;
V_37 . V_38 = F_18 ( V_36 -> V_38 ) ;
V_37 . V_39 = F_18 ( V_36 -> V_39 ) ;
return F_10 ( V_2 , & V_37 , sizeof( V_37 ) ) ;
}
struct V_1 F_19 ( struct V_1 V_2 , T_4 V_40 )
{
T_4 V_41 = F_18 ( V_40 ) ;
return F_10 ( V_2 , & V_41 , sizeof( V_41 ) ) ;
}
struct V_1 F_20 ( struct V_1 V_2 , T_5 V_42 )
{
return F_10 ( V_2 , & V_42 , 1 ) ;
}
struct V_1 F_21 ( struct V_1 V_2 , int V_13 )
{
V_2 = F_2 ( V_2 , V_13 ) ;
memset ( V_2 . V_9 + V_2 . V_13 , 0 , V_13 ) ;
V_2 . V_13 += V_13 ;
return V_2 ;
}
struct V_1 F_22 ( struct V_1 V_2 , int V_43 )
{
int V_44 = F_23 ( V_2 . V_13 , V_43 ) ;
return F_21 ( V_2 , V_44 - V_2 . V_13 ) ;
}
struct V_1 F_24 ( struct V_1 V_2 , enum V_45 type , char * V_8 )
{
struct V_3 * V_4 ;
V_4 = xmalloc ( sizeof( * V_4 ) ) ;
V_4 -> V_28 = V_2 . V_13 ;
V_4 -> type = type ;
V_4 -> V_8 = V_8 ;
V_4 -> V_7 = NULL ;
return F_13 ( V_2 , V_4 ) ;
}
int F_25 ( struct V_1 V_2 )
{
int V_17 ;
int V_13 = V_2 . V_13 ;
if ( V_13 == 0 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_13 - 1 ; V_17 ++ )
if ( V_2 . V_9 [ V_17 ] == '\0' )
return 0 ;
if ( V_2 . V_9 [ V_13 - 1 ] != '\0' )
return 0 ;
return 1 ;
}
