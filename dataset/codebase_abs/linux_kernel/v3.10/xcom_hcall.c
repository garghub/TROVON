int
F_1 ( int V_1 , int V_2 , char * V_3 )
{
if ( ! F_2 () )
return 0 ;
return F_3
( V_1 , V_2 , F_4 ( V_3 , V_2 ) ) ;
}
int
F_5 ( int V_1 , void * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_4 , sizeof( struct V_7 ) ) ;
if ( V_6 == NULL )
return - V_8 ;
return F_6 ( V_1 , V_6 ) ;
}
int
F_7 ( int V_1 , void * V_9 )
{
struct V_5 * V_6 ;
unsigned int V_10 ;
switch ( V_1 ) {
case V_11 :
return F_8 ( V_1 , 0 ) ;
case V_12 :
V_10 = sizeof( struct V_13 ) ;
break;
case V_14 :
V_10 = sizeof( struct V_15 ) ;
break;
case V_16 :
V_10 = sizeof( struct V_17 ) ;
break;
case V_18 :
V_10 = sizeof( struct V_19 ) ;
break;
case V_20 :
V_10 = sizeof( struct V_21 ) ;
break;
case V_22 :
V_10 = ( V_9 == NULL ) ? 0 : sizeof( struct V_23 ) ;
break;
default:
F_9 ( V_24
L_1 , V_25 , V_1 ) ;
return - V_26 ;
}
V_6 = F_4 ( V_9 , V_10 ) ;
if ( V_6 == NULL )
return - V_8 ;
return F_8 ( V_1 , V_6 ) ;
}
int
F_10 ( int V_1 , void * V_4 )
{
unsigned int V_10 ;
switch ( V_1 ) {
case V_27 :
case V_28 :
V_10 = sizeof( struct V_29 ) ;
break;
case V_30 :
case V_31 :
V_10 = sizeof( struct V_32 ) ;
break;
case V_33 :
V_10 = sizeof( struct V_34 ) ;
break;
default:
F_9 ( V_24
L_2 , V_25 , V_1 ) ;
return - V_26 ;
}
return F_11
( V_1 , F_4 ( V_4 , V_10 ) ) ;
}
static int
F_12 ( struct V_35 * * V_36 ,
unsigned int V_1 , void * V_4 , unsigned int V_2 ,
struct V_5 * * V_6 )
{
struct V_5 * V_37 ;
unsigned int V_10 ;
switch ( V_1 ) {
case V_38 :
V_10 = sizeof( struct V_39 ) ;
break;
case V_40 :
V_10 = sizeof( struct V_41 ) ;
break;
case V_42 :
{
struct V_43 * V_44 = V_4 ;
V_10 = sizeof( * V_44 ) ;
if ( V_2 != 1 )
return - V_8 ;
V_37 = F_13
( F_14 ( V_44 -> V_45 ) ,
V_44 -> V_46 *
sizeof( * F_14 ( V_44 -> V_45 ) ) ,
* V_36 ) ;
if ( V_37 == NULL )
return - V_8 ;
( * V_36 ) ++ ;
F_15 ( V_44 -> V_45 , ( void * ) V_37 ) ;
break;
}
case V_47 :
V_10 = sizeof( struct V_48 ) ;
break;
case V_49 :
V_10 = sizeof( struct V_50 ) ;
break;
case V_51 :
V_10 = sizeof( struct V_52 ) ;
break;
case V_53 :
V_10 = sizeof( struct V_54 ) ;
break;
default:
F_9 ( V_24 L_3 ,
V_25 , V_1 ) ;
F_16 () ;
}
* V_6 = F_13 ( V_4 , V_2 * V_10 , * V_36 ) ;
if ( * V_6 == NULL )
return - V_8 ;
( * V_36 ) ++ ;
return 0 ;
}
int
F_17 ( unsigned int V_1 , void * V_4 ,
unsigned int V_2 )
{
int V_55 ;
struct V_5 * V_6 ;
F_18 ( V_36 , 2 ) ;
V_55 = F_12 ( & V_36 , V_1 , V_4 , V_2 , & V_6 ) ;
if ( V_55 )
return V_55 ;
return F_19 ( V_1 , V_6 , V_2 ) ;
}
int
F_20 ( int V_1 , void * V_9 )
{
struct V_5 * V_6 ;
unsigned int V_10 ;
switch ( V_1 ) {
case V_56 :
case V_57 :
V_10 = 0 ;
break;
case V_58 :
V_10 = sizeof( struct V_59 ) ;
break;
case V_60 :
{
struct V_61 * V_62 = V_9 ;
struct V_5 * V_63 ;
V_10 = sizeof( struct V_61 ) ;
V_63 = F_4 ( F_14 ( V_62 -> V_63 ) ,
sizeof( * F_14 ( V_62 -> V_63 ) ) ) ;
F_15 ( V_62 -> V_63 , ( void * ) V_63 ) ;
break;
}
default:
F_9 ( V_24 L_4 , V_25 , V_1 ) ;
return - V_26 ;
}
V_6 = F_4 ( V_9 , V_10 ) ;
if ( V_6 == NULL )
return - V_8 ;
return F_21 ( V_1 , V_6 ) ;
}
int
F_22 ( void * V_64 , int V_65 )
{
int V_55 ;
int V_66 ;
struct V_67 * V_68 ;
struct V_5 * V_6 ;
F_18 ( V_36 , V_65 * 2 ) ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
V_68 = (struct V_67 * ) V_64 + V_66 ;
switch ( V_68 -> V_4 ) {
case V_69 :
case V_70 :
break;
case V_71 :
V_55 = F_12
( & V_36 ,
V_68 -> args [ 0 ] , ( void * ) V_68 -> args [ 1 ] ,
V_68 -> args [ 2 ] , & V_6 ) ;
if ( V_55 )
return V_55 ;
V_68 -> args [ 1 ] = ( unsigned long ) V_6 ;
break;
case V_72 :
default:
F_9 ( V_24
L_5 ,
V_25 , V_68 -> V_4 ) ;
return - V_26 ;
}
}
V_6 = F_4 ( V_64 ,
V_65 * sizeof( struct V_67 ) ) ;
if ( V_6 == NULL )
return - V_8 ;
return F_23 ( V_6 , V_65 ) ;
}
int
F_24 ( int V_1 , void * V_9 )
{
unsigned int V_10 ;
switch ( V_1 ) {
case V_73 :
V_10 = sizeof( struct V_74 ) ;
break;
case V_75 :
V_10 = sizeof( struct V_76 ) ;
break;
default:
F_9 ( V_24
L_6 , V_25 , V_1 ) ;
return - V_26 ;
}
return F_25
( V_1 , F_4 ( V_9 , V_10 ) ) ;
}
static int
F_26 ( struct V_35 * V_36 ,
struct V_77 * V_78 )
{
struct V_5 * V_6 ;
V_6 = F_13 ( F_14 ( V_78 -> V_79 ) ,
V_78 -> V_80 *
sizeof( * F_14 ( V_78 -> V_79 ) ) ,
V_36 ) ;
if ( V_6 == NULL )
return - V_8 ;
F_15 ( V_78 -> V_79 , ( void * ) V_6 ) ;
return 0 ;
}
int
F_27 ( unsigned int V_1 , void * V_9 )
{
F_28 (xen_pfn_t) V_81 [ 2 ] = { { NULL } , { NULL } } ;
struct V_77 * V_82 = NULL ;
int V_55 ;
struct V_5 * V_6 ;
unsigned int V_10 ;
F_18 ( V_36 , 2 ) ;
switch ( V_1 ) {
case V_83 :
case V_84 :
case V_85 :
V_82 = (struct V_77 * ) V_9 ;
F_15 ( V_81 [ 0 ] ,
F_14 ( V_82 -> V_79 ) ) ;
V_10 = sizeof( * V_82 ) ;
V_55 = F_26 ( V_36 , V_82 ) ;
if ( V_55 )
return V_55 ;
V_36 ++ ;
break;
case V_86 :
V_10 = 0 ;
break;
case V_87 :
V_10 = sizeof( struct V_88 ) ;
break;
default:
F_9 ( V_24 L_7 , V_25 , V_1 ) ;
return - V_26 ;
}
V_6 = F_4 ( V_9 , V_10 ) ;
if ( V_6 == NULL )
return - V_8 ;
V_55 = F_29 ( V_1 , V_6 ) ;
switch ( V_1 ) {
case V_83 :
case V_84 :
case V_85 :
F_15 ( V_82 -> V_79 ,
F_14 ( V_81 [ 0 ] ) ) ;
break;
}
return V_55 ;
}
int
F_30 ( unsigned long V_89 )
{
struct V_59 V_9 ;
V_9 . V_90 = V_91 ;
return F_21 (
V_58 , F_4 ( & V_9 , sizeof( V_9 ) ) ) ;
}
long
F_31 ( int V_1 , int V_92 , void * V_9 )
{
unsigned int V_10 ;
switch ( V_1 ) {
case V_93 : {
struct V_94 * V_95 =
(struct V_94 * ) V_9 ;
V_10 = sizeof( * V_9 ) ;
F_15 ( V_95 -> V_96 . V_97 ,
( void * ) F_4 ( V_95 -> V_96 . V_98 ,
sizeof( V_95 -> V_96 . V_98 ) ) ) ;
break;
}
default:
F_9 ( V_24 L_8 , V_25 , V_1 ) ;
return - V_26 ;
}
return F_32 ( V_1 , V_92 ,
F_4 ( V_9 , V_10 ) ) ;
}
long
F_33 ( void * V_9 )
{
return F_34 (
F_4 ( V_9 ,
sizeof( struct V_99 ) ) ) ;
}
