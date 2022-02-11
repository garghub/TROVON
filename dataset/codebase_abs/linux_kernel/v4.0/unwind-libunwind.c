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
}
if ( V_26 )
V_44 = F_10 ( V_32 , V_33 , V_26 ,
V_34 , V_35 ,
V_36 ) ;
return V_44 ;
}
static int F_15 ( struct V_32 * V_32 ,
struct V_33 * V_33 , T_2 * V_26 )
{
int V_21 ;
T_2 V_46 = V_32 -> V_40 . V_45 ;
if ( V_46 == 0 ) {
V_21 = F_14 ( V_32 , V_33 ) ;
if ( V_21 < 0 )
return - V_12 ;
V_46 = F_3 ( V_21 , L_3 ) ;
V_32 -> V_40 . V_45 = V_46 ;
}
* V_26 = V_46 ;
if ( * V_26 )
return 0 ;
return - V_12 ;
}
static struct V_47 * F_16 ( T_7 V_48 , struct V_49 * V_50 )
{
struct V_51 V_52 ;
F_17 ( V_50 -> V_53 , V_54 ,
V_55 , V_48 , & V_52 ) ;
return V_52 . V_47 ;
}
static int
F_18 ( T_8 V_56 , T_7 V_48 , T_9 * V_57 ,
int V_58 , void * V_59 )
{
struct V_49 * V_50 = V_59 ;
struct V_47 * V_47 ;
T_10 V_60 ;
T_2 V_34 , V_35 , V_36 ;
V_47 = F_16 ( V_48 , V_50 ) ;
if ( ! V_47 || ! V_47 -> V_32 )
return - V_12 ;
F_9 ( L_4 , V_47 -> V_32 -> V_22 ) ;
if ( ! F_13 ( V_47 -> V_32 , V_50 -> V_33 ,
& V_34 , & V_35 , & V_36 ) ) {
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_61 = V_62 ;
V_60 . V_63 = V_47 -> V_64 ;
V_60 . V_65 = V_47 -> V_2 ;
V_60 . V_66 . V_67 . V_35 = V_47 -> V_64 + V_35 ;
V_60 . V_66 . V_67 . V_34 = V_47 -> V_64 + V_34 ;
V_60 . V_66 . V_67 . V_68 = V_36 * sizeof( struct V_69 )
/ sizeof( T_7 ) ;
return F_19 ( V_56 , V_48 , & V_60 , V_57 ,
V_58 , V_59 ) ;
}
#ifndef F_20
if ( ! F_15 ( V_47 -> V_32 , V_50 -> V_33 , & V_35 ) ) {
int V_21 = F_14 ( V_47 -> V_32 , V_50 -> V_33 ) ;
int V_70 = F_8 ( V_21 , V_47 -> V_32 -> V_22 ) ;
T_7 V_71 = V_70 ? 0 : V_47 -> V_64 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
if ( F_21 ( 0 , & V_60 , V_48 , V_71 , V_47 -> V_32 -> V_22 ,
V_47 -> V_64 , V_47 -> V_2 ) )
return F_19 ( V_56 , V_48 , & V_60 , V_57 ,
V_58 , V_59 ) ;
}
#endif
return - V_12 ;
}
static int F_22 ( T_8 T_11 V_56 ,
T_12 T_11 V_72 ,
T_13 T_11 * V_3 ,
int T_11 V_73 ,
void T_11 * V_59 )
{
F_23 ( L_5 ) ;
return - V_74 ;
}
static int F_24 ( T_8 T_11 V_56 ,
T_7 T_11 * V_75 ,
void T_11 * V_59 )
{
return - V_76 ;
}
static int F_25 ( T_8 T_11 V_56 ,
T_14 T_11 * V_77 ,
void T_11 * V_59 )
{
F_23 ( L_6 ) ;
return - V_74 ;
}
static int
F_26 ( T_8 T_11 V_56 ,
T_7 T_11 V_78 ,
char T_11 * V_79 , T_15 T_11 V_80 ,
T_7 T_11 * V_81 , void T_11 * V_59 )
{
F_23 ( L_7 ) ;
return - V_74 ;
}
static int F_27 ( struct V_49 * V_50 , T_7 V_78 ,
T_7 * V_40 )
{
struct V_51 V_52 ;
T_6 V_82 ;
F_17 ( V_50 -> V_53 , V_54 ,
V_55 , V_78 , & V_52 ) ;
if ( ! V_52 . V_47 ) {
F_9 ( L_8 , ( unsigned long ) V_78 ) ;
return - 1 ;
}
if ( ! V_52 . V_47 -> V_32 )
return - 1 ;
V_82 = F_28 ( V_52 . V_47 -> V_32 , V_52 . V_47 , V_50 -> V_33 ,
V_78 , ( T_1 * ) V_40 , sizeof( * V_40 ) ) ;
return ! ( V_82 == sizeof( * V_40 ) ) ;
}
static int F_29 ( T_8 T_11 V_56 ,
T_7 V_78 , T_7 * V_83 ,
int V_73 , void * V_59 )
{
struct V_49 * V_50 = V_59 ;
struct V_84 * V_85 = & V_50 -> V_86 -> V_87 ;
T_2 V_64 , V_2 ;
int V_26 ;
int V_44 ;
if ( V_73 || ! V_85 || ! V_50 -> V_86 -> V_88 . V_89 ) {
* V_83 = 0 ;
return 0 ;
}
V_44 = F_30 ( & V_64 , & V_50 -> V_86 -> V_88 , V_90 ) ;
if ( V_44 )
return V_44 ;
V_2 = V_64 + V_85 -> V_82 ;
if ( V_78 + sizeof( T_7 ) < V_78 )
return - V_12 ;
if ( V_78 < V_64 || V_78 + sizeof( T_7 ) >= V_2 ) {
V_44 = F_27 ( V_50 , V_78 , V_83 ) ;
if ( V_44 ) {
F_9 ( L_9
L_10 V_91 L_11 V_91 L_12 ,
( void * ) V_78 , V_64 , V_2 ) ;
* V_83 = 0 ;
return V_44 ;
}
return 0 ;
}
V_26 = V_78 - V_64 ;
* V_83 = * ( T_7 * ) & V_85 -> V_40 [ V_26 ] ;
F_9 ( L_13 ,
( void * ) V_78 , ( unsigned long ) * V_83 , V_26 ) ;
return 0 ;
}
static int F_31 ( T_8 T_11 V_56 ,
T_12 V_92 , T_7 * V_83 ,
int V_73 , void * V_59 )
{
struct V_49 * V_50 = V_59 ;
int V_93 , V_44 ;
T_2 V_3 ;
if ( V_73 ) {
F_23 ( L_14 , V_92 ) ;
return 0 ;
}
if ( ! V_50 -> V_86 -> V_88 . V_89 ) {
* V_83 = 0 ;
return 0 ;
}
V_93 = F_32 ( V_92 ) ;
if ( V_93 < 0 )
return - V_12 ;
V_44 = F_30 ( & V_3 , & V_50 -> V_86 -> V_88 , V_93 ) ;
if ( V_44 ) {
F_23 ( L_15 , V_92 ) ;
return V_44 ;
}
* V_83 = ( T_7 ) V_3 ;
F_9 ( L_16 , V_92 , ( unsigned long ) * V_83 ) ;
return 0 ;
}
static void F_33 ( T_8 T_11 V_56 ,
T_9 * V_57 T_11 ,
void * V_59 T_11 )
{
F_9 ( L_17 ) ;
}
static int F_34 ( T_2 V_48 , struct V_53 * V_53 ,
T_16 V_94 , void * V_59 )
{
struct V_95 V_96 ;
struct V_51 V_52 ;
F_35 ( V_53 , V_54 ,
V_55 , V_48 , & V_52 ) ;
V_96 . V_48 = V_48 ;
V_96 . V_47 = V_52 . V_47 ;
V_96 . V_97 = V_52 . V_97 ;
F_9 ( L_18 V_91 L_19 V_91 L_20 ,
V_52 . V_97 ? V_52 . V_97 -> V_22 : L_21 ,
V_48 ,
V_52 . V_47 ? V_52 . V_47 -> V_98 ( V_52 . V_47 , V_48 ) : ( T_2 ) 0 ) ;
return V_94 ( & V_96 , V_59 ) ;
}
static void F_36 ( int V_99 )
{
switch ( V_99 ) {
case V_74 :
F_23 ( L_22 ) ;
break;
case V_100 :
F_23 ( L_23 ) ;
break;
case V_101 :
F_23 ( L_24 ) ;
break;
default:
break;
}
}
int F_37 ( struct V_53 * V_53 )
{
T_8 V_102 ;
if ( V_103 . V_104 != V_105 )
return 0 ;
V_102 = F_38 ( & V_106 , 0 ) ;
if ( ! V_102 ) {
F_23 ( L_25 ) ;
return - V_107 ;
}
F_39 ( V_102 , V_108 ) ;
F_40 ( V_53 , V_102 ) ;
return 0 ;
}
void F_41 ( struct V_53 * V_53 )
{
T_8 V_102 ;
if ( V_103 . V_104 != V_105 )
return;
V_102 = F_42 ( V_53 ) ;
F_43 ( V_102 , 0 , 0 ) ;
}
void F_44 ( struct V_53 * V_53 )
{
T_8 V_102 ;
if ( V_103 . V_104 != V_105 )
return;
V_102 = F_42 ( V_53 ) ;
F_45 ( V_102 ) ;
}
static int F_46 ( struct V_49 * V_50 , T_16 V_94 ,
void * V_59 , int V_109 )
{
T_8 V_102 ;
T_14 V_110 ;
int V_44 ;
V_102 = F_42 ( V_50 -> V_53 ) ;
if ( V_102 == NULL )
return - 1 ;
V_44 = F_47 ( & V_110 , V_102 , V_50 ) ;
if ( V_44 )
F_36 ( V_44 ) ;
while ( ! V_44 && ( F_48 ( & V_110 ) > 0 ) && V_109 -- ) {
T_7 V_48 ;
F_49 ( & V_110 , V_111 , & V_48 ) ;
V_44 = V_48 ? F_34 ( V_48 , V_50 -> V_53 , V_94 , V_59 ) : 0 ;
}
return V_44 ;
}
int F_50 ( T_16 V_94 , void * V_59 ,
struct V_53 * V_53 ,
struct V_112 * V_40 , int V_109 )
{
T_2 V_48 ;
struct V_49 V_50 = {
. V_86 = V_40 ,
. V_53 = V_53 ,
. V_33 = V_53 -> V_113 -> V_33 ,
} ;
int V_44 ;
if ( ! V_40 -> V_88 . V_89 )
return - V_12 ;
V_44 = F_30 ( & V_48 , & V_40 -> V_88 , V_114 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_34 ( V_48 , V_53 , V_94 , V_59 ) ;
if ( V_44 )
return - V_107 ;
return -- V_109 > 0 ? F_46 ( & V_50 , V_94 , V_59 , V_109 ) : 0 ;
}
