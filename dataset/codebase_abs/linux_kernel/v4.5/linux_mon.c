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
T_1 * V_37 = V_36 -> V_1 ;
if ( V_34 == 1 ) {
if ( V_38 || V_37 [ 0 ] == 0x10 || V_37 [ 0 ] == 0xb0 )
F_2 ( V_11 , L_6 , V_36 -> V_2 , V_36 -> V_1 ) ;
} else {
F_2 ( V_11 , L_7 , V_36 -> V_2 , V_36 -> V_1 ) ;
}
F_14 ( V_36 -> V_1 ) ;
F_14 ( V_36 ) ;
}
static int F_15 ( struct V_39 * V_25 , const T_1 * V_37 , T_3 V_40 )
{
struct V_35 * V_41 = NULL ;
if ( V_25 == NULL ) {
F_16 ( V_11 , L_8 ) ;
return - V_42 ;
}
F_17 ( V_25 ) ;
V_41 = F_18 ( sizeof( struct V_35 ) , V_43 ) ;
if ( V_41 == NULL ) {
F_19 ( L_9 ) ;
return - V_42 ;
}
V_41 -> V_1 = F_18 ( V_40 , V_43 ) ;
if ( V_41 -> V_1 == NULL ) {
F_19 ( L_10 ) ;
F_14 ( V_41 ) ;
return - V_42 ;
}
V_41 -> V_2 = V_40 ;
memcpy ( V_41 -> V_1 , V_37 , V_40 ) ;
F_20 ( V_25 , V_41 , V_41 -> V_1 , V_41 -> V_2 ,
F_13 ) ;
F_21 ( V_25 ) ;
return 0 ;
}
static T_4 F_22 ( struct V_5 * V_6 ,
struct V_39 * V_25 )
{
T_2 V_44 , V_45 , V_46 = 0 ;
struct V_47 * V_48 ;
struct V_5 * V_49 ;
struct V_9 * V_10 ;
if ( V_12 == NULL )
return - V_42 ;
V_48 = F_23 ( V_12 ) ;
if ( V_48 == NULL ) {
F_19 ( L_11 ) ;
return - V_42 ;
}
V_44 = F_24 ( V_6 -> V_50 ) ;
if ( V_6 -> V_40 < V_44 ) {
F_19 ( L_12 ) ;
return - 1 ;
}
F_2 ( V_11 , L_13 , V_44 ) ;
if ( V_38 ) {
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ )
F_2 ( V_11 , L_14 , V_45 , V_6 -> V_50 [ V_45 ] ) ;
}
F_25 ( V_6 , V_44 ) ;
if ( V_6 -> V_50 [ 0 ] == 0xc0 )
F_2 ( V_11 , L_15 , V_6 -> V_50 [ 4 ] , V_6 -> V_50 [ 5 ] , V_6 -> V_50 [ 6 ] , V_6 -> V_50 [ 7 ] , V_6 -> V_50 [ 8 ] , V_6 -> V_50 [ 9 ] ) ;
if ( V_6 -> V_50 [ 0 ] == 0xc0 && ( ! ( memcmp ( V_51 , & V_6 -> V_50 [ 4 ] , 6 ) ) ) ) {
V_49 = F_5 ( V_6 -> V_40 + sizeof( struct V_9 ) ) ;
memcpy ( F_6 ( V_49 , V_6 -> V_40 ) , V_6 -> V_50 , V_6 -> V_40 ) ;
V_10 = (struct V_9 * ) F_7 ( V_49 , sizeof( * V_10 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_15 = 0 ;
V_10 -> V_8 . V_16 = F_8 ( sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_17 = F_9 (
( 1 << V_18 ) |
( 1 << V_19 ) ) ;
V_10 -> V_20 = 5 ;
V_10 -> V_22 = 0x0004 ;
V_49 -> V_25 = V_12 ;
F_10 ( V_49 , 0 ) ;
V_49 -> V_26 = V_27 ;
V_49 -> V_28 = V_29 ;
V_49 -> V_30 = F_11 ( V_31 ) ;
memset ( V_49 -> V_32 , 0 , sizeof( V_49 -> V_32 ) ) ;
F_12 ( V_49 ) ;
return 0 ;
}
V_6 -> V_25 = V_48 -> V_52 ;
F_2 ( V_11 , L_16 ) ;
F_2 ( V_11 , L_17 , V_6 -> V_25 -> V_53 ) ;
F_2 ( V_11 , L_18 , V_48 -> V_52 -> V_53 ) ;
memcpy ( V_54 , & V_6 -> V_50 [ 10 ] , 6 ) ;
memcpy ( V_55 , & V_6 -> V_50 [ 16 ] , 6 ) ;
if ( ! ( memcmp ( V_54 , V_55 , 6 ) ) ) {
F_15 ( V_48 -> V_52 , V_6 -> V_50 , V_6 -> V_40 ) ;
F_26 ( V_6 ) ;
} else
V_46 = F_27 ( V_6 , V_48 -> V_52 ) ;
return V_46 ;
}
struct V_39 * F_28 ( const char * V_53 , struct V_39 * V_56 )
{
T_2 V_46 = 0 ;
struct V_47 * V_33 ;
if ( V_12 ) {
return V_12 ;
}
V_12 = F_29 ( sizeof( struct V_47 ) ) ;
if ( ! V_12 ) {
F_19 ( L_19 ) ;
return NULL ;
}
V_12 -> type = V_57 ;
strncpy ( V_12 -> V_53 , V_53 , V_58 ) ;
V_12 -> V_53 [ V_58 - 1 ] = 0 ;
V_12 -> V_59 = & V_60 ;
V_46 = F_30 ( V_12 ) ;
if ( V_46 ) {
F_19 ( L_20 , V_46 ) ;
return NULL ;
}
V_33 = F_23 ( V_12 ) ;
if ( V_33 == NULL ) {
F_19 ( L_21 ) ;
return NULL ;
}
V_33 -> V_52 = V_56 ;
return V_12 ;
}
int F_31 ( void )
{
bool V_61 = false ;
if ( V_12 != NULL ) {
F_16 ( V_11 , L_22 ) ;
F_16 ( V_11 , L_23 ) ;
if ( F_32 () ) {
F_33 () ;
V_61 = true ;
}
F_16 ( V_11 , L_24 ) ;
F_34 ( V_12 ) ;
if ( V_61 ) {
F_35 () ;
V_61 = false ;
}
V_12 = NULL ;
}
return 0 ;
}
