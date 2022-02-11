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
if ( V_20 != V_25 ) {
T_2 V_26 = ! V_27 ? V_16 : F_9 ( V_16 ) ;
F_10 ( V_18 , & V_26 , sizeof( V_26 ) ) ;
}
if ( ! V_16 )
return;
F_10 ( V_18 , V_9 -> V_4 , V_16 ) ;
}
static void F_11 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
switch ( V_20 ) {
case V_28 :
F_4 ( V_18 , V_20 , V_7 , V_9 ) ;
break;
case V_29 :
case V_25 :
case V_24 :
F_8 ( V_18 , V_20 , V_7 , V_9 ) ;
break;
default:
break;
}
}
void F_12 ( struct V_17 * V_18 , enum V_19 V_20 ,
struct V_8 * V_9 )
{
F_11 ( V_18 , V_20 , V_22 , V_9 ) ;
}
void F_13 ( struct V_17 * V_18 , enum V_19 V_20 ,
struct V_8 * V_9 )
{
F_11 ( V_18 , V_20 , V_21 ,
V_9 ) ;
}
void F_14 ( struct V_17 * V_18 , enum V_19 V_20 ,
struct V_8 * V_9 )
{
F_11 ( V_18 , V_20 , V_13 , V_9 ) ;
}
void F_15 ( struct V_17 * V_18 , enum V_19 V_20 ,
struct V_8 * V_9 )
{
F_11 ( V_18 , V_20 , V_23 , V_9 ) ;
}
static int F_16 ( T_1 * V_30 , T_2 V_31 , T_1 V_32 ,
struct V_8 * V_9 )
{
T_1 V_33 [ V_34 + 2 + V_35 ] = { 0 } ;
enum V_6 V_36 = V_22 ;
T_2 V_37 = 0 ;
if ( V_32 < V_38 ) {
V_36 = V_21 ;
V_37 += snprintf ( V_33 , V_34 + 1 , L_1 ,
V_39 [ V_32 ] ) ;
V_33 [ V_37 ] = ':' ;
V_37 += 2 ;
}
if ( V_30 )
memcpy ( V_33 + V_37 , V_30 , V_31 ) ;
else
V_37 += V_40 ;
return F_2 ( V_33 , V_37 + V_31 ,
V_36 , V_9 ) ;
}
int F_17 ( struct V_41 * V_42 ,
struct V_8 * V_9 )
{
struct {
struct V_43 V_44 ;
char V_30 [ V_35 ] ;
} V_45 ;
T_1 * V_46 = NULL ;
T_2 V_47 = 0 ;
struct V_48 * V_48 ;
int V_49 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
if ( V_42 -> V_50 )
goto V_51;
if ( F_1 ( V_42 -> V_52 -> V_53 -> V_1 ) ) {
V_46 = V_42 -> V_52 -> V_53 -> V_30 ;
V_47 = V_42 -> V_52 -> V_53 -> V_54 ;
goto V_51;
}
if ( ! V_42 -> V_55 )
return - V_56 ;
V_48 = F_18 ( V_42 -> V_55 ) ;
V_45 . V_44 . V_1 = F_1 ( V_57 ) ?
V_57 : V_2 ;
V_49 = F_19 ( V_42 -> V_55 , & V_45 . V_44 ) ;
if ( V_49 ) {
F_20 ( V_58 , V_48 ,
V_42 -> V_59 , L_2 ,
L_3 , V_49 , 0 ) ;
return V_49 ;
}
V_46 = V_45 . V_44 . V_30 ;
V_47 = V_45 . V_44 . V_54 ;
V_51:
return F_16 ( V_46 , V_47 ,
V_38 , V_9 ) ;
}
int F_21 ( struct V_41 * V_42 ,
struct V_8 * V_9 )
{
T_1 * V_46 = NULL , V_32 = V_2 ;
T_2 V_47 = 0 ;
if ( V_42 -> V_50 )
goto V_51;
V_46 = V_42 -> V_52 -> V_53 -> V_30 ;
V_47 = V_42 -> V_52 -> V_53 -> V_54 ;
V_32 = V_42 -> V_52 -> V_53 -> V_1 ;
V_51:
return F_16 ( V_46 , V_47 ,
V_32 , V_9 ) ;
}
static int F_22 ( struct V_41 * V_42 ,
struct V_8 * V_9 ,
bool V_60 )
{
const char * V_61 = NULL ;
T_2 V_62 = 0 ;
F_23 ( V_42 -> V_59 == NULL && V_42 -> V_55 == NULL ) ;
if ( V_42 -> V_59 ) {
V_61 = V_42 -> V_59 ;
V_62 = strlen ( V_42 -> V_59 ) ;
if ( ! V_60 || V_62 <= V_63 )
goto V_51;
}
if ( V_42 -> V_55 ) {
V_61 = V_42 -> V_55 -> V_64 . V_65 -> V_66 . V_67 ;
V_62 = strlen ( V_61 ) ;
} else
V_62 = V_63 ;
V_51:
return F_2 ( V_61 , V_62 ,
V_13 , V_9 ) ;
}
int F_24 ( struct V_41 * V_42 ,
struct V_8 * V_9 )
{
return F_22 ( V_42 , V_9 , true ) ;
}
int F_25 ( struct V_41 * V_42 ,
struct V_8 * V_9 )
{
return F_22 ( V_42 , V_9 , false ) ;
}
int F_26 ( struct V_41 * V_42 ,
struct V_8 * V_9 )
{
enum V_6 V_36 = V_23 ;
struct V_68 * V_69 = V_42 -> V_69 ;
int V_70 = V_42 -> V_70 ;
int V_71 = 0 ;
if ( ( ! V_69 ) || ( V_69 -> type != V_72 ) )
goto V_51;
V_71 = F_2 ( V_69 , V_70 , V_36 ,
V_9 ) ;
V_51:
return V_71 ;
}
