const struct V_1
* F_1 ( struct V_2 * V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ )
if ( V_3 -> V_7 [ V_5 ] . V_8 == V_4 )
return & V_3 -> V_7 [ V_5 ] ;
return NULL ;
}
int F_2 ( struct V_2 * V_3 , T_1 V_9 , T_2 V_10 )
{
struct V_11 * V_12 = V_3 -> V_13 ;
struct V_14 * V_15 ;
int V_16 = 0 ;
F_3 ( & V_12 -> V_17 ) ;
if ( F_4 ( V_18 , & V_12 -> V_19 ) ) {
if ( V_12 -> V_20 == V_12 -> V_21 ) {
F_5 ( & V_12 -> V_17 ) ;
return 0 ;
}
V_15 = F_6 ( sizeof( * V_15 ) , V_22 ) ;
if ( V_15 == NULL ) {
V_16 = - V_23 ;
F_5 ( & V_12 -> V_17 ) ;
goto V_24;
}
V_15 -> V_15 . V_25 = V_9 ;
V_15 -> V_15 . V_10 = V_10 ;
F_7 ( & V_15 -> V_26 , & V_12 -> V_27 ) ;
V_12 -> V_20 ++ ;
F_5 ( & V_12 -> V_17 ) ;
F_8 ( & V_12 -> V_28 ) ;
} else
F_5 ( & V_12 -> V_17 ) ;
V_24:
return V_16 ;
}
T_3 F_9 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
return sprintf ( V_33 , L_1 , F_10 ( V_32 ) -> string ) ;
}
static T_3 F_11 ( struct V_34 * V_35 ,
char T_4 * V_33 ,
T_5 V_36 ,
T_6 * V_37 )
{
struct V_11 * V_12 = V_35 -> V_38 ;
struct V_14 * V_39 ;
T_5 V_40 = sizeof( V_39 -> V_15 ) ;
int V_16 ;
if ( V_36 < V_40 )
return - V_41 ;
F_3 ( & V_12 -> V_17 ) ;
if ( F_12 ( & V_12 -> V_27 ) ) {
if ( V_35 -> V_42 & V_43 ) {
V_16 = - V_44 ;
goto V_45;
}
F_5 ( & V_12 -> V_17 ) ;
V_16 = F_13 ( V_12 -> V_28 ,
! F_12 ( & V_12
-> V_27 ) ) ;
if ( V_16 )
goto V_24;
F_3 ( & V_12 -> V_17 ) ;
}
V_39 = F_14 ( & V_12 -> V_27 ,
struct V_14 ,
V_26 ) ;
if ( F_15 ( V_33 , & ( V_39 -> V_15 ) , V_40 ) ) {
V_16 = - V_46 ;
goto V_45;
}
F_16 ( & V_39 -> V_26 ) ;
V_12 -> V_20 -- ;
F_5 ( & V_12 -> V_17 ) ;
F_17 ( V_39 ) ;
return V_40 ;
V_45:
F_5 ( & V_12 -> V_17 ) ;
V_24:
return V_16 ;
}
static int F_18 ( struct V_47 * V_47 , struct V_34 * V_35 )
{
struct V_11 * V_12 = V_35 -> V_38 ;
struct V_14 * V_39 , * V_48 ;
F_3 ( & V_12 -> V_17 ) ;
F_19 ( V_18 , & V_12 -> V_19 ) ;
F_20 (el, t, &ev_int->det_events, list) {
F_16 ( & V_39 -> V_26 ) ;
F_17 ( V_39 ) ;
}
V_12 -> V_20 = 0 ;
F_5 ( & V_12 -> V_17 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_13 ;
int V_49 ;
if ( V_12 == NULL )
return - V_50 ;
F_3 ( & V_12 -> V_17 ) ;
if ( F_22 ( V_18 , & V_12 -> V_19 ) ) {
F_5 ( & V_12 -> V_17 ) ;
return - V_51 ;
}
F_5 ( & V_12 -> V_17 ) ;
V_49 = F_23 ( L_2 ,
& V_52 , V_12 , V_53 ) ;
if ( V_49 < 0 ) {
F_3 ( & V_12 -> V_17 ) ;
F_19 ( V_18 , & V_12 -> V_19 ) ;
F_5 ( & V_12 -> V_17 ) ;
}
return V_49 ;
}
static int T_7 F_24 ( void )
{
int V_16 ;
V_16 = F_25 ( & V_54 ) ;
if ( V_16 < 0 ) {
F_26 ( V_55
L_3 ,
__FILE__ ) ;
goto V_56;
}
V_16 = F_27 ( & V_57 , 0 , V_58 , L_4 ) ;
if ( V_16 < 0 ) {
F_26 ( V_55 L_5 ,
__FILE__ ) ;
goto V_59;
}
return 0 ;
V_59:
F_28 ( & V_54 ) ;
V_56:
return V_16 ;
}
static void T_8 F_29 ( void )
{
if ( V_57 )
F_30 ( V_57 , V_58 ) ;
F_28 ( & V_54 ) ;
}
static T_3 F_31 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_2 * V_3 = F_32 ( V_30 ) ;
struct V_60 * V_61 = F_33 ( V_32 ) ;
int V_62 , V_63 ;
int V_16 = V_3 -> V_64 -> V_65 ( V_3 , V_61 -> V_66 ,
& V_62 , & V_63 , V_61 -> V_67 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_16 == V_68 )
return sprintf ( V_33 , L_6 , V_62 ) ;
else if ( V_16 == V_69 ) {
if ( V_63 < 0 )
return sprintf ( V_33 , L_7 , V_62 , - V_63 ) ;
else
return sprintf ( V_33 , L_8 , V_62 , V_63 ) ;
} else if ( V_16 == V_70 ) {
if ( V_63 < 0 )
return sprintf ( V_33 , L_9 , V_62 , - V_63 ) ;
else
return sprintf ( V_33 , L_10 , V_62 , V_63 ) ;
} else
return 0 ;
}
static T_3 F_34 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_5 V_40 )
{
struct V_2 * V_3 = F_32 ( V_30 ) ;
struct V_60 * V_61 = F_33 ( V_32 ) ;
int V_16 , integer = 0 , V_71 = 0 , V_72 = 100000 ;
bool V_73 = true , V_74 = false ;
if ( ! V_3 -> V_64 -> V_75 )
return - V_41 ;
if ( V_3 -> V_64 -> V_76 )
switch ( V_3 -> V_64 -> V_76 ( V_3 ,
V_61 -> V_66 , V_61 -> V_67 ) ) {
case V_69 :
V_72 = 100000 ;
break;
case V_70 :
V_72 = 100000000 ;
break;
default:
return - V_41 ;
}
if ( V_33 [ 0 ] == '-' ) {
V_74 = true ;
V_33 ++ ;
}
while ( * V_33 ) {
if ( '0' <= * V_33 && * V_33 <= '9' ) {
if ( V_73 )
integer = integer * 10 + * V_33 - '0' ;
else {
V_71 += V_72 * ( * V_33 - '0' ) ;
if ( V_72 == 1 )
break;
V_72 /= 10 ;
}
} else if ( * V_33 == '\n' ) {
if ( * ( V_33 + 1 ) == '\0' )
break;
else
return - V_41 ;
} else if ( * V_33 == '.' ) {
V_73 = false ;
} else {
return - V_41 ;
}
V_33 ++ ;
}
if ( V_74 ) {
if ( integer )
integer = - integer ;
else
V_71 = - V_71 ;
}
V_16 = V_3 -> V_64 -> V_75 ( V_3 , V_61 -> V_66 ,
integer , V_71 , V_61 -> V_67 ) ;
if ( V_16 )
return V_16 ;
return V_40 ;
}
static
int F_35 ( struct V_31 * V_77 ,
const char * V_78 ,
struct V_1 const * V_79 ,
T_3 (* F_36)( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 ) ,
T_3 (* F_37)( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_5 V_40 ) ,
bool V_80 )
{
int V_16 ;
char * V_81 , * V_82 ;
F_38 ( & V_77 -> V_32 ) ;
if ( V_79 -> V_83 && ! V_80 ) {
if ( V_79 -> V_84 )
V_82 = F_39 ( V_22 , L_11 ,
V_85 [ V_79
-> V_86 ] ,
V_79 -> V_84 ,
V_78 ) ;
else
V_82 = F_39 ( V_22 , L_12 ,
V_85 [ V_79
-> V_86 ] ,
V_78 ) ;
} else {
if ( V_79 -> V_84 == NULL )
V_82 = F_40 ( V_78 , V_22 ) ;
else
V_82 = F_39 ( V_22 ,
L_12 ,
V_79 -> V_84 ,
V_78 ) ;
}
if ( V_82 == NULL ) {
V_16 = - V_23 ;
goto V_24;
}
if ( V_79 -> V_87 ) {
if ( V_80 )
V_81
= F_39 ( V_22 , L_13 ,
V_88 [ V_79 -> V_89 ] ,
V_90 [ V_79 -> type ] ,
V_90 [ V_79 -> type ] ,
V_82 ) ;
else if ( V_79 -> V_91 )
V_81
= F_39 ( V_22 , L_14 ,
V_88 [ V_79 -> V_89 ] ,
V_90 [ V_79 -> type ] ,
V_79 -> V_92 ,
V_90 [ V_79 -> type ] ,
V_79 -> V_86 ,
V_82 ) ;
else {
F_41 ( L_15 ) ;
V_16 = - V_41 ;
goto V_93;
}
} else {
if ( V_80 )
V_81
= F_39 ( V_22 , L_11 ,
V_88 [ V_79 -> V_89 ] ,
V_90 [ V_79 -> type ] ,
V_82 ) ;
else if ( V_79 -> V_91 )
V_81
= F_39 ( V_22 , L_16 ,
V_88 [ V_79 -> V_89 ] ,
V_90 [ V_79 -> type ] ,
V_79 -> V_92 ,
V_82 ) ;
else
V_81
= F_39 ( V_22 , L_11 ,
V_88 [ V_79 -> V_89 ] ,
V_90 [ V_79 -> type ] ,
V_82 ) ;
}
if ( V_81 == NULL ) {
V_16 = - V_23 ;
goto V_93;
}
V_77 -> V_32 . V_94 = F_39 ( V_22 ,
V_81 ,
V_79 -> V_92 ,
V_79 -> V_86 ) ;
if ( V_77 -> V_32 . V_94 == NULL ) {
V_16 = - V_23 ;
goto V_95;
}
if ( F_36 ) {
V_77 -> V_32 . V_96 |= V_97 ;
V_77 -> V_98 = F_36 ;
}
if ( F_37 ) {
V_77 -> V_32 . V_96 |= V_99 ;
V_77 -> V_100 = F_37 ;
}
F_17 ( V_81 ) ;
F_17 ( V_82 ) ;
return 0 ;
V_95:
F_17 ( V_81 ) ;
V_93:
F_17 ( V_82 ) ;
V_24:
return V_16 ;
}
static void F_42 ( struct V_31 * V_77 )
{
F_17 ( V_77 -> V_32 . V_94 ) ;
}
int F_43 ( const char * V_78 ,
struct V_1 const * V_79 ,
T_3 (* F_36)( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 ) ,
T_3 (* F_37)( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_5 V_40 ) ,
T_1 V_101 ,
bool V_80 ,
struct V_29 * V_30 ,
struct V_102 * V_103 )
{
int V_16 ;
struct V_60 * V_104 , * V_48 ;
V_104 = F_44 ( sizeof *V_104 , V_22 ) ;
if ( V_104 == NULL ) {
V_16 = - V_23 ;
goto V_24;
}
V_16 = F_35 ( & V_104 -> V_77 ,
V_78 , V_79 ,
F_36 , F_37 , V_80 ) ;
if ( V_16 )
goto V_105;
V_104 -> V_66 = V_79 ;
V_104 -> V_67 = V_101 ;
F_45 (t, attr_list, l)
if ( strcmp ( V_48 -> V_77 . V_32 . V_94 ,
V_104 -> V_77 . V_32 . V_94 ) == 0 ) {
if ( ! V_80 )
F_46 ( V_30 , L_17 ,
V_48 -> V_77 . V_32 . V_94 ) ;
V_16 = - V_51 ;
goto V_106;
}
F_47 ( & V_104 -> V_107 , V_103 ) ;
return 0 ;
V_106:
F_42 ( & V_104 -> V_77 ) ;
V_105:
F_17 ( V_104 ) ;
V_24:
return V_16 ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_1 const * V_79 )
{
int V_16 , V_5 , V_108 = 0 ;
if ( V_79 -> V_92 < 0 )
return 0 ;
V_16 = F_43 ( V_109 [ V_79 -> V_110 ] ,
V_79 ,
& F_31 ,
( V_79 -> V_89 ?
& F_34 : NULL ) ,
0 ,
0 ,
& V_3 -> V_30 ,
& V_3 -> V_111 ) ;
if ( V_16 )
goto V_24;
V_108 ++ ;
F_49 (i, &chan->info_mask, sizeof(long)*8 ) {
V_16 = F_43 ( V_112 [ V_5 / 2 ] ,
V_79 ,
& F_31 ,
& F_34 ,
V_5 / 2 ,
! ( V_5 % 2 ) ,
& V_3 -> V_30 ,
& V_3 -> V_111 ) ;
if ( V_16 == - V_51 && ( V_5 % 2 == 0 ) ) {
V_16 = 0 ;
continue;
}
if ( V_16 < 0 )
goto V_24;
V_108 ++ ;
}
V_16 = V_108 ;
V_24:
return V_16 ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_60 * V_113 )
{
F_17 ( V_113 -> V_77 . V_32 . V_94 ) ;
F_17 ( V_113 ) ;
}
static T_3 F_51 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_2 * V_3 = F_32 ( V_30 ) ;
return sprintf ( V_33 , L_1 , V_3 -> V_94 ) ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_5 , V_16 = 0 , V_108 , V_114 , V_115 = 0 ;
struct V_60 * V_113 , * V_116 ;
struct V_117 * * V_32 ;
if ( V_3 -> V_64 -> V_118 ) {
V_32 = V_3 -> V_64 -> V_118 -> V_118 ;
while ( * V_32 ++ != NULL )
V_115 ++ ;
}
V_108 = V_115 ;
F_53 ( & V_3 -> V_111 ) ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_16 = F_48 ( V_3 ,
& V_3
-> V_7 [ V_5 ] ) ;
if ( V_16 < 0 )
goto V_119;
V_108 += V_16 ;
}
if ( V_3 -> V_94 )
V_108 ++ ;
V_3 -> V_120 . V_118 = F_54 ( V_108 + 1 ,
sizeof( V_3 -> V_120 . V_118 [ 0 ] ) ,
V_22 ) ;
if ( V_3 -> V_120 . V_118 == NULL ) {
V_16 = - V_23 ;
goto V_119;
}
if ( V_3 -> V_64 -> V_118 )
memcpy ( V_3 -> V_120 . V_118 ,
V_3 -> V_64 -> V_118 -> V_118 ,
sizeof( V_3 -> V_120 . V_118 [ 0 ] )
* V_115 ) ;
V_114 = V_115 ;
F_45 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_120 . V_118 [ V_114 ++ ] = & V_113 -> V_77 . V_32 ;
if ( V_3 -> V_94 )
V_3 -> V_120 . V_118 [ V_114 ++ ] = & V_121 . V_32 ;
V_3 -> V_122 [ V_3 -> V_123 ++ ] =
& V_3 -> V_120 ;
return 0 ;
V_119:
F_20 (p, n,
&indio_dev->channel_attr_list, l) {
F_16 ( & V_113 -> V_107 ) ;
F_50 ( V_3 , V_113 ) ;
}
return V_16 ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_60 * V_113 , * V_116 ;
F_20 (p, n, &indio_dev->channel_attr_list, l) {
F_16 ( & V_113 -> V_107 ) ;
F_50 ( V_3 , V_113 ) ;
}
F_17 ( V_3 -> V_120 . V_118 ) ;
}
static T_3 F_56 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_5 V_40 )
{
struct V_2 * V_3 = F_32 ( V_30 ) ;
struct V_60 * V_61 = F_33 ( V_32 ) ;
int V_16 ;
bool V_62 ;
V_16 = F_57 ( V_33 , & V_62 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = V_3 -> V_64 -> V_124 ( V_3 ,
V_61 -> V_67 ,
V_62 ) ;
return ( V_16 < 0 ) ? V_16 : V_40 ;
}
static T_3 F_58 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_2 * V_3 = F_32 ( V_30 ) ;
struct V_60 * V_61 = F_33 ( V_32 ) ;
int V_62 = V_3 -> V_64 -> V_125 ( V_3 ,
V_61 -> V_67 ) ;
if ( V_62 < 0 )
return V_62 ;
else
return sprintf ( V_33 , L_6 , V_62 ) ;
}
static T_3 F_59 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_2 * V_3 = F_32 ( V_30 ) ;
struct V_60 * V_61 = F_33 ( V_32 ) ;
int V_62 , V_16 ;
V_16 = V_3 -> V_64 -> V_126 ( V_3 ,
V_61 -> V_67 , & V_62 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_33 , L_6 , V_62 ) ;
}
static T_3 F_60 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_5 V_40 )
{
struct V_2 * V_3 = F_32 ( V_30 ) ;
struct V_60 * V_61 = F_33 ( V_32 ) ;
unsigned long V_62 ;
int V_16 ;
if ( ! V_3 -> V_64 -> V_127 )
return - V_41 ;
V_16 = F_61 ( V_33 , 10 , & V_62 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_3 -> V_64 -> V_127 ( V_3 , V_61 -> V_67 ,
V_62 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_40 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_1 const * V_79 )
{
int V_16 = 0 , V_5 , V_108 = 0 ;
T_1 V_101 = 0 ;
char * V_78 ;
if ( ! V_79 -> V_128 )
return 0 ;
F_49 (i, &chan->event_mask, sizeof(chan->event_mask)*8 ) {
V_78 = F_39 ( V_22 , L_18 ,
V_129 [ V_5 / V_130 ] ,
V_131 [ V_5 % V_130 ] ) ;
if ( V_78 == NULL ) {
V_16 = - V_23 ;
goto V_24;
}
if ( V_79 -> V_83 )
V_101 = F_63 ( V_79 -> type , 0 , V_79 -> V_92 ,
V_5 / V_130 ,
V_5 % V_130 ) ;
else if ( V_79 -> V_87 )
V_101 = F_64 ( V_79 -> type ,
0 , 0 ,
V_5 % V_130 ,
V_5 / V_130 ,
0 ,
V_79 -> V_92 ,
V_79 -> V_86 ) ;
else
V_101 = F_65 ( V_79 -> type ,
V_79 -> V_92 ,
V_5 / V_130 ,
V_5 % V_130 ) ;
V_16 = F_43 ( V_78 ,
V_79 ,
& F_58 ,
F_56 ,
V_101 ,
0 ,
& V_3 -> V_30 ,
& V_3 -> V_13 ->
V_132 ) ;
F_17 ( V_78 ) ;
if ( V_16 )
goto V_24;
V_108 ++ ;
V_78 = F_39 ( V_22 , L_19 ,
V_129 [ V_5 / V_130 ] ,
V_131 [ V_5 % V_130 ] ) ;
if ( V_78 == NULL ) {
V_16 = - V_23 ;
goto V_24;
}
V_16 = F_43 ( V_78 , V_79 ,
F_59 ,
F_60 ,
V_101 ,
0 ,
& V_3 -> V_30 ,
& V_3 -> V_13 ->
V_132 ) ;
F_17 ( V_78 ) ;
if ( V_16 )
goto V_24;
V_108 ++ ;
}
V_16 = V_108 ;
V_24:
return V_16 ;
}
static inline void F_66 ( struct V_2 * V_3 )
{
struct V_60 * V_113 , * V_116 ;
F_20 (p, n,
&indio_dev->event_interface->
dev_attr_list, l) {
F_17 ( V_113 -> V_77 . V_32 . V_94 ) ;
F_17 ( V_113 ) ;
}
}
static inline int F_67 ( struct V_2 * V_3 )
{
int V_133 , V_16 , V_108 = 0 ;
F_53 ( & V_3 -> V_13 -> V_132 ) ;
for ( V_133 = 0 ; V_133 < V_3 -> V_6 ; V_133 ++ ) {
V_16 = F_62 ( V_3 ,
& V_3 -> V_7 [ V_133 ] ) ;
if ( V_16 < 0 )
goto V_119;
V_108 += V_16 ;
}
return V_108 ;
V_119:
F_66 ( V_3 ) ;
return V_16 ;
}
static bool F_68 ( struct V_2 * V_3 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_3 -> V_6 ; V_133 ++ )
if ( V_3 -> V_7 [ V_133 ] . V_128 != 0 )
return true ;
return false ;
}
static void F_69 ( struct V_11 * V_12 )
{
F_70 ( & V_12 -> V_17 ) ;
V_12 -> V_21 = 10 ;
V_12 -> V_20 = 0 ;
F_53 ( & V_12 -> V_27 ) ;
F_71 ( & V_12 -> V_28 ) ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_60 * V_113 ;
int V_16 = 0 , V_115 = 0 , V_108 , V_114 ;
struct V_117 * * V_32 ;
if ( ! ( V_3 -> V_64 -> V_134 ||
F_68 ( V_3 ) ) )
return 0 ;
V_3 -> V_13 =
F_44 ( sizeof( struct V_11 ) , V_22 ) ;
if ( V_3 -> V_13 == NULL ) {
V_16 = - V_23 ;
goto V_24;
}
F_69 ( V_3 -> V_13 ) ;
if ( V_3 -> V_64 -> V_134 != NULL ) {
V_32 = V_3 -> V_64 -> V_134 -> V_118 ;
while ( * V_32 ++ != NULL )
V_115 ++ ;
}
V_108 = V_115 ;
if ( V_3 -> V_7 ) {
V_16 = F_67 ( V_3 ) ;
if ( V_16 < 0 )
goto V_135;
V_108 += V_16 ;
}
V_3 -> V_13 -> V_136 . V_94 = V_137 ;
V_3 -> V_13 -> V_136 . V_118 = F_54 ( V_108 + 1 ,
sizeof( V_3 -> V_13 -> V_136 . V_118 [ 0 ] ) ,
V_22 ) ;
if ( V_3 -> V_13 -> V_136 . V_118 == NULL ) {
V_16 = - V_23 ;
goto V_135;
}
if ( V_3 -> V_64 -> V_134 )
memcpy ( V_3 -> V_13 -> V_136 . V_118 ,
V_3 -> V_64 -> V_134 -> V_118 ,
sizeof( V_3 -> V_13 -> V_136 . V_118 [ 0 ] )
* V_115 ) ;
V_114 = V_115 ;
F_45 (p,
&indio_dev->event_interface->dev_attr_list,
l)
V_3 -> V_13 -> V_136 . V_118 [ V_114 ++ ] =
& V_113 -> V_77 . V_32 ;
V_3 -> V_122 [ V_3 -> V_123 ++ ] =
& V_3 -> V_13 -> V_136 ;
return 0 ;
V_135:
F_66 ( V_3 ) ;
F_17 ( V_3 -> V_13 ) ;
V_24:
return V_16 ;
}
static void F_73 ( struct V_2 * V_3 )
{
if ( V_3 -> V_13 == NULL )
return;
F_66 ( V_3 ) ;
F_17 ( V_3 -> V_13 -> V_136 . V_118 ) ;
F_17 ( V_3 -> V_13 ) ;
}
static void F_74 ( struct V_29 * V_29 )
{
struct V_2 * V_3 = F_75 ( V_29 , struct V_2 , V_30 ) ;
F_76 ( & V_3 -> V_138 ) ;
if ( V_3 -> V_139 & V_140 )
F_77 ( V_3 ) ;
F_73 ( V_3 ) ;
F_55 ( V_3 ) ;
}
struct V_2 * F_78 ( int V_141 )
{
struct V_2 * V_30 ;
T_5 V_142 ;
V_142 = sizeof( struct V_2 ) ;
if ( V_141 ) {
V_142 = F_79 ( V_142 , V_143 ) ;
V_142 += V_141 ;
}
V_142 += V_143 - 1 ;
V_30 = F_44 ( V_142 , V_22 ) ;
if ( V_30 ) {
V_30 -> V_30 . V_122 = V_30 -> V_122 ;
V_30 -> V_30 . type = & V_144 ;
V_30 -> V_30 . V_145 = & V_54 ;
F_80 ( & V_30 -> V_30 ) ;
F_81 ( & V_30 -> V_30 , ( void * ) V_30 ) ;
F_70 ( & V_30 -> V_146 ) ;
V_30 -> V_25 = F_82 ( & V_147 , 0 , 0 , V_22 ) ;
if ( V_30 -> V_25 < 0 ) {
F_26 ( V_55 L_20 ) ;
F_17 ( V_30 ) ;
return NULL ;
}
F_83 ( & V_30 -> V_30 , L_21 , V_30 -> V_25 ) ;
}
return V_30 ;
}
void F_84 ( struct V_2 * V_30 )
{
if ( V_30 ) {
F_85 ( & V_147 , V_30 -> V_25 ) ;
F_17 ( V_30 ) ;
}
}
static int F_86 ( struct V_47 * V_47 , struct V_34 * V_148 )
{
struct V_2 * V_3 = F_75 ( V_47 -> V_149 ,
struct V_2 , V_138 ) ;
if ( F_22 ( V_18 , & V_3 -> V_19 ) )
return - V_51 ;
V_148 -> V_38 = V_3 ;
return 0 ;
}
static int F_87 ( struct V_47 * V_47 , struct V_34 * V_148 )
{
struct V_2 * V_3 = F_75 ( V_47 -> V_149 ,
struct V_2 , V_138 ) ;
F_19 ( V_18 , & V_3 -> V_19 ) ;
return 0 ;
}
static long F_88 ( struct V_34 * V_148 , unsigned int V_150 , unsigned long V_151 )
{
struct V_2 * V_3 = V_148 -> V_38 ;
int T_4 * V_152 = ( int T_4 * ) V_151 ;
int V_49 ;
if ( V_150 == V_153 ) {
V_49 = F_21 ( V_3 ) ;
if ( F_15 ( V_152 , & V_49 , sizeof( V_49 ) ) )
return - V_46 ;
return 0 ;
}
return - V_41 ;
}
int F_89 ( struct V_2 * V_3 )
{
int V_16 ;
V_3 -> V_30 . V_154 = F_90 ( F_91 ( V_57 ) , V_3 -> V_25 ) ;
V_16 = F_52 ( V_3 ) ;
if ( V_16 ) {
F_46 ( V_3 -> V_30 . V_155 ,
L_22 ) ;
goto V_24;
}
V_16 = F_72 ( V_3 ) ;
if ( V_16 ) {
F_46 ( V_3 -> V_30 . V_155 ,
L_23 ) ;
goto V_156;
}
if ( V_3 -> V_139 & V_140 )
F_92 ( V_3 ) ;
V_16 = F_93 ( & V_3 -> V_30 ) ;
if ( V_16 < 0 )
goto V_157;
F_94 ( & V_3 -> V_138 , & V_158 ) ;
V_3 -> V_138 . V_159 = V_3 -> V_64 -> V_160 ;
V_16 = F_95 ( & V_3 -> V_138 , V_3 -> V_30 . V_154 , 1 ) ;
if ( V_16 < 0 )
goto V_161;
return 0 ;
V_161:
F_96 ( & V_3 -> V_30 ) ;
V_157:
F_73 ( V_3 ) ;
V_156:
F_55 ( V_3 ) ;
V_24:
return V_16 ;
}
void F_97 ( struct V_2 * V_3 )
{
F_98 ( & V_3 -> V_30 ) ;
}
