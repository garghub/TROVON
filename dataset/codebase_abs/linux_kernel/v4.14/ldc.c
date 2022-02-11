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
static unsigned long F_2 ( unsigned long V_7 , unsigned long V_8 )
{
V_7 += V_9 ;
if ( V_7 == ( V_8 * V_9 ) )
V_7 = 0 ;
return V_7 ;
}
static unsigned long F_3 ( struct V_10 * V_11 , unsigned long V_7 )
{
return F_2 ( V_7 , V_11 -> V_12 ) ;
}
static unsigned long F_4 ( struct V_10 * V_11 , unsigned long V_7 )
{
return F_2 ( V_7 , V_11 -> V_13 ) ;
}
static struct V_14 * F_5 ( struct V_10 * V_11 ,
unsigned long * V_15 )
{
struct V_14 * V_16 ;
unsigned long V_17 ;
V_17 = F_4 ( V_11 , V_11 -> V_18 ) ;
if ( V_17 == V_11 -> V_19 )
return NULL ;
* V_15 = V_17 ;
V_16 = V_11 -> V_20 ;
return V_16 + ( V_11 -> V_18 / V_9 ) ;
}
static unsigned long F_6 ( struct V_10 * V_11 )
{
if ( V_11 -> V_21 . V_22 == V_23 )
return V_11 -> V_24 ;
return V_11 -> V_19 ;
}
static int F_7 ( struct V_10 * V_11 , unsigned int V_25 )
{
unsigned long V_26 , V_27 , V_15 , V_28 ;
unsigned int V_29 ;
V_26 = F_6 ( V_11 ) ;
V_27 = V_11 -> V_18 ;
V_15 = F_4 ( V_11 , V_27 ) ;
if ( V_15 == V_26 )
return 0 ;
if ( V_26 > V_15 )
V_28 = V_26 - V_15 ;
else
V_28 = ( V_26 +
( ( V_11 -> V_13 * V_9 ) - V_15 ) ) ;
V_28 /= V_9 ;
V_29 = V_11 -> V_29 ;
if ( V_28 * V_29 < V_25 )
return 0 ;
return 1 ;
}
static struct V_14 * F_8 ( struct V_10 * V_11 ,
unsigned long * V_15 )
{
struct V_14 * V_16 ;
unsigned long V_30 , V_17 ;
V_30 = F_6 ( V_11 ) ;
V_17 = F_4 ( V_11 , V_11 -> V_18 ) ;
if ( V_17 == V_30 )
return NULL ;
* V_15 = V_17 ;
V_16 = V_11 -> V_20 ;
return V_16 + ( V_11 -> V_18 / V_9 ) ;
}
static int F_9 ( struct V_10 * V_11 , unsigned long V_27 )
{
unsigned long V_31 = V_11 -> V_18 ;
int V_26 = 1000 ;
V_11 -> V_18 = V_27 ;
while ( V_26 -- > 0 ) {
unsigned long V_32 ;
V_32 = F_10 ( V_11 -> V_33 , V_27 ) ;
if ( ! V_32 )
return 0 ;
if ( V_32 != V_34 ) {
V_11 -> V_18 = V_31 ;
return - V_35 ;
}
F_11 ( 1 ) ;
}
V_11 -> V_18 = V_31 ;
return - V_36 ;
}
static int F_12 ( struct V_10 * V_11 , unsigned long V_37 )
{
int V_26 = 1000 ;
while ( V_26 -- > 0 ) {
unsigned long V_32 ;
V_32 = F_13 ( V_11 -> V_33 , V_37 ) ;
if ( ! V_32 )
return 0 ;
if ( V_32 != V_34 )
return - V_35 ;
F_11 ( 1 ) ;
}
return - V_36 ;
}
static int F_14 ( struct V_10 * V_11 ,
struct V_14 * V_16 ,
unsigned long V_15 )
{
F_15 ( V_16 != ( V_11 -> V_20 + ( V_11 -> V_18 / V_9 ) ) ) ;
return F_9 ( V_11 , V_15 ) ;
}
static struct V_14 * F_16 ( struct V_10 * V_11 ,
T_1 V_38 , T_1 V_39 ,
void * V_40 , int V_41 ,
unsigned long * V_15 )
{
struct V_14 * V_16 = F_5 ( V_11 , V_15 ) ;
if ( V_16 ) {
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> type = V_42 ;
V_16 -> V_38 = V_38 ;
V_16 -> V_39 = V_39 ;
if ( V_40 )
memcpy ( V_16 -> V_43 . V_44 , V_40 , V_41 ) ;
}
return V_16 ;
}
static int F_17 ( struct V_10 * V_11 )
{
struct V_14 * V_16 ;
struct V_45 * V_46 ;
unsigned long V_15 ;
V_46 = & V_47 [ 0 ] ;
F_18 ( V_48 , L_7 ,
V_46 -> V_49 , V_46 -> V_50 ) ;
V_16 = F_16 ( V_11 , V_51 , V_52 ,
V_46 , sizeof( * V_46 ) , & V_15 ) ;
if ( V_16 ) {
int V_32 = F_14 ( V_11 , V_16 , V_15 ) ;
if ( ! V_32 )
V_11 -> V_53 &= ~ V_54 ;
return V_32 ;
}
return - V_36 ;
}
static int F_19 ( struct V_10 * V_11 ,
T_2 V_49 , T_2 V_50 )
{
struct V_14 * V_16 ;
struct V_45 V_46 ;
unsigned long V_15 ;
V_46 . V_49 = V_49 ;
V_46 . V_50 = V_50 ;
V_16 = F_16 ( V_11 , V_55 , V_52 ,
& V_46 , sizeof( V_46 ) , & V_15 ) ;
if ( V_16 ) {
F_18 ( V_48 , L_8 ,
V_46 . V_49 , V_46 . V_50 ) ;
return F_14 ( V_11 , V_16 , V_15 ) ;
}
return - V_36 ;
}
static int F_20 ( struct V_10 * V_11 ,
struct V_45 * V_56 )
{
struct V_14 * V_16 ;
unsigned long V_15 ;
V_16 = F_16 ( V_11 , V_57 , V_52 ,
V_56 , sizeof( * V_56 ) , & V_15 ) ;
if ( V_16 ) {
F_18 ( V_48 , L_9 ,
V_56 -> V_49 , V_56 -> V_50 ) ;
return F_14 ( V_11 , V_16 , V_15 ) ;
}
return - V_36 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_14 * V_16 ;
unsigned long V_15 ;
V_16 = F_16 ( V_11 , V_51 , V_58 , NULL , 0 ,
& V_15 ) ;
if ( V_16 ) {
V_16 -> V_59 = V_11 -> V_21 . V_22 ;
V_16 -> V_60 = 0 ;
V_11 -> V_61 = 0 ;
F_18 ( V_48 , L_10 ,
V_16 -> V_59 , V_16 -> V_60 ) ;
return F_14 ( V_11 , V_16 , V_15 ) ;
}
return - V_36 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_14 * V_16 ;
unsigned long V_15 ;
V_16 = F_16 ( V_11 , V_51 , V_62 , NULL , 0 ,
& V_15 ) ;
if ( V_16 ) {
V_16 -> V_59 = V_11 -> V_21 . V_22 ;
V_16 -> V_60 = 0 ;
F_18 ( V_48 , L_11 ,
V_16 -> V_59 , V_16 -> V_60 ) ;
return F_14 ( V_11 , V_16 , V_15 ) ;
}
return - V_36 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_14 * V_16 ;
unsigned long V_15 ;
V_16 = F_16 ( V_11 , V_51 , V_63 , NULL , 0 ,
& V_15 ) ;
if ( V_16 ) {
V_16 -> V_59 = 0 ;
V_16 -> V_60 = ++ V_11 -> V_64 ;
V_16 -> V_43 . V_65 . V_66 = V_11 -> V_61 ;
F_18 ( V_48 , L_12 ,
V_16 -> V_59 , V_16 -> V_60 , V_16 -> V_43 . V_65 . V_66 ) ;
return F_14 ( V_11 , V_16 , V_15 ) ;
}
return - V_36 ;
}
static int F_24 ( struct V_10 * V_11 , struct V_14 * V_67 )
{
struct V_14 * V_16 ;
unsigned long V_15 ;
int V_32 ;
V_16 = F_8 ( V_11 , & V_15 ) ;
if ( ! V_16 )
return - V_36 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> type = V_67 -> type ;
V_16 -> V_38 = V_55 ;
V_16 -> V_39 = V_67 -> V_39 & V_68 ;
V_16 -> V_60 = V_11 -> V_64 + 1 ;
V_16 -> V_43 . V_65 . V_66 = V_11 -> V_61 ;
F_18 ( V_48 , L_13 ,
V_16 -> type , V_16 -> V_39 , V_16 -> V_60 , V_16 -> V_43 . V_65 . V_66 ) ;
V_32 = F_14 ( V_11 , V_16 , V_15 ) ;
if ( ! V_32 )
V_11 -> V_64 ++ ;
return V_32 ;
}
static int F_25 ( struct V_10 * V_11 , const char * V_69 )
{
unsigned long V_70 ;
F_18 ( V_71 , L_14 , V_69 ) ;
F_26 ( V_11 ) ;
V_70 = F_27 ( V_11 -> V_33 , V_11 -> V_72 , V_11 -> V_13 ) ;
if ( V_70 )
F_28 (KERN_ERR PFX L_15
L_16 ,
lp->id, lp->tx_ra, lp->tx_num_entries, hv_err) ;
V_70 = F_29 ( V_11 -> V_33 ,
& V_11 -> V_19 ,
& V_11 -> V_18 ,
& V_11 -> V_73 ) ;
if ( V_70 )
F_28 (KERN_ERR PFX L_15
L_17 ,
lp->id, hv_err) ;
V_70 = F_30 ( V_11 -> V_33 , V_11 -> V_74 , V_11 -> V_12 ) ;
if ( V_70 )
F_28 (KERN_ERR PFX L_15
L_18 ,
lp->id, lp->rx_ra, lp->rx_num_entries, hv_err) ;
V_70 = F_31 ( V_11 -> V_33 ,
& V_11 -> V_75 ,
& V_11 -> V_76 ,
& V_11 -> V_73 ) ;
if ( V_70 )
F_28 (KERN_ERR PFX L_15
L_19 ,
lp->id, hv_err) ;
return - V_77 ;
}
static struct V_45 * F_32 ( T_2 V_49 )
{
struct V_45 * V_78 = NULL ;
int V_79 ;
for ( V_79 = 0 ; V_79 < F_33 ( V_47 ) ; V_79 ++ ) {
struct V_45 * V_80 = & V_47 [ V_79 ] ;
if ( V_80 -> V_49 <= V_49 ) {
V_78 = V_80 ;
break;
}
}
return V_78 ;
}
static int F_34 ( struct V_10 * V_11 , struct V_45 * V_56 )
{
struct V_45 * V_81 ;
int V_32 ;
F_18 ( V_48 , L_20 ,
V_56 -> V_49 , V_56 -> V_50 ) ;
if ( V_11 -> V_82 == V_83 ) {
V_11 -> V_82 = V_84 ;
memset ( & V_11 -> V_46 , 0 , sizeof( V_11 -> V_46 ) ) ;
}
V_81 = F_32 ( V_56 -> V_49 ) ;
if ( ! V_81 ) {
V_32 = F_19 ( V_11 , 0 , 0 ) ;
} else if ( V_81 -> V_49 != V_56 -> V_49 ) {
V_32 = F_19 ( V_11 , V_81 -> V_49 , V_81 -> V_50 ) ;
} else {
struct V_45 V_46 = * V_56 ;
if ( V_46 . V_50 > V_81 -> V_50 )
V_46 . V_50 = V_81 -> V_50 ;
V_32 = F_20 ( V_11 , & V_46 ) ;
if ( ! V_32 ) {
V_11 -> V_46 = V_46 ;
V_11 -> V_82 = V_83 ;
}
}
if ( V_32 )
return F_35 ( V_11 ) ;
return 0 ;
}
static int F_36 ( struct V_10 * V_11 , struct V_45 * V_56 )
{
F_18 ( V_48 , L_21 ,
V_56 -> V_49 , V_56 -> V_50 ) ;
if ( V_11 -> V_82 == V_83 ) {
if ( V_11 -> V_46 . V_49 != V_56 -> V_49 ||
V_11 -> V_46 . V_50 != V_56 -> V_50 )
return F_35 ( V_11 ) ;
} else {
V_11 -> V_46 = * V_56 ;
V_11 -> V_82 = V_83 ;
}
if ( F_21 ( V_11 ) )
return F_35 ( V_11 ) ;
return 0 ;
}
static int F_37 ( struct V_10 * V_11 , struct V_45 * V_56 )
{
struct V_45 * V_81 ;
struct V_14 * V_16 ;
unsigned long V_15 ;
if ( V_56 -> V_49 == 0 && V_56 -> V_50 == 0 )
return F_35 ( V_11 ) ;
V_81 = F_32 ( V_56 -> V_49 ) ;
if ( ! V_81 )
return F_35 ( V_11 ) ;
V_16 = F_16 ( V_11 , V_51 , V_52 ,
V_81 , sizeof( * V_81 ) ,
& V_15 ) ;
if ( ! V_16 )
return F_35 ( V_11 ) ;
return F_14 ( V_11 , V_16 , V_15 ) ;
}
static int F_38 ( struct V_10 * V_11 ,
struct V_14 * V_16 )
{
struct V_45 * V_56 ;
V_56 = (struct V_45 * ) V_16 -> V_43 . V_44 ;
switch ( V_16 -> V_38 ) {
case V_51 :
return F_34 ( V_11 , V_56 ) ;
case V_57 :
return F_36 ( V_11 , V_56 ) ;
case V_55 :
return F_37 ( V_11 , V_56 ) ;
default:
return F_35 ( V_11 ) ;
}
}
static int F_39 ( struct V_10 * V_11 ,
struct V_14 * V_16 )
{
F_18 ( V_48 , L_22 ,
V_16 -> V_38 , V_16 -> V_60 , V_16 -> V_59 ) ;
if ( V_16 -> V_38 != V_51 ||
V_11 -> V_82 != V_83 ||
V_16 -> V_59 != V_11 -> V_21 . V_22 )
return F_35 ( V_11 ) ;
V_11 -> V_64 = V_16 -> V_60 ;
V_11 -> V_61 = V_16 -> V_60 ;
V_11 -> V_82 = V_85 ;
if ( F_22 ( V_11 ) )
return F_35 ( V_11 ) ;
return 0 ;
}
static int F_40 ( struct V_10 * V_11 ,
struct V_14 * V_16 )
{
F_18 ( V_48 , L_23 ,
V_16 -> V_38 , V_16 -> V_60 , V_16 -> V_59 ) ;
if ( V_16 -> V_38 != V_51 ||
V_16 -> V_59 != V_11 -> V_21 . V_22 )
return F_35 ( V_11 ) ;
V_11 -> V_64 = V_16 -> V_60 ;
V_11 -> V_82 = V_86 ;
F_41 ( V_11 , V_6 ) ;
F_23 ( V_11 ) ;
return V_87 ;
}
static int F_42 ( struct V_10 * V_11 , T_3 V_60 )
{
return V_11 -> V_61 + 1 == V_60 ;
}
static int F_43 ( struct V_10 * V_11 ,
struct V_14 * V_16 )
{
F_18 ( V_48 , L_24 ,
V_16 -> V_38 , V_16 -> V_60 , V_16 -> V_59 , V_16 -> V_43 . V_65 . V_66 ) ;
if ( V_16 -> V_38 != V_51 ||
! ( F_42 ( V_11 , V_16 -> V_60 ) ) )
return F_35 ( V_11 ) ;
V_11 -> V_61 = V_16 -> V_60 ;
V_11 -> V_82 = V_86 ;
F_41 ( V_11 , V_6 ) ;
return V_87 ;
}
static int F_44 ( struct V_10 * V_11 ,
struct V_14 * V_16 )
{
switch ( V_16 -> V_39 ) {
case V_52 :
return F_38 ( V_11 , V_16 ) ;
case V_58 :
return F_39 ( V_11 , V_16 ) ;
case V_62 :
return F_40 ( V_11 , V_16 ) ;
case V_63 :
return F_43 ( V_11 , V_16 ) ;
default:
return F_35 ( V_11 ) ;
}
}
static int F_45 ( struct V_10 * V_11 ,
struct V_14 * V_16 )
{
return F_35 ( V_11 ) ;
}
static int F_46 ( struct V_10 * V_11 ,
struct V_14 * V_88 )
{
unsigned long V_37 = V_11 -> V_24 ;
T_3 V_66 = V_88 -> V_43 . V_65 . V_66 ;
while ( 1 ) {
struct V_14 * V_16 = V_11 -> V_20 + ( V_37 / V_9 ) ;
V_37 = F_4 ( V_11 , V_37 ) ;
if ( V_16 -> V_60 == V_66 ) {
V_11 -> V_24 = V_37 ;
return 0 ;
}
if ( V_37 == V_11 -> V_18 )
return F_35 ( V_11 ) ;
}
return 0 ;
}
static void F_47 ( struct V_10 * V_11 , unsigned int V_89 )
{
if ( V_89 & V_90 )
V_11 -> V_21 . V_91 ( V_11 -> V_92 , V_90 ) ;
if ( V_89 & V_87 )
V_11 -> V_21 . V_91 ( V_11 -> V_92 , V_87 ) ;
if ( V_89 & V_93 )
V_11 -> V_21 . V_91 ( V_11 -> V_92 , V_93 ) ;
}
static T_4 F_48 ( int V_94 , void * V_95 )
{
struct V_10 * V_11 = V_95 ;
unsigned long V_96 , V_53 ;
unsigned int V_89 ;
F_49 ( & V_11 -> V_97 , V_53 ) ;
V_96 = V_11 -> V_73 ;
F_31 ( V_11 -> V_33 ,
& V_11 -> V_75 ,
& V_11 -> V_76 ,
& V_11 -> V_73 ) ;
F_18 ( V_98 , L_25 ,
V_96 , V_11 -> V_73 , V_11 -> V_75 , V_11 -> V_76 ) ;
V_89 = 0 ;
if ( V_11 -> V_21 . V_22 == V_99 &&
V_11 -> V_73 == V_100 ) {
V_11 -> V_82 = V_86 ;
F_41 ( V_11 , V_6 ) ;
if ( V_96 != V_100 ) {
V_89 |= V_87 ;
V_96 = V_11 -> V_73 ;
}
}
if ( V_11 -> V_53 & V_54 ) {
( void ) F_50 ( V_11 ) ;
goto V_101;
}
if ( V_11 -> V_82 == V_86 ) {
V_102:
if ( V_11 -> V_73 != V_96 ) {
unsigned int V_91 = V_90 ;
if ( V_11 -> V_73 == V_100 )
V_91 = V_87 ;
V_89 |= V_91 ;
}
if ( V_11 -> V_75 != V_11 -> V_76 )
V_89 |= V_93 ;
goto V_101;
}
if ( V_11 -> V_73 != V_96 )
goto V_101;
while ( V_11 -> V_75 != V_11 -> V_76 ) {
struct V_14 * V_16 ;
unsigned long V_103 ;
int V_32 ;
V_16 = V_11 -> V_104 + ( V_11 -> V_75 / V_9 ) ;
switch ( V_16 -> type ) {
case V_42 :
V_32 = F_44 ( V_11 , V_16 ) ;
if ( V_32 > 0 )
V_89 |= V_32 ;
break;
case V_105 :
V_89 |= V_93 ;
V_32 = 0 ;
break;
case V_106 :
V_32 = F_45 ( V_11 , V_16 ) ;
break;
default:
V_32 = F_35 ( V_11 ) ;
break;
}
if ( V_32 < 0 )
break;
V_103 = V_11 -> V_75 ;
V_103 += V_9 ;
if ( V_103 == ( V_11 -> V_12 * V_9 ) )
V_103 = 0 ;
V_11 -> V_75 = V_103 ;
V_32 = F_12 ( V_11 , V_103 ) ;
if ( V_32 < 0 ) {
( void ) F_35 ( V_11 ) ;
break;
}
if ( V_11 -> V_82 == V_86 )
goto V_102;
}
V_101:
F_51 ( & V_11 -> V_97 , V_53 ) ;
F_47 ( V_11 , V_89 ) ;
return V_107 ;
}
static T_4 F_52 ( int V_94 , void * V_95 )
{
struct V_10 * V_11 = V_95 ;
unsigned long V_53 , V_96 ;
unsigned int V_89 = 0 ;
F_49 ( & V_11 -> V_97 , V_53 ) ;
V_96 = V_11 -> V_73 ;
F_29 ( V_11 -> V_33 ,
& V_11 -> V_19 ,
& V_11 -> V_18 ,
& V_11 -> V_73 ) ;
F_18 ( V_108 , L_26 ,
V_96 , V_11 -> V_73 , V_11 -> V_19 , V_11 -> V_18 ) ;
if ( V_11 -> V_21 . V_22 == V_99 &&
V_11 -> V_73 == V_100 ) {
V_11 -> V_82 = V_86 ;
F_41 ( V_11 , V_6 ) ;
if ( V_96 != V_100 ) {
V_89 |= V_87 ;
V_96 = V_11 -> V_73 ;
}
}
F_51 ( & V_11 -> V_97 , V_53 ) ;
F_47 ( V_11 , V_89 ) ;
return V_107 ;
}
static int F_53 ( unsigned long V_33 )
{
struct V_10 * V_11 ;
F_54 (lp, &ldc_channel_list, list) {
if ( V_11 -> V_33 == V_33 )
return 1 ;
}
return 0 ;
}
static int F_55 ( const char * V_109 , unsigned long V_8 ,
struct V_14 * * V_110 , unsigned long * V_111 )
{
unsigned long V_25 , V_112 ;
void * V_113 ;
V_25 = V_8 * V_9 ;
V_112 = F_56 ( V_25 ) ;
V_113 = ( void * ) F_57 ( V_114 , V_112 ) ;
if ( ! V_113 ) {
F_28 (KERN_ERR PFX L_27
L_28 , name, size, order) ;
return - V_115 ;
}
memset ( V_113 , 0 , V_116 << V_112 ) ;
* V_110 = V_113 ;
* V_111 = F_58 ( V_113 ) ;
return 0 ;
}
static void F_59 ( unsigned long V_8 , struct V_14 * V_113 )
{
unsigned long V_25 , V_112 ;
if ( ! V_113 )
return;
V_25 = V_8 * V_9 ;
V_112 = F_56 ( V_25 ) ;
F_60 ( ( unsigned long ) V_113 , V_112 ) ;
}
static unsigned long F_61 ( T_5 V_117 , void * V_118 )
{
T_5 V_119 = V_117 >> V_120 ;
V_117 &= ~ V_121 ;
return ( V_117 >> ( 13ULL + ( V_119 * 3ULL ) ) ) ;
}
static void F_62 ( struct V_122 * V_123 , unsigned long V_33 , T_5 V_117 ,
unsigned long V_124 , unsigned long V_125 )
{
struct V_126 * V_110 ;
unsigned long V_79 , V_127 ;
V_127 = ( V_117 >> V_120 ) * 3 ;
V_110 = V_123 -> V_128 + V_124 ;
for ( V_79 = 0 ; V_79 < V_125 ; V_79 ++ ) {
if ( V_110 -> V_117 )
F_63 ( V_33 , V_117 + ( V_79 << V_127 ) ,
V_110 -> V_117 ) ;
V_110 -> V_129 = 0 ;
}
}
static int F_64 ( const char * V_109 , struct V_10 * V_11 )
{
unsigned long V_130 , V_131 , V_132 , V_112 ;
struct V_122 * V_122 = & V_11 -> V_123 ;
struct V_133 * V_123 = & V_122 -> V_133 ;
struct V_126 * V_134 ;
unsigned long V_70 ;
int V_32 ;
V_131 = V_135 ;
V_132 = V_131 * sizeof( struct V_126 ) ;
F_65 ( & V_122 -> V_97 ) ;
V_130 = V_131 / 8 ;
V_130 = ( V_130 + 7UL ) & ~ 7UL ;
V_123 -> V_136 = F_66 ( V_130 , V_114 ) ;
if ( ! V_123 -> V_136 ) {
F_28 (KERN_ERR PFX L_29 , sz) ;
return - V_115 ;
}
F_67 ( V_123 , V_131 , V_137 ,
NULL , false ,
1 ,
true ) ;
V_112 = F_56 ( V_132 ) ;
V_134 = (struct V_126 * )
F_57 ( V_114 , V_112 ) ;
V_32 = - V_115 ;
if ( ! V_134 ) {
F_28 (KERN_ERR PFX L_30
L_28 , tsbsize, order) ;
goto V_138;
}
memset ( V_134 , 0 , V_116 << V_112 ) ;
V_122 -> V_128 = V_134 ;
V_70 = F_68 ( V_11 -> V_33 , F_58 ( V_134 ) ,
V_131 ) ;
V_32 = - V_35 ;
if ( V_70 )
goto V_139;
return 0 ;
V_139:
F_60 ( ( unsigned long ) V_134 , V_112 ) ;
V_122 -> V_128 = NULL ;
V_138:
F_69 ( V_123 -> V_136 ) ;
V_123 -> V_136 = NULL ;
return V_32 ;
}
static void F_70 ( struct V_10 * V_11 )
{
struct V_122 * V_122 = & V_11 -> V_123 ;
struct V_133 * V_123 = & V_122 -> V_133 ;
unsigned long V_131 , V_132 , V_112 ;
( void ) F_68 ( V_11 -> V_33 , 0 , 0 ) ;
V_131 = V_123 -> V_140 * V_123 -> V_141 ;
V_132 = V_131 * sizeof( struct V_126 ) ;
V_112 = F_56 ( V_132 ) ;
F_60 ( ( unsigned long ) V_122 -> V_128 , V_112 ) ;
V_122 -> V_128 = NULL ;
F_69 ( V_123 -> V_136 ) ;
V_123 -> V_136 = NULL ;
}
struct V_10 * F_71 ( unsigned long V_33 ,
const struct V_142 * V_143 ,
void * V_92 ,
const char * V_109 )
{
struct V_10 * V_11 ;
const struct V_144 * V_145 ;
unsigned long V_146 , V_147 , V_70 ;
T_1 V_29 , * V_148 ;
int V_32 ;
V_32 = - V_149 ;
if ( ! V_150 )
goto V_151;
V_32 = - V_35 ;
if ( ! V_143 )
goto V_151;
if ( ! V_109 )
goto V_151;
switch ( V_143 -> V_22 ) {
case V_99 :
V_145 = & V_152 ;
V_29 = V_9 ;
break;
case V_153 :
V_145 = & V_154 ;
V_29 = V_9 - 8 ;
break;
case V_23 :
V_145 = & V_155 ;
V_29 = V_9 - 8 - 8 ;
break;
default:
goto V_151;
}
if ( ! V_143 -> V_91 || ! V_92 || ! V_143 -> V_156 || ! V_143 -> V_157 )
goto V_151;
V_70 = F_72 ( V_33 , & V_146 , & V_147 ) ;
V_32 = - V_149 ;
if ( V_70 == V_158 )
goto V_151;
V_32 = - V_159 ;
if ( F_53 ( V_33 ) )
goto V_151;
V_148 = NULL ;
V_11 = F_66 ( sizeof( * V_11 ) , V_114 ) ;
V_32 = - V_115 ;
if ( ! V_11 )
goto V_151;
F_65 ( & V_11 -> V_97 ) ;
V_11 -> V_33 = V_33 ;
V_32 = F_64 ( V_109 , V_11 ) ;
if ( V_32 )
goto V_160;
V_11 -> V_145 = V_145 ;
V_11 -> V_29 = V_29 ;
V_11 -> V_21 = * V_143 ;
if ( ! V_11 -> V_21 . V_161 )
V_11 -> V_21 . V_161 = V_162 ;
if ( V_11 -> V_21 . V_22 == V_23 ) {
V_148 = F_66 ( V_11 -> V_21 . V_161 , V_114 ) ;
if ( ! V_148 ) {
V_32 = - V_115 ;
goto V_163;
}
V_11 -> V_148 = V_148 ;
}
V_11 -> V_92 = V_92 ;
V_11 -> V_13 = V_164 ;
V_11 -> V_12 = V_164 ;
V_32 = F_55 ( L_31 , V_11 -> V_13 ,
& V_11 -> V_20 , & V_11 -> V_72 ) ;
if ( V_32 )
goto V_165;
V_32 = F_55 ( L_32 , V_11 -> V_12 ,
& V_11 -> V_104 , & V_11 -> V_74 ) ;
if ( V_32 )
goto V_166;
V_11 -> V_53 |= V_167 ;
V_11 -> V_82 = V_168 ;
F_41 ( V_11 , V_3 ) ;
F_73 ( & V_11 -> V_169 ) ;
F_74 ( & V_11 -> V_169 , & V_170 ) ;
F_75 ( & V_11 -> V_171 ) ;
snprintf ( V_11 -> V_172 , V_173 , L_33 , V_109 ) ;
snprintf ( V_11 -> V_174 , V_173 , L_34 , V_109 ) ;
V_32 = F_76 ( V_11 -> V_21 . V_156 , F_48 , 0 ,
V_11 -> V_172 , V_11 ) ;
if ( V_32 )
goto V_166;
V_32 = F_76 ( V_11 -> V_21 . V_157 , F_52 , 0 ,
V_11 -> V_174 , V_11 ) ;
if ( V_32 ) {
F_77 ( V_11 -> V_21 . V_156 , V_11 ) ;
goto V_166;
}
return V_11 ;
V_166:
F_59 ( V_11 -> V_13 , V_11 -> V_20 ) ;
V_165:
F_69 ( V_148 ) ;
V_163:
F_70 ( V_11 ) ;
V_160:
F_69 ( V_11 ) ;
V_151:
return F_78 ( V_32 ) ;
}
void F_79 ( struct V_10 * V_11 )
{
if ( V_11 -> V_53 & V_175 ) {
F_77 ( V_11 -> V_21 . V_156 , V_11 ) ;
F_77 ( V_11 -> V_21 . V_157 , V_11 ) ;
V_11 -> V_53 &= ~ V_175 ;
}
if ( V_11 -> V_53 & V_176 ) {
F_27 ( V_11 -> V_33 , 0 , 0 ) ;
F_30 ( V_11 -> V_33 , 0 , 0 ) ;
V_11 -> V_53 &= ~ V_176 ;
}
if ( V_11 -> V_53 & V_167 ) {
F_59 ( V_11 -> V_13 , V_11 -> V_20 ) ;
F_59 ( V_11 -> V_12 , V_11 -> V_104 ) ;
V_11 -> V_53 &= ~ V_167 ;
}
F_41 ( V_11 , V_3 ) ;
}
void F_80 ( struct V_10 * V_11 )
{
F_79 ( V_11 ) ;
F_81 ( & V_11 -> V_169 ) ;
F_69 ( V_11 -> V_148 ) ;
F_70 ( V_11 ) ;
F_69 ( V_11 ) ;
}
int F_82 ( struct V_10 * V_11 )
{
unsigned long V_70 , V_53 ;
int V_32 = - V_35 ;
if ( V_11 -> V_1 != V_3 )
return - V_35 ;
F_49 ( & V_11 -> V_97 , V_53 ) ;
F_83 ( V_11 -> V_21 . V_156 ) ;
F_83 ( V_11 -> V_21 . V_157 ) ;
V_11 -> V_53 |= V_175 ;
V_32 = - V_149 ;
V_70 = F_27 ( V_11 -> V_33 , 0 , 0 ) ;
if ( V_70 )
goto V_177;
V_70 = F_27 ( V_11 -> V_33 , V_11 -> V_72 , V_11 -> V_13 ) ;
if ( V_70 )
goto V_177;
V_70 = F_30 ( V_11 -> V_33 , 0 , 0 ) ;
if ( V_70 )
goto V_178;
V_70 = F_30 ( V_11 -> V_33 , V_11 -> V_74 , V_11 -> V_12 ) ;
if ( V_70 )
goto V_178;
V_11 -> V_53 |= V_176 ;
V_70 = F_29 ( V_11 -> V_33 ,
& V_11 -> V_19 ,
& V_11 -> V_18 ,
& V_11 -> V_73 ) ;
V_32 = - V_36 ;
if ( V_70 )
goto V_179;
V_11 -> V_24 = V_11 -> V_19 ;
V_11 -> V_82 = V_84 ;
F_41 ( V_11 , V_4 ) ;
if ( V_11 -> V_21 . V_22 == V_99 ) {
V_11 -> V_82 = V_86 ;
}
F_51 ( & V_11 -> V_97 , V_53 ) ;
return 0 ;
V_179:
V_11 -> V_53 &= ~ V_176 ;
F_30 ( V_11 -> V_33 , 0 , 0 ) ;
V_178:
F_27 ( V_11 -> V_33 , 0 , 0 ) ;
V_177:
V_11 -> V_53 &= ~ V_175 ;
F_77 ( V_11 -> V_21 . V_157 , V_11 ) ;
F_77 ( V_11 -> V_21 . V_156 , V_11 ) ;
F_51 ( & V_11 -> V_97 , V_53 ) ;
return V_32 ;
}
int F_84 ( struct V_10 * V_11 )
{
unsigned long V_53 ;
int V_32 ;
if ( V_11 -> V_21 . V_22 == V_99 )
return - V_35 ;
F_49 ( & V_11 -> V_97 , V_53 ) ;
if ( ! ( V_11 -> V_53 & V_167 ) ||
! ( V_11 -> V_53 & V_176 ) ||
V_11 -> V_82 != V_84 )
V_32 = ( ( V_11 -> V_82 > V_84 ) ? 0 : - V_35 ) ;
else
V_32 = F_17 ( V_11 ) ;
F_51 ( & V_11 -> V_97 , V_53 ) ;
return V_32 ;
}
int F_85 ( struct V_10 * V_11 )
{
unsigned long V_70 , V_53 ;
int V_32 ;
if ( V_11 -> V_21 . V_22 == V_99 )
return - V_35 ;
if ( ! ( V_11 -> V_53 & V_167 ) ||
! ( V_11 -> V_53 & V_176 ) )
return - V_35 ;
F_49 ( & V_11 -> V_97 , V_53 ) ;
V_32 = - V_149 ;
V_70 = F_27 ( V_11 -> V_33 , 0 , 0 ) ;
if ( V_70 )
goto V_151;
V_70 = F_27 ( V_11 -> V_33 , V_11 -> V_72 , V_11 -> V_13 ) ;
if ( V_70 )
goto V_151;
V_70 = F_30 ( V_11 -> V_33 , 0 , 0 ) ;
if ( V_70 )
goto V_151;
V_70 = F_30 ( V_11 -> V_33 , V_11 -> V_74 , V_11 -> V_12 ) ;
if ( V_70 )
goto V_151;
F_41 ( V_11 , V_4 ) ;
V_11 -> V_82 = V_84 ;
V_11 -> V_53 |= V_54 ;
F_51 ( & V_11 -> V_97 , V_53 ) ;
return 0 ;
V_151:
F_27 ( V_11 -> V_33 , 0 , 0 ) ;
F_30 ( V_11 -> V_33 , 0 , 0 ) ;
F_77 ( V_11 -> V_21 . V_157 , V_11 ) ;
F_77 ( V_11 -> V_21 . V_156 , V_11 ) ;
V_11 -> V_53 &= ~ ( V_175 |
V_176 ) ;
F_41 ( V_11 , V_3 ) ;
F_51 ( & V_11 -> V_97 , V_53 ) ;
return V_32 ;
}
int F_86 ( struct V_10 * V_11 )
{
return V_11 -> V_1 ;
}
void F_41 ( struct V_10 * V_11 , T_1 V_1 )
{
F_18 ( V_71 , L_35 ,
F_1 ( V_11 -> V_1 ) ,
F_1 ( V_1 ) ) ;
V_11 -> V_1 = V_1 ;
}
int F_87 ( struct V_10 * V_11 )
{
return V_11 -> V_21 . V_22 ;
}
int F_50 ( struct V_10 * V_11 )
{
return F_12 ( V_11 , V_11 -> V_76 ) ;
}
void F_88 ( struct V_10 * V_11 , const char * V_180 )
{
F_89 ( L_36
L_37
L_38
L_39 ,
V_180 , V_11 -> V_33 , V_11 -> V_53 , F_1 ( V_11 -> V_1 ) ,
V_11 -> V_73 , V_11 -> V_82 ,
V_11 -> V_75 , V_11 -> V_76 , V_11 -> V_12 ,
V_11 -> V_19 , V_11 -> V_18 , V_11 -> V_13 ,
V_11 -> V_61 , V_11 -> V_64 ) ;
}
static int F_90 ( struct V_10 * V_11 , const void * V_181 , unsigned int V_25 )
{
struct V_14 * V_16 ;
unsigned long V_15 , V_70 ;
int V_32 ;
V_70 = F_29 ( V_11 -> V_33 , & V_11 -> V_19 , & V_11 -> V_18 ,
& V_11 -> V_73 ) ;
if ( F_91 ( V_70 ) )
return - V_36 ;
if ( F_91 ( V_11 -> V_73 != V_100 ) )
return F_35 ( V_11 ) ;
if ( V_25 > V_9 )
return - V_182 ;
V_16 = F_8 ( V_11 , & V_15 ) ;
if ( ! V_16 )
return - V_183 ;
memcpy ( V_16 , V_181 , V_25 ) ;
V_32 = F_14 ( V_11 , V_16 , V_15 ) ;
if ( ! V_32 )
V_32 = V_25 ;
return V_32 ;
}
static int F_92 ( struct V_10 * V_11 , void * V_181 , unsigned int V_25 )
{
struct V_14 * V_16 ;
unsigned long V_70 , V_103 ;
int V_32 ;
if ( V_25 < V_9 )
return - V_35 ;
V_70 = F_31 ( V_11 -> V_33 ,
& V_11 -> V_75 ,
& V_11 -> V_76 ,
& V_11 -> V_73 ) ;
if ( V_70 )
return F_35 ( V_11 ) ;
if ( V_11 -> V_73 == V_184 ||
V_11 -> V_73 == V_185 )
return - V_77 ;
if ( V_11 -> V_75 == V_11 -> V_76 )
return 0 ;
V_16 = V_11 -> V_104 + ( V_11 -> V_75 / V_9 ) ;
memcpy ( V_181 , V_16 , V_9 ) ;
V_103 = F_3 ( V_11 , V_11 -> V_75 ) ;
V_11 -> V_75 = V_103 ;
V_32 = F_12 ( V_11 , V_103 ) ;
if ( V_32 < 0 )
V_32 = - V_77 ;
else
V_32 = V_9 ;
return V_32 ;
}
static int F_93 ( struct V_10 * V_11 , const void * V_181 ,
unsigned int V_25 )
{
unsigned long V_70 , V_27 ;
unsigned int V_186 ;
T_3 V_187 ;
int V_32 ;
V_70 = F_29 ( V_11 -> V_33 , & V_11 -> V_19 , & V_11 -> V_18 ,
& V_11 -> V_73 ) ;
if ( F_91 ( V_70 ) )
return - V_36 ;
if ( F_91 ( V_11 -> V_73 != V_100 ) )
return F_35 ( V_11 ) ;
if ( ! F_7 ( V_11 , V_25 ) )
return - V_183 ;
V_187 = V_11 -> V_64 ;
V_186 = 0 ;
V_27 = V_11 -> V_18 ;
while ( V_186 < V_25 ) {
struct V_14 * V_16 = V_11 -> V_20 + ( V_27 / V_9 ) ;
T_1 * V_40 = ( ( V_11 -> V_21 . V_22 == V_153 ) ?
V_16 -> V_43 . V_44 :
V_16 -> V_43 . V_65 . V_188 ) ;
int V_189 ;
V_16 -> type = V_105 ;
V_16 -> V_38 = V_51 ;
V_16 -> V_39 = 0 ;
V_189 = V_25 - V_186 ;
if ( V_189 > V_11 -> V_29 )
V_189 = V_11 -> V_29 ;
F_15 ( V_189 > V_190 ) ;
V_16 -> V_59 = ( V_189 |
( V_186 == 0 ? V_191 : 0 ) |
( V_189 == V_25 - V_186 ? V_192 : 0 ) ) ;
V_16 -> V_60 = ++ V_187 ;
F_18 ( V_193 , L_40 ,
V_16 -> type ,
V_16 -> V_38 ,
V_16 -> V_39 ,
V_16 -> V_59 ,
V_16 -> V_60 ) ;
memcpy ( V_40 , V_181 , V_189 ) ;
V_181 += V_189 ;
V_186 += V_189 ;
V_27 = F_4 ( V_11 , V_27 ) ;
}
V_32 = F_9 ( V_11 , V_27 ) ;
if ( ! V_32 ) {
V_11 -> V_64 = V_187 ;
V_32 = V_25 ;
}
return V_32 ;
}
static int F_94 ( struct V_10 * V_11 , struct V_14 * V_16 ,
struct V_14 * V_194 )
{
int V_32 ;
if ( V_194 )
V_11 -> V_61 = V_194 -> V_60 - 1 ;
V_32 = F_24 ( V_11 , V_16 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_50 ( V_11 ) ;
if ( V_32 < 0 )
return F_35 ( V_11 ) ;
return 0 ;
}
static int F_95 ( struct V_10 * V_11 , struct V_14 * V_16 )
{
if ( V_16 -> V_38 & V_57 ) {
int V_32 = F_46 ( V_11 , V_16 ) ;
if ( V_32 )
return V_32 ;
}
if ( V_16 -> V_38 & V_55 )
return F_35 ( V_11 ) ;
return 0 ;
}
static int F_96 ( struct V_10 * V_11 , unsigned long V_195 )
{
unsigned long V_196 ;
int V_26 = 1000 ;
F_18 ( V_193 , L_41 ,
V_195 , V_11 -> V_75 , V_11 -> V_76 ) ;
while ( V_26 -- > 0 ) {
unsigned long V_70 ;
V_70 = F_31 ( V_11 -> V_33 ,
& V_196 ,
& V_11 -> V_76 ,
& V_11 -> V_73 ) ;
if ( V_70 )
return F_35 ( V_11 ) ;
if ( V_11 -> V_73 == V_184 ||
V_11 -> V_73 == V_185 )
return - V_77 ;
if ( V_195 != V_11 -> V_76 ) {
F_18 ( V_193 , L_42
L_43 ,
V_196 , V_11 -> V_76 , V_11 -> V_73 ) ;
return 0 ;
}
F_11 ( 1 ) ;
}
return - V_183 ;
}
static int F_97 ( struct V_10 * V_11 , unsigned long V_37 )
{
int V_32 = F_12 ( V_11 , V_37 ) ;
if ( V_32 < 0 )
return F_35 ( V_11 ) ;
V_11 -> V_75 = V_37 ;
return 0 ;
}
static void F_98 ( struct V_10 * V_11 )
{
unsigned long V_15 ;
struct V_14 * V_16 ;
V_16 = F_8 ( V_11 , & V_15 ) ;
if ( F_99 ( V_16 ) ) {
int V_32 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> type = V_105 ;
V_16 -> V_38 = V_57 ;
V_16 -> V_39 = 0 ;
V_16 -> V_60 = V_11 -> V_64 + 1 ;
V_16 -> V_43 . V_65 . V_66 = V_11 -> V_61 ;
V_32 = F_14 ( V_11 , V_16 , V_15 ) ;
if ( ! V_32 )
V_11 -> V_64 ++ ;
}
}
static int F_100 ( struct V_10 * V_11 , void * V_181 , unsigned int V_25 )
{
struct V_14 * V_194 ;
unsigned long V_70 , V_103 ;
int V_32 , V_186 ;
V_70 = F_31 ( V_11 -> V_33 ,
& V_11 -> V_75 ,
& V_11 -> V_76 ,
& V_11 -> V_73 ) ;
if ( V_70 )
return F_35 ( V_11 ) ;
if ( V_11 -> V_73 == V_184 ||
V_11 -> V_73 == V_185 )
return - V_77 ;
if ( V_11 -> V_75 == V_11 -> V_76 )
return 0 ;
V_194 = NULL ;
V_186 = V_32 = 0 ;
V_103 = V_11 -> V_75 ;
while ( 1 ) {
struct V_14 * V_16 ;
int V_197 ;
F_15 ( V_103 == V_11 -> V_76 ) ;
V_16 = V_11 -> V_104 + ( V_103 / V_9 ) ;
F_18 ( V_98 , L_44
L_45 ,
V_16 -> type ,
V_16 -> V_38 ,
V_16 -> V_39 ,
V_16 -> V_59 ,
V_16 -> V_60 ,
V_16 -> V_43 . V_65 . V_66 ,
V_11 -> V_61 ) ;
if ( F_91 ( ! F_42 ( V_11 , V_16 -> V_60 ) ) ) {
V_32 = F_94 ( V_11 , V_16 , V_194 ) ;
V_186 = 0 ;
break;
}
if ( V_16 -> type & V_42 ) {
V_32 = F_44 ( V_11 , V_16 ) ;
if ( V_32 < 0 )
break;
V_32 = 0 ;
}
V_11 -> V_61 = V_16 -> V_60 ;
if ( ! ( V_16 -> type & V_105 ) ) {
V_103 = F_3 ( V_11 , V_103 ) ;
break;
}
if ( V_16 -> V_38 & ( V_57 | V_55 ) ) {
V_32 = F_95 ( V_11 , V_16 ) ;
if ( V_32 )
break;
}
if ( ! ( V_16 -> V_38 & V_51 ) ) {
V_103 = F_3 ( V_11 , V_103 ) ;
V_32 = F_97 ( V_11 , V_103 ) ;
if ( V_32 )
break;
goto V_198;
}
V_197 = V_16 -> V_59 & V_190 ;
if ( ( V_194 == NULL && ! ( V_16 -> V_59 & V_191 ) ) ||
( V_194 != NULL && ( V_16 -> V_59 & V_191 ) ) ) {
if ( ! V_194 )
V_103 = F_3 ( V_11 , V_103 ) ;
V_32 = F_97 ( V_11 , V_103 ) ;
if ( V_32 )
break;
if ( ! V_194 )
goto V_198;
}
if ( ! V_194 )
V_194 = V_16 ;
if ( V_197 > V_25 - V_186 ) {
V_32 = - V_182 ;
break;
}
V_103 = F_3 ( V_11 , V_103 ) ;
memcpy ( V_181 ,
( V_11 -> V_21 . V_22 == V_153 ?
V_16 -> V_43 . V_44 : V_16 -> V_43 . V_65 . V_188 ) , V_197 ) ;
V_181 += V_197 ;
V_186 += V_197 ;
if ( V_16 -> V_59 & V_192 )
break;
V_198:
if ( V_103 == V_11 -> V_76 ) {
V_32 = F_96 ( V_11 , V_103 ) ;
if ( V_32 )
break;
}
}
if ( ! V_32 )
V_32 = F_97 ( V_11 , V_103 ) ;
if ( V_32 && V_194 )
V_11 -> V_61 = V_194 -> V_60 - 1 ;
if ( ! V_32 ) {
V_32 = V_186 ;
if ( V_32 > 0 && V_11 -> V_21 . V_22 != V_153 )
F_98 ( V_11 ) ;
}
return V_32 ;
}
static int F_101 ( struct V_10 * V_11 , const void * V_181 ,
unsigned int V_25 )
{
if ( V_25 > V_11 -> V_21 . V_161 )
V_25 = V_11 -> V_21 . V_161 ;
return F_93 ( V_11 , V_181 , V_25 ) ;
}
static int F_102 ( struct V_10 * V_11 , void * V_181 , unsigned int V_25 )
{
if ( ! V_11 -> V_199 ) {
int V_32 = F_100 ( V_11 , V_11 -> V_148 , V_11 -> V_21 . V_161 ) ;
if ( V_32 < 0 )
return V_32 ;
V_11 -> V_199 = V_32 ;
V_11 -> V_200 = 0 ;
}
if ( V_25 > V_11 -> V_199 )
V_25 = V_11 -> V_199 ;
memcpy ( V_181 , V_11 -> V_148 + V_11 -> V_200 , V_25 ) ;
V_11 -> V_200 += V_25 ;
V_11 -> V_199 -= V_25 ;
return V_25 ;
}
int F_103 ( struct V_10 * V_11 , const void * V_181 , unsigned int V_25 )
{
unsigned long V_53 ;
int V_32 ;
if ( ! V_181 )
return - V_35 ;
if ( ! V_25 )
return 0 ;
F_49 ( & V_11 -> V_97 , V_53 ) ;
if ( V_11 -> V_82 != V_86 )
V_32 = - V_201 ;
else
V_32 = V_11 -> V_145 -> V_202 ( V_11 , V_181 , V_25 ) ;
F_51 ( & V_11 -> V_97 , V_53 ) ;
return V_32 ;
}
int F_104 ( struct V_10 * V_11 , void * V_181 , unsigned int V_25 )
{
unsigned long V_53 ;
int V_32 ;
F_18 ( V_98 , L_46 , V_203 , V_25 ) ;
if ( ! V_181 )
return - V_35 ;
if ( ! V_25 )
return 0 ;
F_49 ( & V_11 -> V_97 , V_53 ) ;
if ( V_11 -> V_82 != V_86 )
V_32 = - V_201 ;
else
V_32 = V_11 -> V_145 -> V_204 ( V_11 , V_181 , V_25 ) ;
F_51 ( & V_11 -> V_97 , V_53 ) ;
F_18 ( V_98 , L_47 , V_203 ,
V_11 -> V_21 . V_22 , V_11 -> V_75 , V_11 -> V_76 , V_32 ) ;
return V_32 ;
}
static T_5 F_105 ( void )
{
switch ( V_116 ) {
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
static T_5 F_106 ( T_5 V_205 , T_5 V_206 , T_5 V_207 )
{
return ( ( V_206 << V_120 ) |
( V_205 << V_137 ) |
V_207 ) ;
}
static struct V_126 * F_107 ( struct V_122 * V_123 ,
unsigned long V_125 )
{
long V_124 ;
V_124 = F_108 ( NULL , & V_123 -> V_133 ,
V_125 , NULL , ( unsigned long ) - 1 , 0 ) ;
if ( F_91 ( V_124 == V_208 ) )
return NULL ;
return V_123 -> V_128 + V_124 ;
}
static T_5 F_109 ( unsigned int V_209 )
{
T_5 V_210 ;
V_210 = F_105 () ;
if ( V_209 & V_211 ) {
if ( V_209 & V_212 )
V_210 |= V_213 ;
if ( V_209 & V_214 )
V_210 |= V_215 ;
}
if ( V_209 & V_216 ) {
if ( V_209 & V_212 )
V_210 |= V_217 ;
if ( V_209 & V_214 )
V_210 |= V_218 ;
if ( V_209 & V_219 )
V_210 |= V_220 ;
}
if ( V_209 & V_221 ) {
if ( V_209 & V_212 )
V_210 |= V_222 ;
if ( V_209 & V_214 )
V_210 |= V_223 ;
}
return V_210 ;
}
static int F_110 ( unsigned long V_110 , long V_224 )
{
int V_225 = 0 ;
do {
unsigned long V_103 = ( V_110 + V_116 ) & V_226 ;
V_224 -= ( V_103 - V_110 ) ;
V_110 = V_103 ;
V_225 ++ ;
} while ( V_224 > 0 );
return V_225 ;
}
static void F_111 ( struct V_227 * V_228 , unsigned long V_229 ,
unsigned long V_7 , unsigned long V_224 )
{
do {
unsigned long V_230 , V_103 = V_229 + V_116 ;
T_5 V_231 ;
V_228 -> V_128 [ V_228 -> V_232 ] . V_129 = V_228 -> V_210 | V_229 ;
V_230 = V_116 ;
if ( V_7 )
V_230 = V_116 - V_7 ;
if ( V_230 > V_224 )
V_230 = V_224 ;
V_231 = F_106 ( V_228 -> V_232 ,
F_105 () , V_7 ) ;
V_7 = 0 ;
if ( V_231 == V_228 -> V_233 ) {
V_228 -> V_234 [ V_228 -> V_235 - 1 ] . V_236 += V_230 ;
} else {
V_228 -> V_234 [ V_228 -> V_235 ] . V_237 = V_231 ;
V_228 -> V_234 [ V_228 -> V_235 ] . V_236 = V_230 ;
V_228 -> V_235 ++ ;
}
V_228 -> V_233 = V_231 + V_230 ;
V_228 -> V_232 ++ ;
V_224 -= V_230 ;
V_229 = V_103 ;
} while ( V_224 > 0 );
}
static int F_112 ( struct V_238 * V_239 )
{
unsigned long V_110 = F_113 ( F_114 ( V_239 ) ) << V_137 ;
long V_224 = V_239 -> V_240 ;
if ( ( V_239 -> V_241 | V_224 ) & ( 8UL - 1 ) )
return - V_242 ;
return F_110 ( V_110 + V_239 -> V_241 , V_224 ) ;
}
static int F_115 ( struct V_238 * V_239 , int V_243 )
{
int V_225 ;
int V_79 ;
V_225 = 0 ;
for ( V_79 = 0 ; V_79 < V_243 ; V_79 ++ ) {
int V_32 = F_112 ( V_239 + V_79 ) ;
if ( V_32 < 0 )
return V_32 ;
V_225 += V_32 ;
}
return V_225 ;
}
int F_116 ( struct V_10 * V_11 ,
struct V_238 * V_239 , int V_243 ,
struct V_244 * V_234 , int V_245 ,
unsigned int V_209 )
{
unsigned long V_79 , V_125 ;
struct V_126 * V_110 ;
struct V_227 V_1 ;
struct V_122 * V_123 ;
int V_32 ;
struct V_238 * V_246 ;
if ( V_209 & ~ V_247 )
return - V_35 ;
V_32 = F_115 ( V_239 , V_243 ) ;
if ( V_32 < 0 )
return V_32 ;
V_125 = V_32 ;
if ( V_32 > V_245 )
return - V_182 ;
V_123 = & V_11 -> V_123 ;
V_110 = F_107 ( V_123 , V_125 ) ;
if ( ! V_110 )
return - V_115 ;
V_1 . V_128 = V_123 -> V_128 ;
V_1 . V_234 = V_234 ;
V_1 . V_210 = F_109 ( V_209 ) ;
V_1 . V_233 = ~ ( T_5 ) 0 ;
V_1 . V_232 = ( V_110 - V_123 -> V_128 ) ;
V_1 . V_235 = 0 ;
F_117 (sg, s, num_sg, i) {
F_111 ( & V_1 , F_113 ( F_114 ( V_246 ) ) << V_137 ,
V_246 -> V_241 , V_246 -> V_240 ) ;
}
return V_1 . V_235 ;
}
int F_118 ( struct V_10 * V_11 ,
void * V_181 , unsigned int V_224 ,
struct V_244 * V_234 , int V_245 ,
unsigned int V_209 )
{
unsigned long V_125 , V_229 ;
struct V_126 * V_110 ;
struct V_227 V_1 ;
struct V_122 * V_123 ;
if ( ( V_209 & ~ V_247 ) || ( V_245 < 1 ) )
return - V_35 ;
V_229 = F_58 ( V_181 ) ;
if ( ( V_229 | V_224 ) & ( 8UL - 1 ) )
return - V_242 ;
V_125 = F_110 ( V_229 , V_224 ) ;
V_123 = & V_11 -> V_123 ;
V_110 = F_107 ( V_123 , V_125 ) ;
if ( ! V_110 )
return - V_115 ;
V_1 . V_128 = V_123 -> V_128 ;
V_1 . V_234 = V_234 ;
V_1 . V_210 = F_109 ( V_209 ) ;
V_1 . V_233 = ~ ( T_5 ) 0 ;
V_1 . V_232 = ( V_110 - V_123 -> V_128 ) ;
V_1 . V_235 = 0 ;
F_111 ( & V_1 , ( V_229 & V_226 ) , ( V_229 & ~ V_226 ) , V_224 ) ;
F_15 ( V_1 . V_235 > V_245 ) ;
return V_1 . V_235 ;
}
static void F_119 ( unsigned long V_33 , struct V_122 * V_123 ,
T_5 V_117 , T_5 V_25 )
{
unsigned long V_125 , V_124 ;
V_125 = F_120 ( ( ( V_117 & ~ V_226 ) + V_25 ) ) >> V_137 ;
V_124 = F_61 ( V_117 , V_123 ) ;
F_62 ( V_123 , V_33 , V_117 , V_124 , V_125 ) ;
F_121 ( & V_123 -> V_133 , V_117 , V_125 , V_124 ) ;
}
void F_122 ( struct V_10 * V_11 , struct V_244 * V_234 ,
int V_245 )
{
struct V_122 * V_123 = & V_11 -> V_123 ;
int V_79 ;
unsigned long V_53 ;
F_49 ( & V_123 -> V_97 , V_53 ) ;
for ( V_79 = 0 ; V_79 < V_245 ; V_79 ++ ) {
T_5 V_248 = V_234 [ V_79 ] . V_237 ;
T_5 V_25 = V_234 [ V_79 ] . V_236 ;
F_119 ( V_11 -> V_33 , V_123 , V_248 , V_25 ) ;
}
F_51 ( & V_123 -> V_97 , V_53 ) ;
}
int F_123 ( struct V_10 * V_11 , int V_249 ,
void * V_181 , unsigned int V_224 , unsigned long V_241 ,
struct V_244 * V_234 , int V_245 )
{
unsigned int V_250 ;
unsigned long V_111 ;
int V_79 ;
if ( V_249 != V_251 && V_249 != V_252 ) {
F_28 (KERN_ERR PFX L_48 ,
lp->id, copy_dir) ;
return - V_35 ;
}
V_111 = F_58 ( V_181 ) ;
if ( ( V_111 | V_224 | V_241 ) & ( 8UL - 1 ) ) {
F_28 (KERN_ERR PFX L_49
L_50 ,
lp->id, ra, len, offset) ;
return - V_242 ;
}
if ( V_11 -> V_82 != V_86 ||
( V_11 -> V_53 & V_54 ) ) {
F_28 (KERN_ERR PFX L_51
L_52 , lp->id, lp->hs_state, lp->flags) ;
return - V_77 ;
}
V_250 = V_224 ;
for ( V_79 = 0 ; V_79 < V_245 ; V_79 ++ ) {
unsigned long V_253 = V_234 [ V_79 ] . V_237 ;
unsigned long V_254 = V_234 [ V_79 ] . V_236 ;
unsigned long V_255 ;
if ( F_91 ( V_241 ) ) {
unsigned long V_256 = V_241 ;
if ( V_256 > V_254 )
V_256 = V_254 ;
V_241 -= V_256 ;
V_254 -= V_256 ;
if ( ! V_254 )
continue;
V_253 += V_256 ;
}
if ( V_254 > V_224 )
V_254 = V_224 ;
while ( 1 ) {
unsigned long V_70 ;
V_70 = F_124 ( V_11 -> V_33 , V_249 ,
V_253 , V_111 ,
V_254 , & V_255 ) ;
if ( F_91 ( V_70 ) ) {
F_28 (KERN_ERR PFX L_53
L_54 ,
lp->id, hv_err) ;
if ( V_11 -> V_82 != V_86 ||
( V_11 -> V_53 & V_54 ) )
return - V_77 ;
else
return - V_242 ;
}
V_253 += V_255 ;
V_111 += V_255 ;
V_224 -= V_255 ;
if ( V_255 == V_254 )
break;
V_254 -= V_255 ;
}
if ( ! V_224 )
break;
}
return V_250 - V_224 ;
}
void * F_125 ( struct V_10 * V_11 , unsigned int V_224 ,
struct V_244 * V_234 , int * V_245 ,
unsigned int V_209 )
{
void * V_181 ;
int V_32 ;
if ( V_224 & ( 8UL - 1 ) )
return F_78 ( - V_35 ) ;
V_181 = F_66 ( V_224 , V_257 ) ;
if ( ! V_181 )
return F_78 ( - V_115 ) ;
V_32 = F_118 ( V_11 , V_181 , V_224 , V_234 , * V_245 , V_209 ) ;
if ( V_32 < 0 ) {
F_69 ( V_181 ) ;
return F_78 ( V_32 ) ;
}
* V_245 = V_32 ;
return V_181 ;
}
void F_126 ( struct V_10 * V_11 , void * V_181 , unsigned int V_224 ,
struct V_244 * V_234 , int V_245 )
{
F_122 ( V_11 , V_234 , V_245 ) ;
F_69 ( V_181 ) ;
}
static int T_6 F_127 ( void )
{
unsigned long V_49 , V_50 ;
struct V_258 * V_259 ;
const T_5 * V_80 ;
int V_32 ;
T_5 V_260 ;
V_259 = F_128 () ;
if ( ! V_259 )
return - V_149 ;
V_260 = F_129 ( V_259 , V_261 , L_55 ) ;
V_32 = - V_149 ;
if ( V_260 == V_261 )
goto V_101;
V_80 = F_130 ( V_259 , V_260 , L_56 , NULL ) ;
if ( ! V_80 )
goto V_101;
V_49 = 1 ;
V_50 = 0 ;
if ( F_131 ( V_262 , V_49 , & V_50 ) ) {
F_28 (KERN_INFO PFX L_57 ) ;
goto V_101;
}
F_28 ( V_263 L_58 , V_264 ) ;
if ( ! * V_80 ) {
F_28 (KERN_INFO PFX L_59 ) ;
goto V_101;
}
V_150 = 1 ;
V_32 = 0 ;
V_101:
F_132 ( V_259 ) ;
return V_32 ;
}
