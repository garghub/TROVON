static struct V_1 * F_1 ( int V_2 )
{
if ( V_2 < 0 || V_2 >= V_3 . V_4 )
return F_2 ( - V_5 ) ;
return & V_6 [ V_2 ] ;
}
static int F_3 ( void T_1 * V_7 , T_2 * V_8 , unsigned int V_9 )
{
int V_10 = 0 ;
switch ( V_9 ) {
case 8 :
* V_8 = F_4 ( V_7 ) ;
break;
case 16 :
* V_8 = F_5 ( V_7 ) ;
break;
case 32 :
* V_8 = F_6 ( V_7 ) ;
break;
case 64 :
* V_8 = F_7 ( V_7 ) ;
break;
default:
F_8 ( L_1 ,
V_9 ) ;
V_10 = - V_11 ;
break;
}
return V_10 ;
}
static int F_9 ( void T_1 * V_7 , T_2 V_8 , unsigned int V_9 )
{
int V_10 = 0 ;
switch ( V_9 ) {
case 8 :
F_10 ( V_8 , V_7 ) ;
break;
case 16 :
F_11 ( V_8 , V_7 ) ;
break;
case 32 :
F_12 ( V_8 , V_7 ) ;
break;
case 64 :
F_13 ( V_8 , V_7 ) ;
break;
default:
F_8 ( L_2 ,
V_9 ) ;
V_10 = - V_11 ;
break;
}
return V_10 ;
}
static int F_14 ( T_3 V_12 , T_3 V_13 )
{
int V_14 , V_15 ;
if ( ! V_12 )
return 0 ;
V_14 = ( V_13 & V_16 ) ? V_17
: V_18 ;
V_15 = ( V_13 & V_19 ) ? V_20
: V_21 ;
return F_15 ( NULL , V_12 , V_14 , V_15 ) ;
}
static T_4 F_16 ( int V_22 , void * V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_28 = V_23 ;
T_2 V_29 ;
T_2 V_30 ;
T_2 V_31 ;
int V_32 ;
V_27 = V_28 -> V_33 ;
F_17 ( V_28 , NULL ) ;
if ( V_27 -> V_34 . type == V_35 ) {
struct V_36 * V_37 = V_28 -> V_33 ;
T_3 V_2 = V_28 - V_6 ;
V_25 = & V_37 -> V_38 ;
V_29 = V_37 -> V_39 ;
V_30 = V_37 -> V_40 ;
V_32 = F_3 ( V_41 [ V_2 ] ,
& V_31 ,
V_25 -> V_9 ) ;
if ( V_32 )
return V_42 ;
V_32 = F_9 ( V_41 [ V_2 ] ,
( V_31 & V_29 )
| V_30 ,
V_25 -> V_9 ) ;
if ( V_32 )
return V_42 ;
}
return V_43 ;
}
struct V_1 * F_18 ( struct V_44 * V_45 ,
int V_46 )
{
struct V_47 * V_48 = V_3 . V_48 ;
struct V_1 * V_28 ;
unsigned long V_13 ;
V_28 = F_1 ( V_46 ) ;
if ( F_19 ( V_28 ) || V_28 -> V_45 ) {
F_20 ( V_48 , L_3 , V_46 ) ;
return F_2 ( - V_49 ) ;
}
F_21 ( & V_28 -> V_50 , V_13 ) ;
V_28 -> V_51 = 0 ;
V_28 -> V_52 = 0 ;
V_28 -> V_53 = NULL ;
V_28 -> V_45 = V_45 ;
F_22 ( & V_28 -> V_54 ) ;
if ( V_28 -> V_55 == V_56 && V_45 -> V_57 )
V_28 -> V_55 |= V_58 ;
F_23 ( & V_28 -> V_50 , V_13 ) ;
if ( V_59 [ V_46 ] > 0 ) {
int V_60 ;
V_60 = F_24 ( V_48 , V_59 [ V_46 ] ,
F_16 , 0 , V_61 , V_28 ) ;
if ( F_25 ( V_60 ) ) {
F_20 ( V_48 , L_4 ,
V_59 [ V_46 ] ) ;
F_26 ( V_28 ) ;
V_28 = F_2 ( V_60 ) ;
}
}
return V_28 ;
}
void F_26 ( struct V_1 * V_28 )
{
T_3 V_2 = V_28 - V_6 ;
unsigned long V_13 ;
if ( ! V_28 || ! V_28 -> V_45 )
return;
if ( V_2 >= V_3 . V_4 ) {
F_8 ( L_5 ) ;
return;
}
if ( V_59 [ V_2 ] > 0 )
F_27 ( V_28 -> V_62 -> V_48 , V_59 [ V_2 ] , V_28 ) ;
F_21 ( & V_28 -> V_50 , V_13 ) ;
V_28 -> V_45 = NULL ;
V_28 -> V_53 = NULL ;
if ( V_28 -> V_55 == ( V_56 | V_58 ) )
V_28 -> V_55 = V_56 ;
F_23 ( & V_28 -> V_50 , V_13 ) ;
}
static int F_28 ( struct V_1 * V_28 , void * V_63 )
{
struct V_26 * V_27 = V_28 -> V_33 ;
struct V_24 * V_64 ;
T_2 V_65 ;
T_2 V_66 ;
T_2 V_67 ;
T_3 V_2 = V_28 - V_6 ;
int V_32 = 0 ;
if ( V_2 >= V_3 . V_4 ) {
F_8 ( L_6 ) ;
return - V_5 ;
}
V_64 = & V_27 -> V_68 ;
V_65 = V_27 -> V_69 ;
V_67 = V_27 -> V_70 ;
if ( V_71 [ V_2 ] ) {
V_32 = F_3 ( V_71 [ V_2 ] , & V_66 ,
V_64 -> V_9 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_9 ( V_71 [ V_2 ] ,
( V_66 & V_65 ) | V_67 ,
V_64 -> V_9 ) ;
} else {
V_32 = F_29 ( & V_66 , V_64 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_30 ( ( V_66 & V_65 ) | V_67 ,
V_64 ) ;
}
return V_32 ;
}
static int F_31 ( struct V_72 * V_34 ,
const unsigned long V_73 )
{
struct V_26 * V_27 ;
if ( V_3 . V_4 <= V_74 ) {
V_27 = (struct V_26 * ) V_34 ;
if ( ( V_27 -> V_34 . type !=
V_75 )
&& ( V_27 -> V_34 . type !=
V_35 ) ) {
F_32 ( L_7 ) ;
return - V_76 ;
}
}
return 0 ;
}
static int F_33 ( int V_2 ,
struct V_26 * V_27 )
{
V_59 [ V_2 ] = F_14 ( V_27 -> V_77 ,
( T_3 ) V_27 -> V_13 ) ;
if ( V_59 [ V_2 ] <= 0 ) {
F_32 ( L_8 ,
V_27 -> V_77 ) ;
return - V_76 ;
}
if ( V_27 -> V_34 . type
== V_35 ) {
struct V_36 * V_37 = ( void * ) V_27 ;
V_41 [ V_2 ] = F_34 (
V_37 -> V_38 . V_78 ,
V_37 -> V_38 . V_9 / 8 ) ;
if ( ! V_41 [ V_2 ] ) {
F_32 ( L_9 ) ;
return - V_79 ;
}
}
return 0 ;
}
static int T_5 F_35 ( void )
{
struct V_80 * V_81 ;
struct V_72 * V_82 ;
struct V_83 * V_84 ;
int V_85 , V_86 , V_60 ;
int V_87 = 0 ;
T_6 V_88 = V_89 ;
V_88 = F_36 ( V_90 , 0 , & V_81 ) ;
if ( F_37 ( V_88 ) || ! V_81 )
return - V_91 ;
V_85 = F_38 ( V_90 ,
sizeof( struct V_83 ) ,
V_75 ,
F_31 , V_74 ) ;
V_87 += ( V_85 > 0 ) ? V_85 : 0 ;
V_85 = F_38 ( V_90 ,
sizeof( struct V_83 ) ,
V_35 ,
F_31 , V_74 ) ;
V_87 += ( V_85 > 0 ) ? V_85 : 0 ;
if ( V_87 == 0 || V_87 >= V_74 ) {
F_32 ( L_10 ) ;
return - V_76 ;
}
V_6 = F_39 ( sizeof( struct V_1 ) *
V_87 , V_92 ) ;
if ( ! V_6 ) {
F_32 ( L_11 ) ;
return - V_79 ;
}
V_71 = F_40 ( V_87 , sizeof( void * ) , V_92 ) ;
if ( ! V_71 ) {
V_60 = - V_79 ;
goto V_93;
}
V_41 = F_40 ( V_87 , sizeof( void * ) , V_92 ) ;
if ( ! V_41 ) {
V_60 = - V_79 ;
goto V_94;
}
V_59 = F_40 ( V_87 , sizeof( int ) , V_92 ) ;
if ( ! V_59 ) {
V_60 = - V_79 ;
goto V_95;
}
V_82 = (struct V_72 * ) (
( unsigned long ) V_81 + sizeof( struct V_83 ) ) ;
V_84 = (struct V_83 * ) V_81 ;
if ( V_84 -> V_13 & V_96 )
V_3 . V_97 = true ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
struct V_24 * V_98 ;
struct V_26 * V_27 ;
V_6 [ V_86 ] . V_33 = V_82 ;
V_27 = (struct V_26 * ) V_82 ;
if ( V_3 . V_97 ) {
V_60 = F_33 ( V_86 , V_27 ) ;
if ( V_60 < 0 )
goto V_99;
}
V_98 = & V_27 -> V_68 ;
if ( V_98 -> V_100 == V_101 )
V_71 [ V_86 ] = F_34 ( V_98 -> V_78 ,
V_98 -> V_9 / 8 ) ;
V_82 = (struct V_72 * )
( ( unsigned long ) V_82 + V_82 -> V_102 ) ;
}
V_3 . V_4 = V_87 ;
F_41 ( L_12 , V_3 . V_4 ) ;
return 0 ;
V_99:
F_42 ( V_59 ) ;
V_95:
F_42 ( V_41 ) ;
V_94:
F_42 ( V_71 ) ;
V_93:
F_42 ( V_6 ) ;
return V_60 ;
}
static int F_43 ( struct V_103 * V_104 )
{
int V_32 = 0 ;
V_3 . V_105 = V_6 ;
V_3 . V_106 = & V_107 ;
V_3 . V_48 = & V_104 -> V_48 ;
F_41 ( L_13 ) ;
V_32 = F_44 ( & V_3 ) ;
if ( V_32 ) {
F_32 ( L_14 , V_32 ) ;
V_32 = - V_91 ;
}
return V_32 ;
}
static int T_5 F_45 ( void )
{
int V_32 ;
struct V_103 * V_108 ;
if ( V_109 )
return - V_91 ;
V_32 = F_35 () ;
if ( V_32 ) {
F_8 ( L_15 ) ;
return - V_91 ;
}
V_108 = F_46 ( & V_110 ,
F_43 , NULL , 0 , NULL , 0 ) ;
if ( F_19 ( V_108 ) ) {
F_8 ( L_16 ) ;
return F_47 ( V_108 ) ;
}
return 0 ;
}
