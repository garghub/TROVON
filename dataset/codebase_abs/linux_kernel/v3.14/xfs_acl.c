STATIC struct V_1 *
F_1 (
struct V_2 * V_3 ,
int V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
unsigned int V_10 , V_11 ;
V_10 = F_2 ( V_3 -> V_12 ) ;
if ( V_10 > V_4 )
return F_3 ( - V_13 ) ;
V_7 = F_4 ( V_10 , V_14 ) ;
if ( ! V_7 )
return F_3 ( - V_15 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
V_6 = & V_7 -> V_16 [ V_11 ] ;
V_9 = & V_3 -> V_17 [ V_11 ] ;
V_6 -> V_18 = F_2 ( V_9 -> V_19 ) ;
V_6 -> V_20 = F_5 ( V_9 -> V_21 ) ;
switch ( V_6 -> V_18 ) {
case V_22 :
V_6 -> V_23 = F_6 ( F_2 ( V_9 -> V_24 ) ) ;
break;
case V_25 :
V_6 -> V_26 = F_7 ( F_2 ( V_9 -> V_24 ) ) ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
break;
default:
goto V_31;
}
}
return V_7 ;
V_31:
F_8 ( V_7 ) ;
return F_3 ( - V_32 ) ;
}
STATIC void
F_9 ( struct V_2 * V_3 , const struct V_1 * V_7 )
{
const struct V_5 * V_6 ;
struct V_8 * V_9 ;
int V_11 ;
V_3 -> V_12 = F_10 ( V_7 -> V_33 ) ;
for ( V_11 = 0 ; V_11 < V_7 -> V_33 ; V_11 ++ ) {
V_9 = & V_3 -> V_17 [ V_11 ] ;
V_6 = & V_7 -> V_16 [ V_11 ] ;
V_9 -> V_19 = F_10 ( V_6 -> V_18 ) ;
switch ( V_6 -> V_18 ) {
case V_22 :
V_9 -> V_24 = F_10 ( F_11 ( V_6 -> V_23 ) ) ;
break;
case V_25 :
V_9 -> V_24 = F_10 ( F_12 ( V_6 -> V_26 ) ) ;
break;
default:
V_9 -> V_24 = F_10 ( V_34 ) ;
break;
}
V_9 -> V_21 = F_13 ( V_6 -> V_20 ) ;
}
}
struct V_1 *
F_14 ( struct V_35 * V_35 , int type )
{
struct V_36 * V_37 = F_15 ( V_35 ) ;
struct V_1 * V_7 = NULL ;
struct V_2 * V_2 ;
unsigned char * V_38 ;
int error ;
int V_39 ;
F_16 ( V_37 ) ;
switch ( type ) {
case V_40 :
V_38 = V_41 ;
break;
case V_42 :
V_38 = V_43 ;
break;
default:
F_17 () ;
}
V_39 = F_18 ( V_37 -> V_44 ) ;
V_2 = F_19 ( V_39 , V_45 ) ;
if ( ! V_2 )
return F_3 ( - V_15 ) ;
error = - F_20 ( V_37 , V_38 , ( unsigned char * ) V_2 ,
& V_39 , V_46 ) ;
if ( error ) {
if ( error == - V_47 )
goto V_48;
goto V_49;
}
V_7 = F_1 ( V_2 , F_21 ( V_37 -> V_44 ) ) ;
if ( F_22 ( V_7 ) )
goto V_49;
V_48:
F_23 ( V_35 , type , V_7 ) ;
V_49:
F_24 ( V_2 ) ;
return V_7 ;
}
STATIC int
F_25 ( struct V_35 * V_35 , int type , struct V_1 * V_7 )
{
struct V_36 * V_37 = F_15 ( V_35 ) ;
unsigned char * V_38 ;
int error ;
switch ( type ) {
case V_40 :
V_38 = V_41 ;
break;
case V_42 :
if ( ! F_26 ( V_35 -> V_50 ) )
return V_7 ? - V_51 : 0 ;
V_38 = V_43 ;
break;
default:
return - V_32 ;
}
if ( V_7 ) {
struct V_2 * V_2 ;
int V_39 = F_18 ( V_37 -> V_44 ) ;
V_2 = F_19 ( V_39 , V_45 ) ;
if ( ! V_2 )
return - V_15 ;
F_9 ( V_2 , V_7 ) ;
V_39 -= sizeof( struct V_8 ) *
( F_21 ( V_37 -> V_44 ) - V_7 -> V_33 ) ;
error = - F_27 ( V_37 , V_38 , ( unsigned char * ) V_2 ,
V_39 , V_46 ) ;
F_24 ( V_2 ) ;
} else {
error = - F_28 ( V_37 , V_38 , V_46 ) ;
if ( error == - V_47 )
error = 0 ;
}
if ( ! error )
F_23 ( V_35 , type , V_7 ) ;
return error ;
}
static int
F_29 ( struct V_35 * V_35 , T_1 V_52 )
{
int error = 0 ;
if ( V_52 != V_35 -> V_50 ) {
struct V_53 V_53 ;
V_53 . V_54 = V_55 | V_56 ;
V_53 . V_57 = V_52 ;
V_53 . V_58 = F_30 ( V_35 -> V_59 ) ;
error = - F_31 ( F_15 ( V_35 ) , & V_53 , V_60 ) ;
}
return error ;
}
static int
F_32 ( struct V_35 * V_35 , unsigned char * V_61 )
{
int V_39 = F_18 ( F_33 ( V_35 -> V_59 ) ) ;
return ( F_20 ( F_15 ( V_35 ) , V_61 , NULL , & V_39 ,
V_46 | V_62 ) == 0 ) ;
}
int
F_34 ( struct V_35 * V_35 )
{
return F_32 ( V_35 , V_41 ) ;
}
int
F_35 ( struct V_35 * V_35 )
{
if ( ! F_26 ( V_35 -> V_50 ) )
return 0 ;
return F_32 ( V_35 , V_43 ) ;
}
int
F_36 ( struct V_35 * V_35 , struct V_1 * V_7 , int type )
{
int error = 0 ;
if ( ! V_7 )
goto V_63;
error = - V_32 ;
if ( V_7 -> V_33 > F_21 ( F_33 ( V_35 -> V_59 ) ) )
return error ;
if ( type == V_40 ) {
T_1 V_52 = V_35 -> V_50 ;
error = F_37 ( V_7 , & V_52 ) ;
if ( error <= 0 ) {
V_7 = NULL ;
if ( error < 0 )
return error ;
}
error = F_29 ( V_35 , V_52 ) ;
if ( error )
return error ;
}
V_63:
return F_25 ( V_35 , type , V_7 ) ;
}
