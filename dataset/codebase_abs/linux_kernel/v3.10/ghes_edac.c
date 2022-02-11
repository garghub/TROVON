static void F_1 ( const struct V_1 * V_2 , void * V_3 )
{
int * V_4 = V_3 ;
if ( V_2 -> type == V_5 )
( * V_4 ) ++ ;
}
static void F_2 ( const struct V_1 * V_2 , void * V_3 )
{
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_2 -> type == V_5 ) {
struct V_10 * V_11 = (struct V_10 * ) V_2 ;
struct V_12 * V_13 = F_3 ( V_9 -> V_14 , V_9 -> V_15 ,
V_9 -> V_16 ,
V_7 -> V_17 , 0 , 0 ) ;
if ( V_11 -> V_18 == 0xffff ) {
F_4 ( L_1 ,
V_7 -> V_17 ) ;
V_13 -> V_19 = F_5 ( 32 ) ;
} else if ( V_11 -> V_18 == 0x7fff ) {
V_13 -> V_19 = F_5 ( V_11 -> V_20 ) ;
} else {
if ( V_11 -> V_18 & 1 << 15 )
V_13 -> V_19 = F_5 ( ( V_11 -> V_18 &
0x7fff ) << 10 ) ;
else
V_13 -> V_19 = F_5 ( V_11 -> V_18 ) ;
}
switch ( V_11 -> V_21 ) {
case 0x12 :
if ( V_11 -> V_22 & 1 << 13 )
V_13 -> V_23 = V_24 ;
else
V_13 -> V_23 = V_25 ;
break;
case 0x13 :
if ( V_11 -> V_22 & 1 << 13 )
V_13 -> V_23 = V_26 ;
else
V_13 -> V_23 = V_27 ;
break;
case 0x14 :
V_13 -> V_23 = V_28 ;
break;
case 0x18 :
if ( V_11 -> V_22 & 1 << 13 )
V_13 -> V_23 = V_29 ;
else
V_13 -> V_23 = V_30 ;
break;
default:
if ( V_11 -> V_22 & 1 << 6 )
V_13 -> V_23 = V_31 ;
else if ( ( V_11 -> V_22 & ( ( 1 << 7 ) | ( 1 << 13 ) ) )
== ( ( 1 << 7 ) | ( 1 << 13 ) ) )
V_13 -> V_23 = V_32 ;
else if ( V_11 -> V_22 & 1 << 7 )
V_13 -> V_23 = V_33 ;
else if ( V_11 -> V_22 & 1 << 9 )
V_13 -> V_23 = V_34 ;
else
V_13 -> V_23 = V_35 ;
}
if ( V_11 -> V_36 == V_11 -> V_37 )
V_13 -> V_38 = V_39 ;
else
V_13 -> V_38 = V_40 ;
V_13 -> V_41 = V_42 ;
V_13 -> V_43 = 128 ;
if ( V_13 -> V_19 ) {
F_6 ( 1 , L_2 ,
V_7 -> V_17 , V_21 [ V_13 -> V_23 ] ,
F_7 ( V_13 -> V_19 ) ,
( V_13 -> V_38 != V_39 ) ? L_3 : L_4 ) ;
F_6 ( 2 , L_5 ,
V_11 -> V_21 , V_11 -> V_22 ,
V_11 -> V_36 , V_11 -> V_37 ) ;
}
V_7 -> V_17 ++ ;
}
}
void F_8 ( struct V_44 * V_44 , int V_45 ,
struct V_46 * V_47 )
{
enum V_48 type ;
struct V_49 * V_50 ;
struct V_8 * V_9 ;
struct V_51 * V_52 = NULL ;
char * V_53 ;
T_1 V_54 ;
F_9 (pvt, &ghes_reglist, list) {
if ( V_44 == V_52 -> V_44 )
break;
}
if ( ! V_52 ) {
F_10 ( L_6 ) ;
return;
}
V_9 = V_52 -> V_9 ;
V_50 = & V_9 -> V_55 ;
memset ( V_50 , 0 , sizeof ( * V_50 ) ) ;
V_50 -> V_56 = 1 ;
strcpy ( V_50 -> V_57 , L_7 ) ;
V_50 -> V_58 = V_52 -> V_58 ;
V_50 -> V_59 = V_52 -> V_59 ;
V_50 -> V_60 = - 1 ;
V_50 -> V_61 = - 1 ;
V_50 -> V_62 = - 1 ;
* V_52 -> V_59 = '\0' ;
* V_52 -> V_58 = '\0' ;
switch ( V_45 ) {
case V_63 :
type = V_64 ;
break;
case V_65 :
type = V_66 ;
break;
case V_67 :
type = V_68 ;
break;
default:
case V_69 :
type = V_70 ;
}
F_6 ( 1 , L_8 ,
( long long ) V_47 -> V_71 ) ;
if ( V_47 -> V_71 & V_72 ) {
V_53 = V_52 -> V_58 ;
switch ( V_47 -> V_73 ) {
case 0 :
V_53 += sprintf ( V_53 , L_9 ) ;
break;
case 1 :
V_53 += sprintf ( V_53 , L_10 ) ;
break;
case 2 :
V_53 += sprintf ( V_53 , L_11 ) ;
break;
case 3 :
V_53 += sprintf ( V_53 , L_12 ) ;
break;
case 4 :
V_53 += sprintf ( V_53 , L_13 ) ;
break;
case 5 :
V_53 += sprintf ( V_53 , L_14 ) ;
break;
case 6 :
V_53 += sprintf ( V_53 , L_15 ) ;
break;
case 7 :
V_53 += sprintf ( V_53 , L_16 ) ;
break;
case 8 :
V_53 += sprintf ( V_53 , L_17 ) ;
break;
case 9 :
V_53 += sprintf ( V_53 , L_18 ) ;
break;
case 10 :
V_53 += sprintf ( V_53 , L_19 ) ;
break;
case 11 :
V_53 += sprintf ( V_53 , L_20 ) ;
break;
case 12 :
V_53 += sprintf ( V_53 , L_21 ) ;
break;
case 13 :
V_53 += sprintf ( V_53 , L_22 ) ;
break;
case 14 :
V_53 += sprintf ( V_53 , L_23 ) ;
break;
case 15 :
V_53 += sprintf ( V_53 , L_24 ) ;
break;
default:
V_53 += sprintf ( V_53 , L_25 ,
V_47 -> V_73 ) ;
}
} else {
strcpy ( V_52 -> V_58 , L_26 ) ;
}
if ( V_47 -> V_71 & V_74 ) {
V_50 -> V_75 = V_47 -> V_76 >> V_77 ;
V_50 -> V_78 = V_47 -> V_76 & ~ V_79 ;
}
if ( V_47 -> V_71 & V_80 ) {
V_50 -> V_43 = ~ ( V_47 -> V_81 & ~ V_79 ) ;
}
V_53 = V_50 -> V_82 ;
if ( V_47 -> V_71 & V_83 )
V_53 += sprintf ( V_53 , L_27 , V_47 -> V_84 ) ;
if ( V_47 -> V_71 & V_85 )
V_53 += sprintf ( V_53 , L_28 , V_47 -> V_86 ) ;
if ( V_47 -> V_71 & V_87 )
V_53 += sprintf ( V_53 , L_29 , V_47 -> V_88 ) ;
if ( V_47 -> V_71 & V_89 )
V_53 += sprintf ( V_53 , L_30 , V_47 -> V_90 ) ;
if ( V_47 -> V_71 & V_91 )
V_53 += sprintf ( V_53 , L_31 , V_47 -> V_92 ) ;
if ( V_47 -> V_71 & V_93 )
V_53 += sprintf ( V_53 , L_32 , V_47 -> V_94 ) ;
if ( V_47 -> V_71 & V_95 )
V_53 += sprintf ( V_53 , L_33 , V_47 -> V_96 ) ;
if ( V_53 > V_50 -> V_82 )
* ( V_53 - 1 ) = '\0' ;
V_53 = V_52 -> V_59 ;
if ( V_47 -> V_71 & V_97 ) {
T_2 V_98 = V_47 -> V_99 ;
V_53 += sprintf ( V_53 , L_34 , ( long long ) V_98 ) ;
switch ( ( V_98 >> 8 ) & 0xff ) {
case 1 :
V_53 += sprintf ( V_53 , L_35 ) ;
break;
case 16 :
V_53 += sprintf ( V_53 , L_36 ) ;
break;
case 4 :
V_53 += sprintf ( V_53 , L_37 ) ;
break;
case 5 :
V_53 += sprintf ( V_53 , L_38 ) ;
break;
case 6 :
V_53 += sprintf ( V_53 , L_39 ) ;
break;
case 7 :
V_53 += sprintf ( V_53 , L_40 ) ;
break;
case 8 :
V_53 += sprintf ( V_53 , L_41 ) ;
break;
case 9 :
V_53 += sprintf ( V_53 , L_42 ) ;
break;
case 17 :
V_53 += sprintf ( V_53 , L_43 ) ;
break;
case 18 :
V_53 += sprintf ( V_53 , L_44 ) ;
break;
case 19 :
V_53 += sprintf ( V_53 , L_45 ) ;
break;
case 20 :
V_53 += sprintf ( V_53 , L_46 ) ;
break;
case 21 :
V_53 += sprintf ( V_53 , L_47 ) ;
break;
case 22 :
V_53 += sprintf ( V_53 , L_48 ) ;
break;
case 23 :
V_53 += sprintf ( V_53 , L_49 ) ;
break;
case 25 :
V_53 += sprintf ( V_53 , L_50 ) ;
break;
case 26 :
V_53 += sprintf ( V_53 , L_51 ) ;
break;
default:
V_53 += sprintf ( V_53 , L_52 ) ;
break;
}
}
if ( V_47 -> V_71 & V_100 )
V_53 += sprintf ( V_53 , L_53 ,
( long long ) V_47 -> V_101 ) ;
if ( V_47 -> V_71 & V_102 )
V_53 += sprintf ( V_53 , L_54 ,
( long long ) V_47 -> V_103 ) ;
if ( V_47 -> V_71 & V_104 )
V_53 += sprintf ( V_53 , L_55 ,
( long long ) V_47 -> V_103 ) ;
if ( V_53 > V_52 -> V_59 )
* ( V_53 - 1 ) = '\0' ;
V_54 = F_11 ( V_50 -> V_43 ) ;
sprintf ( V_52 -> V_105 , L_56 ,
V_50 -> V_82 , V_50 -> V_59 ) ;
F_12 ( type , V_50 -> V_58 , V_50 -> V_57 , V_50 -> V_56 ,
V_9 -> V_106 , V_50 -> V_60 , V_50 -> V_61 , V_50 -> V_62 ,
F_7 ( V_50 -> V_75 ) | V_50 -> V_78 ,
V_54 , V_50 -> V_107 , V_52 -> V_105 ) ;
F_13 ( type , V_9 , V_50 ) ;
}
int F_14 ( struct V_44 * V_44 , struct V_108 * V_109 )
{
bool V_110 = false ;
int V_111 , V_4 = 0 ;
struct V_8 * V_9 ;
struct V_112 V_14 [ 1 ] ;
struct V_51 * V_52 ;
struct V_6 V_7 ;
F_15 ( F_1 , & V_4 ) ;
if ( V_4 == 0 ) {
V_110 = true ;
V_4 = 1 ;
}
V_14 [ 0 ] . type = V_113 ;
V_14 [ 0 ] . V_18 = V_4 ;
V_14 [ 0 ] . V_114 = true ;
F_16 ( & V_115 ) ;
V_9 = F_17 ( V_116 , F_18 ( V_14 ) , V_14 ,
sizeof( * V_52 ) ) ;
if ( ! V_9 ) {
F_4 ( L_57 ) ;
F_19 ( & V_115 ) ;
return - V_117 ;
}
V_52 = V_9 -> V_118 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
F_20 ( & V_52 -> V_119 , & V_120 ) ;
V_52 -> V_44 = V_44 ;
V_52 -> V_9 = V_9 ;
V_9 -> V_121 = V_109 ;
V_9 -> V_122 = V_123 ;
V_9 -> V_124 = V_125 ;
V_9 -> V_126 = V_125 ;
V_9 -> V_127 = L_58 ;
V_9 -> V_128 = V_129 ;
V_9 -> V_130 = L_59 ;
V_9 -> V_131 = L_60 ;
if ( ! V_116 ) {
if ( ! V_110 ) {
F_4 ( L_61 ) ;
F_4 ( L_62 ) ;
F_4 ( L_63 ) ;
F_4 ( L_64 ) ;
F_4 ( L_65 ) ;
F_4 ( L_66 ,
V_4 ) ;
} else {
F_4 ( L_67 ) ;
F_4 ( L_68 ) ;
F_4 ( L_69 ) ;
}
}
if ( ! V_110 ) {
if ( ! V_116 ) {
V_7 . V_17 = 0 ;
V_7 . V_9 = V_9 ;
F_15 ( F_2 , & V_7 ) ;
}
} else {
struct V_12 * V_13 = F_3 ( V_9 -> V_14 , V_9 -> V_15 ,
V_9 -> V_16 , 0 , 0 , 0 ) ;
V_13 -> V_19 = 1 ;
V_13 -> V_43 = 128 ;
V_13 -> V_23 = V_35 ;
V_13 -> V_41 = V_42 ;
V_13 -> V_38 = V_40 ;
}
V_111 = F_21 ( V_9 ) ;
if ( V_111 < 0 ) {
F_4 ( L_70 ) ;
F_22 ( V_9 ) ;
F_19 ( & V_115 ) ;
return - V_132 ;
}
V_116 ++ ;
F_19 ( & V_115 ) ;
return 0 ;
}
void F_23 ( struct V_44 * V_44 )
{
struct V_8 * V_9 ;
struct V_51 * V_52 , * V_133 ;
F_24 (pvt, tmp, &ghes_reglist, list) {
if ( V_44 == V_52 -> V_44 ) {
V_9 = V_52 -> V_9 ;
F_25 ( V_9 -> V_121 ) ;
F_22 ( V_9 ) ;
F_26 ( & V_52 -> V_119 ) ;
}
}
}
