static inline void F_1 ( void )
{
F_2 ( 1000 , 2000 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_3 = V_3 ;
F_4 ( V_2 -> V_4 , V_5 + V_2 -> V_6 ,
V_3 ) ;
}
static int F_5 ( struct V_7 * V_4 )
{
int V_8 ;
V_8 = F_4 ( V_4 , V_9 , V_10 ) ;
if ( V_8 )
return V_8 ;
F_2 ( 1000 , 2000 ) ;
V_8 = F_4 ( V_4 , V_11 ,
V_12 | V_13 |
V_14 | V_15 |
V_16 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_17 , 0x01 ) ;
if ( V_8 )
return V_8 ;
return F_4 ( V_4 , V_18 , 0xff ) ;
}
static void F_6 ( struct V_7 * V_4 )
{
enum V_19 V_20 = V_4 -> V_21 ;
T_1 V_22 [] = {
[ V_23 ] = V_24 ,
[ V_25 ] = V_26 ,
[ V_27 ] = V_28 ,
} ;
T_1 V_29 [] = {
[ V_23 ] = V_30 ,
[ V_25 ] = V_31 ,
[ V_27 ] = V_32 ,
} ;
T_1 V_33 [] = {
[ V_23 ] = V_34 ,
[ V_25 ] = V_35 ,
[ V_27 ] = V_36 ,
} ;
F_7 ( V_4 , V_37 , V_22 [ V_20 ] , V_29 [ V_20 ] ) ;
F_1 () ;
F_4 ( V_4 , V_38 , V_33 [ V_20 ] ) ;
}
static void F_8 ( struct V_7 * V_4 )
{
F_4 ( V_4 , V_37 , 0 ) ;
F_1 () ;
}
static void F_9 ( struct V_7 * V_4 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_4 ( V_4 , V_41 + V_39 , 0 ) ;
}
static void F_10 ( struct V_7 * V_4 , bool V_42 )
{
int V_8 ;
T_1 V_43 ;
T_1 V_44 ;
if ( ! V_42 ) {
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
return;
}
V_8 = F_11 ( V_4 , V_37 , & V_43 ) ;
if ( V_8 )
return;
V_8 = F_11 ( V_4 , V_9 , & V_44 ) ;
if ( V_8 )
return;
if ( F_12 ( V_43 ) ) {
V_43 = ( V_43 & ~ V_24 ) | V_45 ;
V_44 = ( V_44 & ~ V_46 ) | V_45 ;
}
if ( F_13 ( V_43 ) ) {
V_43 = ( V_43 & ~ V_26 ) | V_47 ;
V_44 = ( V_44 & ~ V_48 ) | V_47 ;
}
if ( F_14 ( V_43 ) ) {
V_43 = ( V_43 & ~ V_28 ) | V_49 ;
V_44 = ( V_44 & ~ V_50 ) | V_49 ;
}
F_4 ( V_4 , V_37 , V_43 ) ;
F_1 () ;
F_7 ( V_4 , V_9 , V_51 , V_44 ) ;
}
static int F_15 ( struct V_7 * V_4 ,
const T_1 * V_52 , T_2 V_53 )
{
T_1 V_54 [ V_55 ] = { 0 } ;
unsigned V_56 ;
char V_57 [ 3 ] ;
int V_58 ;
int V_59 ;
int V_60 = 0 ;
int V_8 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_55 ; V_39 ++ )
F_4 ( V_4 , V_61 + V_39 , 0 ) ;
V_39 = 0 ;
while ( ( V_60 < V_53 - 1 ) && ( V_39 < V_55 ) ) {
V_8 = sscanf ( V_52 + V_60 , L_1 , V_57 , & V_59 ) ;
if ( V_8 != 1 )
goto V_62;
V_8 = sscanf ( V_57 , L_2 , & V_56 ) ;
if ( V_8 != 1 )
goto V_62;
V_54 [ V_39 ] = ( T_1 ) V_56 ;
V_60 += V_59 ;
V_39 ++ ;
}
if ( V_39 % 2 )
goto V_62;
V_58 = V_39 ;
for ( V_39 = 0 ; V_39 < V_58 ; V_39 ++ )
F_4 ( V_4 , V_61 + V_39 , V_54 [ V_39 ] ) ;
return 0 ;
V_62:
F_16 ( & V_4 -> V_63 -> V_64 , L_3 ) ;
return - V_65 ;
}
static void F_17 ( struct V_7 * V_4 )
{
const struct V_66 * V_67 = V_4 -> V_67 ;
if ( V_67 -> V_53 > V_55 ) {
F_16 ( & V_4 -> V_63 -> V_64 , L_4 ,
V_67 -> V_53 ) ;
return;
}
F_6 ( V_4 ) ;
F_15 ( V_4 , V_67 -> V_52 , V_67 -> V_53 ) ;
}
static T_3 F_18 ( struct V_68 * V_64 ,
struct V_69 * V_70 ,
char * V_71 )
{
struct V_1 * V_2 = F_19 ( F_20 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_72 * V_73 = V_4 -> V_73 ;
int V_39 , V_8 , V_74 = 0 ;
T_1 V_75 , V_76 , V_77 ;
F_21 ( & V_4 -> V_78 ) ;
V_8 = F_11 ( V_4 , V_79 , & V_75 ) ;
if ( V_8 < 0 )
goto V_80;
if ( V_73 -> V_81 == V_82 ) {
if ( ( V_75 & V_83 ) == 0 )
goto V_80;
}
F_4 ( V_4 , V_84 , V_85 | 16 ) ;
F_2 ( 3000 , 6000 ) ;
V_8 = F_11 ( V_4 , V_79 , & V_75 ) ;
if ( V_8 < 0 )
goto V_80;
if ( ! ( V_75 & V_86 ) )
F_2 ( 3000 , 6000 ) ;
V_8 = F_11 ( V_4 , V_87 , & V_77 ) ;
if ( V_8 < 0 )
goto V_80;
V_77 -- ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( V_73 -> V_88 [ V_39 ] . V_3 == 0 )
continue;
F_4 ( V_4 , V_5 + V_39 ,
V_73 -> V_88 [ V_39 ] . V_3 ) ;
F_4 ( V_4 , V_41 + V_39 , 0xff ) ;
F_2 ( 2000 , 4000 ) ;
F_4 ( V_4 , V_84 ,
V_85 | V_39 ) ;
F_2 ( 3000 , 6000 ) ;
V_8 = F_11 ( V_4 , V_79 , & V_75 ) ;
if ( V_8 < 0 )
goto V_80;
if ( ! ( V_75 & V_86 ) )
F_2 ( 3000 , 6000 ) ;
V_8 = F_11 ( V_4 , V_87 , & V_76 ) ;
if ( V_8 < 0 )
goto V_80;
if ( V_76 >= V_77 || V_76 < V_89 )
V_74 += sprintf ( V_71 + V_74 , L_5 , V_39 ) ;
F_4 ( V_4 , V_41 + V_39 , 0x00 ) ;
F_4 ( V_4 , V_5 + V_39 ,
V_2 -> V_3 ) ;
V_2 ++ ;
}
if ( V_74 == 0 )
V_74 = sprintf ( V_71 , L_6 ) ;
goto V_90;
V_80:
V_74 = sprintf ( V_71 , L_7 ) ;
V_90:
F_22 ( & V_4 -> V_78 ) ;
return V_74 ;
}
static void F_23 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_24 ( V_92 , struct V_1 ,
V_93 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_21 ( & V_4 -> V_78 ) ;
F_4 ( V_4 , V_41 + V_2 -> V_6 ,
V_2 -> V_94 ) ;
F_22 ( & V_4 -> V_78 ) ;
}
static int F_25 ( struct V_95 * V_96 ,
const struct V_97 * V_98 )
{
int V_8 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
struct V_72 * V_73 = V_96 -> V_64 . V_99 ;
if ( ! V_73 ) {
F_16 ( & V_96 -> V_64 , L_8 ) ;
return - V_65 ;
}
V_4 = F_26 ( & V_96 -> V_64 , sizeof( * V_4 ) , V_100 ) ;
if ( ! V_4 )
return - V_101 ;
V_2 = F_26 ( & V_96 -> V_64 ,
sizeof( * V_2 ) * V_73 -> V_102 , V_100 ) ;
if ( ! V_2 )
return - V_101 ;
V_4 -> V_63 = V_96 ;
V_4 -> V_73 = V_73 ;
V_4 -> V_103 = & V_104 ;
F_27 ( & V_4 -> V_78 ) ;
F_28 ( V_96 , V_2 ) ;
V_8 = F_29 ( V_4 ) ;
if ( V_8 )
goto V_105;
F_30 ( & V_96 -> V_64 , L_9 , V_98 -> V_106 ) ;
V_8 = F_31 ( V_2 , V_4 ) ;
if ( V_8 )
goto V_107;
V_8 = F_32 ( V_4 ) ;
if ( V_8 ) {
F_16 ( & V_96 -> V_64 , L_10 ) ;
goto V_108;
}
return 0 ;
V_108:
F_33 ( V_2 , V_4 ) ;
V_107:
F_34 ( V_4 ) ;
V_105:
return V_8 ;
}
static int F_35 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_19 ( V_96 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_8 ( V_4 ) ;
F_36 ( V_4 ) ;
F_33 ( V_2 , V_4 ) ;
F_34 ( V_4 ) ;
return 0 ;
}
