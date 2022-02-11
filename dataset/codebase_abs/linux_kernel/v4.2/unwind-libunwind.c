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
return V_53 . V_48 ;
}
static int
F_19 ( T_8 V_57 , T_7 V_49 , T_9 * V_58 ,
int V_59 , void * V_60 )
{
struct V_50 * V_51 = V_60 ;
struct V_48 * V_48 ;
T_10 V_61 ;
T_2 V_34 , V_35 , V_36 ;
V_48 = F_17 ( V_49 , V_51 ) ;
if ( ! V_48 || ! V_48 -> V_32 )
return - V_12 ;
F_9 ( L_4 , V_48 -> V_32 -> V_22 ) ;
if ( ! F_13 ( V_48 -> V_32 , V_51 -> V_33 ,
& V_34 , & V_35 , & V_36 ) ) {
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_62 = V_63 ;
V_61 . V_64 = V_48 -> V_65 ;
V_61 . V_66 = V_48 -> V_2 ;
V_61 . V_67 . V_68 . V_35 = V_48 -> V_65 + V_35 ;
V_61 . V_67 . V_68 . V_34 = V_48 -> V_65 + V_34 ;
V_61 . V_67 . V_68 . V_69 = V_36 * sizeof( struct V_70 )
/ sizeof( T_7 ) ;
return F_20 ( V_57 , V_49 , & V_61 , V_58 ,
V_59 , V_60 ) ;
}
#ifndef F_21
if ( ! F_16 ( V_48 -> V_32 , V_51 -> V_33 , & V_35 ) ) {
int V_21 = F_14 ( V_48 -> V_32 , V_51 -> V_33 ) ;
int V_71 = F_8 ( V_21 , V_48 -> V_32 -> V_22 ) ;
T_7 V_72 = V_71 ? 0 : V_48 -> V_65 ;
if ( V_21 >= 0 )
F_15 ( V_48 -> V_32 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
if ( F_22 ( 0 , & V_61 , V_49 , V_72 , V_48 -> V_32 -> V_22 ,
V_48 -> V_65 , V_48 -> V_2 ) )
return F_20 ( V_57 , V_49 , & V_61 , V_58 ,
V_59 , V_60 ) ;
}
#endif
return - V_12 ;
}
static int F_23 ( T_8 T_11 V_57 ,
T_12 T_11 V_73 ,
T_13 T_11 * V_3 ,
int T_11 V_74 ,
void T_11 * V_60 )
{
F_24 ( L_5 ) ;
return - V_75 ;
}
static int F_25 ( T_8 T_11 V_57 ,
T_7 T_11 * V_76 ,
void T_11 * V_60 )
{
return - V_77 ;
}
static int F_26 ( T_8 T_11 V_57 ,
T_14 T_11 * V_78 ,
void T_11 * V_60 )
{
F_24 ( L_6 ) ;
return - V_75 ;
}
static int
F_27 ( T_8 T_11 V_57 ,
T_7 T_11 V_79 ,
char T_11 * V_80 , T_15 T_11 V_81 ,
T_7 T_11 * V_82 , void T_11 * V_60 )
{
F_24 ( L_7 ) ;
return - V_75 ;
}
static int F_28 ( struct V_50 * V_51 , T_7 V_79 ,
T_7 * V_40 )
{
struct V_52 V_53 ;
T_6 V_83 ;
F_18 ( V_51 -> V_54 , V_55 ,
V_56 , V_79 , & V_53 ) ;
if ( ! V_53 . V_48 ) {
F_9 ( L_8 , ( unsigned long ) V_79 ) ;
return - 1 ;
}
if ( ! V_53 . V_48 -> V_32 )
return - 1 ;
V_83 = F_29 ( V_53 . V_48 -> V_32 , V_53 . V_48 , V_51 -> V_33 ,
V_79 , ( T_1 * ) V_40 , sizeof( * V_40 ) ) ;
return ! ( V_83 == sizeof( * V_40 ) ) ;
}
static int F_30 ( T_8 T_11 V_57 ,
T_7 V_79 , T_7 * V_84 ,
int V_74 , void * V_60 )
{
struct V_50 * V_51 = V_60 ;
struct V_85 * V_86 = & V_51 -> V_87 -> V_88 ;
T_2 V_65 , V_2 ;
int V_26 ;
int V_44 ;
if ( V_74 || ! V_86 || ! V_51 -> V_87 -> V_89 . V_90 ) {
* V_84 = 0 ;
return 0 ;
}
V_44 = F_31 ( & V_65 , & V_51 -> V_87 -> V_89 , V_91 ) ;
if ( V_44 )
return V_44 ;
V_2 = V_65 + V_86 -> V_83 ;
if ( V_79 + sizeof( T_7 ) < V_79 )
return - V_12 ;
if ( V_79 < V_65 || V_79 + sizeof( T_7 ) >= V_2 ) {
V_44 = F_28 ( V_51 , V_79 , V_84 ) ;
if ( V_44 ) {
F_9 ( L_9
L_10 V_92 L_11 V_92 L_12 ,
( void * ) V_79 , V_65 , V_2 ) ;
* V_84 = 0 ;
return V_44 ;
}
return 0 ;
}
V_26 = V_79 - V_65 ;
* V_84 = * ( T_7 * ) & V_86 -> V_40 [ V_26 ] ;
F_9 ( L_13 ,
( void * ) V_79 , ( unsigned long ) * V_84 , V_26 ) ;
return 0 ;
}
static int F_32 ( T_8 T_11 V_57 ,
T_12 V_93 , T_7 * V_84 ,
int V_74 , void * V_60 )
{
struct V_50 * V_51 = V_60 ;
int V_94 , V_44 ;
T_2 V_3 ;
if ( V_74 ) {
F_24 ( L_14 , V_93 ) ;
return 0 ;
}
if ( ! V_51 -> V_87 -> V_89 . V_90 ) {
* V_84 = 0 ;
return 0 ;
}
V_94 = F_33 ( V_93 ) ;
if ( V_94 < 0 )
return - V_12 ;
V_44 = F_31 ( & V_3 , & V_51 -> V_87 -> V_89 , V_94 ) ;
if ( V_44 ) {
F_24 ( L_15 , V_93 ) ;
return V_44 ;
}
* V_84 = ( T_7 ) V_3 ;
F_9 ( L_16 , V_93 , ( unsigned long ) * V_84 ) ;
return 0 ;
}
static void F_34 ( T_8 T_11 V_57 ,
T_9 * V_58 T_11 ,
void * V_60 T_11 )
{
F_9 ( L_17 ) ;
}
static int F_35 ( T_2 V_49 , struct V_54 * V_54 ,
T_16 V_95 , void * V_60 )
{
struct V_96 V_97 ;
struct V_52 V_53 ;
F_36 ( V_54 , V_55 ,
V_56 , V_49 , & V_53 ) ;
V_97 . V_49 = V_49 ;
V_97 . V_48 = V_53 . V_48 ;
V_97 . V_98 = V_53 . V_98 ;
F_9 ( L_18 V_92 L_19 V_92 L_20 ,
V_53 . V_98 ? V_53 . V_98 -> V_22 : L_21 ,
V_49 ,
V_53 . V_48 ? V_53 . V_48 -> V_99 ( V_53 . V_48 , V_49 ) : ( T_2 ) 0 ) ;
return V_95 ( & V_97 , V_60 ) ;
}
static void F_37 ( int V_100 )
{
switch ( V_100 ) {
case V_75 :
F_24 ( L_22 ) ;
break;
case V_101 :
F_24 ( L_23 ) ;
break;
case V_102 :
F_24 ( L_24 ) ;
break;
default:
break;
}
}
int F_38 ( struct V_54 * V_54 )
{
T_8 V_103 ;
if ( V_104 . V_105 != V_106 )
return 0 ;
V_103 = F_39 ( & V_107 , 0 ) ;
if ( ! V_103 ) {
F_24 ( L_25 ) ;
return - V_108 ;
}
F_40 ( V_103 , V_109 ) ;
F_41 ( V_54 , V_103 ) ;
return 0 ;
}
void F_42 ( struct V_54 * V_54 )
{
T_8 V_103 ;
if ( V_104 . V_105 != V_106 )
return;
V_103 = F_43 ( V_54 ) ;
F_44 ( V_103 , 0 , 0 ) ;
}
void F_45 ( struct V_54 * V_54 )
{
T_8 V_103 ;
if ( V_104 . V_105 != V_106 )
return;
V_103 = F_43 ( V_54 ) ;
F_46 ( V_103 ) ;
}
static int F_47 ( struct V_50 * V_51 , T_16 V_95 ,
void * V_60 , int V_110 )
{
T_8 V_103 ;
T_14 V_111 ;
int V_44 ;
V_103 = F_43 ( V_51 -> V_54 ) ;
if ( V_103 == NULL )
return - 1 ;
V_44 = F_48 ( & V_111 , V_103 , V_51 ) ;
if ( V_44 )
F_37 ( V_44 ) ;
while ( ! V_44 && ( F_49 ( & V_111 ) > 0 ) && V_110 -- ) {
T_7 V_49 ;
F_50 ( & V_111 , V_112 , & V_49 ) ;
V_44 = V_49 ? F_35 ( V_49 , V_51 -> V_54 , V_95 , V_60 ) : 0 ;
}
return V_44 ;
}
int F_51 ( T_16 V_95 , void * V_60 ,
struct V_54 * V_54 ,
struct V_113 * V_40 , int V_110 )
{
T_2 V_49 ;
struct V_50 V_51 = {
. V_87 = V_40 ,
. V_54 = V_54 ,
. V_33 = V_54 -> V_114 -> V_33 ,
} ;
int V_44 ;
if ( ! V_40 -> V_89 . V_90 )
return - V_12 ;
V_44 = F_31 ( & V_49 , & V_40 -> V_89 , V_115 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_35 ( V_49 , V_54 , V_95 , V_60 ) ;
if ( V_44 )
return - V_108 ;
return -- V_110 > 0 ? F_47 ( & V_51 , V_95 , V_60 , V_110 ) : 0 ;
}
