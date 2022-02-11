static bool F_1 ( struct V_1 * V_2 , char * V_3 ,
T_1 * V_4 , T_1 * V_5 )
{
enum V_6 V_7 = V_8 ;
char * V_9 , * V_10 ;
long V_11 , V_12 ;
int V_13 ;
V_9 = strchr ( V_3 , '/' ) ;
if ( V_9 )
* V_9 = 0 ;
if ( strlen ( V_3 ) > 4 ) {
V_10 = V_3 + strlen ( V_3 ) - 4 ;
if ( F_2 ( V_10 , L_1 , 4 ) == 0 )
V_7 = V_14 ;
if ( ( F_2 ( V_10 , L_2 , 4 ) == 0 ) ||
( V_7 == V_14 ) )
* V_10 = '\0' ;
}
V_13 = F_3 ( V_3 , 10 , & V_11 ) ;
if ( V_13 ) {
F_4 ( V_2 ,
L_3 ,
V_3 ) ;
return false ;
}
switch ( V_7 ) {
case V_14 :
* V_4 = V_11 * 10 ;
break;
case V_8 :
default:
* V_4 = V_11 / 100 ;
break;
}
if ( V_9 ) {
V_7 = V_8 ;
if ( strlen ( V_9 + 1 ) > 4 ) {
V_10 = V_9 + 1 - 4 + strlen ( V_9 + 1 ) ;
if ( F_2 ( V_10 , L_1 , 4 ) == 0 )
V_7 = V_14 ;
if ( ( F_2 ( V_10 , L_2 , 4 ) == 0 ) ||
( V_7 == V_14 ) )
* V_10 = '\0' ;
}
V_13 = F_3 ( V_9 + 1 , 10 , & V_12 ) ;
if ( V_13 ) {
F_4 ( V_2 ,
L_4 ,
V_9 + 1 ) ;
return false ;
}
switch ( V_7 ) {
case V_14 :
* V_5 = V_12 * 10 ;
break;
case V_8 :
default:
* V_5 = V_12 / 100 ;
break;
}
}
return true ;
}
void F_5 ( struct V_15 * V_16 )
{
struct V_17 V_18 ;
T_1 V_4 , V_5 ;
char V_19 ;
V_19 = F_6 ( & V_16 -> V_19 ) ;
switch ( V_19 ) {
case V_20 :
case V_21 :
F_7 ( V_16 , V_22 , 1 ) ;
break;
case V_23 :
V_4 = F_6 ( & V_16 -> V_18 . V_24 ) ;
V_5 = F_6 ( & V_16 -> V_18 . V_25 ) ;
V_18 . V_24 = F_8 ( V_4 ) ;
V_18 . V_25 = F_8 ( V_5 ) ;
F_9 ( V_16 , V_22 , 1 ,
& V_18 , sizeof( V_18 ) ) ;
break;
}
}
T_2 F_10 ( struct V_1 * V_2 , char * V_3 ,
T_3 V_26 )
{
struct V_15 * V_16 = F_11 ( V_2 ) ;
T_1 V_27 , V_28 , V_29 = 0 , V_30 = 0 ;
bool V_13 ;
V_27 = ( unsigned int ) F_6 ( & V_16 -> V_18 . V_24 ) ;
V_28 = ( unsigned int ) F_6 ( & V_16 -> V_18 . V_25 ) ;
V_13 = F_1 ( V_2 , V_3 , & V_29 , & V_30 ) ;
if ( ! V_13 )
goto V_31;
if ( ! V_29 )
V_29 = 1 ;
if ( ! V_30 )
V_30 = V_29 / 5 ;
if ( ! V_30 )
V_30 = 1 ;
if ( ( V_27 == V_29 ) && ( V_28 == V_30 ) )
return V_26 ;
F_12 ( V_16 ) ;
F_13 ( V_2 ,
L_5 ,
V_27 / 10 , V_27 % 10 , V_28 / 10 , V_28 % 10 ,
V_29 / 10 , V_29 % 10 , V_30 / 10 , V_30 % 10 ) ;
F_14 ( & V_16 -> V_18 . V_24 , V_29 ) ;
F_14 ( & V_16 -> V_18 . V_25 , V_30 ) ;
F_5 ( V_16 ) ;
V_31:
return V_26 ;
}
static void F_15 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_4 V_34 ,
void * V_35 ,
T_5 V_36 )
{
struct V_17 V_37 , * V_38 ;
if ( ( V_34 & V_39 ) ||
( V_36 < sizeof( V_37 ) ) ) {
V_37 . V_24 = 0 ;
V_37 . V_25 = 0 ;
} else {
V_38 = V_35 ;
V_37 . V_24 = V_38 -> V_24 ;
V_37 . V_25 = V_38 -> V_25 ;
if ( ( V_37 . V_24 == 0 ) ||
( V_37 . V_25 == 0 ) ) {
V_37 . V_24 = 0 ;
V_37 . V_25 = 0 ;
}
}
F_16 ( V_16 , V_33 , & V_37 ) ;
if ( ( V_37 . V_24 != 0 ) &&
( F_6 ( & V_16 -> V_19 ) == V_21 ) &&
( F_6 ( & V_16 -> V_40 ) > 2 ) )
F_17 ( V_16 , V_33 ) ;
}
void F_18 ( struct V_15 * V_16 )
{
F_19 ( V_16 , F_15 ,
NULL , V_22 , 1 ,
V_39 ) ;
}
void F_20 ( struct V_15 * V_16 )
{
F_7 ( V_16 , V_22 , 1 ) ;
F_21 ( V_16 , V_22 , 1 ) ;
}
