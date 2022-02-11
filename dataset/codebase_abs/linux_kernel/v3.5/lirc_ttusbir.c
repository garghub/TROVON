static int F_1 ( void * V_1 )
{
int V_2 , V_3 ;
struct V_4 * V_5 = V_1 ;
F_2 ( L_1 ) ;
V_5 -> V_6 = 1 ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ ) {
V_3 = F_3 ( V_5 -> V_8 [ V_2 ] , V_9 ) ;
if ( V_3 ) {
F_4 ( & V_5 -> V_10 -> V_11 ,
L_2 ,
V_12 , V_2 ) ;
return V_3 ;
}
}
return 0 ;
}
static void F_5 ( void * V_1 )
{
struct V_4 * V_5 = V_1 ;
F_2 ( L_3 ) ;
V_5 -> V_6 = 0 ;
}
static void F_6 ( struct V_8 * V_8 )
{
struct V_4 * V_5 ;
unsigned char * V_13 ;
int V_2 ;
int V_14 ;
V_5 = V_8 -> V_15 ;
if ( ! V_5 -> V_6 )
return;
V_13 = ( unsigned char * ) V_8 -> V_16 ;
for ( V_2 = 0 ; V_2 < 128 ; V_2 ++ ) {
V_13 [ V_2 ] = ~ V_17 [ V_13 [ V_2 ] ] ;
if ( V_5 -> V_18 == V_13 [ V_2 ] ) {
if ( V_5 -> V_19 < V_20 / 63 )
V_5 -> V_19 ++ ;
} else {
V_14 = V_5 -> V_19 * 62 ;
if ( V_5 -> V_18 )
V_14 |= V_21 ;
if ( ! F_7 ( & V_5 -> V_22 ) ) {
F_8 ( & V_5 -> V_22 , ( void * ) & V_14 ) ;
F_9 ( & V_5 -> V_22 . V_23 ) ;
}
V_5 -> V_19 = 0 ;
V_5 -> V_18 = V_13 [ V_2 ] ;
}
}
F_3 ( V_8 , V_24 ) ;
}
static int F_10 ( struct V_25 * V_26 , const struct V_27 * V_28 )
{
int V_29 , V_30 ;
int V_31 = 0 ;
int V_2 , V_32 ;
int V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_4 * V_5 ;
F_2 ( L_4 ) ;
V_33 = sizeof( struct V_4 ) +
( sizeof( struct V_8 * ) * V_7 ) +
( sizeof( char * ) * V_7 ) +
( V_7 * 128 ) ;
V_5 = F_11 ( V_33 , V_9 ) ;
if ( ! V_5 )
return - V_40 ;
V_5 -> V_8 = (struct V_8 * * ) ( ( char * ) V_5 +
sizeof( struct V_4 ) ) ;
V_5 -> V_41 = ( char * * ) ( ( char * ) V_5 -> V_8 +
( sizeof( struct V_8 * ) * V_7 ) ) ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ )
V_5 -> V_41 [ V_2 ] = ( char * ) V_5 -> V_41 +
( sizeof( char * ) * V_7 ) + ( V_2 * 128 ) ;
V_5 -> V_42 = & V_42 ;
V_5 -> V_43 = - 1 ;
V_5 -> V_44 = F_12 ( F_13 ( V_26 ) ) ;
V_5 -> V_10 = V_26 ;
V_5 -> V_18 = 0x00 ;
V_5 -> V_19 = 0 ;
for ( V_29 = 0 ; V_29 < V_26 -> V_45 && ! V_31 ; V_29 ++ ) {
V_35 = & V_26 -> V_46 [ V_29 ] ;
V_37 = & V_35 -> V_47 ;
for ( V_30 = 0 ; V_30 < V_37 -> V_48 ; V_30 ++ ) {
V_39 = & V_35 -> V_49 [ V_30 ] ;
if ( ( V_39 -> V_47 . V_50 == 0x82 ) &&
( V_39 -> V_47 . V_51 == 0x10 ) ) {
V_5 -> V_43 = V_29 ;
V_5 -> V_49 = V_30 ;
V_31 = 1 ;
break;
}
}
}
if ( V_5 -> V_43 != - 1 )
F_2 ( L_5 , V_5 -> V_43 ) ;
else {
F_4 ( & V_26 -> V_11 , L_6 ) ;
F_14 ( V_5 ) ;
return - V_52 ;
}
F_15 ( V_5 -> V_44 , 0 , V_5 -> V_43 ) ;
F_16 ( V_26 , V_5 ) ;
if ( F_17 ( & V_5 -> V_22 , sizeof( int ) , 256 ) < 0 ) {
F_4 ( & V_26 -> V_11 , L_7 ) ;
F_16 ( V_26 , NULL ) ;
F_14 ( V_5 ) ;
return - V_40 ;
}
strcpy ( V_5 -> V_53 . V_54 , L_8 ) ;
V_5 -> V_53 . V_55 = - 1 ;
V_5 -> V_53 . V_56 = 1 ;
V_5 -> V_53 . V_57 = 0 ;
V_5 -> V_53 . V_1 = V_5 ;
V_5 -> V_53 . V_58 = NULL ;
V_5 -> V_53 . V_22 = & V_5 -> V_22 ;
V_5 -> V_53 . F_1 = F_1 ;
V_5 -> V_53 . F_5 = F_5 ;
V_5 -> V_53 . V_11 = & V_26 -> V_11 ;
V_5 -> V_53 . V_59 = V_60 ;
V_5 -> V_53 . V_61 = V_62 ;
V_5 -> V_55 = F_18 ( & V_5 -> V_53 ) ;
if ( V_5 -> V_55 < 0 ) {
F_4 ( & V_26 -> V_11 , L_9 ) ;
F_16 ( V_26 , NULL ) ;
F_19 ( & V_5 -> V_22 ) ;
F_14 ( V_5 ) ;
return - V_63 ;
}
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ ) {
V_5 -> V_8 [ V_2 ] = F_20 ( 8 , V_9 ) ;
if ( ! V_5 -> V_8 [ V_2 ] ) {
F_4 ( & V_26 -> V_11 , L_10 ) ;
for ( V_32 = V_2 - 1 ; V_32 >= 0 ; V_32 -- )
F_14 ( V_5 -> V_8 [ V_32 ] ) ;
F_19 ( & V_5 -> V_22 ) ;
F_21 ( V_5 -> V_55 ) ;
F_14 ( V_5 ) ;
F_16 ( V_26 , NULL ) ;
return - V_40 ;
}
V_5 -> V_8 [ V_2 ] -> V_11 = V_5 -> V_44 ;
V_5 -> V_8 [ V_2 ] -> V_15 = V_5 ;
V_5 -> V_8 [ V_2 ] -> V_64 = F_22 ( V_5 -> V_44 ,
V_5 -> V_49 ) ;
V_5 -> V_8 [ V_2 ] -> V_65 = 1 ;
V_5 -> V_8 [ V_2 ] -> V_66 = V_67 ;
V_5 -> V_8 [ V_2 ] -> V_16 = & V_5 -> V_41 [ V_2 ] [ 0 ] ;
V_5 -> V_8 [ V_2 ] -> V_68 = F_6 ;
V_5 -> V_8 [ V_2 ] -> V_69 = 8 ;
V_5 -> V_8 [ V_2 ] -> V_70 = 128 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
V_5 -> V_8 [ V_2 ] -> V_71 [ V_32 ] . V_72 = V_32 * 16 ;
V_5 -> V_8 [ V_2 ] -> V_71 [ V_32 ] . V_73 = 16 ;
}
}
return 0 ;
}
static void F_23 ( struct V_25 * V_26 )
{
int V_2 ;
struct V_4 * V_5 ;
F_2 ( L_11 ) ;
V_5 = (struct V_4 * ) F_24 ( V_26 ) ;
F_16 ( V_26 , NULL ) ;
F_21 ( V_5 -> V_55 ) ;
F_2 ( L_12 ) ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ ) {
F_25 ( V_5 -> V_8 [ V_2 ] ) ;
F_26 ( V_5 -> V_8 [ V_2 ] ) ;
}
F_2 ( L_13 ) ;
F_19 ( & V_5 -> V_22 ) ;
F_14 ( V_5 ) ;
}
