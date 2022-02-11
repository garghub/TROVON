static T_1 F_1 (
struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_3 ;
struct V_7 * V_8 ;
V_3 = F_2 ( V_4 ) ;
V_8 = F_3 ( V_2 ) ;
if ( ! V_3 -> V_9 )
return - V_10 ;
return V_3 -> V_9 ( V_8 , V_3 , V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_3 ;
struct V_7 * V_8 ;
V_3 = F_2 ( V_4 ) ;
V_8 = F_3 ( V_2 ) ;
if ( ! V_3 -> V_12 )
return - V_10 ;
return V_3 -> V_12 ( V_8 , V_3 , V_5 , V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
F_6 ( L_1 , V_8 -> V_13 ) ;
F_7 ( V_8 ) ;
}
static T_1 F_8 (
struct V_7 * V_8 ,
struct V_6 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_2 , V_8 -> V_14 . V_15 ) ;
}
static T_1 F_9 (
struct V_7 * V_8 ,
struct V_6 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 , V_8 -> V_14 . V_16 ) ;
}
static T_1 F_10 (
struct V_7 * V_8 ,
struct V_6 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 , V_8 -> V_14 . V_17 ) ;
}
static T_1 F_11 (
struct V_7 * V_8 ,
struct V_6 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 , V_8 -> V_14 . V_18 ) ;
}
static T_1 F_12 (
struct V_7 * V_8 ,
struct V_6 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_4 , V_8 -> V_14 . V_19 ) ;
}
static T_1 F_13 (
struct V_7 * V_8 ,
struct V_6 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_4 , V_8 -> V_14 . V_20 ) ;
}
static void F_14 ( struct V_7 * V_8 )
{
char V_21 [ 128 ] ;
char V_22 [ 64 ] ;
char V_23 [ 64 ] ;
char V_24 [ 64 ] ;
char V_25 [ 64 ] ;
char V_26 [ 64 ] ;
char * V_27 [] = {
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
NULL
} ;
snprintf ( V_21 , 128 , L_5 , V_8 -> V_14 . V_15 ) ;
snprintf ( V_22 , 64 , L_6 , V_8 -> V_14 . V_16 ) ;
snprintf ( V_23 , 64 , L_7 , V_8 -> V_14 . V_17 ) ;
snprintf ( V_24 , 64 , L_8 , V_8 -> V_14 . V_18 ) ;
snprintf ( V_25 , 64 , L_9 ,
V_8 -> V_14 . V_19 ) ;
snprintf ( V_26 , 64 , L_10 ,
V_8 -> V_14 . V_20 ) ;
F_15 ( & V_8 -> V_2 , V_28 , V_27 ) ;
}
int F_16 (
struct V_7 * * V_8 ,
struct V_29 * V_30 ,
int V_13 , struct V_31 * V_14 )
{
int V_32 ;
struct V_7 * V_33 ;
V_33 = F_17 ( sizeof( * V_33 ) , V_34 ) ;
if ( ! V_33 )
return - V_35 ;
F_18 ( & V_33 -> V_36 ) ;
V_33 -> V_13 = V_13 ;
memcpy ( & V_33 -> V_14 , V_14 , sizeof( * V_14 ) ) ;
V_33 -> V_2 . V_29 = V_30 ;
V_32 = F_19 ( & V_33 -> V_2 , & V_37 , NULL , L_3 ,
V_13 ) ;
if ( V_32 ) {
F_20 ( L_11 ,
V_13 ) ;
F_21 ( & V_33 -> V_2 ) ;
return V_32 ;
}
F_14 ( V_33 ) ;
* V_8 = V_33 ;
F_6 ( L_12 , V_13 ) ;
return 0 ;
}
void F_22 ( struct V_7 * V_8 )
{
F_6 ( L_13 ,
V_8 -> V_13 ,
V_8 -> V_14 . V_15 ,
V_8 -> V_14 . V_16 ,
V_8 -> V_14 . V_17 ,
V_8 -> V_14 . V_18 ,
V_8 -> V_14 . V_19 ,
V_8 -> V_14 . V_20 ) ;
}
