void F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_2 V_3 , V_4 ;
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
F_2 ( V_11 , L_1 ) ;
if ( V_12 == NULL )
return;
if ( ! F_3 ( V_12 ) ) {
F_2 ( V_11 , L_2 ) ;
return;
}
memcpy ( & V_3 , ( V_1 - V_13 ) , V_13 ) ;
V_4 = F_4 ( V_3 ) ;
if ( V_4 & V_14 ) {
V_6 = F_5 ( V_2 + sizeof( struct V_9 ) ) ;
if ( V_6 == NULL ) {
F_2 ( V_11 , L_3 ) ;
return;
}
memcpy ( F_6 ( V_6 , V_2 ) , V_1 , V_2 ) ;
V_10 = (struct V_9 * ) F_7 ( V_6 , sizeof( * V_10 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_15 = 0 ;
V_10 -> V_8 . V_16 = F_8 ( sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_17 = F_9 (
( 1 << V_18 ) |
( 1 << V_19 ) ) ;
V_10 -> V_20 = 5 ;
if ( V_4 & V_21 ) {
V_10 -> V_22 = V_23 ;
} else {
V_10 -> V_22 = V_24 ;
}
} else {
V_6 = F_5 ( V_2 + sizeof( struct V_7 ) ) ;
if ( V_6 == NULL ) {
F_2 ( V_11 , L_3 ) ;
return;
}
memcpy ( F_6 ( V_6 , V_2 ) , V_1 , V_2 ) ;
V_8 = (struct V_7 * ) F_7 ( V_6 , sizeof( * V_8 ) ) ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_8 . V_15 = 0 ;
V_8 -> V_8 . V_16 = F_8 ( sizeof( struct V_7 ) ) ;
F_2 ( V_11 , L_4 , V_8 -> V_8 . V_16 ) ;
V_8 -> V_8 . V_17 = F_9
( 1 << V_18 ) ;
F_2 ( V_11 , L_5 , V_8 -> V_8 . V_17 ) ;
V_8 -> V_20 = 5 ;
}
V_6 -> V_25 = V_12 ;
F_10 ( V_6 , 0 ) ;
V_6 -> V_26 = V_27 ;
V_6 -> V_28 = V_29 ;
V_6 -> V_30 = F_11 ( V_31 ) ;
memset ( V_6 -> V_32 , 0 , sizeof( V_6 -> V_32 ) ) ;
F_12 ( V_6 ) ;
}
static void F_13 ( void * V_33 , int V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_33 ;
T_3 * V_37 = V_36 -> V_1 ;
if ( V_34 == 1 ) {
if ( V_38 || V_37 [ 0 ] == 0x10 || V_37 [ 0 ] == 0xb0 )
F_2 ( V_11 , L_6 , V_36 -> V_2 , V_36 -> V_1 ) ;
} else {
F_2 ( V_11 , L_7 , V_36 -> V_2 , V_36 -> V_1 ) ;
}
#ifndef F_14
F_15 ( V_36 -> V_1 ) ;
F_15 ( V_36 ) ;
#endif
}
static int F_16 ( struct V_39 * V_25 , const T_3 * V_37 , T_4 V_40 )
{
T_5 * V_41 ;
struct V_35 * V_42 = NULL ;
if ( V_25 == NULL ) {
F_17 ( V_11 , L_8 ) ;
return V_43 ;
}
V_41 = F_18 ( V_25 ) ;
F_19 ( V_25 ) ;
V_42 = F_20 ( sizeof( struct V_35 ) , V_44 ) ;
if ( V_42 == NULL ) {
F_21 ( L_9 ) ;
return V_43 ;
}
#ifdef F_14
V_40 += sizeof( struct V_35 * ) ;
#endif
V_42 -> V_1 = F_20 ( V_40 , V_44 ) ;
if ( V_42 -> V_1 == NULL ) {
F_21 ( L_10 ) ;
return V_43 ;
}
V_42 -> V_2 = V_40 ;
#ifndef F_14
memcpy ( V_42 -> V_1 , V_37 , V_40 ) ;
#else
memcpy ( V_42 -> V_1 , V_37 , V_40 - sizeof( struct V_35 * ) ) ;
memcpy ( ( V_42 -> V_1 ) + ( V_40 - sizeof( struct V_35 * ) ) , & V_42 , sizeof( struct V_35 * ) ) ;
if ( F_22 ( ( V_42 -> V_1 ) , V_40 ) == true ) {
return;
}
#endif
V_45 -> V_46 . V_47 ( V_42 , V_42 -> V_1 , V_42 -> V_2 , F_13 ) ;
F_23 ( V_25 ) ;
return 0 ;
}
static T_6 F_24 ( struct V_5 * V_6 ,
struct V_39 * V_25 )
{
struct V_48 * V_49 ;
T_7 V_50 , V_51 , V_52 = 0 ;
struct V_53 * V_54 ;
struct V_5 * V_55 ;
struct V_9 * V_10 ;
if ( V_12 == NULL )
return V_43 ;
V_54 = F_18 ( V_12 ) ;
if ( V_54 == NULL ) {
F_21 ( L_11 ) ;
return V_43 ;
}
V_49 = (struct V_48 * ) V_6 -> V_56 ;
V_50 = F_25 ( V_6 -> V_56 ) ;
if ( V_6 -> V_40 < V_50 ) {
F_21 ( L_12 ) ;
return - 1 ;
}
F_2 ( V_11 , L_13 , V_50 ) ;
if ( V_38 ) {
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ )
F_2 ( V_11 , L_14 , V_51 , V_6 -> V_56 [ V_51 ] ) ;
}
F_26 ( V_6 , V_50 ) ;
if ( V_6 -> V_56 [ 0 ] == 0xc0 )
F_2 ( V_11 , L_15 , V_6 -> V_56 [ 4 ] , V_6 -> V_56 [ 5 ] , V_6 -> V_56 [ 6 ] , V_6 -> V_56 [ 7 ] , V_6 -> V_56 [ 8 ] , V_6 -> V_56 [ 9 ] ) ;
if ( V_6 -> V_56 [ 0 ] == 0xc0 && ( ! ( memcmp ( V_57 , & V_6 -> V_56 [ 4 ] , 6 ) ) ) ) {
V_55 = F_5 ( V_6 -> V_40 + sizeof( struct V_9 ) ) ;
memcpy ( F_6 ( V_55 , V_6 -> V_40 ) , V_6 -> V_56 , V_6 -> V_40 ) ;
V_10 = (struct V_9 * ) F_7 ( V_55 , sizeof( * V_10 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_15 = 0 ;
V_10 -> V_8 . V_16 = F_8 ( sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_17 = F_9 (
( 1 << V_18 ) |
( 1 << V_19 ) ) ;
V_10 -> V_20 = 5 ;
V_10 -> V_22 = 0x0004 ;
V_55 -> V_25 = V_12 ;
F_10 ( V_55 , 0 ) ;
V_55 -> V_26 = V_27 ;
V_55 -> V_28 = V_29 ;
V_55 -> V_30 = F_11 ( V_31 ) ;
memset ( V_55 -> V_32 , 0 , sizeof( V_55 -> V_32 ) ) ;
F_12 ( V_55 ) ;
return 0 ;
}
V_6 -> V_25 = V_54 -> V_58 ;
F_2 ( V_11 , L_16 ) ;
F_2 ( V_11 , L_17 , V_6 -> V_25 -> V_59 ) ;
F_2 ( V_11 , L_18 , V_54 -> V_58 -> V_59 ) ;
#ifdef F_27
V_52 = F_28 ( V_6 , V_54 -> V_58 ) ;
#elif V_60
memcpy ( V_61 , & V_6 -> V_56 [ 10 ] , 6 ) ;
memcpy ( V_62 , & V_6 -> V_56 [ 16 ] , 6 ) ;
if ( ! ( memcmp ( V_61 , V_62 , 6 ) ) ) {
F_16 ( V_54 -> V_58 , V_6 -> V_56 , V_6 -> V_40 ) ;
F_29 ( V_6 ) ;
} else
V_52 = F_30 ( V_6 , V_54 -> V_58 ) ;
#endif
return V_52 ;
}
void F_31 ( void * V_33 , bool V_63 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_35 * V_36 = (struct V_35 * ) V_33 ;
T_3 * V_37 = V_36 -> V_1 ;
T_8 V_64 = ( V_36 -> V_2 ) - sizeof( struct V_35 * ) ;
{
V_6 = F_5 ( V_64 + sizeof( struct V_9 ) ) ;
memcpy ( F_6 ( V_6 , V_64 ) , V_36 -> V_1 , V_64 ) ;
V_10 = (struct V_9 * ) F_7 ( V_6 , sizeof( * V_10 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_15 = 0 ;
V_10 -> V_8 . V_16 = F_8 ( sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_17 = F_9 (
( 1 << V_18 ) |
( 1 << V_19 ) ) ;
V_10 -> V_20 = 5 ;
if ( V_63 ) {
V_10 -> V_22 = V_23 ;
} else {
V_10 -> V_22 = V_24 ;
}
V_6 -> V_25 = V_12 ;
F_10 ( V_6 , 0 ) ;
V_6 -> V_26 = V_27 ;
V_6 -> V_28 = V_29 ;
V_6 -> V_30 = F_11 ( V_31 ) ;
memset ( V_6 -> V_32 , 0 , sizeof( V_6 -> V_32 ) ) ;
F_12 ( V_6 ) ;
}
F_15 ( V_36 -> V_1 ) ;
F_15 ( V_36 ) ;
}
static void F_32 ( struct V_39 * V_25 )
{
V_25 -> V_65 = & V_66 ;
F_2 ( V_67 , L_19 ) ;
F_33 ( V_25 ) ;
V_25 -> V_68 = 0 ;
V_25 -> type = V_69 ;
memset ( V_25 -> V_70 , 0 , V_71 ) ;
#ifdef V_60
{
unsigned char V_72 [] = { 0x00 , 0x50 , 0xc2 , 0x5e , 0x10 , 0x8f } ;
memcpy ( V_25 -> V_70 , V_72 , V_71 ) ;
}
#else
V_25 -> V_70 [ 0 ] = 0x12 ;
#endif
}
struct V_39 * F_34 ( const char * V_59 , struct V_39 * V_73 )
{
T_7 V_52 = V_74 ;
struct V_53 * V_33 ;
if ( V_12 ) {
return V_12 ;
}
V_12 = F_35 ( sizeof( struct V_53 ) ) ;
if ( ! V_12 ) {
F_21 ( L_20 ) ;
return NULL ;
}
V_12 -> type = V_69 ;
strncpy ( V_12 -> V_59 , V_59 , V_75 ) ;
V_12 -> V_59 [ V_75 - 1 ] = 0 ;
V_12 -> V_65 = & V_66 ;
V_52 = F_36 ( V_12 ) ;
if ( V_52 ) {
F_21 ( L_21 , V_52 ) ;
return NULL ;
}
V_33 = F_18 ( V_12 ) ;
if ( V_33 == NULL ) {
F_21 ( L_22 ) ;
return NULL ;
}
V_33 -> V_58 = V_73 ;
return V_12 ;
}
int F_37 ()
{
bool V_76 = false ;
if ( V_12 != NULL ) {
F_17 ( V_11 , L_23 ) ;
F_17 ( V_11 , L_24 ) ;
if ( F_38 () ) {
F_39 () ;
V_76 = true ;
}
F_17 ( V_11 , L_25 ) ;
F_40 ( V_12 ) ;
if ( V_76 ) {
F_41 () ;
V_76 = false ;
}
V_12 = NULL ;
}
return V_74 ;
}
