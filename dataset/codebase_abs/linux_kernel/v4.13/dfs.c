static inline int F_1 ( T_1 * V_1 )
{
return ( V_1 [ 2 ] & 0xfc ) >> 2 ;
}
static inline int F_2 ( T_1 * V_1 )
{
return ( V_1 [ 0 ] & 0xc0 ) >> 6 | V_1 [ 1 ] << 2 | ( V_1 [ 2 ] & 0x03 ) << 10 ;
}
static inline T_1 F_3 ( T_1 * V_1 )
{
return V_1 [ 0 ] & 0x3f ;
}
static int F_4 ( struct V_2 * V_3 ,
bool V_4 , bool V_5 )
{
const int V_6 = 64 ;
if ( V_4 && V_5 ) {
V_4 = F_3 ( V_3 -> V_7 ) != 0 ;
V_5 = F_3 ( V_3 -> V_8 ) != 0 ;
if ( V_4 && V_5 ) {
int V_9 = F_2 ( V_3 -> V_7 ) ;
int V_10 = F_2 ( V_3 -> V_8 ) ;
if ( V_10 > V_9 )
V_4 = false ;
else
V_5 = false ;
}
}
if ( V_4 )
return F_1 ( V_3 -> V_7 ) ;
return F_1 ( V_3 -> V_8 ) + V_6 ;
}
static bool F_5 ( struct V_11 * V_12 , T_1 * V_13 ,
int V_14 , bool V_4 , bool V_5 )
{
int V_15 ;
int V_16 [ V_17 ] ;
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_21 * V_22 = F_6 ( V_19 ) ;
int V_23 ;
if ( F_7 ( V_19 -> V_24 ) ) {
struct V_2 * V_3 = (struct V_2 * ) V_13 ;
int V_25 = V_14 / sizeof( * V_3 ) ;
if ( V_25 == 0 )
return false ;
F_8 ( V_22 , V_26 , L_1 ,
V_14 , V_25 ) ;
if ( V_25 < ( V_17 ) ) {
F_8 ( V_22 , V_26 , L_2 ) ;
return false ;
}
if ( ( V_14 % sizeof( * V_3 ) ) == 2 ) {
V_3 = (struct V_2 * ) ( V_13 + 2 ) ;
F_8 ( V_22 , V_26 , L_3 ) ;
}
if ( F_9 ( V_19 -> V_24 ) ) {
int V_27 = V_4 ;
V_4 = V_5 ;
V_5 = V_27 ;
}
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ )
V_16 [ V_15 ] = F_4 ( V_3 + V_15 , V_4 ,
V_5 ) ;
} else {
struct V_28 * V_3 = (struct V_28 * ) V_13 ;
int V_25 = V_14 / sizeof( * V_3 ) ;
if ( V_25 == 0 )
return false ;
F_8 ( V_22 , V_26 , L_4 ,
V_14 , V_25 ) ;
if ( V_25 < ( V_17 ) ) {
F_8 ( V_22 , V_26 , L_2 ) ;
return false ;
}
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ )
V_16 [ V_15 ] = F_1 ( V_3 [ V_15 ] . V_7 ) ^ 0x20 ;
}
F_8 ( V_22 , V_26 , L_5 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] ) ;
V_23 = 0 ;
for ( V_15 = 0 ; V_15 < V_29 ; V_15 ++ ) {
int V_30 = - 1 ;
int V_31 = V_16 [ V_15 + 1 ] - V_16 [ V_15 ] ;
if ( abs ( V_31 ) < V_32 || abs ( V_31 ) > V_33 ) {
F_8 ( V_22 , V_26 , L_6
L_7 , V_31 , V_15 ) ;
return false ;
}
if ( V_15 == 0 )
goto V_34;
V_30 = V_31 - V_23 ;
if ( abs ( V_30 ) > V_35 ) {
F_8 ( V_22 , V_26 , L_8 ,
V_30 ) ;
return false ;
}
V_34:
F_8 ( V_22 , V_26 , L_9 ,
V_15 , V_31 , V_30 ) ;
V_23 = V_31 ;
}
return true ;
}
static T_2 F_10 ( struct V_18 * V_19 , T_2 V_36 )
{
const T_2 V_37 = 800 ;
const T_2 V_38 = ( 8000 / 11 ) ;
T_2 V_39 ;
if ( F_11 ( V_19 , V_19 -> V_24 ) )
V_39 = V_36 * V_38 ;
else
V_39 = V_36 * V_37 ;
return ( V_39 + 500 ) / 1000 ;
}
static bool
F_12 ( struct V_11 * V_12 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
T_1 V_44 ;
T_3 V_36 ;
V_41 -> V_45 &= 0x03 ;
switch ( V_41 -> V_45 ) {
case V_46 :
V_36 = V_41 -> V_47 ;
F_13 ( V_12 , V_48 ) ;
V_44 = ( V_41 -> V_49 >= ( V_41 -> V_44 + 3 ) ) ? 0 : V_41 -> V_44 ;
break;
case V_50 :
V_36 = V_41 -> V_51 ;
F_13 ( V_12 , V_52 ) ;
V_44 = ( V_41 -> V_44 >= ( V_41 -> V_49 + 12 ) ) ? 0 : V_41 -> V_49 ;
break;
case ( V_46 | V_50 ) :
if ( V_41 -> V_51 >= V_41 -> V_47 )
V_36 = V_41 -> V_51 ;
else
V_36 = V_41 -> V_47 ;
F_13 ( V_12 , V_53 ) ;
V_44 = ( V_41 -> V_44 < V_41 -> V_49 ) ? V_41 -> V_49 : V_41 -> V_44 ;
break;
default:
F_13 ( V_12 , V_54 ) ;
return false ;
}
if ( V_44 == 0 ) {
F_13 ( V_12 , V_55 ) ;
return false ;
}
V_43 -> V_56 = F_10 ( V_12 -> V_20 , V_36 ) ;
V_43 -> V_44 = V_44 ;
F_13 ( V_12 , V_57 ) ;
return true ;
}
static void
F_14 ( struct V_11 * V_12 , struct V_42 * V_43 )
{
struct V_58 * V_59 = V_12 -> V_60 ;
F_13 ( V_12 , V_61 ) ;
if ( V_59 == NULL )
return;
if ( ! V_59 -> V_62 ( V_59 , V_43 ) )
return;
F_13 ( V_12 , V_63 ) ;
F_15 ( V_12 -> V_64 ) ;
}
void F_16 ( struct V_11 * V_12 , void * V_13 ,
struct V_65 * V_66 , T_4 V_67 )
{
struct V_40 V_41 ;
T_3 V_14 ;
char * V_68 ;
struct V_42 V_43 ;
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_21 * V_22 = F_6 ( V_19 ) ;
F_13 ( V_12 , V_69 ) ;
if ( ( V_66 -> V_70 != V_71 ) &&
( V_66 -> V_70 != V_72 ) ) {
F_8 ( V_22 , V_26 ,
L_10 ,
V_66 -> V_70 ) ;
F_13 ( V_12 , V_73 ) ;
return;
}
V_14 = V_66 -> V_74 ;
if ( V_14 == 0 ) {
F_13 ( V_12 , V_75 ) ;
return;
}
V_41 . V_44 = V_66 -> V_76 [ 0 ] ;
V_41 . V_49 = V_66 -> V_77 [ 0 ] ;
if ( V_41 . V_44 & 0x80 )
V_41 . V_44 = 0 ;
if ( V_41 . V_49 & 0x80 )
V_41 . V_49 = 0 ;
V_68 = ( char * ) V_13 + V_14 ;
V_41 . V_45 = V_68 [ - 1 ] ;
V_41 . V_51 = V_68 [ - 2 ] ;
V_41 . V_47 = V_68 [ - 3 ] ;
V_43 . V_78 = V_19 -> V_24 -> V_79 ;
V_43 . V_80 = V_67 ;
if ( ! F_12 ( V_12 , & V_41 , & V_43 ) )
return;
if ( V_43 . V_56 > V_81 &&
V_43 . V_56 < V_82 ) {
bool V_4 = ! ! ( V_41 . V_45 & V_46 ) ;
bool V_5 = ! ! ( V_41 . V_45 & V_50 ) ;
int V_83 = V_14 - 3 ;
V_43 . V_84 = F_5 ( V_12 , V_13 , V_83 , V_4 , V_5 ) ;
} else {
V_43 . V_84 = false ;
}
F_8 ( V_22 , V_26 ,
L_11
L_12 ,
V_41 . V_45 , V_43 . V_78 , V_43 . V_80 , V_43 . V_56 , V_43 . V_44 ,
V_43 . V_80 - V_12 -> V_85 ) ;
V_12 -> V_85 = V_43 . V_80 ;
if ( V_41 . V_45 & V_46 )
F_14 ( V_12 , & V_43 ) ;
if ( F_7 ( V_19 -> V_24 ) &&
V_41 . V_45 & V_50 ) {
V_43 . V_78 += F_17 ( V_19 -> V_24 ) ? 20 : - 20 ;
F_14 ( V_12 , & V_43 ) ;
}
}
