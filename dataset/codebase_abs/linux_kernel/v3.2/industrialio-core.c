int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 = 0 ;
F_2 ( & V_6 -> V_11 ) ;
if ( F_3 ( V_12 , & V_6 -> V_13 ) ) {
if ( V_6 -> V_14 == V_6 -> V_15 ) {
F_4 ( & V_6 -> V_11 ) ;
return 0 ;
}
V_9 = F_5 ( sizeof( * V_9 ) , V_16 ) ;
if ( V_9 == NULL ) {
V_10 = - V_17 ;
F_4 ( & V_6 -> V_11 ) ;
goto V_18;
}
V_9 -> V_9 . V_19 = V_3 ;
V_9 -> V_9 . V_4 = V_4 ;
F_6 ( & V_9 -> V_20 , & V_6 -> V_21 ) ;
V_6 -> V_14 ++ ;
F_4 ( & V_6 -> V_11 ) ;
F_7 ( & V_6 -> V_22 ) ;
} else
F_4 ( & V_6 -> V_11 ) ;
V_18:
return V_10 ;
}
T_3 F_8 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
char * V_27 )
{
return sprintf ( V_27 , L_1 , F_9 ( V_26 ) -> string ) ;
}
static T_3 F_10 ( struct V_28 * V_29 ,
char T_4 * V_27 ,
T_5 V_30 ,
T_6 * V_31 )
{
struct V_5 * V_6 = V_29 -> V_32 ;
struct V_8 * V_33 ;
int V_10 ;
T_5 V_34 ;
F_2 ( & V_6 -> V_11 ) ;
if ( F_11 ( & V_6 -> V_21 ) ) {
if ( V_29 -> V_35 & V_36 ) {
V_10 = - V_37 ;
goto V_38;
}
F_4 ( & V_6 -> V_11 ) ;
V_10 = F_12 ( V_6 -> V_22 ,
! F_11 ( & V_6
-> V_21 ) ) ;
if ( V_10 )
goto V_18;
F_2 ( & V_6 -> V_11 ) ;
}
V_33 = F_13 ( & V_6 -> V_21 ,
struct V_8 ,
V_20 ) ;
V_34 = sizeof V_33 -> V_9 ;
if ( F_14 ( V_27 , & ( V_33 -> V_9 ) , V_34 ) ) {
V_10 = - V_39 ;
goto V_38;
}
F_15 ( & V_33 -> V_20 ) ;
V_6 -> V_14 -- ;
F_4 ( & V_6 -> V_11 ) ;
F_16 ( V_33 ) ;
return V_34 ;
V_38:
F_4 ( & V_6 -> V_11 ) ;
V_18:
return V_10 ;
}
static int F_17 ( struct V_40 * V_40 , struct V_28 * V_29 )
{
struct V_5 * V_6 = V_29 -> V_32 ;
struct V_8 * V_33 , * V_41 ;
F_2 ( & V_6 -> V_11 ) ;
F_18 ( V_12 , & V_6 -> V_13 ) ;
F_19 (el, t, &ev_int->det_events, list) {
F_15 ( & V_33 -> V_20 ) ;
F_16 ( V_33 ) ;
}
V_6 -> V_14 = 0 ;
F_4 ( & V_6 -> V_11 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_42 ;
if ( V_6 == NULL )
return - V_43 ;
F_2 ( & V_6 -> V_11 ) ;
if ( F_21 ( V_12 , & V_6 -> V_13 ) ) {
F_4 ( & V_6 -> V_11 ) ;
return - V_44 ;
}
F_4 ( & V_6 -> V_11 ) ;
V_42 = F_22 ( L_2 ,
& V_45 , V_6 , V_46 ) ;
if ( V_42 < 0 ) {
F_2 ( & V_6 -> V_11 ) ;
F_18 ( V_12 , & V_6 -> V_13 ) ;
F_4 ( & V_6 -> V_11 ) ;
}
return V_42 ;
}
static int T_7 F_23 ( void )
{
int V_10 ;
V_10 = F_24 ( & V_47 ) ;
if ( V_10 < 0 ) {
F_25 ( V_48
L_3 ,
__FILE__ ) ;
goto V_49;
}
V_10 = F_26 ( & V_50 , 0 , V_51 , L_4 ) ;
if ( V_10 < 0 ) {
F_25 ( V_48 L_5 ,
__FILE__ ) ;
goto V_52;
}
return 0 ;
V_52:
F_27 ( & V_47 ) ;
V_49:
return V_10 ;
}
static void T_8 F_28 ( void )
{
if ( V_50 )
F_29 ( V_50 , V_51 ) ;
F_27 ( & V_47 ) ;
}
static T_3 F_30 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
char * V_27 )
{
struct V_1 * V_2 = F_31 ( V_24 ) ;
struct V_53 * V_54 = F_32 ( V_26 ) ;
int V_55 , V_56 ;
int V_10 = V_2 -> V_57 -> V_58 ( V_2 , V_54 -> V_59 ,
& V_55 , & V_56 , V_54 -> V_60 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 == V_61 )
return sprintf ( V_27 , L_6 , V_55 ) ;
else if ( V_10 == V_62 ) {
if ( V_56 < 0 )
return sprintf ( V_27 , L_7 , V_55 , - V_56 ) ;
else
return sprintf ( V_27 , L_8 , V_55 , V_56 ) ;
} else if ( V_10 == V_63 ) {
if ( V_56 < 0 )
return sprintf ( V_27 , L_9 , V_55 , - V_56 ) ;
else
return sprintf ( V_27 , L_10 , V_55 , V_56 ) ;
} else
return 0 ;
}
static T_3 F_33 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
const char * V_27 ,
T_5 V_34 )
{
struct V_1 * V_2 = F_31 ( V_24 ) ;
struct V_53 * V_54 = F_32 ( V_26 ) ;
int V_10 , integer = 0 , V_64 = 0 , V_65 = 100000 ;
bool V_66 = true , V_67 = false ;
if ( ! V_2 -> V_57 -> V_68 )
return - V_69 ;
if ( V_2 -> V_57 -> V_70 )
switch ( V_2 -> V_57 -> V_70 ( V_2 ,
V_54 -> V_59 , V_54 -> V_60 ) ) {
case V_62 :
V_65 = 100000 ;
break;
case V_63 :
V_65 = 100000000 ;
break;
default:
return - V_69 ;
}
if ( V_27 [ 0 ] == '-' ) {
V_67 = true ;
V_27 ++ ;
}
while ( * V_27 ) {
if ( '0' <= * V_27 && * V_27 <= '9' ) {
if ( V_66 )
integer = integer * 10 + * V_27 - '0' ;
else {
V_64 += V_65 * ( * V_27 - '0' ) ;
if ( V_65 == 1 )
break;
V_65 /= 10 ;
}
} else if ( * V_27 == '\n' ) {
if ( * ( V_27 + 1 ) == '\0' )
break;
else
return - V_69 ;
} else if ( * V_27 == '.' ) {
V_66 = false ;
} else {
return - V_69 ;
}
V_27 ++ ;
}
if ( V_67 ) {
if ( integer )
integer = - integer ;
else
V_64 = - V_64 ;
}
V_10 = V_2 -> V_57 -> V_68 ( V_2 , V_54 -> V_59 ,
integer , V_64 , V_54 -> V_60 ) ;
if ( V_10 )
return V_10 ;
return V_34 ;
}
static
int F_34 ( struct V_25 * V_71 ,
const char * V_72 ,
struct V_73 const * V_74 ,
T_3 (* F_35)( struct V_23 * V_24 ,
struct V_25 * V_26 ,
char * V_27 ) ,
T_3 (* F_36)( struct V_23 * V_24 ,
struct V_25 * V_26 ,
const char * V_27 ,
T_5 V_34 ) ,
bool V_75 )
{
int V_10 ;
char * V_76 , * V_77 ;
F_37 ( & V_71 -> V_26 ) ;
if ( V_74 -> V_78 ) {
if ( V_74 -> V_79 )
V_77 = F_38 ( V_16 , L_11 ,
V_80 [ V_74
-> V_81 ] ,
V_74 -> V_79 ,
V_72 ) ;
else
V_77 = F_38 ( V_16 , L_12 ,
V_80 [ V_74
-> V_81 ] ,
V_72 ) ;
} else {
if ( V_74 -> V_79 == NULL )
V_77 = F_39 ( V_72 , V_16 ) ;
else
V_77 = F_38 ( V_16 ,
L_12 ,
V_74 -> V_79 ,
V_72 ) ;
}
if ( V_77 == NULL ) {
V_10 = - V_17 ;
goto V_18;
}
if ( V_74 -> V_82 ) {
if ( V_75 )
V_76
= F_38 ( V_16 , L_13 ,
V_83 [ V_74 -> V_84 ] ,
V_85 [ V_74 -> type ] ,
V_85 [ V_74 -> type ] ,
V_77 ) ;
else if ( V_74 -> V_86 )
V_76
= F_38 ( V_16 , L_14 ,
V_83 [ V_74 -> V_84 ] ,
V_85 [ V_74 -> type ] ,
V_74 -> V_87 ,
V_85 [ V_74 -> type ] ,
V_74 -> V_81 ,
V_77 ) ;
else {
F_40 ( L_15 ) ;
V_10 = - V_69 ;
goto V_88;
}
} else {
if ( V_75 )
V_76
= F_38 ( V_16 , L_11 ,
V_83 [ V_74 -> V_84 ] ,
V_85 [ V_74 -> type ] ,
V_77 ) ;
else if ( V_74 -> V_86 )
V_76
= F_38 ( V_16 , L_16 ,
V_83 [ V_74 -> V_84 ] ,
V_85 [ V_74 -> type ] ,
V_74 -> V_87 ,
V_77 ) ;
else
V_76
= F_38 ( V_16 , L_11 ,
V_83 [ V_74 -> V_84 ] ,
V_85 [ V_74 -> type ] ,
V_77 ) ;
}
if ( V_76 == NULL ) {
V_10 = - V_17 ;
goto V_88;
}
V_71 -> V_26 . V_89 = F_38 ( V_16 ,
V_76 ,
V_74 -> V_87 ,
V_74 -> V_81 ) ;
if ( V_71 -> V_26 . V_89 == NULL ) {
V_10 = - V_17 ;
goto V_90;
}
if ( F_35 ) {
V_71 -> V_26 . V_91 |= V_92 ;
V_71 -> V_93 = F_35 ;
}
if ( F_36 ) {
V_71 -> V_26 . V_91 |= V_94 ;
V_71 -> V_95 = F_36 ;
}
F_16 ( V_76 ) ;
F_16 ( V_77 ) ;
return 0 ;
V_90:
F_16 ( V_76 ) ;
V_88:
F_16 ( V_77 ) ;
V_18:
return V_10 ;
}
static void F_41 ( struct V_25 * V_71 )
{
F_16 ( V_71 -> V_26 . V_89 ) ;
}
int F_42 ( const char * V_72 ,
struct V_73 const * V_74 ,
T_3 (* F_35)( struct V_23 * V_24 ,
struct V_25 * V_26 ,
char * V_27 ) ,
T_3 (* F_36)( struct V_23 * V_24 ,
struct V_25 * V_26 ,
const char * V_27 ,
T_5 V_34 ) ,
T_1 V_96 ,
bool V_75 ,
struct V_23 * V_24 ,
struct V_97 * V_98 )
{
int V_10 ;
struct V_53 * V_99 , * V_41 ;
V_99 = F_43 ( sizeof *V_99 , V_16 ) ;
if ( V_99 == NULL ) {
V_10 = - V_17 ;
goto V_18;
}
V_10 = F_34 ( & V_99 -> V_71 ,
V_72 , V_74 ,
F_35 , F_36 , V_75 ) ;
if ( V_10 )
goto V_100;
V_99 -> V_59 = V_74 ;
V_99 -> V_60 = V_96 ;
F_44 (t, attr_list, l)
if ( strcmp ( V_41 -> V_71 . V_26 . V_89 ,
V_99 -> V_71 . V_26 . V_89 ) == 0 ) {
if ( ! V_75 )
F_45 ( V_24 , L_17 ,
V_41 -> V_71 . V_26 . V_89 ) ;
V_10 = - V_44 ;
goto V_101;
}
F_46 ( & V_99 -> V_102 , V_98 ) ;
return 0 ;
V_101:
F_41 ( & V_99 -> V_71 ) ;
V_100:
F_16 ( V_99 ) ;
V_18:
return V_10 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_73 const * V_74 )
{
int V_10 , V_103 , V_104 = 0 ;
if ( V_74 -> V_87 < 0 )
return 0 ;
V_10 = F_42 ( V_105 [ V_74 -> V_106 ] ,
V_74 ,
& F_30 ,
( V_74 -> V_84 ?
& F_33 : NULL ) ,
0 ,
0 ,
& V_2 -> V_24 ,
& V_2 -> V_107 ) ;
if ( V_10 )
goto V_18;
V_104 ++ ;
F_48 (i, &chan->info_mask, sizeof(long)*8 ) {
V_10 = F_42 ( V_108 [ V_103 / 2 ] ,
V_74 ,
& F_30 ,
& F_33 ,
( 1 << V_103 ) ,
! ( V_103 % 2 ) ,
& V_2 -> V_24 ,
& V_2 -> V_107 ) ;
if ( V_10 == - V_44 && ( V_103 % 2 == 0 ) ) {
V_10 = 0 ;
continue;
}
if ( V_10 < 0 )
goto V_18;
V_104 ++ ;
}
V_10 = V_104 ;
V_18:
return V_10 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_53 * V_109 )
{
F_16 ( V_109 -> V_71 . V_26 . V_89 ) ;
F_16 ( V_109 ) ;
}
static T_3 F_50 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
char * V_27 )
{
struct V_1 * V_2 = F_31 ( V_24 ) ;
return sprintf ( V_27 , L_1 , V_2 -> V_89 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_103 , V_10 = 0 , V_104 , V_110 , V_111 = 0 ;
struct V_53 * V_109 , * V_112 ;
struct V_113 * * V_26 ;
if ( V_2 -> V_57 -> V_114 ) {
V_26 = V_2 -> V_57 -> V_114 -> V_114 ;
while ( * V_26 ++ != NULL )
V_111 ++ ;
}
V_104 = V_111 ;
F_52 ( & V_2 -> V_107 ) ;
if ( V_2 -> V_115 )
for ( V_103 = 0 ; V_103 < V_2 -> V_116 ; V_103 ++ ) {
V_10 = F_47 ( V_2 ,
& V_2
-> V_115 [ V_103 ] ) ;
if ( V_10 < 0 )
goto V_117;
V_104 += V_10 ;
}
if ( V_2 -> V_89 )
V_104 ++ ;
V_2 -> V_118 . V_114
= F_43 ( sizeof( V_2 -> V_118 . V_114 [ 0 ] ) *
( V_104 + 1 ) ,
V_16 ) ;
if ( V_2 -> V_118 . V_114 == NULL ) {
V_10 = - V_17 ;
goto V_117;
}
if ( V_2 -> V_57 -> V_114 )
memcpy ( V_2 -> V_118 . V_114 ,
V_2 -> V_57 -> V_114 -> V_114 ,
sizeof( V_2 -> V_118 . V_114 [ 0 ] )
* V_111 ) ;
V_110 = V_111 ;
F_44 (p, &indio_dev->channel_attr_list, l)
V_2 -> V_118 . V_114 [ V_110 ++ ] = & V_109 -> V_71 . V_26 ;
if ( V_2 -> V_89 )
V_2 -> V_118 . V_114 [ V_110 ++ ] = & V_119 . V_26 ;
V_2 -> V_120 [ V_2 -> V_121 ++ ] =
& V_2 -> V_118 ;
return 0 ;
V_117:
F_19 (p, n,
&indio_dev->channel_attr_list, l) {
F_15 ( & V_109 -> V_102 ) ;
F_49 ( V_2 , V_109 ) ;
}
return V_10 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_53 * V_109 , * V_112 ;
F_19 (p, n, &indio_dev->channel_attr_list, l) {
F_15 ( & V_109 -> V_102 ) ;
F_49 ( V_2 , V_109 ) ;
}
F_16 ( V_2 -> V_118 . V_114 ) ;
}
static T_3 F_54 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
const char * V_27 ,
T_5 V_34 )
{
struct V_1 * V_2 = F_31 ( V_24 ) ;
struct V_53 * V_54 = F_32 ( V_26 ) ;
int V_10 ;
bool V_55 ;
V_10 = F_55 ( V_27 , & V_55 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = V_2 -> V_57 -> V_122 ( V_2 ,
V_54 -> V_60 ,
V_55 ) ;
return ( V_10 < 0 ) ? V_10 : V_34 ;
}
static T_3 F_56 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
char * V_27 )
{
struct V_1 * V_2 = F_31 ( V_24 ) ;
struct V_53 * V_54 = F_32 ( V_26 ) ;
int V_55 = V_2 -> V_57 -> V_123 ( V_2 ,
V_54 -> V_60 ) ;
if ( V_55 < 0 )
return V_55 ;
else
return sprintf ( V_27 , L_6 , V_55 ) ;
}
static T_3 F_57 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
char * V_27 )
{
struct V_1 * V_2 = F_31 ( V_24 ) ;
struct V_53 * V_54 = F_32 ( V_26 ) ;
int V_55 , V_10 ;
V_10 = V_2 -> V_57 -> V_124 ( V_2 ,
V_54 -> V_60 , & V_55 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_27 , L_6 , V_55 ) ;
}
static T_3 F_58 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
const char * V_27 ,
T_5 V_34 )
{
struct V_1 * V_2 = F_31 ( V_24 ) ;
struct V_53 * V_54 = F_32 ( V_26 ) ;
unsigned long V_55 ;
int V_10 ;
V_10 = F_59 ( V_27 , 10 , & V_55 ) ;
if ( V_10 )
return V_10 ;
V_10 = V_2 -> V_57 -> V_125 ( V_2 , V_54 -> V_60 ,
V_55 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_34 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_73 const * V_74 )
{
int V_10 = 0 , V_103 , V_104 = 0 ;
T_1 V_96 = 0 ;
char * V_72 ;
if ( ! V_74 -> V_126 )
return 0 ;
F_48 (i, &chan->event_mask, sizeof(chan->event_mask)*8 ) {
V_72 = F_38 ( V_16 , L_18 ,
V_127 [ V_103 / V_128 ] ,
V_129 [ V_103 % V_128 ] ) ;
if ( V_72 == NULL ) {
V_10 = - V_17 ;
goto V_18;
}
if ( V_74 -> V_78 )
V_96 = F_61 ( V_74 -> type , 0 , V_74 -> V_87 ,
V_103 / V_128 ,
V_103 % V_128 ) ;
else if ( V_74 -> V_82 )
V_96 = F_62 ( V_74 -> type ,
0 , 0 ,
V_103 % V_128 ,
V_103 / V_128 ,
0 ,
V_74 -> V_87 ,
V_74 -> V_81 ) ;
else
V_96 = F_63 ( V_74 -> type ,
V_74 -> V_87 ,
V_103 / V_128 ,
V_103 % V_128 ) ;
V_10 = F_42 ( V_72 ,
V_74 ,
& F_56 ,
F_54 ,
V_96 ,
0 ,
& V_2 -> V_24 ,
& V_2 -> V_7 ->
V_130 ) ;
F_16 ( V_72 ) ;
if ( V_10 )
goto V_18;
V_104 ++ ;
V_72 = F_38 ( V_16 , L_19 ,
V_127 [ V_103 / V_128 ] ,
V_129 [ V_103 % V_128 ] ) ;
if ( V_72 == NULL ) {
V_10 = - V_17 ;
goto V_18;
}
V_10 = F_42 ( V_72 , V_74 ,
F_57 ,
F_58 ,
V_96 ,
0 ,
& V_2 -> V_24 ,
& V_2 -> V_7 ->
V_130 ) ;
F_16 ( V_72 ) ;
if ( V_10 )
goto V_18;
V_104 ++ ;
}
V_10 = V_104 ;
V_18:
return V_10 ;
}
static inline void F_64 ( struct V_1 * V_2 )
{
struct V_53 * V_109 , * V_112 ;
F_19 (p, n,
&indio_dev->event_interface->
dev_attr_list, l) {
F_16 ( V_109 -> V_71 . V_26 . V_89 ) ;
F_16 ( V_109 ) ;
}
}
static inline int F_65 ( struct V_1 * V_2 )
{
int V_131 , V_10 , V_104 = 0 ;
F_52 ( & V_2 -> V_7 -> V_130 ) ;
for ( V_131 = 0 ; V_131 < V_2 -> V_116 ; V_131 ++ ) {
V_10 = F_60 ( V_2 ,
& V_2 -> V_115 [ V_131 ] ) ;
if ( V_10 < 0 )
goto V_117;
V_104 += V_10 ;
}
return V_104 ;
V_117:
F_64 ( V_2 ) ;
return V_10 ;
}
static bool F_66 ( struct V_1 * V_2 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_2 -> V_116 ; V_131 ++ )
if ( V_2 -> V_115 [ V_131 ] . V_126 != 0 )
return true ;
return false ;
}
static void F_67 ( struct V_5 * V_6 )
{
F_68 ( & V_6 -> V_11 ) ;
V_6 -> V_15 = 10 ;
V_6 -> V_14 = 0 ;
F_52 ( & V_6 -> V_21 ) ;
F_69 ( & V_6 -> V_22 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_53 * V_109 ;
int V_10 = 0 , V_111 = 0 , V_104 , V_110 ;
struct V_113 * * V_26 ;
if ( ! ( V_2 -> V_57 -> V_132 ||
F_66 ( V_2 ) ) )
return 0 ;
V_2 -> V_7 =
F_43 ( sizeof( struct V_5 ) , V_16 ) ;
if ( V_2 -> V_7 == NULL ) {
V_10 = - V_17 ;
goto V_18;
}
F_67 ( V_2 -> V_7 ) ;
if ( V_2 -> V_57 -> V_132 != NULL ) {
V_26 = V_2 -> V_57 -> V_132 -> V_114 ;
while ( * V_26 ++ != NULL )
V_111 ++ ;
}
V_104 = V_111 ;
if ( V_2 -> V_115 ) {
V_10 = F_65 ( V_2 ) ;
if ( V_10 < 0 )
goto V_133;
V_104 += V_10 ;
}
V_2 -> V_7 -> V_134 . V_89 = V_135 ;
V_2 -> V_7 -> V_134 . V_114 =
F_43 ( sizeof( V_2 -> V_7 -> V_134 . V_114 [ 0 ] )
* ( V_104 + 1 ) ,
V_16 ) ;
if ( V_2 -> V_7 -> V_134 . V_114 == NULL ) {
V_10 = - V_17 ;
goto V_133;
}
if ( V_2 -> V_57 -> V_132 )
memcpy ( V_2 -> V_7 -> V_134 . V_114 ,
V_2 -> V_57 -> V_132 -> V_114 ,
sizeof( V_2 -> V_7 -> V_134 . V_114 [ 0 ] )
* V_111 ) ;
V_110 = V_111 ;
F_44 (p,
&indio_dev->event_interface->dev_attr_list,
l)
V_2 -> V_7 -> V_134 . V_114 [ V_110 ++ ] =
& V_109 -> V_71 . V_26 ;
V_2 -> V_120 [ V_2 -> V_121 ++ ] =
& V_2 -> V_7 -> V_134 ;
return 0 ;
V_133:
F_64 ( V_2 ) ;
F_16 ( V_2 -> V_7 ) ;
V_18:
return V_10 ;
}
static void F_71 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == NULL )
return;
F_64 ( V_2 ) ;
F_16 ( V_2 -> V_7 -> V_134 . V_114 ) ;
F_16 ( V_2 -> V_7 ) ;
}
static void F_72 ( struct V_23 * V_23 )
{
struct V_1 * V_2 = F_73 ( V_23 , struct V_1 , V_24 ) ;
F_74 ( & V_2 -> V_136 ) ;
if ( V_2 -> V_137 & V_138 )
F_75 ( V_2 ) ;
F_71 ( V_2 ) ;
F_53 ( V_2 ) ;
}
struct V_1 * F_76 ( int V_139 )
{
struct V_1 * V_24 ;
T_5 V_140 ;
V_140 = sizeof( struct V_1 ) ;
if ( V_139 ) {
V_140 = F_77 ( V_140 , V_141 ) ;
V_140 += V_139 ;
}
V_140 += V_141 - 1 ;
V_24 = F_43 ( V_140 , V_16 ) ;
if ( V_24 ) {
V_24 -> V_24 . V_120 = V_24 -> V_120 ;
V_24 -> V_24 . type = & V_142 ;
V_24 -> V_24 . V_143 = & V_47 ;
F_78 ( & V_24 -> V_24 ) ;
F_79 ( & V_24 -> V_24 , ( void * ) V_24 ) ;
F_68 ( & V_24 -> V_144 ) ;
V_24 -> V_19 = F_80 ( & V_145 , 0 , 0 , V_16 ) ;
if ( V_24 -> V_19 < 0 ) {
F_25 ( V_48 L_20 ) ;
F_16 ( V_24 ) ;
return NULL ;
}
F_81 ( & V_24 -> V_24 , L_21 , V_24 -> V_19 ) ;
}
return V_24 ;
}
void F_82 ( struct V_1 * V_24 )
{
if ( V_24 ) {
F_83 ( & V_145 , V_24 -> V_19 ) ;
F_16 ( V_24 ) ;
}
}
static int F_84 ( struct V_40 * V_40 , struct V_28 * V_146 )
{
struct V_1 * V_2 = F_73 ( V_40 -> V_147 ,
struct V_1 , V_136 ) ;
V_146 -> V_32 = V_2 ;
return F_85 ( V_2 ) ;
}
static int F_86 ( struct V_40 * V_40 , struct V_28 * V_146 )
{
F_87 ( F_73 ( V_40 -> V_147 ,
struct V_1 , V_136 ) ) ;
return 0 ;
}
static long F_88 ( struct V_28 * V_146 , unsigned int V_148 , unsigned long V_149 )
{
struct V_1 * V_2 = V_146 -> V_32 ;
int T_4 * V_150 = ( int T_4 * ) V_149 ;
int V_42 ;
if ( V_148 == V_151 ) {
V_42 = F_20 ( V_2 ) ;
if ( F_14 ( V_150 , & V_42 , sizeof( V_42 ) ) )
return - V_39 ;
return 0 ;
}
return - V_69 ;
}
int F_89 ( struct V_1 * V_2 )
{
int V_10 ;
V_2 -> V_24 . V_152 = F_90 ( F_91 ( V_50 ) , V_2 -> V_19 ) ;
V_10 = F_51 ( V_2 ) ;
if ( V_10 ) {
F_45 ( V_2 -> V_24 . V_153 ,
L_22 ) ;
goto V_18;
}
V_10 = F_70 ( V_2 ) ;
if ( V_10 ) {
F_45 ( V_2 -> V_24 . V_153 ,
L_23 ) ;
goto V_154;
}
if ( V_2 -> V_137 & V_138 )
F_92 ( V_2 ) ;
V_10 = F_93 ( & V_2 -> V_24 ) ;
if ( V_10 < 0 )
goto V_155;
F_94 ( & V_2 -> V_136 , & V_156 ) ;
V_2 -> V_136 . V_157 = V_2 -> V_57 -> V_158 ;
V_10 = F_95 ( & V_2 -> V_136 , V_2 -> V_24 . V_152 , 1 ) ;
if ( V_10 < 0 )
goto V_159;
return 0 ;
V_159:
F_96 ( & V_2 -> V_24 ) ;
V_155:
F_71 ( V_2 ) ;
V_154:
F_53 ( V_2 ) ;
V_18:
return V_10 ;
}
void F_97 ( struct V_1 * V_2 )
{
F_98 ( & V_2 -> V_24 ) ;
}
