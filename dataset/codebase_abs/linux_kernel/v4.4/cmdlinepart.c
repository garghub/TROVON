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
if ( ! V_9 ) {
F_3 ( L_1 ) ;
return F_4 ( - V_18 ) ;
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
char * V_19 ;
V_12 = ++ V_2 ;
V_19 = strchr ( V_12 , V_15 ) ;
if ( ! V_19 ) {
F_3 ( L_2 , V_15 ) ;
return F_4 ( - V_18 ) ;
}
V_13 = V_19 - V_12 ;
V_2 = V_19 + 1 ;
} else {
V_12 = NULL ;
V_13 = 13 ;
}
V_7 += V_13 + 1 ;
if ( strncmp ( V_2 , L_3 , 2 ) == 0 ) {
V_16 |= V_20 ;
V_2 += 2 ;
}
if ( strncmp ( V_2 , L_4 , 2 ) == 0 ) {
V_16 |= V_21 ;
V_2 += 2 ;
}
if ( * V_2 == ',' ) {
if ( V_9 == V_17 ) {
F_3 ( L_5 ) ;
return F_4 ( - V_18 ) ;
}
V_8 = F_1 ( V_2 + 1 , & V_2 , V_4 , V_5 + 1 ,
& V_14 , V_7 ) ;
if ( F_5 ( V_8 ) )
return V_8 ;
} else {
int V_22 ;
* V_4 = V_5 + 1 ;
V_22 = * V_4 * sizeof( struct V_1 ) +
V_7 ;
V_8 = F_6 ( V_22 , V_23 ) ;
if ( ! V_8 )
return F_4 ( - V_24 ) ;
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
V_25 = 1 ;
for( ; V_2 != NULL ; )
{
struct V_26 * V_27 ;
struct V_1 * V_8 ;
int V_28 , V_4 ;
char * V_19 , * V_29 ;
V_29 = V_2 ;
V_19 = strchr ( V_2 , ':' ) ;
if ( ! V_19 ) {
F_3 ( L_8 ) ;
return - V_18 ;
}
V_28 = V_19 - V_29 ;
F_8 ( ( L_9 , V_19 + 1 ) ) ;
V_8 = F_1 ( V_19 + 1 ,
& V_2 ,
& V_4 ,
0 ,
( unsigned char * * ) & V_27 ,
V_28 + 1 + sizeof( * V_27 ) +
sizeof( void * ) - 1 ) ;
if ( F_5 ( V_8 ) ) {
return F_10 ( V_8 ) ;
}
V_27 = (struct V_26 * )
F_11 ( ( unsigned long ) V_27 , sizeof( void * ) ) ;
V_27 -> V_8 = V_8 ;
V_27 -> V_4 = V_4 ;
V_27 -> V_29 = ( char * ) ( V_27 + 1 ) ;
F_7 ( V_27 -> V_29 , V_29 , V_28 + 1 ) ;
V_27 -> V_30 = V_31 ;
V_31 = V_27 ;
F_8 ( ( L_10 ,
V_27 -> V_29 , V_27 -> V_4 ) ) ;
if ( * V_2 == 0 )
break;
if ( * V_2 != ';' ) {
F_3 ( L_11 , * V_2 ) ;
return - V_18 ;
}
V_2 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_32 * V_33 ,
struct V_1 * * V_34 ,
struct V_35 * V_36 )
{
unsigned long long V_10 ;
int V_37 , V_38 ;
struct V_26 * V_39 ;
const char * V_29 = V_33 -> V_12 ;
if ( ! V_25 ) {
V_38 = F_9 ( V_40 ) ;
if ( V_38 )
return V_38 ;
}
for ( V_39 = V_31 ; V_39 ; V_39 = V_39 -> V_30 ) {
if ( ( ! V_29 ) || ( ! strcmp ( V_39 -> V_29 , V_29 ) ) )
break;
}
if ( ! V_39 )
return 0 ;
for ( V_37 = 0 , V_10 = 0 ; V_37 < V_39 -> V_4 ; V_37 ++ ) {
if ( V_39 -> V_8 [ V_37 ] . V_10 == V_11 )
V_39 -> V_8 [ V_37 ] . V_10 = V_10 ;
else
V_10 = V_39 -> V_8 [ V_37 ] . V_10 ;
if ( V_39 -> V_8 [ V_37 ] . V_9 == V_17 )
V_39 -> V_8 [ V_37 ] . V_9 = V_33 -> V_9 - V_10 ;
if ( V_10 + V_39 -> V_8 [ V_37 ] . V_9 > V_33 -> V_9 ) {
F_13 ( L_12 ,
V_39 -> V_29 ) ;
V_39 -> V_8 [ V_37 ] . V_9 = V_33 -> V_9 - V_10 ;
}
V_10 += V_39 -> V_8 [ V_37 ] . V_9 ;
if ( V_39 -> V_8 [ V_37 ] . V_9 == 0 ) {
F_13 ( L_13 ,
V_39 -> V_29 ) ;
V_39 -> V_4 -- ;
memmove ( & V_39 -> V_8 [ V_37 ] , & V_39 -> V_8 [ V_37 + 1 ] ,
sizeof( * V_39 -> V_8 ) * ( V_39 -> V_4 - V_37 ) ) ;
V_37 -- ;
}
}
* V_34 = F_14 ( V_39 -> V_8 , sizeof( * V_39 -> V_8 ) * V_39 -> V_4 ,
V_23 ) ;
if ( ! * V_34 )
return - V_24 ;
return V_39 -> V_4 ;
}
static int T_1 F_15 ( char * V_2 )
{
V_40 = V_2 ;
return 1 ;
}
static int T_1 F_16 ( void )
{
if ( V_41 )
F_15 ( V_41 ) ;
F_17 ( & V_42 ) ;
return 0 ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_42 ) ;
}
