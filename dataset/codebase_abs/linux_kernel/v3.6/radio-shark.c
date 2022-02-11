static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 , V_8 , V_9 ;
if ( V_5 -> V_10 == V_3 )
return;
memset ( V_5 -> V_11 , 0 , V_12 ) ;
V_5 -> V_11 [ 0 ] = 0xc0 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_5 -> V_11 [ V_7 ] |= ( V_3 >> ( 24 - V_7 * 8 ) ) & 0xff ;
V_8 = F_2 ( V_5 -> V_13 ,
F_3 ( V_5 -> V_13 , V_14 ) ,
V_5 -> V_11 , V_12 ,
& V_9 , 1000 ) ;
if ( V_8 >= 0 )
V_5 -> V_10 = V_3 ;
else
F_4 ( & V_5 -> V_15 , L_1 , V_8 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 , V_8 , V_9 ;
T_1 V_3 = 0 ;
memset ( V_5 -> V_11 , 0 , V_12 ) ;
V_5 -> V_11 [ 0 ] = 0x80 ;
V_8 = F_2 ( V_5 -> V_13 ,
F_3 ( V_5 -> V_13 , V_14 ) ,
V_5 -> V_11 , V_12 ,
& V_9 , 1000 ) ;
if ( V_8 < 0 ) {
F_4 ( & V_5 -> V_15 , L_2 , V_8 ) ;
return V_5 -> V_10 ;
}
V_8 = F_2 ( V_5 -> V_13 ,
F_6 ( V_5 -> V_13 , V_16 ) ,
V_5 -> V_11 , V_12 ,
& V_9 , 1000 ) ;
if ( V_8 < 0 ) {
F_4 ( & V_5 -> V_15 , L_3 , V_8 ) ;
return V_5 -> V_10 ;
}
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_3 |= V_5 -> V_11 [ V_7 ] << ( 24 - V_7 * 8 ) ;
V_5 -> V_10 = V_3 ;
if ( ( ( V_3 & V_17 ) == V_18 ) &&
! ( V_3 & V_19 ) )
V_5 -> V_2 . V_20 = true ;
else
V_5 -> V_2 . V_20 = false ;
return V_3 ;
}
static void F_7 ( struct V_21 * V_22 )
{
struct V_4 * V_5 =
F_8 ( V_22 , struct V_4 , V_23 ) ;
int V_7 , V_8 , V_24 , V_9 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
if ( ! F_9 ( V_7 , & V_5 -> V_25 ) )
continue;
V_24 = F_10 ( & V_5 -> V_24 [ V_7 ] ) ;
memset ( V_5 -> V_11 , 0 , V_12 ) ;
if ( V_7 != V_26 ) {
V_5 -> V_11 [ 0 ] = 0xA0 + V_7 ;
V_5 -> V_11 [ 1 ] = V_24 ;
} else
V_5 -> V_11 [ 0 ] = V_24 ? 0xA9 : 0xA8 ;
V_8 = F_2 ( V_5 -> V_13 ,
F_3 ( V_5 -> V_13 , 0x05 ) ,
V_5 -> V_11 , V_12 ,
& V_9 , 1000 ) ;
if ( V_8 < 0 )
F_4 ( & V_5 -> V_15 , L_4 ,
V_5 -> V_27 [ V_7 ] , V_8 ) ;
}
}
static void F_11 ( struct V_28 * V_29 ,
enum V_30 V_31 )
{
struct V_4 * V_5 =
F_8 ( V_29 , struct V_4 , V_32 [ V_33 ] ) ;
F_12 ( & V_5 -> V_24 [ V_33 ] , V_31 ) ;
F_13 ( V_33 , & V_5 -> V_25 ) ;
F_14 ( & V_5 -> V_23 ) ;
}
static void F_15 ( struct V_28 * V_29 ,
enum V_30 V_31 )
{
struct V_4 * V_5 = F_8 ( V_29 ,
struct V_4 , V_32 [ V_34 ] ) ;
F_12 ( & V_5 -> V_24 [ V_34 ] , 256 - V_31 ) ;
F_13 ( V_34 , & V_5 -> V_25 ) ;
F_14 ( & V_5 -> V_23 ) ;
}
static void F_16 ( struct V_28 * V_29 ,
enum V_30 V_31 )
{
struct V_4 * V_5 =
F_8 ( V_29 , struct V_4 , V_32 [ V_26 ] ) ;
F_12 ( & V_5 -> V_24 [ V_26 ] , V_31 ) ;
F_13 ( V_26 , & V_5 -> V_25 ) ;
F_14 ( & V_5 -> V_23 ) ;
}
static int F_17 ( struct V_4 * V_5 , struct V_35 * V_36 )
{
int V_7 , V_37 ;
F_18 ( & V_5 -> V_23 , F_7 ) ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
V_5 -> V_32 [ V_7 ] = V_39 [ V_7 ] ;
snprintf ( V_5 -> V_27 [ V_7 ] , sizeof( V_5 -> V_27 [ 0 ] ) ,
V_5 -> V_32 [ V_7 ] . V_40 , V_5 -> V_15 . V_40 ) ;
V_5 -> V_32 [ V_7 ] . V_40 = V_5 -> V_27 [ V_7 ] ;
V_37 = F_19 ( V_36 , & V_5 -> V_32 [ V_7 ] ) ;
if ( V_37 ) {
F_4 ( & V_5 -> V_15 ,
L_5 ,
V_5 -> V_27 [ V_7 ] ) ;
return V_37 ;
}
}
return 0 ;
}
static void F_20 ( struct V_4 * V_5 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ )
F_21 ( & V_5 -> V_32 [ V_7 ] ) ;
F_22 ( & V_5 -> V_23 ) ;
}
static int F_17 ( struct V_4 * V_5 , struct V_35 * V_36 )
{
F_23 ( & V_5 -> V_15 ,
L_6 ) ;
return 0 ;
}
static inline void F_20 ( struct V_4 * V_5 ) { }
static void F_24 ( struct V_41 * V_42 )
{
struct V_43 * V_15 = F_25 ( V_42 ) ;
struct V_4 * V_5 = F_26 ( V_15 ) ;
F_27 ( & V_5 -> V_2 . V_44 ) ;
F_28 ( & V_5 -> V_15 ) ;
F_29 ( & V_5 -> V_2 ) ;
F_30 ( & V_5 -> V_2 . V_44 ) ;
F_20 ( V_5 ) ;
F_31 ( & V_5 -> V_15 ) ;
}
static void F_32 ( struct V_43 * V_15 )
{
struct V_4 * V_5 = F_26 ( V_15 ) ;
F_33 ( & V_5 -> V_15 ) ;
F_34 ( V_5 -> V_11 ) ;
F_34 ( V_5 ) ;
}
static int F_35 ( struct V_41 * V_42 ,
const struct V_45 * V_46 )
{
struct V_4 * V_5 ;
int V_37 = - V_47 ;
V_5 = F_36 ( sizeof( struct V_4 ) , V_48 ) ;
if ( ! V_5 )
return V_37 ;
V_5 -> V_11 = F_37 ( V_12 , V_48 ) ;
if ( ! V_5 -> V_11 )
goto V_49;
F_38 ( & V_5 -> V_15 , V_50 , & V_51 ) ;
V_37 = F_17 ( V_5 , & V_42 -> V_36 ) ;
if ( V_37 )
goto V_52;
V_5 -> V_15 . V_53 = F_32 ;
V_37 = F_39 ( & V_42 -> V_36 , & V_5 -> V_15 ) ;
if ( V_37 ) {
F_4 ( & V_5 -> V_15 , L_7 ) ;
goto V_54;
}
V_5 -> V_13 = F_40 ( V_42 ) ;
V_5 -> V_2 . V_15 = & V_5 -> V_15 ;
V_5 -> V_2 . V_6 = V_5 ;
V_5 -> V_2 . V_55 = - 1 ;
V_5 -> V_2 . V_56 = & V_57 ;
V_5 -> V_2 . V_58 = true ;
F_41 ( V_5 -> V_2 . V_59 , L_8 ,
sizeof( V_5 -> V_2 . V_59 ) ) ;
F_42 ( V_5 -> V_13 , V_5 -> V_2 . V_60 ,
sizeof( V_5 -> V_2 . V_60 ) ) ;
V_37 = F_43 ( & V_5 -> V_2 , V_61 ) ;
if ( V_37 ) {
F_4 ( & V_5 -> V_15 , L_9 ) ;
goto V_62;
}
return 0 ;
V_62:
F_33 ( & V_5 -> V_15 ) ;
V_54:
F_20 ( V_5 ) ;
V_52:
F_34 ( V_5 -> V_11 ) ;
V_49:
F_34 ( V_5 ) ;
return V_37 ;
}
