char * F_1 ( void )
{
return V_1 ;
}
static enum V_2
F_2 ( struct V_3 * V_4 , const char * V_5 , struct V_3 * V_6 , unsigned V_7 )
{
const char * V_8 ;
if ( ( V_4 == NULL ) || ( V_5 == NULL ) )
return V_9 ;
V_8 = V_5 + V_4 -> V_10 . V_11 ;
* V_6 = * V_4 ;
V_6 -> V_10 . V_12 = F_3 ( V_4 -> V_10 . V_13 ) ;
if ( V_6 -> V_10 . V_12 == NULL )
return V_14 ;
memcpy ( ( void * ) V_6 -> V_10 . V_12 , V_8 , V_4 -> V_10 . V_13 ) ;
V_6 -> V_10 . V_15 = ( char * ) V_6 -> V_10 . V_12 + V_4 -> V_10 . V_16 ;
V_17 [ V_7 ] . V_18 = V_6 -> V_10 . V_12 ;
return V_19 ;
}
enum V_2
F_4 ( const char * V_4 , const struct V_3 * V_20 , struct V_21 * V_22 , unsigned V_23 )
{
const char * V_24 ;
const unsigned char * V_10 ;
if ( ( V_4 == NULL ) || ( V_22 == NULL ) )
return V_9 ;
if ( V_20 == NULL ) V_20 = ( const struct V_3 * ) V_4 ;
V_24 = V_4 + V_20 -> V_10 . V_25 ;
V_10 = ( const unsigned char * ) V_4 + V_20 -> V_10 . V_11 ;
if ( V_20 -> V_10 . V_13 != V_20 -> V_10 . V_26 + V_20 -> V_10 . V_27 + V_20 -> V_10 . V_28 + V_20 -> V_10 . V_29 ) {
return V_9 ;
}
if ( ( V_20 -> V_10 . V_11 % ( 1UL << ( V_30 - 3 ) ) ) != 0 )
return V_9 ;
V_22 -> V_10 = V_10 ;
V_22 -> V_31 = * V_20 ;
if ( V_20 -> type == V_32 || V_20 -> type == V_33 ) {
char * V_34 ;
int V_35 = ( int ) strlen ( V_24 ) ;
V_34 = ( char * ) F_5 ( V_35 + 1 , V_36 ) ;
if ( V_34 == NULL )
return V_14 ;
memcpy ( V_34 , V_24 , V_35 + 1 ) ;
V_22 -> V_24 = V_17 [ V_23 ] . V_24 = V_34 ;
} else {
V_22 -> V_24 = V_24 ;
}
if ( V_20 -> type == V_32 ) {
T_1 V_37 = sizeof( struct V_38 ) ;
T_1 V_39 = sizeof( struct V_40 ) ;
T_1 V_41 = sizeof( struct V_42 ) ;
char * V_43 = ( char * ) F_5 ( V_37 + V_39 + V_41 ,
V_36 ) ;
if ( V_43 == NULL )
return V_14 ;
V_22 -> V_44 . V_45 [ V_46 ] . V_47 = NULL ;
V_22 -> V_44 . V_45 [ V_48 ] . V_47 = NULL ;
V_22 -> V_44 . V_45 [ V_49 ] . V_47 = NULL ;
V_17 [ V_23 ] . V_18 = V_43 ;
memcpy ( V_43 , ( void * ) ( V_4 + V_20 -> V_10 . V_50 . V_51 [ V_46 ] ) ,
V_37 ) ;
V_22 -> V_44 . V_45 [ V_46 ] . V_47 = V_43 ;
memcpy ( V_43 + V_37 ,
( void * ) ( V_4 + V_20 -> V_10 . V_50 . V_51 [ V_48 ] ) ,
V_39 ) ;
V_22 -> V_44 . V_45 [ V_48 ] . V_47 = V_43 + V_37 ;
memcpy ( V_43 + V_37 + V_39 ,
( void * ) ( V_4 + V_20 -> V_10 . V_50 . V_51 [ V_49 ] ) ,
V_41 ) ;
V_22 -> V_44 . V_45 [ V_49 ] . V_47 = V_43 + V_37 + V_39 ;
}
return V_19 ;
}
bool
F_6 ( const char * V_5 )
{
struct V_52 * V_53 ;
V_54 = (struct V_54 * ) V_5 ;
V_53 = & V_54 -> V_53 ;
if ( strcmp ( V_53 -> V_55 , V_56 ) != 0 ) {
return false ;
} else {
return true ;
}
}
enum V_2
F_7 ( const char * V_5 ,
unsigned int V_57 )
{
unsigned V_58 ;
struct V_3 * V_59 ;
struct V_52 * V_53 ;
bool V_60 = false ;
V_54 = (struct V_54 * ) V_5 ;
V_53 = & V_54 -> V_53 ;
V_59 = & V_54 -> V_61 ;
strncpy ( V_1 , V_53 -> V_55 , F_8 ( sizeof( V_1 ) , sizeof( V_53 -> V_55 ) ) - 1 ) ;
V_60 = F_6 ( V_5 ) ;
if ( ! V_60 ) {
#if ! F_9 ( V_62 )
F_10 ( L_1 ,
V_53 -> V_55 , V_56 ) ;
return V_63 ;
#endif
} else {
F_11 ( L_2 , V_56 ) ;
}
if ( ! V_5 || V_57 < sizeof( struct V_52 ) )
return V_64 ;
if ( V_53 -> V_65 != sizeof( struct V_52 ) )
return V_64 ;
V_66 = V_53 -> V_67 ;
if ( V_66 > V_68 ) {
V_69 = F_5 (
( V_66 - V_68 ) *
sizeof( * V_69 ) , V_36 ) ;
if ( V_69 == NULL )
return V_14 ;
} else {
V_69 = NULL ;
}
V_17 = F_12 ( V_66 * sizeof( struct V_70 ) , V_36 ) ;
if ( V_17 == NULL )
return V_14 ;
for ( V_58 = 0 ; V_58 < V_66 ; V_58 ++ ) {
struct V_3 * V_20 = & V_59 [ V_58 ] ;
static struct V_21 V_22 ;
enum V_2 V_71 ;
V_71 = F_4 ( V_5 , V_20 , & V_22 , V_58 ) ;
if ( V_71 != V_19 )
return V_64 ;
if ( V_20 -> V_10 . V_11 + V_20 -> V_10 . V_13 > V_57 )
return V_64 ;
if ( V_20 -> type == V_33 ) {
if ( V_58 != V_72 )
return V_64 ;
V_71 = F_2 ( V_20 , V_5 , & V_73 , V_58 ) ;
if ( V_71 != V_19 )
return V_71 ;
} else {
if ( V_58 < V_68 )
return V_64 ;
if ( V_20 -> type != V_32 )
return V_64 ;
if ( V_69 == NULL )
return V_64 ;
V_69 [ V_58 - V_68 ] = V_22 ;
}
}
return V_19 ;
}
void F_13 ( void )
{
if ( V_17 ) {
unsigned int V_58 = 0 ;
for ( V_58 = 0 ; V_58 < V_66 ; V_58 ++ ) {
if ( V_17 [ V_58 ] . V_24 )
F_14 ( ( void * ) V_17 [ V_58 ] . V_24 ) ;
if ( V_17 [ V_58 ] . V_18 )
F_15 ( ( void * ) V_17 [ V_58 ] . V_18 ) ;
}
F_14 ( V_17 ) ;
V_17 = NULL ;
}
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
if ( V_69 ) {
F_14 ( V_69 ) ;
V_69 = NULL ;
}
V_66 = 0 ;
}
T_2
F_16 ( const unsigned char * V_10 , unsigned V_13 )
{
T_2 V_74 = F_17 ( V_13 ) ;
assert ( V_10 != NULL ) ;
if ( V_74 )
F_18 ( V_74 , V_10 , V_13 ) ;
return V_74 ;
}
