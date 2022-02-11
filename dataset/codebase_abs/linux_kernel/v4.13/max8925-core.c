static inline struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
return & V_5 [ V_4 - V_3 -> V_6 ] ;
}
static T_1 F_2 ( int V_4 , void * V_7 )
{
struct V_2 * V_3 = V_7 ;
struct V_1 * V_8 ;
struct V_9 * V_10 ;
int V_11 = - 1 , V_12 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_3 ( V_5 ) ; V_13 ++ ) {
V_8 = & V_5 [ V_13 ] ;
if ( V_8 -> V_14 )
continue;
if ( V_8 -> V_15 == V_16 )
V_10 = V_3 -> V_17 ;
else if ( V_8 -> V_15 == V_18 )
V_10 = V_3 -> V_19 ;
else
V_10 = V_3 -> V_10 ;
if ( V_11 != V_8 -> V_20 ) {
V_11 = V_8 -> V_20 ;
V_12 = F_4 ( V_10 , V_8 -> V_20 ) ;
}
if ( V_12 & V_8 -> V_21 )
F_5 ( V_3 -> V_6 + V_13 ) ;
}
return V_22 ;
}
static T_1 F_6 ( int V_4 , void * V_7 )
{
struct V_2 * V_3 = V_7 ;
struct V_1 * V_8 ;
struct V_9 * V_10 ;
int V_11 = - 1 , V_12 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_3 ( V_5 ) ; V_13 ++ ) {
V_8 = & V_5 [ V_13 ] ;
if ( ! V_8 -> V_14 )
continue;
if ( V_8 -> V_15 == V_16 )
V_10 = V_3 -> V_17 ;
else if ( V_8 -> V_15 == V_18 )
V_10 = V_3 -> V_19 ;
else
V_10 = V_3 -> V_10 ;
if ( V_11 != V_8 -> V_20 ) {
V_11 = V_8 -> V_20 ;
V_12 = F_4 ( V_10 , V_8 -> V_20 ) ;
}
if ( V_12 & V_8 -> V_21 )
F_5 ( V_3 -> V_6 + V_13 ) ;
}
return V_22 ;
}
static void F_7 ( struct V_8 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
F_9 ( & V_3 -> V_23 ) ;
}
static void F_10 ( struct V_8 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_1 * V_8 ;
static unsigned char V_24 [ 2 ] = { 0xff , 0xff } ;
static unsigned char V_25 [ 2 ] = { 0xff , 0xff } ;
static unsigned char V_26 = 0xff , V_27 = 0xff ;
unsigned char V_28 [ 2 ] , V_29 [ 2 ] ;
unsigned char V_30 , V_31 ;
int V_13 ;
V_28 [ 0 ] = V_24 [ 0 ] ;
V_28 [ 1 ] = V_24 [ 1 ] ;
V_29 [ 0 ] = V_25 [ 0 ] ;
V_29 [ 1 ] = V_25 [ 1 ] ;
V_30 = V_26 ;
V_31 = V_27 ;
for ( V_13 = 0 ; V_13 < F_3 ( V_5 ) ; V_13 ++ ) {
V_8 = & V_5 [ V_13 ] ;
switch ( V_8 -> V_32 ) {
case V_33 :
V_28 [ 0 ] &= ~ V_8 -> V_21 ;
break;
case V_34 :
V_28 [ 1 ] &= ~ V_8 -> V_21 ;
break;
case V_35 :
V_29 [ 0 ] &= ~ V_8 -> V_21 ;
break;
case V_36 :
V_29 [ 1 ] &= ~ V_8 -> V_21 ;
break;
case V_37 :
V_30 &= ~ V_8 -> V_21 ;
break;
case V_38 :
V_31 &= ~ V_8 -> V_21 ;
break;
default:
F_11 ( V_3 -> V_39 , L_1 ) ;
break;
}
}
if ( V_24 [ 0 ] != V_28 [ 0 ] ) {
V_24 [ 0 ] = V_28 [ 0 ] ;
F_12 ( V_3 -> V_10 , V_33 ,
V_28 [ 0 ] ) ;
}
if ( V_24 [ 1 ] != V_28 [ 1 ] ) {
V_24 [ 1 ] = V_28 [ 1 ] ;
F_12 ( V_3 -> V_10 , V_34 ,
V_28 [ 1 ] ) ;
}
if ( V_25 [ 0 ] != V_29 [ 0 ] ) {
V_25 [ 0 ] = V_29 [ 0 ] ;
F_12 ( V_3 -> V_10 , V_35 ,
V_29 [ 0 ] ) ;
}
if ( V_25 [ 1 ] != V_29 [ 1 ] ) {
V_25 [ 1 ] = V_29 [ 1 ] ;
F_12 ( V_3 -> V_10 , V_36 ,
V_29 [ 1 ] ) ;
}
if ( V_26 != V_30 ) {
V_26 = V_30 ;
F_12 ( V_3 -> V_17 , V_37 , V_30 ) ;
}
if ( V_27 != V_31 ) {
V_27 = V_31 ;
F_12 ( V_3 -> V_19 , V_38 , V_31 ) ;
}
F_13 ( & V_3 -> V_23 ) ;
}
static void F_14 ( struct V_8 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
V_5 [ V_7 -> V_4 - V_3 -> V_6 ] . V_21
= V_5 [ V_7 -> V_4 - V_3 -> V_6 ] . V_40 ;
}
static void F_15 ( struct V_8 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
V_5 [ V_7 -> V_4 - V_3 -> V_6 ] . V_21 = 0 ;
}
static int F_16 ( struct V_41 * V_42 , unsigned int V_43 ,
T_2 V_44 )
{
F_17 ( V_43 , V_42 -> V_45 ) ;
F_18 ( V_43 , & V_46 , V_47 ) ;
F_19 ( V_43 , 1 ) ;
F_20 ( V_43 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , int V_4 ,
struct V_48 * V_49 )
{
unsigned long V_15 = V_50 | V_51 ;
int V_52 ;
struct V_53 * V_54 = V_3 -> V_39 -> V_55 ;
F_4 ( V_3 -> V_10 , V_56 ) ;
F_4 ( V_3 -> V_10 , V_57 ) ;
F_4 ( V_3 -> V_10 , V_58 ) ;
F_4 ( V_3 -> V_10 , V_59 ) ;
F_4 ( V_3 -> V_17 , V_60 ) ;
F_4 ( V_3 -> V_19 , V_61 ) ;
F_12 ( V_3 -> V_17 , V_62 , 0 ) ;
F_12 ( V_3 -> V_17 , V_63 , 0 ) ;
F_12 ( V_3 -> V_10 , V_33 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_34 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_35 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_36 , 0xff ) ;
F_12 ( V_3 -> V_17 , V_37 , 0xff ) ;
F_22 ( & V_3 -> V_23 ) ;
V_3 -> V_6 = F_23 ( - 1 , 0 , V_64 , 0 ) ;
if ( V_3 -> V_6 < 0 ) {
F_11 ( V_3 -> V_39 , L_2 ,
V_3 -> V_6 ) ;
return - V_65 ;
}
F_24 ( V_54 , V_64 , V_3 -> V_6 , 0 ,
& V_66 , V_3 ) ;
V_3 -> V_67 = V_4 ;
if ( ! V_3 -> V_67 )
return - V_65 ;
V_52 = F_25 ( V_4 , NULL , F_2 , V_15 | V_51 ,
L_3 , V_3 ) ;
if ( V_52 ) {
F_11 ( V_3 -> V_39 , L_4 , V_52 ) ;
V_3 -> V_67 = 0 ;
return - V_65 ;
}
F_12 ( V_3 -> V_19 , V_38 , 0x0f ) ;
if ( ! V_49 -> V_14 ) {
F_26 ( V_3 -> V_39 , L_5 ) ;
return 0 ;
}
V_3 -> V_14 = V_49 -> V_14 ;
V_52 = F_25 ( V_3 -> V_14 , NULL , F_6 ,
V_15 | V_51 , L_6 , V_3 ) ;
if ( V_52 ) {
F_11 ( V_3 -> V_39 , L_7 , V_52 ) ;
V_3 -> V_14 = 0 ;
}
return 0 ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_48 * V_49 )
{
int V_52 ;
if ( ! V_49 )
return;
if ( V_49 -> V_68 ) {
V_69 [ 0 ] . V_70 = V_49 -> V_68 ;
V_69 [ 0 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_73 ) {
V_69 [ 1 ] . V_70 = V_49 -> V_73 ;
V_69 [ 1 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_74 ) {
V_69 [ 2 ] . V_70 = V_49 -> V_74 ;
V_69 [ 2 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_75 ) {
V_69 [ 3 ] . V_70 = V_49 -> V_75 ;
V_69 [ 3 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_76 ) {
V_69 [ 4 ] . V_70 = V_49 -> V_76 ;
V_69 [ 4 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_77 ) {
V_69 [ 5 ] . V_70 = V_49 -> V_77 ;
V_69 [ 5 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_78 ) {
V_69 [ 6 ] . V_70 = V_49 -> V_78 ;
V_69 [ 6 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_79 ) {
V_69 [ 7 ] . V_70 = V_49 -> V_79 ;
V_69 [ 7 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_80 ) {
V_69 [ 8 ] . V_70 = V_49 -> V_80 ;
V_69 [ 8 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_81 ) {
V_69 [ 9 ] . V_70 = V_49 -> V_81 ;
V_69 [ 9 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_82 ) {
V_69 [ 10 ] . V_70 = V_49 -> V_82 ;
V_69 [ 10 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_83 ) {
V_69 [ 11 ] . V_70 = V_49 -> V_83 ;
V_69 [ 11 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_84 ) {
V_69 [ 12 ] . V_70 = V_49 -> V_84 ;
V_69 [ 12 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_85 ) {
V_69 [ 13 ] . V_70 = V_49 -> V_85 ;
V_69 [ 13 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_86 ) {
V_69 [ 14 ] . V_70 = V_49 -> V_86 ;
V_69 [ 14 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_87 ) {
V_69 [ 15 ] . V_70 = V_49 -> V_87 ;
V_69 [ 15 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_88 ) {
V_69 [ 16 ] . V_70 = V_49 -> V_88 ;
V_69 [ 16 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_89 ) {
V_69 [ 17 ] . V_70 = V_49 -> V_89 ;
V_69 [ 17 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_90 ) {
V_69 [ 18 ] . V_70 = V_49 -> V_90 ;
V_69 [ 18 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_91 ) {
V_69 [ 19 ] . V_70 = V_49 -> V_91 ;
V_69 [ 19 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_92 ) {
V_69 [ 20 ] . V_70 = V_49 -> V_92 ;
V_69 [ 20 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_93 ) {
V_69 [ 21 ] . V_70 = V_49 -> V_93 ;
V_69 [ 21 ] . V_71 = sizeof( struct V_72 ) ;
}
if ( V_49 -> V_94 ) {
V_69 [ 22 ] . V_70 = V_49 -> V_94 ;
V_69 [ 22 ] . V_71 = sizeof( struct V_72 ) ;
}
V_52 = F_28 ( V_3 -> V_39 , 0 , V_69 , F_3 ( V_69 ) ,
NULL , 0 , NULL ) ;
if ( V_52 < 0 ) {
F_11 ( V_3 -> V_39 , L_8 ) ;
return;
}
}
int F_29 ( struct V_2 * V_3 ,
struct V_48 * V_49 )
{
int V_52 ;
F_21 ( V_3 , V_3 -> V_10 -> V_4 , V_49 ) ;
if ( V_49 && ( V_49 -> V_95 || V_49 -> V_96 ) ) {
F_30 ( V_3 -> V_10 , V_97 , 1 , 1 ) ;
F_30 ( V_3 -> V_19 , V_98 , 3 , 2 ) ;
do {
V_52 = F_4 ( V_3 -> V_19 , V_61 ) ;
} while ( V_52 & V_99 );
F_30 ( V_3 -> V_19 , V_100 , 3 , 2 ) ;
}
F_30 ( V_3 -> V_17 , V_101 , 1 << 4 , 1 << 4 ) ;
V_52 = F_28 ( V_3 -> V_39 , 0 , & V_102 [ 0 ] ,
F_3 ( V_102 ) ,
NULL , V_3 -> V_6 , NULL ) ;
if ( V_52 < 0 ) {
F_11 ( V_3 -> V_39 , L_9 ) ;
goto V_103;
}
V_52 = F_28 ( V_3 -> V_39 , 0 , & V_104 [ 0 ] ,
F_3 ( V_104 ) ,
NULL , V_3 -> V_6 , NULL ) ;
if ( V_52 < 0 ) {
F_11 ( V_3 -> V_39 , L_10 ) ;
goto V_105;
}
F_27 ( V_3 , V_49 ) ;
if ( V_49 && V_49 -> V_106 ) {
V_107 [ 0 ] . V_70 = & V_49 -> V_106 ;
V_107 [ 0 ] . V_71 = sizeof( struct V_108 ) ;
}
V_52 = F_28 ( V_3 -> V_39 , 0 , V_107 , F_3 ( V_107 ) ,
NULL , 0 , NULL ) ;
if ( V_52 < 0 ) {
F_11 ( V_3 -> V_39 , L_11 ) ;
goto V_105;
}
V_52 = F_28 ( V_3 -> V_39 , 0 , & V_109 [ 0 ] ,
F_3 ( V_109 ) ,
NULL , 0 , NULL ) ;
if ( V_52 < 0 ) {
F_11 ( V_3 -> V_39 ,
L_12 , V_52 ) ;
goto V_105;
}
if ( V_49 && V_49 -> V_96 ) {
V_52 = F_28 ( V_3 -> V_39 , 0 , & V_110 [ 0 ] ,
F_3 ( V_110 ) ,
NULL , V_3 -> V_14 , NULL ) ;
if ( V_52 < 0 ) {
F_11 ( V_3 -> V_39 , L_13 ) ;
goto V_105;
}
}
return 0 ;
V_105:
F_31 ( V_3 -> V_39 ) ;
V_103:
return V_52 ;
}
void F_32 ( struct V_2 * V_3 )
{
if ( V_3 -> V_67 )
F_33 ( V_3 -> V_67 , V_3 ) ;
if ( V_3 -> V_14 )
F_33 ( V_3 -> V_14 , V_3 ) ;
F_31 ( V_3 -> V_39 ) ;
}
