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
return - V_17 ;
* V_15 = V_16 ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 )
{
int V_16 ;
T_1 V_15 ;
V_16 = F_5 ( V_12 , V_18 , 0x40 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_7 ( V_12 , V_18 , & V_15 ) ;
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
T_1 V_22 [] [ V_23 ] = {
{ 0x9c , 0x30 , 0x9c , 0xb0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
{ 0x9c , 0x40 , 0x9c , 0xc0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
{ 0x9c , 0x50 , 0x9c , 0xd0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
} ;
V_16 |= F_5 ( V_12 , V_18 , V_24 ) ;
F_12 ( 1000 , 2000 ) ;
V_16 |= F_5 ( V_12 , V_25 ,
V_26 | V_27 |
V_28 | V_29 |
V_30 ) ;
V_16 |= F_5 ( V_12 , V_31 , 0x01 ) ;
V_16 |= F_5 ( V_12 , V_32 , 0xff ) ;
V_16 |= F_5 ( V_12 , V_33 , 0x00 ) ;
V_16 |= F_5 ( V_12 , V_34 , 0x10 ) ;
V_16 |= F_5 ( V_12 , V_35 , 0x20 ) ;
V_16 |= F_13 ( & V_20 -> V_7 [ 0 ] , V_22 [ 0 ] ) ;
V_16 |= F_13 ( & V_20 -> V_7 [ 1 ] , V_22 [ 1 ] ) ;
V_16 |= F_13 ( & V_20 -> V_7 [ 2 ] , V_22 [ 2 ] ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_36 , L_1 ) ;
return - 1 ;
}
V_16 |= F_5 ( V_12 , V_18 ,
( V_37 | V_24 ) ) ;
V_16 |= F_5 ( V_12 , V_38 , V_37 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_36 , L_2 ) ;
return - 1 ;
}
F_12 ( 3000 , 6000 ) ;
F_7 ( V_12 , V_39 , & V_21 ) ;
V_21 &= V_40 ;
if ( V_21 == V_40 ) {
F_15 ( & V_12 -> V_36 , L_3 ) ;
} else {
F_16 ( & V_12 -> V_36 , L_4 , V_21 ) ;
F_14 ( & V_12 -> V_36 , L_5 ) ;
return - 1 ;
}
F_16 ( & V_12 -> V_36 , L_6 ) ;
V_16 |= F_5 ( V_12 , V_38 , V_41 ) ;
return V_16 ;
}
static int F_17 ( struct V_5 * V_6 , T_1 V_42 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 ;
T_1 V_43 ;
V_16 = F_7 ( V_12 , V_38 , & V_43 ) ;
if ( V_16 )
goto V_44;
V_43 &= ~ ( V_6 -> V_45 ) ;
V_42 &= V_6 -> V_45 ;
V_43 |= V_42 ;
V_16 |= F_5 ( V_12 , V_38 , V_43 ) ;
V_44:
return V_16 ;
}
static int F_18 ( struct V_5 * V_6 , T_3 V_46 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 = 0 ;
V_16 |= F_17 ( V_6 , V_47 ) ;
V_16 |= F_5 ( V_12 , V_48 , V_6 -> V_49 ) ;
V_16 |= F_5 ( V_12 , V_50 ,
( T_1 ) ( V_46 >> 8 ) ) ;
V_16 |= F_5 ( V_12 , V_50 + 1 , ( T_1 ) ( V_46 ) ) ;
V_6 -> V_51 = V_46 ;
return V_16 ;
}
static int F_13 ( struct V_5 * V_6 , T_1 * V_22 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 = 0 ;
V_16 |= F_17 ( V_6 , V_47 ) ;
V_16 |= F_5 ( V_12 , V_48 ,
V_6 -> V_52 ) ;
V_16 |= F_19 ( V_12 , V_50 ,
V_23 , V_22 ) ;
return V_16 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 ;
V_16 = F_5 ( V_12 , V_18 ,
V_37 | V_24 ) ;
if ( V_16 )
goto V_44;
V_16 = F_17 ( V_6 , V_37 ) ;
V_44:
return V_16 ;
}
static int F_21 ( const char * V_15 , T_3 * V_46 , T_4 V_53 )
{
int V_54 ;
T_3 V_55 = 0 ;
V_53 = V_53 < V_56 ? V_53 : V_56 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
switch ( V_15 [ V_54 ] ) {
case '1' :
V_55 |= ( 1 << V_54 ) ;
break;
case '0' :
break;
case '\n' :
V_54 = V_53 ;
break;
default:
return - 1 ;
}
}
* V_46 = V_55 ;
return 0 ;
}
static void F_22 ( T_3 V_51 , char * V_57 )
{
int V_54 , V_58 = 0 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ )
V_58 += sprintf ( V_57 + V_58 , L_7 , F_23 ( V_51 , V_54 ) ) ;
V_57 [ V_58 ] = '\0' ;
}
static T_5 F_24 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
char * V_15 , int V_62 )
{
struct V_11 * V_12 = F_25 ( V_36 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
char V_46 [ V_56 + 1 ] ;
F_22 ( V_20 -> V_7 [ V_62 - 1 ] . V_51 , V_46 ) ;
return sprintf ( V_15 , L_8 , V_46 ) ;
}
static T_5 F_26 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
const char * V_15 , T_4 V_53 , int V_62 )
{
struct V_11 * V_12 = F_25 ( V_36 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
T_3 V_46 = 0 ;
T_5 V_16 ;
if ( F_21 ( V_15 , & V_46 , V_53 ) )
return - V_63 ;
F_27 ( & V_20 -> V_64 ) ;
V_16 = - V_63 ;
if ( V_20 -> V_7 [ V_62 - 1 ] . V_42 != V_47 )
goto V_65;
if ( F_18 ( & V_20 -> V_7 [ V_62 - 1 ] , V_46 ) )
goto V_65;
V_16 = V_53 ;
V_65:
F_28 ( & V_20 -> V_64 ) ;
return V_16 ;
}
static T_5 F_29 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
char * V_15 )
{
struct V_11 * V_12 = F_25 ( V_36 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
int V_54 , V_16 , V_58 = 0 ;
int V_9 = 0 ;
T_1 V_21 , V_66 , V_67 ;
F_27 ( & V_20 -> V_64 ) ;
V_16 = F_7 ( V_20 -> V_12 , V_39 , & V_21 ) ;
if ( V_16 < 0 )
goto V_44;
if ( ( V_20 -> V_68 ) && ( V_20 -> V_68 -> V_69 == V_70 ) )
if ( ( V_21 & V_71 ) == 0 )
goto V_44;
F_5 ( V_20 -> V_12 , V_72 ,
V_73 | 16 ) ;
F_12 ( 3000 , 6000 ) ;
V_16 = F_7 ( V_20 -> V_12 , V_39 , & V_21 ) ;
if ( ! ( V_21 & V_74 ) )
F_12 ( 3000 , 6000 ) ;
V_16 |= F_7 ( V_20 -> V_12 , V_75 , & V_67 ) ;
V_67 -- ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
if ( V_20 -> V_68 -> V_76 [ V_54 ] . V_77 == 0 )
continue;
F_5 ( V_20 -> V_12 ,
V_78 + V_54 ,
V_20 -> V_68 -> V_76 [ V_54 ] . V_77 ) ;
F_5 ( V_20 -> V_12 , V_79 + V_54 , 0xff ) ;
F_12 ( 2000 , 4000 ) ;
F_5 ( V_20 -> V_12 ,
V_72 ,
V_73 | V_54 ) ;
F_12 ( 3000 , 6000 ) ;
V_16 = F_7 ( V_20 -> V_12 , V_39 , & V_21 ) ;
if ( ! ( V_21 & V_74 ) )
F_12 ( 3000 , 6000 ) ;
V_16 |= F_7 ( V_20 -> V_12 , V_75 , & V_66 ) ;
if ( V_66 >= V_67 || V_66 < V_80 )
V_58 += sprintf ( V_15 + V_58 , L_9 , V_54 ) ;
F_5 ( V_20 -> V_12 , V_79 + V_54 , 0x00 ) ;
F_5 ( V_20 -> V_12 ,
V_78 + V_54 ,
V_20 -> V_10 [ V_9 ] . V_77 ) ;
V_9 ++ ;
}
if ( V_58 == 0 )
V_58 = sprintf ( V_15 , L_10 ) ;
goto V_81;
V_44:
V_58 = sprintf ( V_15 , L_11 ) ;
V_81:
F_28 ( & V_20 -> V_64 ) ;
return V_58 ;
}
static void F_30 ( struct V_2 * V_3 ,
enum V_82 V_83 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_83 = ( T_1 ) V_83 ;
F_31 ( & V_9 -> V_84 ) ;
}
static void F_32 ( struct V_85 * V_86 )
{
struct V_1 * V_9 = F_2 ( V_86 ,
struct V_1 ,
V_84 ) ;
struct V_4 * V_20 = F_4 ( V_9 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
F_27 ( & V_20 -> V_64 ) ;
F_5 ( V_12 , V_79 + V_9 -> V_87 ,
V_9 -> V_83 ) ;
F_28 ( & V_20 -> V_64 ) ;
}
static int F_33 ( struct V_5 * V_6 ,
const char * V_15 , T_4 V_53 )
{
struct V_4 * V_20 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_20 -> V_12 ;
int V_16 , V_88 , V_89 = 0 , V_54 = 0 ;
char V_90 [ 3 ] ;
unsigned V_91 ;
T_1 V_22 [ V_23 ] = { 0 } ;
while ( ( V_89 < V_53 - 1 ) && ( V_54 < V_23 ) ) {
V_16 = sscanf ( V_15 + V_89 , L_12 , V_90 , & V_88 ) ;
V_16 = sscanf ( V_90 , L_13 , & V_91 ) ;
if ( V_16 != 1 )
goto V_44;
V_22 [ V_54 ] = ( T_1 ) V_91 ;
V_89 += V_88 ;
V_54 ++ ;
}
if ( V_54 % 2 )
goto V_44;
F_27 ( & V_20 -> V_64 ) ;
if ( V_6 -> V_42 == V_47 )
V_16 = F_13 ( V_6 , V_22 ) ;
else
V_16 = - V_63 ;
F_28 ( & V_20 -> V_64 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_36 , L_14 ) ;
return V_16 ;
}
return V_53 ;
V_44:
F_14 ( & V_12 -> V_36 , L_15 ) ;
return - V_63 ;
}
static T_5 F_34 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
const char * V_15 , T_4 V_53 , int V_62 )
{
struct V_11 * V_12 = F_25 ( V_36 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
return F_33 ( & V_20 -> V_7 [ V_62 - 1 ] , V_15 , V_53 ) ;
}
static T_5 F_35 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
char * V_15 , int V_62 )
{
struct V_11 * V_12 = F_25 ( V_36 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
switch ( V_20 -> V_7 [ V_62 - 1 ] . V_42 ) {
case V_37 :
return sprintf ( V_15 , L_16 ) ;
case V_47 :
return sprintf ( V_15 , L_17 ) ;
case V_41 :
return sprintf ( V_15 , L_18 ) ;
default:
return sprintf ( V_15 , L_18 ) ;
}
}
static T_5 F_36 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
const char * V_15 , T_4 V_53 , int V_62 )
{
struct V_11 * V_12 = F_25 ( V_36 ) ;
struct V_4 * V_20 = F_11 ( V_12 ) ;
struct V_5 * V_6 = & V_20 -> V_7 [ V_62 - 1 ] ;
F_27 ( & V_20 -> V_64 ) ;
if ( ! strncmp ( V_15 , L_19 , 3 ) )
F_37 ( V_6 , V_37 ) ;
else if ( ! strncmp ( V_15 , L_20 , 4 ) )
F_37 ( V_6 , V_47 ) ;
else if ( ! strncmp ( V_15 , L_21 , 8 ) )
F_37 ( V_6 , V_41 ) ;
F_28 ( & V_20 -> V_64 ) ;
return V_53 ;
}
static T_5 F_38 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
char * V_15 )
{
struct V_2 * V_92 = F_39 ( V_36 ) ;
struct V_1 * V_9 = F_1 ( V_92 ) ;
return sprintf ( V_15 , L_22 , V_9 -> V_93 ) ;
}
static T_5 F_40 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
char * V_15 )
{
struct V_2 * V_92 = F_39 ( V_36 ) ;
struct V_1 * V_9 = F_1 ( V_92 ) ;
return sprintf ( V_15 , L_22 , V_9 -> V_77 ) ;
}
static T_5 F_41 ( struct V_59 * V_36 ,
struct V_60 * V_61 ,
const char * V_15 , T_4 V_53 )
{
struct V_2 * V_92 = F_39 ( V_36 ) ;
struct V_1 * V_9 = F_1 ( V_92 ) ;
struct V_4 * V_20 = F_4 ( V_9 ) ;
T_5 V_16 ;
unsigned long V_94 ;
if ( F_42 ( V_15 , 0 , & V_94 ) )
return - V_63 ;
if ( V_94 > V_9 -> V_93 )
return - V_63 ;
F_27 ( & V_20 -> V_64 ) ;
V_16 = F_5 ( V_20 -> V_12 ,
V_78 + V_9 -> V_87 ,
( T_1 ) V_94 ) ;
F_28 ( & V_20 -> V_64 ) ;
if ( V_16 < 0 )
return V_16 ;
V_9 -> V_77 = ( T_1 ) V_94 ;
return V_53 ;
}
static int F_43 ( struct V_11 * V_12 )
{
struct V_59 * V_36 = & V_12 -> V_36 ;
int V_16 ;
V_16 = F_44 ( & V_36 -> V_95 , & V_96 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static void F_45 ( struct V_11 * V_12 )
{
struct V_4 * V_20 = F_11 ( V_12 ) ;
struct V_59 * V_36 = & V_12 -> V_36 ;
int V_54 ;
F_46 ( & V_36 -> V_95 , & V_96 ) ;
for ( V_54 = 0 ; V_54 < V_20 -> V_97 ; V_54 ++ )
F_46 ( & V_20 -> V_10 [ V_54 ] . V_3 . V_36 -> V_95 ,
& V_98 ) ;
}
static int F_37 ( struct V_5 * V_6 , T_1 V_42 )
{
int V_16 = 0 ;
if ( V_42 == V_6 -> V_42 && V_42 != V_37 )
return 0 ;
if ( V_42 == V_37 ) {
V_16 = F_20 ( V_6 ) ;
} else if ( V_42 == V_47 ) {
F_17 ( V_6 , V_41 ) ;
F_17 ( V_6 , V_47 ) ;
} else if ( V_42 == V_41 ) {
F_17 ( V_6 , V_41 ) ;
}
V_6 -> V_42 = V_42 ;
return V_16 ;
}
static int T_6 F_47 ( struct V_5 * V_6 , int V_8 )
{
if ( V_8 < 1 || V_8 > V_99 )
return - 1 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_45 = V_100 >> F_48 ( V_8 ) ;
V_6 -> V_52 = V_8 - 1 ;
V_6 -> V_49 = V_8 + 2 ;
return 0 ;
}
static int T_7 F_49 ( struct V_1 * V_9 , struct V_59 * V_36 ,
int V_101 , struct V_102 * V_68 )
{
char V_103 [ 32 ] ;
int V_104 ;
if ( V_101 >= V_56 )
return - V_63 ;
if ( V_68 -> V_76 [ V_101 ] . V_77 ) {
V_9 -> V_77 = V_68 -> V_76 [ V_101 ] . V_77 ;
V_9 -> V_93 = V_68 -> V_76 [ V_101 ] . V_93 ;
V_9 -> V_87 = V_68 -> V_76 [ V_101 ] . V_87 ;
if ( V_9 -> V_87 >= V_56 ) {
F_14 ( V_36 , L_23 ,
V_56 - 1 ) ;
return - V_63 ;
}
snprintf ( V_103 , sizeof( V_103 ) , L_24 ,
V_68 -> V_105 ? : L_25 , V_101 ) ;
V_9 -> V_3 . V_103 = V_103 ;
V_9 -> V_3 . V_106 = F_30 ;
V_104 = F_50 ( V_36 , & V_9 -> V_3 ) ;
if ( V_104 < 0 ) {
F_14 ( V_36 , L_26 ,
V_101 ) ;
return V_104 ;
}
V_104 = F_44 ( & V_9 -> V_3 . V_36 -> V_95 ,
& V_98 ) ;
if ( V_104 < 0 ) {
F_14 ( V_36 , L_27 ) ;
F_51 ( & V_9 -> V_3 ) ;
return V_104 ;
}
} else {
V_9 -> V_77 = 0 ;
}
return 0 ;
}
static int T_7 F_52 ( struct V_11 * V_12 ,
const struct V_107 * V_8 )
{
struct V_4 * V_20 ;
struct V_102 * V_68 ;
int V_16 , V_54 , V_9 ;
V_20 = F_53 ( sizeof( * V_20 ) , V_108 ) ;
if ( ! V_20 )
return - V_109 ;
F_54 ( V_12 , V_20 ) ;
V_20 -> V_12 = V_12 ;
V_68 = V_12 -> V_36 . V_110 ;
if ( ! V_68 ) {
F_14 ( & V_12 -> V_36 , L_28 ) ;
V_16 = - V_63 ;
goto V_111;
}
F_55 ( & V_20 -> V_64 ) ;
V_20 -> V_68 = V_68 ;
if ( V_68 -> V_112 ) {
V_16 = V_68 -> V_112 () ;
if ( V_16 < 0 )
goto V_111;
}
if ( V_68 -> V_113 ) {
V_68 -> V_113 ( 0 ) ;
F_12 ( 1000 , 2000 ) ;
V_68 -> V_113 ( 1 ) ;
F_12 ( 1000 , 2000 ) ;
}
F_5 ( V_12 , V_114 , 0xff ) ;
F_12 ( 10000 , 20000 ) ;
V_16 = F_9 ( V_12 ) ;
if ( V_16 )
goto V_115;
F_16 ( & V_12 -> V_36 , L_29 ) ;
for ( V_54 = 0 ; V_54 < F_56 ( V_20 -> V_7 ) ; V_54 ++ ) {
V_16 = F_47 ( & V_20 -> V_7 [ V_54 ] , V_54 + 1 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_36 , L_30 ) ;
goto V_115;
}
}
V_16 = F_10 ( V_12 ) ;
if ( V_16 < 0 ) {
F_14 ( & V_12 -> V_36 , L_31 ) ;
goto V_115;
}
V_20 -> V_116 = V_68 -> V_116 ;
V_20 -> V_97 = 0 ;
V_9 = 0 ;
for ( V_54 = 0 ; V_54 < V_68 -> V_116 ; V_54 ++ ) {
if ( V_68 -> V_76 [ V_54 ] . V_77 == 0 )
continue;
V_16 = F_49 ( & V_20 -> V_10 [ V_9 ] , & V_12 -> V_36 , V_54 , V_68 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_36 , L_32 ) ;
goto V_117;
}
V_20 -> V_97 ++ ;
V_20 -> V_10 [ V_9 ] . V_8 = V_9 ;
F_5 ( V_12 ,
V_78 + V_20 -> V_10 [ V_9 ] . V_87 ,
V_20 -> V_10 [ V_9 ] . V_77 ) ;
F_57 ( & ( V_20 -> V_10 [ V_9 ] . V_84 ) ,
F_32 ) ;
V_9 ++ ;
}
V_16 = F_43 ( V_12 ) ;
if ( V_16 ) {
F_14 ( & V_12 -> V_36 , L_33 ) ;
goto V_117;
}
return V_16 ;
V_117:
for ( V_54 = 0 ; V_54 < V_20 -> V_97 ; V_54 ++ ) {
F_51 ( & V_20 -> V_10 [ V_54 ] . V_3 ) ;
F_58 ( & V_20 -> V_10 [ V_54 ] . V_84 ) ;
}
V_115:
if ( V_68 -> V_113 )
V_68 -> V_113 ( 0 ) ;
if ( V_68 -> V_118 )
V_68 -> V_118 () ;
V_111:
F_59 ( V_20 ) ;
return V_16 ;
}
static int F_60 ( struct V_11 * V_12 )
{
struct V_4 * V_20 = F_11 ( V_12 ) ;
int V_54 ;
F_45 ( V_12 ) ;
for ( V_54 = 0 ; V_54 < V_20 -> V_97 ; V_54 ++ ) {
F_51 ( & V_20 -> V_10 [ V_54 ] . V_3 ) ;
F_58 ( & V_20 -> V_10 [ V_54 ] . V_84 ) ;
}
if ( V_20 -> V_68 -> V_113 )
V_20 -> V_68 -> V_113 ( 0 ) ;
if ( V_20 -> V_68 -> V_118 )
V_20 -> V_68 -> V_118 () ;
F_59 ( V_20 ) ;
return 0 ;
}
