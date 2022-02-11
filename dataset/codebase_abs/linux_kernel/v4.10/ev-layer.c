static char * F_1 ( char * V_1 , const char * V_2 )
{
while ( * V_2 )
if ( * V_1 ++ != * V_2 ++ )
return NULL ;
if ( isalnum ( * V_1 ) )
return NULL ;
return V_1 ;
}
static void F_2 ( struct V_3 * V_4 , int V_5 , int type ,
void * V_6 , int V_7 )
{
unsigned long V_8 ;
unsigned V_9 , V_10 ;
struct V_11 * V_12 ;
F_3 ( V_13 , L_1 , type , V_5 ) ;
F_4 ( & V_4 -> V_14 , V_8 ) ;
V_10 = V_4 -> V_15 ;
V_9 = ( V_10 + 1 ) % V_16 ;
if ( F_5 ( V_9 == V_4 -> V_17 ) ) {
F_6 ( V_4 -> V_18 , L_2 ) ;
F_7 ( V_6 ) ;
} else {
V_12 = V_4 -> V_19 + V_10 ;
V_12 -> type = type ;
V_12 -> V_5 = V_5 ;
V_12 -> V_6 = V_6 ;
V_12 -> V_20 = NULL ;
V_12 -> V_7 = V_7 ;
V_12 -> V_21 = NULL ;
V_4 -> V_15 = V_9 ;
}
F_8 ( & V_4 -> V_14 , V_8 ) ;
}
void F_9 ( struct V_3 * V_4 )
{
char * V_22 , * V_23 , * V_6 ;
const struct V_24 * V_25 ;
const struct V_26 * V_27 ;
int V_5 , V_7 ;
T_1 type , V_28 ;
if ( ! V_4 -> V_29 ) {
F_3 ( V_30 , L_3 , V_4 -> V_31 [ 0 ] ) ;
return;
}
V_4 -> V_31 [ V_4 -> V_29 ] = 0 ;
if ( V_4 -> V_21 . V_32 ) {
V_4 -> V_21 . V_32 = 0 ;
V_6 = F_10 ( V_4 -> V_31 , V_33 ) ;
F_3 ( V_13 , L_4 , V_6 ? V_6 : L_5 ) ;
F_2 ( V_4 , 0 , V_34 , V_6 , 0 ) ;
return;
}
for ( V_25 = V_35 ; V_25 -> V_36 ; ++ V_25 ) {
V_22 = F_1 ( V_4 -> V_31 , V_25 -> V_36 ) ;
if ( V_22 )
break;
}
if ( ! V_25 -> V_36 ) {
F_2 ( V_4 , 0 , V_37 , NULL , 0 ) ;
F_3 ( V_13 , L_6 ,
V_4 -> V_31 ) ;
return;
}
V_23 = strrchr ( V_4 -> V_31 , ';' ) ;
if ( V_23 &&
! F_11 ( V_23 + 1 , 10 , & V_5 ) &&
V_5 >= 1 && V_5 <= 65535 ) {
* V_23 = 0 ;
} else {
V_5 = 0 ;
}
F_3 ( V_13 , L_7 , V_4 -> V_31 ) ;
if ( V_5 )
F_3 ( V_13 , L_8 , V_5 ) ;
switch ( V_25 -> type ) {
case V_38 :
if ( * V_22 )
goto V_39;
F_2 ( V_4 , V_5 , V_25 -> V_40 , NULL , 0 ) ;
break;
case V_41 :
if ( ! * V_22 )
V_22 = NULL ;
else if ( * V_22 ++ != ',' )
goto V_39;
F_2 ( V_4 , 0 , V_25 -> V_40 , NULL , V_5 ) ;
while ( V_22 ) {
V_23 = NULL ;
for ( V_25 = V_35 ; V_25 -> V_36 ; ++ V_25 ) {
V_23 = F_1 ( V_22 , V_25 -> V_36 ) ;
if ( V_23 )
break;
}
if ( ! V_23 || V_25 -> type != V_42 ) {
F_12 ( V_4 -> V_18 ,
L_9 ,
V_22 ) ;
return;
}
if ( * V_23 ++ != '=' )
goto V_39;
V_22 = strchr ( V_23 , ',' ) ;
if ( V_22 )
* V_22 ++ = 0 ;
V_6 = F_10 ( V_23 , V_33 ) ;
F_2 ( V_4 , V_5 , V_25 -> V_40 , V_6 , 0 ) ;
}
break;
case V_43 :
if ( ! * V_22 ) {
F_2 ( V_4 , V_5 , V_25 -> V_40 , NULL , V_44 ) ;
break;
}
if ( * V_22 ++ != '=' )
goto V_39;
for ( V_27 = V_45 ; V_27 -> V_46 ; ++ V_27 )
if ( ! strcmp ( V_22 , V_27 -> V_46 ) )
break;
if ( ! V_27 -> V_46 )
goto V_39;
F_2 ( V_4 , V_5 , V_25 -> V_40 , NULL , V_27 -> V_47 ) ;
break;
case V_42 :
if ( * V_22 ++ != '=' )
goto V_39;
V_6 = F_10 ( V_22 , V_33 ) ;
F_2 ( V_4 , V_5 , V_25 -> V_40 , V_6 , 0 ) ;
break;
case V_48 :
if ( * V_22 ++ != '=' )
goto V_39;
V_23 = strchr ( V_22 , ',' ) ;
if ( ! V_23 )
goto V_39;
* V_23 ++ = 0 ;
if ( F_13 ( V_22 , 16 , & type ) || F_13 ( V_23 , 16 , & V_28 ) ) {
* -- V_23 = ',' ;
goto V_39;
}
V_7 = ( type << 8 ) | V_28 ;
F_2 ( V_4 , V_5 , V_25 -> V_40 , NULL , V_7 ) ;
break;
case V_49 :
if ( * V_22 ++ != '=' )
goto V_39;
if ( F_11 ( V_22 , 10 , & V_7 ) )
goto V_39;
if ( V_25 -> V_40 == V_50 )
V_4 -> V_51 = V_7 ;
F_2 ( V_4 , V_5 , V_25 -> V_40 , NULL , V_7 ) ;
break;
V_39:
F_12 ( V_4 -> V_18 , L_10 ,
V_4 -> V_31 ) ;
F_2 ( V_4 , V_5 , V_25 -> V_40 , NULL , - 1 ) ;
break;
default:
F_6 ( V_4 -> V_18 , L_11 ,
V_52 , V_4 -> V_31 ) ;
}
}
static void F_14 ( struct V_53 * * V_54 ,
struct V_3 * V_4 )
{
unsigned long V_8 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
++ ( * V_54 ) -> V_56 ;
if ( ! V_4 -> V_57 ) {
V_4 -> V_21 . V_58 |= V_59 ;
F_3 ( V_13 , L_12 ) ;
V_4 -> V_60 = 1 ;
}
if ( ! F_15 ( & ( * V_54 ) -> V_61 ) ) {
F_16 ( & ( * V_54 ) -> V_61 ) ;
F_7 ( * V_54 ) ;
* V_54 = NULL ;
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
}
static void F_17 ( struct V_53 * V_21 ,
struct V_3 * V_4 , struct V_62 * V_63 )
{
unsigned long V_8 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
++ V_21 -> V_56 ;
if ( ! V_4 -> V_57 ) {
V_4 -> V_21 . V_58 |= V_59 ;
F_3 ( V_13 , L_12 ) ;
V_4 -> V_60 = 1 ;
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
V_4 -> V_64 -> V_65 ( V_63 ) ;
if ( V_63 -> V_66 & ( V_67 | V_68 ) ) {
V_63 -> V_66 &= ~ ( V_67 | V_68 ) ;
F_18 ( V_63 ) ;
}
}
static inline struct V_53 * F_19 ( struct V_3 * V_4 ,
int V_5 )
{
unsigned long V_8 ;
int V_69 ;
struct V_53 * V_70 ;
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 )
if ( F_20 ( V_4 -> V_63 + V_69 ) >= 0 ) {
V_70 = & V_4 -> V_63 [ V_69 ] . V_21 ;
V_70 -> V_5 = V_5 ;
return V_70 ;
}
F_4 ( & V_4 -> V_55 , V_8 ) ;
V_70 = F_21 ( sizeof( struct V_53 ) , V_33 ) ;
if ( V_70 ) {
F_22 ( V_70 , NULL , V_4 , V_5 ) ;
F_23 ( & V_70 -> V_61 , & V_4 -> V_72 ) ;
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
return V_70 ;
}
static void F_24 ( struct V_3 * V_4 , int V_73 )
{
int V_69 ;
struct V_53 * V_21 ;
V_4 -> V_21 . V_58 &= ~ V_74 ;
V_4 -> V_73 = V_73 ;
V_4 -> V_75 = V_76 ;
F_25 ( V_4 ) ;
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 ) {
V_21 = & V_4 -> V_63 [ V_69 ] . V_21 ;
if ( V_21 -> V_58 & V_77 ) {
V_21 -> V_58 &= ~ V_77 ;
V_21 -> V_58 |= V_78 ;
V_4 -> V_60 = 1 ;
}
}
}
static void F_26 ( struct V_3 * V_4 , int V_79 )
{
if ( V_4 -> V_21 . V_58 & V_74 ) {
F_3 ( V_13 , L_13 ) ;
return;
}
V_4 -> V_75 = V_79 ;
V_4 -> V_73 = V_80 ;
F_27 ( V_4 ) ;
V_4 -> V_21 . V_58 |= V_74 ;
F_3 ( V_13 , L_14 ) ;
V_4 -> V_60 = 1 ;
}
static void F_28 ( struct V_3 * V_4 , const char * V_81 ,
struct V_53 * V_21 )
{
int V_5 = V_21 -> V_5 ;
struct V_82 * V_83 ;
T_2 V_84 ;
V_84 = strlen ( V_81 ) + 12 ;
V_83 = F_21 ( sizeof( struct V_82 ) + V_84 , V_33 ) ;
if ( ! V_83 ) {
F_6 ( V_4 -> V_18 , L_15 , V_52 ) ;
return;
}
if ( V_5 > 0 && V_5 <= 65535 )
V_83 -> V_85 = snprintf ( V_83 -> V_86 , V_84 ,
V_4 -> V_51 ? L_16 : L_17 ,
V_5 , V_81 ) ;
else
V_83 -> V_85 = snprintf ( V_83 -> V_86 , V_84 ,
V_4 -> V_51 ? L_18 : L_19 ,
V_81 ) ;
V_83 -> V_87 = 0 ;
V_83 -> V_9 = NULL ;
V_83 -> V_88 = NULL ;
V_4 -> V_64 -> V_89 ( V_4 , V_83 ) ;
}
static struct V_53 * F_29 ( struct V_3 * V_4 , int V_5 )
{
struct V_53 * V_21 ;
int V_69 ;
unsigned long V_8 ;
if ( V_5 == 0 )
return & V_4 -> V_21 ;
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 )
if ( V_5 == V_4 -> V_63 [ V_69 ] . V_21 . V_5 )
return & V_4 -> V_63 [ V_69 ] . V_21 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
F_30 (at_state, &cs->temp_at_states, list)
if ( V_5 == V_21 -> V_5 ) {
F_8 ( & V_4 -> V_55 , V_8 ) ;
return V_21 ;
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
return NULL ;
}
static void F_31 ( struct V_62 * V_63 )
{
if ( V_63 -> V_66 & V_90 ) {
V_63 -> V_66 &= ~ V_90 ;
F_32 ( V_63 ) ;
}
if ( V_63 -> V_66 & ( V_67 | V_68 ) ) {
V_63 -> V_66 &= ~ ( V_67 | V_68 ) ;
F_18 ( V_63 ) ;
}
F_33 ( V_63 ) ;
F_34 ( V_63 ) ;
}
static void F_35 ( struct V_62 * V_63 )
{
if ( V_63 -> V_66 & V_90 ) {
F_36 ( V_63 -> V_4 -> V_18 , L_20 ,
V_52 ) ;
return;
}
V_63 -> V_66 |= V_90 ;
F_37 ( V_63 ) ;
}
static void F_38 ( struct V_53 * V_21 , void * V_91 ,
unsigned V_56 )
{
struct V_62 * V_63 = V_21 -> V_63 ;
struct V_3 * V_4 = V_21 -> V_4 ;
char * * V_92 = V_91 ;
unsigned long V_8 ;
int V_69 ;
V_63 -> V_66 |= V_68 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
if ( V_21 -> V_56 != V_56 ) {
F_8 ( & V_4 -> V_55 , V_8 ) ;
goto error;
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
for ( V_69 = 0 ; V_69 < V_93 ; ++ V_69 ) {
F_7 ( V_63 -> V_92 [ V_69 ] ) ;
V_63 -> V_92 [ V_69 ] = V_92 [ V_69 ] ;
}
V_21 -> V_58 |= V_77 ;
F_3 ( V_13 , L_21 ) ;
V_4 -> V_60 = 1 ;
return;
error:
for ( V_69 = 0 ; V_69 < V_93 ; ++ V_69 ) {
F_7 ( V_92 [ V_69 ] ) ;
V_92 [ V_69 ] = NULL ;
}
V_21 -> V_58 |= V_78 ;
F_3 ( V_13 , L_22 ) ;
V_4 -> V_60 = 1 ;
return;
}
static void F_39 ( struct V_53 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
struct V_62 * V_63 = V_21 -> V_63 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_93 ; ++ V_69 ) {
F_7 ( V_63 -> V_92 [ V_69 ] ) ;
V_63 -> V_92 [ V_69 ] = NULL ;
}
V_63 -> V_92 [ V_94 ] = F_21 ( 9 , V_33 ) ;
V_63 -> V_92 [ V_95 ] = F_21 ( 9 , V_33 ) ;
if ( ! V_63 -> V_92 [ V_94 ] || ! V_63 -> V_92 [ V_95 ] ) {
F_6 ( V_21 -> V_4 -> V_18 , L_23 ) ;
V_21 -> V_58 |= V_96 ;
F_3 ( V_13 , L_24 ) ;
V_4 -> V_60 = 1 ;
return;
}
snprintf ( V_63 -> V_92 [ V_94 ] , 9 , L_25 , V_63 -> V_97 ) ;
snprintf ( V_63 -> V_92 [ V_95 ] , 9 , L_26 , V_63 -> V_98 + 1 ) ;
V_21 -> V_58 |= V_99 ;
F_3 ( V_13 , L_27 ) ;
V_4 -> V_60 = 1 ;
}
static void F_40 ( struct V_3 * V_4 )
{
F_25 ( V_4 ) ;
if ( V_4 -> V_75 != V_100 )
F_26 ( V_4 , V_101 ) ;
V_4 -> V_102 = 1 ;
F_41 ( V_4 ) ;
V_4 -> V_103 = 0 ;
F_42 ( & V_4 -> V_104 ) ;
}
static void F_43 ( struct V_3 * V_4 )
{
if ( V_4 -> V_75 != V_100 ) {
V_4 -> V_75 = V_76 ;
V_4 -> V_73 = V_80 ;
}
if ( V_4 -> V_102 ) {
V_4 -> V_102 = 0 ;
F_44 ( V_4 ) ;
}
V_4 -> V_105 = - V_106 ;
V_4 -> V_103 = 0 ;
F_42 ( & V_4 -> V_104 ) ;
}
static void F_45 ( struct V_3 * V_4 )
{
F_27 ( V_4 ) ;
if ( V_4 -> V_75 == V_107 ) {
V_4 -> V_75 = V_108 ;
V_4 -> V_21 . V_58 |= V_109 ;
F_3 ( V_13 , L_28 ) ;
V_4 -> V_60 = 1 ;
} else
F_43 ( V_4 ) ;
}
static void F_46 ( struct V_3 * V_4 )
{
unsigned long V_8 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
V_4 -> V_110 = 0 ;
F_8 ( & V_4 -> V_55 , V_8 ) ;
F_45 ( V_4 ) ;
}
static int F_47 ( struct V_3 * V_4 , int V_98 )
{
int V_69 ;
if ( -- V_4 -> V_111 <= 0 )
return - V_112 ;
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 )
if ( V_4 -> V_63 [ V_69 ] . V_21 . V_5 > 0 )
return - V_113 ;
if ( V_98 < 0 )
F_12 ( V_4 -> V_18 ,
L_29 ) ;
else {
F_12 ( V_4 -> V_18 ,
L_30 ) ;
V_4 -> V_63 [ V_98 ] . V_21 . V_58 |= V_77 ;
}
F_26 ( V_4 , V_101 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 ,
struct V_53 * V_114 )
{
unsigned long V_8 ;
unsigned V_98 ;
struct V_53 * V_21 ;
int V_115 = 0 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
if ( V_114 == & V_4 -> V_21 )
goto exit;
F_30 (at_state, &cs->temp_at_states, list)
if ( V_21 == V_114 )
goto exit;
for ( V_98 = 0 ; V_98 < V_4 -> V_71 ; ++ V_98 )
if ( & V_4 -> V_63 [ V_98 ] . V_21 == V_114 )
goto exit;
V_115 = 1 ;
exit:
F_8 ( & V_4 -> V_55 , V_8 ) ;
return V_115 ;
}
static void F_49 ( struct V_3 * V_4 , struct V_62 * V_63 ,
struct V_53 * V_21 )
{
int V_115 ;
V_115 = F_50 ( V_21 ) ;
switch ( V_115 ) {
case V_116 :
break;
default:
F_6 ( V_4 -> V_18 , L_31 , V_115 ) ;
case V_117 :
case V_118 :
V_21 -> V_58 |= V_96 ;
V_4 -> V_60 = 1 ;
break;
}
}
static int F_51 ( struct V_3 * V_4 )
{
int V_73 ;
int V_69 ;
switch ( V_4 -> V_75 ) {
case V_76 :
case V_107 :
if ( V_4 -> V_119 || ! F_15 ( & V_4 -> V_72 ) ||
V_4 -> V_21 . V_58 )
return - V_113 ;
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 )
if ( V_4 -> V_63 [ V_69 ] . V_21 . V_58 )
return - V_113 ;
if ( F_52 ( V_4 ) < 0 )
return - V_113 ;
break;
case V_100 :
break;
default:
return - V_113 ;
}
V_73 = V_4 -> V_73 ;
V_4 -> V_75 = V_100 ;
V_4 -> V_73 = V_80 ;
return V_73 ;
}
static int F_53 ( struct V_3 * V_4 )
{
if ( V_4 -> V_75 != V_100 )
return - V_120 ;
V_4 -> V_75 = V_76 ;
V_4 -> V_73 = V_80 ;
F_25 ( V_4 ) ;
if ( V_4 -> V_110 )
F_26 ( V_4 , V_101 ) ;
return 0 ;
}
static void F_54 ( int V_121 , struct V_3 * V_4 ,
struct V_62 * V_63 ,
struct V_53 * * V_122 , char * * V_123 ,
int * V_124 , int * V_125 ,
struct V_11 * V_126 )
{
struct V_53 * V_21 = * V_122 ;
struct V_62 * V_127 ;
unsigned long V_8 ;
int V_98 ;
unsigned char * V_1 , * V_128 ;
int V_69 ;
unsigned long V_129 ;
switch ( V_121 ) {
case V_130 :
break;
case V_131 :
V_21 -> V_103 = 1 ;
break;
case V_132 :
V_4 -> V_21 . V_58 &= ~ V_74 ;
V_4 -> V_119 = V_133 ;
V_4 -> V_73 = V_134 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
if ( ! V_4 -> V_57 ) {
F_8 ( & V_4 -> V_55 , V_8 ) ;
F_25 ( V_4 ) ;
V_4 -> V_75 = V_107 ;
break;
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
V_4 -> V_21 . V_58 |= V_135 ;
F_3 ( V_13 , L_32 ) ;
V_4 -> V_60 = 1 ;
break;
case V_136 :
F_12 ( V_4 -> V_18 , L_33 ) ;
V_4 -> V_51 = 0 ;
F_24 ( V_4 , V_80 ) ;
V_4 -> V_119 = V_133 ;
break;
case V_137 :
F_24 ( V_4 , V_138 ) ;
V_4 -> V_119 = V_133 ;
break;
case V_139 :
V_4 -> V_51 = 1 ;
V_4 -> V_140 [ 0 ] . V_141 &=
~ ( V_142 | V_143 ) ;
break;
case V_144 :
V_4 -> V_51 = 0 ;
V_4 -> V_140 [ 0 ] . V_141 =
( V_4 -> V_140 [ 0 ] . V_141 & ~ V_143 )
| V_142 ;
break;
case V_145 :
if ( V_4 -> V_75 == V_101 || V_4 -> V_75 == V_146 ) {
F_25 ( V_4 ) ;
V_4 -> V_75 = V_107 ;
}
V_4 -> V_73 = V_147 ;
V_4 -> V_119 = V_133 ;
break;
case V_148 :
V_4 -> V_73 = V_134 ;
V_4 -> V_119 = V_133 ;
break;
case V_149 :
V_4 -> V_119 = V_133 ;
if ( V_4 -> V_75 == V_101 || V_4 -> V_75 == V_146 ) {
F_24 ( V_4 , V_80 ) ;
break;
}
if ( F_47 ( V_4 , - 1 ) < 0 )
F_26 ( V_4 , V_146 ) ;
break;
case V_150 :
V_4 -> V_119 = V_133 ;
F_26 ( V_4 , V_146 ) ;
break;
case V_151 :
if ( V_4 -> V_110 ) {
struct V_82 * V_83 ;
V_83 = F_21 ( sizeof( struct V_82 ) + 3 , V_33 ) ;
if ( ! V_83 ) {
F_6 ( V_4 -> V_18 , L_15 ,
V_52 ) ;
return;
}
memcpy ( V_83 -> V_86 , L_34 , 3 ) ;
V_83 -> V_85 = 3 ;
V_83 -> V_87 = 0 ;
V_83 -> V_9 = NULL ;
V_83 -> V_88 = NULL ;
V_4 -> V_64 -> V_89 ( V_4 , V_83 ) ;
}
break;
case V_152 :
V_21 = F_19 ( V_4 , V_126 -> V_7 ) ;
if ( ! V_21 ) {
F_12 ( V_4 -> V_18 ,
L_35 ) ;
break;
}
V_21 -> V_153 = 700 ;
for ( V_69 = 0 ; V_69 < V_154 ; ++ V_69 ) {
F_7 ( V_21 -> V_155 [ V_69 ] ) ;
V_21 -> V_155 [ V_69 ] = NULL ;
}
V_21 -> V_156 [ V_157 ] = - 1 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
V_21 -> V_158 = V_159 ;
V_21 -> V_160 = 1 ;
F_8 ( & V_4 -> V_55 , V_8 ) ;
break;
case V_161 :
F_49 ( V_4 , V_63 , V_21 ) ;
break;
case V_162 :
F_12 ( V_4 -> V_18 , L_36 ) ;
case V_163 :
case V_164 :
V_4 -> V_119 = V_133 ;
F_43 ( V_4 ) ;
break;
case V_165 :
if ( V_4 -> V_166 ) {
V_21 -> V_58 |= V_167 ;
V_4 -> V_60 = 1 ;
break;
}
V_63 -> V_66 |= V_67 ;
F_55 ( V_63 ) ;
V_4 -> V_64 -> V_168 ( V_63 ) ;
break;
case V_169 :
V_4 -> V_119 = V_133 ;
V_63 = V_4 -> V_63 + V_4 -> V_170 ;
V_63 -> V_66 |= V_67 ;
F_55 ( V_63 ) ;
V_4 -> V_64 -> V_168 ( V_63 ) ;
break;
case V_171 :
V_21 -> V_156 [ V_172 ] = V_173 ;
case V_174 :
V_4 -> V_119 = V_133 ;
V_21 -> V_5 = - 1 ;
if ( ! V_63 ) {
F_14 ( V_122 , V_4 ) ;
} else if ( V_4 -> V_166 && V_4 -> V_51 ) {
V_21 -> V_58 |= V_175 ;
V_4 -> V_60 = 1 ;
} else {
F_17 ( V_21 , V_4 , V_63 ) ;
}
break;
case V_176 :
V_21 -> V_156 [ V_177 ] = 0 ;
V_4 -> V_51 = 0 ;
case V_178 :
V_4 -> V_119 = V_133 ;
V_127 = V_4 -> V_63 + V_4 -> V_170 ;
F_17 ( & V_127 -> V_21 , V_4 , V_127 ) ;
break;
case V_179 :
V_4 -> V_119 = V_133 ;
F_12 ( V_4 -> V_18 , L_37 ) ;
V_21 -> V_5 = - 1 ;
if ( ! V_63 )
F_14 ( V_122 , V_4 ) ;
else if ( V_4 -> V_166 )
V_21 -> V_58 |= V_175 ;
else
F_17 ( V_21 , V_4 , V_63 ) ;
F_26 ( V_4 , V_146 ) ;
break;
case V_180 :
V_4 -> V_119 = V_133 ;
F_12 ( V_4 -> V_18 , L_38 ) ;
V_4 -> V_51 = 0 ;
V_127 = V_4 -> V_63 + V_4 -> V_170 ;
F_17 ( & V_127 -> V_21 , V_4 , V_127 ) ;
F_26 ( V_4 , V_146 ) ;
break;
case V_181 :
V_4 -> V_119 = V_133 ;
F_12 ( V_4 -> V_18 ,
L_39 ) ;
V_98 = V_4 -> V_170 ;
V_4 -> V_63 [ V_98 ] . V_21 . V_58 |= V_96 ;
V_4 -> V_60 = 1 ;
break;
case V_182 :
V_4 -> V_119 = V_133 ;
V_98 = V_4 -> V_170 ;
if ( V_126 -> V_7 > 0 && V_126 -> V_7 <= 65535 ) {
V_4 -> V_63 [ V_98 ] . V_21 . V_5 = V_126 -> V_7 ;
V_4 -> V_63 [ V_98 ] . V_21 . V_58 |=
V_183 ;
V_4 -> V_60 = 1 ;
break;
}
case V_184 :
V_4 -> V_119 = V_133 ;
V_98 = V_4 -> V_170 ;
if ( F_47 ( V_4 , V_98 ) < 0 ) {
F_12 ( V_4 -> V_18 ,
L_40 ) ;
V_127 = V_4 -> V_63 + V_98 ;
F_17 ( & V_127 -> V_21 , V_4 , V_127 ) ;
}
break;
case V_185 :
V_4 -> V_119 = V_133 ;
V_127 = V_4 -> V_63 + V_4 -> V_170 ;
F_17 ( & V_127 -> V_21 , V_4 , V_127 ) ;
break;
case V_186 :
case V_187 :
V_4 -> V_119 = V_133 ;
break;
case V_188 :
if ( V_63 )
F_17 ( V_21 , V_4 , V_63 ) ;
else
F_14 ( V_122 , V_4 ) ;
break;
case V_189 :
V_4 -> V_119 = V_133 ;
V_21 -> V_58 |= V_96 ;
V_4 -> V_60 = 1 ;
break;
case V_190 :
case V_191 :
case V_192 :
V_21 -> V_58 |= V_96 ;
V_4 -> V_60 = 1 ;
break;
case V_193 :
V_21 -> V_32 = 1 ;
break;
case V_194 :
if ( ! V_126 -> V_6 ) {
* V_124 = 1 ;
* V_125 = V_195 ;
break;
}
V_1 = V_126 -> V_6 ;
if ( ! strcmp ( V_1 , L_41 ) ) {
* V_124 = 1 ;
* V_125 = V_37 ;
break;
}
for ( V_69 = 0 ; V_69 < 4 ; ++ V_69 ) {
V_129 = F_56 ( V_1 , ( char * * ) & V_128 , 10 ) ;
if ( V_129 > V_196 || V_128 == V_1 )
break;
if ( V_69 == 3 ) {
if ( * V_128 )
break;
} else if ( * V_128 != '.' )
break;
else
V_1 = V_128 + 1 ;
V_4 -> V_197 [ V_69 ] = V_129 ;
}
if ( V_69 != 4 ) {
* V_124 = 1 ;
* V_125 = V_195 ;
break;
}
V_4 -> V_198 = 0 ;
break;
case V_199 :
if ( V_4 -> V_198 == 0 ) {
V_4 -> V_198 = 1 ;
F_3 ( V_13 ,
L_42 ,
V_4 -> V_197 [ 0 ] , V_4 -> V_197 [ 1 ] ,
V_4 -> V_197 [ 2 ] , V_4 -> V_197 [ 3 ] ) ;
break;
}
case V_200 :
V_4 -> V_198 = - 1 ;
F_6 ( V_4 -> V_18 , L_43 ) ;
break;
case V_201 :
F_3 ( V_202 , L_44 ,
V_52 , V_21 -> V_153 ) ;
V_4 -> V_119 = V_133 ;
break;
case V_203 :
F_3 ( V_202 , L_45 ,
V_52 , V_126 -> type , V_21 -> V_153 ) ;
break;
case V_204 :
F_12 ( V_4 -> V_18 , L_46 ,
V_52 , V_126 -> type , V_21 -> V_153 ) ;
break;
case V_205 :
F_12 ( V_4 -> V_18 , L_47 ,
V_126 -> V_7 , V_21 -> V_153 ) ;
break;
case V_206 :
if ( ! V_126 -> V_6 ) {
* V_124 = 1 ;
* V_125 = V_195 ;
break;
}
F_38 ( V_21 , V_126 -> V_6 , V_126 -> V_7 ) ;
break;
case V_207 :
F_39 ( V_21 ) ;
break;
case V_208 :
V_21 -> V_58 |= V_96 ;
F_3 ( V_13 , L_24 ) ;
V_4 -> V_60 = 1 ;
break;
case V_209 :
F_46 ( V_4 ) ;
break;
case V_210 :
F_40 ( V_4 ) ;
break;
case V_211 :
V_4 -> V_105 = V_126 -> V_7 ? F_51 ( V_4 ) : F_53 ( V_4 ) ;
V_4 -> V_103 = 0 ;
F_42 ( & V_4 -> V_104 ) ;
break;
case V_212 :
if ( V_126 -> V_7 != 0 )
V_4 -> V_105 = - V_120 ;
else if ( V_4 -> V_198 != 1 ) {
V_4 -> V_105 = - V_213 ;
} else {
memcpy ( V_126 -> V_20 , V_4 -> V_197 , sizeof V_4 -> V_197 ) ;
V_4 -> V_105 = 0 ;
}
V_4 -> V_103 = 0 ;
F_42 ( & V_4 -> V_104 ) ;
break;
case V_214 :
F_4 ( & V_4 -> V_55 , V_8 ) ;
if ( V_126 -> V_7 != V_4 -> V_57 ) {
V_4 -> V_57 = V_126 -> V_7 ;
if ( V_126 -> V_7 ) {
V_4 -> V_21 . V_58 |= V_135 ;
F_3 ( V_13 , L_32 ) ;
} else {
V_4 -> V_21 . V_58 |= V_59 ;
F_3 ( V_13 , L_12 ) ;
}
V_4 -> V_60 = 1 ;
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
V_4 -> V_103 = 0 ;
F_42 ( & V_4 -> V_104 ) ;
break;
case V_215 :
F_31 ( V_63 ) ;
break;
case V_216 :
F_35 ( V_63 ) ;
break;
case V_217 :
F_45 ( V_4 ) ;
break;
default:
if ( V_121 >= V_218 && V_121 < V_218 + V_93 ) {
* V_123 = V_21 -> V_63 -> V_92 [ V_121 - V_218 ] ;
if ( ! * V_123 ) {
* V_124 = 1 ;
* V_125 = V_219 ;
}
} else
F_6 ( V_4 -> V_18 , L_48 , V_52 , V_121 ) ;
}
}
static void F_57 ( struct V_3 * V_4 , struct V_11 * V_126 )
{
struct V_62 * V_63 ;
char * V_220 = NULL ;
struct V_221 * V_222 ;
int V_223 ;
int V_224 = 0 ;
int V_40 = V_195 ;
struct V_53 * V_21 ;
int V_225 ;
int V_226 ;
unsigned long V_8 ;
if ( V_126 -> V_5 >= 0 ) {
V_21 = F_29 ( V_4 , V_126 -> V_5 ) ;
if ( ! V_21 ) {
F_3 ( V_13 , L_49 ,
V_126 -> type , V_126 -> V_5 ) ;
F_58 ( V_4 , & V_4 -> V_21 , V_227 ,
NULL , 0 , NULL ) ;
return;
}
} else {
V_21 = V_126 -> V_21 ;
if ( F_48 ( V_4 , V_21 ) ) {
F_3 ( V_13 , L_50 ,
V_21 ) ;
return;
}
}
F_3 ( V_13 , L_51 ,
V_21 -> V_153 , V_126 -> type ) ;
V_63 = V_21 -> V_63 ;
V_222 = V_21 -> V_228 ;
F_4 ( & V_4 -> V_55 , V_8 ) ;
if ( V_126 -> type == V_229 ) {
if ( V_126 -> V_7 != V_21 -> V_230
|| ! V_21 -> V_160 ) {
V_126 -> type = V_37 ;
F_3 ( V_13 , L_52 ) ;
} else {
if ( V_21 -> V_103 )
F_3 ( V_13 , L_53 ) ;
else
F_3 ( V_13 , L_54 ) ;
}
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
if ( V_126 -> type >= V_231 && V_126 -> type < V_231 + V_232 ) {
V_225 = V_126 -> type - V_231 ;
V_21 -> V_156 [ V_225 ] = V_126 -> V_7 ;
} else if ( V_126 -> type >= V_233 && V_126 -> type < V_233 + V_154 ) {
V_225 = V_126 -> type - V_233 ;
F_7 ( V_21 -> V_155 [ V_225 ] ) ;
V_21 -> V_155 [ V_225 ] = V_126 -> V_6 ;
V_126 -> V_6 = NULL ;
}
if ( V_126 -> type == V_229 || V_126 -> type == V_34 )
V_21 -> V_32 = 0 ;
for (; ; V_222 ++ ) {
V_223 = V_222 -> V_40 ;
if ( V_223 == V_234 ) {
F_12 ( V_4 -> V_18 , L_55
L_56 ,
V_52 , V_126 -> type , V_21 -> V_153 ) ;
return;
}
if ( ( V_223 == V_235 || V_223 == V_126 -> type )
&& ( ( int ) V_21 -> V_153 >= V_222 -> V_236 )
&& ( V_222 -> V_237 < 0
|| ( int ) V_21 -> V_153 <= V_222 -> V_237 )
&& ( V_222 -> V_7 < 0 || V_222 -> V_7 == V_126 -> V_7 ) )
break;
}
V_220 = V_222 -> V_238 ;
V_21 -> V_103 = 0 ;
for ( V_226 = 0 ; V_226 < V_239 ; ++ V_226 ) {
F_54 ( V_222 -> V_121 [ V_226 ] , V_4 , V_63 , & V_21 , & V_220 ,
& V_224 , & V_40 , V_126 ) ;
if ( ! V_21 )
return;
}
if ( V_222 -> V_240 >= 0 )
V_21 -> V_153 = V_222 -> V_240 ;
if ( V_224 ) {
F_4 ( & V_4 -> V_55 , V_8 ) ;
V_21 -> V_158 = 0 ;
V_21 -> V_160 = 0 ;
F_8 ( & V_4 -> V_55 , V_8 ) ;
F_58 ( V_4 , V_21 , V_40 , NULL , 0 , NULL ) ;
} else {
if ( V_220 ) {
if ( V_4 -> V_110 )
F_28 ( V_4 , V_220 , V_21 ) ;
else
F_58 ( V_4 , V_21 , V_241 ,
NULL , 0 , NULL ) ;
}
F_4 ( & V_4 -> V_55 , V_8 ) ;
if ( ! V_222 -> V_242 ) {
V_21 -> V_158 = 0 ;
V_21 -> V_160 = 0 ;
} else if ( V_222 -> V_242 > 0 ) {
V_21 -> V_158 = V_222 -> V_242 * 10 ;
V_21 -> V_160 = 1 ;
++ V_21 -> V_230 ;
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
}
}
static void F_59 ( struct V_3 * V_4 ,
struct V_53 * V_21 , int V_243 )
{
V_4 -> V_119 = V_243 ;
F_58 ( V_4 , V_21 , V_244 , NULL , V_243 , NULL ) ;
}
static void F_60 ( struct V_3 * V_4 )
{
struct V_53 * V_21 = NULL ;
struct V_62 * V_63 ;
int V_69 ;
int V_243 ;
unsigned long V_8 ;
V_4 -> V_60 = 0 ;
if ( V_4 -> V_119 ) {
F_3 ( V_13 , L_57 ) ;
return;
}
F_3 ( V_13 , L_58 ) ;
V_243 = V_133 ;
if ( V_4 -> V_21 . V_58 & V_109 ) {
V_4 -> V_21 . V_58 &= ~ V_135 ;
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 ) {
V_63 = V_4 -> V_63 + V_69 ;
V_21 = & V_63 -> V_21 ;
V_21 -> V_58 &=
~ ( V_167 | V_99 | V_183 ) ;
if ( V_21 -> V_5 > 0 )
V_21 -> V_58 |= V_96 ;
if ( V_21 -> V_58 & V_77 ) {
V_21 -> V_58 |= V_78 ;
V_21 -> V_58 &= ~ V_77 ;
}
}
}
if ( V_4 -> V_21 . V_58 & V_74 ) {
V_4 -> V_21 . V_58 &= ~ V_135 ;
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 ) {
V_63 = V_4 -> V_63 + V_69 ;
V_21 = & V_63 -> V_21 ;
V_21 -> V_58 &=
~ ( V_167 | V_99 | V_183 ) ;
if ( V_21 -> V_5 > 0 )
V_21 -> V_58 |= V_96 ;
if ( V_4 -> V_75 == V_146 ) {
if ( V_21 -> V_58 & V_77 ) {
V_21 -> V_58 |= V_78 ;
V_21 -> V_58 &= ~ V_77 ;
}
}
}
}
F_4 ( & V_4 -> V_55 , V_8 ) ;
if ( V_4 -> V_21 . V_58 == V_59
&& ! V_4 -> V_57
&& F_15 ( & V_4 -> V_72 )
&& V_4 -> V_73 == V_147 ) {
V_243 = V_245 ;
V_21 = & V_4 -> V_21 ;
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 ) {
V_63 = V_4 -> V_63 + V_69 ;
if ( V_63 -> V_21 . V_58 ||
V_63 -> V_21 . V_5 > 0 ) {
V_243 = V_133 ;
break;
}
}
}
F_8 ( & V_4 -> V_55 , V_8 ) ;
V_4 -> V_21 . V_58 &= ~ V_59 ;
if ( V_243 != V_133 ) {
F_59 ( V_4 , V_21 , V_243 ) ;
return;
}
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 ) {
V_63 = V_4 -> V_63 + V_69 ;
if ( V_63 -> V_21 . V_58 & V_96 ) {
if ( V_4 -> V_51 ) {
V_4 -> V_170 = V_63 -> V_98 ;
F_59 ( V_4 , & V_4 -> V_21 , V_246 ) ;
return;
}
V_63 -> V_21 . V_58 &= ~ V_96 ;
if ( V_63 -> V_21 . V_58 & V_77 ) {
V_63 -> V_21 . V_58 |= V_78 ;
V_63 -> V_21 . V_58 &= ~ V_77 ;
} else {
F_59 ( V_4 , & V_63 -> V_21 , V_247 ) ;
return;
}
}
if ( V_63 -> V_21 . V_58 & V_78 ) {
V_63 -> V_21 . V_58 &= ~ V_78 ;
V_4 -> V_170 = V_63 -> V_98 ;
F_59 ( V_4 , & V_4 -> V_21 , V_248 ) ;
return;
} else if ( V_63 -> V_21 . V_58 & V_175 ) {
V_63 -> V_21 . V_58 &= ~ V_175 ;
V_4 -> V_170 = V_63 -> V_98 ;
F_59 ( V_4 , & V_4 -> V_21 , V_246 ) ;
return;
}
}
F_30 (at_state, &cs->temp_at_states, list)
if ( V_21 -> V_58 & V_96 ) {
V_21 -> V_58 &= ~ V_96 ;
F_59 ( V_4 , V_21 , V_247 ) ;
return;
}
if ( V_4 -> V_21 . V_58 & V_74 ) {
V_4 -> V_21 . V_58 &= ~ V_74 ;
V_4 -> V_51 = 0 ;
V_4 -> V_140 -> V_141 = V_142 ;
F_59 ( V_4 , & V_4 -> V_21 , V_249 ) ;
return;
}
if ( V_4 -> V_21 . V_58 & V_109 ) {
V_4 -> V_21 . V_58 &= ~ V_109 ;
F_59 ( V_4 , & V_4 -> V_21 , V_250 ) ;
return;
}
if ( V_4 -> V_21 . V_58 & V_135 ) {
V_4 -> V_21 . V_58 &= ~ V_135 ;
if ( V_4 -> V_73 == V_134 ) {
V_4 -> V_111 = 1 ;
F_59 ( V_4 , & V_4 -> V_21 , V_251 ) ;
return;
}
}
for ( V_69 = 0 ; V_69 < V_4 -> V_71 ; ++ V_69 ) {
V_63 = V_4 -> V_63 + V_69 ;
if ( V_63 -> V_21 . V_58 & V_167 ) {
V_63 -> V_21 . V_58 &= ~ V_167 ;
V_4 -> V_170 = V_63 -> V_98 ;
F_59 ( V_4 , & V_4 -> V_21 , V_252 ) ;
return;
}
if ( V_63 -> V_21 . V_58 & V_99 ) {
V_63 -> V_21 . V_58 &= ~ V_99 ;
F_59 ( V_4 , & V_63 -> V_21 , V_253 ) ;
return;
}
if ( V_63 -> V_21 . V_58 & V_183 ) {
V_63 -> V_21 . V_58 &= ~ V_183 ;
F_59 ( V_4 , & V_63 -> V_21 , V_254 ) ;
return;
}
if ( V_63 -> V_21 . V_58 & V_77 ) {
switch ( V_4 -> V_73 ) {
case V_134 :
V_4 -> V_21 . V_58 |= V_135 ;
F_3 ( V_13 , L_32 ) ;
V_4 -> V_60 = 1 ;
return;
case V_80 :
F_26 ( V_4 , V_101 ) ;
return;
}
V_63 -> V_21 . V_58 &= ~ V_77 ;
V_4 -> V_170 = V_63 -> V_98 ;
V_4 -> V_111 = 2 ;
F_59 ( V_4 , & V_4 -> V_21 , V_255 ) ;
return;
}
}
}
static void F_61 ( struct V_3 * V_4 )
{
struct V_11 * V_126 ;
unsigned V_256 , V_10 ;
int V_69 ;
int V_257 = 0 ;
int V_258 ;
unsigned long V_8 ;
F_4 ( & V_4 -> V_14 , V_8 ) ;
V_256 = V_4 -> V_17 ;
for ( V_69 = 0 ; V_69 < 2 * V_16 ; ++ V_69 ) {
V_10 = V_4 -> V_15 ;
if ( V_10 == V_256 ) {
if ( ! V_257 && ! V_4 -> V_60 )
break;
V_257 = 0 ;
F_8 ( & V_4 -> V_14 , V_8 ) ;
F_60 ( V_4 ) ;
F_4 ( & V_4 -> V_14 , V_8 ) ;
V_10 = V_4 -> V_15 ;
if ( V_10 == V_256 ) {
if ( ! V_4 -> V_60 )
break;
continue;
}
}
V_126 = V_4 -> V_19 + V_256 ;
V_258 = V_4 -> V_119 != V_133 ;
F_8 ( & V_4 -> V_14 , V_8 ) ;
F_57 ( V_4 , V_126 ) ;
F_4 ( & V_4 -> V_14 , V_8 ) ;
F_7 ( V_126 -> V_6 ) ;
V_126 -> V_6 = NULL ;
if ( V_258 && V_4 -> V_119 == V_133 )
V_257 = 1 ;
V_256 = ( V_256 + 1 ) % V_16 ;
V_4 -> V_17 = V_256 ;
}
F_8 ( & V_4 -> V_14 , V_8 ) ;
if ( V_69 == 2 * V_16 ) {
F_6 ( V_4 -> V_18 ,
L_59 ) ;
}
}
void F_62 ( unsigned long V_91 )
{
struct V_3 * V_4 = (struct V_3 * ) V_91 ;
if ( V_4 -> V_140 -> V_256 != V_4 -> V_140 -> V_10 ) {
F_3 ( V_259 , L_60 ) ;
V_4 -> V_64 -> V_260 ( V_4 -> V_140 ) ;
}
F_61 ( V_4 ) ;
}
