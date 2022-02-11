inline int F_1 ( int V_1 )
{
if ( V_1 >= 0 )
return V_2 ;
return V_3 ;
}
T_1 * F_2 ( T_2 V_4 )
{
T_1 * V_5 = NULL ;
V_5 = F_3 ( V_4 , F_4 () ? V_6 : V_7 ) ;
return V_5 ;
}
T_1 * F_5 ( T_2 V_4 )
{
T_1 * V_5 = F_2 ( V_4 ) ;
if ( V_5 != NULL ) {
memset ( V_5 , 0 , V_4 ) ;
}
return V_5 ;
}
inline struct V_8 * F_6 ( T_2 V_4 )
{
return F_7 ( V_4 , F_4 () ? V_6 : V_7 ) ;
}
inline struct V_8 * F_8 ( const struct V_8 * V_9 )
{
return F_9 ( V_9 , F_4 () ? V_6 : V_7 ) ;
}
inline struct V_8 * F_10 ( struct V_8 * V_9 )
{
return F_11 ( V_9 , F_4 () ? V_6 : V_7 ) ;
}
inline int F_12 ( T_3 V_10 , struct V_8 * V_9 )
{
V_9 -> V_11 = V_10 ;
return F_13 ( V_9 ) ;
}
void F_14 ( T_4 * V_12 , void * V_13 , void * V_14 )
{
struct V_15 * V_15 = (struct V_15 * ) V_13 ;
F_15 ( V_12 , V_15 -> V_16 , V_14 , V_15 ) ;
}
void F_16 ( struct V_17 * V_18 )
{
F_17 ( & ( V_18 -> V_19 ) ) ;
F_18 ( & ( V_18 -> V_20 ) ) ;
}
static int F_19 ( struct V_21 * * V_22 , char * V_23 , int V_24 , int V_25 )
{
struct V_21 * V_26 ;
V_26 = F_20 ( V_23 , V_24 , V_25 ) ;
if ( F_21 ( V_26 ) ) {
* V_22 = NULL ;
return F_22 ( V_26 ) ;
}
else {
* V_22 = V_26 ;
return 0 ;
}
}
static int F_23 ( struct V_21 * V_26 )
{
F_24 ( V_26 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_26 , char * V_27 , int V_28 )
{
int V_29 = 0 , V_30 = 0 ;
if ( ! V_26 -> V_31 || ! V_26 -> V_31 -> V_32 )
return - V_33 ;
while ( V_30 < V_28 ) {
V_29 = V_26 -> V_31 -> V_32 ( V_26 , ( char V_34 V_35 * ) V_27 + V_30 , V_28 - V_30 , & V_26 -> V_36 ) ;
if ( V_29 > 0 )
V_30 += V_29 ;
else if ( 0 != V_29 )
return V_29 ;
else
break;
}
return V_30 ;
}
static int F_26 ( char * V_23 )
{
struct V_21 * V_26 ;
int V_37 = 0 ;
T_5 V_38 ;
char V_27 ;
V_26 = F_20 ( V_23 , V_39 , 0 ) ;
if ( F_21 ( V_26 ) ) {
V_37 = F_22 ( V_26 ) ;
}
else {
V_38 = F_27 () ; F_28 ( F_29 () ) ;
if ( 1 != F_25 ( V_26 , & V_27 , 1 ) )
V_37 = - V_40 ;
F_28 ( V_38 ) ;
F_24 ( V_26 , NULL ) ;
}
return V_37 ;
}
static int F_30 ( char * V_23 , T_1 * V_27 , T_2 V_4 )
{
int V_37 = - 1 ;
T_5 V_38 ;
struct V_21 * V_26 ;
if ( V_23 && V_27 ) {
if ( 0 == ( V_37 = F_19 ( & V_26 , V_23 , V_39 , 0 ) ) ) {
F_31 ( L_1 , V_41 , V_23 , V_26 ) ;
V_38 = F_27 () ; F_28 ( F_29 () ) ;
V_37 = F_25 ( V_26 , V_27 , V_4 ) ;
F_28 ( V_38 ) ;
F_23 ( V_26 ) ;
F_31 ( L_2 , V_41 , V_37 ) ;
} else {
F_31 ( L_3 , V_41 , V_23 , V_37 ) ;
}
} else {
F_31 ( L_4 , V_41 ) ;
V_37 = - V_40 ;
}
return V_37 ;
}
int F_32 ( char * V_23 )
{
if ( F_26 ( V_23 ) == 0 )
return true ;
else
return false ;
}
int F_33 ( char * V_23 , T_1 * V_27 , T_2 V_4 )
{
int V_37 = F_30 ( V_23 , V_27 , V_4 ) ;
return V_37 >= 0 ? V_37 : 0 ;
}
struct V_42 * F_34 ( int V_43 , void * V_44 )
{
struct V_42 * V_16 ;
struct V_45 * V_46 ;
V_16 = F_35 ( sizeof( struct V_45 ) , 4 ) ;
if ( ! V_16 )
goto RETURN;
V_46 = F_36 ( V_16 ) ;
V_46 -> V_47 = V_44 ;
V_46 -> V_43 = V_43 ;
RETURN:
return V_16 ;
}
struct V_42 * F_37 ( int V_43 )
{
struct V_42 * V_16 ;
struct V_45 * V_46 ;
V_16 = F_35 ( sizeof( struct V_45 ) , 4 ) ;
if ( ! V_16 )
goto RETURN;
V_46 = F_36 ( V_16 ) ;
V_46 -> V_47 = F_38 ( V_43 ) ;
if ( ! V_46 -> V_47 ) {
F_39 ( V_16 ) ;
V_16 = NULL ;
goto RETURN;
}
V_46 -> V_43 = V_43 ;
RETURN:
return V_16 ;
}
void F_40 ( struct V_42 * V_48 )
{
struct V_45 * V_46 ;
if ( ! V_48 )
goto RETURN;
V_46 = F_36 ( V_48 ) ;
if ( ! V_46 -> V_47 )
goto RETURN;
F_41 ( V_46 -> V_47 ) ;
F_39 ( V_48 ) ;
RETURN:
return;
}
int F_42 ( struct V_15 * V_13 , const char * V_49 )
{
struct V_42 * V_16 ;
struct V_42 * V_50 ;
struct V_51 * V_52 ;
int V_37 ;
if ( ! V_13 )
goto error;
V_50 = V_13 -> V_16 ;
V_52 = & V_13 -> V_53 ;
if ( V_52 -> V_54 ) {
F_39 ( V_52 -> V_54 ) ;
V_52 -> V_54 = NULL ;
}
if ( ! F_43 () )
F_44 ( V_50 ) ;
else
F_45 ( V_50 ) ;
V_52 -> V_54 = V_50 ;
V_16 = F_46 ( V_13 ) ;
if ( ! V_16 ) {
V_37 = - 1 ;
goto error;
}
F_47 ( V_16 , F_48 ( F_49 ( V_13 ) ) ) ;
F_50 ( V_16 , V_49 ) ;
memcpy ( V_16 -> V_55 , V_13 -> V_56 . V_57 , V_58 ) ;
if ( ! F_43 () )
V_37 = F_51 ( V_16 ) ;
else
V_37 = F_52 ( V_16 ) ;
if ( V_37 != 0 ) {
F_53 ( V_59 , V_60 , ( L_5 ) ) ;
goto error;
}
return 0 ;
error:
return - 1 ;
}
T_6 F_54 ( T_6 V_61 , T_6 V_62 )
{
return F_55 ( V_61 , V_62 ) ;
}
void F_56 ( T_1 * * V_27 , T_2 * V_63 )
{
T_2 V_64 ;
if ( ! V_27 || ! V_63 )
return;
V_64 = * V_63 ;
if ( * V_27 ) {
* V_63 = 0 ;
F_57 ( * V_27 ) ;
* V_27 = NULL ;
}
}
void F_58 ( T_1 * * V_27 , T_2 * V_63 , T_1 * V_65 , T_2 V_66 )
{
T_2 V_64 = 0 , V_67 = 0 ;
T_1 * V_68 = NULL ;
T_1 * V_69 = NULL ;
if ( ! V_27 || ! V_63 )
return;
if ( ! V_65 || ! V_66 )
goto V_70;
V_69 = F_59 ( V_66 ) ;
if ( V_69 ) {
V_67 = V_66 ;
memcpy ( V_69 , V_65 , V_67 ) ;
}
V_70:
V_68 = * V_27 ;
V_64 = * V_63 ;
* V_63 = 0 ;
* V_27 = V_69 ;
* V_63 = V_67 ;
if ( V_68 && V_64 > 0 )
F_57 ( V_68 ) ;
}
inline bool F_60 ( struct V_71 * V_72 )
{
return ( V_72 -> V_73 == V_72 -> V_32 - 1 ) ? true : false ;
}
inline bool F_61 ( struct V_71 * V_72 )
{
return ( V_72 -> V_73 == V_72 -> V_32 ) ? true : false ;
}
bool F_62 ( struct V_71 * V_72 , void * V_27 )
{
if ( F_60 ( V_72 ) )
return V_3 ;
F_31 ( L_6 , V_41 , V_72 -> V_73 ) ;
V_72 -> V_74 [ V_72 -> V_73 ] = V_27 ;
V_72 -> V_73 = ( V_72 -> V_73 + 1 ) % V_72 -> V_75 ;
return V_2 ;
}
void * F_63 ( struct V_71 * V_72 )
{
void * V_27 ;
if ( F_61 ( V_72 ) )
return NULL ;
F_31 ( L_6 , V_41 , V_72 -> V_32 ) ;
V_27 = V_72 -> V_74 [ V_72 -> V_32 ] ;
V_72 -> V_32 = ( V_72 -> V_32 + 1 ) % V_72 -> V_75 ;
return V_27 ;
}
struct V_71 * F_64 ( T_2 V_75 )
{
struct V_71 * V_72 ;
V_72 = (struct V_71 * ) F_59 ( sizeof( * V_72 ) + sizeof( void * ) * V_75 ) ;
if ( V_72 ) {
V_72 -> V_73 = V_72 -> V_32 = 0 ;
V_72 -> V_75 = V_75 ;
}
return V_72 ;
}
