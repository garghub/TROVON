static int F_1 ( long V_1 )
{
int V_2 = 0 ;
switch ( V_1 ) {
case - V_3 :
F_2 ( V_4 , L_1 ) ;
V_2 = - V_5 ;
break;
case - V_6 :
F_2 ( V_4 , L_2 ) ;
V_2 = - V_7 ;
break;
case - V_8 :
F_2 ( V_4 , L_3 ) ;
V_2 = - V_9 ;
break;
default:
F_2 ( V_4 , L_4
L_5 , V_1 ) ;
V_2 = - V_9 ;
}
return V_2 ;
}
static int F_3 ( int V_1 )
{
int V_2 = V_1 ;
switch ( V_1 ) {
case - V_5 :
F_2 ( V_4 , L_6 ) ;
break;
case - V_9 :
F_2 ( V_4 , L_7 ) ;
break;
default:
V_2 = F_1 ( V_1 ) ;
break;
}
return V_2 ;
}
int F_4 ( unsigned char * V_10 , T_1 * V_11 ,
T_1 * V_12 )
{
int V_2 = 0 ;
( * V_12 ) = 0 ;
( * V_11 ) = 0 ;
if ( V_10 [ 0 ] < 192 ) {
( * V_11 ) = ( unsigned char ) V_10 [ 0 ] ;
( * V_12 ) = 1 ;
} else if ( V_10 [ 0 ] < 224 ) {
( * V_11 ) = ( ( ( unsigned char ) ( V_10 [ 0 ] ) - 192 ) * 256 ) ;
( * V_11 ) += ( ( unsigned char ) ( V_10 [ 1 ] ) + 192 ) ;
( * V_12 ) = 2 ;
} else if ( V_10 [ 0 ] == 255 ) {
F_2 ( V_13 , L_8
L_9 ) ;
V_2 = - V_9 ;
goto V_14;
} else {
F_2 ( V_13 , L_10 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_14:
return V_2 ;
}
int F_5 ( char * V_15 , T_1 V_11 ,
T_1 * V_16 )
{
int V_2 = 0 ;
if ( V_11 < 192 ) {
V_15 [ 0 ] = V_11 ;
( * V_16 ) = 1 ;
} else if ( V_11 < 65536 ) {
V_15 [ 0 ] = ( ( ( V_11 - 192 ) / 256 ) + 192 ) ;
V_15 [ 1 ] = ( ( V_11 - 192 ) % 256 ) ;
( * V_16 ) = 2 ;
} else {
V_2 = - V_9 ;
F_2 ( V_4 ,
L_11 , V_11 ) ;
}
return V_2 ;
}
static int
F_6 ( char * V_17 , struct V_18 * V_19 ,
char * * V_20 , T_1 * V_21 )
{
T_1 V_22 = 0 ;
T_1 V_23 ;
T_1 V_24 ;
char * V_25 ;
int V_2 ;
V_23 = ( 5 + V_26
+ V_19 -> V_27 ) ;
* V_20 = F_7 ( V_23 , V_28 ) ;
V_25 = * V_20 ;
if ( ! V_25 ) {
F_2 ( V_13 , L_12 ) ;
V_2 = - V_29 ;
goto V_14;
}
V_25 [ V_22 ++ ] = V_30 ;
V_2 = F_5 ( & V_25 [ V_22 ] , V_26 ,
& V_24 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_13
L_14 ) ;
goto V_14;
}
V_22 += V_24 ;
memcpy ( & V_25 [ V_22 ] , V_17 , V_26 ) ;
V_22 += V_26 ;
V_2 = F_5 ( & V_25 [ V_22 ] ,
V_19 -> V_27 ,
& V_24 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_13
L_14 ) ;
goto V_14;
}
V_22 += V_24 ;
memcpy ( & V_25 [ V_22 ] , V_19 -> V_31 ,
V_19 -> V_27 ) ;
V_22 += V_19 -> V_27 ;
* V_21 = V_22 ;
V_14:
return V_2 ;
}
static int
F_8 ( struct V_18 * V_19 , T_2 * V_32 ,
struct V_33 * V_34 )
{
T_1 V_22 = 0 ;
char * V_10 ;
T_1 V_23 ;
T_1 V_35 ;
T_1 V_36 ;
T_3 V_37 = 0 ;
T_3 V_38 = 0 ;
int V_2 ;
V_36 = V_34 -> V_23 ;
V_10 = V_34 -> V_10 ;
if ( V_36 < 4 ) {
V_2 = - V_39 ;
goto V_14;
}
if ( V_10 [ V_22 ++ ] != V_40 ) {
F_2 ( V_13 , L_15 ) ;
V_2 = - V_39 ;
goto V_14;
}
if ( V_10 [ V_22 ++ ] ) {
F_2 ( V_13 , L_16
L_17 , V_10 [ V_22 - 1 ] ) ;
V_2 = - V_39 ;
goto V_14;
}
V_2 = F_4 ( & V_10 [ V_22 ] , & V_35 , & V_23 ) ;
if ( V_2 ) {
F_2 ( V_4 , L_18
L_19 , V_2 ) ;
goto V_14;
}
V_22 += V_23 ;
if ( V_36 < ( V_22 + V_35 ) ) {
F_2 ( V_13 , L_20
L_21 ) ;
V_2 = - V_39 ;
goto V_14;
}
if ( V_35 < 3 ) {
F_2 ( V_13 ,
L_22
L_23 ) ;
V_2 = - V_39 ;
goto V_14;
}
* V_32 = V_10 [ V_22 ++ ] ;
V_19 -> V_41 = V_35 - 3 ;
if ( V_19 -> V_41 > V_42 ) {
F_2 ( V_13 , L_24
L_25 ,
V_19 -> V_41 ,
V_43 ) ;
V_2 = - V_39 ;
goto V_14;
}
memcpy ( V_19 -> V_44 , & V_10 [ V_22 ] ,
V_19 -> V_41 ) ;
V_22 += V_19 -> V_41 ;
V_38 += ( unsigned char ) ( V_10 [ V_22 ++ ] ) << 8 ;
V_38 += ( unsigned char ) ( V_10 [ V_22 ++ ] ) ;
for ( V_22 = 0 ; V_22 < V_19 -> V_41 ; V_22 ++ )
V_37 += V_19 -> V_44 [ V_22 ] ;
if ( V_38 != V_37 ) {
F_2 ( V_13 , L_26
L_27
L_28 , V_38 , V_37 ) ;
V_2 = - V_39 ;
}
V_14:
return V_2 ;
}
static int
F_9 ( char * V_17 , T_2 V_32 ,
struct V_45 * V_46 , char * * V_20 ,
T_1 * V_21 )
{
T_1 V_22 = 0 ;
T_1 V_47 ;
T_1 V_23 ;
T_1 V_37 = 0 ;
T_1 V_24 ;
char * V_25 ;
int V_2 ;
V_23 = ( 5 + V_26 + V_46 -> V_48 ) ;
* V_20 = F_7 ( V_23 , V_28 ) ;
V_25 = * V_20 ;
if ( ! V_25 ) {
F_2 ( V_13 , L_12 ) ;
V_2 = - V_29 ;
goto V_14;
}
V_25 [ V_22 ++ ] = V_49 ;
V_2 = F_5 ( & V_25 [ V_22 ] , V_26 ,
& V_24 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_29
L_14 ) ;
goto V_14;
}
V_22 += V_24 ;
memcpy ( & V_25 [ V_22 ] , V_17 , V_26 ) ;
V_22 += V_26 ;
V_2 = F_5 ( & V_25 [ V_22 ] , V_46 -> V_48 + 3 ,
& V_24 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_29
L_14 ) ;
goto V_14;
}
V_22 += V_24 ;
V_25 [ V_22 ++ ] = V_32 ;
memcpy ( & V_25 [ V_22 ] , V_46 -> V_50 , V_46 -> V_48 ) ;
V_22 += V_46 -> V_48 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_48 ; V_47 ++ )
V_37 += V_46 -> V_50 [ V_47 ] ;
V_25 [ V_22 ++ ] = ( V_37 / 256 ) % 256 ;
V_25 [ V_22 ++ ] = ( V_37 % 256 ) ;
* V_21 = V_22 ;
V_14:
return V_2 ;
}
static int
F_10 ( struct V_51 * V_52 ,
struct V_33 * V_34 )
{
T_1 V_22 = 0 ;
char * V_10 ;
T_1 V_23 ;
T_1 V_36 ;
int V_2 ;
V_36 = V_34 -> V_23 ;
V_10 = V_34 -> V_10 ;
if ( V_36 < 4 ) {
V_2 = - V_39 ;
F_11 ( V_13 L_30
L_31 , V_53 , V_36 , 4 ) ;
goto V_14;
}
if ( V_10 [ V_22 ++ ] != V_54 ) {
V_2 = - V_39 ;
F_11 ( V_13 L_32 ,
V_53 ) ;
goto V_14;
}
if ( V_10 [ V_22 ++ ] ) {
V_2 = - V_39 ;
F_11 ( V_13 L_33
L_34 , V_53 , V_10 [ V_22 - 1 ] ) ;
goto V_14;
}
V_2 = F_4 ( & V_10 [ V_22 ] , & V_52 -> V_55 ,
& V_23 ) ;
if ( V_2 ) {
F_2 ( V_4 , L_18
L_19 , V_2 ) ;
goto V_14;
}
V_22 += V_23 ;
if ( V_36 < ( V_22 + V_52 -> V_55 ) ) {
V_2 = - V_39 ;
F_11 ( V_13 L_35 ,
V_53 , V_36 , ( V_22 + V_52 -> V_55 ) ) ;
goto V_14;
}
if ( V_52 -> V_55 > V_43 ) {
V_2 = - V_39 ;
F_11 ( V_13 L_36
L_25 , V_53 ,
V_52 -> V_55 ,
V_43 ) ;
goto V_14;
}
memcpy ( V_52 -> V_56 , & V_10 [ V_22 ] , V_52 -> V_55 ) ;
V_14:
return V_2 ;
}
static int F_12 ( T_3 V_57 )
{
int V_2 = 0 ;
unsigned char V_58 ;
unsigned char V_59 ;
V_58 = ( ( V_57 >> 8 ) & 0xFF ) ;
V_59 = ( V_57 & 0xFF ) ;
if ( V_58 != V_60 ) {
F_2 ( V_13 , L_37
L_38 ,
V_60 , V_58 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( V_59 != V_61 ) {
F_2 ( V_13 , L_39
L_38 ,
V_61 , V_59 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_14:
return V_2 ;
}
static int
F_13 ( struct V_50 * V_62 ,
struct V_63 * * V_64 )
{
int V_2 = 0 ;
( * V_64 ) = F_14 ( V_62 ) ;
if ( F_12 ( ( * V_64 ) -> V_57 ) ) {
F_11 ( V_13 L_40
L_41
L_42 ,
V_60 , V_61 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( ( * V_64 ) -> V_65 != V_66
&& ( * V_64 ) -> V_65 != V_67 ) {
F_11 ( V_13 L_43
L_44 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_14:
return V_2 ;
}
static int
F_15 (
struct V_50 * * V_62 ,
struct V_63 * * V_64 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_71 * V_72 ;
int V_2 = 0 ;
( * V_62 ) = NULL ;
( * V_64 ) = NULL ;
F_16 ( & V_69 -> V_73 ) ;
F_17 (walker,
&mount_crypt_stat->global_auth_tok_list,
mount_crypt_stat_list) {
if ( memcmp ( V_72 -> V_70 , V_70 , V_26 ) )
continue;
if ( V_72 -> V_74 & V_75 ) {
V_2 = - V_9 ;
goto V_14;
}
V_2 = F_18 ( V_72 -> V_76 ) ;
if ( V_2 ) {
if ( V_2 == - V_6 )
goto V_14;
goto V_77;
}
F_19 ( & ( V_72 -> V_76 -> V_78 ) ) ;
V_2 = F_13 (
V_72 -> V_76 , V_64 ) ;
if ( V_2 )
goto V_79;
( * V_62 ) = V_72 -> V_76 ;
F_20 ( * V_62 ) ;
goto V_14;
}
V_2 = - V_5 ;
goto V_14;
V_79:
F_21 ( & ( V_72 -> V_76 -> V_78 ) ) ;
V_77:
F_11 ( V_4 L_45 , V_70 ) ;
V_72 -> V_74 |= V_75 ;
F_22 ( V_72 -> V_76 ) ;
V_72 -> V_76 = NULL ;
V_14:
F_23 ( & V_69 -> V_73 ) ;
return V_2 ;
}
static int
F_24 (
struct V_50 * * V_62 ,
struct V_63 * * V_64 ,
struct V_68 * V_69 ,
char * V_70 )
{
int V_2 = 0 ;
V_2 = F_15 ( V_62 , V_64 ,
V_69 , V_70 ) ;
if ( V_2 == - V_5 ) {
if ( V_69 -> V_74
& V_80 )
return - V_9 ;
V_2 = F_25 ( V_62 , V_64 ,
V_70 ) ;
}
return V_2 ;
}
int
F_26 ( char * V_15 , T_1 * V_81 ,
T_1 * V_82 ,
struct V_68 * V_69 ,
char * V_83 , T_1 V_84 )
{
struct V_85 * V_86 ;
struct V_50 * V_62 = NULL ;
int V_2 = 0 ;
V_86 = F_7 ( sizeof( * V_86 ) , V_28 ) ;
if ( ! V_86 ) {
F_11 ( V_13 L_46
L_47 , V_53 , sizeof( * V_86 ) ) ;
V_2 = - V_29 ;
goto V_14;
}
V_86 -> V_87 . V_74 = V_88 ;
( * V_82 ) = 0 ;
V_2 = F_24 (
& V_62 ,
& V_86 -> V_64 , V_69 ,
V_69 -> V_89 ) ;
if ( V_2 ) {
F_11 ( V_13 L_48
L_49 , V_53 ,
V_69 -> V_89 , V_2 ) ;
goto V_14;
}
V_2 = F_27 (
& V_86 -> V_87 . V_90 ,
& V_86 -> V_91 , V_69 -> V_92 ) ;
if ( F_28 ( V_2 ) ) {
F_11 ( V_13 L_50
L_51 ,
V_69 -> V_92 , V_2 ) ;
goto V_14;
}
F_16 ( V_86 -> V_91 ) ;
V_86 -> V_93 = F_29 ( V_86 -> V_87 . V_90 ) ;
V_86 -> V_94 = ( V_95 + 1 ) ;
V_86 -> V_96 = ( V_86 -> V_94 + V_84 ) ;
if ( ( V_86 -> V_96 % V_86 -> V_93 ) != 0 ) {
V_86 -> V_94 += ( V_86 -> V_93
- ( V_86 -> V_96
% V_86 -> V_93 ) ) ;
V_86 -> V_96 = ( V_86 -> V_94
+ V_84 ) ;
}
V_86 -> V_97 = ( V_98
+ V_86 -> V_96 ) ;
if ( V_15 == NULL ) {
( * V_82 ) = V_86 -> V_97 ;
goto V_99;
}
if ( V_86 -> V_97 > ( * V_81 ) ) {
F_11 ( V_4 L_52
L_53 , V_53 , V_86 -> V_97 ,
( * V_81 ) ) ;
V_2 = - V_9 ;
goto V_99;
}
V_86 -> V_100 = F_30 ( V_86 -> V_96 ,
V_28 ) ;
if ( ! V_86 -> V_100 ) {
F_11 ( V_13 L_54
L_55 , V_53 ,
V_86 -> V_96 ) ;
V_2 = - V_29 ;
goto V_99;
}
V_86 -> V_22 = 0 ;
V_15 [ V_86 -> V_22 ++ ] = V_101 ;
V_2 = F_5 ( & V_15 [ V_86 -> V_22 ] ,
( V_102
+ 1
+ V_86 -> V_96 ) ,
& V_86 -> V_24 ) ;
if ( V_2 ) {
F_11 ( V_13 L_56
L_57 ,
V_53 , V_2 ) ;
goto V_103;
}
V_86 -> V_22 += V_86 -> V_24 ;
F_31 ( & V_15 [ V_86 -> V_22 ] ,
V_69 -> V_89 ,
V_102 ) ;
V_86 -> V_22 += V_102 ;
V_86 -> V_32 = F_32 (
V_69 -> V_92 ,
V_69 -> V_104 ) ;
if ( V_86 -> V_32 == 0 ) {
F_11 ( V_4 L_58
L_59 , V_53 ,
V_69 -> V_92 ,
V_69 -> V_104 ) ;
V_2 = - V_9 ;
goto V_103;
}
V_15 [ V_86 -> V_22 ++ ] = V_86 -> V_32 ;
if ( V_86 -> V_64 -> V_65 != V_66 ) {
V_2 = - V_105 ;
F_11 ( V_106 L_60
L_61 , V_53 ) ;
goto V_103;
}
F_33 (
& V_86 -> V_107 ,
( T_2 * ) V_86 -> V_64 -> V_108 . V_109 . V_110 ,
V_86 -> V_64 -> V_108 . V_109 . V_111 ) ;
V_86 -> V_112 . V_74 = V_88 ;
V_86 -> V_112 . V_90 = F_34 ( V_113 , 0 ,
V_114 ) ;
if ( F_35 ( V_86 -> V_112 . V_90 ) ) {
V_2 = F_36 ( V_86 -> V_112 . V_90 ) ;
F_11 ( V_13 L_62
L_63 ,
V_53 , V_2 ) ;
goto V_103;
}
V_2 = F_37 ( & V_86 -> V_112 ) ;
if ( V_2 ) {
F_11 ( V_13
L_64 ,
V_53 , V_2 ) ;
goto V_115;
}
V_2 = F_38 (
& V_86 -> V_112 , & V_86 -> V_107 ,
V_86 -> V_64 -> V_108 . V_109 . V_111 ) ;
if ( V_2 ) {
F_11 ( V_13
L_65 ,
V_53 , V_2 ) ;
goto V_115;
}
V_2 = F_39 ( & V_86 -> V_112 , V_86 -> V_116 ) ;
if ( V_2 ) {
F_11 ( V_13
L_66 ,
V_53 , V_2 ) ;
goto V_115;
}
for ( V_86 -> V_47 = 0 ; V_86 -> V_47 < ( V_86 -> V_94 - 1 ) ; V_86 -> V_47 ++ ) {
V_86 -> V_100 [ V_86 -> V_47 ] =
V_86 -> V_116 [ ( V_86 -> V_47 % V_117 ) ] ;
if ( ( V_86 -> V_47 % V_117 )
== ( V_117 - 1 ) ) {
F_33 ( & V_86 -> V_107 , ( T_2 * ) V_86 -> V_116 ,
V_117 ) ;
V_2 = F_37 ( & V_86 -> V_112 ) ;
if ( V_2 ) {
F_11 ( V_13
L_67
L_19 , V_53 , V_2 ) ;
goto V_115;
}
V_2 = F_38 ( & V_86 -> V_112 , & V_86 -> V_107 ,
V_117 ) ;
if ( V_2 ) {
F_11 ( V_13
L_68
L_19 , V_53 , V_2 ) ;
goto V_115;
}
V_2 = F_39 ( & V_86 -> V_112 , V_86 -> V_118 ) ;
if ( V_2 ) {
F_11 ( V_13
L_69
L_19 , V_53 , V_2 ) ;
goto V_115;
}
memcpy ( V_86 -> V_116 , V_86 -> V_118 ,
V_117 ) ;
}
if ( V_86 -> V_100 [ V_86 -> V_47 ] == '\0' )
V_86 -> V_100 [ V_86 -> V_47 ] = V_119 ;
}
memcpy ( & V_86 -> V_100 [ V_86 -> V_94 ] , V_83 ,
V_84 ) ;
V_2 = F_40 ( V_86 -> V_100 ,
V_86 -> V_96 , V_86 -> V_120 , 2 ) ;
if ( V_2 < 1 ) {
F_11 ( V_13 L_70
L_71
L_72 , V_53 , V_2 ,
V_86 -> V_96 ) ;
goto V_115;
}
V_2 = F_40 ( & V_15 [ V_86 -> V_22 ] , V_86 -> V_96 ,
V_86 -> V_121 , 2 ) ;
if ( V_2 < 1 ) {
F_11 ( V_13 L_70
L_73
L_74 ,
V_53 , V_2 , V_86 -> V_96 ) ;
goto V_115;
}
memset ( V_86 -> V_122 , 0 , V_123 ) ;
V_86 -> V_87 . V_124 = V_86 -> V_122 ;
V_2 = F_41 (
V_86 -> V_87 . V_90 ,
V_86 -> V_64 -> V_108 . V_109 . V_110 ,
V_69 -> V_104 ) ;
if ( V_2 < 0 ) {
F_11 ( V_13 L_75
L_76
L_77
L_78 , V_53 ,
V_2 ,
V_86 -> V_64 -> V_108 . V_109 . V_110 ,
V_69 -> V_104 ) ;
goto V_115;
}
V_2 = F_42 ( & V_86 -> V_87 , V_86 -> V_121 , V_86 -> V_120 ,
V_86 -> V_96 ) ;
if ( V_2 ) {
F_11 ( V_13 L_79
L_19 , V_53 , V_2 ) ;
goto V_115;
}
V_86 -> V_22 += V_86 -> V_96 ;
( * V_82 ) = V_86 -> V_22 ;
( * V_81 ) -= ( * V_82 ) ;
V_115:
F_43 ( V_86 -> V_112 . V_90 ) ;
V_103:
F_44 ( V_86 -> V_100 ) ;
V_99:
F_23 ( V_86 -> V_91 ) ;
V_14:
if ( V_62 ) {
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
}
F_45 ( V_86 ) ;
return V_2 ;
}
int
F_46 ( char * * V_83 , T_1 * V_84 ,
T_1 * V_82 ,
struct V_68 * V_69 ,
char * V_10 , T_1 V_97 )
{
struct V_125 * V_86 ;
struct V_50 * V_62 = NULL ;
int V_2 = 0 ;
( * V_82 ) = 0 ;
( * V_84 ) = 0 ;
( * V_83 ) = NULL ;
V_86 = F_7 ( sizeof( * V_86 ) , V_28 ) ;
if ( ! V_86 ) {
F_11 ( V_13 L_46
L_47 , V_53 , sizeof( * V_86 ) ) ;
V_2 = - V_29 ;
goto V_14;
}
V_86 -> V_87 . V_74 = V_88 ;
if ( V_97 < V_126 ) {
F_11 ( V_4 L_80
L_81 , V_53 , V_97 ,
V_126 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( V_10 [ ( * V_82 ) ++ ] != V_101 ) {
F_11 ( V_4 L_82
L_83 , V_53 ,
V_10 [ ( ( * V_82 ) - 1 ) ] , V_101 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_2 = F_4 ( & V_10 [ ( * V_82 ) ] ,
& V_86 -> V_127 ,
& V_86 -> V_24 ) ;
if ( V_2 ) {
F_11 ( V_4 L_84
L_19 , V_53 , V_2 ) ;
goto V_14;
}
V_86 -> V_96 = ( V_86 -> V_127
- V_102 - 1 ) ;
if ( ( 1 + V_86 -> V_24 + V_86 -> V_127 )
> V_97 ) {
F_11 ( V_4 L_85
L_86 , V_53 , V_97 ,
( 1 + V_86 -> V_24 + 1
+ V_86 -> V_96 ) ) ;
V_2 = - V_9 ;
goto V_14;
}
( * V_82 ) += V_86 -> V_24 ;
F_47 ( V_86 -> V_128 , & V_10 [ ( * V_82 ) ] ,
V_102 ) ;
V_86 -> V_128 [ V_26 ] = '\0' ;
( * V_82 ) += V_102 ;
V_86 -> V_32 = V_10 [ ( * V_82 ) ++ ] ;
V_2 = F_48 ( V_86 -> V_129 , V_86 -> V_32 ) ;
if ( V_2 ) {
F_11 ( V_4 L_87 ,
V_53 , V_86 -> V_32 ) ;
goto V_14;
}
V_2 = F_24 ( & V_62 ,
& V_86 -> V_64 , V_69 ,
V_86 -> V_128 ) ;
if ( V_2 ) {
F_11 ( V_13 L_48
L_49 , V_53 , V_86 -> V_128 ,
V_2 ) ;
goto V_14;
}
V_2 = F_27 ( & V_86 -> V_87 . V_90 ,
& V_86 -> V_91 ,
V_86 -> V_129 ) ;
if ( F_28 ( V_2 ) ) {
F_11 ( V_13 L_50
L_51 ,
V_86 -> V_129 , V_2 ) ;
goto V_14;
}
F_16 ( V_86 -> V_91 ) ;
V_2 = F_40 ( & V_10 [ ( * V_82 ) ] ,
V_86 -> V_96 , V_86 -> V_120 , 2 ) ;
if ( V_2 < 1 ) {
F_11 ( V_13 L_70
L_73
L_74 ,
V_53 , V_2 , V_86 -> V_96 ) ;
goto V_99;
}
( * V_82 ) += V_86 -> V_96 ;
V_86 -> V_130 = F_7 ( V_86 -> V_96 ,
V_28 ) ;
if ( ! V_86 -> V_130 ) {
F_11 ( V_13 L_88
L_89 , V_53 ,
V_86 -> V_96 ) ;
V_2 = - V_29 ;
goto V_99;
}
V_2 = F_40 ( V_86 -> V_130 ,
V_86 -> V_96 , V_86 -> V_121 , 2 ) ;
if ( V_2 < 1 ) {
F_11 ( V_13 L_70
L_90
L_74 ,
V_53 , V_2 , V_86 -> V_96 ) ;
goto V_103;
}
memset ( V_86 -> V_122 , 0 , V_123 ) ;
V_86 -> V_87 . V_124 = V_86 -> V_122 ;
if ( V_86 -> V_64 -> V_65 != V_66 ) {
V_2 = - V_105 ;
F_11 ( V_106 L_60
L_61 , V_53 ) ;
goto V_103;
}
V_2 = F_41 (
V_86 -> V_87 . V_90 ,
V_86 -> V_64 -> V_108 . V_109 . V_110 ,
V_69 -> V_104 ) ;
if ( V_2 < 0 ) {
F_11 ( V_13 L_75
L_76
L_77
L_78 , V_53 ,
V_2 ,
V_86 -> V_64 -> V_108 . V_109 . V_110 ,
V_69 -> V_104 ) ;
goto V_103;
}
V_2 = F_49 ( & V_86 -> V_87 , V_86 -> V_121 , V_86 -> V_120 ,
V_86 -> V_96 ) ;
if ( V_2 ) {
F_11 ( V_13 L_91
L_19 , V_53 , V_2 ) ;
goto V_103;
}
V_86 -> V_22 = 0 ;
while ( V_86 -> V_130 [ V_86 -> V_22 ] != '\0'
&& V_86 -> V_22 < V_86 -> V_96 )
V_86 -> V_22 ++ ;
if ( V_86 -> V_22 == V_86 -> V_96 ) {
F_11 ( V_4 L_92
L_93
L_94 , V_53 ) ;
V_2 = - V_9 ;
goto V_103;
}
V_86 -> V_22 ++ ;
( * V_84 ) = ( V_86 -> V_96 - V_86 -> V_22 ) ;
if ( ! ( ( * V_84 ) > 0 && ( * V_84 < V_131 ) ) ) {
F_11 ( V_4 L_95
L_96 , V_53 , ( * V_84 ) ) ;
V_2 = - V_9 ;
goto V_103;
}
( * V_83 ) = F_7 ( ( ( * V_84 ) + 1 ) , V_28 ) ;
if ( ! ( * V_83 ) ) {
F_11 ( V_13 L_88
L_89 , V_53 ,
( ( * V_84 ) + 1 ) ) ;
V_2 = - V_29 ;
goto V_103;
}
memcpy ( ( * V_83 ) , & V_86 -> V_130 [ V_86 -> V_22 ] , ( * V_84 ) ) ;
( * V_83 ) [ ( * V_84 ) ] = '\0' ;
V_103:
F_45 ( V_86 -> V_130 ) ;
V_99:
F_23 ( V_86 -> V_91 ) ;
V_14:
if ( V_2 ) {
( * V_82 ) = 0 ;
( * V_84 ) = 0 ;
( * V_83 ) = NULL ;
}
if ( V_62 ) {
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
}
F_45 ( V_86 ) ;
return V_2 ;
}
static int
F_50 ( char * * V_70 , struct V_63 * V_64 )
{
int V_2 = 0 ;
( * V_70 ) = NULL ;
switch ( V_64 -> V_65 ) {
case V_66 :
( * V_70 ) = V_64 -> V_108 . V_109 . V_17 ;
break;
case V_67 :
( * V_70 ) = V_64 -> V_108 . V_132 . V_17 ;
break;
default:
F_11 ( V_13 L_97 ,
V_64 -> V_65 ) ;
V_2 = - V_9 ;
}
return V_2 ;
}
static int
F_51 ( struct V_63 * V_64 ,
struct V_45 * V_46 )
{
T_2 V_32 = 0 ;
struct V_133 * V_134 ;
struct V_33 * V_34 = NULL ;
char * V_135 ;
char * V_136 = NULL ;
T_1 V_137 = 0 ;
int V_2 ;
V_2 = F_50 ( & V_135 , V_64 ) ;
if ( V_2 ) {
F_11 ( V_13 L_98 ,
V_64 -> V_65 ) ;
goto V_14;
}
V_2 = F_6 ( V_135 , & ( V_64 -> V_19 ) ,
& V_136 , & V_137 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_99 ) ;
goto V_14;
}
V_2 = F_52 ( V_136 , V_137 , & V_134 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_100
L_101 , V_2 ) ;
goto V_14;
}
V_2 = F_53 ( V_134 , & V_34 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_102
L_103 ) ;
V_2 = - V_39 ;
goto V_14;
}
V_2 = F_8 ( & ( V_64 -> V_19 ) ,
& V_32 , V_34 ) ;
if ( V_2 ) {
F_11 ( V_13 L_104 ,
V_2 ) ;
goto V_14;
}
V_64 -> V_19 . V_74 |= V_138 ;
memcpy ( V_46 -> V_50 , V_64 -> V_19 . V_44 ,
V_64 -> V_19 . V_41 ) ;
V_46 -> V_48 = V_64 -> V_19 . V_41 ;
V_2 = F_48 ( V_46 -> V_139 , V_32 ) ;
if ( V_2 ) {
F_2 (KERN_ERR, L_105 ,
cipher_code)
goto V_14;
}
V_46 -> V_74 |= V_140 ;
if ( V_141 > 0 ) {
F_2 ( V_142 , L_106 ) ;
F_54 ( V_46 -> V_50 ,
V_46 -> V_48 ) ;
}
V_14:
F_45 ( V_34 ) ;
F_45 ( V_136 ) ;
return V_2 ;
}
static void F_55 ( struct V_143 * V_144 )
{
struct V_145 * V_146 ;
struct V_145 * V_147 ;
F_56 (auth_tok_list_item, auth_tok_list_item_tmp,
auth_tok_list_head, list) {
F_57 ( & V_146 -> V_148 ) ;
F_58 ( V_149 ,
V_146 ) ;
}
}
static int
F_59 ( struct V_45 * V_46 ,
unsigned char * V_10 , struct V_143 * V_150 ,
struct V_63 * * V_151 ,
T_1 * V_82 , T_1 V_97 )
{
T_1 V_152 ;
struct V_145 * V_146 ;
T_1 V_12 ;
int V_2 = 0 ;
( * V_82 ) = 0 ;
( * V_151 ) = NULL ;
if ( F_28 ( V_97 < 12 ) ) {
F_11 ( V_13 L_107 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( V_10 [ ( * V_82 ) ++ ] != V_153 ) {
F_11 ( V_13 L_108 ,
V_153 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_146 =
F_60 ( V_149 ,
V_28 ) ;
if ( ! V_146 ) {
F_11 ( V_13 L_12 ) ;
V_2 = - V_29 ;
goto V_14;
}
( * V_151 ) = & V_146 -> V_64 ;
V_2 = F_4 ( & V_10 [ ( * V_82 ) ] , & V_152 ,
& V_12 ) ;
if ( V_2 ) {
F_11 ( V_4 L_18
L_19 , V_2 ) ;
goto V_154;
}
if ( F_28 ( V_152 < ( V_102 + 2 ) ) ) {
F_11 ( V_4 L_109 , V_152 ) ;
V_2 = - V_9 ;
goto V_154;
}
( * V_82 ) += V_12 ;
if ( F_28 ( ( * V_82 ) + V_152 > V_97 ) ) {
F_11 ( V_4 L_110 ) ;
V_2 = - V_9 ;
goto V_154;
}
if ( F_28 ( V_10 [ ( * V_82 ) ++ ] != 0x03 ) ) {
F_11 ( V_4 L_111 ,
V_10 [ ( * V_82 ) - 1 ] ) ;
V_2 = - V_9 ;
goto V_154;
}
F_47 ( ( * V_151 ) -> V_108 . V_132 . V_17 ,
& V_10 [ ( * V_82 ) ] , V_102 ) ;
* V_82 += V_102 ;
( * V_82 ) ++ ;
( * V_151 ) -> V_19 . V_27 =
V_152 - ( V_102 + 2 ) ;
if ( ( * V_151 ) -> V_19 . V_27
> V_43 ) {
F_11 ( V_4 L_112
L_113 ) ;
V_2 = - V_9 ;
goto V_14;
}
memcpy ( ( * V_151 ) -> V_19 . V_31 ,
& V_10 [ ( * V_82 ) ] , ( V_152 - ( V_102 + 2 ) ) ) ;
( * V_82 ) += ( * V_151 ) -> V_19 . V_27 ;
( * V_151 ) -> V_19 . V_74 &=
~ V_138 ;
( * V_151 ) -> V_19 . V_74 |=
V_155 ;
( * V_151 ) -> V_65 = V_67 ;
( * V_151 ) -> V_74 = 0 ;
( * V_151 ) -> V_19 . V_74 &=
~ ( V_156 ) ;
( * V_151 ) -> V_19 . V_74 &=
~ ( V_157 ) ;
F_61 ( & V_146 -> V_148 , V_150 ) ;
goto V_14;
V_154:
( * V_151 ) = NULL ;
memset ( V_146 , 0 ,
sizeof( struct V_145 ) ) ;
F_58 ( V_149 ,
V_146 ) ;
V_14:
if ( V_2 )
( * V_82 ) = 0 ;
return V_2 ;
}
static int
F_62 ( struct V_45 * V_46 ,
unsigned char * V_10 , struct V_143 * V_150 ,
struct V_63 * * V_151 ,
T_1 * V_82 , T_1 V_97 )
{
T_1 V_152 ;
struct V_145 * V_146 ;
T_1 V_12 ;
int V_2 = 0 ;
( * V_82 ) = 0 ;
( * V_151 ) = NULL ;
if ( V_97 < ( V_158 + 7 ) ) {
F_11 ( V_13 L_114 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( V_10 [ ( * V_82 ) ++ ] != V_159 ) {
F_11 ( V_13 L_115 ,
V_159 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_146 =
F_60 ( V_149 , V_28 ) ;
if ( ! V_146 ) {
F_11 ( V_13 L_12 ) ;
V_2 = - V_29 ;
goto V_14;
}
( * V_151 ) = & V_146 -> V_64 ;
V_2 = F_4 ( & V_10 [ ( * V_82 ) ] , & V_152 ,
& V_12 ) ;
if ( V_2 ) {
F_11 ( V_4 L_116 ,
V_2 ) ;
goto V_154;
}
if ( F_28 ( V_152 < ( V_158 + 5 ) ) ) {
F_11 ( V_4 L_109 , V_152 ) ;
V_2 = - V_9 ;
goto V_154;
}
( * V_82 ) += V_12 ;
if ( F_28 ( ( * V_82 ) + V_152 > V_97 ) ) {
F_11 ( V_13 L_110 ) ;
V_2 = - V_9 ;
goto V_154;
}
( * V_151 ) -> V_19 . V_27 =
( V_152 - ( V_158 + 5 ) ) ;
if ( ( * V_151 ) -> V_19 . V_27
> V_43 ) {
F_11 ( V_4 L_117
L_118 ) ;
V_2 = - V_9 ;
goto V_154;
}
if ( F_28 ( V_10 [ ( * V_82 ) ++ ] != 0x04 ) ) {
F_11 ( V_4 L_111 ,
V_10 [ ( * V_82 ) - 1 ] ) ;
V_2 = - V_9 ;
goto V_154;
}
V_2 = F_48 ( V_46 -> V_139 ,
( T_3 ) V_10 [ ( * V_82 ) ] ) ;
if ( V_2 )
goto V_154;
switch( V_10 [ ( * V_82 ) ++ ] ) {
case V_160 :
V_46 -> V_48 = 24 ;
break;
default:
V_46 -> V_48 =
( * V_151 ) -> V_19 . V_27 ;
}
V_2 = F_63 ( V_46 ) ;
if ( V_2 )
goto V_154;
if ( F_28 ( V_10 [ ( * V_82 ) ++ ] != 0x03 ) ) {
F_11 ( V_4 L_119 ) ;
V_2 = - V_161 ;
goto V_154;
}
switch ( V_10 [ ( * V_82 ) ++ ] ) {
case 0x01 :
memcpy ( ( * V_151 ) -> V_108 . V_109 . V_162 ,
& V_10 [ ( * V_82 ) ] , V_158 ) ;
( * V_82 ) += V_158 ;
( * V_151 ) -> V_108 . V_109 . V_163 =
( ( V_164 ) 16 + ( V_10 [ ( * V_82 ) ] & 15 ) )
<< ( ( V_10 [ ( * V_82 ) ] >> 4 ) + 6 ) ;
( * V_82 ) ++ ;
memcpy ( ( * V_151 ) -> V_19 . V_31 ,
& V_10 [ ( * V_82 ) ] ,
( * V_151 ) -> V_19 . V_27 ) ;
( * V_82 ) +=
( * V_151 ) -> V_19 . V_27 ;
( * V_151 ) -> V_19 . V_74 &=
~ V_138 ;
( * V_151 ) -> V_19 . V_74 |=
V_155 ;
( * V_151 ) -> V_108 . V_109 . V_165 = 0x01 ;
break;
default:
F_2 ( V_13 , L_120
L_17 , V_10 [ ( * V_82 ) - 1 ] ) ;
V_2 = - V_161 ;
goto V_154;
}
( * V_151 ) -> V_65 = V_66 ;
( * V_151 ) -> V_19 . V_74 &=
~ ( V_156 ) ;
( * V_151 ) -> V_19 . V_74 &=
~ ( V_157 ) ;
F_61 ( & V_146 -> V_148 , V_150 ) ;
goto V_14;
V_154:
( * V_151 ) = NULL ;
memset ( V_146 , 0 ,
sizeof( struct V_145 ) ) ;
F_58 ( V_149 ,
V_146 ) ;
V_14:
if ( V_2 )
( * V_82 ) = 0 ;
return V_2 ;
}
static int
F_64 ( unsigned char * V_10 , unsigned char * V_166 ,
T_1 V_167 , T_1 * V_168 ,
T_1 * V_82 , T_1 V_97 )
{
T_1 V_152 ;
T_1 V_12 ;
int V_2 = 0 ;
( * V_82 ) = 0 ;
( * V_168 ) = 0 ;
if ( V_97 < 16 ) {
F_11 ( V_13 L_121 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( V_10 [ ( * V_82 ) ++ ] != V_169 ) {
F_11 ( V_4 L_122 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_2 = F_4 ( & V_10 [ ( * V_82 ) ] , & V_152 ,
& V_12 ) ;
if ( V_2 ) {
F_11 ( V_4 L_122 ) ;
goto V_14;
}
if ( V_152 < 14 ) {
F_11 ( V_4 L_109 , V_152 ) ;
V_2 = - V_9 ;
goto V_14;
}
( * V_82 ) += V_12 ;
( * V_168 ) = ( V_152 - 14 ) ;
if ( F_28 ( ( * V_82 ) + V_152 + 1 > V_97 ) ) {
F_11 ( V_13 L_110 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( F_28 ( ( * V_168 ) > V_167 ) ) {
F_11 ( V_13 L_123
L_124 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( V_10 [ ( * V_82 ) ++ ] != 0x62 ) {
F_11 ( V_4 L_125 ) ;
V_2 = - V_9 ;
goto V_14;
}
if ( V_10 [ ( * V_82 ) ++ ] != 0x08 ) {
F_11 ( V_4 L_125 ) ;
V_2 = - V_9 ;
goto V_14;
}
( * V_82 ) += 12 ;
memcpy ( V_166 , & V_10 [ ( * V_82 ) ] , ( * V_168 ) ) ;
( * V_82 ) += ( * V_168 ) ;
V_14:
if ( V_2 ) {
( * V_82 ) = 0 ;
( * V_168 ) = 0 ;
}
return V_2 ;
}
int F_25 ( struct V_50 * * V_62 ,
struct V_63 * * V_64 ,
char * V_70 )
{
int V_2 = 0 ;
( * V_62 ) = F_65 ( & V_170 , V_70 , NULL ) ;
if ( ! ( * V_62 ) || F_35 ( * V_62 ) ) {
( * V_62 ) = F_66 ( V_70 ) ;
if ( ! ( * V_62 ) || F_35 ( * V_62 ) ) {
F_11 ( V_13 L_126 ,
V_70 ) ;
V_2 = F_1 ( F_36 ( * V_62 ) ) ;
( * V_62 ) = NULL ;
goto V_14;
}
}
F_19 ( & ( * V_62 ) -> V_78 ) ;
V_2 = F_13 ( * V_62 , V_64 ) ;
if ( V_2 ) {
F_21 ( & ( * V_62 ) -> V_78 ) ;
F_22 ( * V_62 ) ;
( * V_62 ) = NULL ;
goto V_14;
}
V_14:
return V_2 ;
}
static int
F_67 ( struct V_63 * V_64 ,
struct V_45 * V_46 )
{
struct V_171 V_121 [ 2 ] ;
struct V_171 V_120 [ 2 ] ;
struct V_172 * V_91 ;
struct V_173 V_87 = {
. V_74 = V_88
} ;
int V_2 = 0 ;
if ( F_28 ( V_141 > 0 ) ) {
F_2 (
V_142 , L_127 ,
V_64 -> V_108 . V_109 . V_111 ) ;
F_54 (
V_64 -> V_108 . V_109 . V_110 ,
V_64 -> V_108 . V_109 . V_111 ) ;
}
V_2 = F_27 ( & V_87 . V_90 , & V_91 ,
V_46 -> V_139 ) ;
if ( F_28 ( V_2 ) ) {
F_11 ( V_13 L_50
L_51 ,
V_46 -> V_139 , V_2 ) ;
goto V_14;
}
V_2 = F_40 ( V_64 -> V_19 . V_31 ,
V_64 -> V_19 . V_27 ,
V_120 , 2 ) ;
if ( V_2 < 1 || V_2 > 2 ) {
F_11 ( V_13 L_128
L_129
L_130
L_131 , V_2 ,
V_64 -> V_19 . V_27 ) ;
goto V_14;
}
V_64 -> V_19 . V_41 =
V_64 -> V_19 . V_27 ;
V_2 = F_40 ( V_64 -> V_19 . V_44 ,
V_64 -> V_19 . V_41 ,
V_121 , 2 ) ;
if ( V_2 < 1 || V_2 > 2 ) {
F_11 ( V_13 L_128
L_132
L_133 , V_2 ) ;
goto V_14;
}
F_16 ( V_91 ) ;
V_2 = F_41 (
V_87 . V_90 , V_64 -> V_108 . V_109 . V_110 ,
V_46 -> V_48 ) ;
if ( F_28 ( V_2 < 0 ) ) {
F_23 ( V_91 ) ;
F_11 ( V_13 L_134 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_2 = F_68 ( & V_87 , V_121 , V_120 ,
V_64 -> V_19 . V_27 ) ;
F_23 ( V_91 ) ;
if ( F_28 ( V_2 ) ) {
F_11 ( V_13 L_135 , V_2 ) ;
goto V_14;
}
V_64 -> V_19 . V_74 |= V_138 ;
memcpy ( V_46 -> V_50 , V_64 -> V_19 . V_44 ,
V_64 -> V_19 . V_41 ) ;
V_46 -> V_74 |= V_140 ;
if ( F_28 ( V_141 > 0 ) ) {
F_2 ( V_142 , L_136 ,
V_46 -> V_48 ) ;
F_54 ( V_46 -> V_50 ,
V_46 -> V_48 ) ;
}
V_14:
return V_2 ;
}
int F_69 ( struct V_45 * V_46 ,
unsigned char * V_174 ,
struct V_175 * V_176 )
{
T_1 V_22 = 0 ;
T_1 V_177 ;
T_1 V_178 ;
struct V_143 V_150 ;
struct V_63 * V_179 ;
struct V_63 * V_180 ;
char * V_181 ;
T_1 V_82 ;
struct V_63 * V_151 ;
unsigned char V_182 [ V_102 ] ;
struct V_145 * V_146 ;
T_1 V_168 ;
T_1 V_183 ;
struct V_50 * V_62 = NULL ;
int V_2 = 0 ;
F_70 ( & V_150 ) ;
V_178 = 1 ;
while ( V_178 ) {
T_1 V_97 = ( ( V_184 - 8 ) - V_22 ) ;
switch ( V_174 [ V_22 ] ) {
case V_159 :
V_2 = F_62 ( V_46 ,
( unsigned char * ) & V_174 [ V_22 ] ,
& V_150 , & V_151 ,
& V_82 , V_97 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_137
L_138 ) ;
V_2 = - V_39 ;
goto V_185;
}
V_22 += V_82 ;
V_2 = F_64 ( ( unsigned char * ) & V_174 [ V_22 ] ,
V_182 ,
V_102 ,
& V_168 ,
& V_183 ,
V_97 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_139
L_140
L_141
L_142
L_143
L_138 ) ;
V_2 = - V_39 ;
goto V_185;
}
V_22 += V_183 ;
if ( V_102 != V_168 ) {
F_2 ( V_13 , L_144
L_145
L_146 ,
V_102 ,
V_168 ) ;
V_2 = - V_39 ;
goto V_185;
}
F_47 ( V_151 -> V_108 . V_109 . V_17 ,
V_182 , V_168 ) ;
V_151 -> V_108 . V_109 . V_17 [
V_186 ] = '\0' ;
V_46 -> V_74 |= V_187 ;
break;
case V_153 :
V_2 = F_59 ( V_46 ,
( unsigned char * ) & V_174 [ V_22 ] ,
& V_150 , & V_151 ,
& V_82 , V_97 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_137
L_147 ) ;
V_2 = - V_39 ;
goto V_185;
}
V_22 += V_82 ;
V_46 -> V_74 |= V_187 ;
break;
case V_169 :
F_2 ( V_4 , L_148
L_149 ) ;
V_2 = - V_39 ;
goto V_185;
default:
F_2 ( V_142 , L_150
L_151
L_152 , V_22 , V_174 [ V_22 ] ) ;
V_178 = 0 ;
}
}
if ( F_71 ( & V_150 ) ) {
F_11 ( V_13 L_153
L_154
L_155 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_188:
V_177 = 0 ;
F_17 (auth_tok_list_item, &auth_tok_list, list) {
V_180 = & V_146 -> V_64 ;
if ( F_28 ( V_141 > 0 ) ) {
F_2 ( V_142 ,
L_156 ) ;
F_72 ( V_180 ) ;
}
V_2 = F_50 ( & V_181 ,
V_180 ) ;
if ( V_2 ) {
F_11 ( V_13
L_157 ,
V_180 -> V_65 ) ;
V_2 = - V_9 ;
goto V_185;
}
V_2 = F_24 ( & V_62 ,
& V_179 ,
V_46 -> V_69 ,
V_181 ) ;
if ( ! V_2 ) {
V_177 = 1 ;
goto V_189;
}
}
if ( ! V_177 ) {
F_2 ( V_13 , L_158
L_159 ) ;
V_2 = - V_39 ;
goto V_185;
}
V_189:
if ( V_180 -> V_65 == V_67 ) {
memcpy ( & ( V_180 -> V_108 . V_132 ) ,
& ( V_179 -> V_108 . V_132 ) ,
sizeof( struct V_190 ) ) ;
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
V_2 = F_51 ( V_180 ,
V_46 ) ;
} else if ( V_180 -> V_65 == V_66 ) {
memcpy ( & ( V_180 -> V_108 . V_109 ) ,
& ( V_179 -> V_108 . V_109 ) ,
sizeof( struct V_191 ) ) ;
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
V_2 = F_67 (
V_180 , V_46 ) ;
} else {
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
V_2 = - V_9 ;
}
if ( V_2 ) {
struct V_145 * V_147 ;
F_2 ( V_4 , L_160
L_161
L_162
L_163
L_164 , V_26 ,
V_181 , V_2 ) ;
F_56 (auth_tok_list_item,
auth_tok_list_item_tmp,
&auth_tok_list, list) {
if ( V_180
== & V_146 -> V_64 ) {
F_57 ( & V_146 -> V_148 ) ;
F_58 (
V_149 ,
V_146 ) ;
goto V_188;
}
}
F_73 () ;
}
V_2 = F_74 ( V_46 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_165
L_166 ) ;
goto V_185;
}
V_2 = F_63 ( V_46 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_167
L_168 ,
V_46 -> V_139 , V_2 ) ;
}
V_185:
F_55 ( & V_150 ) ;
V_14:
return V_2 ;
}
static int
F_75 ( struct V_50 * V_62 ,
struct V_63 * V_64 ,
struct V_45 * V_46 ,
struct V_51 * V_52 )
{
struct V_133 * V_134 = NULL ;
char * V_136 = NULL ;
T_1 V_137 = 0 ;
struct V_33 * V_34 ;
int V_2 ;
V_2 = F_9 ( V_64 -> V_108 . V_132 . V_17 ,
F_32 (
V_46 -> V_139 ,
V_46 -> V_48 ) ,
V_46 , & V_136 , & V_137 ) ;
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_169 ) ;
goto V_14;
}
V_2 = F_52 ( V_136 , V_137 , & V_134 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_100
L_101 , V_2 ) ;
goto V_14;
}
V_2 = F_53 ( V_134 , & V_34 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_170
L_103 ) ;
V_2 = - V_39 ;
goto V_14;
}
V_2 = F_10 ( V_52 , V_34 ) ;
if ( V_2 )
F_2 ( V_13 , L_171 ) ;
F_45 ( V_34 ) ;
V_14:
F_45 ( V_136 ) ;
return V_2 ;
}
static int
F_76 ( char * V_15 , T_1 * V_81 ,
struct V_50 * V_62 , struct V_63 * V_64 ,
struct V_45 * V_46 ,
struct V_51 * V_52 , T_1 * V_82 )
{
T_1 V_22 ;
T_1 V_192 = 0 ;
T_1 V_16 ;
T_1 V_97 ;
int V_2 = 0 ;
( * V_82 ) = 0 ;
F_31 ( V_52 -> V_70 , V_64 -> V_108 . V_132 . V_17 ,
V_102 ) ;
V_192 = 0 ;
for ( V_22 = 0 ; V_22 < V_46 -> V_48 ; V_22 ++ )
V_192 |=
V_64 -> V_19 . V_31 [ V_22 ] ;
if ( V_192 ) {
memcpy ( V_52 -> V_56 ,
V_64 -> V_19 . V_31 ,
V_64 -> V_19 . V_27 ) ;
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
goto V_193;
}
if ( V_64 -> V_19 . V_27 == 0 )
V_64 -> V_19 . V_27 =
V_64 -> V_108 . V_132 . V_48 ;
V_2 = F_75 ( V_62 , V_64 , V_46 ,
V_52 ) ;
if ( V_2 ) {
F_11 ( V_13 L_172
L_173 , V_2 ) ;
goto V_14;
}
if ( V_141 > 0 ) {
F_2 ( V_142 , L_174 ) ;
F_54 ( V_52 -> V_56 , V_52 -> V_55 ) ;
}
V_193:
V_97 = ( 1
+ 3
+ 1
+ V_102
+ 1
+ V_52 -> V_55 ) ;
if ( V_97 > ( * V_81 ) ) {
F_11 ( V_13 L_175
L_176
L_177 , V_97 , ( * V_81 ) ) ;
V_2 = - V_9 ;
goto V_14;
}
V_15 [ ( * V_82 ) ++ ] = V_153 ;
V_2 = F_5 ( & V_15 [ ( * V_82 ) ] ,
( V_97 - 4 ) ,
& V_16 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_178
L_14 ) ;
goto V_14;
}
( * V_82 ) += V_16 ;
V_15 [ ( * V_82 ) ++ ] = 0x03 ;
memcpy ( & V_15 [ ( * V_82 ) ] , V_52 -> V_70 , V_102 ) ;
( * V_82 ) += V_102 ;
V_15 [ ( * V_82 ) ++ ] = V_194 ;
memcpy ( & V_15 [ ( * V_82 ) ] , V_52 -> V_56 ,
V_52 -> V_55 ) ;
( * V_82 ) += V_52 -> V_55 ;
V_14:
if ( V_2 )
( * V_82 ) = 0 ;
else
( * V_81 ) -= ( * V_82 ) ;
return V_2 ;
}
static int
F_77 ( char * V_15 , T_1 * V_81 , char * V_166 ,
T_1 V_195 , T_1 * V_196 )
{
T_1 V_16 ;
T_1 V_97 ;
int V_2 = 0 ;
( * V_196 ) = 0 ;
V_97 = ( 1
+ 3
+ 1
+ 1
+ 8
+ 4
+ V_195 ) ;
if ( V_97 > ( * V_81 ) ) {
F_11 ( V_13 L_175
L_176
L_177 , V_97 , ( * V_81 ) ) ;
V_2 = - V_9 ;
goto V_14;
}
V_15 [ ( * V_196 ) ++ ] = V_169 ;
V_2 = F_5 ( & V_15 [ ( * V_196 ) ] ,
( V_97 - 4 ) ,
& V_16 ) ;
if ( V_2 ) {
F_11 ( V_13 L_179
L_180 , V_2 ) ;
goto V_14;
}
( * V_196 ) += V_16 ;
V_15 [ ( * V_196 ) ++ ] = 0x62 ;
V_15 [ ( * V_196 ) ++ ] = 8 ;
memcpy ( & V_15 [ ( * V_196 ) ] , L_181 , 8 ) ;
( * V_196 ) += 8 ;
memset ( & V_15 [ ( * V_196 ) ] , 0x00 , 4 ) ;
( * V_196 ) += 4 ;
memcpy ( & V_15 [ ( * V_196 ) ] , V_166 , V_195 ) ;
( * V_196 ) += V_195 ;
V_14:
if ( V_2 )
( * V_196 ) = 0 ;
else
( * V_81 ) -= ( * V_196 ) ;
return V_2 ;
}
static int
F_78 ( char * V_15 , T_1 * V_81 ,
struct V_63 * V_64 ,
struct V_45 * V_46 ,
struct V_51 * V_52 , T_1 * V_82 )
{
T_1 V_22 ;
T_1 V_192 = 0 ;
char V_110 [ V_42 ] ;
struct V_171 V_121 [ 2 ] ;
struct V_171 V_120 [ 2 ] ;
struct V_172 * V_91 = NULL ;
T_2 V_32 ;
T_1 V_16 ;
T_1 V_97 ;
struct V_68 * V_69 =
V_46 -> V_69 ;
struct V_173 V_87 = {
. V_90 = NULL ,
. V_74 = V_88
} ;
int V_2 = 0 ;
( * V_82 ) = 0 ;
F_31 ( V_52 -> V_70 , V_64 -> V_108 . V_109 . V_17 ,
V_102 ) ;
V_2 = F_27 ( & V_87 . V_90 , & V_91 ,
V_46 -> V_139 ) ;
if ( F_28 ( V_2 ) ) {
F_11 ( V_13 L_50
L_51 ,
V_46 -> V_139 , V_2 ) ;
goto V_14;
}
if ( V_69 -> V_197 == 0 ) {
struct V_198 * V_199 = F_79 ( V_87 . V_90 ) ;
F_11 ( V_4 L_182
L_183 , V_199 -> V_200 ) ;
V_69 -> V_197 =
V_199 -> V_200 ;
}
if ( V_46 -> V_48 == 0 )
V_46 -> V_48 =
V_69 -> V_197 ;
if ( V_64 -> V_19 . V_27 == 0 )
V_64 -> V_19 . V_27 =
V_46 -> V_48 ;
if ( V_46 -> V_48 == 24
&& strcmp ( L_184 , V_46 -> V_139 ) == 0 ) {
memset ( ( V_46 -> V_50 + 24 ) , 0 , 8 ) ;
V_64 -> V_19 . V_27 = 32 ;
} else
V_64 -> V_19 . V_27 = V_46 -> V_48 ;
V_52 -> V_55 =
V_64 -> V_19 . V_27 ;
V_192 = 0 ;
for ( V_22 = 0 ; V_22 < V_64 -> V_19 . V_27 ; V_22 ++ )
V_192 |=
V_64 -> V_19 . V_31 [ V_22 ] ;
if ( V_192 ) {
F_2 ( V_142 , L_185
L_186
L_187 ,
V_52 -> V_55 ) ;
memcpy ( V_52 -> V_56 ,
V_64 -> V_19 . V_31 ,
V_52 -> V_55 ) ;
goto V_193;
}
if ( V_64 -> V_108 . V_109 . V_74 &
V_201 ) {
F_2 ( V_142 , L_188
L_189 ,
V_64 -> V_108 . V_109 .
V_111 ) ;
memcpy ( V_110 ,
V_64 -> V_108 . V_109 . V_110 ,
V_46 -> V_48 ) ;
F_2 ( V_142 ,
L_190 ) ;
if ( V_141 > 0 )
F_54 ( V_110 , 16 ) ;
}
if ( F_28 ( V_141 > 0 ) ) {
F_2 ( V_142 , L_191 ) ;
F_54 ( V_110 , 16 ) ;
}
V_2 = F_40 ( V_46 -> V_50 , V_52 -> V_55 ,
V_120 , 2 ) ;
if ( V_2 < 1 || V_2 > 2 ) {
F_2 ( V_13 , L_192
L_193
L_194 ,
V_2 , V_52 -> V_55 ) ;
V_2 = - V_29 ;
goto V_14;
}
V_2 = F_40 ( V_52 -> V_56 , V_52 -> V_55 ,
V_121 , 2 ) ;
if ( V_2 < 1 || V_2 > 2 ) {
F_2 ( V_13 , L_192
L_195
L_130
L_196 , V_2 ,
V_52 -> V_55 ) ;
V_2 = - V_29 ;
goto V_14;
}
F_16 ( V_91 ) ;
V_2 = F_41 ( V_87 . V_90 , V_110 ,
V_46 -> V_48 ) ;
if ( V_2 < 0 ) {
F_23 ( V_91 ) ;
F_2 ( V_13 , L_197
L_198 , V_2 ) ;
goto V_14;
}
V_2 = 0 ;
F_2 ( V_142 , L_199 ,
V_46 -> V_48 ) ;
V_2 = F_80 ( & V_87 , V_121 , V_120 ,
( * V_52 ) . V_55 ) ;
F_23 ( V_91 ) ;
if ( V_2 ) {
F_11 ( V_13 L_200 , V_2 ) ;
goto V_14;
}
F_2 ( V_142 , L_201 ) ;
if ( V_141 > 0 ) {
F_2 ( V_142 , L_202 ,
V_52 -> V_55 ) ;
F_54 ( V_52 -> V_56 ,
V_52 -> V_55 ) ;
}
V_193:
V_97 = ( 1
+ 3
+ 1
+ 1
+ 1
+ 1
+ V_158
+ 1
+ V_52 -> V_55 ) ;
if ( V_97 > ( * V_81 ) ) {
F_11 ( V_13 L_203
L_204 , V_97 ,
( * V_81 ) ) ;
V_2 = - V_9 ;
goto V_14;
}
V_15 [ ( * V_82 ) ++ ] = V_159 ;
V_2 = F_5 ( & V_15 [ ( * V_82 ) ] ,
( V_97 - 4 ) ,
& V_16 ) ;
if ( V_2 ) {
F_11 ( V_13 L_205
L_180 , V_2 ) ;
goto V_14;
}
( * V_82 ) += V_16 ;
V_15 [ ( * V_82 ) ++ ] = 0x04 ;
V_32 = F_32 ( V_46 -> V_139 ,
V_46 -> V_48 ) ;
if ( V_32 == 0 ) {
F_2 ( V_4 , L_206
L_207 , V_46 -> V_139 ) ;
V_2 = - V_9 ;
goto V_14;
}
V_15 [ ( * V_82 ) ++ ] = V_32 ;
V_15 [ ( * V_82 ) ++ ] = 0x03 ;
V_15 [ ( * V_82 ) ++ ] = 0x01 ;
memcpy ( & V_15 [ ( * V_82 ) ] , V_64 -> V_108 . V_109 . V_162 ,
V_158 ) ;
( * V_82 ) += V_158 ;
V_15 [ ( * V_82 ) ++ ] = 0x60 ;
memcpy ( & V_15 [ ( * V_82 ) ] , V_52 -> V_56 ,
V_52 -> V_55 ) ;
( * V_82 ) += V_52 -> V_55 ;
V_14:
if ( V_2 )
( * V_82 ) = 0 ;
else
( * V_81 ) -= ( * V_82 ) ;
return V_2 ;
}
int
F_81 ( char * V_202 ,
struct V_45 * V_46 ,
struct V_175 * V_176 , T_1 * V_203 ,
T_1 V_204 )
{
struct V_63 * V_64 ;
struct V_50 * V_62 = NULL ;
struct V_68 * V_69 =
& F_82 (
V_176 -> V_205 ) -> V_69 ;
T_1 V_206 ;
struct V_51 * V_52 ;
struct V_207 * V_208 ;
int V_2 = 0 ;
( * V_203 ) = 0 ;
F_16 ( & V_46 -> V_209 ) ;
V_52 = F_83 ( V_210 , V_28 ) ;
if ( ! V_52 ) {
V_2 = - V_29 ;
goto V_14;
}
F_17 (key_sig, &crypt_stat->keysig_list,
crypt_stat_list) {
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_2 = F_15 ( & V_62 ,
& V_64 ,
V_69 ,
V_208 -> V_211 ) ;
if ( V_2 ) {
F_11 ( V_4 L_208
L_209 , V_208 -> V_211 ) ;
V_2 = F_3 ( V_2 ) ;
goto V_154;
}
if ( V_64 -> V_65 == V_66 ) {
V_2 = F_78 ( ( V_202 + ( * V_203 ) ) ,
& V_204 , V_64 ,
V_46 , V_52 ,
& V_206 ) ;
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
if ( V_2 ) {
F_2 ( V_4 , L_210
L_211 ) ;
goto V_154;
}
( * V_203 ) += V_206 ;
V_2 = F_77 ( ( V_202 + ( * V_203 ) ) , & V_204 ,
V_52 -> V_70 ,
V_102 , & V_206 ) ;
if ( V_2 ) {
F_2 ( V_13 , L_212
L_213 ) ;
goto V_154;
}
( * V_203 ) += V_206 ;
} else if ( V_64 -> V_65 == V_67 ) {
V_2 = F_76 ( V_202 + ( * V_203 ) , & V_204 ,
V_62 , V_64 ,
V_46 , V_52 , & V_206 ) ;
if ( V_2 ) {
F_2 ( V_4 , L_210
L_214 ) ;
goto V_154;
}
( * V_203 ) += V_206 ;
} else {
F_21 ( & ( V_62 -> V_78 ) ) ;
F_22 ( V_62 ) ;
F_2 ( V_4 , L_215
L_216 ) ;
V_2 = - V_9 ;
goto V_154;
}
}
if ( F_84 ( V_204 > 0 ) ) {
V_202 [ ( * V_203 ) ] = 0x00 ;
} else {
F_2 ( V_13 , L_217 ) ;
V_2 = - V_39 ;
}
V_154:
F_58 ( V_210 , V_52 ) ;
V_14:
if ( V_2 )
( * V_203 ) = 0 ;
F_23 ( & V_46 -> V_209 ) ;
return V_2 ;
}
int F_85 ( struct V_45 * V_46 , char * V_70 )
{
struct V_207 * V_212 ;
V_212 = F_83 ( V_213 , V_28 ) ;
if ( ! V_212 ) {
F_11 ( V_13
L_218 ) ;
return - V_29 ;
}
memcpy ( V_212 -> V_211 , V_70 , V_26 ) ;
V_212 -> V_211 [ V_26 ] = '\0' ;
F_61 ( & V_212 -> V_214 , & V_46 -> V_215 ) ;
return 0 ;
}
int
F_86 ( struct V_68 * V_69 ,
char * V_70 , V_164 V_216 )
{
struct V_71 * V_151 ;
int V_2 = 0 ;
V_151 = F_60 ( V_217 ,
V_28 ) ;
if ( ! V_151 ) {
V_2 = - V_29 ;
F_11 ( V_13 L_219
L_220 ) ;
goto V_14;
}
memcpy ( V_151 -> V_70 , V_70 , V_26 ) ;
V_151 -> V_74 = V_216 ;
V_151 -> V_70 [ V_26 ] = '\0' ;
F_16 ( & V_69 -> V_73 ) ;
F_61 ( & V_151 -> V_218 ,
& V_69 -> V_219 ) ;
F_23 ( & V_69 -> V_73 ) ;
V_14:
return V_2 ;
}
