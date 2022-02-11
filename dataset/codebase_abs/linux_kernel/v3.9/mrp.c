static void F_1 ( void * V_1 , T_1 V_2 )
{
T_1 * V_3 = ( T_1 * ) V_1 ;
while ( V_2 > 0 && ! ++ V_3 [ -- V_2 ] )
;
}
static int F_2 ( const struct V_4 * V_5 ,
const void * V_1 , T_1 V_2 , T_1 type )
{
if ( V_5 -> type != type )
return V_5 -> type - type ;
if ( V_5 -> V_2 != V_2 )
return V_5 -> V_2 - V_2 ;
return memcmp ( V_5 -> V_1 , V_1 , V_2 ) ;
}
static struct V_4 * F_3 ( const struct V_6 * V_7 ,
const void * V_1 , T_1 V_2 , T_1 type )
{
struct V_8 * V_9 = V_7 -> V_10 . V_8 ;
struct V_4 * V_5 ;
int V_11 ;
while ( V_9 ) {
V_5 = F_4 ( V_9 , struct V_4 , V_12 ) ;
V_11 = F_2 ( V_5 , V_1 , V_2 , type ) ;
if ( V_11 > 0 )
V_9 = V_9 -> V_13 ;
else if ( V_11 < 0 )
V_9 = V_9 -> V_14 ;
else
return V_5 ;
}
return NULL ;
}
static struct V_4 * F_5 ( struct V_6 * V_7 ,
const void * V_1 , T_1 V_2 , T_1 type )
{
struct V_8 * V_9 = NULL , * * V_15 = & V_7 -> V_10 . V_8 ;
struct V_4 * V_5 ;
int V_11 ;
while ( * V_15 ) {
V_9 = * V_15 ;
V_5 = F_4 ( V_9 , struct V_4 , V_12 ) ;
V_11 = F_2 ( V_5 , V_1 , V_2 , type ) ;
if ( V_11 > 0 )
V_15 = & V_9 -> V_13 ;
else if ( V_11 < 0 )
V_15 = & V_9 -> V_14 ;
else {
return V_5 ;
}
}
V_5 = F_6 ( sizeof( * V_5 ) + V_2 , V_16 ) ;
if ( ! V_5 )
return V_5 ;
V_5 -> V_17 = V_18 ;
V_5 -> type = type ;
V_5 -> V_2 = V_2 ;
memcpy ( V_5 -> V_1 , V_1 , V_2 ) ;
F_7 ( & V_5 -> V_12 , V_9 , V_15 ) ;
F_8 ( & V_5 -> V_12 , & V_7 -> V_10 ) ;
return V_5 ;
}
static void F_9 ( struct V_6 * V_7 , struct V_4 * V_5 )
{
F_10 ( & V_5 -> V_12 , & V_7 -> V_10 ) ;
F_11 ( V_5 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_20 = F_13 ( V_7 -> V_23 -> V_24 + F_14 ( V_7 -> V_23 ) ,
V_16 ) ;
if ( ! V_20 )
return - V_25 ;
V_20 -> V_23 = V_7 -> V_23 ;
V_20 -> V_26 = V_7 -> V_7 -> V_27 . type ;
F_15 ( V_20 , F_14 ( V_7 -> V_23 ) ) ;
F_16 ( V_20 ) ;
F_17 ( V_20 ) ;
V_22 = (struct V_21 * ) F_18 ( V_20 , sizeof( * V_22 ) ) ;
V_22 -> V_28 = V_7 -> V_7 -> V_28 ;
V_7 -> V_29 = V_20 ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
T_2 * V_30 ;
if ( F_20 ( V_7 -> V_29 ) < sizeof( * V_30 ) )
return - 1 ;
V_30 = ( T_2 * ) F_18 ( V_7 -> V_29 , sizeof( * V_30 ) ) ;
F_21 ( V_31 , V_30 ) ;
return 0 ;
}
static void F_22 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_29 )
return;
if ( F_23 ( V_7 -> V_29 ) -> V_32 )
F_19 ( V_7 ) ;
F_19 ( V_7 ) ;
F_24 ( V_7 -> V_29 , V_7 -> V_23 , F_25 ( V_7 -> V_7 -> V_27 . type ) ,
V_7 -> V_7 -> V_33 , V_7 -> V_23 -> V_34 ,
V_7 -> V_29 -> V_2 ) ;
F_26 ( & V_7 -> V_35 , V_7 -> V_29 ) ;
V_7 -> V_29 = NULL ;
}
static void F_27 ( struct V_6 * V_7 )
{
struct V_19 * V_20 ;
while ( ( V_20 = F_28 ( & V_7 -> V_35 ) ) )
F_29 ( V_20 ) ;
}
static int F_30 ( struct V_6 * V_7 ,
T_1 V_36 , T_1 V_37 )
{
struct V_38 * V_32 ;
if ( F_23 ( V_7 -> V_29 ) -> V_32 ) {
if ( F_19 ( V_7 ) < 0 )
return - 1 ;
F_23 ( V_7 -> V_29 ) -> V_32 = NULL ;
F_23 ( V_7 -> V_29 ) -> V_39 = NULL ;
}
if ( F_20 ( V_7 -> V_29 ) < sizeof( * V_32 ) )
return - 1 ;
V_32 = (struct V_38 * ) F_18 ( V_7 -> V_29 , sizeof( * V_32 ) ) ;
V_32 -> V_36 = V_36 ;
V_32 -> V_37 = V_37 ;
F_23 ( V_7 -> V_29 ) -> V_32 = V_32 ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 ,
const void * V_40 , T_1 V_37 )
{
struct V_41 * V_39 ;
if ( F_20 ( V_7 -> V_29 ) < sizeof( * V_39 ) + V_37 )
return - 1 ;
V_39 = (struct V_41 * ) F_18 ( V_7 -> V_29 ,
sizeof( * V_39 ) + V_37 ) ;
F_21 ( 0 , & V_39 -> V_42 ) ;
memcpy ( V_39 -> V_40 , V_40 , V_37 ) ;
F_23 ( V_7 -> V_29 ) -> V_39 = V_39 ;
memcpy ( F_23 ( V_7 -> V_29 ) -> V_43 , V_40 , V_37 ) ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 ,
const struct V_4 * V_5 ,
enum V_44 V_45 )
{
T_3 V_2 , V_46 ;
T_1 * V_47 ;
int V_48 ;
V_49:
if ( ! V_7 -> V_29 ) {
V_48 = F_12 ( V_7 ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( ! F_23 ( V_7 -> V_29 ) -> V_32 ||
F_23 ( V_7 -> V_29 ) -> V_32 -> V_36 != V_5 -> type ||
F_23 ( V_7 -> V_29 ) -> V_32 -> V_37 != V_5 -> V_2 ) {
if ( F_30 ( V_7 , V_5 -> type , V_5 -> V_2 ) < 0 )
goto V_35;
}
if ( ! F_23 ( V_7 -> V_29 ) -> V_39 ||
memcmp ( F_23 ( V_7 -> V_29 ) -> V_43 , V_5 -> V_1 , V_5 -> V_2 ) ) {
if ( F_31 ( V_7 , V_5 -> V_1 , V_5 -> V_2 ) < 0 )
goto V_35;
}
V_2 = F_33 ( F_34 ( & F_23 ( V_7 -> V_29 ) -> V_39 -> V_42 ) ) ;
V_46 = V_2 % 3 ;
if ( ! V_46 ) {
if ( F_20 ( V_7 -> V_29 ) < sizeof( T_1 ) )
goto V_35;
V_47 = ( T_1 * ) F_18 ( V_7 -> V_29 , sizeof( T_1 ) ) ;
} else {
V_47 = ( T_1 * ) ( F_35 ( V_7 -> V_29 ) - sizeof( T_1 ) ) ;
}
switch ( V_46 ) {
case 0 :
* V_47 = V_45 * ( V_50 *
V_50 ) ;
break;
case 1 :
* V_47 += V_45 * V_50 ;
break;
case 2 :
* V_47 += V_45 ;
break;
default:
F_36 ( 1 ) ;
}
F_21 ( F_37 ( ++ V_2 ) , & F_23 ( V_7 -> V_29 ) -> V_39 -> V_42 ) ;
F_1 ( F_23 ( V_7 -> V_29 ) -> V_43 , V_5 -> V_2 ) ;
return 0 ;
V_35:
F_22 ( V_7 ) ;
goto V_49;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_4 * V_5 , enum V_51 V_52 )
{
enum V_53 V_17 ;
V_17 = V_54 [ V_5 -> V_17 ] [ V_52 ] ;
if ( V_17 == V_55 ) {
F_36 ( 1 ) ;
return;
}
if ( V_52 == V_56 ) {
switch ( V_57 [ V_5 -> V_17 ] ) {
case V_58 :
case V_59 :
case V_60 :
break;
case V_61 :
if ( F_32 (
V_7 , V_5 , V_62 ) < 0 )
return;
break;
case V_63 :
if ( F_32 (
V_7 , V_5 , V_64 ) < 0 )
return;
break;
case V_65 :
if ( F_32 (
V_7 , V_5 , V_66 ) < 0 )
return;
F_9 ( V_7 , V_5 ) ;
return;
default:
F_36 ( 1 ) ;
}
}
V_5 -> V_17 = V_17 ;
}
int F_39 ( const struct V_67 * V_23 ,
const struct V_68 * V_69 ,
const void * V_1 , T_1 V_2 , T_1 type )
{
struct V_70 * V_71 = F_40 ( V_23 -> V_70 ) ;
struct V_6 * V_7 = F_40 (
V_71 -> V_72 [ V_69 -> type ] ) ;
struct V_4 * V_5 ;
if ( sizeof( struct V_73 ) + V_2 >
F_41 ( struct V_19 , V_74 ) )
return - V_25 ;
F_42 ( & V_7 -> V_75 ) ;
V_5 = F_5 ( V_7 , V_1 , V_2 , type ) ;
if ( ! V_5 ) {
F_43 ( & V_7 -> V_75 ) ;
return - V_25 ;
}
F_38 ( V_7 , V_5 , V_76 ) ;
F_43 ( & V_7 -> V_75 ) ;
return 0 ;
}
void F_44 ( const struct V_67 * V_23 ,
const struct V_68 * V_69 ,
const void * V_1 , T_1 V_2 , T_1 type )
{
struct V_70 * V_71 = F_40 ( V_23 -> V_70 ) ;
struct V_6 * V_7 = F_40 (
V_71 -> V_72 [ V_69 -> type ] ) ;
struct V_4 * V_5 ;
if ( sizeof( struct V_73 ) + V_2 >
F_41 ( struct V_19 , V_74 ) )
return;
F_42 ( & V_7 -> V_75 ) ;
V_5 = F_3 ( V_7 , V_1 , V_2 , type ) ;
if ( ! V_5 ) {
F_43 ( & V_7 -> V_75 ) ;
return;
}
F_38 ( V_7 , V_5 , V_77 ) ;
F_43 ( & V_7 -> V_75 ) ;
}
static void F_45 ( struct V_6 * V_7 , enum V_51 V_52 )
{
struct V_8 * V_12 , * V_78 ;
struct V_4 * V_5 ;
for ( V_12 = F_46 ( & V_7 -> V_10 ) ;
V_78 = V_12 ? F_47 ( V_12 ) : NULL , V_12 != NULL ;
V_12 = V_78 ) {
V_5 = F_4 ( V_12 , struct V_4 , V_12 ) ;
F_38 ( V_7 , V_5 , V_52 ) ;
}
}
static void F_48 ( struct V_6 * V_7 )
{
unsigned long V_79 ;
V_79 = ( V_80 ) F_49 ( V_81 ) * F_50 () >> 32 ;
F_51 ( & V_7 -> V_82 , V_83 + V_79 ) ;
}
static void F_52 ( unsigned long V_84 )
{
struct V_6 * V_7 = (struct V_6 * ) V_84 ;
F_53 ( & V_7 -> V_75 ) ;
F_45 ( V_7 , V_56 ) ;
F_22 ( V_7 ) ;
F_54 ( & V_7 -> V_75 ) ;
F_27 ( V_7 ) ;
F_48 ( V_7 ) ;
}
static int F_55 ( struct V_19 * V_20 , int * V_85 )
{
T_2 V_30 ;
if ( F_56 ( V_20 , * V_85 , & V_30 , sizeof( V_30 ) ) < 0 )
return - 1 ;
if ( V_30 == V_31 ) {
* V_85 += sizeof( V_30 ) ;
return - 1 ;
}
return 0 ;
}
static void F_57 ( struct V_6 * V_7 ,
struct V_19 * V_20 ,
enum V_44 V_45 )
{
struct V_4 * V_5 ;
enum V_51 V_52 ;
V_5 = F_3 ( V_7 , F_23 ( V_20 ) -> V_43 ,
F_23 ( V_20 ) -> V_32 -> V_37 ,
F_23 ( V_20 ) -> V_32 -> V_36 ) ;
if ( V_5 == NULL )
return;
switch ( V_45 ) {
case V_62 :
V_52 = V_86 ;
break;
case V_64 :
V_52 = V_87 ;
break;
case V_88 :
V_52 = V_89 ;
break;
case V_90 :
V_52 = V_91 ;
break;
case V_92 :
V_52 = V_93 ;
break;
case V_66 :
V_52 = V_94 ;
break;
default:
return;
}
F_38 ( V_7 , V_5 , V_52 ) ;
}
static int F_58 ( struct V_6 * V_7 ,
struct V_19 * V_20 , int * V_85 )
{
struct V_41 V_95 ;
T_3 V_96 ;
T_1 V_47 , V_45 ;
F_23 ( V_20 ) -> V_39 = F_59 ( V_20 , * V_85 , sizeof( V_95 ) ,
& V_95 ) ;
if ( ! F_23 ( V_20 ) -> V_39 )
return - 1 ;
* V_85 += sizeof( V_95 ) ;
if ( F_34 ( & F_23 ( V_20 ) -> V_39 -> V_42 ) &
V_97 )
F_45 ( V_7 , V_98 ) ;
V_96 = F_33 ( F_34 ( & F_23 ( V_20 ) -> V_39 -> V_42 ) &
V_99 ) ;
if ( sizeof( struct V_73 ) + F_23 ( V_20 ) -> V_32 -> V_37 >
F_41 ( struct V_19 , V_74 ) )
return - 1 ;
if ( F_56 ( V_20 , * V_85 , F_23 ( V_20 ) -> V_43 ,
F_23 ( V_20 ) -> V_32 -> V_37 ) < 0 )
return - 1 ;
* V_85 += F_23 ( V_20 ) -> V_32 -> V_37 ;
while ( V_96 > 0 ) {
if ( F_56 ( V_20 , * V_85 , & V_47 ,
sizeof( V_47 ) ) < 0 )
return - 1 ;
* V_85 += sizeof( V_47 ) ;
V_45 = V_47 / ( V_50 *
V_50 ) ;
if ( V_45 >= V_50 ) {
return - 1 ;
}
F_57 ( V_7 , V_20 , V_45 ) ;
if ( ! -- V_96 )
break;
F_1 ( F_23 ( V_20 ) -> V_43 ,
F_23 ( V_20 ) -> V_32 -> V_37 ) ;
V_47 %= ( V_50 *
V_50 ) ;
V_45 = V_47 / V_50 ;
F_57 ( V_7 , V_20 , V_45 ) ;
if ( ! -- V_96 )
break;
F_1 ( F_23 ( V_20 ) -> V_43 ,
F_23 ( V_20 ) -> V_32 -> V_37 ) ;
V_47 %= V_50 ;
V_45 = V_47 ;
F_57 ( V_7 , V_20 , V_45 ) ;
}
return 0 ;
}
static int F_60 ( struct V_6 * V_7 , struct V_19 * V_20 ,
int * V_85 )
{
struct V_38 V_100 ;
F_23 ( V_20 ) -> V_32 = F_59 ( V_20 , * V_85 , sizeof( V_100 ) , & V_100 ) ;
if ( ! F_23 ( V_20 ) -> V_32 )
return - 1 ;
* V_85 += sizeof( V_100 ) ;
if ( F_23 ( V_20 ) -> V_32 -> V_36 == 0 ||
F_23 ( V_20 ) -> V_32 -> V_36 > V_7 -> V_7 -> V_101 ||
F_23 ( V_20 ) -> V_32 -> V_37 == 0 )
return - 1 ;
while ( V_20 -> V_2 > * V_85 ) {
if ( F_55 ( V_20 , V_85 ) < 0 )
break;
if ( F_58 ( V_7 , V_20 , V_85 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_61 ( struct V_19 * V_20 , struct V_67 * V_23 ,
struct V_102 * V_103 , struct V_67 * V_104 )
{
struct V_68 * V_69 = F_62 ( V_103 , struct V_68 ,
V_27 ) ;
struct V_70 * V_71 ;
struct V_6 * V_7 ;
struct V_21 V_105 ;
const struct V_21 * V_22 ;
int V_85 = F_63 ( V_20 ) ;
if ( F_64 ( V_20 -> V_106 == V_107 ) )
goto V_108;
V_20 = F_65 ( V_20 , V_16 ) ;
if ( F_64 ( ! V_20 ) )
goto V_108;
V_71 = F_66 ( V_23 -> V_70 ) ;
if ( F_64 ( ! V_71 ) )
goto V_108;
V_7 = F_66 ( V_71 -> V_72 [ V_69 -> type ] ) ;
if ( F_64 ( ! V_7 ) )
goto V_108;
V_22 = F_59 ( V_20 , V_85 , sizeof( V_105 ) , & V_105 ) ;
if ( ! V_22 )
goto V_108;
V_85 += sizeof( V_105 ) ;
if ( V_22 -> V_28 != V_7 -> V_7 -> V_28 )
goto V_108;
F_53 ( & V_7 -> V_75 ) ;
while ( V_20 -> V_2 > V_85 ) {
if ( F_55 ( V_20 , & V_85 ) < 0 )
break;
if ( F_60 ( V_7 , V_20 , & V_85 ) < 0 )
break;
}
F_54 ( & V_7 -> V_75 ) ;
V_108:
F_67 ( V_20 ) ;
return 0 ;
}
static int F_68 ( struct V_67 * V_23 )
{
struct V_70 * V_71 ;
V_71 = F_69 ( sizeof( * V_71 ) , V_109 ) ;
if ( ! V_71 )
return - V_25 ;
F_70 ( V_23 -> V_70 , V_71 ) ;
return 0 ;
}
static void F_71 ( struct V_67 * V_23 )
{
struct V_70 * V_71 = F_40 ( V_23 -> V_70 ) ;
unsigned int V_110 ;
for ( V_110 = 0 ; V_110 <= V_111 ; V_110 ++ ) {
if ( F_40 ( V_71 -> V_72 [ V_110 ] ) )
return;
}
F_72 ( V_23 -> V_70 , NULL ) ;
F_73 ( V_71 , V_112 ) ;
}
int F_74 ( struct V_67 * V_23 , struct V_68 * V_69 )
{
struct V_6 * V_7 ;
int V_48 ;
F_75 () ;
if ( ! F_40 ( V_23 -> V_70 ) ) {
V_48 = F_68 ( V_23 ) ;
if ( V_48 < 0 )
goto V_113;
}
V_48 = - V_25 ;
V_7 = F_69 ( sizeof( * V_7 ) , V_109 ) ;
if ( ! V_7 )
goto V_114;
V_48 = F_76 ( V_23 , V_69 -> V_33 ) ;
if ( V_48 < 0 )
goto V_115;
V_7 -> V_23 = V_23 ;
V_7 -> V_7 = V_69 ;
V_7 -> V_10 = V_116 ;
F_77 ( & V_7 -> V_75 ) ;
F_78 ( & V_7 -> V_35 ) ;
F_70 ( V_23 -> V_70 -> V_72 [ V_69 -> type ] , V_7 ) ;
F_79 ( & V_7 -> V_82 , F_52 , ( unsigned long ) V_7 ) ;
F_48 ( V_7 ) ;
return 0 ;
V_115:
F_11 ( V_7 ) ;
V_114:
F_71 ( V_23 ) ;
V_113:
return V_48 ;
}
void F_80 ( struct V_67 * V_23 , struct V_68 * V_69 )
{
struct V_70 * V_71 = F_40 ( V_23 -> V_70 ) ;
struct V_6 * V_7 = F_40 (
V_71 -> V_72 [ V_69 -> type ] ) ;
F_75 () ;
F_72 ( V_71 -> V_72 [ V_69 -> type ] , NULL ) ;
F_81 ( & V_7 -> V_82 ) ;
F_53 ( & V_7 -> V_75 ) ;
F_45 ( V_7 , V_56 ) ;
F_22 ( V_7 ) ;
F_54 ( & V_7 -> V_75 ) ;
F_27 ( V_7 ) ;
F_82 ( V_23 , V_69 -> V_33 ) ;
F_73 ( V_7 , V_112 ) ;
F_71 ( V_23 ) ;
}
int F_83 ( struct V_68 * V_69 )
{
V_69 -> V_27 . V_117 = F_61 ;
F_84 ( & V_69 -> V_27 ) ;
return 0 ;
}
void F_85 ( struct V_68 * V_69 )
{
F_86 ( & V_69 -> V_27 ) ;
}
