static T_1 F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
T_1 V_3 ;
F_2 ( & V_1 -> V_4 ) ;
V_3 = * V_2 ;
F_3 ( & V_1 -> V_4 ) ;
return V_3 ;
}
static struct V_1 * F_4 ( struct V_5 * V_6 )
{
int V_7 ;
struct V_1 * V_1 = NULL ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_1 = & V_9 [ V_7 ] ;
if ( F_5 ( V_1 -> V_10 ) == V_6 )
break;
}
return V_1 ;
}
static T_2 F_6 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 , V_1 -> V_14 ) ;
}
static T_2 F_7 ( struct V_5 * V_6 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_15 )
{
int V_16 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
if ( V_1 -> V_17 ) {
F_8 ( L_2 ) ;
return - V_18 ;
}
V_16 = F_9 ( V_13 , 10 , & V_1 -> V_14 ) ;
if ( V_16 )
return V_16 ;
V_1 -> V_14 = F_10 ( V_1 -> V_14 ) ;
F_11 ( V_1 -> V_10 , V_1 -> V_14 >> V_19 ) ;
return V_15 ;
}
static T_2 F_12 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_3 , V_1 -> V_17 ) ;
}
static T_2 F_13 ( struct V_5 * V_6 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_15 )
{
int V_16 ;
unsigned long V_20 ;
struct V_1 * V_1 ;
struct V_21 * V_22 ;
V_1 = F_4 ( V_6 ) ;
V_22 = F_14 ( V_1 -> V_10 , 0 ) ;
if ( V_22 -> V_23 )
return - V_18 ;
V_16 = F_15 ( V_13 , 10 , & V_20 ) ;
if ( V_16 )
return V_16 ;
if ( ! V_20 )
return - V_24 ;
if ( V_22 )
F_16 ( V_22 ) ;
if ( V_1 -> V_17 )
F_17 ( V_1 ) ;
return V_15 ;
}
static T_2 F_18 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_25 . V_26 ) ) ;
}
static T_2 F_19 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_25 . V_27 ) ) ;
}
static T_2 F_20 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_25 . V_28 ) ) ;
}
static T_2 F_21 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_25 . V_29 ) ) ;
}
static T_2 F_22 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_3 , V_1 -> V_25 . V_30 ) ;
}
static T_2 F_23 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
( T_1 ) ( V_1 -> V_25 . V_31 ) << V_32 ) ;
}
static T_2 F_24 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_25 . V_33 ) ) ;
}
static T_2 F_25 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
T_1 V_3 = 0 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
if ( V_1 -> V_17 ) {
V_3 = F_26 ( V_1 -> V_34 ) +
( ( T_1 ) ( V_1 -> V_25 . V_35 ) << V_32 ) ;
}
return sprintf ( V_13 , L_1 , V_3 ) ;
}
