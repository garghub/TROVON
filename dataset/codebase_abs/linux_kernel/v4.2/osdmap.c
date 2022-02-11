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
V_79:
F_5 ( L_23 ) ;
return V_37 ;
V_52:
V_38 = - V_27 ;
V_20:
F_5 ( L_24 , V_38 ) ;
F_25 ( V_37 ) ;
return F_18 ( V_38 ) ;
}
static int F_26 ( struct V_82 V_83 , struct V_82 V_70 )
{
if ( V_83 . V_84 < V_70 . V_84 )
return - 1 ;
if ( V_83 . V_84 > V_70 . V_84 )
return 1 ;
if ( V_83 . V_85 < V_70 . V_85 )
return - 1 ;
if ( V_83 . V_85 > V_70 . V_85 )
return 1 ;
return 0 ;
}
static int F_27 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_90 * * V_14 = & V_89 -> V_90 ;
struct V_90 * V_91 = NULL ;
struct V_86 * V_92 = NULL ;
int V_37 ;
F_5 ( L_25 , * ( V_93 * ) & V_87 -> V_94 , V_87 ) ;
while ( * V_14 ) {
V_91 = * V_14 ;
V_92 = F_28 ( V_91 , struct V_86 , V_95 ) ;
V_37 = F_26 ( V_87 -> V_94 , V_92 -> V_94 ) ;
if ( V_37 < 0 )
V_14 = & ( * V_14 ) -> V_96 ;
else if ( V_37 > 0 )
V_14 = & ( * V_14 ) -> V_97 ;
else
return - V_98 ;
}
F_29 ( & V_87 -> V_95 , V_91 , V_14 ) ;
F_30 ( & V_87 -> V_95 , V_89 ) ;
return 0 ;
}
static struct V_86 * F_31 ( struct V_88 * V_89 ,
struct V_82 V_94 )
{
struct V_90 * V_99 = V_89 -> V_90 ;
struct V_86 * V_92 ;
int V_37 ;
while ( V_99 ) {
V_92 = F_28 ( V_99 , struct V_86 , V_95 ) ;
V_37 = F_26 ( V_94 , V_92 -> V_94 ) ;
if ( V_37 < 0 ) {
V_99 = V_99 -> V_96 ;
} else if ( V_37 > 0 ) {
V_99 = V_99 -> V_97 ;
} else {
F_5 ( L_26 ,
V_94 . V_84 , V_94 . V_85 , V_92 ) ;
return V_92 ;
}
}
return NULL ;
}
static int F_32 ( struct V_88 * V_89 , struct V_82 V_94 )
{
struct V_86 * V_92 = F_31 ( V_89 , V_94 ) ;
if ( V_92 ) {
F_5 ( L_27 , V_94 . V_84 , V_94 . V_85 ,
V_92 ) ;
F_33 ( & V_92 -> V_95 , V_89 ) ;
F_34 ( V_92 ) ;
return 0 ;
}
F_5 ( L_28 , V_94 . V_84 , V_94 . V_85 ) ;
return - V_100 ;
}
static int F_35 ( struct V_88 * V_89 , struct V_8 * V_87 )
{
struct V_90 * * V_14 = & V_89 -> V_90 ;
struct V_90 * V_91 = NULL ;
struct V_8 * V_9 = NULL ;
while ( * V_14 ) {
V_91 = * V_14 ;
V_9 = F_28 ( V_91 , struct V_8 , V_95 ) ;
if ( V_87 -> V_61 < V_9 -> V_61 )
V_14 = & ( * V_14 ) -> V_96 ;
else if ( V_87 -> V_61 > V_9 -> V_61 )
V_14 = & ( * V_14 ) -> V_97 ;
else
return - V_98 ;
}
F_29 ( & V_87 -> V_95 , V_91 , V_14 ) ;
F_30 ( & V_87 -> V_95 , V_89 ) ;
return 0 ;
}
static struct V_8 * F_36 ( struct V_88 * V_89 , V_93 V_61 )
{
struct V_8 * V_9 ;
struct V_90 * V_99 = V_89 -> V_90 ;
while ( V_99 ) {
V_9 = F_28 ( V_99 , struct V_8 , V_95 ) ;
if ( V_61 < V_9 -> V_61 )
V_99 = V_99 -> V_96 ;
else if ( V_61 > V_9 -> V_61 )
V_99 = V_99 -> V_97 ;
else
return V_9 ;
}
return NULL ;
}
struct V_8 * F_37 ( struct V_101 * V_102 , V_93 V_61 )
{
return F_36 ( & V_102 -> V_103 , V_61 ) ;
}
const char * F_38 ( struct V_101 * V_102 , V_93 V_61 )
{
struct V_8 * V_9 ;
if ( V_61 == V_104 )
return NULL ;
if ( F_39 ( V_61 > ( V_93 ) V_105 ) )
return NULL ;
V_9 = F_36 ( & V_102 -> V_103 , ( int ) V_61 ) ;
return V_9 ? V_9 -> V_106 : NULL ;
}
int F_40 ( struct V_101 * V_102 , const char * V_106 )
{
struct V_90 * V_107 ;
for ( V_107 = F_41 ( & V_102 -> V_103 ) ; V_107 ; V_107 = F_42 ( V_107 ) ) {
struct V_8 * V_9 =
F_28 ( V_107 , struct V_8 , V_95 ) ;
if ( V_9 -> V_106 && strcmp ( V_9 -> V_106 , V_106 ) == 0 )
return V_9 -> V_61 ;
}
return - V_100 ;
}
static void F_43 ( struct V_88 * V_89 , struct V_8 * V_9 )
{
F_33 ( & V_9 -> V_95 , V_89 ) ;
F_34 ( V_9 -> V_106 ) ;
F_34 ( V_9 ) ;
}
static int F_44 ( void * * V_14 , void * V_15 , struct V_8 * V_9 )
{
V_80 V_108 , V_109 ;
unsigned V_2 , V_110 ;
void * V_111 ;
F_6 ( V_14 , V_15 , 2 + 4 , V_20 ) ;
V_108 = F_22 ( V_14 ) ;
V_109 = F_22 ( V_14 ) ;
if ( V_108 < 5 ) {
F_45 ( L_29 , V_108 , V_109 ) ;
return - V_22 ;
}
if ( V_109 > 9 ) {
F_45 ( L_30 , V_108 , V_109 ) ;
return - V_22 ;
}
V_2 = F_7 ( V_14 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_111 = * V_14 + V_2 ;
V_9 -> type = F_22 ( V_14 ) ;
V_9 -> V_18 = F_22 ( V_14 ) ;
V_9 -> V_112 = F_22 ( V_14 ) ;
V_9 -> V_113 = F_22 ( V_14 ) ;
V_9 -> V_11 = F_7 ( V_14 ) ;
V_9 -> V_13 = F_7 ( V_14 ) ;
* V_14 += 4 + 4 ;
* V_14 += 4 ;
* V_14 += 8 + 4 ;
V_110 = F_7 ( V_14 ) ;
while ( V_110 -- ) {
* V_14 += 8 ;
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
V_110 = F_7 ( V_14 ) ;
* V_14 += V_110 * ( 8 + 8 ) ;
* V_14 += 8 ;
V_9 -> V_114 = F_46 ( V_14 ) ;
* V_14 += 4 ;
if ( V_108 >= 7 )
* V_14 += 1 ;
if ( V_108 >= 8 )
* V_14 += 8 + 8 ;
if ( V_108 >= 9 ) {
V_110 = F_7 ( V_14 ) ;
* V_14 += V_110 * 8 ;
* V_14 += 8 ;
* V_14 += 1 ;
V_9 -> V_115 = F_46 ( V_14 ) ;
V_9 -> V_116 = F_46 ( V_14 ) ;
} else {
V_9 -> V_115 = - 1 ;
V_9 -> V_116 = - 1 ;
}
* V_14 = V_111 ;
F_3 ( V_9 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_47 ( void * * V_14 , void * V_15 , struct V_101 * V_102 )
{
struct V_8 * V_9 ;
V_19 V_110 , V_2 ;
V_93 V_84 ;
F_15 ( V_14 , V_15 , V_110 , V_20 ) ;
F_5 ( L_31 , V_110 ) ;
while ( V_110 -- ) {
F_48 ( V_14 , V_15 , V_84 , V_20 ) ;
F_15 ( V_14 , V_15 , V_2 , V_20 ) ;
F_5 ( L_32 , V_84 , V_2 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_9 = F_36 ( & V_102 -> V_103 , V_84 ) ;
if ( V_9 ) {
char * V_106 = F_49 ( * V_14 , V_2 , V_26 ) ;
if ( ! V_106 )
return - V_27 ;
F_34 ( V_9 -> V_106 ) ;
V_9 -> V_106 = V_106 ;
F_5 ( L_33 , V_9 -> V_106 ) ;
}
* V_14 += V_2 ;
}
return 0 ;
V_20:
return - V_22 ;
}
void F_50 ( struct V_101 * V_102 )
{
F_5 ( L_34 , V_102 ) ;
if ( V_102 -> V_117 )
F_25 ( V_102 -> V_117 ) ;
while ( ! F_51 ( & V_102 -> V_118 ) ) {
struct V_86 * V_92 =
F_28 ( F_41 ( & V_102 -> V_118 ) ,
struct V_86 , V_95 ) ;
F_33 ( & V_92 -> V_95 , & V_102 -> V_118 ) ;
F_34 ( V_92 ) ;
}
while ( ! F_51 ( & V_102 -> V_119 ) ) {
struct V_86 * V_92 =
F_28 ( F_41 ( & V_102 -> V_119 ) ,
struct V_86 , V_95 ) ;
F_33 ( & V_92 -> V_95 , & V_102 -> V_119 ) ;
F_34 ( V_92 ) ;
}
while ( ! F_51 ( & V_102 -> V_103 ) ) {
struct V_8 * V_9 =
F_28 ( F_41 ( & V_102 -> V_103 ) ,
struct V_8 , V_95 ) ;
F_43 ( & V_102 -> V_103 , V_9 ) ;
}
F_34 ( V_102 -> V_120 ) ;
F_34 ( V_102 -> V_121 ) ;
F_34 ( V_102 -> V_122 ) ;
F_34 ( V_102 -> V_123 ) ;
F_34 ( V_102 ) ;
}
static int F_52 ( struct V_101 * V_102 , int V_124 )
{
V_80 * V_3 ;
V_19 * V_63 ;
struct V_125 * V_126 ;
int V_39 ;
V_3 = F_53 ( V_102 -> V_120 , V_124 * sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
return - V_27 ;
V_102 -> V_120 = V_3 ;
V_63 = F_53 ( V_102 -> V_121 , V_124 * sizeof( * V_63 ) , V_26 ) ;
if ( ! V_63 )
return - V_27 ;
V_102 -> V_121 = V_63 ;
V_126 = F_53 ( V_102 -> V_122 , V_124 * sizeof( * V_126 ) , V_26 ) ;
if ( ! V_126 )
return - V_27 ;
V_102 -> V_122 = V_126 ;
for ( V_39 = V_102 -> V_127 ; V_39 < V_124 ; V_39 ++ ) {
V_102 -> V_120 [ V_39 ] = 0 ;
V_102 -> V_121 [ V_39 ] = V_128 ;
memset ( V_102 -> V_122 + V_39 , 0 , sizeof( * V_102 -> V_122 ) ) ;
}
if ( V_102 -> V_123 ) {
V_19 * V_129 ;
V_129 = F_53 ( V_102 -> V_123 ,
V_124 * sizeof( * V_129 ) , V_26 ) ;
if ( ! V_129 )
return - V_27 ;
V_102 -> V_123 = V_129 ;
for ( V_39 = V_102 -> V_127 ; V_39 < V_124 ; V_39 ++ )
V_102 -> V_123 [ V_39 ] =
V_130 ;
}
V_102 -> V_127 = V_124 ;
return 0 ;
}
static int F_54 ( void * * V_14 , void * V_15 ,
const char * V_131 , V_80 * V_132 )
{
V_80 V_133 ;
F_11 ( V_14 , V_15 , V_133 , V_134 ) ;
if ( V_133 >= 7 ) {
V_80 V_135 ;
F_11 ( V_14 , V_15 , V_135 , V_134 ) ;
if ( V_135 > V_136 ) {
F_45 ( L_35 ,
V_133 , V_135 ,
V_136 , V_131 ) ;
return - V_22 ;
}
* V_14 += 4 ;
F_11 ( V_14 , V_15 , V_133 , V_134 ) ;
F_11 ( V_14 , V_15 , V_135 , V_134 ) ;
if ( V_135 > V_137 ) {
F_45 ( L_36 ,
V_133 , V_135 ,
V_137 , V_131 ) ;
return - V_22 ;
}
* V_14 += 4 ;
} else {
T_1 V_138 ;
* V_14 -= 1 ;
F_55 ( V_14 , V_15 , V_138 , V_134 ) ;
if ( V_138 < 6 ) {
F_45 ( L_37 ,
V_138 , V_131 ) ;
return - V_22 ;
}
V_133 = 0 ;
}
* V_132 = V_133 ;
return 0 ;
V_134:
return - V_22 ;
}
static int F_56 ( void * * V_14 , void * V_15 , struct V_101 * V_102 ,
bool V_139 )
{
V_19 V_99 ;
F_15 ( V_14 , V_15 , V_99 , V_134 ) ;
while ( V_99 -- ) {
struct V_8 * V_9 ;
V_93 V_84 ;
int V_140 ;
F_48 ( V_14 , V_15 , V_84 , V_134 ) ;
V_9 = F_36 ( & V_102 -> V_103 , V_84 ) ;
if ( ! V_139 || ! V_9 ) {
V_9 = F_17 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
V_9 -> V_61 = V_84 ;
V_140 = F_35 ( & V_102 -> V_103 , V_9 ) ;
if ( V_140 ) {
F_34 ( V_9 ) ;
return V_140 ;
}
}
V_140 = F_44 ( V_14 , V_15 , V_9 ) ;
if ( V_140 )
return V_140 ;
}
return 0 ;
V_134:
return - V_22 ;
}
static int F_57 ( void * * V_14 , void * V_15 , struct V_101 * V_102 )
{
return F_56 ( V_14 , V_15 , V_102 , false ) ;
}
static int F_58 ( void * * V_14 , void * V_15 , struct V_101 * V_102 )
{
return F_56 ( V_14 , V_15 , V_102 , true ) ;
}
static int F_59 ( void * * V_14 , void * V_15 , struct V_101 * V_102 ,
bool V_139 )
{
V_19 V_99 ;
F_15 ( V_14 , V_15 , V_99 , V_134 ) ;
while ( V_99 -- ) {
struct V_82 V_94 ;
V_19 V_2 , V_39 ;
int V_140 ;
V_140 = F_60 ( V_14 , V_15 , & V_94 ) ;
if ( V_140 )
return V_140 ;
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
V_140 = F_32 ( & V_102 -> V_118 , V_94 ) ;
F_20 ( ! V_139 && V_140 != - V_100 ) ;
if ( ! V_139 || V_2 > 0 ) {
struct V_86 * V_92 ;
F_6 ( V_14 , V_15 , V_2 * sizeof( V_19 ) , V_134 ) ;
if ( V_2 > ( V_141 - sizeof( * V_92 ) ) / sizeof( V_19 ) )
return - V_22 ;
V_92 = F_17 ( sizeof( * V_92 ) + V_2 * sizeof( V_19 ) , V_26 ) ;
if ( ! V_92 )
return - V_27 ;
V_92 -> V_94 = V_94 ;
V_92 -> V_118 . V_2 = V_2 ;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ )
V_92 -> V_118 . V_142 [ V_39 ] = F_7 ( V_14 ) ;
V_140 = F_27 ( V_92 , & V_102 -> V_118 ) ;
if ( V_140 ) {
F_34 ( V_92 ) ;
return V_140 ;
}
}
}
return 0 ;
V_134:
return - V_22 ;
}
static int F_61 ( void * * V_14 , void * V_15 , struct V_101 * V_102 )
{
return F_59 ( V_14 , V_15 , V_102 , false ) ;
}
static int F_62 ( void * * V_14 , void * V_15 , struct V_101 * V_102 )
{
return F_59 ( V_14 , V_15 , V_102 , true ) ;
}
static int F_63 ( void * * V_14 , void * V_15 , struct V_101 * V_102 ,
bool V_139 )
{
V_19 V_99 ;
F_15 ( V_14 , V_15 , V_99 , V_134 ) ;
while ( V_99 -- ) {
struct V_82 V_94 ;
V_19 V_143 ;
int V_140 ;
V_140 = F_60 ( V_14 , V_15 , & V_94 ) ;
if ( V_140 )
return V_140 ;
F_15 ( V_14 , V_15 , V_143 , V_134 ) ;
V_140 = F_32 ( & V_102 -> V_119 , V_94 ) ;
F_20 ( ! V_139 && V_140 != - V_100 ) ;
if ( ! V_139 || V_143 != ( V_19 ) - 1 ) {
struct V_86 * V_92 ;
V_92 = F_17 ( sizeof( * V_92 ) , V_26 ) ;
if ( ! V_92 )
return - V_27 ;
V_92 -> V_94 = V_94 ;
V_92 -> V_119 . V_143 = V_143 ;
V_140 = F_27 ( V_92 , & V_102 -> V_119 ) ;
if ( V_140 ) {
F_34 ( V_92 ) ;
return V_140 ;
}
}
}
return 0 ;
V_134:
return - V_22 ;
}
static int F_64 ( void * * V_14 , void * V_15 , struct V_101 * V_102 )
{
return F_63 ( V_14 , V_15 , V_102 , false ) ;
}
static int F_65 ( void * * V_14 , void * V_15 ,
struct V_101 * V_102 )
{
return F_63 ( V_14 , V_15 , V_102 , true ) ;
}
V_19 F_66 ( struct V_101 * V_102 , int V_143 )
{
F_20 ( V_143 >= V_102 -> V_127 ) ;
if ( ! V_102 -> V_123 )
return V_130 ;
return V_102 -> V_123 [ V_143 ] ;
}
static int F_67 ( struct V_101 * V_102 , int V_143 , V_19 V_144 )
{
F_20 ( V_143 >= V_102 -> V_127 ) ;
if ( ! V_102 -> V_123 ) {
int V_39 ;
V_102 -> V_123 = F_23 ( V_102 -> V_127 * sizeof( V_19 ) ,
V_26 ) ;
if ( ! V_102 -> V_123 )
return - V_27 ;
for ( V_39 = 0 ; V_39 < V_102 -> V_127 ; V_39 ++ )
V_102 -> V_123 [ V_39 ] =
V_130 ;
}
V_102 -> V_123 [ V_143 ] = V_144 ;
return 0 ;
}
static int F_68 ( void * * V_14 , void * V_15 ,
struct V_101 * V_102 )
{
V_19 V_2 , V_39 ;
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
if ( V_2 == 0 ) {
F_34 ( V_102 -> V_123 ) ;
V_102 -> V_123 = NULL ;
return 0 ;
}
if ( V_2 != V_102 -> V_127 )
goto V_134;
F_6 ( V_14 , V_15 , V_102 -> V_127 * sizeof( V_19 ) , V_134 ) ;
for ( V_39 = 0 ; V_39 < V_102 -> V_127 ; V_39 ++ ) {
int V_140 ;
V_140 = F_67 ( V_102 , V_39 , F_7 ( V_14 ) ) ;
if ( V_140 )
return V_140 ;
}
return 0 ;
V_134:
return - V_22 ;
}
static int F_69 ( void * * V_14 , void * V_15 ,
struct V_101 * V_102 )
{
V_19 V_99 ;
F_15 ( V_14 , V_15 , V_99 , V_134 ) ;
while ( V_99 -- ) {
V_19 V_143 , V_144 ;
int V_140 ;
F_15 ( V_14 , V_15 , V_143 , V_134 ) ;
F_15 ( V_14 , V_15 , V_144 , V_134 ) ;
V_140 = F_67 ( V_102 , V_143 , V_144 ) ;
if ( V_140 )
return V_140 ;
F_70 ( L_38 , V_143 , V_144 ) ;
}
return 0 ;
V_134:
return - V_22 ;
}
static int F_71 ( void * * V_14 , void * V_15 , struct V_101 * V_102 )
{
V_80 V_133 ;
V_19 V_145 = 0 ;
void * V_40 = * V_14 ;
V_19 V_124 ;
V_19 V_2 , V_39 ;
int V_38 ;
F_5 ( L_39 , V_146 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_38 = F_54 ( V_14 , V_15 , L_40 , & V_133 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_102 -> V_147 ) + sizeof( V_19 ) +
sizeof( V_102 -> V_148 ) + sizeof( V_102 -> V_149 ) , V_134 ) ;
F_72 ( V_14 , & V_102 -> V_147 , sizeof( V_102 -> V_147 ) ) ;
V_145 = V_102 -> V_145 = F_7 ( V_14 ) ;
F_72 ( V_14 , & V_102 -> V_148 , sizeof( V_102 -> V_148 ) ) ;
F_72 ( V_14 , & V_102 -> V_149 , sizeof( V_102 -> V_149 ) ) ;
V_38 = F_57 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
V_38 = F_47 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
F_15 ( V_14 , V_15 , V_102 -> V_150 , V_134 ) ;
F_15 ( V_14 , V_15 , V_102 -> V_114 , V_134 ) ;
F_15 ( V_14 , V_15 , V_124 , V_134 ) ;
V_38 = F_52 ( V_102 , V_124 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) +
V_102 -> V_127 * ( 1 + sizeof( * V_102 -> V_121 ) +
sizeof( * V_102 -> V_122 ) ) , V_134 ) ;
if ( F_7 ( V_14 ) != V_102 -> V_127 )
goto V_134;
F_72 ( V_14 , V_102 -> V_120 , V_102 -> V_127 ) ;
if ( F_7 ( V_14 ) != V_102 -> V_127 )
goto V_134;
for ( V_39 = 0 ; V_39 < V_102 -> V_127 ; V_39 ++ )
V_102 -> V_121 [ V_39 ] = F_7 ( V_14 ) ;
if ( F_7 ( V_14 ) != V_102 -> V_127 )
goto V_134;
F_72 ( V_14 , V_102 -> V_122 , V_102 -> V_127 * sizeof( * V_102 -> V_122 ) ) ;
for ( V_39 = 0 ; V_39 < V_102 -> V_127 ; V_39 ++ )
F_73 ( & V_102 -> V_122 [ V_39 ] ) ;
V_38 = F_61 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
if ( V_133 >= 1 ) {
V_38 = F_64 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
}
if ( V_133 >= 2 ) {
V_38 = F_68 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
} else {
F_34 ( V_102 -> V_123 ) ;
V_102 -> V_123 = NULL ;
}
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
V_102 -> V_117 = F_16 ( * V_14 , F_74 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_75 ( V_102 -> V_117 ) ) {
V_38 = F_76 ( V_102 -> V_117 ) ;
V_102 -> V_117 = NULL ;
goto V_20;
}
* V_14 += V_2 ;
* V_14 = V_15 ;
F_5 ( L_41 , V_102 -> V_145 , V_102 -> V_127 ) ;
return 0 ;
V_134:
V_38 = - V_22 ;
V_20:
F_19 ( L_42 ,
V_38 , V_145 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_40 , V_15 ) ;
F_77 ( V_151 , L_43 ,
V_152 , 16 , 1 ,
V_40 , V_15 - V_40 , true ) ;
return V_38 ;
}
struct V_101 * F_78 ( void * * V_14 , void * V_15 )
{
struct V_101 * V_102 ;
int V_140 ;
V_102 = F_17 ( sizeof( * V_102 ) , V_26 ) ;
if ( ! V_102 )
return F_18 ( - V_27 ) ;
V_102 -> V_118 = V_153 ;
V_102 -> V_119 = V_153 ;
F_79 ( & V_102 -> V_154 ) ;
V_140 = F_71 ( V_14 , V_15 , V_102 ) ;
if ( V_140 ) {
F_50 ( V_102 ) ;
return F_18 ( V_140 ) ;
}
return V_102 ;
}
struct V_101 * F_80 ( void * * V_14 , void * V_15 ,
struct V_101 * V_102 ,
struct V_155 * V_156 )
{
struct V_35 * V_157 = NULL ;
struct V_158 V_147 ;
V_19 V_145 = 0 ;
struct V_159 V_149 ;
T_2 V_2 ;
V_93 V_84 ;
T_3 V_160 ;
V_65 V_161 , V_124 ;
void * V_40 = * V_14 ;
int V_38 ;
V_80 V_133 ;
F_5 ( L_39 , V_146 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_38 = F_54 ( V_14 , V_15 , L_44 , & V_133 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_147 ) + sizeof( V_19 ) + sizeof( V_149 ) +
sizeof( V_93 ) + sizeof( V_19 ) , V_134 ) ;
F_72 ( V_14 , & V_147 , sizeof( V_147 ) ) ;
V_145 = F_7 ( V_14 ) ;
F_20 ( V_145 != V_102 -> V_145 + 1 ) ;
F_72 ( V_14 , & V_149 , sizeof( V_149 ) ) ;
V_160 = F_46 ( V_14 ) ;
V_161 = F_7 ( V_14 ) ;
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
if ( V_2 > 0 ) {
F_5 ( L_45 ,
V_2 , * V_14 , V_15 ) ;
return F_78 ( V_14 , F_74 ( * V_14 + V_2 , V_15 ) ) ;
}
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
if ( V_2 > 0 ) {
V_157 = F_16 ( * V_14 , F_74 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_75 ( V_157 ) ) {
V_38 = F_76 ( V_157 ) ;
V_157 = NULL ;
goto V_20;
}
* V_14 += V_2 ;
}
if ( V_161 >= 0 )
V_102 -> V_114 = V_161 ;
if ( V_160 >= 0 )
V_102 -> V_150 = V_160 ;
F_15 ( V_14 , V_15 , V_124 , V_134 ) ;
if ( V_124 >= 0 ) {
V_38 = F_52 ( V_102 , V_124 ) ;
if ( V_38 )
goto V_20;
}
V_102 -> V_145 ++ ;
V_102 -> V_149 = V_149 ;
if ( V_157 ) {
if ( V_102 -> V_117 )
F_25 ( V_102 -> V_117 ) ;
V_102 -> V_117 = V_157 ;
V_157 = NULL ;
}
V_38 = F_58 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
V_38 = F_47 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
while ( V_2 -- ) {
struct V_8 * V_9 ;
F_48 ( V_14 , V_15 , V_84 , V_134 ) ;
V_9 = F_36 ( & V_102 -> V_103 , V_84 ) ;
if ( V_9 )
F_43 ( & V_102 -> V_103 , V_9 ) ;
}
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
while ( V_2 -- ) {
V_19 V_143 ;
struct V_125 V_126 ;
F_15 ( V_14 , V_15 , V_143 , V_134 ) ;
F_24 ( V_14 , V_15 , & V_126 , sizeof( V_126 ) , V_134 ) ;
F_73 ( & V_126 ) ;
F_70 ( L_46 , V_143 ) ;
F_20 ( V_143 >= V_102 -> V_127 ) ;
V_102 -> V_120 [ V_143 ] |= V_5 ;
V_102 -> V_122 [ V_143 ] = V_126 ;
}
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
while ( V_2 -- ) {
V_19 V_143 ;
V_80 V_162 ;
F_15 ( V_14 , V_15 , V_143 , V_134 ) ;
V_162 = * * ( V_80 * * ) V_14 ;
( * V_14 ) ++ ;
if ( V_162 == 0 )
V_162 = V_5 ;
if ( V_162 & V_5 )
F_70 ( L_47 , V_143 ) ;
if ( V_143 < V_102 -> V_127 )
V_102 -> V_120 [ V_143 ] ^= V_162 ;
}
F_15 ( V_14 , V_15 , V_2 , V_134 ) ;
while ( V_2 -- ) {
V_19 V_143 , V_163 ;
F_6 ( V_14 , V_15 , sizeof( V_19 ) * 2 , V_134 ) ;
V_143 = F_7 ( V_14 ) ;
V_163 = F_7 ( V_14 ) ;
F_70 ( L_48 , V_143 , V_163 ,
V_163 == V_164 ? L_49 :
( V_163 == V_128 ? L_50 : L_51 ) ) ;
if ( V_143 < V_102 -> V_127 )
V_102 -> V_121 [ V_143 ] = V_163 ;
}
V_38 = F_62 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
if ( V_133 >= 1 ) {
V_38 = F_65 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
}
if ( V_133 >= 2 ) {
V_38 = F_69 ( V_14 , V_15 , V_102 ) ;
if ( V_38 )
goto V_20;
}
* V_14 = V_15 ;
F_5 ( L_52 , V_102 -> V_145 , V_102 -> V_127 ) ;
return V_102 ;
V_134:
V_38 = - V_22 ;
V_20:
F_19 ( L_53 ,
V_38 , V_145 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_40 , V_15 ) ;
F_77 ( V_151 , L_43 ,
V_152 , 16 , 1 ,
V_40 , V_15 - V_40 , true ) ;
if ( V_157 )
F_25 ( V_157 ) ;
return F_18 ( V_38 ) ;
}
int F_81 ( struct V_165 * V_166 ,
V_93 V_163 , V_93 V_2 ,
V_93 * V_167 ,
V_93 * V_168 , V_93 * V_169 )
{
V_19 V_170 = F_82 ( V_166 -> V_171 ) ;
V_19 V_172 = F_82 ( V_166 -> V_173 ) ;
V_19 V_174 = F_82 ( V_166 -> V_175 ) ;
V_19 V_176 , V_177 , V_178 , V_179 ;
V_19 V_180 ;
V_93 V_6 , V_181 ;
F_5 ( L_54 , V_163 , V_2 ,
V_170 , V_172 ) ;
if ( V_172 == 0 || V_174 == 0 )
goto V_182;
V_180 = V_170 / V_172 ;
if ( V_180 == 0 )
goto V_182;
F_5 ( L_55 , V_170 , V_172 ,
V_180 ) ;
if ( ( V_172 & ~ V_183 ) != 0 )
goto V_182;
V_6 = V_163 ;
F_83 ( V_6 , V_172 ) ;
V_176 = V_6 ;
F_5 ( L_56 , V_163 , V_172 , V_176 ) ;
V_177 = V_176 / V_174 ;
V_178 = V_176 % V_174 ;
V_179 = V_177 / V_180 ;
* V_167 = V_179 * V_174 + V_178 ;
F_5 ( L_57 , V_179 , V_174 , ( unsigned int ) * V_167 ) ;
V_6 = V_163 ;
V_181 = F_83 ( V_6 , V_172 ) ;
* V_168 = V_181 + ( V_177 % V_180 ) * V_172 ;
* V_169 = F_84 ( V_93 , V_2 , V_172 - V_181 ) ;
F_5 ( L_58 , * V_168 , * V_169 ) ;
return 0 ;
V_182:
F_5 ( L_59 ) ;
* V_167 = 0 ;
* V_168 = 0 ;
* V_169 = 0 ;
return - V_22 ;
}
int F_85 ( struct V_101 * V_184 ,
struct V_185 * V_186 ,
struct V_187 * V_188 ,
struct V_82 * V_189 )
{
struct V_8 * V_9 ;
V_9 = F_36 ( & V_184 -> V_103 , V_186 -> V_84 ) ;
if ( ! V_9 )
return - V_190 ;
V_189 -> V_84 = V_186 -> V_84 ;
V_189 -> V_85 = F_86 ( V_9 -> V_113 , V_188 -> V_106 ,
V_188 -> V_191 ) ;
F_5 ( L_60 , V_146 , V_188 -> V_191 , V_188 -> V_106 ,
V_189 -> V_84 , V_189 -> V_85 ) ;
return 0 ;
}
static int F_87 ( struct V_101 * V_102 , int V_192 , int V_193 ,
int * V_194 , int V_195 ,
const T_4 * V_63 , int V_196 )
{
int V_70 ;
F_20 ( V_195 > V_197 ) ;
F_88 ( & V_102 -> V_154 ) ;
V_70 = F_89 ( V_102 -> V_117 , V_192 , V_193 , V_194 , V_195 ,
V_63 , V_196 , V_102 -> V_198 ) ;
F_90 ( & V_102 -> V_154 ) ;
return V_70 ;
}
static int F_91 ( struct V_101 * V_184 ,
struct V_8 * V_84 ,
struct V_82 V_94 , V_19 V_199 , int * V_142 )
{
int V_192 ;
int V_2 ;
V_192 = F_92 ( V_184 -> V_117 , V_84 -> V_112 ,
V_84 -> type , V_84 -> V_18 ) ;
if ( V_192 < 0 ) {
F_19 ( L_61 ,
V_94 . V_84 , V_84 -> V_112 , V_84 -> type ,
V_84 -> V_18 ) ;
return - V_100 ;
}
V_2 = F_87 ( V_184 , V_192 , V_199 , V_142 ,
F_84 ( int , V_84 -> V_18 , V_197 ) ,
V_184 -> V_121 , V_184 -> V_127 ) ;
if ( V_2 < 0 ) {
F_19 ( L_62 ,
V_2 , V_192 , V_94 . V_84 , V_84 -> V_112 ,
V_84 -> type , V_84 -> V_18 ) ;
return V_2 ;
}
return V_2 ;
}
static int F_93 ( struct V_101 * V_184 ,
struct V_8 * V_84 ,
int * V_142 , int V_2 , int * V_200 )
{
int V_201 = - 1 ;
int V_39 ;
if ( F_94 ( V_84 ) ) {
int V_202 = 0 ;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ ) {
if ( F_95 ( V_184 , V_142 [ V_39 ] ) ) {
V_202 ++ ;
continue;
}
if ( V_202 )
V_142 [ V_39 - V_202 ] = V_142 [ V_39 ] ;
}
V_2 -= V_202 ;
if ( V_2 > 0 )
V_201 = V_142 [ 0 ] ;
} else {
for ( V_39 = V_2 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( F_95 ( V_184 , V_142 [ V_39 ] ) )
V_142 [ V_39 ] = V_203 ;
else
V_201 = V_142 [ V_39 ] ;
}
}
* V_200 = V_201 ;
return V_2 ;
}
static void F_96 ( struct V_101 * V_184 , V_19 V_199 ,
struct V_8 * V_84 ,
int * V_142 , int V_2 , int * V_200 )
{
int V_39 ;
int V_204 = - 1 ;
if ( ! V_184 -> V_123 )
return;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ ) {
int V_143 = V_142 [ V_39 ] ;
if ( V_143 != V_203 &&
V_184 -> V_123 [ V_143 ] !=
V_130 ) {
break;
}
}
if ( V_39 == V_2 )
return;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ ) {
int V_143 = V_142 [ V_39 ] ;
V_19 V_144 ;
if ( V_143 == V_203 )
continue;
V_144 = V_184 -> V_123 [ V_143 ] ;
if ( V_144 < V_205 &&
( F_97 ( V_206 ,
V_199 , V_143 ) >> 16 ) >= V_144 ) {
if ( V_204 < 0 )
V_204 = V_39 ;
} else {
V_204 = V_39 ;
break;
}
}
if ( V_204 < 0 )
return;
* V_200 = V_142 [ V_204 ] ;
if ( F_94 ( V_84 ) && V_204 > 0 ) {
for ( V_39 = V_204 ; V_39 > 0 ; V_39 -- )
V_142 [ V_39 ] = V_142 [ V_39 - 1 ] ;
V_142 [ 0 ] = * V_200 ;
}
}
static int F_98 ( struct V_101 * V_184 ,
struct V_8 * V_84 , struct V_82 V_94 ,
int * V_142 , int V_2 , int * V_200 )
{
struct V_86 * V_92 ;
int V_207 ;
int V_208 ;
int V_39 ;
V_94 . V_85 = F_99 ( V_94 . V_85 , V_84 -> V_11 ,
V_84 -> V_10 ) ;
V_92 = F_31 ( & V_184 -> V_118 , V_94 ) ;
if ( V_92 ) {
V_207 = 0 ;
V_208 = - 1 ;
for ( V_39 = 0 ; V_39 < V_92 -> V_118 . V_2 ; V_39 ++ ) {
if ( F_95 ( V_184 , V_92 -> V_118 . V_142 [ V_39 ] ) ) {
if ( F_94 ( V_84 ) )
continue;
else
V_142 [ V_207 ++ ] = V_203 ;
} else {
V_142 [ V_207 ++ ] = V_92 -> V_118 . V_142 [ V_39 ] ;
}
}
for ( V_39 = 0 ; V_39 < V_207 ; V_39 ++ ) {
if ( V_142 [ V_39 ] != V_203 ) {
V_208 = V_142 [ V_39 ] ;
break;
}
}
} else {
V_207 = V_2 ;
V_208 = * V_200 ;
}
V_92 = F_31 ( & V_184 -> V_119 , V_94 ) ;
if ( V_92 )
V_208 = V_92 -> V_119 . V_143 ;
* V_200 = V_208 ;
return V_207 ;
}
int F_100 ( struct V_101 * V_184 , struct V_82 V_94 ,
int * V_142 , int * V_200 )
{
struct V_8 * V_84 ;
V_19 V_199 ;
int V_2 ;
V_84 = F_36 ( & V_184 -> V_103 , V_94 . V_84 ) ;
if ( ! V_84 ) {
* V_200 = - 1 ;
return - V_100 ;
}
if ( V_84 -> V_114 & V_209 ) {
V_199 = F_97 ( V_206 ,
F_99 ( V_94 . V_85 , V_84 -> V_13 ,
V_84 -> V_12 ) ,
V_94 . V_84 ) ;
} else {
V_199 = F_99 ( V_94 . V_85 , V_84 -> V_13 ,
V_84 -> V_12 ) +
( unsigned ) V_94 . V_84 ;
}
V_2 = F_91 ( V_184 , V_84 , V_94 , V_199 , V_142 ) ;
if ( V_2 < 0 ) {
* V_200 = - 1 ;
return V_2 ;
}
V_2 = F_93 ( V_184 , V_84 , V_142 , V_2 , V_200 ) ;
F_96 ( V_184 , V_199 , V_84 , V_142 , V_2 , V_200 ) ;
V_2 = F_98 ( V_184 , V_84 , V_94 , V_142 , V_2 , V_200 ) ;
return V_2 ;
}
int F_101 ( struct V_101 * V_184 , struct V_82 V_94 )
{
int V_142 [ V_197 ] ;
int V_200 ;
F_100 ( V_184 , V_94 , V_142 , & V_200 ) ;
return V_200 ;
}
