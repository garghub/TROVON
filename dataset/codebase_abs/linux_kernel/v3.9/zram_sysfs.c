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
for ( V_7 = 0 ; V_7 < F_5 () ; V_7 ++ ) {
V_1 = & V_8 [ V_7 ] ;
if ( F_6 ( V_1 -> V_9 ) == V_6 )
break;
}
return V_1 ;
}
static T_2 F_7 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_1 , V_1 -> V_13 ) ;
}
static T_2 F_8 ( struct V_5 * V_6 ,
struct V_10 * V_11 , const char * V_12 , T_3 V_14 )
{
T_1 V_13 ;
struct V_15 * V_16 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
V_13 = F_9 ( V_12 , NULL ) ;
if ( ! V_13 )
return - V_17 ;
V_13 = F_10 ( V_13 ) ;
V_16 = F_11 ( V_13 ) ;
F_12 ( & V_1 -> V_18 ) ;
if ( V_1 -> V_19 ) {
F_13 ( & V_1 -> V_18 ) ;
F_14 ( V_16 ) ;
F_15 ( L_2 ) ;
return - V_20 ;
}
V_1 -> V_13 = V_13 ;
F_16 ( V_1 -> V_9 , V_1 -> V_13 >> V_21 ) ;
F_17 ( V_1 , V_16 ) ;
F_13 ( & V_1 -> V_18 ) ;
return V_14 ;
}
static T_2 F_18 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_3 , V_1 -> V_19 ) ;
}
static T_2 F_19 ( struct V_5 * V_6 ,
struct V_10 * V_11 , const char * V_12 , T_3 V_14 )
{
int V_22 ;
unsigned short V_23 ;
struct V_1 * V_1 ;
struct V_24 * V_25 ;
V_1 = F_4 ( V_6 ) ;
V_25 = F_20 ( V_1 -> V_9 , 0 ) ;
if ( V_25 -> V_26 )
return - V_20 ;
V_22 = F_21 ( V_12 , 10 , & V_23 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_23 )
return - V_17 ;
if ( V_25 )
F_22 ( V_25 ) ;
F_23 ( V_1 ) ;
return V_14 ;
}
static T_2 F_24 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_1 ,
F_1 ( V_1 , & V_1 -> V_27 . V_28 ) ) ;
}
static T_2 F_25 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_1 ,
F_1 ( V_1 , & V_1 -> V_27 . V_29 ) ) ;
}
static T_2 F_26 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_1 ,
F_1 ( V_1 , & V_1 -> V_27 . V_30 ) ) ;
}
static T_2 F_27 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_1 ,
F_1 ( V_1 , & V_1 -> V_27 . V_31 ) ) ;
}
static T_2 F_28 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_3 , V_1 -> V_27 . V_32 ) ;
}
static T_2 F_29 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_1 ,
( T_1 ) ( V_1 -> V_27 . V_33 ) << V_34 ) ;
}
static T_2 F_30 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_1 * V_1 = F_4 ( V_6 ) ;
return sprintf ( V_12 , L_1 ,
F_1 ( V_1 , & V_1 -> V_27 . V_35 ) ) ;
}
static T_2 F_31 ( struct V_5 * V_6 ,
struct V_10 * V_11 , char * V_12 )
{
T_1 V_3 = 0 ;
struct V_1 * V_1 = F_4 ( V_6 ) ;
struct V_15 * V_16 = V_1 -> V_16 ;
if ( V_1 -> V_19 )
V_3 = F_32 ( V_16 -> V_36 ) ;
return sprintf ( V_12 , L_1 , V_3 ) ;
}
