char * F_1 ( char * V_1 , int V_2 , T_1 V_3 )
{
if ( ! V_2 )
return V_1 ;
if ( ( V_3 & V_4 ) && ( V_3 & V_5 ) )
snprintf ( V_1 , V_2 , L_1 ) ;
else if ( V_3 & V_4 )
snprintf ( V_1 , V_2 , L_2 ) ;
else if ( V_3 & V_5 )
snprintf ( V_1 , V_2 , L_3 ) ;
else
snprintf ( V_1 , V_2 , L_4 ) ;
return V_1 ;
}
static int F_2 ( unsigned int V_6 )
{
int V_7 = 0 ;
while ( V_6 ) {
V_6 = V_6 >> 1 ;
V_7 ++ ;
}
return V_7 ;
}
static void F_3 ( struct V_8 * V_9 )
{
V_9 -> V_10 = ( 1 << F_2 ( V_9 -> V_11 - 1 ) ) - 1 ;
V_9 -> V_12 = ( 1 << F_2 ( V_9 -> V_13 - 1 ) ) - 1 ;
}
static int F_4 ( void * * V_14 , void * V_15 ,
struct V_16 * V_7 )
{
F_5 ( L_5 , * V_14 , V_15 ) ;
F_6 ( V_14 , V_15 , ( 1 + V_7 -> V_17 . V_18 ) * sizeof( T_1 ) , V_19 ) ;
V_7 -> V_20 = F_7 ( V_14 ) ;
return 0 ;
V_19:
return - V_21 ;
}
static int F_8 ( void * * V_14 , void * V_15 ,
struct V_22 * V_7 )
{
int V_23 ;
F_5 ( L_6 , * V_14 , V_15 ) ;
V_7 -> V_24 = F_9 ( V_7 -> V_17 . V_18 , sizeof( T_1 ) , V_25 ) ;
if ( V_7 -> V_24 == NULL )
return - V_26 ;
V_7 -> V_27 = F_9 ( V_7 -> V_17 . V_18 , sizeof( T_1 ) , V_25 ) ;
if ( V_7 -> V_27 == NULL )
return - V_26 ;
F_6 ( V_14 , V_15 , 2 * V_7 -> V_17 . V_18 * sizeof( T_1 ) , V_19 ) ;
for ( V_23 = 0 ; V_23 < V_7 -> V_17 . V_18 ; V_23 ++ ) {
V_7 -> V_24 [ V_23 ] = F_7 ( V_14 ) ;
V_7 -> V_27 [ V_23 ] = F_7 ( V_14 ) ;
}
return 0 ;
V_19:
return - V_21 ;
}
static int F_10 ( void * * V_14 , void * V_15 ,
struct V_28 * V_7 )
{
int V_23 ;
F_5 ( L_7 , * V_14 , V_15 ) ;
F_11 ( V_14 , V_15 , V_7 -> V_29 , V_19 ) ;
V_7 -> V_30 = F_9 ( V_7 -> V_29 , sizeof( T_1 ) , V_25 ) ;
if ( V_7 -> V_30 == NULL )
return - V_26 ;
F_6 ( V_14 , V_15 , V_7 -> V_29 * sizeof( T_1 ) , V_19 ) ;
for ( V_23 = 0 ; V_23 < V_7 -> V_29 ; V_23 ++ )
V_7 -> V_30 [ V_23 ] = F_7 ( V_14 ) ;
return 0 ;
V_19:
return - V_21 ;
}
static int F_12 ( void * * V_14 , void * V_15 ,
struct V_31 * V_7 )
{
int V_23 ;
F_5 ( L_8 , * V_14 , V_15 ) ;
V_7 -> V_24 = F_9 ( V_7 -> V_17 . V_18 , sizeof( T_1 ) , V_25 ) ;
if ( V_7 -> V_24 == NULL )
return - V_26 ;
V_7 -> V_32 = F_9 ( V_7 -> V_17 . V_18 , sizeof( T_1 ) , V_25 ) ;
if ( V_7 -> V_32 == NULL )
return - V_26 ;
F_6 ( V_14 , V_15 , 2 * V_7 -> V_17 . V_18 * sizeof( T_1 ) , V_19 ) ;
for ( V_23 = 0 ; V_23 < V_7 -> V_17 . V_18 ; V_23 ++ ) {
V_7 -> V_24 [ V_23 ] = F_7 ( V_14 ) ;
V_7 -> V_32 [ V_23 ] = F_7 ( V_14 ) ;
}
return 0 ;
V_19:
return - V_21 ;
}
static int F_13 ( void * * V_14 , void * V_15 ,
struct V_33 * V_7 )
{
int V_23 ;
F_5 ( L_9 , * V_14 , V_15 ) ;
V_7 -> V_24 = F_9 ( V_7 -> V_17 . V_18 , sizeof( T_1 ) , V_25 ) ;
if ( V_7 -> V_24 == NULL )
return - V_26 ;
F_6 ( V_14 , V_15 , V_7 -> V_17 . V_18 * sizeof( T_1 ) , V_19 ) ;
for ( V_23 = 0 ; V_23 < V_7 -> V_17 . V_18 ; V_23 ++ )
V_7 -> V_24 [ V_23 ] = F_7 ( V_14 ) ;
return 0 ;
V_19:
return - V_21 ;
}
static struct V_34 * F_14 ( void )
{
struct V_34 * V_35 ;
V_35 = F_15 ( sizeof( * V_35 ) , V_36 ) ;
if ( ! V_35 )
return NULL ;
F_16 ( & V_35 -> V_37 ) ;
return V_35 ;
}
static void F_17 ( struct V_34 * V_35 )
{
if ( V_35 ) {
int V_38 , V_23 ;
F_18 ( ! F_19 ( & V_35 -> V_37 ) ) ;
for ( V_38 = 0 ; V_38 < V_35 -> V_18 ; V_38 ++ ) {
struct V_39 * V_40 = & V_35 -> args [ V_38 ] ;
for ( V_23 = 0 ; V_23 < V_40 -> V_41 ; V_23 ++ )
F_20 ( V_40 -> V_42 [ V_23 ] . V_43 ) ;
F_20 ( V_40 -> V_42 ) ;
F_20 ( V_40 -> V_44 ) ;
}
F_20 ( V_35 -> args ) ;
F_20 ( V_35 ) ;
}
}
void F_21 ( struct V_45 * V_46 )
{
while ( ! F_22 ( & V_46 -> V_47 ) ) {
struct V_34 * V_35 =
F_23 ( F_24 ( & V_46 -> V_47 ) ,
struct V_34 , V_37 ) ;
F_25 ( & V_46 -> V_47 , V_35 ) ;
F_17 ( V_35 ) ;
}
}
static T_1 * F_26 ( void * * V_14 , void * V_15 , T_1 * V_48 )
{
T_1 * V_49 = NULL ;
T_1 V_2 ;
int V_50 ;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
if ( V_2 ) {
T_1 V_38 ;
V_49 = F_28 ( V_2 , sizeof( T_1 ) , V_36 ) ;
if ( ! V_49 ) {
V_50 = - V_26 ;
goto V_52;
}
F_6 ( V_14 , V_15 , V_2 * sizeof( T_1 ) , V_51 ) ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
V_49 [ V_38 ] = F_7 ( V_14 ) ;
}
* V_48 = V_2 ;
return V_49 ;
V_51:
V_50 = - V_21 ;
V_52:
F_20 ( V_49 ) ;
return F_29 ( V_50 ) ;
}
static int F_30 ( void * * V_14 , void * V_15 , struct V_39 * V_40 )
{
int V_50 ;
F_27 ( V_14 , V_15 , V_40 -> V_41 , V_51 ) ;
if ( V_40 -> V_41 ) {
T_1 V_38 ;
V_40 -> V_42 = F_28 ( V_40 -> V_41 ,
sizeof( * V_40 -> V_42 ) ,
V_36 ) ;
if ( ! V_40 -> V_42 )
return - V_26 ;
for ( V_38 = 0 ; V_38 < V_40 -> V_41 ; V_38 ++ ) {
struct V_53 * V_54 = & V_40 -> V_42 [ V_38 ] ;
V_54 -> V_43 = F_26 ( V_14 , V_15 , & V_54 -> V_18 ) ;
if ( F_31 ( V_54 -> V_43 ) ) {
V_50 = F_32 ( V_54 -> V_43 ) ;
V_54 -> V_43 = NULL ;
return V_50 ;
}
}
}
V_40 -> V_44 = F_26 ( V_14 , V_15 , & V_40 -> V_55 ) ;
if ( F_31 ( V_40 -> V_44 ) ) {
V_50 = F_32 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
return V_50 ;
}
return 0 ;
V_51:
return - V_21 ;
}
static int F_33 ( void * * V_14 , void * V_15 , struct V_45 * V_46 )
{
struct V_34 * V_35 = NULL ;
T_1 V_56 , V_57 ;
int V_50 ;
F_27 ( V_14 , V_15 , V_56 , V_51 ) ;
while ( V_56 -- ) {
V_35 = F_14 () ;
if ( ! V_35 ) {
V_50 = - V_26 ;
goto V_52;
}
F_34 ( V_14 , V_15 , V_35 -> V_58 ,
V_51 ) ;
V_35 -> V_18 = V_46 -> V_59 ;
V_35 -> args = F_9 ( V_35 -> V_18 , sizeof( * V_35 -> args ) ,
V_36 ) ;
if ( ! V_35 -> args ) {
V_50 = - V_26 ;
goto V_52;
}
F_27 ( V_14 , V_15 , V_57 , V_51 ) ;
while ( V_57 -- ) {
struct V_39 * V_40 ;
T_1 V_60 ;
F_27 ( V_14 , V_15 , V_60 , V_51 ) ;
if ( V_60 >= V_35 -> V_18 )
goto V_51;
V_40 = & V_35 -> args [ V_60 ] ;
V_50 = F_30 ( V_14 , V_15 , V_40 ) ;
if ( V_50 )
goto V_52;
if ( V_40 -> V_55 &&
V_40 -> V_55 != V_46 -> V_61 [ V_60 ] -> V_18 )
goto V_51;
}
F_35 ( & V_46 -> V_47 , V_35 ) ;
}
return 0 ;
V_51:
V_50 = - V_21 ;
V_52:
F_17 ( V_35 ) ;
return V_50 ;
}
static void F_36 ( struct V_45 * V_46 )
{
T_2 V_7 ;
V_46 -> V_62 = sizeof( struct V_63 ) +
V_46 -> V_59 * sizeof( struct V_64 * ) ;
for ( V_7 = 0 ; V_7 < V_46 -> V_59 ; V_7 ++ ) {
if ( ! V_46 -> V_61 [ V_7 ] )
continue;
switch ( V_46 -> V_61 [ V_7 ] -> V_65 ) {
default:
V_46 -> V_62 += sizeof( struct V_64 ) ;
break;
}
V_46 -> V_62 += V_46 -> V_61 [ V_7 ] -> V_18 * sizeof( V_66 ) ;
}
}
static struct V_45 * F_37 ( void * V_67 , void * V_15 )
{
struct V_45 * V_46 ;
int V_68 ;
int V_38 , V_23 ;
void * * V_14 = & V_67 ;
void * V_69 = V_67 ;
T_1 V_70 ;
F_5 ( L_10 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_46 = F_15 ( sizeof( * V_46 ) , V_25 ) ;
if ( V_46 == NULL )
return F_29 ( - V_26 ) ;
V_46 -> V_47 = V_71 ;
V_46 -> V_72 = 2 ;
V_46 -> V_73 = 5 ;
V_46 -> V_74 = 19 ;
V_46 -> V_75 = 0 ;
F_6 ( V_14 , V_15 , 4 * sizeof( T_1 ) , V_19 ) ;
V_70 = F_7 ( V_14 ) ;
if ( V_70 != V_76 ) {
F_38 ( L_11 ,
( unsigned int ) V_70 , ( unsigned int ) V_76 ) ;
goto V_19;
}
V_46 -> V_59 = F_7 ( V_14 ) ;
V_46 -> V_77 = F_7 ( V_14 ) ;
V_46 -> V_78 = F_7 ( V_14 ) ;
V_46 -> V_61 = F_9 ( V_46 -> V_59 , sizeof( * V_46 -> V_61 ) , V_25 ) ;
if ( V_46 -> V_61 == NULL )
goto V_79;
V_46 -> V_80 = F_9 ( V_46 -> V_77 , sizeof( * V_46 -> V_80 ) , V_25 ) ;
if ( V_46 -> V_80 == NULL )
goto V_79;
for ( V_38 = 0 ; V_38 < V_46 -> V_59 ; V_38 ++ ) {
int V_18 = 0 ;
T_1 V_65 ;
struct V_81 * V_7 ;
F_27 ( V_14 , V_15 , V_65 , V_19 ) ;
if ( V_65 == 0 ) {
V_46 -> V_61 [ V_38 ] = NULL ;
continue;
}
F_5 ( L_12 ,
V_38 , ( int ) ( * V_14 - V_69 ) , * V_14 , V_15 ) ;
switch ( V_65 ) {
case V_82 :
V_18 = sizeof( struct V_16 ) ;
break;
case V_83 :
V_18 = sizeof( struct V_22 ) ;
break;
case V_84 :
V_18 = sizeof( struct V_28 ) ;
break;
case V_85 :
V_18 = sizeof( struct V_31 ) ;
break;
case V_86 :
V_18 = sizeof( struct V_33 ) ;
break;
default:
goto V_19;
}
F_39 ( V_18 == 0 ) ;
V_7 = V_46 -> V_61 [ V_38 ] = F_15 ( V_18 , V_25 ) ;
if ( V_7 == NULL )
goto V_79;
F_6 ( V_14 , V_15 , 4 * sizeof( T_1 ) , V_19 ) ;
V_7 -> V_87 = F_7 ( V_14 ) ;
V_7 -> type = F_40 ( V_14 ) ;
V_7 -> V_65 = F_41 ( V_14 ) ;
V_7 -> V_88 = F_41 ( V_14 ) ;
V_7 -> V_89 = F_7 ( V_14 ) ;
V_7 -> V_18 = F_7 ( V_14 ) ;
F_5 ( L_13 ,
V_7 -> V_18 , ( int ) ( * V_14 - V_69 ) , * V_14 , V_15 ) ;
V_7 -> V_90 = F_9 ( V_7 -> V_18 , sizeof( T_2 ) , V_25 ) ;
if ( V_7 -> V_90 == NULL )
goto V_79;
F_6 ( V_14 , V_15 , V_7 -> V_18 * sizeof( T_1 ) , V_19 ) ;
for ( V_23 = 0 ; V_23 < V_7 -> V_18 ; V_23 ++ )
V_7 -> V_90 [ V_23 ] = F_7 ( V_14 ) ;
switch ( V_7 -> V_65 ) {
case V_82 :
V_68 = F_4 ( V_14 , V_15 ,
(struct V_16 * ) V_7 ) ;
if ( V_68 < 0 )
goto V_52;
break;
case V_83 :
V_68 = F_8 ( V_14 , V_15 ,
(struct V_22 * ) V_7 ) ;
if ( V_68 < 0 )
goto V_52;
break;
case V_84 :
V_68 = F_10 ( V_14 , V_15 ,
(struct V_28 * ) V_7 ) ;
if ( V_68 < 0 )
goto V_52;
break;
case V_85 :
V_68 = F_12 ( V_14 , V_15 ,
(struct V_31 * ) V_7 ) ;
if ( V_68 < 0 )
goto V_52;
break;
case V_86 :
V_68 = F_13 ( V_14 , V_15 ,
(struct V_33 * ) V_7 ) ;
if ( V_68 < 0 )
goto V_52;
break;
}
}
F_5 ( L_14 , V_46 -> V_80 ) ;
for ( V_38 = 0 ; V_38 < V_46 -> V_77 ; V_38 ++ ) {
T_1 V_91 ;
struct V_92 * V_93 ;
F_27 ( V_14 , V_15 , V_91 , V_19 ) ;
if ( ! V_91 ) {
F_5 ( L_15 ,
V_38 , ( int ) ( * V_14 - V_69 ) , * V_14 , V_15 ) ;
V_46 -> V_80 [ V_38 ] = NULL ;
continue;
}
F_5 ( L_16 ,
V_38 , ( int ) ( * V_14 - V_69 ) , * V_14 , V_15 ) ;
F_27 ( V_14 , V_15 , V_91 , V_19 ) ;
#if V_94 == 32
if ( V_91 > ( V_95 - sizeof( * V_93 ) )
/ sizeof( struct V_96 ) )
goto V_19;
#endif
V_93 = V_46 -> V_80 [ V_38 ] = F_42 ( sizeof( * V_93 ) +
V_91 * sizeof( struct V_96 ) ,
V_25 ) ;
if ( V_93 == NULL )
goto V_79;
F_5 ( L_17 , V_38 , V_93 ) ;
V_93 -> V_2 = V_91 ;
F_43 ( V_14 , V_15 , & V_93 -> V_97 , 4 , V_19 ) ;
F_6 ( V_14 , V_15 , V_93 -> V_2 * 3 * sizeof( T_1 ) , V_19 ) ;
for ( V_23 = 0 ; V_23 < V_93 -> V_2 ; V_23 ++ ) {
V_93 -> V_98 [ V_23 ] . V_99 = F_7 ( V_14 ) ;
V_93 -> V_98 [ V_23 ] . V_100 = F_7 ( V_14 ) ;
V_93 -> V_98 [ V_23 ] . V_101 = F_7 ( V_14 ) ;
}
}
F_44 ( V_14 , V_15 , 32 , string , V_19 ) ;
F_44 ( V_14 , V_15 , 32 , string , V_19 ) ;
F_44 ( V_14 , V_15 , 32 , string , V_19 ) ;
F_6 ( V_14 , V_15 , 3 * sizeof( T_1 ) , V_102 ) ;
V_46 -> V_72 = F_7 ( V_14 ) ;
V_46 -> V_73 = F_7 ( V_14 ) ;
V_46 -> V_74 = F_7 ( V_14 ) ;
F_5 ( L_18 ,
V_46 -> V_72 ) ;
F_5 ( L_19 ,
V_46 -> V_73 ) ;
F_5 ( L_20 ,
V_46 -> V_74 ) ;
F_6 ( V_14 , V_15 , sizeof( T_1 ) , V_102 ) ;
V_46 -> V_75 = F_7 ( V_14 ) ;
F_5 ( L_21 ,
V_46 -> V_75 ) ;
F_6 ( V_14 , V_15 , sizeof( V_103 ) , V_102 ) ;
V_46 -> V_104 = F_41 ( V_14 ) ;
F_5 ( L_22 ,
V_46 -> V_104 ) ;
F_6 ( V_14 , V_15 , sizeof( V_103 ) + sizeof( T_1 ) , V_102 ) ;
* V_14 += sizeof( V_103 ) + sizeof( T_1 ) ;
F_6 ( V_14 , V_15 , sizeof( V_103 ) , V_102 ) ;
V_46 -> V_105 = F_41 ( V_14 ) ;
F_5 ( L_23 ,
V_46 -> V_105 ) ;
if ( * V_14 != V_15 ) {
F_44 ( V_14 , V_15 , 32 , 32 , V_19 ) ;
F_44 ( V_14 , V_15 , 32 , string , V_19 ) ;
F_45 ( V_14 , V_15 , 32 , 32 , 32 , V_19 ) ;
}
if ( * V_14 != V_15 ) {
V_68 = F_33 ( V_14 , V_15 , V_46 ) ;
if ( V_68 )
goto V_52;
}
V_102:
F_36 ( V_46 ) ;
F_5 ( L_24 ) ;
return V_46 ;
V_79:
V_68 = - V_26 ;
V_52:
F_5 ( L_25 , V_68 ) ;
F_46 ( V_46 ) ;
return F_29 ( V_68 ) ;
V_19:
V_68 = - V_21 ;
goto V_52;
}
int F_47 ( const struct V_106 * V_107 , const struct V_106 * V_108 )
{
if ( V_107 -> V_109 < V_108 -> V_109 )
return - 1 ;
if ( V_107 -> V_109 > V_108 -> V_109 )
return 1 ;
if ( V_107 -> V_110 < V_108 -> V_110 )
return - 1 ;
if ( V_107 -> V_110 > V_108 -> V_110 )
return 1 ;
return 0 ;
}
int F_48 ( const struct V_111 * V_107 , const struct V_111 * V_108 )
{
int V_50 ;
V_50 = F_47 ( & V_107 -> V_112 , & V_108 -> V_112 ) ;
if ( V_50 )
return V_50 ;
if ( V_107 -> V_113 < V_108 -> V_113 )
return - 1 ;
if ( V_107 -> V_113 > V_108 -> V_113 )
return 1 ;
return 0 ;
}
static struct V_114 * F_49 ( T_3 V_115 )
{
struct V_114 * V_116 ;
V_116 = F_42 ( sizeof( * V_116 ) + V_115 , V_36 ) ;
if ( ! V_116 )
return NULL ;
F_16 ( & V_116 -> V_37 ) ;
return V_116 ;
}
static void F_50 ( struct V_114 * V_116 )
{
F_18 ( ! F_19 ( & V_116 -> V_37 ) ) ;
F_20 ( V_116 ) ;
}
static int F_51 ( struct V_117 * V_118 , struct V_8 * V_119 )
{
struct V_120 * * V_14 = & V_118 -> V_120 ;
struct V_120 * V_121 = NULL ;
struct V_8 * V_9 = NULL ;
while ( * V_14 ) {
V_121 = * V_14 ;
V_9 = F_23 ( V_121 , struct V_8 , V_37 ) ;
if ( V_119 -> V_87 < V_9 -> V_87 )
V_14 = & ( * V_14 ) -> V_122 ;
else if ( V_119 -> V_87 > V_9 -> V_87 )
V_14 = & ( * V_14 ) -> V_123 ;
else
return - V_124 ;
}
F_52 ( & V_119 -> V_37 , V_121 , V_14 ) ;
F_53 ( & V_119 -> V_37 , V_118 ) ;
return 0 ;
}
static struct V_8 * F_54 ( struct V_117 * V_118 , T_4 V_87 )
{
struct V_8 * V_9 ;
struct V_120 * V_125 = V_118 -> V_120 ;
while ( V_125 ) {
V_9 = F_23 ( V_125 , struct V_8 , V_37 ) ;
if ( V_87 < V_9 -> V_87 )
V_125 = V_125 -> V_122 ;
else if ( V_87 > V_9 -> V_87 )
V_125 = V_125 -> V_123 ;
else
return V_9 ;
}
return NULL ;
}
struct V_8 * F_55 ( struct V_126 * V_127 , T_4 V_87 )
{
return F_54 ( & V_127 -> V_128 , V_87 ) ;
}
const char * F_56 ( struct V_126 * V_127 , T_4 V_87 )
{
struct V_8 * V_9 ;
if ( V_87 == V_129 )
return NULL ;
if ( F_57 ( V_87 > ( T_4 ) V_130 ) )
return NULL ;
V_9 = F_54 ( & V_127 -> V_128 , ( int ) V_87 ) ;
return V_9 ? V_9 -> V_131 : NULL ;
}
int F_58 ( struct V_126 * V_127 , const char * V_131 )
{
struct V_120 * V_132 ;
for ( V_132 = F_24 ( & V_127 -> V_128 ) ; V_132 ; V_132 = F_59 ( V_132 ) ) {
struct V_8 * V_9 =
F_23 ( V_132 , struct V_8 , V_37 ) ;
if ( V_9 -> V_131 && strcmp ( V_9 -> V_131 , V_131 ) == 0 )
return V_9 -> V_87 ;
}
return - V_133 ;
}
static void F_60 ( struct V_117 * V_118 , struct V_8 * V_9 )
{
F_61 ( & V_9 -> V_37 , V_118 ) ;
F_20 ( V_9 -> V_131 ) ;
F_20 ( V_9 ) ;
}
static int F_62 ( void * * V_14 , void * V_15 , struct V_8 * V_9 )
{
V_103 V_134 , V_135 ;
unsigned V_2 , V_136 ;
void * V_137 ;
F_6 ( V_14 , V_15 , 2 + 4 , V_19 ) ;
V_134 = F_41 ( V_14 ) ;
V_135 = F_41 ( V_14 ) ;
if ( V_134 < 5 ) {
F_63 ( L_26 , V_134 , V_135 ) ;
return - V_21 ;
}
if ( V_135 > 9 ) {
F_63 ( L_27 , V_134 , V_135 ) ;
return - V_21 ;
}
V_2 = F_7 ( V_14 ) ;
F_6 ( V_14 , V_15 , V_2 , V_19 ) ;
V_137 = * V_14 + V_2 ;
V_9 -> type = F_41 ( V_14 ) ;
V_9 -> V_18 = F_41 ( V_14 ) ;
V_9 -> V_138 = F_41 ( V_14 ) ;
V_9 -> V_139 = F_41 ( V_14 ) ;
V_9 -> V_11 = F_7 ( V_14 ) ;
V_9 -> V_13 = F_7 ( V_14 ) ;
* V_14 += 4 + 4 ;
* V_14 += 4 ;
* V_14 += 8 + 4 ;
V_136 = F_7 ( V_14 ) ;
while ( V_136 -- ) {
* V_14 += 8 ;
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
V_136 = F_7 ( V_14 ) ;
* V_14 += V_136 * ( 8 + 8 ) ;
* V_14 += 8 ;
V_9 -> V_140 = F_64 ( V_14 ) ;
* V_14 += 4 ;
if ( V_134 >= 7 )
V_9 -> V_141 = F_41 ( V_14 ) ;
else
V_9 -> V_141 = V_9 -> V_18 - V_9 -> V_18 / 2 ;
if ( V_134 >= 8 )
* V_14 += 8 + 8 ;
if ( V_134 >= 9 ) {
V_136 = F_7 ( V_14 ) ;
* V_14 += V_136 * 8 ;
* V_14 += 8 ;
* V_14 += 1 ;
V_9 -> V_142 = F_64 ( V_14 ) ;
V_9 -> V_143 = F_64 ( V_14 ) ;
} else {
V_9 -> V_142 = - 1 ;
V_9 -> V_143 = - 1 ;
}
if ( V_134 >= 10 ) {
V_136 = F_7 ( V_14 ) ;
while ( V_136 -- ) {
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
}
if ( V_134 >= 11 ) {
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
* V_14 += 4 ;
* V_14 += 4 ;
}
if ( V_134 >= 12 )
* V_14 += 4 ;
if ( V_134 >= 13 ) {
* V_14 += 8 ;
* V_14 += 8 ;
* V_14 += 4 ;
* V_14 += 4 ;
* V_14 += 4 ;
* V_14 += 4 ;
}
if ( V_134 >= 14 ) {
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
if ( V_134 >= 15 )
V_9 -> V_144 = F_7 ( V_14 ) ;
else
V_9 -> V_144 = 0 ;
if ( V_134 >= 16 )
* V_14 += 4 ;
if ( V_134 >= 17 )
* V_14 += 8 ;
if ( V_134 >= 19 )
* V_14 += 4 ;
if ( V_134 >= 20 )
* V_14 += 4 ;
if ( V_134 >= 21 )
* V_14 += 1 ;
if ( V_134 >= 22 )
* V_14 += 1 ;
if ( V_134 >= 23 ) {
* V_14 += 4 ;
* V_14 += 4 ;
}
if ( V_134 >= 24 ) {
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
if ( V_134 >= 25 )
V_9 -> V_144 = F_7 ( V_14 ) ;
* V_14 = V_137 ;
F_3 ( V_9 ) ;
return 0 ;
V_19:
return - V_21 ;
}
static int F_65 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
struct V_8 * V_9 ;
T_1 V_136 , V_2 ;
T_4 V_109 ;
F_27 ( V_14 , V_15 , V_136 , V_19 ) ;
F_5 ( L_28 , V_136 ) ;
while ( V_136 -- ) {
F_34 ( V_14 , V_15 , V_109 , V_19 ) ;
F_27 ( V_14 , V_15 , V_2 , V_19 ) ;
F_5 ( L_29 , V_109 , V_2 ) ;
F_6 ( V_14 , V_15 , V_2 , V_19 ) ;
V_9 = F_54 ( & V_127 -> V_128 , V_109 ) ;
if ( V_9 ) {
char * V_131 = F_66 ( * V_14 , V_2 , V_25 ) ;
if ( ! V_131 )
return - V_26 ;
F_20 ( V_9 -> V_131 ) ;
V_9 -> V_131 = V_131 ;
F_5 ( L_30 , V_9 -> V_131 ) ;
}
* V_14 += V_2 ;
}
return 0 ;
V_19:
return - V_21 ;
}
struct V_126 * F_67 ( void )
{
struct V_126 * V_127 ;
V_127 = F_15 ( sizeof( * V_127 ) , V_36 ) ;
if ( ! V_127 )
return NULL ;
V_127 -> V_128 = V_71 ;
V_127 -> V_145 = - 1 ;
V_127 -> V_146 = V_71 ;
V_127 -> V_147 = V_71 ;
V_127 -> V_148 = V_71 ;
V_127 -> V_149 = V_71 ;
F_68 ( & V_127 -> V_150 ) ;
return V_127 ;
}
void F_69 ( struct V_126 * V_127 )
{
F_5 ( L_31 , V_127 ) ;
if ( V_127 -> V_151 )
F_46 ( V_127 -> V_151 ) ;
while ( ! F_22 ( & V_127 -> V_146 ) ) {
struct V_114 * V_116 =
F_23 ( F_24 ( & V_127 -> V_146 ) ,
struct V_114 , V_37 ) ;
F_70 ( & V_127 -> V_146 , V_116 ) ;
F_50 ( V_116 ) ;
}
while ( ! F_22 ( & V_127 -> V_147 ) ) {
struct V_114 * V_116 =
F_23 ( F_24 ( & V_127 -> V_147 ) ,
struct V_114 , V_37 ) ;
F_70 ( & V_127 -> V_147 , V_116 ) ;
F_50 ( V_116 ) ;
}
while ( ! F_22 ( & V_127 -> V_148 ) ) {
struct V_114 * V_116 =
F_23 ( F_24 ( & V_127 -> V_148 ) ,
struct V_114 , V_37 ) ;
F_61 ( & V_116 -> V_37 , & V_127 -> V_148 ) ;
F_20 ( V_116 ) ;
}
while ( ! F_22 ( & V_127 -> V_149 ) ) {
struct V_114 * V_116 =
F_23 ( F_24 ( & V_127 -> V_149 ) ,
struct V_114 , V_37 ) ;
F_61 ( & V_116 -> V_37 , & V_127 -> V_149 ) ;
F_20 ( V_116 ) ;
}
while ( ! F_22 ( & V_127 -> V_128 ) ) {
struct V_8 * V_9 =
F_23 ( F_24 ( & V_127 -> V_128 ) ,
struct V_8 , V_37 ) ;
F_60 ( & V_127 -> V_128 , V_9 ) ;
}
F_20 ( V_127 -> V_152 ) ;
F_20 ( V_127 -> V_153 ) ;
F_20 ( V_127 -> V_154 ) ;
F_20 ( V_127 -> V_155 ) ;
F_20 ( V_127 -> V_156 ) ;
F_20 ( V_127 ) ;
}
static int F_71 ( struct V_126 * V_127 , int V_157 )
{
T_1 * V_3 ;
T_1 * V_89 ;
struct V_158 * V_159 ;
int V_38 ;
V_3 = F_72 ( V_127 -> V_152 , V_157 * sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 )
return - V_26 ;
V_127 -> V_152 = V_3 ;
V_89 = F_72 ( V_127 -> V_153 , V_157 * sizeof( * V_89 ) , V_25 ) ;
if ( ! V_89 )
return - V_26 ;
V_127 -> V_153 = V_89 ;
V_159 = F_72 ( V_127 -> V_154 , V_157 * sizeof( * V_159 ) , V_25 ) ;
if ( ! V_159 )
return - V_26 ;
V_127 -> V_154 = V_159 ;
for ( V_38 = V_127 -> V_160 ; V_38 < V_157 ; V_38 ++ ) {
V_127 -> V_152 [ V_38 ] = 0 ;
V_127 -> V_153 [ V_38 ] = V_161 ;
memset ( V_127 -> V_154 + V_38 , 0 , sizeof( * V_127 -> V_154 ) ) ;
}
if ( V_127 -> V_155 ) {
T_1 * V_162 ;
V_162 = F_72 ( V_127 -> V_155 ,
V_157 * sizeof( * V_162 ) , V_25 ) ;
if ( ! V_162 )
return - V_26 ;
V_127 -> V_155 = V_162 ;
for ( V_38 = V_127 -> V_160 ; V_38 < V_157 ; V_38 ++ )
V_127 -> V_155 [ V_38 ] =
V_163 ;
}
V_127 -> V_160 = V_157 ;
return 0 ;
}
static int F_73 ( struct V_126 * V_127 , struct V_45 * V_151 )
{
void * V_164 ;
T_3 V_165 ;
if ( F_31 ( V_151 ) )
return F_32 ( V_151 ) ;
V_165 = F_74 ( V_151 , V_166 ) ;
F_5 ( L_32 , V_167 , V_165 ) ;
V_164 = F_42 ( V_165 , V_36 ) ;
if ( ! V_164 ) {
F_46 ( V_151 ) ;
return - V_26 ;
}
F_75 ( V_151 , V_164 ) ;
if ( V_127 -> V_151 )
F_46 ( V_127 -> V_151 ) ;
F_20 ( V_127 -> V_156 ) ;
V_127 -> V_151 = V_151 ;
V_127 -> V_156 = V_164 ;
return 0 ;
}
static int F_76 ( void * * V_14 , void * V_15 ,
const char * V_168 , V_103 * V_169 )
{
V_103 V_170 ;
F_11 ( V_14 , V_15 , V_170 , V_51 ) ;
if ( V_170 >= 7 ) {
V_103 V_171 ;
F_11 ( V_14 , V_15 , V_171 , V_51 ) ;
if ( V_171 > V_172 ) {
F_63 ( L_33 ,
V_170 , V_171 ,
V_172 , V_168 ) ;
return - V_21 ;
}
* V_14 += 4 ;
F_11 ( V_14 , V_15 , V_170 , V_51 ) ;
F_11 ( V_14 , V_15 , V_171 , V_51 ) ;
if ( V_171 > V_173 ) {
F_63 ( L_34 ,
V_170 , V_171 ,
V_173 , V_168 ) ;
return - V_21 ;
}
* V_14 += 4 ;
} else {
T_5 V_174 ;
* V_14 -= 1 ;
F_77 ( V_14 , V_15 , V_174 , V_51 ) ;
if ( V_174 < 6 ) {
F_63 ( L_35 ,
V_174 , V_168 ) ;
return - V_21 ;
}
V_170 = 0 ;
}
* V_169 = V_170 ;
return 0 ;
V_51:
return - V_21 ;
}
static int F_78 ( void * * V_14 , void * V_15 , struct V_126 * V_127 ,
bool V_175 )
{
T_1 V_125 ;
F_27 ( V_14 , V_15 , V_125 , V_51 ) ;
while ( V_125 -- ) {
struct V_8 * V_9 ;
T_4 V_109 ;
int V_50 ;
F_34 ( V_14 , V_15 , V_109 , V_51 ) ;
V_9 = F_54 ( & V_127 -> V_128 , V_109 ) ;
if ( ! V_175 || ! V_9 ) {
V_9 = F_15 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 )
return - V_26 ;
V_9 -> V_87 = V_109 ;
V_50 = F_51 ( & V_127 -> V_128 , V_9 ) ;
if ( V_50 ) {
F_20 ( V_9 ) ;
return V_50 ;
}
}
V_50 = F_62 ( V_14 , V_15 , V_9 ) ;
if ( V_50 )
return V_50 ;
}
return 0 ;
V_51:
return - V_21 ;
}
static int F_79 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_78 ( V_14 , V_15 , V_127 , false ) ;
}
static int F_80 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_78 ( V_14 , V_15 , V_127 , true ) ;
}
static int F_81 ( void * * V_14 , void * V_15 , struct V_117 * V_176 ,
T_6 V_177 , bool V_175 )
{
T_1 V_125 ;
F_18 ( ! V_175 && ! V_177 ) ;
F_27 ( V_14 , V_15 , V_125 , V_51 ) ;
while ( V_125 -- ) {
struct V_114 * V_116 ;
struct V_106 V_112 ;
int V_50 ;
V_50 = F_82 ( V_14 , V_15 , & V_112 ) ;
if ( V_50 )
return V_50 ;
V_116 = F_83 ( V_176 , & V_112 ) ;
if ( V_116 ) {
F_18 ( ! V_175 ) ;
F_70 ( V_176 , V_116 ) ;
F_50 ( V_116 ) ;
}
if ( V_177 ) {
V_116 = V_177 ( V_14 , V_15 , V_175 ) ;
if ( F_31 ( V_116 ) )
return F_32 ( V_116 ) ;
if ( V_116 ) {
V_116 -> V_112 = V_112 ;
F_84 ( V_176 , V_116 ) ;
}
}
}
return 0 ;
V_51:
return - V_21 ;
}
static struct V_114 * F_85 ( void * * V_14 , void * V_15 ,
bool V_175 )
{
struct V_114 * V_116 ;
T_1 V_2 , V_38 ;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
if ( V_2 == 0 && V_175 )
return NULL ;
if ( V_2 > ( V_178 - sizeof( * V_116 ) ) / sizeof( T_1 ) )
return F_29 ( - V_21 ) ;
F_6 ( V_14 , V_15 , V_2 * sizeof( T_1 ) , V_51 ) ;
V_116 = F_49 ( V_2 * sizeof( T_1 ) ) ;
if ( ! V_116 )
return F_29 ( - V_26 ) ;
V_116 -> V_146 . V_2 = V_2 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
V_116 -> V_146 . V_179 [ V_38 ] = F_7 ( V_14 ) ;
return V_116 ;
V_51:
return F_29 ( - V_21 ) ;
}
static int F_86 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_146 , F_85 ,
false ) ;
}
static int F_87 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_146 , F_85 ,
true ) ;
}
static struct V_114 * F_88 ( void * * V_14 , void * V_15 ,
bool V_175 )
{
struct V_114 * V_116 ;
T_1 V_180 ;
F_27 ( V_14 , V_15 , V_180 , V_51 ) ;
if ( V_180 == ( T_1 ) - 1 && V_175 )
return NULL ;
V_116 = F_49 ( 0 ) ;
if ( ! V_116 )
return F_29 ( - V_26 ) ;
V_116 -> V_147 . V_180 = V_180 ;
return V_116 ;
V_51:
return F_29 ( - V_21 ) ;
}
static int F_89 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_147 ,
F_88 , false ) ;
}
static int F_90 ( void * * V_14 , void * V_15 ,
struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_147 ,
F_88 , true ) ;
}
T_1 F_91 ( struct V_126 * V_127 , int V_180 )
{
F_39 ( V_180 >= V_127 -> V_160 ) ;
if ( ! V_127 -> V_155 )
return V_163 ;
return V_127 -> V_155 [ V_180 ] ;
}
static int F_92 ( struct V_126 * V_127 , int V_180 , T_1 V_181 )
{
F_39 ( V_180 >= V_127 -> V_160 ) ;
if ( ! V_127 -> V_155 ) {
int V_38 ;
V_127 -> V_155 = F_42 ( V_127 -> V_160 * sizeof( T_1 ) ,
V_25 ) ;
if ( ! V_127 -> V_155 )
return - V_26 ;
for ( V_38 = 0 ; V_38 < V_127 -> V_160 ; V_38 ++ )
V_127 -> V_155 [ V_38 ] =
V_163 ;
}
V_127 -> V_155 [ V_180 ] = V_181 ;
return 0 ;
}
static int F_93 ( void * * V_14 , void * V_15 ,
struct V_126 * V_127 )
{
T_1 V_2 , V_38 ;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
if ( V_2 == 0 ) {
F_20 ( V_127 -> V_155 ) ;
V_127 -> V_155 = NULL ;
return 0 ;
}
if ( V_2 != V_127 -> V_160 )
goto V_51;
F_6 ( V_14 , V_15 , V_127 -> V_160 * sizeof( T_1 ) , V_51 ) ;
for ( V_38 = 0 ; V_38 < V_127 -> V_160 ; V_38 ++ ) {
int V_50 ;
V_50 = F_92 ( V_127 , V_38 , F_7 ( V_14 ) ) ;
if ( V_50 )
return V_50 ;
}
return 0 ;
V_51:
return - V_21 ;
}
static int F_94 ( void * * V_14 , void * V_15 ,
struct V_126 * V_127 )
{
T_1 V_125 ;
F_27 ( V_14 , V_15 , V_125 , V_51 ) ;
while ( V_125 -- ) {
T_1 V_180 , V_181 ;
int V_50 ;
F_27 ( V_14 , V_15 , V_180 , V_51 ) ;
F_27 ( V_14 , V_15 , V_181 , V_51 ) ;
V_50 = F_92 ( V_127 , V_180 , V_181 ) ;
if ( V_50 )
return V_50 ;
F_95 ( L_36 , V_180 , V_181 ) ;
}
return 0 ;
V_51:
return - V_21 ;
}
static struct V_114 * F_96 ( void * * V_14 , void * V_15 ,
bool V_182 )
{
return F_85 ( V_14 , V_15 , false ) ;
}
static int F_97 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_148 , F_96 ,
false ) ;
}
static int F_98 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_148 , F_96 ,
true ) ;
}
static int F_99 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_148 , NULL , true ) ;
}
static struct V_114 * F_100 ( void * * V_14 , void * V_15 ,
bool V_182 )
{
struct V_114 * V_116 ;
T_1 V_2 , V_38 ;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
if ( V_2 > ( V_178 - sizeof( * V_116 ) ) / ( 2 * sizeof( T_1 ) ) )
return F_29 ( - V_21 ) ;
F_6 ( V_14 , V_15 , 2 * V_2 * sizeof( T_1 ) , V_51 ) ;
V_116 = F_49 ( 2 * V_2 * sizeof( T_1 ) ) ;
if ( ! V_116 )
return F_29 ( - V_26 ) ;
V_116 -> V_149 . V_2 = V_2 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
V_116 -> V_149 . V_183 [ V_38 ] [ 0 ] = F_7 ( V_14 ) ;
V_116 -> V_149 . V_183 [ V_38 ] [ 1 ] = F_7 ( V_14 ) ;
}
return V_116 ;
V_51:
return F_29 ( - V_21 ) ;
}
static int F_101 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_149 ,
F_100 , false ) ;
}
static int F_102 ( void * * V_14 , void * V_15 ,
struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_149 ,
F_100 , true ) ;
}
static int F_103 ( void * * V_14 , void * V_15 ,
struct V_126 * V_127 )
{
return F_81 ( V_14 , V_15 , & V_127 -> V_149 , NULL , true ) ;
}
static int F_104 ( void * * V_14 , void * V_15 , struct V_126 * V_127 )
{
V_103 V_170 ;
T_1 V_184 = 0 ;
void * V_69 = * V_14 ;
T_1 V_157 ;
T_1 V_2 , V_38 ;
int V_68 ;
F_5 ( L_37 , V_167 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_68 = F_76 ( V_14 , V_15 , L_38 , & V_170 ) ;
if ( V_68 )
goto V_19;
F_6 ( V_14 , V_15 , sizeof( V_127 -> V_185 ) + sizeof( T_1 ) +
sizeof( V_127 -> V_186 ) + sizeof( V_127 -> V_187 ) , V_51 ) ;
F_105 ( V_14 , & V_127 -> V_185 , sizeof( V_127 -> V_185 ) ) ;
V_184 = V_127 -> V_184 = F_7 ( V_14 ) ;
F_105 ( V_14 , & V_127 -> V_186 , sizeof( V_127 -> V_186 ) ) ;
F_105 ( V_14 , & V_127 -> V_187 , sizeof( V_127 -> V_187 ) ) ;
V_68 = F_79 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
V_68 = F_65 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
F_27 ( V_14 , V_15 , V_127 -> V_145 , V_51 ) ;
F_27 ( V_14 , V_15 , V_127 -> V_140 , V_51 ) ;
F_27 ( V_14 , V_15 , V_157 , V_51 ) ;
V_68 = F_71 ( V_127 , V_157 ) ;
if ( V_68 )
goto V_19;
F_6 ( V_14 , V_15 , 3 * sizeof( T_1 ) +
V_127 -> V_160 * ( ( V_170 >= 5 ? sizeof( T_1 ) :
sizeof( V_103 ) ) +
sizeof( * V_127 -> V_153 ) +
sizeof( * V_127 -> V_154 ) ) , V_51 ) ;
if ( F_7 ( V_14 ) != V_127 -> V_160 )
goto V_51;
if ( V_170 >= 5 ) {
for ( V_38 = 0 ; V_38 < V_127 -> V_160 ; V_38 ++ )
V_127 -> V_152 [ V_38 ] = F_7 ( V_14 ) ;
} else {
for ( V_38 = 0 ; V_38 < V_127 -> V_160 ; V_38 ++ )
V_127 -> V_152 [ V_38 ] = F_41 ( V_14 ) ;
}
if ( F_7 ( V_14 ) != V_127 -> V_160 )
goto V_51;
for ( V_38 = 0 ; V_38 < V_127 -> V_160 ; V_38 ++ )
V_127 -> V_153 [ V_38 ] = F_7 ( V_14 ) ;
if ( F_7 ( V_14 ) != V_127 -> V_160 )
goto V_51;
F_105 ( V_14 , V_127 -> V_154 , V_127 -> V_160 * sizeof( * V_127 -> V_154 ) ) ;
for ( V_38 = 0 ; V_38 < V_127 -> V_160 ; V_38 ++ )
F_106 ( & V_127 -> V_154 [ V_38 ] ) ;
V_68 = F_86 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
if ( V_170 >= 1 ) {
V_68 = F_89 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
}
if ( V_170 >= 2 ) {
V_68 = F_93 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
} else {
F_18 ( V_127 -> V_155 ) ;
}
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
V_68 = F_73 ( V_127 , F_37 ( * V_14 , F_107 ( * V_14 + V_2 , V_15 ) ) ) ;
if ( V_68 )
goto V_19;
* V_14 += V_2 ;
if ( V_170 >= 3 ) {
F_45 ( V_14 , V_15 , string , string , string ,
V_51 ) ;
}
if ( V_170 >= 4 ) {
V_68 = F_97 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
V_68 = F_101 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
} else {
F_18 ( ! F_22 ( & V_127 -> V_148 ) ) ;
F_18 ( ! F_22 ( & V_127 -> V_149 ) ) ;
}
* V_14 = V_15 ;
F_5 ( L_39 , V_127 -> V_184 , V_127 -> V_160 ) ;
return 0 ;
V_51:
V_68 = - V_21 ;
V_19:
F_38 ( L_40 ,
V_68 , V_184 , ( int ) ( * V_14 - V_69 ) , * V_14 , V_69 , V_15 ) ;
F_108 ( V_188 , L_41 ,
V_189 , 16 , 1 ,
V_69 , V_15 - V_69 , true ) ;
return V_68 ;
}
struct V_126 * F_109 ( void * * V_14 , void * V_15 )
{
struct V_126 * V_127 ;
int V_50 ;
V_127 = F_67 () ;
if ( ! V_127 )
return F_29 ( - V_26 ) ;
V_50 = F_104 ( V_14 , V_15 , V_127 ) ;
if ( V_50 ) {
F_69 ( V_127 ) ;
return F_29 ( V_50 ) ;
}
return V_127 ;
}
static int F_110 ( void * * V_14 , void * V_15 , V_103 V_170 ,
struct V_126 * V_127 )
{
void * V_190 ;
void * V_191 ;
void * V_192 ;
T_1 V_2 ;
V_190 = * V_14 ;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
V_2 *= sizeof( T_1 ) + sizeof( struct V_158 ) ;
F_6 ( V_14 , V_15 , V_2 , V_51 ) ;
* V_14 += V_2 ;
V_191 = * V_14 ;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
V_2 *= sizeof( T_1 ) + ( V_170 >= 5 ? sizeof( T_1 ) : sizeof( V_103 ) ) ;
F_6 ( V_14 , V_15 , V_2 , V_51 ) ;
* V_14 += V_2 ;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
while ( V_2 -- ) {
T_7 V_180 ;
T_1 V_54 ;
F_6 ( V_14 , V_15 , 2 * sizeof( T_1 ) , V_51 ) ;
V_180 = F_7 ( V_14 ) ;
V_54 = F_7 ( V_14 ) ;
F_39 ( V_180 >= V_127 -> V_160 ) ;
F_95 ( L_42 , V_180 , V_54 ,
V_54 == V_193 ? L_43 :
( V_54 == V_161 ? L_44 : L_45 ) ) ;
V_127 -> V_153 [ V_180 ] = V_54 ;
if ( V_54 ) {
V_127 -> V_152 [ V_180 ] |= V_4 ;
V_127 -> V_152 [ V_180 ] &= ~ ( V_194 |
V_195 ) ;
}
}
V_192 = * V_14 ;
* V_14 = V_191 ;
V_2 = F_7 ( V_14 ) ;
while ( V_2 -- ) {
T_7 V_180 ;
T_1 V_196 ;
int V_50 ;
V_180 = F_7 ( V_14 ) ;
if ( V_170 >= 5 )
V_196 = F_7 ( V_14 ) ;
else
V_196 = F_41 ( V_14 ) ;
if ( V_196 == 0 )
V_196 = V_5 ;
F_39 ( V_180 >= V_127 -> V_160 ) ;
if ( ( V_127 -> V_152 [ V_180 ] & V_5 ) &&
( V_196 & V_5 ) )
F_95 ( L_46 , V_180 ) ;
if ( ( V_127 -> V_152 [ V_180 ] & V_4 ) &&
( V_196 & V_4 ) ) {
F_95 ( L_47 , V_180 ) ;
V_50 = F_92 ( V_127 , V_180 ,
V_163 ) ;
if ( V_50 )
return V_50 ;
memset ( V_127 -> V_154 + V_180 , 0 , sizeof( * V_127 -> V_154 ) ) ;
V_127 -> V_152 [ V_180 ] = 0 ;
} else {
V_127 -> V_152 [ V_180 ] ^= V_196 ;
}
}
* V_14 = V_190 ;
V_2 = F_7 ( V_14 ) ;
while ( V_2 -- ) {
T_7 V_180 ;
struct V_158 V_159 ;
V_180 = F_7 ( V_14 ) ;
F_105 ( V_14 , & V_159 , sizeof( V_159 ) ) ;
F_106 ( & V_159 ) ;
F_39 ( V_180 >= V_127 -> V_160 ) ;
F_95 ( L_48 , V_180 ) ;
V_127 -> V_152 [ V_180 ] |= V_4 | V_5 ;
V_127 -> V_154 [ V_180 ] = V_159 ;
}
* V_14 = V_192 ;
return 0 ;
V_51:
return - V_21 ;
}
struct V_126 * F_111 ( void * * V_14 , void * V_15 ,
struct V_126 * V_127 )
{
struct V_197 V_185 ;
T_1 V_184 = 0 ;
struct V_198 V_187 ;
T_7 V_2 ;
T_4 V_109 ;
T_8 V_199 ;
T_2 V_200 , V_157 ;
void * V_69 = * V_14 ;
int V_68 ;
V_103 V_170 ;
F_5 ( L_37 , V_167 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_68 = F_76 ( V_14 , V_15 , L_49 , & V_170 ) ;
if ( V_68 )
goto V_19;
F_6 ( V_14 , V_15 , sizeof( V_185 ) + sizeof( T_1 ) + sizeof( V_187 ) +
sizeof( T_4 ) + sizeof( T_1 ) , V_51 ) ;
F_105 ( V_14 , & V_185 , sizeof( V_185 ) ) ;
V_184 = F_7 ( V_14 ) ;
F_39 ( V_184 != V_127 -> V_184 + 1 ) ;
F_105 ( V_14 , & V_187 , sizeof( V_187 ) ) ;
V_199 = F_64 ( V_14 ) ;
V_200 = F_7 ( V_14 ) ;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
if ( V_2 > 0 ) {
F_5 ( L_50 ,
V_2 , * V_14 , V_15 ) ;
return F_109 ( V_14 , F_107 ( * V_14 + V_2 , V_15 ) ) ;
}
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
if ( V_2 > 0 ) {
V_68 = F_73 ( V_127 ,
F_37 ( * V_14 , F_107 ( * V_14 + V_2 , V_15 ) ) ) ;
if ( V_68 )
goto V_19;
* V_14 += V_2 ;
}
if ( V_200 >= 0 )
V_127 -> V_140 = V_200 ;
if ( V_199 >= 0 )
V_127 -> V_145 = V_199 ;
F_27 ( V_14 , V_15 , V_157 , V_51 ) ;
if ( V_157 >= 0 ) {
V_68 = F_71 ( V_127 , V_157 ) ;
if ( V_68 )
goto V_19;
}
V_127 -> V_184 ++ ;
V_127 -> V_187 = V_187 ;
V_68 = F_80 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
V_68 = F_65 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
F_27 ( V_14 , V_15 , V_2 , V_51 ) ;
while ( V_2 -- ) {
struct V_8 * V_9 ;
F_34 ( V_14 , V_15 , V_109 , V_51 ) ;
V_9 = F_54 ( & V_127 -> V_128 , V_109 ) ;
if ( V_9 )
F_60 ( & V_127 -> V_128 , V_9 ) ;
}
V_68 = F_110 ( V_14 , V_15 , V_170 , V_127 ) ;
if ( V_68 )
goto V_19;
V_68 = F_87 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
if ( V_170 >= 1 ) {
V_68 = F_90 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
}
if ( V_170 >= 2 ) {
V_68 = F_94 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
}
if ( V_170 >= 3 ) {
F_45 ( V_14 , V_15 , string , string , string ,
V_51 ) ;
F_112 ( V_14 , V_15 , string , V_51 ) ;
}
if ( V_170 >= 4 ) {
V_68 = F_98 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
V_68 = F_99 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
V_68 = F_102 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
V_68 = F_103 ( V_14 , V_15 , V_127 ) ;
if ( V_68 )
goto V_19;
}
* V_14 = V_15 ;
F_5 ( L_51 , V_127 -> V_184 , V_127 -> V_160 ) ;
return V_127 ;
V_51:
V_68 = - V_21 ;
V_19:
F_38 ( L_52 ,
V_68 , V_184 , ( int ) ( * V_14 - V_69 ) , * V_14 , V_69 , V_15 ) ;
F_108 ( V_188 , L_41 ,
V_189 , 16 , 1 ,
V_69 , V_15 - V_69 , true ) ;
return F_29 ( V_68 ) ;
}
void F_113 ( struct V_201 * V_202 ,
const struct V_201 * V_203 )
{
F_114 ( V_202 ) ;
V_202 -> V_109 = V_203 -> V_109 ;
if ( V_203 -> V_204 )
V_202 -> V_204 = F_115 ( V_203 -> V_204 ) ;
else
V_202 -> V_204 = NULL ;
}
void F_114 ( struct V_201 * V_205 )
{
F_116 ( V_205 -> V_204 ) ;
}
void F_117 ( struct V_206 * V_202 ,
const struct V_206 * V_203 )
{
F_118 ( V_202 ) ;
if ( V_203 -> V_131 != V_203 -> V_207 ) {
V_202 -> V_131 = F_42 ( V_203 -> V_208 + 1 ,
V_36 | V_209 ) ;
} else {
V_202 -> V_131 = V_202 -> V_207 ;
}
memcpy ( V_202 -> V_131 , V_203 -> V_131 , V_203 -> V_208 + 1 ) ;
V_202 -> V_208 = V_203 -> V_208 ;
}
void F_118 ( struct V_206 * V_210 )
{
if ( V_210 -> V_131 != V_210 -> V_207 )
F_20 ( V_210 -> V_131 ) ;
}
static bool F_119 ( const struct V_211 * V_107 ,
const struct V_211 * V_108 )
{
if ( V_107 -> V_18 == V_108 -> V_18 &&
! memcmp ( V_107 -> V_179 , V_108 -> V_179 , V_108 -> V_18 * sizeof( V_108 -> V_179 [ 0 ] ) ) )
return true ;
return false ;
}
static bool F_120 ( const struct V_211 * V_107 ,
const struct V_211 * V_108 )
{
if ( F_119 ( V_107 , V_108 ) &&
V_107 -> V_212 == V_108 -> V_212 )
return true ;
return false ;
}
static bool F_121 ( const struct V_211 * V_213 )
{
if ( V_213 -> V_18 > 0 && V_213 -> V_212 >= 0 )
return true ;
if ( ! V_213 -> V_18 && V_213 -> V_212 == - 1 )
return true ;
if ( V_213 -> V_18 > 0 && V_213 -> V_212 == - 1 ) {
int V_38 ;
for ( V_38 = 0 ; V_38 < V_213 -> V_18 ; V_38 ++ ) {
if ( V_213 -> V_179 [ V_38 ] != V_214 )
break;
}
if ( V_38 == V_213 -> V_18 )
return true ;
}
return false ;
}
void F_122 ( struct V_211 * V_202 , const struct V_211 * V_203 )
{
memcpy ( V_202 -> V_179 , V_203 -> V_179 , V_203 -> V_18 * sizeof( V_203 -> V_179 [ 0 ] ) ) ;
V_202 -> V_18 = V_203 -> V_18 ;
V_202 -> V_212 = V_203 -> V_212 ;
}
bool F_123 ( const struct V_106 * V_112 , T_1 V_215 ,
T_1 V_216 )
{
int V_217 = F_2 ( V_215 ) ;
int V_218 = ( 1 << V_217 ) - 1 ;
int V_125 ;
F_18 ( V_112 -> V_110 >= V_215 ) ;
if ( V_216 <= V_215 )
return false ;
for ( V_125 = 1 ; ; V_125 ++ ) {
int V_219 = V_125 << ( V_217 - 1 ) ;
T_1 V_220 = V_219 | V_112 -> V_110 ;
if ( V_220 < V_215 || V_220 == V_112 -> V_110 )
continue;
if ( V_220 >= V_216 )
break;
V_220 = F_124 ( V_220 , V_215 , V_218 ) ;
if ( V_220 == V_112 -> V_110 )
return true ;
}
return false ;
}
bool F_125 ( const struct V_211 * V_221 ,
const struct V_211 * V_222 ,
const struct V_211 * V_223 ,
const struct V_211 * V_224 ,
int V_225 ,
int V_226 ,
int V_227 ,
int V_228 ,
T_1 V_215 ,
T_1 V_216 ,
bool V_229 ,
bool V_230 ,
bool V_231 ,
bool V_232 ,
const struct V_106 * V_112 )
{
return ! F_120 ( V_221 , V_222 ) ||
! F_120 ( V_223 , V_224 ) ||
V_225 != V_226 ||
V_227 != V_228 ||
F_123 ( V_112 , V_215 , V_216 ) ||
V_229 != V_230 ||
V_231 != V_232 ;
}
static int F_126 ( int V_180 , const struct V_211 * V_233 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_233 -> V_18 ; V_38 ++ ) {
if ( V_233 -> V_179 [ V_38 ] == V_180 )
return V_38 ;
}
return - 1 ;
}
static bool F_127 ( const struct V_211 * V_221 ,
const struct V_211 * V_222 )
{
if ( ! V_221 -> V_18 && ! V_222 -> V_18 )
return false ;
if ( ! V_221 -> V_18 ^ ! V_222 -> V_18 )
return true ;
if ( V_221 -> V_212 != V_222 -> V_212 )
return true ;
if ( F_126 ( V_221 -> V_212 , V_221 ) !=
F_126 ( V_222 -> V_212 , V_222 ) )
return true ;
return false ;
}
bool F_128 ( const struct V_211 * V_221 ,
const struct V_211 * V_222 ,
bool V_234 )
{
if ( F_127 ( V_221 , V_222 ) )
return true ;
if ( V_234 && ! F_119 ( V_221 , V_222 ) )
return true ;
return false ;
}
int F_129 ( struct V_235 * V_236 ,
T_4 V_237 , T_4 V_2 ,
T_4 * V_238 ,
T_4 * V_239 , T_4 * V_240 )
{
T_1 V_241 = V_236 -> V_242 ;
T_1 V_243 = V_236 -> V_244 ;
T_1 V_245 = V_236 -> V_246 ;
T_1 V_247 , V_248 , V_249 , V_250 ;
T_1 V_251 ;
T_4 V_6 , V_252 ;
F_5 ( L_53 , V_237 , V_2 ,
V_241 , V_243 ) ;
if ( V_243 == 0 || V_245 == 0 )
goto V_253;
V_251 = V_241 / V_243 ;
if ( V_251 == 0 )
goto V_253;
F_5 ( L_54 , V_241 , V_243 ,
V_251 ) ;
if ( ( V_243 & ~ V_254 ) != 0 )
goto V_253;
V_6 = V_237 ;
F_130 ( V_6 , V_243 ) ;
V_247 = V_6 ;
F_5 ( L_55 , V_237 , V_243 , V_247 ) ;
V_248 = V_247 / V_245 ;
V_249 = V_247 % V_245 ;
V_250 = V_248 / V_251 ;
* V_238 = V_250 * V_245 + V_249 ;
F_5 ( L_56 , V_250 , V_245 , ( unsigned int ) * V_238 ) ;
V_6 = V_237 ;
V_252 = F_130 ( V_6 , V_243 ) ;
* V_239 = V_252 + ( V_248 % V_251 ) * V_243 ;
* V_240 = F_131 ( T_4 , V_2 , V_243 - V_252 ) ;
F_5 ( L_57 , * V_239 , * V_240 ) ;
return 0 ;
V_253:
F_5 ( L_58 ) ;
* V_238 = 0 ;
* V_239 = 0 ;
* V_240 = 0 ;
return - V_21 ;
}
int F_132 ( struct V_8 * V_9 ,
const struct V_206 * V_210 ,
const struct V_201 * V_205 ,
struct V_106 * V_255 )
{
F_18 ( V_9 -> V_87 != V_205 -> V_109 ) ;
if ( ! V_205 -> V_204 ) {
V_255 -> V_109 = V_205 -> V_109 ;
V_255 -> V_110 = F_133 ( V_9 -> V_139 , V_210 -> V_131 ,
V_210 -> V_208 ) ;
F_5 ( L_59 , V_167 , V_210 -> V_131 ,
V_255 -> V_109 , V_255 -> V_110 ) ;
} else {
char V_256 [ 256 ] ;
char * V_257 = V_256 ;
int V_258 = V_205 -> V_204 -> V_2 ;
T_3 V_259 = V_258 + 1 + V_210 -> V_208 ;
if ( V_259 > sizeof( V_256 ) ) {
V_257 = F_42 ( V_259 , V_36 ) ;
if ( ! V_257 )
return - V_26 ;
}
memcpy ( V_257 , V_205 -> V_204 -> V_1 , V_258 ) ;
V_257 [ V_258 ] = '\037' ;
memcpy ( V_257 + V_258 + 1 , V_210 -> V_131 , V_210 -> V_208 ) ;
V_255 -> V_109 = V_205 -> V_109 ;
V_255 -> V_110 = F_133 ( V_9 -> V_139 , V_257 , V_259 ) ;
if ( V_257 != V_256 )
F_20 ( V_257 ) ;
F_5 ( L_60 , V_167 ,
V_210 -> V_131 , V_258 , V_205 -> V_204 -> V_1 ,
V_255 -> V_109 , V_255 -> V_110 ) ;
}
return 0 ;
}
int F_134 ( struct V_126 * V_260 ,
const struct V_206 * V_210 ,
const struct V_201 * V_205 ,
struct V_106 * V_255 )
{
struct V_8 * V_9 ;
V_9 = F_55 ( V_260 , V_205 -> V_109 ) ;
if ( ! V_9 )
return - V_133 ;
return F_132 ( V_9 , V_210 , V_205 , V_255 ) ;
}
static void F_135 ( struct V_8 * V_9 ,
const struct V_106 * V_255 ,
struct V_106 * V_112 )
{
V_112 -> V_109 = V_255 -> V_109 ;
V_112 -> V_110 = F_124 ( V_255 -> V_110 , V_9 -> V_11 ,
V_9 -> V_10 ) ;
}
static T_1 F_136 ( struct V_8 * V_9 ,
const struct V_106 * V_255 )
{
if ( V_9 -> V_140 & V_261 ) {
return F_137 ( V_262 ,
F_124 ( V_255 -> V_110 ,
V_9 -> V_13 ,
V_9 -> V_12 ) ,
V_255 -> V_109 ) ;
} else {
return F_124 ( V_255 -> V_110 , V_9 -> V_13 ,
V_9 -> V_12 ) +
( unsigned ) V_255 -> V_109 ;
}
}
static int F_138 ( struct V_126 * V_127 , int V_263 , int V_264 ,
int * V_265 , int V_266 ,
const V_66 * V_89 , int V_267 ,
T_9 V_58 )
{
struct V_34 * V_35 ;
int V_93 ;
F_39 ( V_266 > V_166 ) ;
V_35 = F_139 ( & V_127 -> V_151 -> V_47 ,
V_58 ) ;
if ( ! V_35 )
V_35 = F_139 ( & V_127 -> V_151 -> V_47 ,
V_268 ) ;
F_140 ( & V_127 -> V_150 ) ;
V_93 = F_141 ( V_127 -> V_151 , V_263 , V_264 , V_265 , V_266 ,
V_89 , V_267 , V_127 -> V_156 ,
V_35 ? V_35 -> args : NULL ) ;
F_142 ( & V_127 -> V_150 ) ;
return V_93 ;
}
static void F_143 ( struct V_126 * V_260 ,
struct V_8 * V_9 ,
struct V_211 * V_213 )
{
int V_38 ;
if ( F_144 ( V_9 ) ) {
int V_269 = 0 ;
for ( V_38 = 0 ; V_38 < V_213 -> V_18 ; V_38 ++ ) {
if ( ! F_145 ( V_260 , V_213 -> V_179 [ V_38 ] ) ) {
V_269 ++ ;
continue;
}
if ( V_269 )
V_213 -> V_179 [ V_38 - V_269 ] = V_213 -> V_179 [ V_38 ] ;
}
V_213 -> V_18 -= V_269 ;
} else {
for ( V_38 = 0 ; V_38 < V_213 -> V_18 ; V_38 ++ ) {
if ( ! F_145 ( V_260 , V_213 -> V_179 [ V_38 ] ) )
V_213 -> V_179 [ V_38 ] = V_214 ;
}
}
}
static void F_146 ( struct V_126 * V_260 ,
struct V_8 * V_9 ,
const struct V_106 * V_255 ,
struct V_211 * V_270 ,
T_1 * V_271 )
{
T_1 V_272 = F_136 ( V_9 , V_255 ) ;
int V_263 ;
int V_2 ;
F_147 ( V_270 ) ;
if ( V_271 )
* V_271 = V_272 ;
V_263 = F_148 ( V_260 -> V_151 , V_9 -> V_138 , V_9 -> type ,
V_9 -> V_18 ) ;
if ( V_263 < 0 ) {
F_38 ( L_61 ,
V_9 -> V_87 , V_9 -> V_138 , V_9 -> type , V_9 -> V_18 ) ;
return;
}
if ( V_9 -> V_18 > F_149 ( V_270 -> V_179 ) ) {
F_150 ( L_62 ,
V_9 -> V_87 , V_9 -> V_138 , V_9 -> type , V_9 -> V_18 ,
F_149 ( V_270 -> V_179 ) ) ;
return;
}
V_2 = F_138 ( V_260 , V_263 , V_272 , V_270 -> V_179 , V_9 -> V_18 ,
V_260 -> V_153 , V_260 -> V_160 , V_9 -> V_87 ) ;
if ( V_2 < 0 ) {
F_38 ( L_63 ,
V_2 , V_263 , V_9 -> V_87 , V_9 -> V_138 , V_9 -> type ,
V_9 -> V_18 ) ;
return;
}
V_270 -> V_18 = V_2 ;
F_143 ( V_260 , V_9 , V_270 ) ;
}
static void F_151 ( struct V_126 * V_260 ,
const struct V_106 * V_112 ,
struct V_211 * V_270 )
{
struct V_114 * V_116 ;
int V_38 , V_23 ;
V_116 = F_83 ( & V_260 -> V_148 , V_112 ) ;
if ( V_116 ) {
for ( V_38 = 0 ; V_38 < V_116 -> V_148 . V_2 ; V_38 ++ ) {
int V_180 = V_116 -> V_148 . V_179 [ V_38 ] ;
if ( V_180 != V_214 &&
V_180 < V_260 -> V_160 &&
V_260 -> V_153 [ V_180 ] == 0 ) {
return;
}
}
for ( V_38 = 0 ; V_38 < V_116 -> V_148 . V_2 ; V_38 ++ )
V_270 -> V_179 [ V_38 ] = V_116 -> V_148 . V_179 [ V_38 ] ;
V_270 -> V_18 = V_116 -> V_148 . V_2 ;
}
V_116 = F_83 ( & V_260 -> V_149 , V_112 ) ;
if ( V_116 ) {
for ( V_38 = 0 ; V_38 < V_270 -> V_18 ; V_38 ++ ) {
for ( V_23 = 0 ; V_23 < V_116 -> V_149 . V_2 ; V_23 ++ ) {
int V_273 = V_116 -> V_149 . V_183 [ V_23 ] [ 0 ] ;
int V_274 = V_116 -> V_149 . V_183 [ V_23 ] [ 1 ] ;
if ( V_273 == V_270 -> V_179 [ V_38 ] ) {
if ( ! ( V_274 != V_214 &&
V_274 < V_260 -> V_160 &&
V_260 -> V_153 [ V_274 ] == 0 ) )
V_270 -> V_179 [ V_38 ] = V_274 ;
break;
}
}
}
}
}
static void F_152 ( struct V_126 * V_260 ,
struct V_8 * V_9 ,
struct V_211 * V_213 )
{
int V_38 ;
F_39 ( V_213 -> V_212 != - 1 ) ;
if ( F_144 ( V_9 ) ) {
int V_269 = 0 ;
for ( V_38 = 0 ; V_38 < V_213 -> V_18 ; V_38 ++ ) {
if ( F_153 ( V_260 , V_213 -> V_179 [ V_38 ] ) ) {
V_269 ++ ;
continue;
}
if ( V_269 )
V_213 -> V_179 [ V_38 - V_269 ] = V_213 -> V_179 [ V_38 ] ;
}
V_213 -> V_18 -= V_269 ;
if ( V_213 -> V_18 > 0 )
V_213 -> V_212 = V_213 -> V_179 [ 0 ] ;
} else {
for ( V_38 = V_213 -> V_18 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( F_153 ( V_260 , V_213 -> V_179 [ V_38 ] ) )
V_213 -> V_179 [ V_38 ] = V_214 ;
else
V_213 -> V_212 = V_213 -> V_179 [ V_38 ] ;
}
}
}
static void F_154 ( struct V_126 * V_260 ,
struct V_8 * V_9 ,
T_1 V_272 ,
struct V_211 * V_275 )
{
int V_38 ;
int V_276 = - 1 ;
if ( ! V_260 -> V_155 )
return;
for ( V_38 = 0 ; V_38 < V_275 -> V_18 ; V_38 ++ ) {
int V_180 = V_275 -> V_179 [ V_38 ] ;
if ( V_180 != V_214 &&
V_260 -> V_155 [ V_180 ] !=
V_163 ) {
break;
}
}
if ( V_38 == V_275 -> V_18 )
return;
for ( V_38 = 0 ; V_38 < V_275 -> V_18 ; V_38 ++ ) {
int V_180 = V_275 -> V_179 [ V_38 ] ;
T_1 V_181 ;
if ( V_180 == V_214 )
continue;
V_181 = V_260 -> V_155 [ V_180 ] ;
if ( V_181 < V_277 &&
( F_137 ( V_262 ,
V_272 , V_180 ) >> 16 ) >= V_181 ) {
if ( V_276 < 0 )
V_276 = V_38 ;
} else {
V_276 = V_38 ;
break;
}
}
if ( V_276 < 0 )
return;
V_275 -> V_212 = V_275 -> V_179 [ V_276 ] ;
if ( F_144 ( V_9 ) && V_276 > 0 ) {
for ( V_38 = V_276 ; V_38 > 0 ; V_38 -- )
V_275 -> V_179 [ V_38 ] = V_275 -> V_179 [ V_38 - 1 ] ;
V_275 -> V_179 [ 0 ] = V_275 -> V_212 ;
}
}
static void F_155 ( struct V_126 * V_260 ,
struct V_8 * V_9 ,
const struct V_106 * V_112 ,
struct V_211 * V_278 )
{
struct V_114 * V_116 ;
int V_38 ;
F_147 ( V_278 ) ;
V_116 = F_83 ( & V_260 -> V_146 , V_112 ) ;
if ( V_116 ) {
for ( V_38 = 0 ; V_38 < V_116 -> V_146 . V_2 ; V_38 ++ ) {
if ( F_153 ( V_260 , V_116 -> V_146 . V_179 [ V_38 ] ) ) {
if ( F_144 ( V_9 ) )
continue;
V_278 -> V_179 [ V_278 -> V_18 ++ ] = V_214 ;
} else {
V_278 -> V_179 [ V_278 -> V_18 ++ ] = V_116 -> V_146 . V_179 [ V_38 ] ;
}
}
for ( V_38 = 0 ; V_38 < V_278 -> V_18 ; V_38 ++ ) {
if ( V_278 -> V_179 [ V_38 ] != V_214 ) {
V_278 -> V_212 = V_278 -> V_179 [ V_38 ] ;
break;
}
}
}
V_116 = F_83 ( & V_260 -> V_147 , V_112 ) ;
if ( V_116 )
V_278 -> V_212 = V_116 -> V_147 . V_180 ;
}
void F_156 ( struct V_126 * V_260 ,
struct V_8 * V_9 ,
const struct V_106 * V_255 ,
struct V_211 * V_275 ,
struct V_211 * V_233 )
{
struct V_106 V_112 ;
T_1 V_272 ;
F_18 ( V_9 -> V_87 != V_255 -> V_109 ) ;
F_135 ( V_9 , V_255 , & V_112 ) ;
F_146 ( V_260 , V_9 , V_255 , V_275 , & V_272 ) ;
F_151 ( V_260 , & V_112 , V_275 ) ;
F_152 ( V_260 , V_9 , V_275 ) ;
F_154 ( V_260 , V_9 , V_272 , V_275 ) ;
F_155 ( V_260 , V_9 , & V_112 , V_233 ) ;
if ( ! V_233 -> V_18 ) {
memcpy ( V_233 -> V_179 , V_275 -> V_179 , V_275 -> V_18 * sizeof( V_275 -> V_179 [ 0 ] ) ) ;
V_233 -> V_18 = V_275 -> V_18 ;
if ( V_233 -> V_212 == - 1 )
V_233 -> V_212 = V_275 -> V_212 ;
}
F_18 ( ! F_121 ( V_275 ) || ! F_121 ( V_233 ) ) ;
}
bool F_157 ( struct V_126 * V_260 ,
struct V_8 * V_9 ,
const struct V_106 * V_255 ,
struct V_111 * V_279 )
{
struct V_106 V_112 ;
struct V_211 V_275 , V_233 ;
int V_38 ;
F_18 ( V_9 -> V_87 != V_255 -> V_109 ) ;
F_135 ( V_9 , V_255 , & V_112 ) ;
if ( F_144 ( V_9 ) ) {
V_279 -> V_112 = V_112 ;
V_279 -> V_113 = V_280 ;
return true ;
}
F_156 ( V_260 , V_9 , & V_112 , & V_275 , & V_233 ) ;
for ( V_38 = 0 ; V_38 < V_233 . V_18 ; V_38 ++ ) {
if ( V_233 . V_179 [ V_38 ] == V_233 . V_212 ) {
V_279 -> V_112 = V_112 ;
V_279 -> V_113 = V_38 ;
return true ;
}
}
return false ;
}
int F_158 ( struct V_126 * V_260 ,
const struct V_106 * V_255 )
{
struct V_8 * V_9 ;
struct V_211 V_275 , V_233 ;
V_9 = F_55 ( V_260 , V_255 -> V_109 ) ;
if ( ! V_9 )
return - 1 ;
F_156 ( V_260 , V_9 , V_255 , & V_275 , & V_233 ) ;
return V_233 . V_212 ;
}
