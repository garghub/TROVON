static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , V_6 . V_7 . V_8 ) ;
}
static T_1 F_2 ( struct V_9 * V_10 , struct V_1 * V_2 ,
struct V_11 * V_12 ,
char * V_5 , T_2 V_13 , T_3 V_14 )
{
memcpy ( V_5 , ( void * ) & V_6 + V_13 , V_14 ) ;
return V_14 ;
}
static int F_3 ( struct V_1 * V_2 , int * V_15 )
{
const char * V_16 ;
V_16 = F_4 ( V_2 ) ;
return F_5 ( V_16 , 10 , V_15 ) ;
}
static int F_6 ( int V_15 , T_4 * V_17 )
{
int V_18 = 0 ;
struct V_19 * V_20 ;
T_4 V_21 = V_6 . V_7 . V_19 ;
while ( V_21 ) {
if ( V_15 == V_18 ) {
* V_17 = V_21 ;
return 0 ;
}
V_20 = F_7 ( V_21 , sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 )
return - V_23 ;
V_21 = V_20 -> V_24 ;
F_8 ( V_20 ) ;
V_18 ++ ;
}
return - V_25 ;
}
static int T_5 F_9 ( int V_15 , T_3 * V_26 )
{
int V_18 = 0 ;
struct V_19 * V_20 ;
T_4 V_21 = V_6 . V_7 . V_19 ;
while ( V_21 ) {
V_20 = F_7 ( V_21 , sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 )
return - V_23 ;
if ( V_15 == V_18 ) {
* V_26 = V_20 -> V_27 ;
F_8 ( V_20 ) ;
return 0 ;
}
V_21 = V_20 -> V_24 ;
F_8 ( V_20 ) ;
V_18 ++ ;
}
return - V_25 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_15 , V_28 ;
T_4 V_17 ;
struct V_19 * V_20 ;
V_28 = F_3 ( V_2 , & V_15 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_6 ( V_15 , & V_17 ) ;
if ( V_28 )
return V_28 ;
V_20 = F_7 ( V_17 , sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 )
return - V_23 ;
V_28 = sprintf ( V_5 , L_2 , V_20 -> type ) ;
F_8 ( V_20 ) ;
return V_28 ;
}
static T_1 F_11 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_11 * V_12 ,
char * V_5 ,
T_2 V_13 , T_3 V_14 )
{
int V_15 , V_28 = 0 ;
T_4 V_17 ;
struct V_19 * V_20 ;
void * V_29 ;
V_28 = F_3 ( V_2 , & V_15 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_6 ( V_15 , & V_17 ) ;
if ( V_28 )
return V_28 ;
V_20 = F_7 ( V_17 , sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 )
return - V_23 ;
if ( V_13 > V_20 -> V_27 ) {
V_28 = - V_25 ;
goto V_30;
}
if ( V_14 > V_20 -> V_27 - V_13 )
V_14 = V_20 -> V_27 - V_13 ;
if ( ! V_14 )
goto V_30;
V_28 = V_14 ;
V_29 = F_7 ( V_17 + sizeof( * V_20 ) , V_20 -> V_27 , V_22 ) ;
if ( ! V_29 ) {
V_28 = - V_23 ;
goto V_30;
}
memcpy ( V_5 , V_29 + V_13 , V_14 ) ;
F_8 ( V_29 ) ;
V_30:
F_8 ( V_20 ) ;
return V_28 ;
}
static int T_5 F_12 ( struct V_1 * V_31 ,
struct V_1 * * V_32 , int V_15 )
{
int V_28 = 0 ;
T_3 V_26 ;
struct V_1 * V_2 ;
char V_16 [ 16 ] ;
snprintf ( V_16 , 16 , L_3 , V_15 ) ;
V_2 = F_13 ( V_16 , V_31 ) ;
if ( ! V_2 )
return - V_23 ;
V_28 = F_9 ( V_15 , & V_26 ) ;
if ( V_28 )
goto V_33;
V_34 . V_26 = V_26 ;
V_28 = F_14 ( V_2 , & V_35 ) ;
if ( V_28 )
goto V_33;
* V_32 = V_2 ;
return 0 ;
V_33:
F_15 ( V_2 ) ;
return V_28 ;
}
static void T_5 F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 , & V_35 ) ;
F_15 ( V_2 ) ;
}
static int T_5 F_18 ( T_4 V_21 , int * V_15 )
{
int V_28 = 0 ;
struct V_19 * V_20 ;
* V_15 = 0 ;
while ( V_21 ) {
* V_15 += 1 ;
V_20 = F_7 ( V_21 , sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 ) {
V_28 = - V_23 ;
goto V_30;
}
V_21 = V_20 -> V_24 ;
F_8 ( V_20 ) ;
}
V_30:
return V_28 ;
}
static int T_5 F_19 ( struct V_1 * V_31 )
{
struct V_1 * V_36 , * * V_32 ;
T_4 V_21 ;
int V_18 , V_37 , V_15 , V_28 = 0 ;
V_21 = V_6 . V_7 . V_19 ;
if ( ! V_21 )
return 0 ;
V_36 = F_13 ( L_4 , V_31 ) ;
if ( ! V_36 ) {
V_28 = - V_23 ;
goto V_30;
}
V_28 = F_18 ( V_21 , & V_15 ) ;
if ( V_28 )
goto V_38;
V_32 = F_20 ( sizeof( * V_32 ) * V_15 , V_39 ) ;
if ( ! V_32 ) {
V_28 = - V_23 ;
goto V_38;
}
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
V_28 = F_12 ( V_36 , V_32 + V_18 , V_18 ) ;
if ( V_28 )
goto V_40;
}
F_21 ( V_32 ) ;
return 0 ;
V_40:
for ( V_37 = V_18 - 1 ; V_37 >= 0 ; V_37 -- )
F_16 ( * ( V_32 + V_37 ) ) ;
F_21 ( V_32 ) ;
V_38:
F_15 ( V_36 ) ;
V_30:
return V_28 ;
}
static int T_5 F_22 ( void )
{
int V_28 ;
struct V_1 * V_41 ;
V_41 = F_13 ( L_5 ,
V_42 ) ;
if ( ! V_41 ) {
V_28 = - V_23 ;
goto V_30;
}
V_28 = F_14 ( V_41 , & V_43 ) ;
if ( V_28 )
goto V_44;
V_28 = F_19 ( V_41 ) ;
if ( V_28 )
goto V_45;
return 0 ;
V_45:
F_17 ( V_41 , & V_43 ) ;
V_44:
F_15 ( V_41 ) ;
V_30:
return V_28 ;
}
