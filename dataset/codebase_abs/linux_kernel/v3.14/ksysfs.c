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
V_20 = F_7 ( V_21 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_22 ;
V_21 = V_20 -> V_23 ;
F_8 ( V_20 ) ;
V_18 ++ ;
}
return - V_24 ;
}
static int T_5 F_9 ( int V_15 , T_3 * V_25 )
{
int V_18 = 0 ;
struct V_19 * V_20 ;
T_4 V_21 = V_6 . V_7 . V_19 ;
while ( V_21 ) {
V_20 = F_7 ( V_21 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_22 ;
if ( V_15 == V_18 ) {
* V_25 = V_20 -> V_26 ;
F_8 ( V_20 ) ;
return 0 ;
}
V_21 = V_20 -> V_23 ;
F_8 ( V_20 ) ;
V_18 ++ ;
}
return - V_24 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_15 , V_27 ;
T_4 V_17 ;
struct V_19 * V_20 ;
V_27 = F_3 ( V_2 , & V_15 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_6 ( V_15 , & V_17 ) ;
if ( V_27 )
return V_27 ;
V_20 = F_7 ( V_17 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_22 ;
V_27 = sprintf ( V_5 , L_2 , V_20 -> type ) ;
F_8 ( V_20 ) ;
return V_27 ;
}
static T_1 F_11 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_11 * V_12 ,
char * V_5 ,
T_2 V_13 , T_3 V_14 )
{
int V_15 , V_27 = 0 ;
T_4 V_17 ;
struct V_19 * V_20 ;
void * V_28 ;
V_27 = F_3 ( V_2 , & V_15 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_6 ( V_15 , & V_17 ) ;
if ( V_27 )
return V_27 ;
V_20 = F_7 ( V_17 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_22 ;
if ( V_13 > V_20 -> V_26 ) {
V_27 = - V_24 ;
goto V_29;
}
if ( V_14 > V_20 -> V_26 - V_13 )
V_14 = V_20 -> V_26 - V_13 ;
if ( ! V_14 )
goto V_29;
V_27 = V_14 ;
V_28 = F_7 ( V_17 + sizeof( * V_20 ) , V_20 -> V_26 ) ;
if ( ! V_28 ) {
V_27 = - V_22 ;
goto V_29;
}
memcpy ( V_5 , V_28 + V_13 , V_14 ) ;
F_8 ( V_28 ) ;
V_29:
F_8 ( V_20 ) ;
return V_27 ;
}
static int T_5 F_12 ( struct V_1 * V_30 ,
struct V_1 * * V_31 , int V_15 )
{
int V_27 = 0 ;
T_3 V_25 ;
struct V_1 * V_2 ;
char V_16 [ 16 ] ;
snprintf ( V_16 , 16 , L_3 , V_15 ) ;
V_2 = F_13 ( V_16 , V_30 ) ;
if ( ! V_2 )
return - V_22 ;
V_27 = F_9 ( V_15 , & V_25 ) ;
if ( V_27 )
goto V_32;
V_33 . V_25 = V_25 ;
V_27 = F_14 ( V_2 , & V_34 ) ;
if ( V_27 )
goto V_32;
* V_31 = V_2 ;
return 0 ;
V_32:
F_15 ( V_2 ) ;
return V_27 ;
}
static void T_5 F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 , & V_34 ) ;
F_15 ( V_2 ) ;
}
static int T_5 F_18 ( T_4 V_21 , int * V_15 )
{
int V_27 = 0 ;
struct V_19 * V_20 ;
* V_15 = 0 ;
while ( V_21 ) {
* V_15 += 1 ;
V_20 = F_7 ( V_21 , sizeof( * V_20 ) ) ;
if ( ! V_20 ) {
V_27 = - V_22 ;
goto V_29;
}
V_21 = V_20 -> V_23 ;
F_8 ( V_20 ) ;
}
V_29:
return V_27 ;
}
static int T_5 F_19 ( struct V_1 * V_30 )
{
struct V_1 * V_35 , * * V_31 ;
T_4 V_21 ;
int V_18 , V_36 , V_15 , V_27 = 0 ;
V_21 = V_6 . V_7 . V_19 ;
if ( ! V_21 )
return 0 ;
V_35 = F_13 ( L_4 , V_30 ) ;
if ( ! V_35 ) {
V_27 = - V_22 ;
goto V_29;
}
V_27 = F_18 ( V_21 , & V_15 ) ;
if ( V_27 )
goto V_37;
V_31 = F_20 ( sizeof( * V_31 ) * V_15 , V_38 ) ;
if ( ! V_31 ) {
V_27 = - V_22 ;
goto V_37;
}
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
V_27 = F_12 ( V_35 , V_31 + V_18 , V_18 ) ;
if ( V_27 )
goto V_39;
}
F_21 ( V_31 ) ;
return 0 ;
V_39:
for ( V_36 = V_18 - 1 ; V_36 > 0 ; V_36 -- )
F_16 ( * ( V_31 + V_36 ) ) ;
F_21 ( V_31 ) ;
V_37:
F_15 ( V_35 ) ;
V_29:
return V_27 ;
}
static int T_5 F_22 ( void )
{
int V_27 ;
struct V_1 * V_40 ;
V_40 = F_13 ( L_5 ,
V_41 ) ;
if ( ! V_40 ) {
V_27 = - V_22 ;
goto V_29;
}
V_27 = F_14 ( V_40 , & V_42 ) ;
if ( V_27 )
goto V_43;
V_27 = F_19 ( V_40 ) ;
if ( V_27 )
goto V_44;
return 0 ;
V_44:
F_17 ( V_40 , & V_42 ) ;
V_43:
F_15 ( V_40 ) ;
V_29:
return V_27 ;
}
