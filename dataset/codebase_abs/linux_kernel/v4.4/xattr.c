T_1 F_1 ( struct V_1 * V_2 , const char * V_3 ,
void * V_4 , T_2 V_5 )
{
T_1 V_6 ;
T_3 V_7 ;
struct V_1 * V_8 ;
struct V_9 V_9 = { . V_10 = V_4 , . V_11 = V_5 } ;
struct V_12 V_13 ;
int V_14 ;
F_2 ( & V_13 , V_15 | V_16 , & V_9 , 1 , V_5 ) ;
V_8 = F_3 ( V_2 , V_3 , & V_7 ) ;
if ( F_4 ( V_8 ) ) {
V_6 = F_5 ( V_8 ) ;
F_6 ( V_17 , L_1 ,
V_6 ) ;
return V_6 ;
}
if ( V_7 > V_5 ) {
if ( ! V_5 )
V_6 = V_7 ;
else
V_6 = - V_18 ;
} else {
F_7 ( & V_13 , V_7 ) ;
V_6 = F_8 ( V_8 , 0 , & V_13 , & V_14 ) ;
if ( V_14 )
V_6 = V_14 ;
}
F_9 ( V_8 ) ;
return V_6 ;
}
T_1 F_10 ( struct V_19 * V_19 , const char * V_3 ,
void * V_4 , T_2 V_5 )
{
struct V_1 * V_2 ;
F_6 ( V_17 , L_2 ,
V_3 , V_5 ) ;
V_2 = F_11 ( V_19 ) ;
if ( F_4 ( V_2 ) )
return F_5 ( V_2 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
int F_12 ( struct V_19 * V_19 , const char * V_3 ,
const void * V_20 , T_2 V_21 , int V_22 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
if ( F_4 ( V_2 ) )
return F_5 ( V_2 ) ;
return F_13 ( V_2 , V_3 , V_20 , V_21 , V_22 ) ;
}
int F_13 ( struct V_1 * V_2 , const char * V_3 ,
const void * V_20 , T_2 V_21 , int V_22 )
{
struct V_9 V_9 = { . V_10 = ( void * ) V_20 , . V_11 = V_21 } ;
struct V_12 V_23 ;
int V_6 ;
F_2 ( & V_23 , V_24 | V_16 , & V_9 , 1 , V_21 ) ;
F_6 ( V_17 , L_3 ,
V_3 , V_21 , V_22 ) ;
V_2 = F_14 ( V_2 , 0 , NULL , 1 ) ;
if ( F_4 ( V_2 ) )
return F_5 ( V_2 ) ;
V_6 = F_15 ( V_2 , V_3 , V_21 , V_22 ) ;
if ( V_6 < 0 )
F_6 ( V_17 , L_4 ,
V_6 ) ;
else
F_16 ( V_2 , 0 , & V_23 , & V_6 ) ;
F_9 ( V_2 ) ;
return V_6 ;
}
T_1 F_17 ( struct V_19 * V_19 , char * V_4 , T_2 V_5 )
{
return F_10 ( V_19 , NULL , V_4 , V_5 ) ;
}
static int F_18 ( const struct V_25 * V_26 ,
struct V_19 * V_19 , const char * V_3 ,
void * V_4 , T_2 V_27 )
{
const char * V_28 = F_19 ( V_26 , V_3 ) ;
if ( strcmp ( V_3 , L_5 ) == 0 )
return - V_29 ;
return F_10 ( V_19 , V_28 , V_4 , V_27 ) ;
}
static int F_20 ( const struct V_25 * V_26 ,
struct V_19 * V_19 , const char * V_3 ,
const void * V_20 , T_2 V_27 , int V_22 )
{
const char * V_28 = F_19 ( V_26 , V_3 ) ;
if ( strcmp ( V_3 , L_5 ) == 0 )
return - V_29 ;
return F_12 ( V_19 , V_28 , V_20 , V_27 , V_22 ) ;
}
