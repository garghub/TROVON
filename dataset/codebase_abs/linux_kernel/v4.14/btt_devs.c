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
return V_2 -> type == & V_11 ;
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
return F_12 ( V_5 -> V_15 , V_16 , V_14 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_17 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_18 = F_16 ( V_2 , V_14 , & V_5 -> V_15 ,
V_16 ) ;
F_4 ( V_2 , L_2 , V_6 ,
V_18 , V_14 , V_14 [ V_17 - 1 ] == '\n' ? L_3 : L_4 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
return V_18 ? V_18 : V_17 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( V_5 -> V_10 )
return sprintf ( V_14 , L_5 , V_5 -> V_10 ) ;
return sprintf ( V_14 , L_4 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_17 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_14 ( V_2 ) ;
V_18 = F_21 ( V_2 , & V_5 -> V_10 , V_14 , V_17 ) ;
F_4 ( V_2 , L_2 , V_6 ,
V_18 , V_14 , V_14 [ V_17 - 1 ] == '\n' ? L_3 : L_4 ) ;
F_18 ( V_2 ) ;
return V_18 ? V_18 : V_17 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_15 ( V_2 ) ;
V_18 = sprintf ( V_14 , L_1 , V_5 -> V_7
? F_23 ( & V_5 -> V_7 -> V_2 ) : L_3 ) ;
F_17 ( V_2 ) ;
return V_18 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_17 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_18 = F_25 ( V_2 , & V_5 -> V_7 , V_14 , V_17 ) ;
F_4 ( V_2 , L_2 , V_6 ,
V_18 , V_14 , V_14 [ V_17 - 1 ] == '\n' ? L_3 : L_4 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
return V_18 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_18 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_19 )
V_18 = sprintf ( V_14 , L_6 , V_5 -> V_20 ) ;
else {
V_18 = - V_21 ;
}
F_18 ( V_2 ) ;
return V_18 ;
}
static struct V_1 * F_27 ( struct V_3 * V_3 ,
unsigned long V_15 , T_3 * V_10 ,
struct V_22 * V_7 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_28 ( sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = F_29 ( & V_3 -> V_8 , 0 , 0 , V_23 ) ;
if ( V_5 -> V_9 < 0 ) {
F_7 ( V_5 ) ;
return NULL ;
}
V_5 -> V_15 = V_15 ;
if ( V_10 )
V_10 = F_30 ( V_10 , 16 , V_23 ) ;
V_5 -> V_10 = V_10 ;
V_2 = & V_5 -> V_2 ;
F_31 ( V_2 , L_7 , V_3 -> V_9 , V_5 -> V_9 ) ;
V_2 -> V_4 = & V_3 -> V_2 ;
V_2 -> type = & V_11 ;
V_2 -> V_24 = V_25 ;
F_32 ( & V_5 -> V_2 ) ;
if ( V_7 && ! F_33 ( & V_5 -> V_2 , V_7 , & V_5 -> V_7 ) ) {
F_4 ( & V_7 -> V_2 , L_8 ,
V_6 , F_23 ( V_7 -> V_26 ) ) ;
F_34 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
struct V_1 * F_35 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_27 ( V_3 , 0 , NULL , NULL ) ;
F_36 ( V_2 ) ;
return V_2 ;
}
bool F_37 ( struct V_5 * V_5 , struct V_27 * V_28 )
{
const T_3 * V_29 = F_38 ( & V_5 -> V_7 -> V_2 ) ;
T_4 V_30 ;
if ( memcmp ( V_28 -> V_31 , V_32 , V_33 ) != 0 )
return false ;
if ( ! F_39 ( ( V_34 * ) & V_28 -> V_29 ) )
if ( memcmp ( V_28 -> V_29 , V_29 , 16 ) != 0 )
return false ;
V_30 = F_40 ( V_28 -> V_30 ) ;
V_28 -> V_30 = 0 ;
if ( V_30 != F_41 ( (struct V_35 * ) V_28 ) )
return false ;
V_28 -> V_30 = F_42 ( V_30 ) ;
if ( ( F_43 ( V_28 -> V_36 ) & V_37 ) != 0 )
F_44 ( & V_5 -> V_2 , L_9 ) ;
return true ;
}
int F_45 ( struct V_5 * V_5 , struct V_22 * V_7 ,
struct V_27 * V_27 )
{
if ( V_7 -> V_38 == V_39 ) {
V_5 -> V_40 = 0 ;
V_5 -> V_41 = 2 ;
V_5 -> V_42 = 0 ;
if ( F_46 ( V_7 , 0 , V_27 , sizeof( * V_27 ) , 0 ) )
return - V_21 ;
if ( ! F_37 ( V_5 , V_27 ) )
return - V_43 ;
if ( ( F_47 ( V_27 -> V_41 ) != 2 ) ||
( F_47 ( V_27 -> V_42 ) != 0 ) )
return - V_43 ;
} else {
V_5 -> V_40 = V_44 ;
V_5 -> V_41 = 1 ;
V_5 -> V_42 = 1 ;
if ( F_46 ( V_7 , V_44 , V_27 , sizeof( * V_27 ) , 0 ) )
return - V_21 ;
if ( ! F_37 ( V_5 , V_27 ) )
return - V_43 ;
if ( ( F_47 ( V_27 -> V_41 ) != 1 ) ||
( F_47 ( V_27 -> V_42 ) != 1 ) )
return - V_43 ;
}
return 0 ;
}
static int F_48 ( struct V_5 * V_5 ,
struct V_22 * V_7 , struct V_27 * V_27 )
{
int V_18 ;
if ( ! V_27 || ! V_7 || ! V_5 )
return - V_43 ;
if ( F_49 ( V_7 ) < V_45 )
return - V_21 ;
V_18 = F_45 ( V_5 , V_7 , V_27 ) ;
if ( V_18 < 0 )
return V_18 ;
V_5 -> V_15 = F_43 ( V_27 -> V_46 ) ;
V_5 -> V_10 = F_30 ( V_27 -> V_10 , 16 , V_23 ) ;
if ( ! V_5 -> V_10 )
return - V_47 ;
F_36 ( & V_5 -> V_2 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 , struct V_22 * V_7 )
{
int V_18 ;
struct V_1 * V_48 ;
struct V_27 * V_27 ;
struct V_3 * V_3 = F_2 ( V_7 -> V_2 . V_4 ) ;
if ( V_7 -> V_49 )
return - V_43 ;
switch ( V_7 -> V_38 ) {
case V_50 :
case V_51 :
case V_39 :
break;
default:
return - V_43 ;
}
F_15 ( & V_7 -> V_2 ) ;
V_48 = F_27 ( V_3 , 0 , NULL , V_7 ) ;
F_17 ( & V_7 -> V_2 ) ;
if ( ! V_48 )
return - V_47 ;
V_27 = F_51 ( V_2 , sizeof( * V_27 ) , V_23 ) ;
V_18 = F_48 ( F_3 ( V_48 ) , V_7 , V_27 ) ;
F_4 ( V_2 , L_10 , V_6 ,
V_18 == 0 ? F_23 ( V_48 ) : L_11 ) ;
if ( V_18 < 0 ) {
struct V_5 * V_5 = F_3 ( V_48 ) ;
F_5 ( V_48 , & V_5 -> V_7 ) ;
F_34 ( V_48 ) ;
}
return V_18 ;
}
