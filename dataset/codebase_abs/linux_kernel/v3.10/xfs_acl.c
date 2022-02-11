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
case V_23 :
V_6 -> V_24 = F_2 ( V_9 -> V_25 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_6 -> V_24 = V_30 ;
break;
default:
goto V_31;
}
}
return V_7 ;
V_31:
F_6 ( V_7 ) ;
return F_3 ( - V_32 ) ;
}
STATIC void
F_7 ( struct V_2 * V_3 , const struct V_1 * V_7 )
{
const struct V_5 * V_6 ;
struct V_8 * V_9 ;
int V_11 ;
V_3 -> V_12 = F_8 ( V_7 -> V_33 ) ;
for ( V_11 = 0 ; V_11 < V_7 -> V_33 ; V_11 ++ ) {
V_9 = & V_3 -> V_17 [ V_11 ] ;
V_6 = & V_7 -> V_16 [ V_11 ] ;
V_9 -> V_19 = F_8 ( V_6 -> V_18 ) ;
V_9 -> V_25 = F_8 ( V_6 -> V_24 ) ;
V_9 -> V_21 = F_9 ( V_6 -> V_20 ) ;
}
}
struct V_1 *
F_10 ( struct V_34 * V_34 , int type )
{
struct V_35 * V_36 = F_11 ( V_34 ) ;
struct V_1 * V_7 ;
struct V_2 * V_2 ;
unsigned char * V_37 ;
int error ;
int V_38 ;
V_7 = F_12 ( V_34 , type ) ;
if ( V_7 != V_39 )
return V_7 ;
F_13 ( V_36 ) ;
switch ( type ) {
case V_40 :
V_37 = V_41 ;
break;
case V_42 :
V_37 = V_43 ;
break;
default:
F_14 () ;
}
V_38 = F_15 ( V_36 -> V_44 ) ;
V_2 = F_16 ( V_38 , V_14 ) ;
if ( ! V_2 )
return F_3 ( - V_15 ) ;
error = - F_17 ( V_36 , V_37 , ( unsigned char * ) V_2 ,
& V_38 , V_45 ) ;
if ( error ) {
if ( error == - V_46 ) {
V_7 = NULL ;
goto V_47;
}
goto V_48;
}
V_7 = F_1 ( V_2 , F_18 ( V_36 -> V_44 ) ) ;
if ( F_19 ( V_7 ) )
goto V_48;
V_47:
F_20 ( V_34 , type , V_7 ) ;
V_48:
F_21 ( V_2 ) ;
return V_7 ;
}
STATIC int
F_22 ( struct V_34 * V_34 , int type , struct V_1 * V_7 )
{
struct V_35 * V_36 = F_11 ( V_34 ) ;
unsigned char * V_37 ;
int error ;
if ( F_23 ( V_34 -> V_49 ) )
return - V_50 ;
switch ( type ) {
case V_40 :
V_37 = V_41 ;
break;
case V_42 :
if ( ! F_24 ( V_34 -> V_49 ) )
return V_7 ? - V_51 : 0 ;
V_37 = V_43 ;
break;
default:
return - V_32 ;
}
if ( V_7 ) {
struct V_2 * V_2 ;
int V_38 = F_15 ( V_36 -> V_44 ) ;
V_2 = F_16 ( V_38 , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
F_7 ( V_2 , V_7 ) ;
V_38 -= sizeof( struct V_8 ) *
( F_18 ( V_36 -> V_44 ) - V_7 -> V_33 ) ;
error = - F_25 ( V_36 , V_37 , ( unsigned char * ) V_2 ,
V_38 , V_45 ) ;
F_21 ( V_2 ) ;
} else {
error = - F_26 ( V_36 , V_37 , V_45 ) ;
if ( error == - V_46 )
error = 0 ;
}
if ( ! error )
F_20 ( V_34 , type , V_7 ) ;
return error ;
}
static int
F_27 ( struct V_34 * V_34 , T_1 V_52 )
{
int error = 0 ;
if ( V_52 != V_34 -> V_49 ) {
struct V_53 V_53 ;
V_53 . V_54 = V_55 | V_56 ;
V_53 . V_57 = V_52 ;
V_53 . V_58 = F_28 ( V_34 -> V_59 ) ;
error = - F_29 ( F_11 ( V_34 ) , & V_53 , V_60 ) ;
}
return error ;
}
static int
F_30 ( struct V_34 * V_34 , unsigned char * V_61 )
{
int V_38 = F_15 ( F_31 ( V_34 -> V_59 ) ) ;
return ( F_17 ( F_11 ( V_34 ) , V_61 , NULL , & V_38 ,
V_45 | V_62 ) == 0 ) ;
}
int
F_32 ( struct V_34 * V_34 )
{
return F_30 ( V_34 , V_41 ) ;
}
int
F_33 ( struct V_34 * V_34 )
{
if ( ! F_24 ( V_34 -> V_49 ) )
return 0 ;
return F_30 ( V_34 , V_43 ) ;
}
int
F_34 ( struct V_34 * V_34 , struct V_1 * V_7 )
{
T_1 V_52 = V_34 -> V_49 ;
int error = 0 , V_63 = 0 ;
if ( F_24 ( V_34 -> V_49 ) ) {
error = F_22 ( V_34 , V_42 , V_7 ) ;
if ( error )
goto V_48;
}
error = F_35 ( & V_7 , V_14 , & V_52 ) ;
if ( error < 0 )
return error ;
if ( error > 0 )
V_63 = 1 ;
error = F_27 ( V_34 , V_52 ) ;
if ( error )
goto V_48;
if ( V_63 )
error = F_22 ( V_34 , V_40 , V_7 ) ;
V_48:
F_6 ( V_7 ) ;
return error ;
}
int
F_36 ( struct V_34 * V_34 )
{
struct V_1 * V_7 ;
int error ;
if ( F_23 ( V_34 -> V_49 ) )
return - V_50 ;
V_7 = F_10 ( V_34 , V_40 ) ;
if ( F_19 ( V_7 ) || ! V_7 )
return F_37 ( V_7 ) ;
error = F_38 ( & V_7 , V_14 , V_34 -> V_49 ) ;
if ( error )
return error ;
error = F_22 ( V_34 , V_40 , V_7 ) ;
F_6 ( V_7 ) ;
return error ;
}
static int
F_39 ( struct V_64 * V_64 , const char * V_61 ,
void * V_65 , T_2 V_66 , int type )
{
struct V_1 * V_7 ;
int error ;
V_7 = F_10 ( V_64 -> V_67 , type ) ;
if ( F_19 ( V_7 ) )
return F_37 ( V_7 ) ;
if ( V_7 == NULL )
return - V_68 ;
error = F_40 ( & V_69 , V_7 , V_65 , V_66 ) ;
F_6 ( V_7 ) ;
return error ;
}
static int
F_41 ( struct V_64 * V_64 , const char * V_61 ,
const void * V_65 , T_2 V_66 , int V_70 , int type )
{
struct V_34 * V_34 = V_64 -> V_67 ;
struct V_1 * V_7 = NULL ;
int error = 0 ;
if ( V_70 & V_71 )
return - V_32 ;
if ( type == V_42 && ! F_24 ( V_34 -> V_49 ) )
return V_65 ? - V_51 : 0 ;
if ( ( F_42 () != V_34 -> V_72 ) && ! F_43 ( V_73 ) )
return - V_74 ;
if ( ! V_65 )
goto V_75;
V_7 = F_44 ( & V_69 , V_65 , V_66 ) ;
if ( ! V_7 ) {
goto V_48;
}
if ( F_19 ( V_7 ) ) {
error = F_37 ( V_7 ) ;
goto V_48;
}
error = F_45 ( V_7 ) ;
if ( error )
goto V_76;
error = - V_32 ;
if ( V_7 -> V_33 > F_18 ( F_31 ( V_34 -> V_59 ) ) )
goto V_76;
if ( type == V_40 ) {
T_1 V_52 = V_34 -> V_49 ;
error = F_46 ( V_7 , & V_52 ) ;
if ( error <= 0 ) {
F_6 ( V_7 ) ;
V_7 = NULL ;
if ( error < 0 )
return error ;
}
error = F_27 ( V_34 , V_52 ) ;
if ( error )
goto V_76;
}
V_75:
error = F_22 ( V_34 , type , V_7 ) ;
V_76:
F_6 ( V_7 ) ;
V_48:
return error ;
}
