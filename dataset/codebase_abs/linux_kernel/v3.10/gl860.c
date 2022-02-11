static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 -> V_4 , struct V_3 , V_5 ) ;
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
switch ( V_2 -> V_7 ) {
case V_8 :
V_6 -> V_9 . V_10 = V_2 -> V_11 ;
break;
case V_12 :
V_6 -> V_9 . V_13 = V_2 -> V_11 ;
break;
case V_14 :
V_6 -> V_9 . V_15 = V_2 -> V_11 ;
break;
case V_16 :
V_6 -> V_9 . V_17 = V_2 -> V_11 ;
break;
case V_18 :
V_6 -> V_9 . gamma = V_2 -> V_11 ;
break;
case V_19 :
V_6 -> V_9 . V_20 = V_2 -> V_11 ;
break;
case V_21 :
V_6 -> V_9 . V_22 = V_2 -> V_11 ;
break;
case V_23 :
V_6 -> V_9 . V_24 = V_2 -> V_11 ;
break;
case V_25 :
V_6 -> V_9 . V_26 = V_2 -> V_11 ;
break;
case V_27 :
V_6 -> V_9 . V_28 = V_2 -> V_11 ;
break;
case V_29 :
V_6 -> V_9 . V_30 = V_2 -> V_11 ;
break;
default:
return - V_31 ;
}
if ( V_3 -> V_32 )
V_6 -> V_33 = 1 ;
return 0 ;
}
static int F_3 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_34 * V_35 = & V_3 -> V_5 ;
V_3 -> V_36 . V_5 = V_35 ;
F_4 ( V_35 , 11 ) ;
if ( V_6 -> V_37 . V_10 )
F_5 ( V_35 , & V_38 , V_8 ,
0 , V_6 -> V_37 . V_10 , 1 ,
V_6 -> V_9 . V_10 ) ;
if ( V_6 -> V_37 . V_13 )
F_5 ( V_35 , & V_38 , V_12 ,
0 , V_6 -> V_37 . V_13 , 1 ,
V_6 -> V_9 . V_13 ) ;
if ( V_6 -> V_37 . V_15 )
F_5 ( V_35 , & V_38 , V_14 ,
0 , V_6 -> V_37 . V_15 , 1 ,
V_6 -> V_9 . V_15 ) ;
if ( V_6 -> V_37 . V_17 )
F_5 ( V_35 , & V_38 , V_16 ,
0 , V_6 -> V_37 . V_17 , 1 , V_6 -> V_9 . V_17 ) ;
if ( V_6 -> V_37 . gamma )
F_5 ( V_35 , & V_38 , V_18 ,
0 , V_6 -> V_37 . gamma , 1 , V_6 -> V_9 . gamma ) ;
if ( V_6 -> V_37 . V_20 )
F_5 ( V_35 , & V_38 , V_19 ,
0 , V_6 -> V_37 . V_20 , 1 , V_6 -> V_9 . V_20 ) ;
if ( V_6 -> V_37 . V_22 )
F_5 ( V_35 , & V_38 , V_21 ,
0 , V_6 -> V_37 . V_22 , 1 , V_6 -> V_9 . V_22 ) ;
if ( V_6 -> V_37 . V_24 )
F_6 ( V_35 , & V_38 ,
V_23 ,
V_6 -> V_37 . V_24 , 0 , V_6 -> V_9 . V_24 ) ;
if ( V_6 -> V_37 . V_26 )
F_5 ( V_35 , & V_38 ,
V_25 ,
0 , V_6 -> V_37 . V_26 , 1 , V_6 -> V_9 . V_26 ) ;
if ( V_6 -> V_37 . V_28 )
F_5 ( V_35 , & V_38 , V_27 ,
0 , V_6 -> V_37 . V_28 , 1 ,
V_6 -> V_9 . V_28 ) ;
if ( V_6 -> V_37 . V_30 )
F_5 ( V_35 , & V_38 ,
V_29 ,
0 , V_6 -> V_37 . V_30 , 1 ,
V_6 -> V_9 . V_30 ) ;
if ( V_35 -> error ) {
F_7 ( L_1 ) ;
return V_35 -> error ;
}
return 0 ;
}
static int F_8 ( struct V_3 * V_3 ,
const struct V_39 * V_7 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_40 * V_40 ;
T_1 V_41 , V_42 ;
V_41 = V_7 -> V_43 ;
V_42 = V_7 -> V_44 ;
V_6 -> V_45 = 1 ;
V_6 -> V_46 = - 1 ;
V_6 -> V_47 = 0xff ;
if ( strcmp ( V_47 , L_2 ) == 0 )
V_6 -> V_47 = V_48 ;
else if ( strcmp ( V_47 , L_3 ) == 0 )
V_6 -> V_47 = V_49 ;
else if ( strcmp ( V_47 , L_4 ) == 0 )
V_6 -> V_47 = V_50 ;
else if ( strcmp ( V_47 , L_5 ) == 0 )
V_6 -> V_47 = V_51 ;
if ( F_9 ( V_3 , V_41 , V_42 ) == - 1 )
return - 1 ;
V_40 = & V_3 -> V_40 ;
switch ( V_6 -> V_47 ) {
case V_48 :
V_3 -> V_52 = & V_53 ;
V_40 -> V_54 = V_55 ;
V_40 -> V_56 = F_10 ( V_55 ) ;
V_57 = V_58 ;
break;
case V_51 :
V_3 -> V_52 = & V_59 ;
V_40 -> V_54 = V_60 ;
V_40 -> V_56 = F_10 ( V_60 ) ;
V_57 = V_61 ;
break;
case V_49 :
V_3 -> V_52 = & V_62 ;
V_40 -> V_54 = V_63 ;
V_40 -> V_56 = F_10 ( V_63 ) ;
V_57 = V_64 ;
break;
case V_50 :
V_3 -> V_52 = & V_65 ;
V_40 -> V_54 = V_66 ;
V_40 -> V_56 = F_10 ( V_66 ) ;
V_57 = V_67 ;
break;
}
V_57 ( V_3 ) ;
if ( V_24 != 0xff )
( (struct V_6 * ) V_3 ) -> V_9 . V_24 = V_24 ;
return 0 ;
}
static int F_11 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
return V_6 -> V_68 ( V_3 ) ;
}
static int F_12 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
return V_6 -> V_69 ( V_3 ) ;
}
static int F_13 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
return V_6 -> V_70 ( V_3 ) ;
}
static void F_14 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
if ( ! V_6 -> V_3 . V_71 )
return;
return V_6 -> V_72 ( V_3 ) ;
}
static void F_15 ( struct V_3 * V_3 ,
T_2 * V_73 , int V_74 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
static T_3 V_75 ;
T_3 V_76 = ( T_3 ) V_3 -> V_77 ;
T_3 V_78 =
V_6 -> V_79 * ( V_3 -> V_40 . V_54 [ V_76 ] . V_80 + 1 ) ;
switch ( * ( V_81 * ) V_73 ) {
case 0x0202 :
F_16 ( V_3 , V_82 , NULL , 0 ) ;
V_75 = 0 ;
if ( V_6 -> V_46 >= 0 && V_6 -> V_46 < 10 )
V_6 -> V_46 ++ ;
F_16 ( V_3 , V_83 , NULL , 0 ) ;
break;
default:
V_73 += 2 ;
V_74 -= 2 ;
if ( V_75 + V_74 <= V_78 )
V_75 += V_74 ;
else {
if ( V_75 < V_78 && V_75 + V_74 > V_78 ) {
V_73 += V_78 - V_75 ;
V_74 -= V_78 - V_75 ;
V_75 = V_78 + 1 ;
}
F_16 ( V_3 ,
V_84 , V_73 , V_74 ) ;
}
break;
}
}
static void F_17 ( struct V_3 * V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
if ( ! V_85 ) {
T_2 V_86 ;
T_2 V_87 ;
F_18 ( V_3 , 0xc0 , 2 , 0x0000 , 0x0000 , 1 , ( void * ) & V_86 ) ;
V_87 = ( V_86 == 0xc8 || V_86 == 0x40 ) ;
if ( V_87 && V_6 -> V_45 > - 4 ) {
if ( V_6 -> V_45 > 0 )
V_6 -> V_45 = 0 ;
if ( V_6 -> V_45 == - 3 ) {
V_6 -> V_88 = 1 ;
V_6 -> V_33 = 1 ;
}
V_6 -> V_45 -- ;
}
if ( ! V_87 && V_6 -> V_45 < 4 ) {
if ( V_6 -> V_45 < 0 )
V_6 -> V_45 = 0 ;
if ( V_6 -> V_45 == 3 ) {
V_6 -> V_88 = 0 ;
V_6 -> V_33 = 1 ;
}
V_6 -> V_45 ++ ;
}
}
if ( V_6 -> V_33 )
V_6 -> V_89 ( V_3 ) ;
}
static int F_19 ( struct V_90 * V_91 ,
const struct V_39 * V_7 )
{
return F_20 ( V_91 , V_7 ,
& V_53 , sizeof( struct V_6 ) , V_92 ) ;
}
static void F_21 ( struct V_90 * V_91 )
{
F_22 ( V_91 ) ;
}
int F_23 ( struct V_3 * V_3 ,
unsigned char V_93 , T_4 V_94 , T_1 V_11 , T_1 V_95 ,
T_3 V_74 , void * V_96 )
{
struct V_97 * V_98 = V_3 -> V_99 ;
T_3 V_100 = 0 ;
if ( V_93 == 0x40 ) {
if ( V_74 > 0 ) {
memcpy ( V_3 -> V_101 , V_96 , V_74 ) ;
V_100 = F_24 ( V_98 , F_25 ( V_98 , 0 ) ,
V_94 , V_93 , V_11 , V_95 ,
V_3 -> V_101 ,
V_74 , 400 + 200 * ( V_74 > 1 ) ) ;
} else {
V_100 = F_24 ( V_98 , F_25 ( V_98 , 0 ) ,
V_94 , V_93 , V_11 , V_95 , NULL , V_74 , 400 ) ;
}
} else {
if ( V_74 > 0 ) {
V_100 = F_24 ( V_98 , F_26 ( V_98 , 0 ) ,
V_94 , V_93 , V_11 , V_95 ,
V_3 -> V_101 ,
V_74 , 400 + 200 * ( V_74 > 1 ) ) ;
memcpy ( V_96 , V_3 -> V_101 , V_74 ) ;
} else {
V_100 = F_24 ( V_98 , F_26 ( V_98 , 0 ) ,
V_94 , V_93 , V_11 , V_95 , NULL , V_74 , 400 ) ;
}
}
if ( V_100 < 0 )
F_7 ( L_6 ,
V_100 , V_93 , V_94 , V_11 , V_95 , V_74 ) ;
else if ( V_74 > 1 && V_100 < V_74 )
F_27 ( L_7 , V_100 , V_74 ) ;
F_28 ( 1 ) ;
return V_100 ;
}
int F_29 ( struct V_3 * V_3 , struct V_102 * V_103 , int V_74 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_74 ; V_104 ++ ) {
if ( V_103 [ V_104 ] . V_105 != 0xffff )
F_30 ( V_3 , 0x40 , 1 , V_103 [ V_104 ] . V_11 ,
V_103 [ V_104 ] . V_105 , 0 , NULL ) ;
else if ( V_103 [ V_104 ] . V_11 == 0xffff )
break;
else
F_28 ( V_103 [ V_104 ] . V_11 ) ;
}
return V_104 ;
}
int F_31 ( struct V_3 * V_3 , struct V_102 * V_103 ,
int V_74 , int V_104 )
{
while ( ++ V_104 < V_74 ) {
if ( V_103 [ V_104 ] . V_105 != 0xffff )
F_30 ( V_3 , 0x40 , 1 , V_103 [ V_104 ] . V_11 , V_103 [ V_104 ] . V_105 ,
0 , NULL ) ;
else if ( V_103 [ V_104 ] . V_11 == 0xffff )
break;
else
F_28 ( V_103 [ V_104 ] . V_11 ) ;
}
return V_104 ;
}
void F_32 ( struct V_3 * V_3 , struct V_106 * V_103 , int V_74 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_74 ; V_104 ++ ) {
if ( memcmp ( V_103 [ V_104 ] . V_73 , L_8 , 3 ) != 0 )
F_30 ( V_3 , 0x40 , 3 , 0x7a00 , V_103 [ V_104 ] . V_105 ,
3 , V_103 [ V_104 ] . V_73 ) ;
else
F_28 ( V_103 [ V_104 ] . V_105 ) ;
}
}
static int F_9 ( struct V_3 * V_3 ,
T_1 V_41 , T_1 V_42 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
T_2 V_107 , V_108 , V_109 , V_110 , V_111 ;
if ( V_42 == 0xf191 )
V_6 -> V_47 = V_48 ;
if ( V_6 -> V_47 == 0xff ) {
F_18 ( V_3 , 0xc0 , 2 , 0x0000 , 0x0004 , 1 , & V_107 ) ;
F_18 ( V_3 , 0xc0 , 2 , 0x0000 , 0x0004 , 1 , & V_107 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x0000 , 0x0000 , 0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x0010 , 0x0010 , 0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x0008 , 0x00c0 , 0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x0001 , 0x00c1 , 0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x0001 , 0x00c2 , 0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x0020 , 0x0006 , 0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x006a , 0x000d , 0 , NULL ) ;
F_28 ( 56 ) ;
F_33 ( V_112 , L_9 ) ;
V_110 = 0 ;
for ( V_111 = 0 ; V_111 < 4 ; V_111 ++ ) {
F_30 ( V_3 , 0x40 , 1 , 0x0040 , 0x0000 , 0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x0063 , 0x0006 , 0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x7a00 , 0x8030 , 0 , NULL ) ;
F_28 ( 10 ) ;
F_18 ( V_3 , 0xc0 , 2 , 0x7a00 , 0x8030 , 1 , & V_107 ) ;
F_33 ( V_112 , L_10 , V_107 ) ;
if ( V_107 == 0xff )
V_110 ++ ;
}
if ( V_110 ) {
F_33 ( V_112 , L_11 ) ;
F_33 ( V_112 , L_12 ) ;
V_108 = V_109 = 0 ;
for ( V_111 = 0 ; V_111 < 4 ; V_111 ++ ) {
F_30 ( V_3 , 0x40 , 1 , 0x0040 , 0x0000 ,
0 , NULL ) ;
F_28 ( 3 ) ;
F_30 ( V_3 , 0x40 , 1 , 0x6000 , 0x800a ,
0 , NULL ) ;
F_28 ( 10 ) ;
F_18 ( V_3 , 0xc0 , 2 , 0x6000 , 0x800a ,
1 , & V_107 ) ;
if ( V_107 == 0x26 || V_107 == 0x40 ) {
F_33 ( V_112 ,
L_13 ,
V_107 ) ;
V_6 -> V_47 = V_49 ;
V_108 += 4 ;
break;
}
if ( V_107 == 0x96 || V_107 == 0x55 ) {
F_33 ( V_112 ,
L_14 ,
V_107 ) ;
V_6 -> V_47 = V_50 ;
V_109 += 4 ;
break;
}
F_33 ( V_112 , L_10 , V_107 ) ;
if ( V_107 == 0x00 )
V_108 ++ ;
if ( V_107 == 0xff )
V_109 ++ ;
F_28 ( 3 ) ;
}
if ( V_108 < 4 && V_109 < 4 )
return - 1 ;
} else {
F_33 ( V_112 , L_15 ) ;
V_6 -> V_47 = V_51 ;
}
}
if ( V_113 ) {
F_33 ( V_112 , L_16 ) ;
} else if ( V_114 ) {
F_33 ( V_112 , L_17 ) ;
} else if ( V_85 ) {
F_33 ( V_112 , L_18 ) ;
} else if ( V_115 ) {
F_33 ( V_112 , L_19 ) ;
} else {
F_33 ( V_112 , L_20 ) ;
return - 1 ;
}
return 0 ;
}
