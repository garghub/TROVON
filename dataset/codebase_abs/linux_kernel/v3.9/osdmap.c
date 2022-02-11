char * F_1 ( char * V_1 , int V_2 , int V_3 )
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
F_6 ( V_14 , V_15 , ( 1 + V_7 -> V_17 . V_18 ) * sizeof( V_19 ) , V_20 ) ;
V_7 -> V_21 = F_7 ( V_14 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_8 ( void * * V_14 , void * V_15 ,
struct V_23 * V_7 )
{
int V_24 ;
F_5 ( L_6 , * V_14 , V_15 ) ;
V_7 -> V_25 = F_9 ( V_7 -> V_17 . V_18 , sizeof( V_19 ) , V_26 ) ;
if ( V_7 -> V_25 == NULL )
return - V_27 ;
V_7 -> V_28 = F_9 ( V_7 -> V_17 . V_18 , sizeof( V_19 ) , V_26 ) ;
if ( V_7 -> V_28 == NULL )
return - V_27 ;
F_6 ( V_14 , V_15 , 2 * V_7 -> V_17 . V_18 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_17 . V_18 ; V_24 ++ ) {
V_7 -> V_25 [ V_24 ] = F_7 ( V_14 ) ;
V_7 -> V_28 [ V_24 ] = F_7 ( V_14 ) ;
}
return 0 ;
V_20:
return - V_22 ;
}
static int F_10 ( void * * V_14 , void * V_15 ,
struct V_29 * V_7 )
{
int V_24 ;
F_5 ( L_7 , * V_14 , V_15 ) ;
F_11 ( V_14 , V_15 , V_7 -> V_30 , V_20 ) ;
V_7 -> V_31 = F_9 ( V_7 -> V_30 , sizeof( V_19 ) , V_26 ) ;
if ( V_7 -> V_31 == NULL )
return - V_27 ;
F_6 ( V_14 , V_15 , V_7 -> V_30 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_30 ; V_24 ++ )
V_7 -> V_31 [ V_24 ] = F_7 ( V_14 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_12 ( void * * V_14 , void * V_15 ,
struct V_32 * V_7 )
{
int V_24 ;
F_5 ( L_8 , * V_14 , V_15 ) ;
V_7 -> V_25 = F_9 ( V_7 -> V_17 . V_18 , sizeof( V_19 ) , V_26 ) ;
if ( V_7 -> V_25 == NULL )
return - V_27 ;
V_7 -> V_33 = F_9 ( V_7 -> V_17 . V_18 , sizeof( V_19 ) , V_26 ) ;
if ( V_7 -> V_33 == NULL )
return - V_27 ;
F_6 ( V_14 , V_15 , 2 * V_7 -> V_17 . V_18 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_17 . V_18 ; V_24 ++ ) {
V_7 -> V_25 [ V_24 ] = F_7 ( V_14 ) ;
V_7 -> V_33 [ V_24 ] = F_7 ( V_14 ) ;
}
return 0 ;
V_20:
return - V_22 ;
}
static int F_13 ( void * * V_14 , void * V_15 )
{
int V_2 ;
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
while ( V_2 -- ) {
int strlen ;
* V_14 += sizeof( V_19 ) ;
F_11 ( V_14 , V_15 , strlen , V_20 ) ;
* V_14 += strlen ;
}
return 0 ;
V_20:
return - V_22 ;
}
static struct V_34 * F_14 ( void * V_35 , void * V_15 )
{
struct V_34 * V_36 ;
int V_37 = - V_22 ;
int V_38 , V_24 ;
void * * V_14 = & V_35 ;
void * V_39 = V_35 ;
V_19 V_40 ;
V_19 V_41 ;
F_5 ( L_9 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_36 = F_15 ( sizeof( * V_36 ) , V_26 ) ;
if ( V_36 == NULL )
return F_16 ( - V_27 ) ;
V_36 -> V_42 = 2 ;
V_36 -> V_43 = 5 ;
V_36 -> V_44 = 19 ;
V_36 -> V_45 = 0 ;
F_6 ( V_14 , V_15 , 4 * sizeof( V_19 ) , V_20 ) ;
V_40 = F_7 ( V_14 ) ;
if ( V_40 != V_46 ) {
F_17 ( L_10 ,
( unsigned int ) V_40 , ( unsigned int ) V_46 ) ;
goto V_20;
}
V_36 -> V_47 = F_7 ( V_14 ) ;
V_36 -> V_48 = F_7 ( V_14 ) ;
V_36 -> V_49 = F_7 ( V_14 ) ;
V_36 -> V_50 = F_9 ( V_36 -> V_47 , sizeof( * V_36 -> V_50 ) , V_26 ) ;
if ( V_36 -> V_50 == NULL )
goto V_51;
V_36 -> V_52 = F_9 ( V_36 -> V_48 , sizeof( * V_36 -> V_52 ) , V_26 ) ;
if ( V_36 -> V_52 == NULL )
goto V_51;
for ( V_38 = 0 ; V_38 < V_36 -> V_47 ; V_38 ++ ) {
int V_18 = 0 ;
V_19 V_53 ;
struct V_54 * V_7 ;
F_11 ( V_14 , V_15 , V_53 , V_20 ) ;
if ( V_53 == 0 ) {
V_36 -> V_50 [ V_38 ] = NULL ;
continue;
}
F_5 ( L_11 ,
V_38 , ( int ) ( * V_14 - V_39 ) , * V_14 , V_15 ) ;
switch ( V_53 ) {
case V_55 :
V_18 = sizeof( struct V_16 ) ;
break;
case V_56 :
V_18 = sizeof( struct V_23 ) ;
break;
case V_57 :
V_18 = sizeof( struct V_29 ) ;
break;
case V_58 :
V_18 = sizeof( struct V_32 ) ;
break;
default:
V_37 = - V_22 ;
goto V_20;
}
F_18 ( V_18 == 0 ) ;
V_7 = V_36 -> V_50 [ V_38 ] = F_15 ( V_18 , V_26 ) ;
if ( V_7 == NULL )
goto V_51;
F_6 ( V_14 , V_15 , 4 * sizeof( V_19 ) , V_20 ) ;
V_7 -> V_59 = F_7 ( V_14 ) ;
V_7 -> type = F_19 ( V_14 ) ;
V_7 -> V_53 = F_20 ( V_14 ) ;
V_7 -> V_60 = F_20 ( V_14 ) ;
V_7 -> V_61 = F_7 ( V_14 ) ;
V_7 -> V_18 = F_7 ( V_14 ) ;
F_5 ( L_12 ,
V_7 -> V_18 , ( int ) ( * V_14 - V_39 ) , * V_14 , V_15 ) ;
V_7 -> V_62 = F_9 ( V_7 -> V_18 , sizeof( V_63 ) , V_26 ) ;
if ( V_7 -> V_62 == NULL )
goto V_51;
V_7 -> V_64 = F_9 ( V_7 -> V_18 , sizeof( V_19 ) , V_26 ) ;
if ( V_7 -> V_64 == NULL )
goto V_51;
V_7 -> V_65 = 0 ;
F_6 ( V_14 , V_15 , V_7 -> V_18 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_18 ; V_24 ++ )
V_7 -> V_62 [ V_24 ] = F_7 ( V_14 ) ;
switch ( V_7 -> V_53 ) {
case V_55 :
V_37 = F_4 ( V_14 , V_15 ,
(struct V_16 * ) V_7 ) ;
if ( V_37 < 0 )
goto V_20;
break;
case V_56 :
V_37 = F_8 ( V_14 , V_15 ,
(struct V_23 * ) V_7 ) ;
if ( V_37 < 0 )
goto V_20;
break;
case V_57 :
V_37 = F_10 ( V_14 , V_15 ,
(struct V_29 * ) V_7 ) ;
if ( V_37 < 0 )
goto V_20;
break;
case V_58 :
V_37 = F_12 ( V_14 , V_15 ,
(struct V_32 * ) V_7 ) ;
if ( V_37 < 0 )
goto V_20;
break;
}
}
F_5 ( L_13 , V_36 -> V_52 ) ;
for ( V_38 = 0 ; V_38 < V_36 -> V_48 ; V_38 ++ ) {
V_19 V_66 ;
struct V_67 * V_68 ;
F_11 ( V_14 , V_15 , V_66 , V_20 ) ;
if ( ! V_66 ) {
F_5 ( L_14 ,
V_38 , ( int ) ( * V_14 - V_39 ) , * V_14 , V_15 ) ;
V_36 -> V_52 [ V_38 ] = NULL ;
continue;
}
F_5 ( L_15 ,
V_38 , ( int ) ( * V_14 - V_39 ) , * V_14 , V_15 ) ;
F_11 ( V_14 , V_15 , V_66 , V_20 ) ;
#if V_69 == 32
V_37 = - V_22 ;
if ( V_66 > ( V_70 - sizeof( * V_68 ) )
/ sizeof( struct V_71 ) )
goto V_20;
#endif
V_68 = V_36 -> V_52 [ V_38 ] = F_21 ( sizeof( * V_68 ) +
V_66 * sizeof( struct V_71 ) ,
V_26 ) ;
if ( V_68 == NULL )
goto V_51;
F_5 ( L_16 , V_38 , V_68 ) ;
V_68 -> V_2 = V_66 ;
F_22 ( V_14 , V_15 , & V_68 -> V_72 , 4 , V_20 ) ;
F_6 ( V_14 , V_15 , V_68 -> V_2 * 3 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_68 -> V_2 ; V_24 ++ ) {
V_68 -> V_73 [ V_24 ] . V_74 = F_7 ( V_14 ) ;
V_68 -> V_73 [ V_24 ] . V_75 = F_7 ( V_14 ) ;
V_68 -> V_73 [ V_24 ] . V_76 = F_7 ( V_14 ) ;
}
}
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ ) {
V_37 = F_13 ( V_14 , V_15 ) ;
if ( V_37 < 0 )
goto V_77;
}
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) , V_77 ) ;
V_36 -> V_42 = F_7 ( V_14 ) ;
V_36 -> V_43 = F_7 ( V_14 ) ;
V_36 -> V_44 = F_7 ( V_14 ) ;
F_5 ( L_17 ,
V_36 -> V_42 ) ;
F_5 ( L_18 ,
V_36 -> V_43 ) ;
F_5 ( L_19 ,
V_36 -> V_44 ) ;
F_6 ( V_14 , V_15 , sizeof( V_19 ) , V_77 ) ;
V_36 -> V_45 = F_7 ( V_14 ) ;
F_5 ( L_20 ,
V_36 -> V_45 ) ;
V_77:
F_5 ( L_21 ) ;
return V_36 ;
V_51:
V_37 = - V_27 ;
V_20:
F_5 ( L_22 , V_37 ) ;
F_23 ( V_36 ) ;
return F_16 ( V_37 ) ;
}
static int F_24 ( struct V_78 V_79 , struct V_78 V_68 )
{
if ( V_79 . V_80 < V_68 . V_80 )
return - 1 ;
if ( V_79 . V_80 > V_68 . V_80 )
return 1 ;
if ( V_79 . V_81 < V_68 . V_81 )
return - 1 ;
if ( V_79 . V_81 > V_68 . V_81 )
return 1 ;
return 0 ;
}
static int F_25 ( struct V_82 * V_83 ,
struct V_84 * V_85 )
{
struct V_86 * * V_14 = & V_85 -> V_86 ;
struct V_86 * V_87 = NULL ;
struct V_82 * V_88 = NULL ;
int V_36 ;
F_5 ( L_23 , * ( V_89 * ) & V_83 -> V_90 , V_83 ) ;
while ( * V_14 ) {
V_87 = * V_14 ;
V_88 = F_26 ( V_87 , struct V_82 , V_91 ) ;
V_36 = F_24 ( V_83 -> V_90 , V_88 -> V_90 ) ;
if ( V_36 < 0 )
V_14 = & ( * V_14 ) -> V_92 ;
else if ( V_36 > 0 )
V_14 = & ( * V_14 ) -> V_93 ;
else
return - V_94 ;
}
F_27 ( & V_83 -> V_91 , V_87 , V_14 ) ;
F_28 ( & V_83 -> V_91 , V_85 ) ;
return 0 ;
}
static struct V_82 * F_29 ( struct V_84 * V_85 ,
struct V_78 V_90 )
{
struct V_86 * V_95 = V_85 -> V_86 ;
struct V_82 * V_88 ;
int V_36 ;
while ( V_95 ) {
V_88 = F_26 ( V_95 , struct V_82 , V_91 ) ;
V_36 = F_24 ( V_90 , V_88 -> V_90 ) ;
if ( V_36 < 0 ) {
V_95 = V_95 -> V_92 ;
} else if ( V_36 > 0 ) {
V_95 = V_95 -> V_93 ;
} else {
F_5 ( L_24 ,
V_90 . V_80 , V_90 . V_81 , V_88 ) ;
return V_88 ;
}
}
return NULL ;
}
static int F_30 ( struct V_84 * V_85 , struct V_78 V_90 )
{
struct V_82 * V_88 = F_29 ( V_85 , V_90 ) ;
if ( V_88 ) {
F_5 ( L_25 , V_90 . V_80 , V_90 . V_81 ,
V_88 ) ;
F_31 ( & V_88 -> V_91 , V_85 ) ;
F_32 ( V_88 ) ;
return 0 ;
}
F_5 ( L_26 , V_90 . V_80 , V_90 . V_81 ) ;
return - V_96 ;
}
static int F_33 ( struct V_84 * V_85 , struct V_8 * V_83 )
{
struct V_86 * * V_14 = & V_85 -> V_86 ;
struct V_86 * V_87 = NULL ;
struct V_8 * V_9 = NULL ;
while ( * V_14 ) {
V_87 = * V_14 ;
V_9 = F_26 ( V_87 , struct V_8 , V_91 ) ;
if ( V_83 -> V_59 < V_9 -> V_59 )
V_14 = & ( * V_14 ) -> V_92 ;
else if ( V_83 -> V_59 > V_9 -> V_59 )
V_14 = & ( * V_14 ) -> V_93 ;
else
return - V_94 ;
}
F_27 ( & V_83 -> V_91 , V_87 , V_14 ) ;
F_28 ( & V_83 -> V_91 , V_85 ) ;
return 0 ;
}
static struct V_8 * F_34 ( struct V_84 * V_85 , V_89 V_59 )
{
struct V_8 * V_9 ;
struct V_86 * V_95 = V_85 -> V_86 ;
while ( V_95 ) {
V_9 = F_26 ( V_95 , struct V_8 , V_91 ) ;
if ( V_59 < V_9 -> V_59 )
V_95 = V_95 -> V_92 ;
else if ( V_59 > V_9 -> V_59 )
V_95 = V_95 -> V_93 ;
else
return V_9 ;
}
return NULL ;
}
const char * F_35 ( struct V_97 * V_98 , V_89 V_59 )
{
struct V_8 * V_9 ;
if ( V_59 == V_99 )
return NULL ;
if ( F_36 ( V_59 > ( V_89 ) V_100 ) )
return NULL ;
V_9 = F_34 ( & V_98 -> V_101 , ( int ) V_59 ) ;
return V_9 ? V_9 -> V_102 : NULL ;
}
int F_37 ( struct V_97 * V_98 , const char * V_102 )
{
struct V_86 * V_103 ;
for ( V_103 = F_38 ( & V_98 -> V_101 ) ; V_103 ; V_103 = F_39 ( V_103 ) ) {
struct V_8 * V_9 =
F_26 ( V_103 , struct V_8 , V_91 ) ;
if ( V_9 -> V_102 && strcmp ( V_9 -> V_102 , V_102 ) == 0 )
return V_9 -> V_59 ;
}
return - V_96 ;
}
static void F_40 ( struct V_84 * V_85 , struct V_8 * V_9 )
{
F_31 ( & V_9 -> V_91 , V_85 ) ;
F_32 ( V_9 -> V_102 ) ;
F_32 ( V_9 ) ;
}
static int F_41 ( void * * V_14 , void * V_15 , struct V_8 * V_9 )
{
T_1 V_104 , V_105 ;
unsigned V_2 , V_106 ;
void * V_107 ;
F_6 ( V_14 , V_15 , 2 + 4 , V_20 ) ;
V_104 = F_20 ( V_14 ) ;
V_105 = F_20 ( V_14 ) ;
if ( V_104 < 5 ) {
F_42 ( L_27 , V_104 , V_105 ) ;
return - V_22 ;
}
if ( V_105 > 7 ) {
F_42 ( L_28 , V_104 , V_105 ) ;
return - V_22 ;
}
V_2 = F_7 ( V_14 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_107 = * V_14 + V_2 ;
V_9 -> type = F_20 ( V_14 ) ;
V_9 -> V_18 = F_20 ( V_14 ) ;
V_9 -> V_108 = F_20 ( V_14 ) ;
V_9 -> V_109 = F_20 ( V_14 ) ;
V_9 -> V_11 = F_7 ( V_14 ) ;
V_9 -> V_13 = F_7 ( V_14 ) ;
* V_14 += 4 + 4 ;
* V_14 += 4 ;
* V_14 += 8 + 4 ;
V_106 = F_7 ( V_14 ) ;
while ( V_106 -- ) {
* V_14 += 8 ;
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
V_106 = F_7 ( V_14 ) ;
* V_14 += V_106 * ( 8 + 8 ) ;
* V_14 += 8 ;
V_9 -> V_110 = F_43 ( V_14 ) ;
* V_14 = V_107 ;
F_3 ( V_9 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_44 ( void * * V_14 , void * V_15 , struct V_97 * V_98 )
{
struct V_8 * V_9 ;
V_19 V_106 , V_2 ;
V_89 V_80 ;
F_11 ( V_14 , V_15 , V_106 , V_20 ) ;
F_5 ( L_29 , V_106 ) ;
while ( V_106 -- ) {
F_45 ( V_14 , V_15 , V_80 , V_20 ) ;
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
F_5 ( L_30 , V_80 , V_2 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_9 = F_34 ( & V_98 -> V_101 , V_80 ) ;
if ( V_9 ) {
char * V_102 = F_46 ( * V_14 , V_2 , V_26 ) ;
if ( ! V_102 )
return - V_27 ;
F_32 ( V_9 -> V_102 ) ;
V_9 -> V_102 = V_102 ;
F_5 ( L_31 , V_9 -> V_102 ) ;
}
* V_14 += V_2 ;
}
return 0 ;
V_20:
return - V_22 ;
}
void F_47 ( struct V_97 * V_98 )
{
F_5 ( L_32 , V_98 ) ;
if ( V_98 -> V_111 )
F_23 ( V_98 -> V_111 ) ;
while ( ! F_48 ( & V_98 -> V_112 ) ) {
struct V_82 * V_88 =
F_26 ( F_38 ( & V_98 -> V_112 ) ,
struct V_82 , V_91 ) ;
F_31 ( & V_88 -> V_91 , & V_98 -> V_112 ) ;
F_32 ( V_88 ) ;
}
while ( ! F_48 ( & V_98 -> V_101 ) ) {
struct V_8 * V_9 =
F_26 ( F_38 ( & V_98 -> V_101 ) ,
struct V_8 , V_91 ) ;
F_40 ( & V_98 -> V_101 , V_9 ) ;
}
F_32 ( V_98 -> V_113 ) ;
F_32 ( V_98 -> V_114 ) ;
F_32 ( V_98 -> V_115 ) ;
F_32 ( V_98 ) ;
}
static int F_49 ( struct V_97 * V_98 , int V_116 )
{
T_1 * V_3 ;
struct V_117 * V_118 ;
V_19 * V_61 ;
V_3 = F_9 ( V_116 , sizeof( * V_3 ) , V_26 ) ;
V_118 = F_9 ( V_116 , sizeof( * V_118 ) , V_26 ) ;
V_61 = F_9 ( V_116 , sizeof( * V_61 ) , V_26 ) ;
if ( V_3 == NULL || V_118 == NULL || V_61 == NULL ) {
F_32 ( V_3 ) ;
F_32 ( V_118 ) ;
F_32 ( V_61 ) ;
return - V_27 ;
}
if ( V_98 -> V_113 ) {
memcpy ( V_3 , V_98 -> V_113 , V_98 -> V_119 * sizeof( * V_3 ) ) ;
memcpy ( V_118 , V_98 -> V_115 , V_98 -> V_119 * sizeof( * V_118 ) ) ;
memcpy ( V_61 , V_98 -> V_114 , V_98 -> V_119 * sizeof( * V_61 ) ) ;
F_32 ( V_98 -> V_113 ) ;
F_32 ( V_98 -> V_115 ) ;
F_32 ( V_98 -> V_114 ) ;
}
V_98 -> V_113 = V_3 ;
V_98 -> V_114 = V_61 ;
V_98 -> V_115 = V_118 ;
V_98 -> V_119 = V_116 ;
return 0 ;
}
static int F_50 ( void * * V_14 , void * V_15 , struct V_78 * V_88 )
{
T_1 V_120 ;
F_6 ( V_14 , V_15 , 1 + 8 + 4 + 4 , V_20 ) ;
V_120 = F_20 ( V_14 ) ;
if ( V_120 != 1 )
goto V_20;
V_88 -> V_80 = F_43 ( V_14 ) ;
V_88 -> V_81 = F_7 ( V_14 ) ;
* V_14 += 4 ;
return 0 ;
V_20:
F_5 ( L_33 ) ;
return - V_22 ;
}
struct V_97 * F_51 ( void * * V_14 , void * V_15 )
{
struct V_97 * V_98 ;
T_2 V_121 ;
V_19 V_2 , V_116 , V_38 ;
int V_37 = - V_22 ;
void * V_39 = * V_14 ;
struct V_8 * V_9 ;
F_5 ( L_34 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_98 = F_15 ( sizeof( * V_98 ) , V_26 ) ;
if ( V_98 == NULL )
return F_16 ( - V_27 ) ;
V_98 -> V_112 = V_122 ;
F_52 ( V_14 , V_15 , V_121 , V_20 ) ;
if ( V_121 > 6 ) {
F_42 ( L_35 , V_121 ) ;
goto V_20;
}
if ( V_121 < 6 ) {
F_42 ( L_36 , V_121 ) ;
goto V_20;
}
F_6 ( V_14 , V_15 , 2 * sizeof( V_89 ) + 6 * sizeof( V_19 ) , V_20 ) ;
F_53 ( V_14 , & V_98 -> V_123 , sizeof( V_98 -> V_123 ) ) ;
V_98 -> V_124 = F_7 ( V_14 ) ;
F_53 ( V_14 , & V_98 -> V_125 , sizeof( V_98 -> V_125 ) ) ;
F_53 ( V_14 , & V_98 -> V_126 , sizeof( V_98 -> V_126 ) ) ;
F_11 ( V_14 , V_15 , V_116 , V_20 ) ;
while ( V_116 -- ) {
F_6 ( V_14 , V_15 , 8 + 2 , V_20 ) ;
V_37 = - V_27 ;
V_9 = F_15 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
goto V_20;
V_9 -> V_59 = F_43 ( V_14 ) ;
V_37 = F_41 ( V_14 , V_15 , V_9 ) ;
if ( V_37 < 0 ) {
F_32 ( V_9 ) ;
goto V_20;
}
F_33 ( & V_98 -> V_101 , V_9 ) ;
}
V_37 = F_44 ( V_14 , V_15 , V_98 ) ;
if ( V_37 < 0 ) {
F_5 ( L_37 ) ;
goto V_20;
}
F_11 ( V_14 , V_15 , V_98 -> V_127 , V_20 ) ;
F_11 ( V_14 , V_15 , V_98 -> V_110 , V_20 ) ;
V_116 = F_7 ( V_14 ) ;
V_37 = F_49 ( V_98 , V_116 ) ;
if ( V_37 < 0 )
goto V_20;
F_5 ( L_38 , V_98 -> V_119 ) ;
V_37 = - V_22 ;
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) +
V_98 -> V_119 * ( 1 + sizeof( * V_98 -> V_114 ) +
sizeof( * V_98 -> V_115 ) ) , V_20 ) ;
* V_14 += 4 ;
F_53 ( V_14 , V_98 -> V_113 , V_98 -> V_119 ) ;
* V_14 += 4 ;
for ( V_38 = 0 ; V_38 < V_98 -> V_119 ; V_38 ++ )
V_98 -> V_114 [ V_38 ] = F_7 ( V_14 ) ;
* V_14 += 4 ;
F_53 ( V_14 , V_98 -> V_115 , V_98 -> V_119 * sizeof( * V_98 -> V_115 ) ) ;
for ( V_38 = 0 ; V_38 < V_98 -> V_119 ; V_38 ++ )
F_54 ( & V_98 -> V_115 [ V_38 ] ) ;
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
int V_95 , V_24 ;
struct V_78 V_90 ;
struct V_82 * V_88 ;
V_37 = F_50 ( V_14 , V_15 , & V_90 ) ;
if ( V_37 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_19 ) , V_20 ) ;
V_95 = F_7 ( V_14 ) ;
V_37 = - V_22 ;
if ( V_95 > ( V_128 - sizeof( * V_88 ) ) / sizeof( V_19 ) )
goto V_20;
F_6 ( V_14 , V_15 , V_95 * sizeof( V_19 ) , V_20 ) ;
V_37 = - V_27 ;
V_88 = F_21 ( sizeof( * V_88 ) + V_95 * sizeof( V_19 ) , V_26 ) ;
if ( ! V_88 )
goto V_20;
V_88 -> V_90 = V_90 ;
V_88 -> V_2 = V_95 ;
for ( V_24 = 0 ; V_24 < V_95 ; V_24 ++ )
V_88 -> V_129 [ V_24 ] = F_7 ( V_14 ) ;
V_37 = F_25 ( V_88 , & V_98 -> V_112 ) ;
if ( V_37 )
goto V_20;
F_5 ( L_39 , V_90 . V_80 , V_90 . V_81 ,
V_2 ) ;
}
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
F_5 ( L_40 , V_2 ,
( int ) ( * V_14 - V_39 ) ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_98 -> V_111 = F_14 ( * V_14 , V_15 ) ;
* V_14 += V_2 ;
if ( F_55 ( V_98 -> V_111 ) ) {
V_37 = F_56 ( V_98 -> V_111 ) ;
V_98 -> V_111 = NULL ;
goto V_20;
}
* V_14 = V_15 ;
F_5 ( L_41 , * V_14 , V_15 ) ;
return V_98 ;
V_20:
F_5 ( L_42 , V_37 ) ;
F_47 ( V_98 ) ;
return F_16 ( V_37 ) ;
}
struct V_97 * F_57 ( void * * V_14 , void * V_15 ,
struct V_97 * V_98 ,
struct V_130 * V_131 )
{
struct V_34 * V_132 = NULL ;
struct V_133 V_123 ;
V_19 V_124 = 0 ;
struct V_134 V_126 ;
T_3 V_2 ;
V_89 V_80 ;
T_4 V_135 ;
V_63 V_136 , V_116 ;
void * V_39 = * V_14 ;
int V_37 = - V_22 ;
T_2 V_121 ;
F_52 ( V_14 , V_15 , V_121 , V_20 ) ;
if ( V_121 != 6 ) {
F_42 ( L_43 , V_121 ) ;
goto V_20;
}
F_6 ( V_14 , V_15 , sizeof( V_123 ) + sizeof( V_126 ) + 2 * sizeof( V_19 ) ,
V_20 ) ;
F_53 ( V_14 , & V_123 , sizeof( V_123 ) ) ;
V_124 = F_7 ( V_14 ) ;
F_18 ( V_124 != V_98 -> V_124 + 1 ) ;
F_53 ( V_14 , & V_126 , sizeof( V_126 ) ) ;
V_135 = F_43 ( V_14 ) ;
V_136 = F_7 ( V_14 ) ;
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
if ( V_2 > 0 ) {
F_5 ( L_44 ,
V_2 , * V_14 , V_15 ) ;
return F_51 ( V_14 , F_58 ( * V_14 + V_2 , V_15 ) ) ;
}
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
if ( V_2 > 0 ) {
F_5 ( L_45 ,
V_2 , * V_14 , V_15 ) ;
V_132 = F_14 ( * V_14 , F_58 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_55 ( V_132 ) )
return F_59 ( V_132 ) ;
* V_14 += V_2 ;
}
if ( V_136 >= 0 )
V_98 -> V_110 = V_136 ;
if ( V_135 >= 0 )
V_98 -> V_127 = V_135 ;
F_6 ( V_14 , V_15 , 5 * sizeof( V_19 ) , V_20 ) ;
V_116 = F_7 ( V_14 ) ;
if ( V_116 >= 0 ) {
V_37 = F_49 ( V_98 , V_116 ) ;
if ( V_37 < 0 )
goto V_20;
}
V_98 -> V_124 ++ ;
V_98 -> V_126 = V_126 ;
if ( V_132 ) {
if ( V_98 -> V_111 )
F_23 ( V_98 -> V_111 ) ;
V_98 -> V_111 = V_132 ;
V_132 = NULL ;
}
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
while ( V_2 -- ) {
struct V_8 * V_9 ;
F_45 ( V_14 , V_15 , V_80 , V_20 ) ;
V_9 = F_34 ( & V_98 -> V_101 , V_80 ) ;
if ( ! V_9 ) {
V_9 = F_15 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 ) {
V_37 = - V_27 ;
goto V_20;
}
V_9 -> V_59 = V_80 ;
F_33 ( & V_98 -> V_101 , V_9 ) ;
}
V_37 = F_41 ( V_14 , V_15 , V_9 ) ;
if ( V_37 < 0 )
goto V_20;
}
if ( V_121 >= 5 ) {
V_37 = F_44 ( V_14 , V_15 , V_98 ) ;
if ( V_37 < 0 )
goto V_20;
}
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
while ( V_2 -- ) {
struct V_8 * V_9 ;
F_45 ( V_14 , V_15 , V_80 , V_20 ) ;
V_9 = F_34 ( & V_98 -> V_101 , V_80 ) ;
if ( V_9 )
F_40 ( & V_98 -> V_101 , V_9 ) ;
}
V_37 = - V_22 ;
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
while ( V_2 -- ) {
V_19 V_137 ;
struct V_117 V_118 ;
F_11 ( V_14 , V_15 , V_137 , V_20 ) ;
F_22 ( V_14 , V_15 , & V_118 , sizeof( V_118 ) , V_20 ) ;
F_54 ( & V_118 ) ;
F_60 ( L_46 , V_137 ) ;
F_18 ( V_137 >= V_98 -> V_119 ) ;
V_98 -> V_113 [ V_137 ] |= V_5 ;
V_98 -> V_115 [ V_137 ] = V_118 ;
}
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
while ( V_2 -- ) {
V_19 V_137 ;
T_1 V_138 ;
F_11 ( V_14 , V_15 , V_137 , V_20 ) ;
V_138 = * * ( T_1 * * ) V_14 ;
( * V_14 ) ++ ;
if ( V_138 == 0 )
V_138 = V_5 ;
if ( V_138 & V_5 )
F_60 ( L_47 , V_137 ) ;
if ( V_137 < V_98 -> V_119 )
V_98 -> V_113 [ V_137 ] ^= V_138 ;
}
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
while ( V_2 -- ) {
V_19 V_137 , V_139 ;
F_6 ( V_14 , V_15 , sizeof( V_19 ) * 2 , V_20 ) ;
V_137 = F_7 ( V_14 ) ;
V_139 = F_7 ( V_14 ) ;
F_60 ( L_48 , V_137 , V_139 ,
V_139 == V_140 ? L_49 :
( V_139 == V_141 ? L_50 : L_51 ) ) ;
if ( V_137 < V_98 -> V_119 )
V_98 -> V_114 [ V_137 ] = V_139 ;
}
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
while ( V_2 -- ) {
struct V_82 * V_88 ;
int V_24 ;
struct V_78 V_90 ;
V_19 V_142 ;
V_37 = F_50 ( V_14 , V_15 , & V_90 ) ;
if ( V_37 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_19 ) , V_20 ) ;
V_142 = F_7 ( V_14 ) ;
if ( V_142 ) {
F_6 ( V_14 , V_15 , V_142 * sizeof( V_19 ) , V_20 ) ;
( void ) F_30 ( & V_98 -> V_112 , V_90 ) ;
V_37 = - V_22 ;
if ( V_142 > ( V_128 - sizeof( * V_88 ) ) / sizeof( V_19 ) )
goto V_20;
V_37 = - V_27 ;
V_88 = F_21 ( sizeof( * V_88 ) + sizeof( V_19 ) * V_142 , V_26 ) ;
if ( ! V_88 )
goto V_20;
V_88 -> V_90 = V_90 ;
V_88 -> V_2 = V_142 ;
for ( V_24 = 0 ; V_24 < V_142 ; V_24 ++ )
V_88 -> V_129 [ V_24 ] = F_7 ( V_14 ) ;
V_37 = F_25 ( V_88 , & V_98 -> V_112 ) ;
if ( V_37 ) {
F_32 ( V_88 ) ;
goto V_20;
}
F_5 ( L_39 , V_90 . V_80 ,
V_90 . V_81 , V_142 ) ;
} else {
F_30 ( & V_98 -> V_112 , V_90 ) ;
}
}
* V_14 = V_15 ;
return V_98 ;
V_20:
F_17 ( L_52 ,
V_124 , ( int ) ( * V_14 - V_39 ) , * V_14 , V_39 , V_15 ) ;
F_61 ( V_143 , L_53 ,
V_144 , 16 , 1 ,
V_39 , V_15 - V_39 , true ) ;
if ( V_132 )
F_23 ( V_132 ) ;
return F_16 ( V_37 ) ;
}
int F_62 ( struct V_145 * V_146 ,
V_89 V_139 , V_89 V_2 ,
V_89 * V_147 ,
V_89 * V_148 , V_89 * V_149 )
{
V_19 V_150 = F_63 ( V_146 -> V_151 ) ;
V_19 V_152 = F_63 ( V_146 -> V_153 ) ;
V_19 V_154 = F_63 ( V_146 -> V_155 ) ;
V_19 V_156 , V_157 , V_158 , V_159 ;
V_19 V_160 ;
V_89 V_6 , V_161 ;
F_5 ( L_54 , V_139 , V_2 ,
V_150 , V_152 ) ;
if ( V_152 == 0 || V_154 == 0 )
goto V_162;
V_160 = V_150 / V_152 ;
if ( V_160 == 0 )
goto V_162;
F_5 ( L_55 , V_150 , V_152 ,
V_160 ) ;
if ( ( V_152 & ~ V_163 ) != 0 )
goto V_162;
V_6 = V_139 ;
F_64 ( V_6 , V_152 ) ;
V_156 = V_6 ;
F_5 ( L_56 , V_139 , V_152 , V_156 ) ;
V_157 = V_156 / V_154 ;
V_158 = V_156 % V_154 ;
V_159 = V_157 / V_160 ;
* V_147 = V_159 * V_154 + V_158 ;
F_5 ( L_57 , V_159 , V_154 , ( unsigned int ) * V_147 ) ;
V_6 = V_139 ;
V_161 = F_64 ( V_6 , V_152 ) ;
* V_148 = V_161 + ( V_157 % V_160 ) * V_152 ;
* V_149 = F_65 ( V_89 , V_2 , V_152 - V_161 ) ;
F_5 ( L_58 , * V_148 , * V_149 ) ;
return 0 ;
V_162:
F_5 ( L_59 ) ;
* V_147 = 0 ;
* V_148 = 0 ;
* V_149 = 0 ;
return - V_22 ;
}
int F_66 ( struct V_78 * V_88 ,
const char * V_164 ,
struct V_145 * V_165 ,
struct V_97 * V_166 )
{
unsigned int V_106 , V_167 ;
struct V_8 * V_80 ;
F_18 ( ! V_166 ) ;
V_88 -> V_80 = F_63 ( V_165 -> V_168 ) ;
V_80 = F_34 ( & V_166 -> V_101 , V_88 -> V_80 ) ;
if ( ! V_80 )
return - V_169 ;
V_88 -> V_81 = F_67 ( V_80 -> V_109 , V_164 , strlen ( V_164 ) ) ;
V_106 = V_80 -> V_11 ;
V_167 = V_80 -> V_10 ;
F_5 ( L_60 , V_164 , V_88 -> V_80 , V_88 -> V_81 ) ;
return 0 ;
}
static int * F_68 ( struct V_97 * V_166 , struct V_78 V_90 ,
int * V_129 , int * V_106 )
{
struct V_82 * V_88 ;
struct V_8 * V_80 ;
int V_170 ;
int V_68 ;
V_19 V_171 ;
V_80 = F_34 ( & V_166 -> V_101 , V_90 . V_80 ) ;
if ( ! V_80 )
return NULL ;
V_90 . V_81 = F_69 ( V_90 . V_81 , V_80 -> V_11 ,
V_80 -> V_12 ) ;
V_88 = F_29 ( & V_166 -> V_112 , V_90 ) ;
if ( V_88 ) {
* V_106 = V_88 -> V_2 ;
return V_88 -> V_129 ;
}
V_170 = F_70 ( V_166 -> V_111 , V_80 -> V_108 ,
V_80 -> type , V_80 -> V_18 ) ;
if ( V_170 < 0 ) {
F_17 ( L_61 ,
V_90 . V_80 , V_80 -> V_108 , V_80 -> type ,
V_80 -> V_18 ) ;
return NULL ;
}
if ( V_80 -> V_110 & V_172 ) {
V_171 = F_71 ( V_173 ,
F_69 ( V_90 . V_81 , V_80 -> V_13 ,
V_80 -> V_12 ) ,
V_90 . V_80 ) ;
} else {
V_171 = F_69 ( V_90 . V_81 , V_80 -> V_13 ,
V_80 -> V_12 ) +
( unsigned ) V_90 . V_80 ;
}
V_68 = F_72 ( V_166 -> V_111 , V_170 , V_171 , V_129 ,
F_65 ( int , V_80 -> V_18 , * V_106 ) ,
V_166 -> V_114 ) ;
if ( V_68 < 0 ) {
F_17 ( L_62
L_63 , V_68 , V_90 . V_80 , V_80 -> V_108 ,
V_80 -> type , V_80 -> V_18 ) ;
return NULL ;
}
* V_106 = V_68 ;
return V_129 ;
}
int F_73 ( struct V_97 * V_166 , struct V_78 V_90 ,
int * V_174 )
{
int V_175 [ V_176 ] , * V_129 ;
int V_38 , V_177 , V_106 = V_176 ;
V_129 = F_68 ( V_166 , V_90 , V_175 , & V_106 ) ;
if ( ! V_129 )
return - 1 ;
V_177 = 0 ;
for ( V_38 = 0 ; V_38 < V_106 ; V_38 ++ )
if ( F_74 ( V_166 , V_129 [ V_38 ] ) )
V_174 [ V_177 ++ ] = V_129 [ V_38 ] ;
return V_177 ;
}
int F_75 ( struct V_97 * V_166 , struct V_78 V_90 )
{
int V_175 [ V_176 ] , * V_129 ;
int V_38 , V_106 = V_176 ;
V_129 = F_68 ( V_166 , V_90 , V_175 , & V_106 ) ;
if ( ! V_129 )
return - 1 ;
for ( V_38 = 0 ; V_38 < V_106 ; V_38 ++ )
if ( F_74 ( V_166 , V_129 [ V_38 ] ) )
return V_129 [ V_38 ] ;
return - 1 ;
}
