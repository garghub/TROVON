int F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
int V_4 )
{
char * V_5 , V_6 [ 4 ] ;
int V_7 = V_8 , V_9 ;
T_1 V_10 , V_11 , V_12 = 0 , V_13 ;
struct V_14 V_15 ;
if ( V_2 -> V_16 -> V_17 -> V_18 )
return 0 ;
V_10 = ( V_3 > V_19 ) ? V_19 : V_3 ;
V_5 = F_2 ( V_10 , V_20 ) ;
if ( ! V_5 ) {
F_3 ( L_1
L_2 , V_10 ) ;
return - 1 ;
}
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
while ( V_12 < V_3 ) {
V_13 = ( ( V_12 + V_10 ) > V_3 ) ?
( V_3 - V_12 ) : V_10 ;
V_15 . V_21 = V_13 ;
V_15 . V_22 = V_5 ;
V_9 = F_4 ( V_2 , & V_15 , 1 , V_13 ) ;
if ( V_9 != V_13 ) {
V_7 = V_23 ;
goto V_24;
}
V_12 += V_13 ;
}
if ( ! V_4 )
goto V_24;
V_11 = ( ( - V_3 ) & 3 ) ;
if ( V_11 != 0 ) {
V_15 . V_21 = V_11 ;
V_15 . V_22 = V_6 ;
V_9 = F_4 ( V_2 , & V_15 , 1 , V_11 ) ;
if ( V_9 != V_11 ) {
V_7 = V_23 ;
goto V_24;
}
}
if ( V_2 -> V_25 -> V_26 ) {
T_1 V_27 ;
V_15 . V_21 = V_28 ;
V_15 . V_22 = & V_27 ;
V_9 = F_4 ( V_2 , & V_15 , 1 , V_28 ) ;
if ( V_9 != V_28 ) {
V_7 = V_23 ;
goto V_24;
}
}
V_24:
F_5 ( V_5 ) ;
return V_7 ;
}
static int F_6 (
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
F_7 ( & V_30 -> V_33 ) ;
if ( ! V_32 -> V_34 ) {
F_8 ( & V_30 -> V_33 ) ;
return 0 ;
}
V_32 -> V_34 = 0 ;
F_8 ( & V_30 -> V_33 ) ;
F_9 ( V_30 , V_30 -> V_2 , V_35 ) ;
return 0 ;
}
static int F_10 (
struct V_29 * V_30 ,
unsigned char * V_5 ,
T_1 V_36 ,
T_1 V_37 )
{
T_1 V_38 ;
struct V_31 * V_32 ;
if ( ( V_30 -> V_39 & V_40 ) &&
( V_36 <= V_30 -> V_41 ) ) {
F_3 ( L_3
L_4
L_5
L_6 , V_30 -> V_42 , V_36 ,
( V_36 + V_37 ) , V_30 -> V_41 ) ;
return F_11 ( V_30 , V_43 , V_5 ) ;
}
if ( V_37 ) {
if ( ( V_36 + V_37 ) > V_30 -> V_44 ) {
F_3 ( L_7
L_8
L_9 ,
V_30 -> V_42 , V_36 , V_37 , V_30 -> V_44 ) ;
return F_11 ( V_30 ,
V_45 , V_5 ) ;
}
V_38 = ( V_36 + V_37 ) ;
} else
V_38 = V_30 -> V_44 ;
while ( V_36 < V_38 ) {
V_32 = F_12 ( V_30 , V_36 ) ;
if ( ! V_32 )
return - 1 ;
if ( F_6 ( V_30 , V_32 ) < 0 )
return - 1 ;
V_36 ++ ;
}
return 0 ;
}
int F_13 (
struct V_29 * V_30 ,
struct V_46 * V_47 )
{
T_1 V_48 = 0 , V_49 = 0 ;
T_1 V_50 = 0 , V_51 = 0 ;
T_1 V_36 = V_47 -> V_36 ;
struct V_1 * V_2 = V_30 -> V_2 ;
while ( V_36 > V_48 ++ ) {
V_49 ++ ;
if ( ( V_47 -> V_52 +
V_2 -> V_25 -> V_53 ) <
V_2 -> V_16 -> V_17 -> V_54 ) {
V_47 -> V_55 +=
V_2 -> V_25 -> V_53 ;
V_47 -> V_52 +=
V_2 -> V_25 -> V_53 ;
} else {
V_47 -> V_55 +=
( V_2 -> V_16 -> V_17 -> V_54 -
V_47 -> V_52 ) ;
V_47 -> V_52 = 0 ;
V_50 += V_49 ;
V_49 = 0 ;
V_51 ++ ;
}
}
if ( ! V_2 -> V_16 -> V_17 -> V_56 ) {
V_30 -> V_51 = V_51 ;
V_30 -> V_50 = V_50 ;
V_30 -> V_57 = V_49 ;
}
return 0 ;
}
int F_14 (
struct V_29 * V_30 ,
struct V_46 * V_47 )
{
int V_58 = 0 , V_59 ;
T_1 V_48 , V_55 = 0 , V_60 = 0 ;
T_1 V_36 = V_47 -> V_36 ;
T_1 V_37 = V_47 -> V_37 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_61 * V_62 = NULL , * V_63 = NULL ;
if ( ! V_30 -> V_64 ) {
F_3 ( L_10 ) ;
return - 1 ;
}
for ( V_59 = 0 ; V_59 < V_30 -> V_65 ; V_59 ++ ) {
V_63 = & V_30 -> V_64 [ V_59 ] ;
if ( ! V_63 -> V_60 )
V_62 = V_63 ;
if ( ! V_63 -> V_66 ) {
F_3 ( L_11
L_12 , V_63 -> V_67 ,
V_63 -> V_68 ) ;
continue;
}
if ( ( V_63 -> V_67 < V_36 ) &&
( V_63 -> V_68 < V_36 ) ) {
F_3 ( L_13
L_14 , V_63 -> V_67 ,
V_63 -> V_68 ) ;
V_55 += V_30 -> V_64 [ V_59 ] . V_69 ;
V_63 -> V_52 = V_63 -> V_57 = 0 ;
continue;
}
if ( ( V_63 -> V_67 <= V_36 ) &&
( V_63 -> V_68 >= V_36 ) ) {
F_3 ( L_15
L_16 , V_36 ,
V_63 -> V_67 , V_63 -> V_68 ) ;
V_60 = V_63 -> V_60 ;
V_48 = V_63 -> V_67 ;
V_63 -> V_52 = V_63 -> V_57 = 0 ;
V_58 = 1 ;
if ( V_2 -> V_16 -> V_17 -> V_56 ) {
while ( V_48 < V_36 ) {
V_63 -> V_57 ++ ;
V_55 +=
V_2 -> V_25 -> V_53 ;
V_63 -> V_52 +=
V_2 -> V_25 -> V_53 ;
V_48 ++ ;
}
} else {
int V_70 ;
struct V_71 * V_72 ;
while ( V_48 < V_36 ) {
V_63 -> V_57 ++ ;
for ( V_70 = 0 ; V_70 < V_63 -> V_73 ; V_70 ++ ) {
V_72 = & V_30 -> V_74 [
V_63 -> V_50 + V_70 ] ;
if ( V_72 -> V_48 == V_48 ) {
V_55 +=
V_72 -> V_10 ;
V_63 -> V_52 +=
V_72 -> V_10 ;
}
}
V_48 ++ ;
}
}
continue;
}
if ( ( V_63 -> V_67 > V_36 ) ||
( V_63 -> V_68 > V_36 ) ) {
F_3 ( L_17 ,
V_63 -> V_67 , V_63 -> V_68 ) ;
V_63 -> V_52 = V_63 -> V_57 = 0 ;
continue;
}
}
if ( ! V_58 ) {
if ( ! V_36 ) {
if ( ! V_62 ) {
F_3 ( L_18
L_19 ,
V_30 -> V_42 , V_36 ) ;
return - 1 ;
}
V_60 = V_62 -> V_60 ;
V_63 -> V_52 = V_63 -> V_57 = 0 ;
goto V_75;
}
F_3 ( L_20
L_21
L_22 ,
V_30 -> V_42 , V_36 , V_37 ,
( V_2 -> V_16 -> V_17 -> V_56 ) ? L_23 : L_24 ) ;
return - 1 ;
}
V_75:
V_47 -> V_55 = V_55 ;
V_47 -> V_60 = V_60 ;
return 0 ;
}
static int F_15 (
struct V_29 * V_30 ,
unsigned char * V_5 ,
T_1 V_36 ,
T_1 V_37 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_46 * V_47 ;
struct V_76 * V_76 = & V_30 -> V_76 ;
if ( ! ( V_76 -> V_77 & V_78 ) ) {
F_3 ( L_25 ,
V_30 -> V_42 ) ;
return 0 ;
}
if ( ( V_30 -> V_39 & V_40 ) &&
( V_36 <= V_30 -> V_41 ) ) {
F_3 ( L_26
L_27
L_28
L_6 , V_30 -> V_42 , V_36 ,
( V_36 + V_37 ) , V_30 -> V_41 ) ;
return F_11 ( V_30 , V_43 , V_5 ) ;
}
if ( ( V_36 + V_37 ) > ( V_30 -> V_48 - 1 ) ) {
F_3 ( L_29
L_30 ,
V_36 , V_37 , ( V_30 -> V_48 - 1 ) ) ;
return F_11 ( V_30 , V_45 ,
V_5 ) ;
}
V_47 = F_16 () ;
if ( ! V_47 )
return F_11 ( V_30 , V_79 ,
V_5 ) ;
V_47 -> V_48 = V_47 -> V_36 = V_36 ;
V_47 -> V_37 = V_37 ;
V_47 -> V_80 = 1 ;
V_47 -> V_81 = V_82 ;
F_17 ( V_30 , V_47 ) ;
V_30 -> V_83 = V_84 ;
F_18 ( V_30 , V_2 , V_30 -> V_83 ) ;
return 0 ;
}
int F_19 (
struct V_1 * V_2 ,
unsigned char * V_5 ,
T_2 V_42 ,
T_1 V_85 ,
T_1 V_36 ,
T_1 V_37 )
{
struct V_29 * V_30 ;
V_30 = F_20 ( V_2 , V_42 ) ;
if ( ! V_30 )
return 0 ;
switch ( V_30 -> V_86 ) {
case V_87 :
return F_10 ( V_30 , V_5 , V_36 , V_37 ) ;
case V_88 :
return F_15 ( V_30 , V_5 , V_36 ,
V_37 ) ;
default:
F_3 ( L_31 ,
V_30 -> V_86 ) ;
return - 1 ;
}
return 0 ;
}
int F_21 (
struct V_1 * V_2 ,
T_2 V_42 ,
T_1 V_85 ,
T_1 V_36 ,
T_1 V_37 )
{
struct V_29 * V_30 = NULL ;
T_1 V_89 ;
int V_90 ;
if ( ! V_36 ) {
V_36 = V_2 -> V_91 ;
} else if ( V_2 -> V_91 > V_36 ) {
F_3 ( L_32
L_33
L_34 , V_36 , V_37 , V_2 -> V_91 ,
V_2 -> V_92 ) ;
return 0 ;
}
V_89 = ( ! V_37 ) ? V_2 -> V_93 : ( V_36 + V_37 ) ;
while ( V_36 < V_89 ) {
V_90 = 0 ;
F_7 ( & V_2 -> V_94 ) ;
F_22 (cmd, &conn->conn_cmd_list, i_conn_node) {
if ( V_30 -> V_93 == V_36 ) {
V_90 = 1 ;
break;
}
}
F_8 ( & V_2 -> V_94 ) ;
if ( ! V_90 ) {
F_3 ( L_35
L_36
L_37
L_38 , V_36 ) ;
V_36 ++ ;
continue;
}
F_7 ( & V_30 -> V_95 ) ;
if ( V_30 -> V_83 == V_84 ) {
F_8 ( & V_30 -> V_95 ) ;
F_3 ( L_39
L_40
L_41
L_42 , V_36 , V_37 ) ;
V_36 ++ ;
continue;
}
F_8 ( & V_30 -> V_95 ) ;
V_30 -> V_83 = V_96 ;
F_18 ( V_30 , V_2 , V_30 -> V_83 ) ;
V_36 ++ ;
}
return 0 ;
}
int F_23 (
struct V_1 * V_2 ,
T_1 V_85 ,
T_1 V_36 ,
T_1 V_37 )
{
struct V_29 * V_30 = NULL ;
V_30 = F_24 ( V_2 , V_85 ) ;
if ( ! V_30 ) {
F_3 ( L_43
L_44 , V_85 ) ;
return - 1 ;
}
if ( V_36 <= V_30 -> V_41 ) {
F_3 ( L_45
L_46 ,
V_30 -> V_42 , V_36 , V_30 -> V_41 ) ;
return - 1 ;
}
V_30 -> V_39 |= V_40 ;
V_30 -> V_41 = ( V_36 - 1 ) ;
F_25 ( L_47
L_48 ,
V_30 -> V_42 , V_30 -> V_41 ) ;
return 0 ;
}
static int F_26 (
struct V_29 * V_30 ,
T_1 V_12 ,
T_1 V_69 )
{
int V_7 ;
F_7 ( & V_30 -> V_33 ) ;
V_7 = F_27 ( V_30 , V_12 , V_69 , 1 , 0 ) ;
F_8 ( & V_30 -> V_33 ) ;
return V_7 ;
}
int F_28 (
struct V_29 * V_30 ,
struct V_71 * V_72 )
{
int V_59 , V_97 = 0 , V_81 = 0 ;
T_1 V_10 = 0 , V_12 = 0 , V_73 = 0 , V_69 = 0 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_71 * V_98 = NULL ;
if ( V_2 -> V_16 -> V_17 -> V_99 ) {
for ( V_59 = 0 ; V_59 < V_30 -> V_73 ; V_59 ++ ) {
if ( V_30 -> V_74 [ V_59 ] . V_51 == V_72 -> V_51 ) {
if ( ! V_98 )
V_98 = & V_30 -> V_74 [ V_59 ] ;
V_69 += V_30 -> V_74 [ V_59 ] . V_10 ;
V_73 ++ ;
} else if ( V_73 )
break;
}
} else {
struct V_61 * V_63 = V_30 -> V_100 ;
V_98 = & V_30 -> V_74 [ V_63 -> V_50 ] ;
V_73 = V_63 -> V_73 ;
}
if ( ! V_98 || ! V_73 )
return V_23 ;
for ( V_59 = 0 ; V_59 < V_73 ; V_59 ++ ) {
if ( V_98 [ V_59 ] . V_101 == V_102 ) {
if ( ! V_97 )
continue;
if ( F_26 ( V_30 , V_12 , V_10 ) < 0 )
return V_23 ;
V_97 = V_10 = V_12 = 0 ;
continue;
}
V_81 = 1 ;
if ( V_98 [ V_59 ] . V_101 != V_103 )
continue;
if ( ! V_12 )
V_12 = V_98 [ V_59 ] . V_12 ;
V_10 += V_98 [ V_59 ] . V_10 ;
V_97 = 1 ;
}
if ( V_97 )
if ( F_26 ( V_30 , V_12 , V_10 ) < 0 )
return V_23 ;
return ( ! V_81 ) ? V_104 : V_8 ;
}
static int F_29 (
struct V_29 * V_30 ,
T_1 V_105 ,
T_1 V_106 ,
T_1 * V_107 ,
T_1 * V_108 )
{
int V_59 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_71 * V_72 = NULL ;
if ( V_2 -> V_16 -> V_17 -> V_99 ) {
V_30 -> V_48 = 0 ;
if ( V_2 -> V_16 -> V_17 -> V_56 ) {
* V_107 = V_30 -> V_109 ;
* V_108 = ( V_30 -> V_110 -
V_30 -> V_109 ) ;
return 0 ;
}
* V_107 = V_30 -> V_111 ;
* V_108 = ( V_30 -> V_110 - V_30 -> V_111 ) ;
for ( V_59 = 0 ; V_59 < V_30 -> V_73 ; V_59 ++ ) {
V_72 = & V_30 -> V_74 [ V_59 ] ;
if ( V_72 -> V_101 != V_102 )
continue;
if ( ( V_72 -> V_12 >= V_30 -> V_111 ) &&
( ( V_72 -> V_12 + V_72 -> V_10 ) <=
V_30 -> V_110 ) ) {
if ( ! V_30 -> V_112 )
V_30 -> V_52 -= V_72 -> V_10 ;
else
V_30 -> V_113 -= V_72 -> V_10 ;
V_30 -> V_109 -= V_72 -> V_10 ;
V_72 -> V_101 = V_103 ;
}
}
} else {
struct V_61 * V_63 = NULL ;
V_63 = F_30 ( V_30 , V_105 , V_106 ) ;
if ( ! V_63 )
return - 1 ;
* V_107 = V_63 -> V_114 ;
* V_108 = V_63 -> V_69 ;
V_30 -> V_109 -= ( V_63 -> V_12 - V_63 -> V_114 ) ;
if ( V_30 -> V_115 )
V_30 -> V_113 = V_30 -> V_109 ;
V_63 -> V_48 = 0 ;
V_63 -> V_12 = V_63 -> V_114 ;
V_63 -> V_52 = 0 ;
V_63 -> V_101 = V_116 ;
if ( V_2 -> V_16 -> V_17 -> V_56 )
return 0 ;
for ( V_59 = 0 ; V_59 < V_63 -> V_73 ; V_59 ++ ) {
V_72 = & V_30 -> V_74 [ V_59 + V_63 -> V_50 ] ;
if ( V_72 -> V_101 != V_102 )
continue;
V_72 -> V_101 = V_103 ;
}
}
return 0 ;
}
int F_31 (
struct V_29 * V_30 ,
T_1 V_105 ,
T_1 V_106 )
{
T_1 V_108 = 0 , V_107 = 0 ;
F_7 ( & V_30 -> V_95 ) ;
V_30 -> V_39 |= V_117 ;
F_8 ( & V_30 -> V_95 ) ;
if ( F_29 ( V_30 , V_105 , V_106 ,
& V_107 , & V_108 ) < 0 )
return V_23 ;
F_26 ( V_30 , V_107 , V_108 ) ;
return V_8 ;
}
static struct V_118 * F_32 ( void )
{
struct V_118 * V_119 = NULL ;
V_119 = F_33 ( V_120 , V_20 ) ;
if ( ! V_119 ) {
F_3 ( L_49
L_50 ) ;
return NULL ;
}
F_34 ( & V_119 -> V_121 ) ;
return V_119 ;
}
static int F_35 (
struct V_122 * V_16 ,
struct V_118 * V_119 )
{
struct V_118 * V_123 , * V_124 ;
if ( F_36 ( & V_16 -> V_125 ) )
F_37 ( & V_119 -> V_121 ,
& V_16 -> V_125 ) ;
else {
V_123 = F_38 ( V_16 -> V_125 . V_126 ,
F_39 ( * V_123 ) , V_121 ) ;
if ( F_40 ( V_123 -> V_127 , V_119 -> V_127 ) )
F_37 ( & V_119 -> V_121 ,
& V_16 -> V_125 ) ;
else {
F_22 (ooo_tmp, &sess->sess_ooo_cmdsn_list,
ooo_list) {
if ( F_40 ( V_124 -> V_127 , V_119 -> V_127 ) )
continue;
F_41 ( & V_119 -> V_121 ,
V_124 -> V_121 . V_126 ) ;
break;
}
}
}
return 0 ;
}
void F_42 (
struct V_122 * V_16 ,
struct V_118 * V_119 )
{
F_43 ( & V_119 -> V_121 ) ;
F_44 ( V_120 , V_119 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
struct V_122 * V_16 = V_2 -> V_16 ;
F_46 ( & V_16 -> V_128 ) ;
F_22 (ooo_cmdsn, &sess->sess_ooo_cmdsn_list, ooo_list) {
if ( V_119 -> V_92 != V_2 -> V_92 )
continue;
V_119 -> V_30 = NULL ;
}
F_47 ( & V_16 -> V_128 ) ;
}
int F_48 ( struct V_122 * V_16 )
{
int V_129 = 0 ;
struct V_29 * V_30 = NULL ;
struct V_118 * V_119 , * V_130 ;
F_49 (ooo_cmdsn, ooo_cmdsn_tmp,
&sess->sess_ooo_cmdsn_list, ooo_list) {
if ( V_119 -> V_127 != V_16 -> V_131 )
continue;
if ( ! V_119 -> V_30 ) {
V_16 -> V_131 ++ ;
F_42 ( V_16 , V_119 ) ;
continue;
}
V_30 = V_119 -> V_30 ;
V_30 -> V_83 = V_30 -> V_132 ;
V_129 ++ ;
V_16 -> V_131 ++ ;
F_25 ( L_51
L_52 ,
V_30 -> V_133 , V_16 -> V_131 ) ;
F_42 ( V_16 , V_119 ) ;
if ( F_50 ( V_30 , 1 ) < 0 )
return - 1 ;
continue;
}
return V_129 ;
}
int F_50 ( struct V_29 * V_30 , int V_134 )
{
struct V_76 * V_76 = & V_30 -> V_76 ;
struct V_1 * V_2 = V_30 -> V_2 ;
int V_135 = 0 ;
F_7 ( & V_30 -> V_95 ) ;
if ( V_134 )
V_30 -> V_39 &= ~ V_136 ;
switch ( V_30 -> V_137 ) {
case V_138 :
if ( V_30 -> V_139 ) {
if ( V_30 -> V_139 == V_140 ) {
V_30 -> V_83 = V_141 ;
F_8 ( & V_30 -> V_95 ) ;
F_18 ( V_30 , V_30 -> V_2 ,
V_30 -> V_83 ) ;
return 0 ;
}
F_8 ( & V_30 -> V_95 ) ;
if ( F_51 ( V_76 ,
( V_30 -> V_112 == 0 ) ) != 0 )
return 0 ;
return F_52 ( V_76 ,
V_30 -> V_139 , 0 ) ;
}
if ( V_30 -> V_115 ) {
if ( V_30 -> V_39 & V_142 ) {
F_8 ( & V_30 -> V_95 ) ;
F_53 ( & V_30 -> V_76 ) ;
return 0 ;
}
F_8 ( & V_30 -> V_95 ) ;
if ( ! ( V_30 -> V_39 &
V_143 ) ) {
if ( F_51 ( V_76 , 1 )
!= 0 )
return 0 ;
F_54 ( V_30 ) ;
V_2 -> V_144 -> V_145 ( V_2 , V_30 , false ) ;
}
return 0 ;
}
F_8 ( & V_30 -> V_95 ) ;
if ( ( V_30 -> V_86 == V_87 ) &&
! ( V_30 -> V_39 & V_143 ) ) {
if ( F_51 ( V_76 , 1 ) != 0 )
return 0 ;
F_55 ( V_30 ) ;
}
return F_56 ( & V_30 -> V_76 ) ;
case V_146 :
case V_147 :
F_8 ( & V_30 -> V_95 ) ;
F_18 ( V_30 , V_30 -> V_2 , V_30 -> V_83 ) ;
break;
case V_148 :
if ( V_30 -> V_76 . V_149 -> V_150 ) {
F_8 ( & V_30 -> V_95 ) ;
F_18 ( V_30 , V_30 -> V_2 ,
V_30 -> V_83 ) ;
return 0 ;
}
F_8 ( & V_30 -> V_95 ) ;
return F_57 ( & V_30 -> V_76 ) ;
case V_151 :
F_8 ( & V_30 -> V_95 ) ;
switch ( V_30 -> V_152 ) {
case V_153 :
V_135 = F_58 ( V_30 , V_30 -> V_2 ) ;
break;
case V_154 :
V_135 = F_59 ( V_30 , V_30 -> V_2 ) ;
break;
case V_155 :
V_135 = F_60 ( V_30 , V_30 -> V_2 ) ;
break;
default:
F_3 ( L_53
L_54 , V_30 -> V_152 ) ;
return - 1 ;
}
return V_135 ;
default:
F_8 ( & V_30 -> V_95 ) ;
F_3 ( L_55
L_56 , V_30 -> V_137 ) ;
return - 1 ;
}
return 0 ;
}
void F_61 ( struct V_122 * V_16 )
{
struct V_118 * V_119 , * V_130 ;
F_46 ( & V_16 -> V_128 ) ;
F_49 (ooo_cmdsn, ooo_cmdsn_tmp,
&sess->sess_ooo_cmdsn_list, ooo_list) {
F_43 ( & V_119 -> V_121 ) ;
F_44 ( V_120 , V_119 ) ;
}
F_47 ( & V_16 -> V_128 ) ;
}
int F_62 (
struct V_122 * V_16 ,
struct V_29 * V_30 ,
T_1 V_127 )
{
int V_156 = 0 ;
struct V_118 * V_119 = NULL , * V_123 = NULL ;
V_30 -> V_132 = V_30 -> V_83 ;
V_30 -> V_83 = V_157 ;
V_30 -> V_39 |= V_136 ;
if ( F_36 ( & V_16 -> V_125 ) )
V_156 = 1 ;
else {
V_123 = F_38 ( V_16 -> V_125 . V_126 ,
F_39 ( * V_123 ) , V_121 ) ;
if ( V_123 -> V_127 != ( V_127 - 1 ) )
V_156 = 1 ;
}
V_119 = F_32 () ;
if ( ! V_119 )
return - V_158 ;
V_119 -> V_30 = V_30 ;
V_119 -> V_159 = ( V_156 ) ?
( V_127 - V_16 -> V_131 ) : 1 ;
V_119 -> V_92 = V_30 -> V_2 -> V_92 ;
V_119 -> V_160 = V_16 -> V_131 ;
V_119 -> V_127 = V_127 ;
if ( F_35 ( V_16 , V_119 ) < 0 ) {
F_44 ( V_120 , V_119 ) ;
return - V_158 ;
}
return 0 ;
}
static int F_63 (
struct V_29 * V_30 ,
T_1 * V_12 ,
T_1 * V_10 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_31 * V_32 ;
if ( V_30 -> V_112 ) {
* V_12 = 0 ;
* V_10 = ( V_2 -> V_16 -> V_17 -> V_161 >
V_30 -> V_76 . V_162 ) ?
V_30 -> V_76 . V_162 :
V_2 -> V_16 -> V_17 -> V_161 ;
return 0 ;
}
F_7 ( & V_30 -> V_33 ) ;
if ( F_36 ( & V_30 -> V_163 ) ) {
F_3 ( L_57 ) ;
F_8 ( & V_30 -> V_33 ) ;
return - 1 ;
}
F_22 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( V_32 -> V_34 && ! V_32 -> V_164 && ! V_32 -> V_165 ) {
* V_12 = V_32 -> V_12 ;
* V_10 = V_32 -> V_69 ;
F_8 ( & V_30 -> V_33 ) ;
return 0 ;
}
}
F_8 ( & V_30 -> V_33 ) ;
F_3 ( L_58
L_59 , V_30 -> V_42 ) ;
return - 1 ;
}
static void F_64 ( unsigned long V_166 )
{
T_1 V_106 = 0 , V_105 = 0 ;
T_1 V_108 = 0 , V_107 = 0 ;
struct V_29 * V_30 = (struct V_29 * ) V_166 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_122 * V_16 = NULL ;
struct V_167 * V_168 ;
F_65 ( V_2 ) ;
F_7 ( & V_30 -> V_169 ) ;
if ( V_30 -> V_170 & V_171 ) {
F_8 ( & V_30 -> V_169 ) ;
F_66 ( V_2 ) ;
return;
}
V_30 -> V_170 &= ~ V_172 ;
V_16 = V_2 -> V_16 ;
V_168 = F_67 ( V_16 ) ;
if ( ! V_16 -> V_17 -> V_173 ) {
F_25 ( L_60
L_61 ) ;
goto V_174;
}
if ( ++ V_30 -> V_175 == V_168 -> V_175 ) {
F_25 ( L_62
L_63 ,
V_30 -> V_42 , V_168 -> V_175 ) ;
goto V_174;
}
V_30 -> V_39 |= V_117 ;
if ( V_2 -> V_16 -> V_17 -> V_99 ) {
if ( V_2 -> V_16 -> V_17 -> V_56 ) {
V_105 = V_30 -> V_109 ;
if ( ( V_105 + ( V_2 -> V_16 -> V_17 -> V_54 -
V_30 -> V_52 ) ) > V_30 -> V_76 . V_162 )
V_106 = ( V_30 -> V_76 . V_162 -
V_30 -> V_109 ) ;
else
V_106 = ( V_2 -> V_16 -> V_17 -> V_54 -
V_30 -> V_52 ) ;
} else {
V_105 = V_30 -> V_111 ;
V_106 = ( V_30 -> V_110 -
V_30 -> V_111 ) ;
}
} else {
if ( F_63 ( V_30 , & V_105 ,
& V_106 ) < 0 )
goto V_174;
}
if ( F_29 ( V_30 , V_105 , V_106 ,
& V_107 , & V_108 ) < 0 )
goto V_174;
F_25 ( L_64
L_65 ,
V_30 -> V_42 , ( V_30 -> V_112 ) ? L_66 :
L_67 , V_107 , V_108 ) ;
if ( F_26 ( V_30 , V_107 , V_108 ) < 0 )
goto V_174;
F_68 ( V_30 , V_2 ) ;
F_8 ( & V_30 -> V_169 ) ;
F_66 ( V_2 ) ;
return;
V_174:
F_8 ( & V_30 -> V_169 ) ;
F_69 ( V_2 , 0 ) ;
F_66 ( V_2 ) ;
}
void F_70 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_122 * V_16 = V_2 -> V_16 ;
struct V_167 * V_168 = F_67 ( V_16 ) ;
F_7 ( & V_30 -> V_169 ) ;
if ( ! ( V_30 -> V_170 & V_172 ) ) {
F_8 ( & V_30 -> V_169 ) ;
return;
}
F_71 ( & V_30 -> V_176 ,
( F_72 () + V_168 -> V_177 * V_178 ) ) ;
F_25 ( L_68 ,
V_30 -> V_42 ) ;
F_8 ( & V_30 -> V_169 ) ;
}
void F_68 (
struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_122 * V_16 = V_2 -> V_16 ;
struct V_167 * V_168 = F_67 ( V_16 ) ;
if ( V_30 -> V_170 & V_172 )
return;
F_25 ( L_69
L_70 , V_30 -> V_42 , V_2 -> V_92 ) ;
F_73 ( & V_30 -> V_176 ) ;
V_30 -> V_176 . V_179 = ( F_72 () + V_168 -> V_177 * V_178 ) ;
V_30 -> V_176 . V_166 = ( unsigned long ) V_30 ;
V_30 -> V_176 . V_180 = F_64 ;
V_30 -> V_170 &= ~ V_171 ;
V_30 -> V_170 |= V_172 ;
F_74 ( & V_30 -> V_176 ) ;
}
void F_75 ( struct V_29 * V_30 )
{
F_7 ( & V_30 -> V_169 ) ;
if ( ! ( V_30 -> V_170 & V_172 ) ) {
F_8 ( & V_30 -> V_169 ) ;
return;
}
V_30 -> V_170 |= V_171 ;
F_8 ( & V_30 -> V_169 ) ;
F_76 ( & V_30 -> V_176 ) ;
F_7 ( & V_30 -> V_169 ) ;
V_30 -> V_170 &= ~ V_172 ;
F_25 ( L_71 ,
V_30 -> V_42 ) ;
F_8 ( & V_30 -> V_169 ) ;
}
