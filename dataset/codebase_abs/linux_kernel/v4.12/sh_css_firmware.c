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
#if F_3 ( V_12 )
V_6 -> V_10 . V_13 = F_4 ( 1 ) ;
#else
V_6 -> V_10 . V_13 = F_4 ( V_4 -> V_10 . V_14 ) ;
#endif
if ( V_6 -> V_10 . V_13 == NULL )
return V_15 ;
memcpy ( ( void * ) V_6 -> V_10 . V_13 , V_8 , V_4 -> V_10 . V_14 ) ;
V_6 -> V_10 . V_16 = ( char * ) V_6 -> V_10 . V_13 + V_4 -> V_10 . V_17 ;
V_18 [ V_7 ] . V_19 = V_6 -> V_10 . V_13 ;
return V_20 ;
}
enum V_2
F_5 ( const char * V_4 , const struct V_3 * V_21 , struct V_22 * V_23 , unsigned V_24 )
{
const char * V_25 ;
const unsigned char * V_10 ;
if ( ( V_4 == NULL ) || ( V_23 == NULL ) )
return V_9 ;
if ( V_21 == NULL ) V_21 = ( const struct V_3 * ) V_4 ;
V_25 = V_4 + V_21 -> V_10 . V_26 ;
V_10 = ( const unsigned char * ) V_4 + V_21 -> V_10 . V_11 ;
if ( V_21 -> V_10 . V_14 != V_21 -> V_10 . V_27 + V_21 -> V_10 . V_28 + V_21 -> V_10 . V_29 + V_21 -> V_10 . V_30 ) {
return V_9 ;
}
if ( ( V_21 -> V_10 . V_11 % ( 1UL << ( V_31 - 3 ) ) ) != 0 )
return V_9 ;
V_23 -> V_10 = V_10 ;
V_23 -> V_32 = * V_21 ;
if ( ( V_21 -> type == V_33 ) || ( V_21 -> type == V_34 )
#if F_3 ( V_35 )
|| ( V_21 -> type == V_36 )
#endif
)
{
char * V_37 ;
int V_38 = ( int ) strlen ( V_25 ) ;
V_37 = ( char * ) F_6 ( V_38 + 1 , V_39 ) ;
if ( V_37 == NULL )
return V_15 ;
memcpy ( V_37 , V_25 , V_38 + 1 ) ;
V_23 -> V_25 = V_18 [ V_24 ] . V_25 = V_37 ;
} else {
V_23 -> V_25 = V_25 ;
}
if ( V_21 -> type == V_33 ) {
T_1 V_40 = sizeof( struct V_41 ) ;
T_1 V_42 = sizeof( struct V_43 ) ;
T_1 V_44 = sizeof( struct V_45 ) ;
char * V_46 = ( char * ) F_6 ( V_40 + V_42 + V_44 ,
V_39 ) ;
if ( V_46 == NULL )
return V_15 ;
V_23 -> V_47 . V_48 [ V_49 ] . V_50 = NULL ;
V_23 -> V_47 . V_48 [ V_51 ] . V_50 = NULL ;
V_23 -> V_47 . V_48 [ V_52 ] . V_50 = NULL ;
V_18 [ V_24 ] . V_19 = V_46 ;
memcpy ( V_46 , ( void * ) ( V_4 + V_21 -> V_10 . V_53 . V_54 [ V_49 ] ) ,
V_40 ) ;
V_23 -> V_47 . V_48 [ V_49 ] . V_50 = V_46 ;
memcpy ( V_46 + V_40 ,
( void * ) ( V_4 + V_21 -> V_10 . V_53 . V_54 [ V_51 ] ) ,
V_42 ) ;
V_23 -> V_47 . V_48 [ V_51 ] . V_50 = V_46 + V_40 ;
memcpy ( V_46 + V_40 + V_42 ,
( void * ) ( V_4 + V_21 -> V_10 . V_53 . V_54 [ V_52 ] ) ,
V_44 ) ;
V_23 -> V_47 . V_48 [ V_52 ] . V_50 = V_46 + V_40 + V_42 ;
}
return V_20 ;
}
bool
F_7 ( const char * V_5 )
{
struct V_55 * V_56 ;
V_57 = (struct V_57 * ) V_5 ;
V_56 = & V_57 -> V_56 ;
if ( strcmp ( V_56 -> V_58 , V_59 ) != 0 ) {
return false ;
} else {
return true ;
}
}
enum V_2
F_8 ( const char * V_5 ,
unsigned int V_60 )
{
unsigned V_61 ;
struct V_3 * V_62 ;
struct V_55 * V_56 ;
bool V_63 = false ;
V_57 = (struct V_57 * ) V_5 ;
V_56 = & V_57 -> V_56 ;
V_62 = & V_57 -> V_64 ;
strncpy ( V_1 , V_56 -> V_58 , F_9 ( sizeof( V_1 ) , sizeof( V_56 -> V_58 ) ) - 1 ) ;
V_63 = F_7 ( V_5 ) ;
if ( ! V_63 ) {
#if ! F_3 ( V_65 )
F_10 ( L_1 ,
V_56 -> V_58 , V_59 ) ;
return V_66 ;
#endif
} else {
F_11 ( L_2 , V_59 ) ;
}
if ( ! V_5 || V_60 < sizeof( struct V_55 ) )
return V_67 ;
if ( V_56 -> V_68 != sizeof( struct V_55 ) )
return V_67 ;
V_69 = V_56 -> V_70 ;
if ( V_69 > ( V_71 + V_72 ) ) {
V_73 = F_6 (
( V_69 - ( V_71 + V_72 ) ) *
sizeof( * V_73 ) , V_39 ) ;
if ( V_73 == NULL )
return V_15 ;
} else {
V_73 = NULL ;
}
V_18 = F_12 ( V_69 * sizeof( struct V_74 ) , V_39 ) ;
if ( V_18 == NULL )
return V_15 ;
for ( V_61 = 0 ; V_61 < V_69 ; V_61 ++ ) {
struct V_3 * V_21 = & V_62 [ V_61 ] ;
static struct V_22 V_23 ;
enum V_2 V_75 ;
V_75 = F_5 ( V_5 , V_21 , & V_23 , V_61 ) ;
if ( V_75 != V_20 )
return V_67 ;
if ( V_21 -> V_10 . V_11 + V_21 -> V_10 . V_14 > V_60 )
return V_67 ;
if ( V_21 -> type == V_34 ) {
if ( V_61 != V_76 )
return V_67 ;
V_75 = F_2 ( V_21 , V_5 , & V_77 , V_61 ) ;
if ( V_75 != V_20 )
return V_75 ;
#if F_3 ( V_35 )
} else if ( V_21 -> type == V_36 ) {
if ( V_61 != V_78 )
return V_67 ;
V_75 = F_2 ( V_21 , V_5 , & V_79 , V_61 ) ;
if ( V_75 != V_20 )
return V_75 ;
F_11 ( L_3 ) ;
#endif
} else {
if ( V_61 < ( V_71 + V_72 ) )
return V_67 ;
if ( V_21 -> type != V_33 )
return V_67 ;
if ( V_73 == NULL )
return V_67 ;
V_73 [ V_61 - ( V_71 + V_72 ) ] = V_23 ;
}
}
return V_20 ;
}
void F_13 ( void )
{
if ( V_18 ) {
unsigned int V_61 = 0 ;
for ( V_61 = 0 ; V_61 < V_69 ; V_61 ++ ) {
if ( V_18 [ V_61 ] . V_25 )
F_14 ( ( void * ) V_18 [ V_61 ] . V_25 ) ;
if ( V_18 [ V_61 ] . V_19 )
F_15 ( ( void * ) V_18 [ V_61 ] . V_19 ) ;
}
F_14 ( V_18 ) ;
V_18 = NULL ;
}
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_73 ) {
F_14 ( V_73 ) ;
V_73 = NULL ;
}
V_69 = 0 ;
}
T_2
F_16 ( const unsigned char * V_10 , unsigned V_14 )
{
T_2 V_80 = F_17 ( V_14 ) ;
assert ( V_10 != NULL ) ;
if ( V_80 )
F_18 ( V_80 , V_10 , V_14 ) ;
return V_80 ;
}
