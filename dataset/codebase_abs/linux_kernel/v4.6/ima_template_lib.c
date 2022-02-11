static bool F_1 ( T_1 V_1 )
{
if ( V_1 == V_2 || V_1 == V_3 )
return true ;
return false ;
}
static int F_2 ( const void * V_4 , const T_2 V_5 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
T_1 * V_10 , * V_11 ;
T_2 V_12 = V_5 ;
if ( V_7 == V_13 )
V_12 = V_5 + 1 ;
V_10 = F_3 ( V_12 , V_14 ) ;
if ( ! V_10 )
return - V_15 ;
memcpy ( V_10 , V_4 , V_5 ) ;
if ( V_7 == V_13 ) {
for ( V_11 = V_10 ; V_11 - V_10 < V_5 ; V_11 ++ )
if ( * V_11 == ' ' )
* V_11 = '_' ;
}
V_9 -> V_4 = V_10 ;
V_9 -> V_16 = V_12 ;
return 0 ;
}
static void F_4 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
T_1 * V_11 = V_9 -> V_4 ;
T_2 V_12 = V_9 -> V_16 ;
switch ( V_7 ) {
case V_21 :
V_11 = F_5 ( V_9 -> V_4 , V_12 , ':' ) ;
if ( V_11 != V_9 -> V_4 )
F_6 ( V_18 , L_1 , V_9 -> V_4 ) ;
V_11 += 2 ;
V_12 -= V_11 - V_9 -> V_4 ;
case V_22 :
case V_23 :
if ( ! V_12 )
break;
F_7 ( V_18 , V_11 , V_12 ) ;
break;
case V_13 :
F_6 ( V_18 , L_1 , V_11 ) ;
break;
default:
break;
}
}
static void F_8 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
T_2 V_16 = ( V_20 == V_24 ) ?
strlen ( V_9 -> V_4 ) : V_9 -> V_16 ;
if ( V_20 != V_25 )
F_9 ( V_18 , & V_16 , sizeof( V_16 ) ) ;
if ( ! V_16 )
return;
F_9 ( V_18 , V_9 -> V_4 , V_16 ) ;
}
static void F_10 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
switch ( V_20 ) {
case V_26 :
F_4 ( V_18 , V_20 , V_7 , V_9 ) ;
break;
case V_27 :
case V_25 :
case V_24 :
F_8 ( V_18 , V_20 , V_7 , V_9 ) ;
break;
default:
break;
}
}
void F_11 ( struct V_17 * V_18 , enum V_19 V_20 ,
struct V_8 * V_9 )
{
F_10 ( V_18 , V_20 , V_22 , V_9 ) ;
}
void F_12 ( struct V_17 * V_18 , enum V_19 V_20 ,
struct V_8 * V_9 )
{
F_10 ( V_18 , V_20 , V_21 ,
V_9 ) ;
}
void F_13 ( struct V_17 * V_18 , enum V_19 V_20 ,
struct V_8 * V_9 )
{
F_10 ( V_18 , V_20 , V_13 , V_9 ) ;
}
void F_14 ( struct V_17 * V_18 , enum V_19 V_20 ,
struct V_8 * V_9 )
{
F_10 ( V_18 , V_20 , V_23 , V_9 ) ;
}
static int F_15 ( T_1 * V_28 , T_2 V_29 , T_1 V_30 ,
struct V_8 * V_9 )
{
T_1 V_31 [ V_32 + 2 + V_33 ] = { 0 } ;
enum V_6 V_34 = V_22 ;
T_2 V_35 = 0 ;
if ( V_30 < V_36 ) {
V_34 = V_21 ;
V_35 += snprintf ( V_31 , V_32 + 1 , L_1 ,
V_37 [ V_30 ] ) ;
V_31 [ V_35 ] = ':' ;
V_35 += 2 ;
}
if ( V_28 )
memcpy ( V_31 + V_35 , V_28 , V_29 ) ;
else
V_35 += V_38 ;
return F_2 ( V_31 , V_35 + V_29 ,
V_34 , V_9 ) ;
}
int F_16 ( struct V_39 * V_40 ,
struct V_8 * V_9 )
{
struct {
struct V_41 V_42 ;
char V_28 [ V_33 ] ;
} V_43 ;
T_1 * V_44 = NULL ;
T_2 V_45 = 0 ;
struct V_46 * V_46 ;
int V_47 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
if ( V_40 -> V_48 )
goto V_49;
if ( F_1 ( V_40 -> V_50 -> V_51 -> V_1 ) ) {
V_44 = V_40 -> V_50 -> V_51 -> V_28 ;
V_45 = V_40 -> V_50 -> V_51 -> V_52 ;
goto V_49;
}
if ( ! V_40 -> V_53 )
return - V_54 ;
V_46 = F_17 ( V_40 -> V_53 ) ;
V_43 . V_42 . V_1 = F_1 ( V_55 ) ?
V_55 : V_2 ;
V_47 = F_18 ( V_40 -> V_53 , & V_43 . V_42 ) ;
if ( V_47 ) {
F_19 ( V_56 , V_46 ,
V_40 -> V_57 , L_2 ,
L_3 , V_47 , 0 ) ;
return V_47 ;
}
V_44 = V_43 . V_42 . V_28 ;
V_45 = V_43 . V_42 . V_52 ;
V_49:
return F_15 ( V_44 , V_45 ,
V_36 , V_9 ) ;
}
int F_20 ( struct V_39 * V_40 ,
struct V_8 * V_9 )
{
T_1 * V_44 = NULL , V_30 = V_2 ;
T_2 V_45 = 0 ;
if ( V_40 -> V_48 )
goto V_49;
V_44 = V_40 -> V_50 -> V_51 -> V_28 ;
V_45 = V_40 -> V_50 -> V_51 -> V_52 ;
V_30 = V_40 -> V_50 -> V_51 -> V_1 ;
V_49:
return F_15 ( V_44 , V_45 ,
V_30 , V_9 ) ;
}
static int F_21 ( struct V_39 * V_40 ,
struct V_8 * V_9 ,
bool V_58 )
{
const char * V_59 = NULL ;
T_2 V_60 = 0 ;
F_22 ( V_40 -> V_57 == NULL && V_40 -> V_53 == NULL ) ;
if ( V_40 -> V_57 ) {
V_59 = V_40 -> V_57 ;
V_60 = strlen ( V_40 -> V_57 ) ;
if ( ! V_58 || V_60 <= V_61 )
goto V_49;
}
if ( V_40 -> V_53 ) {
V_59 = V_40 -> V_53 -> V_62 . V_63 -> V_64 . V_65 ;
V_60 = strlen ( V_59 ) ;
} else
V_60 = V_61 ;
V_49:
return F_2 ( V_59 , V_60 ,
V_13 , V_9 ) ;
}
int F_23 ( struct V_39 * V_40 ,
struct V_8 * V_9 )
{
return F_21 ( V_40 , V_9 , true ) ;
}
int F_24 ( struct V_39 * V_40 ,
struct V_8 * V_9 )
{
return F_21 ( V_40 , V_9 , false ) ;
}
int F_25 ( struct V_39 * V_40 ,
struct V_8 * V_9 )
{
enum V_6 V_34 = V_23 ;
struct V_66 * V_67 = V_40 -> V_67 ;
int V_68 = V_40 -> V_68 ;
int V_69 = 0 ;
if ( ( ! V_67 ) || ( V_67 -> type != V_70 ) )
goto V_49;
V_69 = F_2 ( V_67 , V_68 , V_34 ,
V_9 ) ;
V_49:
return V_69 ;
}
