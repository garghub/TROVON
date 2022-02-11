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
T_2 * F_3 ( T_1 V_8 )
{
T_2 * V_9 = NULL ;
V_9 = F_4 ( V_8 , F_5 () ? V_10 : V_11 ) ;
return V_9 ;
}
T_2 * F_6 ( T_1 V_8 )
{
T_2 * V_9 = F_3 ( V_8 ) ;
if ( V_9 != NULL )
memset ( V_9 , 0 , V_8 ) ;
return V_9 ;
}
void * F_7 ( int V_12 , int V_13 , int V_14 )
{
int V_15 ;
void * * V_16 = ( void * * ) F_8 ( V_12 * sizeof( void * ) + V_12 * V_13 * V_14 ) ;
if ( V_16 == NULL ) {
F_9 ( L_1 , V_17 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
V_16 [ V_15 ] = ( ( char * ) ( V_16 + V_12 ) ) + V_15 * V_13 * V_14 ;
return V_16 ;
}
void F_10 ( void * V_9 , int V_12 , int V_13 , int V_14 )
{
F_11 ( V_9 ) ;
}
void F_12 ( void * V_9 , int V_18 , T_1 V_8 )
{
memset ( V_9 , V_18 , V_8 ) ;
}
void F_13 ( struct V_19 * V_20 )
{
F_14 ( V_20 ) ;
}
T_1 F_15 ( struct V_19 * V_21 )
{
if ( F_16 ( V_21 ) )
return true ;
else
return false ;
}
void F_17 ( struct V_19 * V_22 , struct V_19 * V_21 )
{
F_18 ( V_22 , V_21 ) ;
}
void F_19 ( struct V_19 * V_22 , struct V_19 * V_21 )
{
F_20 ( V_22 , V_21 ) ;
}
T_1 F_21 ( struct V_23 * V_24 )
{
if ( F_22 ( V_24 ) )
return V_3 ;
else
return V_2 ;
}
void F_23 ( struct V_25 * V_26 )
{
F_13 ( & ( V_26 -> V_27 ) ) ;
F_24 ( & ( V_26 -> V_28 ) ) ;
}
T_1 F_25 ( struct V_25 * V_26 )
{
return F_15 ( & ( V_26 -> V_27 ) ) ;
}
T_1 F_26 ( struct V_19 * V_29 , struct V_19 * V_22 )
{
if ( V_29 == V_22 )
return true ;
else
return false ;
}
inline T_1 F_27 ( T_1 V_30 )
{
return V_30 * 1000 / V_31 ;
}
inline T_1 F_28 ( T_1 V_32 )
{
return V_32 * V_31 / 1000 ;
}
inline T_3 F_29 ( T_1 V_33 )
{
return F_27 ( V_34 - V_33 ) ;
}
inline T_3 F_30 ( T_1 V_33 , T_1 V_35 )
{
return F_27 ( V_35 - V_33 ) ;
}
void F_31 ( int V_32 )
{
T_1 V_36 ;
V_36 = ( V_32 * V_31 ) / 1000 ;
if ( V_36 == 0 )
V_36 = 1 ;
F_32 ( V_37 ) ;
if ( F_33 ( V_36 ) != 0 )
return;
}
struct V_38 * F_34 ( int V_39 ,
void * V_40 )
{
struct V_38 * V_41 ;
struct V_42 * V_43 ;
V_41 = F_35 ( sizeof( struct V_42 ) , 4 ) ;
if ( ! V_41 )
goto RETURN;
V_43 = F_36 ( V_41 ) ;
V_43 -> V_44 = V_40 ;
V_43 -> V_39 = V_39 ;
RETURN:
return V_41 ;
}
struct V_38 * F_37 ( int V_39 )
{
struct V_38 * V_41 ;
struct V_42 * V_43 ;
V_41 = F_35 ( sizeof( struct V_42 ) , 4 ) ;
if ( ! V_41 )
goto RETURN;
V_43 = F_36 ( V_41 ) ;
V_43 -> V_44 = F_38 ( V_39 ) ;
if ( ! V_43 -> V_44 ) {
F_39 ( V_41 ) ;
V_41 = NULL ;
goto RETURN;
}
V_43 -> V_39 = V_39 ;
RETURN:
return V_41 ;
}
void F_40 ( struct V_38 * V_45 )
{
struct V_42 * V_43 ;
if ( ! V_45 )
goto RETURN;
V_43 = F_36 ( V_45 ) ;
if ( ! V_43 -> V_44 )
goto RETURN;
F_41 ( V_43 -> V_44 ) ;
F_39 ( V_45 ) ;
RETURN:
return;
}
int F_42 ( struct V_46 * V_47 , const char * V_48 )
{
struct V_38 * V_41 ;
struct V_38 * V_49 ;
struct V_50 * V_51 ;
int V_52 ;
if ( ! V_47 )
goto error;
V_49 = V_47 -> V_41 ;
V_51 = & V_47 -> V_53 ;
if ( V_51 -> V_54 ) {
F_39 ( V_51 -> V_54 ) ;
V_51 -> V_54 = NULL ;
}
if ( ! F_43 () )
F_44 ( V_49 ) ;
else
F_45 ( V_49 ) ;
F_46 ( V_49 ) ;
V_51 -> V_54 = V_49 ;
V_41 = F_47 ( V_47 ) ;
if ( ! V_41 ) {
V_52 = - 1 ;
goto error;
}
F_48 ( V_41 , F_49 ( F_50 ( V_47 ) ) ) ;
F_51 ( V_41 , V_48 ) ;
memcpy ( V_41 -> V_55 , V_47 -> V_56 . V_57 , V_58 ) ;
if ( ! F_43 () )
V_52 = F_52 ( V_41 ) ;
else
V_52 = F_53 ( V_41 ) ;
if ( V_52 != 0 ) {
F_54 ( V_59 , V_60 ,
( L_2 ) ) ;
goto error;
}
F_55 ( V_41 ) ;
return 0 ;
error:
return - 1 ;
}
T_4 F_56 ( T_4 V_61 , T_4 V_62 )
{
return F_57 ( V_61 , V_62 ) ;
}
T_4 F_58 ( T_4 V_61 , T_4 V_62 )
{
F_57 ( V_61 , V_62 ) ;
return V_61 ;
}
void F_59 ( T_2 * * V_63 , T_1 * V_64 )
{
* V_64 = 0 ;
F_11 ( * V_63 ) ;
* V_63 = NULL ;
}
void F_60 ( T_2 * * V_63 , T_1 * V_64 , T_2 * V_65 , T_1 V_66 )
{
T_1 V_67 = 0 , V_68 = 0 ;
T_2 * V_69 = NULL ;
T_2 * V_70 = NULL ;
if ( ! V_63 || ! V_64 )
return;
if ( ! V_65 || ! V_66 )
goto V_71;
V_70 = F_61 ( V_66 ) ;
if ( V_70 ) {
V_68 = V_66 ;
memcpy ( V_70 , V_65 , V_68 ) ;
}
V_71:
V_69 = * V_63 ;
V_67 = * V_64 ;
* V_64 = 0 ;
* V_63 = V_70 ;
* V_64 = V_68 ;
F_11 ( V_69 ) ;
}
inline bool F_62 ( struct V_72 * V_73 )
{
return ( V_73 -> V_74 == V_73 -> V_75 - 1 ) ? true : false ;
}
inline bool F_63 ( struct V_72 * V_73 )
{
return ( V_73 -> V_74 == V_73 -> V_75 ) ? true : false ;
}
bool F_64 ( struct V_72 * V_73 , void * V_63 )
{
if ( F_62 ( V_73 ) )
return V_3 ;
if ( 0 )
F_65 ( L_3 , V_17 , V_73 -> V_74 ) ;
V_73 -> V_76 [ V_73 -> V_74 ] = V_63 ;
V_73 -> V_74 = ( V_73 -> V_74 + 1 ) % V_73 -> V_14 ;
return V_2 ;
}
void * F_66 ( struct V_72 * V_73 )
{
void * V_63 ;
if ( F_63 ( V_73 ) )
return NULL ;
if ( 0 )
F_65 ( L_3 , V_17 , V_73 -> V_75 ) ;
V_63 = V_73 -> V_76 [ V_73 -> V_75 ] ;
V_73 -> V_75 = ( V_73 -> V_75 + 1 ) % V_73 -> V_14 ;
return V_63 ;
}
struct V_72 * F_67 ( T_1 V_14 )
{
struct V_72 * V_73 ;
V_73 = (struct V_72 * ) F_61 ( sizeof( * V_73 ) +
sizeof( void * ) * V_14 ) ;
if ( V_73 ) {
V_73 -> V_74 = 0 ;
V_73 -> V_75 = 0 ;
V_73 -> V_14 = V_14 ;
}
return V_73 ;
}
