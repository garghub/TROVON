void
F_1 ( struct V_1 * V_2 , char * V_3 , unsigned short V_4 )
{
if ( F_2 ( V_5 , & V_2 -> V_6 ) ) {
V_3 [ 0 ] = ( V_4 >> 8 ) & 0x3f ;
V_3 [ 1 ] = V_4 & 0xff ;
} else {
V_3 [ 0 ] = V_7 [ ( V_4 >> 6 ) & 0x3f ] ;
V_3 [ 1 ] = V_7 [ V_4 & 0x3f ] ;
}
}
struct V_8 *
F_3 ( T_1 V_9 )
{
struct V_8 * V_10 ;
V_10 = F_4 ( sizeof( struct V_8 ) , V_11 | V_12 ) ;
if ( ! V_10 )
return F_5 ( - V_13 ) ;
if ( V_9 > 0 ) {
V_10 -> V_14 = F_6 ( V_9 , V_11 | V_12 ) ;
if ( ! V_10 -> V_14 ) {
F_7 ( V_10 ) ;
return F_5 ( - V_13 ) ;
}
}
V_10 -> V_9 = V_9 ;
F_8 ( & V_10 -> V_15 ) ;
V_10 -> V_16 . V_17 = F_9 ( V_10 -> V_14 ) ;
V_10 -> V_16 . V_6 = V_18 ;
return V_10 ;
}
void
F_10 ( struct V_8 * V_10 )
{
F_7 ( V_10 -> V_14 ) ;
F_7 ( V_10 ) ;
}
void
F_11 ( struct V_8 * V_10 )
{
F_12 ( ! F_13 ( & V_10 -> V_15 ) ) ;
V_10 -> V_16 . V_19 = 0 ;
V_10 -> V_16 . V_20 = 0 ;
V_10 -> V_16 . V_17 = F_9 ( V_10 -> V_14 ) ;
V_10 -> V_16 . V_6 = V_18 ;
V_10 -> V_21 = 0 ;
V_10 -> V_22 = 0 ;
}
void
F_14 ( struct V_8 * V_10 , T_2 V_23 )
{
V_10 -> V_16 . V_19 = V_23 ;
}
int
F_15 ( struct V_8 * V_10 , void * V_24 , T_1 V_9 )
{
if ( V_9 + V_10 -> V_16 . V_20 > V_10 -> V_9 )
return - V_25 ;
memcpy ( V_10 -> V_14 + V_10 -> V_16 . V_20 , V_24 , V_9 ) ;
V_10 -> V_16 . V_20 += V_9 ;
return 0 ;
}
void
F_16 ( struct V_8 * V_10 , void * V_24 , T_1 V_9 )
{
V_10 -> V_16 . V_17 = F_9 ( V_24 ) ;
V_10 -> V_16 . V_20 = V_9 ;
}
void
F_17 ( struct V_8 * V_10 , struct V_26 * V_27 )
{
V_10 -> V_16 . V_17 = F_9 ( V_27 -> V_24 ) ;
V_10 -> V_16 . V_20 = V_27 -> V_9 ;
V_10 -> V_16 . V_6 |= V_28 ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_8 * V_10 )
{
int V_29 ;
int V_22 ;
if ( F_19 ( V_10 ) )
return 0 ;
for ( V_29 = 0 ; V_29 < 5 ; V_29 ++ ) {
if ( V_29 < 2 )
V_22 = F_20 ( V_2 -> V_30 , ( long ) V_10 ) ;
else
V_22 = F_21 ( V_2 -> V_30 , ( long ) V_10 ) ;
if ( V_22 == 0 )
break;
}
return V_22 ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_8 * V_10 )
{
unsigned long V_6 ;
int V_22 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
V_22 = F_18 ( V_2 , V_10 ) ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
return V_22 ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_8 * V_10 )
{
V_10 -> V_32 = V_32 ;
F_27 ( V_32 ) ;
if ( F_13 ( & V_2 -> V_33 ) &&
! F_2 ( V_34 , & V_2 -> V_6 ) ) {
V_10 -> V_22 = F_28 ( V_2 -> V_30 , & V_10 -> V_16 ,
( unsigned long ) V_10 , 0 , 0 ) ;
if ( V_10 -> V_22 ) {
F_29 ( V_32 ) ;
return V_10 -> V_22 ;
}
}
F_30 ( & V_10 -> V_15 , & V_2 -> V_33 ) ;
return 0 ;
}
int
F_31 ( struct V_31 * V_32 , struct V_8 * V_10 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
int V_22 ;
F_23 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
V_2 = V_32 -> V_35 ;
if ( ! V_2 || V_2 -> V_32 != V_32 ||
F_2 ( V_36 , & V_2 -> V_6 ) )
V_22 = - V_37 ;
else if ( ! F_2 ( V_38 , & V_2 -> V_6 ) )
V_22 = - V_39 ;
else
V_22 = F_26 ( V_2 , V_32 , V_10 ) ;
F_25 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
return V_22 ;
}
int
F_32 ( struct V_31 * V_32 , struct V_8 * V_10 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = V_32 -> V_35 ;
if ( ! V_2 || V_2 -> V_32 != V_32 ||
F_2 ( V_36 , & V_2 -> V_6 ) )
V_22 = - V_37 ;
else if ( ! F_2 ( V_38 , & V_2 -> V_6 ) )
V_22 = - V_39 ;
else
V_22 = F_26 ( V_2 , V_32 , V_10 ) ;
return V_22 ;
}
int
F_33 ( struct V_31 * V_32 , struct V_8 * V_10 )
{
struct V_1 * V_2 ;
V_2 = V_32 -> V_35 ;
V_10 -> V_32 = V_32 ;
F_27 ( V_32 ) ;
F_30 ( & V_10 -> V_15 , & V_2 -> V_33 ) ;
return 0 ;
}
static void
F_34 ( struct V_40 * V_30 , unsigned long V_41 , struct V_42 * V_42 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
struct V_8 * V_10 ;
int V_22 ;
F_35 ( F_36 () ) . V_43 [ V_44 ] ++ ;
V_2 = F_37 ( & V_30 -> V_35 ) ;
if ( ! V_2 )
return;
V_10 = (struct V_8 * ) V_41 ;
V_32 = V_10 ? V_10 -> V_32 : V_2 -> V_32 ;
if ( F_38 ( V_42 ) )
V_22 = V_45 ;
else if ( V_42 -> V_46 . V_23 . V_47 & V_48 ) {
V_10 -> V_22 = - V_49 ;
V_22 = V_50 ;
} else if ( V_42 -> V_46 . V_23 . V_51 == ( V_52 | V_53 |
V_54 ) ) {
F_39 ( V_34 , & V_2 -> V_6 ) ;
V_22 = V_55 ;
} else if ( F_2 ( V_34 , & V_2 -> V_6 ) ) {
if ( V_42 -> V_46 . V_23 . V_51 & V_53 ) {
F_40 ( V_34 , & V_2 -> V_6 ) ;
V_22 = V_45 ;
} else
V_22 = V_55 ;
} else if ( V_32 )
V_22 = V_32 -> V_56 -> V_57 ( V_32 , V_10 , V_42 ) ;
else
V_22 = V_50 ;
switch ( V_22 ) {
case V_50 :
break;
case V_55 :
return;
case V_45 :
if ( ! V_10 )
break;
V_10 -> V_22 = F_28 ( V_2 -> V_30 , & V_10 -> V_16 ,
( unsigned long ) V_10 , 0 , 0 ) ;
if ( V_10 -> V_22 == 0 )
return;
break;
case V_58 :
if ( ! V_10 )
break;
F_18 ( V_2 , V_10 ) ;
V_10 -> V_22 = - V_49 ;
break;
default:
F_41 () ;
}
if ( V_10 ) {
F_12 ( F_13 ( & V_10 -> V_15 ) ) ;
F_42 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_59 )
V_10 -> V_59 ( V_10 , V_10 -> V_60 ) ;
F_29 ( V_32 ) ;
}
while ( ! F_13 ( & V_2 -> V_33 ) ) {
V_10 = F_43 ( V_2 -> V_33 . V_61 , struct V_8 , V_15 ) ;
V_10 -> V_22 = F_28 ( V_2 -> V_30 , & V_10 -> V_16 ,
( unsigned long ) V_10 , 0 , 0 ) ;
if ( V_10 -> V_22 == 0 )
break;
F_42 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_59 )
V_10 -> V_59 ( V_10 , V_10 -> V_60 ) ;
F_29 ( V_32 ) ;
}
}
static int
F_44 ( struct V_31 * V_32 , struct V_8 * V_10 ,
struct V_42 * V_42 )
{
if ( V_42 -> V_46 . V_23 . V_51 & V_62 ) {
if ( V_42 -> V_63 [ 0 ] & V_64 ) {
F_39 ( V_34 , & V_32 -> V_35 -> V_6 ) ;
return V_55 ;
}
}
if ( V_10 ) {
if ( V_42 -> V_46 . V_23 . V_51 & V_62 ) {
if ( V_42 -> V_63 [ 0 ] & V_65 )
V_10 -> V_22 = - V_66 ;
else
V_10 -> V_22 = - V_49 ;
} else
V_10 -> V_21 = V_42 -> V_46 . V_23 . V_20 ;
}
if ( V_42 -> V_46 . V_23 . V_51 & V_67 ) {
F_39 ( V_68 , & V_32 -> V_35 -> V_6 ) ;
F_45 ( & V_69 ) ;
}
return V_50 ;
}
static void
F_46 ( struct V_8 * V_10 , void * V_24 )
{
F_45 ( ( V_70 * ) V_24 ) ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_8 * V_10 )
{
unsigned long V_6 ;
int V_22 ;
#ifdef F_48
if ( V_71 == 0 ) {
F_23 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
V_10 -> V_59 = NULL ;
V_22 = F_26 ( V_2 , V_32 , V_10 ) ;
if ( V_22 == 0 )
while ( ! F_19 ( V_10 ) ) {
F_49 () ;
F_50 () ;
}
F_25 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
return V_10 -> V_22 ;
}
#endif
V_10 -> V_59 = F_46 ;
V_10 -> V_60 = & V_69 ;
F_23 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
V_22 = F_26 ( V_2 , V_32 , V_10 ) ;
F_25 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_51 ( V_69 ,
F_19 ( V_10 ) ) ;
if ( V_22 == - V_72 ) {
F_22 ( V_32 -> V_35 , V_10 ) ;
F_52 ( V_69 , F_19 ( V_10 ) ) ;
return - V_72 ;
}
return V_10 -> V_22 ;
}
static int
F_53 ( struct V_1 * V_2 )
{
int V_22 , V_73 ;
struct V_74 V_75 ;
F_54 ( V_2 -> V_30 , & V_75 ) ;
V_76 . V_77 = V_75 . V_78 ;
V_76 . V_79 = sizeof( struct V_80 ) ;
V_22 = V_80 ( & V_76 ) ;
if ( V_22 )
return V_22 ;
V_73 = V_76 . V_81 ;
switch ( V_73 ) {
case 2 :
V_2 -> V_73 = V_73 ;
V_2 -> V_82 = 24 ;
V_2 -> V_83 = 80 ;
break;
case 3 :
V_2 -> V_73 = V_73 ;
V_2 -> V_82 = 32 ;
V_2 -> V_83 = 80 ;
break;
case 4 :
V_2 -> V_73 = V_73 ;
V_2 -> V_82 = 43 ;
V_2 -> V_83 = 80 ;
break;
case 5 :
V_2 -> V_73 = V_73 ;
V_2 -> V_82 = 27 ;
V_2 -> V_83 = 132 ;
break;
default:
V_22 = - V_66 ;
break;
}
return V_22 ;
}
static int
F_55 ( struct V_1 * V_2 )
{
static const unsigned char V_84 [] =
{ 0x00 , 0x07 , 0x01 , 0xff , 0x03 , 0x00 , 0x81 } ;
struct V_85 * V_86 ;
int V_22 ;
memset ( & V_2 -> V_87 , 0 , sizeof( V_2 -> V_87 ) ) ;
memset ( & V_2 -> V_88 , 0 , 256 ) ;
memcpy ( & V_2 -> V_88 , V_84 , sizeof( V_84 ) ) ;
F_8 ( & V_2 -> V_87 . V_15 ) ;
V_2 -> V_87 . V_16 . V_19 = V_89 ;
V_2 -> V_87 . V_16 . V_6 = V_18 ;
V_2 -> V_87 . V_16 . V_20 = sizeof( V_84 ) ;
V_2 -> V_87 . V_16 . V_17 = ( V_90 ) F_9 ( & V_2 -> V_88 ) ;
V_22 = F_47 ( V_2 , & V_91 , & V_2 -> V_87 ) ;
if ( V_22 )
return V_22 ;
#ifdef F_48
if ( V_71 == 0 ) {
unsigned long V_6 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
while ( ! F_56 ( V_68 , & V_2 -> V_6 ) )
F_49 () ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
} else
#endif
V_22 = F_51 ( V_69 ,
F_56 ( V_68 , & V_2 -> V_6 ) ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_87 . V_16 . V_19 = V_92 ;
V_2 -> V_87 . V_16 . V_6 = V_18 ;
V_2 -> V_87 . V_16 . V_20 = sizeof( V_2 -> V_88 ) ;
V_2 -> V_87 . V_16 . V_17 = ( V_90 ) F_9 ( V_2 -> V_88 ) ;
V_22 = F_47 ( V_2 , & V_91 , & V_2 -> V_87 ) ;
if ( V_22 )
return V_22 ;
V_86 = (struct V_85 * ) ( V_2 -> V_88 + 1 ) ;
if ( V_2 -> V_88 [ 0 ] != 0x88 || V_86 -> V_93 . V_94 != 0x81 )
return - V_66 ;
V_2 -> V_82 = V_86 -> V_93 . V_95 ;
V_2 -> V_83 = V_86 -> V_93 . V_96 ;
if ( ( V_86 -> V_93 . V_97 & 0x0d ) == 0x01 )
F_39 ( V_5 , & V_2 -> V_6 ) ;
if ( V_86 -> V_93 . V_98 == sizeof( struct V_85 ) &&
V_86 -> V_99 . V_100 == 0x02 ) {
V_2 -> V_82 = V_86 -> V_99 . V_101 ;
V_2 -> V_83 = V_86 -> V_99 . V_102 ;
}
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 )
{
int V_22 ;
F_58 ( & V_103 ) ;
V_2 -> V_32 = & V_91 ;
V_91 . V_35 = V_2 ;
if ( V_104 )
V_22 = F_53 ( V_2 ) ;
else
V_22 = F_55 ( V_2 ) ;
V_91 . V_35 = NULL ;
V_2 -> V_32 = NULL ;
F_59 ( & V_103 ) ;
if ( V_22 == 0 ) {
V_2 -> V_73 = 0 ;
if ( V_2 -> V_82 == 24 && V_2 -> V_83 == 80 )
V_2 -> V_73 = 2 ;
if ( V_2 -> V_82 == 32 && V_2 -> V_83 == 80 )
V_2 -> V_73 = 3 ;
if ( V_2 -> V_82 == 43 && V_2 -> V_83 == 80 )
V_2 -> V_73 = 4 ;
if ( V_2 -> V_82 == 27 && V_2 -> V_83 == 132 )
V_2 -> V_73 = 5 ;
} else {
V_2 -> V_73 = 2 ;
V_2 -> V_82 = 24 ;
V_2 -> V_83 = 80 ;
return 0 ;
}
return V_22 ;
}
static int
F_60 ( struct V_1 * V_2 )
{
int V_22 ;
F_58 ( & V_103 ) ;
memset ( & V_2 -> V_87 , 0 , sizeof( V_2 -> V_87 ) ) ;
memset ( & V_2 -> V_88 , 0 , sizeof( V_2 -> V_88 ) ) ;
V_2 -> V_88 [ 0 ] = V_105 ;
F_8 ( & V_2 -> V_87 . V_15 ) ;
V_2 -> V_87 . V_16 . V_19 = V_106 ;
V_2 -> V_87 . V_16 . V_6 = V_18 ;
V_2 -> V_87 . V_16 . V_20 = 1 ;
V_2 -> V_87 . V_16 . V_17 = ( V_90 ) F_9 ( V_2 -> V_88 ) ;
V_2 -> V_32 = & V_91 ;
V_91 . V_35 = V_2 ;
V_22 = F_47 ( V_2 , & V_91 , & V_2 -> V_87 ) ;
V_91 . V_35 = NULL ;
V_2 -> V_32 = NULL ;
F_59 ( & V_103 ) ;
return V_22 ;
}
int
F_61 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = V_32 -> V_35 ;
if ( ! V_2 || V_2 -> V_32 != V_32 ||
F_2 ( V_36 , & V_2 -> V_6 ) )
V_22 = - V_37 ;
else if ( ! F_2 ( V_38 , & V_2 -> V_6 ) )
V_22 = - V_39 ;
else
V_22 = F_60 ( V_32 -> V_35 ) ;
return V_22 ;
}
static int
F_62 ( struct V_40 * V_30 , struct V_1 * V_2 , char * V_107 )
{
struct V_108 * V_98 ;
struct V_1 * V_109 ;
int V_110 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
memcpy ( V_107 , V_111 , 256 ) ;
if ( V_112 ) {
V_107 [ '[' ] = 0xad ;
V_107 [ ']' ] = 0xbd ;
V_107 [ '^' ] = 0xb0 ;
}
V_2 -> V_107 = V_107 ;
V_2 -> V_82 = 24 ;
V_2 -> V_83 = 80 ;
F_8 ( & V_2 -> V_33 ) ;
F_8 ( & V_2 -> V_113 ) ;
F_58 ( & V_114 ) ;
V_110 = V_115 ;
V_2 -> V_110 = - 1 ;
F_63 (l, &raw3270_devices) {
V_109 = F_43 ( V_98 , struct V_1 , V_15 ) ;
if ( V_109 -> V_110 > V_110 ) {
V_2 -> V_110 = V_110 ;
F_64 ( & V_2 -> V_15 , V_98 -> V_116 , V_98 ) ;
break;
}
V_110 ++ ;
}
if ( V_2 -> V_110 == - 1 && V_110 < V_117 + V_115 ) {
V_2 -> V_110 = V_110 ;
F_30 ( & V_2 -> V_15 , & V_118 ) ;
}
F_59 ( & V_114 ) ;
if ( V_2 -> V_110 == - 1 )
return - V_119 ;
V_2 -> V_30 = V_30 ;
F_65 ( & V_30 -> V_35 , V_2 ) ;
V_30 -> V_120 = F_34 ;
return 0 ;
}
struct V_1 T_3 * F_66 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
char * V_107 ;
int V_22 ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_11 | V_12 ) ;
V_107 = F_4 ( 256 , V_11 ) ;
V_22 = F_62 ( V_30 , V_2 , V_107 ) ;
if ( V_22 )
return F_5 ( V_22 ) ;
F_39 ( V_121 , & V_2 -> V_6 ) ;
V_22 = F_60 ( V_2 ) ;
if ( V_22 )
return F_5 ( V_22 ) ;
V_22 = F_57 ( V_2 ) ;
if ( V_22 )
return F_5 ( V_22 ) ;
V_22 = F_60 ( V_2 ) ;
if ( V_22 )
return F_5 ( V_22 ) ;
F_39 ( V_38 , & V_2 -> V_6 ) ;
return V_2 ;
}
void
F_67 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
F_49 () ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
}
static struct V_1 *
F_68 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
char * V_107 ;
int V_22 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_11 | V_12 ) ;
if ( ! V_2 )
return F_5 ( - V_13 ) ;
V_107 = F_6 ( 256 , V_11 ) ;
if ( ! V_107 ) {
F_7 ( V_2 ) ;
return F_5 ( - V_13 ) ;
}
V_22 = F_62 ( V_30 , V_2 , V_107 ) ;
if ( V_22 ) {
F_7 ( V_2 -> V_107 ) ;
F_7 ( V_2 ) ;
V_2 = F_5 ( V_22 ) ;
}
F_69 ( & V_30 -> V_35 ) ;
return V_2 ;
}
int
F_70 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_31 * V_122 , * V_123 ;
unsigned long V_6 ;
int V_22 ;
V_2 = V_32 -> V_35 ;
if ( ! V_2 )
return - V_39 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( V_2 -> V_32 == V_32 )
V_22 = 0 ;
else if ( ! F_2 ( V_38 , & V_2 -> V_6 ) )
V_22 = - V_39 ;
else if ( F_2 ( V_36 , & V_2 -> V_6 ) )
V_22 = - V_37 ;
else {
V_122 = NULL ;
if ( V_2 -> V_32 ) {
V_122 = V_2 -> V_32 ;
V_122 -> V_56 -> V_124 ( V_122 ) ;
}
V_2 -> V_32 = V_32 ;
V_22 = V_32 -> V_56 -> V_125 ( V_32 ) ;
if ( V_22 ) {
V_2 -> V_32 = V_122 ;
if ( ! V_122 || V_122 -> V_56 -> V_125 ( V_122 ) != 0 ) {
F_71 (nv, &rp->view_list, list)
if ( V_123 != V_32 && V_123 != V_122 ) {
V_2 -> V_32 = V_123 ;
if ( V_123 -> V_56 -> V_125 ( V_123 ) == 0 )
break;
V_2 -> V_32 = NULL ;
}
}
}
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
return V_22 ;
}
void
F_72 ( struct V_31 * V_32 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
V_2 = V_32 -> V_35 ;
if ( ! V_2 )
return;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( V_2 -> V_32 == V_32 ) {
V_32 -> V_56 -> V_124 ( V_32 ) ;
V_2 -> V_32 = NULL ;
F_42 ( & V_32 -> V_15 ) ;
F_30 ( & V_32 -> V_15 , & V_2 -> V_113 ) ;
if ( F_2 ( V_38 , & V_2 -> V_6 ) &&
! F_2 ( V_36 , & V_2 -> V_6 ) ) {
F_71 (view, &rp->view_list, list) {
V_2 -> V_32 = V_32 ;
if ( V_32 -> V_56 -> V_125 ( V_32 ) == 0 )
break;
V_2 -> V_32 = NULL ;
}
}
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
}
int
F_73 ( struct V_31 * V_32 , struct V_126 * V_56 , int V_110 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_110 <= 0 )
return - V_39 ;
F_58 ( & V_114 ) ;
V_22 = - V_39 ;
F_71 (rp, &raw3270_devices, list) {
if ( V_2 -> V_110 != V_110 )
continue;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( F_2 ( V_38 , & V_2 -> V_6 ) ) {
F_74 ( & V_32 -> V_127 , 2 ) ;
V_32 -> V_35 = V_2 ;
V_32 -> V_56 = V_56 ;
V_32 -> V_73 = V_2 -> V_73 ;
V_32 -> V_82 = V_2 -> V_82 ;
V_32 -> V_83 = V_2 -> V_83 ;
V_32 -> V_107 = V_2 -> V_107 ;
F_75 ( & V_32 -> V_128 ) ;
F_76 ( & V_32 -> V_15 , & V_2 -> V_113 ) ;
V_22 = 0 ;
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
break;
}
F_59 ( & V_114 ) ;
return V_22 ;
}
struct V_31 *
F_77 ( struct V_126 * V_56 , int V_110 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 , * V_109 ;
unsigned long V_6 ;
F_58 ( & V_114 ) ;
V_32 = F_5 ( - V_39 ) ;
F_71 (rp, &raw3270_devices, list) {
if ( V_2 -> V_110 != V_110 )
continue;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( F_2 ( V_38 , & V_2 -> V_6 ) ) {
V_32 = F_5 ( - V_129 ) ;
F_71 (tmp, &rp->view_list, list) {
if ( V_109 -> V_56 == V_56 ) {
F_27 ( V_109 ) ;
V_32 = V_109 ;
break;
}
}
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
break;
}
F_59 ( & V_114 ) ;
return V_32 ;
}
void
F_78 ( struct V_31 * V_32 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
struct V_31 * V_123 ;
V_2 = V_32 -> V_35 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( V_2 -> V_32 == V_32 ) {
V_32 -> V_56 -> V_124 ( V_32 ) ;
V_2 -> V_32 = NULL ;
}
F_42 ( & V_32 -> V_15 ) ;
if ( ! V_2 -> V_32 && F_2 ( V_38 , & V_2 -> V_6 ) &&
! F_2 ( V_36 , & V_2 -> V_6 ) ) {
F_71 (nv, &rp->view_list, list) {
if ( V_123 -> V_56 -> V_125 ( V_123 ) == 0 ) {
V_2 -> V_32 = V_123 ;
break;
}
}
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
F_79 ( & V_32 -> V_127 ) ;
F_52 ( V_69 , F_80 ( & V_32 -> V_127 ) == 0 ) ;
if ( V_32 -> V_56 -> free )
V_32 -> V_56 -> free ( V_32 ) ;
}
static void
F_81 ( struct V_1 * V_2 )
{
struct V_40 * V_30 ;
F_58 ( & V_114 ) ;
if ( V_2 -> V_130 && ! F_38 ( V_2 -> V_130 ) )
F_82 ( V_131 , F_83 ( V_132 , V_2 -> V_110 ) ) ;
if ( V_2 -> V_133 && ! F_38 ( V_2 -> V_133 ) )
F_82 ( V_131 , F_83 ( V_134 , V_2 -> V_110 ) ) ;
F_42 ( & V_2 -> V_15 ) ;
F_59 ( & V_114 ) ;
V_30 = V_2 -> V_30 ;
V_2 -> V_30 = NULL ;
F_65 ( & V_30 -> V_35 , NULL ) ;
V_30 -> V_120 = NULL ;
F_84 ( & V_30 -> V_35 ) ;
F_7 ( V_2 -> V_107 ) ;
F_7 ( V_2 ) ;
}
static int
F_85 ( struct V_40 * V_30 )
{
return 0 ;
}
static T_4
F_86 ( struct V_135 * V_35 , struct V_136 * V_137 , char * V_138 )
{
return snprintf ( V_138 , V_139 , L_1 ,
( (struct V_1 * ) F_37 ( V_35 ) ) -> V_73 ) ;
}
static T_4
F_87 ( struct V_135 * V_35 , struct V_136 * V_137 , char * V_138 )
{
return snprintf ( V_138 , V_139 , L_1 ,
( (struct V_1 * ) F_37 ( V_35 ) ) -> V_82 ) ;
}
static T_4
F_88 ( struct V_135 * V_35 , struct V_136 * V_137 , char * V_138 )
{
return snprintf ( V_138 , V_139 , L_1 ,
( (struct V_1 * ) F_37 ( V_35 ) ) -> V_83 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_90 ( & V_2 -> V_30 -> V_35 . V_140 , & V_141 ) ;
if ( V_22 )
goto V_142;
V_2 -> V_130 = F_91 ( V_131 , & V_2 -> V_30 -> V_35 ,
F_83 ( V_132 , V_2 -> V_110 ) , NULL ,
L_2 , F_92 ( & V_2 -> V_30 -> V_35 ) ) ;
if ( F_38 ( V_2 -> V_130 ) ) {
V_22 = F_93 ( V_2 -> V_130 ) ;
goto V_143;
}
V_2 -> V_133 = F_91 ( V_131 , & V_2 -> V_30 -> V_35 ,
F_83 ( V_134 , V_2 -> V_110 ) , NULL ,
L_3 , F_92 ( & V_2 -> V_30 -> V_35 ) ) ;
if ( ! F_38 ( V_2 -> V_133 ) )
goto V_142;
V_22 = F_93 ( V_2 -> V_133 ) ;
F_82 ( V_131 , F_83 ( V_132 , V_2 -> V_110 ) ) ;
V_143:
F_94 ( & V_2 -> V_30 -> V_35 . V_140 , & V_141 ) ;
V_142:
return V_22 ;
}
int F_95 ( void (* F_96)( int , int ) )
{
struct V_144 * V_145 ;
struct V_1 * V_2 ;
V_145 = F_6 ( sizeof( struct V_144 ) , V_11 ) ;
if ( ! V_145 )
return - V_13 ;
V_145 -> F_96 = F_96 ;
F_58 ( & V_114 ) ;
F_30 ( & V_145 -> V_15 , & V_144 ) ;
F_71 (rp, &raw3270_devices, list) {
F_69 ( & V_2 -> V_30 -> V_35 ) ;
F_96 ( V_2 -> V_110 , 1 ) ;
}
F_59 ( & V_114 ) ;
return 0 ;
}
void F_97 ( void (* F_96)( int , int ) )
{
struct V_144 * V_145 ;
F_58 ( & V_114 ) ;
F_71 (np, &raw3270_notifier, list)
if ( V_145 -> F_96 == F_96 ) {
F_98 ( & V_145 -> V_15 ) ;
F_7 ( V_145 ) ;
break;
}
F_59 ( & V_114 ) ;
}
static int
F_99 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
struct V_144 * V_145 ;
int V_22 ;
V_2 = F_68 ( V_30 ) ;
if ( F_38 ( V_2 ) )
return F_93 ( V_2 ) ;
V_22 = F_60 ( V_2 ) ;
if ( V_22 )
goto V_146;
V_22 = F_57 ( V_2 ) ;
if ( V_22 )
goto V_146;
V_22 = F_60 ( V_2 ) ;
if ( V_22 )
goto V_146;
V_22 = F_89 ( V_2 ) ;
if ( V_22 )
goto V_146;
F_39 ( V_38 , & V_2 -> V_6 ) ;
F_58 ( & V_114 ) ;
F_71 (np, &raw3270_notifier, list)
V_145 -> F_96 ( V_2 -> V_110 , 1 ) ;
F_59 ( & V_114 ) ;
return 0 ;
V_146:
F_81 ( V_2 ) ;
return V_22 ;
}
static void
F_100 ( struct V_40 * V_30 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
struct V_31 * V_147 ;
struct V_144 * V_145 ;
V_2 = F_37 ( & V_30 -> V_35 ) ;
if ( V_2 == NULL )
return;
F_40 ( V_38 , & V_2 -> V_6 ) ;
F_94 ( & V_30 -> V_35 . V_140 , & V_141 ) ;
F_23 ( F_24 ( V_30 ) , V_6 ) ;
if ( V_2 -> V_32 ) {
V_2 -> V_32 -> V_56 -> V_124 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
}
while ( ! F_13 ( & V_2 -> V_113 ) ) {
V_147 = F_43 ( V_2 -> V_113 . V_61 , struct V_31 , V_15 ) ;
if ( V_147 -> V_56 -> V_148 )
V_147 -> V_56 -> V_148 ( V_147 ) ;
F_25 ( F_24 ( V_30 ) , V_6 ) ;
F_78 ( V_147 ) ;
F_23 ( F_24 ( V_30 ) , V_6 ) ;
}
F_25 ( F_24 ( V_30 ) , V_6 ) ;
F_58 ( & V_114 ) ;
F_71 (np, &raw3270_notifier, list)
V_145 -> F_96 ( V_2 -> V_110 , 0 ) ;
F_59 ( & V_114 ) ;
F_60 ( V_2 ) ;
F_81 ( V_2 ) ;
}
static int
F_101 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( & V_30 -> V_35 ) ;
if ( F_2 ( V_121 , & V_2 -> V_6 ) )
return - V_149 ;
F_100 ( V_30 ) ;
return 0 ;
}
static int F_102 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
unsigned long V_6 ;
V_2 = F_37 ( & V_30 -> V_35 ) ;
if ( ! V_2 )
return 0 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( V_2 -> V_32 )
V_2 -> V_32 -> V_56 -> V_124 ( V_2 -> V_32 ) ;
if ( ! F_2 ( V_121 , & V_2 -> V_6 ) ) {
F_71 (view, &rp->view_list, list) {
if ( V_32 -> V_56 -> V_148 )
V_32 -> V_56 -> V_148 ( V_32 ) ;
}
}
F_39 ( V_36 , & V_2 -> V_6 ) ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
return 0 ;
}
static int F_103 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
unsigned long V_6 ;
V_2 = F_37 ( & V_30 -> V_35 ) ;
if ( ! V_2 )
return 0 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
F_40 ( V_36 , & V_2 -> V_6 ) ;
if ( V_2 -> V_32 )
V_2 -> V_32 -> V_56 -> V_125 ( V_2 -> V_32 ) ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
return 0 ;
}
void F_104 ( struct V_31 * V_32 )
{
#ifdef F_48
struct V_1 * V_2 ;
V_2 = V_32 -> V_35 ;
if ( V_2 && F_2 ( V_36 , & V_2 -> V_6 ) )
F_105 () ;
#endif
}
static int
F_106 ( void )
{
struct V_1 * V_2 ;
int V_22 ;
if ( V_71 )
return 0 ;
V_71 = 1 ;
V_22 = F_107 ( & V_150 ) ;
if ( V_22 == 0 ) {
F_58 ( & V_114 ) ;
V_131 = F_108 ( V_151 , L_4 ) ;
F_71 (rp, &raw3270_devices, list) {
F_69 ( & V_2 -> V_30 -> V_35 ) ;
F_89 ( V_2 ) ;
}
F_59 ( & V_114 ) ;
}
return V_22 ;
}
static void
F_109 ( void )
{
F_110 ( & V_150 ) ;
F_111 ( V_131 ) ;
}
