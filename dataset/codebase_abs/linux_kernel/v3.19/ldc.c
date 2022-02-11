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
F_51 (lp, &ldc_channel_list, list) {
if ( V_8 -> V_34 == V_34 )
return 1 ;
}
return 0 ;
}
static int F_52 ( const char * V_108 , unsigned long V_11 ,
struct V_15 * * V_109 , unsigned long * V_110 )
{
unsigned long V_26 , V_111 ;
void * V_112 ;
V_26 = V_11 * V_12 ;
V_111 = F_53 ( V_26 ) ;
V_112 = ( void * ) F_54 ( V_113 , V_111 ) ;
if ( ! V_112 ) {
F_28 (KERN_ERR PFX L_28
L_29 , name, size, order) ;
return - V_114 ;
}
memset ( V_112 , 0 , V_115 << V_111 ) ;
* V_109 = V_112 ;
* V_110 = F_55 ( V_112 ) ;
return 0 ;
}
static void F_56 ( unsigned long V_11 , struct V_15 * V_112 )
{
unsigned long V_26 , V_111 ;
if ( ! V_112 )
return;
V_26 = V_11 * V_12 ;
V_111 = F_53 ( V_26 ) ;
F_57 ( ( unsigned long ) V_112 , V_111 ) ;
}
static int F_58 ( struct V_7 * V_8 )
{
unsigned long V_116 , V_117 , V_118 , V_111 ;
struct V_119 * V_120 = & V_8 -> V_120 ;
struct V_121 * V_122 ;
unsigned long V_70 ;
int V_33 ;
V_117 = V_123 ;
V_118 = V_117 * sizeof( struct V_121 ) ;
F_59 ( & V_120 -> V_96 ) ;
V_116 = V_117 / 8 ;
V_116 = ( V_116 + 7UL ) & ~ 7UL ;
V_120 -> V_124 . V_125 = F_60 ( V_116 , V_113 ) ;
if ( ! V_120 -> V_124 . V_125 ) {
F_28 (KERN_ERR PFX L_30 , sz) ;
return - V_114 ;
}
V_120 -> V_124 . V_27 = V_117 ;
V_111 = F_53 ( V_118 ) ;
V_122 = (struct V_121 * )
F_54 ( V_113 , V_111 ) ;
V_33 = - V_114 ;
if ( ! V_122 ) {
F_28 (KERN_ERR PFX L_31
L_29 , tsbsize, order) ;
goto V_126;
}
memset ( V_122 , 0 , V_115 << V_111 ) ;
V_120 -> V_127 = V_122 ;
V_70 = F_61 ( V_8 -> V_34 , F_55 ( V_122 ) ,
V_117 ) ;
V_33 = - V_36 ;
if ( V_70 )
goto V_128;
return 0 ;
V_128:
F_57 ( ( unsigned long ) V_122 , V_111 ) ;
V_120 -> V_127 = NULL ;
V_126:
F_62 ( V_120 -> V_124 . V_125 ) ;
V_120 -> V_124 . V_125 = NULL ;
return V_33 ;
}
static void F_63 ( struct V_7 * V_8 )
{
struct V_119 * V_120 = & V_8 -> V_120 ;
unsigned long V_117 , V_118 , V_111 ;
( void ) F_61 ( V_8 -> V_34 , 0 , 0 ) ;
V_117 = V_120 -> V_124 . V_27 ;
V_118 = V_117 * sizeof( struct V_121 ) ;
V_111 = F_53 ( V_118 ) ;
F_57 ( ( unsigned long ) V_120 -> V_127 , V_111 ) ;
V_120 -> V_127 = NULL ;
F_62 ( V_120 -> V_124 . V_125 ) ;
V_120 -> V_124 . V_125 = NULL ;
}
struct V_7 * F_64 ( unsigned long V_34 ,
const struct V_129 * V_130 ,
void * V_91 ,
const char * V_108 )
{
struct V_7 * V_8 ;
const struct V_131 * V_132 ;
unsigned long V_133 , V_134 , V_70 ;
T_1 V_30 , * V_135 ;
int V_33 ;
V_33 = - V_136 ;
if ( ! V_137 )
goto V_138;
V_33 = - V_36 ;
if ( ! V_130 )
goto V_138;
if ( ! V_108 )
goto V_138;
switch ( V_130 -> V_23 ) {
case V_98 :
V_132 = & V_139 ;
V_30 = V_12 ;
break;
case V_140 :
V_132 = & V_141 ;
V_30 = V_12 - 8 ;
break;
case V_24 :
V_132 = & V_142 ;
V_30 = V_12 - 8 - 8 ;
break;
default:
goto V_138;
}
if ( ! V_130 -> V_90 || ! V_91 || ! V_130 -> V_143 || ! V_130 -> V_144 )
goto V_138;
V_70 = F_65 ( V_34 , & V_133 , & V_134 ) ;
V_33 = - V_136 ;
if ( V_70 == V_145 )
goto V_138;
V_33 = - V_146 ;
if ( F_50 ( V_34 ) )
goto V_138;
V_135 = NULL ;
V_8 = F_60 ( sizeof( * V_8 ) , V_113 ) ;
V_33 = - V_114 ;
if ( ! V_8 )
goto V_138;
F_59 ( & V_8 -> V_96 ) ;
V_8 -> V_34 = V_34 ;
V_33 = F_58 ( V_8 ) ;
if ( V_33 )
goto V_147;
V_8 -> V_132 = V_132 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_22 = * V_130 ;
if ( ! V_8 -> V_22 . V_148 )
V_8 -> V_22 . V_148 = V_149 ;
if ( V_8 -> V_22 . V_23 == V_24 ) {
V_135 = F_60 ( V_8 -> V_22 . V_148 , V_113 ) ;
if ( ! V_135 ) {
V_33 = - V_114 ;
goto V_150;
}
V_8 -> V_135 = V_135 ;
}
V_8 -> V_91 = V_91 ;
V_8 -> V_14 = V_151 ;
V_8 -> V_13 = V_151 ;
V_33 = F_52 ( L_32 , V_8 -> V_14 ,
& V_8 -> V_21 , & V_8 -> V_71 ) ;
if ( V_33 )
goto V_152;
V_33 = F_52 ( L_33 , V_8 -> V_13 ,
& V_8 -> V_103 , & V_8 -> V_73 ) ;
if ( V_33 )
goto V_153;
V_8 -> V_54 |= V_154 ;
V_8 -> V_81 = V_155 ;
F_2 ( V_8 , V_3 ) ;
F_66 ( & V_8 -> V_156 ) ;
F_67 ( & V_8 -> V_156 , & V_157 ) ;
F_68 ( & V_8 -> V_158 ) ;
snprintf ( V_8 -> V_159 , V_160 , L_34 , V_108 ) ;
snprintf ( V_8 -> V_161 , V_160 , L_35 , V_108 ) ;
V_33 = F_69 ( V_8 -> V_22 . V_143 , F_46 , 0 ,
V_8 -> V_159 , V_8 ) ;
if ( V_33 )
goto V_153;
V_33 = F_69 ( V_8 -> V_22 . V_144 , F_49 , 0 ,
V_8 -> V_161 , V_8 ) ;
if ( V_33 ) {
F_70 ( V_8 -> V_22 . V_143 , V_8 ) ;
goto V_153;
}
return V_8 ;
V_153:
F_56 ( V_8 -> V_14 , V_8 -> V_21 ) ;
V_152:
F_62 ( V_135 ) ;
V_150:
F_63 ( V_8 ) ;
V_147:
F_62 ( V_8 ) ;
V_138:
return F_71 ( V_33 ) ;
}
void F_72 ( struct V_7 * V_8 )
{
if ( V_8 -> V_54 & V_162 ) {
F_70 ( V_8 -> V_22 . V_143 , V_8 ) ;
F_70 ( V_8 -> V_22 . V_144 , V_8 ) ;
V_8 -> V_54 &= ~ V_162 ;
}
if ( V_8 -> V_54 & V_163 ) {
F_27 ( V_8 -> V_34 , 0 , 0 ) ;
F_30 ( V_8 -> V_34 , 0 , 0 ) ;
V_8 -> V_54 &= ~ V_163 ;
}
if ( V_8 -> V_54 & V_154 ) {
F_56 ( V_8 -> V_14 , V_8 -> V_21 ) ;
F_56 ( V_8 -> V_13 , V_8 -> V_103 ) ;
V_8 -> V_54 &= ~ V_154 ;
}
F_2 ( V_8 , V_3 ) ;
}
void F_73 ( struct V_7 * V_8 )
{
F_72 ( V_8 ) ;
F_74 ( & V_8 -> V_156 ) ;
F_62 ( V_8 -> V_135 ) ;
F_63 ( V_8 ) ;
F_62 ( V_8 ) ;
}
int F_75 ( struct V_7 * V_8 )
{
unsigned long V_70 , V_54 ;
int V_33 = - V_36 ;
if ( V_8 -> V_1 != V_3 )
return - V_36 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
F_76 ( V_8 -> V_22 . V_143 ) ;
F_76 ( V_8 -> V_22 . V_144 ) ;
V_8 -> V_54 |= V_162 ;
V_33 = - V_136 ;
V_70 = F_27 ( V_8 -> V_34 , 0 , 0 ) ;
if ( V_70 )
goto V_164;
V_70 = F_27 ( V_8 -> V_34 , V_8 -> V_71 , V_8 -> V_14 ) ;
if ( V_70 )
goto V_164;
V_70 = F_30 ( V_8 -> V_34 , 0 , 0 ) ;
if ( V_70 )
goto V_165;
V_70 = F_30 ( V_8 -> V_34 , V_8 -> V_73 , V_8 -> V_13 ) ;
if ( V_70 )
goto V_165;
V_8 -> V_54 |= V_163 ;
V_70 = F_29 ( V_8 -> V_34 ,
& V_8 -> V_20 ,
& V_8 -> V_19 ,
& V_8 -> V_72 ) ;
V_33 = - V_37 ;
if ( V_70 )
goto V_166;
V_8 -> V_25 = V_8 -> V_20 ;
V_8 -> V_81 = V_83 ;
F_2 ( V_8 , V_4 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return 0 ;
V_166:
V_8 -> V_54 &= ~ V_163 ;
F_30 ( V_8 -> V_34 , 0 , 0 ) ;
V_165:
F_27 ( V_8 -> V_34 , 0 , 0 ) ;
V_164:
V_8 -> V_54 &= ~ V_162 ;
F_70 ( V_8 -> V_22 . V_144 , V_8 ) ;
F_70 ( V_8 -> V_22 . V_143 , V_8 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
int F_77 ( struct V_7 * V_8 )
{
unsigned long V_54 ;
int V_33 ;
if ( V_8 -> V_22 . V_23 == V_98 )
return - V_36 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
if ( ! ( V_8 -> V_54 & V_154 ) ||
! ( V_8 -> V_54 & V_163 ) ||
V_8 -> V_81 != V_83 )
V_33 = ( ( V_8 -> V_81 > V_83 ) ? 0 : - V_36 ) ;
else
V_33 = F_19 ( V_8 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
int F_78 ( struct V_7 * V_8 )
{
unsigned long V_70 , V_54 ;
int V_33 ;
if ( V_8 -> V_22 . V_23 == V_98 )
return - V_36 ;
if ( ! ( V_8 -> V_54 & V_154 ) ||
! ( V_8 -> V_54 & V_163 ) )
return - V_36 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
V_33 = - V_136 ;
V_70 = F_27 ( V_8 -> V_34 , 0 , 0 ) ;
if ( V_70 )
goto V_138;
V_70 = F_27 ( V_8 -> V_34 , V_8 -> V_71 , V_8 -> V_14 ) ;
if ( V_70 )
goto V_138;
V_70 = F_30 ( V_8 -> V_34 , 0 , 0 ) ;
if ( V_70 )
goto V_138;
V_70 = F_30 ( V_8 -> V_34 , V_8 -> V_73 , V_8 -> V_13 ) ;
if ( V_70 )
goto V_138;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_81 = V_83 ;
V_8 -> V_54 |= V_55 ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return 0 ;
V_138:
F_27 ( V_8 -> V_34 , 0 , 0 ) ;
F_30 ( V_8 -> V_34 , 0 , 0 ) ;
F_70 ( V_8 -> V_22 . V_144 , V_8 ) ;
F_70 ( V_8 -> V_22 . V_143 , V_8 ) ;
V_8 -> V_54 &= ~ ( V_162 |
V_163 ) ;
F_2 ( V_8 , V_3 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
int F_79 ( struct V_7 * V_8 )
{
return V_8 -> V_1 ;
}
static int F_80 ( struct V_7 * V_8 , const void * V_167 , unsigned int V_26 )
{
struct V_15 * V_17 ;
unsigned long V_16 ;
int V_33 ;
if ( V_26 > V_12 )
return - V_168 ;
V_17 = F_10 ( V_8 , & V_16 ) ;
if ( ! V_17 )
return - V_169 ;
memcpy ( V_17 , V_167 , V_26 ) ;
V_33 = F_16 ( V_8 , V_17 , V_16 ) ;
if ( ! V_33 )
V_33 = V_26 ;
return V_33 ;
}
static int F_81 ( struct V_7 * V_8 , void * V_167 , unsigned int V_26 )
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
if ( V_8 -> V_72 == V_170 ||
V_8 -> V_72 == V_171 )
return - V_76 ;
if ( V_8 -> V_74 == V_8 -> V_75 )
return 0 ;
V_17 = V_8 -> V_103 + ( V_8 -> V_74 / V_12 ) ;
memcpy ( V_167 , V_17 , V_12 ) ;
V_102 = F_5 ( V_8 , V_8 -> V_74 ) ;
V_8 -> V_74 = V_102 ;
V_33 = F_14 ( V_8 , V_102 ) ;
if ( V_33 < 0 )
V_33 = - V_76 ;
else
V_33 = V_12 ;
return V_33 ;
}
static int F_82 ( struct V_7 * V_8 , const void * V_167 ,
unsigned int V_26 )
{
unsigned long V_70 , V_28 ;
unsigned int V_172 ;
T_3 V_173 ;
int V_33 ;
V_70 = F_29 ( V_8 -> V_34 , & V_8 -> V_20 , & V_8 -> V_19 ,
& V_8 -> V_72 ) ;
if ( F_83 ( V_70 ) )
return - V_37 ;
if ( F_83 ( V_8 -> V_72 != V_99 ) )
return F_26 ( V_8 ) ;
if ( ! F_9 ( V_8 , V_26 ) )
return - V_169 ;
V_173 = V_8 -> V_65 ;
V_172 = 0 ;
V_28 = V_8 -> V_19 ;
while ( V_172 < V_26 ) {
struct V_15 * V_17 = V_8 -> V_21 + ( V_28 / V_12 ) ;
T_1 * V_41 = ( ( V_8 -> V_22 . V_23 == V_140 ) ?
V_17 -> V_44 . V_45 :
V_17 -> V_44 . V_66 . V_174 ) ;
int V_175 ;
V_17 -> type = V_104 ;
V_17 -> V_39 = V_52 ;
V_17 -> V_40 = 0 ;
V_175 = V_26 - V_172 ;
if ( V_175 > V_8 -> V_30 )
V_175 = V_8 -> V_30 ;
F_17 ( V_175 > V_176 ) ;
V_17 -> V_60 = ( V_175 |
( V_172 == 0 ? V_177 : 0 ) |
( V_175 == V_26 - V_172 ? V_178 : 0 ) ) ;
V_17 -> V_61 = ++ V_173 ;
F_3 ( V_179 , L_36 ,
V_17 -> type ,
V_17 -> V_39 ,
V_17 -> V_40 ,
V_17 -> V_60 ,
V_17 -> V_61 ) ;
memcpy ( V_41 , V_167 , V_175 ) ;
V_167 += V_175 ;
V_172 += V_175 ;
V_28 = F_6 ( V_8 , V_28 ) ;
}
V_33 = F_11 ( V_8 , V_28 ) ;
if ( ! V_33 ) {
V_8 -> V_65 = V_173 ;
V_33 = V_26 ;
}
return V_33 ;
}
static int F_84 ( struct V_7 * V_8 , struct V_15 * V_17 ,
struct V_15 * V_180 )
{
int V_33 ;
if ( V_180 )
V_8 -> V_62 = V_180 -> V_61 - 1 ;
V_33 = F_25 ( V_8 , V_17 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_14 ( V_8 , V_8 -> V_75 ) ;
if ( V_33 < 0 )
return F_26 ( V_8 ) ;
return 0 ;
}
static int F_85 ( struct V_7 * V_8 , struct V_15 * V_17 )
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
static int F_86 ( struct V_7 * V_8 , unsigned long V_181 )
{
unsigned long V_182 ;
int V_27 = 1000 ;
F_3 ( V_179 , L_37 ,
V_181 , V_8 -> V_74 , V_8 -> V_75 ) ;
while ( V_27 -- > 0 ) {
unsigned long V_70 ;
V_70 = F_31 ( V_8 -> V_34 ,
& V_182 ,
& V_8 -> V_75 ,
& V_8 -> V_72 ) ;
if ( V_70 )
return F_26 ( V_8 ) ;
if ( V_8 -> V_72 == V_170 ||
V_8 -> V_72 == V_171 )
return - V_76 ;
if ( V_181 != V_8 -> V_75 ) {
F_3 ( V_179 , L_38
L_39 ,
V_182 , V_8 -> V_75 , V_8 -> V_72 ) ;
return 0 ;
}
F_13 ( 1 ) ;
}
return - V_169 ;
}
static int F_87 ( struct V_7 * V_8 , unsigned long V_38 )
{
int V_33 = F_14 ( V_8 , V_38 ) ;
if ( V_33 < 0 )
return F_26 ( V_8 ) ;
V_8 -> V_74 = V_38 ;
return 0 ;
}
static void F_88 ( struct V_7 * V_8 )
{
unsigned long V_16 ;
struct V_15 * V_17 ;
V_17 = F_10 ( V_8 , & V_16 ) ;
if ( F_89 ( V_17 ) ) {
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
static int F_90 ( struct V_7 * V_8 , void * V_167 , unsigned int V_26 )
{
struct V_15 * V_180 ;
unsigned long V_70 , V_102 ;
int V_33 , V_172 ;
V_70 = F_31 ( V_8 -> V_34 ,
& V_8 -> V_74 ,
& V_8 -> V_75 ,
& V_8 -> V_72 ) ;
if ( V_70 )
return F_26 ( V_8 ) ;
if ( V_8 -> V_72 == V_170 ||
V_8 -> V_72 == V_171 )
return - V_76 ;
if ( V_8 -> V_74 == V_8 -> V_75 )
return 0 ;
V_180 = NULL ;
V_172 = V_33 = 0 ;
V_102 = V_8 -> V_74 ;
while ( 1 ) {
struct V_15 * V_17 ;
int V_183 ;
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
if ( F_83 ( ! F_40 ( V_8 , V_17 -> V_61 ) ) ) {
V_33 = F_84 ( V_8 , V_17 , V_180 ) ;
V_172 = 0 ;
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
goto V_184;
}
if ( V_17 -> V_39 & ( V_58 | V_56 ) ) {
V_33 = F_85 ( V_8 , V_17 ) ;
if ( V_33 )
break;
}
if ( ! ( V_17 -> V_39 & V_52 ) ) {
V_102 = F_5 ( V_8 , V_102 ) ;
V_33 = F_87 ( V_8 , V_102 ) ;
if ( V_33 )
break;
goto V_184;
}
V_183 = V_17 -> V_60 & V_176 ;
if ( ( V_180 == NULL && ! ( V_17 -> V_60 & V_177 ) ) ||
( V_180 != NULL && ( V_17 -> V_60 & V_177 ) ) ) {
if ( ! V_180 )
V_102 = F_5 ( V_8 , V_102 ) ;
V_33 = F_87 ( V_8 , V_102 ) ;
if ( V_33 )
break;
if ( ! V_180 )
goto V_184;
}
if ( ! V_180 )
V_180 = V_17 ;
if ( V_183 > V_26 - V_172 ) {
V_33 = - V_168 ;
break;
}
V_102 = F_5 ( V_8 , V_102 ) ;
memcpy ( V_167 ,
( V_8 -> V_22 . V_23 == V_140 ?
V_17 -> V_44 . V_45 : V_17 -> V_44 . V_66 . V_174 ) , V_183 ) ;
V_167 += V_183 ;
V_172 += V_183 ;
if ( V_17 -> V_60 & V_178 )
break;
V_184:
if ( V_102 == V_8 -> V_75 ) {
V_33 = F_86 ( V_8 , V_102 ) ;
if ( V_33 )
break;
}
}
if ( ! V_33 )
V_33 = F_87 ( V_8 , V_102 ) ;
if ( V_33 && V_180 )
V_8 -> V_62 = V_180 -> V_61 - 1 ;
if ( ! V_33 ) {
V_33 = V_172 ;
if ( V_33 > 0 && V_8 -> V_22 . V_23 != V_140 )
F_88 ( V_8 ) ;
}
return V_33 ;
}
static int F_91 ( struct V_7 * V_8 , const void * V_167 ,
unsigned int V_26 )
{
if ( V_26 > V_8 -> V_22 . V_148 )
V_26 = V_8 -> V_22 . V_148 ;
return F_82 ( V_8 , V_167 , V_26 ) ;
}
static int F_92 ( struct V_7 * V_8 , void * V_167 , unsigned int V_26 )
{
if ( ! V_8 -> V_185 ) {
int V_33 = F_90 ( V_8 , V_8 -> V_135 , V_8 -> V_22 . V_148 ) ;
if ( V_33 < 0 )
return V_33 ;
V_8 -> V_185 = V_33 ;
V_8 -> V_186 = 0 ;
}
if ( V_26 > V_8 -> V_185 )
V_26 = V_8 -> V_185 ;
memcpy ( V_167 , V_8 -> V_135 + V_8 -> V_186 , V_26 ) ;
V_8 -> V_186 += V_26 ;
V_8 -> V_185 -= V_26 ;
return V_26 ;
}
int F_93 ( struct V_7 * V_8 , const void * V_167 , unsigned int V_26 )
{
unsigned long V_54 ;
int V_33 ;
if ( ! V_167 )
return - V_36 ;
if ( ! V_26 )
return 0 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
if ( V_8 -> V_81 != V_85 )
V_33 = - V_187 ;
else
V_33 = V_8 -> V_132 -> V_188 ( V_8 , V_167 , V_26 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
int F_94 ( struct V_7 * V_8 , void * V_167 , unsigned int V_26 )
{
unsigned long V_54 ;
int V_33 ;
if ( ! V_167 )
return - V_36 ;
if ( ! V_26 )
return 0 ;
F_47 ( & V_8 -> V_96 , V_54 ) ;
if ( V_8 -> V_81 != V_85 )
V_33 = - V_187 ;
else
V_33 = V_8 -> V_132 -> V_189 ( V_8 , V_167 , V_26 ) ;
F_48 ( & V_8 -> V_96 , V_54 ) ;
return V_33 ;
}
static long F_95 ( struct V_119 * V_120 , unsigned long V_190 )
{
struct V_191 * V_124 = & V_120 -> V_124 ;
unsigned long V_192 , V_193 , V_194 , V_27 ;
int V_195 ;
V_27 = V_124 -> V_27 ;
V_193 = V_124 -> V_196 ;
V_195 = 0 ;
V_197:
V_192 = F_96 ( V_124 -> V_125 , V_27 , V_193 , V_190 , 0 ) ;
V_194 = V_192 + V_190 ;
if ( F_83 ( V_194 >= V_27 ) ) {
if ( F_89 ( V_195 < 1 ) ) {
V_27 = V_193 ;
V_193 = 0 ;
V_195 ++ ;
goto V_197;
} else {
return - 1 ;
}
}
F_97 ( V_124 -> V_125 , V_192 , V_190 ) ;
V_124 -> V_196 = V_194 ;
return V_192 ;
}
static T_5 F_98 ( void )
{
switch ( V_115 ) {
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
static T_5 F_99 ( T_5 V_198 , T_5 V_199 , T_5 V_200 )
{
return ( ( V_199 << V_201 ) |
( V_198 << V_202 ) |
V_200 ) ;
}
static T_5 F_100 ( T_5 V_203 , unsigned long * V_204 )
{
T_5 V_205 = V_203 >> V_201 ;
V_203 &= ~ V_206 ;
* V_204 = V_205 * 3 ;
return ( V_203 >> ( 13ULL + ( V_205 * 3ULL ) ) ) ;
}
static struct V_121 * F_101 ( struct V_119 * V_120 ,
unsigned long V_190 )
{
long V_207 ;
V_207 = F_95 ( V_120 , V_190 ) ;
if ( F_83 ( V_207 < 0 ) )
return NULL ;
return V_120 -> V_127 + V_207 ;
}
static T_5 F_102 ( unsigned int V_208 )
{
T_5 V_209 ;
V_209 = F_98 () ;
if ( V_208 & V_210 ) {
if ( V_208 & V_211 )
V_209 |= V_212 ;
if ( V_208 & V_213 )
V_209 |= V_214 ;
}
if ( V_208 & V_215 ) {
if ( V_208 & V_211 )
V_209 |= V_216 ;
if ( V_208 & V_213 )
V_209 |= V_217 ;
if ( V_208 & V_218 )
V_209 |= V_219 ;
}
if ( V_208 & V_220 ) {
if ( V_208 & V_211 )
V_209 |= V_221 ;
if ( V_208 & V_213 )
V_209 |= V_222 ;
}
return V_209 ;
}
static int F_103 ( unsigned long V_109 , long V_223 )
{
int V_224 = 0 ;
do {
unsigned long V_102 = ( V_109 + V_115 ) & V_225 ;
V_223 -= ( V_102 - V_109 ) ;
V_109 = V_102 ;
V_224 ++ ;
} while ( V_223 > 0 );
return V_224 ;
}
static void F_104 ( struct V_226 * V_227 , unsigned long V_228 ,
unsigned long V_10 , unsigned long V_223 )
{
do {
unsigned long V_229 , V_102 = V_228 + V_115 ;
T_5 V_230 ;
V_227 -> V_127 [ V_227 -> V_231 ] . V_232 = V_227 -> V_209 | V_228 ;
V_229 = V_115 ;
if ( V_10 )
V_229 = V_115 - V_10 ;
if ( V_229 > V_223 )
V_229 = V_223 ;
V_230 = F_99 ( V_227 -> V_231 ,
F_98 () , V_10 ) ;
V_10 = 0 ;
if ( V_230 == V_227 -> V_233 ) {
V_227 -> V_234 [ V_227 -> V_235 - 1 ] . V_236 += V_229 ;
} else {
V_227 -> V_234 [ V_227 -> V_235 ] . V_237 = V_230 ;
V_227 -> V_234 [ V_227 -> V_235 ] . V_236 = V_229 ;
V_227 -> V_235 ++ ;
}
V_227 -> V_233 = V_230 + V_229 ;
V_227 -> V_231 ++ ;
V_223 -= V_229 ;
V_228 = V_102 ;
} while ( V_223 > 0 );
}
static int F_105 ( struct V_238 * V_239 )
{
unsigned long V_109 = F_106 ( F_107 ( V_239 ) ) << V_202 ;
long V_223 = V_239 -> V_240 ;
if ( ( V_239 -> V_241 | V_223 ) & ( 8UL - 1 ) )
return - V_242 ;
return F_103 ( V_109 + V_239 -> V_241 , V_223 ) ;
}
static int F_108 ( struct V_238 * V_239 , int V_243 )
{
int V_224 ;
int V_78 ;
V_224 = 0 ;
for ( V_78 = 0 ; V_78 < V_243 ; V_78 ++ ) {
int V_33 = F_105 ( V_239 + V_78 ) ;
if ( V_33 < 0 )
return V_33 ;
V_224 += V_33 ;
}
return V_224 ;
}
int F_109 ( struct V_7 * V_8 ,
struct V_238 * V_239 , int V_243 ,
struct V_244 * V_234 , int V_245 ,
unsigned int V_208 )
{
unsigned long V_78 , V_190 , V_54 ;
struct V_121 * V_109 ;
struct V_226 V_1 ;
struct V_119 * V_120 ;
int V_33 ;
if ( V_208 & ~ V_246 )
return - V_36 ;
V_33 = F_108 ( V_239 , V_243 ) ;
if ( V_33 < 0 )
return V_33 ;
V_190 = V_33 ;
if ( V_33 > V_245 )
return - V_168 ;
V_120 = & V_8 -> V_120 ;
F_47 ( & V_120 -> V_96 , V_54 ) ;
V_109 = F_101 ( V_120 , V_190 ) ;
F_48 ( & V_120 -> V_96 , V_54 ) ;
if ( ! V_109 )
return - V_114 ;
V_1 . V_127 = V_120 -> V_127 ;
V_1 . V_234 = V_234 ;
V_1 . V_209 = F_102 ( V_208 ) ;
V_1 . V_233 = ~ ( T_5 ) 0 ;
V_1 . V_231 = ( V_109 - V_120 -> V_127 ) ;
V_1 . V_235 = 0 ;
for ( V_78 = 0 ; V_78 < V_243 ; V_78 ++ )
F_104 ( & V_1 , F_106 ( F_107 ( & V_239 [ V_78 ] ) ) << V_202 ,
V_239 [ V_78 ] . V_241 , V_239 [ V_78 ] . V_240 ) ;
return V_1 . V_235 ;
}
int F_110 ( struct V_7 * V_8 ,
void * V_167 , unsigned int V_223 ,
struct V_244 * V_234 , int V_245 ,
unsigned int V_208 )
{
unsigned long V_190 , V_228 , V_54 ;
struct V_121 * V_109 ;
struct V_226 V_1 ;
struct V_119 * V_120 ;
if ( ( V_208 & ~ V_246 ) || ( V_245 < 1 ) )
return - V_36 ;
V_228 = F_55 ( V_167 ) ;
if ( ( V_228 | V_223 ) & ( 8UL - 1 ) )
return - V_242 ;
V_190 = F_103 ( V_228 , V_223 ) ;
V_120 = & V_8 -> V_120 ;
F_47 ( & V_120 -> V_96 , V_54 ) ;
V_109 = F_101 ( V_120 , V_190 ) ;
F_48 ( & V_120 -> V_96 , V_54 ) ;
if ( ! V_109 )
return - V_114 ;
V_1 . V_127 = V_120 -> V_127 ;
V_1 . V_234 = V_234 ;
V_1 . V_209 = F_102 ( V_208 ) ;
V_1 . V_233 = ~ ( T_5 ) 0 ;
V_1 . V_231 = ( V_109 - V_120 -> V_127 ) ;
V_1 . V_235 = 0 ;
F_104 ( & V_1 , ( V_228 & V_225 ) , ( V_228 & ~ V_225 ) , V_223 ) ;
F_17 ( V_1 . V_235 > V_245 ) ;
return V_1 . V_235 ;
}
static void F_111 ( unsigned long V_34 , struct V_119 * V_120 ,
T_5 V_203 , T_5 V_26 )
{
struct V_191 * V_124 = & V_120 -> V_124 ;
unsigned long V_78 , V_204 , V_198 , V_190 ;
struct V_121 * V_109 ;
V_190 = F_112 ( ( ( V_203 & ~ V_225 ) + V_26 ) ) >> V_202 ;
V_198 = F_100 ( V_203 , & V_204 ) ;
V_109 = V_120 -> V_127 + V_198 ;
F_17 ( V_198 > V_124 -> V_27 ||
( V_198 + V_190 ) > V_124 -> V_27 ) ;
for ( V_78 = 0 ; V_78 < V_190 ; V_78 ++ ) {
if ( V_109 -> V_203 )
F_113 ( V_34 , V_203 + ( V_78 << V_204 ) ,
V_109 -> V_203 ) ;
V_109 -> V_232 = 0 ;
F_114 ( V_198 + V_78 , V_124 -> V_125 ) ;
}
}
void F_115 ( struct V_7 * V_8 , struct V_244 * V_234 ,
int V_245 )
{
struct V_119 * V_120 = & V_8 -> V_120 ;
unsigned long V_54 ;
int V_78 ;
F_47 ( & V_120 -> V_96 , V_54 ) ;
for ( V_78 = 0 ; V_78 < V_245 ; V_78 ++ ) {
T_5 V_247 = V_234 [ V_78 ] . V_237 ;
T_5 V_26 = V_234 [ V_78 ] . V_236 ;
F_111 ( V_8 -> V_34 , V_120 , V_247 , V_26 ) ;
}
F_48 ( & V_120 -> V_96 , V_54 ) ;
}
int F_116 ( struct V_7 * V_8 , int V_248 ,
void * V_167 , unsigned int V_223 , unsigned long V_241 ,
struct V_244 * V_234 , int V_245 )
{
unsigned int V_249 ;
unsigned long V_110 ;
int V_78 ;
if ( V_248 != V_250 && V_248 != V_251 ) {
F_28 (KERN_ERR PFX L_42 ,
lp->id, copy_dir) ;
return - V_36 ;
}
V_110 = F_55 ( V_167 ) ;
if ( ( V_110 | V_223 | V_241 ) & ( 8UL - 1 ) ) {
F_28 (KERN_ERR PFX L_43
L_44 ,
lp->id, ra, len, offset) ;
return - V_242 ;
}
if ( V_8 -> V_81 != V_85 ||
( V_8 -> V_54 & V_55 ) ) {
F_28 (KERN_ERR PFX L_45
L_46 , lp->id, lp->hs_state, lp->flags) ;
return - V_76 ;
}
V_249 = V_223 ;
for ( V_78 = 0 ; V_78 < V_245 ; V_78 ++ ) {
unsigned long V_252 = V_234 [ V_78 ] . V_237 ;
unsigned long V_253 = V_234 [ V_78 ] . V_236 ;
unsigned long V_254 ;
if ( F_83 ( V_241 ) ) {
unsigned long V_255 = V_241 ;
if ( V_255 > V_253 )
V_255 = V_253 ;
V_241 -= V_255 ;
V_253 -= V_255 ;
if ( ! V_253 )
continue;
V_252 += V_255 ;
}
if ( V_253 > V_223 )
V_253 = V_223 ;
while ( 1 ) {
unsigned long V_70 ;
V_70 = F_117 ( V_8 -> V_34 , V_248 ,
V_252 , V_110 ,
V_253 , & V_254 ) ;
if ( F_83 ( V_70 ) ) {
F_28 (KERN_ERR PFX L_47
L_48 ,
lp->id, hv_err) ;
if ( V_8 -> V_81 != V_85 ||
( V_8 -> V_54 & V_55 ) )
return - V_76 ;
else
return - V_242 ;
}
V_252 += V_254 ;
V_110 += V_254 ;
V_223 -= V_254 ;
if ( V_254 == V_253 )
break;
V_253 -= V_254 ;
}
if ( ! V_223 )
break;
}
return V_249 - V_223 ;
}
void * F_118 ( struct V_7 * V_8 , unsigned int V_223 ,
struct V_244 * V_234 , int * V_245 ,
unsigned int V_208 )
{
void * V_167 ;
int V_33 ;
if ( V_223 & ( 8UL - 1 ) )
return F_71 ( - V_36 ) ;
V_167 = F_60 ( V_223 , V_113 ) ;
if ( ! V_167 )
return F_71 ( - V_114 ) ;
V_33 = F_110 ( V_8 , V_167 , V_223 , V_234 , * V_245 , V_208 ) ;
if ( V_33 < 0 ) {
F_62 ( V_167 ) ;
return F_71 ( V_33 ) ;
}
* V_245 = V_33 ;
return V_167 ;
}
void F_119 ( struct V_7 * V_8 , void * V_167 , unsigned int V_223 ,
struct V_244 * V_234 , int V_245 )
{
F_115 ( V_8 , V_234 , V_245 ) ;
F_62 ( V_167 ) ;
}
static int T_6 F_120 ( void )
{
unsigned long V_50 , V_51 ;
struct V_256 * V_257 ;
const T_5 * V_79 ;
int V_33 ;
T_5 V_258 ;
V_257 = F_121 () ;
if ( ! V_257 )
return - V_136 ;
V_258 = F_122 ( V_257 , V_259 , L_49 ) ;
V_33 = - V_136 ;
if ( V_258 == V_259 )
goto V_100;
V_79 = F_123 ( V_257 , V_258 , L_50 , NULL ) ;
if ( ! V_79 )
goto V_100;
V_50 = 1 ;
V_51 = 0 ;
if ( F_124 ( V_260 , V_50 , & V_51 ) ) {
F_28 (KERN_INFO PFX L_51 ) ;
goto V_100;
}
F_28 ( V_261 L_52 , V_262 ) ;
if ( ! * V_79 ) {
F_28 (KERN_INFO PFX L_53 ) ;
goto V_100;
}
V_137 = 1 ;
V_33 = 0 ;
V_100:
F_125 ( V_257 ) ;
return V_33 ;
}
