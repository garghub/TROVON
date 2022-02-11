static int F_1 ( const T_1 * V_1 , int V_2 )
{
if ( V_2 < V_3 )
return 0 ;
return ( V_1 [ 0x7e ] + 1 ) * V_3 ;
}
static void * F_2 ( struct V_4 * V_5 , const char * V_6 ,
const char * V_7 )
{
const struct V_8 * V_9 = NULL ;
const T_1 * V_10 ;
T_1 * V_1 ;
int V_11 , V_12 ;
int V_13 , V_14 = 0 ;
bool V_15 = ! V_5 -> V_16 || ( V_17 & V_18 ) ;
V_12 = 0 ;
for ( V_13 = 0 ; V_13 < V_19 ; V_13 ++ ) {
if ( strcmp ( V_6 , V_20 [ V_13 ] ) == 0 ) {
V_10 = V_21 [ V_13 ] ;
V_11 = sizeof( V_21 [ V_13 ] ) ;
V_12 = 1 ;
break;
}
}
if ( ! V_12 ) {
struct V_22 * V_23 ;
int V_24 ;
V_23 = F_3 ( V_7 , - 1 , NULL , 0 ) ;
if ( F_4 ( V_23 ) ) {
F_5 ( L_1
L_2 , V_7 ) ;
return F_6 ( V_23 ) ;
}
V_24 = F_7 ( & V_9 , V_6 , & V_23 -> V_25 ) ;
F_8 ( V_23 ) ;
if ( V_24 ) {
F_5 ( L_3 ,
V_6 , V_24 ) ;
return F_9 ( V_24 ) ;
}
V_10 = V_9 -> V_26 ;
V_11 = V_9 -> V_27 ;
}
if ( F_1 ( V_10 , V_11 ) != V_11 ) {
F_5 ( L_4
L_5 , V_6 ,
F_1 ( V_10 , V_11 ) , ( int ) V_11 ) ;
V_1 = F_9 ( - V_28 ) ;
goto V_29;
}
V_1 = F_10 ( V_10 , V_11 , V_30 ) ;
if ( V_1 == NULL ) {
V_1 = F_9 ( - V_31 ) ;
goto V_29;
}
if ( ! F_11 ( V_1 , 0 , V_15 ,
& V_5 -> V_32 ) ) {
V_5 -> V_16 ++ ;
F_5 ( L_6 ,
V_6 ) ;
F_12 ( V_1 ) ;
V_1 = F_9 ( - V_28 ) ;
goto V_29;
}
for ( V_13 = 1 ; V_13 <= V_1 [ 0x7e ] ; V_13 ++ ) {
if ( V_13 != V_14 + 1 )
memcpy ( V_1 + ( V_14 + 1 ) * V_3 ,
V_1 + V_13 * V_3 , V_3 ) ;
if ( F_11 ( V_1 + V_13 * V_3 , V_13 ,
V_15 ,
NULL ) )
V_14 ++ ;
}
if ( V_14 != V_1 [ 0x7e ] ) {
T_1 * V_33 ;
V_1 [ V_3 - 1 ] += V_1 [ 0x7e ] - V_14 ;
F_13 ( L_7
L_8 , V_14 ,
V_1 [ 0x7e ] , V_6 , V_7 ) ;
V_1 [ 0x7e ] = V_14 ;
V_33 = F_14 ( V_1 , ( V_14 + 1 ) * V_3 ,
V_30 ) ;
if ( V_33 )
V_1 = V_33 ;
}
F_13 ( L_9
L_8 , V_12 ? L_10 :
L_11 , V_14 , V_14 == 1 ? L_12 : L_13 ,
V_6 , V_7 ) ;
V_29:
F_15 ( V_9 ) ;
return V_1 ;
}
int F_16 ( struct V_4 * V_5 )
{
const char * V_7 = V_5 -> V_6 ;
char * V_34 , * V_35 , * V_36 , * V_37 , * V_38 , * V_39 = NULL ;
int V_40 ;
struct V_1 * V_1 ;
if ( V_41 [ 0 ] == '\0' )
return 0 ;
V_37 = F_17 ( V_41 , V_30 ) ;
V_38 = V_37 ;
while ( ( V_34 = F_18 ( & V_38 , L_14 ) ) ) {
V_36 = strchr ( V_34 , ':' ) ;
if ( V_36 != NULL ) {
if ( strncmp ( V_7 , V_34 , V_36 - V_34 ) )
continue;
V_34 = V_36 + 1 ;
break;
}
if ( * V_34 != '\0' )
V_39 = V_34 ;
}
if ( ! V_34 ) {
if ( ! V_39 ) {
F_12 ( V_37 ) ;
return 0 ;
}
V_34 = V_39 ;
}
V_35 = V_34 + strlen ( V_34 ) - 1 ;
if ( * V_35 == '\n' )
* V_35 = '\0' ;
V_1 = F_2 ( V_5 , V_34 , V_7 ) ;
F_12 ( V_37 ) ;
if ( F_19 ( V_1 ) )
return 0 ;
F_20 ( V_5 , V_1 ) ;
V_40 = F_21 ( V_5 , V_1 ) ;
F_22 ( V_5 , V_1 ) ;
F_12 ( V_1 ) ;
return V_40 ;
}
