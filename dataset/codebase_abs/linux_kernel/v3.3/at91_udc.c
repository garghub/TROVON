static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static char * V_5 [] = {
L_1 , L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 , L_8 } ;
T_1 V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 = V_4 -> V_11 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
V_6 = F_3 ( V_4 -> V_13 ) ;
F_4 ( V_2 , L_9 ) ;
F_4 ( V_2 , L_10 ,
V_4 -> V_4 . V_14 , V_4 -> V_4 . V_15 ,
V_4 -> V_16 ? L_11 : L_12 ,
V_4 -> V_17 ? L_13 : L_14 ,
V_4 -> V_18
? ( V_4 -> V_19 ? L_15 : L_16 )
: L_14 ,
V_4 -> V_20 ? L_17 : L_14 ) ;
F_4 ( V_2 , L_18 V_21 L_9 ,
V_6 ,
( V_6 & 0x07ff0000 ) >> 16 ,
( V_6 & ( 1 << 15 ) ) ? L_19 : L_20 ,
( V_6 & ( 1 << 11 ) ) ? L_21 : L_22 ,
V_5 [ ( V_6 & 0x700 ) >> 8 ] ,
( ! ( V_6 & 0x700 ) )
? ( ( V_6 & ( 1 << 7 ) ) ? L_23 : L_24 )
: L_14 ,
( V_6 & ( 1 << 6 ) ) ? L_25 : L_14 ,
( V_6 & ( 1 << 5 ) ) ? L_26 : L_14 ,
( V_6 & ( 1 << 4 ) ) ? L_27 : L_14 ,
( V_6 & ( 1 << 3 ) ) ? L_28 : L_14 ,
( V_6 & ( 1 << 2 ) ) ? L_29 : L_14 ,
( V_6 & ( 1 << 1 ) ) ? L_30 : L_14 ,
( V_6 & ( 1 << 0 ) ) ? L_31 : L_14 ) ;
if ( F_5 ( & V_4 -> V_22 ) )
F_4 ( V_2 , L_32 ) ;
else F_6 (req, &ep->queue, queue) {
unsigned V_23 = V_8 -> V_8 . V_24 ;
F_4 ( V_2 , L_33 ,
& V_8 -> V_8 , V_23 ,
V_8 -> V_8 . V_23 , V_8 -> V_8 . V_25 ) ;
}
F_7 ( & V_11 -> V_12 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 , const char * V_26 , T_1 V_27 )
{
int V_28 ;
F_4 ( V_2 , L_34 V_29 , V_26 , V_27 ,
( V_27 & ( 1 << 13 ) ) ? L_35 : L_14 ,
( V_27 & ( 1 << 12 ) ) ? L_36 : L_14 ,
( V_27 & ( 1 << 11 ) ) ? L_37 : L_14 ,
( V_27 & ( 1 << 10 ) ) ? L_38 : L_14 ,
( V_27 & ( 1 << 9 ) ) ? L_39 : L_14 ,
( V_27 & ( 1 << 8 ) ) ? L_40 : L_14 ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
if ( V_27 & ( 1 << V_28 ) )
F_4 ( V_2 , L_41 , V_28 ) ;
}
F_4 ( V_2 , L_9 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_30 )
{
struct V_10 * V_11 = V_2 -> V_31 ;
struct V_3 * V_4 ;
T_1 V_32 ;
F_4 ( V_2 , L_42 , V_33 , V_34 ) ;
F_4 ( V_2 , L_43 ,
V_11 -> V_35 ? L_44 : L_45 ,
V_11 -> V_36
? ( V_11 -> V_35 ? L_46 : L_19 )
: L_20 ,
V_11 -> V_37 ? L_47 : L_48 ,
V_11 -> V_38 ? L_49 : L_14 ,
V_11 -> V_39 ? V_11 -> V_39 -> V_39 . V_14 : L_50 ) ;
if ( ! V_11 -> V_40 ) {
F_4 ( V_2 , L_51 ) ;
return 0 ;
}
V_32 = F_10 ( V_11 , V_41 ) ;
F_4 ( V_2 , L_52 , V_32 ,
( V_32 & V_42 ) ? L_53 : L_14 ,
( V_32 & V_43 ) ? L_54 : L_14 ,
( V_32 & V_44 ) ) ;
V_32 = F_10 ( V_11 , V_45 ) ;
F_4 ( V_2 , L_55 V_29 L_9 , V_32 ,
( V_32 & V_46 ) ? L_56 : L_14 ,
( V_32 & V_47 ) ? L_57 : L_14 ,
( V_32 & V_48 ) ? L_58 : L_14 ,
( V_32 & V_49 ) ? L_59 : L_14 ,
( V_32 & V_50 ) ? L_60 : L_14 ) ;
V_32 = F_10 ( V_11 , V_51 ) ;
F_4 ( V_2 , L_61 , V_32 ,
( V_32 & V_52 ) ? L_62 : L_14 ,
( V_32 & V_53 ) ) ;
F_8 ( V_2 , L_63 , F_10 ( V_11 , V_54 ) ) ;
F_8 ( V_2 , L_64 , F_10 ( V_11 , V_55 ) ) ;
if ( V_11 -> V_36 && V_11 -> V_35 ) {
F_1 ( V_2 , & V_11 -> V_4 [ 0 ] ) ;
F_6 (ep, &udc->gadget.ep_list, ep.ep_list) {
if ( V_4 -> V_56 )
F_1 ( V_2 , V_4 ) ;
}
}
return 0 ;
}
static int F_11 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_12 ( V_58 , F_9 , F_13 ( V_57 ) -> V_59 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
V_11 -> V_60 = F_15 ( V_61 , 0 , NULL , & V_62 , V_11 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
if ( V_11 -> V_60 )
F_17 ( V_61 , NULL ) ;
}
static inline void F_14 ( struct V_10 * V_11 ) {}
static inline void F_16 ( struct V_10 * V_11 ) {}
static void F_18 ( struct V_3 * V_4 , struct V_7 * V_8 , int V_63 )
{
unsigned V_20 = V_4 -> V_20 ;
struct V_10 * V_11 = V_4 -> V_11 ;
F_19 ( & V_8 -> V_22 ) ;
if ( V_8 -> V_8 . V_63 == - V_64 )
V_8 -> V_8 . V_63 = V_63 ;
else
V_63 = V_8 -> V_8 . V_63 ;
if ( V_63 && V_63 != - V_65 )
F_20 ( L_65 , V_4 -> V_4 . V_14 , V_8 , V_63 ) ;
V_4 -> V_20 = 1 ;
F_21 ( & V_11 -> V_12 ) ;
V_8 -> V_8 . V_66 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_22 ( & V_11 -> V_12 ) ;
V_4 -> V_20 = V_20 ;
if ( F_5 ( & V_4 -> V_22 ) && V_4 -> V_67 != ( 1 << 0 ) )
F_23 ( V_11 , V_68 , V_4 -> V_67 ) ;
}
static int F_24 ( struct V_3 * V_4 , struct V_7 * V_8 )
{
T_1 T_2 * V_13 = V_4 -> V_13 ;
T_3 T_2 * V_69 = V_4 -> V_13 + ( F_25 ( 0 ) - F_26 ( 0 ) ) ;
T_1 V_6 ;
T_3 * V_25 ;
unsigned int V_70 , V_71 , V_72 ;
V_25 = V_8 -> V_8 . V_25 + V_8 -> V_8 . V_24 ;
V_71 = V_8 -> V_8 . V_23 - V_8 -> V_8 . V_24 ;
V_73:
V_6 = F_3 ( V_13 ) ;
if ( ( V_6 & V_74 ) == 0 )
return 0 ;
V_70 = ( V_6 & V_75 ) >> 16 ;
if ( V_70 > V_4 -> V_4 . V_15 )
V_70 = V_4 -> V_4 . V_15 ;
if ( V_70 > V_71 ) {
F_27 ( L_66 , V_4 -> V_4 . V_14 ) ;
V_8 -> V_8 . V_63 = - V_76 ;
V_70 = V_71 ;
}
F_28 ( V_69 , V_25 , V_70 ) ;
V_6 |= V_77 ;
if ( V_4 -> V_18 ) {
if ( V_4 -> V_19 == 0 ) {
V_6 &= ~ ( V_78 | V_79 ) ;
V_4 -> V_19 = 1 ;
} else {
V_6 &= ~ ( V_78 | V_80 ) ;
V_4 -> V_19 = 0 ;
}
} else
V_6 &= ~ ( V_78 | V_79 ) ;
F_29 ( V_6 , V_13 ) ;
V_8 -> V_8 . V_24 += V_70 ;
V_72 = ( V_70 < V_4 -> V_4 . V_15 ) ;
if ( V_70 == V_71 )
V_72 = 1 ;
F_30 ( L_67 , V_4 -> V_4 . V_14 , & V_8 -> V_8 , V_70 ,
V_72 ? L_68 : L_14 ) ;
if ( V_72 )
F_18 ( V_4 , V_8 , 0 ) ;
else if ( V_4 -> V_18 ) {
V_6 = F_3 ( V_13 ) ;
V_71 -= V_70 ;
V_25 += V_70 ;
goto V_73;
}
return V_72 ;
}
static int F_31 ( struct V_3 * V_4 , struct V_7 * V_8 )
{
T_1 T_2 * V_13 = V_4 -> V_13 ;
T_1 V_6 = F_3 ( V_13 ) ;
T_3 T_2 * V_69 = V_4 -> V_13 + ( F_25 ( 0 ) - F_26 ( 0 ) ) ;
unsigned V_81 , V_70 , V_82 ;
T_3 * V_25 ;
if ( F_32 ( V_6 & ( V_83 | V_84 ) ) ) {
if ( V_6 & V_83 ) {
V_6 |= V_77 ;
V_6 &= ~ ( V_78 | V_83 ) ;
F_29 ( V_6 , V_13 ) ;
V_6 = F_3 ( V_13 ) ;
}
if ( V_6 & V_84 )
return 0 ;
}
V_25 = V_8 -> V_8 . V_25 + V_8 -> V_8 . V_24 ;
F_33 ( V_25 ) ;
V_81 = V_8 -> V_8 . V_23 - V_8 -> V_8 . V_24 ;
if ( V_4 -> V_4 . V_15 < V_81 ) {
V_70 = V_4 -> V_4 . V_15 ;
V_82 = 0 ;
} else {
V_70 = V_81 ;
V_82 = ( V_70 < V_4 -> V_4 . V_15 ) || ! V_8 -> V_8 . V_85 ;
}
F_34 ( V_69 , V_25 , V_70 ) ;
V_6 &= ~ V_78 ;
V_6 |= V_77 | V_84 ;
F_29 ( V_6 , V_13 ) ;
V_8 -> V_8 . V_24 += V_70 ;
F_30 ( L_69 , V_4 -> V_4 . V_14 , & V_8 -> V_8 , V_70 ,
V_82 ? L_68 : L_14 ) ;
if ( V_82 )
F_18 ( V_4 , V_8 , 0 ) ;
return V_82 ;
}
static void F_35 ( struct V_3 * V_4 , int V_63 )
{
struct V_7 * V_8 ;
V_4 -> V_20 = 1 ;
if ( F_5 ( & V_4 -> V_22 ) )
return;
F_20 ( L_70 , V_86 , V_4 -> V_4 . V_14 ) ;
while ( ! F_5 ( & V_4 -> V_22 ) ) {
V_8 = F_36 ( V_4 -> V_22 . V_87 , struct V_7 , V_22 ) ;
F_18 ( V_4 , V_8 , V_63 ) ;
}
}
static int F_37 ( struct V_88 * V_89 ,
const struct V_90 * V_56 )
{
struct V_3 * V_4 = F_38 ( V_89 , struct V_3 , V_4 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
T_4 V_15 ;
T_1 V_32 ;
unsigned long V_9 ;
if ( ! V_89 || ! V_4
|| ! V_56 || V_4 -> V_56
|| V_89 -> V_14 == V_91
|| V_56 -> V_92 != V_93
|| ( V_15 = F_39 ( V_56 ) ) == 0
|| V_15 > V_4 -> V_15 ) {
F_27 ( L_71 ) ;
return - V_94 ;
}
if ( ! V_11 -> V_39 || V_11 -> V_95 . V_96 == V_97 ) {
F_27 ( L_72 ) ;
return - V_65 ;
}
V_32 = F_40 ( V_56 ) ;
switch ( V_32 ) {
case V_98 :
F_27 ( L_73 ) ;
return - V_94 ;
case V_99 :
if ( V_15 > 64 )
goto V_100;
break;
case V_101 :
switch ( V_15 ) {
case 8 :
case 16 :
case 32 :
case 64 :
goto V_102;
}
V_100:
F_27 ( L_74 , V_15 ) ;
return - V_94 ;
case V_103 :
if ( ! V_4 -> V_18 ) {
F_27 ( L_75 ) ;
return - V_94 ;
}
break;
}
V_102:
F_2 ( & V_11 -> V_12 , V_9 ) ;
V_4 -> V_16 = F_41 ( V_56 ) ;
V_4 -> V_17 = ( V_32 == V_103 ) ;
V_4 -> V_20 = 0 ;
if ( V_4 -> V_16 )
V_32 |= 0x04 ;
V_32 <<= 8 ;
V_32 |= V_104 ;
F_29 ( V_32 , V_4 -> V_13 ) ;
V_4 -> V_56 = V_56 ;
V_4 -> V_4 . V_15 = V_15 ;
F_23 ( V_11 , V_105 , V_4 -> V_67 ) ;
F_23 ( V_11 , V_105 , 0 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
return 0 ;
}
static int F_42 ( struct V_88 * V_89 )
{
struct V_3 * V_4 = F_38 ( V_89 , struct V_3 , V_4 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
unsigned long V_9 ;
if ( V_4 == & V_4 -> V_11 -> V_4 [ 0 ] )
return - V_94 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
F_35 ( V_4 , - V_65 ) ;
V_4 -> V_56 = NULL ;
V_4 -> V_4 . V_15 = V_4 -> V_15 ;
if ( V_4 -> V_11 -> V_40 ) {
F_23 ( V_11 , V_105 , V_4 -> V_67 ) ;
F_23 ( V_11 , V_105 , 0 ) ;
F_29 ( 0 , V_4 -> V_13 ) ;
}
F_7 ( & V_11 -> V_12 , V_9 ) ;
return 0 ;
}
static struct V_106 *
F_43 ( struct V_88 * V_89 , T_5 V_107 )
{
struct V_7 * V_8 ;
V_8 = F_44 ( sizeof ( struct V_7 ) , V_107 ) ;
if ( ! V_8 )
return NULL ;
F_45 ( & V_8 -> V_22 ) ;
return & V_8 -> V_8 ;
}
static void F_46 ( struct V_88 * V_89 , struct V_106 * V_108 )
{
struct V_7 * V_8 ;
V_8 = F_38 ( V_108 , struct V_7 , V_8 ) ;
F_47 ( ! F_5 ( & V_8 -> V_22 ) ) ;
F_48 ( V_8 ) ;
}
static int F_49 ( struct V_88 * V_89 ,
struct V_106 * V_108 , T_5 V_107 )
{
struct V_7 * V_8 ;
struct V_3 * V_4 ;
struct V_10 * V_11 ;
int V_63 ;
unsigned long V_9 ;
V_8 = F_38 ( V_108 , struct V_7 , V_8 ) ;
V_4 = F_38 ( V_89 , struct V_3 , V_4 ) ;
if ( ! V_108 || ! V_108 -> V_66
|| ! V_108 -> V_25 || ! F_5 ( & V_8 -> V_22 ) ) {
F_27 ( L_76 ) ;
return - V_94 ;
}
if ( ! V_89 || ( ! V_4 -> V_56 && V_4 -> V_4 . V_14 != V_91 ) ) {
F_27 ( L_77 ) ;
return - V_94 ;
}
V_11 = V_4 -> V_11 ;
if ( ! V_11 || ! V_11 -> V_39 || V_11 -> V_95 . V_96 == V_97 ) {
F_27 ( L_78 ) ;
return - V_94 ;
}
V_108 -> V_63 = - V_64 ;
V_108 -> V_24 = 0 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
if ( F_5 ( & V_4 -> V_22 ) && ! V_4 -> V_20 ) {
int V_109 ;
V_109 = ( V_4 -> V_4 . V_14 == V_91 ) ;
if ( V_109 ) {
T_1 V_32 ;
if ( ! V_11 -> V_110 ) {
V_63 = - V_94 ;
goto F_18;
}
if ( V_11 -> V_111 ) {
V_32 = F_10 ( V_11 , V_45 ) ;
V_32 ^= V_49 ;
F_20 ( L_79 ) ;
F_23 ( V_11 , V_45 , V_32 ) ;
}
if ( V_8 -> V_8 . V_23 == 0 ) {
V_112:
F_30 ( L_80 ) ;
V_63 = 0 ;
V_32 = F_3 ( V_4 -> V_13 ) ;
V_32 &= ~ V_78 ;
V_32 |= V_77 | V_84 ;
F_29 ( V_32 , V_4 -> V_13 ) ;
V_11 -> V_110 = 0 ;
goto F_18;
}
}
if ( V_4 -> V_16 )
V_63 = F_31 ( V_4 , V_8 ) ;
else {
V_63 = F_24 ( V_4 , V_8 ) ;
if ( V_63 && V_109 )
goto V_112;
}
} else
V_63 = 0 ;
if ( V_8 && ! V_63 ) {
F_50 ( & V_8 -> V_22 , & V_4 -> V_22 ) ;
F_23 ( V_11 , V_113 , V_4 -> V_67 ) ;
}
F_18:
F_7 ( & V_11 -> V_12 , V_9 ) ;
return ( V_63 < 0 ) ? V_63 : 0 ;
}
static int F_51 ( struct V_88 * V_89 , struct V_106 * V_108 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 ;
V_4 = F_38 ( V_89 , struct V_3 , V_4 ) ;
if ( ! V_89 || V_4 -> V_4 . V_14 == V_91 )
return - V_94 ;
V_11 = V_4 -> V_11 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
F_6 (req, &ep->queue, queue) {
if ( & V_8 -> V_8 == V_108 )
break;
}
if ( & V_8 -> V_8 != V_108 ) {
F_7 ( & V_11 -> V_12 , V_9 ) ;
return - V_94 ;
}
F_18 ( V_4 , V_8 , - V_114 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
return 0 ;
}
static int F_52 ( struct V_88 * V_89 , int V_115 )
{
struct V_3 * V_4 = F_38 ( V_89 , struct V_3 , V_4 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
T_1 T_2 * V_13 ;
T_1 V_6 ;
unsigned long V_9 ;
int V_63 = 0 ;
if ( ! V_89 || V_4 -> V_17 || ! V_4 -> V_11 -> V_40 )
return - V_94 ;
V_13 = V_4 -> V_13 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
V_6 = F_3 ( V_13 ) ;
if ( V_4 -> V_16 && ( ! F_5 ( & V_4 -> V_22 ) || ( V_6 >> 16 ) != 0 ) )
V_63 = - V_116 ;
else {
V_6 |= V_77 ;
V_6 &= ~ V_78 ;
if ( V_115 ) {
V_6 |= V_117 ;
F_20 ( L_81 , V_4 -> V_4 . V_14 ) ;
} else {
F_23 ( V_11 , V_105 , V_4 -> V_67 ) ;
F_23 ( V_11 , V_105 , 0 ) ;
V_6 &= ~ V_117 ;
}
F_29 ( V_6 , V_13 ) ;
}
F_7 ( & V_11 -> V_12 , V_9 ) ;
return V_63 ;
}
static int F_53 ( struct V_118 * V_95 )
{
struct V_10 * V_11 = F_54 ( V_95 ) ;
if ( ! F_54 ( V_95 ) -> V_40 )
return - V_94 ;
return F_10 ( V_11 , V_41 ) & V_44 ;
}
static int F_55 ( struct V_118 * V_95 )
{
struct V_10 * V_11 = F_54 ( V_95 ) ;
T_1 V_119 ;
int V_63 = - V_94 ;
unsigned long V_9 ;
F_27 ( L_82 , V_86 ) ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
if ( ! V_11 -> V_40 || ! V_11 -> V_38 )
goto F_18;
V_119 = F_10 ( V_11 , V_45 ) ;
if ( ! ( V_119 & V_48 ) )
goto F_18;
V_119 |= V_48 ;
F_23 ( V_11 , V_45 , V_119 ) ;
F_18:
F_7 ( & V_11 -> V_12 , V_9 ) ;
return V_63 ;
}
static void F_56 ( struct V_10 * V_11 )
{
T_1 V_28 ;
F_45 ( & V_11 -> V_95 . V_120 ) ;
F_45 ( & V_11 -> V_95 . V_121 -> V_120 ) ;
for ( V_28 = 0 ; V_28 < V_122 ; V_28 ++ ) {
struct V_3 * V_4 = & V_11 -> V_4 [ V_28 ] ;
if ( V_28 != 0 )
F_50 ( & V_4 -> V_4 . V_120 , & V_11 -> V_95 . V_120 ) ;
V_4 -> V_56 = NULL ;
V_4 -> V_20 = 0 ;
V_4 -> V_19 = 0 ;
V_4 -> V_4 . V_15 = V_4 -> V_15 ;
V_4 -> V_13 = ( void T_2 * ) V_11 -> V_123 + F_26 ( V_28 ) ;
F_45 ( & V_4 -> V_22 ) ;
}
}
static void F_57 ( struct V_10 * V_11 )
{
struct V_124 * V_39 = V_11 -> V_39 ;
int V_28 ;
if ( V_11 -> V_95 . V_96 == V_97 )
V_39 = NULL ;
V_11 -> V_95 . V_96 = V_97 ;
V_11 -> V_38 = 0 ;
for ( V_28 = 0 ; V_28 < V_122 ; V_28 ++ ) {
struct V_3 * V_4 = & V_11 -> V_4 [ V_28 ] ;
V_4 -> V_20 = 1 ;
F_35 ( V_4 , - V_65 ) ;
}
if ( V_39 ) {
F_21 ( & V_11 -> V_12 ) ;
V_39 -> V_125 ( & V_11 -> V_95 ) ;
F_22 ( & V_11 -> V_12 ) ;
}
F_56 ( V_11 ) ;
}
static void F_58 ( struct V_10 * V_11 )
{
if ( V_11 -> V_40 )
return;
V_11 -> V_40 = 1 ;
F_59 ( V_11 -> V_126 ) ;
F_59 ( V_11 -> V_127 ) ;
}
static void F_60 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_40 )
return;
V_11 -> V_40 = 0 ;
V_11 -> V_95 . V_96 = V_97 ;
F_61 ( V_11 -> V_127 ) ;
F_61 ( V_11 -> V_126 ) ;
}
static void F_62 ( struct V_10 * V_11 , int V_128 )
{
int V_129 = ! V_11 -> V_130 . V_131 ;
if ( ! V_11 -> V_36 || ! V_11 -> V_35 )
V_128 = 0 ;
F_27 ( L_83 , V_128 ? L_14 : L_11 ) ;
if ( V_128 ) {
F_58 ( V_11 ) ;
F_23 ( V_11 , V_132 , V_133 ) ;
F_23 ( V_11 , V_134 , 0 ) ;
if ( F_63 () )
F_64 ( V_11 -> V_130 . V_135 , V_129 ) ;
else if ( F_65 () || F_66 () || F_67 () ) {
T_1 V_136 = F_10 ( V_11 , V_134 ) ;
V_136 |= V_137 ;
F_23 ( V_11 , V_134 , V_136 ) ;
} else if ( F_68 () || F_69 () ) {
T_1 V_138 ;
V_138 = F_70 ( V_139 ) ;
V_138 |= V_140 ;
F_71 ( V_139 , V_138 ) ;
}
} else {
F_57 ( V_11 ) ;
F_23 ( V_11 , V_68 , V_133 ) ;
F_23 ( V_11 , V_134 , V_141 ) ;
if ( F_63 () )
F_64 ( V_11 -> V_130 . V_135 , ! V_129 ) ;
else if ( F_65 () || F_66 () || F_67 () ) {
T_1 V_136 = F_10 ( V_11 , V_134 ) ;
V_136 &= ~ V_137 ;
F_23 ( V_11 , V_134 , V_136 ) ;
} else if ( F_68 () || F_69 () ) {
T_1 V_138 ;
V_138 = F_70 ( V_139 ) ;
V_138 &= ~ V_140 ;
F_71 ( V_139 , V_138 ) ;
}
F_60 ( V_11 ) ;
}
}
static int F_72 ( struct V_118 * V_95 , int V_142 )
{
struct V_10 * V_11 = F_54 ( V_95 ) ;
unsigned long V_9 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
V_11 -> V_35 = ( V_142 != 0 ) ;
if ( V_11 -> V_39 )
F_62 ( V_11 , V_142 ) ;
else
F_62 ( V_11 , 0 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
return 0 ;
}
static int F_73 ( struct V_118 * V_95 , int V_128 )
{
struct V_10 * V_11 = F_54 ( V_95 ) ;
unsigned long V_9 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
V_11 -> V_36 = V_128 = ! ! V_128 ;
F_62 ( V_11 , V_128 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
return 0 ;
}
static int F_74 ( struct V_118 * V_95 , int V_128 )
{
struct V_10 * V_11 = F_54 ( V_95 ) ;
unsigned long V_9 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
V_11 -> V_37 = ( V_128 != 0 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
return 0 ;
}
static int F_75 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
T_1 T_2 * V_13 = V_4 -> V_13 ;
T_1 V_6 = F_3 ( V_13 ) ;
if ( ! F_5 ( & V_4 -> V_22 ) )
V_8 = F_36 ( V_4 -> V_22 . V_87 ,
struct V_7 , V_22 ) ;
else
V_8 = NULL ;
if ( V_4 -> V_16 ) {
if ( V_6 & ( V_143 | V_83 ) ) {
V_6 |= V_77 ;
V_6 &= ~ ( V_78 | V_143 | V_83 ) ;
F_29 ( V_6 , V_13 ) ;
}
if ( V_8 )
return F_31 ( V_4 , V_8 ) ;
} else {
if ( V_6 & V_143 ) {
if ( V_4 -> V_17 && V_8 )
V_8 -> V_8 . V_63 = - V_144 ;
V_6 |= V_77 ;
V_6 &= ~ ( V_78 | V_143 ) ;
F_29 ( V_6 , V_13 ) ;
V_6 = F_3 ( V_13 ) ;
}
if ( V_8 && ( V_6 & V_74 ) )
return F_24 ( V_4 , V_8 ) ;
}
return 0 ;
}
static void F_76 ( struct V_10 * V_11 , struct V_3 * V_4 , T_1 V_6 )
{
T_1 T_2 * V_13 = V_4 -> V_13 ;
T_3 T_2 * V_69 = V_4 -> V_13 + ( F_25 ( 0 ) - F_26 ( 0 ) ) ;
unsigned V_145 , V_28 = 0 ;
T_1 V_32 ;
union V_146 V_147 ;
int V_63 = 0 ;
V_145 = ( V_6 & V_75 ) >> 16 ;
if ( F_77 ( V_145 == 8 ) ) {
while ( V_145 -- )
V_147 . V_148 [ V_28 ++ ] = F_78 ( V_69 ) ;
if ( V_147 . V_149 . V_150 & V_151 ) {
V_6 |= V_152 ;
V_4 -> V_16 = 1 ;
} else {
V_6 &= ~ V_152 ;
V_4 -> V_16 = 0 ;
}
} else {
F_79 ( L_84 , V_145 , V_6 ) ;
V_63 = - V_94 ;
}
V_6 |= V_77 ;
V_6 &= ~ ( V_78 | V_153 ) ;
F_29 ( V_6 , V_13 ) ;
V_11 -> V_154 = 0 ;
V_11 -> V_111 = 0 ;
V_4 -> V_20 = 0 ;
if ( F_32 ( V_63 != 0 ) )
goto V_155;
#define F_80 le16_to_cpu(pkt.r.wIndex)
#define F_81 le16_to_cpu(pkt.r.wValue)
#define F_82 le16_to_cpu(pkt.r.wLength)
F_20 ( L_85 ,
V_147 . V_149 . V_150 , V_147 . V_149 . V_156 ,
F_81 , F_80 , F_82 ) ;
V_11 -> V_110 = 1 ;
V_6 = F_3 ( V_13 ) ;
V_6 |= V_77 ;
V_6 &= ~ V_78 ;
switch ( ( V_147 . V_149 . V_150 << 8 ) | V_147 . V_149 . V_156 ) {
case ( ( V_157 | V_158 ) << 8 )
| V_159 :
F_29 ( V_6 | V_84 , V_13 ) ;
V_11 -> V_160 = F_81 ;
V_11 -> V_154 = 1 ;
V_11 -> V_110 = 0 ;
return;
case ( ( V_157 | V_158 ) << 8 )
| V_161 :
V_32 = F_10 ( V_11 , V_45 ) & V_49 ;
if ( V_147 . V_149 . V_162 )
V_11 -> V_111 = ( V_32 == 0 ) ;
else
V_11 -> V_111 = ( V_32 != 0 ) ;
if ( V_11 -> V_111 )
F_20 ( L_86 ) ;
break;
case ( ( V_151 | V_157 | V_158 ) << 8 )
| V_163 :
V_32 = ( V_11 -> V_37 << V_164 ) ;
if ( F_10 ( V_11 , V_45 ) & V_48 )
V_32 |= ( 1 << V_165 ) ;
F_30 ( L_87 ) ;
F_83 ( V_32 , V_69 ) ;
F_83 ( 0 , V_69 ) ;
goto V_166;
case ( ( V_157 | V_158 ) << 8 )
| V_167 :
if ( F_81 != V_165 )
goto V_155;
V_32 = F_10 ( V_11 , V_45 ) ;
V_32 |= V_48 ;
F_23 ( V_11 , V_45 , V_32 ) ;
goto V_168;
case ( ( V_157 | V_158 ) << 8 )
| V_169 :
if ( F_81 != V_165 )
goto V_155;
V_32 = F_10 ( V_11 , V_45 ) ;
V_32 &= ~ V_48 ;
F_23 ( V_11 , V_45 , V_32 ) ;
goto V_168;
case ( ( V_151 | V_157 | V_170 ) << 8 )
| V_163 :
F_30 ( L_88 ) ;
F_83 ( 0 , V_69 ) ;
F_83 ( 0 , V_69 ) ;
goto V_166;
case ( ( V_157 | V_170 ) << 8 )
| V_167 :
case ( ( V_157 | V_170 ) << 8 )
| V_169 :
goto V_155;
case ( ( V_151 | V_157 | V_171 ) << 8 )
| V_163 :
V_32 = F_80 & V_172 ;
V_4 = & V_11 -> V_4 [ V_32 ] ;
if ( V_32 >= V_122 || ( V_32 && ! V_4 -> V_56 ) )
goto V_155;
if ( V_32 ) {
if ( ( F_80 & V_151 ) ) {
if ( ! V_4 -> V_16 )
goto V_155;
} else if ( V_4 -> V_16 )
goto V_155;
}
F_30 ( L_89 , V_4 -> V_4 . V_14 ) ;
if ( F_3 ( V_4 -> V_13 ) & V_117 )
V_32 = ( 1 << V_173 ) ;
else
V_32 = 0 ;
F_83 ( V_32 , V_69 ) ;
F_83 ( 0 , V_69 ) ;
goto V_166;
case ( ( V_157 | V_171 ) << 8 )
| V_167 :
V_32 = F_80 & V_172 ;
V_4 = & V_11 -> V_4 [ V_32 ] ;
if ( F_81 != V_173 || V_32 >= V_122 )
goto V_155;
if ( ! V_4 -> V_56 || V_4 -> V_17 )
goto V_155;
if ( ( F_80 & V_151 ) ) {
if ( ! V_4 -> V_16 )
goto V_155;
} else if ( V_4 -> V_16 )
goto V_155;
V_32 = F_3 ( V_4 -> V_13 ) ;
V_32 &= ~ V_78 ;
V_32 |= V_77 | V_117 ;
F_29 ( V_32 , V_4 -> V_13 ) ;
goto V_168;
case ( ( V_157 | V_171 ) << 8 )
| V_169 :
V_32 = F_80 & V_172 ;
V_4 = & V_11 -> V_4 [ V_32 ] ;
if ( F_81 != V_173 || V_32 >= V_122 )
goto V_155;
if ( V_32 == 0 )
goto V_168;
if ( ! V_4 -> V_56 || V_4 -> V_17 )
goto V_155;
if ( ( F_80 & V_151 ) ) {
if ( ! V_4 -> V_16 )
goto V_155;
} else if ( V_4 -> V_16 )
goto V_155;
F_23 ( V_11 , V_105 , V_4 -> V_67 ) ;
F_23 ( V_11 , V_105 , 0 ) ;
V_32 = F_3 ( V_4 -> V_13 ) ;
V_32 |= V_77 ;
V_32 &= ~ ( V_78 | V_117 ) ;
F_29 ( V_32 , V_4 -> V_13 ) ;
if ( ! F_5 ( & V_4 -> V_22 ) )
F_75 ( V_4 ) ;
goto V_168;
}
#undef F_81
#undef F_80
#undef F_82
if ( V_11 -> V_39 ) {
F_21 ( & V_11 -> V_12 ) ;
V_63 = V_11 -> V_39 -> V_146 ( & V_11 -> V_95 , & V_147 . V_149 ) ;
F_22 ( & V_11 -> V_12 ) ;
}
else
V_63 = - V_174 ;
if ( V_63 < 0 ) {
V_155:
F_20 ( L_90 ,
V_147 . V_149 . V_150 , V_147 . V_149 . V_156 , V_63 ) ;
V_6 |= V_117 ;
F_29 ( V_6 , V_13 ) ;
V_11 -> V_110 = 0 ;
}
return;
V_168:
F_30 ( L_80 ) ;
V_166:
V_6 |= V_84 ;
F_29 ( V_6 , V_13 ) ;
V_11 -> V_110 = 0 ;
}
static void F_84 ( struct V_10 * V_11 )
{
struct V_3 * V_121 = & V_11 -> V_4 [ 0 ] ;
T_1 T_2 * V_13 = V_121 -> V_13 ;
T_1 V_6 = F_3 ( V_13 ) ;
struct V_7 * V_8 ;
if ( F_32 ( V_6 & V_143 ) ) {
F_35 ( V_121 , - V_175 ) ;
V_11 -> V_110 = 0 ;
V_6 |= V_77 ;
V_6 &= ~ ( V_78 | V_143 | V_117 ) ;
F_29 ( V_6 , V_13 ) ;
F_20 ( L_91 ) ;
V_6 = F_3 ( V_13 ) ;
}
if ( V_6 & V_153 ) {
F_35 ( V_121 , 0 ) ;
V_11 -> V_110 = 0 ;
F_76 ( V_11 , V_121 , V_6 ) ;
return;
}
if ( F_5 ( & V_121 -> V_22 ) )
V_8 = NULL ;
else
V_8 = F_36 ( V_121 -> V_22 . V_87 , struct V_7 , V_22 ) ;
if ( V_6 & V_83 ) {
V_6 |= V_77 ;
V_6 &= ~ ( V_78 | V_83 ) ;
if ( V_8 && V_121 -> V_16 ) {
if ( F_75 ( V_121 ) )
V_11 -> V_110 = 0 ;
} else {
V_11 -> V_110 = 0 ;
F_29 ( V_6 , V_13 ) ;
if ( V_11 -> V_154 ) {
T_1 V_32 ;
F_23 ( V_11 , V_51 ,
V_52 | V_11 -> V_160 ) ;
V_32 = F_10 ( V_11 , V_45 ) ;
V_32 &= ~ V_50 ;
if ( V_11 -> V_160 )
V_32 |= V_50 ;
F_23 ( V_11 , V_45 , V_32 ) ;
V_11 -> V_154 = 0 ;
F_20 ( L_92 , V_11 -> V_160 ) ;
}
}
}
else if ( V_6 & V_79 ) {
V_6 |= V_77 ;
V_6 &= ~ ( V_78 | V_79 ) ;
if ( ! V_121 -> V_16 ) {
if ( V_8 ) {
if ( F_75 ( V_121 ) ) {
F_30 ( L_80 ) ;
V_6 = F_3 ( V_13 ) ;
V_6 &= ~ V_78 ;
V_6 |= V_77 | V_84 ;
F_29 ( V_6 , V_13 ) ;
V_11 -> V_110 = 0 ;
}
} else if ( V_11 -> V_110 ) {
F_27 ( L_93 ) ;
F_29 ( V_6 | V_117 , V_13 ) ;
V_11 -> V_110 = 0 ;
}
} else {
F_30 ( L_94 ) ;
F_29 ( V_6 , V_13 ) ;
if ( V_8 )
F_18 ( V_121 , V_8 , 0 ) ;
}
}
}
static T_6 F_85 ( int V_176 , void * V_177 )
{
struct V_10 * V_11 = V_177 ;
T_1 V_178 = 5 ;
int V_179 = 0 ;
unsigned long V_9 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
if ( ! V_11 -> V_40 ) {
F_58 ( V_11 ) ;
V_179 = 1 ;
}
while ( V_178 -- ) {
T_1 V_63 ;
V_63 = F_10 ( V_11 , V_55 )
& F_10 ( V_11 , V_54 ) ;
if ( ! V_63 )
break;
if ( V_63 & V_180 ) {
F_23 ( V_11 , V_68 , ~ V_181 ) ;
F_23 ( V_11 , V_113 , V_181 ) ;
F_23 ( V_11 , V_132 , V_180 ) ;
F_23 ( V_11 , V_132 , V_180 ) ;
F_20 ( L_95 ) ;
V_11 -> V_160 = 0 ;
F_57 ( V_11 ) ;
F_23 ( V_11 , F_26 ( 0 ) ,
V_104 | V_182 ) ;
V_11 -> V_95 . V_96 = V_183 ;
V_11 -> V_38 = 0 ;
F_23 ( V_11 , V_113 , F_86 ( 0 ) ) ;
} else if ( V_63 & V_184 ) {
F_23 ( V_11 , V_68 , V_184 ) ;
F_23 ( V_11 , V_113 , V_133 ) ;
F_23 ( V_11 , V_132 , V_184 ) ;
if ( V_11 -> V_38 )
continue;
V_11 -> V_38 = 1 ;
if ( V_11 -> V_39 && V_11 -> V_39 -> V_185 ) {
F_21 ( & V_11 -> V_12 ) ;
V_11 -> V_39 -> V_185 ( & V_11 -> V_95 ) ;
F_22 ( & V_11 -> V_12 ) ;
}
} else if ( V_63 & V_133 ) {
F_23 ( V_11 , V_68 , V_133 ) ;
F_23 ( V_11 , V_113 , V_184 ) ;
F_23 ( V_11 , V_132 , V_133 ) ;
if ( ! V_11 -> V_38 )
continue;
V_11 -> V_38 = 0 ;
if ( V_11 -> V_39 && V_11 -> V_39 -> V_186 ) {
F_21 ( & V_11 -> V_12 ) ;
V_11 -> V_39 -> V_186 ( & V_11 -> V_95 ) ;
F_22 ( & V_11 -> V_12 ) ;
}
} else {
int V_28 ;
unsigned V_27 = 1 ;
struct V_3 * V_4 = & V_11 -> V_4 [ 1 ] ;
if ( V_63 & V_27 )
F_84 ( V_11 ) ;
for ( V_28 = 1 ; V_28 < V_122 ; V_28 ++ ) {
V_27 <<= 1 ;
if ( V_63 & V_27 )
F_75 ( V_4 ) ;
V_4 ++ ;
}
}
}
if ( V_179 )
F_60 ( V_11 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
return V_187 ;
}
static void F_87 ( struct V_188 * V_189 )
{
}
static void F_88 ( struct V_10 * V_11 , unsigned V_115 )
{
V_115 ^= V_11 -> V_130 . V_190 ;
if ( V_115 != V_11 -> V_35 )
F_72 ( & V_11 -> V_95 , V_115 ) ;
}
static T_6 F_89 ( int V_176 , void * V_177 )
{
struct V_10 * V_11 = V_177 ;
F_90 ( 10 ) ;
F_88 ( V_11 , F_91 ( V_11 -> V_130 . V_191 ) ) ;
return V_187 ;
}
static void F_92 ( struct V_192 * V_193 )
{
struct V_10 * V_11 = F_38 ( V_193 , struct V_10 ,
V_194 ) ;
F_88 ( V_11 , F_93 ( V_11 -> V_130 . V_191 ) ) ;
if ( ! F_94 ( & V_11 -> V_195 ) )
F_95 ( & V_11 -> V_195 , V_196 + V_197 ) ;
}
static void F_96 ( unsigned long V_59 )
{
struct V_10 * V_11 = (struct V_10 * ) V_59 ;
if ( ! F_97 ( & V_11 -> V_194 ) )
F_98 ( & V_11 -> V_194 ) ;
}
static int F_99 ( struct V_124 * V_39 ,
int (* F_100)( struct V_118 * ) )
{
struct V_10 * V_11 = & V_198 ;
int V_199 ;
unsigned long V_9 ;
if ( ! V_39
|| V_39 -> V_200 < V_183
|| ! F_100
|| ! V_39 -> V_146 ) {
F_27 ( L_96 ) ;
return - V_94 ;
}
if ( V_11 -> V_39 ) {
F_27 ( L_97 ) ;
return - V_201 ;
}
V_11 -> V_39 = V_39 ;
V_11 -> V_95 . V_189 . V_39 = & V_39 -> V_39 ;
F_101 ( & V_11 -> V_95 . V_189 , & V_39 -> V_39 ) ;
V_11 -> V_36 = 1 ;
V_11 -> V_37 = 1 ;
V_199 = F_100 ( & V_11 -> V_95 ) ;
if ( V_199 ) {
F_27 ( L_98 , V_199 ) ;
V_11 -> V_39 = NULL ;
V_11 -> V_95 . V_189 . V_39 = NULL ;
F_101 ( & V_11 -> V_95 . V_189 , NULL ) ;
V_11 -> V_36 = 0 ;
V_11 -> V_37 = 0 ;
return V_199 ;
}
F_2 ( & V_11 -> V_12 , V_9 ) ;
F_62 ( V_11 , 1 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
F_27 ( L_99 , V_39 -> V_39 . V_14 ) ;
return 0 ;
}
static int F_102 ( struct V_124 * V_39 )
{
struct V_10 * V_11 = & V_198 ;
unsigned long V_9 ;
if ( ! V_39 || V_39 != V_11 -> V_39 || ! V_39 -> V_202 )
return - V_94 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
V_11 -> V_36 = 0 ;
F_23 ( V_11 , V_68 , ~ 0 ) ;
F_62 ( V_11 , 0 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
V_39 -> V_202 ( & V_11 -> V_95 ) ;
V_11 -> V_95 . V_189 . V_39 = NULL ;
F_101 ( & V_11 -> V_95 . V_189 , NULL ) ;
V_11 -> V_39 = NULL ;
F_27 ( L_100 , V_39 -> V_39 . V_14 ) ;
return 0 ;
}
static void F_103 ( struct V_203 * V_189 )
{
struct V_10 * V_11 = F_104 ( V_189 ) ;
unsigned long V_9 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
F_62 ( F_104 ( V_189 ) , 0 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
}
static int T_7 F_105 ( struct V_203 * V_204 )
{
struct V_188 * V_189 = & V_204 -> V_189 ;
struct V_10 * V_11 ;
int V_199 ;
struct V_205 * V_206 ;
if ( ! V_189 -> V_207 ) {
F_27 ( L_101 ) ;
return - V_174 ;
}
if ( V_204 -> V_208 != 2 ) {
F_27 ( L_102 ) ;
return - V_174 ;
}
if ( ( V_204 -> V_205 [ 0 ] . V_9 != V_209 )
|| ( V_204 -> V_205 [ 1 ] . V_9 != V_210 ) ) {
F_27 ( L_103 ) ;
return - V_174 ;
}
V_206 = F_106 ( V_204 , V_209 , 0 ) ;
if ( ! V_206 )
return - V_211 ;
if ( ! F_107 ( V_206 -> V_212 , F_108 ( V_206 ) , V_33 ) ) {
F_27 ( L_104 ) ;
return - V_201 ;
}
V_11 = & V_198 ;
V_11 -> V_95 . V_189 . V_213 = V_189 ;
V_11 -> V_130 = * (struct V_214 * ) V_189 -> V_207 ;
V_11 -> V_204 = V_204 ;
V_11 -> V_36 = 0 ;
F_109 ( & V_11 -> V_12 ) ;
if ( F_63 () ) {
if ( F_110 ( V_11 -> V_130 . V_135 ) ) {
F_27 ( L_105 ) ;
V_199 = - V_174 ;
goto V_215;
}
V_199 = F_111 ( V_11 -> V_130 . V_135 , L_106 ) ;
if ( V_199 ) {
F_27 ( L_107 ) ;
goto V_215;
}
F_112 ( V_11 -> V_130 . V_135 ,
V_11 -> V_130 . V_131 ) ;
}
if ( F_65 () || F_67 () ) {
V_11 -> V_4 [ 0 ] . V_15 = 64 ;
V_11 -> V_4 [ 3 ] . V_15 = 64 ;
V_11 -> V_4 [ 4 ] . V_15 = 512 ;
V_11 -> V_4 [ 5 ] . V_15 = 512 ;
} else if ( F_68 () || F_69 () ) {
V_11 -> V_4 [ 3 ] . V_15 = 64 ;
} else if ( F_66 () ) {
V_11 -> V_4 [ 0 ] . V_15 = 64 ;
V_11 -> V_4 [ 3 ] . V_15 = 64 ;
}
V_11 -> V_123 = F_113 ( V_206 -> V_212 , F_108 ( V_206 ) ) ;
if ( ! V_11 -> V_123 ) {
V_199 = - V_216 ;
goto V_217;
}
F_56 ( V_11 ) ;
V_11 -> V_126 = F_114 ( V_189 , L_108 ) ;
V_11 -> V_127 = F_114 ( V_189 , L_109 ) ;
if ( F_115 ( V_11 -> V_126 ) || F_115 ( V_11 -> V_127 ) ) {
F_27 ( L_110 ) ;
V_199 = - V_174 ;
goto V_218;
}
V_199 = F_116 ( & V_11 -> V_95 . V_189 ) ;
if ( V_199 < 0 ) {
F_117 ( & V_11 -> V_95 . V_189 ) ;
goto V_218;
}
F_59 ( V_11 -> V_126 ) ;
F_23 ( V_11 , V_134 , V_141 ) ;
F_23 ( V_11 , V_68 , 0xffffffff ) ;
F_23 ( V_11 , V_132 , 0xffffffff ) ;
F_61 ( V_11 -> V_126 ) ;
V_11 -> V_219 = F_118 ( V_204 , 0 ) ;
V_199 = F_119 ( V_11 -> V_219 , F_85 ,
0 , V_33 , V_11 ) ;
if ( V_199 < 0 ) {
F_27 ( L_111 , V_11 -> V_219 ) ;
goto V_220;
}
if ( F_110 ( V_11 -> V_130 . V_191 ) ) {
V_199 = F_111 ( V_11 -> V_130 . V_191 , L_112 ) ;
if ( V_199 < 0 ) {
F_27 ( L_113 ) ;
goto V_221;
}
F_120 ( V_11 -> V_130 . V_191 ) ;
V_11 -> V_35 = F_93 ( V_11 -> V_130 . V_191 ) ^
V_11 -> V_130 . V_190 ;
if ( V_11 -> V_130 . V_222 ) {
F_121 ( & V_11 -> V_194 , F_92 ) ;
F_122 ( & V_11 -> V_195 , F_96 ,
( unsigned long ) V_11 ) ;
F_95 ( & V_11 -> V_195 ,
V_196 + V_197 ) ;
} else {
if ( F_119 ( V_11 -> V_130 . V_191 , F_89 ,
0 , V_33 , V_11 ) ) {
F_27 ( L_114 ,
V_11 -> V_130 . V_191 ) ;
V_199 = - V_201 ;
goto V_223;
}
}
} else {
F_27 ( L_115 ) ;
V_11 -> V_35 = 1 ;
}
V_199 = F_123 ( V_189 , & V_11 -> V_95 ) ;
if ( V_199 )
goto V_224;
F_101 ( V_189 , V_11 ) ;
F_124 ( V_189 , 1 ) ;
F_14 ( V_11 ) ;
F_125 ( L_116 , V_33 , V_34 ) ;
return 0 ;
V_224:
if ( F_110 ( V_11 -> V_130 . V_191 ) && ! V_11 -> V_130 . V_222 )
F_126 ( V_11 -> V_130 . V_191 , V_11 ) ;
V_223:
if ( F_110 ( V_11 -> V_130 . V_191 ) )
F_127 ( V_11 -> V_130 . V_191 ) ;
V_221:
F_126 ( V_11 -> V_219 , V_11 ) ;
V_220:
F_128 ( & V_11 -> V_95 . V_189 ) ;
V_218:
F_129 ( V_11 -> V_123 ) ;
V_217:
if ( F_63 () )
F_127 ( V_11 -> V_130 . V_135 ) ;
V_215:
F_130 ( V_206 -> V_212 , F_108 ( V_206 ) ) ;
F_27 ( L_117 , V_33 , V_199 ) ;
return V_199 ;
}
static int T_8 F_131 ( struct V_203 * V_204 )
{
struct V_10 * V_11 = F_104 ( V_204 ) ;
struct V_205 * V_206 ;
unsigned long V_9 ;
F_27 ( L_118 ) ;
F_132 ( & V_11 -> V_95 ) ;
if ( V_11 -> V_39 )
return - V_201 ;
F_2 ( & V_11 -> V_12 , V_9 ) ;
F_62 ( V_11 , 0 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
F_124 ( & V_204 -> V_189 , 0 ) ;
F_16 ( V_11 ) ;
if ( F_110 ( V_11 -> V_130 . V_191 ) ) {
F_126 ( V_11 -> V_130 . V_191 , V_11 ) ;
F_127 ( V_11 -> V_130 . V_191 ) ;
}
F_126 ( V_11 -> V_219 , V_11 ) ;
F_128 ( & V_11 -> V_95 . V_189 ) ;
F_129 ( V_11 -> V_123 ) ;
if ( F_63 () )
F_127 ( V_11 -> V_130 . V_135 ) ;
V_206 = F_106 ( V_204 , V_209 , 0 ) ;
F_130 ( V_206 -> V_212 , F_108 ( V_206 ) ) ;
F_133 ( V_11 -> V_126 ) ;
F_133 ( V_11 -> V_127 ) ;
return 0 ;
}
static int F_134 ( struct V_203 * V_204 , T_9 V_225 )
{
struct V_10 * V_11 = F_104 ( V_204 ) ;
int V_226 = V_11 -> V_39 && F_135 ( & V_204 -> V_189 ) ;
unsigned long V_9 ;
if ( ( ! V_11 -> V_38 && V_11 -> V_160 )
|| ! V_226
|| F_136 () ) {
F_2 ( & V_11 -> V_12 , V_9 ) ;
F_62 ( V_11 , 0 ) ;
V_226 = 0 ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
} else
F_137 ( V_11 -> V_219 ) ;
V_11 -> V_227 = V_226 ;
if ( F_110 ( V_11 -> V_130 . V_191 ) && ! V_11 -> V_130 . V_222 && V_226 )
F_137 ( V_11 -> V_130 . V_191 ) ;
return 0 ;
}
static int F_138 ( struct V_203 * V_204 )
{
struct V_10 * V_11 = F_104 ( V_204 ) ;
unsigned long V_9 ;
if ( F_110 ( V_11 -> V_130 . V_191 ) && ! V_11 -> V_130 . V_222 &&
V_11 -> V_227 )
F_139 ( V_11 -> V_130 . V_191 ) ;
if ( V_11 -> V_227 )
F_139 ( V_11 -> V_219 ) ;
else {
F_2 ( & V_11 -> V_12 , V_9 ) ;
F_62 ( V_11 , 1 ) ;
F_7 ( & V_11 -> V_12 , V_9 ) ;
}
return 0 ;
}
static int T_7 F_140 ( void )
{
return F_141 ( & V_228 , F_105 ) ;
}
static void T_8 F_142 ( void )
{
F_143 ( & V_228 ) ;
}
