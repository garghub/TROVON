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
T_2 V_26 = V_21 ;
T_2 V_27 = V_22 ;
T_3 V_28 = V_23 ;
T_2 V_29 = V_24 ;
F_3 ( V_4 -> V_30 , & V_25 , & V_4 -> type ,
& V_26 , & V_27 , & V_28 , & V_29 , & V_4 -> V_6 ) ;
if ( V_25 == NULL )
return - V_8 ;
V_4 -> V_16 = V_26 ;
V_4 -> V_17 = V_27 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_31 = V_29 ;
V_4 -> V_32 [ 0 ] = V_4 -> V_32 [ 1 ] = 0 ;
F_4 ( V_4 -> V_25 , V_25 , sizeof( V_4 -> V_25 ) ) ;
return 0 ;
}
int F_5 ( struct V_33 * V_34 , struct V_3 * V_4 ,
const char * const * V_5 )
{
int V_35 ;
V_34 -> V_32 = 0 ;
if ( V_5 == NULL )
V_5 = F_6 ( V_34 -> V_30 ) ;
if ( V_5 == NULL ||
( V_4 && ( V_34 -> V_36 < V_4 -> V_16 || V_34 -> V_36 > V_4 -> V_17 ) ) )
return - V_8 ;
for ( V_35 = 0 ; V_35 < V_34 -> V_36 && V_5 [ V_35 ] ; V_35 ++ ) ;
if ( V_5 [ V_35 ] == NULL || V_5 [ V_35 ] [ 0 ] == '\0' )
return - V_8 ;
F_4 ( V_34 -> V_25 , V_5 [ V_34 -> V_36 ] , sizeof( V_34 -> V_25 ) ) ;
return 0 ;
}
int F_7 ( struct V_33 * V_34 , const T_4 * V_37 )
{
const char * const * V_5 = F_6 ( V_34 -> V_30 ) ;
V_34 -> V_32 = 0 ;
if ( V_5 == NULL || V_37 == NULL )
return - V_8 ;
while ( * V_37 != V_38 ) {
if ( * V_37 ++ == V_34 -> V_36 ) {
F_4 ( V_34 -> V_25 , V_5 [ V_34 -> V_36 ] ,
sizeof( V_34 -> V_25 ) ) ;
return 0 ;
}
}
return - V_8 ;
}
T_4 F_8 ( const T_4 * const * V_39 , T_4 V_30 )
{
T_4 V_40 = F_9 ( V_30 ) ;
const T_4 * V_41 ;
if ( V_39 == NULL )
return 0 ;
if ( ( V_30 & V_42 ) == 0 ) {
while ( * V_39 && F_9 ( * * V_39 ) != V_40 )
V_39 ++ ;
if ( * V_39 == NULL )
return 0 ;
V_41 = * V_39 ;
while ( * V_41 && * V_41 != V_30 ) V_41 ++ ;
return * V_41 ? V_30 : 0 ;
}
V_30 &= V_43 ;
V_30 ++ ;
while ( * V_39 && F_9 ( * * V_39 ) < V_40 )
V_39 ++ ;
if ( * V_39 == NULL )
return 0 ;
V_41 = * V_39 ;
while ( * V_41 && * V_41 < V_30 ) V_41 ++ ;
if ( * V_41 )
return * V_41 ;
V_39 ++ ;
if ( * V_39 == NULL )
return 0 ;
return * * V_39 ;
}
void F_10 ( struct V_44 * V_45 , struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
F_11 ( V_45 , V_49 ) ;
V_45 -> V_6 |= V_50 ;
V_45 -> V_51 = V_47 -> V_52 . V_53 -> V_51 ;
V_45 -> V_52 = & V_47 -> V_52 ;
F_12 ( V_45 , V_47 ) ;
F_13 ( V_47 , V_45 ) ;
snprintf ( V_45 -> V_25 , sizeof( V_45 -> V_25 ) , L_1 ,
V_47 -> V_52 . V_53 -> V_25 , F_14 ( V_47 -> V_54 ) ,
V_47 -> V_55 ) ;
}
struct V_44 * F_15 ( struct V_56 * V_57 ,
struct V_58 * V_54 , struct V_59 * V_60 ,
const unsigned short * V_61 )
{
struct V_44 * V_45 = NULL ;
struct V_46 * V_47 ;
F_16 ( ! V_57 ) ;
F_17 ( V_62 L_2 , V_60 -> type ) ;
if ( V_60 -> V_55 == 0 && V_61 )
V_47 = F_18 ( V_54 , V_60 , V_61 ,
NULL ) ;
else
V_47 = F_19 ( V_54 , V_60 ) ;
if ( V_47 == NULL || V_47 -> V_52 . V_53 == NULL )
goto error;
if ( ! F_20 ( V_47 -> V_52 . V_53 -> V_51 ) )
goto error;
V_45 = F_21 ( V_47 ) ;
if ( F_22 ( V_57 , V_45 ) )
V_45 = NULL ;
F_23 ( V_47 -> V_52 . V_53 -> V_51 ) ;
error:
if ( V_47 && V_45 == NULL )
F_24 ( V_47 ) ;
return V_45 ;
}
struct V_44 * F_25 ( struct V_56 * V_57 ,
struct V_58 * V_54 , const char * V_63 ,
T_5 V_55 , const unsigned short * V_61 )
{
struct V_59 V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_4 ( V_60 . type , V_63 , sizeof( V_60 . type ) ) ;
V_60 . V_55 = V_55 ;
return F_15 ( V_57 , V_54 , & V_60 , V_61 ) ;
}
unsigned short F_26 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_27 ( V_45 ) ;
return V_47 ? V_47 -> V_55 : V_64 ;
}
const unsigned short * F_28 ( enum V_65 type )
{
static const unsigned short V_66 [] = {
#if F_29 ( V_67 )
0x10 ,
#endif
0x60 ,
V_64
} ;
static const unsigned short V_68 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
V_64
} ;
static const unsigned short V_69 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
0x60 , 0x61 , 0x62 , 0x63 , 0x64 ,
V_64
} ;
switch ( type ) {
case V_70 :
return V_66 ;
case V_71 :
return V_68 ;
case V_72 :
return V_69 ;
case V_73 :
return V_69 + 4 ;
}
return NULL ;
}
void F_30 ( struct V_44 * V_45 , struct V_74 * V_75 ,
const struct V_48 * V_49 )
{
F_11 ( V_45 , V_49 ) ;
V_45 -> V_6 |= V_76 ;
V_45 -> V_51 = V_75 -> V_52 . V_53 -> V_51 ;
V_45 -> V_52 = & V_75 -> V_52 ;
F_12 ( V_45 , V_75 ) ;
F_31 ( V_75 , V_45 ) ;
F_4 ( V_45 -> V_25 , V_75 -> V_52 . V_53 -> V_25 , sizeof( V_45 -> V_25 ) ) ;
}
struct V_44 * F_32 ( struct V_56 * V_57 ,
struct V_77 * V_78 , struct V_79 * V_60 )
{
struct V_44 * V_45 = NULL ;
struct V_74 * V_75 = NULL ;
F_16 ( ! V_57 ) ;
if ( V_60 -> V_80 [ 0 ] )
F_17 ( V_60 -> V_80 ) ;
V_75 = F_33 ( V_78 , V_60 ) ;
if ( V_75 == NULL || V_75 -> V_52 . V_53 == NULL )
goto error;
if ( ! F_20 ( V_75 -> V_52 . V_53 -> V_51 ) )
goto error;
V_45 = F_34 ( V_75 ) ;
if ( F_22 ( V_57 , V_45 ) )
V_45 = NULL ;
F_23 ( V_75 -> V_52 . V_53 -> V_51 ) ;
error:
if ( V_75 && V_45 == NULL )
F_35 ( V_75 ) ;
return V_45 ;
}
static unsigned int F_36 ( unsigned int V_81 , unsigned int V_26 ,
unsigned int V_27 , unsigned int V_82 )
{
unsigned int V_83 = ~ ( ( 1 << V_82 ) - 1 ) ;
V_81 = F_37 ( V_81 , ( V_26 + ~ V_83 ) & V_83 , V_27 & V_83 ) ;
if ( V_82 )
V_81 = ( V_81 + ( 1 << ( V_82 - 1 ) ) ) & V_83 ;
return V_81 ;
}
void F_38 ( T_4 * V_84 , unsigned int V_85 , unsigned int V_86 ,
unsigned int V_87 ,
T_4 * V_88 , unsigned int V_89 , unsigned int V_90 ,
unsigned int V_91 , unsigned int V_92 )
{
* V_84 = F_36 ( * V_84 , V_85 , V_86 , V_87 ) ;
* V_88 = F_36 ( * V_88 , V_89 , V_90 , V_91 ) ;
if ( ! V_92 )
return;
V_87 = F_39 ( * V_84 ) ;
V_91 = F_39 ( * V_88 ) ;
if ( V_87 + V_91 < V_92 ) {
unsigned int V_93 = F_40 ( V_86 ^ ( V_85 - 1 ) ) ;
unsigned int V_94 = F_40 ( V_90 ^ ( V_89 - 1 ) ) ;
do {
if ( V_91 >= V_94 ||
( V_87 <= V_91 && V_87 < V_93 ) ) {
* V_84 = F_36 ( * V_84 , V_85 , V_86 , V_87 + 1 ) ;
V_87 = F_39 ( * V_84 ) ;
} else {
* V_88 = F_36 ( * V_88 , V_89 , V_90 , V_91 + 1 ) ;
V_91 = F_39 ( * V_88 ) ;
}
} while ( V_91 + V_87 < V_92 );
}
}
const struct V_95 * F_41 (
const struct V_96 * V_97 ,
T_1 V_98 , T_1 V_99 )
{
int V_35 ;
T_4 error , V_100 = V_101 ;
const struct V_95 * V_102 , * V_103 = NULL ;
if ( ! V_97 )
return V_103 ;
for ( V_35 = 0 , V_102 = V_97 -> V_104 ; V_35 < V_97 -> V_105 ; V_35 ++ , V_102 ++ ) {
error = abs ( V_102 -> V_98 - V_98 ) + abs ( V_102 -> V_99 - V_99 ) ;
if ( error < V_100 ) {
V_100 = error ;
V_103 = V_102 ;
}
if ( ! error )
break;
}
return V_103 ;
}
void F_42 ( struct V_106 * V_107 )
{
struct V_108 V_109 ;
F_43 ( & V_109 ) ;
V_107 -> V_110 = V_109 . V_110 ;
V_107 -> V_111 = V_109 . V_112 / V_113 ;
}
