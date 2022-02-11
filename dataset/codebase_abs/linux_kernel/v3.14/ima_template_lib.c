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
T_2 V_12 ;
switch ( V_7 ) {
case V_13 :
V_12 = V_14 + 1 ;
break;
case V_15 :
V_12 = V_5 + 1 ;
break;
default:
V_12 = V_5 ;
}
V_10 = F_3 ( V_12 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
memcpy ( V_10 , V_4 , V_5 ) ;
if ( V_7 == V_13 || V_7 == V_15 ) {
for ( V_11 = V_10 ; V_11 - V_10 < V_5 ; V_11 ++ )
if ( * V_11 == ' ' )
* V_11 = '_' ;
}
V_9 -> V_4 = V_10 ;
V_9 -> V_18 = V_12 ;
return 0 ;
}
static void F_4 ( struct V_19 * V_20 ,
enum V_21 V_22 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
T_1 * V_11 = V_9 -> V_4 , V_12 = V_9 -> V_18 ;
switch ( V_7 ) {
case V_23 :
V_11 = F_5 ( V_9 -> V_4 , V_12 , ':' ) ;
if ( V_11 != V_9 -> V_4 )
F_6 ( V_20 , L_1 , V_9 -> V_4 ) ;
V_11 += 2 ;
V_12 -= V_11 - V_9 -> V_4 ;
case V_24 :
case V_25 :
if ( ! V_12 )
break;
F_7 ( V_20 , V_11 , V_12 ) ;
break;
case V_15 :
F_6 ( V_20 , L_1 , V_11 ) ;
break;
default:
break;
}
}
static void F_8 ( struct V_19 * V_20 ,
enum V_21 V_22 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
if ( V_22 != V_26 )
F_9 ( V_20 , & V_9 -> V_18 , sizeof( T_2 ) ) ;
if ( ! V_9 -> V_18 )
return;
F_9 ( V_20 , V_9 -> V_4 , V_9 -> V_18 ) ;
}
static void F_10 ( struct V_19 * V_20 ,
enum V_21 V_22 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
switch ( V_22 ) {
case V_27 :
F_4 ( V_20 , V_22 , V_7 , V_9 ) ;
break;
case V_28 :
case V_26 :
F_8 ( V_20 , V_22 , V_7 , V_9 ) ;
break;
default:
break;
}
}
void F_11 ( struct V_19 * V_20 , enum V_21 V_22 ,
struct V_8 * V_9 )
{
F_10 ( V_20 , V_22 , V_24 , V_9 ) ;
}
void F_12 ( struct V_19 * V_20 , enum V_21 V_22 ,
struct V_8 * V_9 )
{
F_10 ( V_20 , V_22 , V_23 ,
V_9 ) ;
}
void F_13 ( struct V_19 * V_20 , enum V_21 V_22 ,
struct V_8 * V_9 )
{
F_10 ( V_20 , V_22 , V_15 , V_9 ) ;
}
void F_14 ( struct V_19 * V_20 , enum V_21 V_22 ,
struct V_8 * V_9 )
{
F_10 ( V_20 , V_22 , V_25 , V_9 ) ;
}
static int F_15 ( T_1 * V_29 , T_2 V_30 , T_1 V_31 ,
struct V_8 * V_9 )
{
T_1 V_32 [ V_33 + 2 + V_34 ] = { 0 } ;
enum V_6 V_35 = V_24 ;
T_2 V_36 = 0 ;
if ( V_31 < V_37 ) {
V_35 = V_23 ;
V_36 += snprintf ( V_32 , V_33 + 1 , L_1 ,
V_38 [ V_31 ] ) ;
V_32 [ V_36 ] = ':' ;
V_36 += 2 ;
}
if ( V_29 )
memcpy ( V_32 + V_36 , V_29 , V_30 ) ;
else
V_36 += V_39 ;
return F_2 ( V_32 , V_36 + V_30 ,
V_35 , V_9 ) ;
}
int F_16 ( struct V_40 * V_41 , struct V_42 * V_42 ,
const unsigned char * V_43 ,
struct V_44 * V_45 , int V_46 ,
struct V_8 * V_9 )
{
struct {
struct V_47 V_48 ;
char V_29 [ V_34 ] ;
} V_49 ;
T_1 * V_50 = NULL ;
T_2 V_51 = 0 ;
struct V_52 * V_52 ;
int V_53 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
if ( ! V_41 )
goto V_54;
if ( F_1 ( V_41 -> V_55 -> V_1 ) ) {
V_50 = V_41 -> V_55 -> V_29 ;
V_51 = V_41 -> V_55 -> V_56 ;
goto V_54;
}
if ( ! V_42 )
return - V_57 ;
V_52 = F_17 ( V_42 ) ;
V_49 . V_48 . V_1 = F_1 ( V_58 ) ?
V_58 : V_2 ;
V_53 = F_18 ( V_42 , & V_49 . V_48 ) ;
if ( V_53 ) {
F_19 ( V_59 , V_52 ,
V_43 , L_2 ,
L_3 , V_53 , 0 ) ;
return V_53 ;
}
V_50 = V_49 . V_48 . V_29 ;
V_51 = V_49 . V_48 . V_56 ;
V_54:
return F_15 ( V_50 , V_51 ,
V_37 , V_9 ) ;
}
int F_20 ( struct V_40 * V_41 ,
struct V_42 * V_42 , const unsigned char * V_43 ,
struct V_44 * V_45 ,
int V_46 , struct V_8 * V_9 )
{
T_1 * V_50 = NULL , V_31 = V_2 ;
T_2 V_51 = 0 ;
if ( ! V_41 )
goto V_54;
V_50 = V_41 -> V_55 -> V_29 ;
V_51 = V_41 -> V_55 -> V_56 ;
V_31 = V_41 -> V_55 -> V_1 ;
V_54:
return F_15 ( V_50 , V_51 ,
V_31 , V_9 ) ;
}
static int F_21 ( struct V_40 * V_41 ,
struct V_42 * V_42 ,
const unsigned char * V_43 ,
struct V_8 * V_9 ,
bool V_60 )
{
const char * V_61 = NULL ;
T_2 V_62 = 0 ;
enum V_6 V_35 = V_60 ?
V_13 : V_15 ;
F_22 ( V_43 == NULL && V_42 == NULL ) ;
if ( V_43 ) {
V_61 = V_43 ;
V_62 = strlen ( V_43 ) ;
if ( ! V_60 || V_62 <= V_14 )
goto V_54;
}
if ( V_42 ) {
V_61 = V_42 -> V_63 -> V_64 . V_65 ;
V_62 = strlen ( V_61 ) ;
} else
V_62 = V_14 ;
V_54:
return F_2 ( V_61 , V_62 ,
V_35 , V_9 ) ;
}
int F_23 ( struct V_40 * V_41 , struct V_42 * V_42 ,
const unsigned char * V_43 ,
struct V_44 * V_45 , int V_46 ,
struct V_8 * V_9 )
{
return F_21 ( V_41 , V_42 , V_43 ,
V_9 , true ) ;
}
int F_24 ( struct V_40 * V_41 , struct V_42 * V_42 ,
const unsigned char * V_43 ,
struct V_44 * V_45 , int V_46 ,
struct V_8 * V_9 )
{
return F_21 ( V_41 , V_42 , V_43 ,
V_9 , false ) ;
}
int F_25 ( struct V_40 * V_41 , struct V_42 * V_42 ,
const unsigned char * V_43 ,
struct V_44 * V_45 , int V_46 ,
struct V_8 * V_9 )
{
enum V_6 V_35 = V_25 ;
int V_66 = 0 ;
if ( ( ! V_45 ) || ( V_45 -> type != V_67 ) )
goto V_54;
V_66 = F_2 ( V_45 , V_46 , V_35 ,
V_9 ) ;
V_54:
return V_66 ;
}
