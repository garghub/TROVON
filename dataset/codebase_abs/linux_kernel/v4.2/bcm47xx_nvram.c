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
int V_4 ;
T_1 V_10 ;
T_1 * V_11 , * V_12 ;
T_1 V_13 ;
if ( V_14 ) {
F_4 ( L_1 ) ;
return - V_15 ;
}
V_10 = V_16 ;
while ( V_10 <= V_9 ) {
V_13 = F_1 ( V_8 + V_10 ) ;
if ( V_13 ) {
V_3 = (struct V_2 * ) ( V_8 + V_10 - V_13 ) ;
goto V_17;
}
V_10 <<= 1 ;
}
V_3 = (struct V_2 * ) ( V_8 + 4096 ) ;
if ( V_3 -> V_6 == V_7 ) {
V_13 = V_18 ;
goto V_17;
}
V_3 = (struct V_2 * ) ( V_8 + 1024 ) ;
if ( V_3 -> V_6 == V_7 ) {
V_13 = V_18 ;
goto V_17;
}
F_5 ( L_2 ) ;
return - V_19 ;
V_17:
V_11 = ( T_1 * ) V_3 ;
V_12 = ( T_1 * ) V_20 ;
for ( V_4 = 0 ; V_4 < sizeof( struct V_2 ) ; V_4 += 4 )
* V_12 ++ = F_6 ( V_11 ++ ) ;
V_3 = (struct V_2 * ) V_20 ;
V_14 = V_3 -> V_21 ;
if ( V_14 > V_13 ) {
F_5 ( L_3 ) ;
V_14 = V_13 ;
}
if ( V_14 >= V_18 ) {
F_5 ( L_4 ,
V_3 -> V_21 , V_18 - 1 ) ;
V_14 = V_18 - 1 ;
}
for (; V_4 < V_14 ; V_4 += 4 )
* V_12 ++ = F_7 ( V_11 ++ ) ;
V_20 [ V_18 - 1 ] = '\0' ;
return 0 ;
}
int F_8 ( T_1 V_22 , T_1 V_9 )
{
void T_2 * V_8 ;
int V_23 ;
V_8 = F_9 ( V_22 , V_9 ) ;
if ( ! V_8 )
return - V_24 ;
V_23 = F_3 ( V_8 , V_9 ) ;
F_10 ( V_8 ) ;
return V_23 ;
}
static int F_11 ( void )
{
#ifdef F_12
struct V_25 * V_26 ;
struct V_2 V_3 ;
T_3 V_27 ;
int V_23 ;
V_26 = F_13 ( L_5 ) ;
if ( F_14 ( V_26 ) )
return - V_28 ;
V_23 = F_15 ( V_26 , 0 , sizeof( V_3 ) , & V_27 , ( V_29 * ) & V_3 ) ;
if ( ! V_23 && V_3 . V_6 == V_7 &&
V_3 . V_21 > sizeof( V_3 ) ) {
V_14 = V_3 . V_21 ;
if ( V_14 >= V_18 ) {
F_5 ( L_4 ,
V_3 . V_21 , V_18 ) ;
V_14 = V_18 - 1 ;
}
V_23 = F_15 ( V_26 , 0 , V_14 , & V_14 ,
( V_30 * ) V_20 ) ;
return V_23 ;
}
#endif
return - V_19 ;
}
int F_16 ( const char * V_31 , char * V_32 , T_3 V_33 )
{
char * V_34 , * V_35 , * V_1 , * V_36 ;
int V_23 ;
if ( ! V_31 )
return - V_37 ;
if ( ! V_14 ) {
V_23 = F_11 () ;
if ( V_23 )
return V_23 ;
}
V_34 = & V_20 [ sizeof( struct V_2 ) ] ;
V_1 = V_20 + sizeof( V_20 ) ;
while ( V_34 < V_1 && * V_34 ) {
V_36 = strchr ( V_34 , '=' ) ;
if ( ! V_36 )
break;
V_35 = V_36 + 1 ;
if ( V_36 - V_34 == strlen ( V_31 ) &&
strncmp ( V_34 , V_31 , V_36 - V_34 ) == 0 )
return snprintf ( V_32 , V_33 , L_6 , V_35 ) ;
V_34 = V_35 + strlen ( V_35 ) + 1 ;
}
return - V_38 ;
}
int F_17 ( const char * V_31 )
{
int V_4 , V_23 ;
char V_39 [] = L_7 ;
char V_40 [ V_41 ] ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ ) {
V_23 = snprintf ( V_39 , sizeof( V_39 ) , L_8 , V_4 ) ;
if ( V_23 <= 0 )
continue;
V_23 = F_16 ( V_39 , V_40 , sizeof( V_40 ) ) ;
if ( V_23 <= 0 )
continue;
if ( ! strcmp ( V_31 , V_40 ) )
return V_4 ;
}
return - V_38 ;
}
char * F_18 ( T_3 * V_43 )
{
int V_23 ;
char * V_44 ;
if ( ! V_14 ) {
V_23 = F_11 () ;
if ( V_23 )
return NULL ;
}
* V_43 = V_14 - sizeof( struct V_2 ) ;
V_44 = F_19 ( * V_43 ) ;
if ( ! V_44 )
return NULL ;
memcpy ( V_44 , & V_20 [ sizeof( struct V_2 ) ] , * V_43 ) ;
return V_44 ;
}
