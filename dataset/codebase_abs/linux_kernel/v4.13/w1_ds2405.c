static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 = F_2 ( * ( T_1 * ) & V_2 -> V_8 ) ;
unsigned int V_9 ;
if ( F_3 ( V_5 ) != 0 )
return 0 ;
F_4 ( V_5 , V_3 ? V_10 : V_11 ) ;
for ( V_9 = 0 ; V_9 < 64 ; V_9 ++ ) {
int V_12 = ! ! ( V_7 & F_5 ( V_9 ) ) ;
T_2 V_13 ;
V_13 = F_6 ( V_5 , V_12 ) ;
if ( ( V_13 & ( F_5 ( 0 ) | F_5 ( 1 ) ) ) ==
( F_5 ( 0 ) | F_5 ( 1 ) ) )
return 0 ;
if ( ! ! ( V_13 & F_5 ( 2 ) ) != V_12 )
return 0 ;
}
return 1 ;
}
static int F_7 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 , true ) )
return 0 ;
if ( F_1 ( V_2 , false ) )
return 1 ;
return - V_14 ;
}
static T_3 F_8 ( struct V_15 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_13 ;
T_3 V_19 ;
T_2 V_20 ;
V_13 = F_10 ( & V_5 -> V_21 ) ;
if ( V_13 )
return V_13 ;
if ( ! F_1 ( V_2 , false ) ) {
V_19 = - V_14 ;
goto V_22;
}
V_20 = F_11 ( V_5 ) ;
if ( V_20 != 0 &&
V_20 != 0xff ) {
F_12 ( V_15 , L_1 , V_20 ) ;
V_19 = - V_23 ;
goto V_22;
}
* V_18 = V_20 ? '1' : '0' ;
V_19 = 1 ;
V_22:
F_3 ( V_5 ) ;
F_13 ( & V_5 -> V_21 ) ;
return V_19 ;
}
static T_3 F_14 ( struct V_15 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_13 ;
T_3 V_19 ;
V_13 = F_10 ( & V_5 -> V_21 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_7 ( V_2 ) ;
if ( V_13 < 0 ) {
V_19 = V_13 ;
goto V_22;
}
* V_18 = V_13 ? '1' : '0' ;
V_19 = 1 ;
V_22:
F_3 ( V_5 ) ;
F_13 ( & V_5 -> V_21 ) ;
return V_19 ;
}
static T_3 F_15 ( struct V_15 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_4 V_24 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_13 , V_25 ;
unsigned int V_26 ;
T_3 V_19 ;
if ( V_24 < 1 )
return - V_27 ;
if ( sscanf ( V_18 , L_2 , & V_26 , & V_13 ) < 1 )
return - V_27 ;
if ( V_26 != 0 && V_26 != 1 )
return - V_27 ;
V_19 = V_13 ;
V_13 = F_10 ( & V_5 -> V_21 ) ;
if ( V_13 )
return V_13 ;
V_25 = F_7 ( V_2 ) ;
if ( V_25 < 0 ) {
V_19 = V_25 ;
goto V_22;
}
if ( V_25 == V_26 )
goto V_22;
if ( F_3 ( V_5 ) != 0 ) {
V_19 = - V_14 ;
goto V_22;
}
do {
T_1 V_7 = F_2 ( * ( T_1 * ) & V_2 -> V_8 ) ;
T_2 V_28 [ 9 ] ;
V_28 [ 0 ] = V_29 ;
memcpy ( & V_28 [ 1 ] , & V_7 , sizeof( V_7 ) ) ;
F_16 ( V_5 , V_28 , sizeof( V_28 ) ) ;
} while ( 0 );
V_22:
F_3 ( V_5 ) ;
F_13 ( & V_5 -> V_21 ) ;
return V_19 ;
}
