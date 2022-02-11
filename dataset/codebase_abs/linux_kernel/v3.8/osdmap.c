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
static int F_14 ( void * * V_21 , void * V_22 )
{
int V_2 ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
int strlen ;
* V_21 += sizeof( V_26 ) ;
F_12 ( V_21 , V_22 , strlen , V_27 ) ;
* V_21 += strlen ;
}
return 0 ;
V_27:
return - V_29 ;
}
static struct V_41 * F_15 ( void * V_42 , void * V_22 )
{
struct V_41 * V_43 ;
int V_44 = - V_29 ;
int V_45 , V_31 ;
void * * V_21 = & V_42 ;
void * V_46 = V_42 ;
V_26 V_47 ;
V_26 V_48 ;
F_6 ( L_11 , * V_21 , V_22 , ( int ) ( V_22 - * V_21 ) ) ;
V_43 = F_16 ( sizeof( * V_43 ) , V_33 ) ;
if ( V_43 == NULL )
return F_17 ( - V_34 ) ;
V_43 -> V_49 = 2 ;
V_43 -> V_50 = 5 ;
V_43 -> V_51 = 19 ;
F_7 ( V_21 , V_22 , 4 * sizeof( V_26 ) , V_27 ) ;
V_47 = F_8 ( V_21 ) ;
if ( V_47 != V_52 ) {
F_18 ( L_12 ,
( unsigned int ) V_47 , ( unsigned int ) V_52 ) ;
goto V_27;
}
V_43 -> V_53 = F_8 ( V_21 ) ;
V_43 -> V_54 = F_8 ( V_21 ) ;
V_43 -> V_55 = F_8 ( V_21 ) ;
V_43 -> V_56 = F_10 ( V_43 -> V_53 , sizeof( * V_43 -> V_56 ) , V_33 ) ;
if ( V_43 -> V_56 == NULL )
goto V_57;
V_43 -> V_58 = F_10 ( V_43 -> V_54 , sizeof( * V_43 -> V_58 ) , V_33 ) ;
if ( V_43 -> V_58 == NULL )
goto V_57;
for ( V_45 = 0 ; V_45 < V_43 -> V_53 ; V_45 ++ ) {
int V_25 = 0 ;
V_26 V_59 ;
struct V_60 * V_9 ;
F_12 ( V_21 , V_22 , V_59 , V_27 ) ;
if ( V_59 == 0 ) {
V_43 -> V_56 [ V_45 ] = NULL ;
continue;
}
F_6 ( L_13 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
switch ( V_59 ) {
case V_61 :
V_25 = sizeof( struct V_23 ) ;
break;
case V_62 :
V_25 = sizeof( struct V_30 ) ;
break;
case V_63 :
V_25 = sizeof( struct V_36 ) ;
break;
case V_64 :
V_25 = sizeof( struct V_39 ) ;
break;
default:
V_44 = - V_29 ;
goto V_27;
}
F_19 ( V_25 == 0 ) ;
V_9 = V_43 -> V_56 [ V_45 ] = F_16 ( V_25 , V_33 ) ;
if ( V_9 == NULL )
goto V_57;
F_7 ( V_21 , V_22 , 4 * sizeof( V_26 ) , V_27 ) ;
V_9 -> V_65 = F_8 ( V_21 ) ;
V_9 -> type = F_20 ( V_21 ) ;
V_9 -> V_59 = F_21 ( V_21 ) ;
V_9 -> V_66 = F_21 ( V_21 ) ;
V_9 -> V_67 = F_8 ( V_21 ) ;
V_9 -> V_25 = F_8 ( V_21 ) ;
F_6 ( L_14 ,
V_9 -> V_25 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
V_9 -> V_68 = F_10 ( V_9 -> V_25 , sizeof( V_69 ) , V_33 ) ;
if ( V_9 -> V_68 == NULL )
goto V_57;
V_9 -> V_70 = F_10 ( V_9 -> V_25 , sizeof( V_26 ) , V_33 ) ;
if ( V_9 -> V_70 == NULL )
goto V_57;
V_9 -> V_71 = 0 ;
F_7 ( V_21 , V_22 , V_9 -> V_25 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_9 -> V_25 ; V_31 ++ )
V_9 -> V_68 [ V_31 ] = F_8 ( V_21 ) ;
switch ( V_9 -> V_59 ) {
case V_61 :
V_44 = F_5 ( V_21 , V_22 ,
(struct V_23 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_62 :
V_44 = F_9 ( V_21 , V_22 ,
(struct V_30 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_63 :
V_44 = F_11 ( V_21 , V_22 ,
(struct V_36 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_64 :
V_44 = F_13 ( V_21 , V_22 ,
(struct V_39 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
}
}
F_6 ( L_15 , V_43 -> V_58 ) ;
for ( V_45 = 0 ; V_45 < V_43 -> V_54 ; V_45 ++ ) {
V_26 V_72 ;
struct V_73 * V_74 ;
F_12 ( V_21 , V_22 , V_72 , V_27 ) ;
if ( ! V_72 ) {
F_6 ( L_16 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
V_43 -> V_58 [ V_45 ] = NULL ;
continue;
}
F_6 ( L_17 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
F_12 ( V_21 , V_22 , V_72 , V_27 ) ;
#if V_75 == 32
V_44 = - V_29 ;
if ( V_72 > ( V_76 - sizeof( * V_74 ) )
/ sizeof( struct V_77 ) )
goto V_27;
#endif
V_74 = V_43 -> V_58 [ V_45 ] = F_22 ( sizeof( * V_74 ) +
V_72 * sizeof( struct V_77 ) ,
V_33 ) ;
if ( V_74 == NULL )
goto V_57;
F_6 ( L_18 , V_45 , V_74 ) ;
V_74 -> V_2 = V_72 ;
F_23 ( V_21 , V_22 , & V_74 -> V_78 , 4 , V_27 ) ;
F_7 ( V_21 , V_22 , V_74 -> V_2 * 3 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_74 -> V_2 ; V_31 ++ ) {
V_74 -> V_79 [ V_31 ] . V_80 = F_8 ( V_21 ) ;
V_74 -> V_79 [ V_31 ] . V_81 = F_8 ( V_21 ) ;
V_74 -> V_79 [ V_31 ] . V_82 = F_8 ( V_21 ) ;
}
}
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
V_44 = F_14 ( V_21 , V_22 ) ;
if ( V_44 < 0 )
goto V_5;
}
F_7 ( V_21 , V_22 , 3 * sizeof( V_26 ) , V_5 ) ;
V_43 -> V_49 = F_8 ( V_21 ) ;
V_43 -> V_50 = F_8 ( V_21 ) ;
V_43 -> V_51 = F_8 ( V_21 ) ;
F_6 ( L_19 ,
V_43 -> V_49 ) ;
F_6 ( L_20 ,
V_43 -> V_50 ) ;
F_6 ( L_21 ,
V_43 -> V_51 ) ;
V_5:
F_6 ( L_22 ) ;
return V_43 ;
V_57:
V_44 = - V_34 ;
V_27:
F_6 ( L_23 , V_44 ) ;
F_24 ( V_43 ) ;
return F_17 ( V_44 ) ;
}
static int F_25 ( struct V_83 V_84 , struct V_83 V_74 )
{
T_1 V_85 = * ( T_1 * ) & V_84 ;
T_1 V_9 = * ( T_1 * ) & V_74 ;
if ( V_85 < V_9 )
return - 1 ;
if ( V_85 > V_9 )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_90 * * V_21 = & V_89 -> V_90 ;
struct V_90 * V_91 = NULL ;
struct V_86 * V_92 = NULL ;
int V_43 ;
F_6 ( L_24 , * ( T_1 * ) & V_87 -> V_93 , V_87 ) ;
while ( * V_21 ) {
V_91 = * V_21 ;
V_92 = F_27 ( V_91 , struct V_86 , V_94 ) ;
V_43 = F_25 ( V_87 -> V_93 , V_92 -> V_93 ) ;
if ( V_43 < 0 )
V_21 = & ( * V_21 ) -> V_95 ;
else if ( V_43 > 0 )
V_21 = & ( * V_21 ) -> V_96 ;
else
return - V_97 ;
}
F_28 ( & V_87 -> V_94 , V_91 , V_21 ) ;
F_29 ( & V_87 -> V_94 , V_89 ) ;
return 0 ;
}
static struct V_86 * F_30 ( struct V_88 * V_89 ,
struct V_83 V_93 )
{
struct V_90 * V_98 = V_89 -> V_90 ;
struct V_86 * V_92 ;
int V_43 ;
while ( V_98 ) {
V_92 = F_27 ( V_98 , struct V_86 , V_94 ) ;
V_43 = F_25 ( V_93 , V_92 -> V_93 ) ;
if ( V_43 < 0 ) {
V_98 = V_98 -> V_95 ;
} else if ( V_43 > 0 ) {
V_98 = V_98 -> V_96 ;
} else {
F_6 ( L_25 ,
* ( T_1 * ) & V_93 , V_92 ) ;
return V_92 ;
}
}
return NULL ;
}
static int F_31 ( struct V_88 * V_89 , struct V_83 V_93 )
{
struct V_86 * V_92 = F_30 ( V_89 , V_93 ) ;
if ( V_92 ) {
F_6 ( L_26 , * ( T_1 * ) & V_93 , V_92 ) ;
F_32 ( & V_92 -> V_94 , V_89 ) ;
F_33 ( V_92 ) ;
return 0 ;
}
F_6 ( L_27 , * ( T_1 * ) & V_93 ) ;
return - V_99 ;
}
static int F_34 ( struct V_88 * V_89 , struct V_10 * V_87 )
{
struct V_90 * * V_21 = & V_89 -> V_90 ;
struct V_90 * V_91 = NULL ;
struct V_10 * V_11 = NULL ;
while ( * V_21 ) {
V_91 = * V_21 ;
V_11 = F_27 ( V_91 , struct V_10 , V_94 ) ;
if ( V_87 -> V_65 < V_11 -> V_65 )
V_21 = & ( * V_21 ) -> V_95 ;
else if ( V_87 -> V_65 > V_11 -> V_65 )
V_21 = & ( * V_21 ) -> V_96 ;
else
return - V_97 ;
}
F_28 ( & V_87 -> V_94 , V_91 , V_21 ) ;
F_29 ( & V_87 -> V_94 , V_89 ) ;
return 0 ;
}
static struct V_10 * F_35 ( struct V_88 * V_89 , int V_65 )
{
struct V_10 * V_11 ;
struct V_90 * V_98 = V_89 -> V_90 ;
while ( V_98 ) {
V_11 = F_27 ( V_98 , struct V_10 , V_94 ) ;
if ( V_65 < V_11 -> V_65 )
V_98 = V_98 -> V_95 ;
else if ( V_65 > V_11 -> V_65 )
V_98 = V_98 -> V_96 ;
else
return V_11 ;
}
return NULL ;
}
const char * F_36 ( struct V_100 * V_101 , T_1 V_65 )
{
struct V_10 * V_11 ;
if ( V_65 == V_102 )
return NULL ;
if ( F_37 ( V_65 > ( T_1 ) V_103 ) )
return NULL ;
V_11 = F_35 ( & V_101 -> V_104 , ( int ) V_65 ) ;
return V_11 ? V_11 -> V_105 : NULL ;
}
int F_38 ( struct V_100 * V_101 , const char * V_105 )
{
struct V_90 * V_106 ;
for ( V_106 = F_39 ( & V_101 -> V_104 ) ; V_106 ; V_106 = F_40 ( V_106 ) ) {
struct V_10 * V_11 =
F_27 ( V_106 , struct V_10 , V_94 ) ;
if ( V_11 -> V_105 && strcmp ( V_11 -> V_105 , V_105 ) == 0 )
return V_11 -> V_65 ;
}
return - V_99 ;
}
static void F_41 ( struct V_88 * V_89 , struct V_10 * V_11 )
{
F_32 ( & V_11 -> V_94 , V_89 ) ;
F_33 ( V_11 -> V_105 ) ;
F_33 ( V_11 ) ;
}
static int F_42 ( void * * V_21 , void * V_22 , struct V_10 * V_11 )
{
unsigned int V_98 , V_107 ;
F_43 ( V_21 , & V_11 -> V_13 , sizeof( V_11 -> V_13 ) ) ;
F_3 ( V_11 ) ;
V_98 = F_4 ( V_11 -> V_13 . V_108 ) ;
while ( V_98 -- ) {
F_7 ( V_21 , V_22 , sizeof( T_1 ) + 1 + sizeof( T_1 ) +
sizeof( struct V_109 ) , V_27 ) ;
* V_21 += sizeof( T_1 ) +
1 + sizeof( T_1 ) +
sizeof( struct V_109 ) ;
V_107 = F_8 ( V_21 ) ;
* V_21 += V_107 ;
}
* V_21 += F_4 ( V_11 -> V_13 . V_110 ) * sizeof( T_1 ) * 2 ;
return 0 ;
V_27:
return - V_29 ;
}
static int F_44 ( void * * V_21 , void * V_22 , struct V_100 * V_101 )
{
struct V_10 * V_11 ;
V_26 V_111 , V_2 , V_112 ;
F_12 ( V_21 , V_22 , V_111 , V_27 ) ;
F_6 ( L_28 , V_111 ) ;
while ( V_111 -- ) {
F_12 ( V_21 , V_22 , V_112 , V_27 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
F_6 ( L_29 , V_112 , V_2 ) ;
F_7 ( V_21 , V_22 , V_2 , V_27 ) ;
V_11 = F_35 ( & V_101 -> V_104 , V_112 ) ;
if ( V_11 ) {
char * V_105 = F_45 ( * V_21 , V_2 , V_33 ) ;
if ( ! V_105 )
return - V_34 ;
F_33 ( V_11 -> V_105 ) ;
V_11 -> V_105 = V_105 ;
F_6 ( L_30 , V_11 -> V_105 ) ;
}
* V_21 += V_2 ;
}
return 0 ;
V_27:
return - V_29 ;
}
void F_46 ( struct V_100 * V_101 )
{
F_6 ( L_31 , V_101 ) ;
if ( V_101 -> V_113 )
F_24 ( V_101 -> V_113 ) ;
while ( ! F_47 ( & V_101 -> V_114 ) ) {
struct V_86 * V_92 =
F_27 ( F_39 ( & V_101 -> V_114 ) ,
struct V_86 , V_94 ) ;
F_32 ( & V_92 -> V_94 , & V_101 -> V_114 ) ;
F_33 ( V_92 ) ;
}
while ( ! F_47 ( & V_101 -> V_104 ) ) {
struct V_10 * V_11 =
F_27 ( F_39 ( & V_101 -> V_104 ) ,
struct V_10 , V_94 ) ;
F_41 ( & V_101 -> V_104 , V_11 ) ;
}
F_33 ( V_101 -> V_115 ) ;
F_33 ( V_101 -> V_116 ) ;
F_33 ( V_101 -> V_117 ) ;
F_33 ( V_101 ) ;
}
static int F_48 ( struct V_100 * V_101 , int V_118 )
{
T_2 * V_3 ;
struct V_119 * V_120 ;
V_26 * V_67 ;
V_3 = F_10 ( V_118 , sizeof( * V_3 ) , V_33 ) ;
V_120 = F_10 ( V_118 , sizeof( * V_120 ) , V_33 ) ;
V_67 = F_10 ( V_118 , sizeof( * V_67 ) , V_33 ) ;
if ( V_3 == NULL || V_120 == NULL || V_67 == NULL ) {
F_33 ( V_3 ) ;
F_33 ( V_120 ) ;
F_33 ( V_67 ) ;
return - V_34 ;
}
if ( V_101 -> V_115 ) {
memcpy ( V_3 , V_101 -> V_115 , V_101 -> V_121 * sizeof( * V_3 ) ) ;
memcpy ( V_120 , V_101 -> V_117 , V_101 -> V_121 * sizeof( * V_120 ) ) ;
memcpy ( V_67 , V_101 -> V_116 , V_101 -> V_121 * sizeof( * V_67 ) ) ;
F_33 ( V_101 -> V_115 ) ;
F_33 ( V_101 -> V_117 ) ;
F_33 ( V_101 -> V_116 ) ;
}
V_101 -> V_115 = V_3 ;
V_101 -> V_116 = V_67 ;
V_101 -> V_117 = V_120 ;
V_101 -> V_121 = V_118 ;
return 0 ;
}
struct V_100 * F_49 ( void * * V_21 , void * V_22 )
{
struct V_100 * V_101 ;
T_3 V_122 ;
V_26 V_2 , V_118 , V_45 ;
T_2 V_123 ;
int V_44 = - V_29 ;
void * V_46 = * V_21 ;
struct V_10 * V_11 ;
F_6 ( L_32 , * V_21 , V_22 , ( int ) ( V_22 - * V_21 ) ) ;
V_101 = F_16 ( sizeof( * V_101 ) , V_33 ) ;
if ( V_101 == NULL )
return F_17 ( - V_34 ) ;
V_101 -> V_114 = V_124 ;
F_50 ( V_21 , V_22 , V_122 , V_27 ) ;
if ( V_122 > V_125 ) {
F_51 ( L_33 , V_122 ,
V_125 ) ;
goto V_27;
}
F_7 ( V_21 , V_22 , 2 * sizeof( T_1 ) + 6 * sizeof( V_26 ) , V_27 ) ;
F_43 ( V_21 , & V_101 -> V_126 , sizeof( V_101 -> V_126 ) ) ;
V_101 -> V_127 = F_8 ( V_21 ) ;
F_43 ( V_21 , & V_101 -> V_128 , sizeof( V_101 -> V_128 ) ) ;
F_43 ( V_21 , & V_101 -> V_129 , sizeof( V_101 -> V_129 ) ) ;
F_12 ( V_21 , V_22 , V_118 , V_27 ) ;
while ( V_118 -- ) {
F_7 ( V_21 , V_22 , 4 + 1 + sizeof( V_11 -> V_13 ) , V_27 ) ;
V_44 = - V_34 ;
V_11 = F_16 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 )
goto V_27;
V_11 -> V_65 = F_8 ( V_21 ) ;
V_44 = - V_29 ;
V_123 = F_21 ( V_21 ) ;
if ( V_123 > V_130 ) {
F_51 ( L_34 ,
V_123 , V_130 ) ;
F_33 ( V_11 ) ;
goto V_27;
}
V_44 = F_42 ( V_21 , V_22 , V_11 ) ;
if ( V_44 < 0 ) {
F_33 ( V_11 ) ;
goto V_27;
}
F_34 ( & V_101 -> V_104 , V_11 ) ;
}
if ( V_122 >= 5 ) {
V_44 = F_44 ( V_21 , V_22 , V_101 ) ;
if ( V_44 < 0 ) {
F_6 ( L_35 ) ;
goto V_27;
}
}
F_12 ( V_21 , V_22 , V_101 -> V_131 , V_27 ) ;
F_12 ( V_21 , V_22 , V_101 -> V_132 , V_27 ) ;
V_118 = F_8 ( V_21 ) ;
V_44 = F_48 ( V_101 , V_118 ) ;
if ( V_44 < 0 )
goto V_27;
F_6 ( L_36 , V_101 -> V_121 ) ;
V_44 = - V_29 ;
F_7 ( V_21 , V_22 , 3 * sizeof( V_26 ) +
V_101 -> V_121 * ( 1 + sizeof( * V_101 -> V_116 ) +
sizeof( * V_101 -> V_117 ) ) , V_27 ) ;
* V_21 += 4 ;
F_43 ( V_21 , V_101 -> V_115 , V_101 -> V_121 ) ;
* V_21 += 4 ;
for ( V_45 = 0 ; V_45 < V_101 -> V_121 ; V_45 ++ )
V_101 -> V_116 [ V_45 ] = F_8 ( V_21 ) ;
* V_21 += 4 ;
F_43 ( V_21 , V_101 -> V_117 , V_101 -> V_121 * sizeof( * V_101 -> V_117 ) ) ;
for ( V_45 = 0 ; V_45 < V_101 -> V_121 ; V_45 ++ )
F_52 ( & V_101 -> V_117 [ V_45 ] ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
for ( V_45 = 0 ; V_45 < V_2 ; V_45 ++ ) {
int V_98 , V_31 ;
struct V_83 V_93 ;
struct V_86 * V_92 ;
F_7 ( V_21 , V_22 , sizeof( V_26 ) + sizeof( T_1 ) , V_27 ) ;
F_43 ( V_21 , & V_93 , sizeof( V_93 ) ) ;
V_98 = F_8 ( V_21 ) ;
V_44 = - V_29 ;
if ( V_98 > ( V_133 - sizeof( * V_92 ) ) / sizeof( V_26 ) )
goto V_27;
F_7 ( V_21 , V_22 , V_98 * sizeof( V_26 ) , V_27 ) ;
V_44 = - V_34 ;
V_92 = F_22 ( sizeof( * V_92 ) + V_98 * sizeof( V_26 ) , V_33 ) ;
if ( ! V_92 )
goto V_27;
V_92 -> V_93 = V_93 ;
V_92 -> V_2 = V_98 ;
for ( V_31 = 0 ; V_31 < V_98 ; V_31 ++ )
V_92 -> V_134 [ V_31 ] = F_8 ( V_21 ) ;
V_44 = F_26 ( V_92 , & V_101 -> V_114 ) ;
if ( V_44 )
goto V_27;
F_6 ( L_37 , * ( T_1 * ) & V_93 , V_2 ) ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
F_6 ( L_38 , V_2 ,
( int ) ( * V_21 - V_46 ) ) ;
F_7 ( V_21 , V_22 , V_2 , V_27 ) ;
V_101 -> V_113 = F_15 ( * V_21 , V_22 ) ;
* V_21 += V_2 ;
if ( F_53 ( V_101 -> V_113 ) ) {
V_44 = F_54 ( V_101 -> V_113 ) ;
V_101 -> V_113 = NULL ;
goto V_27;
}
* V_21 = V_22 ;
F_6 ( L_39 , * V_21 , V_22 ) ;
return V_101 ;
V_27:
F_6 ( L_40 , V_44 ) ;
F_46 ( V_101 ) ;
return F_17 ( V_44 ) ;
}
struct V_100 * F_55 ( void * * V_21 , void * V_22 ,
struct V_100 * V_101 ,
struct V_135 * V_136 )
{
struct V_41 * V_137 = NULL ;
struct V_138 V_126 ;
V_26 V_127 = 0 ;
struct V_109 V_129 ;
V_26 V_2 , V_112 ;
V_69 V_139 , V_140 , V_118 ;
void * V_46 = * V_21 ;
int V_44 = - V_29 ;
T_3 V_122 ;
F_50 ( V_21 , V_22 , V_122 , V_27 ) ;
if ( V_122 > V_141 ) {
F_51 ( L_41 , V_122 ,
V_141 ) ;
goto V_27;
}
F_7 ( V_21 , V_22 , sizeof( V_126 ) + sizeof( V_129 ) + 2 * sizeof( V_26 ) ,
V_27 ) ;
F_43 ( V_21 , & V_126 , sizeof( V_126 ) ) ;
V_127 = F_8 ( V_21 ) ;
F_19 ( V_127 != V_101 -> V_127 + 1 ) ;
F_43 ( V_21 , & V_129 , sizeof( V_129 ) ) ;
V_139 = F_8 ( V_21 ) ;
V_140 = F_8 ( V_21 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
if ( V_2 > 0 ) {
F_6 ( L_42 ,
V_2 , * V_21 , V_22 ) ;
return F_49 ( V_21 , F_56 ( * V_21 + V_2 , V_22 ) ) ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
if ( V_2 > 0 ) {
F_6 ( L_43 ,
V_2 , * V_21 , V_22 ) ;
V_137 = F_15 ( * V_21 , F_56 ( * V_21 + V_2 , V_22 ) ) ;
if ( F_53 ( V_137 ) )
return F_57 ( V_137 ) ;
* V_21 += V_2 ;
}
if ( V_140 >= 0 )
V_101 -> V_132 = V_140 ;
if ( V_139 >= 0 )
V_101 -> V_131 = V_139 ;
F_7 ( V_21 , V_22 , 5 * sizeof( V_26 ) , V_27 ) ;
V_118 = F_8 ( V_21 ) ;
if ( V_118 >= 0 ) {
V_44 = F_48 ( V_101 , V_118 ) ;
if ( V_44 < 0 )
goto V_27;
}
V_101 -> V_127 ++ ;
V_101 -> V_129 = V_129 ;
if ( V_137 ) {
if ( V_101 -> V_113 )
F_24 ( V_101 -> V_113 ) ;
V_101 -> V_113 = V_137 ;
V_137 = NULL ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
T_4 V_123 ;
struct V_10 * V_11 ;
F_12 ( V_21 , V_22 , V_112 , V_27 ) ;
F_7 ( V_21 , V_22 , 1 + sizeof( V_11 -> V_13 ) , V_27 ) ;
V_123 = F_21 ( V_21 ) ;
if ( V_123 > V_130 ) {
F_51 ( L_34 ,
V_123 , V_130 ) ;
V_44 = - V_29 ;
goto V_27;
}
V_11 = F_35 ( & V_101 -> V_104 , V_112 ) ;
if ( ! V_11 ) {
V_11 = F_16 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 ) {
V_44 = - V_34 ;
goto V_27;
}
V_11 -> V_65 = V_112 ;
F_34 ( & V_101 -> V_104 , V_11 ) ;
}
V_44 = F_42 ( V_21 , V_22 , V_11 ) ;
if ( V_44 < 0 )
goto V_27;
}
if ( V_122 >= 5 ) {
V_44 = F_44 ( V_21 , V_22 , V_101 ) ;
if ( V_44 < 0 )
goto V_27;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
struct V_10 * V_11 ;
F_12 ( V_21 , V_22 , V_112 , V_27 ) ;
V_11 = F_35 ( & V_101 -> V_104 , V_112 ) ;
if ( V_11 )
F_41 ( & V_101 -> V_104 , V_11 ) ;
}
V_44 = - V_29 ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_142 ;
struct V_119 V_120 ;
F_12 ( V_21 , V_22 , V_142 , V_27 ) ;
F_23 ( V_21 , V_22 , & V_120 , sizeof( V_120 ) , V_27 ) ;
F_52 ( & V_120 ) ;
F_58 ( L_44 , V_142 ) ;
F_19 ( V_142 >= V_101 -> V_121 ) ;
V_101 -> V_115 [ V_142 ] |= V_7 ;
V_101 -> V_117 [ V_142 ] = V_120 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_142 ;
T_2 V_143 ;
F_12 ( V_21 , V_22 , V_142 , V_27 ) ;
V_143 = * * ( T_2 * * ) V_21 ;
( * V_21 ) ++ ;
if ( V_143 == 0 )
V_143 = V_7 ;
if ( V_143 & V_7 )
F_58 ( L_45 , V_142 ) ;
if ( V_142 < V_101 -> V_121 )
V_101 -> V_115 [ V_142 ] ^= V_143 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_142 , V_144 ;
F_7 ( V_21 , V_22 , sizeof( V_26 ) * 2 , V_27 ) ;
V_142 = F_8 ( V_21 ) ;
V_144 = F_8 ( V_21 ) ;
F_58 ( L_46 , V_142 , V_144 ,
V_144 == V_145 ? L_47 :
( V_144 == V_146 ? L_48 : L_4 ) ) ;
if ( V_142 < V_101 -> V_121 )
V_101 -> V_116 [ V_142 ] = V_144 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
struct V_86 * V_92 ;
int V_31 ;
struct V_83 V_93 ;
V_26 V_147 ;
F_7 ( V_21 , V_22 , sizeof( T_1 ) + sizeof( V_26 ) , V_27 ) ;
F_43 ( V_21 , & V_93 , sizeof( V_93 ) ) ;
V_147 = F_8 ( V_21 ) ;
if ( V_147 ) {
F_7 ( V_21 , V_22 , V_147 * sizeof( V_26 ) , V_27 ) ;
( void ) F_31 ( & V_101 -> V_114 , V_93 ) ;
V_44 = - V_29 ;
if ( V_147 > ( V_133 - sizeof( * V_92 ) ) / sizeof( V_26 ) )
goto V_27;
V_44 = - V_34 ;
V_92 = F_22 ( sizeof( * V_92 ) + sizeof( V_26 ) * V_147 , V_33 ) ;
if ( ! V_92 )
goto V_27;
V_92 -> V_93 = V_93 ;
V_92 -> V_2 = V_147 ;
for ( V_31 = 0 ; V_31 < V_147 ; V_31 ++ )
V_92 -> V_134 [ V_31 ] = F_8 ( V_21 ) ;
V_44 = F_26 ( V_92 , & V_101 -> V_114 ) ;
if ( V_44 ) {
F_33 ( V_92 ) ;
goto V_27;
}
F_6 ( L_37 , * ( T_1 * ) & V_93 ,
V_147 ) ;
} else {
F_31 ( & V_101 -> V_114 , V_93 ) ;
}
}
* V_21 = V_22 ;
return V_101 ;
V_27:
F_18 ( L_49 ,
V_127 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_46 , V_22 ) ;
F_59 ( V_148 , L_50 ,
V_149 , 16 , 1 ,
V_46 , V_22 - V_46 , true ) ;
if ( V_137 )
F_24 ( V_137 ) ;
return F_17 ( V_44 ) ;
}
int F_60 ( struct V_150 * V_151 ,
T_1 V_144 , T_1 * V_152 ,
T_1 * V_153 ,
T_1 * V_154 , T_1 * V_155 )
{
V_26 V_156 = F_4 ( V_151 -> V_157 ) ;
V_26 V_158 = F_4 ( V_151 -> V_159 ) ;
V_26 V_160 = F_4 ( V_151 -> V_161 ) ;
V_26 V_162 , V_163 , V_164 , V_165 ;
V_26 V_166 ;
T_1 V_8 , V_167 ;
F_6 ( L_51 , V_144 , * V_152 ,
V_156 , V_158 ) ;
if ( V_158 == 0 || V_160 == 0 )
goto V_168;
V_166 = V_156 / V_158 ;
if ( V_166 == 0 )
goto V_168;
F_6 ( L_52 , V_156 , V_158 ,
V_166 ) ;
if ( ( V_158 & ~ V_169 ) != 0 )
goto V_168;
V_8 = V_144 ;
F_61 ( V_8 , V_158 ) ;
V_162 = V_8 ;
F_6 ( L_53 , V_144 , V_158 , V_162 ) ;
V_163 = V_162 / V_160 ;
V_164 = V_162 % V_160 ;
V_165 = V_163 / V_166 ;
* V_153 = V_165 * V_160 + V_164 ;
F_6 ( L_54 , V_165 , V_160 , ( unsigned int ) * V_153 ) ;
V_8 = V_144 ;
V_167 = F_61 ( V_8 , V_158 ) ;
* V_154 = V_167 + ( V_163 % V_166 ) * V_158 ;
* V_155 = F_62 ( T_1 , * V_152 , V_158 - V_167 ) ;
* V_152 = * V_155 ;
F_6 ( L_55 , * V_154 , * V_155 ) ;
return 0 ;
V_168:
F_6 ( L_56 ) ;
* V_153 = 0 ;
* V_154 = 0 ;
* V_155 = 0 ;
return - V_29 ;
}
int F_63 ( struct V_170 * V_171 ,
const char * V_172 ,
struct V_150 * V_173 ,
struct V_100 * V_174 )
{
unsigned int V_111 , V_175 ;
struct V_83 V_93 ;
int V_176 = F_4 ( V_173 -> V_177 ) ;
struct V_10 * V_112 ;
unsigned int V_178 ;
F_19 ( ! V_174 ) ;
V_112 = F_35 ( & V_174 -> V_104 , V_176 ) ;
if ( ! V_112 )
return - V_179 ;
V_178 = F_64 ( V_112 -> V_13 . V_180 , V_172 , strlen ( V_172 ) ) ;
V_111 = F_4 ( V_112 -> V_13 . V_14 ) ;
V_175 = V_112 -> V_12 ;
V_93 . V_178 = F_65 ( V_178 ) ;
V_93 . V_181 = F_65 ( - 1 ) ;
V_93 . V_112 = V_173 -> V_177 ;
F_6 ( L_57 , V_172 , V_176 , V_178 ) ;
V_171 -> V_182 = V_93 ;
V_171 -> V_183 = V_173 -> V_184 ;
return 0 ;
}
static int * F_66 ( struct V_100 * V_174 , struct V_83 V_93 ,
int * V_134 , int * V_111 )
{
struct V_86 * V_92 ;
struct V_10 * V_112 ;
int V_185 ;
unsigned int V_176 , V_178 , V_186 , V_8 , V_74 ;
V_176 = F_4 ( V_93 . V_112 ) ;
V_178 = F_67 ( V_93 . V_178 ) ;
V_112 = F_35 ( & V_174 -> V_104 , V_176 ) ;
if ( ! V_112 )
return NULL ;
V_8 = F_68 ( V_178 , F_4 ( V_112 -> V_13 . V_14 ) ,
V_112 -> V_15 ) ;
V_93 . V_178 = F_65 ( V_8 ) ;
V_92 = F_30 ( & V_174 -> V_114 , V_93 ) ;
if ( V_92 ) {
* V_111 = V_92 -> V_2 ;
return V_92 -> V_134 ;
}
V_185 = F_69 ( V_174 -> V_113 , V_112 -> V_13 . V_187 ,
V_112 -> V_13 . type , V_112 -> V_13 . V_25 ) ;
if ( V_185 < 0 ) {
F_18 ( L_58 ,
V_176 , V_112 -> V_13 . V_187 , V_112 -> V_13 . type ,
V_112 -> V_13 . V_25 ) ;
return NULL ;
}
V_186 = F_68 ( V_178 ,
F_4 ( V_112 -> V_13 . V_16 ) ,
V_112 -> V_15 ) ;
V_186 += V_176 ;
V_74 = F_70 ( V_174 -> V_113 , V_185 , V_186 , V_134 ,
F_62 ( int , V_112 -> V_13 . V_25 , * V_111 ) ,
V_174 -> V_116 ) ;
if ( V_74 < 0 ) {
F_18 ( L_59
L_60 , V_74 , V_176 , V_112 -> V_13 . V_187 ,
V_112 -> V_13 . type , V_112 -> V_13 . V_25 ) ;
return NULL ;
}
* V_111 = V_74 ;
return V_134 ;
}
int F_71 ( struct V_100 * V_174 , struct V_83 V_93 ,
int * V_188 )
{
int V_189 [ V_190 ] , * V_134 ;
int V_45 , V_191 , V_111 = V_190 ;
V_134 = F_66 ( V_174 , V_93 , V_189 , & V_111 ) ;
if ( ! V_134 )
return - 1 ;
V_191 = 0 ;
for ( V_45 = 0 ; V_45 < V_111 ; V_45 ++ )
if ( F_72 ( V_174 , V_134 [ V_45 ] ) )
V_188 [ V_191 ++ ] = V_134 [ V_45 ] ;
return V_191 ;
}
int F_73 ( struct V_100 * V_174 , struct V_83 V_93 )
{
int V_189 [ V_190 ] , * V_134 ;
int V_45 , V_111 = V_190 ;
V_134 = F_66 ( V_174 , V_93 , V_189 , & V_111 ) ;
if ( ! V_134 )
return - 1 ;
for ( V_45 = 0 ; V_45 < V_111 ; V_45 ++ )
if ( F_72 ( V_174 , V_134 [ V_45 ] ) )
return V_134 [ V_45 ] ;
return - 1 ;
}
