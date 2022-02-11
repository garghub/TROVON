static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ||
V_2 -> V_3 == V_4 ;
}
void
F_3 ( struct V_1 * V_2 , char * V_6 , unsigned short V_7 )
{
if ( F_4 ( V_8 , & V_2 -> V_9 ) ) {
V_6 [ 0 ] = ( V_7 >> 8 ) & 0x3f ;
V_6 [ 1 ] = V_7 & 0xff ;
} else {
V_6 [ 0 ] = V_10 [ ( V_7 >> 6 ) & 0x3f ] ;
V_6 [ 1 ] = V_10 [ V_7 & 0x3f ] ;
}
}
struct V_11 *
F_5 ( T_1 V_12 )
{
struct V_11 * V_13 ;
V_13 = F_6 ( sizeof( struct V_11 ) , V_14 | V_15 ) ;
if ( ! V_13 )
return F_7 ( - V_16 ) ;
if ( V_12 > 0 ) {
V_13 -> V_17 = F_8 ( V_12 , V_14 | V_15 ) ;
if ( ! V_13 -> V_17 ) {
F_9 ( V_13 ) ;
return F_7 ( - V_16 ) ;
}
}
V_13 -> V_12 = V_12 ;
F_10 ( & V_13 -> V_18 ) ;
V_13 -> V_19 . V_20 = F_11 ( V_13 -> V_17 ) ;
V_13 -> V_19 . V_9 = V_21 ;
return V_13 ;
}
void
F_12 ( struct V_11 * V_13 )
{
F_9 ( V_13 -> V_17 ) ;
F_9 ( V_13 ) ;
}
void
F_13 ( struct V_11 * V_13 )
{
F_14 ( ! F_15 ( & V_13 -> V_18 ) ) ;
V_13 -> V_19 . V_22 = 0 ;
V_13 -> V_19 . V_23 = 0 ;
V_13 -> V_19 . V_20 = F_11 ( V_13 -> V_17 ) ;
V_13 -> V_19 . V_9 = V_21 ;
V_13 -> V_24 = 0 ;
V_13 -> V_25 = 0 ;
}
void
F_16 ( struct V_11 * V_13 , T_2 V_26 )
{
V_13 -> V_19 . V_22 = V_26 ;
}
int
F_17 ( struct V_11 * V_13 , void * V_27 , T_1 V_12 )
{
if ( V_12 + V_13 -> V_19 . V_23 > V_13 -> V_12 )
return - V_28 ;
memcpy ( V_13 -> V_17 + V_13 -> V_19 . V_23 , V_27 , V_12 ) ;
V_13 -> V_19 . V_23 += V_12 ;
return 0 ;
}
void
F_18 ( struct V_11 * V_13 , void * V_27 , T_1 V_12 )
{
V_13 -> V_19 . V_20 = F_11 ( V_27 ) ;
V_13 -> V_19 . V_23 = V_12 ;
}
void
F_19 ( struct V_11 * V_13 , struct V_29 * V_30 )
{
V_13 -> V_19 . V_20 = F_11 ( V_30 -> V_27 ) ;
V_13 -> V_19 . V_23 = V_30 -> V_12 ;
V_13 -> V_19 . V_9 |= V_31 ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_11 * V_13 )
{
int V_32 ;
int V_25 ;
if ( F_21 ( V_13 ) )
return 0 ;
for ( V_32 = 0 ; V_32 < 5 ; V_32 ++ ) {
if ( V_32 < 2 )
V_25 = F_22 ( V_2 -> V_33 , ( long ) V_13 ) ;
else
V_25 = F_23 ( V_2 -> V_33 , ( long ) V_13 ) ;
if ( V_25 == 0 )
break;
}
return V_25 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_11 * V_13 )
{
V_13 -> V_35 = V_35 ;
F_25 ( V_35 ) ;
if ( F_15 ( & V_2 -> V_36 ) &&
! F_4 ( V_37 , & V_2 -> V_9 ) ) {
V_13 -> V_25 = F_26 ( V_2 -> V_33 , & V_13 -> V_19 ,
( unsigned long ) V_13 , 0 , 0 ) ;
if ( V_13 -> V_25 ) {
F_27 ( V_35 ) ;
return V_13 -> V_25 ;
}
}
F_28 ( & V_13 -> V_18 , & V_2 -> V_36 ) ;
return 0 ;
}
int
F_29 ( struct V_34 * V_35 , struct V_11 * V_13 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
int V_25 ;
F_30 ( F_31 ( V_35 -> V_38 -> V_33 ) , V_9 ) ;
V_2 = V_35 -> V_38 ;
if ( ! V_2 || V_2 -> V_35 != V_35 ||
F_4 ( V_39 , & V_2 -> V_9 ) )
V_25 = - V_40 ;
else if ( ! F_1 ( V_2 ) )
V_25 = - V_41 ;
else
V_25 = F_24 ( V_2 , V_35 , V_13 ) ;
F_32 ( F_31 ( V_35 -> V_38 -> V_33 ) , V_9 ) ;
return V_25 ;
}
int
F_33 ( struct V_34 * V_35 , struct V_11 * V_13 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = V_35 -> V_38 ;
if ( ! V_2 || V_2 -> V_35 != V_35 ||
F_4 ( V_39 , & V_2 -> V_9 ) )
V_25 = - V_40 ;
else if ( ! F_1 ( V_2 ) )
V_25 = - V_41 ;
else
V_25 = F_24 ( V_2 , V_35 , V_13 ) ;
return V_25 ;
}
int
F_34 ( struct V_34 * V_35 , struct V_11 * V_13 )
{
struct V_1 * V_2 ;
V_2 = V_35 -> V_38 ;
V_13 -> V_35 = V_35 ;
F_25 ( V_35 ) ;
F_28 ( & V_13 -> V_18 , & V_2 -> V_36 ) ;
return 0 ;
}
static void
F_35 ( struct V_42 * V_33 , unsigned long V_43 , struct V_44 * V_44 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
struct V_11 * V_13 ;
int V_25 ;
V_2 = F_36 ( & V_33 -> V_38 ) ;
if ( ! V_2 )
return;
V_13 = (struct V_11 * ) V_43 ;
V_35 = V_13 ? V_13 -> V_35 : V_2 -> V_35 ;
if ( F_37 ( V_44 ) )
V_25 = V_45 ;
else if ( V_44 -> V_46 . V_26 . V_47 & V_48 ) {
V_13 -> V_25 = - V_49 ;
V_25 = V_50 ;
} else if ( V_44 -> V_46 . V_26 . V_51 == ( V_52 | V_53 |
V_54 ) ) {
F_38 ( V_37 , & V_2 -> V_9 ) ;
V_25 = V_55 ;
} else if ( F_4 ( V_37 , & V_2 -> V_9 ) ) {
if ( V_44 -> V_46 . V_26 . V_51 & V_53 ) {
F_39 ( V_37 , & V_2 -> V_9 ) ;
V_25 = V_45 ;
} else
V_25 = V_55 ;
} else if ( V_35 )
V_25 = V_35 -> V_56 -> V_57 ( V_35 , V_13 , V_44 ) ;
else
V_25 = V_50 ;
switch ( V_25 ) {
case V_50 :
break;
case V_55 :
return;
case V_45 :
if ( ! V_13 )
break;
V_13 -> V_25 = F_26 ( V_2 -> V_33 , & V_13 -> V_19 ,
( unsigned long ) V_13 , 0 , 0 ) ;
if ( V_13 -> V_25 == 0 )
return;
break;
case V_58 :
if ( ! V_13 )
break;
F_20 ( V_2 , V_13 ) ;
V_13 -> V_25 = - V_49 ;
break;
default:
F_40 () ;
}
if ( V_13 ) {
F_14 ( F_15 ( & V_13 -> V_18 ) ) ;
F_41 ( & V_13 -> V_18 ) ;
if ( V_13 -> V_59 )
V_13 -> V_59 ( V_13 , V_13 -> V_60 ) ;
F_27 ( V_35 ) ;
}
while ( ! F_15 ( & V_2 -> V_36 ) ) {
V_13 = F_42 ( V_2 -> V_36 . V_61 , struct V_11 , V_18 ) ;
V_13 -> V_25 = F_26 ( V_2 -> V_33 , & V_13 -> V_19 ,
( unsigned long ) V_13 , 0 , 0 ) ;
if ( V_13 -> V_25 == 0 )
break;
F_41 ( & V_13 -> V_18 ) ;
if ( V_13 -> V_59 )
V_13 -> V_59 ( V_13 , V_13 -> V_60 ) ;
F_27 ( V_35 ) ;
}
}
static void
F_43 ( struct V_1 * V_2 )
{
int V_25 , V_62 ;
struct V_63 V_64 ;
struct V_65 V_66 ;
F_44 ( V_2 -> V_33 , & V_64 ) ;
V_66 . V_67 = V_64 . V_68 ;
V_66 . V_69 = sizeof( struct V_65 ) ;
V_25 = V_65 ( & V_66 ) ;
V_62 = V_66 . V_70 ;
if ( V_25 || V_62 < 2 || V_62 > 5 )
V_62 = 2 ;
switch ( V_62 ) {
case 2 :
V_2 -> V_62 = V_62 ;
V_2 -> V_71 = 24 ;
V_2 -> V_72 = 80 ;
break;
case 3 :
V_2 -> V_62 = V_62 ;
V_2 -> V_71 = 32 ;
V_2 -> V_72 = 80 ;
break;
case 4 :
V_2 -> V_62 = V_62 ;
V_2 -> V_71 = 43 ;
V_2 -> V_72 = 80 ;
break;
case 5 :
V_2 -> V_62 = V_62 ;
V_2 -> V_71 = 27 ;
V_2 -> V_72 = 132 ;
break;
}
}
static void
F_45 ( struct V_1 * V_2 )
{
struct V_73 * V_74 ;
V_74 = (struct V_73 * ) ( V_2 -> V_75 + 1 ) ;
if ( V_2 -> V_76 . V_25 || V_2 -> V_75 [ 0 ] != 0x88 ||
V_74 -> V_77 . V_78 != 0x81 ) {
V_2 -> V_62 = 2 ;
V_2 -> V_71 = 24 ;
V_2 -> V_72 = 80 ;
return;
}
V_2 -> V_71 = V_74 -> V_77 . V_79 ;
V_2 -> V_72 = V_74 -> V_77 . V_80 ;
if ( ( V_74 -> V_77 . V_81 & 0x0d ) == 0x01 )
F_38 ( V_8 , & V_2 -> V_9 ) ;
if ( V_74 -> V_77 . V_82 == sizeof( struct V_73 ) &&
V_74 -> V_83 . V_84 == 0x02 ) {
V_2 -> V_71 = V_74 -> V_83 . V_85 ;
V_2 -> V_72 = V_74 -> V_83 . V_86 ;
}
V_2 -> V_62 = 0 ;
if ( V_2 -> V_71 == 24 && V_2 -> V_72 == 80 )
V_2 -> V_62 = 2 ;
if ( V_2 -> V_71 == 32 && V_2 -> V_72 == 80 )
V_2 -> V_62 = 3 ;
if ( V_2 -> V_71 == 43 && V_2 -> V_72 == 80 )
V_2 -> V_62 = 4 ;
if ( V_2 -> V_71 == 27 && V_2 -> V_72 == 132 )
V_2 -> V_62 = 5 ;
}
static void
F_46 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_2 -> V_35 = NULL ;
V_2 -> V_3 = V_4 ;
F_47 (view, &rp->view_list, list)
if ( V_35 -> V_56 -> V_87 )
V_35 -> V_56 -> V_87 ( V_35 , V_2 -> V_62 , V_2 -> V_71 , V_2 -> V_72 ) ;
F_47 (view, &rp->view_list, list) {
V_2 -> V_35 = V_35 ;
if ( V_35 -> V_56 -> V_88 ( V_35 ) == 0 )
break;
V_2 -> V_35 = NULL ;
}
}
static void
F_48 ( struct V_11 * V_13 , void * V_27 )
{
struct V_1 * V_2 = V_13 -> V_35 -> V_38 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
static void
F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_89 )
return;
memset ( & V_2 -> V_76 , 0 , sizeof( V_2 -> V_76 ) ) ;
memset ( & V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
V_2 -> V_76 . V_19 . V_22 = V_90 ;
V_2 -> V_76 . V_19 . V_9 = V_21 ;
V_2 -> V_76 . V_19 . V_23 = sizeof( V_2 -> V_75 ) ;
V_2 -> V_76 . V_19 . V_20 = ( V_91 ) F_11 ( V_2 -> V_75 ) ;
V_2 -> V_76 . V_59 = F_48 ;
V_2 -> V_3 = V_92 ;
F_34 ( & V_2 -> V_93 , & V_2 -> V_76 ) ;
}
static void
F_50 ( struct V_1 * V_2 )
{
static const unsigned char V_94 [] =
{ 0x00 , 0x07 , 0x01 , 0xff , 0x03 , 0x00 , 0x81 } ;
memset ( & V_2 -> V_95 , 0 , sizeof( V_2 -> V_95 ) ) ;
memset ( & V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
memcpy ( & V_2 -> V_75 , V_94 , sizeof( V_94 ) ) ;
V_2 -> V_95 . V_19 . V_22 = V_96 ;
V_2 -> V_95 . V_19 . V_9 = V_21 ;
V_2 -> V_95 . V_19 . V_23 = sizeof( V_94 ) ;
V_2 -> V_95 . V_19 . V_20 = ( V_91 ) F_11 ( & V_2 -> V_75 ) ;
V_2 -> V_3 = V_89 ;
F_34 ( & V_2 -> V_93 , & V_2 -> V_95 ) ;
}
static void
F_51 ( struct V_11 * V_13 , void * V_27 )
{
struct V_1 * V_2 = V_13 -> V_35 -> V_38 ;
if ( V_2 -> V_3 != V_97 )
return;
if ( V_13 && V_13 -> V_25 ) {
V_2 -> V_3 = V_5 ;
} else if ( 0 && V_98 ) {
F_43 ( V_2 ) ;
F_46 ( V_2 ) ;
} else
F_50 ( V_2 ) ;
}
static int
F_52 ( struct V_1 * V_2 )
{
int V_25 ;
memset ( & V_2 -> V_99 , 0 , sizeof( V_2 -> V_99 ) ) ;
memset ( & V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
V_2 -> V_75 [ 0 ] = V_100 ;
V_2 -> V_99 . V_19 . V_22 = V_101 ;
V_2 -> V_99 . V_19 . V_9 = V_21 ;
V_2 -> V_99 . V_19 . V_23 = 1 ;
V_2 -> V_99 . V_19 . V_20 = ( V_91 ) F_11 ( V_2 -> V_75 ) ;
V_2 -> V_99 . V_59 = F_51 ;
V_25 = F_24 ( V_2 , & V_2 -> V_93 , & V_2 -> V_99 ) ;
if ( V_25 == 0 && V_2 -> V_3 == V_5 )
V_2 -> V_3 = V_97 ;
return V_25 ;
}
static int
F_53 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_25 ;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
V_25 = F_52 ( V_2 ) ;
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
return V_25 ;
}
int
F_54 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = V_35 -> V_38 ;
if ( ! V_2 || V_2 -> V_35 != V_35 ||
F_4 ( V_39 , & V_2 -> V_9 ) )
V_25 = - V_40 ;
else if ( ! F_1 ( V_2 ) )
V_25 = - V_41 ;
else
V_25 = F_53 ( V_35 -> V_38 ) ;
return V_25 ;
}
static int
F_55 ( struct V_34 * V_35 , struct V_11 * V_13 ,
struct V_44 * V_44 )
{
struct V_1 * V_2 ;
if ( V_44 -> V_46 . V_26 . V_51 & V_102 ) {
if ( V_44 -> V_103 [ 0 ] & V_104 ) {
F_38 ( V_37 , & V_35 -> V_38 -> V_9 ) ;
return V_55 ;
}
}
if ( V_13 ) {
if ( V_44 -> V_46 . V_26 . V_51 & V_102 ) {
if ( V_44 -> V_103 [ 0 ] & V_105 )
V_13 -> V_25 = - V_106 ;
else
V_13 -> V_25 = - V_49 ;
}
}
if ( V_44 -> V_46 . V_26 . V_51 & V_107 ) {
V_2 = V_35 -> V_38 ;
F_49 ( V_2 ) ;
}
return V_50 ;
}
static int
F_56 ( struct V_42 * V_33 , struct V_1 * V_2 , char * V_108 )
{
struct V_109 * V_82 ;
struct V_1 * V_110 ;
int V_111 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
memcpy ( V_108 , V_112 , 256 ) ;
if ( V_113 ) {
V_108 [ '[' ] = 0xad ;
V_108 [ ']' ] = 0xbd ;
V_108 [ '^' ] = 0xb0 ;
}
V_2 -> V_108 = V_108 ;
V_2 -> V_71 = 24 ;
V_2 -> V_72 = 80 ;
F_10 ( & V_2 -> V_36 ) ;
F_10 ( & V_2 -> V_114 ) ;
V_2 -> V_93 . V_38 = V_2 ;
V_2 -> V_93 . V_56 = & V_115 ;
V_2 -> V_35 = & V_2 -> V_93 ;
F_57 ( & V_116 ) ;
V_111 = V_117 ;
V_2 -> V_111 = - 1 ;
F_58 (l, &raw3270_devices) {
V_110 = F_42 ( V_82 , struct V_1 , V_18 ) ;
if ( V_110 -> V_111 > V_111 ) {
V_2 -> V_111 = V_111 ;
F_59 ( & V_2 -> V_18 , V_82 -> V_118 , V_82 ) ;
break;
}
V_111 ++ ;
}
if ( V_2 -> V_111 == - 1 && V_111 < V_119 + V_117 ) {
V_2 -> V_111 = V_111 ;
F_28 ( & V_2 -> V_18 , & V_120 ) ;
}
F_60 ( & V_116 ) ;
if ( V_2 -> V_111 == - 1 )
return - V_121 ;
V_2 -> V_33 = V_33 ;
F_61 ( & V_33 -> V_38 , V_2 ) ;
V_33 -> V_122 = F_35 ;
return 0 ;
}
struct V_1 T_3 * F_62 ( struct V_42 * V_33 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
char * V_108 ;
int V_25 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_14 | V_15 ) ;
V_108 = F_6 ( 256 , V_14 ) ;
V_25 = F_56 ( V_33 , V_2 , V_108 ) ;
if ( V_25 )
return F_7 ( V_25 ) ;
F_38 ( V_123 , & V_2 -> V_9 ) ;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
do {
F_52 ( V_2 ) ;
while ( ! F_2 ( V_2 ) ) {
F_63 ( V_2 -> V_33 ) ;
F_64 () ;
}
} while ( V_2 -> V_3 != V_4 );
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
return V_2 ;
}
void
F_65 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
F_63 ( V_2 -> V_33 ) ;
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
}
static struct V_1 *
F_66 ( struct V_42 * V_33 )
{
struct V_1 * V_2 ;
char * V_108 ;
int V_25 ;
V_2 = F_8 ( sizeof( struct V_1 ) , V_14 | V_15 ) ;
if ( ! V_2 )
return F_7 ( - V_16 ) ;
V_108 = F_8 ( 256 , V_14 ) ;
if ( ! V_108 ) {
F_9 ( V_2 ) ;
return F_7 ( - V_16 ) ;
}
V_25 = F_56 ( V_33 , V_2 , V_108 ) ;
if ( V_25 ) {
F_9 ( V_2 -> V_108 ) ;
F_9 ( V_2 ) ;
V_2 = F_7 ( V_25 ) ;
}
F_67 ( & V_33 -> V_38 ) ;
return V_2 ;
}
int
F_68 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_34 * V_124 , * V_125 ;
unsigned long V_9 ;
int V_25 ;
V_2 = V_35 -> V_38 ;
if ( ! V_2 )
return - V_126 ;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
if ( V_2 -> V_35 == V_35 )
V_25 = 0 ;
else if ( ! F_1 ( V_2 ) )
V_25 = - V_41 ;
else if ( F_4 ( V_39 , & V_2 -> V_9 ) )
V_25 = - V_40 ;
else {
V_124 = NULL ;
if ( V_2 -> V_35 && V_2 -> V_35 -> V_56 -> V_127 ) {
V_124 = V_2 -> V_35 ;
V_124 -> V_56 -> V_127 ( V_124 ) ;
}
V_2 -> V_35 = V_35 ;
V_25 = V_35 -> V_56 -> V_88 ( V_35 ) ;
if ( V_25 ) {
V_2 -> V_35 = V_124 ;
if ( ! V_124 || V_124 -> V_56 -> V_88 ( V_124 ) != 0 ) {
F_47 (nv, &rp->view_list, list)
if ( V_125 != V_35 && V_125 != V_124 ) {
V_2 -> V_35 = V_125 ;
if ( V_125 -> V_56 -> V_88 ( V_125 ) == 0 )
break;
V_2 -> V_35 = NULL ;
}
}
}
}
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
return V_25 ;
}
void
F_69 ( struct V_34 * V_35 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = V_35 -> V_38 ;
if ( ! V_2 )
return;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
if ( V_2 -> V_35 == V_35 ) {
V_35 -> V_56 -> V_127 ( V_35 ) ;
V_2 -> V_35 = NULL ;
F_41 ( & V_35 -> V_18 ) ;
F_28 ( & V_35 -> V_18 , & V_2 -> V_114 ) ;
if ( F_1 ( V_2 ) &&
! F_4 ( V_39 , & V_2 -> V_9 ) ) {
F_47 (view, &rp->view_list, list) {
V_2 -> V_35 = V_35 ;
if ( V_35 -> V_56 -> V_88 ( V_35 ) == 0 )
break;
V_2 -> V_35 = NULL ;
}
}
}
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
}
int
F_70 ( struct V_34 * V_35 , struct V_128 * V_56 , int V_111 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
int V_25 ;
if ( V_111 <= 0 )
return - V_126 ;
F_57 ( & V_116 ) ;
V_25 = - V_126 ;
F_47 (rp, &raw3270_devices, list) {
if ( V_2 -> V_111 != V_111 )
continue;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
F_71 ( & V_35 -> V_129 , 2 ) ;
V_35 -> V_38 = V_2 ;
V_35 -> V_56 = V_56 ;
V_35 -> V_62 = V_2 -> V_62 ;
V_35 -> V_71 = V_2 -> V_71 ;
V_35 -> V_72 = V_2 -> V_72 ;
V_35 -> V_108 = V_2 -> V_108 ;
F_72 ( & V_35 -> V_130 ) ;
F_73 ( & V_35 -> V_18 , & V_2 -> V_114 ) ;
V_25 = 0 ;
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
break;
}
F_60 ( & V_116 ) ;
return V_25 ;
}
struct V_34 *
F_74 ( struct V_128 * V_56 , int V_111 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 , * V_110 ;
unsigned long V_9 ;
F_57 ( & V_116 ) ;
V_35 = F_7 ( - V_126 ) ;
F_47 (rp, &raw3270_devices, list) {
if ( V_2 -> V_111 != V_111 )
continue;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
F_47 (tmp, &rp->view_list, list) {
if ( V_110 -> V_56 == V_56 ) {
F_25 ( V_110 ) ;
V_35 = V_110 ;
break;
}
}
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
break;
}
F_60 ( & V_116 ) ;
return V_35 ;
}
void
F_75 ( struct V_34 * V_35 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
struct V_34 * V_125 ;
V_2 = V_35 -> V_38 ;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
if ( V_2 -> V_35 == V_35 ) {
V_35 -> V_56 -> V_127 ( V_35 ) ;
V_2 -> V_35 = NULL ;
}
F_41 ( & V_35 -> V_18 ) ;
if ( ! V_2 -> V_35 && F_1 ( V_2 ) &&
! F_4 ( V_39 , & V_2 -> V_9 ) ) {
F_47 (nv, &rp->view_list, list) {
if ( V_125 -> V_56 -> V_88 ( V_125 ) == 0 ) {
V_2 -> V_35 = V_125 ;
break;
}
}
}
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
F_76 ( & V_35 -> V_129 ) ;
F_77 ( V_131 , F_78 ( & V_35 -> V_129 ) == 0 ) ;
if ( V_35 -> V_56 -> free )
V_35 -> V_56 -> free ( V_35 ) ;
}
static void
F_79 ( struct V_1 * V_2 )
{
struct V_42 * V_33 ;
F_57 ( & V_116 ) ;
F_41 ( & V_2 -> V_18 ) ;
F_60 ( & V_116 ) ;
V_33 = V_2 -> V_33 ;
V_2 -> V_33 = NULL ;
F_61 ( & V_33 -> V_38 , NULL ) ;
V_33 -> V_122 = NULL ;
F_80 ( & V_33 -> V_38 ) ;
F_9 ( V_2 -> V_108 ) ;
F_9 ( V_2 ) ;
}
static int
F_81 ( struct V_42 * V_33 )
{
return 0 ;
}
static T_4
F_82 ( struct V_132 * V_38 , struct V_133 * V_134 , char * V_135 )
{
return snprintf ( V_135 , V_136 , L_1 ,
( (struct V_1 * ) F_36 ( V_38 ) ) -> V_62 ) ;
}
static T_4
F_83 ( struct V_132 * V_38 , struct V_133 * V_134 , char * V_135 )
{
return snprintf ( V_135 , V_136 , L_1 ,
( (struct V_1 * ) F_36 ( V_38 ) ) -> V_71 ) ;
}
static T_4
F_84 ( struct V_132 * V_38 , struct V_133 * V_134 , char * V_135 )
{
return snprintf ( V_135 , V_136 , L_1 ,
( (struct V_1 * ) F_36 ( V_38 ) ) -> V_72 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
return F_86 ( & V_2 -> V_33 -> V_38 . V_137 , & V_138 ) ;
}
int F_87 ( struct V_139 * V_140 )
{
struct V_1 * V_2 ;
F_57 ( & V_116 ) ;
F_28 ( & V_140 -> V_18 , & V_139 ) ;
F_47 (rp, &raw3270_devices, list)
V_140 -> V_141 ( V_2 -> V_111 ) ;
F_60 ( & V_116 ) ;
return 0 ;
}
void F_88 ( struct V_139 * V_140 )
{
struct V_1 * V_2 ;
F_57 ( & V_116 ) ;
F_47 (rp, &raw3270_devices, list)
V_140 -> V_142 ( V_2 -> V_111 ) ;
F_89 ( & V_140 -> V_18 ) ;
F_60 ( & V_116 ) ;
}
static int
F_90 ( struct V_42 * V_33 )
{
struct V_139 * V_143 ;
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_66 ( V_33 ) ;
if ( F_37 ( V_2 ) )
return F_91 ( V_2 ) ;
V_25 = F_85 ( V_2 ) ;
if ( V_25 )
goto V_144;
F_53 ( V_2 ) ;
F_57 ( & V_116 ) ;
F_47 (np, &raw3270_notifier, list)
V_143 -> V_141 ( V_2 -> V_111 ) ;
F_60 ( & V_116 ) ;
return 0 ;
V_144:
F_79 ( V_2 ) ;
return V_25 ;
}
static void
F_92 ( struct V_42 * V_33 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
struct V_34 * V_145 ;
struct V_139 * V_143 ;
V_2 = F_36 ( & V_33 -> V_38 ) ;
if ( V_2 == NULL )
return;
F_93 ( & V_33 -> V_38 . V_137 , & V_138 ) ;
F_30 ( F_31 ( V_33 ) , V_9 ) ;
if ( V_2 -> V_35 ) {
if ( V_2 -> V_35 -> V_56 -> V_127 )
V_2 -> V_35 -> V_56 -> V_127 ( V_2 -> V_35 ) ;
V_2 -> V_35 = NULL ;
}
while ( ! F_15 ( & V_2 -> V_114 ) ) {
V_145 = F_42 ( V_2 -> V_114 . V_61 , struct V_34 , V_18 ) ;
if ( V_145 -> V_56 -> V_146 )
V_145 -> V_56 -> V_146 ( V_145 ) ;
F_32 ( F_31 ( V_33 ) , V_9 ) ;
F_75 ( V_145 ) ;
F_30 ( F_31 ( V_33 ) , V_9 ) ;
}
F_32 ( F_31 ( V_33 ) , V_9 ) ;
F_57 ( & V_116 ) ;
F_47 (np, &raw3270_notifier, list)
V_143 -> V_142 ( V_2 -> V_111 ) ;
F_60 ( & V_116 ) ;
F_53 ( V_2 ) ;
F_79 ( V_2 ) ;
}
static int
F_94 ( struct V_42 * V_33 )
{
struct V_1 * V_2 ;
V_2 = F_36 ( & V_33 -> V_38 ) ;
if ( F_4 ( V_123 , & V_2 -> V_9 ) )
return - V_41 ;
F_92 ( V_33 ) ;
return 0 ;
}
static int F_95 ( struct V_42 * V_33 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
unsigned long V_9 ;
V_2 = F_36 ( & V_33 -> V_38 ) ;
if ( ! V_2 )
return 0 ;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
if ( V_2 -> V_35 && V_2 -> V_35 -> V_56 -> V_127 )
V_2 -> V_35 -> V_56 -> V_127 ( V_2 -> V_35 ) ;
if ( ! F_4 ( V_123 , & V_2 -> V_9 ) ) {
F_47 (view, &rp->view_list, list) {
if ( V_35 -> V_56 -> V_146 )
V_35 -> V_56 -> V_146 ( V_35 ) ;
}
}
F_38 ( V_39 , & V_2 -> V_9 ) ;
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
return 0 ;
}
static int F_96 ( struct V_42 * V_33 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
V_2 = F_36 ( & V_33 -> V_38 ) ;
if ( ! V_2 )
return 0 ;
F_30 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
F_39 ( V_39 , & V_2 -> V_9 ) ;
if ( V_2 -> V_35 && V_2 -> V_35 -> V_56 -> V_88 )
V_2 -> V_35 -> V_56 -> V_88 ( V_2 -> V_35 ) ;
F_32 ( F_31 ( V_2 -> V_33 ) , V_9 ) ;
return 0 ;
}
void F_97 ( struct V_34 * V_35 )
{
#ifdef F_98
struct V_1 * V_2 ;
V_2 = V_35 -> V_38 ;
if ( V_2 && F_4 ( V_39 , & V_2 -> V_9 ) )
F_99 ( V_2 -> V_33 ) ;
#endif
}
static int
F_100 ( void )
{
struct V_1 * V_2 ;
int V_25 ;
if ( V_147 )
return 0 ;
V_147 = 1 ;
V_25 = F_101 ( & V_148 ) ;
if ( V_25 == 0 ) {
F_57 ( & V_116 ) ;
V_149 = F_102 ( V_150 , L_2 ) ;
F_47 (rp, &raw3270_devices, list) {
F_67 ( & V_2 -> V_33 -> V_38 ) ;
F_85 ( V_2 ) ;
}
F_60 ( & V_116 ) ;
}
return V_25 ;
}
static void
F_103 ( void )
{
F_104 ( & V_148 ) ;
F_105 ( V_149 ) ;
}
