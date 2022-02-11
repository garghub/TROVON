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
F_16 ( V_35 ) ;
}
static void T_4 F_34 ( void )
{
F_16 ( V_36 ) ;
}
static void T_4 F_35 ( void )
{
F_16 ( V_34 ) ;
}
static const char T_4 * F_36 ( void )
{
struct V_6 * V_7 ;
void T_2 * V_47 ;
V_7 = F_6 ( NULL , NULL , L_6 ) ;
V_47 = F_7 ( V_7 , 0 ) ;
F_8 ( ! V_47 ) ;
V_48 = F_37 ( V_47 + V_49 ) ;
V_50 = V_48 & V_51 ;
F_38 ( V_47 ) ;
F_39 ( V_7 ) ;
switch ( V_50 ) {
case V_52 :
return L_7 ;
case V_53 :
return L_8 ;
default:
return L_9 ;
}
}
static T_1 T_4 F_40 ( void )
{
T_1 V_54 = V_48 & V_55 ;
switch ( V_50 ) {
case V_52 :
switch ( V_54 ) {
case 0x0 :
return V_56 ;
case 0x1 :
return V_57 ;
case 0x2 :
return V_58 ;
case 0x3 :
return V_59 ;
case 0x4 :
return V_60 ;
default:
return V_61 ;
}
case V_53 :
switch ( V_54 ) {
case 0x0 :
return V_57 ;
case 0x1 :
return V_58 ;
default:
return V_61 ;
}
default:
return V_61 ;
}
}
static const char T_4 * F_41 ( void )
{
T_1 V_54 = F_40 () ;
if ( V_54 != V_61 )
return F_42 ( V_29 , L_10 , ( V_54 >> 4 ) & 0xf ,
V_54 & 0xf ) ;
else
return F_42 ( V_29 , L_11 , L_9 ) ;
}
static int T_4 F_43 ( void )
{
struct V_6 * V_7 ;
V_7 = F_6 ( NULL , NULL , L_12 ) ;
V_62 = F_7 ( V_7 , 0 ) ;
if ( ! V_62 )
return - V_63 ;
if ( F_44 ( V_7 , L_13 ) )
V_62 += V_64 ;
else
V_62 += V_65 ;
F_39 ( V_7 ) ;
return 0 ;
}
static void T_4 F_45 ( void )
{
F_27 ( V_39 ) ;
}
static void T_4 F_46 ( void )
{
struct V_6 * V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
int V_73 ;
V_72 = F_18 ( sizeof( * V_72 ) , V_29 ) ;
if ( ! V_72 )
return;
V_66 = F_47 ( L_14 ) ;
V_73 = F_48 ( V_66 , L_15 , & V_72 -> V_74 ) ;
if ( V_73 )
return;
V_72 -> V_75 = L_16 ;
V_72 -> V_76 = F_36 () ;
V_72 -> V_77 = F_41 () ;
V_70 = F_49 ( V_72 ) ;
if ( F_24 ( V_70 ) ) {
F_20 ( V_72 -> V_77 ) ;
F_20 ( V_72 ) ;
return;
}
V_68 = F_50 ( V_70 ) ;
if ( F_51 ( L_17 ) )
F_26 () ;
if ( F_51 ( L_18 ) )
F_28 () ;
else if ( F_51 ( L_19 ) )
F_30 () ;
else if ( F_51 ( L_20 ) )
F_33 () ;
else if ( F_51 ( L_21 ) )
F_45 () ;
else if ( F_51 ( L_22 ) )
F_34 () ;
else if ( F_51 ( L_23 ) )
F_35 () ;
F_52 ( NULL , NULL , V_68 ) ;
F_43 () ;
}
static void F_53 ( enum V_78 V_79 , const char * V_80 )
{
if ( V_62 ) {
F_1 ( V_81 , V_62 ) ;
F_15 ( L_24 ) ;
F_54 ( 50 ) ;
}
F_55 ( 0 ) ;
}
