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
int F_36 ( struct V_100 * V_101 , const char * V_102 )
{
struct V_90 * V_103 ;
for ( V_103 = F_37 ( & V_101 -> V_104 ) ; V_103 ; V_103 = F_38 ( V_103 ) ) {
struct V_10 * V_11 =
F_27 ( V_103 , struct V_10 , V_94 ) ;
if ( V_11 -> V_102 && strcmp ( V_11 -> V_102 , V_102 ) == 0 )
return V_11 -> V_65 ;
}
return - V_99 ;
}
static void F_39 ( struct V_88 * V_89 , struct V_10 * V_11 )
{
F_32 ( & V_11 -> V_94 , V_89 ) ;
F_33 ( V_11 -> V_102 ) ;
F_33 ( V_11 ) ;
}
static int F_40 ( void * * V_21 , void * V_22 , struct V_10 * V_11 )
{
unsigned int V_98 , V_105 ;
F_41 ( V_21 , & V_11 -> V_13 , sizeof( V_11 -> V_13 ) ) ;
F_3 ( V_11 ) ;
V_98 = F_4 ( V_11 -> V_13 . V_106 ) ;
while ( V_98 -- ) {
F_7 ( V_21 , V_22 , sizeof( T_1 ) + 1 + sizeof( T_1 ) +
sizeof( struct V_107 ) , V_27 ) ;
* V_21 += sizeof( T_1 ) +
1 + sizeof( T_1 ) +
sizeof( struct V_107 ) ;
V_105 = F_8 ( V_21 ) ;
* V_21 += V_105 ;
}
* V_21 += F_4 ( V_11 -> V_13 . V_108 ) * sizeof( T_1 ) * 2 ;
return 0 ;
V_27:
return - V_29 ;
}
static int F_42 ( void * * V_21 , void * V_22 , struct V_100 * V_101 )
{
struct V_10 * V_11 ;
V_26 V_109 , V_2 , V_110 ;
F_12 ( V_21 , V_22 , V_109 , V_27 ) ;
F_6 ( L_28 , V_109 ) ;
while ( V_109 -- ) {
F_12 ( V_21 , V_22 , V_110 , V_27 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
F_6 ( L_29 , V_110 , V_2 ) ;
F_7 ( V_21 , V_22 , V_2 , V_27 ) ;
V_11 = F_35 ( & V_101 -> V_104 , V_110 ) ;
if ( V_11 ) {
char * V_102 = F_43 ( * V_21 , V_2 , V_33 ) ;
if ( ! V_102 )
return - V_34 ;
F_33 ( V_11 -> V_102 ) ;
V_11 -> V_102 = V_102 ;
F_6 ( L_30 , V_11 -> V_102 ) ;
}
* V_21 += V_2 ;
}
return 0 ;
V_27:
return - V_29 ;
}
void F_44 ( struct V_100 * V_101 )
{
F_6 ( L_31 , V_101 ) ;
if ( V_101 -> V_111 )
F_24 ( V_101 -> V_111 ) ;
while ( ! F_45 ( & V_101 -> V_112 ) ) {
struct V_86 * V_92 =
F_27 ( F_37 ( & V_101 -> V_112 ) ,
struct V_86 , V_94 ) ;
F_32 ( & V_92 -> V_94 , & V_101 -> V_112 ) ;
F_33 ( V_92 ) ;
}
while ( ! F_45 ( & V_101 -> V_104 ) ) {
struct V_10 * V_11 =
F_27 ( F_37 ( & V_101 -> V_104 ) ,
struct V_10 , V_94 ) ;
F_39 ( & V_101 -> V_104 , V_11 ) ;
}
F_33 ( V_101 -> V_113 ) ;
F_33 ( V_101 -> V_114 ) ;
F_33 ( V_101 -> V_115 ) ;
F_33 ( V_101 ) ;
}
static int F_46 ( struct V_100 * V_101 , int V_116 )
{
T_2 * V_3 ;
struct V_117 * V_118 ;
V_26 * V_67 ;
V_3 = F_10 ( V_116 , sizeof( * V_3 ) , V_33 ) ;
V_118 = F_10 ( V_116 , sizeof( * V_118 ) , V_33 ) ;
V_67 = F_10 ( V_116 , sizeof( * V_67 ) , V_33 ) ;
if ( V_3 == NULL || V_118 == NULL || V_67 == NULL ) {
F_33 ( V_3 ) ;
F_33 ( V_118 ) ;
F_33 ( V_67 ) ;
return - V_34 ;
}
if ( V_101 -> V_113 ) {
memcpy ( V_3 , V_101 -> V_113 , V_101 -> V_119 * sizeof( * V_3 ) ) ;
memcpy ( V_118 , V_101 -> V_115 , V_101 -> V_119 * sizeof( * V_118 ) ) ;
memcpy ( V_67 , V_101 -> V_114 , V_101 -> V_119 * sizeof( * V_67 ) ) ;
F_33 ( V_101 -> V_113 ) ;
F_33 ( V_101 -> V_115 ) ;
F_33 ( V_101 -> V_114 ) ;
}
V_101 -> V_113 = V_3 ;
V_101 -> V_114 = V_67 ;
V_101 -> V_115 = V_118 ;
V_101 -> V_119 = V_116 ;
return 0 ;
}
struct V_100 * F_47 ( void * * V_21 , void * V_22 )
{
struct V_100 * V_101 ;
T_3 V_120 ;
V_26 V_2 , V_116 , V_45 ;
T_2 V_121 ;
int V_44 = - V_29 ;
void * V_46 = * V_21 ;
struct V_10 * V_11 ;
F_6 ( L_32 , * V_21 , V_22 , ( int ) ( V_22 - * V_21 ) ) ;
V_101 = F_16 ( sizeof( * V_101 ) , V_33 ) ;
if ( V_101 == NULL )
return F_17 ( - V_34 ) ;
V_101 -> V_112 = V_122 ;
F_48 ( V_21 , V_22 , V_120 , V_27 ) ;
if ( V_120 > V_123 ) {
F_49 ( L_33 , V_120 ,
V_123 ) ;
goto V_27;
}
F_7 ( V_21 , V_22 , 2 * sizeof( T_1 ) + 6 * sizeof( V_26 ) , V_27 ) ;
F_41 ( V_21 , & V_101 -> V_124 , sizeof( V_101 -> V_124 ) ) ;
V_101 -> V_125 = F_8 ( V_21 ) ;
F_41 ( V_21 , & V_101 -> V_126 , sizeof( V_101 -> V_126 ) ) ;
F_41 ( V_21 , & V_101 -> V_127 , sizeof( V_101 -> V_127 ) ) ;
F_12 ( V_21 , V_22 , V_116 , V_27 ) ;
while ( V_116 -- ) {
F_7 ( V_21 , V_22 , 4 + 1 + sizeof( V_11 -> V_13 ) , V_27 ) ;
V_11 = F_16 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 )
goto V_27;
V_11 -> V_65 = F_8 ( V_21 ) ;
V_121 = F_21 ( V_21 ) ;
if ( V_121 > V_128 ) {
F_49 ( L_34 ,
V_121 , V_128 ) ;
F_33 ( V_11 ) ;
goto V_27;
}
V_44 = F_40 ( V_21 , V_22 , V_11 ) ;
if ( V_44 < 0 ) {
F_33 ( V_11 ) ;
goto V_27;
}
F_34 ( & V_101 -> V_104 , V_11 ) ;
}
if ( V_120 >= 5 && F_42 ( V_21 , V_22 , V_101 ) < 0 )
goto V_27;
F_12 ( V_21 , V_22 , V_101 -> V_129 , V_27 ) ;
F_12 ( V_21 , V_22 , V_101 -> V_130 , V_27 ) ;
V_116 = F_8 ( V_21 ) ;
V_44 = F_46 ( V_101 , V_116 ) ;
if ( V_44 < 0 )
goto V_27;
F_6 ( L_35 , V_101 -> V_119 ) ;
V_44 = - V_29 ;
F_7 ( V_21 , V_22 , 3 * sizeof( V_26 ) +
V_101 -> V_119 * ( 1 + sizeof( * V_101 -> V_114 ) +
sizeof( * V_101 -> V_115 ) ) , V_27 ) ;
* V_21 += 4 ;
F_41 ( V_21 , V_101 -> V_113 , V_101 -> V_119 ) ;
* V_21 += 4 ;
for ( V_45 = 0 ; V_45 < V_101 -> V_119 ; V_45 ++ )
V_101 -> V_114 [ V_45 ] = F_8 ( V_21 ) ;
* V_21 += 4 ;
F_41 ( V_21 , V_101 -> V_115 , V_101 -> V_119 * sizeof( * V_101 -> V_115 ) ) ;
for ( V_45 = 0 ; V_45 < V_101 -> V_119 ; V_45 ++ )
F_50 ( & V_101 -> V_115 [ V_45 ] ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
for ( V_45 = 0 ; V_45 < V_2 ; V_45 ++ ) {
int V_98 , V_31 ;
struct V_83 V_93 ;
struct V_86 * V_92 ;
F_7 ( V_21 , V_22 , sizeof( V_26 ) + sizeof( T_1 ) , V_27 ) ;
F_41 ( V_21 , & V_93 , sizeof( V_93 ) ) ;
V_98 = F_8 ( V_21 ) ;
V_44 = - V_29 ;
if ( V_98 > ( V_131 - sizeof( * V_92 ) ) / sizeof( V_26 ) )
goto V_27;
F_7 ( V_21 , V_22 , V_98 * sizeof( V_26 ) , V_27 ) ;
V_44 = - V_34 ;
V_92 = F_22 ( sizeof( * V_92 ) + V_98 * sizeof( V_26 ) , V_33 ) ;
if ( ! V_92 )
goto V_27;
V_92 -> V_93 = V_93 ;
V_92 -> V_2 = V_98 ;
for ( V_31 = 0 ; V_31 < V_98 ; V_31 ++ )
V_92 -> V_132 [ V_31 ] = F_8 ( V_21 ) ;
V_44 = F_26 ( V_92 , & V_101 -> V_112 ) ;
if ( V_44 )
goto V_27;
F_6 ( L_36 , * ( T_1 * ) & V_93 , V_2 ) ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
F_6 ( L_37 , V_2 ,
( int ) ( * V_21 - V_46 ) ) ;
F_7 ( V_21 , V_22 , V_2 , V_27 ) ;
V_101 -> V_111 = F_15 ( * V_21 , V_22 ) ;
* V_21 += V_2 ;
if ( F_51 ( V_101 -> V_111 ) ) {
V_44 = F_52 ( V_101 -> V_111 ) ;
V_101 -> V_111 = NULL ;
goto V_27;
}
* V_21 = V_22 ;
F_6 ( L_38 , * V_21 , V_22 ) ;
return V_101 ;
V_27:
F_6 ( L_39 ) ;
F_44 ( V_101 ) ;
return F_17 ( V_44 ) ;
}
struct V_100 * F_53 ( void * * V_21 , void * V_22 ,
struct V_100 * V_101 ,
struct V_133 * V_134 )
{
struct V_41 * V_135 = NULL ;
struct V_136 V_124 ;
V_26 V_125 = 0 ;
struct V_107 V_127 ;
V_26 V_2 , V_110 ;
V_69 V_137 , V_138 , V_116 ;
void * V_46 = * V_21 ;
int V_44 = - V_29 ;
T_3 V_120 ;
F_48 ( V_21 , V_22 , V_120 , V_27 ) ;
if ( V_120 > V_139 ) {
F_49 ( L_40 , V_120 ,
V_139 ) ;
goto V_27;
}
F_7 ( V_21 , V_22 , sizeof( V_124 ) + sizeof( V_127 ) + 2 * sizeof( V_26 ) ,
V_27 ) ;
F_41 ( V_21 , & V_124 , sizeof( V_124 ) ) ;
V_125 = F_8 ( V_21 ) ;
F_19 ( V_125 != V_101 -> V_125 + 1 ) ;
F_41 ( V_21 , & V_127 , sizeof( V_127 ) ) ;
V_137 = F_8 ( V_21 ) ;
V_138 = F_8 ( V_21 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
if ( V_2 > 0 ) {
F_6 ( L_41 ,
V_2 , * V_21 , V_22 ) ;
return F_47 ( V_21 , F_54 ( * V_21 + V_2 , V_22 ) ) ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
if ( V_2 > 0 ) {
F_6 ( L_42 ,
V_2 , * V_21 , V_22 ) ;
V_135 = F_15 ( * V_21 , F_54 ( * V_21 + V_2 , V_22 ) ) ;
if ( F_51 ( V_135 ) )
return F_55 ( V_135 ) ;
* V_21 += V_2 ;
}
if ( V_138 >= 0 )
V_101 -> V_130 = V_138 ;
if ( V_137 >= 0 )
V_101 -> V_129 = V_137 ;
F_7 ( V_21 , V_22 , 5 * sizeof( V_26 ) , V_27 ) ;
V_116 = F_8 ( V_21 ) ;
if ( V_116 >= 0 ) {
V_44 = F_46 ( V_101 , V_116 ) ;
if ( V_44 < 0 )
goto V_27;
}
V_101 -> V_125 ++ ;
V_101 -> V_127 = V_127 ;
if ( V_135 ) {
if ( V_101 -> V_111 )
F_24 ( V_101 -> V_111 ) ;
V_101 -> V_111 = V_135 ;
V_135 = NULL ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
T_4 V_121 ;
struct V_10 * V_11 ;
F_12 ( V_21 , V_22 , V_110 , V_27 ) ;
F_7 ( V_21 , V_22 , 1 + sizeof( V_11 -> V_13 ) , V_27 ) ;
V_121 = F_21 ( V_21 ) ;
if ( V_121 > V_128 ) {
F_49 ( L_34 ,
V_121 , V_128 ) ;
goto V_27;
}
V_11 = F_35 ( & V_101 -> V_104 , V_110 ) ;
if ( ! V_11 ) {
V_11 = F_16 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 ) {
V_44 = - V_34 ;
goto V_27;
}
V_11 -> V_65 = V_110 ;
F_34 ( & V_101 -> V_104 , V_11 ) ;
}
V_44 = F_40 ( V_21 , V_22 , V_11 ) ;
if ( V_44 < 0 )
goto V_27;
}
if ( V_120 >= 5 && F_42 ( V_21 , V_22 , V_101 ) < 0 )
goto V_27;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
struct V_10 * V_11 ;
F_12 ( V_21 , V_22 , V_110 , V_27 ) ;
V_11 = F_35 ( & V_101 -> V_104 , V_110 ) ;
if ( V_11 )
F_39 ( & V_101 -> V_104 , V_11 ) ;
}
V_44 = - V_29 ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_140 ;
struct V_117 V_118 ;
F_12 ( V_21 , V_22 , V_140 , V_27 ) ;
F_23 ( V_21 , V_22 , & V_118 , sizeof( V_118 ) , V_27 ) ;
F_50 ( & V_118 ) ;
F_56 ( L_43 , V_140 ) ;
F_19 ( V_140 >= V_101 -> V_119 ) ;
V_101 -> V_113 [ V_140 ] |= V_7 ;
V_101 -> V_115 [ V_140 ] = V_118 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_140 ;
T_2 V_141 ;
F_12 ( V_21 , V_22 , V_140 , V_27 ) ;
V_141 = * * ( T_2 * * ) V_21 ;
( * V_21 ) ++ ;
if ( V_141 == 0 )
V_141 = V_7 ;
if ( V_141 & V_7 )
F_56 ( L_44 , V_140 ) ;
if ( V_140 < V_101 -> V_119 )
V_101 -> V_113 [ V_140 ] ^= V_141 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_140 , V_142 ;
F_7 ( V_21 , V_22 , sizeof( V_26 ) * 2 , V_27 ) ;
V_140 = F_8 ( V_21 ) ;
V_142 = F_8 ( V_21 ) ;
F_56 ( L_45 , V_140 , V_142 ,
V_142 == V_143 ? L_46 :
( V_142 == V_144 ? L_47 : L_4 ) ) ;
if ( V_140 < V_101 -> V_119 )
V_101 -> V_114 [ V_140 ] = V_142 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
struct V_86 * V_92 ;
int V_31 ;
struct V_83 V_93 ;
V_26 V_145 ;
F_7 ( V_21 , V_22 , sizeof( T_1 ) + sizeof( V_26 ) , V_27 ) ;
F_41 ( V_21 , & V_93 , sizeof( V_93 ) ) ;
V_145 = F_8 ( V_21 ) ;
if ( V_145 ) {
F_7 ( V_21 , V_22 , V_145 * sizeof( V_26 ) , V_27 ) ;
( void ) F_31 ( & V_101 -> V_112 , V_93 ) ;
if ( V_145 > ( V_131 - sizeof( * V_92 ) ) / sizeof( V_26 ) ) {
V_44 = - V_29 ;
goto V_27;
}
V_92 = F_22 ( sizeof( * V_92 ) + sizeof( V_26 ) * V_145 , V_33 ) ;
if ( ! V_92 ) {
V_44 = - V_34 ;
goto V_27;
}
V_92 -> V_93 = V_93 ;
V_92 -> V_2 = V_145 ;
for ( V_31 = 0 ; V_31 < V_145 ; V_31 ++ )
V_92 -> V_132 [ V_31 ] = F_8 ( V_21 ) ;
V_44 = F_26 ( V_92 , & V_101 -> V_112 ) ;
if ( V_44 ) {
F_33 ( V_92 ) ;
goto V_27;
}
F_6 ( L_36 , * ( T_1 * ) & V_93 ,
V_145 ) ;
} else {
F_31 ( & V_101 -> V_112 , V_93 ) ;
}
}
* V_21 = V_22 ;
return V_101 ;
V_27:
F_18 ( L_48 ,
V_125 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_46 , V_22 ) ;
F_57 ( V_146 , L_49 ,
V_147 , 16 , 1 ,
V_46 , V_22 - V_46 , true ) ;
if ( V_135 )
F_24 ( V_135 ) ;
return F_17 ( V_44 ) ;
}
void F_58 ( struct V_148 * V_149 ,
T_1 V_142 , T_1 * V_150 ,
T_1 * V_151 ,
T_1 * V_152 , T_1 * V_153 )
{
V_26 V_154 = F_4 ( V_149 -> V_155 ) ;
V_26 V_156 = F_4 ( V_149 -> V_157 ) ;
V_26 V_158 = F_4 ( V_149 -> V_159 ) ;
V_26 V_160 , V_161 , V_162 , V_163 ;
V_26 V_164 ;
T_1 V_8 , V_165 ;
F_6 ( L_50 , V_142 , * V_150 ,
V_154 , V_156 ) ;
V_164 = V_154 / V_156 ;
F_6 ( L_51 , V_154 , V_156 ,
V_164 ) ;
F_19 ( ( V_156 & ~ V_166 ) != 0 ) ;
V_8 = V_142 ;
F_59 ( V_8 , V_156 ) ;
V_160 = V_8 ;
F_6 ( L_52 , V_142 , V_156 , V_160 ) ;
V_161 = V_160 / V_158 ;
V_162 = V_160 % V_158 ;
V_163 = V_161 / V_164 ;
* V_151 = V_163 * V_158 + V_162 ;
F_6 ( L_53 , V_163 , V_158 , ( unsigned int ) * V_151 ) ;
V_8 = V_142 ;
V_165 = F_59 ( V_8 , V_156 ) ;
* V_152 = V_165 + ( V_161 % V_164 ) * V_156 ;
* V_153 = F_60 ( T_1 , * V_150 , V_156 - V_165 ) ;
* V_150 = * V_153 ;
F_6 ( L_54 , * V_152 , * V_153 ) ;
}
int F_61 ( struct V_167 * V_168 ,
const char * V_169 ,
struct V_148 * V_170 ,
struct V_100 * V_171 )
{
unsigned int V_109 , V_172 ;
struct V_83 V_93 ;
int V_173 = F_4 ( V_170 -> V_174 ) ;
struct V_10 * V_110 ;
unsigned int V_175 ;
F_19 ( ! V_171 ) ;
V_110 = F_35 ( & V_171 -> V_104 , V_173 ) ;
if ( ! V_110 )
return - V_176 ;
V_175 = F_62 ( V_110 -> V_13 . V_177 , V_169 , strlen ( V_169 ) ) ;
V_109 = F_4 ( V_110 -> V_13 . V_14 ) ;
V_172 = V_110 -> V_12 ;
V_93 . V_175 = F_63 ( V_175 ) ;
V_93 . V_178 = F_63 ( - 1 ) ;
V_93 . V_110 = V_170 -> V_174 ;
F_6 ( L_55 , V_169 , V_173 , V_175 ) ;
V_168 -> V_179 = V_93 ;
V_168 -> V_180 = V_170 -> V_181 ;
return 0 ;
}
static int * F_64 ( struct V_100 * V_171 , struct V_83 V_93 ,
int * V_132 , int * V_109 )
{
struct V_86 * V_92 ;
struct V_10 * V_110 ;
int V_182 ;
unsigned int V_173 , V_175 , V_183 , V_8 , V_74 ;
V_173 = F_4 ( V_93 . V_110 ) ;
V_175 = F_65 ( V_93 . V_175 ) ;
V_110 = F_35 ( & V_171 -> V_104 , V_173 ) ;
if ( ! V_110 )
return NULL ;
V_8 = F_66 ( V_175 , F_4 ( V_110 -> V_13 . V_14 ) ,
V_110 -> V_15 ) ;
V_93 . V_175 = F_63 ( V_8 ) ;
V_92 = F_30 ( & V_171 -> V_112 , V_93 ) ;
if ( V_92 ) {
* V_109 = V_92 -> V_2 ;
return V_92 -> V_132 ;
}
V_182 = F_67 ( V_171 -> V_111 , V_110 -> V_13 . V_184 ,
V_110 -> V_13 . type , V_110 -> V_13 . V_25 ) ;
if ( V_182 < 0 ) {
F_18 ( L_56 ,
V_173 , V_110 -> V_13 . V_184 , V_110 -> V_13 . type ,
V_110 -> V_13 . V_25 ) ;
return NULL ;
}
V_183 = F_66 ( V_175 ,
F_4 ( V_110 -> V_13 . V_16 ) ,
V_110 -> V_15 ) ;
V_183 += V_173 ;
V_74 = F_68 ( V_171 -> V_111 , V_182 , V_183 , V_132 ,
F_60 ( int , V_110 -> V_13 . V_25 , * V_109 ) ,
V_171 -> V_114 ) ;
if ( V_74 < 0 ) {
F_18 ( L_57
L_58 , V_74 , V_173 , V_110 -> V_13 . V_184 ,
V_110 -> V_13 . type , V_110 -> V_13 . V_25 ) ;
return NULL ;
}
* V_109 = V_74 ;
return V_132 ;
}
int F_69 ( struct V_100 * V_171 , struct V_83 V_93 ,
int * V_185 )
{
int V_186 [ V_187 ] , * V_132 ;
int V_45 , V_188 , V_109 = V_187 ;
V_132 = F_64 ( V_171 , V_93 , V_186 , & V_109 ) ;
if ( ! V_132 )
return - 1 ;
V_188 = 0 ;
for ( V_45 = 0 ; V_45 < V_109 ; V_45 ++ )
if ( F_70 ( V_171 , V_132 [ V_45 ] ) )
V_185 [ V_188 ++ ] = V_132 [ V_45 ] ;
return V_188 ;
}
int F_71 ( struct V_100 * V_171 , struct V_83 V_93 )
{
int V_186 [ V_187 ] , * V_132 ;
int V_45 , V_109 = V_187 ;
V_132 = F_64 ( V_171 , V_93 , V_186 , & V_109 ) ;
if ( ! V_132 )
return - 1 ;
for ( V_45 = 0 ; V_45 < V_109 ; V_45 ++ )
if ( F_70 ( V_171 , V_132 [ V_45 ] ) )
return V_132 [ V_45 ] ;
return - 1 ;
}
