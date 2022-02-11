T_1 F_1 ( T_1 * V_1 )
{
char V_2 [ V_3 ] = L_1 ;
int V_4 = - V_5 ;
struct V_6 * V_7 = NULL ;
T_1 V_8 ;
T_1 V_9 ;
if ( ! F_2 () )
goto V_10;
V_4 = F_3 ( & V_7 ) ;
if ( V_4 ) {
F_4 () ;
goto V_10;
}
V_4 = F_5 ( ( T_1 ) & V_2 , & V_9 ) ;
if ( ! V_4 ) {
V_4 = F_6 ( (struct V_11 * )
V_9 ) ;
if ( V_4 )
( void ) F_7
( ( T_1 ) V_9 , V_7 ) ;
} else {
F_8 ( V_12 , L_2 , V_13 ) ;
V_4 = - V_5 ;
}
if ( V_4 ) {
for ( V_8 = F_9 () ;
V_8 != 0 ;
V_8 = F_10 ( V_8 ) ) {
( void ) F_11 ( (struct V_11 * )
V_8 ) ;
( void ) F_7 ( ( T_1 ) V_8 , V_7 ) ;
}
( void ) F_12 ( V_7 ) ;
V_7 = NULL ;
F_4 () ;
F_8 ( V_12 , L_3 , V_13 ) ;
}
V_10:
if ( ! V_4 ) {
( void ) F_13 () ;
} else {
F_8 ( V_12 , L_4 , V_13 ) ;
}
* V_1 = V_4 ;
return ( T_1 ) V_7 ;
}
bool F_14 ( T_1 V_14 )
{
bool V_15 = true ;
T_1 V_8 ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = F_15 ( V_12 ) ;
while ( ( V_8 = F_9 () ) != 0 ) {
( void ) F_11 ( (struct V_11 * ) V_8 ) ;
( void ) F_7 ( ( T_1 ) V_8 ,
(struct V_6 * ) V_14 ) ;
}
( void ) F_12 ( (struct V_6 * ) V_14 ) ;
if ( V_19 && V_19 -> V_16 ) {
V_17 = V_19 -> V_16 ;
( void ) F_16 ( V_17 ) ;
} else {
F_17 ( L_5 , V_13 ) ;
}
F_4 () ;
return V_15 ;
}
