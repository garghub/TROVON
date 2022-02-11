static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 ;
struct V_5 * log = V_2 -> V_6 ;
void * V_7 = log -> V_8 ;
void * V_9 = log -> V_10 ;
struct V_11 * V_12 ;
for ( V_4 = 0 ; V_4 < * V_3 ; V_4 ++ ) {
V_12 = V_7 ;
if ( ( V_7 + sizeof( struct V_11 ) ) < V_9 ) {
if ( V_12 -> V_13 == 0 && V_12 -> V_14 == 0 )
return NULL ;
V_7 += sizeof( struct V_11 ) + V_12 -> V_14 ;
}
}
if ( ( V_7 + sizeof( struct V_11 ) ) >= V_9 )
return NULL ;
V_12 = V_7 ;
if ( ( V_12 -> V_13 == 0 && V_12 -> V_14 == 0 ) ||
( ( V_7 + sizeof( struct V_11 ) + V_12 -> V_14 ) >= V_9 ) )
return NULL ;
return V_7 ;
}
static void * F_2 ( struct V_1 * V_2 , void * V_15 ,
T_1 * V_3 )
{
struct V_11 * V_12 = V_15 ;
struct V_5 * log = V_2 -> V_6 ;
void * V_9 = log -> V_10 ;
V_15 += sizeof( struct V_11 ) + V_12 -> V_14 ;
if ( ( V_15 + sizeof( struct V_11 ) ) >= V_9 )
return NULL ;
V_12 = V_15 ;
if ( V_12 -> V_13 == 0 && V_12 -> V_14 == 0 )
return NULL ;
if ( ( V_12 -> V_13 == 0 && V_12 -> V_14 == 0 ) ||
( ( V_15 + sizeof( struct V_11 ) + V_12 -> V_14 ) >= V_9 ) )
return NULL ;
( * V_3 ) ++ ;
return V_15 ;
}
static void F_3 ( struct V_1 * V_2 , void * V_15 )
{
}
static int F_4 ( char * V_16 , struct V_11 * V_12 ,
unsigned char * V_17 )
{
const char * V_18 = L_1 ;
char V_19 [ 41 ] = L_1 ;
int V_4 , V_20 = 0 , V_21 = 0 ;
struct V_22 * V_23 ;
switch( V_12 -> V_13 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_18 = V_39 [ V_12 -> V_13 ] ;
V_20 = strlen ( V_18 ) ;
break;
case V_40 :
case V_41 :
if ( V_42 > V_12 -> V_14 ) {
V_18 = V_17 ;
V_20 = V_12 -> V_14 ;
}
break;
case V_43 :
V_23 = (struct V_22 * ) V_17 ;
switch ( V_23 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_18 = V_52 [ V_23 -> V_44 ] ;
V_20 = strlen ( V_18 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_18 = V_52 [ V_23 -> V_44 ] ;
V_20 = strlen ( V_18 ) ;
for ( V_4 = 0 ; V_4 < 20 ; V_4 ++ )
V_21 += sprintf ( & V_19 [ 2 * V_4 ] , L_2 ,
V_23 -> V_58 [ V_4 ] ) ;
break;
default:
break;
}
default:
break;
}
return snprintf ( V_16 , V_42 , L_3 ,
V_20 , V_18 , V_21 , V_19 ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_15 )
{
struct V_11 * V_12 = V_15 ;
char * V_19 = V_15 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < sizeof( struct V_11 ) + V_12 -> V_14 ; V_4 ++ )
F_6 ( V_2 , V_19 [ V_4 ] ) ;
return 0 ;
}
static int F_7 ( struct V_59 * V_59 ,
struct V_60 * V_60 )
{
struct V_1 * V_61 = V_60 -> V_62 ;
struct V_5 * log = V_61 -> V_6 ;
if ( log ) {
F_8 ( log -> V_8 ) ;
F_8 ( log ) ;
}
return F_9 ( V_59 , V_60 ) ;
}
static int F_10 ( struct V_1 * V_2 , void * V_15 )
{
int V_63 = 0 ;
int V_4 ;
char * V_64 ;
struct V_11 * V_12 = V_15 ;
unsigned char * V_17 =
( unsigned char * ) ( V_15 + sizeof( struct V_11 ) ) ;
V_64 = F_11 ( V_42 , V_65 ) ;
if ( ! V_64 ) {
F_12 ( V_66 L_4 ,
V_67 ) ;
return - V_68 ;
}
F_13 ( V_2 , L_5 , V_12 -> V_69 ) ;
for ( V_4 = 0 ; V_4 < 20 ; V_4 ++ )
F_13 ( V_2 , L_2 , V_12 -> V_70 [ V_4 ] ) ;
F_13 ( V_2 , L_6 , V_12 -> V_13 ) ;
V_63 += F_4 ( V_64 , V_12 , V_17 ) ;
F_13 ( V_2 , L_7 , V_64 ) ;
F_8 ( V_64 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * log )
{
struct V_71 * V_72 ;
T_2 V_73 ;
struct V_74 * V_75 ;
T_3 V_63 , V_76 ;
if ( log -> V_8 != NULL ) {
F_12 ( V_66
L_8 ,
V_67 ) ;
return - V_68 ;
}
V_73 = F_15 ( V_77 , 1 ,
(struct V_74 * * ) & V_72 ) ;
if ( F_16 ( V_73 ) ) {
F_12 ( V_66 L_9 ,
V_67 ) ;
return - V_78 ;
}
switch( V_72 -> V_79 ) {
case V_80 :
V_63 = V_72 -> V_81 . V_82 ;
V_76 = V_72 -> V_81 . V_83 ;
break;
case V_84 :
default:
V_63 = V_72 -> V_85 . V_82 ;
V_76 = V_72 -> V_85 . V_83 ;
break;
}
if ( ! V_63 ) {
F_12 ( V_66 L_10 , V_67 ) ;
return - V_78 ;
}
log -> V_8 = F_11 ( V_63 , V_65 ) ;
if ( ! log -> V_8 ) {
F_12 ( L_11 ,
V_67 ) ;
return - V_86 ;
}
log -> V_10 = log -> V_8 + V_63 ;
V_75 = F_17 ( V_76 , V_63 ) ;
memcpy ( log -> V_8 , V_75 , V_63 ) ;
F_18 ( V_75 , V_63 ) ;
return 0 ;
}
static int F_19 ( struct V_59 * V_59 ,
struct V_60 * V_60 )
{
int V_87 ;
struct V_5 * log ;
struct V_1 * V_61 ;
log = F_20 ( sizeof( struct V_5 ) , V_65 ) ;
if ( ! log )
return - V_86 ;
if ( ( V_87 = F_14 ( log ) ) )
goto V_88;
V_87 = F_21 ( V_60 , & V_89 ) ;
if ( ! V_87 ) {
V_61 = V_60 -> V_62 ;
V_61 -> V_6 = log ;
} else {
goto V_88;
}
V_90:
return V_87 ;
V_88:
F_8 ( log -> V_8 ) ;
F_8 ( log ) ;
goto V_90;
}
static int F_22 ( struct V_59 * V_59 ,
struct V_60 * V_60 )
{
int V_87 ;
struct V_5 * log ;
struct V_1 * V_61 ;
log = F_20 ( sizeof( struct V_5 ) , V_65 ) ;
if ( ! log )
return - V_86 ;
if ( ( V_87 = F_14 ( log ) ) )
goto V_88;
V_87 = F_21 ( V_60 , & V_91 ) ;
if ( ! V_87 ) {
V_61 = V_60 -> V_62 ;
V_61 -> V_6 = log ;
} else {
goto V_88;
}
V_90:
return V_87 ;
V_88:
F_8 ( log -> V_8 ) ;
F_8 ( log ) ;
goto V_90;
}
static int F_23 ( void * V_92 )
{
if ( ! V_92 )
return 1 ;
if ( F_24 ( V_92 ) && ( F_25 ( V_92 ) != - V_93 ) )
return 1 ;
return 0 ;
}
struct V_94 * * F_26 ( char * V_18 )
{
struct V_94 * * V_95 = NULL , * V_96 , * V_97 , * V_98 ;
V_96 = F_27 ( V_18 , NULL ) ;
if ( F_23 ( V_96 ) )
goto V_90;
V_97 =
F_28 ( L_12 ,
V_99 | V_100 , V_96 , NULL ,
& V_101 ) ;
if ( F_23 ( V_97 ) )
goto V_102;
V_98 =
F_28 ( L_13 ,
V_99 | V_100 , V_96 , NULL ,
& V_103 ) ;
if ( F_23 ( V_98 ) )
goto V_104;
V_95 = F_11 ( 3 * sizeof( struct V_94 * ) , V_65 ) ;
if ( ! V_95 )
goto V_105;
V_95 [ 0 ] = V_98 ;
V_95 [ 1 ] = V_97 ;
V_95 [ 2 ] = V_96 ;
return V_95 ;
V_105:
F_29 ( V_98 ) ;
V_104:
F_29 ( V_97 ) ;
V_102:
F_29 ( V_96 ) ;
V_90:
return NULL ;
}
void F_30 ( struct V_94 * * V_106 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ )
F_29 ( V_106 [ V_4 ] ) ;
}
