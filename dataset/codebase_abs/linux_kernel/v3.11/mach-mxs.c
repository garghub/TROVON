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
struct V_36 * V_36 = F_23 ( L_5 , NULL ) ;
if ( ! F_24 ( V_36 ) )
F_25 ( V_36 ) ;
}
static void T_4 F_26 ( void )
{
F_16 ( V_33 ) ;
F_27 ( V_37 ) ;
}
static int F_28 ( struct V_38 * V_39 )
{
V_39 -> V_40 |= V_41 ;
return 0 ;
}
static void T_4 F_29 ( void )
{
F_22 () ;
if ( F_30 ( V_42 ) )
F_31 ( V_43 , V_44 ,
F_28 ) ;
}
static void T_4 F_32 ( void )
{
struct V_6 * V_7 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_49 ;
F_22 () ;
V_7 = F_6 ( NULL , NULL , L_3 ) ;
V_46 = F_33 ( V_7 ) ;
if ( ! V_46 ) {
F_15 ( L_6 , V_20 ) ;
return;
}
V_48 = F_34 ( & V_46 -> V_50 , L_7 ) ;
if ( F_24 ( V_48 ) ) {
F_15 ( L_8 , V_20 ) ;
return;
}
V_49 = F_35 ( V_51 , F_36 ( V_51 ) ) ;
if ( V_49 ) {
F_15 ( L_9 , V_20 , V_49 ) ;
return;
}
F_37 ( V_52 , 1 ) ;
F_38 ( 26 ) ;
F_37 ( V_53 , 1 ) ;
F_37 ( V_54 , 1 ) ;
F_37 ( V_55 , 1 ) ;
F_13 ( 100 ) ;
F_37 ( V_56 , 1 ) ;
F_39 ( V_48 ) ;
}
static void T_4 F_40 ( void )
{
F_16 ( V_35 ) ;
}
static const char T_4 * F_41 ( void )
{
struct V_6 * V_7 ;
void T_2 * V_57 ;
V_7 = F_6 ( NULL , NULL , L_10 ) ;
V_57 = F_7 ( V_7 , 0 ) ;
F_8 ( ! V_57 ) ;
V_58 = F_42 ( V_57 + V_59 ) ;
V_60 = V_58 & V_61 ;
F_43 ( V_57 ) ;
F_44 ( V_7 ) ;
switch ( V_60 ) {
case V_62 :
return L_11 ;
case V_63 :
return L_12 ;
default:
return L_13 ;
}
}
static T_1 T_4 F_45 ( void )
{
T_1 V_64 = V_58 & V_65 ;
switch ( V_60 ) {
case V_62 :
switch ( V_64 ) {
case 0x0 :
return V_66 ;
case 0x1 :
return V_67 ;
case 0x2 :
return V_68 ;
case 0x3 :
return V_69 ;
case 0x4 :
return V_70 ;
default:
return V_71 ;
}
case V_63 :
switch ( V_64 ) {
case 0x0 :
return V_67 ;
case 0x1 :
return V_68 ;
default:
return V_71 ;
}
default:
return V_71 ;
}
}
static const char T_4 * F_46 ( void )
{
T_1 V_64 = F_45 () ;
if ( V_64 != V_71 )
return F_47 ( V_29 , L_14 , ( V_64 >> 4 ) & 0xf ,
V_64 & 0xf ) ;
else
return F_47 ( V_29 , L_15 , L_13 ) ;
}
static void T_4 F_48 ( void )
{
struct V_6 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
int V_49 ;
V_78 = F_18 ( sizeof( * V_78 ) , V_29 ) ;
if ( ! V_78 )
return;
V_72 = F_49 ( L_16 ) ;
V_49 = F_50 ( V_72 , L_17 , & V_78 -> V_79 ) ;
if ( V_49 )
return;
V_78 -> V_80 = L_18 ;
V_78 -> V_81 = F_41 () ;
V_78 -> V_82 = F_46 () ;
V_76 = F_51 ( V_78 ) ;
if ( F_24 ( V_76 ) ) {
F_20 ( V_78 -> V_82 ) ;
F_20 ( V_78 ) ;
return;
}
V_74 = F_52 ( V_76 ) ;
if ( F_53 ( L_19 ) )
F_26 () ;
else if ( F_53 ( L_20 ) )
F_29 () ;
else if ( F_53 ( L_21 ) ||
F_53 ( L_22 ) ||
F_53 ( L_23 ) ||
F_53 ( L_24 ) )
F_40 () ;
F_54 ( NULL , V_83 ,
NULL , V_74 ) ;
if ( F_53 ( L_25 ) )
F_32 () ;
}
static void F_55 ( enum V_84 V_85 , const char * V_86 )
{
struct V_6 * V_7 ;
void T_2 * V_87 ;
V_7 = F_6 ( NULL , NULL , L_26 ) ;
V_87 = F_7 ( V_7 , 0 ) ;
if ( ! V_87 )
goto V_88;
if ( F_56 ( V_7 , L_27 ) )
V_87 += V_89 ;
else
V_87 += V_90 ;
F_1 ( V_91 , V_87 ) ;
F_15 ( L_28 ) ;
F_57 ( 50 ) ;
V_88:
F_58 ( 0 ) ;
}
static void T_4 F_59 ( void )
{
if ( F_53 ( L_29 ) )
F_60 () ;
else
F_61 () ;
F_62 () ;
}
