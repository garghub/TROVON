int F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
int V_4 )
{
char * V_5 , V_6 [ 4 ] ;
int V_7 = V_8 , V_9 ;
T_1 V_10 , V_11 , V_12 = 0 , V_13 ;
struct V_14 V_15 ;
V_10 = ( V_3 > V_16 ) ? V_16 : V_3 ;
V_5 = F_2 ( V_10 , V_17 ) ;
if ( ! V_5 ) {
F_3 ( L_1
L_2 , V_10 ) ;
return - 1 ;
}
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
while ( V_12 < V_3 ) {
V_13 = ( ( V_12 + V_10 ) > V_3 ) ?
( V_3 - V_12 ) : V_10 ;
V_15 . V_18 = V_13 ;
V_15 . V_19 = V_5 ;
V_9 = F_4 ( V_2 , & V_15 , 1 , V_13 ) ;
if ( V_9 != V_13 ) {
V_7 = V_20 ;
goto V_21;
}
V_12 += V_13 ;
}
if ( ! V_4 )
goto V_21;
V_11 = ( ( - V_3 ) & 3 ) ;
if ( V_11 != 0 ) {
V_15 . V_18 = V_11 ;
V_15 . V_19 = V_6 ;
V_9 = F_4 ( V_2 , & V_15 , 1 , V_11 ) ;
if ( V_9 != V_11 ) {
V_7 = V_20 ;
goto V_21;
}
}
if ( V_2 -> V_22 -> V_23 ) {
T_1 V_24 ;
V_15 . V_18 = V_25 ;
V_15 . V_19 = & V_24 ;
V_9 = F_4 ( V_2 , & V_15 , 1 , V_25 ) ;
if ( V_9 != V_25 ) {
V_7 = V_20 ;
goto V_21;
}
}
V_21:
F_5 ( V_5 ) ;
return V_7 ;
}
static int F_6 (
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
F_7 ( & V_27 -> V_30 ) ;
if ( ! V_29 -> V_31 ) {
F_8 ( & V_27 -> V_30 ) ;
return 0 ;
}
V_29 -> V_31 = 0 ;
F_8 ( & V_27 -> V_30 ) ;
F_9 ( V_27 , V_27 -> V_2 , V_32 ) ;
return 0 ;
}
static int F_10 (
struct V_26 * V_27 ,
unsigned char * V_5 ,
T_1 V_33 ,
T_1 V_34 )
{
T_1 V_35 ;
struct V_28 * V_29 ;
if ( ( V_27 -> V_36 & V_37 ) &&
( V_33 <= V_27 -> V_38 ) ) {
F_3 ( L_3
L_4
L_5
L_6 , V_27 -> V_39 , V_33 ,
( V_33 + V_34 ) , V_27 -> V_38 ) ;
return F_11 (
V_40 ,
1 , 0 , V_5 , V_27 ) ;
}
if ( V_34 ) {
if ( ( V_33 + V_34 ) > V_27 -> V_41 ) {
F_3 ( L_7
L_8
L_9 ,
V_27 -> V_39 , V_33 , V_34 , V_27 -> V_41 ) ;
return F_11 (
V_42 , 1 , 0 , V_5 , V_27 ) ;
}
V_35 = ( V_33 + V_34 ) ;
} else
V_35 = V_27 -> V_41 ;
while ( V_33 < V_35 ) {
V_29 = F_12 ( V_27 , V_33 ) ;
if ( ! V_29 )
return - 1 ;
if ( F_6 ( V_27 , V_29 ) < 0 )
return - 1 ;
V_33 ++ ;
}
return 0 ;
}
int F_13 (
struct V_26 * V_27 ,
struct V_43 * V_44 )
{
T_1 V_45 = 0 , V_46 = 0 ;
T_1 V_47 = 0 , V_48 = 0 ;
T_1 V_33 = V_44 -> V_33 ;
struct V_1 * V_2 = V_27 -> V_2 ;
while ( V_33 > V_45 ++ ) {
V_46 ++ ;
if ( ( V_44 -> V_49 +
V_2 -> V_22 -> V_50 ) <
V_2 -> V_51 -> V_52 -> V_53 ) {
V_44 -> V_54 +=
V_2 -> V_22 -> V_50 ;
V_44 -> V_49 +=
V_2 -> V_22 -> V_50 ;
} else {
V_44 -> V_54 +=
( V_2 -> V_51 -> V_52 -> V_53 -
V_44 -> V_49 ) ;
V_44 -> V_49 = 0 ;
V_47 += V_46 ;
V_46 = 0 ;
V_48 ++ ;
}
}
if ( ! V_2 -> V_51 -> V_52 -> V_55 ) {
V_27 -> V_48 = V_48 ;
V_27 -> V_47 = V_47 ;
V_27 -> V_56 = V_46 ;
}
return 0 ;
}
int F_14 (
struct V_26 * V_27 ,
struct V_43 * V_44 )
{
int V_57 = 0 , V_58 ;
T_1 V_45 , V_54 = 0 , V_59 = 0 ;
T_1 V_33 = V_44 -> V_33 ;
T_1 V_34 = V_44 -> V_34 ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_60 * V_61 = NULL , * V_62 = NULL ;
if ( ! V_27 -> V_63 ) {
F_3 ( L_10 ) ;
return - 1 ;
}
for ( V_58 = 0 ; V_58 < V_27 -> V_64 ; V_58 ++ ) {
V_62 = & V_27 -> V_63 [ V_58 ] ;
if ( ! V_62 -> V_59 )
V_61 = V_62 ;
if ( ! V_62 -> V_65 ) {
#if 0
pr_err("Ignoring non-sent sequence 0x%08x ->"
" 0x%08x\n\n", seq->first_datasn,
seq->last_datasn);
#endif
continue;
}
if ( ( V_62 -> V_66 < V_33 ) &&
( V_62 -> V_67 < V_33 ) ) {
#if 0
pr_err("Pre BegRun sequence 0x%08x ->"
" 0x%08x\n", seq->first_datasn,
seq->last_datasn);
#endif
V_54 += V_27 -> V_63 [ V_58 ] . V_68 ;
V_62 -> V_49 = V_62 -> V_56 = 0 ;
continue;
}
if ( ( V_62 -> V_66 <= V_33 ) &&
( V_62 -> V_67 >= V_33 ) ) {
#if 0
pr_err("Found sequence begrun: 0x%08x in"
" 0x%08x -> 0x%08x\n", begrun,
seq->first_datasn, seq->last_datasn);
#endif
V_59 = V_62 -> V_59 ;
V_45 = V_62 -> V_66 ;
V_62 -> V_49 = V_62 -> V_56 = 0 ;
V_57 = 1 ;
if ( V_2 -> V_51 -> V_52 -> V_55 ) {
while ( V_45 < V_33 ) {
V_62 -> V_56 ++ ;
V_54 +=
V_2 -> V_22 -> V_50 ;
V_62 -> V_49 +=
V_2 -> V_22 -> V_50 ;
V_45 ++ ;
}
} else {
int V_69 ;
struct V_70 * V_71 ;
while ( V_45 < V_33 ) {
V_62 -> V_56 ++ ;
for ( V_69 = 0 ; V_69 < V_62 -> V_72 ; V_69 ++ ) {
V_71 = & V_27 -> V_73 [
V_62 -> V_47 + V_69 ] ;
if ( V_71 -> V_45 == V_45 ) {
V_54 +=
V_71 -> V_10 ;
V_62 -> V_49 +=
V_71 -> V_10 ;
}
}
V_45 ++ ;
}
}
continue;
}
if ( ( V_62 -> V_66 > V_33 ) ||
( V_62 -> V_67 > V_33 ) ) {
#if 0
pr_err("Post BegRun sequence 0x%08x -> 0x%08x\n",
seq->first_datasn, seq->last_datasn);
#endif
V_62 -> V_49 = V_62 -> V_56 = 0 ;
continue;
}
}
if ( ! V_57 ) {
if ( ! V_33 ) {
if ( ! V_61 ) {
F_3 ( L_11
L_12 ,
V_27 -> V_39 , V_33 ) ;
return - 1 ;
}
V_59 = V_61 -> V_59 ;
V_62 -> V_49 = V_62 -> V_56 = 0 ;
goto V_74;
}
F_3 ( L_13
L_14
L_15 ,
V_27 -> V_39 , V_33 , V_34 ,
( V_2 -> V_51 -> V_52 -> V_55 ) ? L_16 : L_17 ) ;
return - 1 ;
}
V_74:
V_44 -> V_54 = V_54 ;
V_44 -> V_59 = V_59 ;
return 0 ;
}
static int F_15 (
struct V_26 * V_27 ,
unsigned char * V_5 ,
T_1 V_33 ,
T_1 V_34 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_43 * V_44 ;
struct V_75 * V_75 = & V_27 -> V_75 ;
if ( ! F_16 ( & V_75 -> V_76 ) ) {
F_3 ( L_18 ,
V_27 -> V_39 ) ;
return 0 ;
}
if ( ( V_27 -> V_36 & V_37 ) &&
( V_33 <= V_27 -> V_38 ) ) {
F_3 ( L_19
L_20
L_21
L_6 , V_27 -> V_39 , V_33 ,
( V_33 + V_34 ) , V_27 -> V_38 ) ;
return F_11 ( V_40 ,
1 , 0 , V_5 , V_27 ) ;
}
if ( ( V_33 + V_34 ) > ( V_27 -> V_45 - 1 ) ) {
F_3 ( L_22
L_23 ,
V_33 , V_34 , ( V_27 -> V_45 - 1 ) ) ;
return F_11 ( V_42 ,
1 , 0 , V_5 , V_27 ) ;
}
V_44 = F_17 () ;
if ( ! V_44 )
return F_11 ( V_77 ,
1 , 0 , V_5 , V_27 ) ;
V_44 -> V_45 = V_44 -> V_33 = V_33 ;
V_44 -> V_34 = V_34 ;
V_44 -> V_78 = 1 ;
V_44 -> V_79 = V_80 ;
F_18 ( V_27 , V_44 ) ;
V_27 -> V_81 = V_82 ;
F_19 ( V_27 , V_2 , V_27 -> V_81 ) ;
return 0 ;
}
int F_20 (
struct V_1 * V_2 ,
unsigned char * V_5 ,
T_1 V_39 ,
T_1 V_83 ,
T_1 V_33 ,
T_1 V_34 )
{
struct V_26 * V_27 ;
V_27 = F_21 ( V_2 , V_39 ) ;
if ( ! V_27 )
return 0 ;
switch ( V_27 -> V_84 ) {
case V_85 :
return F_10 ( V_27 , V_5 , V_33 , V_34 ) ;
case V_86 :
return F_15 ( V_27 , V_5 , V_33 ,
V_34 ) ;
default:
F_3 ( L_24 ,
V_27 -> V_84 ) ;
return - 1 ;
}
return 0 ;
}
int F_22 (
struct V_1 * V_2 ,
T_1 V_39 ,
T_1 V_83 ,
T_1 V_33 ,
T_1 V_34 )
{
struct V_26 * V_27 = NULL ;
T_1 V_87 ;
int V_88 ;
if ( V_2 -> V_89 > V_33 ) {
F_3 ( L_25
L_26
L_27 , V_33 , V_34 , V_2 -> V_89 ,
V_2 -> V_90 ) ;
return 0 ;
}
V_87 = ( ! V_34 ) ? V_2 -> V_91 : ( V_33 + V_34 ) ;
while ( V_33 < V_87 ) {
V_88 = 0 ;
F_7 ( & V_2 -> V_92 ) ;
F_23 (cmd, &conn->conn_cmd_list, i_list) {
if ( V_27 -> V_91 == V_33 ) {
V_88 = 1 ;
break;
}
}
F_8 ( & V_2 -> V_92 ) ;
if ( ! V_88 ) {
F_3 ( L_28
L_29
L_30
L_31 , V_33 ) ;
V_33 ++ ;
continue;
}
F_7 ( & V_27 -> V_93 ) ;
if ( V_27 -> V_81 == V_82 ) {
F_8 ( & V_27 -> V_93 ) ;
F_3 ( L_32
L_33
L_34
L_35 , V_33 , V_34 ) ;
V_33 ++ ;
continue;
}
F_8 ( & V_27 -> V_93 ) ;
V_27 -> V_81 = V_94 ;
F_19 ( V_27 , V_2 , V_27 -> V_81 ) ;
V_33 ++ ;
}
return 0 ;
}
int F_24 (
struct V_1 * V_2 ,
T_1 V_83 ,
T_1 V_33 ,
T_1 V_34 )
{
struct V_26 * V_27 = NULL ;
V_27 = F_25 ( V_2 , V_83 ) ;
if ( ! V_27 ) {
F_3 ( L_36
L_37 , V_83 ) ;
return - 1 ;
}
if ( V_33 <= V_27 -> V_38 ) {
F_3 ( L_38
L_39 ,
V_27 -> V_39 , V_33 , V_27 -> V_38 ) ;
return - 1 ;
}
V_27 -> V_36 |= V_37 ;
V_27 -> V_38 = ( V_33 - 1 ) ;
F_26 ( L_40
L_41 ,
V_27 -> V_39 , V_27 -> V_38 ) ;
return 0 ;
}
static int F_27 (
struct V_26 * V_27 ,
T_1 V_12 ,
T_1 V_68 )
{
int V_7 ;
F_7 ( & V_27 -> V_30 ) ;
V_7 = F_28 ( V_27 , V_12 , V_68 , 1 , 0 ) ;
F_8 ( & V_27 -> V_30 ) ;
return V_7 ;
}
int F_29 (
struct V_26 * V_27 ,
struct V_70 * V_71 )
{
int V_58 , V_95 = 0 , V_79 = 0 ;
T_1 V_10 = 0 , V_12 = 0 , V_72 = 0 , V_68 = 0 ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_70 * V_96 = NULL ;
if ( V_2 -> V_51 -> V_52 -> V_97 ) {
for ( V_58 = 0 ; V_58 < V_27 -> V_72 ; V_58 ++ ) {
if ( V_27 -> V_73 [ V_58 ] . V_48 == V_71 -> V_48 ) {
if ( ! V_96 )
V_96 = & V_27 -> V_73 [ V_58 ] ;
V_68 += V_27 -> V_73 [ V_58 ] . V_10 ;
V_72 ++ ;
} else if ( V_72 )
break;
}
} else {
struct V_60 * V_62 = V_27 -> V_98 ;
V_96 = & V_27 -> V_73 [ V_62 -> V_47 ] ;
V_72 = V_62 -> V_72 ;
}
if ( ! V_96 || ! V_72 )
return V_20 ;
for ( V_58 = 0 ; V_58 < V_72 ; V_58 ++ ) {
if ( V_96 [ V_58 ] . V_99 == V_100 ) {
if ( ! V_95 )
continue;
if ( F_27 ( V_27 , V_12 , V_10 ) < 0 )
return V_20 ;
V_95 = V_10 = V_12 = 0 ;
continue;
}
V_79 = 1 ;
if ( V_96 [ V_58 ] . V_99 != V_101 )
continue;
if ( ! V_12 )
V_12 = V_96 [ V_58 ] . V_12 ;
V_10 += V_96 [ V_58 ] . V_10 ;
V_95 = 1 ;
}
if ( V_95 )
if ( F_27 ( V_27 , V_12 , V_10 ) < 0 )
return V_20 ;
return ( ! V_79 ) ? V_102 : V_8 ;
}
static int F_30 (
struct V_26 * V_27 ,
T_1 V_103 ,
T_1 V_104 ,
T_1 * V_105 ,
T_1 * V_106 )
{
int V_58 ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_70 * V_71 = NULL ;
if ( V_2 -> V_51 -> V_52 -> V_97 ) {
V_27 -> V_45 = 0 ;
if ( V_2 -> V_51 -> V_52 -> V_55 ) {
* V_105 = V_27 -> V_107 ;
* V_106 = ( V_27 -> V_108 -
V_27 -> V_107 ) ;
return 0 ;
}
* V_105 = V_27 -> V_109 ;
* V_106 = ( V_27 -> V_108 - V_27 -> V_109 ) ;
for ( V_58 = 0 ; V_58 < V_27 -> V_72 ; V_58 ++ ) {
V_71 = & V_27 -> V_73 [ V_58 ] ;
if ( V_71 -> V_99 != V_100 )
continue;
if ( ( V_71 -> V_12 >= V_27 -> V_109 ) &&
( ( V_71 -> V_12 + V_71 -> V_10 ) <=
V_27 -> V_108 ) ) {
if ( ! V_27 -> V_110 )
V_27 -> V_49 -= V_71 -> V_10 ;
else
V_27 -> V_111 -= V_71 -> V_10 ;
V_27 -> V_107 -= V_71 -> V_10 ;
V_71 -> V_99 = V_101 ;
}
}
} else {
struct V_60 * V_62 = NULL ;
V_62 = F_31 ( V_27 , V_103 , V_104 ) ;
if ( ! V_62 )
return - 1 ;
* V_105 = V_62 -> V_112 ;
* V_106 = V_62 -> V_68 ;
V_27 -> V_107 -= ( V_62 -> V_12 - V_62 -> V_112 ) ;
if ( V_27 -> V_113 )
V_27 -> V_111 = V_27 -> V_107 ;
V_62 -> V_45 = 0 ;
V_62 -> V_12 = V_62 -> V_112 ;
V_62 -> V_49 = 0 ;
V_62 -> V_99 = V_114 ;
if ( V_2 -> V_51 -> V_52 -> V_55 )
return 0 ;
for ( V_58 = 0 ; V_58 < V_62 -> V_72 ; V_58 ++ ) {
V_71 = & V_27 -> V_73 [ V_58 + V_62 -> V_47 ] ;
if ( V_71 -> V_99 != V_100 )
continue;
V_71 -> V_99 = V_101 ;
}
}
return 0 ;
}
int F_32 (
struct V_26 * V_27 ,
T_1 V_103 ,
T_1 V_104 )
{
T_1 V_106 = 0 , V_105 = 0 ;
F_7 ( & V_27 -> V_93 ) ;
V_27 -> V_36 |= V_115 ;
F_8 ( & V_27 -> V_93 ) ;
if ( F_30 ( V_27 , V_103 , V_104 ,
& V_105 , & V_106 ) < 0 )
return V_20 ;
F_27 ( V_27 , V_105 , V_106 ) ;
return V_8 ;
}
static struct V_116 * F_33 ( void )
{
struct V_116 * V_117 = NULL ;
V_117 = F_34 ( V_118 , V_17 ) ;
if ( ! V_117 ) {
F_3 ( L_42
L_43 ) ;
return NULL ;
}
F_35 ( & V_117 -> V_119 ) ;
return V_117 ;
}
static int F_36 (
struct V_120 * V_51 ,
struct V_116 * V_117 )
{
struct V_116 * V_121 , * V_122 ;
if ( F_37 ( & V_51 -> V_123 ) )
F_38 ( & V_117 -> V_119 ,
& V_51 -> V_123 ) ;
else {
V_121 = F_39 ( V_51 -> V_123 . V_124 ,
F_40 ( * V_121 ) , V_119 ) ;
if ( V_121 -> V_125 < V_117 -> V_125 )
F_38 ( & V_117 -> V_119 ,
& V_51 -> V_123 ) ;
else {
F_23 (ooo_tmp, &sess->sess_ooo_cmdsn_list,
ooo_list) {
if ( V_122 -> V_125 < V_117 -> V_125 )
continue;
F_41 ( & V_117 -> V_119 ,
& V_122 -> V_119 ) ;
break;
}
}
}
return 0 ;
}
void F_42 (
struct V_120 * V_51 ,
struct V_116 * V_117 )
{
F_43 ( & V_117 -> V_119 ) ;
F_44 ( V_118 , V_117 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_116 * V_117 ;
struct V_120 * V_51 = V_2 -> V_51 ;
F_46 ( & V_51 -> V_126 ) ;
F_23 (ooo_cmdsn, &sess->sess_ooo_cmdsn_list, ooo_list) {
if ( V_117 -> V_90 != V_2 -> V_90 )
continue;
V_117 -> V_27 = NULL ;
}
F_47 ( & V_51 -> V_126 ) ;
}
int F_48 ( struct V_120 * V_51 )
{
int V_127 = 0 ;
struct V_26 * V_27 = NULL ;
struct V_116 * V_117 , * V_128 ;
F_49 (ooo_cmdsn, ooo_cmdsn_tmp,
&sess->sess_ooo_cmdsn_list, ooo_list) {
if ( V_117 -> V_125 != V_51 -> V_129 )
continue;
if ( ! V_117 -> V_27 ) {
V_51 -> V_129 ++ ;
F_42 ( V_51 , V_117 ) ;
continue;
}
V_27 = V_117 -> V_27 ;
V_27 -> V_81 = V_27 -> V_130 ;
V_127 ++ ;
V_51 -> V_129 ++ ;
F_26 ( L_44
L_45 ,
V_27 -> V_131 , V_51 -> V_129 ) ;
F_42 ( V_51 , V_117 ) ;
if ( F_50 ( V_27 , 1 ) < 0 )
return - 1 ;
continue;
}
return V_127 ;
}
int F_50 ( struct V_26 * V_27 , int V_132 )
{
struct V_75 * V_75 = & V_27 -> V_75 ;
int V_133 = 0 ;
F_7 ( & V_27 -> V_93 ) ;
if ( V_132 )
V_27 -> V_36 &= ~ V_134 ;
switch ( V_27 -> V_135 ) {
case V_136 :
if ( V_75 -> V_137 & V_138 ) {
if ( V_75 -> V_137 &
V_139 ) {
V_27 -> V_81 = V_140 ;
F_8 ( & V_27 -> V_93 ) ;
F_19 ( V_27 , V_27 -> V_2 ,
V_27 -> V_81 ) ;
return 0 ;
}
F_8 ( & V_27 -> V_93 ) ;
if ( F_51 ( V_75 ,
( V_27 -> V_110 == 0 ) ) != 0 )
return 0 ;
return F_52 ( V_75 ,
V_75 -> V_141 , 0 ) ;
}
if ( V_27 -> V_113 ) {
if ( V_27 -> V_36 & V_142 ) {
F_8 ( & V_27 -> V_93 ) ;
return F_53 (
& V_27 -> V_75 ) ;
}
F_8 ( & V_27 -> V_93 ) ;
if ( ! ( V_27 -> V_36 &
V_143 ) ) {
if ( F_51 ( V_75 , 1 )
!= 0 )
return 0 ;
F_54 ( V_27 ) ;
F_55 ( V_27 , V_27 -> V_2 , 0 ) ;
}
return 0 ;
}
F_8 ( & V_27 -> V_93 ) ;
if ( ( V_27 -> V_84 == V_85 ) &&
! ( V_27 -> V_36 & V_143 ) ) {
if ( F_51 ( V_75 , 1 ) != 0 )
return 0 ;
F_54 ( V_27 ) ;
F_7 ( & V_27 -> V_144 ) ;
F_56 ( V_27 , V_27 -> V_2 ) ;
F_8 ( & V_27 -> V_144 ) ;
}
return F_57 ( & V_27 -> V_75 ) ;
case V_145 :
case V_146 :
F_8 ( & V_27 -> V_93 ) ;
F_19 ( V_27 , V_27 -> V_2 , V_27 -> V_81 ) ;
break;
case V_147 :
if ( V_75 -> V_137 & V_138 ) {
F_8 ( & V_27 -> V_93 ) ;
F_19 ( V_27 , V_27 -> V_2 ,
V_27 -> V_81 ) ;
return 0 ;
}
F_8 ( & V_27 -> V_93 ) ;
return F_58 ( & V_27 -> V_75 ) ;
case V_148 :
F_8 ( & V_27 -> V_93 ) ;
switch ( V_27 -> V_149 ) {
case V_150 :
V_133 = F_59 ( V_27 , V_27 -> V_2 ) ;
break;
case V_151 :
V_133 = F_60 ( V_27 , V_27 -> V_2 ) ;
break;
case V_152 :
V_133 = F_61 ( V_27 , V_27 -> V_2 ) ;
break;
default:
F_3 ( L_46
L_47 , V_27 -> V_149 ) ;
return - 1 ;
}
return V_133 ;
default:
F_8 ( & V_27 -> V_93 ) ;
F_3 ( L_48
L_49 , V_27 -> V_135 ) ;
return - 1 ;
}
return 0 ;
}
void F_62 ( struct V_120 * V_51 )
{
struct V_116 * V_117 , * V_128 ;
F_46 ( & V_51 -> V_126 ) ;
F_49 (ooo_cmdsn, ooo_cmdsn_tmp,
&sess->sess_ooo_cmdsn_list, ooo_list) {
F_43 ( & V_117 -> V_119 ) ;
F_44 ( V_118 , V_117 ) ;
}
F_47 ( & V_51 -> V_126 ) ;
}
int F_63 (
struct V_120 * V_51 ,
struct V_26 * V_27 ,
T_1 V_125 )
{
int V_153 = 0 ;
struct V_116 * V_117 = NULL , * V_121 = NULL ;
V_27 -> V_130 = V_27 -> V_81 ;
V_27 -> V_81 = V_154 ;
V_27 -> V_36 |= V_134 ;
if ( F_37 ( & V_51 -> V_123 ) )
V_153 = 1 ;
else {
V_121 = F_39 ( V_51 -> V_123 . V_124 ,
F_40 ( * V_121 ) , V_119 ) ;
if ( V_121 -> V_125 != ( V_125 - 1 ) )
V_153 = 1 ;
}
V_117 = F_33 () ;
if ( ! V_117 )
return V_155 ;
V_117 -> V_27 = V_27 ;
V_117 -> V_156 = ( V_153 ) ?
( V_125 - V_51 -> V_129 ) : 1 ;
V_117 -> V_90 = V_27 -> V_2 -> V_90 ;
V_117 -> V_157 = V_51 -> V_129 ;
V_117 -> V_125 = V_125 ;
if ( F_36 ( V_51 , V_117 ) < 0 ) {
F_44 ( V_118 , V_117 ) ;
return V_155 ;
}
return V_158 ;
}
static int F_64 (
struct V_26 * V_27 ,
T_1 * V_12 ,
T_1 * V_10 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_28 * V_29 ;
if ( V_27 -> V_110 ) {
* V_12 = 0 ;
* V_10 = ( V_2 -> V_51 -> V_52 -> V_159 >
V_27 -> V_160 ) ?
V_27 -> V_160 :
V_2 -> V_51 -> V_52 -> V_159 ;
return 0 ;
}
F_7 ( & V_27 -> V_30 ) ;
if ( F_37 ( & V_27 -> V_161 ) ) {
F_3 ( L_50 ) ;
F_8 ( & V_27 -> V_30 ) ;
return - 1 ;
}
F_23 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( V_29 -> V_31 && ! V_29 -> V_162 && ! V_29 -> V_163 ) {
* V_12 = V_29 -> V_12 ;
* V_10 = V_29 -> V_68 ;
F_8 ( & V_27 -> V_30 ) ;
return 0 ;
}
}
F_8 ( & V_27 -> V_30 ) ;
F_3 ( L_51
L_52 , V_27 -> V_39 ) ;
return - 1 ;
}
static void F_65 ( unsigned long V_164 )
{
T_1 V_104 = 0 , V_103 = 0 ;
T_1 V_106 = 0 , V_105 = 0 ;
struct V_26 * V_27 = (struct V_26 * ) V_164 ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_120 * V_51 = NULL ;
struct V_165 * V_166 ;
F_66 ( V_2 ) ;
F_7 ( & V_27 -> V_144 ) ;
if ( V_27 -> V_167 & V_168 ) {
F_8 ( & V_27 -> V_144 ) ;
F_67 ( V_2 ) ;
return;
}
V_27 -> V_167 &= ~ V_169 ;
V_51 = V_2 -> V_51 ;
V_166 = F_68 ( V_51 ) ;
if ( ! V_51 -> V_52 -> V_170 ) {
F_26 ( L_53
L_54 ) ;
goto V_171;
}
if ( ++ V_27 -> V_172 == V_166 -> V_172 ) {
F_26 ( L_55
L_56 ,
V_27 -> V_39 , V_166 -> V_172 ) ;
goto V_171;
}
V_27 -> V_36 |= V_115 ;
if ( V_2 -> V_51 -> V_52 -> V_97 ) {
if ( V_2 -> V_51 -> V_52 -> V_55 ) {
V_103 = V_27 -> V_107 ;
if ( ( V_103 + ( V_2 -> V_51 -> V_52 -> V_53 -
V_27 -> V_49 ) ) > V_27 -> V_160 )
V_104 = ( V_27 -> V_160 -
V_27 -> V_107 ) ;
else
V_104 = ( V_2 -> V_51 -> V_52 -> V_53 -
V_27 -> V_49 ) ;
} else {
V_103 = V_27 -> V_109 ;
V_104 = ( V_27 -> V_108 -
V_27 -> V_109 ) ;
}
} else {
if ( F_64 ( V_27 , & V_103 ,
& V_104 ) < 0 )
goto V_171;
}
if ( F_30 ( V_27 , V_103 , V_104 ,
& V_105 , & V_106 ) < 0 )
goto V_171;
F_26 ( L_57
L_58 ,
V_27 -> V_39 , ( V_27 -> V_110 ) ? L_59 :
L_60 , V_105 , V_106 ) ;
if ( F_27 ( V_27 , V_105 , V_106 ) < 0 )
goto V_171;
F_56 ( V_27 , V_2 ) ;
F_8 ( & V_27 -> V_144 ) ;
F_67 ( V_2 ) ;
return;
V_171:
F_8 ( & V_27 -> V_144 ) ;
F_69 ( V_2 , 0 ) ;
F_67 ( V_2 ) ;
}
void F_70 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_120 * V_51 = V_2 -> V_51 ;
struct V_165 * V_166 = V_166 = F_68 ( V_51 ) ;
F_7 ( & V_27 -> V_144 ) ;
if ( ! ( V_27 -> V_167 & V_169 ) ) {
F_8 ( & V_27 -> V_144 ) ;
return;
}
F_71 ( & V_27 -> V_173 ,
( F_72 () + V_166 -> V_174 * V_175 ) ) ;
F_26 ( L_61 ,
V_27 -> V_39 ) ;
F_8 ( & V_27 -> V_144 ) ;
}
void F_56 (
struct V_26 * V_27 ,
struct V_1 * V_2 )
{
struct V_120 * V_51 = V_2 -> V_51 ;
struct V_165 * V_166 = V_166 = F_68 ( V_51 ) ;
if ( V_27 -> V_167 & V_169 )
return;
F_26 ( L_62
L_63 , V_27 -> V_39 , V_2 -> V_90 ) ;
F_73 ( & V_27 -> V_173 ) ;
V_27 -> V_173 . V_176 = ( F_72 () + V_166 -> V_174 * V_175 ) ;
V_27 -> V_173 . V_164 = ( unsigned long ) V_27 ;
V_27 -> V_173 . V_177 = F_65 ;
V_27 -> V_167 &= ~ V_168 ;
V_27 -> V_167 |= V_169 ;
F_74 ( & V_27 -> V_173 ) ;
}
void F_75 ( struct V_26 * V_27 )
{
F_7 ( & V_27 -> V_144 ) ;
if ( ! ( V_27 -> V_167 & V_169 ) ) {
F_8 ( & V_27 -> V_144 ) ;
return;
}
V_27 -> V_167 |= V_168 ;
F_8 ( & V_27 -> V_144 ) ;
F_76 ( & V_27 -> V_173 ) ;
F_7 ( & V_27 -> V_144 ) ;
V_27 -> V_167 &= ~ V_169 ;
F_26 ( L_64 ,
V_27 -> V_39 ) ;
F_8 ( & V_27 -> V_144 ) ;
}
