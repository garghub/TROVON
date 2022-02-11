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
static void F_5 ( void )
{
if ( V_6 || V_7 )
F_6 ( V_8 , 1 ) ;
else
F_6 ( V_8 , 0 ) ;
}
static void F_7 ( int V_9 )
{
V_6 = V_9 ;
F_5 () ;
}
static void F_8 ( int V_9 )
{
V_7 = V_9 ;
F_5 () ;
}
static const T_1 * F_9 ( void )
{
struct V_10 * V_11 ;
void T_2 * V_12 ;
int V_13 = 0x400 ;
T_3 V_14 ;
static int V_15 ;
if ( V_15 )
return V_16 ;
V_11 = F_10 ( NULL , NULL , L_1 ) ;
V_12 = F_11 ( V_11 , 0 ) ;
F_12 ( ! V_12 ) ;
F_13 ( & V_17 ) ;
F_3 ( V_18 , V_12 ) ;
while ( ( F_14 ( V_12 ) &
( V_19 | V_18 ) ) && -- V_13 )
F_15 () ;
if ( F_16 ( ! V_13 ) )
goto V_20;
F_1 ( V_21 , V_12 ) ;
F_17 ( 1 ) ;
V_13 = 0x400 ;
while ( ( F_14 ( V_12 ) & V_19 ) && -- V_13 )
F_15 () ;
if ( F_16 ( ! V_13 ) )
goto V_20;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
V_16 [ V_14 ] = F_14 ( V_12 + V_23 +
V_14 * 0x10 ) ;
F_3 ( V_21 , V_12 ) ;
V_15 = 1 ;
F_18 ( & V_17 ) ;
return V_16 ;
V_20:
F_18 ( & V_17 ) ;
F_19 ( L_2 , V_24 ) ;
return NULL ;
}
static void T_4 F_20 ( enum V_25 V_26 )
{
struct V_10 * V_11 , * V_27 = NULL ;
struct V_28 * V_29 ;
const T_1 * V_30 = F_9 () ;
T_5 * V_31 ;
T_1 V_32 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
V_11 = F_10 ( V_27 , NULL , L_3 ) ;
if ( ! V_11 )
return;
V_27 = V_11 ;
if ( F_21 ( V_11 , L_4 , NULL ) )
continue;
V_29 = F_22 ( sizeof( * V_29 ) + 6 , V_33 ) ;
if ( ! V_29 )
return;
V_29 -> V_34 = V_29 + 1 ;
V_29 -> V_35 = 6 ;
V_29 -> V_36 = F_23 ( L_4 , V_33 ) ;
if ( ! V_29 -> V_36 ) {
F_24 ( V_29 ) ;
return;
}
V_31 = V_29 -> V_34 ;
switch ( V_26 ) {
case V_37 :
V_31 [ 0 ] = 0x00 ;
V_31 [ 1 ] = 0x04 ;
V_31 [ 2 ] = 0x9f ;
break;
case V_38 :
V_31 [ 0 ] = 0xc0 ;
V_31 [ 1 ] = 0xe5 ;
V_31 [ 2 ] = 0x4e ;
break;
case V_39 :
V_31 [ 0 ] = 0x58 ;
V_31 [ 1 ] = 0xb9 ;
V_31 [ 2 ] = 0xe1 ;
break;
}
V_32 = V_30 [ V_14 ] ;
V_31 [ 3 ] = ( V_32 >> 16 ) & 0xff ;
V_31 [ 4 ] = ( V_32 >> 8 ) & 0xff ;
V_31 [ 5 ] = ( V_32 >> 0 ) & 0xff ;
F_25 ( V_11 , V_29 ) ;
}
}
static inline void F_26 ( void )
{
struct V_40 * V_40 = F_27 ( L_5 , NULL ) ;
if ( ! F_28 ( V_40 ) )
F_29 ( V_40 ) ;
}
static void T_4 F_30 ( void )
{
F_20 ( V_37 ) ;
F_31 ( V_41 ) ;
}
static void T_4 F_32 ( void )
{
if ( ! F_33 ( V_8 , V_42 ,
L_6 ) ) {
V_43 [ 0 ] . V_44 = F_7 ;
V_43 [ 1 ] . V_44 = F_8 ;
}
}
static int F_34 ( struct V_45 * V_46 )
{
V_46 -> V_47 |= V_48 ;
return 0 ;
}
static void T_4 F_35 ( void )
{
F_26 () ;
if ( F_36 ( V_49 ) )
F_37 ( V_50 , V_51 ,
F_34 ) ;
}
static void T_4 F_38 ( void )
{
struct V_10 * V_11 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_56 ;
F_26 () ;
V_11 = F_10 ( NULL , NULL , L_3 ) ;
V_53 = F_39 ( V_11 ) ;
if ( ! V_53 ) {
F_19 ( L_7 , V_24 ) ;
return;
}
V_55 = F_40 ( & V_53 -> V_57 , L_8 ) ;
if ( F_28 ( V_55 ) ) {
F_19 ( L_9 , V_24 ) ;
return;
}
V_56 = F_41 ( V_58 , F_42 ( V_58 ) ) ;
if ( V_56 ) {
F_19 ( L_10 , V_24 , V_56 ) ;
return;
}
F_6 ( V_59 , 1 ) ;
F_43 ( 26 ) ;
F_6 ( V_60 , 1 ) ;
F_6 ( V_61 , 1 ) ;
F_6 ( V_62 , 1 ) ;
F_17 ( 100 ) ;
F_6 ( V_63 , 1 ) ;
F_44 ( V_55 ) ;
}
static void T_4 F_45 ( void )
{
F_20 ( V_39 ) ;
}
static void T_4 F_46 ( void )
{
F_20 ( V_39 ) ;
}
static void T_4 F_47 ( void )
{
if ( F_48 ( L_11 ) )
F_30 () ;
else if ( F_48 ( L_12 ) )
F_35 () ;
else if ( F_48 ( L_13 ) )
F_46 () ;
else if ( F_48 ( L_14 ) )
F_45 () ;
F_49 ( NULL , V_64 ,
V_65 , NULL ) ;
if ( F_48 ( L_15 ) )
F_38 () ;
if ( F_48 ( L_11 ) )
F_32 () ;
}
static void F_50 ( char V_66 , const char * V_67 )
{
struct V_10 * V_11 ;
void T_2 * V_68 ;
V_11 = F_10 ( NULL , NULL , L_16 ) ;
V_68 = F_11 ( V_11 , 0 ) ;
if ( ! V_68 )
goto V_69;
if ( F_51 ( V_11 , L_17 ) )
V_68 += V_70 ;
else
V_68 += V_71 ;
F_1 ( V_72 , V_68 ) ;
F_19 ( L_18 ) ;
F_52 ( 50 ) ;
V_69:
F_53 ( 0 ) ;
}
static void T_4 F_54 ( void )
{
if ( F_48 ( L_19 ) )
F_55 () ;
else
F_56 () ;
F_57 () ;
}
