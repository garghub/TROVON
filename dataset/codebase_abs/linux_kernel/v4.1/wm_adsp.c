static struct V_1 * F_1 ( const void * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_6 == NULL )
return NULL ;
V_6 -> V_6 = F_3 ( V_3 ) ;
if ( ! V_6 -> V_6 ) {
F_4 ( V_6 ) ;
return NULL ;
}
memcpy ( V_6 -> V_6 , V_2 , V_3 ) ;
if ( V_5 )
F_5 ( & V_6 -> V_5 , V_5 ) ;
return V_6 ;
}
static void F_6 ( struct V_4 * V_5 )
{
while ( ! F_7 ( V_5 ) ) {
struct V_1 * V_6 = F_8 ( V_5 ,
struct V_1 ,
V_5 ) ;
F_9 ( & V_6 -> V_5 ) ;
F_4 ( V_6 -> V_6 ) ;
F_10 ( V_6 ) ;
}
}
static int F_11 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_12 ( V_9 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_9 -> V_16 ;
struct V_17 * V_18 = F_13 ( V_13 ) ;
V_11 -> V_19 . integer . V_19 [ 0 ] = V_18 [ V_15 -> V_20 ] . V_21 ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_12 ( V_9 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_9 -> V_16 ;
struct V_17 * V_18 = F_13 ( V_13 ) ;
if ( V_11 -> V_19 . integer . V_19 [ 0 ] == V_18 [ V_15 -> V_20 ] . V_21 )
return 0 ;
if ( V_11 -> V_19 . integer . V_19 [ 0 ] >= V_22 )
return - V_23 ;
if ( V_18 [ V_15 -> V_20 ] . V_24 )
return - V_25 ;
V_18 [ V_15 -> V_20 ] . V_21 = V_11 -> V_19 . integer . V_19 [ 0 ] ;
return 0 ;
}
static struct V_26 const * F_15 ( struct V_17 * V_27 ,
int type )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_27 -> V_29 ; V_28 ++ )
if ( V_27 -> V_30 [ V_28 ] . type == type )
return & V_27 -> V_30 [ V_28 ] ;
return NULL ;
}
static unsigned int F_16 ( struct V_26 const * V_31 ,
unsigned int V_32 )
{
if ( F_17 ( ! V_31 ) )
return V_32 ;
switch ( V_31 -> type ) {
case V_33 :
return V_31 -> V_34 + ( V_32 * 3 ) ;
case V_35 :
return V_31 -> V_34 + ( V_32 * 2 ) ;
case V_36 :
return V_31 -> V_34 + ( V_32 * 2 ) ;
case V_37 :
return V_31 -> V_34 + ( V_32 * 2 ) ;
case V_38 :
return V_31 -> V_34 + ( V_32 * 2 ) ;
default:
F_18 ( 1 , L_1 ) ;
return V_32 ;
}
}
static int F_19 ( struct V_8 * V_9 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = (struct V_41 * ) V_9 -> V_16 ;
V_40 -> type = V_43 ;
V_40 -> V_44 = V_42 -> V_3 ;
return 0 ;
}
static int F_20 ( struct V_8 * V_9 ,
const void * V_6 , T_1 V_3 )
{
struct V_41 * V_42 = (struct V_41 * ) V_9 -> V_16 ;
struct V_45 * V_31 = & V_42 -> V_31 ;
const struct V_26 * V_30 ;
struct V_17 * V_18 = V_42 -> V_18 ;
void * V_46 ;
int V_47 ;
unsigned int V_48 ;
V_30 = F_15 ( V_18 , V_31 -> type ) ;
if ( ! V_30 ) {
F_21 ( V_18 , L_2 ,
V_31 -> type ) ;
return - V_23 ;
}
V_48 = V_42 -> V_31 . V_34 ;
V_48 = F_16 ( V_30 , V_48 ) ;
V_46 = F_22 ( V_6 , V_42 -> V_3 , V_7 | V_49 ) ;
if ( ! V_46 )
return - V_50 ;
V_47 = F_23 ( V_18 -> V_51 , V_48 , V_46 ,
V_42 -> V_3 ) ;
if ( V_47 ) {
F_21 ( V_18 , L_3 ,
V_42 -> V_3 , V_48 , V_47 ) ;
F_10 ( V_46 ) ;
return V_47 ;
}
F_24 ( V_18 , L_4 , V_42 -> V_3 , V_48 ) ;
F_10 ( V_46 ) ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_41 * V_42 = (struct V_41 * ) V_9 -> V_16 ;
char * V_52 = V_11 -> V_19 . V_53 . V_54 ;
memcpy ( V_42 -> V_55 , V_52 , V_42 -> V_3 ) ;
V_42 -> V_56 = 1 ;
if ( ! V_42 -> V_57 )
return 0 ;
return F_20 ( V_9 , V_52 , V_42 -> V_3 ) ;
}
static int F_26 ( struct V_8 * V_9 ,
void * V_6 , T_1 V_3 )
{
struct V_41 * V_42 = (struct V_41 * ) V_9 -> V_16 ;
struct V_45 * V_31 = & V_42 -> V_31 ;
const struct V_26 * V_30 ;
struct V_17 * V_18 = V_42 -> V_18 ;
void * V_46 ;
int V_47 ;
unsigned int V_48 ;
V_30 = F_15 ( V_18 , V_31 -> type ) ;
if ( ! V_30 ) {
F_21 ( V_18 , L_2 ,
V_31 -> type ) ;
return - V_23 ;
}
V_48 = V_42 -> V_31 . V_34 ;
V_48 = F_16 ( V_30 , V_48 ) ;
V_46 = F_27 ( V_42 -> V_3 , V_7 | V_49 ) ;
if ( ! V_46 )
return - V_50 ;
V_47 = F_28 ( V_18 -> V_51 , V_48 , V_46 , V_42 -> V_3 ) ;
if ( V_47 ) {
F_21 ( V_18 , L_5 ,
V_42 -> V_3 , V_48 , V_47 ) ;
F_10 ( V_46 ) ;
return V_47 ;
}
F_24 ( V_18 , L_6 , V_42 -> V_3 , V_48 ) ;
memcpy ( V_6 , V_46 , V_42 -> V_3 ) ;
F_10 ( V_46 ) ;
return 0 ;
}
static int F_29 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_41 * V_42 = (struct V_41 * ) V_9 -> V_16 ;
char * V_52 = V_11 -> V_19 . V_53 . V_54 ;
memcpy ( V_52 , V_42 -> V_55 , V_42 -> V_3 ) ;
return 0 ;
}
static int F_30 ( struct V_17 * V_18 , struct V_41 * V_42 )
{
struct V_58 * V_9 ;
int V_47 ;
if ( ! V_42 || ! V_42 -> V_59 )
return - V_23 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_7 ) ;
if ( ! V_9 )
return - V_50 ;
V_9 -> V_60 = V_61 ;
V_9 -> V_59 = V_42 -> V_59 ;
V_9 -> V_62 = F_19 ;
V_9 -> V_63 = F_29 ;
V_9 -> V_64 = F_25 ;
V_9 -> V_16 = ( unsigned long ) V_42 ;
V_47 = F_31 ( V_18 -> V_65 ,
V_9 , 1 ) ;
if ( V_47 < 0 )
goto V_66;
F_10 ( V_9 ) ;
V_42 -> V_9 = F_32 ( V_18 -> V_65 ,
V_42 -> V_59 ) ;
F_33 ( & V_42 -> V_5 , & V_18 -> V_67 ) ;
return 0 ;
V_66:
F_10 ( V_9 ) ;
return V_47 ;
}
static int F_34 ( struct V_17 * V_27 )
{
F_35 ( V_68 ) ;
const struct V_69 * V_69 ;
struct V_51 * V_51 = V_27 -> V_51 ;
unsigned int V_70 = 0 ;
const struct V_71 * V_72 ;
const struct V_73 * V_74 ;
const struct V_75 * V_76 ;
const struct V_77 * V_78 ;
const struct V_79 * V_31 ;
const struct V_26 * V_30 ;
const char * V_80 ;
char * V_81 , * V_82 ;
struct V_1 * V_6 ;
unsigned int V_48 ;
int V_83 = 0 ;
int V_47 , V_32 , type , V_84 ;
V_81 = F_2 ( V_85 , V_7 ) ;
if ( V_81 == NULL )
return - V_50 ;
snprintf ( V_81 , V_85 , L_7 , V_27 -> V_86 , V_27 -> V_87 ,
V_88 [ V_27 -> V_21 ] . V_81 ) ;
V_81 [ V_85 - 1 ] = '\0' ;
V_47 = F_36 ( & V_69 , V_81 , V_27 -> V_89 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_8 , V_81 ) ;
goto V_90;
}
V_47 = - V_23 ;
V_70 = sizeof( * V_72 ) + sizeof( * V_74 ) + sizeof( * V_78 ) ;
if ( V_70 >= V_69 -> V_91 ) {
F_21 ( V_27 , L_9 ,
V_81 , V_69 -> V_91 ) ;
goto V_92;
}
V_72 = ( void * ) & V_69 -> V_54 [ 0 ] ;
if ( memcmp ( & V_72 -> V_93 [ 0 ] , L_10 , 4 ) != 0 ) {
F_21 ( V_27 , L_11 , V_81 ) ;
goto V_92;
}
if ( V_72 -> V_94 != 0 ) {
F_21 ( V_27 , L_12 ,
V_81 , V_72 -> V_94 ) ;
goto V_92;
}
F_37 ( V_27 , L_13 , V_72 -> V_94 ) ;
if ( V_72 -> V_95 != V_27 -> type ) {
F_21 ( V_27 , L_14 ,
V_81 , V_72 -> V_95 , V_27 -> type ) ;
goto V_92;
}
switch ( V_27 -> type ) {
case V_96 :
V_70 = sizeof( * V_72 ) + sizeof( * V_74 ) + sizeof( * V_78 ) ;
V_74 = ( void * ) & ( V_72 [ 1 ] ) ;
V_78 = ( void * ) & ( V_74 [ 1 ] ) ;
V_84 = sizeof( * V_74 ) ;
F_24 ( V_27 , L_15 ,
V_81 , F_38 ( V_74 -> V_97 ) ,
F_38 ( V_74 -> V_98 ) ,
F_38 ( V_74 -> V_99 ) ) ;
break;
case V_100 :
V_70 = sizeof( * V_72 ) + sizeof( * V_76 ) + sizeof( * V_78 ) ;
V_76 = ( void * ) & ( V_72 [ 1 ] ) ;
V_78 = ( void * ) & ( V_76 [ 1 ] ) ;
V_84 = sizeof( * V_76 ) ;
F_24 ( V_27 , L_16 ,
V_81 , F_38 ( V_76 -> V_101 ) ,
F_38 ( V_76 -> V_102 ) ,
F_38 ( V_76 -> V_98 ) ,
F_38 ( V_76 -> V_99 ) ) ;
break;
default:
F_18 ( 1 , L_17 ) ;
goto V_92;
}
if ( F_38 ( V_72 -> V_3 ) != sizeof( * V_72 ) +
V_84 + sizeof( * V_78 ) ) {
F_21 ( V_27 , L_18 ,
V_81 , F_38 ( V_72 -> V_3 ) ) ;
goto V_92;
}
F_24 ( V_27 , L_19 , V_81 ,
F_39 ( V_78 -> V_103 ) ) ;
while ( V_70 < V_69 -> V_91 &&
V_70 - V_69 -> V_91 > sizeof( * V_31 ) ) {
V_31 = ( void * ) & ( V_69 -> V_54 [ V_70 ] ) ;
V_80 = L_20 ;
V_48 = 0 ;
V_82 = NULL ;
V_32 = F_38 ( V_31 -> V_32 ) & 0xffffff ;
type = F_40 ( V_31 -> type ) & 0xff ;
V_30 = F_15 ( V_27 , type ) ;
switch ( type ) {
case V_104 :
V_80 = L_21 ;
V_82 = F_2 ( F_38 ( V_31 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_105 :
V_80 = L_22 ;
V_82 = F_2 ( F_38 ( V_31 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_106 :
V_80 = L_23 ;
V_48 = V_32 ;
break;
case V_33 :
V_80 = L_24 ;
V_48 = F_16 ( V_30 , V_32 ) ;
break;
case V_35 :
V_80 = L_25 ;
V_48 = F_16 ( V_30 , V_32 ) ;
break;
case V_36 :
V_80 = L_26 ;
V_48 = F_16 ( V_30 , V_32 ) ;
break;
case V_37 :
V_80 = L_27 ;
V_48 = F_16 ( V_30 , V_32 ) ;
break;
case V_38 :
V_80 = L_28 ;
V_48 = F_16 ( V_30 , V_32 ) ;
break;
default:
F_41 ( V_27 ,
L_29 ,
V_81 , V_83 , type , V_70 , V_70 ) ;
break;
}
F_24 ( V_27 , L_30 , V_81 ,
V_83 , F_38 ( V_31 -> V_3 ) , V_32 ,
V_80 ) ;
if ( V_82 ) {
memcpy ( V_82 , V_31 -> V_54 , F_38 ( V_31 -> V_3 ) ) ;
F_37 ( V_27 , L_31 , V_81 , V_82 ) ;
F_10 ( V_82 ) ;
}
if ( V_48 ) {
V_6 = F_1 ( V_31 -> V_54 ,
F_38 ( V_31 -> V_3 ) ,
& V_68 ) ;
if ( ! V_6 ) {
F_21 ( V_27 , L_32 ) ;
V_47 = - V_50 ;
goto V_92;
}
V_47 = F_42 ( V_51 , V_48 , V_6 -> V_6 ,
F_38 ( V_31 -> V_3 ) ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 ,
L_33 ,
V_81 , V_83 ,
F_38 ( V_31 -> V_3 ) , V_32 ,
V_80 , V_47 ) ;
goto V_92;
}
}
V_70 += F_38 ( V_31 -> V_3 ) + sizeof( * V_31 ) ;
V_83 ++ ;
}
V_47 = F_43 ( V_51 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_34 , V_47 ) ;
goto V_92;
}
if ( V_70 > V_69 -> V_91 )
F_41 ( V_27 , L_35 ,
V_81 , V_83 , V_70 - V_69 -> V_91 ) ;
V_92:
F_43 ( V_51 ) ;
F_6 ( & V_68 ) ;
F_44 ( V_69 ) ;
V_90:
F_10 ( V_81 ) ;
return V_47 ;
}
static int F_45 ( struct V_17 * V_18 )
{
struct V_41 * V_42 ;
int V_47 ;
F_46 (ctl, &adsp->ctl_list, list) {
if ( ! V_42 -> V_57 || V_42 -> V_56 )
continue;
V_47 = F_26 ( V_42 -> V_9 ,
V_42 -> V_55 ,
V_42 -> V_3 ) ;
if ( V_47 < 0 )
return V_47 ;
}
return 0 ;
}
static int F_47 ( struct V_17 * V_18 )
{
struct V_41 * V_42 ;
int V_47 ;
F_46 (ctl, &adsp->ctl_list, list) {
if ( ! V_42 -> V_57 )
continue;
if ( V_42 -> V_56 ) {
V_47 = F_20 ( V_42 -> V_9 ,
V_42 -> V_55 ,
V_42 -> V_3 ) ;
if ( V_47 < 0 )
return V_47 ;
}
}
return 0 ;
}
static void F_48 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = F_49 ( V_108 ,
struct V_109 ,
V_108 ) ;
F_30 ( V_110 -> V_18 , V_110 -> V_42 ) ;
F_10 ( V_110 ) ;
}
static int F_50 ( struct V_17 * V_27 ,
const struct V_45 * V_31 )
{
struct V_41 * V_42 ;
struct V_109 * V_110 ;
char * V_59 ;
char * V_80 ;
int V_47 ;
V_59 = F_27 ( V_85 , V_7 ) ;
if ( ! V_59 )
return - V_50 ;
switch ( V_31 -> type ) {
case V_33 :
V_80 = L_24 ;
break;
case V_35 :
V_80 = L_25 ;
break;
case V_36 :
V_80 = L_26 ;
break;
case V_37 :
V_80 = L_27 ;
break;
case V_38 :
V_80 = L_28 ;
break;
default:
V_47 = - V_23 ;
goto V_111;
}
snprintf ( V_59 , V_85 , L_36 ,
V_27 -> V_87 , V_80 , V_31 -> V_112 ) ;
F_46 (ctl, &dsp->ctl_list,
list) {
if ( ! strcmp ( V_42 -> V_59 , V_59 ) ) {
if ( ! V_42 -> V_57 )
V_42 -> V_57 = 1 ;
goto V_113;
}
}
V_42 = F_2 ( sizeof( * V_42 ) , V_7 ) ;
if ( ! V_42 ) {
V_47 = - V_50 ;
goto V_111;
}
V_42 -> V_31 = * V_31 ;
V_42 -> V_59 = F_22 ( V_59 , strlen ( V_59 ) + 1 , V_7 ) ;
if ( ! V_42 -> V_59 ) {
V_47 = - V_50 ;
goto V_114;
}
V_42 -> V_57 = 1 ;
V_42 -> V_56 = 0 ;
V_42 -> V_115 . V_116 = F_29 ;
V_42 -> V_115 . V_117 = F_25 ;
V_42 -> V_18 = V_27 ;
V_42 -> V_3 = V_31 -> V_3 ;
V_42 -> V_55 = F_2 ( V_42 -> V_3 , V_7 ) ;
if ( ! V_42 -> V_55 ) {
V_47 = - V_50 ;
goto V_118;
}
V_110 = F_2 ( sizeof( * V_110 ) , V_7 ) ;
if ( ! V_110 ) {
V_47 = - V_50 ;
goto V_119;
}
V_110 -> V_18 = V_27 ;
V_110 -> V_42 = V_42 ;
F_51 ( & V_110 -> V_108 , F_48 ) ;
F_52 ( & V_110 -> V_108 ) ;
V_113:
F_10 ( V_59 ) ;
return 0 ;
V_119:
F_10 ( V_42 -> V_55 ) ;
V_118:
F_10 ( V_42 -> V_59 ) ;
V_114:
F_10 ( V_42 ) ;
V_111:
F_10 ( V_59 ) ;
return V_47 ;
}
static int F_53 ( struct V_17 * V_27 )
{
struct V_51 * V_51 = V_27 -> V_51 ;
struct V_120 V_121 ;
struct V_122 V_123 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
void * V_112 , * V_6 ;
struct V_45 * V_31 ;
const struct V_26 * V_30 ;
unsigned int V_70 , V_128 ;
T_1 V_129 , V_130 ;
T_2 V_131 ;
int V_28 , V_47 ;
switch ( V_27 -> type ) {
case V_96 :
V_30 = F_15 ( V_27 , V_35 ) ;
break;
case V_100 :
V_30 = F_15 ( V_27 , V_36 ) ;
break;
default:
V_30 = NULL ;
break;
}
if ( F_17 ( ! V_30 ) )
return - V_23 ;
switch ( V_27 -> type ) {
case V_96 :
V_47 = F_28 ( V_51 , V_30 -> V_34 , & V_121 ,
sizeof( V_121 ) ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_37 ,
V_47 ) ;
return V_47 ;
}
V_6 = & V_121 ;
V_130 = sizeof( V_121 ) ;
V_129 = F_40 ( V_121 . V_129 ) ;
V_27 -> V_132 = F_40 ( V_121 . V_21 . V_133 ) ;
F_37 ( V_27 , L_38 ,
V_27 -> V_132 ,
( F_40 ( V_121 . V_21 . V_94 ) & 0xff0000 ) >> 16 ,
( F_40 ( V_121 . V_21 . V_94 ) & 0xff00 ) >> 8 ,
F_40 ( V_121 . V_21 . V_94 ) & 0xff ,
V_129 ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 )
return - V_50 ;
V_31 -> type = V_38 ;
V_31 -> V_112 = F_40 ( V_121 . V_21 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_121 . V_99 ) ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 )
return - V_50 ;
V_31 -> type = V_35 ;
V_31 -> V_112 = F_40 ( V_121 . V_21 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_121 . V_97 ) ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
V_70 = sizeof( V_121 ) / 2 ;
V_128 = V_70 + ( ( sizeof( * V_125 ) * V_129 ) / 2 ) ;
break;
case V_100 :
V_47 = F_28 ( V_51 , V_30 -> V_34 , & V_123 ,
sizeof( V_123 ) ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_37 ,
V_47 ) ;
return V_47 ;
}
V_6 = & V_123 ;
V_130 = sizeof( V_123 ) ;
V_129 = F_40 ( V_123 . V_129 ) ;
V_27 -> V_132 = F_40 ( V_123 . V_21 . V_133 ) ;
F_37 ( V_27 , L_38 ,
V_27 -> V_132 ,
( F_40 ( V_123 . V_21 . V_94 ) & 0xff0000 ) >> 16 ,
( F_40 ( V_123 . V_21 . V_94 ) & 0xff00 ) >> 8 ,
F_40 ( V_123 . V_21 . V_94 ) & 0xff ,
V_129 ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 )
return - V_50 ;
V_31 -> type = V_36 ;
V_31 -> V_112 = F_40 ( V_123 . V_21 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_123 . V_101 ) ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 )
return - V_50 ;
V_31 -> type = V_37 ;
V_31 -> V_112 = F_40 ( V_123 . V_21 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_123 . V_102 ) ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 )
return - V_50 ;
V_31 -> type = V_135 ;
V_31 -> V_112 = F_40 ( V_123 . V_21 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_123 . V_99 ) ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
V_70 = sizeof( V_123 ) / 2 ;
V_128 = V_70 + ( ( sizeof( * V_127 ) * V_129 ) / 2 ) ;
break;
default:
F_18 ( 1 , L_17 ) ;
return - V_23 ;
}
if ( V_129 == 0 ) {
F_21 ( V_27 , L_39 ) ;
return - V_23 ;
}
if ( V_129 > 1024 ) {
F_21 ( V_27 , L_40 , V_129 ) ;
F_54 ( F_55 ( V_27 -> V_89 ) , V_136 ,
V_6 , V_130 ) ;
return - V_23 ;
}
V_47 = F_28 ( V_51 , V_30 -> V_34 + V_128 , & V_131 , sizeof( V_131 ) ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_41 ,
V_47 ) ;
return V_47 ;
}
if ( F_40 ( V_131 ) != 0xbedead )
F_41 ( V_27 , L_42 ,
V_128 , F_40 ( V_131 ) ) ;
V_112 = F_2 ( ( V_128 - V_70 ) * 2 , V_7 | V_49 ) ;
if ( ! V_112 )
return - V_50 ;
V_47 = F_28 ( V_51 , V_30 -> V_34 + V_70 , V_112 , ( V_128 - V_70 ) * 2 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_43 ,
V_47 ) ;
goto V_90;
}
V_125 = V_112 ;
V_127 = V_112 ;
for ( V_28 = 0 ; V_28 < V_129 ; V_28 ++ ) {
switch ( V_27 -> type ) {
case V_96 :
F_37 ( V_27 , L_44 ,
V_28 , F_40 ( V_125 [ V_28 ] . V_112 . V_133 ) ,
( F_40 ( V_125 [ V_28 ] . V_112 . V_94 ) & 0xff0000 ) >> 16 ,
( F_40 ( V_125 [ V_28 ] . V_112 . V_94 ) & 0xff00 ) >> 8 ,
F_40 ( V_125 [ V_28 ] . V_112 . V_94 ) & 0xff ,
F_40 ( V_125 [ V_28 ] . V_97 ) ,
F_40 ( V_125 [ V_28 ] . V_99 ) ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 ) {
V_47 = - V_50 ;
goto V_90;
}
V_31 -> type = V_35 ;
V_31 -> V_112 = F_40 ( V_125 [ V_28 ] . V_112 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_125 [ V_28 ] . V_97 ) ;
V_31 -> V_3 = 0 ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
if ( V_28 + 1 < V_129 ) {
V_31 -> V_3 = F_40 ( V_125 [ V_28 + 1 ] . V_97 ) ;
V_31 -> V_3 -= F_40 ( V_125 [ V_28 ] . V_97 ) ;
V_31 -> V_3 *= 4 ;
F_50 ( V_27 , V_31 ) ;
} else {
F_41 ( V_27 , L_45 ,
F_40 ( V_125 [ V_28 ] . V_112 . V_133 ) ) ;
}
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 ) {
V_47 = - V_50 ;
goto V_90;
}
V_31 -> type = V_38 ;
V_31 -> V_112 = F_40 ( V_125 [ V_28 ] . V_112 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_125 [ V_28 ] . V_99 ) ;
V_31 -> V_3 = 0 ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
if ( V_28 + 1 < V_129 ) {
V_31 -> V_3 = F_40 ( V_125 [ V_28 + 1 ] . V_99 ) ;
V_31 -> V_3 -= F_40 ( V_125 [ V_28 ] . V_99 ) ;
V_31 -> V_3 *= 4 ;
F_50 ( V_27 , V_31 ) ;
} else {
F_41 ( V_27 , L_46 ,
F_40 ( V_125 [ V_28 ] . V_112 . V_133 ) ) ;
}
break;
case V_100 :
F_37 ( V_27 ,
L_47 ,
V_28 , F_40 ( V_127 [ V_28 ] . V_112 . V_133 ) ,
( F_40 ( V_127 [ V_28 ] . V_112 . V_94 ) & 0xff0000 ) >> 16 ,
( F_40 ( V_127 [ V_28 ] . V_112 . V_94 ) & 0xff00 ) >> 8 ,
F_40 ( V_127 [ V_28 ] . V_112 . V_94 ) & 0xff ,
F_40 ( V_127 [ V_28 ] . V_101 ) ,
F_40 ( V_127 [ V_28 ] . V_102 ) ,
F_40 ( V_127 [ V_28 ] . V_99 ) ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 ) {
V_47 = - V_50 ;
goto V_90;
}
V_31 -> type = V_36 ;
V_31 -> V_112 = F_40 ( V_127 [ V_28 ] . V_112 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_127 [ V_28 ] . V_101 ) ;
V_31 -> V_3 = 0 ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
if ( V_28 + 1 < V_129 ) {
V_31 -> V_3 = F_40 ( V_127 [ V_28 + 1 ] . V_101 ) ;
V_31 -> V_3 -= F_40 ( V_127 [ V_28 ] . V_101 ) ;
V_31 -> V_3 *= 4 ;
F_50 ( V_27 , V_31 ) ;
} else {
F_41 ( V_27 , L_48 ,
F_40 ( V_127 [ V_28 ] . V_112 . V_133 ) ) ;
}
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 ) {
V_47 = - V_50 ;
goto V_90;
}
V_31 -> type = V_37 ;
V_31 -> V_112 = F_40 ( V_127 [ V_28 ] . V_112 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_127 [ V_28 ] . V_102 ) ;
V_31 -> V_3 = 0 ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
if ( V_28 + 1 < V_129 ) {
V_31 -> V_3 = F_40 ( V_127 [ V_28 + 1 ] . V_102 ) ;
V_31 -> V_3 -= F_40 ( V_127 [ V_28 ] . V_102 ) ;
V_31 -> V_3 *= 4 ;
F_50 ( V_27 , V_31 ) ;
} else {
F_41 ( V_27 , L_49 ,
F_40 ( V_127 [ V_28 ] . V_112 . V_133 ) ) ;
}
V_31 = F_2 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 ) {
V_47 = - V_50 ;
goto V_90;
}
V_31 -> type = V_135 ;
V_31 -> V_112 = F_40 ( V_127 [ V_28 ] . V_112 . V_133 ) ;
V_31 -> V_34 = F_40 ( V_127 [ V_28 ] . V_99 ) ;
V_31 -> V_3 = 0 ;
F_5 ( & V_31 -> V_5 , & V_27 -> V_134 ) ;
if ( V_28 + 1 < V_129 ) {
V_31 -> V_3 = F_40 ( V_127 [ V_28 + 1 ] . V_99 ) ;
V_31 -> V_3 -= F_40 ( V_127 [ V_28 ] . V_99 ) ;
V_31 -> V_3 *= 4 ;
F_50 ( V_27 , V_31 ) ;
} else {
F_41 ( V_27 , L_46 ,
F_40 ( V_127 [ V_28 ] . V_112 . V_133 ) ) ;
}
break;
}
}
V_90:
F_10 ( V_112 ) ;
return V_47 ;
}
static int F_56 ( struct V_17 * V_27 )
{
F_35 ( V_68 ) ;
struct V_51 * V_51 = V_27 -> V_51 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
const struct V_69 * V_69 ;
const struct V_26 * V_30 ;
struct V_45 * V_141 ;
const char * V_80 ;
int V_47 , V_70 , V_142 , type , V_32 , V_48 ;
char * V_81 ;
struct V_1 * V_6 ;
V_81 = F_2 ( V_85 , V_7 ) ;
if ( V_81 == NULL )
return - V_50 ;
snprintf ( V_81 , V_85 , L_50 , V_27 -> V_86 , V_27 -> V_87 ,
V_88 [ V_27 -> V_21 ] . V_81 ) ;
V_81 [ V_85 - 1 ] = '\0' ;
V_47 = F_36 ( & V_69 , V_81 , V_27 -> V_89 ) ;
if ( V_47 != 0 ) {
F_41 ( V_27 , L_8 , V_81 ) ;
V_47 = 0 ;
goto V_90;
}
V_47 = - V_23 ;
if ( sizeof( * V_138 ) >= V_69 -> V_91 ) {
F_21 ( V_27 , L_9 ,
V_81 , V_69 -> V_91 ) ;
goto V_92;
}
V_138 = ( void * ) & V_69 -> V_54 [ 0 ] ;
if ( memcmp ( V_138 -> V_93 , L_51 , 4 ) != 0 ) {
F_21 ( V_27 , L_11 , V_81 ) ;
goto V_92;
}
switch ( F_40 ( V_138 -> V_143 ) & 0xff ) {
case 1 :
break;
default:
F_21 ( V_27 , L_52 ,
V_81 , F_40 ( V_138 -> V_143 ) & 0xff ) ;
V_47 = - V_23 ;
goto V_92;
}
F_24 ( V_27 , L_53 , V_81 ,
( F_38 ( V_138 -> V_94 ) >> 16 ) & 0xff ,
( F_38 ( V_138 -> V_94 ) >> 8 ) & 0xff ,
F_38 ( V_138 -> V_94 ) & 0xff ) ;
V_70 = F_38 ( V_138 -> V_3 ) ;
V_142 = 0 ;
while ( V_70 < V_69 -> V_91 &&
V_70 - V_69 -> V_91 > sizeof( * V_140 ) ) {
V_140 = ( void * ) ( & V_69 -> V_54 [ V_70 ] ) ;
type = F_57 ( V_140 -> type ) ;
V_32 = F_57 ( V_140 -> V_32 ) ;
F_24 ( V_27 , L_54 ,
V_81 , V_142 , F_38 ( V_140 -> V_133 ) ,
( F_38 ( V_140 -> V_94 ) >> 16 ) & 0xff ,
( F_38 ( V_140 -> V_94 ) >> 8 ) & 0xff ,
F_38 ( V_140 -> V_94 ) & 0xff ) ;
F_24 ( V_27 , L_55 ,
V_81 , V_142 , F_38 ( V_140 -> V_3 ) , V_32 , type ) ;
V_48 = 0 ;
V_80 = L_20 ;
switch ( type ) {
case ( V_104 << 8 ) :
case ( V_105 << 8 ) :
break;
case ( V_106 << 8 ) :
if ( F_38 ( V_140 -> V_133 ) == V_27 -> V_132 &&
V_32 == 0 ) {
V_80 = L_56 ;
V_30 = F_15 ( V_27 , type ) ;
if ( ! V_30 ) {
F_21 ( V_27 , L_57 ) ;
break;
}
V_48 = F_16 ( V_30 , 0 ) ;
} else {
V_80 = L_58 ;
V_48 = V_32 ;
}
break;
case V_35 :
case V_38 :
case V_36 :
case V_37 :
F_24 ( V_27 , L_59 ,
V_81 , V_142 , F_38 ( V_140 -> V_3 ) ,
type , F_38 ( V_140 -> V_133 ) ) ;
V_30 = F_15 ( V_27 , type ) ;
if ( ! V_30 ) {
F_21 ( V_27 , L_2 , type ) ;
break;
}
V_48 = 0 ;
F_46 (alg_region,
&dsp->alg_regions, list) {
if ( F_38 ( V_140 -> V_133 ) == V_141 -> V_112 &&
type == V_141 -> type ) {
V_48 = V_141 -> V_34 ;
V_48 = F_16 ( V_30 ,
V_48 ) ;
V_48 += V_32 ;
break;
}
}
if ( V_48 == 0 )
F_21 ( V_27 , L_60 ,
type , F_38 ( V_140 -> V_133 ) ) ;
break;
default:
F_21 ( V_27 , L_61 ,
V_81 , V_142 , type , V_70 ) ;
break;
}
if ( V_48 ) {
V_6 = F_1 ( V_140 -> V_54 ,
F_38 ( V_140 -> V_3 ) ,
& V_68 ) ;
if ( ! V_6 ) {
F_21 ( V_27 , L_32 ) ;
V_47 = - V_50 ;
goto V_92;
}
F_24 ( V_27 , L_62 ,
V_81 , V_142 , F_38 ( V_140 -> V_3 ) ,
V_48 ) ;
V_47 = F_42 ( V_51 , V_48 , V_6 -> V_6 ,
F_38 ( V_140 -> V_3 ) ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 ,
L_63 ,
V_81 , V_142 , V_48 , V_80 , V_47 ) ;
}
}
V_70 += ( F_38 ( V_140 -> V_3 ) + sizeof( * V_140 ) + 3 ) & ~ 0x03 ;
V_142 ++ ;
}
V_47 = F_43 ( V_51 ) ;
if ( V_47 != 0 )
F_21 ( V_27 , L_34 , V_47 ) ;
if ( V_70 > V_69 -> V_91 )
F_41 ( V_27 , L_35 ,
V_81 , V_142 , V_70 - V_69 -> V_91 ) ;
V_92:
F_43 ( V_51 ) ;
F_44 ( V_69 ) ;
F_6 ( & V_68 ) ;
V_90:
F_10 ( V_81 ) ;
return V_47 ;
}
int F_58 ( struct V_17 * V_18 )
{
F_59 ( & V_18 -> V_134 ) ;
return 0 ;
}
int F_60 ( struct V_144 * V_145 ,
struct V_8 * V_9 ,
int V_146 )
{
struct V_12 * V_13 = F_61 ( V_145 -> V_147 ) ;
struct V_17 * V_148 = F_13 ( V_13 ) ;
struct V_17 * V_27 = & V_148 [ V_145 -> V_149 ] ;
struct V_45 * V_141 ;
struct V_41 * V_42 ;
int V_47 ;
int V_131 ;
V_27 -> V_65 = V_13 -> V_150 . V_65 ;
switch ( V_146 ) {
case V_151 :
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_152 ,
V_153 , V_153 ) ;
if( V_27 -> V_154 ) {
V_47 = F_63 ( V_27 -> V_51 , V_27 -> V_154 , & V_131 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_64 ,
V_47 ) ;
return V_47 ;
}
V_131 = ( V_131 & V_27 -> V_155 )
>> V_27 -> V_156 ;
V_47 = F_62 ( V_27 -> V_51 ,
V_27 -> V_34 + V_157 ,
V_158 , V_131 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_65 ,
V_47 ) ;
return V_47 ;
}
}
V_47 = F_34 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_47 = F_53 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_47 = F_56 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_47 = F_45 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_47 = F_47 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_152 ,
V_160 | V_161 ,
V_160 | V_161 ) ;
break;
case V_162 :
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_152 ,
V_160 | V_161 , 0 ) ;
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_163 ,
V_164 , 0 ) ;
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_152 ,
V_153 , 0 ) ;
F_46 (ctl, &dsp->ctl_list, list)
V_42 -> V_57 = 0 ;
while ( ! F_7 ( & V_27 -> V_134 ) ) {
V_141 = F_8 ( & V_27 -> V_134 ,
struct V_45 ,
V_5 ) ;
F_9 ( & V_141 -> V_5 ) ;
F_10 ( V_141 ) ;
}
break;
default:
break;
}
return 0 ;
V_159:
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_152 ,
V_153 , 0 ) ;
return V_47 ;
}
static int F_64 ( struct V_17 * V_27 )
{
unsigned int V_131 ;
int V_47 , V_44 ;
V_47 = F_65 ( V_27 -> V_51 , V_27 -> V_34 + V_165 ,
V_166 , V_166 ) ;
if ( V_47 != 0 )
return V_47 ;
for ( V_44 = 0 ; V_44 < 10 ; ++ V_44 ) {
V_47 = F_63 ( V_27 -> V_51 , V_27 -> V_34 + V_167 ,
& V_131 ) ;
if ( V_47 != 0 )
return V_47 ;
if ( V_131 & V_168 )
break;
F_66 ( 1 ) ;
}
if ( ! ( V_131 & V_168 ) ) {
F_21 ( V_27 , L_66 ) ;
return - V_25 ;
}
F_24 ( V_27 , L_67 , V_44 ) ;
return 0 ;
}
static void F_67 ( struct V_107 * V_108 )
{
struct V_17 * V_27 = F_49 ( V_108 ,
struct V_17 ,
V_169 ) ;
int V_47 ;
unsigned int V_131 ;
V_47 = F_63 ( V_27 -> V_51 , V_170 , & V_131 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_64 , V_47 ) ;
return;
}
V_131 = ( V_131 & V_171 )
>> V_172 ;
V_47 = F_65 ( V_27 -> V_51 ,
V_27 -> V_34 + V_173 ,
V_174 , V_131 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_65 , V_47 ) ;
return;
}
if ( V_27 -> V_175 ) {
V_47 = F_63 ( V_27 -> V_51 ,
V_27 -> V_34 + V_173 , & V_131 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 , L_68 , V_47 ) ;
return;
}
if ( ( V_131 & V_174 ) >= 3 ) {
V_47 = F_68 ( V_27 -> V_175 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 ,
L_69 ,
V_47 ) ;
return;
}
V_47 = F_69 ( V_27 -> V_175 ,
1800000 ,
1800000 ) ;
if ( V_47 != 0 ) {
F_21 ( V_27 ,
L_70 ,
V_47 ) ;
return;
}
}
}
V_47 = F_64 ( V_27 ) ;
if ( V_47 != 0 )
return;
V_47 = F_34 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_47 = F_53 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_47 = F_56 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_47 = F_45 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_47 = F_47 ( V_27 ) ;
if ( V_47 != 0 )
goto V_159;
V_27 -> V_24 = true ;
return;
V_159:
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_165 ,
V_166 | V_176 | V_177 , 0 ) ;
}
int F_70 ( struct V_144 * V_145 ,
struct V_8 * V_9 , int V_146 )
{
struct V_12 * V_13 = F_61 ( V_145 -> V_147 ) ;
struct V_17 * V_148 = F_13 ( V_13 ) ;
struct V_17 * V_27 = & V_148 [ V_145 -> V_149 ] ;
V_27 -> V_65 = V_13 -> V_150 . V_65 ;
switch ( V_146 ) {
case V_178 :
F_71 ( V_179 , & V_27 -> V_169 ) ;
break;
default:
break;
}
return 0 ;
}
int F_72 ( struct V_144 * V_145 ,
struct V_8 * V_9 , int V_146 )
{
struct V_12 * V_13 = F_61 ( V_145 -> V_147 ) ;
struct V_17 * V_148 = F_13 ( V_13 ) ;
struct V_17 * V_27 = & V_148 [ V_145 -> V_149 ] ;
struct V_45 * V_141 ;
struct V_41 * V_42 ;
int V_47 ;
switch ( V_146 ) {
case V_151 :
F_73 ( & V_27 -> V_169 ) ;
if ( ! V_27 -> V_24 )
return - V_180 ;
V_47 = F_62 ( V_27 -> V_51 ,
V_27 -> V_34 + V_165 ,
V_176 | V_177 ,
V_176 | V_177 ) ;
if ( V_47 != 0 )
goto V_159;
break;
case V_162 :
V_27 -> V_24 = false ;
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_165 ,
V_166 | V_176 |
V_177 , 0 ) ;
F_74 ( V_27 -> V_51 , V_27 -> V_34 + V_181 , 0 ) ;
F_74 ( V_27 -> V_51 , V_27 -> V_34 + V_182 , 0 ) ;
F_74 ( V_27 -> V_51 , V_27 -> V_34 + V_183 , 0 ) ;
if ( V_27 -> V_175 ) {
V_47 = F_69 ( V_27 -> V_175 , 1200000 ,
1800000 ) ;
if ( V_47 != 0 )
F_41 ( V_27 ,
L_71 ,
V_47 ) ;
V_47 = F_75 ( V_27 -> V_175 ) ;
if ( V_47 != 0 )
F_21 ( V_27 ,
L_69 ,
V_47 ) ;
}
F_46 (ctl, &dsp->ctl_list, list)
V_42 -> V_57 = 0 ;
while ( ! F_7 ( & V_27 -> V_134 ) ) {
V_141 = F_8 ( & V_27 -> V_134 ,
struct V_45 ,
V_5 ) ;
F_9 ( & V_141 -> V_5 ) ;
F_10 ( V_141 ) ;
}
F_24 ( V_27 , L_72 ) ;
break;
default:
break;
}
return 0 ;
V_159:
F_62 ( V_27 -> V_51 , V_27 -> V_34 + V_165 ,
V_166 | V_176 | V_177 , 0 ) ;
return V_47 ;
}
int F_76 ( struct V_17 * V_18 , bool V_175 )
{
int V_47 ;
V_47 = F_62 ( V_18 -> V_51 , V_18 -> V_34 + V_165 ,
V_184 , 0 ) ;
if ( V_47 != 0 ) {
F_21 ( V_18 , L_73 , V_47 ) ;
return V_47 ;
}
F_59 ( & V_18 -> V_134 ) ;
F_59 ( & V_18 -> V_67 ) ;
F_51 ( & V_18 -> V_169 , F_67 ) ;
if ( V_175 ) {
V_18 -> V_175 = F_77 ( V_18 -> V_89 , L_74 ) ;
if ( F_78 ( V_18 -> V_175 ) ) {
V_47 = F_79 ( V_18 -> V_175 ) ;
F_21 ( V_18 , L_75 , V_47 ) ;
return V_47 ;
}
V_47 = F_68 ( V_18 -> V_175 ) ;
if ( V_47 != 0 ) {
F_21 ( V_18 , L_76 , V_47 ) ;
return V_47 ;
}
V_47 = F_69 ( V_18 -> V_175 , 1200000 , 1800000 ) ;
if ( V_47 != 0 ) {
F_21 ( V_18 , L_77 , V_47 ) ;
return V_47 ;
}
V_47 = F_75 ( V_18 -> V_175 ) ;
if ( V_47 != 0 ) {
F_21 ( V_18 , L_78 , V_47 ) ;
return V_47 ;
}
}
return 0 ;
}
