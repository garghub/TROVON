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
struct V_35 * V_41 = NULL ;
if ( V_25 == NULL ) {
F_17 ( V_11 , L_8 ) ;
return V_42 ;
}
F_18 ( V_25 ) ;
V_41 = F_19 ( sizeof( struct V_35 ) , V_43 ) ;
if ( V_41 == NULL ) {
F_20 ( L_9 ) ;
return V_42 ;
}
#ifdef F_14
V_40 += sizeof( struct V_35 * ) ;
#endif
V_41 -> V_1 = F_19 ( V_40 , V_43 ) ;
if ( V_41 -> V_1 == NULL ) {
F_20 ( L_10 ) ;
return V_42 ;
}
V_41 -> V_2 = V_40 ;
#ifndef F_14
memcpy ( V_41 -> V_1 , V_37 , V_40 ) ;
#else
memcpy ( V_41 -> V_1 , V_37 , V_40 - sizeof( struct V_35 * ) ) ;
memcpy ( ( V_41 -> V_1 ) + ( V_40 - sizeof( struct V_35 * ) ) , & V_41 , sizeof( struct V_35 * ) ) ;
if ( F_21 ( ( V_41 -> V_1 ) , V_40 ) == true ) {
return;
}
#endif
V_44 -> V_45 . V_46 ( V_41 , V_41 -> V_1 , V_41 -> V_2 , F_13 ) ;
F_22 ( V_25 ) ;
return 0 ;
}
static T_5 F_23 ( struct V_5 * V_6 ,
struct V_39 * V_25 )
{
T_6 V_47 , V_48 , V_49 = 0 ;
struct V_50 * V_51 ;
struct V_5 * V_52 ;
struct V_9 * V_10 ;
if ( V_12 == NULL )
return V_42 ;
V_51 = F_24 ( V_12 ) ;
if ( V_51 == NULL ) {
F_20 ( L_11 ) ;
return V_42 ;
}
V_47 = F_25 ( V_6 -> V_53 ) ;
if ( V_6 -> V_40 < V_47 ) {
F_20 ( L_12 ) ;
return - 1 ;
}
F_2 ( V_11 , L_13 , V_47 ) ;
if ( V_38 ) {
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ )
F_2 ( V_11 , L_14 , V_48 , V_6 -> V_53 [ V_48 ] ) ;
}
F_26 ( V_6 , V_47 ) ;
if ( V_6 -> V_53 [ 0 ] == 0xc0 )
F_2 ( V_11 , L_15 , V_6 -> V_53 [ 4 ] , V_6 -> V_53 [ 5 ] , V_6 -> V_53 [ 6 ] , V_6 -> V_53 [ 7 ] , V_6 -> V_53 [ 8 ] , V_6 -> V_53 [ 9 ] ) ;
if ( V_6 -> V_53 [ 0 ] == 0xc0 && ( ! ( memcmp ( V_54 , & V_6 -> V_53 [ 4 ] , 6 ) ) ) ) {
V_52 = F_5 ( V_6 -> V_40 + sizeof( struct V_9 ) ) ;
memcpy ( F_6 ( V_52 , V_6 -> V_40 ) , V_6 -> V_53 , V_6 -> V_40 ) ;
V_10 = (struct V_9 * ) F_7 ( V_52 , sizeof( * V_10 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_15 = 0 ;
V_10 -> V_8 . V_16 = F_8 ( sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_17 = F_9 (
( 1 << V_18 ) |
( 1 << V_19 ) ) ;
V_10 -> V_20 = 5 ;
V_10 -> V_22 = 0x0004 ;
V_52 -> V_25 = V_12 ;
F_10 ( V_52 , 0 ) ;
V_52 -> V_26 = V_27 ;
V_52 -> V_28 = V_29 ;
V_52 -> V_30 = F_11 ( V_31 ) ;
memset ( V_52 -> V_32 , 0 , sizeof( V_52 -> V_32 ) ) ;
F_12 ( V_52 ) ;
return 0 ;
}
V_6 -> V_25 = V_51 -> V_55 ;
F_2 ( V_11 , L_16 ) ;
F_2 ( V_11 , L_17 , V_6 -> V_25 -> V_56 ) ;
F_2 ( V_11 , L_18 , V_51 -> V_55 -> V_56 ) ;
#if V_57
memcpy ( V_58 , & V_6 -> V_53 [ 10 ] , 6 ) ;
memcpy ( V_59 , & V_6 -> V_53 [ 16 ] , 6 ) ;
if ( ! ( memcmp ( V_58 , V_59 , 6 ) ) ) {
F_16 ( V_51 -> V_55 , V_6 -> V_53 , V_6 -> V_40 ) ;
F_27 ( V_6 ) ;
} else
V_49 = F_28 ( V_6 , V_51 -> V_55 ) ;
#endif
return V_49 ;
}
void F_29 ( void * V_33 , bool V_60 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_35 * V_36 = (struct V_35 * ) V_33 ;
T_3 * V_37 = V_36 -> V_1 ;
T_7 V_61 = ( V_36 -> V_2 ) - sizeof( struct V_35 * ) ;
{
V_6 = F_5 ( V_61 + sizeof( struct V_9 ) ) ;
memcpy ( F_6 ( V_6 , V_61 ) , V_36 -> V_1 , V_61 ) ;
V_10 = (struct V_9 * ) F_7 ( V_6 , sizeof( * V_10 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_15 = 0 ;
V_10 -> V_8 . V_16 = F_8 ( sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_17 = F_9 (
( 1 << V_18 ) |
( 1 << V_19 ) ) ;
V_10 -> V_20 = 5 ;
if ( V_60 ) {
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
static void F_30 ( struct V_39 * V_25 )
{
V_25 -> V_62 = & V_63 ;
F_2 ( V_64 , L_19 ) ;
F_31 ( V_25 ) ;
V_25 -> V_65 |= V_66 ;
V_25 -> type = V_67 ;
F_32 ( V_25 -> V_68 ) ;
#ifdef V_57
{
unsigned char V_69 [] = { 0x00 , 0x50 , 0xc2 , 0x5e , 0x10 , 0x8f } ;
memcpy ( V_25 -> V_68 , V_69 , V_70 ) ;
}
#else
V_25 -> V_68 [ 0 ] = 0x12 ;
#endif
}
struct V_39 * F_33 ( const char * V_56 , struct V_39 * V_71 )
{
T_6 V_49 = V_72 ;
struct V_50 * V_33 ;
if ( V_12 ) {
return V_12 ;
}
V_12 = F_34 ( sizeof( struct V_50 ) ) ;
if ( ! V_12 ) {
F_20 ( L_20 ) ;
return NULL ;
}
V_12 -> type = V_67 ;
strncpy ( V_12 -> V_56 , V_56 , V_73 ) ;
V_12 -> V_56 [ V_73 - 1 ] = 0 ;
V_12 -> V_62 = & V_63 ;
V_49 = F_35 ( V_12 ) ;
if ( V_49 ) {
F_20 ( L_21 , V_49 ) ;
return NULL ;
}
V_33 = F_24 ( V_12 ) ;
if ( V_33 == NULL ) {
F_20 ( L_22 ) ;
return NULL ;
}
V_33 -> V_55 = V_71 ;
return V_12 ;
}
int F_36 ( void )
{
bool V_74 = false ;
if ( V_12 != NULL ) {
F_17 ( V_11 , L_23 ) ;
F_17 ( V_11 , L_24 ) ;
if ( F_37 () ) {
F_38 () ;
V_74 = true ;
}
F_17 ( V_11 , L_25 ) ;
F_39 ( V_12 ) ;
if ( V_74 ) {
F_40 () ;
V_74 = false ;
}
V_12 = NULL ;
}
return V_72 ;
}
