static int F_1 ( void )
{
#if F_2 ( V_1 ) && F_2 ( V_2 )
struct V_3 * V_4 = V_5 -> V_6 . V_3 ;
return V_4 ? V_4 -> V_7 . V_8 : - 1 ;
#else
return - 1 ;
#endif
}
static void F_3 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 )
{
struct V_14 V_15 = {
. V_15 = V_16 ,
} ;
if ( ! V_12 -> V_4 ) {
F_4 ( L_1 ,
V_17 , ( int ) ( V_12 - & V_10 -> V_12 [ 0 ] ) ) ;
return;
}
F_4 ( L_2 , V_17 , V_12 -> V_4 -> V_7 . V_8 ,
V_13 ) ;
if ( V_13 != V_18 )
return;
F_5 ( V_12 -> V_4 , & V_15 ) ;
}
static void F_6 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 )
{
if ( ! V_12 -> V_4 ) {
F_4 ( L_1 ,
V_17 , ( int ) ( V_12 - & V_10 -> V_12 [ 0 ] ) ) ;
return;
}
F_4 ( L_2 , V_17 , V_12 -> V_4 -> V_7 . V_8 ,
V_13 ) ;
if ( V_13 != V_18 )
return;
F_7 ( V_12 -> V_4 ) ;
}
static inline void F_8 ( struct V_19 * V_20 , int V_21 )
{
F_9 ( V_21 , V_20 -> V_22 ) ;
}
static inline void F_10 ( struct V_19 * V_20 , int V_21 )
{
F_11 ( V_21 , V_20 -> V_22 ) ;
}
static inline int F_12 ( struct V_19 * V_20 , int V_21 )
{
return F_13 ( V_21 , V_20 -> V_22 ) ;
}
static void F_14 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
int V_15 = - 1 ;
int V_23 = - 1 ;
int V_24 = - 1 ;
for (; ; ) {
V_15 = F_15 ( V_20 -> V_22 , V_10 -> V_25 , V_15 + 1 ) ;
if ( V_15 == V_10 -> V_25 )
break;
F_4 ( L_3 ,
V_15 , F_16 ( V_10 -> V_26 [ V_15 ] . V_27 ) , V_24 ) ;
if ( F_16 ( V_10 -> V_26 [ V_15 ] . V_27 ) > V_24 ) {
V_23 = V_15 ;
V_24 = F_16 ( V_10 -> V_26 [ V_15 ] . V_27 ) ;
}
}
V_20 -> V_23 = V_23 ;
V_20 -> V_24 = V_24 ;
}
static int F_17 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
F_14 ( V_10 , V_20 ) ;
return V_20 -> V_23 ;
}
static void F_18 ( struct V_9 * V_10 , int V_28 , int V_21 ,
bool V_29 , bool V_30 )
{
struct V_11 * V_12 ;
struct V_31 * V_26 ;
int V_24 ;
V_12 = & V_10 -> V_12 [ V_28 ] ;
V_26 = & V_10 -> V_26 [ V_21 ] ;
F_4 ( L_4 ,
V_17 , V_21 , V_29 , V_30 ) ;
if ( V_26 -> V_13 != V_18 ) {
F_4 ( L_5 ,
V_17 , V_26 -> V_13 , V_21 , V_29 , V_30 ,
V_12 -> V_32 [ V_26 -> V_13 ] ) ;
if ( V_29 ) {
if ( ! V_30 &&
V_12 -> V_32 [ V_26 -> V_13 ] ++ == 0 ) {
F_4 ( L_6 ,
V_17 , V_26 -> V_13 , V_28 , V_21 ) ;
F_3 ( V_10 , V_12 , V_26 -> V_13 ) ;
}
} else {
if ( V_30 &&
-- V_12 -> V_32 [ V_26 -> V_13 ] == 0 ) {
F_4 ( L_7 ,
V_17 , V_26 -> V_13 , V_28 , V_21 ) ;
F_6 ( V_10 , V_12 , V_26 -> V_13 ) ;
}
}
return;
}
V_24 = F_16 ( V_26 -> V_27 ) ;
if ( V_29 )
F_8 ( & V_12 -> V_33 , V_21 ) ;
else
F_10 ( & V_12 -> V_33 , V_21 ) ;
F_14 ( V_10 , & V_12 -> V_33 ) ;
if ( V_29 && V_24 <= V_12 -> V_34 ) {
F_4 ( L_8 ,
V_17 , V_21 , V_24 , V_12 -> V_34 , V_28 ) ;
V_29 = 0 ;
}
if ( V_29 ) {
if ( F_17 ( V_10 , & V_12 -> V_35 ) >= 0 &&
V_24 <= V_12 -> V_35 . V_24 ) {
F_4 ( L_9 ,
V_17 , V_21 , V_12 -> V_35 . V_23 , V_28 ) ;
} else {
F_4 ( L_10 ,
V_17 , V_28 , V_21 , V_12 -> V_33 . V_23 ) ;
F_3 ( V_10 , V_12 , V_18 ) ;
}
} else {
F_17 ( V_10 , & V_12 -> V_35 ) ;
if ( V_12 -> V_33 . V_24 > V_12 -> V_34 &&
V_12 -> V_33 . V_24 > V_12 -> V_35 . V_24 ) {
F_4 ( L_11 ,
V_17 , V_21 , V_12 -> V_33 . V_23 ,
V_12 -> V_33 . V_24 , V_12 -> V_34 ,
V_12 -> V_35 . V_24 , V_28 ) ;
} else {
F_4 ( L_12 ,
V_17 , V_21 , V_12 -> V_34 ,
V_12 -> V_35 . V_24 , V_28 ) ;
F_6 ( V_10 , V_12 , V_18 ) ;
}
}
}
static void F_19 ( struct V_9 * V_10 , int V_21 )
{
struct V_31 * V_26 ;
bool V_29 , V_30 ;
int V_36 ;
V_26 = & V_10 -> V_26 [ V_21 ] ;
V_29 = V_26 -> V_37 ;
if ( ( V_26 -> V_27 & V_38 ) && ! V_26 -> V_39 ) {
F_4 ( L_13 , V_17 , V_21 ) ;
V_29 = false ;
}
V_30 = ! ! ( V_26 -> V_27 & V_40 ) ;
if ( ! V_29 && ! V_30 ) {
F_4 ( L_14 , V_17 , V_21 ) ;
return;
}
if ( V_29 )
V_26 -> V_27 |= V_40 ;
else
V_26 -> V_27 &= ~ V_40 ;
if ( V_26 -> V_41 == 0 ) {
F_4 ( L_15 , V_17 , V_21 ) ;
return;
}
if ( V_26 -> V_41 == ( 1 << V_26 -> V_42 ) ) {
F_18 ( V_10 , V_26 -> V_42 , V_21 , V_29 , V_30 ) ;
} else if ( ! ( V_26 -> V_27 & V_43 ) ) {
for ( V_36 = 0 ; V_36 < V_10 -> V_44 ; V_36 ++ ) {
if ( V_26 -> V_41 & ( 1 << V_36 ) ) {
F_18 ( V_10 , V_36 , V_21 , V_29 ,
V_30 ) ;
}
}
} else {
for ( V_36 = V_26 -> V_42 + 1 ; V_36 != V_26 -> V_42 ; V_36 ++ ) {
if ( V_36 == V_10 -> V_44 )
V_36 = 0 ;
if ( V_26 -> V_41 & ( 1 << V_36 ) ) {
F_18 ( V_10 , V_36 , V_21 , V_29 ,
V_30 ) ;
V_26 -> V_42 = V_36 ;
break;
}
}
}
}
static void F_20 ( void * V_45 , int V_21 , int V_46 )
{
struct V_9 * V_10 = V_45 ;
struct V_31 * V_26 ;
if ( V_21 >= V_47 ) {
F_21 ( 1 , L_16 , V_17 , V_21 ) ;
return;
}
V_26 = & V_10 -> V_26 [ V_21 ] ;
F_4 ( L_17 ,
V_21 , V_46 , V_26 -> V_27 ) ;
if ( V_26 -> V_46 ) {
V_26 -> V_37 = V_46 ;
F_19 ( V_10 , V_21 ) ;
} else {
if ( V_46 ) {
V_26 -> V_37 = 1 ;
F_19 ( V_10 , V_21 ) ;
}
if ( V_26 -> V_13 != V_18 ) {
V_26 -> V_37 = 0 ;
F_19 ( V_10 , V_21 ) ;
}
}
}
static void F_22 ( struct V_9 * V_10 )
{
int V_36 ;
V_10 -> V_48 = V_49 ;
V_10 -> V_50 = ( ( V_10 -> V_51 - 1 ) << V_52 ) |
( V_10 -> V_53 << V_54 ) ;
V_10 -> V_55 = 0 ;
V_10 -> V_56 = - 1 & V_10 -> V_57 ;
V_10 -> V_58 = V_10 -> V_59 ;
for ( V_36 = 0 ; V_36 < V_10 -> V_25 ; V_36 ++ ) {
V_10 -> V_26 [ V_36 ] . V_27 = V_10 -> V_60 ;
V_10 -> V_26 [ V_36 ] . V_61 = V_10 -> V_62 ;
switch ( V_10 -> V_26 [ V_36 ] . type ) {
case V_63 :
V_10 -> V_26 [ V_36 ] . V_46 =
! ! ( V_10 -> V_60 & V_64 ) ;
break;
case V_65 :
V_10 -> V_26 [ V_36 ] . V_27 |= V_66 ;
break;
case V_67 :
break;
}
}
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
V_10 -> V_12 [ V_36 ] . V_34 = 15 ;
memset ( & V_10 -> V_12 [ V_36 ] . V_33 , 0 , sizeof( struct V_19 ) ) ;
V_10 -> V_12 [ V_36 ] . V_33 . V_23 = - 1 ;
memset ( & V_10 -> V_12 [ V_36 ] . V_35 , 0 , sizeof( struct V_19 ) ) ;
V_10 -> V_12 [ V_36 ] . V_35 . V_23 = - 1 ;
}
for ( V_36 = 0 ; V_36 < V_69 ; V_36 ++ ) {
V_10 -> V_70 [ V_36 ] . V_71 = 0 ;
V_10 -> V_70 [ V_36 ] . V_72 = V_73 ;
}
V_10 -> V_48 = 0 ;
}
static inline T_1 F_23 ( struct V_9 * V_10 , int V_21 )
{
return V_10 -> V_26 [ V_21 ] . V_61 ;
}
static inline T_1 F_24 ( struct V_9 * V_10 , int V_21 )
{
if ( V_10 -> V_74 & V_75 )
return V_10 -> V_26 [ V_21 ] . V_13 ;
return 0xffffffff ;
}
static inline T_1 F_25 ( struct V_9 * V_10 , int V_21 )
{
return V_10 -> V_26 [ V_21 ] . V_27 ;
}
static inline void F_26 ( struct V_9 * V_10 , int V_21 ,
T_1 V_76 )
{
struct V_31 * V_26 = & V_10 -> V_26 [ V_21 ] ;
T_1 V_77 = ( 1UL << V_10 -> V_44 ) - 1 ;
T_1 V_78 = 0 ;
T_1 V_79 = V_77 ;
int V_80 = V_81 - V_10 -> V_44 ;
int V_36 ;
if ( V_10 -> V_74 & V_82 ) {
V_78 = V_79 << V_80 ;
V_79 |= V_78 | V_83 ;
}
V_26 -> V_61 = V_76 & V_79 ;
F_4 ( L_18 , V_21 , V_26 -> V_61 ) ;
if ( V_10 -> V_74 & V_82 ) {
if ( V_26 -> V_61 & V_78 ) {
if ( V_26 -> V_61 & V_77 ) {
F_4 ( L_19 ,
V_17 ) ;
}
V_26 -> V_13 = V_84 ;
V_26 -> V_39 = true ;
V_26 -> V_41 = 0 ;
for ( V_36 = 0 ; V_36 < V_10 -> V_44 ; V_36 ++ ) {
int V_85 = V_86 - V_36 ;
if ( V_26 -> V_61 & ( 1UL << V_85 ) )
V_26 -> V_41 |= 1UL << V_36 ;
}
} else {
V_26 -> V_13 = V_18 ;
V_26 -> V_39 = false ;
V_26 -> V_41 = V_26 -> V_61 & V_77 ;
}
} else {
V_26 -> V_41 = V_26 -> V_61 ;
}
}
static inline void F_27 ( struct V_9 * V_10 , int V_21 ,
T_1 V_76 )
{
if ( V_10 -> V_74 & V_75 ) {
struct V_31 * V_26 = & V_10 -> V_26 [ V_21 ] ;
V_26 -> V_13 = V_76 & V_87 ;
F_4 ( L_20 , V_21 , V_26 -> V_61 ,
V_26 -> V_13 ) ;
}
}
static inline void F_28 ( struct V_9 * V_10 , int V_21 ,
T_1 V_76 )
{
T_1 V_79 ;
V_79 = V_38 | V_88 | V_64 |
V_66 | V_10 -> V_57 ;
V_10 -> V_26 [ V_21 ] . V_27 =
( V_10 -> V_26 [ V_21 ] . V_27 & V_40 ) | ( V_76 & V_79 ) ;
switch ( V_10 -> V_26 [ V_21 ] . type ) {
case V_63 :
V_10 -> V_26 [ V_21 ] . V_46 =
! ! ( V_10 -> V_26 [ V_21 ] . V_27 & V_64 ) ;
break;
case V_65 :
V_10 -> V_26 [ V_21 ] . V_27 &= ~ V_64 ;
break;
case V_67 :
V_10 -> V_26 [ V_21 ] . V_27 &= ~ ( V_66 | V_64 ) ;
break;
}
F_19 ( V_10 , V_21 ) ;
F_4 ( L_21 , V_21 , V_76 ,
V_10 -> V_26 [ V_21 ] . V_27 ) ;
}
static void F_29 ( struct V_9 * V_10 , T_2 V_76 )
{
if ( V_76 & V_49 ) {
F_22 ( V_10 ) ;
return;
}
V_10 -> V_48 &= ~ V_10 -> V_89 ;
V_10 -> V_48 |= V_76 & V_10 -> V_89 ;
}
static int F_30 ( void * V_45 , T_3 V_90 , T_4 V_76 )
{
struct V_9 * V_10 = V_45 ;
int V_91 = 0 ;
F_4 ( L_22 , V_17 , V_90 , V_76 ) ;
if ( V_90 & 0xF )
return 0 ;
switch ( V_90 ) {
case 0x00 :
break;
case 0x40 :
case 0x50 :
case 0x60 :
case 0x70 :
case 0x80 :
case 0x90 :
case 0xA0 :
case 0xB0 :
V_91 = F_31 ( V_10 , V_90 , V_76 ,
F_1 () ) ;
break;
case 0x1000 :
break;
case 0x1020 :
F_29 ( V_10 , V_76 ) ;
break;
case 0x1080 :
break;
case 0x1090 :
V_91 = - V_92 ;
break;
case 0x10A0 :
case 0x10B0 :
case 0x10C0 :
case 0x10D0 : {
int V_93 ;
V_93 = ( V_90 - 0x10A0 ) >> 4 ;
F_28 ( V_10 , V_10 -> V_94 + V_93 , V_76 ) ;
break;
}
case 0x10E0 :
V_10 -> V_56 = V_76 & V_10 -> V_57 ;
break;
default:
break;
}
return V_91 ;
}
static int F_32 ( void * V_45 , T_3 V_90 , T_4 * V_95 )
{
struct V_9 * V_10 = V_45 ;
T_4 V_96 ;
int V_91 = 0 ;
F_4 ( L_23 , V_17 , V_90 ) ;
V_96 = 0xFFFFFFFF ;
if ( V_90 & 0xF )
goto V_97;
switch ( V_90 ) {
case 0x1000 :
V_96 = V_10 -> V_50 ;
V_96 |= ( V_10 -> V_44 - 1 ) << V_98 ;
break;
case 0x1020 :
V_96 = V_10 -> V_48 ;
break;
case 0x1080 :
V_96 = V_10 -> V_99 ;
break;
case 0x1090 :
V_96 = 0x00000000 ;
break;
case 0x00 :
V_96 = V_10 -> V_100 ;
break;
case 0x40 :
case 0x50 :
case 0x60 :
case 0x70 :
case 0x80 :
case 0x90 :
case 0xA0 :
case 0xB0 :
V_91 = F_33 ( V_10 , V_90 ,
& V_96 , F_1 () ) ;
break;
case 0x10A0 :
case 0x10B0 :
case 0x10C0 :
case 0x10D0 :
{
int V_93 ;
V_93 = ( V_90 - 0x10A0 ) >> 4 ;
V_96 = F_25 ( V_10 , V_10 -> V_94 + V_93 ) ;
}
break;
case 0x10E0 :
V_96 = V_10 -> V_56 ;
break;
default:
break;
}
V_97:
F_4 ( L_24 , V_17 , V_96 ) ;
* V_95 = V_96 ;
return V_91 ;
}
static int F_34 ( void * V_45 , T_3 V_90 , T_4 V_76 )
{
struct V_9 * V_10 = V_45 ;
int V_93 ;
V_90 += 0x10f0 ;
F_4 ( L_22 , V_17 , V_90 , V_76 ) ;
if ( V_90 & 0xF )
return 0 ;
if ( V_90 == 0x10f0 ) {
V_10 -> V_58 = V_76 ;
return 0 ;
}
V_93 = ( V_90 >> 6 ) & 0x3 ;
V_90 = V_90 & 0x30 ;
switch ( V_90 & 0x30 ) {
case 0x00 :
break;
case 0x10 :
if ( ( V_10 -> V_70 [ V_93 ] . V_71 & V_101 ) != 0 &&
( V_76 & V_73 ) == 0 &&
( V_10 -> V_70 [ V_93 ] . V_72 & V_73 ) != 0 )
V_10 -> V_70 [ V_93 ] . V_71 &= ~ V_101 ;
V_10 -> V_70 [ V_93 ] . V_72 = V_76 ;
break;
case 0x20 :
F_28 ( V_10 , V_10 -> V_102 + V_93 , V_76 ) ;
break;
case 0x30 :
F_26 ( V_10 , V_10 -> V_102 + V_93 , V_76 ) ;
break;
}
return 0 ;
}
static int F_35 ( void * V_45 , T_3 V_90 , T_4 * V_95 )
{
struct V_9 * V_10 = V_45 ;
T_1 V_96 = - 1 ;
int V_93 ;
F_4 ( L_23 , V_17 , V_90 ) ;
if ( V_90 & 0xF )
goto V_97;
V_93 = ( V_90 >> 6 ) & 0x3 ;
if ( V_90 == 0x0 ) {
V_96 = V_10 -> V_58 ;
goto V_97;
}
switch ( V_90 & 0x30 ) {
case 0x00 :
V_96 = V_10 -> V_70 [ V_93 ] . V_71 ;
break;
case 0x10 :
V_96 = V_10 -> V_70 [ V_93 ] . V_72 ;
break;
case 0x20 :
V_96 = F_25 ( V_10 , V_10 -> V_102 + V_93 ) ;
break;
case 0x30 :
V_96 = F_23 ( V_10 , V_10 -> V_102 + V_93 ) ;
break;
}
V_97:
F_4 ( L_24 , V_17 , V_96 ) ;
* V_95 = V_96 ;
return 0 ;
}
static int F_36 ( void * V_45 , T_3 V_90 , T_4 V_76 )
{
struct V_9 * V_10 = V_45 ;
int V_93 ;
F_4 ( L_22 , V_17 , V_90 , V_76 ) ;
V_90 = V_90 & 0xffff ;
V_93 = V_90 >> 5 ;
switch ( V_90 & 0x1f ) {
case 0x00 :
F_28 ( V_10 , V_93 , V_76 ) ;
break;
case 0x10 :
F_26 ( V_10 , V_93 , V_76 ) ;
break;
case 0x18 :
F_27 ( V_10 , V_93 , V_76 ) ;
break;
}
return 0 ;
}
static int F_37 ( void * V_45 , T_3 V_90 , T_4 * V_95 )
{
struct V_9 * V_10 = V_45 ;
T_1 V_96 ;
int V_93 ;
F_4 ( L_23 , V_17 , V_90 ) ;
V_96 = 0xFFFFFFFF ;
V_90 = V_90 & 0xffff ;
V_93 = V_90 >> 5 ;
switch ( V_90 & 0x1f ) {
case 0x00 :
V_96 = F_25 ( V_10 , V_93 ) ;
break;
case 0x10 :
V_96 = F_23 ( V_10 , V_93 ) ;
break;
case 0x18 :
V_96 = F_24 ( V_10 , V_93 ) ;
break;
}
F_4 ( L_24 , V_17 , V_96 ) ;
* V_95 = V_96 ;
return 0 ;
}
static int F_38 ( void * V_45 , T_3 V_90 , T_4 V_76 )
{
struct V_9 * V_10 = V_45 ;
int V_93 = V_10 -> V_103 ;
int V_104 , V_105 ;
F_4 ( L_25 , V_17 , V_90 , V_76 ) ;
if ( V_90 & 0xF )
return 0 ;
switch ( V_90 ) {
case V_106 :
V_104 = V_76 >> V_107 ;
V_93 += V_104 ;
V_105 = ( V_76 & V_108 ) >> V_109 ;
V_10 -> V_110 [ V_104 ] . V_111 |= 1 << V_105 ;
F_20 ( V_10 , V_93 , 1 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_39 ( void * V_45 , T_3 V_90 , T_4 * V_95 )
{
struct V_9 * V_10 = V_45 ;
T_1 V_112 = 0 ;
int V_36 , V_104 ;
F_4 ( L_23 , V_17 , V_90 ) ;
if ( V_90 & 0xF )
return - V_92 ;
V_104 = V_90 >> 4 ;
switch ( V_90 ) {
case 0x00 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x50 :
case 0x60 :
case 0x70 :
V_112 = V_10 -> V_110 [ V_104 ] . V_111 ;
V_10 -> V_110 [ V_104 ] . V_111 = 0 ;
F_20 ( V_10 , V_10 -> V_103 + V_104 , 0 ) ;
break;
case 0x120 :
for ( V_36 = 0 ; V_36 < V_113 ; V_36 ++ )
V_112 |= ( V_10 -> V_110 [ V_36 ] . V_111 ? 1 : 0 ) << V_36 ;
break;
}
F_4 ( L_24 , V_17 , V_112 ) ;
* V_95 = V_112 ;
return 0 ;
}
static int F_40 ( void * V_45 , T_3 V_90 , T_4 * V_95 )
{
T_1 V_112 = 0 ;
F_4 ( L_23 , V_17 , V_90 ) ;
* V_95 = V_112 ;
return 0 ;
}
static int F_41 ( void * V_45 , T_3 V_90 , T_4 V_76 )
{
F_4 ( L_25 , V_17 , V_90 , V_76 ) ;
return 0 ;
}
static int F_31 ( void * V_45 , T_3 V_90 ,
T_4 V_76 , int V_93 )
{
struct V_9 * V_10 = V_45 ;
struct V_31 * V_26 ;
struct V_11 * V_12 ;
int V_114 , V_21 ;
F_4 ( L_26 , V_17 , V_93 ,
V_90 , V_76 ) ;
if ( V_93 < 0 )
return 0 ;
if ( V_90 & 0xF )
return 0 ;
V_12 = & V_10 -> V_12 [ V_93 ] ;
V_90 &= 0xFF0 ;
switch ( V_90 ) {
case 0x40 :
case 0x50 :
case 0x60 :
case 0x70 :
V_93 = ( V_90 - 0x40 ) >> 4 ;
V_10 -> V_26 [ V_10 -> V_94 + V_93 ] . V_41 |= V_76 ;
F_20 ( V_10 , V_10 -> V_94 + V_93 , 1 ) ;
F_20 ( V_10 , V_10 -> V_94 + V_93 , 0 ) ;
break;
case 0x80 :
V_12 -> V_34 = V_76 & 0x0000000F ;
F_4 ( L_27 ,
V_17 , V_93 , V_12 -> V_34 , V_12 -> V_33 . V_24 ,
V_12 -> V_35 . V_24 ) ;
if ( V_12 -> V_33 . V_24 <= V_12 -> V_34 ) {
F_4 ( L_28 ,
V_17 , V_93 ) ;
F_6 ( V_10 , V_12 , V_18 ) ;
} else if ( V_12 -> V_33 . V_24 > V_12 -> V_35 . V_24 ) {
F_4 ( L_29 ,
V_17 , V_93 , V_12 -> V_33 . V_23 ) ;
F_3 ( V_10 , V_12 , V_18 ) ;
}
break;
case 0x90 :
break;
case 0xA0 :
break;
case 0xB0 : {
int V_115 ;
F_4 ( L_30 ) ;
V_114 = F_17 ( V_10 , & V_12 -> V_35 ) ;
if ( V_114 < 0 ) {
F_4 ( L_31 ,
V_17 ) ;
break;
}
F_10 ( & V_12 -> V_35 , V_114 ) ;
V_115 = V_114 ;
V_114 = F_17 ( V_10 , & V_12 -> V_35 ) ;
V_21 = F_17 ( V_10 , & V_12 -> V_33 ) ;
V_26 = & V_10 -> V_26 [ V_21 ] ;
if ( V_21 != - 1 &&
( V_114 == - 1 ||
F_16 ( V_26 -> V_27 ) > V_12 -> V_35 . V_24 ) ) {
F_4 ( L_32 ,
V_93 , V_21 ) ;
F_3 ( V_10 , V_12 , V_18 ) ;
}
F_42 ( & V_10 -> V_116 ) ;
F_43 ( V_10 -> V_117 , 0 , V_115 ) ;
F_44 ( & V_10 -> V_116 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_45 ( void * V_45 , T_3 V_90 , T_4 V_76 )
{
struct V_9 * V_10 = V_45 ;
return F_31 ( V_10 , V_90 , V_76 ,
( V_90 & 0x1f000 ) >> 12 ) ;
}
static T_1 F_46 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_118 )
{
struct V_31 * V_26 ;
int V_96 , V_15 ;
F_4 ( L_33 ) ;
F_6 ( V_10 , V_12 , V_18 ) ;
V_15 = F_17 ( V_10 , & V_12 -> V_33 ) ;
F_4 ( L_34 , V_15 ) ;
if ( V_15 == - 1 )
return V_10 -> V_56 ;
V_26 = & V_10 -> V_26 [ V_15 ] ;
if ( ! ( V_26 -> V_27 & V_40 ) ||
! ( F_16 ( V_26 -> V_27 ) > V_12 -> V_34 ) ) {
F_47 ( L_35 ,
V_17 , V_15 , V_12 -> V_34 , V_26 -> V_27 ) ;
F_19 ( V_10 , V_15 ) ;
V_96 = V_10 -> V_56 ;
} else {
F_8 ( & V_12 -> V_35 , V_15 ) ;
V_96 = F_48 ( V_10 , V_26 -> V_27 ) ;
}
if ( ! V_26 -> V_46 ) {
V_26 -> V_27 &= ~ V_40 ;
V_26 -> V_37 = 0 ;
F_10 ( & V_12 -> V_33 , V_15 ) ;
}
if ( ( V_15 >= V_10 -> V_94 ) && ( V_15 < ( V_10 -> V_94 + V_119 ) ) ) {
V_26 -> V_41 &= ~ ( 1 << V_118 ) ;
if ( V_26 -> V_41 && ! V_26 -> V_46 ) {
F_20 ( V_10 , V_15 , 1 ) ;
F_20 ( V_10 , V_15 , 0 ) ;
V_26 -> V_27 |= V_40 ;
}
}
return V_96 ;
}
void F_49 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_7 . V_120 ;
int V_118 = V_4 -> V_7 . V_8 ;
unsigned long V_74 ;
F_50 ( & V_10 -> V_116 , V_74 ) ;
if ( ( V_10 -> V_48 & V_10 -> V_89 ) == V_121 )
F_51 ( V_4 , F_46 ( V_10 , & V_10 -> V_12 [ V_118 ] , V_118 ) ) ;
F_52 ( & V_10 -> V_116 , V_74 ) ;
}
static int F_33 ( void * V_45 , T_3 V_90 ,
T_4 * V_95 , int V_93 )
{
struct V_9 * V_10 = V_45 ;
struct V_11 * V_12 ;
T_1 V_96 ;
F_4 ( L_36 , V_17 , V_93 , V_90 ) ;
V_96 = 0xFFFFFFFF ;
if ( V_93 < 0 )
goto V_97;
if ( V_90 & 0xF )
goto V_97;
V_12 = & V_10 -> V_12 [ V_93 ] ;
V_90 &= 0xFF0 ;
switch ( V_90 ) {
case 0x80 :
V_96 = V_12 -> V_34 ;
break;
case 0x90 :
V_96 = V_93 ;
break;
case 0xA0 :
V_96 = F_46 ( V_10 , V_12 , V_93 ) ;
break;
case 0xB0 :
V_96 = 0 ;
break;
default:
break;
}
F_4 ( L_24 , V_17 , V_96 ) ;
V_97:
* V_95 = V_96 ;
return 0 ;
}
static int F_53 ( void * V_45 , T_3 V_90 , T_4 * V_95 )
{
struct V_9 * V_10 = V_45 ;
return F_33 ( V_10 , V_90 , V_95 ,
( V_90 & 0x1f000 ) >> 12 ) ;
}
static void F_54 ( struct V_9 * V_10 , const struct V_122 * V_123 )
{
if ( V_10 -> V_124 >= V_125 ) {
F_55 ( 1 , L_37 ) ;
return;
}
V_10 -> V_126 [ V_10 -> V_124 ++ ] = V_123 ;
}
static void F_56 ( struct V_9 * V_10 )
{
int V_36 ;
int V_127 = V_128 ;
F_54 ( V_10 , & V_129 ) ;
F_54 ( V_10 , & V_130 ) ;
V_10 -> V_53 = V_131 ;
V_10 -> V_99 = V_132 ;
V_10 -> V_57 = 0xFFFF ;
V_10 -> V_59 = 0 ;
V_10 -> V_60 = V_38 ;
V_10 -> V_62 = 1 << 0 ;
V_10 -> V_25 = V_47 ;
V_10 -> V_94 = V_127 ;
V_127 += V_119 ;
V_10 -> V_102 = V_127 ;
V_127 += V_69 ;
F_57 ( V_127 > V_47 ) ;
V_10 -> V_103 = 224 ;
for ( V_36 = 0 ; V_36 < V_10 -> V_133 -> V_134 ; V_36 ++ )
V_10 -> V_26 [ V_36 ] . V_46 = false ;
for ( V_36 = 16 ; V_36 < V_128 ; V_36 ++ ) {
V_10 -> V_26 [ V_36 ] . type = V_65 ;
V_10 -> V_26 [ V_36 ] . V_46 = true ;
}
for ( V_36 = V_128 ; V_36 < V_127 ; V_36 ++ ) {
V_10 -> V_26 [ V_36 ] . type = V_67 ;
V_10 -> V_26 [ V_36 ] . V_46 = false ;
}
}
static int F_58 ( struct V_9 * V_10 , T_3 V_90 , T_4 * V_95 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_10 -> V_124 ; V_36 ++ ) {
const struct V_122 * V_123 = V_10 -> V_126 [ V_36 ] ;
if ( V_123 -> V_135 > V_90 || V_90 >= V_123 -> V_135 + V_123 -> V_136 )
continue;
return V_123 -> V_137 ( V_10 , V_90 - V_123 -> V_135 , V_95 ) ;
}
return - V_92 ;
}
static int F_59 ( struct V_9 * V_10 , T_3 V_90 , T_4 V_76 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_10 -> V_124 ; V_36 ++ ) {
const struct V_122 * V_123 = V_10 -> V_126 [ V_36 ] ;
if ( V_123 -> V_135 > V_90 || V_90 >= V_123 -> V_135 + V_123 -> V_136 )
continue;
return V_123 -> V_138 ( V_10 , V_90 - V_123 -> V_135 , V_76 ) ;
}
return - V_92 ;
}
static int F_60 ( struct V_139 * V_140 , T_3 V_90 ,
int V_141 , void * V_95 )
{
struct V_9 * V_10 = F_61 ( V_140 , struct V_9 , V_142 ) ;
int V_143 ;
union {
T_4 V_76 ;
T_5 V_144 [ 4 ] ;
} V_145 ;
if ( V_90 & ( V_141 - 1 ) ) {
F_4 ( L_38 ,
V_17 , V_90 , V_141 ) ;
return - V_146 ;
}
F_62 ( & V_10 -> V_116 ) ;
V_143 = F_58 ( V_10 , V_90 - V_10 -> V_147 , & V_145 . V_76 ) ;
F_63 ( & V_10 -> V_116 ) ;
if ( V_141 == 4 ) {
* ( T_4 * ) V_95 = V_145 . V_76 ;
F_4 ( L_39 ,
V_17 , V_90 , V_143 , V_145 . V_76 ) ;
} else if ( V_141 == 1 ) {
* ( T_5 * ) V_95 = V_145 . V_144 [ V_90 & 3 ] ;
F_4 ( L_40 ,
V_17 , V_90 , V_143 , V_145 . V_144 [ V_90 & 3 ] ) ;
} else {
F_4 ( L_41 , V_17 , V_141 ) ;
return - V_146 ;
}
return V_143 ;
}
static int F_64 ( struct V_139 * V_140 , T_3 V_90 ,
int V_141 , const void * V_95 )
{
struct V_9 * V_10 = F_61 ( V_140 , struct V_9 , V_142 ) ;
int V_143 ;
if ( V_141 != 4 ) {
F_4 ( L_41 , V_17 , V_141 ) ;
return - V_148 ;
}
if ( V_90 & 3 ) {
F_4 ( L_38 , V_17 , V_90 , V_141 ) ;
return - V_148 ;
}
F_62 ( & V_10 -> V_116 ) ;
V_143 = F_59 ( V_10 , V_90 - V_10 -> V_147 ,
* ( const T_4 * ) V_95 ) ;
F_63 ( & V_10 -> V_116 ) ;
F_4 ( L_42 ,
V_17 , V_90 , V_143 , * ( const T_4 * ) V_95 ) ;
return V_143 ;
}
static void F_65 ( struct V_9 * V_10 )
{
F_66 ( & V_10 -> V_142 , & V_149 ) ;
F_67 ( V_10 -> V_117 , V_150 ,
V_10 -> V_147 , V_151 ,
& V_10 -> V_142 ) ;
}
static void F_68 ( struct V_9 * V_10 )
{
F_69 ( V_10 -> V_117 , V_150 , & V_10 -> V_142 ) ;
}
static int F_70 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
T_6 V_154 ;
if ( F_71 ( & V_154 , ( T_6 V_155 * ) ( long ) V_153 -> V_90 , sizeof( T_6 ) ) )
return - V_156 ;
if ( V_154 & 0x3ffff ) {
F_4 ( L_43 ,
V_17 , V_154 ) ;
return - V_146 ;
}
if ( V_154 == V_10 -> V_147 )
return 0 ;
F_72 ( & V_10 -> V_117 -> V_157 ) ;
F_68 ( V_10 ) ;
V_10 -> V_147 = V_154 ;
F_4 ( L_44 ,
V_17 , V_154 ) ;
if ( V_154 == 0 )
goto V_97;
F_65 ( V_10 ) ;
V_97:
F_73 ( & V_10 -> V_117 -> V_157 ) ;
return 0 ;
}
static int F_74 ( struct V_9 * V_10 , T_3 V_90 , T_4 * V_76 , int type )
{
int V_143 ;
if ( V_90 & 3 )
return - V_92 ;
F_62 ( & V_10 -> V_116 ) ;
if ( type == V_158 )
V_143 = F_59 ( V_10 , V_90 , * V_76 ) ;
else
V_143 = F_58 ( V_10 , V_90 , V_76 ) ;
F_63 ( & V_10 -> V_116 ) ;
F_4 ( L_45 , V_17 , type , V_90 , * V_76 ) ;
return V_143 ;
}
static int F_75 ( struct V_159 * V_160 , struct V_152 * V_153 )
{
struct V_9 * V_10 = V_160 -> V_161 ;
T_4 V_162 ;
switch ( V_153 -> V_163 ) {
case V_164 :
switch ( V_153 -> V_153 ) {
case V_165 :
return F_70 ( V_10 , V_153 ) ;
}
break;
case V_166 :
if ( F_76 ( V_162 , ( T_4 V_155 * ) ( long ) V_153 -> V_90 ) )
return - V_156 ;
return F_74 ( V_10 , V_153 -> V_153 , & V_162 , V_158 ) ;
case V_167 :
if ( V_153 -> V_153 > V_128 )
return - V_146 ;
if ( F_76 ( V_162 , ( T_4 V_155 * ) ( long ) V_153 -> V_90 ) )
return - V_156 ;
if ( V_162 != 0 && V_162 != 1 )
return - V_146 ;
F_62 ( & V_10 -> V_116 ) ;
F_20 ( V_10 , V_153 -> V_153 , V_162 ) ;
F_63 ( & V_10 -> V_116 ) ;
return 0 ;
}
return - V_92 ;
}
static int F_77 ( struct V_159 * V_160 , struct V_152 * V_153 )
{
struct V_9 * V_10 = V_160 -> V_161 ;
T_6 V_168 ;
T_4 V_162 ;
int V_143 ;
switch ( V_153 -> V_163 ) {
case V_164 :
switch ( V_153 -> V_153 ) {
case V_165 :
F_72 ( & V_10 -> V_117 -> V_157 ) ;
V_168 = V_10 -> V_147 ;
F_73 ( & V_10 -> V_117 -> V_157 ) ;
if ( F_78 ( ( T_6 V_155 * ) ( long ) V_153 -> V_90 ,
& V_168 , sizeof( T_6 ) ) )
return - V_156 ;
return 0 ;
}
break;
case V_166 :
V_143 = F_74 ( V_10 , V_153 -> V_153 , & V_162 , V_169 ) ;
if ( V_143 )
return V_143 ;
if ( F_79 ( V_162 , ( T_4 V_155 * ) ( long ) V_153 -> V_90 ) )
return - V_156 ;
return 0 ;
case V_167 :
if ( V_153 -> V_153 > V_128 )
return - V_146 ;
F_62 ( & V_10 -> V_116 ) ;
V_162 = V_10 -> V_26 [ V_153 -> V_153 ] . V_37 ;
F_63 ( & V_10 -> V_116 ) ;
if ( F_79 ( V_162 , ( T_4 V_155 * ) ( long ) V_153 -> V_90 ) )
return - V_156 ;
return 0 ;
}
return - V_92 ;
}
static int F_80 ( struct V_159 * V_160 , struct V_152 * V_153 )
{
switch ( V_153 -> V_163 ) {
case V_164 :
switch ( V_153 -> V_153 ) {
case V_165 :
return 0 ;
}
break;
case V_166 :
return 0 ;
case V_167 :
if ( V_153 -> V_153 > V_128 )
break;
return 0 ;
}
return - V_92 ;
}
static void F_81 ( struct V_159 * V_160 )
{
struct V_9 * V_10 = V_160 -> V_161 ;
V_160 -> V_117 -> V_7 . V_120 = NULL ;
F_82 ( V_10 ) ;
F_82 ( V_160 ) ;
}
static int F_83 ( struct V_9 * V_10 )
{
struct V_170 * V_171 ;
V_171 = F_84 ( ( sizeof( * V_171 ) ) , V_172 ) ;
if ( ! V_171 )
return - V_173 ;
F_85 ( V_10 -> V_117 , V_171 , 0 , 0 ) ;
F_82 ( V_171 ) ;
return 0 ;
}
static int F_86 ( struct V_159 * V_160 , T_4 type )
{
struct V_9 * V_10 ;
int V_143 ;
if ( V_160 -> V_117 -> V_7 . V_120 )
return - V_146 ;
V_10 = F_84 ( sizeof( struct V_9 ) , V_172 ) ;
if ( ! V_10 )
return - V_173 ;
V_160 -> V_161 = V_10 ;
V_10 -> V_117 = V_160 -> V_117 ;
V_10 -> V_160 = V_160 ;
V_10 -> V_174 = type ;
F_87 ( & V_10 -> V_116 ) ;
F_54 ( V_10 , & V_175 ) ;
F_54 ( V_10 , & V_176 ) ;
F_54 ( V_10 , & V_177 ) ;
F_54 ( V_10 , & V_178 ) ;
switch ( V_10 -> V_174 ) {
case V_179 :
V_10 -> V_133 = & V_180 ;
V_10 -> V_100 = 0x00400200 ;
V_10 -> V_74 |= V_82 ;
V_10 -> V_51 = 80 ;
V_10 -> V_89 = V_181 ;
F_56 ( V_10 ) ;
break;
case V_182 :
V_10 -> V_133 = & V_183 ;
V_10 -> V_100 = 0x00400402 ;
V_10 -> V_74 |= V_75 ;
V_10 -> V_51 = 196 ;
V_10 -> V_89 = V_121 ;
F_56 ( V_10 ) ;
break;
default:
V_143 = - V_184 ;
goto V_91;
}
V_143 = F_83 ( V_10 ) ;
if ( V_143 )
goto V_91;
F_22 ( V_10 ) ;
F_88 () ;
V_160 -> V_117 -> V_7 . V_120 = V_10 ;
return 0 ;
V_91:
F_82 ( V_10 ) ;
return V_143 ;
}
int F_89 ( struct V_159 * V_160 , struct V_3 * V_4 ,
T_4 V_118 )
{
struct V_9 * V_10 = V_160 -> V_161 ;
int V_143 = 0 ;
if ( V_160 -> V_185 != & V_186 )
return - V_187 ;
if ( V_10 -> V_117 != V_4 -> V_117 )
return - V_187 ;
if ( V_118 < 0 || V_118 >= V_68 )
return - V_187 ;
F_62 ( & V_10 -> V_116 ) ;
if ( V_10 -> V_12 [ V_118 ] . V_4 ) {
V_143 = - V_188 ;
goto V_97;
}
if ( V_4 -> V_7 . V_189 ) {
V_143 = - V_190 ;
goto V_97;
}
V_10 -> V_12 [ V_118 ] . V_4 = V_4 ;
V_10 -> V_44 = F_90 ( V_10 -> V_44 , V_118 + 1 ) ;
V_4 -> V_7 . V_120 = V_10 ;
V_4 -> V_7 . V_8 = V_118 ;
V_4 -> V_7 . V_189 = V_191 ;
if ( V_10 -> V_89 == V_121 )
V_4 -> V_7 . V_192 |= V_193 ;
V_97:
F_63 ( & V_10 -> V_116 ) ;
return V_143 ;
}
void F_91 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
F_57 ( ! V_10 -> V_12 [ V_4 -> V_7 . V_8 ] . V_4 ) ;
V_10 -> V_12 [ V_4 -> V_7 . V_8 ] . V_4 = NULL ;
}
static int F_92 ( struct V_194 * V_195 ,
struct V_117 * V_117 , int V_196 , int V_46 ,
bool V_197 )
{
T_4 V_15 = V_195 -> V_198 . V_199 ;
struct V_9 * V_10 = V_117 -> V_7 . V_120 ;
unsigned long V_74 ;
F_50 ( & V_10 -> V_116 , V_74 ) ;
F_20 ( V_10 , V_15 , V_46 ) ;
F_52 ( & V_10 -> V_116 , V_74 ) ;
return 0 ;
}
int F_93 ( struct V_194 * V_195 ,
struct V_117 * V_117 , int V_196 , int V_46 , bool V_197 )
{
struct V_9 * V_10 = V_117 -> V_7 . V_120 ;
unsigned long V_74 ;
F_50 ( & V_10 -> V_116 , V_74 ) ;
F_38 ( V_117 -> V_7 . V_120 , V_106 , V_195 -> V_110 . V_200 ) ;
F_52 ( & V_10 -> V_116 , V_74 ) ;
return 0 ;
}
int F_94 ( struct V_201 * V_202 ,
struct V_194 * V_195 ,
const struct V_170 * V_203 )
{
int V_112 = - V_146 ;
switch ( V_203 -> type ) {
case V_204 :
V_195 -> V_205 = F_92 ;
V_195 -> V_198 . V_198 = V_203 -> V_145 . V_198 . V_198 ;
V_195 -> V_198 . V_199 = V_203 -> V_145 . V_198 . V_199 ;
if ( V_195 -> V_198 . V_199 >= V_206 )
goto V_97;
V_202 -> V_207 [ V_203 -> V_145 . V_198 . V_198 ] [ V_195 -> V_198 . V_199 ] = V_203 -> V_208 ;
break;
case V_209 :
V_195 -> V_205 = F_93 ;
V_195 -> V_110 . V_210 = V_203 -> V_145 . V_110 . V_210 ;
V_195 -> V_110 . V_211 = V_203 -> V_145 . V_110 . V_211 ;
V_195 -> V_110 . V_200 = V_203 -> V_145 . V_110 . V_200 ;
break;
default:
goto V_97;
}
V_112 = 0 ;
V_97:
return V_112 ;
}
