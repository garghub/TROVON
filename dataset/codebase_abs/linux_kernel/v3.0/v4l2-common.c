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
return 0 ;
}
int F_2 ( struct V_3 * V_4 , T_1 V_20 , T_1 V_21 , T_1 V_22 , T_1 V_23 )
{
const char * V_24 ;
F_3 ( V_4 -> V_25 , & V_24 , & V_4 -> type ,
& V_20 , & V_21 , & V_22 , & V_23 , & V_4 -> V_6 ) ;
if ( V_24 == NULL )
return - V_8 ;
V_4 -> V_16 = V_20 ;
V_4 -> V_17 = V_21 ;
V_4 -> V_22 = V_22 ;
V_4 -> V_26 = V_23 ;
V_4 -> V_27 [ 0 ] = V_4 -> V_27 [ 1 ] = 0 ;
F_4 ( V_4 -> V_24 , V_24 , sizeof( V_4 -> V_24 ) ) ;
return 0 ;
}
int F_5 ( struct V_28 * V_29 , struct V_3 * V_4 ,
const char * const * V_5 )
{
int V_30 ;
V_29 -> V_27 = 0 ;
if ( V_5 == NULL )
V_5 = F_6 ( V_29 -> V_25 ) ;
if ( V_5 == NULL ||
( V_4 && ( V_29 -> V_31 < V_4 -> V_16 || V_29 -> V_31 > V_4 -> V_17 ) ) )
return - V_8 ;
for ( V_30 = 0 ; V_30 < V_29 -> V_31 && V_5 [ V_30 ] ; V_30 ++ ) ;
if ( V_5 [ V_30 ] == NULL || V_5 [ V_30 ] [ 0 ] == '\0' )
return - V_8 ;
F_4 ( V_29 -> V_24 , V_5 [ V_29 -> V_31 ] , sizeof( V_29 -> V_24 ) ) ;
return 0 ;
}
int F_7 ( struct V_28 * V_29 , const T_2 * V_32 )
{
const char * const * V_5 = F_6 ( V_29 -> V_25 ) ;
V_29 -> V_27 = 0 ;
if ( V_5 == NULL || V_32 == NULL )
return - V_8 ;
while ( * V_32 != V_33 ) {
if ( * V_32 ++ == V_29 -> V_31 ) {
F_4 ( V_29 -> V_24 , V_5 [ V_29 -> V_31 ] ,
sizeof( V_29 -> V_24 ) ) ;
return 0 ;
}
}
return - V_8 ;
}
T_2 F_8 ( const T_2 * const * V_34 , T_2 V_25 )
{
T_2 V_35 = F_9 ( V_25 ) ;
const T_2 * V_36 ;
if ( V_34 == NULL )
return 0 ;
if ( ( V_25 & V_37 ) == 0 ) {
while ( * V_34 && F_9 ( * * V_34 ) != V_35 )
V_34 ++ ;
if ( * V_34 == NULL )
return 0 ;
V_36 = * V_34 ;
while ( * V_36 && * V_36 != V_25 ) V_36 ++ ;
return * V_36 ? V_25 : 0 ;
}
V_25 &= V_38 ;
V_25 ++ ;
while ( * V_34 && F_9 ( * * V_34 ) < V_35 )
V_34 ++ ;
if ( * V_34 == NULL )
return 0 ;
V_36 = * V_34 ;
while ( * V_36 && * V_36 < V_25 ) V_36 ++ ;
if ( * V_36 )
return * V_36 ;
V_34 ++ ;
if ( * V_34 == NULL )
return 0 ;
return * * V_34 ;
}
int F_10 ( const struct V_39 * V_40 )
{
switch ( V_40 -> type ) {
case V_41 :
return V_40 -> V_42 == 0 ;
default:
return 0 ;
}
}
int F_11 ( struct V_43 * V_44 , const struct V_39 * V_40 )
{
int V_45 ;
if ( V_44 == NULL || V_40 == NULL )
return 0 ;
switch ( V_40 -> type ) {
case V_46 :
if ( V_44 -> V_47 == NULL || V_44 -> V_47 -> V_47 . V_24 == NULL )
return 0 ;
V_45 = strlen ( V_44 -> V_47 -> V_47 . V_24 ) ;
if ( V_45 && V_44 -> V_47 -> V_47 . V_24 [ V_45 - 1 ] == '\'' )
V_45 -- ;
return V_45 && ! strncmp ( V_44 -> V_47 -> V_47 . V_24 , V_40 -> V_24 , V_45 ) ;
case V_48 :
return V_44 -> V_42 == V_40 -> V_42 ;
default:
return 0 ;
}
}
int F_12 ( struct V_43 * V_44 , struct V_49 * V_50 ,
T_2 V_51 , T_2 V_52 )
{
if ( ! F_11 ( V_44 , & V_50 -> V_40 ) )
return 0 ;
if ( V_50 -> V_51 == V_53 ) {
V_50 -> V_51 = V_51 ;
V_50 -> V_52 = V_52 ;
}
else {
V_50 -> V_51 = V_54 ;
V_50 -> V_52 = 0 ;
}
return 0 ;
}
void F_13 ( struct V_55 * V_56 , struct V_43 * V_57 ,
const struct V_58 * V_59 )
{
F_14 ( V_56 , V_59 ) ;
V_56 -> V_6 |= V_60 ;
V_56 -> V_61 = V_57 -> V_47 -> V_47 . V_61 ;
F_15 ( V_56 , V_57 ) ;
F_16 ( V_57 , V_56 ) ;
snprintf ( V_56 -> V_24 , sizeof( V_56 -> V_24 ) , L_1 ,
V_57 -> V_47 -> V_47 . V_24 , F_17 ( V_57 -> V_62 ) ,
V_57 -> V_42 ) ;
}
struct V_55 * F_18 ( struct V_63 * V_64 ,
struct V_65 * V_62 , struct V_66 * V_67 ,
const unsigned short * V_68 )
{
struct V_55 * V_56 = NULL ;
struct V_43 * V_57 ;
F_19 ( ! V_64 ) ;
F_20 ( V_69 L_2 , V_67 -> type ) ;
if ( V_67 -> V_42 == 0 && V_68 )
V_57 = F_21 ( V_62 , V_67 , V_68 ,
NULL ) ;
else
V_57 = F_22 ( V_62 , V_67 ) ;
if ( V_57 == NULL || V_57 -> V_47 == NULL )
goto error;
if ( ! F_23 ( V_57 -> V_47 -> V_47 . V_61 ) )
goto error;
V_56 = F_24 ( V_57 ) ;
if ( F_25 ( V_64 , V_56 ) )
V_56 = NULL ;
F_26 ( V_57 -> V_47 -> V_47 . V_61 ) ;
error:
if ( V_57 && V_56 == NULL )
F_27 ( V_57 ) ;
return V_56 ;
}
struct V_55 * F_28 ( struct V_63 * V_64 ,
struct V_65 * V_62 , const char * V_70 ,
T_3 V_42 , const unsigned short * V_68 )
{
struct V_66 V_67 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
F_4 ( V_67 . type , V_70 , sizeof( V_67 . type ) ) ;
V_67 . V_42 = V_42 ;
return F_18 ( V_64 , V_62 , & V_67 , V_68 ) ;
}
unsigned short F_29 ( struct V_55 * V_56 )
{
struct V_43 * V_57 = F_30 ( V_56 ) ;
return V_57 ? V_57 -> V_42 : V_71 ;
}
const unsigned short * F_31 ( enum V_72 type )
{
static const unsigned short V_73 [] = {
#if F_32 ( V_74 ) || F_32 ( V_75 )
0x10 ,
#endif
0x60 ,
V_71
} ;
static const unsigned short V_76 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
V_71
} ;
static const unsigned short V_77 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
0x60 , 0x61 , 0x62 , 0x63 , 0x64 ,
V_71
} ;
switch ( type ) {
case V_78 :
return V_73 ;
case V_79 :
return V_76 ;
case V_80 :
return V_77 ;
case V_81 :
return V_77 + 4 ;
}
return NULL ;
}
void F_33 ( struct V_55 * V_56 , struct V_82 * V_83 ,
const struct V_58 * V_59 )
{
F_14 ( V_56 , V_59 ) ;
V_56 -> V_6 |= V_84 ;
V_56 -> V_61 = V_83 -> V_85 . V_47 -> V_61 ;
F_15 ( V_56 , V_83 ) ;
F_34 ( V_83 , V_56 ) ;
F_4 ( V_56 -> V_24 , V_83 -> V_85 . V_47 -> V_24 , sizeof( V_56 -> V_24 ) ) ;
}
struct V_55 * F_35 ( struct V_63 * V_64 ,
struct V_86 * V_87 , struct V_88 * V_67 )
{
struct V_55 * V_56 = NULL ;
struct V_82 * V_83 = NULL ;
F_19 ( ! V_64 ) ;
if ( V_67 -> V_89 )
F_20 ( V_67 -> V_89 ) ;
V_83 = F_36 ( V_87 , V_67 ) ;
if ( V_83 == NULL || V_83 -> V_85 . V_47 == NULL )
goto error;
if ( ! F_23 ( V_83 -> V_85 . V_47 -> V_61 ) )
goto error;
V_56 = F_37 ( V_83 ) ;
if ( F_25 ( V_64 , V_56 ) )
V_56 = NULL ;
F_26 ( V_83 -> V_85 . V_47 -> V_61 ) ;
error:
if ( V_83 && V_56 == NULL )
F_38 ( V_83 ) ;
return V_56 ;
}
static unsigned int F_39 ( unsigned int V_90 , unsigned int V_20 ,
unsigned int V_21 , unsigned int V_91 )
{
unsigned int V_92 = ~ ( ( 1 << V_91 ) - 1 ) ;
if ( V_91 )
V_90 = ( V_90 + ( 1 << ( V_91 - 1 ) ) ) & V_92 ;
if ( V_90 < V_20 )
V_90 = ( V_20 + ~ V_92 ) & V_92 ;
else if ( V_90 > V_21 )
V_90 = V_21 & V_92 ;
return V_90 ;
}
void F_40 ( T_2 * V_93 , unsigned int V_94 , unsigned int V_95 ,
unsigned int V_96 ,
T_2 * V_97 , unsigned int V_98 , unsigned int V_99 ,
unsigned int V_100 , unsigned int V_101 )
{
* V_93 = F_39 ( * V_93 , V_94 , V_95 , V_96 ) ;
* V_97 = F_39 ( * V_97 , V_98 , V_99 , V_100 ) ;
if ( ! V_101 )
return;
V_96 = F_41 ( * V_93 ) ;
V_100 = F_41 ( * V_97 ) ;
if ( V_96 + V_100 < V_101 ) {
unsigned int V_102 = F_42 ( V_95 ^ ( V_94 - 1 ) ) ;
unsigned int V_103 = F_42 ( V_99 ^ ( V_98 - 1 ) ) ;
do {
if ( V_100 >= V_103 ||
( V_96 <= V_100 && V_96 < V_102 ) ) {
* V_93 = F_39 ( * V_93 , V_94 , V_95 , V_96 + 1 ) ;
V_96 = F_41 ( * V_93 ) ;
} else {
* V_97 = F_39 ( * V_97 , V_98 , V_99 , V_100 + 1 ) ;
V_100 = F_41 ( * V_97 ) ;
}
} while ( V_100 + V_96 < V_101 );
}
}
int F_43 ( T_2 V_104 , struct V_105 * V_67 )
{
static const struct V_106 {
T_4 V_107 ;
T_4 V_108 ;
const char * V_24 ;
} V_109 [] = {
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
if ( V_67 == NULL || V_104 >= F_44 ( V_109 ) )
return - V_8 ;
V_67 -> V_104 = V_104 ;
V_67 -> V_107 = V_109 [ V_104 ] . V_107 ;
V_67 -> V_108 = V_109 [ V_104 ] . V_108 ;
F_4 ( V_67 -> V_24 , V_109 [ V_104 ] . V_24 , sizeof( V_67 -> V_24 ) ) ;
return 0 ;
}
const struct V_110 * F_45 (
const struct V_111 * V_112 ,
T_1 V_107 , T_1 V_108 )
{
int V_30 ;
T_2 error , V_113 = V_114 ;
const struct V_110 * V_115 , * V_116 = NULL ;
if ( ! V_112 )
return V_116 ;
for ( V_30 = 0 , V_115 = V_112 -> V_117 ; V_30 < V_112 -> V_118 ; V_30 ++ , V_115 ++ ) {
error = abs ( V_115 -> V_107 - V_107 ) + abs ( V_115 -> V_108 - V_108 ) ;
if ( error < V_113 ) {
V_113 = error ;
V_116 = V_115 ;
}
if ( ! error )
break;
}
return V_116 ;
}
