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
F_7 ( V_8 ) ;
F_8 ( V_8 ) ;
V_5 -> V_2 = NULL ;
}
V_9 = & V_4 -> V_8 ;
F_5 ( V_9 ) ;
if ( V_9 -> V_15 == V_19 ) {
struct V_3 * V_20 , * V_6 ;
struct V_7 * V_21 ;
F_3 (lsk, n, &parent->accept_queue,
accept_queue) {
V_21 = & V_20 -> V_8 ;
F_5 ( V_21 ) ;
F_9 ( V_21 ) ;
V_21 -> V_15 = V_18 ;
F_7 ( V_21 ) ;
F_8 ( V_21 ) ;
V_20 -> V_2 = NULL ;
}
}
if ( V_9 -> V_15 == V_16 )
F_6 ( V_4 -> V_17 ) ;
V_9 -> V_15 = V_18 ;
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
V_4 -> V_2 = NULL ;
}
F_10 ( & V_2 -> V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_22 ) ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
F_10 ( & V_2 -> V_22 ) ;
}
static void F_12 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 , struct V_1 ,
V_28 ) ;
F_14 ( V_2 -> V_17 ) ;
}
static void F_15 ( unsigned long V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 ;
F_16 ( L_1 ) ;
F_17 ( V_2 -> V_30 , & V_2 -> V_28 ) ;
}
struct V_1 * F_18 ( struct V_31 * V_17 )
{
struct V_1 * V_2 , * V_6 ;
F_3 (local, n, &llcp_devices, list)
if ( V_2 -> V_17 == V_17 )
return V_2 ;
F_19 ( L_2 ) ;
return NULL ;
}
static int F_20 ( char * V_32 , T_1 V_33 )
{
int V_34 , V_35 ;
F_19 ( L_3 , V_32 ) ;
if ( V_32 == NULL )
return - V_36 ;
V_35 = F_21 ( V_37 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( V_37 [ V_34 ] == NULL )
continue;
if ( strncmp ( V_37 [ V_34 ] , V_32 , V_33 ) == 0 )
return V_34 ;
}
return - V_36 ;
}
T_2 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_7 )
{
F_2 ( & V_2 -> V_22 ) ;
if ( V_7 -> V_32 != NULL && V_7 -> V_33 > 0 ) {
int V_38 = F_20 ( V_7 -> V_32 ,
V_7 -> V_33 ) ;
if ( V_38 > 0 ) {
F_19 ( L_4 , V_38 ) ;
if ( V_2 -> V_23 & F_23 ( V_38 ) ) {
F_10 ( & V_2 -> V_22 ) ;
return V_39 ;
}
F_24 ( V_38 , & V_2 -> V_23 ) ;
F_10 ( & V_2 -> V_22 ) ;
return V_38 ;
}
V_38 = F_25 ( & V_2 -> V_24 , V_40 ) ;
if ( V_38 == V_40 ) {
F_10 ( & V_2 -> V_22 ) ;
return V_39 ;
}
F_19 ( L_5 , V_41 + V_38 ) ;
F_24 ( V_38 , & V_2 -> V_24 ) ;
F_10 ( & V_2 -> V_22 ) ;
return V_41 + V_38 ;
} else if ( V_7 -> V_38 != 0 ) {
if ( V_7 -> V_38 < V_41 ) {
if ( ! F_26 ( V_7 -> V_38 , & V_2 -> V_23 ) ) {
F_24 ( V_7 -> V_38 , & V_2 -> V_23 ) ;
F_10 ( & V_2 -> V_22 ) ;
return V_7 -> V_38 ;
}
} else if ( V_7 -> V_38 < V_40 ) {
if ( ! F_26 ( V_7 -> V_38 - V_41 ,
& V_2 -> V_24 ) ) {
F_24 ( V_7 -> V_38 - V_41 ,
& V_2 -> V_24 ) ;
F_10 ( & V_2 -> V_22 ) ;
return V_7 -> V_38 ;
}
}
}
F_10 ( & V_2 -> V_22 ) ;
return V_39 ;
}
T_2 F_27 ( struct V_1 * V_2 )
{
T_2 V_42 ;
F_2 ( & V_2 -> V_22 ) ;
V_42 = F_25 ( & V_2 -> V_25 , V_43 ) ;
if ( V_42 == V_43 ) {
F_10 ( & V_2 -> V_22 ) ;
return V_39 ;
}
F_24 ( V_42 , & V_2 -> V_25 ) ;
F_10 ( & V_2 -> V_22 ) ;
return V_42 + V_44 ;
}
void F_28 ( struct V_1 * V_2 , T_2 V_38 )
{
T_2 V_42 ;
unsigned long * V_45 ;
if ( V_38 < V_41 ) {
V_42 = V_38 ;
V_45 = & V_2 -> V_23 ;
} else if ( V_38 < V_43 ) {
V_42 = V_38 - V_41 ;
V_45 = & V_2 -> V_24 ;
} else if ( V_38 < V_12 ) {
V_42 = V_38 - V_43 ;
V_45 = & V_2 -> V_25 ;
} else {
return;
}
F_2 ( & V_2 -> V_22 ) ;
F_29 ( V_42 , V_45 ) ;
F_10 ( & V_2 -> V_22 ) ;
}
T_2 * F_30 ( struct V_31 * V_17 , T_1 * V_46 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL ) {
* V_46 = 0 ;
return NULL ;
}
* V_46 = V_2 -> V_47 ;
return V_2 -> V_48 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_2 * V_49 , * V_50 , V_51 , V_52 ;
T_2 * V_53 , V_54 , V_55 ;
T_2 * V_56 , V_57 ;
T_2 * V_58 , V_59 ;
T_3 V_60 ;
T_2 V_47 = 0 ;
V_51 = V_61 ;
V_50 = F_32 ( V_62 , & V_51 ,
1 , & V_52 ) ;
V_47 += V_52 ;
V_54 = 150 ;
V_53 = F_32 ( V_63 , & V_54 , 1 , & V_55 ) ;
V_47 += V_55 ;
F_19 ( L_6 , V_2 -> V_23 ) ;
V_56 = F_32 ( V_64 , ( T_2 * ) & V_2 -> V_23 , 2 ,
& V_57 ) ;
V_47 += V_57 ;
V_60 = F_33 ( V_65 ) ;
V_58 = F_32 ( V_66 , ( T_2 * ) & V_60 , 0 ,
& V_59 ) ;
V_47 += V_59 ;
V_47 += F_21 ( V_67 ) ;
if ( V_47 > V_68 ) {
F_34 ( V_50 ) ;
return - V_36 ;
}
V_49 = V_2 -> V_48 ;
memcpy ( V_49 , V_67 , F_21 ( V_67 ) ) ;
V_49 += F_21 ( V_67 ) ;
memcpy ( V_49 , V_50 , V_52 ) ;
V_49 += V_52 ;
memcpy ( V_49 , V_53 , V_55 ) ;
V_49 += V_55 ;
memcpy ( V_49 , V_56 , V_57 ) ;
V_49 += V_57 ;
memcpy ( V_49 , V_58 , V_59 ) ;
V_49 += V_59 ;
F_34 ( V_50 ) ;
F_34 ( V_53 ) ;
V_2 -> V_47 = V_47 ;
return 0 ;
}
int F_35 ( struct V_31 * V_17 , T_2 * V_48 , T_2 V_47 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL ) {
F_16 ( L_7 ) ;
return - V_69 ;
}
memset ( V_2 -> V_70 , 0 , V_68 ) ;
memcpy ( V_2 -> V_70 , V_48 , V_47 ) ;
V_2 -> V_71 = V_47 ;
if ( V_2 -> V_70 == NULL || V_2 -> V_71 == 0 )
return - V_69 ;
if ( memcmp ( V_2 -> V_70 , V_67 , 3 ) ) {
F_16 ( L_8 ) ;
return - V_36 ;
}
return F_36 ( V_2 ,
& V_2 -> V_70 [ 3 ] ,
V_2 -> V_71 - 3 ) ;
}
static void F_37 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 , struct V_1 ,
V_72 ) ;
struct V_73 * V_74 ;
V_74 = F_38 ( & V_2 -> V_75 ) ;
if ( V_74 != NULL ) {
F_19 ( L_9 ) ;
F_39 ( V_76 , L_10 , V_77 ,
16 , 1 , V_74 -> V_29 , V_74 -> V_78 , true ) ;
F_40 ( V_2 -> V_17 , V_2 -> V_79 ,
V_74 , V_80 , V_2 ) ;
} else {
F_41 ( V_2 -> V_17 ) ;
}
F_42 ( & V_2 -> V_81 ,
V_82 + F_43 ( V_2 -> V_83 ) ) ;
}
static T_2 F_44 ( struct V_73 * V_84 )
{
return ( V_84 -> V_29 [ 0 ] & 0xfc ) >> 2 ;
}
static T_2 F_45 ( struct V_73 * V_84 )
{
return ( ( V_84 -> V_29 [ 0 ] & 0x03 ) << 2 ) | ( ( V_84 -> V_29 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_2 F_46 ( struct V_73 * V_84 )
{
return V_84 -> V_29 [ 1 ] & 0x3f ;
}
static T_2 F_47 ( struct V_73 * V_84 )
{
return V_84 -> V_29 [ 2 ] >> 4 ;
}
static T_2 F_48 ( struct V_73 * V_84 )
{
return V_84 -> V_29 [ 2 ] & 0xf ;
}
static void F_49 ( struct V_3 * V_7 , struct V_73 * V_84 )
{
V_84 -> V_29 [ 2 ] = ( V_7 -> V_85 << 4 ) | ( V_7 -> V_86 ) ;
V_7 -> V_85 = ( V_7 -> V_85 + 1 ) % 16 ;
V_7 -> V_87 = ( V_7 -> V_86 - 1 ) % 16 ;
}
static struct V_3 * F_50 ( struct V_1 * V_2 ,
T_2 V_38 , T_2 V_88 )
{
struct V_3 * V_7 , * V_89 , * V_6 ;
F_19 ( L_11 , V_38 , V_88 ) ;
if ( V_38 == 0 && V_88 == 0 )
return NULL ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = V_2 -> V_13 [ V_38 ] ;
if ( V_7 == NULL ) {
F_10 ( & V_2 -> V_11 ) ;
return NULL ;
}
F_19 ( L_12 , V_7 -> V_88 , V_88 ) ;
if ( V_7 -> V_88 == V_88 ) {
F_51 ( & V_7 -> V_8 ) ;
F_10 ( & V_2 -> V_11 ) ;
return V_7 ;
}
F_3 (llcp_sock, n, &sock->list, list) {
F_19 ( L_13 , V_89 ,
& V_89 -> V_8 , V_89 -> V_88 ) ;
if ( V_89 -> V_88 == V_88 ) {
F_51 ( & V_89 -> V_8 ) ;
F_10 ( & V_2 -> V_11 ) ;
return V_89 ;
}
}
F_16 ( L_14 , V_38 , V_88 ) ;
F_10 ( & V_2 -> V_11 ) ;
return NULL ;
}
static void F_52 ( struct V_3 * V_7 )
{
F_53 ( & V_7 -> V_8 ) ;
}
static T_2 * F_54 ( struct V_73 * V_74 , T_1 * V_90 )
{
T_2 * V_91 = & V_74 -> V_29 [ 2 ] , type , V_92 ;
T_1 V_93 = V_74 -> V_78 - V_94 , V_95 = 0 ;
while ( V_95 < V_93 ) {
type = V_91 [ 0 ] ;
V_92 = V_91 [ 1 ] ;
F_19 ( L_15 , type , V_92 ) ;
if ( type == V_96 ) {
* V_90 = V_92 ;
return & V_91 [ 2 ] ;
}
V_95 += V_92 + 2 ;
V_91 += V_92 + 2 ;
}
return NULL ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_7 * V_97 , * V_4 ;
struct V_3 * V_7 , * V_98 ;
T_2 V_88 , V_38 , V_99 , V_100 ;
V_88 = F_44 ( V_74 ) ;
V_38 = F_46 ( V_74 ) ;
F_19 ( L_16 , V_88 , V_38 ) ;
F_36 ( V_2 , & V_74 -> V_29 [ V_94 ] ,
V_74 -> V_78 - V_94 ) ;
if ( V_88 != V_101 ) {
V_99 = V_88 ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = V_2 -> V_13 [ V_88 ] ;
if ( V_7 == NULL ) {
F_10 ( & V_2 -> V_11 ) ;
V_100 = V_102 ;
goto V_103;
}
F_51 ( & V_7 -> V_8 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_5 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_88 == V_101 &&
V_7 -> V_8 . V_15 == V_19 )
goto V_104;
} else {
T_2 * V_105 ;
T_1 V_90 ;
V_105 = F_54 ( V_74 , & V_90 ) ;
if ( V_105 == NULL ) {
V_100 = V_102 ;
goto V_103;
}
F_19 ( L_17 , V_90 ) ;
F_2 ( & V_2 -> V_11 ) ;
for ( V_99 = 0 ; V_99 < V_44 ;
V_99 ++ ) {
V_7 = V_2 -> V_13 [ V_99 ] ;
if ( V_7 == NULL )
continue;
if ( V_7 -> V_32 == NULL ||
V_7 -> V_33 == 0 )
continue;
if ( V_7 -> V_33 != V_90 )
continue;
if ( V_7 -> V_88 == V_101 &&
V_7 -> V_8 . V_15 == V_19 &&
! memcmp ( V_105 , V_7 -> V_32 , V_90 ) ) {
F_19 ( L_18 ,
V_99 ) ;
F_51 ( & V_7 -> V_8 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_5 ( & V_7 -> V_8 ) ;
goto V_104;
}
}
F_10 ( & V_2 -> V_11 ) ;
}
V_100 = V_102 ;
goto V_103;
V_104:
V_4 = & V_7 -> V_8 ;
if ( F_56 ( V_4 ) ) {
V_100 = V_106 ;
F_7 ( & V_7 -> V_8 ) ;
F_53 ( & V_7 -> V_8 ) ;
goto V_103;
}
V_97 = F_57 ( NULL , V_4 -> V_107 , V_108 ) ;
if ( V_97 == NULL ) {
V_100 = V_106 ;
F_7 ( & V_7 -> V_8 ) ;
F_53 ( & V_7 -> V_8 ) ;
goto V_103;
}
V_98 = V_3 ( V_97 ) ;
V_98 -> V_17 = V_2 -> V_17 ;
V_98 -> V_2 = V_2 ;
V_98 -> V_109 = V_7 -> V_109 ;
V_98 -> V_38 = V_99 ;
V_98 -> V_88 = V_38 ;
V_98 -> V_4 = V_4 ;
F_19 ( L_19 , V_98 , & V_98 -> V_8 ) ;
F_58 ( & V_98 -> V_14 , & V_7 -> V_14 ) ;
F_59 ( & V_7 -> V_8 , V_97 ) ;
F_60 ( V_2 -> V_17 -> V_110 ) ;
V_97 -> V_15 = V_16 ;
V_4 -> V_111 ( V_4 , 0 ) ;
F_61 ( V_98 ) ;
F_7 ( & V_7 -> V_8 ) ;
F_53 ( & V_7 -> V_8 ) ;
return;
V_103:
F_62 ( V_2 , V_88 , V_38 , V_100 ) ;
return;
}
int F_63 ( struct V_3 * V_7 )
{
int V_112 = 0 ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_19 ( L_20 ,
V_7 -> V_113 , F_64 ( & V_7 -> V_114 ) ,
V_2 -> V_115 ) ;
while ( V_7 -> V_113 &&
F_64 ( & V_7 -> V_114 ) < V_2 -> V_115 ) {
struct V_73 * V_84 , * V_116 ;
V_84 = F_38 ( & V_7 -> V_75 ) ;
if ( V_84 == NULL )
break;
F_49 ( V_7 , V_84 ) ;
V_116 = F_65 ( V_84 , V_117 ) ;
F_66 ( & V_2 -> V_75 , V_84 ) ;
F_66 ( & V_7 -> V_114 , V_116 ) ;
V_112 ++ ;
}
return V_112 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_89 ;
struct V_7 * V_8 ;
T_2 V_88 , V_38 , V_118 , V_119 , V_120 ;
V_118 = F_45 ( V_74 ) ;
V_88 = F_44 ( V_74 ) ;
V_38 = F_46 ( V_74 ) ;
V_119 = F_47 ( V_74 ) ;
V_120 = F_48 ( V_74 ) ;
F_19 ( L_21 , V_88 , V_38 , V_120 , V_119 ) ;
V_89 = F_50 ( V_2 , V_88 , V_38 ) ;
if ( V_89 == NULL ) {
F_62 ( V_2 , V_88 , V_38 , V_121 ) ;
return;
}
V_8 = & V_89 -> V_8 ;
F_5 ( V_8 ) ;
if ( V_8 -> V_15 == V_18 ) {
F_7 ( V_8 ) ;
F_52 ( V_89 ) ;
}
if ( V_118 == V_122 ) {
F_19 ( L_22 , & V_89 -> V_8 ) ;
if ( V_119 == V_89 -> V_86 )
V_89 -> V_86 = ( V_89 -> V_86 + 1 ) % 16 ;
else
F_16 ( L_23 ) ;
F_68 ( V_74 , V_94 + V_123 ) ;
if ( F_69 ( & V_89 -> V_8 , V_74 ) ) {
F_16 ( L_24 ) ;
F_70 ( & V_89 -> V_124 , V_74 ) ;
}
}
if ( V_89 -> V_125 != V_120 ) {
struct V_73 * V_5 , * V_126 ;
V_89 -> V_125 = V_120 ;
F_71 (&llcp_sock->tx_pending_queue, s, tmp)
if ( F_47 ( V_5 ) <= V_120 ) {
F_72 ( V_5 , & V_89 -> V_114 ) ;
F_73 ( V_5 ) ;
}
}
if ( V_118 == V_127 )
V_89 -> V_113 = true ;
else if ( V_118 == V_128 )
V_89 -> V_113 = false ;
if ( F_63 ( V_89 ) == 0 )
F_74 ( V_89 ) ;
F_7 ( V_8 ) ;
F_52 ( V_89 ) ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_89 ;
struct V_7 * V_8 ;
T_2 V_88 , V_38 ;
V_88 = F_44 ( V_74 ) ;
V_38 = F_46 ( V_74 ) ;
V_89 = F_50 ( V_2 , V_88 , V_38 ) ;
if ( V_89 == NULL ) {
F_62 ( V_2 , V_88 , V_38 , V_121 ) ;
return;
}
V_8 = & V_89 -> V_8 ;
F_5 ( V_8 ) ;
if ( V_8 -> V_15 == V_18 ) {
F_7 ( V_8 ) ;
F_52 ( V_89 ) ;
}
if ( V_8 -> V_15 == V_16 ) {
F_6 ( V_2 -> V_17 ) ;
V_8 -> V_15 = V_18 ;
V_8 -> V_129 ( V_8 ) ;
}
F_62 ( V_2 , V_88 , V_38 , V_130 ) ;
F_7 ( V_8 ) ;
F_52 ( V_89 ) ;
}
static void F_76 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_3 * V_89 ;
struct V_7 * V_8 ;
T_2 V_88 , V_38 ;
V_88 = F_44 ( V_74 ) ;
V_38 = F_46 ( V_74 ) ;
V_89 = F_50 ( V_2 , V_88 , V_38 ) ;
if ( V_89 == NULL )
V_89 = F_50 ( V_2 , V_88 , V_101 ) ;
if ( V_89 == NULL ) {
F_16 ( L_25 ) ;
F_62 ( V_2 , V_88 , V_38 , V_121 ) ;
return;
}
V_89 -> V_88 = V_38 ;
V_8 = & V_89 -> V_8 ;
F_36 ( V_2 , & V_74 -> V_29 [ V_94 ] ,
V_74 -> V_78 - V_94 ) ;
V_8 -> V_15 = V_16 ;
V_8 -> V_129 ( V_8 ) ;
F_52 ( V_89 ) ;
}
static void F_77 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 , struct V_1 ,
V_131 ) ;
T_2 V_88 , V_38 , V_118 ;
struct V_73 * V_74 ;
V_74 = V_2 -> V_132 ;
if ( V_74 == NULL ) {
F_19 ( L_26 ) ;
return;
}
V_118 = F_45 ( V_74 ) ;
V_88 = F_44 ( V_74 ) ;
V_38 = F_46 ( V_74 ) ;
F_19 ( L_27 , V_118 , V_88 , V_38 ) ;
if ( V_118 != V_133 )
F_39 ( V_76 , L_28 , V_77 ,
16 , 1 , V_74 -> V_29 , V_74 -> V_78 , true ) ;
switch ( V_118 ) {
case V_133 :
F_19 ( L_29 ) ;
break;
case V_134 :
F_19 ( L_30 ) ;
F_55 ( V_2 , V_74 ) ;
break;
case V_135 :
F_19 ( L_31 ) ;
F_75 ( V_2 , V_74 ) ;
break;
case V_136 :
F_19 ( L_32 ) ;
F_76 ( V_2 , V_74 ) ;
break;
case V_122 :
case V_127 :
case V_128 :
F_19 ( L_33 ) ;
F_67 ( V_2 , V_74 ) ;
break;
}
F_17 ( V_2 -> V_137 , & V_2 -> V_72 ) ;
F_73 ( V_2 -> V_132 ) ;
V_2 -> V_132 = NULL ;
return;
}
void V_80 ( void * V_29 , struct V_73 * V_74 , int V_138 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 ;
F_19 ( L_34 ) ;
if ( V_138 < 0 ) {
F_16 ( L_35 , V_138 ) ;
return;
}
V_2 -> V_132 = F_78 ( V_74 ) ;
F_79 ( & V_2 -> V_81 ) ;
F_17 ( V_2 -> V_139 , & V_2 -> V_131 ) ;
return;
}
void F_80 ( struct V_31 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL )
return;
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
}
void F_81 ( struct V_31 * V_17 , T_4 V_79 ,
T_2 V_140 , T_2 V_141 )
{
struct V_1 * V_2 ;
F_19 ( L_36 , V_141 ) ;
V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL )
return;
V_2 -> V_79 = V_79 ;
V_2 -> V_140 = V_140 ;
V_2 -> V_141 = V_141 ;
if ( V_141 == V_142 ) {
F_19 ( L_37 ) ;
F_17 ( V_2 -> V_137 , & V_2 -> V_72 ) ;
} else {
F_42 ( & V_2 -> V_81 ,
V_82 + F_43 ( V_2 -> V_83 ) ) ;
}
}
int F_82 ( struct V_31 * V_143 )
{
struct V_144 * V_17 = & V_143 -> V_17 ;
struct V_1 * V_2 ;
char V_145 [ 32 ] ;
int V_138 ;
V_2 = F_83 ( sizeof( struct V_1 ) , V_117 ) ;
if ( V_2 == NULL )
return - V_146 ;
V_2 -> V_17 = V_143 ;
F_84 ( & V_2 -> V_14 ) ;
F_85 ( & V_2 -> V_22 ) ;
F_85 ( & V_2 -> V_11 ) ;
F_86 ( & V_2 -> V_81 ) ;
V_2 -> V_81 . V_29 = ( unsigned long ) V_2 ;
V_2 -> V_81 . V_147 = F_15 ;
F_87 ( & V_2 -> V_75 ) ;
F_88 ( & V_2 -> V_72 , F_37 ) ;
snprintf ( V_145 , sizeof( V_145 ) , L_38 , F_89 ( V_17 ) ) ;
V_2 -> V_137 =
F_90 ( V_145 ,
V_148 | V_149 | V_150 ,
1 ) ;
if ( V_2 -> V_137 == NULL ) {
V_138 = - V_146 ;
goto V_151;
}
V_2 -> V_132 = NULL ;
F_88 ( & V_2 -> V_131 , F_77 ) ;
snprintf ( V_145 , sizeof( V_145 ) , L_39 , F_89 ( V_17 ) ) ;
V_2 -> V_139 =
F_90 ( V_145 ,
V_148 | V_149 | V_150 ,
1 ) ;
if ( V_2 -> V_139 == NULL ) {
V_138 = - V_146 ;
goto V_152;
}
F_88 ( & V_2 -> V_28 , F_12 ) ;
snprintf ( V_145 , sizeof( V_145 ) , L_40 , F_89 ( V_17 ) ) ;
V_2 -> V_30 =
F_90 ( V_145 ,
V_148 | V_149 | V_150 ,
1 ) ;
if ( V_2 -> V_30 == NULL ) {
V_138 = - V_146 ;
goto V_153;
}
F_31 ( V_2 ) ;
V_2 -> V_154 = V_155 ;
V_2 -> V_83 = V_156 ;
V_2 -> V_115 = V_157 ;
F_91 ( & V_158 , & V_2 -> V_14 ) ;
return 0 ;
V_153:
F_92 ( V_2 -> V_139 ) ;
V_152:
F_92 ( V_2 -> V_137 ) ;
V_151:
F_34 ( V_2 ) ;
return 0 ;
}
void F_93 ( struct V_31 * V_17 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL ) {
F_19 ( L_41 ) ;
return;
}
F_94 ( & V_2 -> V_14 ) ;
F_1 ( V_2 ) ;
F_95 ( & V_2 -> V_81 ) ;
F_96 ( & V_2 -> V_75 ) ;
F_92 ( V_2 -> V_137 ) ;
F_92 ( V_2 -> V_139 ) ;
F_73 ( V_2 -> V_132 ) ;
F_34 ( V_2 ) ;
}
int T_5 F_97 ( void )
{
F_84 ( & V_158 ) ;
return F_98 () ;
}
void F_99 ( void )
{
F_100 () ;
}
