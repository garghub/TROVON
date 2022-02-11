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
static int F_8 ( struct V_29 * V_29 , struct V_30 * V_30 ,
T_2 V_26 , T_2 * V_31 , T_2 * V_32 ,
T_2 * V_33 )
{
struct V_34 V_35 ;
T_1 * V_36 = ( T_1 * ) & V_35 . V_36 ;
T_1 * V_2 = ( T_1 * ) & V_35 . V_37 ;
T_6 V_38 ;
V_38 = F_9 ( V_29 , V_30 , V_26 ,
( T_1 * ) & V_35 , sizeof( V_35 ) ) ;
if ( V_38 != sizeof( V_35 ) )
return - V_12 ;
F_10 ( V_36 , V_2 , V_35 . V_39 ) ;
* V_33 = F_10 ( V_36 , V_2 , V_35 . V_40 ) ;
* V_32 = V_26 ;
* V_31 = ( V_36 - ( T_1 * ) & V_35 ) + V_26 ;
return 0 ;
}
static int F_11 ( struct V_29 * V_29 , struct V_30 * V_30 ,
T_2 * V_31 , T_2 * V_32 ,
T_2 * V_33 )
{
int V_41 = - V_12 , V_21 ;
T_2 V_26 ;
V_21 = F_12 ( V_29 , V_30 ) ;
if ( V_21 < 0 )
return - V_12 ;
V_26 = F_3 ( V_21 , L_1 ) ;
if ( V_26 )
V_41 = F_8 ( V_29 , V_30 , V_26 ,
V_31 , V_32 ,
V_33 ) ;
return V_41 ;
}
static int F_13 ( struct V_29 * V_29 ,
struct V_30 * V_30 , T_2 * V_26 )
{
int V_21 = F_12 ( V_29 , V_30 ) ;
if ( V_21 < 0 )
return - V_12 ;
* V_26 = F_3 ( V_21 , L_2 ) ;
if ( * V_26 )
return 0 ;
return - V_12 ;
}
static struct V_42 * F_14 ( T_7 V_43 , struct V_44 * V_45 )
{
struct V_46 V_47 ;
F_15 ( V_45 -> V_48 , V_45 -> V_30 , V_49 ,
V_50 , V_43 , & V_47 ) ;
return V_47 . V_42 ;
}
static int
F_16 ( T_8 V_51 , T_7 V_43 , T_9 * V_52 ,
int V_53 , void * V_54 )
{
struct V_44 * V_45 = V_54 ;
struct V_42 * V_42 ;
T_10 V_55 ;
T_2 V_31 , V_32 , V_33 ;
V_42 = F_14 ( V_43 , V_45 ) ;
if ( ! V_42 || ! V_42 -> V_29 )
return - V_12 ;
F_17 ( L_3 , V_42 -> V_29 -> V_22 ) ;
if ( ! F_11 ( V_42 -> V_29 , V_45 -> V_30 ,
& V_31 , & V_32 , & V_33 ) ) {
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = V_57 ;
V_55 . V_58 = V_42 -> V_59 ;
V_55 . V_60 = V_42 -> V_2 ;
V_55 . V_61 . V_62 . V_32 = V_42 -> V_59 + V_32 ;
V_55 . V_61 . V_62 . V_31 = V_42 -> V_59 + V_31 ;
V_55 . V_61 . V_62 . V_63 = V_33 * sizeof( struct V_64 )
/ sizeof( T_7 ) ;
return F_18 ( V_51 , V_43 , & V_55 , V_52 ,
V_53 , V_54 ) ;
}
#ifndef F_19
if ( ! F_13 ( V_42 -> V_29 , V_45 -> V_30 , & V_32 ) ) {
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
if ( F_20 ( 0 , & V_55 , V_43 , 0 , V_42 -> V_29 -> V_22 ,
V_42 -> V_59 , V_42 -> V_2 ) )
return F_18 ( V_51 , V_43 , & V_55 , V_52 ,
V_53 , V_54 ) ;
}
#endif
return - V_12 ;
}
static int F_21 ( T_8 T_11 V_51 ,
T_12 T_11 V_65 ,
T_13 T_11 * V_3 ,
int T_11 V_66 ,
void T_11 * V_54 )
{
F_22 ( L_4 ) ;
return - V_67 ;
}
static int F_23 ( T_8 T_11 V_51 ,
T_7 T_11 * V_68 ,
void T_11 * V_54 )
{
return - V_69 ;
}
static int F_24 ( T_8 T_11 V_51 ,
T_14 T_11 * V_70 ,
void T_11 * V_54 )
{
F_22 ( L_5 ) ;
return - V_67 ;
}
static int
F_25 ( T_8 T_11 V_51 ,
T_7 T_11 V_71 ,
char T_11 * V_72 , T_15 T_11 V_73 ,
T_7 T_11 * V_74 , void T_11 * V_54 )
{
F_22 ( L_6 ) ;
return - V_67 ;
}
static int F_26 ( struct V_44 * V_45 , T_7 V_71 ,
T_7 * V_37 )
{
struct V_46 V_47 ;
T_6 V_75 ;
F_15 ( V_45 -> V_48 , V_45 -> V_30 , V_49 ,
V_50 , V_71 , & V_47 ) ;
if ( ! V_47 . V_42 ) {
F_17 ( L_7 , ( unsigned long ) V_71 ) ;
return - 1 ;
}
if ( ! V_47 . V_42 -> V_29 )
return - 1 ;
V_75 = F_27 ( V_47 . V_42 -> V_29 , V_47 . V_42 , V_45 -> V_30 ,
V_71 , ( T_1 * ) V_37 , sizeof( * V_37 ) ) ;
return ! ( V_75 == sizeof( * V_37 ) ) ;
}
static int F_28 ( T_8 T_11 V_51 ,
T_7 V_71 , T_7 * V_76 ,
int V_66 , void * V_54 )
{
struct V_44 * V_45 = V_54 ;
struct V_77 * V_78 = & V_45 -> V_79 -> V_80 ;
T_2 V_59 , V_2 ;
int V_26 ;
int V_41 ;
if ( V_66 || ! V_78 || ! V_45 -> V_79 -> V_81 . V_82 ) {
* V_76 = 0 ;
return 0 ;
}
V_41 = F_29 ( & V_59 , & V_45 -> V_79 -> V_81 , V_83 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_59 + V_78 -> V_75 ;
if ( V_71 + sizeof( T_7 ) < V_71 )
return - V_12 ;
if ( V_71 < V_59 || V_71 + sizeof( T_7 ) >= V_2 ) {
V_41 = F_26 ( V_45 , V_71 , V_76 ) ;
if ( V_41 ) {
F_17 ( L_8
L_9 V_84 L_10 V_84 L_11 ,
( void * ) V_71 , V_59 , V_2 ) ;
* V_76 = 0 ;
return V_41 ;
}
return 0 ;
}
V_26 = V_71 - V_59 ;
* V_76 = * ( T_7 * ) & V_78 -> V_37 [ V_26 ] ;
F_17 ( L_12 ,
( void * ) V_71 , ( unsigned long ) * V_76 , V_26 ) ;
return 0 ;
}
static int F_30 ( T_8 T_11 V_51 ,
T_12 V_85 , T_7 * V_76 ,
int V_66 , void * V_54 )
{
struct V_44 * V_45 = V_54 ;
int V_86 , V_41 ;
T_2 V_3 ;
if ( V_66 ) {
F_22 ( L_13 , V_85 ) ;
return 0 ;
}
if ( ! V_45 -> V_79 -> V_81 . V_82 ) {
* V_76 = 0 ;
return 0 ;
}
V_86 = F_31 ( V_85 ) ;
if ( V_86 < 0 )
return - V_12 ;
V_41 = F_29 ( & V_3 , & V_45 -> V_79 -> V_81 , V_86 ) ;
if ( V_41 ) {
F_22 ( L_14 , V_85 ) ;
return V_41 ;
}
* V_76 = ( T_7 ) V_3 ;
F_17 ( L_15 , V_85 , ( unsigned long ) * V_76 ) ;
return 0 ;
}
static void F_32 ( T_8 T_11 V_51 ,
T_9 * V_52 T_11 ,
void * V_54 T_11 )
{
F_17 ( L_16 ) ;
}
static int F_33 ( T_2 V_43 , struct V_48 * V_48 , struct V_30 * V_30 ,
T_16 V_87 , void * V_54 )
{
struct V_88 V_89 ;
struct V_46 V_47 ;
F_34 ( V_48 , V_30 ,
V_49 ,
V_50 , V_43 , & V_47 ) ;
V_89 . V_43 = V_43 ;
V_89 . V_42 = V_47 . V_42 ;
V_89 . V_90 = V_47 . V_90 ;
F_17 ( L_17 V_84 L_18 V_84 L_19 ,
V_47 . V_90 ? V_47 . V_90 -> V_22 : L_20 ,
V_43 ,
V_47 . V_42 ? V_47 . V_42 -> V_91 ( V_47 . V_42 , V_43 ) : ( T_2 ) 0 ) ;
return V_87 ( & V_89 , V_54 ) ;
}
static void F_35 ( int V_92 )
{
switch ( V_92 ) {
case V_67 :
F_22 ( L_21 ) ;
break;
case V_93 :
F_22 ( L_22 ) ;
break;
case V_94 :
F_22 ( L_23 ) ;
break;
default:
break;
}
}
static int F_36 ( struct V_44 * V_45 , T_16 V_87 ,
void * V_54 , int V_95 )
{
T_8 V_96 ;
T_14 V_97 ;
int V_41 ;
V_96 = F_37 ( & V_98 , 0 ) ;
if ( ! V_96 ) {
F_22 ( L_24 ) ;
return - V_99 ;
}
V_41 = F_38 ( & V_97 , V_96 , V_45 ) ;
if ( V_41 )
F_35 ( V_41 ) ;
while ( ! V_41 && ( F_39 ( & V_97 ) > 0 ) && V_95 -- ) {
T_7 V_43 ;
F_40 ( & V_97 , V_100 , & V_43 ) ;
V_41 = V_43 ? F_33 ( V_43 , V_45 -> V_48 , V_45 -> V_30 , V_87 , V_54 ) : 0 ;
}
F_41 ( V_96 ) ;
return V_41 ;
}
int F_42 ( T_16 V_87 , void * V_54 ,
struct V_30 * V_30 , struct V_48 * V_48 ,
struct V_101 * V_37 , int V_95 )
{
T_2 V_43 ;
struct V_44 V_45 = {
. V_79 = V_37 ,
. V_48 = V_48 ,
. V_30 = V_30 ,
} ;
int V_41 ;
if ( ! V_37 -> V_81 . V_82 )
return - V_12 ;
V_41 = F_29 ( & V_43 , & V_37 -> V_81 , V_102 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_33 ( V_43 , V_48 , V_30 , V_87 , V_54 ) ;
if ( V_41 )
return - V_99 ;
return -- V_95 > 0 ? F_36 ( & V_45 , V_87 , V_54 , V_95 ) : 0 ;
}
