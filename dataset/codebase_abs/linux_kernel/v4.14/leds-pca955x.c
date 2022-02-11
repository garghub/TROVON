static inline int F_1 ( int V_1 )
{
return ( V_1 + 7 ) / 8 ;
}
static inline int F_2 ( int V_1 )
{
return ( V_1 + 3 ) / 4 ;
}
static inline T_1 F_3 ( T_1 V_2 , int V_3 , int V_4 )
{
return ( V_2 & ( ~ ( 0x3 << ( V_3 << 1 ) ) ) ) |
( ( V_4 & 0x3 ) << ( V_3 << 1 ) ) ;
}
static int F_4 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
int V_10 ;
V_10 = F_6 ( V_6 ,
F_1 ( V_9 -> V_11 -> V_1 ) + 2 * V_7 ,
V_8 ) ;
if ( V_10 < 0 )
F_7 ( & V_6 -> V_12 , L_1 ,
V_13 , V_7 , V_8 , V_10 ) ;
return V_10 ;
}
static int F_8 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
int V_10 ;
V_10 = F_6 ( V_6 ,
F_1 ( V_9 -> V_11 -> V_1 ) + 1 + 2 * V_7 ,
V_8 ) ;
if ( V_10 < 0 )
F_7 ( & V_6 -> V_12 , L_1 ,
V_13 , V_7 , V_8 , V_10 ) ;
return V_10 ;
}
static int F_9 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
int V_10 ;
V_10 = F_6 ( V_6 ,
F_1 ( V_9 -> V_11 -> V_1 ) + 4 + V_7 ,
V_8 ) ;
if ( V_10 < 0 )
F_7 ( & V_6 -> V_12 , L_1 ,
V_13 , V_7 , V_8 , V_10 ) ;
return V_10 ;
}
static int F_10 ( struct V_5 * V_6 , int V_7 , T_1 * V_8 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
int V_10 ;
V_10 = F_11 ( V_6 ,
F_1 ( V_9 -> V_11 -> V_1 ) + 4 + V_7 ) ;
if ( V_10 < 0 ) {
F_7 ( & V_6 -> V_12 , L_2 ,
V_13 , V_7 , V_10 ) ;
return V_10 ;
}
* V_8 = ( T_1 ) V_10 ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
enum V_16 V_17 )
{
struct V_18 * V_18 ;
struct V_9 * V_9 ;
T_1 V_19 ;
int V_20 ;
int V_21 ;
int V_10 ;
V_18 = F_13 ( V_15 , struct V_18 , V_15 ) ;
V_9 = V_18 -> V_9 ;
V_20 = V_18 -> V_3 / 4 ;
V_21 = V_18 -> V_3 % 4 ;
F_14 ( & V_9 -> V_22 ) ;
V_10 = F_10 ( V_9 -> V_6 , V_20 , & V_19 ) ;
if ( V_10 )
goto V_23;
switch ( V_17 ) {
case V_24 :
V_19 = F_3 ( V_19 , V_21 , V_25 ) ;
break;
case V_26 :
V_19 = F_3 ( V_19 , V_21 , V_27 ) ;
break;
case V_28 :
V_19 = F_3 ( V_19 , V_21 , V_29 ) ;
break;
default:
V_10 = F_8 ( V_9 -> V_6 , 1 , 255 - V_17 ) ;
if ( V_10 )
goto V_23;
V_19 = F_3 ( V_19 , V_21 , V_30 ) ;
break;
}
V_10 = F_9 ( V_9 -> V_6 , V_20 , V_19 ) ;
V_23:
F_15 ( & V_9 -> V_22 ) ;
return V_10 ;
}
static int F_16 ( struct V_5 * V_6 , int V_7 , T_1 * V_8 )
{
int V_10 = F_11 ( V_6 , V_7 ) ;
if ( V_10 < 0 ) {
F_7 ( & V_6 -> V_12 , L_2 ,
V_13 , V_7 , V_10 ) ;
return V_10 ;
}
* V_8 = ( T_1 ) V_10 ;
return 0 ;
}
static int F_17 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_9 * V_9 = F_18 ( V_32 ) ;
struct V_18 * V_34 = & V_9 -> V_35 [ V_33 ] ;
if ( V_34 -> type == V_36 )
return 0 ;
return - V_37 ;
}
static int F_19 ( struct V_31 * V_32 , unsigned int V_33 ,
int V_8 )
{
struct V_9 * V_9 = F_18 ( V_32 ) ;
struct V_18 * V_34 = & V_9 -> V_35 [ V_33 ] ;
if ( V_8 )
return F_12 ( & V_34 -> V_15 , V_24 ) ;
else
return F_12 ( & V_34 -> V_15 , V_26 ) ;
}
static void F_20 ( struct V_31 * V_32 , unsigned int V_33 ,
int V_8 )
{
F_19 ( V_32 , V_33 , V_8 ) ;
}
static int F_21 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_9 * V_9 = F_18 ( V_32 ) ;
struct V_18 * V_34 = & V_9 -> V_35 [ V_33 ] ;
T_1 V_38 = 0 ;
F_16 ( V_9 -> V_6 , V_34 -> V_3 / 8 , & V_38 ) ;
return ! ! ( V_38 & ( 1 << ( V_34 -> V_3 % 8 ) ) ) ;
}
static int F_22 ( struct V_31 * V_32 ,
unsigned int V_33 )
{
return F_19 ( V_32 , V_33 , 0 ) ;
}
static int F_23 ( struct V_31 * V_32 ,
unsigned int V_33 , int V_8 )
{
return F_19 ( V_32 , V_33 , V_8 ) ;
}
static struct V_39 *
F_24 ( struct V_5 * V_6 , struct V_40 * V_41 )
{
struct V_42 * V_43 = V_6 -> V_12 . V_44 ;
struct V_42 * V_45 ;
struct V_39 * V_46 ;
int V_47 ;
V_47 = F_25 ( V_43 ) ;
if ( ! V_47 || V_47 > V_41 -> V_1 )
return F_26 ( - V_48 ) ;
V_46 = F_27 ( & V_6 -> V_12 , sizeof( * V_46 ) , V_49 ) ;
if ( ! V_46 )
return F_26 ( - V_50 ) ;
V_46 -> V_35 = F_27 ( & V_6 -> V_12 ,
sizeof( struct V_18 ) * V_41 -> V_1 ,
V_49 ) ;
if ( ! V_46 -> V_35 )
return F_26 ( - V_50 ) ;
F_28 (np, child) {
const char * V_51 ;
T_2 V_38 ;
int V_52 ;
V_52 = F_29 ( V_45 , L_3 , & V_38 ) ;
if ( ( V_52 != 0 ) || ( V_38 >= V_41 -> V_1 ) )
continue;
if ( F_30 ( V_45 , L_4 , & V_51 ) )
V_51 = V_45 -> V_51 ;
snprintf ( V_46 -> V_35 [ V_38 ] . V_51 , sizeof( V_46 -> V_35 [ V_38 ] . V_51 ) ,
L_5 , V_51 ) ;
V_46 -> V_35 [ V_38 ] . type = V_53 ;
F_29 ( V_45 , L_6 , & V_46 -> V_35 [ V_38 ] . type ) ;
F_30 ( V_45 , L_7 ,
& V_46 -> V_35 [ V_38 ] . V_54 ) ;
}
V_46 -> V_55 = V_41 -> V_1 ;
return V_46 ;
}
static struct V_39 *
F_24 ( struct V_5 * V_6 , struct V_40 * V_41 )
{
return F_26 ( - V_48 ) ;
}
static int F_31 ( struct V_5 * V_6 ,
const struct V_56 * V_57 )
{
struct V_9 * V_9 ;
struct V_18 * V_18 ;
struct V_40 * V_41 ;
struct V_58 * V_59 ;
int V_60 , V_61 ;
struct V_39 * V_46 ;
int V_62 = 0 ;
if ( V_57 ) {
V_41 = & V_63 [ V_57 -> V_64 ] ;
} else {
const struct V_65 * V_66 ;
V_66 = F_32 ( V_67 , & V_6 -> V_12 ) ;
if ( ! V_66 )
return - V_48 ;
V_41 = & V_63 [ V_66 -> V_64 ] ;
}
V_59 = F_33 ( V_6 -> V_12 . V_68 ) ;
V_46 = F_34 ( & V_6 -> V_12 ) ;
if ( ! V_46 ) {
V_46 = F_24 ( V_6 , V_41 ) ;
if ( F_35 ( V_46 ) )
return F_36 ( V_46 ) ;
}
if ( ( V_6 -> V_69 & ~ ( ( 1 << V_41 -> V_70 ) - 1 ) ) !=
V_41 -> V_71 ) {
F_7 ( & V_6 -> V_12 , L_8 ,
V_6 -> V_69 ) ;
return - V_48 ;
}
F_37 ( & V_6 -> V_12 , L_9
L_10 ,
V_6 -> V_51 , V_41 -> V_1 , V_6 -> V_69 ) ;
if ( ! F_38 ( V_59 , V_72 ) )
return - V_73 ;
if ( V_46 -> V_55 != V_41 -> V_1 ) {
F_7 ( & V_6 -> V_12 ,
L_11 ,
V_46 -> V_55 , V_41 -> V_1 ) ;
return - V_48 ;
}
V_9 = F_27 ( & V_6 -> V_12 , sizeof( * V_9 ) , V_49 ) ;
if ( ! V_9 )
return - V_50 ;
V_9 -> V_35 = F_27 ( & V_6 -> V_12 ,
sizeof( * V_18 ) * V_41 -> V_1 , V_49 ) ;
if ( ! V_9 -> V_35 )
return - V_50 ;
F_39 ( V_6 , V_9 ) ;
F_40 ( & V_9 -> V_22 ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_11 = V_41 ;
for ( V_60 = 0 ; V_60 < V_41 -> V_1 ; V_60 ++ ) {
V_18 = & V_9 -> V_35 [ V_60 ] ;
V_18 -> V_3 = V_60 ;
V_18 -> V_9 = V_9 ;
V_18 -> type = V_46 -> V_35 [ V_60 ] . type ;
switch ( V_18 -> type ) {
case V_74 :
break;
case V_36 :
V_62 ++ ;
break;
case V_53 :
if ( V_46 -> V_35 [ V_60 ] . V_51 [ 0 ] == '\0' )
snprintf ( V_46 -> V_35 [ V_60 ] . V_51 ,
sizeof( V_46 -> V_35 [ V_60 ] . V_51 ) , L_12 , V_60 ) ;
snprintf ( V_18 -> V_51 ,
sizeof( V_18 -> V_51 ) , L_13 ,
V_46 -> V_35 [ V_60 ] . V_51 ) ;
if ( V_46 -> V_35 [ V_60 ] . V_54 )
V_18 -> V_15 . V_54 =
V_46 -> V_35 [ V_60 ] . V_54 ;
V_18 -> V_15 . V_51 = V_18 -> V_51 ;
V_18 -> V_15 . V_75 =
F_12 ;
V_61 = F_41 ( & V_6 -> V_12 ,
& V_18 -> V_15 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_12 ( & V_18 -> V_15 , V_26 ) ;
if ( V_61 )
return V_61 ;
}
}
V_61 = F_8 ( V_6 , 0 , 255 - V_28 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_8 ( V_6 , 1 , 0 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_4 ( V_6 , 0 , 0 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_4 ( V_6 , 1 , 0 ) ;
if ( V_61 )
return V_61 ;
#ifdef F_42
if ( V_62 ) {
V_9 -> V_76 . V_77 = L_14 ;
V_9 -> V_76 . V_78 = F_22 ;
V_9 -> V_76 . V_79 = F_23 ;
V_9 -> V_76 . V_80 = F_20 ;
V_9 -> V_76 . V_81 = F_21 ;
V_9 -> V_76 . V_82 = F_17 ;
V_9 -> V_76 . V_83 = 1 ;
V_9 -> V_76 . V_84 = - 1 ;
V_9 -> V_76 . V_85 = V_62 ;
V_9 -> V_76 . V_68 = & V_6 -> V_12 ;
V_9 -> V_76 . V_86 = V_87 ;
V_61 = F_43 ( & V_6 -> V_12 , & V_9 -> V_76 ,
V_9 ) ;
if ( V_61 ) {
V_9 -> V_76 . V_68 = NULL ;
F_44 ( & V_6 -> V_12 , L_15 ) ;
return V_61 ;
}
F_37 ( & V_6 -> V_12 , L_16 ,
V_9 -> V_76 . V_84 , V_9 -> V_76 . V_84 +
V_9 -> V_76 . V_85 - 1 ) ;
}
#endif
return 0 ;
}
