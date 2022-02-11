static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 ,
V_7 [ V_6 -> V_8 - 1 ] ) ;
}
static inline struct V_4 * F_4 ( struct V_1 * V_9 )
{
return F_2 ( V_9 , struct V_4 ,
V_10 [ V_9 -> V_8 ] ) ;
}
static int F_5 ( struct V_11 * V_12 , T_1 V_13 , T_1 V_14 )
{
return F_6 ( V_12 , V_13 , V_14 ) ;
}
static int F_7 ( struct V_11 * V_12 , T_1 V_13 , T_1 * V_15 )
{
T_2 V_16 = F_8 ( V_12 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_15 = V_16 ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 )
{
int V_16 ;
T_1 V_15 ;
V_16 = F_5 ( V_12 , V_17 , V_18 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_7 ( V_12 , V_17 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 == 0x40 )
return 0 ;
else
return - V_19 ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_4 * V_20 = F_11 ( V_12 ) ;
int V_16 = 0 ;
T_1 V_21 ;
static const T_1 V_22 [] [ V_23 ] = {
{ 0x9c , 0x30 , 0x9c , 0xb0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
{ 0x9c , 0x40 , 0x9c , 0xc0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
{ 0x9c , 0x50 , 0x9c , 0xd0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
} ;
V_16 |= F_5 ( V_12 , V_17 , V_18 ) ;
F_12 ( 1000 , 2000 ) ;
V_16 |= F_5 ( V_12 , V_24 ,
V_25 | V_26 |
V_27 | V_28 |
V_29 ) ;
V_16 |= F_5 ( V_12 , V_30 , 0x01 ) ;
V_16 |= F_5 ( V_12 , V_31 , 0xff ) ;
V_16 |= F_5 ( V_12 , V_32 , 0x00 ) ;
V_16 |= F_5 ( V_12 , V_33 , 0x10 ) ;
V_16 |= F_5 ( V_12 , V_34 , 0x20 ) ;
V_16 |= F_13 ( & V_20 -> V_7 [ 0 ] , V_22 [ 0 ] ) ;
V_16 |= F_13 ( & V_20 -> V_7 [ 1 ] , V_22 [ 1 ] ) ;
V_16 |= F_13 ( & V_20 -> V_7 [ 2 ] , V_22 [ 2 ] ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_35 , L_1 ) ;
return - 1 ;
}
V_16 |= F_5 ( V_12 , V_17 ,
( V_36 | V_18 ) ) ;
V_16 |= F_5 ( V_12 , V_37 , V_36 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_35 , L_2 ) ;
return - 1 ;
}
F_12 ( 3000 , 6000 ) ;
V_16 = F_7 ( V_12 , V_38 , & V_21 ) ;
if ( V_16 < 0 )
return V_16 ;
V_21 &= V_39 ;
if ( V_21 == V_39 ) {
F_15 ( & V_12 -> V_35 , L_3 ) ;
} else {
F_16 ( & V_12 -> V_35 , L_4 , V_21 ) ;
F_14 ( & V_12 -> V_35 , L_5 ) ;
return - 1 ;
}
F_16 ( & V_12 -> V_35 , L_6 ) ;
V_16 |= F_5 ( V_12 , V_37 , V_40 ) ;
return V_16 ;
}
static int F_17 ( struct V_5 * V_6 , T_1 V_41 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 ;
T_1 V_42 ;
V_16 = F_7 ( V_12 , V_37 , & V_42 ) ;
if ( V_16 )
goto V_43;
V_42 &= ~ ( V_6 -> V_44 ) ;
V_41 &= V_6 -> V_44 ;
V_42 |= V_41 ;
V_16 |= F_5 ( V_12 , V_37 , V_42 ) ;
V_43:
return V_16 ;
}
static int F_18 ( struct V_5 * V_6 , T_3 V_45 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 = 0 ;
V_16 |= F_17 ( V_6 , V_46 ) ;
V_16 |= F_5 ( V_12 , V_47 , V_6 -> V_48 ) ;
V_16 |= F_5 ( V_12 , V_49 ,
( T_1 ) ( V_45 >> 8 ) ) ;
V_16 |= F_5 ( V_12 , V_49 + 1 , ( T_1 ) ( V_45 ) ) ;
V_6 -> V_50 = V_45 ;
return V_16 ;
}
static int F_13 ( struct V_5 * V_6 , const T_1 * V_22 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 = 0 ;
V_16 |= F_17 ( V_6 , V_46 ) ;
V_16 |= F_5 ( V_12 , V_47 ,
V_6 -> V_51 ) ;
V_16 |= F_19 ( V_12 , V_49 ,
V_23 , V_22 ) ;
return V_16 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 ;
V_16 = F_5 ( V_12 , V_17 ,
V_36 | V_18 ) ;
if ( V_16 )
goto V_43;
V_16 = F_17 ( V_6 , V_36 ) ;
V_43:
return V_16 ;
}
static int F_21 ( const char * V_15 , T_3 * V_45 , T_4 V_52 )
{
int V_53 ;
T_3 V_54 = 0 ;
V_52 = F_22 ( int , V_52 , V_55 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
switch ( V_15 [ V_53 ] ) {
case '1' :
V_54 |= ( 1 << V_53 ) ;
break;
case '0' :
break;
case '\n' :
V_53 = V_52 ;
break;
default:
return - 1 ;
}
}
* V_45 = V_54 ;
return 0 ;
}
static void F_23 ( T_3 V_50 , char * V_56 )
{
int V_53 , V_57 = 0 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
V_57 += sprintf ( V_56 + V_57 , L_7 , F_24 ( V_50 , V_53 ) ) ;
V_56 [ V_57 ] = '\0' ;
}
static T_5 F_25 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
char * V_15 , int V_61 )
{
struct V_11 * V_12 = F_26 ( V_35 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
char V_45 [ V_55 + 1 ] ;
F_23 ( V_20 -> V_7 [ V_61 - 1 ] . V_50 , V_45 ) ;
return sprintf ( V_15 , L_8 , V_45 ) ;
}
static T_5 F_27 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
const char * V_15 , T_4 V_52 , int V_61 )
{
struct V_11 * V_12 = F_26 ( V_35 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
T_3 V_45 = 0 ;
T_5 V_16 ;
if ( F_21 ( V_15 , & V_45 , V_52 ) )
return - V_62 ;
F_28 ( & V_20 -> V_63 ) ;
V_16 = - V_62 ;
if ( V_20 -> V_7 [ V_61 - 1 ] . V_41 != V_46 )
goto V_64;
if ( F_18 ( & V_20 -> V_7 [ V_61 - 1 ] , V_45 ) )
goto V_64;
V_16 = V_52 ;
V_64:
F_29 ( & V_20 -> V_63 ) ;
return V_16 ;
}
static T_5 F_30 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
char * V_15 )
{
struct V_11 * V_12 = F_26 ( V_35 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
int V_53 , V_16 , V_57 = 0 ;
int V_9 = 0 ;
T_1 V_21 , V_65 , V_66 ;
F_28 ( & V_20 -> V_63 ) ;
V_16 = F_7 ( V_20 -> V_12 , V_38 , & V_21 ) ;
if ( V_16 < 0 )
goto V_43;
if ( ( V_20 -> V_67 ) && ( V_20 -> V_67 -> V_68 == V_69 ) )
if ( ( V_21 & V_70 ) == 0 )
goto V_43;
F_5 ( V_20 -> V_12 , V_71 ,
V_72 | 16 ) ;
F_12 ( 3000 , 6000 ) ;
V_16 = F_7 ( V_20 -> V_12 , V_38 , & V_21 ) ;
if ( V_16 < 0 )
goto V_43;
if ( ! ( V_21 & V_73 ) )
F_12 ( 3000 , 6000 ) ;
V_16 = F_7 ( V_20 -> V_12 , V_74 , & V_66 ) ;
if ( V_16 < 0 )
goto V_43;
V_66 -- ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( V_20 -> V_67 -> V_75 [ V_53 ] . V_76 == 0 )
continue;
F_5 ( V_20 -> V_12 ,
V_77 + V_53 ,
V_20 -> V_67 -> V_75 [ V_53 ] . V_76 ) ;
F_5 ( V_20 -> V_12 , V_78 + V_53 , 0xff ) ;
F_12 ( 2000 , 4000 ) ;
F_5 ( V_20 -> V_12 ,
V_71 ,
V_72 | V_53 ) ;
F_12 ( 3000 , 6000 ) ;
V_16 = F_7 ( V_20 -> V_12 , V_38 , & V_21 ) ;
if ( V_16 < 0 )
goto V_43;
if ( ! ( V_21 & V_73 ) )
F_12 ( 3000 , 6000 ) ;
V_16 = F_7 ( V_20 -> V_12 , V_74 , & V_65 ) ;
if ( V_16 < 0 )
goto V_43;
if ( V_65 >= V_66 || V_65 < V_79 )
V_57 += sprintf ( V_15 + V_57 , L_9 , V_53 ) ;
F_5 ( V_20 -> V_12 , V_78 + V_53 , 0x00 ) ;
F_5 ( V_20 -> V_12 ,
V_77 + V_53 ,
V_20 -> V_10 [ V_9 ] . V_76 ) ;
V_9 ++ ;
}
if ( V_57 == 0 )
V_57 = sprintf ( V_15 , L_10 ) ;
goto V_80;
V_43:
V_57 = sprintf ( V_15 , L_11 ) ;
V_80:
F_29 ( & V_20 -> V_63 ) ;
return V_57 ;
}
static void F_31 ( struct V_2 * V_3 ,
enum V_81 V_82 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_82 = ( T_1 ) V_82 ;
F_32 ( & V_9 -> V_83 ) ;
}
static void F_33 ( struct V_84 * V_85 )
{
struct V_1 * V_9 = F_2 ( V_85 ,
struct V_1 ,
V_83 ) ;
struct V_4 * V_20 = F_4 ( V_9 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
F_28 ( & V_20 -> V_63 ) ;
F_5 ( V_12 , V_78 + V_9 -> V_86 ,
V_9 -> V_82 ) ;
F_29 ( & V_20 -> V_63 ) ;
}
static int F_34 ( struct V_5 * V_6 ,
const char * V_15 , T_4 V_52 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 , V_87 , V_88 = 0 , V_53 = 0 ;
char V_89 [ 3 ] ;
unsigned V_90 ;
T_1 V_22 [ V_23 ] = { 0 } ;
if ( V_6 -> V_41 != V_46 )
return - V_62 ;
while ( ( V_88 < V_52 - 1 ) && ( V_53 < V_23 ) ) {
V_16 = sscanf ( V_15 + V_88 , L_12 , V_89 , & V_87 ) ;
V_16 = sscanf ( V_89 , L_13 , & V_90 ) ;
if ( V_16 != 1 )
goto V_43;
V_22 [ V_53 ] = ( T_1 ) V_90 ;
V_88 += V_87 ;
V_53 ++ ;
}
if ( V_53 % 2 )
goto V_43;
F_28 ( & V_20 -> V_63 ) ;
V_16 = F_13 ( V_6 , V_22 ) ;
F_29 ( & V_20 -> V_63 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_35 , L_14 ) ;
return V_16 ;
}
return V_52 ;
V_43:
F_14 ( & V_12 -> V_35 , L_15 ) ;
return - V_62 ;
}
static T_5 F_35 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
const char * V_15 , T_4 V_52 , int V_61 )
{
struct V_11 * V_12 = F_26 ( V_35 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
return F_34 ( & V_20 -> V_7 [ V_61 - 1 ] , V_15 , V_52 ) ;
}
static T_5 F_36 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
char * V_15 , int V_61 )
{
struct V_11 * V_12 = F_26 ( V_35 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
switch ( V_20 -> V_7 [ V_61 - 1 ] . V_41 ) {
case V_36 :
return sprintf ( V_15 , L_16 ) ;
case V_46 :
return sprintf ( V_15 , L_17 ) ;
case V_40 :
return sprintf ( V_15 , L_18 ) ;
default:
return sprintf ( V_15 , L_18 ) ;
}
}
static T_5 F_37 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
const char * V_15 , T_4 V_52 , int V_61 )
{
struct V_11 * V_12 = F_26 ( V_35 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
struct V_5 * V_6 = & V_20 -> V_7 [ V_61 - 1 ] ;
F_28 ( & V_20 -> V_63 ) ;
if ( ! strncmp ( V_15 , L_19 , 3 ) )
F_38 ( V_6 , V_36 ) ;
else if ( ! strncmp ( V_15 , L_20 , 4 ) )
F_38 ( V_6 , V_46 ) ;
else if ( ! strncmp ( V_15 , L_21 , 8 ) )
F_38 ( V_6 , V_40 ) ;
F_29 ( & V_20 -> V_63 ) ;
return V_52 ;
}
static T_5 F_39 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
char * V_15 )
{
struct V_2 * V_91 = F_40 ( V_35 ) ;
struct V_1 * V_9 = F_1 ( V_91 ) ;
return sprintf ( V_15 , L_22 , V_9 -> V_92 ) ;
}
static T_5 F_41 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
char * V_15 )
{
struct V_2 * V_91 = F_40 ( V_35 ) ;
struct V_1 * V_9 = F_1 ( V_91 ) ;
return sprintf ( V_15 , L_22 , V_9 -> V_76 ) ;
}
static T_5 F_42 ( struct V_58 * V_35 ,
struct V_59 * V_60 ,
const char * V_15 , T_4 V_52 )
{
struct V_2 * V_91 = F_40 ( V_35 ) ;
struct V_1 * V_9 = F_1 ( V_91 ) ;
struct V_4 * V_20 = F_4 ( V_9 ) ;
T_5 V_16 ;
unsigned long V_93 ;
if ( F_43 ( V_15 , 0 , & V_93 ) )
return - V_62 ;
if ( V_93 > V_9 -> V_92 )
return - V_62 ;
F_28 ( & V_20 -> V_63 ) ;
V_16 = F_5 ( V_20 -> V_12 ,
V_77 + V_9 -> V_86 ,
( T_1 ) V_93 ) ;
F_29 ( & V_20 -> V_63 ) ;
if ( V_16 < 0 )
return V_16 ;
V_9 -> V_76 = ( T_1 ) V_93 ;
return V_52 ;
}
static int F_44 ( struct V_11 * V_12 )
{
struct V_58 * V_35 = & V_12 -> V_35 ;
int V_16 ;
V_16 = F_45 ( & V_35 -> V_94 , & V_95 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static void F_46 ( struct V_11 * V_12 )
{
struct V_4 * V_20 = F_11 ( V_12 ) ;
struct V_58 * V_35 = & V_12 -> V_35 ;
int V_53 ;
F_47 ( & V_35 -> V_94 , & V_95 ) ;
for ( V_53 = 0 ; V_53 < V_20 -> V_96 ; V_53 ++ )
F_47 ( & V_20 -> V_10 [ V_53 ] . V_3 . V_35 -> V_94 ,
& V_97 ) ;
}
static void F_38 ( struct V_5 * V_6 , T_1 V_41 )
{
if ( V_41 == V_6 -> V_41 && V_41 != V_36 )
return;
switch ( V_41 ) {
case V_36 :
F_20 ( V_6 ) ;
break;
case V_46 :
F_17 ( V_6 , V_40 ) ;
F_17 ( V_6 , V_46 ) ;
break;
case V_40 :
F_17 ( V_6 , V_40 ) ;
break;
default:
return;
}
V_6 -> V_41 = V_41 ;
}
static int T_6 F_48 ( struct V_5 * V_6 , int V_8 )
{
if ( V_8 < 1 || V_8 > V_98 )
return - 1 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_44 = V_99 >> F_49 ( V_8 ) ;
V_6 -> V_51 = V_8 - 1 ;
V_6 -> V_48 = V_8 + 2 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_9 , struct V_58 * V_35 ,
int V_100 , struct V_101 * V_67 ,
const char * V_102 )
{
char V_103 [ 32 ] ;
int V_104 ;
if ( V_100 >= V_55 )
return - V_62 ;
if ( V_67 -> V_75 [ V_100 ] . V_76 ) {
V_9 -> V_76 = V_67 -> V_75 [ V_100 ] . V_76 ;
V_9 -> V_92 = V_67 -> V_75 [ V_100 ] . V_92 ;
V_9 -> V_86 = V_67 -> V_75 [ V_100 ] . V_86 ;
if ( V_9 -> V_86 >= V_55 ) {
F_14 ( V_35 , L_23 ,
V_55 - 1 ) ;
return - V_62 ;
}
if ( V_67 -> V_75 [ V_100 ] . V_103 ) {
V_9 -> V_3 . V_103 = V_67 -> V_75 [ V_100 ] . V_103 ;
} else {
snprintf ( V_103 , sizeof( V_103 ) , L_24 ,
V_67 -> V_105 ? : V_102 , V_100 ) ;
V_9 -> V_3 . V_103 = V_103 ;
}
V_9 -> V_3 . V_106 = F_31 ;
V_104 = F_51 ( V_35 , & V_9 -> V_3 ) ;
if ( V_104 < 0 ) {
F_14 ( V_35 , L_25 ,
V_100 ) ;
return V_104 ;
}
V_104 = F_45 ( & V_9 -> V_3 . V_35 -> V_94 ,
& V_97 ) ;
if ( V_104 < 0 ) {
F_14 ( V_35 , L_26 ) ;
F_52 ( & V_9 -> V_3 ) ;
return V_104 ;
}
} else {
V_9 -> V_76 = 0 ;
}
return 0 ;
}
static int F_53 ( struct V_11 * V_12 ,
const struct V_107 * V_8 )
{
struct V_4 * V_20 ;
struct V_101 * V_67 ;
int V_16 , V_53 , V_9 ;
V_20 = F_54 ( & V_12 -> V_35 , sizeof( * V_20 ) , V_108 ) ;
if ( ! V_20 )
return - V_109 ;
F_55 ( V_12 , V_20 ) ;
V_20 -> V_12 = V_12 ;
V_67 = V_12 -> V_35 . V_110 ;
if ( ! V_67 ) {
F_14 ( & V_12 -> V_35 , L_27 ) ;
return - V_62 ;
}
F_56 ( & V_20 -> V_63 ) ;
V_20 -> V_67 = V_67 ;
if ( V_67 -> V_111 ) {
V_16 = V_67 -> V_111 () ;
if ( V_16 < 0 )
return V_16 ;
}
if ( V_67 -> V_112 ) {
V_67 -> V_112 ( 0 ) ;
F_12 ( 1000 , 2000 ) ;
V_67 -> V_112 ( 1 ) ;
F_12 ( 1000 , 2000 ) ;
}
F_5 ( V_12 , V_113 , 0xff ) ;
F_12 ( 10000 , 20000 ) ;
V_16 = F_9 ( V_12 ) ;
if ( V_16 )
goto V_114;
F_16 ( & V_12 -> V_35 , L_28 , V_8 -> V_103 ) ;
for ( V_53 = 0 ; V_53 < F_57 ( V_20 -> V_7 ) ; V_53 ++ ) {
V_16 = F_48 ( & V_20 -> V_7 [ V_53 ] , V_53 + 1 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_35 , L_29 ) ;
goto V_114;
}
}
V_16 = F_10 ( V_12 ) ;
if ( V_16 < 0 ) {
F_14 ( & V_12 -> V_35 , L_30 ) ;
goto V_114;
}
V_20 -> V_115 = V_67 -> V_115 ;
V_20 -> V_96 = 0 ;
V_9 = 0 ;
for ( V_53 = 0 ; V_53 < V_67 -> V_115 ; V_53 ++ ) {
if ( V_67 -> V_75 [ V_53 ] . V_76 == 0 )
continue;
F_58 ( & V_20 -> V_10 [ V_9 ] . V_83 ,
F_33 ) ;
V_16 = F_50 ( & V_20 -> V_10 [ V_9 ] , & V_12 -> V_35 , V_53 , V_67 ,
V_8 -> V_103 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_35 , L_31 ) ;
goto V_116;
}
V_20 -> V_96 ++ ;
V_20 -> V_10 [ V_9 ] . V_8 = V_9 ;
F_5 ( V_12 ,
V_77 + V_20 -> V_10 [ V_9 ] . V_86 ,
V_20 -> V_10 [ V_9 ] . V_76 ) ;
V_9 ++ ;
}
V_16 = F_44 ( V_12 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_35 , L_32 ) ;
goto V_116;
}
return V_16 ;
V_116:
for ( V_53 = 0 ; V_53 < V_20 -> V_96 ; V_53 ++ ) {
F_52 ( & V_20 -> V_10 [ V_53 ] . V_3 ) ;
F_59 ( & V_20 -> V_10 [ V_53 ] . V_83 ) ;
}
V_114:
if ( V_67 -> V_112 )
V_67 -> V_112 ( 0 ) ;
if ( V_67 -> V_117 )
V_67 -> V_117 () ;
return V_16 ;
}
static int F_60 ( struct V_11 * V_12 )
{
struct V_4 * V_20 = F_11 ( V_12 ) ;
int V_53 ;
F_5 ( V_12 , V_37 , V_40 ) ;
F_46 ( V_12 ) ;
for ( V_53 = 0 ; V_53 < V_20 -> V_96 ; V_53 ++ ) {
F_52 ( & V_20 -> V_10 [ V_53 ] . V_3 ) ;
F_59 ( & V_20 -> V_10 [ V_53 ] . V_83 ) ;
}
if ( V_20 -> V_67 -> V_112 )
V_20 -> V_67 -> V_112 ( 0 ) ;
if ( V_20 -> V_67 -> V_117 )
V_20 -> V_67 -> V_117 () ;
return 0 ;
}
