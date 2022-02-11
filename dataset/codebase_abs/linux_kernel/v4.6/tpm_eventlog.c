static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 ;
struct V_5 * log = V_2 -> V_6 ;
void * V_7 = log -> V_8 ;
void * V_9 = log -> V_10 ;
struct V_11 * V_12 ;
T_2 V_13 ;
T_2 V_14 ;
for ( V_4 = 0 ; V_4 < * V_3 ; V_4 ++ ) {
V_12 = V_7 ;
V_13 =
F_2 ( V_12 -> V_15 ) ;
V_14 =
F_2 ( V_12 -> V_16 ) ;
if ( ( V_7 + sizeof( struct V_11 ) ) < V_9 ) {
if ( ( V_14 == 0 ) &&
( V_13 == 0 ) )
return NULL ;
V_7 += ( sizeof( struct V_11 ) +
V_13 ) ;
}
}
if ( ( V_7 + sizeof( struct V_11 ) ) >= V_9 )
return NULL ;
V_12 = V_7 ;
V_13 = F_2 ( V_12 -> V_15 ) ;
V_14 = F_2 ( V_12 -> V_16 ) ;
if ( ( ( V_14 == 0 ) && ( V_13 == 0 ) )
|| ( ( V_7 + sizeof( struct V_11 ) + V_13 )
>= V_9 ) )
return NULL ;
return V_7 ;
}
static void * F_3 ( struct V_1 * V_2 , void * V_17 ,
T_1 * V_3 )
{
struct V_11 * V_12 = V_17 ;
struct V_5 * log = V_2 -> V_6 ;
void * V_9 = log -> V_10 ;
T_2 V_13 ;
T_2 V_14 ;
V_13 = F_2 ( V_12 -> V_15 ) ;
V_17 += sizeof( struct V_11 ) + V_13 ;
if ( ( V_17 + sizeof( struct V_11 ) ) >= V_9 )
return NULL ;
V_12 = V_17 ;
V_13 = F_2 ( V_12 -> V_15 ) ;
V_14 = F_2 ( V_12 -> V_16 ) ;
if ( ( ( V_14 == 0 ) && ( V_13 == 0 ) ) ||
( ( V_17 + sizeof( struct V_11 ) + V_13 ) >= V_9 ) )
return NULL ;
( * V_3 ) ++ ;
return V_17 ;
}
static void F_4 ( struct V_1 * V_2 , void * V_17 )
{
}
static int F_5 ( char * V_18 , struct V_11 * V_12 ,
unsigned char * V_19 )
{
const char * V_20 = L_1 ;
char V_21 [ 41 ] = L_1 ;
int V_4 , V_22 = 0 , V_23 = 0 ;
struct V_24 * V_25 ;
switch ( F_2 ( V_12 -> V_16 ) ) {
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
case V_39 :
case V_40 :
V_20 = V_41 [ F_2
( V_12 -> V_16 ) ] ;
V_22 = strlen ( V_20 ) ;
break;
case V_42 :
case V_43 :
if ( V_44 >
F_2 ( V_12 -> V_15 ) ) {
V_20 = V_19 ;
V_22 = F_2 ( V_12 -> V_15 ) ;
}
break;
case V_45 :
V_25 = (struct V_24 * ) V_19 ;
switch ( F_2 ( V_25 -> V_46 ) ) {
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_20 = V_54 [ F_2
( V_25 -> V_46 ) ] ;
V_22 = strlen ( V_20 ) ;
break;
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_20 = V_54 [ F_2
( V_25 -> V_46 ) ] ;
V_22 = strlen ( V_20 ) ;
for ( V_4 = 0 ; V_4 < 20 ; V_4 ++ )
V_23 += sprintf ( & V_21 [ 2 * V_4 ] , L_2 ,
V_25 -> V_60 [ V_4 ] ) ;
break;
default:
break;
}
default:
break;
}
return snprintf ( V_18 , V_44 , L_3 ,
V_22 , V_20 , V_23 , V_21 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_17 )
{
struct V_11 * V_12 = V_17 ;
struct V_11 V_61 ;
char * V_62 ;
int V_4 ;
memcpy ( & V_61 , V_12 , sizeof( struct V_11 ) ) ;
V_61 . V_63 = F_2 ( V_12 -> V_63 ) ;
V_61 . V_16 = F_2 ( V_12 -> V_16 ) ;
V_61 . V_15 = F_2 ( V_12 -> V_15 ) ;
V_62 = ( char * ) & V_61 ;
for ( V_4 = 0 ; V_4 < ( sizeof( struct V_11 ) - 1 ) ; V_4 ++ )
F_7 ( V_2 , V_62 [ V_4 ] ) ;
V_62 = ( char * ) V_17 ;
for ( V_4 = ( sizeof( struct V_11 ) - 1 ) ;
V_4 < ( sizeof( struct V_11 ) + V_61 . V_15 ) ; V_4 ++ )
F_7 ( V_2 , V_62 [ V_4 ] ) ;
return 0 ;
}
static int F_8 ( struct V_64 * V_64 ,
struct V_65 * V_65 )
{
struct V_1 * V_66 = V_65 -> V_67 ;
struct V_5 * log = V_66 -> V_6 ;
if ( log ) {
F_9 ( log -> V_8 ) ;
F_9 ( log ) ;
}
return F_10 ( V_64 , V_65 ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_17 )
{
int V_68 = 0 ;
char * V_69 ;
struct V_11 * V_12 = V_17 ;
unsigned char * V_19 =
( unsigned char * ) ( V_17 + sizeof( struct V_11 ) ) ;
V_69 = F_12 ( V_44 , V_70 ) ;
if ( ! V_69 ) {
F_13 ( V_71 L_4 ,
V_72 ) ;
return - V_73 ;
}
F_14 ( V_2 , L_5 , F_2 ( V_12 -> V_63 ) ) ;
F_14 ( V_2 , L_6 , V_12 -> V_74 ) ;
F_14 ( V_2 , L_7 , F_2 ( V_12 -> V_16 ) ) ;
V_68 += F_5 ( V_69 , V_12 , V_19 ) ;
F_14 ( V_2 , L_8 , V_69 ) ;
F_9 ( V_69 ) ;
return 0 ;
}
static int F_15 ( struct V_64 * V_64 ,
struct V_65 * V_65 )
{
int V_75 ;
struct V_5 * log ;
struct V_1 * V_66 ;
log = F_16 ( sizeof( struct V_5 ) , V_70 ) ;
if ( ! log )
return - V_76 ;
if ( ( V_75 = F_17 ( log ) ) )
goto V_77;
V_75 = F_18 ( V_65 , & V_78 ) ;
if ( ! V_75 ) {
V_66 = V_65 -> V_67 ;
V_66 -> V_6 = log ;
} else {
goto V_77;
}
V_79:
return V_75 ;
V_77:
F_9 ( log -> V_8 ) ;
F_9 ( log ) ;
goto V_79;
}
static int F_19 ( struct V_64 * V_64 ,
struct V_65 * V_65 )
{
int V_75 ;
struct V_5 * log ;
struct V_1 * V_66 ;
log = F_16 ( sizeof( struct V_5 ) , V_70 ) ;
if ( ! log )
return - V_76 ;
if ( ( V_75 = F_17 ( log ) ) )
goto V_77;
V_75 = F_18 ( V_65 , & V_80 ) ;
if ( ! V_75 ) {
V_66 = V_65 -> V_67 ;
V_66 -> V_6 = log ;
} else {
goto V_77;
}
V_79:
return V_75 ;
V_77:
F_9 ( log -> V_8 ) ;
F_9 ( log ) ;
goto V_79;
}
static int F_20 ( void * V_81 )
{
if ( ! V_81 )
return 1 ;
if ( F_21 ( V_81 ) && ( F_22 ( V_81 ) != - V_82 ) )
return 1 ;
return 0 ;
}
struct V_83 * * F_23 ( char * V_20 )
{
struct V_83 * * V_84 = NULL , * V_85 , * V_86 , * V_87 ;
V_85 = F_24 ( V_20 , NULL ) ;
if ( F_20 ( V_85 ) )
goto V_79;
V_86 =
F_25 ( L_9 ,
V_88 | V_89 , V_85 , NULL ,
& V_90 ) ;
if ( F_20 ( V_86 ) )
goto V_91;
V_87 =
F_25 ( L_10 ,
V_88 | V_89 , V_85 , NULL ,
& V_92 ) ;
if ( F_20 ( V_87 ) )
goto V_93;
V_84 = F_12 ( 3 * sizeof( struct V_83 * ) , V_70 ) ;
if ( ! V_84 )
goto V_94;
V_84 [ 0 ] = V_87 ;
V_84 [ 1 ] = V_86 ;
V_84 [ 2 ] = V_85 ;
return V_84 ;
V_94:
F_26 ( V_87 ) ;
V_93:
F_26 ( V_86 ) ;
V_91:
F_26 ( V_85 ) ;
V_79:
return NULL ;
}
void F_27 ( struct V_83 * * V_95 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ )
F_26 ( V_95 [ V_4 ] ) ;
}
