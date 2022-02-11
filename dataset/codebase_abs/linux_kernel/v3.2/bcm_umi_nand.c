static void F_1 ( T_1 V_1 , int V_2 , void * V_3 )
{
F_2 ( & V_4 ) ;
}
static int F_3 ( void )
{
int V_5 ;
V_5 = F_4 ( V_6 ,
F_1 , NULL ) ;
if ( V_5 != 0 ) {
F_5 ( V_7 L_1 , V_5 ) ;
return V_5 ;
}
V_8 =
F_6 ( NULL , V_9 , & V_10 , V_11 ) ;
if ( V_8 == NULL ) {
F_5 ( V_7 L_2 ) ;
return - V_12 ;
}
return 0 ;
}
static void F_7 ( void )
{
if ( V_8 != NULL )
F_8 ( NULL , V_9 , V_8 , V_10 ) ;
}
static void F_9 ( void * V_13 , int V_14 )
{
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = V_14 ;
T_2 V_18 ;
if ( V_8 == NULL )
F_10 ( L_3 ) ;
if ( ( void * ) V_10 == NULL )
F_10 ( L_4 ) ;
V_18 = F_11 ( V_6 ) ;
if ( V_18 < 0 ) {
F_5 ( V_7
L_5 ,
( int ) V_18 ) ;
F_10 ( L_6 ) ;
}
while ( V_17 > 0 ) {
if ( V_17 > V_19 ) {
V_16 = V_19 ;
V_17 -= V_19 ;
} else {
V_16 = V_17 ;
V_17 = 0 ;
}
F_12 ( & V_4 ) ;
F_13 ( V_18 , V_20 ,
V_10 + V_15 , V_16 ) ;
F_14 ( & V_4 ) ;
V_15 += V_16 ;
}
F_15 ( V_18 ) ;
if ( V_13 != NULL )
memcpy ( V_13 , V_8 , V_14 ) ;
}
static void F_16 ( const void * V_13 , int V_14 )
{
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = V_14 ;
T_2 V_18 ;
if ( V_13 == NULL )
F_10 ( L_7 ) ;
if ( V_8 == NULL )
F_10 ( L_8 ) ;
if ( ( void * ) V_10 == NULL )
F_10 ( L_9 ) ;
memcpy ( V_8 , V_13 , V_14 ) ;
V_18 = F_11 ( V_6 ) ;
if ( V_18 < 0 ) {
F_5 ( V_7
L_10 ,
( int ) V_18 ) ;
F_10 ( L_6 ) ;
}
while ( V_17 > 0 ) {
if ( V_17 > V_19 ) {
V_16 = V_19 ;
V_17 -= V_19 ;
} else {
V_16 = V_17 ;
V_17 = 0 ;
}
F_12 ( & V_4 ) ;
F_13 ( V_18 , V_10 + V_15 ,
V_20 , V_16 ) ;
F_14 ( & V_4 ) ;
V_15 += V_16 ;
}
F_15 ( V_18 ) ;
}
static int F_17 ( struct V_21 * V_22 )
{
return F_18 () ;
}
int F_19 ( void )
{
V_23 &= ~ 0x7ffff ;
V_23 |= V_24 ;
#if ! F_20 ( V_25 )
V_23 |= V_26 ;
#endif
V_27 |= V_28 ;
V_23 &= ~ V_29 ;
V_30 |= V_31 ;
F_21 ( V_32 , V_33 + V_34 ) ;
F_22 () ;
#if V_35
F_23 ( V_36 ) ;
#endif
return 0 ;
}
static void F_24 ( struct V_21 * V_22 , int V_37 ,
unsigned int V_38 )
{
struct V_39 * V_40 = V_22 -> V_41 ;
if ( V_38 & V_42 ) {
if ( V_38 & V_43 ) {
V_40 -> V_44 = V_33 + V_34 ;
goto V_45;
}
if ( V_38 & V_46 ) {
V_40 -> V_44 =
V_33 + V_47 ;
goto V_45;
}
V_40 -> V_44 = V_33 + V_48 ;
}
V_45:
if ( V_37 != V_49 )
F_25 ( V_37 , V_40 -> V_44 ) ;
}
static void F_26 ( struct V_21 * V_22 , const T_3 * V_13 ,
int V_14 )
{
if ( F_27 ( V_14 ) ) {
int V_50 ;
struct V_39 * V_51 = V_22 -> V_41 ;
for ( V_50 = 0 ; V_50 < V_14 ; V_50 ++ )
F_25 ( V_13 [ V_50 ] , V_51 -> V_44 ) ;
}
#if V_52
else
F_16 ( V_13 , V_14 ) ;
#endif
}
static void F_28 ( struct V_21 * V_22 , T_3 * V_13 , int V_14 )
{
if ( F_27 ( V_14 ) ) {
int V_50 ;
struct V_39 * V_51 = V_22 -> V_41 ;
for ( V_50 = 0 ; V_50 < V_14 ; V_50 ++ )
V_13 [ V_50 ] = F_29 ( V_51 -> V_53 ) ;
}
#if V_52
else
F_9 ( V_13 , V_14 ) ;
#endif
}
static int F_30 ( struct V_21 * V_22 , const T_3 * V_13 ,
int V_14 )
{
struct V_39 * V_40 = V_22 -> V_41 ;
int V_54 = V_40 -> V_55 . V_56 ( V_22 , V_40 , V_57 , 0 ) ;
if ( V_54 < 0 )
return - V_58 ;
else {
if ( memcmp ( V_57 , V_13 , V_14 ) == 0 )
return 0 ;
return - V_58 ;
}
return 0 ;
}
static int T_4 F_31 ( struct V_59 * V_60 )
{
struct V_39 * V_51 ;
struct V_61 * V_62 ;
int V_63 = 0 ;
F_5 ( V_64 ) ;
V_65 =
F_32 ( sizeof( struct V_21 ) + sizeof( struct V_39 ) ,
V_11 ) ;
if ( ! V_65 ) {
F_5 ( V_66
L_11 ) ;
return - V_12 ;
}
V_62 = F_33 ( V_60 , V_67 , 0 ) ;
if ( ! V_62 ) {
V_63 = - V_68 ;
goto V_69;
}
V_33 = F_34 ( V_62 -> V_70 , F_35 ( V_62 ) ) ;
if ( ! V_33 ) {
F_5 ( V_7 L_12 ) ;
V_63 = - V_71 ;
goto V_69;
}
V_51 = (struct V_39 * ) ( & V_65 [ 1 ] ) ;
memset ( ( char * ) V_65 , 0 , sizeof( struct V_21 ) ) ;
memset ( ( char * ) V_51 , 0 , sizeof( struct V_39 ) ) ;
V_65 -> V_41 = V_51 ;
if ( F_19 () < 0 ) {
F_5 ( V_7 L_13 ) ;
V_63 = - V_71 ;
goto V_72;
}
V_51 -> V_44 = V_33 + V_48 ;
V_51 -> V_53 = V_33 + V_48 ;
V_51 -> V_73 = 0 ;
V_51 -> V_74 = F_17 ;
V_51 -> V_75 = 0 ;
V_51 -> V_76 = F_26 ;
V_51 -> V_77 = F_28 ;
V_51 -> V_78 = F_30 ;
V_51 -> V_79 = F_24 ;
V_51 -> V_55 . V_80 = V_81 ;
V_51 -> V_55 . V_82 = 512 ;
V_51 -> V_55 . V_83 = V_36 ;
#if V_35
V_51 -> V_55 . V_56 = V_84 ;
V_51 -> V_55 . V_85 = V_86 ;
#else
V_51 -> V_55 . V_87 = V_88 ;
V_51 -> V_55 . V_89 = V_90 ;
V_51 -> V_55 . V_91 = V_92 ;
#endif
#if V_52
V_63 = F_3 () ;
if ( V_63 != 0 )
goto V_72;
#endif
V_63 = F_36 ( V_65 , 1 , NULL ) ;
if ( V_63 ) {
F_5 ( V_7 L_14 , V_63 ) ;
goto V_72;
}
switch ( V_65 -> V_93 ) {
case 4096 :
V_51 -> V_55 . V_94 = & V_95 ;
break;
case 2048 :
V_51 -> V_55 . V_94 = & V_96 ;
break;
case 512 :
V_51 -> V_55 . V_94 = & V_97 ;
break;
default:
{
F_5 ( V_7 L_15 ,
V_65 -> V_93 ) ;
V_63 = - V_98 ;
goto V_72;
}
}
#if V_35
if ( V_65 -> V_93 > 512 ) {
if ( V_51 -> V_99 & V_100 )
V_101 . V_75 = V_102 ;
V_51 -> V_103 = & V_101 ;
}
#endif
V_63 = F_37 ( V_65 ) ;
if ( V_63 ) {
F_5 ( V_7 L_14 , V_63 ) ;
goto V_72;
}
V_65 -> V_104 = L_16 ;
F_38 ( V_65 , NULL , 0 , NULL , 0 ) ;
return 0 ;
V_72:
F_39 ( V_33 ) ;
V_69:
F_40 ( V_65 ) ;
return V_63 ;
}
static int F_41 ( struct V_59 * V_60 )
{
#if V_52
F_7 () ;
#endif
F_42 ( V_65 ) ;
F_39 ( V_33 ) ;
F_40 ( V_65 ) ;
return 0 ;
}
static int F_43 ( struct V_59 * V_60 ,
T_5 V_105 )
{
F_5 ( V_7 L_17 ) ;
return 0 ;
}
static int F_44 ( struct V_59 * V_60 )
{
F_5 ( V_7 L_18 ) ;
return 0 ;
}
static int T_6 F_45 ( void )
{
return F_46 ( & V_106 ) ;
}
static void T_7 F_47 ( void )
{
F_48 ( & V_106 ) ;
}
