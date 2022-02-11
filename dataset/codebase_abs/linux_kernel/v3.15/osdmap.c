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
F_6 ( V_14 , V_15 , sizeof( V_78 ) , V_77 ) ;
V_36 -> V_79 = F_20 ( V_14 ) ;
F_5 ( L_21 ,
V_36 -> V_79 ) ;
V_77:
F_5 ( L_22 ) ;
return V_36 ;
V_51:
V_37 = - V_27 ;
V_20:
F_5 ( L_23 , V_37 ) ;
F_23 ( V_36 ) ;
return F_16 ( V_37 ) ;
}
static int F_24 ( struct V_80 V_81 , struct V_80 V_68 )
{
if ( V_81 . V_82 < V_68 . V_82 )
return - 1 ;
if ( V_81 . V_82 > V_68 . V_82 )
return 1 ;
if ( V_81 . V_83 < V_68 . V_83 )
return - 1 ;
if ( V_81 . V_83 > V_68 . V_83 )
return 1 ;
return 0 ;
}
static int F_25 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_88 * * V_14 = & V_87 -> V_88 ;
struct V_88 * V_89 = NULL ;
struct V_84 * V_90 = NULL ;
int V_36 ;
F_5 ( L_24 , * ( V_91 * ) & V_85 -> V_92 , V_85 ) ;
while ( * V_14 ) {
V_89 = * V_14 ;
V_90 = F_26 ( V_89 , struct V_84 , V_93 ) ;
V_36 = F_24 ( V_85 -> V_92 , V_90 -> V_92 ) ;
if ( V_36 < 0 )
V_14 = & ( * V_14 ) -> V_94 ;
else if ( V_36 > 0 )
V_14 = & ( * V_14 ) -> V_95 ;
else
return - V_96 ;
}
F_27 ( & V_85 -> V_93 , V_89 , V_14 ) ;
F_28 ( & V_85 -> V_93 , V_87 ) ;
return 0 ;
}
static struct V_84 * F_29 ( struct V_86 * V_87 ,
struct V_80 V_92 )
{
struct V_88 * V_97 = V_87 -> V_88 ;
struct V_84 * V_90 ;
int V_36 ;
while ( V_97 ) {
V_90 = F_26 ( V_97 , struct V_84 , V_93 ) ;
V_36 = F_24 ( V_92 , V_90 -> V_92 ) ;
if ( V_36 < 0 ) {
V_97 = V_97 -> V_94 ;
} else if ( V_36 > 0 ) {
V_97 = V_97 -> V_95 ;
} else {
F_5 ( L_25 ,
V_92 . V_82 , V_92 . V_83 , V_90 ) ;
return V_90 ;
}
}
return NULL ;
}
static int F_30 ( struct V_86 * V_87 , struct V_80 V_92 )
{
struct V_84 * V_90 = F_29 ( V_87 , V_92 ) ;
if ( V_90 ) {
F_5 ( L_26 , V_92 . V_82 , V_92 . V_83 ,
V_90 ) ;
F_31 ( & V_90 -> V_93 , V_87 ) ;
F_32 ( V_90 ) ;
return 0 ;
}
F_5 ( L_27 , V_92 . V_82 , V_92 . V_83 ) ;
return - V_98 ;
}
static int F_33 ( struct V_86 * V_87 , struct V_8 * V_85 )
{
struct V_88 * * V_14 = & V_87 -> V_88 ;
struct V_88 * V_89 = NULL ;
struct V_8 * V_9 = NULL ;
while ( * V_14 ) {
V_89 = * V_14 ;
V_9 = F_26 ( V_89 , struct V_8 , V_93 ) ;
if ( V_85 -> V_59 < V_9 -> V_59 )
V_14 = & ( * V_14 ) -> V_94 ;
else if ( V_85 -> V_59 > V_9 -> V_59 )
V_14 = & ( * V_14 ) -> V_95 ;
else
return - V_96 ;
}
F_27 ( & V_85 -> V_93 , V_89 , V_14 ) ;
F_28 ( & V_85 -> V_93 , V_87 ) ;
return 0 ;
}
static struct V_8 * F_34 ( struct V_86 * V_87 , V_91 V_59 )
{
struct V_8 * V_9 ;
struct V_88 * V_97 = V_87 -> V_88 ;
while ( V_97 ) {
V_9 = F_26 ( V_97 , struct V_8 , V_93 ) ;
if ( V_59 < V_9 -> V_59 )
V_97 = V_97 -> V_94 ;
else if ( V_59 > V_9 -> V_59 )
V_97 = V_97 -> V_95 ;
else
return V_9 ;
}
return NULL ;
}
struct V_8 * F_35 ( struct V_99 * V_100 , V_91 V_59 )
{
return F_34 ( & V_100 -> V_101 , V_59 ) ;
}
const char * F_36 ( struct V_99 * V_100 , V_91 V_59 )
{
struct V_8 * V_9 ;
if ( V_59 == V_102 )
return NULL ;
if ( F_37 ( V_59 > ( V_91 ) V_103 ) )
return NULL ;
V_9 = F_34 ( & V_100 -> V_101 , ( int ) V_59 ) ;
return V_9 ? V_9 -> V_104 : NULL ;
}
int F_38 ( struct V_99 * V_100 , const char * V_104 )
{
struct V_88 * V_105 ;
for ( V_105 = F_39 ( & V_100 -> V_101 ) ; V_105 ; V_105 = F_40 ( V_105 ) ) {
struct V_8 * V_9 =
F_26 ( V_105 , struct V_8 , V_93 ) ;
if ( V_9 -> V_104 && strcmp ( V_9 -> V_104 , V_104 ) == 0 )
return V_9 -> V_59 ;
}
return - V_98 ;
}
static void F_41 ( struct V_86 * V_87 , struct V_8 * V_9 )
{
F_31 ( & V_9 -> V_93 , V_87 ) ;
F_32 ( V_9 -> V_104 ) ;
F_32 ( V_9 ) ;
}
static int F_42 ( void * * V_14 , void * V_15 , struct V_8 * V_9 )
{
V_78 V_106 , V_107 ;
unsigned V_2 , V_108 ;
void * V_109 ;
F_6 ( V_14 , V_15 , 2 + 4 , V_20 ) ;
V_106 = F_20 ( V_14 ) ;
V_107 = F_20 ( V_14 ) ;
if ( V_106 < 5 ) {
F_43 ( L_28 , V_106 , V_107 ) ;
return - V_22 ;
}
if ( V_107 > 9 ) {
F_43 ( L_29 , V_106 , V_107 ) ;
return - V_22 ;
}
V_2 = F_7 ( V_14 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_109 = * V_14 + V_2 ;
V_9 -> type = F_20 ( V_14 ) ;
V_9 -> V_18 = F_20 ( V_14 ) ;
V_9 -> V_110 = F_20 ( V_14 ) ;
V_9 -> V_111 = F_20 ( V_14 ) ;
V_9 -> V_11 = F_7 ( V_14 ) ;
V_9 -> V_13 = F_7 ( V_14 ) ;
* V_14 += 4 + 4 ;
* V_14 += 4 ;
* V_14 += 8 + 4 ;
V_108 = F_7 ( V_14 ) ;
while ( V_108 -- ) {
* V_14 += 8 ;
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
V_108 = F_7 ( V_14 ) ;
* V_14 += V_108 * ( 8 + 8 ) ;
* V_14 += 8 ;
V_9 -> V_112 = F_44 ( V_14 ) ;
* V_14 += 4 ;
if ( V_106 >= 7 )
* V_14 += 1 ;
if ( V_106 >= 8 )
* V_14 += 8 + 8 ;
if ( V_106 >= 9 ) {
V_108 = F_7 ( V_14 ) ;
* V_14 += V_108 * 8 ;
* V_14 += 8 ;
* V_14 += 1 ;
V_9 -> V_113 = F_44 ( V_14 ) ;
V_9 -> V_114 = F_44 ( V_14 ) ;
} else {
V_9 -> V_113 = - 1 ;
V_9 -> V_114 = - 1 ;
}
* V_14 = V_109 ;
F_3 ( V_9 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_45 ( void * * V_14 , void * V_15 , struct V_99 * V_100 )
{
struct V_8 * V_9 ;
V_19 V_108 , V_2 ;
V_91 V_82 ;
F_11 ( V_14 , V_15 , V_108 , V_20 ) ;
F_5 ( L_30 , V_108 ) ;
while ( V_108 -- ) {
F_46 ( V_14 , V_15 , V_82 , V_20 ) ;
F_11 ( V_14 , V_15 , V_2 , V_20 ) ;
F_5 ( L_31 , V_82 , V_2 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_9 = F_34 ( & V_100 -> V_101 , V_82 ) ;
if ( V_9 ) {
char * V_104 = F_47 ( * V_14 , V_2 , V_26 ) ;
if ( ! V_104 )
return - V_27 ;
F_32 ( V_9 -> V_104 ) ;
V_9 -> V_104 = V_104 ;
F_5 ( L_32 , V_9 -> V_104 ) ;
}
* V_14 += V_2 ;
}
return 0 ;
V_20:
return - V_22 ;
}
void F_48 ( struct V_99 * V_100 )
{
F_5 ( L_33 , V_100 ) ;
if ( V_100 -> V_115 )
F_23 ( V_100 -> V_115 ) ;
while ( ! F_49 ( & V_100 -> V_116 ) ) {
struct V_84 * V_90 =
F_26 ( F_39 ( & V_100 -> V_116 ) ,
struct V_84 , V_93 ) ;
F_31 ( & V_90 -> V_93 , & V_100 -> V_116 ) ;
F_32 ( V_90 ) ;
}
while ( ! F_49 ( & V_100 -> V_117 ) ) {
struct V_84 * V_90 =
F_26 ( F_39 ( & V_100 -> V_117 ) ,
struct V_84 , V_93 ) ;
F_31 ( & V_90 -> V_93 , & V_100 -> V_117 ) ;
F_32 ( V_90 ) ;
}
while ( ! F_49 ( & V_100 -> V_101 ) ) {
struct V_8 * V_9 =
F_26 ( F_39 ( & V_100 -> V_101 ) ,
struct V_8 , V_93 ) ;
F_41 ( & V_100 -> V_101 , V_9 ) ;
}
F_32 ( V_100 -> V_118 ) ;
F_32 ( V_100 -> V_119 ) ;
F_32 ( V_100 -> V_120 ) ;
F_32 ( V_100 -> V_121 ) ;
F_32 ( V_100 ) ;
}
static int F_50 ( struct V_99 * V_100 , int V_122 )
{
V_78 * V_3 ;
V_19 * V_61 ;
struct V_123 * V_124 ;
int V_38 ;
V_3 = F_51 ( V_100 -> V_118 , V_122 * sizeof( * V_3 ) , V_26 ) ;
V_61 = F_51 ( V_100 -> V_119 , V_122 * sizeof( * V_61 ) , V_26 ) ;
V_124 = F_51 ( V_100 -> V_120 , V_122 * sizeof( * V_124 ) , V_26 ) ;
if ( ! V_3 || ! V_61 || ! V_124 ) {
F_32 ( V_3 ) ;
F_32 ( V_61 ) ;
F_32 ( V_124 ) ;
return - V_27 ;
}
for ( V_38 = V_100 -> V_125 ; V_38 < V_122 ; V_38 ++ ) {
V_3 [ V_38 ] = 0 ;
V_61 [ V_38 ] = V_126 ;
memset ( V_124 + V_38 , 0 , sizeof( * V_124 ) ) ;
}
V_100 -> V_118 = V_3 ;
V_100 -> V_119 = V_61 ;
V_100 -> V_120 = V_124 ;
if ( V_100 -> V_121 ) {
V_19 * V_127 ;
V_127 = F_51 ( V_100 -> V_121 ,
V_122 * sizeof( * V_127 ) , V_26 ) ;
if ( ! V_127 )
return - V_27 ;
for ( V_38 = V_100 -> V_125 ; V_38 < V_122 ; V_38 ++ )
V_127 [ V_38 ] = V_128 ;
V_100 -> V_121 = V_127 ;
}
V_100 -> V_125 = V_122 ;
return 0 ;
}
static int F_52 ( void * * V_14 , void * V_15 ,
const char * V_129 , V_78 * V_130 )
{
V_78 V_131 ;
F_53 ( V_14 , V_15 , V_131 , V_132 ) ;
if ( V_131 >= 7 ) {
V_78 V_133 ;
F_53 ( V_14 , V_15 , V_133 , V_132 ) ;
if ( V_133 > V_134 ) {
F_43 ( L_34 ,
V_131 , V_133 ,
V_134 , V_129 ) ;
return - V_22 ;
}
* V_14 += 4 ;
F_53 ( V_14 , V_15 , V_131 , V_132 ) ;
F_53 ( V_14 , V_15 , V_133 , V_132 ) ;
if ( V_133 > V_135 ) {
F_43 ( L_35 ,
V_131 , V_133 ,
V_135 , V_129 ) ;
return - V_22 ;
}
* V_14 += 4 ;
} else {
T_1 V_136 ;
* V_14 -= 1 ;
F_54 ( V_14 , V_15 , V_136 , V_132 ) ;
if ( V_136 < 6 ) {
F_43 ( L_36 , V_136 ,
V_129 ) ;
return - V_22 ;
}
V_131 = 0 ;
}
* V_130 = V_131 ;
return 0 ;
V_132:
return - V_22 ;
}
static int F_55 ( void * * V_14 , void * V_15 , struct V_99 * V_100 ,
bool V_137 )
{
V_19 V_97 ;
F_11 ( V_14 , V_15 , V_97 , V_132 ) ;
while ( V_97 -- ) {
struct V_8 * V_9 ;
V_91 V_82 ;
int V_138 ;
F_46 ( V_14 , V_15 , V_82 , V_132 ) ;
V_9 = F_34 ( & V_100 -> V_101 , V_82 ) ;
if ( ! V_137 || ! V_9 ) {
V_9 = F_15 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
V_9 -> V_59 = V_82 ;
V_138 = F_33 ( & V_100 -> V_101 , V_9 ) ;
if ( V_138 ) {
F_32 ( V_9 ) ;
return V_138 ;
}
}
V_138 = F_42 ( V_14 , V_15 , V_9 ) ;
if ( V_138 )
return V_138 ;
}
return 0 ;
V_132:
return - V_22 ;
}
static int F_56 ( void * * V_14 , void * V_15 , struct V_99 * V_100 )
{
return F_55 ( V_14 , V_15 , V_100 , false ) ;
}
static int F_57 ( void * * V_14 , void * V_15 , struct V_99 * V_100 )
{
return F_55 ( V_14 , V_15 , V_100 , true ) ;
}
static int F_58 ( void * * V_14 , void * V_15 , struct V_99 * V_100 ,
bool V_137 )
{
V_19 V_97 ;
F_11 ( V_14 , V_15 , V_97 , V_132 ) ;
while ( V_97 -- ) {
struct V_80 V_92 ;
V_19 V_2 , V_38 ;
int V_138 ;
V_138 = F_59 ( V_14 , V_15 , & V_92 ) ;
if ( V_138 )
return V_138 ;
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
V_138 = F_30 ( & V_100 -> V_116 , V_92 ) ;
F_18 ( ! V_137 && V_138 != - V_98 ) ;
if ( ! V_137 || V_2 > 0 ) {
struct V_84 * V_90 ;
F_6 ( V_14 , V_15 , V_2 * sizeof( V_19 ) , V_132 ) ;
if ( V_2 > ( V_139 - sizeof( * V_90 ) ) / sizeof( V_19 ) )
return - V_22 ;
V_90 = F_15 ( sizeof( * V_90 ) + V_2 * sizeof( V_19 ) , V_26 ) ;
if ( ! V_90 )
return - V_27 ;
V_90 -> V_92 = V_92 ;
V_90 -> V_116 . V_2 = V_2 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
V_90 -> V_116 . V_140 [ V_38 ] = F_7 ( V_14 ) ;
V_138 = F_25 ( V_90 , & V_100 -> V_116 ) ;
if ( V_138 ) {
F_32 ( V_90 ) ;
return V_138 ;
}
}
}
return 0 ;
V_132:
return - V_22 ;
}
static int F_60 ( void * * V_14 , void * V_15 , struct V_99 * V_100 )
{
return F_58 ( V_14 , V_15 , V_100 , false ) ;
}
static int F_61 ( void * * V_14 , void * V_15 , struct V_99 * V_100 )
{
return F_58 ( V_14 , V_15 , V_100 , true ) ;
}
static int F_62 ( void * * V_14 , void * V_15 , struct V_99 * V_100 ,
bool V_137 )
{
V_19 V_97 ;
F_11 ( V_14 , V_15 , V_97 , V_132 ) ;
while ( V_97 -- ) {
struct V_80 V_92 ;
V_19 V_141 ;
int V_138 ;
V_138 = F_59 ( V_14 , V_15 , & V_92 ) ;
if ( V_138 )
return V_138 ;
F_11 ( V_14 , V_15 , V_141 , V_132 ) ;
V_138 = F_30 ( & V_100 -> V_117 , V_92 ) ;
F_18 ( ! V_137 && V_138 != - V_98 ) ;
if ( ! V_137 || V_141 != ( V_19 ) - 1 ) {
struct V_84 * V_90 ;
V_90 = F_15 ( sizeof( * V_90 ) , V_26 ) ;
if ( ! V_90 )
return - V_27 ;
V_90 -> V_92 = V_92 ;
V_90 -> V_117 . V_141 = V_141 ;
V_138 = F_25 ( V_90 , & V_100 -> V_117 ) ;
if ( V_138 ) {
F_32 ( V_90 ) ;
return V_138 ;
}
}
}
return 0 ;
V_132:
return - V_22 ;
}
static int F_63 ( void * * V_14 , void * V_15 , struct V_99 * V_100 )
{
return F_62 ( V_14 , V_15 , V_100 , false ) ;
}
static int F_64 ( void * * V_14 , void * V_15 ,
struct V_99 * V_100 )
{
return F_62 ( V_14 , V_15 , V_100 , true ) ;
}
V_19 F_65 ( struct V_99 * V_100 , int V_141 )
{
F_18 ( V_141 >= V_100 -> V_125 ) ;
if ( ! V_100 -> V_121 )
return V_128 ;
return V_100 -> V_121 [ V_141 ] ;
}
static int F_66 ( struct V_99 * V_100 , int V_141 , V_19 V_142 )
{
F_18 ( V_141 >= V_100 -> V_125 ) ;
if ( ! V_100 -> V_121 ) {
int V_38 ;
V_100 -> V_121 = F_21 ( V_100 -> V_125 * sizeof( V_19 ) ,
V_26 ) ;
if ( ! V_100 -> V_121 )
return - V_27 ;
for ( V_38 = 0 ; V_38 < V_100 -> V_125 ; V_38 ++ )
V_100 -> V_121 [ V_38 ] =
V_128 ;
}
V_100 -> V_121 [ V_141 ] = V_142 ;
return 0 ;
}
static int F_67 ( void * * V_14 , void * V_15 ,
struct V_99 * V_100 )
{
V_19 V_2 , V_38 ;
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
if ( V_2 == 0 ) {
F_32 ( V_100 -> V_121 ) ;
V_100 -> V_121 = NULL ;
return 0 ;
}
if ( V_2 != V_100 -> V_125 )
goto V_132;
F_6 ( V_14 , V_15 , V_100 -> V_125 * sizeof( V_19 ) , V_132 ) ;
for ( V_38 = 0 ; V_38 < V_100 -> V_125 ; V_38 ++ ) {
int V_138 ;
V_138 = F_66 ( V_100 , V_38 , F_7 ( V_14 ) ) ;
if ( V_138 )
return V_138 ;
}
return 0 ;
V_132:
return - V_22 ;
}
static int F_68 ( void * * V_14 , void * V_15 ,
struct V_99 * V_100 )
{
V_19 V_97 ;
F_11 ( V_14 , V_15 , V_97 , V_132 ) ;
while ( V_97 -- ) {
V_19 V_141 , V_142 ;
int V_138 ;
F_11 ( V_14 , V_15 , V_141 , V_132 ) ;
F_11 ( V_14 , V_15 , V_142 , V_132 ) ;
V_138 = F_66 ( V_100 , V_141 , V_142 ) ;
if ( V_138 )
return V_138 ;
F_69 ( L_37 , V_141 , V_142 ) ;
}
return 0 ;
V_132:
return - V_22 ;
}
static int F_70 ( void * * V_14 , void * V_15 , struct V_99 * V_100 )
{
V_78 V_131 ;
V_19 V_143 = 0 ;
void * V_39 = * V_14 ;
V_19 V_122 ;
V_19 V_2 , V_38 ;
int V_37 ;
F_5 ( L_38 , V_144 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_37 = F_52 ( V_14 , V_15 , L_39 , & V_131 ) ;
if ( V_37 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_100 -> V_145 ) + sizeof( V_19 ) +
sizeof( V_100 -> V_146 ) + sizeof( V_100 -> V_147 ) , V_132 ) ;
F_71 ( V_14 , & V_100 -> V_145 , sizeof( V_100 -> V_145 ) ) ;
V_143 = V_100 -> V_143 = F_7 ( V_14 ) ;
F_71 ( V_14 , & V_100 -> V_146 , sizeof( V_100 -> V_146 ) ) ;
F_71 ( V_14 , & V_100 -> V_147 , sizeof( V_100 -> V_147 ) ) ;
V_37 = F_56 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
V_37 = F_45 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
F_11 ( V_14 , V_15 , V_100 -> V_148 , V_132 ) ;
F_11 ( V_14 , V_15 , V_100 -> V_112 , V_132 ) ;
F_11 ( V_14 , V_15 , V_122 , V_132 ) ;
V_37 = F_50 ( V_100 , V_122 ) ;
if ( V_37 )
goto V_20;
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) +
V_100 -> V_125 * ( 1 + sizeof( * V_100 -> V_119 ) +
sizeof( * V_100 -> V_120 ) ) , V_132 ) ;
if ( F_7 ( V_14 ) != V_100 -> V_125 )
goto V_132;
F_71 ( V_14 , V_100 -> V_118 , V_100 -> V_125 ) ;
if ( F_7 ( V_14 ) != V_100 -> V_125 )
goto V_132;
for ( V_38 = 0 ; V_38 < V_100 -> V_125 ; V_38 ++ )
V_100 -> V_119 [ V_38 ] = F_7 ( V_14 ) ;
if ( F_7 ( V_14 ) != V_100 -> V_125 )
goto V_132;
F_71 ( V_14 , V_100 -> V_120 , V_100 -> V_125 * sizeof( * V_100 -> V_120 ) ) ;
for ( V_38 = 0 ; V_38 < V_100 -> V_125 ; V_38 ++ )
F_72 ( & V_100 -> V_120 [ V_38 ] ) ;
V_37 = F_60 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
if ( V_131 >= 1 ) {
V_37 = F_63 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
}
if ( V_131 >= 2 ) {
V_37 = F_67 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
} else {
F_32 ( V_100 -> V_121 ) ;
V_100 -> V_121 = NULL ;
}
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
V_100 -> V_115 = F_14 ( * V_14 , F_73 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_74 ( V_100 -> V_115 ) ) {
V_37 = F_75 ( V_100 -> V_115 ) ;
V_100 -> V_115 = NULL ;
goto V_20;
}
* V_14 += V_2 ;
* V_14 = V_15 ;
F_5 ( L_40 , V_100 -> V_143 , V_100 -> V_125 ) ;
return 0 ;
V_132:
V_37 = - V_22 ;
V_20:
F_17 ( L_41 ,
V_37 , V_143 , ( int ) ( * V_14 - V_39 ) , * V_14 , V_39 , V_15 ) ;
F_76 ( V_149 , L_42 ,
V_150 , 16 , 1 ,
V_39 , V_15 - V_39 , true ) ;
return V_37 ;
}
struct V_99 * F_77 ( void * * V_14 , void * V_15 )
{
struct V_99 * V_100 ;
int V_138 ;
V_100 = F_15 ( sizeof( * V_100 ) , V_26 ) ;
if ( ! V_100 )
return F_16 ( - V_27 ) ;
V_100 -> V_116 = V_151 ;
V_100 -> V_117 = V_151 ;
F_78 ( & V_100 -> V_152 ) ;
V_138 = F_70 ( V_14 , V_15 , V_100 ) ;
if ( V_138 ) {
F_48 ( V_100 ) ;
return F_16 ( V_138 ) ;
}
return V_100 ;
}
struct V_99 * F_79 ( void * * V_14 , void * V_15 ,
struct V_99 * V_100 ,
struct V_153 * V_154 )
{
struct V_34 * V_155 = NULL ;
struct V_156 V_145 ;
V_19 V_143 = 0 ;
struct V_157 V_147 ;
T_2 V_2 ;
V_91 V_82 ;
T_3 V_158 ;
V_63 V_159 , V_122 ;
void * V_39 = * V_14 ;
int V_37 ;
V_78 V_131 ;
F_5 ( L_38 , V_144 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_37 = F_52 ( V_14 , V_15 , L_43 , & V_131 ) ;
if ( V_37 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_145 ) + sizeof( V_19 ) + sizeof( V_147 ) +
sizeof( V_91 ) + sizeof( V_19 ) , V_132 ) ;
F_71 ( V_14 , & V_145 , sizeof( V_145 ) ) ;
V_143 = F_7 ( V_14 ) ;
F_18 ( V_143 != V_100 -> V_143 + 1 ) ;
F_71 ( V_14 , & V_147 , sizeof( V_147 ) ) ;
V_158 = F_44 ( V_14 ) ;
V_159 = F_7 ( V_14 ) ;
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
if ( V_2 > 0 ) {
F_5 ( L_44 ,
V_2 , * V_14 , V_15 ) ;
return F_77 ( V_14 , F_73 ( * V_14 + V_2 , V_15 ) ) ;
}
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
if ( V_2 > 0 ) {
V_155 = F_14 ( * V_14 , F_73 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_74 ( V_155 ) ) {
V_37 = F_75 ( V_155 ) ;
V_155 = NULL ;
goto V_20;
}
* V_14 += V_2 ;
}
if ( V_159 >= 0 )
V_100 -> V_112 = V_159 ;
if ( V_158 >= 0 )
V_100 -> V_148 = V_158 ;
F_11 ( V_14 , V_15 , V_122 , V_132 ) ;
if ( V_122 >= 0 ) {
V_37 = F_50 ( V_100 , V_122 ) ;
if ( V_37 )
goto V_20;
}
V_100 -> V_143 ++ ;
V_100 -> V_147 = V_147 ;
if ( V_155 ) {
if ( V_100 -> V_115 )
F_23 ( V_100 -> V_115 ) ;
V_100 -> V_115 = V_155 ;
V_155 = NULL ;
}
V_37 = F_57 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
V_37 = F_45 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
while ( V_2 -- ) {
struct V_8 * V_9 ;
F_46 ( V_14 , V_15 , V_82 , V_132 ) ;
V_9 = F_34 ( & V_100 -> V_101 , V_82 ) ;
if ( V_9 )
F_41 ( & V_100 -> V_101 , V_9 ) ;
}
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
while ( V_2 -- ) {
V_19 V_141 ;
struct V_123 V_124 ;
F_11 ( V_14 , V_15 , V_141 , V_132 ) ;
F_22 ( V_14 , V_15 , & V_124 , sizeof( V_124 ) , V_132 ) ;
F_72 ( & V_124 ) ;
F_69 ( L_45 , V_141 ) ;
F_18 ( V_141 >= V_100 -> V_125 ) ;
V_100 -> V_118 [ V_141 ] |= V_5 ;
V_100 -> V_120 [ V_141 ] = V_124 ;
}
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
while ( V_2 -- ) {
V_19 V_141 ;
V_78 V_160 ;
F_11 ( V_14 , V_15 , V_141 , V_132 ) ;
V_160 = * * ( V_78 * * ) V_14 ;
( * V_14 ) ++ ;
if ( V_160 == 0 )
V_160 = V_5 ;
if ( V_160 & V_5 )
F_69 ( L_46 , V_141 ) ;
if ( V_141 < V_100 -> V_125 )
V_100 -> V_118 [ V_141 ] ^= V_160 ;
}
F_11 ( V_14 , V_15 , V_2 , V_132 ) ;
while ( V_2 -- ) {
V_19 V_141 , V_161 ;
F_6 ( V_14 , V_15 , sizeof( V_19 ) * 2 , V_132 ) ;
V_141 = F_7 ( V_14 ) ;
V_161 = F_7 ( V_14 ) ;
F_69 ( L_47 , V_141 , V_161 ,
V_161 == V_162 ? L_48 :
( V_161 == V_126 ? L_49 : L_50 ) ) ;
if ( V_141 < V_100 -> V_125 )
V_100 -> V_119 [ V_141 ] = V_161 ;
}
V_37 = F_61 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
if ( V_131 >= 1 ) {
V_37 = F_64 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
}
if ( V_131 >= 2 ) {
V_37 = F_68 ( V_14 , V_15 , V_100 ) ;
if ( V_37 )
goto V_20;
}
* V_14 = V_15 ;
F_5 ( L_51 , V_100 -> V_143 , V_100 -> V_125 ) ;
return V_100 ;
V_132:
V_37 = - V_22 ;
V_20:
F_17 ( L_52 ,
V_37 , V_143 , ( int ) ( * V_14 - V_39 ) , * V_14 , V_39 , V_15 ) ;
F_76 ( V_149 , L_42 ,
V_150 , 16 , 1 ,
V_39 , V_15 - V_39 , true ) ;
if ( V_155 )
F_23 ( V_155 ) ;
return F_16 ( V_37 ) ;
}
int F_80 ( struct V_163 * V_164 ,
V_91 V_161 , V_91 V_2 ,
V_91 * V_165 ,
V_91 * V_166 , V_91 * V_167 )
{
V_19 V_168 = F_81 ( V_164 -> V_169 ) ;
V_19 V_170 = F_81 ( V_164 -> V_171 ) ;
V_19 V_172 = F_81 ( V_164 -> V_173 ) ;
V_19 V_174 , V_175 , V_176 , V_177 ;
V_19 V_178 ;
V_91 V_6 , V_179 ;
F_5 ( L_53 , V_161 , V_2 ,
V_168 , V_170 ) ;
if ( V_170 == 0 || V_172 == 0 )
goto V_180;
V_178 = V_168 / V_170 ;
if ( V_178 == 0 )
goto V_180;
F_5 ( L_54 , V_168 , V_170 ,
V_178 ) ;
if ( ( V_170 & ~ V_181 ) != 0 )
goto V_180;
V_6 = V_161 ;
F_82 ( V_6 , V_170 ) ;
V_174 = V_6 ;
F_5 ( L_55 , V_161 , V_170 , V_174 ) ;
V_175 = V_174 / V_172 ;
V_176 = V_174 % V_172 ;
V_177 = V_175 / V_178 ;
* V_165 = V_177 * V_172 + V_176 ;
F_5 ( L_56 , V_177 , V_172 , ( unsigned int ) * V_165 ) ;
V_6 = V_161 ;
V_179 = F_82 ( V_6 , V_170 ) ;
* V_166 = V_179 + ( V_175 % V_178 ) * V_170 ;
* V_167 = F_83 ( V_91 , V_2 , V_170 - V_179 ) ;
F_5 ( L_57 , * V_166 , * V_167 ) ;
return 0 ;
V_180:
F_5 ( L_58 ) ;
* V_165 = 0 ;
* V_166 = 0 ;
* V_167 = 0 ;
return - V_22 ;
}
int F_84 ( struct V_99 * V_182 ,
struct V_183 * V_184 ,
struct V_185 * V_186 ,
struct V_80 * V_187 )
{
struct V_8 * V_9 ;
V_9 = F_34 ( & V_182 -> V_101 , V_184 -> V_82 ) ;
if ( ! V_9 )
return - V_188 ;
V_187 -> V_82 = V_184 -> V_82 ;
V_187 -> V_83 = F_85 ( V_9 -> V_111 , V_186 -> V_104 ,
V_186 -> V_189 ) ;
F_5 ( L_59 , V_144 , V_186 -> V_189 , V_186 -> V_104 ,
V_187 -> V_82 , V_187 -> V_83 ) ;
return 0 ;
}
static int F_86 ( struct V_99 * V_100 , int V_190 , int V_191 ,
int * V_192 , int V_193 ,
const T_4 * V_61 , int V_194 )
{
int V_68 ;
F_18 ( V_193 > V_195 ) ;
F_87 ( & V_100 -> V_152 ) ;
V_68 = F_88 ( V_100 -> V_115 , V_190 , V_191 , V_192 , V_193 ,
V_61 , V_194 , V_100 -> V_196 ) ;
F_89 ( & V_100 -> V_152 ) ;
return V_68 ;
}
static int F_90 ( struct V_99 * V_182 ,
struct V_8 * V_82 ,
struct V_80 V_92 , V_19 V_197 , int * V_140 )
{
int V_190 ;
int V_2 ;
V_190 = F_91 ( V_182 -> V_115 , V_82 -> V_110 ,
V_82 -> type , V_82 -> V_18 ) ;
if ( V_190 < 0 ) {
F_17 ( L_60 ,
V_92 . V_82 , V_82 -> V_110 , V_82 -> type ,
V_82 -> V_18 ) ;
return - V_98 ;
}
V_2 = F_86 ( V_182 , V_190 , V_197 , V_140 ,
F_83 ( int , V_82 -> V_18 , V_195 ) ,
V_182 -> V_119 , V_182 -> V_125 ) ;
if ( V_2 < 0 ) {
F_17 ( L_61 ,
V_2 , V_190 , V_92 . V_82 , V_82 -> V_110 ,
V_82 -> type , V_82 -> V_18 ) ;
return V_2 ;
}
return V_2 ;
}
static int F_92 ( struct V_99 * V_182 ,
struct V_8 * V_82 ,
int * V_140 , int V_2 , int * V_198 )
{
int V_199 = - 1 ;
int V_38 ;
if ( F_93 ( V_82 ) ) {
int V_200 = 0 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
if ( F_94 ( V_182 , V_140 [ V_38 ] ) ) {
V_200 ++ ;
continue;
}
if ( V_200 )
V_140 [ V_38 - V_200 ] = V_140 [ V_38 ] ;
}
V_2 -= V_200 ;
if ( V_2 > 0 )
V_199 = V_140 [ 0 ] ;
} else {
for ( V_38 = V_2 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( F_94 ( V_182 , V_140 [ V_38 ] ) )
V_140 [ V_38 ] = V_201 ;
else
V_199 = V_140 [ V_38 ] ;
}
}
* V_198 = V_199 ;
return V_2 ;
}
static void F_95 ( struct V_99 * V_182 , V_19 V_197 ,
struct V_8 * V_82 ,
int * V_140 , int V_2 , int * V_198 )
{
int V_38 ;
int V_202 = - 1 ;
if ( ! V_182 -> V_121 )
return;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
int V_141 = V_140 [ V_38 ] ;
if ( V_141 != V_201 &&
V_182 -> V_121 [ V_141 ] !=
V_128 ) {
break;
}
}
if ( V_38 == V_2 )
return;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
int V_141 = V_140 [ V_38 ] ;
V_19 V_142 ;
if ( V_141 == V_201 )
continue;
V_142 = V_182 -> V_121 [ V_141 ] ;
if ( V_142 < V_203 &&
( F_96 ( V_204 ,
V_197 , V_141 ) >> 16 ) >= V_142 ) {
if ( V_202 < 0 )
V_202 = V_38 ;
} else {
V_202 = V_38 ;
break;
}
}
if ( V_202 < 0 )
return;
* V_198 = V_140 [ V_202 ] ;
if ( F_93 ( V_82 ) && V_202 > 0 ) {
for ( V_38 = V_202 ; V_38 > 0 ; V_38 -- )
V_140 [ V_38 ] = V_140 [ V_38 - 1 ] ;
V_140 [ 0 ] = * V_198 ;
}
}
static int F_97 ( struct V_99 * V_182 ,
struct V_8 * V_82 , struct V_80 V_92 ,
int * V_140 , int V_2 , int * V_198 )
{
struct V_84 * V_90 ;
int V_205 ;
int V_206 ;
int V_38 ;
V_92 . V_83 = F_98 ( V_92 . V_83 , V_82 -> V_11 ,
V_82 -> V_10 ) ;
V_90 = F_29 ( & V_182 -> V_116 , V_92 ) ;
if ( V_90 ) {
V_205 = 0 ;
V_206 = - 1 ;
for ( V_38 = 0 ; V_38 < V_90 -> V_116 . V_2 ; V_38 ++ ) {
if ( F_94 ( V_182 , V_90 -> V_116 . V_140 [ V_38 ] ) ) {
if ( F_93 ( V_82 ) )
continue;
else
V_140 [ V_205 ++ ] = V_201 ;
} else {
V_140 [ V_205 ++ ] = V_90 -> V_116 . V_140 [ V_38 ] ;
}
}
for ( V_38 = 0 ; V_38 < V_205 ; V_38 ++ ) {
if ( V_140 [ V_38 ] != V_201 ) {
V_206 = V_140 [ V_38 ] ;
break;
}
}
} else {
V_205 = V_2 ;
V_206 = * V_198 ;
}
V_90 = F_29 ( & V_182 -> V_117 , V_92 ) ;
if ( V_90 )
V_206 = V_90 -> V_117 . V_141 ;
* V_198 = V_206 ;
return V_205 ;
}
int F_99 ( struct V_99 * V_182 , struct V_80 V_92 ,
int * V_140 , int * V_198 )
{
struct V_8 * V_82 ;
V_19 V_197 ;
int V_2 ;
V_82 = F_34 ( & V_182 -> V_101 , V_92 . V_82 ) ;
if ( ! V_82 ) {
* V_198 = - 1 ;
return - V_98 ;
}
if ( V_82 -> V_112 & V_207 ) {
V_197 = F_96 ( V_204 ,
F_98 ( V_92 . V_83 , V_82 -> V_13 ,
V_82 -> V_12 ) ,
V_92 . V_82 ) ;
} else {
V_197 = F_98 ( V_92 . V_83 , V_82 -> V_13 ,
V_82 -> V_12 ) +
( unsigned ) V_92 . V_82 ;
}
V_2 = F_90 ( V_182 , V_82 , V_92 , V_197 , V_140 ) ;
if ( V_2 < 0 ) {
* V_198 = - 1 ;
return V_2 ;
}
V_2 = F_92 ( V_182 , V_82 , V_140 , V_2 , V_198 ) ;
F_95 ( V_182 , V_197 , V_82 , V_140 , V_2 , V_198 ) ;
V_2 = F_97 ( V_182 , V_82 , V_92 , V_140 , V_2 , V_198 ) ;
return V_2 ;
}
int F_100 ( struct V_99 * V_182 , struct V_80 V_92 )
{
int V_140 [ V_195 ] ;
int V_198 ;
F_99 ( V_182 , V_92 , V_140 , & V_198 ) ;
return V_198 ;
}
