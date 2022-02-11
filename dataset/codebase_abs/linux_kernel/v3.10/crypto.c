void F_1 ( char * V_1 , char * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
sprintf ( & V_1 [ V_4 * 2 ] , L_1 , ( unsigned char ) V_2 [ V_4 ] ) ;
}
void F_2 ( char * V_1 , char * V_2 , int V_5 )
{
int V_4 ;
char V_6 [ 3 ] = { 0 , } ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_6 [ 0 ] = V_2 [ V_4 * 2 ] ;
V_6 [ 1 ] = V_2 [ V_4 * 2 + 1 ] ;
V_1 [ V_4 ] = ( unsigned char ) F_3 ( V_6 , NULL , 16 ) ;
}
}
static int F_4 ( char * V_1 ,
struct V_7 * V_8 ,
char * V_2 , int V_9 )
{
struct V_10 V_11 ;
struct V_12 V_13 = {
. V_14 = V_8 -> V_15 ,
. V_16 = V_17
} ;
int V_18 = 0 ;
F_5 ( & V_8 -> V_19 ) ;
F_6 ( & V_11 , ( V_20 * ) V_2 , V_9 ) ;
if ( ! V_13 . V_14 ) {
V_13 . V_14 = F_7 ( V_21 , 0 ,
V_22 ) ;
if ( F_8 ( V_13 . V_14 ) ) {
V_18 = F_9 ( V_13 . V_14 ) ;
F_10 ( V_23 , L_2
L_3 ,
V_18 ) ;
goto V_24;
}
V_8 -> V_15 = V_13 . V_14 ;
}
V_18 = F_11 ( & V_13 ) ;
if ( V_18 ) {
F_12 ( V_23
L_4 ,
V_25 , V_18 ) ;
goto V_24;
}
V_18 = F_13 ( & V_13 , & V_11 , V_9 ) ;
if ( V_18 ) {
F_12 ( V_23
L_5 ,
V_25 , V_18 ) ;
goto V_24;
}
V_18 = F_14 ( & V_13 , V_1 ) ;
if ( V_18 ) {
F_12 ( V_23
L_6 ,
V_25 , V_18 ) ;
goto V_24;
}
V_24:
F_15 ( & V_8 -> V_19 ) ;
return V_18 ;
}
static int F_16 ( char * * V_26 ,
char * V_27 ,
char * V_28 )
{
int V_29 = strlen ( V_27 ) ;
int V_30 = strlen ( V_28 ) ;
int V_31 ;
int V_18 ;
V_31 = ( V_30 + V_29 + 3 ) ;
( * V_26 ) = F_17 ( V_31 , V_32 ) ;
if ( ! ( * V_26 ) ) {
V_18 = - V_33 ;
goto V_24;
}
snprintf ( ( * V_26 ) , V_31 , L_7 ,
V_28 , V_27 ) ;
V_18 = 0 ;
V_24:
return V_18 ;
}
int F_18 ( char * V_34 , struct V_7 * V_8 ,
T_2 V_35 )
{
int V_18 = 0 ;
char V_1 [ V_36 ] ;
char V_2 [ V_37 + 16 ] ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_8 ) ;
F_20 ( V_8 -> V_40 , V_8 -> V_41 ) ;
}
memcpy ( V_2 , V_8 -> V_40 , V_8 -> V_41 ) ;
memset ( ( V_2 + V_8 -> V_41 ) , 0 , 16 ) ;
snprintf ( ( V_2 + V_8 -> V_41 ) , 16 , L_9 , V_35 ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_10 ) ;
F_20 ( V_2 , ( V_8 -> V_41 + 16 ) ) ;
}
V_18 = F_4 ( V_1 , V_8 , V_2 ,
( V_8 -> V_41 + 16 ) ) ;
if ( V_18 ) {
F_10 ( V_42 , L_11
L_12 ) ;
goto V_24;
}
memcpy ( V_34 , V_1 , V_8 -> V_41 ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_13 ) ;
F_20 ( V_34 , V_8 -> V_41 ) ;
}
V_24:
return V_18 ;
}
void
F_21 ( struct V_7 * V_8 )
{
memset ( ( void * ) V_8 , 0 , sizeof( struct V_7 ) ) ;
F_22 ( & V_8 -> V_43 ) ;
F_23 ( & V_8 -> V_44 ) ;
F_23 ( & V_8 -> V_45 ) ;
F_23 ( & V_8 -> V_46 ) ;
F_23 ( & V_8 -> V_19 ) ;
V_8 -> V_16 |= V_47 ;
}
void F_24 ( struct V_7 * V_8 )
{
struct V_48 * V_49 , * V_50 ;
if ( V_8 -> V_14 )
F_25 ( V_8 -> V_14 ) ;
if ( V_8 -> V_15 )
F_26 ( V_8 -> V_15 ) ;
F_27 (key_sig, key_sig_tmp,
&crypt_stat->keysig_list, crypt_stat_list) {
F_28 ( & V_49 -> V_51 ) ;
F_29 ( V_52 , V_49 ) ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
}
void F_30 (
struct V_53 * V_54 )
{
struct V_55 * V_56 , * V_57 ;
if ( ! ( V_54 -> V_16 & V_58 ) )
return;
F_5 ( & V_54 -> V_59 ) ;
F_27 (auth_tok, auth_tok_tmp,
&mount_crypt_stat->global_auth_tok_list,
mount_crypt_stat_list) {
F_28 ( & V_56 -> V_60 ) ;
if ( V_56 -> V_61
&& ! ( V_56 -> V_16 & V_62 ) )
F_31 ( V_56 -> V_61 ) ;
F_29 ( V_63 , V_56 ) ;
}
F_15 ( & V_54 -> V_59 ) ;
memset ( V_54 , 0 , sizeof( struct V_53 ) ) ;
}
int F_32 ( const void * V_64 , int V_65 , struct V_10 * V_11 ,
int V_66 )
{
int V_67 = 0 ;
struct V_68 * V_69 ;
int V_35 ;
int V_70 ;
F_33 ( V_11 , V_66 ) ;
while ( V_65 > 0 && V_67 < V_66 ) {
V_69 = F_34 ( V_64 ) ;
V_35 = F_35 ( V_64 ) ;
F_36 ( & V_11 [ V_67 ] , V_69 , 0 , V_35 ) ;
V_70 = V_71 - V_35 ;
if ( V_65 >= V_70 ) {
V_11 [ V_67 ] . V_72 = V_70 ;
V_64 += V_70 ;
V_65 -= V_70 ;
} else {
V_11 [ V_67 ] . V_72 = V_65 ;
V_64 += V_65 ;
V_65 = 0 ;
}
V_67 ++ ;
}
if ( V_65 > 0 )
return - V_33 ;
return V_67 ;
}
static void F_37 ( struct V_73 * V_74 , int V_18 )
{
struct V_75 * V_76 = V_74 -> V_77 ;
if ( V_18 == - V_78 )
return;
V_76 -> V_18 = V_18 ;
F_38 ( & V_76 -> V_79 ) ;
}
static int F_39 ( struct V_7 * V_8 ,
struct V_10 * V_80 ,
struct V_10 * V_81 , int V_65 ,
unsigned char * V_34 )
{
struct V_82 * V_74 = NULL ;
struct V_75 V_76 ;
int V_18 = 0 ;
F_40 ( ! V_8 || ! V_8 -> V_14
|| ! ( V_8 -> V_16 & V_47 ) ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_14 ,
V_8 -> V_83 ) ;
F_20 ( V_8 -> V_84 ,
V_8 -> V_83 ) ;
}
F_41 ( & V_76 . V_79 ) ;
F_5 ( & V_8 -> V_46 ) ;
V_74 = F_42 ( V_8 -> V_14 , V_85 ) ;
if ( ! V_74 ) {
F_15 ( & V_8 -> V_46 ) ;
V_18 = - V_33 ;
goto V_24;
}
F_43 ( V_74 ,
V_86 | V_17 ,
F_37 , & V_76 ) ;
if ( ! ( V_8 -> V_16 & V_87 ) ) {
V_18 = F_44 ( V_8 -> V_14 , V_8 -> V_84 ,
V_8 -> V_83 ) ;
if ( V_18 ) {
F_10 ( V_23 ,
L_15 ,
V_18 ) ;
F_15 ( & V_8 -> V_46 ) ;
V_18 = - V_88 ;
goto V_24;
}
V_8 -> V_16 |= V_87 ;
}
F_15 ( & V_8 -> V_46 ) ;
F_10 ( V_39 , L_16 , V_65 ) ;
F_45 ( V_74 , V_81 , V_80 , V_65 , V_34 ) ;
V_18 = F_46 ( V_74 ) ;
if ( V_18 == - V_78 || V_18 == - V_89 ) {
struct V_75 * V_76 = V_74 -> V_90 . V_77 ;
F_47 ( & V_76 -> V_79 ) ;
V_18 = V_76 -> V_18 ;
F_48 ( V_76 -> V_79 ) ;
}
V_24:
F_49 ( V_74 ) ;
return V_18 ;
}
static void F_50 ( T_2 * V_35 , T_2 V_91 ,
struct V_7 * V_8 )
{
( * V_35 ) = F_51 ( V_8 )
+ ( V_8 -> V_92 * V_91 ) ;
}
static int F_52 ( struct V_68 * V_93 ,
struct V_7 * V_8 ,
struct V_68 * V_68 ,
unsigned long V_94 )
{
T_2 V_95 ;
char V_96 [ V_37 ] ;
int V_18 ;
V_95 = ( ( ( T_2 ) V_68 -> V_97 )
* ( V_71 / V_8 -> V_92 ) ) ;
V_18 = F_18 ( V_96 , V_8 ,
( V_95 + V_94 ) ) ;
if ( V_18 ) {
F_10 ( V_23 , L_17
L_18 ,
( unsigned long long ) ( V_95 + V_94 ) , V_18 ) ;
goto V_24;
}
V_18 = F_53 ( V_8 , V_93 , 0 ,
V_68 , ( V_94
* V_8 -> V_92 ) ,
V_8 -> V_92 , V_96 ) ;
if ( V_18 < 0 ) {
F_12 ( V_23 L_19
L_20
L_21 , V_25 , V_68 -> V_97 , V_94 ,
V_18 ) ;
goto V_24;
}
V_18 = 0 ;
V_24:
return V_18 ;
}
int F_54 ( struct V_68 * V_68 )
{
struct V_98 * V_99 ;
struct V_7 * V_8 ;
char * V_100 ;
struct V_68 * V_93 = NULL ;
T_2 V_94 ;
int V_18 = 0 ;
V_99 = V_68 -> V_101 -> V_102 ;
V_8 =
& ( F_55 ( V_99 ) -> V_8 ) ;
F_40 ( ! ( V_8 -> V_16 & V_103 ) ) ;
V_93 = F_56 ( V_104 ) ;
if ( ! V_93 ) {
V_18 = - V_33 ;
F_10 ( V_23 , L_22
L_23 ) ;
goto V_24;
}
V_100 = F_57 ( V_93 ) ;
for ( V_94 = 0 ;
V_94 < ( V_71 / V_8 -> V_92 ) ;
V_94 ++ ) {
T_2 V_35 ;
V_18 = F_52 ( V_93 , V_8 , V_68 ,
V_94 ) ;
if ( V_18 ) {
F_12 ( V_23 L_24
L_21 , V_25 , V_18 ) ;
goto V_24;
}
F_50 (
& V_35 , ( ( ( ( T_2 ) V_68 -> V_97 )
* ( V_71
/ V_8 -> V_92 ) )
+ V_94 ) , V_8 ) ;
V_18 = F_58 ( V_99 , V_100 ,
V_35 , V_8 -> V_92 ) ;
if ( V_18 < 0 ) {
F_10 ( V_23 , L_25
L_26
L_27 , V_18 ) ;
goto V_24;
}
}
V_18 = 0 ;
V_24:
if ( V_93 ) {
F_59 ( V_93 ) ;
F_60 ( V_93 ) ;
}
return V_18 ;
}
static int F_61 ( struct V_68 * V_68 ,
struct V_7 * V_8 ,
struct V_68 * V_93 ,
unsigned long V_94 )
{
T_2 V_95 ;
char V_96 [ V_37 ] ;
int V_18 ;
V_95 = ( ( ( T_2 ) V_68 -> V_97 )
* ( V_71 / V_8 -> V_92 ) ) ;
V_18 = F_18 ( V_96 , V_8 ,
( V_95 + V_94 ) ) ;
if ( V_18 ) {
F_10 ( V_23 , L_17
L_18 ,
( unsigned long long ) ( V_95 + V_94 ) , V_18 ) ;
goto V_24;
}
V_18 = F_62 ( V_8 , V_68 ,
( V_94
* V_8 -> V_92 ) ,
V_93 , 0 ,
V_8 -> V_92 , V_96 ) ;
if ( V_18 < 0 ) {
F_12 ( V_23 L_28
L_20
L_21 , V_25 , V_68 -> V_97 , V_94 ,
V_18 ) ;
goto V_24;
}
V_18 = 0 ;
V_24:
return V_18 ;
}
int F_63 ( struct V_68 * V_68 )
{
struct V_98 * V_99 ;
struct V_7 * V_8 ;
char * V_100 ;
struct V_68 * V_93 = NULL ;
unsigned long V_94 ;
int V_18 = 0 ;
V_99 = V_68 -> V_101 -> V_102 ;
V_8 =
& ( F_55 ( V_99 ) -> V_8 ) ;
F_40 ( ! ( V_8 -> V_16 & V_103 ) ) ;
V_93 = F_56 ( V_104 ) ;
if ( ! V_93 ) {
V_18 = - V_33 ;
F_10 ( V_23 , L_22
L_23 ) ;
goto V_24;
}
V_100 = F_57 ( V_93 ) ;
for ( V_94 = 0 ;
V_94 < ( V_71 / V_8 -> V_92 ) ;
V_94 ++ ) {
T_2 V_35 ;
F_50 (
& V_35 , ( ( V_68 -> V_97 * ( V_71
/ V_8 -> V_92 ) )
+ V_94 ) , V_8 ) ;
V_18 = F_64 ( V_100 , V_35 ,
V_8 -> V_92 ,
V_99 ) ;
if ( V_18 < 0 ) {
F_10 ( V_23 , L_25
L_29
L_27 , V_18 ) ;
goto V_24;
}
V_18 = F_61 ( V_68 , V_8 , V_93 ,
V_94 ) ;
if ( V_18 ) {
F_12 ( V_23 L_24
L_21 , V_25 , V_18 ) ;
goto V_24;
}
}
V_24:
if ( V_93 ) {
F_59 ( V_93 ) ;
F_60 ( V_93 ) ;
}
return V_18 ;
}
static int F_65 ( struct V_7 * V_8 ,
struct V_10 * V_80 ,
struct V_10 * V_81 , int V_65 ,
unsigned char * V_34 )
{
struct V_82 * V_74 = NULL ;
struct V_75 V_76 ;
int V_18 = 0 ;
F_40 ( ! V_8 || ! V_8 -> V_14
|| ! ( V_8 -> V_16 & V_47 ) ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_14 ,
V_8 -> V_83 ) ;
F_20 ( V_8 -> V_84 ,
V_8 -> V_83 ) ;
}
F_41 ( & V_76 . V_79 ) ;
F_5 ( & V_8 -> V_46 ) ;
V_74 = F_42 ( V_8 -> V_14 , V_85 ) ;
if ( ! V_74 ) {
F_15 ( & V_8 -> V_46 ) ;
V_18 = - V_33 ;
goto V_24;
}
F_43 ( V_74 ,
V_86 | V_17 ,
F_37 , & V_76 ) ;
if ( ! ( V_8 -> V_16 & V_87 ) ) {
V_18 = F_44 ( V_8 -> V_14 , V_8 -> V_84 ,
V_8 -> V_83 ) ;
if ( V_18 ) {
F_10 ( V_23 ,
L_15 ,
V_18 ) ;
F_15 ( & V_8 -> V_46 ) ;
V_18 = - V_88 ;
goto V_24;
}
V_8 -> V_16 |= V_87 ;
}
F_15 ( & V_8 -> V_46 ) ;
F_10 ( V_39 , L_30 , V_65 ) ;
F_45 ( V_74 , V_81 , V_80 , V_65 , V_34 ) ;
V_18 = F_66 ( V_74 ) ;
if ( V_18 == - V_78 || V_18 == - V_89 ) {
struct V_75 * V_76 = V_74 -> V_90 . V_77 ;
F_47 ( & V_76 -> V_79 ) ;
V_18 = V_76 -> V_18 ;
F_48 ( V_76 -> V_79 ) ;
}
V_24:
F_49 ( V_74 ) ;
return V_18 ;
}
static int
F_53 ( struct V_7 * V_8 ,
struct V_68 * V_105 , int V_106 ,
struct V_68 * V_107 , int V_108 , int V_65 ,
unsigned char * V_34 )
{
struct V_10 V_81 , V_109 ;
F_33 ( & V_81 , 1 ) ;
F_33 ( & V_109 , 1 ) ;
F_36 ( & V_81 , V_107 , V_65 , V_108 ) ;
F_36 ( & V_109 , V_105 , V_65 , V_106 ) ;
return F_39 ( V_8 , & V_109 , & V_81 , V_65 , V_34 ) ;
}
static int
F_62 ( struct V_7 * V_8 ,
struct V_68 * V_105 , int V_106 ,
struct V_68 * V_107 , int V_108 , int V_65 ,
unsigned char * V_34 )
{
struct V_10 V_81 , V_109 ;
F_33 ( & V_81 , 1 ) ;
F_36 ( & V_81 , V_107 , V_65 , V_108 ) ;
F_33 ( & V_109 , 1 ) ;
F_36 ( & V_109 , V_105 , V_65 , V_106 ) ;
return F_65 ( V_8 , & V_109 , & V_81 , V_65 , V_34 ) ;
}
int F_67 ( struct V_7 * V_8 )
{
char * V_110 ;
int V_18 = - V_88 ;
if ( ! V_8 -> V_111 ) {
F_10 ( V_23 , L_31 ) ;
goto V_24;
}
F_10 ( V_39 ,
L_32
L_33 ,
V_8 -> V_111 , ( int ) strlen ( V_8 -> V_111 ) ,
V_8 -> V_83 << 3 ) ;
if ( V_8 -> V_14 ) {
V_18 = 0 ;
goto V_24;
}
F_5 ( & V_8 -> V_46 ) ;
V_18 = F_16 ( & V_110 ,
V_8 -> V_111 , L_34 ) ;
if ( V_18 )
goto V_112;
V_8 -> V_14 = F_68 ( V_110 , 0 , 0 ) ;
F_69 ( V_110 ) ;
if ( F_8 ( V_8 -> V_14 ) ) {
V_18 = F_9 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
F_10 ( V_23 , L_35
L_36 ,
V_8 -> V_111 ) ;
goto V_112;
}
F_70 ( V_8 -> V_14 , V_113 ) ;
V_18 = 0 ;
V_112:
F_15 ( & V_8 -> V_46 ) ;
V_24:
return V_18 ;
}
static void F_71 ( struct V_7 * V_8 )
{
int V_114 ;
V_8 -> V_115 = 0xFFFFFFFF ;
V_8 -> V_116 = 0 ;
if ( V_8 -> V_92 == 0 )
return;
V_114 = V_8 -> V_92 ;
while ( ( V_114 & 0x01 ) == 0 ) {
V_114 >>= 1 ;
V_8 -> V_115 <<= 1 ;
V_8 -> V_116 ++ ;
}
}
void F_72 ( struct V_7 * V_8 )
{
V_8 -> V_92 = V_117 ;
F_71 ( V_8 ) ;
V_8 -> V_41 = V_118 ;
if ( V_8 -> V_16 & V_119 )
V_8 -> V_120 = V_121 ;
else {
if ( V_71 <= V_121 )
V_8 -> V_120 =
V_121 ;
else
V_8 -> V_120 = V_71 ;
}
}
int F_73 ( struct V_7 * V_8 )
{
int V_18 = 0 ;
char V_1 [ V_36 ] ;
F_40 ( V_8 -> V_41 > V_36 ) ;
F_40 ( V_8 -> V_41 <= 0 ) ;
if ( ! ( V_8 -> V_16 & V_122 ) ) {
V_18 = - V_88 ;
F_10 ( V_42 , L_37
L_38 ) ;
goto V_24;
}
V_18 = F_4 ( V_1 , V_8 , V_8 -> V_84 ,
V_8 -> V_83 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_11
L_39 ) ;
goto V_24;
}
memcpy ( V_8 -> V_40 , V_1 , V_8 -> V_41 ) ;
V_24:
if ( V_18 ) {
memset ( V_8 -> V_40 , 0 , V_8 -> V_41 ) ;
V_8 -> V_16 |= V_123 ;
}
return V_18 ;
}
static void F_74 ( struct V_7 * V_8 )
{
F_75 ( V_8 -> V_84 , V_8 -> V_83 ) ;
V_8 -> V_16 |= V_122 ;
F_73 ( V_8 ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_40 ) ;
F_20 ( V_8 -> V_84 ,
V_8 -> V_83 ) ;
}
}
static void F_76 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
if ( V_54 -> V_16 & V_124 )
V_8 -> V_16 |= V_119 ;
if ( V_54 -> V_16 & V_125 )
V_8 -> V_16 |= V_126 ;
if ( V_54 -> V_16 & V_127 ) {
V_8 -> V_16 |= V_128 ;
if ( V_54 -> V_16
& V_129 )
V_8 -> V_16 |= V_130 ;
else if ( V_54 -> V_16
& V_131 )
V_8 -> V_16 |= V_132 ;
}
}
static int F_77 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
struct V_55 * V_133 ;
int V_18 = 0 ;
F_5 ( & V_8 -> V_44 ) ;
F_5 ( & V_54 -> V_59 ) ;
F_78 (global_auth_tok,
&mount_crypt_stat->global_auth_tok_list,
mount_crypt_stat_list) {
if ( V_133 -> V_16 & V_134 )
continue;
V_18 = F_79 ( V_8 , V_133 -> V_135 ) ;
if ( V_18 ) {
F_12 ( V_23 L_41 , V_18 ) ;
goto V_24;
}
}
V_24:
F_15 ( & V_54 -> V_59 ) ;
F_15 ( & V_8 -> V_44 ) ;
return V_18 ;
}
static void F_80 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
F_76 ( V_8 ,
V_54 ) ;
F_72 ( V_8 ) ;
strcpy ( V_8 -> V_111 , V_136 ) ;
V_8 -> V_83 = V_137 ;
V_8 -> V_16 &= ~ ( V_122 ) ;
V_8 -> V_138 = V_139 ;
V_8 -> V_54 = V_54 ;
}
int F_81 ( struct V_98 * V_99 )
{
struct V_7 * V_8 =
& F_55 ( V_99 ) -> V_8 ;
struct V_53 * V_54 =
& F_82 (
V_99 -> V_140 ) -> V_54 ;
int V_29 ;
int V_18 = 0 ;
F_80 ( V_8 , V_54 ) ;
V_8 -> V_16 |= ( V_103 | V_122 ) ;
F_76 ( V_8 ,
V_54 ) ;
V_18 = F_77 ( V_8 ,
V_54 ) ;
if ( V_18 ) {
F_12 ( V_23 L_42
L_43 , V_18 ) ;
goto V_24;
}
V_29 =
strlen ( V_54 -> V_141 ) ;
memcpy ( V_8 -> V_111 ,
V_54 -> V_141 ,
V_29 ) ;
V_8 -> V_111 [ V_29 ] = '\0' ;
V_8 -> V_83 =
V_54 -> V_142 ;
F_74 ( V_8 ) ;
V_18 = F_67 ( V_8 ) ;
if ( V_18 )
F_10 ( V_23 , L_44
L_45 ,
V_8 -> V_111 , V_18 ) ;
V_24:
return V_18 ;
}
static int F_83 ( char * V_77 )
{
T_3 V_143 , V_144 ;
V_143 = F_84 ( V_77 ) ;
V_144 = F_84 ( V_77 + 4 ) ;
if ( ( V_143 ^ V_145 ) == V_144 )
return 0 ;
F_10 ( V_39 , L_46
L_47 , V_143 , V_144 ,
V_145 ) ;
F_10 ( V_39 , L_48
L_49 , ( V_143 ^ V_145 ) ) ;
return - V_88 ;
}
static int F_85 ( struct V_7 * V_8 ,
char * V_146 , int * V_147 )
{
int V_18 = 0 ;
int V_67 ;
T_3 V_16 ;
V_16 = F_84 ( V_146 ) ;
for ( V_67 = 0 ; V_67 < ( ( sizeof( V_148 )
/ sizeof( struct V_149 ) ) ) ; V_67 ++ )
if ( V_16 & V_148 [ V_67 ] . V_150 ) {
V_8 -> V_16 |= V_148 [ V_67 ] . V_151 ;
} else
V_8 -> V_16 &= ~ ( V_148 [ V_67 ] . V_151 ) ;
V_8 -> V_138 = ( ( V_16 >> 24 ) & 0xFF ) ;
( * V_147 ) = 4 ;
return V_18 ;
}
static void F_86 ( char * V_146 , T_1 * V_152 )
{
T_3 V_143 , V_144 ;
F_75 ( & V_143 , ( V_153 / 2 ) ) ;
V_144 = ( V_143 ^ V_145 ) ;
F_87 ( V_143 , V_146 ) ;
V_146 += ( V_153 / 2 ) ;
F_87 ( V_144 , V_146 ) ;
( * V_152 ) = V_153 ;
}
void F_88 ( char * V_146 ,
struct V_7 * V_8 ,
T_1 * V_152 )
{
T_3 V_16 = 0 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < ( ( sizeof( V_148 )
/ sizeof( struct V_149 ) ) ) ; V_67 ++ )
if ( V_8 -> V_16 & V_148 [ V_67 ] . V_151 )
V_16 |= V_148 [ V_67 ] . V_150 ;
V_16 |= ( ( ( ( V_20 ) V_8 -> V_138 ) << 24 ) & 0xFF000000 ) ;
F_87 ( V_16 , V_146 ) ;
( * V_152 ) = 4 ;
}
V_20 F_89 ( char * V_27 , T_1 V_154 )
{
int V_67 ;
V_20 V_155 = 0 ;
struct V_156 * V_157 =
V_158 ;
if ( strcmp ( V_27 , L_50 ) == 0 ) {
switch ( V_154 ) {
case 16 :
V_155 = V_159 ;
break;
case 24 :
V_155 = V_160 ;
break;
case 32 :
V_155 = V_161 ;
}
} else {
for ( V_67 = 0 ; V_67 < F_90 ( V_158 ) ; V_67 ++ )
if ( strcmp ( V_27 , V_157 [ V_67 ] . V_162 ) == 0 ) {
V_155 = V_157 [ V_67 ] . V_163 ;
break;
}
}
return V_155 ;
}
int F_91 ( char * V_164 , V_20 V_163 )
{
int V_18 = 0 ;
int V_67 ;
V_164 [ 0 ] = '\0' ;
for ( V_67 = 0 ; V_67 < F_90 ( V_158 ) ; V_67 ++ )
if ( V_163 == V_158 [ V_67 ] . V_163 )
strcpy ( V_164 , V_158 [ V_67 ] . V_162 ) ;
if ( V_164 [ 0 ] == '\0' ) {
F_10 ( V_42 , L_51
L_52 , V_163 ) ;
V_18 = - V_88 ;
}
return V_18 ;
}
int F_92 ( struct V_98 * V_98 )
{
V_20 V_165 [ V_166 ] ;
V_20 * V_167 = V_165 + V_168 ;
int V_18 ;
V_18 = F_64 ( V_165 , 0 , V_166 ,
V_98 ) ;
if ( V_18 < V_166 )
return V_18 >= 0 ? - V_88 : V_18 ;
V_18 = F_83 ( V_167 ) ;
if ( ! V_18 )
F_93 ( V_165 , V_98 ) ;
return V_18 ;
}
void
F_94 ( char * V_169 ,
struct V_7 * V_8 ,
T_1 * V_152 )
{
T_3 V_170 ;
T_4 V_171 ;
V_170 = ( T_3 ) V_8 -> V_92 ;
V_171 =
( T_4 ) ( V_8 -> V_120 / V_8 -> V_92 ) ;
F_87 ( V_170 , V_169 ) ;
V_169 += 4 ;
F_95 ( V_171 , V_169 ) ;
( * V_152 ) = 6 ;
}
static int F_96 ( char * V_146 , T_1 V_172 ,
T_1 * V_65 ,
struct V_7 * V_8 ,
struct V_173 * V_174 )
{
int V_18 ;
T_1 V_152 ;
T_1 V_35 ;
V_35 = V_168 ;
F_86 ( ( V_146 + V_35 ) , & V_152 ) ;
V_35 += V_152 ;
F_88 ( ( V_146 + V_35 ) , V_8 ,
& V_152 ) ;
V_35 += V_152 ;
F_94 ( ( V_146 + V_35 ) , V_8 ,
& V_152 ) ;
V_35 += V_152 ;
V_18 = F_97 ( ( V_146 + V_35 ) , V_8 ,
V_174 , & V_152 ,
V_172 - V_35 ) ;
if ( V_18 )
F_10 ( V_42 , L_53
L_54 , V_18 ) ;
if ( V_65 ) {
V_35 += V_152 ;
* V_65 = V_35 ;
}
return V_18 ;
}
static int
F_98 ( struct V_98 * V_99 ,
char * V_169 , T_1 V_175 )
{
int V_18 ;
V_18 = F_58 ( V_99 , V_169 ,
0 , V_175 ) ;
if ( V_18 < 0 )
F_12 ( V_23 L_55
L_56 , V_25 , V_18 ) ;
else
V_18 = 0 ;
return V_18 ;
}
static int
F_99 ( struct V_173 * V_174 ,
char * V_146 , T_1 V_65 )
{
int V_18 ;
V_18 = F_100 ( V_174 , V_176 , V_146 ,
V_65 , 0 ) ;
return V_18 ;
}
static unsigned long F_101 ( T_5 V_177 ,
unsigned int V_178 )
{
struct V_68 * V_68 ;
V_68 = F_102 ( V_177 | V_179 , V_178 ) ;
if ( V_68 )
return ( unsigned long ) F_103 ( V_68 ) ;
return 0 ;
}
int F_104 ( struct V_173 * V_174 ,
struct V_98 * V_99 )
{
struct V_7 * V_8 =
& F_55 ( V_99 ) -> V_8 ;
unsigned int V_178 ;
char * V_169 ;
T_1 V_175 ;
T_1 V_65 = 0 ;
int V_18 = 0 ;
if ( F_105 ( V_8 -> V_16 & V_103 ) ) {
if ( ! ( V_8 -> V_16 & V_122 ) ) {
F_12 ( V_23 L_57 ) ;
V_18 = - V_88 ;
goto V_24;
}
} else {
F_12 ( V_42 L_58 ,
V_25 ) ;
V_18 = - V_88 ;
goto V_24;
}
V_175 = V_8 -> V_120 ;
V_178 = F_106 ( V_175 ) ;
V_169 = ( char * ) F_101 ( V_32 , V_178 ) ;
if ( ! V_169 ) {
F_12 ( V_23 L_59 , V_25 ) ;
V_18 = - V_33 ;
goto V_24;
}
V_18 = F_96 ( V_169 , V_175 , & V_65 , V_8 ,
V_174 ) ;
if ( F_19 ( V_18 ) ) {
F_12 ( V_23 L_60 ,
V_25 , V_18 ) ;
goto V_180;
}
if ( V_8 -> V_16 & V_119 )
V_18 = F_99 ( V_174 , V_169 ,
V_65 ) ;
else
V_18 = F_98 ( V_99 , V_169 ,
V_175 ) ;
if ( V_18 ) {
F_12 ( V_23 L_61
L_21 , V_25 , V_18 ) ;
goto V_180;
}
V_180:
F_107 ( ( unsigned long ) V_169 , V_178 ) ;
V_24:
return V_18 ;
}
static int F_108 ( struct V_7 * V_8 ,
char * V_169 , int * V_147 ,
int V_181 )
{
int V_18 = 0 ;
T_3 V_170 ;
T_4 V_171 ;
V_170 = F_84 ( V_169 ) ;
V_169 += sizeof( V_182 ) ;
V_171 = F_109 ( V_169 ) ;
V_8 -> V_120 = ( ( ( T_1 ) V_171
* ( T_1 ) V_170 ) ) ;
( * V_147 ) = ( sizeof( V_182 ) + sizeof( V_183 ) ) ;
if ( ( V_181 == V_184 )
&& ( V_8 -> V_120
< V_121 ) ) {
V_18 = - V_88 ;
F_12 ( V_42 L_62 ,
V_8 -> V_120 ) ;
}
return V_18 ;
}
static void F_110 ( struct V_7 * V_8 )
{
V_8 -> V_120 = V_121 ;
}
void F_93 ( const char * V_146 , struct V_98 * V_98 )
{
struct V_53 * V_54 ;
struct V_7 * V_8 ;
T_6 V_165 ;
V_8 = & F_55 ( V_98 ) -> V_8 ;
V_54 =
& F_82 ( V_98 -> V_140 ) -> V_54 ;
if ( V_54 -> V_16 & V_125 ) {
V_165 = F_111 ( F_112 ( V_98 ) ) ;
if ( V_8 -> V_16 & V_119 )
V_165 += V_8 -> V_120 ;
} else
V_165 = F_113 ( V_146 ) ;
F_114 ( V_98 , ( T_2 ) V_165 ) ;
V_8 -> V_16 |= V_185 ;
}
static int F_115 ( char * V_146 ,
struct V_7 * V_8 ,
struct V_173 * V_174 ,
int V_181 )
{
int V_18 = 0 ;
int V_35 ;
int V_147 ;
F_72 ( V_8 ) ;
V_8 -> V_54 = & F_82 (
V_174 -> V_186 ) -> V_54 ;
V_35 = V_168 ;
V_18 = F_83 ( V_146 + V_35 ) ;
if ( V_18 )
goto V_24;
if ( ! ( V_8 -> V_16 & V_185 ) )
F_93 ( V_146 , V_174 -> V_187 ) ;
V_35 += V_153 ;
V_18 = F_85 ( V_8 , ( V_146 + V_35 ) ,
& V_147 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_63 ) ;
goto V_24;
}
if ( V_8 -> V_138 > V_188 ) {
F_10 ( V_42 , L_64
L_65
L_66 ,
V_8 -> V_138 ,
V_188 ) ;
V_18 = - V_88 ;
goto V_24;
}
V_35 += V_147 ;
if ( V_8 -> V_138 >= 1 ) {
V_18 = F_108 ( V_8 , ( V_146 + V_35 ) ,
& V_147 , V_181 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_67
L_68 , V_18 ) ;
}
V_35 += V_147 ;
} else
F_110 ( V_8 ) ;
V_18 = F_116 ( V_8 , ( V_146 + V_35 ) ,
V_174 ) ;
V_24:
return V_18 ;
}
int F_117 ( char * V_146 , struct V_98 * V_99 )
{
struct V_173 * V_189 =
F_55 ( V_99 ) -> V_190 -> V_191 ;
T_7 V_65 ;
int V_18 = 0 ;
V_65 = F_118 ( V_189 , V_176 ,
V_146 , V_117 ) ;
if ( V_65 < 0 ) {
if ( F_19 ( V_38 > 0 ) )
F_12 ( V_192 L_69
L_70
L_71 , V_176 , V_65 ) ;
V_18 = - V_88 ;
goto V_24;
}
V_24:
return V_18 ;
}
int F_119 ( struct V_173 * V_173 ,
struct V_98 * V_98 )
{
V_20 V_165 [ V_166 ] ;
V_20 * V_167 = V_165 + V_168 ;
int V_18 ;
V_18 = F_118 ( F_120 ( V_173 ) ,
V_176 , V_165 ,
V_166 ) ;
if ( V_18 < V_166 )
return V_18 >= 0 ? - V_88 : V_18 ;
V_18 = F_83 ( V_167 ) ;
if ( ! V_18 )
F_93 ( V_165 , V_98 ) ;
return V_18 ;
}
int F_121 ( struct V_173 * V_174 )
{
int V_18 ;
char * V_146 ;
struct V_98 * V_99 = V_174 -> V_187 ;
struct V_7 * V_8 =
& F_55 ( V_99 ) -> V_8 ;
struct V_53 * V_54 =
& F_82 (
V_174 -> V_186 ) -> V_54 ;
F_76 ( V_8 ,
V_54 ) ;
V_146 = F_122 ( V_193 , V_104 ) ;
if ( ! V_146 ) {
V_18 = - V_33 ;
F_12 ( V_23 L_72 ,
V_25 ) ;
goto V_24;
}
V_18 = F_64 ( V_146 , 0 , V_8 -> V_92 ,
V_99 ) ;
if ( V_18 >= 0 )
V_18 = F_115 ( V_146 , V_8 ,
V_174 ,
V_184 ) ;
if ( V_18 ) {
memset ( V_146 , 0 , V_71 ) ;
V_18 = F_117 ( V_146 , V_99 ) ;
if ( V_18 ) {
F_12 ( V_39 L_73
L_74 ,
V_99 -> V_194 ) ;
V_18 = - V_88 ;
goto V_24;
}
V_18 = F_115 ( V_146 , V_8 ,
V_174 ,
V_195 ) ;
if ( V_18 ) {
F_12 ( V_39 L_73
L_75 ,
V_99 -> V_194 ) ;
V_18 = - V_88 ;
}
if ( V_8 -> V_54 -> V_16
& V_124 ) {
V_8 -> V_16 |= V_119 ;
} else {
F_12 ( V_42 L_76
L_77
L_78
L_79
L_80 ,
V_99 -> V_194 ) ;
V_18 = - V_88 ;
}
}
V_24:
if ( V_146 ) {
memset ( V_146 , 0 , V_71 ) ;
F_29 ( V_193 , V_146 ) ;
}
return V_18 ;
}
static int
F_123 ( struct V_196 * V_197 ,
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
int V_18 = 0 ;
V_197 -> V_198 = NULL ;
V_197 -> V_199 = 0 ;
if ( ( V_8 && ( V_8 -> V_16 & V_130 ) )
|| ( V_54 && ( V_54 -> V_16
& V_129 ) ) ) {
T_1 V_200 ;
T_1 V_201 ;
V_18 = F_124 (
NULL , NULL ,
& V_197 -> V_199 ,
V_54 , NULL ,
V_197 -> V_202 ) ;
if ( V_18 ) {
F_12 ( V_23 L_81
L_82 , V_25 ,
V_18 ) ;
V_197 -> V_199 = 0 ;
goto V_24;
}
V_197 -> V_198 =
F_17 ( V_197 -> V_199 , V_32 ) ;
if ( ! V_197 -> V_198 ) {
F_12 ( V_23 L_83
L_84 , V_25 ,
V_197 -> V_199 ) ;
V_18 = - V_33 ;
goto V_24;
}
V_201 = V_197 -> V_199 ;
V_18 = F_124 ( V_197 -> V_198 ,
& V_201 ,
& V_200 ,
V_54 ,
V_197 -> V_197 ,
V_197 -> V_202 ) ;
if ( V_18 ) {
F_12 ( V_23 L_85
L_86 , V_25 ,
V_18 ) ;
F_69 ( V_197 -> V_198 ) ;
V_197 -> V_198 = NULL ;
V_197 -> V_199 = 0 ;
goto V_24;
}
V_197 -> V_199 = V_200 ;
} else {
F_12 ( V_23 L_87
L_88 , V_25 ) ;
V_18 = - V_203 ;
goto V_24;
}
V_24:
return V_18 ;
}
static int F_125 ( char * * V_204 , T_1 * V_205 ,
const char * V_206 , T_1 V_207 )
{
int V_18 = 0 ;
( * V_204 ) = F_17 ( ( V_207 + 1 ) , V_32 ) ;
if ( ! ( * V_204 ) ) {
V_18 = - V_33 ;
goto V_24;
}
memcpy ( ( void * ) ( * V_204 ) , ( void * ) V_206 , V_207 ) ;
( * V_204 ) [ ( V_207 ) ] = '\0' ;
( * V_205 ) = V_207 ;
V_24:
return V_18 ;
}
static int
F_126 ( struct V_208 * * V_209 ,
char * V_27 , T_1 * V_83 )
{
char V_210 [ V_211 ] ;
char * V_110 = NULL ;
int V_18 ;
* V_209 = NULL ;
if ( * V_83 > V_211 ) {
V_18 = - V_88 ;
F_12 ( V_23 L_89
L_90 , * V_83 , V_211 ) ;
goto V_24;
}
V_18 = F_16 ( & V_110 , V_27 ,
L_91 ) ;
if ( V_18 )
goto V_24;
* V_209 = F_127 ( V_110 , 0 , V_22 ) ;
if ( F_8 ( * V_209 ) ) {
V_18 = F_9 ( * V_209 ) ;
F_12 ( V_23 L_92
L_93 , V_110 , V_18 ) ;
goto V_24;
}
F_128 ( * V_209 , V_113 ) ;
if ( * V_83 == 0 ) {
struct V_212 * V_213 = F_129 ( * V_209 ) ;
* V_83 = V_213 -> V_214 ;
}
F_75 ( V_210 , * V_83 ) ;
V_18 = F_130 ( * V_209 , V_210 , * V_83 ) ;
if ( V_18 ) {
F_12 ( V_23 L_94
L_95 , * V_83 , V_110 ,
V_18 ) ;
V_18 = - V_88 ;
goto V_24;
}
V_24:
F_69 ( V_110 ) ;
return V_18 ;
}
int T_8 F_131 ( void )
{
F_23 ( & V_215 ) ;
F_22 ( & V_216 ) ;
return 0 ;
}
int F_132 ( void )
{
struct V_217 * V_209 , * V_218 ;
F_5 ( & V_215 ) ;
F_27 (key_tfm, key_tfm_tmp, &key_tfm_list,
key_tfm_list) {
F_28 ( & V_209 -> V_216 ) ;
if ( V_209 -> V_209 )
F_133 ( V_209 -> V_209 ) ;
F_29 ( V_219 , V_209 ) ;
}
F_15 ( & V_215 ) ;
return 0 ;
}
int
F_134 ( struct V_217 * * V_209 , char * V_27 ,
T_1 V_83 )
{
struct V_217 * V_220 ;
int V_18 = 0 ;
F_40 ( ! F_135 ( & V_215 ) ) ;
V_220 = F_122 ( V_219 , V_32 ) ;
if ( V_209 != NULL )
( * V_209 ) = V_220 ;
if ( ! V_220 ) {
V_18 = - V_33 ;
F_12 ( V_23 L_96
L_97 ) ;
goto V_24;
}
F_23 ( & V_220 -> V_221 ) ;
strncpy ( V_220 -> V_27 , V_27 ,
V_222 ) ;
V_220 -> V_27 [ V_222 ] = '\0' ;
V_220 -> V_83 = V_83 ;
V_18 = F_126 ( & V_220 -> V_209 ,
V_220 -> V_27 ,
& V_220 -> V_83 ) ;
if ( V_18 ) {
F_12 ( V_23 L_98
L_99 ,
V_220 -> V_27 , V_18 ) ;
F_29 ( V_219 , V_220 ) ;
if ( V_209 != NULL )
( * V_209 ) = NULL ;
goto V_24;
}
F_136 ( & V_220 -> V_216 , & V_216 ) ;
V_24:
return V_18 ;
}
int F_137 ( char * V_27 , struct V_217 * * V_209 )
{
struct V_217 * V_223 ;
F_40 ( ! F_135 ( & V_215 ) ) ;
F_78 (tmp_key_tfm, &key_tfm_list, key_tfm_list) {
if ( strcmp ( V_223 -> V_27 , V_27 ) == 0 ) {
if ( V_209 )
( * V_209 ) = V_223 ;
return 1 ;
}
}
if ( V_209 )
( * V_209 ) = NULL ;
return 0 ;
}
int F_138 ( struct V_208 * * V_14 ,
struct V_224 * * V_225 ,
char * V_27 )
{
struct V_217 * V_209 ;
int V_18 = 0 ;
( * V_14 ) = NULL ;
( * V_225 ) = NULL ;
F_5 ( & V_215 ) ;
if ( ! F_137 ( V_27 , & V_209 ) ) {
V_18 = F_134 ( & V_209 , V_27 , 0 ) ;
if ( V_18 ) {
F_12 ( V_23 L_100
L_21 , V_18 ) ;
goto V_24;
}
}
( * V_14 ) = V_209 -> V_209 ;
( * V_225 ) = & V_209 -> V_221 ;
V_24:
F_15 ( & V_215 ) ;
return V_18 ;
}
static void F_139 ( unsigned char * V_1 , T_1 * V_5 ,
unsigned char * V_2 , T_1 V_3 )
{
T_1 V_226 ;
T_1 V_227 = 0 ;
T_1 V_106 = 0 ;
unsigned char V_228 [ 3 ] ;
if ( V_3 == 0 ) {
( * V_5 ) = 0 ;
goto V_24;
}
V_226 = ( V_3 / 3 ) ;
if ( ( V_3 % 3 ) == 0 ) {
memcpy ( V_228 , ( & V_2 [ V_3 - 3 ] ) , 3 ) ;
} else {
V_226 ++ ;
V_228 [ 2 ] = 0x00 ;
switch ( V_3 % 3 ) {
case 1 :
V_228 [ 0 ] = V_2 [ V_3 - 1 ] ;
V_228 [ 1 ] = 0x00 ;
break;
case 2 :
V_228 [ 0 ] = V_2 [ V_3 - 2 ] ;
V_228 [ 1 ] = V_2 [ V_3 - 1 ] ;
}
}
( * V_5 ) = ( V_226 * 4 ) ;
if ( ! V_1 )
goto V_24;
while ( V_227 < V_226 ) {
unsigned char * V_229 ;
unsigned char V_230 [ 4 ] ;
if ( V_227 == ( V_226 - 1 ) )
V_229 = V_228 ;
else
V_229 = & V_2 [ V_227 * 3 ] ;
V_230 [ 0 ] = ( ( V_229 [ 0 ] >> 2 ) & 0x3F ) ;
V_230 [ 1 ] = ( ( ( V_229 [ 0 ] << 4 ) & 0x30 )
| ( ( V_229 [ 1 ] >> 4 ) & 0x0F ) ) ;
V_230 [ 2 ] = ( ( ( V_229 [ 1 ] << 2 ) & 0x3C )
| ( ( V_229 [ 2 ] >> 6 ) & 0x03 ) ) ;
V_230 [ 3 ] = ( V_229 [ 2 ] & 0x3F ) ;
V_1 [ V_106 ++ ] = V_231 [ V_230 [ 0 ] ] ;
V_1 [ V_106 ++ ] = V_231 [ V_230 [ 1 ] ] ;
V_1 [ V_106 ++ ] = V_231 [ V_230 [ 2 ] ] ;
V_1 [ V_106 ++ ] = V_231 [ V_230 [ 3 ] ] ;
V_227 ++ ;
}
V_24:
return;
}
static T_1 F_140 ( T_1 V_232 )
{
return ( ( V_232 + 1 ) * 3 ) / 4 ;
}
static void
F_141 ( unsigned char * V_1 , T_1 * V_5 ,
const unsigned char * V_2 , T_1 V_3 )
{
V_20 V_233 = 0 ;
T_1 V_234 = 0 ;
T_1 V_235 = 0 ;
if ( V_1 == NULL ) {
( * V_5 ) = F_140 ( V_3 ) ;
goto V_24;
}
while ( V_234 < V_3 ) {
unsigned char V_236 =
V_237 [ ( int ) V_2 [ V_234 ] ] ;
switch ( V_233 ) {
case 0 :
V_1 [ V_235 ] = ( V_236 << 2 ) ;
V_233 = 6 ;
break;
case 6 :
V_1 [ V_235 ++ ] |= ( V_236 >> 4 ) ;
V_1 [ V_235 ] = ( ( V_236 & 0xF )
<< 4 ) ;
V_233 = 4 ;
break;
case 4 :
V_1 [ V_235 ++ ] |= ( V_236 >> 2 ) ;
V_1 [ V_235 ] = ( V_236 << 6 ) ;
V_233 = 2 ;
break;
case 2 :
V_1 [ V_235 ++ ] |= ( V_236 ) ;
V_1 [ V_235 ] = 0 ;
V_233 = 0 ;
break;
}
V_234 ++ ;
}
( * V_5 ) = V_235 ;
V_24:
return;
}
int F_142 (
char * * V_238 ,
T_1 * V_239 ,
struct V_7 * V_8 ,
struct V_53 * V_54 ,
const char * V_206 , T_1 V_207 )
{
T_1 V_240 ;
int V_18 = 0 ;
( * V_238 ) = NULL ;
( * V_239 ) = 0 ;
if ( ( V_8 && ( V_8 -> V_16 & V_128 ) )
|| ( V_54 && ( V_54 -> V_16
& V_127 ) ) ) {
struct V_196 * V_197 ;
V_197 = F_143 ( sizeof( * V_197 ) , V_32 ) ;
if ( ! V_197 ) {
F_12 ( V_23 L_83
L_101 , V_25 ,
sizeof( * V_197 ) ) ;
V_18 = - V_33 ;
goto V_24;
}
V_197 -> V_197 = ( char * ) V_206 ;
V_197 -> V_202 = V_207 ;
V_18 = F_123 ( V_197 , V_8 ,
V_54 ) ;
if ( V_18 ) {
F_12 ( V_23 L_102
L_103 , V_25 , V_18 ) ;
F_69 ( V_197 ) ;
goto V_24;
}
F_139 (
NULL , & V_240 ,
V_197 -> V_198 ,
V_197 -> V_199 ) ;
if ( ( V_8 && ( V_8 -> V_16
& V_130 ) )
|| ( V_54
&& ( V_54 -> V_16
& V_129 ) ) )
( * V_239 ) =
( V_241
+ V_240 ) ;
else
( * V_239 ) =
( V_242
+ V_240 ) ;
( * V_238 ) = F_17 ( ( * V_239 ) + 1 , V_32 ) ;
if ( ! ( * V_238 ) ) {
F_12 ( V_23 L_83
L_101 , V_25 ,
( * V_239 ) ) ;
V_18 = - V_33 ;
F_69 ( V_197 -> V_198 ) ;
F_69 ( V_197 ) ;
goto V_24;
}
if ( ( V_8 && ( V_8 -> V_16
& V_130 ) )
|| ( V_54
&& ( V_54 -> V_16
& V_129 ) ) ) {
memcpy ( ( * V_238 ) ,
V_243 ,
V_241 ) ;
F_139 (
( ( * V_238 )
+ V_241 ) ,
& V_240 ,
V_197 -> V_198 ,
V_197 -> V_199 ) ;
( * V_239 ) =
( V_241
+ V_240 ) ;
( * V_238 ) [ ( * V_239 ) ] = '\0' ;
} else {
V_18 = - V_203 ;
}
if ( V_18 ) {
F_12 ( V_23 L_104
L_105 , V_25 ,
V_18 ) ;
F_69 ( ( * V_238 ) ) ;
( * V_238 ) = NULL ;
( * V_239 ) = 0 ;
}
F_69 ( V_197 -> V_198 ) ;
F_69 ( V_197 ) ;
} else {
V_18 = F_125 ( V_238 ,
V_239 ,
V_206 , V_207 ) ;
}
V_24:
return V_18 ;
}
int F_144 ( char * * V_244 ,
T_1 * V_245 ,
struct V_173 * V_246 ,
const char * V_206 , T_1 V_207 )
{
struct V_53 * V_54 =
& F_82 (
V_246 -> V_186 ) -> V_54 ;
char * V_247 ;
T_1 V_248 ;
T_1 V_200 ;
int V_18 = 0 ;
if ( ( V_54 -> V_16 & V_127 )
&& ! ( V_54 -> V_16 & V_125 )
&& ( V_207 > V_241 )
&& ( strncmp ( V_206 , V_243 ,
V_241 ) == 0 ) ) {
const char * V_249 = V_206 ;
T_1 V_250 = V_207 ;
V_206 += V_241 ;
V_207 -= V_241 ;
F_141 ( NULL , & V_248 ,
V_206 , V_207 ) ;
V_247 = F_17 ( V_248 , V_32 ) ;
if ( ! V_247 ) {
F_12 ( V_23 L_83
L_84 , V_25 ,
V_248 ) ;
V_18 = - V_33 ;
goto V_24;
}
F_141 ( V_247 , & V_248 ,
V_206 , V_207 ) ;
V_18 = F_145 ( V_244 ,
V_245 ,
& V_200 ,
V_54 ,
V_247 ,
V_248 ) ;
if ( V_18 ) {
F_12 ( V_192 L_106
L_107
L_108 , V_25 ) ;
V_18 = F_125 ( V_244 ,
V_245 ,
V_249 , V_250 ) ;
goto V_180;
}
} else {
V_18 = F_125 ( V_244 ,
V_245 ,
V_206 , V_207 ) ;
goto V_24;
}
V_180:
F_69 ( V_247 ) ;
V_24:
return V_18 ;
}
int F_146 ( long * V_251 , long V_252 ,
struct V_53 * V_54 )
{
struct V_253 V_13 ;
struct V_224 * V_225 ;
T_1 V_254 ;
int V_18 ;
if ( ! ( V_54 -> V_16 & V_127 ) ) {
( * V_251 ) = V_252 ;
return 0 ;
}
V_18 = F_138 ( & V_13 . V_14 , & V_225 ,
V_54 -> V_255 ) ;
if ( F_19 ( V_18 ) ) {
( * V_251 ) = 0 ;
return V_18 ;
}
F_5 ( V_225 ) ;
V_254 = F_147 ( V_13 . V_14 ) ;
F_15 ( V_225 ) ;
if ( V_252 == V_256
&& ( V_254 == 8 || V_254 == 16 ) ) {
( * V_251 ) = V_257 ;
return 0 ;
}
( * V_251 ) = V_252 ;
( * V_251 ) -= V_241 ;
( * V_251 ) = F_140 ( * V_251 ) - 3 ;
( * V_251 ) -= V_258 ;
( * V_251 ) -= V_259 ;
( * V_251 ) -= V_254 - 1 ;
if ( ( * V_251 ) < 0 )
( * V_251 ) = 0 ;
return 0 ;
}
