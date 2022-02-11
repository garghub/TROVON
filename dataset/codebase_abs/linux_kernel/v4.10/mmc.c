int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 = V_1 -> V_3 ;
V_1 -> V_4 = F_2 ( V_2 , sizeof( V_1 -> V_4 [ 0 ] ) , V_5 ) ;
if ( V_1 -> V_4 == NULL )
return - V_6 ;
F_3 ( & V_1 -> V_7 ) ;
return 0 ;
}
void F_4 ( struct V_1 * V_1 )
{
F_5 ( V_1 -> V_4 ) ;
}
int F_6 ( struct V_1 * V_1 , T_1 V_8 , T_1 V_9 ,
struct V_10 * V_11 )
{
int V_12 = - V_13 ;
unsigned V_14 , V_15 ;
F_7 ( & V_1 -> V_7 ) ;
switch ( V_11 -> V_16 ) {
case V_17 :
V_14 = V_1 -> V_3 - 1 ;
break;
case V_18 :
F_8 ( V_1 -> V_19 , L_1
L_2 , V_11 -> V_16 ) ;
V_12 = - V_20 ;
goto V_21;
default:
V_14 = ~ 0 ;
for ( V_15 = 0 ; V_15 < V_1 -> V_3 - 1 ; V_15 ++ ) {
if ( V_1 -> V_4 [ V_15 ] == V_11 ) {
V_14 = V_15 ;
break;
}
if ( V_1 -> V_4 [ V_15 ] == NULL )
V_14 = V_15 ;
}
if ( V_14 == ~ 0 )
goto V_21;
}
V_12 = ( V_1 -> V_22 ) ( V_1 , V_8 , V_9 , V_14 ,
V_11 ) ;
if ( V_12 >= 0 )
V_1 -> V_4 [ V_14 ] = V_11 ;
V_21:
F_9 ( & V_1 -> V_7 ) ;
return V_12 ;
}
void F_10 ( struct V_1 * V_1 , struct V_10 * V_11 )
{
int V_12 ;
unsigned V_14 , V_15 ;
F_7 ( & V_1 -> V_7 ) ;
for ( V_15 = 0 ; V_15 < V_1 -> V_3 ; V_15 ++ ) {
if ( V_1 -> V_4 [ V_15 ] == V_11 ) {
V_14 = V_15 ;
goto V_23;
}
}
F_9 ( & V_1 -> V_7 ) ;
return;
V_23:
V_12 = ( V_1 -> V_24 ) ( V_1 , V_14 ) ;
if ( V_12 == 0 )
V_1 -> V_4 [ V_15 ] = NULL ;
F_9 ( & V_1 -> V_7 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
int V_25 ;
F_7 ( & V_1 -> V_26 ) ;
V_25 = V_1 -> V_27 ( V_1 ) ;
if ( V_25 >= 0 )
V_1 -> V_28 = 1 ;
F_9 ( & V_1 -> V_26 ) ;
return V_25 ;
}
static void F_12 ( struct V_1 * V_1 )
{
F_7 ( & V_1 -> V_26 ) ;
V_1 -> V_28 = 0 ;
V_1 -> V_29 ( V_1 , V_30 ) ;
F_9 ( & V_1 -> V_26 ) ;
}
int F_13 ( struct V_1 * V_1 )
{
int V_12 ;
struct V_31 * V_19 = V_1 -> V_19 ;
F_14 ( V_1 -> V_32 != NULL ) ;
F_15 ( V_1 -> V_33 == NULL ) ;
V_12 = F_16 ( V_1 ) ;
if ( V_12 < 0 ) {
F_8 ( V_19 , L_3 ,
V_12 ) ;
goto V_34;
}
V_12 = F_17 ( V_1 ) ;
if ( V_12 < 0 ) {
F_8 ( V_19 , L_4 ,
V_12 ) ;
goto V_35;
}
V_12 = F_18 ( V_1 ) ;
if ( V_12 < 0 ) {
F_8 ( V_19 , L_5 ,
V_12 ) ;
goto V_36;
}
V_12 = V_1 -> V_37 ( V_1 , V_1 -> V_38 ,
V_1 -> V_39 ) ;
if ( V_12 < 0 ) {
F_8 ( V_19 , L_6 , V_12 ) ;
goto V_40;
}
V_12 = F_11 ( V_1 ) ;
if ( V_12 < 0 ) {
F_8 ( V_19 , L_7 , V_12 ) ;
goto V_41;
}
return 0 ;
V_41:
F_19 ( V_1 ) ;
V_40:
V_36:
F_20 ( V_1 ) ;
V_35:
F_21 ( V_1 ) ;
V_34:
return V_12 ;
}
void F_22 ( struct V_1 * V_1 )
{
F_12 ( V_1 ) ;
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
}
int F_23 ( struct V_1 * V_1 , const struct V_42 * V_43 )
{
int V_12 = 0 ;
if ( memcmp ( V_43 , & V_44 , sizeof( * V_43 ) ) == 0 )
V_43 = NULL ;
F_7 ( & V_1 -> V_26 ) ;
if ( V_43 ) {
if ( V_1 -> V_28 ) {
F_9 ( & V_1 -> V_26 ) ;
return - V_45 ;
}
V_1 -> V_43 = * V_43 ;
}
if ( ( V_43 ) && ( V_1 -> V_33 == NULL ) ) {
V_1 -> V_33 = F_24 ( V_1 -> V_19 -> V_46 ) ;
if ( V_1 -> V_33 == NULL ) {
V_12 = - V_47 ;
F_8 ( V_1 -> V_19 ,
L_8 ) ;
goto V_48;
}
V_12 = F_25 ( V_1 ) ;
if ( V_12 < 0 ) {
F_8 ( V_1 -> V_19 , L_9 ) ;
goto V_49;
}
}
F_9 ( & V_1 -> V_26 ) ;
if ( V_43 )
V_12 = F_26 ( & V_1 -> V_50 ) ;
else if ( V_1 -> V_33 )
F_27 ( & V_1 -> V_50 ) ;
return V_12 ;
V_49:
F_28 ( V_1 -> V_33 ) ;
V_1 -> V_33 = NULL ;
V_48:
F_9 ( & V_1 -> V_26 ) ;
return V_12 ;
}
