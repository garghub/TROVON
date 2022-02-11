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
static int F_2 ( unsigned V_8 )
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
( unsigned ) V_47 , ( unsigned ) V_48 ) ;
goto V_27;
}
V_43 -> V_49 = F_8 ( V_21 ) ;
V_43 -> V_50 = F_8 ( V_21 ) ;
V_43 -> V_51 = F_8 ( V_21 ) ;
V_43 -> V_52 = F_10 ( V_43 -> V_51 , sizeof( V_26 ) , V_33 ) ;
if ( V_43 -> V_52 == NULL )
goto V_53;
V_43 -> V_54 = F_10 ( V_43 -> V_49 , sizeof( V_26 ) , V_33 ) ;
if ( V_43 -> V_54 == NULL )
goto V_53;
V_43 -> V_55 = F_10 ( V_43 -> V_49 , sizeof( * V_43 -> V_55 ) , V_33 ) ;
if ( V_43 -> V_55 == NULL )
goto V_53;
V_43 -> V_56 = F_10 ( V_43 -> V_50 , sizeof( * V_43 -> V_56 ) , V_33 ) ;
if ( V_43 -> V_56 == NULL )
goto V_53;
for ( V_45 = 0 ; V_45 < V_43 -> V_49 ; V_45 ++ ) {
int V_25 = 0 ;
V_26 V_57 ;
struct V_58 * V_9 ;
F_12 ( V_21 , V_22 , V_57 , V_27 ) ;
if ( V_57 == 0 ) {
V_43 -> V_55 [ V_45 ] = NULL ;
continue;
}
F_6 ( L_13 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
switch ( V_57 ) {
case V_59 :
V_25 = sizeof( struct V_23 ) ;
break;
case V_60 :
V_25 = sizeof( struct V_30 ) ;
break;
case V_61 :
V_25 = sizeof( struct V_36 ) ;
break;
case V_62 :
V_25 = sizeof( struct V_39 ) ;
break;
default:
V_44 = - V_29 ;
goto V_27;
}
F_18 ( V_25 == 0 ) ;
V_9 = V_43 -> V_55 [ V_45 ] = F_15 ( V_25 , V_33 ) ;
if ( V_9 == NULL )
goto V_53;
F_7 ( V_21 , V_22 , 4 * sizeof( V_26 ) , V_27 ) ;
V_9 -> V_63 = F_8 ( V_21 ) ;
V_9 -> type = F_19 ( V_21 ) ;
V_9 -> V_57 = F_20 ( V_21 ) ;
V_9 -> V_64 = F_20 ( V_21 ) ;
V_9 -> V_65 = F_8 ( V_21 ) ;
V_9 -> V_25 = F_8 ( V_21 ) ;
F_6 ( L_14 ,
V_9 -> V_25 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
V_9 -> V_66 = F_10 ( V_9 -> V_25 , sizeof( V_67 ) , V_33 ) ;
if ( V_9 -> V_66 == NULL )
goto V_53;
V_9 -> V_68 = F_10 ( V_9 -> V_25 , sizeof( V_26 ) , V_33 ) ;
if ( V_9 -> V_68 == NULL )
goto V_53;
V_9 -> V_69 = 0 ;
F_7 ( V_21 , V_22 , V_9 -> V_25 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_9 -> V_25 ; V_31 ++ )
V_9 -> V_66 [ V_31 ] = F_8 ( V_21 ) ;
switch ( V_9 -> V_57 ) {
case V_59 :
V_44 = F_5 ( V_21 , V_22 ,
(struct V_23 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_60 :
V_44 = F_9 ( V_21 , V_22 ,
(struct V_30 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_61 :
V_44 = F_11 ( V_21 , V_22 ,
(struct V_36 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
case V_62 :
V_44 = F_13 ( V_21 , V_22 ,
(struct V_39 * ) V_9 ) ;
if ( V_44 < 0 )
goto V_27;
break;
}
}
F_6 ( L_15 , V_43 -> V_56 ) ;
for ( V_45 = 0 ; V_45 < V_43 -> V_50 ; V_45 ++ ) {
V_26 V_70 ;
struct V_71 * V_72 ;
F_12 ( V_21 , V_22 , V_70 , V_27 ) ;
if ( ! V_70 ) {
F_6 ( L_16 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
V_43 -> V_56 [ V_45 ] = NULL ;
continue;
}
F_6 ( L_17 ,
V_45 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_22 ) ;
F_12 ( V_21 , V_22 , V_70 , V_27 ) ;
#if V_73 == 32
V_44 = - V_29 ;
if ( V_70 > V_74 / sizeof( struct V_75 ) )
goto V_27;
#endif
V_72 = V_43 -> V_56 [ V_45 ] = F_21 ( sizeof( * V_72 ) +
V_70 * sizeof( struct V_75 ) ,
V_33 ) ;
if ( V_72 == NULL )
goto V_53;
F_6 ( L_18 , V_45 , V_72 ) ;
V_72 -> V_2 = V_70 ;
F_22 ( V_21 , V_22 , & V_72 -> V_76 , 4 , V_27 ) ;
F_7 ( V_21 , V_22 , V_72 -> V_2 * 3 * sizeof( V_26 ) , V_27 ) ;
for ( V_31 = 0 ; V_31 < V_72 -> V_2 ; V_31 ++ ) {
V_72 -> V_77 [ V_31 ] . V_78 = F_8 ( V_21 ) ;
V_72 -> V_77 [ V_31 ] . V_79 = F_8 ( V_21 ) ;
V_72 -> V_77 [ V_31 ] . V_80 = F_8 ( V_21 ) ;
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
static int F_24 ( struct V_81 V_82 , struct V_81 V_72 )
{
T_1 V_83 = * ( T_1 * ) & V_82 ;
T_1 V_9 = * ( T_1 * ) & V_72 ;
if ( V_83 < V_9 )
return - 1 ;
if ( V_83 > V_9 )
return 1 ;
return 0 ;
}
static int F_25 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_88 * * V_21 = & V_87 -> V_88 ;
struct V_88 * V_89 = NULL ;
struct V_84 * V_90 = NULL ;
int V_43 ;
while ( * V_21 ) {
V_89 = * V_21 ;
V_90 = F_26 ( V_89 , struct V_84 , V_91 ) ;
V_43 = F_24 ( V_85 -> V_92 , V_90 -> V_92 ) ;
if ( V_43 < 0 )
V_21 = & ( * V_21 ) -> V_93 ;
else if ( V_43 > 0 )
V_21 = & ( * V_21 ) -> V_94 ;
else
return - V_95 ;
}
F_27 ( & V_85 -> V_91 , V_89 , V_21 ) ;
F_28 ( & V_85 -> V_91 , V_87 ) ;
return 0 ;
}
static struct V_84 * F_29 ( struct V_86 * V_87 ,
struct V_81 V_92 )
{
struct V_88 * V_96 = V_87 -> V_88 ;
struct V_84 * V_90 ;
int V_43 ;
while ( V_96 ) {
V_90 = F_26 ( V_96 , struct V_84 , V_91 ) ;
V_43 = F_24 ( V_92 , V_90 -> V_92 ) ;
if ( V_43 < 0 )
V_96 = V_96 -> V_93 ;
else if ( V_43 > 0 )
V_96 = V_96 -> V_94 ;
else
return V_90 ;
}
return NULL ;
}
static int F_30 ( struct V_86 * V_87 , struct V_10 * V_85 )
{
struct V_88 * * V_21 = & V_87 -> V_88 ;
struct V_88 * V_89 = NULL ;
struct V_10 * V_11 = NULL ;
while ( * V_21 ) {
V_89 = * V_21 ;
V_11 = F_26 ( V_89 , struct V_10 , V_91 ) ;
if ( V_85 -> V_63 < V_11 -> V_63 )
V_21 = & ( * V_21 ) -> V_93 ;
else if ( V_85 -> V_63 > V_11 -> V_63 )
V_21 = & ( * V_21 ) -> V_94 ;
else
return - V_95 ;
}
F_27 ( & V_85 -> V_91 , V_89 , V_21 ) ;
F_28 ( & V_85 -> V_91 , V_87 ) ;
return 0 ;
}
static struct V_10 * F_31 ( struct V_86 * V_87 , int V_63 )
{
struct V_10 * V_11 ;
struct V_88 * V_96 = V_87 -> V_88 ;
while ( V_96 ) {
V_11 = F_26 ( V_96 , struct V_10 , V_91 ) ;
if ( V_63 < V_11 -> V_63 )
V_96 = V_96 -> V_93 ;
else if ( V_63 > V_11 -> V_63 )
V_96 = V_96 -> V_94 ;
else
return V_11 ;
}
return NULL ;
}
int F_32 ( struct V_97 * V_98 , const char * V_99 )
{
struct V_88 * V_100 ;
for ( V_100 = F_33 ( & V_98 -> V_101 ) ; V_100 ; V_100 = F_34 ( V_100 ) ) {
struct V_10 * V_11 =
F_26 ( V_100 , struct V_10 , V_91 ) ;
if ( V_11 -> V_99 && strcmp ( V_11 -> V_99 , V_99 ) == 0 )
return V_11 -> V_63 ;
}
return - V_102 ;
}
static void F_35 ( struct V_86 * V_87 , struct V_10 * V_11 )
{
F_36 ( & V_11 -> V_91 , V_87 ) ;
F_37 ( V_11 -> V_99 ) ;
F_37 ( V_11 ) ;
}
static int F_38 ( void * * V_21 , void * V_22 , struct V_10 * V_11 )
{
unsigned V_96 , V_103 ;
F_39 ( V_21 , & V_11 -> V_13 , sizeof( V_11 -> V_13 ) ) ;
F_3 ( V_11 ) ;
V_96 = F_4 ( V_11 -> V_13 . V_104 ) ;
while ( V_96 -- ) {
F_7 ( V_21 , V_22 , sizeof( T_1 ) + 1 + sizeof( T_1 ) +
sizeof( struct V_105 ) , V_27 ) ;
* V_21 += sizeof( T_1 ) +
1 + sizeof( T_1 ) +
sizeof( struct V_105 ) ;
V_103 = F_8 ( V_21 ) ;
* V_21 += V_103 ;
}
* V_21 += F_4 ( V_11 -> V_13 . V_106 ) * sizeof( T_1 ) * 2 ;
return 0 ;
V_27:
return - V_29 ;
}
static int F_40 ( void * * V_21 , void * V_22 , struct V_97 * V_98 )
{
struct V_10 * V_11 ;
V_26 V_107 , V_2 , V_108 ;
F_12 ( V_21 , V_22 , V_107 , V_27 ) ;
F_6 ( L_21 , V_107 ) ;
while ( V_107 -- ) {
F_12 ( V_21 , V_22 , V_108 , V_27 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
F_6 ( L_22 , V_108 , V_2 ) ;
V_11 = F_31 ( & V_98 -> V_101 , V_108 ) ;
if ( V_11 ) {
F_37 ( V_11 -> V_99 ) ;
V_11 -> V_99 = F_21 ( V_2 + 1 , V_33 ) ;
if ( V_11 -> V_99 ) {
memcpy ( V_11 -> V_99 , * V_21 , V_2 ) ;
V_11 -> V_99 [ V_2 ] = '\0' ;
F_6 ( L_23 , V_11 -> V_99 ) ;
}
}
* V_21 += V_2 ;
}
return 0 ;
V_27:
return - V_29 ;
}
void F_41 ( struct V_97 * V_98 )
{
F_6 ( L_24 , V_98 ) ;
if ( V_98 -> V_109 )
F_23 ( V_98 -> V_109 ) ;
while ( ! F_42 ( & V_98 -> V_110 ) ) {
struct V_84 * V_90 =
F_26 ( F_33 ( & V_98 -> V_110 ) ,
struct V_84 , V_91 ) ;
F_36 ( & V_90 -> V_91 , & V_98 -> V_110 ) ;
F_37 ( V_90 ) ;
}
while ( ! F_42 ( & V_98 -> V_101 ) ) {
struct V_10 * V_11 =
F_26 ( F_33 ( & V_98 -> V_101 ) ,
struct V_10 , V_91 ) ;
F_35 ( & V_98 -> V_101 , V_11 ) ;
}
F_37 ( V_98 -> V_111 ) ;
F_37 ( V_98 -> V_112 ) ;
F_37 ( V_98 -> V_113 ) ;
F_37 ( V_98 ) ;
}
static int F_43 ( struct V_97 * V_98 , int V_114 )
{
T_2 * V_3 ;
struct V_115 * V_116 ;
V_26 * V_65 ;
V_3 = F_10 ( V_114 , sizeof( * V_3 ) , V_33 ) ;
V_116 = F_10 ( V_114 , sizeof( * V_116 ) , V_33 ) ;
V_65 = F_10 ( V_114 , sizeof( * V_65 ) , V_33 ) ;
if ( V_3 == NULL || V_116 == NULL || V_65 == NULL ) {
F_37 ( V_3 ) ;
F_37 ( V_116 ) ;
F_37 ( V_65 ) ;
return - V_34 ;
}
if ( V_98 -> V_111 ) {
memcpy ( V_3 , V_98 -> V_111 , V_98 -> V_117 * sizeof( * V_3 ) ) ;
memcpy ( V_116 , V_98 -> V_113 , V_98 -> V_117 * sizeof( * V_116 ) ) ;
memcpy ( V_65 , V_98 -> V_112 , V_98 -> V_117 * sizeof( * V_65 ) ) ;
F_37 ( V_98 -> V_111 ) ;
F_37 ( V_98 -> V_113 ) ;
F_37 ( V_98 -> V_112 ) ;
}
V_98 -> V_111 = V_3 ;
V_98 -> V_112 = V_65 ;
V_98 -> V_113 = V_116 ;
V_98 -> V_117 = V_114 ;
return 0 ;
}
struct V_97 * F_44 ( void * * V_21 , void * V_22 )
{
struct V_97 * V_98 ;
T_3 V_118 ;
V_26 V_2 , V_114 , V_45 ;
T_2 V_119 ;
int V_44 = - V_29 ;
void * V_46 = * V_21 ;
struct V_10 * V_11 ;
F_6 ( L_25 , * V_21 , V_22 , ( int ) ( V_22 - * V_21 ) ) ;
V_98 = F_15 ( sizeof( * V_98 ) , V_33 ) ;
if ( V_98 == NULL )
return F_16 ( - V_34 ) ;
V_98 -> V_110 = V_120 ;
F_45 ( V_21 , V_22 , V_118 , V_27 ) ;
if ( V_118 > V_121 ) {
F_46 ( L_26 , V_118 ,
V_121 ) ;
goto V_27;
}
F_7 ( V_21 , V_22 , 2 * sizeof( T_1 ) + 6 * sizeof( V_26 ) , V_27 ) ;
F_39 ( V_21 , & V_98 -> V_122 , sizeof( V_98 -> V_122 ) ) ;
V_98 -> V_123 = F_8 ( V_21 ) ;
F_39 ( V_21 , & V_98 -> V_124 , sizeof( V_98 -> V_124 ) ) ;
F_39 ( V_21 , & V_98 -> V_125 , sizeof( V_98 -> V_125 ) ) ;
F_12 ( V_21 , V_22 , V_114 , V_27 ) ;
while ( V_114 -- ) {
F_7 ( V_21 , V_22 , 4 + 1 + sizeof( V_11 -> V_13 ) , V_27 ) ;
V_11 = F_15 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 )
goto V_27;
V_11 -> V_63 = F_8 ( V_21 ) ;
V_119 = F_20 ( V_21 ) ;
if ( V_119 > V_126 ) {
F_46 ( L_27 ,
V_119 , V_126 ) ;
F_37 ( V_11 ) ;
goto V_27;
}
V_44 = F_38 ( V_21 , V_22 , V_11 ) ;
if ( V_44 < 0 ) {
F_37 ( V_11 ) ;
goto V_27;
}
F_30 ( & V_98 -> V_101 , V_11 ) ;
}
if ( V_118 >= 5 && F_40 ( V_21 , V_22 , V_98 ) < 0 )
goto V_27;
F_12 ( V_21 , V_22 , V_98 -> V_127 , V_27 ) ;
F_12 ( V_21 , V_22 , V_98 -> V_128 , V_27 ) ;
V_114 = F_8 ( V_21 ) ;
V_44 = F_43 ( V_98 , V_114 ) ;
if ( V_44 < 0 )
goto V_27;
F_6 ( L_28 , V_98 -> V_117 ) ;
V_44 = - V_29 ;
F_7 ( V_21 , V_22 , 3 * sizeof( V_26 ) +
V_98 -> V_117 * ( 1 + sizeof( * V_98 -> V_112 ) +
sizeof( * V_98 -> V_113 ) ) , V_27 ) ;
* V_21 += 4 ;
F_39 ( V_21 , V_98 -> V_111 , V_98 -> V_117 ) ;
* V_21 += 4 ;
for ( V_45 = 0 ; V_45 < V_98 -> V_117 ; V_45 ++ )
V_98 -> V_112 [ V_45 ] = F_8 ( V_21 ) ;
* V_21 += 4 ;
F_39 ( V_21 , V_98 -> V_113 , V_98 -> V_117 * sizeof( * V_98 -> V_113 ) ) ;
for ( V_45 = 0 ; V_45 < V_98 -> V_117 ; V_45 ++ )
F_47 ( & V_98 -> V_113 [ V_45 ] ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
for ( V_45 = 0 ; V_45 < V_2 ; V_45 ++ ) {
int V_96 , V_31 ;
struct V_81 V_92 ;
struct V_84 * V_90 ;
F_7 ( V_21 , V_22 , sizeof( V_26 ) + sizeof( T_1 ) , V_27 ) ;
F_39 ( V_21 , & V_92 , sizeof( V_92 ) ) ;
V_96 = F_8 ( V_21 ) ;
F_7 ( V_21 , V_22 , V_96 * sizeof( V_26 ) , V_27 ) ;
V_44 = - V_34 ;
V_90 = F_21 ( sizeof( * V_90 ) + V_96 * sizeof( V_26 ) , V_33 ) ;
if ( ! V_90 )
goto V_27;
V_90 -> V_92 = V_92 ;
V_90 -> V_2 = V_96 ;
for ( V_31 = 0 ; V_31 < V_96 ; V_31 ++ )
V_90 -> V_129 [ V_31 ] = F_8 ( V_21 ) ;
V_44 = F_25 ( V_90 , & V_98 -> V_110 ) ;
if ( V_44 )
goto V_27;
F_6 ( L_29 , * ( T_1 * ) & V_92 , V_2 ) ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
F_6 ( L_30 , V_2 ,
( int ) ( * V_21 - V_46 ) ) ;
F_7 ( V_21 , V_22 , V_2 , V_27 ) ;
V_98 -> V_109 = F_14 ( * V_21 , V_22 ) ;
* V_21 += V_2 ;
if ( F_48 ( V_98 -> V_109 ) ) {
V_44 = F_49 ( V_98 -> V_109 ) ;
V_98 -> V_109 = NULL ;
goto V_27;
}
* V_21 = V_22 ;
F_6 ( L_31 , * V_21 , V_22 ) ;
return V_98 ;
V_27:
F_6 ( L_32 ) ;
F_41 ( V_98 ) ;
return F_16 ( V_44 ) ;
}
struct V_97 * F_50 ( void * * V_21 , void * V_22 ,
struct V_97 * V_98 ,
struct V_130 * V_131 )
{
struct V_41 * V_132 = NULL ;
struct V_133 V_122 ;
V_26 V_123 = 0 ;
struct V_105 V_125 ;
V_26 V_2 , V_108 ;
V_67 V_134 , V_135 , V_114 ;
void * V_46 = * V_21 ;
int V_44 = - V_29 ;
T_3 V_118 ;
struct V_88 * V_100 ;
F_45 ( V_21 , V_22 , V_118 , V_27 ) ;
if ( V_118 > V_136 ) {
F_46 ( L_33 , V_118 ,
V_136 ) ;
goto V_27;
}
F_7 ( V_21 , V_22 , sizeof( V_122 ) + sizeof( V_125 ) + 2 * sizeof( V_26 ) ,
V_27 ) ;
F_39 ( V_21 , & V_122 , sizeof( V_122 ) ) ;
V_123 = F_8 ( V_21 ) ;
F_18 ( V_123 != V_98 -> V_123 + 1 ) ;
F_39 ( V_21 , & V_125 , sizeof( V_125 ) ) ;
V_134 = F_8 ( V_21 ) ;
V_135 = F_8 ( V_21 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
if ( V_2 > 0 ) {
F_6 ( L_34 ,
V_2 , * V_21 , V_22 ) ;
return F_44 ( V_21 , F_51 ( * V_21 + V_2 , V_22 ) ) ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
if ( V_2 > 0 ) {
F_6 ( L_35 ,
V_2 , * V_21 , V_22 ) ;
V_132 = F_14 ( * V_21 , F_51 ( * V_21 + V_2 , V_22 ) ) ;
if ( F_48 ( V_132 ) )
return F_52 ( V_132 ) ;
* V_21 += V_2 ;
}
if ( V_135 >= 0 )
V_98 -> V_128 = V_135 ;
if ( V_134 >= 0 )
V_98 -> V_127 = V_134 ;
F_7 ( V_21 , V_22 , 5 * sizeof( V_26 ) , V_27 ) ;
V_114 = F_8 ( V_21 ) ;
if ( V_114 >= 0 ) {
V_44 = F_43 ( V_98 , V_114 ) ;
if ( V_44 < 0 )
goto V_27;
}
V_98 -> V_123 ++ ;
V_98 -> V_125 = V_125 ;
if ( V_132 ) {
if ( V_98 -> V_109 )
F_23 ( V_98 -> V_109 ) ;
V_98 -> V_109 = V_132 ;
V_132 = NULL ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
T_4 V_119 ;
struct V_10 * V_11 ;
F_12 ( V_21 , V_22 , V_108 , V_27 ) ;
F_7 ( V_21 , V_22 , 1 + sizeof( V_11 -> V_13 ) , V_27 ) ;
V_119 = F_20 ( V_21 ) ;
if ( V_119 > V_126 ) {
F_46 ( L_27 ,
V_119 , V_126 ) ;
goto V_27;
}
V_11 = F_31 ( & V_98 -> V_101 , V_108 ) ;
if ( ! V_11 ) {
V_11 = F_15 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 ) {
V_44 = - V_34 ;
goto V_27;
}
V_11 -> V_63 = V_108 ;
F_30 ( & V_98 -> V_101 , V_11 ) ;
}
V_44 = F_38 ( V_21 , V_22 , V_11 ) ;
if ( V_44 < 0 )
goto V_27;
}
if ( V_118 >= 5 && F_40 ( V_21 , V_22 , V_98 ) < 0 )
goto V_27;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
struct V_10 * V_11 ;
F_12 ( V_21 , V_22 , V_108 , V_27 ) ;
V_11 = F_31 ( & V_98 -> V_101 , V_108 ) ;
if ( V_11 )
F_35 ( & V_98 -> V_101 , V_11 ) ;
}
V_44 = - V_29 ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_137 ;
struct V_115 V_116 ;
F_12 ( V_21 , V_22 , V_137 , V_27 ) ;
F_22 ( V_21 , V_22 , & V_116 , sizeof( V_116 ) , V_27 ) ;
F_47 ( & V_116 ) ;
F_53 ( L_36 , V_137 ) ;
F_18 ( V_137 >= V_98 -> V_117 ) ;
V_98 -> V_111 [ V_137 ] |= V_7 ;
V_98 -> V_113 [ V_137 ] = V_116 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_137 ;
T_2 V_138 ;
F_12 ( V_21 , V_22 , V_137 , V_27 ) ;
V_138 = * * ( T_2 * * ) V_21 ;
( * V_21 ) ++ ;
if ( V_138 == 0 )
V_138 = V_7 ;
if ( V_138 & V_7 )
F_53 ( L_37 , V_137 ) ;
if ( V_137 < V_98 -> V_117 )
V_98 -> V_111 [ V_137 ] ^= V_138 ;
}
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
V_26 V_137 , V_139 ;
F_7 ( V_21 , V_22 , sizeof( V_26 ) * 2 , V_27 ) ;
V_137 = F_8 ( V_21 ) ;
V_139 = F_8 ( V_21 ) ;
F_53 ( L_38 , V_137 , V_139 ,
V_139 == V_140 ? L_39 :
( V_139 == V_141 ? L_40 : L_4 ) ) ;
if ( V_137 < V_98 -> V_117 )
V_98 -> V_112 [ V_137 ] = V_139 ;
}
V_100 = F_33 ( & V_98 -> V_110 ) ;
F_12 ( V_21 , V_22 , V_2 , V_27 ) ;
while ( V_2 -- ) {
struct V_84 * V_90 ;
int V_31 ;
struct V_81 V_92 ;
V_26 V_142 ;
F_7 ( V_21 , V_22 , sizeof( T_1 ) + sizeof( V_26 ) , V_27 ) ;
F_39 ( V_21 , & V_92 , sizeof( V_92 ) ) ;
V_142 = F_8 ( V_21 ) ;
while ( V_100 && F_24 ( F_26 ( V_100 , struct V_84 ,
V_91 ) -> V_92 , V_92 ) <= 0 ) {
struct V_84 * V_143 =
F_26 ( V_100 , struct V_84 , V_91 ) ;
V_100 = F_34 ( V_100 ) ;
F_6 ( L_41 , * ( T_1 * ) & V_143 -> V_92 ) ;
F_36 ( & V_143 -> V_91 , & V_98 -> V_110 ) ;
F_37 ( V_143 ) ;
}
if ( V_142 ) {
F_7 ( V_21 , V_22 , V_142 * sizeof( V_26 ) , V_27 ) ;
V_90 = F_21 ( sizeof( * V_90 ) + sizeof( V_26 ) * V_142 , V_33 ) ;
if ( ! V_90 ) {
V_44 = - V_34 ;
goto V_27;
}
V_90 -> V_92 = V_92 ;
V_90 -> V_2 = V_142 ;
for ( V_31 = 0 ; V_31 < V_142 ; V_31 ++ )
V_90 -> V_129 [ V_31 ] = F_8 ( V_21 ) ;
V_44 = F_25 ( V_90 , & V_98 -> V_110 ) ;
if ( V_44 ) {
F_37 ( V_90 ) ;
goto V_27;
}
F_6 ( L_29 , * ( T_1 * ) & V_92 ,
V_142 ) ;
}
}
while ( V_100 ) {
struct V_84 * V_143 =
F_26 ( V_100 , struct V_84 , V_91 ) ;
V_100 = F_34 ( V_100 ) ;
F_6 ( L_41 , * ( T_1 * ) & V_143 -> V_92 ) ;
F_36 ( & V_143 -> V_91 , & V_98 -> V_110 ) ;
F_37 ( V_143 ) ;
}
* V_21 = V_22 ;
return V_98 ;
V_27:
F_17 ( L_42 ,
V_123 , ( int ) ( * V_21 - V_46 ) , * V_21 , V_46 , V_22 ) ;
F_54 ( V_144 , L_43 ,
V_145 , 16 , 1 ,
V_46 , V_22 - V_46 , true ) ;
if ( V_132 )
F_23 ( V_132 ) ;
return F_16 ( V_44 ) ;
}
void F_55 ( struct V_146 * V_147 ,
T_1 V_139 , T_1 * V_148 ,
T_1 * V_149 ,
T_1 * V_150 , T_1 * V_151 )
{
V_26 V_152 = F_4 ( V_147 -> V_153 ) ;
V_26 V_154 = F_4 ( V_147 -> V_155 ) ;
V_26 V_156 = F_4 ( V_147 -> V_157 ) ;
V_26 V_158 , V_159 , V_160 , V_161 ;
V_26 V_162 ;
T_1 V_8 , V_163 ;
F_6 ( L_44 , V_139 , * V_148 ,
V_152 , V_154 ) ;
V_162 = V_152 / V_154 ;
F_6 ( L_45 , V_152 , V_154 ,
V_162 ) ;
F_18 ( ( V_154 & ~ V_164 ) != 0 ) ;
V_8 = V_139 ;
F_56 ( V_8 , V_154 ) ;
V_158 = V_8 ;
F_6 ( L_46 , V_139 , V_154 , V_158 ) ;
V_159 = V_158 / V_156 ;
V_160 = V_158 % V_156 ;
V_161 = V_159 / V_162 ;
* V_149 = V_161 * V_156 + V_160 ;
F_6 ( L_47 , V_161 , V_156 , ( unsigned ) * V_149 ) ;
V_8 = V_139 ;
V_163 = F_56 ( V_8 , V_154 ) ;
* V_150 = V_163 + ( V_159 % V_162 ) * V_154 ;
* V_151 = F_57 ( T_1 , * V_148 , V_154 - V_163 ) ;
* V_148 = * V_151 ;
F_6 ( L_48 , * V_150 , * V_151 ) ;
}
int F_58 ( struct V_165 * V_166 ,
const char * V_167 ,
struct V_146 * V_168 ,
struct V_97 * V_169 )
{
unsigned V_107 , V_170 ;
struct V_81 V_92 ;
T_5 V_171 = ( T_5 ) F_4 ( V_168 -> V_172 ) ;
int V_173 = F_4 ( V_168 -> V_174 ) ;
struct V_10 * V_108 ;
unsigned V_175 ;
F_18 ( ! V_169 ) ;
V_108 = F_31 ( & V_169 -> V_101 , V_173 ) ;
if ( ! V_108 )
return - V_176 ;
V_175 = F_59 ( V_108 -> V_13 . V_177 , V_167 , strlen ( V_167 ) ) ;
if ( V_171 >= 0 ) {
V_175 += V_171 ;
V_107 = F_4 ( V_108 -> V_13 . V_18 ) ;
V_170 = V_108 -> V_17 ;
} else {
V_107 = F_4 ( V_108 -> V_13 . V_14 ) ;
V_170 = V_108 -> V_12 ;
}
V_92 . V_175 = F_60 ( V_175 ) ;
V_92 . V_171 = F_60 ( V_171 ) ;
V_92 . V_108 = V_168 -> V_174 ;
if ( V_171 >= 0 )
F_6 ( L_49 , V_167 , V_173 , V_175 ,
( int ) V_171 ) ;
else
F_6 ( L_50 , V_167 , V_173 , V_175 ) ;
V_166 -> V_178 = V_92 ;
V_166 -> V_179 = V_168 -> V_180 ;
return 0 ;
}
static int * F_61 ( struct V_97 * V_169 , struct V_81 V_92 ,
int * V_129 , int * V_107 )
{
struct V_84 * V_90 ;
struct V_10 * V_108 ;
int V_181 ;
unsigned V_173 , V_175 , V_182 ;
int V_171 ;
V_90 = F_29 ( & V_169 -> V_110 , V_92 ) ;
if ( V_90 ) {
* V_107 = V_90 -> V_2 ;
return V_90 -> V_129 ;
}
V_173 = F_4 ( V_92 . V_108 ) ;
V_175 = F_62 ( V_92 . V_175 ) ;
V_171 = ( V_183 ) F_62 ( V_92 . V_171 ) ;
if ( V_171 >= V_169 -> V_117 ||
V_171 >= V_169 -> V_109 -> V_51 )
V_171 = - 1 ;
V_108 = F_31 ( & V_169 -> V_101 , V_173 ) ;
if ( ! V_108 )
return NULL ;
V_181 = F_63 ( V_169 -> V_109 , V_108 -> V_13 . V_184 ,
V_108 -> V_13 . type , V_108 -> V_13 . V_25 ) ;
if ( V_181 < 0 ) {
F_17 ( L_51 ,
V_173 , V_108 -> V_13 . V_184 , V_108 -> V_13 . type ,
V_108 -> V_13 . V_25 ) ;
return NULL ;
}
if ( V_171 >= 0 )
V_182 = F_64 ( V_175 ,
F_4 ( V_108 -> V_13 . V_20 ) ,
V_108 -> V_19 ) ;
else
V_182 = F_64 ( V_175 ,
F_4 ( V_108 -> V_13 . V_16 ) ,
V_108 -> V_15 ) ;
V_182 += V_173 ;
* V_107 = F_65 ( V_169 -> V_109 , V_181 , V_182 , V_129 ,
F_57 ( int , V_108 -> V_13 . V_25 , * V_107 ) ,
V_171 , V_169 -> V_112 ) ;
return V_129 ;
}
int F_66 ( struct V_97 * V_169 , struct V_81 V_92 ,
int * V_185 )
{
int V_186 [ V_187 ] , * V_129 ;
int V_45 , V_188 , V_107 = V_187 ;
V_129 = F_61 ( V_169 , V_92 , V_186 , & V_107 ) ;
if ( ! V_129 )
return - 1 ;
V_188 = 0 ;
for ( V_45 = 0 ; V_45 < V_107 ; V_45 ++ )
if ( F_67 ( V_169 , V_129 [ V_45 ] ) )
V_185 [ V_188 ++ ] = V_129 [ V_45 ] ;
return V_188 ;
}
int F_68 ( struct V_97 * V_169 , struct V_81 V_92 )
{
int V_186 [ V_187 ] , * V_129 ;
int V_45 , V_107 = V_187 ;
V_129 = F_61 ( V_169 , V_92 , V_186 , & V_107 ) ;
if ( ! V_129 )
return - 1 ;
for ( V_45 = 0 ; V_45 < V_107 ; V_45 ++ )
if ( F_67 ( V_169 , V_129 [ V_45 ] ) )
return V_129 [ V_45 ] ;
return - 1 ;
}
