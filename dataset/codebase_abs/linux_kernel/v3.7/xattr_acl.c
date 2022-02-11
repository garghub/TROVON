static int
F_1 ( struct V_1 * V_1 , const char * V_2 , const void * V_3 ,
T_1 V_4 , int V_5 , int type )
{
struct V_6 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 ;
int error , V_10 ;
struct V_11 V_12 ;
T_1 V_13 ;
if ( ! F_2 ( V_6 -> V_14 ) )
return - V_15 ;
if ( ! F_3 ( V_6 ) )
return - V_16 ;
if ( V_3 ) {
V_9 = F_4 ( & V_17 , V_3 , V_4 ) ;
if ( F_5 ( V_9 ) ) {
return F_6 ( V_9 ) ;
} else if ( V_9 ) {
error = F_7 ( V_9 ) ;
if ( error )
goto V_18;
}
} else
V_9 = NULL ;
V_13 = F_8 ( V_6 ) +
F_9 ( V_6 , V_4 ) * 2 ;
F_10 ( V_6 -> V_14 ) ;
error = F_11 ( & V_12 , V_6 -> V_14 , V_13 ) ;
if ( error == 0 ) {
error = F_12 ( & V_12 , V_6 , type , V_9 ) ;
V_10 = F_13 ( & V_12 , V_6 -> V_14 , V_13 ) ;
if ( V_10 )
error = V_10 ;
}
F_14 ( V_6 -> V_14 ) ;
V_18:
F_15 ( V_9 ) ;
return error ;
}
static int
F_16 ( struct V_1 * V_1 , const char * V_2 , void * V_19 ,
T_1 V_4 , int type )
{
struct V_8 * V_9 ;
int error ;
if ( ! F_2 ( V_1 -> V_20 ) )
return - V_15 ;
V_9 = F_17 ( V_1 -> V_7 , type ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
if ( V_9 == NULL )
return - V_21 ;
error = F_18 ( & V_17 , V_9 , V_19 , V_4 ) ;
F_15 ( V_9 ) ;
return error ;
}
static struct V_8 * F_19 ( const void * V_3 , T_1 V_4 )
{
const char * V_22 = ( char * ) V_3 + V_4 ;
int V_23 , V_24 ;
struct V_8 * V_9 ;
if ( ! V_3 )
return NULL ;
if ( V_4 < sizeof( V_25 ) )
return F_20 ( - V_26 ) ;
if ( ( ( V_25 * ) V_3 ) -> V_27 !=
F_21 ( V_28 ) )
return F_20 ( - V_26 ) ;
V_3 = ( char * ) V_3 + sizeof( V_25 ) ;
V_24 = F_22 ( V_4 ) ;
if ( V_24 < 0 )
return F_20 ( - V_26 ) ;
if ( V_24 == 0 )
return NULL ;
V_9 = F_23 ( V_24 , V_29 ) ;
if ( ! V_9 )
return F_20 ( - V_30 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
T_2 * V_31 = ( T_2 * ) V_3 ;
if ( ( char * ) V_3 + sizeof( V_32 ) > V_22 )
goto V_33;
V_9 -> V_34 [ V_23 ] . V_35 = F_24 ( V_31 -> V_35 ) ;
V_9 -> V_34 [ V_23 ] . V_36 = F_24 ( V_31 -> V_36 ) ;
switch ( V_9 -> V_34 [ V_23 ] . V_35 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_3 = ( char * ) V_3 +
sizeof( V_32 ) ;
break;
case V_41 :
V_3 = ( char * ) V_3 + sizeof( T_2 ) ;
if ( ( char * ) V_3 > V_22 )
goto V_33;
V_9 -> V_34 [ V_23 ] . V_42 =
F_25 ( & V_17 ,
F_26 ( V_31 -> V_43 ) ) ;
break;
case V_44 :
V_3 = ( char * ) V_3 + sizeof( T_2 ) ;
if ( ( char * ) V_3 > V_22 )
goto V_33;
V_9 -> V_34 [ V_23 ] . V_45 =
F_27 ( & V_17 ,
F_26 ( V_31 -> V_43 ) ) ;
break;
default:
goto V_33;
}
}
if ( V_3 != V_22 )
goto V_33;
return V_9 ;
V_33:
F_15 ( V_9 ) ;
return F_20 ( - V_26 ) ;
}
static void * F_28 ( const struct V_8 * V_9 , T_1 * V_4 )
{
V_25 * V_46 ;
char * V_47 ;
int V_23 ;
* V_4 = F_29 ( V_9 -> V_48 ) ;
V_46 = F_30 ( sizeof( V_25 ) +
V_9 -> V_48 *
sizeof( T_2 ) ,
V_29 ) ;
if ( ! V_46 )
return F_20 ( - V_30 ) ;
V_46 -> V_27 = F_21 ( V_28 ) ;
V_47 = ( char * ) V_46 + sizeof( V_25 ) ;
for ( V_23 = 0 ; V_23 < V_9 -> V_48 ; V_23 ++ ) {
const struct V_49 * V_50 = & V_9 -> V_34 [ V_23 ] ;
T_2 * V_31 = ( T_2 * ) V_47 ;
V_31 -> V_35 = F_31 ( V_9 -> V_34 [ V_23 ] . V_35 ) ;
V_31 -> V_36 = F_31 ( V_9 -> V_34 [ V_23 ] . V_36 ) ;
switch ( V_9 -> V_34 [ V_23 ] . V_35 ) {
case V_41 :
V_31 -> V_43 = F_21 (
F_32 ( & V_17 , V_50 -> V_42 ) ) ;
V_47 += sizeof( T_2 ) ;
break;
case V_44 :
V_31 -> V_43 = F_21 (
F_33 ( & V_17 , V_50 -> V_45 ) ) ;
V_47 += sizeof( T_2 ) ;
break;
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_47 += sizeof( V_32 ) ;
break;
default:
goto V_33;
}
}
return ( char * ) V_46 ;
V_33:
F_34 ( V_46 ) ;
return F_20 ( - V_26 ) ;
}
struct V_8 * F_17 ( struct V_6 * V_6 , int type )
{
char * V_2 , * V_3 ;
struct V_8 * V_9 ;
int V_4 ;
int V_51 ;
V_9 = F_35 ( V_6 , type ) ;
if ( V_9 != V_52 )
return V_9 ;
switch ( type ) {
case V_53 :
V_2 = V_54 ;
break;
case V_55 :
V_2 = V_56 ;
break;
default:
F_36 () ;
}
V_4 = F_37 ( V_6 , V_2 , NULL , 0 ) ;
if ( V_4 < 0 ) {
if ( V_4 == - V_21 || V_4 == - V_57 ) {
F_38 ( V_6 , type , NULL ) ;
return NULL ;
}
return F_20 ( V_4 ) ;
}
V_3 = F_30 ( V_4 , V_29 ) ;
if ( ! V_3 )
return F_20 ( - V_30 ) ;
V_51 = F_37 ( V_6 , V_2 , V_3 , V_4 ) ;
if ( V_51 == - V_21 || V_51 == - V_57 ) {
V_9 = NULL ;
} else if ( V_51 < 0 ) {
V_9 = F_20 ( V_51 ) ;
} else {
V_9 = F_19 ( V_3 , V_51 ) ;
}
if ( ! F_5 ( V_9 ) )
F_38 ( V_6 , type , V_9 ) ;
F_34 ( V_3 ) ;
return V_9 ;
}
static int
F_12 ( struct V_11 * V_12 , struct V_6 * V_6 ,
int type , struct V_8 * V_9 )
{
char * V_2 ;
void * V_3 = NULL ;
T_1 V_4 = 0 ;
int error ;
if ( F_39 ( V_6 -> V_58 ) )
return - V_15 ;
switch ( type ) {
case V_53 :
V_2 = V_54 ;
if ( V_9 ) {
error = F_40 ( V_9 , & V_6 -> V_58 ) ;
if ( error < 0 )
return error ;
else {
if ( error == 0 )
V_9 = NULL ;
}
}
break;
case V_55 :
V_2 = V_56 ;
if ( ! F_41 ( V_6 -> V_58 ) )
return V_9 ? - V_59 : 0 ;
break;
default:
return - V_26 ;
}
if ( V_9 ) {
V_3 = F_28 ( V_9 , & V_4 ) ;
if ( F_5 ( V_3 ) )
return ( int ) F_6 ( V_3 ) ;
}
error = F_42 ( V_12 , V_6 , V_2 , V_3 , V_4 , 0 ) ;
if ( error == - V_21 ) {
error = 0 ;
if ( type == V_53 ) {
V_6 -> V_60 = V_61 ;
F_43 ( V_6 ) ;
}
}
F_34 ( V_3 ) ;
if ( ! error )
F_38 ( V_6 , type , V_9 ) ;
return error ;
}
int
F_44 ( struct V_11 * V_12 ,
struct V_6 * V_62 , struct V_1 * V_1 ,
struct V_6 * V_6 )
{
struct V_8 * V_9 ;
int V_63 = 0 ;
if ( F_39 ( V_6 -> V_58 ) )
return 0 ;
if ( F_45 ( V_62 ) == V_64 )
goto V_65;
if ( F_46 ( V_62 ) ) {
V_6 -> V_66 |= V_67 ;
goto V_65;
}
V_9 = F_17 ( V_62 , V_55 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
if ( V_9 ) {
if ( F_41 ( V_6 -> V_58 ) ) {
V_63 = F_12 ( V_12 , V_6 , V_55 ,
V_9 ) ;
if ( V_63 )
goto V_68;
}
V_63 = F_47 ( & V_9 , V_29 , & V_6 -> V_58 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_63 > 0 )
V_63 = F_12 ( V_12 , V_6 , V_53 , V_9 ) ;
V_68:
F_15 ( V_9 ) ;
} else {
V_65:
V_6 -> V_58 &= ~ F_48 () ;
}
return V_63 ;
}
int F_49 ( struct V_6 * V_6 )
{
struct V_8 * V_9 ;
int V_69 = 0 ;
if ( F_46 ( V_6 ) )
return 0 ;
V_9 = F_17 ( V_6 , V_55 ) ;
if ( V_9 && ! F_5 ( V_9 ) ) {
int V_4 = F_29 ( V_9 -> V_48 ) ;
V_69 = F_8 ( V_6 ) ;
V_69 += F_50 ( V_6 -> V_14 ) ;
F_51 ( V_6 ) -> V_66 |= V_70 ;
V_69 += F_9 ( V_6 , V_4 ) * 4 ;
F_15 ( V_9 ) ;
}
return V_69 ;
}
int F_52 ( struct V_6 * V_6 )
{
struct V_11 V_12 ;
struct V_8 * V_9 ;
T_1 V_4 ;
int V_71 ;
int error ;
if ( F_39 ( V_6 -> V_58 ) )
return - V_15 ;
if ( F_45 ( V_6 ) == V_64 ||
! F_2 ( V_6 -> V_14 ) ) {
return 0 ;
}
F_14 ( V_6 -> V_14 ) ;
V_9 = F_17 ( V_6 , V_53 ) ;
F_10 ( V_6 -> V_14 ) ;
if ( ! V_9 )
return 0 ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
error = F_53 ( & V_9 , V_29 , V_6 -> V_58 ) ;
if ( error )
return error ;
V_4 = F_9 ( V_6 , F_29 ( V_9 -> V_48 ) ) ;
V_71 = F_54 ( V_6 -> V_14 ) ;
error = F_11 ( & V_12 , V_6 -> V_14 , V_4 * 2 ) ;
if ( ! error ) {
int V_10 ;
error = F_12 ( & V_12 , V_6 , V_53 , V_9 ) ;
V_10 = F_13 ( & V_12 , V_6 -> V_14 , V_4 * 2 ) ;
if ( V_10 )
error = V_10 ;
}
F_55 ( V_6 -> V_14 , V_71 ) ;
F_15 ( V_9 ) ;
return error ;
}
static T_1 F_56 ( struct V_1 * V_1 , char * V_72 ,
T_1 V_73 , const char * V_2 ,
T_1 V_74 , int type )
{
const T_1 V_4 = sizeof( V_54 ) ;
if ( ! F_2 ( V_1 -> V_20 ) )
return 0 ;
if ( V_72 && V_4 <= V_73 )
memcpy ( V_72 , V_54 , V_4 ) ;
return V_4 ;
}
static T_1 F_57 ( struct V_1 * V_1 , char * V_72 ,
T_1 V_73 , const char * V_2 ,
T_1 V_74 , int type )
{
const T_1 V_4 = sizeof( V_56 ) ;
if ( ! F_2 ( V_1 -> V_20 ) )
return 0 ;
if ( V_72 && V_4 <= V_73 )
memcpy ( V_72 , V_56 , V_4 ) ;
return V_4 ;
}
