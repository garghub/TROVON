int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int type )
{
int error , V_4 ;
struct V_5 V_6 ;
T_1 V_7 ;
int V_8 = V_3 ? F_2 ( V_3 -> V_9 ) : 0 ;
int V_10 = 0 ;
T_2 V_11 = V_1 -> V_12 ;
V_7 = F_3 ( V_1 ) +
F_4 ( V_1 , V_8 ) * 2 ;
F_5 ( V_1 -> V_13 ) ;
error = F_6 ( & V_6 , V_1 -> V_13 , V_7 ) ;
F_7 ( V_1 -> V_13 ) ;
if ( error == 0 ) {
if ( type == V_14 && V_3 ) {
error = F_8 ( V_1 , & V_11 , & V_3 ) ;
if ( error )
goto V_15;
V_10 = 1 ;
}
error = F_9 ( & V_6 , V_1 , type , V_3 ) ;
if ( ! error && V_10 )
V_1 -> V_12 = V_11 ;
V_15:
F_5 ( V_1 -> V_13 ) ;
V_4 = F_10 ( & V_6 ) ;
F_7 ( V_1 -> V_13 ) ;
if ( V_4 )
error = V_4 ;
}
return error ;
}
static struct V_2 * F_11 ( const void * V_16 , T_1 V_8 )
{
const char * V_17 = ( char * ) V_16 + V_8 ;
int V_18 , V_19 ;
struct V_2 * V_3 ;
if ( ! V_16 )
return NULL ;
if ( V_8 < sizeof( V_20 ) )
return F_12 ( - V_21 ) ;
if ( ( ( V_20 * ) V_16 ) -> V_22 !=
F_13 ( V_23 ) )
return F_12 ( - V_21 ) ;
V_16 = ( char * ) V_16 + sizeof( V_20 ) ;
V_19 = F_14 ( V_8 ) ;
if ( V_19 < 0 )
return F_12 ( - V_21 ) ;
if ( V_19 == 0 )
return NULL ;
V_3 = F_15 ( V_19 , V_24 ) ;
if ( ! V_3 )
return F_12 ( - V_25 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
T_3 * V_26 = ( T_3 * ) V_16 ;
if ( ( char * ) V_16 + sizeof( V_27 ) > V_17 )
goto V_28;
V_3 -> V_29 [ V_18 ] . V_30 = F_16 ( V_26 -> V_30 ) ;
V_3 -> V_29 [ V_18 ] . V_31 = F_16 ( V_26 -> V_31 ) ;
switch ( V_3 -> V_29 [ V_18 ] . V_30 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
V_16 = ( char * ) V_16 +
sizeof( V_27 ) ;
break;
case V_36 :
V_16 = ( char * ) V_16 + sizeof( T_3 ) ;
if ( ( char * ) V_16 > V_17 )
goto V_28;
V_3 -> V_29 [ V_18 ] . V_37 =
F_17 ( & V_38 ,
F_18 ( V_26 -> V_39 ) ) ;
break;
case V_40 :
V_16 = ( char * ) V_16 + sizeof( T_3 ) ;
if ( ( char * ) V_16 > V_17 )
goto V_28;
V_3 -> V_29 [ V_18 ] . V_41 =
F_19 ( & V_38 ,
F_18 ( V_26 -> V_39 ) ) ;
break;
default:
goto V_28;
}
}
if ( V_16 != V_17 )
goto V_28;
return V_3 ;
V_28:
F_20 ( V_3 ) ;
return F_12 ( - V_21 ) ;
}
static void * F_21 ( const struct V_2 * V_3 , T_1 * V_8 )
{
V_20 * V_42 ;
char * V_43 ;
int V_18 ;
* V_8 = F_22 ( V_3 -> V_9 ) ;
V_42 = F_23 ( sizeof( V_20 ) +
V_3 -> V_9 *
sizeof( T_3 ) ,
V_24 ) ;
if ( ! V_42 )
return F_12 ( - V_25 ) ;
V_42 -> V_22 = F_13 ( V_23 ) ;
V_43 = ( char * ) V_42 + sizeof( V_20 ) ;
for ( V_18 = 0 ; V_18 < V_3 -> V_9 ; V_18 ++ ) {
const struct V_44 * V_45 = & V_3 -> V_29 [ V_18 ] ;
T_3 * V_26 = ( T_3 * ) V_43 ;
V_26 -> V_30 = F_24 ( V_3 -> V_29 [ V_18 ] . V_30 ) ;
V_26 -> V_31 = F_24 ( V_3 -> V_29 [ V_18 ] . V_31 ) ;
switch ( V_3 -> V_29 [ V_18 ] . V_30 ) {
case V_36 :
V_26 -> V_39 = F_13 (
F_25 ( & V_38 , V_45 -> V_37 ) ) ;
V_43 += sizeof( T_3 ) ;
break;
case V_40 :
V_26 -> V_39 = F_13 (
F_26 ( & V_38 , V_45 -> V_41 ) ) ;
V_43 += sizeof( T_3 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
V_43 += sizeof( V_27 ) ;
break;
default:
goto V_28;
}
}
return ( char * ) V_42 ;
V_28:
F_27 ( V_42 ) ;
return F_12 ( - V_21 ) ;
}
struct V_2 * F_28 ( struct V_1 * V_1 , int type )
{
char * V_46 , * V_16 ;
struct V_2 * V_3 ;
int V_8 ;
int V_47 ;
switch ( type ) {
case V_14 :
V_46 = V_48 ;
break;
case V_49 :
V_46 = V_50 ;
break;
default:
F_29 () ;
}
V_8 = F_30 ( V_1 , V_46 , NULL , 0 ) ;
if ( V_8 < 0 ) {
if ( V_8 == - V_51 || V_8 == - V_52 )
return NULL ;
return F_12 ( V_8 ) ;
}
V_16 = F_23 ( V_8 , V_24 ) ;
if ( ! V_16 )
return F_12 ( - V_25 ) ;
V_47 = F_30 ( V_1 , V_46 , V_16 , V_8 ) ;
if ( V_47 == - V_51 || V_47 == - V_52 ) {
V_3 = NULL ;
} else if ( V_47 < 0 ) {
V_3 = F_12 ( V_47 ) ;
} else {
V_3 = F_11 ( V_16 , V_47 ) ;
}
F_27 ( V_16 ) ;
return V_3 ;
}
static int
F_9 ( struct V_5 * V_6 , struct V_1 * V_1 ,
int type , struct V_2 * V_3 )
{
char * V_46 ;
void * V_16 = NULL ;
T_1 V_8 = 0 ;
int error ;
switch ( type ) {
case V_14 :
V_46 = V_48 ;
break;
case V_49 :
V_46 = V_50 ;
if ( ! F_31 ( V_1 -> V_12 ) )
return V_3 ? - V_53 : 0 ;
break;
default:
return - V_21 ;
}
if ( V_3 ) {
V_16 = F_21 ( V_3 , & V_8 ) ;
if ( F_32 ( V_16 ) )
return ( int ) F_33 ( V_16 ) ;
}
error = F_34 ( V_6 , V_1 , V_46 , V_16 , V_8 , 0 ) ;
if ( error == - V_51 ) {
error = 0 ;
if ( type == V_14 ) {
V_1 -> V_54 = F_35 ( V_1 ) ;
F_36 ( V_1 ) ;
}
}
F_27 ( V_16 ) ;
if ( ! error )
F_37 ( V_1 , type , V_3 ) ;
return error ;
}
int
F_38 ( struct V_5 * V_6 ,
struct V_1 * V_55 , struct V_56 * V_56 ,
struct V_1 * V_1 )
{
struct V_2 * V_57 , * V_3 ;
int V_58 = 0 ;
if ( F_39 ( V_1 -> V_12 ) )
return 0 ;
if ( F_40 ( V_55 ) == V_59 )
goto V_60;
if ( F_41 ( V_55 ) ) {
V_1 -> V_61 |= V_62 ;
goto V_60;
}
V_58 = F_42 ( V_55 , & V_1 -> V_12 , & V_57 , & V_3 ) ;
if ( V_58 )
return V_58 ;
if ( V_57 ) {
V_58 = F_9 ( V_6 , V_1 , V_49 ,
V_57 ) ;
F_20 ( V_57 ) ;
}
if ( V_3 ) {
if ( ! V_58 )
V_58 = F_9 ( V_6 , V_1 , V_14 ,
V_3 ) ;
F_20 ( V_3 ) ;
}
return V_58 ;
V_60:
V_1 -> V_12 &= ~ F_43 () ;
return V_58 ;
}
int F_44 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
int V_63 = 0 ;
if ( F_41 ( V_1 ) )
return 0 ;
V_3 = F_45 ( V_1 , V_49 ) ;
if ( V_3 && ! F_32 ( V_3 ) ) {
int V_8 = F_22 ( V_3 -> V_9 ) ;
V_63 = F_3 ( V_1 ) ;
V_63 += F_46 ( V_1 -> V_13 ) ;
F_47 ( V_1 ) -> V_61 |= V_64 ;
V_63 += F_4 ( V_1 , V_8 ) * 4 ;
F_20 ( V_3 ) ;
}
return V_63 ;
}
int F_48 ( struct V_1 * V_1 )
{
if ( F_41 ( V_1 ) )
return 0 ;
if ( F_40 ( V_1 ) == V_59 ||
! F_49 ( V_1 -> V_13 ) )
return 0 ;
return F_50 ( V_1 , V_1 -> V_12 ) ;
}
