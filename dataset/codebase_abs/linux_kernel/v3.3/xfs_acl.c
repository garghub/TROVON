STATIC struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 , V_10 ;
V_9 = F_2 ( V_3 -> V_11 ) ;
if ( V_9 > V_12 )
return F_3 ( - V_13 ) ;
V_6 = F_4 ( V_9 , V_14 ) ;
if ( ! V_6 )
return F_3 ( - V_15 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
V_5 = & V_6 -> V_16 [ V_10 ] ;
V_8 = & V_3 -> V_17 [ V_10 ] ;
V_5 -> V_18 = F_2 ( V_8 -> V_19 ) ;
V_5 -> V_20 = F_5 ( V_8 -> V_21 ) ;
switch ( V_5 -> V_18 ) {
case V_22 :
case V_23 :
V_5 -> V_24 = F_2 ( V_8 -> V_25 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_5 -> V_24 = V_30 ;
break;
default:
goto V_31;
}
}
return V_6 ;
V_31:
F_6 ( V_6 ) ;
return F_3 ( - V_32 ) ;
}
STATIC void
F_7 ( struct V_2 * V_3 , const struct V_1 * V_6 )
{
const struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_10 ;
V_3 -> V_11 = F_8 ( V_6 -> V_33 ) ;
for ( V_10 = 0 ; V_10 < V_6 -> V_33 ; V_10 ++ ) {
V_8 = & V_3 -> V_17 [ V_10 ] ;
V_5 = & V_6 -> V_16 [ V_10 ] ;
V_8 -> V_19 = F_8 ( V_5 -> V_18 ) ;
V_8 -> V_25 = F_8 ( V_5 -> V_24 ) ;
V_8 -> V_21 = F_9 ( V_5 -> V_20 ) ;
}
}
struct V_1 *
F_10 ( struct V_34 * V_34 , int type )
{
struct V_35 * V_36 = F_11 ( V_34 ) ;
struct V_1 * V_6 ;
struct V_2 * V_2 ;
int V_37 = sizeof( struct V_2 ) ;
unsigned char * V_38 ;
int error ;
V_6 = F_12 ( V_34 , type ) ;
if ( V_6 != V_39 )
return V_6 ;
F_13 ( V_36 ) ;
switch ( type ) {
case V_40 :
V_38 = V_41 ;
break;
case V_42 :
V_38 = V_43 ;
break;
default:
F_14 () ;
}
V_2 = F_15 ( sizeof( struct V_2 ) , V_14 ) ;
if ( ! V_2 )
return F_3 ( - V_15 ) ;
error = - F_16 ( V_36 , V_38 , ( unsigned char * ) V_2 ,
& V_37 , V_44 ) ;
if ( error ) {
if ( error == - V_45 ) {
V_6 = NULL ;
goto V_46;
}
goto V_47;
}
V_6 = F_1 ( V_2 ) ;
if ( F_17 ( V_6 ) )
goto V_47;
V_46:
F_18 ( V_34 , type , V_6 ) ;
V_47:
F_19 ( V_2 ) ;
return V_6 ;
}
STATIC int
F_20 ( struct V_34 * V_34 , int type , struct V_1 * V_6 )
{
struct V_35 * V_36 = F_11 ( V_34 ) ;
unsigned char * V_38 ;
int error ;
if ( F_21 ( V_34 -> V_48 ) )
return - V_49 ;
switch ( type ) {
case V_40 :
V_38 = V_41 ;
break;
case V_42 :
if ( ! F_22 ( V_34 -> V_48 ) )
return V_6 ? - V_50 : 0 ;
V_38 = V_43 ;
break;
default:
return - V_32 ;
}
if ( V_6 ) {
struct V_2 * V_2 ;
int V_37 ;
V_2 = F_15 ( sizeof( struct V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
F_7 ( V_2 , V_6 ) ;
V_37 = sizeof( struct V_2 ) -
( sizeof( struct V_7 ) *
( V_12 - V_6 -> V_33 ) ) ;
error = - F_23 ( V_36 , V_38 , ( unsigned char * ) V_2 ,
V_37 , V_44 ) ;
F_19 ( V_2 ) ;
} else {
error = - F_24 ( V_36 , V_38 , V_44 ) ;
if ( error == - V_45 )
error = 0 ;
}
if ( ! error )
F_18 ( V_34 , type , V_6 ) ;
return error ;
}
static int
F_25 ( struct V_34 * V_34 , T_1 V_51 )
{
int error = 0 ;
if ( V_51 != V_34 -> V_48 ) {
struct V_52 V_52 ;
V_52 . V_53 = V_54 | V_55 ;
V_52 . V_56 = V_51 ;
V_52 . V_57 = F_26 ( V_34 -> V_58 ) ;
error = - F_27 ( F_11 ( V_34 ) , & V_52 , V_59 ) ;
}
return error ;
}
static int
F_28 ( struct V_34 * V_34 , unsigned char * V_60 )
{
int V_37 = sizeof( struct V_2 ) ;
return ( F_16 ( F_11 ( V_34 ) , V_60 , NULL , & V_37 ,
V_44 | V_61 ) == 0 ) ;
}
int
F_29 ( struct V_34 * V_34 )
{
return F_28 ( V_34 , V_41 ) ;
}
int
F_30 ( struct V_34 * V_34 )
{
if ( ! F_22 ( V_34 -> V_48 ) )
return 0 ;
return F_28 ( V_34 , V_43 ) ;
}
int
F_31 ( struct V_34 * V_34 , struct V_1 * V_6 )
{
T_1 V_51 = V_34 -> V_48 ;
int error = 0 , V_62 = 0 ;
if ( F_22 ( V_34 -> V_48 ) ) {
error = F_20 ( V_34 , V_42 , V_6 ) ;
if ( error )
goto V_47;
}
error = F_32 ( & V_6 , V_14 , & V_51 ) ;
if ( error < 0 )
return error ;
if ( error > 0 )
V_62 = 1 ;
error = F_25 ( V_34 , V_51 ) ;
if ( error )
goto V_47;
if ( V_62 )
error = F_20 ( V_34 , V_40 , V_6 ) ;
V_47:
F_6 ( V_6 ) ;
return error ;
}
int
F_33 ( struct V_34 * V_34 )
{
struct V_1 * V_6 ;
int error ;
if ( F_21 ( V_34 -> V_48 ) )
return - V_49 ;
V_6 = F_10 ( V_34 , V_40 ) ;
if ( F_17 ( V_6 ) || ! V_6 )
return F_34 ( V_6 ) ;
error = F_35 ( & V_6 , V_14 , V_34 -> V_48 ) ;
if ( error )
return error ;
error = F_20 ( V_34 , V_40 , V_6 ) ;
F_6 ( V_6 ) ;
return error ;
}
static int
F_36 ( struct V_63 * V_63 , const char * V_60 ,
void * V_64 , T_2 V_65 , int type )
{
struct V_1 * V_6 ;
int error ;
V_6 = F_10 ( V_63 -> V_66 , type ) ;
if ( F_17 ( V_6 ) )
return F_34 ( V_6 ) ;
if ( V_6 == NULL )
return - V_67 ;
error = F_37 ( V_6 , V_64 , V_65 ) ;
F_6 ( V_6 ) ;
return error ;
}
static int
F_38 ( struct V_63 * V_63 , const char * V_60 ,
const void * V_64 , T_2 V_65 , int V_68 , int type )
{
struct V_34 * V_34 = V_63 -> V_66 ;
struct V_1 * V_6 = NULL ;
int error = 0 ;
if ( V_68 & V_69 )
return - V_32 ;
if ( type == V_42 && ! F_22 ( V_34 -> V_48 ) )
return V_64 ? - V_50 : 0 ;
if ( ( F_39 () != V_34 -> V_70 ) && ! F_40 ( V_71 ) )
return - V_72 ;
if ( ! V_64 )
goto V_73;
V_6 = F_41 ( V_64 , V_65 ) ;
if ( ! V_6 ) {
goto V_47;
}
if ( F_17 ( V_6 ) ) {
error = F_34 ( V_6 ) ;
goto V_47;
}
error = F_42 ( V_6 ) ;
if ( error )
goto V_74;
error = - V_32 ;
if ( V_6 -> V_33 > V_12 )
goto V_74;
if ( type == V_40 ) {
T_1 V_51 = V_34 -> V_48 ;
error = F_43 ( V_6 , & V_51 ) ;
if ( error <= 0 ) {
F_6 ( V_6 ) ;
V_6 = NULL ;
if ( error < 0 )
return error ;
}
error = F_25 ( V_34 , V_51 ) ;
if ( error )
goto V_74;
}
V_73:
error = F_20 ( V_34 , type , V_6 ) ;
V_74:
F_6 ( V_6 ) ;
V_47:
return error ;
}
