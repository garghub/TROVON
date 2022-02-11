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
if ( ! V_27 -> V_28 . V_29 )
return 0 ;
V_25 = F_10 ( & V_27 -> V_28 . V_30 ) ;
V_24 = V_27 -> V_28 . V_29 - F_11 ( V_25 ) ;
V_24 = F_3 ( V_24 , V_27 -> V_28 . V_29 ) ;
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
T_3 V_31 , V_32 ;
int V_33 ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
V_32 = F_12 ( V_12 , V_3 , V_13 ) ;
V_31 = F_1 ( V_32 , V_34 , V_35 ) ;
switch ( V_3 -> V_21 ) {
case 0 :
case 1 :
case 4 :
case 5 :
V_33 = ( V_3 -> V_36 - V_31 ) & 0xffff ;
break;
case 3 :
V_33 = V_3 -> V_36 - ( F_3 ( ( 2 * V_31 ) , V_3 -> V_36 ) ) ;
break;
default:
V_33 = V_3 -> V_36 - F_3 ( V_31 , V_3 -> V_36 ) ;
break;
}
return V_33 ;
}
static int F_15 ( struct V_12 * V_12 , int V_13 )
{
struct V_15 * V_3 =
& V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] ;
T_3 V_31 , V_32 ;
int V_37 ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
V_32 = F_12 ( V_12 , V_3 , V_13 ) ;
V_31 = F_1 ( V_32 , V_34 , V_35 ) ;
switch ( V_3 -> V_21 ) {
default:
case 0 :
V_37 = ( V_31 >= V_3 -> V_36 ) ;
break;
case 1 :
V_37 = ( V_31 < V_3 -> V_36 ) ;
break;
case 2 :
V_37 = ( ( F_3 ( V_31 , V_3 -> V_36 ) == 0 ) && ( V_31 != 0 ) ) ;
break;
case 3 :
V_37 = ( F_3 ( V_31 , V_3 -> V_36 ) < ( ( V_3 -> V_36 + 1 ) >> 1 ) ) ;
break;
case 4 :
case 5 :
V_37 = ( V_31 == V_3 -> V_36 ) ;
break;
}
return V_37 ;
}
static void F_16 ( struct V_12 * V_12 , int V_13 )
{
struct V_15 * V_3 =
& V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
if ( ! V_3 -> V_38 ) {
V_3 -> V_39 = F_14 ( V_12 , V_13 ) ;
V_3 -> V_38 = V_3 -> V_40 ;
}
}
static void F_17 ( struct V_12 * V_12 , int V_13 )
{
struct V_15 * V_3 =
& V_12 -> V_16 . V_17 -> V_18 . V_19 [ V_13 ] ;
F_5 ( ! F_6 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ) ;
if ( ! V_3 -> V_41 ) {
V_3 -> V_42 = ( ( F_15 ( V_12 , V_13 ) << 7 ) |
( V_3 -> V_40 << 4 ) |
( V_3 -> V_21 << 1 ) |
V_3 -> V_43 ) ;
V_3 -> V_41 = 1 ;
}
}
static void F_18 ( struct V_44 * V_45 )
{
struct V_26 * V_27 = F_19 ( V_45 , struct V_26 ,
V_46 ) ;
int V_47 ;
F_20 ( & V_27 -> V_48 ) ;
V_47 = F_21 ( & V_27 -> V_28 . V_49 ) ;
if ( V_47 < 0 )
F_22 ( & V_27 -> V_28 . V_49 ) ;
else if ( V_47 > 0 )
F_23 ( V_27 -> V_50 -> V_51 , & V_27 -> V_50 -> V_52 ) ;
V_27 -> V_53 = 1 ;
F_24 ( & V_27 -> V_48 ) ;
}
void F_25 ( struct V_54 * V_55 )
{
struct V_56 * V_50 = V_55 -> V_12 -> V_16 . V_17 ;
struct V_57 * V_30 ;
if ( ! F_26 ( V_55 ) || ! V_50 )
return;
V_30 = & V_50 -> V_18 . V_28 . V_30 ;
if ( F_27 ( V_30 ) )
F_28 ( V_30 , V_58 ) ;
}
static void F_29 ( struct V_56 * V_50 )
{
F_27 ( & V_50 -> V_18 . V_28 . V_30 ) ;
F_30 ( & V_50 -> V_52 ) ;
}
static bool F_31 ( struct V_59 * V_60 )
{
struct V_26 * V_27 = F_19 ( V_60 , struct V_26 ,
V_28 ) ;
return V_27 -> V_61 ;
}
static void F_32 ( struct V_62 * V_63 )
{
struct V_56 * V_50 = F_19 ( V_63 , struct V_56 , V_52 ) ;
struct V_12 * V_12 = V_50 -> V_12 ;
struct V_54 * V_55 ;
int V_64 ;
struct V_26 * V_27 = & V_50 -> V_18 ;
int V_65 = 0 ;
F_20 ( & V_27 -> V_48 ) ;
if ( V_27 -> V_53 ) {
V_27 -> V_53 = 0 ;
V_65 = 1 ;
}
F_24 ( & V_27 -> V_48 ) ;
if ( V_65 ) {
F_33 ( V_12 , V_12 -> V_16 . V_17 -> V_66 , 0 , 1 ) ;
F_33 ( V_12 , V_12 -> V_16 . V_17 -> V_66 , 0 , 0 ) ;
if ( V_12 -> V_16 . V_67 > 0 )
F_34 (i, vcpu, kvm)
F_35 ( V_55 ) ;
}
}
static enum V_68 F_36 ( struct V_57 * V_69 )
{
struct V_59 * V_60 = F_19 ( V_69 , struct V_59 , V_30 ) ;
struct V_56 * V_70 = V_60 -> V_12 -> V_16 . V_17 ;
if ( V_60 -> V_71 || ! F_37 ( & V_60 -> V_49 ) ) {
F_22 ( & V_60 -> V_49 ) ;
F_23 ( V_70 -> V_51 , & V_70 -> V_52 ) ;
}
if ( V_60 -> V_72 -> V_61 ( V_60 ) ) {
F_38 ( & V_60 -> V_30 , V_60 -> V_29 ) ;
return V_73 ;
} else
return V_74 ;
}
static void F_39 ( struct V_12 * V_12 , T_2 V_14 , int V_75 )
{
struct V_26 * V_27 = & V_12 -> V_16 . V_17 -> V_18 ;
struct V_59 * V_70 = & V_27 -> V_28 ;
T_3 V_76 ;
if ( ! F_40 ( V_12 ) || V_27 -> V_77 & V_78 )
return;
V_76 = F_1 ( V_14 , V_35 , V_34 ) ;
F_41 ( L_1 , V_76 ) ;
F_27 ( & V_70 -> V_30 ) ;
F_30 ( & V_27 -> V_50 -> V_52 ) ;
V_70 -> V_29 = V_76 ;
V_27 -> V_61 = V_75 ;
V_70 -> V_30 . V_79 = F_36 ;
V_70 -> V_72 = & V_80 ;
V_70 -> V_12 = V_27 -> V_50 -> V_12 ;
F_42 ( & V_70 -> V_49 , 0 ) ;
V_27 -> V_53 = 1 ;
F_43 ( & V_70 -> V_30 , F_44 ( F_7 () , V_76 ) ,
V_58 ) ;
}
static void F_45 ( struct V_12 * V_12 , int V_13 , T_2 V_14 )
{
struct V_26 * V_27 = & V_12 -> V_16 . V_17 -> V_18 ;
F_5 ( ! F_6 ( & V_27 -> V_20 ) ) ;
F_41 ( L_2 , V_14 , V_13 ) ;
if ( V_14 == 0 )
V_14 = 0x10000 ;
V_27 -> V_19 [ V_13 ] . V_36 = V_14 ;
if ( V_13 != 0 ) {
V_27 -> V_19 [ V_13 ] . V_23 = F_7 () ;
return;
}
switch ( V_27 -> V_19 [ 0 ] . V_21 ) {
case 0 :
case 1 :
case 4 :
F_39 ( V_12 , V_14 , 0 ) ;
break;
case 2 :
case 3 :
F_39 ( V_12 , V_14 , 1 ) ;
break;
default:
F_29 ( V_12 -> V_16 . V_17 ) ;
}
}
void F_46 ( struct V_12 * V_12 , int V_13 , T_2 V_14 , int V_81 )
{
T_5 V_82 ;
if ( V_81 ) {
V_82 = V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 ;
V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 = 0xff ;
F_45 ( V_12 , V_13 , V_14 ) ;
V_12 -> V_16 . V_17 -> V_18 . V_19 [ 0 ] . V_21 = V_82 ;
} else {
F_45 ( V_12 , V_13 , V_14 ) ;
}
}
static inline struct V_56 * F_47 ( struct V_83 * V_84 )
{
return F_19 ( V_84 , struct V_56 , V_84 ) ;
}
static inline struct V_56 * F_48 ( struct V_83 * V_84 )
{
return F_19 ( V_84 , struct V_56 , V_85 ) ;
}
static inline int F_49 ( T_6 V_86 )
{
return ( ( V_86 >= V_87 ) &&
( V_86 < V_87 + V_88 ) ) ;
}
static int F_50 ( struct V_83 * V_89 ,
T_6 V_86 , int V_90 , const void * V_69 )
{
struct V_56 * V_50 = F_47 ( V_89 ) ;
struct V_26 * V_18 = & V_50 -> V_18 ;
struct V_12 * V_12 = V_50 -> V_12 ;
int V_13 , V_91 ;
struct V_15 * V_92 ;
T_2 V_14 = * ( T_2 * ) V_69 ;
if ( ! F_49 ( V_86 ) )
return - V_93 ;
V_14 &= 0xff ;
V_86 &= V_94 ;
F_51 ( & V_18 -> V_20 ) ;
if ( V_14 != 0 )
F_41 ( L_3 ,
( unsigned int ) V_86 , V_90 , V_14 ) ;
if ( V_86 == 3 ) {
V_13 = V_14 >> 6 ;
if ( V_13 == 3 ) {
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_92 = & V_18 -> V_19 [ V_13 ] ;
if ( V_14 & ( 2 << V_13 ) ) {
if ( ! ( V_14 & 0x20 ) )
F_16 ( V_12 , V_13 ) ;
if ( ! ( V_14 & 0x10 ) )
F_17 ( V_12 , V_13 ) ;
}
}
} else {
V_92 = & V_18 -> V_19 [ V_13 ] ;
V_91 = ( V_14 >> 4 ) & V_94 ;
if ( V_91 == 0 ) {
F_16 ( V_12 , V_13 ) ;
} else {
V_92 -> V_40 = V_91 ;
V_92 -> V_95 = V_91 ;
V_92 -> V_96 = V_91 ;
V_92 -> V_21 = ( V_14 >> 1 ) & 7 ;
if ( V_92 -> V_21 > 5 )
V_92 -> V_21 -= 4 ;
V_92 -> V_43 = V_14 & 1 ;
}
}
} else {
V_92 = & V_18 -> V_19 [ V_86 ] ;
switch ( V_92 -> V_96 ) {
default:
case V_97 :
F_45 ( V_12 , V_86 , V_14 ) ;
break;
case V_98 :
F_45 ( V_12 , V_86 , V_14 << 8 ) ;
break;
case V_99 :
V_92 -> V_100 = V_14 ;
V_92 -> V_96 = V_101 ;
break;
case V_101 :
F_45 ( V_12 , V_86 , V_92 -> V_100 | ( V_14 << 8 ) ) ;
V_92 -> V_96 = V_99 ;
break;
}
}
F_52 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_53 ( struct V_83 * V_89 ,
T_6 V_86 , int V_90 , void * V_69 )
{
struct V_56 * V_50 = F_47 ( V_89 ) ;
struct V_26 * V_18 = & V_50 -> V_18 ;
struct V_12 * V_12 = V_50 -> V_12 ;
int V_102 , V_36 ;
struct V_15 * V_92 ;
if ( ! F_49 ( V_86 ) )
return - V_93 ;
V_86 &= V_94 ;
if ( V_86 == 3 )
return 0 ;
V_92 = & V_18 -> V_19 [ V_86 ] ;
F_51 ( & V_18 -> V_20 ) ;
if ( V_92 -> V_41 ) {
V_92 -> V_41 = 0 ;
V_102 = V_92 -> V_42 ;
} else if ( V_92 -> V_38 ) {
switch ( V_92 -> V_38 ) {
default:
case V_97 :
V_102 = V_92 -> V_39 & 0xff ;
V_92 -> V_38 = 0 ;
break;
case V_98 :
V_102 = V_92 -> V_39 >> 8 ;
V_92 -> V_38 = 0 ;
break;
case V_99 :
V_102 = V_92 -> V_39 & 0xff ;
V_92 -> V_38 = V_98 ;
break;
}
} else {
switch ( V_92 -> V_95 ) {
default:
case V_97 :
V_36 = F_14 ( V_12 , V_86 ) ;
V_102 = V_36 & 0xff ;
break;
case V_98 :
V_36 = F_14 ( V_12 , V_86 ) ;
V_102 = ( V_36 >> 8 ) & 0xff ;
break;
case V_99 :
V_36 = F_14 ( V_12 , V_86 ) ;
V_102 = V_36 & 0xff ;
V_92 -> V_95 = V_101 ;
break;
case V_101 :
V_36 = F_14 ( V_12 , V_86 ) ;
V_102 = ( V_36 >> 8 ) & 0xff ;
V_92 -> V_95 = V_99 ;
break;
}
}
if ( V_90 > sizeof( V_102 ) )
V_90 = sizeof( V_102 ) ;
memcpy ( V_69 , ( char * ) & V_102 , V_90 ) ;
F_52 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_54 ( struct V_83 * V_89 ,
T_6 V_86 , int V_90 , const void * V_69 )
{
struct V_56 * V_50 = F_48 ( V_89 ) ;
struct V_26 * V_18 = & V_50 -> V_18 ;
struct V_12 * V_12 = V_50 -> V_12 ;
T_2 V_14 = * ( T_2 * ) V_69 ;
if ( V_86 != V_103 )
return - V_93 ;
F_51 ( & V_18 -> V_20 ) ;
V_18 -> V_104 = ( V_14 >> 1 ) & 1 ;
F_4 ( V_12 , 2 , V_14 & 1 ) ;
F_52 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_55 ( struct V_83 * V_89 ,
T_6 V_86 , int V_90 , void * V_69 )
{
struct V_56 * V_50 = F_48 ( V_89 ) ;
struct V_26 * V_18 = & V_50 -> V_18 ;
struct V_12 * V_12 = V_50 -> V_12 ;
unsigned int V_105 ;
int V_102 ;
if ( V_86 != V_103 )
return - V_93 ;
V_105 = ( ( unsigned int ) F_11 ( F_7 () ) >> 14 ) & 1 ;
F_51 ( & V_18 -> V_20 ) ;
V_102 = ( ( V_18 -> V_104 << 1 ) | F_8 ( V_12 , 2 ) |
( F_15 ( V_12 , 2 ) << 5 ) | ( V_105 << 4 ) ) ;
if ( V_90 > sizeof( V_102 ) )
V_90 = sizeof( V_102 ) ;
memcpy ( V_69 , ( char * ) & V_102 , V_90 ) ;
F_52 ( & V_18 -> V_20 ) ;
return 0 ;
}
void F_56 ( struct V_56 * V_50 )
{
int V_64 ;
struct V_15 * V_3 ;
F_51 ( & V_50 -> V_18 . V_20 ) ;
V_50 -> V_18 . V_77 = 0 ;
for ( V_64 = 0 ; V_64 < 3 ; V_64 ++ ) {
V_3 = & V_50 -> V_18 . V_19 [ V_64 ] ;
V_3 -> V_21 = 0xff ;
V_3 -> V_22 = ( V_64 != 2 ) ;
F_45 ( V_50 -> V_12 , V_64 , 0 ) ;
}
F_52 ( & V_50 -> V_18 . V_20 ) ;
F_42 ( & V_50 -> V_18 . V_28 . V_49 , 0 ) ;
V_50 -> V_18 . V_53 = 1 ;
}
static void F_57 ( struct V_106 * V_107 , bool V_108 )
{
struct V_56 * V_50 = F_19 ( V_107 , struct V_56 , V_109 ) ;
if ( ! V_108 ) {
F_42 ( & V_50 -> V_18 . V_28 . V_49 , 0 ) ;
V_50 -> V_18 . V_53 = 1 ;
}
}
struct V_56 * F_58 ( struct V_12 * V_12 , T_2 V_77 )
{
struct V_56 * V_50 ;
struct V_26 * V_18 ;
int V_102 ;
V_50 = F_59 ( sizeof( struct V_56 ) , V_110 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_66 = F_60 ( V_12 ) ;
if ( V_50 -> V_66 < 0 ) {
F_61 ( V_50 ) ;
return NULL ;
}
F_62 ( & V_50 -> V_18 . V_20 ) ;
F_51 ( & V_50 -> V_18 . V_20 ) ;
F_63 ( & V_50 -> V_18 . V_48 ) ;
V_50 -> V_51 = F_64 ( L_4 ) ;
if ( ! V_50 -> V_51 ) {
F_52 ( & V_50 -> V_18 . V_20 ) ;
F_65 ( V_12 , V_50 -> V_66 ) ;
F_61 ( V_50 ) ;
return NULL ;
}
F_66 ( & V_50 -> V_52 , F_32 ) ;
V_12 -> V_16 . V_17 = V_50 ;
V_50 -> V_12 = V_12 ;
V_18 = & V_50 -> V_18 ;
V_18 -> V_50 = V_50 ;
F_67 ( & V_18 -> V_28 . V_30 ,
V_111 , V_58 ) ;
V_18 -> V_46 . V_112 = 0 ;
V_18 -> V_46 . V_113 = F_18 ;
F_68 ( V_12 , & V_18 -> V_46 ) ;
V_18 -> V_28 . V_71 = true ;
F_52 ( & V_50 -> V_18 . V_20 ) ;
F_56 ( V_50 ) ;
V_50 -> V_109 . V_114 = F_57 ;
F_69 ( V_12 , 0 , & V_50 -> V_109 ) ;
F_70 ( & V_50 -> V_84 , & V_115 ) ;
V_102 = F_71 ( V_12 , V_116 , V_87 ,
V_88 , & V_50 -> V_84 ) ;
if ( V_102 < 0 )
goto V_117;
if ( V_77 & V_118 ) {
F_70 ( & V_50 -> V_85 , & V_119 ) ;
V_102 = F_71 ( V_12 , V_116 ,
V_103 , 4 ,
& V_50 -> V_85 ) ;
if ( V_102 < 0 )
goto V_120;
}
return V_50 ;
V_120:
F_72 ( V_12 , V_116 , & V_50 -> V_84 ) ;
V_117:
F_73 ( V_12 , 0 , & V_50 -> V_109 ) ;
F_74 ( V_12 , & V_18 -> V_46 ) ;
F_65 ( V_12 , V_50 -> V_66 ) ;
F_75 ( V_50 -> V_51 ) ;
F_61 ( V_50 ) ;
return NULL ;
}
void F_76 ( struct V_12 * V_12 )
{
struct V_57 * V_30 ;
if ( V_12 -> V_16 . V_17 ) {
F_72 ( V_12 , V_116 , & V_12 -> V_16 . V_17 -> V_84 ) ;
F_72 ( V_12 , V_116 ,
& V_12 -> V_16 . V_17 -> V_85 ) ;
F_73 ( V_12 , 0 ,
& V_12 -> V_16 . V_17 -> V_109 ) ;
F_74 ( V_12 ,
& V_12 -> V_16 . V_17 -> V_18 . V_46 ) ;
F_51 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ;
V_30 = & V_12 -> V_16 . V_17 -> V_18 . V_28 . V_30 ;
F_27 ( V_30 ) ;
F_30 ( & V_12 -> V_16 . V_17 -> V_52 ) ;
F_65 ( V_12 , V_12 -> V_16 . V_17 -> V_66 ) ;
F_52 ( & V_12 -> V_16 . V_17 -> V_18 . V_20 ) ;
F_75 ( V_12 -> V_16 . V_17 -> V_51 ) ;
F_61 ( V_12 -> V_16 . V_17 ) ;
}
}
