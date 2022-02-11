static T_1 F_1 ( enum V_1 V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case 32 :
return F_2 ( 3 , 2 , 0 , 1 , 3 , 8 , 8 , 8 , 8 ) ;
case 24 :
return F_2 ( 4 , 0 , 1 , 2 , 2 , 0 , 8 , 8 , 8 ) ;
case 16 :
return F_2 ( 4 , 2 , 1 , 0 , 1 , 5 , 6 , 5 , 0 ) ;
default:
F_3 ( L_1 , V_3 ) ;
return 0 ;
}
}
static void F_4 ( enum V_1 V_2 ,
char * V_4 )
{
}
static T_2 F_5 ( const void * V_5 , unsigned int V_6 , T_1 V_7 )
{
#ifndef F_6
return V_7 & V_8 ;
#else
const struct V_9 * V_10 = V_5 + 0xc08 ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ ) {
T_3 V_12 = F_7 ( & V_10 [ V_11 ] . V_12 ) ;
T_1 V_13 = F_7 ( & V_10 [ V_11 ] . V_13 ) ;
if ( ( V_13 & V_14 ) == V_15 )
return ( V_7 & V_8 ) | ( ( V_12 & V_16 ) << 12 ) ;
}
return 0 ;
#endif
}
static void F_8 ( enum V_1 V_2 )
{
struct V_17 * V_18 ;
struct V_17 * V_19 = NULL ;
struct V_17 * V_20 = NULL ;
struct V_21 T_4 * V_22 ;
struct V_23 * V_24 = NULL ;
void * V_5 = NULL ;
T_5 T_4 * V_25 = NULL ;
T_5 T_4 * V_26 = NULL ;
T_2 V_27 , V_28 ;
T_1 V_29 , V_30 , V_31 , V_32 ;
const T_6 * V_33 ;
unsigned int V_34 ;
T_5 V_35 ;
V_18 = F_9 ( NULL , NULL , L_2 ) ;
if ( ! V_18 ) {
F_3 ( L_3 ) ;
return;
}
V_22 = F_10 ( V_18 , 0 ) ;
if ( ! V_22 ) {
F_3 ( L_4 ) ;
goto exit;
}
V_19 = F_9 ( NULL , NULL , L_5 ) ;
if ( ! V_19 ) {
F_3 ( L_6 ) ;
goto exit;
}
V_24 = F_10 ( V_19 , 0 ) ;
if ( ! V_24 ) {
F_3 ( L_7 ) ;
goto exit;
}
V_20 = F_9 ( NULL , NULL , L_8 ) ;
if ( ! V_20 ) {
F_3 ( L_9 ) ;
goto exit;
}
V_5 = F_10 ( V_20 , 0 ) ;
if ( ! V_5 ) {
F_3 ( L_10 ) ;
goto exit;
}
V_33 = F_11 ( V_20 , L_11 , NULL ) ;
if ( ! V_33 ) {
F_3 ( L_12 ) ;
goto exit;
}
V_34 = F_12 ( V_33 ) ;
V_29 = F_7 ( & V_24 -> V_36 [ 0 ] . V_7 ) ;
V_31 = F_7 ( & V_24 -> V_36 [ 1 ] . V_7 ) ;
V_30 = F_7 ( & V_24 -> V_36 [ 0 ] . V_37 ) ;
V_32 = F_7 ( & V_24 -> V_36 [ 1 ] . V_37 ) ;
if ( ! ( V_29 & V_38 ) || ! ( V_31 & V_38 ) ) {
F_3 ( L_13 ) ;
goto exit;
}
if ( ( V_29 & V_39 ) != V_40 ) {
V_29 = ( V_29 & V_8 ) | V_38 ;
V_30 = 0xFFFF8000 | 0xFF7 ;
F_13 ( & V_24 -> V_36 [ 0 ] . V_7 , V_29 ) ;
F_13 ( & V_24 -> V_36 [ 0 ] . V_37 , V_30 ) ;
}
if ( ( V_31 & V_39 ) != V_40 ) {
V_31 = ( V_31 & V_8 ) | V_38 ;
V_32 = 0xFFFF8000 | 0xFF7 ;
F_13 ( & V_24 -> V_36 [ 1 ] . V_7 , V_31 ) ;
F_13 ( & V_24 -> V_36 [ 1 ] . V_37 , V_32 ) ;
}
V_27 = F_5 ( V_5 , V_34 , V_29 ) ;
if ( ! V_27 ) {
F_3 ( L_14
L_15 , V_29 ) ;
goto exit;
}
V_28 = F_5 ( V_5 , V_34 , V_31 ) ;
if ( ! V_27 ) {
F_3 ( L_16
L_17 , V_31 ) ;
goto exit;
}
V_25 = F_14 ( V_27 , 1 ) ;
if ( ! V_25 ) {
F_3 ( L_18 ,
( unsigned long long ) V_27 ) ;
goto exit;
}
V_26 = F_14 ( V_28 , 1 ) ;
if ( ! V_26 ) {
F_3 ( L_19 ,
( unsigned long long ) V_28 ) ;
goto exit;
}
if ( ( F_7 ( & V_22 -> V_41 ) & V_42 ) !=
V_43 ) {
struct V_17 * V_44 ;
void T_4 * V_45 ;
V_44 =
F_9 ( NULL , NULL , L_20 ) ;
if ( ! V_44 ) {
F_3 ( L_21 ) ;
goto exit;
}
V_45 = F_10 ( V_44 , 0 ) ;
F_15 ( V_44 ) ;
if ( ! V_45 ) {
F_3 ( L_22 ) ;
goto exit;
}
F_16 ( V_45 + V_46 , V_47 ) ;
F_17 ( V_45 ) ;
F_18 ( V_25 , V_48 ) ;
V_35 = F_19 ( V_26 ) ;
V_35 |= V_49 ;
F_18 ( V_26 , V_35 ) ;
F_20 ( & V_22 -> V_41 , V_42 ,
V_43 ) ;
F_7 ( & V_22 -> V_41 ) ;
}
switch ( V_2 ) {
case V_50 :
F_18 ( V_25 , V_51 ) ;
V_35 = F_19 ( V_26 ) ;
V_35 &= ~ ( V_52 | V_53 ) ;
V_35 |= V_54 ;
F_18 ( V_26 , V_35 ) ;
break;
case V_55 :
F_18 ( V_25 , V_51 ) ;
V_35 = F_19 ( V_26 ) ;
V_35 &= ~ V_54 ;
V_35 |= V_52 | V_53 ;
F_18 ( V_26 , V_35 ) ;
break;
default:
F_3 ( L_23 , V_2 ) ;
}
exit:
if ( V_26 )
F_17 ( V_26 ) ;
if ( V_25 )
F_17 ( V_25 ) ;
if ( V_24 )
F_17 ( V_24 ) ;
if ( V_5 )
F_17 ( V_5 ) ;
if ( V_22 )
F_17 ( V_22 ) ;
F_15 ( V_20 ) ;
F_15 ( V_19 ) ;
F_15 ( V_18 ) ;
}
void F_21 ( unsigned int V_56 )
{
struct V_17 * V_57 = NULL ;
struct V_21 T_4 * V_22 ;
unsigned long V_58 ;
T_3 V_59 ;
T_1 V_60 ;
V_57 = F_9 ( NULL , NULL , L_2 ) ;
if ( ! V_57 ) {
F_3 ( L_3 ) ;
return;
}
V_22 = F_10 ( V_57 , 0 ) ;
F_15 ( V_57 ) ;
if ( ! V_22 ) {
F_3 ( L_4 ) ;
return;
}
V_59 = 1000000000000ULL ;
F_22 ( V_59 , V_56 ) ;
V_58 = V_59 ;
V_60 = F_23 ( F_24 () , V_58 ) ;
V_60 = F_25 ( T_1 , V_60 , 2 , 255 ) ;
F_26 ( & V_22 -> V_61 ,
V_62 | V_63 | V_64 ) ;
F_27 ( & V_22 -> V_61 , V_62 | ( V_60 << 16 ) ) ;
F_17 ( V_22 ) ;
}
enum V_1
F_28 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_50 :
case V_55 :
return V_2 ;
default:
return V_50 ;
}
}
void T_7 F_29 ( void )
{
struct V_65 * V_65 = F_30 ( NULL , 0 , V_66 |
V_67 ,
0 , 256 , L_24 ) ;
F_31 ( V_65 == NULL ) ;
F_32 ( V_65 ) ;
}
static int T_7 F_33 ( char * V_68 )
{
V_69 = ( strncmp ( V_68 , L_25 , 6 ) == 0 ) ;
return 0 ;
}
static void T_7 F_34 ( void )
{
if ( V_70 . V_71 )
V_70 . V_71 ( L_26 , 0 ) ;
#if F_35 ( V_72 ) || F_35 ( V_73 )
V_74 . V_75 = F_1 ;
V_74 . V_76 = F_4 ;
V_74 . V_77 = F_8 ;
V_74 . V_78 = F_21 ;
V_74 . V_79 = F_28 ;
if ( V_69 ) {
struct V_17 * V_80 =
F_9 ( NULL , NULL , L_5 ) ;
if ( V_80 ) {
struct V_17 * V_81 ;
F_36 ( V_80 ) ;
V_81 = F_9 ( V_80 , NULL , L_27 ) ;
if ( V_81 ) {
static struct V_82 V_83 = {
. V_84 = L_28 ,
. V_85 = L_29 ,
. V_86 = sizeof( L_29 ) ,
} ;
F_37 ( L_30 ,
V_81 -> V_87 ) ;
F_38 ( V_81 , & V_83 ) ;
F_15 ( V_81 ) ;
}
F_36 ( V_80 ) ;
V_81 = F_9 ( V_80 , NULL ,
L_31 ) ;
if ( V_81 ) {
static struct V_82 V_88 = {
. V_84 = L_28 ,
. V_85 = L_29 ,
. V_86 = sizeof( L_29 ) ,
} ;
F_37 ( L_30 ,
V_81 -> V_87 ) ;
F_38 ( V_81 , & V_88 ) ;
F_15 ( V_81 ) ;
}
F_15 ( V_80 ) ;
}
}
#endif
F_39 () ;
F_40 () ;
F_41 () ;
F_37 ( L_32 ) ;
}
static int T_7 F_42 ( void )
{
unsigned long V_89 = F_43 () ;
return F_44 ( V_89 , L_33 ) ;
}
