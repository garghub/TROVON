static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned char * V_5 ;
if ( V_2 -> V_6 == 0 ) {
V_5 = V_2 -> V_7 ;
if ( V_5 [ 0 ] & V_8 )
F_2 ( V_4 , V_9 ) ;
else
F_2 ( V_4 , V_10 ) ;
if ( V_5 [ 1 ] & V_11 )
V_4 -> V_12 |= F_3 ( ~ 0 ) ;
else
V_4 -> V_12 &= ~ F_3 ( ~ 0 ) ;
} else
F_4 ( 4 , L_1 ,
V_2 -> V_6 ) ;
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_7 ( 1 , 32 ) ;
if ( F_8 ( V_2 ) ) {
F_9 ( 6 , L_2 ) ;
return F_10 ( V_2 ) ;
}
V_2 -> V_13 = V_14 ;
F_11 ( V_2 -> V_15 , V_16 , 32 , V_2 -> V_7 ) ;
V_6 = F_12 ( V_4 , V_2 ) ;
F_1 ( V_2 ) ;
return V_6 ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( 1 , 32 ) ;
if ( F_8 ( V_2 ) ) {
F_9 ( 6 , L_2 ) ;
return;
}
V_2 -> V_13 = V_14 ;
F_11 ( V_2 -> V_15 , V_16 , 32 , V_2 -> V_7 ) ;
V_2 -> V_17 = ( void * ) F_1 ;
V_2 -> V_18 = NULL ;
F_14 ( V_4 , V_2 ) ;
}
static void
F_15 ( struct V_19 * V_20 )
{
struct V_21 * V_22 =
F_16 ( V_20 , struct V_21 , V_20 ) ;
struct V_3 * V_4 = V_22 -> V_4 ;
switch( V_22 -> V_13 ) {
case V_14 :
F_13 ( V_4 ) ;
break;
default:
F_4 ( 3 , L_3 ) ;
}
F_17 ( V_4 ) ;
F_18 ( V_22 ) ;
}
static int
F_19 ( struct V_3 * V_4 , enum V_23 V_13 )
{
struct V_21 * V_22 ;
if ( ( V_22 = F_20 ( sizeof( * V_22 ) , V_24 ) ) == NULL )
return - V_25 ;
F_21 ( & V_22 -> V_20 , F_15 ) ;
V_22 -> V_4 = F_22 ( V_4 ) ;
V_22 -> V_13 = V_13 ;
F_23 ( & V_22 -> V_20 ) ;
return 0 ;
}
static inline int
F_24 ( struct V_1 * V_2 )
{
F_4 ( 6 , L_4 , V_26 [ V_2 -> V_13 ] ) ;
switch ( V_2 -> V_13 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
F_25 ( V_2 -> V_4 , 0 ) ;
break;
default:
;
}
return V_33 ;
}
static inline int
F_26 ( struct V_1 * V_2 , int V_6 )
{
F_4 ( 3 , L_5 ,
V_26 [ V_2 -> V_13 ] , V_6 ) ;
return V_6 ;
}
static inline int
F_27 ( struct V_1 * V_2 )
{
F_4 ( 3 , L_6 ,
V_26 [ V_2 -> V_13 ] ) ;
return F_24 ( V_2 ) ;
}
static inline int
F_28 ( struct V_1 * V_2 )
{
F_4 ( 3 , L_7 , V_26 [ V_2 -> V_13 ] ) ;
return V_34 ;
}
static int
F_29 ( struct V_3 * V_4 , struct V_35 * V_35 )
{
if ( V_35 -> V_36 . V_37 . V_38 == 0x85 ) {
F_4 ( 6 , L_8 ) ;
F_25 ( V_4 , 0 ) ;
F_19 ( V_4 , V_14 ) ;
} else {
F_4 ( 3 , L_9 , V_4 -> V_39 ) ;
F_30 ( V_4 , NULL , V_35 ) ;
}
return V_33 ;
}
static int
F_31 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_13 == V_40 ) {
F_32 ( V_4 , V_2 ) ;
return F_28 ( V_2 ) ;
}
return F_26 ( V_2 , - V_41 ) ;
}
static int
F_33 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_35 * V_35 , int V_42 )
{
if ( V_2 -> V_13 != V_31 ) {
F_34 ( & V_4 -> V_43 -> V_44 , L_10
L_11 , V_42 ) ;
F_30 ( V_4 , V_2 , V_35 ) ;
}
return F_26 ( V_2 , - V_41 ) ;
}
static int
F_35 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
if ( V_35 -> V_45 [ 3 ] == 0x40 ) {
F_36 ( & V_4 -> V_43 -> V_44 , L_12
L_13 ) ;
return F_26 ( V_2 , - V_41 ) ;
}
return F_33 ( V_4 , V_2 , V_35 , - 1 ) ;
}
static int
F_37 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_35 * V_35 )
{
if ( V_35 -> V_45 [ 3 ] == 0x41 ) {
F_36 ( & V_4 -> V_43 -> V_44 , L_14
L_15 ) ;
return F_26 ( V_2 , - V_41 ) ;
}
return F_33 ( V_4 , V_2 , V_35 , - 2 ) ;
}
static int
F_38 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
int V_46 ;
T_1 * V_5 ;
V_46 = ( * V_4 -> V_47 & 0x80 ) ? 1 : 0 ;
V_5 = V_35 -> V_45 ;
#ifdef F_39
if ( V_2 -> V_13 == V_48 ) {
V_4 -> V_49 . V_50 = - 1 ;
if ( V_2 -> V_51 -- <= 0 )
return F_26 ( V_2 , - V_41 ) ;
else
return F_28 ( V_2 ) ;
}
#endif
if (
V_5 [ 0 ] & V_52 &&
V_5 [ 1 ] & V_11
) {
if (
V_2 -> V_13 == V_27 ||
V_2 -> V_13 == V_29 ||
V_2 -> V_13 == V_30
) {
return F_26 ( V_2 , - V_53 ) ;
} else {
return F_33 ( V_4 , V_2 , V_35 , - 3 ) ;
}
}
if ( (
V_5 [ 0 ] == V_54 ||
V_5 [ 0 ] == V_55 ||
V_5 [ 0 ] == V_55 + V_56
) && (
V_5 [ 1 ] == V_57 ||
V_5 [ 1 ] == V_58 + V_59
) ) {
switch ( V_2 -> V_13 ) {
case V_60 :
case V_61 :
return F_26 ( V_2 , - V_62 ) ;
case V_63 :
return F_28 ( V_2 ) ;
case V_64 :
F_25 ( V_4 , 0 ) ;
return F_26 ( V_2 , - V_41 ) ;
case V_40 :
return F_26 ( V_2 , 0 ) ;
case V_29 :
return F_26 ( V_2 , - V_62 ) ;
default:
return F_26 ( V_2 , 0 ) ;
}
}
if ( V_5 [ 0 ] & V_65 )
return F_28 ( V_2 ) ;
if ( V_5 [ 0 ] & V_54 ) {
switch ( V_5 [ 3 ] ) {
case 0x23 :
if ( ( V_5 [ 2 ] & V_66 ) ||
V_46 )
return F_33 ( V_4 , V_2 ,
V_35 , - 4 ) ;
F_36 ( & V_4 -> V_43 -> V_44 , L_16
L_17 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x25 :
if ( ( V_5 [ 2 ] & V_66 ) ||
V_46 )
return F_33 ( V_4 , V_2 ,
V_35 , - 5 ) ;
F_36 ( & V_4 -> V_43 -> V_44 , L_18
L_19 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x26 :
return F_31 ( V_4 , V_2 ) ;
case 0x28 :
F_36 ( & V_4 -> V_43 -> V_44 , L_20
L_21 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x31 :
F_36 ( & V_4 -> V_43 -> V_44 , L_22
L_23 ) ;
return F_26 ( V_2 , - V_62 ) ;
case 0x41 :
F_36 ( & V_4 -> V_43 -> V_44 , L_24
L_25 ) ;
return F_26 ( V_2 , - V_41 ) ;
default:
if ( V_4 -> V_43 -> V_67 . V_68 == V_69 )
return F_33 ( V_4 , V_2 ,
V_35 , - 6 ) ;
}
}
if ( V_5 [ 0 ] & V_70 )
return F_35 ( V_4 , V_2 , V_35 ) ;
if ( V_5 [ 1 ] & V_71 )
return F_37 ( V_4 , V_2 , V_35 ) ;
switch ( V_5 [ 3 ] ) {
case 0x00 :
return V_33 ;
case 0x21 :
return F_28 ( V_2 ) ;
case 0x22 :
F_36 ( & V_4 -> V_43 -> V_44 , L_26
L_27 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x24 :
return F_27 ( V_2 ) ;
case 0x27 :
return F_28 ( V_2 ) ;
case 0x29 :
return F_26 ( V_2 , - V_41 ) ;
case 0x2a :
return F_28 ( V_2 ) ;
case 0x2b :
if ( V_2 -> V_13 == V_28 ) {
F_2 ( V_4 , V_9 ) ;
return F_27 ( V_2 ) ;
}
return F_33 ( V_4 , V_2 , V_35 , V_5 [ 3 ] ) ;
case 0x2c :
return F_26 ( V_2 , - V_41 ) ;
case 0x2d :
if ( V_2 -> V_13 == V_27 )
return F_26 ( V_2 , - V_41 ) ;
return F_33 ( V_4 , V_2 , V_35 , V_5 [ 3 ] ) ;
case 0x2e :
F_36 ( & V_4 -> V_43 -> V_44 , L_28
L_29 ) ;
return F_26 ( V_2 , - V_72 ) ;
case 0x30 :
F_36 ( & V_4 -> V_43 -> V_44 , L_30
L_31 ) ;
return F_26 ( V_2 , - V_53 ) ;
case 0x32 :
F_36 ( & V_4 -> V_43 -> V_44 , L_32
L_33 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x33 :
F_36 ( & V_4 -> V_43 -> V_44 , L_34
L_35 ) ;
F_25 ( V_4 , 0 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x34 :
F_36 ( & V_4 -> V_43 -> V_44 , L_36
L_37 ) ;
if ( V_2 -> V_13 == V_28 )
return F_26 ( V_2 , - V_41 ) ;
return F_33 ( V_4 , V_2 , V_35 , V_5 [ 3 ] ) ;
case 0x35 :
F_36 ( & V_4 -> V_43 -> V_44 , L_38
L_39 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x36 :
if ( V_4 -> V_43 -> V_67 . V_68 == V_73 )
return F_26 ( V_2 , - V_41 ) ;
return F_33 ( V_4 , V_2 , V_35 , V_5 [ 3 ] ) ;
case 0x37 :
F_36 ( & V_4 -> V_43 -> V_44 , L_40
L_41 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x38 :
if ( V_2 -> V_13 == V_29 ||
V_2 -> V_13 == V_27 ||
V_2 -> V_13 == V_30 )
return F_26 ( V_2 , - V_62 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x39 :
return F_26 ( V_2 , - V_41 ) ;
case 0x3a :
F_36 ( & V_4 -> V_43 -> V_44 , L_42 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x3b :
F_36 ( & V_4 -> V_43 -> V_44 , L_43
L_44 ) ;
F_25 ( V_4 , 0 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x42 :
F_36 ( & V_4 -> V_43 -> V_44 , L_45
L_46 ) ;
return F_28 ( V_2 ) ;
case 0x43 :
F_25 ( V_4 , 0 ) ;
F_2 ( V_4 , V_9 ) ;
if ( V_5 [ 1 ] & V_57 ) {
switch( V_2 -> V_13 ) {
case V_31 :
case V_32 :
case V_74 :
case V_75 :
return F_24 ( V_2 ) ;
break;
default:
break;
}
}
return F_26 ( V_2 , - V_76 ) ;
case 0x44 :
if ( V_2 -> V_13 != V_48 && V_2 -> V_13 != V_64 )
return F_33 ( V_4 , V_2 ,
V_35 , V_5 [ 3 ] ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x45 :
F_36 ( & V_4 -> V_43 -> V_44 , L_47
L_48 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x46 :
F_36 ( & V_4 -> V_43 -> V_44 , L_49 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x47 :
F_36 ( & V_4 -> V_43 -> V_44 , L_50
L_51 ) ;
F_25 ( V_4 , 0 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x48 :
return F_28 ( V_2 ) ;
case 0x49 :
F_36 ( & V_4 -> V_43 -> V_44 , L_52
L_53 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x4a :
F_36 ( & V_4 -> V_43 -> V_44 , L_54
L_55 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x4b :
F_36 ( & V_4 -> V_43 -> V_44 , L_56
L_57 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x4c :
return F_28 ( V_2 ) ;
case 0x4d :
if ( V_4 -> V_43 -> V_67 . V_68 == V_73 )
return F_28 ( V_2 ) ;
return F_33 ( V_4 , V_2 , V_35 , V_5 [ 3 ] ) ;
case 0x4e :
if ( V_4 -> V_43 -> V_67 . V_68 == V_73 ) {
F_36 ( & V_4 -> V_43 -> V_44 , L_58
L_59 ) ;
return F_26 ( V_2 , - V_77 ) ;
}
return F_33 ( V_4 , V_2 , V_35 , V_5 [ 3 ] ) ;
case 0x50 :
return F_28 ( V_2 ) ;
case 0x51 :
return F_28 ( V_2 ) ;
case 0x52 :
if ( V_2 -> V_13 == V_28 ) {
F_2 ( V_4 , V_9 ) ;
F_25 ( V_4 , 0 ) ;
return F_27 ( V_2 ) ;
}
return F_33 ( V_4 , V_2 , V_35 , V_5 [ 3 ] ) ;
case 0x53 :
return F_28 ( V_2 ) ;
case 0x54 :
return F_28 ( V_2 ) ;
case 0x55 :
F_36 ( & V_4 -> V_43 -> V_44 , L_60
L_61 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x56 :
F_36 ( & V_4 -> V_43 -> V_44 , L_62
L_63 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x57 :
if ( V_4 -> V_43 -> V_67 . V_68 == V_69 ) {
return F_28 ( V_2 ) ;
} else {
return F_28 ( V_2 ) ;
}
case 0x5a :
F_36 ( & V_4 -> V_43 -> V_44 , L_64
L_65 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x5b :
if ( V_5 [ 1 ] & V_58 )
return F_28 ( V_2 ) ;
F_36 ( & V_4 -> V_43 -> V_44 , L_66
L_67 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x5c :
F_36 ( & V_4 -> V_43 -> V_44 , L_68
L_69 ) ;
return F_26 ( V_2 , - V_41 ) ;
case 0x5d :
F_36 ( & V_4 -> V_43 -> V_44 , L_66
L_70 ) ;
return F_26 ( V_2 , - V_72 ) ;
case 0x5e :
F_36 ( & V_4 -> V_43 -> V_44 , L_66
L_71 ) ;
return F_26 ( V_2 , - V_72 ) ;
case 0x23 :
case 0x25 :
case 0x26 :
case 0x28 :
case 0x31 :
case 0x40 :
case 0x41 :
default:
return F_33 ( V_4 , V_2 , V_35 , V_5 [ 3 ] ) ;
}
}
static int
F_40 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
if ( V_2 == NULL )
return F_29 ( V_4 , V_35 ) ;
if ( ( V_35 -> V_36 . V_37 . V_38 & V_78 ) &&
( V_35 -> V_36 . V_37 . V_38 & V_79 ) &&
( V_2 -> V_13 == V_29 ) ) {
return F_26 ( V_2 , - V_62 ) ;
}
if ( V_35 -> V_36 . V_37 . V_38 & V_80 )
return F_38 ( V_4 , V_2 , V_35 ) ;
if ( V_35 -> V_36 . V_37 . V_38 & V_79 ) {
if ( V_35 -> V_36 . V_37 . V_38 & V_78 ) {
if ( V_2 -> V_13 == V_63 || V_2 -> V_13 == V_61 )
V_2 -> V_81 ++ ;
else
F_4 ( 5 , L_72 ) ;
}
return F_24 ( V_2 ) ;
}
F_4 ( 6 , L_73 ) ;
F_30 ( V_4 , V_2 , V_35 ) ;
return V_82 ;
}
static int
F_41 ( struct V_3 * V_4 , unsigned int V_37 , unsigned long V_83 )
{
if ( V_37 == V_84 ) {
struct V_85 V_86 ;
if ( F_42 ( & V_86 , ( char V_87 * ) V_83 , sizeof( V_86 ) ) != 0 )
return - V_88 ;
return F_43 ( V_4 , & V_86 ) ;
} else
return - V_89 ;
}
static inline void
F_44 ( struct V_90 V_91 , struct V_92 * V_93 )
{
struct V_94 * V_95 ;
V_95 = F_45 ( sizeof( * V_95 ) , V_24 ) ;
if ( ! V_95 )
return;
V_95 -> V_91 = V_91 ;
F_46 ( & V_95 -> V_96 , V_93 ) ;
}
static void
F_47 ( struct V_3 * V_4 , struct V_90 V_91 )
{
struct V_92 * V_97 ;
struct V_94 * V_98 ;
struct V_92 * V_93 ;
V_97 = (struct V_92 * ) V_4 -> V_99 ;
if ( ! V_97 || ( V_91 . V_100 < 2 && V_91 . V_101 == 0 ) )
return;
F_48 (l, sbid_list) {
V_98 = F_49 ( V_93 , struct V_94 , V_96 ) ;
if (
( V_98 -> V_91 . V_100 == V_91 . V_100 ) &&
( V_98 -> V_91 . V_101 == V_91 . V_101 )
) {
if ( V_91 . V_102 < V_98 -> V_91 . V_102 )
V_98 -> V_91 = V_91 ;
else return;
break;
}
if ( V_91 . V_102 < V_98 -> V_91 . V_102 ) {
F_44 ( V_91 , V_93 -> V_103 ) ;
break;
}
}
if ( V_93 == V_97 )
F_44 ( V_91 , V_93 -> V_103 ) ;
F_50 ( 4 , L_74 ) ;
F_48 (l, sbid_list) {
V_98 = F_49 ( V_93 , struct V_94 , V_96 ) ;
F_50 ( 4 , L_75 ,
V_98 -> V_91 . V_101 ,
V_98 -> V_91 . V_100 ,
V_98 -> V_91 . V_102
) ;
}
}
static void
F_25 ( struct V_3 * V_4 , int V_104 )
{
struct V_92 * V_97 ;
struct V_94 * V_98 ;
struct V_92 * V_93 ;
struct V_92 * V_105 ;
V_97 = (struct V_92 * ) V_4 -> V_99 ;
if ( ! V_97 )
return;
F_51 (l, n, sbid_list) {
V_98 = F_49 ( V_93 , struct V_94 , V_96 ) ;
if ( V_98 -> V_91 . V_102 >= V_104 ) {
F_50 ( 4 , L_76 ,
V_98 -> V_91 . V_101 ,
V_98 -> V_91 . V_100 ,
V_98 -> V_91 . V_102
) ;
F_52 ( V_93 ) ;
F_18 ( V_98 ) ;
}
}
}
static void
F_53 (
struct V_3 * V_4 ,
struct V_90 * V_91
) {
struct V_94 * V_98 ;
struct V_94 * V_106 ;
struct V_92 * V_97 ;
struct V_92 * V_93 ;
V_97 = (struct V_92 * ) V_4 -> V_99 ;
V_91 -> V_101 = 0 ;
V_91 -> V_100 = 1 ;
if ( ! V_97 || F_54 ( V_97 ) )
return;
V_106 = NULL ;
F_48 (l, sbid_list) {
V_98 = F_49 ( V_93 , struct V_94 , V_96 ) ;
if ( V_98 -> V_91 . V_102 >= V_91 -> V_102 )
break;
V_106 = V_98 ;
}
if ( V_106 ) {
V_91 -> V_101 = V_106 -> V_91 . V_101 ;
V_91 -> V_100 = V_106 -> V_91 . V_100 ;
F_50 ( 4 , L_77 ,
V_106 -> V_91 . V_101 ,
V_106 -> V_91 . V_100 ,
V_106 -> V_91 . V_102 ,
V_91 -> V_102
) ;
}
}
static int
F_55 ( struct V_3 * V_4 )
{
int V_6 ;
struct V_92 * V_99 ;
F_4 ( 6 , L_78 ) ;
if ( ( V_6 = F_56 ( V_4 ) ) == 0 ) {
if ( ( V_6 = F_6 ( V_4 ) ) != 0 ) {
F_50 ( 3 , L_79 , V_6 ) ;
}
}
V_99 = F_45 ( sizeof( struct V_92 ) , V_107 ) ;
if ( V_99 ) {
F_57 ( V_99 ) ;
V_4 -> V_99 = V_99 ;
}
return V_6 ;
}
static void
F_58 ( struct V_3 * V_4 )
{
F_59 ( V_4 ) ;
if ( V_4 -> V_99 ) {
F_25 ( V_4 , 0 ) ;
F_18 ( V_4 -> V_99 ) ;
V_4 -> V_99 = NULL ;
}
}
static int
F_60 ( struct V_3 * V_4 , int V_108 )
{
struct {
struct V_90 V_109 ;
struct V_90 V_110 ;
} V_111 ( ( V_112 ) ) V_113 ;
int V_6 ;
V_6 = F_61 ( V_4 , ( V_114 * ) & V_113 ) ;
if ( V_6 )
return V_6 ;
F_47 ( V_4 , V_113 . V_109 ) ;
return V_113 . V_109 . V_102 ;
}
static int
F_62 ( struct V_3 * V_4 , int V_108 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 ;
if ( V_108 > 0x3fffff ) {
F_9 ( 6 , L_80 ) ;
return - V_89 ;
}
V_2 = F_7 ( 3 , 4 ) ;
if ( F_8 ( V_2 ) )
return F_10 ( V_2 ) ;
V_2 -> V_13 = V_64 ;
V_91 = (struct V_90 * ) V_2 -> V_7 ;
V_91 -> V_115 = ( * V_4 -> V_47 & 0x08 ) ?
V_116 : V_117 ;
V_91 -> V_102 = V_108 ;
F_53 ( V_4 , V_91 ) ;
F_63 ( V_2 -> V_15 , V_118 , 1 , V_4 -> V_47 ) ;
F_63 ( V_2 -> V_15 + 1 , V_119 , 4 , V_2 -> V_7 ) ;
F_11 ( V_2 -> V_15 + 2 , V_120 , 0 , NULL ) ;
return F_64 ( V_4 , V_2 ) ;
}
static struct V_1 *
F_65 ( struct V_3 * V_4 , struct V_2 * V_121 )
{
struct V_1 * V_2 ;
struct V_122 * V_123 ;
int V_124 = 0 ;
unsigned V_125 ;
char * V_126 ;
struct V_127 * V_128 ;
struct V_129 V_130 ;
struct V_90 * V_131 ;
F_4 ( 6 , L_81 ) ;
F_66 (bv, req, iter)
V_124 += V_128 -> V_132 >> ( V_133 + 9 ) ;
V_2 = F_7 ( 3 + V_124 + 1 , 8 ) ;
if ( F_8 ( V_2 ) )
return V_2 ;
V_2 -> V_13 = V_48 ;
V_131 = (struct V_90 * ) V_2 -> V_7 ;
V_131 -> V_102 = F_67 ( V_121 ) >> V_133 ;
F_4 ( 6 , L_82 , V_131 -> V_102 ) ;
V_123 = V_2 -> V_15 ;
V_123 = F_63 ( V_123 , V_118 , 1 , V_4 -> V_47 ) ;
V_123 = F_63 ( V_123 , V_120 , 0 , NULL ) ;
V_123 = F_63 ( V_123 , V_120 , 0 , NULL ) ;
F_66 (bv, req, iter) {
V_126 = F_68 ( V_128 -> V_134 ) + V_128 -> V_135 ;
for ( V_125 = 0 ; V_125 < V_128 -> V_132 ; V_125 += V_136 ) {
V_123 -> V_137 = V_138 ;
V_123 -> V_139 = V_140 ;
V_123 -> V_124 = V_136 ;
F_69 ( V_123 , ( void * ) F_70 ( V_126 ) ) ;
V_123 ++ ;
V_126 += V_136 ;
}
}
V_123 = F_11 ( V_123 , V_120 , 0 , NULL ) ;
F_4 ( 6 , L_83 ) ;
return V_2 ;
}
static void
F_71 ( struct V_1 * V_2 )
{
struct V_122 * V_123 ;
V_123 = V_2 -> V_15 ;
if ( ( V_123 + 2 ) -> V_139 == V_141 ) {
struct {
struct V_90 V_109 ;
struct V_90 V_110 ;
} V_111 ( ( V_112 ) ) * V_142 ;
V_142 = V_2 -> V_7 ;
if ( V_2 -> V_4 )
F_47 ( V_2 -> V_4 , V_142 -> V_109 ) ;
}
for (; V_123 -> V_137 & V_138 ; V_123 ++ )
if ( V_123 -> V_139 == V_140 )
F_72 ( V_123 ) ;
F_5 ( V_2 ) ;
}
static void
F_73 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_90 * V_131 ;
V_131 = (struct V_90 * ) V_2 -> V_7 ;
if ( V_131 -> V_102 == V_4 -> V_49 . V_50 )
return;
F_50 ( 4 , L_84 , V_131 -> V_102 , V_4 -> V_143 ) ;
V_131 -> V_101 = 0 ;
V_131 -> V_100 = 1 ;
V_131 -> V_115 = ( * V_4 -> V_47 & 0x08 ) ?
V_116 :
V_117 ;
V_131 -> V_102 = V_131 -> V_102 + V_4 -> V_143 ;
F_53 ( V_4 , V_131 ) ;
F_63 ( V_2 -> V_15 + 1 , V_119 , 4 , V_2 -> V_7 ) ;
F_63 ( V_2 -> V_15 + 2 , V_141 , 8 , V_2 -> V_7 ) ;
}
static int
F_74 ( struct V_144 * V_43 )
{
return F_75 (
F_76 ( & V_43 -> V_44 ) ,
& V_145
) ;
}
static int
F_77 ( void )
{
int V_6 ;
V_146 = F_78 ( L_85 , 2 , 2 , 4 * sizeof( long ) ) ;
F_79 ( V_146 , & V_147 ) ;
#ifdef F_80
F_81 ( V_146 , 6 ) ;
#endif
F_4 ( 3 , L_86 ) ;
V_6 = F_82 ( & V_148 ) ;
if ( V_6 )
F_4 ( 3 , L_87 ) ;
else
F_4 ( 3 , L_88 ) ;
return V_6 ;
}
static void
F_83 ( void )
{
F_84 ( & V_148 ) ;
F_85 ( V_146 ) ;
}
