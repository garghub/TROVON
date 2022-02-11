int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int type )
{
int error , V_4 ;
struct V_5 V_6 ;
T_1 V_7 ;
int V_8 = V_3 ? F_2 ( V_3 -> V_9 ) : 0 ;
V_7 = F_3 ( V_1 ) +
F_4 ( V_1 , V_8 ) * 2 ;
F_5 ( V_1 -> V_10 ) ;
error = F_6 ( & V_6 , V_1 -> V_10 , V_7 ) ;
F_7 ( V_1 -> V_10 ) ;
if ( error == 0 ) {
error = F_8 ( & V_6 , V_1 , type , V_3 ) ;
F_5 ( V_1 -> V_10 ) ;
V_4 = F_9 ( & V_6 ) ;
F_7 ( V_1 -> V_10 ) ;
if ( V_4 )
error = V_4 ;
}
return error ;
}
static struct V_2 * F_10 ( const void * V_11 , T_1 V_8 )
{
const char * V_12 = ( char * ) V_11 + V_8 ;
int V_13 , V_14 ;
struct V_2 * V_3 ;
if ( ! V_11 )
return NULL ;
if ( V_8 < sizeof( V_15 ) )
return F_11 ( - V_16 ) ;
if ( ( ( V_15 * ) V_11 ) -> V_17 !=
F_12 ( V_18 ) )
return F_11 ( - V_16 ) ;
V_11 = ( char * ) V_11 + sizeof( V_15 ) ;
V_14 = F_13 ( V_8 ) ;
if ( V_14 < 0 )
return F_11 ( - V_16 ) ;
if ( V_14 == 0 )
return NULL ;
V_3 = F_14 ( V_14 , V_19 ) ;
if ( ! V_3 )
return F_11 ( - V_20 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
T_2 * V_21 = ( T_2 * ) V_11 ;
if ( ( char * ) V_11 + sizeof( V_22 ) > V_12 )
goto V_23;
V_3 -> V_24 [ V_13 ] . V_25 = F_15 ( V_21 -> V_25 ) ;
V_3 -> V_24 [ V_13 ] . V_26 = F_15 ( V_21 -> V_26 ) ;
switch ( V_3 -> V_24 [ V_13 ] . V_25 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_11 = ( char * ) V_11 +
sizeof( V_22 ) ;
break;
case V_31 :
V_11 = ( char * ) V_11 + sizeof( T_2 ) ;
if ( ( char * ) V_11 > V_12 )
goto V_23;
V_3 -> V_24 [ V_13 ] . V_32 =
F_16 ( & V_33 ,
F_17 ( V_21 -> V_34 ) ) ;
break;
case V_35 :
V_11 = ( char * ) V_11 + sizeof( T_2 ) ;
if ( ( char * ) V_11 > V_12 )
goto V_23;
V_3 -> V_24 [ V_13 ] . V_36 =
F_18 ( & V_33 ,
F_17 ( V_21 -> V_34 ) ) ;
break;
default:
goto V_23;
}
}
if ( V_11 != V_12 )
goto V_23;
return V_3 ;
V_23:
F_19 ( V_3 ) ;
return F_11 ( - V_16 ) ;
}
static void * F_20 ( const struct V_2 * V_3 , T_1 * V_8 )
{
V_15 * V_37 ;
char * V_38 ;
int V_13 ;
* V_8 = F_21 ( V_3 -> V_9 ) ;
V_37 = F_22 ( sizeof( V_15 ) +
V_3 -> V_9 *
sizeof( T_2 ) ,
V_19 ) ;
if ( ! V_37 )
return F_11 ( - V_20 ) ;
V_37 -> V_17 = F_12 ( V_18 ) ;
V_38 = ( char * ) V_37 + sizeof( V_15 ) ;
for ( V_13 = 0 ; V_13 < V_3 -> V_9 ; V_13 ++ ) {
const struct V_39 * V_40 = & V_3 -> V_24 [ V_13 ] ;
T_2 * V_21 = ( T_2 * ) V_38 ;
V_21 -> V_25 = F_23 ( V_3 -> V_24 [ V_13 ] . V_25 ) ;
V_21 -> V_26 = F_23 ( V_3 -> V_24 [ V_13 ] . V_26 ) ;
switch ( V_3 -> V_24 [ V_13 ] . V_25 ) {
case V_31 :
V_21 -> V_34 = F_12 (
F_24 ( & V_33 , V_40 -> V_32 ) ) ;
V_38 += sizeof( T_2 ) ;
break;
case V_35 :
V_21 -> V_34 = F_12 (
F_25 ( & V_33 , V_40 -> V_36 ) ) ;
V_38 += sizeof( T_2 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_38 += sizeof( V_22 ) ;
break;
default:
goto V_23;
}
}
return ( char * ) V_37 ;
V_23:
F_26 ( V_37 ) ;
return F_11 ( - V_16 ) ;
}
struct V_2 * F_27 ( struct V_1 * V_1 , int type )
{
char * V_41 , * V_11 ;
struct V_2 * V_3 ;
int V_8 ;
int V_42 ;
switch ( type ) {
case V_43 :
V_41 = V_44 ;
break;
case V_45 :
V_41 = V_46 ;
break;
default:
F_28 () ;
}
V_8 = F_29 ( V_1 , V_41 , NULL , 0 ) ;
if ( V_8 < 0 ) {
if ( V_8 == - V_47 || V_8 == - V_48 )
return NULL ;
return F_11 ( V_8 ) ;
}
V_11 = F_22 ( V_8 , V_19 ) ;
if ( ! V_11 )
return F_11 ( - V_20 ) ;
V_42 = F_29 ( V_1 , V_41 , V_11 , V_8 ) ;
if ( V_42 == - V_47 || V_42 == - V_48 ) {
V_3 = NULL ;
} else if ( V_42 < 0 ) {
V_3 = F_11 ( V_42 ) ;
} else {
V_3 = F_10 ( V_11 , V_42 ) ;
}
F_26 ( V_11 ) ;
return V_3 ;
}
static int
F_8 ( struct V_5 * V_6 , struct V_1 * V_1 ,
int type , struct V_2 * V_3 )
{
char * V_41 ;
void * V_11 = NULL ;
T_1 V_8 = 0 ;
int error ;
switch ( type ) {
case V_43 :
V_41 = V_44 ;
if ( V_3 ) {
error = F_30 ( V_1 , & V_1 -> V_49 , & V_3 ) ;
if ( error )
return error ;
}
break;
case V_45 :
V_41 = V_46 ;
if ( ! F_31 ( V_1 -> V_49 ) )
return V_3 ? - V_50 : 0 ;
break;
default:
return - V_16 ;
}
if ( V_3 ) {
V_11 = F_20 ( V_3 , & V_8 ) ;
if ( F_32 ( V_11 ) )
return ( int ) F_33 ( V_11 ) ;
}
error = F_34 ( V_6 , V_1 , V_41 , V_11 , V_8 , 0 ) ;
if ( error == - V_47 ) {
error = 0 ;
if ( type == V_43 ) {
V_1 -> V_51 = F_35 ( V_1 ) ;
F_36 ( V_1 ) ;
}
}
F_26 ( V_11 ) ;
if ( ! error )
F_37 ( V_1 , type , V_3 ) ;
return error ;
}
int
F_38 ( struct V_5 * V_6 ,
struct V_1 * V_52 , struct V_53 * V_53 ,
struct V_1 * V_1 )
{
struct V_2 * V_54 , * V_3 ;
int V_55 = 0 ;
if ( F_39 ( V_1 -> V_49 ) )
return 0 ;
if ( F_40 ( V_52 ) == V_56 )
goto V_57;
if ( F_41 ( V_52 ) ) {
V_1 -> V_58 |= V_59 ;
goto V_57;
}
V_55 = F_42 ( V_52 , & V_1 -> V_49 , & V_54 , & V_3 ) ;
if ( V_55 )
return V_55 ;
if ( V_54 ) {
V_55 = F_8 ( V_6 , V_1 , V_45 ,
V_54 ) ;
F_19 ( V_54 ) ;
}
if ( V_3 ) {
if ( ! V_55 )
V_55 = F_8 ( V_6 , V_1 , V_43 ,
V_3 ) ;
F_19 ( V_3 ) ;
}
return V_55 ;
V_57:
V_1 -> V_49 &= ~ F_43 () ;
return V_55 ;
}
int F_44 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
int V_60 = 0 ;
if ( F_41 ( V_1 ) )
return 0 ;
V_3 = F_45 ( V_1 , V_45 ) ;
if ( V_3 && ! F_32 ( V_3 ) ) {
int V_8 = F_21 ( V_3 -> V_9 ) ;
V_60 = F_3 ( V_1 ) ;
V_60 += F_46 ( V_1 -> V_10 ) ;
F_47 ( V_1 ) -> V_58 |= V_61 ;
V_60 += F_4 ( V_1 , V_8 ) * 4 ;
F_19 ( V_3 ) ;
}
return V_60 ;
}
int F_48 ( struct V_1 * V_1 )
{
if ( F_41 ( V_1 ) )
return 0 ;
if ( F_40 ( V_1 ) == V_56 ||
! F_49 ( V_1 -> V_10 ) )
return 0 ;
return F_50 ( V_1 , V_1 -> V_49 ) ;
}
