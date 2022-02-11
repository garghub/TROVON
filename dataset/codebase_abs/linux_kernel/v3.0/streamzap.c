static void F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
F_2 ( V_2 -> V_5 , L_1 ,
( V_4 . V_6 ? L_2 : L_3 ) , V_4 . V_7 ) ;
F_3 ( V_2 -> V_8 , & V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned char V_9 )
{
F_5 ( V_4 ) ;
if ( V_2 -> V_10 ) {
long V_11 ;
V_2 -> V_12 = V_2 -> V_13 ;
F_6 ( & V_2 -> V_13 ) ;
V_11 = V_2 -> V_13 . V_14 - V_2 -> V_12 . V_14 ;
V_4 . V_6 = false ;
if ( V_11 > 15 ) {
V_4 . V_7 = V_15 ;
} else {
V_4 . V_7 = ( int ) ( V_11 * 1000000 +
V_2 -> V_13 . V_16 -
V_2 -> V_12 . V_16 ) ;
V_4 . V_7 -= V_2 -> V_17 ;
V_4 . V_7 = F_7 ( V_4 . V_7 ) ;
V_4 . V_7 &= V_15 ;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_10 = false ;
V_2 -> V_17 = 0 ;
}
V_4 . V_6 = true ;
V_4 . V_7 = ( ( int ) V_9 ) * V_18 ;
V_4 . V_7 += V_18 / 2 ;
V_2 -> V_17 += V_4 . V_7 ;
V_4 . V_7 = F_7 ( V_4 . V_7 ) ;
V_4 . V_7 &= V_15 ;
F_1 ( V_2 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char V_9 )
{
F_4 ( V_2 , ( V_9 & V_19 ) >> 4 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned char V_9 )
{
F_5 ( V_4 ) ;
V_4 . V_6 = false ;
V_4 . V_7 = ( ( int ) V_9 ) * V_18 ;
V_4 . V_7 += V_18 / 2 ;
V_2 -> V_17 += V_4 . V_7 ;
V_4 . V_7 = F_7 ( V_4 . V_7 ) ;
F_1 ( V_2 , V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
F_9 ( V_2 , V_9 & V_20 ) ;
}
static void F_11 ( struct V_21 * V_21 )
{
struct V_1 * V_2 ;
unsigned int V_22 ;
int V_23 ;
if ( ! V_21 )
return;
V_2 = V_21 -> V_24 ;
V_23 = V_21 -> V_25 ;
switch ( V_21 -> V_26 ) {
case - V_27 :
case - V_28 :
case - V_29 :
F_12 ( V_2 -> V_5 , L_4 , V_21 -> V_26 ) ;
return;
default:
break;
}
F_2 ( V_2 -> V_5 , L_5 , V_30 , V_23 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
F_2 ( V_2 -> V_5 , L_6 ,
V_22 , ( unsigned char ) V_2 -> V_31 [ V_22 ] ) ;
switch ( V_2 -> V_32 ) {
case V_33 :
if ( ( V_2 -> V_31 [ V_22 ] & V_19 ) ==
V_19 ) {
V_2 -> V_32 = V_34 ;
continue;
} else if ( ( V_2 -> V_31 [ V_22 ] & V_20 )
== V_20 ) {
F_8 ( V_2 , V_2 -> V_31 [ V_22 ] ) ;
V_2 -> V_32 = V_35 ;
continue;
} else {
F_8 ( V_2 , V_2 -> V_31 [ V_22 ] ) ;
F_10 ( V_2 , V_2 -> V_31 [ V_22 ] ) ;
}
break;
case V_34 :
F_4 ( V_2 , V_2 -> V_31 [ V_22 ] ) ;
V_2 -> V_32 = V_36 ;
break;
case V_35 :
if ( V_2 -> V_31 [ V_22 ] == V_37 ) {
F_5 ( V_4 ) ;
V_4 . V_6 = false ;
V_4 . V_7 = V_2 -> V_8 -> V_38 ;
V_2 -> V_10 = true ;
if ( V_2 -> V_39 )
F_1 ( V_2 , V_4 ) ;
F_13 ( V_2 -> V_8 ) ;
F_14 ( V_2 -> V_8 ) ;
} else {
F_9 ( V_2 , V_2 -> V_31 [ V_22 ] ) ;
}
V_2 -> V_32 = V_33 ;
break;
case V_36 :
if ( ( V_2 -> V_31 [ V_22 ] & V_20 ) ==
V_20 ) {
V_2 -> V_32 = V_35 ;
continue;
}
F_10 ( V_2 , V_2 -> V_31 [ V_22 ] ) ;
V_2 -> V_32 = V_33 ;
break;
}
}
F_13 ( V_2 -> V_8 ) ;
F_15 ( V_21 , V_40 ) ;
return;
}
static struct V_41 * F_16 ( struct V_1 * V_2 )
{
struct V_41 * V_8 ;
struct V_42 * V_5 = V_2 -> V_5 ;
int V_43 ;
V_8 = F_17 () ;
if ( ! V_8 ) {
F_12 ( V_5 , L_7 ) ;
goto V_44;
}
snprintf ( V_2 -> V_45 , sizeof( V_2 -> V_45 ) , L_8
L_9 ,
F_18 ( V_2 -> V_46 -> V_47 . V_48 ) ,
F_18 ( V_2 -> V_46 -> V_47 . V_49 ) ) ;
F_19 ( V_2 -> V_46 , V_2 -> V_50 , sizeof( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , L_10 , sizeof( V_2 -> V_50 ) ) ;
V_8 -> V_51 = V_2 -> V_45 ;
V_8 -> V_52 = V_2 -> V_50 ;
F_21 ( V_2 -> V_46 , & V_8 -> V_53 ) ;
V_8 -> V_5 . V_54 = V_5 ;
V_8 -> V_55 = V_2 ;
V_8 -> V_56 = V_57 ;
V_8 -> V_58 = V_59 ;
V_8 -> V_60 = V_61 ;
V_8 -> V_62 = V_63 ;
V_43 = F_22 ( V_8 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 , L_11 ) ;
goto V_44;
}
return V_8 ;
V_44:
F_23 ( V_8 ) ;
return NULL ;
}
static int T_1 F_24 ( struct V_64 * V_65 ,
const struct V_66 * V_67 )
{
struct V_68 * V_46 = F_25 ( V_65 ) ;
struct V_69 * V_70 ;
struct V_1 * V_2 = NULL ;
char V_71 [ 63 ] , V_45 [ 128 ] = L_12 ;
int V_72 = - V_73 ;
int V_74 , V_75 ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_77 = V_65 ;
V_70 = V_65 -> V_78 ;
if ( V_70 -> V_79 . V_80 != 1 ) {
F_12 ( & V_65 -> V_5 , L_13 ,
V_30 , V_70 -> V_79 . V_80 ) ;
V_72 = - V_81 ;
goto V_82;
}
V_2 -> V_83 = & ( V_70 -> V_83 [ 0 ] . V_79 ) ;
if ( ( V_2 -> V_83 -> V_84 & V_85 )
!= V_86 ) {
F_12 ( & V_65 -> V_5 , L_14
L_15 , V_30 , V_2 -> V_83 -> V_84 ) ;
V_72 = - V_81 ;
goto V_82;
}
if ( ( V_2 -> V_83 -> V_87 & V_88 )
!= V_89 ) {
F_12 ( & V_65 -> V_5 , L_16
L_15 , V_30 , V_2 -> V_83 -> V_87 ) ;
V_72 = - V_81 ;
goto V_82;
}
V_74 = F_27 ( V_46 , V_2 -> V_83 -> V_84 ) ;
V_75 = F_28 ( V_46 , V_74 , F_29 ( V_74 ) ) ;
if ( V_75 == 0 ) {
F_12 ( & V_65 -> V_5 , L_17 ,
V_30 ) ;
V_72 = - V_81 ;
goto V_82;
}
V_2 -> V_31 = F_30 ( V_46 , V_75 , V_40 , & V_2 -> V_90 ) ;
if ( ! V_2 -> V_31 )
goto V_82;
V_2 -> V_91 = F_31 ( 0 , V_76 ) ;
if ( ! V_2 -> V_91 )
goto V_92;
V_2 -> V_5 = & V_65 -> V_5 ;
V_2 -> V_93 = V_75 ;
if ( V_46 -> V_47 . V_94
&& F_32 ( V_46 , V_46 -> V_47 . V_94 ,
V_71 , sizeof( V_71 ) ) > 0 )
F_33 ( V_45 , V_71 , sizeof( V_45 ) ) ;
if ( V_46 -> V_47 . V_95
&& F_32 ( V_46 , V_46 -> V_47 . V_95 ,
V_71 , sizeof( V_71 ) ) > 0 )
snprintf ( V_45 + strlen ( V_45 ) , sizeof( V_45 ) - strlen ( V_45 ) ,
L_18 , V_71 ) ;
V_2 -> V_8 = F_16 ( V_2 ) ;
if ( ! V_2 -> V_8 )
goto V_96;
V_2 -> V_10 = true ;
V_2 -> V_32 = V_33 ;
V_2 -> V_39 = true ;
V_2 -> V_8 -> V_38 = ( ( F_7 ( V_37 * V_18 ) &
V_15 ) | 0x03000000 ) ;
#if 0
sz->min_timeout = US_TO_NS(SZ_TIMEOUT * SZ_RESOLUTION);
sz->max_timeout = US_TO_NS(SZ_TIMEOUT * SZ_RESOLUTION);
#endif
F_6 ( & V_2 -> V_13 ) ;
F_34 ( V_2 -> V_91 , V_46 , V_74 , V_2 -> V_31 ,
V_75 , ( V_97 ) F_11 ,
V_2 , V_2 -> V_83 -> V_98 ) ;
V_2 -> V_91 -> V_99 = V_2 -> V_90 ;
V_2 -> V_91 -> V_100 |= V_101 ;
F_35 ( V_65 , V_2 ) ;
if ( F_15 ( V_2 -> V_91 , V_40 ) )
F_12 ( V_2 -> V_5 , L_19 ) ;
F_36 ( V_2 -> V_5 , L_20 , V_45 ,
V_46 -> V_102 -> V_103 , V_46 -> V_104 ) ;
F_37 () ;
return 0 ;
V_96:
F_38 ( V_2 -> V_91 ) ;
V_92:
F_39 ( V_46 , V_75 , V_2 -> V_31 , V_2 -> V_90 ) ;
V_82:
F_40 ( V_2 ) ;
return V_72 ;
}
static void F_41 ( struct V_64 * V_77 )
{
struct V_1 * V_2 = F_42 ( V_77 ) ;
struct V_68 * V_46 = F_25 ( V_77 ) ;
F_35 ( V_77 , NULL ) ;
if ( ! V_2 )
return;
V_2 -> V_46 = NULL ;
F_43 ( V_2 -> V_8 ) ;
F_44 ( V_2 -> V_91 ) ;
F_38 ( V_2 -> V_91 ) ;
F_39 ( V_46 , V_2 -> V_93 , V_2 -> V_31 , V_2 -> V_90 ) ;
F_40 ( V_2 ) ;
}
static int F_45 ( struct V_64 * V_65 , T_2 V_105 )
{
struct V_1 * V_2 = F_42 ( V_65 ) ;
F_44 ( V_2 -> V_91 ) ;
return 0 ;
}
static int F_46 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_42 ( V_65 ) ;
if ( F_15 ( V_2 -> V_91 , V_40 ) ) {
F_12 ( V_2 -> V_5 , L_21 ) ;
return - V_106 ;
}
return 0 ;
}
static int T_3 F_47 ( void )
{
int V_43 ;
V_43 = F_48 ( & V_107 ) ;
if ( V_43 < 0 )
F_49 (KERN_ERR DRIVER_NAME L_22
L_23 , ret) ;
return V_43 ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_107 ) ;
}
