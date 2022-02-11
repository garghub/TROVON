static int F_1 ( struct V_1 * V_2 , char * V_3 )
{
char * V_4 = V_3 ;
int V_5 ;
struct V_6 * V_7 ;
V_4 += sprintf ( V_3 , L_1 ) ;
V_5 = 11 ;
V_7 = V_2 -> V_8 ;
while ( V_7 && V_5 -- ) {
V_4 += sprintf ( V_4 , L_2 , V_7 -> V_9 , V_7 -> V_10 ) ;
V_7 = V_7 -> V_11 ;
}
V_4 += sprintf ( V_4 , L_3 ) ;
V_5 = 11 ;
V_7 = V_2 -> V_12 ;
while ( V_7 && V_5 -- ) {
V_4 += sprintf ( V_4 , L_2 , V_7 -> V_9 , V_7 -> V_10 ) ;
V_7 = V_7 -> V_11 ;
}
V_4 += sprintf ( V_4 , L_4 ) ;
V_5 = 11 ;
V_7 = V_2 -> V_13 ;
while ( V_7 && V_5 -- ) {
V_4 += sprintf ( V_4 , L_2 , V_7 -> V_9 , V_7 -> V_10 ) ;
V_7 = V_7 -> V_11 ;
}
V_4 += sprintf ( V_4 , L_5 ) ;
V_5 = 11 ;
V_7 = V_2 -> V_14 ;
while ( V_7 && V_5 -- ) {
V_4 += sprintf ( V_4 , L_2 , V_7 -> V_9 , V_7 -> V_10 ) ;
V_7 = V_7 -> V_11 ;
}
return V_4 - V_3 ;
}
static int F_2 ( struct V_1 * V_2 , char * V_3 )
{
char * V_4 = V_3 ;
int V_5 ;
struct V_6 * V_7 ;
struct V_15 * V_16 ;
struct V_17 * V_17 ;
V_17 = V_2 -> V_17 ;
while ( V_17 ) {
V_16 = F_3 ( V_17 -> V_18 , V_17 -> V_19 , 0 ) ;
if ( ! V_16 )
break;
V_4 += sprintf ( V_4 , L_6 ) ;
V_5 = 11 ;
V_7 = V_16 -> V_8 ;
while ( V_7 && V_5 -- ) {
V_4 += sprintf ( V_4 , L_2 , V_7 -> V_9 , V_7 -> V_10 ) ;
V_7 = V_7 -> V_11 ;
}
V_4 += sprintf ( V_4 , L_7 ) ;
V_5 = 11 ;
V_7 = V_16 -> V_12 ;
while ( V_7 && V_5 -- ) {
V_4 += sprintf ( V_4 , L_2 , V_7 -> V_9 , V_7 -> V_10 ) ;
V_7 = V_7 -> V_11 ;
}
V_4 += sprintf ( V_4 , L_8 ) ;
V_5 = 11 ;
V_7 = V_16 -> V_13 ;
while ( V_7 && V_5 -- ) {
V_4 += sprintf ( V_4 , L_2 , V_7 -> V_9 , V_7 -> V_10 ) ;
V_7 = V_7 -> V_11 ;
}
V_4 += sprintf ( V_4 , L_9 ) ;
V_5 = 11 ;
V_7 = V_16 -> V_14 ;
while ( V_7 && V_5 -- ) {
V_4 += sprintf ( V_4 , L_2 , V_7 -> V_9 , V_7 -> V_10 ) ;
V_7 = V_7 -> V_11 ;
}
V_17 = V_17 -> V_11 ;
}
return V_4 - V_3 ;
}
static int F_4 ( struct V_1 * V_2 , char * V_20 , int V_21 )
{
int V_22 ;
V_22 = V_21 - F_1 ( V_2 , V_20 ) ;
V_22 = ( V_21 - V_22 ) - F_2 ( V_2 , & V_20 [ V_22 ] ) ;
return V_22 ;
}
static int F_5 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_26 * V_27 ;
int V_28 = - V_29 ;
F_6 ( & V_30 ) ;
V_27 = F_7 ( sizeof( * V_27 ) , V_31 ) ;
if ( ! V_27 )
goto exit;
V_27 -> V_20 = F_7 ( V_32 , V_31 ) ;
if ( ! V_27 -> V_20 ) {
F_8 ( V_27 ) ;
goto exit;
}
V_27 -> V_21 = F_4 ( V_2 , V_27 -> V_20 , V_32 ) ;
V_24 -> V_33 = V_27 ;
V_28 = 0 ;
exit:
F_9 ( & V_30 ) ;
return V_28 ;
}
static T_1 F_10 ( struct V_24 * V_24 , T_1 V_34 , int V_35 )
{
struct V_26 * V_27 = V_24 -> V_33 ;
return F_11 ( V_24 , V_34 , V_35 , V_27 -> V_21 ) ;
}
static T_2 F_12 ( struct V_24 * V_24 , char T_3 * V_3 ,
T_4 V_36 , T_1 * V_37 )
{
struct V_26 * V_27 = V_24 -> V_33 ;
return F_13 ( V_3 , V_36 , V_37 , V_27 -> V_20 , V_27 -> V_21 ) ;
}
static int F_14 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
struct V_26 * V_27 = V_24 -> V_33 ;
F_8 ( V_27 -> V_20 ) ;
F_8 ( V_27 ) ;
return 0 ;
}
void F_15 ( void )
{
if ( ! V_38 )
V_38 = F_16 ( L_10 , NULL ) ;
}
void F_17 ( void )
{
F_18 ( V_38 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_39 = F_20 ( F_21 ( & V_2 -> V_40 -> V_41 ) ,
V_42 , V_38 , V_2 , & V_43 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
}
