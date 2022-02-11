static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ,
V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_5 )
{
if ( V_2 -> V_6 ) {
F_2 ( V_2 , V_7 , V_5 ) ;
F_2 ( V_2 , V_3 ,
V_8 ) ;
} else {
F_2 ( V_2 , V_3 ,
V_8 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
}
}
static T_2 F_4 ( const T_1 * V_9 ,
const T_1 * V_10 ,
T_3 V_11 ,
unsigned int * V_12 )
{
const T_1 * V_13 ;
unsigned int V_14 = * V_12 ;
T_2 V_15 ;
if ( V_14 < V_11 )
V_13 = V_9 ;
else {
V_13 = V_10 ;
V_14 -= V_11 ;
}
V_15 = F_5 ( * ( ( V_16 * ) ( V_13 + V_14 ) ) ) ;
* V_12 += 2 ;
return V_15 ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 * V_9 ,
const T_1 * V_10 ,
unsigned int V_17 )
{
T_2 V_18 ;
unsigned int V_14 = 0 ;
if ( V_2 -> V_6 ) {
V_18 = F_4 ( V_9 , V_10 ,
sizeof( struct V_19 ) , & V_14 ) ;
F_2 ( V_2 , V_7 , V_18 ) ;
}
F_2 ( V_2 , V_3 ,
V_8 |
V_20 ) ;
while ( V_14 < V_17 - 1 ) {
V_18 = F_4 ( V_9 , V_10 ,
sizeof( struct V_19 ) , & V_14 ) ;
F_2 ( V_2 , V_7 , V_18 ) ;
}
if ( V_17 % 2 )
F_3 ( V_2 , V_10 [ V_17 -
sizeof( struct V_19 ) - 1 ] ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
if ( V_2 -> V_6 ) {
F_2 ( V_2 , V_7 ,
V_22 -> V_18 [ V_22 -> V_23 - 1 ] ) ;
F_2 ( V_2 , V_3 ,
V_8 |
V_24 ) ;
} else
F_2 ( V_2 , V_3 ,
V_24 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 ,
struct V_25 * V_10 )
{
T_2 V_26 = 0x0000 ;
int V_27 ;
switch ( V_2 -> V_28 ) {
case V_29 :
break;
case V_30 :
V_26 = 0x1000 ;
break;
case V_31 :
V_26 = 0x2000 ;
break;
case V_32 :
V_26 = 0x3000 ;
break;
default:
F_9 ( 1 ) ;
}
V_27 = F_10 ( V_10 ) ;
F_9 ( ! ( ( ( T_2 ) V_27 & 0xF000 ) == 0x0000 ) ) ;
V_26 |= ( T_2 ) V_27 ;
return V_26 ;
}
static
struct V_1 * F_11 ( struct V_33 * V_34 ,
T_2 V_26 ,
struct V_25 * * V_10 )
{
struct V_35 * V_36 = & V_34 -> V_36 ;
struct V_1 * V_2 = NULL ;
int V_27 ;
switch ( V_26 & 0xF000 ) {
case 0x0000 :
V_2 = V_36 -> V_37 ;
break;
case 0x1000 :
V_2 = V_36 -> V_38 ;
break;
case 0x2000 :
V_2 = V_36 -> V_39 ;
break;
case 0x3000 :
V_2 = V_36 -> V_40 ;
break;
default:
F_9 ( 1 ) ;
}
V_27 = ( V_26 & 0x0FFF ) ;
F_9 ( ! ( V_27 >= 0 && V_27
< V_41 ) ) ;
* V_10 = & ( V_2 -> V_42 [ V_27 ] ) ;
return V_2 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_25 * V_10 ,
T_3 V_11 )
{
union V_43 V_44 ;
T_1 * V_9 = NULL ;
unsigned int V_17 ;
int V_45 ;
V_9 = ( T_1 * ) ( & V_44 . V_46 ) ;
F_9 ( F_13 ( V_22 ) -> V_47 != 0 ) ;
V_45 = F_14 ( V_2 -> V_34 ,
V_9 , V_22 -> V_18 , V_22 -> V_23 ,
F_15 ( V_22 ) ,
F_8 ( V_2 , V_10 ) ) ;
if ( V_45 )
return V_45 ;
F_1 ( V_2 ) ;
V_17 = V_22 -> V_23 + V_11 ;
if ( V_2 -> V_6 )
V_17 -- ;
F_6 ( V_2 , V_9 , ( T_1 * ) V_22 -> V_18 , V_17 ) ;
F_7 ( V_2 , V_22 ) ;
return 0 ;
}
static void F_16 ( struct V_25 * V_10 ,
int V_48 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_22 ) {
if ( V_48 )
F_17 ( V_10 -> V_22 ) ;
else
F_18 ( V_10 -> V_22 ) ;
}
F_19 ( & V_10 -> V_49 , & V_2 -> V_50 ) ;
V_2 -> V_51 ++ ;
}
static int F_20 ( struct V_25 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_21 * V_22 = V_10 -> V_22 ;
T_2 V_17 ;
int V_45 ;
V_17 = ( T_2 ) V_22 -> V_23 + sizeof( struct V_19 ) ;
if ( V_2 -> V_52 < V_17 ) {
F_21 ( V_2 -> V_34 -> V_53 , L_1
L_2 ) ;
F_16 ( V_10 , 1 ) ;
return 0 ;
}
F_9 ( V_2 -> V_54 >
V_55 ) ;
F_9 ( V_2 -> V_56 > V_2 -> V_52 ) ;
if ( V_2 -> V_54 == V_55 )
return - V_57 ;
if ( V_2 -> V_56 + V_17 > V_2 -> V_52 )
return - V_57 ;
V_45 = F_12 ( V_2 , V_22 , V_10 ,
sizeof( struct V_19 ) ) ;
if ( F_22 ( V_45 == - V_58 ) ) {
F_16 ( V_10 , 1 ) ;
return 0 ;
}
V_2 -> V_54 ++ ;
V_2 -> V_56 += V_17 ;
F_23 ( & V_10 -> V_49 , & V_2 -> V_59 ) ;
return 0 ;
}
static void F_24 ( unsigned long V_60 )
{
struct V_1 * V_2 = (struct V_1 * ) V_60 ;
struct V_33 * V_34 = V_2 -> V_34 ;
unsigned long V_61 ;
struct V_25 * V_10 , * V_62 ;
int V_45 ;
T_2 V_63 ;
F_25 ( & V_34 -> V_53 -> V_64 , V_61 ) ;
if ( V_2 -> V_65 )
goto V_66;
V_63 = F_26 ( V_2 , V_3 ) ;
if ( V_63 & V_67 )
goto V_66;
F_27 (packet, tmp_packet, &queue->txqueue, list) {
V_45 = F_20 ( V_10 ) ;
if ( V_45 )
break;
}
V_66:
F_28 ( & V_34 -> V_53 -> V_64 , V_61 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_25 * V_10 ;
int V_14 ;
V_2 -> V_51 = V_41 ;
for ( V_14 = 0 ; V_14 < V_41 ; V_14 ++ ) {
V_10 = & ( V_2 -> V_42 [ V_14 ] ) ;
V_10 -> V_2 = V_2 ;
F_30 ( & V_10 -> V_49 ) ;
F_31 ( & V_10 -> V_49 , & V_2 -> V_50 ) ;
}
}
static
struct V_1 * F_32 ( struct V_33 * V_34 ,
T_2 V_68 )
{
struct V_1 * V_2 ;
T_4 V_69 ;
T_2 V_70 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 )
goto V_72;
V_2 -> V_34 = V_34 ;
V_2 -> V_28 = V_68 ;
V_2 -> V_6 = ( V_34 -> V_34 -> V_73 . V_74 < 3 ) ;
F_30 ( & V_2 -> V_50 ) ;
F_30 ( & V_2 -> V_75 ) ;
F_30 ( & V_2 -> V_59 ) ;
F_34 ( & V_2 -> V_76 , F_24 ,
( unsigned long ) V_2 ) ;
V_69 = F_35 ( V_34 , V_77 ) ;
V_69 &= ~ V_78 ;
F_36 ( V_34 , V_77 , V_69 ) ;
V_70 = F_37 ( V_34 , V_2 -> V_28
+ V_79 ) ;
if ( V_70 == 0 ) {
F_38 ( V_34 -> V_53 , L_3
L_4
L_5 ) ;
goto V_80;
}
if ( V_70 <= V_81 ) {
F_38 ( V_34 -> V_53 , L_6 ,
V_70 ) ;
goto V_80;
}
V_70 -= V_81 ;
V_2 -> V_52 = V_70 ;
F_29 ( V_2 ) ;
V_72:
return V_2 ;
V_80:
F_39 ( V_2 ) ;
V_2 = NULL ;
goto V_72;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_25 * V_10 , * V_62 ;
F_41 ( & V_2 -> V_76 ) ;
F_27 (packet, tmp_packet, &queue->txrunning, list)
F_16 ( V_10 , 0 ) ;
F_27 (packet, tmp_packet, &queue->txqueue, list)
F_16 ( V_10 , 0 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_40 ( V_2 ) ;
F_39 ( V_2 ) ;
}
void F_43 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
if ( ! F_44 ( V_34 ) )
return;
V_36 = & V_34 -> V_36 ;
F_42 ( V_36 -> V_40 ) ;
V_36 -> V_40 = NULL ;
F_42 ( V_36 -> V_39 ) ;
V_36 -> V_39 = NULL ;
F_42 ( V_36 -> V_38 ) ;
V_36 -> V_38 = NULL ;
F_42 ( V_36 -> V_37 ) ;
V_36 -> V_37 = NULL ;
}
int F_45 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = & V_34 -> V_36 ;
struct V_1 * V_2 ;
int V_45 = - V_82 ;
V_2 = F_32 ( V_34 , V_29 ) ;
if ( ! V_2 )
goto V_72;
V_36 -> V_37 = V_2 ;
V_2 = F_32 ( V_34 , V_30 ) ;
if ( ! V_2 )
goto V_83;
V_36 -> V_38 = V_2 ;
V_2 = F_32 ( V_34 , V_31 ) ;
if ( ! V_2 )
goto V_84;
V_36 -> V_39 = V_2 ;
V_2 = F_32 ( V_34 , V_32 ) ;
if ( ! V_2 )
goto V_85;
V_36 -> V_40 = V_2 ;
if ( V_34 -> V_34 -> V_73 . V_74 < 3 )
V_34 -> V_86 |= V_87 ;
F_46 ( V_34 -> V_53 , L_7 ) ;
V_45 = 0 ;
V_72:
return V_45 ;
V_85:
F_42 ( V_36 -> V_39 ) ;
V_36 -> V_39 = NULL ;
V_84:
F_42 ( V_36 -> V_38 ) ;
V_36 -> V_38 = NULL ;
V_83:
F_42 ( V_36 -> V_37 ) ;
V_36 -> V_37 = NULL ;
goto V_72;
}
int F_47 ( struct V_33 * V_34 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_34 -> V_36 . V_38 ;
struct V_25 * V_10 ;
F_9 ( V_2 -> V_88 ) ;
F_9 ( F_48 ( & V_2 -> V_50 ) ) ;
V_10 = F_49 ( V_2 -> V_50 . V_89 , struct V_25 ,
V_49 ) ;
V_10 -> V_22 = V_22 ;
F_23 ( & V_10 -> V_49 , & V_2 -> V_75 ) ;
V_2 -> V_51 -- ;
F_9 ( V_2 -> V_51 >= V_41 ) ;
F_50 ( & V_2 -> V_76 ) ;
return 0 ;
}
void F_51 ( struct V_33 * V_34 ,
const struct V_90 * V_91 )
{
struct V_1 * V_2 ;
struct V_25 * V_10 ;
struct V_92 * V_93 ;
int V_94 ;
V_2 = F_11 ( V_34 , V_91 -> V_26 , & V_10 ) ;
F_9 ( ! V_2 ) ;
if ( ! V_10 -> V_22 )
return;
V_2 -> V_54 -- ;
V_2 -> V_56 -= ( V_10 -> V_22 -> V_23 +
sizeof( struct V_19 ) ) ;
V_93 = F_15 ( V_10 -> V_22 ) ;
V_94 = V_93 -> V_91 . V_95 [ 0 ] . V_96 ;
F_52 ( V_93 ) ;
if ( V_91 -> V_97 )
V_93 -> V_61 |= V_98 ;
if ( V_91 -> V_99 > V_34 -> V_53 -> V_100 -> V_101 . V_102 ) {
V_93 -> V_91 . V_95 [ 0 ] . V_96 = 0 ;
V_93 -> V_91 . V_95 [ 1 ] . V_96 = V_91 -> V_103 ;
} else {
if ( V_91 -> V_103 > V_94 ) {
V_93 -> V_91 . V_95 [ 0 ] . V_96 = V_94 ;
V_93 -> V_91 . V_95 [ 1 ] . V_96 = V_91 -> V_103 -
V_94 ;
} else {
V_93 -> V_91 . V_95 [ 0 ] . V_96 = V_91 -> V_103 ;
V_93 -> V_91 . V_95 [ 1 ] . V_104 = - 1 ;
}
}
F_53 ( V_34 -> V_53 -> V_100 , V_10 -> V_22 ) ;
V_10 -> V_22 = NULL ;
F_16 ( V_10 , 1 ) ;
if ( ! F_48 ( & V_2 -> V_75 ) )
F_50 ( & V_2 -> V_76 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
int V_105 ,
const char * error )
{
int V_14 ;
F_38 ( V_2 -> V_34 -> V_53 , L_8 , error ) ;
F_2 ( V_2 , V_106 ,
V_107 ) ;
if ( V_105 ) {
F_9 ( V_2 -> V_28 != V_29 ) ;
for ( V_14 = 0 ; V_14 < 15 ; V_14 ++ ) {
F_26 ( V_2 , V_108 ) ;
}
}
}
void F_55 ( struct V_1 * V_2 )
{
V_16 V_109 [ 21 ] = { 0 } ;
struct V_110 * V_111 ;
T_2 V_112 ;
T_2 V_23 ;
T_2 V_113 ;
int V_14 ;
int V_114 ;
struct V_21 * V_22 ;
V_112 = F_26 ( V_2 , V_106 ) ;
if ( ! ( V_112 & V_115 ) )
return;
F_2 ( V_2 , V_106 ,
V_115 ) ;
for ( V_14 = 0 ; V_14 < 10 ; V_14 ++ ) {
V_112 = F_26 ( V_2 , V_106 ) ;
if ( V_112 & V_107 )
goto V_116;
F_56 ( 10 ) ;
}
F_46 ( V_2 -> V_34 -> V_53 , L_9 ) ;
return;
V_116:
V_23 = F_26 ( V_2 , V_108 ) ;
if ( F_22 ( V_23 > 0x700 ) ) {
F_54 ( V_2 , 0 , L_10 ) ;
return;
}
if ( F_22 ( V_23 == 0 && V_2 -> V_28 !=
V_32 ) ) {
F_54 ( V_2 , 0 , L_11 ) ;
return;
}
V_109 [ 0 ] = F_57 ( V_23 ) ;
if ( V_2 -> V_28 == V_32 )
V_114 = 14 / sizeof( T_2 ) ;
else
V_114 = 18 / sizeof( T_2 ) ;
for ( V_14 = 0 ; V_14 < V_114 ; V_14 ++ ) {
V_112 = F_26 ( V_2 , V_108 ) ;
V_109 [ V_14 + 1 ] = F_57 ( V_112 ) ;
}
V_111 = (struct V_110 * ) V_109 ;
V_113 = F_5 ( V_111 -> V_117 ) ;
if ( V_113 & V_118 ) {
F_54 ( V_2 ,
( V_2 -> V_28 == V_29 ) ,
L_12 ) ;
return;
}
if ( V_2 -> V_28 == V_32 ) {
struct V_119 * V_100 ;
V_100 = (struct V_119 * ) ( V_109 + 1 ) ;
F_58 ( V_2 -> V_34 , V_100 ) ;
return;
}
V_22 = F_59 ( V_23 ) ;
if ( F_22 ( ! V_22 ) ) {
F_54 ( V_2 , 1 , L_13 ) ;
return;
}
F_60 ( V_22 , V_23 ) ;
for ( V_14 = 0 ; V_14 < V_23 - 1 ; V_14 += 2 ) {
V_112 = F_26 ( V_2 , V_108 ) ;
* ( ( V_16 * ) ( V_22 -> V_18 + V_14 ) ) = F_57 ( V_112 ) ;
}
if ( V_23 % 2 ) {
V_112 = F_26 ( V_2 , V_108 ) ;
V_22 -> V_18 [ V_23 - 1 ] = ( V_112 & 0x00FF ) ;
}
F_61 ( V_2 -> V_34 , V_22 , V_111 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_34 , - 1 , 1 ) ;
F_2 ( V_2 , V_3 ,
F_26 ( V_2 , V_3 )
| V_67 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ,
F_26 ( V_2 , V_3 )
& ~ V_67 ) ;
F_63 ( V_2 -> V_34 , - 1 , - 1 ) ;
F_50 ( & V_2 -> V_76 ) ;
}
void F_65 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
F_9 ( ! F_44 ( V_34 ) ) ;
V_36 = & V_34 -> V_36 ;
V_36 -> V_37 -> V_65 = 1 ;
V_36 -> V_38 -> V_65 = 1 ;
V_36 -> V_39 -> V_65 = 1 ;
V_36 -> V_40 -> V_65 = 1 ;
}
void F_66 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
F_9 ( ! F_44 ( V_34 ) ) ;
V_36 = & V_34 -> V_36 ;
V_36 -> V_37 -> V_65 = 0 ;
V_36 -> V_38 -> V_65 = 0 ;
V_36 -> V_39 -> V_65 = 0 ;
V_36 -> V_40 -> V_65 = 0 ;
if ( ! F_48 ( & V_36 -> V_37 -> V_75 ) )
F_50 ( & V_36 -> V_37 -> V_76 ) ;
if ( ! F_48 ( & V_36 -> V_38 -> V_75 ) )
F_50 ( & V_36 -> V_38 -> V_76 ) ;
if ( ! F_48 ( & V_36 -> V_39 -> V_75 ) )
F_50 ( & V_36 -> V_39 -> V_76 ) ;
if ( ! F_48 ( & V_36 -> V_40 -> V_75 ) )
F_50 ( & V_36 -> V_40 -> V_76 ) ;
}
