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
void F_10 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
F_11 ( V_41 , V_45 ) ;
V_41 -> V_6 |= V_46 ;
V_41 -> V_47 = V_43 -> V_48 -> V_48 . V_47 ;
V_41 -> V_49 = & V_43 -> V_49 ;
F_12 ( V_41 , V_43 ) ;
F_13 ( V_43 , V_41 ) ;
snprintf ( V_41 -> V_25 , sizeof( V_41 -> V_25 ) , L_1 ,
V_43 -> V_48 -> V_48 . V_25 , F_14 ( V_43 -> V_50 ) ,
V_43 -> V_51 ) ;
}
struct V_40 * F_15 ( struct V_52 * V_53 ,
struct V_54 * V_50 , struct V_55 * V_56 ,
const unsigned short * V_57 )
{
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 ;
F_16 ( ! V_53 ) ;
F_17 ( V_58 L_2 , V_56 -> type ) ;
if ( V_56 -> V_51 == 0 && V_57 )
V_43 = F_18 ( V_50 , V_56 , V_57 ,
NULL ) ;
else
V_43 = F_19 ( V_50 , V_56 ) ;
if ( V_43 == NULL || V_43 -> V_48 == NULL )
goto error;
if ( ! F_20 ( V_43 -> V_48 -> V_48 . V_47 ) )
goto error;
V_41 = F_21 ( V_43 ) ;
if ( F_22 ( V_53 , V_41 ) )
V_41 = NULL ;
F_23 ( V_43 -> V_48 -> V_48 . V_47 ) ;
error:
if ( V_43 && V_41 == NULL )
F_24 ( V_43 ) ;
return V_41 ;
}
struct V_40 * F_25 ( struct V_52 * V_53 ,
struct V_54 * V_50 , const char * V_59 ,
T_3 V_51 , const unsigned short * V_57 )
{
struct V_55 V_56 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
F_4 ( V_56 . type , V_59 , sizeof( V_56 . type ) ) ;
V_56 . V_51 = V_51 ;
return F_15 ( V_53 , V_50 , & V_56 , V_57 ) ;
}
unsigned short F_26 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
return V_43 ? V_43 -> V_51 : V_60 ;
}
const unsigned short * F_28 ( enum V_61 type )
{
static const unsigned short V_62 [] = {
#if F_29 ( V_63 )
0x10 ,
#endif
0x60 ,
V_60
} ;
static const unsigned short V_64 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
V_60
} ;
static const unsigned short V_65 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
0x60 , 0x61 , 0x62 , 0x63 , 0x64 ,
V_60
} ;
switch ( type ) {
case V_66 :
return V_62 ;
case V_67 :
return V_64 ;
case V_68 :
return V_65 ;
case V_69 :
return V_65 + 4 ;
}
return NULL ;
}
void F_30 ( struct V_40 * V_41 , struct V_70 * V_71 ,
const struct V_44 * V_45 )
{
F_11 ( V_41 , V_45 ) ;
V_41 -> V_6 |= V_72 ;
V_41 -> V_47 = V_71 -> V_49 . V_48 -> V_47 ;
V_41 -> V_49 = & V_71 -> V_49 ;
F_12 ( V_41 , V_71 ) ;
F_31 ( V_71 , V_41 ) ;
F_4 ( V_41 -> V_25 , V_71 -> V_49 . V_48 -> V_25 , sizeof( V_41 -> V_25 ) ) ;
}
struct V_40 * F_32 ( struct V_52 * V_53 ,
struct V_73 * V_74 , struct V_75 * V_56 )
{
struct V_40 * V_41 = NULL ;
struct V_70 * V_71 = NULL ;
F_16 ( ! V_53 ) ;
if ( V_56 -> V_76 [ 0 ] )
F_17 ( V_56 -> V_76 ) ;
V_71 = F_33 ( V_74 , V_56 ) ;
if ( V_71 == NULL || V_71 -> V_49 . V_48 == NULL )
goto error;
if ( ! F_20 ( V_71 -> V_49 . V_48 -> V_47 ) )
goto error;
V_41 = F_34 ( V_71 ) ;
if ( F_22 ( V_53 , V_41 ) )
V_41 = NULL ;
F_23 ( V_71 -> V_49 . V_48 -> V_47 ) ;
error:
if ( V_71 && V_41 == NULL )
F_35 ( V_71 ) ;
return V_41 ;
}
static unsigned int F_36 ( unsigned int V_77 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_78 )
{
unsigned int V_79 = ~ ( ( 1 << V_78 ) - 1 ) ;
if ( V_78 )
V_77 = ( V_77 + ( 1 << ( V_78 - 1 ) ) ) & V_79 ;
if ( V_77 < V_21 )
V_77 = ( V_21 + ~ V_79 ) & V_79 ;
else if ( V_77 > V_22 )
V_77 = V_22 & V_79 ;
return V_77 ;
}
void F_37 ( T_2 * V_80 , unsigned int V_81 , unsigned int V_82 ,
unsigned int V_83 ,
T_2 * V_84 , unsigned int V_85 , unsigned int V_86 ,
unsigned int V_87 , unsigned int V_88 )
{
* V_80 = F_36 ( * V_80 , V_81 , V_82 , V_83 ) ;
* V_84 = F_36 ( * V_84 , V_85 , V_86 , V_87 ) ;
if ( ! V_88 )
return;
V_83 = F_38 ( * V_80 ) ;
V_87 = F_38 ( * V_84 ) ;
if ( V_83 + V_87 < V_88 ) {
unsigned int V_89 = F_39 ( V_82 ^ ( V_81 - 1 ) ) ;
unsigned int V_90 = F_39 ( V_86 ^ ( V_85 - 1 ) ) ;
do {
if ( V_87 >= V_90 ||
( V_83 <= V_87 && V_83 < V_89 ) ) {
* V_80 = F_36 ( * V_80 , V_81 , V_82 , V_83 + 1 ) ;
V_83 = F_38 ( * V_80 ) ;
} else {
* V_84 = F_36 ( * V_84 , V_85 , V_86 , V_87 + 1 ) ;
V_87 = F_38 ( * V_84 ) ;
}
} while ( V_87 + V_83 < V_88 );
}
}
const struct V_91 * F_40 (
const struct V_92 * V_93 ,
T_1 V_94 , T_1 V_95 )
{
int V_31 ;
T_2 error , V_96 = V_97 ;
const struct V_91 * V_98 , * V_99 = NULL ;
if ( ! V_93 )
return V_99 ;
for ( V_31 = 0 , V_98 = V_93 -> V_100 ; V_31 < V_93 -> V_101 ; V_31 ++ , V_98 ++ ) {
error = abs ( V_98 -> V_94 - V_94 ) + abs ( V_98 -> V_95 - V_95 ) ;
if ( error < V_96 ) {
V_96 = error ;
V_99 = V_98 ;
}
if ( ! error )
break;
}
return V_99 ;
}
void F_41 ( struct V_102 * V_103 )
{
struct V_104 V_105 ;
F_42 ( & V_105 ) ;
V_103 -> V_106 = V_105 . V_106 ;
V_103 -> V_107 = V_105 . V_108 / V_109 ;
}
