void F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_2 V_3 , V_4 ;
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
if ( ! V_11 )
return;
if ( ! F_2 ( V_11 ) )
return;
memcpy ( & V_3 , ( V_1 - V_12 ) , V_12 ) ;
V_4 = F_3 ( V_3 ) ;
if ( V_4 & V_13 ) {
V_6 = F_4 ( V_2 + sizeof( struct V_9 ) ) ;
if ( ! V_6 )
return;
F_5 ( V_6 , V_1 , V_2 ) ;
V_10 = F_6 ( V_6 , sizeof( * V_10 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_14 = 0 ;
V_10 -> V_8 . V_15 = F_7 ( sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_16 = F_8 (
( 1 << V_17 ) |
( 1 << V_18 ) ) ;
V_10 -> V_19 = 5 ;
if ( V_4 & V_20 ) {
V_10 -> V_21 = V_22 ;
} else {
V_10 -> V_21 = V_23 ;
}
} else {
V_6 = F_4 ( V_2 + sizeof( struct V_7 ) ) ;
if ( ! V_6 )
return;
F_5 ( V_6 , V_1 , V_2 ) ;
V_8 = F_6 ( V_6 , sizeof( * V_8 ) ) ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_8 . V_14 = 0 ;
V_8 -> V_8 . V_15 = F_7 ( sizeof( struct V_7 ) ) ;
V_8 -> V_8 . V_16 = F_8
( 1 << V_17 ) ;
V_8 -> V_19 = 5 ;
}
V_6 -> V_24 = V_11 ;
F_9 ( V_6 ) ;
V_6 -> V_25 = V_26 ;
V_6 -> V_27 = V_28 ;
V_6 -> V_29 = F_10 ( V_30 ) ;
memset ( V_6 -> V_31 , 0 , sizeof( V_6 -> V_31 ) ) ;
F_11 ( V_6 ) ;
}
static void F_12 ( void * V_32 , int V_33 )
{
struct V_34 * V_35 = V_32 ;
F_13 ( V_35 -> V_1 ) ;
F_13 ( V_35 ) ;
}
static int F_14 ( struct V_36 * V_24 , const T_1 * V_37 , T_3 V_38 )
{
struct V_34 * V_39 = NULL ;
if ( ! V_24 )
return - V_40 ;
F_15 ( V_24 ) ;
V_39 = F_16 ( sizeof( * V_39 ) , V_41 ) ;
if ( ! V_39 )
return - V_42 ;
V_39 -> V_1 = F_16 ( V_38 , V_41 ) ;
if ( ! V_39 -> V_1 ) {
F_13 ( V_39 ) ;
return - V_42 ;
}
V_39 -> V_2 = V_38 ;
memcpy ( V_39 -> V_1 , V_37 , V_38 ) ;
F_17 ( V_24 , V_39 , V_39 -> V_1 , V_39 -> V_2 ,
F_12 ) ;
F_18 ( V_24 ) ;
return 0 ;
}
static T_4 F_19 ( struct V_5 * V_6 ,
struct V_36 * V_24 )
{
T_2 V_43 , V_44 = 0 ;
struct V_45 * V_46 ;
struct V_5 * V_47 ;
struct V_9 * V_10 ;
if ( ! V_11 )
return - V_40 ;
V_46 = F_20 ( V_11 ) ;
if ( ! V_46 )
return - V_40 ;
V_43 = F_21 ( V_6 -> V_48 ) ;
if ( V_6 -> V_38 < V_43 )
return - 1 ;
F_22 ( V_6 , V_43 ) ;
if ( V_6 -> V_48 [ 0 ] == 0xc0 && ( ! ( memcmp ( V_49 , & V_6 -> V_48 [ 4 ] , 6 ) ) ) ) {
V_47 = F_4 ( V_6 -> V_38 + sizeof( struct V_9 ) ) ;
if ( ! V_47 )
return - V_42 ;
F_5 ( V_47 , V_6 -> V_48 , V_6 -> V_38 ) ;
V_10 = F_6 ( V_47 , sizeof( * V_10 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_14 = 0 ;
V_10 -> V_8 . V_15 = F_7 ( sizeof( struct V_9 ) ) ;
V_10 -> V_8 . V_16 = F_8 (
( 1 << V_17 ) |
( 1 << V_18 ) ) ;
V_10 -> V_19 = 5 ;
V_10 -> V_21 = 0x0004 ;
V_47 -> V_24 = V_11 ;
F_9 ( V_47 ) ;
V_47 -> V_25 = V_26 ;
V_47 -> V_27 = V_28 ;
V_47 -> V_29 = F_10 ( V_30 ) ;
memset ( V_47 -> V_31 , 0 , sizeof( V_47 -> V_31 ) ) ;
F_11 ( V_47 ) ;
return 0 ;
}
V_6 -> V_24 = V_46 -> V_50 ;
memcpy ( V_51 , & V_6 -> V_48 [ 10 ] , 6 ) ;
memcpy ( V_52 , & V_6 -> V_48 [ 16 ] , 6 ) ;
if ( ! ( memcmp ( V_51 , V_52 , 6 ) ) ) {
V_44 = F_14 ( V_46 -> V_50 , V_6 -> V_48 , V_6 -> V_38 ) ;
if ( V_44 )
F_23 ( V_24 , L_1 ) ;
F_24 ( V_6 ) ;
} else {
V_44 = F_25 ( V_6 , V_46 -> V_50 ) ;
}
return V_44 ;
}
struct V_36 * F_26 ( const char * V_53 ,
struct V_36 * V_54 )
{
T_2 V_44 = 0 ;
struct V_45 * V_32 ;
if ( V_11 )
return V_11 ;
V_11 = F_27 ( sizeof( struct V_45 ) ) ;
if ( ! V_11 )
return NULL ;
V_11 -> type = V_55 ;
strncpy ( V_11 -> V_53 , V_53 , V_56 ) ;
V_11 -> V_53 [ V_56 - 1 ] = 0 ;
V_11 -> V_57 = & V_58 ;
V_44 = F_28 ( V_11 ) ;
if ( V_44 ) {
F_23 ( V_54 , L_2 ) ;
return NULL ;
}
V_32 = F_20 ( V_11 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_50 = V_54 ;
return V_11 ;
}
int F_29 ( void )
{
bool V_59 = false ;
if ( V_11 ) {
if ( F_30 () ) {
F_31 () ;
V_59 = true ;
}
F_32 ( V_11 ) ;
if ( V_59 ) {
F_33 () ;
V_59 = false ;
}
V_11 = NULL ;
}
return 0 ;
}
