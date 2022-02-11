int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * const * V_5 )
{
if ( V_4 -> V_6 & V_7 )
return - V_8 ;
if ( V_4 -> V_6 & V_9 )
return - V_10 ;
if ( V_4 -> type == V_11 )
return 0 ;
if ( V_4 -> type == V_12 ||
V_4 -> type == V_13 ||
V_4 -> type == V_14 )
return 0 ;
if ( V_2 -> V_15 < V_4 -> V_16 || V_2 -> V_15 > V_4 -> V_17 )
return - V_18 ;
if ( V_4 -> type == V_19 && V_5 != NULL ) {
if ( V_5 [ V_2 -> V_15 ] == NULL ||
V_5 [ V_2 -> V_15 ] [ 0 ] == '\0' )
return - V_8 ;
}
if ( V_4 -> type == V_20 &&
( V_2 -> V_15 & ~ V_4 -> V_17 ) )
return - V_18 ;
return 0 ;
}
int F_2 ( struct V_3 * V_4 , T_1 V_21 , T_1 V_22 , T_1 V_23 , T_1 V_24 )
{
const char * V_25 ;
F_3 ( V_4 -> V_26 , & V_25 , & V_4 -> type ,
& V_21 , & V_22 , & V_23 , & V_24 , & V_4 -> V_6 ) ;
if ( V_25 == NULL )
return - V_8 ;
V_4 -> V_16 = V_21 ;
V_4 -> V_17 = V_22 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_27 = V_24 ;
V_4 -> V_28 [ 0 ] = V_4 -> V_28 [ 1 ] = 0 ;
F_4 ( V_4 -> V_25 , V_25 , sizeof( V_4 -> V_25 ) ) ;
return 0 ;
}
int F_5 ( struct V_29 * V_30 , struct V_3 * V_4 ,
const char * const * V_5 )
{
int V_31 ;
V_30 -> V_28 = 0 ;
if ( V_5 == NULL )
V_5 = F_6 ( V_30 -> V_26 ) ;
if ( V_5 == NULL ||
( V_4 && ( V_30 -> V_32 < V_4 -> V_16 || V_30 -> V_32 > V_4 -> V_17 ) ) )
return - V_8 ;
for ( V_31 = 0 ; V_31 < V_30 -> V_32 && V_5 [ V_31 ] ; V_31 ++ ) ;
if ( V_5 [ V_31 ] == NULL || V_5 [ V_31 ] [ 0 ] == '\0' )
return - V_8 ;
F_4 ( V_30 -> V_25 , V_5 [ V_30 -> V_32 ] , sizeof( V_30 -> V_25 ) ) ;
return 0 ;
}
int F_7 ( struct V_29 * V_30 , const T_2 * V_33 )
{
const char * const * V_5 = F_6 ( V_30 -> V_26 ) ;
V_30 -> V_28 = 0 ;
if ( V_5 == NULL || V_33 == NULL )
return - V_8 ;
while ( * V_33 != V_34 ) {
if ( * V_33 ++ == V_30 -> V_32 ) {
F_4 ( V_30 -> V_25 , V_5 [ V_30 -> V_32 ] ,
sizeof( V_30 -> V_25 ) ) ;
return 0 ;
}
}
return - V_8 ;
}
T_2 F_8 ( const T_2 * const * V_35 , T_2 V_26 )
{
T_2 V_36 = F_9 ( V_26 ) ;
const T_2 * V_37 ;
if ( V_35 == NULL )
return 0 ;
if ( ( V_26 & V_38 ) == 0 ) {
while ( * V_35 && F_9 ( * * V_35 ) != V_36 )
V_35 ++ ;
if ( * V_35 == NULL )
return 0 ;
V_37 = * V_35 ;
while ( * V_37 && * V_37 != V_26 ) V_37 ++ ;
return * V_37 ? V_26 : 0 ;
}
V_26 &= V_39 ;
V_26 ++ ;
while ( * V_35 && F_9 ( * * V_35 ) < V_36 )
V_35 ++ ;
if ( * V_35 == NULL )
return 0 ;
V_37 = * V_35 ;
while ( * V_37 && * V_37 < V_26 ) V_37 ++ ;
if ( * V_37 )
return * V_37 ;
V_35 ++ ;
if ( * V_35 == NULL )
return 0 ;
return * * V_35 ;
}
int F_10 ( const struct V_40 * V_41 )
{
switch ( V_41 -> type ) {
case V_42 :
return V_41 -> V_43 == 0 ;
default:
return 0 ;
}
}
int F_11 ( struct V_44 * V_45 , const struct V_40 * V_41 )
{
int V_46 ;
if ( V_45 == NULL || V_41 == NULL )
return 0 ;
switch ( V_41 -> type ) {
case V_47 :
if ( V_45 -> V_48 == NULL || V_45 -> V_48 -> V_48 . V_25 == NULL )
return 0 ;
V_46 = strlen ( V_45 -> V_48 -> V_48 . V_25 ) ;
if ( V_46 && V_45 -> V_48 -> V_48 . V_25 [ V_46 - 1 ] == '\'' )
V_46 -- ;
return V_46 && ! strncmp ( V_45 -> V_48 -> V_48 . V_25 , V_41 -> V_25 , V_46 ) ;
case V_49 :
return V_45 -> V_43 == V_41 -> V_43 ;
default:
return 0 ;
}
}
int F_12 ( struct V_44 * V_45 , struct V_50 * V_51 ,
T_2 V_52 , T_2 V_53 )
{
if ( ! F_11 ( V_45 , & V_51 -> V_41 ) )
return 0 ;
if ( V_51 -> V_52 == V_54 ) {
V_51 -> V_52 = V_52 ;
V_51 -> V_53 = V_53 ;
}
else {
V_51 -> V_52 = V_55 ;
V_51 -> V_53 = 0 ;
}
return 0 ;
}
void F_13 ( struct V_56 * V_57 , struct V_44 * V_58 ,
const struct V_59 * V_60 )
{
F_14 ( V_57 , V_60 ) ;
V_57 -> V_6 |= V_61 ;
V_57 -> V_62 = V_58 -> V_48 -> V_48 . V_62 ;
F_15 ( V_57 , V_58 ) ;
F_16 ( V_58 , V_57 ) ;
snprintf ( V_57 -> V_25 , sizeof( V_57 -> V_25 ) , L_1 ,
V_58 -> V_48 -> V_48 . V_25 , F_17 ( V_58 -> V_63 ) ,
V_58 -> V_43 ) ;
}
struct V_56 * F_18 ( struct V_64 * V_65 ,
struct V_66 * V_63 , struct V_67 * V_68 ,
const unsigned short * V_69 )
{
struct V_56 * V_57 = NULL ;
struct V_44 * V_58 ;
F_19 ( ! V_65 ) ;
F_20 ( V_70 L_2 , V_68 -> type ) ;
if ( V_68 -> V_43 == 0 && V_69 )
V_58 = F_21 ( V_63 , V_68 , V_69 ,
NULL ) ;
else
V_58 = F_22 ( V_63 , V_68 ) ;
if ( V_58 == NULL || V_58 -> V_48 == NULL )
goto error;
if ( ! F_23 ( V_58 -> V_48 -> V_48 . V_62 ) )
goto error;
V_57 = F_24 ( V_58 ) ;
if ( F_25 ( V_65 , V_57 ) )
V_57 = NULL ;
F_26 ( V_58 -> V_48 -> V_48 . V_62 ) ;
error:
if ( V_58 && V_57 == NULL )
F_27 ( V_58 ) ;
return V_57 ;
}
struct V_56 * F_28 ( struct V_64 * V_65 ,
struct V_66 * V_63 , const char * V_71 ,
T_3 V_43 , const unsigned short * V_69 )
{
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
F_4 ( V_68 . type , V_71 , sizeof( V_68 . type ) ) ;
V_68 . V_43 = V_43 ;
return F_18 ( V_65 , V_63 , & V_68 , V_69 ) ;
}
unsigned short F_29 ( struct V_56 * V_57 )
{
struct V_44 * V_58 = F_30 ( V_57 ) ;
return V_58 ? V_58 -> V_43 : V_72 ;
}
const unsigned short * F_31 ( enum V_73 type )
{
static const unsigned short V_74 [] = {
#if F_32 ( V_75 ) || F_32 ( V_76 )
0x10 ,
#endif
0x60 ,
V_72
} ;
static const unsigned short V_77 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
V_72
} ;
static const unsigned short V_78 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
0x60 , 0x61 , 0x62 , 0x63 , 0x64 ,
V_72
} ;
switch ( type ) {
case V_79 :
return V_74 ;
case V_80 :
return V_77 ;
case V_81 :
return V_78 ;
case V_82 :
return V_78 + 4 ;
}
return NULL ;
}
void F_33 ( struct V_56 * V_57 , struct V_83 * V_84 ,
const struct V_59 * V_60 )
{
F_14 ( V_57 , V_60 ) ;
V_57 -> V_6 |= V_85 ;
V_57 -> V_62 = V_84 -> V_86 . V_48 -> V_62 ;
F_15 ( V_57 , V_84 ) ;
F_34 ( V_84 , V_57 ) ;
F_4 ( V_57 -> V_25 , V_84 -> V_86 . V_48 -> V_25 , sizeof( V_57 -> V_25 ) ) ;
}
struct V_56 * F_35 ( struct V_64 * V_65 ,
struct V_87 * V_88 , struct V_89 * V_68 )
{
struct V_56 * V_57 = NULL ;
struct V_83 * V_84 = NULL ;
F_19 ( ! V_65 ) ;
if ( V_68 -> V_90 )
F_20 ( V_68 -> V_90 ) ;
V_84 = F_36 ( V_88 , V_68 ) ;
if ( V_84 == NULL || V_84 -> V_86 . V_48 == NULL )
goto error;
if ( ! F_23 ( V_84 -> V_86 . V_48 -> V_62 ) )
goto error;
V_57 = F_37 ( V_84 ) ;
if ( F_25 ( V_65 , V_57 ) )
V_57 = NULL ;
F_26 ( V_84 -> V_86 . V_48 -> V_62 ) ;
error:
if ( V_84 && V_57 == NULL )
F_38 ( V_84 ) ;
return V_57 ;
}
static unsigned int F_39 ( unsigned int V_91 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_92 )
{
unsigned int V_93 = ~ ( ( 1 << V_92 ) - 1 ) ;
if ( V_92 )
V_91 = ( V_91 + ( 1 << ( V_92 - 1 ) ) ) & V_93 ;
if ( V_91 < V_21 )
V_91 = ( V_21 + ~ V_93 ) & V_93 ;
else if ( V_91 > V_22 )
V_91 = V_22 & V_93 ;
return V_91 ;
}
void F_40 ( T_2 * V_94 , unsigned int V_95 , unsigned int V_96 ,
unsigned int V_97 ,
T_2 * V_98 , unsigned int V_99 , unsigned int V_100 ,
unsigned int V_101 , unsigned int V_102 )
{
* V_94 = F_39 ( * V_94 , V_95 , V_96 , V_97 ) ;
* V_98 = F_39 ( * V_98 , V_99 , V_100 , V_101 ) ;
if ( ! V_102 )
return;
V_97 = F_41 ( * V_94 ) ;
V_101 = F_41 ( * V_98 ) ;
if ( V_97 + V_101 < V_102 ) {
unsigned int V_103 = F_42 ( V_96 ^ ( V_95 - 1 ) ) ;
unsigned int V_104 = F_42 ( V_100 ^ ( V_99 - 1 ) ) ;
do {
if ( V_101 >= V_104 ||
( V_97 <= V_101 && V_97 < V_103 ) ) {
* V_94 = F_39 ( * V_94 , V_95 , V_96 , V_97 + 1 ) ;
V_97 = F_41 ( * V_94 ) ;
} else {
* V_98 = F_39 ( * V_98 , V_99 , V_100 , V_101 + 1 ) ;
V_101 = F_41 ( * V_98 ) ;
}
} while ( V_101 + V_97 < V_102 );
}
}
int F_43 ( T_2 V_105 , struct V_106 * V_68 )
{
static const struct V_107 {
T_4 V_108 ;
T_4 V_109 ;
const char * V_25 ;
} V_110 [] = {
{ 0 , 0 , L_3 } ,
{ 720 , 480 , L_4 } ,
{ 720 , 576 , L_5 } ,
{ 1280 , 720 , L_6 } ,
{ 1280 , 720 , L_7 } ,
{ 1280 , 720 , L_8 } ,
{ 1280 , 720 , L_9 } ,
{ 1280 , 720 , L_10 } ,
{ 1280 , 720 , L_11 } ,
{ 1920 , 1080 , L_12 } ,
{ 1920 , 1080 , L_13 } ,
{ 1920 , 1080 , L_14 } ,
{ 1920 , 1080 , L_15 } ,
{ 1920 , 1080 , L_16 } ,
{ 1920 , 1080 , L_17 } ,
{ 1920 , 1080 , L_18 } ,
{ 1920 , 1080 , L_19 } ,
{ 1920 , 1080 , L_20 } ,
{ 1920 , 1080 , L_21 } ,
} ;
if ( V_68 == NULL || V_105 >= F_44 ( V_110 ) )
return - V_8 ;
V_68 -> V_105 = V_105 ;
V_68 -> V_108 = V_110 [ V_105 ] . V_108 ;
V_68 -> V_109 = V_110 [ V_105 ] . V_109 ;
F_4 ( V_68 -> V_25 , V_110 [ V_105 ] . V_25 , sizeof( V_68 -> V_25 ) ) ;
return 0 ;
}
const struct V_111 * F_45 (
const struct V_112 * V_113 ,
T_1 V_108 , T_1 V_109 )
{
int V_31 ;
T_2 error , V_114 = V_115 ;
const struct V_111 * V_116 , * V_117 = NULL ;
if ( ! V_113 )
return V_117 ;
for ( V_31 = 0 , V_116 = V_113 -> V_118 ; V_31 < V_113 -> V_119 ; V_31 ++ , V_116 ++ ) {
error = abs ( V_116 -> V_108 - V_108 ) + abs ( V_116 -> V_109 - V_109 ) ;
if ( error < V_114 ) {
V_114 = error ;
V_117 = V_116 ;
}
if ( ! error )
break;
}
return V_117 ;
}
