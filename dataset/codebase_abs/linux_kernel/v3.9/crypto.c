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
static int F_37 ( struct V_7 * V_8 ,
struct V_10 * V_73 ,
struct V_10 * V_74 , int V_65 ,
unsigned char * V_34 )
{
struct V_75 V_13 = {
. V_14 = V_8 -> V_14 ,
. V_76 = V_34 ,
. V_16 = V_17
} ;
int V_18 = 0 ;
F_38 ( ! V_8 || ! V_8 -> V_14
|| ! ( V_8 -> V_16 & V_47 ) ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_14 ,
V_8 -> V_77 ) ;
F_20 ( V_8 -> V_78 ,
V_8 -> V_77 ) ;
}
F_5 ( & V_8 -> V_46 ) ;
if ( ! ( V_8 -> V_16 & V_79 ) ) {
V_18 = F_39 ( V_8 -> V_14 , V_8 -> V_78 ,
V_8 -> V_77 ) ;
V_8 -> V_16 |= V_79 ;
}
if ( V_18 ) {
F_10 ( V_23 , L_15 ,
V_18 ) ;
F_15 ( & V_8 -> V_46 ) ;
V_18 = - V_80 ;
goto V_24;
}
F_10 ( V_39 , L_16 , V_65 ) ;
F_40 ( & V_13 , V_73 , V_74 , V_65 ) ;
F_15 ( & V_8 -> V_46 ) ;
V_24:
return V_18 ;
}
static void F_41 ( T_2 * V_35 , T_2 V_81 ,
struct V_7 * V_8 )
{
( * V_35 ) = F_42 ( V_8 )
+ ( V_8 -> V_82 * V_81 ) ;
}
static int F_43 ( struct V_68 * V_83 ,
struct V_7 * V_8 ,
struct V_68 * V_68 ,
unsigned long V_84 )
{
T_2 V_85 ;
char V_86 [ V_37 ] ;
int V_18 ;
V_85 = ( ( ( T_2 ) V_68 -> V_87 )
* ( V_71 / V_8 -> V_82 ) ) ;
V_18 = F_18 ( V_86 , V_8 ,
( V_85 + V_84 ) ) ;
if ( V_18 ) {
F_10 ( V_23 , L_17
L_18 ,
( unsigned long long ) ( V_85 + V_84 ) , V_18 ) ;
goto V_24;
}
V_18 = F_44 ( V_8 , V_83 , 0 ,
V_68 , ( V_84
* V_8 -> V_82 ) ,
V_8 -> V_82 , V_86 ) ;
if ( V_18 < 0 ) {
F_12 ( V_23 L_19
L_20
L_21 , V_25 , V_68 -> V_87 , V_84 ,
V_18 ) ;
goto V_24;
}
V_18 = 0 ;
V_24:
return V_18 ;
}
int F_45 ( struct V_68 * V_68 )
{
struct V_88 * V_89 ;
struct V_7 * V_8 ;
char * V_90 ;
struct V_68 * V_83 = NULL ;
T_2 V_84 ;
int V_18 = 0 ;
V_89 = V_68 -> V_91 -> V_92 ;
V_8 =
& ( F_46 ( V_89 ) -> V_8 ) ;
F_38 ( ! ( V_8 -> V_16 & V_93 ) ) ;
V_83 = F_47 ( V_94 ) ;
if ( ! V_83 ) {
V_18 = - V_33 ;
F_10 ( V_23 , L_22
L_23 ) ;
goto V_24;
}
V_90 = F_48 ( V_83 ) ;
for ( V_84 = 0 ;
V_84 < ( V_71 / V_8 -> V_82 ) ;
V_84 ++ ) {
T_2 V_35 ;
V_18 = F_43 ( V_83 , V_8 , V_68 ,
V_84 ) ;
if ( V_18 ) {
F_12 ( V_23 L_24
L_21 , V_25 , V_18 ) ;
goto V_24;
}
F_41 (
& V_35 , ( ( ( ( T_2 ) V_68 -> V_87 )
* ( V_71
/ V_8 -> V_82 ) )
+ V_84 ) , V_8 ) ;
V_18 = F_49 ( V_89 , V_90 ,
V_35 , V_8 -> V_82 ) ;
if ( V_18 < 0 ) {
F_10 ( V_23 , L_25
L_26
L_27 , V_18 ) ;
goto V_24;
}
}
V_18 = 0 ;
V_24:
if ( V_83 ) {
F_50 ( V_83 ) ;
F_51 ( V_83 ) ;
}
return V_18 ;
}
static int F_52 ( struct V_68 * V_68 ,
struct V_7 * V_8 ,
struct V_68 * V_83 ,
unsigned long V_84 )
{
T_2 V_85 ;
char V_86 [ V_37 ] ;
int V_18 ;
V_85 = ( ( ( T_2 ) V_68 -> V_87 )
* ( V_71 / V_8 -> V_82 ) ) ;
V_18 = F_18 ( V_86 , V_8 ,
( V_85 + V_84 ) ) ;
if ( V_18 ) {
F_10 ( V_23 , L_17
L_18 ,
( unsigned long long ) ( V_85 + V_84 ) , V_18 ) ;
goto V_24;
}
V_18 = F_53 ( V_8 , V_68 ,
( V_84
* V_8 -> V_82 ) ,
V_83 , 0 ,
V_8 -> V_82 , V_86 ) ;
if ( V_18 < 0 ) {
F_12 ( V_23 L_28
L_20
L_21 , V_25 , V_68 -> V_87 , V_84 ,
V_18 ) ;
goto V_24;
}
V_18 = 0 ;
V_24:
return V_18 ;
}
int F_54 ( struct V_68 * V_68 )
{
struct V_88 * V_89 ;
struct V_7 * V_8 ;
char * V_90 ;
struct V_68 * V_83 = NULL ;
unsigned long V_84 ;
int V_18 = 0 ;
V_89 = V_68 -> V_91 -> V_92 ;
V_8 =
& ( F_46 ( V_89 ) -> V_8 ) ;
F_38 ( ! ( V_8 -> V_16 & V_93 ) ) ;
V_83 = F_47 ( V_94 ) ;
if ( ! V_83 ) {
V_18 = - V_33 ;
F_10 ( V_23 , L_22
L_23 ) ;
goto V_24;
}
V_90 = F_48 ( V_83 ) ;
for ( V_84 = 0 ;
V_84 < ( V_71 / V_8 -> V_82 ) ;
V_84 ++ ) {
T_2 V_35 ;
F_41 (
& V_35 , ( ( V_68 -> V_87 * ( V_71
/ V_8 -> V_82 ) )
+ V_84 ) , V_8 ) ;
V_18 = F_55 ( V_90 , V_35 ,
V_8 -> V_82 ,
V_89 ) ;
if ( V_18 < 0 ) {
F_10 ( V_23 , L_25
L_29
L_27 , V_18 ) ;
goto V_24;
}
V_18 = F_52 ( V_68 , V_8 , V_83 ,
V_84 ) ;
if ( V_18 ) {
F_12 ( V_23 L_24
L_21 , V_25 , V_18 ) ;
goto V_24;
}
}
V_24:
if ( V_83 ) {
F_50 ( V_83 ) ;
F_51 ( V_83 ) ;
}
return V_18 ;
}
static int F_56 ( struct V_7 * V_8 ,
struct V_10 * V_73 ,
struct V_10 * V_74 , int V_65 ,
unsigned char * V_34 )
{
struct V_75 V_13 = {
. V_14 = V_8 -> V_14 ,
. V_76 = V_34 ,
. V_16 = V_17
} ;
int V_18 = 0 ;
F_5 ( & V_8 -> V_46 ) ;
V_18 = F_39 ( V_8 -> V_14 , V_8 -> V_78 ,
V_8 -> V_77 ) ;
if ( V_18 ) {
F_10 ( V_23 , L_15 ,
V_18 ) ;
F_15 ( & V_8 -> V_46 ) ;
V_18 = - V_80 ;
goto V_24;
}
F_10 ( V_39 , L_30 , V_65 ) ;
V_18 = F_57 ( & V_13 , V_73 , V_74 , V_65 ) ;
F_15 ( & V_8 -> V_46 ) ;
if ( V_18 ) {
F_10 ( V_23 , L_31 ,
V_18 ) ;
goto V_24;
}
V_18 = V_65 ;
V_24:
return V_18 ;
}
static int
F_44 ( struct V_7 * V_8 ,
struct V_68 * V_95 , int V_96 ,
struct V_68 * V_97 , int V_98 , int V_65 ,
unsigned char * V_34 )
{
struct V_10 V_74 , V_99 ;
F_33 ( & V_74 , 1 ) ;
F_33 ( & V_99 , 1 ) ;
F_36 ( & V_74 , V_97 , V_65 , V_98 ) ;
F_36 ( & V_99 , V_95 , V_65 , V_96 ) ;
return F_37 ( V_8 , & V_99 , & V_74 , V_65 , V_34 ) ;
}
static int
F_53 ( struct V_7 * V_8 ,
struct V_68 * V_95 , int V_96 ,
struct V_68 * V_97 , int V_98 , int V_65 ,
unsigned char * V_34 )
{
struct V_10 V_74 , V_99 ;
F_33 ( & V_74 , 1 ) ;
F_36 ( & V_74 , V_97 , V_65 , V_98 ) ;
F_33 ( & V_99 , 1 ) ;
F_36 ( & V_99 , V_95 , V_65 , V_96 ) ;
return F_56 ( V_8 , & V_99 , & V_74 , V_65 , V_34 ) ;
}
int F_58 ( struct V_7 * V_8 )
{
char * V_100 ;
int V_18 = - V_80 ;
if ( ! V_8 -> V_101 ) {
F_10 ( V_23 , L_32 ) ;
goto V_24;
}
F_10 ( V_39 ,
L_33
L_34 ,
V_8 -> V_101 , ( int ) strlen ( V_8 -> V_101 ) ,
V_8 -> V_77 << 3 ) ;
if ( V_8 -> V_14 ) {
V_18 = 0 ;
goto V_24;
}
F_5 ( & V_8 -> V_46 ) ;
V_18 = F_16 ( & V_100 ,
V_8 -> V_101 , L_35 ) ;
if ( V_18 )
goto V_102;
V_8 -> V_14 = F_59 ( V_100 , 0 ,
V_22 ) ;
F_60 ( V_100 ) ;
if ( F_8 ( V_8 -> V_14 ) ) {
V_18 = F_9 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
F_10 ( V_23 , L_36
L_37 ,
V_8 -> V_101 ) ;
goto V_102;
}
F_61 ( V_8 -> V_14 , V_103 ) ;
V_18 = 0 ;
V_102:
F_15 ( & V_8 -> V_46 ) ;
V_24:
return V_18 ;
}
static void F_62 ( struct V_7 * V_8 )
{
int V_104 ;
V_8 -> V_105 = 0xFFFFFFFF ;
V_8 -> V_106 = 0 ;
if ( V_8 -> V_82 == 0 )
return;
V_104 = V_8 -> V_82 ;
while ( ( V_104 & 0x01 ) == 0 ) {
V_104 >>= 1 ;
V_8 -> V_105 <<= 1 ;
V_8 -> V_106 ++ ;
}
}
void F_63 ( struct V_7 * V_8 )
{
V_8 -> V_82 = V_107 ;
F_62 ( V_8 ) ;
V_8 -> V_41 = V_108 ;
if ( V_8 -> V_16 & V_109 )
V_8 -> V_110 = V_111 ;
else {
if ( V_71 <= V_111 )
V_8 -> V_110 =
V_111 ;
else
V_8 -> V_110 = V_71 ;
}
}
int F_64 ( struct V_7 * V_8 )
{
int V_18 = 0 ;
char V_1 [ V_36 ] ;
F_38 ( V_8 -> V_41 > V_36 ) ;
F_38 ( V_8 -> V_41 <= 0 ) ;
if ( ! ( V_8 -> V_16 & V_112 ) ) {
V_18 = - V_80 ;
F_10 ( V_42 , L_38
L_39 ) ;
goto V_24;
}
V_18 = F_4 ( V_1 , V_8 , V_8 -> V_78 ,
V_8 -> V_77 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_11
L_40 ) ;
goto V_24;
}
memcpy ( V_8 -> V_40 , V_1 , V_8 -> V_41 ) ;
V_24:
if ( V_18 ) {
memset ( V_8 -> V_40 , 0 , V_8 -> V_41 ) ;
V_8 -> V_16 |= V_113 ;
}
return V_18 ;
}
static void F_65 ( struct V_7 * V_8 )
{
F_66 ( V_8 -> V_78 , V_8 -> V_77 ) ;
V_8 -> V_16 |= V_112 ;
F_64 ( V_8 ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_41 ) ;
F_20 ( V_8 -> V_78 ,
V_8 -> V_77 ) ;
}
}
static void F_67 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
if ( V_54 -> V_16 & V_114 )
V_8 -> V_16 |= V_109 ;
if ( V_54 -> V_16 & V_115 )
V_8 -> V_16 |= V_116 ;
if ( V_54 -> V_16 & V_117 ) {
V_8 -> V_16 |= V_118 ;
if ( V_54 -> V_16
& V_119 )
V_8 -> V_16 |= V_120 ;
else if ( V_54 -> V_16
& V_121 )
V_8 -> V_16 |= V_122 ;
}
}
static int F_68 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
struct V_55 * V_123 ;
int V_18 = 0 ;
F_5 ( & V_8 -> V_44 ) ;
F_5 ( & V_54 -> V_59 ) ;
F_69 (global_auth_tok,
&mount_crypt_stat->global_auth_tok_list,
mount_crypt_stat_list) {
if ( V_123 -> V_16 & V_124 )
continue;
V_18 = F_70 ( V_8 , V_123 -> V_125 ) ;
if ( V_18 ) {
F_12 ( V_23 L_42 , V_18 ) ;
goto V_24;
}
}
V_24:
F_15 ( & V_54 -> V_59 ) ;
F_15 ( & V_8 -> V_44 ) ;
return V_18 ;
}
static void F_71 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
F_67 ( V_8 ,
V_54 ) ;
F_63 ( V_8 ) ;
strcpy ( V_8 -> V_101 , V_126 ) ;
V_8 -> V_77 = V_127 ;
V_8 -> V_16 &= ~ ( V_112 ) ;
V_8 -> V_128 = V_129 ;
V_8 -> V_54 = V_54 ;
}
int F_72 ( struct V_88 * V_89 )
{
struct V_7 * V_8 =
& F_46 ( V_89 ) -> V_8 ;
struct V_53 * V_54 =
& F_73 (
V_89 -> V_130 ) -> V_54 ;
int V_29 ;
int V_18 = 0 ;
F_71 ( V_8 , V_54 ) ;
V_8 -> V_16 |= ( V_93 | V_112 ) ;
F_67 ( V_8 ,
V_54 ) ;
V_18 = F_68 ( V_8 ,
V_54 ) ;
if ( V_18 ) {
F_12 ( V_23 L_43
L_44 , V_18 ) ;
goto V_24;
}
V_29 =
strlen ( V_54 -> V_131 ) ;
memcpy ( V_8 -> V_101 ,
V_54 -> V_131 ,
V_29 ) ;
V_8 -> V_101 [ V_29 ] = '\0' ;
V_8 -> V_77 =
V_54 -> V_132 ;
F_65 ( V_8 ) ;
V_18 = F_58 ( V_8 ) ;
if ( V_18 )
F_10 ( V_23 , L_45
L_46 ,
V_8 -> V_101 , V_18 ) ;
V_24:
return V_18 ;
}
static int F_74 ( char * V_133 )
{
T_3 V_134 , V_135 ;
V_134 = F_75 ( V_133 ) ;
V_135 = F_75 ( V_133 + 4 ) ;
if ( ( V_134 ^ V_136 ) == V_135 )
return 0 ;
F_10 ( V_39 , L_47
L_48 , V_134 , V_135 ,
V_136 ) ;
F_10 ( V_39 , L_49
L_50 , ( V_134 ^ V_136 ) ) ;
return - V_80 ;
}
static int F_76 ( struct V_7 * V_8 ,
char * V_137 , int * V_138 )
{
int V_18 = 0 ;
int V_67 ;
T_3 V_16 ;
V_16 = F_75 ( V_137 ) ;
for ( V_67 = 0 ; V_67 < ( ( sizeof( V_139 )
/ sizeof( struct V_140 ) ) ) ; V_67 ++ )
if ( V_16 & V_139 [ V_67 ] . V_141 ) {
V_8 -> V_16 |= V_139 [ V_67 ] . V_142 ;
} else
V_8 -> V_16 &= ~ ( V_139 [ V_67 ] . V_142 ) ;
V_8 -> V_128 = ( ( V_16 >> 24 ) & 0xFF ) ;
( * V_138 ) = 4 ;
return V_18 ;
}
static void F_77 ( char * V_137 , T_1 * V_143 )
{
T_3 V_134 , V_135 ;
F_66 ( & V_134 , ( V_144 / 2 ) ) ;
V_135 = ( V_134 ^ V_136 ) ;
F_78 ( V_134 , V_137 ) ;
V_137 += ( V_144 / 2 ) ;
F_78 ( V_135 , V_137 ) ;
( * V_143 ) = V_144 ;
}
void F_79 ( char * V_137 ,
struct V_7 * V_8 ,
T_1 * V_143 )
{
T_3 V_16 = 0 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < ( ( sizeof( V_139 )
/ sizeof( struct V_140 ) ) ) ; V_67 ++ )
if ( V_8 -> V_16 & V_139 [ V_67 ] . V_142 )
V_16 |= V_139 [ V_67 ] . V_141 ;
V_16 |= ( ( ( ( V_20 ) V_8 -> V_128 ) << 24 ) & 0xFF000000 ) ;
F_78 ( V_16 , V_137 ) ;
( * V_143 ) = 4 ;
}
V_20 F_80 ( char * V_27 , T_1 V_145 )
{
int V_67 ;
V_20 V_146 = 0 ;
struct V_147 * V_148 =
V_149 ;
if ( strcmp ( V_27 , L_51 ) == 0 ) {
switch ( V_145 ) {
case 16 :
V_146 = V_150 ;
break;
case 24 :
V_146 = V_151 ;
break;
case 32 :
V_146 = V_152 ;
}
} else {
for ( V_67 = 0 ; V_67 < F_81 ( V_149 ) ; V_67 ++ )
if ( strcmp ( V_27 , V_148 [ V_67 ] . V_153 ) == 0 ) {
V_146 = V_148 [ V_67 ] . V_154 ;
break;
}
}
return V_146 ;
}
int F_82 ( char * V_155 , V_20 V_154 )
{
int V_18 = 0 ;
int V_67 ;
V_155 [ 0 ] = '\0' ;
for ( V_67 = 0 ; V_67 < F_81 ( V_149 ) ; V_67 ++ )
if ( V_154 == V_149 [ V_67 ] . V_154 )
strcpy ( V_155 , V_149 [ V_67 ] . V_153 ) ;
if ( V_155 [ 0 ] == '\0' ) {
F_10 ( V_42 , L_52
L_53 , V_154 ) ;
V_18 = - V_80 ;
}
return V_18 ;
}
int F_83 ( struct V_88 * V_88 )
{
V_20 V_156 [ V_157 ] ;
V_20 * V_158 = V_156 + V_159 ;
int V_18 ;
V_18 = F_55 ( V_156 , 0 , V_157 ,
V_88 ) ;
if ( V_18 < V_157 )
return V_18 >= 0 ? - V_80 : V_18 ;
V_18 = F_74 ( V_158 ) ;
if ( ! V_18 )
F_84 ( V_156 , V_88 ) ;
return V_18 ;
}
void
F_85 ( char * V_160 ,
struct V_7 * V_8 ,
T_1 * V_143 )
{
T_3 V_161 ;
T_4 V_162 ;
V_161 = ( T_3 ) V_8 -> V_82 ;
V_162 =
( T_4 ) ( V_8 -> V_110 / V_8 -> V_82 ) ;
F_78 ( V_161 , V_160 ) ;
V_160 += 4 ;
F_86 ( V_162 , V_160 ) ;
( * V_143 ) = 6 ;
}
static int F_87 ( char * V_137 , T_1 V_163 ,
T_1 * V_65 ,
struct V_7 * V_8 ,
struct V_164 * V_165 )
{
int V_18 ;
T_1 V_143 ;
T_1 V_35 ;
V_35 = V_159 ;
F_77 ( ( V_137 + V_35 ) , & V_143 ) ;
V_35 += V_143 ;
F_79 ( ( V_137 + V_35 ) , V_8 ,
& V_143 ) ;
V_35 += V_143 ;
F_85 ( ( V_137 + V_35 ) , V_8 ,
& V_143 ) ;
V_35 += V_143 ;
V_18 = F_88 ( ( V_137 + V_35 ) , V_8 ,
V_165 , & V_143 ,
V_163 - V_35 ) ;
if ( V_18 )
F_10 ( V_42 , L_54
L_55 , V_18 ) ;
if ( V_65 ) {
V_35 += V_143 ;
* V_65 = V_35 ;
}
return V_18 ;
}
static int
F_89 ( struct V_88 * V_89 ,
char * V_160 , T_1 V_166 )
{
int V_18 ;
V_18 = F_49 ( V_89 , V_160 ,
0 , V_166 ) ;
if ( V_18 < 0 )
F_12 ( V_23 L_56
L_57 , V_25 , V_18 ) ;
else
V_18 = 0 ;
return V_18 ;
}
static int
F_90 ( struct V_164 * V_165 ,
char * V_137 , T_1 V_65 )
{
int V_18 ;
V_18 = F_91 ( V_165 , V_167 , V_137 ,
V_65 , 0 ) ;
return V_18 ;
}
static unsigned long F_92 ( T_5 V_168 ,
unsigned int V_169 )
{
struct V_68 * V_68 ;
V_68 = F_93 ( V_168 | V_170 , V_169 ) ;
if ( V_68 )
return ( unsigned long ) F_94 ( V_68 ) ;
return 0 ;
}
int F_95 ( struct V_164 * V_165 ,
struct V_88 * V_89 )
{
struct V_7 * V_8 =
& F_46 ( V_89 ) -> V_8 ;
unsigned int V_169 ;
char * V_160 ;
T_1 V_166 ;
T_1 V_65 = 0 ;
int V_18 = 0 ;
if ( F_96 ( V_8 -> V_16 & V_93 ) ) {
if ( ! ( V_8 -> V_16 & V_112 ) ) {
F_12 ( V_23 L_58 ) ;
V_18 = - V_80 ;
goto V_24;
}
} else {
F_12 ( V_42 L_59 ,
V_25 ) ;
V_18 = - V_80 ;
goto V_24;
}
V_166 = V_8 -> V_110 ;
V_169 = F_97 ( V_166 ) ;
V_160 = ( char * ) F_92 ( V_32 , V_169 ) ;
if ( ! V_160 ) {
F_12 ( V_23 L_60 , V_25 ) ;
V_18 = - V_33 ;
goto V_24;
}
V_18 = F_87 ( V_160 , V_166 , & V_65 , V_8 ,
V_165 ) ;
if ( F_19 ( V_18 ) ) {
F_12 ( V_23 L_61 ,
V_25 , V_18 ) ;
goto V_171;
}
if ( V_8 -> V_16 & V_109 )
V_18 = F_90 ( V_165 , V_160 ,
V_65 ) ;
else
V_18 = F_89 ( V_89 , V_160 ,
V_166 ) ;
if ( V_18 ) {
F_12 ( V_23 L_62
L_21 , V_25 , V_18 ) ;
goto V_171;
}
V_171:
F_98 ( ( unsigned long ) V_160 , V_169 ) ;
V_24:
return V_18 ;
}
static int F_99 ( struct V_7 * V_8 ,
char * V_160 , int * V_138 ,
int V_172 )
{
int V_18 = 0 ;
T_3 V_161 ;
T_4 V_162 ;
V_161 = F_75 ( V_160 ) ;
V_160 += sizeof( V_173 ) ;
V_162 = F_100 ( V_160 ) ;
V_8 -> V_110 = ( ( ( T_1 ) V_162
* ( T_1 ) V_161 ) ) ;
( * V_138 ) = ( sizeof( V_173 ) + sizeof( V_174 ) ) ;
if ( ( V_172 == V_175 )
&& ( V_8 -> V_110
< V_111 ) ) {
V_18 = - V_80 ;
F_12 ( V_42 L_63 ,
V_8 -> V_110 ) ;
}
return V_18 ;
}
static void F_101 ( struct V_7 * V_8 )
{
V_8 -> V_110 = V_111 ;
}
void F_84 ( const char * V_137 , struct V_88 * V_88 )
{
struct V_53 * V_54 ;
struct V_7 * V_8 ;
T_6 V_156 ;
V_8 = & F_46 ( V_88 ) -> V_8 ;
V_54 =
& F_73 ( V_88 -> V_130 ) -> V_54 ;
if ( V_54 -> V_16 & V_115 ) {
V_156 = F_102 ( F_103 ( V_88 ) ) ;
if ( V_8 -> V_16 & V_109 )
V_156 += V_8 -> V_110 ;
} else
V_156 = F_104 ( V_137 ) ;
F_105 ( V_88 , ( T_2 ) V_156 ) ;
V_8 -> V_16 |= V_176 ;
}
static int F_106 ( char * V_137 ,
struct V_7 * V_8 ,
struct V_164 * V_165 ,
int V_172 )
{
int V_18 = 0 ;
int V_35 ;
int V_138 ;
F_63 ( V_8 ) ;
V_8 -> V_54 = & F_73 (
V_165 -> V_177 ) -> V_54 ;
V_35 = V_159 ;
V_18 = F_74 ( V_137 + V_35 ) ;
if ( V_18 )
goto V_24;
if ( ! ( V_8 -> V_16 & V_176 ) )
F_84 ( V_137 , V_165 -> V_178 ) ;
V_35 += V_144 ;
V_18 = F_76 ( V_8 , ( V_137 + V_35 ) ,
& V_138 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_64 ) ;
goto V_24;
}
if ( V_8 -> V_128 > V_179 ) {
F_10 ( V_42 , L_65
L_66
L_67 ,
V_8 -> V_128 ,
V_179 ) ;
V_18 = - V_80 ;
goto V_24;
}
V_35 += V_138 ;
if ( V_8 -> V_128 >= 1 ) {
V_18 = F_99 ( V_8 , ( V_137 + V_35 ) ,
& V_138 , V_172 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_68
L_69 , V_18 ) ;
}
V_35 += V_138 ;
} else
F_101 ( V_8 ) ;
V_18 = F_107 ( V_8 , ( V_137 + V_35 ) ,
V_165 ) ;
V_24:
return V_18 ;
}
int F_108 ( char * V_137 , struct V_88 * V_89 )
{
struct V_164 * V_180 =
F_46 ( V_89 ) -> V_181 -> V_182 ;
T_7 V_65 ;
int V_18 = 0 ;
V_65 = F_109 ( V_180 , V_167 ,
V_137 , V_107 ) ;
if ( V_65 < 0 ) {
if ( F_19 ( V_38 > 0 ) )
F_12 ( V_183 L_70
L_71
L_72 , V_167 , V_65 ) ;
V_18 = - V_80 ;
goto V_24;
}
V_24:
return V_18 ;
}
int F_110 ( struct V_164 * V_164 ,
struct V_88 * V_88 )
{
V_20 V_156 [ V_157 ] ;
V_20 * V_158 = V_156 + V_159 ;
int V_18 ;
V_18 = F_109 ( F_111 ( V_164 ) ,
V_167 , V_156 ,
V_157 ) ;
if ( V_18 < V_157 )
return V_18 >= 0 ? - V_80 : V_18 ;
V_18 = F_74 ( V_158 ) ;
if ( ! V_18 )
F_84 ( V_156 , V_88 ) ;
return V_18 ;
}
int F_112 ( struct V_164 * V_165 )
{
int V_18 ;
char * V_137 ;
struct V_88 * V_89 = V_165 -> V_178 ;
struct V_7 * V_8 =
& F_46 ( V_89 ) -> V_8 ;
struct V_53 * V_54 =
& F_73 (
V_165 -> V_177 ) -> V_54 ;
F_67 ( V_8 ,
V_54 ) ;
V_137 = F_113 ( V_184 , V_94 ) ;
if ( ! V_137 ) {
V_18 = - V_33 ;
F_12 ( V_23 L_73 ,
V_25 ) ;
goto V_24;
}
V_18 = F_55 ( V_137 , 0 , V_8 -> V_82 ,
V_89 ) ;
if ( V_18 >= 0 )
V_18 = F_106 ( V_137 , V_8 ,
V_165 ,
V_175 ) ;
if ( V_18 ) {
memset ( V_137 , 0 , V_71 ) ;
V_18 = F_108 ( V_137 , V_89 ) ;
if ( V_18 ) {
F_12 ( V_39 L_74
L_75 ,
V_89 -> V_185 ) ;
V_18 = - V_80 ;
goto V_24;
}
V_18 = F_106 ( V_137 , V_8 ,
V_165 ,
V_186 ) ;
if ( V_18 ) {
F_12 ( V_39 L_74
L_76 ,
V_89 -> V_185 ) ;
V_18 = - V_80 ;
}
if ( V_8 -> V_54 -> V_16
& V_114 ) {
V_8 -> V_16 |= V_109 ;
} else {
F_12 ( V_42 L_77
L_78
L_79
L_80
L_81 ,
V_89 -> V_185 ) ;
V_18 = - V_80 ;
}
}
V_24:
if ( V_137 ) {
memset ( V_137 , 0 , V_71 ) ;
F_29 ( V_184 , V_137 ) ;
}
return V_18 ;
}
static int
F_114 ( struct V_187 * V_188 ,
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
int V_18 = 0 ;
V_188 -> V_189 = NULL ;
V_188 -> V_190 = 0 ;
if ( ( V_8 && ( V_8 -> V_16 & V_120 ) )
|| ( V_54 && ( V_54 -> V_16
& V_119 ) ) ) {
T_1 V_191 ;
T_1 V_192 ;
V_18 = F_115 (
NULL , NULL ,
& V_188 -> V_190 ,
V_54 , NULL ,
V_188 -> V_193 ) ;
if ( V_18 ) {
F_12 ( V_23 L_82
L_83 , V_25 ,
V_18 ) ;
V_188 -> V_190 = 0 ;
goto V_24;
}
V_188 -> V_189 =
F_17 ( V_188 -> V_190 , V_32 ) ;
if ( ! V_188 -> V_189 ) {
F_12 ( V_23 L_84
L_85 , V_25 ,
V_188 -> V_190 ) ;
V_18 = - V_33 ;
goto V_24;
}
V_192 = V_188 -> V_190 ;
V_18 = F_115 ( V_188 -> V_189 ,
& V_192 ,
& V_191 ,
V_54 ,
V_188 -> V_188 ,
V_188 -> V_193 ) ;
if ( V_18 ) {
F_12 ( V_23 L_86
L_87 , V_25 ,
V_18 ) ;
F_60 ( V_188 -> V_189 ) ;
V_188 -> V_189 = NULL ;
V_188 -> V_190 = 0 ;
goto V_24;
}
V_188 -> V_190 = V_191 ;
} else {
F_12 ( V_23 L_88
L_89 , V_25 ) ;
V_18 = - V_194 ;
goto V_24;
}
V_24:
return V_18 ;
}
static int F_116 ( char * * V_195 , T_1 * V_196 ,
const char * V_197 , T_1 V_198 )
{
int V_18 = 0 ;
( * V_195 ) = F_17 ( ( V_198 + 1 ) , V_32 ) ;
if ( ! ( * V_195 ) ) {
V_18 = - V_33 ;
goto V_24;
}
memcpy ( ( void * ) ( * V_195 ) , ( void * ) V_197 , V_198 ) ;
( * V_195 ) [ ( V_198 ) ] = '\0' ;
( * V_196 ) = V_198 ;
V_24:
return V_18 ;
}
static int
F_117 ( struct V_199 * * V_200 ,
char * V_27 , T_1 * V_77 )
{
char V_201 [ V_202 ] ;
char * V_100 = NULL ;
int V_18 ;
* V_200 = NULL ;
if ( * V_77 > V_202 ) {
V_18 = - V_80 ;
F_12 ( V_23 L_90
L_91 , * V_77 , V_202 ) ;
goto V_24;
}
V_18 = F_16 ( & V_100 , V_27 ,
L_92 ) ;
if ( V_18 )
goto V_24;
* V_200 = F_59 ( V_100 , 0 , V_22 ) ;
if ( F_8 ( * V_200 ) ) {
V_18 = F_9 ( * V_200 ) ;
F_12 ( V_23 L_93
L_94 , V_100 , V_18 ) ;
goto V_24;
}
F_61 ( * V_200 , V_103 ) ;
if ( * V_77 == 0 ) {
struct V_203 * V_204 = F_118 ( * V_200 ) ;
* V_77 = V_204 -> V_205 ;
}
F_66 ( V_201 , * V_77 ) ;
V_18 = F_39 ( * V_200 , V_201 , * V_77 ) ;
if ( V_18 ) {
F_12 ( V_23 L_95
L_96 , * V_77 , V_100 ,
V_18 ) ;
V_18 = - V_80 ;
goto V_24;
}
V_24:
F_60 ( V_100 ) ;
return V_18 ;
}
int T_8 F_119 ( void )
{
F_23 ( & V_206 ) ;
F_22 ( & V_207 ) ;
return 0 ;
}
int F_120 ( void )
{
struct V_208 * V_200 , * V_209 ;
F_5 ( & V_206 ) ;
F_27 (key_tfm, key_tfm_tmp, &key_tfm_list,
key_tfm_list) {
F_28 ( & V_200 -> V_207 ) ;
if ( V_200 -> V_200 )
F_25 ( V_200 -> V_200 ) ;
F_29 ( V_210 , V_200 ) ;
}
F_15 ( & V_206 ) ;
return 0 ;
}
int
F_121 ( struct V_208 * * V_200 , char * V_27 ,
T_1 V_77 )
{
struct V_208 * V_211 ;
int V_18 = 0 ;
F_38 ( ! F_122 ( & V_206 ) ) ;
V_211 = F_113 ( V_210 , V_32 ) ;
if ( V_200 != NULL )
( * V_200 ) = V_211 ;
if ( ! V_211 ) {
V_18 = - V_33 ;
F_12 ( V_23 L_97
L_98 ) ;
goto V_24;
}
F_23 ( & V_211 -> V_212 ) ;
strncpy ( V_211 -> V_27 , V_27 ,
V_213 ) ;
V_211 -> V_27 [ V_213 ] = '\0' ;
V_211 -> V_77 = V_77 ;
V_18 = F_117 ( & V_211 -> V_200 ,
V_211 -> V_27 ,
& V_211 -> V_77 ) ;
if ( V_18 ) {
F_12 ( V_23 L_99
L_100 ,
V_211 -> V_27 , V_18 ) ;
F_29 ( V_210 , V_211 ) ;
if ( V_200 != NULL )
( * V_200 ) = NULL ;
goto V_24;
}
F_123 ( & V_211 -> V_207 , & V_207 ) ;
V_24:
return V_18 ;
}
int F_124 ( char * V_27 , struct V_208 * * V_200 )
{
struct V_208 * V_214 ;
F_38 ( ! F_122 ( & V_206 ) ) ;
F_69 (tmp_key_tfm, &key_tfm_list, key_tfm_list) {
if ( strcmp ( V_214 -> V_27 , V_27 ) == 0 ) {
if ( V_200 )
( * V_200 ) = V_214 ;
return 1 ;
}
}
if ( V_200 )
( * V_200 ) = NULL ;
return 0 ;
}
int F_125 ( struct V_199 * * V_14 ,
struct V_215 * * V_216 ,
char * V_27 )
{
struct V_208 * V_200 ;
int V_18 = 0 ;
( * V_14 ) = NULL ;
( * V_216 ) = NULL ;
F_5 ( & V_206 ) ;
if ( ! F_124 ( V_27 , & V_200 ) ) {
V_18 = F_121 ( & V_200 , V_27 , 0 ) ;
if ( V_18 ) {
F_12 ( V_23 L_101
L_21 , V_18 ) ;
goto V_24;
}
}
( * V_14 ) = V_200 -> V_200 ;
( * V_216 ) = & V_200 -> V_212 ;
V_24:
F_15 ( & V_206 ) ;
return V_18 ;
}
static void F_126 ( unsigned char * V_1 , T_1 * V_5 ,
unsigned char * V_2 , T_1 V_3 )
{
T_1 V_217 ;
T_1 V_218 = 0 ;
T_1 V_96 = 0 ;
unsigned char V_219 [ 3 ] ;
if ( V_3 == 0 ) {
( * V_5 ) = 0 ;
goto V_24;
}
V_217 = ( V_3 / 3 ) ;
if ( ( V_3 % 3 ) == 0 ) {
memcpy ( V_219 , ( & V_2 [ V_3 - 3 ] ) , 3 ) ;
} else {
V_217 ++ ;
V_219 [ 2 ] = 0x00 ;
switch ( V_3 % 3 ) {
case 1 :
V_219 [ 0 ] = V_2 [ V_3 - 1 ] ;
V_219 [ 1 ] = 0x00 ;
break;
case 2 :
V_219 [ 0 ] = V_2 [ V_3 - 2 ] ;
V_219 [ 1 ] = V_2 [ V_3 - 1 ] ;
}
}
( * V_5 ) = ( V_217 * 4 ) ;
if ( ! V_1 )
goto V_24;
while ( V_218 < V_217 ) {
unsigned char * V_220 ;
unsigned char V_221 [ 4 ] ;
if ( V_218 == ( V_217 - 1 ) )
V_220 = V_219 ;
else
V_220 = & V_2 [ V_218 * 3 ] ;
V_221 [ 0 ] = ( ( V_220 [ 0 ] >> 2 ) & 0x3F ) ;
V_221 [ 1 ] = ( ( ( V_220 [ 0 ] << 4 ) & 0x30 )
| ( ( V_220 [ 1 ] >> 4 ) & 0x0F ) ) ;
V_221 [ 2 ] = ( ( ( V_220 [ 1 ] << 2 ) & 0x3C )
| ( ( V_220 [ 2 ] >> 6 ) & 0x03 ) ) ;
V_221 [ 3 ] = ( V_220 [ 2 ] & 0x3F ) ;
V_1 [ V_96 ++ ] = V_222 [ V_221 [ 0 ] ] ;
V_1 [ V_96 ++ ] = V_222 [ V_221 [ 1 ] ] ;
V_1 [ V_96 ++ ] = V_222 [ V_221 [ 2 ] ] ;
V_1 [ V_96 ++ ] = V_222 [ V_221 [ 3 ] ] ;
V_218 ++ ;
}
V_24:
return;
}
static T_1 F_127 ( T_1 V_223 )
{
return ( ( V_223 + 1 ) * 3 ) / 4 ;
}
static void
F_128 ( unsigned char * V_1 , T_1 * V_5 ,
const unsigned char * V_2 , T_1 V_3 )
{
V_20 V_224 = 0 ;
T_1 V_225 = 0 ;
T_1 V_226 = 0 ;
if ( V_1 == NULL ) {
( * V_5 ) = F_127 ( V_3 ) ;
goto V_24;
}
while ( V_225 < V_3 ) {
unsigned char V_227 =
V_228 [ ( int ) V_2 [ V_225 ] ] ;
switch ( V_224 ) {
case 0 :
V_1 [ V_226 ] = ( V_227 << 2 ) ;
V_224 = 6 ;
break;
case 6 :
V_1 [ V_226 ++ ] |= ( V_227 >> 4 ) ;
V_1 [ V_226 ] = ( ( V_227 & 0xF )
<< 4 ) ;
V_224 = 4 ;
break;
case 4 :
V_1 [ V_226 ++ ] |= ( V_227 >> 2 ) ;
V_1 [ V_226 ] = ( V_227 << 6 ) ;
V_224 = 2 ;
break;
case 2 :
V_1 [ V_226 ++ ] |= ( V_227 ) ;
V_1 [ V_226 ] = 0 ;
V_224 = 0 ;
break;
}
V_225 ++ ;
}
( * V_5 ) = V_226 ;
V_24:
return;
}
int F_129 (
char * * V_229 ,
T_1 * V_230 ,
struct V_7 * V_8 ,
struct V_53 * V_54 ,
const char * V_197 , T_1 V_198 )
{
T_1 V_231 ;
int V_18 = 0 ;
( * V_229 ) = NULL ;
( * V_230 ) = 0 ;
if ( ( V_8 && ( V_8 -> V_16 & V_118 ) )
|| ( V_54 && ( V_54 -> V_16
& V_117 ) ) ) {
struct V_187 * V_188 ;
V_188 = F_130 ( sizeof( * V_188 ) , V_32 ) ;
if ( ! V_188 ) {
F_12 ( V_23 L_84
L_102 , V_25 ,
sizeof( * V_188 ) ) ;
V_18 = - V_33 ;
goto V_24;
}
V_188 -> V_188 = ( char * ) V_197 ;
V_188 -> V_193 = V_198 ;
V_18 = F_114 ( V_188 , V_8 ,
V_54 ) ;
if ( V_18 ) {
F_12 ( V_23 L_103
L_104 , V_25 , V_18 ) ;
F_60 ( V_188 ) ;
goto V_24;
}
F_126 (
NULL , & V_231 ,
V_188 -> V_189 ,
V_188 -> V_190 ) ;
if ( ( V_8 && ( V_8 -> V_16
& V_120 ) )
|| ( V_54
&& ( V_54 -> V_16
& V_119 ) ) )
( * V_230 ) =
( V_232
+ V_231 ) ;
else
( * V_230 ) =
( V_233
+ V_231 ) ;
( * V_229 ) = F_17 ( ( * V_230 ) + 1 , V_32 ) ;
if ( ! ( * V_229 ) ) {
F_12 ( V_23 L_84
L_102 , V_25 ,
( * V_230 ) ) ;
V_18 = - V_33 ;
F_60 ( V_188 -> V_189 ) ;
F_60 ( V_188 ) ;
goto V_24;
}
if ( ( V_8 && ( V_8 -> V_16
& V_120 ) )
|| ( V_54
&& ( V_54 -> V_16
& V_119 ) ) ) {
memcpy ( ( * V_229 ) ,
V_234 ,
V_232 ) ;
F_126 (
( ( * V_229 )
+ V_232 ) ,
& V_231 ,
V_188 -> V_189 ,
V_188 -> V_190 ) ;
( * V_230 ) =
( V_232
+ V_231 ) ;
( * V_229 ) [ ( * V_230 ) ] = '\0' ;
} else {
V_18 = - V_194 ;
}
if ( V_18 ) {
F_12 ( V_23 L_105
L_106 , V_25 ,
V_18 ) ;
F_60 ( ( * V_229 ) ) ;
( * V_229 ) = NULL ;
( * V_230 ) = 0 ;
}
F_60 ( V_188 -> V_189 ) ;
F_60 ( V_188 ) ;
} else {
V_18 = F_116 ( V_229 ,
V_230 ,
V_197 , V_198 ) ;
}
V_24:
return V_18 ;
}
int F_131 ( char * * V_235 ,
T_1 * V_236 ,
struct V_164 * V_237 ,
const char * V_197 , T_1 V_198 )
{
struct V_53 * V_54 =
& F_73 (
V_237 -> V_177 ) -> V_54 ;
char * V_238 ;
T_1 V_239 ;
T_1 V_191 ;
int V_18 = 0 ;
if ( ( V_54 -> V_16 & V_117 )
&& ! ( V_54 -> V_16 & V_115 )
&& ( V_198 > V_232 )
&& ( strncmp ( V_197 , V_234 ,
V_232 ) == 0 ) ) {
const char * V_240 = V_197 ;
T_1 V_241 = V_198 ;
V_197 += V_232 ;
V_198 -= V_232 ;
F_128 ( NULL , & V_239 ,
V_197 , V_198 ) ;
V_238 = F_17 ( V_239 , V_32 ) ;
if ( ! V_238 ) {
F_12 ( V_23 L_84
L_85 , V_25 ,
V_239 ) ;
V_18 = - V_33 ;
goto V_24;
}
F_128 ( V_238 , & V_239 ,
V_197 , V_198 ) ;
V_18 = F_132 ( V_235 ,
V_236 ,
& V_191 ,
V_54 ,
V_238 ,
V_239 ) ;
if ( V_18 ) {
F_12 ( V_183 L_107
L_108
L_109 , V_25 ) ;
V_18 = F_116 ( V_235 ,
V_236 ,
V_240 , V_241 ) ;
goto V_171;
}
} else {
V_18 = F_116 ( V_235 ,
V_236 ,
V_197 , V_198 ) ;
goto V_24;
}
V_171:
F_60 ( V_238 ) ;
V_24:
return V_18 ;
}
int F_133 ( long * V_242 , long V_243 ,
struct V_53 * V_54 )
{
struct V_75 V_13 ;
struct V_215 * V_216 ;
T_1 V_244 ;
int V_18 ;
if ( ! ( V_54 -> V_16 & V_117 ) ) {
( * V_242 ) = V_243 ;
return 0 ;
}
V_18 = F_125 ( & V_13 . V_14 , & V_216 ,
V_54 -> V_245 ) ;
if ( F_19 ( V_18 ) ) {
( * V_242 ) = 0 ;
return V_18 ;
}
F_5 ( V_216 ) ;
V_244 = F_134 ( V_13 . V_14 ) ;
F_15 ( V_216 ) ;
if ( V_243 == V_246
&& ( V_244 == 8 || V_244 == 16 ) ) {
( * V_242 ) = V_247 ;
return 0 ;
}
( * V_242 ) = V_243 ;
( * V_242 ) -= V_232 ;
( * V_242 ) = F_127 ( * V_242 ) - 3 ;
( * V_242 ) -= V_248 ;
( * V_242 ) -= V_249 ;
( * V_242 ) -= V_244 - 1 ;
if ( ( * V_242 ) < 0 )
( * V_242 ) = 0 ;
return 0 ;
}
