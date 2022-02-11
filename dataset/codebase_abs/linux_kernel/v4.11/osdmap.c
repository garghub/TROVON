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
static int F_13 ( void * * V_14 , void * V_15 ,
struct V_34 * V_7 )
{
int V_24 ;
F_5 ( L_9 , * V_14 , V_15 ) ;
V_7 -> V_25 = F_9 ( V_7 -> V_17 . V_18 , sizeof( V_19 ) , V_26 ) ;
if ( V_7 -> V_25 == NULL )
return - V_27 ;
F_6 ( V_14 , V_15 , V_7 -> V_17 . V_18 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_17 . V_18 ; V_24 ++ )
V_7 -> V_25 [ V_24 ] = F_7 ( V_14 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_14 ( void * * V_14 , void * V_15 )
{
int V_2 ;
F_15 ( V_14 , V_15 , V_2 , V_20 ) ;
while ( V_2 -- ) {
int strlen ;
* V_14 += sizeof( V_19 ) ;
F_15 ( V_14 , V_15 , strlen , V_20 ) ;
* V_14 += strlen ;
}
return 0 ;
V_20:
return - V_22 ;
}
static void F_16 ( struct V_35 * V_36 )
{
T_1 V_7 ;
V_36 -> V_37 = sizeof( struct V_38 ) +
V_36 -> V_39 * sizeof( struct V_40 * ) ;
for ( V_7 = 0 ; V_7 < V_36 -> V_39 ; V_7 ++ ) {
if ( ! V_36 -> V_41 [ V_7 ] )
continue;
switch ( V_36 -> V_41 [ V_7 ] -> V_42 ) {
default:
V_36 -> V_37 += sizeof( struct V_40 ) ;
break;
}
V_36 -> V_37 += V_36 -> V_41 [ V_7 ] -> V_18 * sizeof( V_43 ) ;
}
}
static struct V_35 * F_17 ( void * V_44 , void * V_15 )
{
struct V_35 * V_36 ;
int V_45 = - V_22 ;
int V_46 , V_24 ;
void * * V_14 = & V_44 ;
void * V_47 = V_44 ;
V_19 V_48 ;
V_19 V_49 ;
F_5 ( L_10 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_36 = F_18 ( sizeof( * V_36 ) , V_26 ) ;
if ( V_36 == NULL )
return F_19 ( - V_27 ) ;
V_36 -> V_50 = 2 ;
V_36 -> V_51 = 5 ;
V_36 -> V_52 = 19 ;
V_36 -> V_53 = 0 ;
F_6 ( V_14 , V_15 , 4 * sizeof( V_19 ) , V_20 ) ;
V_48 = F_7 ( V_14 ) ;
if ( V_48 != V_54 ) {
F_20 ( L_11 ,
( unsigned int ) V_48 , ( unsigned int ) V_54 ) ;
goto V_20;
}
V_36 -> V_39 = F_7 ( V_14 ) ;
V_36 -> V_55 = F_7 ( V_14 ) ;
V_36 -> V_56 = F_7 ( V_14 ) ;
V_36 -> V_41 = F_9 ( V_36 -> V_39 , sizeof( * V_36 -> V_41 ) , V_26 ) ;
if ( V_36 -> V_41 == NULL )
goto V_57;
V_36 -> V_58 = F_9 ( V_36 -> V_55 , sizeof( * V_36 -> V_58 ) , V_26 ) ;
if ( V_36 -> V_58 == NULL )
goto V_57;
for ( V_46 = 0 ; V_46 < V_36 -> V_39 ; V_46 ++ ) {
int V_18 = 0 ;
V_19 V_42 ;
struct V_59 * V_7 ;
F_15 ( V_14 , V_15 , V_42 , V_20 ) ;
if ( V_42 == 0 ) {
V_36 -> V_41 [ V_46 ] = NULL ;
continue;
}
F_5 ( L_12 ,
V_46 , ( int ) ( * V_14 - V_47 ) , * V_14 , V_15 ) ;
switch ( V_42 ) {
case V_60 :
V_18 = sizeof( struct V_16 ) ;
break;
case V_61 :
V_18 = sizeof( struct V_23 ) ;
break;
case V_62 :
V_18 = sizeof( struct V_29 ) ;
break;
case V_63 :
V_18 = sizeof( struct V_32 ) ;
break;
case V_64 :
V_18 = sizeof( struct V_34 ) ;
break;
default:
V_45 = - V_22 ;
goto V_20;
}
F_21 ( V_18 == 0 ) ;
V_7 = V_36 -> V_41 [ V_46 ] = F_18 ( V_18 , V_26 ) ;
if ( V_7 == NULL )
goto V_57;
F_6 ( V_14 , V_15 , 4 * sizeof( V_19 ) , V_20 ) ;
V_7 -> V_65 = F_7 ( V_14 ) ;
V_7 -> type = F_22 ( V_14 ) ;
V_7 -> V_42 = F_23 ( V_14 ) ;
V_7 -> V_66 = F_23 ( V_14 ) ;
V_7 -> V_67 = F_7 ( V_14 ) ;
V_7 -> V_18 = F_7 ( V_14 ) ;
F_5 ( L_13 ,
V_7 -> V_18 , ( int ) ( * V_14 - V_47 ) , * V_14 , V_15 ) ;
V_7 -> V_68 = F_9 ( V_7 -> V_18 , sizeof( T_1 ) , V_26 ) ;
if ( V_7 -> V_68 == NULL )
goto V_57;
F_6 ( V_14 , V_15 , V_7 -> V_18 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_18 ; V_24 ++ )
V_7 -> V_68 [ V_24 ] = F_7 ( V_14 ) ;
switch ( V_7 -> V_42 ) {
case V_60 :
V_45 = F_4 ( V_14 , V_15 ,
(struct V_16 * ) V_7 ) ;
if ( V_45 < 0 )
goto V_20;
break;
case V_61 :
V_45 = F_8 ( V_14 , V_15 ,
(struct V_23 * ) V_7 ) ;
if ( V_45 < 0 )
goto V_20;
break;
case V_62 :
V_45 = F_10 ( V_14 , V_15 ,
(struct V_29 * ) V_7 ) ;
if ( V_45 < 0 )
goto V_20;
break;
case V_63 :
V_45 = F_12 ( V_14 , V_15 ,
(struct V_32 * ) V_7 ) ;
if ( V_45 < 0 )
goto V_20;
break;
case V_64 :
V_45 = F_13 ( V_14 , V_15 ,
(struct V_34 * ) V_7 ) ;
if ( V_45 < 0 )
goto V_20;
break;
}
}
F_5 ( L_14 , V_36 -> V_58 ) ;
for ( V_46 = 0 ; V_46 < V_36 -> V_55 ; V_46 ++ ) {
V_19 V_69 ;
struct V_70 * V_71 ;
F_15 ( V_14 , V_15 , V_69 , V_20 ) ;
if ( ! V_69 ) {
F_5 ( L_15 ,
V_46 , ( int ) ( * V_14 - V_47 ) , * V_14 , V_15 ) ;
V_36 -> V_58 [ V_46 ] = NULL ;
continue;
}
F_5 ( L_16 ,
V_46 , ( int ) ( * V_14 - V_47 ) , * V_14 , V_15 ) ;
F_15 ( V_14 , V_15 , V_69 , V_20 ) ;
#if V_72 == 32
V_45 = - V_22 ;
if ( V_69 > ( V_73 - sizeof( * V_71 ) )
/ sizeof( struct V_74 ) )
goto V_20;
#endif
V_71 = V_36 -> V_58 [ V_46 ] = F_24 ( sizeof( * V_71 ) +
V_69 * sizeof( struct V_74 ) ,
V_26 ) ;
if ( V_71 == NULL )
goto V_57;
F_5 ( L_17 , V_46 , V_71 ) ;
V_71 -> V_2 = V_69 ;
F_25 ( V_14 , V_15 , & V_71 -> V_75 , 4 , V_20 ) ;
F_6 ( V_14 , V_15 , V_71 -> V_2 * 3 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_71 -> V_2 ; V_24 ++ ) {
V_71 -> V_76 [ V_24 ] . V_77 = F_7 ( V_14 ) ;
V_71 -> V_76 [ V_24 ] . V_78 = F_7 ( V_14 ) ;
V_71 -> V_76 [ V_24 ] . V_79 = F_7 ( V_14 ) ;
}
}
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_45 = F_14 ( V_14 , V_15 ) ;
if ( V_45 < 0 )
goto V_80;
}
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) , V_80 ) ;
V_36 -> V_50 = F_7 ( V_14 ) ;
V_36 -> V_51 = F_7 ( V_14 ) ;
V_36 -> V_52 = F_7 ( V_14 ) ;
F_5 ( L_18 ,
V_36 -> V_50 ) ;
F_5 ( L_19 ,
V_36 -> V_51 ) ;
F_5 ( L_20 ,
V_36 -> V_52 ) ;
F_6 ( V_14 , V_15 , sizeof( V_19 ) , V_80 ) ;
V_36 -> V_53 = F_7 ( V_14 ) ;
F_5 ( L_21 ,
V_36 -> V_53 ) ;
F_6 ( V_14 , V_15 , sizeof( V_81 ) , V_80 ) ;
V_36 -> V_82 = F_23 ( V_14 ) ;
F_5 ( L_22 ,
V_36 -> V_82 ) ;
F_6 ( V_14 , V_15 , sizeof( V_81 ) + sizeof( V_19 ) , V_80 ) ;
* V_14 += sizeof( V_81 ) + sizeof( V_19 ) ;
F_6 ( V_14 , V_15 , sizeof( V_81 ) , V_80 ) ;
V_36 -> V_83 = F_23 ( V_14 ) ;
F_5 ( L_23 ,
V_36 -> V_83 ) ;
V_80:
F_16 ( V_36 ) ;
F_5 ( L_24 ) ;
return V_36 ;
V_57:
V_45 = - V_27 ;
V_20:
F_5 ( L_25 , V_45 ) ;
F_26 ( V_36 ) ;
return F_19 ( V_45 ) ;
}
int F_27 ( const struct V_84 * V_85 , const struct V_84 * V_86 )
{
if ( V_85 -> V_87 < V_86 -> V_87 )
return - 1 ;
if ( V_85 -> V_87 > V_86 -> V_87 )
return 1 ;
if ( V_85 -> V_88 < V_86 -> V_88 )
return - 1 ;
if ( V_85 -> V_88 > V_86 -> V_88 )
return 1 ;
return 0 ;
}
static int F_28 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
struct V_93 * * V_14 = & V_92 -> V_93 ;
struct V_93 * V_94 = NULL ;
struct V_89 * V_95 = NULL ;
int V_36 ;
F_5 ( L_26 , * ( V_96 * ) & V_90 -> V_97 , V_90 ) ;
while ( * V_14 ) {
V_94 = * V_14 ;
V_95 = F_29 ( V_94 , struct V_89 , V_98 ) ;
V_36 = F_27 ( & V_90 -> V_97 , & V_95 -> V_97 ) ;
if ( V_36 < 0 )
V_14 = & ( * V_14 ) -> V_99 ;
else if ( V_36 > 0 )
V_14 = & ( * V_14 ) -> V_100 ;
else
return - V_101 ;
}
F_30 ( & V_90 -> V_98 , V_94 , V_14 ) ;
F_31 ( & V_90 -> V_98 , V_92 ) ;
return 0 ;
}
static struct V_89 * F_32 ( struct V_91 * V_92 ,
struct V_84 V_97 )
{
struct V_93 * V_102 = V_92 -> V_93 ;
struct V_89 * V_95 ;
int V_36 ;
while ( V_102 ) {
V_95 = F_29 ( V_102 , struct V_89 , V_98 ) ;
V_36 = F_27 ( & V_97 , & V_95 -> V_97 ) ;
if ( V_36 < 0 ) {
V_102 = V_102 -> V_99 ;
} else if ( V_36 > 0 ) {
V_102 = V_102 -> V_100 ;
} else {
F_5 ( L_27 ,
V_97 . V_87 , V_97 . V_88 , V_95 ) ;
return V_95 ;
}
}
return NULL ;
}
static int F_33 ( struct V_91 * V_92 , struct V_84 V_97 )
{
struct V_89 * V_95 = F_32 ( V_92 , V_97 ) ;
if ( V_95 ) {
F_5 ( L_28 , V_97 . V_87 , V_97 . V_88 ,
V_95 ) ;
F_34 ( & V_95 -> V_98 , V_92 ) ;
F_35 ( V_95 ) ;
return 0 ;
}
F_5 ( L_29 , V_97 . V_87 , V_97 . V_88 ) ;
return - V_103 ;
}
static int F_36 ( struct V_91 * V_92 , struct V_8 * V_90 )
{
struct V_93 * * V_14 = & V_92 -> V_93 ;
struct V_93 * V_94 = NULL ;
struct V_8 * V_9 = NULL ;
while ( * V_14 ) {
V_94 = * V_14 ;
V_9 = F_29 ( V_94 , struct V_8 , V_98 ) ;
if ( V_90 -> V_65 < V_9 -> V_65 )
V_14 = & ( * V_14 ) -> V_99 ;
else if ( V_90 -> V_65 > V_9 -> V_65 )
V_14 = & ( * V_14 ) -> V_100 ;
else
return - V_101 ;
}
F_30 ( & V_90 -> V_98 , V_94 , V_14 ) ;
F_31 ( & V_90 -> V_98 , V_92 ) ;
return 0 ;
}
static struct V_8 * F_37 ( struct V_91 * V_92 , V_96 V_65 )
{
struct V_8 * V_9 ;
struct V_93 * V_102 = V_92 -> V_93 ;
while ( V_102 ) {
V_9 = F_29 ( V_102 , struct V_8 , V_98 ) ;
if ( V_65 < V_9 -> V_65 )
V_102 = V_102 -> V_99 ;
else if ( V_65 > V_9 -> V_65 )
V_102 = V_102 -> V_100 ;
else
return V_9 ;
}
return NULL ;
}
struct V_8 * F_38 ( struct V_104 * V_105 , V_96 V_65 )
{
return F_37 ( & V_105 -> V_106 , V_65 ) ;
}
const char * F_39 ( struct V_104 * V_105 , V_96 V_65 )
{
struct V_8 * V_9 ;
if ( V_65 == V_107 )
return NULL ;
if ( F_40 ( V_65 > ( V_96 ) V_108 ) )
return NULL ;
V_9 = F_37 ( & V_105 -> V_106 , ( int ) V_65 ) ;
return V_9 ? V_9 -> V_109 : NULL ;
}
int F_41 ( struct V_104 * V_105 , const char * V_109 )
{
struct V_93 * V_110 ;
for ( V_110 = F_42 ( & V_105 -> V_106 ) ; V_110 ; V_110 = F_43 ( V_110 ) ) {
struct V_8 * V_9 =
F_29 ( V_110 , struct V_8 , V_98 ) ;
if ( V_9 -> V_109 && strcmp ( V_9 -> V_109 , V_109 ) == 0 )
return V_9 -> V_65 ;
}
return - V_103 ;
}
static void F_44 ( struct V_91 * V_92 , struct V_8 * V_9 )
{
F_34 ( & V_9 -> V_98 , V_92 ) ;
F_35 ( V_9 -> V_109 ) ;
F_35 ( V_9 ) ;
}
static int F_45 ( void * * V_14 , void * V_15 , struct V_8 * V_9 )
{
V_81 V_111 , V_112 ;
unsigned V_2 , V_113 ;
void * V_114 ;
F_6 ( V_14 , V_15 , 2 + 4 , V_20 ) ;
V_111 = F_23 ( V_14 ) ;
V_112 = F_23 ( V_14 ) ;
if ( V_111 < 5 ) {
F_46 ( L_30 , V_111 , V_112 ) ;
return - V_22 ;
}
if ( V_112 > 9 ) {
F_46 ( L_31 , V_111 , V_112 ) ;
return - V_22 ;
}
V_2 = F_7 ( V_14 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_114 = * V_14 + V_2 ;
V_9 -> type = F_23 ( V_14 ) ;
V_9 -> V_18 = F_23 ( V_14 ) ;
V_9 -> V_115 = F_23 ( V_14 ) ;
V_9 -> V_116 = F_23 ( V_14 ) ;
V_9 -> V_11 = F_7 ( V_14 ) ;
V_9 -> V_13 = F_7 ( V_14 ) ;
* V_14 += 4 + 4 ;
* V_14 += 4 ;
* V_14 += 8 + 4 ;
V_113 = F_7 ( V_14 ) ;
while ( V_113 -- ) {
* V_14 += 8 ;
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
V_113 = F_7 ( V_14 ) ;
* V_14 += V_113 * ( 8 + 8 ) ;
* V_14 += 8 ;
V_9 -> V_117 = F_47 ( V_14 ) ;
* V_14 += 4 ;
if ( V_111 >= 7 )
V_9 -> V_118 = F_23 ( V_14 ) ;
else
V_9 -> V_118 = V_9 -> V_18 - V_9 -> V_18 / 2 ;
if ( V_111 >= 8 )
* V_14 += 8 + 8 ;
if ( V_111 >= 9 ) {
V_113 = F_7 ( V_14 ) ;
* V_14 += V_113 * 8 ;
* V_14 += 8 ;
* V_14 += 1 ;
V_9 -> V_119 = F_47 ( V_14 ) ;
V_9 -> V_120 = F_47 ( V_14 ) ;
} else {
V_9 -> V_119 = - 1 ;
V_9 -> V_120 = - 1 ;
}
if ( V_111 >= 10 ) {
V_113 = F_7 ( V_14 ) ;
while ( V_113 -- ) {
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
}
if ( V_111 >= 11 ) {
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
* V_14 += 4 ;
* V_14 += 4 ;
}
if ( V_111 >= 12 )
* V_14 += 4 ;
if ( V_111 >= 13 ) {
* V_14 += 8 ;
* V_14 += 8 ;
* V_14 += 4 ;
* V_14 += 4 ;
* V_14 += 4 ;
* V_14 += 4 ;
}
if ( V_111 >= 14 ) {
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
if ( V_111 >= 15 )
V_9 -> V_121 = F_7 ( V_14 ) ;
else
V_9 -> V_121 = 0 ;
* V_14 = V_114 ;
F_3 ( V_9 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_48 ( void * * V_14 , void * V_15 , struct V_104 * V_105 )
{
struct V_8 * V_9 ;
V_19 V_113 , V_2 ;
V_96 V_87 ;
F_15 ( V_14 , V_15 , V_113 , V_20 ) ;
F_5 ( L_32 , V_113 ) ;
while ( V_113 -- ) {
F_49 ( V_14 , V_15 , V_87 , V_20 ) ;
F_15 ( V_14 , V_15 , V_2 , V_20 ) ;
F_5 ( L_33 , V_87 , V_2 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_9 = F_37 ( & V_105 -> V_106 , V_87 ) ;
if ( V_9 ) {
char * V_109 = F_50 ( * V_14 , V_2 , V_26 ) ;
if ( ! V_109 )
return - V_27 ;
F_35 ( V_9 -> V_109 ) ;
V_9 -> V_109 = V_109 ;
F_5 ( L_34 , V_9 -> V_109 ) ;
}
* V_14 += V_2 ;
}
return 0 ;
V_20:
return - V_22 ;
}
struct V_104 * F_51 ( void )
{
struct V_104 * V_105 ;
V_105 = F_18 ( sizeof( * V_105 ) , V_122 ) ;
if ( ! V_105 )
return NULL ;
V_105 -> V_106 = V_123 ;
V_105 -> V_124 = - 1 ;
V_105 -> V_125 = V_123 ;
V_105 -> V_126 = V_123 ;
F_52 ( & V_105 -> V_127 ) ;
return V_105 ;
}
void F_53 ( struct V_104 * V_105 )
{
F_5 ( L_35 , V_105 ) ;
if ( V_105 -> V_128 )
F_26 ( V_105 -> V_128 ) ;
while ( ! F_54 ( & V_105 -> V_125 ) ) {
struct V_89 * V_95 =
F_29 ( F_42 ( & V_105 -> V_125 ) ,
struct V_89 , V_98 ) ;
F_34 ( & V_95 -> V_98 , & V_105 -> V_125 ) ;
F_35 ( V_95 ) ;
}
while ( ! F_54 ( & V_105 -> V_126 ) ) {
struct V_89 * V_95 =
F_29 ( F_42 ( & V_105 -> V_126 ) ,
struct V_89 , V_98 ) ;
F_34 ( & V_95 -> V_98 , & V_105 -> V_126 ) ;
F_35 ( V_95 ) ;
}
while ( ! F_54 ( & V_105 -> V_106 ) ) {
struct V_8 * V_9 =
F_29 ( F_42 ( & V_105 -> V_106 ) ,
struct V_8 , V_98 ) ;
F_44 ( & V_105 -> V_106 , V_9 ) ;
}
F_35 ( V_105 -> V_129 ) ;
F_35 ( V_105 -> V_130 ) ;
F_35 ( V_105 -> V_131 ) ;
F_35 ( V_105 -> V_132 ) ;
F_35 ( V_105 -> V_133 ) ;
F_35 ( V_105 ) ;
}
static int F_55 ( struct V_104 * V_105 , int V_134 )
{
V_81 * V_3 ;
V_19 * V_67 ;
struct V_135 * V_136 ;
int V_46 ;
V_3 = F_56 ( V_105 -> V_129 , V_134 * sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
return - V_27 ;
V_105 -> V_129 = V_3 ;
V_67 = F_56 ( V_105 -> V_130 , V_134 * sizeof( * V_67 ) , V_26 ) ;
if ( ! V_67 )
return - V_27 ;
V_105 -> V_130 = V_67 ;
V_136 = F_56 ( V_105 -> V_131 , V_134 * sizeof( * V_136 ) , V_26 ) ;
if ( ! V_136 )
return - V_27 ;
V_105 -> V_131 = V_136 ;
for ( V_46 = V_105 -> V_137 ; V_46 < V_134 ; V_46 ++ ) {
V_105 -> V_129 [ V_46 ] = 0 ;
V_105 -> V_130 [ V_46 ] = V_138 ;
memset ( V_105 -> V_131 + V_46 , 0 , sizeof( * V_105 -> V_131 ) ) ;
}
if ( V_105 -> V_132 ) {
V_19 * V_139 ;
V_139 = F_56 ( V_105 -> V_132 ,
V_134 * sizeof( * V_139 ) , V_26 ) ;
if ( ! V_139 )
return - V_27 ;
V_105 -> V_132 = V_139 ;
for ( V_46 = V_105 -> V_137 ; V_46 < V_134 ; V_46 ++ )
V_105 -> V_132 [ V_46 ] =
V_140 ;
}
V_105 -> V_137 = V_134 ;
return 0 ;
}
static int F_57 ( struct V_104 * V_105 , struct V_35 * V_128 )
{
void * V_141 ;
T_2 V_142 ;
if ( F_58 ( V_128 ) )
return F_59 ( V_128 ) ;
V_142 = F_60 ( V_128 , V_143 ) ;
F_5 ( L_36 , V_144 , V_142 ) ;
V_141 = F_24 ( V_142 , V_122 ) ;
if ( ! V_141 ) {
F_26 ( V_128 ) ;
return - V_27 ;
}
F_61 ( V_128 , V_141 ) ;
if ( V_105 -> V_128 )
F_26 ( V_105 -> V_128 ) ;
F_35 ( V_105 -> V_133 ) ;
V_105 -> V_128 = V_128 ;
V_105 -> V_133 = V_141 ;
return 0 ;
}
static int F_62 ( void * * V_14 , void * V_15 ,
const char * V_145 , V_81 * V_146 )
{
V_81 V_147 ;
F_11 ( V_14 , V_15 , V_147 , V_148 ) ;
if ( V_147 >= 7 ) {
V_81 V_149 ;
F_11 ( V_14 , V_15 , V_149 , V_148 ) ;
if ( V_149 > V_150 ) {
F_46 ( L_37 ,
V_147 , V_149 ,
V_150 , V_145 ) ;
return - V_22 ;
}
* V_14 += 4 ;
F_11 ( V_14 , V_15 , V_147 , V_148 ) ;
F_11 ( V_14 , V_15 , V_149 , V_148 ) ;
if ( V_149 > V_151 ) {
F_46 ( L_38 ,
V_147 , V_149 ,
V_151 , V_145 ) ;
return - V_22 ;
}
* V_14 += 4 ;
} else {
T_3 V_152 ;
* V_14 -= 1 ;
F_63 ( V_14 , V_15 , V_152 , V_148 ) ;
if ( V_152 < 6 ) {
F_46 ( L_39 ,
V_152 , V_145 ) ;
return - V_22 ;
}
V_147 = 0 ;
}
* V_146 = V_147 ;
return 0 ;
V_148:
return - V_22 ;
}
static int F_64 ( void * * V_14 , void * V_15 , struct V_104 * V_105 ,
bool V_153 )
{
V_19 V_102 ;
F_15 ( V_14 , V_15 , V_102 , V_148 ) ;
while ( V_102 -- ) {
struct V_8 * V_9 ;
V_96 V_87 ;
int V_154 ;
F_49 ( V_14 , V_15 , V_87 , V_148 ) ;
V_9 = F_37 ( & V_105 -> V_106 , V_87 ) ;
if ( ! V_153 || ! V_9 ) {
V_9 = F_18 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
V_9 -> V_65 = V_87 ;
V_154 = F_36 ( & V_105 -> V_106 , V_9 ) ;
if ( V_154 ) {
F_35 ( V_9 ) ;
return V_154 ;
}
}
V_154 = F_45 ( V_14 , V_15 , V_9 ) ;
if ( V_154 )
return V_154 ;
}
return 0 ;
V_148:
return - V_22 ;
}
static int F_65 ( void * * V_14 , void * V_15 , struct V_104 * V_105 )
{
return F_64 ( V_14 , V_15 , V_105 , false ) ;
}
static int F_66 ( void * * V_14 , void * V_15 , struct V_104 * V_105 )
{
return F_64 ( V_14 , V_15 , V_105 , true ) ;
}
static int F_67 ( void * * V_14 , void * V_15 , struct V_104 * V_105 ,
bool V_153 )
{
V_19 V_102 ;
F_15 ( V_14 , V_15 , V_102 , V_148 ) ;
while ( V_102 -- ) {
struct V_84 V_97 ;
V_19 V_2 , V_46 ;
int V_154 ;
V_154 = F_68 ( V_14 , V_15 , & V_97 ) ;
if ( V_154 )
return V_154 ;
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
V_154 = F_33 ( & V_105 -> V_125 , V_97 ) ;
F_21 ( ! V_153 && V_154 != - V_103 ) ;
if ( ! V_153 || V_2 > 0 ) {
struct V_89 * V_95 ;
F_6 ( V_14 , V_15 , V_2 * sizeof( V_19 ) , V_148 ) ;
if ( V_2 > ( V_155 - sizeof( * V_95 ) ) / sizeof( V_19 ) )
return - V_22 ;
V_95 = F_18 ( sizeof( * V_95 ) + V_2 * sizeof( V_19 ) , V_26 ) ;
if ( ! V_95 )
return - V_27 ;
V_95 -> V_97 = V_97 ;
V_95 -> V_125 . V_2 = V_2 ;
for ( V_46 = 0 ; V_46 < V_2 ; V_46 ++ )
V_95 -> V_125 . V_156 [ V_46 ] = F_7 ( V_14 ) ;
V_154 = F_28 ( V_95 , & V_105 -> V_125 ) ;
if ( V_154 ) {
F_35 ( V_95 ) ;
return V_154 ;
}
}
}
return 0 ;
V_148:
return - V_22 ;
}
static int F_69 ( void * * V_14 , void * V_15 , struct V_104 * V_105 )
{
return F_67 ( V_14 , V_15 , V_105 , false ) ;
}
static int F_70 ( void * * V_14 , void * V_15 , struct V_104 * V_105 )
{
return F_67 ( V_14 , V_15 , V_105 , true ) ;
}
static int F_71 ( void * * V_14 , void * V_15 , struct V_104 * V_105 ,
bool V_153 )
{
V_19 V_102 ;
F_15 ( V_14 , V_15 , V_102 , V_148 ) ;
while ( V_102 -- ) {
struct V_84 V_97 ;
V_19 V_157 ;
int V_154 ;
V_154 = F_68 ( V_14 , V_15 , & V_97 ) ;
if ( V_154 )
return V_154 ;
F_15 ( V_14 , V_15 , V_157 , V_148 ) ;
V_154 = F_33 ( & V_105 -> V_126 , V_97 ) ;
F_21 ( ! V_153 && V_154 != - V_103 ) ;
if ( ! V_153 || V_157 != ( V_19 ) - 1 ) {
struct V_89 * V_95 ;
V_95 = F_18 ( sizeof( * V_95 ) , V_26 ) ;
if ( ! V_95 )
return - V_27 ;
V_95 -> V_97 = V_97 ;
V_95 -> V_126 . V_157 = V_157 ;
V_154 = F_28 ( V_95 , & V_105 -> V_126 ) ;
if ( V_154 ) {
F_35 ( V_95 ) ;
return V_154 ;
}
}
}
return 0 ;
V_148:
return - V_22 ;
}
static int F_72 ( void * * V_14 , void * V_15 , struct V_104 * V_105 )
{
return F_71 ( V_14 , V_15 , V_105 , false ) ;
}
static int F_73 ( void * * V_14 , void * V_15 ,
struct V_104 * V_105 )
{
return F_71 ( V_14 , V_15 , V_105 , true ) ;
}
V_19 F_74 ( struct V_104 * V_105 , int V_157 )
{
F_21 ( V_157 >= V_105 -> V_137 ) ;
if ( ! V_105 -> V_132 )
return V_140 ;
return V_105 -> V_132 [ V_157 ] ;
}
static int F_75 ( struct V_104 * V_105 , int V_157 , V_19 V_158 )
{
F_21 ( V_157 >= V_105 -> V_137 ) ;
if ( ! V_105 -> V_132 ) {
int V_46 ;
V_105 -> V_132 = F_24 ( V_105 -> V_137 * sizeof( V_19 ) ,
V_26 ) ;
if ( ! V_105 -> V_132 )
return - V_27 ;
for ( V_46 = 0 ; V_46 < V_105 -> V_137 ; V_46 ++ )
V_105 -> V_132 [ V_46 ] =
V_140 ;
}
V_105 -> V_132 [ V_157 ] = V_158 ;
return 0 ;
}
static int F_76 ( void * * V_14 , void * V_15 ,
struct V_104 * V_105 )
{
V_19 V_2 , V_46 ;
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
if ( V_2 == 0 ) {
F_35 ( V_105 -> V_132 ) ;
V_105 -> V_132 = NULL ;
return 0 ;
}
if ( V_2 != V_105 -> V_137 )
goto V_148;
F_6 ( V_14 , V_15 , V_105 -> V_137 * sizeof( V_19 ) , V_148 ) ;
for ( V_46 = 0 ; V_46 < V_105 -> V_137 ; V_46 ++ ) {
int V_154 ;
V_154 = F_75 ( V_105 , V_46 , F_7 ( V_14 ) ) ;
if ( V_154 )
return V_154 ;
}
return 0 ;
V_148:
return - V_22 ;
}
static int F_77 ( void * * V_14 , void * V_15 ,
struct V_104 * V_105 )
{
V_19 V_102 ;
F_15 ( V_14 , V_15 , V_102 , V_148 ) ;
while ( V_102 -- ) {
V_19 V_157 , V_158 ;
int V_154 ;
F_15 ( V_14 , V_15 , V_157 , V_148 ) ;
F_15 ( V_14 , V_15 , V_158 , V_148 ) ;
V_154 = F_75 ( V_105 , V_157 , V_158 ) ;
if ( V_154 )
return V_154 ;
F_78 ( L_40 , V_157 , V_158 ) ;
}
return 0 ;
V_148:
return - V_22 ;
}
static int F_79 ( void * * V_14 , void * V_15 , struct V_104 * V_105 )
{
V_81 V_147 ;
V_19 V_159 = 0 ;
void * V_47 = * V_14 ;
V_19 V_134 ;
V_19 V_2 , V_46 ;
int V_45 ;
F_5 ( L_41 , V_144 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_45 = F_62 ( V_14 , V_15 , L_42 , & V_147 ) ;
if ( V_45 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_105 -> V_160 ) + sizeof( V_19 ) +
sizeof( V_105 -> V_161 ) + sizeof( V_105 -> V_162 ) , V_148 ) ;
F_80 ( V_14 , & V_105 -> V_160 , sizeof( V_105 -> V_160 ) ) ;
V_159 = V_105 -> V_159 = F_7 ( V_14 ) ;
F_80 ( V_14 , & V_105 -> V_161 , sizeof( V_105 -> V_161 ) ) ;
F_80 ( V_14 , & V_105 -> V_162 , sizeof( V_105 -> V_162 ) ) ;
V_45 = F_65 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
V_45 = F_48 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
F_15 ( V_14 , V_15 , V_105 -> V_124 , V_148 ) ;
F_15 ( V_14 , V_15 , V_105 -> V_117 , V_148 ) ;
F_15 ( V_14 , V_15 , V_134 , V_148 ) ;
V_45 = F_55 ( V_105 , V_134 ) ;
if ( V_45 )
goto V_20;
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) +
V_105 -> V_137 * ( 1 + sizeof( * V_105 -> V_130 ) +
sizeof( * V_105 -> V_131 ) ) , V_148 ) ;
if ( F_7 ( V_14 ) != V_105 -> V_137 )
goto V_148;
F_80 ( V_14 , V_105 -> V_129 , V_105 -> V_137 ) ;
if ( F_7 ( V_14 ) != V_105 -> V_137 )
goto V_148;
for ( V_46 = 0 ; V_46 < V_105 -> V_137 ; V_46 ++ )
V_105 -> V_130 [ V_46 ] = F_7 ( V_14 ) ;
if ( F_7 ( V_14 ) != V_105 -> V_137 )
goto V_148;
F_80 ( V_14 , V_105 -> V_131 , V_105 -> V_137 * sizeof( * V_105 -> V_131 ) ) ;
for ( V_46 = 0 ; V_46 < V_105 -> V_137 ; V_46 ++ )
F_81 ( & V_105 -> V_131 [ V_46 ] ) ;
V_45 = F_69 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
if ( V_147 >= 1 ) {
V_45 = F_72 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
}
if ( V_147 >= 2 ) {
V_45 = F_76 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
} else {
F_35 ( V_105 -> V_132 ) ;
V_105 -> V_132 = NULL ;
}
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
V_45 = F_57 ( V_105 , F_17 ( * V_14 , F_82 ( * V_14 + V_2 , V_15 ) ) ) ;
if ( V_45 )
goto V_20;
* V_14 = V_15 ;
F_5 ( L_43 , V_105 -> V_159 , V_105 -> V_137 ) ;
return 0 ;
V_148:
V_45 = - V_22 ;
V_20:
F_20 ( L_44 ,
V_45 , V_159 , ( int ) ( * V_14 - V_47 ) , * V_14 , V_47 , V_15 ) ;
F_83 ( V_163 , L_45 ,
V_164 , 16 , 1 ,
V_47 , V_15 - V_47 , true ) ;
return V_45 ;
}
struct V_104 * F_84 ( void * * V_14 , void * V_15 )
{
struct V_104 * V_105 ;
int V_154 ;
V_105 = F_51 () ;
if ( ! V_105 )
return F_19 ( - V_27 ) ;
V_154 = F_79 ( V_14 , V_15 , V_105 ) ;
if ( V_154 ) {
F_53 ( V_105 ) ;
return F_19 ( V_154 ) ;
}
return V_105 ;
}
static int F_85 ( void * * V_14 , void * V_15 ,
struct V_104 * V_105 )
{
void * V_165 ;
void * V_166 ;
void * V_167 ;
V_19 V_2 ;
V_165 = * V_14 ;
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
V_2 *= sizeof( V_19 ) + sizeof( struct V_135 ) ;
F_6 ( V_14 , V_15 , V_2 , V_148 ) ;
* V_14 += V_2 ;
V_166 = * V_14 ;
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
V_2 *= sizeof( V_19 ) + sizeof( V_81 ) ;
F_6 ( V_14 , V_15 , V_2 , V_148 ) ;
* V_14 += V_2 ;
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
while ( V_2 -- ) {
T_4 V_157 ;
V_19 V_168 ;
F_6 ( V_14 , V_15 , 2 * sizeof( V_19 ) , V_148 ) ;
V_157 = F_7 ( V_14 ) ;
V_168 = F_7 ( V_14 ) ;
F_21 ( V_157 >= V_105 -> V_137 ) ;
F_78 ( L_46 , V_157 , V_168 ,
V_168 == V_169 ? L_47 :
( V_168 == V_138 ? L_48 : L_49 ) ) ;
V_105 -> V_130 [ V_157 ] = V_168 ;
if ( V_168 ) {
V_105 -> V_129 [ V_157 ] |= V_4 ;
V_105 -> V_129 [ V_157 ] &= ~ ( V_170 |
V_171 ) ;
}
}
V_167 = * V_14 ;
* V_14 = V_166 ;
V_2 = F_7 ( V_14 ) ;
while ( V_2 -- ) {
T_4 V_157 ;
V_81 V_172 ;
int V_154 ;
V_157 = F_7 ( V_14 ) ;
V_172 = F_23 ( V_14 ) ;
if ( V_172 == 0 )
V_172 = V_5 ;
F_21 ( V_157 >= V_105 -> V_137 ) ;
if ( ( V_105 -> V_129 [ V_157 ] & V_5 ) &&
( V_172 & V_5 ) )
F_78 ( L_50 , V_157 ) ;
if ( ( V_105 -> V_129 [ V_157 ] & V_4 ) &&
( V_172 & V_4 ) ) {
F_78 ( L_51 , V_157 ) ;
V_154 = F_75 ( V_105 , V_157 ,
V_140 ) ;
if ( V_154 )
return V_154 ;
memset ( V_105 -> V_131 + V_157 , 0 , sizeof( * V_105 -> V_131 ) ) ;
V_105 -> V_129 [ V_157 ] = 0 ;
} else {
V_105 -> V_129 [ V_157 ] ^= V_172 ;
}
}
* V_14 = V_165 ;
V_2 = F_7 ( V_14 ) ;
while ( V_2 -- ) {
T_4 V_157 ;
struct V_135 V_136 ;
V_157 = F_7 ( V_14 ) ;
F_80 ( V_14 , & V_136 , sizeof( V_136 ) ) ;
F_81 ( & V_136 ) ;
F_21 ( V_157 >= V_105 -> V_137 ) ;
F_78 ( L_52 , V_157 ) ;
V_105 -> V_129 [ V_157 ] |= V_4 | V_5 ;
V_105 -> V_131 [ V_157 ] = V_136 ;
}
* V_14 = V_167 ;
return 0 ;
V_148:
return - V_22 ;
}
struct V_104 * F_86 ( void * * V_14 , void * V_15 ,
struct V_104 * V_105 )
{
struct V_173 V_160 ;
V_19 V_159 = 0 ;
struct V_174 V_162 ;
T_4 V_2 ;
V_96 V_87 ;
T_5 V_175 ;
T_1 V_176 , V_134 ;
void * V_47 = * V_14 ;
int V_45 ;
V_81 V_147 ;
F_5 ( L_41 , V_144 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_45 = F_62 ( V_14 , V_15 , L_53 , & V_147 ) ;
if ( V_45 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_160 ) + sizeof( V_19 ) + sizeof( V_162 ) +
sizeof( V_96 ) + sizeof( V_19 ) , V_148 ) ;
F_80 ( V_14 , & V_160 , sizeof( V_160 ) ) ;
V_159 = F_7 ( V_14 ) ;
F_21 ( V_159 != V_105 -> V_159 + 1 ) ;
F_80 ( V_14 , & V_162 , sizeof( V_162 ) ) ;
V_175 = F_47 ( V_14 ) ;
V_176 = F_7 ( V_14 ) ;
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
if ( V_2 > 0 ) {
F_5 ( L_54 ,
V_2 , * V_14 , V_15 ) ;
return F_84 ( V_14 , F_82 ( * V_14 + V_2 , V_15 ) ) ;
}
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
if ( V_2 > 0 ) {
V_45 = F_57 ( V_105 ,
F_17 ( * V_14 , F_82 ( * V_14 + V_2 , V_15 ) ) ) ;
if ( V_45 )
goto V_20;
* V_14 += V_2 ;
}
if ( V_176 >= 0 )
V_105 -> V_117 = V_176 ;
if ( V_175 >= 0 )
V_105 -> V_124 = V_175 ;
F_15 ( V_14 , V_15 , V_134 , V_148 ) ;
if ( V_134 >= 0 ) {
V_45 = F_55 ( V_105 , V_134 ) ;
if ( V_45 )
goto V_20;
}
V_105 -> V_159 ++ ;
V_105 -> V_162 = V_162 ;
V_45 = F_66 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
V_45 = F_48 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
F_15 ( V_14 , V_15 , V_2 , V_148 ) ;
while ( V_2 -- ) {
struct V_8 * V_9 ;
F_49 ( V_14 , V_15 , V_87 , V_148 ) ;
V_9 = F_37 ( & V_105 -> V_106 , V_87 ) ;
if ( V_9 )
F_44 ( & V_105 -> V_106 , V_9 ) ;
}
V_45 = F_85 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
V_45 = F_70 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
if ( V_147 >= 1 ) {
V_45 = F_73 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
}
if ( V_147 >= 2 ) {
V_45 = F_77 ( V_14 , V_15 , V_105 ) ;
if ( V_45 )
goto V_20;
}
* V_14 = V_15 ;
F_5 ( L_55 , V_105 -> V_159 , V_105 -> V_137 ) ;
return V_105 ;
V_148:
V_45 = - V_22 ;
V_20:
F_20 ( L_56 ,
V_45 , V_159 , ( int ) ( * V_14 - V_47 ) , * V_14 , V_47 , V_15 ) ;
F_83 ( V_163 , L_45 ,
V_164 , 16 , 1 ,
V_47 , V_15 - V_47 , true ) ;
return F_19 ( V_45 ) ;
}
void F_87 ( struct V_177 * V_178 ,
const struct V_177 * V_179 )
{
F_88 ( ! F_89 ( V_178 ) ) ;
F_88 ( V_178 -> V_180 ) ;
V_178 -> V_87 = V_179 -> V_87 ;
if ( V_179 -> V_180 )
V_178 -> V_180 = F_90 ( V_179 -> V_180 ) ;
}
void F_91 ( struct V_177 * V_181 )
{
F_92 ( V_181 -> V_180 ) ;
}
void F_93 ( struct V_182 * V_178 ,
const struct V_182 * V_179 )
{
F_88 ( ! F_94 ( V_178 ) ) ;
if ( V_179 -> V_109 != V_179 -> V_183 ) {
V_178 -> V_109 = F_24 ( V_179 -> V_184 + 1 ,
V_122 | V_185 ) ;
}
memcpy ( V_178 -> V_109 , V_179 -> V_109 , V_179 -> V_184 + 1 ) ;
V_178 -> V_184 = V_179 -> V_184 ;
}
void F_95 ( struct V_182 * V_186 )
{
if ( V_186 -> V_109 != V_186 -> V_183 )
F_35 ( V_186 -> V_109 ) ;
}
static bool F_96 ( const struct V_187 * V_85 ,
const struct V_187 * V_86 )
{
if ( V_85 -> V_18 == V_86 -> V_18 &&
! memcmp ( V_85 -> V_156 , V_86 -> V_156 , V_86 -> V_18 * sizeof( V_86 -> V_156 [ 0 ] ) ) )
return true ;
return false ;
}
static bool F_97 ( const struct V_187 * V_85 ,
const struct V_187 * V_86 )
{
if ( F_96 ( V_85 , V_86 ) &&
V_85 -> V_188 == V_86 -> V_188 )
return true ;
return false ;
}
static bool F_98 ( const struct V_187 * V_189 )
{
if ( V_189 -> V_18 > 0 && V_189 -> V_188 >= 0 )
return true ;
if ( ! V_189 -> V_18 && V_189 -> V_188 == - 1 )
return true ;
if ( V_189 -> V_18 > 0 && V_189 -> V_188 == - 1 ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < V_189 -> V_18 ; V_46 ++ ) {
if ( V_189 -> V_156 [ V_46 ] != V_190 )
break;
}
if ( V_46 == V_189 -> V_18 )
return true ;
}
return false ;
}
void F_99 ( struct V_187 * V_178 , const struct V_187 * V_179 )
{
memcpy ( V_178 -> V_156 , V_179 -> V_156 , V_179 -> V_18 * sizeof( V_179 -> V_156 [ 0 ] ) ) ;
V_178 -> V_18 = V_179 -> V_18 ;
V_178 -> V_188 = V_179 -> V_188 ;
}
static bool F_100 ( const struct V_84 * V_97 ,
V_19 V_191 ,
V_19 V_192 )
{
int V_193 = F_2 ( V_191 ) ;
int V_194 = ( 1 << V_193 ) - 1 ;
int V_102 ;
F_88 ( V_97 -> V_88 >= V_191 ) ;
if ( V_192 <= V_191 )
return false ;
for ( V_102 = 1 ; ; V_102 ++ ) {
int V_195 = V_102 << ( V_193 - 1 ) ;
V_19 V_196 = V_195 | V_97 -> V_88 ;
if ( V_196 < V_191 || V_196 == V_97 -> V_88 )
continue;
if ( V_196 >= V_192 )
break;
V_196 = F_101 ( V_196 , V_191 , V_194 ) ;
if ( V_196 == V_97 -> V_88 )
return true ;
}
return false ;
}
bool F_102 ( const struct V_187 * V_197 ,
const struct V_187 * V_198 ,
const struct V_187 * V_199 ,
const struct V_187 * V_200 ,
int V_201 ,
int V_202 ,
int V_203 ,
int V_204 ,
V_19 V_191 ,
V_19 V_192 ,
bool V_205 ,
bool V_206 ,
const struct V_84 * V_97 )
{
return ! F_97 ( V_197 , V_198 ) ||
! F_97 ( V_199 , V_200 ) ||
V_201 != V_202 ||
V_203 != V_204 ||
F_100 ( V_97 , V_191 , V_192 ) ||
V_205 != V_206 ;
}
static int F_103 ( int V_157 , const struct V_187 * V_207 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_207 -> V_18 ; V_46 ++ ) {
if ( V_207 -> V_156 [ V_46 ] == V_157 )
return V_46 ;
}
return - 1 ;
}
static bool F_104 ( const struct V_187 * V_197 ,
const struct V_187 * V_198 )
{
if ( ! V_197 -> V_18 && ! V_198 -> V_18 )
return false ;
if ( ! V_197 -> V_18 ^ ! V_198 -> V_18 )
return true ;
if ( V_197 -> V_188 != V_198 -> V_188 )
return true ;
if ( F_103 ( V_197 -> V_188 , V_197 ) !=
F_103 ( V_198 -> V_188 , V_198 ) )
return true ;
return false ;
}
bool F_105 ( const struct V_187 * V_197 ,
const struct V_187 * V_198 ,
bool V_208 )
{
if ( F_104 ( V_197 , V_198 ) )
return true ;
if ( V_208 && ! F_96 ( V_197 , V_198 ) )
return true ;
return false ;
}
int F_106 ( struct V_209 * V_210 ,
V_96 V_211 , V_96 V_2 ,
V_96 * V_212 ,
V_96 * V_213 , V_96 * V_214 )
{
V_19 V_215 = V_210 -> V_216 ;
V_19 V_217 = V_210 -> V_218 ;
V_19 V_219 = V_210 -> V_220 ;
V_19 V_221 , V_222 , V_223 , V_224 ;
V_19 V_225 ;
V_96 V_6 , V_226 ;
F_5 ( L_57 , V_211 , V_2 ,
V_215 , V_217 ) ;
if ( V_217 == 0 || V_219 == 0 )
goto V_227;
V_225 = V_215 / V_217 ;
if ( V_225 == 0 )
goto V_227;
F_5 ( L_58 , V_215 , V_217 ,
V_225 ) ;
if ( ( V_217 & ~ V_228 ) != 0 )
goto V_227;
V_6 = V_211 ;
F_107 ( V_6 , V_217 ) ;
V_221 = V_6 ;
F_5 ( L_59 , V_211 , V_217 , V_221 ) ;
V_222 = V_221 / V_219 ;
V_223 = V_221 % V_219 ;
V_224 = V_222 / V_225 ;
* V_212 = V_224 * V_219 + V_223 ;
F_5 ( L_60 , V_224 , V_219 , ( unsigned int ) * V_212 ) ;
V_6 = V_211 ;
V_226 = F_107 ( V_6 , V_217 ) ;
* V_213 = V_226 + ( V_222 % V_225 ) * V_217 ;
* V_214 = F_108 ( V_96 , V_2 , V_217 - V_226 ) ;
F_5 ( L_61 , * V_213 , * V_214 ) ;
return 0 ;
V_227:
F_5 ( L_62 ) ;
* V_212 = 0 ;
* V_213 = 0 ;
* V_214 = 0 ;
return - V_22 ;
}
int F_109 ( struct V_104 * V_229 ,
struct V_182 * V_186 ,
struct V_177 * V_181 ,
struct V_84 * V_230 )
{
struct V_8 * V_9 ;
V_9 = F_38 ( V_229 , V_181 -> V_87 ) ;
if ( ! V_9 )
return - V_103 ;
if ( ! V_181 -> V_180 ) {
V_230 -> V_87 = V_181 -> V_87 ;
V_230 -> V_88 = F_110 ( V_9 -> V_116 , V_186 -> V_109 ,
V_186 -> V_184 ) ;
F_5 ( L_63 , V_144 , V_186 -> V_109 ,
V_230 -> V_87 , V_230 -> V_88 ) ;
} else {
char V_231 [ 256 ] ;
char * V_232 = V_231 ;
int V_233 = V_181 -> V_180 -> V_2 ;
T_2 V_234 = V_233 + 1 + V_186 -> V_184 ;
if ( V_234 > sizeof( V_231 ) ) {
V_232 = F_24 ( V_234 , V_122 ) ;
if ( ! V_232 )
return - V_27 ;
}
memcpy ( V_232 , V_181 -> V_180 -> V_1 , V_233 ) ;
V_232 [ V_233 ] = '\037' ;
memcpy ( V_232 + V_233 + 1 , V_186 -> V_109 , V_186 -> V_184 ) ;
V_230 -> V_87 = V_181 -> V_87 ;
V_230 -> V_88 = F_110 ( V_9 -> V_116 , V_232 , V_234 ) ;
if ( V_232 != V_231 )
F_35 ( V_232 ) ;
F_5 ( L_64 , V_144 ,
V_186 -> V_109 , V_233 , V_181 -> V_180 -> V_1 ,
V_230 -> V_87 , V_230 -> V_88 ) ;
}
return 0 ;
}
static void F_111 ( struct V_8 * V_9 ,
const struct V_84 * V_230 ,
struct V_84 * V_97 )
{
V_97 -> V_87 = V_230 -> V_87 ;
V_97 -> V_88 = F_101 ( V_230 -> V_88 , V_9 -> V_11 ,
V_9 -> V_10 ) ;
}
static V_19 F_112 ( struct V_8 * V_9 ,
const struct V_84 * V_230 )
{
if ( V_9 -> V_117 & V_235 ) {
return F_113 ( V_236 ,
F_101 ( V_230 -> V_88 ,
V_9 -> V_13 ,
V_9 -> V_12 ) ,
V_230 -> V_87 ) ;
} else {
return F_101 ( V_230 -> V_88 , V_9 -> V_13 ,
V_9 -> V_12 ) +
( unsigned ) V_230 -> V_87 ;
}
}
static int F_114 ( struct V_104 * V_105 , int V_237 , int V_238 ,
int * V_239 , int V_240 ,
const V_43 * V_67 , int V_241 )
{
int V_71 ;
F_21 ( V_240 > V_143 ) ;
F_115 ( & V_105 -> V_127 ) ;
V_71 = F_116 ( V_105 -> V_128 , V_237 , V_238 , V_239 , V_240 ,
V_67 , V_241 , V_105 -> V_133 ) ;
F_117 ( & V_105 -> V_127 ) ;
return V_71 ;
}
static void F_118 ( struct V_104 * V_229 ,
struct V_8 * V_9 ,
const struct V_84 * V_230 ,
struct V_187 * V_242 ,
V_19 * V_243 )
{
V_19 V_244 = F_112 ( V_9 , V_230 ) ;
int V_237 ;
int V_2 ;
F_119 ( V_242 ) ;
if ( V_243 )
* V_243 = V_244 ;
V_237 = F_120 ( V_229 -> V_128 , V_9 -> V_115 , V_9 -> type ,
V_9 -> V_18 ) ;
if ( V_237 < 0 ) {
F_20 ( L_65 ,
V_9 -> V_65 , V_9 -> V_115 , V_9 -> type , V_9 -> V_18 ) ;
return;
}
if ( V_9 -> V_18 > F_121 ( V_242 -> V_156 ) ) {
F_122 ( L_66 ,
V_9 -> V_65 , V_9 -> V_115 , V_9 -> type , V_9 -> V_18 ,
F_121 ( V_242 -> V_156 ) ) ;
return;
}
V_2 = F_114 ( V_229 , V_237 , V_244 , V_242 -> V_156 , V_9 -> V_18 ,
V_229 -> V_130 , V_229 -> V_137 ) ;
if ( V_2 < 0 ) {
F_20 ( L_67 ,
V_2 , V_237 , V_9 -> V_65 , V_9 -> V_115 , V_9 -> type ,
V_9 -> V_18 ) ;
return;
}
V_242 -> V_18 = V_2 ;
}
static void F_123 ( struct V_104 * V_229 ,
struct V_8 * V_9 ,
struct V_187 * V_189 )
{
int V_46 ;
F_21 ( V_189 -> V_188 != - 1 ) ;
if ( F_124 ( V_9 ) ) {
int V_245 = 0 ;
for ( V_46 = 0 ; V_46 < V_189 -> V_18 ; V_46 ++ ) {
if ( F_125 ( V_229 , V_189 -> V_156 [ V_46 ] ) ) {
V_245 ++ ;
continue;
}
if ( V_245 )
V_189 -> V_156 [ V_46 - V_245 ] = V_189 -> V_156 [ V_46 ] ;
}
V_189 -> V_18 -= V_245 ;
if ( V_189 -> V_18 > 0 )
V_189 -> V_188 = V_189 -> V_156 [ 0 ] ;
} else {
for ( V_46 = V_189 -> V_18 - 1 ; V_46 >= 0 ; V_46 -- ) {
if ( F_125 ( V_229 , V_189 -> V_156 [ V_46 ] ) )
V_189 -> V_156 [ V_46 ] = V_190 ;
else
V_189 -> V_188 = V_189 -> V_156 [ V_46 ] ;
}
}
}
static void F_126 ( struct V_104 * V_229 ,
struct V_8 * V_9 ,
V_19 V_244 ,
struct V_187 * V_246 )
{
int V_46 ;
int V_247 = - 1 ;
if ( ! V_229 -> V_132 )
return;
for ( V_46 = 0 ; V_46 < V_246 -> V_18 ; V_46 ++ ) {
int V_157 = V_246 -> V_156 [ V_46 ] ;
if ( V_157 != V_190 &&
V_229 -> V_132 [ V_157 ] !=
V_140 ) {
break;
}
}
if ( V_46 == V_246 -> V_18 )
return;
for ( V_46 = 0 ; V_46 < V_246 -> V_18 ; V_46 ++ ) {
int V_157 = V_246 -> V_156 [ V_46 ] ;
V_19 V_158 ;
if ( V_157 == V_190 )
continue;
V_158 = V_229 -> V_132 [ V_157 ] ;
if ( V_158 < V_248 &&
( F_113 ( V_236 ,
V_244 , V_157 ) >> 16 ) >= V_158 ) {
if ( V_247 < 0 )
V_247 = V_46 ;
} else {
V_247 = V_46 ;
break;
}
}
if ( V_247 < 0 )
return;
V_246 -> V_188 = V_246 -> V_156 [ V_247 ] ;
if ( F_124 ( V_9 ) && V_247 > 0 ) {
for ( V_46 = V_247 ; V_46 > 0 ; V_46 -- )
V_246 -> V_156 [ V_46 ] = V_246 -> V_156 [ V_46 - 1 ] ;
V_246 -> V_156 [ 0 ] = V_246 -> V_188 ;
}
}
static void F_127 ( struct V_104 * V_229 ,
struct V_8 * V_9 ,
const struct V_84 * V_230 ,
struct V_187 * V_249 )
{
struct V_84 V_97 ;
struct V_89 * V_95 ;
int V_46 ;
F_111 ( V_9 , V_230 , & V_97 ) ;
F_119 ( V_249 ) ;
V_95 = F_32 ( & V_229 -> V_125 , V_97 ) ;
if ( V_95 ) {
for ( V_46 = 0 ; V_46 < V_95 -> V_125 . V_2 ; V_46 ++ ) {
if ( F_125 ( V_229 , V_95 -> V_125 . V_156 [ V_46 ] ) ) {
if ( F_124 ( V_9 ) )
continue;
V_249 -> V_156 [ V_249 -> V_18 ++ ] = V_190 ;
} else {
V_249 -> V_156 [ V_249 -> V_18 ++ ] = V_95 -> V_125 . V_156 [ V_46 ] ;
}
}
for ( V_46 = 0 ; V_46 < V_249 -> V_18 ; V_46 ++ ) {
if ( V_249 -> V_156 [ V_46 ] != V_190 ) {
V_249 -> V_188 = V_249 -> V_156 [ V_46 ] ;
break;
}
}
}
V_95 = F_32 ( & V_229 -> V_126 , V_97 ) ;
if ( V_95 )
V_249 -> V_188 = V_95 -> V_126 . V_157 ;
}
void F_128 ( struct V_104 * V_229 ,
const struct V_84 * V_230 ,
struct V_187 * V_246 ,
struct V_187 * V_207 )
{
struct V_8 * V_9 ;
V_19 V_244 ;
V_9 = F_38 ( V_229 , V_230 -> V_87 ) ;
if ( ! V_9 ) {
F_119 ( V_246 ) ;
F_119 ( V_207 ) ;
goto V_250;
}
F_118 ( V_229 , V_9 , V_230 , V_246 , & V_244 ) ;
F_123 ( V_229 , V_9 , V_246 ) ;
F_126 ( V_229 , V_9 , V_244 , V_246 ) ;
F_127 ( V_229 , V_9 , V_230 , V_207 ) ;
if ( ! V_207 -> V_18 ) {
memcpy ( V_207 -> V_156 , V_246 -> V_156 , V_246 -> V_18 * sizeof( V_246 -> V_156 [ 0 ] ) ) ;
V_207 -> V_18 = V_246 -> V_18 ;
if ( V_207 -> V_188 == - 1 )
V_207 -> V_188 = V_246 -> V_188 ;
}
V_250:
F_88 ( ! F_98 ( V_246 ) || ! F_98 ( V_207 ) ) ;
}
int F_129 ( struct V_104 * V_229 ,
const struct V_84 * V_230 )
{
struct V_187 V_246 , V_207 ;
F_128 ( V_229 , V_230 , & V_246 , & V_207 ) ;
return V_207 . V_188 ;
}
