static int F_1 ( struct V_1 * * V_2 , char * V_3 )
{
int V_4 = 0 ;
struct V_1 * V_5 ;
* V_2 = NULL ;
V_5 = F_2 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
if ( * V_3 == '-' ) {
V_5 -> V_8 = ( V_9 ) ( ~ 0ULL ) ;
V_3 ++ ;
} else {
V_5 -> V_8 = ( V_9 ) F_3 ( V_3 , & V_3 ) ;
if ( V_5 -> V_8 < ( V_9 ) V_10 ) {
F_4 ( L_1 ) ;
V_4 = - V_11 ;
goto V_12;
}
}
if ( * V_3 == '@' ) {
V_3 ++ ;
V_5 -> V_13 = ( V_9 ) F_3 ( V_3 , & V_3 ) ;
} else {
V_5 -> V_13 = ( V_9 ) ( ~ 0ULL ) ;
}
if ( * V_3 == '(' ) {
int V_14 ;
char * V_15 = strchr ( ++ V_3 , ')' ) ;
if ( ! V_15 ) {
F_4 ( L_2 ) ;
V_4 = - V_11 ;
goto V_12;
}
V_14 = F_5 ( int , V_15 - V_3 ,
sizeof( V_5 -> V_16 ) - 1 ) ;
strncpy ( V_5 -> V_16 , V_3 , V_14 ) ;
V_5 -> V_16 [ V_14 ] = '\0' ;
V_3 = ++ V_15 ;
} else
V_5 -> V_16 [ 0 ] = '\0' ;
V_5 -> V_17 = 0 ;
if ( ! strncmp ( V_3 , L_3 , 2 ) ) {
V_5 -> V_17 |= V_18 ;
V_3 += 2 ;
}
if ( ! strncmp ( V_3 , L_4 , 2 ) ) {
V_5 -> V_17 |= V_19 ;
V_3 += 2 ;
}
* V_2 = V_5 ;
return 0 ;
V_12:
F_6 ( V_5 ) ;
return V_4 ;
}
static void F_7 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
while ( V_21 -> V_2 ) {
V_2 = V_21 -> V_2 ;
V_21 -> V_2 = V_2 -> V_22 ;
F_6 ( V_2 ) ;
}
}
static int F_8 ( struct V_20 * * V_21 , const char * V_23 )
{
int V_4 = - V_11 ;
char * V_15 ;
int V_14 ;
struct V_1 * * V_22 ;
struct V_20 * V_24 ;
char V_25 [ V_26 + 32 + 4 ] ;
* V_21 = NULL ;
V_24 = F_2 ( sizeof( struct V_20 ) , V_6 ) ;
if ( ! V_24 )
return - V_7 ;
V_15 = strchr ( V_23 , ':' ) ;
if ( ! V_15 ) {
F_4 ( L_5 ) ;
goto V_12;
}
V_14 = F_5 ( int , V_15 - V_23 , sizeof( V_24 -> V_16 ) - 1 ) ;
strncpy ( V_24 -> V_16 , V_23 , V_14 ) ;
V_24 -> V_16 [ V_14 ] = '\0' ;
V_24 -> V_27 = 0 ;
V_22 = & V_24 -> V_2 ;
while ( V_15 && * ( ++ V_15 ) ) {
V_23 = V_15 ;
V_15 = strchr ( V_23 , ',' ) ;
V_14 = ( ! V_15 ) ? ( sizeof( V_25 ) - 1 ) :
F_5 ( int , V_15 - V_23 , sizeof( V_25 ) - 1 ) ;
strncpy ( V_25 , V_23 , V_14 ) ;
V_25 [ V_14 ] = '\0' ;
V_4 = F_1 ( V_22 , V_25 ) ;
if ( V_4 )
goto V_12;
V_24 -> V_27 ++ ;
V_22 = & ( * V_22 ) -> V_22 ;
}
if ( ! V_24 -> V_2 ) {
F_4 ( L_6 ) ;
V_4 = - V_11 ;
goto V_12;
}
* V_21 = V_24 ;
return 0 ;
V_12:
F_7 ( V_24 ) ;
F_6 ( V_24 ) ;
return V_4 ;
}
void F_9 ( struct V_20 * * V_21 )
{
struct V_20 * V_28 ;
while ( * V_21 ) {
V_28 = ( * V_21 ) -> V_28 ;
F_7 ( * V_21 ) ;
F_6 ( * V_21 ) ;
* V_21 = V_28 ;
}
}
int F_10 ( struct V_20 * * V_21 , const char * V_29 )
{
int V_4 ;
char * V_25 ;
char * V_30 ;
char * V_15 ;
struct V_20 * * V_28 ;
* V_21 = NULL ;
V_15 = V_30 = V_25 = F_11 ( V_29 , V_6 ) ;
if ( ! V_25 )
return - V_7 ;
V_28 = V_21 ;
while ( V_15 && * V_30 ) {
V_15 = strchr ( V_30 , ';' ) ;
if ( V_15 )
* V_15 = '\0' ;
V_4 = F_8 ( V_28 , V_30 ) ;
if ( V_4 )
goto V_12;
if ( V_15 )
V_30 = ++ V_15 ;
V_28 = & ( * V_28 ) -> V_28 ;
}
if ( ! * V_21 ) {
F_4 ( L_6 ) ;
V_4 = - V_11 ;
goto V_12;
}
V_4 = 0 ;
V_31:
F_6 ( V_25 ) ;
return V_4 ;
V_12:
F_9 ( V_21 ) ;
goto V_31;
}
struct V_20 * F_12 ( struct V_20 * V_21 ,
const char * V_32 )
{
while ( V_21 && strncmp ( V_32 , V_21 -> V_16 , sizeof( V_21 -> V_16 ) ) )
V_21 = V_21 -> V_28 ;
return V_21 ;
}
int F_13 ( struct V_20 * V_21 , V_9 V_33 ,
int V_34 ,
int (* F_14)( int , struct V_1 * , void * ) ,
void * V_35 )
{
V_9 V_13 = 0 ;
struct V_1 * V_2 ;
for ( V_2 = V_21 -> V_2 ; V_2 ;
V_2 = V_2 -> V_22 , V_34 ++ ) {
if ( V_2 -> V_13 == ( V_9 ) ( ~ 0ULL ) )
V_2 -> V_13 = V_13 ;
else
V_13 = V_2 -> V_13 ;
if ( V_13 >= V_33 )
break;
if ( V_2 -> V_8 > ( V_33 - V_13 ) )
V_2 -> V_8 = V_33 - V_13 ;
V_13 += V_2 -> V_8 ;
if ( F_14 ( V_34 , V_2 , V_35 ) )
break;
}
return V_34 ;
}
