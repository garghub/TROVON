static
int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , const T_1 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
struct V_8 * V_9 ;
V_7 = - V_10 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_11 ) ;
if ( V_9 == NULL )
goto V_12;
V_9 -> V_13 . V_14 = V_15 ;
V_9 -> V_13 . V_16 = F_3 ( V_17 ) ;
V_9 -> V_3 = V_3 ;
if ( V_4 ) {
T_2 V_18 = 0 ;
switch ( V_3 >> 1 ) {
case 0 : V_18 = 2 ; break;
case 1 : V_18 = 6 ; break;
default: F_4 () ;
}
memcpy ( V_9 -> V_4 , V_4 , V_18 ) ;
}
V_6 -> V_19 . V_20 = V_15 ;
V_6 -> V_19 . V_21 = V_17 ;
V_7 = F_5 ( V_2 , L_1 ,
& V_9 -> V_13 , sizeof( * V_9 ) ,
& V_6 -> V_19 , sizeof( * V_6 ) ) ;
if ( V_7 < 0 )
goto V_22;
if ( V_7 < sizeof( * V_6 ) ) {
F_6 ( & V_2 -> V_23 . V_24 ,
L_2
L_3 , V_7 , sizeof( * V_6 ) ) ;
V_7 = - V_25 ;
} else if ( V_6 -> V_26 != V_27 ) {
F_6 ( & V_2 -> V_23 . V_24 ,
L_4 ,
F_7 ( V_6 -> V_26 ) ,
V_6 -> V_26 ) ;
V_7 = - V_28 ;
} else
V_7 = 0 ;
V_22:
F_8 ( V_9 ) ;
V_12:
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 ,
const void * V_29 , enum V_30 type )
{
int V_7 ;
T_1 V_3 = 0x1 ;
const struct V_31 * V_32 = V_29 ;
const struct V_33 * V_34 = V_29 ;
struct V_5 V_6 ;
const T_1 * V_4 ;
V_7 = - V_35 ;
switch ( type ) {
case V_36 :
V_4 = V_32 -> V_37 ;
break;
case V_38 :
V_4 = V_34 -> V_37 ;
V_3 |= 0x2 ;
break;
default:
return V_7 ;
}
return F_1 ( V_2 , V_3 , V_4 , & V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
void * V_29 , enum V_30 type )
{
int V_7 ;
T_1 V_3 = 0x0 ;
struct V_5 V_39 ;
struct V_31 * V_32 = V_29 ;
struct V_33 * V_34 = V_29 ;
T_1 * V_4 ;
V_7 = - V_35 ;
switch ( type ) {
case V_36 :
V_4 = V_32 -> V_37 ;
break;
case V_38 :
V_3 |= 0x2 ;
V_4 = V_34 -> V_37 ;
break;
default:
return V_7 ;
}
V_7 = F_1 ( V_2 , V_3 , V_4 , & V_39 ) ;
if ( V_7 == 0 )
switch ( type ) {
case V_36 :
memcpy ( & V_32 -> V_37 , V_39 . V_4 ,
sizeof( V_32 -> V_37 ) ) ;
break;
case V_38 :
memcpy ( & V_34 -> V_37 , V_39 . V_4 ,
sizeof( V_34 -> V_37 ) ) ;
break;
default:
F_4 () ;
}
return V_7 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_33 * V_40 ) {
return F_10 ( V_2 , V_40 , V_38 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_31 * V_40 ) {
return F_10 ( V_2 , V_40 , V_36 ) ;
}
int F_13 ( struct V_1 * V_2 ,
const struct V_33 * V_40 )
{
int V_7 = - V_35 ;
F_14 ( & V_2 -> V_23 . V_41 ) ;
V_7 = F_9 ( V_2 , V_40 , V_38 ) ;
F_15 ( & V_2 -> V_23 . V_41 ) ;
return V_7 ;
}
int F_16 ( struct V_1 * V_2 ,
const struct V_31 * V_40 )
{
int V_7 = - V_35 ;
F_14 ( & V_2 -> V_23 . V_41 ) ;
V_7 = F_9 ( V_2 , V_40 , V_36 ) ;
V_2 -> V_23 . V_32 = * V_40 ;
F_15 ( & V_2 -> V_23 . V_41 ) ;
return V_7 ;
}
int F_17 ( struct V_42 * V_24 , void * V_29 )
{
struct V_23 * V_23 = F_18 ( V_24 ) ;
struct V_33 * V_40 = V_29 ;
if ( ! F_19 ( V_40 , & V_23 -> V_34 ) )
return ! 0 ;
return 0 ;
}
int F_20 ( struct V_42 * V_24 , void * V_29 )
{
struct V_23 * V_23 = F_18 ( V_24 ) ;
struct V_31 * V_40 = V_29 ;
if ( ! F_21 ( V_40 , & V_23 -> V_32 ) )
return ! 0 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_31 V_43 ;
do {
F_23 ( V_43 . V_37 , sizeof( V_43 . V_37 ) ) ;
} while ( V_43 . V_37 [ 0 ] == 0x00 || V_43 . V_37 [ 0 ] == 0xff
|| F_24 ( V_2 , & V_43 ) );
return F_16 ( V_2 , & V_43 ) ;
}
int F_25 ( struct V_44 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
return F_22 ( V_2 ) ;
}
static T_3 F_26 ( struct V_42 * V_24 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_23 * V_23 = F_18 ( V_24 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_33 V_40 ;
T_3 V_7 ;
F_14 ( & V_2 -> V_23 . V_41 ) ;
V_7 = F_10 ( V_2 , & V_40 , V_38 ) ;
F_15 ( & V_2 -> V_23 . V_41 ) ;
if ( V_7 >= 0 ) {
V_7 = F_27 ( V_47 , V_48 , & V_40 ) ;
V_47 [ V_7 ++ ] = '\n' ;
}
return V_7 ;
}
static T_3 F_28 ( struct V_42 * V_24 ,
struct V_45 * V_46 ,
const char * V_47 , T_2 V_18 )
{
struct V_23 * V_23 = F_18 ( V_24 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_33 V_40 ;
T_3 V_7 ;
V_7 = sscanf ( V_47 , L_5 ,
& V_40 . V_37 [ 0 ] , & V_40 . V_37 [ 1 ] , & V_40 . V_37 [ 2 ] ,
& V_40 . V_37 [ 3 ] , & V_40 . V_37 [ 4 ] , & V_40 . V_37 [ 5 ] ) ;
if ( V_7 != 6 ) {
V_7 = - V_35 ;
goto V_49;
}
if ( F_29 ( V_40 . V_37 ) ) {
F_6 ( & V_2 -> V_23 . V_24 , L_6
L_7 , V_47 ) ;
V_7 = - V_35 ;
goto V_49;
}
V_7 = F_13 ( V_2 , & V_40 ) ;
if ( V_7 == 0 )
V_2 -> V_23 . V_34 = V_40 ;
V_49:
return V_7 < 0 ? V_7 : V_18 ;
}
T_2 F_30 ( char * V_47 , T_2 V_50 , const unsigned char * V_40 ,
int type )
{
T_2 V_7 ;
if ( type )
V_7 = F_31 ( V_47 , V_50 , L_8 , V_40 ) ;
else
V_7 = F_31 ( V_47 , V_50 , L_9 ,
V_40 [ 1 ] , V_40 [ 0 ] ) ;
return V_7 ;
}
