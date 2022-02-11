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
static int F_16 ( struct V_2 * V_3 , int V_4 ,
struct V_41 * V_42 )
{
unsigned long V_15 = V_43 | V_44 ;
int V_13 , V_45 ;
int V_46 ;
if ( ! V_42 || ! V_42 -> V_6 ) {
F_17 ( V_3 -> V_39 , L_2 ) ;
return - V_47 ;
}
F_4 ( V_3 -> V_10 , V_48 ) ;
F_4 ( V_3 -> V_10 , V_49 ) ;
F_4 ( V_3 -> V_10 , V_50 ) ;
F_4 ( V_3 -> V_10 , V_51 ) ;
F_4 ( V_3 -> V_17 , V_52 ) ;
F_4 ( V_3 -> V_19 , V_53 ) ;
F_12 ( V_3 -> V_17 , V_54 , 0 ) ;
F_12 ( V_3 -> V_17 , V_55 , 0 ) ;
F_12 ( V_3 -> V_10 , V_33 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_34 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_35 , 0xff ) ;
F_12 ( V_3 -> V_10 , V_36 , 0xff ) ;
F_12 ( V_3 -> V_17 , V_37 , 0xff ) ;
F_18 ( & V_3 -> V_23 ) ;
V_3 -> V_56 = V_4 ;
V_3 -> V_6 = V_42 -> V_6 ;
for ( V_13 = 0 ; V_13 < F_3 ( V_5 ) ; V_13 ++ ) {
V_46 = V_13 + V_3 -> V_6 ;
F_19 ( V_46 , V_3 ) ;
F_20 ( V_46 , & V_57 ,
V_58 ) ;
F_21 ( V_46 , 1 ) ;
#ifdef F_22
F_23 ( V_46 , V_59 ) ;
#else
F_24 ( V_46 ) ;
#endif
}
if ( ! V_4 ) {
F_17 ( V_3 -> V_39 , L_3 ) ;
goto V_14;
}
V_45 = F_25 ( V_4 , NULL , F_2 , V_15 | V_44 ,
L_4 , V_3 ) ;
if ( V_45 ) {
F_11 ( V_3 -> V_39 , L_5 , V_45 ) ;
V_3 -> V_56 = 0 ;
}
V_14:
F_12 ( V_3 -> V_19 , V_38 , 0x0f ) ;
if ( ! V_42 -> V_14 ) {
F_17 ( V_3 -> V_39 , L_6 ) ;
return 0 ;
}
V_3 -> V_14 = V_42 -> V_14 ;
V_45 = F_25 ( V_3 -> V_14 , NULL , F_6 ,
V_15 | V_44 , L_7 , V_3 ) ;
if ( V_45 ) {
F_11 ( V_3 -> V_39 , L_8 , V_45 ) ;
V_3 -> V_14 = 0 ;
}
return 0 ;
}
static void F_26 ( struct V_2 * V_3 ,
struct V_41 * V_42 )
{
int V_45 ;
if ( ! V_42 )
return;
if ( V_42 -> V_60 ) {
V_61 [ 0 ] . V_62 = V_42 -> V_60 ;
V_61 [ 0 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_65 ) {
V_61 [ 1 ] . V_62 = V_42 -> V_65 ;
V_61 [ 1 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_66 ) {
V_61 [ 2 ] . V_62 = V_42 -> V_66 ;
V_61 [ 2 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_67 ) {
V_61 [ 3 ] . V_62 = V_42 -> V_67 ;
V_61 [ 3 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_68 ) {
V_61 [ 4 ] . V_62 = V_42 -> V_68 ;
V_61 [ 4 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_69 ) {
V_61 [ 5 ] . V_62 = V_42 -> V_69 ;
V_61 [ 5 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_70 ) {
V_61 [ 6 ] . V_62 = V_42 -> V_70 ;
V_61 [ 6 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_71 ) {
V_61 [ 7 ] . V_62 = V_42 -> V_71 ;
V_61 [ 7 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_72 ) {
V_61 [ 8 ] . V_62 = V_42 -> V_72 ;
V_61 [ 8 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_73 ) {
V_61 [ 9 ] . V_62 = V_42 -> V_73 ;
V_61 [ 9 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_74 ) {
V_61 [ 10 ] . V_62 = V_42 -> V_74 ;
V_61 [ 10 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_75 ) {
V_61 [ 11 ] . V_62 = V_42 -> V_75 ;
V_61 [ 11 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_76 ) {
V_61 [ 12 ] . V_62 = V_42 -> V_76 ;
V_61 [ 12 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_77 ) {
V_61 [ 13 ] . V_62 = V_42 -> V_77 ;
V_61 [ 13 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_78 ) {
V_61 [ 14 ] . V_62 = V_42 -> V_78 ;
V_61 [ 14 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_79 ) {
V_61 [ 15 ] . V_62 = V_42 -> V_79 ;
V_61 [ 15 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_80 ) {
V_61 [ 16 ] . V_62 = V_42 -> V_80 ;
V_61 [ 16 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_81 ) {
V_61 [ 17 ] . V_62 = V_42 -> V_81 ;
V_61 [ 17 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_82 ) {
V_61 [ 18 ] . V_62 = V_42 -> V_82 ;
V_61 [ 18 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_83 ) {
V_61 [ 19 ] . V_62 = V_42 -> V_83 ;
V_61 [ 19 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_84 ) {
V_61 [ 20 ] . V_62 = V_42 -> V_84 ;
V_61 [ 20 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_85 ) {
V_61 [ 21 ] . V_62 = V_42 -> V_85 ;
V_61 [ 21 ] . V_63 = sizeof( struct V_64 ) ;
}
if ( V_42 -> V_86 ) {
V_61 [ 22 ] . V_62 = V_42 -> V_86 ;
V_61 [ 22 ] . V_63 = sizeof( struct V_64 ) ;
}
V_45 = F_27 ( V_3 -> V_39 , 0 , V_61 , F_3 ( V_61 ) ,
NULL , 0 , NULL ) ;
if ( V_45 < 0 ) {
F_11 ( V_3 -> V_39 , L_9 ) ;
return;
}
}
int F_28 ( struct V_2 * V_3 ,
struct V_41 * V_42 )
{
int V_45 ;
F_16 ( V_3 , V_3 -> V_10 -> V_4 , V_42 ) ;
if ( V_42 && ( V_42 -> V_87 || V_42 -> V_88 ) ) {
F_29 ( V_3 -> V_10 , V_89 , 1 , 1 ) ;
F_29 ( V_3 -> V_19 , V_90 , 3 , 2 ) ;
do {
V_45 = F_4 ( V_3 -> V_19 , V_53 ) ;
} while ( V_45 & V_91 );
F_29 ( V_3 -> V_19 , V_92 , 3 , 2 ) ;
}
F_29 ( V_3 -> V_17 , V_93 , 1 << 4 , 1 << 4 ) ;
V_45 = F_27 ( V_3 -> V_39 , 0 , & V_94 [ 0 ] ,
F_3 ( V_94 ) ,
& V_95 [ 0 ] , V_3 -> V_6 , NULL ) ;
if ( V_45 < 0 ) {
F_11 ( V_3 -> V_39 , L_10 ) ;
goto V_96;
}
V_45 = F_27 ( V_3 -> V_39 , 0 , & V_97 [ 0 ] ,
F_3 ( V_97 ) ,
& V_98 [ 0 ] , 0 , NULL ) ;
if ( V_45 < 0 ) {
F_11 ( V_3 -> V_39 , L_11 ) ;
goto V_99;
}
F_26 ( V_3 , V_42 ) ;
if ( V_42 && V_42 -> V_100 ) {
V_101 [ 0 ] . V_62 = & V_42 -> V_100 ;
V_101 [ 0 ] . V_63 = sizeof( struct V_102 ) ;
}
V_45 = F_27 ( V_3 -> V_39 , 0 , V_101 , F_3 ( V_101 ) ,
NULL , 0 , NULL ) ;
if ( V_45 < 0 ) {
F_11 ( V_3 -> V_39 , L_12 ) ;
goto V_99;
}
if ( V_42 && V_42 -> V_87 ) {
V_45 = F_27 ( V_3 -> V_39 , 0 , & V_103 [ 0 ] ,
F_3 ( V_103 ) ,
& V_104 [ 0 ] , 0 , NULL ) ;
if ( V_45 < 0 ) {
F_11 ( V_3 -> V_39 , L_13
L_14 ) ;
goto V_99;
}
}
if ( V_42 && V_42 -> V_88 ) {
V_45 = F_27 ( V_3 -> V_39 , 0 , & V_105 [ 0 ] ,
F_3 ( V_105 ) ,
& V_106 [ 0 ] , 0 , NULL ) ;
if ( V_45 < 0 ) {
F_11 ( V_3 -> V_39 , L_15 ) ;
goto V_99;
}
}
return 0 ;
V_99:
F_30 ( V_3 -> V_39 ) ;
V_96:
return V_45 ;
}
void F_31 ( struct V_2 * V_3 )
{
if ( V_3 -> V_56 )
F_32 ( V_3 -> V_56 , V_3 ) ;
if ( V_3 -> V_14 )
F_32 ( V_3 -> V_14 , V_3 ) ;
F_30 ( V_3 -> V_39 ) ;
}
