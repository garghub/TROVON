static T_1 * F_1 ( struct V_1 * V_2 , char * V_3 ,
char * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 * V_9 = NULL , * V_10 , * V_11 ;
int V_12 , V_13 ;
int V_14 = 0 , V_15 = 0 ;
int V_16 , V_17 = 0 ;
bool V_18 = ! V_2 -> V_19 || ( V_20 & V_21 ) ;
V_8 = F_2 ( V_4 , - 1 , NULL , 0 ) ;
if ( F_3 ( V_8 ) ) {
F_4 ( L_1
L_2 , V_4 ) ;
V_15 = - V_22 ;
goto V_23;
}
V_15 = F_5 ( & V_6 , V_3 , & V_8 -> V_24 ) ;
F_6 ( V_8 ) ;
if ( V_15 ) {
V_16 = 0 ;
while ( V_16 < V_25 && strcmp ( V_3 , V_26 [ V_16 ] ) )
V_16 ++ ;
if ( V_16 < V_25 ) {
V_15 = 0 ;
V_14 = 1 ;
V_9 = V_27 [ V_16 ] ;
V_12 = sizeof( V_27 [ V_16 ] ) ;
}
}
if ( V_15 ) {
F_4 ( L_3 ,
V_3 , V_15 ) ;
goto V_23;
}
if ( V_9 == NULL ) {
V_9 = ( T_1 * ) V_6 -> V_28 ;
V_12 = V_6 -> V_29 ;
}
V_13 = ( V_9 [ 0x7e ] + 1 ) * V_30 ;
if ( V_13 != V_12 ) {
F_4 ( L_4
L_5 , V_3 , V_13 , ( int ) V_12 ) ;
V_15 = - V_22 ;
goto V_31;
}
V_10 = F_7 ( V_12 , V_32 ) ;
if ( V_10 == NULL ) {
V_15 = - V_33 ;
goto V_31;
}
memcpy ( V_10 , V_9 , V_12 ) ;
if ( ! F_8 ( V_10 , 0 , V_18 ) ) {
V_2 -> V_19 ++ ;
F_4 ( L_6 ,
V_3 ) ;
F_9 ( V_10 ) ;
V_15 = - V_22 ;
goto V_31;
}
for ( V_16 = 1 ; V_16 <= V_10 [ 0x7e ] ; V_16 ++ ) {
if ( V_16 != V_17 + 1 )
memcpy ( V_10 + ( V_17 + 1 ) * V_30 ,
V_10 + V_16 * V_30 , V_30 ) ;
if ( F_8 ( V_10 + V_16 * V_30 , V_16 , V_18 ) )
V_17 ++ ;
}
if ( V_17 != V_10 [ 0x7e ] ) {
V_10 [ V_30 - 1 ] += V_10 [ 0x7e ] - V_17 ;
F_10 ( L_7
L_8 , V_17 ,
V_10 [ 0x7e ] , V_3 , V_4 ) ;
V_10 [ 0x7e ] = V_17 ;
V_11 = F_11 ( V_10 , ( V_17 + 1 ) * V_30 ,
V_32 ) ;
if ( V_11 == NULL ) {
V_15 = - V_33 ;
F_9 ( V_10 ) ;
goto V_31;
}
V_10 = V_11 ;
}
F_10 ( L_9
L_8 , V_14 ? L_10 :
L_11 , V_17 , V_17 == 1 ? L_12 : L_13 ,
V_3 , V_4 ) ;
V_31:
F_12 ( V_6 ) ;
V_23:
if ( V_15 )
return F_13 ( V_15 ) ;
return V_10 ;
}
int F_14 ( struct V_1 * V_2 )
{
char * V_4 = F_15 ( V_2 ) ;
char * V_34 = V_35 , * V_36 , * V_37 ;
int V_38 ;
struct V_10 * V_10 ;
if ( * V_34 == '\0' )
return 0 ;
V_37 = strchr ( V_34 , ':' ) ;
if ( V_37 != NULL ) {
if ( strncmp ( V_4 , V_34 , V_37 - V_34 ) )
return 0 ;
V_34 = V_37 + 1 ;
if ( * V_34 == '\0' )
return 0 ;
}
V_36 = V_34 + strlen ( V_34 ) - 1 ;
if ( * V_36 == '\n' )
* V_36 = '\0' ;
V_10 = (struct V_10 * ) F_1 ( V_2 , V_34 , V_4 ) ;
if ( F_16 ( V_10 ) )
return 0 ;
F_17 ( V_2 , V_10 ) ;
V_38 = F_18 ( V_2 , V_10 ) ;
F_9 ( V_10 ) ;
return V_38 ;
}
