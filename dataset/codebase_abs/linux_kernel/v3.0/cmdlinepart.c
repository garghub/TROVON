static struct V_1 * F_1 ( char * V_2 ,
char * * V_3 ,
int * V_4 ,
int V_5 ,
unsigned char * * V_6 ,
int V_7 )
{
struct V_1 * V_8 ;
unsigned long V_9 ;
unsigned long V_10 = V_11 ;
char * V_12 ;
int V_13 ;
unsigned char * V_14 ;
char V_15 ;
unsigned int V_16 ;
if ( * V_2 == '-' )
{
V_9 = V_17 ;
V_2 ++ ;
}
else
{
V_9 = F_2 ( V_2 , & V_2 ) ;
if ( V_9 < V_18 )
{
F_3 (KERN_ERR ERRP L_1 , size) ;
return NULL ;
}
}
V_16 = 0 ;
V_15 = 0 ;
if ( * V_2 == '@' )
{
V_2 ++ ;
V_10 = F_2 ( V_2 , & V_2 ) ;
}
if ( * V_2 == '(' )
{
V_15 = ')' ;
}
if ( V_15 )
{
char * V_19 ;
V_12 = ++ V_2 ;
V_19 = strchr ( V_12 , V_15 ) ;
if ( ! V_19 )
{
F_3 (KERN_ERR ERRP L_2 , delim) ;
return NULL ;
}
V_13 = V_19 - V_12 ;
V_2 = V_19 + 1 ;
}
else
{
V_12 = NULL ;
V_13 = 13 ;
}
V_7 += V_13 + 1 ;
if ( strncmp ( V_2 , L_3 , 2 ) == 0 )
{
V_16 |= V_20 ;
V_2 += 2 ;
}
if ( strncmp ( V_2 , L_4 , 2 ) == 0 )
{
V_16 |= V_21 ;
V_2 += 2 ;
}
if ( * V_2 == ',' )
{
if ( V_9 == V_17 )
{
F_3 (KERN_ERR ERRP L_5 ) ;
return NULL ;
}
V_8 = F_1 ( V_2 + 1 , & V_2 , V_4 , V_5 + 1 ,
& V_14 , V_7 ) ;
if ( ! V_8 )
return NULL ;
}
else
{
int V_22 ;
* V_4 = V_5 + 1 ;
V_22 = * V_4 * sizeof( struct V_1 ) +
V_7 ;
V_8 = F_4 ( V_22 , V_23 ) ;
if ( ! V_8 )
{
F_3 (KERN_ERR ERRP L_6 ) ;
return NULL ;
}
V_14 = ( unsigned char * ) ( V_8 + * V_4 ) ;
}
V_8 [ V_5 ] . V_9 = V_9 ;
V_8 [ V_5 ] . V_10 = V_10 ;
V_8 [ V_5 ] . V_16 = V_16 ;
if ( V_12 )
{
F_5 ( V_14 , V_12 , V_13 + 1 ) ;
}
else
{
sprintf ( V_14 , L_7 , V_5 ) ;
}
V_8 [ V_5 ] . V_12 = V_14 ;
V_14 += V_13 + 1 ;
F_6 ( ( L_8 ,
V_5 ,
V_8 [ V_5 ] . V_12 ,
V_8 [ V_5 ] . V_10 ,
V_8 [ V_5 ] . V_9 ,
V_8 [ V_5 ] . V_16 ) ) ;
if ( V_6 )
* V_6 = V_14 ;
* V_3 = V_2 ;
return V_8 ;
}
static int F_7 ( char * V_2 )
{
V_24 = 1 ;
for( ; V_2 != NULL ; )
{
struct V_25 * V_26 ;
struct V_1 * V_8 ;
int V_27 ;
int V_4 ;
char * V_19 , * V_28 ;
V_28 = V_2 ;
if ( ! ( V_19 = strchr ( V_2 , ':' ) ) )
{
F_3 (KERN_ERR ERRP L_9 ) ;
return 0 ;
}
V_27 = V_19 - V_28 ;
F_6 ( ( L_10 , V_19 + 1 ) ) ;
V_8 = F_1 ( V_19 + 1 ,
& V_2 ,
& V_4 ,
0 ,
( unsigned char * * ) & V_26 ,
V_27 + 1 + sizeof( * V_26 ) +
sizeof( void * ) - 1 ) ;
if( ! V_8 )
{
return 0 ;
}
V_26 = (struct V_25 * )
F_8 ( ( unsigned long ) V_26 , sizeof( void * ) ) ;
V_26 -> V_8 = V_8 ;
V_26 -> V_4 = V_4 ;
V_26 -> V_28 = ( char * ) ( V_26 + 1 ) ;
F_5 ( V_26 -> V_28 , V_28 , V_27 + 1 ) ;
V_26 -> V_29 = V_30 ;
V_30 = V_26 ;
F_6 ( ( L_11 ,
V_26 -> V_28 , V_26 -> V_4 ) ) ;
if ( * V_2 == 0 )
break;
if ( * V_2 != ';' )
{
F_3 (KERN_ERR ERRP L_12 , *s) ;
return 0 ;
}
V_2 ++ ;
}
return 1 ;
}
static int F_9 ( struct V_31 * V_32 ,
struct V_1 * * V_33 ,
unsigned long V_34 )
{
unsigned long V_10 ;
int V_35 ;
struct V_25 * V_36 ;
const char * V_28 = V_32 -> V_12 ;
if ( ! V_24 )
F_7 ( V_37 ) ;
for( V_36 = V_30 ; V_36 ; V_36 = V_36 -> V_29 )
{
if ( ( ! V_28 ) || ( ! strcmp ( V_36 -> V_28 , V_28 ) ) )
{
for( V_35 = 0 , V_10 = 0 ; V_35 < V_36 -> V_4 ; V_35 ++ )
{
if ( V_36 -> V_8 [ V_35 ] . V_10 == V_11 )
V_36 -> V_8 [ V_35 ] . V_10 = V_10 ;
else
V_10 = V_36 -> V_8 [ V_35 ] . V_10 ;
if ( V_36 -> V_8 [ V_35 ] . V_9 == V_17 )
V_36 -> V_8 [ V_35 ] . V_9 = V_32 -> V_9 - V_10 ;
if ( V_10 + V_36 -> V_8 [ V_35 ] . V_9 > V_32 -> V_9 )
{
F_3 (KERN_WARNING ERRP
L_13 ,
part->mtd_id) ;
V_36 -> V_8 [ V_35 ] . V_9 = V_32 -> V_9 - V_10 ;
V_36 -> V_4 = V_35 ;
}
V_10 += V_36 -> V_8 [ V_35 ] . V_9 ;
}
* V_33 = F_10 ( V_36 -> V_8 ,
sizeof( * V_36 -> V_8 ) * V_36 -> V_4 ,
V_23 ) ;
if ( ! * V_33 )
return - V_38 ;
return V_36 -> V_4 ;
}
}
return 0 ;
}
static int F_11 ( char * V_2 )
{
V_37 = V_2 ;
return 1 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_39 ) ;
}
