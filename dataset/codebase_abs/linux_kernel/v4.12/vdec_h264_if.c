static unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return V_3 * ( V_1 / V_4 ) * ( V_2 / V_4 ) ;
}
static int F_2 ( struct V_5 * V_6 )
{
int V_7 = 0 ;
V_6 -> V_8 . V_9 = V_10 ;
V_7 = F_3 ( V_6 -> V_11 , & V_6 -> V_8 ) ;
if ( V_7 ) {
F_4 ( V_6 , L_1 ) ;
return V_7 ;
}
V_6 -> V_12 -> V_13 = V_6 -> V_8 . V_14 ;
return 0 ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = NULL ;
F_6 ( V_6 ) ;
V_6 -> V_12 -> V_13 = 0 ;
V_16 = & V_6 -> V_8 ;
if ( V_16 -> V_17 )
F_7 ( V_6 -> V_11 , V_16 ) ;
}
static int F_8 ( struct V_5 * V_6 , struct V_18 * V_19 )
{
int V_20 ;
int V_7 ;
struct V_15 * V_16 = NULL ;
unsigned int V_21 = F_1 ( V_19 -> V_22 , V_19 -> V_23 ) ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_16 = & V_6 -> V_25 [ V_20 ] ;
if ( V_16 -> V_17 )
F_7 ( V_6 -> V_11 , V_16 ) ;
V_16 -> V_9 = V_21 ;
V_7 = F_3 ( V_6 -> V_11 , V_16 ) ;
if ( V_7 ) {
F_4 ( V_6 , L_2 ) ;
return V_7 ;
}
V_6 -> V_12 -> V_26 [ V_20 ] = V_16 -> V_14 ;
}
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
int V_20 ;
struct V_15 * V_16 = NULL ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_6 -> V_12 -> V_26 [ V_20 ] = 0 ;
V_16 = & V_6 -> V_25 [ V_20 ] ;
if ( V_16 -> V_17 )
F_7 ( V_6 -> V_11 , V_16 ) ;
}
}
static int F_10 ( struct V_5 * V_6 , bool V_27 )
{
struct V_28 * V_29 ;
V_29 = V_27 ? & V_6 -> V_12 -> V_30 : & V_6 -> V_12 -> V_31 ;
if ( V_29 -> V_32 > V_24 ||
V_29 -> V_33 >= V_24 ||
V_29 -> V_34 >= V_24 ) {
F_4 ( V_6 , L_3 ,
V_27 ? L_4 : L_5 , V_29 -> V_32 ,
V_29 -> V_33 , V_29 -> V_34 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_11 ( struct V_5 * V_6 , struct V_36 * V_37 )
{
struct V_28 * V_29 ;
if ( V_37 ) {
if ( F_10 ( V_6 , false ) )
return;
V_29 = & V_6 -> V_12 -> V_31 ;
if ( V_29 -> V_32 == V_24 ) {
F_4 ( V_6 , L_6 ) ;
return;
}
F_12 ( V_6 , L_7 ,
V_37 -> V_38 . V_17 , ( V_39 ) V_37 -> V_38 . V_14 ) ;
V_29 -> V_40 [ V_29 -> V_34 ] . V_41 = ( V_39 ) ( V_42 ) V_37 ;
V_29 -> V_34 = ( V_29 -> V_34 == V_24 - 1 ) ?
0 : V_29 -> V_34 + 1 ;
V_29 -> V_32 ++ ;
}
}
static void F_13 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
* V_19 = V_6 -> V_12 -> V_19 ;
F_12 ( V_6 , L_8 ,
V_19 -> V_43 , V_19 -> V_44 , V_19 -> V_22 , V_19 -> V_23 ) ;
F_12 ( V_6 , L_9 , V_19 -> V_45 ,
V_19 -> V_46 , V_19 -> V_47 , V_19 -> V_48 ) ;
}
static void F_14 ( struct V_5 * V_6 , struct V_49 * V_50 )
{
V_50 -> V_51 = V_6 -> V_12 -> V_52 . V_51 ;
V_50 -> V_53 = V_6 -> V_12 -> V_52 . V_53 ;
V_50 -> V_1 = V_6 -> V_12 -> V_52 . V_1 ;
V_50 -> V_2 = V_6 -> V_12 -> V_52 . V_2 ;
F_12 ( V_6 , L_10 ,
V_50 -> V_51 , V_50 -> V_53 , V_50 -> V_1 , V_50 -> V_2 ) ;
}
static void F_15 ( struct V_5 * V_6 , unsigned int * V_54 )
{
* V_54 = V_6 -> V_12 -> V_55 . V_54 ;
F_12 ( V_6 , L_11 , * V_54 ) ;
}
static int F_16 ( struct V_56 * V_11 , unsigned long * V_57 )
{
struct V_5 * V_6 = NULL ;
int V_7 ;
V_6 = F_17 ( sizeof( * V_6 ) , V_58 ) ;
if ( ! V_6 )
return - V_59 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_60 . V_61 = V_62 ;
V_6 -> V_60 . V_63 = V_11 -> V_63 -> V_64 ;
V_6 -> V_60 . V_11 = V_11 ;
V_6 -> V_60 . V_65 = V_66 ;
V_7 = F_18 ( & V_6 -> V_60 ) ;
if ( V_7 ) {
F_4 ( V_6 , L_12 , V_7 ) ;
goto V_67;
}
V_6 -> V_12 = (struct V_68 * ) V_6 -> V_60 . V_12 ;
V_7 = F_2 ( V_6 ) ;
if ( V_7 )
goto V_69;
F_12 ( V_6 , L_13 , V_6 ) ;
* V_57 = ( unsigned long ) V_6 ;
return 0 ;
V_69:
F_19 ( & V_6 -> V_60 ) ;
V_67:
F_20 ( V_6 ) ;
return V_7 ;
}
static void F_21 ( unsigned long V_57 )
{
struct V_5 * V_6 = (struct V_5 * ) V_57 ;
F_6 ( V_6 ) ;
F_19 ( & V_6 -> V_60 ) ;
F_5 ( V_6 ) ;
F_9 ( V_6 ) ;
F_20 ( V_6 ) ;
}
static int F_22 ( unsigned char * V_70 , unsigned int V_71 )
{
if ( V_71 > 3 && V_70 [ 0 ] == 0 && V_70 [ 1 ] == 0 && V_70 [ 2 ] == 1 )
return 3 ;
if ( V_71 > 4 && V_70 [ 0 ] == 0 && V_70 [ 1 ] == 0 && V_70 [ 2 ] == 0 &&
V_70 [ 3 ] == 1 )
return 4 ;
return - 1 ;
}
static int F_23 ( unsigned long V_57 , struct V_15 * V_72 ,
struct V_36 * V_37 , bool * V_73 )
{
struct V_5 * V_6 = (struct V_5 * ) V_57 ;
struct V_74 * V_60 = & V_6 -> V_60 ;
int V_75 = 0 ;
int V_7 = 0 ;
unsigned int V_76 ;
unsigned int V_77 ;
unsigned char * V_78 ;
unsigned int V_21 ;
unsigned int V_70 [ 2 ] ;
T_1 V_41 = ( V_39 ) ( V_42 ) V_37 ;
T_1 V_79 = V_37 ? ( V_39 ) V_37 -> V_38 . V_14 : 0 ;
T_1 V_80 = V_37 ? ( V_39 ) V_37 -> V_81 . V_14 : 0 ;
F_12 ( V_6 , L_14 ,
++ V_6 -> V_82 , V_79 , V_80 , V_37 ) ;
if ( V_72 == NULL )
return F_24 ( V_60 ) ;
V_78 = ( unsigned char * ) V_72 -> V_17 ;
V_21 = V_72 -> V_9 ;
V_75 = F_22 ( V_78 , V_21 ) ;
if ( V_75 < 0 )
goto V_83;
V_76 = V_78 [ V_75 ] ;
V_77 = F_25 ( V_78 [ V_75 ] ) ;
F_12 ( V_6 , L_15 , V_6 -> V_82 ,
V_77 ) ;
if ( V_77 == V_84 ) {
V_21 -= V_75 ;
if ( V_21 > V_85 ) {
V_7 = - V_86 ;
goto V_83;
}
memcpy ( V_6 -> V_12 -> V_87 , V_78 + V_75 , V_21 ) ;
}
V_6 -> V_12 -> V_55 . V_88 = ( T_1 ) V_72 -> V_14 ;
V_6 -> V_12 -> V_55 . V_79 = V_79 ;
V_6 -> V_12 -> V_55 . V_80 = V_80 ;
V_6 -> V_12 -> V_55 . V_41 = V_41 ;
V_70 [ 0 ] = V_21 ;
V_70 [ 1 ] = V_76 ;
V_7 = F_26 ( V_60 , V_70 , 2 ) ;
if ( V_7 )
goto V_83;
* V_73 = V_6 -> V_12 -> V_55 . V_89 ;
if ( * V_73 ) {
struct V_18 V_19 ;
F_12 ( V_6 , L_16 ) ;
F_13 ( V_6 , & V_19 ) ;
if ( V_6 -> V_12 -> V_55 . V_90 ) {
V_7 = F_8 ( V_6 , & V_19 ) ;
if ( V_7 )
goto V_83;
}
}
if ( V_77 == V_91 || V_77 == V_92 ) {
V_7 = F_27 ( V_6 -> V_11 ,
V_93 ,
V_94 ) ;
if ( V_7 )
goto V_83;
F_28 ( V_60 ) ;
}
F_12 ( V_6 , L_17 , V_6 -> V_82 ,
V_77 ) ;
return 0 ;
V_83:
F_11 ( V_6 , V_37 ) ;
F_4 ( V_6 , L_18 , V_6 -> V_82 , V_7 ) ;
return V_7 ;
}
static void F_29 ( struct V_5 * V_6 ,
struct V_28 * V_29 ,
bool V_27 , struct V_36 * * V_95 )
{
struct V_36 * V_37 ;
if ( F_10 ( V_6 , V_27 ) )
return;
if ( V_29 -> V_32 == 0 ) {
F_12 ( V_6 , L_19 ,
V_27 ? L_4 : L_5 ) ;
* V_95 = NULL ;
return;
}
V_37 = (struct V_36 * )
( V_42 ) V_29 -> V_40 [ V_29 -> V_33 ] . V_41 ;
V_37 -> V_96 |= ( V_27 ? V_97 : V_98 ) ;
* V_95 = V_37 ;
F_12 ( V_6 , L_20 ,
V_27 ? L_4 : L_5 ,
V_37 -> V_96 , V_29 -> V_40 [ V_29 -> V_33 ] . V_99 ,
V_29 -> V_40 [ V_29 -> V_33 ] . V_41 ) ;
V_29 -> V_33 = ( V_29 -> V_33 == V_24 - 1 ) ?
0 : V_29 -> V_33 + 1 ;
V_29 -> V_32 -- ;
}
static int F_30 ( unsigned long V_57 ,
enum V_100 type , void * V_101 )
{
struct V_5 * V_6 = (struct V_5 * ) V_57 ;
switch ( type ) {
case V_102 :
F_29 ( V_6 , & V_6 -> V_12 -> V_30 , true , V_101 ) ;
break;
case V_103 :
F_29 ( V_6 , & V_6 -> V_12 -> V_31 , false , V_101 ) ;
break;
case V_104 :
F_13 ( V_6 , V_101 ) ;
break;
case V_105 :
F_15 ( V_6 , V_101 ) ;
break;
case V_106 :
F_14 ( V_6 , V_101 ) ;
break;
default:
F_4 ( V_6 , L_21 , type ) ;
return - V_35 ;
}
return 0 ;
}
struct V_107 * F_31 ( void )
{
return & V_108 ;
}
