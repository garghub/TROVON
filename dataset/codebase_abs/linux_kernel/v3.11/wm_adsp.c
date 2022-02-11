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
F_16 ( NULL != L_1 ) ;
return V_33 ;
}
}
static int F_17 ( struct V_9 * V_10 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
V_41 -> type = V_44 ;
V_41 -> V_45 = V_43 -> V_3 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 ,
const void * V_6 , T_1 V_3 )
{
struct V_46 * V_46 = F_11 ( V_10 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
struct V_47 * V_32 = & V_43 -> V_32 ;
const struct V_27 * V_31 ;
struct V_18 * V_19 = V_43 -> V_19 ;
void * V_48 ;
int V_49 ;
unsigned int V_50 ;
V_31 = F_14 ( V_19 , V_32 -> type ) ;
if ( ! V_31 ) {
F_19 ( V_19 , L_2 ,
V_32 -> type ) ;
return - V_24 ;
}
V_50 = V_43 -> V_32 . V_35 ;
V_50 = F_15 ( V_31 , V_50 ) ;
V_48 = F_3 ( V_6 , V_43 -> V_3 , V_7 | V_8 ) ;
if ( ! V_48 )
return - V_51 ;
V_49 = F_20 ( V_46 -> V_52 , V_50 , V_48 ,
V_43 -> V_3 ) ;
if ( V_49 ) {
F_19 ( V_19 , L_3 ,
V_43 -> V_3 , V_50 ) ;
F_4 ( V_48 ) ;
return V_49 ;
}
F_4 ( V_48 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
char * V_53 = V_12 -> V_20 . V_54 . V_55 ;
memcpy ( V_43 -> V_56 , V_53 , V_43 -> V_3 ) ;
if ( ! V_43 -> V_57 ) {
V_43 -> V_58 = 1 ;
return 0 ;
}
return F_18 ( V_10 , V_53 , V_43 -> V_3 ) ;
}
static int F_22 ( struct V_9 * V_10 ,
void * V_6 , T_1 V_3 )
{
struct V_46 * V_46 = F_11 ( V_10 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
struct V_47 * V_32 = & V_43 -> V_32 ;
const struct V_27 * V_31 ;
struct V_18 * V_19 = V_43 -> V_19 ;
void * V_48 ;
int V_49 ;
unsigned int V_50 ;
V_31 = F_14 ( V_19 , V_32 -> type ) ;
if ( ! V_31 ) {
F_19 ( V_19 , L_2 ,
V_32 -> type ) ;
return - V_24 ;
}
V_50 = V_43 -> V_32 . V_35 ;
V_50 = F_15 ( V_31 , V_50 ) ;
V_48 = F_23 ( V_43 -> V_3 , V_7 | V_8 ) ;
if ( ! V_48 )
return - V_51 ;
V_49 = F_24 ( V_46 -> V_52 , V_50 , V_48 , V_43 -> V_3 ) ;
if ( V_49 ) {
F_19 ( V_19 , L_4 ,
V_43 -> V_3 , V_50 ) ;
F_4 ( V_48 ) ;
return V_49 ;
}
memcpy ( V_6 , V_48 , V_43 -> V_3 ) ;
F_4 ( V_48 ) ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_42 * V_43 = (struct V_42 * ) V_10 -> V_17 ;
char * V_53 = V_12 -> V_20 . V_54 . V_55 ;
memcpy ( V_53 , V_43 -> V_56 , V_43 -> V_3 ) ;
return 0 ;
}
static int F_26 ( struct V_46 * V_46 ,
struct V_42 * V_43 ,
const struct V_59 * V_60 )
{
int V_49 ;
struct V_9 * V_10 ;
V_10 = F_27 ( V_60 , V_46 ) ;
V_49 = F_28 ( V_43 -> V_61 , V_10 ) ;
if ( V_49 < 0 ) {
F_29 ( V_46 -> V_62 , L_5 ,
V_60 -> V_63 , V_49 ) ;
return V_49 ;
}
V_43 -> V_10 = V_10 ;
return 0 ;
}
static int F_30 ( struct V_46 * V_46 ,
struct V_42 * V_43 )
{
struct V_59 * V_10 ;
int V_49 ;
if ( ! V_46 || ! V_43 || ! V_43 -> V_63 || ! V_43 -> V_61 )
return - V_24 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_7 ) ;
if ( ! V_10 )
return - V_51 ;
V_10 -> V_64 = V_65 ;
V_10 -> V_63 = V_43 -> V_63 ;
V_10 -> V_66 = F_17 ;
V_10 -> V_67 = F_25 ;
V_10 -> V_68 = F_21 ;
V_10 -> V_17 = ( unsigned long ) V_43 ;
V_49 = F_26 ( V_46 ,
V_43 , V_10 ) ;
if ( V_49 < 0 )
goto V_69;
F_4 ( V_10 ) ;
F_31 ( & V_43 -> V_5 , & V_46 -> V_70 ) ;
return 0 ;
V_69:
F_4 ( V_10 ) ;
return V_49 ;
}
static int F_32 ( struct V_18 * V_28 )
{
F_33 ( V_71 ) ;
const struct V_72 * V_72 ;
struct V_52 * V_52 = V_28 -> V_52 ;
unsigned int V_73 = 0 ;
const struct V_74 * V_75 ;
const struct V_76 * V_77 ;
const struct V_78 * V_79 ;
const struct V_80 * V_81 ;
const struct V_82 * V_32 ;
const struct V_27 * V_31 ;
const char * V_83 ;
char * V_84 , * V_85 ;
struct V_1 * V_6 ;
unsigned int V_50 ;
int V_86 = 0 ;
int V_49 , V_33 , type , V_87 ;
V_84 = F_2 ( V_88 , V_7 ) ;
if ( V_84 == NULL )
return - V_51 ;
snprintf ( V_84 , V_88 , L_6 , V_28 -> V_89 , V_28 -> V_90 ,
V_91 [ V_28 -> V_22 ] . V_84 ) ;
V_84 [ V_88 - 1 ] = '\0' ;
V_49 = F_34 ( & V_72 , V_84 , V_28 -> V_62 ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_7 , V_84 ) ;
goto V_92;
}
V_49 = - V_24 ;
V_73 = sizeof( * V_75 ) + sizeof( * V_77 ) + sizeof( * V_81 ) ;
if ( V_73 >= V_72 -> V_93 ) {
F_19 ( V_28 , L_8 ,
V_84 , V_72 -> V_93 ) ;
goto V_94;
}
V_75 = ( void * ) & V_72 -> V_55 [ 0 ] ;
if ( memcmp ( & V_75 -> V_95 [ 0 ] , L_9 , 4 ) != 0 ) {
F_19 ( V_28 , L_10 , V_84 ) ;
goto V_94;
}
if ( V_75 -> V_96 != 0 ) {
F_19 ( V_28 , L_11 ,
V_84 , V_75 -> V_96 ) ;
goto V_94;
}
if ( V_75 -> V_97 != V_28 -> type ) {
F_19 ( V_28 , L_12 ,
V_84 , V_75 -> V_97 , V_28 -> type ) ;
goto V_94;
}
switch ( V_28 -> type ) {
case V_98 :
V_73 = sizeof( * V_75 ) + sizeof( * V_77 ) + sizeof( * V_81 ) ;
V_77 = ( void * ) & ( V_75 [ 1 ] ) ;
V_81 = ( void * ) & ( V_77 [ 1 ] ) ;
V_87 = sizeof( * V_77 ) ;
F_35 ( V_28 , L_13 ,
V_84 , F_36 ( V_77 -> V_99 ) ,
F_36 ( V_77 -> V_100 ) ,
F_36 ( V_77 -> V_101 ) ) ;
break;
case V_102 :
V_73 = sizeof( * V_75 ) + sizeof( * V_79 ) + sizeof( * V_81 ) ;
V_79 = ( void * ) & ( V_75 [ 1 ] ) ;
V_81 = ( void * ) & ( V_79 [ 1 ] ) ;
V_87 = sizeof( * V_79 ) ;
F_35 ( V_28 , L_14 ,
V_84 , F_36 ( V_79 -> V_103 ) ,
F_36 ( V_79 -> V_104 ) ,
F_36 ( V_79 -> V_100 ) ,
F_36 ( V_79 -> V_101 ) ) ;
break;
default:
F_37 ( NULL == L_15 ) ;
goto V_94;
}
if ( F_36 ( V_75 -> V_3 ) != sizeof( * V_75 ) +
V_87 + sizeof( * V_81 ) ) {
F_19 ( V_28 , L_16 ,
V_84 , F_36 ( V_75 -> V_3 ) ) ;
goto V_94;
}
F_35 ( V_28 , L_17 , V_84 ,
F_38 ( V_81 -> V_105 ) ) ;
while ( V_73 < V_72 -> V_93 &&
V_73 - V_72 -> V_93 > sizeof( * V_32 ) ) {
V_32 = ( void * ) & ( V_72 -> V_55 [ V_73 ] ) ;
V_83 = L_18 ;
V_50 = 0 ;
V_85 = NULL ;
V_33 = F_36 ( V_32 -> V_33 ) & 0xffffff ;
type = F_39 ( V_32 -> type ) & 0xff ;
V_31 = F_14 ( V_28 , type ) ;
switch ( type ) {
case V_106 :
V_83 = L_19 ;
V_85 = F_2 ( F_36 ( V_32 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_107 :
V_83 = L_20 ;
V_85 = F_2 ( F_36 ( V_32 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_108 :
V_83 = L_21 ;
V_50 = V_33 ;
break;
case V_34 :
F_37 ( ! V_31 ) ;
V_83 = L_22 ;
V_50 = F_15 ( V_31 , V_33 ) ;
break;
case V_36 :
F_37 ( ! V_31 ) ;
V_83 = L_23 ;
V_50 = F_15 ( V_31 , V_33 ) ;
break;
case V_37 :
F_37 ( ! V_31 ) ;
V_83 = L_24 ;
V_50 = F_15 ( V_31 , V_33 ) ;
break;
case V_38 :
F_37 ( ! V_31 ) ;
V_83 = L_25 ;
V_50 = F_15 ( V_31 , V_33 ) ;
break;
case V_39 :
F_37 ( ! V_31 ) ;
V_83 = L_26 ;
V_50 = F_15 ( V_31 , V_33 ) ;
break;
default:
F_40 ( V_28 ,
L_27 ,
V_84 , V_86 , type , V_73 , V_73 ) ;
break;
}
F_35 ( V_28 , L_28 , V_84 ,
V_86 , F_36 ( V_32 -> V_3 ) , V_33 ,
V_83 ) ;
if ( V_85 ) {
memcpy ( V_85 , V_32 -> V_55 , F_36 ( V_32 -> V_3 ) ) ;
F_41 ( V_28 , L_29 , V_84 , V_85 ) ;
F_4 ( V_85 ) ;
}
if ( V_50 ) {
V_6 = F_1 ( V_32 -> V_55 ,
F_36 ( V_32 -> V_3 ) ,
& V_71 ) ;
if ( ! V_6 ) {
F_19 ( V_28 , L_30 ) ;
return - V_51 ;
}
V_49 = F_42 ( V_52 , V_50 , V_6 -> V_6 ,
F_36 ( V_32 -> V_3 ) ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 ,
L_31 ,
V_84 , V_86 ,
F_36 ( V_32 -> V_3 ) , V_33 ,
V_83 , V_49 ) ;
goto V_94;
}
}
V_73 += F_36 ( V_32 -> V_3 ) + sizeof( * V_32 ) ;
V_86 ++ ;
}
V_49 = F_43 ( V_52 ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_32 , V_49 ) ;
goto V_94;
}
if ( V_73 > V_72 -> V_93 )
F_40 ( V_28 , L_33 ,
V_84 , V_86 , V_73 - V_72 -> V_93 ) ;
V_94:
F_43 ( V_52 ) ;
F_6 ( & V_71 ) ;
F_44 ( V_72 ) ;
V_92:
F_4 ( V_84 ) ;
return V_49 ;
}
static int F_45 ( struct V_46 * V_46 )
{
struct V_42 * V_43 ;
int V_49 ;
F_46 (ctl, &wm_coeff->ctl_list,
list) {
if ( ! V_43 -> V_57 || V_43 -> V_58 )
continue;
V_49 = F_22 ( V_43 -> V_10 ,
V_43 -> V_56 ,
V_43 -> V_3 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return 0 ;
}
static int F_47 ( struct V_46 * V_46 )
{
struct V_42 * V_43 ;
int V_49 ;
F_46 (ctl, &wm_coeff->ctl_list,
list) {
if ( ! V_43 -> V_57 )
continue;
if ( V_43 -> V_58 ) {
V_49 = F_18 ( V_43 -> V_10 ,
V_43 -> V_56 ,
V_43 -> V_3 ) ;
if ( V_49 < 0 )
return V_49 ;
}
}
return 0 ;
}
static void F_48 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = F_49 ( V_110 ,
struct V_111 ,
V_110 ) ;
F_30 ( V_112 -> V_46 , V_112 -> V_43 ) ;
F_4 ( V_112 ) ;
}
static int F_50 ( struct V_13 * V_14 ,
const struct V_47 * V_32 )
{
struct V_18 * V_28 = F_12 ( V_14 ) ;
struct V_42 * V_43 ;
struct V_111 * V_112 ;
char * V_63 ;
char * V_83 ;
int V_49 ;
V_63 = F_23 ( V_88 , V_7 ) ;
if ( ! V_63 )
return - V_51 ;
switch ( V_32 -> type ) {
case V_34 :
V_83 = L_22 ;
break;
case V_36 :
V_83 = L_23 ;
break;
case V_37 :
V_83 = L_24 ;
break;
case V_38 :
V_83 = L_25 ;
break;
case V_39 :
V_83 = L_26 ;
break;
default:
V_49 = - V_24 ;
goto V_113;
}
snprintf ( V_63 , V_88 , L_34 ,
V_28 -> V_90 , V_83 , V_32 -> V_114 ) ;
F_46 (ctl, &dsp->wm_coeff->ctl_list,
list) {
if ( ! strcmp ( V_43 -> V_63 , V_63 ) ) {
if ( ! V_43 -> V_57 )
V_43 -> V_57 = 1 ;
goto V_115;
}
}
V_43 = F_2 ( sizeof( * V_43 ) , V_7 ) ;
if ( ! V_43 ) {
V_49 = - V_51 ;
goto V_113;
}
V_43 -> V_32 = * V_32 ;
V_43 -> V_63 = F_3 ( V_63 , strlen ( V_63 ) + 1 , V_7 ) ;
if ( ! V_43 -> V_63 ) {
V_49 = - V_51 ;
goto V_116;
}
V_43 -> V_57 = 1 ;
V_43 -> V_58 = 0 ;
V_43 -> V_117 . V_118 = F_25 ;
V_43 -> V_117 . V_119 = F_21 ;
V_43 -> V_61 = V_14 -> V_61 -> V_120 ;
V_43 -> V_19 = V_28 ;
V_43 -> V_3 = V_32 -> V_3 ;
V_43 -> V_56 = F_2 ( V_43 -> V_3 , V_7 ) ;
if ( ! V_43 -> V_56 ) {
V_49 = - V_51 ;
goto V_121;
}
V_112 = F_2 ( sizeof( * V_112 ) , V_7 ) ;
if ( ! V_112 ) {
V_49 = - V_51 ;
goto V_122;
}
V_112 -> V_46 = V_28 -> V_46 ;
V_112 -> V_43 = V_43 ;
F_51 ( & V_112 -> V_110 , F_48 ) ;
F_52 ( & V_112 -> V_110 ) ;
V_115:
F_4 ( V_63 ) ;
return 0 ;
V_122:
F_4 ( V_43 -> V_56 ) ;
V_121:
F_4 ( V_43 -> V_63 ) ;
V_116:
F_4 ( V_43 ) ;
V_113:
F_4 ( V_63 ) ;
return V_49 ;
}
static int F_53 ( struct V_18 * V_28 , struct V_13 * V_14 )
{
struct V_52 * V_52 = V_28 -> V_52 ;
struct V_123 V_124 ;
struct V_125 V_126 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
void * V_114 , * V_6 ;
struct V_47 * V_32 ;
const struct V_27 * V_31 ;
unsigned int V_73 , V_131 ;
T_1 V_132 , V_133 ;
T_2 V_134 ;
int V_29 , V_49 ;
switch ( V_28 -> type ) {
case V_98 :
V_31 = F_14 ( V_28 , V_36 ) ;
break;
case V_102 :
V_31 = F_14 ( V_28 , V_37 ) ;
break;
default:
V_31 = NULL ;
break;
}
if ( V_31 == NULL ) {
F_37 ( V_31 != NULL ) ;
return - V_24 ;
}
switch ( V_28 -> type ) {
case V_98 :
V_49 = F_24 ( V_52 , V_31 -> V_35 , & V_124 ,
sizeof( V_124 ) ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_35 ,
V_49 ) ;
return V_49 ;
}
V_6 = & V_124 ;
V_133 = sizeof( V_124 ) ;
V_132 = F_39 ( V_124 . V_132 ) ;
V_28 -> V_135 = F_39 ( V_124 . V_22 . V_136 ) ;
F_41 ( V_28 , L_36 ,
V_28 -> V_135 ,
( F_39 ( V_124 . V_22 . V_96 ) & 0xff0000 ) >> 16 ,
( F_39 ( V_124 . V_22 . V_96 ) & 0xff00 ) >> 8 ,
F_39 ( V_124 . V_22 . V_96 ) & 0xff ,
V_132 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_39 ;
V_32 -> V_114 = F_39 ( V_124 . V_22 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_124 . V_101 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_36 ;
V_32 -> V_114 = F_39 ( V_124 . V_22 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_124 . V_99 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
V_73 = sizeof( V_124 ) / 2 ;
V_131 = V_73 + ( ( sizeof( * V_128 ) * V_132 ) / 2 ) ;
break;
case V_102 :
V_49 = F_24 ( V_52 , V_31 -> V_35 , & V_126 ,
sizeof( V_126 ) ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_35 ,
V_49 ) ;
return V_49 ;
}
V_6 = & V_126 ;
V_133 = sizeof( V_126 ) ;
V_132 = F_39 ( V_126 . V_132 ) ;
V_28 -> V_135 = F_39 ( V_126 . V_22 . V_136 ) ;
F_41 ( V_28 , L_36 ,
V_28 -> V_135 ,
( F_39 ( V_126 . V_22 . V_96 ) & 0xff0000 ) >> 16 ,
( F_39 ( V_126 . V_22 . V_96 ) & 0xff00 ) >> 8 ,
F_39 ( V_126 . V_22 . V_96 ) & 0xff ,
V_132 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_37 ;
V_32 -> V_114 = F_39 ( V_126 . V_22 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_126 . V_103 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_38 ;
V_32 -> V_114 = F_39 ( V_126 . V_22 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_126 . V_104 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_138 ;
V_32 -> V_114 = F_39 ( V_126 . V_22 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_126 . V_101 ) ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
V_73 = sizeof( V_126 ) / 2 ;
V_131 = V_73 + ( ( sizeof( * V_130 ) * V_132 ) / 2 ) ;
break;
default:
F_37 ( NULL == L_15 ) ;
return - V_24 ;
}
if ( V_132 == 0 ) {
F_19 ( V_28 , L_37 ) ;
return - V_24 ;
}
if ( V_132 > 1024 ) {
F_19 ( V_28 , L_38 , V_132 ) ;
F_54 ( F_55 ( V_28 -> V_62 ) , V_139 ,
V_6 , V_133 ) ;
return - V_24 ;
}
V_49 = F_24 ( V_52 , V_31 -> V_35 + V_131 , & V_134 , sizeof( V_134 ) ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_39 ,
V_49 ) ;
return V_49 ;
}
if ( F_39 ( V_134 ) != 0xbedead )
F_40 ( V_28 , L_40 ,
V_131 , F_39 ( V_134 ) ) ;
V_114 = F_2 ( ( V_131 - V_73 ) * 2 , V_7 | V_8 ) ;
if ( ! V_114 )
return - V_51 ;
V_49 = F_24 ( V_52 , V_31 -> V_35 + V_73 , V_114 , ( V_131 - V_73 ) * 2 ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_41 ,
V_49 ) ;
goto V_92;
}
V_128 = V_114 ;
V_130 = V_114 ;
for ( V_29 = 0 ; V_29 < V_132 ; V_29 ++ ) {
switch ( V_28 -> type ) {
case V_98 :
F_41 ( V_28 , L_42 ,
V_29 , F_39 ( V_128 [ V_29 ] . V_114 . V_136 ) ,
( F_39 ( V_128 [ V_29 ] . V_114 . V_96 ) & 0xff0000 ) >> 16 ,
( F_39 ( V_128 [ V_29 ] . V_114 . V_96 ) & 0xff00 ) >> 8 ,
F_39 ( V_128 [ V_29 ] . V_114 . V_96 ) & 0xff ,
F_39 ( V_128 [ V_29 ] . V_99 ) ,
F_39 ( V_128 [ V_29 ] . V_101 ) ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_36 ;
V_32 -> V_114 = F_39 ( V_128 [ V_29 ] . V_114 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_128 [ V_29 ] . V_99 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
if ( V_29 + 1 < V_132 ) {
V_32 -> V_3 = F_39 ( V_128 [ V_29 + 1 ] . V_99 ) ;
V_32 -> V_3 -= F_39 ( V_128 [ V_29 ] . V_99 ) ;
F_50 ( V_14 , V_32 ) ;
} else {
F_40 ( V_28 , L_43 ,
F_39 ( V_128 [ V_29 ] . V_114 . V_136 ) ) ;
}
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_39 ;
V_32 -> V_114 = F_39 ( V_128 [ V_29 ] . V_114 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_128 [ V_29 ] . V_101 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
if ( V_29 + 1 < V_132 ) {
V_32 -> V_3 = F_39 ( V_128 [ V_29 + 1 ] . V_101 ) ;
V_32 -> V_3 -= F_39 ( V_128 [ V_29 ] . V_101 ) ;
F_50 ( V_14 , V_32 ) ;
} else {
F_40 ( V_28 , L_44 ,
F_39 ( V_128 [ V_29 ] . V_114 . V_136 ) ) ;
}
break;
case V_102 :
F_41 ( V_28 ,
L_45 ,
V_29 , F_39 ( V_130 [ V_29 ] . V_114 . V_136 ) ,
( F_39 ( V_130 [ V_29 ] . V_114 . V_96 ) & 0xff0000 ) >> 16 ,
( F_39 ( V_130 [ V_29 ] . V_114 . V_96 ) & 0xff00 ) >> 8 ,
F_39 ( V_130 [ V_29 ] . V_114 . V_96 ) & 0xff ,
F_39 ( V_130 [ V_29 ] . V_103 ) ,
F_39 ( V_130 [ V_29 ] . V_104 ) ,
F_39 ( V_130 [ V_29 ] . V_101 ) ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_37 ;
V_32 -> V_114 = F_39 ( V_130 [ V_29 ] . V_114 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_130 [ V_29 ] . V_103 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
if ( V_29 + 1 < V_132 ) {
V_32 -> V_3 = F_39 ( V_130 [ V_29 + 1 ] . V_103 ) ;
V_32 -> V_3 -= F_39 ( V_130 [ V_29 ] . V_103 ) ;
F_50 ( V_14 , V_32 ) ;
} else {
F_40 ( V_28 , L_46 ,
F_39 ( V_130 [ V_29 ] . V_114 . V_136 ) ) ;
}
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_38 ;
V_32 -> V_114 = F_39 ( V_130 [ V_29 ] . V_114 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_130 [ V_29 ] . V_104 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
if ( V_29 + 1 < V_132 ) {
V_32 -> V_3 = F_39 ( V_130 [ V_29 + 1 ] . V_104 ) ;
V_32 -> V_3 -= F_39 ( V_130 [ V_29 ] . V_104 ) ;
F_50 ( V_14 , V_32 ) ;
} else {
F_40 ( V_28 , L_47 ,
F_39 ( V_130 [ V_29 ] . V_114 . V_136 ) ) ;
}
V_32 = F_2 ( sizeof( * V_32 ) , V_7 ) ;
if ( ! V_32 )
return - V_51 ;
V_32 -> type = V_138 ;
V_32 -> V_114 = F_39 ( V_130 [ V_29 ] . V_114 . V_136 ) ;
V_32 -> V_35 = F_39 ( V_130 [ V_29 ] . V_101 ) ;
V_32 -> V_3 = 0 ;
F_5 ( & V_32 -> V_5 , & V_28 -> V_137 ) ;
if ( V_29 + 1 < V_132 ) {
V_32 -> V_3 = F_39 ( V_130 [ V_29 + 1 ] . V_101 ) ;
V_32 -> V_3 -= F_39 ( V_130 [ V_29 ] . V_101 ) ;
F_50 ( V_14 , V_32 ) ;
} else {
F_40 ( V_28 , L_44 ,
F_39 ( V_130 [ V_29 ] . V_114 . V_136 ) ) ;
}
break;
}
}
V_92:
F_4 ( V_114 ) ;
return V_49 ;
}
static int F_56 ( struct V_18 * V_28 )
{
F_33 ( V_71 ) ;
struct V_52 * V_52 = V_28 -> V_52 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
const struct V_72 * V_72 ;
const struct V_27 * V_31 ;
struct V_47 * V_144 ;
const char * V_83 ;
int V_49 , V_73 , V_145 , type , V_33 , V_50 ;
char * V_84 ;
struct V_1 * V_6 ;
int V_146 ;
V_84 = F_2 ( V_88 , V_7 ) ;
if ( V_84 == NULL )
return - V_51 ;
snprintf ( V_84 , V_88 , L_48 , V_28 -> V_89 , V_28 -> V_90 ,
V_91 [ V_28 -> V_22 ] . V_84 ) ;
V_84 [ V_88 - 1 ] = '\0' ;
V_49 = F_34 ( & V_72 , V_84 , V_28 -> V_62 ) ;
if ( V_49 != 0 ) {
F_40 ( V_28 , L_7 , V_84 ) ;
V_49 = 0 ;
goto V_92;
}
V_49 = - V_24 ;
if ( sizeof( * V_141 ) >= V_72 -> V_93 ) {
F_19 ( V_28 , L_8 ,
V_84 , V_72 -> V_93 ) ;
goto V_94;
}
V_141 = ( void * ) & V_72 -> V_55 [ 0 ] ;
if ( memcmp ( V_141 -> V_95 , L_49 , 4 ) != 0 ) {
F_19 ( V_28 , L_10 , V_84 ) ;
goto V_94;
}
switch ( F_39 ( V_141 -> V_147 ) & 0xff ) {
case 1 :
break;
default:
F_19 ( V_28 , L_50 ,
V_84 , F_39 ( V_141 -> V_147 ) & 0xff ) ;
V_49 = - V_24 ;
goto V_94;
}
F_35 ( V_28 , L_51 , V_84 ,
( F_36 ( V_141 -> V_96 ) >> 16 ) & 0xff ,
( F_36 ( V_141 -> V_96 ) >> 8 ) & 0xff ,
F_36 ( V_141 -> V_96 ) & 0xff ) ;
V_73 = F_36 ( V_141 -> V_3 ) ;
V_145 = 0 ;
while ( V_73 < V_72 -> V_93 &&
V_73 - V_72 -> V_93 > sizeof( * V_143 ) ) {
V_143 = ( void * ) ( & V_72 -> V_55 [ V_73 ] ) ;
type = F_57 ( V_143 -> type ) ;
V_33 = F_57 ( V_143 -> V_33 ) ;
F_35 ( V_28 , L_52 ,
V_84 , V_145 , F_36 ( V_143 -> V_136 ) ,
( F_36 ( V_143 -> V_96 ) >> 16 ) & 0xff ,
( F_36 ( V_143 -> V_96 ) >> 8 ) & 0xff ,
F_36 ( V_143 -> V_96 ) & 0xff ) ;
F_35 ( V_28 , L_53 ,
V_84 , V_145 , F_36 ( V_143 -> V_3 ) , V_33 , type ) ;
V_50 = 0 ;
V_83 = L_18 ;
switch ( type ) {
case ( V_106 << 8 ) :
case ( V_107 << 8 ) :
break;
case ( V_108 << 8 ) :
if ( F_36 ( V_143 -> V_136 ) == V_28 -> V_135 &&
V_33 == 0 ) {
V_83 = L_54 ;
V_31 = F_14 ( V_28 , type ) ;
if ( ! V_31 ) {
F_19 ( V_28 , L_55 ) ;
break;
}
V_50 = F_15 ( V_31 , 0 ) ;
} else {
V_83 = L_56 ;
V_50 = V_33 ;
}
break;
case V_36 :
case V_39 :
case V_37 :
case V_38 :
F_35 ( V_28 , L_57 ,
V_84 , V_145 , F_36 ( V_143 -> V_3 ) ,
type , F_36 ( V_143 -> V_136 ) ) ;
V_31 = F_14 ( V_28 , type ) ;
if ( ! V_31 ) {
F_19 ( V_28 , L_2 , type ) ;
break;
}
V_50 = 0 ;
F_46 (alg_region,
&dsp->alg_regions, list) {
if ( F_36 ( V_143 -> V_136 ) == V_144 -> V_114 &&
type == V_144 -> type ) {
V_50 = V_144 -> V_35 ;
V_50 = F_15 ( V_31 ,
V_50 ) ;
V_50 += V_33 ;
}
}
if ( V_50 == 0 )
F_19 ( V_28 , L_58 ,
type , F_36 ( V_143 -> V_136 ) ) ;
break;
default:
F_19 ( V_28 , L_59 ,
V_84 , V_145 , type , V_73 ) ;
break;
}
if ( V_50 ) {
V_6 = F_1 ( V_143 -> V_55 ,
F_36 ( V_143 -> V_3 ) ,
& V_71 ) ;
if ( ! V_6 ) {
F_19 ( V_28 , L_30 ) ;
V_49 = - V_51 ;
goto V_94;
}
F_35 ( V_28 , L_60 ,
V_84 , V_145 , F_36 ( V_143 -> V_3 ) ,
V_50 ) ;
V_49 = F_42 ( V_52 , V_50 , V_6 -> V_6 ,
F_36 ( V_143 -> V_3 ) ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 ,
L_61 ,
V_84 , V_145 , V_50 , V_83 ) ;
}
}
V_146 = F_36 ( V_143 -> V_3 ) % 4 ;
if ( V_146 )
V_73 += F_36 ( V_143 -> V_3 ) + ( 4 - V_146 ) + sizeof( * V_143 ) ;
else
V_73 += F_36 ( V_143 -> V_3 ) + sizeof( * V_143 ) ;
V_145 ++ ;
}
V_49 = F_43 ( V_52 ) ;
if ( V_49 != 0 )
F_19 ( V_28 , L_32 , V_49 ) ;
if ( V_73 > V_72 -> V_93 )
F_40 ( V_28 , L_33 ,
V_84 , V_145 , V_73 - V_72 -> V_93 ) ;
V_94:
F_44 ( V_72 ) ;
F_6 ( & V_71 ) ;
V_92:
F_4 ( V_84 ) ;
return V_49 ;
}
int F_58 ( struct V_18 * V_19 )
{
F_59 ( & V_19 -> V_137 ) ;
return 0 ;
}
int F_60 ( struct V_148 * V_149 ,
struct V_9 * V_10 ,
int V_150 )
{
struct V_13 * V_14 = V_149 -> V_14 ;
struct V_18 * V_151 = F_12 ( V_14 ) ;
struct V_18 * V_28 = & V_151 [ V_149 -> V_152 ] ;
struct V_42 * V_43 ;
int V_49 ;
int V_134 ;
switch ( V_150 ) {
case V_153 :
F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_154 ,
V_155 , V_155 ) ;
if( V_28 -> V_156 ) {
V_49 = F_62 ( V_28 -> V_52 , V_28 -> V_156 , & V_134 ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_62 ,
V_49 ) ;
return V_49 ;
}
V_134 = ( V_134 & V_28 -> V_157 )
>> V_28 -> V_158 ;
V_49 = F_61 ( V_28 -> V_52 ,
V_28 -> V_35 + V_159 ,
V_160 , V_134 ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_63 ,
V_49 ) ;
return V_49 ;
}
}
V_49 = F_32 ( V_28 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_53 ( V_28 , V_14 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_56 ( V_28 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_45 ( V_28 -> V_46 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_47 ( V_28 -> V_46 ) ;
if ( V_49 != 0 )
goto V_161;
F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_154 ,
V_162 | V_163 ,
V_162 | V_163 ) ;
break;
case V_164 :
F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_154 ,
V_162 | V_163 , 0 ) ;
F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_165 ,
V_166 , 0 ) ;
F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_154 ,
V_155 , 0 ) ;
F_46 (ctl, &dsp->wm_coeff->ctl_list,
list) {
V_43 -> V_57 = 0 ;
}
break;
default:
break;
}
return 0 ;
V_161:
F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_154 ,
V_155 , 0 ) ;
return V_49 ;
}
static int F_63 ( struct V_18 * V_28 )
{
unsigned int V_134 ;
int V_49 , V_45 ;
V_49 = F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_167 ,
V_168 , V_168 ) ;
if ( V_49 != 0 )
return V_49 ;
V_45 = 0 ;
do {
V_49 = F_62 ( V_28 -> V_52 , V_28 -> V_35 + V_169 ,
& V_134 ) ;
if ( V_49 != 0 )
return V_49 ;
} while ( ! ( V_134 & V_170 ) && ++ V_45 < 10 );
if ( ! ( V_134 & V_170 ) ) {
F_19 ( V_28 , L_64 ) ;
return - V_26 ;
}
F_35 ( V_28 , L_65 , V_45 ) ;
F_41 ( V_28 , L_65 , V_45 ) ;
return 0 ;
}
int F_64 ( struct V_148 * V_149 ,
struct V_9 * V_10 , int V_150 )
{
struct V_13 * V_14 = V_149 -> V_14 ;
struct V_18 * V_151 = F_12 ( V_14 ) ;
struct V_18 * V_28 = & V_151 [ V_149 -> V_152 ] ;
struct V_47 * V_144 ;
struct V_42 * V_43 ;
unsigned int V_134 ;
int V_49 ;
switch ( V_150 ) {
case V_153 :
V_49 = F_62 ( V_28 -> V_52 , V_171 , & V_134 ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_62 ,
V_49 ) ;
return V_49 ;
}
V_134 = ( V_134 & V_172 )
>> V_173 ;
V_49 = F_61 ( V_28 -> V_52 ,
V_28 -> V_35 + V_174 ,
V_175 , V_134 ) ;
if ( V_49 != 0 ) {
F_19 ( V_28 , L_63 ,
V_49 ) ;
return V_49 ;
}
if ( V_28 -> V_176 ) {
V_49 = F_62 ( V_28 -> V_52 ,
V_28 -> V_35 + V_174 , & V_134 ) ;
if ( V_49 != 0 ) {
F_29 ( V_28 -> V_62 ,
L_66 , V_49 ) ;
return V_49 ;
}
if ( ( V_134 & V_175 ) >= 3 ) {
V_49 = F_65 ( V_28 -> V_176 ) ;
if ( V_49 != 0 ) {
F_29 ( V_28 -> V_62 ,
L_67 ,
V_49 ) ;
return V_49 ;
}
V_49 = F_66 ( V_28 -> V_176 ,
1800000 ,
1800000 ) ;
if ( V_49 != 0 ) {
F_29 ( V_28 -> V_62 ,
L_68 ,
V_49 ) ;
return V_49 ;
}
}
}
V_49 = F_63 ( V_28 ) ;
if ( V_49 != 0 )
return V_49 ;
V_49 = F_32 ( V_28 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_53 ( V_28 , V_14 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_56 ( V_28 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_45 ( V_28 -> V_46 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_47 ( V_28 -> V_46 ) ;
if ( V_49 != 0 )
goto V_161;
V_49 = F_61 ( V_28 -> V_52 ,
V_28 -> V_35 + V_167 ,
V_177 | V_178 ,
V_177 | V_178 ) ;
if ( V_49 != 0 )
goto V_161;
V_28 -> V_25 = true ;
break;
case V_164 :
V_28 -> V_25 = false ;
F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_167 ,
V_168 | V_177 |
V_178 , 0 ) ;
F_67 ( V_28 -> V_52 , V_28 -> V_35 + V_179 , 0 ) ;
F_67 ( V_28 -> V_52 , V_28 -> V_35 + V_180 , 0 ) ;
F_67 ( V_28 -> V_52 , V_28 -> V_35 + V_181 , 0 ) ;
if ( V_28 -> V_176 ) {
V_49 = F_66 ( V_28 -> V_176 , 1200000 ,
1800000 ) ;
if ( V_49 != 0 )
F_68 ( V_28 -> V_62 ,
L_69 ,
V_49 ) ;
V_49 = F_69 ( V_28 -> V_176 ) ;
if ( V_49 != 0 )
F_29 ( V_28 -> V_62 ,
L_67 ,
V_49 ) ;
}
F_46 (ctl, &dsp->wm_coeff->ctl_list,
list) {
V_43 -> V_57 = 0 ;
}
while ( ! F_7 ( & V_28 -> V_137 ) ) {
V_144 = F_8 ( & V_28 -> V_137 ,
struct V_47 ,
V_5 ) ;
F_9 ( & V_144 -> V_5 ) ;
F_4 ( V_144 ) ;
}
break;
default:
break;
}
return 0 ;
V_161:
F_61 ( V_28 -> V_52 , V_28 -> V_35 + V_167 ,
V_168 | V_177 | V_178 , 0 ) ;
return V_49 ;
}
int F_70 ( struct V_18 * V_19 , bool V_176 )
{
int V_49 ;
V_49 = F_61 ( V_19 -> V_52 , V_19 -> V_35 + V_167 ,
V_182 , 0 ) ;
if ( V_49 != 0 ) {
F_19 ( V_19 , L_70 , V_49 ) ;
return V_49 ;
}
F_59 ( & V_19 -> V_137 ) ;
V_19 -> V_46 = F_2 ( sizeof( * V_19 -> V_46 ) ,
V_7 ) ;
if ( ! V_19 -> V_46 )
return - V_51 ;
V_19 -> V_46 -> V_52 = V_19 -> V_52 ;
V_19 -> V_46 -> V_62 = V_19 -> V_62 ;
F_59 ( & V_19 -> V_46 -> V_70 ) ;
if ( V_176 ) {
V_19 -> V_176 = F_71 ( V_19 -> V_62 , L_71 ) ;
if ( F_72 ( V_19 -> V_176 ) ) {
V_49 = F_73 ( V_19 -> V_176 ) ;
F_29 ( V_19 -> V_62 , L_72 , V_49 ) ;
goto V_183;
}
V_49 = F_65 ( V_19 -> V_176 ) ;
if ( V_49 != 0 ) {
F_29 ( V_19 -> V_62 , L_73 ,
V_49 ) ;
goto V_183;
}
V_49 = F_66 ( V_19 -> V_176 , 1200000 , 1800000 ) ;
if ( V_49 != 0 ) {
F_29 ( V_19 -> V_62 , L_74 ,
V_49 ) ;
goto V_183;
}
V_49 = F_69 ( V_19 -> V_176 ) ;
if ( V_49 != 0 ) {
F_29 ( V_19 -> V_62 , L_75 ,
V_49 ) ;
goto V_183;
}
}
return 0 ;
V_183:
F_4 ( V_19 -> V_46 ) ;
return V_49 ;
}
