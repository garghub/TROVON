STATIC struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
V_9 = F_2 ( V_3 -> V_11 ) ;
V_6 = F_3 ( V_9 , V_12 ) ;
if ( ! V_6 )
return F_4 ( - V_13 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
V_5 = & V_6 -> V_14 [ V_10 ] ;
V_8 = & V_3 -> V_15 [ V_10 ] ;
V_5 -> V_16 = F_2 ( V_8 -> V_17 ) ;
V_5 -> V_18 = F_5 ( V_8 -> V_19 ) ;
switch ( V_5 -> V_16 ) {
case V_20 :
case V_21 :
V_5 -> V_22 = F_2 ( V_8 -> V_23 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_5 -> V_22 = V_28 ;
break;
default:
goto V_29;
}
}
return V_6 ;
V_29:
F_6 ( V_6 ) ;
return F_4 ( - V_30 ) ;
}
STATIC void
F_7 ( struct V_2 * V_3 , const struct V_1 * V_6 )
{
const struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_10 ;
V_3 -> V_11 = F_8 ( V_6 -> V_31 ) ;
for ( V_10 = 0 ; V_10 < V_6 -> V_31 ; V_10 ++ ) {
V_8 = & V_3 -> V_15 [ V_10 ] ;
V_5 = & V_6 -> V_14 [ V_10 ] ;
V_8 -> V_17 = F_8 ( V_5 -> V_16 ) ;
V_8 -> V_23 = F_8 ( V_5 -> V_22 ) ;
V_8 -> V_19 = F_9 ( V_5 -> V_18 ) ;
}
}
struct V_1 *
F_10 ( struct V_32 * V_32 , int type )
{
struct V_33 * V_34 = F_11 ( V_32 ) ;
struct V_1 * V_6 ;
struct V_2 * V_2 ;
int V_35 = sizeof( struct V_2 ) ;
unsigned char * V_36 ;
int error ;
V_6 = F_12 ( V_32 , type ) ;
if ( V_6 != V_37 )
return V_6 ;
F_13 ( V_34 ) ;
switch ( type ) {
case V_38 :
V_36 = V_39 ;
break;
case V_40 :
V_36 = V_41 ;
break;
default:
F_14 () ;
}
V_2 = F_15 ( sizeof( struct V_2 ) , V_12 ) ;
if ( ! V_2 )
return F_4 ( - V_13 ) ;
error = - F_16 ( V_34 , V_36 , ( unsigned char * ) V_2 ,
& V_35 , V_42 ) ;
if ( error ) {
if ( error == - V_43 ) {
V_6 = NULL ;
goto V_44;
}
goto V_45;
}
V_6 = F_1 ( V_2 ) ;
if ( F_17 ( V_6 ) )
goto V_45;
V_44:
F_18 ( V_32 , type , V_6 ) ;
V_45:
F_19 ( V_2 ) ;
return V_6 ;
}
STATIC int
F_20 ( struct V_32 * V_32 , int type , struct V_1 * V_6 )
{
struct V_33 * V_34 = F_11 ( V_32 ) ;
unsigned char * V_36 ;
int error ;
if ( F_21 ( V_32 -> V_46 ) )
return - V_47 ;
switch ( type ) {
case V_38 :
V_36 = V_39 ;
break;
case V_40 :
if ( ! F_22 ( V_32 -> V_46 ) )
return V_6 ? - V_48 : 0 ;
V_36 = V_41 ;
break;
default:
return - V_30 ;
}
if ( V_6 ) {
struct V_2 * V_2 ;
int V_35 ;
V_2 = F_15 ( sizeof( struct V_2 ) , V_12 ) ;
if ( ! V_2 )
return - V_13 ;
F_7 ( V_2 , V_6 ) ;
V_35 = sizeof( struct V_2 ) -
( sizeof( struct V_7 ) *
( V_49 - V_6 -> V_31 ) ) ;
error = - F_23 ( V_34 , V_36 , ( unsigned char * ) V_2 ,
V_35 , V_42 ) ;
F_19 ( V_2 ) ;
} else {
error = - F_24 ( V_34 , V_36 , V_42 ) ;
if ( error == - V_43 )
error = 0 ;
}
if ( ! error )
F_18 ( V_32 , type , V_6 ) ;
return error ;
}
static int
F_25 ( struct V_32 * V_32 , T_1 V_50 )
{
int error = 0 ;
if ( V_50 != V_32 -> V_46 ) {
struct V_51 V_51 ;
V_51 . V_52 = V_53 | V_54 ;
V_51 . V_55 = V_50 ;
V_51 . V_56 = F_26 ( V_32 -> V_57 ) ;
error = - F_27 ( F_11 ( V_32 ) , & V_51 , V_58 ) ;
}
return error ;
}
static int
F_28 ( struct V_32 * V_32 , unsigned char * V_59 )
{
int V_35 = sizeof( struct V_2 ) ;
return ( F_16 ( F_11 ( V_32 ) , V_59 , NULL , & V_35 ,
V_42 | V_60 ) == 0 ) ;
}
int
F_29 ( struct V_32 * V_32 )
{
return F_28 ( V_32 , V_39 ) ;
}
int
F_30 ( struct V_32 * V_32 )
{
if ( ! F_22 ( V_32 -> V_46 ) )
return 0 ;
return F_28 ( V_32 , V_41 ) ;
}
int
F_31 ( struct V_32 * V_32 , struct V_1 * V_6 )
{
T_1 V_50 = V_32 -> V_46 ;
int error = 0 , V_61 = 0 ;
if ( F_22 ( V_32 -> V_46 ) ) {
error = F_20 ( V_32 , V_40 , V_6 ) ;
if ( error )
goto V_45;
}
error = F_32 ( & V_6 , V_12 , & V_50 ) ;
if ( error < 0 )
return error ;
if ( error > 0 )
V_61 = 1 ;
error = F_25 ( V_32 , V_50 ) ;
if ( error )
goto V_45;
if ( V_61 )
error = F_20 ( V_32 , V_38 , V_6 ) ;
V_45:
F_6 ( V_6 ) ;
return error ;
}
int
F_33 ( struct V_32 * V_32 )
{
struct V_1 * V_6 ;
int error ;
if ( F_21 ( V_32 -> V_46 ) )
return - V_47 ;
V_6 = F_10 ( V_32 , V_38 ) ;
if ( F_17 ( V_6 ) || ! V_6 )
return F_34 ( V_6 ) ;
error = F_35 ( & V_6 , V_12 , V_32 -> V_46 ) ;
if ( error )
return error ;
error = F_20 ( V_32 , V_38 , V_6 ) ;
F_6 ( V_6 ) ;
return error ;
}
static int
F_36 ( struct V_62 * V_62 , const char * V_59 ,
void * V_63 , T_2 V_64 , int type )
{
struct V_1 * V_6 ;
int error ;
V_6 = F_10 ( V_62 -> V_65 , type ) ;
if ( F_17 ( V_6 ) )
return F_34 ( V_6 ) ;
if ( V_6 == NULL )
return - V_66 ;
error = F_37 ( V_6 , V_63 , V_64 ) ;
F_6 ( V_6 ) ;
return error ;
}
static int
F_38 ( struct V_62 * V_62 , const char * V_59 ,
const void * V_63 , T_2 V_64 , int V_67 , int type )
{
struct V_32 * V_32 = V_62 -> V_65 ;
struct V_1 * V_6 = NULL ;
int error = 0 ;
if ( V_67 & V_68 )
return - V_30 ;
if ( type == V_40 && ! F_22 ( V_32 -> V_46 ) )
return V_63 ? - V_48 : 0 ;
if ( ( F_39 () != V_32 -> V_69 ) && ! F_40 ( V_70 ) )
return - V_71 ;
if ( ! V_63 )
goto V_72;
V_6 = F_41 ( V_63 , V_64 ) ;
if ( ! V_6 ) {
goto V_45;
}
if ( F_17 ( V_6 ) ) {
error = F_34 ( V_6 ) ;
goto V_45;
}
error = F_42 ( V_6 ) ;
if ( error )
goto V_73;
error = - V_30 ;
if ( V_6 -> V_31 > V_49 )
goto V_73;
if ( type == V_38 ) {
T_1 V_50 = V_32 -> V_46 ;
error = F_43 ( V_6 , & V_50 ) ;
if ( error <= 0 ) {
F_6 ( V_6 ) ;
V_6 = NULL ;
if ( error < 0 )
return error ;
}
error = F_25 ( V_32 , V_50 ) ;
if ( error )
goto V_73;
}
V_72:
error = F_20 ( V_32 , type , V_6 ) ;
V_73:
F_6 ( V_6 ) ;
V_45:
return error ;
}
