static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_2 , & V_5 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_6 ;
V_6 = F_6 ( & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_7 . V_8 = ( char * ) V_5 . V_9 ;
return F_7 ( & V_7 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_7 ) ;
F_10 ( & V_5 ) ;
}
static int F_11 ( struct V_10 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
int V_16 ;
F_12 ( V_17 L_1 , V_2 -> V_18 ) ;
V_15 = F_13 ( V_2 , sizeof( struct V_19 ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_14 ( V_2 , V_12 -> V_20 [ 0 ] , V_12 -> V_20 [ 1 ] ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_15 ( V_21 -> V_22 ) ;
if ( V_15 < 0 ) {
F_12 ( V_23 L_2 ) ;
return V_15 ;
}
V_2 -> V_24 = V_25 -> V_8 ;
V_2 -> V_26 = F_16 ( V_21 -> V_22 ) ;
F_12 ( V_17 L_3 , V_2 -> V_24 ) ;
if ( F_17 ( V_2 , 2 ) < 0 )
return - V_27 ;
V_14 = V_2 -> V_28 + 0 ;
V_14 -> type = V_29 ;
V_14 -> V_30 = V_31 ;
V_14 -> V_32 = V_25 -> V_33 ;
V_14 -> V_34 = 0xffff ;
if ( V_14 -> V_32 == 32 ) {
const struct V_35 * * V_36 ;
V_36 = F_18 ( sizeof( struct V_35 * ) * 32 ,
V_37 ) ;
if ( ! V_36 )
return - V_27 ;
V_14 -> V_36 = V_36 ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
V_36 [ V_16 ] = & V_38 ;
V_36 [ 16 + V_16 ] = & V_39 ;
}
} else {
V_14 -> V_40 = & V_38 ;
}
V_14 -> V_41 = & V_42 ;
V_14 -> V_43 = & V_44 ;
V_14 = V_2 -> V_28 + 1 ;
V_14 -> type = V_45 ;
V_14 -> V_30 = V_46 | V_31 ;
V_14 -> V_32 = 8 ;
V_14 -> V_34 = 1 ;
V_14 -> V_40 = & V_47 ;
V_14 -> V_48 = V_49 ;
V_14 -> V_50 = V_51 ;
F_19 ( 0x10 , V_21 -> V_22 -> V_52 + V_53 ) ;
F_19 ( 0x00 , V_21 -> V_22 -> V_52 + V_54 ) ;
F_12 ( V_17 L_4 ) ;
return 1 ;
}
static void F_20 ( struct V_10 * V_2 )
{
F_21 ( V_2 -> V_28 [ 0 ] . V_36 ) ;
if ( V_2 -> V_55 && V_21 -> V_22 )
F_22 ( V_21 -> V_22 ) ;
if ( V_2 -> V_26 )
F_23 ( V_2 -> V_26 , V_2 ) ;
}
static int V_42 ( struct V_10 * V_2 ,
struct V_13 * V_14 ,
struct V_56 * V_57 , unsigned int * V_58 )
{
int V_16 ;
int V_59 = F_24 ( V_57 -> V_60 ) ;
for ( V_16 = 0 ; V_16 < V_57 -> V_61 ; V_16 ++ ) {
F_19 ( ( ( V_59 & 15 ) << 1 ) | ( ( V_59 & 16 ) >> 4 ) ,
V_21 -> V_22 -> V_52 + V_62 ) ;
F_19 ( V_58 [ V_16 ] , V_21 -> V_22 -> V_52 + V_63 ) ;
V_21 -> V_64 [ V_59 ] = V_58 [ V_16 ] ;
}
return V_16 ;
}
static int V_44 ( struct V_10 * V_2 ,
struct V_13 * V_14 ,
struct V_56 * V_57 , unsigned int * V_58 )
{
int V_16 ;
int V_59 = F_24 ( V_57 -> V_60 ) ;
for ( V_16 = 0 ; V_16 < V_57 -> V_61 ; V_16 ++ )
V_58 [ V_16 ] = V_21 -> V_64 [ V_59 ] ;
return V_16 ;
}
static int V_49 ( struct V_10 * V_2 ,
struct V_13 * V_14 ,
struct V_56 * V_57 , unsigned int * V_58 )
{
if ( V_57 -> V_61 != 2 )
return - V_65 ;
if ( V_58 [ 0 ] ) {
V_14 -> V_66 &= ~ V_58 [ 0 ] ;
V_14 -> V_66 |= V_58 [ 0 ] & V_58 [ 1 ] ;
F_19 ( V_14 -> V_66 ,
V_21 -> V_22 -> V_52 + V_67 ) ;
}
V_58 [ 1 ] = F_25 ( V_21 -> V_22 -> V_52 + V_67 ) ;
return 2 ;
}
static int V_51 ( struct V_10 * V_2 ,
struct V_13 * V_14 ,
struct V_56 * V_57 , unsigned int * V_58 )
{
int V_59 = F_24 ( V_57 -> V_60 ) ;
switch ( V_58 [ 0 ] ) {
case V_68 :
V_14 -> V_69 |= 1 << V_59 ;
break;
case V_70 :
V_14 -> V_69 &= ~ ( 1 << V_59 ) ;
break;
case V_71 :
V_58 [ 1 ] =
( V_14 -> V_69 & ( 1 << V_59 ) ) ? V_72 : V_73 ;
return V_57 -> V_61 ;
break;
default:
return - V_65 ;
break;
}
F_19 ( V_14 -> V_69 , V_21 -> V_22 -> V_52 + V_74 ) ;
return V_57 -> V_61 ;
}
static int F_14 ( struct V_10 * V_2 , int V_75 , int V_76 )
{
struct V_77 * V_22 ;
int V_16 ;
for ( V_22 = V_78 ; V_22 ; V_22 = V_22 -> V_79 ) {
if ( V_22 -> V_80 )
continue;
if ( V_75 || V_76 ) {
if ( V_75 != V_22 -> V_81 -> V_75 -> V_82
|| V_76 != F_26 ( V_22 -> V_81 -> V_83 ) )
continue;
}
for ( V_16 = 0 ; V_16 < V_84 ; V_16 ++ ) {
if ( F_27 ( V_22 ) == V_85 [ V_16 ] . V_86 ) {
V_2 -> V_87 = V_85 + V_16 ;
V_21 -> V_22 = V_22 ;
return 0 ;
}
}
}
F_12 ( V_17 L_5 ) ;
F_28 () ;
return - V_88 ;
}
