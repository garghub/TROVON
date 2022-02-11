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
static int F_8 ( struct V_17 * V_17 , const void * V_18 , int V_19 )
{
unsigned long V_20 , V_21 ;
T_1 V_22 ;
const char * V_23 = ( const char * ) V_18 ;
T_2 V_24 = 0 ;
V_20 = F_9 ( & V_25 -> V_26 . signal , V_27 ) ;
V_22 = F_10 () ;
F_11 ( V_28 ) ;
while ( V_19 &&
( V_24 = V_17 -> V_29 -> V_30 ( V_17 , V_23 , V_19 , & V_17 -> V_31 ) ) > 0 ) {
V_23 += V_24 ;
V_19 -= V_24 ;
}
F_11 ( V_22 ) ;
if ( V_24 == - V_32 && ! V_20 ) {
F_12 ( & V_25 -> V_33 -> V_34 , V_21 ) ;
F_13 ( & V_25 -> V_26 . signal , V_27 ) ;
F_14 () ;
F_15 ( & V_25 -> V_33 -> V_34 , V_21 ) ;
}
return ( V_19 > 0 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int type )
{
union {
struct V_35 V_36 ;
union V_37 V_38 ;
union V_39 V_40 ;
} V_41 ;
struct V_17 * V_15 = NULL ;
T_3 V_42 ;
F_4 ( L_2 ,
V_4 -> V_43 , V_4 -> V_12 . V_44 , V_4 -> V_12 . V_12 , type ) ;
memset ( & V_41 , 0 , sizeof V_41 ) ;
V_41 . V_36 . V_45 = V_2 -> V_46 ;
V_41 . V_36 . type = type ;
switch ( type ) {
case V_47 :
{
struct V_48 * V_49 = & V_41 . V_38 . V_50 ;
V_42 = sizeof( * V_49 ) ;
V_49 -> V_43 = V_4 -> V_43 ;
V_49 -> V_44 = V_4 -> V_12 . V_44 ;
memcpy ( V_49 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_44 ) ;
V_49 -> V_12 [ V_4 -> V_12 . V_44 ] = '\0' ;
break;
}
case V_51 :
{
struct V_52 * V_53 = & V_41 . V_38 . V_54 ;
V_42 = sizeof( * V_53 ) ;
V_53 -> V_43 = V_4 -> V_43 ;
V_53 -> V_44 = V_4 -> V_12 . V_44 ;
memcpy ( V_53 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_44 ) ;
V_53 -> V_12 [ V_4 -> V_12 . V_44 ] = '\0' ;
break;
}
case V_55 :
case V_56 :
case V_57 :
case V_58 :
{
struct V_59 * V_60 = & V_41 . V_40 . V_61 ;
V_42 = sizeof( * V_60 ) ;
V_60 -> V_43 = V_4 -> V_43 ;
V_60 -> V_44 = V_4 -> V_12 . V_44 ;
memcpy ( V_60 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_44 ) ;
V_60 -> V_12 [ V_4 -> V_12 . V_44 ] = '\0' ;
V_60 -> V_62 = V_4 -> V_62 ;
V_60 -> V_63 = V_4 -> V_63 ;
V_60 -> V_64 = V_4 -> V_64 ;
V_60 -> V_65 = V_4 -> V_65 ;
V_60 -> V_66 = V_4 -> V_66 ;
V_60 -> V_67 = V_4 -> V_67 ;
break;
}
default:
F_17 ( L_3 , type ) ;
return;
}
F_2 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_7 ) {
V_15 = V_2 -> V_15 ;
F_18 ( V_15 ) ;
}
F_3 ( & V_2 -> V_6 ) ;
if ( V_15 ) {
if ( F_8 ( V_15 , & V_41 , V_42 ) )
F_1 ( V_2 ) ;
F_7 ( V_15 ) ;
}
}
static int F_19 ( struct V_1 * V_2 ,
struct V_68 * V_68 , char * * V_12 )
{
struct V_68 * V_69 = V_2 -> V_70 -> V_71 ;
struct V_68 * V_72 ;
char * V_73 ;
char * V_74 ;
int V_44 ;
unsigned V_75 ;
V_76:
V_73 = * V_12 ;
V_44 = 0 ;
V_75 = F_20 ( & V_77 ) ;
F_21 () ;
F_22 ( & V_2 -> V_78 ) ;
for ( V_72 = V_68 ; V_72 != V_69 ; V_72 = V_72 -> V_79 )
V_44 += V_72 -> V_80 . V_44 + 1 ;
if ( ! V_44 || -- V_44 > V_81 ) {
F_23 ( & V_2 -> V_78 ) ;
F_24 () ;
if ( F_25 ( & V_77 , V_75 ) )
goto V_76;
return 0 ;
}
* ( V_73 + V_44 ) = '\0' ;
V_74 = V_73 + V_44 - V_68 -> V_80 . V_44 ;
strncpy ( V_74 , V_68 -> V_80 . V_12 , V_68 -> V_80 . V_44 ) ;
for ( V_72 = V_68 -> V_79 ; V_72 != V_69 ; V_72 = V_72 -> V_79 ) {
* ( -- V_74 ) = '/' ;
V_74 -= V_72 -> V_80 . V_44 ;
strncpy ( V_74 , V_72 -> V_80 . V_12 , V_72 -> V_80 . V_44 ) ;
}
F_23 ( & V_2 -> V_78 ) ;
F_24 () ;
if ( F_25 ( & V_77 , V_75 ) )
goto V_76;
return V_44 ;
}
static struct V_3 *
F_26 ( struct V_1 * V_2 , struct V_82 * V_82 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_8 ; V_4 ; V_4 = V_4 -> V_9 ) {
if ( V_4 -> V_12 . V_83 == V_82 -> V_83 &&
V_4 -> V_12 . V_44 == V_82 -> V_44 &&
V_4 -> V_12 . V_12 &&
! memcmp ( V_4 -> V_12 . V_12 , V_82 -> V_12 , V_82 -> V_44 ) )
break;
}
return V_4 ;
}
static int F_27 ( struct V_3 * * V_84 ,
struct V_1 * V_2 ,
struct V_82 * V_82 ,
struct V_68 * V_68 , enum V_85 V_86 )
{
struct V_3 * V_4 ;
struct V_87 * V_63 ;
V_4 = F_26 ( V_2 , V_82 ) ;
if ( V_4 ) {
* V_84 = V_4 ;
return 1 ;
}
* V_84 = NULL ;
V_63 = F_28 ( V_68 ) ;
if ( ! V_63 )
return 1 ;
if ( V_86 == V_88 ) {
while ( V_63 -> V_21 & V_89 ) {
F_3 ( & V_2 -> V_6 ) ;
F_29 ( V_90 / 10 ) ;
if ( F_30 ( & V_2 -> V_6 ) )
return - V_91 ;
V_4 = F_26 ( V_2 , V_82 ) ;
if ( V_4 ) {
* V_84 = V_4 ;
return 1 ;
}
}
return 0 ;
}
if ( V_86 == V_92 ) {
struct V_68 * V_93 = NULL ;
int V_94 = 1 ;
if ( ! F_31 ( V_68 ) ) {
if ( V_68 -> V_95 && F_32 ( V_68 ) ) {
struct V_68 * V_96 = V_68 -> V_79 ;
V_93 = F_33 ( V_96 , & V_68 -> V_80 ) ;
if ( V_93 )
V_68 = V_93 ;
}
}
if ( F_34 ( V_68 ) )
V_94 = 0 ;
if ( V_93 )
F_35 ( V_93 ) ;
return V_94 ;
}
return 1 ;
}
int F_36 ( struct V_1 * V_2 , struct V_68 * V_68 ,
enum V_85 V_86 )
{
struct V_3 * V_4 ;
struct V_82 V_82 ;
char * V_12 ;
int V_10 , V_97 , type ;
if ( V_2 -> V_7 )
return - V_11 ;
if ( ! V_68 -> V_95 ) {
if ( F_37 ( V_2 -> type ) )
return - V_11 ;
else if ( ! F_31 ( V_68 -> V_79 ) )
return - V_11 ;
}
V_12 = F_38 ( V_81 + 1 , V_98 ) ;
if ( ! V_12 )
return - V_99 ;
if ( F_31 ( V_68 ) && F_37 ( V_2 -> type ) )
V_82 . V_44 = sprintf ( V_12 , L_4 , V_68 ) ;
else {
V_82 . V_44 = F_19 ( V_2 , V_68 , & V_12 ) ;
if ( ! V_82 . V_44 ) {
F_5 ( V_12 ) ;
return - V_11 ;
}
}
V_82 . V_12 = V_12 ;
V_82 . V_83 = F_39 ( V_12 , V_82 . V_44 ) ;
if ( F_30 ( & V_2 -> V_6 ) ) {
F_5 ( V_82 . V_12 ) ;
return - V_91 ;
}
V_97 = F_27 ( & V_4 , V_2 , & V_82 , V_68 , V_86 ) ;
if ( V_97 <= 0 ) {
if ( V_97 == 0 )
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_82 . V_12 ) ;
return V_97 ;
}
if ( ! V_4 ) {
V_4 = F_38 ( sizeof( struct V_3 ) , V_98 ) ;
if ( ! V_4 ) {
F_5 ( V_82 . V_12 ) ;
F_3 ( & V_2 -> V_6 ) ;
return - V_99 ;
}
V_4 -> V_43 = V_100 ;
if ( ++ V_100 == 0 )
V_100 = 1 ;
V_4 -> V_9 = V_2 -> V_8 ;
V_2 -> V_8 = V_4 ;
F_40 ( & V_4 -> V_14 ) ;
memcpy ( & V_4 -> V_12 , & V_82 , sizeof( struct V_82 ) ) ;
V_4 -> V_62 = F_41 ( V_2 ) ;
V_4 -> V_63 = F_42 ( V_2 ) ;
V_4 -> V_64 = F_43 () ;
V_4 -> V_65 = F_44 () ;
V_4 -> V_66 = V_25 -> V_66 ;
V_4 -> V_67 = V_25 -> V_67 ;
V_4 -> V_10 = - V_91 ;
V_4 -> V_13 = 2 ;
F_3 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_46 < 5 ) {
if ( V_86 == V_92 )
type = V_47 ;
else
type = V_51 ;
} else {
if ( V_86 == V_92 )
type = F_37 ( V_2 -> type ) ?
V_57 :
V_55 ;
else
type = F_37 ( V_2 -> type ) ?
V_58 :
V_56 ;
}
F_4 ( L_5 ,
( unsigned long ) V_4 -> V_43 , V_4 -> V_12 . V_44 ,
V_4 -> V_12 . V_12 , V_86 ) ;
F_16 ( V_2 , V_4 , type ) ;
} else {
V_4 -> V_13 ++ ;
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_82 . V_12 ) ;
F_4 ( L_6 ,
( unsigned long ) V_4 -> V_43 , V_4 -> V_12 . V_44 ,
V_4 -> V_12 . V_12 , V_86 ) ;
}
if ( V_4 -> V_12 . V_12 ) {
T_4 V_101 ;
unsigned long V_102 ;
F_12 ( & V_25 -> V_33 -> V_34 , V_102 ) ;
V_101 = V_25 -> V_103 ;
F_45 ( & V_25 -> V_103 , V_104 & ~ V_101 . V_105 [ 0 ] ) ;
F_14 () ;
F_15 ( & V_25 -> V_33 -> V_34 , V_102 ) ;
F_46 ( V_4 -> V_14 , V_4 -> V_12 . V_12 == NULL ) ;
F_12 ( & V_25 -> V_33 -> V_34 , V_102 ) ;
V_25 -> V_103 = V_101 ;
F_14 () ;
F_15 ( & V_25 -> V_33 -> V_34 , V_102 ) ;
} else {
F_4 ( L_7 ) ;
}
V_10 = V_4 -> V_10 ;
if ( ! V_10 ) {
struct V_87 * V_63 ;
struct V_68 * V_106 = NULL ;
V_63 = F_28 ( V_68 ) ;
if ( ! V_63 ) {
V_106 = F_33 ( V_68 -> V_79 , & V_68 -> V_80 ) ;
if ( V_106 )
V_63 = F_28 ( V_106 ) ;
}
if ( V_63 ) {
F_22 ( & V_2 -> V_78 ) ;
V_63 -> V_64 = V_4 -> V_64 ;
V_63 -> V_65 = V_4 -> V_65 ;
F_23 ( & V_2 -> V_78 ) ;
}
if ( V_106 )
F_35 ( V_106 ) ;
}
F_2 ( & V_2 -> V_6 ) ;
if ( ! -- V_4 -> V_13 )
F_5 ( V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_10 ;
}
int F_47 ( struct V_1 * V_2 , T_5 V_43 , int V_10 )
{
struct V_3 * V_4 , * * V_107 ;
F_2 ( & V_2 -> V_6 ) ;
for ( V_107 = & V_2 -> V_8 ; ( V_4 = * V_107 ) != NULL ; V_107 = & V_4 -> V_9 ) {
if ( V_4 -> V_43 == V_43 )
break;
}
if ( ! V_4 ) {
F_3 ( & V_2 -> V_6 ) ;
return - V_108 ;
}
* V_107 = V_4 -> V_9 ;
F_5 ( V_4 -> V_12 . V_12 ) ;
V_4 -> V_12 . V_12 = NULL ;
V_4 -> V_10 = V_10 ;
F_6 ( & V_4 -> V_14 ) ;
if ( ! -- V_4 -> V_13 )
F_5 ( V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return 0 ;
}
