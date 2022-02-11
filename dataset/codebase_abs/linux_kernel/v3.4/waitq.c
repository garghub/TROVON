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
static void F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int type )
{
union {
struct V_36 V_37 ;
union V_38 V_39 ;
union V_40 V_41 ;
} V_42 ;
struct V_17 * V_15 = NULL ;
T_3 V_43 ;
F_4 ( L_2 ,
( unsigned long ) V_4 -> V_44 , V_4 -> V_12 . V_45 , V_4 -> V_12 . V_12 , type ) ;
memset ( & V_42 , 0 , sizeof V_42 ) ;
V_42 . V_37 . V_46 = V_2 -> V_47 ;
V_42 . V_37 . type = type ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 ) {
F_3 ( & V_2 -> V_6 ) ;
return;
}
switch ( type ) {
case V_48 :
{
struct V_49 * V_50 = & V_42 . V_39 . V_51 ;
V_43 = sizeof( * V_50 ) ;
V_50 -> V_44 = V_4 -> V_44 ;
V_50 -> V_45 = V_4 -> V_12 . V_45 ;
memcpy ( V_50 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_45 ) ;
V_50 -> V_12 [ V_4 -> V_12 . V_45 ] = '\0' ;
break;
}
case V_52 :
{
struct V_53 * V_54 = & V_42 . V_39 . V_55 ;
V_43 = sizeof( * V_54 ) ;
V_54 -> V_44 = V_4 -> V_44 ;
V_54 -> V_45 = V_4 -> V_12 . V_45 ;
memcpy ( V_54 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_45 ) ;
V_54 -> V_12 [ V_4 -> V_12 . V_45 ] = '\0' ;
break;
}
case V_56 :
case V_57 :
case V_58 :
case V_59 :
{
struct V_60 * V_61 = & V_42 . V_41 . V_62 ;
V_43 = sizeof( * V_61 ) ;
V_61 -> V_44 = V_4 -> V_44 ;
V_61 -> V_45 = V_4 -> V_12 . V_45 ;
memcpy ( V_61 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_45 ) ;
V_61 -> V_12 [ V_4 -> V_12 . V_45 ] = '\0' ;
V_61 -> V_63 = V_4 -> V_63 ;
V_61 -> V_64 = V_4 -> V_64 ;
V_61 -> V_65 = V_4 -> V_65 ;
V_61 -> V_66 = V_4 -> V_66 ;
V_61 -> V_67 = V_4 -> V_67 ;
V_61 -> V_68 = V_4 -> V_68 ;
break;
}
default:
F_17 ( L_3 , type ) ;
F_3 ( & V_2 -> V_6 ) ;
return;
}
V_15 = V_2 -> V_15 ;
F_18 ( V_15 ) ;
F_3 ( & V_2 -> V_6 ) ;
if ( F_8 ( V_2 , V_15 , & V_42 , V_43 ) )
F_1 ( V_2 ) ;
F_7 ( V_15 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_69 * V_69 , char * * V_12 )
{
struct V_69 * V_70 = V_2 -> V_71 -> V_72 ;
struct V_69 * V_73 ;
char * V_74 ;
char * V_75 ;
int V_45 ;
unsigned V_76 ;
V_77:
V_74 = * V_12 ;
V_45 = 0 ;
V_76 = F_20 ( & V_78 ) ;
F_21 () ;
F_22 ( & V_2 -> V_79 ) ;
for ( V_73 = V_69 ; V_73 != V_70 ; V_73 = V_73 -> V_80 )
V_45 += V_73 -> V_81 . V_45 + 1 ;
if ( ! V_45 || -- V_45 > V_82 ) {
F_23 ( & V_2 -> V_79 ) ;
F_24 () ;
if ( F_25 ( & V_78 , V_76 ) )
goto V_77;
return 0 ;
}
* ( V_74 + V_45 ) = '\0' ;
V_75 = V_74 + V_45 - V_69 -> V_81 . V_45 ;
strncpy ( V_75 , V_69 -> V_81 . V_12 , V_69 -> V_81 . V_45 ) ;
for ( V_73 = V_69 -> V_80 ; V_73 != V_70 ; V_73 = V_73 -> V_80 ) {
* ( -- V_75 ) = '/' ;
V_75 -= V_73 -> V_81 . V_45 ;
strncpy ( V_75 , V_73 -> V_81 . V_12 , V_73 -> V_81 . V_45 ) ;
}
F_23 ( & V_2 -> V_79 ) ;
F_24 () ;
if ( F_25 ( & V_78 , V_76 ) )
goto V_77;
return V_45 ;
}
static struct V_3 *
F_26 ( struct V_1 * V_2 , struct V_83 * V_83 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_8 ; V_4 ; V_4 = V_4 -> V_9 ) {
if ( V_4 -> V_12 . V_84 == V_83 -> V_84 &&
V_4 -> V_12 . V_45 == V_83 -> V_45 &&
V_4 -> V_12 . V_12 &&
! memcmp ( V_4 -> V_12 . V_12 , V_83 -> V_12 , V_83 -> V_45 ) )
break;
}
return V_4 ;
}
static int F_27 ( struct V_3 * * V_85 ,
struct V_1 * V_2 ,
struct V_83 * V_83 ,
struct V_69 * V_69 , enum V_86 V_87 )
{
struct V_3 * V_4 ;
struct V_88 * V_64 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_4 = F_26 ( V_2 , V_83 ) ;
if ( V_4 ) {
* V_85 = V_4 ;
return 1 ;
}
* V_85 = NULL ;
V_64 = F_28 ( V_69 ) ;
if ( ! V_64 )
return 1 ;
if ( V_87 == V_89 ) {
while ( V_64 -> V_21 & V_90 ) {
F_3 ( & V_2 -> V_6 ) ;
F_29 ( V_91 / 10 ) ;
if ( F_30 ( & V_2 -> V_6 ) )
return - V_92 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_4 = F_26 ( V_2 , V_83 ) ;
if ( V_4 ) {
* V_85 = V_4 ;
return 1 ;
}
}
return 0 ;
}
if ( V_87 == V_93 ) {
struct V_69 * V_94 = NULL ;
int V_95 = 1 ;
if ( ! F_31 ( V_69 ) ) {
if ( V_69 -> V_96 && F_32 ( V_69 ) ) {
struct V_69 * V_97 = V_69 -> V_80 ;
V_94 = F_33 ( V_97 , & V_69 -> V_81 ) ;
if ( V_94 )
V_69 = V_94 ;
}
}
if ( F_34 ( V_69 ) )
V_95 = 0 ;
if ( V_94 )
F_35 ( V_94 ) ;
return V_95 ;
}
return 1 ;
}
int F_36 ( struct V_1 * V_2 , struct V_69 * V_69 ,
enum V_86 V_87 )
{
struct V_3 * V_4 ;
struct V_83 V_83 ;
char * V_12 ;
int V_10 , V_98 , type ;
if ( V_2 -> V_7 )
return - V_11 ;
if ( ! V_69 -> V_96 ) {
if ( F_37 ( V_2 -> type ) )
return - V_11 ;
else if ( ! F_31 ( V_69 -> V_80 ) )
return - V_11 ;
}
V_12 = F_38 ( V_82 + 1 , V_99 ) ;
if ( ! V_12 )
return - V_100 ;
if ( F_31 ( V_69 ) && F_37 ( V_2 -> type ) )
V_83 . V_45 = sprintf ( V_12 , L_4 , V_69 ) ;
else {
V_83 . V_45 = F_19 ( V_2 , V_69 , & V_12 ) ;
if ( ! V_83 . V_45 ) {
F_5 ( V_12 ) ;
return - V_11 ;
}
}
V_83 . V_12 = V_12 ;
V_83 . V_84 = F_39 ( V_12 , V_83 . V_45 ) ;
if ( F_30 ( & V_2 -> V_6 ) ) {
F_5 ( V_83 . V_12 ) ;
return - V_92 ;
}
V_98 = F_27 ( & V_4 , V_2 , & V_83 , V_69 , V_87 ) ;
if ( V_98 <= 0 ) {
if ( V_98 != - V_92 )
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_83 . V_12 ) ;
return V_98 ;
}
if ( ! V_4 ) {
V_4 = F_38 ( sizeof( struct V_3 ) , V_99 ) ;
if ( ! V_4 ) {
F_5 ( V_83 . V_12 ) ;
F_3 ( & V_2 -> V_6 ) ;
return - V_100 ;
}
V_4 -> V_44 = V_101 ;
if ( ++ V_101 == 0 )
V_101 = 1 ;
V_4 -> V_9 = V_2 -> V_8 ;
V_2 -> V_8 = V_4 ;
F_40 ( & V_4 -> V_14 ) ;
memcpy ( & V_4 -> V_12 , & V_83 , sizeof( struct V_83 ) ) ;
V_4 -> V_63 = F_41 ( V_2 ) ;
V_4 -> V_64 = F_42 ( V_2 ) ;
V_4 -> V_65 = F_43 () ;
V_4 -> V_66 = F_44 () ;
V_4 -> V_67 = V_25 -> V_67 ;
V_4 -> V_68 = V_25 -> V_68 ;
V_4 -> V_10 = - V_92 ;
V_4 -> V_13 = 2 ;
F_3 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_47 < 5 ) {
if ( V_87 == V_93 )
type = V_48 ;
else
type = V_52 ;
} else {
if ( V_87 == V_93 )
type = F_37 ( V_2 -> type ) ?
V_58 :
V_56 ;
else
type = F_37 ( V_2 -> type ) ?
V_59 :
V_57 ;
}
F_4 ( L_5 ,
( unsigned long ) V_4 -> V_44 , V_4 -> V_12 . V_45 ,
V_4 -> V_12 . V_12 , V_87 ) ;
F_16 ( V_2 , V_4 , type ) ;
} else {
V_4 -> V_13 ++ ;
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_83 . V_12 ) ;
F_4 ( L_6 ,
( unsigned long ) V_4 -> V_44 , V_4 -> V_12 . V_45 ,
V_4 -> V_12 . V_12 , V_87 ) ;
}
if ( V_4 -> V_12 . V_12 ) {
T_4 V_102 ;
unsigned long V_103 ;
F_12 ( & V_25 -> V_34 -> V_35 , V_103 ) ;
V_102 = V_25 -> V_104 ;
F_45 ( & V_25 -> V_104 , V_105 & ~ V_102 . V_106 [ 0 ] ) ;
F_14 () ;
F_15 ( & V_25 -> V_34 -> V_35 , V_103 ) ;
F_46 ( V_4 -> V_14 , V_4 -> V_12 . V_12 == NULL ) ;
F_12 ( & V_25 -> V_34 -> V_35 , V_103 ) ;
V_25 -> V_104 = V_102 ;
F_14 () ;
F_15 ( & V_25 -> V_34 -> V_35 , V_103 ) ;
} else {
F_4 ( L_7 ) ;
}
V_10 = V_4 -> V_10 ;
if ( ! V_10 ) {
struct V_88 * V_64 ;
struct V_69 * V_107 = NULL ;
V_64 = F_28 ( V_69 ) ;
if ( ! V_64 ) {
V_107 = F_33 ( V_69 -> V_80 , & V_69 -> V_81 ) ;
if ( V_107 )
V_64 = F_28 ( V_107 ) ;
}
if ( V_64 ) {
F_22 ( & V_2 -> V_79 ) ;
V_64 -> V_65 = V_4 -> V_65 ;
V_64 -> V_66 = V_4 -> V_66 ;
F_23 ( & V_2 -> V_79 ) ;
}
if ( V_107 )
F_35 ( V_107 ) ;
}
F_2 ( & V_2 -> V_6 ) ;
if ( ! -- V_4 -> V_13 )
F_5 ( V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_10 ;
}
int F_47 ( struct V_1 * V_2 , T_5 V_44 , int V_10 )
{
struct V_3 * V_4 , * * V_108 ;
F_2 ( & V_2 -> V_6 ) ;
for ( V_108 = & V_2 -> V_8 ; ( V_4 = * V_108 ) != NULL ; V_108 = & V_4 -> V_9 ) {
if ( V_4 -> V_44 == V_44 )
break;
}
if ( ! V_4 ) {
F_3 ( & V_2 -> V_6 ) ;
return - V_109 ;
}
* V_108 = V_4 -> V_9 ;
F_5 ( V_4 -> V_12 . V_12 ) ;
V_4 -> V_12 . V_12 = NULL ;
V_4 -> V_10 = V_10 ;
F_6 ( & V_4 -> V_14 ) ;
if ( ! -- V_4 -> V_13 )
F_5 ( V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return 0 ;
}
