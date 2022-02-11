static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 , * V_6 ;
struct V_7 * V_8 , * V_9 ;
int V_10 ;
F_2 ( & V_2 -> V_11 ) ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
V_4 = V_2 -> V_13 [ V_10 ] ;
if ( V_4 == NULL )
continue;
F_3 (s, n, &parent->list, list) {
F_4 ( & V_5 -> V_14 ) ;
V_8 = & V_5 -> V_8 ;
F_5 ( V_8 ) ;
if ( V_8 -> V_15 == V_16 )
F_6 ( V_5 -> V_17 ) ;
V_8 -> V_15 = V_18 ;
F_7 ( V_8 , V_19 ) ;
F_8 ( V_8 ) ;
}
V_9 = & V_4 -> V_8 ;
F_5 ( V_9 ) ;
if ( V_9 -> V_15 == V_20 ) {
struct V_3 * V_21 , * V_6 ;
struct V_7 * V_22 ;
F_3 (lsk, n, &parent->accept_queue,
accept_queue) {
V_22 = & V_21 -> V_8 ;
F_5 ( V_22 ) ;
F_9 ( V_22 ) ;
V_22 -> V_15 = V_18 ;
F_7 ( V_22 , V_19 ) ;
F_8 ( V_22 ) ;
F_10 ( V_22 ) ;
}
}
if ( V_9 -> V_15 == V_16 )
F_6 ( V_4 -> V_17 ) ;
V_9 -> V_15 = V_18 ;
F_7 ( V_9 , V_19 ) ;
F_8 ( V_9 ) ;
}
F_11 ( & V_2 -> V_11 ) ;
}
static void F_12 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 , struct V_1 ,
V_25 ) ;
F_14 ( V_2 -> V_17 ) ;
}
static void F_15 ( unsigned long V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_26 ;
F_16 ( L_1 ) ;
F_17 ( V_2 -> V_27 , & V_2 -> V_25 ) ;
}
struct V_1 * F_18 ( struct V_28 * V_17 )
{
struct V_1 * V_2 , * V_6 ;
F_3 (local, n, &llcp_devices, list)
if ( V_2 -> V_17 == V_17 )
return V_2 ;
F_19 ( L_2 ) ;
return NULL ;
}
static int F_20 ( char * V_29 , T_1 V_30 )
{
int V_31 , V_32 ;
F_19 ( L_3 , V_29 ) ;
if ( V_29 == NULL )
return - V_33 ;
V_32 = F_21 ( V_34 ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
if ( V_34 [ V_31 ] == NULL )
continue;
if ( strncmp ( V_34 [ V_31 ] , V_29 , V_30 ) == 0 )
return V_31 ;
}
return - V_33 ;
}
T_2 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_7 )
{
F_2 ( & V_2 -> V_35 ) ;
if ( V_7 -> V_29 != NULL && V_7 -> V_30 > 0 ) {
int V_36 = F_20 ( V_7 -> V_29 ,
V_7 -> V_30 ) ;
if ( V_36 > 0 ) {
F_19 ( L_4 , V_36 ) ;
if ( V_2 -> V_37 & F_23 ( V_36 ) ) {
F_11 ( & V_2 -> V_35 ) ;
return V_38 ;
}
F_24 ( F_23 ( V_36 ) , & V_2 -> V_37 ) ;
F_11 ( & V_2 -> V_35 ) ;
return V_36 ;
}
V_36 = F_25 ( & V_2 -> V_39 , V_40 ) ;
if ( V_36 == V_40 ) {
F_11 ( & V_2 -> V_35 ) ;
return V_38 ;
}
F_19 ( L_5 , V_41 + V_36 ) ;
F_24 ( F_23 ( V_36 ) , & V_2 -> V_39 ) ;
F_11 ( & V_2 -> V_35 ) ;
return V_41 + V_36 ;
} else if ( V_7 -> V_36 != 0 ) {
if ( V_7 -> V_36 < V_41 ) {
if ( ! ( V_2 -> V_37 & F_23 ( V_7 -> V_36 ) ) ) {
F_24 ( F_23 ( V_7 -> V_36 ) , & V_2 -> V_37 ) ;
F_11 ( & V_2 -> V_35 ) ;
return V_7 -> V_36 ;
}
} else if ( V_7 -> V_36 < V_40 ) {
if ( ! ( V_2 -> V_39 &
F_23 ( V_7 -> V_36 - V_41 ) ) ) {
F_24 ( F_23 ( V_7 -> V_36 - V_41 ) ,
& V_2 -> V_39 ) ;
F_11 ( & V_2 -> V_35 ) ;
return V_7 -> V_36 ;
}
}
}
F_11 ( & V_2 -> V_35 ) ;
return V_38 ;
}
T_2 F_26 ( struct V_1 * V_2 )
{
T_2 V_42 ;
F_2 ( & V_2 -> V_35 ) ;
V_42 = F_25 ( & V_2 -> V_43 , V_44 ) ;
if ( V_42 == V_44 ) {
F_11 ( & V_2 -> V_35 ) ;
return V_38 ;
}
F_24 ( F_23 ( V_42 ) , & V_2 -> V_43 ) ;
F_11 ( & V_2 -> V_35 ) ;
return V_42 + V_45 ;
}
void F_27 ( struct V_1 * V_2 , T_2 V_36 )
{
T_2 V_42 ;
unsigned long * V_46 ;
if ( V_36 < V_41 ) {
V_42 = V_36 ;
V_46 = & V_2 -> V_37 ;
} else if ( V_36 < V_44 ) {
V_42 = V_36 - V_41 ;
V_46 = & V_2 -> V_39 ;
} else if ( V_36 < V_12 ) {
V_42 = V_36 - V_44 ;
V_46 = & V_2 -> V_43 ;
} else {
return;
}
F_2 ( & V_2 -> V_35 ) ;
F_28 ( 1 << V_42 , V_46 ) ;
F_11 ( & V_2 -> V_35 ) ;
}
T_2 * F_29 ( struct V_28 * V_17 , T_2 * V_47 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL ) {
* V_47 = 0 ;
return NULL ;
}
* V_47 = V_2 -> V_48 ;
return V_2 -> V_49 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_2 * V_50 , * V_51 , V_52 , V_53 ;
T_2 * V_54 , V_55 , V_56 ;
T_2 * V_57 , V_58 ;
T_2 V_48 = 0 ;
V_52 = V_59 ;
V_51 = F_31 ( V_60 , & V_52 ,
1 , & V_53 ) ;
V_48 += V_53 ;
V_55 = 150 ;
V_54 = F_31 ( V_60 , & V_55 , 1 , & V_56 ) ;
V_48 += V_56 ;
F_19 ( L_6 , V_2 -> V_37 ) ;
V_57 = F_31 ( V_61 , ( T_2 * ) & V_2 -> V_37 , 2 ,
& V_58 ) ;
V_48 += V_58 ;
V_48 += F_21 ( V_62 ) ;
if ( V_48 > V_63 ) {
F_32 ( V_51 ) ;
return - V_33 ;
}
V_50 = V_2 -> V_49 ;
memcpy ( V_50 , V_62 , F_21 ( V_62 ) ) ;
V_50 += F_21 ( V_62 ) ;
memcpy ( V_50 , V_51 , V_53 ) ;
V_50 += V_53 ;
memcpy ( V_50 , V_54 , V_56 ) ;
V_50 += V_56 ;
memcpy ( V_50 , V_57 , V_58 ) ;
V_50 += V_58 ;
F_32 ( V_51 ) ;
F_32 ( V_54 ) ;
V_2 -> V_48 = V_48 ;
return 0 ;
}
int F_33 ( struct V_28 * V_17 , T_2 * V_49 , T_2 V_48 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL ) {
F_16 ( L_7 ) ;
return - V_64 ;
}
memset ( V_2 -> V_65 , 0 , V_63 ) ;
memcpy ( V_2 -> V_65 , V_49 , V_48 ) ;
V_2 -> V_66 = V_48 ;
if ( V_2 -> V_65 == NULL ||
V_2 -> V_66 == 0 )
return - V_64 ;
if ( memcmp ( V_2 -> V_65 , V_62 , 3 ) ) {
F_16 ( L_8 ) ;
return - V_33 ;
}
return F_34 ( V_2 ,
& V_2 -> V_65 [ 3 ] , V_2 -> V_66 - 3 ) ;
}
static void F_35 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 , struct V_1 ,
V_67 ) ;
struct V_68 * V_69 ;
V_69 = F_36 ( & V_2 -> V_70 ) ;
if ( V_69 != NULL ) {
F_19 ( L_9 ) ;
F_37 ( V_2 -> V_17 , V_2 -> V_71 ,
V_69 , V_72 , V_2 ) ;
} else {
F_38 ( V_2 -> V_17 ) ;
}
F_39 ( & V_2 -> V_73 ,
V_74 + F_40 ( V_2 -> V_75 ) ) ;
}
static T_2 F_41 ( struct V_68 * V_76 )
{
return ( V_76 -> V_26 [ 0 ] & 0xfc ) >> 2 ;
}
static T_2 F_42 ( struct V_68 * V_76 )
{
return ( ( V_76 -> V_26 [ 0 ] & 0x03 ) << 2 ) | ( ( V_76 -> V_26 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_2 F_43 ( struct V_68 * V_76 )
{
return V_76 -> V_26 [ 1 ] & 0x3f ;
}
static T_2 F_44 ( struct V_68 * V_76 )
{
return V_76 -> V_26 [ 2 ] >> 4 ;
}
static T_2 F_45 ( struct V_68 * V_76 )
{
return V_76 -> V_26 [ 2 ] & 0xf ;
}
static void F_46 ( struct V_3 * V_7 , struct V_68 * V_76 )
{
V_76 -> V_26 [ 2 ] = ( V_7 -> V_77 << 4 ) | ( ( V_7 -> V_78 - 1 ) % 16 ) ;
V_7 -> V_77 = ( V_7 -> V_77 + 1 ) % 16 ;
V_7 -> V_79 = ( V_7 -> V_78 - 1 ) % 16 ;
}
static struct V_3 * F_47 ( struct V_1 * V_2 ,
T_2 V_36 , T_2 V_80 )
{
struct V_3 * V_7 , * V_81 , * V_6 ;
if ( V_36 == 0 && V_80 == 0 )
return NULL ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = V_2 -> V_13 [ V_36 ] ;
if ( V_7 == NULL ) {
F_11 ( & V_2 -> V_11 ) ;
return NULL ;
}
F_19 ( L_10 , V_7 -> V_80 , V_80 ) ;
if ( V_7 -> V_80 == V_80 ) {
F_48 ( & V_7 -> V_8 ) ;
F_11 ( & V_2 -> V_11 ) ;
return V_7 ;
}
F_3 (llcp_sock, n, &sock->list, list) {
F_19 ( L_11 , V_81 ,
& V_81 -> V_8 , V_81 -> V_80 ) ;
if ( V_81 -> V_80 == V_80 ) {
F_48 ( & V_81 -> V_8 ) ;
F_11 ( & V_2 -> V_11 ) ;
return V_81 ;
}
}
F_16 ( L_12 , V_36 , V_80 ) ;
F_11 ( & V_2 -> V_11 ) ;
return NULL ;
}
static void F_49 ( struct V_3 * V_7 )
{
F_50 ( & V_7 -> V_8 ) ;
}
static T_2 * F_51 ( struct V_68 * V_69 , T_1 * V_82 )
{
T_2 * V_83 = & V_69 -> V_26 [ 2 ] , type , V_84 ;
T_1 V_85 = V_69 -> V_86 - V_87 , V_88 = 0 ;
while ( V_88 < V_85 ) {
type = V_83 [ 0 ] ;
V_84 = V_83 [ 1 ] ;
F_19 ( L_13 , type , V_84 ) ;
if ( type == V_89 ) {
* V_82 = V_84 ;
return & V_83 [ 2 ] ;
}
V_88 += V_84 + 2 ;
V_83 += V_84 + 2 ;
}
return NULL ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_7 * V_90 , * V_4 ;
struct V_3 * V_7 , * V_91 ;
T_2 V_80 , V_36 , V_92 , V_93 ;
V_80 = F_41 ( V_69 ) ;
V_36 = F_43 ( V_69 ) ;
F_19 ( L_14 , V_80 , V_36 ) ;
F_34 ( V_2 , & V_69 -> V_26 [ V_87 ] ,
V_69 -> V_86 - V_87 ) ;
if ( V_80 != V_94 ) {
V_92 = V_80 ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = V_2 -> V_13 [ V_80 ] ;
if ( V_7 == NULL ) {
F_11 ( & V_2 -> V_11 ) ;
V_93 = V_95 ;
goto V_96;
}
F_48 ( & V_7 -> V_8 ) ;
F_11 ( & V_2 -> V_11 ) ;
F_5 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_80 == V_94 &&
V_7 -> V_8 . V_15 == V_20 )
goto V_97;
} else {
T_2 * V_98 ;
T_1 V_82 ;
V_98 = F_51 ( V_69 , & V_82 ) ;
if ( V_98 == NULL ) {
V_93 = V_95 ;
goto V_96;
}
F_19 ( L_15 , V_82 ) ;
F_2 ( & V_2 -> V_11 ) ;
for ( V_92 = 0 ; V_92 < V_45 ;
V_92 ++ ) {
V_7 = V_2 -> V_13 [ V_92 ] ;
if ( V_7 == NULL )
continue;
if ( V_7 -> V_29 == NULL ||
V_7 -> V_30 == 0 )
continue;
if ( V_7 -> V_30 != V_82 )
continue;
if ( V_7 -> V_80 == V_94 &&
V_7 -> V_8 . V_15 == V_20 &&
! memcmp ( V_98 , V_7 -> V_29 , V_82 ) ) {
F_19 ( L_16 ,
V_92 ) ;
F_48 ( & V_7 -> V_8 ) ;
F_11 ( & V_2 -> V_11 ) ;
F_5 ( & V_7 -> V_8 ) ;
goto V_97;
}
}
F_11 ( & V_2 -> V_11 ) ;
}
V_93 = V_95 ;
goto V_96;
V_97:
V_4 = & V_7 -> V_8 ;
if ( F_53 ( V_4 ) ) {
V_93 = V_99 ;
F_8 ( & V_7 -> V_8 ) ;
F_50 ( & V_7 -> V_8 ) ;
goto V_96;
}
V_90 = F_54 ( NULL , V_4 -> V_100 ,
V_101 ) ;
if ( V_90 == NULL ) {
V_93 = V_99 ;
F_8 ( & V_7 -> V_8 ) ;
F_50 ( & V_7 -> V_8 ) ;
goto V_96;
}
V_91 = V_3 ( V_90 ) ;
V_91 -> V_17 = V_2 -> V_17 ;
V_91 -> V_2 = V_2 ;
V_91 -> V_102 = V_7 -> V_102 ;
V_91 -> V_36 = V_92 ;
V_91 -> V_80 = V_36 ;
V_91 -> V_4 = V_4 ;
F_19 ( L_17 , V_91 , & V_91 -> V_8 ) ;
F_55 ( & V_91 -> V_14 , & V_7 -> V_14 ) ;
F_56 ( & V_7 -> V_8 , V_90 ) ;
F_57 ( V_2 -> V_17 -> V_103 ) ;
V_90 -> V_15 = V_16 ;
V_4 -> V_104 ( V_4 , 0 ) ;
F_58 ( V_91 ) ;
F_8 ( & V_7 -> V_8 ) ;
F_50 ( & V_7 -> V_8 ) ;
return;
V_96:
F_59 ( V_2 , V_80 , V_36 , V_93 ) ;
return;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_3 * V_81 ;
struct V_7 * V_8 ;
T_2 V_80 , V_36 , V_105 , V_106 , V_107 ;
V_105 = F_42 ( V_69 ) ;
V_80 = F_41 ( V_69 ) ;
V_36 = F_43 ( V_69 ) ;
V_106 = F_44 ( V_69 ) ;
V_107 = F_45 ( V_69 ) ;
F_19 ( L_18 , V_80 , V_36 , V_107 , V_106 ) ;
V_81 = F_47 ( V_2 , V_80 , V_36 ) ;
if ( V_81 == NULL ) {
F_59 ( V_2 , V_80 , V_36 , V_108 ) ;
return;
}
V_8 = & V_81 -> V_8 ;
F_5 ( V_8 ) ;
if ( V_8 -> V_15 == V_18 ) {
F_8 ( V_8 ) ;
F_49 ( V_81 ) ;
}
if ( V_106 == V_81 -> V_78 )
V_81 -> V_78 = ( V_81 -> V_78 + 1 ) % 16 ;
else
F_16 ( L_19 ) ;
if ( V_105 == V_109 ) {
F_19 ( L_20 , & V_81 -> V_8 ) ;
F_61 ( V_69 , V_87 + V_110 ) ;
if ( F_62 ( & V_81 -> V_8 , V_69 ) ) {
F_16 ( L_21 ) ;
F_63 ( & V_81 -> V_111 , V_69 ) ;
}
}
if ( V_81 -> V_112 != V_107 ) {
struct V_68 * V_5 , * V_113 ;
V_81 -> V_112 = V_107 ;
F_64 (&llcp_sock->tx_pending_queue, s, tmp)
if ( F_44 ( V_5 ) <= V_107 ) {
F_65 ( V_5 , & V_81 -> V_114 ) ;
F_66 ( V_5 ) ;
}
}
while ( V_81 -> V_115 &&
F_67 ( & V_81 -> V_114 ) <= V_2 -> V_116 ) {
struct V_68 * V_76 , * V_117 ;
V_76 = F_36 ( & V_81 -> V_70 ) ;
if ( V_76 == NULL )
break;
F_46 ( V_81 , V_76 ) ;
V_117 = F_68 ( V_76 , V_118 ) ;
F_69 ( & V_2 -> V_70 , V_76 ) ;
F_69 ( & V_81 -> V_114 , V_117 ) ;
}
F_8 ( V_8 ) ;
F_49 ( V_81 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_3 * V_81 ;
struct V_7 * V_8 ;
T_2 V_80 , V_36 ;
V_80 = F_41 ( V_69 ) ;
V_36 = F_43 ( V_69 ) ;
V_81 = F_47 ( V_2 , V_80 , V_36 ) ;
if ( V_81 == NULL ) {
F_59 ( V_2 , V_80 , V_36 , V_108 ) ;
return;
}
V_8 = & V_81 -> V_8 ;
F_5 ( V_8 ) ;
if ( V_8 -> V_15 == V_18 ) {
F_8 ( V_8 ) ;
F_49 ( V_81 ) ;
}
if ( V_8 -> V_15 == V_16 ) {
F_6 ( V_2 -> V_17 ) ;
V_8 -> V_15 = V_18 ;
V_8 -> V_119 ( V_8 ) ;
}
F_59 ( V_2 , V_80 , V_36 , V_120 ) ;
F_8 ( V_8 ) ;
F_49 ( V_81 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_3 * V_81 ;
T_2 V_80 , V_36 ;
V_80 = F_41 ( V_69 ) ;
V_36 = F_43 ( V_69 ) ;
V_81 = F_47 ( V_2 , V_80 , V_36 ) ;
if ( V_81 == NULL )
V_81 = F_47 ( V_2 , V_80 , V_94 ) ;
if ( V_81 == NULL ) {
F_16 ( L_22 ) ;
F_59 ( V_2 , V_80 , V_36 , V_108 ) ;
return;
}
V_81 -> V_80 = V_36 ;
F_34 ( V_2 , & V_69 -> V_26 [ V_87 ] ,
V_69 -> V_86 - V_87 ) ;
F_49 ( V_81 ) ;
}
static void F_72 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 , struct V_1 ,
V_121 ) ;
T_2 V_80 , V_36 , V_105 ;
struct V_68 * V_69 ;
V_69 = V_2 -> V_122 ;
if ( V_69 == NULL ) {
F_19 ( L_23 ) ;
return;
}
V_105 = F_42 ( V_69 ) ;
V_80 = F_41 ( V_69 ) ;
V_36 = F_43 ( V_69 ) ;
F_19 ( L_24 , V_105 , V_80 , V_36 ) ;
switch ( V_105 ) {
case V_123 :
F_19 ( L_25 ) ;
break;
case V_124 :
F_19 ( L_26 ) ;
F_52 ( V_2 , V_69 ) ;
break;
case V_125 :
F_19 ( L_27 ) ;
F_70 ( V_2 , V_69 ) ;
break;
case V_126 :
F_19 ( L_28 ) ;
F_71 ( V_2 , V_69 ) ;
break;
case V_109 :
case V_127 :
F_19 ( L_29 ) ;
F_60 ( V_2 , V_69 ) ;
break;
}
F_17 ( V_2 -> V_128 , & V_2 -> V_67 ) ;
F_66 ( V_2 -> V_122 ) ;
V_2 -> V_122 = NULL ;
return;
}
void V_72 ( void * V_26 , struct V_68 * V_69 , int V_129 )
{
struct V_1 * V_2 = (struct V_1 * ) V_26 ;
F_19 ( L_30 ) ;
if ( V_129 < 0 ) {
F_16 ( L_31 , V_129 ) ;
return;
}
V_2 -> V_122 = F_73 ( V_69 ) ;
F_74 ( & V_2 -> V_73 ) ;
F_17 ( V_2 -> V_130 , & V_2 -> V_121 ) ;
return;
}
void F_75 ( struct V_28 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL )
return;
F_1 ( V_2 ) ;
}
void F_76 ( struct V_28 * V_17 , T_3 V_71 ,
T_2 V_131 , T_2 V_132 )
{
struct V_1 * V_2 ;
F_19 ( L_32 , V_132 ) ;
V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL )
return;
V_2 -> V_71 = V_71 ;
V_2 -> V_131 = V_131 ;
V_2 -> V_132 = V_132 ;
if ( V_132 == V_133 ) {
F_19 ( L_33 ) ;
F_17 ( V_2 -> V_128 , & V_2 -> V_67 ) ;
} else {
F_39 ( & V_2 -> V_73 ,
V_74 + F_40 ( V_2 -> V_75 ) ) ;
}
}
int F_77 ( struct V_28 * V_134 )
{
struct V_135 * V_17 = & V_134 -> V_17 ;
struct V_1 * V_2 ;
char V_136 [ 32 ] ;
int V_129 ;
V_2 = F_78 ( sizeof( struct V_1 ) , V_118 ) ;
if ( V_2 == NULL )
return - V_137 ;
V_2 -> V_17 = V_134 ;
F_79 ( & V_2 -> V_14 ) ;
F_80 ( & V_2 -> V_35 ) ;
F_80 ( & V_2 -> V_11 ) ;
F_81 ( & V_2 -> V_73 ) ;
V_2 -> V_73 . V_26 = ( unsigned long ) V_2 ;
V_2 -> V_73 . V_138 = F_15 ;
F_82 ( & V_2 -> V_70 ) ;
F_83 ( & V_2 -> V_67 , F_35 ) ;
snprintf ( V_136 , sizeof( V_136 ) , L_34 , F_84 ( V_17 ) ) ;
V_2 -> V_128 = F_85 ( V_136 ,
V_139 | V_140 | V_141 , 1 ) ;
if ( V_2 -> V_128 == NULL ) {
V_129 = - V_137 ;
goto V_142;
}
V_2 -> V_122 = NULL ;
F_83 ( & V_2 -> V_121 , F_72 ) ;
snprintf ( V_136 , sizeof( V_136 ) , L_35 , F_84 ( V_17 ) ) ;
V_2 -> V_130 = F_85 ( V_136 ,
V_139 | V_140 | V_141 , 1 ) ;
if ( V_2 -> V_130 == NULL ) {
V_129 = - V_137 ;
goto V_143;
}
F_83 ( & V_2 -> V_25 , F_12 ) ;
snprintf ( V_136 , sizeof( V_136 ) , L_36 , F_84 ( V_17 ) ) ;
V_2 -> V_27 = F_85 ( V_136 ,
V_139 | V_140 | V_141 , 1 ) ;
if ( V_2 -> V_27 == NULL ) {
V_129 = - V_137 ;
goto V_144;
}
F_30 ( V_2 ) ;
V_2 -> V_145 = V_146 ;
V_2 -> V_75 = V_147 ;
V_2 -> V_116 = V_148 ;
F_86 ( & V_149 , & V_2 -> V_14 ) ;
return 0 ;
V_144:
F_87 ( V_2 -> V_130 ) ;
V_143:
F_87 ( V_2 -> V_128 ) ;
V_142:
F_32 ( V_2 ) ;
return 0 ;
}
void F_88 ( struct V_28 * V_17 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL ) {
F_19 ( L_37 ) ;
return;
}
F_4 ( & V_2 -> V_14 ) ;
F_1 ( V_2 ) ;
F_89 ( & V_2 -> V_73 ) ;
F_90 ( & V_2 -> V_70 ) ;
F_87 ( V_2 -> V_128 ) ;
F_87 ( V_2 -> V_130 ) ;
F_66 ( V_2 -> V_122 ) ;
F_32 ( V_2 ) ;
}
int T_4 F_91 ( void )
{
F_79 ( & V_149 ) ;
return F_92 () ;
}
void F_93 ( void )
{
F_94 () ;
}
