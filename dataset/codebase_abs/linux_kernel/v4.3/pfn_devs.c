static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
F_4 ( V_2 , L_1 , V_6 ) ;
F_5 ( & V_5 -> V_2 , & V_5 -> V_7 ) ;
F_6 ( & V_3 -> V_8 , V_5 -> V_9 ) ;
F_7 ( V_5 -> V_10 ) ;
F_7 ( V_5 ) ;
}
bool F_8 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_11 : false ;
}
struct V_5 * F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_9 ( V_2 , struct V_5 , V_2 ) ;
F_10 ( ! F_8 ( V_2 ) ) ;
return V_5 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
switch ( V_5 -> V_15 ) {
case V_16 :
return sprintf ( V_14 , L_2 ) ;
case V_17 :
return sprintf ( V_14 , L_3 ) ;
default:
return sprintf ( V_14 , L_4 ) ;
}
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 = 0 ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_20 )
V_19 = - V_21 ;
else {
T_2 V_22 = V_18 - 1 ;
if ( strncmp ( V_14 , L_3 , V_22 ) == 0
|| strncmp ( V_14 , L_5 , V_22 ) == 0 ) {
V_19 = - V_23 ;
} else if ( strncmp ( V_14 , L_2 , V_22 ) == 0
|| strncmp ( V_14 , L_6 , V_22 ) == 0 )
V_5 -> V_15 = V_16 ;
else if ( strncmp ( V_14 , L_4 , V_22 ) == 0
|| strncmp ( V_14 , L_7 , V_22 ) == 0 )
V_5 -> V_15 = V_24 ;
else
V_19 = - V_25 ;
}
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( V_5 -> V_10 )
return sprintf ( V_14 , L_11 , V_5 -> V_10 ) ;
return sprintf ( V_14 , L_10 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_13 ( V_2 ) ;
V_19 = F_19 ( V_2 , & V_5 -> V_10 , V_14 , V_18 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_16 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
V_19 = sprintf ( V_14 , L_1 , V_5 -> V_7
? F_21 ( & V_5 -> V_7 -> V_2 ) : L_9 ) ;
F_15 ( V_2 ) ;
return V_19 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_19 = F_23 ( V_2 , & V_5 -> V_7 , V_14 , V_18 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_19 ;
}
static struct V_1 * F_24 ( struct V_3 * V_3 ,
T_3 * V_10 , enum V_26 V_15 ,
struct V_27 * V_7 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
if ( ! F_25 ( & V_3 -> V_2 ) )
return NULL ;
V_5 = F_26 ( sizeof( * V_5 ) , V_28 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = F_27 ( & V_3 -> V_8 , 0 , 0 , V_28 ) ;
if ( V_5 -> V_9 < 0 ) {
F_7 ( V_5 ) ;
return NULL ;
}
V_5 -> V_15 = V_15 ;
if ( V_10 )
V_10 = F_28 ( V_10 , 16 , V_28 ) ;
V_5 -> V_10 = V_10 ;
V_2 = & V_5 -> V_2 ;
F_29 ( V_2 , L_12 , V_3 -> V_9 , V_5 -> V_9 ) ;
V_2 -> V_4 = & V_3 -> V_2 ;
V_2 -> type = & V_11 ;
V_2 -> V_29 = V_30 ;
F_30 ( & V_5 -> V_2 ) ;
if ( V_7 && ! F_31 ( & V_5 -> V_2 , V_7 , & V_5 -> V_7 ) ) {
F_4 ( & V_7 -> V_2 , L_13 ,
V_6 , F_21 ( V_7 -> V_31 ) ) ;
F_32 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
struct V_1 * F_33 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_24 ( V_3 , NULL , V_24 ,
NULL ) ;
if ( V_2 )
F_34 ( V_2 ) ;
return V_2 ;
}
int F_35 ( struct V_5 * V_5 )
{
struct V_27 * V_7 = V_5 -> V_7 ;
struct V_32 * V_33 = V_5 -> V_33 ;
struct V_34 * V_35 ;
T_4 V_36 , V_37 ;
if ( ! V_33 || ! V_7 )
return - V_38 ;
if ( ! F_25 ( V_5 -> V_2 . V_4 ) )
return - V_38 ;
if ( F_36 ( V_7 ) < V_39 )
return - V_38 ;
if ( F_37 ( V_7 , V_40 , V_33 , sizeof( * V_33 ) ) )
return - V_41 ;
if ( memcmp ( V_33 -> V_42 , V_43 , V_44 ) != 0 )
return - V_38 ;
V_36 = F_38 ( V_33 -> V_36 ) ;
V_33 -> V_36 = 0 ;
if ( V_36 != F_39 ( (struct V_45 * ) V_33 ) )
return - V_38 ;
V_33 -> V_36 = F_40 ( V_36 ) ;
switch ( F_41 ( V_33 -> V_15 ) ) {
case V_16 :
break;
case V_17 :
return - V_23 ;
default:
return - V_41 ;
}
if ( ! V_5 -> V_10 ) {
V_5 -> V_10 = F_28 ( V_33 -> V_10 , 16 , V_28 ) ;
if ( ! V_5 -> V_10 )
return - V_46 ;
} else {
if ( memcmp ( V_5 -> V_10 , V_33 -> V_10 , 16 ) != 0 )
return - V_25 ;
}
V_37 = F_38 ( V_33 -> V_47 ) ;
V_35 = F_42 ( & V_7 -> V_2 ) ;
if ( V_35 -> V_48 . V_49 & V_50 ) {
F_43 ( & V_5 -> V_2 ,
L_14 ,
F_21 ( & V_7 -> V_2 ) ) ;
return - V_21 ;
} else if ( V_37 >= F_44 ( & V_35 -> V_48 ) ) {
F_43 ( & V_5 -> V_2 , L_15 ,
F_21 ( & V_7 -> V_2 ) ) ;
return - V_21 ;
}
return 0 ;
}
int F_45 ( struct V_27 * V_7 , void * V_51 )
{
int V_19 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
struct V_32 * V_33 ;
struct V_3 * V_3 = F_2 ( V_7 -> V_2 . V_4 ) ;
if ( V_7 -> V_52 )
return - V_38 ;
F_14 ( & V_7 -> V_2 ) ;
V_2 = F_24 ( V_3 , NULL , V_24 , V_7 ) ;
F_15 ( & V_7 -> V_2 ) ;
if ( ! V_2 )
return - V_46 ;
F_46 ( V_2 , V_51 ) ;
V_33 = F_26 ( sizeof( * V_33 ) , V_28 ) ;
V_5 = F_3 ( V_2 ) ;
V_5 -> V_33 = V_33 ;
V_19 = F_35 ( V_5 ) ;
V_5 -> V_33 = NULL ;
F_7 ( V_33 ) ;
F_4 ( & V_7 -> V_2 , L_16 , V_6 ,
V_19 == 0 ? F_21 ( V_2 ) : L_17 ) ;
if ( V_19 < 0 ) {
F_47 ( V_2 , & V_5 -> V_7 ) ;
F_32 ( V_2 ) ;
} else
F_34 ( & V_5 -> V_2 ) ;
return V_19 ;
}
