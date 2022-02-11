static int F_1 ( struct V_1 * V_2 ,
int V_3 , struct V_4 * V_5 ) {
return - 1 ;
}
struct V_6 * F_2 ( void )
{
struct V_7 V_7 ;
struct V_1 * V_8 =
F_3 ( sizeof( struct V_1 ) , V_9 ) ;
if ( ! V_8 )
return NULL ;
F_4 ( F_5 ( struct V_1 , V_10 . V_11 ) == 0 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_12 = 0xff ;
F_6 ( & V_8 -> V_10 , 0 , & V_7 , false ) ;
F_7 ( & V_8 -> V_13 , 1 ) ;
F_7 ( & V_8 -> V_14 , 1 ) ;
V_8 -> V_10 . V_11 . V_15 = V_16 ;
sprintf ( V_8 -> V_10 . V_11 . V_17 , L_1 ) ;
V_8 -> V_10 . V_11 . V_18 = V_19 ;
#ifndef F_8
F_9 ( & V_8 -> V_20 ) ;
V_8 -> V_21 = 1 ;
#endif
F_9 ( & V_8 -> V_22 ) ;
F_10 ( & V_8 -> V_23 ) ;
return & V_8 -> V_10 . V_11 ;
}
void F_11 ( struct V_6 * V_11 )
{
struct V_24 * V_25 , * V_26 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
F_13 ( & V_2 -> V_22 ) ;
F_14 (p, tmp, &ctrl->list, list) {
F_15 ( & V_25 -> V_23 ) ;
F_16 ( V_25 ) ;
}
F_17 ( & V_2 -> V_22 ) ;
F_16 ( V_11 ) ;
}
static bool F_18 ( const struct V_27 * V_28 ,
const struct V_27 * V_29 )
{
bool V_30 =
V_28 -> V_31 == V_29 -> V_31 &&
V_28 -> V_32 == V_29 -> V_32 &&
V_28 -> V_33 == V_29 -> V_33 &&
V_28 -> V_34 == V_29 -> V_34 && V_28 -> V_35 == V_29 -> V_35 ;
if ( ! V_30 )
return false ;
switch ( V_28 -> V_31 ) {
case V_36 :
return true ;
case V_37 :
return V_28 -> V_38 . V_39 . V_40 == V_29 -> V_38 . V_39 . V_40 ;
case V_41 :
return
V_28 -> V_38 . V_42 . V_40 == V_29 -> V_38 . V_42 . V_40 &&
strcmp ( V_28 -> V_38 . V_42 . V_43 , V_29 -> V_38 . V_42 . V_43 ) == 0 ;
case V_44 :
return
V_28 -> V_38 . V_45 . V_46 == V_29 -> V_38 . V_45 . V_46
&& V_28 -> V_38 . V_45 . V_47 ==
V_29 -> V_38 . V_45 . V_47
&& strcmp ( V_28 -> V_38 . V_45 . V_17 , V_29 -> V_38 . V_45 . V_17 ) == 0
&& V_28 -> V_38 . V_45 . V_48 == V_29 -> V_38 . V_45 . V_48
&& memcmp ( V_28 -> V_38 . V_45 . V_49 , V_29 -> V_38 . V_45 . V_49 ,
V_28 -> V_38 . V_45 . V_48 ) == 0 ;
case V_50 :
return V_28 -> V_38 . V_51 . V_40 == V_29 -> V_38 . V_51 . V_40 ;
case V_52 :
return true ;
case V_53 :
return false ;
default:
return false ;
}
return false ;
}
static bool F_19 ( const struct V_24 * V_54 ,
const struct V_24 * V_55 )
{
if ( V_54 -> V_3 != V_55 -> V_3 )
return false ;
if ( V_54 -> V_3 == V_56 )
return F_18 ( & V_54 -> V_57 , & V_55 -> V_57 ) ;
else
return V_54 -> V_58 == V_55 -> V_58 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_24 * V_59 )
{
F_13 ( & V_2 -> V_22 ) ;
F_21 ( & V_2 -> V_13 ) ;
V_59 -> V_60 = F_22 ( & V_2 -> V_13 ) ;
F_23 ( & V_59 -> V_23 , & V_2 -> V_23 ) ;
F_17 ( & V_2 -> V_22 ) ;
}
static struct V_24 * F_24 ( struct V_1 * V_2 ,
struct V_24 * V_59 )
{
struct V_24 * V_25 , * V_26 , * V_61 ;
V_61 = F_25 ( & V_2 -> V_23 , struct V_24 , V_23 ) ;
F_14 (p, tmp, &ctrl->list, list) {
if ( F_19 ( V_59 , V_25 ) ) {
if ( V_25 != V_61 )
F_26 ( L_2 ) ;
F_7 ( & V_2 -> V_14 ,
V_25 -> V_60 ) ;
F_15 ( & V_25 -> V_23 ) ;
goto V_62;
}
}
V_25 = NULL ;
V_62:
return V_25 ;
}
struct V_63 * F_27 ( struct V_6 * V_11 )
{
struct V_1 * V_8 = F_12 ( V_11 ) ;
return & V_8 -> V_64 ;
}
static void F_28 ( struct V_65 * V_66 , struct V_1 * V_1 )
{
V_66 -> V_67 = 0 ;
V_66 -> V_58 = V_1 -> V_10 . V_11 . V_12 ;
V_66 -> V_7 = & V_1 -> V_10 . V_7 ;
}
void F_29 ( struct V_6 * V_11 , T_1 V_68 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
struct V_4 * V_5 = F_30 ( V_69 ) ;
struct V_6 * V_70 = V_1 -> V_10 . V_11 . V_70 ;
if ( ! V_5 )
return;
if ( ! V_70 ) {
F_31 ( L_3 ) ;
return;
}
F_4 ( F_5 ( struct V_1 , V_10 . V_11 ) == 0 ) ;
F_28 ( F_32 ( V_5 ) , V_1 ) ;
F_32 ( V_5 ) -> V_7 -> V_12 = V_68 ;
V_1 -> V_10 . V_7 . V_12 = V_68 ;
F_33 ( V_5 , V_71 ) ;
F_33 ( V_5 , V_68 ) ;
F_34 ( V_5 , V_72 ) ;
V_70 -> V_73 ( V_70 , V_5 ) ;
}
int F_35 ( struct V_6 * V_11 ,
struct V_27 * V_57 ,
struct V_6 * V_74 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
T_2 V_75 ;
T_3 V_76 ;
T_1 V_77 ;
struct V_24 * V_59 ;
int V_78 ;
char V_79 [ 16 ] ;
struct V_4 * V_5 ;
struct V_6 * V_70 = V_1 -> V_10 . V_11 . V_70 ;
if ( ! V_70 ) {
F_31 ( L_4 ) ;
return - V_80 ;
}
if ( F_36 ( V_11 , V_74 ) > 0 ) {
F_37 ( L_5 ) ;
F_38 ( 1 ) ;
return - V_81 ;
}
V_5 = F_30 ( V_69 ) ;
if ( ! V_5 )
return - V_82 ;
F_33 ( V_5 , V_56 ) ;
F_33 ( V_5 , ( V_57 -> V_35 << 4 ) | V_57 -> V_31 ) ;
F_33 ( V_5 , ( V_57 -> V_32 << 3 ) | V_57 -> V_33 ) ;
F_33 ( V_5 , V_57 -> V_34 & 0x03 ) ;
switch ( V_57 -> V_31 ) {
case V_36 :
break;
case V_50 :
F_33 ( V_5 , ( T_1 ) V_57 -> V_38 . V_51 . V_40 ) ;
break;
case V_52 :
break;
case V_37 :
V_75 = F_39 ( V_57 -> V_38 . V_39 . V_40 ) ;
F_40 ( V_5 , & V_75 , 4 ) ;
break;
case V_41 :
V_75 = F_39 ( V_57 -> V_38 . V_42 . V_40 ) ;
F_40 ( V_5 , & V_75 , 4 ) ;
F_40 ( V_5 , V_57 -> V_38 . V_42 . V_43 ,
strlen ( V_57 -> V_38 . V_42 . V_43 ) + 1 ) ;
break;
case V_44 :
V_76 = F_41 ( V_57 -> V_38 . V_45 . V_46 ) ;
F_40 ( V_5 , & V_76 , 2 ) ;
V_76 = F_41 ( V_57 -> V_38 . V_45 . V_47 ) ;
F_40 ( V_5 , & V_76 , 2 ) ;
memset ( V_79 , 0 , sizeof( V_79 ) ) ;
strncpy ( V_79 , V_57 -> V_38 . V_45 . V_17 ,
V_83 - 1 ) ;
F_40 ( V_5 , V_79 , V_83 ) ;
V_77 = V_57 -> V_38 . V_45 . V_48 ;
F_40 ( V_5 , & V_77 , 1 ) ;
F_40 ( V_5 , V_57 -> V_38 . V_45 . V_49 ,
V_57 -> V_38 . V_45 . V_48 ) ;
break;
default:
F_26 ( L_6 ,
V_57 -> V_31 ) ;
return - V_84 ;
}
V_59 = F_3 ( sizeof( * V_59 ) , V_85 ) ;
if ( ! V_59 )
return - V_82 ;
V_59 -> V_86 = V_74 ;
V_59 -> V_3 = V_56 ;
V_59 -> V_57 = * V_57 ;
F_20 ( V_1 , V_59 ) ;
F_28 ( F_32 ( V_5 ) , V_1 ) ;
F_32 ( V_5 ) -> V_7 -> V_12 = V_57 -> V_33 ;
F_34 ( V_5 , V_72 ) ;
V_78 =
V_70 -> V_73 ( V_70 , V_5 ) ;
if ( V_78 < 0 ) {
int V_87 ;
V_87 = F_36 ( & V_1 -> V_10 . V_11 ,
V_74 ) ;
if ( V_87 != 1 )
F_37 ( L_7 , V_87 ) ;
return - V_80 ;
}
return 0 ;
}
int F_42 ( struct V_6 * V_11 , T_1 V_88 ,
struct V_6 * V_89 )
{
int V_78 ;
struct V_1 * V_1 = F_12 ( V_11 ) ;
struct V_4 * V_5 = F_30 ( V_69 ) ;
struct V_6 * V_70 = V_1 -> V_10 . V_11 . V_70 ;
if ( ! V_5 )
return - V_82 ;
if ( ! V_70 ) {
F_31 ( L_8 ) ;
return - V_80 ;
}
F_33 ( V_5 , V_90 ) ;
F_33 ( V_5 , V_88 ) ;
F_28 ( F_32 ( V_5 ) , V_1 ) ;
F_34 ( V_5 , V_72 ) ;
V_78 =
V_70 -> V_73 ( V_70 , V_5 ) ;
#ifndef F_8
V_1 -> V_91 [ V_88 ] = 0 ;
#endif
return V_78 ;
}
int F_36 ( struct V_6 * V_92 , struct V_6 * V_93 )
{
struct V_24 * V_25 , * V_26 ;
struct V_1 * V_2 = F_12 ( V_92 ) ;
int V_94 = 0 ;
F_13 ( & V_2 -> V_22 ) ;
F_14 (p, tmp, &ctrl->list, list) {
if ( V_25 -> V_86 == V_93 ) {
F_15 ( & V_25 -> V_23 ) ;
F_16 ( V_25 ) ;
V_94 ++ ;
}
}
F_17 ( & V_2 -> V_22 ) ;
return V_94 ;
}
static int V_16 ( struct V_6 * V_11 , struct V_4 * V_5 )
{
T_1 V_95 ;
T_1 V_3 ;
int V_78 = - 1 ;
T_3 V_76 ;
T_1 V_96 ;
T_1 V_57 [ 255 ] ;
T_1 V_97 ;
struct V_1 * V_1 = F_12 ( V_11 ) ;
struct V_24 V_98 , * V_59 ;
F_43 ( V_5 , & V_95 , 1 ) ;
V_3 = V_95 & V_99 ;
if ( V_3 != V_100
&& V_101 != ( V_101 & V_95 )
&& V_102 != ( V_102 & V_95 ) ) {
if ( F_1 ( V_1 , V_3 , V_5 ) != 0 )
V_95 |= V_102 ;
}
switch ( V_3 ) {
case V_56 :
{
enum V_103 V_10 ;
enum V_103 V_104 ;
T_1 V_34 ;
T_1 V_68 ;
T_1 V_105 ;
T_1 V_26 ;
T_2 V_75 ;
T_1 * V_106 ;
int V_107 ;
struct V_27 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_43 ( V_5 , & V_26 , 1 ) ;
V_10 = V_26 & V_109 ;
V_108 . V_31 = V_10 ;
V_104 = V_26 >> 4 ;
V_108 . V_35 = V_104 ;
F_43 ( V_5 , & V_26 , 1 ) ;
V_68 = V_26 & 0x07 ;
V_105 = V_26 >> 3 ;
V_108 . V_32 = V_105 ;
V_108 . V_33 = V_68 ;
F_43 ( V_5 , & V_34 , 1 ) ;
V_108 . V_34 = V_34 & 0x03 ;
switch ( V_10 ) {
case V_36 :
case V_52 :
if ( V_102 & V_95 )
break;
F_43 ( V_5 , & V_97 , 1 ) ;
break;
case V_50 :
F_43 ( V_5 , & V_26 , 1 ) ;
V_108 . V_38 . V_51 . V_40 = V_26 ;
if ( V_102 & V_95 )
break;
F_43 ( V_5 , & V_97 , 1 ) ;
break;
case V_37 :
F_43 ( V_5 , & V_75 , 4 ) ;
V_108 . V_38 . V_39 . V_40 =
F_44 ( V_75 ) ;
if ( V_102 & V_95 )
break;
F_43 ( V_5 , & V_97 , 1 ) ;
break;
case V_41 :
F_43 ( V_5 , & V_75 , 4 ) ;
V_108 . V_38 . V_42 . V_40 =
F_44 ( V_75 ) ;
V_106 = ( T_1 * ) V_108 . V_38 . V_42 . V_43 ;
for ( F_43 ( V_5 , & V_26 , 1 ) ;
F_45 ( V_5 ) && V_26 != '\0' ;
F_43 ( V_5 , & V_26 , 1 ) )
* V_106 ++ = V_26 ;
* V_106 = '\0' ;
if ( V_102 & V_95 )
break;
F_43 ( V_5 , & V_97 , 1 ) ;
break;
case V_44 :
F_43 ( V_5 , & V_76 , 2 ) ;
V_108 . V_38 . V_45 . V_46 =
F_46 ( V_76 ) ;
F_43 ( V_5 , & V_76 , 2 ) ;
V_108 . V_38 . V_45 . V_47 =
F_46 ( V_76 ) ;
V_106 = ( T_1 * ) V_108 . V_38 . V_45 . V_17 ;
F_4 ( sizeof( V_108 . V_38 . V_45 . V_17 )
>= V_83 ) ;
for ( V_107 = 0 ;
V_107 < V_83
&& F_45 ( V_5 ) ; V_107 ++ ) {
F_43 ( V_5 , & V_26 , 1 ) ;
* V_106 ++ = V_26 ;
}
F_43 ( V_5 , & V_96 , 1 ) ;
V_108 . V_38 . V_45 . V_48 = V_96 ;
V_106 = V_108 . V_38 . V_45 . V_49 ;
while ( F_45 ( V_5 ) && V_96 -- ) {
F_43 ( V_5 , & V_26 , 1 ) ;
* V_106 ++ = V_26 ;
}
if ( V_102 & V_95 )
break;
F_43 ( V_5 , & V_97 , 1 ) ;
F_43 ( V_5 , & V_96 , 1 ) ;
F_43 ( V_5 , & V_57 , V_96 ) ;
break;
default:
F_26 ( L_9 ,
V_10 ) ;
goto error;
}
V_98 . V_3 = V_3 ;
V_98 . V_57 = V_108 ;
F_13 ( & V_1 -> V_22 ) ;
V_59 = F_24 ( V_1 , & V_98 ) ;
if ( V_102 == ( V_102 & V_95 ) ||
F_47 ( V_5 ) ) {
F_37 ( L_10
L_11 ) ;
V_1 -> V_64 . V_110 ( V_1 -> V_10 . V_11 . V_111 ,
0 ,
V_59 ? V_59 -> V_86
: NULL ) ;
} else {
V_1 -> V_64 . V_112 ( V_1 -> V_10 .
V_11 . V_111 , V_97 ,
V_10 , V_68 ,
V_59 ? V_59 ->
V_86 : NULL ) ;
}
if ( V_59 != NULL )
F_16 ( V_59 ) ;
F_17 ( & V_1 -> V_22 ) ;
}
break;
case V_90 :
F_43 ( V_5 , & V_97 , 1 ) ;
V_1 -> V_64 . V_113 ( V_1 -> V_10 . V_11 . V_111 , V_97 ) ;
break;
case V_100 :
F_37 ( L_12 ) ;
V_1 -> V_64 . V_114 () ;
break;
case V_71 :
V_1 -> V_64 . V_115 () ;
break;
case V_116 :
V_1 -> V_64 . V_117 () ;
break;
case V_118 :
V_1 -> V_64 . V_119 () ;
break;
case V_120 :
V_1 -> V_64 . V_121 () ;
break;
case V_122 :
V_1 -> V_64 . V_123 () ;
break;
default:
F_37 ( L_13 ) ;
goto error;
break;
}
V_78 = 0 ;
error:
F_48 ( V_5 ) ;
return V_78 ;
}
static void V_19 ( struct V_6 * V_92 , enum V_124 V_2 ,
int V_33 )
{
struct V_1 * V_8 = F_12 ( V_92 ) ;
switch ( V_2 ) {
case V_125 :
case V_126 :
F_13 ( & V_8 -> V_22 ) ;
if ( ! F_49 ( & V_8 -> V_23 ) )
F_31 ( L_14 ) ;
F_17 ( & V_8 -> V_22 ) ;
break;
case V_127 : {
struct V_24 * V_25 , * V_26 ;
F_13 ( & V_8 -> V_22 ) ;
F_14 (p, tmp, &this->list, list) {
if ( V_25 -> V_57 . V_33 == V_33 ) {
F_15 ( & V_25 -> V_23 ) ;
V_25 -> V_86 -> V_18 ( V_25 -> V_86 ,
V_128 ,
V_33 ) ;
F_16 ( V_25 ) ;
}
}
F_17 ( & V_8 -> V_22 ) ;
break;
}
default:
break;
}
}
static int F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 )
{
static int V_129 ;
static int V_130 ;
T_1 V_97 , V_31 , V_26 ;
switch ( V_3 ) {
case V_56 :
F_13 ( & V_2 -> V_20 ) ;
if ( ! V_130 ) {
for ( V_97 = V_129 + 1 ; V_97 < 254 ; V_97 ++ )
if ( ! V_2 -> V_91 [ V_97 ] )
goto V_94;
}
V_130 = 1 ;
for ( V_97 = V_129 - 1 ; V_97 > 1 ; V_97 -- )
if ( ! V_2 -> V_91 [ V_97 ] )
goto V_94;
F_17 ( & V_2 -> V_20 ) ;
return - 1 ;
V_94:
if ( V_97 < 10 )
V_130 = 0 ;
if ( ! V_2 -> V_91 [ V_97 ] )
V_2 -> V_91 [ V_97 ] = 1 ;
V_129 = V_97 ;
F_50 ( V_5 , & V_97 , 1 ) ;
F_17 ( & V_2 -> V_20 ) ;
F_51 ( V_5 , & V_31 , 1 ) ;
if ( V_31 == V_44 ) {
V_26 = 0x01 ;
F_50 ( V_5 , & V_26 , 1 ) ;
F_50 ( V_5 , & V_26 , 1 ) ;
}
break;
case V_90 :
F_13 ( & V_2 -> V_20 ) ;
F_51 ( V_5 , & V_97 , 1 ) ;
V_2 -> V_91 [ V_97 ] = 0 ;
F_17 ( & V_2 -> V_20 ) ;
break;
default:
break;
}
return 0 ;
}
