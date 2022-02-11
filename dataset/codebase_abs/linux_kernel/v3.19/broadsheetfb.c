static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 0 ) ;
V_2 -> V_4 -> V_7 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 1 ) ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 -> V_5 ( V_2 , V_8 , 0 ) ;
F_1 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 -> V_9 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 0 ) ;
F_2 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_8 , 1 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 1 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_11 ,
int V_12 , T_1 * V_13 )
{
int V_14 ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 0 ) ;
F_2 ( V_2 , V_11 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_8 , 1 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
F_1 ( V_2 , V_13 [ V_14 ] ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 1 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_11 ,
int V_12 , T_1 * V_13 )
{
int V_14 ;
V_2 -> V_4 -> V_15 ( V_2 , V_16 , V_11 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
V_2 -> V_4 -> V_15 ( V_2 , V_17 , V_13 [ V_14 ] ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 -> V_15 )
V_2 -> V_4 -> V_15 ( V_2 , V_16 , V_3 ) ;
else
F_3 ( V_2 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_11 ,
int V_12 , T_1 * V_13 )
{
if ( V_2 -> V_4 -> V_15 )
F_5 ( V_2 , V_11 , V_12 , V_13 ) ;
else
F_4 ( V_2 , V_11 , V_12 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_18 ,
T_1 * V_3 )
{
int V_14 ;
T_1 V_19 ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 0 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_8 , 1 ) ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 0 ) ;
V_19 = ( V_3 [ V_14 ] & 0x0F ) << 4 ;
V_19 |= ( V_3 [ V_14 ] & 0x0F00 ) << 4 ;
V_2 -> V_4 -> V_7 ( V_2 , V_19 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 1 ) ;
}
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 1 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_18 ,
T_1 * V_3 )
{
int V_14 ;
T_1 V_19 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
V_19 = ( V_3 [ V_14 ] & 0x0F ) << 4 ;
V_19 |= ( V_3 [ V_14 ] & 0x0F00 ) << 4 ;
V_2 -> V_4 -> V_15 ( V_2 , V_17 , V_19 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , int V_18 ,
T_1 * V_3 )
{
if ( V_2 -> V_4 -> V_15 )
F_9 ( V_2 , V_18 , V_3 ) ;
else
F_8 ( V_2 , V_18 , V_3 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_20 ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_8 , 1 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 0 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 0 ) ;
V_20 = V_2 -> V_4 -> V_21 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_6 , 1 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 1 ) ;
return V_20 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_22 )
return V_2 -> V_4 -> V_22 ( V_2 ) ;
else
return F_11 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_3 )
{
V_2 -> V_4 -> V_9 ( V_2 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 0 ) ;
F_2 ( V_2 , V_24 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_8 , 1 ) ;
F_1 ( V_2 , V_23 ) ;
F_1 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_5 ( V_2 , V_10 , 1 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_3 )
{
V_2 -> V_4 -> V_15 ( V_2 , V_16 , V_24 ) ;
V_2 -> V_4 -> V_15 ( V_2 , V_17 , V_23 ) ;
V_2 -> V_4 -> V_15 ( V_2 , V_17 , V_3 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_3 )
{
if ( V_2 -> V_4 -> V_15 )
F_14 ( V_2 , V_23 , V_3 ) ;
else
F_13 ( V_2 , V_23 , V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_23 ,
T_2 V_3 )
{
F_15 ( V_2 , V_23 , F_17 ( V_3 ) & 0xFFFF ) ;
F_15 ( V_2 , V_23 + 2 , ( F_17 ( V_3 ) >> 16 ) & 0xFFFF ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_1 V_23 )
{
F_7 ( V_2 , V_25 , 1 , & V_23 ) ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
return F_12 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
return F_18 ( V_2 , 0x000A ) & 0x0001 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
T_1 V_19 ;
F_15 ( V_2 , 0x0006 , 0x0000 ) ;
F_15 ( V_2 , 0x0010 , 0x0004 ) ;
F_15 ( V_2 , 0x0012 , 0x5949 ) ;
F_15 ( V_2 , 0x0014 , 0x0040 ) ;
F_15 ( V_2 , 0x0016 , 0x0000 ) ;
do {
if ( V_26 ++ > 100 )
return - V_27 ;
F_21 ( 1 ) ;
} while ( ! F_19 ( V_2 ) );
V_19 = F_18 ( V_2 , 0x0006 ) ;
V_19 &= ~ 0x1 ;
F_15 ( V_2 , 0x0006 , V_19 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_15 ( V_2 , 0x0204 , ( ( 3 << 3 ) | 1 ) ) ;
F_15 ( V_2 , 0x0208 , 0x0001 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 * V_28 )
{
* V_28 = F_18 ( V_2 , 0x0204 ) ;
F_15 ( V_2 , 0x0208 , 0 ) ;
F_15 ( V_2 , 0x0204 , 0 ) ;
F_15 ( V_2 , 0x0204 , ( ( 3 << 3 ) | 1 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_23 , int V_29 , int V_30 ,
int V_31 )
{
T_1 V_19 ;
do {
V_19 = F_18 ( V_2 , V_23 ) ;
if ( ( ( V_19 >> V_29 ) & 1 ) == V_30 )
return 0 ;
F_21 ( 1 ) ;
} while ( V_31 -- );
return - V_27 ;
}
static int F_25 ( struct V_1 * V_2 , T_3 V_3 )
{
F_15 ( V_2 , 0x0202 , ( V_3 | 0x100 ) ) ;
return F_24 ( V_2 , 0x0206 , 3 , 0 , 100 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_3 * V_3 )
{
int V_32 ;
T_1 V_19 ;
F_15 ( V_2 , 0x0202 , 0 ) ;
V_32 = F_24 ( V_2 , 0x0206 , 3 , 0 , 100 ) ;
if ( V_32 )
return V_32 ;
V_19 = F_18 ( V_2 , 0x200 ) ;
* V_3 = V_19 & 0xFF ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
int V_31 )
{
T_3 V_19 ;
int V_32 ;
do {
F_15 ( V_2 , 0x0208 , 1 ) ;
V_32 = F_25 ( V_2 , 0x05 ) ;
if ( V_32 )
goto V_33;
V_32 = F_26 ( V_2 , & V_19 ) ;
if ( V_32 )
goto V_33;
F_15 ( V_2 , 0x0208 , 0 ) ;
if ( ! ( V_19 & 0x1 ) )
return 0 ;
F_21 ( 5 ) ;
} while ( V_31 -- );
F_28 ( V_2 -> V_34 -> V_35 , L_1 ) ;
return - V_27 ;
V_33:
F_15 ( V_2 , 0x0208 , 0 ) ;
return V_32 ;
}
static int F_29 ( struct V_1 * V_2 ,
T_3 V_36 , T_2 V_37 )
{
int V_14 ;
T_3 V_19 ;
int V_32 ;
F_15 ( V_2 , 0x0208 , 1 ) ;
V_32 = F_25 ( V_2 , V_36 ) ;
if ( V_32 )
return V_32 ;
for ( V_14 = 2 ; V_14 >= 0 ; V_14 -- ) {
V_19 = ( ( V_37 >> ( V_14 * 8 ) ) & 0xFF ) ;
V_32 = F_25 ( V_2 , V_19 ) ;
if ( V_32 )
return V_32 ;
}
return V_32 ;
}
static int F_30 ( struct V_1 * V_2 ,
int * V_38 )
{
int V_32 = 0 ;
T_3 V_39 ;
V_32 = F_29 ( V_2 , 0xAB , 0x00000000 ) ;
if ( V_32 )
goto V_33;
V_32 = F_26 ( V_2 , & V_39 ) ;
if ( V_32 )
goto V_33;
if ( ( V_39 != 0x10 ) && ( V_39 != 0x11 ) ) {
F_28 ( V_2 -> V_34 -> V_35 , L_2 ) ;
V_32 = - V_40 ;
goto V_33;
}
* V_38 = V_39 ;
V_33:
F_15 ( V_2 , 0x0208 , 0 ) ;
return V_32 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_1 * V_41 , int * V_38 )
{
int V_32 ;
V_32 = F_20 ( V_2 ) ;
if ( V_32 )
return V_32 ;
F_15 ( V_2 , 0x0106 , 0x0203 ) ;
V_32 = F_22 ( V_2 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_23 ( V_2 , V_41 ) ;
if ( V_32 )
return V_32 ;
return F_30 ( V_2 , V_38 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
int V_42 )
{
int V_32 ;
F_15 ( V_2 , 0x0208 , 1 ) ;
if ( V_42 )
V_32 = F_25 ( V_2 , 0x06 ) ;
else
V_32 = F_25 ( V_2 , 0x04 ) ;
F_15 ( V_2 , 0x0208 , 0 ) ;
return V_32 ;
}
static int F_33 ( struct V_1 * V_2 ,
int V_37 )
{
int V_32 ;
F_32 ( V_2 , 1 ) ;
V_32 = F_29 ( V_2 , 0xD8 , V_37 ) ;
F_15 ( V_2 , 0x0208 , 0 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_27 ( V_2 , 1000 ) ;
return V_32 ;
}
static int F_34 ( struct V_1 * V_2 ,
int V_37 , int V_18 , char * V_3 )
{
int V_32 ;
int V_14 ;
V_32 = F_29 ( V_2 , 0x03 , V_37 ) ;
if ( V_32 )
goto V_33;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
V_32 = F_26 ( V_2 , & V_3 [ V_14 ] ) ;
if ( V_32 )
goto V_33;
}
V_33:
F_15 ( V_2 , 0x0208 , 0 ) ;
return V_32 ;
}
static int F_35 ( struct V_1 * V_2 ,
int V_37 , const char * V_3 )
{
int V_32 ;
int V_14 ;
F_32 ( V_2 , 1 ) ;
V_32 = F_29 ( V_2 , 0x02 , V_37 ) ;
if ( V_32 )
goto V_33;
for ( V_14 = 0 ; V_14 < V_43 ; V_14 ++ ) {
V_32 = F_25 ( V_2 , V_3 [ V_14 ] ) ;
if ( V_32 )
goto V_33;
}
F_15 ( V_2 , 0x0208 , 0 ) ;
V_32 = F_27 ( V_2 , 100 ) ;
V_33:
return V_32 ;
}
static int F_36 ( struct V_1 * V_2 ,
int V_37 , const char * V_3 , int V_44 )
{
int V_14 ;
int V_32 ;
for ( V_14 = 0 ; V_14 < V_44 ; V_14 += V_43 ) {
V_32 = F_35 ( V_2 , V_37 + V_14 , & V_3 [ V_14 ] ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
int V_44 , int V_45 ,
int V_46 , const char * V_3 )
{
int V_32 ;
char * V_47 ;
int V_48 ;
int V_49 ;
V_47 = F_38 ( sizeof( char ) * V_44 , V_50 ) ;
if ( ! V_47 )
return - V_51 ;
V_49 = ( V_45 / V_44 ) * V_44 ;
if ( V_45 != V_49 ) {
V_32 = F_34 ( V_2 , V_49 ,
V_45 , V_47 ) ;
if ( V_32 )
goto V_52;
}
memcpy ( V_47 + V_45 , V_3 , V_46 ) ;
V_48 = ( V_45 + V_46 ) % V_44 ;
if ( V_48 ) {
int V_53 ;
V_53 = V_44 - V_48 ;
V_32 = F_34 ( V_2 , V_48 ,
V_53 , V_47 + V_48 ) ;
if ( V_32 )
goto V_52;
}
V_32 = F_33 ( V_2 , V_49 ) ;
if ( V_32 )
goto V_52;
V_32 = F_36 ( V_2 , V_49 ,
V_47 , V_44 ) ;
V_52:
F_39 ( V_47 ) ;
return V_32 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 V_54 ,
const T_3 * V_55 , int V_56 , int V_38 )
{
int V_44 ;
int V_32 ;
int V_57 ;
int V_58 ;
int V_59 ;
int V_60 = 0 ;
switch ( V_38 ) {
case 0x10 :
V_44 = 32 * 1024 ;
break;
case 0x11 :
default:
V_44 = 64 * 1024 ;
break;
}
while ( V_56 ) {
V_57 = V_54 + V_60 ;
V_59 = F_41 ( V_57 , V_44 ) - V_57 ;
V_58 = F_42 ( V_56 , V_59 ) ;
V_32 = F_37 ( V_2 , V_44 ,
V_57 , V_58 , V_55 + V_60 ) ;
if ( V_32 )
return V_32 ;
V_60 += V_58 ;
V_56 -= V_58 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
const T_3 * V_55 , T_4 V_61 )
{
int V_32 = 0 ;
T_1 V_41 = 0 ;
int V_38 = 0 ;
V_32 = F_31 ( V_2 , & V_41 , & V_38 ) ;
if ( V_32 )
goto V_33;
V_32 = F_40 ( V_2 , 0x886 , V_55 , V_61 , V_38 ) ;
V_33:
F_15 ( V_2 , 0x0204 , V_41 ) ;
return V_32 ;
}
static T_5 F_44 ( struct V_35 * V_62 ,
struct V_63 * V_64 ,
const char * V_65 , T_4 V_66 )
{
int V_32 ;
struct V_67 * V_34 = F_45 ( V_62 ) ;
struct V_1 * V_2 = V_34 -> V_2 ;
const struct V_68 * V_69 ;
if ( V_66 < 1 )
return - V_40 ;
V_32 = F_46 ( & V_69 , L_3 , V_62 ) ;
if ( V_32 < 0 ) {
F_28 ( V_62 , L_4 ) ;
goto V_70;
}
if ( ( V_69 -> V_18 < 8 * 1024 ) || ( V_69 -> V_18 > 64 * 1024 ) ) {
F_28 ( V_62 , L_5 ) ;
V_32 = - V_40 ;
goto V_70;
}
F_47 ( & ( V_2 -> V_71 ) ) ;
V_32 = F_43 ( V_2 , V_69 -> V_3 ,
V_69 -> V_18 ) ;
F_48 ( & ( V_2 -> V_71 ) ) ;
if ( V_32 < 0 ) {
F_28 ( V_62 , L_6 ) ;
goto V_70;
}
F_49 ( V_62 , L_7 , V_69 -> V_18 ) ;
return V_66 ;
V_70:
return V_32 ;
}
static void F_50 ( struct V_1 * V_2 )
{
T_1 args [ 5 ] ;
int V_72 = V_2 -> V_34 -> V_73 . V_72 ;
int V_74 = V_2 -> V_34 -> V_73 . V_74 ;
args [ 0 ] = V_75 [ V_2 -> V_76 ] . V_77 ;
args [ 1 ] = V_75 [ V_2 -> V_76 ] . V_78 ;
args [ 2 ] = V_75 [ V_2 -> V_76 ] . V_79 ;
args [ 3 ] = V_75 [ V_2 -> V_76 ] . V_80 ;
args [ 4 ] = V_75 [ V_2 -> V_76 ] . V_81 ;
F_7 ( V_2 , V_82 , 5 , args ) ;
F_7 ( V_2 , V_82 , 5 , args ) ;
args [ 0 ] = V_75 [ V_2 -> V_76 ] . V_83 ;
args [ 1 ] = V_75 [ V_2 -> V_76 ] . V_84 ;
args [ 2 ] = V_75 [ V_2 -> V_76 ] . V_85 ;
args [ 3 ] = V_75 [ V_2 -> V_76 ] . V_86 ;
args [ 4 ] = V_75 [ V_2 -> V_76 ] . V_87 ;
F_7 ( V_2 , V_88 , 5 , args ) ;
F_16 ( V_2 , 0x310 , V_72 * V_74 * 2 ) ;
args [ 0 ] = 0x886 ;
args [ 1 ] = 0 ;
F_7 ( V_2 , V_89 , 2 , args ) ;
F_6 ( V_2 , V_90 ) ;
F_6 ( V_2 , V_91 ) ;
F_15 ( V_2 , 0x330 , 0x84 ) ;
F_6 ( V_2 , V_91 ) ;
args [ 0 ] = ( 0x3 << 4 ) ;
F_7 ( V_2 , V_92 , 1 , args ) ;
args [ 0 ] = 0x154 ;
F_7 ( V_2 , V_24 , 1 , args ) ;
F_10 ( V_2 , ( V_75 [ V_2 -> V_76 ] . V_77 *
V_75 [ V_2 -> V_76 ] . V_78 ) / 2 ,
( T_1 * ) V_2 -> V_34 -> V_93 ) ;
F_6 ( V_2 , V_94 ) ;
args [ 0 ] = 0x4300 ;
F_7 ( V_2 , V_95 , 1 , args ) ;
F_6 ( V_2 , V_91 ) ;
F_6 ( V_2 , V_96 ) ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_1 V_97 , V_98 ;
struct V_35 * V_62 = V_2 -> V_34 -> V_35 ;
V_97 = F_18 ( V_2 , V_99 ) ;
V_98 = F_18 ( V_2 , V_100 ) ;
F_49 ( V_62 , L_8 , V_97 , V_98 ) ;
if ( V_98 != 0x0047 )
F_52 ( V_62 , L_9 ) ;
if ( V_97 != 0x0100 )
F_52 ( V_62 , L_10 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_101 ) ;
F_54 ( 1000 ) ;
F_50 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
T_1 y1 , T_1 V_102 )
{
T_1 args [ 5 ] ;
unsigned char * V_65 = ( unsigned char * ) V_2 -> V_34 -> V_93 ;
F_47 ( & ( V_2 -> V_71 ) ) ;
y1 &= 0xFFFC ;
V_102 |= 0x0003 ;
args [ 0 ] = 0x3 << 4 ;
args [ 1 ] = 0 ;
args [ 2 ] = y1 ;
args [ 3 ] = F_56 ( V_2 -> V_34 -> V_73 . V_72 ) ;
args [ 4 ] = V_102 ;
F_7 ( V_2 , V_103 , 5 , args ) ;
args [ 0 ] = 0x154 ;
F_7 ( V_2 , V_24 , 1 , args ) ;
V_65 += y1 * V_2 -> V_34 -> V_73 . V_72 ;
F_10 ( V_2 , ( ( 1 + V_102 - y1 ) * V_2 -> V_34 -> V_73 . V_72 ) / 2 ,
( T_1 * ) V_65 ) ;
F_6 ( V_2 , V_94 ) ;
args [ 0 ] = 0x4300 ;
F_7 ( V_2 , V_95 , 1 , args ) ;
F_6 ( V_2 , V_91 ) ;
F_6 ( V_2 , V_96 ) ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
F_48 ( & ( V_2 -> V_71 ) ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 args [ 5 ] ;
F_47 ( & ( V_2 -> V_71 ) ) ;
args [ 0 ] = 0x3 << 4 ;
F_7 ( V_2 , V_92 , 1 , args ) ;
args [ 0 ] = 0x154 ;
F_7 ( V_2 , V_24 , 1 , args ) ;
F_10 ( V_2 , ( V_75 [ V_2 -> V_76 ] . V_77 *
V_75 [ V_2 -> V_76 ] . V_78 ) / 2 ,
( T_1 * ) V_2 -> V_34 -> V_93 ) ;
F_6 ( V_2 , V_94 ) ;
args [ 0 ] = 0x4300 ;
F_7 ( V_2 , V_95 , 1 , args ) ;
F_6 ( V_2 , V_91 ) ;
F_6 ( V_2 , V_96 ) ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
F_48 ( & ( V_2 -> V_71 ) ) ;
}
static void F_58 ( struct V_67 * V_34 ,
struct V_104 * V_105 )
{
T_1 y1 = 0 , V_78 = 0 ;
int V_106 = - 1 ;
struct V_107 * V_108 ;
struct V_109 * V_110 = V_34 -> V_110 ;
int V_111 ;
T_1 V_74 = V_34 -> V_73 . V_74 ;
T_1 V_72 = V_34 -> V_73 . V_72 ;
V_111 = F_59 ( V_112 , V_72 ) ;
F_60 (cur, &fbdefio->pagelist, lru) {
if ( V_106 < 0 ) {
y1 = ( V_108 -> V_113 << V_114 ) / V_72 ;
V_78 = V_111 ;
} else if ( ( V_106 + 1 ) == V_108 -> V_113 ) {
V_78 += V_111 ;
} else {
F_55 ( V_34 -> V_2 , y1 , y1 + V_78 ) ;
y1 = ( V_108 -> V_113 << V_114 ) / V_72 ;
V_78 = V_111 ;
}
V_106 = V_108 -> V_113 ;
}
if ( V_78 >= V_74 ) {
F_57 ( V_34 -> V_2 ) ;
} else {
F_55 ( V_34 -> V_2 , y1 ,
F_42 ( ( T_1 ) ( y1 + V_78 ) , V_74 ) ) ;
}
}
static void F_61 ( struct V_67 * V_34 ,
const struct V_115 * V_116 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_62 ( V_34 , V_116 ) ;
F_57 ( V_2 ) ;
}
static void F_63 ( struct V_67 * V_34 ,
const struct V_117 * V_118 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_64 ( V_34 , V_118 ) ;
F_57 ( V_2 ) ;
}
static void F_65 ( struct V_67 * V_34 ,
const struct V_119 * V_120 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_66 ( V_34 , V_120 ) ;
F_57 ( V_2 ) ;
}
static T_5 F_67 ( struct V_67 * V_34 , const char T_6 * V_65 ,
T_4 V_121 , T_7 * V_122 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned long V_123 = * V_122 ;
void * V_124 ;
int V_32 = 0 ;
unsigned long V_125 ;
if ( V_34 -> V_126 != V_127 )
return - V_128 ;
V_125 = V_34 -> V_129 . V_130 ;
if ( V_123 > V_125 )
return - V_131 ;
if ( V_121 > V_125 ) {
V_32 = - V_131 ;
V_121 = V_125 ;
}
if ( V_121 + V_123 > V_125 ) {
if ( ! V_32 )
V_32 = - V_132 ;
V_121 = V_125 - V_123 ;
}
V_124 = ( void * ) ( V_34 -> V_93 + V_123 ) ;
if ( F_68 ( V_124 , V_65 , V_121 ) )
V_32 = - V_133 ;
if ( ! V_32 )
* V_122 += V_121 ;
F_57 ( V_2 ) ;
return ( V_32 ) ? V_32 : V_121 ;
}
static int F_69 ( struct V_134 * V_62 )
{
struct V_67 * V_34 ;
struct V_135 * V_4 ;
int V_136 = - V_51 ;
int V_137 ;
unsigned char * V_138 ;
struct V_1 * V_2 ;
int V_14 ;
int V_139 , V_140 ;
int V_76 ;
V_4 = V_62 -> V_62 . V_141 ;
if ( ! V_4 )
return - V_40 ;
if ( ! F_70 ( V_4 -> V_142 ) )
return - V_143 ;
V_34 = F_71 ( sizeof( struct V_1 ) , & V_62 -> V_62 ) ;
if ( ! V_34 )
goto V_32;
switch ( V_4 -> V_144 () ) {
case 37 :
V_76 = 1 ;
break;
case 97 :
V_76 = 2 ;
break;
case 6 :
default:
V_76 = 0 ;
break;
}
V_139 = V_75 [ V_76 ] . V_77 ;
V_140 = V_75 [ V_76 ] . V_78 ;
V_137 = F_41 ( ( V_139 * V_140 ) , V_112 ) ;
V_138 = F_72 ( V_137 ) ;
if ( ! V_138 )
goto V_145;
V_34 -> V_93 = ( char * ) V_138 ;
V_34 -> V_146 = & V_147 ;
V_148 . V_72 = V_139 ;
V_148 . V_74 = V_140 ;
V_148 . V_149 = V_139 ;
V_148 . V_150 = V_140 ;
V_34 -> V_73 = V_148 ;
V_151 . V_152 = V_139 ;
V_34 -> V_129 = V_151 ;
V_34 -> V_129 . V_130 = V_137 ;
V_2 = V_34 -> V_2 ;
V_2 -> V_76 = V_76 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_153 = F_15 ;
V_2 -> V_154 = F_18 ;
F_73 ( & V_2 -> V_155 ) ;
F_74 ( & V_2 -> V_71 ) ;
V_34 -> V_156 = V_157 | V_158 ;
V_34 -> V_110 = & V_159 ;
F_75 ( V_34 ) ;
V_136 = F_76 ( & V_34 -> V_160 , 16 , 0 ) ;
if ( V_136 < 0 ) {
F_28 ( & V_62 -> V_62 , L_11 ) ;
goto V_161;
}
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ )
V_34 -> V_160 . V_162 [ V_14 ] = ( ( ( 2 * V_14 ) + 1 ) * ( 0xFFFF ) ) / 32 ;
memcpy ( V_34 -> V_160 . V_163 , V_34 -> V_160 . V_162 , sizeof( T_1 ) * 16 ) ;
memcpy ( V_34 -> V_160 . V_164 , V_34 -> V_160 . V_162 , sizeof( T_1 ) * 16 ) ;
V_136 = V_2 -> V_4 -> V_165 ( V_34 ) ;
if ( V_136 < 0 )
goto V_166;
V_136 = V_4 -> V_167 ( V_2 ) ;
if ( V_136 < 0 )
goto V_168;
F_51 ( V_2 ) ;
F_53 ( V_2 ) ;
V_136 = F_77 ( V_34 ) ;
if ( V_136 < 0 )
goto V_168;
F_78 ( V_62 , V_34 ) ;
V_136 = F_79 ( & V_62 -> V_62 , & V_169 ) ;
if ( V_136 < 0 )
goto V_170;
V_67 ( V_34 , L_12 ,
V_137 >> 10 ) ;
return 0 ;
V_170:
F_80 ( V_34 ) ;
V_168:
V_4 -> V_171 ( V_2 ) ;
V_166:
F_81 ( & V_34 -> V_160 ) ;
V_161:
F_82 ( V_138 ) ;
V_145:
F_83 ( V_34 ) ;
V_32:
F_84 ( V_4 -> V_142 ) ;
return V_136 ;
}
static int F_85 ( struct V_134 * V_62 )
{
struct V_67 * V_34 = F_86 ( V_62 ) ;
if ( V_34 ) {
struct V_1 * V_2 = V_34 -> V_2 ;
F_87 ( V_34 -> V_62 , & V_169 ) ;
F_80 ( V_34 ) ;
F_88 ( V_34 ) ;
V_2 -> V_4 -> V_171 ( V_2 ) ;
F_81 ( & V_34 -> V_160 ) ;
F_82 ( ( void * ) V_34 -> V_93 ) ;
F_84 ( V_2 -> V_4 -> V_142 ) ;
F_83 ( V_34 ) ;
}
return 0 ;
}
