static inline int F_1 ( struct V_1 * * V_2 )
{
int V_3 = 1 ;
struct V_1 * V_4 = * V_2 ;
F_2 ( L_1 , V_4 -> V_5 -> V_6 ) ;
F_2 ( L_2 , V_4 -> V_5 -> V_7 ) ;
if ( F_3 ( V_4 -> V_5 ) )
V_3 = F_4 ( V_4 , V_8 , NULL ) ;
if ( V_3 )
return V_3 ;
V_4 -> V_9 -> V_10 = F_5 ( V_4 -> V_11 ) ;
if ( F_6 ( V_4 -> V_5 ) )
V_4 -> V_9 -> V_12 =
F_7 ( V_4 -> V_11 ) ;
else
V_4 -> V_9 -> V_12 = 0xFF ;
F_2 ( L_3 ,
V_4 -> V_11 ,
V_4 -> V_9 -> V_10 ,
V_4 -> V_9 -> V_12 ) ;
* V_2 = V_4 ;
return 0 ;
}
static inline int F_8 ( struct V_1 * * V_2 )
{
int V_3 ;
V_3 = F_4 ( * V_2 , V_13 , NULL ) ;
if ( V_3 )
return V_3 ;
if ( ! V_14 )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
static int T_1 F_9 ( void )
{
struct V_1 * V_4 ;
T_2 V_15 = 0 ;
F_10 (slot_cur, &ibmphp_slot_head, ibm_slot_list) {
V_15 = F_11 ( V_15 , V_4 -> V_16 ) ;
}
return V_15 ;
}
int F_12 ( struct V_1 * * V_17 )
{
struct V_18 * V_19 ;
int V_20 ;
int V_21 ;
int V_22 ;
V_19 = F_13 () ;
if ( ! V_19 ) {
F_14 ( L_4 ) ;
return - V_23 ;
}
V_20 = ( V_19 -> V_24 - sizeof( struct V_18 ) ) /
sizeof( struct V_25 ) ;
if ( ! V_20 ) {
F_15 ( V_19 ) ;
return - 1 ;
}
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( ( * V_17 ) -> V_16 == V_19 -> V_26 [ V_21 ] . V_1 &&
( * V_17 ) -> V_27 == V_19 -> V_26 [ V_21 ] . V_27 ) {
( * V_17 ) -> V_28 = F_16 ( V_19 -> V_26 [ V_21 ] . V_29 ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
( * V_17 ) -> V_30 [ V_22 ] = F_17 ( ( int ) ( * V_17 ) -> V_27 ,
( int ) ( * V_17 ) -> V_28 , V_22 ) ;
F_2 ( L_5 ,
( * V_17 ) -> V_30 [ 0 ] ) ;
F_2 ( L_6 ,
( * V_17 ) -> V_30 [ 1 ] ) ;
F_2 ( L_7 ,
( * V_17 ) -> V_30 [ 2 ] ) ;
F_2 ( L_8 ,
( * V_17 ) -> V_30 [ 3 ] ) ;
F_2 ( L_9 ,
V_19 -> V_31 ) ;
F_2 ( L_10 ,
V_19 -> V_26 [ V_21 ] . V_30 [ 0 ] . V_32 ) ;
F_2 ( L_11 ,
V_19 -> V_26 [ V_21 ] . V_30 [ 1 ] . V_32 ) ;
F_2 ( L_12 ,
V_19 -> V_26 [ V_21 ] . V_30 [ 2 ] . V_32 ) ;
F_2 ( L_13 ,
V_19 -> V_26 [ V_21 ] . V_30 [ 3 ] . V_32 ) ;
F_2 ( L_14 ,
V_19 -> V_26 [ V_21 ] . V_30 [ 0 ] . V_33 ) ;
F_2 ( L_15 ,
V_19 -> V_26 [ V_21 ] . V_30 [ 1 ] . V_33 ) ;
F_2 ( L_16 ,
V_19 -> V_26 [ V_21 ] . V_30 [ 2 ] . V_33 ) ;
F_2 ( L_17 ,
V_19 -> V_26 [ V_21 ] . V_30 [ 3 ] . V_33 ) ;
F_2 ( L_18 ) ;
F_15 ( V_19 ) ;
return 0 ;
}
}
F_15 ( V_19 ) ;
return - 1 ;
}
static inline int F_18 ( struct V_1 * V_4 )
{
T_2 V_34 = V_35 ;
int V_36 ;
V_36 = F_19 ( V_4 , V_34 ) ;
if ( V_36 ) {
F_14 ( L_19 ) ;
return V_36 ;
}
if ( F_20 ( V_4 -> V_5 -> V_37 ) ) {
F_14 ( L_20 ) ;
return - V_38 ;
}
F_21 ( 3000 ) ;
return 0 ;
}
static inline int F_22 ( struct V_1 * V_4 )
{
T_2 V_34 = V_39 ;
int V_36 ;
V_36 = F_19 ( V_4 , V_34 ) ;
if ( V_36 ) {
F_14 ( L_21 ) ;
return V_36 ;
}
if ( F_20 ( V_4 -> V_5 -> V_37 ) ) {
F_14 ( L_22 ) ;
V_36 = - V_38 ;
}
return V_36 ;
}
static int F_23 ( struct V_40 * V_40 , T_2 V_41 )
{
int V_3 = 0 ;
struct V_1 * V_42 ;
T_2 V_34 = 0x00 ;
F_2 ( L_23 ,
( V_43 ) V_40 , V_41 ) ;
F_24 () ;
if ( V_40 ) {
switch ( V_41 ) {
case V_44 :
V_34 = V_45 ;
break;
case V_46 :
V_34 = V_47 ;
break;
case V_48 :
V_34 = V_49 ;
break;
default:
V_3 = - V_50 ;
F_14 ( L_24 ,
V_41 ) ;
break;
}
if ( V_3 == 0 ) {
V_42 = V_40 -> V_51 ;
if ( V_42 )
V_3 = F_19 ( V_42 , V_34 ) ;
else
V_3 = - V_50 ;
}
} else
V_3 = - V_50 ;
F_25 () ;
F_2 ( L_25 , V_3 ) ;
return V_3 ;
}
static int F_26 ( struct V_40 * V_40 , T_2 * V_41 )
{
int V_3 = - V_50 ;
struct V_1 * V_42 ;
struct V_1 V_52 ;
F_2 ( L_26 ,
( V_43 ) V_40 , ( V_43 ) V_41 ) ;
F_24 () ;
if ( V_40 ) {
V_42 = V_40 -> V_51 ;
if ( V_42 ) {
memcpy ( & V_52 , V_42 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_42 , V_53 ,
& ( V_52 . V_37 ) ) ;
if ( ! V_3 )
V_3 = F_4 ( V_42 ,
V_54 ,
& ( V_52 . V_55 ) ) ;
if ( ! V_3 )
* V_41 = F_27 ( V_52 . V_37 ,
V_52 . V_55 ) ;
}
}
F_25 () ;
F_2 ( L_27 , V_3 , * V_41 ) ;
return V_3 ;
}
static int F_28 ( struct V_40 * V_40 , T_2 * V_41 )
{
int V_3 = - V_50 ;
struct V_1 * V_42 ;
struct V_1 V_52 ;
F_2 ( L_28 ,
( V_43 ) V_40 , ( V_43 ) V_41 ) ;
F_24 () ;
if ( V_40 ) {
V_42 = V_40 -> V_51 ;
if ( V_42 ) {
memcpy ( & V_52 , V_42 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_42 , V_53 ,
& ( V_52 . V_37 ) ) ;
if ( ! V_3 )
* V_41 = F_29 ( V_52 . V_37 ) ;
}
}
F_25 () ;
F_2 ( L_29 ,
V_3 , V_3 , * V_41 ) ;
return V_3 ;
}
static int F_30 ( struct V_40 * V_40 , T_2 * V_41 )
{
int V_3 = - V_50 ;
struct V_1 * V_42 ;
struct V_1 V_52 ;
F_2 ( L_30 ,
( V_43 ) V_40 , ( V_43 ) V_41 ) ;
F_24 () ;
if ( V_40 ) {
V_42 = V_40 -> V_51 ;
if ( V_42 ) {
memcpy ( & V_52 , V_42 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_42 , V_53 ,
& ( V_52 . V_37 ) ) ;
if ( ! V_3 )
* V_41 = F_31 ( V_52 . V_37 ) ;
}
}
F_25 () ;
F_2 ( L_31 ,
V_3 , V_3 , * V_41 ) ;
return V_3 ;
}
static int F_32 ( struct V_40 * V_40 , T_2 * V_41 )
{
int V_3 = - V_50 ;
struct V_1 * V_42 ;
T_2 V_56 ;
struct V_1 V_52 ;
F_2 ( L_32 ,
( V_43 ) V_40 , ( V_43 ) V_41 ) ;
F_24 () ;
if ( V_40 ) {
V_42 = V_40 -> V_51 ;
if ( V_42 ) {
memcpy ( & V_52 , V_42 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_42 , V_53 ,
& ( V_52 . V_37 ) ) ;
if ( ! V_3 ) {
V_56 = F_33 ( V_52 . V_37 ) ;
if ( V_56 == V_57 )
* V_41 = 0 ;
else
* V_41 = 1 ;
}
}
}
F_25 () ;
F_2 ( L_33 , V_3 , * V_41 ) ;
return V_3 ;
}
static int F_34 ( struct V_1 * V_1 )
{
int V_3 ;
T_2 V_58 = 0 ;
enum V_59 V_60 ;
struct V_61 * V_27 = V_1 -> V_40 -> V_62 -> V_27 ;
F_2 ( L_34 , V_63 , V_1 ) ;
F_24 () ;
V_58 = V_1 -> V_64 ;
V_60 = V_1 -> V_65 ;
F_25 () ;
switch ( V_60 ) {
case V_66 :
break;
case V_67 :
if ( V_58 == V_68 )
V_60 += 0x01 ;
break;
case V_69 :
case V_70 :
V_60 += 0x01 ;
break;
default:
V_3 = - V_50 ;
}
if ( ! V_3 )
V_27 -> V_71 = V_60 ;
F_2 ( L_35 , V_63 , V_3 , V_60 ) ;
return V_3 ;
}
static int T_1 F_35 ( void )
{
struct V_1 * V_4 ;
int V_36 ;
int V_3 ;
F_10 (slot_cur, &ibmphp_slot_head, ibm_slot_list) {
F_2 ( L_36 ,
V_4 -> V_16 ) ;
if ( V_4 -> V_5 -> V_7 == 0xFF )
if ( F_36 ( V_4 ,
& V_4 -> V_5 -> V_7 ) )
return - 1 ;
if ( V_4 -> V_9 -> V_10 == 0xFF )
if ( F_1 ( & V_4 ) )
return - 1 ;
F_34 ( V_4 ) ;
if ( V_4 -> V_5 -> V_6 == 0xFF )
if ( F_37 ( V_4 , & V_4 -> V_5 -> V_6 ) )
return - 1 ;
V_36 = F_8 ( & V_4 ) ;
if ( V_36 )
return V_36 ;
F_2 ( L_37 , V_4 -> V_37 ) ;
F_2 ( L_38 , V_4 -> V_55 ) ;
F_2 ( L_39 , F_38 ( V_4 -> V_37 ) ) ;
F_2 ( L_40 , F_33 ( V_4 -> V_37 ) ) ;
F_2 ( L_41 , F_29 ( V_4 -> V_37 ) ) ;
if ( ( F_31 ( V_4 -> V_37 ) ) &&
! ( F_33 ( V_4 -> V_37 ) ) &&
! ( F_29 ( V_4 -> V_37 ) ) ) {
F_2 ( L_42 ) ;
V_3 = F_22 ( V_4 ) ;
if ( V_3 )
return V_3 ;
}
}
V_14 = 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_4 , int V_72 )
{
int V_16 ;
int V_36 ;
if ( ! V_4 )
return - V_50 ;
V_16 = V_4 -> V_16 ;
if ( ( V_16 > V_73 ) || ( V_16 < 0 ) )
return - V_74 ;
F_2 ( L_43 , V_4 -> V_16 ) ;
V_36 = F_8 ( & V_4 ) ;
if ( V_36 )
return V_36 ;
switch ( V_72 ) {
case V_75 :
if ( ! ( F_31 ( V_4 -> V_37 ) ) &&
( F_33 ( V_4 -> V_37 ) ) &&
! ( F_29 ( V_4 -> V_37 ) ) )
return 0 ;
break;
case V_76 :
if ( ( F_31 ( V_4 -> V_37 ) ) &&
( F_33 ( V_4 -> V_37 ) ) &&
! ( F_29 ( V_4 -> V_37 ) ) )
return 0 ;
break;
default:
break;
}
F_14 ( L_44 ) ;
return - V_77 ;
}
int F_40 ( struct V_1 * V_4 )
{
struct V_78 * V_79 ;
struct V_61 * V_27 = V_4 -> V_40 -> V_62 -> V_27 ;
int V_3 ;
T_2 V_80 ;
T_2 V_58 ;
V_79 = F_41 ( sizeof( struct V_78 ) , V_81 ) ;
if ( ! V_79 ) {
F_14 ( L_45 ) ;
return - V_23 ;
}
V_79 -> V_82 = F_31 ( V_4 -> V_37 ) ;
V_79 -> V_83 = F_27 ( V_4 -> V_37 ,
V_4 -> V_55 ) ;
V_79 -> V_84 = F_29 ( V_4 -> V_37 ) ;
if ( ! F_33 ( V_4 -> V_37 ) ) {
V_79 -> V_85 = 0 ;
} else {
V_79 -> V_85 = 1 ;
}
V_80 = V_4 -> V_9 -> V_10 ;
V_58 = V_4 -> V_9 -> V_12 ;
switch ( V_80 ) {
case V_66 :
break;
case V_67 :
if ( V_58 == V_68 )
V_80 += 0x01 ;
else if ( V_58 == V_86 )
;
else
V_80 = V_87 ;
break;
case V_69 :
case V_70 :
V_80 += 0x01 ;
break;
default:
V_80 = V_87 ;
}
V_27 -> V_88 = V_80 ;
V_3 = F_42 ( V_4 -> V_40 , V_79 ) ;
F_15 ( V_79 ) ;
return V_3 ;
}
static struct V_89 * F_43 ( T_2 V_90 , T_2 V_28 , T_2 V_91 )
{
struct V_89 * V_92 ;
struct V_1 * V_4 ;
F_10 (slot_cur, &ibmphp_slot_head, ibm_slot_list) {
if ( V_4 -> V_93 ) {
V_92 = V_4 -> V_93 ;
while ( V_92 ) {
if ( ( V_92 -> V_90 == V_90 ) &&
( V_92 -> V_28 == V_28 ) &&
( V_92 -> V_91 == V_91 ) )
return V_92 ;
V_92 = V_92 -> V_94 ;
}
}
}
return NULL ;
}
static void F_44 ( void )
{
struct V_1 * V_4 , * V_94 ;
F_2 ( L_46 , V_63 ) ;
F_45 (slot_cur, next, &ibmphp_slot_head,
ibm_slot_list) {
F_46 ( V_4 -> V_40 ) ;
}
F_2 ( L_47 , V_63 ) ;
}
static void F_47 ( struct V_89 * V_93 )
{
struct V_95 * V_96 ;
T_2 V_97 ;
F_2 ( L_48 , V_63 ) ;
F_2 ( L_49 ,
V_93 -> V_28 , V_93 -> V_91 ) ;
F_2 ( L_50 , V_93 -> V_28 << 3 | 0x0 ) ;
F_48 () ;
for ( V_97 = 0 ; V_97 < 0x08 ; V_97 ++ ) {
V_96 = F_49 ( V_93 -> V_90 , ( V_93 -> V_28 << 3 ) | V_97 ) ;
if ( V_96 ) {
F_50 ( V_96 ) ;
F_51 ( V_96 ) ;
}
}
F_51 ( V_93 -> V_98 ) ;
F_52 () ;
}
static T_2 F_53 ( T_2 V_90 )
{
struct V_61 * V_27 , * V_99 ;
struct V_95 * V_98 ;
T_3 V_100 ;
if ( F_54 ( 0 , V_90 ) || ! ( F_55 ( V_90 ) ) )
return 1 ;
V_27 = F_41 ( sizeof( * V_27 ) , V_81 ) ;
if ( ! V_27 ) {
F_14 ( L_51 , V_63 ) ;
return 1 ;
}
V_98 = F_41 ( sizeof( * V_98 ) , V_81 ) ;
if ( ! V_98 ) {
F_15 ( V_27 ) ;
F_14 ( L_51 , V_63 ) ;
return 1 ;
}
V_27 -> V_16 = V_90 ;
V_27 -> V_101 = V_102 -> V_101 ;
V_98 -> V_27 = V_27 ;
for ( V_98 -> V_29 = 0 ; V_98 -> V_29 < 256 ; V_98 -> V_29 += 8 ) {
if ( ! F_56 ( V_98 , V_103 , & V_100 ) &&
( V_100 != 0x0000 ) && ( V_100 != 0xffff ) ) {
F_2 ( L_52 ,
V_63 ) ;
V_99 = F_57 ( V_90 , V_102 -> V_101 , NULL ) ;
if ( ! V_99 )
continue;
F_58 ( V_99 ) ;
break;
}
}
F_15 ( V_98 ) ;
F_15 ( V_27 ) ;
return 0 ;
}
static int F_59 ( struct V_89 * V_93 )
{
struct V_61 * V_104 ;
int V_105 ;
int V_106 = 0 ;
F_48 () ;
if ( ! ( F_53 ( V_93 -> V_90 ) ) )
V_106 = 1 ;
if ( V_93 -> V_98 == NULL )
V_93 -> V_98 = F_49 ( V_93 -> V_90 ,
F_60 ( V_93 -> V_28 , V_93 -> V_91 ) ) ;
if ( V_93 -> V_98 == NULL ) {
struct V_61 * V_27 = F_54 ( 0 , V_93 -> V_90 ) ;
if ( ! V_27 )
goto V_107;
V_105 = F_61 ( V_27 ,
F_60 ( V_93 -> V_28 , V_93 -> V_91 ) ) ;
if ( V_105 )
F_58 ( V_27 ) ;
V_93 -> V_98 = F_49 ( V_93 -> V_90 ,
F_60 ( V_93 -> V_28 , V_93 -> V_91 ) ) ;
if ( V_93 -> V_98 == NULL ) {
F_14 ( L_53 ) ;
goto V_107;
}
}
if ( ! ( V_106 ) && ( V_93 -> V_98 -> V_108 == V_109 ) ) {
F_62 ( V_93 -> V_98 ) ;
V_104 = V_93 -> V_98 -> V_110 ;
if ( V_104 )
F_58 ( V_104 ) ;
}
V_107:
F_52 () ;
return 0 ;
}
static int F_63 ( struct V_1 * V_4 )
{
int V_3 ;
struct V_1 * V_111 ;
T_2 V_22 = V_4 -> V_9 -> V_112 ;
while ( V_22 <= V_4 -> V_9 -> V_113 ) {
if ( V_22 == V_4 -> V_16 ) {
V_22 ++ ;
continue;
}
V_111 = F_64 ( V_22 ) ;
if ( ! V_111 )
return 0 ;
V_3 = F_8 ( & V_111 ) ;
if ( V_3 )
return 0 ;
if ( F_33 ( V_111 -> V_37 ) &&
F_31 ( V_111 -> V_37 ) )
return 0 ;
V_22 ++ ;
}
return 1 ;
}
static int F_65 ( struct V_1 * V_4 )
{
int V_3 ;
T_2 V_60 ;
T_2 V_34 = 0x0 ;
int V_36 ;
static const struct V_114 V_115 [] = {
{ F_66 (PCI_VENDOR_ID_SERVERWORKS, 0x0101 ) } ,
{ } ,
} ;
F_2 ( L_54 , V_63 , V_4 -> V_16 ) ;
if ( F_67 ( V_4 -> V_5 ) && F_63 ( V_4 ) ) {
V_3 = F_8 ( & V_4 ) ;
if ( V_3 )
return V_3 ;
V_60 = F_68 ( V_4 -> V_55 ) ;
F_2 ( L_55 , V_4 -> V_55 , V_60 ) ;
switch ( V_60 ) {
case V_116 :
V_34 = V_117 ;
break;
case V_118 :
if ( F_69 ( V_4 -> V_55 ) ) {
if ( ( V_4 -> V_65 >= V_67 ) &&
( V_4 -> V_64 == V_68 ) )
V_34 = V_119 ;
else if ( ! F_70 ( V_4 -> V_55 ) )
V_34 = V_120 ;
else
V_34 = V_117 ;
} else {
if ( V_4 -> V_65 >= V_67 )
V_34 = V_120 ;
else
V_34 = V_117 ;
}
break;
case V_121 :
switch ( V_4 -> V_65 ) {
case V_66 :
V_34 = V_117 ;
break;
case V_67 :
if ( V_4 -> V_64 == V_68 )
V_34 = V_119 ;
else
V_34 = V_120 ;
break;
case V_69 :
V_34 = V_122 ;
break;
case V_70 :
if ( F_71 ( V_115 ) )
F_19 ( V_4 ,
V_122 ) ;
V_34 = V_123 ;
break;
default:
F_14 ( L_56 ) ;
return - V_50 ;
}
break;
default:
F_14 ( L_57 ) ;
return - V_50 ;
}
F_2 ( L_58 ,
V_4 -> V_16 , V_34 ) ;
V_36 = F_19 ( V_4 , V_34 ) ;
if ( V_36 ) {
F_14 ( L_59 ) ;
return V_36 ;
}
if ( F_20 ( V_4 -> V_5 -> V_37 ) ) {
F_14 ( L_60 ) ;
return - V_38 ;
}
}
F_21 ( 1000 ) ;
F_2 ( L_61 , V_63 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_4 )
{
T_2 V_22 ;
struct V_1 * V_111 ;
T_2 V_124 = 0 ;
T_2 V_125 = 0 ;
for ( V_22 = V_4 -> V_9 -> V_112 ; V_22 <= V_4 -> V_9 -> V_113 ; V_22 ++ ) {
V_111 = F_64 ( V_22 ) ;
if ( ! V_111 )
return - V_50 ;
if ( ( F_31 ( V_111 -> V_37 ) ) &&
! ( F_73 ( V_111 -> V_37 ) ) )
V_124 ++ ;
}
F_1 ( & V_4 ) ;
switch ( V_4 -> V_9 -> V_10 ) {
case V_66 :
V_125 = V_4 -> V_9 -> V_126 ;
break;
case V_67 :
if ( V_4 -> V_9 -> V_12 == V_68 )
V_125 = V_4 -> V_9 -> V_127 ;
else
V_125 = V_4 -> V_9 -> V_128 ;
break;
case V_69 :
V_125 = V_4 -> V_9 -> V_129 ;
break;
case V_70 :
V_125 = V_4 -> V_9 -> V_130 ;
break;
}
if ( ( V_124 + 1 ) > V_125 )
return - V_77 ;
return 0 ;
}
static inline void F_74 ( struct V_1 * V_4 )
{
V_79 ( L_62 ) ;
if ( ( V_4 -> V_55 & V_131 ) == V_132 )
V_79 ( L_63 ) ;
else if ( ( V_4 -> V_55 & V_131 ) == V_133 )
V_79 ( L_64 ) ;
else if ( ( V_4 -> V_55 & V_131 ) == V_134 )
V_79 ( L_65 ) ;
else
V_79 ( L_66 ) ;
}
static int F_75 ( struct V_40 * V_135 )
{
int V_3 , V_22 , V_136 ;
struct V_1 * V_4 ;
T_2 V_91 ;
struct V_89 * V_137 ;
F_24 () ;
F_2 ( L_67 ) ;
V_4 = V_135 -> V_51 ;
V_3 = F_39 ( V_4 , V_75 ) ;
if ( V_3 ) {
F_14 ( L_68 ) ;
goto V_138;
}
F_76 ( V_4 ) ;
V_3 = F_65 ( V_4 ) ;
if ( V_3 ) {
F_14 ( L_69 ) ;
goto V_138;
}
F_1 ( & V_4 ) ;
F_2 ( L_70 ,
V_4 -> V_9 -> V_10 ) ;
V_3 = F_72 ( V_4 ) ;
if ( V_3 ) {
F_14 ( L_71 ) ;
F_14 ( L_72 ) ;
F_14 ( L_73 ) ;
V_3 = - V_77 ;
goto V_138;
}
V_3 = F_18 ( V_4 ) ;
if ( V_3 ) {
F_14 ( L_74 ) ;
F_77 ( V_4 ) ;
F_78 ( V_4 ) ;
if ( F_8 ( & V_4 ) ) {
F_77 ( V_4 ) ;
F_78 ( V_4 ) ;
V_3 = - V_50 ;
goto exit;
}
if ( ( F_38 ( V_4 -> V_37 ) ) &&
! ( F_31 ( V_4 -> V_37 ) ) )
F_14 ( L_75 ) ;
else if ( F_79 ( V_4 -> V_37 ) ) {
F_14 ( L_76 ) ;
F_74 ( V_4 ) ;
} else if ( F_70 ( V_4 -> V_55 ) ) {
F_14 ( L_77 ) ;
F_74 ( V_4 ) ;
}
F_40 ( V_4 ) ;
goto exit;
}
F_2 ( L_78 ) ;
F_1 ( & V_4 ) ;
F_2 ( L_79 ,
V_4 -> V_9 -> V_10 ) ;
V_3 = F_8 ( & V_4 ) ;
if ( V_3 )
goto V_139;
V_3 = - V_77 ;
if ( F_38 ( V_4 -> V_37 ) && ! ( F_31 ( V_4 -> V_37 ) ) ) {
F_14 ( L_80 ) ;
goto V_139;
}
if ( F_38 ( V_4 -> V_37 ) && ( F_79 ( V_4 -> V_37 ) ) ) {
F_14 ( L_76 ) ;
F_74 ( V_4 ) ;
goto V_139;
}
if ( ! ( F_38 ( V_4 -> V_37 ) ) ) {
F_14 ( L_81 ) ;
goto V_139;
}
V_4 -> V_93 = F_80 ( sizeof( struct V_89 ) , V_81 ) ;
if ( ! V_4 -> V_93 ) {
F_14 ( L_45 ) ;
V_3 = - V_23 ;
goto V_139;
}
V_4 -> V_93 -> V_90 = V_4 -> V_27 ;
V_4 -> V_93 -> V_28 = V_4 -> V_28 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
V_4 -> V_93 -> V_30 [ V_22 ] = V_4 -> V_30 [ V_22 ] ;
F_2 ( L_82 ,
V_4 -> V_27 , V_4 -> V_28 ) ;
if ( F_81 ( V_4 -> V_93 , V_4 -> V_16 ) ) {
F_14 ( L_83 ) ;
F_82 ( & V_4 , 1 ) ;
F_2 ( L_84 ) ;
V_4 -> V_93 = NULL ;
V_3 = - V_23 ;
goto V_139;
}
V_91 = 0x00 ;
do {
V_137 = F_43 ( V_4 -> V_27 , V_4 -> V_93 -> V_28 ,
V_91 ++ ) ;
if ( V_137 && ! ( V_137 -> V_98 ) )
F_59 ( V_137 ) ;
} while ( V_137 );
F_77 ( V_4 ) ;
if ( F_8 ( & V_4 ) ) {
V_3 = - V_140 ;
goto exit;
}
F_83 () ;
V_3 = F_40 ( V_4 ) ;
exit:
F_25 () ;
return V_3 ;
V_138:
F_77 ( V_4 ) ;
F_78 ( V_4 ) ;
V_141:
V_136 = F_8 ( & V_4 ) ;
if ( V_136 ) {
V_3 = V_136 ;
goto exit;
}
F_40 ( V_4 ) ;
goto exit;
V_139:
F_77 ( V_4 ) ;
F_78 ( V_4 ) ;
V_136 = F_22 ( V_4 ) ;
if ( V_136 ) {
V_3 = V_136 ;
goto exit;
}
goto V_141;
}
static int F_84 ( struct V_40 * V_40 )
{
struct V_1 * V_1 = V_40 -> V_51 ;
int V_3 ;
F_24 () ;
V_3 = F_85 ( V_1 ) ;
F_25 () ;
return V_3 ;
}
int F_85 ( struct V_1 * V_4 )
{
int V_3 ;
T_2 V_106 ;
F_2 ( L_85 ) ;
if ( ( V_4 == NULL ) || ( V_4 -> V_5 == NULL ) )
return - V_50 ;
V_106 = V_4 -> V_106 ;
V_4 -> V_106 = 1 ;
if ( V_106 == 1 ) {
V_3 = F_39 ( V_4 , V_76 ) ;
if ( V_3 )
goto error;
}
F_76 ( V_4 ) ;
if ( V_4 -> V_93 == NULL ) {
V_4 -> V_93 = F_80 ( sizeof( struct V_89 ) , V_81 ) ;
if ( ! V_4 -> V_93 ) {
F_14 ( L_45 ) ;
V_3 = - V_23 ;
goto error;
}
V_4 -> V_93 -> V_90 = V_4 -> V_27 ;
V_4 -> V_93 -> V_28 = V_4 -> V_28 ;
}
F_47 ( V_4 -> V_93 ) ;
if ( ! V_106 ) {
F_77 ( V_4 ) ;
return 0 ;
}
V_3 = F_82 ( & V_4 , 0 ) ;
V_4 -> V_93 = NULL ;
F_2 ( L_86 ) ;
if ( V_3 ) {
F_14 ( L_87 ) ;
goto error;
}
V_3 = F_19 ( V_4 , V_39 ) ;
if ( V_3 )
goto error;
F_77 ( V_4 ) ;
V_3 = F_8 ( & V_4 ) ;
if ( V_3 )
goto exit;
V_3 = F_40 ( V_4 ) ;
F_83 () ;
exit:
return V_3 ;
error:
F_77 ( V_4 ) ;
F_78 ( V_4 ) ;
if ( F_8 ( & V_4 ) ) {
V_3 = - V_140 ;
goto exit;
}
if ( V_106 )
F_40 ( V_4 ) ;
goto exit;
}
static void F_86 ( void )
{
F_44 () ;
F_2 ( L_88 ) ;
F_87 () ;
F_2 ( L_89 ) ;
F_88 () ;
F_2 ( L_90 ) ;
F_89 () ;
F_2 ( L_91 ) ;
F_90 () ;
F_2 ( L_92 ) ;
F_15 ( V_102 ) ;
}
static int T_1 F_91 ( void )
{
struct V_61 * V_27 ;
int V_22 = 0 ;
int V_3 = 0 ;
V_14 = 1 ;
V_79 ( V_142 L_93 V_143 L_94 ) ;
V_102 = F_41 ( sizeof( * V_102 ) , V_81 ) ;
if ( ! V_102 ) {
F_14 ( L_95 ) ;
V_3 = - V_23 ;
goto exit;
}
V_27 = F_54 ( 0 , 0 ) ;
if ( ! V_27 ) {
F_14 ( L_96 ) ;
V_3 = - V_50 ;
goto error;
}
memcpy ( V_102 , V_27 , sizeof( * V_102 ) ) ;
V_144 = F_2 ;
F_92 () ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ )
V_145 [ V_22 ] = 0 ;
V_3 = F_93 () ;
if ( V_3 )
goto error;
F_2 ( L_97 ) ;
V_3 = F_94 () ;
if ( V_3 )
goto error;
F_2 ( L_98 ) ;
V_73 = F_9 () ;
V_3 = F_95 () ;
if ( V_3 )
goto error;
if ( F_35 () ) {
V_3 = - V_50 ;
goto error;
}
F_83 () ;
V_3 = F_96 () ;
if ( V_3 )
goto error;
exit:
return V_3 ;
error:
F_86 () ;
goto exit;
}
static void T_4 F_97 ( void )
{
F_98 () ;
F_2 ( L_99 ) ;
F_86 () ;
F_2 ( L_100 ) ;
}
