static inline void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 + V_3 ) ;
}
static inline void F_3 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 + V_4 ) ;
}
static inline void F_4 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 + V_5 ) ;
}
static const T_1 * F_5 ( void )
{
struct V_6 * V_7 ;
void T_2 * V_8 ;
int V_9 = 0x400 ;
T_3 V_10 ;
static int V_11 ;
if ( V_11 )
return V_12 ;
V_7 = F_6 ( NULL , NULL , L_1 ) ;
V_8 = F_7 ( V_7 , 0 ) ;
F_8 ( ! V_8 ) ;
F_9 ( & V_13 ) ;
F_3 ( V_14 , V_8 ) ;
while ( ( F_10 ( V_8 ) &
( V_15 | V_14 ) ) && -- V_9 )
F_11 () ;
if ( F_12 ( ! V_9 ) )
goto V_16;
F_1 ( V_17 , V_8 ) ;
F_13 ( 1 ) ;
V_9 = 0x400 ;
while ( ( F_10 ( V_8 ) & V_15 ) && -- V_9 )
F_11 () ;
if ( F_12 ( ! V_9 ) )
goto V_16;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ )
V_12 [ V_10 ] = F_10 ( V_8 + V_19 +
V_10 * 0x10 ) ;
F_3 ( V_17 , V_8 ) ;
V_11 = 1 ;
F_14 ( & V_13 ) ;
return V_12 ;
V_16:
F_14 ( & V_13 ) ;
F_15 ( L_2 , V_20 ) ;
return NULL ;
}
static void T_4 F_16 ( enum V_21 V_22 )
{
struct V_6 * V_7 , * V_23 = NULL ;
struct V_24 * V_25 ;
const T_1 * V_26 = F_5 () ;
T_5 * V_27 ;
T_1 V_28 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
V_7 = F_6 ( V_23 , NULL , L_3 ) ;
if ( ! V_7 )
return;
V_23 = V_7 ;
if ( F_17 ( V_7 , L_4 , NULL ) )
continue;
V_25 = F_18 ( sizeof( * V_25 ) + 6 , V_29 ) ;
if ( ! V_25 )
return;
V_25 -> V_30 = V_25 + 1 ;
V_25 -> V_31 = 6 ;
V_25 -> V_32 = F_19 ( L_4 , V_29 ) ;
if ( ! V_25 -> V_32 ) {
F_20 ( V_25 ) ;
return;
}
V_27 = V_25 -> V_30 ;
switch ( V_22 ) {
case V_33 :
V_27 [ 0 ] = 0x00 ;
V_27 [ 1 ] = 0x04 ;
V_27 [ 2 ] = 0x9f ;
break;
case V_34 :
V_27 [ 0 ] = 0xc0 ;
V_27 [ 1 ] = 0xe5 ;
V_27 [ 2 ] = 0x4e ;
break;
case V_35 :
V_27 [ 0 ] = 0x58 ;
V_27 [ 1 ] = 0xb9 ;
V_27 [ 2 ] = 0xe1 ;
break;
case V_36 :
V_27 [ 0 ] = 0x00 ;
V_27 [ 1 ] = 0x01 ;
V_27 [ 2 ] = 0x87 ;
break;
case V_37 :
V_27 [ 0 ] = 0x00 ;
V_27 [ 1 ] = 0x1e ;
V_27 [ 2 ] = 0xac ;
break;
}
V_28 = V_26 [ V_10 ] ;
V_27 [ 3 ] = ( V_28 >> 16 ) & 0xff ;
V_27 [ 4 ] = ( V_28 >> 8 ) & 0xff ;
V_27 [ 5 ] = ( V_28 >> 0 ) & 0xff ;
F_21 ( V_7 , V_25 ) ;
}
}
static inline void F_22 ( void )
{
struct V_38 * V_38 = F_23 ( L_5 , NULL ) ;
if ( ! F_24 ( V_38 ) )
F_25 ( V_38 ) ;
}
static void T_4 F_26 ( void )
{
F_16 ( V_33 ) ;
F_27 ( V_39 ) ;
}
static void T_4 F_28 ( void )
{
F_16 ( V_37 ) ;
}
static int F_29 ( struct V_40 * V_41 )
{
V_41 -> V_42 |= V_43 ;
return 0 ;
}
static void T_4 F_30 ( void )
{
F_22 () ;
if ( F_31 ( V_44 ) )
F_32 ( V_45 , V_46 ,
F_29 ) ;
}
static void T_4 F_33 ( void )
{
struct V_6 * V_7 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 ;
F_22 () ;
V_7 = F_6 ( NULL , NULL , L_3 ) ;
V_48 = F_34 ( V_7 ) ;
if ( ! V_48 ) {
F_15 ( L_6 , V_20 ) ;
return;
}
V_50 = F_35 ( & V_48 -> V_52 , L_7 ) ;
if ( F_24 ( V_50 ) ) {
F_15 ( L_8 , V_20 ) ;
return;
}
V_51 = F_36 ( V_53 , F_37 ( V_53 ) ) ;
if ( V_51 ) {
F_15 ( L_9 , V_20 , V_51 ) ;
return;
}
F_38 ( V_54 , 1 ) ;
F_39 ( 26 ) ;
F_38 ( V_55 , 1 ) ;
F_38 ( V_56 , 1 ) ;
F_38 ( V_57 , 1 ) ;
F_13 ( 100 ) ;
F_38 ( V_58 , 1 ) ;
F_40 ( V_50 ) ;
}
static void T_4 F_41 ( void )
{
F_16 ( V_35 ) ;
}
static void T_4 F_42 ( void )
{
F_16 ( V_36 ) ;
}
static void T_4 F_43 ( void )
{
F_16 ( V_34 ) ;
}
static const char T_4 * F_44 ( void )
{
struct V_6 * V_7 ;
void T_2 * V_59 ;
V_7 = F_6 ( NULL , NULL , L_10 ) ;
V_59 = F_7 ( V_7 , 0 ) ;
F_8 ( ! V_59 ) ;
V_60 = F_45 ( V_59 + V_61 ) ;
V_62 = V_60 & V_63 ;
F_46 ( V_59 ) ;
F_47 ( V_7 ) ;
switch ( V_62 ) {
case V_64 :
return L_11 ;
case V_65 :
return L_12 ;
default:
return L_13 ;
}
}
static T_1 T_4 F_48 ( void )
{
T_1 V_66 = V_60 & V_67 ;
switch ( V_62 ) {
case V_64 :
switch ( V_66 ) {
case 0x0 :
return V_68 ;
case 0x1 :
return V_69 ;
case 0x2 :
return V_70 ;
case 0x3 :
return V_71 ;
case 0x4 :
return V_72 ;
default:
return V_73 ;
}
case V_65 :
switch ( V_66 ) {
case 0x0 :
return V_69 ;
case 0x1 :
return V_70 ;
default:
return V_73 ;
}
default:
return V_73 ;
}
}
static const char T_4 * F_49 ( void )
{
T_1 V_66 = F_48 () ;
if ( V_66 != V_73 )
return F_50 ( V_29 , L_14 , ( V_66 >> 4 ) & 0xf ,
V_66 & 0xf ) ;
else
return F_50 ( V_29 , L_15 , L_13 ) ;
}
static int T_4 F_51 ( void )
{
struct V_6 * V_7 ;
V_7 = F_6 ( NULL , NULL , L_16 ) ;
V_74 = F_7 ( V_7 , 0 ) ;
if ( ! V_74 )
return - V_75 ;
if ( F_52 ( V_7 , L_17 ) )
V_74 += V_76 ;
else
V_74 += V_77 ;
F_47 ( V_7 ) ;
return 0 ;
}
static void T_4 F_53 ( void )
{
F_27 ( V_39 ) ;
}
static void T_4 F_54 ( void )
{
struct V_6 * V_78 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_51 ;
V_84 = F_18 ( sizeof( * V_84 ) , V_29 ) ;
if ( ! V_84 )
return;
V_78 = F_55 ( L_18 ) ;
V_51 = F_56 ( V_78 , L_19 , & V_84 -> V_85 ) ;
if ( V_51 )
return;
V_84 -> V_86 = L_20 ;
V_84 -> V_87 = F_44 () ;
V_84 -> V_88 = F_49 () ;
V_82 = F_57 ( V_84 ) ;
if ( F_24 ( V_82 ) ) {
F_20 ( V_84 -> V_88 ) ;
F_20 ( V_84 ) ;
return;
}
V_80 = F_58 ( V_82 ) ;
if ( F_59 ( L_21 ) )
F_26 () ;
if ( F_59 ( L_22 ) )
F_28 () ;
else if ( F_59 ( L_23 ) )
F_30 () ;
else if ( F_59 ( L_24 ) )
F_41 () ;
else if ( F_59 ( L_25 ) )
F_53 () ;
else if ( F_59 ( L_26 ) )
F_42 () ;
else if ( F_59 ( L_27 ) )
F_43 () ;
F_60 ( NULL , NULL , V_80 ) ;
F_51 () ;
if ( F_59 ( L_28 ) )
F_33 () ;
}
static void F_61 ( enum V_89 V_90 , const char * V_91 )
{
if ( V_74 ) {
F_1 ( V_92 , V_74 ) ;
F_15 ( L_29 ) ;
F_62 ( 50 ) ;
}
F_63 ( 0 ) ;
}
