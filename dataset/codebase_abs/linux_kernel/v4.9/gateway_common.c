bool F_1 ( struct V_1 * V_2 , char * V_3 ,
const char * V_4 , T_1 * V_5 )
{
enum V_6 V_7 = V_8 ;
T_2 V_9 ;
char * V_10 ;
int V_11 ;
if ( strlen ( V_3 ) > 4 ) {
V_10 = V_3 + strlen ( V_3 ) - 4 ;
if ( strncasecmp ( V_10 , L_1 , 4 ) == 0 )
V_7 = V_12 ;
if ( ( strncasecmp ( V_10 , L_2 , 4 ) == 0 ) ||
( V_7 == V_12 ) )
* V_10 = '\0' ;
}
V_11 = F_2 ( V_3 , 10 , & V_9 ) ;
if ( V_11 ) {
F_3 ( V_2 ,
L_3 ,
V_4 , V_3 ) ;
return false ;
}
switch ( V_7 ) {
case V_12 :
if ( V_13 / 10 < V_9 ) {
F_3 ( V_2 ,
L_4 ,
V_4 , V_3 ) ;
return false ;
}
V_9 *= 10 ;
break;
case V_8 :
default:
V_9 = F_4 ( V_9 , 100 ) ;
break;
}
if ( V_9 > V_14 ) {
F_3 ( V_2 ,
L_4 ,
V_4 , V_3 ) ;
return false ;
}
* V_5 = V_9 ;
return true ;
}
static bool F_5 ( struct V_1 * V_2 , char * V_3 ,
T_1 * V_15 , T_1 * V_16 )
{
char * V_17 ;
bool V_11 ;
V_17 = strchr ( V_3 , '/' ) ;
if ( V_17 )
* V_17 = 0 ;
V_11 = F_1 ( V_2 , V_3 , L_5 ,
V_15 ) ;
if ( ! V_11 )
return false ;
if ( V_17 ) {
V_11 = F_1 ( V_2 , V_17 + 1 ,
L_6 , V_16 ) ;
if ( ! V_11 )
return false ;
}
return true ;
}
void F_6 ( struct V_18 * V_19 )
{
struct V_20 V_21 ;
T_1 V_15 , V_16 ;
char V_22 ;
V_22 = F_7 ( & V_19 -> V_21 . V_23 ) ;
switch ( V_22 ) {
case V_24 :
case V_25 :
F_8 ( V_19 , V_26 , 1 ) ;
break;
case V_27 :
V_15 = F_7 ( & V_19 -> V_21 . V_28 ) ;
V_16 = F_7 ( & V_19 -> V_21 . V_29 ) ;
V_21 . V_28 = F_9 ( V_15 ) ;
V_21 . V_29 = F_9 ( V_16 ) ;
F_10 ( V_19 , V_26 , 1 ,
& V_21 , sizeof( V_21 ) ) ;
break;
}
}
T_3 F_11 ( struct V_1 * V_2 , char * V_3 ,
T_4 V_30 )
{
struct V_18 * V_19 = F_12 ( V_2 ) ;
T_1 V_31 ;
T_1 V_32 ;
T_1 V_33 = 0 ;
T_1 V_34 = 0 ;
bool V_11 ;
V_31 = ( unsigned int ) F_7 ( & V_19 -> V_21 . V_28 ) ;
V_32 = ( unsigned int ) F_7 ( & V_19 -> V_21 . V_29 ) ;
V_11 = F_5 ( V_2 , V_3 , & V_33 , & V_34 ) ;
if ( ! V_11 )
return - V_35 ;
if ( ! V_33 )
V_33 = 1 ;
if ( ! V_34 )
V_34 = V_33 / 5 ;
if ( ! V_34 )
V_34 = 1 ;
if ( ( V_31 == V_33 ) && ( V_32 == V_34 ) )
return V_30 ;
F_13 ( V_19 ) ;
F_14 ( V_2 ,
L_7 ,
V_31 / 10 , V_31 % 10 , V_32 / 10 , V_32 % 10 ,
V_33 / 10 , V_33 % 10 , V_34 / 10 , V_34 % 10 ) ;
F_15 ( & V_19 -> V_21 . V_28 , V_33 ) ;
F_15 ( & V_19 -> V_21 . V_29 , V_34 ) ;
F_6 ( V_19 ) ;
return V_30 ;
}
static void F_16 ( struct V_18 * V_19 ,
struct V_36 * V_37 ,
T_5 V_38 ,
void * V_39 , T_6 V_40 )
{
struct V_20 V_41 , * V_42 ;
if ( ( V_38 & V_43 ) ||
( V_40 < sizeof( V_41 ) ) ) {
V_41 . V_28 = 0 ;
V_41 . V_29 = 0 ;
} else {
V_42 = V_39 ;
V_41 . V_28 = V_42 -> V_28 ;
V_41 . V_29 = V_42 -> V_29 ;
if ( ( V_41 . V_28 == 0 ) ||
( V_41 . V_29 == 0 ) ) {
V_41 . V_28 = 0 ;
V_41 . V_29 = 0 ;
}
}
F_17 ( V_19 , V_37 , & V_41 ) ;
if ( ( V_41 . V_28 != 0 ) &&
( F_7 ( & V_19 -> V_21 . V_23 ) == V_25 ) )
F_18 ( V_19 , V_37 ) ;
}
void F_19 ( struct V_18 * V_19 )
{
F_20 ( V_19 , F_16 ,
NULL , V_26 , 1 ,
V_43 ) ;
}
void F_21 ( struct V_18 * V_19 )
{
F_8 ( V_19 , V_26 , 1 ) ;
F_22 ( V_19 , V_26 , 1 ) ;
}
