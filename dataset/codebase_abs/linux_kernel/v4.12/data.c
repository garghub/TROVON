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
struct V_1 F_5 ( const char * V_16 , int V_13 )
{
int V_17 = 0 ;
struct V_1 V_2 ;
char * V_18 ;
V_2 = F_2 ( V_15 , V_13 + 1 ) ;
V_18 = V_2 . V_9 ;
while ( V_17 < V_13 ) {
char V_19 = V_16 [ V_17 ++ ] ;
if ( V_19 == '\\' )
V_19 = F_6 ( V_16 , & V_17 ) ;
V_18 [ V_2 . V_13 ++ ] = V_19 ;
}
V_18 [ V_2 . V_13 ++ ] = '\0' ;
return V_2 ;
}
struct V_1 F_7 ( T_1 * V_20 , T_2 V_21 )
{
struct V_1 V_2 = V_15 ;
while ( ! feof ( V_20 ) && ( V_2 . V_13 < V_21 ) ) {
T_2 V_22 , V_23 ;
if ( V_21 == - 1 )
V_22 = 4096 ;
else
V_22 = V_21 - V_2 . V_13 ;
V_2 = F_2 ( V_2 , V_22 ) ;
V_23 = fread ( V_2 . V_9 + V_2 . V_13 , 1 , V_22 , V_20 ) ;
if ( ferror ( V_20 ) )
F_8 ( L_1 , strerror ( V_24 ) ) ;
if ( V_2 . V_13 + V_23 < V_2 . V_13 )
F_8 ( L_2 ) ;
V_2 . V_13 += V_23 ;
}
return V_2 ;
}
struct V_1 F_9 ( struct V_1 V_2 , const void * V_25 , int V_13 )
{
V_2 = F_2 ( V_2 , V_13 ) ;
memcpy ( V_2 . V_9 + V_2 . V_13 , V_25 , V_13 ) ;
V_2 . V_13 += V_13 ;
return V_2 ;
}
struct V_1 F_10 ( struct V_1 V_2 , struct V_3 * V_4 ,
const void * V_25 , int V_13 )
{
V_2 = F_2 ( V_2 , V_13 ) ;
memmove ( V_2 . V_9 + V_4 -> V_26 + V_13 , V_2 . V_9 + V_4 -> V_26 , V_2 . V_13 - V_4 -> V_26 ) ;
memcpy ( V_2 . V_9 + V_4 -> V_26 , V_25 , V_13 ) ;
V_2 . V_13 += V_13 ;
V_4 = V_4 -> V_7 ;
F_11 (m)
V_4 -> V_26 += V_13 ;
return V_2 ;
}
static struct V_1 F_12 ( struct V_1 V_2 , struct V_3 * V_4 )
{
struct V_3 * * V_27 = & V_2 . V_6 ;
while ( * V_27 )
V_27 = & ( ( * V_27 ) -> V_7 ) ;
* V_27 = V_4 ;
return V_2 ;
}
struct V_1 F_13 ( struct V_1 V_28 , struct V_1 V_29 )
{
struct V_1 V_2 ;
struct V_3 * V_30 = V_29 . V_6 ;
V_2 = F_12 ( F_9 ( V_28 , V_29 . V_9 , V_29 . V_13 ) , V_30 ) ;
F_11 (m2)
V_30 -> V_26 += V_28 . V_13 ;
V_29 . V_6 = NULL ;
F_1 ( V_29 ) ;
return V_2 ;
}
struct V_1 F_14 ( struct V_1 V_2 , T_3 V_31 , int V_32 )
{
T_4 V_33 ;
T_5 V_34 ;
T_6 V_35 ;
T_7 V_36 ;
switch ( V_32 ) {
case 8 :
V_33 = V_31 ;
return F_9 ( V_2 , & V_33 , 1 ) ;
case 16 :
V_34 = F_15 ( V_31 ) ;
return F_9 ( V_2 , & V_34 , 2 ) ;
case 32 :
V_35 = F_16 ( V_31 ) ;
return F_9 ( V_2 , & V_35 , 4 ) ;
case 64 :
V_36 = F_17 ( V_31 ) ;
return F_9 ( V_2 , & V_36 , 8 ) ;
default:
F_8 ( L_3 , V_32 ) ;
}
}
struct V_1 F_18 ( struct V_1 V_2 , T_3 V_37 , T_3 V_38 )
{
struct V_39 V_40 ;
V_40 . V_37 = F_17 ( V_37 ) ;
V_40 . V_38 = F_17 ( V_38 ) ;
return F_9 ( V_2 , & V_40 , sizeof( V_40 ) ) ;
}
struct V_1 F_19 ( struct V_1 V_2 , T_8 V_41 )
{
return F_14 ( V_2 , V_41 , sizeof( V_41 ) * 8 ) ;
}
struct V_1 F_20 ( struct V_1 V_2 , T_3 V_42 )
{
return F_14 ( V_2 , V_42 , sizeof( V_42 ) * 8 ) ;
}
struct V_1 F_21 ( struct V_1 V_2 , T_4 V_43 )
{
return F_9 ( V_2 , & V_43 , 1 ) ;
}
struct V_1 F_22 ( struct V_1 V_2 , int V_13 )
{
V_2 = F_2 ( V_2 , V_13 ) ;
memset ( V_2 . V_9 + V_2 . V_13 , 0 , V_13 ) ;
V_2 . V_13 += V_13 ;
return V_2 ;
}
struct V_1 F_23 ( struct V_1 V_2 , int V_44 )
{
int V_45 = F_24 ( V_2 . V_13 , V_44 ) ;
return F_22 ( V_2 , V_45 - V_2 . V_13 ) ;
}
struct V_1 F_25 ( struct V_1 V_2 , enum V_46 type , char * V_8 )
{
struct V_3 * V_4 ;
V_4 = xmalloc ( sizeof( * V_4 ) ) ;
V_4 -> V_26 = V_2 . V_13 ;
V_4 -> type = type ;
V_4 -> V_8 = V_8 ;
V_4 -> V_7 = NULL ;
return F_12 ( V_2 , V_4 ) ;
}
bool F_26 ( struct V_1 V_2 )
{
int V_17 ;
int V_13 = V_2 . V_13 ;
if ( V_13 == 0 )
return false ;
for ( V_17 = 0 ; V_17 < V_13 - 1 ; V_17 ++ )
if ( V_2 . V_9 [ V_17 ] == '\0' )
return false ;
if ( V_2 . V_9 [ V_13 - 1 ] != '\0' )
return false ;
return true ;
}
