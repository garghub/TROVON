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
const char * V_22 = ( const char * ) V_18 ;
T_1 V_23 = 0 ;
V_20 = F_9 ( & V_24 -> V_25 . signal , V_26 ) ;
F_2 ( & V_2 -> V_27 ) ;
while ( V_19 ) {
V_23 = F_10 ( V_17 , V_22 , V_19 , & V_17 -> V_28 ) ;
if ( V_23 <= 0 )
break;
V_22 += V_23 ;
V_19 -= V_23 ;
}
F_3 ( & V_2 -> V_27 ) ;
if ( V_23 == - V_29 && ! V_20 ) {
F_11 ( & V_24 -> V_30 -> V_31 , V_21 ) ;
F_12 ( & V_24 -> V_25 . signal , V_26 ) ;
F_13 () ;
F_14 ( & V_24 -> V_30 -> V_31 , V_21 ) ;
}
return ( V_19 > 0 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int type )
{
union {
struct V_32 V_33 ;
union V_34 V_35 ;
union V_36 V_37 ;
} V_38 ;
struct V_17 * V_15 = NULL ;
T_2 V_39 ;
F_4 ( L_2 ,
( unsigned long ) V_4 -> V_40 ,
V_4 -> V_12 . V_41 , V_4 -> V_12 . V_12 , type ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_33 . V_42 = V_2 -> V_43 ;
V_38 . V_33 . type = type ;
switch ( type ) {
case V_44 :
{
struct V_45 * V_46 = & V_38 . V_35 . V_47 ;
V_39 = sizeof( * V_46 ) ;
V_46 -> V_40 = V_4 -> V_40 ;
V_46 -> V_41 = V_4 -> V_12 . V_41 ;
memcpy ( V_46 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_41 ) ;
V_46 -> V_12 [ V_4 -> V_12 . V_41 ] = '\0' ;
break;
}
case V_48 :
{
struct V_49 * V_50 =
& V_38 . V_35 . V_51 ;
V_39 = sizeof( * V_50 ) ;
V_50 -> V_40 = V_4 -> V_40 ;
V_50 -> V_41 = V_4 -> V_12 . V_41 ;
memcpy ( V_50 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_41 ) ;
V_50 -> V_12 [ V_4 -> V_12 . V_41 ] = '\0' ;
break;
}
case V_52 :
case V_53 :
case V_54 :
case V_55 :
{
struct V_56 * V_57 = & V_38 . V_37 . V_58 ;
struct V_59 * V_60 = V_2 -> V_15 -> V_61 -> V_60 ;
V_39 = sizeof( * V_57 ) ;
V_57 -> V_40 = V_4 -> V_40 ;
V_57 -> V_41 = V_4 -> V_12 . V_41 ;
memcpy ( V_57 -> V_12 , V_4 -> V_12 . V_12 , V_4 -> V_12 . V_41 ) ;
V_57 -> V_12 [ V_4 -> V_12 . V_41 ] = '\0' ;
V_57 -> V_62 = V_4 -> V_62 ;
V_57 -> V_63 = V_4 -> V_63 ;
V_57 -> V_64 = F_16 ( V_60 , V_4 -> V_64 ) ;
V_57 -> V_65 = F_17 ( V_60 , V_4 -> V_65 ) ;
V_57 -> V_66 = V_4 -> V_66 ;
V_57 -> V_67 = V_4 -> V_67 ;
break;
}
default:
F_18 ( L_3 , type ) ;
F_3 ( & V_2 -> V_6 ) ;
return;
}
V_15 = F_19 ( V_2 -> V_15 ) ;
F_3 ( & V_2 -> V_6 ) ;
if ( F_8 ( V_2 , V_15 , & V_38 , V_39 ) )
F_1 ( V_2 ) ;
F_7 ( V_15 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_68 * V_68 , char * * V_12 )
{
struct V_68 * V_69 = V_2 -> V_70 -> V_71 ;
struct V_68 * V_72 ;
char * V_73 ;
char * V_74 ;
int V_41 ;
unsigned V_75 ;
V_76:
V_73 = * V_12 ;
V_41 = 0 ;
V_75 = F_21 ( & V_77 ) ;
F_22 () ;
F_23 ( & V_2 -> V_78 ) ;
for ( V_72 = V_68 ; V_72 != V_69 ; V_72 = V_72 -> V_79 )
V_41 += V_72 -> V_80 . V_41 + 1 ;
if ( ! V_41 || -- V_41 > V_81 ) {
F_24 ( & V_2 -> V_78 ) ;
F_25 () ;
if ( F_26 ( & V_77 , V_75 ) )
goto V_76;
return 0 ;
}
* ( V_73 + V_41 ) = '\0' ;
V_74 = V_73 + V_41 - V_68 -> V_80 . V_41 ;
strncpy ( V_74 , V_68 -> V_80 . V_12 , V_68 -> V_80 . V_41 ) ;
for ( V_72 = V_68 -> V_79 ; V_72 != V_69 ; V_72 = V_72 -> V_79 ) {
* ( -- V_74 ) = '/' ;
V_74 -= V_72 -> V_80 . V_41 ;
strncpy ( V_74 , V_72 -> V_80 . V_12 , V_72 -> V_80 . V_41 ) ;
}
F_24 ( & V_2 -> V_78 ) ;
F_25 () ;
if ( F_26 ( & V_77 , V_75 ) )
goto V_76;
return V_41 ;
}
static struct V_3 *
F_27 ( struct V_1 * V_2 , const struct V_82 * V_82 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_8 ; V_4 ; V_4 = V_4 -> V_9 ) {
if ( V_4 -> V_12 . V_83 == V_82 -> V_83 &&
V_4 -> V_12 . V_41 == V_82 -> V_41 &&
V_4 -> V_12 . V_12 &&
! memcmp ( V_4 -> V_12 . V_12 , V_82 -> V_12 , V_82 -> V_41 ) )
break;
}
return V_4 ;
}
static int F_28 ( struct V_3 * * V_84 ,
struct V_1 * V_2 ,
const struct V_82 * V_82 ,
const struct V_85 * V_85 , enum V_86 V_87 )
{
struct V_68 * V_68 = V_85 -> V_68 ;
struct V_3 * V_4 ;
struct V_88 * V_63 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_4 = F_27 ( V_2 , V_82 ) ;
if ( V_4 ) {
* V_84 = V_4 ;
return 1 ;
}
* V_84 = NULL ;
V_63 = F_29 ( V_68 ) ;
if ( ! V_63 )
return 1 ;
if ( V_87 == V_89 ) {
while ( V_63 -> V_21 & V_90 ) {
F_3 ( & V_2 -> V_6 ) ;
F_30 ( V_91 / 10 ) ;
if ( F_31 ( & V_2 -> V_6 ) )
return - V_92 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_4 = F_27 ( V_2 , V_82 ) ;
if ( V_4 ) {
* V_84 = V_4 ;
return 1 ;
}
}
return 0 ;
}
if ( V_87 == V_93 ) {
struct V_68 * V_94 = NULL ;
struct V_85 V_95 ;
int V_96 = 1 ;
if ( ! F_32 ( V_68 ) ) {
if ( F_33 ( V_68 ) &&
F_34 ( V_68 ) ) {
struct V_68 * V_97 = V_68 -> V_79 ;
V_94 = F_35 ( V_97 , & V_68 -> V_80 ) ;
if ( V_94 )
V_68 = V_94 ;
}
}
V_95 . V_98 = V_85 -> V_98 ;
V_95 . V_68 = V_68 ;
if ( F_36 ( & V_95 ) )
V_96 = 0 ;
if ( V_94 )
F_37 ( V_94 ) ;
return V_96 ;
}
return 1 ;
}
int F_38 ( struct V_1 * V_2 ,
const struct V_85 * V_85 , enum V_86 V_87 )
{
struct V_68 * V_68 = V_85 -> V_68 ;
struct V_3 * V_4 ;
struct V_82 V_82 ;
char * V_12 ;
int V_10 , V_99 , type ;
T_3 V_66 ;
T_3 V_67 ;
if ( V_2 -> V_7 )
return - V_11 ;
V_66 = F_39 ( V_24 , F_40 ( V_2 -> V_100 ) ) ;
V_67 = F_41 ( V_24 , F_40 ( V_2 -> V_100 ) ) ;
if ( V_66 == 0 || V_67 == 0 )
return - V_11 ;
if ( F_42 ( V_68 ) ) {
if ( F_43 ( V_2 -> type ) )
return - V_11 ;
else if ( ! F_32 ( V_68 -> V_79 ) )
return - V_11 ;
}
V_12 = F_44 ( V_81 + 1 , V_101 ) ;
if ( ! V_12 )
return - V_102 ;
if ( F_32 ( V_68 ) && F_43 ( V_2 -> type ) )
V_82 . V_41 = sprintf ( V_12 , L_4 , V_68 ) ;
else {
V_82 . V_41 = F_20 ( V_2 , V_68 , & V_12 ) ;
if ( ! V_82 . V_41 ) {
F_5 ( V_12 ) ;
return - V_11 ;
}
}
V_82 . V_12 = V_12 ;
V_82 . V_83 = F_45 ( V_68 , V_12 , V_82 . V_41 ) ;
if ( F_31 ( & V_2 -> V_6 ) ) {
F_5 ( V_82 . V_12 ) ;
return - V_92 ;
}
V_99 = F_28 ( & V_4 , V_2 , & V_82 , V_85 , V_87 ) ;
if ( V_99 <= 0 ) {
if ( V_99 != - V_92 )
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_82 . V_12 ) ;
return V_99 ;
}
if ( ! V_4 ) {
V_4 = F_44 ( sizeof( struct V_3 ) , V_101 ) ;
if ( ! V_4 ) {
F_5 ( V_82 . V_12 ) ;
F_3 ( & V_2 -> V_6 ) ;
return - V_102 ;
}
V_4 -> V_40 = V_103 ;
if ( ++ V_103 == 0 )
V_103 = 1 ;
V_4 -> V_9 = V_2 -> V_8 ;
V_2 -> V_8 = V_4 ;
F_46 ( & V_4 -> V_14 ) ;
memcpy ( & V_4 -> V_12 , & V_82 , sizeof( struct V_82 ) ) ;
V_4 -> V_62 = F_47 ( V_2 ) ;
V_4 -> V_63 = F_48 ( V_2 ) ;
V_4 -> V_64 = F_49 () -> V_64 ;
V_4 -> V_65 = F_49 () -> V_65 ;
V_4 -> V_66 = V_66 ;
V_4 -> V_67 = V_67 ;
V_4 -> V_10 = - V_92 ;
V_4 -> V_13 = 2 ;
if ( V_2 -> V_43 < 5 ) {
if ( V_87 == V_93 )
type = V_44 ;
else
type = V_48 ;
} else {
if ( V_87 == V_93 )
type = F_43 ( V_2 -> type ) ?
V_54 :
V_52 ;
else
type = F_43 ( V_2 -> type ) ?
V_55 :
V_53 ;
}
F_4 ( L_5 ,
( unsigned long ) V_4 -> V_40 , V_4 -> V_12 . V_41 ,
V_4 -> V_12 . V_12 , V_87 ) ;
F_15 ( V_2 , V_4 , type ) ;
} else {
V_4 -> V_13 ++ ;
F_4 ( L_6 ,
( unsigned long ) V_4 -> V_40 , V_4 -> V_12 . V_41 ,
V_4 -> V_12 . V_12 , V_87 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_5 ( V_82 . V_12 ) ;
}
if ( V_4 -> V_12 . V_12 ) {
unsigned long V_104 ;
unsigned long V_105 ;
T_4 V_106 ;
F_11 ( & V_24 -> V_30 -> V_31 , V_105 ) ;
V_106 = V_24 -> V_107 ;
V_104 = V_108 & ~ V_106 . V_109 [ 0 ] ;
F_50 ( & V_24 -> V_107 , V_104 ) ;
F_13 () ;
F_14 ( & V_24 -> V_30 -> V_31 , V_105 ) ;
F_51 ( V_4 -> V_14 , V_4 -> V_12 . V_12 == NULL ) ;
F_11 ( & V_24 -> V_30 -> V_31 , V_105 ) ;
V_24 -> V_107 = V_106 ;
F_13 () ;
F_14 ( & V_24 -> V_30 -> V_31 , V_105 ) ;
} else {
F_4 ( L_7 ) ;
}
V_10 = V_4 -> V_10 ;
if ( ! V_10 ) {
struct V_88 * V_63 ;
struct V_68 * V_110 = NULL ;
V_63 = F_29 ( V_68 ) ;
if ( ! V_63 ) {
V_110 = F_35 ( V_68 -> V_79 , & V_68 -> V_80 ) ;
if ( V_110 )
V_63 = F_29 ( V_110 ) ;
}
if ( V_63 ) {
F_23 ( & V_2 -> V_78 ) ;
V_63 -> V_64 = V_4 -> V_64 ;
V_63 -> V_65 = V_4 -> V_65 ;
F_24 ( & V_2 -> V_78 ) ;
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
int F_52 ( struct V_1 * V_2 , T_5 V_40 , int V_10 )
{
struct V_3 * V_4 , * * V_111 ;
F_2 ( & V_2 -> V_6 ) ;
for ( V_111 = & V_2 -> V_8 ; ( V_4 = * V_111 ) != NULL ; V_111 = & V_4 -> V_9 ) {
if ( V_4 -> V_40 == V_40 )
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
