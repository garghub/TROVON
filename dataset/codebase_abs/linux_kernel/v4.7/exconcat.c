T_1
F_1 ( union V_1 * V_2 ,
union V_1 * V_3 ,
union V_1 * * V_4 ,
struct V_5 * V_6 )
{
union V_1 * V_7 = V_2 ;
union V_1 * V_8 = V_3 ;
union V_1 * V_9 = NULL ;
union V_1 * V_10 ;
char * V_11 ;
T_2 V_12 ;
T_2 V_13 ;
T_1 V_14 ;
F_2 ( V_15 ) ;
switch ( V_2 -> V_16 . type ) {
case V_17 :
case V_18 :
case V_19 :
V_12 = V_2 -> V_16 . type ;
break;
default:
V_14 =
F_3 ( V_2 ,
& V_7 ) ;
if ( F_4 ( V_14 ) ) {
goto V_20;
}
V_12 = V_18 ;
break;
}
switch ( V_3 -> V_16 . type ) {
case V_17 :
case V_18 :
case V_19 :
V_13 = V_3 -> V_16 . type ;
break;
default:
V_14 =
F_3 ( V_3 ,
& V_8 ) ;
if ( F_4 ( V_14 ) ) {
goto V_20;
}
V_13 = V_18 ;
break;
}
switch ( V_12 ) {
case V_17 :
V_14 =
F_5 ( V_8 , & V_9 ,
16 ) ;
break;
case V_19 :
V_14 =
F_6 ( V_8 , & V_9 ) ;
break;
case V_18 :
switch ( V_13 ) {
case V_17 :
case V_18 :
case V_19 :
V_14 =
F_7 ( V_8 ,
& V_9 ,
V_21 ) ;
break;
default:
V_14 = V_22 ;
break;
}
break;
default:
F_8 ( ( V_23 , L_1 ,
V_2 -> V_16 . type ) ) ;
V_14 = V_24 ;
}
if ( F_4 ( V_14 ) ) {
goto V_20;
}
if ( ( V_8 != V_3 ) && ( V_8 != V_9 ) ) {
F_9 ( V_8 ) ;
}
V_8 = V_9 ;
switch ( V_12 ) {
case V_17 :
V_10 = F_10 ( ( V_25 )
F_11
( V_26 ) ) ;
if ( ! V_10 ) {
V_14 = V_27 ;
goto V_20;
}
V_11 = ( char * ) V_10 -> V_11 . V_28 ;
memcpy ( V_11 , & V_2 -> integer . V_29 ,
V_26 ) ;
memcpy ( V_11 + V_26 ,
& V_8 -> integer . V_29 ,
V_26 ) ;
break;
case V_18 :
V_10 = F_12 ( ( ( V_25 )
V_7 ->
string . V_30 +
V_8 ->
string . V_30 ) ) ;
if ( ! V_10 ) {
V_14 = V_27 ;
goto V_20;
}
V_11 = V_10 -> string . V_28 ;
strcpy ( V_11 , V_7 -> string . V_28 ) ;
strcat ( V_11 , V_8 -> string . V_28 ) ;
break;
case V_19 :
V_10 = F_10 ( ( ( V_25 )
V_2 -> V_11 .
V_30 +
V_8 ->
V_11 . V_30 ) ) ;
if ( ! V_10 ) {
V_14 = V_27 ;
goto V_20;
}
V_11 = ( char * ) V_10 -> V_11 . V_28 ;
memcpy ( V_11 , V_2 -> V_11 . V_28 ,
V_2 -> V_11 . V_30 ) ;
memcpy ( V_11 + V_2 -> V_11 . V_30 ,
V_8 -> V_11 . V_28 ,
V_8 -> V_11 . V_30 ) ;
break;
default:
F_8 ( ( V_23 , L_1 ,
V_2 -> V_16 . type ) ) ;
V_14 = V_24 ;
goto V_20;
}
* V_4 = V_10 ;
V_20:
if ( V_7 != V_2 ) {
F_9 ( V_7 ) ;
}
if ( V_8 != V_3 ) {
F_9 ( V_8 ) ;
}
F_13 ( V_14 ) ;
}
static T_1
F_3 ( union V_1 * V_31 ,
union V_1 * * V_32 )
{
union V_1 * V_10 ;
const char * V_33 ;
V_33 = F_14 ( V_31 -> V_16 . type ) ;
V_10 = F_12 ( ( ( V_25 ) strlen ( V_33 ) + 9 ) ) ;
if ( ! V_10 ) {
return ( V_27 ) ;
}
strcpy ( V_10 -> string . V_28 , L_2 ) ;
strcat ( V_10 -> string . V_28 , V_33 ) ;
strcat ( V_10 -> string . V_28 , L_3 ) ;
* V_32 = V_10 ;
return ( V_22 ) ;
}
T_1
F_15 ( union V_1 * V_2 ,
union V_1 * V_3 ,
union V_1 * * V_4 ,
struct V_5 * V_6 )
{
T_1 V_14 ;
union V_1 * V_10 ;
T_3 * V_34 ;
T_3 * V_35 ;
V_25 V_36 ;
V_25 V_37 ;
V_25 V_38 ;
F_2 ( V_39 ) ;
V_14 = F_16 ( V_2 , & V_35 ) ;
if ( F_4 ( V_14 ) ) {
F_13 ( V_14 ) ;
}
V_36 = F_17 ( V_35 , V_2 -> V_11 . V_28 ) ;
V_14 = F_16 ( V_3 , & V_35 ) ;
if ( F_4 ( V_14 ) ) {
F_13 ( V_14 ) ;
}
V_37 = F_17 ( V_35 , V_3 -> V_11 . V_28 ) ;
V_38 = V_36 + V_37 + sizeof( struct V_40 ) ;
V_10 = F_10 ( V_38 ) ;
if ( ! V_10 ) {
F_13 ( V_27 ) ;
}
V_34 = V_10 -> V_11 . V_28 ;
memcpy ( V_34 , V_2 -> V_11 . V_28 , V_36 ) ;
memcpy ( V_34 + V_36 , V_3 -> V_11 . V_28 , V_37 ) ;
V_34 [ V_38 - 1 ] = 0 ;
V_34 [ V_38 - 2 ] = V_41 | 1 ;
* V_4 = V_10 ;
F_13 ( V_22 ) ;
}
