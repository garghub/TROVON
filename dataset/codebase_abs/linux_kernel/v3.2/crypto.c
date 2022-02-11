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
if ( V_11 )
F_36 ( & V_11 [ V_67 ] , V_69 , 0 , V_35 ) ;
V_70 = V_71 - V_35 ;
if ( V_65 >= V_70 ) {
if ( V_11 )
V_11 [ V_67 ] . V_72 = V_70 ;
V_64 += V_70 ;
V_65 -= V_70 ;
} else {
if ( V_11 )
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
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_19
L_20 ) ;
F_20 ( V_86 , V_8 -> V_41 ) ;
F_10 ( V_39 , L_21
L_22 ) ;
F_20 ( ( char * )
( F_44 ( V_68 )
+ ( V_84 * V_8 -> V_82 ) ) ,
8 ) ;
}
V_18 = F_45 ( V_8 , V_83 , 0 ,
V_68 , ( V_84
* V_8 -> V_82 ) ,
V_8 -> V_82 , V_86 ) ;
if ( V_18 < 0 ) {
F_12 ( V_23 L_23
L_24
L_25 , V_25 , V_68 -> V_87 , V_84 ,
V_18 ) ;
goto V_24;
}
V_18 = 0 ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_26
L_25 ,
( unsigned long long ) ( V_85 + V_84 ) , V_18 ) ;
F_10 ( V_39 , L_27
L_22 ) ;
F_20 ( ( char * ) ( F_44 ( V_83 ) ) , 8 ) ;
}
V_24:
return V_18 ;
}
int F_46 ( struct V_68 * V_68 )
{
struct V_88 * V_89 ;
struct V_7 * V_8 ;
char * V_90 ;
struct V_68 * V_83 = NULL ;
T_2 V_84 ;
int V_18 = 0 ;
V_89 = V_68 -> V_91 -> V_92 ;
V_8 =
& ( F_47 ( V_89 ) -> V_8 ) ;
F_38 ( ! ( V_8 -> V_16 & V_93 ) ) ;
V_83 = F_48 ( V_94 ) ;
if ( ! V_83 ) {
V_18 = - V_33 ;
F_10 ( V_23 , L_28
L_29 ) ;
goto V_24;
}
V_90 = F_49 ( V_83 ) ;
for ( V_84 = 0 ;
V_84 < ( V_71 / V_8 -> V_82 ) ;
V_84 ++ ) {
T_2 V_35 ;
V_18 = F_43 ( V_83 , V_8 , V_68 ,
V_84 ) ;
if ( V_18 ) {
F_12 ( V_23 L_30
L_25 , V_25 , V_18 ) ;
goto V_24;
}
F_41 (
& V_35 , ( ( ( ( T_2 ) V_68 -> V_87 )
* ( V_71
/ V_8 -> V_82 ) )
+ V_84 ) , V_8 ) ;
V_18 = F_50 ( V_89 , V_90 ,
V_35 , V_8 -> V_82 ) ;
if ( V_18 < 0 ) {
F_10 ( V_23 , L_31
L_32
L_33 , V_18 ) ;
goto V_24;
}
}
V_18 = 0 ;
V_24:
if ( V_83 ) {
F_51 ( V_83 ) ;
F_52 ( V_83 ) ;
}
return V_18 ;
}
static int F_53 ( struct V_68 * V_68 ,
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
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_34
L_20 ) ;
F_20 ( V_86 , V_8 -> V_41 ) ;
F_10 ( V_39 , L_21
L_35 ) ;
F_20 ( ( char * )
( F_44 ( V_83 )
+ ( V_84 * V_8 -> V_82 ) ) ,
8 ) ;
}
V_18 = F_54 ( V_8 , V_68 ,
( V_84
* V_8 -> V_82 ) ,
V_83 , 0 ,
V_8 -> V_82 , V_86 ) ;
if ( V_18 < 0 ) {
F_12 ( V_23 L_36
L_24
L_25 , V_25 , V_68 -> V_87 , V_84 ,
V_18 ) ;
goto V_24;
}
V_18 = 0 ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_37
L_25 ,
( unsigned long long ) ( V_85 + V_84 ) , V_18 ) ;
F_10 ( V_39 , L_27
L_35 ) ;
F_20 ( ( char * ) ( F_44 ( V_68 )
+ ( V_84
* V_8 -> V_82 ) ) , 8 ) ;
}
V_24:
return V_18 ;
}
int F_55 ( struct V_68 * V_68 )
{
struct V_88 * V_89 ;
struct V_7 * V_8 ;
char * V_90 ;
struct V_68 * V_83 = NULL ;
unsigned long V_84 ;
int V_18 = 0 ;
V_89 = V_68 -> V_91 -> V_92 ;
V_8 =
& ( F_47 ( V_89 ) -> V_8 ) ;
F_38 ( ! ( V_8 -> V_16 & V_93 ) ) ;
V_83 = F_48 ( V_94 ) ;
if ( ! V_83 ) {
V_18 = - V_33 ;
F_10 ( V_23 , L_28
L_29 ) ;
goto V_24;
}
V_90 = F_49 ( V_83 ) ;
for ( V_84 = 0 ;
V_84 < ( V_71 / V_8 -> V_82 ) ;
V_84 ++ ) {
T_2 V_35 ;
F_41 (
& V_35 , ( ( V_68 -> V_87 * ( V_71
/ V_8 -> V_82 ) )
+ V_84 ) , V_8 ) ;
V_18 = F_56 ( V_90 , V_35 ,
V_8 -> V_82 ,
V_89 ) ;
if ( V_18 < 0 ) {
F_10 ( V_23 , L_31
L_38
L_33 , V_18 ) ;
goto V_24;
}
V_18 = F_53 ( V_68 , V_8 , V_83 ,
V_84 ) ;
if ( V_18 ) {
F_12 ( V_23 L_30
L_25 , V_25 , V_18 ) ;
goto V_24;
}
}
V_24:
if ( V_83 ) {
F_51 ( V_83 ) ;
F_52 ( V_83 ) ;
}
return V_18 ;
}
static int F_57 ( struct V_7 * V_8 ,
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
F_10 ( V_39 , L_39 , V_65 ) ;
V_18 = F_58 ( & V_13 , V_73 , V_74 , V_65 ) ;
F_15 ( & V_8 -> V_46 ) ;
if ( V_18 ) {
F_10 ( V_23 , L_40 ,
V_18 ) ;
goto V_24;
}
V_18 = V_65 ;
V_24:
return V_18 ;
}
static int
F_45 ( struct V_7 * V_8 ,
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
F_54 ( struct V_7 * V_8 ,
struct V_68 * V_95 , int V_96 ,
struct V_68 * V_97 , int V_98 , int V_65 ,
unsigned char * V_34 )
{
struct V_10 V_74 , V_99 ;
F_33 ( & V_74 , 1 ) ;
F_36 ( & V_74 , V_97 , V_65 , V_98 ) ;
F_33 ( & V_99 , 1 ) ;
F_36 ( & V_99 , V_95 , V_65 , V_96 ) ;
return F_57 ( V_8 , & V_99 , & V_74 , V_65 , V_34 ) ;
}
int F_59 ( struct V_7 * V_8 )
{
char * V_100 ;
int V_18 = - V_80 ;
if ( ! V_8 -> V_101 ) {
F_10 ( V_23 , L_41 ) ;
goto V_24;
}
F_10 ( V_39 ,
L_42
L_43 ,
V_8 -> V_101 , ( int ) strlen ( V_8 -> V_101 ) ,
V_8 -> V_77 << 3 ) ;
if ( V_8 -> V_14 ) {
V_18 = 0 ;
goto V_24;
}
F_5 ( & V_8 -> V_46 ) ;
V_18 = F_16 ( & V_100 ,
V_8 -> V_101 , L_44 ) ;
if ( V_18 )
goto V_102;
V_8 -> V_14 = F_60 ( V_100 , 0 ,
V_22 ) ;
F_61 ( V_100 ) ;
if ( F_8 ( V_8 -> V_14 ) ) {
V_18 = F_9 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
F_10 ( V_23 , L_45
L_46 ,
V_8 -> V_101 ) ;
goto V_102;
}
F_62 ( V_8 -> V_14 , V_103 ) ;
V_18 = 0 ;
V_102:
F_15 ( & V_8 -> V_46 ) ;
V_24:
return V_18 ;
}
static void F_63 ( struct V_7 * V_8 )
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
void F_64 ( struct V_7 * V_8 )
{
V_8 -> V_82 = V_107 ;
F_63 ( V_8 ) ;
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
int F_65 ( struct V_7 * V_8 )
{
int V_18 = 0 ;
char V_1 [ V_36 ] ;
F_38 ( V_8 -> V_41 > V_36 ) ;
F_38 ( V_8 -> V_41 <= 0 ) ;
if ( ! ( V_8 -> V_16 & V_112 ) ) {
V_18 = - V_80 ;
F_10 ( V_42 , L_47
L_48 ) ;
goto V_24;
}
V_18 = F_4 ( V_1 , V_8 , V_8 -> V_78 ,
V_8 -> V_77 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_11
L_49 ) ;
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
static void F_66 ( struct V_7 * V_8 )
{
F_67 ( V_8 -> V_78 , V_8 -> V_77 ) ;
V_8 -> V_16 |= V_112 ;
F_65 ( V_8 ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_50 ) ;
F_20 ( V_8 -> V_78 ,
V_8 -> V_77 ) ;
}
}
static void F_68 (
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
static int F_69 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
struct V_55 * V_123 ;
int V_18 = 0 ;
F_5 ( & V_8 -> V_44 ) ;
F_5 ( & V_54 -> V_59 ) ;
F_70 (global_auth_tok,
&mount_crypt_stat->global_auth_tok_list,
mount_crypt_stat_list) {
if ( V_123 -> V_16 & V_124 )
continue;
V_18 = F_71 ( V_8 , V_123 -> V_125 ) ;
if ( V_18 ) {
F_12 ( V_23 L_51 , V_18 ) ;
goto V_24;
}
}
V_24:
F_15 ( & V_54 -> V_59 ) ;
F_15 ( & V_8 -> V_44 ) ;
return V_18 ;
}
static void F_72 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
F_68 ( V_8 ,
V_54 ) ;
F_64 ( V_8 ) ;
strcpy ( V_8 -> V_101 , V_126 ) ;
V_8 -> V_77 = V_127 ;
V_8 -> V_16 &= ~ ( V_112 ) ;
V_8 -> V_128 = V_129 ;
V_8 -> V_54 = V_54 ;
}
int F_73 ( struct V_88 * V_89 )
{
struct V_7 * V_8 =
& F_47 ( V_89 ) -> V_8 ;
struct V_53 * V_54 =
& F_74 (
V_89 -> V_130 ) -> V_54 ;
int V_29 ;
int V_18 = 0 ;
F_72 ( V_8 , V_54 ) ;
V_8 -> V_16 |= ( V_93 | V_112 ) ;
F_68 ( V_8 ,
V_54 ) ;
V_18 = F_69 ( V_8 ,
V_54 ) ;
if ( V_18 ) {
F_12 ( V_23 L_52
L_53 , V_18 ) ;
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
F_66 ( V_8 ) ;
V_18 = F_59 ( V_8 ) ;
if ( V_18 )
F_10 ( V_23 , L_54
L_55 ,
V_8 -> V_101 , V_18 ) ;
V_24:
return V_18 ;
}
static int F_75 ( char * V_133 )
{
T_3 V_134 , V_135 ;
V_134 = F_76 ( V_133 ) ;
V_135 = F_76 ( V_133 + 4 ) ;
if ( ( V_134 ^ V_136 ) == V_135 )
return 0 ;
F_10 ( V_39 , L_56
L_57 , V_134 , V_135 ,
V_136 ) ;
F_10 ( V_39 , L_58
L_59 , ( V_134 ^ V_136 ) ) ;
return - V_80 ;
}
static int F_77 ( struct V_7 * V_8 ,
char * V_137 , int * V_138 )
{
int V_18 = 0 ;
int V_67 ;
T_3 V_16 ;
V_16 = F_76 ( V_137 ) ;
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
static void F_78 ( char * V_137 , T_1 * V_143 )
{
T_3 V_134 , V_135 ;
F_67 ( & V_134 , ( V_144 / 2 ) ) ;
V_135 = ( V_134 ^ V_136 ) ;
F_79 ( V_134 , V_137 ) ;
V_137 += ( V_144 / 2 ) ;
F_79 ( V_135 , V_137 ) ;
( * V_143 ) = V_144 ;
}
void F_80 ( char * V_137 ,
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
F_79 ( V_16 , V_137 ) ;
( * V_143 ) = 4 ;
}
V_20 F_81 ( char * V_27 , T_1 V_145 )
{
int V_67 ;
V_20 V_146 = 0 ;
struct V_147 * V_148 =
V_149 ;
if ( strcmp ( V_27 , L_60 ) == 0 ) {
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
for ( V_67 = 0 ; V_67 < F_82 ( V_149 ) ; V_67 ++ )
if ( strcmp ( V_27 , V_148 [ V_67 ] . V_153 ) == 0 ) {
V_146 = V_148 [ V_67 ] . V_154 ;
break;
}
}
return V_146 ;
}
int F_83 ( char * V_155 , V_20 V_154 )
{
int V_18 = 0 ;
int V_67 ;
V_155 [ 0 ] = '\0' ;
for ( V_67 = 0 ; V_67 < F_82 ( V_149 ) ; V_67 ++ )
if ( V_154 == V_149 [ V_67 ] . V_154 )
strcpy ( V_155 , V_149 [ V_67 ] . V_153 ) ;
if ( V_155 [ 0 ] == '\0' ) {
F_10 ( V_42 , L_61
L_62 , V_154 ) ;
V_18 = - V_80 ;
}
return V_18 ;
}
int F_84 ( struct V_88 * V_88 )
{
V_20 V_156 [ V_157 ] ;
V_20 * V_158 = V_156 + V_159 ;
int V_18 ;
V_18 = F_56 ( V_156 , 0 , V_157 ,
V_88 ) ;
if ( V_18 < V_157 )
return V_18 >= 0 ? - V_80 : V_18 ;
V_18 = F_75 ( V_158 ) ;
if ( ! V_18 )
F_85 ( V_156 , V_88 ) ;
return V_18 ;
}
void
F_86 ( char * V_160 ,
struct V_7 * V_8 ,
T_1 * V_143 )
{
T_3 V_161 ;
T_4 V_162 ;
V_161 = ( T_3 ) V_8 -> V_82 ;
V_162 =
( T_4 ) ( V_8 -> V_110 / V_8 -> V_82 ) ;
F_79 ( V_161 , V_160 ) ;
V_160 += 4 ;
F_87 ( V_162 , V_160 ) ;
( * V_143 ) = 6 ;
}
static int F_88 ( char * V_137 , T_1 V_163 ,
T_1 * V_65 ,
struct V_7 * V_8 ,
struct V_164 * V_165 )
{
int V_18 ;
T_1 V_143 ;
T_1 V_35 ;
V_35 = V_159 ;
F_78 ( ( V_137 + V_35 ) , & V_143 ) ;
V_35 += V_143 ;
F_80 ( ( V_137 + V_35 ) , V_8 ,
& V_143 ) ;
V_35 += V_143 ;
F_86 ( ( V_137 + V_35 ) , V_8 ,
& V_143 ) ;
V_35 += V_143 ;
V_18 = F_89 ( ( V_137 + V_35 ) , V_8 ,
V_165 , & V_143 ,
V_163 - V_35 ) ;
if ( V_18 )
F_10 ( V_42 , L_63
L_64 , V_18 ) ;
if ( V_65 ) {
V_35 += V_143 ;
* V_65 = V_35 ;
}
return V_18 ;
}
static int
F_90 ( struct V_88 * V_89 ,
char * V_160 , T_1 V_166 )
{
int V_18 ;
V_18 = F_50 ( V_89 , V_160 ,
0 , V_166 ) ;
if ( V_18 < 0 )
F_12 ( V_23 L_65
L_66 , V_25 , V_18 ) ;
else
V_18 = 0 ;
return V_18 ;
}
static int
F_91 ( struct V_164 * V_165 ,
char * V_137 , T_1 V_65 )
{
int V_18 ;
V_18 = F_92 ( V_165 , V_167 , V_137 ,
V_65 , 0 ) ;
return V_18 ;
}
static unsigned long F_93 ( T_5 V_168 ,
unsigned int V_169 )
{
struct V_68 * V_68 ;
V_68 = F_94 ( V_168 | V_170 , V_169 ) ;
if ( V_68 )
return ( unsigned long ) F_44 ( V_68 ) ;
return 0 ;
}
int F_95 ( struct V_164 * V_165 ,
struct V_88 * V_89 )
{
struct V_7 * V_8 =
& F_47 ( V_89 ) -> V_8 ;
unsigned int V_169 ;
char * V_160 ;
T_1 V_166 ;
T_1 V_65 = 0 ;
int V_18 = 0 ;
if ( F_96 ( V_8 -> V_16 & V_93 ) ) {
if ( ! ( V_8 -> V_16 & V_112 ) ) {
F_12 ( V_23 L_67 ) ;
V_18 = - V_80 ;
goto V_24;
}
} else {
F_12 ( V_42 L_68 ,
V_25 ) ;
V_18 = - V_80 ;
goto V_24;
}
V_166 = V_8 -> V_110 ;
V_169 = F_97 ( V_166 ) ;
V_160 = ( char * ) F_93 ( V_32 , V_169 ) ;
if ( ! V_160 ) {
F_12 ( V_23 L_69 , V_25 ) ;
V_18 = - V_33 ;
goto V_24;
}
V_18 = F_88 ( V_160 , V_166 , & V_65 , V_8 ,
V_165 ) ;
if ( F_19 ( V_18 ) ) {
F_12 ( V_23 L_70 ,
V_25 , V_18 ) ;
goto V_171;
}
if ( V_8 -> V_16 & V_109 )
V_18 = F_91 ( V_165 , V_160 ,
V_65 ) ;
else
V_18 = F_90 ( V_89 , V_160 ,
V_166 ) ;
if ( V_18 ) {
F_12 ( V_23 L_71
L_25 , V_25 , V_18 ) ;
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
V_161 = F_76 ( V_160 ) ;
V_160 += sizeof( V_173 ) ;
V_162 = F_100 ( V_160 ) ;
V_8 -> V_110 = ( ( ( T_1 ) V_162
* ( T_1 ) V_161 ) ) ;
( * V_138 ) = ( sizeof( V_173 ) + sizeof( V_174 ) ) ;
if ( ( V_172 == V_175 )
&& ( V_8 -> V_110
< V_111 ) ) {
V_18 = - V_80 ;
F_12 ( V_42 L_72 ,
V_8 -> V_110 ) ;
}
return V_18 ;
}
static void F_101 ( struct V_7 * V_8 )
{
V_8 -> V_110 = V_111 ;
}
void F_85 ( const char * V_137 , struct V_88 * V_88 )
{
struct V_53 * V_54 ;
struct V_7 * V_8 ;
T_6 V_156 ;
V_8 = & F_47 ( V_88 ) -> V_8 ;
V_54 =
& F_74 ( V_88 -> V_130 ) -> V_54 ;
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
F_64 ( V_8 ) ;
V_8 -> V_54 = & F_74 (
V_165 -> V_177 ) -> V_54 ;
V_35 = V_159 ;
V_18 = F_75 ( V_137 + V_35 ) ;
if ( V_18 )
goto V_24;
if ( ! ( V_8 -> V_16 & V_176 ) )
F_85 ( V_137 , V_165 -> V_178 ) ;
V_35 += V_144 ;
V_18 = F_77 ( V_8 , ( V_137 + V_35 ) ,
& V_138 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_73 ) ;
goto V_24;
}
if ( V_8 -> V_128 > V_179 ) {
F_10 ( V_42 , L_74
L_75
L_76 ,
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
F_10 ( V_42 , L_77
L_78 , V_18 ) ;
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
F_47 ( V_89 ) -> V_181 -> V_182 ;
T_7 V_65 ;
int V_18 = 0 ;
V_65 = F_109 ( V_180 , V_167 ,
V_137 , V_107 ) ;
if ( V_65 < 0 ) {
if ( F_19 ( V_38 > 0 ) )
F_12 ( V_183 L_79
L_80
L_81 , V_167 , V_65 ) ;
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
V_18 = F_75 ( V_158 ) ;
if ( ! V_18 )
F_85 ( V_156 , V_88 ) ;
return V_18 ;
}
int F_112 ( struct V_164 * V_165 )
{
int V_18 = 0 ;
char * V_137 = NULL ;
struct V_88 * V_89 = V_165 -> V_178 ;
struct V_7 * V_8 =
& F_47 ( V_89 ) -> V_8 ;
struct V_53 * V_54 =
& F_74 (
V_165 -> V_177 ) -> V_54 ;
F_68 ( V_8 ,
V_54 ) ;
V_137 = F_113 ( V_184 , V_94 ) ;
if ( ! V_137 ) {
V_18 = - V_33 ;
F_12 ( V_23 L_82 ,
V_25 ) ;
goto V_24;
}
V_18 = F_56 ( V_137 , 0 , V_8 -> V_82 ,
V_89 ) ;
if ( V_18 >= 0 )
V_18 = F_106 ( V_137 , V_8 ,
V_165 ,
V_175 ) ;
if ( V_18 ) {
memset ( V_137 , 0 , V_71 ) ;
V_18 = F_108 ( V_137 , V_89 ) ;
if ( V_18 ) {
F_12 ( V_39 L_83
L_84 ) ;
V_18 = - V_80 ;
goto V_24;
}
V_18 = F_106 ( V_137 , V_8 ,
V_165 ,
V_185 ) ;
if ( V_18 ) {
F_12 ( V_39 L_83
L_85 ) ;
V_18 = - V_80 ;
}
if ( V_8 -> V_54 -> V_16
& V_114 ) {
V_8 -> V_16 |= V_109 ;
} else {
F_12 ( V_42 L_86
L_87
L_88
L_89
L_90 ) ;
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
F_114 ( struct V_186 * V_187 ,
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
int V_18 = 0 ;
V_187 -> V_188 = NULL ;
V_187 -> V_189 = 0 ;
if ( ( V_8 && ( V_8 -> V_16 & V_120 ) )
|| ( V_54 && ( V_54 -> V_16
& V_119 ) ) ) {
T_1 V_190 ;
T_1 V_191 ;
V_18 = F_115 (
NULL , NULL ,
& V_187 -> V_189 ,
V_54 , NULL ,
V_187 -> V_192 ) ;
if ( V_18 ) {
F_12 ( V_23 L_91
L_92 , V_25 ,
V_18 ) ;
V_187 -> V_189 = 0 ;
goto V_24;
}
V_187 -> V_188 =
F_17 ( V_187 -> V_189 , V_32 ) ;
if ( ! V_187 -> V_188 ) {
F_12 ( V_23 L_93
L_94 , V_25 ,
V_187 -> V_189 ) ;
V_18 = - V_33 ;
goto V_24;
}
V_191 = V_187 -> V_189 ;
V_18 = F_115 ( V_187 -> V_188 ,
& V_191 ,
& V_190 ,
V_54 ,
V_187 -> V_187 ,
V_187 -> V_192 ) ;
if ( V_18 ) {
F_12 ( V_23 L_95
L_96 , V_25 ,
V_18 ) ;
F_61 ( V_187 -> V_188 ) ;
V_187 -> V_188 = NULL ;
V_187 -> V_189 = 0 ;
goto V_24;
}
V_187 -> V_189 = V_190 ;
} else {
F_12 ( V_23 L_97
L_98 , V_25 ) ;
V_18 = - V_193 ;
goto V_24;
}
V_24:
return V_18 ;
}
static int F_116 ( char * * V_194 , T_1 * V_195 ,
const char * V_196 , T_1 V_197 )
{
int V_18 = 0 ;
( * V_194 ) = F_17 ( ( V_197 + 1 ) , V_32 ) ;
if ( ! ( * V_194 ) ) {
V_18 = - V_33 ;
goto V_24;
}
memcpy ( ( void * ) ( * V_194 ) , ( void * ) V_196 , V_197 ) ;
( * V_194 ) [ ( V_197 ) ] = '\0' ;
( * V_195 ) = V_197 ;
V_24:
return V_18 ;
}
static int
F_117 ( struct V_198 * * V_199 ,
char * V_27 , T_1 * V_77 )
{
char V_200 [ V_201 ] ;
char * V_100 = NULL ;
int V_18 ;
* V_199 = NULL ;
if ( * V_77 > V_201 ) {
V_18 = - V_80 ;
F_12 ( V_23 L_99
L_100 , * V_77 , V_201 ) ;
goto V_24;
}
V_18 = F_16 ( & V_100 , V_27 ,
L_101 ) ;
if ( V_18 )
goto V_24;
* V_199 = F_60 ( V_100 , 0 , V_22 ) ;
if ( F_8 ( * V_199 ) ) {
V_18 = F_9 ( * V_199 ) ;
F_12 ( V_23 L_102
L_103 , V_100 , V_18 ) ;
goto V_24;
}
F_62 ( * V_199 , V_103 ) ;
if ( * V_77 == 0 ) {
struct V_202 * V_203 = F_118 ( * V_199 ) ;
* V_77 = V_203 -> V_204 ;
}
F_67 ( V_200 , * V_77 ) ;
V_18 = F_39 ( * V_199 , V_200 , * V_77 ) ;
if ( V_18 ) {
F_12 ( V_23 L_104
L_105 , * V_77 , V_100 ,
V_18 ) ;
V_18 = - V_80 ;
goto V_24;
}
V_24:
F_61 ( V_100 ) ;
return V_18 ;
}
int T_8 F_119 ( void )
{
F_23 ( & V_205 ) ;
F_22 ( & V_206 ) ;
return 0 ;
}
int F_120 ( void )
{
struct V_207 * V_199 , * V_208 ;
F_5 ( & V_205 ) ;
F_27 (key_tfm, key_tfm_tmp, &key_tfm_list,
key_tfm_list) {
F_28 ( & V_199 -> V_206 ) ;
if ( V_199 -> V_199 )
F_25 ( V_199 -> V_199 ) ;
F_29 ( V_209 , V_199 ) ;
}
F_15 ( & V_205 ) ;
return 0 ;
}
int
F_121 ( struct V_207 * * V_199 , char * V_27 ,
T_1 V_77 )
{
struct V_207 * V_210 ;
int V_18 = 0 ;
F_38 ( ! F_122 ( & V_205 ) ) ;
V_210 = F_113 ( V_209 , V_32 ) ;
if ( V_199 != NULL )
( * V_199 ) = V_210 ;
if ( ! V_210 ) {
V_18 = - V_33 ;
F_12 ( V_23 L_106
L_107 ) ;
goto V_24;
}
F_23 ( & V_210 -> V_211 ) ;
strncpy ( V_210 -> V_27 , V_27 ,
V_212 ) ;
V_210 -> V_27 [ V_212 ] = '\0' ;
V_210 -> V_77 = V_77 ;
V_18 = F_117 ( & V_210 -> V_199 ,
V_210 -> V_27 ,
& V_210 -> V_77 ) ;
if ( V_18 ) {
F_12 ( V_23 L_108
L_109 ,
V_210 -> V_27 , V_18 ) ;
F_29 ( V_209 , V_210 ) ;
if ( V_199 != NULL )
( * V_199 ) = NULL ;
goto V_24;
}
F_123 ( & V_210 -> V_206 , & V_206 ) ;
V_24:
return V_18 ;
}
int F_124 ( char * V_27 , struct V_207 * * V_199 )
{
struct V_207 * V_213 ;
F_38 ( ! F_122 ( & V_205 ) ) ;
F_70 (tmp_key_tfm, &key_tfm_list, key_tfm_list) {
if ( strcmp ( V_213 -> V_27 , V_27 ) == 0 ) {
if ( V_199 )
( * V_199 ) = V_213 ;
return 1 ;
}
}
if ( V_199 )
( * V_199 ) = NULL ;
return 0 ;
}
int F_125 ( struct V_198 * * V_14 ,
struct V_214 * * V_215 ,
char * V_27 )
{
struct V_207 * V_199 ;
int V_18 = 0 ;
( * V_14 ) = NULL ;
( * V_215 ) = NULL ;
F_5 ( & V_205 ) ;
if ( ! F_124 ( V_27 , & V_199 ) ) {
V_18 = F_121 ( & V_199 , V_27 , 0 ) ;
if ( V_18 ) {
F_12 ( V_23 L_110
L_25 , V_18 ) ;
goto V_24;
}
}
( * V_14 ) = V_199 -> V_199 ;
( * V_215 ) = & V_199 -> V_211 ;
V_24:
F_15 ( & V_205 ) ;
return V_18 ;
}
void F_126 ( unsigned char * V_1 , T_1 * V_5 ,
unsigned char * V_2 , T_1 V_3 )
{
T_1 V_216 ;
T_1 V_217 = 0 ;
T_1 V_96 = 0 ;
unsigned char V_218 [ 3 ] ;
if ( V_3 == 0 ) {
( * V_5 ) = 0 ;
goto V_24;
}
V_216 = ( V_3 / 3 ) ;
if ( ( V_3 % 3 ) == 0 ) {
memcpy ( V_218 , ( & V_2 [ V_3 - 3 ] ) , 3 ) ;
} else {
V_216 ++ ;
V_218 [ 2 ] = 0x00 ;
switch ( V_3 % 3 ) {
case 1 :
V_218 [ 0 ] = V_2 [ V_3 - 1 ] ;
V_218 [ 1 ] = 0x00 ;
break;
case 2 :
V_218 [ 0 ] = V_2 [ V_3 - 2 ] ;
V_218 [ 1 ] = V_2 [ V_3 - 1 ] ;
}
}
( * V_5 ) = ( V_216 * 4 ) ;
if ( ! V_1 )
goto V_24;
while ( V_217 < V_216 ) {
unsigned char * V_219 ;
unsigned char V_220 [ 4 ] ;
if ( V_217 == ( V_216 - 1 ) )
V_219 = V_218 ;
else
V_219 = & V_2 [ V_217 * 3 ] ;
V_220 [ 0 ] = ( ( V_219 [ 0 ] >> 2 ) & 0x3F ) ;
V_220 [ 1 ] = ( ( ( V_219 [ 0 ] << 4 ) & 0x30 )
| ( ( V_219 [ 1 ] >> 4 ) & 0x0F ) ) ;
V_220 [ 2 ] = ( ( ( V_219 [ 1 ] << 2 ) & 0x3C )
| ( ( V_219 [ 2 ] >> 6 ) & 0x03 ) ) ;
V_220 [ 3 ] = ( V_219 [ 2 ] & 0x3F ) ;
V_1 [ V_96 ++ ] = V_221 [ V_220 [ 0 ] ] ;
V_1 [ V_96 ++ ] = V_221 [ V_220 [ 1 ] ] ;
V_1 [ V_96 ++ ] = V_221 [ V_220 [ 2 ] ] ;
V_1 [ V_96 ++ ] = V_221 [ V_220 [ 3 ] ] ;
V_217 ++ ;
}
V_24:
return;
}
static void
F_127 ( unsigned char * V_1 , T_1 * V_5 ,
const unsigned char * V_2 , T_1 V_3 )
{
V_20 V_222 = 0 ;
T_1 V_223 = 0 ;
T_1 V_224 = 0 ;
if ( V_1 == NULL ) {
( * V_5 ) = ( ( ( V_3 + 1 ) * 3 ) / 4 ) ;
goto V_24;
}
while ( V_223 < V_3 ) {
unsigned char V_225 =
V_226 [ ( int ) V_2 [ V_223 ] ] ;
switch ( V_222 ) {
case 0 :
V_1 [ V_224 ] = ( V_225 << 2 ) ;
V_222 = 6 ;
break;
case 6 :
V_1 [ V_224 ++ ] |= ( V_225 >> 4 ) ;
V_1 [ V_224 ] = ( ( V_225 & 0xF )
<< 4 ) ;
V_222 = 4 ;
break;
case 4 :
V_1 [ V_224 ++ ] |= ( V_225 >> 2 ) ;
V_1 [ V_224 ] = ( V_225 << 6 ) ;
V_222 = 2 ;
break;
case 2 :
V_1 [ V_224 ++ ] |= ( V_225 ) ;
V_1 [ V_224 ] = 0 ;
V_222 = 0 ;
break;
}
V_223 ++ ;
}
( * V_5 ) = V_224 ;
V_24:
return;
}
int F_128 (
char * * V_227 ,
T_1 * V_228 ,
struct V_7 * V_8 ,
struct V_53 * V_54 ,
const char * V_196 , T_1 V_197 )
{
T_1 V_229 ;
int V_18 = 0 ;
( * V_227 ) = NULL ;
( * V_228 ) = 0 ;
if ( ( V_8 && ( V_8 -> V_16 & V_118 ) )
|| ( V_54 && ( V_54 -> V_16
& V_117 ) ) ) {
struct V_186 * V_187 ;
V_187 = F_129 ( sizeof( * V_187 ) , V_32 ) ;
if ( ! V_187 ) {
F_12 ( V_23 L_93
L_111 , V_25 ,
sizeof( * V_187 ) ) ;
V_18 = - V_33 ;
goto V_24;
}
V_187 -> V_187 = ( char * ) V_196 ;
V_187 -> V_192 = V_197 ;
V_18 = F_114 ( V_187 , V_8 ,
V_54 ) ;
if ( V_18 ) {
F_12 ( V_23 L_112
L_113 , V_25 , V_18 ) ;
F_61 ( V_187 ) ;
goto V_24;
}
F_126 (
NULL , & V_229 ,
V_187 -> V_188 ,
V_187 -> V_189 ) ;
if ( ( V_8 && ( V_8 -> V_16
& V_120 ) )
|| ( V_54
&& ( V_54 -> V_16
& V_119 ) ) )
( * V_228 ) =
( V_230
+ V_229 ) ;
else
( * V_228 ) =
( V_231
+ V_229 ) ;
( * V_227 ) = F_17 ( ( * V_228 ) + 1 , V_32 ) ;
if ( ! ( * V_227 ) ) {
F_12 ( V_23 L_93
L_111 , V_25 ,
( * V_228 ) ) ;
V_18 = - V_33 ;
F_61 ( V_187 -> V_188 ) ;
F_61 ( V_187 ) ;
goto V_24;
}
if ( ( V_8 && ( V_8 -> V_16
& V_120 ) )
|| ( V_54
&& ( V_54 -> V_16
& V_119 ) ) ) {
memcpy ( ( * V_227 ) ,
V_232 ,
V_230 ) ;
F_126 (
( ( * V_227 )
+ V_230 ) ,
& V_229 ,
V_187 -> V_188 ,
V_187 -> V_189 ) ;
( * V_228 ) =
( V_230
+ V_229 ) ;
( * V_227 ) [ ( * V_228 ) ] = '\0' ;
} else {
V_18 = - V_193 ;
}
if ( V_18 ) {
F_12 ( V_23 L_114
L_115 , V_25 ,
V_18 ) ;
F_61 ( ( * V_227 ) ) ;
( * V_227 ) = NULL ;
( * V_228 ) = 0 ;
}
F_61 ( V_187 -> V_188 ) ;
F_61 ( V_187 ) ;
} else {
V_18 = F_116 ( V_227 ,
V_228 ,
V_196 , V_197 ) ;
}
V_24:
return V_18 ;
}
int F_130 ( char * * V_233 ,
T_1 * V_234 ,
struct V_164 * V_235 ,
const char * V_196 , T_1 V_197 )
{
struct V_53 * V_54 =
& F_74 (
V_235 -> V_177 ) -> V_54 ;
char * V_236 ;
T_1 V_237 ;
T_1 V_190 ;
int V_18 = 0 ;
if ( ( V_54 -> V_16 & V_117 )
&& ! ( V_54 -> V_16 & V_115 )
&& ( V_197 > V_230 )
&& ( strncmp ( V_196 , V_232 ,
V_230 ) == 0 ) ) {
const char * V_238 = V_196 ;
T_1 V_239 = V_197 ;
V_196 += V_230 ;
V_197 -= V_230 ;
F_127 ( NULL , & V_237 ,
V_196 , V_197 ) ;
V_236 = F_17 ( V_237 , V_32 ) ;
if ( ! V_236 ) {
F_12 ( V_23 L_93
L_94 , V_25 ,
V_237 ) ;
V_18 = - V_33 ;
goto V_24;
}
F_127 ( V_236 , & V_237 ,
V_196 , V_197 ) ;
V_18 = F_131 ( V_233 ,
V_234 ,
& V_190 ,
V_54 ,
V_236 ,
V_237 ) ;
if ( V_18 ) {
F_12 ( V_183 L_116
L_117
L_118 , V_25 ) ;
V_18 = F_116 ( V_233 ,
V_234 ,
V_238 , V_239 ) ;
goto V_171;
}
} else {
V_18 = F_116 ( V_233 ,
V_234 ,
V_196 , V_197 ) ;
goto V_24;
}
V_171:
F_61 ( V_236 ) ;
V_24:
return V_18 ;
}
