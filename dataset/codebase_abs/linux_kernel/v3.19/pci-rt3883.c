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
F_5 ( V_7 , V_15 , V_17 ) ;
V_16 = F_3 ( V_7 , V_18 ) ;
return V_16 ;
}
static void F_9 ( struct V_1 * V_7 ,
unsigned V_3 , unsigned V_11 ,
unsigned V_12 , unsigned V_8 , T_1 V_10 )
{
unsigned long V_14 ;
T_1 V_15 ;
V_15 = F_7 ( V_3 , V_11 , V_12 , V_8 ) ;
F_5 ( V_7 , V_15 , V_17 ) ;
F_5 ( V_7 , V_10 , V_18 ) ;
}
static void F_10 ( unsigned int V_19 , struct V_20 * V_21 )
{
struct V_1 * V_7 ;
T_1 V_22 ;
V_7 = F_11 ( V_19 ) ;
V_22 = F_3 ( V_7 , V_23 ) &
F_3 ( V_7 , V_24 ) ;
if ( ! V_22 ) {
F_12 () ;
return;
}
while ( V_22 ) {
unsigned V_25 = F_13 ( V_22 ) ;
V_19 = F_14 ( V_7 -> V_26 , V_25 ) ;
F_15 ( V_19 ) ;
V_22 &= ~ F_16 ( V_25 ) ;
}
}
static void F_17 ( struct V_27 * V_28 )
{
struct V_1 * V_7 ;
T_1 V_29 ;
V_7 = F_18 ( V_28 ) ;
V_29 = F_3 ( V_7 , V_24 ) ;
F_5 ( V_7 , V_29 | F_16 ( V_28 -> V_30 ) , V_24 ) ;
F_3 ( V_7 , V_24 ) ;
}
static void F_19 ( struct V_27 * V_28 )
{
struct V_1 * V_7 ;
T_1 V_29 ;
V_7 = F_18 ( V_28 ) ;
V_29 = F_3 ( V_7 , V_24 ) ;
F_5 ( V_7 , V_29 & ~ F_16 ( V_28 -> V_30 ) , V_24 ) ;
F_3 ( V_7 , V_24 ) ;
}
static int F_20 ( struct V_26 * V_28 , unsigned int V_19 ,
T_2 V_31 )
{
F_21 ( V_19 , & V_32 , V_33 ) ;
F_22 ( V_19 , V_28 -> V_34 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_1 * V_7 )
{
int V_19 ;
V_19 = F_24 ( V_7 -> V_37 , 0 ) ;
if ( V_19 == 0 ) {
F_25 ( V_36 , L_1 ,
F_26 ( V_7 -> V_37 ) ) ;
return - V_38 ;
}
F_5 ( V_7 , 0 , V_24 ) ;
V_7 -> V_26 =
F_27 ( V_7 -> V_37 , V_39 ,
& V_40 ,
V_7 ) ;
if ( ! V_7 -> V_26 ) {
F_25 ( V_36 , L_2 ) ;
return - V_41 ;
}
F_28 ( V_19 , V_7 ) ;
F_29 ( V_19 , F_10 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , unsigned int V_42 ,
int V_13 , int V_43 , T_1 * V_10 )
{
struct V_1 * V_7 ;
unsigned long V_14 ;
T_1 V_15 ;
T_1 V_44 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 -> V_45 && V_3 -> V_46 == 1 )
return V_47 ;
V_15 = F_7 ( V_3 -> V_46 , F_31 ( V_42 ) ,
F_32 ( V_42 ) , V_13 ) ;
F_5 ( V_7 , V_15 , V_17 ) ;
V_44 = F_3 ( V_7 , V_18 ) ;
switch ( V_43 ) {
case 1 :
* V_10 = ( V_44 >> ( ( V_13 & 3 ) << 3 ) ) & 0xff ;
break;
case 2 :
* V_10 = ( V_44 >> ( ( V_13 & 3 ) << 3 ) ) & 0xffff ;
break;
case 4 :
* V_10 = V_44 ;
break;
}
return V_48 ;
}
static int F_33 ( struct V_2 * V_3 , unsigned int V_42 ,
int V_13 , int V_43 , T_1 V_10 )
{
struct V_1 * V_7 ;
unsigned long V_14 ;
T_1 V_15 ;
T_1 V_44 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 -> V_45 && V_3 -> V_46 == 1 )
return V_47 ;
V_15 = F_7 ( V_3 -> V_46 , F_31 ( V_42 ) ,
F_32 ( V_42 ) , V_13 ) ;
F_5 ( V_7 , V_15 , V_17 ) ;
V_44 = F_3 ( V_7 , V_18 ) ;
switch ( V_43 ) {
case 1 :
V_44 = ( V_44 & ~ ( 0xff << ( ( V_13 & 3 ) << 3 ) ) ) |
( V_10 << ( ( V_13 & 3 ) << 3 ) ) ;
break;
case 2 :
V_44 = ( V_44 & ~ ( 0xffff << ( ( V_13 & 3 ) << 3 ) ) ) |
( V_10 << ( ( V_13 & 3 ) << 3 ) ) ;
break;
case 4 :
V_44 = V_10 ;
break;
}
F_5 ( V_7 , V_44 , V_18 ) ;
return V_48 ;
}
static void F_34 ( struct V_1 * V_7 , unsigned V_49 )
{
T_1 V_50 ;
T_1 V_51 ;
T_1 V_52 ;
T_1 V_29 ;
V_51 = F_35 ( V_53 ) ;
V_50 = F_35 ( V_54 ) ;
V_52 = F_35 ( V_55 ) ;
if ( V_49 & V_56 ) {
V_51 |= V_57 ;
F_36 ( V_51 , V_53 ) ;
V_50 &= ~ ( 0x30 ) ;
V_50 |= ( 2 << 4 ) ;
F_36 ( V_50 , V_54 ) ;
V_29 = F_35 ( V_58 ) ;
V_29 &= ~ F_16 ( 31 ) ;
F_36 ( V_29 , V_58 ) ;
V_29 = F_35 ( V_59 ) ;
V_29 &= 0x80ffffff ;
F_36 ( V_29 , V_59 ) ;
V_29 = F_35 ( V_59 ) ;
V_29 |= 0xa << 24 ;
F_36 ( V_29 , V_59 ) ;
V_29 = F_35 ( V_58 ) ;
V_29 |= F_16 ( 31 ) ;
F_36 ( V_29 , V_58 ) ;
F_37 ( 50 ) ;
V_51 &= ~ V_57 ;
F_36 ( V_51 , V_53 ) ;
}
V_50 |= ( V_60 | V_61 ) ;
V_52 &= ~ ( V_62 | V_63 ) ;
if ( V_49 & V_64 ) {
V_52 |= V_62 ;
V_51 &= ~ V_65 ;
}
if ( V_49 & V_56 ) {
V_52 |= V_63 ;
V_51 &= ~ V_57 ;
}
F_36 ( V_50 , V_54 ) ;
F_36 ( V_51 , V_53 ) ;
F_36 ( V_52 , V_55 ) ;
F_37 ( 500 ) ;
V_29 = ( V_66 << V_67 ) ;
F_5 ( V_7 , V_29 , V_68 ) ;
F_3 ( V_7 , V_68 ) ;
F_37 ( 500 ) ;
if ( V_49 & V_56 ) {
F_37 ( 500 ) ;
V_29 = F_3 ( V_7 , F_38 ( 1 ) ) ;
V_7 -> V_45 = V_29 & F_16 ( 0 ) ;
if ( ! V_7 -> V_45 ) {
V_29 = F_35 ( V_53 ) ;
V_29 |= V_57 ;
F_36 ( V_29 , V_53 ) ;
V_29 &= ~ V_57 ;
F_36 ( V_29 , V_53 ) ;
V_29 = F_35 ( V_55 ) ;
V_29 &= ~ V_63 ;
F_36 ( V_29 , V_55 ) ;
V_29 = F_35 ( V_58 ) ;
V_29 &= ~ 0xf000c080 ;
F_36 ( V_29 , V_58 ) ;
}
}
F_5 ( V_7 , 0x79 , V_69 ) ;
}
static int F_39 ( struct V_70 * V_71 )
{
struct V_1 * V_7 ;
struct V_35 * V_36 = & V_71 -> V_36 ;
struct V_72 * V_73 = V_36 -> V_74 ;
struct V_75 * V_76 ;
struct V_72 * V_77 ;
T_1 V_10 ;
int V_78 ;
int V_49 ;
V_7 = F_40 ( V_36 , sizeof( * V_7 ) , V_79 ) ;
if ( ! V_7 )
return - V_80 ;
V_76 = F_41 ( V_71 , V_81 , 0 ) ;
V_7 -> V_9 = F_42 ( V_36 , V_76 ) ;
if ( F_43 ( V_7 -> V_9 ) )
return F_44 ( V_7 -> V_9 ) ;
F_45 (np, child) {
if ( F_46 ( V_77 , L_3 , NULL ) &&
F_47 ( V_77 ) ) {
V_7 -> V_37 = V_77 ;
break;
}
}
if ( ! V_7 -> V_37 ) {
F_25 ( V_36 , L_4 ,
F_26 ( V_7 -> V_37 ) ,
L_5 ) ;
return - V_38 ;
}
F_45 (np, child) {
if ( V_77 -> type &&
F_48 ( V_77 -> type , L_6 ) == 0 &&
F_47 ( V_77 ) ) {
V_7 -> V_4 . V_74 = V_77 ;
break;
}
}
if ( ! V_7 -> V_4 . V_74 ) {
F_25 ( V_36 , L_4 ,
F_26 ( V_7 -> V_37 ) ,
L_7 ) ;
V_78 = - V_38 ;
goto V_82;
}
V_49 = V_83 ;
F_49 (rpc->pci_controller.of_node, child) {
int V_42 ;
if ( ! V_77 -> type ||
F_48 ( V_77 -> type , L_6 ) != 0 )
continue;
V_42 = F_50 ( V_77 ) ;
if ( V_42 < 0 )
continue;
switch ( F_31 ( V_42 ) ) {
case 1 :
V_49 |= V_56 ;
break;
case 17 :
case 18 :
V_49 |= V_64 ;
break;
}
}
if ( V_49 == V_83 ) {
F_25 ( V_36 , L_8 ) ;
V_78 = - V_38 ;
goto V_84;
}
F_51 ( V_36 , L_9 ,
( V_49 & V_64 ) ? L_10 : L_11 ,
( V_49 & V_56 ) ? L_12 : L_11 ) ;
F_34 ( V_7 , V_49 ) ;
V_7 -> V_4 . V_85 = & V_86 ;
V_7 -> V_4 . V_87 = & V_7 -> V_88 ;
V_7 -> V_4 . V_89 = & V_7 -> V_90 ;
F_52 ( & V_7 -> V_4 ,
V_7 -> V_4 . V_74 ) ;
F_5 ( V_7 , V_7 -> V_90 . V_91 , V_92 ) ;
F_5 ( V_7 , V_7 -> V_88 . V_91 , V_93 ) ;
V_94 . V_91 = V_7 -> V_88 . V_91 ;
V_94 . V_95 = V_7 -> V_88 . V_95 ;
F_5 ( V_7 , 0x03ff0000 , F_53 ( 0 ) ) ;
F_5 ( V_7 , V_96 , F_54 ( 0 ) ) ;
F_5 ( V_7 , 0x08021814 , F_55 ( 0 ) ) ;
F_5 ( V_7 , 0x00800001 , F_56 ( 0 ) ) ;
F_5 ( V_7 , 0x28801814 , F_57 ( 0 ) ) ;
F_5 ( V_7 , 0x03ff0000 , F_53 ( 1 ) ) ;
F_5 ( V_7 , V_96 , F_54 ( 1 ) ) ;
F_5 ( V_7 , 0x08021814 , F_55 ( 1 ) ) ;
F_5 ( V_7 , 0x06040001 , F_56 ( 1 ) ) ;
F_5 ( V_7 , 0x28801814 , F_57 ( 1 ) ) ;
V_78 = F_23 ( V_36 , V_7 ) ;
if ( V_78 )
goto V_84;
V_10 = F_8 ( V_7 , 0 , 0x01 , 0 , V_97 ) ;
V_10 |= V_98 | V_99 | V_100 ;
F_9 ( V_7 , 0 , 0x01 , 0 , V_97 , V_10 ) ;
V_10 = F_8 ( V_7 , 0 , 0x00 , 0 , V_97 ) ;
V_10 |= V_98 | V_99 | V_100 ;
F_9 ( V_7 , 0 , 0x00 , 0 , V_97 , V_10 ) ;
if ( V_49 == V_56 ) {
F_5 ( V_7 , 0x03ff0001 , F_53 ( 0 ) ) ;
F_5 ( V_7 , 0x03ff0001 , F_53 ( 1 ) ) ;
F_9 ( V_7 , 0 , V_66 , 0 ,
V_101 ,
V_96 ) ;
F_8 ( V_7 , 0 , V_66 , 0 ,
V_101 ) ;
} else {
F_9 ( V_7 , 0 , V_66 , 0 ,
V_102 , 0x00000101 ) ;
}
F_58 ( & V_7 -> V_4 ) ;
return 0 ;
V_84:
F_59 ( V_7 -> V_4 . V_74 ) ;
V_82:
F_59 ( V_7 -> V_37 ) ;
return V_78 ;
}
int T_3 F_60 ( const struct V_103 * V_36 , T_4 V_11 , T_4 V_104 )
{
return F_61 ( V_36 , V_11 , V_104 ) ;
}
int F_62 ( struct V_103 * V_36 )
{
return 0 ;
}
static int T_3 F_63 ( void )
{
return F_64 ( & V_105 ) ;
}
