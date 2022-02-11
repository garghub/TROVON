void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( & V_2 ) ;
}
void F_4 ( void )
{
F_5 ( NULL ) ;
}
int F_6 ( const char * V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
struct V_8 V_9 ;
int V_10 = - V_11 ;
F_7 ( & V_9 , V_3 ) ;
F_8 ( & V_2 ) ;
F_9 (data, &g_uuid_list, un_list) {
if ( F_10 ( & V_7 -> V_12 , & V_9 ) ) {
if ( V_5 >= V_7 -> V_13 )
break;
V_10 = 0 ;
* V_4 = V_7 -> V_14 [ V_5 ] ;
break;
}
}
F_11 ( & V_2 ) ;
return V_10 ;
}
int F_12 ( const char * V_3 , T_2 V_15 )
{
struct V_6 * V_7 , * V_16 ;
int V_17 = 0 ;
F_13 ( V_15 != 0 ) ;
if ( strlen ( V_3 ) > V_18 - 1 )
return - V_19 ;
F_14 ( V_7 ) ;
if ( V_7 == NULL )
return - V_20 ;
F_7 ( & V_7 -> V_12 , V_3 ) ;
V_7 -> V_14 [ 0 ] = V_15 ;
V_7 -> V_13 = 1 ;
F_8 ( & V_2 ) ;
F_9 (entry, &g_uuid_list, un_list) {
if ( F_10 ( & V_16 -> V_12 , & V_7 -> V_12 ) ) {
int V_21 ;
V_17 = 1 ;
for ( V_21 = 0 ; V_21 < V_16 -> V_13 ; V_21 ++ )
if ( V_15 == V_16 -> V_14 [ V_21 ] )
break;
if ( V_21 == V_16 -> V_13 ) {
F_13 ( V_16 -> V_13 < V_22 ) ;
V_16 -> V_14 [ V_16 -> V_13 ++ ] = V_15 ;
}
break;
}
}
if ( ! V_17 )
F_15 ( & V_7 -> V_23 , & V_1 ) ;
F_11 ( & V_2 ) ;
if ( V_17 ) {
F_16 ( V_24 , L_1 , V_3 ,
F_17 ( V_15 ) , V_16 -> V_13 ) ;
F_18 ( V_7 , sizeof( * V_7 ) ) ;
} else {
F_16 ( V_24 , L_2 , V_3 , F_17 ( V_15 ) ) ;
}
return 0 ;
}
int F_5 ( const char * V_3 )
{
F_19 ( V_25 ) ;
struct V_6 * V_7 ;
F_8 ( & V_2 ) ;
if ( V_3 != NULL ) {
struct V_8 V_9 ;
F_7 ( & V_9 , V_3 ) ;
F_9 (data, &g_uuid_list, un_list) {
if ( F_10 ( & V_7 -> V_12 , & V_9 ) ) {
F_20 ( & V_7 -> V_23 , & V_25 ) ;
break;
}
}
} else
F_21 ( & V_1 , & V_25 ) ;
F_11 ( & V_2 ) ;
if ( V_3 != NULL && F_22 ( & V_25 ) ) {
F_16 ( V_24 , L_3 , V_3 ) ;
return - V_26 ;
}
while ( ! F_22 ( & V_25 ) ) {
V_7 = F_23 ( V_25 . V_27 , struct V_6 ,
V_23 ) ;
F_24 ( & V_7 -> V_23 ) ;
F_16 ( V_24 , L_4 ,
F_25 ( & V_7 -> V_12 ) ,
F_17 ( V_7 -> V_14 [ 0 ] ) ,
V_7 -> V_13 ) ;
F_18 ( V_7 , sizeof( * V_7 ) ) ;
}
return 0 ;
}
int F_26 ( struct V_8 * V_3 , T_2 V_15 )
{
struct V_6 * V_16 ;
int V_17 = 0 ;
V_28 ;
F_16 ( V_24 , L_5 ,
F_25 ( V_3 ) , F_17 ( V_15 ) ) ;
F_8 ( & V_2 ) ;
F_9 (entry, &g_uuid_list, un_list) {
int V_21 ;
if ( ! F_10 ( & V_16 -> V_12 , V_3 ) )
continue;
for ( V_21 = 0 ; V_21 < V_16 -> V_13 ; V_21 ++ ) {
if ( V_16 -> V_14 [ V_21 ] == V_15 ) {
V_17 = 1 ;
break;
}
}
break;
}
F_11 ( & V_2 ) ;
RETURN ( V_17 ) ;
}
