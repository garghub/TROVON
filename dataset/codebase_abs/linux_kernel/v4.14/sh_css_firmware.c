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
V_34 = F_5 ( V_24 , V_35 ) ;
if ( ! V_34 )
return V_14 ;
V_22 -> V_24 = V_17 [ V_23 ] . V_24 = V_34 ;
} else {
V_22 -> V_24 = V_24 ;
}
if ( V_20 -> type == V_32 ) {
T_1 V_36 = sizeof( struct V_37 ) ;
T_1 V_38 = sizeof( struct V_39 ) ;
T_1 V_40 = sizeof( struct V_41 ) ;
char * V_42 = ( char * ) F_6 ( V_36 + V_38 + V_40 ,
V_35 ) ;
if ( V_42 == NULL )
return V_14 ;
V_22 -> V_43 . V_44 [ V_45 ] . V_46 = NULL ;
V_22 -> V_43 . V_44 [ V_47 ] . V_46 = NULL ;
V_22 -> V_43 . V_44 [ V_48 ] . V_46 = NULL ;
V_17 [ V_23 ] . V_18 = V_42 ;
memcpy ( V_42 , ( void * ) ( V_4 + V_20 -> V_10 . V_49 . V_50 [ V_45 ] ) ,
V_36 ) ;
V_22 -> V_43 . V_44 [ V_45 ] . V_46 = V_42 ;
memcpy ( V_42 + V_36 ,
( void * ) ( V_4 + V_20 -> V_10 . V_49 . V_50 [ V_47 ] ) ,
V_38 ) ;
V_22 -> V_43 . V_44 [ V_47 ] . V_46 = V_42 + V_36 ;
memcpy ( V_42 + V_36 + V_38 ,
( void * ) ( V_4 + V_20 -> V_10 . V_49 . V_50 [ V_48 ] ) ,
V_40 ) ;
V_22 -> V_43 . V_44 [ V_48 ] . V_46 = V_42 + V_36 + V_38 ;
}
return V_19 ;
}
bool
F_7 ( const char * V_5 )
{
struct V_51 * V_52 ;
V_53 = (struct V_53 * ) V_5 ;
V_52 = & V_53 -> V_52 ;
if ( strcmp ( V_52 -> V_54 , V_55 ) != 0 ) {
return false ;
} else {
return true ;
}
}
enum V_2
F_8 ( const char * V_5 ,
unsigned int V_56 )
{
unsigned V_57 ;
struct V_3 * V_58 ;
struct V_51 * V_52 ;
bool V_59 = false ;
V_53 = (struct V_53 * ) V_5 ;
V_52 = & V_53 -> V_52 ;
V_58 = & V_53 -> V_60 ;
strncpy ( V_1 , V_52 -> V_54 , F_9 ( sizeof( V_1 ) , sizeof( V_52 -> V_54 ) ) - 1 ) ;
V_59 = F_7 ( V_5 ) ;
if ( ! V_59 ) {
#if ! F_10 ( V_61 )
F_11 ( L_1 ,
V_52 -> V_54 , V_55 ) ;
return V_62 ;
#endif
} else {
F_12 ( L_2 , V_55 ) ;
}
if ( ! V_5 || V_56 < sizeof( struct V_51 ) )
return V_63 ;
if ( V_52 -> V_64 != sizeof( struct V_51 ) )
return V_63 ;
V_65 = V_52 -> V_66 ;
if ( V_65 > V_67 ) {
V_68 = F_6 (
( V_65 - V_67 ) *
sizeof( * V_68 ) , V_35 ) ;
if ( V_68 == NULL )
return V_14 ;
} else {
V_68 = NULL ;
}
V_17 = F_13 ( V_65 * sizeof( struct V_69 ) , V_35 ) ;
if ( V_17 == NULL )
return V_14 ;
for ( V_57 = 0 ; V_57 < V_65 ; V_57 ++ ) {
struct V_3 * V_20 = & V_58 [ V_57 ] ;
static struct V_21 V_22 ;
enum V_2 V_70 ;
V_70 = F_4 ( V_5 , V_20 , & V_22 , V_57 ) ;
if ( V_70 != V_19 )
return V_63 ;
if ( V_20 -> V_10 . V_11 + V_20 -> V_10 . V_13 > V_56 )
return V_63 ;
if ( V_20 -> type == V_33 ) {
if ( V_57 != V_71 )
return V_63 ;
V_70 = F_2 ( V_20 , V_5 , & V_72 , V_57 ) ;
if ( V_70 != V_19 )
return V_70 ;
} else {
if ( V_57 < V_67 )
return V_63 ;
if ( V_20 -> type != V_32 )
return V_63 ;
if ( V_68 == NULL )
return V_63 ;
V_68 [ V_57 - V_67 ] = V_22 ;
}
}
return V_19 ;
}
void F_14 ( void )
{
if ( V_17 ) {
unsigned int V_57 = 0 ;
for ( V_57 = 0 ; V_57 < V_65 ; V_57 ++ ) {
if ( V_17 [ V_57 ] . V_24 )
F_15 ( ( void * ) V_17 [ V_57 ] . V_24 ) ;
if ( V_17 [ V_57 ] . V_18 )
F_16 ( ( void * ) V_17 [ V_57 ] . V_18 ) ;
}
F_15 ( V_17 ) ;
V_17 = NULL ;
}
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
if ( V_68 ) {
F_15 ( V_68 ) ;
V_68 = NULL ;
}
V_65 = 0 ;
}
T_2
F_17 ( const unsigned char * V_10 , unsigned V_13 )
{
T_2 V_73 = F_18 ( V_13 ) ;
assert ( V_10 != NULL ) ;
if ( V_73 )
F_19 ( V_73 , V_10 , V_13 ) ;
return V_73 ;
}
