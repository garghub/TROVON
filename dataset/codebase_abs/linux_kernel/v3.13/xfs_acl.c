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
struct V_1 * V_7 ;
struct V_2 * V_2 ;
unsigned char * V_38 ;
int error ;
int V_39 ;
V_7 = F_16 ( V_35 , type ) ;
if ( V_7 != V_40 )
return V_7 ;
F_17 ( V_37 ) ;
switch ( type ) {
case V_41 :
V_38 = V_42 ;
break;
case V_43 :
V_38 = V_44 ;
break;
default:
F_18 () ;
}
V_39 = F_19 ( V_37 -> V_45 ) ;
V_2 = F_20 ( V_39 , V_46 ) ;
if ( ! V_2 )
return F_3 ( - V_15 ) ;
error = - F_21 ( V_37 , V_38 , ( unsigned char * ) V_2 ,
& V_39 , V_47 ) ;
if ( error ) {
if ( error == - V_48 ) {
V_7 = NULL ;
goto V_49;
}
goto V_50;
}
V_7 = F_1 ( V_2 , F_22 ( V_37 -> V_45 ) ) ;
if ( F_23 ( V_7 ) )
goto V_50;
V_49:
F_24 ( V_35 , type , V_7 ) ;
V_50:
F_25 ( V_2 ) ;
return V_7 ;
}
STATIC int
F_26 ( struct V_35 * V_35 , int type , struct V_1 * V_7 )
{
struct V_36 * V_37 = F_15 ( V_35 ) ;
unsigned char * V_38 ;
int error ;
if ( F_27 ( V_35 -> V_51 ) )
return - V_52 ;
switch ( type ) {
case V_41 :
V_38 = V_42 ;
break;
case V_43 :
if ( ! F_28 ( V_35 -> V_51 ) )
return V_7 ? - V_53 : 0 ;
V_38 = V_44 ;
break;
default:
return - V_32 ;
}
if ( V_7 ) {
struct V_2 * V_2 ;
int V_39 = F_19 ( V_37 -> V_45 ) ;
V_2 = F_20 ( V_39 , V_46 ) ;
if ( ! V_2 )
return - V_15 ;
F_9 ( V_2 , V_7 ) ;
V_39 -= sizeof( struct V_8 ) *
( F_22 ( V_37 -> V_45 ) - V_7 -> V_33 ) ;
error = - F_29 ( V_37 , V_38 , ( unsigned char * ) V_2 ,
V_39 , V_47 ) ;
F_25 ( V_2 ) ;
} else {
error = - F_30 ( V_37 , V_38 , V_47 ) ;
if ( error == - V_48 )
error = 0 ;
}
if ( ! error )
F_24 ( V_35 , type , V_7 ) ;
return error ;
}
static int
F_31 ( struct V_35 * V_35 , T_1 V_54 )
{
int error = 0 ;
if ( V_54 != V_35 -> V_51 ) {
struct V_55 V_55 ;
V_55 . V_56 = V_57 | V_58 ;
V_55 . V_59 = V_54 ;
V_55 . V_60 = F_32 ( V_35 -> V_61 ) ;
error = - F_33 ( F_15 ( V_35 ) , & V_55 , V_62 ) ;
}
return error ;
}
static int
F_34 ( struct V_35 * V_35 , unsigned char * V_63 )
{
int V_39 = F_19 ( F_35 ( V_35 -> V_61 ) ) ;
return ( F_21 ( F_15 ( V_35 ) , V_63 , NULL , & V_39 ,
V_47 | V_64 ) == 0 ) ;
}
int
F_36 ( struct V_35 * V_35 )
{
return F_34 ( V_35 , V_42 ) ;
}
int
F_37 ( struct V_35 * V_35 )
{
if ( ! F_28 ( V_35 -> V_51 ) )
return 0 ;
return F_34 ( V_35 , V_44 ) ;
}
int
F_38 ( struct V_35 * V_35 , struct V_1 * V_7 )
{
T_1 V_54 = V_35 -> V_51 ;
int error = 0 , V_65 = 0 ;
if ( F_28 ( V_35 -> V_51 ) ) {
error = F_26 ( V_35 , V_43 , V_7 ) ;
if ( error )
goto V_50;
}
error = F_39 ( & V_7 , V_14 , & V_54 ) ;
if ( error < 0 )
return error ;
if ( error > 0 )
V_65 = 1 ;
error = F_31 ( V_35 , V_54 ) ;
if ( error )
goto V_50;
if ( V_65 )
error = F_26 ( V_35 , V_41 , V_7 ) ;
V_50:
F_8 ( V_7 ) ;
return error ;
}
int
F_40 ( struct V_35 * V_35 )
{
struct V_1 * V_7 ;
int error ;
if ( F_27 ( V_35 -> V_51 ) )
return - V_52 ;
V_7 = F_14 ( V_35 , V_41 ) ;
if ( F_23 ( V_7 ) || ! V_7 )
return F_41 ( V_7 ) ;
error = F_42 ( & V_7 , V_14 , V_35 -> V_51 ) ;
if ( error )
return error ;
error = F_26 ( V_35 , V_41 , V_7 ) ;
F_8 ( V_7 ) ;
return error ;
}
static int
F_43 ( struct V_66 * V_66 , const char * V_63 ,
void * V_67 , T_2 V_68 , int type )
{
struct V_1 * V_7 ;
int error ;
V_7 = F_14 ( V_66 -> V_69 , type ) ;
if ( F_23 ( V_7 ) )
return F_41 ( V_7 ) ;
if ( V_7 == NULL )
return - V_70 ;
error = F_44 ( & V_71 , V_7 , V_67 , V_68 ) ;
F_8 ( V_7 ) ;
return error ;
}
static int
F_45 ( struct V_66 * V_66 , const char * V_63 ,
const void * V_67 , T_2 V_68 , int V_72 , int type )
{
struct V_35 * V_35 = V_66 -> V_69 ;
struct V_1 * V_7 = NULL ;
int error = 0 ;
if ( V_72 & V_73 )
return - V_32 ;
if ( type == V_43 && ! F_28 ( V_35 -> V_51 ) )
return V_67 ? - V_53 : 0 ;
if ( ! F_46 ( V_35 ) )
return - V_74 ;
if ( ! V_67 )
goto V_75;
V_7 = F_47 ( & V_71 , V_67 , V_68 ) ;
if ( ! V_7 ) {
goto V_50;
}
if ( F_23 ( V_7 ) ) {
error = F_41 ( V_7 ) ;
goto V_50;
}
error = F_48 ( V_7 ) ;
if ( error )
goto V_76;
error = - V_32 ;
if ( V_7 -> V_33 > F_22 ( F_35 ( V_35 -> V_61 ) ) )
goto V_76;
if ( type == V_41 ) {
T_1 V_54 = V_35 -> V_51 ;
error = F_49 ( V_7 , & V_54 ) ;
if ( error <= 0 ) {
F_8 ( V_7 ) ;
V_7 = NULL ;
if ( error < 0 )
return error ;
}
error = F_31 ( V_35 , V_54 ) ;
if ( error )
goto V_76;
}
V_75:
error = F_26 ( V_35 , type , V_7 ) ;
V_76:
F_8 ( V_7 ) ;
V_50:
return error ;
}
