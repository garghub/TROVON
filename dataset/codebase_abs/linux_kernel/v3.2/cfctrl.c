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
V_70 -> V_72 ( V_70 , V_5 ) ;
}
int F_34 ( struct V_6 * V_11 ,
struct V_27 * V_57 ,
struct V_6 * V_73 )
{
struct V_1 * V_1 = F_12 ( V_11 ) ;
T_2 V_74 ;
T_3 V_75 ;
T_1 V_76 ;
struct V_24 * V_59 ;
int V_77 ;
char V_78 [ 16 ] ;
struct V_4 * V_5 ;
struct V_6 * V_70 = V_1 -> V_10 . V_11 . V_70 ;
if ( ! V_70 ) {
F_31 ( L_4 ) ;
return - V_79 ;
}
if ( F_35 ( V_11 , V_73 ) > 0 ) {
F_36 ( L_5 ) ;
F_37 ( 1 ) ;
return - V_80 ;
}
V_5 = F_30 ( V_69 ) ;
if ( ! V_5 )
return - V_81 ;
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
V_74 = F_38 ( V_57 -> V_38 . V_39 . V_40 ) ;
F_39 ( V_5 , & V_74 , 4 ) ;
break;
case V_41 :
V_74 = F_38 ( V_57 -> V_38 . V_42 . V_40 ) ;
F_39 ( V_5 , & V_74 , 4 ) ;
F_39 ( V_5 , V_57 -> V_38 . V_42 . V_43 ,
strlen ( V_57 -> V_38 . V_42 . V_43 ) + 1 ) ;
break;
case V_44 :
V_75 = F_40 ( V_57 -> V_38 . V_45 . V_46 ) ;
F_39 ( V_5 , & V_75 , 2 ) ;
V_75 = F_40 ( V_57 -> V_38 . V_45 . V_47 ) ;
F_39 ( V_5 , & V_75 , 2 ) ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
strncpy ( V_78 , V_57 -> V_38 . V_45 . V_17 ,
V_82 - 1 ) ;
F_39 ( V_5 , V_78 , V_82 ) ;
V_76 = V_57 -> V_38 . V_45 . V_48 ;
F_39 ( V_5 , & V_76 , 1 ) ;
F_39 ( V_5 , V_57 -> V_38 . V_45 . V_49 ,
V_57 -> V_38 . V_45 . V_48 ) ;
break;
default:
F_26 ( L_6 ,
V_57 -> V_31 ) ;
return - V_83 ;
}
V_59 = F_3 ( sizeof( * V_59 ) , V_84 ) ;
if ( ! V_59 )
return - V_81 ;
V_59 -> V_85 = V_73 ;
V_59 -> V_3 = V_56 ;
V_59 -> V_57 = * V_57 ;
F_20 ( V_1 , V_59 ) ;
F_28 ( F_32 ( V_5 ) , V_1 ) ;
F_32 ( V_5 ) -> V_7 -> V_12 = V_57 -> V_33 ;
V_77 =
V_70 -> V_72 ( V_70 , V_5 ) ;
if ( V_77 < 0 ) {
int V_86 ;
V_86 = F_35 ( & V_1 -> V_10 . V_11 ,
V_73 ) ;
if ( V_86 != 1 )
F_36 ( L_7 , V_86 ) ;
return - V_79 ;
}
return 0 ;
}
int F_41 ( struct V_6 * V_11 , T_1 V_87 ,
struct V_6 * V_88 )
{
int V_77 ;
struct V_1 * V_1 = F_12 ( V_11 ) ;
struct V_4 * V_5 = F_30 ( V_69 ) ;
struct V_6 * V_70 = V_1 -> V_10 . V_11 . V_70 ;
if ( ! V_5 )
return - V_81 ;
if ( ! V_70 ) {
F_31 ( L_8 ) ;
return - V_79 ;
}
F_33 ( V_5 , V_89 ) ;
F_33 ( V_5 , V_87 ) ;
F_28 ( F_32 ( V_5 ) , V_1 ) ;
V_77 =
V_70 -> V_72 ( V_70 , V_5 ) ;
#ifndef F_8
V_1 -> V_90 [ V_87 ] = 0 ;
#endif
return V_77 ;
}
int F_35 ( struct V_6 * V_91 , struct V_6 * V_92 )
{
struct V_24 * V_25 , * V_26 ;
struct V_1 * V_2 = F_12 ( V_91 ) ;
int V_93 = 0 ;
F_13 ( & V_2 -> V_22 ) ;
F_14 (p, tmp, &ctrl->list, list) {
if ( V_25 -> V_85 == V_92 ) {
F_15 ( & V_25 -> V_23 ) ;
F_16 ( V_25 ) ;
V_93 ++ ;
}
}
F_17 ( & V_2 -> V_22 ) ;
return V_93 ;
}
static int V_16 ( struct V_6 * V_11 , struct V_4 * V_5 )
{
T_1 V_94 ;
T_1 V_3 ;
int V_77 = - 1 ;
T_3 V_75 ;
T_1 V_95 ;
T_1 V_57 [ 255 ] ;
T_1 V_96 ;
struct V_1 * V_1 = F_12 ( V_11 ) ;
struct V_24 V_97 , * V_59 ;
F_42 ( V_5 , & V_94 , 1 ) ;
V_3 = V_94 & V_98 ;
if ( V_3 != V_99
&& V_100 != ( V_100 & V_94 )
&& V_101 != ( V_101 & V_94 ) ) {
if ( F_1 ( V_1 , V_3 , V_5 ) != 0 )
V_94 |= V_101 ;
}
switch ( V_3 ) {
case V_56 :
{
enum V_102 V_10 ;
enum V_102 V_103 ;
T_1 V_34 ;
T_1 V_68 ;
T_1 V_104 ;
T_1 V_26 ;
T_2 V_74 ;
T_1 * V_105 ;
int V_106 ;
struct V_27 V_107 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
F_42 ( V_5 , & V_26 , 1 ) ;
V_10 = V_26 & V_108 ;
V_107 . V_31 = V_10 ;
V_103 = V_26 >> 4 ;
V_107 . V_35 = V_103 ;
F_42 ( V_5 , & V_26 , 1 ) ;
V_68 = V_26 & 0x07 ;
V_104 = V_26 >> 3 ;
V_107 . V_32 = V_104 ;
V_107 . V_33 = V_68 ;
F_42 ( V_5 , & V_34 , 1 ) ;
V_107 . V_34 = V_34 & 0x03 ;
switch ( V_10 ) {
case V_36 :
case V_52 :
if ( V_101 & V_94 )
break;
F_42 ( V_5 , & V_96 , 1 ) ;
break;
case V_50 :
F_42 ( V_5 , & V_26 , 1 ) ;
V_107 . V_38 . V_51 . V_40 = V_26 ;
if ( V_101 & V_94 )
break;
F_42 ( V_5 , & V_96 , 1 ) ;
break;
case V_37 :
F_42 ( V_5 , & V_74 , 4 ) ;
V_107 . V_38 . V_39 . V_40 =
F_43 ( V_74 ) ;
if ( V_101 & V_94 )
break;
F_42 ( V_5 , & V_96 , 1 ) ;
break;
case V_41 :
F_42 ( V_5 , & V_74 , 4 ) ;
V_107 . V_38 . V_42 . V_40 =
F_43 ( V_74 ) ;
V_105 = ( T_1 * ) V_107 . V_38 . V_42 . V_43 ;
for ( F_42 ( V_5 , & V_26 , 1 ) ;
F_44 ( V_5 ) && V_26 != '\0' ;
F_42 ( V_5 , & V_26 , 1 ) )
* V_105 ++ = V_26 ;
* V_105 = '\0' ;
if ( V_101 & V_94 )
break;
F_42 ( V_5 , & V_96 , 1 ) ;
break;
case V_44 :
F_42 ( V_5 , & V_75 , 2 ) ;
V_107 . V_38 . V_45 . V_46 =
F_45 ( V_75 ) ;
F_42 ( V_5 , & V_75 , 2 ) ;
V_107 . V_38 . V_45 . V_47 =
F_45 ( V_75 ) ;
V_105 = ( T_1 * ) V_107 . V_38 . V_45 . V_17 ;
F_4 ( sizeof( V_107 . V_38 . V_45 . V_17 )
>= V_82 ) ;
for ( V_106 = 0 ;
V_106 < V_82
&& F_44 ( V_5 ) ; V_106 ++ ) {
F_42 ( V_5 , & V_26 , 1 ) ;
* V_105 ++ = V_26 ;
}
F_42 ( V_5 , & V_95 , 1 ) ;
V_107 . V_38 . V_45 . V_48 = V_95 ;
V_105 = V_107 . V_38 . V_45 . V_49 ;
while ( F_44 ( V_5 ) && V_95 -- ) {
F_42 ( V_5 , & V_26 , 1 ) ;
* V_105 ++ = V_26 ;
}
if ( V_101 & V_94 )
break;
F_42 ( V_5 , & V_96 , 1 ) ;
F_42 ( V_5 , & V_95 , 1 ) ;
F_42 ( V_5 , & V_57 , V_95 ) ;
break;
default:
F_26 ( L_9 ,
V_10 ) ;
goto error;
}
V_97 . V_3 = V_3 ;
V_97 . V_57 = V_107 ;
F_13 ( & V_1 -> V_22 ) ;
V_59 = F_24 ( V_1 , & V_97 ) ;
if ( V_101 == ( V_101 & V_94 ) ||
F_46 ( V_5 ) ) {
F_36 ( L_10
L_11 ) ;
V_1 -> V_64 . V_109 ( V_1 -> V_10 . V_11 . V_110 ,
0 ,
V_59 ? V_59 -> V_85
: NULL ) ;
} else {
V_1 -> V_64 . V_111 ( V_1 -> V_10 .
V_11 . V_110 , V_96 ,
V_10 , V_68 ,
V_59 ? V_59 ->
V_85 : NULL ) ;
}
if ( V_59 != NULL )
F_16 ( V_59 ) ;
F_17 ( & V_1 -> V_22 ) ;
}
break;
case V_89 :
F_42 ( V_5 , & V_96 , 1 ) ;
V_1 -> V_64 . V_112 ( V_1 -> V_10 . V_11 . V_110 , V_96 ) ;
break;
case V_99 :
F_36 ( L_12 ) ;
V_1 -> V_64 . V_113 () ;
break;
case V_71 :
V_1 -> V_64 . V_114 () ;
break;
case V_115 :
V_1 -> V_64 . V_116 () ;
break;
case V_117 :
V_1 -> V_64 . V_118 () ;
break;
case V_119 :
V_1 -> V_64 . V_120 () ;
break;
case V_121 :
V_1 -> V_64 . V_122 () ;
break;
default:
F_36 ( L_13 ) ;
goto error;
break;
}
V_77 = 0 ;
error:
F_47 ( V_5 ) ;
return V_77 ;
}
static void V_19 ( struct V_6 * V_91 , enum V_123 V_2 ,
int V_33 )
{
struct V_1 * V_8 = F_12 ( V_91 ) ;
switch ( V_2 ) {
case V_124 :
case V_125 :
F_13 ( & V_8 -> V_22 ) ;
if ( ! F_48 ( & V_8 -> V_23 ) )
F_31 ( L_14 ) ;
F_17 ( & V_8 -> V_22 ) ;
break;
case V_126 : {
struct V_24 * V_25 , * V_26 ;
F_13 ( & V_8 -> V_22 ) ;
F_14 (p, tmp, &this->list, list) {
if ( V_25 -> V_57 . V_33 == V_33 ) {
F_15 ( & V_25 -> V_23 ) ;
V_25 -> V_85 -> V_18 ( V_25 -> V_85 ,
V_127 ,
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
static int V_128 ;
static int V_129 ;
T_1 V_96 , V_31 , V_26 ;
switch ( V_3 ) {
case V_56 :
F_13 ( & V_2 -> V_20 ) ;
if ( ! V_129 ) {
for ( V_96 = V_128 + 1 ; V_96 < 254 ; V_96 ++ )
if ( ! V_2 -> V_90 [ V_96 ] )
goto V_93;
}
V_129 = 1 ;
for ( V_96 = V_128 - 1 ; V_96 > 1 ; V_96 -- )
if ( ! V_2 -> V_90 [ V_96 ] )
goto V_93;
F_17 ( & V_2 -> V_20 ) ;
return - 1 ;
V_93:
if ( V_96 < 10 )
V_129 = 0 ;
if ( ! V_2 -> V_90 [ V_96 ] )
V_2 -> V_90 [ V_96 ] = 1 ;
V_128 = V_96 ;
F_49 ( V_5 , & V_96 , 1 ) ;
F_17 ( & V_2 -> V_20 ) ;
F_50 ( V_5 , & V_31 , 1 ) ;
if ( V_31 == V_44 ) {
V_26 = 0x01 ;
F_49 ( V_5 , & V_26 , 1 ) ;
F_49 ( V_5 , & V_26 , 1 ) ;
}
break;
case V_89 :
F_13 ( & V_2 -> V_20 ) ;
F_50 ( V_5 , & V_96 , 1 ) ;
V_2 -> V_90 [ V_96 ] = 0 ;
F_17 ( & V_2 -> V_20 ) ;
break;
default:
break;
}
return 0 ;
}
