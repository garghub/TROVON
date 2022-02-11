static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_3 , V_4 ) ;
if ( F_3 ( V_5 != 0 ) )
return - V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_5 ( V_2 -> V_6 , V_3 , V_4 ) ;
if ( F_3 ( V_5 != 0 ) )
return - V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
T_1 V_8 )
{
int V_9 ;
int V_10 = 0 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
T_1 V_14 ;
V_12 = ( V_8 * V_15 ) + V_16 ;
while ( 1 ) {
V_9 = F_1 ( V_2 , V_17 ,
( V_12 & 0x0000F000 ) >> 12 ) ;
if ( V_9 )
goto error;
V_9 = F_1 ( V_2 , V_18 ,
( V_12 & 0x00FF0000 ) >> 16 ) ;
if ( V_9 )
goto error;
V_9 = F_1 ( V_2 , V_19 ,
( V_12 & 0xFF000000 ) >> 24 ) ;
if ( V_9 )
goto error;
V_13 = 0 ;
V_9 = F_4 ( V_2 , V_17 , & V_14 ) ;
if ( V_9 )
goto error;
V_13 |= ( ( T_2 ) ( V_14 & 0x0F ) ) << 12 ;
V_9 = F_4 ( V_2 , V_18 , & V_14 ) ;
if ( V_9 )
goto error;
V_13 |= ( ( T_2 ) V_14 ) << 16 ;
V_9 = F_4 ( V_2 , V_19 , & V_14 ) ;
if ( V_9 )
goto error;
V_13 |= ( ( T_2 ) V_14 ) << 24 ;
V_11 = ( V_13 - V_16 ) / V_15 ;
if ( V_11 == V_8 )
break;
V_9 = - V_20 ;
if ( V_10 ++ > V_21 )
goto error;
F_7 ( 10 ) ;
}
return 0 ;
error:
F_8 (KERN_ERR PFX L_1 , coreidx) ;
return V_9 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
int V_9 ;
#if V_24
F_8 (KERN_INFO PFX
L_2 ,
ssb_core_name(dev->id.coreid),
dev->core_index) ;
#endif
V_9 = F_6 ( V_2 , V_23 -> V_25 ) ;
if ( ! V_9 )
V_2 -> V_26 = V_23 ;
return V_9 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_27 )
{
int V_10 = 0 ;
int V_9 ;
T_1 V_14 ;
F_11 ( ( V_27 != 0 ) && ( V_27 != 1 ) ) ;
while ( 1 ) {
V_9 = F_1 ( V_2 , V_28 , V_27 ) ;
if ( V_9 )
goto error;
V_9 = F_4 ( V_2 , V_28 , & V_14 ) ;
if ( V_9 )
goto error;
if ( V_14 == V_27 )
break;
V_9 = - V_20 ;
if ( F_3 ( V_10 ++ > V_21 ) )
goto error;
F_7 ( 10 ) ;
}
V_2 -> V_29 = V_27 ;
return 0 ;
error:
F_8 (KERN_ERR PFX L_3 ) ;
return V_9 ;
}
static int F_12 ( struct V_22 * V_23 ,
T_3 * V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
int V_9 ;
T_1 V_30 ;
if ( * V_3 >= 0x800 ) {
* V_3 -= 0x800 ;
V_30 = 1 ;
} else
V_30 = 0 ;
if ( F_3 ( V_23 != V_2 -> V_26 ) ) {
V_9 = F_9 ( V_2 , V_23 ) ;
if ( F_3 ( V_9 ) )
return V_9 ;
}
if ( F_3 ( V_30 != V_2 -> V_29 ) ) {
V_9 = F_10 ( V_2 , V_30 ) ;
if ( F_3 ( V_9 ) )
return V_9 ;
}
return 0 ;
}
static T_1 F_13 ( struct V_22 * V_23 , T_3 V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_31 ;
int V_9 ;
T_1 V_4 = 0xFF ;
F_14 ( & V_2 -> V_32 , V_31 ) ;
V_9 = F_12 ( V_23 , & V_3 ) ;
if ( F_15 ( ! V_9 ) )
V_4 = F_16 ( V_2 -> V_33 + V_3 ) ;
F_17 ( & V_2 -> V_32 , V_31 ) ;
return V_4 ;
}
static T_3 F_18 ( struct V_22 * V_23 , T_3 V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_31 ;
int V_9 ;
T_3 V_4 = 0xFFFF ;
F_14 ( & V_2 -> V_32 , V_31 ) ;
V_9 = F_12 ( V_23 , & V_3 ) ;
if ( F_15 ( ! V_9 ) )
V_4 = F_19 ( V_2 -> V_33 + V_3 ) ;
F_17 ( & V_2 -> V_32 , V_31 ) ;
return V_4 ;
}
static T_2 F_20 ( struct V_22 * V_23 , T_3 V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_31 ;
int V_9 ;
T_2 V_34 = 0xFFFFFFFF , V_35 = 0xFFFFFFFF ;
F_14 ( & V_2 -> V_32 , V_31 ) ;
V_9 = F_12 ( V_23 , & V_3 ) ;
if ( F_15 ( ! V_9 ) ) {
V_34 = F_19 ( V_2 -> V_33 + V_3 ) ;
V_35 = F_19 ( V_2 -> V_33 + V_3 + 2 ) ;
}
F_17 ( & V_2 -> V_32 , V_31 ) ;
return ( V_34 | ( V_35 << 16 ) ) ;
}
static void F_21 ( struct V_22 * V_23 , void * V_36 ,
T_4 V_37 , T_3 V_3 , T_1 V_38 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_31 ;
void T_5 * V_12 = V_2 -> V_33 + V_3 ;
int V_9 ;
F_14 ( & V_2 -> V_32 , V_31 ) ;
V_9 = F_12 ( V_23 , & V_3 ) ;
if ( F_3 ( V_9 ) ) {
memset ( V_36 , 0xFF , V_37 ) ;
goto V_39;
}
switch ( V_38 ) {
case sizeof( T_1 ) : {
T_1 * V_40 = V_36 ;
while ( V_37 ) {
* V_40 = F_22 ( V_12 ) ;
V_40 ++ ;
V_37 -- ;
}
break;
}
case sizeof( T_3 ) : {
T_6 * V_40 = V_36 ;
F_11 ( V_37 & 1 ) ;
while ( V_37 ) {
* V_40 = ( V_41 T_6 ) F_23 ( V_12 ) ;
V_40 ++ ;
V_37 -= 2 ;
}
break;
}
case sizeof( T_2 ) : {
T_6 * V_40 = V_36 ;
F_11 ( V_37 & 3 ) ;
while ( V_37 ) {
* V_40 = ( V_41 T_6 ) F_23 ( V_12 ) ;
V_40 ++ ;
* V_40 = ( V_41 T_6 ) F_23 ( V_12 + 2 ) ;
V_40 ++ ;
V_37 -= 4 ;
}
break;
}
default:
F_11 ( 1 ) ;
}
V_39:
F_17 ( & V_2 -> V_32 , V_31 ) ;
}
static void F_24 ( struct V_22 * V_23 , T_3 V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_31 ;
int V_9 ;
F_14 ( & V_2 -> V_32 , V_31 ) ;
V_9 = F_12 ( V_23 , & V_3 ) ;
if ( F_15 ( ! V_9 ) )
F_25 ( V_4 , V_2 -> V_33 + V_3 ) ;
F_26 () ;
F_17 ( & V_2 -> V_32 , V_31 ) ;
}
static void F_27 ( struct V_22 * V_23 , T_3 V_3 , T_3 V_4 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_31 ;
int V_9 ;
F_14 ( & V_2 -> V_32 , V_31 ) ;
V_9 = F_12 ( V_23 , & V_3 ) ;
if ( F_15 ( ! V_9 ) )
F_28 ( V_4 , V_2 -> V_33 + V_3 ) ;
F_26 () ;
F_17 ( & V_2 -> V_32 , V_31 ) ;
}
static void F_29 ( struct V_22 * V_23 , T_3 V_3 , T_2 V_4 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_31 ;
int V_9 ;
F_14 ( & V_2 -> V_32 , V_31 ) ;
V_9 = F_12 ( V_23 , & V_3 ) ;
if ( F_15 ( ! V_9 ) ) {
F_28 ( ( V_4 & 0x0000FFFF ) , V_2 -> V_33 + V_3 ) ;
F_28 ( ( ( V_4 & 0xFFFF0000 ) >> 16 ) , V_2 -> V_33 + V_3 + 2 ) ;
}
F_26 () ;
F_17 ( & V_2 -> V_32 , V_31 ) ;
}
static void F_30 ( struct V_22 * V_23 , const void * V_36 ,
T_4 V_37 , T_3 V_3 , T_1 V_38 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned long V_31 ;
void T_5 * V_12 = V_2 -> V_33 + V_3 ;
int V_9 ;
F_14 ( & V_2 -> V_32 , V_31 ) ;
V_9 = F_12 ( V_23 , & V_3 ) ;
if ( F_3 ( V_9 ) )
goto V_39;
switch ( V_38 ) {
case sizeof( T_1 ) : {
const T_1 * V_40 = V_36 ;
while ( V_37 ) {
F_31 ( * V_40 , V_12 ) ;
V_40 ++ ;
V_37 -- ;
}
break;
}
case sizeof( T_3 ) : {
const T_6 * V_40 = V_36 ;
F_11 ( V_37 & 1 ) ;
while ( V_37 ) {
F_32 ( ( V_41 T_3 ) ( * V_40 ) , V_12 ) ;
V_40 ++ ;
V_37 -= 2 ;
}
break;
}
case sizeof( T_2 ) : {
const T_6 * V_40 = V_36 ;
F_11 ( V_37 & 3 ) ;
while ( V_37 ) {
F_32 ( ( V_41 T_3 ) ( * V_40 ) , V_12 ) ;
V_40 ++ ;
F_32 ( ( V_41 T_3 ) ( * V_40 ) , V_12 + 2 ) ;
V_40 ++ ;
V_37 -= 4 ;
}
break;
}
default:
F_11 ( 1 ) ;
}
V_39:
F_26 () ;
F_17 ( & V_2 -> V_32 , V_31 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_42 )
{
unsigned int V_43 ;
int V_9 ;
T_1 V_4 ;
V_9 = F_1 ( V_2 , V_44 , V_42 ) ;
if ( V_9 )
return V_9 ;
for ( V_43 = 0 ; V_43 < 1000 ; V_43 ++ ) {
V_9 = F_4 ( V_2 , V_44 , & V_4 ) ;
if ( V_9 )
return V_9 ;
if ( V_4 & V_45 )
return 0 ;
F_7 ( 10 ) ;
}
return - V_20 ;
}
static int F_34 ( struct V_1 * V_2 , T_3 V_3 , T_3 * V_4 )
{
int V_9 ;
T_1 V_34 , V_35 ;
V_3 *= 2 ;
V_9 = F_1 ( V_2 , V_46 ,
( V_3 & 0x00FF ) ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_2 , V_47 ,
( V_3 & 0xFF00 ) >> 8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_33 ( V_2 , V_48 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_2 , V_49 , & V_34 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_2 , V_50 , & V_35 ) ;
if ( V_9 )
return V_9 ;
* V_4 = ( V_34 | ( ( ( T_3 ) V_35 ) << 8 ) ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_3 V_3 , T_3 V_4 )
{
int V_9 ;
V_3 *= 2 ;
V_9 = F_1 ( V_2 , V_46 ,
( V_3 & 0x00FF ) ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_2 , V_47 ,
( V_3 & 0xFF00 ) >> 8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_2 , V_49 ,
( V_4 & 0x00FF ) ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_2 , V_50 ,
( V_4 & 0xFF00 ) >> 8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_33 ( V_2 , V_51 ) ;
if ( V_9 )
return V_9 ;
F_36 ( 20 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_3 * V_52 )
{
int V_9 , V_43 ;
for ( V_43 = 0 ; V_43 < V_53 ; V_43 ++ ) {
V_9 = F_34 ( V_2 , V_43 , & V_52 [ V_43 ] ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , const T_3 * V_52 )
{
int V_43 , V_9 ;
bool V_54 = 0 ;
T_4 V_55 = V_53 ;
F_8 (KERN_NOTICE PFX
L_4
L_5 ) ;
V_9 = F_33 ( V_2 , V_56 ) ;
if ( V_9 ) {
F_8 (KERN_NOTICE PFX
L_6 ) ;
return - V_7 ;
}
F_8 (KERN_NOTICE PFX L_7 ) ;
F_36 ( 500 ) ;
for ( V_43 = 0 ; V_43 < V_55 ; V_43 ++ ) {
if ( V_43 == V_55 / 4 )
F_8 ( L_8 ) ;
else if ( V_43 == V_55 / 2 )
F_8 ( L_9 ) ;
else if ( V_43 == ( V_55 * 3 ) / 4 )
F_8 ( L_10 ) ;
else if ( V_43 % 2 )
F_8 ( L_11 ) ;
V_9 = F_35 ( V_2 , V_43 , V_52 [ V_43 ] ) ;
if ( V_9 ) {
F_8 (KERN_NOTICE PFX
L_12 ) ;
V_54 = 1 ;
break;
}
}
V_9 = F_33 ( V_2 , V_57 ) ;
if ( V_9 ) {
F_8 (KERN_NOTICE PFX
L_13 ) ;
V_54 = 1 ;
}
F_36 ( 500 ) ;
if ( ! V_54 ) {
F_8 ( L_14 ) ;
F_8 (KERN_NOTICE PFX L_15 ) ;
}
return V_54 ? - V_7 : 0 ;
}
static int F_39 ( const T_3 * V_52 , T_4 V_55 )
{
return 0 ;
}
static int F_40 ( struct V_58 * V_59 ,
T_7 * V_60 ,
void * V_61 )
{
struct V_62 * V_52 = V_61 ;
if ( V_60 -> V_63 [ 0 ] != V_64 )
return - V_65 ;
if ( V_60 -> V_66 != V_67 + 2 )
return - V_65 ;
if ( V_60 -> V_63 [ 1 ] != V_67 )
return - V_65 ;
memcpy ( V_52 -> V_68 , & V_60 -> V_63 [ 2 ] , V_67 ) ;
return 0 ;
}
static int F_41 ( struct V_58 * V_59 ,
T_7 * V_60 ,
void * V_61 )
{
struct V_69 * V_70 = V_61 ;
struct V_62 * V_52 = & V_70 -> V_52 ;
struct V_71 * V_72 = & V_70 -> V_73 ;
const char * V_74 ;
F_42 ( V_60 -> V_66 < 1 , L_16 ) ;
switch ( V_60 -> V_63 [ 0 ] ) {
case V_75 :
F_42 ( ( V_60 -> V_66 != 5 ) &&
( V_60 -> V_66 != 7 ) ,
L_17 ) ;
V_72 -> V_76 = V_60 -> V_63 [ 1 ] |
( ( T_3 ) V_60 -> V_63 [ 2 ] << 8 ) ;
break;
case V_77 :
F_42 ( V_60 -> V_66 != 2 ,
L_18 ) ;
V_52 -> V_78 = V_60 -> V_63 [ 1 ] ;
break;
case V_79 :
F_42 ( ( V_60 -> V_66 != 9 ) &&
( V_60 -> V_66 != 10 ) ,
L_19 ) ;
V_52 -> V_80 = V_60 -> V_63 [ 1 ] |
( ( T_3 ) V_60 -> V_63 [ 2 ] << 8 ) ;
V_52 -> V_81 = V_60 -> V_63 [ 3 ] |
( ( T_3 ) V_60 -> V_63 [ 4 ] << 8 ) ;
V_52 -> V_82 = V_60 -> V_63 [ 5 ] |
( ( T_3 ) V_60 -> V_63 [ 6 ] << 8 ) ;
V_52 -> V_83 = V_60 -> V_63 [ 7 ] ;
V_52 -> V_84 = V_60 -> V_63 [ 7 ] ;
V_52 -> V_85 = V_60 -> V_63 [ 8 ] ;
V_52 -> V_86 = V_60 -> V_63 [ 8 ] ;
break;
case V_87 :
break;
case V_88 :
F_42 ( V_60 -> V_66 != 2 ,
L_20 ) ;
V_52 -> V_89 = V_60 -> V_63 [ 1 ] ;
break;
case V_90 :
F_42 ( V_60 -> V_66 != 2 ,
L_21 ) ;
V_52 -> V_91 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_92 = V_60 -> V_63 [ 1 ] ;
break;
case V_93 :
F_42 ( V_60 -> V_66 != 2 ,
L_22 ) ;
V_52 -> V_94 . V_95 . V_96 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_94 . V_95 . V_97 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_94 . V_95 . V_98 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_94 . V_95 . V_99 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_94 . V_100 . V_96 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_94 . V_100 . V_97 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_94 . V_100 . V_98 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_94 . V_100 . V_99 = V_60 -> V_63 [ 1 ] ;
break;
case V_101 :
F_42 ( ( V_60 -> V_66 != 3 ) &&
( V_60 -> V_66 != 5 ) ,
L_23 ) ;
V_52 -> V_102 = V_60 -> V_63 [ 1 ] |
( ( T_3 ) V_60 -> V_63 [ 2 ] << 8 ) ;
break;
case V_103 :
F_42 ( V_60 -> V_66 != 5 ,
L_24 ) ;
V_52 -> V_104 = V_60 -> V_63 [ 1 ] ;
V_52 -> V_105 = V_60 -> V_63 [ 2 ] ;
V_52 -> V_106 = V_60 -> V_63 [ 3 ] ;
V_52 -> V_107 = V_60 -> V_63 [ 4 ] ;
break;
}
return - V_108 ;
error:
F_8 (KERN_ERR PFX
L_25 ,
error_description) ;
return - V_109 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_62 * V_52 = & V_70 -> V_52 ;
int V_5 ;
memset ( V_52 , 0xFF , sizeof( * V_52 ) ) ;
V_52 -> V_110 = 1 ;
V_52 -> V_102 = 0 ;
V_52 -> V_111 = 0 ;
V_5 = F_44 ( V_2 -> V_6 , V_112 ,
F_40 , V_52 ) ;
if ( V_5 != 0 ) {
F_8 (KERN_ERR PFX
L_26 ) ;
return - V_109 ;
}
V_5 = F_44 ( V_2 -> V_6 , V_113 ,
F_41 , V_70 ) ;
if ( ( V_5 == 0 ) || ( V_5 == - V_108 ) )
return 0 ;
F_8 (KERN_ERR PFX
L_27 ) ;
return - V_109 ;
}
static T_8 F_45 ( struct V_114 * V_115 ,
struct V_116 * V_117 ,
char * V_40 )
{
struct V_58 * V_118 =
F_46 ( V_115 , struct V_58 , V_23 ) ;
struct V_1 * V_2 ;
V_2 = F_47 ( V_118 ) ;
if ( ! V_2 )
return - V_109 ;
return F_48 ( V_2 , V_40 ,
F_37 ) ;
}
static T_8 F_49 ( struct V_114 * V_115 ,
struct V_116 * V_117 ,
const char * V_40 , T_4 V_37 )
{
struct V_58 * V_118 =
F_46 ( V_115 , struct V_58 , V_23 ) ;
struct V_1 * V_2 ;
V_2 = F_47 ( V_118 ) ;
if ( ! V_2 )
return - V_109 ;
return F_50 ( V_2 , V_40 , V_37 ,
F_39 ,
F_38 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_119 )
{
T_1 V_14 ;
int V_9 ;
V_9 = F_4 ( V_2 , V_119 , & V_14 ) ;
if ( V_9 )
return V_9 ;
V_14 &= ~ V_120 ;
V_14 |= V_121 | V_122 | V_123 ;
V_9 = F_1 ( V_2 , V_119 , V_14 ) ;
if ( V_9 )
return V_9 ;
F_36 ( 40 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_124 != V_125 )
return 0 ;
F_10 ( V_2 , 0 ) ;
V_9 = F_51 ( V_2 , V_126 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_51 ( V_2 , V_126 + 0x80 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_124 != V_125 )
return;
F_54 ( & V_2 -> V_6 -> V_23 , & V_127 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_124 != V_125 )
return 0 ;
V_9 = F_52 ( V_2 ) ;
if ( V_9 )
goto error;
V_2 -> V_128 = V_53 ;
F_56 ( & V_2 -> V_129 ) ;
V_9 = F_57 ( & V_2 -> V_6 -> V_23 , & V_127 ) ;
if ( V_9 )
goto error;
return 0 ;
error:
F_8 (KERN_ERR PFX L_28 ) ;
return V_9 ;
}
