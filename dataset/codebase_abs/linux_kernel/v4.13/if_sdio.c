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
if ( V_17 > V_22 ) {
F_6 ( L_1 ,
( int ) V_17 ) ;
V_4 = - V_23 ;
goto V_24;
}
F_7 ( & V_19 -> V_25 , V_20 ) ;
V_21 = ( V_19 -> V_26 == 0 ) ? 1 : 0 ;
F_8 ( V_19 -> V_27 [ V_21 ] ) ;
V_19 -> V_27 [ V_21 ] = V_17 ;
memcpy ( V_19 -> V_28 [ V_21 ] , V_16 , V_17 ) ;
F_9 ( V_19 , V_21 ) ;
F_10 ( & V_19 -> V_25 , V_20 ) ;
V_4 = 0 ;
V_24:
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 * V_16 , unsigned V_17 )
{
int V_4 ;
struct V_29 * V_30 ;
if ( V_17 > V_31 ) {
F_6 ( L_1 ,
( int ) V_17 ) ;
V_4 = - V_23 ;
goto V_24;
}
V_30 = F_12 ( V_31 + V_32 ) ;
if ( ! V_30 ) {
V_4 = - V_33 ;
goto V_24;
}
F_13 ( V_30 , V_32 ) ;
F_14 ( V_30 , V_16 , V_17 ) ;
F_15 ( V_2 -> V_19 , V_30 ) ;
V_4 = 0 ;
V_24:
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_2 * V_16 , unsigned V_17 )
{
int V_4 ;
T_3 V_34 ;
if ( V_2 -> V_11 == V_12 ) {
V_34 = F_2 ( V_2 -> V_6 , V_35 , & V_4 ) ;
if ( V_4 )
goto V_24;
V_34 >>= 3 ;
} else {
if ( V_17 < 4 ) {
F_6 ( L_2 ,
( int ) V_17 ) ;
V_4 = - V_36 ;
goto V_24;
}
V_34 = V_16 [ 3 ] << 24 ;
V_34 |= V_16 [ 2 ] << 16 ;
V_34 |= V_16 [ 1 ] << 8 ;
V_34 |= V_16 [ 0 ] << 0 ;
}
F_17 ( V_2 -> V_19 , V_34 & 0xFF ) ;
V_4 = 0 ;
V_24:
return V_4 ;
}
static int F_18 ( struct V_1 * V_2 , const T_2 V_37 )
{
T_2 V_38 ;
unsigned long V_39 ;
int V_4 = 0 ;
V_39 = V_40 + V_41 ;
while ( 1 ) {
V_38 = F_2 ( V_2 -> V_6 , V_42 , & V_4 ) ;
if ( V_4 )
return V_4 ;
if ( ( V_38 & V_37 ) == V_37 )
break;
if ( F_19 ( V_40 , V_39 ) )
return - V_43 ;
F_20 ( 1 ) ;
}
return V_4 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_17 , type , V_44 ;
V_17 = F_4 ( V_2 , & V_4 ) ;
if ( V_4 )
goto V_24;
if ( V_17 < 4 ) {
F_6 ( L_3 ,
( int ) V_17 ) ;
V_4 = - V_36 ;
goto V_24;
}
V_4 = F_18 ( V_2 , V_45 ) ;
if ( V_4 )
goto V_24;
V_44 = F_22 ( V_2 -> V_6 , V_17 ) ;
V_4 = F_23 ( V_2 -> V_6 , V_2 -> V_16 , V_2 -> V_46 , V_44 ) ;
if ( V_4 )
goto V_24;
V_44 = V_2 -> V_16 [ 0 ] | ( V_2 -> V_16 [ 1 ] << 8 ) ;
type = V_2 -> V_16 [ 2 ] | ( V_2 -> V_16 [ 3 ] << 8 ) ;
F_6 ( L_4 ,
( int ) type , ( int ) V_44 ) ;
if ( V_44 > V_17 ) {
F_6 ( L_5 ,
( int ) V_44 , ( int ) V_17 ) ;
V_4 = - V_36 ;
goto V_24;
}
if ( V_44 < V_17 ) {
F_6 ( L_6 ,
( int ) V_44 , ( int ) V_17 ) ;
}
switch ( type ) {
case V_47 :
V_4 = F_5 ( V_2 , V_2 -> V_16 + 4 , V_44 - 4 ) ;
if ( V_4 )
goto V_24;
break;
case V_48 :
V_4 = F_11 ( V_2 , V_2 -> V_16 + 4 , V_44 - 4 ) ;
if ( V_4 )
goto V_24;
break;
case V_49 :
V_4 = F_16 ( V_2 , V_2 -> V_16 + 4 , V_44 - 4 ) ;
if ( V_4 )
goto V_24;
break;
default:
F_6 ( L_7 ,
( int ) type ) ;
V_4 = - V_36 ;
goto V_24;
}
V_24:
if ( V_4 )
F_24 ( L_8 ) ;
return V_4 ;
}
static void F_25 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
int V_4 ;
unsigned long V_20 ;
V_2 = F_26 ( V_51 , struct V_1 , V_54 ) ;
while ( 1 ) {
F_7 ( & V_2 -> V_55 , V_20 ) ;
V_53 = V_2 -> V_56 ;
if ( V_53 )
V_2 -> V_56 = V_53 -> V_57 ;
F_10 ( & V_2 -> V_55 , V_20 ) ;
if ( ! V_53 )
break;
F_27 ( V_2 -> V_6 ) ;
V_4 = F_18 ( V_2 , V_45 ) ;
if ( V_4 == 0 ) {
V_4 = F_28 ( V_2 -> V_6 , V_2 -> V_46 ,
V_53 -> V_16 , V_53 -> V_58 ) ;
}
if ( V_4 )
F_24 ( L_9 , V_4 ) ;
F_29 ( V_2 -> V_6 ) ;
F_30 ( V_53 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_59 * V_60 )
{
int V_4 ;
unsigned long V_39 ;
T_2 * V_61 ;
T_3 V_62 ;
const T_2 * V_59 ;
T_4 V_17 ;
V_61 = F_32 ( 64 , V_63 ) ;
if ( ! V_61 ) {
V_4 = - V_33 ;
goto V_24;
}
F_27 ( V_2 -> V_6 ) ;
V_4 = F_33 ( V_2 -> V_6 , 32 ) ;
if ( V_4 )
goto V_64;
V_59 = V_60 -> V_65 ;
V_17 = V_60 -> V_17 ;
while ( V_17 ) {
V_4 = F_18 ( V_2 , V_66 ) ;
if ( V_4 )
goto V_64;
F_20 ( 2 ) ;
V_62 = F_34 ( T_4 , V_17 , 60 ) ;
* ( ( V_67 * ) V_61 ) = F_35 ( V_62 ) ;
memcpy ( V_61 + 4 , V_59 , V_62 ) ;
V_4 = F_28 ( V_2 -> V_6 , V_2 -> V_46 ,
V_61 , 64 ) ;
if ( V_4 )
goto V_64;
V_59 += V_62 ;
V_17 -= V_62 ;
}
memset ( V_61 , 0 , 4 ) ;
V_4 = F_28 ( V_2 -> V_6 , V_2 -> V_46 , V_61 , 64 ) ;
if ( V_4 )
goto V_64;
F_6 ( L_10 ) ;
V_39 = V_40 + V_41 ;
while ( 1 ) {
T_1 V_68 ;
V_68 = F_2 ( V_2 -> V_6 , V_69 , & V_4 ) ;
if ( V_4 )
goto V_64;
V_68 |= F_2 ( V_2 -> V_6 , V_69 + 1 , & V_4 ) << 8 ;
if ( V_4 )
goto V_64;
if ( V_68 != 0 )
break;
if ( F_19 ( V_40 , V_39 ) ) {
V_4 = - V_43 ;
goto V_64;
}
F_36 ( 10 ) ;
}
V_4 = 0 ;
V_64:
F_29 ( V_2 -> V_6 ) ;
F_30 ( V_61 ) ;
V_24:
if ( V_4 )
F_24 ( L_11 ) ;
return V_4 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_59 * V_60 )
{
int V_4 ;
unsigned long V_39 ;
T_2 * V_61 ;
T_3 V_62 ;
const T_2 * V_59 ;
T_4 V_17 , V_68 ;
V_61 = F_32 ( 512 , V_63 ) ;
if ( ! V_61 ) {
V_4 = - V_33 ;
goto V_24;
}
F_27 ( V_2 -> V_6 ) ;
V_4 = F_33 ( V_2 -> V_6 , 32 ) ;
if ( V_4 )
goto V_64;
V_59 = V_60 -> V_65 ;
V_17 = V_60 -> V_17 ;
while ( V_17 ) {
V_39 = V_40 + V_41 ;
while ( 1 ) {
V_4 = F_18 ( V_2 , V_66 ) ;
if ( V_4 )
goto V_64;
V_68 = F_2 ( V_2 -> V_6 , V_69 ,
& V_4 ) ;
if ( V_4 )
goto V_64;
V_68 |= F_2 ( V_2 -> V_6 , V_69 + 1 ,
& V_4 ) << 8 ;
if ( V_4 )
goto V_64;
if ( ( V_17 != V_60 -> V_17 ) || ( V_68 > 2 ) )
break;
if ( F_19 ( V_40 , V_39 ) ) {
V_4 = - V_43 ;
goto V_64;
}
F_20 ( 1 ) ;
}
if ( V_68 == 0 ) {
F_6 ( L_12 ) ;
V_4 = - V_70 ;
goto V_64;
}
if ( V_68 & 0x01 ) {
F_6 ( L_13 ) ;
V_4 = - V_70 ;
goto V_64;
}
if ( V_68 > V_17 )
V_68 = V_17 ;
while ( V_68 ) {
V_62 = F_34 ( T_4 , V_68 , 512 ) ;
memcpy ( V_61 , V_59 , V_62 ) ;
V_4 = F_28 ( V_2 -> V_6 , V_2 -> V_46 ,
V_61 , F_38 ( V_62 , 32 ) ) ;
if ( V_4 )
goto V_64;
V_59 += V_62 ;
V_17 -= V_62 ;
V_68 -= V_62 ;
}
}
V_4 = 0 ;
F_6 ( L_14 ) ;
V_39 = V_40 + V_41 ;
while ( 1 ) {
T_1 V_5 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_4 )
goto V_64;
if ( V_5 == V_71 )
break;
if ( F_19 ( V_40 , V_39 ) ) {
V_4 = - V_43 ;
goto V_64;
}
F_36 ( 10 ) ;
}
V_4 = 0 ;
V_64:
F_29 ( V_2 -> V_6 ) ;
F_30 ( V_61 ) ;
V_24:
if ( V_4 )
F_24 ( L_15 ) ;
return V_4 ;
}
static void F_39 ( struct V_18 * V_19 , int V_4 ,
const struct V_59 * V_72 ,
const struct V_59 * V_73 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_4 ) {
F_24 ( L_16 , V_4 ) ;
return;
}
V_4 = F_31 ( V_2 , V_72 ) ;
if ( V_4 )
return;
F_6 ( L_17 ) ;
V_4 = F_37 ( V_2 , V_73 ) ;
if ( V_4 )
return;
F_6 ( L_18 ) ;
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_5 ;
F_27 ( V_2 -> V_6 ) ;
F_42 ( V_2 -> V_6 , 0x00 , V_74 , & V_4 ) ;
F_29 ( V_2 -> V_6 ) ;
F_27 ( V_2 -> V_6 ) ;
V_5 = F_1 ( V_2 , & V_4 ) ;
F_29 ( V_2 -> V_6 ) ;
F_6 ( L_19 , V_5 ) ;
F_6 ( L_20 , V_4 ) ;
if ( V_4 )
goto V_24;
if ( V_5 == V_71 ) {
F_6 ( L_21 ) ;
F_40 ( V_2 ) ;
return 0 ;
} else if ( ( V_2 -> V_11 == V_13 ) && ( V_5 & 0x7fff ) ) {
F_6 ( L_22 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
V_4 = F_43 ( V_2 -> V_19 , & V_2 -> V_6 -> V_75 , V_2 -> V_11 ,
V_76 , F_39 ) ;
V_24:
return V_4 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_77 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 = V_2 -> V_19 ;
int V_4 ;
F_27 ( V_6 ) ;
F_33 ( V_2 -> V_6 , V_78 ) ;
if ( ( V_2 -> V_11 != V_12 )
&& ( V_2 -> V_11 != V_13 ) )
V_2 -> V_8 = F_3 ( V_2 ) ;
else
V_2 -> V_8 = 0 ;
V_4 = F_44 ( V_6 , V_79 ) ;
if ( V_4 )
goto V_64;
F_42 ( V_6 , 0x0f , V_74 , & V_4 ) ;
if ( V_4 )
goto V_80;
F_29 ( V_6 ) ;
V_19 -> V_81 = 1 ;
if ( V_2 -> V_11 == V_14 ) {
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
F_6 ( L_23 ) ;
if ( F_45 ( V_19 , V_84 , & V_83 , sizeof( V_83 ) ,
V_85 , ( unsigned long ) & V_83 ) )
F_46 ( V_19 -> V_75 , L_24 ) ;
}
F_47 ( & V_2 -> V_86 ) ;
if ( ! V_2 -> V_87 ) {
V_4 = F_48 ( V_19 ) ;
F_49 ( V_2 ) ;
if ( V_4 == 0 ) {
V_2 -> V_87 = true ;
F_50 ( & V_6 -> V_75 ) ;
}
}
return;
V_80:
F_51 ( V_6 ) ;
V_64:
F_29 ( V_6 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_77 * V_6 = V_2 -> V_6 ;
struct V_88 * V_89 = V_6 -> V_2 -> V_89 ;
int V_4 ;
F_27 ( V_6 ) ;
V_4 = F_53 ( V_6 ) ;
if ( V_4 )
goto V_64;
if ( ( V_2 -> V_11 == V_13 ) &&
( V_89 -> V_90 & V_91 ) &&
( V_89 -> V_92 . V_93 == V_94 ) ) {
T_2 V_95 ;
V_6 -> V_2 -> V_96 |= V_97 ;
V_95 = F_54 ( V_6 , V_98 , & V_4 ) ;
if ( V_4 )
goto V_99;
V_95 |= V_100 ;
F_55 ( V_6 , V_95 , V_98 , & V_4 ) ;
if ( V_4 )
goto V_99;
}
V_2 -> V_46 = F_2 ( V_6 , V_101 , & V_4 ) ;
if ( V_4 )
goto V_99;
V_2 -> V_46 |= F_2 ( V_6 , V_101 + 1 , & V_4 ) << 8 ;
if ( V_4 )
goto V_99;
V_2 -> V_46 |= F_2 ( V_6 , V_101 + 2 , & V_4 ) << 16 ;
if ( V_4 )
goto V_99;
F_29 ( V_6 ) ;
V_4 = F_41 ( V_2 ) ;
if ( V_4 ) {
F_27 ( V_6 ) ;
goto V_99;
}
return 0 ;
V_99:
F_56 ( V_6 ) ;
V_64:
F_29 ( V_6 ) ;
return V_4 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_77 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 = V_2 -> V_19 ;
V_19 -> V_81 = 0 ;
F_27 ( V_6 ) ;
F_51 ( V_6 ) ;
F_56 ( V_6 ) ;
F_29 ( V_6 ) ;
return 0 ;
}
static int F_57 ( struct V_18 * V_19 ,
T_2 type , T_2 * V_102 , T_1 V_58 )
{
int V_4 ;
struct V_1 * V_2 ;
struct V_52 * V_53 , * V_103 ;
T_1 V_17 ;
unsigned long V_20 ;
V_2 = V_19 -> V_2 ;
if ( V_58 > ( 65536 - sizeof( struct V_52 ) - 4 ) ) {
V_4 = - V_36 ;
goto V_24;
}
V_17 = F_22 ( V_2 -> V_6 , V_58 + 4 ) ;
V_53 = F_32 ( sizeof( struct V_52 ) + V_17 ,
V_104 ) ;
if ( ! V_53 ) {
V_4 = - V_33 ;
goto V_24;
}
V_53 -> V_57 = NULL ;
V_53 -> V_58 = V_17 ;
V_53 -> V_16 [ 0 ] = ( V_58 + 4 ) & 0xff ;
V_53 -> V_16 [ 1 ] = ( ( V_58 + 4 ) >> 8 ) & 0xff ;
V_53 -> V_16 [ 2 ] = type ;
V_53 -> V_16 [ 3 ] = 0 ;
memcpy ( V_53 -> V_16 + 4 , V_102 , V_58 ) ;
F_7 ( & V_2 -> V_55 , V_20 ) ;
if ( ! V_2 -> V_56 )
V_2 -> V_56 = V_53 ;
else {
V_103 = V_2 -> V_56 ;
while ( V_103 -> V_57 )
V_103 = V_103 -> V_57 ;
V_103 -> V_57 = V_53 ;
}
switch ( type ) {
case V_47 :
V_19 -> V_105 = V_106 ;
break;
case V_48 :
V_19 -> V_105 = V_107 ;
break;
default:
F_6 ( L_25 , ( int ) type ) ;
}
F_10 ( & V_2 -> V_55 , V_20 ) ;
F_58 ( V_2 -> V_108 , & V_2 -> V_54 ) ;
V_4 = 0 ;
V_24:
return V_4 ;
}
static int F_59 ( struct V_18 * V_19 )
{
int V_4 = - 1 ;
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
F_6 ( L_26 ) ;
V_4 = F_45 ( V_19 , V_109 , & V_83 , sizeof( V_83 ) ,
V_85 , ( unsigned long ) & V_83 ) ;
if ( V_4 )
F_60 ( V_19 -> V_75 , L_27 ) ;
F_20 ( 200 ) ;
return V_4 ;
}
static int F_61 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = - 1 ;
F_27 ( V_2 -> V_6 ) ;
F_42 ( V_2 -> V_6 , V_110 , V_111 , & V_4 ) ;
if ( V_4 )
F_60 ( V_19 -> V_75 , L_28 ) ;
F_29 ( V_2 -> V_6 ) ;
return V_4 ;
}
static int F_62 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = - 1 ;
F_27 ( V_2 -> V_6 ) ;
F_42 ( V_2 -> V_6 , 0 , V_111 , & V_4 ) ;
if ( V_4 )
F_60 ( V_19 -> V_75 , L_28 ) ;
F_29 ( V_2 -> V_6 ) ;
return V_4 ;
}
static void F_63 ( struct V_50 * V_51 )
{
F_64 ( L_29 ) ;
F_65 ( V_112 ) ;
F_66 ( V_112 ) ;
}
static void F_67 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( F_68 ( & V_113 ) )
return;
V_112 = V_2 -> V_6 -> V_2 -> V_89 ;
F_69 ( & V_113 ) ;
}
static int F_70 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
F_71 ( V_2 -> V_108 ) ;
V_4 = F_49 ( V_2 ) ;
F_72 ( & V_2 -> V_6 -> V_75 ) ;
return V_4 ;
}
static int F_73 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_114 ;
F_74 ( & V_2 -> V_6 -> V_75 ) ;
V_114 = F_52 ( V_2 ) ;
if ( V_114 )
return V_114 ;
F_75 ( V_2 -> V_86 , V_19 -> V_81 ) ;
return 0 ;
}
static void V_79 ( struct V_77 * V_6 )
{
int V_4 ;
struct V_1 * V_2 ;
T_2 V_115 ;
V_2 = F_76 ( V_6 ) ;
V_115 = F_2 ( V_2 -> V_6 , V_116 , & V_4 ) ;
if ( V_4 || ! V_115 )
return;
F_6 ( L_30 , ( unsigned ) V_115 ) ;
F_42 ( V_2 -> V_6 , ~ V_115 , V_116 , & V_4 ) ;
if ( V_4 )
return;
V_2 -> V_19 -> V_117 = 1 ;
if ( V_115 & V_118 )
F_77 ( V_2 -> V_19 ) ;
if ( V_115 & V_119 ) {
V_4 = F_21 ( V_2 ) ;
if ( V_4 )
return;
}
}
static int F_78 ( struct V_77 * V_6 ,
const struct V_120 * V_121 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_4 , V_21 ;
unsigned int V_11 ;
struct V_52 * V_53 ;
for ( V_21 = 0 ; V_21 < V_6 -> V_2 -> V_122 ; V_21 ++ ) {
if ( sscanf ( V_6 -> V_2 -> V_123 [ V_21 ] ,
L_31 , & V_11 ) == 1 )
break;
if ( sscanf ( V_6 -> V_2 -> V_123 [ V_21 ] ,
L_32 , & V_11 ) == 1 )
break;
if ( ! strcmp ( V_6 -> V_2 -> V_123 [ V_21 ] , L_33 ) ) {
V_11 = V_12 ;
break;
}
}
if ( V_21 == V_6 -> V_2 -> V_122 ) {
F_24 ( L_34 ) ;
return - V_124 ;
}
V_2 = F_32 ( sizeof( struct V_1 ) , V_63 ) ;
if ( ! V_2 )
return - V_33 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = V_11 ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_2 -> V_7 = V_125 ;
break;
case V_13 :
V_2 -> V_7 = V_126 ;
break;
case V_14 :
default:
V_2 -> V_7 = V_127 ;
break;
}
F_79 ( & V_2 -> V_55 ) ;
V_2 -> V_108 = F_80 ( L_35 , V_128 , 0 ) ;
F_81 ( & V_2 -> V_54 , F_25 ) ;
F_82 ( & V_2 -> V_86 ) ;
for ( V_21 = 0 ; V_21 < F_83 ( V_76 ) ; V_21 ++ ) {
if ( V_2 -> V_11 == V_76 [ V_21 ] . V_11 )
break;
}
if ( V_21 == F_83 ( V_76 ) ) {
F_24 ( L_36 , V_2 -> V_11 ) ;
V_4 = - V_124 ;
goto free;
}
F_84 ( V_6 , V_2 ) ;
F_6 ( L_37
L_38 ,
V_6 -> V_129 , V_6 -> V_130 , V_6 -> V_131 ,
V_11 , ( unsigned ) V_2 -> V_46 ) ;
V_19 = F_85 ( V_2 , & V_6 -> V_75 ) ;
if ( ! V_19 ) {
V_4 = - V_33 ;
goto free;
}
V_2 -> V_19 = V_19 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_132 = F_57 ;
V_19 -> V_133 = F_59 ;
V_19 -> V_134 = F_61 ;
V_19 -> V_135 = F_62 ;
V_19 -> V_136 = F_67 ;
V_19 -> V_137 = F_70 ;
V_19 -> V_138 = F_73 ;
V_19 -> V_139 = ! ( V_6 -> V_2 -> V_89 -> V_90 & V_91 ) ;
V_4 = F_52 ( V_2 ) ;
if ( V_4 )
goto V_140;
V_24:
return V_4 ;
V_140:
F_71 ( V_2 -> V_108 ) ;
F_86 ( V_19 ) ;
free:
F_87 ( V_2 -> V_108 ) ;
while ( V_2 -> V_56 ) {
V_53 = V_2 -> V_56 ;
V_2 -> V_56 = V_2 -> V_56 -> V_57 ;
F_30 ( V_53 ) ;
}
F_30 ( V_2 ) ;
goto V_24;
}
static void F_88 ( struct V_77 * V_6 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
V_2 = F_76 ( V_6 ) ;
F_89 ( & V_6 -> V_75 ) ;
if ( V_141 && ( V_2 -> V_11 == V_14 ) ) {
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
F_6 ( L_39 ) ;
if ( F_45 ( V_2 -> V_19 , V_142 ,
& V_83 , sizeof( V_83 ) , V_85 ,
( unsigned long ) & V_83 ) )
F_90 ( L_40 ) ;
}
F_6 ( L_41 ) ;
F_91 ( V_2 -> V_19 ) ;
F_86 ( V_2 -> V_19 ) ;
F_87 ( V_2 -> V_108 ) ;
while ( V_2 -> V_56 ) {
V_53 = V_2 -> V_56 ;
V_2 -> V_56 = V_2 -> V_56 -> V_57 ;
F_30 ( V_53 ) ;
}
F_30 ( V_2 ) ;
}
static int F_92 ( struct V_131 * V_75 )
{
struct V_77 * V_6 = F_93 ( V_75 ) ;
int V_4 ;
struct V_1 * V_2 = F_76 ( V_6 ) ;
T_5 V_20 = F_94 ( V_6 ) ;
if ( ! F_95 ( V_2 -> V_19 ) )
return - V_143 ;
F_96 ( V_75 , L_42 ,
F_97 ( V_6 ) , V_20 ) ;
if ( V_2 -> V_19 -> V_144 == V_145 ) {
F_96 ( V_75 , L_43 ) ;
return - V_143 ;
}
if ( ! ( V_20 & V_146 ) ) {
F_98 ( V_75 , L_44 ,
F_97 ( V_6 ) ) ;
return - V_143 ;
}
V_4 = F_99 ( V_6 , V_146 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_100 ( V_2 -> V_19 ) ;
if ( V_4 )
return V_4 ;
return F_99 ( V_6 , V_147 ) ;
}
static int F_101 ( struct V_131 * V_75 )
{
struct V_77 * V_6 = F_93 ( V_75 ) ;
struct V_1 * V_2 = F_76 ( V_6 ) ;
int V_4 ;
F_96 ( V_75 , L_45 , F_97 ( V_6 ) ) ;
V_4 = F_102 ( V_2 -> V_19 ) ;
return V_4 ;
}
static int T_6 F_103 ( void )
{
int V_4 = 0 ;
F_104 ( V_148 L_46 ) ;
F_104 ( V_148 L_47 ) ;
V_4 = F_105 ( & V_149 ) ;
V_141 = 0 ;
return V_4 ;
}
static void T_7 F_106 ( void )
{
V_141 = 1 ;
F_107 ( & V_113 ) ;
F_108 ( & V_149 ) ;
}
