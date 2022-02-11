static void F_1 ( struct V_1 * V_2 , int V_3 )
{
union V_4 V_5 ;
V_5 . V_3 = V_3 ;
F_2 ( V_2 -> V_6 , V_7 , & V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_9 ,
T_1 V_10 , int V_11 )
{
union V_4 V_12 ;
union V_4 V_5 ;
int V_13 ;
V_12 . V_12 . V_8 = V_8 ;
V_12 . V_12 . V_14 = V_9 ;
F_4 ( V_15 , V_16 , 1 , L_1 , V_8 , V_9 , V_10 ) ;
if ( ( V_13 = F_2 ( V_2 -> V_6 , V_17 , & V_12 ) ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_2 , V_13 , V_8 , V_9 ) ;
return - V_18 ;
}
F_5 ( 1000 ) ;
if ( V_9 == 0 )
return 0 ;
if ( V_11 )
F_6 ( 10 ) ;
V_5 . V_19 . V_8 = V_9 ;
V_5 . V_19 . V_20 = V_10 ;
if ( ( V_13 = F_2 ( V_2 -> V_6 , V_21 , & V_5 ) ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_3 , V_13 , V_9 , V_10 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 * V_22 )
{
union V_4 V_23 ;
int V_13 ;
* V_22 = 0 ;
if ( ( V_13 = F_2 ( V_2 -> V_6 , V_24 , & V_23 ) ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_4 , V_13 ) ;
return - V_18 ;
}
* V_22 = ( T_2 ) V_23 . V_26 . V_27 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
F_4 ( V_15 , V_16 , 1 , L_5 ) ;
if ( F_3 ( V_2 , V_28 , V_28 , 0 , V_29 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_6 ) ;
return - 1 ;
}
F_6 ( 10 ) ;
if ( F_3 ( V_2 , V_28 , V_28 , V_28 , V_29 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_6 ) ;
F_6 ( 10 ) ;
return - 1 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_4 ( V_15 , V_30 , 1 , L_7 ) ;
if ( F_3 ( V_2 , V_31 , V_31 , 0 , V_29 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_6 ) ;
return - 1 ;
}
F_5 ( 1000 ) ;
if ( F_3 ( V_2 , V_31 , V_31 , V_31 , V_32 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_6 ) ;
return - 1 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , ~ 0 , V_33 , 0 , V_29 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_6 ) ;
return - 1 ;
}
F_5 ( 1000 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , ~ 0 , V_34 , V_34 , V_29 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_6 ) ;
return - 1 ;
}
if ( V_2 -> V_35 & V_36 )
F_5 ( 1000 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_2 V_37 )
{
T_2 V_38 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 200 ; V_39 ++ ) {
if ( F_7 ( V_2 , & V_38 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_8 ) ;
return - 1 ;
}
if ( ( V_38 & V_33 ) == 0 ) {
F_4 ( V_15 , V_16 , 1 , L_9 , V_39 ) ;
return 1 ;
}
F_6 ( 10 ) ;
}
F_4 ( V_15 , V_40 , 1 , L_10 , V_39 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
F_4 ( V_15 , V_40 , 1 , L_11 ) ;
F_11 ( V_2 ) ;
F_6 ( 10 ) ;
F_10 ( V_2 ) ;
F_6 ( 10 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
F_4 ( V_15 , V_16 , 1 , L_12 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
F_6 ( 10 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
F_4 ( V_15 , V_16 , 1 , L_13 ) ;
if ( ( F_10 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_14 ) ;
return - 1 ;
}
if ( ( F_8 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_15 ) ;
return - 1 ;
}
if ( V_2 -> V_35 & V_36 )
F_6 ( 100 ) ;
else
F_6 ( 5 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_2 * V_41 , T_2 V_42 )
{
struct V_43 V_44 = {
. V_45 = V_2 -> V_46 -> V_47 ,
. V_48 = 0 ,
. V_49 = V_41 ,
. V_42 = V_42
} ;
int V_13 ;
T_2 V_50 , V_39 ;
F_4 ( V_15 , V_40 , 0 , L_16 ) ;
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ )
F_4 ( V_15 , V_40 , 0 , L_17 , V_41 [ V_39 ] ) ;
F_4 ( V_15 , V_40 , 0 , L_18 ) ;
for ( V_50 = 0 ; V_50 < 2 ; V_50 ++ ) {
if ( ( V_13 = F_17 ( V_2 -> V_51 , & V_44 , 1 ) ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_19 , V_13 , V_42 , V_41 [ 0 ] ) ;
F_13 ( V_2 ) ;
continue;
} else
break;
}
if ( V_50 >= 2 ) {
F_4 ( V_15 , V_16 , 1 , L_20 ) ;
F_14 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_2 * V_52 , T_2 V_42 )
{
struct V_43 V_44 = {
. V_45 = V_2 -> V_46 -> V_47 ,
. V_48 = V_53 ,
. V_49 = V_52 ,
. V_42 = V_42
} ;
int V_13 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < 2 ; V_50 ++ ) {
if ( ( V_13 = F_17 ( V_2 -> V_51 , & V_44 , 1 ) ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_21 , V_13 , V_42 , V_52 [ 0 ] ) ;
F_13 ( V_2 ) ;
continue;
} else
break;
}
if ( V_50 >= 2 ) {
F_4 ( V_15 , V_16 , 1 , L_20 ) ;
F_14 ( V_2 ) ;
return - 1 ;
}
F_4 ( V_15 , V_30 , 1 , L_22 , V_52 [ 0 ] ) ;
for ( V_13 = 1 ; V_13 < V_42 ; V_13 ++ )
F_4 ( V_15 , V_30 , 0 , L_23 , V_52 [ V_13 ] ) ;
if ( V_13 > 1 )
F_4 ( V_15 , V_30 , 0 , L_24 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_54 ) {
case V_55 :
F_4 ( V_15 , V_16 , 1 , L_25 ) ;
V_2 -> V_56 [ 8 ] &= ~ 0x40 ;
break;
case V_57 :
F_4 ( V_15 , V_16 , 1 , L_26 ) ;
V_2 -> V_56 [ 8 ] |= 0x40 ;
break;
case V_58 :
break;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_59 )
{
V_2 -> V_60 = V_59 ;
F_4 ( V_15 , V_16 , 1 , L_27 , V_59 ) ;
if ( V_2 -> V_61 == V_62 ) {
V_59 = V_59 / 1000 ;
if ( V_59 < 950 || V_59 > 2150 )
return - V_63 ;
V_2 -> V_56 [ 2 ] = ( V_59 >> 8 ) ;
V_2 -> V_56 [ 3 ] = ( T_2 ) V_59 ;
V_2 -> V_56 [ 4 ] = 0x01 ;
V_2 -> V_56 [ 8 ] &= ~ 0x04 ;
if ( V_2 -> V_35 & V_64 ) {
if ( V_59 < 1531 )
V_2 -> V_56 [ 8 ] |= 0x04 ;
}
} else if ( V_2 -> V_61 == V_65 ) {
V_59 = V_59 / 1000 ;
if ( V_59 < 137000 || V_59 > 858000 )
return - V_63 ;
V_2 -> V_56 [ 2 ] = ( V_59 >> 16 ) & 0xff ;
V_2 -> V_56 [ 3 ] = ( V_59 >> 8 ) & 0xff ;
V_2 -> V_56 [ 4 ] = ( T_2 ) V_59 ;
} else if ( V_2 -> V_61 == V_66 ) {
V_59 = V_59 / 1000 ;
V_2 -> V_56 [ 2 ] = ( V_59 >> 16 ) & 0xff ;
V_2 -> V_56 [ 3 ] = ( V_59 >> 8 ) & 0xff ;
V_2 -> V_56 [ 4 ] = ( T_2 ) V_59 ;
} else if ( V_2 -> V_61 == V_67 ) {
V_59 = V_59 / 1000 ;
if ( V_59 < 51000 || V_59 > 858000 )
return - V_63 ;
V_2 -> V_56 [ 2 ] = ( V_59 >> 16 ) & 0xff ;
V_2 -> V_56 [ 3 ] = ( V_59 >> 8 ) & 0xff ;
V_2 -> V_56 [ 4 ] = ( T_2 ) V_59 ;
V_2 -> V_56 [ 5 ] = 0x00 ;
V_2 -> V_56 [ 6 ] = 0x00 ;
if ( V_2 -> V_68 & V_69 )
V_2 -> V_56 [ 7 ] = 0x00 ;
} else
return - V_63 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_70 )
{
V_2 -> V_70 = V_70 ;
if ( V_2 -> V_61 != V_65 )
return - V_71 ;
switch ( V_70 ) {
case 6000000 :
if ( V_2 -> V_68 & V_72 )
V_2 -> V_56 [ 7 ] = 0x06 ;
else {
V_2 -> V_56 [ 6 ] = 0x06 ;
V_2 -> V_56 [ 7 ] = 0x00 ;
}
break;
case 7000000 :
if ( V_2 -> V_68 & V_72 )
V_2 -> V_56 [ 7 ] = 0x07 ;
else {
V_2 -> V_56 [ 6 ] = 0x07 ;
V_2 -> V_56 [ 7 ] = 0x00 ;
}
break;
case 8000000 :
if ( V_2 -> V_68 & V_72 )
V_2 -> V_56 [ 7 ] = 0x08 ;
else {
V_2 -> V_56 [ 6 ] = 0x08 ;
V_2 -> V_56 [ 7 ] = 0x00 ;
}
break;
default:
return - V_63 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_73 )
{
V_2 -> V_73 = V_73 ;
switch ( V_73 ) {
case V_74 :
V_2 -> V_56 [ 8 ] &= ~ 0x80 ;
break;
case V_75 :
V_2 -> V_56 [ 8 ] |= 0x80 ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_4 V_76 )
{
V_2 -> V_76 = V_76 ;
return 0 ;
}
static T_4 F_24 ( struct V_1 * V_2 )
{
return V_2 -> V_76 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_77 )
{
T_1 V_78 ;
T_5 V_79 ;
V_2 -> V_80 = V_77 ;
if ( V_2 -> V_61 == V_65 ) {
return - V_71 ;
}
F_4 ( V_15 , V_16 , 1 , L_28 , V_77 ) ;
V_77 /= 1000 ;
if ( V_2 -> V_61 == V_62 ) {
if ( V_2 -> V_35 & V_81 ) {
V_79 = V_77 ;
V_79 <<= 20 ;
F_26 ( V_79 , 88000 ) ;
V_78 = ( T_1 ) V_79 ;
F_4 ( V_15 , V_16 , 1 , L_29 , V_78 ) ;
V_2 -> V_56 [ 5 ] = ( T_2 ) ( V_78 >> 12 ) ;
V_2 -> V_56 [ 6 ] = ( T_2 ) ( V_78 >> 4 ) ;
V_2 -> V_56 [ 7 ] = ( T_2 ) ( V_78 << 4 ) ;
} else {
V_2 -> V_56 [ 5 ] = ( T_2 ) ( V_77 >> 16 ) & 0x7f ;
V_2 -> V_56 [ 6 ] = ( T_2 ) ( V_77 >> 8 ) ;
V_2 -> V_56 [ 7 ] = ( T_2 ) V_77 ;
}
V_2 -> V_56 [ 8 ] &= ~ 0x20 ;
if ( V_2 -> V_35 & V_64 ) {
if ( V_77 > 8000 )
V_2 -> V_56 [ 8 ] |= 0x20 ;
}
} else if ( V_2 -> V_61 == V_66 ) {
F_4 ( V_15 , V_30 , 1 , L_30 , V_2 -> V_82 ) ;
if ( ! strncmp ( V_2 -> V_82 , L_31 , 6 ) ) {
V_2 -> V_56 [ 5 ] = ( T_2 ) ( V_77 >> 8 ) ;
V_2 -> V_56 [ 6 ] = ( T_2 ) V_77 ;
V_2 -> V_56 [ 7 ] = 0x00 ;
} else if ( ! strncmp ( V_2 -> V_82 , L_32 , 6 ) ) {
V_2 -> V_56 [ 5 ] = 0x00 ;
V_2 -> V_56 [ 6 ] = ( T_2 ) ( V_77 >> 8 ) ;
V_2 -> V_56 [ 7 ] = ( T_2 ) V_77 ;
}
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_6 V_83 )
{
if ( V_2 -> V_61 != V_66 )
return - V_71 ;
V_2 -> V_83 = V_83 ;
switch ( V_83 ) {
case V_84 :
V_2 -> V_56 [ 8 ] = 0x10 ;
break;
case V_85 :
V_2 -> V_56 [ 8 ] = 0x20 ;
break;
case V_86 :
V_2 -> V_56 [ 8 ] = 0x40 ;
break;
case V_87 :
V_2 -> V_56 [ 8 ] = 0x80 ;
break;
case V_88 :
if ( ! strncmp ( V_2 -> V_82 , L_31 , 6 ) )
V_2 -> V_56 [ 8 ] = 0xff ;
else if ( ! strncmp ( V_2 -> V_82 , L_32 , 6 ) )
V_2 -> V_56 [ 8 ] = 0x00 ;
break;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
default:
return - V_63 ;
}
return 0 ;
}
static T_6 F_28 ( struct V_1 * V_2 )
{
return V_2 -> V_83 ;
}
T_2 F_29 ( T_2 * V_49 , T_1 V_42 )
{
T_1 V_39 ;
T_2 V_93 = 0 ;
if ( ! V_42 )
return 0 ;
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ ) {
V_93 += V_49 [ V_39 ] ;
}
return ( ( ~ V_93 ) + 1 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_35 = V_2 -> V_35 ;
F_4 ( V_15 , V_25 , 0 , L_33 ) ;
if ( V_35 & V_94 )
F_4 ( V_15 , V_25 , 0 , L_34 , V_94 ) ;
if ( V_35 & V_95 )
F_4 ( V_15 , V_25 , 0 , L_35 , V_95 ) ;
if ( V_35 & V_96 )
F_4 ( V_15 , V_25 , 0 , L_36 , V_96 ) ;
if ( V_35 & V_97 )
F_4 ( V_15 , V_25 , 0 , L_37 , V_97 ) ;
if ( V_35 & V_81 )
F_4 ( V_15 , V_25 , 0 , L_38 , V_81 ) ;
if ( V_35 & V_36 )
F_4 ( V_15 , V_25 , 0 , L_39 , V_36 ) ;
if ( V_35 & V_98 )
F_4 ( V_15 , V_25 , 0 , L_40 , V_98 ) ;
if ( V_35 & V_99 )
F_4 ( V_15 , V_25 , 0 , L_41 , V_99 ) ;
F_4 ( V_15 , V_25 , 0 , L_24 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_2 type )
{
char * V_100 ;
switch ( type ) {
case V_62 :
V_100 = L_42 ;
break;
case V_65 :
V_100 = L_43 ;
break;
case V_66 :
V_100 = L_44 ;
break;
case V_67 :
V_100 = L_45 ;
break;
default:
F_4 ( V_15 , V_16 , 1 , L_46 , type ) ;
return - V_63 ;
}
F_4 ( V_15 , V_16 , 1 , L_47 , V_100 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_2 V_101 [] = { 0x00 , 0x0a , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_101 [ 7 ] = F_29 ( V_101 , 7 ) ;
if ( F_33 ( V_2 , V_101 , 8 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_48 ) ;
return - 1 ;
}
memset ( & V_2 -> V_102 , '\0' , 8 ) ;
memcpy ( & V_2 -> V_102 , & V_2 -> V_103 , 6 ) ;
F_4 ( V_15 , V_25 , 1 , L_49 , V_2 -> V_102 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_2 V_104 [] = { 0x00 , 0x10 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_104 [ 7 ] = F_29 ( V_104 , 7 ) ;
if ( F_33 ( V_2 , V_104 , 8 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_48 ) ;
return - 1 ;
}
memcpy ( & V_2 -> V_105 , & V_2 -> V_103 , 8 ) ;
F_4 ( V_15 , V_25 , 1 , L_50 ,
V_2 -> V_105 [ 0 ] >> 4 , V_2 -> V_105 [ 0 ] & 0x0f ,
V_2 -> V_105 [ 1 ] ,
V_2 -> V_105 [ 5 ] , V_2 -> V_105 [ 6 ] ,
V_2 -> V_105 [ 4 ] , V_2 -> V_105 [ 3 ] , V_2 -> V_105 [ 2 ] ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_106 ;
struct V_107 * V_108 = NULL ;
T_2 V_109 [] = { 0x00 , 0x11 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_109 [ 7 ] = F_29 ( V_109 , 7 ) ;
if ( F_33 ( V_2 , V_109 , 8 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_48 ) ;
return - 1 ;
}
memset ( & V_2 -> V_110 , '\0' , 8 ) ;
memcpy ( & V_2 -> V_110 , & V_2 -> V_103 , 7 ) ;
F_4 ( V_15 , V_25 , 1 , L_51 , & V_2 -> V_110 [ 0 ] ) ;
for ( V_106 = 0 , V_108 = V_111 ; V_106 < F_36 ( V_111 ) ; V_106 ++ , V_108 ++ ) {
if ( ! strcmp ( & V_2 -> V_110 [ 0 ] , V_108 -> V_112 ) ) {
V_2 -> V_113 = V_108 -> V_113 ;
F_4 ( V_15 , V_25 , 1 , L_52 ,
V_108 -> V_114 , V_108 -> V_113 ) ;
}
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_2 V_115 [] = { 0x00 , 0x12 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_115 [ 7 ] = F_29 ( V_115 , 7 ) ;
if ( F_33 ( V_2 , V_115 , 8 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_48 ) ;
return - 1 ;
}
memset ( & V_2 -> V_116 , '\0' , 8 ) ;
memcpy ( & V_2 -> V_116 , & V_2 -> V_103 , 7 ) ;
F_4 ( V_15 , V_25 , 1 , L_53 , & V_2 -> V_116 [ 0 ] ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
int V_39 ;
if ( V_15 > 2 ) {
F_39 ( L_54 , V_117 ) ;
for ( V_39 = 0 ; V_39 < 8 ; V_39 ++ )
F_39 ( L_55 , V_2 -> V_103 [ V_39 ] ) ;
F_39 ( L_18 ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
T_2 V_118 [] = { 0x00 , 0x04 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_118 [ 7 ] = F_29 ( V_118 , 7 ) ;
if ( F_33 ( V_2 , V_118 , 8 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_56 ) ;
return - 1 ;
}
F_38 ( V_2 ) ;
if ( memcmp ( & V_118 , & V_2 -> V_103 , 8 ) ) {
F_4 ( V_15 , V_25 , 1 , L_57 ) ;
V_2 -> V_113 = V_119 ;
return 0 ;
}
return - 1 ;
}
static int F_41 ( struct V_1 * V_2 )
{
T_2 V_120 [] = { 0x00 , 0x10 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_120 [ 7 ] = F_29 ( V_120 , 7 ) ;
if ( F_33 ( V_2 , V_120 , 8 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_58 ) ;
return - 1 ;
}
F_38 ( V_2 ) ;
if ( memcmp ( & V_120 , & V_2 -> V_103 , 8 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_59 ) ;
V_2 -> V_113 = V_121 ;
return 0 ;
}
return - 1 ;
}
static int F_42 ( struct V_1 * V_2 )
{
T_2 V_122 [] = { 0x00 , 0x13 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
T_2 V_123 [] = { 0x00 , 0x0b , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_122 [ 7 ] = F_29 ( V_122 , 7 ) ;
V_123 [ 7 ] = F_29 ( V_123 , 7 ) ;
F_4 ( V_15 , V_25 , 1 , L_60 ) ;
if ( V_2 -> V_35 & V_124 ) {
if ( F_33 ( V_2 , V_122 , 8 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_61 ) ;
goto V_125;
}
} else {
if ( F_33 ( V_2 , V_123 , 8 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_62 ) ;
goto V_125;
}
}
memcpy ( & V_2 -> V_126 , & V_2 -> V_103 , 8 ) ;
if ( V_2 -> V_35 & V_124 ) {
F_4 ( V_15 , V_25 , 1 , L_63 ) ;
}
if ( V_2 -> V_126 [ 0 ] == 0xbc ) {
if ( V_2 -> V_61 != V_67 )
V_2 -> V_35 |= V_94 ;
else
V_2 -> V_35 |= V_95 ;
if ( V_2 -> V_126 [ 1 ] == 0x01 ) {
V_2 -> V_68 |= V_127 ;
F_4 ( V_15 , V_25 , 1 , L_64 ) ;
}
}
return 0 ;
V_125:
if ( ! strncmp ( V_2 -> V_82 , L_32 , 6 ) ) {
V_2 -> V_35 |= V_96 ;
F_4 ( V_15 , V_25 , 1 , L_65 , V_2 -> V_82 ) ;
}
return - 1 ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_2 V_38 ;
int V_39 , V_106 ;
struct V_128 * V_129 = NULL ;
struct V_107 * V_108 = NULL ;
T_2 V_130 = 0 ;
T_1 V_131 = 0 ;
static T_2 V_132 [ 8 ] = { 0x00 , 0x06 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xff } ;
V_2 -> V_113 = 0 ;
V_132 [ 7 ] = F_29 ( V_132 , 7 ) ;
if ( F_16 ( V_2 , V_132 , V_133 ) )
return - 1 ;
if ( ( F_11 ( V_2 ) ) < 0 )
return - 1 ;
if ( F_18 ( V_2 , & V_38 , V_134 ) )
return - 1 ;
if ( V_38 != V_135 ) {
F_4 ( V_15 , V_16 , 1 , L_66 , V_38 ) ;
return - 1 ;
}
if ( ! F_12 ( V_2 , V_136 ) )
return - 1 ;
if ( F_18 ( V_2 , V_2 -> V_103 , V_133 ) )
return - 1 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_103 [ 7 ] != F_29 ( V_2 -> V_103 , 7 ) ) {
F_4 ( V_15 , V_16 , 1 , L_67 ) ;
return - 1 ;
}
V_2 -> V_103 [ 7 ] = '\0' ;
for ( V_39 = 0 , V_129 = V_137 ; V_39 < F_36 ( V_137 ) ; V_39 ++ , V_129 ++ ) {
if ( ! strncmp ( & V_2 -> V_103 [ V_129 -> V_138 ] , V_129 -> V_139 , strlen ( V_129 -> V_139 ) ) ) {
V_131 = V_129 -> V_35 ;
V_130 = V_129 -> V_61 ;
V_2 -> V_68 = V_129 -> V_140 ;
F_4 ( V_15 , V_25 , 1 , L_68 , V_129 -> V_139 ) ;
strncpy ( & V_2 -> V_82 [ 0 ] , V_129 -> V_139 , 6 ) ;
if ( V_129 -> V_113 & V_141 ) {
switch ( V_130 ) {
case V_62 :
if ( F_40 ( V_2 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_69 ) ;
V_2 -> V_113 = V_121 ;
}
break;
default:
break;
}
if ( F_41 ( V_2 ) < 0 )
F_4 ( V_15 , V_25 , 1 , L_69 ) ;
} else {
V_2 -> V_113 = V_129 -> V_113 ;
}
for ( V_106 = 0 , V_108 = V_111 ; V_106 < F_36 ( V_111 ) ; V_106 ++ , V_108 ++ ) {
if ( ! ( strncmp ( V_129 -> V_139 , V_108 -> V_82 , 7 ) ) &&
V_108 -> V_113 == V_2 -> V_113 ) {
F_4 ( V_15 , V_25 , 1 , L_70 ,
V_129 -> V_139 , V_108 -> V_114 ) ;
}
}
break;
}
}
if ( V_39 >= F_36 ( V_137 ) ) {
F_4 ( V_15 , V_25 , 1 , L_71 , & V_2 -> V_103 [ 0 ] , & V_2 -> V_103 [ 1 ] ) ;
F_4 ( V_15 , V_25 , 1 , L_72 ) ;
V_130 = V_62 ;
V_131 = V_81 ;
}
F_31 ( V_2 , V_130 ) ;
V_2 -> V_35 = V_131 ;
V_2 -> V_61 = V_130 ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_142 ) ;
if ( V_143 & V_72 ) {
if ( ( F_9 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_73 ) ;
return - 1 ;
}
F_6 ( 4000 ) ;
} else {
F_6 ( 100 ) ;
}
if ( ( F_15 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_74 ) ;
return - 1 ;
}
F_6 ( 100 ) ;
if ( F_43 ( V_2 ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_75 ) ;
return - 1 ;
}
if ( F_32 ( V_2 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_76 ) ;
}
if ( ( V_2 -> V_35 & V_124 ) || ( V_2 -> V_35 & V_144 ) ) {
if ( F_42 ( V_2 ) < 0 )
F_4 ( V_15 , V_16 , 1 , L_77 ) ;
}
if ( V_2 -> V_35 & V_96 ) {
F_1 ( V_2 , 204 ) ;
}
if ( V_2 -> V_35 & V_144 ) {
if ( F_34 ( V_2 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_78 ) ;
return 0 ;
}
if ( F_35 ( V_2 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_79 ) ;
return 0 ;
}
if ( F_37 ( V_2 ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_80 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_2 * V_41 , T_2 V_42 )
{
T_2 V_38 ;
F_46 ( & V_2 -> V_142 ) ;
if ( ( F_15 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_40 , 1 , L_81 ) ;
goto error;
}
if ( F_16 ( V_2 , V_41 , V_42 ) ) {
F_4 ( V_15 , V_16 , 1 , L_82 ) ;
if ( ( F_13 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_83 ) ;
goto error;
}
goto error;
}
if ( ( F_11 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_25 , 1 , L_84 ) ;
goto error;
}
if ( V_2 -> V_35 & V_36 )
F_47 ( 3 ) ;
if ( F_18 ( V_2 , & V_38 , V_134 ) ) {
F_4 ( V_15 , V_30 , 1 , L_82 ) ;
if ( ( F_13 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_83 ) ;
goto error;
}
goto error;
}
if ( V_38 != V_135 ) {
F_4 ( V_15 , V_16 , 1 , L_85 , V_38 ) ;
goto error;
}
if ( V_42 >= 2 && V_41 [ 0 ] == 0 && ( V_41 [ 1 ] == 1 || V_41 [ 1 ] == 3 ) )
goto error;
if ( V_2 -> V_35 & V_36 )
F_47 ( 3 ) ;
else
F_5 ( 2000 ) ;
if ( ! F_12 ( V_2 , V_29 ) )
goto error;
if ( F_18 ( V_2 , V_2 -> V_103 , V_133 ) ) {
F_4 ( V_15 , V_30 , 1 , L_82 ) ;
if ( ( F_13 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_16 , 1 , L_86 ) ;
goto error;
}
goto error;
}
if ( V_2 -> V_103 [ 7 ] != F_29 ( V_2 -> V_103 , 7 ) ) {
F_4 ( V_15 , V_16 , 1 , L_87 ) ;
goto error;
}
F_48 ( & V_2 -> V_142 ) ;
return 0 ;
error:
F_48 ( & V_2 -> V_142 ) ;
return - V_145 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_146 ;
T_2 V_147 [] = { 0x00 , 0x05 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xfb } ;
if ( ( V_2 -> V_148 & V_149 ) == 0 ) {
V_2 -> V_150 = V_2 -> V_151 = V_2 -> V_152 = 0 ;
return 0 ;
}
if ( 0 == ( V_2 -> V_148 & V_153 ) ) {
V_2 -> V_150 = V_2 -> V_151 = V_2 -> V_152 = 0 ;
return 0 ;
}
if ( F_50 ( V_154 , V_2 -> V_155 + ( V_156 / 5 ) ) ) {
V_146 = F_33 ( V_2 , V_147 , 8 ) ;
if ( V_146 < 0 )
return V_146 ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_150 = ( ( V_2 -> V_103 [ 6 ] & 0x10 ) == 0 ) ? 1 : 0 ;
V_2 -> V_151 = V_2 -> V_103 [ 5 ] << 8 ;
V_2 -> V_152 = V_2 -> V_103 [ 2 ] << 8 | V_2 -> V_103 [ 3 ] ;
} else if ( ( V_2 -> V_61 == V_65 ) || ( V_2 -> V_61 == V_66 ) ) {
V_2 -> V_150 = ( V_2 -> V_103 [ 1 ] ) ? 1 : 0 ;
V_2 -> V_151 = V_2 -> V_103 [ 4 ] << 8 ;
V_2 -> V_152 = V_2 -> V_103 [ 3 ] << 8 ;
} else if ( V_2 -> V_61 == V_67 ) {
V_2 -> V_150 = ( V_2 -> V_103 [ 6 ] == 0x00 ) ? 1 : 0 ;
V_2 -> V_151 = V_2 -> V_103 [ 4 ] << 8 ;
V_2 -> V_152 = V_2 -> V_103 [ 2 ] << 8 | V_2 -> V_103 [ 3 ] ;
}
V_2 -> V_155 = V_154 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
T_2 V_157 [ 8 ] = { 0x00 , 0x09 , 0xff , 0xff , 0x01 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_61 != V_62 )
return - V_71 ;
V_157 [ 4 ] = V_2 -> V_56 [ 4 ] ;
V_157 [ 2 ] = V_2 -> V_56 [ 2 ] ;
V_157 [ 3 ] = V_2 -> V_56 [ 3 ] ;
V_157 [ 7 ] = F_29 ( V_157 , 7 ) ;
return F_33 ( V_2 , V_157 , 8 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_146 ;
if ( ( V_2 -> V_148 & V_149 ) == 0 )
return 0 ;
V_2 -> V_148 &= ~ ( V_153 ) ;
if ( ! F_12 ( V_2 , V_29 ) )
return - V_145 ;
if ( ( V_2 -> V_35 & V_97 ) &&
! ( V_2 -> V_61 == V_67 ) )
V_146 = F_18 ( V_2 , V_2 -> V_158 , 10 ) ;
else
V_146 = F_18 ( V_2 , & V_2 -> V_158 [ 2 ] , V_133 ) ;
if ( V_146 < 0 ) {
F_4 ( V_15 , V_30 , 1 , L_88 ) ;
return V_146 ;
}
if ( ( V_2 -> V_35 & V_97 ) &&
! ( V_2 -> V_61 == V_67 ) ) {
if ( V_2 -> V_158 [ 9 ] != F_29 ( & V_2 -> V_158 [ 0 ] , 9 ) ) {
F_4 ( V_15 , V_16 , 1 , L_89 ) ;
return - V_145 ;
}
} else {
if ( V_2 -> V_158 [ 9 ] != F_29 ( & V_2 -> V_158 [ 2 ] , 7 ) ) {
F_4 ( V_15 , V_16 , 1 , L_90 ) ;
return - V_145 ;
}
}
if ( V_2 -> V_158 [ 2 ] == 0 && V_2 -> V_158 [ 3 ] == 0 )
return 0 ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_159 = ( ( V_2 -> V_158 [ 2 ] & 0x7f ) << 8 ) + V_2 -> V_158 [ 3 ] ;
} else {
V_2 -> V_159 = ( ( V_2 -> V_158 [ 2 ] & 0x7f ) << 16 ) + ( V_2 -> V_158 [ 3 ] << 8 ) + V_2 -> V_158 [ 4 ] ;
}
V_2 -> V_159 = V_2 -> V_159 * 1000 ;
V_2 -> V_150 = 1 ;
V_2 -> V_148 |= V_153 ;
return 1 ;
}
static int F_53 ( struct V_160 * V_161 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
int V_146 ;
T_2 V_38 ;
F_4 ( V_15 , V_16 , 1 , L_91 , V_2 -> V_35 ) ;
V_2 -> V_159 = 0 ;
V_2 -> V_150 = V_2 -> V_151 = V_2 -> V_152 = 0 ;
if ( V_2 -> V_61 == V_62 ) {
if ( ! ( V_2 -> V_148 & V_163 ) )
F_54 ( V_161 , V_55 ) ;
}
V_2 -> V_148 &= ~ ( V_153 | V_149 ) ;
F_46 ( & V_2 -> V_142 ) ;
if ( ( F_15 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_30 , 1 , L_92 ) ;
goto error;
}
if ( ( V_2 -> V_35 & V_97 ) &&
( ! ( V_2 -> V_61 == V_67 ) ) ) {
V_2 -> V_56 [ 9 ] = F_29 ( & V_2 -> V_56 [ 0 ] , 9 ) ;
V_146 = F_16 ( V_2 , & V_2 -> V_56 [ 0 ] , 10 ) ;
} else {
V_2 -> V_56 [ 9 ] = F_29 ( & V_2 -> V_56 [ 2 ] , 7 ) ;
V_146 = F_16 ( V_2 , & V_2 -> V_56 [ 2 ] , V_133 ) ;
}
if ( V_146 < 0 ) {
F_11 ( V_2 ) ;
F_4 ( V_15 , V_30 , 1 , L_93 ) ;
goto V_164;
}
if ( ( F_11 ( V_2 ) ) < 0 ) {
F_4 ( V_15 , V_30 , 1 , L_94 ) ;
goto error;
}
if ( ( F_18 ( V_2 , & V_38 , V_134 ) < 0 ) ) {
F_4 ( V_15 , V_30 , 1 , L_95 ) ;
goto error;
}
if ( V_38 != V_135 ) {
F_4 ( V_15 , V_30 , 1 , L_85 , V_38 ) ;
goto error;
}
V_2 -> V_148 |= V_149 ;
V_146 = F_52 ( V_2 ) ;
V_164:
F_48 ( & V_2 -> V_142 ) ;
return V_146 ;
error:
F_48 ( & V_2 -> V_142 ) ;
return - V_145 ;
}
static int F_55 ( struct V_160 * V_161 , struct V_165 * V_166 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
T_2 V_157 [ 8 ] = { 0x00 , 0x08 , 0x04 , 0xe0 , 0x10 , 0x38 , 0xf0 , 0xec } ;
if ( V_2 -> V_61 != V_62 )
return - V_71 ;
if ( V_166 -> V_167 > 0 && V_166 -> V_167 < 5 )
memcpy ( & V_157 [ 3 ] , V_166 -> V_44 , V_166 -> V_167 ) ;
else if ( V_166 -> V_167 == 5 && V_2 -> V_68 & V_168 )
memcpy ( & V_157 [ 2 ] , V_166 -> V_44 , V_166 -> V_167 ) ;
else
return - V_63 ;
V_157 [ 7 ] = F_29 ( & V_157 [ 0 ] , 7 ) ;
return F_33 ( V_2 , V_157 , 8 ) ;
}
static int F_54 ( struct V_160 * V_161 , T_7 V_54 )
{
int V_169 , V_146 = 0 ;
struct V_1 * V_2 = V_161 -> V_162 ;
V_2 -> V_54 = V_54 ;
if ( V_2 -> V_61 != V_62 )
return - V_71 ;
V_169 = 0 ;
switch ( V_54 ) {
case V_55 :
case V_57 :
if ( ( V_2 -> V_148 & V_163 ) == 0 )
V_169 = 1 ;
V_2 -> V_148 |= V_163 ;
V_2 -> V_56 [ 4 ] = 0x01 ;
break;
case V_58 :
V_169 = 1 ;
V_2 -> V_148 &= ~ ( V_163 | V_153 | V_149 ) ;
V_2 -> V_56 [ 4 ] = 0x00 ;
break;
default:
return - V_63 ;
}
if ( V_169 )
V_146 = F_51 ( V_2 ) ;
return V_146 ;
}
static int F_56 ( struct V_160 * V_161 , T_8 V_170 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
V_2 -> V_170 = V_170 ;
if ( V_2 -> V_61 != V_62 )
return - V_71 ;
switch ( V_170 ) {
case V_171 :
if ( V_2 -> V_35 & V_64 )
V_2 -> V_56 [ 2 ] = 0x00 ;
else
V_2 -> V_56 [ 2 ] = 0xff ;
break;
case V_172 :
V_2 -> V_56 [ 2 ] = 0x02 ;
break;
default:
return - V_63 ;
}
return F_51 ( V_2 ) ;
}
static int F_57 ( struct V_160 * V_161 , T_9 V_173 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
if ( V_2 -> V_61 != V_62 )
return - V_71 ;
V_2 -> V_173 = V_173 ;
switch ( V_173 ) {
case V_174 :
V_2 -> V_56 [ 3 ] = 0x02 ;
break;
case V_175 :
V_2 -> V_56 [ 3 ] = 0xff ;
break;
}
return F_51 ( V_2 ) ;
}
static int F_58 ( struct V_160 * V_161 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
static T_2 V_176 [] = { 0x09 , 0x00 , 0x03 , 0xb6 , 0x01 , 0x00 , 0x73 , 0x21 , 0x00 , 0x00 } ;
static T_2 V_177 [] = { 0x00 , 0x00 , 0x03 , 0xb6 , 0x01 , 0x55 , 0xbd , 0x50 , 0x00 , 0x00 } ;
static T_2 V_178 [] = { 0x09 , 0x00 , 0x03 , 0xb6 , 0x01 , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static T_2 V_179 [] = { 0x00 , 0x00 , 0x03 , 0xb6 , 0x01 , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static T_2 V_180 [] = { 0x09 , 0x00 , 0x03 , 0xb6 , 0x01 , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static T_2 V_181 [] = { 0x00 , 0x00 , 0x03 , 0xb6 , 0x01 , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static T_2 V_182 [] = { 0x00 , 0x00 , 0x03 , 0xb6 , 0x01 , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_2 -> V_73 = V_74 ;
V_2 -> V_54 = V_55 ;
V_2 -> V_170 = V_171 ;
V_2 -> V_148 = 0 ;
V_2 -> V_183 = 0x02 ;
V_2 -> V_70 = 7000000 ;
V_2 -> V_155 = V_154 ;
if ( V_2 -> V_61 == V_62 )
memcpy ( V_2 -> V_56 , ( ( V_2 -> V_35 & V_97 ) ? V_176 : V_177 ) , sizeof ( V_177 ) ) ;
else if ( V_2 -> V_61 == V_65 )
memcpy ( V_2 -> V_56 , ( ( V_2 -> V_35 & V_97 ) ? V_178 : V_179 ) , sizeof ( V_179 ) ) ;
else if ( V_2 -> V_61 == V_66 )
memcpy ( V_2 -> V_56 , ( ( V_2 -> V_35 & V_97 ) ? V_180 : V_181 ) , sizeof ( V_181 ) ) ;
else if ( V_2 -> V_61 == V_67 )
memcpy ( V_2 -> V_56 , V_182 , sizeof ( V_182 ) ) ;
return 0 ;
}
static int F_59 ( struct V_160 * V_161 , T_10 * V_184 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
* V_184 = 0 ;
if ( V_2 -> V_148 & V_153 ) {
if ( V_2 -> V_150 )
* V_184 |= V_185 | V_186 | V_187 | V_188 | V_189 ;
}
return 0 ;
}
static int F_60 ( struct V_160 * V_161 , T_11 * V_190 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
int V_146 = F_49 ( V_2 ) ;
* V_190 = V_2 -> V_151 ;
return V_146 ;
}
static int F_61 ( struct V_160 * V_161 , T_11 * V_191 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
int V_146 = F_49 ( V_2 ) ;
* V_191 = V_2 -> V_152 ;
return V_146 ;
}
static int F_62 ( struct V_160 * V_161 )
{
struct V_192 * V_193 = & V_161 -> V_194 ;
int V_146 = - V_63 ;
struct V_1 * V_2 = V_161 -> V_162 ;
if ( V_193 != NULL ) {
V_146 = F_20 ( V_2 , V_193 -> V_60 ) ;
if( V_146 != 0 )
return V_146 ;
F_4 ( V_15 , V_30 , 1 , L_96 , V_193 -> V_60 ) ;
if ( V_2 -> V_61 == V_62 ) {
if ( V_2 -> V_35 & V_64 )
F_22 ( V_2 , V_193 -> V_73 ) ;
F_23 ( V_2 , V_193 -> V_195 ) ;
F_25 ( V_2 , V_193 -> V_80 ) ;
F_19 ( V_2 ) ;
F_4 ( V_15 , V_30 , 1 , L_97 , V_193 -> V_80 ) ;
} else if ( V_2 -> V_61 == V_65 )
F_21 ( V_2 , V_193 -> V_196 ) ;
else if ( V_2 -> V_61 == V_66 ) {
F_23 ( V_2 , V_193 -> V_195 ) ;
F_25 ( V_2 , V_193 -> V_80 ) ;
F_27 ( V_2 , V_193 -> V_83 ) ;
}
V_146 = F_53 ( V_161 ) ;
}
return V_146 ;
}
static int F_63 ( struct V_160 * V_161 ,
bool V_197 ,
unsigned int V_198 ,
unsigned int * V_11 ,
T_10 * V_184 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
struct V_192 * V_193 = & V_161 -> V_194 ;
if ( V_197 ) {
F_20 ( V_2 , V_193 -> V_60 ) ;
F_4 ( V_15 , V_30 , 1 , L_96 , V_193 -> V_60 ) ;
if ( V_2 -> V_61 == V_62 ) {
if ( V_2 -> V_35 & V_64 )
F_22 ( V_2 , V_193 -> V_73 ) ;
F_23 ( V_2 , V_193 -> V_195 ) ;
F_25 ( V_2 , V_193 -> V_80 ) ;
F_19 ( V_2 ) ;
F_4 ( V_15 , V_30 , 1 , L_97 , V_193 -> V_80 ) ;
} else if ( V_2 -> V_61 == V_65 )
F_21 ( V_2 , V_193 -> V_196 ) ;
else if ( V_2 -> V_61 == V_66 ) {
F_23 ( V_2 , V_193 -> V_195 ) ;
F_25 ( V_2 , V_193 -> V_80 ) ;
F_27 ( V_2 , V_193 -> V_83 ) ;
}
F_53 ( V_161 ) ;
}
if ( ! ( V_198 & V_199 ) )
F_59 ( V_161 , V_184 ) ;
* V_11 = V_156 / 10 ;
return 0 ;
}
static int F_64 ( struct V_160 * V_161 )
{
return V_200 ? V_201 : V_202 ;
}
static int F_65 ( struct V_160 * V_161 )
{
struct V_192 * V_193 = & V_161 -> V_194 ;
struct V_1 * V_2 = V_161 -> V_162 ;
V_193 -> V_60 = V_2 -> V_159 ;
if ( V_2 -> V_61 == V_62 ) {
if ( V_2 -> V_35 & V_64 )
V_193 -> V_73 = V_2 -> V_73 ;
V_193 -> V_80 = V_2 -> V_80 ;
V_193 -> V_195 = F_24 ( V_2 ) ;
} else if ( V_2 -> V_61 == V_65 ) {
V_193 -> V_196 = V_2 -> V_70 ;
} else if ( V_2 -> V_61 == V_66 ) {
V_193 -> V_80 = V_2 -> V_80 ;
V_193 -> V_195 = F_24 ( V_2 ) ;
V_193 -> V_83 = F_28 ( V_2 ) ;
}
return 0 ;
}
static void F_66 ( struct V_160 * V_161 )
{
struct V_1 * V_2 = V_161 -> V_162 ;
if ( V_2 -> V_203 ) {
F_67 ( V_2 -> V_203 ) ;
#ifdef F_68
F_69 ( V_204 ) ;
#endif
}
F_70 ( V_2 ) ;
}
struct V_1 * F_71 ( struct V_1 * V_2 , struct V_205 * V_205 )
{
if ( F_44 ( V_2 ) < 0 ) {
F_70 ( V_2 ) ;
return NULL ;
}
switch ( V_2 -> V_61 ) {
case V_65 :
memcpy ( & V_2 -> V_206 . V_207 , & V_208 , sizeof( struct V_209 ) ) ;
break;
case V_66 :
memcpy ( & V_2 -> V_206 . V_207 , & V_210 , sizeof( struct V_209 ) ) ;
break;
case V_62 :
memcpy ( & V_2 -> V_206 . V_207 , & V_211 , sizeof( struct V_209 ) ) ;
break;
case V_67 :
memcpy ( & V_2 -> V_206 . V_207 , & V_212 , sizeof( struct V_209 ) ) ;
break;
default:
F_4 ( V_15 , V_25 , 1 , L_98 ) ;
F_70 ( V_2 ) ;
return NULL ;
}
V_2 -> V_206 . V_162 = V_2 ;
return V_2 ;
}
