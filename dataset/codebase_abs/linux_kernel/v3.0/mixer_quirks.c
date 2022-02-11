static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
const struct V_5 * V_6 = V_3 -> V_7 ;
T_1 V_8 ;
if ( V_1 -> V_9 < 0 || V_1 -> V_10 < V_6 -> V_11 )
return;
V_8 = V_3 -> V_12 [ V_6 -> V_13 ] ;
if ( V_6 -> V_14 == 2 )
V_8 |= V_3 -> V_12 [ V_6 -> V_13 + 1 ] << 8 ;
if ( V_8 == V_6 -> V_15 )
F_2 ( V_3 , V_6 -> V_16 ) ;
V_3 -> V_17 = V_8 ;
F_3 () ;
F_4 ( & V_3 -> V_18 ) ;
}
static long F_5 ( struct V_19 * V_20 , char T_2 * V_21 ,
long V_22 , T_3 * V_13 )
{
struct V_2 * V_3 = V_20 -> V_23 ;
int V_24 ;
T_1 V_17 ;
if ( V_22 != 1 && V_22 != 4 )
return - V_25 ;
V_24 = F_6 ( V_3 -> V_18 ,
( V_17 = F_7 ( & V_3 -> V_17 , 0 ) ) != 0 ) ;
if ( V_24 == 0 ) {
if ( V_22 == 1 )
V_24 = F_8 ( V_17 , V_21 ) ;
else
V_24 = F_8 ( V_17 , ( T_1 T_2 * ) V_21 ) ;
}
return V_24 < 0 ? V_24 : V_22 ;
}
static unsigned int F_9 ( struct V_19 * V_20 , struct V_26 * V_26 ,
T_4 * V_27 )
{
struct V_2 * V_3 = V_20 -> V_23 ;
F_10 ( V_26 , & V_3 -> V_18 , V_27 ) ;
return V_3 -> V_17 ? V_28 | V_29 : 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_19 * V_30 ;
int V_24 , V_31 , V_32 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_33 ) ; ++ V_32 )
if ( V_33 [ V_32 ] . V_34 == V_3 -> V_35 -> V_34 )
break;
if ( V_32 >= F_12 ( V_33 ) )
return 0 ;
V_3 -> V_7 = & V_33 [ V_32 ] ;
V_31 = V_3 -> V_7 -> V_36 ;
F_13 ( & V_3 -> V_18 ) ;
V_24 = F_14 ( V_3 -> V_35 -> V_37 , L_1 , 0 , & V_30 ) ;
if ( V_24 < 0 )
return V_24 ;
snprintf ( V_30 -> V_38 , sizeof( V_30 -> V_38 ) ,
L_2 , V_3 -> V_35 -> V_37 -> V_39 ) ;
V_30 -> V_40 = V_41 ;
V_30 -> V_23 = V_3 ;
V_30 -> V_42 . V_43 = F_5 ;
V_30 -> V_42 . V_44 = F_9 ;
V_30 -> V_45 = 1 ;
V_3 -> V_46 = F_15 ( 0 , V_47 ) ;
if ( ! V_3 -> V_46 )
return - V_48 ;
V_3 -> V_49 = F_16 ( sizeof( * V_3 -> V_49 ) , V_47 ) ;
if ( ! V_3 -> V_49 ) {
F_17 ( V_3 -> V_46 ) ;
V_3 -> V_46 = NULL ;
return - V_48 ;
}
V_3 -> V_49 -> V_50 =
V_51 | V_52 | V_53 ;
V_3 -> V_49 -> V_54 = V_55 ;
V_3 -> V_49 -> V_56 = F_18 ( 0 ) ;
V_3 -> V_49 -> V_57 = F_18 ( 0 ) ;
V_3 -> V_49 -> V_58 = F_18 ( V_31 ) ;
F_19 ( V_3 -> V_46 , V_3 -> V_35 -> V_59 ,
F_20 ( V_3 -> V_35 -> V_59 , 0 ) ,
( V_60 * ) V_3 -> V_49 , V_3 -> V_12 , V_31 ,
F_1 , V_3 ) ;
return 0 ;
}
static int F_21 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
int V_65 = V_62 -> V_66 ;
V_64 -> V_67 . integer . V_67 [ 0 ] = V_3 -> V_68 [ V_65 ] ;
return 0 ;
}
static int F_23 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
int V_65 = V_62 -> V_66 ;
int V_67 = V_64 -> V_67 . integer . V_67 [ 0 ] ;
int V_24 , V_69 ;
if ( V_67 > 1 )
return - V_25 ;
V_69 = V_67 != V_3 -> V_68 [ V_65 ] ;
if ( V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3042 ) )
V_24 = F_25 ( V_3 -> V_35 -> V_59 ,
F_26 ( V_3 -> V_35 -> V_59 , 0 ) , 0x24 ,
V_70 | V_71 | V_72 ,
! V_67 , 0 , NULL , 0 , 100 ) ;
if ( V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x30df ) )
V_24 = F_25 ( V_3 -> V_35 -> V_59 ,
F_26 ( V_3 -> V_35 -> V_59 , 0 ) , 0x24 ,
V_70 | V_71 | V_72 ,
! V_67 , 0 , NULL , 0 , 100 ) ;
else
V_24 = F_25 ( V_3 -> V_35 -> V_59 ,
F_26 ( V_3 -> V_35 -> V_59 , 0 ) , 0x24 ,
V_70 | V_71 | V_72 ,
V_67 , V_65 + 2 , NULL , 0 , 100 ) ;
if ( V_24 < 0 )
return V_24 ;
V_3 -> V_68 [ V_65 ] = V_67 ;
return V_69 ;
}
static int F_27 ( struct V_2 * V_3 )
{
int V_32 , V_24 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_73 ) ; ++ V_32 ) {
if ( ( V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3042 ) ) && V_32 == 0 )
continue;
if ( ( V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x30df ) ) && V_32 == 0 )
continue;
if ( V_32 > 1 &&
( V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3040 ) ||
V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3042 ) ||
V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x30df ) ||
V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3048 ) ) )
break;
V_24 = F_28 ( V_3 -> V_35 -> V_37 ,
F_29 ( & V_73 [ V_32 ] , V_3 ) ) ;
if ( V_24 < 0 )
return V_24 ;
}
V_3 -> V_68 [ 1 ] = 1 ;
return 0 ;
}
static void F_30 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
static const struct V_78 {
int V_79 ;
const char * V_38 ;
} V_80 [] = {
{ 4 , L_3 } ,
{ 7 , L_4 } ,
{ 19 , L_5 } ,
{ 20 , L_6 } ,
{ - 1 , NULL }
} , V_81 [] = {
{ 4 , L_4 } ,
{ 3 , L_6 } ,
{ 0 , L_7 } ,
{ - 1 , NULL }
} ;
const struct V_78 * V_82 ;
struct V_2 * V_3 = V_75 -> V_23 ;
int V_32 , V_24 ;
V_60 V_21 [ 3 ] ;
F_31 ( V_77 , L_8 , V_3 -> V_35 -> V_37 -> V_39 ) ;
if ( V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3020 ) )
V_82 = V_80 ;
else if ( V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3040 ) ||
V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3048 ) )
V_82 = V_81 ;
else
return;
for ( V_32 = 0 ; V_82 [ V_32 ] . V_38 ; ++ V_32 ) {
F_31 ( V_77 , L_9 , V_82 [ V_32 ] . V_38 ) ;
V_24 = F_25 ( V_3 -> V_35 -> V_59 ,
F_20 ( V_3 -> V_35 -> V_59 , 0 ) ,
V_55 , V_51 | V_52 |
V_53 , 0 ,
V_82 [ V_32 ] . V_79 << 8 , V_21 , 3 , 100 ) ;
if ( V_24 == 3 && ( V_21 [ 0 ] == 3 || V_21 [ 0 ] == 6 ) )
F_31 ( V_77 , L_10 , V_21 [ 1 ] , V_21 [ 2 ] ) ;
else
F_31 ( V_77 , L_11 ) ;
}
}
static int F_32 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
V_64 -> V_67 . integer . V_67 [ 0 ] = ! ! ( V_3 -> V_83 & 0x02 ) ;
return 0 ;
}
static int F_33 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
V_60 V_84 , V_85 ;
int V_24 , V_69 ;
V_84 = V_3 -> V_83 ;
if ( V_64 -> V_67 . integer . V_67 [ 0 ] )
V_85 = V_84 | 0x02 ;
else
V_85 = V_84 & ~ 0x02 ;
V_69 = V_85 != V_84 ;
V_24 = F_25 ( V_3 -> V_35 -> V_59 ,
F_26 ( V_3 -> V_35 -> V_59 , 0 ) , 0x08 ,
V_70 | V_71 | V_72 ,
50 , 0 , & V_85 , 1 , 100 ) ;
if ( V_24 < 0 )
return V_24 ;
V_3 -> V_83 = V_85 ;
return V_69 ;
}
static int F_34 ( struct V_2 * V_3 )
{
int V_24 ;
V_24 = F_28 ( V_3 -> V_35 -> V_37 ,
F_29 ( & V_86 , V_3 ) ) ;
if ( V_24 < 0 )
return V_24 ;
V_3 -> V_83 = 0x05 ;
return 0 ;
}
static int F_35 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_87 * V_59 = V_3 -> V_35 -> V_59 ;
V_60 V_54 = ( V_62 -> V_66 >> 16 ) & 0xff ;
T_5 V_57 = V_62 -> V_66 & 0xffff ;
V_60 V_88 ;
int V_89 = F_36 ( V_59 , F_20 ( V_59 , 0 ) , V_54 ,
V_71 | V_90 | V_51 ,
0 , F_18 ( V_57 ) ,
& V_88 , sizeof( V_88 ) , 1000 ) ;
if ( V_89 < 0 ) {
F_37 ( V_91
L_12 , V_89 ) ;
return V_89 ;
}
V_64 -> V_67 . integer . V_67 [ 0 ] = V_88 ;
return 0 ;
}
static int F_38 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_87 * V_59 = V_3 -> V_35 -> V_59 ;
V_60 V_54 = ( V_62 -> V_66 >> 16 ) & 0xff ;
T_5 V_57 = V_62 -> V_66 & 0xffff ;
T_5 V_56 = V_64 -> V_67 . integer . V_67 [ 0 ] ;
int V_89 = F_36 ( V_59 , F_26 ( V_59 , 0 ) , V_54 ,
V_71 | V_90 | V_70 ,
F_18 ( V_56 ) , F_18 ( V_57 ) ,
NULL , 0 , 1000 ) ;
if ( V_89 < 0 ) {
F_37 ( V_91
L_13 , V_89 ) ;
return V_89 ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
const struct V_92 * V_93 ,
unsigned int V_22 )
{
int V_32 , V_24 = 0 ;
struct V_92 V_94 = {
. V_40 = V_95 ,
. V_96 = V_97 ,
. V_98 = F_35 ,
. V_99 = F_38 ,
. V_100 = V_101 ,
} ;
for ( V_32 = 0 ; V_32 < V_22 ; V_32 ++ ) {
struct V_61 * V_102 ;
V_94 . V_38 = V_93 [ V_32 ] . V_38 ;
V_94 . V_66 = V_93 [ V_32 ] . V_66 ;
V_102 = F_29 ( & V_94 , V_3 ) ;
V_24 = F_28 ( V_3 -> V_35 -> V_37 , V_102 ) ;
if ( V_24 < 0 )
break;
}
return V_24 ;
}
static void F_40 ( struct V_61 * V_103 )
{
F_41 ( V_103 -> V_23 ) ;
V_103 -> V_23 = NULL ;
}
static int F_42 ( struct V_2 * V_3 ,
int V_104 , int V_105 , const char * V_38 )
{
struct V_106 * V_107 ;
struct V_61 * V_103 ;
V_107 = F_43 ( sizeof( * V_107 ) , V_47 ) ;
if ( ! V_107 )
return - V_48 ;
V_107 -> V_108 = 5 ;
V_107 -> V_3 = V_3 ;
V_107 -> V_109 = V_110 ;
V_107 -> V_111 = 1 ;
V_107 -> V_112 = V_105 + 1 ;
V_107 -> V_113 = 1 << V_104 ;
V_103 = F_29 ( V_114 , V_107 ) ;
if ( ! V_103 ) {
F_41 ( V_107 ) ;
return - V_48 ;
}
snprintf ( V_103 -> V_108 . V_38 , sizeof( V_103 -> V_108 . V_38 ) , V_38 ) ;
V_103 -> V_115 = F_40 ;
return F_44 ( V_3 , V_103 ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
char V_38 [ 64 ] ;
int V_104 , V_105 , V_24 ;
for ( V_105 = 0 ; V_105 < 8 ; V_105 ++ ) {
for ( V_104 = 0 ; V_104 < 8 ; V_104 ++ ) {
snprintf ( V_38 , sizeof( V_38 ) ,
L_14 , V_104 + 1 , V_105 + 1 ) ;
V_24 = F_42 ( V_3 , V_104 , V_105 , V_38 ) ;
if ( V_24 < 0 )
return V_24 ;
}
for ( V_104 = 8 ; V_104 < 16 ; V_104 ++ ) {
snprintf ( V_38 , sizeof( V_38 ) ,
L_15 , V_104 - 7 , V_105 + 1 ) ;
V_24 = F_42 ( V_3 , V_104 , V_105 , V_38 ) ;
if ( V_24 < 0 )
return V_24 ;
}
}
return 0 ;
}
void F_46 ( struct V_116 * V_35 ,
unsigned char V_117 )
{
struct V_2 * V_3 ;
struct V_106 * V_107 ;
int V_79 = 12 ;
F_47 (mixer, &chip->mixer_list, list) {
V_107 = V_3 -> V_118 [ V_79 ] ;
if ( V_107 ) {
F_48 ( V_107 , V_119 ,
V_107 -> V_112 << 8 ,
V_117 ) ;
F_2 ( V_3 , V_79 ) ;
}
break;
}
}
int F_49 ( struct V_2 * V_3 )
{
int V_24 = 0 ;
struct V_74 * V_75 ;
if ( ( V_24 = F_11 ( V_3 ) ) < 0 )
return V_24 ;
switch ( V_3 -> V_35 -> V_34 ) {
case F_24 ( 0x041e , 0x3020 ) :
case F_24 ( 0x041e , 0x3040 ) :
case F_24 ( 0x041e , 0x3042 ) :
case F_24 ( 0x041e , 0x30df ) :
case F_24 ( 0x041e , 0x3048 ) :
V_24 = F_27 ( V_3 ) ;
if ( V_24 < 0 )
break;
if ( ! F_50 ( V_3 -> V_35 -> V_37 , L_16 , & V_75 ) )
F_51 ( V_75 , V_3 ,
F_30 ) ;
break;
case F_24 ( 0x0763 , 0x2080 ) :
case F_24 ( 0x0763 , 0x2081 ) :
V_24 = F_45 ( V_3 ) ;
break;
case F_24 ( 0x0b05 , 0x1739 ) :
case F_24 ( 0x0b05 , 0x1743 ) :
V_24 = F_34 ( V_3 ) ;
break;
case F_24 ( 0x17cc , 0x1011 ) :
V_24 = F_39 ( V_3 ,
V_120 ,
F_12 ( V_120 ) ) ;
break;
case F_24 ( 0x17cc , 0x1021 ) :
V_24 = F_39 ( V_3 ,
V_121 ,
F_12 ( V_121 ) ) ;
break;
}
return V_24 ;
}
void F_52 ( struct V_2 * V_3 ,
int V_79 )
{
if ( ! V_3 -> V_7 )
return;
switch ( V_79 ) {
case 0 :
V_3 -> V_46 -> V_59 = V_3 -> V_35 -> V_59 ;
F_53 ( V_3 -> V_46 , V_122 ) ;
break;
case 4 :
case 7 :
case 19 :
case 20 :
break;
case 3 :
if ( V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3040 ) ||
V_3 -> V_35 -> V_34 == F_24 ( 0x041e , 0x3048 ) )
F_2 ( V_3 , V_3 -> V_7 -> V_16 ) ;
break;
default:
F_54 ( V_123 L_17 , V_79 ) ;
break;
}
}
