static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_3 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_5 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_7 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_10 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_13 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_15 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_17 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_19 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_21 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_23 ( L_1 , V_16 , * V_12 ) ;
V_9 -> V_17 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_18 = ( int * ) V_12 ;
int V_19 = ( V_18 [ 0 ] > 0 ) ;
short V_20 = V_9 -> V_21 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if( V_19 )
V_9 -> V_21 = 1 ;
else
V_9 -> V_21 = 0 ;
F_25 ( L_2 ,
V_9 -> V_21 ? L_3 : L_4 ) ;
if( V_20 != V_9 -> V_21 && V_9 -> F_11 ) {
}
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_22 ;
int V_13 ;
if ( V_9 -> V_14 )
return 0 ;
V_22 = V_9 -> V_23 ;
F_9 ( & V_9 -> V_15 ) ;
#ifdef F_27
if( V_6 -> V_24 == V_25 ) {
if ( V_9 -> V_26 . V_27 ) {
if( V_22 == V_28 ) {
if( V_9 -> V_29 > V_30 )
{
F_28 ( V_31 , L_5 , V_16 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
}
else{
F_28 ( V_31 , L_6 , V_16 ) ;
F_9 ( & V_9 -> V_10 -> V_32 ) ;
F_29 ( V_9 ) ;
F_11 ( & V_9 -> V_10 -> V_32 ) ;
}
}
}
}
#endif
V_13 = F_30 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_9 -> V_10 ;
T_1 V_22 ;
int V_13 ;
if ( V_9 -> V_14 )
return 0 ;
V_22 = V_9 -> V_23 ;
if( ! V_9 -> F_11 ) return - V_35 ;
if ( V_9 -> V_10 -> V_36 . V_37 == true )
return - V_38 ;
if ( V_6 -> V_39 . V_40 & V_41 )
{
struct V_42 * V_43 = (struct V_42 * ) V_7 ;
if ( V_43 -> V_44 )
{
V_34 -> V_45 . V_46 = V_43 -> V_44 ;
memcpy ( V_34 -> V_45 . V_47 , V_43 -> V_48 , V_43 -> V_44 ) ;
}
}
F_9 ( & V_9 -> V_15 ) ;
#ifdef F_27
V_9 -> V_10 -> V_49 = true ;
if( V_9 -> V_10 -> V_50 != V_51 ) {
if ( V_9 -> V_26 . V_27 ) {
if( V_22 == V_28 ) {
if( V_9 -> V_29 > V_30 )
{
F_28 ( V_31 , L_5 , V_16 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
}
else{
F_9 ( & V_9 -> V_10 -> V_32 ) ;
F_29 ( V_9 ) ;
F_11 ( & V_9 -> V_10 -> V_32 ) ;
}
}
}
V_9 -> V_10 -> V_52 = 0 ;
F_32 ( V_9 -> V_10 ) ;
V_13 = 0 ;
}
else
#else
if( V_9 -> V_10 -> V_50 != V_51 ) {
V_9 -> V_10 -> V_52 = 0 ;
F_32 ( V_9 -> V_10 ) ;
V_13 = 0 ;
}
else
#endif
V_13 = F_33 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
if( ! V_9 -> F_11 ) return - V_35 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_35 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_22 ;
int V_13 ;
if ( V_9 -> V_14 )
return 0 ;
V_22 = V_9 -> V_23 ;
F_9 ( & V_9 -> V_15 ) ;
#ifdef F_27
F_9 ( & V_9 -> V_10 -> V_32 ) ;
F_29 ( V_9 ) ;
F_11 ( & V_9 -> V_10 -> V_32 ) ;
#endif
V_13 = F_37 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_39 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_41 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_43 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
if ( V_6 -> V_53 . V_54 )
V_9 -> V_10 -> V_55 = V_56 ;
else {
if ( V_6 -> V_53 . V_57 < V_58 ||
V_6 -> V_53 . V_57 > V_59 )
return - V_60 ;
V_9 -> V_10 -> V_55 = V_6 -> V_53 . V_57 & ~ 0x1 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_53 . V_57 = V_9 -> V_10 -> V_55 ;
V_6 -> V_53 . V_61 = 0 ;
V_6 -> V_53 . V_54 = ( V_6 -> V_53 . V_57 == V_56 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_62 ,
char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
#ifdef F_27
F_9 ( & V_9 -> V_10 -> V_32 ) ;
F_29 ( V_9 ) ;
F_11 ( & V_9 -> V_10 -> V_32 ) ;
#endif
V_13 = F_47 ( V_9 -> V_10 , V_11 , V_62 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_49 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_63 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_51 ( V_9 -> V_10 , V_11 , V_6 , V_63 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_63 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
struct V_33 * V_34 = V_9 -> V_10 ;
T_2 V_64 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_3 V_65 = 0xff ;
T_2 V_66 = 0 ;
T_3 V_67 [ 4 ] [ 6 ] = { { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
int V_68 ;
if ( V_9 -> V_14 )
return 0 ;
if( ! V_9 -> F_11 ) return - V_35 ;
V_9 -> V_10 -> V_69 = 1 ;
#ifdef F_27
F_9 ( & V_9 -> V_10 -> V_32 ) ;
F_29 ( V_9 ) ;
F_11 ( & V_9 -> V_10 -> V_32 ) ;
#endif
F_9 ( & V_9 -> V_15 ) ;
F_28 ( V_70 , L_7 ) ;
V_13 = F_53 ( V_9 -> V_10 , V_11 , V_6 , V_63 ) ;
F_11 ( & V_9 -> V_15 ) ;
if( V_6 -> V_71 . V_72 != 0 ) {
for( V_68 = 0 ; V_68 < 4 ; V_68 ++ ) {
V_64 [ V_68 ] |= V_63 [ 4 * V_68 + 0 ] & V_65 ;
if( V_68 == 1 && ( 4 * V_68 + 1 ) == V_6 -> V_71 . V_72 ) V_65 = 0x00 ;
if( V_68 == 3 && ( 4 * V_68 + 1 ) == V_6 -> V_71 . V_72 ) V_65 = 0x00 ;
V_64 [ V_68 ] |= ( V_63 [ 4 * V_68 + 1 ] & V_65 ) << 8 ;
V_64 [ V_68 ] |= ( V_63 [ 4 * V_68 + 2 ] & V_65 ) << 16 ;
V_64 [ V_68 ] |= ( V_63 [ 4 * V_68 + 3 ] & V_65 ) << 24 ;
}
#define F_54 0x4
#define F_55 0x14
switch( V_6 -> V_71 . V_40 & V_73 ) {
case 0 : V_66 = V_34 -> V_74 ; break;
case 1 : V_66 = 0 ; break;
case 2 : V_66 = 1 ; break;
case 3 : V_66 = 2 ; break;
case 4 : V_66 = 3 ; break;
default: break;
}
if( V_6 -> V_71 . V_72 == 0x5 ) {
V_34 -> V_75 = V_76 ;
F_56 ( V_9 ) ;
F_57 ( V_9 , V_66 , V_66 , V_76 ,
V_67 [ V_66 ] , 0 , V_64 ) ;
}
else if( V_6 -> V_71 . V_72 == 0xd ) {
V_34 -> V_75 = V_77 ;
F_56 ( V_9 ) ;
F_57 ( V_9 , V_66 , V_66 , V_77 ,
V_67 [ V_66 ] , 0 , V_64 ) ;
}
else F_23 ( L_8 ) ;
}
V_9 -> V_10 -> V_69 = 0 ;
return V_13 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_3 * V_78 , union
V_5 * V_6 , char * V_79 ) {
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_18 = ( int * ) V_79 ;
int V_24 = V_18 [ 0 ] ;
V_9 -> V_10 -> V_80 = V_24 ;
return 1 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_81 = 0 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_82 . V_40 & V_83 ||
V_6 -> V_82 . V_54 ) {
V_81 = - V_60 ;
goto exit;
}
if ( ! ( V_6 -> V_82 . V_40 & V_84 ) ) {
V_81 = - V_60 ;
goto exit;
}
if( V_6 -> V_82 . V_57 > V_85 ) {
V_81 = - V_60 ;
goto exit;
}
if ( V_6 -> V_82 . V_40 & V_86 ) {
V_9 -> V_87 = V_6 -> V_82 . V_57 ;
F_25 ( L_9 , V_6 -> V_82 . V_57 ) ;
} else {
V_9 -> V_88 = V_6 -> V_82 . V_57 ;
F_25 ( L_10 , V_6 -> V_82 . V_57 ) ;
}
F_60 ( V_9 ) ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_81 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_82 . V_54 = 0 ;
if ( ( V_6 -> V_82 . V_40 & V_89 ) ==
V_83 )
return - V_60 ;
if ( V_6 -> V_82 . V_40 & V_86 ) {
V_6 -> V_82 . V_40 = V_84 & V_86 ;
V_6 -> V_82 . V_57 = V_9 -> V_87 ;
} else {
V_6 -> V_82 . V_40 = V_84 & V_90 ;
V_6 -> V_82 . V_57 = V_9 -> V_88 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if( V_9 -> V_91 == NULL )
return - 1 ;
V_6 -> V_92 . V_57 = V_9 -> V_92 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
short V_81 = 0 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if( V_9 -> V_91 == NULL ) {
V_81 = - 1 ;
goto exit;
}
if( V_9 -> V_91 ( V_2 , V_6 -> V_92 . V_57 ) == 0 )
V_9 -> V_92 = V_6 -> V_92 . V_57 ;
else
V_81 = - V_60 ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_81 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_9 -> V_10 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_9 -> V_10 -> V_69 = 1 ;
#ifdef F_27
F_9 ( & V_9 -> V_10 -> V_32 ) ;
F_29 ( V_9 ) ;
F_11 ( & V_9 -> V_10 -> V_32 ) ;
#endif
V_13 = F_65 ( V_34 , V_11 , V_6 , V_12 ) ;
{
T_3 V_93 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_3 V_94 [ 6 ] = { 0 } ;
T_2 V_63 [ 4 ] = { 0 } ;
struct V_95 * V_96 = (struct V_95 * ) V_12 ;
struct V_97 * V_71 = & V_6 -> V_71 ;
T_3 V_98 = 0 , V_99 = 0 , V_100 = 0 ;
if ( ( V_71 -> V_40 & V_101 ) ||
V_96 -> V_99 == V_102 )
{
V_34 -> V_75 = V_34 -> V_103 = V_104 ;
F_66 ( V_9 ) ;
goto V_105;
}
V_99 = ( V_96 -> V_99 == V_106 ) ? V_107 : V_96 -> V_99 ;
V_98 = V_71 -> V_40 & V_73 ;
if ( V_98 )
V_98 -- ;
V_100 = V_96 -> V_108 & V_109 ;
if ( ( ! V_100 ) || ( V_25 == V_34 -> V_110 ) || ( V_99 == V_76 ) )
{
if ( ( V_96 -> V_111 == 13 ) && ( V_99 == V_76 ) )
V_99 = V_77 ;
V_34 -> V_75 = V_99 ;
F_56 ( V_9 ) ;
}
memcpy ( ( T_3 * ) V_63 , V_96 -> V_63 , 16 ) ;
if ( ( V_99 & V_76 ) && ( V_34 -> V_112 != 2 ) )
{
if ( V_96 -> V_111 == 13 )
V_34 -> V_75 = V_99 = V_77 ;
F_57 ( V_9 , V_98 , V_98 , V_99 , V_94 , 0 , V_63 ) ;
}
else if ( V_100 )
{
V_34 -> V_103 = V_99 ;
F_57 ( V_9 , V_98 , V_98 , V_99 , V_93 , 0 , V_63 ) ;
}
else
{
if ( ( V_34 -> V_75 == V_107 ) && V_34 -> V_113 -> V_114 ) {
F_67 ( V_9 , 0x173 , 1 ) ;
}
F_57 ( V_9 , 4 , V_98 , V_99 ,
( T_3 * ) V_34 -> V_115 , 0 , V_63 ) ;
}
}
V_105:
V_9 -> V_10 -> V_69 = 0 ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_39 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_69 ( V_9 -> V_10 , V_11 , & ( V_39 -> V_116 ) , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_71 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_39 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_73 ( V_9 -> V_10 , V_12 , V_39 -> V_39 . V_72 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
return - 1 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
#ifdef F_76
T_4 V_117 = & V_9 -> V_26 ;
struct V_33 * V_34 = V_9 -> V_10 ;
#endif
F_9 ( & V_9 -> V_15 ) ;
#ifdef F_76
F_28 ( V_118 , L_11 , V_16 , ( * V_12 == 6 ) ? L_12 : L_13 ) ;
if( * V_12 || V_9 -> V_119 ) {
V_9 -> V_120 = false ;
V_117 -> V_121 = true ;
} else {
if( V_9 -> V_10 -> V_50 == V_51 )
F_77 ( V_9 -> V_10 ) ;
V_9 -> V_120 = true ;
V_117 -> V_121 = false ;
V_34 -> V_122 = * V_12 ;
}
#endif
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static struct V_123 * F_78 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_9 -> V_10 ;
struct V_123 * V_124 = & V_9 -> V_124 ;
int V_125 = 0 ;
int V_126 = 0 ;
int V_127 = 0 ;
if( V_34 -> V_50 < V_51 )
{
V_124 -> V_128 . V_128 = 0 ;
V_124 -> V_128 . V_129 = 0 ;
V_124 -> V_128 . V_130 = 0 ;
V_124 -> V_128 . V_131 = V_132 | V_133 ;
return V_124 ;
}
V_125 = ( & V_34 -> V_45 ) -> V_134 . V_135 ;
V_126 = ( & V_34 -> V_45 ) -> V_134 . signal ;
V_127 = ( & V_34 -> V_45 ) -> V_134 . V_130 ;
V_124 -> V_128 . V_129 = V_125 ;
V_124 -> V_128 . V_128 = V_126 ;
V_124 -> V_128 . V_130 = V_127 ;
V_124 -> V_128 . V_131 = V_132 | V_133 ;
return V_124 ;
}
