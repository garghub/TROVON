static T_1 F_1 ( void T_2 * V_1 )
{
struct V_2 T_2 * V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_3 = (struct V_2 * ) ( V_1 - V_5 [ V_4 ] ) ;
if ( V_3 -> V_6 == V_7 )
return V_5 [ V_4 ] ;
}
return 0 ;
}
static int F_3 ( void T_2 * V_8 , T_1 V_9 )
{
struct V_2 T_2 * V_3 ;
T_1 V_10 ;
T_1 V_11 ;
if ( V_12 ) {
F_4 ( L_1 ) ;
return - V_13 ;
}
V_10 = V_14 ;
while ( V_10 <= V_9 ) {
V_11 = F_1 ( V_8 + V_10 ) ;
if ( V_11 ) {
V_3 = (struct V_2 * ) ( V_8 + V_10 - V_11 ) ;
goto V_15;
}
V_10 <<= 1 ;
}
V_3 = (struct V_2 * ) ( V_8 + 4096 ) ;
if ( V_3 -> V_6 == V_7 ) {
V_11 = V_16 ;
goto V_15;
}
V_3 = (struct V_2 * ) ( V_8 + 1024 ) ;
if ( V_3 -> V_6 == V_7 ) {
V_11 = V_16 ;
goto V_15;
}
F_5 ( L_2 ) ;
return - V_17 ;
V_15:
F_6 ( V_18 , V_3 , sizeof( * V_3 ) / 4 ) ;
V_12 = ( (struct V_2 * ) ( V_18 ) ) -> V_19 ;
if ( V_12 > V_11 ) {
F_5 ( L_3 ) ;
V_12 = V_11 ;
}
if ( V_12 >= V_16 ) {
F_5 ( L_4 ,
V_12 , V_16 - 1 ) ;
V_12 = V_16 - 1 ;
}
F_6 ( V_18 + sizeof( * V_3 ) , V_3 + 1 ,
F_7 ( V_12 , 4 ) ) ;
V_18 [ V_16 - 1 ] = '\0' ;
return 0 ;
}
int F_8 ( T_1 V_20 , T_1 V_9 )
{
void T_2 * V_8 ;
int V_21 ;
V_8 = F_9 ( V_20 , V_9 ) ;
if ( ! V_8 )
return - V_22 ;
V_21 = F_3 ( V_8 , V_9 ) ;
F_10 ( V_8 ) ;
return V_21 ;
}
static int F_11 ( void )
{
#ifdef F_12
struct V_23 * V_24 ;
struct V_2 V_3 ;
T_3 V_25 ;
int V_21 ;
V_24 = F_13 ( L_5 ) ;
if ( F_14 ( V_24 ) )
return - V_26 ;
V_21 = F_15 ( V_24 , 0 , sizeof( V_3 ) , & V_25 , ( V_27 * ) & V_3 ) ;
if ( ! V_21 && V_3 . V_6 == V_7 &&
V_3 . V_19 > sizeof( V_3 ) ) {
V_12 = V_3 . V_19 ;
if ( V_12 >= V_16 ) {
F_5 ( L_4 ,
V_3 . V_19 , V_16 ) ;
V_12 = V_16 - 1 ;
}
V_21 = F_15 ( V_24 , 0 , V_12 , & V_12 ,
( V_28 * ) V_18 ) ;
return V_21 ;
}
#endif
return - V_17 ;
}
int F_16 ( const char * V_29 , char * V_30 , T_3 V_31 )
{
char * V_32 , * V_33 , * V_1 , * V_34 ;
int V_21 ;
if ( ! V_29 )
return - V_35 ;
if ( ! V_12 ) {
V_21 = F_11 () ;
if ( V_21 )
return V_21 ;
}
V_32 = & V_18 [ sizeof( struct V_2 ) ] ;
V_1 = V_18 + sizeof( V_18 ) ;
while ( V_32 < V_1 && * V_32 ) {
V_34 = strchr ( V_32 , '=' ) ;
if ( ! V_34 )
break;
V_33 = V_34 + 1 ;
if ( V_34 - V_32 == strlen ( V_29 ) &&
strncmp ( V_32 , V_29 , V_34 - V_32 ) == 0 )
return snprintf ( V_30 , V_31 , L_6 , V_33 ) ;
V_32 = V_33 + strlen ( V_33 ) + 1 ;
}
return - V_36 ;
}
int F_17 ( const char * V_29 )
{
int V_4 , V_21 ;
char V_37 [] = L_7 ;
char V_38 [ V_39 ] ;
for ( V_4 = 0 ; V_4 < V_40 ; V_4 ++ ) {
V_21 = snprintf ( V_37 , sizeof( V_37 ) , L_8 , V_4 ) ;
if ( V_21 <= 0 )
continue;
V_21 = F_16 ( V_37 , V_38 , sizeof( V_38 ) ) ;
if ( V_21 <= 0 )
continue;
if ( ! strcmp ( V_29 , V_38 ) )
return V_4 ;
}
return - V_36 ;
}
char * F_18 ( T_3 * V_41 )
{
int V_21 ;
char * V_42 ;
if ( ! V_12 ) {
V_21 = F_11 () ;
if ( V_21 )
return NULL ;
}
* V_41 = V_12 - sizeof( struct V_2 ) ;
V_42 = F_19 ( * V_41 ) ;
if ( ! V_42 )
return NULL ;
memcpy ( V_42 , & V_18 [ sizeof( struct V_2 ) ] , * V_41 ) ;
return V_42 ;
}
