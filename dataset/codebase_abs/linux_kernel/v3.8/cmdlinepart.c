static struct V_1 * F_1 ( char * V_2 ,
char * * V_3 ,
int * V_4 ,
int V_5 ,
unsigned char * * V_6 ,
int V_7 )
{
struct V_1 * V_8 ;
unsigned long long V_9 , V_10 = V_11 ;
char * V_12 ;
int V_13 ;
unsigned char * V_14 ;
char V_15 ;
unsigned int V_16 ;
if ( * V_2 == '-' ) {
V_9 = V_17 ;
V_2 ++ ;
} else {
V_9 = F_2 ( V_2 , & V_2 ) ;
if ( V_9 < V_18 ) {
F_3 (KERN_ERR ERRP L_1 ,
size) ;
return F_4 ( - V_19 ) ;
}
}
V_16 = 0 ;
V_15 = 0 ;
if ( * V_2 == '@' ) {
V_2 ++ ;
V_10 = F_2 ( V_2 , & V_2 ) ;
}
if ( * V_2 == '(' )
V_15 = ')' ;
if ( V_15 ) {
char * V_20 ;
V_12 = ++ V_2 ;
V_20 = strchr ( V_12 , V_15 ) ;
if ( ! V_20 ) {
F_3 (KERN_ERR ERRP L_2 , delim) ;
return F_4 ( - V_19 ) ;
}
V_13 = V_20 - V_12 ;
V_2 = V_20 + 1 ;
} else {
V_12 = NULL ;
V_13 = 13 ;
}
V_7 += V_13 + 1 ;
if ( strncmp ( V_2 , L_3 , 2 ) == 0 ) {
V_16 |= V_21 ;
V_2 += 2 ;
}
if ( strncmp ( V_2 , L_4 , 2 ) == 0 ) {
V_16 |= V_22 ;
V_2 += 2 ;
}
if ( * V_2 == ',' ) {
if ( V_9 == V_17 ) {
F_3 (KERN_ERR ERRP L_5 ) ;
return F_4 ( - V_19 ) ;
}
V_8 = F_1 ( V_2 + 1 , & V_2 , V_4 , V_5 + 1 ,
& V_14 , V_7 ) ;
if ( F_5 ( V_8 ) )
return V_8 ;
} else {
int V_23 ;
* V_4 = V_5 + 1 ;
V_23 = * V_4 * sizeof( struct V_1 ) +
V_7 ;
V_8 = F_6 ( V_23 , V_24 ) ;
if ( ! V_8 )
return F_4 ( - V_25 ) ;
V_14 = ( unsigned char * ) ( V_8 + * V_4 ) ;
}
V_8 [ V_5 ] . V_9 = V_9 ;
V_8 [ V_5 ] . V_10 = V_10 ;
V_8 [ V_5 ] . V_16 = V_16 ;
if ( V_12 )
F_7 ( V_14 , V_12 , V_13 + 1 ) ;
else
sprintf ( V_14 , L_6 , V_5 ) ;
V_8 [ V_5 ] . V_12 = V_14 ;
V_14 += V_13 + 1 ;
F_8 ( ( L_7 ,
V_5 , V_8 [ V_5 ] . V_12 , V_8 [ V_5 ] . V_10 ,
V_8 [ V_5 ] . V_9 , V_8 [ V_5 ] . V_16 ) ) ;
if ( V_6 )
* V_6 = V_14 ;
* V_3 = V_2 ;
return V_8 ;
}
static int F_9 ( char * V_2 )
{
V_26 = 1 ;
for( ; V_2 != NULL ; )
{
struct V_27 * V_28 ;
struct V_1 * V_8 ;
int V_29 , V_4 ;
char * V_20 , * V_30 ;
V_30 = V_2 ;
V_20 = strchr ( V_2 , ':' ) ;
if ( ! V_20 ) {
F_3 (KERN_ERR ERRP L_8 ) ;
return - V_19 ;
}
V_29 = V_20 - V_30 ;
F_8 ( ( L_9 , V_20 + 1 ) ) ;
V_8 = F_1 ( V_20 + 1 ,
& V_2 ,
& V_4 ,
0 ,
( unsigned char * * ) & V_28 ,
V_29 + 1 + sizeof( * V_28 ) +
sizeof( void * ) - 1 ) ;
if ( F_5 ( V_8 ) ) {
return F_10 ( V_8 ) ;
}
V_28 = (struct V_27 * )
F_11 ( ( unsigned long ) V_28 , sizeof( void * ) ) ;
V_28 -> V_8 = V_8 ;
V_28 -> V_4 = V_4 ;
V_28 -> V_30 = ( char * ) ( V_28 + 1 ) ;
F_7 ( V_28 -> V_30 , V_30 , V_29 + 1 ) ;
V_28 -> V_31 = V_32 ;
V_32 = V_28 ;
F_8 ( ( L_10 ,
V_28 -> V_30 , V_28 -> V_4 ) ) ;
if ( * V_2 == 0 )
break;
if ( * V_2 != ';' ) {
F_3 (KERN_ERR ERRP L_11 , *s) ;
return - V_19 ;
}
V_2 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_33 * V_34 ,
struct V_1 * * V_35 ,
struct V_36 * V_37 )
{
unsigned long long V_10 ;
int V_38 , V_39 ;
struct V_27 * V_40 ;
const char * V_30 = V_34 -> V_12 ;
if ( ! V_26 ) {
V_39 = F_9 ( V_41 ) ;
if ( V_39 )
return V_39 ;
}
for ( V_40 = V_32 ; V_40 ; V_40 = V_40 -> V_31 ) {
if ( ( ! V_30 ) || ( ! strcmp ( V_40 -> V_30 , V_30 ) ) )
break;
}
if ( ! V_40 )
return 0 ;
for ( V_38 = 0 , V_10 = 0 ; V_38 < V_40 -> V_4 ; V_38 ++ ) {
if ( V_40 -> V_8 [ V_38 ] . V_10 == V_11 )
V_40 -> V_8 [ V_38 ] . V_10 = V_10 ;
else
V_10 = V_40 -> V_8 [ V_38 ] . V_10 ;
if ( V_40 -> V_8 [ V_38 ] . V_9 == V_17 )
V_40 -> V_8 [ V_38 ] . V_9 = V_34 -> V_9 - V_10 ;
if ( V_40 -> V_8 [ V_38 ] . V_9 == 0 ) {
F_3 (KERN_WARNING ERRP
L_12 ,
part->mtd_id) ;
V_40 -> V_4 -- ;
memmove ( & V_40 -> V_8 [ V_38 ] , & V_40 -> V_8 [ V_38 + 1 ] ,
sizeof( * V_40 -> V_8 ) * ( V_40 -> V_4 - V_38 ) ) ;
continue;
}
if ( V_10 + V_40 -> V_8 [ V_38 ] . V_9 > V_34 -> V_9 ) {
F_3 (KERN_WARNING ERRP
L_13 ,
part->mtd_id) ;
V_40 -> V_8 [ V_38 ] . V_9 = V_34 -> V_9 - V_10 ;
}
V_10 += V_40 -> V_8 [ V_38 ] . V_9 ;
}
* V_35 = F_13 ( V_40 -> V_8 , sizeof( * V_40 -> V_8 ) * V_40 -> V_4 ,
V_24 ) ;
if ( ! * V_35 )
return - V_25 ;
return V_40 -> V_4 ;
}
static int F_14 ( char * V_2 )
{
V_41 = V_2 ;
return 1 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_42 ) ;
}
