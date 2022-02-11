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
static struct V_35 * F_16 ( void * V_36 , void * V_15 )
{
struct V_35 * V_37 ;
int V_38 = - V_22 ;
int V_39 , V_24 ;
void * * V_14 = & V_36 ;
void * V_40 = V_36 ;
V_19 V_41 ;
V_19 V_42 ;
F_5 ( L_10 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_37 = F_17 ( sizeof( * V_37 ) , V_26 ) ;
if ( V_37 == NULL )
return F_18 ( - V_27 ) ;
V_37 -> V_43 = 2 ;
V_37 -> V_44 = 5 ;
V_37 -> V_45 = 19 ;
V_37 -> V_46 = 0 ;
F_6 ( V_14 , V_15 , 4 * sizeof( V_19 ) , V_20 ) ;
V_41 = F_7 ( V_14 ) ;
if ( V_41 != V_47 ) {
F_19 ( L_11 ,
( unsigned int ) V_41 , ( unsigned int ) V_47 ) ;
goto V_20;
}
V_37 -> V_48 = F_7 ( V_14 ) ;
V_37 -> V_49 = F_7 ( V_14 ) ;
V_37 -> V_50 = F_7 ( V_14 ) ;
V_37 -> V_51 = F_9 ( V_37 -> V_48 , sizeof( * V_37 -> V_51 ) , V_26 ) ;
if ( V_37 -> V_51 == NULL )
goto V_52;
V_37 -> V_53 = F_9 ( V_37 -> V_49 , sizeof( * V_37 -> V_53 ) , V_26 ) ;
if ( V_37 -> V_53 == NULL )
goto V_52;
for ( V_39 = 0 ; V_39 < V_37 -> V_48 ; V_39 ++ ) {
int V_18 = 0 ;
V_19 V_54 ;
struct V_55 * V_7 ;
F_15 ( V_14 , V_15 , V_54 , V_20 ) ;
if ( V_54 == 0 ) {
V_37 -> V_51 [ V_39 ] = NULL ;
continue;
}
F_5 ( L_12 ,
V_39 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_15 ) ;
switch ( V_54 ) {
case V_56 :
V_18 = sizeof( struct V_16 ) ;
break;
case V_57 :
V_18 = sizeof( struct V_23 ) ;
break;
case V_58 :
V_18 = sizeof( struct V_29 ) ;
break;
case V_59 :
V_18 = sizeof( struct V_32 ) ;
break;
case V_60 :
V_18 = sizeof( struct V_34 ) ;
break;
default:
V_38 = - V_22 ;
goto V_20;
}
F_20 ( V_18 == 0 ) ;
V_7 = V_37 -> V_51 [ V_39 ] = F_17 ( V_18 , V_26 ) ;
if ( V_7 == NULL )
goto V_52;
F_6 ( V_14 , V_15 , 4 * sizeof( V_19 ) , V_20 ) ;
V_7 -> V_61 = F_7 ( V_14 ) ;
V_7 -> type = F_21 ( V_14 ) ;
V_7 -> V_54 = F_22 ( V_14 ) ;
V_7 -> V_62 = F_22 ( V_14 ) ;
V_7 -> V_63 = F_7 ( V_14 ) ;
V_7 -> V_18 = F_7 ( V_14 ) ;
F_5 ( L_13 ,
V_7 -> V_18 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_15 ) ;
V_7 -> V_64 = F_9 ( V_7 -> V_18 , sizeof( V_65 ) , V_26 ) ;
if ( V_7 -> V_64 == NULL )
goto V_52;
V_7 -> V_66 = F_9 ( V_7 -> V_18 , sizeof( V_19 ) , V_26 ) ;
if ( V_7 -> V_66 == NULL )
goto V_52;
V_7 -> V_67 = 0 ;
F_6 ( V_14 , V_15 , V_7 -> V_18 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_18 ; V_24 ++ )
V_7 -> V_64 [ V_24 ] = F_7 ( V_14 ) ;
switch ( V_7 -> V_54 ) {
case V_56 :
V_38 = F_4 ( V_14 , V_15 ,
(struct V_16 * ) V_7 ) ;
if ( V_38 < 0 )
goto V_20;
break;
case V_57 :
V_38 = F_8 ( V_14 , V_15 ,
(struct V_23 * ) V_7 ) ;
if ( V_38 < 0 )
goto V_20;
break;
case V_58 :
V_38 = F_10 ( V_14 , V_15 ,
(struct V_29 * ) V_7 ) ;
if ( V_38 < 0 )
goto V_20;
break;
case V_59 :
V_38 = F_12 ( V_14 , V_15 ,
(struct V_32 * ) V_7 ) ;
if ( V_38 < 0 )
goto V_20;
break;
case V_60 :
V_38 = F_13 ( V_14 , V_15 ,
(struct V_34 * ) V_7 ) ;
if ( V_38 < 0 )
goto V_20;
break;
}
}
F_5 ( L_14 , V_37 -> V_53 ) ;
for ( V_39 = 0 ; V_39 < V_37 -> V_49 ; V_39 ++ ) {
V_19 V_68 ;
struct V_69 * V_70 ;
F_15 ( V_14 , V_15 , V_68 , V_20 ) ;
if ( ! V_68 ) {
F_5 ( L_15 ,
V_39 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_15 ) ;
V_37 -> V_53 [ V_39 ] = NULL ;
continue;
}
F_5 ( L_16 ,
V_39 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_15 ) ;
F_15 ( V_14 , V_15 , V_68 , V_20 ) ;
#if V_71 == 32
V_38 = - V_22 ;
if ( V_68 > ( V_72 - sizeof( * V_70 ) )
/ sizeof( struct V_73 ) )
goto V_20;
#endif
V_70 = V_37 -> V_53 [ V_39 ] = F_23 ( sizeof( * V_70 ) +
V_68 * sizeof( struct V_73 ) ,
V_26 ) ;
if ( V_70 == NULL )
goto V_52;
F_5 ( L_17 , V_39 , V_70 ) ;
V_70 -> V_2 = V_68 ;
F_24 ( V_14 , V_15 , & V_70 -> V_74 , 4 , V_20 ) ;
F_6 ( V_14 , V_15 , V_70 -> V_2 * 3 * sizeof( V_19 ) , V_20 ) ;
for ( V_24 = 0 ; V_24 < V_70 -> V_2 ; V_24 ++ ) {
V_70 -> V_75 [ V_24 ] . V_76 = F_7 ( V_14 ) ;
V_70 -> V_75 [ V_24 ] . V_77 = F_7 ( V_14 ) ;
V_70 -> V_75 [ V_24 ] . V_78 = F_7 ( V_14 ) ;
}
}
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_38 = F_14 ( V_14 , V_15 ) ;
if ( V_38 < 0 )
goto V_79;
}
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) , V_79 ) ;
V_37 -> V_43 = F_7 ( V_14 ) ;
V_37 -> V_44 = F_7 ( V_14 ) ;
V_37 -> V_45 = F_7 ( V_14 ) ;
F_5 ( L_18 ,
V_37 -> V_43 ) ;
F_5 ( L_19 ,
V_37 -> V_44 ) ;
F_5 ( L_20 ,
V_37 -> V_45 ) ;
F_6 ( V_14 , V_15 , sizeof( V_19 ) , V_79 ) ;
V_37 -> V_46 = F_7 ( V_14 ) ;
F_5 ( L_21 ,
V_37 -> V_46 ) ;
F_6 ( V_14 , V_15 , sizeof( V_80 ) , V_79 ) ;
V_37 -> V_81 = F_22 ( V_14 ) ;
F_5 ( L_22 ,
V_37 -> V_81 ) ;
F_6 ( V_14 , V_15 , sizeof( V_80 ) + sizeof( V_19 ) , V_79 ) ;
* V_14 += sizeof( V_80 ) + sizeof( V_19 ) ;
F_6 ( V_14 , V_15 , sizeof( V_80 ) , V_79 ) ;
V_37 -> V_82 = F_22 ( V_14 ) ;
F_5 ( L_23 ,
V_37 -> V_82 ) ;
V_79:
F_5 ( L_24 ) ;
return V_37 ;
V_52:
V_38 = - V_27 ;
V_20:
F_5 ( L_25 , V_38 ) ;
F_25 ( V_37 ) ;
return F_18 ( V_38 ) ;
}
static int F_26 ( struct V_83 V_84 , struct V_83 V_70 )
{
if ( V_84 . V_85 < V_70 . V_85 )
return - 1 ;
if ( V_84 . V_85 > V_70 . V_85 )
return 1 ;
if ( V_84 . V_86 < V_70 . V_86 )
return - 1 ;
if ( V_84 . V_86 > V_70 . V_86 )
return 1 ;
return 0 ;
}
static int F_27 ( struct V_87 * V_88 ,
struct V_89 * V_90 )
{
struct V_91 * * V_14 = & V_90 -> V_91 ;
struct V_91 * V_92 = NULL ;
struct V_87 * V_93 = NULL ;
int V_37 ;
F_5 ( L_26 , * ( V_94 * ) & V_88 -> V_95 , V_88 ) ;
while ( * V_14 ) {
V_92 = * V_14 ;
V_93 = F_28 ( V_92 , struct V_87 , V_96 ) ;
V_37 = F_26 ( V_88 -> V_95 , V_93 -> V_95 ) ;
if ( V_37 < 0 )
V_14 = & ( * V_14 ) -> V_97 ;
else if ( V_37 > 0 )
V_14 = & ( * V_14 ) -> V_98 ;
else
return - V_99 ;
}
F_29 ( & V_88 -> V_96 , V_92 , V_14 ) ;
F_30 ( & V_88 -> V_96 , V_90 ) ;
return 0 ;
}
static struct V_87 * F_31 ( struct V_89 * V_90 ,
struct V_83 V_95 )
{
struct V_91 * V_100 = V_90 -> V_91 ;
struct V_87 * V_93 ;
int V_37 ;
while ( V_100 ) {
V_93 = F_28 ( V_100 , struct V_87 , V_96 ) ;
V_37 = F_26 ( V_95 , V_93 -> V_95 ) ;
if ( V_37 < 0 ) {
V_100 = V_100 -> V_97 ;
} else if ( V_37 > 0 ) {
V_100 = V_100 -> V_98 ;
} else {
F_5 ( L_27 ,
V_95 . V_85 , V_95 . V_86 , V_93 ) ;
return V_93 ;
}
}
return NULL ;
}
static int F_32 ( struct V_89 * V_90 , struct V_83 V_95 )
{
struct V_87 * V_93 = F_31 ( V_90 , V_95 ) ;
if ( V_93 ) {
F_5 ( L_28 , V_95 . V_85 , V_95 . V_86 ,
V_93 ) ;
F_33 ( & V_93 -> V_96 , V_90 ) ;
F_34 ( V_93 ) ;
return 0 ;
}
F_5 ( L_29 , V_95 . V_85 , V_95 . V_86 ) ;
return - V_101 ;
}
static int F_35 ( struct V_89 * V_90 , struct V_8 * V_88 )
{
struct V_91 * * V_14 = & V_90 -> V_91 ;
struct V_91 * V_92 = NULL ;
struct V_8 * V_9 = NULL ;
while ( * V_14 ) {
V_92 = * V_14 ;
V_9 = F_28 ( V_92 , struct V_8 , V_96 ) ;
if ( V_88 -> V_61 < V_9 -> V_61 )
V_14 = & ( * V_14 ) -> V_97 ;
else if ( V_88 -> V_61 > V_9 -> V_61 )
V_14 = & ( * V_14 ) -> V_98 ;
else
return - V_99 ;
}
F_29 ( & V_88 -> V_96 , V_92 , V_14 ) ;
F_30 ( & V_88 -> V_96 , V_90 ) ;
return 0 ;
}
static struct V_8 * F_36 ( struct V_89 * V_90 , V_94 V_61 )
{
struct V_8 * V_9 ;
struct V_91 * V_100 = V_90 -> V_91 ;
while ( V_100 ) {
V_9 = F_28 ( V_100 , struct V_8 , V_96 ) ;
if ( V_61 < V_9 -> V_61 )
V_100 = V_100 -> V_97 ;
else if ( V_61 > V_9 -> V_61 )
V_100 = V_100 -> V_98 ;
else
return V_9 ;
}
return NULL ;
}
struct V_8 * F_37 ( struct V_102 * V_103 , V_94 V_61 )
{
return F_36 ( & V_103 -> V_104 , V_61 ) ;
}
const char * F_38 ( struct V_102 * V_103 , V_94 V_61 )
{
struct V_8 * V_9 ;
if ( V_61 == V_105 )
return NULL ;
if ( F_39 ( V_61 > ( V_94 ) V_106 ) )
return NULL ;
V_9 = F_36 ( & V_103 -> V_104 , ( int ) V_61 ) ;
return V_9 ? V_9 -> V_107 : NULL ;
}
int F_40 ( struct V_102 * V_103 , const char * V_107 )
{
struct V_91 * V_108 ;
for ( V_108 = F_41 ( & V_103 -> V_104 ) ; V_108 ; V_108 = F_42 ( V_108 ) ) {
struct V_8 * V_9 =
F_28 ( V_108 , struct V_8 , V_96 ) ;
if ( V_9 -> V_107 && strcmp ( V_9 -> V_107 , V_107 ) == 0 )
return V_9 -> V_61 ;
}
return - V_101 ;
}
static void F_43 ( struct V_89 * V_90 , struct V_8 * V_9 )
{
F_33 ( & V_9 -> V_96 , V_90 ) ;
F_34 ( V_9 -> V_107 ) ;
F_34 ( V_9 ) ;
}
static int F_44 ( void * * V_14 , void * V_15 , struct V_8 * V_9 )
{
V_80 V_109 , V_110 ;
unsigned V_2 , V_111 ;
void * V_112 ;
F_6 ( V_14 , V_15 , 2 + 4 , V_20 ) ;
V_109 = F_22 ( V_14 ) ;
V_110 = F_22 ( V_14 ) ;
if ( V_109 < 5 ) {
F_45 ( L_30 , V_109 , V_110 ) ;
return - V_22 ;
}
if ( V_110 > 9 ) {
F_45 ( L_31 , V_109 , V_110 ) ;
return - V_22 ;
}
V_2 = F_7 ( V_14 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_112 = * V_14 + V_2 ;
V_9 -> type = F_22 ( V_14 ) ;
V_9 -> V_18 = F_22 ( V_14 ) ;
V_9 -> V_113 = F_22 ( V_14 ) ;
V_9 -> V_114 = F_22 ( V_14 ) ;
V_9 -> V_11 = F_7 ( V_14 ) ;
V_9 -> V_13 = F_7 ( V_14 ) ;
* V_14 += 4 + 4 ;
* V_14 += 4 ;
* V_14 += 8 + 4 ;
V_111 = F_7 ( V_14 ) ;
while ( V_111 -- ) {
* V_14 += 8 ;
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
V_111 = F_7 ( V_14 ) ;
* V_14 += V_111 * ( 8 + 8 ) ;
* V_14 += 8 ;
V_9 -> V_115 = F_46 ( V_14 ) ;
* V_14 += 4 ;
if ( V_109 >= 7 )
* V_14 += 1 ;
if ( V_109 >= 8 )
* V_14 += 8 + 8 ;
if ( V_109 >= 9 ) {
V_111 = F_7 ( V_14 ) ;
* V_14 += V_111 * 8 ;
* V_14 += 8 ;
* V_14 += 1 ;
V_9 -> V_116 = F_46 ( V_14 ) ;
V_9 -> V_117 = F_46 ( V_14 ) ;
} else {
V_9 -> V_116 = - 1 ;
V_9 -> V_117 = - 1 ;
}
* V_14 = V_112 ;
F_3 ( V_9 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_47 ( void * * V_14 , void * V_15 , struct V_102 * V_103 )
{
struct V_8 * V_9 ;
V_19 V_111 , V_2 ;
V_94 V_85 ;
F_15 ( V_14 , V_15 , V_111 , V_20 ) ;
F_5 ( L_32 , V_111 ) ;
while ( V_111 -- ) {
F_48 ( V_14 , V_15 , V_85 , V_20 ) ;
F_15 ( V_14 , V_15 , V_2 , V_20 ) ;
F_5 ( L_33 , V_85 , V_2 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_9 = F_36 ( & V_103 -> V_104 , V_85 ) ;
if ( V_9 ) {
char * V_107 = F_49 ( * V_14 , V_2 , V_26 ) ;
if ( ! V_107 )
return - V_27 ;
F_34 ( V_9 -> V_107 ) ;
V_9 -> V_107 = V_107 ;
F_5 ( L_34 , V_9 -> V_107 ) ;
}
* V_14 += V_2 ;
}
return 0 ;
V_20:
return - V_22 ;
}
void F_50 ( struct V_102 * V_103 )
{
F_5 ( L_35 , V_103 ) ;
if ( V_103 -> V_118 )
F_25 ( V_103 -> V_118 ) ;
while ( ! F_51 ( & V_103 -> V_119 ) ) {
struct V_87 * V_93 =
F_28 ( F_41 ( & V_103 -> V_119 ) ,
struct V_87 , V_96 ) ;
F_33 ( & V_93 -> V_96 , & V_103 -> V_119 ) ;
F_34 ( V_93 ) ;
}
while ( ! F_51 ( & V_103 -> V_120 ) ) {
struct V_87 * V_93 =
F_28 ( F_41 ( & V_103 -> V_120 ) ,
struct V_87 , V_96 ) ;
F_33 ( & V_93 -> V_96 , & V_103 -> V_120 ) ;
F_34 ( V_93 ) ;
}
while ( ! F_51 ( & V_103 -> V_104 ) ) {
struct V_8 * V_9 =
F_28 ( F_41 ( & V_103 -> V_104 ) ,
struct V_8 , V_96 ) ;
F_43 ( & V_103 -> V_104 , V_9 ) ;
}
F_34 ( V_103 -> V_121 ) ;
F_34 ( V_103 -> V_122 ) ;
F_34 ( V_103 -> V_123 ) ;
F_34 ( V_103 -> V_124 ) ;
F_34 ( V_103 ) ;
}
static int F_52 ( struct V_102 * V_103 , int V_125 )
{
V_80 * V_3 ;
V_19 * V_63 ;
struct V_126 * V_127 ;
int V_39 ;
V_3 = F_53 ( V_103 -> V_121 , V_125 * sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
return - V_27 ;
V_103 -> V_121 = V_3 ;
V_63 = F_53 ( V_103 -> V_122 , V_125 * sizeof( * V_63 ) , V_26 ) ;
if ( ! V_63 )
return - V_27 ;
V_103 -> V_122 = V_63 ;
V_127 = F_53 ( V_103 -> V_123 , V_125 * sizeof( * V_127 ) , V_26 ) ;
if ( ! V_127 )
return - V_27 ;
V_103 -> V_123 = V_127 ;
for ( V_39 = V_103 -> V_128 ; V_39 < V_125 ; V_39 ++ ) {
V_103 -> V_121 [ V_39 ] = 0 ;
V_103 -> V_122 [ V_39 ] = V_129 ;
memset ( V_103 -> V_123 + V_39 , 0 , sizeof( * V_103 -> V_123 ) ) ;
}
if ( V_103 -> V_124 ) {
V_19 * V_130 ;
V_130 = F_53 ( V_103 -> V_124 ,
V_125 * sizeof( * V_130 ) , V_26 ) ;
if ( ! V_130 )
return - V_27 ;
V_103 -> V_124 = V_130 ;
for ( V_39 = V_103 -> V_128 ; V_39 < V_125 ; V_39 ++ )
V_103 -> V_124 [ V_39 ] =
V_131 ;
}
V_103 -> V_128 = V_125 ;
return 0 ;
}
static int F_54 ( void * * V_14 , void * V_15 ,
const char * V_132 , V_80 * V_133 )
{
V_80 V_134 ;
F_11 ( V_14 , V_15 , V_134 , V_135 ) ;
if ( V_134 >= 7 ) {
V_80 V_136 ;
F_11 ( V_14 , V_15 , V_136 , V_135 ) ;
if ( V_136 > V_137 ) {
F_45 ( L_36 ,
V_134 , V_136 ,
V_137 , V_132 ) ;
return - V_22 ;
}
* V_14 += 4 ;
F_11 ( V_14 , V_15 , V_134 , V_135 ) ;
F_11 ( V_14 , V_15 , V_136 , V_135 ) ;
if ( V_136 > V_138 ) {
F_45 ( L_37 ,
V_134 , V_136 ,
V_138 , V_132 ) ;
return - V_22 ;
}
* V_14 += 4 ;
} else {
T_1 V_139 ;
* V_14 -= 1 ;
F_55 ( V_14 , V_15 , V_139 , V_135 ) ;
if ( V_139 < 6 ) {
F_45 ( L_38 ,
V_139 , V_132 ) ;
return - V_22 ;
}
V_134 = 0 ;
}
* V_133 = V_134 ;
return 0 ;
V_135:
return - V_22 ;
}
static int F_56 ( void * * V_14 , void * V_15 , struct V_102 * V_103 ,
bool V_140 )
{
V_19 V_100 ;
F_15 ( V_14 , V_15 , V_100 , V_135 ) ;
while ( V_100 -- ) {
struct V_8 * V_9 ;
V_94 V_85 ;
int V_141 ;
F_48 ( V_14 , V_15 , V_85 , V_135 ) ;
V_9 = F_36 ( & V_103 -> V_104 , V_85 ) ;
if ( ! V_140 || ! V_9 ) {
V_9 = F_17 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
V_9 -> V_61 = V_85 ;
V_141 = F_35 ( & V_103 -> V_104 , V_9 ) ;
if ( V_141 ) {
F_34 ( V_9 ) ;
return V_141 ;
}
}
V_141 = F_44 ( V_14 , V_15 , V_9 ) ;
if ( V_141 )
return V_141 ;
}
return 0 ;
V_135:
return - V_22 ;
}
static int F_57 ( void * * V_14 , void * V_15 , struct V_102 * V_103 )
{
return F_56 ( V_14 , V_15 , V_103 , false ) ;
}
static int F_58 ( void * * V_14 , void * V_15 , struct V_102 * V_103 )
{
return F_56 ( V_14 , V_15 , V_103 , true ) ;
}
static int F_59 ( void * * V_14 , void * V_15 , struct V_102 * V_103 ,
bool V_140 )
{
V_19 V_100 ;
F_15 ( V_14 , V_15 , V_100 , V_135 ) ;
while ( V_100 -- ) {
struct V_83 V_95 ;
V_19 V_2 , V_39 ;
int V_141 ;
V_141 = F_60 ( V_14 , V_15 , & V_95 ) ;
if ( V_141 )
return V_141 ;
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
V_141 = F_32 ( & V_103 -> V_119 , V_95 ) ;
F_20 ( ! V_140 && V_141 != - V_101 ) ;
if ( ! V_140 || V_2 > 0 ) {
struct V_87 * V_93 ;
F_6 ( V_14 , V_15 , V_2 * sizeof( V_19 ) , V_135 ) ;
if ( V_2 > ( V_142 - sizeof( * V_93 ) ) / sizeof( V_19 ) )
return - V_22 ;
V_93 = F_17 ( sizeof( * V_93 ) + V_2 * sizeof( V_19 ) , V_26 ) ;
if ( ! V_93 )
return - V_27 ;
V_93 -> V_95 = V_95 ;
V_93 -> V_119 . V_2 = V_2 ;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ )
V_93 -> V_119 . V_143 [ V_39 ] = F_7 ( V_14 ) ;
V_141 = F_27 ( V_93 , & V_103 -> V_119 ) ;
if ( V_141 ) {
F_34 ( V_93 ) ;
return V_141 ;
}
}
}
return 0 ;
V_135:
return - V_22 ;
}
static int F_61 ( void * * V_14 , void * V_15 , struct V_102 * V_103 )
{
return F_59 ( V_14 , V_15 , V_103 , false ) ;
}
static int F_62 ( void * * V_14 , void * V_15 , struct V_102 * V_103 )
{
return F_59 ( V_14 , V_15 , V_103 , true ) ;
}
static int F_63 ( void * * V_14 , void * V_15 , struct V_102 * V_103 ,
bool V_140 )
{
V_19 V_100 ;
F_15 ( V_14 , V_15 , V_100 , V_135 ) ;
while ( V_100 -- ) {
struct V_83 V_95 ;
V_19 V_144 ;
int V_141 ;
V_141 = F_60 ( V_14 , V_15 , & V_95 ) ;
if ( V_141 )
return V_141 ;
F_15 ( V_14 , V_15 , V_144 , V_135 ) ;
V_141 = F_32 ( & V_103 -> V_120 , V_95 ) ;
F_20 ( ! V_140 && V_141 != - V_101 ) ;
if ( ! V_140 || V_144 != ( V_19 ) - 1 ) {
struct V_87 * V_93 ;
V_93 = F_17 ( sizeof( * V_93 ) , V_26 ) ;
if ( ! V_93 )
return - V_27 ;
V_93 -> V_95 = V_95 ;
V_93 -> V_120 . V_144 = V_144 ;
V_141 = F_27 ( V_93 , & V_103 -> V_120 ) ;
if ( V_141 ) {
F_34 ( V_93 ) ;
return V_141 ;
}
}
}
return 0 ;
V_135:
return - V_22 ;
}
static int F_64 ( void * * V_14 , void * V_15 , struct V_102 * V_103 )
{
return F_63 ( V_14 , V_15 , V_103 , false ) ;
}
static int F_65 ( void * * V_14 , void * V_15 ,
struct V_102 * V_103 )
{
return F_63 ( V_14 , V_15 , V_103 , true ) ;
}
V_19 F_66 ( struct V_102 * V_103 , int V_144 )
{
F_20 ( V_144 >= V_103 -> V_128 ) ;
if ( ! V_103 -> V_124 )
return V_131 ;
return V_103 -> V_124 [ V_144 ] ;
}
static int F_67 ( struct V_102 * V_103 , int V_144 , V_19 V_145 )
{
F_20 ( V_144 >= V_103 -> V_128 ) ;
if ( ! V_103 -> V_124 ) {
int V_39 ;
V_103 -> V_124 = F_23 ( V_103 -> V_128 * sizeof( V_19 ) ,
V_26 ) ;
if ( ! V_103 -> V_124 )
return - V_27 ;
for ( V_39 = 0 ; V_39 < V_103 -> V_128 ; V_39 ++ )
V_103 -> V_124 [ V_39 ] =
V_131 ;
}
V_103 -> V_124 [ V_144 ] = V_145 ;
return 0 ;
}
static int F_68 ( void * * V_14 , void * V_15 ,
struct V_102 * V_103 )
{
V_19 V_2 , V_39 ;
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
if ( V_2 == 0 ) {
F_34 ( V_103 -> V_124 ) ;
V_103 -> V_124 = NULL ;
return 0 ;
}
if ( V_2 != V_103 -> V_128 )
goto V_135;
F_6 ( V_14 , V_15 , V_103 -> V_128 * sizeof( V_19 ) , V_135 ) ;
for ( V_39 = 0 ; V_39 < V_103 -> V_128 ; V_39 ++ ) {
int V_141 ;
V_141 = F_67 ( V_103 , V_39 , F_7 ( V_14 ) ) ;
if ( V_141 )
return V_141 ;
}
return 0 ;
V_135:
return - V_22 ;
}
static int F_69 ( void * * V_14 , void * V_15 ,
struct V_102 * V_103 )
{
V_19 V_100 ;
F_15 ( V_14 , V_15 , V_100 , V_135 ) ;
while ( V_100 -- ) {
V_19 V_144 , V_145 ;
int V_141 ;
F_15 ( V_14 , V_15 , V_144 , V_135 ) ;
F_15 ( V_14 , V_15 , V_145 , V_135 ) ;
V_141 = F_67 ( V_103 , V_144 , V_145 ) ;
if ( V_141 )
return V_141 ;
F_70 ( L_39 , V_144 , V_145 ) ;
}
return 0 ;
V_135:
return - V_22 ;
}
static int F_71 ( void * * V_14 , void * V_15 , struct V_102 * V_103 )
{
V_80 V_134 ;
V_19 V_146 = 0 ;
void * V_40 = * V_14 ;
V_19 V_125 ;
V_19 V_2 , V_39 ;
int V_38 ;
F_5 ( L_40 , V_147 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_38 = F_54 ( V_14 , V_15 , L_41 , & V_134 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_103 -> V_148 ) + sizeof( V_19 ) +
sizeof( V_103 -> V_149 ) + sizeof( V_103 -> V_150 ) , V_135 ) ;
F_72 ( V_14 , & V_103 -> V_148 , sizeof( V_103 -> V_148 ) ) ;
V_146 = V_103 -> V_146 = F_7 ( V_14 ) ;
F_72 ( V_14 , & V_103 -> V_149 , sizeof( V_103 -> V_149 ) ) ;
F_72 ( V_14 , & V_103 -> V_150 , sizeof( V_103 -> V_150 ) ) ;
V_38 = F_57 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
V_38 = F_47 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
F_15 ( V_14 , V_15 , V_103 -> V_151 , V_135 ) ;
F_15 ( V_14 , V_15 , V_103 -> V_115 , V_135 ) ;
F_15 ( V_14 , V_15 , V_125 , V_135 ) ;
V_38 = F_52 ( V_103 , V_125 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) +
V_103 -> V_128 * ( 1 + sizeof( * V_103 -> V_122 ) +
sizeof( * V_103 -> V_123 ) ) , V_135 ) ;
if ( F_7 ( V_14 ) != V_103 -> V_128 )
goto V_135;
F_72 ( V_14 , V_103 -> V_121 , V_103 -> V_128 ) ;
if ( F_7 ( V_14 ) != V_103 -> V_128 )
goto V_135;
for ( V_39 = 0 ; V_39 < V_103 -> V_128 ; V_39 ++ )
V_103 -> V_122 [ V_39 ] = F_7 ( V_14 ) ;
if ( F_7 ( V_14 ) != V_103 -> V_128 )
goto V_135;
F_72 ( V_14 , V_103 -> V_123 , V_103 -> V_128 * sizeof( * V_103 -> V_123 ) ) ;
for ( V_39 = 0 ; V_39 < V_103 -> V_128 ; V_39 ++ )
F_73 ( & V_103 -> V_123 [ V_39 ] ) ;
V_38 = F_61 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
if ( V_134 >= 1 ) {
V_38 = F_64 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
}
if ( V_134 >= 2 ) {
V_38 = F_68 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
} else {
F_34 ( V_103 -> V_124 ) ;
V_103 -> V_124 = NULL ;
}
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
V_103 -> V_118 = F_16 ( * V_14 , F_74 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_75 ( V_103 -> V_118 ) ) {
V_38 = F_76 ( V_103 -> V_118 ) ;
V_103 -> V_118 = NULL ;
goto V_20;
}
* V_14 += V_2 ;
* V_14 = V_15 ;
F_5 ( L_42 , V_103 -> V_146 , V_103 -> V_128 ) ;
return 0 ;
V_135:
V_38 = - V_22 ;
V_20:
F_19 ( L_43 ,
V_38 , V_146 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_40 , V_15 ) ;
F_77 ( V_152 , L_44 ,
V_153 , 16 , 1 ,
V_40 , V_15 - V_40 , true ) ;
return V_38 ;
}
struct V_102 * F_78 ( void * * V_14 , void * V_15 )
{
struct V_102 * V_103 ;
int V_141 ;
V_103 = F_17 ( sizeof( * V_103 ) , V_26 ) ;
if ( ! V_103 )
return F_18 ( - V_27 ) ;
V_103 -> V_119 = V_154 ;
V_103 -> V_120 = V_154 ;
F_79 ( & V_103 -> V_155 ) ;
V_141 = F_71 ( V_14 , V_15 , V_103 ) ;
if ( V_141 ) {
F_50 ( V_103 ) ;
return F_18 ( V_141 ) ;
}
return V_103 ;
}
struct V_102 * F_80 ( void * * V_14 , void * V_15 ,
struct V_102 * V_103 ,
struct V_156 * V_157 )
{
struct V_35 * V_158 = NULL ;
struct V_159 V_148 ;
V_19 V_146 = 0 ;
struct V_160 V_150 ;
T_2 V_2 ;
V_94 V_85 ;
T_3 V_161 ;
V_65 V_162 , V_125 ;
void * V_40 = * V_14 ;
int V_38 ;
V_80 V_134 ;
F_5 ( L_40 , V_147 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_38 = F_54 ( V_14 , V_15 , L_45 , & V_134 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_148 ) + sizeof( V_19 ) + sizeof( V_150 ) +
sizeof( V_94 ) + sizeof( V_19 ) , V_135 ) ;
F_72 ( V_14 , & V_148 , sizeof( V_148 ) ) ;
V_146 = F_7 ( V_14 ) ;
F_20 ( V_146 != V_103 -> V_146 + 1 ) ;
F_72 ( V_14 , & V_150 , sizeof( V_150 ) ) ;
V_161 = F_46 ( V_14 ) ;
V_162 = F_7 ( V_14 ) ;
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
if ( V_2 > 0 ) {
F_5 ( L_46 ,
V_2 , * V_14 , V_15 ) ;
return F_78 ( V_14 , F_74 ( * V_14 + V_2 , V_15 ) ) ;
}
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
if ( V_2 > 0 ) {
V_158 = F_16 ( * V_14 , F_74 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_75 ( V_158 ) ) {
V_38 = F_76 ( V_158 ) ;
V_158 = NULL ;
goto V_20;
}
* V_14 += V_2 ;
}
if ( V_162 >= 0 )
V_103 -> V_115 = V_162 ;
if ( V_161 >= 0 )
V_103 -> V_151 = V_161 ;
F_15 ( V_14 , V_15 , V_125 , V_135 ) ;
if ( V_125 >= 0 ) {
V_38 = F_52 ( V_103 , V_125 ) ;
if ( V_38 )
goto V_20;
}
V_103 -> V_146 ++ ;
V_103 -> V_150 = V_150 ;
if ( V_158 ) {
if ( V_103 -> V_118 )
F_25 ( V_103 -> V_118 ) ;
V_103 -> V_118 = V_158 ;
V_158 = NULL ;
}
V_38 = F_58 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
V_38 = F_47 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
while ( V_2 -- ) {
struct V_8 * V_9 ;
F_48 ( V_14 , V_15 , V_85 , V_135 ) ;
V_9 = F_36 ( & V_103 -> V_104 , V_85 ) ;
if ( V_9 )
F_43 ( & V_103 -> V_104 , V_9 ) ;
}
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
while ( V_2 -- ) {
V_19 V_144 ;
struct V_126 V_127 ;
F_15 ( V_14 , V_15 , V_144 , V_135 ) ;
F_24 ( V_14 , V_15 , & V_127 , sizeof( V_127 ) , V_135 ) ;
F_73 ( & V_127 ) ;
F_70 ( L_47 , V_144 ) ;
F_20 ( V_144 >= V_103 -> V_128 ) ;
V_103 -> V_121 [ V_144 ] |= V_5 | V_4 ;
V_103 -> V_123 [ V_144 ] = V_127 ;
}
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
while ( V_2 -- ) {
V_19 V_144 ;
V_80 V_163 ;
F_15 ( V_14 , V_15 , V_144 , V_135 ) ;
V_163 = * * ( V_80 * * ) V_14 ;
( * V_14 ) ++ ;
if ( V_163 == 0 )
V_163 = V_5 ;
if ( V_163 & V_5 )
F_70 ( L_48 , V_144 ) ;
if ( V_144 < V_103 -> V_128 )
V_103 -> V_121 [ V_144 ] ^= V_163 ;
}
F_15 ( V_14 , V_15 , V_2 , V_135 ) ;
while ( V_2 -- ) {
V_19 V_144 , V_164 ;
F_6 ( V_14 , V_15 , sizeof( V_19 ) * 2 , V_135 ) ;
V_144 = F_7 ( V_14 ) ;
V_164 = F_7 ( V_14 ) ;
F_70 ( L_49 , V_144 , V_164 ,
V_164 == V_165 ? L_50 :
( V_164 == V_129 ? L_51 : L_52 ) ) ;
if ( V_144 < V_103 -> V_128 )
V_103 -> V_122 [ V_144 ] = V_164 ;
}
V_38 = F_62 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
if ( V_134 >= 1 ) {
V_38 = F_65 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
}
if ( V_134 >= 2 ) {
V_38 = F_69 ( V_14 , V_15 , V_103 ) ;
if ( V_38 )
goto V_20;
}
* V_14 = V_15 ;
F_5 ( L_53 , V_103 -> V_146 , V_103 -> V_128 ) ;
return V_103 ;
V_135:
V_38 = - V_22 ;
V_20:
F_19 ( L_54 ,
V_38 , V_146 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_40 , V_15 ) ;
F_77 ( V_152 , L_44 ,
V_153 , 16 , 1 ,
V_40 , V_15 - V_40 , true ) ;
if ( V_158 )
F_25 ( V_158 ) ;
return F_18 ( V_38 ) ;
}
int F_81 ( struct V_166 * V_167 ,
V_94 V_164 , V_94 V_2 ,
V_94 * V_168 ,
V_94 * V_169 , V_94 * V_170 )
{
V_19 V_171 = F_82 ( V_167 -> V_172 ) ;
V_19 V_173 = F_82 ( V_167 -> V_174 ) ;
V_19 V_175 = F_82 ( V_167 -> V_176 ) ;
V_19 V_177 , V_178 , V_179 , V_180 ;
V_19 V_181 ;
V_94 V_6 , V_182 ;
F_5 ( L_55 , V_164 , V_2 ,
V_171 , V_173 ) ;
if ( V_173 == 0 || V_175 == 0 )
goto V_183;
V_181 = V_171 / V_173 ;
if ( V_181 == 0 )
goto V_183;
F_5 ( L_56 , V_171 , V_173 ,
V_181 ) ;
if ( ( V_173 & ~ V_184 ) != 0 )
goto V_183;
V_6 = V_164 ;
F_83 ( V_6 , V_173 ) ;
V_177 = V_6 ;
F_5 ( L_57 , V_164 , V_173 , V_177 ) ;
V_178 = V_177 / V_175 ;
V_179 = V_177 % V_175 ;
V_180 = V_178 / V_181 ;
* V_168 = V_180 * V_175 + V_179 ;
F_5 ( L_58 , V_180 , V_175 , ( unsigned int ) * V_168 ) ;
V_6 = V_164 ;
V_182 = F_83 ( V_6 , V_173 ) ;
* V_169 = V_182 + ( V_178 % V_181 ) * V_173 ;
* V_170 = F_84 ( V_94 , V_2 , V_173 - V_182 ) ;
F_5 ( L_59 , * V_169 , * V_170 ) ;
return 0 ;
V_183:
F_5 ( L_60 ) ;
* V_168 = 0 ;
* V_169 = 0 ;
* V_170 = 0 ;
return - V_22 ;
}
int F_85 ( struct V_102 * V_185 ,
struct V_186 * V_187 ,
struct V_188 * V_189 ,
struct V_83 * V_190 )
{
struct V_8 * V_9 ;
V_9 = F_36 ( & V_185 -> V_104 , V_187 -> V_85 ) ;
if ( ! V_9 )
return - V_191 ;
V_190 -> V_85 = V_187 -> V_85 ;
V_190 -> V_86 = F_86 ( V_9 -> V_114 , V_189 -> V_107 ,
V_189 -> V_192 ) ;
F_5 ( L_61 , V_147 , V_189 -> V_192 , V_189 -> V_107 ,
V_190 -> V_85 , V_190 -> V_86 ) ;
return 0 ;
}
static int F_87 ( struct V_102 * V_103 , int V_193 , int V_194 ,
int * V_195 , int V_196 ,
const T_4 * V_63 , int V_197 )
{
int V_70 ;
F_20 ( V_196 > V_198 ) ;
F_88 ( & V_103 -> V_155 ) ;
V_70 = F_89 ( V_103 -> V_118 , V_193 , V_194 , V_195 , V_196 ,
V_63 , V_197 , V_103 -> V_199 ) ;
F_90 ( & V_103 -> V_155 ) ;
return V_70 ;
}
static int F_91 ( struct V_102 * V_185 ,
struct V_8 * V_85 ,
struct V_83 V_95 , V_19 V_200 , int * V_143 )
{
int V_193 ;
int V_2 ;
V_193 = F_92 ( V_185 -> V_118 , V_85 -> V_113 ,
V_85 -> type , V_85 -> V_18 ) ;
if ( V_193 < 0 ) {
F_19 ( L_62 ,
V_95 . V_85 , V_85 -> V_113 , V_85 -> type ,
V_85 -> V_18 ) ;
return - V_101 ;
}
V_2 = F_87 ( V_185 , V_193 , V_200 , V_143 ,
F_84 ( int , V_85 -> V_18 , V_198 ) ,
V_185 -> V_122 , V_185 -> V_128 ) ;
if ( V_2 < 0 ) {
F_19 ( L_63 ,
V_2 , V_193 , V_95 . V_85 , V_85 -> V_113 ,
V_85 -> type , V_85 -> V_18 ) ;
return V_2 ;
}
return V_2 ;
}
static int F_93 ( struct V_102 * V_185 ,
struct V_8 * V_85 ,
int * V_143 , int V_2 , int * V_201 )
{
int V_202 = - 1 ;
int V_39 ;
if ( F_94 ( V_85 ) ) {
int V_203 = 0 ;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ ) {
if ( F_95 ( V_185 , V_143 [ V_39 ] ) ) {
V_203 ++ ;
continue;
}
if ( V_203 )
V_143 [ V_39 - V_203 ] = V_143 [ V_39 ] ;
}
V_2 -= V_203 ;
if ( V_2 > 0 )
V_202 = V_143 [ 0 ] ;
} else {
for ( V_39 = V_2 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( F_95 ( V_185 , V_143 [ V_39 ] ) )
V_143 [ V_39 ] = V_204 ;
else
V_202 = V_143 [ V_39 ] ;
}
}
* V_201 = V_202 ;
return V_2 ;
}
static void F_96 ( struct V_102 * V_185 , V_19 V_200 ,
struct V_8 * V_85 ,
int * V_143 , int V_2 , int * V_201 )
{
int V_39 ;
int V_205 = - 1 ;
if ( ! V_185 -> V_124 )
return;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ ) {
int V_144 = V_143 [ V_39 ] ;
if ( V_144 != V_204 &&
V_185 -> V_124 [ V_144 ] !=
V_131 ) {
break;
}
}
if ( V_39 == V_2 )
return;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ ) {
int V_144 = V_143 [ V_39 ] ;
V_19 V_145 ;
if ( V_144 == V_204 )
continue;
V_145 = V_185 -> V_124 [ V_144 ] ;
if ( V_145 < V_206 &&
( F_97 ( V_207 ,
V_200 , V_144 ) >> 16 ) >= V_145 ) {
if ( V_205 < 0 )
V_205 = V_39 ;
} else {
V_205 = V_39 ;
break;
}
}
if ( V_205 < 0 )
return;
* V_201 = V_143 [ V_205 ] ;
if ( F_94 ( V_85 ) && V_205 > 0 ) {
for ( V_39 = V_205 ; V_39 > 0 ; V_39 -- )
V_143 [ V_39 ] = V_143 [ V_39 - 1 ] ;
V_143 [ 0 ] = * V_201 ;
}
}
static int F_98 ( struct V_102 * V_185 ,
struct V_8 * V_85 , struct V_83 V_95 ,
int * V_143 , int V_2 , int * V_201 )
{
struct V_87 * V_93 ;
int V_208 ;
int V_209 ;
int V_39 ;
V_95 . V_86 = F_99 ( V_95 . V_86 , V_85 -> V_11 ,
V_85 -> V_10 ) ;
V_93 = F_31 ( & V_185 -> V_119 , V_95 ) ;
if ( V_93 ) {
V_208 = 0 ;
V_209 = - 1 ;
for ( V_39 = 0 ; V_39 < V_93 -> V_119 . V_2 ; V_39 ++ ) {
if ( F_95 ( V_185 , V_93 -> V_119 . V_143 [ V_39 ] ) ) {
if ( F_94 ( V_85 ) )
continue;
else
V_143 [ V_208 ++ ] = V_204 ;
} else {
V_143 [ V_208 ++ ] = V_93 -> V_119 . V_143 [ V_39 ] ;
}
}
for ( V_39 = 0 ; V_39 < V_208 ; V_39 ++ ) {
if ( V_143 [ V_39 ] != V_204 ) {
V_209 = V_143 [ V_39 ] ;
break;
}
}
} else {
V_208 = V_2 ;
V_209 = * V_201 ;
}
V_93 = F_31 ( & V_185 -> V_120 , V_95 ) ;
if ( V_93 )
V_209 = V_93 -> V_120 . V_144 ;
* V_201 = V_209 ;
return V_208 ;
}
int F_100 ( struct V_102 * V_185 , struct V_83 V_95 ,
int * V_143 , int * V_201 )
{
struct V_8 * V_85 ;
V_19 V_200 ;
int V_2 ;
V_85 = F_36 ( & V_185 -> V_104 , V_95 . V_85 ) ;
if ( ! V_85 ) {
* V_201 = - 1 ;
return - V_101 ;
}
if ( V_85 -> V_115 & V_210 ) {
V_200 = F_97 ( V_207 ,
F_99 ( V_95 . V_86 , V_85 -> V_13 ,
V_85 -> V_12 ) ,
V_95 . V_85 ) ;
} else {
V_200 = F_99 ( V_95 . V_86 , V_85 -> V_13 ,
V_85 -> V_12 ) +
( unsigned ) V_95 . V_85 ;
}
V_2 = F_91 ( V_185 , V_85 , V_95 , V_200 , V_143 ) ;
if ( V_2 < 0 ) {
* V_201 = - 1 ;
return V_2 ;
}
V_2 = F_93 ( V_185 , V_85 , V_143 , V_2 , V_201 ) ;
F_96 ( V_185 , V_200 , V_85 , V_143 , V_2 , V_201 ) ;
V_2 = F_98 ( V_185 , V_85 , V_95 , V_143 , V_2 , V_201 ) ;
return V_2 ;
}
int F_101 ( struct V_102 * V_185 , struct V_83 V_95 )
{
int V_143 [ V_198 ] ;
int V_201 ;
F_100 ( V_185 , V_95 , V_143 , & V_201 ) ;
return V_201 ;
}
