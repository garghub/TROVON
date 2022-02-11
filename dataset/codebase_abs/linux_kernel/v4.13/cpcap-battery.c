static struct V_1 *
F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
if ( V_5 >= V_6 )
return NULL ;
return & V_3 -> V_5 [ V_5 ] ;
}
static struct V_1 *
F_2 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , V_7 ) ;
}
static struct V_1 *
F_3 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , V_8 ) ;
}
static int F_4 ( struct V_2 * V_3 ,
int * V_9 )
{
struct V_10 * V_11 ;
int error ;
V_11 = V_3 -> V_12 [ V_13 ] ;
error = F_5 ( V_11 , V_9 ) ;
if ( error < 0 ) {
F_6 ( V_3 -> V_14 , L_1 , V_15 , error ) ;
* V_9 = V_16 ;
return error ;
}
* V_9 /= 100 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_10 * V_11 ;
int error , V_9 = 0 ;
V_11 = V_3 -> V_12 [ V_17 ] ;
error = F_5 ( V_11 , & V_9 ) ;
if ( error < 0 ) {
F_6 ( V_3 -> V_14 , L_1 , V_15 , error ) ;
return 0 ;
}
return V_9 * 1000 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_11 ;
int error , V_9 = 0 ;
V_11 = V_3 -> V_12 [ V_18 ] ;
error = F_5 ( V_11 , & V_9 ) ;
if ( error < 0 ) {
F_6 ( V_3 -> V_14 , L_1 , V_15 , error ) ;
return 0 ;
}
return V_9 * 1000 ;
}
static int F_9 ( struct V_2 * V_3 ,
T_1 V_19 , T_2 V_20 ,
T_3 V_21 , T_1 V_22 )
{
T_4 V_23 ;
T_5 V_24 ;
int V_25 ;
T_1 V_26 ;
V_19 &= 0xffffff ;
V_21 &= 0x7ff ;
switch ( V_3 -> V_27 ) {
case V_28 :
V_26 = 95374 ;
break;
case V_29 :
V_26 = 91501 ;
break;
default:
return - V_30 ;
}
V_23 = V_20 ;
V_23 = V_23 - ( ( T_4 ) V_19 * V_21 ) ;
V_26 = ( V_26 * V_3 -> V_31 . V_32 ) / 1000 ;
if ( V_23 >= 0 )
V_24 = V_23 ;
else
V_24 = V_23 * - 1 ;
V_24 = V_24 * V_26 ;
F_10 ( V_24 , V_22 ) ;
V_25 = V_24 ;
if ( V_23 >= 0 )
return - V_25 ;
else
return V_25 ;
}
static int F_11 ( struct V_2 * V_3 ,
T_1 V_19 , T_2 V_20 ,
T_3 V_21 )
{
return F_9 ( V_3 , V_19 ,
V_20 , V_21 ,
3600000 ) ;
}
static int F_12 ( struct V_2 * V_3 ,
T_1 V_19 , T_2 V_20 ,
T_3 V_21 )
{
return F_9 ( V_3 , V_19 ,
V_20 , V_21 ,
V_19 *
V_33 ) ;
}
static int
F_13 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
T_6 V_36 [ 7 ] ;
int error ;
V_35 -> V_19 = 0 ;
V_35 -> V_20 = 0 ;
V_35 -> V_21 = 0 ;
error = F_14 ( V_3 -> V_37 , V_38 ,
V_36 , F_15 ( V_36 ) ) ;
if ( error )
return 0 ;
V_35 -> V_19 = ( V_36 [ 1 ] & 0x0fff ) << 16 ;
V_35 -> V_19 |= V_36 [ 0 ] ;
V_35 -> V_20 = ( ( T_3 ) V_36 [ 3 ] ) << 16 ;
V_35 -> V_20 |= V_36 [ 2 ] ;
V_35 -> V_21 = V_36 [ 5 ] ;
if ( V_36 [ 4 ] >= 0x200 )
V_35 -> V_21 |= 0xfc00 ;
return F_11 ( V_3 ,
V_35 -> V_19 ,
V_35 -> V_20 ,
V_35 -> V_21 ) ;
}
static int F_16 ( struct V_2 * V_3 )
{
int V_9 , V_23 , error ;
T_2 V_19 = 1 ;
T_3 V_21 ;
if ( V_3 -> V_27 == V_28 )
V_19 = 4 ;
error = F_17 ( V_3 -> V_37 , V_39 , & V_9 ) ;
if ( error )
return error ;
if ( ( V_3 -> V_27 == V_29 ) && ( V_9 > 0x2000 ) )
V_9 = V_9 | 0xc000 ;
V_23 = ( T_3 ) V_9 ;
error = F_17 ( V_3 -> V_37 , V_40 , & V_9 ) ;
if ( error )
return error ;
if ( V_9 < 0x200 )
V_21 = V_9 ;
else
V_21 = V_9 | 0xfc00 ;
return F_12 ( V_3 , V_19 , V_23 , V_21 ) ;
}
static bool F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_41 >= ( V_3 -> V_31 . V_42 . V_43 - 4000 ) )
return true ;
return false ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 V_5 , * V_44 , * V_45 ;
T_7 V_46 ;
int error ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_46 = F_20 () ;
V_44 = F_2 ( V_3 ) ;
if ( V_44 ) {
T_4 V_47 = F_21 ( F_22 ( V_46 , V_44 -> time ) ) ;
if ( V_47 < V_33 )
return V_47 ;
}
V_5 . time = V_46 ;
V_5 . V_41 = F_7 ( V_3 ) ;
V_5 . V_48 = F_8 ( V_3 ) ;
V_5 . V_49 = F_13 ( V_3 , & V_5 . V_50 ) ;
error = F_4 ( V_3 ,
& V_5 . V_51 ) ;
if ( error )
return error ;
V_45 = F_3 ( V_3 ) ;
memcpy ( V_45 , V_44 , sizeof( * V_45 ) ) ;
memcpy ( V_44 , & V_5 , sizeof( * V_44 ) ) ;
return 0 ;
}
static int F_23 ( struct V_52 * V_53 ,
enum V_54 V_55 ,
union V_56 * V_57 )
{
struct V_2 * V_3 = F_24 ( V_53 ) ;
struct V_1 * V_44 , * V_45 ;
T_1 V_19 ;
T_2 V_20 ;
int V_58 ;
T_4 V_24 ;
V_58 = F_19 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_44 = F_2 ( V_3 ) ;
V_45 = F_3 ( V_3 ) ;
switch ( V_55 ) {
case V_59 :
if ( V_44 -> V_51 > V_16 )
V_57 -> V_60 = 1 ;
else
V_57 -> V_60 = 0 ;
break;
case V_61 :
if ( F_18 ( V_3 ) ) {
V_57 -> V_60 = V_62 ;
break;
}
if ( F_16 ( V_3 ) < 0 )
V_57 -> V_60 = V_63 ;
else
V_57 -> V_60 = V_64 ;
break;
case V_65 :
V_57 -> V_60 = V_3 -> V_31 . V_42 . V_66 ;
break;
case V_67 :
V_57 -> V_60 = F_7 ( V_3 ) ;
break;
case V_68 :
V_57 -> V_60 = V_3 -> V_31 . V_42 . V_43 ;
break;
case V_69 :
V_57 -> V_60 = V_3 -> V_31 . V_42 . V_70 ;
break;
case V_71 :
if ( V_58 ) {
V_57 -> V_60 = F_16 ( V_3 ) ;
break;
}
V_19 = V_44 -> V_50 . V_19 - V_45 -> V_50 . V_19 ;
V_20 = V_44 -> V_50 . V_20 - V_45 -> V_50 . V_20 ;
V_57 -> V_60 = F_12 ( V_3 , V_19 ,
V_20 ,
V_44 -> V_50 . V_21 ) ;
break;
case V_72 :
V_57 -> V_60 = V_44 -> V_48 ;
break;
case V_73 :
V_57 -> V_60 = V_44 -> V_49 ;
break;
case V_74 :
V_24 = ( V_44 -> V_41 / 10000 ) * V_44 -> V_48 ;
V_57 -> V_60 = F_25 ( V_24 , 100 ) ;
break;
case V_75 :
if ( V_58 ) {
V_24 = F_16 ( V_3 ) ;
V_24 *= ( V_44 -> V_41 / 10000 ) ;
V_57 -> V_60 = F_25 ( V_24 , 100 ) ;
break;
}
V_19 = V_44 -> V_50 . V_19 - V_45 -> V_50 . V_19 ;
V_20 = V_44 -> V_50 . V_20 - V_45 -> V_50 . V_20 ;
V_24 = F_12 ( V_3 , V_19 , V_20 ,
V_44 -> V_50 . V_21 ) ;
V_24 *= ( ( V_44 -> V_41 + V_45 -> V_41 ) / 20000 ) ;
V_57 -> V_60 = F_25 ( V_24 , 100 ) ;
break;
case V_76 :
if ( F_18 ( V_3 ) )
V_57 -> V_60 = V_77 ;
else if ( V_44 -> V_41 >= 3750000 )
V_57 -> V_60 = V_78 ;
else if ( V_44 -> V_41 >= 3300000 )
V_57 -> V_60 = V_79 ;
else if ( V_44 -> V_41 > 3100000 )
V_57 -> V_60 = V_80 ;
else if ( V_44 -> V_41 <= 3100000 )
V_57 -> V_60 = V_81 ;
else
V_57 -> V_60 = V_82 ;
break;
case V_83 :
V_57 -> V_60 = V_3 -> V_31 . V_42 . V_84 ;
break;
case V_85 :
V_57 -> V_60 = V_86 ;
break;
case V_87 :
V_57 -> V_60 = V_44 -> V_51 ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static T_8 F_26 ( int V_88 , void * V_89 )
{
struct V_2 * V_3 = V_89 ;
struct V_1 * V_44 ;
struct V_90 * V_91 ;
if ( ! F_27 ( & V_3 -> V_92 ) )
return V_93 ;
F_28 (d, &ddata->irq_list, node) {
if ( V_88 == V_91 -> V_88 )
break;
}
if ( ! V_91 )
return V_93 ;
V_44 = F_2 ( V_3 ) ;
switch ( V_91 -> V_94 ) {
case V_95 :
if ( V_44 -> V_49 >= 0 )
F_6 ( V_3 -> V_14 , L_2 ) ;
break;
case V_96 :
if ( V_44 -> V_49 >= 0 ) {
F_29 ( V_3 -> V_14 ,
L_3 ) ;
F_30 ( true ) ;
}
break;
default:
break;
}
F_31 ( V_3 -> V_53 ) ;
return V_97 ;
}
static int F_32 ( struct V_98 * V_99 ,
struct V_2 * V_3 ,
const char * V_100 )
{
struct V_90 * V_91 ;
int V_88 , error ;
V_88 = F_33 ( V_99 , V_100 ) ;
if ( ! V_88 )
return - V_101 ;
error = F_34 ( V_3 -> V_14 , V_88 , NULL ,
F_26 ,
V_102 ,
V_100 , V_3 ) ;
if ( error ) {
F_35 ( V_3 -> V_14 , L_4 ,
V_100 , error ) ;
return error ;
}
V_91 = F_36 ( V_3 -> V_14 , sizeof( * V_91 ) , V_103 ) ;
if ( ! V_91 )
return - V_104 ;
V_91 -> V_100 = V_100 ;
V_91 -> V_88 = V_88 ;
if ( ! strncmp ( V_100 , L_5 , 6 ) )
V_91 -> V_94 = V_95 ;
else if ( ! strncmp ( V_100 , L_6 , 6 ) )
V_91 -> V_94 = V_96 ;
F_37 ( & V_91 -> V_105 , & V_3 -> V_106 ) ;
return 0 ;
}
static int F_38 ( struct V_98 * V_99 ,
struct V_2 * V_3 )
{
const char * const V_107 [] = {
L_7 , L_5 , L_6 ,
L_8 , L_9
} ;
int V_108 , error ;
for ( V_108 = 0 ; V_108 < F_15 ( V_107 ) ; V_108 ++ ) {
error = F_32 ( V_99 , V_3 ,
V_107 [ V_108 ] ) ;
if ( error )
return error ;
}
error = F_39 ( V_3 -> V_37 , V_109 ,
0xffff ,
V_110 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
const char * const V_111 [ V_112 ] = {
L_9 , L_10 , L_11 , L_12 ,
} ;
int error , V_108 ;
for ( V_108 = 0 ; V_108 < V_112 ; V_108 ++ ) {
V_3 -> V_12 [ V_108 ] = F_41 ( V_3 -> V_14 ,
V_111 [ V_108 ] ) ;
if ( F_42 ( V_3 -> V_12 [ V_108 ] ) ) {
error = F_43 ( V_3 -> V_12 [ V_108 ] ) ;
goto V_113;
}
if ( ! V_3 -> V_12 [ V_108 ] -> V_114 ) {
error = - V_115 ;
goto V_113;
}
}
return 0 ;
V_113:
F_35 ( V_3 -> V_14 , L_13 ,
error ) ;
return error ;
}
static int F_44 ( struct V_98 * V_99 )
{
struct V_116 * V_117 ;
struct V_2 * V_3 ;
const struct V_118 * V_119 ;
struct V_120 V_121 = {} ;
int error ;
V_119 = F_45 ( F_46 ( V_122 ) ,
& V_99 -> V_14 ) ;
if ( ! V_119 )
return - V_30 ;
if ( ! V_119 -> V_89 ) {
F_35 ( & V_99 -> V_14 , L_14 ) ;
return - V_101 ;
}
V_3 = F_36 ( & V_99 -> V_14 , sizeof( * V_3 ) , V_103 ) ;
if ( ! V_3 )
return - V_104 ;
F_47 ( & V_3 -> V_106 ) ;
V_3 -> V_14 = & V_99 -> V_14 ;
memcpy ( & V_3 -> V_31 , V_119 -> V_89 , sizeof( V_3 -> V_31 ) ) ;
V_3 -> V_37 = F_48 ( V_3 -> V_14 -> V_123 , NULL ) ;
if ( ! V_3 -> V_37 )
return - V_101 ;
error = F_49 ( V_3 -> V_14 , V_3 -> V_37 , & V_3 -> V_27 ) ;
if ( error )
return error ;
F_50 ( V_99 , V_3 ) ;
error = F_39 ( V_3 -> V_37 , V_40 ,
0xffff , V_3 -> V_31 . V_124 ) ;
if ( error )
return error ;
error = F_38 ( V_99 , V_3 ) ;
if ( error )
return error ;
error = F_40 ( V_3 ) ;
if ( error )
return error ;
V_117 = F_36 ( V_3 -> V_14 , sizeof( * V_117 ) , V_103 ) ;
if ( ! V_117 )
return - V_104 ;
V_117 -> V_100 = L_15 ,
V_117 -> type = V_125 ,
V_117 -> V_126 = V_127 ,
V_117 -> V_128 = F_15 ( V_127 ) ,
V_117 -> V_129 = F_23 ,
V_121 . V_130 = V_99 -> V_14 . V_130 ;
V_121 . V_131 = V_3 ;
V_3 -> V_53 = F_51 ( V_3 -> V_14 , V_117 ,
& V_121 ) ;
error = F_52 ( V_3 -> V_53 ) ;
if ( error ) {
F_35 ( V_3 -> V_14 , L_16 ) ;
return error ;
}
F_53 ( & V_3 -> V_92 , 1 ) ;
return 0 ;
}
static int F_54 ( struct V_98 * V_99 )
{
struct V_2 * V_3 = F_55 ( V_99 ) ;
int error ;
F_53 ( & V_3 -> V_92 , 0 ) ;
error = F_39 ( V_3 -> V_37 , V_109 ,
0xffff , 0 ) ;
if ( error )
F_35 ( & V_99 -> V_14 , L_17 , error ) ;
return 0 ;
}
