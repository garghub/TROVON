void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 ) {
F_3 ( & V_2 -> V_6 ) ;
return;
}
F_4 ( L_1 ) ;
V_2 -> V_7 = 1 ;
V_4 = V_2 -> V_8 ;
V_2 -> V_8 = NULL ;
while ( V_4 ) {
V_5 = V_4 -> V_9 ;
V_4 -> V_10 = - V_11 ;
if ( V_4 -> V_12 . V_12 ) {
F_5 ( V_4 -> V_12 . V_12 ) ;
V_4 -> V_12 . V_12 = NULL ;
}
V_4 -> V_13 -- ;
F_6 ( & V_4 -> V_14 ) ;
V_4 = V_5 ;
}
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_16 = - 1 ;
F_3 ( & V_2 -> V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_17 * V_17 , const void * V_18 , int V_19 )
{
unsigned long V_20 , V_21 ;
T_1 V_22 ;
const char * V_23 = ( const char * ) V_18 ;
T_2 V_24 = 0 ;
V_20 = F_9 ( & V_25 -> V_26 . signal , V_27 ) ;
V_22 = F_10 () ;
F_11 ( V_28 ) ;
F_2 ( & V_2 -> V_29 ) ;
while ( V_19 &&
( V_24 = V_17 -> V_30 -> V_31 ( V_17 , V_23 , V_19 , & V_17 -> V_32 ) ) > 0 ) {
V_23 += V_24 ;
V_19 -= V_24 ;
}
F_3 ( & V_2 -> V_29 ) ;
F_11 ( V_22 ) ;
if ( V_24 == - V_33 && ! V_20 ) {
F_12 ( & V_25 -> V_34 -> V_35 , V_21 ) ;
F_13 ( & V_25 -> V_26 . signal , V_27 ) ;
F_14 () ;
F_15 ( & V_25 -> V_34 -> V_35 , V_21 ) ;
}
return ( V_19 > 0 ) ;
}
static T_3 T_4 F_16 ( struct V_1 * V_2 )
{
T_4 V_36 = sizeof( struct V_37 ) ;
#if F_17 ( V_38 ) && F_17 ( V_39 )
if ( V_2 -> V_40 > 0 )
V_36 -= 4 ;
#endif
return V_36 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int type )
{
union {
struct V_41 V_42 ;
union V_43 V_44 ;
union V_45 V_46 ;
} V_47 ;
struct V_17 * V_15 = NULL ;
T_4 V_36 ;
F_4 ( L_2 ,
( unsigned long ) V_4 -> V_48 , V_4 -> V_12 . V_49 , V_4 -> V_12 . V_12 , type ) ;
memset ( & V_47 , 0 , sizeof V_47 ) ;
V_47 . V_42 . V_50 = V_2 -> V_51 ;
V_47 . V_42 . type = type ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 ) {
F_3 ( & V_2 -> V_6 ) ;
return;
}
switch ( type ) {
case V_52 :
{
struct V_53 * V_54 = & V_47 . V_44 . V_55 ;
V_36 = sizeof( * V_54 ) ;
V_54 -> V_48 = V_4 -> V_48 ;
V_54 -> V_49 = V_4 -> V_12 . V_49 ;
memcpy ( V_54 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_49 ) ;
V_54 -> V_12 [ V_4 -> V_12 . V_49 ] = '\0' ;
break;
}
case V_56 :
{
struct V_57 * V_58 = & V_47 . V_44 . V_59 ;
V_36 = sizeof( * V_58 ) ;
V_58 -> V_48 = V_4 -> V_48 ;
V_58 -> V_49 = V_4 -> V_12 . V_49 ;
memcpy ( V_58 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_49 ) ;
V_58 -> V_12 [ V_4 -> V_12 . V_49 ] = '\0' ;
break;
}
case V_60 :
case V_61 :
case V_62 :
case V_63 :
{
struct V_37 * V_64 = & V_47 . V_46 . V_65 ;
V_36 = F_16 ( V_2 ) ;
V_64 -> V_48 = V_4 -> V_48 ;
V_64 -> V_49 = V_4 -> V_12 . V_49 ;
memcpy ( V_64 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_49 ) ;
V_64 -> V_12 [ V_4 -> V_12 . V_49 ] = '\0' ;
V_64 -> V_66 = V_4 -> V_66 ;
V_64 -> V_67 = V_4 -> V_67 ;
V_64 -> V_68 = V_4 -> V_68 ;
V_64 -> V_69 = V_4 -> V_69 ;
V_64 -> V_70 = V_4 -> V_70 ;
V_64 -> V_71 = V_4 -> V_71 ;
break;
}
default:
F_19 ( L_3 , type ) ;
F_3 ( & V_2 -> V_6 ) ;
return;
}
V_15 = V_2 -> V_15 ;
F_20 ( V_15 ) ;
F_3 ( & V_2 -> V_6 ) ;
if ( F_8 ( V_2 , V_15 , & V_47 , V_36 ) )
F_1 ( V_2 ) ;
F_7 ( V_15 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_72 * V_72 , char * * V_12 )
{
struct V_72 * V_73 = V_2 -> V_74 -> V_75 ;
struct V_72 * V_76 ;
char * V_77 ;
char * V_78 ;
int V_49 ;
unsigned V_79 ;
V_80:
V_77 = * V_12 ;
V_49 = 0 ;
V_79 = F_22 ( & V_81 ) ;
F_23 () ;
F_24 ( & V_2 -> V_82 ) ;
for ( V_76 = V_72 ; V_76 != V_73 ; V_76 = V_76 -> V_83 )
V_49 += V_76 -> V_84 . V_49 + 1 ;
if ( ! V_49 || -- V_49 > V_85 ) {
F_25 ( & V_2 -> V_82 ) ;
F_26 () ;
if ( F_27 ( & V_81 , V_79 ) )
goto V_80;
return 0 ;
}
* ( V_77 + V_49 ) = '\0' ;
V_78 = V_77 + V_49 - V_72 -> V_84 . V_49 ;
strncpy ( V_78 , V_72 -> V_84 . V_12 , V_72 -> V_84 . V_49 ) ;
for ( V_76 = V_72 -> V_83 ; V_76 != V_73 ; V_76 = V_76 -> V_83 ) {
* ( -- V_78 ) = '/' ;
V_78 -= V_76 -> V_84 . V_49 ;
strncpy ( V_78 , V_76 -> V_84 . V_12 , V_76 -> V_84 . V_49 ) ;
}
F_25 ( & V_2 -> V_82 ) ;
F_26 () ;
if ( F_27 ( & V_81 , V_79 ) )
goto V_80;
return V_49 ;
}
static struct V_3 *
F_28 ( struct V_1 * V_2 , struct V_86 * V_86 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_8 ; V_4 ; V_4 = V_4 -> V_9 ) {
if ( V_4 -> V_12 . V_87 == V_86 -> V_87 &&
V_4 -> V_12 . V_49 == V_86 -> V_49 &&
V_4 -> V_12 . V_12 &&
! memcmp ( V_4 -> V_12 . V_12 , V_86 -> V_12 , V_86 -> V_49 ) )
break;
}
return V_4 ;
}
static int F_29 ( struct V_3 * * V_88 ,
struct V_1 * V_2 ,
struct V_86 * V_86 ,
struct V_72 * V_72 , enum V_89 V_90 )
{
struct V_3 * V_4 ;
struct V_91 * V_67 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_4 = F_28 ( V_2 , V_86 ) ;
if ( V_4 ) {
* V_88 = V_4 ;
return 1 ;
}
* V_88 = NULL ;
V_67 = F_30 ( V_72 ) ;
if ( ! V_67 )
return 1 ;
if ( V_90 == V_92 ) {
while ( V_67 -> V_21 & V_93 ) {
F_3 ( & V_2 -> V_6 ) ;
F_31 ( V_94 / 10 ) ;
if ( F_32 ( & V_2 -> V_6 ) )
return - V_95 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_4 = F_28 ( V_2 , V_86 ) ;
if ( V_4 ) {
* V_88 = V_4 ;
return 1 ;
}
}
return 0 ;
}
if ( V_90 == V_96 ) {
struct V_72 * V_97 = NULL ;
int V_98 = 1 ;
if ( ! F_33 ( V_72 ) ) {
if ( V_72 -> V_99 && F_34 ( V_72 ) ) {
struct V_72 * V_100 = V_72 -> V_83 ;
V_97 = F_35 ( V_100 , & V_72 -> V_84 ) ;
if ( V_97 )
V_72 = V_97 ;
}
}
if ( F_36 ( V_72 ) )
V_98 = 0 ;
if ( V_97 )
F_37 ( V_97 ) ;
return V_98 ;
}
return 1 ;
}
int F_38 ( struct V_1 * V_2 , struct V_72 * V_72 ,
enum V_89 V_90 )
{
struct V_3 * V_4 ;
struct V_86 V_86 ;
char * V_12 ;
int V_10 , V_101 , type ;
if ( V_2 -> V_7 )
return - V_11 ;
if ( ! V_72 -> V_99 ) {
if ( F_39 ( V_2 -> type ) )
return - V_11 ;
else if ( ! F_33 ( V_72 -> V_83 ) )
return - V_11 ;
}
V_12 = F_40 ( V_85 + 1 , V_102 ) ;
if ( ! V_12 )
return - V_103 ;
if ( F_33 ( V_72 ) && F_39 ( V_2 -> type ) )
V_86 . V_49 = sprintf ( V_12 , L_4 , V_72 ) ;
else {
V_86 . V_49 = F_21 ( V_2 , V_72 , & V_12 ) ;
if ( ! V_86 . V_49 ) {
F_5 ( V_12 ) ;
return - V_11 ;
}
}
V_86 . V_12 = V_12 ;
V_86 . V_87 = F_41 ( V_12 , V_86 . V_49 ) ;
if ( F_32 ( & V_2 -> V_6 ) ) {
F_5 ( V_86 . V_12 ) ;
return - V_95 ;
}
V_101 = F_29 ( & V_4 , V_2 , & V_86 , V_72 , V_90 ) ;
if ( V_101 <= 0 ) {
if ( V_101 != - V_95 )
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_86 . V_12 ) ;
return V_101 ;
}
if ( ! V_4 ) {
V_4 = F_40 ( sizeof( struct V_3 ) , V_102 ) ;
if ( ! V_4 ) {
F_5 ( V_86 . V_12 ) ;
F_3 ( & V_2 -> V_6 ) ;
return - V_103 ;
}
V_4 -> V_48 = V_104 ;
if ( ++ V_104 == 0 )
V_104 = 1 ;
V_4 -> V_9 = V_2 -> V_8 ;
V_2 -> V_8 = V_4 ;
F_42 ( & V_4 -> V_14 ) ;
memcpy ( & V_4 -> V_12 , & V_86 , sizeof( struct V_86 ) ) ;
V_4 -> V_66 = F_43 ( V_2 ) ;
V_4 -> V_67 = F_44 ( V_2 ) ;
V_4 -> V_68 = F_45 () ;
V_4 -> V_69 = F_46 () ;
V_4 -> V_70 = V_25 -> V_70 ;
V_4 -> V_71 = V_25 -> V_71 ;
V_4 -> V_10 = - V_95 ;
V_4 -> V_13 = 2 ;
F_3 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_51 < 5 ) {
if ( V_90 == V_96 )
type = V_52 ;
else
type = V_56 ;
} else {
if ( V_90 == V_96 )
type = F_39 ( V_2 -> type ) ?
V_62 :
V_60 ;
else
type = F_39 ( V_2 -> type ) ?
V_63 :
V_61 ;
}
F_4 ( L_5 ,
( unsigned long ) V_4 -> V_48 , V_4 -> V_12 . V_49 ,
V_4 -> V_12 . V_12 , V_90 ) ;
F_18 ( V_2 , V_4 , type ) ;
} else {
V_4 -> V_13 ++ ;
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_86 . V_12 ) ;
F_4 ( L_6 ,
( unsigned long ) V_4 -> V_48 , V_4 -> V_12 . V_49 ,
V_4 -> V_12 . V_12 , V_90 ) ;
}
if ( V_4 -> V_12 . V_12 ) {
T_5 V_105 ;
unsigned long V_106 ;
F_12 ( & V_25 -> V_34 -> V_35 , V_106 ) ;
V_105 = V_25 -> V_107 ;
F_47 ( & V_25 -> V_107 , V_108 & ~ V_105 . V_109 [ 0 ] ) ;
F_14 () ;
F_15 ( & V_25 -> V_34 -> V_35 , V_106 ) ;
F_48 ( V_4 -> V_14 , V_4 -> V_12 . V_12 == NULL ) ;
F_12 ( & V_25 -> V_34 -> V_35 , V_106 ) ;
V_25 -> V_107 = V_105 ;
F_14 () ;
F_15 ( & V_25 -> V_34 -> V_35 , V_106 ) ;
} else {
F_4 ( L_7 ) ;
}
V_10 = V_4 -> V_10 ;
if ( ! V_10 ) {
struct V_91 * V_67 ;
struct V_72 * V_110 = NULL ;
V_67 = F_30 ( V_72 ) ;
if ( ! V_67 ) {
V_110 = F_35 ( V_72 -> V_83 , & V_72 -> V_84 ) ;
if ( V_110 )
V_67 = F_30 ( V_110 ) ;
}
if ( V_67 ) {
F_24 ( & V_2 -> V_82 ) ;
V_67 -> V_68 = V_4 -> V_68 ;
V_67 -> V_69 = V_4 -> V_69 ;
F_25 ( & V_2 -> V_82 ) ;
}
if ( V_110 )
F_37 ( V_110 ) ;
}
F_2 ( & V_2 -> V_6 ) ;
if ( ! -- V_4 -> V_13 )
F_5 ( V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_10 ;
}
int F_49 ( struct V_1 * V_2 , T_6 V_48 , int V_10 )
{
struct V_3 * V_4 , * * V_111 ;
F_2 ( & V_2 -> V_6 ) ;
for ( V_111 = & V_2 -> V_8 ; ( V_4 = * V_111 ) != NULL ; V_111 = & V_4 -> V_9 ) {
if ( V_4 -> V_48 == V_48 )
break;
}
if ( ! V_4 ) {
F_3 ( & V_2 -> V_6 ) ;
return - V_112 ;
}
* V_111 = V_4 -> V_9 ;
F_5 ( V_4 -> V_12 . V_12 ) ;
V_4 -> V_12 . V_12 = NULL ;
V_4 -> V_10 = V_10 ;
F_6 ( & V_4 -> V_14 ) ;
if ( ! -- V_4 -> V_13 )
F_5 ( V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return 0 ;
}
