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
int F_16 ( void * V_30 , void * V_31 , void * * V_32 ,
int V_33 , struct V_8 * V_34 , int * V_35 ,
unsigned long * V_36 , int V_37 , char * V_38 )
{
void * V_39 = V_30 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_33 ; V_40 ++ ) {
if ( V_36 == NULL || ! F_17 ( V_40 , V_36 ) ) {
if ( V_39 > ( V_31 - sizeof( T_2 ) ) )
break;
V_34 [ V_40 ] . V_16 = * ( T_2 * ) V_39 ;
if ( V_27 )
V_34 [ V_40 ] . V_16 = F_18 ( V_34 [ V_40 ] . V_16 ) ;
V_39 += sizeof( T_2 ) ;
}
if ( V_39 > ( V_31 - V_34 [ V_40 ] . V_16 ) )
break;
V_34 [ V_40 ] . V_4 = V_39 ;
V_39 += V_34 [ V_40 ] . V_16 ;
}
if ( ( V_37 & V_41 ) && V_40 != V_33 ) {
F_19 ( L_2 ,
V_38 , V_33 , V_40 ) ;
return - V_42 ;
}
if ( ( V_37 & V_43 ) && V_39 != V_31 ) {
F_19 ( L_3 ,
V_38 , V_31 , V_39 ) ;
return - V_42 ;
}
if ( V_35 )
* V_35 = V_40 ;
if ( V_32 )
* V_32 = V_39 ;
return 0 ;
}
static int F_20 ( T_1 * V_44 , T_2 V_45 , T_1 V_46 ,
struct V_8 * V_9 )
{
T_1 V_47 [ V_48 + 2 + V_49 ] = { 0 } ;
enum V_6 V_50 = V_22 ;
T_2 V_51 = 0 ;
if ( V_46 < V_52 ) {
V_50 = V_21 ;
V_51 += snprintf ( V_47 , V_48 + 1 , L_1 ,
V_53 [ V_46 ] ) ;
V_47 [ V_51 ] = ':' ;
V_51 += 2 ;
}
if ( V_44 )
memcpy ( V_47 + V_51 , V_44 , V_45 ) ;
else
V_51 += V_54 ;
return F_2 ( V_47 , V_51 + V_45 ,
V_50 , V_9 ) ;
}
int F_21 ( struct V_55 * V_56 ,
struct V_8 * V_9 )
{
struct {
struct V_57 V_58 ;
char V_44 [ V_49 ] ;
} V_59 ;
T_1 * V_60 = NULL ;
T_2 V_61 = 0 ;
struct V_62 * V_62 ;
int V_63 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
if ( V_56 -> V_64 )
goto V_65;
if ( F_1 ( V_56 -> V_66 -> V_67 -> V_1 ) ) {
V_60 = V_56 -> V_66 -> V_67 -> V_44 ;
V_61 = V_56 -> V_66 -> V_67 -> V_68 ;
goto V_65;
}
if ( ! V_56 -> V_69 )
return - V_42 ;
V_62 = F_22 ( V_56 -> V_69 ) ;
V_59 . V_58 . V_1 = F_1 ( V_70 ) ?
V_70 : V_2 ;
V_63 = F_23 ( V_56 -> V_69 , & V_59 . V_58 ) ;
if ( V_63 ) {
F_24 ( V_71 , V_62 ,
V_56 -> V_72 , L_4 ,
L_5 , V_63 , 0 ) ;
return V_63 ;
}
V_60 = V_59 . V_58 . V_44 ;
V_61 = V_59 . V_58 . V_68 ;
V_65:
return F_20 ( V_60 , V_61 ,
V_52 , V_9 ) ;
}
int F_25 ( struct V_55 * V_56 ,
struct V_8 * V_9 )
{
T_1 * V_60 = NULL , V_46 = V_2 ;
T_2 V_61 = 0 ;
if ( V_56 -> V_64 )
goto V_65;
V_60 = V_56 -> V_66 -> V_67 -> V_44 ;
V_61 = V_56 -> V_66 -> V_67 -> V_68 ;
V_46 = V_56 -> V_66 -> V_67 -> V_1 ;
V_65:
return F_20 ( V_60 , V_61 ,
V_46 , V_9 ) ;
}
static int F_26 ( struct V_55 * V_56 ,
struct V_8 * V_9 ,
bool V_73 )
{
const char * V_74 = NULL ;
T_2 V_75 = 0 ;
F_27 ( V_56 -> V_72 == NULL && V_56 -> V_69 == NULL ) ;
if ( V_56 -> V_72 ) {
V_74 = V_56 -> V_72 ;
V_75 = strlen ( V_56 -> V_72 ) ;
if ( ! V_73 || V_75 <= V_76 )
goto V_65;
}
if ( V_56 -> V_69 ) {
V_74 = V_56 -> V_69 -> V_77 . V_78 -> V_79 . V_80 ;
V_75 = strlen ( V_74 ) ;
} else
V_75 = V_76 ;
V_65:
return F_2 ( V_74 , V_75 ,
V_13 , V_9 ) ;
}
int F_28 ( struct V_55 * V_56 ,
struct V_8 * V_9 )
{
return F_26 ( V_56 , V_9 , true ) ;
}
int F_29 ( struct V_55 * V_56 ,
struct V_8 * V_9 )
{
return F_26 ( V_56 , V_9 , false ) ;
}
int F_30 ( struct V_55 * V_56 ,
struct V_8 * V_9 )
{
enum V_6 V_50 = V_23 ;
struct V_81 * V_82 = V_56 -> V_82 ;
int V_83 = V_56 -> V_83 ;
int V_84 = 0 ;
if ( ( ! V_82 ) || ( V_82 -> type != V_85 ) )
goto V_65;
V_84 = F_2 ( V_82 , V_83 , V_50 ,
V_9 ) ;
V_65:
return V_84 ;
}
