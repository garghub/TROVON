static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 , unsigned char V_5 )
{
int V_6 = 0 ;
unsigned int V_7 ;
unsigned char * V_8 ;
V_8 = F_2 ( V_9 , V_10 ) ;
if ( ! V_8 ) {
V_6 = - V_11 ;
goto error;
}
F_3 ( & V_2 -> V_12 -> V_2 , L_1 , V_5 ) ;
V_7 = F_4 ( V_2 -> V_12 , 0 ) ;
V_6 = F_5 ( V_2 -> V_12 , V_7 , V_3 ,
V_13 | V_14 | V_15 ,
V_4 , V_5 , V_8 , V_9 ,
V_16 ) ;
switch ( V_3 ) {
case V_17 :
if ( V_4 == V_18 ) {
V_2 -> V_19 [ 0 ] = V_8 [ 1 ] ;
F_3 ( & V_2 -> V_12 -> V_2 ,
L_2 ,
V_2 -> V_19 [ 0 ] ) ;
}
else if ( V_4 == V_20 ) {
V_2 -> V_19 [ 1 ] = V_8 [ 1 ] ;
F_3 ( & V_2 -> V_12 -> V_2 ,
L_3 ,
V_2 -> V_19 [ 1 ] ) ;
}
break;
}
F_6 ( V_8 ) ;
error:
return V_6 ;
}
static T_1 F_7 ( struct V_21 * V_2 , struct V_22 * V_23 ,
const char * V_24 , T_2 V_25 ,
int V_26 , int V_27 )
{
int V_28 = - 1 ;
int V_29 = 0 ;
struct V_30 * V_31 = F_8 ( V_2 ) ;
struct V_1 * V_32 = F_9 ( V_31 ) ;
F_3 ( & V_32 -> V_12 -> V_2 , L_4 , V_26 ) ;
if ( sscanf ( V_24 , L_5 , & V_28 ) < 1 ) {
V_29 = - V_33 ;
goto error;
}
if ( V_28 < 0 || V_28 > 255 ) {
V_29 = - V_33 ;
goto error;
}
V_29 = F_1 ( V_32 , V_34 , V_27 ,
( unsigned char ) V_28 ) ;
F_3 ( & V_32 -> V_12 -> V_2 , L_6 , V_29 ) ;
error:
return V_29 < 0 ? V_29 : V_25 ;
}
static T_1 F_10 ( struct V_21 * V_2 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_25 )
{
return F_7 ( V_2 , V_23 , V_24 , V_25 , 0 , V_35 ) ;
}
static T_1 F_11 ( struct V_21 * V_2 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_25 )
{
return F_7 ( V_2 , V_23 , V_24 , V_25 , 1 , V_36 ) ;
}
static T_1 F_12 ( struct V_21 * V_2 , struct V_22 * V_23 ,
char * V_24 , int V_26 , int V_37 )
{
int V_29 = 0 ;
struct V_30 * V_31 = F_8 ( V_2 ) ;
struct V_1 * V_32 = F_9 ( V_31 ) ;
F_3 ( & V_32 -> V_12 -> V_2 , L_7 , V_26 ) ;
V_29 = F_1 ( V_32 , V_17 , V_37 , 0 ) ;
F_3 ( & V_32 -> V_12 -> V_2 , L_6 , V_29 ) ;
return sprintf ( V_24 , L_5 , V_32 -> V_19 [ V_26 ] ) ;
}
static T_1 F_13 ( struct V_21 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
return F_12 ( V_2 , V_23 , V_24 , 0 , V_18 ) ;
}
static T_1 F_14 ( struct V_21 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
return F_12 ( V_2 , V_23 , V_24 , 1 , V_20 ) ;
}
static int F_15 ( struct V_30 * V_38 ,
const struct V_39 * V_40 )
{
struct V_1 * V_2 = NULL ;
int V_6 = - V_11 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
goto V_41;
V_2 -> V_12 = F_16 ( F_17 ( V_38 ) ) ;
F_18 ( V_38 , V_2 ) ;
V_6 = F_19 ( & V_38 -> V_2 , & V_42 ) ;
if ( V_6 )
goto error;
V_6 = F_19 ( & V_38 -> V_2 , & V_43 ) ;
if ( V_6 )
goto error;
F_20 ( & V_38 -> V_2 ,
L_8 ) ;
return 0 ;
error:
F_21 ( & V_38 -> V_2 , & V_42 ) ;
F_21 ( & V_38 -> V_2 , & V_43 ) ;
F_18 ( V_38 , NULL ) ;
F_22 ( V_2 -> V_12 ) ;
F_6 ( V_2 ) ;
V_41:
return V_6 ;
}
static void F_23 ( struct V_30 * V_38 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_38 ) ;
F_21 ( & V_38 -> V_2 , & V_42 ) ;
F_21 ( & V_38 -> V_2 , & V_43 ) ;
F_18 ( V_38 , NULL ) ;
F_22 ( V_2 -> V_12 ) ;
F_20 ( & V_38 -> V_2 ,
L_9 ) ;
F_6 ( V_2 ) ;
}
