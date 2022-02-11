static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , char * V_5 )
{
int V_6 = F_2 ( V_2 -> V_7 , V_3 , V_4 ) ;
if ( V_6 < 0 )
F_3 ( & V_2 -> V_7 -> V_8 ,
L_1 ,
V_6 , V_5 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , char * V_5 )
{
int V_6 = F_5 ( V_2 -> V_7 , V_3 ) ;
if ( V_6 < 0 )
F_3 ( & V_2 -> V_7 -> V_8 ,
L_2 ,
V_6 , V_5 ) ;
return V_6 ;
}
static T_2 F_6 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_15 , V_16 ;
V_15 = F_4 ( V_2 , V_17 , L_3 ) ;
if ( V_15 < 0 )
return V_15 ;
V_16 = F_4 ( V_2 , V_18 , L_4 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_12 , L_5 , ( V_16 << 8 ) | V_15 ) ;
}
static T_2 F_9 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_19 ;
V_19 = F_4 ( V_2 , V_20 , L_6 ) ;
if ( V_19 < 0 )
return V_19 ;
return sprintf ( V_12 , L_5 , V_19 & V_21 ) ;
}
static T_2 F_10 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 , T_3 V_22 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
unsigned long V_4 ;
int error ;
error = F_11 ( V_12 , 0 , & V_4 ) ;
if ( error )
return error ;
if ( V_4 < V_23 || V_4 > V_24 )
return - V_25 ;
F_12 ( & V_2 -> V_26 ) ;
error = F_1 ( V_2 , V_20 , V_4 , L_6 ) ;
if ( error < 0 ) {
F_13 ( & V_2 -> V_26 ) ;
return error ;
}
F_14 ( V_27 ) ;
V_2 -> V_28 = V_4 ;
F_13 ( & V_2 -> V_26 ) ;
return V_22 ;
}
static int F_15 ( struct V_29 * V_7 ,
const struct V_30 * V_31 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
struct V_32 * V_33 = F_16 ( V_7 -> V_8 . V_34 ) ;
if ( ! F_17 ( V_33 , V_35 ) ) {
V_6 = - V_36 ;
goto V_37;
}
V_2 = F_18 ( sizeof( struct V_1 ) , V_38 ) ;
if ( V_2 == NULL ) {
V_6 = - V_39 ;
goto V_37;
}
V_2 -> V_7 = V_7 ;
F_19 ( V_7 , V_2 ) ;
V_6 = F_4 ( V_2 , V_40 , L_7 ) ;
if ( V_6 < 0 )
goto V_37;
F_20 ( & V_7 -> V_8 , L_8 ,
( V_6 & V_41 ) ) ;
F_21 ( & V_2 -> V_26 ) ;
V_6 = F_22 ( & V_7 -> V_8 . V_42 , & V_43 ) ;
if ( V_6 )
goto V_37;
return 0 ;
V_37:
F_23 ( V_2 ) ;
return V_6 ;
}
static int F_24 ( struct V_29 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_7 ) ;
F_26 ( & V_7 -> V_8 . V_42 , & V_43 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_8 )
{
struct V_1 * V_2 ;
int V_19 , V_6 ;
struct V_29 * V_7 = F_28 ( V_8 ) ;
V_2 = F_25 ( V_7 ) ;
V_19 = F_4 ( V_2 , V_20 , L_6 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_28 = V_19 & V_21 ;
V_6 = F_1 ( V_2 , V_20 , V_23 ,
L_6 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_8 )
{
struct V_1 * V_2 ;
int V_19 , V_6 ;
struct V_29 * V_7 = F_28 ( V_8 ) ;
V_2 = F_25 ( V_7 ) ;
V_19 = V_2 -> V_28 ;
V_6 = F_1 ( V_2 , V_20 , V_19 ,
L_6 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
