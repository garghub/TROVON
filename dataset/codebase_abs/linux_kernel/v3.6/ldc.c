static const char * F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
default:
return L_6 ;
}
}
static void F_2 ( struct V_7 * V_8 , T_1 V_1 )
{
F_3 ( V_9 , L_7 ,
F_1 ( V_8 -> V_1 ) ,
F_1 ( V_1 ) ) ;
V_8 -> V_1 = V_1 ;
}
static unsigned long F_4 ( unsigned long V_10 , unsigned long V_11 )
{
V_10 += V_12 ;
if ( V_10 == ( V_11 * V_12 ) )
V_10 = 0 ;
return V_10 ;
}
static unsigned long F_5 ( struct V_7 * V_8 , unsigned long V_10 )
{
return F_4 ( V_10 , V_8 -> V_13 ) ;
}
static unsigned long F_6 ( struct V_7 * V_8 , unsigned long V_10 )
{
return F_4 ( V_10 , V_8 -> V_14 ) ;
}
static struct V_15 * F_7 ( struct V_7 * V_8 ,
unsigned long * V_16 )
{
struct V_15 * V_17 ;
unsigned long V_18 ;
V_18 = F_6 ( V_8 , V_8 -> V_19 ) ;
if ( V_18 == V_8 -> V_20 )
return NULL ;
* V_16 = V_18 ;
V_17 = V_8 -> V_21 ;
return V_17 + ( V_8 -> V_19 / V_12 ) ;
}
static unsigned long F_8 ( struct V_7 * V_8 )
{
if ( V_8 -> V_22 . V_23 == V_24 )
return V_8 -> V_25 ;
return V_8 -> V_20 ;
}
static int F_9 ( struct V_7 * V_8 , unsigned int V_26 )
{
unsigned long V_27 , V_28 , V_16 , V_29 ;
unsigned int V_30 ;
V_27 = F_8 ( V_8 ) ;
V_28 = V_8 -> V_19 ;
V_16 = F_6 ( V_8 , V_28 ) ;
if ( V_16 == V_27 )
return 0 ;
if ( V_27 > V_16 )
V_29 = V_27 - V_16 ;
else
V_29 = ( V_27 +
( ( V_8 -> V_14 * V_12 ) - V_16 ) ) ;
V_29 /= V_12 ;
V_30 = V_8 -> V_30 ;
if ( V_29 * V_30 < V_26 )
return 0 ;
return 1 ;
}
static struct V_15 * F_10 ( struct V_7 * V_8 ,
unsigned long * V_16 )
{
struct V_15 * V_17 ;
unsigned long V_31 , V_18 ;
V_31 = F_8 ( V_8 ) ;
V_18 = F_6 ( V_8 , V_8 -> V_19 ) ;
if ( V_18 == V_31 )
return NULL ;
* V_16 = V_18 ;
V_17 = V_8 -> V_21 ;
return V_17 + ( V_8 -> V_19 / V_12 ) ;
}
static int F_11 ( struct V_7 * V_8 , unsigned long V_28 )
{
unsigned long V_32 = V_8 -> V_19 ;
int V_27 = 1000 ;
V_8 -> V_19 = V_28 ;
while ( V_27 -- > 0 ) {
unsigned long V_33 ;
V_33 = F_12 ( V_8 -> V_34 , V_28 ) ;
if ( ! V_33 )
return 0 ;
if ( V_33 != V_35 ) {
V_8 -> V_19 = V_32 ;
return - V_36 ;
}
F_13 ( 1 ) ;
}
V_8 -> V_19 = V_32 ;
return - V_37 ;
}
static int F_14 ( struct V_7 * V_8 , unsigned long V_38 )
{
int V_27 = 1000 ;
while ( V_27 -- > 0 ) {
unsigned long V_33 ;
V_33 = F_15 ( V_8 -> V_34 , V_38 ) ;
if ( ! V_33 )
return 0 ;
if ( V_33 != V_35 )
return - V_36 ;
F_13 ( 1 ) ;
}
return - V_37 ;
}
static int F_16 ( struct V_7 * V_8 ,
struct V_15 * V_17 ,
unsigned long V_16 )
{
F_17 ( V_17 != ( V_8 -> V_21 + ( V_8 -> V_19 / V_12 ) ) ) ;
return F_11 ( V_8 , V_16 ) ;
}
static struct V_15 * F_18 ( struct V_7 * V_8 ,
T_1 V_39 , T_1 V_40 ,
void * V_41 , int V_42 ,
unsigned long * V_16 )
{
struct V_15 * V_17 = F_7 ( V_8 , V_16 ) ;
if ( V_17 ) {
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> type = V_43 ;
V_17 -> V_39 = V_39 ;
V_17 -> V_40 = V_40 ;
if ( V_41 )
memcpy ( V_17 -> V_44 . V_45 , V_41 , V_42 ) ;
}
return V_17 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_15 * V_17 ;
struct V_46 * V_47 ;
unsigned long V_16 ;
V_47 = & V_48 [ 0 ] ;
F_3 ( V_49 , L_8 ,
V_47 -> V_50 , V_47 -> V_51 ) ;
V_17 = F_18 ( V_8 , V_52 , V_53 ,
V_47 , sizeof( * V_47 ) , & V_16 ) ;
if ( V_17 ) {
int V_33 = F_16 ( V_8 , V_17 , V_16 ) ;
if ( ! V_33 )
V_8 -> V_54 &= ~ V_55 ;
return V_33 ;
}
return - V_37 ;
}
static int F_20 ( struct V_7 * V_8 ,
T_2 V_50 , T_2 V_51 )
{
struct V_15 * V_17 ;
struct V_46 V_47 ;
unsigned long V_16 ;
V_47 . V_50 = V_50 ;
V_47 . V_51 = V_51 ;
V_17 = F_18 ( V_8 , V_56 , V_53 ,
& V_47 , sizeof( V_47 ) , & V_16 ) ;
if ( V_17 ) {
F_3 ( V_49 , L_9 ,
V_47 . V_50 , V_47 . V_51 ) ;
return F_16 ( V_8 , V_17 , V_16 ) ;
}
return - V_37 ;
}
static int F_21 ( struct V_7 * V_8 ,
struct V_46 * V_57 )
{
struct V_15 * V_17 ;
unsigned long V_16 ;
V_17 = F_18 ( V_8 , V_58 , V_53 ,
V_57 , sizeof( * V_57 ) , & V_16 ) ;
if ( V_17 ) {
F_3 ( V_49 , L_10 ,
V_57 -> V_50 , V_57 -> V_51 ) ;
return F_16 ( V_8 , V_17 , V_16 ) ;
}
return - V_37 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_15 * V_17 ;
unsigned long V_16 ;
V_17 = F_18 ( V_8 , V_52 , V_59 , NULL , 0 ,
& V_16 ) ;
if ( V_17 ) {
V_17 -> V_60 = V_8 -> V_22 . V_23 ;
V_17 -> V_61 = 0 ;
V_8 -> V_62 = 0 ;
F_3 ( V_49 , L_11 ,
V_17 -> V_60 , V_17 -> V_61 ) ;
return F_16 ( V_8 , V_17 , V_16 ) ;
}
return - V_37 ;
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_15 * V_17 ;
unsigned long V_16 ;
V_17 = F_18 ( V_8 , V_52 , V_63 , NULL , 0 ,
& V_16 ) ;
if ( V_17 ) {
V_17 -> V_60 = V_8 -> V_22 . V_23 ;
V_17 -> V_61 = 0 ;
F_3 ( V_49 , L_12 ,
V_17 -> V_60 , V_17 -> V_61 ) ;
return F_16 ( V_8 , V_17 , V_16 ) ;
}
return - V_37 ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_15 * V_17 ;
unsigned long V_16 ;
V_17 = F_18 ( V_8 , V_52 , V_64 , NULL , 0 ,
& V_16 ) ;
if ( V_17 ) {
V_17 -> V_60 = 0 ;
V_17 -> V_61 = ++ V_8 -> V_65 ;
V_17 -> V_44 . V_66 . V_67 = V_8 -> V_62 ;
F_3 ( V_49 , L_13 ,
V_17 -> V_60 , V_17 -> V_61 , V_17 -> V_44 . V_66 . V_67 ) ;
return F_16 ( V_8 , V_17 , V_16 ) ;
}
return - V_37 ;
}
static int F_25 ( struct V_7 * V_8 , struct V_15 * V_68 )
{
struct V_15 * V_17 ;
unsigned long V_16 ;
int V_33 ;
V_17 = F_10 ( V_8 , & V_16 ) ;
if ( ! V_17 )
return - V_37 ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> type = V_68 -> type ;
V_17 -> V_39 = V_56 ;
V_17 -> V_40 = V_68 -> V_40 & V_69 ;
V_17 -> V_61 = V_8 -> V_65 + 1 ;
V_17 -> V_44 . V_66 . V_67 = V_8 -> V_62 ;
F_3 ( V_49 , L_14 ,
V_17 -> type , V_17 -> V_40 , V_17 -> V_61 , V_17 -> V_44 . V_66 . V_67 ) ;
V_33 = F_16 ( V_8 , V_17 , V_16 ) ;
if ( ! V_33 )
V_8 -> V_65 ++ ;
return V_33 ;
}
static int F_26 ( struct V_7 * V_8 )
{
unsigned long V_70 ;
F_3 ( V_9 , L_15 ) ;
V_70 = F_27 ( V_8 -> V_34 , V_8 -> V_71 , V_8 -> V_14 ) ;
if ( V_70 )
F_28 (KERN_ERR PFX L_16
L_17 ,
lp->id, lp->tx_ra, lp->tx_num_entries, hv_err) ;
V_70 = F_29 ( V_8 -> V_34 ,
& V_8 -> V_20 ,
& V_8 -> V_19 ,
& V_8 -> V_72 ) ;
if ( V_70 )
F_28 (KERN_ERR PFX L_16
L_18 ,
lp->id, hv_err) ;
V_70 = F_30 ( V_8 -> V_34 , V_8 -> V_73 , V_8 -> V_13 ) ;
if ( V_70 )
F_28 (KERN_ERR PFX L_16
L_19 ,
lp->id, lp->rx_ra, lp->rx_num_entries, hv_err) ;
V_70 = F_31 ( V_8 -> V_34 ,
& V_8 -> V_74 ,
& V_8 -> V_75 ,
& V_8 -> V_72 ) ;
if ( V_70 )
F_28 (KERN_ERR PFX L_16
L_20 ,
lp->id, hv_err) ;
return - V_76 ;
}
static struct V_46 * F_32 ( T_2 V_50 )
{
struct V_46 * V_77 = NULL ;
int V_78 ;
for ( V_78 = 0 ; V_78 < F_33 ( V_48 ) ; V_78 ++ ) {
struct V_46 * V_79 = & V_48 [ V_78 ] ;
if ( V_79 -> V_50 <= V_50 ) {
V_77 = V_79 ;
break;
}
}
return V_77 ;
}
static int F_34 ( struct V_7 * V_8 , struct V_46 * V_57 )
{
struct V_46 * V_80 ;
int V_33 ;
F_3 ( V_49 , L_21 ,
V_57 -> V_50 , V_57 -> V_51 ) ;
if ( V_8 -> V_81 == V_82 ) {
V_8 -> V_81 = V_83 ;
memset ( & V_8 -> V_47 , 0 , sizeof( V_8 -> V_47 ) ) ;
}
V_80 = F_32 ( V_57 -> V_50 ) ;
if ( ! V_80 ) {
V_33 = F_20 ( V_8 , 0 , 0 ) ;
} else if ( V_80 -> V_50 != V_57 -> V_50 ) {
V_33 = F_20 ( V_8 , V_80 -> V_50 , V_80 -> V_51 ) ;
} else {
struct V_46 V_47 = * V_57 ;
if ( V_47 . V_51 > V_80 -> V_51 )
V_47 . V_51 = V_80 -> V_51 ;
V_33 = F_21 ( V_8 , & V_47 ) ;
if ( ! V_33 ) {
V_8 -> V_47 = V_47 ;
V_8 -> V_81 = V_82 ;
}
}
if ( V_33 )
return F_26 ( V_8 ) ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 , struct V_46 * V_57 )
{
F_3 ( V_49 , L_22 ,
V_57 -> V_50 , V_57 -> V_51 ) ;
if ( V_8 -> V_81 == V_82 ) {
if ( V_8 -> V_47 . V_50 != V_57 -> V_50 ||
V_8 -> V_47 . V_51 != V_57 -> V_51 )
return F_26 ( V_8 ) ;
} else {
V_8 -> V_47 = * V_57 ;
V_8 -> V_81 = V_82 ;
}
if ( F_22 ( V_8 ) )
return F_26 ( V_8 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 , struct V_46 * V_57 )
{
struct V_46 * V_80 ;
struct V_15 * V_17 ;
unsigned long V_16 ;
if ( V_57 -> V_50 == 0 && V_57 -> V_51 == 0 )
return F_26 ( V_8 ) ;
V_80 = F_32 ( V_57 -> V_50 ) ;
if ( ! V_80 )
return F_26 ( V_8 ) ;
V_17 = F_18 ( V_8 , V_52 , V_53 ,
V_80 , sizeof( * V_80 ) ,
& V_16 ) ;
if ( ! V_17 )
return F_26 ( V_8 ) ;
return F_16 ( V_8 , V_17 , V_16 ) ;
}
static int F_37 ( struct V_7 * V_8 ,
struct V_15 * V_17 )
{
struct V_46 * V_57 ;
V_57 = (struct V_46 * ) V_17 -> V_44 . V_45 ;
switch ( V_17 -> V_39 ) {
case V_52 :
return F_34 ( V_8 , V_57 ) ;
case V_58 :
return F_35 ( V_8 , V_57 ) ;
case V_56 :
return F_36 ( V_8 , V_57 ) ;
default:
return F_26 ( V_8 ) ;
}
}
static int F_38 ( struct V_7 * V_8 ,
struct V_15 * V_17 )
{
F_3 ( V_49 , L_23 ,
V_17 -> V_39 , V_17 -> V_61 , V_17 -> V_60 ) ;
if ( V_17 -> V_39 != V_52 ||
V_8 -> V_81 != V_82 ||
V_17 -> V_60 != V_8 -> V_22 . V_23 )
return F_26 ( V_8 ) ;
V_8 -> V_65 = V_17 -> V_61 ;
V_8 -> V_62 = V_17 -> V_61 ;
V_8 -> V_81 = V_84 ;
if ( F_23 ( V_8 ) )
return F_26 ( V_8 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 ,
struct V_15 * V_17 )
{
F_3 ( V_49 , L_24 ,
V_17 -> V_39 , V_17 -> V_61 , V_17 -> V_60 ) ;
if ( V_17 -> V_39 != V_52 ||
V_17 -> V_60 != V_8 -> V_22 . V_23 )
return F_26 ( V_8 ) ;
V_8 -> V_65 = V_17 -> V_61 ;
V_8 -> V_81 = V_85 ;
F_2 ( V_8 , V_6 ) ;
F_24 ( V_8 ) ;
return V_86 ;
}
static int F_40 ( struct V_7 * V_8 , T_3 V_61 )
{
return V_8 -> V_62 + 1 == V_61 ;
}
static int F_41 ( struct V_7 * V_8 ,
struct V_15 * V_17 )
{
F_3 ( V_49 , L_25 ,
V_17 -> V_39 , V_17 -> V_61 , V_17 -> V_60 , V_17 -> V_44 . V_66 . V_67 ) ;
if ( V_17 -> V_39 != V_52 ||
! ( F_40 ( V_8 , V_17 -> V_61 ) ) )
return F_26 ( V_8 ) ;
V_8 -> V_62 = V_17 -> V_61 ;
V_8 -> V_81 = V_85 ;
F_2 ( V_8 , V_6 ) ;
return V_86 ;
}
static int F_42 ( struct V_7 * V_8 ,
struct V_15 * V_17 )
{
switch ( V_17 -> V_40 ) {
case V_53 :
return F_37 ( V_8 , V_17 ) ;
case V_59 :
return F_38 ( V_8 , V_17 ) ;
case V_63 :
return F_39 ( V_8 , V_17 ) ;
case V_64 :
return F_41 ( V_8 , V_17 ) ;
default:
return F_26 ( V_8 ) ;
}
}
static int F_43 ( struct V_7 * V_8 ,
struct V_15 * V_17 )
{
return F_26 ( V_8 ) ;
}
static int F_44 ( struct V_7 * V_8 ,
struct V_15 * V_87 )
{
unsigned long V_38 = V_8 -> V_25 ;
T_3 V_67 = V_87 -> V_44 . V_66 . V_67 ;
while ( 1 ) {
struct V_15 * V_17 = V_8 -> V_21 + ( V_38 / V_12 ) ;
V_38 = F_6 ( V_8 , V_38 ) ;
if ( V_17 -> V_61 == V_67 ) {
V_8 -> V_25 = V_38 ;
return 0 ;
}
if ( V_38 == V_8 -> V_19 )
return F_26 ( V_8 ) ;
}
return 0 ;
}
static void F_45 ( struct V_7 * V_8 , unsigned int V_88 )
{
if ( V_88 & V_89 )
V_8 -> V_22 . V_90 ( V_8 -> V_91 , V_89 ) ;
if ( V_88 & V_86 )
V_8 -> V_22 . V_90 ( V_8 -> V_91 , V_86 ) ;
if ( V_88 & V_92 )
V_8 -> V_22 . V_90 ( V_8 -> V_91 , V_92 ) ;
}
static T_4 F_46 ( int V_93 , void * V_94 )
{
struct V_7 * V_8 = V_94 ;
unsigned long V_95 , V_54 ;
unsigned int V_88 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
V_95 = V_8 -> V_72 ;
F_31 ( V_8 -> V_34 ,
& V_8 -> V_74 ,
& V_8 -> V_75 ,
& V_8 -> V_72 ) ;
F_3 ( V_97 , L_26 ,
V_95 , V_8 -> V_72 , V_8 -> V_74 , V_8 -> V_75 ) ;
V_88 = 0 ;
if ( V_8 -> V_22 . V_23 == V_98 &&
V_8 -> V_72 == V_99 ) {
V_8 -> V_81 = V_85 ;
F_2 ( V_8 , V_6 ) ;
V_88 |= V_86 ;
V_95 = V_8 -> V_72 ;
}
if ( V_8 -> V_54 & V_55 ) {
( void ) F_14 ( V_8 , V_8 -> V_75 ) ;
goto V_100;
}
if ( V_8 -> V_81 == V_85 ) {
V_101:
if ( V_8 -> V_72 != V_95 ) {
unsigned int V_90 = V_89 ;
if ( V_8 -> V_72 == V_99 )
V_90 = V_86 ;
V_88 |= V_90 ;
}
if ( V_8 -> V_74 != V_8 -> V_75 )
V_88 |= V_92 ;
goto V_100;
}
if ( V_8 -> V_72 != V_95 )
goto V_100;
while ( V_8 -> V_74 != V_8 -> V_75 ) {
struct V_15 * V_17 ;
unsigned long V_102 ;
int V_33 ;
V_17 = V_8 -> V_103 + ( V_8 -> V_74 / V_12 ) ;
switch ( V_17 -> type ) {
case V_43 :
V_33 = F_42 ( V_8 , V_17 ) ;
if ( V_33 > 0 )
V_88 |= V_33 ;
break;
case V_104 :
V_88 |= V_92 ;
V_33 = 0 ;
break;
case V_105 :
V_33 = F_43 ( V_8 , V_17 ) ;
break;
default:
V_33 = F_26 ( V_8 ) ;
break;
}
if ( V_33 < 0 )
break;
V_102 = V_8 -> V_74 ;
V_102 += V_12 ;
if ( V_102 == ( V_8 -> V_13 * V_12 ) )
V_102 = 0 ;
V_8 -> V_74 = V_102 ;
V_33 = F_14 ( V_8 , V_102 ) ;
if ( V_33 < 0 ) {
( void ) F_26 ( V_8 ) ;
break;
}
if ( V_8 -> V_81 == V_85 )
goto V_101;
}
V_100:
F_48 ( & V_8 -> V_96 , V_54 ) ;
F_45 ( V_8 , V_88 ) ;
return V_106 ;
}
static T_4 F_49 ( int V_93 , void * V_94 )
{
struct V_7 * V_8 = V_94 ;
unsigned long V_54 , V_95 ;
unsigned int V_88 = 0 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
V_95 = V_8 -> V_72 ;
F_29 ( V_8 -> V_34 ,
& V_8 -> V_20 ,
& V_8 -> V_19 ,
& V_8 -> V_72 ) ;
F_3 ( V_107 , L_27 ,
V_95 , V_8 -> V_72 , V_8 -> V_20 , V_8 -> V_19 ) ;
if ( V_8 -> V_22 . V_23 == V_98 &&
V_8 -> V_72 == V_99 ) {
V_8 -> V_81 = V_85 ;
F_2 ( V_8 , V_6 ) ;
V_88 |= V_86 ;
}
F_48 ( & V_8 -> V_96 , V_54 ) ;
F_45 ( V_8 , V_88 ) ;
return V_106 ;
}
static int F_50 ( unsigned long V_34 )
{
struct V_7 * V_8 ;
struct V_108 * V_109 ;
F_51 (lp, n, &ldc_channel_list, list) {
if ( V_8 -> V_34 == V_34 )
return 1 ;
}
return 0 ;
}
static int F_52 ( const char * V_110 , unsigned long V_11 ,
struct V_15 * * V_111 , unsigned long * V_112 )
{
unsigned long V_26 , V_113 ;
void * V_114 ;
V_26 = V_11 * V_12 ;
V_113 = F_53 ( V_26 ) ;
V_114 = ( void * ) F_54 ( V_115 , V_113 ) ;
if ( ! V_114 ) {
F_28 (KERN_ERR PFX L_28
L_29 , name, size, order) ;
return - V_116 ;
}
memset ( V_114 , 0 , V_117 << V_113 ) ;
* V_111 = V_114 ;
* V_112 = F_55 ( V_114 ) ;
return 0 ;
}
static void F_56 ( unsigned long V_11 , struct V_15 * V_114 )
{
unsigned long V_26 , V_113 ;
if ( ! V_114 )
return;
V_26 = V_11 * V_12 ;
V_113 = F_53 ( V_26 ) ;
F_57 ( ( unsigned long ) V_114 , V_113 ) ;
}
static int F_58 ( struct V_7 * V_8 )
{
unsigned long V_118 , V_119 , V_120 , V_113 ;
struct V_121 * V_122 = & V_8 -> V_122 ;
struct V_123 * V_124 ;
unsigned long V_70 ;
int V_33 ;
V_119 = V_125 ;
V_120 = V_119 * sizeof( struct V_123 ) ;
F_59 ( & V_122 -> V_96 ) ;
V_118 = V_119 / 8 ;
V_118 = ( V_118 + 7UL ) & ~ 7UL ;
V_122 -> V_126 . V_127 = F_60 ( V_118 , V_115 ) ;
if ( ! V_122 -> V_126 . V_127 ) {
F_28 (KERN_ERR PFX L_30 , sz) ;
return - V_116 ;
}
V_122 -> V_126 . V_27 = V_119 ;
V_113 = F_53 ( V_120 ) ;
V_124 = (struct V_123 * )
F_54 ( V_115 , V_113 ) ;
V_33 = - V_116 ;
if ( ! V_124 ) {
F_28 (KERN_ERR PFX L_31
L_29 , tsbsize, order) ;
goto V_128;
}
memset ( V_124 , 0 , V_117 << V_113 ) ;
V_122 -> V_129 = V_124 ;
V_70 = F_61 ( V_8 -> V_34 , F_55 ( V_124 ) ,
V_119 ) ;
V_33 = - V_36 ;
if ( V_70 )
goto V_130;
return 0 ;
V_130:
F_57 ( ( unsigned long ) V_124 , V_113 ) ;
V_122 -> V_129 = NULL ;
V_128:
F_62 ( V_122 -> V_126 . V_127 ) ;
V_122 -> V_126 . V_127 = NULL ;
return V_33 ;
}
static void F_63 ( struct V_7 * V_8 )
{
struct V_121 * V_122 = & V_8 -> V_122 ;
unsigned long V_119 , V_120 , V_113 ;
( void ) F_61 ( V_8 -> V_34 , 0 , 0 ) ;
V_119 = V_122 -> V_126 . V_27 ;
V_120 = V_119 * sizeof( struct V_123 ) ;
V_113 = F_53 ( V_120 ) ;
F_57 ( ( unsigned long ) V_122 -> V_129 , V_113 ) ;
V_122 -> V_129 = NULL ;
F_62 ( V_122 -> V_126 . V_127 ) ;
V_122 -> V_126 . V_127 = NULL ;
}
struct V_7 * F_64 ( unsigned long V_34 ,
const struct V_131 * V_132 ,
void * V_91 )
{
struct V_7 * V_8 ;
const struct V_133 * V_134 ;
unsigned long V_135 , V_136 , V_70 ;
T_1 V_30 , * V_137 ;
int V_33 ;
V_33 = - V_138 ;
if ( ! V_139 )
goto V_140;
V_33 = - V_36 ;
if ( ! V_132 )
goto V_140;
switch ( V_132 -> V_23 ) {
case V_98 :
V_134 = & V_141 ;
V_30 = V_12 ;
break;
case V_142 :
V_134 = & V_143 ;
V_30 = V_12 - 8 ;
break;
case V_24 :
V_134 = & V_144 ;
V_30 = V_12 - 8 - 8 ;
break;
default:
goto V_140;
}
if ( ! V_132 -> V_90 || ! V_91 || ! V_132 -> V_145 || ! V_132 -> V_146 )
goto V_140;
V_70 = F_65 ( V_34 , & V_135 , & V_136 ) ;
V_33 = - V_138 ;
if ( V_70 == V_147 )
goto V_140;
V_33 = - V_148 ;
if ( F_50 ( V_34 ) )
goto V_140;
V_137 = NULL ;
V_8 = F_60 ( sizeof( * V_8 ) , V_115 ) ;
V_33 = - V_116 ;
if ( ! V_8 )
goto V_140;
F_59 ( & V_8 -> V_96 ) ;
V_8 -> V_34 = V_34 ;
V_33 = F_58 ( V_8 ) ;
if ( V_33 )
goto V_149;
V_8 -> V_134 = V_134 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_22 = * V_132 ;
if ( ! V_8 -> V_22 . V_150 )
V_8 -> V_22 . V_150 = V_151 ;
if ( V_8 -> V_22 . V_23 == V_24 ) {
V_137 = F_60 ( V_8 -> V_22 . V_150 , V_115 ) ;
if ( ! V_137 ) {
V_33 = - V_116 ;
goto V_152;
}
V_8 -> V_137 = V_137 ;
}
V_8 -> V_91 = V_91 ;
V_8 -> V_14 = V_153 ;
V_8 -> V_13 = V_153 ;
V_33 = F_52 ( L_32 , V_8 -> V_14 ,
& V_8 -> V_21 , & V_8 -> V_71 ) ;
if ( V_33 )
goto V_154;
V_33 = F_52 ( L_33 , V_8 -> V_13 ,
& V_8 -> V_103 , & V_8 -> V_73 ) ;
if ( V_33 )
goto V_155;
V_8 -> V_54 |= V_156 ;
V_8 -> V_81 = V_157 ;
F_2 ( V_8 , V_3 ) ;
F_66 ( & V_8 -> V_158 ) ;
F_67 ( & V_8 -> V_158 , & V_159 ) ;
F_68 ( & V_8 -> V_160 ) ;
return V_8 ;
V_155:
F_56 ( V_8 -> V_14 , V_8 -> V_21 ) ;
V_154:
F_62 ( V_137 ) ;
V_152:
F_63 ( V_8 ) ;
V_149:
F_62 ( V_8 ) ;
V_140:
return F_69 ( V_33 ) ;
}
void F_70 ( struct V_7 * V_8 )
{
if ( V_8 -> V_54 & V_161 ) {
F_71 ( V_8 -> V_22 . V_145 , V_8 ) ;
F_71 ( V_8 -> V_22 . V_146 , V_8 ) ;
}
if ( V_8 -> V_54 & V_162 ) {
F_27 ( V_8 -> V_34 , 0 , 0 ) ;
F_30 ( V_8 -> V_34 , 0 , 0 ) ;
V_8 -> V_54 &= ~ V_162 ;
}
if ( V_8 -> V_54 & V_156 ) {
F_56 ( V_8 -> V_14 , V_8 -> V_21 ) ;
F_56 ( V_8 -> V_13 , V_8 -> V_103 ) ;
V_8 -> V_54 &= ~ V_156 ;
}
F_72 ( & V_8 -> V_158 ) ;
F_62 ( V_8 -> V_137 ) ;
F_63 ( V_8 ) ;
F_62 ( V_8 ) ;
}
int F_73 ( struct V_7 * V_8 , const char * V_110 )
{
unsigned long V_70 , V_54 ;
int V_33 = - V_36 ;
if ( ! V_110 ||
( V_8 -> V_1 != V_3 ) )
return - V_36 ;
snprintf ( V_8 -> V_163 , V_164 , L_34 , V_110 ) ;
snprintf ( V_8 -> V_165 , V_164 , L_35 , V_110 ) ;
V_33 = F_74 ( V_8 -> V_22 . V_145 , F_46 , V_166 ,
V_8 -> V_163 , V_8 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_74 ( V_8 -> V_22 . V_146 , F_49 , V_166 ,
V_8 -> V_165 , V_8 ) ;
if ( V_33 ) {
F_71 ( V_8 -> V_22 . V_145 , V_8 ) ;
return V_33 ;
}
F_47 ( & V_8 -> V_96 , V_54 ) ;
F_75 ( V_8 -> V_22 . V_145 ) ;
F_75 ( V_8 -> V_22 . V_146 ) ;
V_8 -> V_54 |= V_161 ;
V_33 = - V_138 ;
V_70 = F_27 ( V_8 -> V_34 , 0 , 0 ) ;
if ( V_70 )
goto V_167;
V_70 = F_27 ( V_8 -> V_34 , V_8 -> V_71 , V_8 -> V_14 ) ;
if ( V_70 )
goto V_167;
V_70 = F_30 ( V_8 -> V_34 , 0 , 0 ) ;
if ( V_70 )
goto V_168;
V_70 = F_30 ( V_8 -> V_34 , V_8 -> V_73 , V_8 -> V_13 ) ;
if ( V_70 )
goto V_168;
V_8 -> V_54 |= V_162 ;
V_70 = F_29 ( V_8 -> V_34 ,
& V_8 -> V_20 ,
& V_8 -> V_19 ,
& V_8 -> V_72 ) ;
V_33 = - V_37 ;
if ( V_70 )
goto V_169;
V_8 -> V_25 = V_8 -> V_20 ;
V_8 -> V_81 = V_83 ;
F_2 ( V_8 , V_4 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return 0 ;
V_169:
V_8 -> V_54 &= ~ V_162 ;
F_30 ( V_8 -> V_34 , 0 , 0 ) ;
V_168:
F_27 ( V_8 -> V_34 , 0 , 0 ) ;
V_167:
V_8 -> V_54 &= ~ V_161 ;
F_71 ( V_8 -> V_22 . V_146 , V_8 ) ;
F_71 ( V_8 -> V_22 . V_145 , V_8 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
int F_76 ( struct V_7 * V_8 )
{
unsigned long V_54 ;
int V_33 ;
if ( V_8 -> V_22 . V_23 == V_98 )
return - V_36 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
if ( ! ( V_8 -> V_54 & V_156 ) ||
! ( V_8 -> V_54 & V_162 ) ||
V_8 -> V_81 != V_83 )
V_33 = - V_36 ;
else
V_33 = F_19 ( V_8 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
int F_77 ( struct V_7 * V_8 )
{
unsigned long V_70 , V_54 ;
int V_33 ;
if ( V_8 -> V_22 . V_23 == V_98 )
return - V_36 ;
if ( ! ( V_8 -> V_54 & V_156 ) ||
! ( V_8 -> V_54 & V_162 ) )
return - V_36 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
V_33 = - V_138 ;
V_70 = F_27 ( V_8 -> V_34 , 0 , 0 ) ;
if ( V_70 )
goto V_140;
V_70 = F_27 ( V_8 -> V_34 , V_8 -> V_71 , V_8 -> V_14 ) ;
if ( V_70 )
goto V_140;
V_70 = F_30 ( V_8 -> V_34 , 0 , 0 ) ;
if ( V_70 )
goto V_140;
V_70 = F_30 ( V_8 -> V_34 , V_8 -> V_73 , V_8 -> V_13 ) ;
if ( V_70 )
goto V_140;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_81 = V_83 ;
V_8 -> V_54 |= V_55 ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return 0 ;
V_140:
F_27 ( V_8 -> V_34 , 0 , 0 ) ;
F_30 ( V_8 -> V_34 , 0 , 0 ) ;
F_71 ( V_8 -> V_22 . V_146 , V_8 ) ;
F_71 ( V_8 -> V_22 . V_145 , V_8 ) ;
V_8 -> V_54 &= ~ ( V_161 |
V_162 ) ;
F_2 ( V_8 , V_3 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
int F_78 ( struct V_7 * V_8 )
{
return V_8 -> V_1 ;
}
static int F_79 ( struct V_7 * V_8 , const void * V_170 , unsigned int V_26 )
{
struct V_15 * V_17 ;
unsigned long V_16 ;
int V_33 ;
if ( V_26 > V_12 )
return - V_171 ;
V_17 = F_10 ( V_8 , & V_16 ) ;
if ( ! V_17 )
return - V_172 ;
memcpy ( V_17 , V_170 , V_26 ) ;
V_33 = F_16 ( V_8 , V_17 , V_16 ) ;
if ( ! V_33 )
V_33 = V_26 ;
return V_33 ;
}
static int F_80 ( struct V_7 * V_8 , void * V_170 , unsigned int V_26 )
{
struct V_15 * V_17 ;
unsigned long V_70 , V_102 ;
int V_33 ;
if ( V_26 < V_12 )
return - V_36 ;
V_70 = F_31 ( V_8 -> V_34 ,
& V_8 -> V_74 ,
& V_8 -> V_75 ,
& V_8 -> V_72 ) ;
if ( V_70 )
return F_26 ( V_8 ) ;
if ( V_8 -> V_72 == V_173 ||
V_8 -> V_72 == V_174 )
return - V_76 ;
if ( V_8 -> V_74 == V_8 -> V_75 )
return 0 ;
V_17 = V_8 -> V_103 + ( V_8 -> V_74 / V_12 ) ;
memcpy ( V_170 , V_17 , V_12 ) ;
V_102 = F_5 ( V_8 , V_8 -> V_74 ) ;
V_8 -> V_74 = V_102 ;
V_33 = F_14 ( V_8 , V_102 ) ;
if ( V_33 < 0 )
V_33 = - V_76 ;
else
V_33 = V_12 ;
return V_33 ;
}
static int F_81 ( struct V_7 * V_8 , const void * V_170 ,
unsigned int V_26 )
{
unsigned long V_70 , V_28 ;
unsigned int V_175 ;
T_3 V_176 ;
int V_33 ;
V_70 = F_29 ( V_8 -> V_34 , & V_8 -> V_20 , & V_8 -> V_19 ,
& V_8 -> V_72 ) ;
if ( F_82 ( V_70 ) )
return - V_37 ;
if ( F_82 ( V_8 -> V_72 != V_99 ) )
return F_26 ( V_8 ) ;
if ( ! F_9 ( V_8 , V_26 ) )
return - V_172 ;
V_176 = V_8 -> V_65 ;
V_175 = 0 ;
V_28 = V_8 -> V_19 ;
while ( V_175 < V_26 ) {
struct V_15 * V_17 = V_8 -> V_21 + ( V_28 / V_12 ) ;
T_1 * V_41 = ( ( V_8 -> V_22 . V_23 == V_142 ) ?
V_17 -> V_44 . V_45 :
V_17 -> V_44 . V_66 . V_177 ) ;
int V_178 ;
V_17 -> type = V_104 ;
V_17 -> V_39 = V_52 ;
V_17 -> V_40 = 0 ;
V_178 = V_26 - V_175 ;
if ( V_178 > V_8 -> V_30 )
V_178 = V_8 -> V_30 ;
F_17 ( V_178 > V_179 ) ;
V_17 -> V_60 = ( V_178 |
( V_175 == 0 ? V_180 : 0 ) |
( V_178 == V_26 - V_175 ? V_181 : 0 ) ) ;
V_17 -> V_61 = ++ V_176 ;
F_3 ( V_182 , L_36 ,
V_17 -> type ,
V_17 -> V_39 ,
V_17 -> V_40 ,
V_17 -> V_60 ,
V_17 -> V_61 ) ;
memcpy ( V_41 , V_170 , V_178 ) ;
V_170 += V_178 ;
V_175 += V_178 ;
V_28 = F_6 ( V_8 , V_28 ) ;
}
V_33 = F_11 ( V_8 , V_28 ) ;
if ( ! V_33 ) {
V_8 -> V_65 = V_176 ;
V_33 = V_26 ;
}
return V_33 ;
}
static int F_83 ( struct V_7 * V_8 , struct V_15 * V_17 ,
struct V_15 * V_183 )
{
int V_33 ;
if ( V_183 )
V_8 -> V_62 = V_183 -> V_61 - 1 ;
V_33 = F_25 ( V_8 , V_17 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_14 ( V_8 , V_8 -> V_75 ) ;
if ( V_33 < 0 )
return F_26 ( V_8 ) ;
return 0 ;
}
static int F_84 ( struct V_7 * V_8 , struct V_15 * V_17 )
{
if ( V_17 -> V_39 & V_58 ) {
int V_33 = F_44 ( V_8 , V_17 ) ;
if ( V_33 )
return V_33 ;
}
if ( V_17 -> V_39 & V_56 )
return F_26 ( V_8 ) ;
return 0 ;
}
static int F_85 ( struct V_7 * V_8 , unsigned long V_184 )
{
unsigned long V_185 ;
int V_27 = 1000 ;
F_3 ( V_182 , L_37 ,
V_184 , V_8 -> V_74 , V_8 -> V_75 ) ;
while ( V_27 -- > 0 ) {
unsigned long V_70 ;
V_70 = F_31 ( V_8 -> V_34 ,
& V_185 ,
& V_8 -> V_75 ,
& V_8 -> V_72 ) ;
if ( V_70 )
return F_26 ( V_8 ) ;
if ( V_8 -> V_72 == V_173 ||
V_8 -> V_72 == V_174 )
return - V_76 ;
if ( V_184 != V_8 -> V_75 ) {
F_3 ( V_182 , L_38
L_39 ,
V_185 , V_8 -> V_75 , V_8 -> V_72 ) ;
return 0 ;
}
F_13 ( 1 ) ;
}
return - V_172 ;
}
static int F_86 ( struct V_7 * V_8 , unsigned long V_38 )
{
int V_33 = F_14 ( V_8 , V_38 ) ;
if ( V_33 < 0 )
return F_26 ( V_8 ) ;
V_8 -> V_74 = V_38 ;
return 0 ;
}
static void F_87 ( struct V_7 * V_8 )
{
unsigned long V_16 ;
struct V_15 * V_17 ;
V_17 = F_10 ( V_8 , & V_16 ) ;
if ( F_88 ( V_17 ) ) {
int V_33 ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> type = V_104 ;
V_17 -> V_39 = V_58 ;
V_17 -> V_40 = 0 ;
V_17 -> V_61 = V_8 -> V_65 + 1 ;
V_17 -> V_44 . V_66 . V_67 = V_8 -> V_62 ;
V_33 = F_16 ( V_8 , V_17 , V_16 ) ;
if ( ! V_33 )
V_8 -> V_65 ++ ;
}
}
static int F_89 ( struct V_7 * V_8 , void * V_170 , unsigned int V_26 )
{
struct V_15 * V_183 ;
unsigned long V_70 , V_102 ;
int V_33 , V_175 ;
V_70 = F_31 ( V_8 -> V_34 ,
& V_8 -> V_74 ,
& V_8 -> V_75 ,
& V_8 -> V_72 ) ;
if ( V_70 )
return F_26 ( V_8 ) ;
if ( V_8 -> V_72 == V_173 ||
V_8 -> V_72 == V_174 )
return - V_76 ;
if ( V_8 -> V_74 == V_8 -> V_75 )
return 0 ;
V_183 = NULL ;
V_175 = V_33 = 0 ;
V_102 = V_8 -> V_74 ;
while ( 1 ) {
struct V_15 * V_17 ;
int V_186 ;
F_17 ( V_102 == V_8 -> V_75 ) ;
V_17 = V_8 -> V_103 + ( V_102 / V_12 ) ;
F_3 ( V_97 , L_40
L_41 ,
V_17 -> type ,
V_17 -> V_39 ,
V_17 -> V_40 ,
V_17 -> V_60 ,
V_17 -> V_61 ,
V_17 -> V_44 . V_66 . V_67 ,
V_8 -> V_62 ) ;
if ( F_82 ( ! F_40 ( V_8 , V_17 -> V_61 ) ) ) {
V_33 = F_83 ( V_8 , V_17 , V_183 ) ;
V_175 = 0 ;
break;
}
if ( V_17 -> type & V_43 ) {
V_33 = F_42 ( V_8 , V_17 ) ;
if ( V_33 < 0 )
break;
V_33 = 0 ;
}
V_8 -> V_62 = V_17 -> V_61 ;
if ( ! ( V_17 -> type & V_104 ) ) {
V_102 = F_5 ( V_8 , V_102 ) ;
goto V_187;
}
if ( V_17 -> V_39 & ( V_58 | V_56 ) ) {
V_33 = F_84 ( V_8 , V_17 ) ;
if ( V_33 )
break;
}
if ( ! ( V_17 -> V_39 & V_52 ) ) {
V_102 = F_5 ( V_8 , V_102 ) ;
V_33 = F_86 ( V_8 , V_102 ) ;
if ( V_33 )
break;
goto V_187;
}
V_186 = V_17 -> V_60 & V_179 ;
if ( ( V_183 == NULL && ! ( V_17 -> V_60 & V_180 ) ) ||
( V_183 != NULL && ( V_17 -> V_60 & V_180 ) ) ) {
if ( ! V_183 )
V_102 = F_5 ( V_8 , V_102 ) ;
V_33 = F_86 ( V_8 , V_102 ) ;
if ( V_33 )
break;
if ( ! V_183 )
goto V_187;
}
if ( ! V_183 )
V_183 = V_17 ;
if ( V_186 > V_26 - V_175 ) {
V_33 = - V_171 ;
break;
}
V_102 = F_5 ( V_8 , V_102 ) ;
memcpy ( V_170 ,
( V_8 -> V_22 . V_23 == V_142 ?
V_17 -> V_44 . V_45 : V_17 -> V_44 . V_66 . V_177 ) , V_186 ) ;
V_170 += V_186 ;
V_175 += V_186 ;
if ( V_17 -> V_60 & V_181 )
break;
V_187:
if ( V_102 == V_8 -> V_75 ) {
V_33 = F_85 ( V_8 , V_102 ) ;
if ( V_33 )
break;
}
}
if ( ! V_33 )
V_33 = F_86 ( V_8 , V_102 ) ;
if ( V_33 && V_183 )
V_8 -> V_62 = V_183 -> V_61 - 1 ;
if ( ! V_33 ) {
V_33 = V_175 ;
if ( V_33 > 0 && V_8 -> V_22 . V_23 != V_142 )
F_87 ( V_8 ) ;
}
return V_33 ;
}
static int F_90 ( struct V_7 * V_8 , const void * V_170 ,
unsigned int V_26 )
{
if ( V_26 > V_8 -> V_22 . V_150 )
V_26 = V_8 -> V_22 . V_150 ;
return F_81 ( V_8 , V_170 , V_26 ) ;
}
static int F_91 ( struct V_7 * V_8 , void * V_170 , unsigned int V_26 )
{
if ( ! V_8 -> V_188 ) {
int V_33 = F_89 ( V_8 , V_8 -> V_137 , V_8 -> V_22 . V_150 ) ;
if ( V_33 < 0 )
return V_33 ;
V_8 -> V_188 = V_33 ;
V_8 -> V_189 = 0 ;
}
if ( V_26 > V_8 -> V_188 )
V_26 = V_8 -> V_188 ;
memcpy ( V_170 , V_8 -> V_137 + V_8 -> V_189 , V_26 ) ;
V_8 -> V_189 += V_26 ;
V_8 -> V_188 -= V_26 ;
return V_26 ;
}
int F_92 ( struct V_7 * V_8 , const void * V_170 , unsigned int V_26 )
{
unsigned long V_54 ;
int V_33 ;
if ( ! V_170 )
return - V_36 ;
if ( ! V_26 )
return 0 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
if ( V_8 -> V_81 != V_85 )
V_33 = - V_190 ;
else
V_33 = V_8 -> V_134 -> V_191 ( V_8 , V_170 , V_26 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
int F_93 ( struct V_7 * V_8 , void * V_170 , unsigned int V_26 )
{
unsigned long V_54 ;
int V_33 ;
if ( ! V_170 )
return - V_36 ;
if ( ! V_26 )
return 0 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
if ( V_8 -> V_81 != V_85 )
V_33 = - V_190 ;
else
V_33 = V_8 -> V_134 -> V_192 ( V_8 , V_170 , V_26 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
static long F_94 ( struct V_121 * V_122 , unsigned long V_193 )
{
struct V_194 * V_126 = & V_122 -> V_126 ;
unsigned long V_109 , V_195 , V_196 , V_27 ;
int V_197 ;
V_27 = V_126 -> V_27 ;
V_195 = V_126 -> V_198 ;
V_197 = 0 ;
V_199:
V_109 = F_95 ( V_126 -> V_127 , V_27 , V_195 , V_193 , 0 ) ;
V_196 = V_109 + V_193 ;
if ( F_82 ( V_196 >= V_27 ) ) {
if ( F_88 ( V_197 < 1 ) ) {
V_27 = V_195 ;
V_195 = 0 ;
V_197 ++ ;
goto V_199;
} else {
return - 1 ;
}
}
F_96 ( V_126 -> V_127 , V_109 , V_193 ) ;
V_126 -> V_198 = V_196 ;
return V_109 ;
}
static T_5 F_97 ( void )
{
switch ( V_117 ) {
default:
case ( 8ULL * 1024ULL ) :
return 0 ;
case ( 64ULL * 1024ULL ) :
return 1 ;
case ( 512ULL * 1024ULL ) :
return 2 ;
case ( 4ULL * 1024ULL * 1024ULL ) :
return 3 ;
case ( 32ULL * 1024ULL * 1024ULL ) :
return 4 ;
case ( 256ULL * 1024ULL * 1024ULL ) :
return 5 ;
}
}
static T_5 F_98 ( T_5 V_200 , T_5 V_201 , T_5 V_202 )
{
return ( ( V_201 << V_203 ) |
( V_200 << V_204 ) |
V_202 ) ;
}
static T_5 F_99 ( T_5 V_205 , unsigned long * V_206 )
{
T_5 V_207 = V_205 >> V_203 ;
V_205 &= ~ V_208 ;
* V_206 = V_207 * 3 ;
return ( V_205 >> ( 13ULL + ( V_207 * 3ULL ) ) ) ;
}
static struct V_123 * F_100 ( struct V_121 * V_122 ,
unsigned long V_193 )
{
long V_209 ;
V_209 = F_94 ( V_122 , V_193 ) ;
if ( F_82 ( V_209 < 0 ) )
return NULL ;
return V_122 -> V_129 + V_209 ;
}
static T_5 F_101 ( unsigned int V_210 )
{
T_5 V_211 ;
V_211 = F_97 () ;
if ( V_210 & V_212 ) {
if ( V_210 & V_213 )
V_211 |= V_214 ;
if ( V_210 & V_215 )
V_211 |= V_216 ;
}
if ( V_210 & V_217 ) {
if ( V_210 & V_213 )
V_211 |= V_218 ;
if ( V_210 & V_215 )
V_211 |= V_219 ;
if ( V_210 & V_220 )
V_211 |= V_221 ;
}
if ( V_210 & V_222 ) {
if ( V_210 & V_213 )
V_211 |= V_223 ;
if ( V_210 & V_215 )
V_211 |= V_224 ;
}
return V_211 ;
}
static int F_102 ( unsigned long V_111 , long V_225 )
{
int V_226 = 0 ;
do {
unsigned long V_102 = ( V_111 + V_117 ) & V_227 ;
V_225 -= ( V_102 - V_111 ) ;
V_111 = V_102 ;
V_226 ++ ;
} while ( V_225 > 0 );
return V_226 ;
}
static void F_103 ( struct V_228 * V_229 , unsigned long V_230 ,
unsigned long V_10 , unsigned long V_225 )
{
do {
unsigned long V_231 , V_102 = V_230 + V_117 ;
T_5 V_232 ;
V_229 -> V_129 [ V_229 -> V_233 ] . V_234 = V_229 -> V_211 | V_230 ;
V_231 = V_117 ;
if ( V_10 )
V_231 = V_117 - V_10 ;
if ( V_231 > V_225 )
V_231 = V_225 ;
V_232 = F_98 ( V_229 -> V_233 ,
F_97 () , V_10 ) ;
V_10 = 0 ;
if ( V_232 == V_229 -> V_235 ) {
V_229 -> V_236 [ V_229 -> V_237 - 1 ] . V_238 += V_231 ;
} else {
V_229 -> V_236 [ V_229 -> V_237 ] . V_239 = V_232 ;
V_229 -> V_236 [ V_229 -> V_237 ] . V_238 = V_231 ;
V_229 -> V_237 ++ ;
}
V_229 -> V_235 = V_232 + V_231 ;
V_229 -> V_233 ++ ;
V_225 -= V_231 ;
V_230 = V_102 ;
} while ( V_225 > 0 );
}
static int F_104 ( struct V_240 * V_241 )
{
unsigned long V_111 = F_105 ( F_106 ( V_241 ) ) << V_204 ;
long V_225 = V_241 -> V_242 ;
if ( ( V_241 -> V_243 | V_225 ) & ( 8UL - 1 ) )
return - V_244 ;
return F_102 ( V_111 + V_241 -> V_243 , V_225 ) ;
}
static int F_107 ( struct V_240 * V_241 , int V_245 )
{
int V_226 ;
int V_78 ;
V_226 = 0 ;
for ( V_78 = 0 ; V_78 < V_245 ; V_78 ++ ) {
int V_33 = F_104 ( V_241 + V_78 ) ;
if ( V_33 < 0 )
return V_33 ;
V_226 += V_33 ;
}
return V_226 ;
}
int F_108 ( struct V_7 * V_8 ,
struct V_240 * V_241 , int V_245 ,
struct V_246 * V_236 , int V_247 ,
unsigned int V_210 )
{
unsigned long V_78 , V_193 , V_54 ;
struct V_123 * V_111 ;
struct V_228 V_1 ;
struct V_121 * V_122 ;
int V_33 ;
if ( V_210 & ~ V_248 )
return - V_36 ;
V_33 = F_107 ( V_241 , V_245 ) ;
if ( V_33 < 0 )
return V_33 ;
V_193 = V_33 ;
if ( V_33 > V_247 )
return - V_171 ;
V_122 = & V_8 -> V_122 ;
F_47 ( & V_122 -> V_96 , V_54 ) ;
V_111 = F_100 ( V_122 , V_193 ) ;
F_48 ( & V_122 -> V_96 , V_54 ) ;
if ( ! V_111 )
return - V_116 ;
V_1 . V_129 = V_122 -> V_129 ;
V_1 . V_236 = V_236 ;
V_1 . V_211 = F_101 ( V_210 ) ;
V_1 . V_235 = ~ ( T_5 ) 0 ;
V_1 . V_233 = ( V_111 - V_122 -> V_129 ) ;
V_1 . V_237 = 0 ;
for ( V_78 = 0 ; V_78 < V_245 ; V_78 ++ )
F_103 ( & V_1 , F_105 ( F_106 ( & V_241 [ V_78 ] ) ) << V_204 ,
V_241 [ V_78 ] . V_243 , V_241 [ V_78 ] . V_242 ) ;
return V_1 . V_237 ;
}
int F_109 ( struct V_7 * V_8 ,
void * V_170 , unsigned int V_225 ,
struct V_246 * V_236 , int V_247 ,
unsigned int V_210 )
{
unsigned long V_193 , V_230 , V_54 ;
struct V_123 * V_111 ;
struct V_228 V_1 ;
struct V_121 * V_122 ;
if ( ( V_210 & ~ V_248 ) || ( V_247 < 1 ) )
return - V_36 ;
V_230 = F_55 ( V_170 ) ;
if ( ( V_230 | V_225 ) & ( 8UL - 1 ) )
return - V_244 ;
V_193 = F_102 ( V_230 , V_225 ) ;
V_122 = & V_8 -> V_122 ;
F_47 ( & V_122 -> V_96 , V_54 ) ;
V_111 = F_100 ( V_122 , V_193 ) ;
F_48 ( & V_122 -> V_96 , V_54 ) ;
if ( ! V_111 )
return - V_116 ;
V_1 . V_129 = V_122 -> V_129 ;
V_1 . V_236 = V_236 ;
V_1 . V_211 = F_101 ( V_210 ) ;
V_1 . V_235 = ~ ( T_5 ) 0 ;
V_1 . V_233 = ( V_111 - V_122 -> V_129 ) ;
V_1 . V_237 = 0 ;
F_103 ( & V_1 , ( V_230 & V_227 ) , ( V_230 & ~ V_227 ) , V_225 ) ;
F_17 ( V_1 . V_237 != 1 ) ;
return V_1 . V_237 ;
}
static void F_110 ( unsigned long V_34 , struct V_121 * V_122 ,
T_5 V_205 , T_5 V_26 )
{
struct V_194 * V_126 = & V_122 -> V_126 ;
unsigned long V_78 , V_206 , V_200 , V_193 ;
struct V_123 * V_111 ;
V_193 = F_111 ( ( ( V_205 & ~ V_227 ) + V_26 ) ) >> V_204 ;
V_200 = F_99 ( V_205 , & V_206 ) ;
V_111 = V_122 -> V_129 + V_200 ;
F_17 ( V_200 > V_126 -> V_27 ||
( V_200 + V_193 ) > V_126 -> V_27 ) ;
for ( V_78 = 0 ; V_78 < V_193 ; V_78 ++ ) {
if ( V_111 -> V_205 )
F_112 ( V_34 , V_205 + ( V_78 << V_206 ) ,
V_111 -> V_205 ) ;
V_111 -> V_234 = 0 ;
F_113 ( V_200 + V_78 , V_126 -> V_127 ) ;
}
}
void F_114 ( struct V_7 * V_8 , struct V_246 * V_236 ,
int V_247 )
{
struct V_121 * V_122 = & V_8 -> V_122 ;
unsigned long V_54 ;
int V_78 ;
F_47 ( & V_122 -> V_96 , V_54 ) ;
for ( V_78 = 0 ; V_78 < V_247 ; V_78 ++ ) {
T_5 V_249 = V_236 [ V_78 ] . V_239 ;
T_5 V_26 = V_236 [ V_78 ] . V_238 ;
F_110 ( V_8 -> V_34 , V_122 , V_249 , V_26 ) ;
}
F_48 ( & V_122 -> V_96 , V_54 ) ;
}
int F_115 ( struct V_7 * V_8 , int V_250 ,
void * V_170 , unsigned int V_225 , unsigned long V_243 ,
struct V_246 * V_236 , int V_247 )
{
unsigned int V_251 ;
unsigned long V_112 ;
int V_78 ;
if ( V_250 != V_252 && V_250 != V_253 ) {
F_28 (KERN_ERR PFX L_42 ,
lp->id, copy_dir) ;
return - V_36 ;
}
V_112 = F_55 ( V_170 ) ;
if ( ( V_112 | V_225 | V_243 ) & ( 8UL - 1 ) ) {
F_28 (KERN_ERR PFX L_43
L_44 ,
lp->id, ra, len, offset) ;
return - V_244 ;
}
if ( V_8 -> V_81 != V_85 ||
( V_8 -> V_54 & V_55 ) ) {
F_28 (KERN_ERR PFX L_45
L_46 , lp->id, lp->hs_state, lp->flags) ;
return - V_76 ;
}
V_251 = V_225 ;
for ( V_78 = 0 ; V_78 < V_247 ; V_78 ++ ) {
unsigned long V_254 = V_236 [ V_78 ] . V_239 ;
unsigned long V_255 = V_236 [ V_78 ] . V_238 ;
unsigned long V_256 ;
if ( F_82 ( V_243 ) ) {
unsigned long V_257 = V_243 ;
if ( V_257 > V_255 )
V_257 = V_255 ;
V_243 -= V_257 ;
V_255 -= V_257 ;
if ( ! V_255 )
continue;
V_254 += V_257 ;
}
if ( V_255 > V_225 )
V_255 = V_225 ;
while ( 1 ) {
unsigned long V_70 ;
V_70 = F_116 ( V_8 -> V_34 , V_250 ,
V_254 , V_112 ,
V_255 , & V_256 ) ;
if ( F_82 ( V_70 ) ) {
F_28 (KERN_ERR PFX L_47
L_48 ,
lp->id, hv_err) ;
if ( V_8 -> V_81 != V_85 ||
( V_8 -> V_54 & V_55 ) )
return - V_76 ;
else
return - V_244 ;
}
V_254 += V_256 ;
V_112 += V_256 ;
V_225 -= V_256 ;
if ( V_256 == V_255 )
break;
V_255 -= V_256 ;
}
if ( ! V_225 )
break;
}
return V_251 - V_225 ;
}
void * F_117 ( struct V_7 * V_8 , unsigned int V_225 ,
struct V_246 * V_236 , int * V_247 ,
unsigned int V_210 )
{
void * V_170 ;
int V_33 ;
if ( V_225 & ( 8UL - 1 ) )
return F_69 ( - V_36 ) ;
V_170 = F_60 ( V_225 , V_115 ) ;
if ( ! V_170 )
return F_69 ( - V_116 ) ;
V_33 = F_109 ( V_8 , V_170 , V_225 , V_236 , * V_247 , V_210 ) ;
if ( V_33 < 0 ) {
F_62 ( V_170 ) ;
return F_69 ( V_33 ) ;
}
* V_247 = V_33 ;
return V_170 ;
}
void F_118 ( struct V_7 * V_8 , void * V_170 , unsigned int V_225 ,
struct V_246 * V_236 , int V_247 )
{
F_114 ( V_8 , V_236 , V_247 ) ;
F_62 ( V_170 ) ;
}
static int T_6 F_119 ( void )
{
unsigned long V_50 , V_51 ;
struct V_258 * V_259 ;
const T_5 * V_79 ;
int V_33 ;
T_5 V_260 ;
V_259 = F_120 () ;
if ( ! V_259 )
return - V_138 ;
V_260 = F_121 ( V_259 , V_261 , L_49 ) ;
V_33 = - V_138 ;
if ( V_260 == V_261 )
goto V_100;
V_79 = F_122 ( V_259 , V_260 , L_50 , NULL ) ;
if ( ! V_79 )
goto V_100;
V_50 = 1 ;
V_51 = 0 ;
if ( F_123 ( V_262 , V_50 , & V_51 ) ) {
F_28 (KERN_INFO PFX L_51 ) ;
goto V_100;
}
F_28 ( V_263 L_52 , V_264 ) ;
if ( ! * V_79 ) {
F_28 (KERN_INFO PFX L_53 ) ;
goto V_100;
}
V_139 = 1 ;
V_33 = 0 ;
V_100:
F_124 ( V_259 ) ;
return V_33 ;
}
