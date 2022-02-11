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
if ( V_21 < 0 )
return - V_12 ;
V_46 = F_3 ( V_21 , L_3 ) ;
V_32 -> V_40 . V_47 = V_46 ;
F_15 ( V_32 ) ;
}
* V_26 = V_46 ;
if ( * V_26 )
return 0 ;
return - V_12 ;
}
static struct V_48 * F_17 ( T_7 V_49 , struct V_50 * V_51 )
{
struct V_52 V_53 ;
F_18 ( V_51 -> V_54 , V_55 ,
V_56 , V_49 , & V_53 ) ;
if ( ! V_53 . V_48 ) {
F_18 ( V_51 -> V_54 , V_55 ,
V_57 , V_49 , & V_53 ) ;
}
return V_53 . V_48 ;
}
static int
F_19 ( T_8 V_58 , T_7 V_49 , T_9 * V_59 ,
int V_60 , void * V_61 )
{
struct V_50 * V_51 = V_61 ;
struct V_48 * V_48 ;
T_10 V_62 ;
T_2 V_34 , V_35 , V_36 ;
int V_44 = - V_12 ;
V_48 = F_17 ( V_49 , V_51 ) ;
if ( ! V_48 || ! V_48 -> V_32 )
return - V_12 ;
F_9 ( L_4 , V_48 -> V_32 -> V_22 ) ;
if ( ! F_13 ( V_48 -> V_32 , V_51 -> V_33 ,
& V_34 , & V_35 , & V_36 ) ) {
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_63 = V_64 ;
V_62 . V_65 = V_48 -> V_66 ;
V_62 . V_67 = V_48 -> V_2 ;
V_62 . V_68 . V_69 . V_35 = V_48 -> V_66 + V_35 - V_48 -> V_70 ;
V_62 . V_68 . V_69 . V_34 = V_48 -> V_66 + V_34 - V_48 -> V_70 ;
V_62 . V_68 . V_69 . V_71 = V_36 * sizeof( struct V_72 )
/ sizeof( T_7 ) ;
V_44 = F_20 ( V_58 , V_49 , & V_62 , V_59 ,
V_60 , V_61 ) ;
}
#ifndef F_21
if ( V_44 < 0 &&
! F_16 ( V_48 -> V_32 , V_51 -> V_33 , & V_35 ) ) {
int V_21 = F_14 ( V_48 -> V_32 , V_51 -> V_33 ) ;
int V_73 = F_8 ( V_21 , V_48 -> V_32 -> V_22 ) ;
T_7 V_74 = V_73 ? 0 : V_48 -> V_66 ;
const char * V_75 ;
if ( V_21 >= 0 )
F_15 ( V_48 -> V_32 ) ;
V_75 = V_48 -> V_32 -> V_76 ? : V_48 -> V_32 -> V_22 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
if ( F_22 ( 0 , & V_62 , V_49 , V_74 , V_75 ,
V_48 -> V_66 , V_48 -> V_2 ) )
return F_20 ( V_58 , V_49 , & V_62 , V_59 ,
V_60 , V_61 ) ;
}
#endif
return V_44 ;
}
static int F_23 ( T_8 T_11 V_58 ,
T_12 T_11 V_77 ,
T_13 T_11 * V_3 ,
int T_11 V_78 ,
void T_11 * V_61 )
{
F_24 ( L_5 ) ;
return - V_79 ;
}
static int F_25 ( T_8 T_11 V_58 ,
T_7 T_11 * V_80 ,
void T_11 * V_61 )
{
return - V_81 ;
}
static int F_26 ( T_8 T_11 V_58 ,
T_14 T_11 * V_82 ,
void T_11 * V_61 )
{
F_24 ( L_6 ) ;
return - V_79 ;
}
static int
F_27 ( T_8 T_11 V_58 ,
T_7 T_11 V_83 ,
char T_11 * V_84 , T_15 T_11 V_85 ,
T_7 T_11 * V_86 , void T_11 * V_61 )
{
F_24 ( L_7 ) ;
return - V_79 ;
}
static int F_28 ( struct V_50 * V_51 , T_7 V_83 ,
T_7 * V_40 )
{
struct V_48 * V_48 ;
T_6 V_87 ;
V_48 = F_17 ( V_83 , V_51 ) ;
if ( ! V_48 ) {
F_9 ( L_8 , ( unsigned long ) V_83 ) ;
return - 1 ;
}
if ( ! V_48 -> V_32 )
return - 1 ;
V_87 = F_29 ( V_48 -> V_32 , V_48 , V_51 -> V_33 ,
V_83 , ( T_1 * ) V_40 , sizeof( * V_40 ) ) ;
return ! ( V_87 == sizeof( * V_40 ) ) ;
}
static int F_30 ( T_8 T_11 V_58 ,
T_7 V_83 , T_7 * V_88 ,
int V_78 , void * V_61 )
{
struct V_50 * V_51 = V_61 ;
struct V_89 * V_90 = & V_51 -> V_91 -> V_92 ;
T_2 V_66 , V_2 ;
int V_26 ;
int V_44 ;
if ( V_78 || ! V_90 || ! V_51 -> V_91 -> V_93 . V_94 ) {
* V_88 = 0 ;
return 0 ;
}
V_44 = F_31 ( & V_66 , & V_51 -> V_91 -> V_93 ,
V_95 ) ;
if ( V_44 )
return V_44 ;
V_2 = V_66 + V_90 -> V_87 ;
if ( V_83 + sizeof( T_7 ) < V_83 )
return - V_12 ;
if ( V_83 < V_66 || V_83 + sizeof( T_7 ) >= V_2 ) {
V_44 = F_28 ( V_51 , V_83 , V_88 ) ;
if ( V_44 ) {
F_9 ( L_9
L_10 V_96 L_11 V_96 L_12 ,
( void * ) ( V_97 ) V_83 , V_66 , V_2 ) ;
* V_88 = 0 ;
return V_44 ;
}
return 0 ;
}
V_26 = V_83 - V_66 ;
* V_88 = * ( T_7 * ) & V_90 -> V_40 [ V_26 ] ;
F_9 ( L_13 ,
( void * ) ( V_97 ) V_83 , ( unsigned long ) * V_88 , V_26 ) ;
return 0 ;
}
static int F_32 ( T_8 T_11 V_58 ,
T_12 V_98 , T_7 * V_88 ,
int V_78 , void * V_61 )
{
struct V_50 * V_51 = V_61 ;
int V_99 , V_44 ;
T_2 V_3 ;
if ( V_78 ) {
F_24 ( L_14 , V_98 ) ;
return 0 ;
}
if ( ! V_51 -> V_91 -> V_93 . V_94 ) {
* V_88 = 0 ;
return 0 ;
}
V_99 = F_33 ( V_98 ) ;
if ( V_99 < 0 )
return - V_12 ;
V_44 = F_31 ( & V_3 , & V_51 -> V_91 -> V_93 , V_99 ) ;
if ( V_44 ) {
F_24 ( L_15 , V_98 ) ;
return V_44 ;
}
* V_88 = ( T_7 ) V_3 ;
F_9 ( L_16 , V_98 , ( unsigned long ) * V_88 ) ;
return 0 ;
}
static void F_34 ( T_8 T_11 V_58 ,
T_9 * V_59 T_11 ,
void * V_61 T_11 )
{
F_9 ( L_17 ) ;
}
static int F_35 ( T_2 V_49 , struct V_54 * V_54 ,
T_16 V_100 , void * V_61 )
{
struct V_101 V_102 ;
struct V_52 V_53 ;
F_36 ( V_54 , V_55 ,
V_56 , V_49 , & V_53 ) ;
V_102 . V_49 = V_53 . V_83 ;
V_102 . V_48 = V_53 . V_48 ;
V_102 . V_103 = V_53 . V_103 ;
F_9 ( L_18 V_96 L_19 V_96 L_20 ,
V_53 . V_103 ? V_53 . V_103 -> V_22 : L_21 ,
V_49 ,
V_53 . V_48 ? V_53 . V_48 -> V_104 ( V_53 . V_48 , V_49 ) : ( T_2 ) 0 ) ;
return V_100 ( & V_102 , V_61 ) ;
}
static void F_37 ( int V_105 )
{
switch ( V_105 ) {
case V_79 :
F_24 ( L_22 ) ;
break;
case V_106 :
F_24 ( L_23 ) ;
break;
case V_107 :
F_24 ( L_24 ) ;
break;
default:
break;
}
}
static int F_38 ( struct V_54 * V_54 )
{
if ( V_108 . V_109 != V_110 )
return 0 ;
V_54 -> V_111 = F_39 ( & V_112 , 0 ) ;
if ( ! V_54 -> V_111 ) {
F_24 ( L_25 ) ;
return - V_113 ;
}
F_40 ( V_54 -> V_111 , V_114 ) ;
return 0 ;
}
static void F_41 ( struct V_54 * V_54 )
{
if ( V_108 . V_109 != V_110 )
return;
F_42 ( V_54 -> V_111 , 0 , 0 ) ;
}
static void F_43 ( struct V_54 * V_54 )
{
if ( V_108 . V_109 != V_110 )
return;
F_44 ( V_54 -> V_111 ) ;
}
static int F_45 ( struct V_50 * V_51 , T_16 V_100 ,
void * V_61 , int V_115 )
{
T_2 V_3 ;
T_7 V_116 [ V_115 ] ;
T_8 V_111 ;
T_14 V_117 ;
int V_44 , V_118 = 0 ;
V_44 = F_31 ( & V_3 , & V_51 -> V_91 -> V_93 ,
V_119 ) ;
if ( V_44 )
return V_44 ;
V_116 [ V_118 ++ ] = ( T_7 ) V_3 ;
if ( V_115 - 1 > 0 ) {
F_46 ( ! V_51 -> V_54 , L_26 ) ;
V_111 = V_51 -> V_54 -> V_111 ;
if ( V_111 == NULL )
return - 1 ;
V_44 = F_47 ( & V_117 , V_111 , V_51 ) ;
if ( V_44 )
F_37 ( V_44 ) ;
while ( ! V_44 && ( F_48 ( & V_117 ) > 0 ) && V_118 < V_115 ) {
F_49 ( & V_117 , V_120 , & V_116 [ V_118 ] ) ;
++ V_118 ;
}
V_115 = V_118 ;
}
for ( V_118 = 0 ; V_118 < V_115 && ! V_44 ; V_118 ++ ) {
int V_121 = V_118 ;
if ( V_108 . V_122 == V_123 )
V_121 = V_115 - V_118 - 1 ;
V_44 = V_116 [ V_121 ] ? F_35 ( V_116 [ V_121 ] , V_51 -> V_54 , V_100 , V_61 ) : 0 ;
}
return V_44 ;
}
static int F_50 ( T_16 V_100 , void * V_61 ,
struct V_54 * V_54 ,
struct V_124 * V_40 , int V_115 )
{
struct V_50 V_51 = {
. V_91 = V_40 ,
. V_54 = V_54 ,
. V_33 = V_54 -> V_125 -> V_33 ,
} ;
if ( ! V_40 -> V_93 . V_94 )
return - V_12 ;
if ( V_115 <= 0 )
return - V_12 ;
return F_45 ( & V_51 , V_100 , V_61 , V_115 ) ;
}
