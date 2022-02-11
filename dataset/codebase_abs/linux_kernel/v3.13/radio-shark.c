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
F_14 ( V_34 , & V_5 -> V_25 ) ;
F_15 ( & V_5 -> V_23 ) ;
}
static void F_16 ( struct V_28 * V_29 ,
enum V_30 V_31 )
{
struct V_4 * V_5 = F_8 ( V_29 ,
struct V_4 , V_32 [ V_35 ] ) ;
F_12 ( & V_5 -> V_24 [ V_35 ] , 256 - V_31 ) ;
F_13 ( V_35 , & V_5 -> V_25 ) ;
F_13 ( V_34 , & V_5 -> V_25 ) ;
F_15 ( & V_5 -> V_23 ) ;
}
static void F_17 ( struct V_28 * V_29 ,
enum V_30 V_31 )
{
struct V_4 * V_5 =
F_8 ( V_29 , struct V_4 , V_32 [ V_26 ] ) ;
F_12 ( & V_5 -> V_24 [ V_26 ] , V_31 ) ;
F_13 ( V_26 , & V_5 -> V_25 ) ;
F_15 ( & V_5 -> V_23 ) ;
}
static int F_18 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
int V_7 , V_38 ;
F_12 ( & V_5 -> V_24 [ V_33 ] , 127 ) ;
F_19 ( & V_5 -> V_23 , F_7 ) ;
for ( V_7 = 0 ; V_7 < V_39 ; V_7 ++ ) {
V_5 -> V_32 [ V_7 ] = V_40 [ V_7 ] ;
snprintf ( V_5 -> V_27 [ V_7 ] , sizeof( V_5 -> V_27 [ 0 ] ) ,
V_5 -> V_32 [ V_7 ] . V_41 , V_5 -> V_15 . V_41 ) ;
V_5 -> V_32 [ V_7 ] . V_41 = V_5 -> V_27 [ V_7 ] ;
V_38 = F_20 ( V_37 , & V_5 -> V_32 [ V_7 ] ) ;
if ( V_38 ) {
F_4 ( & V_5 -> V_15 ,
L_5 ,
V_5 -> V_27 [ V_7 ] ) ;
return V_38 ;
}
}
return 0 ;
}
static void F_21 ( struct V_4 * V_5 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_39 ; V_7 ++ )
F_22 ( & V_5 -> V_32 [ V_7 ] ) ;
F_23 ( & V_5 -> V_23 ) ;
}
static inline void F_24 ( struct V_4 * V_5 )
{
if ( F_25 ( V_34 , & V_5 -> V_25 ) )
F_13 ( V_35 , & V_5 -> V_25 ) ;
else
F_13 ( V_33 , & V_5 -> V_25 ) ;
F_13 ( V_26 , & V_5 -> V_25 ) ;
F_15 ( & V_5 -> V_23 ) ;
}
static int F_18 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
F_26 ( & V_5 -> V_15 ,
L_6 ) ;
return 0 ;
}
static inline void F_21 ( struct V_4 * V_5 ) { }
static inline void F_24 ( struct V_4 * V_5 ) { }
static void F_27 ( struct V_42 * V_43 )
{
struct V_44 * V_15 = F_28 ( V_43 ) ;
struct V_4 * V_5 = F_29 ( V_15 ) ;
F_30 ( & V_5 -> V_2 . V_45 ) ;
F_31 ( & V_5 -> V_15 ) ;
F_32 ( & V_5 -> V_2 ) ;
F_33 ( & V_5 -> V_2 . V_45 ) ;
F_21 ( V_5 ) ;
F_34 ( & V_5 -> V_15 ) ;
}
static void F_35 ( struct V_44 * V_15 )
{
struct V_4 * V_5 = F_29 ( V_15 ) ;
F_36 ( & V_5 -> V_15 ) ;
F_37 ( V_5 -> V_11 ) ;
F_37 ( V_5 ) ;
}
static int F_38 ( struct V_42 * V_43 ,
const struct V_46 * V_47 )
{
struct V_4 * V_5 ;
int V_38 = - V_48 ;
V_5 = F_39 ( sizeof( struct V_4 ) , V_49 ) ;
if ( ! V_5 )
return V_38 ;
V_5 -> V_11 = F_40 ( V_12 , V_49 ) ;
if ( ! V_5 -> V_11 )
goto V_50;
F_41 ( & V_5 -> V_15 , V_51 , & V_52 ) ;
V_38 = F_18 ( V_5 , & V_43 -> V_37 ) ;
if ( V_38 )
goto V_53;
V_5 -> V_15 . V_54 = F_35 ;
V_38 = F_42 ( & V_43 -> V_37 , & V_5 -> V_15 ) ;
if ( V_38 ) {
F_4 ( & V_5 -> V_15 , L_7 ) ;
goto V_55;
}
V_5 -> V_13 = F_43 ( V_43 ) ;
V_5 -> V_2 . V_15 = & V_5 -> V_15 ;
V_5 -> V_2 . V_6 = V_5 ;
V_5 -> V_2 . V_56 = - 1 ;
V_5 -> V_2 . V_57 = & V_58 ;
V_5 -> V_2 . V_59 = true ;
V_5 -> V_2 . V_60 = true ;
F_44 ( V_5 -> V_2 . V_61 , L_8 ,
sizeof( V_5 -> V_2 . V_61 ) ) ;
F_45 ( V_5 -> V_13 , V_5 -> V_2 . V_62 ,
sizeof( V_5 -> V_2 . V_62 ) ) ;
V_38 = F_46 ( & V_5 -> V_2 , V_63 ) ;
if ( V_38 ) {
F_4 ( & V_5 -> V_15 , L_9 ) ;
goto V_64;
}
return 0 ;
V_64:
F_36 ( & V_5 -> V_15 ) ;
V_55:
F_21 ( V_5 ) ;
V_53:
F_37 ( V_5 -> V_11 ) ;
V_50:
F_37 ( V_5 ) ;
return V_38 ;
}
static int F_47 ( struct V_42 * V_43 , T_2 V_65 )
{
return 0 ;
}
static int F_48 ( struct V_42 * V_43 )
{
struct V_44 * V_15 = F_28 ( V_43 ) ;
struct V_4 * V_5 = F_29 ( V_15 ) ;
F_30 ( & V_5 -> V_2 . V_45 ) ;
F_49 ( & V_5 -> V_2 ) ;
F_33 ( & V_5 -> V_2 . V_45 ) ;
F_24 ( V_5 ) ;
return 0 ;
}
