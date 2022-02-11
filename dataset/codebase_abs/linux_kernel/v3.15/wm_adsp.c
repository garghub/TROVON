static struct V_1 * F_1 ( const void * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_6 == NULL )
return NULL ;
V_6 -> V_6 = F_3 ( V_2 , V_3 , V_7 | V_8 ) ;
if ( ! V_6 -> V_6 ) {
F_4 ( V_6 ) ;
return NULL ;
}
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
F_4 ( V_6 ) ;
}
}
static int F_10 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_11 ( V_10 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_10 -> V_17 ;
struct V_18 * V_19 = F_12 ( V_14 ) ;
V_12 -> V_20 . integer . V_20 [ 0 ] = V_19 [ V_16 -> V_21 ] . V_22 ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_11 ( V_10 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_10 -> V_17 ;
struct V_18 * V_19 = F_12 ( V_14 ) ;
if ( V_12 -> V_20 . integer . V_20 [ 0 ] == V_19 [ V_16 -> V_21 ] . V_22 )
return 0 ;
if ( V_12 -> V_20 . integer . V_20 [ 0 ] >= V_23 )
return - V_24 ;
if ( V_19 [ V_16 -> V_21 ] . V_25 )
return - V_26 ;
V_19 [ V_16 -> V_21 ] . V_22 = V_12 -> V_20 . integer . V_20 [ 0 ] ;
return 0 ;
}
static struct V_27 const * F_14 ( struct V_18 * V_28 ,
int type )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_30 ; V_29 ++ )
if ( V_28 -> V_31 [ V_29 ] . type == type )
return & V_28 -> V_31 [ V_29 ] ;
return NULL ;
}
static unsigned int F_15 ( struct V_27 const * V_32 ,
unsigned int V_33 )
{
if ( F_16 ( ! V_32 ) )
return V_33 ;
switch ( V_32 -> type ) {
case V_34 :
return V_32 -> V_35 + ( V_33 * 3 ) ;
case V_36 :
return V_32 -> V_35 + ( V_33 * 2 ) ;
case V_37 :
return V_32 -> V_35 + ( V_33 * 2 ) ;
case V_38 :
return V_32 -> V_35 + ( V_33 * 2 ) ;
case V_39 :
return V_32 -> V_35 + ( V_33 * 2 ) ;
default:
F_17 ( 1 , L_1 ) ;
return V_33 ;
}
}
static int F_18 ( struct V_9 * V_10 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
V_41 -> type = V_44 ;
V_41 -> V_45 = V_43 -> V_3 ;
return 0 ;
}
static int F_19 ( struct V_9 * V_10 ,
const void * V_6 , T_1 V_3 )
{
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
struct V_46 * V_32 = & V_43 -> V_32 ;
const struct V_27 * V_31 ;
struct V_18 * V_19 = V_43 -> V_19 ;
void * V_47 ;
int V_48 ;
unsigned int V_49 ;
V_31 = F_14 ( V_19 , V_32 -> type ) ;
if ( ! V_31 ) {
F_20 ( V_19 , L_2 ,
V_32 -> type ) ;
return - V_24 ;
}
V_49 = V_43 -> V_32 . V_35 ;
V_49 = F_15 ( V_31 , V_49 ) ;
V_47 = F_3 ( V_6 , V_43 -> V_3 , V_7 | V_8 ) ;
if ( ! V_47 )
return - V_50 ;
V_48 = F_21 ( V_19 -> V_51 , V_49 , V_47 ,
V_43 -> V_3 ) ;
if ( V_48 ) {
F_20 ( V_19 , L_3 ,
V_43 -> V_3 , V_49 , V_48 ) ;
F_4 ( V_47 ) ;
return V_48 ;
}
F_22 ( V_19 , L_4 , V_43 -> V_3 , V_49 ) ;
F_4 ( V_47 ) ;
return 0 ;
}
static int F_23 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
char * V_52 = V_12 -> V_20 . V_53 . V_54 ;
memcpy ( V_43 -> V_55 , V_52 , V_43 -> V_3 ) ;
if ( ! V_43 -> V_56 ) {
V_43 -> V_57 = 1 ;
return 0 ;
}
return F_19 ( V_10 , V_52 , V_43 -> V_3 ) ;
}
static int F_24 ( struct V_9 * V_10 ,
void * V_6 , T_1 V_3 )
{
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
struct V_46 * V_32 = & V_43 -> V_32 ;
const struct V_27 * V_31 ;
struct V_18 * V_19 = V_43 -> V_19 ;
void * V_47 ;
int V_48 ;
unsigned int V_49 ;
V_31 = F_14 ( V_19 , V_32 -> type ) ;
if ( ! V_31 ) {
F_20 ( V_19 , L_2 ,
V_32 -> type ) ;
return - V_24 ;
}
V_49 = V_43 -> V_32 . V_35 ;
V_49 = F_15 ( V_31 , V_49 ) ;
V_47 = F_25 ( V_43 -> V_3 , V_7 | V_8 ) ;
if ( ! V_47 )
return - V_50 ;
V_48 = F_26 ( V_19 -> V_51 , V_49 , V_47 , V_43 -> V_3 ) ;
if ( V_48 ) {
F_20 ( V_19 , L_5 ,
V_43 -> V_3 , V_49 , V_48 ) ;
F_4 ( V_47 ) ;
return V_48 ;
}
F_22 ( V_19 , L_6 , V_43 -> V_3 , V_49 ) ;
memcpy ( V_6 , V_47 , V_43 -> V_3 ) ;
F_4 ( V_47 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
char * V_52 = V_12 -> V_20 . V_53 . V_54 ;
memcpy ( V_52 , V_43 -> V_55 , V_43 -> V_3 ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 , struct V_42 * V_43 )
{
struct V_58 * V_10 ;
int V_48 ;
if ( ! V_43 || ! V_43 -> V_59 )
return - V_24 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_7 ) ;
if ( ! V_10 )
return - V_50 ;
V_10 -> V_60 = V_61 ;
V_10 -> V_59 = V_43 -> V_59 ;
V_10 -> V_62 = F_18 ;
V_10 -> V_63 = F_27 ;
V_10 -> V_64 = F_23 ;
V_10 -> V_17 = ( unsigned long ) V_43 ;
V_48 = F_29 ( V_19 -> V_65 ,
V_10 , 1 ) ;
if ( V_48 < 0 )
goto V_66;
F_4 ( V_10 ) ;
V_43 -> V_10 = F_30 ( V_19 -> V_65 ,
V_43 -> V_59 ) ;
F_31 ( & V_43 -> V_5 , & V_19 -> V_67 ) ;
return 0 ;
V_66:
F_4 ( V_10 ) ;
return V_48 ;
}
static int F_32 ( struct V_18 * V_28 )
{
F_33 ( V_68 ) ;
const struct V_69 * V_69 ;
struct V_51 * V_51 = V_28 -> V_51 ;
unsigned int V_70 = 0 ;
const struct V_71 * V_72 ;
const struct V_73 * V_74 ;
const struct V_75 * V_76 ;
const struct V_77 * V_78 ;
const struct V_79 * V_32 ;
const struct V_27 * V_31 ;
const char * V_80 ;
char * V_81 , * V_82 ;
struct V_1 * V_6 ;
unsigned int V_49 ;
int V_83 = 0 ;
int V_48 , V_33 , type , V_84 ;
V_81 = F_2 ( V_85 , V_7 ) ;
if ( V_81 == NULL )
return - V_50 ;
snprintf ( V_81 , V_85 , L_7 , V_28 -> V_86 , V_28 -> V_87 ,
V_88 [ V_28 -> V_22 ] . V_81 ) ;
V_81 [ V_85 - 1 ] = '\0' ;
V_48 = F_34 ( & V_69 , V_81 , V_28 -> V_89 ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_8 , V_81 ) ;
goto V_90;
}
V_48 = - V_24 ;
V_70 = sizeof( * V_72 ) + sizeof( * V_74 ) + sizeof( * V_78 ) ;
if ( V_70 >= V_69 -> V_91 ) {
F_20 ( V_28 , L_9 ,
V_81 , V_69 -> V_91 ) ;
goto V_92;
}
V_72 = ( void * ) & V_69 -> V_54 [ 0 ] ;
if ( memcmp ( & V_72 -> V_93 [ 0 ] , L_10 , 4 ) != 0 ) {
F_20 ( V_28 , L_11 , V_81 ) ;
goto V_92;
}
if ( V_72 -> V_94 != 0 ) {
F_20 ( V_28 , L_12 ,
V_81 , V_72 -> V_94 ) ;
goto V_92;
}
F_35 ( V_28 , L_13 , V_72 -> V_94 ) ;
if ( V_72 -> V_95 != V_28 -> type ) {
F_20 ( V_28 , L_14 ,
V_81 , V_72 -> V_95 , V_28 -> type ) ;
goto V_92;
}
switch ( V_28 -> type ) {
case V_96 :
V_70 = sizeof( * V_72 ) + sizeof( * V_74 ) + sizeof( * V_78 ) ;
V_74 = ( void * ) & ( V_72 [ 1 ] ) ;
V_78 = ( void * ) & ( V_74 [ 1 ] ) ;
V_84 = sizeof( * V_74 ) ;
F_22 ( V_28 , L_15 ,
V_81 , F_36 ( V_74 -> V_97 ) ,
F_36 ( V_74 -> V_98 ) ,
F_36 ( V_74 -> V_99 ) ) ;
break;
case V_100 :
V_70 = sizeof( * V_72 ) + sizeof( * V_76 ) + sizeof( * V_78 ) ;
V_76 = ( void * ) & ( V_72 [ 1 ] ) ;
V_78 = ( void * ) & ( V_76 [ 1 ] ) ;
V_84 = sizeof( * V_76 ) ;
F_22 ( V_28 , L_16 ,
V_81 , F_36 ( V_76 -> V_101 ) ,
F_36 ( V_76 -> V_102 ) ,
F_36 ( V_76 -> V_98 ) ,
F_36 ( V_76 -> V_99 ) ) ;
break;
default:
F_17 ( 1 , L_17 ) ;
goto V_92;
}
if ( F_36 ( V_72 -> V_3 ) != sizeof( * V_72 ) +
V_84 + sizeof( * V_78 ) ) {
F_20 ( V_28 , L_18 ,
V_81 , F_36 ( V_72 -> V_3 ) ) ;
goto V_92;
}
F_22 ( V_28 , L_19 , V_81 ,
F_37 ( V_78 -> V_103 ) ) ;
while ( V_70 < V_69 -> V_91 &&
V_70 - V_69 -> V_91 > sizeof( * V_32 ) ) {
V_32 = ( void * ) & ( V_69 -> V_54 [ V_70 ] ) ;
V_80 = L_20 ;
V_49 = 0 ;
V_82 = NULL ;
V_33 = F_36 ( V_32 -> V_33 ) & 0xffffff ;
type = F_38 ( V_32 -> type ) & 0xff ;
V_31 = F_14 ( V_28 , type ) ;
switch ( type ) {
case V_104 :
V_80 = L_21 ;
V_82 = F_2 ( F_36 ( V_32 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_105 :
V_80 = L_22 ;
V_82 = F_2 ( F_36 ( V_32 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_106 :
V_80 = L_23 ;
V_49 = V_33 ;
break;
case V_34 :
V_80 = L_24 ;
V_49 = F_15 ( V_31 , V_33 ) ;
break;
case V_36 :
V_80 = L_25 ;
V_49 = F_15 ( V_31 , V_33 ) ;
break;
case V_37 :
V_80 = L_26 ;
V_49 = F_15 ( V_31 , V_33 ) ;
break;
case V_38 :
V_80 = L_27 ;
V_49 = F_15 ( V_31 , V_33 ) ;
break;
case V_39 :
V_80 = L_28 ;
V_49 = F_15 ( V_31 , V_33 ) ;
break;
default:
F_39 ( V_28 ,
L_29 ,
V_81 , V_83 , type , V_70 , V_70 ) ;
break;
}
F_22 ( V_28 , L_30 , V_81 ,
V_83 , F_36 ( V_32 -> V_3 ) , V_33 ,
V_80 ) ;
if ( V_82 ) {
memcpy ( V_82 , V_32 -> V_54 , F_36 ( V_32 -> V_3 ) ) ;
F_35 ( V_28 , L_31 , V_81 , V_82 ) ;
F_4 ( V_82 ) ;
}
if ( V_49 ) {
T_1 V_107 = V_85 ;
T_1 V_108 = F_36 ( V_32 -> V_3 ) ;
const T_2 * V_54 = V_32 -> V_54 ;
while ( V_108 > 0 ) {
if ( V_108 < V_85 )
V_107 = V_108 ;
V_6 = F_1 ( V_54 ,
V_107 ,
& V_68 ) ;
if ( ! V_6 ) {
F_20 ( V_28 , L_32 ) ;
V_48 = - V_50 ;
goto V_92;
}
V_48 = F_40 ( V_51 , V_49 ,
V_6 -> V_6 ,
V_107 ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 ,
L_33 ,
V_81 , V_83 ,
V_107 , V_33 ,
V_80 , V_48 ) ;
goto V_92;
}
V_54 += V_107 ;
V_49 += V_107 / 2 ;
V_108 -= V_107 ;
}
}
V_70 += F_36 ( V_32 -> V_3 ) + sizeof( * V_32 ) ;
V_83 ++ ;
}
V_48 = F_41 ( V_51 ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_34 , V_48 ) ;
goto V_92;
}
if ( V_70 > V_69 -> V_91 )
F_39 ( V_28 , L_35 ,
V_81 , V_83 , V_70 - V_69 -> V_91 ) ;
V_92:
F_41 ( V_51 ) ;
F_6 ( & V_68 ) ;
F_42 ( V_69 ) ;
V_90:
F_4 ( V_81 ) ;
return V_48 ;
}
static int F_43 ( struct V_18 * V_19 )
{
struct V_42 * V_43 ;
int V_48 ;
F_44 (ctl, &adsp->ctl_list, list) {
if ( ! V_43 -> V_56 || V_43 -> V_57 )
continue;
V_48 = F_24 ( V_43 -> V_10 ,
V_43 -> V_55 ,
V_43 -> V_3 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_42 * V_43 ;
int V_48 ;
F_44 (ctl, &adsp->ctl_list, list) {
if ( ! V_43 -> V_56 )
continue;
if ( V_43 -> V_57 ) {
V_48 = F_19 ( V_43 -> V_10 ,
V_43 -> V_55 ,
V_43 -> V_3 ) ;
if ( V_48 < 0 )
return V_48 ;
}
}
return 0 ;
}
static void F_46 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = F_47 ( V_110 ,
struct V_111 ,
V_110 ) ;
F_28 ( V_112 -> V_19 , V_112 -> V_43 ) ;
F_4 ( V_112 ) ;
}
static int F_48 ( struct V_18 * V_28 ,
const struct V_46 * V_32 )
{
struct V_42 * V_43 ;
struct V_111 * V_112 ;
char * V_59 ;
char * V_80 ;
int V_48 ;
V_59 = F_25 ( V_85 , V_7 ) ;
if ( ! V_59 )
return - V_50 ;
switch ( V_32 -> type ) {
case V_34 :
V_80 = L_24 ;
break;
case V_36 :
V_80 = L_25 ;
break;
case V_37 :
V_80 = L_26 ;
break;
case V_38 :
V_80 = L_27 ;
break;
case V_39 :
V_80 = L_28 ;
break;
default:
V_48 = - V_24 ;
goto V_113;
}
snprintf ( V_59 , V_85 , L_36 ,
V_28 -> V_87 , V_80 , V_32 -> V_114 ) ;
F_44 (ctl, &dsp->ctl_list,
list) {
if ( ! strcmp ( V_43 -> V_59 , V_59 ) ) {
if ( ! V_43 -> V_56 )
V_43 -> V_56 = 1 ;
goto V_115;
}
}
V_43 = F_2 ( sizeof( * V_43 ) , V_7 ) ;
if ( ! V_43 ) {
V_48 = - V_50 ;
goto V_113;
}
V_43 -> V_32 = * V_32 ;
V_43 -> V_59 = F_3 ( V_59 , strlen ( V_59 ) + 1 , V_7 ) ;
if ( ! V_43 -> V_59 ) {
V_48 = - V_50 ;
goto V_116;
}
V_43 -> V_56 = 1 ;
V_43 -> V_57 = 0 ;
V_43 -> V_117 . V_118 = F_27 ;
V_43 -> V_117 . V_119 = F_23 ;
V_43 -> V_19 = V_28 ;
V_43 -> V_3 = V_32 -> V_3 ;
V_43 -> V_55 = F_2 ( V_43 -> V_3 , V_7 ) ;
if ( ! V_43 -> V_55 ) {
V_48 = - V_50 ;
goto V_120;
}
V_112 = F_2 ( sizeof( * V_112 ) , V_7 ) ;
if ( ! V_112 ) {
V_48 = - V_50 ;
goto V_121;
}
V_112 -> V_19 = V_28 ;
V_112 -> V_43 = V_43 ;
F_49 ( & V_112 -> V_110 , F_46 ) ;
F_50 ( & V_112 -> V_110 ) ;
V_115:
F_4 ( V_59 ) ;
return 0 ;
V_121:
F_4 ( V_43 -> V_55 ) ;
V_120:
F_4 ( V_43 -> V_59 ) ;
V_116:
F_4 ( V_43 ) ;
V_113:
F_4 ( V_59 ) ;
return V_48 ;
}
static int F_51 ( struct V_18 * V_28 )
{
struct V_51 * V_51 = V_28 -> V_51 ;
struct V_122 V_123 ;
struct V_124 V_125 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
void * V_114 , * V_6 ;
struct V_46 * V_32 ;
const struct V_27 * V_31 ;
unsigned int V_70 , V_130 ;
T_1 V_131 , V_132 ;
T_3 V_133 ;
int V_29 , V_48 ;
switch ( V_28 -> type ) {
case V_96 :
V_31 = F_14 ( V_28 , V_36 ) ;
break;
case V_100 :
V_31 = F_14 ( V_28 , V_37 ) ;
break;
default:
V_31 = NULL ;
break;
}
if ( F_16 ( ! V_31 ) )
return - V_24 ;
switch ( V_28 -> type ) {
case V_96 :
V_48 = F_26 ( V_51 , V_31 -> V_35 , & V_123 ,
sizeof( V_123 ) ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_37 ,
V_48 ) ;
return V_48 ;
}
V_6 = & V_123 ;
V_132 = sizeof( V_123 ) ;
V_131 = F_38 ( V_123 . V_131 ) ;
V_28 -> V_134 = F_38 ( V_123 . V_22 . V_135 ) ;
F_35 ( V_28 , L_38 ,
V_28 -> V_134 ,
( F_38 ( V_123 . V_22 . V_94 ) & 0xff0000 ) >> 16 ,
( F_38 ( V_123 . V_22 . V_94 ) & 0xff00 ) >> 8 ,
F_38 ( V_123 . V_22 . V_94 ) & 0xff ,
V_131 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_39 ;
V_32 -> V_114 = F_38 ( V_123 . V_22 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_123 . V_99 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_36 ;
V_32 -> V_114 = F_38 ( V_123 . V_22 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_123 . V_97 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
V_70 = sizeof( V_123 ) / 2 ;
V_130 = V_70 + ( ( sizeof( * V_127 ) * V_131 ) / 2 ) ;
break;
case V_100 :
V_48 = F_26 ( V_51 , V_31 -> V_35 , & V_125 ,
sizeof( V_125 ) ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_37 ,
V_48 ) ;
return V_48 ;
}
V_6 = & V_125 ;
V_132 = sizeof( V_125 ) ;
V_131 = F_38 ( V_125 . V_131 ) ;
V_28 -> V_134 = F_38 ( V_125 . V_22 . V_135 ) ;
F_35 ( V_28 , L_38 ,
V_28 -> V_134 ,
( F_38 ( V_125 . V_22 . V_94 ) & 0xff0000 ) >> 16 ,
( F_38 ( V_125 . V_22 . V_94 ) & 0xff00 ) >> 8 ,
F_38 ( V_125 . V_22 . V_94 ) & 0xff ,
V_131 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_37 ;
V_32 -> V_114 = F_38 ( V_125 . V_22 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_125 . V_101 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_38 ;
V_32 -> V_114 = F_38 ( V_125 . V_22 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_125 . V_102 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_137 ;
V_32 -> V_114 = F_38 ( V_125 . V_22 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_125 . V_99 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
V_70 = sizeof( V_125 ) / 2 ;
V_130 = V_70 + ( ( sizeof( * V_129 ) * V_131 ) / 2 ) ;
break;
default:
F_17 ( 1 , L_17 ) ;
return - V_24 ;
}
if ( V_131 == 0 ) {
F_20 ( V_28 , L_39 ) ;
return - V_24 ;
}
if ( V_131 > 1024 ) {
F_20 ( V_28 , L_40 , V_131 ) ;
F_52 ( F_53 ( V_28 -> V_89 ) , V_138 ,
V_6 , V_132 ) ;
return - V_24 ;
}
V_48 = F_26 ( V_51 , V_31 -> V_35 + V_130 , & V_133 , sizeof( V_133 ) ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_41 ,
V_48 ) ;
return V_48 ;
}
if ( F_38 ( V_133 ) != 0xbedead )
F_39 ( V_28 , L_42 ,
V_130 , F_38 ( V_133 ) ) ;
V_114 = F_2 ( ( V_130 - V_70 ) * 2 , V_7 | V_8 ) ;
if ( ! V_114 )
return - V_50 ;
V_48 = F_26 ( V_51 , V_31 -> V_35 + V_70 , V_114 , ( V_130 - V_70 ) * 2 ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_43 ,
V_48 ) ;
goto V_90;
}
V_127 = V_114 ;
V_129 = V_114 ;
for ( V_29 = 0 ; V_29 < V_131 ; V_29 ++ ) {
switch ( V_28 -> type ) {
case V_96 :
F_35 ( V_28 , L_44 ,
V_29 , F_38 ( V_127 [ V_29 ] . V_114 . V_135 ) ,
( F_38 ( V_127 [ V_29 ] . V_114 . V_94 ) & 0xff0000 ) >> 16 ,
( F_38 ( V_127 [ V_29 ] . V_114 . V_94 ) & 0xff00 ) >> 8 ,
F_38 ( V_127 [ V_29 ] . V_114 . V_94 ) & 0xff ,
F_38 ( V_127 [ V_29 ] . V_97 ) ,
F_38 ( V_127 [ V_29 ] . V_99 ) ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_36 ;
V_32 -> V_114 = F_38 ( V_127 [ V_29 ] . V_114 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_127 [ V_29 ] . V_97 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
if ( V_29 + 1 < V_131 ) {
V_32 -> V_3 = F_38 ( V_127 [ V_29 + 1 ] . V_97 ) ;
V_32 -> V_3 -= F_38 ( V_127 [ V_29 ] . V_97 ) ;
V_32 -> V_3 *= 4 ;
F_48 ( V_28 , V_32 ) ;
} else {
F_39 ( V_28 , L_45 ,
F_38 ( V_127 [ V_29 ] . V_114 . V_135 ) ) ;
}
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_39 ;
V_32 -> V_114 = F_38 ( V_127 [ V_29 ] . V_114 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_127 [ V_29 ] . V_99 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
if ( V_29 + 1 < V_131 ) {
V_32 -> V_3 = F_38 ( V_127 [ V_29 + 1 ] . V_99 ) ;
V_32 -> V_3 -= F_38 ( V_127 [ V_29 ] . V_99 ) ;
V_32 -> V_3 *= 4 ;
F_48 ( V_28 , V_32 ) ;
} else {
F_39 ( V_28 , L_46 ,
F_38 ( V_127 [ V_29 ] . V_114 . V_135 ) ) ;
}
break;
case V_100 :
F_35 ( V_28 ,
L_47 ,
V_29 , F_38 ( V_129 [ V_29 ] . V_114 . V_135 ) ,
( F_38 ( V_129 [ V_29 ] . V_114 . V_94 ) & 0xff0000 ) >> 16 ,
( F_38 ( V_129 [ V_29 ] . V_114 . V_94 ) & 0xff00 ) >> 8 ,
F_38 ( V_129 [ V_29 ] . V_114 . V_94 ) & 0xff ,
F_38 ( V_129 [ V_29 ] . V_101 ) ,
F_38 ( V_129 [ V_29 ] . V_102 ) ,
F_38 ( V_129 [ V_29 ] . V_99 ) ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_37 ;
V_32 -> V_114 = F_38 ( V_129 [ V_29 ] . V_114 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_129 [ V_29 ] . V_101 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
if ( V_29 + 1 < V_131 ) {
V_32 -> V_3 = F_38 ( V_129 [ V_29 + 1 ] . V_101 ) ;
V_32 -> V_3 -= F_38 ( V_129 [ V_29 ] . V_101 ) ;
V_32 -> V_3 *= 4 ;
F_48 ( V_28 , V_32 ) ;
} else {
F_39 ( V_28 , L_48 ,
F_38 ( V_129 [ V_29 ] . V_114 . V_135 ) ) ;
}
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_38 ;
V_32 -> V_114 = F_38 ( V_129 [ V_29 ] . V_114 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_129 [ V_29 ] . V_102 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
if ( V_29 + 1 < V_131 ) {
V_32 -> V_3 = F_38 ( V_129 [ V_29 + 1 ] . V_102 ) ;
V_32 -> V_3 -= F_38 ( V_129 [ V_29 ] . V_102 ) ;
V_32 -> V_3 *= 4 ;
F_48 ( V_28 , V_32 ) ;
} else {
F_39 ( V_28 , L_49 ,
F_38 ( V_129 [ V_29 ] . V_114 . V_135 ) ) ;
}
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> type = V_137 ;
V_32 -> V_114 = F_38 ( V_129 [ V_29 ] . V_114 . V_135 ) ;
V_32 -> V_35 = F_38 ( V_129 [ V_29 ] . V_99 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_136 ) ;
if ( V_29 + 1 < V_131 ) {
V_32 -> V_3 = F_38 ( V_129 [ V_29 + 1 ] . V_99 ) ;
V_32 -> V_3 -= F_38 ( V_129 [ V_29 ] . V_99 ) ;
V_32 -> V_3 *= 4 ;
F_48 ( V_28 , V_32 ) ;
} else {
F_39 ( V_28 , L_46 ,
F_38 ( V_129 [ V_29 ] . V_114 . V_135 ) ) ;
}
break;
}
}
V_90:
F_4 ( V_114 ) ;
return V_48 ;
}
static int F_54 ( struct V_18 * V_28 )
{
F_33 ( V_68 ) ;
struct V_51 * V_51 = V_28 -> V_51 ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
const struct V_69 * V_69 ;
const struct V_27 * V_31 ;
struct V_46 * V_143 ;
const char * V_80 ;
int V_48 , V_70 , V_144 , type , V_33 , V_49 ;
char * V_81 ;
struct V_1 * V_6 ;
int V_145 ;
V_81 = F_2 ( V_85 , V_7 ) ;
if ( V_81 == NULL )
return - V_50 ;
snprintf ( V_81 , V_85 , L_50 , V_28 -> V_86 , V_28 -> V_87 ,
V_88 [ V_28 -> V_22 ] . V_81 ) ;
V_81 [ V_85 - 1 ] = '\0' ;
V_48 = F_34 ( & V_69 , V_81 , V_28 -> V_89 ) ;
if ( V_48 != 0 ) {
F_39 ( V_28 , L_8 , V_81 ) ;
V_48 = 0 ;
goto V_90;
}
V_48 = - V_24 ;
if ( sizeof( * V_140 ) >= V_69 -> V_91 ) {
F_20 ( V_28 , L_9 ,
V_81 , V_69 -> V_91 ) ;
goto V_92;
}
V_140 = ( void * ) & V_69 -> V_54 [ 0 ] ;
if ( memcmp ( V_140 -> V_93 , L_51 , 4 ) != 0 ) {
F_20 ( V_28 , L_11 , V_81 ) ;
goto V_92;
}
switch ( F_38 ( V_140 -> V_146 ) & 0xff ) {
case 1 :
break;
default:
F_20 ( V_28 , L_52 ,
V_81 , F_38 ( V_140 -> V_146 ) & 0xff ) ;
V_48 = - V_24 ;
goto V_92;
}
F_22 ( V_28 , L_53 , V_81 ,
( F_36 ( V_140 -> V_94 ) >> 16 ) & 0xff ,
( F_36 ( V_140 -> V_94 ) >> 8 ) & 0xff ,
F_36 ( V_140 -> V_94 ) & 0xff ) ;
V_70 = F_36 ( V_140 -> V_3 ) ;
V_144 = 0 ;
while ( V_70 < V_69 -> V_91 &&
V_70 - V_69 -> V_91 > sizeof( * V_142 ) ) {
V_142 = ( void * ) ( & V_69 -> V_54 [ V_70 ] ) ;
type = F_55 ( V_142 -> type ) ;
V_33 = F_55 ( V_142 -> V_33 ) ;
F_22 ( V_28 , L_54 ,
V_81 , V_144 , F_36 ( V_142 -> V_135 ) ,
( F_36 ( V_142 -> V_94 ) >> 16 ) & 0xff ,
( F_36 ( V_142 -> V_94 ) >> 8 ) & 0xff ,
F_36 ( V_142 -> V_94 ) & 0xff ) ;
F_22 ( V_28 , L_55 ,
V_81 , V_144 , F_36 ( V_142 -> V_3 ) , V_33 , type ) ;
V_49 = 0 ;
V_80 = L_20 ;
switch ( type ) {
case ( V_104 << 8 ) :
case ( V_105 << 8 ) :
break;
case ( V_106 << 8 ) :
if ( F_36 ( V_142 -> V_135 ) == V_28 -> V_134 &&
V_33 == 0 ) {
V_80 = L_56 ;
V_31 = F_14 ( V_28 , type ) ;
if ( ! V_31 ) {
F_20 ( V_28 , L_57 ) ;
break;
}
V_49 = F_15 ( V_31 , 0 ) ;
} else {
V_80 = L_58 ;
V_49 = V_33 ;
}
break;
case V_36 :
case V_39 :
case V_37 :
case V_38 :
F_22 ( V_28 , L_59 ,
V_81 , V_144 , F_36 ( V_142 -> V_3 ) ,
type , F_36 ( V_142 -> V_135 ) ) ;
V_31 = F_14 ( V_28 , type ) ;
if ( ! V_31 ) {
F_20 ( V_28 , L_2 , type ) ;
break;
}
V_49 = 0 ;
F_44 (alg_region,
&dsp->alg_regions, list) {
if ( F_36 ( V_142 -> V_135 ) == V_143 -> V_114 &&
type == V_143 -> type ) {
V_49 = V_143 -> V_35 ;
V_49 = F_15 ( V_31 ,
V_49 ) ;
V_49 += V_33 ;
break;
}
}
if ( V_49 == 0 )
F_20 ( V_28 , L_60 ,
type , F_36 ( V_142 -> V_135 ) ) ;
break;
default:
F_20 ( V_28 , L_61 ,
V_81 , V_144 , type , V_70 ) ;
break;
}
if ( V_49 ) {
V_6 = F_1 ( V_142 -> V_54 ,
F_36 ( V_142 -> V_3 ) ,
& V_68 ) ;
if ( ! V_6 ) {
F_20 ( V_28 , L_32 ) ;
V_48 = - V_50 ;
goto V_92;
}
F_22 ( V_28 , L_62 ,
V_81 , V_144 , F_36 ( V_142 -> V_3 ) ,
V_49 ) ;
V_48 = F_40 ( V_51 , V_49 , V_6 -> V_6 ,
F_36 ( V_142 -> V_3 ) ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 ,
L_63 ,
V_81 , V_144 , V_49 , V_80 , V_48 ) ;
}
}
V_145 = F_36 ( V_142 -> V_3 ) % 4 ;
if ( V_145 )
V_70 += F_36 ( V_142 -> V_3 ) + ( 4 - V_145 ) + sizeof( * V_142 ) ;
else
V_70 += F_36 ( V_142 -> V_3 ) + sizeof( * V_142 ) ;
V_144 ++ ;
}
V_48 = F_41 ( V_51 ) ;
if ( V_48 != 0 )
F_20 ( V_28 , L_34 , V_48 ) ;
if ( V_70 > V_69 -> V_91 )
F_39 ( V_28 , L_35 ,
V_81 , V_144 , V_70 - V_69 -> V_91 ) ;
V_92:
F_42 ( V_69 ) ;
F_6 ( & V_68 ) ;
V_90:
F_4 ( V_81 ) ;
return V_48 ;
}
int F_56 ( struct V_18 * V_19 )
{
F_57 ( & V_19 -> V_136 ) ;
return 0 ;
}
int F_58 ( struct V_147 * V_148 ,
struct V_9 * V_10 ,
int V_149 )
{
struct V_13 * V_14 = V_148 -> V_14 ;
struct V_18 * V_150 = F_12 ( V_14 ) ;
struct V_18 * V_28 = & V_150 [ V_148 -> V_151 ] ;
struct V_46 * V_143 ;
struct V_42 * V_43 ;
int V_48 ;
int V_133 ;
V_28 -> V_65 = V_14 -> V_65 ;
switch ( V_149 ) {
case V_152 :
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_153 ,
V_154 , V_154 ) ;
if( V_28 -> V_155 ) {
V_48 = F_60 ( V_28 -> V_51 , V_28 -> V_155 , & V_133 ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_64 ,
V_48 ) ;
return V_48 ;
}
V_133 = ( V_133 & V_28 -> V_156 )
>> V_28 -> V_157 ;
V_48 = F_59 ( V_28 -> V_51 ,
V_28 -> V_35 + V_158 ,
V_159 , V_133 ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_65 ,
V_48 ) ;
return V_48 ;
}
}
V_48 = F_32 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_51 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_54 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_43 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_45 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_153 ,
V_161 | V_162 ,
V_161 | V_162 ) ;
break;
case V_163 :
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_153 ,
V_161 | V_162 , 0 ) ;
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_164 ,
V_165 , 0 ) ;
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_153 ,
V_154 , 0 ) ;
F_44 (ctl, &dsp->ctl_list, list)
V_43 -> V_56 = 0 ;
while ( ! F_7 ( & V_28 -> V_136 ) ) {
V_143 = F_8 ( & V_28 -> V_136 ,
struct V_46 ,
V_5 ) ;
F_9 ( & V_143 -> V_5 ) ;
F_4 ( V_143 ) ;
}
break;
default:
break;
}
return 0 ;
V_160:
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_153 ,
V_154 , 0 ) ;
return V_48 ;
}
static int F_61 ( struct V_18 * V_28 )
{
unsigned int V_133 ;
int V_48 , V_45 ;
V_48 = F_62 ( V_28 -> V_51 , V_28 -> V_35 + V_166 ,
V_167 , V_167 ) ;
if ( V_48 != 0 )
return V_48 ;
for ( V_45 = 0 ; V_45 < 10 ; ++ V_45 ) {
V_48 = F_60 ( V_28 -> V_51 , V_28 -> V_35 + V_168 ,
& V_133 ) ;
if ( V_48 != 0 )
return V_48 ;
if ( V_133 & V_169 )
break;
F_63 ( 1 ) ;
}
if ( ! ( V_133 & V_169 ) ) {
F_20 ( V_28 , L_66 ) ;
return - V_26 ;
}
F_22 ( V_28 , L_67 , V_45 ) ;
return 0 ;
}
static void F_64 ( struct V_109 * V_110 )
{
struct V_18 * V_28 = F_47 ( V_110 ,
struct V_18 ,
V_170 ) ;
int V_48 ;
unsigned int V_133 ;
V_48 = F_60 ( V_28 -> V_51 , V_171 , & V_133 ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_64 , V_48 ) ;
return;
}
V_133 = ( V_133 & V_172 )
>> V_173 ;
V_48 = F_62 ( V_28 -> V_51 ,
V_28 -> V_35 + V_174 ,
V_175 , V_133 ) ;
if ( V_48 != 0 ) {
F_20 ( V_28 , L_65 , V_48 ) ;
return;
}
if ( V_28 -> V_176 ) {
V_48 = F_60 ( V_28 -> V_51 ,
V_28 -> V_35 + V_174 , & V_133 ) ;
if ( V_48 != 0 ) {
F_65 ( V_28 -> V_89 , L_68 , V_48 ) ;
return;
}
if ( ( V_133 & V_175 ) >= 3 ) {
V_48 = F_66 ( V_28 -> V_176 ) ;
if ( V_48 != 0 ) {
F_65 ( V_28 -> V_89 ,
L_69 ,
V_48 ) ;
return;
}
V_48 = F_67 ( V_28 -> V_176 ,
1800000 ,
1800000 ) ;
if ( V_48 != 0 ) {
F_65 ( V_28 -> V_89 ,
L_70 ,
V_48 ) ;
return;
}
}
}
V_48 = F_61 ( V_28 ) ;
if ( V_48 != 0 )
return;
V_48 = F_32 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_51 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_54 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_43 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_45 ( V_28 ) ;
if ( V_48 != 0 )
goto V_160;
V_48 = F_62 ( V_28 -> V_51 ,
V_28 -> V_35 + V_166 ,
V_177 ,
V_177 ) ;
if ( V_48 != 0 )
goto V_160;
V_28 -> V_25 = true ;
return;
V_160:
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_166 ,
V_167 | V_177 | V_178 , 0 ) ;
}
int F_68 ( struct V_147 * V_148 ,
struct V_9 * V_10 , int V_149 )
{
struct V_13 * V_14 = V_148 -> V_14 ;
struct V_18 * V_150 = F_12 ( V_14 ) ;
struct V_18 * V_28 = & V_150 [ V_148 -> V_151 ] ;
V_28 -> V_65 = V_14 -> V_65 ;
switch ( V_149 ) {
case V_179 :
F_69 ( V_180 , & V_28 -> V_170 ) ;
break;
default:
break;
} ;
return 0 ;
}
int F_70 ( struct V_147 * V_148 ,
struct V_9 * V_10 , int V_149 )
{
struct V_13 * V_14 = V_148 -> V_14 ;
struct V_18 * V_150 = F_12 ( V_14 ) ;
struct V_18 * V_28 = & V_150 [ V_148 -> V_151 ] ;
struct V_46 * V_143 ;
struct V_42 * V_43 ;
int V_48 ;
switch ( V_149 ) {
case V_152 :
F_71 ( & V_28 -> V_170 ) ;
if ( ! V_28 -> V_25 )
return - V_181 ;
V_48 = F_59 ( V_28 -> V_51 ,
V_28 -> V_35 + V_166 ,
V_178 ,
V_178 ) ;
if ( V_48 != 0 )
goto V_160;
break;
case V_163 :
V_28 -> V_25 = false ;
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_166 ,
V_167 | V_177 |
V_178 , 0 ) ;
F_72 ( V_28 -> V_51 , V_28 -> V_35 + V_182 , 0 ) ;
F_72 ( V_28 -> V_51 , V_28 -> V_35 + V_183 , 0 ) ;
F_72 ( V_28 -> V_51 , V_28 -> V_35 + V_184 , 0 ) ;
if ( V_28 -> V_176 ) {
V_48 = F_67 ( V_28 -> V_176 , 1200000 ,
1800000 ) ;
if ( V_48 != 0 )
F_73 ( V_28 -> V_89 ,
L_71 ,
V_48 ) ;
V_48 = F_74 ( V_28 -> V_176 ) ;
if ( V_48 != 0 )
F_65 ( V_28 -> V_89 ,
L_69 ,
V_48 ) ;
}
F_44 (ctl, &dsp->ctl_list, list)
V_43 -> V_56 = 0 ;
while ( ! F_7 ( & V_28 -> V_136 ) ) {
V_143 = F_8 ( & V_28 -> V_136 ,
struct V_46 ,
V_5 ) ;
F_9 ( & V_143 -> V_5 ) ;
F_4 ( V_143 ) ;
}
F_22 ( V_28 , L_72 ) ;
break;
default:
break;
}
return 0 ;
V_160:
F_59 ( V_28 -> V_51 , V_28 -> V_35 + V_166 ,
V_167 | V_177 | V_178 , 0 ) ;
return V_48 ;
}
int F_75 ( struct V_18 * V_19 , bool V_176 )
{
int V_48 ;
V_48 = F_59 ( V_19 -> V_51 , V_19 -> V_35 + V_166 ,
V_185 , 0 ) ;
if ( V_48 != 0 ) {
F_20 ( V_19 , L_73 , V_48 ) ;
return V_48 ;
}
F_57 ( & V_19 -> V_136 ) ;
F_57 ( & V_19 -> V_67 ) ;
F_49 ( & V_19 -> V_170 , F_64 ) ;
if ( V_176 ) {
V_19 -> V_176 = F_76 ( V_19 -> V_89 , L_74 ) ;
if ( F_77 ( V_19 -> V_176 ) ) {
V_48 = F_78 ( V_19 -> V_176 ) ;
F_65 ( V_19 -> V_89 , L_75 , V_48 ) ;
return V_48 ;
}
V_48 = F_66 ( V_19 -> V_176 ) ;
if ( V_48 != 0 ) {
F_65 ( V_19 -> V_89 , L_76 ,
V_48 ) ;
return V_48 ;
}
V_48 = F_67 ( V_19 -> V_176 , 1200000 , 1800000 ) ;
if ( V_48 != 0 ) {
F_65 ( V_19 -> V_89 , L_77 ,
V_48 ) ;
return V_48 ;
}
V_48 = F_74 ( V_19 -> V_176 ) ;
if ( V_48 != 0 ) {
F_65 ( V_19 -> V_89 , L_78 ,
V_48 ) ;
return V_48 ;
}
}
return 0 ;
}
