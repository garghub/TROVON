static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned V_5 , V_6 ;
unsigned V_7 ;
do {
V_5 = V_4 -> V_8 ;
V_6 = 0 ;
switch( V_4 -> V_8 ) {
case V_9 :
if ( V_2 -> V_10 -> V_11 )
V_7 = V_2 -> V_10 -> V_11 ( V_2 ) ;
else
V_7 = 0 ;
if ( ! V_7 ) {
V_5 = V_12 ;
break;
}
if ( V_2 -> V_13 > 115200 )
V_6 = ( V_7 * 8 * 10000 ) / ( V_2 -> V_13 / 100 ) ;
else if ( V_2 -> V_13 > 0 )
V_6 = ( V_7 * 10 * 10000 ) / ( V_2 -> V_13 / 100 ) ;
else
V_6 = 0 ;
if ( V_6 < 100 ) {
F_2 ( V_6 ) ;
V_6 = 0 ;
break;
}
V_6 = ( V_6 + 999 ) / 1000 ;
break;
case V_12 :
if ( V_2 -> V_10 -> V_14 )
V_2 -> V_10 -> V_14 ( V_2 ) ;
V_5 = V_15 ;
break;
case V_15 :
return 0 ;
default:
F_3 ( L_1 , V_16 ) ;
return - V_17 ;
}
V_4 -> V_8 = V_5 ;
} while ( V_6 == 0 );
return V_6 ;
}
static void F_4 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_5 ( V_19 , struct V_1 , V_4 . V_19 . V_19 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 ;
int V_20 = - 1 ;
unsigned V_6 ;
F_6 ( L_2 , V_16 , V_21 ) ;
do {
F_6 ( L_3 ,
V_16 , V_4 -> V_22 , V_4 -> V_8 ) ;
V_5 = V_4 -> V_22 ;
V_6 = 0 ;
switch( V_4 -> V_22 ) {
case V_23 :
if ( V_2 -> V_24 != NULL ) {
V_20 = F_7 ( V_2 ) ;
if ( V_20 ) {
V_4 -> V_25 = - V_17 ;
V_5 = V_26 ;
break;
}
}
V_20 = F_8 ( V_2 , V_4 -> V_27 ) ;
if ( V_20 ) {
V_4 -> V_25 = V_20 ;
V_5 = V_26 ;
break;
}
V_6 = 50 ;
V_4 -> V_8 = V_28 ;
V_5 = V_28 ;
V_4 -> V_27 = 9600 ;
break;
case V_29 :
if ( V_2 -> V_24 == NULL ) {
V_4 -> V_25 = - V_17 ;
V_5 = V_26 ;
break;
}
V_20 = F_7 ( V_2 ) ;
if ( V_20 ) {
V_4 -> V_25 = V_20 ;
V_5 = V_26 ;
break;
}
V_5 = V_30 ;
break;
case V_31 :
V_20 = F_9 ( V_2 ,
( V_4 -> V_27 & 0x02 ) ? TRUE : FALSE ,
( V_4 -> V_27 & 0x01 ) ? TRUE : FALSE ) ;
V_5 = V_30 ;
break;
case V_32 :
V_4 -> V_8 = V_9 ;
V_5 = V_33 ;
break;
case V_33 :
V_20 = F_1 ( V_2 ) ;
if ( V_20 < 0 ) {
V_4 -> V_25 = V_20 ;
V_5 = V_26 ;
break;
}
if ( ( V_6 = V_20 ) != 0 )
break;
if ( V_2 -> V_24 ) {
V_4 -> V_8 = V_28 ;
V_5 = V_28 ;
}
else {
V_2 -> V_13 = V_4 -> V_27 ;
V_5 = V_34 ;
}
break;
case V_28 :
if ( V_2 -> V_24 -> V_35 ) {
V_20 = V_2 -> V_24 -> V_35 ( V_2 ) ;
if ( V_20 < 0 ) {
V_4 -> V_25 = V_20 ;
V_5 = V_26 ;
break;
}
}
else
V_20 = 0 ;
if ( ( V_6 = V_20 ) == 0 ) {
if ( V_2 -> V_10 -> V_36 )
V_2 -> V_10 -> V_36 ( V_2 , V_2 -> V_13 ) ;
V_4 -> V_8 = V_37 ;
V_5 = V_37 ;
}
break;
case V_37 :
if ( V_2 -> V_24 -> V_36 ) {
V_20 = V_2 -> V_24 -> V_36 ( V_2 , V_4 -> V_27 ) ;
if ( V_20 < 0 ) {
V_4 -> V_25 = V_20 ;
V_5 = V_26 ;
break;
}
}
else
V_20 = 0 ;
if ( ( V_6 = V_20 ) == 0 )
V_5 = V_34 ;
break;
case V_34 :
if ( V_2 -> V_10 -> V_36 )
V_2 -> V_10 -> V_36 ( V_2 , V_2 -> V_13 ) ;
V_2 -> V_38 = 0 ;
V_5 = V_30 ;
break;
case V_30 :
F_10 ( V_2 -> V_39 ) ;
V_5 = V_40 ;
break;
default:
F_3 ( L_1 , V_16 ) ;
V_4 -> V_25 = - V_17 ;
case V_26 :
F_3 ( L_4 ,
V_16 , V_4 -> V_25 ) ;
#if 0
netif_stop_queue(dev->netdev);
#else
F_10 ( V_2 -> V_39 ) ;
#endif
case V_40 :
F_11 ( V_2 ) ;
F_12 ( & V_4 -> V_41 ) ;
return;
}
V_4 -> V_22 = V_5 ;
} while( ! V_6 );
F_13 ( V_42 , & V_4 -> V_19 , F_14 ( V_6 ) ) ;
}
int F_15 ( struct V_1 * V_2 , int V_43 , unsigned V_27 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_6 ( L_5 , V_16 ,
V_43 , V_27 ) ;
if ( F_16 ( & V_4 -> V_41 ) ) {
if ( F_17 () || F_18 () || F_19 () ) {
F_6 ( L_6 , V_16 ) ;
return - V_44 ;
} else
F_20 ( & V_4 -> V_41 ) ;
}
if ( V_4 -> V_22 == V_45 ) {
F_3 ( L_7 , V_16 ) ;
F_12 ( & V_4 -> V_41 ) ;
return - V_46 ;
}
F_21 ( V_2 -> V_39 ) ;
F_22 ( & V_2 -> V_47 , 0 ) ;
V_4 -> V_22 = V_43 ;
V_4 -> V_27 = V_27 ;
V_4 -> V_25 = 0 ;
F_23 ( & V_4 -> V_19 , F_4 ) ;
F_13 ( V_42 , & V_4 -> V_19 , 0 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( F_24 ( F_25 ( & V_2 -> V_47 ) ) )
return;
V_2 -> V_48 . V_49 = V_2 -> V_48 . V_50 ;
V_2 -> V_48 . V_51 = 0 ;
V_2 -> V_48 . V_52 = FALSE ;
V_2 -> V_48 . V_22 = V_53 ;
F_22 ( & V_2 -> V_47 , 1 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( ! F_25 ( & V_2 -> V_47 ) )
return 0 ;
return V_2 -> V_48 . V_22 != V_53 ;
}
int F_27 ( struct V_1 * V_2 , T_1 type )
{
int V_54 ;
F_6 ( L_8 , V_16 , type ) ;
V_54 = F_28 ( V_2 , type ) ;
if ( F_24 ( V_54 ) )
return V_54 ;
F_20 ( & V_2 -> V_4 . V_41 ) ;
V_54 = V_2 -> V_4 . V_25 ;
F_12 ( & V_2 -> V_4 . V_41 ) ;
return V_54 ;
}
int F_29 ( struct V_1 * V_2 , const char * V_55 , int V_51 )
{
unsigned long V_56 ;
int V_20 ;
if ( F_24 ( V_51 > V_2 -> V_57 . V_58 ) )
return - V_59 ;
F_30 ( & V_2 -> V_60 , V_56 ) ;
while ( V_2 -> V_57 . V_51 > 0 ) {
F_31 ( & V_2 -> V_60 , V_56 ) ;
F_32 ( 10 ) ;
F_30 ( & V_2 -> V_60 , V_56 ) ;
}
V_2 -> V_57 . V_49 = V_2 -> V_57 . V_50 ;
memcpy ( V_2 -> V_57 . V_49 , V_55 , V_51 ) ;
V_2 -> V_57 . V_51 = V_51 ;
V_20 = V_2 -> V_10 -> V_61 ( V_2 , V_2 -> V_57 . V_49 , V_2 -> V_57 . V_51 ) ;
if ( V_20 > 0 ) {
F_6 ( L_9 , V_16 ) ;
V_2 -> V_57 . V_49 += V_20 ;
V_2 -> V_57 . V_51 -= V_20 ;
V_2 -> V_62 = 1 ;
V_20 = V_51 ;
}
F_31 ( & V_2 -> V_60 , V_56 ) ;
return V_20 ;
}
int F_33 ( struct V_1 * V_2 , char * V_55 , int V_51 )
{
int V_63 ;
if ( F_25 ( & V_2 -> V_47 ) )
return - V_64 ;
V_63 = ( V_51 < V_2 -> V_48 . V_51 ) ? V_51 : V_2 -> V_48 . V_51 ;
if ( V_63 > 0 ) {
memcpy ( V_55 , V_2 -> V_48 . V_49 , V_63 ) ;
V_2 -> V_48 . V_49 += V_63 ;
V_2 -> V_48 . V_51 -= V_63 ;
}
return V_63 ;
}
int F_9 ( struct V_1 * V_2 , int V_65 , int V_66 )
{
int V_20 = - V_67 ;
if ( V_2 -> V_10 -> V_68 )
V_20 = V_2 -> V_10 -> V_68 ( V_2 , V_65 , V_66 ) ;
return V_20 ;
}
void F_34 ( struct V_1 * V_2 )
{
unsigned long V_56 ;
struct V_69 * V_70 ;
int V_71 = 0 ;
int V_54 ;
F_30 ( & V_2 -> V_60 , V_56 ) ;
F_6 ( L_10 ,
V_16 , V_2 -> V_57 . V_51 ) ;
if ( F_35 ( V_2 -> V_57 . V_51 > 0 ) ) {
V_71 = V_2 -> V_10 -> V_61 ( V_2 , V_2 -> V_57 . V_49 , V_2 -> V_57 . V_51 ) ;
if ( F_35 ( V_71 > 0 ) ) {
V_2 -> V_57 . V_49 += V_71 ;
V_2 -> V_57 . V_51 -= V_71 ;
}
else if ( F_24 ( V_71 < 0 ) ) {
F_3 ( L_11 ,
V_16 , V_71 ) ;
if ( ( V_70 = V_2 -> V_72 ) != NULL ) {
V_2 -> V_72 = NULL ;
F_36 ( V_70 ) ;
V_2 -> V_39 -> V_73 . V_74 ++ ;
V_2 -> V_39 -> V_73 . V_75 ++ ;
}
V_2 -> V_57 . V_51 = 0 ;
}
if ( V_2 -> V_57 . V_51 > 0 )
goto V_76;
}
if ( F_24 ( V_2 -> V_62 != 0 ) ) {
F_6 ( L_12 , V_16 ) ;
V_2 -> V_62 = 0 ;
goto V_76;
}
F_6 ( L_13 , V_16 ) ;
if ( ( V_70 = V_2 -> V_72 ) != NULL ) {
V_2 -> V_72 = NULL ;
V_2 -> V_39 -> V_73 . V_77 ++ ;
V_2 -> V_39 -> V_73 . V_78 += V_70 -> V_51 ;
F_36 ( V_70 ) ;
}
if ( F_24 ( V_2 -> V_38 > 0 ) ) {
F_6 ( L_14 , V_16 ) ;
V_54 = F_37 ( V_2 , V_2 -> V_38 ) ;
if ( F_24 ( V_54 ) ) {
F_3 ( L_15 ,
V_16 , V_54 ) ;
F_10 ( V_2 -> V_39 ) ;
}
}
else {
F_11 ( V_2 ) ;
F_10 ( V_2 -> V_39 ) ;
}
V_76:
F_31 ( & V_2 -> V_60 , V_56 ) ;
}
int F_38 ( struct V_1 * V_2 , const unsigned char * V_79 , T_2 V_63 )
{
if ( ! V_2 || ! V_2 -> V_39 ) {
F_39 ( L_16 , V_16 ) ;
return - 1 ;
}
if ( ! V_2 -> V_80 ) {
F_39 ( L_17 ,
V_16 , V_79 , V_63 ) ;
return - 1 ;
}
if ( V_79 == NULL ) {
F_40 ( V_2 -> V_39 , TRUE ) ;
V_2 -> V_39 -> V_73 . V_81 ++ ;
F_6 ( L_18 , V_16 , V_63 ) ;
return 0 ;
}
if ( F_35 ( F_25 ( & V_2 -> V_47 ) ) ) {
while ( V_63 -- )
F_41 ( V_2 -> V_39 , & V_2 -> V_39 -> V_73 ,
& V_2 -> V_48 , * V_79 ++ ) ;
} else {
while ( V_63 -- ) {
V_2 -> V_48 . V_49 [ V_2 -> V_48 . V_51 ++ ] = * V_79 ++ ;
if ( F_24 ( V_2 -> V_48 . V_51 == V_2 -> V_48 . V_58 ) )
V_2 -> V_48 . V_51 = 0 ;
}
}
return 0 ;
}
static T_3 F_42 ( struct V_69 * V_70 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_43 ( V_83 ) ;
unsigned long V_56 ;
int V_71 = 0 ;
int V_54 ;
T_4 V_13 ;
F_44 (dev != NULL, return NETDEV_TX_OK;) ;
F_21 ( V_83 ) ;
F_6 ( L_19 , V_16 , V_70 -> V_51 ) ;
V_13 = F_45 ( V_70 ) ;
if ( ( V_13 != V_2 -> V_13 ) && ( V_13 != - 1 ) ) {
if ( ! V_70 -> V_51 ) {
V_54 = F_37 ( V_2 , V_13 ) ;
if ( F_24 ( V_54 == - V_44 ) ) {
return V_84 ;
}
else if ( F_24 ( V_54 ) ) {
F_46 ( V_83 ) ;
}
F_36 ( V_70 ) ;
return V_85 ;
} else
V_2 -> V_38 = V_13 ;
}
V_2 -> V_57 . V_49 = V_2 -> V_57 . V_50 ;
if( F_47 ( & V_2 -> V_60 ) ) {
F_6 ( L_20 , V_16 ) ;
}
F_30 ( & V_2 -> V_60 , V_56 ) ;
V_2 -> V_57 . V_51 = F_48 ( V_70 , V_2 -> V_57 . V_49 , V_2 -> V_57 . V_58 ) ;
F_22 ( & V_2 -> V_47 , 0 ) ;
if ( F_24 ( F_26 ( V_2 ) ) )
V_2 -> V_39 -> V_73 . V_86 ++ ;
V_71 = V_2 -> V_10 -> V_61 ( V_2 , V_2 -> V_57 . V_49 , V_2 -> V_57 . V_51 ) ;
if ( F_35 ( V_71 > 0 ) ) {
V_2 -> V_72 = V_70 ;
V_2 -> V_57 . V_49 += V_71 ;
V_2 -> V_57 . V_51 -= V_71 ;
}
else if ( F_24 ( V_71 < 0 ) ) {
F_3 ( L_11 ,
V_16 , V_71 ) ;
F_36 ( V_70 ) ;
V_2 -> V_39 -> V_73 . V_74 ++ ;
V_2 -> V_39 -> V_73 . V_75 ++ ;
F_10 ( V_83 ) ;
}
F_31 ( & V_2 -> V_60 , V_56 ) ;
return V_85 ;
}
static int F_49 ( struct V_82 * V_83 , struct V_87 * V_88 , int V_89 )
{
struct V_90 * V_91 = (struct V_90 * ) V_88 ;
struct V_1 * V_2 = F_43 ( V_83 ) ;
int V_20 = 0 ;
F_44 (dev != NULL, return -1;) ;
F_6 ( L_21 , V_16 , V_83 -> V_92 , V_89 ) ;
switch ( V_89 ) {
case V_93 :
if ( ! F_50 ( V_94 ) )
V_20 = - V_95 ;
else
V_20 = F_37 ( V_2 , V_91 -> V_96 ) ;
break;
case V_97 :
if ( ! F_50 ( V_94 ) )
V_20 = - V_95 ;
else
V_20 = F_28 ( V_2 , V_91 -> V_98 ) ;
break;
case V_99 :
if ( ! F_50 ( V_94 ) )
V_20 = - V_95 ;
else
F_40 ( V_2 -> V_39 , TRUE ) ;
break;
case V_100 :
V_91 -> V_101 = F_26 ( V_2 ) ;
break;
case V_102 :
if ( ! F_50 ( V_94 ) )
V_20 = - V_95 ;
else
V_20 = F_51 ( V_2 , V_91 -> V_103 , V_91 -> V_104 ) ;
break;
case V_105 :
#if 0
if (!capable(CAP_NET_ADMIN))
ret = -EPERM;
else
ret = sirdev_schedule_mode(dev, irq->ifr_mode);
break;
#endif
default:
V_20 = - V_106 ;
}
return V_20 ;
}
static int F_52 ( struct V_1 * V_2 )
{
V_2 -> V_57 . V_58 = V_107 ;
V_2 -> V_48 . V_58 = V_108 ;
V_2 -> V_48 . V_70 = F_53 ( V_2 -> V_39 , V_2 -> V_48 . V_58 ,
V_109 ) ;
if ( V_2 -> V_48 . V_70 == NULL )
return - V_110 ;
F_54 ( V_2 -> V_48 . V_70 , 1 ) ;
V_2 -> V_48 . V_50 = V_2 -> V_48 . V_70 -> V_49 ;
V_2 -> V_57 . V_50 = F_55 ( V_2 -> V_57 . V_58 , V_109 ) ;
if ( V_2 -> V_57 . V_50 == NULL ) {
F_56 ( V_2 -> V_48 . V_70 ) ;
V_2 -> V_48 . V_70 = NULL ;
V_2 -> V_48 . V_50 = NULL ;
return - V_110 ;
}
V_2 -> V_57 . V_49 = V_2 -> V_57 . V_50 ;
V_2 -> V_48 . V_49 = V_2 -> V_48 . V_50 ;
V_2 -> V_57 . V_51 = 0 ;
V_2 -> V_48 . V_51 = 0 ;
V_2 -> V_48 . V_52 = FALSE ;
V_2 -> V_48 . V_22 = V_53 ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_56 ( V_2 -> V_48 . V_70 ) ;
F_58 ( V_2 -> V_57 . V_50 ) ;
V_2 -> V_48 . V_50 = V_2 -> V_57 . V_50 = NULL ;
V_2 -> V_48 . V_70 = NULL ;
}
static int F_59 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_43 ( V_83 ) ;
const struct V_111 * V_10 = V_2 -> V_10 ;
if ( ! V_10 )
return - V_112 ;
if ( ! F_60 ( V_10 -> V_113 ) )
return - V_46 ;
if ( F_52 ( V_2 ) )
goto V_114;
if ( ! V_2 -> V_10 -> V_115 || V_2 -> V_10 -> V_115 ( V_2 ) )
goto V_116;
F_11 ( V_2 ) ;
V_2 -> V_62 = 0 ;
F_46 ( V_83 ) ;
V_2 -> V_80 = F_61 ( V_83 , & V_2 -> V_117 , V_2 -> V_118 ) ;
if ( ! V_2 -> V_80 )
goto V_119;
F_10 ( V_83 ) ;
F_6 ( L_22 , V_16 , V_2 -> V_13 ) ;
return 0 ;
V_119:
F_22 ( & V_2 -> V_47 , 0 ) ;
if ( V_2 -> V_10 -> V_120 )
V_2 -> V_10 -> V_120 ( V_2 ) ;
V_116:
F_57 ( V_2 ) ;
V_114:
F_62 ( V_10 -> V_113 ) ;
return - V_121 ;
}
static int F_63 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_43 ( V_83 ) ;
const struct V_111 * V_10 ;
F_21 ( V_83 ) ;
F_20 ( & V_2 -> V_4 . V_41 ) ;
F_22 ( & V_2 -> V_47 , 0 ) ;
if ( F_24 ( ! V_2 -> V_80 ) )
goto V_122;
F_64 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
V_10 = V_2 -> V_10 ;
if ( F_24 ( ! V_10 || ! V_2 -> V_123 ) )
goto V_122;
if ( V_10 -> V_120 )
V_10 -> V_120 ( V_2 ) ;
F_57 ( V_2 ) ;
F_62 ( V_10 -> V_113 ) ;
V_122:
V_2 -> V_13 = 0 ;
F_12 ( & V_2 -> V_4 . V_41 ) ;
return 0 ;
}
struct V_1 * F_65 ( const struct V_111 * V_10 , const char * V_92 )
{
struct V_82 * V_83 ;
struct V_1 * V_2 ;
F_6 ( L_23 , V_16 , V_92 ) ;
if ( ! V_10 || ! V_10 -> V_61 )
return NULL ;
V_83 = F_66 ( sizeof( * V_2 ) ) ;
if ( V_83 == NULL ) {
F_3 ( L_24 ,
V_16 ) ;
goto V_122;
}
V_2 = F_43 ( V_83 ) ;
F_67 ( & V_2 -> V_117 ) ;
V_2 -> V_117 . V_124 . V_125 = V_126 | V_127 | V_128 | V_129 | V_130 ;
V_2 -> V_117 . V_131 . V_125 = V_10 -> V_132 ;
F_68 ( & V_2 -> V_117 ) ;
strncpy ( V_2 -> V_118 , V_92 , sizeof( V_2 -> V_118 ) - 1 ) ;
F_22 ( & V_2 -> V_47 , 0 ) ;
V_2 -> V_72 = NULL ;
F_69 ( & V_2 -> V_60 ) ;
F_70 ( & V_2 -> V_4 . V_41 , 1 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_39 = V_83 ;
V_83 -> V_133 = & V_134 ;
if ( F_71 ( V_83 ) ) {
F_3 ( L_25 ,
V_16 ) ;
goto V_135;
}
return V_2 ;
V_135:
F_72 ( V_83 ) ;
V_122:
return NULL ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_54 = 0 ;
F_6 ( L_26 , V_16 ) ;
F_22 ( & V_2 -> V_47 , 0 ) ;
F_74 ( V_2 -> V_39 ) ;
F_75 ( V_2 -> V_39 ) ;
if ( V_2 -> V_24 )
V_54 = F_76 ( V_2 ) ;
if ( V_54 )
F_3 ( L_27 , V_16 , V_54 ) ;
F_63 ( V_2 -> V_39 ) ;
F_20 ( & V_2 -> V_4 . V_41 ) ;
V_2 -> V_4 . V_22 = V_45 ;
V_2 -> V_24 = NULL ;
V_2 -> V_123 = NULL ;
F_12 ( & V_2 -> V_4 . V_41 ) ;
F_77 ( V_2 -> V_39 ) ;
F_72 ( V_2 -> V_39 ) ;
return 0 ;
}
static int T_5 F_78 ( void )
{
V_42 = F_79 ( L_28 ) ;
if ( ! V_42 )
return - V_110 ;
return 0 ;
}
static void T_6 F_80 ( void )
{
F_81 ( V_42 ) ;
}
