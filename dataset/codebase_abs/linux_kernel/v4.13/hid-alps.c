static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_2 V_5 , bool V_6 )
{
int V_7 , V_8 ;
T_2 V_9 ;
T_2 * V_10 ;
T_2 * V_11 ;
V_10 = F_2 ( V_12 , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
V_10 [ 0 ] = V_15 ;
if ( V_6 ) {
V_10 [ 1 ] = V_16 ;
V_10 [ 6 ] = 0x00 ;
} else {
V_10 [ 1 ] = V_17 ;
V_10 [ 6 ] = V_5 ;
}
F_3 ( V_3 , V_10 + 2 ) ;
V_9 = V_18 ;
for ( V_8 = 0 ; V_8 < V_12 - 1 ; V_8 ++ )
V_9 += V_10 [ V_8 ] ;
V_10 [ 7 ] = V_9 ;
V_7 = F_4 ( V_2 , V_15 , V_10 ,
V_12 ,
V_19 , V_20 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_1 , V_7 ) ;
goto exit;
}
if ( V_6 ) {
V_11 = F_2 ( V_12 , V_13 ) ;
if ( ! V_11 ) {
V_7 = - V_14 ;
goto exit;
}
V_7 = F_4 ( V_2 , V_15 , V_11 ,
V_12 ,
V_19 , V_22 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_2 , V_7 ) ;
F_6 ( V_11 ) ;
goto exit;
}
* V_4 = V_11 [ 6 ] ;
F_6 ( V_11 ) ;
}
V_7 = 0 ;
exit:
F_6 ( V_10 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_2 * V_25 , int V_26 )
{
unsigned int V_27 , V_28 , V_29 ;
int V_8 ;
short V_30 , V_31 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
switch ( V_25 [ 0 ] ) {
case V_34 :
break;
case V_15 :
break;
case V_35 :
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
T_2 * V_37 = & V_25 [ V_8 * 5 ] ;
V_27 = F_9 ( V_37 + 3 ) ;
V_28 = F_9 ( V_37 + 5 ) ;
V_29 = V_37 [ 7 ] & 0x7F ;
F_10 ( V_33 -> V_10 , V_8 ) ;
if ( V_29 != 0 ) {
F_11 ( V_33 -> V_10 ,
V_38 , 1 ) ;
F_12 ( V_33 -> V_10 ,
V_39 , V_27 ) ;
F_12 ( V_33 -> V_10 ,
V_40 , V_28 ) ;
F_12 ( V_33 -> V_10 ,
V_41 , V_29 ) ;
} else {
F_11 ( V_33 -> V_10 ,
V_38 , 0 ) ;
}
}
F_13 ( V_33 -> V_10 ) ;
F_14 ( V_33 -> V_10 , V_42 ,
V_25 [ 1 ] & 0x1 ) ;
F_14 ( V_33 -> V_10 , V_43 ,
( V_25 [ 1 ] & 0x2 ) ) ;
F_14 ( V_33 -> V_10 , V_44 ,
( V_25 [ 1 ] & 0x4 ) ) ;
F_15 ( V_33 -> V_10 ) ;
return 1 ;
case V_45 :
V_30 = F_9 ( V_25 + 2 ) ;
V_31 = F_9 ( V_25 + 4 ) ;
V_30 = V_30 / 8 ;
V_31 = V_31 / 8 ;
F_16 ( V_33 -> V_46 , V_47 , V_30 ) ;
F_16 ( V_33 -> V_46 , V_48 , V_31 ) ;
F_14 ( V_33 -> V_46 , V_42 ,
V_25 [ 1 ] & 0x1 ) ;
F_14 ( V_33 -> V_46 , V_43 ,
( V_25 [ 1 ] & 0x2 ) ) ;
F_14 ( V_33 -> V_46 , V_44 ,
( V_25 [ 1 ] & 0x4 ) ) ;
F_15 ( V_33 -> V_46 ) ;
return 1 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_49 ,
NULL , V_50 | V_51 , false ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_49 ,
NULL , V_50 | V_51 , false ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_32 * V_25 = F_8 ( V_2 ) ;
struct V_54 * V_10 = V_53 -> V_10 , * V_46 ;
struct V_32 V_55 ;
int V_7 ;
int V_56 , V_57 , V_8 ;
V_25 -> V_10 = V_10 ;
F_20 ( V_2 , L_3 ) ;
V_7 = F_21 ( V_2 ) ;
if ( V_7 )
return V_7 ;
F_22 ( V_2 ) ;
V_7 = F_1 ( V_2 , V_49 ,
& V_55 . V_58 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_4 , V_7 ) ;
goto exit;
}
V_55 . V_58 &= ~ V_59 ;
V_55 . V_58 |= V_50 ;
V_7 = F_1 ( V_2 , V_49 ,
NULL , V_55 . V_58 , false ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_5 , V_7 ) ;
goto exit;
}
V_7 = F_1 ( V_2 , V_60 ,
& V_55 . V_61 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_6 , V_7 ) ;
goto exit;
}
V_7 = F_1 ( V_2 , V_62 ,
& V_55 . V_63 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_7 , V_7 ) ;
goto exit;
}
V_7 = F_1 ( V_2 , V_64 ,
& V_55 . V_65 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_8 , V_7 ) ;
goto exit;
}
V_7 = F_1 ( V_2 , V_66 ,
& V_55 . V_67 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_9 , V_7 ) ;
goto exit;
}
V_7 = F_1 ( V_2 , V_68 ,
& V_55 . V_69 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_10 , V_7 ) ;
goto exit;
}
V_7 = F_1 ( V_2 , V_70 ,
& V_55 . V_71 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_11 , V_7 ) ;
goto exit;
}
V_7 = F_1 ( V_2 , V_72 ,
& V_55 . V_73 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_12 , V_7 ) ;
goto exit;
}
V_55 . V_74 =
( V_55 . V_65 * ( V_55 . V_61 - 1 ) ) / 10 ;
V_55 . V_75 =
( V_55 . V_67 * ( V_55 . V_63 - 1 ) ) / 10 ;
V_55 . V_76 =
( V_55 . V_69 << 2 ) * ( V_55 . V_61 - 1 ) ;
V_55 . V_77 =
( V_55 . V_69 << 2 ) * ( V_55 . V_63 - 1 ) ;
F_23 ( V_78 , V_10 -> V_79 ) ;
F_24 ( V_10 , V_39 , 1 , V_55 . V_76 , 0 , 0 ) ;
F_24 ( V_10 , V_40 , 1 , V_55 . V_77 , 0 , 0 ) ;
if ( V_55 . V_74 && V_55 . V_75 ) {
V_56 = ( V_55 . V_76 - 1 ) / V_55 . V_74 ;
V_57 = ( V_55 . V_77 - 1 ) / V_55 . V_75 ;
F_25 ( V_10 , V_39 , V_56 ) ;
F_25 ( V_10 , V_40 , V_57 ) ;
}
F_24 ( V_10 , V_41 , 0 , 64 , 0 , 0 ) ;
F_26 ( V_10 , V_36 , V_80 ) ;
F_23 ( V_81 , V_10 -> V_79 ) ;
if ( ( V_55 . V_71 & 0x0F ) == ( V_55 . V_71 & 0xF0 ) >> 4 ) {
V_55 . V_82 = ( V_55 . V_71 & 0x0F ) ;
} else {
V_55 . V_82 = 1 ;
F_23 ( V_83 , V_10 -> V_84 ) ;
}
for ( V_8 = 0 ; V_8 < V_55 . V_82 ; V_8 ++ )
F_23 ( V_42 + V_8 , V_10 -> V_85 ) ;
if ( V_55 . V_73 & V_86 ) {
V_46 = F_27 () ;
if ( ! V_46 ) {
V_7 = - V_14 ;
goto exit;
}
V_25 -> V_46 = V_46 ;
V_55 . V_58 |= V_51 ;
V_7 = F_1 ( V_2 , V_49 ,
NULL , V_55 . V_58 , false ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_13 , V_7 ) ;
F_28 ( V_46 ) ;
goto exit;
}
V_7 = F_1 ( V_2 , V_87 ,
& V_55 . V_88 , 0 , true ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_21 , L_14 , V_7 ) ;
F_28 ( V_46 ) ;
goto exit;
}
V_46 -> V_89 = V_10 -> V_89 ;
V_46 -> V_90 = L_15 ;
V_46 -> V_91 . V_92 = V_93 ;
V_46 -> V_91 . V_94 = V_10 -> V_91 . V_94 ;
V_46 -> V_91 . V_95 = V_10 -> V_91 . V_95 ;
V_46 -> V_91 . V_96 = V_10 -> V_91 . V_96 ;
V_46 -> V_21 . V_97 = V_10 -> V_21 . V_97 ;
F_23 ( V_81 , V_46 -> V_79 ) ;
V_55 . V_98 = ( V_55 . V_88 & 0x0F ) ;
for ( V_8 = 0 ; V_8 < V_55 . V_98 ; V_8 ++ )
F_23 ( V_42 + V_8 , V_46 -> V_85 ) ;
F_23 ( V_99 , V_46 -> V_79 ) ;
F_23 ( V_47 , V_46 -> V_100 ) ;
F_23 ( V_48 , V_46 -> V_100 ) ;
F_23 ( V_101 , V_46 -> V_84 ) ;
F_23 ( V_102 , V_46 -> V_84 ) ;
V_7 = F_29 ( V_25 -> V_46 ) ;
if ( V_7 ) {
F_28 ( V_46 ) ;
goto exit;
}
}
exit:
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
return V_7 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_52 * V_53 , struct V_103 * V_104 ,
struct V_105 * V_106 , unsigned long * * V_107 , int * V_108 )
{
return - 1 ;
}
static int F_33 ( struct V_1 * V_2 , const struct V_109 * V_91 )
{
struct V_32 * V_25 = NULL ;
int V_7 ;
V_25 = F_34 ( & V_2 -> V_21 , sizeof( struct V_32 ) , V_13 ) ;
if ( ! V_25 )
return - V_14 ;
V_25 -> V_2 = V_2 ;
F_35 ( V_2 , V_25 ) ;
V_2 -> V_110 |= V_111 ;
V_7 = F_36 ( V_2 ) ;
if ( V_7 ) {
F_37 ( V_2 , L_16 ) ;
return V_7 ;
}
V_7 = F_38 ( V_2 , V_112 ) ;
if ( V_7 ) {
F_37 ( V_2 , L_17 ) ;
return V_7 ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
}
