char * F_1 ( char * V_1 , int V_2 , int V_3 )
{
int V_4 = 0 ;
if ( ! V_2 )
goto V_5;
* V_1 = '\0' ;
if ( V_3 ) {
if ( V_3 & V_6 ) {
snprintf ( V_1 , V_2 , L_1 ) ;
V_4 = 1 ;
}
if ( V_3 & V_7 ) {
snprintf ( V_1 , V_2 , L_2 , V_1 , ( V_4 ? L_3 : L_4 ) ,
L_5 ) ;
V_4 = 1 ;
}
} else {
snprintf ( V_1 , V_2 , L_6 ) ;
}
V_5:
return V_1 ;
}
static int F_2 ( unsigned int V_8 )
{
int V_9 = 0 ;
while ( V_8 ) {
V_8 = V_8 >> 1 ;
V_9 ++ ;
}
return V_9 ;
}
static void F_3 ( struct V_10 * V_11 )
{
V_11 -> V_12 = ( 1 << F_2 ( F_4 ( V_11 -> V_13 . V_14 ) - 1 ) ) - 1 ;
V_11 -> V_15 =
( 1 << F_2 ( F_4 ( V_11 -> V_13 . V_16 ) - 1 ) ) - 1 ;
V_11 -> V_17 =
( 1 << F_2 ( F_4 ( V_11 -> V_13 . V_18 ) - 1 ) ) - 1 ;
V_11 -> V_19 =
( 1 << F_2 ( F_4 ( V_11 -> V_13 . V_20 ) - 1 ) ) - 1 ;
}
static int F_5 ( void * * V_21 , void * V_22 ,
struct V_23 * V_9 )
{
F_6 ( L_7 , * V_21 , V_22 ) ;
F_7 ( V_21 , V_22 , ( 1 + V_9 -> V_24 . V_25 ) * sizeof( V_26 ) , V_27 ) ;
V_9 -> V_28 = F_8 ( V_21 ) ;
return 0 ;
V_27:
return - V_29 ;
}
static int F_9 ( void * * V_21 , void * V_22 ,
struct V_30 * V_9 )
{
int V_31 ;
F_6 ( L_8 , * V_21 , V_22 ) ;
V_9 -> V_32 = F_10 ( V_9 -> V_24 . V_25 , sizeof( V_26 ) , V_33 ) ;
if ( V_9 -> V_32 == NULL )
return - V_34 ;
V_9 -> V_35 = F_10 ( V_9 -> V_24 . V_25 , sizeof( V_26 ) , V_33 ) ;
if ( V_9 -> V_35 == NULL )
return - V_34 ;
F_7 ( V_21 , V_22 , 2 * V_9 -> V_24 . V_25 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_9 -> V_24 . V_25 ; V_31 ++ ) {
V_9 -> V_32 [ V_31 ] = F_8 ( V_21 ) ;
V_9 -> V_35 [ V_31 ] = F_8 ( V_21 ) ;
}
return 0 ;
V_27:
return - V_29 ;
}
static int F_11 ( void * * V_21 , void * V_22 ,
struct V_36 * V_9 )
{
int V_31 ;
F_6 ( L_9 , * V_21 , V_22 ) ;
F_12 ( V_21 , V_22 , V_9 -> V_37 , V_27 ) ;
V_9 -> V_38 = F_10 ( V_9 -> V_37 , sizeof( V_26 ) , V_33 ) ;
if ( V_9 -> V_38 == NULL )
return - V_34 ;
F_7 ( V_21 , V_22 , V_9 -> V_37 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_9 -> V_37 ; V_31 ++ )
V_9 -> V_38 [ V_31 ] = F_8 ( V_21 ) ;
return 0 ;
V_27:
return - V_29 ;
}
static int F_13 ( void * * V_21 , void * V_22 ,
struct V_39 * V_9 )
{
int V_31 ;
F_6 ( L_10 , * V_21 , V_22 ) ;
V_9 -> V_32 = F_10 ( V_9 -> V_24 . V_25 , sizeof( V_26 ) , V_33 ) ;
if ( V_9 -> V_32 == NULL )
return - V_34 ;
V_9 -> V_40 = F_10 ( V_9 -> V_24 . V_25 , sizeof( V_26 ) , V_33 ) ;
if ( V_9 -> V_40 == NULL )
return - V_34 ;
F_7 ( V_21 , V_22 , 2 * V_9 -> V_24 . V_25 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_9 -> V_24 . V_25 ; V_31 ++ ) {
V_9 -> V_32 [ V_31 ] = F_8 ( V_21 ) ;
V_9 -> V_40 [ V_31 ] = F_8 ( V_21 ) ;
}
return 0 ;
V_27:
return - V_29 ;
}
static struct V_41 * F_14 ( void * V_42 , void * V_22 )
{
struct V_41 * V_43 ;
int V_44 = - V_29 ;
int V_45 , V_31 ;
void * * V_21 = & V_42 ;
void * V_46 = V_42 ;
V_26 V_47 ;
F_6 ( L_11 , * V_21 , V_22 , ( int ) ( V_22 - * V_21 ) ) ;
V_43 = F_15 ( sizeof( * V_43 ) , V_33 ) ;
if ( V_43 == NULL )
return F_16 ( - V_34 ) ;
F_7 ( V_21 , V_22 , 4 * sizeof( V_26 ) , V_27 ) ;
V_47 = F_8 ( V_21 ) ;
if ( V_47 != V_48 ) {
F_17 ( L_12 ,
( unsigned int ) V_47 , ( unsigned int ) V_48 ) ;
goto V_27;
}
V_43 -> V_49 = F_8 ( V_21 ) ;
V_43 -> V_50 = F_8 ( V_21 ) ;
V_43 -> V_51 = F_8 ( V_21 ) ;
V_43 -> V_52 = F_10 ( V_43 -> V_49 , sizeof( * V_43 -> V_52 ) , V_33 ) ;
if ( V_43 -> V_52 == NULL )
goto V_53;
V_43 -> V_54 = F_10 ( V_43 -> V_50 , sizeof( * V_43 -> V_54 ) , V_33 ) ;
if ( V_43 -> V_54 == NULL )
goto V_53;
for ( V_45 = 0 ; V_45 < V_43 -> V_49 ; V_45 ++ ) {
int V_25 = 0 ;
V_26 V_55 ;
struct V_56 * V_9 ;
F_12 ( V_21 , V_22 , V_55 , V_27 ) ;
if ( V_55 == 0 ) {
V_43 -> V_52 [ V_45 ] = NULL ;
continue;
}
F_6 ( L_13 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
switch ( V_55 ) {
case V_57 :
V_25 = sizeof( struct V_23 ) ;
break;
case V_58 :
V_25 = sizeof( struct V_30 ) ;
break;
case V_59 :
V_25 = sizeof( struct V_36 ) ;
break;
case V_60 :
V_25 = sizeof( struct V_39 ) ;
break;
default:
V_44 = - V_29 ;
goto V_27;
}
F_18 ( V_25 == 0 ) ;
V_9 = V_43 -> V_52 [ V_45 ] = F_15 ( V_25 , V_33 ) ;
if ( V_9 == NULL )
goto V_53;
F_7 ( V_21 , V_22 , 4 * sizeof( V_26 ) , V_27 ) ;
V_9 -> V_61 = F_8 ( V_21 ) ;
V_9 -> type = F_19 ( V_21 ) ;
V_9 -> V_55 = F_20 ( V_21 ) ;
V_9 -> V_62 = F_20 ( V_21 ) ;
V_9 -> V_63 = F_8 ( V_21 ) ;
V_9 -> V_25 = F_8 ( V_21 ) ;
F_6 ( L_14 ,
V_9 -> V_25 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
V_9 -> V_64 = F_10 ( V_9 -> V_25 , sizeof( V_65 ) , V_33 ) ;
if ( V_9 -> V_64 == NULL )
goto V_53;
V_9 -> V_66 = F_10 ( V_9 -> V_25 , sizeof( V_26 ) , V_33 ) ;
if ( V_9 -> V_66 == NULL )
goto V_53;
V_9 -> V_67 = 0 ;
F_7 ( V_21 , V_22 , V_9 -> V_25 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_9 -> V_25 ; V_31 ++ )
V_9 -> V_64 [ V_31 ] = F_8 ( V_21 ) ;
switch ( V_9 -> V_55 ) {
case V_57 :
V_44 = F_5 ( V_21 , V_22 ,
(struct V_23 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_58 :
V_44 = F_9 ( V_21 , V_22 ,
(struct V_30 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_59 :
V_44 = F_11 ( V_21 , V_22 ,
(struct V_36 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_60 :
V_44 = F_13 ( V_21 , V_22 ,
(struct V_39 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
}
}
F_6 ( L_15 , V_43 -> V_54 ) ;
for ( V_45 = 0 ; V_45 < V_43 -> V_50 ; V_45 ++ ) {
V_26 V_68 ;
struct V_69 * V_70 ;
F_12 ( V_21 , V_22 , V_68 , V_27 ) ;
if ( ! V_68 ) {
F_6 ( L_16 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
V_43 -> V_54 [ V_45 ] = NULL ;
continue;
}
F_6 ( L_17 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
F_12 ( V_21 , V_22 , V_68 , V_27 ) ;
#if V_71 == 32
V_44 = - V_29 ;
if ( V_68 > ( V_72 - sizeof( * V_70 ) )
/ sizeof( struct V_73 ) )
goto V_27;
#endif
V_70 = V_43 -> V_54 [ V_45 ] = F_21 ( sizeof( * V_70 ) +
V_68 * sizeof( struct V_73 ) ,
V_33 ) ;
if ( V_70 == NULL )
goto V_53;
F_6 ( L_18 , V_45 , V_70 ) ;
V_70 -> V_2 = V_68 ;
F_22 ( V_21 , V_22 , & V_70 -> V_74 , 4 , V_27 ) ;
F_7 ( V_21 , V_22 , V_70 -> V_2 * 3 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_70 -> V_2 ; V_31 ++ ) {
V_70 -> V_75 [ V_31 ] . V_76 = F_8 ( V_21 ) ;
V_70 -> V_75 [ V_31 ] . V_77 = F_8 ( V_21 ) ;
V_70 -> V_75 [ V_31 ] . V_78 = F_8 ( V_21 ) ;
}
}
F_6 ( L_19 ) ;
return V_43 ;
V_53:
V_44 = - V_34 ;
V_27:
F_6 ( L_20 , V_44 ) ;
F_23 ( V_43 ) ;
return F_16 ( V_44 ) ;
}
static int F_24 ( struct V_79 V_80 , struct V_79 V_70 )
{
T_1 V_81 = * ( T_1 * ) & V_80 ;
T_1 V_9 = * ( T_1 * ) & V_70 ;
if ( V_81 < V_9 )
return - 1 ;
if ( V_81 > V_9 )
return 1 ;
return 0 ;
}
static int F_25 ( struct V_82 * V_83 ,
struct V_84 * V_85 )
{
struct V_86 * * V_21 = & V_85 -> V_86 ;
struct V_86 * V_87 = NULL ;
struct V_82 * V_88 = NULL ;
int V_43 ;
F_6 ( L_21 , * ( T_1 * ) & V_83 -> V_89 , V_83 ) ;
while ( * V_21 ) {
V_87 = * V_21 ;
V_88 = F_26 ( V_87 , struct V_82 , V_90 ) ;
V_43 = F_24 ( V_83 -> V_89 , V_88 -> V_89 ) ;
if ( V_43 < 0 )
V_21 = & ( * V_21 ) -> V_91 ;
else if ( V_43 > 0 )
V_21 = & ( * V_21 ) -> V_92 ;
else
return - V_93 ;
}
F_27 ( & V_83 -> V_90 , V_87 , V_21 ) ;
F_28 ( & V_83 -> V_90 , V_85 ) ;
return 0 ;
}
static struct V_82 * F_29 ( struct V_84 * V_85 ,
struct V_79 V_89 )
{
struct V_86 * V_94 = V_85 -> V_86 ;
struct V_82 * V_88 ;
int V_43 ;
while ( V_94 ) {
V_88 = F_26 ( V_94 , struct V_82 , V_90 ) ;
V_43 = F_24 ( V_89 , V_88 -> V_89 ) ;
if ( V_43 < 0 ) {
V_94 = V_94 -> V_91 ;
} else if ( V_43 > 0 ) {
V_94 = V_94 -> V_92 ;
} else {
F_6 ( L_22 ,
* ( T_1 * ) & V_89 , V_88 ) ;
return V_88 ;
}
}
return NULL ;
}
static int F_30 ( struct V_84 * V_85 , struct V_79 V_89 )
{
struct V_82 * V_88 = F_29 ( V_85 , V_89 ) ;
if ( V_88 ) {
F_6 ( L_23 , * ( T_1 * ) & V_89 , V_88 ) ;
F_31 ( & V_88 -> V_90 , V_85 ) ;
F_32 ( V_88 ) ;
return 0 ;
}
F_6 ( L_24 , * ( T_1 * ) & V_89 ) ;
return - V_95 ;
}
static int F_33 ( struct V_84 * V_85 , struct V_10 * V_83 )
{
struct V_86 * * V_21 = & V_85 -> V_86 ;
struct V_86 * V_87 = NULL ;
struct V_10 * V_11 = NULL ;
while ( * V_21 ) {
V_87 = * V_21 ;
V_11 = F_26 ( V_87 , struct V_10 , V_90 ) ;
if ( V_83 -> V_61 < V_11 -> V_61 )
V_21 = & ( * V_21 ) -> V_91 ;
else if ( V_83 -> V_61 > V_11 -> V_61 )
V_21 = & ( * V_21 ) -> V_92 ;
else
return - V_93 ;
}
F_27 ( & V_83 -> V_90 , V_87 , V_21 ) ;
F_28 ( & V_83 -> V_90 , V_85 ) ;
return 0 ;
}
static struct V_10 * F_34 ( struct V_84 * V_85 , int V_61 )
{
struct V_10 * V_11 ;
struct V_86 * V_94 = V_85 -> V_86 ;
while ( V_94 ) {
V_11 = F_26 ( V_94 , struct V_10 , V_90 ) ;
if ( V_61 < V_11 -> V_61 )
V_94 = V_94 -> V_91 ;
else if ( V_61 > V_11 -> V_61 )
V_94 = V_94 -> V_92 ;
else
return V_11 ;
}
return NULL ;
}
int F_35 ( struct V_96 * V_97 , const char * V_98 )
{
struct V_86 * V_99 ;
for ( V_99 = F_36 ( & V_97 -> V_100 ) ; V_99 ; V_99 = F_37 ( V_99 ) ) {
struct V_10 * V_11 =
F_26 ( V_99 , struct V_10 , V_90 ) ;
if ( V_11 -> V_98 && strcmp ( V_11 -> V_98 , V_98 ) == 0 )
return V_11 -> V_61 ;
}
return - V_95 ;
}
static void F_38 ( struct V_84 * V_85 , struct V_10 * V_11 )
{
F_31 ( & V_11 -> V_90 , V_85 ) ;
F_32 ( V_11 -> V_98 ) ;
F_32 ( V_11 ) ;
}
static int F_39 ( void * * V_21 , void * V_22 , struct V_10 * V_11 )
{
unsigned int V_94 , V_101 ;
F_40 ( V_21 , & V_11 -> V_13 , sizeof( V_11 -> V_13 ) ) ;
F_3 ( V_11 ) ;
V_94 = F_4 ( V_11 -> V_13 . V_102 ) ;
while ( V_94 -- ) {
F_7 ( V_21 , V_22 , sizeof( T_1 ) + 1 + sizeof( T_1 ) +
sizeof( struct V_103 ) , V_27 ) ;
* V_21 += sizeof( T_1 ) +
1 + sizeof( T_1 ) +
sizeof( struct V_103 ) ;
V_101 = F_8 ( V_21 ) ;
* V_21 += V_101 ;
}
* V_21 += F_4 ( V_11 -> V_13 . V_104 ) * sizeof( T_1 ) * 2 ;
return 0 ;
V_27:
return - V_29 ;
}
static int F_41 ( void * * V_21 , void * V_22 , struct V_96 * V_97 )
{
struct V_10 * V_11 ;
V_26 V_105 , V_2 , V_106 ;
F_12 ( V_21 , V_22 , V_105 , V_27 ) ;
F_6 ( L_25 , V_105 ) ;
while ( V_105 -- ) {
F_12 ( V_21 , V_22 , V_106 , V_27 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
F_6 ( L_26 , V_106 , V_2 ) ;
V_11 = F_34 ( & V_97 -> V_100 , V_106 ) ;
if ( V_11 ) {
F_32 ( V_11 -> V_98 ) ;
V_11 -> V_98 = F_21 ( V_2 + 1 , V_33 ) ;
if ( V_11 -> V_98 ) {
memcpy ( V_11 -> V_98 , * V_21 , V_2 ) ;
V_11 -> V_98 [ V_2 ] = '\0' ;
F_6 ( L_27 , V_11 -> V_98 ) ;
}
}
* V_21 += V_2 ;
}
return 0 ;
V_27:
return - V_29 ;
}
void F_42 ( struct V_96 * V_97 )
{
F_6 ( L_28 , V_97 ) ;
if ( V_97 -> V_107 )
F_23 ( V_97 -> V_107 ) ;
while ( ! F_43 ( & V_97 -> V_108 ) ) {
struct V_82 * V_88 =
F_26 ( F_36 ( & V_97 -> V_108 ) ,
struct V_82 , V_90 ) ;
F_31 ( & V_88 -> V_90 , & V_97 -> V_108 ) ;
F_32 ( V_88 ) ;
}
while ( ! F_43 ( & V_97 -> V_100 ) ) {
struct V_10 * V_11 =
F_26 ( F_36 ( & V_97 -> V_100 ) ,
struct V_10 , V_90 ) ;
F_38 ( & V_97 -> V_100 , V_11 ) ;
}
F_32 ( V_97 -> V_109 ) ;
F_32 ( V_97 -> V_110 ) ;
F_32 ( V_97 -> V_111 ) ;
F_32 ( V_97 ) ;
}
static int F_44 ( struct V_96 * V_97 , int V_112 )
{
T_2 * V_3 ;
struct V_113 * V_114 ;
V_26 * V_63 ;
V_3 = F_10 ( V_112 , sizeof( * V_3 ) , V_33 ) ;
V_114 = F_10 ( V_112 , sizeof( * V_114 ) , V_33 ) ;
V_63 = F_10 ( V_112 , sizeof( * V_63 ) , V_33 ) ;
if ( V_3 == NULL || V_114 == NULL || V_63 == NULL ) {
F_32 ( V_3 ) ;
F_32 ( V_114 ) ;
F_32 ( V_63 ) ;
return - V_34 ;
}
if ( V_97 -> V_109 ) {
memcpy ( V_3 , V_97 -> V_109 , V_97 -> V_115 * sizeof( * V_3 ) ) ;
memcpy ( V_114 , V_97 -> V_111 , V_97 -> V_115 * sizeof( * V_114 ) ) ;
memcpy ( V_63 , V_97 -> V_110 , V_97 -> V_115 * sizeof( * V_63 ) ) ;
F_32 ( V_97 -> V_109 ) ;
F_32 ( V_97 -> V_111 ) ;
F_32 ( V_97 -> V_110 ) ;
}
V_97 -> V_109 = V_3 ;
V_97 -> V_110 = V_63 ;
V_97 -> V_111 = V_114 ;
V_97 -> V_115 = V_112 ;
return 0 ;
}
struct V_96 * F_45 ( void * * V_21 , void * V_22 )
{
struct V_96 * V_97 ;
T_3 V_116 ;
V_26 V_2 , V_112 , V_45 ;
T_2 V_117 ;
int V_44 = - V_29 ;
void * V_46 = * V_21 ;
struct V_10 * V_11 ;
F_6 ( L_29 , * V_21 , V_22 , ( int ) ( V_22 - * V_21 ) ) ;
V_97 = F_15 ( sizeof( * V_97 ) , V_33 ) ;
if ( V_97 == NULL )
return F_16 ( - V_34 ) ;
V_97 -> V_108 = V_118 ;
F_46 ( V_21 , V_22 , V_116 , V_27 ) ;
if ( V_116 > V_119 ) {
F_47 ( L_30 , V_116 ,
V_119 ) ;
goto V_27;
}
F_7 ( V_21 , V_22 , 2 * sizeof( T_1 ) + 6 * sizeof( V_26 ) , V_27 ) ;
F_40 ( V_21 , & V_97 -> V_120 , sizeof( V_97 -> V_120 ) ) ;
V_97 -> V_121 = F_8 ( V_21 ) ;
F_40 ( V_21 , & V_97 -> V_122 , sizeof( V_97 -> V_122 ) ) ;
F_40 ( V_21 , & V_97 -> V_123 , sizeof( V_97 -> V_123 ) ) ;
F_12 ( V_21 , V_22 , V_112 , V_27 ) ;
while ( V_112 -- ) {
F_7 ( V_21 , V_22 , 4 + 1 + sizeof( V_11 -> V_13 ) , V_27 ) ;
V_11 = F_15 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 )
goto V_27;
V_11 -> V_61 = F_8 ( V_21 ) ;
V_117 = F_20 ( V_21 ) ;
if ( V_117 > V_124 ) {
F_47 ( L_31 ,
V_117 , V_124 ) ;
F_32 ( V_11 ) ;
goto V_27;
}
V_44 = F_39 ( V_21 , V_22 , V_11 ) ;
if ( V_44 < 0 ) {
F_32 ( V_11 ) ;
goto V_27;
}
F_33 ( & V_97 -> V_100 , V_11 ) ;
}
if ( V_116 >= 5 && F_41 ( V_21 , V_22 , V_97 ) < 0 )
goto V_27;
F_12 ( V_21 , V_22 , V_97 -> V_125 , V_27 ) ;
F_12 ( V_21 , V_22 , V_97 -> V_126 , V_27 ) ;
V_112 = F_8 ( V_21 ) ;
V_44 = F_44 ( V_97 , V_112 ) ;
if ( V_44 < 0 )
goto V_27;
F_6 ( L_32 , V_97 -> V_115 ) ;
V_44 = - V_29 ;
F_7 ( V_21 , V_22 , 3 * sizeof( V_26 ) +
V_97 -> V_115 * ( 1 + sizeof( * V_97 -> V_110 ) +
sizeof( * V_97 -> V_111 ) ) , V_27 ) ;
* V_21 += 4 ;
F_40 ( V_21 , V_97 -> V_109 , V_97 -> V_115 ) ;
* V_21 += 4 ;
for ( V_45 = 0 ; V_45 < V_97 -> V_115 ; V_45 ++ )
V_97 -> V_110 [ V_45 ] = F_8 ( V_21 ) ;
* V_21 += 4 ;
F_40 ( V_21 , V_97 -> V_111 , V_97 -> V_115 * sizeof( * V_97 -> V_111 ) ) ;
for ( V_45 = 0 ; V_45 < V_97 -> V_115 ; V_45 ++ )
F_48 ( & V_97 -> V_111 [ V_45 ] ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
for ( V_45 = 0 ; V_45 < V_2 ; V_45 ++ ) {
int V_94 , V_31 ;
struct V_79 V_89 ;
struct V_82 * V_88 ;
F_7 ( V_21 , V_22 , sizeof( V_26 ) + sizeof( T_1 ) , V_27 ) ;
F_40 ( V_21 , & V_89 , sizeof( V_89 ) ) ;
V_94 = F_8 ( V_21 ) ;
F_7 ( V_21 , V_22 , V_94 * sizeof( V_26 ) , V_27 ) ;
V_44 = - V_34 ;
V_88 = F_21 ( sizeof( * V_88 ) + V_94 * sizeof( V_26 ) , V_33 ) ;
if ( ! V_88 )
goto V_27;
V_88 -> V_89 = V_89 ;
V_88 -> V_2 = V_94 ;
for ( V_31 = 0 ; V_31 < V_94 ; V_31 ++ )
V_88 -> V_127 [ V_31 ] = F_8 ( V_21 ) ;
V_44 = F_25 ( V_88 , & V_97 -> V_108 ) ;
if ( V_44 )
goto V_27;
F_6 ( L_33 , * ( T_1 * ) & V_89 , V_2 ) ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
F_6 ( L_34 , V_2 ,
( int ) ( * V_21 - V_46 ) ) ;
F_7 ( V_21 , V_22 , V_2 , V_27 ) ;
V_97 -> V_107 = F_14 ( * V_21 , V_22 ) ;
* V_21 += V_2 ;
if ( F_49 ( V_97 -> V_107 ) ) {
V_44 = F_50 ( V_97 -> V_107 ) ;
V_97 -> V_107 = NULL ;
goto V_27;
}
* V_21 = V_22 ;
F_6 ( L_35 , * V_21 , V_22 ) ;
return V_97 ;
V_27:
F_6 ( L_36 ) ;
F_42 ( V_97 ) ;
return F_16 ( V_44 ) ;
}
struct V_96 * F_51 ( void * * V_21 , void * V_22 ,
struct V_96 * V_97 ,
struct V_128 * V_129 )
{
struct V_41 * V_130 = NULL ;
struct V_131 V_120 ;
V_26 V_121 = 0 ;
struct V_103 V_123 ;
V_26 V_2 , V_106 ;
V_65 V_132 , V_133 , V_112 ;
void * V_46 = * V_21 ;
int V_44 = - V_29 ;
T_3 V_116 ;
F_46 ( V_21 , V_22 , V_116 , V_27 ) ;
if ( V_116 > V_134 ) {
F_47 ( L_37 , V_116 ,
V_134 ) ;
goto V_27;
}
F_7 ( V_21 , V_22 , sizeof( V_120 ) + sizeof( V_123 ) + 2 * sizeof( V_26 ) ,
V_27 ) ;
F_40 ( V_21 , & V_120 , sizeof( V_120 ) ) ;
V_121 = F_8 ( V_21 ) ;
F_18 ( V_121 != V_97 -> V_121 + 1 ) ;
F_40 ( V_21 , & V_123 , sizeof( V_123 ) ) ;
V_132 = F_8 ( V_21 ) ;
V_133 = F_8 ( V_21 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
if ( V_2 > 0 ) {
F_6 ( L_38 ,
V_2 , * V_21 , V_22 ) ;
return F_45 ( V_21 , F_52 ( * V_21 + V_2 , V_22 ) ) ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
if ( V_2 > 0 ) {
F_6 ( L_39 ,
V_2 , * V_21 , V_22 ) ;
V_130 = F_14 ( * V_21 , F_52 ( * V_21 + V_2 , V_22 ) ) ;
if ( F_49 ( V_130 ) )
return F_53 ( V_130 ) ;
* V_21 += V_2 ;
}
if ( V_133 >= 0 )
V_97 -> V_126 = V_133 ;
if ( V_132 >= 0 )
V_97 -> V_125 = V_132 ;
F_7 ( V_21 , V_22 , 5 * sizeof( V_26 ) , V_27 ) ;
V_112 = F_8 ( V_21 ) ;
if ( V_112 >= 0 ) {
V_44 = F_44 ( V_97 , V_112 ) ;
if ( V_44 < 0 )
goto V_27;
}
V_97 -> V_121 ++ ;
V_97 -> V_123 = V_123 ;
if ( V_130 ) {
if ( V_97 -> V_107 )
F_23 ( V_97 -> V_107 ) ;
V_97 -> V_107 = V_130 ;
V_130 = NULL ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
T_4 V_117 ;
struct V_10 * V_11 ;
F_12 ( V_21 , V_22 , V_106 , V_27 ) ;
F_7 ( V_21 , V_22 , 1 + sizeof( V_11 -> V_13 ) , V_27 ) ;
V_117 = F_20 ( V_21 ) ;
if ( V_117 > V_124 ) {
F_47 ( L_31 ,
V_117 , V_124 ) ;
goto V_27;
}
V_11 = F_34 ( & V_97 -> V_100 , V_106 ) ;
if ( ! V_11 ) {
V_11 = F_15 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 ) {
V_44 = - V_34 ;
goto V_27;
}
V_11 -> V_61 = V_106 ;
F_33 ( & V_97 -> V_100 , V_11 ) ;
}
V_44 = F_39 ( V_21 , V_22 , V_11 ) ;
if ( V_44 < 0 )
goto V_27;
}
if ( V_116 >= 5 && F_41 ( V_21 , V_22 , V_97 ) < 0 )
goto V_27;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
struct V_10 * V_11 ;
F_12 ( V_21 , V_22 , V_106 , V_27 ) ;
V_11 = F_34 ( & V_97 -> V_100 , V_106 ) ;
if ( V_11 )
F_38 ( & V_97 -> V_100 , V_11 ) ;
}
V_44 = - V_29 ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_135 ;
struct V_113 V_114 ;
F_12 ( V_21 , V_22 , V_135 , V_27 ) ;
F_22 ( V_21 , V_22 , & V_114 , sizeof( V_114 ) , V_27 ) ;
F_48 ( & V_114 ) ;
F_54 ( L_40 , V_135 ) ;
F_18 ( V_135 >= V_97 -> V_115 ) ;
V_97 -> V_109 [ V_135 ] |= V_7 ;
V_97 -> V_111 [ V_135 ] = V_114 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_135 ;
T_2 V_136 ;
F_12 ( V_21 , V_22 , V_135 , V_27 ) ;
V_136 = * * ( T_2 * * ) V_21 ;
( * V_21 ) ++ ;
if ( V_136 == 0 )
V_136 = V_7 ;
if ( V_136 & V_7 )
F_54 ( L_41 , V_135 ) ;
if ( V_135 < V_97 -> V_115 )
V_97 -> V_109 [ V_135 ] ^= V_136 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_135 , V_137 ;
F_7 ( V_21 , V_22 , sizeof( V_26 ) * 2 , V_27 ) ;
V_135 = F_8 ( V_21 ) ;
V_137 = F_8 ( V_21 ) ;
F_54 ( L_42 , V_135 , V_137 ,
V_137 == V_138 ? L_43 :
( V_137 == V_139 ? L_44 : L_4 ) ) ;
if ( V_135 < V_97 -> V_115 )
V_97 -> V_110 [ V_135 ] = V_137 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
struct V_82 * V_88 ;
int V_31 ;
struct V_79 V_89 ;
V_26 V_140 ;
F_7 ( V_21 , V_22 , sizeof( T_1 ) + sizeof( V_26 ) , V_27 ) ;
F_40 ( V_21 , & V_89 , sizeof( V_89 ) ) ;
V_140 = F_8 ( V_21 ) ;
if ( V_140 ) {
F_7 ( V_21 , V_22 , V_140 * sizeof( V_26 ) , V_27 ) ;
( void ) F_30 ( & V_97 -> V_108 , V_89 ) ;
V_88 = F_21 ( sizeof( * V_88 ) + sizeof( V_26 ) * V_140 , V_33 ) ;
if ( ! V_88 ) {
V_44 = - V_34 ;
goto V_27;
}
V_88 -> V_89 = V_89 ;
V_88 -> V_2 = V_140 ;
for ( V_31 = 0 ; V_31 < V_140 ; V_31 ++ )
V_88 -> V_127 [ V_31 ] = F_8 ( V_21 ) ;
V_44 = F_25 ( V_88 , & V_97 -> V_108 ) ;
if ( V_44 ) {
F_32 ( V_88 ) ;
goto V_27;
}
F_6 ( L_33 , * ( T_1 * ) & V_89 ,
V_140 ) ;
} else {
F_30 ( & V_97 -> V_108 , V_89 ) ;
}
}
* V_21 = V_22 ;
return V_97 ;
V_27:
F_17 ( L_45 ,
V_121 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_46 , V_22 ) ;
F_55 ( V_141 , L_46 ,
V_142 , 16 , 1 ,
V_46 , V_22 - V_46 , true ) ;
if ( V_130 )
F_23 ( V_130 ) ;
return F_16 ( V_44 ) ;
}
void F_56 ( struct V_143 * V_144 ,
T_1 V_137 , T_1 * V_145 ,
T_1 * V_146 ,
T_1 * V_147 , T_1 * V_148 )
{
V_26 V_149 = F_4 ( V_144 -> V_150 ) ;
V_26 V_151 = F_4 ( V_144 -> V_152 ) ;
V_26 V_153 = F_4 ( V_144 -> V_154 ) ;
V_26 V_155 , V_156 , V_157 , V_158 ;
V_26 V_159 ;
T_1 V_8 , V_160 ;
F_6 ( L_47 , V_137 , * V_145 ,
V_149 , V_151 ) ;
V_159 = V_149 / V_151 ;
F_6 ( L_48 , V_149 , V_151 ,
V_159 ) ;
F_18 ( ( V_151 & ~ V_161 ) != 0 ) ;
V_8 = V_137 ;
F_57 ( V_8 , V_151 ) ;
V_155 = V_8 ;
F_6 ( L_49 , V_137 , V_151 , V_155 ) ;
V_156 = V_155 / V_153 ;
V_157 = V_155 % V_153 ;
V_158 = V_156 / V_159 ;
* V_146 = V_158 * V_153 + V_157 ;
F_6 ( L_50 , V_158 , V_153 , ( unsigned int ) * V_146 ) ;
V_8 = V_137 ;
V_160 = F_57 ( V_8 , V_151 ) ;
* V_147 = V_160 + ( V_156 % V_159 ) * V_151 ;
* V_148 = F_58 ( T_1 , * V_145 , V_151 - V_160 ) ;
* V_145 = * V_148 ;
F_6 ( L_51 , * V_147 , * V_148 ) ;
}
int F_59 ( struct V_162 * V_163 ,
const char * V_164 ,
struct V_143 * V_165 ,
struct V_96 * V_166 )
{
unsigned int V_105 , V_167 ;
struct V_79 V_89 ;
int V_168 = F_4 ( V_165 -> V_169 ) ;
struct V_10 * V_106 ;
unsigned int V_170 ;
F_18 ( ! V_166 ) ;
V_106 = F_34 ( & V_166 -> V_100 , V_168 ) ;
if ( ! V_106 )
return - V_171 ;
V_170 = F_60 ( V_106 -> V_13 . V_172 , V_164 , strlen ( V_164 ) ) ;
V_105 = F_4 ( V_106 -> V_13 . V_14 ) ;
V_167 = V_106 -> V_12 ;
V_89 . V_170 = F_61 ( V_170 ) ;
V_89 . V_173 = F_61 ( - 1 ) ;
V_89 . V_106 = V_165 -> V_169 ;
F_6 ( L_52 , V_164 , V_168 , V_170 ) ;
V_163 -> V_174 = V_89 ;
V_163 -> V_175 = V_165 -> V_176 ;
return 0 ;
}
static int * F_62 ( struct V_96 * V_166 , struct V_79 V_89 ,
int * V_127 , int * V_105 )
{
struct V_82 * V_88 ;
struct V_10 * V_106 ;
int V_177 ;
unsigned int V_168 , V_170 , V_178 , V_8 , V_70 ;
V_168 = F_4 ( V_89 . V_106 ) ;
V_170 = F_63 ( V_89 . V_170 ) ;
V_106 = F_34 ( & V_166 -> V_100 , V_168 ) ;
if ( ! V_106 )
return NULL ;
V_8 = F_64 ( V_170 , F_4 ( V_106 -> V_13 . V_14 ) ,
V_106 -> V_15 ) ;
V_89 . V_170 = F_61 ( V_8 ) ;
V_88 = F_29 ( & V_166 -> V_108 , V_89 ) ;
if ( V_88 ) {
* V_105 = V_88 -> V_2 ;
return V_88 -> V_127 ;
}
V_177 = F_65 ( V_166 -> V_107 , V_106 -> V_13 . V_179 ,
V_106 -> V_13 . type , V_106 -> V_13 . V_25 ) ;
if ( V_177 < 0 ) {
F_17 ( L_53 ,
V_168 , V_106 -> V_13 . V_179 , V_106 -> V_13 . type ,
V_106 -> V_13 . V_25 ) ;
return NULL ;
}
V_178 = F_64 ( V_170 ,
F_4 ( V_106 -> V_13 . V_16 ) ,
V_106 -> V_15 ) ;
V_178 += V_168 ;
V_70 = F_66 ( V_166 -> V_107 , V_177 , V_178 , V_127 ,
F_58 ( int , V_106 -> V_13 . V_25 , * V_105 ) ,
V_166 -> V_110 ) ;
if ( V_70 < 0 ) {
F_17 ( L_54
L_55 , V_70 , V_168 , V_106 -> V_13 . V_179 ,
V_106 -> V_13 . type , V_106 -> V_13 . V_25 ) ;
return NULL ;
}
* V_105 = V_70 ;
return V_127 ;
}
int F_67 ( struct V_96 * V_166 , struct V_79 V_89 ,
int * V_180 )
{
int V_181 [ V_182 ] , * V_127 ;
int V_45 , V_183 , V_105 = V_182 ;
V_127 = F_62 ( V_166 , V_89 , V_181 , & V_105 ) ;
if ( ! V_127 )
return - 1 ;
V_183 = 0 ;
for ( V_45 = 0 ; V_45 < V_105 ; V_45 ++ )
if ( F_68 ( V_166 , V_127 [ V_45 ] ) )
V_180 [ V_183 ++ ] = V_127 [ V_45 ] ;
return V_183 ;
}
int F_69 ( struct V_96 * V_166 , struct V_79 V_89 )
{
int V_181 [ V_182 ] , * V_127 ;
int V_45 , V_105 = V_182 ;
V_127 = F_62 ( V_166 , V_89 , V_181 , & V_105 ) ;
if ( ! V_127 )
return - 1 ;
for ( V_45 = 0 ; V_45 < V_105 ; V_45 ++ )
if ( F_68 ( V_166 , V_127 [ V_45 ] ) )
return V_127 [ V_45 ] ;
return - 1 ;
}
