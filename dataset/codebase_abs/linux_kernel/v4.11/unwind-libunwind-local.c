static int F_1 ( T_1 * * V_1 , T_1 * V_2 , T_2 * V_3 ,
T_1 V_4 )
{
T_1 * V_5 = * V_1 ;
* V_3 = 0 ;
switch ( V_4 ) {
case V_6 :
* V_3 = 0 ;
goto V_7;
case V_8 :
* V_3 = F_2 (cur, unsigned long, end) ;
goto V_7;
default:
break;
}
switch ( V_4 & V_9 ) {
case V_10 :
break;
case V_11 :
* V_3 = ( unsigned long ) V_5 ;
break;
default:
return - V_12 ;
}
if ( ( V_4 & 0x07 ) == 0x00 )
V_4 |= V_13 ;
switch ( V_4 & V_14 ) {
case V_15 :
* V_3 += F_2 ( V_5 , V_16 , V_2 ) ;
break;
case V_13 :
* V_3 += F_2 ( V_5 , V_17 , V_2 ) ;
break;
case V_18 :
* V_3 += F_2 ( V_5 , V_19 , V_2 ) ;
break;
case V_20 :
* V_3 += F_2 ( V_5 , T_2 , V_2 ) ;
break;
default:
return - V_12 ;
}
V_7:
* V_1 = V_5 ;
return 0 ;
}
static T_2 F_3 ( int V_21 , const char * V_22 )
{
T_3 * V_23 ;
T_4 V_24 ;
T_5 V_25 ;
T_2 V_26 = 0 ;
V_23 = F_4 ( V_21 , V_27 , NULL ) ;
if ( V_23 == NULL )
return 0 ;
do {
if ( F_5 ( V_23 , & V_24 ) == NULL )
break;
if ( ! F_6 ( V_23 , & V_24 , & V_25 , V_22 , NULL ) )
break;
V_26 = V_25 . V_28 ;
} while ( 0 );
F_7 ( V_23 ) ;
return V_26 ;
}
static int F_8 ( int V_21 , const char * V_22 )
{
T_3 * V_23 ;
T_4 V_24 ;
int V_29 = 0 ;
V_23 = F_4 ( V_21 , V_27 , NULL ) ;
if ( V_23 == NULL )
return 0 ;
if ( F_5 ( V_23 , & V_24 ) == NULL )
goto V_7;
V_29 = ( V_24 . V_30 == V_31 ) ;
V_7:
F_7 ( V_23 ) ;
F_9 ( L_1 , V_22 , V_29 ) ;
return V_29 ;
}
static int F_10 ( struct V_32 * V_32 , struct V_33 * V_33 ,
T_2 V_26 , T_2 * V_34 , T_2 * V_35 ,
T_2 * V_36 )
{
struct V_37 V_38 ;
T_1 * V_39 = ( T_1 * ) & V_38 . V_39 ;
T_1 * V_2 = ( T_1 * ) & V_38 . V_40 ;
T_6 V_41 ;
V_41 = F_11 ( V_32 , V_33 , V_26 ,
( T_1 * ) & V_38 , sizeof( V_38 ) ) ;
if ( V_41 != sizeof( V_38 ) )
return - V_12 ;
F_12 ( V_39 , V_2 , V_38 . V_42 ) ;
* V_36 = F_12 ( V_39 , V_2 , V_38 . V_43 ) ;
* V_35 = V_26 ;
* V_34 = ( V_39 - ( T_1 * ) & V_38 ) + V_26 ;
return 0 ;
}
static int F_13 ( struct V_32 * V_32 , struct V_33 * V_33 ,
T_2 * V_34 , T_2 * V_35 ,
T_2 * V_36 )
{
int V_44 = - V_12 , V_21 ;
T_2 V_26 = V_32 -> V_40 . V_45 ;
if ( V_26 == 0 ) {
V_21 = F_14 ( V_32 , V_33 ) ;
if ( V_21 < 0 )
return - V_12 ;
V_26 = F_3 ( V_21 , L_2 ) ;
V_32 -> V_40 . V_45 = V_26 ;
F_15 ( V_32 ) ;
}
if ( V_26 )
V_44 = F_10 ( V_32 , V_33 , V_26 ,
V_34 , V_35 ,
V_36 ) ;
return V_44 ;
}
static int F_16 ( struct V_32 * V_32 ,
struct V_33 * V_33 , T_2 * V_26 )
{
int V_21 ;
T_2 V_46 = V_32 -> V_40 . V_47 ;
if ( V_46 == 0 ) {
V_21 = F_14 ( V_32 , V_33 ) ;
if ( V_21 >= 0 ) {
V_46 = F_3 ( V_21 , L_3 ) ;
F_15 ( V_32 ) ;
}
if ( V_46 <= 0 ) {
V_21 = F_17 ( V_32 -> V_48 , V_49 ) ;
if ( V_21 >= 0 ) {
V_46 = F_3 ( V_21 , L_3 ) ;
F_18 ( V_21 ) ;
}
}
if ( V_46 <= 0 ) {
char * V_50 = malloc ( V_51 ) ;
int V_44 = 0 ;
V_44 = F_19 (
V_32 , V_52 ,
V_33 -> V_53 , V_50 , V_51 ) ;
if ( ! V_44 ) {
V_21 = F_17 ( V_50 , V_49 ) ;
if ( V_21 >= 0 ) {
V_46 = F_3 ( V_21 ,
L_3 ) ;
F_18 ( V_21 ) ;
}
}
if ( V_46 > 0 ) {
if ( V_32 -> V_48 != NULL ) {
F_20 (
L_4 ,
V_54 ,
V_32 -> V_48 ,
V_50 ) ;
free ( V_32 -> V_48 ) ;
}
V_32 -> V_48 = V_50 ;
} else {
free ( V_50 ) ;
}
}
V_32 -> V_40 . V_47 = V_46 ;
}
* V_26 = V_46 ;
if ( * V_26 )
return 0 ;
return - V_12 ;
}
static struct V_55 * F_21 ( T_7 V_56 , struct V_57 * V_58 )
{
struct V_59 V_60 ;
F_22 ( V_58 -> V_61 , V_62 ,
V_63 , V_56 , & V_60 ) ;
if ( ! V_60 . V_55 ) {
F_22 ( V_58 -> V_61 , V_62 ,
V_64 , V_56 , & V_60 ) ;
}
return V_60 . V_55 ;
}
static int
F_23 ( T_8 V_65 , T_7 V_56 , T_9 * V_66 ,
int V_67 , void * V_68 )
{
struct V_57 * V_58 = V_68 ;
struct V_55 * V_55 ;
T_10 V_69 ;
T_2 V_34 , V_35 , V_36 ;
int V_44 = - V_12 ;
V_55 = F_21 ( V_56 , V_58 ) ;
if ( ! V_55 || ! V_55 -> V_32 )
return - V_12 ;
F_9 ( L_5 , V_55 -> V_32 -> V_22 ) ;
if ( ! F_13 ( V_55 -> V_32 , V_58 -> V_33 ,
& V_34 , & V_35 , & V_36 ) ) {
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_70 = V_71 ;
V_69 . V_72 = V_55 -> V_73 ;
V_69 . V_74 = V_55 -> V_2 ;
V_69 . V_75 . V_76 . V_35 = V_55 -> V_73 + V_35 - V_55 -> V_77 ;
V_69 . V_75 . V_76 . V_34 = V_55 -> V_73 + V_34 - V_55 -> V_77 ;
V_69 . V_75 . V_76 . V_78 = V_36 * sizeof( struct V_79 )
/ sizeof( T_7 ) ;
V_44 = F_24 ( V_65 , V_56 , & V_69 , V_66 ,
V_67 , V_68 ) ;
}
#ifndef F_25
if ( V_44 < 0 &&
! F_16 ( V_55 -> V_32 , V_58 -> V_33 , & V_35 ) ) {
int V_21 = F_14 ( V_55 -> V_32 , V_58 -> V_33 ) ;
int V_80 = F_8 ( V_21 , V_55 -> V_32 -> V_22 ) ;
T_7 V_81 = V_80 ? 0 : V_55 -> V_73 ;
const char * V_82 ;
if ( V_21 >= 0 )
F_15 ( V_55 -> V_32 ) ;
V_82 = V_55 -> V_32 -> V_48 ? : V_55 -> V_32 -> V_22 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( F_26 ( 0 , & V_69 , V_56 , V_81 , V_82 ,
V_55 -> V_73 , V_55 -> V_2 ) )
return F_24 ( V_65 , V_56 , & V_69 , V_66 ,
V_67 , V_68 ) ;
}
#endif
return V_44 ;
}
static int F_27 ( T_8 T_11 V_65 ,
T_12 T_11 V_83 ,
T_13 T_11 * V_3 ,
int T_11 V_84 ,
void T_11 * V_68 )
{
F_28 ( L_6 ) ;
return - V_85 ;
}
static int F_29 ( T_8 T_11 V_65 ,
T_7 T_11 * V_86 ,
void T_11 * V_68 )
{
return - V_87 ;
}
static int F_30 ( T_8 T_11 V_65 ,
T_14 T_11 * V_88 ,
void T_11 * V_68 )
{
F_28 ( L_7 ) ;
return - V_85 ;
}
static int
F_31 ( T_8 T_11 V_65 ,
T_7 T_11 V_89 ,
char T_11 * V_90 , T_15 T_11 V_91 ,
T_7 T_11 * V_92 , void T_11 * V_68 )
{
F_28 ( L_8 ) ;
return - V_85 ;
}
static int F_32 ( struct V_57 * V_58 , T_7 V_89 ,
T_7 * V_40 )
{
struct V_55 * V_55 ;
T_6 V_93 ;
V_55 = F_21 ( V_89 , V_58 ) ;
if ( ! V_55 ) {
F_9 ( L_9 , ( unsigned long ) V_89 ) ;
return - 1 ;
}
if ( ! V_55 -> V_32 )
return - 1 ;
V_93 = F_33 ( V_55 -> V_32 , V_55 , V_58 -> V_33 ,
V_89 , ( T_1 * ) V_40 , sizeof( * V_40 ) ) ;
return ! ( V_93 == sizeof( * V_40 ) ) ;
}
static int F_34 ( T_8 T_11 V_65 ,
T_7 V_89 , T_7 * V_94 ,
int V_84 , void * V_68 )
{
struct V_57 * V_58 = V_68 ;
struct V_95 * V_96 = & V_58 -> V_97 -> V_98 ;
T_2 V_73 , V_2 ;
int V_26 ;
int V_44 ;
if ( V_84 || ! V_96 || ! V_58 -> V_97 -> V_99 . V_100 ) {
* V_94 = 0 ;
return 0 ;
}
V_44 = F_35 ( & V_73 , & V_58 -> V_97 -> V_99 ,
V_101 ) ;
if ( V_44 )
return V_44 ;
V_2 = V_73 + V_96 -> V_93 ;
if ( V_89 + sizeof( T_7 ) < V_89 )
return - V_12 ;
if ( V_89 < V_73 || V_89 + sizeof( T_7 ) >= V_2 ) {
V_44 = F_32 ( V_58 , V_89 , V_94 ) ;
if ( V_44 ) {
F_9 ( L_10
L_11 V_102 L_12 V_102 L_13 ,
( void * ) ( V_103 ) V_89 , V_73 , V_2 ) ;
* V_94 = 0 ;
return V_44 ;
}
return 0 ;
}
V_26 = V_89 - V_73 ;
* V_94 = * ( T_7 * ) & V_96 -> V_40 [ V_26 ] ;
F_9 ( L_14 ,
( void * ) ( V_103 ) V_89 , ( unsigned long ) * V_94 , V_26 ) ;
return 0 ;
}
static int F_36 ( T_8 T_11 V_65 ,
T_12 V_104 , T_7 * V_94 ,
int V_84 , void * V_68 )
{
struct V_57 * V_58 = V_68 ;
int V_105 , V_44 ;
T_2 V_3 ;
if ( V_84 ) {
F_28 ( L_15 , V_104 ) ;
return 0 ;
}
if ( ! V_58 -> V_97 -> V_99 . V_100 ) {
* V_94 = 0 ;
return 0 ;
}
V_105 = F_37 ( V_104 ) ;
if ( V_105 < 0 )
return - V_12 ;
V_44 = F_35 ( & V_3 , & V_58 -> V_97 -> V_99 , V_105 ) ;
if ( V_44 ) {
F_28 ( L_16 , V_104 ) ;
return V_44 ;
}
* V_94 = ( T_7 ) V_3 ;
F_9 ( L_17 , V_104 , ( unsigned long ) * V_94 ) ;
return 0 ;
}
static void F_38 ( T_8 T_11 V_65 ,
T_9 * V_66 T_11 ,
void * V_68 T_11 )
{
F_9 ( L_18 ) ;
}
static int F_39 ( T_2 V_56 , struct V_61 * V_61 ,
T_16 V_106 , void * V_68 )
{
struct V_107 V_108 ;
struct V_59 V_60 ;
F_40 ( V_61 , V_62 ,
V_63 , V_56 , & V_60 ) ;
V_108 . V_56 = V_60 . V_89 ;
V_108 . V_55 = V_60 . V_55 ;
V_108 . V_109 = V_60 . V_109 ;
F_9 ( L_19 V_102 L_20 V_102 L_21 ,
V_60 . V_109 ? V_60 . V_109 -> V_22 : L_22 ,
V_56 ,
V_60 . V_55 ? V_60 . V_55 -> V_110 ( V_60 . V_55 , V_56 ) : ( T_2 ) 0 ) ;
return V_106 ( & V_108 , V_68 ) ;
}
static void F_41 ( int V_111 )
{
switch ( V_111 ) {
case V_85 :
F_28 ( L_23 ) ;
break;
case V_112 :
F_28 ( L_24 ) ;
break;
case V_113 :
F_28 ( L_25 ) ;
break;
default:
break;
}
}
static int F_42 ( struct V_61 * V_61 )
{
if ( V_114 . V_115 != V_116 )
return 0 ;
V_61 -> V_117 = F_43 ( & V_118 , 0 ) ;
if ( ! V_61 -> V_117 ) {
F_28 ( L_26 ) ;
return - V_119 ;
}
F_44 ( V_61 -> V_117 , V_120 ) ;
return 0 ;
}
static void F_45 ( struct V_61 * V_61 )
{
if ( V_114 . V_115 != V_116 )
return;
F_46 ( V_61 -> V_117 , 0 , 0 ) ;
}
static void F_47 ( struct V_61 * V_61 )
{
if ( V_114 . V_115 != V_116 )
return;
F_48 ( V_61 -> V_117 ) ;
}
static int F_49 ( struct V_57 * V_58 , T_16 V_106 ,
void * V_68 , int V_121 )
{
T_2 V_3 ;
T_7 V_122 [ V_121 ] ;
T_8 V_117 ;
T_14 V_123 ;
int V_44 , V_124 = 0 ;
V_44 = F_35 ( & V_3 , & V_58 -> V_97 -> V_99 ,
V_125 ) ;
if ( V_44 )
return V_44 ;
V_122 [ V_124 ++ ] = ( T_7 ) V_3 ;
if ( V_121 - 1 > 0 ) {
F_50 ( ! V_58 -> V_61 , L_27 ) ;
V_117 = V_58 -> V_61 -> V_117 ;
if ( V_117 == NULL )
return - 1 ;
V_44 = F_51 ( & V_123 , V_117 , V_58 ) ;
if ( V_44 )
F_41 ( V_44 ) ;
while ( ! V_44 && ( F_52 ( & V_123 ) > 0 ) && V_124 < V_121 ) {
F_53 ( & V_123 , V_126 , & V_122 [ V_124 ] ) ;
++ V_124 ;
}
V_121 = V_124 ;
}
for ( V_124 = 0 ; V_124 < V_121 && ! V_44 ; V_124 ++ ) {
int V_127 = V_124 ;
if ( V_114 . V_128 == V_129 )
V_127 = V_121 - V_124 - 1 ;
V_44 = V_122 [ V_127 ] ? F_39 ( V_122 [ V_127 ] , V_58 -> V_61 , V_106 , V_68 ) : 0 ;
}
return V_44 ;
}
static int F_54 ( T_16 V_106 , void * V_68 ,
struct V_61 * V_61 ,
struct V_130 * V_40 , int V_121 )
{
struct V_57 V_58 = {
. V_97 = V_40 ,
. V_61 = V_61 ,
. V_33 = V_61 -> V_131 -> V_33 ,
} ;
if ( ! V_40 -> V_99 . V_100 )
return - V_12 ;
if ( V_121 <= 0 )
return - V_12 ;
return F_49 ( & V_58 , V_106 , V_68 , V_121 ) ;
}
