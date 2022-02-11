static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
switch ( V_3 -> V_4 [ 0 ] & 0x3f ) {
case V_5 :
F_3 ( V_3 -> V_6 , & V_3 -> V_7 ) ;
break;
case V_8 :
F_4 ( V_3 -> V_6 , V_9 ,
0 , 0 , 0 , 0 ) ;
break;
case V_10 :
F_4 ( V_3 -> V_6 , V_11 ,
0 , 1 , 0 , 0 ) ;
break;
case V_12 :
case V_13 :
case V_14 :
F_4 ( V_3 -> V_6 , V_15 ,
0 , 0 , 0 , 1 ) ;
break;
}
}
static T_1 F_5 ( struct V_16 * V_16 , unsigned char V_4 ,
unsigned int V_17 )
{
struct V_3 * V_3 = F_6 ( V_16 ) ;
if ( ! V_3 -> V_18 && V_4 != V_19 )
return V_20 ;
if ( V_4 == V_21 ) {
V_3 -> V_22 = true ;
return V_20 ;
}
if ( V_3 -> V_22 ) {
V_4 += V_23 ;
V_3 -> V_22 = false ;
} else if ( V_4 == V_24 ) {
struct V_25 * V_26 = & V_3 -> V_7 ;
if ( V_27 )
F_7 ( V_3 -> V_28 , L_1 ,
V_3 -> V_29 , V_3 -> V_30 ) ;
V_3 -> V_4 [ 0 ] = V_3 -> V_30 [ 0 ] ;
switch ( V_3 -> V_30 [ 0 ] & 0x3f ) {
case V_31 :
V_26 -> V_32 = 1 ;
V_26 -> V_26 [ 0 ] = V_3 -> V_30 [ 1 ] ;
break;
case V_5 :
if ( V_26 -> V_32 == V_33 )
break;
V_26 -> V_26 [ V_26 -> V_32 ++ ] = V_3 -> V_30 [ 1 ] ;
if ( V_3 -> V_30 [ 0 ] & V_34 )
F_8 ( & V_3 -> V_2 ) ;
break;
case V_8 :
case V_12 :
case V_10 :
case V_13 :
case V_14 :
F_8 ( & V_3 -> V_2 ) ;
break;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
break;
case V_39 :
case V_40 :
default:
if ( V_3 -> V_29 == 0 )
break;
memcpy ( V_3 -> V_4 , V_3 -> V_30 , V_3 -> V_29 ) ;
V_3 -> V_32 = V_3 -> V_29 ;
F_9 ( & V_3 -> V_41 ) ;
break;
}
V_3 -> V_29 = 0 ;
V_3 -> V_18 = false ;
return V_20 ;
} else if ( V_4 == V_19 ) {
V_3 -> V_29 = 0 ;
V_3 -> V_18 = true ;
return V_20 ;
}
if ( V_3 -> V_29 >= V_42 ) {
F_10 ( V_3 -> V_28 ,
L_2 , V_3 -> V_29 ) ;
V_3 -> V_29 = 0 ;
}
V_3 -> V_30 [ V_3 -> V_29 ++ ] = V_4 ;
return V_20 ;
}
static void F_11 ( struct V_16 * V_16 )
{
struct V_3 * V_3 = F_6 ( V_16 ) ;
F_12 ( V_3 -> V_6 ) ;
F_7 ( & V_16 -> V_28 , L_3 ) ;
F_13 ( V_16 ) ;
F_14 ( V_16 , NULL ) ;
F_15 ( V_3 ) ;
}
static int F_16 ( struct V_16 * V_16 , const T_2 * V_43 , T_2 V_44 )
{
int V_45 = 0 ;
V_45 = F_17 ( V_16 , V_19 ) ;
if ( V_45 )
return V_45 ;
for (; ! V_45 && V_44 ; V_43 ++ , V_44 -- ) {
if ( * V_43 >= V_21 ) {
V_45 = F_17 ( V_16 , V_21 ) ;
if ( ! V_45 )
V_45 = F_17 ( V_16 , * V_43 - V_23 ) ;
} else {
V_45 = F_17 ( V_16 , * V_43 ) ;
}
}
if ( ! V_45 )
V_45 = F_17 ( V_16 , 0xfe ) ;
return V_45 ;
}
static int F_18 ( struct V_3 * V_3 ,
const T_2 * V_46 , T_2 V_44 , T_2 V_47 , T_2 V_48 )
{
int V_45 ;
F_19 ( & V_3 -> V_41 ) ;
V_45 = F_16 ( V_3 -> V_16 , V_46 , V_44 ) ;
if ( V_45 )
return V_45 ;
if ( ! F_20 ( & V_3 -> V_41 , V_49 ) )
return - V_50 ;
if ( ( V_3 -> V_4 [ 0 ] & 0x3f ) == V_40 &&
V_46 [ 0 ] != V_51 &&
V_46 [ 0 ] != V_52 &&
V_46 [ 0 ] != V_53 ) {
T_2 V_54 [ 2 ] ;
V_54 [ 0 ] = V_51 ;
V_54 [ 1 ] = 1 ;
V_45 = F_18 ( V_3 , V_54 , 2 ,
V_39 , 1 ) ;
if ( V_45 )
return V_45 ;
F_19 ( & V_3 -> V_41 ) ;
V_45 = F_16 ( V_3 -> V_16 , V_46 , V_44 ) ;
if ( V_45 )
return V_45 ;
if ( ! F_20 ( & V_3 -> V_41 , V_49 ) )
return - V_50 ;
}
if ( V_47 &&
( ( V_3 -> V_4 [ 0 ] & 0x3f ) != V_47 || V_3 -> V_32 < V_48 + 1 ) ) {
F_7 ( V_3 -> V_28 , L_4 ,
V_3 -> V_4 [ 0 ] & 0x3f ) ;
return - V_55 ;
}
return 0 ;
}
static int F_21 ( struct V_3 * V_3 , struct V_16 * V_16 )
{
T_2 * V_4 = V_3 -> V_4 + 1 ;
unsigned int V_56 = 0 ;
unsigned int V_57 = 0 ;
T_2 V_46 [ 2 ] ;
int V_45 ;
V_46 [ 0 ] = V_58 ;
V_45 = F_18 ( V_3 , V_46 , 1 ,
V_39 , 0 ) ;
V_46 [ 0 ] = V_59 ;
if ( ! V_45 )
V_45 = F_18 ( V_3 , V_46 , 1 , V_46 [ 0 ] , 2 ) ;
if ( V_45 )
return V_45 ;
V_57 = ( V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ;
F_7 ( V_3 -> V_28 , L_5 , V_57 ) ;
if ( V_57 < 2 )
return 0 ;
V_46 [ 0 ] = V_53 ;
if ( ! V_45 )
V_45 = F_18 ( V_3 , V_46 , 1 , V_46 [ 0 ] , 4 ) ;
if ( ! V_45 ) {
T_3 V_60 = ( V_4 [ 0 ] << 24 ) | ( V_4 [ 1 ] << 16 ) |
( V_4 [ 2 ] << 8 ) | V_4 [ 3 ] ;
struct V_61 V_61 ;
F_22 ( V_60 , 0 , & V_61 ) ;
F_7 ( V_3 -> V_28 , L_6 ,
V_61 . V_62 + 1900 , V_61 . V_63 + 1 , V_61 . V_64 ,
V_61 . V_65 , V_61 . V_66 , V_61 . V_67 ) ;
}
do {
if ( V_56 )
F_23 ( 500 ) ;
V_46 [ 0 ] = V_52 ;
V_46 [ 1 ] = 0 ;
V_45 = F_18 ( V_3 , V_46 , 2 ,
V_39 , 1 ) ;
if ( V_45 && V_56 == 0 ) {
F_7 ( V_3 -> V_28 , L_7 ) ;
return 0 ;
}
V_46 [ 0 ] = V_68 ;
if ( ! V_45 )
V_45 = F_18 ( V_3 , V_46 , 1 , V_46 [ 0 ] , 1 ) ;
if ( ! V_45 && ! V_4 [ 0 ] ) {
V_46 [ 0 ] = V_69 ;
V_45 = F_18 ( V_3 , V_46 , 1 ,
V_39 , 1 ) ;
V_46 [ 0 ] = V_68 ;
if ( ! V_45 )
V_45 = F_18 ( V_3 , V_46 , 1 ,
V_46 [ 0 ] , 1 ) ;
}
} while ( ! V_45 && V_4 [ 0 ] && V_56 ++ < 5 );
if ( ! V_45 && V_4 [ 0 ] )
V_45 = - V_55 ;
return V_45 ;
}
static int F_24 ( struct V_70 * V_6 , bool V_71 )
{
struct V_3 * V_3 = V_6 -> V_72 ;
T_2 V_46 [ 16 ] ;
int V_45 ;
V_46 [ 0 ] = V_51 ;
V_46 [ 1 ] = V_71 ;
V_45 = F_18 ( V_3 , V_46 , 2 ,
V_39 , 1 ) ;
return V_71 ? V_45 : 0 ;
}
static int F_25 ( struct V_70 * V_6 , T_2 V_73 )
{
struct V_3 * V_3 = V_6 -> V_72 ;
T_4 V_74 = 0 ;
T_2 V_46 [ 3 ] ;
int V_45 ;
if ( V_73 != V_75 )
V_74 = 1 << V_73 ;
V_46 [ 0 ] = V_76 ;
V_46 [ 1 ] = V_74 >> 8 ;
V_46 [ 2 ] = V_74 & 0xff ;
V_45 = F_18 ( V_3 , V_46 , 3 ,
V_39 , 0 ) ;
if ( V_74 == 0 )
return 0 ;
return V_45 ;
}
static int F_26 ( struct V_70 * V_6 , T_2 V_77 ,
T_5 V_78 , struct V_25 * V_26 )
{
struct V_3 * V_3 = V_6 -> V_72 ;
T_2 V_46 [ 2 ] ;
unsigned int V_79 ;
int V_45 ;
V_46 [ 0 ] = V_80 ;
V_46 [ 1 ] = V_78 ;
V_45 = F_18 ( V_3 , V_46 , 2 ,
V_39 , 1 ) ;
V_46 [ 0 ] = V_81 ;
V_46 [ 1 ] = F_27 ( V_26 ) ;
if ( ! V_45 )
V_45 = F_18 ( V_3 , V_46 , 2 ,
V_39 , 1 ) ;
V_46 [ 0 ] = V_26 -> V_32 == 1 ? V_82 : V_83 ;
V_46 [ 1 ] = V_26 -> V_26 [ 0 ] ;
if ( ! V_45 )
V_45 = F_18 ( V_3 , V_46 , 2 ,
V_39 , 1 ) ;
if ( ! V_45 && V_26 -> V_32 > 1 ) {
V_46 [ 0 ] = V_26 -> V_32 == 2 ? V_82 :
V_83 ;
V_46 [ 1 ] = V_26 -> V_26 [ 1 ] ;
V_45 = F_18 ( V_3 , V_46 , 2 ,
V_39 , 1 ) ;
for ( V_79 = 0 ; ! V_45 && V_79 + 2 < V_26 -> V_32 ; V_79 ++ ) {
V_46 [ 0 ] = ( V_79 + 2 == V_26 -> V_32 - 1 ) ?
V_82 : V_83 ;
V_46 [ 1 ] = V_26 -> V_26 [ V_79 + 2 ] ;
V_45 = F_18 ( V_3 , V_46 , 2 ,
V_39 , 1 ) ;
}
}
return V_45 ;
}
static int F_28 ( struct V_70 * V_6 , struct V_25 * V_26 )
{
return - V_84 ;
}
static int F_29 ( struct V_16 * V_16 , struct V_85 * V_86 )
{
T_5 V_87 = V_88 | V_89 | V_90 |
V_91 | V_92 | V_93 ;
struct V_3 * V_3 ;
int V_45 = - V_94 ;
V_3 = F_30 ( sizeof( * V_3 ) , V_95 ) ;
if ( ! V_3 )
return - V_94 ;
V_3 -> V_16 = V_16 ;
V_3 -> V_6 = F_31 ( & V_96 , V_3 ,
L_8 , V_87 , 1 , & V_16 -> V_28 ) ;
V_45 = F_32 ( V_3 -> V_6 ) ;
if ( V_45 < 0 )
goto V_97;
V_3 -> V_28 = & V_16 -> V_28 ;
F_14 ( V_16 , V_3 ) ;
F_33 ( & V_3 -> V_2 , F_1 ) ;
V_45 = F_34 ( V_16 , V_86 ) ;
if ( V_45 )
goto V_98;
V_45 = F_21 ( V_3 , V_16 ) ;
if ( V_45 )
goto V_99;
V_45 = F_35 ( V_3 -> V_6 ) ;
if ( V_45 < 0 )
goto V_99;
V_3 -> V_28 = & V_3 -> V_6 -> V_100 . V_28 ;
return 0 ;
V_99:
F_13 ( V_16 ) ;
V_98:
F_36 ( V_3 -> V_6 ) ;
F_14 ( V_16 , NULL ) ;
V_97:
F_15 ( V_3 ) ;
return V_45 ;
}
