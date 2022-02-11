static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = (struct V_4 * ) V_3 -> V_6 ;
return F_2 ( V_5 , struct V_1 , V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_7 ,
unsigned V_8 )
{
return F_4 ( V_7 -> V_9 + V_8 ) ;
}
static inline void F_5 ( struct V_1 * V_7 ,
T_1 V_10 , unsigned V_8 )
{
F_6 ( V_10 , V_7 -> V_9 + V_8 ) ;
}
static inline T_1 F_7 ( unsigned int V_3 , unsigned int V_11 ,
unsigned int V_12 , unsigned int V_13 )
{
return ( V_3 << 16 ) | ( V_11 << 11 ) | ( V_12 << 8 ) | ( V_13 & 0xfc ) |
0x80000000 ;
}
static T_1 F_8 ( struct V_1 * V_7 ,
unsigned V_3 , unsigned V_11 ,
unsigned V_12 , unsigned V_8 )
{
unsigned long V_14 ;
T_1 V_15 ;
T_1 V_16 ;
V_15 = F_7 ( V_3 , V_11 , V_12 , V_8 ) ;
F_9 ( & V_7 -> V_17 , V_14 ) ;
F_5 ( V_7 , V_15 , V_18 ) ;
V_16 = F_3 ( V_7 , V_19 ) ;
F_10 ( & V_7 -> V_17 , V_14 ) ;
return V_16 ;
}
static void F_11 ( struct V_1 * V_7 ,
unsigned V_3 , unsigned V_11 ,
unsigned V_12 , unsigned V_8 , T_1 V_10 )
{
unsigned long V_14 ;
T_1 V_15 ;
V_15 = F_7 ( V_3 , V_11 , V_12 , V_8 ) ;
F_9 ( & V_7 -> V_17 , V_14 ) ;
F_5 ( V_7 , V_15 , V_18 ) ;
F_5 ( V_7 , V_10 , V_19 ) ;
F_10 ( & V_7 -> V_17 , V_14 ) ;
}
static void F_12 ( unsigned int V_20 , struct V_21 * V_22 )
{
struct V_1 * V_7 ;
T_1 V_23 ;
V_7 = F_13 ( V_20 ) ;
V_23 = F_3 ( V_7 , V_24 ) &
F_3 ( V_7 , V_25 ) ;
if ( ! V_23 ) {
F_14 () ;
return;
}
while ( V_23 ) {
unsigned V_26 = F_15 ( V_23 ) ;
V_20 = F_16 ( V_7 -> V_27 , V_26 ) ;
F_17 ( V_20 ) ;
V_23 &= ~ F_18 ( V_26 ) ;
}
}
static void F_19 ( struct V_28 * V_29 )
{
struct V_1 * V_7 ;
T_1 V_30 ;
V_7 = F_20 ( V_29 ) ;
V_30 = F_3 ( V_7 , V_25 ) ;
F_5 ( V_7 , V_30 | F_18 ( V_29 -> V_31 ) , V_25 ) ;
F_3 ( V_7 , V_25 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_1 * V_7 ;
T_1 V_30 ;
V_7 = F_20 ( V_29 ) ;
V_30 = F_3 ( V_7 , V_25 ) ;
F_5 ( V_7 , V_30 & ~ F_18 ( V_29 -> V_31 ) , V_25 ) ;
F_3 ( V_7 , V_25 ) ;
}
static int F_22 ( struct V_27 * V_29 , unsigned int V_20 ,
T_2 V_32 )
{
F_23 ( V_20 , & V_33 , V_34 ) ;
F_24 ( V_20 , V_29 -> V_35 ) ;
return 0 ;
}
static int F_25 ( struct V_36 * V_37 ,
struct V_1 * V_7 )
{
int V_20 ;
V_20 = F_26 ( V_7 -> V_38 , 0 ) ;
if ( V_20 == 0 ) {
F_27 ( V_37 , L_1 ,
F_28 ( V_7 -> V_38 ) ) ;
return - V_39 ;
}
F_5 ( V_7 , 0 , V_25 ) ;
V_7 -> V_27 =
F_29 ( V_7 -> V_38 , V_40 ,
& V_41 ,
V_7 ) ;
if ( ! V_7 -> V_27 ) {
F_27 ( V_37 , L_2 ) ;
return - V_42 ;
}
F_30 ( V_20 , V_7 ) ;
F_31 ( V_20 , F_12 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , unsigned int V_43 ,
int V_13 , int V_44 , T_1 * V_10 )
{
struct V_1 * V_7 ;
unsigned long V_14 ;
T_1 V_15 ;
T_1 V_45 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 -> V_46 && V_3 -> V_47 == 1 )
return V_48 ;
V_15 = F_7 ( V_3 -> V_47 , F_33 ( V_43 ) ,
F_34 ( V_43 ) , V_13 ) ;
F_9 ( & V_7 -> V_17 , V_14 ) ;
F_5 ( V_7 , V_15 , V_18 ) ;
V_45 = F_3 ( V_7 , V_19 ) ;
F_10 ( & V_7 -> V_17 , V_14 ) ;
switch ( V_44 ) {
case 1 :
* V_10 = ( V_45 >> ( ( V_13 & 3 ) << 3 ) ) & 0xff ;
break;
case 2 :
* V_10 = ( V_45 >> ( ( V_13 & 3 ) << 3 ) ) & 0xffff ;
break;
case 4 :
* V_10 = V_45 ;
break;
}
return V_49 ;
}
static int F_35 ( struct V_2 * V_3 , unsigned int V_43 ,
int V_13 , int V_44 , T_1 V_10 )
{
struct V_1 * V_7 ;
unsigned long V_14 ;
T_1 V_15 ;
T_1 V_45 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 -> V_46 && V_3 -> V_47 == 1 )
return V_48 ;
V_15 = F_7 ( V_3 -> V_47 , F_33 ( V_43 ) ,
F_34 ( V_43 ) , V_13 ) ;
F_9 ( & V_7 -> V_17 , V_14 ) ;
F_5 ( V_7 , V_15 , V_18 ) ;
V_45 = F_3 ( V_7 , V_19 ) ;
switch ( V_44 ) {
case 1 :
V_45 = ( V_45 & ~ ( 0xff << ( ( V_13 & 3 ) << 3 ) ) ) |
( V_10 << ( ( V_13 & 3 ) << 3 ) ) ;
break;
case 2 :
V_45 = ( V_45 & ~ ( 0xffff << ( ( V_13 & 3 ) << 3 ) ) ) |
( V_10 << ( ( V_13 & 3 ) << 3 ) ) ;
break;
case 4 :
V_45 = V_10 ;
break;
}
F_5 ( V_7 , V_45 , V_19 ) ;
F_10 ( & V_7 -> V_17 , V_14 ) ;
return V_49 ;
}
static void F_36 ( struct V_1 * V_7 , unsigned V_50 )
{
T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 ;
T_1 V_30 ;
V_52 = F_37 ( V_54 ) ;
V_51 = F_37 ( V_55 ) ;
V_53 = F_37 ( V_56 ) ;
if ( V_50 & V_57 ) {
V_52 |= V_58 ;
F_38 ( V_52 , V_54 ) ;
V_51 &= ~ ( 0x30 ) ;
V_51 |= ( 2 << 4 ) ;
F_38 ( V_51 , V_55 ) ;
V_30 = F_37 ( V_59 ) ;
V_30 &= ~ F_18 ( 31 ) ;
F_38 ( V_30 , V_59 ) ;
V_30 = F_37 ( V_60 ) ;
V_30 &= 0x80ffffff ;
F_38 ( V_30 , V_60 ) ;
V_30 = F_37 ( V_60 ) ;
V_30 |= 0xa << 24 ;
F_38 ( V_30 , V_60 ) ;
V_30 = F_37 ( V_59 ) ;
V_30 |= F_18 ( 31 ) ;
F_38 ( V_30 , V_59 ) ;
F_39 ( 50 ) ;
V_52 &= ~ V_58 ;
F_38 ( V_52 , V_54 ) ;
}
V_51 |= ( V_61 | V_62 ) ;
V_53 &= ~ ( V_63 | V_64 ) ;
if ( V_50 & V_65 ) {
V_53 |= V_63 ;
V_52 &= ~ V_66 ;
}
if ( V_50 & V_57 ) {
V_53 |= V_64 ;
V_52 &= ~ V_58 ;
}
F_38 ( V_51 , V_55 ) ;
F_38 ( V_52 , V_54 ) ;
F_38 ( V_53 , V_56 ) ;
F_39 ( 500 ) ;
V_30 = ( V_67 << V_68 ) ;
F_5 ( V_7 , V_30 , V_69 ) ;
F_3 ( V_7 , V_69 ) ;
F_39 ( 500 ) ;
if ( V_50 & V_57 ) {
F_39 ( 500 ) ;
V_30 = F_3 ( V_7 , F_40 ( 1 ) ) ;
V_7 -> V_46 = V_30 & F_18 ( 0 ) ;
if ( ! V_7 -> V_46 ) {
V_30 = F_37 ( V_54 ) ;
V_30 |= V_58 ;
F_38 ( V_30 , V_54 ) ;
V_30 &= ~ V_58 ;
F_38 ( V_30 , V_54 ) ;
V_30 = F_37 ( V_56 ) ;
V_30 &= ~ V_64 ;
F_38 ( V_30 , V_56 ) ;
V_30 = F_37 ( V_59 ) ;
V_30 &= ~ 0xf000c080 ;
F_38 ( V_30 , V_59 ) ;
}
}
F_5 ( V_7 , 0x79 , V_70 ) ;
}
static int F_41 ( struct V_71 * V_72 )
{
struct V_1 * V_7 ;
struct V_36 * V_37 = & V_72 -> V_37 ;
struct V_73 * V_74 = V_37 -> V_75 ;
struct V_76 * V_77 ;
struct V_73 * V_78 ;
T_1 V_10 ;
int V_79 ;
int V_50 ;
V_7 = F_42 ( V_37 , sizeof( * V_7 ) , V_80 ) ;
if ( ! V_7 )
return - V_81 ;
V_77 = F_43 ( V_72 , V_82 , 0 ) ;
if ( ! V_77 )
return - V_39 ;
V_7 -> V_9 = F_44 ( V_37 , V_77 ) ;
if ( F_45 ( V_7 -> V_9 ) )
return F_46 ( V_7 -> V_9 ) ;
F_47 (np, child) {
if ( F_48 ( V_78 , L_3 , NULL ) &&
F_49 ( V_78 ) ) {
V_7 -> V_38 = V_78 ;
break;
}
}
if ( ! V_7 -> V_38 ) {
F_27 ( V_37 , L_4 ,
F_28 ( V_7 -> V_38 ) ,
L_5 ) ;
return - V_39 ;
}
F_47 (np, child) {
if ( V_78 -> type &&
F_50 ( V_78 -> type , L_6 ) == 0 &&
F_49 ( V_78 ) ) {
V_7 -> V_4 . V_75 = V_78 ;
break;
}
}
if ( ! V_7 -> V_4 . V_75 ) {
F_27 ( V_37 , L_4 ,
F_28 ( V_7 -> V_38 ) ,
L_7 ) ;
V_79 = - V_39 ;
goto V_83;
}
V_50 = V_84 ;
F_51 (rpc->pci_controller.of_node, child) {
int V_43 ;
if ( ! V_78 -> type ||
F_50 ( V_78 -> type , L_6 ) != 0 )
continue;
V_43 = F_52 ( V_78 ) ;
if ( V_43 < 0 )
continue;
switch ( F_33 ( V_43 ) ) {
case 1 :
V_50 |= V_57 ;
break;
case 17 :
case 18 :
V_50 |= V_65 ;
break;
}
}
if ( V_50 == V_84 ) {
F_27 ( V_37 , L_8 ) ;
V_79 = - V_39 ;
goto V_85;
}
F_53 ( V_37 , L_9 ,
( V_50 & V_65 ) ? L_10 : L_11 ,
( V_50 & V_57 ) ? L_12 : L_11 ) ;
F_36 ( V_7 , V_50 ) ;
V_7 -> V_4 . V_86 = & V_87 ;
V_7 -> V_4 . V_88 = & V_7 -> V_89 ;
V_7 -> V_4 . V_90 = & V_7 -> V_91 ;
F_54 ( & V_7 -> V_4 ,
V_7 -> V_4 . V_75 ) ;
F_5 ( V_7 , V_7 -> V_91 . V_92 , V_93 ) ;
F_5 ( V_7 , V_7 -> V_89 . V_92 , V_94 ) ;
V_95 . V_92 = V_7 -> V_89 . V_92 ;
V_95 . V_96 = V_7 -> V_89 . V_96 ;
F_5 ( V_7 , 0x03ff0000 , F_55 ( 0 ) ) ;
F_5 ( V_7 , V_97 , F_56 ( 0 ) ) ;
F_5 ( V_7 , 0x08021814 , F_57 ( 0 ) ) ;
F_5 ( V_7 , 0x00800001 , F_58 ( 0 ) ) ;
F_5 ( V_7 , 0x28801814 , F_59 ( 0 ) ) ;
F_5 ( V_7 , 0x03ff0000 , F_55 ( 1 ) ) ;
F_5 ( V_7 , V_97 , F_56 ( 1 ) ) ;
F_5 ( V_7 , 0x08021814 , F_57 ( 1 ) ) ;
F_5 ( V_7 , 0x06040001 , F_58 ( 1 ) ) ;
F_5 ( V_7 , 0x28801814 , F_59 ( 1 ) ) ;
V_79 = F_25 ( V_37 , V_7 ) ;
if ( V_79 )
goto V_85;
V_10 = F_8 ( V_7 , 0 , 0x01 , 0 , V_98 ) ;
V_10 |= V_99 | V_100 | V_101 ;
F_11 ( V_7 , 0 , 0x01 , 0 , V_98 , V_10 ) ;
V_10 = F_8 ( V_7 , 0 , 0x00 , 0 , V_98 ) ;
V_10 |= V_99 | V_100 | V_101 ;
F_11 ( V_7 , 0 , 0x00 , 0 , V_98 , V_10 ) ;
if ( V_50 == V_57 ) {
F_5 ( V_7 , 0x03ff0001 , F_55 ( 0 ) ) ;
F_5 ( V_7 , 0x03ff0001 , F_55 ( 1 ) ) ;
F_11 ( V_7 , 0 , V_67 , 0 ,
V_102 ,
V_97 ) ;
F_8 ( V_7 , 0 , V_67 , 0 ,
V_102 ) ;
} else {
F_11 ( V_7 , 0 , V_67 , 0 ,
V_103 , 0x00000101 ) ;
}
F_60 ( & V_7 -> V_4 ) ;
return 0 ;
V_85:
F_61 ( V_7 -> V_4 . V_75 ) ;
V_83:
F_61 ( V_7 -> V_38 ) ;
return V_79 ;
}
int T_3 F_62 ( const struct V_104 * V_37 , T_4 V_11 , T_4 V_105 )
{
return F_63 ( V_37 , V_11 , V_105 ) ;
}
int F_64 ( struct V_104 * V_37 )
{
return 0 ;
}
static int T_3 F_65 ( void )
{
return F_66 ( & V_106 ) ;
}
