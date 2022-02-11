static T_1 F_1 ( struct V_1 * V_2 , int * V_3 )
{
int V_4 ;
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_2 -> V_7 , & V_4 ) ;
if ( ! V_4 )
V_5 |= F_2 ( V_2 -> V_6 , V_2 -> V_7 + 1 ,
& V_4 ) << 8 ;
if ( V_3 )
* V_3 = V_4 ;
if ( V_4 )
return 0xffff ;
return V_5 ;
}
static T_2 F_3 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_8 ;
V_8 = F_2 ( V_2 -> V_6 , V_9 , & V_4 ) ;
if ( V_4 )
V_8 = 0 ;
return V_8 ;
}
static T_1 F_4 ( struct V_1 * V_2 , int * V_3 )
{
int V_4 ;
T_1 V_10 ;
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
V_10 = F_1 ( V_2 , & V_4 ) ;
break;
case V_14 :
default:
V_10 = F_2 ( V_2 -> V_6 , V_15 , & V_4 ) ;
if ( ! V_4 )
V_10 <<= V_2 -> V_8 ;
else
V_10 = 0xffff ;
break;
}
if ( V_3 )
* V_3 = V_4 ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 * V_16 , unsigned V_17 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
int V_4 ;
unsigned long V_20 ;
T_2 V_21 ;
F_6 ( V_22 ) ;
if ( V_17 > V_23 ) {
F_7 ( L_1 ,
( int ) V_17 ) ;
V_4 = - V_24 ;
goto V_25;
}
F_8 ( & V_19 -> V_26 , V_20 ) ;
V_21 = ( V_19 -> V_27 == 0 ) ? 1 : 0 ;
F_9 ( V_19 -> V_28 [ V_21 ] ) ;
V_19 -> V_28 [ V_21 ] = V_17 ;
memcpy ( V_19 -> V_29 [ V_21 ] , V_16 , V_17 ) ;
F_10 ( V_19 , V_21 ) ;
F_11 ( & V_19 -> V_26 , V_20 ) ;
V_4 = 0 ;
V_25:
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_2 * V_16 , unsigned V_17 )
{
int V_4 ;
struct V_30 * V_31 ;
char * V_32 ;
F_6 ( V_22 ) ;
if ( V_17 > V_33 ) {
F_7 ( L_1 ,
( int ) V_17 ) ;
V_4 = - V_24 ;
goto V_25;
}
V_31 = F_14 ( V_33 + V_34 ) ;
if ( ! V_31 ) {
V_4 = - V_35 ;
goto V_25;
}
F_15 ( V_31 , V_34 ) ;
V_32 = F_16 ( V_31 , V_17 ) ;
memcpy ( V_32 , V_16 , V_17 ) ;
F_17 ( V_2 -> V_19 , V_31 ) ;
V_4 = 0 ;
V_25:
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_2 * V_16 , unsigned V_17 )
{
int V_4 ;
T_3 V_36 ;
F_6 ( V_22 ) ;
if ( V_2 -> V_11 == V_12 ) {
V_36 = F_2 ( V_2 -> V_6 , V_37 , & V_4 ) ;
if ( V_4 )
goto V_25;
V_36 >>= 3 ;
} else {
if ( V_17 < 4 ) {
F_7 ( L_3 ,
( int ) V_17 ) ;
V_4 = - V_38 ;
goto V_25;
}
V_36 = V_16 [ 3 ] << 24 ;
V_36 |= V_16 [ 2 ] << 16 ;
V_36 |= V_16 [ 1 ] << 8 ;
V_36 |= V_16 [ 0 ] << 0 ;
}
F_19 ( V_2 -> V_19 , V_36 & 0xFF ) ;
V_4 = 0 ;
V_25:
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_20 ( struct V_1 * V_2 , const T_2 V_39 )
{
T_2 V_40 ;
unsigned long V_41 ;
int V_4 = 0 ;
V_41 = V_42 + V_43 ;
while ( 1 ) {
V_40 = F_2 ( V_2 -> V_6 , V_44 , & V_4 ) ;
if ( V_4 )
return V_4 ;
if ( ( V_40 & V_39 ) == V_39 )
break;
if ( F_21 ( V_42 , V_41 ) )
return - V_45 ;
F_22 ( 1 ) ;
}
return V_4 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_17 , type , V_46 ;
F_6 ( V_22 ) ;
V_17 = F_4 ( V_2 , & V_4 ) ;
if ( V_4 )
goto V_25;
if ( V_17 < 4 ) {
F_7 ( L_4 ,
( int ) V_17 ) ;
V_4 = - V_38 ;
goto V_25;
}
V_4 = F_20 ( V_2 , V_47 ) ;
if ( V_4 )
goto V_25;
V_46 = F_24 ( V_2 -> V_6 , V_17 ) ;
V_4 = F_25 ( V_2 -> V_6 , V_2 -> V_16 , V_2 -> V_48 , V_46 ) ;
if ( V_4 )
goto V_25;
V_46 = V_2 -> V_16 [ 0 ] | ( V_2 -> V_16 [ 1 ] << 8 ) ;
type = V_2 -> V_16 [ 2 ] | ( V_2 -> V_16 [ 3 ] << 8 ) ;
F_7 ( L_5 ,
( int ) type , ( int ) V_46 ) ;
if ( V_46 > V_17 ) {
F_7 ( L_6 ,
( int ) V_46 , ( int ) V_17 ) ;
V_4 = - V_38 ;
goto V_25;
}
if ( V_46 < V_17 ) {
F_7 ( L_7 ,
( int ) V_46 , ( int ) V_17 ) ;
}
switch ( type ) {
case V_49 :
V_4 = F_5 ( V_2 , V_2 -> V_16 + 4 , V_46 - 4 ) ;
if ( V_4 )
goto V_25;
break;
case V_50 :
V_4 = F_13 ( V_2 , V_2 -> V_16 + 4 , V_46 - 4 ) ;
if ( V_4 )
goto V_25;
break;
case V_51 :
V_4 = F_18 ( V_2 , V_2 -> V_16 + 4 , V_46 - 4 ) ;
if ( V_4 )
goto V_25;
break;
default:
F_7 ( L_8 ,
( int ) type ) ;
V_4 = - V_38 ;
goto V_25;
}
V_25:
if ( V_4 )
F_26 ( L_9 ) ;
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static void F_27 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_54 * V_55 ;
int V_4 ;
unsigned long V_20 ;
F_6 ( V_22 ) ;
V_2 = F_28 ( V_53 , struct V_1 , V_56 ) ;
while ( 1 ) {
F_8 ( & V_2 -> V_57 , V_20 ) ;
V_55 = V_2 -> V_58 ;
if ( V_55 )
V_2 -> V_58 = V_55 -> V_59 ;
F_11 ( & V_2 -> V_57 , V_20 ) ;
if ( ! V_55 )
break;
F_29 ( V_2 -> V_6 ) ;
V_4 = F_20 ( V_2 , V_47 ) ;
if ( V_4 == 0 ) {
V_4 = F_30 ( V_2 -> V_6 , V_2 -> V_48 ,
V_55 -> V_16 , V_55 -> V_60 ) ;
}
if ( V_4 )
F_26 ( L_10 , V_4 ) ;
F_31 ( V_2 -> V_6 ) ;
F_32 ( V_55 ) ;
}
F_33 ( V_22 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_61 * V_62 )
{
int V_4 ;
unsigned long V_41 ;
T_2 * V_63 ;
T_3 V_64 ;
const T_2 * V_61 ;
T_4 V_17 ;
F_6 ( V_22 ) ;
V_63 = F_35 ( 64 , V_65 ) ;
if ( ! V_63 ) {
V_4 = - V_35 ;
goto V_25;
}
F_29 ( V_2 -> V_6 ) ;
V_4 = F_36 ( V_2 -> V_6 , 32 ) ;
if ( V_4 )
goto V_66;
V_61 = V_62 -> V_32 ;
V_17 = V_62 -> V_17 ;
while ( V_17 ) {
V_4 = F_20 ( V_2 , V_67 ) ;
if ( V_4 )
goto V_66;
F_22 ( 2 ) ;
V_64 = F_37 ( T_4 , V_17 , 60 ) ;
* ( ( V_68 * ) V_63 ) = F_38 ( V_64 ) ;
memcpy ( V_63 + 4 , V_61 , V_64 ) ;
V_4 = F_30 ( V_2 -> V_6 , V_2 -> V_48 ,
V_63 , 64 ) ;
if ( V_4 )
goto V_66;
V_61 += V_64 ;
V_17 -= V_64 ;
}
memset ( V_63 , 0 , 4 ) ;
V_4 = F_30 ( V_2 -> V_6 , V_2 -> V_48 , V_63 , 64 ) ;
if ( V_4 )
goto V_66;
F_7 ( L_11 ) ;
V_41 = V_42 + V_43 ;
while ( 1 ) {
T_1 V_69 ;
V_69 = F_2 ( V_2 -> V_6 , V_70 , & V_4 ) ;
if ( V_4 )
goto V_66;
V_69 |= F_2 ( V_2 -> V_6 , V_70 + 1 , & V_4 ) << 8 ;
if ( V_4 )
goto V_66;
if ( V_69 != 0 )
break;
if ( F_21 ( V_42 , V_41 ) ) {
V_4 = - V_45 ;
goto V_66;
}
F_39 ( 10 ) ;
}
V_4 = 0 ;
V_66:
F_31 ( V_2 -> V_6 ) ;
F_32 ( V_63 ) ;
V_25:
if ( V_4 )
F_26 ( L_12 ) ;
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_40 ( struct V_1 * V_2 ,
const struct V_61 * V_62 )
{
int V_4 ;
unsigned long V_41 ;
T_2 * V_63 ;
T_3 V_64 ;
const T_2 * V_61 ;
T_4 V_17 , V_69 ;
F_6 ( V_22 ) ;
V_63 = F_35 ( 512 , V_65 ) ;
if ( ! V_63 ) {
V_4 = - V_35 ;
goto V_25;
}
F_29 ( V_2 -> V_6 ) ;
V_4 = F_36 ( V_2 -> V_6 , 32 ) ;
if ( V_4 )
goto V_66;
V_61 = V_62 -> V_32 ;
V_17 = V_62 -> V_17 ;
while ( V_17 ) {
V_41 = V_42 + V_43 ;
while ( 1 ) {
V_4 = F_20 ( V_2 , V_67 ) ;
if ( V_4 )
goto V_66;
V_69 = F_2 ( V_2 -> V_6 , V_70 ,
& V_4 ) ;
if ( V_4 )
goto V_66;
V_69 |= F_2 ( V_2 -> V_6 , V_70 + 1 ,
& V_4 ) << 8 ;
if ( V_4 )
goto V_66;
if ( ( V_17 != V_62 -> V_17 ) || ( V_69 > 2 ) )
break;
if ( F_21 ( V_42 , V_41 ) ) {
V_4 = - V_45 ;
goto V_66;
}
F_22 ( 1 ) ;
}
if ( V_69 == 0 ) {
F_7 ( L_13 ) ;
V_4 = - V_71 ;
goto V_66;
}
if ( V_69 & 0x01 ) {
F_7 ( L_14 ) ;
V_4 = - V_71 ;
goto V_66;
}
if ( V_69 > V_17 )
V_69 = V_17 ;
while ( V_69 ) {
V_64 = F_37 ( T_4 , V_69 , 512 ) ;
memcpy ( V_63 , V_61 , V_64 ) ;
V_4 = F_30 ( V_2 -> V_6 , V_2 -> V_48 ,
V_63 , F_41 ( V_64 , 32 ) ) ;
if ( V_4 )
goto V_66;
V_61 += V_64 ;
V_17 -= V_64 ;
V_69 -= V_64 ;
}
}
V_4 = 0 ;
F_7 ( L_15 ) ;
V_41 = V_42 + V_43 ;
while ( 1 ) {
T_1 V_5 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_4 )
goto V_66;
if ( V_5 == V_72 )
break;
if ( F_21 ( V_42 , V_41 ) ) {
V_4 = - V_45 ;
goto V_66;
}
F_39 ( 10 ) ;
}
V_4 = 0 ;
V_66:
F_31 ( V_2 -> V_6 ) ;
F_32 ( V_63 ) ;
V_25:
if ( V_4 )
F_26 ( L_16 ) ;
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static void F_42 ( struct V_18 * V_19 , int V_4 ,
const struct V_61 * V_73 ,
const struct V_61 * V_74 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_4 ) {
F_26 ( L_17 , V_4 ) ;
return;
}
V_4 = F_34 ( V_2 , V_73 ) ;
if ( V_4 )
return;
F_7 ( L_18 ) ;
V_4 = F_40 ( V_2 , V_74 ) ;
if ( V_4 )
return;
F_7 ( L_19 ) ;
F_43 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_5 ;
F_6 ( V_22 ) ;
F_29 ( V_2 -> V_6 ) ;
F_45 ( V_2 -> V_6 , 0x00 , V_75 , & V_4 ) ;
F_31 ( V_2 -> V_6 ) ;
F_29 ( V_2 -> V_6 ) ;
V_5 = F_1 ( V_2 , & V_4 ) ;
F_31 ( V_2 -> V_6 ) ;
F_7 ( L_20 , V_5 ) ;
F_7 ( L_21 , V_4 ) ;
if ( V_4 )
goto V_25;
if ( V_5 == V_72 ) {
F_7 ( L_22 ) ;
F_43 ( V_2 ) ;
return 0 ;
} else if ( ( V_2 -> V_11 == V_13 ) && ( V_5 & 0x7fff ) ) {
F_7 ( L_23 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
V_4 = F_46 ( V_2 -> V_19 , & V_2 -> V_6 -> V_76 , V_2 -> V_11 ,
V_77 , F_42 ) ;
V_25:
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_78 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 = V_2 -> V_19 ;
int V_4 ;
F_29 ( V_6 ) ;
F_36 ( V_2 -> V_6 , V_79 ) ;
if ( ( V_2 -> V_11 != V_12 )
&& ( V_2 -> V_11 != V_13 ) )
V_2 -> V_8 = F_3 ( V_2 ) ;
else
V_2 -> V_8 = 0 ;
V_4 = F_47 ( V_6 , V_80 ) ;
if ( V_4 )
goto V_66;
F_45 ( V_6 , 0x0f , V_75 , & V_4 ) ;
if ( V_4 )
goto V_81;
F_31 ( V_6 ) ;
V_19 -> V_82 = 1 ;
if ( V_2 -> V_11 == V_14 ) {
struct V_83 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_7 ( L_24 ) ;
if ( F_48 ( V_19 , V_85 , & V_84 , sizeof( V_84 ) ,
V_86 , ( unsigned long ) & V_84 ) )
F_49 ( V_19 -> V_76 , L_25 ) ;
}
F_50 ( & V_2 -> V_87 ) ;
if ( ! V_2 -> V_88 ) {
V_4 = F_51 ( V_19 ) ;
F_52 ( V_2 ) ;
if ( V_4 == 0 ) {
V_2 -> V_88 = true ;
F_53 ( & V_6 -> V_76 ) ;
}
}
return;
V_81:
F_54 ( V_6 ) ;
V_66:
F_31 ( V_6 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_78 * V_6 = V_2 -> V_6 ;
struct V_89 * V_90 = V_6 -> V_2 -> V_90 ;
int V_4 ;
F_29 ( V_6 ) ;
V_4 = F_56 ( V_6 ) ;
if ( V_4 )
goto V_66;
if ( ( V_2 -> V_11 == V_13 ) &&
( V_90 -> V_91 & V_92 ) &&
( V_90 -> V_93 . V_94 == V_95 ) ) {
T_2 V_96 ;
V_6 -> V_2 -> V_97 |= V_98 ;
V_96 = F_57 ( V_6 , V_99 , & V_4 ) ;
if ( V_4 )
goto V_100;
V_96 |= V_101 ;
F_58 ( V_6 , V_96 , V_99 , & V_4 ) ;
if ( V_4 )
goto V_100;
}
V_2 -> V_48 = F_2 ( V_6 , V_102 , & V_4 ) ;
if ( V_4 )
goto V_100;
V_2 -> V_48 |= F_2 ( V_6 , V_102 + 1 , & V_4 ) << 8 ;
if ( V_4 )
goto V_100;
V_2 -> V_48 |= F_2 ( V_6 , V_102 + 2 , & V_4 ) << 16 ;
if ( V_4 )
goto V_100;
F_31 ( V_6 ) ;
V_4 = F_44 ( V_2 ) ;
if ( V_4 ) {
F_29 ( V_6 ) ;
goto V_100;
}
return 0 ;
V_100:
F_59 ( V_6 ) ;
V_66:
F_31 ( V_6 ) ;
return V_4 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_78 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 = V_2 -> V_19 ;
V_19 -> V_82 = 0 ;
F_29 ( V_6 ) ;
F_54 ( V_6 ) ;
F_59 ( V_6 ) ;
F_31 ( V_6 ) ;
return 0 ;
}
static int F_60 ( struct V_18 * V_19 ,
T_2 type , T_2 * V_103 , T_1 V_60 )
{
int V_4 ;
struct V_1 * V_2 ;
struct V_54 * V_55 , * V_104 ;
T_1 V_17 ;
unsigned long V_20 ;
F_61 ( V_22 , L_26 , type , V_60 ) ;
V_2 = V_19 -> V_2 ;
if ( V_60 > ( 65536 - sizeof( struct V_54 ) - 4 ) ) {
V_4 = - V_38 ;
goto V_25;
}
V_17 = F_24 ( V_2 -> V_6 , V_60 + 4 ) ;
V_55 = F_35 ( sizeof( struct V_54 ) + V_17 ,
V_105 ) ;
if ( ! V_55 ) {
V_4 = - V_35 ;
goto V_25;
}
V_55 -> V_59 = NULL ;
V_55 -> V_60 = V_17 ;
V_55 -> V_16 [ 0 ] = ( V_60 + 4 ) & 0xff ;
V_55 -> V_16 [ 1 ] = ( ( V_60 + 4 ) >> 8 ) & 0xff ;
V_55 -> V_16 [ 2 ] = type ;
V_55 -> V_16 [ 3 ] = 0 ;
memcpy ( V_55 -> V_16 + 4 , V_103 , V_60 ) ;
F_8 ( & V_2 -> V_57 , V_20 ) ;
if ( ! V_2 -> V_58 )
V_2 -> V_58 = V_55 ;
else {
V_104 = V_2 -> V_58 ;
while ( V_104 -> V_59 )
V_104 = V_104 -> V_59 ;
V_104 -> V_59 = V_55 ;
}
switch ( type ) {
case V_49 :
V_19 -> V_106 = V_107 ;
break;
case V_50 :
V_19 -> V_106 = V_108 ;
break;
default:
F_7 ( L_27 , ( int ) type ) ;
}
F_11 ( & V_2 -> V_57 , V_20 ) ;
F_62 ( V_2 -> V_109 , & V_2 -> V_56 ) ;
V_4 = 0 ;
V_25:
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_63 ( struct V_18 * V_19 )
{
int V_4 = - 1 ;
struct V_83 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_7 ( L_28 ) ;
V_4 = F_48 ( V_19 , V_110 , & V_84 , sizeof( V_84 ) ,
V_86 , ( unsigned long ) & V_84 ) ;
if ( V_4 )
F_64 ( V_19 -> V_76 , L_29 ) ;
F_22 ( 200 ) ;
return V_4 ;
}
static int F_65 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = - 1 ;
F_6 ( V_22 ) ;
F_29 ( V_2 -> V_6 ) ;
F_45 ( V_2 -> V_6 , V_111 , V_112 , & V_4 ) ;
if ( V_4 )
F_64 ( V_19 -> V_76 , L_30 ) ;
F_31 ( V_2 -> V_6 ) ;
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_66 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = - 1 ;
F_6 ( V_22 ) ;
F_29 ( V_2 -> V_6 ) ;
F_45 ( V_2 -> V_6 , 0 , V_112 , & V_4 ) ;
if ( V_4 )
F_64 ( V_19 -> V_76 , L_30 ) ;
F_31 ( V_2 -> V_6 ) ;
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static void F_67 ( struct V_52 * V_53 )
{
F_68 ( L_31 ) ;
F_69 ( V_113 ) ;
F_70 ( V_113 ) ;
}
static void F_71 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( F_72 ( & V_114 ) )
return;
V_113 = V_2 -> V_6 -> V_2 -> V_90 ;
F_73 ( & V_114 ) ;
}
static int F_74 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
F_75 ( V_2 -> V_109 ) ;
V_4 = F_52 ( V_2 ) ;
F_76 ( & V_2 -> V_6 -> V_76 ) ;
return V_4 ;
}
static int F_77 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_115 ;
F_78 ( & V_2 -> V_6 -> V_76 ) ;
V_115 = F_55 ( V_2 ) ;
if ( V_115 )
return V_115 ;
F_79 ( V_2 -> V_87 , V_19 -> V_82 ) ;
return 0 ;
}
static void V_80 ( struct V_78 * V_6 )
{
int V_4 ;
struct V_1 * V_2 ;
T_2 V_116 ;
F_6 ( V_22 ) ;
V_2 = F_80 ( V_6 ) ;
V_116 = F_2 ( V_2 -> V_6 , V_117 , & V_4 ) ;
if ( V_4 || ! V_116 )
goto V_25;
F_7 ( L_32 , ( unsigned ) V_116 ) ;
F_45 ( V_2 -> V_6 , ~ V_116 , V_117 , & V_4 ) ;
if ( V_4 )
goto V_25;
V_2 -> V_19 -> V_118 = 1 ;
if ( V_116 & V_119 )
F_81 ( V_2 -> V_19 ) ;
if ( V_116 & V_120 ) {
V_4 = F_23 ( V_2 ) ;
if ( V_4 )
goto V_25;
}
V_4 = 0 ;
V_25:
F_12 ( V_22 , L_2 , V_4 ) ;
}
static int F_82 ( struct V_78 * V_6 ,
const struct V_121 * V_122 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_4 , V_21 ;
unsigned int V_11 ;
struct V_54 * V_55 ;
F_6 ( V_22 ) ;
for ( V_21 = 0 ; V_21 < V_6 -> V_2 -> V_123 ; V_21 ++ ) {
if ( sscanf ( V_6 -> V_2 -> V_124 [ V_21 ] ,
L_33 , & V_11 ) == 1 )
break;
if ( sscanf ( V_6 -> V_2 -> V_124 [ V_21 ] ,
L_34 , & V_11 ) == 1 )
break;
if ( ! strcmp ( V_6 -> V_2 -> V_124 [ V_21 ] , L_35 ) ) {
V_11 = V_12 ;
break;
}
}
if ( V_21 == V_6 -> V_2 -> V_123 ) {
F_26 ( L_36 ) ;
return - V_125 ;
}
V_2 = F_35 ( sizeof( struct V_1 ) , V_65 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = V_11 ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_2 -> V_7 = V_126 ;
break;
case V_13 :
V_2 -> V_7 = V_127 ;
break;
case V_14 :
default:
V_2 -> V_7 = V_128 ;
break;
}
F_83 ( & V_2 -> V_57 ) ;
V_2 -> V_109 = F_84 ( L_37 ) ;
F_85 ( & V_2 -> V_56 , F_27 ) ;
F_86 ( & V_2 -> V_87 ) ;
for ( V_21 = 0 ; V_21 < F_87 ( V_77 ) ; V_21 ++ ) {
if ( V_2 -> V_11 == V_77 [ V_21 ] . V_11 )
break;
}
if ( V_21 == F_87 ( V_77 ) ) {
F_26 ( L_38 , V_2 -> V_11 ) ;
V_4 = - V_125 ;
goto free;
}
F_88 ( V_6 , V_2 ) ;
F_7 ( L_39
L_40 ,
V_6 -> V_129 , V_6 -> V_130 , V_6 -> V_131 ,
V_11 , ( unsigned ) V_2 -> V_48 ) ;
V_19 = F_89 ( V_2 , & V_6 -> V_76 ) ;
if ( ! V_19 ) {
V_4 = - V_35 ;
goto free;
}
V_2 -> V_19 = V_19 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_132 = F_60 ;
V_19 -> V_133 = F_63 ;
V_19 -> V_134 = F_65 ;
V_19 -> V_135 = F_66 ;
V_19 -> V_136 = F_71 ;
V_19 -> V_137 = F_74 ;
V_19 -> V_138 = F_77 ;
V_4 = F_55 ( V_2 ) ;
if ( V_4 )
goto V_139;
V_25:
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
V_139:
F_75 ( V_2 -> V_109 ) ;
F_90 ( V_19 ) ;
free:
F_91 ( V_2 -> V_109 ) ;
while ( V_2 -> V_58 ) {
V_55 = V_2 -> V_58 ;
V_2 -> V_58 = V_2 -> V_58 -> V_59 ;
F_32 ( V_55 ) ;
}
F_32 ( V_2 ) ;
goto V_25;
}
static void F_92 ( struct V_78 * V_6 )
{
struct V_1 * V_2 ;
struct V_54 * V_55 ;
F_6 ( V_22 ) ;
V_2 = F_80 ( V_6 ) ;
F_93 ( & V_6 -> V_76 ) ;
if ( V_140 && ( V_2 -> V_11 == V_14 ) ) {
struct V_83 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_7 ( L_41 ) ;
if ( F_48 ( V_2 -> V_19 , V_141 ,
& V_84 , sizeof( V_84 ) , V_86 ,
( unsigned long ) & V_84 ) )
F_94 ( L_42 ) ;
}
F_7 ( L_43 ) ;
F_95 ( V_2 -> V_19 ) ;
F_90 ( V_2 -> V_19 ) ;
F_75 ( V_2 -> V_109 ) ;
F_91 ( V_2 -> V_109 ) ;
while ( V_2 -> V_58 ) {
V_55 = V_2 -> V_58 ;
V_2 -> V_58 = V_2 -> V_58 -> V_59 ;
F_32 ( V_55 ) ;
}
F_32 ( V_2 ) ;
F_33 ( V_22 ) ;
}
static int F_96 ( struct V_131 * V_76 )
{
struct V_78 * V_6 = F_97 ( V_76 ) ;
int V_4 ;
struct V_1 * V_2 = F_80 ( V_6 ) ;
T_5 V_20 = F_98 ( V_6 ) ;
if ( ! F_99 ( V_2 -> V_19 ) )
return - V_142 ;
F_100 ( V_76 , L_44 ,
F_101 ( V_6 ) , V_20 ) ;
if ( V_2 -> V_19 -> V_143 == V_144 ) {
F_100 ( V_76 , L_45 ) ;
return - V_142 ;
}
if ( ! ( V_20 & V_145 ) ) {
F_102 ( V_76 , L_46 ,
F_101 ( V_6 ) ) ;
return - V_142 ;
}
V_4 = F_103 ( V_6 , V_145 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_104 ( V_2 -> V_19 ) ;
if ( V_4 )
return V_4 ;
return F_103 ( V_6 , V_146 ) ;
}
static int F_105 ( struct V_131 * V_76 )
{
struct V_78 * V_6 = F_97 ( V_76 ) ;
struct V_1 * V_2 = F_80 ( V_6 ) ;
int V_4 ;
F_100 ( V_76 , L_47 , F_101 ( V_6 ) ) ;
V_4 = F_106 ( V_2 -> V_19 ) ;
return V_4 ;
}
static int T_6 F_107 ( void )
{
int V_4 = 0 ;
F_6 ( V_22 ) ;
F_108 ( V_147 L_48 ) ;
F_108 ( V_147 L_49 ) ;
V_4 = F_109 ( & V_148 ) ;
V_140 = 0 ;
F_12 ( V_22 , L_2 , V_4 ) ;
return V_4 ;
}
static void T_7 F_110 ( void )
{
F_6 ( V_22 ) ;
V_140 = 1 ;
F_111 ( & V_114 ) ;
F_112 ( & V_148 ) ;
F_33 ( V_22 ) ;
}
