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
int F_26 ( const struct V_83 * V_84 , const struct V_83 * V_85 )
{
if ( V_84 -> V_86 < V_85 -> V_86 )
return - 1 ;
if ( V_84 -> V_86 > V_85 -> V_86 )
return 1 ;
if ( V_84 -> V_87 < V_85 -> V_87 )
return - 1 ;
if ( V_84 -> V_87 > V_85 -> V_87 )
return 1 ;
return 0 ;
}
static int F_27 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_92 * * V_14 = & V_91 -> V_92 ;
struct V_92 * V_93 = NULL ;
struct V_88 * V_94 = NULL ;
int V_37 ;
F_5 ( L_26 , * ( V_95 * ) & V_89 -> V_96 , V_89 ) ;
while ( * V_14 ) {
V_93 = * V_14 ;
V_94 = F_28 ( V_93 , struct V_88 , V_97 ) ;
V_37 = F_26 ( & V_89 -> V_96 , & V_94 -> V_96 ) ;
if ( V_37 < 0 )
V_14 = & ( * V_14 ) -> V_98 ;
else if ( V_37 > 0 )
V_14 = & ( * V_14 ) -> V_99 ;
else
return - V_100 ;
}
F_29 ( & V_89 -> V_97 , V_93 , V_14 ) ;
F_30 ( & V_89 -> V_97 , V_91 ) ;
return 0 ;
}
static struct V_88 * F_31 ( struct V_90 * V_91 ,
struct V_83 V_96 )
{
struct V_92 * V_101 = V_91 -> V_92 ;
struct V_88 * V_94 ;
int V_37 ;
while ( V_101 ) {
V_94 = F_28 ( V_101 , struct V_88 , V_97 ) ;
V_37 = F_26 ( & V_96 , & V_94 -> V_96 ) ;
if ( V_37 < 0 ) {
V_101 = V_101 -> V_98 ;
} else if ( V_37 > 0 ) {
V_101 = V_101 -> V_99 ;
} else {
F_5 ( L_27 ,
V_96 . V_86 , V_96 . V_87 , V_94 ) ;
return V_94 ;
}
}
return NULL ;
}
static int F_32 ( struct V_90 * V_91 , struct V_83 V_96 )
{
struct V_88 * V_94 = F_31 ( V_91 , V_96 ) ;
if ( V_94 ) {
F_5 ( L_28 , V_96 . V_86 , V_96 . V_87 ,
V_94 ) ;
F_33 ( & V_94 -> V_97 , V_91 ) ;
F_34 ( V_94 ) ;
return 0 ;
}
F_5 ( L_29 , V_96 . V_86 , V_96 . V_87 ) ;
return - V_102 ;
}
static int F_35 ( struct V_90 * V_91 , struct V_8 * V_89 )
{
struct V_92 * * V_14 = & V_91 -> V_92 ;
struct V_92 * V_93 = NULL ;
struct V_8 * V_9 = NULL ;
while ( * V_14 ) {
V_93 = * V_14 ;
V_9 = F_28 ( V_93 , struct V_8 , V_97 ) ;
if ( V_89 -> V_61 < V_9 -> V_61 )
V_14 = & ( * V_14 ) -> V_98 ;
else if ( V_89 -> V_61 > V_9 -> V_61 )
V_14 = & ( * V_14 ) -> V_99 ;
else
return - V_100 ;
}
F_29 ( & V_89 -> V_97 , V_93 , V_14 ) ;
F_30 ( & V_89 -> V_97 , V_91 ) ;
return 0 ;
}
static struct V_8 * F_36 ( struct V_90 * V_91 , V_95 V_61 )
{
struct V_8 * V_9 ;
struct V_92 * V_101 = V_91 -> V_92 ;
while ( V_101 ) {
V_9 = F_28 ( V_101 , struct V_8 , V_97 ) ;
if ( V_61 < V_9 -> V_61 )
V_101 = V_101 -> V_98 ;
else if ( V_61 > V_9 -> V_61 )
V_101 = V_101 -> V_99 ;
else
return V_9 ;
}
return NULL ;
}
struct V_8 * F_37 ( struct V_103 * V_104 , V_95 V_61 )
{
return F_36 ( & V_104 -> V_105 , V_61 ) ;
}
const char * F_38 ( struct V_103 * V_104 , V_95 V_61 )
{
struct V_8 * V_9 ;
if ( V_61 == V_106 )
return NULL ;
if ( F_39 ( V_61 > ( V_95 ) V_107 ) )
return NULL ;
V_9 = F_36 ( & V_104 -> V_105 , ( int ) V_61 ) ;
return V_9 ? V_9 -> V_108 : NULL ;
}
int F_40 ( struct V_103 * V_104 , const char * V_108 )
{
struct V_92 * V_109 ;
for ( V_109 = F_41 ( & V_104 -> V_105 ) ; V_109 ; V_109 = F_42 ( V_109 ) ) {
struct V_8 * V_9 =
F_28 ( V_109 , struct V_8 , V_97 ) ;
if ( V_9 -> V_108 && strcmp ( V_9 -> V_108 , V_108 ) == 0 )
return V_9 -> V_61 ;
}
return - V_102 ;
}
static void F_43 ( struct V_90 * V_91 , struct V_8 * V_9 )
{
F_33 ( & V_9 -> V_97 , V_91 ) ;
F_34 ( V_9 -> V_108 ) ;
F_34 ( V_9 ) ;
}
static int F_44 ( void * * V_14 , void * V_15 , struct V_8 * V_9 )
{
V_80 V_110 , V_111 ;
unsigned V_2 , V_112 ;
void * V_113 ;
F_6 ( V_14 , V_15 , 2 + 4 , V_20 ) ;
V_110 = F_22 ( V_14 ) ;
V_111 = F_22 ( V_14 ) ;
if ( V_110 < 5 ) {
F_45 ( L_30 , V_110 , V_111 ) ;
return - V_22 ;
}
if ( V_111 > 9 ) {
F_45 ( L_31 , V_110 , V_111 ) ;
return - V_22 ;
}
V_2 = F_7 ( V_14 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_113 = * V_14 + V_2 ;
V_9 -> type = F_22 ( V_14 ) ;
V_9 -> V_18 = F_22 ( V_14 ) ;
V_9 -> V_114 = F_22 ( V_14 ) ;
V_9 -> V_115 = F_22 ( V_14 ) ;
V_9 -> V_11 = F_7 ( V_14 ) ;
V_9 -> V_13 = F_7 ( V_14 ) ;
* V_14 += 4 + 4 ;
* V_14 += 4 ;
* V_14 += 8 + 4 ;
V_112 = F_7 ( V_14 ) ;
while ( V_112 -- ) {
* V_14 += 8 ;
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
V_112 = F_7 ( V_14 ) ;
* V_14 += V_112 * ( 8 + 8 ) ;
* V_14 += 8 ;
V_9 -> V_116 = F_46 ( V_14 ) ;
* V_14 += 4 ;
if ( V_110 >= 7 )
V_9 -> V_117 = F_22 ( V_14 ) ;
else
V_9 -> V_117 = V_9 -> V_18 - V_9 -> V_18 / 2 ;
if ( V_110 >= 8 )
* V_14 += 8 + 8 ;
if ( V_110 >= 9 ) {
V_112 = F_7 ( V_14 ) ;
* V_14 += V_112 * 8 ;
* V_14 += 8 ;
* V_14 += 1 ;
V_9 -> V_118 = F_46 ( V_14 ) ;
V_9 -> V_119 = F_46 ( V_14 ) ;
} else {
V_9 -> V_118 = - 1 ;
V_9 -> V_119 = - 1 ;
}
if ( V_110 >= 10 ) {
V_112 = F_7 ( V_14 ) ;
while ( V_112 -- ) {
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
}
if ( V_110 >= 11 ) {
* V_14 += 1 + 1 ;
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
* V_14 += 4 ;
* V_14 += 4 ;
}
if ( V_110 >= 12 )
* V_14 += 4 ;
if ( V_110 >= 13 ) {
* V_14 += 8 ;
* V_14 += 8 ;
* V_14 += 4 ;
* V_14 += 4 ;
* V_14 += 4 ;
* V_14 += 4 ;
}
if ( V_110 >= 14 ) {
V_2 = F_7 ( V_14 ) ;
* V_14 += V_2 ;
}
if ( V_110 >= 15 )
V_9 -> V_120 = F_7 ( V_14 ) ;
else
V_9 -> V_120 = 0 ;
* V_14 = V_113 ;
F_3 ( V_9 ) ;
return 0 ;
V_20:
return - V_22 ;
}
static int F_47 ( void * * V_14 , void * V_15 , struct V_103 * V_104 )
{
struct V_8 * V_9 ;
V_19 V_112 , V_2 ;
V_95 V_86 ;
F_15 ( V_14 , V_15 , V_112 , V_20 ) ;
F_5 ( L_32 , V_112 ) ;
while ( V_112 -- ) {
F_48 ( V_14 , V_15 , V_86 , V_20 ) ;
F_15 ( V_14 , V_15 , V_2 , V_20 ) ;
F_5 ( L_33 , V_86 , V_2 ) ;
F_6 ( V_14 , V_15 , V_2 , V_20 ) ;
V_9 = F_36 ( & V_104 -> V_105 , V_86 ) ;
if ( V_9 ) {
char * V_108 = F_49 ( * V_14 , V_2 , V_26 ) ;
if ( ! V_108 )
return - V_27 ;
F_34 ( V_9 -> V_108 ) ;
V_9 -> V_108 = V_108 ;
F_5 ( L_34 , V_9 -> V_108 ) ;
}
* V_14 += V_2 ;
}
return 0 ;
V_20:
return - V_22 ;
}
struct V_103 * F_50 ( void )
{
struct V_103 * V_104 ;
V_104 = F_17 ( sizeof( * V_104 ) , V_121 ) ;
if ( ! V_104 )
return NULL ;
V_104 -> V_105 = V_122 ;
V_104 -> V_123 = - 1 ;
V_104 -> V_124 = V_122 ;
V_104 -> V_125 = V_122 ;
F_51 ( & V_104 -> V_126 ) ;
return V_104 ;
}
void F_52 ( struct V_103 * V_104 )
{
F_5 ( L_35 , V_104 ) ;
if ( V_104 -> V_127 )
F_25 ( V_104 -> V_127 ) ;
while ( ! F_53 ( & V_104 -> V_124 ) ) {
struct V_88 * V_94 =
F_28 ( F_41 ( & V_104 -> V_124 ) ,
struct V_88 , V_97 ) ;
F_33 ( & V_94 -> V_97 , & V_104 -> V_124 ) ;
F_34 ( V_94 ) ;
}
while ( ! F_53 ( & V_104 -> V_125 ) ) {
struct V_88 * V_94 =
F_28 ( F_41 ( & V_104 -> V_125 ) ,
struct V_88 , V_97 ) ;
F_33 ( & V_94 -> V_97 , & V_104 -> V_125 ) ;
F_34 ( V_94 ) ;
}
while ( ! F_53 ( & V_104 -> V_105 ) ) {
struct V_8 * V_9 =
F_28 ( F_41 ( & V_104 -> V_105 ) ,
struct V_8 , V_97 ) ;
F_43 ( & V_104 -> V_105 , V_9 ) ;
}
F_34 ( V_104 -> V_128 ) ;
F_34 ( V_104 -> V_129 ) ;
F_34 ( V_104 -> V_130 ) ;
F_34 ( V_104 -> V_131 ) ;
F_34 ( V_104 ) ;
}
static int F_54 ( struct V_103 * V_104 , int V_132 )
{
V_80 * V_3 ;
V_19 * V_63 ;
struct V_133 * V_134 ;
int V_39 ;
V_3 = F_55 ( V_104 -> V_128 , V_132 * sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
return - V_27 ;
V_104 -> V_128 = V_3 ;
V_63 = F_55 ( V_104 -> V_129 , V_132 * sizeof( * V_63 ) , V_26 ) ;
if ( ! V_63 )
return - V_27 ;
V_104 -> V_129 = V_63 ;
V_134 = F_55 ( V_104 -> V_130 , V_132 * sizeof( * V_134 ) , V_26 ) ;
if ( ! V_134 )
return - V_27 ;
V_104 -> V_130 = V_134 ;
for ( V_39 = V_104 -> V_135 ; V_39 < V_132 ; V_39 ++ ) {
V_104 -> V_128 [ V_39 ] = 0 ;
V_104 -> V_129 [ V_39 ] = V_136 ;
memset ( V_104 -> V_130 + V_39 , 0 , sizeof( * V_104 -> V_130 ) ) ;
}
if ( V_104 -> V_131 ) {
V_19 * V_137 ;
V_137 = F_55 ( V_104 -> V_131 ,
V_132 * sizeof( * V_137 ) , V_26 ) ;
if ( ! V_137 )
return - V_27 ;
V_104 -> V_131 = V_137 ;
for ( V_39 = V_104 -> V_135 ; V_39 < V_132 ; V_39 ++ )
V_104 -> V_131 [ V_39 ] =
V_138 ;
}
V_104 -> V_135 = V_132 ;
return 0 ;
}
static int F_56 ( void * * V_14 , void * V_15 ,
const char * V_139 , V_80 * V_140 )
{
V_80 V_141 ;
F_11 ( V_14 , V_15 , V_141 , V_142 ) ;
if ( V_141 >= 7 ) {
V_80 V_143 ;
F_11 ( V_14 , V_15 , V_143 , V_142 ) ;
if ( V_143 > V_144 ) {
F_45 ( L_36 ,
V_141 , V_143 ,
V_144 , V_139 ) ;
return - V_22 ;
}
* V_14 += 4 ;
F_11 ( V_14 , V_15 , V_141 , V_142 ) ;
F_11 ( V_14 , V_15 , V_143 , V_142 ) ;
if ( V_143 > V_145 ) {
F_45 ( L_37 ,
V_141 , V_143 ,
V_145 , V_139 ) ;
return - V_22 ;
}
* V_14 += 4 ;
} else {
T_1 V_146 ;
* V_14 -= 1 ;
F_57 ( V_14 , V_15 , V_146 , V_142 ) ;
if ( V_146 < 6 ) {
F_45 ( L_38 ,
V_146 , V_139 ) ;
return - V_22 ;
}
V_141 = 0 ;
}
* V_140 = V_141 ;
return 0 ;
V_142:
return - V_22 ;
}
static int F_58 ( void * * V_14 , void * V_15 , struct V_103 * V_104 ,
bool V_147 )
{
V_19 V_101 ;
F_15 ( V_14 , V_15 , V_101 , V_142 ) ;
while ( V_101 -- ) {
struct V_8 * V_9 ;
V_95 V_86 ;
int V_148 ;
F_48 ( V_14 , V_15 , V_86 , V_142 ) ;
V_9 = F_36 ( & V_104 -> V_105 , V_86 ) ;
if ( ! V_147 || ! V_9 ) {
V_9 = F_17 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
V_9 -> V_61 = V_86 ;
V_148 = F_35 ( & V_104 -> V_105 , V_9 ) ;
if ( V_148 ) {
F_34 ( V_9 ) ;
return V_148 ;
}
}
V_148 = F_44 ( V_14 , V_15 , V_9 ) ;
if ( V_148 )
return V_148 ;
}
return 0 ;
V_142:
return - V_22 ;
}
static int F_59 ( void * * V_14 , void * V_15 , struct V_103 * V_104 )
{
return F_58 ( V_14 , V_15 , V_104 , false ) ;
}
static int F_60 ( void * * V_14 , void * V_15 , struct V_103 * V_104 )
{
return F_58 ( V_14 , V_15 , V_104 , true ) ;
}
static int F_61 ( void * * V_14 , void * V_15 , struct V_103 * V_104 ,
bool V_147 )
{
V_19 V_101 ;
F_15 ( V_14 , V_15 , V_101 , V_142 ) ;
while ( V_101 -- ) {
struct V_83 V_96 ;
V_19 V_2 , V_39 ;
int V_148 ;
V_148 = F_62 ( V_14 , V_15 , & V_96 ) ;
if ( V_148 )
return V_148 ;
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
V_148 = F_32 ( & V_104 -> V_124 , V_96 ) ;
F_20 ( ! V_147 && V_148 != - V_102 ) ;
if ( ! V_147 || V_2 > 0 ) {
struct V_88 * V_94 ;
F_6 ( V_14 , V_15 , V_2 * sizeof( V_19 ) , V_142 ) ;
if ( V_2 > ( V_149 - sizeof( * V_94 ) ) / sizeof( V_19 ) )
return - V_22 ;
V_94 = F_17 ( sizeof( * V_94 ) + V_2 * sizeof( V_19 ) , V_26 ) ;
if ( ! V_94 )
return - V_27 ;
V_94 -> V_96 = V_96 ;
V_94 -> V_124 . V_2 = V_2 ;
for ( V_39 = 0 ; V_39 < V_2 ; V_39 ++ )
V_94 -> V_124 . V_150 [ V_39 ] = F_7 ( V_14 ) ;
V_148 = F_27 ( V_94 , & V_104 -> V_124 ) ;
if ( V_148 ) {
F_34 ( V_94 ) ;
return V_148 ;
}
}
}
return 0 ;
V_142:
return - V_22 ;
}
static int F_63 ( void * * V_14 , void * V_15 , struct V_103 * V_104 )
{
return F_61 ( V_14 , V_15 , V_104 , false ) ;
}
static int F_64 ( void * * V_14 , void * V_15 , struct V_103 * V_104 )
{
return F_61 ( V_14 , V_15 , V_104 , true ) ;
}
static int F_65 ( void * * V_14 , void * V_15 , struct V_103 * V_104 ,
bool V_147 )
{
V_19 V_101 ;
F_15 ( V_14 , V_15 , V_101 , V_142 ) ;
while ( V_101 -- ) {
struct V_83 V_96 ;
V_19 V_151 ;
int V_148 ;
V_148 = F_62 ( V_14 , V_15 , & V_96 ) ;
if ( V_148 )
return V_148 ;
F_15 ( V_14 , V_15 , V_151 , V_142 ) ;
V_148 = F_32 ( & V_104 -> V_125 , V_96 ) ;
F_20 ( ! V_147 && V_148 != - V_102 ) ;
if ( ! V_147 || V_151 != ( V_19 ) - 1 ) {
struct V_88 * V_94 ;
V_94 = F_17 ( sizeof( * V_94 ) , V_26 ) ;
if ( ! V_94 )
return - V_27 ;
V_94 -> V_96 = V_96 ;
V_94 -> V_125 . V_151 = V_151 ;
V_148 = F_27 ( V_94 , & V_104 -> V_125 ) ;
if ( V_148 ) {
F_34 ( V_94 ) ;
return V_148 ;
}
}
}
return 0 ;
V_142:
return - V_22 ;
}
static int F_66 ( void * * V_14 , void * V_15 , struct V_103 * V_104 )
{
return F_65 ( V_14 , V_15 , V_104 , false ) ;
}
static int F_67 ( void * * V_14 , void * V_15 ,
struct V_103 * V_104 )
{
return F_65 ( V_14 , V_15 , V_104 , true ) ;
}
V_19 F_68 ( struct V_103 * V_104 , int V_151 )
{
F_20 ( V_151 >= V_104 -> V_135 ) ;
if ( ! V_104 -> V_131 )
return V_138 ;
return V_104 -> V_131 [ V_151 ] ;
}
static int F_69 ( struct V_103 * V_104 , int V_151 , V_19 V_152 )
{
F_20 ( V_151 >= V_104 -> V_135 ) ;
if ( ! V_104 -> V_131 ) {
int V_39 ;
V_104 -> V_131 = F_23 ( V_104 -> V_135 * sizeof( V_19 ) ,
V_26 ) ;
if ( ! V_104 -> V_131 )
return - V_27 ;
for ( V_39 = 0 ; V_39 < V_104 -> V_135 ; V_39 ++ )
V_104 -> V_131 [ V_39 ] =
V_138 ;
}
V_104 -> V_131 [ V_151 ] = V_152 ;
return 0 ;
}
static int F_70 ( void * * V_14 , void * V_15 ,
struct V_103 * V_104 )
{
V_19 V_2 , V_39 ;
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
if ( V_2 == 0 ) {
F_34 ( V_104 -> V_131 ) ;
V_104 -> V_131 = NULL ;
return 0 ;
}
if ( V_2 != V_104 -> V_135 )
goto V_142;
F_6 ( V_14 , V_15 , V_104 -> V_135 * sizeof( V_19 ) , V_142 ) ;
for ( V_39 = 0 ; V_39 < V_104 -> V_135 ; V_39 ++ ) {
int V_148 ;
V_148 = F_69 ( V_104 , V_39 , F_7 ( V_14 ) ) ;
if ( V_148 )
return V_148 ;
}
return 0 ;
V_142:
return - V_22 ;
}
static int F_71 ( void * * V_14 , void * V_15 ,
struct V_103 * V_104 )
{
V_19 V_101 ;
F_15 ( V_14 , V_15 , V_101 , V_142 ) ;
while ( V_101 -- ) {
V_19 V_151 , V_152 ;
int V_148 ;
F_15 ( V_14 , V_15 , V_151 , V_142 ) ;
F_15 ( V_14 , V_15 , V_152 , V_142 ) ;
V_148 = F_69 ( V_104 , V_151 , V_152 ) ;
if ( V_148 )
return V_148 ;
F_72 ( L_39 , V_151 , V_152 ) ;
}
return 0 ;
V_142:
return - V_22 ;
}
static int F_73 ( void * * V_14 , void * V_15 , struct V_103 * V_104 )
{
V_80 V_141 ;
V_19 V_153 = 0 ;
void * V_40 = * V_14 ;
V_19 V_132 ;
V_19 V_2 , V_39 ;
int V_38 ;
F_5 ( L_40 , V_154 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_38 = F_56 ( V_14 , V_15 , L_41 , & V_141 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_104 -> V_155 ) + sizeof( V_19 ) +
sizeof( V_104 -> V_156 ) + sizeof( V_104 -> V_157 ) , V_142 ) ;
F_74 ( V_14 , & V_104 -> V_155 , sizeof( V_104 -> V_155 ) ) ;
V_153 = V_104 -> V_153 = F_7 ( V_14 ) ;
F_74 ( V_14 , & V_104 -> V_156 , sizeof( V_104 -> V_156 ) ) ;
F_74 ( V_14 , & V_104 -> V_157 , sizeof( V_104 -> V_157 ) ) ;
V_38 = F_59 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
V_38 = F_47 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
F_15 ( V_14 , V_15 , V_104 -> V_123 , V_142 ) ;
F_15 ( V_14 , V_15 , V_104 -> V_116 , V_142 ) ;
F_15 ( V_14 , V_15 , V_132 , V_142 ) ;
V_38 = F_54 ( V_104 , V_132 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , 3 * sizeof( V_19 ) +
V_104 -> V_135 * ( 1 + sizeof( * V_104 -> V_129 ) +
sizeof( * V_104 -> V_130 ) ) , V_142 ) ;
if ( F_7 ( V_14 ) != V_104 -> V_135 )
goto V_142;
F_74 ( V_14 , V_104 -> V_128 , V_104 -> V_135 ) ;
if ( F_7 ( V_14 ) != V_104 -> V_135 )
goto V_142;
for ( V_39 = 0 ; V_39 < V_104 -> V_135 ; V_39 ++ )
V_104 -> V_129 [ V_39 ] = F_7 ( V_14 ) ;
if ( F_7 ( V_14 ) != V_104 -> V_135 )
goto V_142;
F_74 ( V_14 , V_104 -> V_130 , V_104 -> V_135 * sizeof( * V_104 -> V_130 ) ) ;
for ( V_39 = 0 ; V_39 < V_104 -> V_135 ; V_39 ++ )
F_75 ( & V_104 -> V_130 [ V_39 ] ) ;
V_38 = F_63 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
if ( V_141 >= 1 ) {
V_38 = F_66 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
}
if ( V_141 >= 2 ) {
V_38 = F_70 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
} else {
F_34 ( V_104 -> V_131 ) ;
V_104 -> V_131 = NULL ;
}
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
V_104 -> V_127 = F_16 ( * V_14 , F_76 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_77 ( V_104 -> V_127 ) ) {
V_38 = F_78 ( V_104 -> V_127 ) ;
V_104 -> V_127 = NULL ;
goto V_20;
}
* V_14 += V_2 ;
* V_14 = V_15 ;
F_5 ( L_42 , V_104 -> V_153 , V_104 -> V_135 ) ;
return 0 ;
V_142:
V_38 = - V_22 ;
V_20:
F_19 ( L_43 ,
V_38 , V_153 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_40 , V_15 ) ;
F_79 ( V_158 , L_44 ,
V_159 , 16 , 1 ,
V_40 , V_15 - V_40 , true ) ;
return V_38 ;
}
struct V_103 * F_80 ( void * * V_14 , void * V_15 )
{
struct V_103 * V_104 ;
int V_148 ;
V_104 = F_50 () ;
if ( ! V_104 )
return F_18 ( - V_27 ) ;
V_148 = F_73 ( V_14 , V_15 , V_104 ) ;
if ( V_148 ) {
F_52 ( V_104 ) ;
return F_18 ( V_148 ) ;
}
return V_104 ;
}
static int F_81 ( void * * V_14 , void * V_15 ,
struct V_103 * V_104 )
{
void * V_160 ;
void * V_161 ;
void * V_162 ;
V_19 V_2 ;
V_160 = * V_14 ;
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
V_2 *= sizeof( V_19 ) + sizeof( struct V_133 ) ;
F_6 ( V_14 , V_15 , V_2 , V_142 ) ;
* V_14 += V_2 ;
V_161 = * V_14 ;
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
V_2 *= sizeof( V_19 ) + sizeof( V_80 ) ;
F_6 ( V_14 , V_15 , V_2 , V_142 ) ;
* V_14 += V_2 ;
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
while ( V_2 -- ) {
T_2 V_151 ;
V_19 V_163 ;
F_6 ( V_14 , V_15 , 2 * sizeof( V_19 ) , V_142 ) ;
V_151 = F_7 ( V_14 ) ;
V_163 = F_7 ( V_14 ) ;
F_20 ( V_151 >= V_104 -> V_135 ) ;
F_72 ( L_45 , V_151 , V_163 ,
V_163 == V_164 ? L_46 :
( V_163 == V_136 ? L_47 : L_48 ) ) ;
V_104 -> V_129 [ V_151 ] = V_163 ;
if ( V_163 ) {
V_104 -> V_128 [ V_151 ] |= V_4 ;
V_104 -> V_128 [ V_151 ] &= ~ ( V_165 |
V_166 ) ;
}
}
V_162 = * V_14 ;
* V_14 = V_161 ;
V_2 = F_7 ( V_14 ) ;
while ( V_2 -- ) {
T_2 V_151 ;
V_80 V_167 ;
int V_148 ;
V_151 = F_7 ( V_14 ) ;
V_167 = F_22 ( V_14 ) ;
if ( V_167 == 0 )
V_167 = V_5 ;
F_20 ( V_151 >= V_104 -> V_135 ) ;
if ( ( V_104 -> V_128 [ V_151 ] & V_5 ) &&
( V_167 & V_5 ) )
F_72 ( L_49 , V_151 ) ;
if ( ( V_104 -> V_128 [ V_151 ] & V_4 ) &&
( V_167 & V_4 ) ) {
F_72 ( L_50 , V_151 ) ;
V_104 -> V_129 [ V_151 ] = V_164 ;
V_148 = F_69 ( V_104 , V_151 ,
V_138 ) ;
if ( V_148 )
return V_148 ;
memset ( V_104 -> V_130 + V_151 , 0 , sizeof( * V_104 -> V_130 ) ) ;
V_104 -> V_128 [ V_151 ] = 0 ;
} else {
V_104 -> V_128 [ V_151 ] ^= V_167 ;
}
}
* V_14 = V_160 ;
V_2 = F_7 ( V_14 ) ;
while ( V_2 -- ) {
T_2 V_151 ;
struct V_133 V_134 ;
V_151 = F_7 ( V_14 ) ;
F_74 ( V_14 , & V_134 , sizeof( V_134 ) ) ;
F_75 ( & V_134 ) ;
F_20 ( V_151 >= V_104 -> V_135 ) ;
F_72 ( L_51 , V_151 ) ;
V_104 -> V_128 [ V_151 ] |= V_4 | V_5 ;
V_104 -> V_130 [ V_151 ] = V_134 ;
}
* V_14 = V_162 ;
return 0 ;
V_142:
return - V_22 ;
}
struct V_103 * F_82 ( void * * V_14 , void * V_15 ,
struct V_103 * V_104 )
{
struct V_35 * V_168 = NULL ;
struct V_169 V_155 ;
V_19 V_153 = 0 ;
struct V_170 V_157 ;
T_2 V_2 ;
V_95 V_86 ;
T_3 V_171 ;
V_65 V_172 , V_132 ;
void * V_40 = * V_14 ;
int V_38 ;
V_80 V_141 ;
F_5 ( L_40 , V_154 , * V_14 , V_15 , ( int ) ( V_15 - * V_14 ) ) ;
V_38 = F_56 ( V_14 , V_15 , L_52 , & V_141 ) ;
if ( V_38 )
goto V_20;
F_6 ( V_14 , V_15 , sizeof( V_155 ) + sizeof( V_19 ) + sizeof( V_157 ) +
sizeof( V_95 ) + sizeof( V_19 ) , V_142 ) ;
F_74 ( V_14 , & V_155 , sizeof( V_155 ) ) ;
V_153 = F_7 ( V_14 ) ;
F_20 ( V_153 != V_104 -> V_153 + 1 ) ;
F_74 ( V_14 , & V_157 , sizeof( V_157 ) ) ;
V_171 = F_46 ( V_14 ) ;
V_172 = F_7 ( V_14 ) ;
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
if ( V_2 > 0 ) {
F_5 ( L_53 ,
V_2 , * V_14 , V_15 ) ;
return F_80 ( V_14 , F_76 ( * V_14 + V_2 , V_15 ) ) ;
}
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
if ( V_2 > 0 ) {
V_168 = F_16 ( * V_14 , F_76 ( * V_14 + V_2 , V_15 ) ) ;
if ( F_77 ( V_168 ) ) {
V_38 = F_78 ( V_168 ) ;
V_168 = NULL ;
goto V_20;
}
* V_14 += V_2 ;
}
if ( V_172 >= 0 )
V_104 -> V_116 = V_172 ;
if ( V_171 >= 0 )
V_104 -> V_123 = V_171 ;
F_15 ( V_14 , V_15 , V_132 , V_142 ) ;
if ( V_132 >= 0 ) {
V_38 = F_54 ( V_104 , V_132 ) ;
if ( V_38 )
goto V_20;
}
V_104 -> V_153 ++ ;
V_104 -> V_157 = V_157 ;
if ( V_168 ) {
if ( V_104 -> V_127 )
F_25 ( V_104 -> V_127 ) ;
V_104 -> V_127 = V_168 ;
V_168 = NULL ;
}
V_38 = F_60 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
V_38 = F_47 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
F_15 ( V_14 , V_15 , V_2 , V_142 ) ;
while ( V_2 -- ) {
struct V_8 * V_9 ;
F_48 ( V_14 , V_15 , V_86 , V_142 ) ;
V_9 = F_36 ( & V_104 -> V_105 , V_86 ) ;
if ( V_9 )
F_43 ( & V_104 -> V_105 , V_9 ) ;
}
V_38 = F_81 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
V_38 = F_64 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
if ( V_141 >= 1 ) {
V_38 = F_67 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
}
if ( V_141 >= 2 ) {
V_38 = F_71 ( V_14 , V_15 , V_104 ) ;
if ( V_38 )
goto V_20;
}
* V_14 = V_15 ;
F_5 ( L_54 , V_104 -> V_153 , V_104 -> V_135 ) ;
return V_104 ;
V_142:
V_38 = - V_22 ;
V_20:
F_19 ( L_55 ,
V_38 , V_153 , ( int ) ( * V_14 - V_40 ) , * V_14 , V_40 , V_15 ) ;
F_79 ( V_158 , L_44 ,
V_159 , 16 , 1 ,
V_40 , V_15 - V_40 , true ) ;
if ( V_168 )
F_25 ( V_168 ) ;
return F_18 ( V_38 ) ;
}
void F_83 ( struct V_173 * V_174 ,
const struct V_173 * V_175 )
{
F_84 ( ! F_85 ( V_174 ) ) ;
if ( V_175 -> V_108 != V_175 -> V_176 ) {
V_174 -> V_108 = F_23 ( V_175 -> V_177 + 1 ,
V_121 | V_178 ) ;
}
memcpy ( V_174 -> V_108 , V_175 -> V_108 , V_175 -> V_177 + 1 ) ;
V_174 -> V_177 = V_175 -> V_177 ;
}
void F_86 ( struct V_173 * V_179 )
{
if ( V_179 -> V_108 != V_179 -> V_176 )
F_34 ( V_179 -> V_108 ) ;
}
static bool F_87 ( const struct V_180 * V_84 ,
const struct V_180 * V_85 )
{
if ( V_84 -> V_18 == V_85 -> V_18 &&
! memcmp ( V_84 -> V_150 , V_85 -> V_150 , V_85 -> V_18 * sizeof( V_85 -> V_150 [ 0 ] ) ) )
return true ;
return false ;
}
static bool F_88 ( const struct V_180 * V_84 ,
const struct V_180 * V_85 )
{
if ( F_87 ( V_84 , V_85 ) &&
V_84 -> V_181 == V_85 -> V_181 )
return true ;
return false ;
}
static bool F_89 ( const struct V_180 * V_182 )
{
if ( V_182 -> V_18 > 0 && V_182 -> V_181 >= 0 )
return true ;
if ( ! V_182 -> V_18 && V_182 -> V_181 == - 1 )
return true ;
if ( V_182 -> V_18 > 0 && V_182 -> V_181 == - 1 ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_182 -> V_18 ; V_39 ++ ) {
if ( V_182 -> V_150 [ V_39 ] != V_183 )
break;
}
if ( V_39 == V_182 -> V_18 )
return true ;
}
return false ;
}
void F_90 ( struct V_180 * V_174 , const struct V_180 * V_175 )
{
memcpy ( V_174 -> V_150 , V_175 -> V_150 , V_175 -> V_18 * sizeof( V_175 -> V_150 [ 0 ] ) ) ;
V_174 -> V_18 = V_175 -> V_18 ;
V_174 -> V_181 = V_175 -> V_181 ;
}
static bool F_91 ( const struct V_83 * V_96 ,
V_19 V_184 ,
V_19 V_185 )
{
int V_186 = F_2 ( V_184 ) ;
int V_187 = ( 1 << V_186 ) - 1 ;
int V_101 ;
F_84 ( V_96 -> V_87 >= V_184 ) ;
if ( V_185 <= V_184 )
return false ;
for ( V_101 = 1 ; ; V_101 ++ ) {
int V_188 = V_101 << ( V_186 - 1 ) ;
V_19 V_189 = V_188 | V_96 -> V_87 ;
if ( V_189 < V_184 || V_189 == V_96 -> V_87 )
continue;
if ( V_189 >= V_185 )
break;
V_189 = F_92 ( V_189 , V_184 , V_187 ) ;
if ( V_189 == V_96 -> V_87 )
return true ;
}
return false ;
}
bool F_93 ( const struct V_180 * V_190 ,
const struct V_180 * V_191 ,
const struct V_180 * V_192 ,
const struct V_180 * V_193 ,
int V_194 ,
int V_195 ,
int V_196 ,
int V_197 ,
V_19 V_184 ,
V_19 V_185 ,
bool V_198 ,
bool V_199 ,
const struct V_83 * V_96 )
{
return ! F_88 ( V_190 , V_191 ) ||
! F_88 ( V_192 , V_193 ) ||
V_194 != V_195 ||
V_196 != V_197 ||
F_91 ( V_96 , V_184 , V_185 ) ||
V_198 != V_199 ;
}
static int F_94 ( int V_151 , const struct V_180 * V_200 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_200 -> V_18 ; V_39 ++ ) {
if ( V_200 -> V_150 [ V_39 ] == V_151 )
return V_39 ;
}
return - 1 ;
}
static bool F_95 ( const struct V_180 * V_190 ,
const struct V_180 * V_191 )
{
if ( ! V_190 -> V_18 && ! V_191 -> V_18 )
return false ;
if ( ! V_190 -> V_18 ^ ! V_191 -> V_18 )
return true ;
if ( V_190 -> V_181 != V_191 -> V_181 )
return true ;
if ( F_94 ( V_190 -> V_181 , V_190 ) !=
F_94 ( V_191 -> V_181 , V_191 ) )
return true ;
return false ;
}
bool F_96 ( const struct V_180 * V_190 ,
const struct V_180 * V_191 ,
bool V_201 )
{
if ( F_95 ( V_190 , V_191 ) )
return true ;
if ( V_201 && ! F_87 ( V_190 , V_191 ) )
return true ;
return false ;
}
int F_97 ( struct V_202 * V_203 ,
V_95 V_204 , V_95 V_2 ,
V_95 * V_205 ,
V_95 * V_206 , V_95 * V_207 )
{
V_19 V_208 = F_98 ( V_203 -> V_209 ) ;
V_19 V_210 = F_98 ( V_203 -> V_211 ) ;
V_19 V_212 = F_98 ( V_203 -> V_213 ) ;
V_19 V_214 , V_215 , V_216 , V_217 ;
V_19 V_218 ;
V_95 V_6 , V_219 ;
F_5 ( L_56 , V_204 , V_2 ,
V_208 , V_210 ) ;
if ( V_210 == 0 || V_212 == 0 )
goto V_220;
V_218 = V_208 / V_210 ;
if ( V_218 == 0 )
goto V_220;
F_5 ( L_57 , V_208 , V_210 ,
V_218 ) ;
if ( ( V_210 & ~ V_221 ) != 0 )
goto V_220;
V_6 = V_204 ;
F_99 ( V_6 , V_210 ) ;
V_214 = V_6 ;
F_5 ( L_58 , V_204 , V_210 , V_214 ) ;
V_215 = V_214 / V_212 ;
V_216 = V_214 % V_212 ;
V_217 = V_215 / V_218 ;
* V_205 = V_217 * V_212 + V_216 ;
F_5 ( L_59 , V_217 , V_212 , ( unsigned int ) * V_205 ) ;
V_6 = V_204 ;
V_219 = F_99 ( V_6 , V_210 ) ;
* V_206 = V_219 + ( V_215 % V_218 ) * V_210 ;
* V_207 = F_100 ( V_95 , V_2 , V_210 - V_219 ) ;
F_5 ( L_60 , * V_206 , * V_207 ) ;
return 0 ;
V_220:
F_5 ( L_61 ) ;
* V_205 = 0 ;
* V_206 = 0 ;
* V_207 = 0 ;
return - V_22 ;
}
int F_101 ( struct V_103 * V_222 ,
struct V_173 * V_179 ,
struct V_223 * V_224 ,
struct V_83 * V_225 )
{
struct V_8 * V_9 ;
V_9 = F_37 ( V_222 , V_224 -> V_86 ) ;
if ( ! V_9 )
return - V_102 ;
V_225 -> V_86 = V_224 -> V_86 ;
V_225 -> V_87 = F_102 ( V_9 -> V_115 , V_179 -> V_108 ,
V_179 -> V_177 ) ;
F_5 ( L_62 , V_154 , V_179 -> V_108 ,
V_225 -> V_86 , V_225 -> V_87 ) ;
return 0 ;
}
static void F_103 ( struct V_8 * V_9 ,
const struct V_83 * V_225 ,
struct V_83 * V_96 )
{
V_96 -> V_86 = V_225 -> V_86 ;
V_96 -> V_87 = F_92 ( V_225 -> V_87 , V_9 -> V_11 ,
V_9 -> V_10 ) ;
}
static V_19 F_104 ( struct V_8 * V_9 ,
const struct V_83 * V_225 )
{
if ( V_9 -> V_116 & V_226 ) {
return F_105 ( V_227 ,
F_92 ( V_225 -> V_87 ,
V_9 -> V_13 ,
V_9 -> V_12 ) ,
V_225 -> V_86 ) ;
} else {
return F_92 ( V_225 -> V_87 , V_9 -> V_13 ,
V_9 -> V_12 ) +
( unsigned ) V_225 -> V_86 ;
}
}
static int F_106 ( struct V_103 * V_104 , int V_228 , int V_229 ,
int * V_230 , int V_231 ,
const T_4 * V_63 , int V_232 )
{
int V_70 ;
F_20 ( V_231 > V_233 ) ;
F_107 ( & V_104 -> V_126 ) ;
V_70 = F_108 ( V_104 -> V_127 , V_228 , V_229 , V_230 , V_231 ,
V_63 , V_232 , V_104 -> V_234 ) ;
F_109 ( & V_104 -> V_126 ) ;
return V_70 ;
}
static void F_110 ( struct V_103 * V_222 ,
struct V_8 * V_9 ,
const struct V_83 * V_225 ,
struct V_180 * V_235 ,
V_19 * V_236 )
{
V_19 V_237 = F_104 ( V_9 , V_225 ) ;
int V_228 ;
int V_2 ;
F_111 ( V_235 ) ;
if ( V_236 )
* V_236 = V_237 ;
V_228 = F_112 ( V_222 -> V_127 , V_9 -> V_114 , V_9 -> type ,
V_9 -> V_18 ) ;
if ( V_228 < 0 ) {
F_19 ( L_63 ,
V_9 -> V_61 , V_9 -> V_114 , V_9 -> type , V_9 -> V_18 ) ;
return;
}
V_2 = F_106 ( V_222 , V_228 , V_237 , V_235 -> V_150 ,
F_100 ( int , V_9 -> V_18 , F_113 ( V_235 -> V_150 ) ) ,
V_222 -> V_129 , V_222 -> V_135 ) ;
if ( V_2 < 0 ) {
F_19 ( L_64 ,
V_2 , V_228 , V_9 -> V_61 , V_9 -> V_114 , V_9 -> type ,
V_9 -> V_18 ) ;
return;
}
V_235 -> V_18 = V_2 ;
}
static void F_114 ( struct V_103 * V_222 ,
struct V_8 * V_9 ,
struct V_180 * V_182 )
{
int V_39 ;
F_20 ( V_182 -> V_181 != - 1 ) ;
if ( F_115 ( V_9 ) ) {
int V_238 = 0 ;
for ( V_39 = 0 ; V_39 < V_182 -> V_18 ; V_39 ++ ) {
if ( F_116 ( V_222 , V_182 -> V_150 [ V_39 ] ) ) {
V_238 ++ ;
continue;
}
if ( V_238 )
V_182 -> V_150 [ V_39 - V_238 ] = V_182 -> V_150 [ V_39 ] ;
}
V_182 -> V_18 -= V_238 ;
if ( V_182 -> V_18 > 0 )
V_182 -> V_181 = V_182 -> V_150 [ 0 ] ;
} else {
for ( V_39 = V_182 -> V_18 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( F_116 ( V_222 , V_182 -> V_150 [ V_39 ] ) )
V_182 -> V_150 [ V_39 ] = V_183 ;
else
V_182 -> V_181 = V_182 -> V_150 [ V_39 ] ;
}
}
}
static void F_117 ( struct V_103 * V_222 ,
struct V_8 * V_9 ,
V_19 V_237 ,
struct V_180 * V_239 )
{
int V_39 ;
int V_240 = - 1 ;
if ( ! V_222 -> V_131 )
return;
for ( V_39 = 0 ; V_39 < V_239 -> V_18 ; V_39 ++ ) {
int V_151 = V_239 -> V_150 [ V_39 ] ;
if ( V_151 != V_183 &&
V_222 -> V_131 [ V_151 ] !=
V_138 ) {
break;
}
}
if ( V_39 == V_239 -> V_18 )
return;
for ( V_39 = 0 ; V_39 < V_239 -> V_18 ; V_39 ++ ) {
int V_151 = V_239 -> V_150 [ V_39 ] ;
V_19 V_152 ;
if ( V_151 == V_183 )
continue;
V_152 = V_222 -> V_131 [ V_151 ] ;
if ( V_152 < V_241 &&
( F_105 ( V_227 ,
V_237 , V_151 ) >> 16 ) >= V_152 ) {
if ( V_240 < 0 )
V_240 = V_39 ;
} else {
V_240 = V_39 ;
break;
}
}
if ( V_240 < 0 )
return;
V_239 -> V_181 = V_239 -> V_150 [ V_240 ] ;
if ( F_115 ( V_9 ) && V_240 > 0 ) {
for ( V_39 = V_240 ; V_39 > 0 ; V_39 -- )
V_239 -> V_150 [ V_39 ] = V_239 -> V_150 [ V_39 - 1 ] ;
V_239 -> V_150 [ 0 ] = V_239 -> V_181 ;
}
}
static void F_118 ( struct V_103 * V_222 ,
struct V_8 * V_9 ,
const struct V_83 * V_225 ,
struct V_180 * V_242 )
{
struct V_83 V_96 ;
struct V_88 * V_94 ;
int V_39 ;
F_103 ( V_9 , V_225 , & V_96 ) ;
F_111 ( V_242 ) ;
V_94 = F_31 ( & V_222 -> V_124 , V_96 ) ;
if ( V_94 ) {
for ( V_39 = 0 ; V_39 < V_94 -> V_124 . V_2 ; V_39 ++ ) {
if ( F_116 ( V_222 , V_94 -> V_124 . V_150 [ V_39 ] ) ) {
if ( F_115 ( V_9 ) )
continue;
V_242 -> V_150 [ V_242 -> V_18 ++ ] = V_183 ;
} else {
V_242 -> V_150 [ V_242 -> V_18 ++ ] = V_94 -> V_124 . V_150 [ V_39 ] ;
}
}
for ( V_39 = 0 ; V_39 < V_242 -> V_18 ; V_39 ++ ) {
if ( V_242 -> V_150 [ V_39 ] != V_183 ) {
V_242 -> V_181 = V_242 -> V_150 [ V_39 ] ;
break;
}
}
}
V_94 = F_31 ( & V_222 -> V_125 , V_96 ) ;
if ( V_94 )
V_242 -> V_181 = V_94 -> V_125 . V_151 ;
}
void F_119 ( struct V_103 * V_222 ,
const struct V_83 * V_225 ,
struct V_180 * V_239 ,
struct V_180 * V_200 )
{
struct V_8 * V_9 ;
V_19 V_237 ;
V_9 = F_37 ( V_222 , V_225 -> V_86 ) ;
if ( ! V_9 ) {
F_111 ( V_239 ) ;
F_111 ( V_200 ) ;
goto V_243;
}
F_110 ( V_222 , V_9 , V_225 , V_239 , & V_237 ) ;
F_114 ( V_222 , V_9 , V_239 ) ;
F_117 ( V_222 , V_9 , V_237 , V_239 ) ;
F_118 ( V_222 , V_9 , V_225 , V_200 ) ;
if ( ! V_200 -> V_18 ) {
memcpy ( V_200 -> V_150 , V_239 -> V_150 , V_239 -> V_18 * sizeof( V_239 -> V_150 [ 0 ] ) ) ;
V_200 -> V_18 = V_239 -> V_18 ;
if ( V_200 -> V_181 == - 1 )
V_200 -> V_181 = V_239 -> V_181 ;
}
V_243:
F_84 ( ! F_89 ( V_239 ) || ! F_89 ( V_200 ) ) ;
}
int F_120 ( struct V_103 * V_222 ,
const struct V_83 * V_225 )
{
struct V_180 V_239 , V_200 ;
F_119 ( V_222 , V_225 , & V_239 , & V_200 ) ;
return V_200 . V_181 ;
}
