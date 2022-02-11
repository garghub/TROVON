T_1 F_1 ( T_2 V_1 , T_3 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
if ( ! V_2 ) {
return ( V_6 ) ;
}
V_5 = F_2 ( V_7 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
V_4 = F_4 ( V_1 ) ;
if ( ! V_4 ) {
( void ) F_5 ( V_7 ) ;
return ( V_6 ) ;
}
* V_2 = V_4 -> V_8 ;
V_5 = F_5 ( V_7 ) ;
return ( V_5 ) ;
}
T_1 F_6 ( T_2 V_1 , T_4 * V_9 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
if ( ! V_9 ) {
return ( V_6 ) ;
}
if ( V_1 == V_10 ) {
* V_9 = V_11 ;
return ( V_12 ) ;
}
V_5 = F_2 ( V_7 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
V_4 = F_4 ( V_1 ) ;
if ( ! V_4 ) {
( void ) F_5 ( V_7 ) ;
return ( V_6 ) ;
}
* V_9 = V_4 -> type ;
V_5 = F_5 ( V_7 ) ;
return ( V_5 ) ;
}
T_1 F_7 ( T_2 V_1 , T_2 * V_13 )
{
struct V_3 * V_4 ;
struct V_3 * V_14 ;
T_1 V_5 ;
if ( ! V_13 ) {
return ( V_6 ) ;
}
if ( V_1 == V_10 ) {
return ( V_15 ) ;
}
V_5 = F_2 ( V_7 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
V_4 = F_4 ( V_1 ) ;
if ( ! V_4 ) {
V_5 = V_6 ;
goto V_16;
}
V_14 = V_4 -> V_17 ;
* V_13 = F_8 ( T_2 , V_14 ) ;
if ( ! V_14 ) {
V_5 = V_15 ;
}
V_16:
( void ) F_5 ( V_7 ) ;
return ( V_5 ) ;
}
T_1
F_9 ( T_4 type ,
T_2 V_17 ,
T_2 V_18 , T_2 * V_13 )
{
T_1 V_5 ;
struct V_3 * V_4 ;
struct V_3 * V_14 = NULL ;
struct V_3 * V_19 = NULL ;
if ( type > V_20 ) {
return ( V_6 ) ;
}
V_5 = F_2 ( V_7 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
if ( ! V_18 ) {
V_14 = F_4 ( V_17 ) ;
if ( ! V_14 ) {
V_5 = V_6 ;
goto V_16;
}
} else {
V_19 = F_4 ( V_18 ) ;
if ( ! V_19 ) {
V_5 = V_6 ;
goto V_16;
}
}
V_4 = F_10 ( type , V_14 , V_19 ) ;
if ( ! V_4 ) {
V_5 = V_21 ;
goto V_16;
}
if ( V_13 ) {
* V_13 = F_8 ( T_2 , V_4 ) ;
}
V_16:
( void ) F_5 ( V_7 ) ;
return ( V_5 ) ;
}
