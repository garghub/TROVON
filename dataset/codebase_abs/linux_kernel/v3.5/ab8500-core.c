static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
int V_4 ;
V_4 = F_2 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 , 1 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_6 ,
T_2 V_3 )
{
int V_4 ;
V_4 = F_5 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 ,
& V_6 , 1 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_4 ;
T_2 V_3 ;
V_4 = F_7 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 , 1 ) ;
if ( V_4 < 0 ) {
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
return ( int ) V_3 ;
}
static int F_8 ( struct V_7 * V_5 )
{
struct V_1 * V_1 ;
if ( ! V_5 )
return - V_8 ;
V_1 = F_9 ( V_5 -> V_9 ) ;
return V_1 ? ( int ) V_1 -> V_10 : - V_8 ;
}
static int F_10 ( struct V_1 * V_1 , T_2 V_11 ,
T_2 V_12 , T_2 V_3 )
{
int V_4 ;
T_1 V_2 = ( ( T_1 ) V_11 ) << 8 | V_12 ;
F_11 ( V_1 -> V_5 , L_2 , V_2 , V_3 ) ;
F_12 ( & V_1 -> V_13 ) ;
V_4 = V_1 -> V_14 ( V_1 , V_2 , V_3 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_3 ,
V_2 , V_4 ) ;
F_13 ( & V_1 -> V_13 ) ;
return V_4 ;
}
static int F_14 ( struct V_7 * V_5 , T_2 V_11 ,
T_2 V_12 , T_2 V_15 )
{
int V_4 ;
struct V_1 * V_1 = F_9 ( V_5 -> V_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
V_4 = F_10 ( V_1 , V_11 , V_12 , V_15 ) ;
F_16 ( & V_1 -> V_16 ) ;
return V_4 ;
}
static int F_17 ( struct V_1 * V_1 , T_2 V_11 ,
T_2 V_12 , T_2 * V_15 )
{
int V_4 ;
T_1 V_2 = ( ( T_1 ) V_11 ) << 8 | V_12 ;
F_12 ( & V_1 -> V_13 ) ;
V_4 = V_1 -> V_17 ( V_1 , V_2 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_4 ,
V_2 , V_4 ) ;
else
* V_15 = V_4 ;
F_13 ( & V_1 -> V_13 ) ;
F_11 ( V_1 -> V_5 , L_5 , V_2 , V_4 ) ;
return V_4 ;
}
static int F_18 ( struct V_7 * V_5 , T_2 V_11 ,
T_2 V_12 , T_2 * V_15 )
{
int V_4 ;
struct V_1 * V_1 = F_9 ( V_5 -> V_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
V_4 = F_17 ( V_1 , V_11 , V_12 , V_15 ) ;
F_16 ( & V_1 -> V_16 ) ;
return V_4 ;
}
static int F_19 ( struct V_1 * V_1 , T_2 V_11 ,
T_2 V_12 , T_2 V_18 , T_2 V_19 )
{
int V_4 ;
T_1 V_2 = ( ( T_1 ) V_11 ) << 8 | V_12 ;
F_12 ( & V_1 -> V_13 ) ;
if ( V_1 -> V_20 == NULL ) {
T_2 V_3 ;
V_4 = V_1 -> V_17 ( V_1 , V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_1 -> V_5 , L_4 ,
V_2 , V_4 ) ;
goto V_21;
}
V_3 = ( T_2 ) V_4 ;
V_3 = ( ~ V_18 & V_3 ) | ( V_18 & V_19 ) ;
V_4 = V_1 -> V_14 ( V_1 , V_2 , V_3 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_3 ,
V_2 , V_4 ) ;
F_11 ( V_1 -> V_5 , L_6 , V_2 ,
V_3 ) ;
goto V_21;
}
V_4 = V_1 -> V_20 ( V_1 , V_2 , V_18 , V_19 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_7 , V_2 ,
V_4 ) ;
V_21:
F_13 ( & V_1 -> V_13 ) ;
return V_4 ;
}
static int F_20 ( struct V_7 * V_5 ,
T_2 V_11 , T_2 V_12 , T_2 V_18 , T_2 V_19 )
{
int V_4 ;
struct V_1 * V_1 = F_9 ( V_5 -> V_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
V_4 = F_19 ( V_1 , V_11 , V_12 ,
V_18 , V_19 ) ;
F_16 ( & V_1 -> V_16 ) ;
return V_4 ;
}
static void F_21 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
F_12 ( & V_1 -> V_23 ) ;
F_15 ( & V_1 -> V_16 ) ;
}
static void F_23 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
T_2 V_26 = V_1 -> V_27 [ V_24 ] ;
T_2 V_28 = V_1 -> V_6 [ V_24 ] ;
int V_12 ;
if ( V_28 == V_26 )
continue;
if ( V_1 -> V_29 [ V_24 ] == 11 &&
F_24 ( V_1 ) )
continue;
V_1 -> V_27 [ V_24 ] = V_28 ;
V_12 = V_30 + V_1 -> V_29 [ V_24 ] ;
F_10 ( V_1 , V_31 , V_12 , V_28 ) ;
}
F_16 ( & V_1 -> V_16 ) ;
F_13 ( & V_1 -> V_23 ) ;
}
static void F_25 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
int V_32 = V_3 -> V_33 - V_1 -> V_34 ;
int V_35 = V_32 / 8 ;
int V_6 = 1 << ( V_32 % 8 ) ;
V_1 -> V_6 [ V_35 ] |= V_6 ;
}
static void F_26 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
int V_32 = V_3 -> V_33 - V_1 -> V_34 ;
int V_35 = V_32 / 8 ;
int V_6 = 1 << ( V_32 % 8 ) ;
V_1 -> V_6 [ V_35 ] &= ~ V_6 ;
}
static int F_27 ( struct V_1 * V_1 ,
int V_36 , T_2 V_37 )
{
int V_38 = F_28 ( V_37 ) ;
int line , V_24 ;
do {
V_38 = F_28 ( V_37 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ )
if ( V_1 -> V_29 [ V_24 ] == V_36 )
break;
if ( V_24 >= V_1 -> V_25 ) {
F_3 ( V_1 -> V_5 , L_8 ,
V_36 ) ;
return - V_39 ;
}
line = ( V_24 << 3 ) + V_38 ;
V_37 &= ~ ( 1 << V_38 ) ;
F_29 ( V_1 -> V_34 + line ) ;
} while ( V_37 );
return 0 ;
}
static int F_30 ( struct V_1 * V_1 ,
int V_40 , T_2 V_41 )
{
int V_42 , V_43 ;
T_2 V_36 , V_37 ;
do {
V_42 = F_28 ( V_41 ) ;
V_36 = ( V_40 << 3 ) + V_42 ;
if ( F_31 ( V_36 == 17 ) )
V_36 = 24 ;
V_43 = F_17 ( V_1 ,
V_31 ,
V_44 + V_36 ,
& V_37 ) ;
if ( V_43 < 0 || V_37 == 0 )
goto V_45;
V_43 = F_27 ( V_1 ,
V_36 , V_37 ) ;
if ( V_43 < 0 )
return V_43 ;
V_45:
V_41 &= ~ ( 1 << V_42 ) ;
} while ( V_41 );
return 0 ;
}
static T_3 F_32 ( int V_33 , void * V_5 )
{
struct V_1 * V_1 = V_5 ;
T_2 V_24 ;
F_11 ( V_1 -> V_5 , L_9 ) ;
for ( V_24 = 0 ; V_24 < V_46 ; V_24 ++ ) {
int V_43 ;
T_2 V_41 ;
V_43 = F_17 ( V_1 , V_31 ,
V_47 + V_24 , & V_41 ) ;
if ( V_43 < 0 || V_41 == 0 )
continue;
V_43 = F_30 ( V_1 , V_24 , V_41 ) ;
if ( V_43 < 0 )
break;
}
return V_48 ;
}
static T_3 F_33 ( int V_33 , void * V_5 )
{
struct V_1 * V_1 = V_5 ;
int V_24 ;
F_11 ( V_1 -> V_5 , L_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
int V_49 = V_1 -> V_29 [ V_24 ] ;
int V_43 ;
T_2 V_15 ;
if ( V_49 == 11 && F_24 ( V_1 ) )
continue;
V_43 = F_17 ( V_1 , V_31 ,
V_44 + V_49 , & V_15 ) ;
if ( V_43 < 0 || V_15 == 0 )
continue;
do {
int V_50 = F_28 ( V_15 ) ;
int line = V_24 * 8 + V_50 ;
F_29 ( V_1 -> V_34 + line ) ;
V_15 &= ~ ( 1 << V_50 ) ;
} while ( V_15 );
}
F_16 ( & V_1 -> V_16 ) ;
return V_48 ;
}
static int F_34 ( struct V_1 * V_1 )
{
int V_51 = V_1 -> V_34 ;
int V_33 ;
int V_52 ;
if ( F_35 ( V_1 ) )
V_52 = V_53 ;
else if ( F_36 ( V_1 ) )
V_52 = V_54 ;
else
V_52 = V_55 ;
for ( V_33 = V_51 ; V_33 < V_51 + V_52 ; V_33 ++ ) {
F_37 ( V_33 , V_1 ) ;
F_38 ( V_33 , & V_56 ,
V_57 ) ;
F_39 ( V_33 , 1 ) ;
#ifdef F_40
F_41 ( V_33 , V_58 ) ;
#else
F_42 ( V_33 ) ;
#endif
}
return 0 ;
}
static void F_43 ( struct V_1 * V_1 )
{
int V_51 = V_1 -> V_34 ;
int V_33 ;
int V_52 ;
if ( F_35 ( V_1 ) )
V_52 = V_53 ;
else if ( F_36 ( V_1 ) )
V_52 = V_54 ;
else
V_52 = V_55 ;
for ( V_33 = V_51 ; V_33 < V_51 + V_52 ; V_33 ++ ) {
#ifdef F_40
F_41 ( V_33 , 0 ) ;
#endif
F_38 ( V_33 , NULL , NULL ) ;
F_37 ( V_33 , NULL ) ;
}
}
int F_44 ( struct V_1 * V_1 )
{
if ( F_45 ( & V_1 -> V_16 ) )
return - V_8 ;
else
return 0 ;
}
static T_4 F_46 ( struct V_7 * V_5 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
return sprintf ( V_61 , L_10 , V_1 ? V_1 -> V_10 : - V_8 ) ;
}
static T_4 F_47 ( struct V_7 * V_5 ,
struct V_59 * V_60 , char * V_61 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_62 ,
V_63 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_61 , L_10 , V_15 ) ;
}
static T_4 F_48 ( struct V_7 * V_5 ,
struct V_59 * V_60 , char * V_61 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_64 ,
V_65 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_61 , L_10 , V_15 ) ;
}
static T_4 F_49 ( struct V_7 * V_5 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_1 * V_1 ;
int V_4 ;
T_2 V_15 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_66 ,
V_67 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_61 , L_11 ,
( V_15 & V_68 ) ? 1 : 0 ) ;
}
static T_4 F_50 ( struct V_7 * V_5 ,
struct V_59 * V_60 , const char * V_61 , T_5 V_69 )
{
struct V_1 * V_1 ;
int V_4 = V_69 ;
int V_70 ;
T_2 V_19 ;
V_1 = F_9 ( V_5 ) ;
if ( V_69 > 0 ) {
switch ( V_61 [ 0 ] ) {
case '0' :
V_19 = 0 ;
break;
case '1' :
V_19 = V_68 ;
break;
default:
goto exit;
}
V_70 = F_19 ( V_1 ,
V_66 , V_67 ,
V_68 , V_19 ) ;
if ( V_70 )
F_51 ( V_1 -> V_5 ,
L_12 ,
V_61 [ 0 ] , V_70 ) ;
}
exit:
return V_4 ;
}
static int T_6 F_52 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_53 ( & V_72 -> V_5 ) ;
const struct V_75 * V_76 = F_54 ( V_72 ) ;
enum V_77 V_78 = V_79 ;
struct V_80 * V_81 = V_72 -> V_5 . V_82 ;
struct V_1 * V_1 ;
struct V_83 * V_83 ;
int V_4 ;
int V_24 ;
T_2 V_15 ;
V_1 = F_55 ( sizeof *V_1 , V_84 ) ;
if ( ! V_1 )
return - V_85 ;
if ( V_74 )
V_1 -> V_34 = V_74 -> V_34 ;
else if ( V_81 )
V_4 = F_56 ( V_81 , L_13 , & V_1 -> V_34 ) ;
if ( ! V_1 -> V_34 ) {
F_51 ( & V_72 -> V_5 , L_14 ) ;
V_4 = - V_8 ;
goto V_86;
}
V_1 -> V_5 = & V_72 -> V_5 ;
V_83 = F_57 ( V_72 , V_87 , 0 ) ;
if ( ! V_83 ) {
V_4 = - V_88 ;
goto V_86;
}
V_1 -> V_33 = V_83 -> V_89 ;
V_1 -> V_17 = F_6 ;
V_1 -> V_14 = F_1 ;
V_1 -> V_20 = F_4 ;
F_58 ( & V_1 -> V_13 ) ;
F_58 ( & V_1 -> V_23 ) ;
F_59 ( & V_1 -> V_16 , 0 ) ;
F_60 ( V_72 , V_1 ) ;
if ( V_76 )
V_78 = V_76 -> V_90 ;
else if ( V_81 )
V_78 = ( unsigned int )
F_61 ( V_91 , & V_72 -> V_5 ) -> V_3 ;
if ( V_78 != V_79 )
V_1 -> V_78 = V_78 ;
else {
V_4 = F_17 ( V_1 , V_92 ,
V_93 , & V_15 ) ;
if ( V_4 < 0 )
goto V_86;
V_1 -> V_78 = V_15 ;
}
V_4 = F_17 ( V_1 , V_92 ,
V_94 , & V_15 ) ;
if ( V_4 < 0 )
goto V_86;
V_1 -> V_10 = V_15 ;
F_51 ( V_1 -> V_5 , L_15 ,
V_95 [ V_1 -> V_78 ] ,
V_1 -> V_10 >> 4 ,
V_1 -> V_10 & 0x0F ) ;
if ( F_35 ( V_1 ) || F_36 ( V_1 ) ) {
V_1 -> V_25 = V_96 ;
V_1 -> V_29 = V_97 ;
} else {
V_1 -> V_25 = V_98 ;
V_1 -> V_29 = V_99 ;
}
V_1 -> V_6 = F_55 ( V_1 -> V_25 , V_84 ) ;
if ( ! V_1 -> V_6 )
return - V_85 ;
V_1 -> V_27 = F_55 ( V_1 -> V_25 , V_84 ) ;
if ( ! V_1 -> V_27 ) {
V_4 = - V_85 ;
goto V_100;
}
V_4 = F_17 ( V_1 , V_62 ,
V_63 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
F_51 ( V_1 -> V_5 , L_16 , V_15 ) ;
if ( V_74 && V_74 -> V_101 )
V_74 -> V_101 ( V_1 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
if ( V_1 -> V_29 [ V_24 ] == 11 &&
F_24 ( V_1 ) )
continue;
F_17 ( V_1 , V_31 ,
V_44 + V_1 -> V_29 [ V_24 ] ,
& V_15 ) ;
F_10 ( V_1 , V_31 ,
V_30 + V_1 -> V_29 [ V_24 ] , 0xff ) ;
}
V_4 = F_62 ( V_1 -> V_5 , & V_102 ) ;
if ( V_4 )
goto V_103;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ )
V_1 -> V_6 [ V_24 ] = V_1 -> V_27 [ V_24 ] = 0xff ;
if ( V_1 -> V_34 ) {
V_4 = F_34 ( V_1 ) ;
if ( V_4 )
goto V_103;
if ( F_35 ( V_1 ) )
V_4 = F_63 ( V_1 -> V_33 , NULL ,
F_32 ,
V_104 | V_105 ,
L_17 , V_1 ) ;
else
V_4 = F_63 ( V_1 -> V_33 , NULL ,
F_33 ,
V_104 | V_105 ,
L_17 , V_1 ) ;
if ( V_4 )
goto V_106;
}
if ( ! V_81 ) {
V_4 = F_64 ( V_1 -> V_5 , 0 , V_107 ,
F_65 ( V_107 ) , NULL ,
V_1 -> V_34 ) ;
if ( V_4 )
goto V_108;
if ( F_35 ( V_1 ) )
V_4 = F_64 ( V_1 -> V_5 , 0 , V_109 ,
F_65 ( V_109 ) , NULL ,
V_1 -> V_34 ) ;
else
V_4 = F_64 ( V_1 -> V_5 , 0 , V_110 ,
F_65 ( V_110 ) , NULL ,
V_1 -> V_34 ) ;
if ( V_4 )
goto V_108;
if ( F_35 ( V_1 ) || F_36 ( V_1 ) )
V_4 = F_64 ( V_1 -> V_5 , 0 , V_111 ,
F_65 ( V_111 ) , NULL ,
V_1 -> V_34 ) ;
if ( V_4 )
goto V_108;
}
if ( ! V_112 ) {
V_4 = F_64 ( V_1 -> V_5 , 0 , V_113 ,
F_65 ( V_113 ) , NULL ,
V_1 -> V_34 ) ;
if ( V_4 )
F_3 ( V_1 -> V_5 , L_18 ) ;
}
if ( F_35 ( V_1 ) )
V_4 = F_66 ( & V_1 -> V_5 -> V_114 ,
& V_115 ) ;
else
V_4 = F_66 ( & V_1 -> V_5 -> V_114 ,
& V_116 ) ;
if ( V_4 )
F_3 ( V_1 -> V_5 , L_19 ) ;
else
return V_4 ;
V_108:
if ( V_1 -> V_34 )
F_67 ( V_1 -> V_33 , V_1 ) ;
V_106:
if ( V_1 -> V_34 )
F_43 ( V_1 ) ;
V_103:
F_68 ( V_1 -> V_27 ) ;
V_100:
F_68 ( V_1 -> V_6 ) ;
V_86:
F_68 ( V_1 ) ;
return V_4 ;
}
static int T_7 F_69 ( struct V_71 * V_72 )
{
struct V_1 * V_1 = F_70 ( V_72 ) ;
if ( F_35 ( V_1 ) )
F_71 ( & V_1 -> V_5 -> V_114 , & V_115 ) ;
else
F_71 ( & V_1 -> V_5 -> V_114 , & V_116 ) ;
F_72 ( V_1 -> V_5 ) ;
if ( V_1 -> V_34 ) {
F_67 ( V_1 -> V_33 , V_1 ) ;
F_43 ( V_1 ) ;
}
F_68 ( V_1 -> V_27 ) ;
F_68 ( V_1 -> V_6 ) ;
F_68 ( V_1 ) ;
return 0 ;
}
static int T_8 F_73 ( void )
{
return F_74 ( & V_117 ) ;
}
static void T_9 F_75 ( void )
{
F_76 ( & V_117 ) ;
}
