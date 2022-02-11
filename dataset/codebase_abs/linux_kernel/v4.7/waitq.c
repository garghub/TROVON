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
F_5 ( V_4 -> V_12 . V_12 ) ;
V_4 -> V_12 . V_12 = NULL ;
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
while ( V_19 ) {
V_24 = F_12 ( V_17 , V_23 , V_19 , & V_17 -> V_30 ) ;
if ( V_24 <= 0 )
break;
V_23 += V_24 ;
V_19 -= V_24 ;
}
F_3 ( & V_2 -> V_29 ) ;
F_11 ( V_22 ) ;
if ( V_24 == - V_31 && ! V_20 ) {
F_13 ( & V_25 -> V_32 -> V_33 , V_21 ) ;
F_14 ( & V_25 -> V_26 . signal , V_27 ) ;
F_15 () ;
F_16 ( & V_25 -> V_32 -> V_33 , V_21 ) ;
}
return ( V_19 > 0 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int type )
{
union {
struct V_34 V_35 ;
union V_36 V_37 ;
union V_38 V_39 ;
} V_40 ;
struct V_17 * V_15 = NULL ;
T_3 V_41 ;
F_4 ( L_2 ,
( unsigned long ) V_4 -> V_42 ,
V_4 -> V_12 . V_43 , V_4 -> V_12 . V_12 , type ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_35 . V_44 = V_2 -> V_45 ;
V_40 . V_35 . type = type ;
switch ( type ) {
case V_46 :
{
struct V_47 * V_48 = & V_40 . V_37 . V_49 ;
V_41 = sizeof( * V_48 ) ;
V_48 -> V_42 = V_4 -> V_42 ;
V_48 -> V_43 = V_4 -> V_12 . V_43 ;
memcpy ( V_48 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_43 ) ;
V_48 -> V_12 [ V_4 -> V_12 . V_43 ] = '\0' ;
break;
}
case V_50 :
{
struct V_51 * V_52 =
& V_40 . V_37 . V_53 ;
V_41 = sizeof( * V_52 ) ;
V_52 -> V_42 = V_4 -> V_42 ;
V_52 -> V_43 = V_4 -> V_12 . V_43 ;
memcpy ( V_52 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_43 ) ;
V_52 -> V_12 [ V_4 -> V_12 . V_43 ] = '\0' ;
break;
}
case V_54 :
case V_55 :
case V_56 :
case V_57 :
{
struct V_58 * V_59 = & V_40 . V_39 . V_60 ;
struct V_61 * V_62 = V_2 -> V_15 -> V_63 -> V_62 ;
V_41 = sizeof( * V_59 ) ;
V_59 -> V_42 = V_4 -> V_42 ;
V_59 -> V_43 = V_4 -> V_12 . V_43 ;
memcpy ( V_59 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_43 ) ;
V_59 -> V_12 [ V_4 -> V_12 . V_43 ] = '\0' ;
V_59 -> V_64 = V_4 -> V_64 ;
V_59 -> V_65 = V_4 -> V_65 ;
V_59 -> V_66 = F_18 ( V_62 , V_4 -> V_66 ) ;
V_59 -> V_67 = F_19 ( V_62 , V_4 -> V_67 ) ;
V_59 -> V_68 = V_4 -> V_68 ;
V_59 -> V_69 = V_4 -> V_69 ;
break;
}
default:
F_20 ( L_3 , type ) ;
F_3 ( & V_2 -> V_6 ) ;
return;
}
V_15 = F_21 ( V_2 -> V_15 ) ;
F_3 ( & V_2 -> V_6 ) ;
if ( F_8 ( V_2 , V_15 , & V_40 , V_41 ) )
F_1 ( V_2 ) ;
F_7 ( V_15 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_70 * V_70 , char * * V_12 )
{
struct V_70 * V_71 = V_2 -> V_72 -> V_73 ;
struct V_70 * V_74 ;
char * V_75 ;
char * V_76 ;
int V_43 ;
unsigned V_77 ;
V_78:
V_75 = * V_12 ;
V_43 = 0 ;
V_77 = F_23 ( & V_79 ) ;
F_24 () ;
F_25 ( & V_2 -> V_80 ) ;
for ( V_74 = V_70 ; V_74 != V_71 ; V_74 = V_74 -> V_81 )
V_43 += V_74 -> V_82 . V_43 + 1 ;
if ( ! V_43 || -- V_43 > V_83 ) {
F_26 ( & V_2 -> V_80 ) ;
F_27 () ;
if ( F_28 ( & V_79 , V_77 ) )
goto V_78;
return 0 ;
}
* ( V_75 + V_43 ) = '\0' ;
V_76 = V_75 + V_43 - V_70 -> V_82 . V_43 ;
strncpy ( V_76 , V_70 -> V_82 . V_12 , V_70 -> V_82 . V_43 ) ;
for ( V_74 = V_70 -> V_81 ; V_74 != V_71 ; V_74 = V_74 -> V_81 ) {
* ( -- V_76 ) = '/' ;
V_76 -= V_74 -> V_82 . V_43 ;
strncpy ( V_76 , V_74 -> V_82 . V_12 , V_74 -> V_82 . V_43 ) ;
}
F_26 ( & V_2 -> V_80 ) ;
F_27 () ;
if ( F_28 ( & V_79 , V_77 ) )
goto V_78;
return V_43 ;
}
static struct V_3 *
F_29 ( struct V_1 * V_2 , struct V_84 * V_84 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_8 ; V_4 ; V_4 = V_4 -> V_9 ) {
if ( V_4 -> V_12 . V_85 == V_84 -> V_85 &&
V_4 -> V_12 . V_43 == V_84 -> V_43 &&
V_4 -> V_12 . V_12 &&
! memcmp ( V_4 -> V_12 . V_12 , V_84 -> V_12 , V_84 -> V_43 ) )
break;
}
return V_4 ;
}
static int F_30 ( struct V_3 * * V_86 ,
struct V_1 * V_2 ,
struct V_84 * V_84 ,
struct V_70 * V_70 , enum V_87 V_88 )
{
struct V_3 * V_4 ;
struct V_89 * V_65 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_4 = F_29 ( V_2 , V_84 ) ;
if ( V_4 ) {
* V_86 = V_4 ;
return 1 ;
}
* V_86 = NULL ;
V_65 = F_31 ( V_70 ) ;
if ( ! V_65 )
return 1 ;
if ( V_88 == V_90 ) {
while ( V_65 -> V_21 & V_91 ) {
F_3 ( & V_2 -> V_6 ) ;
F_32 ( V_92 / 10 ) ;
if ( F_33 ( & V_2 -> V_6 ) )
return - V_93 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_4 = F_29 ( V_2 , V_84 ) ;
if ( V_4 ) {
* V_86 = V_4 ;
return 1 ;
}
}
return 0 ;
}
if ( V_88 == V_94 ) {
struct V_70 * V_95 = NULL ;
int V_96 = 1 ;
if ( ! F_34 ( V_70 ) ) {
if ( F_35 ( V_70 ) &&
F_36 ( V_70 ) ) {
struct V_70 * V_97 = V_70 -> V_81 ;
V_95 = F_37 ( V_97 , & V_70 -> V_82 ) ;
if ( V_95 )
V_70 = V_95 ;
}
}
if ( F_38 ( V_70 ) )
V_96 = 0 ;
if ( V_95 )
F_39 ( V_95 ) ;
return V_96 ;
}
return 1 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_70 * V_70 , enum V_87 V_88 )
{
struct V_3 * V_4 ;
struct V_84 V_84 ;
char * V_12 ;
int V_10 , V_98 , type ;
T_4 V_68 ;
T_4 V_69 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_68 = F_41 ( V_25 , F_42 ( V_2 -> V_99 ) ) ;
V_69 = F_43 ( V_25 , F_42 ( V_2 -> V_99 ) ) ;
if ( V_68 == 0 || V_69 == 0 )
return - V_11 ;
if ( F_44 ( V_70 ) ) {
if ( F_45 ( V_2 -> type ) )
return - V_11 ;
else if ( ! F_34 ( V_70 -> V_81 ) )
return - V_11 ;
}
V_12 = F_46 ( V_83 + 1 , V_100 ) ;
if ( ! V_12 )
return - V_101 ;
if ( F_34 ( V_70 ) && F_45 ( V_2 -> type ) )
V_84 . V_43 = sprintf ( V_12 , L_4 , V_70 ) ;
else {
V_84 . V_43 = F_22 ( V_2 , V_70 , & V_12 ) ;
if ( ! V_84 . V_43 ) {
F_5 ( V_12 ) ;
return - V_11 ;
}
}
V_84 . V_12 = V_12 ;
V_84 . V_85 = F_47 ( V_12 , V_84 . V_43 ) ;
if ( F_33 ( & V_2 -> V_6 ) ) {
F_5 ( V_84 . V_12 ) ;
return - V_93 ;
}
V_98 = F_30 ( & V_4 , V_2 , & V_84 , V_70 , V_88 ) ;
if ( V_98 <= 0 ) {
if ( V_98 != - V_93 )
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_84 . V_12 ) ;
return V_98 ;
}
if ( ! V_4 ) {
V_4 = F_46 ( sizeof( struct V_3 ) , V_100 ) ;
if ( ! V_4 ) {
F_5 ( V_84 . V_12 ) ;
F_3 ( & V_2 -> V_6 ) ;
return - V_101 ;
}
V_4 -> V_42 = V_102 ;
if ( ++ V_102 == 0 )
V_102 = 1 ;
V_4 -> V_9 = V_2 -> V_8 ;
V_2 -> V_8 = V_4 ;
F_48 ( & V_4 -> V_14 ) ;
memcpy ( & V_4 -> V_12 , & V_84 , sizeof( struct V_84 ) ) ;
V_4 -> V_64 = F_49 ( V_2 ) ;
V_4 -> V_65 = F_50 ( V_2 ) ;
V_4 -> V_66 = F_51 () ;
V_4 -> V_67 = F_52 () ;
V_4 -> V_68 = V_68 ;
V_4 -> V_69 = V_69 ;
V_4 -> V_10 = - V_93 ;
V_4 -> V_13 = 2 ;
if ( V_2 -> V_45 < 5 ) {
if ( V_88 == V_94 )
type = V_46 ;
else
type = V_50 ;
} else {
if ( V_88 == V_94 )
type = F_45 ( V_2 -> type ) ?
V_56 :
V_54 ;
else
type = F_45 ( V_2 -> type ) ?
V_57 :
V_55 ;
}
F_4 ( L_5 ,
( unsigned long ) V_4 -> V_42 , V_4 -> V_12 . V_43 ,
V_4 -> V_12 . V_12 , V_88 ) ;
F_17 ( V_2 , V_4 , type ) ;
} else {
V_4 -> V_13 ++ ;
F_4 ( L_6 ,
( unsigned long ) V_4 -> V_42 , V_4 -> V_12 . V_43 ,
V_4 -> V_12 . V_12 , V_88 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_84 . V_12 ) ;
}
if ( V_4 -> V_12 . V_12 ) {
unsigned long V_103 ;
unsigned long V_104 ;
T_5 V_105 ;
F_13 ( & V_25 -> V_32 -> V_33 , V_104 ) ;
V_105 = V_25 -> V_106 ;
V_103 = V_107 & ~ V_105 . V_108 [ 0 ] ;
F_53 ( & V_25 -> V_106 , V_103 ) ;
F_15 () ;
F_16 ( & V_25 -> V_32 -> V_33 , V_104 ) ;
F_54 ( V_4 -> V_14 , V_4 -> V_12 . V_12 == NULL ) ;
F_13 ( & V_25 -> V_32 -> V_33 , V_104 ) ;
V_25 -> V_106 = V_105 ;
F_15 () ;
F_16 ( & V_25 -> V_32 -> V_33 , V_104 ) ;
} else {
F_4 ( L_7 ) ;
}
V_10 = V_4 -> V_10 ;
if ( ! V_10 ) {
struct V_89 * V_65 ;
struct V_70 * V_109 = NULL ;
V_65 = F_31 ( V_70 ) ;
if ( ! V_65 ) {
V_109 = F_37 ( V_70 -> V_81 , & V_70 -> V_82 ) ;
if ( V_109 )
V_65 = F_31 ( V_109 ) ;
}
if ( V_65 ) {
F_25 ( & V_2 -> V_80 ) ;
V_65 -> V_66 = V_4 -> V_66 ;
V_65 -> V_67 = V_4 -> V_67 ;
F_26 ( & V_2 -> V_80 ) ;
}
if ( V_109 )
F_39 ( V_109 ) ;
}
F_2 ( & V_2 -> V_6 ) ;
if ( ! -- V_4 -> V_13 )
F_5 ( V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_10 ;
}
int F_55 ( struct V_1 * V_2 , T_6 V_42 , int V_10 )
{
struct V_3 * V_4 , * * V_110 ;
F_2 ( & V_2 -> V_6 ) ;
for ( V_110 = & V_2 -> V_8 ; ( V_4 = * V_110 ) != NULL ; V_110 = & V_4 -> V_9 ) {
if ( V_4 -> V_42 == V_42 )
break;
}
if ( ! V_4 ) {
F_3 ( & V_2 -> V_6 ) ;
return - V_111 ;
}
* V_110 = V_4 -> V_9 ;
F_5 ( V_4 -> V_12 . V_12 ) ;
V_4 -> V_12 . V_12 = NULL ;
V_4 -> V_10 = V_10 ;
F_6 ( & V_4 -> V_14 ) ;
if ( ! -- V_4 -> V_13 )
F_5 ( V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return 0 ;
}
