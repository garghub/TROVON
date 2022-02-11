static bool F_1 ( const struct V_1 * V_2 ,
const char * V_3 , T_1 V_4 )
{
const struct V_5 * V_6 ;
int V_7 , V_8 , V_9 ;
T_2 V_10 [ 2 ] = { 0 , 0 } ;
int V_11 = ( ( const unsigned char * ) V_3 ) [ 5 ] ;
memcpy ( ( ( char * ) V_10 ) + 2 , V_3 , V_12 ) ;
V_7 = V_2 -> V_13 [ V_11 ] ;
V_8 = V_2 -> V_13 [ V_11 + 1 ] ;
if ( V_4 ) {
for ( V_9 = V_7 ; V_9 < V_8 ; V_9 ++ ) {
V_6 = & V_2 -> V_14 [ V_9 ] ;
if ( V_10 [ 1 ] == V_6 -> V_10 [ 1 ] && V_10 [ 0 ] == V_6 -> V_10 [ 0 ] )
if ( V_6 -> V_4 == 0 || V_6 -> V_4 == V_4 )
return true ;
}
} else {
for ( V_9 = V_7 ; V_9 < V_8 ; V_9 ++ ) {
V_6 = & V_2 -> V_14 [ V_9 ] ;
if ( V_10 [ 1 ] == V_6 -> V_10 [ 1 ] && V_10 [ 0 ] == V_6 -> V_10 [ 0 ] )
if ( V_6 -> V_4 == 0 )
return true ;
}
}
return false ;
}
static int F_2 ( const struct V_1
* V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
if ( V_2 -> V_13 [ V_9 ] > V_2 -> V_13 [ V_9 + 1 ] )
return - 0x100 - V_9 ;
if ( V_2 -> V_13 [ V_9 ] < 0 )
return - 0x200 - V_9 ;
if ( V_2 -> V_13 [ V_9 ] > V_2 -> V_15 )
return - 0x300 - V_9 ;
}
if ( V_2 -> V_13 [ 256 ] > V_2 -> V_15 )
return - 0xc00 ;
return 0 ;
}
static int F_3 ( const struct V_16 * V_17 , T_1 * V_18 )
{
if ( F_4 ( V_17 ) -> V_19 == F_5 ( V_20 ) ) {
const struct V_21 * V_22 ;
struct V_21 V_23 ;
V_22 = F_6 ( V_17 , 0 , sizeof( V_23 ) , & V_23 ) ;
if ( V_22 == NULL )
return - 1 ;
* V_18 = V_22 -> V_24 ;
} else if ( F_4 ( V_17 ) -> V_19 == F_5 ( V_25 ) ) {
const struct V_26 * V_27 ;
struct V_26 V_28 ;
const T_1 * V_29 ;
T_1 V_30 ;
V_27 = F_6 ( V_17 , 0 , sizeof( V_28 ) , & V_28 ) ;
if ( V_27 == NULL ||
V_27 -> V_31 != sizeof( T_1 ) ||
V_27 -> V_32 != V_12 )
return - 1 ;
V_29 = F_6 ( V_17 , sizeof( struct V_26 ) +
2 * V_12 + sizeof( T_1 ) ,
sizeof( T_1 ) , & V_30 ) ;
if ( V_29 == NULL )
return - 1 ;
* V_18 = * V_29 ;
}
return 0 ;
}
static int F_7 ( const struct V_16 * V_17 , T_1 * V_18 )
{
if ( F_4 ( V_17 ) -> V_19 == F_5 ( V_20 ) ) {
const struct V_21 * V_22 ;
struct V_21 V_23 ;
V_22 = F_6 ( V_17 , 0 , sizeof( V_23 ) , & V_23 ) ;
if ( V_22 == NULL )
return - 1 ;
* V_18 = V_22 -> V_33 ;
} else if ( F_4 ( V_17 ) -> V_19 == F_5 ( V_25 ) ) {
const struct V_26 * V_27 ;
struct V_26 V_28 ;
const T_1 * V_29 ;
T_1 V_30 ;
V_27 = F_6 ( V_17 , 0 , sizeof( V_28 ) , & V_28 ) ;
if ( V_27 == NULL ||
V_27 -> V_31 != sizeof( T_1 ) ||
V_27 -> V_32 != V_12 )
return - 1 ;
V_29 = F_6 ( V_17 , sizeof( struct V_26 ) +
V_12 , sizeof( T_1 ) , & V_30 ) ;
if ( V_29 == NULL )
return - 1 ;
* V_18 = * V_29 ;
}
return 0 ;
}
static bool
F_8 ( const struct V_16 * V_17 , struct V_34 * V_35 )
{
const struct V_36 * V_37 = V_35 -> V_38 ;
const char * V_39 , * V_40 ;
const struct V_1 * V_41 , * V_42 ;
T_1 V_43 = 0 , V_44 = 0 ;
V_41 = F_9 ( V_37 ) ;
V_42 = F_10 ( V_37 ) ;
if ( V_42 ) {
V_40 = F_4 ( V_17 ) -> V_45 ;
if ( F_7 ( V_17 , & V_44 ) )
return false ;
if ( ! ( V_37 -> V_46 & V_47 ) ) {
if ( ! F_1 ( V_42 , V_40 , V_44 ) )
return false ;
} else {
if ( F_1 ( V_42 , V_40 , V_44 ) )
return false ;
}
}
if ( V_41 ) {
V_39 = F_4 ( V_17 ) -> V_48 ;
if ( F_3 ( V_17 , & V_43 ) )
return false ;
if ( ! ( V_37 -> V_46 & V_49 ) ) {
if ( ! F_1 ( V_41 , V_39 , V_43 ) )
return false ;
} else {
if ( F_1 ( V_41 , V_39 , V_43 ) )
return false ;
}
}
return true ;
}
static int F_11 ( const struct V_50 * V_35 )
{
const struct V_36 * V_37 = V_35 -> V_38 ;
const struct V_51 * V_52 =
F_12 ( V_35 -> V_38 , const struct V_51 , V_53 ) ;
int V_54 = sizeof( struct V_36 ) ;
const struct V_1 * V_41 , * V_42 ;
int V_55 ;
V_41 = F_9 ( V_37 ) ;
V_42 = F_10 ( V_37 ) ;
V_54 += F_13 ( V_41 ) ;
V_54 += F_13 ( V_42 ) ;
if ( V_52 -> V_56 != F_14 ( V_54 ) ) {
F_15 ( L_1 ,
V_52 -> V_56 , V_54 ,
F_14 ( V_54 ) ) ;
return - V_57 ;
}
if ( V_41 && ( V_55 = F_2 ( V_41 ) ) ) {
F_15 ( L_2 , - V_55 ) ;
return - V_57 ;
}
if ( V_42 && ( V_55 = F_2 ( V_42 ) ) ) {
F_15 ( L_3 , - V_55 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_58 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_58 ) ;
}
