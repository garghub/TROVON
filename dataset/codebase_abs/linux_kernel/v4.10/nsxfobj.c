T_1 F_1 ( T_2 V_1 , T_3 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
if ( ! V_2 ) {
return ( V_6 ) ;
}
if ( V_1 == V_7 ) {
* V_2 = V_8 ;
return ( V_9 ) ;
}
V_5 = F_2 ( V_10 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
V_4 = F_4 ( V_1 ) ;
if ( ! V_4 ) {
( void ) F_5 ( V_10 ) ;
return ( V_6 ) ;
}
* V_2 = V_4 -> type ;
V_5 = F_5 ( V_10 ) ;
return ( V_5 ) ;
}
T_1 F_6 ( T_2 V_1 , T_2 * V_11 )
{
struct V_3 * V_4 ;
struct V_3 * V_12 ;
T_1 V_5 ;
if ( ! V_11 ) {
return ( V_6 ) ;
}
if ( V_1 == V_7 ) {
return ( V_13 ) ;
}
V_5 = F_2 ( V_10 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
V_4 = F_4 ( V_1 ) ;
if ( ! V_4 ) {
V_5 = V_6 ;
goto V_14;
}
V_12 = V_4 -> V_15 ;
* V_11 = F_7 ( T_2 , V_12 ) ;
if ( ! V_12 ) {
V_5 = V_13 ;
}
V_14:
( void ) F_5 ( V_10 ) ;
return ( V_5 ) ;
}
T_1
F_8 ( T_3 type ,
T_2 V_15 ,
T_2 V_16 , T_2 * V_11 )
{
T_1 V_5 ;
struct V_3 * V_4 ;
struct V_3 * V_12 = NULL ;
struct V_3 * V_17 = NULL ;
if ( type > V_18 ) {
return ( V_6 ) ;
}
V_5 = F_2 ( V_10 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
if ( ! V_16 ) {
V_12 = F_4 ( V_15 ) ;
if ( ! V_12 ) {
V_5 = V_6 ;
goto V_14;
}
} else {
V_17 = F_4 ( V_16 ) ;
if ( ! V_17 ) {
V_5 = V_6 ;
goto V_14;
}
}
V_4 = F_9 ( type , V_12 , V_17 ) ;
if ( ! V_4 ) {
V_5 = V_19 ;
goto V_14;
}
if ( V_11 ) {
* V_11 = F_7 ( T_2 , V_4 ) ;
}
V_14:
( void ) F_5 ( V_10 ) ;
return ( V_5 ) ;
}
