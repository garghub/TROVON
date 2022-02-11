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
int V_11 ;
V_2 -> V_12 = V_2 -> V_13 ;
V_2 -> V_13 = F_6 () ;
V_11 = F_7 ( V_2 -> V_13 , V_2 -> V_12 ) ;
V_4 . V_6 = false ;
if ( V_11 > ( 15 * V_14 ) ) {
V_4 . V_7 = V_15 ;
} else {
V_4 . V_7 = V_11 ;
V_4 . V_7 -= V_2 -> V_16 ;
V_4 . V_7 = F_8 ( V_4 . V_7 ) ;
V_4 . V_7 = ( V_4 . V_7 > V_15 ) ?
V_15 : V_4 . V_7 ;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_10 = false ;
V_2 -> V_16 = 0 ;
}
V_4 . V_6 = true ;
V_4 . V_7 = ( ( int ) V_9 ) * V_17 ;
V_4 . V_7 += V_17 / 2 ;
V_2 -> V_16 += V_4 . V_7 ;
V_4 . V_7 = F_8 ( V_4 . V_7 ) ;
V_4 . V_7 = ( V_4 . V_7 > V_15 ) ?
V_15 : V_4 . V_7 ;
F_1 ( V_2 , V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned char V_9 )
{
F_4 ( V_2 , ( V_9 & V_18 ) >> 4 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned char V_9 )
{
F_5 ( V_4 ) ;
V_4 . V_6 = false ;
V_4 . V_7 = ( ( int ) V_9 ) * V_17 ;
V_4 . V_7 += V_17 / 2 ;
V_2 -> V_16 += V_4 . V_7 ;
V_4 . V_7 = F_8 ( V_4 . V_7 ) ;
F_1 ( V_2 , V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
F_10 ( V_2 , V_9 & V_19 ) ;
}
static void F_12 ( struct V_20 * V_20 )
{
struct V_1 * V_2 ;
unsigned int V_21 ;
int V_22 ;
if ( ! V_20 )
return;
V_2 = V_20 -> V_23 ;
V_22 = V_20 -> V_24 ;
switch ( V_20 -> V_25 ) {
case - V_26 :
case - V_27 :
case - V_28 :
F_13 ( V_2 -> V_5 , L_4 , V_20 -> V_25 ) ;
return;
default:
break;
}
F_2 ( V_2 -> V_5 , L_5 , V_29 , V_22 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
F_2 ( V_2 -> V_5 , L_6 ,
V_21 , ( unsigned char ) V_2 -> V_30 [ V_21 ] ) ;
switch ( V_2 -> V_31 ) {
case V_32 :
if ( ( V_2 -> V_30 [ V_21 ] & V_18 ) ==
V_18 ) {
V_2 -> V_31 = V_33 ;
continue;
} else if ( ( V_2 -> V_30 [ V_21 ] & V_19 )
== V_19 ) {
F_9 ( V_2 , V_2 -> V_30 [ V_21 ] ) ;
V_2 -> V_31 = V_34 ;
continue;
} else {
F_9 ( V_2 , V_2 -> V_30 [ V_21 ] ) ;
F_11 ( V_2 , V_2 -> V_30 [ V_21 ] ) ;
}
break;
case V_33 :
F_4 ( V_2 , V_2 -> V_30 [ V_21 ] ) ;
V_2 -> V_31 = V_35 ;
break;
case V_34 :
if ( V_2 -> V_30 [ V_21 ] == V_36 ) {
F_5 ( V_4 ) ;
V_4 . V_6 = false ;
V_4 . V_7 = V_2 -> V_8 -> V_37 ;
V_2 -> V_10 = true ;
if ( V_2 -> V_38 )
F_1 ( V_2 , V_4 ) ;
F_14 ( V_2 -> V_8 ) ;
F_15 ( V_2 -> V_8 ) ;
} else {
F_10 ( V_2 , V_2 -> V_30 [ V_21 ] ) ;
}
V_2 -> V_31 = V_32 ;
break;
case V_35 :
if ( ( V_2 -> V_30 [ V_21 ] & V_19 ) ==
V_19 ) {
V_2 -> V_31 = V_34 ;
continue;
}
F_11 ( V_2 , V_2 -> V_30 [ V_21 ] ) ;
V_2 -> V_31 = V_32 ;
break;
}
}
F_14 ( V_2 -> V_8 ) ;
F_16 ( V_20 , V_39 ) ;
return;
}
static struct V_40 * F_17 ( struct V_1 * V_2 )
{
struct V_40 * V_8 ;
struct V_41 * V_5 = V_2 -> V_5 ;
int V_42 ;
V_8 = F_18 () ;
if ( ! V_8 ) {
F_13 ( V_5 , L_7 ) ;
goto V_43;
}
snprintf ( V_2 -> V_44 , sizeof( V_2 -> V_44 ) , L_8 ,
F_19 ( V_2 -> V_45 -> V_46 . V_47 ) ,
F_19 ( V_2 -> V_45 -> V_46 . V_48 ) ) ;
F_20 ( V_2 -> V_45 , V_2 -> V_49 , sizeof( V_2 -> V_49 ) ) ;
F_21 ( V_2 -> V_49 , L_9 , sizeof( V_2 -> V_49 ) ) ;
V_8 -> V_50 = V_2 -> V_44 ;
V_8 -> V_51 = V_2 -> V_49 ;
F_22 ( V_2 -> V_45 , & V_8 -> V_52 ) ;
V_8 -> V_5 . V_53 = V_5 ;
V_8 -> V_54 = V_2 ;
V_8 -> V_55 = V_56 ;
V_8 -> V_57 = V_58 ;
V_8 -> V_59 = V_60 ;
V_8 -> V_61 = V_62 ;
V_42 = F_23 ( V_8 ) ;
if ( V_42 < 0 ) {
F_13 ( V_5 , L_10 ) ;
goto V_43;
}
return V_8 ;
V_43:
F_24 ( V_8 ) ;
return NULL ;
}
static int F_25 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
struct V_67 * V_45 = F_26 ( V_64 ) ;
struct V_68 * V_69 ;
struct V_1 * V_2 = NULL ;
char V_70 [ 63 ] , V_44 [ 128 ] = L_11 ;
int V_71 = - V_72 ;
int V_73 , V_74 ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_76 = V_64 ;
V_69 = V_64 -> V_77 ;
if ( V_69 -> V_78 . V_79 != 1 ) {
F_13 ( & V_64 -> V_5 , L_12 ,
V_29 , V_69 -> V_78 . V_79 ) ;
V_71 = - V_80 ;
goto V_81;
}
V_2 -> V_82 = & ( V_69 -> V_82 [ 0 ] . V_78 ) ;
if ( ! F_28 ( V_2 -> V_82 ) ) {
F_13 ( & V_64 -> V_5 , L_13 ,
V_29 , V_2 -> V_82 -> V_83 ) ;
V_71 = - V_80 ;
goto V_81;
}
if ( ! F_29 ( V_2 -> V_82 ) ) {
F_13 ( & V_64 -> V_5 , L_14 ,
V_29 , V_2 -> V_82 -> V_84 ) ;
V_71 = - V_80 ;
goto V_81;
}
V_73 = F_30 ( V_45 , V_2 -> V_82 -> V_83 ) ;
V_74 = F_31 ( V_45 , V_73 , F_32 ( V_73 ) ) ;
if ( V_74 == 0 ) {
F_13 ( & V_64 -> V_5 , L_15 ,
V_29 ) ;
V_71 = - V_80 ;
goto V_81;
}
V_2 -> V_30 = F_33 ( V_45 , V_74 , V_39 , & V_2 -> V_85 ) ;
if ( ! V_2 -> V_30 )
goto V_81;
V_2 -> V_86 = F_34 ( 0 , V_75 ) ;
if ( ! V_2 -> V_86 )
goto V_87;
V_2 -> V_5 = & V_64 -> V_5 ;
V_2 -> V_88 = V_74 ;
if ( V_45 -> V_46 . V_89
&& F_35 ( V_45 , V_45 -> V_46 . V_89 ,
V_70 , sizeof( V_70 ) ) > 0 )
F_36 ( V_44 , V_70 , sizeof( V_44 ) ) ;
if ( V_45 -> V_46 . V_90
&& F_35 ( V_45 , V_45 -> V_46 . V_90 ,
V_70 , sizeof( V_70 ) ) > 0 )
snprintf ( V_44 + strlen ( V_44 ) , sizeof( V_44 ) - strlen ( V_44 ) ,
L_16 , V_70 ) ;
V_2 -> V_8 = F_17 ( V_2 ) ;
if ( ! V_2 -> V_8 )
goto V_91;
V_2 -> V_10 = true ;
V_2 -> V_31 = V_32 ;
V_2 -> V_38 = true ;
V_2 -> V_8 -> V_37 = ( ( F_8 ( V_36 * V_17 ) &
V_15 ) | 0x03000000 ) ;
#if 0
sz->min_timeout = US_TO_NS(SZ_TIMEOUT * SZ_RESOLUTION);
sz->max_timeout = US_TO_NS(SZ_TIMEOUT * SZ_RESOLUTION);
#endif
V_2 -> V_13 = F_6 () ;
F_37 ( V_2 -> V_86 , V_45 , V_73 , V_2 -> V_30 ,
V_74 , ( V_92 ) F_12 ,
V_2 , V_2 -> V_82 -> V_93 ) ;
V_2 -> V_86 -> V_94 = V_2 -> V_85 ;
V_2 -> V_86 -> V_95 |= V_96 ;
F_38 ( V_64 , V_2 ) ;
if ( F_16 ( V_2 -> V_86 , V_39 ) )
F_13 ( V_2 -> V_5 , L_17 ) ;
F_39 ( V_2 -> V_5 , L_18 , V_44 ,
V_45 -> V_97 -> V_98 , V_45 -> V_99 ) ;
return 0 ;
V_91:
F_40 ( V_2 -> V_86 ) ;
V_87:
F_41 ( V_45 , V_74 , V_2 -> V_30 , V_2 -> V_85 ) ;
V_81:
F_42 ( V_2 ) ;
return V_71 ;
}
static void F_43 ( struct V_63 * V_76 )
{
struct V_1 * V_2 = F_44 ( V_76 ) ;
struct V_67 * V_45 = F_26 ( V_76 ) ;
F_38 ( V_76 , NULL ) ;
if ( ! V_2 )
return;
V_2 -> V_45 = NULL ;
F_45 ( V_2 -> V_8 ) ;
F_46 ( V_2 -> V_86 ) ;
F_40 ( V_2 -> V_86 ) ;
F_41 ( V_45 , V_2 -> V_88 , V_2 -> V_30 , V_2 -> V_85 ) ;
F_42 ( V_2 ) ;
}
static int F_47 ( struct V_63 * V_64 , T_1 V_100 )
{
struct V_1 * V_2 = F_44 ( V_64 ) ;
F_46 ( V_2 -> V_86 ) ;
return 0 ;
}
static int F_48 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_44 ( V_64 ) ;
if ( F_16 ( V_2 -> V_86 , V_39 ) ) {
F_13 ( V_2 -> V_5 , L_19 ) ;
return - V_101 ;
}
return 0 ;
}
