static T_1 F_1 ( T_1 V_1 , T_2 V_2 , T_2 V_3 )
{
union {
T_1 V_4 ;
struct {
T_2 V_5 , V_6 ;
} V_7 ;
} V_8 , V_9 ;
T_1 V_10 , V_11 ;
V_8 . V_4 = V_1 ;
V_10 = ( T_1 ) V_8 . V_7 . V_5 * ( T_1 ) V_2 ;
V_11 = ( T_1 ) V_8 . V_7 . V_6 * ( T_1 ) V_2 ;
V_11 += ( V_10 >> 32 ) ;
V_9 . V_7 . V_6 = F_2 ( V_11 , V_3 ) ;
V_9 . V_7 . V_5 = F_2 ( ( ( F_3 ( V_11 , V_3 ) << 32 ) + ( V_10 & 0xffffffff ) ) , V_3 ) ;
return V_9 . V_4 ;
}
static void F_4 ( struct V_12 * V_12 , int V_13 , T_2 V_14 )
{
struct V_15 * V_3 =
& V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
switch ( V_3 -> V_21 ) {
default:
case 0 :
case 4 :
break;
case 1 :
case 2 :
case 3 :
case 5 :
if ( V_3 -> V_22 < V_14 )
V_3 -> V_23 = F_7 () ;
break;
}
V_3 -> V_22 = V_14 ;
}
static int F_8 ( struct V_12 * V_12 , int V_13 )
{
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
return V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] . V_22 ;
}
static T_3 F_9 ( struct V_12 * V_12 )
{
T_3 V_24 ;
T_4 V_25 ;
struct V_26 * V_27 = & V_12 -> V_16 . V_17 -> V_18 ;
if ( ! V_27 -> V_28 )
return 0 ;
V_25 = F_10 ( & V_27 -> V_29 ) ;
V_24 = V_27 -> V_28 - F_11 ( V_25 ) ;
return V_24 ;
}
static T_3 F_12 ( struct V_12 * V_12 , struct V_15 * V_3 ,
int V_13 )
{
if ( V_13 == 0 )
return F_9 ( V_12 ) ;
return F_11 ( F_13 ( F_7 () , V_3 -> V_23 ) ) ;
}
static int F_14 ( struct V_12 * V_12 , int V_13 )
{
struct V_15 * V_3 =
& V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] ;
T_3 V_30 , V_31 ;
int V_32 ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
V_31 = F_12 ( V_12 , V_3 , V_13 ) ;
V_30 = F_1 ( V_31 , V_33 , V_34 ) ;
switch ( V_3 -> V_21 ) {
case 0 :
case 1 :
case 4 :
case 5 :
V_32 = ( V_3 -> V_35 - V_30 ) & 0xffff ;
break;
case 3 :
V_32 = V_3 -> V_35 - ( F_3 ( ( 2 * V_30 ) , V_3 -> V_35 ) ) ;
break;
default:
V_32 = V_3 -> V_35 - F_3 ( V_30 , V_3 -> V_35 ) ;
break;
}
return V_32 ;
}
static int F_15 ( struct V_12 * V_12 , int V_13 )
{
struct V_15 * V_3 =
& V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] ;
T_3 V_30 , V_31 ;
int V_36 ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
V_31 = F_12 ( V_12 , V_3 , V_13 ) ;
V_30 = F_1 ( V_31 , V_33 , V_34 ) ;
switch ( V_3 -> V_21 ) {
default:
case 0 :
V_36 = ( V_30 >= V_3 -> V_35 ) ;
break;
case 1 :
V_36 = ( V_30 < V_3 -> V_35 ) ;
break;
case 2 :
V_36 = ( ( F_3 ( V_30 , V_3 -> V_35 ) == 0 ) && ( V_30 != 0 ) ) ;
break;
case 3 :
V_36 = ( F_3 ( V_30 , V_3 -> V_35 ) < ( ( V_3 -> V_35 + 1 ) >> 1 ) ) ;
break;
case 4 :
case 5 :
V_36 = ( V_30 == V_3 -> V_35 ) ;
break;
}
return V_36 ;
}
static void F_16 ( struct V_12 * V_12 , int V_13 )
{
struct V_15 * V_3 =
& V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
if ( ! V_3 -> V_37 ) {
V_3 -> V_38 = F_14 ( V_12 , V_13 ) ;
V_3 -> V_37 = V_3 -> V_39 ;
}
}
static void F_17 ( struct V_12 * V_12 , int V_13 )
{
struct V_15 * V_3 =
& V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
if ( ! V_3 -> V_40 ) {
V_3 -> V_41 = ( ( F_15 ( V_12 , V_13 ) << 7 ) |
( V_3 -> V_39 << 4 ) |
( V_3 -> V_21 << 1 ) |
V_3 -> V_42 ) ;
V_3 -> V_40 = 1 ;
}
}
static void F_18 ( struct V_43 * V_44 )
{
struct V_26 * V_27 = F_19 ( V_44 , struct V_26 ,
V_45 ) ;
int V_46 ;
F_20 ( & V_27 -> V_47 ) ;
V_46 = F_21 ( & V_27 -> V_48 ) ;
if ( V_46 < 0 )
F_22 ( & V_27 -> V_48 ) ;
else if ( V_46 > 0 )
F_23 ( & V_27 -> V_49 -> V_50 , & V_27 -> V_49 -> V_51 ) ;
V_27 -> V_52 = 1 ;
F_24 ( & V_27 -> V_47 ) ;
}
void F_25 ( struct V_53 * V_54 )
{
struct V_55 * V_49 = V_54 -> V_12 -> V_16 . V_17 ;
struct V_56 * V_29 ;
if ( ! F_26 ( V_54 ) || ! V_49 )
return;
V_29 = & V_49 -> V_18 . V_29 ;
F_27 ( & V_49 -> V_18 . V_20 ) ;
if ( F_28 ( V_29 ) )
F_29 ( V_29 , V_57 ) ;
F_30 ( & V_49 -> V_18 . V_20 ) ;
}
static void F_31 ( struct V_55 * V_49 )
{
F_28 ( & V_49 -> V_18 . V_29 ) ;
F_32 ( & V_49 -> V_51 ) ;
}
static void F_33 ( struct V_58 * V_59 )
{
struct V_55 * V_49 = F_19 ( V_59 , struct V_55 , V_51 ) ;
struct V_12 * V_12 = V_49 -> V_12 ;
struct V_53 * V_54 ;
int V_60 ;
struct V_26 * V_27 = & V_49 -> V_18 ;
int V_61 = 0 ;
F_20 ( & V_27 -> V_47 ) ;
if ( V_27 -> V_52 ) {
V_27 -> V_52 = 0 ;
V_61 = 1 ;
}
F_24 ( & V_27 -> V_47 ) ;
if ( V_61 ) {
F_34 ( V_12 , V_12 -> V_16 . V_17 -> V_62 , 0 , 1 , false ) ;
F_34 ( V_12 , V_12 -> V_16 . V_17 -> V_62 , 0 , 0 , false ) ;
if ( F_35 ( & V_12 -> V_16 . V_63 ) > 0 )
F_36 (i, vcpu, kvm)
F_37 ( V_54 ) ;
}
}
static enum V_64 F_38 ( struct V_56 * V_65 )
{
struct V_26 * V_27 = F_19 ( V_65 , struct V_26 , V_29 ) ;
struct V_55 * V_66 = V_27 -> V_12 -> V_16 . V_17 ;
if ( V_27 -> V_67 || ! F_35 ( & V_27 -> V_48 ) ) {
F_22 ( & V_27 -> V_48 ) ;
F_23 ( & V_66 -> V_50 , & V_66 -> V_51 ) ;
}
if ( V_27 -> V_68 ) {
F_39 ( & V_27 -> V_29 , V_27 -> V_28 ) ;
return V_69 ;
} else
return V_70 ;
}
static void F_40 ( struct V_12 * V_12 , T_2 V_14 , int V_71 )
{
struct V_26 * V_27 = & V_12 -> V_16 . V_17 -> V_18 ;
T_3 V_72 ;
if ( ! F_41 ( V_12 ) ||
V_27 -> V_73 & V_74 )
return;
V_72 = F_1 ( V_14 , V_34 , V_33 ) ;
F_42 ( L_1 , V_72 ) ;
F_28 ( & V_27 -> V_29 ) ;
F_32 ( & V_27 -> V_49 -> V_51 ) ;
V_27 -> V_28 = V_72 ;
V_27 -> V_68 = V_71 ;
V_27 -> V_29 . V_75 = F_38 ;
V_27 -> V_12 = V_27 -> V_49 -> V_12 ;
F_43 ( & V_27 -> V_48 , 0 ) ;
V_27 -> V_52 = 1 ;
if ( V_27 -> V_68 ) {
T_3 V_76 = V_77 * 1000LL ;
if ( V_27 -> V_28 < V_76 ) {
F_44 (
L_2
L_3 ,
V_27 -> V_28 , V_76 ) ;
V_27 -> V_28 = V_76 ;
}
}
F_45 ( & V_27 -> V_29 , F_46 ( F_7 () , V_72 ) ,
V_57 ) ;
}
static void F_47 ( struct V_12 * V_12 , int V_13 , T_2 V_14 )
{
struct V_26 * V_27 = & V_12 -> V_16 . V_17 -> V_18 ;
F_5 ( ! F_6 ( & V_27 -> V_20 ) ) ;
F_42 ( L_4 , V_14 , V_13 ) ;
if ( V_14 == 0 )
V_14 = 0x10000 ;
V_27 -> V_19 [ V_13 ] . V_35 = V_14 ;
if ( V_13 != 0 ) {
V_27 -> V_19 [ V_13 ] . V_23 = F_7 () ;
return;
}
switch ( V_27 -> V_19 [ 0 ] . V_21 ) {
case 0 :
case 1 :
case 4 :
F_40 ( V_12 , V_14 , 0 ) ;
break;
case 2 :
case 3 :
F_40 ( V_12 , V_14 , 1 ) ;
break;
default:
F_31 ( V_12 -> V_16 . V_17 ) ;
}
}
void F_48 ( struct V_12 * V_12 , int V_13 , T_2 V_14 , int V_78 )
{
T_5 V_79 ;
if ( V_78 ) {
F_5 ( V_13 != 0 ) ;
V_79 = V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 ;
V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 = 0xff ;
F_47 ( V_12 , V_13 , V_14 ) ;
V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 = V_79 ;
} else {
F_47 ( V_12 , V_13 , V_14 ) ;
}
}
static inline struct V_55 * F_49 ( struct V_80 * V_81 )
{
return F_19 ( V_81 , struct V_55 , V_81 ) ;
}
static inline struct V_55 * F_50 ( struct V_80 * V_81 )
{
return F_19 ( V_81 , struct V_55 , V_82 ) ;
}
static inline int F_51 ( T_6 V_83 )
{
return ( ( V_83 >= V_84 ) &&
( V_83 < V_84 + V_85 ) ) ;
}
static int F_52 ( struct V_53 * V_54 ,
struct V_80 * V_86 ,
T_6 V_83 , int V_87 , const void * V_65 )
{
struct V_55 * V_49 = F_49 ( V_86 ) ;
struct V_26 * V_18 = & V_49 -> V_18 ;
struct V_12 * V_12 = V_49 -> V_12 ;
int V_13 , V_88 ;
struct V_15 * V_89 ;
T_2 V_14 = * ( T_2 * ) V_65 ;
if ( ! F_51 ( V_83 ) )
return - V_90 ;
V_14 &= 0xff ;
V_83 &= V_91 ;
F_27 ( & V_18 -> V_20 ) ;
if ( V_14 != 0 )
F_42 ( L_5 ,
( unsigned int ) V_83 , V_87 , V_14 ) ;
if ( V_83 == 3 ) {
V_13 = V_14 >> 6 ;
if ( V_13 == 3 ) {
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_89 = & V_18 -> V_19 [ V_13 ] ;
if ( V_14 & ( 2 << V_13 ) ) {
if ( ! ( V_14 & 0x20 ) )
F_16 ( V_12 , V_13 ) ;
if ( ! ( V_14 & 0x10 ) )
F_17 ( V_12 , V_13 ) ;
}
}
} else {
V_89 = & V_18 -> V_19 [ V_13 ] ;
V_88 = ( V_14 >> 4 ) & V_91 ;
if ( V_88 == 0 ) {
F_16 ( V_12 , V_13 ) ;
} else {
V_89 -> V_39 = V_88 ;
V_89 -> V_92 = V_88 ;
V_89 -> V_93 = V_88 ;
V_89 -> V_21 = ( V_14 >> 1 ) & 7 ;
if ( V_89 -> V_21 > 5 )
V_89 -> V_21 -= 4 ;
V_89 -> V_42 = V_14 & 1 ;
}
}
} else {
V_89 = & V_18 -> V_19 [ V_83 ] ;
switch ( V_89 -> V_93 ) {
default:
case V_94 :
F_47 ( V_12 , V_83 , V_14 ) ;
break;
case V_95 :
F_47 ( V_12 , V_83 , V_14 << 8 ) ;
break;
case V_96 :
V_89 -> V_97 = V_14 ;
V_89 -> V_93 = V_98 ;
break;
case V_98 :
F_47 ( V_12 , V_83 , V_89 -> V_97 | ( V_14 << 8 ) ) ;
V_89 -> V_93 = V_96 ;
break;
}
}
F_30 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_53 ( struct V_53 * V_54 ,
struct V_80 * V_86 ,
T_6 V_83 , int V_87 , void * V_65 )
{
struct V_55 * V_49 = F_49 ( V_86 ) ;
struct V_26 * V_18 = & V_49 -> V_18 ;
struct V_12 * V_12 = V_49 -> V_12 ;
int V_99 , V_35 ;
struct V_15 * V_89 ;
if ( ! F_51 ( V_83 ) )
return - V_90 ;
V_83 &= V_91 ;
if ( V_83 == 3 )
return 0 ;
V_89 = & V_18 -> V_19 [ V_83 ] ;
F_27 ( & V_18 -> V_20 ) ;
if ( V_89 -> V_40 ) {
V_89 -> V_40 = 0 ;
V_99 = V_89 -> V_41 ;
} else if ( V_89 -> V_37 ) {
switch ( V_89 -> V_37 ) {
default:
case V_94 :
V_99 = V_89 -> V_38 & 0xff ;
V_89 -> V_37 = 0 ;
break;
case V_95 :
V_99 = V_89 -> V_38 >> 8 ;
V_89 -> V_37 = 0 ;
break;
case V_96 :
V_99 = V_89 -> V_38 & 0xff ;
V_89 -> V_37 = V_95 ;
break;
}
} else {
switch ( V_89 -> V_92 ) {
default:
case V_94 :
V_35 = F_14 ( V_12 , V_83 ) ;
V_99 = V_35 & 0xff ;
break;
case V_95 :
V_35 = F_14 ( V_12 , V_83 ) ;
V_99 = ( V_35 >> 8 ) & 0xff ;
break;
case V_96 :
V_35 = F_14 ( V_12 , V_83 ) ;
V_99 = V_35 & 0xff ;
V_89 -> V_92 = V_98 ;
break;
case V_98 :
V_35 = F_14 ( V_12 , V_83 ) ;
V_99 = ( V_35 >> 8 ) & 0xff ;
V_89 -> V_92 = V_96 ;
break;
}
}
if ( V_87 > sizeof( V_99 ) )
V_87 = sizeof( V_99 ) ;
memcpy ( V_65 , ( char * ) & V_99 , V_87 ) ;
F_30 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_54 ( struct V_53 * V_54 ,
struct V_80 * V_86 ,
T_6 V_83 , int V_87 , const void * V_65 )
{
struct V_55 * V_49 = F_50 ( V_86 ) ;
struct V_26 * V_18 = & V_49 -> V_18 ;
struct V_12 * V_12 = V_49 -> V_12 ;
T_2 V_14 = * ( T_2 * ) V_65 ;
if ( V_83 != V_100 )
return - V_90 ;
F_27 ( & V_18 -> V_20 ) ;
V_18 -> V_101 = ( V_14 >> 1 ) & 1 ;
F_4 ( V_12 , 2 , V_14 & 1 ) ;
F_30 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_55 ( struct V_53 * V_54 ,
struct V_80 * V_86 ,
T_6 V_83 , int V_87 , void * V_65 )
{
struct V_55 * V_49 = F_50 ( V_86 ) ;
struct V_26 * V_18 = & V_49 -> V_18 ;
struct V_12 * V_12 = V_49 -> V_12 ;
unsigned int V_102 ;
int V_99 ;
if ( V_83 != V_100 )
return - V_90 ;
V_102 = ( ( unsigned int ) F_11 ( F_7 () ) >> 14 ) & 1 ;
F_27 ( & V_18 -> V_20 ) ;
V_99 = ( ( V_18 -> V_101 << 1 ) | F_8 ( V_12 , 2 ) |
( F_15 ( V_12 , 2 ) << 5 ) | ( V_102 << 4 ) ) ;
if ( V_87 > sizeof( V_99 ) )
V_87 = sizeof( V_99 ) ;
memcpy ( V_65 , ( char * ) & V_99 , V_87 ) ;
F_30 ( & V_18 -> V_20 ) ;
return 0 ;
}
void F_56 ( struct V_55 * V_49 )
{
int V_60 ;
struct V_15 * V_3 ;
F_27 ( & V_49 -> V_18 . V_20 ) ;
V_49 -> V_18 . V_73 = 0 ;
for ( V_60 = 0 ; V_60 < 3 ; V_60 ++ ) {
V_3 = & V_49 -> V_18 . V_19 [ V_60 ] ;
V_3 -> V_21 = 0xff ;
V_3 -> V_22 = ( V_60 != 2 ) ;
F_47 ( V_49 -> V_12 , V_60 , 0 ) ;
}
F_30 ( & V_49 -> V_18 . V_20 ) ;
F_43 ( & V_49 -> V_18 . V_48 , 0 ) ;
V_49 -> V_18 . V_52 = 1 ;
}
static void F_57 ( struct V_103 * V_104 , bool V_105 )
{
struct V_55 * V_49 = F_19 ( V_104 , struct V_55 , V_106 ) ;
if ( ! V_105 ) {
F_43 ( & V_49 -> V_18 . V_48 , 0 ) ;
V_49 -> V_18 . V_52 = 1 ;
}
}
struct V_55 * F_58 ( struct V_12 * V_12 , T_2 V_73 )
{
struct V_55 * V_49 ;
struct V_26 * V_18 ;
struct V_107 * V_107 ;
T_7 V_108 ;
int V_99 ;
V_49 = F_59 ( sizeof( struct V_55 ) , V_109 ) ;
if ( ! V_49 )
return NULL ;
V_49 -> V_62 = F_60 ( V_12 ) ;
if ( V_49 -> V_62 < 0 ) {
F_61 ( V_49 ) ;
return NULL ;
}
F_62 ( & V_49 -> V_18 . V_20 ) ;
F_27 ( & V_49 -> V_18 . V_20 ) ;
F_63 ( & V_49 -> V_18 . V_47 ) ;
V_107 = F_64 ( F_65 ( V_110 ) ) ;
V_108 = F_66 ( V_107 ) ;
F_67 ( V_107 ) ;
F_68 ( & V_49 -> V_50 ) ;
V_49 -> V_111 = F_69 ( V_112 , & V_49 -> V_50 ,
L_6 , V_108 ) ;
if ( F_70 ( V_49 -> V_111 ) ) {
F_30 ( & V_49 -> V_18 . V_20 ) ;
F_71 ( V_12 , V_49 -> V_62 ) ;
F_61 ( V_49 ) ;
return NULL ;
}
F_72 ( & V_49 -> V_51 , F_33 ) ;
V_12 -> V_16 . V_17 = V_49 ;
V_49 -> V_12 = V_12 ;
V_18 = & V_49 -> V_18 ;
V_18 -> V_49 = V_49 ;
F_73 ( & V_18 -> V_29 , V_113 , V_57 ) ;
V_18 -> V_45 . V_114 = 0 ;
V_18 -> V_45 . V_115 = F_18 ;
F_74 ( V_12 , & V_18 -> V_45 ) ;
V_18 -> V_67 = true ;
F_30 ( & V_49 -> V_18 . V_20 ) ;
F_56 ( V_49 ) ;
V_49 -> V_106 . V_116 = F_57 ;
F_75 ( V_12 , 0 , & V_49 -> V_106 ) ;
F_76 ( & V_49 -> V_81 , & V_117 ) ;
V_99 = F_77 ( V_12 , V_118 , V_84 ,
V_85 , & V_49 -> V_81 ) ;
if ( V_99 < 0 )
goto V_119;
if ( V_73 & V_120 ) {
F_76 ( & V_49 -> V_82 , & V_121 ) ;
V_99 = F_77 ( V_12 , V_118 ,
V_100 , 4 ,
& V_49 -> V_82 ) ;
if ( V_99 < 0 )
goto V_122;
}
return V_49 ;
V_122:
F_78 ( V_12 , V_118 , & V_49 -> V_81 ) ;
V_119:
F_79 ( V_12 , 0 , & V_49 -> V_106 ) ;
F_80 ( V_12 , & V_18 -> V_45 ) ;
F_71 ( V_12 , V_49 -> V_62 ) ;
F_81 ( V_49 -> V_111 ) ;
F_61 ( V_49 ) ;
return NULL ;
}
void F_82 ( struct V_12 * V_12 )
{
struct V_56 * V_29 ;
if ( V_12 -> V_16 . V_17 ) {
F_78 ( V_12 , V_118 , & V_12 -> V_16 . V_17 -> V_81 ) ;
F_78 ( V_12 , V_118 ,
& V_12 -> V_16 . V_17 -> V_82 ) ;
F_79 ( V_12 , 0 ,
& V_12 -> V_16 . V_17 -> V_106 ) ;
F_80 ( V_12 ,
& V_12 -> V_16 . V_17 -> V_18 . V_45 ) ;
F_27 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ;
V_29 = & V_12 -> V_16 . V_17 -> V_18 . V_29 ;
F_28 ( V_29 ) ;
F_32 ( & V_12 -> V_16 . V_17 -> V_51 ) ;
F_81 ( V_12 -> V_16 . V_17 -> V_111 ) ;
F_71 ( V_12 , V_12 -> V_16 . V_17 -> V_62 ) ;
F_30 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ;
F_61 ( V_12 -> V_16 . V_17 ) ;
}
}
