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
F_20 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_11 * V_13 )
{
V_13 -> V_33 = V_33 ;
F_21 ( V_33 ) ;
if ( F_15 ( & V_2 -> V_34 ) &&
! F_4 ( V_35 , & V_2 -> V_9 ) ) {
V_13 -> V_25 = F_22 ( V_2 -> V_36 , & V_13 -> V_19 ,
( unsigned long ) V_13 , 0 , 0 ) ;
if ( V_13 -> V_25 ) {
F_23 ( V_33 ) ;
return V_13 -> V_25 ;
}
}
F_24 ( & V_13 -> V_18 , & V_2 -> V_34 ) ;
return 0 ;
}
int
F_25 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_37 ;
return V_2 && V_2 -> V_33 == V_33 &&
! F_4 ( V_38 , & V_2 -> V_9 ) ;
}
int
F_26 ( struct V_32 * V_33 , struct V_11 * V_13 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
int V_25 ;
F_27 ( F_28 ( V_33 -> V_37 -> V_36 ) , V_9 ) ;
V_2 = V_33 -> V_37 ;
if ( ! V_2 || V_2 -> V_33 != V_33 ||
F_4 ( V_38 , & V_2 -> V_9 ) )
V_25 = - V_39 ;
else if ( ! F_1 ( V_2 ) )
V_25 = - V_40 ;
else
V_25 = F_20 ( V_2 , V_33 , V_13 ) ;
F_29 ( F_28 ( V_33 -> V_37 -> V_36 ) , V_9 ) ;
return V_25 ;
}
int
F_30 ( struct V_32 * V_33 , struct V_11 * V_13 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = V_33 -> V_37 ;
if ( ! V_2 || V_2 -> V_33 != V_33 ||
F_4 ( V_38 , & V_2 -> V_9 ) )
V_25 = - V_39 ;
else if ( ! F_1 ( V_2 ) )
V_25 = - V_40 ;
else
V_25 = F_20 ( V_2 , V_33 , V_13 ) ;
return V_25 ;
}
int
F_31 ( struct V_32 * V_33 , struct V_11 * V_13 )
{
struct V_1 * V_2 ;
V_2 = V_33 -> V_37 ;
V_13 -> V_33 = V_33 ;
F_21 ( V_33 ) ;
F_24 ( & V_13 -> V_18 , & V_2 -> V_34 ) ;
return 0 ;
}
static void
F_32 ( struct V_41 * V_36 , unsigned long V_42 , struct V_43 * V_43 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_11 * V_13 ;
V_2 = F_33 ( & V_36 -> V_37 ) ;
if ( ! V_2 )
return;
V_13 = (struct V_11 * ) V_42 ;
V_33 = V_13 ? V_13 -> V_33 : V_2 -> V_33 ;
if ( ! F_34 ( V_43 ) ) {
if ( V_43 -> V_44 . V_26 . V_45 & V_46 )
F_35 ( V_35 , & V_2 -> V_9 ) ;
if ( V_43 -> V_44 . V_26 . V_45 == ( V_47 |
V_46 |
V_48 ) )
F_36 ( V_35 , & V_2 -> V_9 ) ;
if ( ( V_43 -> V_44 . V_26 . V_45 & V_49 ) &&
( V_43 -> V_50 [ 0 ] & V_51 ) ) {
F_36 ( V_35 , & V_2 -> V_9 ) ;
if ( V_2 -> V_3 > V_52 )
F_37 ( V_2 ) ;
}
if ( V_33 )
V_33 -> V_53 -> V_54 ( V_33 , V_13 , V_43 ) ;
}
if ( F_4 ( V_35 , & V_2 -> V_9 ) )
return;
if ( V_13 && ! F_15 ( & V_13 -> V_18 ) ) {
F_38 ( & V_13 -> V_18 ) ;
if ( V_13 -> V_55 )
V_13 -> V_55 ( V_13 , V_13 -> V_56 ) ;
F_23 ( V_33 ) ;
}
while ( ! F_15 ( & V_2 -> V_34 ) ) {
V_13 = F_39 ( V_2 -> V_34 . V_57 , struct V_11 , V_18 ) ;
V_13 -> V_25 = F_22 ( V_2 -> V_36 , & V_13 -> V_19 ,
( unsigned long ) V_13 , 0 , 0 ) ;
if ( V_13 -> V_25 == 0 )
break;
F_38 ( & V_13 -> V_18 ) ;
if ( V_13 -> V_55 )
V_13 -> V_55 ( V_13 , V_13 -> V_56 ) ;
F_23 ( V_33 ) ;
}
}
static void
F_40 ( struct V_1 * V_2 )
{
int V_25 , V_58 ;
struct V_59 V_60 ;
struct V_61 V_62 ;
F_41 ( V_2 -> V_36 , & V_60 ) ;
V_62 . V_63 = V_60 . V_64 ;
V_62 . V_65 = sizeof( struct V_61 ) ;
V_25 = V_61 ( & V_62 ) ;
V_58 = V_62 . V_66 ;
if ( V_25 || V_58 < 2 || V_58 > 5 )
V_58 = 2 ;
switch ( V_58 ) {
case 2 :
V_2 -> V_58 = V_58 ;
V_2 -> V_67 = 24 ;
V_2 -> V_68 = 80 ;
break;
case 3 :
V_2 -> V_58 = V_58 ;
V_2 -> V_67 = 32 ;
V_2 -> V_68 = 80 ;
break;
case 4 :
V_2 -> V_58 = V_58 ;
V_2 -> V_67 = 43 ;
V_2 -> V_68 = 80 ;
break;
case 5 :
V_2 -> V_58 = V_58 ;
V_2 -> V_67 = 27 ;
V_2 -> V_68 = 132 ;
break;
}
}
static void
F_42 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
V_70 = (struct V_69 * ) ( V_2 -> V_71 + 1 ) ;
if ( V_2 -> V_72 . V_25 || V_2 -> V_71 [ 0 ] != 0x88 ||
V_70 -> V_73 . V_74 != 0x81 ) {
V_2 -> V_58 = 2 ;
V_2 -> V_67 = 24 ;
V_2 -> V_68 = 80 ;
return;
}
V_2 -> V_67 = V_70 -> V_73 . V_75 ;
V_2 -> V_68 = V_70 -> V_73 . V_76 ;
if ( ( V_70 -> V_73 . V_77 & 0x0d ) == 0x01 )
F_36 ( V_8 , & V_2 -> V_9 ) ;
if ( V_70 -> V_73 . V_78 == sizeof( struct V_69 ) &&
V_70 -> V_79 . V_80 == 0x02 ) {
V_2 -> V_67 = V_70 -> V_79 . V_81 ;
V_2 -> V_68 = V_70 -> V_79 . V_82 ;
}
V_2 -> V_58 = 0 ;
if ( V_2 -> V_67 == 24 && V_2 -> V_68 == 80 )
V_2 -> V_58 = 2 ;
if ( V_2 -> V_67 == 32 && V_2 -> V_68 == 80 )
V_2 -> V_58 = 3 ;
if ( V_2 -> V_67 == 43 && V_2 -> V_68 == 80 )
V_2 -> V_58 = 4 ;
if ( V_2 -> V_67 == 27 && V_2 -> V_68 == 132 )
V_2 -> V_58 = 5 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_2 -> V_33 = NULL ;
V_2 -> V_3 = V_4 ;
F_44 (view, &rp->view_list, list)
if ( V_33 -> V_53 -> V_83 )
V_33 -> V_53 -> V_83 ( V_33 , V_2 -> V_58 , V_2 -> V_67 , V_2 -> V_68 ) ;
F_44 (view, &rp->view_list, list) {
V_2 -> V_33 = V_33 ;
if ( V_33 -> V_53 -> V_84 ( V_33 ) == 0 )
break;
V_2 -> V_33 = NULL ;
}
}
static void
F_45 ( struct V_11 * V_13 , void * V_27 )
{
struct V_1 * V_2 = V_13 -> V_33 -> V_37 ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
}
static void
F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_85 )
return;
memset ( & V_2 -> V_72 , 0 , sizeof( V_2 -> V_72 ) ) ;
memset ( & V_2 -> V_71 , 0 , sizeof( V_2 -> V_71 ) ) ;
V_2 -> V_72 . V_19 . V_22 = V_86 ;
V_2 -> V_72 . V_19 . V_9 = V_21 ;
V_2 -> V_72 . V_19 . V_23 = sizeof( V_2 -> V_71 ) ;
V_2 -> V_72 . V_19 . V_20 = ( V_87 ) F_11 ( V_2 -> V_71 ) ;
V_2 -> V_72 . V_55 = F_45 ;
V_2 -> V_3 = V_88 ;
F_31 ( & V_2 -> V_89 , & V_2 -> V_72 ) ;
}
static void
F_47 ( struct V_1 * V_2 )
{
static const unsigned char V_90 [] =
{ 0x00 , 0x07 , 0x01 , 0xff , 0x03 , 0x00 , 0x81 } ;
memset ( & V_2 -> V_91 , 0 , sizeof( V_2 -> V_91 ) ) ;
memset ( & V_2 -> V_71 , 0 , sizeof( V_2 -> V_71 ) ) ;
memcpy ( & V_2 -> V_71 , V_90 , sizeof( V_90 ) ) ;
V_2 -> V_91 . V_19 . V_22 = V_92 ;
V_2 -> V_91 . V_19 . V_9 = V_21 ;
V_2 -> V_91 . V_19 . V_23 = sizeof( V_90 ) ;
V_2 -> V_91 . V_19 . V_20 = ( V_87 ) F_11 ( & V_2 -> V_71 ) ;
V_2 -> V_3 = V_85 ;
F_31 ( & V_2 -> V_89 , & V_2 -> V_91 ) ;
}
static void
F_48 ( struct V_11 * V_13 , void * V_27 )
{
struct V_1 * V_2 = V_13 -> V_33 -> V_37 ;
if ( V_2 -> V_3 != V_52 )
return;
if ( V_13 -> V_25 ) {
V_2 -> V_3 = V_5 ;
} else if ( V_93 ) {
F_40 ( V_2 ) ;
F_43 ( V_2 ) ;
} else
F_47 ( V_2 ) ;
memset ( & V_2 -> V_94 , 0 , sizeof( V_2 -> V_94 ) ) ;
}
static int
F_49 ( struct V_1 * V_2 )
{
int V_25 ;
if ( V_2 -> V_94 . V_33 )
return - V_40 ;
V_2 -> V_71 [ 0 ] = V_95 ;
V_2 -> V_94 . V_19 . V_22 = V_96 ;
V_2 -> V_94 . V_19 . V_9 = V_21 ;
V_2 -> V_94 . V_19 . V_23 = 1 ;
V_2 -> V_94 . V_19 . V_20 = ( V_87 ) F_11 ( V_2 -> V_71 ) ;
V_2 -> V_94 . V_55 = F_48 ;
V_25 = F_20 ( V_2 , & V_2 -> V_89 , & V_2 -> V_94 ) ;
if ( V_25 == 0 && V_2 -> V_3 == V_5 )
V_2 -> V_3 = V_52 ;
return V_25 ;
}
static int
F_50 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_25 ;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
V_25 = F_49 ( V_2 ) ;
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
return V_25 ;
}
int
F_51 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = V_33 -> V_37 ;
if ( ! V_2 || V_2 -> V_33 != V_33 ||
F_4 ( V_38 , & V_2 -> V_9 ) )
V_25 = - V_39 ;
else if ( ! F_1 ( V_2 ) )
V_25 = - V_40 ;
else
V_25 = F_50 ( V_33 -> V_37 ) ;
return V_25 ;
}
static void
F_37 ( struct V_1 * V_2 )
{
struct V_11 * V_13 ;
struct V_32 * V_33 ;
V_2 -> V_3 = V_5 ;
V_2 -> V_33 = & V_2 -> V_89 ;
while ( ! F_15 ( & V_2 -> V_34 ) ) {
V_13 = F_39 ( V_2 -> V_34 . V_57 , struct V_11 , V_18 ) ;
V_33 = V_13 -> V_33 ;
V_13 -> V_25 = - V_39 ;
F_38 ( & V_13 -> V_18 ) ;
if ( V_13 -> V_55 )
V_13 -> V_55 ( V_13 , V_13 -> V_56 ) ;
F_23 ( V_33 ) ;
}
F_49 ( V_2 ) ;
}
static void
F_52 ( struct V_32 * V_33 , struct V_11 * V_13 ,
struct V_43 * V_43 )
{
struct V_1 * V_2 ;
if ( V_13 ) {
if ( V_43 -> V_44 . V_26 . V_45 & V_49 ) {
if ( V_43 -> V_50 [ 0 ] & V_97 )
V_13 -> V_25 = - V_98 ;
else
V_13 -> V_25 = - V_99 ;
}
}
if ( V_43 -> V_44 . V_26 . V_45 & V_100 ) {
V_2 = V_33 -> V_37 ;
F_46 ( V_2 ) ;
}
}
static int
F_53 ( struct V_41 * V_36 , struct V_1 * V_2 , char * V_101 )
{
struct V_102 * V_78 ;
struct V_1 * V_103 ;
int V_104 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
memcpy ( V_101 , V_105 , 256 ) ;
if ( V_106 ) {
V_101 [ '[' ] = 0xad ;
V_101 [ ']' ] = 0xbd ;
V_101 [ '^' ] = 0xb0 ;
}
V_2 -> V_101 = V_101 ;
V_2 -> V_67 = 24 ;
V_2 -> V_68 = 80 ;
F_10 ( & V_2 -> V_34 ) ;
F_10 ( & V_2 -> V_107 ) ;
V_2 -> V_89 . V_37 = V_2 ;
V_2 -> V_89 . V_53 = & V_108 ;
V_2 -> V_33 = & V_2 -> V_89 ;
F_54 ( & V_109 ) ;
V_104 = V_110 ;
V_2 -> V_104 = - 1 ;
F_55 (l, &raw3270_devices) {
V_103 = F_39 ( V_78 , struct V_1 , V_18 ) ;
if ( V_103 -> V_104 > V_104 ) {
V_2 -> V_104 = V_104 ;
F_56 ( & V_2 -> V_18 , V_78 -> V_111 , V_78 ) ;
break;
}
V_104 ++ ;
}
if ( V_2 -> V_104 == - 1 && V_104 < V_112 + V_110 ) {
V_2 -> V_104 = V_104 ;
F_24 ( & V_2 -> V_18 , & V_113 ) ;
}
F_57 ( & V_109 ) ;
if ( V_2 -> V_104 == - 1 )
return - V_114 ;
V_2 -> V_36 = V_36 ;
F_58 ( & V_36 -> V_37 , V_2 ) ;
V_36 -> V_115 = F_32 ;
return 0 ;
}
struct V_1 T_3 * F_59 ( void )
{
struct V_41 * V_36 ;
unsigned long V_9 ;
struct V_1 * V_2 ;
char * V_101 ;
int V_25 ;
V_36 = F_60 ( & V_116 ) ;
if ( F_34 ( V_36 ) )
return F_61 ( V_36 ) ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_14 | V_15 ) ;
V_101 = F_6 ( 256 , V_14 ) ;
V_25 = F_53 ( V_36 , V_2 , V_101 ) ;
if ( V_25 )
return F_7 ( V_25 ) ;
F_36 ( V_117 , & V_2 -> V_9 ) ;
V_25 = F_62 ( V_36 ) ;
if ( V_25 ) {
F_63 ( V_36 ) ;
return F_7 ( V_25 ) ;
}
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
do {
F_49 ( V_2 ) ;
while ( ! F_2 ( V_2 ) ) {
F_64 ( V_2 -> V_36 ) ;
F_65 () ;
}
} while ( V_2 -> V_3 != V_4 );
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
return V_2 ;
}
void
F_66 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
F_64 ( V_2 -> V_36 ) ;
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
}
static struct V_1 *
F_67 ( struct V_41 * V_36 )
{
struct V_1 * V_2 ;
char * V_101 ;
int V_25 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_14 | V_15 ) ;
if ( ! V_2 )
return F_7 ( - V_16 ) ;
V_101 = F_8 ( 256 , V_14 ) ;
if ( ! V_101 ) {
F_9 ( V_2 ) ;
return F_7 ( - V_16 ) ;
}
V_25 = F_53 ( V_36 , V_2 , V_101 ) ;
if ( V_25 ) {
F_9 ( V_2 -> V_101 ) ;
F_9 ( V_2 ) ;
V_2 = F_7 ( V_25 ) ;
}
F_68 ( & V_36 -> V_37 ) ;
return V_2 ;
}
int
F_69 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_32 * V_118 , * V_119 ;
unsigned long V_9 ;
int V_25 ;
V_2 = V_33 -> V_37 ;
if ( ! V_2 )
return - V_120 ;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
if ( V_2 -> V_33 == V_33 )
V_25 = 0 ;
else if ( ! F_1 ( V_2 ) )
V_25 = - V_40 ;
else if ( F_4 ( V_38 , & V_2 -> V_9 ) )
V_25 = - V_39 ;
else {
V_118 = NULL ;
if ( V_2 -> V_33 && V_2 -> V_33 -> V_53 -> V_121 ) {
V_118 = V_2 -> V_33 ;
V_118 -> V_53 -> V_121 ( V_118 ) ;
}
V_2 -> V_33 = V_33 ;
V_25 = V_33 -> V_53 -> V_84 ( V_33 ) ;
if ( V_25 ) {
V_2 -> V_33 = V_118 ;
if ( ! V_118 || V_118 -> V_53 -> V_84 ( V_118 ) != 0 ) {
F_44 (nv, &rp->view_list, list)
if ( V_119 != V_33 && V_119 != V_118 ) {
V_2 -> V_33 = V_119 ;
if ( V_119 -> V_53 -> V_84 ( V_119 ) == 0 )
break;
V_2 -> V_33 = NULL ;
}
}
}
}
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
return V_25 ;
}
void
F_70 ( struct V_32 * V_33 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = V_33 -> V_37 ;
if ( ! V_2 )
return;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
if ( V_2 -> V_33 == V_33 ) {
V_33 -> V_53 -> V_121 ( V_33 ) ;
V_2 -> V_33 = NULL ;
F_38 ( & V_33 -> V_18 ) ;
F_24 ( & V_33 -> V_18 , & V_2 -> V_107 ) ;
if ( F_1 ( V_2 ) &&
! F_4 ( V_38 , & V_2 -> V_9 ) ) {
F_44 (view, &rp->view_list, list) {
V_2 -> V_33 = V_33 ;
if ( V_33 -> V_53 -> V_84 ( V_33 ) == 0 )
break;
V_2 -> V_33 = NULL ;
}
}
}
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
}
int
F_71 ( struct V_32 * V_33 , struct V_122 * V_53 , int V_104 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
int V_25 ;
if ( V_104 <= 0 )
return - V_120 ;
F_54 ( & V_109 ) ;
V_25 = - V_120 ;
F_44 (rp, &raw3270_devices, list) {
if ( V_2 -> V_104 != V_104 )
continue;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
F_72 ( & V_33 -> V_123 , 2 ) ;
V_33 -> V_37 = V_2 ;
V_33 -> V_53 = V_53 ;
V_33 -> V_58 = V_2 -> V_58 ;
V_33 -> V_67 = V_2 -> V_67 ;
V_33 -> V_68 = V_2 -> V_68 ;
V_33 -> V_101 = V_2 -> V_101 ;
F_73 ( & V_33 -> V_124 ) ;
F_74 ( & V_33 -> V_18 , & V_2 -> V_107 ) ;
V_25 = 0 ;
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
break;
}
F_57 ( & V_109 ) ;
return V_25 ;
}
struct V_32 *
F_75 ( struct V_122 * V_53 , int V_104 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 , * V_103 ;
unsigned long V_9 ;
F_54 ( & V_109 ) ;
V_33 = F_7 ( - V_120 ) ;
F_44 (rp, &raw3270_devices, list) {
if ( V_2 -> V_104 != V_104 )
continue;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
F_44 (tmp, &rp->view_list, list) {
if ( V_103 -> V_53 == V_53 ) {
F_21 ( V_103 ) ;
V_33 = V_103 ;
break;
}
}
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
break;
}
F_57 ( & V_109 ) ;
return V_33 ;
}
void
F_76 ( struct V_32 * V_33 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
struct V_32 * V_119 ;
V_2 = V_33 -> V_37 ;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
if ( V_2 -> V_33 == V_33 ) {
V_33 -> V_53 -> V_121 ( V_33 ) ;
V_2 -> V_33 = NULL ;
}
F_38 ( & V_33 -> V_18 ) ;
if ( ! V_2 -> V_33 && F_1 ( V_2 ) &&
! F_4 ( V_38 , & V_2 -> V_9 ) ) {
F_44 (nv, &rp->view_list, list) {
if ( V_119 -> V_53 -> V_84 ( V_119 ) == 0 ) {
V_2 -> V_33 = V_119 ;
break;
}
}
}
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
F_77 ( & V_33 -> V_123 ) ;
F_78 ( V_125 , F_79 ( & V_33 -> V_123 ) == 0 ) ;
if ( V_33 -> V_53 -> free )
V_33 -> V_53 -> free ( V_33 ) ;
}
static void
F_80 ( struct V_1 * V_2 )
{
struct V_41 * V_36 ;
F_54 ( & V_109 ) ;
F_38 ( & V_2 -> V_18 ) ;
F_57 ( & V_109 ) ;
V_36 = V_2 -> V_36 ;
V_2 -> V_36 = NULL ;
F_58 ( & V_36 -> V_37 , NULL ) ;
V_36 -> V_115 = NULL ;
F_81 ( & V_36 -> V_37 ) ;
F_9 ( V_2 -> V_101 ) ;
F_9 ( V_2 ) ;
}
static int
F_82 ( struct V_41 * V_36 )
{
return 0 ;
}
static T_4
F_83 ( struct V_126 * V_37 , struct V_127 * V_128 , char * V_129 )
{
return snprintf ( V_129 , V_130 , L_1 ,
( (struct V_1 * ) F_33 ( V_37 ) ) -> V_58 ) ;
}
static T_4
F_84 ( struct V_126 * V_37 , struct V_127 * V_128 , char * V_129 )
{
return snprintf ( V_129 , V_130 , L_1 ,
( (struct V_1 * ) F_33 ( V_37 ) ) -> V_67 ) ;
}
static T_4
F_85 ( struct V_126 * V_37 , struct V_127 * V_128 , char * V_129 )
{
return snprintf ( V_129 , V_130 , L_1 ,
( (struct V_1 * ) F_33 ( V_37 ) ) -> V_68 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
return F_87 ( & V_2 -> V_36 -> V_37 . V_131 , & V_132 ) ;
}
int F_88 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
F_54 ( & V_109 ) ;
F_24 ( & V_134 -> V_18 , & V_133 ) ;
F_44 (rp, &raw3270_devices, list)
V_134 -> V_135 ( V_2 -> V_104 ) ;
F_57 ( & V_109 ) ;
return 0 ;
}
void F_89 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
F_54 ( & V_109 ) ;
F_44 (rp, &raw3270_devices, list)
V_134 -> V_136 ( V_2 -> V_104 ) ;
F_90 ( & V_134 -> V_18 ) ;
F_57 ( & V_109 ) ;
}
static int
F_91 ( struct V_41 * V_36 )
{
struct V_133 * V_137 ;
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_67 ( V_36 ) ;
if ( F_34 ( V_2 ) )
return F_92 ( V_2 ) ;
V_25 = F_86 ( V_2 ) ;
if ( V_25 )
goto V_138;
F_50 ( V_2 ) ;
F_54 ( & V_109 ) ;
F_44 (np, &raw3270_notifier, list)
V_137 -> V_135 ( V_2 -> V_104 ) ;
F_57 ( & V_109 ) ;
return 0 ;
V_138:
F_80 ( V_2 ) ;
return V_25 ;
}
static void
F_93 ( struct V_41 * V_36 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
struct V_32 * V_139 ;
struct V_133 * V_137 ;
V_2 = F_33 ( & V_36 -> V_37 ) ;
if ( V_2 == NULL )
return;
F_94 ( & V_36 -> V_37 . V_131 , & V_132 ) ;
F_27 ( F_28 ( V_36 ) , V_9 ) ;
if ( V_2 -> V_33 ) {
if ( V_2 -> V_33 -> V_53 -> V_121 )
V_2 -> V_33 -> V_53 -> V_121 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
}
while ( ! F_15 ( & V_2 -> V_107 ) ) {
V_139 = F_39 ( V_2 -> V_107 . V_57 , struct V_32 , V_18 ) ;
if ( V_139 -> V_53 -> V_140 )
V_139 -> V_53 -> V_140 ( V_139 ) ;
F_29 ( F_28 ( V_36 ) , V_9 ) ;
F_76 ( V_139 ) ;
F_27 ( F_28 ( V_36 ) , V_9 ) ;
}
F_29 ( F_28 ( V_36 ) , V_9 ) ;
F_54 ( & V_109 ) ;
F_44 (np, &raw3270_notifier, list)
V_137 -> V_136 ( V_2 -> V_104 ) ;
F_57 ( & V_109 ) ;
F_50 ( V_2 ) ;
F_80 ( V_2 ) ;
}
static int
F_95 ( struct V_41 * V_36 )
{
struct V_1 * V_2 ;
V_2 = F_33 ( & V_36 -> V_37 ) ;
if ( F_4 ( V_117 , & V_2 -> V_9 ) )
return - V_40 ;
F_93 ( V_36 ) ;
return 0 ;
}
static int F_96 ( struct V_41 * V_36 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
unsigned long V_9 ;
V_2 = F_33 ( & V_36 -> V_37 ) ;
if ( ! V_2 )
return 0 ;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
if ( V_2 -> V_33 && V_2 -> V_33 -> V_53 -> V_121 )
V_2 -> V_33 -> V_53 -> V_121 ( V_2 -> V_33 ) ;
if ( ! F_4 ( V_117 , & V_2 -> V_9 ) ) {
F_44 (view, &rp->view_list, list) {
if ( V_33 -> V_53 -> V_140 )
V_33 -> V_53 -> V_140 ( V_33 ) ;
}
}
F_36 ( V_38 , & V_2 -> V_9 ) ;
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
return 0 ;
}
static int F_97 ( struct V_41 * V_36 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
V_2 = F_33 ( & V_36 -> V_37 ) ;
if ( ! V_2 )
return 0 ;
F_27 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
F_35 ( V_38 , & V_2 -> V_9 ) ;
if ( V_2 -> V_33 && V_2 -> V_33 -> V_53 -> V_84 )
V_2 -> V_33 -> V_53 -> V_84 ( V_2 -> V_33 ) ;
F_29 ( F_28 ( V_2 -> V_36 ) , V_9 ) ;
return 0 ;
}
void F_98 ( struct V_32 * V_33 )
{
#ifdef F_99
struct V_1 * V_2 ;
V_2 = V_33 -> V_37 ;
if ( V_2 && F_4 ( V_38 , & V_2 -> V_9 ) )
F_100 ( V_2 -> V_36 ) ;
#endif
}
static int
F_101 ( void )
{
struct V_1 * V_2 ;
int V_25 ;
if ( V_141 )
return 0 ;
V_141 = 1 ;
V_25 = F_102 ( & V_116 ) ;
if ( V_25 == 0 ) {
F_54 ( & V_109 ) ;
V_142 = F_103 ( V_143 , L_2 ) ;
F_44 (rp, &raw3270_devices, list) {
F_68 ( & V_2 -> V_36 -> V_37 ) ;
F_86 ( V_2 ) ;
}
F_57 ( & V_109 ) ;
}
return V_25 ;
}
static void
F_104 ( void )
{
F_105 ( & V_116 ) ;
F_106 ( V_142 ) ;
}
