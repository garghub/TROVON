static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 ,
enum V_8 V_9 , int * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_2 -> V_13 ;
struct V_14 * V_15 = (struct V_14 * ) V_2 -> V_13 ;
int V_16 ;
unsigned int V_17 ;
unsigned int V_18 ;
unsigned int V_19 = V_20 ;
V_12 -> V_21 = F_2 ( V_22 ) ;
V_12 -> V_23 = F_2 ( V_7 ) ;
V_12 -> V_24 = ( V_9 == V_25 ) ? 1 << 7 : 0 ;
V_12 -> V_26 = ++ V_2 -> V_27 ;
V_12 -> V_28 = V_3 ;
V_12 -> V_29 = V_5 ;
memset ( V_12 -> V_30 , 0 , sizeof( V_12 -> V_30 ) ) ;
memcpy ( V_12 -> V_30 , V_4 , V_12 -> V_29 ) ;
V_16 = F_3 ( V_2 , V_2 -> V_31 ,
V_12 , V_19 , NULL ) ;
if ( V_16 != V_32 )
return V_33 ;
if ( V_6 && V_7 ) {
unsigned int V_34 = ( V_9 == V_25 ) ?
V_2 -> V_35 : V_2 -> V_31 ;
V_16 = F_3 ( V_2 , V_34 ,
V_6 , V_7 , NULL ) ;
if ( V_16 == V_36 )
return V_33 ;
}
V_16 = F_3 ( V_2 , V_2 -> V_35 ,
V_15 , V_37 , & V_18 ) ;
if ( V_16 != V_32 )
return V_33 ;
if ( V_15 -> V_21 != F_2 ( V_38 ) ) {
F_4 ( L_1 ,
F_5 ( V_15 -> V_21 ) ,
V_38 ) ;
return V_33 ;
}
V_17 = V_15 -> V_39 ;
if ( V_15 -> V_26 != V_2 -> V_27 )
return V_33 ;
if ( V_17 )
V_17 = V_17 < V_7 ? V_17 : V_7 ;
if ( V_10 )
* V_10 = V_7 - V_17 ;
switch ( V_15 -> V_40 ) {
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
case V_45 :
return V_33 ;
}
return V_33 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_16 ;
V_2 -> V_13 [ 0 ] = 0 ;
V_16 = F_7 ( V_2 , V_2 -> V_46 ,
V_47 ,
V_48 | V_49 |
V_50 ,
0 , V_2 -> V_51 , V_2 -> V_13 , 1 , 10 * V_52 ) ;
F_4 ( L_2 ,
V_16 , V_2 -> V_13 [ 0 ] ) ;
if ( V_16 > 0 )
return V_2 -> V_13 [ 0 ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_53 , T_1 * V_54 , T_2 V_55 )
{
int V_56 ;
T_1 V_57 [ 12 ] = { 0 } ;
F_4 ( L_3 , V_58 , V_53 , V_55 ) ;
V_57 [ 0 ] = 0xF0 ;
V_57 [ 1 ] = 0x0D ;
V_57 [ 2 ] = ( T_1 ) ( V_53 >> 8 ) ;
V_57 [ 3 ] = ( T_1 ) V_53 ;
V_57 [ 4 ] = ( T_1 ) ( V_55 >> 8 ) ;
V_57 [ 5 ] = ( T_1 ) V_55 ;
V_56 = F_1 ( V_2 , 0 , V_57 , 12 ,
V_54 , V_55 , V_25 , NULL ) ;
if ( V_56 != V_42 )
return - V_59 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_53 , T_1 * V_54 , T_2 V_55 )
{
int V_56 ;
T_1 V_57 [ 12 ] = { 0 } ;
F_4 ( L_3 , V_58 , V_53 , V_55 ) ;
V_57 [ 0 ] = 0xF0 ;
V_57 [ 1 ] = 0x0E ;
V_57 [ 2 ] = ( T_1 ) ( V_53 >> 8 ) ;
V_57 [ 3 ] = ( T_1 ) V_53 ;
V_57 [ 4 ] = ( T_1 ) ( V_55 >> 8 ) ;
V_57 [ 5 ] = ( T_1 ) V_55 ;
V_56 = F_1 ( V_2 , 0 , V_57 , 12 ,
V_54 , V_55 , V_60 , NULL ) ;
if ( V_56 != V_42 )
return - V_59 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_61 , int V_55 , int * V_62 )
{
int V_56 ;
T_1 V_57 [ 12 ] = { 0 } ;
F_4 ( L_4 , V_58 , V_3 ) ;
V_57 [ 0 ] = 0xF0 ;
V_57 [ 1 ] = 0x09 ;
V_56 = F_1 ( V_2 , V_3 , V_57 , 12 ,
V_61 , V_55 , V_25 , V_62 ) ;
if ( V_56 != V_42 )
return - V_59 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
int V_56 ;
T_1 V_6 [ 16 ] ;
V_56 = F_10 ( V_2 , V_3 , V_6 , 16 , & ( V_64 -> V_66 ) ) ;
if ( V_56 < 0 )
return - V_59 ;
F_4 ( L_5 , V_64 -> V_66 ) ;
V_64 -> V_61 [ V_3 ] . V_67 = ( ( T_2 ) V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
V_64 -> V_61 [ V_3 ] . V_68 = ( ( T_2 ) V_6 [ 2 ] << 8 ) | V_6 [ 3 ] ;
V_64 -> V_61 [ V_3 ] . V_69 = V_6 [ 4 ] ;
V_64 -> V_61 [ V_3 ] . V_70 = V_6 [ 5 ] ;
V_64 -> V_61 [ V_3 ] . V_71 = V_6 [ 6 ] ;
V_64 -> V_61 [ V_3 ] . V_72 = ( ( T_2 ) V_6 [ 7 ] << 8 ) | V_6 [ 8 ] ;
V_64 -> V_61 [ V_3 ] . V_73 = V_6 [ 9 ] ;
V_64 -> V_61 [ V_3 ] . V_74 = V_6 [ 10 ] ;
V_64 -> V_61 [ V_3 ] . V_75 = V_6 [ 11 ] ;
V_64 -> V_61 [ V_3 ] . V_76 = V_6 [ 12 ] ;
if ( V_64 -> V_66 == 16 ) {
V_64 -> V_61 [ V_3 ] . V_77 . V_78 = V_6 [ 13 ] ;
V_64 -> V_61 [ V_3 ] . V_79 [ 0 ] = V_6 [ 14 ] ;
V_64 -> V_61 [ V_3 ] . V_79 [ 1 ] = V_6 [ 15 ] ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_56 ;
T_1 V_80 ;
V_56 = F_8 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
V_80 |= 0x04 ;
V_56 = F_9 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
V_56 = F_8 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( ! ( V_80 & 0x04 ) )
return - V_59 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_81 , int V_82 )
{
int V_56 ;
T_1 V_80 ;
V_56 = F_8 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( V_81 ) {
if ( V_82 )
V_80 |= 0x03 ;
else
V_80 |= 0x01 ;
} else {
V_80 &= ~ 0x03 ;
}
F_4 ( L_6 , V_58 , V_80 ) ;
V_56 = F_9 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
int V_56 ;
T_1 V_80 ;
if ( ! F_15 ( V_64 ) )
return 0 ;
V_56 = F_8 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( V_83 ) {
F_16 ( V_80 , 0 ) ;
F_16 ( V_80 , 1 ) ;
F_17 ( V_80 , 2 ) ;
if ( F_18 ( V_64 , 0x0138 , 0x3882 ) )
F_16 ( V_80 , 2 ) ;
F_17 ( V_80 , 7 ) ;
V_56 = F_9 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
V_56 = F_12 ( V_2 ) ;
if ( V_56 == 0 )
( void ) F_13 ( V_2 , 1 , 0 ) ;
} else {
F_17 ( V_80 , 2 ) ;
if ( F_18 ( V_64 , 0x0138 , 0x3882 ) )
F_16 ( V_80 , 2 ) ;
if ( F_18 ( V_64 , 0x0159 , 0x5889 ) ||
F_18 ( V_64 , 0x0138 , 0x3880 ) ) {
F_16 ( V_80 , 0 ) ;
F_16 ( V_80 , 7 ) ;
}
V_56 = F_9 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( F_18 ( V_64 , 0x0159 , 0x5888 ) ) {
V_80 = 0xFF ;
V_56 = F_9 ( V_2 , 0xFE79 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
V_80 = 0x01 ;
V_56 = F_9 ( V_2 , 0x48 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_65 ) ;
int V_56 ;
T_1 V_80 ;
if ( ! F_15 ( V_64 ) )
return 0 ;
if ( V_83 ) {
V_56 = F_8 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
F_17 ( V_80 , 2 ) ;
V_56 = F_9 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( F_18 ( V_64 , 0x0159 , 0x5888 ) ) {
V_80 = 0x01 ;
V_56 = F_9 ( V_2 , 0x48 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
}
V_56 = F_8 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
F_17 ( V_80 , 0 ) ;
if ( F_18 ( V_64 , 0x0138 , 0x3882 ) )
F_17 ( V_80 , 2 ) ;
V_56 = F_9 ( V_2 , 0xFE77 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
} else {
if ( F_18 ( V_64 , 0x0159 , 0x5889 ) ||
F_18 ( V_64 , 0x0138 , 0x3880 ) ||
F_18 ( V_64 , 0x0138 , 0x3882 ) ) {
V_56 = F_8 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
if ( F_18 ( V_64 , 0x0159 , 0x5889 ) ||
F_18 ( V_64 , 0x0138 , 0x3880 ) ) {
F_17 ( V_80 , 0 ) ;
F_17 ( V_80 , 7 ) ;
}
if ( F_18 ( V_64 , 0x0138 , 0x3882 ) )
F_17 ( V_80 , 2 ) ;
V_56 = F_9 ( V_2 , 0xFE47 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
}
if ( F_18 ( V_64 , 0x0159 , 0x5888 ) ) {
V_80 = 0x01 ;
V_56 = F_9 ( V_2 , 0x48 , & V_80 , 1 ) ;
if ( V_56 < 0 )
return - V_59 ;
}
}
return 0 ;
}
static void F_20 ( void * V_65 )
{
struct V_63 * V_64 = (struct V_63 * ) V_65 ;
if ( ! V_64 )
return;
F_21 ( V_64 -> V_61 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_84 )
{
if ( V_84 == V_85 )
( void ) F_19 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
int V_86 , V_87 , V_56 ;
V_64 = F_24 ( sizeof( struct V_63 ) , V_88 ) ;
if ( ! V_64 )
return - V_89 ;
V_2 -> V_65 = V_64 ;
V_2 -> V_90 = F_20 ;
#ifdef F_25
V_2 -> V_91 = F_22 ;
#endif
V_2 -> V_92 = V_64 -> V_92 = F_6 ( V_2 ) ;
F_4 ( L_7 , V_64 -> V_92 ) ;
V_86 = ( V_64 -> V_92 + 1 ) * sizeof( struct V_93 ) ;
V_64 -> V_61 = F_24 ( V_86 , V_88 ) ;
if ( ! V_64 -> V_61 )
goto V_94;
for ( V_87 = 0 ; V_87 <= ( int ) ( V_64 -> V_92 ) ; V_87 ++ ) {
V_56 = F_11 ( V_2 , ( T_1 ) V_87 ) ;
if ( V_56 < 0 )
goto V_94;
}
if ( F_26 ( V_64 , 0x5888 ) || F_26 ( V_64 , 0x5889 ) ||
F_26 ( V_64 , 0x5901 ) )
F_27 ( V_64 ) ;
if ( F_28 ( V_64 ) == 16 ) {
if ( F_29 ( V_64 ) )
F_27 ( V_64 ) ;
}
F_4 ( L_8 , V_64 -> V_95 ) ;
( void ) F_14 ( V_2 ) ;
return 0 ;
V_94:
if ( V_2 -> V_65 ) {
F_21 ( V_64 -> V_61 ) ;
F_21 ( V_2 -> V_65 ) ;
V_2 -> V_65 = NULL ;
}
return - V_59 ;
}
static int F_30 ( struct V_96 * V_97 ,
const struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_16 ;
F_4 ( L_9 ) ;
V_16 = F_31 ( & V_2 , V_97 , V_99 ,
( V_99 - V_100 ) + V_101 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_32 ( V_2 ) ;
return V_16 ;
}
static int T_3 F_33 ( void )
{
return F_34 ( & V_102 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_102 ) ;
}
