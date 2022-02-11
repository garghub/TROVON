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
if ( V_7 -> V_2 < V_13 )
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
V_7 -> V_32 = true ;
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
if ( V_23 -> V_30 )
F_13 ( V_23 -> V_30 ) ;
}
static void F_16 ( T_2 * V_33 , T_2 * V_34 , T_1 V_31 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_31 / 8 ; V_27 ++ )
V_34 [ V_27 ] = F_17 ( F_18 ( V_33 [ V_27 ] ) ) ;
}
static int F_19 ( const char * V_35 , struct V_4 * V_5 )
{
struct V_36 * V_37 = F_20 ( V_5 -> V_19 ) ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_38 V_39 ;
struct V_22 * V_23 ;
int V_40 ;
struct V_41 V_30 ;
const struct V_42 * V_43 ;
const struct V_44 * V_45 ;
const struct V_46 * V_47 ;
T_2 * V_48 ;
T_3 * V_49 , V_50 ;
T_1 V_31 , V_51 ;
F_21 ( & V_39 ) ;
V_40 = F_22 ( & V_43 , V_35 , V_5 -> V_19 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_28 ,
V_35 , V_40 ) ;
return V_40 ;
}
V_45 = ( const struct V_44 * ) V_43 -> V_21 ;
V_47 = ( const struct V_46 * ) V_45 -> V_21 ;
V_51 = 0 ;
V_50 = V_47 -> V_52 ;
V_7 -> V_20 = false ;
F_23 ( ! F_24 ( & V_39 ) ) ;
F_25 ( & V_30 ) ;
if ( V_45 -> V_53 != V_54 ) {
F_11 ( V_5 -> V_19 , L_29 ) ;
V_40 = - V_55 ;
goto abort;
}
if ( V_47 -> V_56 != V_57 ) {
F_11 ( V_5 -> V_19 ,
L_30 ,
V_47 -> V_56 ) ;
V_40 = - V_55 ;
goto abort;
}
F_14 ( V_5 -> V_19 , L_31 ,
V_47 -> V_56 ) ;
if ( V_50 != V_58 ) {
F_11 ( V_5 -> V_19 , L_32 ) ;
V_40 = - V_55 ;
goto abort;
}
V_51 += ( ( V_45 -> V_59 ) + 8 ) ;
V_45 = ( void * ) & V_45 -> V_21 [ V_45 -> V_59 ] ;
while ( V_51 < V_43 -> V_60 ) {
F_14 ( V_5 -> V_19 ,
L_33 ,
V_45 -> V_53 , V_45 -> V_59 ) ;
V_31 = V_45 -> V_59 + 8 ;
V_23 = F_26 ( sizeof( * V_23 ) , V_61 ) ;
if ( ! V_23 ) {
F_11 ( V_5 -> V_19 , L_34 ) ;
V_40 = - V_62 ;
goto abort;
}
V_23 -> V_5 = V_5 ;
F_27 ( & V_23 -> V_63 , & V_39 ) ;
V_49 = F_26 ( V_31 , V_61 | V_64 ) ;
if ( ! V_49 ) {
F_11 ( V_5 -> V_19 ,
L_35 ) ;
V_40 = - V_62 ;
goto V_65;
}
V_23 -> V_25 . V_26 = V_49 ;
V_48 = F_26 ( V_31 , V_61 | V_64 ) ;
if ( ! V_48 ) {
F_11 ( V_5 -> V_19 ,
L_36 ) ;
V_40 = - V_62 ;
goto V_65;
}
V_23 -> V_25 . V_66 = V_48 ;
F_16 ( ( T_2 * ) & V_45 -> V_53 , V_48 , V_31 ) ;
F_28 ( & V_23 -> V_28 ) ;
V_23 -> V_28 . F_13 = F_12 ;
V_23 -> V_28 . V_67 = V_23 ;
V_23 -> V_25 . V_31 = V_31 ;
V_23 -> V_25 . V_68 = 8 ;
if ( ! V_7 -> V_32 ) {
V_23 -> V_25 . V_69 = V_7 -> V_70 / 6 ;
} else {
V_23 -> V_25 . V_69 = V_7 -> V_71 ;
if ( V_7 -> V_72 &&
( V_7 -> V_72 < V_7 -> V_71 ) )
V_23 -> V_25 . V_69 = V_7 -> V_72 ;
}
V_7 -> V_71 = V_23 -> V_25 . V_69 ;
F_29 ( & V_23 -> V_25 , & V_23 -> V_28 ) ;
V_51 += ( ( V_45 -> V_59 ) + 8 ) ;
V_45 = ( void * ) & V_45 -> V_21 [ V_45 -> V_59 ] ;
if ( V_51 >= V_43 -> V_60 ) {
F_14 ( V_5 -> V_19 , L_37 ) ;
V_23 -> V_30 = & V_30 ;
}
V_40 = F_30 ( V_37 , & V_23 -> V_28 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_38 , V_40 ) ;
goto V_65;
}
if ( V_7 -> V_20 ) {
F_14 ( V_5 -> V_19 , L_39 ) ;
V_40 = - V_55 ;
goto V_65;
}
}
F_31 ( & V_30 ) ;
V_40 = 0 ;
V_65:
while ( ! F_24 ( & V_39 ) ) {
V_23 = F_32 ( & V_39 , struct V_22 ,
V_63 ) ;
F_33 ( V_23 -> V_25 . V_26 ) ;
F_33 ( V_23 -> V_25 . V_66 ) ;
F_34 ( & V_23 -> V_63 ) ;
F_33 ( V_23 ) ;
}
abort:
F_35 ( V_43 ) ;
return V_40 ;
}
static int F_36 ( struct V_4 * V_5 )
{
struct V_36 * V_37 = F_20 ( V_5 -> V_19 ) ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
const struct V_42 * V_43 ;
struct V_73 V_28 ;
struct V_74 V_25 ;
T_1 * V_48 ;
T_3 * V_49 ;
int V_27 ;
int V_40 = 0 ;
V_40 = F_22 ( & V_43 , L_40 , V_5 -> V_19 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_41 ,
V_40 ) ;
return V_40 ;
}
F_14 ( V_5 -> V_19 , L_42 , V_43 -> V_60 ) ;
V_48 = F_26 ( V_43 -> V_60 , V_61 | V_64 ) ;
if ( ! V_48 ) {
F_11 ( V_5 -> V_19 , L_36 ) ;
V_40 = - V_62 ;
goto V_75;
}
V_49 = F_26 ( V_43 -> V_60 , V_61 | V_64 ) ;
if ( ! V_49 ) {
F_11 ( V_5 -> V_19 , L_43 ) ;
V_40 = - V_62 ;
goto V_65;
}
memcpy ( V_48 , & V_43 -> V_21 [ 0 ] , V_43 -> V_60 ) ;
F_28 ( & V_28 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 = V_49 ;
V_25 . V_66 = V_48 ;
V_25 . V_31 = V_43 -> V_60 ;
V_25 . V_68 = 8 ;
V_25 . V_69 = V_7 -> V_70 / 10 ;
F_29 ( & V_25 , & V_28 ) ;
F_14 ( V_5 -> V_19 , L_44 ,
V_25 . V_69 ) ;
V_40 = F_37 ( V_37 , & V_28 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_45 , V_40 ) ;
goto abort;
}
for ( V_27 = 0 ; V_27 < V_43 -> V_60 ; V_27 ++ ) {
if ( V_49 [ V_27 ] != 0x55 ) {
F_11 ( V_5 -> V_19 , L_46 ,
V_49 [ V_27 ] , V_27 ) ;
F_10 ( V_7 ) ;
V_40 = - V_76 ;
goto abort;
}
}
abort:
F_33 ( V_49 ) ;
V_65:
F_33 ( V_48 ) ;
V_75:
F_35 ( V_43 ) ;
return V_40 ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_36 * V_37 = F_20 ( V_5 -> V_19 ) ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
unsigned long V_8 ;
int V_40 ;
const struct V_42 * V_43 ;
struct V_73 V_28 ;
struct V_74 V_25 ;
struct V_77 V_78 ;
T_1 * V_79 , V_31 ;
T_2 * V_80 ;
T_3 * V_49 ;
int V_27 ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
if ( V_7 -> V_2 != V_10 )
F_39 ( V_7 -> V_19 , L_47 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
if ( V_7 -> V_70 > 26000000 ) {
F_11 ( V_5 -> V_19 , L_48 ) ;
V_40 = - V_81 ;
goto V_82;
}
F_40 ( & V_7 -> V_83 ) ;
V_7 -> V_32 = false ;
F_14 ( V_5 -> V_19 , L_49 , V_7 -> V_71 ) ;
V_40 = F_41 ( F_2 ( V_7 -> V_18 ) ,
V_7 -> V_18 ) ;
if ( V_40 != 0 ) {
F_11 ( & V_37 -> V_19 , L_50 ,
V_40 ) ;
F_42 ( & V_7 -> V_83 ) ;
goto V_82;
}
V_40 = F_43 ( V_7 -> V_17 ) ;
if ( V_40 != 0 ) {
F_11 ( & V_37 -> V_19 , L_51 , V_40 ) ;
goto V_84;
}
F_7 ( V_7 -> V_15 , ! V_7 -> V_16 ) ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_11 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_40 = F_22 ( & V_43 , L_40 , V_5 -> V_19 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_41 ,
V_40 ) ;
goto abort;
}
if ( ! F_44 ( & V_7 -> V_85 ,
F_45 ( 20 ) ) )
F_11 ( V_5 -> V_19 , L_52 ) ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_12 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_40 = F_36 ( V_5 ) ;
if ( V_40 )
goto abort;
if ( ! F_44 ( & V_7 -> V_85 ,
F_45 ( 20 ) ) )
F_11 ( V_5 -> V_19 , L_53 ) ;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_13 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
if ( V_7 -> V_71 ) {
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_53 = V_86 ;
V_78 . V_59 = ( sizeof( V_78 ) - 8 ) ;
V_78 . V_87 = V_7 -> V_88 ;
V_40 = - V_62 ;
V_31 = V_78 . V_59 + 8 ;
V_49 = F_26 ( V_31 , V_61 | V_64 ) ;
if ( ! V_49 ) {
F_11 ( V_5 -> V_19 ,
L_35 ) ;
goto abort;
}
V_80 = F_26 ( V_31 , V_61 | V_64 ) ;
if ( ! V_80 ) {
F_11 ( V_5 -> V_19 ,
L_36 ) ;
goto abort;
}
F_16 ( ( T_2 * ) & V_78 , V_80 , V_31 ) ;
F_28 ( & V_28 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 = V_49 ;
V_25 . V_66 = V_80 ;
V_25 . V_31 = V_31 ;
V_25 . V_68 = 8 ;
V_25 . V_69 = V_7 -> V_70 / 6 ;
F_29 ( & V_25 , & V_28 ) ;
V_40 = F_37 ( V_37 , & V_28 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_54 , V_40 ) ;
goto abort;
}
V_40 = F_37 ( V_37 , & V_28 ) ;
if ( V_40 != 0 ) {
F_11 ( V_5 -> V_19 , L_55 , V_40 ) ;
goto abort;
}
V_79 = ( T_1 * ) V_49 ;
for ( V_27 = 0 ; V_27 < V_31 / 4 ; V_27 ++ ) {
if ( * V_79 == 0x0e00ed0f ) {
F_14 ( V_5 -> V_19 , L_17 ) ;
V_7 -> V_32 = true ;
break;
}
V_79 ++ ;
}
F_33 ( V_80 ) ;
F_33 ( V_49 ) ;
} else
F_14 ( V_5 -> V_19 , L_56 ) ;
V_40 = F_19 ( L_57 , V_5 ) ;
if ( V_40 != 0 )
goto abort;
F_5 ( & V_7 -> V_9 , V_8 ) ;
V_7 -> V_2 = V_14 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_42 ( & V_7 -> V_83 ) ;
return 0 ;
abort:
F_3 ( V_5 ) ;
F_42 ( & V_7 -> V_83 ) ;
return V_40 ;
V_84:
F_42 ( & V_7 -> V_83 ) ;
F_9 ( F_2 ( V_7 -> V_18 ) ,
V_7 -> V_18 ) ;
V_82:
return V_40 ;
}
static int F_46 ( struct V_4 * V_5 ,
enum V_89 V_90 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
switch ( V_90 ) {
case V_91 :
if ( V_5 -> V_92 . V_93 == V_94 )
F_38 ( V_5 ) ;
break;
case V_94 :
break;
case V_95 :
if ( V_5 -> V_92 . V_93 == V_94 ) {
F_40 ( & V_7 -> V_83 ) ;
F_3 ( V_5 ) ;
F_42 ( & V_7 -> V_83 ) ;
}
break;
case V_96 :
break;
}
V_5 -> V_92 . V_93 = V_90 ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 , int V_97 ,
int V_98 , unsigned int V_99 , int V_100 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
unsigned int V_27 ;
V_7 -> V_70 = V_99 ;
if ( V_99 < V_101 [ F_2 ( V_101 ) - 1 ] . V_102 ) {
V_7 -> V_71 = 0 ;
} else {
for ( V_27 = 0 ; V_27 < F_2 ( V_101 ) ; V_27 ++ )
if ( V_99 >= V_101 [ V_27 ] . V_102 )
break;
V_7 -> V_71 = V_101 [ V_27 ] . V_103 ;
V_7 -> V_88 = V_101 [ V_27 ] . V_88 ;
}
return 0 ;
}
static T_4 F_48 ( int V_104 , void * V_21 )
{
struct V_6 * V_7 = V_21 ;
switch ( V_7 -> V_2 ) {
case V_11 :
case V_12 :
case V_13 :
F_49 ( & V_7 -> V_9 ) ;
F_13 ( & V_7 -> V_85 ) ;
F_50 ( & V_7 -> V_9 ) ;
return V_105 ;
default:
return V_106 ;
}
return V_106 ;
}
static int F_51 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
return 0 ;
}
static int F_52 ( struct V_36 * V_37 )
{
unsigned long V_107 ;
int V_40 ;
int V_108 ;
int V_104 ;
struct V_6 * V_7 ;
V_7 = F_53 ( & V_37 -> V_19 , sizeof( * V_7 ) ,
V_61 ) ;
if ( ! V_7 )
return - V_62 ;
F_54 ( & V_7 -> V_83 ) ;
F_55 ( & V_7 -> V_9 ) ;
F_56 ( V_37 , V_7 ) ;
V_7 -> V_19 = & V_37 -> V_19 ;
if ( F_57 ( & V_37 -> V_19 ) )
memcpy ( & V_7 -> V_109 , F_57 ( & V_37 -> V_19 ) ,
sizeof( V_7 -> V_109 ) ) ;
F_25 ( & V_7 -> V_85 ) ;
V_7 -> V_18 [ 0 ] . V_110 = L_58 ;
V_7 -> V_18 [ 1 ] . V_110 = L_59 ;
V_40 = F_58 ( V_7 -> V_19 , F_2 ( V_7 -> V_18 ) ,
V_7 -> V_18 ) ;
if ( V_40 != 0 ) {
F_11 ( V_7 -> V_19 , L_60 ,
V_40 ) ;
return V_40 ;
}
V_7 -> V_17 = F_59 ( V_7 -> V_19 , L_61 ) ;
if ( F_60 ( V_7 -> V_17 ) ) {
V_40 = F_61 ( V_7 -> V_17 ) ;
F_11 ( V_7 -> V_19 , L_62 , V_40 ) ;
return V_40 ;
}
if ( V_7 -> V_109 . V_15 ) {
V_7 -> V_15 = V_7 -> V_109 . V_15 ;
if ( V_7 -> V_109 . V_111 )
V_7 -> V_16 = 1 ;
else
V_7 -> V_16 = 0 ;
if ( V_7 -> V_16 )
V_107 = V_112 ;
else
V_107 = V_113 ;
V_40 = F_62 ( V_7 -> V_19 , V_7 -> V_15 ,
V_107 , L_63 ) ;
if ( V_40 < 0 ) {
F_11 ( V_7 -> V_19 ,
L_64 ,
V_40 ) ;
return V_40 ;
}
} else {
F_11 ( V_7 -> V_19 , L_65 ) ;
return - V_55 ;
}
V_7 -> V_2 = V_10 ;
V_104 = V_37 -> V_104 ;
if ( V_7 -> V_109 . V_114 )
V_108 = V_7 -> V_109 . V_114 ;
else
V_108 = V_115 ;
V_108 |= V_116 ;
V_40 = F_63 ( V_104 , NULL , F_48 , V_108 | V_116 ,
L_66 , V_7 ) ;
if ( V_40 ) {
F_11 ( V_7 -> V_19 , L_67 ,
V_104 , V_40 ) ;
return V_40 ;
}
V_7 -> V_104 = V_104 ;
V_40 = F_64 ( V_104 , 1 ) ;
if ( V_40 ) {
F_11 ( V_7 -> V_19 , L_68 ,
V_104 , V_40 ) ;
return V_40 ;
}
if ( V_37 -> V_117 )
V_7 -> V_72 = V_37 -> V_117 ;
else
V_7 -> V_72 = 0 ;
V_40 = F_65 ( & V_37 -> V_19 ,
& V_118 , V_119 ,
F_2 ( V_119 ) ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
static int F_66 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_67 ( V_37 ) ;
F_68 ( & V_37 -> V_19 ) ;
F_7 ( V_7 -> V_15 ,
V_7 -> V_16 ) ;
F_64 ( V_7 -> V_104 , 0 ) ;
if ( V_7 -> V_104 )
F_69 ( V_7 -> V_104 , V_7 ) ;
return 0 ;
}
