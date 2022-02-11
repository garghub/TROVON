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
#ifdef F_20
F_21 ( V_43 , V_48 ) ;
#else
F_22 ( V_43 ) ;
#endif
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , int V_4 ,
struct V_49 * V_50 )
{
unsigned long V_15 = V_51 | V_52 ;
int V_53 ;
struct V_54 * V_55 = V_3 -> V_39 -> V_56 ;
F_4 ( V_3 -> V_10 , V_57 ) ;
F_4 ( V_3 -> V_10 , V_58 ) ;
F_4 ( V_3 -> V_10 , V_59 ) ;
F_4 ( V_3 -> V_10 , V_60 ) ;
F_4 ( V_3 -> V_17 , V_61 ) ;
F_4 ( V_3 -> V_19 , V_62 ) ;
F_12 ( V_3 -> V_17 , V_63 , 0 ) ;
F_12 ( V_3 -> V_17 , V_64 , 0 ) ;
F_12 ( V_3 -> V_10 , V_33 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_34 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_35 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_36 , 0xff ) ;
F_12 ( V_3 -> V_17 , V_37 , 0xff ) ;
F_24 ( & V_3 -> V_23 ) ;
V_3 -> V_6 = F_25 ( - 1 , 0 , V_65 , 0 ) ;
if ( V_3 -> V_6 < 0 ) {
F_11 ( V_3 -> V_39 , L_2 ,
V_3 -> V_6 ) ;
return - V_66 ;
}
F_26 ( V_55 , V_65 , V_3 -> V_6 , 0 ,
& V_67 , V_3 ) ;
V_3 -> V_68 = V_4 ;
if ( ! V_3 -> V_68 )
return - V_66 ;
V_53 = F_27 ( V_4 , NULL , F_2 , V_15 | V_52 ,
L_3 , V_3 ) ;
if ( V_53 ) {
F_11 ( V_3 -> V_39 , L_4 , V_53 ) ;
V_3 -> V_68 = 0 ;
return - V_66 ;
}
F_12 ( V_3 -> V_19 , V_38 , 0x0f ) ;
if ( ! V_50 -> V_14 ) {
F_28 ( V_3 -> V_39 , L_5 ) ;
return 0 ;
}
V_3 -> V_14 = V_50 -> V_14 ;
V_53 = F_27 ( V_3 -> V_14 , NULL , F_6 ,
V_15 | V_52 , L_6 , V_3 ) ;
if ( V_53 ) {
F_11 ( V_3 -> V_39 , L_7 , V_53 ) ;
V_3 -> V_14 = 0 ;
}
return 0 ;
}
static void F_29 ( struct V_2 * V_3 ,
struct V_49 * V_50 )
{
int V_53 ;
if ( ! V_50 )
return;
if ( V_50 -> V_69 ) {
V_70 [ 0 ] . V_71 = V_50 -> V_69 ;
V_70 [ 0 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_74 ) {
V_70 [ 1 ] . V_71 = V_50 -> V_74 ;
V_70 [ 1 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_75 ) {
V_70 [ 2 ] . V_71 = V_50 -> V_75 ;
V_70 [ 2 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_76 ) {
V_70 [ 3 ] . V_71 = V_50 -> V_76 ;
V_70 [ 3 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_77 ) {
V_70 [ 4 ] . V_71 = V_50 -> V_77 ;
V_70 [ 4 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_78 ) {
V_70 [ 5 ] . V_71 = V_50 -> V_78 ;
V_70 [ 5 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_79 ) {
V_70 [ 6 ] . V_71 = V_50 -> V_79 ;
V_70 [ 6 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_80 ) {
V_70 [ 7 ] . V_71 = V_50 -> V_80 ;
V_70 [ 7 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_81 ) {
V_70 [ 8 ] . V_71 = V_50 -> V_81 ;
V_70 [ 8 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_82 ) {
V_70 [ 9 ] . V_71 = V_50 -> V_82 ;
V_70 [ 9 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_83 ) {
V_70 [ 10 ] . V_71 = V_50 -> V_83 ;
V_70 [ 10 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_84 ) {
V_70 [ 11 ] . V_71 = V_50 -> V_84 ;
V_70 [ 11 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_85 ) {
V_70 [ 12 ] . V_71 = V_50 -> V_85 ;
V_70 [ 12 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_86 ) {
V_70 [ 13 ] . V_71 = V_50 -> V_86 ;
V_70 [ 13 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_87 ) {
V_70 [ 14 ] . V_71 = V_50 -> V_87 ;
V_70 [ 14 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_88 ) {
V_70 [ 15 ] . V_71 = V_50 -> V_88 ;
V_70 [ 15 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_89 ) {
V_70 [ 16 ] . V_71 = V_50 -> V_89 ;
V_70 [ 16 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_90 ) {
V_70 [ 17 ] . V_71 = V_50 -> V_90 ;
V_70 [ 17 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_91 ) {
V_70 [ 18 ] . V_71 = V_50 -> V_91 ;
V_70 [ 18 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_92 ) {
V_70 [ 19 ] . V_71 = V_50 -> V_92 ;
V_70 [ 19 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_93 ) {
V_70 [ 20 ] . V_71 = V_50 -> V_93 ;
V_70 [ 20 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_94 ) {
V_70 [ 21 ] . V_71 = V_50 -> V_94 ;
V_70 [ 21 ] . V_72 = sizeof( struct V_73 ) ;
}
if ( V_50 -> V_95 ) {
V_70 [ 22 ] . V_71 = V_50 -> V_95 ;
V_70 [ 22 ] . V_72 = sizeof( struct V_73 ) ;
}
V_53 = F_30 ( V_3 -> V_39 , 0 , V_70 , F_3 ( V_70 ) ,
NULL , 0 , NULL ) ;
if ( V_53 < 0 ) {
F_11 ( V_3 -> V_39 , L_8 ) ;
return;
}
}
int F_31 ( struct V_2 * V_3 ,
struct V_49 * V_50 )
{
int V_53 ;
F_23 ( V_3 , V_3 -> V_10 -> V_4 , V_50 ) ;
if ( V_50 && ( V_50 -> V_96 || V_50 -> V_97 ) ) {
F_32 ( V_3 -> V_10 , V_98 , 1 , 1 ) ;
F_32 ( V_3 -> V_19 , V_99 , 3 , 2 ) ;
do {
V_53 = F_4 ( V_3 -> V_19 , V_62 ) ;
} while ( V_53 & V_100 );
F_32 ( V_3 -> V_19 , V_101 , 3 , 2 ) ;
}
F_32 ( V_3 -> V_17 , V_102 , 1 << 4 , 1 << 4 ) ;
V_53 = F_30 ( V_3 -> V_39 , 0 , & V_103 [ 0 ] ,
F_3 ( V_103 ) ,
NULL , V_3 -> V_6 , NULL ) ;
if ( V_53 < 0 ) {
F_11 ( V_3 -> V_39 , L_9 ) ;
goto V_104;
}
V_53 = F_30 ( V_3 -> V_39 , 0 , & V_105 [ 0 ] ,
F_3 ( V_105 ) ,
NULL , V_3 -> V_6 , NULL ) ;
if ( V_53 < 0 ) {
F_11 ( V_3 -> V_39 , L_10 ) ;
goto V_106;
}
F_29 ( V_3 , V_50 ) ;
if ( V_50 && V_50 -> V_107 ) {
V_108 [ 0 ] . V_71 = & V_50 -> V_107 ;
V_108 [ 0 ] . V_72 = sizeof( struct V_109 ) ;
}
V_53 = F_30 ( V_3 -> V_39 , 0 , V_108 , F_3 ( V_108 ) ,
NULL , 0 , NULL ) ;
if ( V_53 < 0 ) {
F_11 ( V_3 -> V_39 , L_11 ) ;
goto V_106;
}
V_53 = F_30 ( V_3 -> V_39 , 0 , & V_110 [ 0 ] ,
F_3 ( V_110 ) ,
NULL , 0 , NULL ) ;
if ( V_53 < 0 ) {
F_11 ( V_3 -> V_39 ,
L_12 , V_53 ) ;
goto V_106;
}
if ( V_50 && V_50 -> V_97 ) {
V_53 = F_30 ( V_3 -> V_39 , 0 , & V_111 [ 0 ] ,
F_3 ( V_111 ) ,
NULL , V_3 -> V_14 , NULL ) ;
if ( V_53 < 0 ) {
F_11 ( V_3 -> V_39 , L_13 ) ;
goto V_106;
}
}
return 0 ;
V_106:
F_33 ( V_3 -> V_39 ) ;
V_104:
return V_53 ;
}
void F_34 ( struct V_2 * V_3 )
{
if ( V_3 -> V_68 )
F_35 ( V_3 -> V_68 , V_3 ) ;
if ( V_3 -> V_14 )
F_35 ( V_3 -> V_14 , V_3 ) ;
F_33 ( V_3 -> V_39 ) ;
}
