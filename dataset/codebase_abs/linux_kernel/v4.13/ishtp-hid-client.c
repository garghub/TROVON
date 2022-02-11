static void F_1 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_2 ( & V_9 -> V_10 -> V_11 , L_1
L_2
L_3
L_4
L_5
L_6 ,
V_7 -> V_12 . V_13 , V_9 -> V_14 ,
( unsigned int ) V_4 ,
( ( unsigned char * ) V_7 ) [ 0 ] , ( ( unsigned char * ) V_7 ) [ 1 ] ,
( ( unsigned char * ) V_7 ) [ 2 ] , ( ( unsigned char * ) V_7 ) [ 3 ] ,
( unsigned int ) V_5 , V_9 -> V_15 ,
V_7 -> V_12 . V_13 & ~ V_16 ) ;
}
static void F_3 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_17 )
{
struct V_6 * V_7 ;
unsigned char * V_18 ;
struct V_19 * V_20 ;
int V_21 , V_22 ;
T_1 V_5 , V_23 , V_4 ;
int V_24 ;
struct V_25 * V_26 ;
char * V_27 ;
T_1 V_28 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_29 = V_9 -> V_30 ;
if ( V_17 < sizeof( struct V_31 ) ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_7 ,
( unsigned int ) V_17 ,
( unsigned int ) sizeof( struct V_31 ) ) ;
++ V_9 -> V_14 ;
F_4 ( V_2 -> V_11 ) ;
return;
}
V_18 = V_3 + sizeof( struct V_31 ) ;
V_23 = V_17 ;
V_4 = 0 ;
do {
V_7 = (struct V_6 * ) ( V_3 + V_4 ) ;
V_5 = V_7 -> V_12 . V_32 ;
if ( V_4 + V_5 + sizeof( struct V_6 ) >
V_23 ) {
++ V_9 -> V_14 ;
F_1 ( V_2 , V_7 , V_4 ,
V_5 ) ;
F_4 ( V_2 -> V_11 ) ;
break;
}
F_5 ( V_9 , L_8 ,
V_33 , V_7 -> V_12 . V_13 & V_16 ) ;
switch ( V_7 -> V_12 . V_13 & V_16 ) {
case V_34 :
if ( ( ! ( V_7 -> V_12 . V_13 & ~ V_16 ) ||
V_9 -> V_35 ) ) {
++ V_9 -> V_14 ;
F_1 ( V_2 , V_7 ,
V_4 ,
V_5 ) ;
F_4 ( V_2 -> V_11 ) ;
break;
}
V_9 -> V_36 = ( unsigned int ) * V_18 ;
if ( ! V_9 -> V_37 )
V_9 -> V_37 = F_6 (
& V_9 -> V_10 -> V_11 ,
V_9 -> V_36 *
sizeof( struct V_19 ) ,
V_38 ) ;
if ( ! V_9 -> V_37 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_9 ) ;
F_7 ( & V_9 -> V_39 ) ;
break;
}
for ( V_21 = 0 ; V_21 < V_9 -> V_36 ; ++ V_21 ) {
if ( 1 + sizeof( struct V_19 ) * V_21 >=
V_5 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_10 ,
1 + sizeof( struct V_19 )
* V_21 , V_5 ) ;
}
if ( 1 + sizeof( struct V_19 ) * V_21 >=
V_17 )
break;
V_20 = (struct V_19 * ) ( V_18 + 1 +
sizeof( struct V_19 ) * V_21 ) ;
if ( V_9 -> V_37 )
memcpy ( V_9 -> V_37 + V_21 ,
V_20 ,
sizeof( struct V_19 ) ) ;
}
V_9 -> V_40 = true ;
F_7 ( & V_9 -> V_39 ) ;
break;
case V_41 :
if ( ( ! ( V_7 -> V_12 . V_13 & ~ V_16 ) ||
V_9 -> V_35 ) ) {
++ V_9 -> V_14 ;
F_1 ( V_2 , V_7 ,
V_4 ,
V_5 ) ;
F_4 ( V_2 -> V_11 ) ;
break;
}
if ( ! V_9 -> V_42 [ V_29 ] )
V_9 -> V_42 [ V_29 ] =
F_8 ( & V_9 -> V_10 -> V_11 ,
V_5 , V_38 ) ;
if ( V_9 -> V_42 [ V_29 ] ) {
memcpy ( V_9 -> V_42 [ V_29 ] ,
V_18 , V_5 ) ;
V_9 -> V_43 [ V_29 ] =
V_5 ;
V_9 -> V_44 = true ;
}
F_7 ( & V_9 -> V_39 ) ;
break;
case V_45 :
if ( ( ! ( V_7 -> V_12 . V_13 & ~ V_16 ) ||
V_9 -> V_35 ) ) {
++ V_9 -> V_14 ;
F_1 ( V_2 , V_7 ,
V_4 ,
V_5 ) ;
F_4 ( V_2 -> V_11 ) ;
break;
}
if ( ! V_9 -> V_46 [ V_29 ] )
V_9 -> V_46 [ V_29 ] =
F_8 ( & V_9 -> V_10 -> V_11 ,
V_5 , V_38 ) ;
if ( V_9 -> V_46 [ V_29 ] ) {
memcpy ( V_9 -> V_46 [ V_29 ] ,
V_18 ,
V_5 ) ;
V_9 -> V_47 [ V_29 ] =
V_5 ;
V_9 -> V_48 = true ;
}
F_7 ( & V_9 -> V_39 ) ;
break;
case V_49 :
V_24 = V_50 ;
goto V_51;
case V_52 :
V_24 = V_53 ;
V_51:
for ( V_21 = 0 ; V_21 < V_9 -> V_54 ; ++ V_21 ) {
if ( V_7 -> V_12 . V_55 ==
V_9 -> V_37 [ V_21 ] . V_56 )
if ( V_9 -> V_57 [ V_21 ] ) {
F_9 (
V_9 -> V_57 [
V_21 ] ,
V_24 , V_18 ,
V_5 , 0 ) ;
F_10 (
V_9 -> V_57 [
V_21 ] ) ;
break;
}
}
break;
case V_58 :
for ( V_21 = 0 ; V_21 < V_9 -> V_54 ; ++ V_21 ) {
if ( V_7 -> V_12 . V_55 ==
V_9 -> V_37 [ V_21 ] . V_56 )
if ( V_9 -> V_57 [ V_21 ] ) {
F_10 (
V_9 -> V_57 [
V_21 ] ) ;
break;
}
}
break;
case V_59 :
V_24 = V_53 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_54 ; ++ V_21 )
if ( V_7 -> V_12 . V_55 ==
V_9 -> V_37 [ V_21 ] . V_56 )
if ( V_9 -> V_57 [ V_21 ] )
F_9 (
V_9 -> V_57 [
V_21 ] ,
V_24 , V_18 ,
V_5 , 0 ) ;
break;
case V_60 :
V_24 = V_53 ;
V_26 = (struct V_25 * ) V_18 ;
V_27 = ( char * ) V_26 -> V_27 ;
for ( V_22 = 0 ; V_22 < V_26 -> V_61 ; V_22 ++ ) {
V_7 = (struct V_6 * ) ( V_27 +
sizeof( V_62 ) ) ;
V_28 = * ( V_62 * ) V_27 ;
V_18 = V_27 + sizeof( V_62 ) +
sizeof( struct V_31 ) ;
V_5 = V_28 -
sizeof( struct V_31 ) ;
for ( V_21 = 0 ; V_21 < V_9 -> V_54 ;
++ V_21 )
if ( V_7 -> V_12 . V_55 ==
V_9 -> V_37 [ V_21 ] . V_56 &&
V_9 -> V_57 [ V_21 ] ) {
F_9 (
V_9 -> V_57 [
V_21 ] ,
V_24 ,
V_18 , V_5 ,
0 ) ;
}
V_27 += sizeof( V_62 ) + V_28 ;
}
break;
default:
++ V_9 -> V_14 ;
F_1 ( V_2 , V_7 , V_4 ,
V_5 ) ;
F_4 ( V_2 -> V_11 ) ;
break;
}
if ( ! V_4 && V_4 + V_5 +
sizeof( struct V_6 ) < V_23 )
++ V_9 -> V_15 ;
V_4 += V_5 + sizeof( struct V_6 ) ;
V_18 += V_5 + sizeof( struct V_6 ) ;
} while ( V_4 < V_23 );
}
static void F_11 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_65 ;
struct V_66 * V_67 ;
T_1 V_68 ;
unsigned long V_69 ;
if ( ! V_2 )
return;
F_12 ( & V_2 -> V_70 , V_69 ) ;
while ( ! F_13 ( & V_2 -> V_71 . V_72 ) ) {
V_67 = F_14 (
V_2 -> V_71 . V_72 . V_73 ,
struct V_66 , V_72 ) ;
F_15 ( & V_67 -> V_72 ) ;
F_16 ( & V_2 -> V_70 ,
V_69 ) ;
if ( ! V_67 -> V_74 . V_75 )
return;
V_68 = V_67 -> V_76 ;
F_3 ( V_2 , V_67 -> V_74 . V_75 , V_68 ) ;
F_17 ( V_67 ) ;
F_12 ( & V_2 -> V_70 , V_69 ) ;
}
F_16 ( & V_2 -> V_70 , V_69 ) ;
}
void F_18 ( struct V_77 * V_78 , char * V_79 , unsigned int V_80 ,
int V_81 )
{
struct V_82 * V_83 = V_78 -> V_65 ;
struct V_8 * V_9 = V_83 -> V_9 ;
struct V_6 * V_84 = (struct V_6 * ) V_79 ;
int V_85 ;
int V_21 ;
F_5 ( V_9 , L_11 , V_33 , V_78 ) ;
V_85 = F_19 ( V_9 ) ;
if ( V_85 ) {
F_5 ( V_9 , L_12 ,
V_33 , V_78 ) ;
return;
}
memset ( V_84 , 0 , sizeof( struct V_6 ) ) ;
V_84 -> V_12 . V_13 = V_58 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_54 ; ++ V_21 ) {
if ( V_78 == V_9 -> V_57 [ V_21 ] ) {
V_84 -> V_12 . V_55 =
V_9 -> V_37 [ V_21 ] . V_56 ;
break;
}
}
if ( V_21 == V_9 -> V_54 )
return;
V_85 = F_20 ( V_9 -> V_2 , V_79 , V_80 ) ;
if ( V_85 )
F_5 ( V_9 , L_13 ,
V_33 , V_78 ) ;
}
void F_21 ( struct V_77 * V_78 , int V_81 ,
int V_24 )
{
struct V_82 * V_83 = V_78 -> V_65 ;
struct V_8 * V_9 = V_83 -> V_9 ;
static unsigned char V_79 [ 10 ] ;
unsigned int V_80 ;
struct V_86 * V_84 = (struct V_86 * ) V_79 ;
int V_85 ;
int V_21 ;
F_5 ( V_9 , L_11 , V_33 , V_78 ) ;
V_85 = F_19 ( V_9 ) ;
if ( V_85 ) {
F_5 ( V_9 , L_12 ,
V_33 , V_78 ) ;
return;
}
V_80 = sizeof( struct V_86 ) ;
memset ( V_84 , 0 , sizeof( struct V_86 ) ) ;
V_84 -> V_12 . V_13 = ( V_24 == V_50 ) ?
V_49 : V_52 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_54 ; ++ V_21 ) {
if ( V_78 == V_9 -> V_57 [ V_21 ] ) {
V_84 -> V_12 . V_55 =
V_9 -> V_37 [ V_21 ] . V_56 ;
break;
}
}
if ( V_21 == V_9 -> V_54 )
return;
V_84 -> V_81 = V_81 ;
V_85 = F_20 ( V_9 -> V_2 , V_79 , V_80 ) ;
if ( V_85 )
F_5 ( V_9 , L_13 ,
V_33 , V_78 ) ;
}
int F_19 ( struct V_8 * V_9 )
{
int V_87 ;
if ( V_9 -> V_88 ) {
F_5 ( V_9 , L_14 ) ;
V_87 = F_22 (
V_9 -> V_89 ,
! V_9 -> V_88 ,
5 * V_90 ) ;
if ( V_87 == 0 ) {
F_5 ( V_9 , L_15 ) ;
return - V_91 ;
}
F_5 ( V_9 , L_16 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 V_84 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_92 ;
int V_85 ;
memset ( & V_84 , 0 , sizeof( struct V_6 ) ) ;
V_84 . V_12 . V_13 = V_34 ;
V_85 = F_20 ( V_2 , ( unsigned char * ) & V_84 ,
sizeof( struct V_6 ) ) ;
if ( V_85 )
return V_85 ;
V_92 = 0 ;
while ( ! V_9 -> V_40 &&
V_92 < 10 ) {
F_22 ( V_9 -> V_39 ,
V_9 -> V_40 ,
3 * V_90 ) ;
++ V_92 ;
if ( ! V_9 -> V_40 )
V_85 = F_20 ( V_2 ,
( unsigned char * ) & V_84 ,
sizeof( struct V_6 ) ) ;
}
if ( ! V_9 -> V_40 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_17 ) ;
return - V_93 ;
}
if ( ! V_9 -> V_37 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_18 ) ;
return - V_94 ;
}
V_9 -> V_54 = V_9 -> V_36 ;
V_20 ( & V_2 -> V_64 -> V_11 ,
L_19 ,
V_9 -> V_54 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_95 )
{
struct V_6 V_84 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_85 ;
V_9 -> V_44 = false ;
memset ( & V_84 , 0 , sizeof( struct V_6 ) ) ;
V_84 . V_12 . V_13 = V_41 ;
V_84 . V_12 . V_55 = V_9 -> V_37 [ V_95 ] . V_56 ;
V_85 = F_20 ( V_2 , ( unsigned char * ) & V_84 ,
sizeof( struct V_6 ) ) ;
if ( V_85 )
return V_85 ;
if ( ! V_9 -> V_44 ) {
F_22 ( V_9 -> V_39 ,
V_9 -> V_44 ,
3 * V_90 ) ;
if ( ! V_9 -> V_44 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_20 ) ;
return - V_91 ;
}
if ( ! V_9 -> V_42 [ V_95 ] ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_21 ) ;
return - V_94 ;
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_95 )
{
struct V_6 V_84 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_85 ;
V_9 -> V_48 = false ;
memset ( & V_84 , 0 , sizeof( struct V_6 ) ) ;
V_84 . V_12 . V_13 = V_45 ;
V_84 . V_12 . V_55 = V_9 -> V_37 [ V_95 ] . V_56 ;
V_85 = F_20 ( V_2 , ( unsigned char * ) & V_84 ,
sizeof( struct V_6 ) ) ;
if ( V_85 )
return V_85 ;
if ( ! V_9 -> V_48 )
F_22 ( V_9 -> V_39 ,
V_9 -> V_48 ,
3 * V_90 ) ;
if ( ! V_9 -> V_48 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_22 ) ;
return - V_91 ;
}
if ( ! V_9 -> V_46 [ V_95 ] ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_23 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_96 )
{
struct V_97 * V_11 ;
unsigned long V_69 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_21 ;
int V_85 ;
F_27 ( & V_9 -> V_10 -> V_11 , L_24 , V_33 ) ;
F_5 ( V_9 , L_25 , V_33 , V_96 ) ;
V_85 = F_28 ( V_2 , V_98 ) ;
if ( V_85 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_26 ) ;
return - V_94 ;
}
V_9 -> V_35 = 0 ;
V_11 = V_2 -> V_11 ;
V_2 -> V_99 = V_100 ;
V_2 -> V_101 = V_102 ;
F_12 ( & V_11 -> V_103 , V_69 ) ;
V_21 = F_29 ( V_11 , & V_104 ) ;
if ( V_21 < 0 ) {
F_16 ( & V_11 -> V_103 , V_69 ) ;
F_2 ( & V_9 -> V_10 -> V_11 ,
L_27 ) ;
return V_21 ;
}
V_2 -> V_105 = V_11 -> V_106 [ V_21 ] . V_107 ;
F_16 ( & V_11 -> V_103 , V_69 ) ;
V_2 -> V_108 = V_109 ;
V_85 = F_30 ( V_2 ) ;
if ( V_85 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_28 ) ;
goto V_110;
}
F_5 ( V_9 , L_29 , V_33 ) ;
F_31 ( V_2 -> V_64 , F_11 ) ;
V_85 = F_23 ( V_2 ) ;
if ( V_85 )
goto V_111;
F_5 ( V_9 , L_30 ,
V_33 , V_9 -> V_54 ) ;
for ( V_21 = 0 ; V_21 < V_9 -> V_54 ; ++ V_21 ) {
V_9 -> V_30 = V_21 ;
V_85 = F_24 ( V_2 , V_21 ) ;
if ( V_85 )
goto V_111;
V_85 = F_25 ( V_2 , V_21 ) ;
if ( V_85 )
goto V_111;
if ( ! V_96 ) {
V_85 = F_32 ( V_21 , V_9 ) ;
if ( V_85 ) {
F_2 ( & V_9 -> V_10 -> V_11 ,
L_31 ,
V_21 , V_85 ) ;
goto V_111;
}
}
}
V_9 -> V_35 = 1 ;
V_9 -> V_88 = false ;
F_7 ( & V_9 -> V_89 ) ;
F_5 ( V_9 , L_32 , V_33 ) ;
return 0 ;
V_111:
V_2 -> V_108 = V_112 ;
F_33 ( V_2 ) ;
V_110:
F_34 ( V_2 ) ;
return V_85 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
}
static void F_38 ( struct V_113 * V_114 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_63 * V_10 ;
int V_115 ;
int V_85 ;
V_9 = F_39 ( V_114 , struct V_8 , V_114 ) ;
V_2 = V_9 -> V_2 ;
V_10 = V_9 -> V_10 ;
F_5 ( V_9 , L_33 , V_33 ,
V_2 ) ;
F_27 ( & V_10 -> V_11 , L_24 , V_33 ) ;
F_35 ( V_2 ) ;
V_2 = F_40 ( V_10 -> V_116 ) ;
if ( ! V_2 )
return;
V_10 -> V_65 = V_2 ;
V_2 -> V_9 = V_9 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_54 = 0 ;
for ( V_115 = 0 ; V_115 < 3 ; ++ V_115 ) {
V_85 = F_26 ( V_2 , 1 ) ;
if ( ! V_85 )
break;
F_2 ( & V_9 -> V_10 -> V_11 , L_34 ) ;
}
if ( V_85 ) {
F_2 ( & V_9 -> V_10 -> V_11 , L_35 ) ;
F_5 ( V_9 , L_36 ,
V_33 , V_2 ) ;
}
}
static int F_41 ( struct V_63 * V_10 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_85 ;
if ( ! V_10 )
return - V_117 ;
if ( F_42 ( V_104 ,
V_10 -> V_118 -> V_119 . V_120 ) != 0 )
return - V_117 ;
V_9 = F_6 ( & V_10 -> V_11 , sizeof( * V_9 ) ,
V_38 ) ;
if ( ! V_9 )
return - V_94 ;
V_2 = F_40 ( V_10 -> V_116 ) ;
if ( ! V_2 )
return - V_94 ;
V_10 -> V_65 = V_2 ;
V_2 -> V_9 = V_9 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_10 = V_10 ;
F_43 ( & V_9 -> V_39 ) ;
F_43 ( & V_9 -> V_89 ) ;
F_44 ( & V_9 -> V_114 , F_38 ) ;
V_85 = F_26 ( V_2 , 0 ) ;
if ( V_85 ) {
F_37 ( V_2 ) ;
return V_85 ;
}
F_45 ( V_10 ) ;
return 0 ;
}
static int F_46 ( struct V_63 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_65 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_5 ( V_9 , L_33 , V_33 ,
V_2 ) ;
F_27 ( & V_10 -> V_11 , L_24 , V_33 ) ;
V_2 -> V_108 = V_112 ;
F_33 ( V_2 ) ;
F_47 ( V_10 ) ;
F_48 ( V_9 ) ;
F_35 ( V_2 ) ;
V_2 = NULL ;
V_9 -> V_54 = 0 ;
return 0 ;
}
static int F_49 ( struct V_63 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_65 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_5 ( V_9 , L_33 , V_33 ,
V_2 ) ;
F_50 ( & V_9 -> V_114 ) ;
return 0 ;
}
static int F_51 ( struct V_64 * V_64 )
{
struct V_63 * V_10 = F_52 ( V_64 ) ;
struct V_1 * V_2 = V_10 -> V_65 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_5 ( V_9 , L_33 , V_33 ,
V_2 ) ;
V_9 -> V_88 = true ;
return 0 ;
}
static int F_53 ( struct V_64 * V_64 )
{
struct V_63 * V_10 = F_52 ( V_64 ) ;
struct V_1 * V_2 = V_10 -> V_65 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_5 ( V_9 , L_33 , V_33 ,
V_2 ) ;
V_9 -> V_88 = false ;
return 0 ;
}
static int T_2 F_54 ( void )
{
int V_85 ;
V_85 = F_55 ( & V_121 ) ;
return V_85 ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_121 ) ;
}
