static inline T_1 F_1 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 . V_4 , V_2 ) ;
V_1 = F_3 ( V_3 . V_5 ) ;
if ( ! ( V_1 & V_6 ) )
V_3 . V_7 = 0 ;
F_4 ( & V_3 . V_4 , V_2 ) ;
return V_1 ;
}
static inline T_1 F_5 ( void )
{
return F_3 ( V_3 . V_8 ) ;
}
static inline void F_6 ( T_1 V_9 )
{
unsigned long V_2 ;
F_2 ( & V_3 . V_4 , V_2 ) ;
V_3 . V_7 = 1 ;
if ( ( V_9 & 0xf0 ) == 0xe0 )
V_3 . V_10 = 0xff ;
F_7 ( V_9 , V_3 . V_5 ) ;
F_4 ( & V_3 . V_4 , V_2 ) ;
}
static inline void F_8 ( T_1 V_9 )
{
unsigned long V_2 ;
F_2 ( & V_3 . V_4 , V_2 ) ;
V_3 . V_7 = 1 ;
F_7 ( V_9 , V_3 . V_8 ) ;
F_4 ( & V_3 . V_4 , V_2 ) ;
}
static inline void F_9 ( void )
{
unsigned long V_2 ;
T_2 * V_11 ;
V_11 = & V_3 . V_4 ;
F_10 ( V_11 , V_2 ) ;
if ( ! V_3 . V_7 ) {
F_11 ( V_11 , V_2 ) ;
return;
}
F_12 ( V_11 ) ;
F_13 ( V_11 ) ;
while ( F_3 ( V_3 . V_5 ) & V_6 )
{ }
V_3 . V_7 = 0 ;
F_4 ( V_11 , V_2 ) ;
}
static void F_14 ( int V_12 , void * V_13 , T_1 V_1 , T_1 V_14 )
{
T_3 * V_15 ;
F_15 ( & V_3 . V_16 ) ;
if ( V_3 . V_17 < 0 ) {
F_12 ( & V_3 . V_16 ) ;
return;
}
V_15 = V_3 . V_18 [ V_3 . V_17 ] ;
F_12 ( & V_3 . V_16 ) ;
V_15 -> V_19 [ V_15 -> V_20 ++ ] = V_1 ;
V_15 -> V_19 [ V_15 -> V_20 ++ ] = V_14 ;
V_3 . V_21 -= 2 ;
F_16 ( & V_3 . V_22 ) ;
if ( V_3 . V_21 <= 0 ) {
if ( V_15 -> V_19 [ V_15 -> V_23 ] & V_24 )
if ( V_15 -> V_25 . V_26 )
F_17 ( V_15 -> V_25 . V_26 ) ;
if ( V_15 -> V_19 [ V_15 -> V_23 ] & V_27 )
if ( V_15 -> V_25 . V_28 )
V_15 -> V_25 . V_28 ( V_12 , V_13 , V_1 , V_14 ) ;
V_15 -> V_23 = V_15 -> V_20 ;
V_15 -> V_20 ++ ;
F_13 ( & V_3 . V_16 ) ;
V_3 . V_17 = - 1 ;
V_3 . V_21 = 0 ;
F_18 ( & V_3 . V_16 ) ;
F_19 ( & V_3 . V_29 ) ;
}
}
static T_4 F_20 ( int V_12 , void * V_13 )
{
T_1 V_1 , V_14 ;
V_1 = F_1 () ;
V_14 = F_5 () ;
if ( ( ( V_1 & 0xf1 ) == 0x51 ) && V_14 == 0x82 )
return V_30 ;
switch ( V_1 & V_31 ) {
case 0 :
break;
case V_32 :
case V_33 :
case V_34 :
F_15 ( & V_3 . V_35 ) ;
if ( V_3 . V_36 != NULL )
V_3 . V_36 ( V_12 , V_13 , V_1 , V_14 ) ;
F_12 ( & V_3 . V_35 ) ;
break;
case V_37 :
F_14 ( V_12 , V_13 , V_1 , V_14 ) ;
break;
case V_38 :
case V_39 :
F_15 ( & V_3 . V_35 ) ;
if ( V_3 . V_40 != NULL )
V_3 . V_40 ( V_12 , V_13 , V_1 , V_14 ) ;
F_12 ( & V_3 . V_35 ) ;
break;
case V_41 :
F_15 ( & V_3 . V_35 ) ;
if ( V_3 . V_42 != NULL )
V_3 . V_42 ( V_12 , V_13 , V_1 , V_14 ) ;
else
F_21 (KERN_INFO PREFIX L_1 ) ;
F_12 ( & V_3 . V_35 ) ;
break;
default:
F_15 ( & V_3 . V_35 ) ;
if ( V_3 . V_43 != NULL )
V_3 . V_43 ( V_12 , V_13 , V_1 , V_14 ) ;
F_12 ( & V_3 . V_35 ) ;
break;
}
return V_30 ;
}
static T_4 F_22 ( int V_12 , void * V_13 )
{
int V_1 ;
V_1 = F_1 () ;
F_21 (KERN_WARNING PREFIX L_2 ) ;
#if 0
if (status & HP_SDC_NMISTATUS_FHS) {
read_lock(&hp_sdc.hook_lock);
if (hp_sdc.timer != NULL)
hp_sdc.timer(irq, dev_id, status, 0);
read_unlock(&hp_sdc.hook_lock);
} else {
printk(KERN_WARNING PREFIX "HIL NMI\n");
}
#endif
return V_30 ;
}
static void F_23 ( unsigned long V_44 )
{
F_24 ( & V_3 . V_16 ) ;
if ( V_3 . V_17 >= 0 ) {
struct V_45 V_46 ;
F_16 ( & V_46 ) ;
if ( V_46 . V_47 > V_3 . V_22 . V_47 )
V_46 . V_48 += V_49 ;
if ( V_46 . V_48 - V_3 . V_22 . V_48 > V_50 ) {
T_3 * V_15 ;
T_1 V_51 ;
V_15 = V_3 . V_18 [ V_3 . V_17 ] ;
F_21 (KERN_WARNING PREFIX L_3 ,
(int)(tv.tv_usec - hp_sdc.rtv.tv_usec)) ;
V_15 -> V_20 += V_3 . V_21 ;
V_3 . V_21 = 0 ;
V_51 = V_15 -> V_19 [ V_15 -> V_23 ] ;
V_15 -> V_19 [ V_15 -> V_23 ] |= V_52 ;
if ( V_51 & V_24 )
if ( V_15 -> V_25 . V_26 )
F_17 ( V_15 -> V_25 . V_26 ) ;
if ( V_51 & V_27 ) {
if ( V_15 -> V_25 . V_28 )
V_15 -> V_25 . V_28 ( 0 , NULL , 0 , 0 ) ;
}
V_15 -> V_23 = V_15 -> V_20 ;
V_15 -> V_20 ++ ;
V_3 . V_17 = - 1 ;
}
}
F_25 ( & V_3 . V_16 ) ;
F_26 () ;
}
unsigned long F_26 ( void )
{
T_3 * V_15 ;
T_1 V_25 ;
int V_20 , V_53 ;
int V_54 = 0 ;
F_13 ( & V_3 . V_11 ) ;
if ( V_3 . V_7 ) {
F_1 () ;
if ( V_3 . V_7 )
goto V_55;
}
V_56:
if ( V_3 . V_57 < 0 )
V_3 . V_57 = 0 ;
F_27 ( & V_3 . V_16 ) ;
if ( V_3 . V_17 == V_3 . V_57 )
V_3 . V_57 ++ ;
F_28 ( & V_3 . V_16 ) ;
if ( V_3 . V_57 >= V_58 )
V_3 . V_57 = 0 ;
V_53 = V_3 . V_57 ;
if ( V_3 . V_18 [ V_53 ] != NULL )
goto V_59;
while ( ++ V_53 != V_3 . V_57 ) {
if ( V_53 >= V_58 ) {
V_53 = - 1 ;
continue;
}
F_27 ( & V_3 . V_16 ) ;
if ( V_3 . V_17 == V_53 ) {
F_28 ( & V_3 . V_16 ) ;
continue;
}
F_28 ( & V_3 . V_16 ) ;
if ( V_3 . V_18 [ V_53 ] != NULL )
break;
}
if ( V_53 == V_3 . V_57 ) {
V_53 = - 1 ;
}
V_3 . V_57 = V_53 ;
V_59:
if ( V_3 . V_60 ) {
F_6 ( V_3 . V_61 | V_62 ) ;
V_3 . V_60 = 0 ;
goto V_55;
}
if ( V_3 . V_57 == - 1 )
goto V_63;
V_15 = V_3 . V_18 [ V_53 ] ;
V_20 = V_15 -> V_23 ;
if ( V_15 -> V_23 >= V_15 -> V_64 ) {
V_3 . V_18 [ V_53 ] = NULL ;
V_3 . V_57 ++ ;
if ( V_3 . V_57 >= V_58 )
V_3 . V_57 = 0 ;
goto V_55;
}
V_25 = V_15 -> V_19 [ V_20 ] ;
V_20 ++ ;
if ( V_15 -> V_20 >= V_15 -> V_64 ) {
if ( V_25 & V_65 )
F_29 ( V_15 ) ;
V_3 . V_18 [ V_53 ] = NULL ;
V_3 . V_57 ++ ;
if ( V_3 . V_57 >= V_58 )
V_3 . V_57 = 0 ;
goto V_55;
}
while ( V_25 & V_66 ) {
if ( V_15 -> V_20 != V_20 ) {
V_20 ++ ;
V_25 &= ~ V_66 ;
break;
}
F_6 ( V_15 -> V_19 [ V_20 ] ) ;
V_15 -> V_20 ++ ;
if ( ( V_25 & V_67 ) == V_66 )
goto V_68;
if ( V_25 & V_69 )
V_15 -> V_20 ++ ;
goto V_55;
}
if ( V_25 & V_69 ) {
int V_70 ;
V_70 = V_15 -> V_19 [ V_20 ] ;
V_20 ++ ;
if ( V_15 -> V_20 - V_20 < V_70 ) {
F_8 ( V_15 -> V_19 [ V_15 -> V_20 ] ) ;
V_15 -> V_20 ++ ;
if ( V_15 -> V_20 - V_20 >= V_70 &&
( V_25 & V_67 ) == V_69 )
goto V_68;
goto V_55;
}
V_20 += V_70 ;
V_25 &= ~ V_69 ;
} else
while ( V_25 & V_71 ) {
int V_72 ;
T_1 V_73 [ 4 ] ;
V_72 = V_15 -> V_19 [ V_20 ] ;
if ( V_20 != V_15 -> V_20 ) {
V_20 ++ ;
V_20 += ! ! ( V_72 & 1 ) ;
V_20 += ! ! ( V_72 & 2 ) ;
V_20 += ! ! ( V_72 & 4 ) ;
V_20 += ! ! ( V_72 & 8 ) ;
V_25 &= ~ V_71 ;
break;
}
V_73 [ 0 ] = ( V_72 & 1 ) ? V_15 -> V_19 [ ++ V_20 ] : V_3 . V_74 [ 0 ] ;
V_73 [ 1 ] = ( V_72 & 2 ) ? V_15 -> V_19 [ ++ V_20 ] : V_3 . V_74 [ 1 ] ;
V_73 [ 2 ] = ( V_72 & 4 ) ? V_15 -> V_19 [ ++ V_20 ] : V_3 . V_74 [ 2 ] ;
V_73 [ 3 ] = ( V_72 & 8 ) ? V_15 -> V_19 [ ++ V_20 ] : V_3 . V_74 [ 3 ] ;
if ( V_3 . V_10 > 0x73 || V_3 . V_10 < 0x70 ||
V_73 [ V_3 . V_10 - 0x70 ] == V_3 . V_74 [ V_3 . V_10 - 0x70 ] ) {
int V_75 = 0 ;
while ( V_75 < 4 && V_73 [ V_75 ] == V_3 . V_74 [ V_75 ] )
V_75 ++ ;
if ( V_75 < 4 ) {
F_6 ( V_76 + V_75 ) ;
V_3 . V_10 = 0x70 + V_75 ;
goto V_55;
}
V_20 ++ ;
if ( ( V_25 & V_67 ) == V_71 )
goto V_68;
V_15 -> V_20 = V_20 ;
V_25 &= ~ V_71 ;
break;
}
F_8 ( V_73 [ V_3 . V_10 - 0x70 ] ) ;
V_3 . V_74 [ V_3 . V_10 - 0x70 ] = V_73 [ V_3 . V_10 - 0x70 ] ;
V_3 . V_10 ++ ;
{
int V_75 = 0 ;
while ( ( V_75 < 4 ) && V_73 [ V_75 ] == V_3 . V_74 [ V_75 ] )
V_75 ++ ;
if ( V_75 >= 4 ) {
V_15 -> V_20 = V_20 + 1 ;
if ( ( V_25 & V_67 ) ==
V_71 )
goto V_68;
}
}
goto V_55;
}
F_27 ( & V_3 . V_16 ) ;
if ( V_3 . V_17 >= 0 ) {
F_28 ( & V_3 . V_16 ) ;
goto V_55;
}
F_28 ( & V_3 . V_16 ) ;
if ( V_25 & V_77 ) {
T_1 V_78 ;
V_78 = V_15 -> V_19 [ V_20 ] ;
V_15 -> V_20 ++ ;
if ( V_25 & V_79 ) {
V_3 . V_21 = V_15 -> V_19 [ V_15 -> V_20 ] ;
F_16 ( & V_3 . V_22 ) ;
V_15 -> V_20 ++ ;
F_24 ( & V_3 . V_16 ) ;
V_3 . V_17 = V_53 ;
F_25 ( & V_3 . V_16 ) ;
F_6 ( V_78 ) ;
goto V_55;
}
F_6 ( V_78 ) ;
goto V_68;
}
V_68:
if ( V_25 & V_24 )
F_17 ( V_15 -> V_25 . V_26 ) ;
else if ( V_25 & V_27 )
V_15 -> V_25 . V_28 ( 0 , NULL , 0 , 0 ) ;
if ( V_15 -> V_20 >= V_15 -> V_64 ) {
if ( V_25 & V_65 )
F_29 ( V_15 ) ;
V_3 . V_18 [ V_53 ] = NULL ;
} else {
V_15 -> V_23 = V_20 + 1 ;
V_15 -> V_20 = V_20 + 2 ;
}
V_3 . V_57 ++ ;
if ( V_3 . V_57 >= V_58 )
V_3 . V_57 = 0 ;
V_55:
if ( ! V_3 . V_7 && V_54 ++ < 20 )
goto V_56;
V_63:
if ( V_3 . V_57 >= 0 )
F_19 ( & V_3 . V_29 ) ;
F_18 ( & V_3 . V_11 ) ;
return 0 ;
}
int F_30 ( T_3 * V_80 )
{
int V_75 ;
if ( V_80 == NULL ) {
F_31 () ;
return - V_81 ;
}
for ( V_75 = 0 ; V_75 < V_58 ; V_75 ++ )
if ( V_3 . V_18 [ V_75 ] == V_80 )
goto V_82;
V_80 -> V_23 = 0 ;
V_80 -> V_20 = 1 ;
for ( V_75 = 0 ; V_75 < V_58 ; V_75 ++ )
if ( V_3 . V_18 [ V_75 ] == NULL ) {
V_3 . V_18 [ V_75 ] = V_80 ;
F_19 ( & V_3 . V_29 ) ;
return 0 ;
}
F_21 (KERN_WARNING PREFIX L_4 ) ;
return - V_83 ;
V_82:
F_21 (KERN_WARNING PREFIX L_5 ) ;
return - V_81 ;
}
int F_32 ( T_3 * V_80 ) {
unsigned long V_2 ;
int V_84 ;
F_2 ( & V_3 . V_11 , V_2 ) ;
V_84 = F_30 ( V_80 ) ;
F_4 ( & V_3 . V_11 , V_2 ) ;
return V_84 ;
}
int F_33 ( T_3 * V_80 )
{
unsigned long V_2 ;
int V_75 ;
F_2 ( & V_3 . V_11 , V_2 ) ;
for ( V_75 = 0 ; V_75 < V_58 ; V_75 ++ )
if ( V_3 . V_18 [ V_75 ] == V_80 )
V_3 . V_18 [ V_75 ] = NULL ;
F_4 ( & V_3 . V_11 , V_2 ) ;
return 0 ;
}
int F_34 ( T_5 * V_85 )
{
if ( V_85 == NULL || V_3 . V_86 == NULL )
return - V_81 ;
F_24 ( & V_3 . V_35 ) ;
if ( V_3 . V_36 != NULL ) {
F_25 ( & V_3 . V_35 ) ;
return - V_83 ;
}
V_3 . V_36 = V_85 ;
V_3 . V_61 &= ~ V_87 ;
V_3 . V_61 &= ~ V_88 ;
V_3 . V_61 &= ~ V_89 ;
V_3 . V_60 = 1 ;
F_25 ( & V_3 . V_35 ) ;
F_19 ( & V_3 . V_29 ) ;
return 0 ;
}
int F_35 ( T_5 * V_85 )
{
if ( V_85 == NULL || V_3 . V_86 == NULL )
return - V_81 ;
F_24 ( & V_3 . V_35 ) ;
if ( V_3 . V_40 != NULL ) {
F_25 ( & V_3 . V_35 ) ;
return - V_83 ;
}
V_3 . V_40 = V_85 ;
V_3 . V_61 &= ~ ( V_90 | V_91 ) ;
V_3 . V_60 = 1 ;
F_25 ( & V_3 . V_35 ) ;
F_19 ( & V_3 . V_29 ) ;
return 0 ;
}
int F_36 ( T_5 * V_85 )
{
if ( V_85 == NULL || V_3 . V_86 == NULL )
return - V_81 ;
F_24 ( & V_3 . V_35 ) ;
if ( V_3 . V_43 != NULL ) {
F_25 ( & V_3 . V_35 ) ;
return - V_83 ;
}
V_3 . V_43 = V_85 ;
V_3 . V_61 &= ~ ( V_90 | V_91 ) ;
V_3 . V_60 = 1 ;
F_25 ( & V_3 . V_35 ) ;
F_19 ( & V_3 . V_29 ) ;
return 0 ;
}
int F_37 ( T_5 * V_85 )
{
F_24 ( & V_3 . V_35 ) ;
if ( ( V_85 != V_3 . V_36 ) ||
( V_3 . V_36 == NULL ) ) {
F_25 ( & V_3 . V_35 ) ;
return - V_81 ;
}
V_3 . V_36 = NULL ;
V_3 . V_61 |= V_89 ;
V_3 . V_61 |= V_87 ;
V_3 . V_61 |= V_88 ;
V_3 . V_60 = 1 ;
F_25 ( & V_3 . V_35 ) ;
F_19 ( & V_3 . V_29 ) ;
return 0 ;
}
int F_38 ( T_5 * V_85 )
{
F_24 ( & V_3 . V_35 ) ;
if ( ( V_85 != V_3 . V_40 ) ||
( V_3 . V_40 == NULL ) ) {
F_25 ( & V_3 . V_35 ) ;
return - V_81 ;
}
V_3 . V_40 = NULL ;
if( V_3 . V_43 == NULL ) {
V_3 . V_61 |= ( V_90 | V_91 ) ;
V_3 . V_60 = 1 ;
}
F_25 ( & V_3 . V_35 ) ;
F_19 ( & V_3 . V_29 ) ;
return 0 ;
}
int F_39 ( T_5 * V_85 )
{
F_24 ( & V_3 . V_35 ) ;
if ( ( V_85 != V_3 . V_43 ) ||
( V_3 . V_43 == NULL ) ) {
F_25 ( & V_3 . V_35 ) ;
return - V_81 ;
}
V_3 . V_43 = NULL ;
if( V_3 . V_40 == NULL ) {
V_3 . V_61 |= ( V_90 | V_91 ) ;
V_3 . V_60 = 1 ;
}
F_25 ( & V_3 . V_35 ) ;
F_19 ( & V_3 . V_29 ) ;
return 0 ;
}
void F_40 ( unsigned long V_14 )
{
F_19 ( & V_3 . V_29 ) ;
F_41 ( & V_3 . V_92 , V_93 + V_94 ) ;
}
static int T_6 F_42 ( void )
{
char * V_95 ;
T_3 V_96 ;
T_1 V_97 [ 6 ] ;
struct V_26 V_98 ;
F_43 ( & V_3 . V_11 ) ;
F_43 ( & V_3 . V_4 ) ;
F_43 ( & V_3 . V_16 ) ;
F_43 ( & V_3 . V_35 ) ;
V_3 . V_36 = NULL ;
V_3 . V_40 = NULL ;
V_3 . V_42 = NULL ;
V_3 . V_43 = NULL ;
V_3 . V_61 = V_99 ;
V_3 . V_60 = 1 ;
V_3 . V_10 = 0xff ;
V_3 . V_74 [ 0 ] = 0xff ;
V_3 . V_74 [ 1 ] = 0xff ;
V_3 . V_74 [ 2 ] = 0xff ;
V_3 . V_74 [ 3 ] = 0xff ;
V_3 . V_7 = 1 ;
memset ( & V_3 . V_18 , 0 , sizeof( V_3 . V_18 ) ) ;
V_3 . V_57 = - 1 ;
V_3 . V_17 = - 1 ;
V_3 . V_21 = 0 ;
V_3 . V_100 = - V_101 ;
V_95 = L_6 ;
if ( ! V_3 . V_102 )
goto V_103;
V_95 = L_7 ;
if ( ! V_3 . V_12 )
goto V_103;
V_3 . V_100 = - V_83 ;
#if F_44 ( V_104 )
V_95 = L_8 ;
if ( F_45 ( V_3 . V_8 , 2 , V_105 . V_106 ) )
goto V_103;
#endif
V_95 = L_9 ;
if ( F_46 ( V_3 . V_12 , & F_20 , V_107 | V_108 ,
L_10 , & V_3 ) )
goto V_109;
V_95 = L_11 ;
if ( F_46 ( V_3 . V_110 , & F_22 , V_107 ,
L_12 , & V_3 ) )
goto V_111;
F_21 (KERN_INFO PREFIX L_13 ,
(void *)hp_sdc.base_io, hp_sdc.irq, hp_sdc.nmi) ;
F_1 () ;
F_5 () ;
F_47 ( & V_3 . V_29 , F_23 , 0 ) ;
V_96 . V_23 = 0 ;
V_96 . V_20 = 1 ;
V_96 . V_64 = 6 ;
V_96 . V_19 = V_97 ;
V_97 [ 0 ] = V_71 | V_24 ;
V_97 [ 1 ] = 0x0f ;
V_97 [ 2 ] = V_97 [ 3 ] = V_97 [ 4 ] = V_97 [ 5 ] = 0 ;
V_96 . V_25 . V_26 = & V_98 ;
F_48 ( & V_98 , 0 ) ;
F_32 ( & V_96 ) ;
F_49 ( & V_98 ) ;
F_50 ( & V_3 . V_92 ) ;
V_3 . V_92 . V_112 = V_93 + V_94 ;
V_3 . V_92 . V_113 = & F_40 ;
F_51 ( & V_3 . V_92 ) ;
V_3 . V_100 = 0 ;
return 0 ;
V_111:
F_52 ( V_3 . V_12 , & V_3 ) ;
V_109:
F_53 ( V_3 . V_8 , 2 ) ;
V_103:
F_21 (KERN_WARNING PREFIX L_14 ,
errstr, (void *)hp_sdc.base_io, hp_sdc.irq, hp_sdc.nmi) ;
V_3 . V_86 = NULL ;
return V_3 . V_100 ;
}
static void F_54 ( struct V_114 * V_115 )
{
F_55 ( L_15 ) ;
}
static int T_6 F_56 ( struct V_116 * V_117 )
{
int V_84 ;
if ( ! V_117 )
return 1 ;
if ( V_3 . V_86 != NULL )
return 1 ;
V_3 . V_86 = V_117 ;
V_3 . V_12 = V_117 -> V_12 ;
V_3 . V_110 = V_117 -> V_118 ;
V_3 . V_102 = V_117 -> V_119 . V_59 ;
V_3 . V_8 = V_117 -> V_119 . V_59 + 0x800 ;
V_3 . V_5 = V_117 -> V_119 . V_59 + 0x801 ;
F_57 ( & V_120 , F_54 ) ;
V_84 = F_42 () ;
if ( ! V_84 )
F_58 ( & V_120 ,
F_59 ( 2000 ) ) ;
return V_84 ;
}
static void F_60 ( void )
{
if ( ! V_3 . V_86 )
return;
F_24 ( & V_3 . V_11 ) ;
F_9 () ;
F_7 ( V_62 | V_99 , V_3 . V_5 ) ;
F_9 () ;
F_52 ( V_3 . V_110 , & V_3 ) ;
F_52 ( V_3 . V_12 , & V_3 ) ;
F_25 ( & V_3 . V_11 ) ;
F_61 ( & V_3 . V_92 ) ;
F_62 ( & V_3 . V_29 ) ;
#if F_44 ( V_104 )
F_63 ( & V_120 ) ;
if ( F_64 ( & V_105 ) )
F_21 (KERN_WARNING PREFIX L_16 ) ;
#endif
}
static int T_6 F_65 ( void )
{
T_3 V_121 ;
T_1 V_122 [ 5 ] ;
struct V_26 V_123 ;
#if F_44 ( V_124 )
T_7 V_125 ;
unsigned char V_75 ;
#endif
if ( V_126 ) {
F_21 (KERN_WARNING PREFIX L_17 ) ;
return - V_101 ;
}
V_3 . V_86 = NULL ;
V_3 . V_100 = 0 ;
#if F_44 ( V_104 )
if ( F_66 ( & V_105 ) ) {
F_21 (KERN_WARNING PREFIX L_18 ) ;
return - V_101 ;
}
#elif F_44 ( V_124 )
if ( ! V_127 )
return - V_101 ;
V_3 . V_12 = 1 ;
V_3 . V_110 = 7 ;
V_3 . V_102 = ( unsigned long ) 0xf0428000 ;
V_3 . V_8 = ( unsigned long ) V_3 . V_102 + 1 ;
V_3 . V_5 = ( unsigned long ) V_3 . V_102 + 3 ;
V_125 = F_67 () ;
F_68 ( V_128 ) ;
if ( ! F_69 ( V_75 , ( unsigned char * ) V_3 . V_8 ) )
V_3 . V_86 = ( void * ) 1 ;
F_68 ( V_125 ) ;
V_3 . V_100 = F_42 () ;
#endif
if ( V_3 . V_86 == NULL ) {
F_21 (KERN_WARNING PREFIX L_19 ) ;
return V_3 . V_100 ;
}
F_48 ( & V_123 , 0 ) ;
V_121 . V_23 = 0 ;
V_121 . V_20 = 1 ;
V_121 . V_64 = 5 ;
V_121 . V_19 = V_122 ;
V_121 . V_25 . V_26 = & V_123 ;
V_122 [ 0 ] =
V_77 | V_79 | V_24 ;
V_122 [ 1 ] = V_129 ;
V_122 [ 2 ] = 1 ;
V_122 [ 3 ] = 0 ;
V_122 [ 4 ] = 0 ;
F_32 ( & V_121 ) ;
F_49 ( & V_123 ) ;
F_17 ( & V_123 ) ;
if ( ( V_122 [ 0 ] & V_52 ) == V_52 ) {
F_21 (KERN_WARNING PREFIX L_20 ) ;
F_60 () ;
return - V_101 ;
}
V_3 . V_130 = V_122 [ 4 ] ;
if ( V_3 . V_130 & V_131 ) {
const char * V_132 ;
F_21 (KERN_INFO PREFIX L_21 ) ;
V_122 [ 1 ] = V_133 ;
V_121 . V_23 = 0 ;
V_121 . V_20 = 1 ;
F_49 ( & V_123 ) ;
F_32 ( & V_121 ) ;
F_49 ( & V_123 ) ;
F_17 ( & V_123 ) ;
if ( ( V_122 [ 0 ] & V_52 ) == V_52 ) {
F_21 (KERN_WARNING PREFIX L_22 ) ;
return - V_101 ;
}
V_3 . V_134 = V_122 [ 4 ] ;
F_70 (hp_sdc.r7e & HP_SDC_XTD_REV, str)
F_21 (KERN_INFO PREFIX L_23 , str) ;
if ( V_3 . V_134 & V_135 )
F_21 (KERN_INFO PREFIX L_24 ) ;
if ( V_3 . V_134 & V_136 )
F_21 (KERN_INFO PREFIX L_25 ) ;
F_21 (KERN_INFO PREFIX L_26
L_27 ) ;
V_122 [ 0 ] = V_66 |
V_69 | V_24 ;
V_122 [ 1 ] = V_137 ;
V_122 [ 2 ] = 1 ;
V_122 [ 3 ] = 0 ;
V_121 . V_23 = 0 ;
V_121 . V_20 = 1 ;
V_121 . V_64 = 4 ;
F_49 ( & V_123 ) ;
F_32 ( & V_121 ) ;
F_49 ( & V_123 ) ;
F_17 ( & V_123 ) ;
} else
F_21 (KERN_INFO PREFIX L_28 ,
(hp_sdc.r11 & HP_SDC_CFG_REV) ? L_29 : L_30 ) ;
return 0 ;
}
