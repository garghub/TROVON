static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 , unsigned char V_5 ,
void * V_6 , int V_7 )
{
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
V_3 ,
V_8 | V_9 | V_10 ,
V_4 ,
V_5 , V_6 , V_7 ,
V_11 ) ;
}
static T_1 F_4 ( struct V_12 * V_2 , struct V_13 * V_14 , char * V_6 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
return sprintf ( V_6 , L_1 , V_18 -> V_19 ) ;
}
static T_1 F_7 ( struct V_12 * V_2 , struct V_13 * V_14 , const char * V_6 ,
T_2 V_20 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
unsigned char * V_21 ;
int V_22 ;
V_21 = F_8 ( 8 , V_23 ) ;
if ( ! V_21 ) {
F_9 ( & V_18 -> V_24 -> V_2 , L_2 ) ;
return 0 ;
}
V_18 -> V_19 = F_10 ( V_6 , NULL , 10 ) ;
if ( V_18 -> V_19 > 0xFF )
V_18 -> V_19 = 0xFF ;
else if ( V_18 -> V_19 < 0 )
V_18 -> V_19 = 0 ;
V_22 = F_1 ( V_18 -> V_24 , V_25 , V_26 ,
V_18 -> V_19 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
V_22 = F_1 ( V_18 -> V_24 , V_25 , V_27 ,
0x01 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
F_12 ( V_21 ) ;
return V_20 ;
}
static T_1 F_13 ( struct V_12 * V_2 , struct V_13 * V_14 , char * V_6 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
int V_22 ;
unsigned char * V_21 ;
int V_28 , V_29 ;
V_21 = F_8 ( 8 , V_23 ) ;
if ( ! V_21 ) {
F_9 ( & V_18 -> V_24 -> V_2 , L_2 ) ;
return 0 ;
}
V_22 = F_1 ( V_18 -> V_24 , V_30 , V_31 , 0 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
V_28 = V_21 [ 1 ] ;
V_22 = F_1 ( V_18 -> V_24 , V_30 , V_32 , 0 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
V_29 = V_21 [ 1 ] ;
F_12 ( V_21 ) ;
return sprintf ( V_6 , L_4 , V_29 ? '-' : '+' , V_28 >> 1 ,
5 * ( V_28 - ( ( V_28 >> 1 ) << 1 ) ) ) ;
}
static T_1 F_14 ( struct V_12 * V_2 , struct V_13 * V_14 , const char * V_6 , T_2 V_20 )
{
return V_20 ;
}
static T_1 F_15 ( struct V_12 * V_2 , struct V_13 * V_14 , char * V_6 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
int V_22 ;
unsigned char * V_21 ;
V_21 = F_8 ( 8 , V_23 ) ;
if ( ! V_21 ) {
F_9 ( & V_18 -> V_24 -> V_2 , L_2 ) ;
return 0 ;
}
V_22 = F_1 ( V_18 -> V_24 , V_30 , V_33 , 0 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
V_22 = V_21 [ 1 ] ;
F_12 ( V_21 ) ;
if ( V_22 )
return sprintf ( V_6 , L_5 ) ;
else
return sprintf ( V_6 , L_6 ) ;
}
static T_1 F_16 ( struct V_12 * V_2 , struct V_13 * V_14 , const char * V_6 , T_2 V_20 )
{
return V_20 ;
}
static T_1 F_17 ( struct V_12 * V_2 , struct V_13 * V_14 , char * V_6 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
int V_22 ;
unsigned char * V_21 ;
V_21 = F_8 ( 8 , V_23 ) ;
if ( ! V_21 ) {
F_9 ( & V_18 -> V_24 -> V_2 , L_2 ) ;
return 0 ;
}
V_22 = F_1 ( V_18 -> V_24 , V_34 , 0 , 0 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
V_22 = V_21 [ 1 ] ;
F_12 ( V_21 ) ;
return sprintf ( V_6 , L_7 , V_22 ) ;
}
static T_1 F_18 ( struct V_12 * V_2 , struct V_13 * V_14 , const char * V_6 , T_2 V_20 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
unsigned char * V_21 ;
int V_22 ;
int V_35 ;
V_21 = F_8 ( 8 , V_23 ) ;
if ( ! V_21 ) {
F_9 ( & V_18 -> V_24 -> V_2 , L_2 ) ;
return 0 ;
}
V_35 = F_10 ( V_6 , NULL , 10 ) ;
if ( V_35 > 0xFF )
V_35 = 0xFF ;
else if ( V_35 < 0 )
V_35 = 0 ;
V_22 = F_1 ( V_18 -> V_24 , V_36 , 0 ,
V_35 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
F_12 ( V_21 ) ;
return V_20 ;
}
static T_1 F_19 ( struct V_12 * V_2 , struct V_13 * V_14 , char * V_6 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
int V_22 ;
unsigned char * V_21 ;
V_21 = F_8 ( 8 , V_23 ) ;
if ( ! V_21 ) {
F_9 ( & V_18 -> V_24 -> V_2 , L_2 ) ;
return 0 ;
}
V_22 = F_1 ( V_18 -> V_24 , V_34 , 1 , 0 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
V_22 = V_21 [ 1 ] ;
F_12 ( V_21 ) ;
return sprintf ( V_6 , L_7 , V_22 ) ;
}
static T_1 F_20 ( struct V_12 * V_2 , struct V_13 * V_14 , const char * V_6 , T_2 V_20 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
unsigned char * V_21 ;
int V_22 ;
int V_35 ;
V_21 = F_8 ( 8 , V_23 ) ;
if ( ! V_21 ) {
F_9 ( & V_18 -> V_24 -> V_2 , L_2 ) ;
return 0 ;
}
V_35 = F_10 ( V_6 , NULL , 10 ) ;
if ( V_35 > 0xFF )
V_35 = 0xFF ;
else if ( V_35 < 0 )
V_35 = 0 ;
V_22 = F_1 ( V_18 -> V_24 , V_36 , 1 ,
V_35 , V_21 , 8 ) ;
if ( V_22 )
F_11 ( & V_18 -> V_24 -> V_2 , L_3 , V_22 ) ;
F_12 ( V_21 ) ;
return V_20 ;
}
static int F_21 ( struct V_15 * V_37 ,
const struct V_38 * V_39 )
{
struct V_1 * V_24 = F_22 ( V_37 ) ;
struct V_17 * V_2 = NULL ;
int V_22 = - V_40 ;
V_2 = F_23 ( sizeof( struct V_17 ) , V_23 ) ;
if ( V_2 == NULL ) {
F_9 ( & V_37 -> V_2 , L_8 ) ;
goto V_41;
}
V_2 -> V_24 = F_24 ( V_24 ) ;
F_25 ( V_37 , V_2 ) ;
V_2 -> V_19 = 0xFF ;
V_22 = F_26 ( & V_37 -> V_2 , & V_42 ) ;
if ( V_22 )
goto error;
V_22 = F_26 ( & V_37 -> V_2 , & V_43 ) ;
if ( V_22 )
goto error;
V_22 = F_26 ( & V_37 -> V_2 , & V_44 ) ;
if ( V_22 )
goto error;
V_22 = F_26 ( & V_37 -> V_2 , & V_45 ) ;
if ( V_22 )
goto error;
V_22 = F_26 ( & V_37 -> V_2 , & V_46 ) ;
if ( V_22 )
goto error;
F_27 ( & V_37 -> V_2 ,
L_9 ) ;
return 0 ;
error:
F_28 ( & V_37 -> V_2 , & V_42 ) ;
F_28 ( & V_37 -> V_2 , & V_43 ) ;
F_28 ( & V_37 -> V_2 , & V_44 ) ;
F_28 ( & V_37 -> V_2 , & V_45 ) ;
F_28 ( & V_37 -> V_2 , & V_46 ) ;
F_25 ( V_37 , NULL ) ;
F_29 ( V_2 -> V_24 ) ;
F_12 ( V_2 ) ;
V_41:
return V_22 ;
}
static void F_30 ( struct V_15 * V_37 )
{
struct V_17 * V_2 ;
V_2 = F_6 ( V_37 ) ;
F_28 ( & V_37 -> V_2 , & V_42 ) ;
F_28 ( & V_37 -> V_2 , & V_43 ) ;
F_28 ( & V_37 -> V_2 , & V_44 ) ;
F_28 ( & V_37 -> V_2 , & V_45 ) ;
F_28 ( & V_37 -> V_2 , & V_46 ) ;
F_25 ( V_37 , NULL ) ;
F_29 ( V_2 -> V_24 ) ;
F_12 ( V_2 ) ;
F_27 ( & V_37 -> V_2 , L_10 ) ;
}
