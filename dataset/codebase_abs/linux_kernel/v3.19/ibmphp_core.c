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
struct V_15 * V_16 ;
T_2 V_17 = 0 ;
F_10 (tmp, &ibmphp_slot_head) {
V_4 = F_11 ( V_16 , struct V_1 , V_18 ) ;
V_17 = F_12 ( V_17 , V_4 -> V_19 ) ;
}
return V_17 ;
}
int F_13 ( struct V_1 * * V_20 )
{
struct V_21 * V_22 ;
int V_23 ;
int V_24 ;
int V_25 ;
V_22 = F_14 () ;
if ( ! V_22 ) {
F_15 ( L_4 ) ;
return - V_26 ;
}
V_23 = ( V_22 -> V_27 - sizeof( struct V_21 ) ) /
sizeof( struct V_28 ) ;
if ( ! V_23 ) {
F_16 ( V_22 ) ;
return - 1 ;
}
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
if ( ( * V_20 ) -> V_19 == V_22 -> V_29 [ V_24 ] . V_1 &&
( * V_20 ) -> V_30 == V_22 -> V_29 [ V_24 ] . V_30 ) {
( * V_20 ) -> V_31 = F_17 ( V_22 -> V_29 [ V_24 ] . V_32 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
( * V_20 ) -> V_33 [ V_25 ] = F_18 ( ( int ) ( * V_20 ) -> V_30 ,
( int ) ( * V_20 ) -> V_31 , V_25 ) ;
F_2 ( L_5 ,
( * V_20 ) -> V_33 [ 0 ] ) ;
F_2 ( L_6 ,
( * V_20 ) -> V_33 [ 1 ] ) ;
F_2 ( L_7 ,
( * V_20 ) -> V_33 [ 2 ] ) ;
F_2 ( L_8 ,
( * V_20 ) -> V_33 [ 3 ] ) ;
F_2 ( L_9 ,
V_22 -> V_34 ) ;
F_2 ( L_10 ,
V_22 -> V_29 [ V_24 ] . V_33 [ 0 ] . V_35 ) ;
F_2 ( L_11 ,
V_22 -> V_29 [ V_24 ] . V_33 [ 1 ] . V_35 ) ;
F_2 ( L_12 ,
V_22 -> V_29 [ V_24 ] . V_33 [ 2 ] . V_35 ) ;
F_2 ( L_13 ,
V_22 -> V_29 [ V_24 ] . V_33 [ 3 ] . V_35 ) ;
F_2 ( L_14 ,
V_22 -> V_29 [ V_24 ] . V_33 [ 0 ] . V_36 ) ;
F_2 ( L_15 ,
V_22 -> V_29 [ V_24 ] . V_33 [ 1 ] . V_36 ) ;
F_2 ( L_16 ,
V_22 -> V_29 [ V_24 ] . V_33 [ 2 ] . V_36 ) ;
F_2 ( L_17 ,
V_22 -> V_29 [ V_24 ] . V_33 [ 3 ] . V_36 ) ;
F_2 ( L_18 ) ;
F_16 ( V_22 ) ;
return 0 ;
}
}
F_16 ( V_22 ) ;
return - 1 ;
}
static inline int F_19 ( struct V_1 * V_4 )
{
T_2 V_37 = V_38 ;
int V_39 ;
V_39 = F_20 ( V_4 , V_37 ) ;
if ( V_39 ) {
F_15 ( L_19 ) ;
return V_39 ;
}
if ( F_21 ( V_4 -> V_5 -> V_40 ) ) {
F_15 ( L_20 ) ;
return - V_41 ;
}
F_22 ( 3000 ) ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_4 )
{
T_2 V_37 = V_42 ;
int V_39 ;
V_39 = F_20 ( V_4 , V_37 ) ;
if ( V_39 ) {
F_15 ( L_21 ) ;
return V_39 ;
}
if ( F_21 ( V_4 -> V_5 -> V_40 ) ) {
F_15 ( L_22 ) ;
V_39 = - V_41 ;
}
return V_39 ;
}
static int F_24 ( struct V_43 * V_43 , T_2 V_44 )
{
int V_3 = 0 ;
struct V_1 * V_45 ;
T_2 V_37 = 0x00 ;
F_2 ( L_23 ,
( V_46 ) V_43 , V_44 ) ;
F_25 () ;
if ( V_43 ) {
switch ( V_44 ) {
case V_47 :
V_37 = V_48 ;
break;
case V_49 :
V_37 = V_50 ;
break;
case V_51 :
V_37 = V_52 ;
break;
default:
V_3 = - V_53 ;
F_15 ( L_24 ,
V_44 ) ;
break;
}
if ( V_3 == 0 ) {
V_45 = V_43 -> V_54 ;
if ( V_45 )
V_3 = F_20 ( V_45 , V_37 ) ;
else
V_3 = - V_53 ;
}
} else
V_3 = - V_53 ;
F_26 () ;
F_2 ( L_25 , V_3 ) ;
return V_3 ;
}
static int F_27 ( struct V_43 * V_43 , T_2 * V_44 )
{
int V_3 = - V_53 ;
struct V_1 * V_45 ;
struct V_1 V_55 ;
F_2 ( L_26 ,
( V_46 ) V_43 , ( V_46 ) V_44 ) ;
F_25 () ;
if ( V_43 ) {
V_45 = V_43 -> V_54 ;
if ( V_45 ) {
memcpy ( & V_55 , V_45 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_45 , V_56 ,
& ( V_55 . V_40 ) ) ;
if ( ! V_3 )
V_3 = F_4 ( V_45 ,
V_57 ,
& ( V_55 . V_58 ) ) ;
if ( ! V_3 )
* V_44 = F_28 ( V_55 . V_40 ,
V_55 . V_58 ) ;
}
}
F_26 () ;
F_2 ( L_27 , V_3 , * V_44 ) ;
return V_3 ;
}
static int F_29 ( struct V_43 * V_43 , T_2 * V_44 )
{
int V_3 = - V_53 ;
struct V_1 * V_45 ;
struct V_1 V_55 ;
F_2 ( L_28 ,
( V_46 ) V_43 , ( V_46 ) V_44 ) ;
F_25 () ;
if ( V_43 ) {
V_45 = V_43 -> V_54 ;
if ( V_45 ) {
memcpy ( & V_55 , V_45 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_45 , V_56 ,
& ( V_55 . V_40 ) ) ;
if ( ! V_3 )
* V_44 = F_30 ( V_55 . V_40 ) ;
}
}
F_26 () ;
F_2 ( L_29 ,
V_3 , V_3 , * V_44 ) ;
return V_3 ;
}
static int F_31 ( struct V_43 * V_43 , T_2 * V_44 )
{
int V_3 = - V_53 ;
struct V_1 * V_45 ;
struct V_1 V_55 ;
F_2 ( L_30 ,
( V_46 ) V_43 , ( V_46 ) V_44 ) ;
F_25 () ;
if ( V_43 ) {
V_45 = V_43 -> V_54 ;
if ( V_45 ) {
memcpy ( & V_55 , V_45 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_45 , V_56 ,
& ( V_55 . V_40 ) ) ;
if ( ! V_3 )
* V_44 = F_32 ( V_55 . V_40 ) ;
}
}
F_26 () ;
F_2 ( L_31 ,
V_3 , V_3 , * V_44 ) ;
return V_3 ;
}
static int F_33 ( struct V_43 * V_43 , T_2 * V_44 )
{
int V_3 = - V_53 ;
struct V_1 * V_45 ;
T_2 V_59 ;
struct V_1 V_55 ;
F_2 ( L_32 ,
( V_46 ) V_43 , ( V_46 ) V_44 ) ;
F_25 () ;
if ( V_43 ) {
V_45 = V_43 -> V_54 ;
if ( V_45 ) {
memcpy ( & V_55 , V_45 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_45 , V_56 ,
& ( V_55 . V_40 ) ) ;
if ( ! V_3 ) {
V_59 = F_34 ( V_55 . V_40 ) ;
if ( V_59 == V_60 )
* V_44 = 0 ;
else
* V_44 = 1 ;
}
}
}
F_26 () ;
F_2 ( L_33 , V_3 , * V_44 ) ;
return V_3 ;
}
static int F_35 ( struct V_1 * V_1 )
{
int V_3 ;
T_2 V_61 = 0 ;
enum V_62 V_63 ;
struct V_64 * V_30 = V_1 -> V_43 -> V_65 -> V_30 ;
F_2 ( L_34 , V_66 , V_1 ) ;
F_25 () ;
V_61 = V_1 -> V_67 ;
V_63 = V_1 -> V_68 ;
F_26 () ;
switch ( V_63 ) {
case V_69 :
break;
case V_70 :
if ( V_61 == V_71 )
V_63 += 0x01 ;
break;
case V_72 :
case V_73 :
V_63 += 0x01 ;
break;
default:
V_3 = - V_53 ;
}
if ( ! V_3 )
V_30 -> V_74 = V_63 ;
F_2 ( L_35 , V_66 , V_3 , V_63 ) ;
return V_3 ;
}
static int T_1 F_36 ( void )
{
struct V_1 * V_4 ;
struct V_15 * V_16 ;
int V_39 ;
int V_3 ;
F_10 (tmp, &ibmphp_slot_head) {
V_4 = F_11 ( V_16 , struct V_1 , V_18 ) ;
if ( ! V_4 )
return - V_53 ;
F_2 ( L_36 ,
V_4 -> V_19 ) ;
if ( V_4 -> V_5 -> V_7 == 0xFF )
if ( F_37 ( V_4 ,
& V_4 -> V_5 -> V_7 ) )
return - 1 ;
if ( V_4 -> V_9 -> V_10 == 0xFF )
if ( F_1 ( & V_4 ) )
return - 1 ;
F_35 ( V_4 ) ;
if ( V_4 -> V_5 -> V_6 == 0xFF )
if ( F_38 ( V_4 , & V_4 -> V_5 -> V_6 ) )
return - 1 ;
V_39 = F_8 ( & V_4 ) ;
if ( V_39 )
return V_39 ;
F_2 ( L_37 , V_4 -> V_40 ) ;
F_2 ( L_38 , V_4 -> V_58 ) ;
F_2 ( L_39 , F_39 ( V_4 -> V_40 ) ) ;
F_2 ( L_40 , F_34 ( V_4 -> V_40 ) ) ;
F_2 ( L_41 , F_30 ( V_4 -> V_40 ) ) ;
if ( ( F_32 ( V_4 -> V_40 ) ) &&
! ( F_34 ( V_4 -> V_40 ) ) &&
! ( F_30 ( V_4 -> V_40 ) ) ) {
F_2 ( L_42 ) ;
V_3 = F_23 ( V_4 ) ;
if ( V_3 )
return V_3 ;
}
}
V_14 = 0 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_4 , int V_75 )
{
int V_19 ;
int V_39 ;
if ( ! V_4 )
return - V_53 ;
V_19 = V_4 -> V_19 ;
if ( ( V_19 > V_76 ) || ( V_19 < 0 ) )
return - V_77 ;
F_2 ( L_43 , V_4 -> V_19 ) ;
V_39 = F_8 ( & V_4 ) ;
if ( V_39 )
return V_39 ;
switch ( V_75 ) {
case V_78 :
if ( ! ( F_32 ( V_4 -> V_40 ) ) &&
( F_34 ( V_4 -> V_40 ) ) &&
! ( F_30 ( V_4 -> V_40 ) ) )
return 0 ;
break;
case V_79 :
if ( ( F_32 ( V_4 -> V_40 ) ) &&
( F_34 ( V_4 -> V_40 ) ) &&
! ( F_30 ( V_4 -> V_40 ) ) )
return 0 ;
break;
default:
break;
}
F_15 ( L_44 ) ;
return - V_80 ;
}
int F_41 ( struct V_1 * V_4 )
{
struct V_81 * V_82 ;
struct V_64 * V_30 = V_4 -> V_43 -> V_65 -> V_30 ;
int V_3 ;
T_2 V_83 ;
T_2 V_61 ;
V_82 = F_42 ( sizeof( struct V_81 ) , V_84 ) ;
if ( ! V_82 ) {
F_15 ( L_45 ) ;
return - V_26 ;
}
V_82 -> V_85 = F_32 ( V_4 -> V_40 ) ;
V_82 -> V_86 = F_28 ( V_4 -> V_40 ,
V_4 -> V_58 ) ;
V_82 -> V_87 = F_30 ( V_4 -> V_40 ) ;
if ( ! F_34 ( V_4 -> V_40 ) ) {
V_82 -> V_88 = 0 ;
} else {
V_82 -> V_88 = 1 ;
}
V_83 = V_4 -> V_9 -> V_10 ;
V_61 = V_4 -> V_9 -> V_12 ;
switch ( V_83 ) {
case V_69 :
break;
case V_70 :
if ( V_61 == V_71 )
V_83 += 0x01 ;
else if ( V_61 == V_89 )
;
else
V_83 = V_90 ;
break;
case V_72 :
case V_73 :
V_83 += 0x01 ;
break;
default:
V_83 = V_90 ;
}
V_30 -> V_91 = V_83 ;
V_3 = F_43 ( V_4 -> V_43 , V_82 ) ;
F_16 ( V_82 ) ;
return V_3 ;
}
static struct V_92 * F_44 ( T_2 V_93 , T_2 V_31 , T_2 V_94 )
{
struct V_92 * V_95 ;
struct V_1 * V_4 ;
struct V_15 * V_16 ;
F_10 (tmp, &ibmphp_slot_head) {
V_4 = F_11 ( V_16 , struct V_1 , V_18 ) ;
if ( V_4 -> V_96 ) {
V_95 = V_4 -> V_96 ;
while ( V_95 ) {
if ( ( V_95 -> V_93 == V_93 ) &&
( V_95 -> V_31 == V_31 ) &&
( V_95 -> V_94 == V_94 ) )
return V_95 ;
V_95 = V_95 -> V_97 ;
}
}
}
return NULL ;
}
static void F_45 ( void )
{
struct V_1 * V_4 ;
struct V_15 * V_16 ;
struct V_15 * V_97 ;
F_2 ( L_46 , V_66 ) ;
F_46 (tmp, next, &ibmphp_slot_head) {
V_4 = F_11 ( V_16 , struct V_1 , V_18 ) ;
F_47 ( V_4 -> V_43 ) ;
}
F_2 ( L_47 , V_66 ) ;
}
static void F_48 ( struct V_92 * V_96 )
{
struct V_98 * V_99 ;
T_2 V_100 ;
F_2 ( L_48 , V_66 ) ;
F_2 ( L_49 ,
V_96 -> V_31 , V_96 -> V_94 ) ;
F_2 ( L_50 , V_96 -> V_31 << 3 | 0x0 ) ;
F_49 () ;
for ( V_100 = 0 ; V_100 < 0x08 ; V_100 ++ ) {
V_99 = F_50 ( V_96 -> V_93 , ( V_96 -> V_31 << 3 ) | V_100 ) ;
if ( V_99 ) {
F_51 ( V_99 ) ;
F_52 ( V_99 ) ;
}
}
F_52 ( V_96 -> V_101 ) ;
F_53 () ;
}
static T_2 F_54 ( T_2 V_93 )
{
struct V_64 * V_30 ;
struct V_98 * V_101 ;
T_3 V_102 ;
if ( F_55 ( 0 , V_93 ) || ! ( F_56 ( V_93 ) ) )
return 1 ;
V_30 = F_42 ( sizeof( * V_30 ) , V_84 ) ;
if ( ! V_30 ) {
F_15 ( L_51 , V_66 ) ;
return 1 ;
}
V_101 = F_42 ( sizeof( * V_101 ) , V_84 ) ;
if ( ! V_101 ) {
F_16 ( V_30 ) ;
F_15 ( L_51 , V_66 ) ;
return 1 ;
}
V_30 -> V_19 = V_93 ;
V_30 -> V_103 = V_104 -> V_103 ;
V_101 -> V_30 = V_30 ;
for ( V_101 -> V_32 = 0 ; V_101 -> V_32 < 256 ; V_101 -> V_32 += 8 ) {
if ( ! F_57 ( V_101 , V_105 , & V_102 ) &&
( V_102 != 0x0000 ) && ( V_102 != 0xffff ) ) {
F_2 ( L_52 ,
V_66 ) ;
F_58 ( V_93 , V_104 -> V_103 , NULL ) ;
break;
}
}
F_16 ( V_101 ) ;
F_16 ( V_30 ) ;
return 0 ;
}
static int F_59 ( struct V_92 * V_96 )
{
struct V_64 * V_106 ;
int V_107 ;
int V_108 = 0 ;
F_49 () ;
if ( ! ( F_54 ( V_96 -> V_93 ) ) )
V_108 = 1 ;
if ( V_96 -> V_101 == NULL )
V_96 -> V_101 = F_50 ( V_96 -> V_93 ,
F_60 ( V_96 -> V_31 , V_96 -> V_94 ) ) ;
if ( V_96 -> V_101 == NULL ) {
struct V_64 * V_30 = F_55 ( 0 , V_96 -> V_93 ) ;
if ( ! V_30 )
goto V_109;
V_107 = F_61 ( V_30 ,
F_60 ( V_96 -> V_31 , V_96 -> V_94 ) ) ;
if ( V_107 )
F_62 ( V_30 ) ;
V_96 -> V_101 = F_50 ( V_96 -> V_93 ,
F_60 ( V_96 -> V_31 , V_96 -> V_94 ) ) ;
if ( V_96 -> V_101 == NULL ) {
F_15 ( L_53 ) ;
goto V_109;
}
}
if ( ! ( V_108 ) && ( V_96 -> V_101 -> V_110 == V_111 ) ) {
F_63 ( V_96 -> V_101 ) ;
V_106 = V_96 -> V_101 -> V_112 ;
if ( V_106 )
F_62 ( V_106 ) ;
}
V_109:
F_53 () ;
return 0 ;
}
static int F_64 ( struct V_1 * V_4 )
{
int V_3 ;
struct V_1 * V_113 ;
T_2 V_25 = V_4 -> V_9 -> V_114 ;
while ( V_25 <= V_4 -> V_9 -> V_115 ) {
if ( V_25 == V_4 -> V_19 ) {
V_25 ++ ;
continue;
}
V_113 = F_65 ( V_25 ) ;
if ( ! V_113 )
return 0 ;
V_3 = F_8 ( & V_113 ) ;
if ( V_3 )
return 0 ;
if ( F_34 ( V_113 -> V_40 ) &&
F_32 ( V_113 -> V_40 ) )
return 0 ;
V_25 ++ ;
}
return 1 ;
}
static int F_66 ( struct V_1 * V_4 )
{
int V_3 ;
T_2 V_63 ;
T_2 V_37 = 0x0 ;
int V_39 ;
static struct V_116 V_117 [] = {
{ F_67 (PCI_VENDOR_ID_SERVERWORKS, 0x0101 ) } ,
{ } ,
} ;
F_2 ( L_54 , V_66 , V_4 -> V_19 ) ;
if ( F_68 ( V_4 -> V_5 ) && F_64 ( V_4 ) ) {
V_3 = F_8 ( & V_4 ) ;
if ( V_3 )
return V_3 ;
V_63 = F_69 ( V_4 -> V_58 ) ;
F_2 ( L_55 , V_4 -> V_58 , V_63 ) ;
switch ( V_63 ) {
case V_118 :
V_37 = V_119 ;
break;
case V_120 :
if ( F_70 ( V_4 -> V_58 ) ) {
if ( ( V_4 -> V_68 >= V_70 ) &&
( V_4 -> V_67 == V_71 ) )
V_37 = V_121 ;
else if ( ! F_71 ( V_4 -> V_58 ) )
V_37 = V_122 ;
else
V_37 = V_119 ;
} else {
if ( V_4 -> V_68 >= V_70 )
V_37 = V_122 ;
else
V_37 = V_119 ;
}
break;
case V_123 :
switch ( V_4 -> V_68 ) {
case V_69 :
V_37 = V_119 ;
break;
case V_70 :
if ( V_4 -> V_67 == V_71 )
V_37 = V_121 ;
else
V_37 = V_122 ;
break;
case V_72 :
V_37 = V_124 ;
break;
case V_73 :
if ( F_72 ( V_117 ) )
F_20 ( V_4 ,
V_124 ) ;
V_37 = V_125 ;
break;
default:
F_15 ( L_56 ) ;
return - V_53 ;
}
break;
default:
F_15 ( L_57 ) ;
return - V_53 ;
}
F_2 ( L_58 ,
V_4 -> V_19 , V_37 ) ;
V_39 = F_20 ( V_4 , V_37 ) ;
if ( V_39 ) {
F_15 ( L_59 ) ;
return V_39 ;
}
if ( F_21 ( V_4 -> V_5 -> V_40 ) ) {
F_15 ( L_60 ) ;
return - V_41 ;
}
}
F_22 ( 1000 ) ;
F_2 ( L_61 , V_66 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_4 )
{
T_2 V_25 ;
struct V_1 * V_113 ;
T_2 V_126 = 0 ;
T_2 V_127 = 0 ;
for ( V_25 = V_4 -> V_9 -> V_114 ; V_25 <= V_4 -> V_9 -> V_115 ; V_25 ++ ) {
V_113 = F_65 ( V_25 ) ;
if ( ! V_113 )
return - V_53 ;
if ( ( F_32 ( V_113 -> V_40 ) ) &&
! ( F_74 ( V_113 -> V_40 ) ) )
V_126 ++ ;
}
F_1 ( & V_4 ) ;
switch ( V_4 -> V_9 -> V_10 ) {
case V_69 :
V_127 = V_4 -> V_9 -> V_128 ;
break;
case V_70 :
if ( V_4 -> V_9 -> V_12 == V_71 )
V_127 = V_4 -> V_9 -> V_129 ;
else
V_127 = V_4 -> V_9 -> V_130 ;
break;
case V_72 :
V_127 = V_4 -> V_9 -> V_131 ;
break;
case V_73 :
V_127 = V_4 -> V_9 -> V_132 ;
break;
}
if ( ( V_126 + 1 ) > V_127 )
return - V_80 ;
return 0 ;
}
static inline void F_75 ( struct V_1 * V_4 )
{
V_82 ( L_62 ) ;
if ( ( V_4 -> V_58 & V_133 ) == V_134 )
V_82 ( L_63 ) ;
else if ( ( V_4 -> V_58 & V_133 ) == V_135 )
V_82 ( L_64 ) ;
else if ( ( V_4 -> V_58 & V_133 ) == V_136 )
V_82 ( L_65 ) ;
else
V_82 ( L_66 ) ;
}
static int F_76 ( struct V_43 * V_137 )
{
int V_3 , V_25 , V_138 ;
struct V_1 * V_4 ;
T_2 V_94 ;
struct V_92 * V_139 ;
F_25 () ;
F_2 ( L_67 ) ;
V_4 = V_137 -> V_54 ;
V_3 = F_40 ( V_4 , V_78 ) ;
if ( V_3 ) {
F_15 ( L_68 ) ;
goto V_140;
}
F_77 ( V_4 ) ;
V_3 = F_66 ( V_4 ) ;
if ( V_3 ) {
F_15 ( L_69 ) ;
goto V_140;
}
F_1 ( & V_4 ) ;
F_2 ( L_70 ,
V_4 -> V_9 -> V_10 ) ;
V_3 = F_73 ( V_4 ) ;
if ( V_3 ) {
F_15 ( L_71 ) ;
F_15 ( L_72 ) ;
F_15 ( L_73 ) ;
V_3 = - V_80 ;
goto V_140;
}
V_3 = F_19 ( V_4 ) ;
if ( V_3 ) {
F_15 ( L_74 ) ;
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
if ( F_8 ( & V_4 ) ) {
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_3 = - V_53 ;
goto exit;
}
if ( ( F_39 ( V_4 -> V_40 ) ) &&
! ( F_32 ( V_4 -> V_40 ) ) )
F_15 ( L_75 ) ;
else if ( F_80 ( V_4 -> V_40 ) ) {
F_15 ( L_76 ) ;
F_75 ( V_4 ) ;
} else if ( F_71 ( V_4 -> V_58 ) ) {
F_15 ( L_77 ) ;
F_75 ( V_4 ) ;
}
F_41 ( V_4 ) ;
goto exit;
}
F_2 ( L_78 ) ;
F_1 ( & V_4 ) ;
F_2 ( L_79 ,
V_4 -> V_9 -> V_10 ) ;
V_3 = F_8 ( & V_4 ) ;
if ( V_3 )
goto V_141;
V_3 = - V_80 ;
if ( F_39 ( V_4 -> V_40 ) && ! ( F_32 ( V_4 -> V_40 ) ) ) {
F_15 ( L_80 ) ;
goto V_141;
}
if ( F_39 ( V_4 -> V_40 ) && ( F_80 ( V_4 -> V_40 ) ) ) {
F_15 ( L_76 ) ;
F_75 ( V_4 ) ;
goto V_141;
}
if ( ! ( F_39 ( V_4 -> V_40 ) ) ) {
F_15 ( L_81 ) ;
goto V_141;
}
V_4 -> V_96 = F_81 ( sizeof( struct V_92 ) , V_84 ) ;
if ( ! V_4 -> V_96 ) {
F_15 ( L_45 ) ;
V_3 = - V_26 ;
goto V_141;
}
V_4 -> V_96 -> V_93 = V_4 -> V_30 ;
V_4 -> V_96 -> V_31 = V_4 -> V_31 ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
V_4 -> V_96 -> V_33 [ V_25 ] = V_4 -> V_33 [ V_25 ] ;
F_2 ( L_82 ,
V_4 -> V_30 , V_4 -> V_31 ) ;
if ( F_82 ( V_4 -> V_96 , V_4 -> V_19 ) ) {
F_15 ( L_83 ) ;
F_83 ( & V_4 , 1 ) ;
F_2 ( L_84 ) ;
V_4 -> V_96 = NULL ;
V_3 = - V_26 ;
goto V_141;
}
V_94 = 0x00 ;
do {
V_139 = F_44 ( V_4 -> V_30 , V_4 -> V_96 -> V_31 ,
V_94 ++ ) ;
if ( V_139 && ! ( V_139 -> V_101 ) )
F_59 ( V_139 ) ;
} while ( V_139 );
F_78 ( V_4 ) ;
if ( F_8 ( & V_4 ) ) {
V_3 = - V_142 ;
goto exit;
}
F_84 () ;
V_3 = F_41 ( V_4 ) ;
exit:
F_26 () ;
return V_3 ;
V_140:
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_143:
V_138 = F_8 ( & V_4 ) ;
if ( V_138 ) {
V_3 = V_138 ;
goto exit;
}
F_41 ( V_4 ) ;
goto exit;
V_141:
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_138 = F_23 ( V_4 ) ;
if ( V_138 ) {
V_3 = V_138 ;
goto exit;
}
goto V_143;
}
static int F_85 ( struct V_43 * V_43 )
{
struct V_1 * V_1 = V_43 -> V_54 ;
int V_3 ;
F_25 () ;
V_3 = F_86 ( V_1 ) ;
F_26 () ;
return V_3 ;
}
int F_86 ( struct V_1 * V_4 )
{
int V_3 ;
T_2 V_108 ;
F_2 ( L_85 ) ;
if ( ( V_4 == NULL ) || ( V_4 -> V_5 == NULL ) )
return - V_53 ;
V_108 = V_4 -> V_108 ;
V_4 -> V_108 = 1 ;
if ( V_108 == 1 ) {
V_3 = F_40 ( V_4 , V_79 ) ;
if ( V_3 )
goto error;
}
F_77 ( V_4 ) ;
if ( V_4 -> V_96 == NULL ) {
V_4 -> V_96 = F_81 ( sizeof( struct V_92 ) , V_84 ) ;
if ( ! V_4 -> V_96 ) {
F_15 ( L_45 ) ;
V_3 = - V_26 ;
goto error;
}
V_4 -> V_96 -> V_93 = V_4 -> V_30 ;
V_4 -> V_96 -> V_31 = V_4 -> V_31 ;
}
F_48 ( V_4 -> V_96 ) ;
if ( ! V_108 ) {
F_78 ( V_4 ) ;
return 0 ;
}
V_3 = F_83 ( & V_4 , 0 ) ;
V_4 -> V_96 = NULL ;
F_2 ( L_86 ) ;
if ( V_3 ) {
F_15 ( L_87 ) ;
goto error;
}
V_3 = F_20 ( V_4 , V_42 ) ;
if ( V_3 )
goto error;
F_78 ( V_4 ) ;
V_3 = F_8 ( & V_4 ) ;
if ( V_3 )
goto exit;
V_3 = F_41 ( V_4 ) ;
F_84 () ;
exit:
return V_3 ;
error:
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
if ( F_8 ( & V_4 ) ) {
V_3 = - V_142 ;
goto exit;
}
if ( V_108 )
F_41 ( V_4 ) ;
goto exit;
}
static void F_87 ( void )
{
F_45 () ;
F_2 ( L_88 ) ;
F_88 () ;
F_2 ( L_89 ) ;
F_89 () ;
F_2 ( L_90 ) ;
F_90 () ;
F_2 ( L_91 ) ;
F_91 () ;
F_2 ( L_92 ) ;
F_16 ( V_104 ) ;
}
static int T_1 F_92 ( void )
{
struct V_64 * V_30 ;
int V_25 = 0 ;
int V_3 = 0 ;
V_14 = 1 ;
V_82 ( V_144 L_93 V_145 L_94 ) ;
V_104 = F_42 ( sizeof( * V_104 ) , V_84 ) ;
if ( ! V_104 ) {
F_15 ( L_95 ) ;
V_3 = - V_26 ;
goto exit;
}
V_30 = F_55 ( 0 , 0 ) ;
if ( ! V_30 ) {
F_15 ( L_96 ) ;
V_3 = - V_53 ;
goto error;
}
memcpy ( V_104 , V_30 , sizeof( * V_104 ) ) ;
V_146 = F_2 ;
F_93 () ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
V_147 [ V_25 ] = 0 ;
V_3 = F_94 () ;
if ( V_3 )
goto error;
F_2 ( L_97 ) ;
V_3 = F_95 () ;
if ( V_3 )
goto error;
F_2 ( L_98 ) ;
V_76 = F_9 () ;
V_3 = F_96 () ;
if ( V_3 )
goto error;
if ( F_36 () ) {
V_3 = - V_53 ;
goto error;
}
F_84 () ;
V_3 = F_97 () ;
if ( V_3 )
goto error;
exit:
return V_3 ;
error:
F_87 () ;
goto exit;
}
static void T_4 F_98 ( void )
{
F_99 () ;
F_2 ( L_99 ) ;
F_87 () ;
F_2 ( L_100 ) ;
}
