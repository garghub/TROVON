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
V_2 = F_35 ( & V_30 -> V_35 ) ;
if ( ! V_2 )
return;
V_10 = (struct V_8 * ) V_41 ;
V_32 = V_10 ? V_10 -> V_32 : V_2 -> V_32 ;
if ( F_36 ( V_42 ) )
V_22 = V_43 ;
else if ( V_42 -> V_44 . V_23 . V_45 & V_46 ) {
V_10 -> V_22 = - V_47 ;
V_22 = V_48 ;
} else if ( V_42 -> V_44 . V_23 . V_49 == ( V_50 | V_51 |
V_52 ) ) {
F_37 ( V_34 , & V_2 -> V_6 ) ;
V_22 = V_53 ;
} else if ( F_2 ( V_34 , & V_2 -> V_6 ) ) {
if ( V_42 -> V_44 . V_23 . V_49 & V_51 ) {
F_38 ( V_34 , & V_2 -> V_6 ) ;
V_22 = V_43 ;
} else
V_22 = V_53 ;
} else if ( V_32 )
V_22 = V_32 -> V_54 -> V_55 ( V_32 , V_10 , V_42 ) ;
else
V_22 = V_48 ;
switch ( V_22 ) {
case V_48 :
break;
case V_53 :
return;
case V_43 :
if ( ! V_10 )
break;
V_10 -> V_22 = F_28 ( V_2 -> V_30 , & V_10 -> V_16 ,
( unsigned long ) V_10 , 0 , 0 ) ;
if ( V_10 -> V_22 == 0 )
return;
break;
case V_56 :
if ( ! V_10 )
break;
F_18 ( V_2 , V_10 ) ;
V_10 -> V_22 = - V_47 ;
break;
default:
F_39 () ;
}
if ( V_10 ) {
F_12 ( F_13 ( & V_10 -> V_15 ) ) ;
F_40 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_57 )
V_10 -> V_57 ( V_10 , V_10 -> V_58 ) ;
F_29 ( V_32 ) ;
}
while ( ! F_13 ( & V_2 -> V_33 ) ) {
V_10 = F_41 ( V_2 -> V_33 . V_59 , struct V_8 , V_15 ) ;
V_10 -> V_22 = F_28 ( V_2 -> V_30 , & V_10 -> V_16 ,
( unsigned long ) V_10 , 0 , 0 ) ;
if ( V_10 -> V_22 == 0 )
break;
F_40 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_57 )
V_10 -> V_57 ( V_10 , V_10 -> V_58 ) ;
F_29 ( V_32 ) ;
}
}
static int
F_42 ( struct V_31 * V_32 , struct V_8 * V_10 ,
struct V_42 * V_42 )
{
if ( V_42 -> V_44 . V_23 . V_49 & V_60 ) {
if ( V_42 -> V_61 [ 0 ] & V_62 ) {
F_37 ( V_34 , & V_32 -> V_35 -> V_6 ) ;
return V_53 ;
}
}
if ( V_10 ) {
if ( V_42 -> V_44 . V_23 . V_49 & V_60 ) {
if ( V_42 -> V_61 [ 0 ] & V_63 )
V_10 -> V_22 = - V_64 ;
else
V_10 -> V_22 = - V_47 ;
} else
V_10 -> V_21 = V_42 -> V_44 . V_23 . V_20 ;
}
if ( V_42 -> V_44 . V_23 . V_49 & V_65 ) {
F_37 ( V_66 , & V_32 -> V_35 -> V_6 ) ;
F_43 ( & V_67 ) ;
}
return V_48 ;
}
static void
F_44 ( struct V_8 * V_10 , void * V_24 )
{
F_43 ( ( V_68 * ) V_24 ) ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_8 * V_10 )
{
unsigned long V_6 ;
int V_22 ;
#ifdef F_46
if ( V_69 == 0 ) {
F_23 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
V_10 -> V_57 = NULL ;
V_22 = F_26 ( V_2 , V_32 , V_10 ) ;
if ( V_22 == 0 )
while ( ! F_19 ( V_10 ) ) {
F_47 () ;
F_48 () ;
}
F_25 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
return V_10 -> V_22 ;
}
#endif
V_10 -> V_57 = F_44 ;
V_10 -> V_58 = & V_67 ;
F_23 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
V_22 = F_26 ( V_2 , V_32 , V_10 ) ;
F_25 ( F_24 ( V_32 -> V_35 -> V_30 ) , V_6 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_49 ( V_67 ,
F_19 ( V_10 ) ) ;
if ( V_22 == - V_70 ) {
F_22 ( V_32 -> V_35 , V_10 ) ;
F_50 ( V_67 , F_19 ( V_10 ) ) ;
return - V_70 ;
}
return V_10 -> V_22 ;
}
static int
F_51 ( struct V_1 * V_2 )
{
int V_22 , V_71 ;
struct V_72 V_73 ;
F_52 ( V_2 -> V_30 , & V_73 ) ;
V_74 . V_75 = V_73 . V_76 ;
V_74 . V_77 = sizeof( struct V_78 ) ;
V_22 = V_78 ( & V_74 ) ;
if ( V_22 )
return V_22 ;
V_71 = V_74 . V_79 ;
switch ( V_71 ) {
case 2 :
V_2 -> V_71 = V_71 ;
V_2 -> V_80 = 24 ;
V_2 -> V_81 = 80 ;
break;
case 3 :
V_2 -> V_71 = V_71 ;
V_2 -> V_80 = 32 ;
V_2 -> V_81 = 80 ;
break;
case 4 :
V_2 -> V_71 = V_71 ;
V_2 -> V_80 = 43 ;
V_2 -> V_81 = 80 ;
break;
case 5 :
V_2 -> V_71 = V_71 ;
V_2 -> V_80 = 27 ;
V_2 -> V_81 = 132 ;
break;
default:
V_22 = - V_64 ;
break;
}
return V_22 ;
}
static int
F_53 ( struct V_1 * V_2 )
{
static const unsigned char V_82 [] =
{ 0x00 , 0x07 , 0x01 , 0xff , 0x03 , 0x00 , 0x81 } ;
struct V_83 * V_84 ;
int V_22 ;
memset ( & V_2 -> V_85 , 0 , sizeof( V_2 -> V_85 ) ) ;
memset ( & V_2 -> V_86 , 0 , 256 ) ;
memcpy ( & V_2 -> V_86 , V_82 , sizeof( V_82 ) ) ;
F_8 ( & V_2 -> V_85 . V_15 ) ;
V_2 -> V_85 . V_16 . V_19 = V_87 ;
V_2 -> V_85 . V_16 . V_6 = V_18 ;
V_2 -> V_85 . V_16 . V_20 = sizeof( V_82 ) ;
V_2 -> V_85 . V_16 . V_17 = ( V_88 ) F_9 ( & V_2 -> V_86 ) ;
V_22 = F_45 ( V_2 , & V_89 , & V_2 -> V_85 ) ;
if ( V_22 )
return V_22 ;
#ifdef F_46
if ( V_69 == 0 ) {
unsigned long V_6 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
while ( ! F_54 ( V_66 , & V_2 -> V_6 ) )
F_47 () ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
} else
#endif
V_22 = F_49 ( V_67 ,
F_54 ( V_66 , & V_2 -> V_6 ) ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_85 . V_16 . V_19 = V_90 ;
V_2 -> V_85 . V_16 . V_6 = V_18 ;
V_2 -> V_85 . V_16 . V_20 = sizeof( V_2 -> V_86 ) ;
V_2 -> V_85 . V_16 . V_17 = ( V_88 ) F_9 ( V_2 -> V_86 ) ;
V_22 = F_45 ( V_2 , & V_89 , & V_2 -> V_85 ) ;
if ( V_22 )
return V_22 ;
V_84 = (struct V_83 * ) ( V_2 -> V_86 + 1 ) ;
if ( V_2 -> V_86 [ 0 ] != 0x88 || V_84 -> V_91 . V_92 != 0x81 )
return - V_64 ;
V_2 -> V_80 = V_84 -> V_91 . V_93 ;
V_2 -> V_81 = V_84 -> V_91 . V_94 ;
if ( ( V_84 -> V_91 . V_95 & 0x0d ) == 0x01 )
F_37 ( V_5 , & V_2 -> V_6 ) ;
if ( V_84 -> V_91 . V_96 == sizeof( struct V_83 ) &&
V_84 -> V_97 . V_98 == 0x02 ) {
V_2 -> V_80 = V_84 -> V_97 . V_99 ;
V_2 -> V_81 = V_84 -> V_97 . V_100 ;
}
return 0 ;
}
static int
F_55 ( struct V_1 * V_2 )
{
int V_22 ;
F_56 ( & V_101 ) ;
V_2 -> V_32 = & V_89 ;
V_89 . V_35 = V_2 ;
if ( V_102 )
V_22 = F_51 ( V_2 ) ;
else
V_22 = F_53 ( V_2 ) ;
V_89 . V_35 = NULL ;
V_2 -> V_32 = NULL ;
F_57 ( & V_101 ) ;
if ( V_22 == 0 ) {
V_2 -> V_71 = 0 ;
if ( V_2 -> V_80 == 24 && V_2 -> V_81 == 80 )
V_2 -> V_71 = 2 ;
if ( V_2 -> V_80 == 32 && V_2 -> V_81 == 80 )
V_2 -> V_71 = 3 ;
if ( V_2 -> V_80 == 43 && V_2 -> V_81 == 80 )
V_2 -> V_71 = 4 ;
if ( V_2 -> V_80 == 27 && V_2 -> V_81 == 132 )
V_2 -> V_71 = 5 ;
} else {
V_2 -> V_71 = 2 ;
V_2 -> V_80 = 24 ;
V_2 -> V_81 = 80 ;
return 0 ;
}
return V_22 ;
}
static int
F_58 ( struct V_1 * V_2 )
{
int V_22 ;
F_56 ( & V_101 ) ;
memset ( & V_2 -> V_85 , 0 , sizeof( V_2 -> V_85 ) ) ;
memset ( & V_2 -> V_86 , 0 , sizeof( V_2 -> V_86 ) ) ;
V_2 -> V_86 [ 0 ] = V_103 ;
F_8 ( & V_2 -> V_85 . V_15 ) ;
V_2 -> V_85 . V_16 . V_19 = V_104 ;
V_2 -> V_85 . V_16 . V_6 = V_18 ;
V_2 -> V_85 . V_16 . V_20 = 1 ;
V_2 -> V_85 . V_16 . V_17 = ( V_88 ) F_9 ( V_2 -> V_86 ) ;
V_2 -> V_32 = & V_89 ;
V_89 . V_35 = V_2 ;
V_22 = F_45 ( V_2 , & V_89 , & V_2 -> V_85 ) ;
V_89 . V_35 = NULL ;
V_2 -> V_32 = NULL ;
F_57 ( & V_101 ) ;
return V_22 ;
}
int
F_59 ( struct V_31 * V_32 )
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
V_22 = F_58 ( V_32 -> V_35 ) ;
return V_22 ;
}
static int
F_60 ( struct V_40 * V_30 , struct V_1 * V_2 , char * V_105 )
{
struct V_106 * V_96 ;
struct V_1 * V_107 ;
int V_108 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
memcpy ( V_105 , V_109 , 256 ) ;
if ( V_110 ) {
V_105 [ '[' ] = 0xad ;
V_105 [ ']' ] = 0xbd ;
V_105 [ '^' ] = 0xb0 ;
}
V_2 -> V_105 = V_105 ;
V_2 -> V_80 = 24 ;
V_2 -> V_81 = 80 ;
F_8 ( & V_2 -> V_33 ) ;
F_8 ( & V_2 -> V_111 ) ;
F_56 ( & V_112 ) ;
V_108 = V_113 ;
V_2 -> V_108 = - 1 ;
F_61 (l, &raw3270_devices) {
V_107 = F_41 ( V_96 , struct V_1 , V_15 ) ;
if ( V_107 -> V_108 > V_108 ) {
V_2 -> V_108 = V_108 ;
F_62 ( & V_2 -> V_15 , V_96 -> V_114 , V_96 ) ;
break;
}
V_108 ++ ;
}
if ( V_2 -> V_108 == - 1 && V_108 < V_115 + V_113 ) {
V_2 -> V_108 = V_108 ;
F_30 ( & V_2 -> V_15 , & V_116 ) ;
}
F_57 ( & V_112 ) ;
if ( V_2 -> V_108 == - 1 )
return - V_117 ;
V_2 -> V_30 = V_30 ;
F_63 ( & V_30 -> V_35 , V_2 ) ;
V_30 -> V_118 = F_34 ;
return 0 ;
}
struct V_1 T_3 * F_64 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
char * V_105 ;
int V_22 ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_11 | V_12 ) ;
V_105 = F_4 ( 256 , V_11 ) ;
V_22 = F_60 ( V_30 , V_2 , V_105 ) ;
if ( V_22 )
return F_5 ( V_22 ) ;
F_37 ( V_119 , & V_2 -> V_6 ) ;
V_22 = F_58 ( V_2 ) ;
if ( V_22 )
return F_5 ( V_22 ) ;
V_22 = F_55 ( V_2 ) ;
if ( V_22 )
return F_5 ( V_22 ) ;
V_22 = F_58 ( V_2 ) ;
if ( V_22 )
return F_5 ( V_22 ) ;
F_37 ( V_38 , & V_2 -> V_6 ) ;
return V_2 ;
}
void
F_65 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
F_47 () ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
}
static struct V_1 *
F_66 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
char * V_105 ;
int V_22 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_11 | V_12 ) ;
if ( ! V_2 )
return F_5 ( - V_13 ) ;
V_105 = F_6 ( 256 , V_11 ) ;
if ( ! V_105 ) {
F_7 ( V_2 ) ;
return F_5 ( - V_13 ) ;
}
V_22 = F_60 ( V_30 , V_2 , V_105 ) ;
if ( V_22 ) {
F_7 ( V_2 -> V_105 ) ;
F_7 ( V_2 ) ;
V_2 = F_5 ( V_22 ) ;
}
F_67 ( & V_30 -> V_35 ) ;
return V_2 ;
}
int
F_68 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_31 * V_120 , * V_121 ;
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
V_120 = NULL ;
if ( V_2 -> V_32 ) {
V_120 = V_2 -> V_32 ;
V_120 -> V_54 -> V_122 ( V_120 ) ;
}
V_2 -> V_32 = V_32 ;
V_22 = V_32 -> V_54 -> V_123 ( V_32 ) ;
if ( V_22 ) {
V_2 -> V_32 = V_120 ;
if ( ! V_120 || V_120 -> V_54 -> V_123 ( V_120 ) != 0 ) {
F_69 (nv, &rp->view_list, list)
if ( V_121 != V_32 && V_121 != V_120 ) {
V_2 -> V_32 = V_121 ;
if ( V_121 -> V_54 -> V_123 ( V_121 ) == 0 )
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
F_70 ( struct V_31 * V_32 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
V_2 = V_32 -> V_35 ;
if ( ! V_2 )
return;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( V_2 -> V_32 == V_32 ) {
V_32 -> V_54 -> V_122 ( V_32 ) ;
V_2 -> V_32 = NULL ;
F_40 ( & V_32 -> V_15 ) ;
F_30 ( & V_32 -> V_15 , & V_2 -> V_111 ) ;
if ( F_2 ( V_38 , & V_2 -> V_6 ) &&
! F_2 ( V_36 , & V_2 -> V_6 ) ) {
F_69 (view, &rp->view_list, list) {
V_2 -> V_32 = V_32 ;
if ( V_32 -> V_54 -> V_123 ( V_32 ) == 0 )
break;
V_2 -> V_32 = NULL ;
}
}
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
}
int
F_71 ( struct V_31 * V_32 , struct V_124 * V_54 , int V_108 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_108 <= 0 )
return - V_39 ;
F_56 ( & V_112 ) ;
V_22 = - V_39 ;
F_69 (rp, &raw3270_devices, list) {
if ( V_2 -> V_108 != V_108 )
continue;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( F_2 ( V_38 , & V_2 -> V_6 ) ) {
F_72 ( & V_32 -> V_125 , 2 ) ;
V_32 -> V_35 = V_2 ;
V_32 -> V_54 = V_54 ;
V_32 -> V_71 = V_2 -> V_71 ;
V_32 -> V_80 = V_2 -> V_80 ;
V_32 -> V_81 = V_2 -> V_81 ;
V_32 -> V_105 = V_2 -> V_105 ;
F_73 ( & V_32 -> V_126 ) ;
F_74 ( & V_32 -> V_15 , & V_2 -> V_111 ) ;
V_22 = 0 ;
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
break;
}
F_57 ( & V_112 ) ;
return V_22 ;
}
struct V_31 *
F_75 ( struct V_124 * V_54 , int V_108 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 , * V_107 ;
unsigned long V_6 ;
F_56 ( & V_112 ) ;
V_32 = F_5 ( - V_39 ) ;
F_69 (rp, &raw3270_devices, list) {
if ( V_2 -> V_108 != V_108 )
continue;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( F_2 ( V_38 , & V_2 -> V_6 ) ) {
V_32 = F_5 ( - V_127 ) ;
F_69 (tmp, &rp->view_list, list) {
if ( V_107 -> V_54 == V_54 ) {
F_27 ( V_107 ) ;
V_32 = V_107 ;
break;
}
}
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
break;
}
F_57 ( & V_112 ) ;
return V_32 ;
}
void
F_76 ( struct V_31 * V_32 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
struct V_31 * V_121 ;
V_2 = V_32 -> V_35 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( V_2 -> V_32 == V_32 ) {
V_32 -> V_54 -> V_122 ( V_32 ) ;
V_2 -> V_32 = NULL ;
}
F_40 ( & V_32 -> V_15 ) ;
if ( ! V_2 -> V_32 && F_2 ( V_38 , & V_2 -> V_6 ) &&
! F_2 ( V_36 , & V_2 -> V_6 ) ) {
F_69 (nv, &rp->view_list, list) {
if ( V_121 -> V_54 -> V_123 ( V_121 ) == 0 ) {
V_2 -> V_32 = V_121 ;
break;
}
}
}
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
F_77 ( & V_32 -> V_125 ) ;
F_50 ( V_67 , F_78 ( & V_32 -> V_125 ) == 0 ) ;
if ( V_32 -> V_54 -> free )
V_32 -> V_54 -> free ( V_32 ) ;
}
static void
F_79 ( struct V_1 * V_2 )
{
struct V_40 * V_30 ;
F_56 ( & V_112 ) ;
if ( V_2 -> V_128 && ! F_36 ( V_2 -> V_128 ) )
F_80 ( V_129 , F_81 ( V_130 , V_2 -> V_108 ) ) ;
if ( V_2 -> V_131 && ! F_36 ( V_2 -> V_131 ) )
F_80 ( V_129 , F_81 ( V_132 , V_2 -> V_108 ) ) ;
F_40 ( & V_2 -> V_15 ) ;
F_57 ( & V_112 ) ;
V_30 = V_2 -> V_30 ;
V_2 -> V_30 = NULL ;
F_63 ( & V_30 -> V_35 , NULL ) ;
V_30 -> V_118 = NULL ;
F_82 ( & V_30 -> V_35 ) ;
F_7 ( V_2 -> V_105 ) ;
F_7 ( V_2 ) ;
}
static int
F_83 ( struct V_40 * V_30 )
{
return 0 ;
}
static T_4
F_84 ( struct V_133 * V_35 , struct V_134 * V_135 , char * V_136 )
{
return snprintf ( V_136 , V_137 , L_1 ,
( (struct V_1 * ) F_35 ( V_35 ) ) -> V_71 ) ;
}
static T_4
F_85 ( struct V_133 * V_35 , struct V_134 * V_135 , char * V_136 )
{
return snprintf ( V_136 , V_137 , L_1 ,
( (struct V_1 * ) F_35 ( V_35 ) ) -> V_80 ) ;
}
static T_4
F_86 ( struct V_133 * V_35 , struct V_134 * V_135 , char * V_136 )
{
return snprintf ( V_136 , V_137 , L_1 ,
( (struct V_1 * ) F_35 ( V_35 ) ) -> V_81 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_88 ( & V_2 -> V_30 -> V_35 . V_138 , & V_139 ) ;
if ( V_22 )
goto V_140;
V_2 -> V_128 = F_89 ( V_129 , & V_2 -> V_30 -> V_35 ,
F_81 ( V_130 , V_2 -> V_108 ) , NULL ,
L_2 , F_90 ( & V_2 -> V_30 -> V_35 ) ) ;
if ( F_36 ( V_2 -> V_128 ) ) {
V_22 = F_91 ( V_2 -> V_128 ) ;
goto V_141;
}
V_2 -> V_131 = F_89 ( V_129 , & V_2 -> V_30 -> V_35 ,
F_81 ( V_132 , V_2 -> V_108 ) , NULL ,
L_3 , F_90 ( & V_2 -> V_30 -> V_35 ) ) ;
if ( ! F_36 ( V_2 -> V_131 ) )
goto V_140;
V_22 = F_91 ( V_2 -> V_131 ) ;
F_80 ( V_129 , F_81 ( V_130 , V_2 -> V_108 ) ) ;
V_141:
F_92 ( & V_2 -> V_30 -> V_35 . V_138 , & V_139 ) ;
V_140:
return V_22 ;
}
int F_93 ( void (* F_94)( int , int ) )
{
struct V_142 * V_143 ;
struct V_1 * V_2 ;
V_143 = F_6 ( sizeof( struct V_142 ) , V_11 ) ;
if ( ! V_143 )
return - V_13 ;
V_143 -> F_94 = F_94 ;
F_56 ( & V_112 ) ;
F_30 ( & V_143 -> V_15 , & V_142 ) ;
F_69 (rp, &raw3270_devices, list) {
F_67 ( & V_2 -> V_30 -> V_35 ) ;
F_94 ( V_2 -> V_108 , 1 ) ;
}
F_57 ( & V_112 ) ;
return 0 ;
}
void F_95 ( void (* F_94)( int , int ) )
{
struct V_142 * V_143 ;
F_56 ( & V_112 ) ;
F_69 (np, &raw3270_notifier, list)
if ( V_143 -> F_94 == F_94 ) {
F_96 ( & V_143 -> V_15 ) ;
F_7 ( V_143 ) ;
break;
}
F_57 ( & V_112 ) ;
}
static int
F_97 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
struct V_142 * V_143 ;
int V_22 ;
V_2 = F_66 ( V_30 ) ;
if ( F_36 ( V_2 ) )
return F_91 ( V_2 ) ;
V_22 = F_58 ( V_2 ) ;
if ( V_22 )
goto V_144;
V_22 = F_55 ( V_2 ) ;
if ( V_22 )
goto V_144;
V_22 = F_58 ( V_2 ) ;
if ( V_22 )
goto V_144;
V_22 = F_87 ( V_2 ) ;
if ( V_22 )
goto V_144;
F_37 ( V_38 , & V_2 -> V_6 ) ;
F_56 ( & V_112 ) ;
F_69 (np, &raw3270_notifier, list)
V_143 -> F_94 ( V_2 -> V_108 , 1 ) ;
F_57 ( & V_112 ) ;
return 0 ;
V_144:
F_79 ( V_2 ) ;
return V_22 ;
}
static void
F_98 ( struct V_40 * V_30 )
{
unsigned long V_6 ;
struct V_1 * V_2 ;
struct V_31 * V_145 ;
struct V_142 * V_143 ;
V_2 = F_35 ( & V_30 -> V_35 ) ;
if ( V_2 == NULL )
return;
F_38 ( V_38 , & V_2 -> V_6 ) ;
F_92 ( & V_30 -> V_35 . V_138 , & V_139 ) ;
F_23 ( F_24 ( V_30 ) , V_6 ) ;
if ( V_2 -> V_32 ) {
V_2 -> V_32 -> V_54 -> V_122 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
}
while ( ! F_13 ( & V_2 -> V_111 ) ) {
V_145 = F_41 ( V_2 -> V_111 . V_59 , struct V_31 , V_15 ) ;
if ( V_145 -> V_54 -> V_146 )
V_145 -> V_54 -> V_146 ( V_145 ) ;
F_25 ( F_24 ( V_30 ) , V_6 ) ;
F_76 ( V_145 ) ;
F_23 ( F_24 ( V_30 ) , V_6 ) ;
}
F_25 ( F_24 ( V_30 ) , V_6 ) ;
F_56 ( & V_112 ) ;
F_69 (np, &raw3270_notifier, list)
V_143 -> F_94 ( V_2 -> V_108 , 0 ) ;
F_57 ( & V_112 ) ;
F_58 ( V_2 ) ;
F_79 ( V_2 ) ;
}
static int
F_99 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
V_2 = F_35 ( & V_30 -> V_35 ) ;
if ( F_2 ( V_119 , & V_2 -> V_6 ) )
return - V_147 ;
F_98 ( V_30 ) ;
return 0 ;
}
static int F_100 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
unsigned long V_6 ;
V_2 = F_35 ( & V_30 -> V_35 ) ;
if ( ! V_2 )
return 0 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
if ( V_2 -> V_32 )
V_2 -> V_32 -> V_54 -> V_122 ( V_2 -> V_32 ) ;
if ( ! F_2 ( V_119 , & V_2 -> V_6 ) ) {
F_69 (view, &rp->view_list, list) {
if ( V_32 -> V_54 -> V_146 )
V_32 -> V_54 -> V_146 ( V_32 ) ;
}
}
F_37 ( V_36 , & V_2 -> V_6 ) ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
return 0 ;
}
static int F_101 ( struct V_40 * V_30 )
{
struct V_1 * V_2 ;
unsigned long V_6 ;
V_2 = F_35 ( & V_30 -> V_35 ) ;
if ( ! V_2 )
return 0 ;
F_23 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
F_38 ( V_36 , & V_2 -> V_6 ) ;
if ( V_2 -> V_32 )
V_2 -> V_32 -> V_54 -> V_123 ( V_2 -> V_32 ) ;
F_25 ( F_24 ( V_2 -> V_30 ) , V_6 ) ;
return 0 ;
}
void F_102 ( struct V_31 * V_32 )
{
#ifdef F_46
struct V_1 * V_2 ;
V_2 = V_32 -> V_35 ;
if ( V_2 && F_2 ( V_36 , & V_2 -> V_6 ) )
F_103 () ;
#endif
}
static int
F_104 ( void )
{
struct V_1 * V_2 ;
int V_22 ;
if ( V_69 )
return 0 ;
V_69 = 1 ;
V_22 = F_105 ( & V_148 ) ;
if ( V_22 == 0 ) {
F_56 ( & V_112 ) ;
V_129 = F_106 ( V_149 , L_4 ) ;
F_69 (rp, &raw3270_devices, list) {
F_67 ( & V_2 -> V_30 -> V_35 ) ;
F_87 ( V_2 ) ;
}
F_57 ( & V_112 ) ;
}
return V_22 ;
}
static void
F_107 ( void )
{
F_108 ( & V_148 ) ;
F_109 ( V_129 ) ;
}
