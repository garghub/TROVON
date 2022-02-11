static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 V_4 , T_1 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 , V_10 , V_11 ;
F_3 ( & V_2 -> V_12 ) ;
memcpy ( & V_8 -> V_13 [ 0 ] , V_3 , V_4 ) ;
V_8 -> V_13 [ 60 ] = V_8 -> V_14 ++ ;
F_4 ( & V_2 -> V_15 -> V_16 , L_1 , V_17 , V_4 , V_8 -> V_13 ) ;
V_10 = F_5 ( V_2 , V_8 -> V_13 , sizeof( V_8 -> V_13 ) ,
V_8 -> V_13 , sizeof( V_8 -> V_13 ) ) ;
if ( V_10 )
goto V_18;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_10 = F_6 ( V_2 -> V_15 , F_7 ( V_2 -> V_15 ,
V_2 -> V_19 -> V_20 ) ,
V_8 -> V_13 , sizeof( V_8 -> V_13 ) , & V_9 , 2000 ) ;
if ( V_10 ) {
F_4 ( & V_2 -> V_15 -> V_16 ,
L_2 ,
V_17 , V_10 ) ;
} else {
F_4 ( & V_2 -> V_15 -> V_16 , L_3 , V_17 ,
V_6 , V_8 -> V_13 ) ;
if ( V_8 -> V_13 [ 63 ] != 0x4f )
F_4 ( & V_2 -> V_15 -> V_16 ,
L_4 , V_17 ) ;
break;
}
}
if ( V_10 ) {
F_8 ( & V_2 -> V_15 -> V_16 , L_2 ,
V_21 , V_10 ) ;
goto V_18;
}
if ( V_5 && V_6 )
memcpy ( V_5 , V_8 -> V_13 , V_6 ) ;
V_18:
F_9 ( & V_2 -> V_12 ) ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_22 , T_1 * V_23 )
{
T_1 V_13 [] = { V_24 , V_22 >> 8 , V_22 & 0xff , 0x01 } ;
int V_10 ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_23 , 1 ) ;
F_4 ( & V_2 -> V_15 -> V_16 , L_5 , V_17 , V_22 , * V_23 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_23 )
{
T_1 V_13 [] = { V_25 , V_22 >> 8 , V_22 & 0xff , 0x01 , V_23 } ;
F_4 ( & V_2 -> V_15 -> V_16 , L_5 , V_17 , V_22 , V_23 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_23 ,
T_1 V_26 )
{
int V_10 ;
T_1 V_27 ;
if ( V_26 != 0xff ) {
V_10 = F_10 ( V_2 , V_22 , & V_27 ) ;
if ( V_10 )
return V_10 ;
V_23 &= V_26 ;
V_27 &= ~ V_26 ;
V_23 |= V_27 ;
}
return F_11 ( V_2 , V_22 , V_23 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_22 , T_1 * V_23 ,
T_1 V_26 )
{
int V_10 , V_11 ;
T_1 V_27 ;
V_10 = F_10 ( V_2 , V_22 , & V_27 ) ;
if ( V_10 )
return V_10 ;
V_27 &= V_26 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
if ( ( V_26 >> V_11 ) & 0x01 )
break;
}
* V_23 = V_27 >> V_11 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_28 )
{
T_1 V_13 [] = { V_29 } ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_28 , 3 ) ;
}
static int F_15 ( struct V_30 * V_31 , int V_32 )
{
T_1 V_13 [] = { V_33 , ( T_1 ) V_32 , 0x00 } ;
F_4 ( & F_16 ( V_31 ) -> V_15 -> V_16 , L_6 , V_17 , V_32 ) ;
return F_1 ( F_16 ( V_31 ) , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_34 , T_1 V_35 )
{
T_1 V_13 [] = { V_36 , 0x01 , V_34 , V_35 } ;
F_4 ( & V_2 -> V_15 -> V_16 , L_7 , V_17 ,
V_34 , V_35 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_32 )
{
T_1 V_13 [] = { V_36 , 0x02 , V_32 } ;
F_4 ( & V_2 -> V_15 -> V_16 , L_6 , V_17 , V_32 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_19 ( struct V_37 * V_38 , struct V_39 * V_40 ,
int V_41 )
{
struct V_1 * V_2 = F_20 ( V_38 ) ;
int V_10 = 0 , V_42 , V_11 = 0 ;
T_1 V_13 [ 52 ] ;
if ( F_21 ( & V_2 -> V_43 ) < 0 )
return - V_44 ;
while ( V_11 < V_41 ) {
if ( V_41 > V_11 + 1 && ( V_40 [ V_11 + 1 ] . V_45 & V_46 ) ) {
if ( V_40 [ V_11 ] . V_47 > 2 || V_40 [ V_11 + 1 ] . V_47 > 60 ) {
V_10 = - V_48 ;
break;
}
V_13 [ 0 ] = V_49 ;
V_13 [ 1 ] = ( V_40 [ V_11 ] . V_50 << 1 ) | 0x01 ;
V_13 [ 2 ] = V_40 [ V_11 ] . V_13 [ 0 ] ;
V_13 [ 3 ] = V_40 [ V_11 ] . V_13 [ 1 ] ;
V_13 [ 4 ] = V_40 [ V_11 ] . V_47 - 1 ;
V_13 [ 5 ] = V_40 [ V_11 + 1 ] . V_47 ;
V_10 = F_1 ( V_2 , V_13 , 6 , V_40 [ V_11 + 1 ] . V_13 ,
V_40 [ V_11 + 1 ] . V_47 ) ;
V_42 = 2 ;
} else {
if ( V_40 [ V_11 ] . V_47 > 48 ) {
V_10 = - V_48 ;
break;
}
V_13 [ 0 ] = V_51 ;
V_13 [ 1 ] = ( V_40 [ V_11 ] . V_50 << 1 ) ;
V_13 [ 2 ] = V_40 [ V_11 ] . V_47 ;
V_13 [ 3 ] = 0x01 ;
memcpy ( & V_13 [ 4 ] , V_40 [ V_11 ] . V_13 , V_40 [ V_11 ] . V_47 ) ;
V_10 = F_1 ( V_2 , V_13 , 4 + V_40 [ V_11 ] . V_47 , NULL , 0 ) ;
V_42 = 1 ;
}
if ( V_10 )
break;
V_11 += V_42 ;
}
F_9 ( & V_2 -> V_43 ) ;
return V_10 ? V_10 : V_11 ;
}
static T_3 F_22 ( struct V_37 * V_52 )
{
return V_53 ;
}
static int F_23 ( struct V_30 * V_31 )
{
static T_1 V_54 [] = { V_55 , 0x38 , 0x28 } ;
static T_1 V_56 [] = { V_57 , 0x80 } ;
static T_1 V_58 [] = { V_59 , 0x40 } ;
static T_1 V_60 [] = { V_61 , 0x28 , 0x20 } ;
static T_1 V_62 [] = { V_63 , 0x33 } ;
static T_1 V_64 [] = { V_65 , 0x32 } ;
F_24 ( V_31 , V_54 , sizeof( V_54 ) ) ;
F_25 ( 200 ) ;
F_24 ( V_31 , V_56 , sizeof( V_56 ) ) ;
F_24 ( V_31 , V_58 , sizeof( V_58 ) ) ;
F_24 ( V_31 , V_60 , sizeof( V_60 ) ) ;
F_24 ( V_31 , V_62 , sizeof( V_62 ) ) ;
F_24 ( V_31 , V_64 , sizeof( V_64 ) ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
T_1 V_66 [ 3 ] ;
V_10 = F_14 ( V_2 , V_66 ) ;
if ( V_10 )
goto error;
V_10 = F_14 ( V_2 , V_66 ) ;
if ( V_10 )
goto error;
F_27 ( & V_2 -> V_15 -> V_16 , L_8 ,
V_21 , V_66 [ 1 ] , V_66 [ 2 ] , V_66 [ 0 ] ) ;
V_8 -> V_67 = V_66 [ 0 ] ;
error:
return V_10 ;
}
static int F_28 ( struct V_30 * V_31 , int V_68 )
{
return F_12 ( F_16 ( V_31 ) , V_69 , ( V_68 << 4 ) , 0x10 ) ;
}
static int F_29 ( struct V_30 * V_31 , int V_32 )
{
struct V_7 * V_8 = F_30 ( V_31 ) ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_10 ;
F_4 ( & V_2 -> V_15 -> V_16 , L_9 , V_17 , V_31 -> V_28 , V_32 ) ;
if ( V_32 == 0 )
return 0 ;
switch ( V_8 -> V_67 ) {
case V_70 :
if ( V_31 -> V_28 == 0 ) {
V_10 = F_12 ( V_2 , V_71 , ( 0 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_69 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
} else {
V_10 = F_12 ( V_2 , V_71 , ( 0 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_69 , ( 0 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
}
break;
case V_72 :
case V_73 :
if ( V_31 -> V_28 == 0 ) {
V_10 = F_12 ( V_2 , V_71 , ( 0 << 6 ) , 0x40 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_69 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
} else {
V_10 = F_12 ( V_2 , V_71 , ( 0 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 6 ) , 0x40 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_69 , ( 0 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
}
break;
default:
V_10 = 0 ;
}
error:
return V_10 ;
}
static int F_31 ( struct V_1 * V_2 , const char * type ,
T_1 V_50 , void * V_74 )
{
int V_10 , V_41 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_75 * V_76 ;
struct V_37 * V_52 = & V_2 -> V_77 ;
struct V_78 V_79 = {
. V_50 = V_50 ,
. V_74 = V_74 ,
} ;
F_32 ( V_79 . type , type , V_80 ) ;
for ( V_41 = 0 ; V_41 < V_81 ; V_41 ++ ) {
if ( V_8 -> V_75 [ V_41 ] == NULL )
break;
}
F_4 ( & V_2 -> V_15 -> V_16 , L_10 , V_17 , V_41 ) ;
if ( V_41 == V_81 ) {
F_8 ( & V_2 -> V_15 -> V_16 , L_11 ,
V_21 ) ;
V_10 = - V_82 ;
goto V_83;
}
F_33 ( L_12 , V_79 . type ) ;
V_76 = F_34 ( V_52 , & V_79 ) ;
if ( V_76 == NULL || V_76 -> V_16 . V_84 == NULL ) {
V_10 = - V_82 ;
goto V_83;
}
if ( ! F_35 ( V_76 -> V_16 . V_84 -> V_85 ) ) {
F_36 ( V_76 ) ;
V_10 = - V_82 ;
goto V_83;
}
V_8 -> V_75 [ V_41 ] = V_76 ;
return 0 ;
V_83:
F_4 ( & V_2 -> V_15 -> V_16 , L_13 , V_17 , V_10 ) ;
return V_10 ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_41 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_75 * V_76 ;
V_41 = V_81 ;
while ( V_41 -- ) {
if ( V_8 -> V_75 [ V_41 ] != NULL )
break;
}
F_4 ( & V_2 -> V_15 -> V_16 , L_10 , V_17 , V_41 ) ;
if ( V_41 == - 1 ) {
F_8 ( & V_2 -> V_15 -> V_16 , L_11 ,
V_21 ) ;
goto V_83;
}
V_76 = V_8 -> V_75 [ V_41 ] ;
F_38 ( V_76 -> V_16 . V_84 -> V_85 ) ;
F_36 ( V_76 ) ;
V_8 -> V_75 [ V_41 ] = NULL ;
V_83:
F_4 ( & V_2 -> V_15 -> V_16 , L_14 , V_17 ) ;
}
static int F_39 ( struct V_86 * V_38 )
{
struct V_7 * V_8 = F_40 ( V_38 ) ;
struct V_1 * V_2 = F_41 ( V_38 ) ;
int V_10 = 0 ;
T_1 V_27 ;
struct V_39 V_40 [ 2 ] = {
{
. V_50 = 0x60 ,
. V_45 = 0 ,
. V_47 = 1 ,
. V_13 = L_15 ,
} , {
. V_50 = 0x60 ,
. V_45 = V_46 ,
. V_47 = 1 ,
. V_13 = & V_27 ,
}
} ;
switch ( V_8 -> V_67 ) {
case V_87 :
V_38 -> V_31 [ 0 ] = F_42 ( V_88 , & V_89 ,
& V_2 -> V_77 ) ;
if ( V_38 -> V_31 [ 0 ] )
break;
V_38 -> V_31 [ 0 ] = F_42 ( V_90 , & V_91 ,
& V_2 -> V_77 ) ;
break;
case V_92 :
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_93 , ( 0 << 7 ) , 0x80 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_42 ( V_90 , & V_91 ,
& V_2 -> V_77 ) ;
break;
case V_94 :
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_42 ( V_95 ,
& V_96 , & V_2 -> V_77 , 0x48 ) ;
break;
case V_97 :
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_42 ( V_98 , & V_99 ,
& V_2 -> V_77 ) ;
break;
case V_70 :
V_10 = F_12 ( V_2 , V_69 , ( 1 << 4 ) , 0x10 ) ;
if ( V_10 )
goto error;
V_27 = 0 ;
V_10 = F_43 ( & V_2 -> V_77 , V_40 , 2 ) ;
if ( V_10 == 2 && V_27 == 0xc7 ) {
F_4 ( & V_2 -> V_15 -> V_16 , L_16 ,
V_17 ) ;
V_8 -> V_100 = true ;
}
else
V_27 = 0 ;
V_10 = F_12 ( V_2 , V_69 , ( 0 << 4 ) , 0x10 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
if ( V_27 == 0xc7 ) {
V_38 -> V_31 [ 0 ] = F_42 ( V_95 ,
& V_101 ,
& V_2 -> V_77 , 0x48 ) ;
if ( V_38 -> V_31 [ 0 ] )
V_38 -> V_31 [ 0 ] -> V_102 . V_103 =
F_28 ;
} else {
V_38 -> V_31 [ 0 ] = F_42 ( V_95 ,
& V_96 ,
& V_2 -> V_77 , 0x48 ) ;
}
if ( ! V_38 -> V_31 [ 0 ] )
break;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
if ( V_27 == 0xc7 ) {
V_38 -> V_31 [ 1 ] = F_42 ( V_90 ,
& V_104 ,
& V_2 -> V_77 ) ;
if ( V_38 -> V_31 [ 1 ] )
V_38 -> V_31 [ 1 ] -> V_102 . V_103 =
F_28 ;
} else {
V_38 -> V_31 [ 1 ] = F_42 ( V_90 ,
& V_91 ,
& V_2 -> V_77 ) ;
}
break;
case V_72 :
case V_73 :
V_10 = F_12 ( V_2 , V_71 , ( 0 << 6 ) , 0x40 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_42 ( V_95 ,
& V_101 ,
& V_2 -> V_77 , 0x48 ) ;
if ( V_38 -> V_31 [ 0 ] )
V_38 -> V_31 [ 0 ] -> V_102 . V_103 = F_28 ;
if ( ! V_38 -> V_31 [ 0 ] )
break;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 6 ) , 0x40 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 1 ] = F_42 ( V_90 ,
& V_105 ,
& V_2 -> V_77 ) ;
if ( V_38 -> V_31 [ 1 ] )
V_38 -> V_31 [ 1 ] -> V_102 . V_103 = F_28 ;
V_8 -> V_106 = true ;
break;
case V_107 :
case V_108 :
V_10 = F_12 ( V_2 , V_69 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_42 ( V_109 ,
& V_110 , & V_2 -> V_77 , 0 ) ;
V_8 -> V_106 = true ;
break;
case V_111 :
V_10 = F_12 ( V_2 , V_69 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_42 ( V_112 ,
& V_113 , & V_2 -> V_77 , NULL ) ;
V_8 -> V_106 = true ;
break;
}
if ( ! V_38 -> V_31 [ 0 ] ) {
V_10 = - V_82 ;
F_8 ( & V_2 -> V_15 -> V_16 ,
L_17 ,
V_21 ) ;
}
error:
return V_10 ;
}
static int F_44 ( struct V_86 * V_38 )
{
struct V_7 * V_8 = F_40 ( V_38 ) ;
struct V_1 * V_2 = F_41 ( V_38 ) ;
struct V_30 * V_31 ;
int V_10 ;
F_4 ( & V_2 -> V_15 -> V_16 , L_18 , V_17 ) ;
switch ( V_8 -> V_67 ) {
case V_87 :
V_31 = F_42 ( V_114 , V_38 -> V_31 [ 0 ] , ( 0xc2 >> 1 ) , NULL ,
V_115 ) ;
break;
case V_92 :
V_31 = F_42 ( V_114 , V_38 -> V_31 [ 0 ] , ( 0xc2 >> 1 ) ,
& V_2 -> V_77 , V_115 ) ;
break;
case V_94 :
V_31 = F_42 ( V_114 , V_38 -> V_31 [ 0 ] , ( 0xc0 >> 1 ) ,
& V_2 -> V_77 , V_116 ) ;
break;
case V_97 :
V_31 = F_42 ( V_117 , V_38 -> V_31 [ 0 ] , & V_2 -> V_77 ,
& V_118 ) ;
break;
case V_70 :
if ( V_8 -> V_100 ) {
struct V_119 V_119 =
V_120 ;
V_119 . V_31 = V_38 -> V_31 [ 0 ] ;
V_10 = F_31 ( V_2 , L_19 , 0x60 ,
& V_119 ) ;
if ( V_10 )
goto V_83;
if ( V_38 -> V_31 [ 1 ] ) {
V_38 -> V_31 [ 1 ] -> V_121 =
V_38 -> V_31 [ 0 ] -> V_121 ;
memcpy ( & V_38 -> V_31 [ 1 ] -> V_102 . V_122 ,
& V_38 -> V_31 [ 0 ] -> V_102 . V_122 ,
sizeof( struct V_123 ) ) ;
}
return 0 ;
} else {
V_31 = F_42 ( V_114 , V_38 -> V_31 [ 0 ] ,
( 0xc0 >> 1 ) , & V_2 -> V_77 ,
V_116 ) ;
if ( V_31 && V_38 -> V_31 [ 1 ] ) {
V_31 = F_42 ( V_114 , V_38 -> V_31 [ 1 ] ,
( 0xc0 >> 1 ) , & V_2 -> V_77 ,
V_116 ) ;
}
}
break;
case V_72 :
case V_73 :
{
struct V_119 V_119 = V_120 ;
V_119 . V_31 = V_38 -> V_31 [ 0 ] ;
V_10 = F_31 ( V_2 , L_19 , 0x60 , & V_119 ) ;
if ( V_10 )
goto V_83;
if ( V_38 -> V_31 [ 1 ] ) {
V_38 -> V_31 [ 1 ] -> V_121 = V_38 -> V_31 [ 0 ] -> V_121 ;
memcpy ( & V_38 -> V_31 [ 1 ] -> V_102 . V_122 ,
& V_38 -> V_31 [ 0 ] -> V_102 . V_122 ,
sizeof( struct V_123 ) ) ;
}
return 0 ;
}
case V_107 :
case V_108 :
V_31 = F_42 ( V_124 , V_38 -> V_31 [ 0 ] ,
& V_125 , & V_2 -> V_77 ) ;
if ( V_31 ) {
V_31 = F_42 ( V_117 , V_38 -> V_31 [ 0 ] ,
& V_2 -> V_77 , & V_118 ) ;
}
break;
case V_111 :
{
struct V_119 V_119 =
V_126 ;
V_119 . V_31 = V_38 -> V_31 [ 0 ] ;
V_10 = F_31 ( V_2 , L_19 , 0x60 , & V_119 ) ;
if ( V_10 )
goto V_83;
return 0 ;
}
default:
V_31 = NULL ;
}
if ( V_31 )
V_10 = 0 ;
else
V_10 = - V_82 ;
V_83:
return V_10 ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_1 V_13 [] = { V_127 } ;
T_1 V_128 [ 2 ] ;
int V_10 ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_128 , sizeof( V_128 ) ) ;
if ( V_10 )
return V_10 ;
if ( V_128 [ 0 ] ) {
F_4 ( & V_2 -> V_15 -> V_16 , L_20 , V_17 ,
V_128 [ 1 ] ) ;
F_46 ( V_2 -> V_129 , V_130 ,
F_47 ( 0x08 , V_128 [ 1 ] ) , 0 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_131 * V_132 )
{
V_132 -> V_133 = V_134 ;
V_132 -> V_135 = F_45 ;
V_132 -> V_35 = 250 ;
return 0 ;
}
static int F_49 ( struct V_136 * V_137 , int V_138 ,
int V_50 )
{
struct V_1 * V_2 = V_137 -> V_139 ;
int V_10 ;
T_1 V_13 [] = { V_140 , 0x02 , 0x40 | V_50 >> 8 , V_50 & 0xff , 0x00 , 1 } ;
T_1 V_23 ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , & V_23 , 1 ) ;
if ( V_10 )
return V_10 ;
return V_23 ;
}
static int F_50 ( struct V_136 * V_137 , int V_138 ,
int V_50 , T_1 V_23 )
{
struct V_1 * V_2 = V_137 -> V_139 ;
int V_10 ;
T_1 V_13 [] = { V_140 , 0x03 , 0x40 | V_50 >> 8 , V_50 & 0xff , 0x00 , 1 , V_23 } ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_51 ( struct V_136 * V_137 , int V_138 ,
T_1 V_50 )
{
struct V_1 * V_2 = V_137 -> V_139 ;
int V_10 ;
T_1 V_13 [] = { V_140 , 0x04 , 0x40 , V_50 , 0x00 , 1 } ;
T_1 V_23 ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , & V_23 , 1 ) ;
if ( V_10 )
return V_10 ;
return V_23 ;
}
static int F_52 ( struct V_136 * V_137 , int V_138 ,
T_1 V_50 , T_1 V_23 )
{
struct V_1 * V_2 = V_137 -> V_139 ;
int V_10 ;
T_1 V_13 [] = { V_140 , 0x05 , 0x40 , V_50 , 0x00 , 1 , V_23 } ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_53 ( struct V_136 * V_137 , int V_138 )
{
struct V_1 * V_2 = V_137 -> V_139 ;
int V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_141 = V_142 + F_54 ( 1000 ) ;
V_10 = F_12 ( V_2 , V_93 , ( 0 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
F_55 ( 300 ) ;
V_10 = F_12 ( V_2 , V_93 , ( 1 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_56 ( struct V_136 * V_137 , int V_138 )
{
struct V_1 * V_2 = V_137 -> V_139 ;
int V_10 ;
V_10 = F_12 ( V_2 , V_93 , ( 0 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
F_55 ( 30 ) ;
V_10 = F_12 ( V_2 , V_93 , ( 1 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_57 ( struct V_136 * V_137 , int V_138 )
{
struct V_1 * V_2 = V_137 -> V_139 ;
int V_10 ;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 1 ) , 0x02 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_58 ( struct V_136 * V_137 , int V_138 ,
int V_143 )
{
struct V_1 * V_2 = V_137 -> V_139 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
T_1 V_27 = 0 ;
V_10 = F_13 ( V_2 , V_144 , & V_27 , 0x40 ) ;
if ( V_10 )
return V_10 ;
if ( V_27 == 0 ) {
V_10 = V_145 ;
if ( F_59 ( V_142 , V_8 -> V_141 ) )
V_10 |= V_146 ;
}
return V_10 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
V_8 -> V_137 . V_85 = V_147 ;
V_8 -> V_137 . V_148 = F_49 ;
V_8 -> V_137 . V_149 = F_50 ;
V_8 -> V_137 . V_150 = F_51 ;
V_8 -> V_137 . V_151 = F_52 ;
V_8 -> V_137 . V_152 = F_53 ;
V_8 -> V_137 . V_153 = F_56 ;
V_8 -> V_137 . V_154 = F_57 ;
V_8 -> V_137 . V_155 = F_58 ;
V_8 -> V_137 . V_139 = V_2 ;
V_10 = F_12 ( V_2 , V_93 , ( 1 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 2 ) | ( 0 << 1 ) | ( 0 << 0 ) , 0x07 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 2 ) | ( 1 << 1 ) | ( 1 << 0 ) , 0x07 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_61 ( & V_2 -> V_52 [ 0 ] . V_156 , & V_8 -> V_137 , 0 , 1 ) ;
if ( V_10 )
return V_10 ;
V_8 -> V_157 = true ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_157 )
F_63 ( & V_8 -> V_137 ) ;
return;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_65 ( V_2 -> V_15 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_17 ( V_2 , 0x01 , 0x03 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_18 ( V_2 , 1 ) ;
if ( V_10 )
return V_10 ;
if ( V_8 -> V_106 ) {
V_10 = F_60 ( V_2 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_75 [ 0 ] )
F_37 ( V_2 ) ;
return F_62 ( V_2 ) ;
}
