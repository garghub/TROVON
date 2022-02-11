static T_1 F_1 ( const void * V_1 , unsigned int V_2 , T_2 V_3 )
{
#ifndef F_2
return V_3 & V_4 ;
#else
const struct V_5 * V_6 = V_1 + 0xc08 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
T_3 V_8 = F_3 ( & V_6 [ V_7 ] . V_8 ) ;
T_2 V_9 = F_3 ( & V_6 [ V_7 ] . V_9 ) ;
if ( ( V_9 & V_10 ) == V_11 )
return ( V_3 & V_4 ) | ( ( V_8 & V_12 ) << 12 ) ;
}
return 0 ;
#endif
}
static void F_4 ( enum V_13 V_14 )
{
struct V_15 * V_16 ;
struct V_15 * V_17 = NULL ;
struct V_15 * V_18 = NULL ;
struct V_19 T_4 * V_20 ;
struct V_21 * V_22 = NULL ;
void * V_1 = NULL ;
T_5 T_4 * V_23 = NULL ;
T_5 T_4 * V_24 = NULL ;
T_1 V_25 , V_26 ;
T_2 V_27 , V_28 , V_29 , V_30 ;
const T_6 * V_31 ;
unsigned int V_32 ;
T_5 V_33 ;
V_16 = F_5 ( NULL , NULL , L_1 ) ;
if ( ! V_16 ) {
F_6 ( L_2 ) ;
return;
}
V_20 = F_7 ( V_16 , 0 ) ;
if ( ! V_20 ) {
F_6 ( L_3 ) ;
goto exit;
}
V_17 = F_5 ( NULL , NULL , L_4 ) ;
if ( ! V_17 ) {
F_6 ( L_5 ) ;
goto exit;
}
V_22 = F_7 ( V_17 , 0 ) ;
if ( ! V_22 ) {
F_6 ( L_6 ) ;
goto exit;
}
V_18 = F_5 ( NULL , NULL , L_7 ) ;
if ( ! V_18 ) {
F_6 ( L_8 ) ;
goto exit;
}
V_1 = F_7 ( V_18 , 0 ) ;
if ( ! V_1 ) {
F_6 ( L_9 ) ;
goto exit;
}
V_31 = F_8 ( V_18 , L_10 , NULL ) ;
if ( ! V_31 ) {
F_6 ( L_11 ) ;
goto exit;
}
V_32 = F_9 ( V_31 ) ;
V_27 = F_3 ( & V_22 -> V_34 [ 0 ] . V_3 ) ;
V_29 = F_3 ( & V_22 -> V_34 [ 1 ] . V_3 ) ;
V_28 = F_3 ( & V_22 -> V_34 [ 0 ] . V_35 ) ;
V_30 = F_3 ( & V_22 -> V_34 [ 1 ] . V_35 ) ;
if ( ! ( V_27 & V_36 ) || ! ( V_29 & V_36 ) ) {
F_6 ( L_12 ) ;
goto exit;
}
if ( ( V_27 & V_37 ) != V_38 ) {
V_27 = ( V_27 & V_4 ) | V_36 ;
V_28 = 0xFFFF8000 | 0xFF7 ;
F_10 ( & V_22 -> V_34 [ 0 ] . V_3 , V_27 ) ;
F_10 ( & V_22 -> V_34 [ 0 ] . V_35 , V_28 ) ;
}
if ( ( V_29 & V_37 ) != V_38 ) {
V_29 = ( V_29 & V_4 ) | V_36 ;
V_30 = 0xFFFF8000 | 0xFF7 ;
F_10 ( & V_22 -> V_34 [ 1 ] . V_3 , V_29 ) ;
F_10 ( & V_22 -> V_34 [ 1 ] . V_35 , V_30 ) ;
}
V_25 = F_1 ( V_1 , V_32 , V_27 ) ;
if ( ! V_25 ) {
F_6 ( L_13
L_14 , V_27 ) ;
goto exit;
}
V_26 = F_1 ( V_1 , V_32 , V_29 ) ;
if ( ! V_26 ) {
F_6 ( L_15
L_16 , V_29 ) ;
goto exit;
}
V_23 = F_11 ( V_25 , 1 ) ;
if ( ! V_23 ) {
F_6 ( L_17 ,
( unsigned long long ) V_25 ) ;
goto exit;
}
V_24 = F_11 ( V_26 , 1 ) ;
if ( ! V_24 ) {
F_6 ( L_18 ,
( unsigned long long ) V_26 ) ;
goto exit;
}
if ( ( F_3 ( & V_20 -> V_39 ) & V_40 ) !=
V_41 ) {
struct V_15 * V_42 ;
void T_4 * V_43 ;
V_42 =
F_5 ( NULL , NULL , L_19 ) ;
if ( ! V_42 ) {
F_6 ( L_20 ) ;
goto exit;
}
V_43 = F_7 ( V_42 , 0 ) ;
F_12 ( V_42 ) ;
if ( ! V_43 ) {
F_6 ( L_21 ) ;
goto exit;
}
F_13 ( V_43 + V_44 , V_45 ) ;
F_14 ( V_43 ) ;
F_15 ( V_23 , V_46 ) ;
V_33 = F_16 ( V_24 ) ;
V_33 |= V_47 ;
F_15 ( V_24 , V_33 ) ;
F_17 ( & V_20 -> V_39 , V_40 ,
V_41 ) ;
F_3 ( & V_20 -> V_39 ) ;
}
switch ( V_14 ) {
case V_48 :
F_15 ( V_23 , V_49 ) ;
V_33 = F_16 ( V_24 ) ;
V_33 &= ~ ( V_50 | V_51 ) ;
V_33 |= V_52 ;
F_15 ( V_24 , V_33 ) ;
break;
case V_53 :
F_15 ( V_23 , V_49 ) ;
V_33 = F_16 ( V_24 ) ;
V_33 &= ~ V_52 ;
V_33 |= V_50 | V_51 ;
F_15 ( V_24 , V_33 ) ;
break;
default:
F_6 ( L_22 , V_14 ) ;
}
exit:
if ( V_24 )
F_14 ( V_24 ) ;
if ( V_23 )
F_14 ( V_23 ) ;
if ( V_22 )
F_14 ( V_22 ) ;
if ( V_1 )
F_14 ( V_1 ) ;
if ( V_20 )
F_14 ( V_20 ) ;
F_12 ( V_18 ) ;
F_12 ( V_17 ) ;
F_12 ( V_16 ) ;
}
void F_18 ( unsigned int V_54 )
{
struct V_15 * V_55 = NULL ;
struct V_19 T_4 * V_20 ;
unsigned long V_56 ;
T_3 V_57 ;
T_2 V_58 ;
V_55 = F_5 ( NULL , NULL , L_1 ) ;
if ( ! V_55 ) {
F_6 ( L_2 ) ;
return;
}
V_20 = F_7 ( V_55 , 0 ) ;
F_12 ( V_55 ) ;
if ( ! V_20 ) {
F_6 ( L_3 ) ;
return;
}
V_57 = 1000000000000ULL ;
F_19 ( V_57 , V_54 ) ;
V_56 = V_57 ;
V_58 = F_20 ( F_21 () , V_56 ) ;
V_58 = F_22 ( T_2 , V_58 , 2 , 255 ) ;
F_23 ( & V_20 -> V_59 ,
V_60 | V_61 | V_62 ) ;
F_24 ( & V_20 -> V_59 , V_60 | ( V_58 << 16 ) ) ;
F_14 ( V_20 ) ;
}
enum V_13
F_25 ( enum V_13 V_14 )
{
switch ( V_14 ) {
case V_48 :
case V_53 :
return V_14 ;
default:
return V_48 ;
}
}
void T_7 F_26 ( void )
{
struct V_63 * V_63 = F_27 ( NULL , 0 , V_64 |
V_65 ,
0 , 256 , L_23 ) ;
F_28 ( V_63 == NULL ) ;
F_29 ( V_63 ) ;
}
static int T_7 F_30 ( char * V_66 )
{
V_67 = ( strncmp ( V_66 , L_24 , 6 ) == 0 ) ;
return 0 ;
}
static void T_7 F_31 ( void )
{
if ( V_68 . V_69 )
V_68 . V_69 ( L_25 , 0 ) ;
#if F_32 ( V_70 ) || F_32 ( V_71 )
V_72 . V_73 = F_4 ;
V_72 . V_74 = F_18 ;
V_72 . V_75 = F_25 ;
if ( V_67 ) {
struct V_15 * V_76 =
F_5 ( NULL , NULL , L_4 ) ;
if ( V_76 ) {
struct V_15 * V_77 ;
F_33 ( V_76 ) ;
V_77 = F_5 ( V_76 , NULL , L_26 ) ;
if ( V_77 ) {
static struct V_78 V_79 = {
. V_80 = L_27 ,
. V_81 = L_28 ,
. V_82 = sizeof( L_28 ) ,
} ;
F_34 ( L_29 ,
V_77 -> V_83 ) ;
F_35 ( V_77 , & V_79 ) ;
F_12 ( V_77 ) ;
}
F_33 ( V_76 ) ;
V_77 = F_5 ( V_76 , NULL ,
L_30 ) ;
if ( V_77 ) {
static struct V_78 V_84 = {
. V_80 = L_27 ,
. V_81 = L_28 ,
. V_82 = sizeof( L_28 ) ,
} ;
F_34 ( L_29 ,
V_77 -> V_83 ) ;
F_35 ( V_77 , & V_84 ) ;
F_12 ( V_77 ) ;
}
F_12 ( V_76 ) ;
}
}
#endif
F_36 () ;
F_37 () ;
F_38 () ;
F_34 ( L_31 ) ;
}
static int T_7 F_39 ( void )
{
unsigned long V_85 = F_40 () ;
return F_41 ( V_85 , L_32 ) ;
}
