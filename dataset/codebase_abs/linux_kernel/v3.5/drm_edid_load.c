static int F_1 ( struct V_1 * V_2 , char * V_3 ,
char * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 * V_9 = NULL , * V_10 ;
int V_11 , V_12 ;
int V_13 = 0 , V_14 = 0 ;
int V_15 , V_16 = 0 ;
V_8 = F_2 ( V_4 , - 1 , NULL , 0 ) ;
if ( F_3 ( V_8 ) ) {
F_4 ( L_1
L_2 , V_4 ) ;
V_14 = - V_17 ;
goto V_18;
}
V_14 = F_5 ( & V_6 , V_3 , & V_8 -> V_19 ) ;
F_6 ( V_8 ) ;
if ( V_14 ) {
V_15 = 0 ;
while ( V_15 < V_20 && strcmp ( V_3 , V_21 [ V_15 ] ) )
V_15 ++ ;
if ( V_15 < V_20 ) {
V_14 = 0 ;
V_13 = 1 ;
V_9 = V_22 [ V_15 ] ;
V_11 = sizeof( V_22 [ V_15 ] ) ;
}
}
if ( V_14 ) {
F_4 ( L_3 ,
V_3 , V_14 ) ;
goto V_18;
}
if ( V_9 == NULL ) {
V_9 = ( T_1 * ) V_6 -> V_23 ;
V_11 = V_6 -> V_24 ;
}
V_12 = ( V_9 [ 0x7e ] + 1 ) * V_25 ;
if ( V_12 != V_11 ) {
F_4 ( L_4
L_5 , V_3 , V_12 , ( int ) V_11 ) ;
V_14 = - V_17 ;
goto V_26;
}
V_10 = F_7 ( V_11 , V_27 ) ;
if ( V_10 == NULL ) {
V_14 = - V_28 ;
goto V_26;
}
memcpy ( V_10 , V_9 , V_11 ) ;
if ( ! F_8 ( V_10 , 0 ) ) {
F_4 ( L_6 ,
V_3 ) ;
F_9 ( V_10 ) ;
V_14 = - V_17 ;
goto V_26;
}
for ( V_15 = 1 ; V_15 <= V_10 [ 0x7e ] ; V_15 ++ ) {
if ( V_15 != V_16 + 1 )
memcpy ( V_10 + ( V_16 + 1 ) * V_25 ,
V_10 + V_15 * V_25 , V_25 ) ;
if ( F_8 ( V_10 + V_15 * V_25 , V_15 ) )
V_16 ++ ;
}
if ( V_16 != V_10 [ 0x7e ] ) {
V_10 [ V_25 - 1 ] += V_10 [ 0x7e ] - V_16 ;
F_10 ( L_7
L_8 , V_16 ,
V_10 [ 0x7e ] , V_3 , V_4 ) ;
V_10 [ 0x7e ] = V_16 ;
V_10 = F_11 ( V_10 , ( V_16 + 1 ) * V_25 ,
V_27 ) ;
if ( V_10 == NULL ) {
V_14 = - V_28 ;
goto V_26;
}
}
V_2 -> V_29 . V_30 = V_10 ;
F_10 ( L_9
L_8 , V_13 ? L_10 :
L_11 , V_16 , V_16 == 1 ? L_12 : L_13 ,
V_3 , V_4 ) ;
V_26:
F_12 ( V_6 ) ;
V_18:
return V_14 ;
}
int F_13 ( struct V_1 * V_2 )
{
char * V_4 = F_14 ( V_2 ) ;
char * V_31 = V_32 , * V_33 , * V_34 ;
int V_35 ;
if ( * V_31 == '\0' )
return 0 ;
V_34 = strchr ( V_31 , ':' ) ;
if ( V_34 != NULL ) {
if ( strncmp ( V_4 , V_31 , V_34 - V_31 ) )
return 0 ;
V_31 = V_34 + 1 ;
if ( * V_31 == '\0' )
return 0 ;
}
V_33 = V_31 + strlen ( V_31 ) - 1 ;
if ( * V_33 == '\n' )
* V_33 = '\0' ;
V_35 = F_1 ( V_2 , V_31 , V_4 ) ;
if ( V_35 )
return 0 ;
F_15 ( V_2 ,
(struct V_10 * ) V_2 -> V_29 . V_30 ) ;
return F_16 ( V_2 , (struct V_10 * )
V_2 -> V_29 . V_30 ) ;
}
