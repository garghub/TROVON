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
F_22 ( V_8 , V_58 ) ;
V_8 -> V_59 = V_60 ;
V_8 -> V_61 = V_62 ;
V_43 = F_23 ( V_8 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 , L_11 ) ;
goto V_44;
}
return V_8 ;
V_44:
F_24 ( V_8 ) ;
return NULL ;
}
static int F_25 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
struct V_67 * V_46 = F_26 ( V_64 ) ;
struct V_68 * V_69 ;
struct V_1 * V_2 = NULL ;
char V_70 [ 63 ] , V_45 [ 128 ] = L_12 ;
int V_71 = - V_72 ;
int V_73 , V_74 ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_76 = V_64 ;
V_69 = V_64 -> V_77 ;
if ( V_69 -> V_78 . V_79 != 1 ) {
F_12 ( & V_64 -> V_5 , L_13 ,
V_30 , V_69 -> V_78 . V_79 ) ;
V_71 = - V_80 ;
goto V_81;
}
V_2 -> V_82 = & ( V_69 -> V_82 [ 0 ] . V_78 ) ;
if ( ( V_2 -> V_82 -> V_83 & V_84 )
!= V_85 ) {
F_12 ( & V_64 -> V_5 , L_14
L_15 , V_30 , V_2 -> V_82 -> V_83 ) ;
V_71 = - V_80 ;
goto V_81;
}
if ( ( V_2 -> V_82 -> V_86 & V_87 )
!= V_88 ) {
F_12 ( & V_64 -> V_5 , L_16
L_15 , V_30 , V_2 -> V_82 -> V_86 ) ;
V_71 = - V_80 ;
goto V_81;
}
V_73 = F_28 ( V_46 , V_2 -> V_82 -> V_83 ) ;
V_74 = F_29 ( V_46 , V_73 , F_30 ( V_73 ) ) ;
if ( V_74 == 0 ) {
F_12 ( & V_64 -> V_5 , L_17 ,
V_30 ) ;
V_71 = - V_80 ;
goto V_81;
}
V_2 -> V_31 = F_31 ( V_46 , V_74 , V_40 , & V_2 -> V_89 ) ;
if ( ! V_2 -> V_31 )
goto V_81;
V_2 -> V_90 = F_32 ( 0 , V_75 ) ;
if ( ! V_2 -> V_90 )
goto V_91;
V_2 -> V_5 = & V_64 -> V_5 ;
V_2 -> V_92 = V_74 ;
if ( V_46 -> V_47 . V_93
&& F_33 ( V_46 , V_46 -> V_47 . V_93 ,
V_70 , sizeof( V_70 ) ) > 0 )
F_34 ( V_45 , V_70 , sizeof( V_45 ) ) ;
if ( V_46 -> V_47 . V_94
&& F_33 ( V_46 , V_46 -> V_47 . V_94 ,
V_70 , sizeof( V_70 ) ) > 0 )
snprintf ( V_45 + strlen ( V_45 ) , sizeof( V_45 ) - strlen ( V_45 ) ,
L_18 , V_70 ) ;
V_2 -> V_8 = F_16 ( V_2 ) ;
if ( ! V_2 -> V_8 )
goto V_95;
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
F_35 ( V_2 -> V_90 , V_46 , V_73 , V_2 -> V_31 ,
V_74 , ( V_96 ) F_11 ,
V_2 , V_2 -> V_82 -> V_97 ) ;
V_2 -> V_90 -> V_98 = V_2 -> V_89 ;
V_2 -> V_90 -> V_99 |= V_100 ;
F_36 ( V_64 , V_2 ) ;
if ( F_15 ( V_2 -> V_90 , V_40 ) )
F_12 ( V_2 -> V_5 , L_19 ) ;
F_37 ( V_2 -> V_5 , L_20 , V_45 ,
V_46 -> V_101 -> V_102 , V_46 -> V_103 ) ;
F_38 () ;
return 0 ;
V_95:
F_39 ( V_2 -> V_90 ) ;
V_91:
F_40 ( V_46 , V_74 , V_2 -> V_31 , V_2 -> V_89 ) ;
V_81:
F_41 ( V_2 ) ;
return V_71 ;
}
static void F_42 ( struct V_63 * V_76 )
{
struct V_1 * V_2 = F_43 ( V_76 ) ;
struct V_67 * V_46 = F_26 ( V_76 ) ;
F_36 ( V_76 , NULL ) ;
if ( ! V_2 )
return;
V_2 -> V_46 = NULL ;
F_44 ( V_2 -> V_8 ) ;
F_45 ( V_2 -> V_90 ) ;
F_39 ( V_2 -> V_90 ) ;
F_40 ( V_46 , V_2 -> V_92 , V_2 -> V_31 , V_2 -> V_89 ) ;
F_41 ( V_2 ) ;
}
static int F_46 ( struct V_63 * V_64 , T_1 V_104 )
{
struct V_1 * V_2 = F_43 ( V_64 ) ;
F_45 ( V_2 -> V_90 ) ;
return 0 ;
}
static int F_47 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_43 ( V_64 ) ;
if ( F_15 ( V_2 -> V_90 , V_40 ) ) {
F_12 ( V_2 -> V_5 , L_21 ) ;
return - V_105 ;
}
return 0 ;
}
