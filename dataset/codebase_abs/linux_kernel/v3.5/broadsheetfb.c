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
return V_32 ;
}
memcpy ( V_47 + V_45 , V_3 , V_46 ) ;
V_48 = ( V_45 + V_46 ) % V_44 ;
if ( V_48 ) {
int V_52 ;
V_52 = V_44 - V_48 ;
V_32 = F_34 ( V_2 , V_48 ,
V_52 , V_47 + V_48 ) ;
if ( V_32 )
return V_32 ;
}
V_32 = F_33 ( V_2 , V_49 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_36 ( V_2 , V_49 ,
V_47 , V_44 ) ;
return V_32 ;
}
static int F_39 ( struct V_1 * V_2 , T_2 V_53 ,
const T_3 * V_54 , int V_55 , int V_38 )
{
int V_44 ;
int V_32 ;
int V_56 ;
int V_57 ;
int V_58 ;
int V_59 = 0 ;
switch ( V_38 ) {
case 0x10 :
V_44 = 32 * 1024 ;
break;
case 0x11 :
default:
V_44 = 64 * 1024 ;
break;
}
while ( V_55 ) {
V_56 = V_53 + V_59 ;
V_58 = F_40 ( V_56 , V_44 ) - V_56 ;
V_57 = F_41 ( V_55 , V_58 ) ;
V_32 = F_37 ( V_2 , V_44 ,
V_56 , V_57 , V_54 + V_59 ) ;
if ( V_32 )
return V_32 ;
V_59 += V_57 ;
V_55 -= V_57 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
const T_3 * V_54 , T_4 V_60 )
{
int V_32 = 0 ;
T_1 V_41 = 0 ;
int V_38 = 0 ;
V_32 = F_31 ( V_2 , & V_41 , & V_38 ) ;
if ( V_32 )
goto V_33;
V_32 = F_39 ( V_2 , 0x886 , V_54 , V_60 , V_38 ) ;
V_33:
F_15 ( V_2 , 0x0204 , V_41 ) ;
return V_32 ;
}
static T_5 F_43 ( struct V_35 * V_61 ,
struct V_62 * V_63 ,
const char * V_64 , T_4 V_65 )
{
int V_32 ;
struct V_66 * V_34 = F_44 ( V_61 ) ;
struct V_1 * V_2 = V_34 -> V_2 ;
const struct V_67 * V_68 ;
if ( V_65 < 1 )
return - V_40 ;
V_32 = F_45 ( & V_68 , L_3 , V_61 ) ;
if ( V_32 < 0 ) {
F_28 ( V_61 , L_4 ) ;
goto V_69;
}
if ( ( V_68 -> V_18 < 8 * 1024 ) || ( V_68 -> V_18 > 64 * 1024 ) ) {
F_28 ( V_61 , L_5 ) ;
V_32 = - V_40 ;
goto V_69;
}
F_46 ( & ( V_2 -> V_70 ) ) ;
V_32 = F_42 ( V_2 , V_68 -> V_3 ,
V_68 -> V_18 ) ;
F_47 ( & ( V_2 -> V_70 ) ) ;
if ( V_32 < 0 ) {
F_28 ( V_61 , L_6 ) ;
goto V_69;
}
F_48 ( V_61 , L_7 , V_68 -> V_18 ) ;
return V_65 ;
V_69:
return V_32 ;
}
static void T_6 F_49 ( struct V_1 * V_2 )
{
T_1 args [ 5 ] ;
int V_71 = V_2 -> V_34 -> V_72 . V_71 ;
int V_73 = V_2 -> V_34 -> V_72 . V_73 ;
args [ 0 ] = V_74 [ V_2 -> V_75 ] . V_76 ;
args [ 1 ] = V_74 [ V_2 -> V_75 ] . V_77 ;
args [ 2 ] = V_74 [ V_2 -> V_75 ] . V_78 ;
args [ 3 ] = V_74 [ V_2 -> V_75 ] . V_79 ;
args [ 4 ] = V_74 [ V_2 -> V_75 ] . V_80 ;
F_7 ( V_2 , V_81 , 5 , args ) ;
F_7 ( V_2 , V_81 , 5 , args ) ;
args [ 0 ] = V_74 [ V_2 -> V_75 ] . V_82 ;
args [ 1 ] = V_74 [ V_2 -> V_75 ] . V_83 ;
args [ 2 ] = V_74 [ V_2 -> V_75 ] . V_84 ;
args [ 3 ] = V_74 [ V_2 -> V_75 ] . V_85 ;
args [ 4 ] = V_74 [ V_2 -> V_75 ] . V_86 ;
F_7 ( V_2 , V_87 , 5 , args ) ;
F_16 ( V_2 , 0x310 , V_71 * V_73 * 2 ) ;
args [ 0 ] = 0x886 ;
args [ 1 ] = 0 ;
F_7 ( V_2 , V_88 , 2 , args ) ;
F_6 ( V_2 , V_89 ) ;
F_6 ( V_2 , V_90 ) ;
F_15 ( V_2 , 0x330 , 0x84 ) ;
F_6 ( V_2 , V_90 ) ;
args [ 0 ] = ( 0x3 << 4 ) ;
F_7 ( V_2 , V_91 , 1 , args ) ;
args [ 0 ] = 0x154 ;
F_7 ( V_2 , V_24 , 1 , args ) ;
F_10 ( V_2 , ( V_74 [ V_2 -> V_75 ] . V_76 *
V_74 [ V_2 -> V_75 ] . V_77 ) / 2 ,
( T_1 * ) V_2 -> V_34 -> V_92 ) ;
F_6 ( V_2 , V_93 ) ;
args [ 0 ] = 0x4300 ;
F_7 ( V_2 , V_94 , 1 , args ) ;
F_6 ( V_2 , V_90 ) ;
F_6 ( V_2 , V_95 ) ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
}
static void T_6 F_50 ( struct V_1 * V_2 )
{
T_1 V_96 , V_97 ;
struct V_35 * V_61 = V_2 -> V_34 -> V_35 ;
V_96 = F_18 ( V_2 , V_98 ) ;
V_97 = F_18 ( V_2 , V_99 ) ;
F_48 ( V_61 , L_8 , V_96 , V_97 ) ;
if ( V_97 != 0x0047 )
F_51 ( V_61 , L_9 ) ;
if ( V_96 != 0x0100 )
F_51 ( V_61 , L_10 ) ;
}
static void T_6 F_52 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_100 ) ;
F_53 ( 1000 ) ;
F_49 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
T_1 y1 , T_1 V_101 )
{
T_1 args [ 5 ] ;
unsigned char * V_64 = ( unsigned char * ) V_2 -> V_34 -> V_92 ;
F_46 ( & ( V_2 -> V_70 ) ) ;
y1 &= 0xFFFC ;
V_101 |= 0x0003 ;
args [ 0 ] = 0x3 << 4 ;
args [ 1 ] = 0 ;
args [ 2 ] = y1 ;
args [ 3 ] = F_55 ( V_2 -> V_34 -> V_72 . V_71 ) ;
args [ 4 ] = V_101 ;
F_7 ( V_2 , V_102 , 5 , args ) ;
args [ 0 ] = 0x154 ;
F_7 ( V_2 , V_24 , 1 , args ) ;
V_64 += y1 * V_2 -> V_34 -> V_72 . V_71 ;
F_10 ( V_2 , ( ( 1 + V_101 - y1 ) * V_2 -> V_34 -> V_72 . V_71 ) / 2 ,
( T_1 * ) V_64 ) ;
F_6 ( V_2 , V_93 ) ;
args [ 0 ] = 0x4300 ;
F_7 ( V_2 , V_94 , 1 , args ) ;
F_6 ( V_2 , V_90 ) ;
F_6 ( V_2 , V_95 ) ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
F_47 ( & ( V_2 -> V_70 ) ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_1 args [ 5 ] ;
F_46 ( & ( V_2 -> V_70 ) ) ;
args [ 0 ] = 0x3 << 4 ;
F_7 ( V_2 , V_91 , 1 , args ) ;
args [ 0 ] = 0x154 ;
F_7 ( V_2 , V_24 , 1 , args ) ;
F_10 ( V_2 , ( V_74 [ V_2 -> V_75 ] . V_76 *
V_74 [ V_2 -> V_75 ] . V_77 ) / 2 ,
( T_1 * ) V_2 -> V_34 -> V_92 ) ;
F_6 ( V_2 , V_93 ) ;
args [ 0 ] = 0x4300 ;
F_7 ( V_2 , V_94 , 1 , args ) ;
F_6 ( V_2 , V_90 ) ;
F_6 ( V_2 , V_95 ) ;
V_2 -> V_4 -> V_9 ( V_2 ) ;
F_47 ( & ( V_2 -> V_70 ) ) ;
}
static void F_57 ( struct V_66 * V_34 ,
struct V_103 * V_104 )
{
T_1 y1 = 0 , V_77 = 0 ;
int V_105 = - 1 ;
struct V_106 * V_107 ;
struct V_108 * V_109 = V_34 -> V_109 ;
int V_110 ;
T_1 V_73 = V_34 -> V_72 . V_73 ;
T_1 V_71 = V_34 -> V_72 . V_71 ;
V_110 = F_58 ( V_111 , V_71 ) ;
F_59 (cur, &fbdefio->pagelist, lru) {
if ( V_105 < 0 ) {
y1 = ( V_107 -> V_112 << V_113 ) / V_71 ;
V_77 = V_110 ;
} else if ( ( V_105 + 1 ) == V_107 -> V_112 ) {
V_77 += V_110 ;
} else {
F_54 ( V_34 -> V_2 , y1 , y1 + V_77 ) ;
y1 = ( V_107 -> V_112 << V_113 ) / V_71 ;
V_77 = V_110 ;
}
V_105 = V_107 -> V_112 ;
}
if ( V_77 >= V_73 ) {
F_56 ( V_34 -> V_2 ) ;
} else {
F_54 ( V_34 -> V_2 , y1 ,
F_41 ( ( T_1 ) ( y1 + V_77 ) , V_73 ) ) ;
}
}
static void F_60 ( struct V_66 * V_34 ,
const struct V_114 * V_115 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_61 ( V_34 , V_115 ) ;
F_56 ( V_2 ) ;
}
static void F_62 ( struct V_66 * V_34 ,
const struct V_116 * V_117 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_63 ( V_34 , V_117 ) ;
F_56 ( V_2 ) ;
}
static void F_64 ( struct V_66 * V_34 ,
const struct V_118 * V_119 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_65 ( V_34 , V_119 ) ;
F_56 ( V_2 ) ;
}
static T_5 F_66 ( struct V_66 * V_34 , const char T_7 * V_64 ,
T_4 V_120 , T_8 * V_121 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned long V_122 = * V_121 ;
void * V_123 ;
int V_32 = 0 ;
unsigned long V_124 ;
if ( V_34 -> V_125 != V_126 )
return - V_127 ;
V_124 = V_34 -> V_128 . V_129 ;
if ( V_122 > V_124 )
return - V_130 ;
if ( V_120 > V_124 ) {
V_32 = - V_130 ;
V_120 = V_124 ;
}
if ( V_120 + V_122 > V_124 ) {
if ( ! V_32 )
V_32 = - V_131 ;
V_120 = V_124 - V_122 ;
}
V_123 = ( void * ) ( V_34 -> V_92 + V_122 ) ;
if ( F_67 ( V_123 , V_64 , V_120 ) )
V_32 = - V_132 ;
if ( ! V_32 )
* V_121 += V_120 ;
F_56 ( V_2 ) ;
return ( V_32 ) ? V_32 : V_120 ;
}
static int T_6 F_68 ( struct V_133 * V_61 )
{
struct V_66 * V_34 ;
struct V_134 * V_4 ;
int V_135 = - V_51 ;
int V_136 ;
unsigned char * V_137 ;
struct V_1 * V_2 ;
int V_14 ;
int V_138 , V_139 ;
int V_75 ;
V_4 = V_61 -> V_61 . V_140 ;
if ( ! V_4 )
return - V_40 ;
if ( ! F_69 ( V_4 -> V_141 ) )
return - V_142 ;
V_34 = F_70 ( sizeof( struct V_1 ) , & V_61 -> V_61 ) ;
if ( ! V_34 )
goto V_32;
switch ( V_4 -> V_143 () ) {
case 37 :
V_75 = 1 ;
break;
case 97 :
V_75 = 2 ;
break;
case 6 :
default:
V_75 = 0 ;
break;
}
V_138 = V_74 [ V_75 ] . V_76 ;
V_139 = V_74 [ V_75 ] . V_77 ;
V_136 = F_40 ( ( V_138 * V_139 ) , V_111 ) ;
V_137 = F_71 ( V_136 ) ;
if ( ! V_137 )
goto V_144;
V_34 -> V_92 = ( char * ) V_137 ;
V_34 -> V_145 = & V_146 ;
V_147 . V_71 = V_138 ;
V_147 . V_73 = V_139 ;
V_147 . V_148 = V_138 ;
V_147 . V_149 = V_139 ;
V_34 -> V_72 = V_147 ;
V_150 . V_151 = V_138 ;
V_34 -> V_128 = V_150 ;
V_34 -> V_128 . V_129 = V_136 ;
V_2 = V_34 -> V_2 ;
V_2 -> V_75 = V_75 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_152 = F_15 ;
V_2 -> V_153 = F_18 ;
F_72 ( & V_2 -> V_154 ) ;
F_73 ( & V_2 -> V_70 ) ;
V_34 -> V_155 = V_156 | V_157 ;
V_34 -> V_109 = & V_158 ;
F_74 ( V_34 ) ;
V_135 = F_75 ( & V_34 -> V_159 , 16 , 0 ) ;
if ( V_135 < 0 ) {
F_28 ( & V_61 -> V_61 , L_11 ) ;
goto V_160;
}
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ )
V_34 -> V_159 . V_161 [ V_14 ] = ( ( ( 2 * V_14 ) + 1 ) * ( 0xFFFF ) ) / 32 ;
memcpy ( V_34 -> V_159 . V_162 , V_34 -> V_159 . V_161 , sizeof( T_1 ) * 16 ) ;
memcpy ( V_34 -> V_159 . V_163 , V_34 -> V_159 . V_161 , sizeof( T_1 ) * 16 ) ;
V_135 = V_2 -> V_4 -> V_164 ( V_34 ) ;
if ( V_135 < 0 )
goto V_165;
V_135 = V_4 -> V_166 ( V_2 ) ;
if ( V_135 < 0 )
goto V_167;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
V_135 = F_76 ( V_34 ) ;
if ( V_135 < 0 )
goto V_167;
F_77 ( V_61 , V_34 ) ;
V_135 = F_78 ( & V_61 -> V_61 , & V_168 ) ;
if ( V_135 < 0 )
goto V_169;
F_79 ( V_170
L_12 ,
V_34 -> V_171 , V_136 >> 10 ) ;
return 0 ;
V_169:
F_80 ( V_34 ) ;
V_167:
V_4 -> V_172 ( V_2 ) ;
V_165:
F_81 ( & V_34 -> V_159 ) ;
V_160:
F_82 ( V_137 ) ;
V_144:
F_83 ( V_34 ) ;
V_32:
F_84 ( V_4 -> V_141 ) ;
return V_135 ;
}
static int T_9 F_85 ( struct V_133 * V_61 )
{
struct V_66 * V_34 = F_86 ( V_61 ) ;
if ( V_34 ) {
struct V_1 * V_2 = V_34 -> V_2 ;
F_87 ( V_34 -> V_61 , & V_168 ) ;
F_80 ( V_34 ) ;
F_88 ( V_34 ) ;
V_2 -> V_4 -> V_172 ( V_2 ) ;
F_81 ( & V_34 -> V_159 ) ;
F_82 ( ( void * ) V_34 -> V_92 ) ;
F_84 ( V_2 -> V_4 -> V_141 ) ;
F_83 ( V_34 ) ;
}
return 0 ;
}
static int T_10 F_89 ( void )
{
return F_90 ( & V_173 ) ;
}
static void T_11 F_91 ( void )
{
F_92 ( & V_173 ) ;
}
