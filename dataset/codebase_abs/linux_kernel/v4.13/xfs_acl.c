STATIC struct V_1 *
F_1 (
const struct V_2 * V_3 ,
int V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
struct V_1 * V_8 ;
const struct V_9 * V_10 ;
unsigned int V_11 , V_12 ;
if ( V_4 < sizeof( * V_3 ) )
return F_2 ( - V_13 ) ;
V_11 = F_3 ( V_3 -> V_14 ) ;
if ( V_11 > V_5 || F_4 ( V_11 ) != V_4 )
return F_2 ( - V_13 ) ;
V_8 = F_5 ( V_11 , V_15 ) ;
if ( ! V_8 )
return F_2 ( - V_16 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
V_7 = & V_8 -> V_17 [ V_12 ] ;
V_10 = & V_3 -> V_18 [ V_12 ] ;
V_7 -> V_19 = F_3 ( V_10 -> V_20 ) ;
V_7 -> V_21 = F_6 ( V_10 -> V_22 ) ;
switch ( V_7 -> V_19 ) {
case V_23 :
V_7 -> V_24 = F_7 ( F_3 ( V_10 -> V_25 ) ) ;
break;
case V_26 :
V_7 -> V_27 = F_8 ( F_3 ( V_10 -> V_25 ) ) ;
break;
case V_28 :
case V_29 :
case V_30 :
case V_31 :
break;
default:
goto V_32;
}
}
return V_8 ;
V_32:
F_9 ( V_8 ) ;
return F_2 ( - V_33 ) ;
}
STATIC void
F_10 ( struct V_2 * V_3 , const struct V_1 * V_8 )
{
const struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_12 ;
V_3 -> V_14 = F_11 ( V_8 -> V_34 ) ;
for ( V_12 = 0 ; V_12 < V_8 -> V_34 ; V_12 ++ ) {
V_10 = & V_3 -> V_18 [ V_12 ] ;
V_7 = & V_8 -> V_17 [ V_12 ] ;
V_10 -> V_20 = F_11 ( V_7 -> V_19 ) ;
switch ( V_7 -> V_19 ) {
case V_23 :
V_10 -> V_25 = F_11 ( F_12 ( V_7 -> V_24 ) ) ;
break;
case V_26 :
V_10 -> V_25 = F_11 ( F_13 ( V_7 -> V_27 ) ) ;
break;
default:
V_10 -> V_25 = F_11 ( V_35 ) ;
break;
}
V_10 -> V_22 = F_14 ( V_7 -> V_21 ) ;
}
}
struct V_1 *
F_15 ( struct V_36 * V_36 , int type )
{
struct V_37 * V_38 = F_16 ( V_36 ) ;
struct V_1 * V_8 = NULL ;
struct V_2 * V_2 ;
unsigned char * V_39 ;
int error ;
int V_4 ;
F_17 ( V_38 ) ;
switch ( type ) {
case V_40 :
V_39 = V_41 ;
break;
case V_42 :
V_39 = V_43 ;
break;
default:
F_18 () ;
}
V_4 = F_19 ( V_38 -> V_44 ) ;
V_2 = F_20 ( V_4 , V_45 ) ;
if ( ! V_2 )
return F_2 ( - V_16 ) ;
error = F_21 ( V_38 , V_39 , ( unsigned char * ) V_2 ,
& V_4 , V_46 ) ;
if ( error ) {
if ( error != - V_47 )
V_8 = F_2 ( error ) ;
} else {
V_8 = F_1 ( V_2 , V_4 ,
F_22 ( V_38 -> V_44 ) ) ;
}
F_23 ( V_2 ) ;
return V_8 ;
}
int
F_24 ( struct V_36 * V_36 , struct V_1 * V_8 , int type )
{
struct V_37 * V_38 = F_16 ( V_36 ) ;
unsigned char * V_39 ;
int error ;
switch ( type ) {
case V_40 :
V_39 = V_41 ;
break;
case V_42 :
if ( ! F_25 ( V_36 -> V_48 ) )
return V_8 ? - V_49 : 0 ;
V_39 = V_43 ;
break;
default:
return - V_33 ;
}
if ( V_8 ) {
struct V_2 * V_2 ;
int V_4 = F_19 ( V_38 -> V_44 ) ;
V_2 = F_20 ( V_4 , V_45 ) ;
if ( ! V_2 )
return - V_16 ;
F_10 ( V_2 , V_8 ) ;
V_4 -= sizeof( struct V_9 ) *
( F_22 ( V_38 -> V_44 ) - V_8 -> V_34 ) ;
error = F_26 ( V_38 , V_39 , ( unsigned char * ) V_2 ,
V_4 , V_46 ) ;
F_23 ( V_2 ) ;
} else {
error = F_27 ( V_38 , V_39 , V_46 ) ;
if ( error == - V_47 )
error = 0 ;
}
if ( ! error )
F_28 ( V_36 , type , V_8 ) ;
return error ;
}
static int
F_29 ( struct V_36 * V_36 , T_1 V_50 )
{
int error = 0 ;
if ( V_50 != V_36 -> V_48 ) {
struct V_51 V_51 ;
V_51 . V_52 = V_53 | V_54 ;
V_51 . V_55 = V_50 ;
V_51 . V_56 = F_30 ( V_36 ) ;
error = F_31 ( F_16 ( V_36 ) , & V_51 , V_57 ) ;
}
return error ;
}
int
F_32 ( struct V_36 * V_36 , struct V_1 * V_8 , int type )
{
int error = 0 ;
if ( ! V_8 )
goto V_58;
error = - V_59 ;
if ( V_8 -> V_34 > F_22 ( F_33 ( V_36 -> V_60 ) ) )
return error ;
if ( type == V_40 ) {
T_1 V_50 ;
error = F_34 ( V_36 , & V_50 , & V_8 ) ;
if ( error )
return error ;
error = F_29 ( V_36 , V_50 ) ;
if ( error )
return error ;
}
V_58:
return F_24 ( V_36 , V_8 , type ) ;
}
