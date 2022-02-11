static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 , V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_12 ; V_10 ++ ) {
if ( ! F_3 ( V_10 , V_6 -> V_13 ) )
continue;
V_9 -> V_14 [ V_11 ] = F_4 ( V_9 , F_5 ( V_9 , V_10 ) ) ;
V_11 ++ ;
}
if ( V_6 -> V_15 ) {
T_2 * V_16 = ( T_2 * ) ( ( V_17 * ) V_9 -> V_14 +
F_6 ( V_11 , sizeof( T_2 ) ) ) ;
* V_16 = V_4 -> V_16 ;
}
F_7 ( V_6 , ( V_17 * ) V_9 -> V_14 ) ;
F_8 ( V_6 -> V_18 ) ;
F_4 ( V_9 , V_19 ) ;
F_9 ( V_9 -> V_1 ) ;
return V_20 ;
}
static T_1 F_10 ( int V_1 , void * V_21 )
{
struct V_5 * V_6 = V_21 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
T_3 V_22 = F_4 ( V_9 , V_9 -> V_23 -> V_24 ) ;
if ( ! ( V_22 & V_9 -> V_23 -> V_25 ) )
return V_20 ;
if ( F_11 ( V_6 ) ) {
F_12 ( V_1 ) ;
F_13 ( V_6 -> V_18 , F_14 () ) ;
} else {
V_9 -> V_26 = F_4 ( V_9 , V_19 ) ;
V_9 -> V_27 = true ;
F_15 ( & V_9 -> V_28 ) ;
}
return V_20 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_29 * V_30 , * V_16 ;
int V_31 , V_32 = 0 ;
V_6 -> V_33 = F_17 ( & V_9 -> V_34 ,
V_9 -> V_33 ) + 1 ;
V_30 = F_18 ( & V_6 -> V_35 ,
( ( V_6 -> V_33 + 1 ) *
sizeof( struct V_29 ) ) ,
V_36 ) ;
if ( ! V_30 )
return - V_37 ;
F_19 (bit, &st->channels_mask, st->num_channels) {
struct V_29 * V_38 = V_30 + V_32 ;
V_38 -> type = V_39 ;
V_38 -> V_40 = 1 ;
V_38 -> V_41 = V_31 ;
V_38 -> V_42 = V_32 ;
V_38 -> V_43 . V_44 = 'u' ;
V_38 -> V_43 . V_45 = 10 ;
V_38 -> V_43 . V_46 = 16 ;
V_38 -> V_47 = V_48 |
V_49 ;
V_32 ++ ;
}
V_16 = V_30 + V_32 ;
V_16 -> type = V_50 ;
V_16 -> V_41 = - 1 ;
V_16 -> V_42 = V_32 ;
V_16 -> V_43 . V_44 = 's' ;
V_16 -> V_43 . V_45 = 64 ;
V_16 -> V_43 . V_46 = 64 ;
V_6 -> V_51 = V_30 ;
return V_6 -> V_33 ;
}
static V_17 F_20 ( struct V_5 * V_6 ,
struct V_52 * V_53 ,
const char * V_54 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
V_17 V_55 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_56 ; V_10 ++ ) {
char * V_57 = F_21 ( V_36 ,
L_1 ,
V_6 -> V_57 ,
V_6 -> V_58 ,
V_53 [ V_10 ] . V_57 ) ;
if ( ! V_57 )
return - V_37 ;
if ( strcmp ( V_54 , V_57 ) == 0 ) {
V_55 = V_53 [ V_10 ] . V_55 ;
F_22 ( V_57 ) ;
break;
}
F_22 ( V_57 ) ;
}
return V_55 ;
}
static int F_23 ( struct V_59 * V_18 , bool V_60 )
{
struct V_5 * V_6 = V_18 -> V_61 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_62 * V_14 = V_6 -> V_14 ;
struct V_63 * V_64 = V_9 -> V_23 ;
T_3 V_22 = F_4 ( V_9 , V_64 -> V_65 ) ;
V_17 V_55 ;
V_17 V_31 ;
V_55 = F_20 ( V_6 ,
V_9 -> V_66 ,
V_6 -> V_18 -> V_57 ) ;
if ( V_55 == 0 )
return - V_67 ;
if ( V_60 ) {
V_9 -> V_14 = F_24 ( V_6 -> V_68 , V_36 ) ;
if ( V_9 -> V_14 == NULL )
return - V_37 ;
F_25 ( V_9 , V_64 -> V_65 ,
V_22 | V_55 ) ;
F_19 (bit, buffer->scan_mask,
st->num_channels) {
struct V_29 const * V_38 = V_6 -> V_51 + V_31 ;
F_25 ( V_9 , V_69 ,
F_26 ( V_38 -> V_41 ) ) ;
}
F_25 ( V_9 , V_70 , V_64 -> V_25 ) ;
} else {
F_25 ( V_9 , V_71 , V_64 -> V_25 ) ;
F_25 ( V_9 , V_64 -> V_65 ,
V_22 & ~ V_55 ) ;
F_19 (bit, buffer->scan_mask,
st->num_channels) {
struct V_29 const * V_38 = V_6 -> V_51 + V_31 ;
F_25 ( V_9 , V_72 ,
F_26 ( V_38 -> V_41 ) ) ;
}
F_22 ( V_9 -> V_14 ) ;
}
return 0 ;
}
static struct V_59 * F_27 ( struct V_5 * V_6 ,
struct V_52 * V_73 )
{
struct V_59 * V_18 ;
int V_74 ;
V_18 = F_28 ( L_1 , V_6 -> V_57 ,
V_6 -> V_58 , V_73 -> V_57 ) ;
if ( V_18 == NULL )
return NULL ;
V_18 -> V_35 . V_75 = V_6 -> V_35 . V_75 ;
V_18 -> V_61 = V_6 ;
V_18 -> V_76 = & V_77 ;
V_74 = F_29 ( V_18 ) ;
if ( V_74 )
return NULL ;
return V_18 ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 , V_74 ;
V_9 -> V_18 = F_18 ( & V_6 -> V_35 ,
V_9 -> V_56 * sizeof( V_9 -> V_18 ) ,
V_36 ) ;
if ( V_9 -> V_18 == NULL ) {
V_74 = - V_37 ;
goto V_78;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_56 ; V_10 ++ ) {
if ( V_9 -> V_66 [ V_10 ] . V_79 && ! ( V_9 -> V_80 ) )
continue;
V_9 -> V_18 [ V_10 ] = F_27 ( V_6 ,
V_9 -> V_66 + V_10 ) ;
if ( V_9 -> V_18 [ V_10 ] == NULL ) {
F_31 ( & V_6 -> V_35 ,
L_2 , V_10 ) ;
V_74 = - V_37 ;
goto V_81;
}
}
return 0 ;
V_81:
for ( V_10 -- ; V_10 >= 0 ; V_10 -- ) {
F_32 ( V_9 -> V_18 [ V_10 ] ) ;
F_33 ( V_9 -> V_18 [ V_10 ] ) ;
}
V_78:
return V_74 ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_56 ; V_10 ++ ) {
F_32 ( V_9 -> V_18 [ V_10 ] ) ;
F_33 ( V_9 -> V_18 [ V_10 ] ) ;
}
}
static int F_35 ( struct V_5 * V_6 )
{
return F_36 ( V_6 , & V_82 ,
& F_1 , NULL ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
F_38 ( V_6 ) ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_29 const * V_38 ,
int * V_83 , int * V_84 , long V_85 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_74 ;
switch ( V_85 ) {
case V_86 :
F_40 ( & V_9 -> V_87 ) ;
F_25 ( V_9 , V_69 ,
F_26 ( V_38 -> V_41 ) ) ;
F_25 ( V_9 , V_70 , V_9 -> V_23 -> V_25 ) ;
F_25 ( V_9 , V_88 , V_89 ) ;
V_74 = F_41 ( V_9 -> V_28 ,
V_9 -> V_27 ,
F_42 ( 1000 ) ) ;
if ( V_74 == 0 )
V_74 = - V_90 ;
if ( V_74 < 0 ) {
F_43 ( & V_9 -> V_87 ) ;
return V_74 ;
}
* V_83 = V_9 -> V_26 ;
F_25 ( V_9 , V_72 ,
F_26 ( V_38 -> V_41 ) ) ;
F_25 ( V_9 , V_71 , V_9 -> V_23 -> V_25 ) ;
V_9 -> V_26 = 0 ;
V_9 -> V_27 = false ;
F_43 ( & V_9 -> V_87 ) ;
return V_91 ;
case V_92 :
* V_83 = ( V_9 -> V_93 * 1000 ) >> V_38 -> V_43 . V_45 ;
* V_84 = 0 ;
return V_94 ;
default:
break;
}
return - V_67 ;
}
static int F_44 ( struct V_8 * V_9 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_45 ( V_9 ) ;
struct V_97 * V_98 = V_96 -> V_35 . V_99 ;
struct V_97 * V_100 ;
int V_10 = 0 , V_74 ;
T_3 V_101 ;
if ( ! V_98 )
return - V_67 ;
V_9 -> V_80 = F_46 ( V_98 , L_3 ) ;
if ( F_47 ( V_98 , L_4 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_5 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_9 -> V_34 = V_101 ;
if ( F_47 ( V_98 , L_6 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_7 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_9 -> V_33 = V_101 ;
if ( F_47 ( V_98 , L_8 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_9 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_9 -> V_102 = V_101 ;
if ( F_47 ( V_98 , L_10 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_11 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_9 -> V_93 = V_101 ;
V_9 -> V_23 = F_18 ( & V_6 -> V_35 ,
sizeof( struct V_63 ) ,
V_36 ) ;
if ( ! V_9 -> V_23 ) {
F_31 ( & V_6 -> V_35 , L_12 ) ;
V_74 = - V_37 ;
goto V_78;
}
if ( F_47 ( V_98 , L_13 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_14 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_9 -> V_23 -> V_103 = V_101 ;
if ( F_47 ( V_98 , L_15 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_16 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_9 -> V_23 -> V_25 = V_101 ;
if ( F_47 ( V_98 , L_17 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_18 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_9 -> V_23 -> V_24 = V_101 ;
if ( F_47 ( V_98 , L_19 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_20 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_9 -> V_23 -> V_65 = V_101 ;
V_9 -> V_56 = F_48 ( V_98 ) ;
V_9 -> V_66 = F_18 ( & V_6 -> V_35 , V_9 -> V_56 *
sizeof( struct V_52 ) ,
V_36 ) ;
if ( ! V_9 -> V_66 ) {
F_31 ( & V_6 -> V_35 , L_21 ) ;
V_74 = - V_37 ;
goto V_78;
}
F_49 (node, trig_node) {
struct V_52 * V_18 = V_9 -> V_66 + V_10 ;
const char * V_57 ;
if ( F_50 ( V_100 , L_22 , & V_57 ) ) {
F_31 ( & V_6 -> V_35 , L_23 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_18 -> V_57 = V_57 ;
if ( F_47 ( V_100 , L_24 , & V_101 ) ) {
F_31 ( & V_6 -> V_35 , L_25 ) ;
V_74 = - V_67 ;
goto V_78;
}
V_18 -> V_55 = V_101 ;
V_18 -> V_79 = F_46 ( V_100 , L_26 ) ;
V_10 ++ ;
}
return 0 ;
V_78:
return V_74 ;
}
static int F_51 ( struct V_8 * V_9 ,
struct V_95 * V_96 )
{
struct V_104 * V_105 = V_96 -> V_35 . V_106 ;
if ( ! V_105 )
return - V_67 ;
V_9 -> V_80 = V_105 -> V_107 ;
V_9 -> V_93 = V_105 -> V_108 ;
V_9 -> V_34 = V_105 -> V_109 ;
V_9 -> V_33 = V_105 -> V_33 ;
V_9 -> V_102 = V_105 -> V_102 ;
V_9 -> V_56 = V_105 -> V_56 ;
V_9 -> V_66 = V_105 -> V_66 ;
V_9 -> V_23 = V_105 -> V_23 ;
return 0 ;
}
static int F_52 ( struct V_95 * V_96 )
{
unsigned int V_110 , V_111 , V_112 , V_113 ;
int V_74 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_114 * V_115 ;
V_6 = F_53 ( sizeof( struct V_8 ) ) ;
if ( V_6 == NULL ) {
V_74 = - V_37 ;
goto V_78;
}
V_9 = F_2 ( V_6 ) ;
if ( V_96 -> V_35 . V_99 )
V_74 = F_44 ( V_9 , V_96 ) ;
else
V_74 = F_51 ( V_9 , V_96 ) ;
if ( V_74 ) {
F_31 ( & V_96 -> V_35 , L_27 ) ;
V_74 = - V_67 ;
goto V_116;
}
F_54 ( V_96 , V_6 ) ;
V_6 -> V_35 . V_75 = & V_96 -> V_35 ;
V_6 -> V_57 = F_55 ( & V_96 -> V_35 ) ;
V_6 -> V_117 = V_118 ;
V_6 -> V_119 = & V_120 ;
V_9 -> V_1 = F_56 ( V_96 , 0 ) ;
if ( V_9 -> V_1 < 0 ) {
F_31 ( & V_96 -> V_35 , L_28 ) ;
V_74 = - V_121 ;
goto V_116;
}
V_115 = F_57 ( V_96 , V_122 , 0 ) ;
V_9 -> V_123 = F_58 ( & V_96 -> V_35 , V_115 ) ;
if ( F_59 ( V_9 -> V_123 ) ) {
V_74 = F_60 ( V_9 -> V_123 ) ;
goto V_116;
}
F_25 ( V_9 , V_88 , V_124 ) ;
F_25 ( V_9 , V_71 , 0xFFFFFFFF ) ;
V_74 = F_61 ( V_9 -> V_1 ,
F_10 ,
0 ,
V_96 -> V_35 . V_125 -> V_57 ,
V_6 ) ;
if ( V_74 ) {
F_31 ( & V_96 -> V_35 , L_29 ) ;
goto V_116;
}
V_9 -> V_126 = F_62 ( & V_96 -> V_35 , L_30 ) ;
if ( F_59 ( V_9 -> V_126 ) ) {
F_31 ( & V_96 -> V_35 , L_31 ) ;
V_74 = F_60 ( V_9 -> V_126 ) ;
goto V_127;
}
V_74 = F_63 ( V_9 -> V_126 ) ;
if ( V_74 ) {
F_31 ( & V_96 -> V_35 ,
L_32 ) ;
goto V_127;
}
V_9 -> V_113 = F_62 ( & V_96 -> V_35 , L_33 ) ;
if ( F_59 ( V_9 -> V_113 ) ) {
F_31 ( & V_96 -> V_35 , L_34 ) ;
V_74 = F_60 ( V_9 -> V_113 ) ;
goto V_128;
}
V_74 = F_63 ( V_9 -> V_113 ) ;
if ( V_74 ) {
F_31 ( & V_96 -> V_35 ,
L_35 ) ;
goto V_128;
}
V_111 = F_64 ( V_9 -> V_126 ) ;
V_113 = F_64 ( V_9 -> V_113 ) ;
V_110 = ( V_111 / ( 2 * V_113 ) ) - 1 ;
if ( ! V_9 -> V_102 ) {
F_31 ( & V_96 -> V_35 , L_36 ) ;
V_74 = - V_67 ;
goto V_129;
}
V_112 = F_65 ( ( V_9 -> V_102 * V_113 /
1000000 ) - 1 , 8 ) / 8 ;
F_25 ( V_9 , V_130 ,
( F_66 ( V_110 ) & V_131 ) |
( F_67 ( V_112 ) & V_132 ) ) ;
V_74 = F_16 ( V_6 ) ;
if ( V_74 < 0 ) {
F_31 ( & V_96 -> V_35 , L_37 ) ;
goto V_129;
}
F_68 ( & V_9 -> V_28 ) ;
F_69 ( & V_9 -> V_87 ) ;
V_74 = F_35 ( V_6 ) ;
if ( V_74 < 0 ) {
F_31 ( & V_96 -> V_35 , L_38 ) ;
goto V_129;
}
V_74 = F_30 ( V_6 ) ;
if ( V_74 < 0 ) {
F_31 ( & V_96 -> V_35 , L_39 ) ;
goto V_133;
}
V_74 = F_70 ( V_6 ) ;
if ( V_74 < 0 ) {
F_31 ( & V_96 -> V_35 , L_40 ) ;
goto V_134;
}
return 0 ;
V_134:
F_34 ( V_6 ) ;
V_133:
F_37 ( V_6 ) ;
V_129:
F_71 ( V_9 -> V_113 ) ;
V_128:
F_71 ( V_9 -> V_126 ) ;
V_127:
F_72 ( V_9 -> V_1 , V_6 ) ;
V_116:
F_73 ( V_6 ) ;
V_78:
return V_74 ;
}
static int F_74 ( struct V_95 * V_96 )
{
struct V_5 * V_6 = F_75 ( V_96 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_76 ( V_6 ) ;
F_34 ( V_6 ) ;
F_37 ( V_6 ) ;
F_71 ( V_9 -> V_113 ) ;
F_71 ( V_9 -> V_126 ) ;
F_72 ( V_9 -> V_1 , V_6 ) ;
F_73 ( V_6 ) ;
return 0 ;
}
