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
V_5 -> V_15 = V_17 ;
} else if ( strncmp ( V_14 , L_2 , V_22 ) == 0
|| strncmp ( V_14 , L_6 , V_22 ) == 0 )
V_5 -> V_15 = V_16 ;
else if ( strncmp ( V_14 , L_4 , V_22 ) == 0
|| strncmp ( V_14 , L_7 , V_22 ) == 0 )
V_5 -> V_15 = V_23 ;
else
V_19 = - V_24 ;
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
return sprintf ( V_14 , L_11 , V_5 -> V_25 ) ;
}
static T_1 F_18 ( struct V_5 * V_5 , const char * V_14 )
{
unsigned long V_26 ;
int V_19 ;
V_19 = F_19 ( V_14 , 0 , & V_26 ) ;
if ( V_19 )
return V_19 ;
if ( ! F_20 ( V_26 ) || V_26 < V_27 || V_26 > V_28 )
return - V_24 ;
if ( V_5 -> V_2 . V_20 )
return - V_21 ;
else
V_5 -> V_25 = V_26 ;
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_19 = F_18 ( V_5 , V_14 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
if ( V_5 -> V_10 )
return sprintf ( V_14 , L_12 , V_5 -> V_10 ) ;
return sprintf ( V_14 , L_10 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_13 ( V_2 ) ;
V_19 = F_24 ( V_2 , & V_5 -> V_10 , V_14 , V_18 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_16 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
V_19 = sprintf ( V_14 , L_1 , V_5 -> V_7
? F_26 ( & V_5 -> V_7 -> V_2 ) : L_9 ) ;
F_15 ( V_2 ) ;
return V_19 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_19 = F_28 ( V_2 , & V_5 -> V_7 , V_14 , V_18 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_19 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_13 ( V_2 ) ;
if ( V_2 -> V_20 ) {
struct V_29 * V_30 = V_5 -> V_30 ;
T_3 V_31 = F_30 ( V_30 -> V_32 ) ;
struct V_33 * V_7 = V_5 -> V_7 ;
T_4 V_34 = F_31 ( V_30 -> V_34 ) ;
struct V_35 * V_36 = F_32 ( & V_7 -> V_2 ) ;
V_19 = sprintf ( V_14 , L_13 , ( unsigned long long ) V_36 -> V_37 . V_38
+ V_34 + V_31 ) ;
} else {
V_19 = - V_39 ;
}
F_16 ( V_2 ) ;
return V_19 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
T_1 V_19 ;
F_13 ( V_2 ) ;
if ( V_2 -> V_20 ) {
struct V_29 * V_30 = V_5 -> V_30 ;
T_3 V_31 = F_30 ( V_30 -> V_32 ) ;
struct V_33 * V_7 = V_5 -> V_7 ;
T_4 V_34 = F_31 ( V_30 -> V_34 ) ;
T_4 V_40 = F_31 ( V_30 -> V_40 ) ;
struct V_35 * V_36 = F_32 ( & V_7 -> V_2 ) ;
V_19 = sprintf ( V_14 , L_14 , ( unsigned long long )
F_34 ( & V_36 -> V_37 ) - V_34
- V_40 - V_31 ) ;
} else {
V_19 = - V_39 ;
}
F_16 ( V_2 ) ;
return V_19 ;
}
static struct V_1 * F_35 ( struct V_3 * V_3 ,
struct V_33 * V_7 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
if ( ! F_36 ( & V_3 -> V_2 ) )
return NULL ;
V_5 = F_37 ( sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = F_38 ( & V_3 -> V_8 , 0 , 0 , V_41 ) ;
if ( V_5 -> V_9 < 0 ) {
F_7 ( V_5 ) ;
return NULL ;
}
V_5 -> V_15 = V_23 ;
V_5 -> V_25 = V_42 ;
V_2 = & V_5 -> V_2 ;
F_39 ( V_2 , L_15 , V_3 -> V_9 , V_5 -> V_9 ) ;
V_2 -> V_4 = & V_3 -> V_2 ;
V_2 -> type = & V_11 ;
V_2 -> V_43 = V_44 ;
F_40 ( & V_5 -> V_2 ) ;
if ( V_7 && ! F_41 ( & V_5 -> V_2 , V_7 , & V_5 -> V_7 ) ) {
F_4 ( & V_7 -> V_2 , L_16 ,
V_6 , F_26 ( V_7 -> V_45 ) ) ;
F_42 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
struct V_1 * F_43 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_35 ( V_3 , NULL ) ;
if ( V_2 )
F_44 ( V_2 ) ;
return V_2 ;
}
int F_45 ( struct V_5 * V_5 )
{
T_3 V_46 , V_31 ;
struct V_35 * V_36 ;
struct V_29 * V_30 = V_5 -> V_30 ;
struct V_33 * V_7 = V_5 -> V_7 ;
const T_5 * V_47 = F_46 ( & V_7 -> V_2 ) ;
if ( ! V_30 || ! V_7 )
return - V_48 ;
if ( ! F_36 ( V_5 -> V_2 . V_4 ) )
return - V_48 ;
if ( F_47 ( V_7 , V_49 , V_30 , sizeof( * V_30 ) ) )
return - V_39 ;
if ( memcmp ( V_30 -> V_50 , V_51 , V_52 ) != 0 )
return - V_48 ;
V_46 = F_48 ( V_30 -> V_46 ) ;
V_30 -> V_46 = 0 ;
if ( V_46 != F_49 ( (struct V_53 * ) V_30 ) )
return - V_48 ;
V_30 -> V_46 = F_50 ( V_46 ) ;
if ( memcmp ( V_30 -> V_47 , V_47 , 16 ) != 0 )
return - V_48 ;
if ( F_51 ( V_30 -> V_54 ) < 1 ) {
V_30 -> V_34 = 0 ;
V_30 -> V_40 = 0 ;
}
switch ( F_52 ( V_30 -> V_15 ) ) {
case V_16 :
case V_17 :
break;
default:
return - V_39 ;
}
if ( ! V_5 -> V_10 ) {
V_5 -> V_10 = F_53 ( V_30 -> V_10 , 16 , V_41 ) ;
if ( ! V_5 -> V_10 )
return - V_55 ;
} else {
if ( memcmp ( V_5 -> V_10 , V_30 -> V_10 , 16 ) != 0 )
return - V_48 ;
}
if ( V_5 -> V_25 > F_54 ( V_7 ) ) {
F_55 ( & V_5 -> V_2 , L_17 ,
V_5 -> V_25 , F_54 ( V_7 ) ) ;
return - V_24 ;
}
V_31 = F_48 ( V_30 -> V_32 ) ;
V_36 = F_32 ( & V_7 -> V_2 ) ;
if ( V_31 >= F_34 ( & V_36 -> V_37 ) ) {
F_55 ( & V_5 -> V_2 , L_18 ,
F_26 ( & V_7 -> V_2 ) ) ;
return - V_21 ;
}
V_5 -> V_25 = 1UL << F_56 ( V_31 ) ;
if ( ! F_20 ( V_31 ) || V_31 < V_27 ) {
F_55 ( & V_5 -> V_2 , L_19 ,
V_31 ) ;
return - V_39 ;
}
return 0 ;
}
int F_57 ( struct V_33 * V_7 , void * V_56 )
{
int V_19 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
struct V_29 * V_30 ;
struct V_3 * V_3 = F_2 ( V_7 -> V_2 . V_4 ) ;
if ( V_7 -> V_57 )
return - V_48 ;
F_14 ( & V_7 -> V_2 ) ;
V_2 = F_35 ( V_3 , V_7 ) ;
F_15 ( & V_7 -> V_2 ) ;
if ( ! V_2 )
return - V_55 ;
F_58 ( V_2 , V_56 ) ;
V_30 = F_37 ( sizeof( * V_30 ) , V_41 ) ;
V_5 = F_3 ( V_2 ) ;
V_5 -> V_30 = V_30 ;
V_19 = F_45 ( V_5 ) ;
V_5 -> V_30 = NULL ;
F_7 ( V_30 ) ;
F_4 ( & V_7 -> V_2 , L_20 , V_6 ,
V_19 == 0 ? F_26 ( V_2 ) : L_21 ) ;
if ( V_19 < 0 ) {
F_59 ( V_2 , & V_5 -> V_7 ) ;
F_42 ( V_2 ) ;
} else
F_44 ( & V_5 -> V_2 ) ;
return V_19 ;
}
