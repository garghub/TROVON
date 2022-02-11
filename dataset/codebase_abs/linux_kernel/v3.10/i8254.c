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
if ( F_27 ( V_29 ) )
F_28 ( V_29 , V_57 ) ;
}
static void F_29 ( struct V_55 * V_49 )
{
F_27 ( & V_49 -> V_18 . V_29 ) ;
F_30 ( & V_49 -> V_51 ) ;
}
static void F_31 ( struct V_58 * V_59 )
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
F_32 ( V_12 , V_12 -> V_16 . V_17 -> V_62 , 0 , 1 , false ) ;
F_32 ( V_12 , V_12 -> V_16 . V_17 -> V_62 , 0 , 0 , false ) ;
if ( V_12 -> V_16 . V_63 > 0 )
F_33 (i, vcpu, kvm)
F_34 ( V_54 ) ;
}
}
static enum V_64 F_35 ( struct V_56 * V_65 )
{
struct V_26 * V_27 = F_19 ( V_65 , struct V_26 , V_29 ) ;
struct V_55 * V_66 = V_27 -> V_12 -> V_16 . V_17 ;
if ( V_27 -> V_67 || ! F_36 ( & V_27 -> V_48 ) ) {
F_22 ( & V_27 -> V_48 ) ;
F_23 ( & V_66 -> V_50 , & V_66 -> V_51 ) ;
}
if ( V_27 -> V_68 ) {
F_37 ( & V_27 -> V_29 , V_27 -> V_28 ) ;
return V_69 ;
} else
return V_70 ;
}
static void F_38 ( struct V_12 * V_12 , T_2 V_14 , int V_71 )
{
struct V_26 * V_27 = & V_12 -> V_16 . V_17 -> V_18 ;
T_3 V_72 ;
if ( ! F_39 ( V_12 ) || V_27 -> V_73 & V_74 )
return;
V_72 = F_1 ( V_14 , V_34 , V_33 ) ;
F_40 ( L_1 , V_72 ) ;
F_27 ( & V_27 -> V_29 ) ;
F_30 ( & V_27 -> V_49 -> V_51 ) ;
V_27 -> V_28 = V_72 ;
V_27 -> V_68 = V_71 ;
V_27 -> V_29 . V_75 = F_35 ;
V_27 -> V_12 = V_27 -> V_49 -> V_12 ;
F_41 ( & V_27 -> V_48 , 0 ) ;
V_27 -> V_52 = 1 ;
F_42 ( & V_27 -> V_29 , F_43 ( F_7 () , V_72 ) ,
V_57 ) ;
}
static void F_44 ( struct V_12 * V_12 , int V_13 , T_2 V_14 )
{
struct V_26 * V_27 = & V_12 -> V_16 . V_17 -> V_18 ;
F_5 ( ! F_6 ( & V_27 -> V_20 ) ) ;
F_40 ( L_2 , V_14 , V_13 ) ;
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
F_38 ( V_12 , V_14 , 0 ) ;
break;
case 2 :
case 3 :
F_38 ( V_12 , V_14 , 1 ) ;
break;
default:
F_29 ( V_12 -> V_16 . V_17 ) ;
}
}
void F_45 ( struct V_12 * V_12 , int V_13 , T_2 V_14 , int V_76 )
{
T_5 V_77 ;
if ( V_76 ) {
V_77 = V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 ;
V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 = 0xff ;
F_44 ( V_12 , V_13 , V_14 ) ;
V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 = V_77 ;
} else {
F_44 ( V_12 , V_13 , V_14 ) ;
}
}
static inline struct V_55 * F_46 ( struct V_78 * V_79 )
{
return F_19 ( V_79 , struct V_55 , V_79 ) ;
}
static inline struct V_55 * F_47 ( struct V_78 * V_79 )
{
return F_19 ( V_79 , struct V_55 , V_80 ) ;
}
static inline int F_48 ( T_6 V_81 )
{
return ( ( V_81 >= V_82 ) &&
( V_81 < V_82 + V_83 ) ) ;
}
static int F_49 ( struct V_78 * V_84 ,
T_6 V_81 , int V_85 , const void * V_65 )
{
struct V_55 * V_49 = F_46 ( V_84 ) ;
struct V_26 * V_18 = & V_49 -> V_18 ;
struct V_12 * V_12 = V_49 -> V_12 ;
int V_13 , V_86 ;
struct V_15 * V_87 ;
T_2 V_14 = * ( T_2 * ) V_65 ;
if ( ! F_48 ( V_81 ) )
return - V_88 ;
V_14 &= 0xff ;
V_81 &= V_89 ;
F_50 ( & V_18 -> V_20 ) ;
if ( V_14 != 0 )
F_40 ( L_3 ,
( unsigned int ) V_81 , V_85 , V_14 ) ;
if ( V_81 == 3 ) {
V_13 = V_14 >> 6 ;
if ( V_13 == 3 ) {
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_87 = & V_18 -> V_19 [ V_13 ] ;
if ( V_14 & ( 2 << V_13 ) ) {
if ( ! ( V_14 & 0x20 ) )
F_16 ( V_12 , V_13 ) ;
if ( ! ( V_14 & 0x10 ) )
F_17 ( V_12 , V_13 ) ;
}
}
} else {
V_87 = & V_18 -> V_19 [ V_13 ] ;
V_86 = ( V_14 >> 4 ) & V_89 ;
if ( V_86 == 0 ) {
F_16 ( V_12 , V_13 ) ;
} else {
V_87 -> V_39 = V_86 ;
V_87 -> V_90 = V_86 ;
V_87 -> V_91 = V_86 ;
V_87 -> V_21 = ( V_14 >> 1 ) & 7 ;
if ( V_87 -> V_21 > 5 )
V_87 -> V_21 -= 4 ;
V_87 -> V_42 = V_14 & 1 ;
}
}
} else {
V_87 = & V_18 -> V_19 [ V_81 ] ;
switch ( V_87 -> V_91 ) {
default:
case V_92 :
F_44 ( V_12 , V_81 , V_14 ) ;
break;
case V_93 :
F_44 ( V_12 , V_81 , V_14 << 8 ) ;
break;
case V_94 :
V_87 -> V_95 = V_14 ;
V_87 -> V_91 = V_96 ;
break;
case V_96 :
F_44 ( V_12 , V_81 , V_87 -> V_95 | ( V_14 << 8 ) ) ;
V_87 -> V_91 = V_94 ;
break;
}
}
F_51 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_52 ( struct V_78 * V_84 ,
T_6 V_81 , int V_85 , void * V_65 )
{
struct V_55 * V_49 = F_46 ( V_84 ) ;
struct V_26 * V_18 = & V_49 -> V_18 ;
struct V_12 * V_12 = V_49 -> V_12 ;
int V_97 , V_35 ;
struct V_15 * V_87 ;
if ( ! F_48 ( V_81 ) )
return - V_88 ;
V_81 &= V_89 ;
if ( V_81 == 3 )
return 0 ;
V_87 = & V_18 -> V_19 [ V_81 ] ;
F_50 ( & V_18 -> V_20 ) ;
if ( V_87 -> V_40 ) {
V_87 -> V_40 = 0 ;
V_97 = V_87 -> V_41 ;
} else if ( V_87 -> V_37 ) {
switch ( V_87 -> V_37 ) {
default:
case V_92 :
V_97 = V_87 -> V_38 & 0xff ;
V_87 -> V_37 = 0 ;
break;
case V_93 :
V_97 = V_87 -> V_38 >> 8 ;
V_87 -> V_37 = 0 ;
break;
case V_94 :
V_97 = V_87 -> V_38 & 0xff ;
V_87 -> V_37 = V_93 ;
break;
}
} else {
switch ( V_87 -> V_90 ) {
default:
case V_92 :
V_35 = F_14 ( V_12 , V_81 ) ;
V_97 = V_35 & 0xff ;
break;
case V_93 :
V_35 = F_14 ( V_12 , V_81 ) ;
V_97 = ( V_35 >> 8 ) & 0xff ;
break;
case V_94 :
V_35 = F_14 ( V_12 , V_81 ) ;
V_97 = V_35 & 0xff ;
V_87 -> V_90 = V_96 ;
break;
case V_96 :
V_35 = F_14 ( V_12 , V_81 ) ;
V_97 = ( V_35 >> 8 ) & 0xff ;
V_87 -> V_90 = V_94 ;
break;
}
}
if ( V_85 > sizeof( V_97 ) )
V_85 = sizeof( V_97 ) ;
memcpy ( V_65 , ( char * ) & V_97 , V_85 ) ;
F_51 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_53 ( struct V_78 * V_84 ,
T_6 V_81 , int V_85 , const void * V_65 )
{
struct V_55 * V_49 = F_47 ( V_84 ) ;
struct V_26 * V_18 = & V_49 -> V_18 ;
struct V_12 * V_12 = V_49 -> V_12 ;
T_2 V_14 = * ( T_2 * ) V_65 ;
if ( V_81 != V_98 )
return - V_88 ;
F_50 ( & V_18 -> V_20 ) ;
V_18 -> V_99 = ( V_14 >> 1 ) & 1 ;
F_4 ( V_12 , 2 , V_14 & 1 ) ;
F_51 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_54 ( struct V_78 * V_84 ,
T_6 V_81 , int V_85 , void * V_65 )
{
struct V_55 * V_49 = F_47 ( V_84 ) ;
struct V_26 * V_18 = & V_49 -> V_18 ;
struct V_12 * V_12 = V_49 -> V_12 ;
unsigned int V_100 ;
int V_97 ;
if ( V_81 != V_98 )
return - V_88 ;
V_100 = ( ( unsigned int ) F_11 ( F_7 () ) >> 14 ) & 1 ;
F_50 ( & V_18 -> V_20 ) ;
V_97 = ( ( V_18 -> V_99 << 1 ) | F_8 ( V_12 , 2 ) |
( F_15 ( V_12 , 2 ) << 5 ) | ( V_100 << 4 ) ) ;
if ( V_85 > sizeof( V_97 ) )
V_85 = sizeof( V_97 ) ;
memcpy ( V_65 , ( char * ) & V_97 , V_85 ) ;
F_51 ( & V_18 -> V_20 ) ;
return 0 ;
}
void F_55 ( struct V_55 * V_49 )
{
int V_60 ;
struct V_15 * V_3 ;
F_50 ( & V_49 -> V_18 . V_20 ) ;
V_49 -> V_18 . V_73 = 0 ;
for ( V_60 = 0 ; V_60 < 3 ; V_60 ++ ) {
V_3 = & V_49 -> V_18 . V_19 [ V_60 ] ;
V_3 -> V_21 = 0xff ;
V_3 -> V_22 = ( V_60 != 2 ) ;
F_44 ( V_49 -> V_12 , V_60 , 0 ) ;
}
F_51 ( & V_49 -> V_18 . V_20 ) ;
F_41 ( & V_49 -> V_18 . V_48 , 0 ) ;
V_49 -> V_18 . V_52 = 1 ;
}
static void F_56 ( struct V_101 * V_102 , bool V_103 )
{
struct V_55 * V_49 = F_19 ( V_102 , struct V_55 , V_104 ) ;
if ( ! V_103 ) {
F_41 ( & V_49 -> V_18 . V_48 , 0 ) ;
V_49 -> V_18 . V_52 = 1 ;
}
}
struct V_55 * F_57 ( struct V_12 * V_12 , T_2 V_73 )
{
struct V_55 * V_49 ;
struct V_26 * V_18 ;
struct V_105 * V_105 ;
T_7 V_106 ;
int V_97 ;
V_49 = F_58 ( sizeof( struct V_55 ) , V_107 ) ;
if ( ! V_49 )
return NULL ;
V_49 -> V_62 = F_59 ( V_12 ) ;
if ( V_49 -> V_62 < 0 ) {
F_60 ( V_49 ) ;
return NULL ;
}
F_61 ( & V_49 -> V_18 . V_20 ) ;
F_50 ( & V_49 -> V_18 . V_20 ) ;
F_62 ( & V_49 -> V_18 . V_47 ) ;
V_105 = F_63 ( F_64 ( V_108 ) ) ;
V_106 = F_65 ( V_105 ) ;
F_66 ( V_105 ) ;
F_67 ( & V_49 -> V_50 ) ;
V_49 -> V_109 = F_68 ( V_110 , & V_49 -> V_50 ,
L_4 , V_106 ) ;
if ( F_69 ( V_49 -> V_109 ) ) {
F_51 ( & V_49 -> V_18 . V_20 ) ;
F_70 ( V_12 , V_49 -> V_62 ) ;
F_60 ( V_49 ) ;
return NULL ;
}
F_71 ( & V_49 -> V_51 , F_31 ) ;
V_12 -> V_16 . V_17 = V_49 ;
V_49 -> V_12 = V_12 ;
V_18 = & V_49 -> V_18 ;
V_18 -> V_49 = V_49 ;
F_72 ( & V_18 -> V_29 , V_111 , V_57 ) ;
V_18 -> V_45 . V_112 = 0 ;
V_18 -> V_45 . V_113 = F_18 ;
F_73 ( V_12 , & V_18 -> V_45 ) ;
V_18 -> V_67 = true ;
F_51 ( & V_49 -> V_18 . V_20 ) ;
F_55 ( V_49 ) ;
V_49 -> V_104 . V_114 = F_56 ;
F_74 ( V_12 , 0 , & V_49 -> V_104 ) ;
F_75 ( & V_49 -> V_79 , & V_115 ) ;
V_97 = F_76 ( V_12 , V_116 , V_82 ,
V_83 , & V_49 -> V_79 ) ;
if ( V_97 < 0 )
goto V_117;
if ( V_73 & V_118 ) {
F_75 ( & V_49 -> V_80 , & V_119 ) ;
V_97 = F_76 ( V_12 , V_116 ,
V_98 , 4 ,
& V_49 -> V_80 ) ;
if ( V_97 < 0 )
goto V_120;
}
return V_49 ;
V_120:
F_77 ( V_12 , V_116 , & V_49 -> V_79 ) ;
V_117:
F_78 ( V_12 , 0 , & V_49 -> V_104 ) ;
F_79 ( V_12 , & V_18 -> V_45 ) ;
F_70 ( V_12 , V_49 -> V_62 ) ;
F_80 ( V_49 -> V_109 ) ;
F_60 ( V_49 ) ;
return NULL ;
}
void F_81 ( struct V_12 * V_12 )
{
struct V_56 * V_29 ;
if ( V_12 -> V_16 . V_17 ) {
F_77 ( V_12 , V_116 , & V_12 -> V_16 . V_17 -> V_79 ) ;
F_77 ( V_12 , V_116 ,
& V_12 -> V_16 . V_17 -> V_80 ) ;
F_78 ( V_12 , 0 ,
& V_12 -> V_16 . V_17 -> V_104 ) ;
F_79 ( V_12 ,
& V_12 -> V_16 . V_17 -> V_18 . V_45 ) ;
F_50 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ;
V_29 = & V_12 -> V_16 . V_17 -> V_18 . V_29 ;
F_27 ( V_29 ) ;
F_30 ( & V_12 -> V_16 . V_17 -> V_51 ) ;
F_80 ( V_12 -> V_16 . V_17 -> V_109 ) ;
F_70 ( V_12 , V_12 -> V_16 . V_17 -> V_62 ) ;
F_51 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ;
F_60 ( V_12 -> V_16 . V_17 ) ;
}
}
