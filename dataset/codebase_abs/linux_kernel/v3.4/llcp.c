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
T_2 V_47 = 0 ;
V_51 = V_58 ;
V_50 = F_32 ( V_59 , & V_51 ,
1 , & V_52 ) ;
V_47 += V_52 ;
V_54 = 150 ;
V_53 = F_32 ( V_59 , & V_54 , 1 , & V_55 ) ;
V_47 += V_55 ;
F_19 ( L_6 , V_2 -> V_23 ) ;
V_56 = F_32 ( V_60 , ( T_2 * ) & V_2 -> V_23 , 2 ,
& V_57 ) ;
V_47 += V_57 ;
V_47 += F_21 ( V_61 ) ;
if ( V_47 > V_62 ) {
F_33 ( V_50 ) ;
return - V_36 ;
}
V_49 = V_2 -> V_48 ;
memcpy ( V_49 , V_61 , F_21 ( V_61 ) ) ;
V_49 += F_21 ( V_61 ) ;
memcpy ( V_49 , V_50 , V_52 ) ;
V_49 += V_52 ;
memcpy ( V_49 , V_53 , V_55 ) ;
V_49 += V_55 ;
memcpy ( V_49 , V_56 , V_57 ) ;
V_49 += V_57 ;
F_33 ( V_50 ) ;
F_33 ( V_53 ) ;
V_2 -> V_47 = V_47 ;
return 0 ;
}
int F_34 ( struct V_31 * V_17 , T_2 * V_48 , T_2 V_47 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL ) {
F_16 ( L_7 ) ;
return - V_63 ;
}
memset ( V_2 -> V_64 , 0 , V_62 ) ;
memcpy ( V_2 -> V_64 , V_48 , V_47 ) ;
V_2 -> V_65 = V_47 ;
if ( V_2 -> V_64 == NULL || V_2 -> V_65 == 0 )
return - V_63 ;
if ( memcmp ( V_2 -> V_64 , V_61 , 3 ) ) {
F_16 ( L_8 ) ;
return - V_36 ;
}
return F_35 ( V_2 ,
& V_2 -> V_64 [ 3 ] ,
V_2 -> V_65 - 3 ) ;
}
static void F_36 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 , struct V_1 ,
V_66 ) ;
struct V_67 * V_68 ;
V_68 = F_37 ( & V_2 -> V_69 ) ;
if ( V_68 != NULL ) {
F_19 ( L_9 ) ;
F_38 ( V_2 -> V_17 , V_2 -> V_70 ,
V_68 , V_71 , V_2 ) ;
} else {
F_39 ( V_2 -> V_17 ) ;
}
F_40 ( & V_2 -> V_72 ,
V_73 + F_41 ( V_2 -> V_74 ) ) ;
}
static T_2 F_42 ( struct V_67 * V_75 )
{
return ( V_75 -> V_29 [ 0 ] & 0xfc ) >> 2 ;
}
static T_2 F_43 ( struct V_67 * V_75 )
{
return ( ( V_75 -> V_29 [ 0 ] & 0x03 ) << 2 ) | ( ( V_75 -> V_29 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_2 F_44 ( struct V_67 * V_75 )
{
return V_75 -> V_29 [ 1 ] & 0x3f ;
}
static T_2 F_45 ( struct V_67 * V_75 )
{
return V_75 -> V_29 [ 2 ] >> 4 ;
}
static T_2 F_46 ( struct V_67 * V_75 )
{
return V_75 -> V_29 [ 2 ] & 0xf ;
}
static void F_47 ( struct V_3 * V_7 , struct V_67 * V_75 )
{
V_75 -> V_29 [ 2 ] = ( V_7 -> V_76 << 4 ) | ( V_7 -> V_77 % 16 ) ;
V_7 -> V_76 = ( V_7 -> V_76 + 1 ) % 16 ;
V_7 -> V_78 = ( V_7 -> V_77 - 1 ) % 16 ;
}
static struct V_3 * F_48 ( struct V_1 * V_2 ,
T_2 V_38 , T_2 V_79 )
{
struct V_3 * V_7 , * V_80 , * V_6 ;
if ( V_38 == 0 && V_79 == 0 )
return NULL ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = V_2 -> V_13 [ V_38 ] ;
if ( V_7 == NULL ) {
F_10 ( & V_2 -> V_11 ) ;
return NULL ;
}
F_19 ( L_10 , V_7 -> V_79 , V_79 ) ;
if ( V_7 -> V_79 == V_79 ) {
F_49 ( & V_7 -> V_8 ) ;
F_10 ( & V_2 -> V_11 ) ;
return V_7 ;
}
F_3 (llcp_sock, n, &sock->list, list) {
F_19 ( L_11 , V_80 ,
& V_80 -> V_8 , V_80 -> V_79 ) ;
if ( V_80 -> V_79 == V_79 ) {
F_49 ( & V_80 -> V_8 ) ;
F_10 ( & V_2 -> V_11 ) ;
return V_80 ;
}
}
F_16 ( L_12 , V_38 , V_79 ) ;
F_10 ( & V_2 -> V_11 ) ;
return NULL ;
}
static void F_50 ( struct V_3 * V_7 )
{
F_51 ( & V_7 -> V_8 ) ;
}
static T_2 * F_52 ( struct V_67 * V_68 , T_1 * V_81 )
{
T_2 * V_82 = & V_68 -> V_29 [ 2 ] , type , V_83 ;
T_1 V_84 = V_68 -> V_85 - V_86 , V_87 = 0 ;
while ( V_87 < V_84 ) {
type = V_82 [ 0 ] ;
V_83 = V_82 [ 1 ] ;
F_19 ( L_13 , type , V_83 ) ;
if ( type == V_88 ) {
* V_81 = V_83 ;
return & V_82 [ 2 ] ;
}
V_87 += V_83 + 2 ;
V_82 += V_83 + 2 ;
}
return NULL ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_7 * V_89 , * V_4 ;
struct V_3 * V_7 , * V_90 ;
T_2 V_79 , V_38 , V_91 , V_92 ;
V_79 = F_42 ( V_68 ) ;
V_38 = F_44 ( V_68 ) ;
F_19 ( L_14 , V_79 , V_38 ) ;
F_35 ( V_2 , & V_68 -> V_29 [ V_86 ] ,
V_68 -> V_85 - V_86 ) ;
if ( V_79 != V_93 ) {
V_91 = V_79 ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = V_2 -> V_13 [ V_79 ] ;
if ( V_7 == NULL ) {
F_10 ( & V_2 -> V_11 ) ;
V_92 = V_94 ;
goto V_95;
}
F_49 ( & V_7 -> V_8 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_5 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_79 == V_93 &&
V_7 -> V_8 . V_15 == V_19 )
goto V_96;
} else {
T_2 * V_97 ;
T_1 V_81 ;
V_97 = F_52 ( V_68 , & V_81 ) ;
if ( V_97 == NULL ) {
V_92 = V_94 ;
goto V_95;
}
F_19 ( L_15 , V_81 ) ;
F_2 ( & V_2 -> V_11 ) ;
for ( V_91 = 0 ; V_91 < V_44 ;
V_91 ++ ) {
V_7 = V_2 -> V_13 [ V_91 ] ;
if ( V_7 == NULL )
continue;
if ( V_7 -> V_32 == NULL ||
V_7 -> V_33 == 0 )
continue;
if ( V_7 -> V_33 != V_81 )
continue;
if ( V_7 -> V_79 == V_93 &&
V_7 -> V_8 . V_15 == V_19 &&
! memcmp ( V_97 , V_7 -> V_32 , V_81 ) ) {
F_19 ( L_16 ,
V_91 ) ;
F_49 ( & V_7 -> V_8 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_5 ( & V_7 -> V_8 ) ;
goto V_96;
}
}
F_10 ( & V_2 -> V_11 ) ;
}
V_92 = V_94 ;
goto V_95;
V_96:
V_4 = & V_7 -> V_8 ;
if ( F_54 ( V_4 ) ) {
V_92 = V_98 ;
F_7 ( & V_7 -> V_8 ) ;
F_51 ( & V_7 -> V_8 ) ;
goto V_95;
}
V_89 = F_55 ( NULL , V_4 -> V_99 , V_100 ) ;
if ( V_89 == NULL ) {
V_92 = V_98 ;
F_7 ( & V_7 -> V_8 ) ;
F_51 ( & V_7 -> V_8 ) ;
goto V_95;
}
V_90 = V_3 ( V_89 ) ;
V_90 -> V_17 = V_2 -> V_17 ;
V_90 -> V_2 = V_2 ;
V_90 -> V_101 = V_7 -> V_101 ;
V_90 -> V_38 = V_91 ;
V_90 -> V_79 = V_38 ;
V_90 -> V_4 = V_4 ;
F_19 ( L_17 , V_90 , & V_90 -> V_8 ) ;
F_56 ( & V_90 -> V_14 , & V_7 -> V_14 ) ;
F_57 ( & V_7 -> V_8 , V_89 ) ;
F_58 ( V_2 -> V_17 -> V_102 ) ;
V_89 -> V_15 = V_16 ;
V_4 -> V_103 ( V_4 , 0 ) ;
F_59 ( V_90 ) ;
F_7 ( & V_7 -> V_8 ) ;
F_51 ( & V_7 -> V_8 ) ;
return;
V_95:
F_60 ( V_2 , V_79 , V_38 , V_92 ) ;
return;
}
int F_61 ( struct V_3 * V_7 )
{
int V_104 = 0 ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_19 ( L_18 ,
V_7 -> V_105 , F_62 ( & V_7 -> V_106 ) ,
V_2 -> V_107 ) ;
while ( V_7 -> V_105 &&
F_62 ( & V_7 -> V_106 ) < V_2 -> V_107 ) {
struct V_67 * V_75 , * V_108 ;
V_75 = F_37 ( & V_7 -> V_69 ) ;
if ( V_75 == NULL )
break;
F_47 ( V_7 , V_75 ) ;
V_108 = F_63 ( V_75 , V_109 ) ;
F_64 ( & V_2 -> V_69 , V_75 ) ;
F_64 ( & V_7 -> V_106 , V_108 ) ;
V_104 ++ ;
}
return V_104 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_3 * V_80 ;
struct V_7 * V_8 ;
T_2 V_79 , V_38 , V_110 , V_111 , V_112 ;
V_110 = F_43 ( V_68 ) ;
V_79 = F_42 ( V_68 ) ;
V_38 = F_44 ( V_68 ) ;
V_111 = F_45 ( V_68 ) ;
V_112 = F_46 ( V_68 ) ;
F_19 ( L_19 , V_79 , V_38 , V_112 , V_111 ) ;
V_80 = F_48 ( V_2 , V_79 , V_38 ) ;
if ( V_80 == NULL ) {
F_60 ( V_2 , V_79 , V_38 , V_113 ) ;
return;
}
V_8 = & V_80 -> V_8 ;
F_5 ( V_8 ) ;
if ( V_8 -> V_15 == V_18 ) {
F_7 ( V_8 ) ;
F_50 ( V_80 ) ;
}
if ( V_110 == V_114 ) {
F_19 ( L_20 , & V_80 -> V_8 ) ;
if ( V_111 == V_80 -> V_77 )
V_80 -> V_77 = ( V_80 -> V_77 + 1 ) % 16 ;
else
F_16 ( L_21 ) ;
F_66 ( V_68 , V_86 + V_115 ) ;
if ( F_67 ( & V_80 -> V_8 , V_68 ) ) {
F_16 ( L_22 ) ;
F_68 ( & V_80 -> V_116 , V_68 ) ;
}
}
if ( V_80 -> V_117 != V_112 ) {
struct V_67 * V_5 , * V_118 ;
V_80 -> V_117 = V_112 ;
F_69 (&llcp_sock->tx_pending_queue, s, tmp)
if ( F_45 ( V_5 ) <= V_112 ) {
F_70 ( V_5 , & V_80 -> V_106 ) ;
F_71 ( V_5 ) ;
}
}
if ( V_110 == V_119 )
V_80 -> V_105 = true ;
else if ( V_110 == V_120 )
V_80 -> V_105 = false ;
if ( F_61 ( V_80 ) == 0 )
F_72 ( V_80 ) ;
F_7 ( V_8 ) ;
F_50 ( V_80 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_3 * V_80 ;
struct V_7 * V_8 ;
T_2 V_79 , V_38 ;
V_79 = F_42 ( V_68 ) ;
V_38 = F_44 ( V_68 ) ;
V_80 = F_48 ( V_2 , V_79 , V_38 ) ;
if ( V_80 == NULL ) {
F_60 ( V_2 , V_79 , V_38 , V_113 ) ;
return;
}
V_8 = & V_80 -> V_8 ;
F_5 ( V_8 ) ;
if ( V_8 -> V_15 == V_18 ) {
F_7 ( V_8 ) ;
F_50 ( V_80 ) ;
}
if ( V_8 -> V_15 == V_16 ) {
F_6 ( V_2 -> V_17 ) ;
V_8 -> V_15 = V_18 ;
V_8 -> V_121 ( V_8 ) ;
}
F_60 ( V_2 , V_79 , V_38 , V_122 ) ;
F_7 ( V_8 ) ;
F_50 ( V_80 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
struct V_3 * V_80 ;
T_2 V_79 , V_38 ;
V_79 = F_42 ( V_68 ) ;
V_38 = F_44 ( V_68 ) ;
V_80 = F_48 ( V_2 , V_79 , V_38 ) ;
if ( V_80 == NULL )
V_80 = F_48 ( V_2 , V_79 , V_93 ) ;
if ( V_80 == NULL ) {
F_16 ( L_23 ) ;
F_60 ( V_2 , V_79 , V_38 , V_113 ) ;
return;
}
V_80 -> V_79 = V_38 ;
F_35 ( V_2 , & V_68 -> V_29 [ V_86 ] ,
V_68 -> V_85 - V_86 ) ;
F_50 ( V_80 ) ;
}
static void F_75 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 , struct V_1 ,
V_123 ) ;
T_2 V_79 , V_38 , V_110 ;
struct V_67 * V_68 ;
V_68 = V_2 -> V_124 ;
if ( V_68 == NULL ) {
F_19 ( L_24 ) ;
return;
}
V_110 = F_43 ( V_68 ) ;
V_79 = F_42 ( V_68 ) ;
V_38 = F_44 ( V_68 ) ;
F_19 ( L_25 , V_110 , V_79 , V_38 ) ;
switch ( V_110 ) {
case V_125 :
F_19 ( L_26 ) ;
break;
case V_126 :
F_19 ( L_27 ) ;
F_53 ( V_2 , V_68 ) ;
break;
case V_127 :
F_19 ( L_28 ) ;
F_73 ( V_2 , V_68 ) ;
break;
case V_128 :
F_19 ( L_29 ) ;
F_74 ( V_2 , V_68 ) ;
break;
case V_114 :
case V_119 :
case V_120 :
F_19 ( L_30 ) ;
F_65 ( V_2 , V_68 ) ;
break;
}
F_17 ( V_2 -> V_129 , & V_2 -> V_66 ) ;
F_71 ( V_2 -> V_124 ) ;
V_2 -> V_124 = NULL ;
return;
}
void V_71 ( void * V_29 , struct V_67 * V_68 , int V_130 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 ;
F_19 ( L_31 ) ;
if ( V_130 < 0 ) {
F_16 ( L_32 , V_130 ) ;
return;
}
V_2 -> V_124 = F_76 ( V_68 ) ;
F_77 ( & V_2 -> V_72 ) ;
F_17 ( V_2 -> V_131 , & V_2 -> V_123 ) ;
return;
}
void F_78 ( struct V_31 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL )
return;
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
}
void F_79 ( struct V_31 * V_17 , T_3 V_70 ,
T_2 V_132 , T_2 V_133 )
{
struct V_1 * V_2 ;
F_19 ( L_33 , V_133 ) ;
V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL )
return;
V_2 -> V_70 = V_70 ;
V_2 -> V_132 = V_132 ;
V_2 -> V_133 = V_133 ;
if ( V_133 == V_134 ) {
F_19 ( L_34 ) ;
F_17 ( V_2 -> V_129 , & V_2 -> V_66 ) ;
} else {
F_40 ( & V_2 -> V_72 ,
V_73 + F_41 ( V_2 -> V_74 ) ) ;
}
}
int F_80 ( struct V_31 * V_135 )
{
struct V_136 * V_17 = & V_135 -> V_17 ;
struct V_1 * V_2 ;
char V_137 [ 32 ] ;
int V_130 ;
V_2 = F_81 ( sizeof( struct V_1 ) , V_109 ) ;
if ( V_2 == NULL )
return - V_138 ;
V_2 -> V_17 = V_135 ;
F_82 ( & V_2 -> V_14 ) ;
F_83 ( & V_2 -> V_22 ) ;
F_83 ( & V_2 -> V_11 ) ;
F_84 ( & V_2 -> V_72 ) ;
V_2 -> V_72 . V_29 = ( unsigned long ) V_2 ;
V_2 -> V_72 . V_139 = F_15 ;
F_85 ( & V_2 -> V_69 ) ;
F_86 ( & V_2 -> V_66 , F_36 ) ;
snprintf ( V_137 , sizeof( V_137 ) , L_35 , F_87 ( V_17 ) ) ;
V_2 -> V_129 =
F_88 ( V_137 ,
V_140 | V_141 | V_142 ,
1 ) ;
if ( V_2 -> V_129 == NULL ) {
V_130 = - V_138 ;
goto V_143;
}
V_2 -> V_124 = NULL ;
F_86 ( & V_2 -> V_123 , F_75 ) ;
snprintf ( V_137 , sizeof( V_137 ) , L_36 , F_87 ( V_17 ) ) ;
V_2 -> V_131 =
F_88 ( V_137 ,
V_140 | V_141 | V_142 ,
1 ) ;
if ( V_2 -> V_131 == NULL ) {
V_130 = - V_138 ;
goto V_144;
}
F_86 ( & V_2 -> V_28 , F_12 ) ;
snprintf ( V_137 , sizeof( V_137 ) , L_37 , F_87 ( V_17 ) ) ;
V_2 -> V_30 =
F_88 ( V_137 ,
V_140 | V_141 | V_142 ,
1 ) ;
if ( V_2 -> V_30 == NULL ) {
V_130 = - V_138 ;
goto V_145;
}
F_31 ( V_2 ) ;
V_2 -> V_146 = V_147 ;
V_2 -> V_74 = V_148 ;
V_2 -> V_107 = V_149 ;
F_89 ( & V_150 , & V_2 -> V_14 ) ;
return 0 ;
V_145:
F_90 ( V_2 -> V_131 ) ;
V_144:
F_90 ( V_2 -> V_129 ) ;
V_143:
F_33 ( V_2 ) ;
return 0 ;
}
void F_91 ( struct V_31 * V_17 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
if ( V_2 == NULL ) {
F_19 ( L_38 ) ;
return;
}
F_92 ( & V_2 -> V_14 ) ;
F_1 ( V_2 ) ;
F_93 ( & V_2 -> V_72 ) ;
F_94 ( & V_2 -> V_69 ) ;
F_90 ( V_2 -> V_129 ) ;
F_90 ( V_2 -> V_131 ) ;
F_71 ( V_2 -> V_124 ) ;
F_33 ( V_2 ) ;
}
int T_4 F_95 ( void )
{
F_82 ( & V_150 ) ;
return F_96 () ;
}
void F_97 ( void )
{
F_98 () ;
}
