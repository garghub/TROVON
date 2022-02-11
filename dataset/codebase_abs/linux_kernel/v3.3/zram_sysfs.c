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
T_1 V_14 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
V_16 = F_8 ( V_13 , 10 , & V_14 ) ;
if ( V_16 )
return V_16 ;
F_9 ( & V_1 -> V_17 ) ;
if ( V_1 -> V_18 ) {
F_10 ( & V_1 -> V_17 ) ;
F_11 ( L_2 ) ;
return - V_19 ;
}
V_1 -> V_14 = F_12 ( V_14 ) ;
F_13 ( V_1 -> V_10 , V_1 -> V_14 >> V_20 ) ;
F_10 ( & V_1 -> V_17 ) ;
return V_15 ;
}
static T_2 F_14 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_3 , V_1 -> V_18 ) ;
}
static T_2 F_15 ( struct V_5 * V_6 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_15 )
{
int V_16 ;
unsigned short V_21 ;
struct V_1 * V_1 ;
struct V_22 * V_23 ;
V_1 = F_4 ( V_6 ) ;
V_23 = F_16 ( V_1 -> V_10 , 0 ) ;
if ( V_23 -> V_24 )
return - V_19 ;
V_16 = F_17 ( V_13 , 10 , & V_21 ) ;
if ( V_16 )
return V_16 ;
if ( ! V_21 )
return - V_25 ;
if ( V_23 )
F_18 ( V_23 ) ;
F_9 ( & V_1 -> V_17 ) ;
if ( V_1 -> V_18 )
F_19 ( V_1 ) ;
F_10 ( & V_1 -> V_17 ) ;
return V_15 ;
}
static T_2 F_20 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_26 . V_27 ) ) ;
}
static T_2 F_21 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_26 . V_28 ) ) ;
}
static T_2 F_22 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_26 . V_29 ) ) ;
}
static T_2 F_23 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_26 . V_30 ) ) ;
}
static T_2 F_24 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_3 , V_1 -> V_26 . V_31 ) ;
}
static T_2 F_25 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
( T_1 ) ( V_1 -> V_26 . V_32 ) << V_33 ) ;
}
static T_2 F_26 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_13 , L_1 ,
F_1 ( V_1 , & V_1 -> V_26 . V_34 ) ) ;
}
static T_2 F_27 ( struct V_5 * V_6 ,
struct V_11 * V_12 , char * V_13 )
{
T_1 V_3 = 0 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
if ( V_1 -> V_18 ) {
V_3 = F_28 ( V_1 -> V_35 ) +
( ( T_1 ) ( V_1 -> V_26 . V_36 ) << V_33 ) ;
}
return sprintf ( V_13 , L_1 , V_3 ) ;
}
