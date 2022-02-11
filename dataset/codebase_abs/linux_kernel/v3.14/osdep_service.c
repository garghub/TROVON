inline int F_1 ( int V_1 )
{
if ( V_1 >= 0 )
return V_2 ;
return V_3 ;
}
T_1 F_2 ( T_2 * V_4 )
{
int V_5 = 0 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 <= strlen ( V_4 ) ; V_7 ++ ) {
if ( V_4 [ V_7 ] >= '0' && V_4 [ V_7 ] <= '9' )
V_5 = V_5 * 10 + V_4 [ V_7 ] - '0' ;
else if ( V_4 [ 0 ] == '-' && V_7 == 0 )
V_6 = 1 ;
else
break;
}
if ( V_6 == 1 )
V_5 = V_5 * - 1 ;
return V_5 ;
}
inline T_2 * F_3 ( T_1 V_8 )
{
T_2 * V_9 ;
V_9 = F_4 ( V_8 ) ;
return V_9 ;
}
inline T_2 * F_5 ( T_1 V_8 )
{
T_2 * V_9 ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 != NULL )
memset ( V_9 , 0 , V_8 ) ;
return V_9 ;
}
inline void F_6 ( T_2 * V_9 , T_1 V_8 )
{
F_7 ( V_9 ) ;
}
T_2 * F_8 ( T_1 V_8 )
{
T_2 * V_9 = NULL ;
V_9 = F_9 ( V_8 , F_10 () ? V_10 : V_11 ) ;
return V_9 ;
}
T_2 * F_11 ( T_1 V_8 )
{
T_2 * V_9 = F_8 ( V_8 ) ;
if ( V_9 != NULL )
memset ( V_9 , 0 , V_8 ) ;
return V_9 ;
}
void * F_12 ( int V_12 , int V_13 , int V_14 )
{
int V_15 ;
void * * V_16 = ( void * * ) F_13 ( V_12 * sizeof( void * ) + V_12 * V_13 * V_14 ) ;
if ( V_16 == NULL ) {
F_14 ( L_1 , V_17 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
V_16 [ V_15 ] = ( ( char * ) ( V_16 + V_12 ) ) + V_15 * V_13 * V_14 ;
return V_16 ;
}
void F_15 ( void * V_9 , int V_12 , int V_13 , int V_14 )
{
F_16 ( V_9 ) ;
}
int F_17 ( void * V_18 , void * V_19 , T_1 V_8 )
{
if ( ! ( memcmp ( V_18 , V_19 , V_8 ) ) )
return true ;
else
return false ;
}
void F_18 ( void * V_9 , int V_20 , T_1 V_8 )
{
memset ( V_9 , V_20 , V_8 ) ;
}
void F_19 ( struct V_21 * V_22 )
{
F_20 ( V_22 ) ;
}
T_1 F_21 ( struct V_21 * V_23 )
{
if ( F_22 ( V_23 ) )
return true ;
else
return false ;
}
void F_23 ( struct V_21 * V_24 , struct V_21 * V_23 )
{
F_24 ( V_24 , V_23 ) ;
}
void F_25 ( struct V_21 * V_24 , struct V_21 * V_23 )
{
F_26 ( V_24 , V_23 ) ;
}
T_1 F_27 ( struct V_25 * V_26 )
{
if ( F_28 ( V_26 ) )
return V_3 ;
else
return V_2 ;
}
void F_29 ( struct V_27 * V_28 )
{
F_19 ( & ( V_28 -> V_29 ) ) ;
F_30 ( & ( V_28 -> V_30 ) ) ;
}
T_1 F_31 ( struct V_27 * V_28 )
{
return F_21 ( & ( V_28 -> V_29 ) ) ;
}
T_1 F_32 ( struct V_21 * V_31 , struct V_21 * V_24 )
{
if ( V_31 == V_24 )
return true ;
else
return false ;
}
inline T_1 F_33 ( T_1 V_32 )
{
return V_32 * 1000 / V_33 ;
}
inline T_1 F_34 ( T_1 V_34 )
{
return V_34 * V_33 / 1000 ;
}
inline T_3 F_35 ( T_1 V_35 )
{
return F_33 ( V_36 - V_35 ) ;
}
inline T_3 F_36 ( T_1 V_35 , T_1 V_37 )
{
return F_33 ( V_37 - V_35 ) ;
}
void F_37 ( int V_34 )
{
T_1 V_38 ;
V_38 = ( V_34 * V_33 ) / 1000 ;
if ( V_38 == 0 )
V_38 = 1 ;
F_38 ( V_39 ) ;
if ( F_39 ( V_38 ) != 0 )
return;
}
struct V_40 * F_40 ( int V_41 ,
void * V_42 )
{
struct V_40 * V_43 ;
struct V_44 * V_45 ;
V_43 = F_41 ( sizeof( struct V_44 ) , 4 ) ;
if ( ! V_43 )
goto RETURN;
V_45 = F_42 ( V_43 ) ;
V_45 -> V_46 = V_42 ;
V_45 -> V_41 = V_41 ;
RETURN:
return V_43 ;
}
struct V_40 * F_43 ( int V_41 )
{
struct V_40 * V_43 ;
struct V_44 * V_45 ;
V_43 = F_41 ( sizeof( struct V_44 ) , 4 ) ;
if ( ! V_43 )
goto RETURN;
V_45 = F_42 ( V_43 ) ;
V_45 -> V_46 = F_44 ( V_41 ) ;
if ( ! V_45 -> V_46 ) {
F_45 ( V_43 ) ;
V_43 = NULL ;
goto RETURN;
}
V_45 -> V_41 = V_41 ;
RETURN:
return V_43 ;
}
void F_46 ( struct V_40 * V_47 )
{
struct V_44 * V_45 ;
if ( ! V_47 )
goto RETURN;
V_45 = F_42 ( V_47 ) ;
if ( ! V_45 -> V_46 )
goto RETURN;
F_47 ( V_45 -> V_46 , V_45 -> V_41 ) ;
F_45 ( V_47 ) ;
RETURN:
return;
}
int F_48 ( struct V_48 * V_49 , const char * V_50 )
{
struct V_40 * V_43 ;
struct V_40 * V_51 ;
struct V_52 * V_53 ;
int V_54 ;
if ( ! V_49 )
goto error;
V_51 = V_49 -> V_43 ;
V_53 = & V_49 -> V_55 ;
if ( V_53 -> V_56 ) {
F_45 ( V_53 -> V_56 ) ;
V_53 -> V_56 = NULL ;
}
if ( ! F_49 () )
F_50 ( V_51 ) ;
else
F_51 ( V_51 ) ;
F_52 ( V_51 ) ;
V_53 -> V_56 = V_51 ;
V_43 = F_53 ( V_49 ) ;
if ( ! V_43 ) {
V_54 = - 1 ;
goto error;
}
F_54 ( V_43 , F_55 ( F_56 ( V_49 ) ) ) ;
F_57 ( V_43 , V_50 ) ;
memcpy ( V_43 -> V_57 , V_49 -> V_58 . V_59 , V_60 ) ;
if ( ! F_49 () )
V_54 = F_58 ( V_43 ) ;
else
V_54 = F_59 ( V_43 ) ;
if ( V_54 != 0 ) {
F_60 ( V_61 , V_62 ,
( L_2 ) ) ;
goto error;
}
F_61 ( V_43 ) ;
return 0 ;
error:
return - 1 ;
}
T_4 F_62 ( T_4 V_63 , T_4 V_64 )
{
return F_63 ( V_63 , V_64 ) ;
}
T_4 F_64 ( T_4 V_63 , T_4 V_64 )
{
F_63 ( V_63 , V_64 ) ;
return V_63 ;
}
void F_65 ( T_2 * * V_65 , T_1 * V_66 )
{
* V_66 = 0 ;
F_16 ( * V_65 ) ;
* V_65 = NULL ;
}
void F_66 ( T_2 * * V_65 , T_1 * V_66 , T_2 * V_19 , T_1 V_67 )
{
T_1 V_68 = 0 , V_69 = 0 ;
T_2 * V_70 = NULL ;
T_2 * V_71 = NULL ;
if ( ! V_65 || ! V_66 )
return;
if ( ! V_19 || ! V_67 )
goto V_72;
V_71 = F_67 ( V_67 ) ;
if ( V_71 ) {
V_69 = V_67 ;
memcpy ( V_71 , V_19 , V_69 ) ;
}
V_72:
V_70 = * V_65 ;
V_68 = * V_66 ;
* V_66 = 0 ;
* V_65 = V_71 ;
* V_66 = V_69 ;
F_16 ( V_70 ) ;
}
inline bool F_68 ( struct V_73 * V_74 )
{
return ( V_74 -> V_75 == V_74 -> V_76 - 1 ) ? true : false ;
}
inline bool F_69 ( struct V_73 * V_74 )
{
return ( V_74 -> V_75 == V_74 -> V_76 ) ? true : false ;
}
bool F_70 ( struct V_73 * V_74 , void * V_65 )
{
if ( F_68 ( V_74 ) )
return V_3 ;
if ( 0 )
F_71 ( L_3 , V_17 , V_74 -> V_75 ) ;
V_74 -> V_77 [ V_74 -> V_75 ] = V_65 ;
V_74 -> V_75 = ( V_74 -> V_75 + 1 ) % V_74 -> V_14 ;
return V_2 ;
}
void * F_72 ( struct V_73 * V_74 )
{
void * V_65 ;
if ( F_69 ( V_74 ) )
return NULL ;
if ( 0 )
F_71 ( L_3 , V_17 , V_74 -> V_76 ) ;
V_65 = V_74 -> V_77 [ V_74 -> V_76 ] ;
V_74 -> V_76 = ( V_74 -> V_76 + 1 ) % V_74 -> V_14 ;
return V_65 ;
}
struct V_73 * F_73 ( T_1 V_14 )
{
struct V_73 * V_74 ;
V_74 = (struct V_73 * ) F_67 ( sizeof( * V_74 ) +
sizeof( void * ) * V_14 ) ;
if ( V_74 ) {
V_74 -> V_75 = 0 ;
V_74 -> V_76 = 0 ;
V_74 -> V_14 = V_14 ;
}
return V_74 ;
}
