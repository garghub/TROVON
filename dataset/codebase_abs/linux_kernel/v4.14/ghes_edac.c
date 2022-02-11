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
V_7 -> V_17 , V_44 [ V_13 -> V_23 ] ,
F_7 ( V_13 -> V_19 ) ,
( V_13 -> V_38 != V_39 ) ? L_3 : L_4 ) ;
F_6 ( 2 , L_5 ,
V_11 -> V_21 , V_11 -> V_22 ,
V_11 -> V_36 , V_11 -> V_37 ) ;
}
V_7 -> V_17 ++ ;
}
}
void F_8 ( struct V_45 * V_45 , int V_46 ,
struct V_47 * V_48 )
{
enum V_49 type ;
struct V_50 * V_51 ;
struct V_8 * V_9 ;
struct V_52 * V_53 = NULL ;
char * V_54 ;
T_1 V_55 ;
F_9 (pvt, &ghes_reglist, list) {
if ( V_45 == V_53 -> V_45 )
break;
}
if ( ! V_53 ) {
F_10 ( L_6 ) ;
return;
}
V_9 = V_53 -> V_9 ;
V_51 = & V_9 -> V_56 ;
memset ( V_51 , 0 , sizeof ( * V_51 ) ) ;
V_51 -> V_57 = 1 ;
strcpy ( V_51 -> V_58 , L_7 ) ;
V_51 -> V_59 = V_53 -> V_59 ;
V_51 -> V_60 = V_53 -> V_60 ;
V_51 -> V_61 = - 1 ;
V_51 -> V_62 = - 1 ;
V_51 -> V_63 = - 1 ;
* V_53 -> V_60 = '\0' ;
* V_53 -> V_59 = '\0' ;
switch ( V_46 ) {
case V_64 :
type = V_65 ;
break;
case V_66 :
type = V_67 ;
break;
case V_68 :
type = V_69 ;
break;
default:
case V_70 :
type = V_71 ;
}
F_6 ( 1 , L_8 ,
( long long ) V_48 -> V_72 ) ;
if ( V_48 -> V_72 & V_73 ) {
V_54 = V_53 -> V_59 ;
switch ( V_48 -> V_74 ) {
case 0 :
V_54 += sprintf ( V_54 , L_9 ) ;
break;
case 1 :
V_54 += sprintf ( V_54 , L_10 ) ;
break;
case 2 :
V_54 += sprintf ( V_54 , L_11 ) ;
break;
case 3 :
V_54 += sprintf ( V_54 , L_12 ) ;
break;
case 4 :
V_54 += sprintf ( V_54 , L_13 ) ;
break;
case 5 :
V_54 += sprintf ( V_54 , L_14 ) ;
break;
case 6 :
V_54 += sprintf ( V_54 , L_15 ) ;
break;
case 7 :
V_54 += sprintf ( V_54 , L_16 ) ;
break;
case 8 :
V_54 += sprintf ( V_54 , L_17 ) ;
break;
case 9 :
V_54 += sprintf ( V_54 , L_18 ) ;
break;
case 10 :
V_54 += sprintf ( V_54 , L_19 ) ;
break;
case 11 :
V_54 += sprintf ( V_54 , L_20 ) ;
break;
case 12 :
V_54 += sprintf ( V_54 , L_21 ) ;
break;
case 13 :
V_54 += sprintf ( V_54 , L_22 ) ;
break;
case 14 :
V_54 += sprintf ( V_54 , L_23 ) ;
break;
case 15 :
V_54 += sprintf ( V_54 , L_24 ) ;
break;
default:
V_54 += sprintf ( V_54 , L_25 ,
V_48 -> V_74 ) ;
}
} else {
strcpy ( V_53 -> V_59 , L_26 ) ;
}
if ( V_48 -> V_72 & V_75 ) {
V_51 -> V_76 = V_48 -> V_77 >> V_78 ;
V_51 -> V_79 = V_48 -> V_77 & ~ V_80 ;
}
if ( V_48 -> V_72 & V_81 )
V_51 -> V_43 = ~ ( V_48 -> V_82 & ~ V_80 ) ;
V_54 = V_51 -> V_83 ;
if ( V_48 -> V_72 & V_84 )
V_54 += sprintf ( V_54 , L_27 , V_48 -> V_85 ) ;
if ( V_48 -> V_72 & V_86 )
V_54 += sprintf ( V_54 , L_28 , V_48 -> V_87 ) ;
if ( V_48 -> V_72 & V_88 )
V_54 += sprintf ( V_54 , L_29 , V_48 -> V_89 ) ;
if ( V_48 -> V_72 & V_90 )
V_54 += sprintf ( V_54 , L_30 , V_48 -> V_91 ) ;
if ( V_48 -> V_72 & V_92 )
V_54 += sprintf ( V_54 , L_31 , V_48 -> V_93 ) ;
if ( V_48 -> V_72 & V_94 )
V_54 += sprintf ( V_54 , L_32 , V_48 -> V_95 ) ;
if ( V_48 -> V_72 & V_96 )
V_54 += sprintf ( V_54 , L_33 , V_48 -> V_97 ) ;
if ( V_48 -> V_72 & V_98 )
V_54 += sprintf ( V_54 , L_34 , V_48 -> V_99 ) ;
if ( V_48 -> V_72 & V_100 ) {
const char * V_93 = NULL , * V_101 = NULL ;
F_11 ( V_48 -> V_102 , & V_93 , & V_101 ) ;
if ( V_93 != NULL && V_101 != NULL )
V_54 += sprintf ( V_54 , L_35 , V_93 , V_101 ) ;
else
V_54 += sprintf ( V_54 , L_36 ,
V_48 -> V_102 ) ;
}
if ( V_54 > V_51 -> V_83 )
* ( V_54 - 1 ) = '\0' ;
V_54 = V_53 -> V_60 ;
if ( V_48 -> V_72 & V_103 ) {
T_2 V_104 = V_48 -> V_105 ;
V_54 += sprintf ( V_54 , L_37 , ( long long ) V_104 ) ;
switch ( ( V_104 >> 8 ) & 0xff ) {
case 1 :
V_54 += sprintf ( V_54 , L_38 ) ;
break;
case 16 :
V_54 += sprintf ( V_54 , L_39 ) ;
break;
case 4 :
V_54 += sprintf ( V_54 , L_40 ) ;
break;
case 5 :
V_54 += sprintf ( V_54 , L_41 ) ;
break;
case 6 :
V_54 += sprintf ( V_54 , L_42 ) ;
break;
case 7 :
V_54 += sprintf ( V_54 , L_43 ) ;
break;
case 8 :
V_54 += sprintf ( V_54 , L_44 ) ;
break;
case 9 :
V_54 += sprintf ( V_54 , L_45 ) ;
break;
case 17 :
V_54 += sprintf ( V_54 , L_46 ) ;
break;
case 18 :
V_54 += sprintf ( V_54 , L_47 ) ;
break;
case 19 :
V_54 += sprintf ( V_54 , L_48 ) ;
break;
case 20 :
V_54 += sprintf ( V_54 , L_49 ) ;
break;
case 21 :
V_54 += sprintf ( V_54 , L_50 ) ;
break;
case 22 :
V_54 += sprintf ( V_54 , L_51 ) ;
break;
case 23 :
V_54 += sprintf ( V_54 , L_52 ) ;
break;
case 25 :
V_54 += sprintf ( V_54 , L_53 ) ;
break;
case 26 :
V_54 += sprintf ( V_54 , L_54 ) ;
break;
default:
V_54 += sprintf ( V_54 , L_55 ) ;
break;
}
}
if ( V_48 -> V_72 & V_106 )
V_54 += sprintf ( V_54 , L_56 ,
( long long ) V_48 -> V_107 ) ;
if ( V_48 -> V_72 & V_108 )
V_54 += sprintf ( V_54 , L_57 ,
( long long ) V_48 -> V_109 ) ;
if ( V_48 -> V_72 & V_110 )
V_54 += sprintf ( V_54 , L_58 ,
( long long ) V_48 -> V_109 ) ;
if ( V_54 > V_53 -> V_60 )
* ( V_54 - 1 ) = '\0' ;
V_55 = F_12 ( V_51 -> V_43 ) ;
snprintf ( V_53 -> V_111 , sizeof( V_53 -> V_111 ) ,
L_59 , V_51 -> V_83 , V_51 -> V_60 ) ;
F_13 ( type , V_51 -> V_59 , V_51 -> V_58 , V_51 -> V_57 ,
V_9 -> V_112 , V_51 -> V_61 , V_51 -> V_62 , V_51 -> V_63 ,
( V_51 -> V_76 << V_78 ) | V_51 -> V_79 ,
V_55 , V_51 -> V_113 , V_53 -> V_111 ) ;
F_14 ( type , V_9 , V_51 ) ;
}
int F_15 ( struct V_45 * V_45 , struct V_101 * V_114 )
{
bool V_115 = false ;
int V_116 , V_4 = 0 ;
struct V_8 * V_9 ;
struct V_117 V_14 [ 1 ] ;
struct V_52 * V_53 ;
struct V_6 V_7 ;
F_16 ( F_1 , & V_4 ) ;
if ( V_4 == 0 ) {
V_115 = true ;
V_4 = 1 ;
}
V_14 [ 0 ] . type = V_118 ;
V_14 [ 0 ] . V_18 = V_4 ;
V_14 [ 0 ] . V_119 = true ;
F_17 ( & V_120 ) ;
V_9 = F_18 ( V_121 , F_19 ( V_14 ) , V_14 ,
sizeof( * V_53 ) ) ;
if ( ! V_9 ) {
F_4 ( L_60 ) ;
F_20 ( & V_120 ) ;
return - V_122 ;
}
V_53 = V_9 -> V_123 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
F_21 ( & V_53 -> V_124 , & V_125 ) ;
V_53 -> V_45 = V_45 ;
V_53 -> V_9 = V_9 ;
V_9 -> V_126 = V_114 ;
V_9 -> V_127 = V_128 ;
V_9 -> V_129 = V_130 ;
V_9 -> V_131 = V_130 ;
V_9 -> V_132 = L_61 ;
V_9 -> V_133 = L_62 ;
V_9 -> V_134 = L_63 ;
if ( ! V_121 ) {
if ( ! V_115 ) {
F_4 ( L_64 ) ;
F_4 ( L_65 ) ;
F_4 ( L_66 ) ;
F_4 ( L_67 ) ;
F_4 ( L_68 ) ;
F_4 ( L_69 ,
V_4 ) ;
} else {
F_4 ( L_70 ) ;
F_4 ( L_71 ) ;
F_4 ( L_72 ) ;
}
}
if ( ! V_115 ) {
if ( ! V_121 ) {
V_7 . V_17 = 0 ;
V_7 . V_9 = V_9 ;
F_16 ( F_2 , & V_7 ) ;
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
V_116 = F_22 ( V_9 ) ;
if ( V_116 < 0 ) {
F_4 ( L_73 ) ;
F_23 ( V_9 ) ;
F_20 ( & V_120 ) ;
return - V_135 ;
}
V_121 ++ ;
F_20 ( & V_120 ) ;
return 0 ;
}
void F_24 ( struct V_45 * V_45 )
{
struct V_8 * V_9 ;
struct V_52 * V_53 , * V_136 ;
F_25 (pvt, tmp, &ghes_reglist, list) {
if ( V_45 == V_53 -> V_45 ) {
V_9 = V_53 -> V_9 ;
F_26 ( V_9 -> V_126 ) ;
F_23 ( V_9 ) ;
F_27 ( & V_53 -> V_124 ) ;
}
}
}
