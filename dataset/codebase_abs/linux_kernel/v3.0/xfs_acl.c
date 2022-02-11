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
switch ( type ) {
case V_38 :
V_36 = V_39 ;
break;
case V_40 :
V_36 = V_41 ;
break;
default:
F_13 () ;
}
V_2 = F_14 ( sizeof( struct V_2 ) , V_12 ) ;
if ( ! V_2 )
return F_4 ( - V_13 ) ;
error = - F_15 ( V_34 , V_36 , ( unsigned char * ) V_2 ,
& V_35 , V_42 ) ;
if ( error ) {
if ( error == - V_43 ) {
V_6 = NULL ;
goto V_44;
}
goto V_45;
}
V_6 = F_1 ( V_2 ) ;
if ( F_16 ( V_6 ) )
goto V_45;
V_44:
F_17 ( V_32 , type , V_6 ) ;
V_45:
F_18 ( V_2 ) ;
return V_6 ;
}
STATIC int
F_19 ( struct V_32 * V_32 , int type , struct V_1 * V_6 )
{
struct V_33 * V_34 = F_11 ( V_32 ) ;
unsigned char * V_36 ;
int error ;
if ( F_20 ( V_32 -> V_46 ) )
return - V_47 ;
switch ( type ) {
case V_38 :
V_36 = V_39 ;
break;
case V_40 :
if ( ! F_21 ( V_32 -> V_46 ) )
return V_6 ? - V_48 : 0 ;
V_36 = V_41 ;
break;
default:
return - V_30 ;
}
if ( V_6 ) {
struct V_2 * V_2 ;
int V_35 ;
V_2 = F_14 ( sizeof( struct V_2 ) , V_12 ) ;
if ( ! V_2 )
return - V_13 ;
F_7 ( V_2 , V_6 ) ;
V_35 = sizeof( struct V_2 ) -
( sizeof( struct V_7 ) *
( V_49 - V_6 -> V_31 ) ) ;
error = - F_22 ( V_34 , V_36 , ( unsigned char * ) V_2 ,
V_35 , V_42 ) ;
F_18 ( V_2 ) ;
} else {
error = - F_23 ( V_34 , V_36 , V_42 ) ;
if ( error == - V_43 )
error = 0 ;
}
if ( ! error )
F_17 ( V_32 , type , V_6 ) ;
return error ;
}
int
F_24 ( struct V_32 * V_32 , int V_50 , unsigned int V_51 )
{
struct V_33 * V_34 ;
struct V_1 * V_6 ;
int error = - V_52 ;
V_34 = F_11 ( V_32 ) ;
F_25 ( V_34 ) ;
if ( ! F_26 ( V_34 ) )
return - V_52 ;
if ( V_51 & V_53 ) {
if ( ! F_27 ( V_32 , V_38 ) )
return - V_54 ;
return - V_52 ;
}
V_6 = F_10 ( V_32 , V_38 ) ;
if ( F_16 ( V_6 ) )
return F_28 ( V_6 ) ;
if ( V_6 ) {
error = F_29 ( V_32 , V_6 , V_50 ) ;
F_6 ( V_6 ) ;
}
return error ;
}
static int
F_30 ( struct V_32 * V_32 , T_1 V_55 )
{
int error = 0 ;
if ( V_55 != V_32 -> V_46 ) {
struct V_56 V_56 ;
V_56 . V_57 = V_58 | V_59 ;
V_56 . V_60 = V_55 ;
V_56 . V_61 = F_31 ( V_32 -> V_62 ) ;
error = - F_32 ( F_11 ( V_32 ) , & V_56 , V_63 ) ;
}
return error ;
}
static int
F_33 ( struct V_32 * V_32 , unsigned char * V_64 )
{
int V_35 = sizeof( struct V_2 ) ;
return ( F_15 ( F_11 ( V_32 ) , V_64 , NULL , & V_35 ,
V_42 | V_65 ) == 0 ) ;
}
int
F_34 ( struct V_32 * V_32 )
{
return F_33 ( V_32 , V_39 ) ;
}
int
F_35 ( struct V_32 * V_32 )
{
if ( ! F_21 ( V_32 -> V_46 ) )
return 0 ;
return F_33 ( V_32 , V_41 ) ;
}
int
F_36 ( struct V_32 * V_32 , struct V_1 * V_66 )
{
struct V_1 * V_67 ;
T_1 V_55 ;
int error = 0 , V_68 = 0 ;
if ( F_21 ( V_32 -> V_46 ) ) {
error = F_19 ( V_32 , V_40 , V_66 ) ;
if ( error )
return error ;
}
V_67 = F_37 ( V_66 , V_12 ) ;
if ( ! V_67 )
return - V_13 ;
V_55 = V_32 -> V_46 ;
error = F_38 ( V_67 , & V_55 ) ;
if ( error < 0 )
goto V_69;
if ( error > 0 )
V_68 = 1 ;
error = F_30 ( V_32 , V_55 ) ;
if ( error )
goto V_69;
if ( V_68 )
error = F_19 ( V_32 , V_38 , V_67 ) ;
V_69:
F_6 ( V_67 ) ;
return error ;
}
int
F_39 ( struct V_32 * V_32 )
{
struct V_1 * V_6 , * V_67 ;
int error ;
if ( F_20 ( V_32 -> V_46 ) )
return - V_47 ;
V_6 = F_10 ( V_32 , V_38 ) ;
if ( F_16 ( V_6 ) || ! V_6 )
return F_28 ( V_6 ) ;
V_67 = F_37 ( V_6 , V_12 ) ;
F_6 ( V_6 ) ;
if ( ! V_67 )
return - V_13 ;
error = F_40 ( V_67 , V_32 -> V_46 ) ;
if ( ! error )
error = F_19 ( V_32 , V_38 , V_67 ) ;
F_6 ( V_67 ) ;
return error ;
}
static int
F_41 ( struct V_70 * V_70 , const char * V_64 ,
void * V_71 , T_2 V_72 , int type )
{
struct V_1 * V_6 ;
int error ;
V_6 = F_10 ( V_70 -> V_73 , type ) ;
if ( F_16 ( V_6 ) )
return F_28 ( V_6 ) ;
if ( V_6 == NULL )
return - V_74 ;
error = F_42 ( V_6 , V_71 , V_72 ) ;
F_6 ( V_6 ) ;
return error ;
}
static int
F_43 ( struct V_70 * V_70 , const char * V_64 ,
const void * V_71 , T_2 V_72 , int V_51 , int type )
{
struct V_32 * V_32 = V_70 -> V_73 ;
struct V_1 * V_6 = NULL ;
int error = 0 ;
if ( V_51 & V_75 )
return - V_30 ;
if ( type == V_40 && ! F_21 ( V_32 -> V_46 ) )
return V_71 ? - V_48 : 0 ;
if ( ( F_44 () != V_32 -> V_76 ) && ! F_45 ( V_77 ) )
return - V_78 ;
if ( ! V_71 )
goto V_79;
V_6 = F_46 ( V_71 , V_72 ) ;
if ( ! V_6 ) {
goto V_45;
}
if ( F_16 ( V_6 ) ) {
error = F_28 ( V_6 ) ;
goto V_45;
}
error = F_47 ( V_6 ) ;
if ( error )
goto V_80;
error = - V_30 ;
if ( V_6 -> V_31 > V_49 )
goto V_80;
if ( type == V_38 ) {
T_1 V_55 = V_32 -> V_46 ;
error = F_48 ( V_6 , & V_55 ) ;
if ( error <= 0 ) {
F_6 ( V_6 ) ;
V_6 = NULL ;
if ( error < 0 )
return error ;
}
error = F_30 ( V_32 , V_55 ) ;
if ( error )
goto V_80;
}
V_79:
error = F_19 ( V_32 , type , V_6 ) ;
V_80:
F_6 ( V_6 ) ;
V_45:
return error ;
}
