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
struct V_31 V_32 ;
( * V_20 ) -> V_33 = F_17 ( V_22 -> V_29 [ V_24 ] . V_34 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
( * V_20 ) -> V_35 [ V_25 ] = F_18 ( ( int ) ( * V_20 ) -> V_30 ,
( int ) ( * V_20 ) -> V_33 , V_25 ,
& V_32 ) ;
F_2 ( L_5 ,
( * V_20 ) -> V_35 [ 0 ] ) ;
F_2 ( L_6 ,
( * V_20 ) -> V_35 [ 1 ] ) ;
F_2 ( L_7 ,
( * V_20 ) -> V_35 [ 2 ] ) ;
F_2 ( L_8 ,
( * V_20 ) -> V_35 [ 3 ] ) ;
F_2 ( L_9 ,
V_22 -> V_36 ) ;
F_2 ( L_10 ,
V_22 -> V_29 [ V_24 ] . V_35 [ 0 ] . V_37 ) ;
F_2 ( L_11 ,
V_22 -> V_29 [ V_24 ] . V_35 [ 1 ] . V_37 ) ;
F_2 ( L_12 ,
V_22 -> V_29 [ V_24 ] . V_35 [ 2 ] . V_37 ) ;
F_2 ( L_13 ,
V_22 -> V_29 [ V_24 ] . V_35 [ 3 ] . V_37 ) ;
F_2 ( L_14 ,
V_22 -> V_29 [ V_24 ] . V_35 [ 0 ] . V_38 ) ;
F_2 ( L_15 ,
V_22 -> V_29 [ V_24 ] . V_35 [ 1 ] . V_38 ) ;
F_2 ( L_16 ,
V_22 -> V_29 [ V_24 ] . V_35 [ 2 ] . V_38 ) ;
F_2 ( L_17 ,
V_22 -> V_29 [ V_24 ] . V_35 [ 3 ] . V_38 ) ;
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
T_2 V_39 = V_40 ;
int V_41 ;
V_41 = F_20 ( V_4 , V_39 ) ;
if ( V_41 ) {
F_15 ( L_19 ) ;
return V_41 ;
}
if ( F_21 ( V_4 -> V_5 -> V_42 ) ) {
F_15 ( L_20 ) ;
return - V_43 ;
}
F_22 ( 3000 ) ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_4 )
{
T_2 V_39 = V_44 ;
int V_41 ;
V_41 = F_20 ( V_4 , V_39 ) ;
if ( V_41 ) {
F_15 ( L_21 ) ;
return V_41 ;
}
if ( F_21 ( V_4 -> V_5 -> V_42 ) ) {
F_15 ( L_22 ) ;
V_41 = - V_43 ;
}
return V_41 ;
}
static int F_24 ( struct V_45 * V_45 , T_2 V_46 )
{
int V_3 = 0 ;
struct V_1 * V_47 ;
T_2 V_39 = 0x00 ;
F_2 ( L_23 ,
( V_48 ) V_45 , V_46 ) ;
F_25 () ;
if ( V_45 ) {
switch ( V_46 ) {
case V_49 :
V_39 = V_50 ;
break;
case V_51 :
V_39 = V_52 ;
break;
case V_53 :
V_39 = V_54 ;
break;
default:
V_3 = - V_55 ;
F_15 ( L_24 ,
V_46 ) ;
break;
}
if ( V_3 == 0 ) {
V_47 = V_45 -> V_56 ;
if ( V_47 )
V_3 = F_20 ( V_47 , V_39 ) ;
else
V_3 = - V_55 ;
}
} else
V_3 = - V_55 ;
F_26 () ;
F_2 ( L_25 , V_3 ) ;
return V_3 ;
}
static int F_27 ( struct V_45 * V_45 , T_2 * V_46 )
{
int V_3 = - V_55 ;
struct V_1 * V_47 ;
struct V_1 V_57 ;
F_2 ( L_26 ,
( V_48 ) V_45 , ( V_48 ) V_46 ) ;
F_25 () ;
if ( V_45 ) {
V_47 = V_45 -> V_56 ;
if ( V_47 ) {
memcpy ( & V_57 , V_47 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_47 , V_58 ,
& ( V_57 . V_42 ) ) ;
if ( ! V_3 )
V_3 = F_4 ( V_47 ,
V_59 ,
& ( V_57 . V_60 ) ) ;
if ( ! V_3 )
* V_46 = F_28 ( V_57 . V_42 ,
V_57 . V_60 ) ;
}
}
F_26 () ;
F_2 ( L_27 , V_3 , * V_46 ) ;
return V_3 ;
}
static int F_29 ( struct V_45 * V_45 , T_2 * V_46 )
{
int V_3 = - V_55 ;
struct V_1 * V_47 ;
struct V_1 V_57 ;
F_2 ( L_28 ,
( V_48 ) V_45 , ( V_48 ) V_46 ) ;
F_25 () ;
if ( V_45 ) {
V_47 = V_45 -> V_56 ;
if ( V_47 ) {
memcpy ( & V_57 , V_47 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_47 , V_58 ,
& ( V_57 . V_42 ) ) ;
if ( ! V_3 )
* V_46 = F_30 ( V_57 . V_42 ) ;
}
}
F_26 () ;
F_2 ( L_29 ,
V_3 , V_3 , * V_46 ) ;
return V_3 ;
}
static int F_31 ( struct V_45 * V_45 , T_2 * V_46 )
{
int V_3 = - V_55 ;
struct V_1 * V_47 ;
struct V_1 V_57 ;
F_2 ( L_30 ,
( V_48 ) V_45 , ( V_48 ) V_46 ) ;
F_25 () ;
if ( V_45 ) {
V_47 = V_45 -> V_56 ;
if ( V_47 ) {
memcpy ( & V_57 , V_47 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_47 , V_58 ,
& ( V_57 . V_42 ) ) ;
if ( ! V_3 )
* V_46 = F_32 ( V_57 . V_42 ) ;
}
}
F_26 () ;
F_2 ( L_31 ,
V_3 , V_3 , * V_46 ) ;
return V_3 ;
}
static int F_33 ( struct V_45 * V_45 , T_2 * V_46 )
{
int V_3 = - V_55 ;
struct V_1 * V_47 ;
T_2 V_61 ;
struct V_1 V_57 ;
F_2 ( L_32 ,
( V_48 ) V_45 , ( V_48 ) V_46 ) ;
F_25 () ;
if ( V_45 ) {
V_47 = V_45 -> V_56 ;
if ( V_47 ) {
memcpy ( & V_57 , V_47 , sizeof( struct V_1 ) ) ;
V_3 = F_4 ( V_47 , V_58 ,
& ( V_57 . V_42 ) ) ;
if ( ! V_3 ) {
V_61 = F_34 ( V_57 . V_42 ) ;
if ( V_61 == V_62 )
* V_46 = 0 ;
else
* V_46 = 1 ;
}
}
}
F_26 () ;
F_2 ( L_33 , V_3 , * V_46 ) ;
return V_3 ;
}
static int F_35 ( struct V_1 * V_1 )
{
int V_3 ;
T_2 V_63 = 0 ;
enum V_64 V_65 ;
struct V_66 * V_30 = V_1 -> V_45 -> V_67 -> V_30 ;
F_2 ( L_34 , V_68 , V_1 ) ;
F_25 () ;
V_63 = V_1 -> V_69 ;
V_65 = V_1 -> V_70 ;
F_26 () ;
switch ( V_65 ) {
case V_71 :
break;
case V_72 :
if ( V_63 == V_73 )
V_65 += 0x01 ;
break;
case V_74 :
case V_75 :
V_65 += 0x01 ;
break;
default:
V_3 = - V_55 ;
}
if ( ! V_3 )
V_30 -> V_76 = V_65 ;
F_2 ( L_35 , V_68 , V_3 , V_65 ) ;
return V_3 ;
}
static int T_1 F_36 ( void )
{
struct V_1 * V_4 ;
struct V_15 * V_16 ;
int V_41 ;
int V_3 ;
F_10 (tmp, &ibmphp_slot_head) {
V_4 = F_11 ( V_16 , struct V_1 , V_18 ) ;
if ( ! V_4 )
return - V_55 ;
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
V_41 = F_8 ( & V_4 ) ;
if ( V_41 )
return V_41 ;
F_2 ( L_37 , V_4 -> V_42 ) ;
F_2 ( L_38 , V_4 -> V_60 ) ;
F_2 ( L_39 , F_39 ( V_4 -> V_42 ) ) ;
F_2 ( L_40 , F_34 ( V_4 -> V_42 ) ) ;
F_2 ( L_41 , F_30 ( V_4 -> V_42 ) ) ;
if ( ( F_32 ( V_4 -> V_42 ) ) &&
! ( F_34 ( V_4 -> V_42 ) ) &&
! ( F_30 ( V_4 -> V_42 ) ) ) {
F_2 ( L_42 ) ;
V_3 = F_23 ( V_4 ) ;
if ( V_3 )
return V_3 ;
}
}
V_14 = 0 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_4 , int V_77 )
{
int V_19 ;
int V_41 ;
if ( ! V_4 )
return - V_55 ;
V_19 = V_4 -> V_19 ;
if ( ( V_19 > V_78 ) || ( V_19 < 0 ) )
return - V_79 ;
F_2 ( L_43 , V_4 -> V_19 ) ;
V_41 = F_8 ( & V_4 ) ;
if ( V_41 )
return V_41 ;
switch ( V_77 ) {
case V_80 :
if ( ! ( F_32 ( V_4 -> V_42 ) ) &&
( F_34 ( V_4 -> V_42 ) ) &&
! ( F_30 ( V_4 -> V_42 ) ) )
return 0 ;
break;
case V_81 :
if ( ( F_32 ( V_4 -> V_42 ) ) &&
( F_34 ( V_4 -> V_42 ) ) &&
! ( F_30 ( V_4 -> V_42 ) ) )
return 0 ;
break;
default:
break;
}
F_15 ( L_44 ) ;
return - V_82 ;
}
int F_41 ( struct V_1 * V_4 )
{
struct V_83 * V_84 ;
struct V_66 * V_30 = V_4 -> V_45 -> V_67 -> V_30 ;
int V_3 ;
T_2 V_85 ;
T_2 V_63 ;
V_84 = F_42 ( sizeof( struct V_83 ) , V_86 ) ;
if ( ! V_84 ) {
F_15 ( L_45 ) ;
return - V_26 ;
}
V_84 -> V_87 = F_32 ( V_4 -> V_42 ) ;
V_84 -> V_88 = F_28 ( V_4 -> V_42 ,
V_4 -> V_60 ) ;
V_84 -> V_89 = F_30 ( V_4 -> V_42 ) ;
if ( ! F_34 ( V_4 -> V_42 ) ) {
V_84 -> V_90 = 0 ;
} else {
V_84 -> V_90 = 1 ;
}
V_85 = V_4 -> V_9 -> V_10 ;
V_63 = V_4 -> V_9 -> V_12 ;
switch ( V_85 ) {
case V_71 :
break;
case V_72 :
if ( V_63 == V_73 )
V_85 += 0x01 ;
else if ( V_63 == V_91 )
;
else
V_85 = V_92 ;
break;
case V_74 :
case V_75 :
V_85 += 0x01 ;
break;
default:
V_85 = V_92 ;
}
V_30 -> V_93 = V_85 ;
V_3 = F_43 ( V_4 -> V_45 , V_84 ) ;
F_16 ( V_84 ) ;
return V_3 ;
}
static struct V_94 * F_44 ( T_2 V_95 , T_2 V_33 , T_2 V_96 )
{
struct V_94 * V_97 ;
struct V_1 * V_4 ;
struct V_15 * V_16 ;
F_10 (tmp, &ibmphp_slot_head) {
V_4 = F_11 ( V_16 , struct V_1 , V_18 ) ;
if ( V_4 -> V_98 ) {
V_97 = V_4 -> V_98 ;
while ( V_97 ) {
if ( ( V_97 -> V_95 == V_95 ) &&
( V_97 -> V_33 == V_33 ) &&
( V_97 -> V_96 == V_96 ) )
return V_97 ;
V_97 = V_97 -> V_99 ;
}
}
}
return NULL ;
}
static void F_45 ( void )
{
struct V_1 * V_4 ;
struct V_15 * V_16 ;
struct V_15 * V_99 ;
F_2 ( L_46 , V_68 ) ;
F_46 (tmp, next, &ibmphp_slot_head) {
V_4 = F_11 ( V_16 , struct V_1 , V_18 ) ;
F_47 ( V_4 -> V_45 ) ;
}
F_2 ( L_47 , V_68 ) ;
}
static void F_48 ( struct V_94 * V_98 )
{
struct V_100 * V_101 ;
T_2 V_102 ;
F_2 ( L_48 , V_68 ) ;
F_2 ( L_49 ,
V_98 -> V_33 , V_98 -> V_96 ) ;
F_2 ( L_50 , V_98 -> V_33 << 3 | 0x0 ) ;
F_49 () ;
for ( V_102 = 0 ; V_102 < 0x08 ; V_102 ++ ) {
V_101 = F_50 ( V_98 -> V_95 , ( V_98 -> V_33 << 3 ) | V_102 ) ;
if ( V_101 ) {
F_51 ( V_101 ) ;
F_52 ( V_101 ) ;
}
}
F_52 ( V_98 -> V_103 ) ;
F_53 () ;
}
static T_2 F_54 ( T_2 V_95 )
{
struct V_66 * V_30 ;
struct V_100 * V_103 ;
T_3 V_104 ;
if ( F_55 ( 0 , V_95 ) || ! ( F_56 ( V_95 ) ) )
return 1 ;
V_30 = F_42 ( sizeof( * V_30 ) , V_86 ) ;
if ( ! V_30 ) {
F_15 ( L_51 , V_68 ) ;
return 1 ;
}
V_103 = F_42 ( sizeof( * V_103 ) , V_86 ) ;
if ( ! V_103 ) {
F_16 ( V_30 ) ;
F_15 ( L_51 , V_68 ) ;
return 1 ;
}
V_30 -> V_19 = V_95 ;
V_30 -> V_105 = V_106 -> V_105 ;
V_103 -> V_30 = V_30 ;
for ( V_103 -> V_34 = 0 ; V_103 -> V_34 < 256 ; V_103 -> V_34 += 8 ) {
if ( ! F_57 ( V_103 , V_107 , & V_104 ) &&
( V_104 != 0x0000 ) && ( V_104 != 0xffff ) ) {
F_2 ( L_52 ,
V_68 ) ;
F_58 ( V_95 , V_106 -> V_105 , NULL ) ;
break;
}
}
F_16 ( V_103 ) ;
F_16 ( V_30 ) ;
return 0 ;
}
static int F_59 ( struct V_94 * V_98 )
{
struct V_66 * V_108 ;
int V_109 ;
int V_110 = 0 ;
F_49 () ;
if ( ! ( F_54 ( V_98 -> V_95 ) ) )
V_110 = 1 ;
if ( V_98 -> V_103 == NULL )
V_98 -> V_103 = F_50 ( V_98 -> V_95 ,
F_60 ( V_98 -> V_33 , V_98 -> V_96 ) ) ;
if ( V_98 -> V_103 == NULL ) {
struct V_66 * V_30 = F_55 ( 0 , V_98 -> V_95 ) ;
if ( ! V_30 )
goto V_111;
V_109 = F_61 ( V_30 ,
F_60 ( V_98 -> V_33 , V_98 -> V_96 ) ) ;
if ( V_109 )
F_62 ( V_30 ) ;
V_98 -> V_103 = F_50 ( V_98 -> V_95 ,
F_60 ( V_98 -> V_33 , V_98 -> V_96 ) ) ;
if ( V_98 -> V_103 == NULL ) {
F_15 ( L_53 ) ;
goto V_111;
}
}
if ( ! ( V_110 ) && ( V_98 -> V_103 -> V_112 == V_113 ) ) {
F_63 ( V_98 -> V_103 ) ;
V_108 = V_98 -> V_103 -> V_114 ;
if ( V_108 )
F_62 ( V_108 ) ;
}
V_111:
F_53 () ;
return 0 ;
}
static int F_64 ( struct V_1 * V_4 )
{
int V_3 ;
struct V_1 * V_115 ;
T_2 V_25 = V_4 -> V_9 -> V_116 ;
while ( V_25 <= V_4 -> V_9 -> V_117 ) {
if ( V_25 == V_4 -> V_19 ) {
V_25 ++ ;
continue;
}
V_115 = F_65 ( V_25 ) ;
if ( ! V_115 )
return 0 ;
V_3 = F_8 ( & V_115 ) ;
if ( V_3 )
return 0 ;
if ( F_34 ( V_115 -> V_42 ) &&
F_32 ( V_115 -> V_42 ) )
return 0 ;
V_25 ++ ;
}
return 1 ;
}
static int F_66 ( struct V_1 * V_4 )
{
int V_3 ;
T_2 V_65 ;
T_2 V_39 = 0x0 ;
int V_41 ;
static struct V_118 V_119 [] = {
{ F_67 (PCI_VENDOR_ID_SERVERWORKS, 0x0101 ) } ,
{ } ,
} ;
F_2 ( L_54 , V_68 , V_4 -> V_19 ) ;
if ( F_68 ( V_4 -> V_5 ) && F_64 ( V_4 ) ) {
V_3 = F_8 ( & V_4 ) ;
if ( V_3 )
return V_3 ;
V_65 = F_69 ( V_4 -> V_60 ) ;
F_2 ( L_55 , V_4 -> V_60 , V_65 ) ;
switch ( V_65 ) {
case V_120 :
V_39 = V_121 ;
break;
case V_122 :
if ( F_70 ( V_4 -> V_60 ) ) {
if ( ( V_4 -> V_70 >= V_72 ) &&
( V_4 -> V_69 == V_73 ) )
V_39 = V_123 ;
else if ( ! F_71 ( V_4 -> V_60 ) )
V_39 = V_124 ;
else
V_39 = V_121 ;
} else {
if ( V_4 -> V_70 >= V_72 )
V_39 = V_124 ;
else
V_39 = V_121 ;
}
break;
case V_125 :
switch ( V_4 -> V_70 ) {
case V_71 :
V_39 = V_121 ;
break;
case V_72 :
if ( V_4 -> V_69 == V_73 )
V_39 = V_123 ;
else
V_39 = V_124 ;
break;
case V_74 :
V_39 = V_126 ;
break;
case V_75 :
if ( F_72 ( V_119 ) )
F_20 ( V_4 ,
V_126 ) ;
V_39 = V_127 ;
break;
default:
F_15 ( L_56 ) ;
return - V_55 ;
}
break;
default:
F_15 ( L_57 ) ;
return - V_55 ;
}
F_2 ( L_58 ,
V_4 -> V_19 , V_39 ) ;
V_41 = F_20 ( V_4 , V_39 ) ;
if ( V_41 ) {
F_15 ( L_59 ) ;
return V_41 ;
}
if ( F_21 ( V_4 -> V_5 -> V_42 ) ) {
F_15 ( L_60 ) ;
return - V_43 ;
}
}
F_22 ( 1000 ) ;
F_2 ( L_61 , V_68 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_4 )
{
T_2 V_25 ;
struct V_1 * V_115 ;
T_2 V_128 = 0 ;
T_2 V_129 = 0 ;
for ( V_25 = V_4 -> V_9 -> V_116 ; V_25 <= V_4 -> V_9 -> V_117 ; V_25 ++ ) {
V_115 = F_65 ( V_25 ) ;
if ( ! V_115 )
return - V_55 ;
if ( ( F_32 ( V_115 -> V_42 ) ) &&
! ( F_74 ( V_115 -> V_42 ) ) )
V_128 ++ ;
}
F_1 ( & V_4 ) ;
switch ( V_4 -> V_9 -> V_10 ) {
case V_71 :
V_129 = V_4 -> V_9 -> V_130 ;
break;
case V_72 :
if ( V_4 -> V_9 -> V_12 == V_73 )
V_129 = V_4 -> V_9 -> V_131 ;
else
V_129 = V_4 -> V_9 -> V_132 ;
break;
case V_74 :
V_129 = V_4 -> V_9 -> V_133 ;
break;
case V_75 :
V_129 = V_4 -> V_9 -> V_134 ;
break;
}
if ( ( V_128 + 1 ) > V_129 )
return - V_82 ;
return 0 ;
}
static inline void F_75 ( struct V_1 * V_4 )
{
V_84 ( L_62 ) ;
if ( ( V_4 -> V_60 & V_135 ) == V_136 )
V_84 ( L_63 ) ;
else if ( ( V_4 -> V_60 & V_135 ) == V_137 )
V_84 ( L_64 ) ;
else if ( ( V_4 -> V_60 & V_135 ) == V_138 )
V_84 ( L_65 ) ;
else
V_84 ( L_66 ) ;
}
static int F_76 ( struct V_45 * V_139 )
{
int V_3 , V_25 , V_140 ;
struct V_1 * V_4 ;
T_2 V_96 ;
struct V_94 * V_141 ;
F_25 () ;
F_2 ( L_67 ) ;
V_4 = V_139 -> V_56 ;
if ( ( V_3 = F_40 ( V_4 , V_80 ) ) ) {
F_15 ( L_68 ) ;
goto V_142;
}
F_77 ( V_4 ) ;
V_3 = F_66 ( V_4 ) ;
if ( V_3 ) {
F_15 ( L_69 ) ;
goto V_142;
}
F_1 ( & V_4 ) ;
F_2 ( L_70 ,
V_4 -> V_9 -> V_10 ) ;
V_3 = F_73 ( V_4 ) ;
if ( V_3 ) {
F_15 ( L_71 ) ;
F_15 ( L_72 ) ;
F_15 ( L_73 ) ;
V_3 = - V_82 ;
goto V_142;
}
V_3 = F_19 ( V_4 ) ;
if ( V_3 ) {
F_15 ( L_74 ) ;
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
if ( F_8 ( & V_4 ) ) {
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_3 = - V_55 ;
goto exit;
}
if ( ( F_39 ( V_4 -> V_42 ) ) &&
! ( F_32 ( V_4 -> V_42 ) ) )
F_15 ( L_75 ) ;
else if ( F_80 ( V_4 -> V_42 ) ) {
F_15 ( L_76 ) ;
F_75 ( V_4 ) ;
} else if ( F_71 ( V_4 -> V_60 ) ) {
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
goto V_143;
V_3 = - V_82 ;
if ( F_39 ( V_4 -> V_42 ) && ! ( F_32 ( V_4 -> V_42 ) ) ) {
F_15 ( L_80 ) ;
goto V_143;
}
if ( F_39 ( V_4 -> V_42 ) && ( F_80 ( V_4 -> V_42 ) ) ) {
F_15 ( L_76 ) ;
F_75 ( V_4 ) ;
goto V_143;
}
if ( ! ( F_39 ( V_4 -> V_42 ) ) ) {
F_15 ( L_81 ) ;
goto V_143;
}
V_4 -> V_98 = F_81 ( sizeof( struct V_94 ) , V_86 ) ;
if ( ! V_4 -> V_98 ) {
F_15 ( L_45 ) ;
V_3 = - V_26 ;
goto V_143;
}
V_4 -> V_98 -> V_95 = V_4 -> V_30 ;
V_4 -> V_98 -> V_33 = V_4 -> V_33 ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
V_4 -> V_98 -> V_35 [ V_25 ] = V_4 -> V_35 [ V_25 ] ;
F_2 ( L_82 ,
V_4 -> V_30 , V_4 -> V_33 ) ;
if ( F_82 ( V_4 -> V_98 , V_4 -> V_19 ) ) {
F_15 ( L_83 ) ;
F_83 ( & V_4 , 1 ) ;
F_2 ( L_84 ) ;
V_4 -> V_98 = NULL ;
V_3 = - V_26 ;
goto V_143;
}
V_96 = 0x00 ;
do {
V_141 = F_44 ( V_4 -> V_30 , V_4 -> V_98 -> V_33 ,
V_96 ++ ) ;
if ( V_141 && ! ( V_141 -> V_103 ) )
F_59 ( V_141 ) ;
} while ( V_141 );
F_78 ( V_4 ) ;
if ( F_8 ( & V_4 ) ) {
V_3 = - V_144 ;
goto exit;
}
F_84 () ;
V_3 = F_41 ( V_4 ) ;
exit:
F_26 () ;
return V_3 ;
V_142:
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_145:
V_140 = F_8 ( & V_4 ) ;
if ( V_140 ) {
V_3 = V_140 ;
goto exit;
}
F_41 ( V_4 ) ;
goto exit;
V_143:
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_140 = F_23 ( V_4 ) ;
if ( V_140 ) {
V_3 = V_140 ;
goto exit;
}
goto V_145;
}
static int F_85 ( struct V_45 * V_45 )
{
struct V_1 * V_1 = V_45 -> V_56 ;
int V_3 ;
F_25 () ;
V_3 = F_86 ( V_1 ) ;
F_26 () ;
return V_3 ;
}
int F_86 ( struct V_1 * V_4 )
{
int V_3 ;
T_2 V_110 ;
F_2 ( L_85 ) ;
if ( ( V_4 == NULL ) || ( V_4 -> V_5 == NULL ) ) {
return - V_55 ;
}
V_110 = V_4 -> V_110 ;
V_4 -> V_110 = 1 ;
if ( V_110 == 1 ) {
V_3 = F_40 ( V_4 , V_81 ) ;
if ( V_3 )
goto error;
}
F_77 ( V_4 ) ;
if ( V_4 -> V_98 == NULL ) {
V_4 -> V_98 = F_81 ( sizeof( struct V_94 ) , V_86 ) ;
if ( ! V_4 -> V_98 ) {
F_15 ( L_45 ) ;
V_3 = - V_26 ;
goto error;
}
V_4 -> V_98 -> V_95 = V_4 -> V_30 ;
V_4 -> V_98 -> V_33 = V_4 -> V_33 ;
}
F_48 ( V_4 -> V_98 ) ;
if ( ! V_110 ) {
F_78 ( V_4 ) ;
return 0 ;
}
V_3 = F_83 ( & V_4 , 0 ) ;
V_4 -> V_98 = NULL ;
F_2 ( L_86 ) ;
if ( V_3 ) {
F_15 ( L_87 ) ;
goto error;
}
V_3 = F_20 ( V_4 , V_44 ) ;
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
V_3 = - V_144 ;
goto exit;
}
if ( V_110 )
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
F_16 ( V_106 ) ;
}
static int T_1 F_92 ( void )
{
struct V_66 * V_30 ;
int V_25 = 0 ;
int V_3 = 0 ;
V_14 = 1 ;
V_84 ( V_146 L_93 V_147 L_94 ) ;
V_106 = F_42 ( sizeof( * V_106 ) , V_86 ) ;
if ( ! V_106 ) {
F_15 ( L_95 ) ;
V_3 = - V_26 ;
goto exit;
}
V_30 = F_55 ( 0 , 0 ) ;
if ( ! V_30 ) {
F_15 ( L_96 ) ;
V_3 = - V_55 ;
goto error;
}
memcpy ( V_106 , V_30 , sizeof( * V_106 ) ) ;
V_148 = F_2 ;
F_93 () ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
V_149 [ V_25 ] = 0 ;
if ( ( V_3 = F_94 () ) )
goto error;
F_2 ( L_97 ) ;
if ( ( V_3 = F_95 () ) )
goto error;
F_2 ( L_98 ) ;
V_78 = F_9 () ;
if ( ( V_3 = F_96 () ) )
goto error;
if ( F_36 () ) {
V_3 = - V_55 ;
goto error;
}
F_84 () ;
if ( ( V_3 = F_97 () ) ) {
goto error;
}
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
