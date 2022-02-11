static int
F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_1 == V_1 )
return 1 ;
return 0 ;
}
static const struct V_5 *
F_2 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_1 == V_1 )
return & V_4 [ V_2 ] ;
return NULL ;
}
static const void *
F_3 ( const void * V_6 , const void * V_7 , void * V_8 , int V_9 )
{
const void * V_10 = ( const void * ) ( ( const char * ) V_6 + V_9 ) ;
if ( F_4 ( V_10 > V_7 || V_10 < V_6 ) )
return F_5 ( - V_11 ) ;
memcpy ( V_8 , V_6 , V_9 ) ;
return V_10 ;
}
static const void *
F_6 ( const void * V_6 , const void * V_7 , struct V_12 * V_8 )
{
const void * V_10 ;
unsigned int V_9 ;
V_6 = F_3 ( V_6 , V_7 , & V_9 , sizeof( V_9 ) ) ;
if ( F_7 ( V_6 ) )
return V_6 ;
V_10 = ( const void * ) ( ( const char * ) V_6 + V_9 ) ;
if ( F_4 ( V_10 > V_7 || V_10 < V_6 ) )
return F_5 ( - V_11 ) ;
V_8 -> V_13 = F_8 ( V_6 , V_9 , V_14 ) ;
if ( F_4 ( V_8 -> V_13 == NULL ) )
return F_5 ( - V_15 ) ;
V_8 -> V_9 = V_9 ;
return V_10 ;
}
static inline const void *
F_9 ( const void * V_6 , const void * V_7 ,
struct V_16 * V_17 , struct V_18 * * V_8 )
{
struct V_12 V_19 ;
int V_20 ;
V_6 = F_3 ( V_6 , V_7 , & V_20 , sizeof( V_20 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
switch ( V_20 ) {
case V_22 :
case V_23 :
case V_24 :
V_20 = V_25 ;
break;
}
if ( ! F_1 ( V_20 ) ) {
F_10 ( V_26 L_1
L_2 , V_20 ) ;
V_6 = F_5 ( - V_27 ) ;
goto V_21;
}
V_6 = F_6 ( V_6 , V_7 , & V_19 ) ;
if ( F_7 ( V_6 ) )
goto V_21;
* V_8 = F_11 ( V_17 -> V_28 -> V_29 , 0 ,
V_30 ) ;
if ( F_7 ( * V_8 ) ) {
F_10 ( V_26 L_3
L_4 , V_17 -> V_28 -> V_29 ) ;
* V_8 = NULL ;
goto V_31;
}
if ( F_12 ( * V_8 , V_19 . V_13 , V_19 . V_9 ) ) {
F_10 ( V_26 L_5
L_4 , V_17 -> V_28 -> V_29 ) ;
goto V_32;
}
F_13 ( V_19 . V_13 ) ;
return V_6 ;
V_32:
F_14 ( * V_8 ) ;
V_31:
F_13 ( V_19 . V_13 ) ;
V_6 = F_5 ( - V_27 ) ;
V_21:
return V_6 ;
}
static int
F_15 ( const void * V_6 , const void * V_7 , struct V_16 * V_17 )
{
int V_33 ;
V_6 = F_3 ( V_6 , V_7 , & V_17 -> V_34 , sizeof( V_17 -> V_34 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
V_17 -> V_35 = V_25 ;
V_17 -> V_28 = F_2 ( V_17 -> V_35 ) ;
if ( V_17 -> V_28 == NULL ) {
V_6 = F_5 ( - V_27 ) ;
goto V_21;
}
if ( F_4 ( V_6 + 20 > V_7 || V_6 + 20 < V_6 ) ) {
V_6 = F_5 ( - V_11 ) ;
goto V_21;
}
V_6 += 20 ;
V_6 = F_3 ( V_6 , V_7 , & V_33 , sizeof( V_33 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
if ( V_33 != V_36 ) {
V_6 = F_5 ( - V_37 ) ;
goto V_21;
}
V_6 = F_3 ( V_6 , V_7 , & V_33 , sizeof( V_33 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
if ( V_33 != V_38 ) {
V_6 = F_5 ( - V_37 ) ;
goto V_21;
}
V_6 = F_3 ( V_6 , V_7 , & V_17 -> V_39 , sizeof( V_17 -> V_39 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
V_6 = F_3 ( V_6 , V_7 , & V_17 -> V_40 , sizeof( V_17 -> V_40 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
V_6 = F_6 ( V_6 , V_7 , & V_17 -> V_41 ) ;
if ( F_7 ( V_6 ) )
goto V_21;
V_6 = F_9 ( V_6 , V_7 , V_17 , & V_17 -> V_42 ) ;
if ( F_7 ( V_6 ) )
goto V_43;
V_6 = F_9 ( V_6 , V_7 , V_17 , & V_17 -> V_44 ) ;
if ( F_7 ( V_6 ) )
goto V_45;
if ( V_6 != V_7 ) {
V_6 = F_5 ( - V_11 ) ;
goto V_46;
}
return 0 ;
V_46:
F_14 ( V_17 -> V_44 ) ;
V_45:
F_14 ( V_17 -> V_42 ) ;
V_43:
F_13 ( V_17 -> V_41 . V_13 ) ;
V_21:
return F_16 ( V_6 ) ;
}
static struct V_18 *
F_17 ( struct V_16 * V_17 , const char * V_47 , T_1 * V_19 )
{
struct V_18 * V_48 ;
V_48 = F_11 ( V_47 , 0 , V_30 ) ;
if ( F_7 ( V_48 ) ) {
F_18 ( L_3
L_4 , V_47 ) ;
return NULL ;
}
if ( F_12 ( V_48 , V_19 , V_17 -> V_28 -> V_49 ) ) {
F_18 ( L_5
L_4 , V_47 ) ;
F_14 ( V_48 ) ;
return NULL ;
}
return V_48 ;
}
static inline void
F_19 ( T_1 V_50 [ V_51 ] , T_2 V_52 , T_1 V_53 )
{
V_50 [ 0 ] = ( V_52 >> 24 ) & 0xff ;
V_50 [ 1 ] = ( V_52 >> 16 ) & 0xff ;
V_50 [ 2 ] = ( V_52 >> 8 ) & 0xff ;
V_50 [ 3 ] = V_52 & 0xff ;
V_50 [ 4 ] = V_53 ;
}
static int
F_20 ( struct V_16 * V_17 , T_3 V_54 )
{
struct V_12 V_55 , V_56 , V_57 ;
T_1 V_50 [ V_51 ] ;
T_2 V_58 ;
V_55 . V_9 = V_51 ;
V_55 . V_13 = V_50 ;
V_56 . V_13 = V_17 -> V_59 ;
V_56 . V_9 = V_17 -> V_28 -> V_49 ;
V_57 . V_9 = V_17 -> V_28 -> V_49 ;
V_17 -> V_44 = F_17 ( V_17 , V_17 -> V_28 -> V_29 ,
V_17 -> V_59 ) ;
if ( V_17 -> V_44 == NULL )
goto V_21;
V_17 -> V_42 = F_17 ( V_17 , V_17 -> V_28 -> V_29 ,
V_17 -> V_59 ) ;
if ( V_17 -> V_42 == NULL )
goto V_60;
F_19 ( V_50 , V_61 , V_62 ) ;
V_57 . V_13 = V_17 -> V_63 ;
V_58 = F_21 ( V_17 -> V_28 , & V_56 , & V_57 , & V_55 , V_54 ) ;
if ( V_58 ) {
F_18 ( L_6 ,
V_64 , V_58 ) ;
goto V_65;
}
return 0 ;
V_65:
F_14 ( V_17 -> V_42 ) ;
V_60:
F_14 ( V_17 -> V_44 ) ;
V_21:
return - V_27 ;
}
static int
F_22 ( struct V_16 * V_17 )
{
struct V_66 * V_67 ;
char V_68 [] = L_7 ;
int V_69 = strlen ( V_68 ) + 1 ;
struct V_70 V_71 ;
struct V_72 V_73 [ 1 ] ;
int V_58 ;
F_18 ( L_8 , V_64 ) ;
V_67 = F_23 ( V_17 -> V_28 -> V_74 , 0 , V_30 ) ;
if ( F_7 ( V_67 ) ) {
F_18 ( L_9 ,
V_64 , F_16 ( V_67 ) , V_17 -> V_28 -> V_74 ) ;
V_58 = F_16 ( V_67 ) ;
goto V_21;
}
V_58 = F_24 ( V_67 , V_17 -> V_59 , V_17 -> V_28 -> V_49 ) ;
if ( V_58 )
goto V_75;
F_25 ( V_73 , 1 ) ;
F_26 ( V_73 , V_68 , V_69 ) ;
V_71 . V_76 = V_67 ;
V_71 . V_77 = 0 ;
V_58 = F_27 ( & V_71 ) ;
if ( V_58 )
goto V_75;
V_58 = F_28 ( & V_71 , V_73 , V_69 , V_17 -> V_63 ) ;
if ( V_58 )
goto V_75;
V_17 -> V_42 = F_11 ( V_17 -> V_28 -> V_29 , 0 ,
V_30 ) ;
if ( F_7 ( V_17 -> V_42 ) ) {
V_58 = F_16 ( V_17 -> V_42 ) ;
goto V_75;
}
V_17 -> V_44 = F_11 ( V_17 -> V_28 -> V_29 , 0 ,
V_30 ) ;
if ( F_7 ( V_17 -> V_44 ) ) {
F_14 ( V_17 -> V_42 ) ;
V_58 = F_16 ( V_17 -> V_44 ) ;
goto V_75;
}
F_18 ( L_10 , V_64 ) ;
V_58 = 0 ;
V_75:
F_29 ( V_67 ) ;
V_21:
F_18 ( L_11 , V_64 , V_58 ) ;
return V_58 ;
}
static int
F_30 ( struct V_16 * V_17 , T_3 V_54 )
{
struct V_12 V_55 , V_56 , V_57 ;
T_1 V_50 [ V_51 ] ;
T_2 V_58 ;
V_55 . V_9 = V_51 ;
V_55 . V_13 = V_50 ;
V_56 . V_13 = V_17 -> V_59 ;
V_56 . V_9 = V_17 -> V_28 -> V_49 ;
V_57 . V_9 = V_17 -> V_28 -> V_49 ;
F_19 ( V_50 , V_78 , V_79 ) ;
V_57 . V_13 = V_17 -> V_80 ;
V_58 = F_21 ( V_17 -> V_28 , & V_56 , & V_57 , & V_55 , V_54 ) ;
if ( V_58 ) {
F_18 ( L_12 ,
V_64 , V_58 ) ;
goto V_21;
}
V_17 -> V_81 = F_17 ( V_17 ,
V_17 -> V_28 -> V_29 ,
V_17 -> V_80 ) ;
if ( V_17 -> V_81 == NULL )
goto V_21;
F_19 ( V_50 , V_82 , V_79 ) ;
V_57 . V_13 = V_17 -> V_83 ;
V_58 = F_21 ( V_17 -> V_28 , & V_56 , & V_57 , & V_55 , V_54 ) ;
if ( V_58 ) {
F_18 ( L_13 ,
V_64 , V_58 ) ;
goto V_84;
}
V_17 -> V_85 = F_17 ( V_17 ,
V_17 -> V_28 -> V_29 ,
V_17 -> V_83 ) ;
if ( V_17 -> V_85 == NULL )
goto V_84;
F_19 ( V_50 , V_86 , V_62 ) ;
V_57 . V_13 = V_17 -> V_87 ;
V_58 = F_21 ( V_17 -> V_28 , & V_56 , & V_57 , & V_55 , V_54 ) ;
if ( V_58 ) {
F_18 ( L_14 ,
V_64 , V_58 ) ;
goto V_88;
}
F_19 ( V_50 , V_89 , V_62 ) ;
V_57 . V_13 = V_17 -> V_90 ;
V_58 = F_21 ( V_17 -> V_28 , & V_56 , & V_57 , & V_55 , V_54 ) ;
if ( V_58 ) {
F_18 ( L_15 ,
V_64 , V_58 ) ;
goto V_88;
}
F_19 ( V_50 , V_78 , V_91 ) ;
V_57 . V_13 = V_17 -> V_92 ;
V_58 = F_21 ( V_17 -> V_28 , & V_56 , & V_57 , & V_55 , V_54 ) ;
if ( V_58 ) {
F_18 ( L_16 ,
V_64 , V_58 ) ;
goto V_88;
}
F_19 ( V_50 , V_82 , V_91 ) ;
V_57 . V_13 = V_17 -> V_93 ;
V_58 = F_21 ( V_17 -> V_28 , & V_56 , & V_57 , & V_55 , V_54 ) ;
if ( V_58 ) {
F_18 ( L_17 ,
V_64 , V_58 ) ;
goto V_88;
}
switch ( V_17 -> V_35 ) {
case V_94 :
case V_95 :
V_17 -> V_96 =
F_17 ( V_17 , L_18 ,
V_17 -> V_80 ) ;
if ( V_17 -> V_96 == NULL )
goto V_88;
V_17 -> V_97 =
F_17 ( V_17 , L_18 ,
V_17 -> V_83 ) ;
if ( V_17 -> V_97 == NULL ) {
F_14 ( V_17 -> V_96 ) ;
goto V_88;
}
}
return 0 ;
V_88:
F_14 ( V_17 -> V_85 ) ;
V_84:
F_14 ( V_17 -> V_81 ) ;
V_21:
return - V_27 ;
}
static int
F_31 ( const void * V_6 , const void * V_7 , struct V_16 * V_17 ,
T_3 V_54 )
{
int V_98 ;
V_6 = F_3 ( V_6 , V_7 , & V_17 -> V_77 , sizeof( V_17 -> V_77 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
V_17 -> V_34 = V_17 -> V_77 & V_99 ;
V_6 = F_3 ( V_6 , V_7 , & V_17 -> V_39 , sizeof( V_17 -> V_39 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
V_6 = F_3 ( V_6 , V_7 , & V_17 -> V_100 , sizeof( V_17 -> V_100 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
V_17 -> V_40 = V_17 -> V_100 ;
if ( V_17 -> V_100 != V_17 -> V_40 ) {
F_18 ( L_19 , V_64 ,
( unsigned long ) V_17 -> V_100 , V_17 -> V_40 ) ;
V_6 = F_5 ( - V_27 ) ;
goto V_21;
}
V_6 = F_3 ( V_6 , V_7 , & V_17 -> V_35 , sizeof( V_17 -> V_35 ) ) ;
if ( F_7 ( V_6 ) )
goto V_21;
if ( V_17 -> V_35 == V_101 )
V_17 -> V_35 = V_102 ;
V_17 -> V_28 = F_2 ( V_17 -> V_35 ) ;
if ( V_17 -> V_28 == NULL ) {
F_18 ( L_20 ,
V_17 -> V_35 ) ;
V_6 = F_5 ( - V_27 ) ;
goto V_21;
}
V_98 = V_17 -> V_28 -> V_49 ;
V_6 = F_3 ( V_6 , V_7 , V_17 -> V_59 , V_98 ) ;
if ( F_7 ( V_6 ) )
goto V_21;
if ( V_6 != V_7 ) {
V_6 = F_5 ( - V_27 ) ;
goto V_21;
}
V_17 -> V_41 . V_13 = F_8 ( V_103 . V_104 . V_13 ,
V_103 . V_104 . V_9 , V_54 ) ;
if ( F_4 ( V_17 -> V_41 . V_13 == NULL ) ) {
V_6 = F_5 ( - V_15 ) ;
goto V_21;
}
V_17 -> V_41 . V_9 = V_103 . V_104 . V_9 ;
switch ( V_17 -> V_35 ) {
case V_102 :
return F_20 ( V_17 , V_54 ) ;
case V_105 :
return F_22 ( V_17 ) ;
case V_94 :
case V_95 :
return F_30 ( V_17 , V_54 ) ;
default:
return - V_27 ;
}
V_21:
return F_16 ( V_6 ) ;
}
static int
F_32 ( const void * V_6 , T_4 V_9 ,
struct V_106 * V_107 ,
T_3 V_54 )
{
const void * V_7 = ( const void * ) ( ( const char * ) V_6 + V_9 ) ;
struct V_16 * V_17 ;
int V_108 ;
V_17 = F_33 ( sizeof( * V_17 ) , V_54 ) ;
if ( V_17 == NULL )
return - V_15 ;
if ( V_9 == 85 )
V_108 = F_15 ( V_6 , V_7 , V_17 ) ;
else
V_108 = F_31 ( V_6 , V_7 , V_17 , V_54 ) ;
if ( V_108 == 0 )
V_107 -> V_109 = V_17 ;
else
F_13 ( V_17 ) ;
F_18 ( L_11 , V_64 , V_108 ) ;
return V_108 ;
}
static void
F_34 ( void * V_110 ) {
struct V_16 * V_111 = V_110 ;
F_14 ( V_111 -> V_44 ) ;
F_14 ( V_111 -> V_42 ) ;
F_14 ( V_111 -> V_85 ) ;
F_14 ( V_111 -> V_81 ) ;
F_14 ( V_111 -> V_97 ) ;
F_14 ( V_111 -> V_96 ) ;
F_13 ( V_111 -> V_41 . V_13 ) ;
F_13 ( V_111 ) ;
}
static int T_5 F_35 ( void )
{
int V_112 ;
V_112 = F_36 ( & V_103 ) ;
if ( V_112 )
F_10 ( L_21 ) ;
return V_112 ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_103 ) ;
}
