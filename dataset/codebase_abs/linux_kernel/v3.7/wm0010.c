static const char * F_1 ( enum V_1 V_2 )
{
const char * V_3 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5
} ;
if ( V_2 < 0 || V_2 >= F_2 ( V_3 ) )
return L_6 ;
return V_3 [ V_2 ] ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
unsigned long V_8 ;
enum V_1 V_2 ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_2 = V_7 -> V_2 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
switch ( V_2 ) {
case V_10 :
return;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
F_7 ( V_7 -> V_15 ,
V_7 -> V_16 ) ;
F_8 ( V_7 -> V_17 ) ;
F_9 ( F_2 ( V_7 -> V_18 ) ,
V_7 -> V_18 ) ;
break;
}
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_10 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
enum V_1 V_2 ;
unsigned long V_8 ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_2 = V_7 -> V_2 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_11 ( V_7 -> V_19 , L_7 ,
F_1 ( V_2 ) , F_1 ( V_2 + 1 ) ) ;
V_7 -> V_20 = true ;
}
static void F_12 ( void * V_21 )
{
struct V_22 * V_23 = V_21 ;
struct V_4 * V_5 = V_23 -> V_5 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
T_1 * V_24 = V_23 -> V_25 . V_26 ;
int V_27 ;
if ( V_23 -> V_28 . V_29 != 0 ) {
F_11 ( V_5 -> V_19 , L_8 ,
V_23 -> V_28 . V_29 ) ;
F_10 ( V_7 ) ;
if ( V_23 -> V_30 )
F_13 ( V_23 -> V_30 ) ;
return;
}
for ( V_27 = 0 ; V_27 < V_23 -> V_25 . V_31 / 4 ; V_27 ++ ) {
F_14 ( V_5 -> V_19 , L_9 , V_27 , V_24 [ V_27 ] ) ;
switch ( F_15 ( V_24 [ V_27 ] ) ) {
case 0xe0e0e0e0 :
F_11 ( V_5 -> V_19 ,
L_10 , V_27 ) ;
F_10 ( V_7 ) ;
break;
case 0x55555555 :
if ( V_7 -> V_32 == 0 )
break;
F_11 ( V_5 -> V_19 ,
L_11 , V_27 ) ;
F_10 ( V_7 ) ;
break;
case 0x0fed0000 :
F_14 ( V_5 -> V_19 , L_12 ) ;
break;
case 0x0fed0007 :
F_14 ( V_5 -> V_19 , L_13 ) ;
break;
case 0x0fed0008 :
F_14 ( V_5 -> V_19 , L_14 ) ;
break;
case 0x0fed0009 :
F_14 ( V_5 -> V_19 , L_15 ) ;
break;
case 0x0fed000c :
F_14 ( V_5 -> V_19 , L_16 ) ;
break;
case 0x0fed000e :
F_14 ( V_5 -> V_19 , L_17 ) ;
V_7 -> V_33 = true ;
break;
case 0x0fed0025 :
F_11 ( V_5 -> V_19 , L_18 ) ;
F_10 ( V_7 ) ;
break;
case 0x0fed002c :
F_11 ( V_5 -> V_19 , L_19 ) ;
F_10 ( V_7 ) ;
break;
case 0x0fed0031 :
F_11 ( V_5 -> V_19 , L_20 ) ;
F_10 ( V_7 ) ;
break;
case 0x0fed0032 :
F_11 ( V_5 -> V_19 , L_21 ) ;
F_10 ( V_7 ) ;
break;
case 0x0fed0033 :
F_11 ( V_5 -> V_19 , L_22 ) ;
F_10 ( V_7 ) ;
break;
case 0x0fed0034 :
F_11 ( V_5 -> V_19 , L_23 ) ;
F_10 ( V_7 ) ;
break;
case 0x0fed0035 :
F_11 ( V_5 -> V_19 , L_24 ) ;
F_10 ( V_7 ) ;
break;
case 0x0fed0038 :
F_11 ( V_5 -> V_19 , L_25 ) ;
break;
case 0x0fed003a :
F_11 ( V_5 -> V_19 , L_26 ) ;
F_10 ( V_7 ) ;
break;
default:
F_11 ( V_5 -> V_19 , L_27 ,
F_15 ( V_24 [ V_27 ] ) ) ;
F_10 ( V_7 ) ;
break;
}
if ( V_7 -> V_20 )
break;
}
V_7 -> V_32 ++ ;
if ( V_23 -> V_30 )
F_13 ( V_23 -> V_30 ) ;
}
static void F_16 ( T_2 * V_34 , T_2 * V_35 , T_1 V_31 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_31 / 8 ; V_27 ++ )
V_35 [ V_27 ] = F_17 ( F_18 ( V_34 [ V_27 ] ) ) ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_36 * V_37 = F_20 ( V_5 -> V_19 ) ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
unsigned long V_8 ;
struct V_38 V_39 ;
struct V_22 * V_23 ;
int V_40 ;
struct V_41 V_30 ;
const struct V_42 * V_43 ;
const struct V_44 * V_45 ;
struct V_46 V_28 ;
struct V_47 V_25 ;
struct V_48 V_49 ;
T_1 * V_50 , * V_51 ;
T_2 * V_52 ;
T_3 * V_53 ;
T_1 V_31 , V_54 ;
int V_27 ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
if ( V_7 -> V_2 != V_10 )
F_21 ( V_7 -> V_19 , L_28 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
if ( V_7 -> V_55 > 26000000 ) {
F_11 ( V_5 -> V_19 , L_29 ) ;
V_40 = - V_56 ;
goto V_57;
}
F_22 ( & V_39 ) ;
F_23 ( & V_7 -> V_58 ) ;
V_7 -> V_33 = false ;
F_14 ( V_5 -> V_19 , L_30 , V_7 -> V_59 ) ;
V_40 = F_24 ( F_2 ( V_7 -> V_18 ) ,
V_7 -> V_18 ) ;
if ( V_40 != 0 ) {
F_11 ( & V_37 -> V_19 , L_31 ,
V_40 ) ;
F_25 ( & V_7 -> V_58 ) ;
goto V_57;
}
V_40 = F_26 ( V_7 -> V_17 ) ;
if ( V_40 != 0 ) {
F_11 ( & V_37 -> V_19 , L_32 , V_40 ) ;
goto V_60;
}
F_7 ( V_7 -> V_15 , ! V_7 -> V_16 ) ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_11 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_40 = F_27 ( & V_43 , L_33 , V_5 -> V_19 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_34 ,
V_40 ) ;
goto abort;
}
if ( ! F_28 ( & V_7 -> V_61 ,
F_29 ( 10 ) ) )
F_11 ( V_5 -> V_19 , L_35 ) ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_12 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_14 ( V_5 -> V_19 , L_36 , V_43 -> V_62 ) ;
V_50 = F_30 ( V_43 -> V_62 , V_63 ) ;
if ( ! V_50 ) {
F_11 ( V_5 -> V_19 , L_37 ) ;
goto abort;
}
V_53 = F_30 ( V_43 -> V_62 , V_63 ) ;
if ( ! V_53 ) {
F_11 ( V_5 -> V_19 , L_38 ) ;
goto abort;
}
memcpy ( V_50 , & V_43 -> V_21 [ 0 ] , V_43 -> V_62 ) ;
F_31 ( & V_28 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 = V_53 ;
V_25 . V_64 = V_50 ;
V_25 . V_31 = V_43 -> V_62 ;
V_25 . V_65 = 8 ;
V_25 . V_66 = V_7 -> V_55 / 10 ;
F_32 ( & V_25 , & V_28 ) ;
F_14 ( V_5 -> V_19 , L_39 ,
V_25 . V_66 ) ;
V_40 = F_33 ( V_37 , & V_28 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_40 , V_40 ) ;
goto abort;
}
for ( V_27 = 0 ; V_27 < V_43 -> V_62 ; V_27 ++ ) {
if ( V_53 [ V_27 ] != 0x55 ) {
V_40 = - V_67 ;
F_11 ( V_5 -> V_19 , L_41 ,
V_53 [ V_27 ] , V_27 ) ;
F_10 ( V_7 ) ;
goto abort;
}
}
F_34 ( V_43 ) ;
F_35 ( V_50 ) ;
F_35 ( V_53 ) ;
if ( ! F_28 ( & V_7 -> V_61 ,
F_29 ( 10 ) ) )
F_11 ( V_5 -> V_19 , L_42 ) ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_13 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
if ( V_7 -> V_59 ) {
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_68 = V_69 ;
V_49 . V_70 = ( sizeof( V_49 ) - 8 ) ;
V_49 . V_71 = V_7 -> V_72 ;
V_31 = V_49 . V_70 + 8 ;
V_53 = F_30 ( V_31 , V_63 ) ;
if ( ! V_53 ) {
F_11 ( V_5 -> V_19 ,
L_43 ) ;
goto abort;
}
V_52 = F_30 ( V_31 , V_63 ) ;
if ( ! V_52 ) {
F_11 ( V_5 -> V_19 ,
L_37 ) ;
goto abort;
}
F_16 ( ( T_2 * ) & V_49 , V_52 , V_31 ) ;
F_31 ( & V_28 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 = V_53 ;
V_25 . V_64 = V_52 ;
V_25 . V_31 = V_31 ;
V_25 . V_65 = 8 ;
V_25 . V_66 = V_7 -> V_55 / 6 ;
F_32 ( & V_25 , & V_28 ) ;
V_40 = F_33 ( V_37 , & V_28 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_44 , V_40 ) ;
goto abort;
}
V_40 = F_33 ( V_37 , & V_28 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_45 , V_40 ) ;
goto abort;
}
V_51 = ( T_1 * ) V_53 ;
for ( V_27 = 0 ; V_27 < V_31 / 4 ; V_27 ++ ) {
if ( * V_51 == 0x0e00ed0f ) {
F_14 ( V_5 -> V_19 , L_17 ) ;
V_7 -> V_33 = true ;
break;
}
V_51 ++ ;
}
F_35 ( V_52 ) ;
F_35 ( V_53 ) ;
} else
F_14 ( V_5 -> V_19 , L_46 ) ;
V_40 = F_27 ( & V_43 , L_47 , V_5 -> V_19 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_48 ,
V_40 ) ;
goto abort;
}
V_45 = ( const struct V_44 * ) V_43 -> V_21 ;
V_54 = 0 ;
V_7 -> V_32 = 0 ;
V_7 -> V_20 = false ;
F_36 ( ! F_37 ( & V_39 ) ) ;
F_38 ( & V_30 ) ;
if ( V_45 -> V_68 != V_73 ) {
F_11 ( V_5 -> V_19 , L_49 ) ;
goto abort;
}
if ( V_45 -> V_21 [ 0 ] != V_74 ) {
F_11 ( V_5 -> V_19 , L_50 ) ;
goto abort;
}
V_54 += ( ( V_45 -> V_70 ) + 8 ) ;
V_45 = ( void * ) & V_45 -> V_21 [ V_45 -> V_70 ] ;
while ( V_54 < V_43 -> V_62 ) {
F_14 ( V_5 -> V_19 ,
L_51 ,
V_45 -> V_68 , V_45 -> V_70 ) ;
V_31 = V_45 -> V_70 + 8 ;
V_53 = F_30 ( V_31 , V_63 ) ;
if ( ! V_53 ) {
F_11 ( V_5 -> V_19 ,
L_43 ) ;
goto abort;
}
V_52 = F_30 ( V_31 , V_63 ) ;
if ( ! V_52 ) {
F_11 ( V_5 -> V_19 ,
L_37 ) ;
goto abort;
}
F_16 ( ( T_2 * ) & V_45 -> V_68 , V_52 , V_31 ) ;
V_23 = F_30 ( sizeof( * V_23 ) , V_63 ) ;
if ( ! V_23 ) {
F_11 ( V_5 -> V_19 , L_52 ) ;
goto abort;
}
V_23 -> V_5 = V_5 ;
F_39 ( & V_23 -> V_75 , & V_39 ) ;
F_31 ( & V_23 -> V_28 ) ;
V_23 -> V_28 . F_13 = F_12 ;
V_23 -> V_28 . V_76 = V_23 ;
V_23 -> V_25 . V_64 = V_52 ;
V_23 -> V_25 . V_26 = V_53 ;
V_23 -> V_25 . V_31 = V_31 ;
V_23 -> V_25 . V_65 = 8 ;
if ( ! V_7 -> V_33 ) {
V_23 -> V_25 . V_66 = V_7 -> V_55 / 6 ;
} else {
V_23 -> V_25 . V_66 = V_7 -> V_59 ;
if ( V_7 -> V_77 &&
( V_7 -> V_77 < V_7 -> V_59 ) )
V_23 -> V_25 . V_66 = V_7 -> V_77 ;
}
V_7 -> V_59 = V_23 -> V_25 . V_66 ;
F_32 ( & V_23 -> V_25 , & V_23 -> V_28 ) ;
V_54 += ( ( V_45 -> V_70 ) + 8 ) ;
V_45 = ( void * ) & V_45 -> V_21 [ V_45 -> V_70 ] ;
if ( V_54 >= V_43 -> V_62 ) {
F_14 ( V_5 -> V_19 , L_53 ) ;
V_23 -> V_30 = & V_30 ;
}
V_40 = F_40 ( V_37 , & V_23 -> V_28 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_54 , V_40 ) ;
goto abort;
}
if ( V_7 -> V_20 )
goto abort;
}
F_41 ( & V_30 ) ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_14 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_25 ( & V_7 -> V_58 ) ;
F_34 ( V_43 ) ;
while ( ! F_37 ( & V_39 ) ) {
V_23 = F_42 ( & V_39 , struct V_22 ,
V_75 ) ;
F_35 ( V_23 -> V_25 . V_26 ) ;
F_35 ( V_23 -> V_25 . V_64 ) ;
F_43 ( & V_23 -> V_75 ) ;
F_35 ( V_23 ) ;
}
return 0 ;
abort:
F_3 ( V_5 ) ;
F_25 ( & V_7 -> V_58 ) ;
return V_40 ;
V_60:
F_25 ( & V_7 -> V_58 ) ;
F_9 ( F_2 ( V_7 -> V_18 ) ,
V_7 -> V_18 ) ;
V_57:
return V_40 ;
}
static int F_44 ( struct V_4 * V_5 ,
enum V_78 V_79 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
switch ( V_79 ) {
case V_80 :
if ( V_5 -> V_81 . V_82 == V_83 )
F_19 ( V_5 ) ;
break;
case V_83 :
break;
case V_84 :
if ( V_5 -> V_81 . V_82 == V_83 ) {
F_23 ( & V_7 -> V_58 ) ;
F_3 ( V_5 ) ;
F_25 ( & V_7 -> V_58 ) ;
}
break;
case V_85 :
break;
}
V_5 -> V_81 . V_82 = V_79 ;
return 0 ;
}
static int F_45 ( struct V_4 * V_5 , int V_86 ,
int V_87 , unsigned int V_88 , int V_89 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
unsigned int V_27 ;
V_7 -> V_55 = V_88 ;
if ( V_88 < V_90 [ F_2 ( V_90 ) - 1 ] . V_91 ) {
V_7 -> V_59 = 0 ;
} else {
for ( V_27 = 0 ; V_27 < F_2 ( V_90 ) ; V_27 ++ )
if ( V_88 >= V_90 [ V_27 ] . V_91 )
break;
V_7 -> V_59 = V_90 [ V_27 ] . V_92 ;
V_7 -> V_72 = V_90 [ V_27 ] . V_72 ;
}
return 0 ;
}
static T_4 F_46 ( int V_93 , void * V_21 )
{
struct V_6 * V_7 = V_21 ;
switch ( V_7 -> V_2 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
F_47 ( & V_7 -> V_9 ) ;
F_13 ( & V_7 -> V_61 ) ;
F_48 ( & V_7 -> V_9 ) ;
return V_94 ;
default:
return V_95 ;
}
return V_95 ;
}
static int F_49 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
return 0 ;
}
static int T_5 F_50 ( struct V_36 * V_37 )
{
unsigned long V_96 ;
int V_40 ;
int V_97 ;
int V_93 ;
struct V_6 * V_7 ;
V_7 = F_51 ( & V_37 -> V_19 , sizeof( * V_7 ) ,
V_63 ) ;
if ( ! V_7 )
return - V_98 ;
F_52 ( & V_7 -> V_58 ) ;
F_53 ( & V_7 -> V_9 ) ;
F_54 ( V_37 , V_7 ) ;
V_7 -> V_19 = & V_37 -> V_19 ;
if ( F_55 ( & V_37 -> V_19 ) )
memcpy ( & V_7 -> V_99 , F_55 ( & V_37 -> V_19 ) ,
sizeof( V_7 -> V_99 ) ) ;
F_38 ( & V_7 -> V_61 ) ;
V_7 -> V_18 [ 0 ] . V_100 = L_55 ;
V_7 -> V_18 [ 1 ] . V_100 = L_56 ;
V_40 = F_56 ( V_7 -> V_19 , F_2 ( V_7 -> V_18 ) ,
V_7 -> V_18 ) ;
if ( V_40 != 0 ) {
F_11 ( V_7 -> V_19 , L_57 ,
V_40 ) ;
return V_40 ;
}
V_7 -> V_17 = F_57 ( V_7 -> V_19 , L_58 ) ;
if ( F_58 ( V_7 -> V_17 ) ) {
V_40 = F_59 ( V_7 -> V_17 ) ;
F_11 ( V_7 -> V_19 , L_59 , V_40 ) ;
return V_40 ;
}
if ( V_7 -> V_99 . V_15 ) {
V_7 -> V_15 = V_7 -> V_99 . V_15 ;
if ( V_7 -> V_99 . V_101 )
V_7 -> V_16 = 1 ;
else
V_7 -> V_16 = 0 ;
if ( V_7 -> V_16 )
V_96 = V_102 ;
else
V_96 = V_103 ;
V_40 = F_60 ( V_7 -> V_19 , V_7 -> V_15 ,
V_96 , L_60 ) ;
if ( V_40 < 0 ) {
F_11 ( V_7 -> V_19 ,
L_61 ,
V_40 ) ;
return V_40 ;
}
} else {
F_11 ( V_7 -> V_19 , L_62 ) ;
return - V_104 ;
}
V_7 -> V_2 = V_10 ;
V_93 = V_37 -> V_93 ;
if ( V_7 -> V_99 . V_105 )
V_97 = V_7 -> V_99 . V_105 ;
else
V_97 = V_106 ;
V_97 |= V_107 ;
V_40 = F_61 ( V_93 , NULL , F_46 , V_97 | V_107 ,
L_63 , V_7 ) ;
if ( V_40 ) {
F_11 ( V_7 -> V_19 , L_64 ,
V_93 , V_40 ) ;
return V_40 ;
}
V_7 -> V_93 = V_93 ;
if ( V_37 -> V_108 )
V_7 -> V_77 = V_37 -> V_108 ;
else
V_7 -> V_77 = 0 ;
V_40 = F_62 ( & V_37 -> V_19 ,
& V_109 , V_110 ,
F_2 ( V_110 ) ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
static int T_6 F_63 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_64 ( V_37 ) ;
F_65 ( & V_37 -> V_19 ) ;
F_7 ( V_7 -> V_15 ,
V_7 -> V_16 ) ;
if ( V_7 -> V_93 )
F_66 ( V_7 -> V_93 , V_7 ) ;
return 0 ;
}
