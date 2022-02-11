static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 [ V_3 ] ;
switch ( V_6 -> V_9 ) {
default:
case 0 :
case 4 :
break;
case 1 :
case 2 :
case 3 :
case 5 :
if ( V_6 -> V_10 < V_4 )
V_6 -> V_11 = F_2 () ;
break;
}
V_6 -> V_10 = V_4 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_7 . V_8 [ V_3 ] . V_10 ;
}
static T_2 F_4 ( struct V_1 * V_2 )
{
T_2 V_12 ;
T_3 V_13 ;
struct V_14 * V_15 = & V_2 -> V_7 ;
if ( ! V_15 -> V_16 )
return 0 ;
V_13 = F_5 ( & V_15 -> V_17 ) ;
V_12 = V_15 -> V_16 - F_6 ( V_13 ) ;
return V_12 ;
}
static T_2 F_7 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_3 )
{
if ( V_3 == 0 )
return F_4 ( V_2 ) ;
return F_6 ( F_8 ( F_2 () , V_6 -> V_11 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 [ V_3 ] ;
T_2 V_18 , V_19 ;
int V_20 ;
V_19 = F_7 ( V_2 , V_6 , V_3 ) ;
V_18 = F_10 ( V_19 , V_21 , V_22 ) ;
switch ( V_6 -> V_9 ) {
case 0 :
case 1 :
case 4 :
case 5 :
V_20 = ( V_6 -> V_23 - V_18 ) & 0xffff ;
break;
case 3 :
V_20 = V_6 -> V_23 - ( F_11 ( ( 2 * V_18 ) , V_6 -> V_23 ) ) ;
break;
default:
V_20 = V_6 -> V_23 - F_11 ( V_18 , V_6 -> V_23 ) ;
break;
}
return V_20 ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 [ V_3 ] ;
T_2 V_18 , V_19 ;
int V_24 ;
V_19 = F_7 ( V_2 , V_6 , V_3 ) ;
V_18 = F_10 ( V_19 , V_21 , V_22 ) ;
switch ( V_6 -> V_9 ) {
default:
case 0 :
V_24 = ( V_18 >= V_6 -> V_23 ) ;
break;
case 1 :
V_24 = ( V_18 < V_6 -> V_23 ) ;
break;
case 2 :
V_24 = ( ( F_11 ( V_18 , V_6 -> V_23 ) == 0 ) && ( V_18 != 0 ) ) ;
break;
case 3 :
V_24 = ( F_11 ( V_18 , V_6 -> V_23 ) < ( ( V_6 -> V_23 + 1 ) >> 1 ) ) ;
break;
case 4 :
case 5 :
V_24 = ( V_18 == V_6 -> V_23 ) ;
break;
}
return V_24 ;
}
static void F_13 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 [ V_3 ] ;
if ( ! V_6 -> V_25 ) {
V_6 -> V_26 = F_9 ( V_2 , V_3 ) ;
V_6 -> V_25 = V_6 -> V_27 ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 [ V_3 ] ;
if ( ! V_6 -> V_28 ) {
V_6 -> V_29 = ( ( F_12 ( V_2 , V_3 ) << 7 ) |
( V_6 -> V_27 << 4 ) |
( V_6 -> V_9 << 1 ) |
V_6 -> V_30 ) ;
V_6 -> V_28 = 1 ;
}
}
static inline struct V_1 * F_15 ( struct V_14 * V_15 )
{
return F_16 ( V_15 , struct V_1 , V_7 ) ;
}
static void F_17 ( struct V_31 * V_32 )
{
struct V_14 * V_15 = F_16 ( V_32 , struct V_14 ,
V_33 ) ;
struct V_1 * V_2 = F_15 ( V_15 ) ;
F_18 ( & V_15 -> V_34 , 1 ) ;
F_19 () ;
if ( F_20 ( & V_15 -> V_35 ) > 0 )
F_21 ( V_2 -> V_36 , & V_2 -> V_37 ) ;
}
void F_22 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 -> V_41 . V_42 ;
struct V_43 * V_17 ;
if ( ! F_23 ( V_39 ) || ! V_2 )
return;
V_17 = & V_2 -> V_7 . V_17 ;
F_24 ( & V_2 -> V_7 . V_44 ) ;
if ( F_25 ( V_17 ) )
F_26 ( V_17 , V_45 ) ;
F_27 ( & V_2 -> V_7 . V_44 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_7 . V_17 ) ;
F_29 ( & V_2 -> V_37 ) ;
}
static void F_30 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_16 ( V_47 , struct V_1 , V_37 ) ;
struct V_40 * V_40 = V_2 -> V_40 ;
struct V_38 * V_39 ;
int V_48 ;
struct V_14 * V_15 = & V_2 -> V_7 ;
if ( F_31 ( & V_15 -> V_49 ) && ! F_32 ( & V_15 -> V_34 , 0 ) )
return;
F_33 ( V_40 , V_2 -> V_50 , 0 , 1 , false ) ;
F_33 ( V_40 , V_2 -> V_50 , 0 , 0 , false ) ;
if ( F_31 ( & V_40 -> V_41 . V_51 ) > 0 )
F_34 (i, vcpu, kvm)
F_35 ( V_39 ) ;
}
static enum V_52 F_36 ( struct V_43 * V_53 )
{
struct V_14 * V_15 = F_16 ( V_53 , struct V_14 , V_17 ) ;
struct V_1 * V_54 = F_15 ( V_15 ) ;
if ( F_31 ( & V_15 -> V_49 ) )
F_37 ( & V_15 -> V_35 ) ;
F_21 ( V_54 -> V_36 , & V_54 -> V_37 ) ;
if ( V_15 -> V_55 ) {
F_38 ( & V_15 -> V_17 , V_15 -> V_16 ) ;
return V_56 ;
} else
return V_57 ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_7 . V_35 , 0 ) ;
F_18 ( & V_2 -> V_7 . V_34 , 1 ) ;
}
void F_40 ( struct V_1 * V_2 , bool V_49 )
{
struct V_14 * V_15 = & V_2 -> V_7 ;
struct V_40 * V_40 = V_2 -> V_40 ;
if ( F_31 ( & V_15 -> V_49 ) == V_49 )
return;
if ( V_49 ) {
F_39 ( V_2 ) ;
F_41 ( V_40 , & V_15 -> V_33 ) ;
F_42 ( V_40 , 0 , & V_2 -> V_58 ) ;
} else {
F_43 ( V_40 , & V_15 -> V_33 ) ;
F_44 ( V_40 , 0 , & V_2 -> V_58 ) ;
}
F_18 ( & V_15 -> V_49 , V_49 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_4 , int V_59 )
{
struct V_14 * V_15 = & V_2 -> V_7 ;
struct V_40 * V_40 = V_2 -> V_40 ;
T_2 V_60 ;
if ( ! F_46 ( V_40 ) ||
V_15 -> V_61 & V_62 )
return;
V_60 = F_10 ( V_4 , V_22 , V_21 ) ;
F_47 ( L_1 , V_60 ) ;
F_25 ( & V_15 -> V_17 ) ;
F_29 ( & V_2 -> V_37 ) ;
V_15 -> V_16 = V_60 ;
V_15 -> V_55 = V_59 ;
F_39 ( V_2 ) ;
if ( V_15 -> V_55 ) {
T_2 V_63 = V_64 * 1000LL ;
if ( V_15 -> V_16 < V_63 ) {
F_48 (
L_2
L_3 ,
V_15 -> V_16 , V_63 ) ;
V_15 -> V_16 = V_63 ;
}
}
F_49 ( & V_15 -> V_17 , F_50 ( F_2 () , V_60 ) ,
V_45 ) ;
}
static void F_51 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_14 * V_15 = & V_2 -> V_7 ;
F_47 ( L_4 , V_4 , V_3 ) ;
if ( V_4 == 0 )
V_4 = 0x10000 ;
V_15 -> V_8 [ V_3 ] . V_23 = V_4 ;
if ( V_3 != 0 ) {
V_15 -> V_8 [ V_3 ] . V_11 = F_2 () ;
return;
}
switch ( V_15 -> V_8 [ 0 ] . V_9 ) {
case 0 :
case 1 :
case 4 :
F_45 ( V_2 , V_4 , 0 ) ;
break;
case 2 :
case 3 :
F_45 ( V_2 , V_4 , 1 ) ;
break;
default:
F_28 ( V_2 ) ;
}
}
void F_52 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
int V_65 )
{
T_4 V_66 ;
F_53 ( ! F_54 ( & V_2 -> V_7 . V_44 ) ) ;
if ( V_65 ) {
F_55 ( V_3 != 0 ) ;
V_66 = V_2 -> V_7 . V_8 [ 0 ] . V_9 ;
V_2 -> V_7 . V_8 [ 0 ] . V_9 = 0xff ;
F_51 ( V_2 , V_3 , V_4 ) ;
V_2 -> V_7 . V_8 [ 0 ] . V_9 = V_66 ;
} else {
F_51 ( V_2 , V_3 , V_4 ) ;
}
}
static inline struct V_1 * F_56 ( struct V_67 * V_68 )
{
return F_16 ( V_68 , struct V_1 , V_68 ) ;
}
static inline struct V_1 * F_57 ( struct V_67 * V_68 )
{
return F_16 ( V_68 , struct V_1 , V_69 ) ;
}
static inline int F_58 ( T_5 V_70 )
{
return ( ( V_70 >= V_71 ) &&
( V_70 < V_71 + V_72 ) ) ;
}
static int F_59 ( struct V_38 * V_39 ,
struct V_67 * V_73 ,
T_5 V_70 , int V_74 , const void * V_53 )
{
struct V_1 * V_2 = F_56 ( V_73 ) ;
struct V_14 * V_7 = & V_2 -> V_7 ;
int V_3 , V_75 ;
struct V_5 * V_76 ;
T_1 V_4 = * ( T_1 * ) V_53 ;
if ( ! F_58 ( V_70 ) )
return - V_77 ;
V_4 &= 0xff ;
V_70 &= V_78 ;
F_24 ( & V_7 -> V_44 ) ;
if ( V_4 != 0 )
F_47 ( L_5 ,
( unsigned int ) V_70 , V_74 , V_4 ) ;
if ( V_70 == 3 ) {
V_3 = V_4 >> 6 ;
if ( V_3 == 3 ) {
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_76 = & V_7 -> V_8 [ V_3 ] ;
if ( V_4 & ( 2 << V_3 ) ) {
if ( ! ( V_4 & 0x20 ) )
F_13 ( V_2 , V_3 ) ;
if ( ! ( V_4 & 0x10 ) )
F_14 ( V_2 , V_3 ) ;
}
}
} else {
V_76 = & V_7 -> V_8 [ V_3 ] ;
V_75 = ( V_4 >> 4 ) & V_78 ;
if ( V_75 == 0 ) {
F_13 ( V_2 , V_3 ) ;
} else {
V_76 -> V_27 = V_75 ;
V_76 -> V_79 = V_75 ;
V_76 -> V_80 = V_75 ;
V_76 -> V_9 = ( V_4 >> 1 ) & 7 ;
if ( V_76 -> V_9 > 5 )
V_76 -> V_9 -= 4 ;
V_76 -> V_30 = V_4 & 1 ;
}
}
} else {
V_76 = & V_7 -> V_8 [ V_70 ] ;
switch ( V_76 -> V_80 ) {
default:
case V_81 :
F_51 ( V_2 , V_70 , V_4 ) ;
break;
case V_82 :
F_51 ( V_2 , V_70 , V_4 << 8 ) ;
break;
case V_83 :
V_76 -> V_84 = V_4 ;
V_76 -> V_80 = V_85 ;
break;
case V_85 :
F_51 ( V_2 , V_70 , V_76 -> V_84 | ( V_4 << 8 ) ) ;
V_76 -> V_80 = V_83 ;
break;
}
}
F_27 ( & V_7 -> V_44 ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_39 ,
struct V_67 * V_73 ,
T_5 V_70 , int V_74 , void * V_53 )
{
struct V_1 * V_2 = F_56 ( V_73 ) ;
struct V_14 * V_7 = & V_2 -> V_7 ;
int V_86 , V_23 ;
struct V_5 * V_76 ;
if ( ! F_58 ( V_70 ) )
return - V_77 ;
V_70 &= V_78 ;
if ( V_70 == 3 )
return 0 ;
V_76 = & V_7 -> V_8 [ V_70 ] ;
F_24 ( & V_7 -> V_44 ) ;
if ( V_76 -> V_28 ) {
V_76 -> V_28 = 0 ;
V_86 = V_76 -> V_29 ;
} else if ( V_76 -> V_25 ) {
switch ( V_76 -> V_25 ) {
default:
case V_81 :
V_86 = V_76 -> V_26 & 0xff ;
V_76 -> V_25 = 0 ;
break;
case V_82 :
V_86 = V_76 -> V_26 >> 8 ;
V_76 -> V_25 = 0 ;
break;
case V_83 :
V_86 = V_76 -> V_26 & 0xff ;
V_76 -> V_25 = V_82 ;
break;
}
} else {
switch ( V_76 -> V_79 ) {
default:
case V_81 :
V_23 = F_9 ( V_2 , V_70 ) ;
V_86 = V_23 & 0xff ;
break;
case V_82 :
V_23 = F_9 ( V_2 , V_70 ) ;
V_86 = ( V_23 >> 8 ) & 0xff ;
break;
case V_83 :
V_23 = F_9 ( V_2 , V_70 ) ;
V_86 = V_23 & 0xff ;
V_76 -> V_79 = V_85 ;
break;
case V_85 :
V_23 = F_9 ( V_2 , V_70 ) ;
V_86 = ( V_23 >> 8 ) & 0xff ;
V_76 -> V_79 = V_83 ;
break;
}
}
if ( V_74 > sizeof( V_86 ) )
V_74 = sizeof( V_86 ) ;
memcpy ( V_53 , ( char * ) & V_86 , V_74 ) ;
F_27 ( & V_7 -> V_44 ) ;
return 0 ;
}
static int F_61 ( struct V_38 * V_39 ,
struct V_67 * V_73 ,
T_5 V_70 , int V_74 , const void * V_53 )
{
struct V_1 * V_2 = F_57 ( V_73 ) ;
struct V_14 * V_7 = & V_2 -> V_7 ;
T_1 V_4 = * ( T_1 * ) V_53 ;
if ( V_70 != V_87 )
return - V_77 ;
F_24 ( & V_7 -> V_44 ) ;
V_7 -> V_88 = ( V_4 >> 1 ) & 1 ;
F_1 ( V_2 , 2 , V_4 & 1 ) ;
F_27 ( & V_7 -> V_44 ) ;
return 0 ;
}
static int F_62 ( struct V_38 * V_39 ,
struct V_67 * V_73 ,
T_5 V_70 , int V_74 , void * V_53 )
{
struct V_1 * V_2 = F_57 ( V_73 ) ;
struct V_14 * V_7 = & V_2 -> V_7 ;
unsigned int V_89 ;
int V_86 ;
if ( V_70 != V_87 )
return - V_77 ;
V_89 = ( ( unsigned int ) F_6 ( F_2 () ) >> 14 ) & 1 ;
F_24 ( & V_7 -> V_44 ) ;
V_86 = ( ( V_7 -> V_88 << 1 ) | F_3 ( V_2 , 2 ) |
( F_12 ( V_2 , 2 ) << 5 ) | ( V_89 << 4 ) ) ;
if ( V_74 > sizeof( V_86 ) )
V_74 = sizeof( V_86 ) ;
memcpy ( V_53 , ( char * ) & V_86 , V_74 ) ;
F_27 ( & V_7 -> V_44 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_5 * V_6 ;
V_2 -> V_7 . V_61 = 0 ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
V_6 = & V_2 -> V_7 . V_8 [ V_48 ] ;
V_6 -> V_9 = 0xff ;
V_6 -> V_10 = ( V_48 != 2 ) ;
F_51 ( V_2 , V_48 , 0 ) ;
}
F_39 ( V_2 ) ;
}
static void F_64 ( struct V_90 * V_91 , bool V_92 )
{
struct V_1 * V_2 = F_16 ( V_91 , struct V_1 , V_58 ) ;
if ( ! V_92 )
F_39 ( V_2 ) ;
}
struct V_1 * F_65 ( struct V_40 * V_40 , T_1 V_61 )
{
struct V_1 * V_2 ;
struct V_14 * V_7 ;
struct V_93 * V_93 ;
T_6 V_94 ;
int V_86 ;
V_2 = F_66 ( sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_50 = F_67 ( V_40 ) ;
if ( V_2 -> V_50 < 0 )
goto V_96;
F_68 ( & V_2 -> V_7 . V_44 ) ;
V_93 = F_69 ( F_70 ( V_97 ) ) ;
V_94 = F_71 ( V_93 ) ;
F_72 ( V_93 ) ;
V_2 -> V_36 = F_73 ( 0 , L_6 , V_94 ) ;
if ( F_74 ( V_2 -> V_36 ) )
goto V_98;
F_75 ( & V_2 -> V_37 , F_30 ) ;
V_2 -> V_40 = V_40 ;
V_7 = & V_2 -> V_7 ;
F_76 ( & V_7 -> V_17 , V_99 , V_45 ) ;
V_7 -> V_17 . V_100 = F_36 ;
V_7 -> V_33 . V_101 = 0 ;
V_7 -> V_33 . V_102 = F_17 ;
V_2 -> V_58 . V_103 = F_64 ;
F_63 ( V_2 ) ;
F_40 ( V_2 , true ) ;
F_24 ( & V_40 -> V_104 ) ;
F_77 ( & V_2 -> V_68 , & V_105 ) ;
V_86 = F_78 ( V_40 , V_106 , V_71 ,
V_72 , & V_2 -> V_68 ) ;
if ( V_86 < 0 )
goto V_107;
if ( V_61 & V_108 ) {
F_77 ( & V_2 -> V_69 , & V_109 ) ;
V_86 = F_78 ( V_40 , V_106 ,
V_87 , 4 ,
& V_2 -> V_69 ) ;
if ( V_86 < 0 )
goto V_110;
}
F_27 ( & V_40 -> V_104 ) ;
return V_2 ;
V_110:
F_79 ( V_40 , V_106 , & V_2 -> V_68 ) ;
V_107:
F_27 ( & V_40 -> V_104 ) ;
F_40 ( V_2 , false ) ;
F_80 ( V_2 -> V_36 ) ;
V_98:
F_81 ( V_40 , V_2 -> V_50 ) ;
V_96:
F_82 ( V_2 ) ;
return NULL ;
}
void F_83 ( struct V_40 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_41 . V_42 ;
if ( V_2 ) {
F_79 ( V_40 , V_106 , & V_2 -> V_68 ) ;
F_79 ( V_40 , V_106 , & V_2 -> V_69 ) ;
F_40 ( V_2 , false ) ;
F_25 ( & V_2 -> V_7 . V_17 ) ;
F_80 ( V_2 -> V_36 ) ;
F_81 ( V_40 , V_2 -> V_50 ) ;
F_82 ( V_2 ) ;
}
}
