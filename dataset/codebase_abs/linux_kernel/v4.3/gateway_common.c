static bool F_1 ( struct V_1 * V_2 , char * V_3 ,
T_1 * V_4 , T_1 * V_5 )
{
enum V_6 V_7 = V_8 ;
char * V_9 , * V_10 ;
T_2 V_11 , V_12 ;
int V_13 ;
V_9 = strchr ( V_3 , '/' ) ;
if ( V_9 )
* V_9 = 0 ;
if ( strlen ( V_3 ) > 4 ) {
V_10 = V_3 + strlen ( V_3 ) - 4 ;
if ( strncasecmp ( V_10 , L_1 , 4 ) == 0 )
V_7 = V_14 ;
if ( ( strncasecmp ( V_10 , L_2 , 4 ) == 0 ) ||
( V_7 == V_14 ) )
* V_10 = '\0' ;
}
V_13 = F_2 ( V_3 , 10 , & V_11 ) ;
if ( V_13 ) {
F_3 ( V_2 ,
L_3 ,
V_3 ) ;
return false ;
}
switch ( V_7 ) {
case V_14 :
if ( V_15 / 10 < V_11 ) {
F_3 ( V_2 ,
L_4 ,
V_3 ) ;
return false ;
}
V_11 *= 10 ;
break;
case V_8 :
default:
V_11 = F_4 ( V_11 , 100 ) ;
break;
}
if ( V_16 < V_11 ) {
F_3 ( V_2 ,
L_4 ,
V_3 ) ;
return false ;
}
* V_4 = V_11 ;
if ( V_9 ) {
V_7 = V_8 ;
if ( strlen ( V_9 + 1 ) > 4 ) {
V_10 = V_9 + 1 - 4 + strlen ( V_9 + 1 ) ;
if ( strncasecmp ( V_10 , L_1 , 4 ) == 0 )
V_7 = V_14 ;
if ( ( strncasecmp ( V_10 , L_2 , 4 ) == 0 ) ||
( V_7 == V_14 ) )
* V_10 = '\0' ;
}
V_13 = F_2 ( V_9 + 1 , 10 , & V_12 ) ;
if ( V_13 ) {
F_3 ( V_2 ,
L_5 ,
V_9 + 1 ) ;
return false ;
}
switch ( V_7 ) {
case V_14 :
if ( V_15 / 10 < V_12 ) {
F_3 ( V_2 ,
L_6 ,
V_9 + 1 ) ;
return false ;
}
V_12 *= 10 ;
break;
case V_8 :
default:
V_12 = F_4 ( V_12 , 100 ) ;
break;
}
if ( V_16 < V_12 ) {
F_3 ( V_2 ,
L_6 ,
V_9 + 1 ) ;
return false ;
}
* V_5 = V_12 ;
}
return true ;
}
void F_5 ( struct V_17 * V_18 )
{
struct V_19 V_20 ;
T_1 V_4 , V_5 ;
char V_21 ;
V_21 = F_6 ( & V_18 -> V_21 ) ;
switch ( V_21 ) {
case V_22 :
case V_23 :
F_7 ( V_18 , V_24 , 1 ) ;
break;
case V_25 :
V_4 = F_6 ( & V_18 -> V_20 . V_26 ) ;
V_5 = F_6 ( & V_18 -> V_20 . V_27 ) ;
V_20 . V_26 = F_8 ( V_4 ) ;
V_20 . V_27 = F_8 ( V_5 ) ;
F_9 ( V_18 , V_24 , 1 ,
& V_20 , sizeof( V_20 ) ) ;
break;
}
}
T_3 F_10 ( struct V_1 * V_2 , char * V_3 ,
T_4 V_28 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_31 = 0 ;
T_1 V_32 = 0 ;
bool V_13 ;
V_29 = ( unsigned int ) F_6 ( & V_18 -> V_20 . V_26 ) ;
V_30 = ( unsigned int ) F_6 ( & V_18 -> V_20 . V_27 ) ;
V_13 = F_1 ( V_2 , V_3 , & V_31 , & V_32 ) ;
if ( ! V_13 )
return - V_33 ;
if ( ! V_31 )
V_31 = 1 ;
if ( ! V_32 )
V_32 = V_31 / 5 ;
if ( ! V_32 )
V_32 = 1 ;
if ( ( V_29 == V_31 ) && ( V_30 == V_32 ) )
return V_28 ;
F_12 ( V_18 ) ;
F_13 ( V_2 ,
L_7 ,
V_29 / 10 , V_29 % 10 , V_30 / 10 , V_30 % 10 ,
V_31 / 10 , V_31 % 10 , V_32 / 10 , V_32 % 10 ) ;
F_14 ( & V_18 -> V_20 . V_26 , V_31 ) ;
F_14 ( & V_18 -> V_20 . V_27 , V_32 ) ;
F_5 ( V_18 ) ;
return V_28 ;
}
static void F_15 ( struct V_17 * V_18 ,
struct V_34 * V_35 ,
T_5 V_36 ,
void * V_37 , T_6 V_38 )
{
struct V_19 V_39 , * V_40 ;
if ( ( V_36 & V_41 ) ||
( V_38 < sizeof( V_39 ) ) ) {
V_39 . V_26 = 0 ;
V_39 . V_27 = 0 ;
} else {
V_40 = V_37 ;
V_39 . V_26 = V_40 -> V_26 ;
V_39 . V_27 = V_40 -> V_27 ;
if ( ( V_39 . V_26 == 0 ) ||
( V_39 . V_27 == 0 ) ) {
V_39 . V_26 = 0 ;
V_39 . V_27 = 0 ;
}
}
F_16 ( V_18 , V_35 , & V_39 ) ;
if ( ( V_39 . V_26 != 0 ) &&
( F_6 ( & V_18 -> V_21 ) == V_23 ) &&
( F_6 ( & V_18 -> V_42 ) > 2 ) )
F_17 ( V_18 , V_35 ) ;
}
void F_18 ( struct V_17 * V_18 )
{
F_19 ( V_18 , F_15 ,
NULL , V_24 , 1 ,
V_41 ) ;
}
void F_20 ( struct V_17 * V_18 )
{
F_7 ( V_18 , V_24 , 1 ) ;
F_21 ( V_18 , V_24 , 1 ) ;
}
