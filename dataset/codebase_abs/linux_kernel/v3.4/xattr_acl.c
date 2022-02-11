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
V_9 = F_4 ( V_3 , V_4 ) ;
if ( F_5 ( V_9 ) ) {
return F_6 ( V_9 ) ;
} else if ( V_9 ) {
error = F_7 ( V_9 ) ;
if ( error )
goto V_17;
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
V_17:
F_15 ( V_9 ) ;
return error ;
}
static int
F_16 ( struct V_1 * V_1 , const char * V_2 , void * V_18 ,
T_1 V_4 , int type )
{
struct V_8 * V_9 ;
int error ;
if ( ! F_2 ( V_1 -> V_19 ) )
return - V_15 ;
V_9 = F_17 ( V_1 -> V_7 , type ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
if ( V_9 == NULL )
return - V_20 ;
error = F_18 ( V_9 , V_18 , V_4 ) ;
F_15 ( V_9 ) ;
return error ;
}
static struct V_8 * F_19 ( const void * V_3 , T_1 V_4 )
{
const char * V_21 = ( char * ) V_3 + V_4 ;
int V_22 , V_23 ;
struct V_8 * V_9 ;
if ( ! V_3 )
return NULL ;
if ( V_4 < sizeof( V_24 ) )
return F_20 ( - V_25 ) ;
if ( ( ( V_24 * ) V_3 ) -> V_26 !=
F_21 ( V_27 ) )
return F_20 ( - V_25 ) ;
V_3 = ( char * ) V_3 + sizeof( V_24 ) ;
V_23 = F_22 ( V_4 ) ;
if ( V_23 < 0 )
return F_20 ( - V_25 ) ;
if ( V_23 == 0 )
return NULL ;
V_9 = F_23 ( V_23 , V_28 ) ;
if ( ! V_9 )
return F_20 ( - V_29 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
T_2 * V_30 = ( T_2 * ) V_3 ;
if ( ( char * ) V_3 + sizeof( V_31 ) > V_21 )
goto V_32;
V_9 -> V_33 [ V_22 ] . V_34 = F_24 ( V_30 -> V_34 ) ;
V_9 -> V_33 [ V_22 ] . V_35 = F_24 ( V_30 -> V_35 ) ;
switch ( V_9 -> V_33 [ V_22 ] . V_34 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_3 = ( char * ) V_3 +
sizeof( V_31 ) ;
V_9 -> V_33 [ V_22 ] . V_40 = V_41 ;
break;
case V_42 :
case V_43 :
V_3 = ( char * ) V_3 + sizeof( T_2 ) ;
if ( ( char * ) V_3 > V_21 )
goto V_32;
V_9 -> V_33 [ V_22 ] . V_40 = F_25 ( V_30 -> V_40 ) ;
break;
default:
goto V_32;
}
}
if ( V_3 != V_21 )
goto V_32;
return V_9 ;
V_32:
F_15 ( V_9 ) ;
return F_20 ( - V_25 ) ;
}
static void * F_26 ( const struct V_8 * V_9 , T_1 * V_4 )
{
V_24 * V_44 ;
char * V_45 ;
int V_22 ;
* V_4 = F_27 ( V_9 -> V_46 ) ;
V_44 = F_28 ( sizeof( V_24 ) +
V_9 -> V_46 *
sizeof( T_2 ) ,
V_28 ) ;
if ( ! V_44 )
return F_20 ( - V_29 ) ;
V_44 -> V_26 = F_21 ( V_27 ) ;
V_45 = ( char * ) V_44 + sizeof( V_24 ) ;
for ( V_22 = 0 ; V_22 < V_9 -> V_46 ; V_22 ++ ) {
T_2 * V_30 = ( T_2 * ) V_45 ;
V_30 -> V_34 = F_29 ( V_9 -> V_33 [ V_22 ] . V_34 ) ;
V_30 -> V_35 = F_29 ( V_9 -> V_33 [ V_22 ] . V_35 ) ;
switch ( V_9 -> V_33 [ V_22 ] . V_34 ) {
case V_42 :
case V_43 :
V_30 -> V_40 = F_21 ( V_9 -> V_33 [ V_22 ] . V_40 ) ;
V_45 += sizeof( T_2 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_45 += sizeof( V_31 ) ;
break;
default:
goto V_32;
}
}
return ( char * ) V_44 ;
V_32:
F_30 ( V_44 ) ;
return F_20 ( - V_25 ) ;
}
struct V_8 * F_17 ( struct V_6 * V_6 , int type )
{
char * V_2 , * V_3 ;
struct V_8 * V_9 ;
int V_4 ;
int V_47 ;
V_9 = F_31 ( V_6 , type ) ;
if ( V_9 != V_48 )
return V_9 ;
switch ( type ) {
case V_49 :
V_2 = V_50 ;
break;
case V_51 :
V_2 = V_52 ;
break;
default:
F_32 () ;
}
V_4 = F_33 ( V_6 , V_2 , NULL , 0 ) ;
if ( V_4 < 0 ) {
if ( V_4 == - V_20 || V_4 == - V_53 ) {
F_34 ( V_6 , type , NULL ) ;
return NULL ;
}
return F_20 ( V_4 ) ;
}
V_3 = F_28 ( V_4 , V_28 ) ;
if ( ! V_3 )
return F_20 ( - V_29 ) ;
V_47 = F_33 ( V_6 , V_2 , V_3 , V_4 ) ;
if ( V_47 == - V_20 || V_47 == - V_53 ) {
V_9 = NULL ;
} else if ( V_47 < 0 ) {
V_9 = F_20 ( V_47 ) ;
} else {
V_9 = F_19 ( V_3 , V_47 ) ;
}
if ( ! F_5 ( V_9 ) )
F_34 ( V_6 , type , V_9 ) ;
F_30 ( V_3 ) ;
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
if ( F_35 ( V_6 -> V_54 ) )
return - V_15 ;
switch ( type ) {
case V_49 :
V_2 = V_50 ;
if ( V_9 ) {
error = F_36 ( V_9 , & V_6 -> V_54 ) ;
if ( error < 0 )
return error ;
else {
if ( error == 0 )
V_9 = NULL ;
}
}
break;
case V_51 :
V_2 = V_52 ;
if ( ! F_37 ( V_6 -> V_54 ) )
return V_9 ? - V_55 : 0 ;
break;
default:
return - V_25 ;
}
if ( V_9 ) {
V_3 = F_26 ( V_9 , & V_4 ) ;
if ( F_5 ( V_3 ) )
return ( int ) F_6 ( V_3 ) ;
}
error = F_38 ( V_12 , V_6 , V_2 , V_3 , V_4 , 0 ) ;
if ( error == - V_20 ) {
error = 0 ;
if ( type == V_49 ) {
V_6 -> V_56 = V_57 ;
F_39 ( V_6 ) ;
}
}
F_30 ( V_3 ) ;
if ( ! error )
F_34 ( V_6 , type , V_9 ) ;
return error ;
}
int
F_40 ( struct V_11 * V_12 ,
struct V_6 * V_58 , struct V_1 * V_1 ,
struct V_6 * V_6 )
{
struct V_8 * V_9 ;
int V_59 = 0 ;
if ( F_35 ( V_6 -> V_54 ) )
return 0 ;
if ( F_41 ( V_58 ) == V_60 )
goto V_61;
if ( F_42 ( V_58 ) ) {
V_6 -> V_62 |= V_63 ;
goto V_61;
}
V_9 = F_17 ( V_58 , V_51 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
if ( V_9 ) {
if ( F_37 ( V_6 -> V_54 ) ) {
V_59 = F_12 ( V_12 , V_6 , V_51 ,
V_9 ) ;
if ( V_59 )
goto V_64;
}
V_59 = F_43 ( & V_9 , V_28 , & V_6 -> V_54 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 > 0 )
V_59 = F_12 ( V_12 , V_6 , V_49 , V_9 ) ;
V_64:
F_15 ( V_9 ) ;
} else {
V_61:
V_6 -> V_54 &= ~ F_44 () ;
}
return V_59 ;
}
int F_45 ( struct V_6 * V_6 )
{
struct V_8 * V_9 ;
int V_65 = 0 ;
if ( F_42 ( V_6 ) )
return 0 ;
V_9 = F_17 ( V_6 , V_51 ) ;
if ( V_9 && ! F_5 ( V_9 ) ) {
int V_4 = F_27 ( V_9 -> V_46 ) ;
V_65 = F_8 ( V_6 ) ;
V_65 += F_46 ( V_6 -> V_14 ) ;
F_47 ( V_6 ) -> V_62 |= V_66 ;
V_65 += F_9 ( V_6 , V_4 ) * 4 ;
F_15 ( V_9 ) ;
}
return V_65 ;
}
int F_48 ( struct V_6 * V_6 )
{
struct V_11 V_12 ;
struct V_8 * V_9 ;
T_1 V_4 ;
int V_67 ;
int error ;
if ( F_35 ( V_6 -> V_54 ) )
return - V_15 ;
if ( F_41 ( V_6 ) == V_60 ||
! F_2 ( V_6 -> V_14 ) ) {
return 0 ;
}
F_14 ( V_6 -> V_14 ) ;
V_9 = F_17 ( V_6 , V_49 ) ;
F_10 ( V_6 -> V_14 ) ;
if ( ! V_9 )
return 0 ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
error = F_49 ( & V_9 , V_28 , V_6 -> V_54 ) ;
if ( error )
return error ;
V_4 = F_9 ( V_6 , F_27 ( V_9 -> V_46 ) ) ;
V_67 = F_50 ( V_6 -> V_14 ) ;
error = F_11 ( & V_12 , V_6 -> V_14 , V_4 * 2 ) ;
if ( ! error ) {
int V_10 ;
error = F_12 ( & V_12 , V_6 , V_49 , V_9 ) ;
V_10 = F_13 ( & V_12 , V_6 -> V_14 , V_4 * 2 ) ;
if ( V_10 )
error = V_10 ;
}
F_51 ( V_6 -> V_14 , V_67 ) ;
F_15 ( V_9 ) ;
return error ;
}
static T_1 F_52 ( struct V_1 * V_1 , char * V_68 ,
T_1 V_69 , const char * V_2 ,
T_1 V_70 , int type )
{
const T_1 V_4 = sizeof( V_50 ) ;
if ( ! F_2 ( V_1 -> V_19 ) )
return 0 ;
if ( V_68 && V_4 <= V_69 )
memcpy ( V_68 , V_50 , V_4 ) ;
return V_4 ;
}
static T_1 F_53 ( struct V_1 * V_1 , char * V_68 ,
T_1 V_69 , const char * V_2 ,
T_1 V_70 , int type )
{
const T_1 V_4 = sizeof( V_52 ) ;
if ( ! F_2 ( V_1 -> V_19 ) )
return 0 ;
if ( V_68 && V_4 <= V_69 )
memcpy ( V_68 , V_52 , V_4 ) ;
return V_4 ;
}
