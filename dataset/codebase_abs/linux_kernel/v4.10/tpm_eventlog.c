static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * log = & V_6 -> log ;
void * V_9 = log -> V_10 ;
void * V_11 = log -> V_12 ;
struct V_13 * V_14 ;
T_2 V_15 ;
T_2 V_16 ;
for ( V_4 = 0 ; V_4 < * V_3 ; V_4 ++ ) {
V_14 = V_9 ;
V_15 =
F_2 ( V_14 -> V_17 ) ;
V_16 =
F_2 ( V_14 -> V_18 ) ;
if ( ( V_9 + sizeof( struct V_13 ) ) < V_11 ) {
if ( ( V_16 == 0 ) &&
( V_15 == 0 ) )
return NULL ;
V_9 += ( sizeof( struct V_13 ) +
V_15 ) ;
}
}
if ( ( V_9 + sizeof( struct V_13 ) ) >= V_11 )
return NULL ;
V_14 = V_9 ;
V_15 = F_2 ( V_14 -> V_17 ) ;
V_16 = F_2 ( V_14 -> V_18 ) ;
if ( ( ( V_16 == 0 ) && ( V_15 == 0 ) )
|| ( ( V_9 + sizeof( struct V_13 ) + V_15 )
>= V_11 ) )
return NULL ;
return V_9 ;
}
static void * F_3 ( struct V_1 * V_2 , void * V_19 ,
T_1 * V_3 )
{
struct V_13 * V_14 = V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * log = & V_6 -> log ;
void * V_11 = log -> V_12 ;
T_2 V_15 ;
T_2 V_16 ;
V_15 = F_2 ( V_14 -> V_17 ) ;
V_19 += sizeof( struct V_13 ) + V_15 ;
if ( ( V_19 + sizeof( struct V_13 ) ) >= V_11 )
return NULL ;
V_14 = V_19 ;
V_15 = F_2 ( V_14 -> V_17 ) ;
V_16 = F_2 ( V_14 -> V_18 ) ;
if ( ( ( V_16 == 0 ) && ( V_15 == 0 ) ) ||
( ( V_19 + sizeof( struct V_13 ) + V_15 ) >= V_11 ) )
return NULL ;
( * V_3 ) ++ ;
return V_19 ;
}
static void F_4 ( struct V_1 * V_2 , void * V_19 )
{
}
static int F_5 ( char * V_20 , struct V_13 * V_14 ,
unsigned char * V_21 )
{
const char * V_22 = L_1 ;
char V_23 [ 41 ] = L_1 ;
int V_4 , V_24 = 0 , V_25 = 0 ;
struct V_26 * V_27 ;
switch ( F_2 ( V_14 -> V_18 ) ) {
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
case V_41 :
case V_42 :
V_22 = V_43 [ F_2
( V_14 -> V_18 ) ] ;
V_24 = strlen ( V_22 ) ;
break;
case V_44 :
case V_45 :
if ( V_46 >
F_2 ( V_14 -> V_17 ) ) {
V_22 = V_21 ;
V_24 = F_2 ( V_14 -> V_17 ) ;
}
break;
case V_47 :
V_27 = (struct V_26 * ) V_21 ;
switch ( F_2 ( V_27 -> V_48 ) ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
V_22 = V_56 [ F_2
( V_27 -> V_48 ) ] ;
V_24 = strlen ( V_22 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
V_22 = V_56 [ F_2
( V_27 -> V_48 ) ] ;
V_24 = strlen ( V_22 ) ;
for ( V_4 = 0 ; V_4 < 20 ; V_4 ++ )
V_25 += sprintf ( & V_23 [ 2 * V_4 ] , L_2 ,
V_27 -> V_62 [ V_4 ] ) ;
break;
default:
break;
}
default:
break;
}
return snprintf ( V_20 , V_46 , L_3 ,
V_24 , V_22 , V_25 , V_23 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_19 )
{
struct V_13 * V_14 = V_19 ;
struct V_13 V_63 ;
char * V_64 ;
int V_4 ;
memcpy ( & V_63 , V_14 , sizeof( struct V_13 ) ) ;
V_63 . V_65 = F_2 ( V_14 -> V_65 ) ;
V_63 . V_18 = F_2 ( V_14 -> V_18 ) ;
V_63 . V_17 = F_2 ( V_14 -> V_17 ) ;
V_64 = ( char * ) & V_63 ;
for ( V_4 = 0 ; V_4 < ( sizeof( struct V_13 ) - 1 ) ; V_4 ++ )
F_7 ( V_2 , V_64 [ V_4 ] ) ;
V_64 = ( char * ) V_19 ;
for ( V_4 = ( sizeof( struct V_13 ) - 1 ) ;
V_4 < ( sizeof( struct V_13 ) + V_63 . V_17 ) ; V_4 ++ )
F_7 ( V_2 , V_64 [ V_4 ] ) ;
return 0 ;
}
static int F_8 ( struct V_66 * V_66 ,
struct V_67 * V_67 )
{
struct V_1 * V_68 = (struct V_1 * ) V_67 -> V_69 ;
struct V_5 * V_6 = (struct V_5 * ) V_68 -> V_7 ;
F_9 ( & V_6 -> V_70 ) ;
return F_10 ( V_66 , V_67 ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_19 )
{
int V_71 = 0 ;
char * V_72 ;
struct V_13 * V_14 = V_19 ;
unsigned char * V_21 =
( unsigned char * ) ( V_19 + sizeof( struct V_13 ) ) ;
V_72 = F_12 ( V_46 , V_73 ) ;
if ( ! V_72 ) {
F_13 ( V_74 L_4 ,
V_75 ) ;
return - V_76 ;
}
F_14 ( V_2 , L_5 , F_2 ( V_14 -> V_65 ) ) ;
F_14 ( V_2 , L_6 , V_14 -> V_77 ) ;
F_14 ( V_2 , L_7 , F_2 ( V_14 -> V_18 ) ) ;
V_71 += F_5 ( V_72 , V_14 , V_21 ) ;
F_14 ( V_2 , L_8 , V_72 ) ;
F_15 ( V_72 ) ;
return 0 ;
}
static int F_16 ( struct V_66 * V_66 ,
struct V_67 * V_67 )
{
int V_78 ;
struct V_1 * V_68 ;
struct V_79 * V_80 ;
const struct V_81 * V_82 ;
struct V_5 * V_6 ;
F_17 ( V_66 ) ;
if ( ! V_66 -> V_83 ) {
F_18 ( V_66 ) ;
return - V_84 ;
}
V_80 = (struct V_79 * ) V_66 -> V_83 ;
V_82 = V_80 -> V_82 ;
V_6 = V_80 -> V_6 ;
F_19 ( & V_6 -> V_70 ) ;
F_18 ( V_66 ) ;
V_78 = F_20 ( V_67 , V_82 ) ;
if ( ! V_78 ) {
V_68 = V_67 -> V_69 ;
V_68 -> V_7 = V_6 ;
}
return V_78 ;
}
static int F_21 ( struct V_5 * V_6 )
{
int V_85 ;
if ( V_6 -> log . V_10 != NULL ) {
F_22 ( & V_6 -> V_70 ,
L_9 ,
V_75 ) ;
return - V_76 ;
}
V_85 = F_23 ( V_6 ) ;
if ( V_85 != - V_84 )
return V_85 ;
return F_24 ( V_6 ) ;
}
int F_25 ( struct V_5 * V_6 )
{
const char * V_22 = F_26 ( & V_6 -> V_70 ) ;
unsigned int V_86 ;
int V_85 = 0 ;
if ( V_6 -> V_87 & V_88 )
return 0 ;
V_85 = F_21 ( V_6 ) ;
if ( V_85 )
return V_85 ;
V_86 = 0 ;
V_6 -> V_89 [ V_86 ] = F_27 ( V_22 , NULL ) ;
if ( F_28 ( V_6 -> V_89 [ V_86 ] ) )
goto V_78;
V_86 ++ ;
V_6 -> V_90 . V_6 = V_6 ;
V_6 -> V_90 . V_82 = & V_91 ;
V_6 -> V_89 [ V_86 ] =
F_29 ( L_10 ,
0440 , V_6 -> V_89 [ 0 ] ,
( void * ) & V_6 -> V_90 ,
& V_92 ) ;
if ( F_28 ( V_6 -> V_89 [ V_86 ] ) )
goto V_78;
V_86 ++ ;
V_6 -> V_93 . V_6 = V_6 ;
V_6 -> V_93 . V_82 = & V_94 ;
V_6 -> V_89 [ V_86 ] =
F_29 ( L_11 ,
0440 , V_6 -> V_89 [ 0 ] ,
( void * ) & V_6 -> V_93 ,
& V_92 ) ;
if ( F_28 ( V_6 -> V_89 [ V_86 ] ) )
goto V_78;
V_86 ++ ;
return 0 ;
V_78:
V_85 = F_30 ( V_6 -> V_89 [ V_86 ] ) ;
V_6 -> V_89 [ V_86 ] = NULL ;
F_31 ( V_6 ) ;
return V_85 ;
}
void F_31 ( struct V_5 * V_6 )
{
int V_4 ;
struct V_66 * V_66 ;
for ( V_4 = ( V_95 - 1 ) ; V_4 >= 0 ; V_4 -- ) {
if ( V_6 -> V_89 [ V_4 ] ) {
V_66 = F_32 ( V_6 -> V_89 [ V_4 ] ) ;
F_17 ( V_66 ) ;
V_66 -> V_83 = NULL ;
F_18 ( V_66 ) ;
F_33 ( V_6 -> V_89 [ V_4 ] ) ;
}
}
}
