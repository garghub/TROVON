static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
int V_7 = 0 ;
F_2 ( & V_2 -> V_8 -> V_2 , L_1 , V_9 , F_3 ( & V_5 -> V_10 ) , V_3 ) ;
if ( ( V_3 && F_4 ( 1 , & V_5 -> V_10 ) == 1 ) || ( ! V_3 && F_5 ( & V_5 -> V_10 ) ) ) {
V_7 = F_6 ( V_2 -> V_8 ) ;
V_2 -> V_8 -> V_11 = V_3 ;
if ( ! V_7 )
F_7 ( V_2 -> V_8 ) ;
}
return 0 ;
}
static int F_8 ( struct V_12 * V_8 , int V_13 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
return F_1 ( V_2 , V_13 ) ;
}
static int F_10 ( struct V_14 * V_15 , T_1 V_16 , T_2 V_17 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
if ( V_17 == V_18 )
V_5 -> V_19 |= V_20 ;
else
if ( V_17 >= 512 )
return - V_21 ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 , T_1 V_16 , T_2 V_17 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
if ( V_17 == V_18 )
V_5 -> V_19 &= ~ V_20 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_12 * V_8 , T_3 V_22 )
{
struct V_23 * V_24 = F_14 ( V_8 -> V_2 . V_24 ) ;
const struct V_25 * V_26 ;
struct V_27 * V_5 ;
int V_28 ;
V_28 = F_15 ( V_2 -> V_29 ,
V_8 -> V_30 -> V_31 . V_32 ,
V_22 ) ;
if ( V_28 )
return V_28 ;
V_26 = F_16 ( V_8 , V_24 -> V_33 ) ;
if ( ! V_26 )
return - V_34 ;
V_5 = (struct V_27 * ) V_26 -> V_27 ;
if ( V_5 != V_2 -> V_27 ) {
F_2 ( & V_8 -> V_2 , L_2 ,
V_5 -> V_35 ) ;
V_2 -> V_27 = V_5 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_12 * V_8 )
{
struct V_36 * V_37 ;
struct V_23 * V_38 = F_18 ( - V_34 ) ;
int V_28 = - V_34 ;
T_3 V_39 = 1 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
if ( F_19 ( V_8 ) == V_40 ) {
V_39 = V_41 ;
V_28 = F_13 ( V_2 , V_8 , V_40 ) ;
if ( V_28 )
goto V_42;
V_28 = - V_34 ;
}
if ( ! F_20 ( V_8 -> V_30 ) )
goto V_42;
V_28 = F_21 ( V_2 , V_8 , V_39 , V_2 -> V_27 -> V_6 ) ;
if ( V_28 )
goto V_42;
V_37 = V_5 -> V_37 ;
if ( V_37 -> V_43 && V_2 -> V_13 )
V_38 = F_22 ( V_37 -> V_44 ,
& V_2 -> V_13 -> V_31 ,
F_23 ( V_37 -> V_43 -> V_45 ) ,
F_8 ) ;
if ( F_24 ( V_38 ) ) {
V_28 = F_25 ( V_38 ) ;
F_26 ( V_2 , V_8 ) ;
goto V_42;
}
V_2 -> V_13 = NULL ;
V_5 -> V_38 = V_38 ;
V_2 -> V_46 -> V_19 |= V_47 ;
V_2 -> V_46 -> V_48 |= V_49 | V_50 ;
V_2 -> V_46 -> V_51 = & V_52 ;
V_42:
return V_28 ;
}
static void F_27 ( struct V_1 * V_2 , struct V_12 * V_8 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_36 * V_37 = V_5 -> V_37 ;
if ( V_5 -> V_38 && V_5 -> V_38 -> V_53 )
V_5 -> V_38 -> V_53 ( V_37 -> V_44 ) ;
V_5 -> V_38 = NULL ;
F_26 ( V_2 , V_8 ) ;
}
static bool F_28 ( T_1 V_16 )
{
switch ( V_16 ) {
case F_29 ( V_54 ) :
case F_29 ( V_55 ) :
return true ;
}
return false ;
}
static struct V_56 * F_30 ( struct V_1 * V_2 , struct V_56 * V_57 , T_4 V_19 )
{
struct V_56 * V_58 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_36 * V_37 = V_5 -> V_37 ;
T_5 V_59 = F_31 ( V_60 ) ;
T_2 V_61 = 0 ;
bool V_62 ;
T_3 * V_63 ;
if ( ! V_37 )
goto error;
if ( V_57 ) {
if ( V_57 -> V_64 <= V_65 )
goto error;
F_32 ( V_57 ) ;
if ( F_33 ( V_57 , & V_61 ) < 0 && V_57 -> V_64 > V_66 &&
F_34 ( V_57 , & V_61 ) == 0 ) {
V_62 = F_28 ( F_35 ( V_57 ) -> V_67 ) ;
F_36 ( V_57 , V_66 ) ;
} else {
V_62 = F_28 ( F_37 ( V_57 ) -> V_68 ) ;
F_36 ( V_57 , V_65 ) ;
}
if ( V_5 -> V_19 & V_20 ) {
if ( ! V_61 )
goto error;
if ( V_61 == V_18 )
V_61 = 0 ;
}
switch ( V_61 & 0x0f00 ) {
case 0x0000 :
if ( ! V_62 )
goto error;
V_63 = ( T_3 * ) & V_59 ;
V_63 [ 3 ] = V_61 ;
break;
case 0x0100 :
if ( V_62 )
goto error;
V_59 = F_31 ( V_69 ) ;
V_63 = ( T_3 * ) & V_59 ;
V_63 [ 3 ] = V_61 ;
break;
default:
F_38 ( V_2 , V_70 , V_2 -> V_46 ,
L_3 , V_61 ) ;
goto error;
}
}
F_39 ( & V_37 -> V_71 ) ;
V_58 = F_40 ( V_2 , V_57 , V_59 ) ;
F_41 ( & V_37 -> V_71 ) ;
return V_58 ;
error:
if ( V_57 )
F_42 ( V_57 ) ;
return NULL ;
}
static void F_43 ( struct V_1 * V_2 , T_3 * V_72 , T_2 V_61 )
{
struct V_73 * V_74 = ( void * ) V_72 ;
struct V_75 * V_76 = ( void * ) ( V_74 + 1 ) ;
struct V_14 * V_15 ;
struct V_77 * V_78 ;
bool V_79 ;
if ( ! F_44 ( & V_74 -> V_80 ) ||
! ( F_45 ( & V_74 -> V_81 ) & V_82 ) )
return;
F_46 () ;
if ( V_61 ) {
V_15 = F_47 ( V_2 -> V_46 , F_29 ( V_83 ) ,
V_61 ) ;
if ( ! V_15 ) {
F_48 () ;
return;
}
} else {
V_15 = V_2 -> V_46 ;
}
F_49 ( V_15 ) ;
F_48 () ;
V_78 = F_50 ( V_15 ) ;
if ( ! V_78 )
goto V_84;
V_79 = ! ! V_78 -> V_85 . V_86 ;
F_51 ( V_78 ) ;
V_87 -> V_88 ( V_15 , & V_74 -> V_81 , & V_76 -> V_89 ,
V_79 ,
true ,
false ,
true ) ;
V_84:
F_52 ( V_15 ) ;
}
static bool F_53 ( T_3 * V_72 , T_6 V_64 )
{
struct V_73 * V_74 = ( void * ) V_72 ;
struct V_75 * V_76 = ( void * ) ( V_74 + 1 ) ;
return ( V_64 >= sizeof( struct V_73 ) + sizeof( struct V_75 ) &&
V_74 -> V_90 == V_91 &&
V_76 -> V_92 . V_93 == 0 &&
V_76 -> V_92 . V_94 == V_95 ) ;
}
static struct V_56 * F_54 ( struct V_1 * V_2 , T_3 * V_72 , T_6 V_64 , T_2 V_61 )
{
T_1 V_16 = F_29 ( V_96 ) ;
struct V_56 * V_57 = NULL ;
if ( V_61 < 256 || V_61 == V_18 ) {
if ( V_64 < sizeof( struct V_97 ) )
goto V_42;
switch ( * V_72 & 0xf0 ) {
case 0x40 :
V_16 = F_29 ( V_54 ) ;
break;
case 0x60 :
if ( F_53 ( V_72 , V_64 ) )
F_43 ( V_2 , V_72 , V_61 ) ;
V_16 = F_29 ( V_55 ) ;
break;
default:
goto V_42;
}
}
V_57 = F_55 ( V_2 -> V_46 , V_64 + V_65 ) ;
if ( ! V_57 )
goto V_42;
F_56 ( V_57 , V_65 ) ;
F_32 ( V_57 ) ;
F_37 ( V_57 ) -> V_68 = V_16 ;
F_57 ( F_37 ( V_57 ) -> V_98 ) ;
memcpy ( F_37 ( V_57 ) -> V_99 , V_2 -> V_46 -> V_100 , V_101 ) ;
F_58 ( V_57 , V_72 , V_64 ) ;
if ( V_61 )
F_59 ( V_57 , F_29 ( V_83 ) , V_61 ) ;
V_42:
return V_57 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_56 * V_102 )
{
struct V_56 * V_57 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_36 * V_37 = V_5 -> V_37 ;
int V_64 ;
int V_103 ;
int V_104 ;
int V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
int V_110 ;
int V_111 = 50 ;
T_7 V_112 = 0 ;
T_3 * V_63 ;
T_2 V_61 ;
V_110 = F_61 ( V_37 , V_102 ) ;
if ( V_110 < 0 )
goto error;
V_113:
V_103 = F_62 ( V_102 , V_110 ) ;
if ( V_103 < 0 )
goto error;
V_107 = (struct V_106 * ) ( V_102 -> V_6 + V_110 ) ;
switch ( V_107 -> V_114 & F_31 ( 0x00ffffff ) ) {
case F_31 ( V_60 ) :
V_63 = ( T_3 * ) & V_107 -> V_114 ;
V_61 = V_63 [ 3 ] ;
if ( ! V_61 && V_5 -> V_19 & V_20 )
V_61 = V_18 ;
break;
case F_31 ( V_69 ) :
V_63 = ( T_3 * ) & V_107 -> V_114 ;
V_61 = V_63 [ 3 ] + 256 ;
break;
default:
F_63 ( V_2 , V_115 , V_2 -> V_46 ,
L_4 ,
F_64 ( V_107 -> V_114 ) ) ;
goto V_116;
}
V_109 = V_107 -> V_109 ;
for ( V_104 = 0 ; V_104 < V_103 ; V_104 ++ , V_109 ++ ) {
V_105 = F_23 ( V_109 -> V_117 ) ;
V_64 = F_23 ( V_109 -> V_118 ) ;
if ( ( V_105 == 0 ) || ( V_64 == 0 ) ) {
if ( ! V_104 )
goto V_116;
break;
}
if ( ( ( V_105 + V_64 ) > V_102 -> V_64 ) || ( V_64 > V_37 -> V_119 ) ) {
F_63 ( V_2 , V_115 , V_2 -> V_46 ,
L_5 ,
V_104 , V_105 , V_64 , V_102 ) ;
if ( ! V_104 )
goto V_116;
break;
} else {
V_57 = F_54 ( V_2 , V_102 -> V_6 + V_105 , V_64 , V_61 ) ;
if ( ! V_57 )
goto error;
F_65 ( V_2 , V_57 ) ;
V_112 += V_64 ;
}
}
V_116:
V_110 = F_23 ( V_107 -> V_120 ) ;
if ( V_110 && V_111 -- )
goto V_113;
V_37 -> V_121 += V_102 -> V_64 - V_112 ;
V_37 -> V_122 ++ ;
return 1 ;
error:
return 0 ;
}
static int F_66 ( struct V_12 * V_8 , T_8 V_123 )
{
int V_28 = - V_34 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_36 * V_37 = V_5 -> V_37 ;
if ( ! V_37 )
goto error;
V_28 = F_67 ( V_8 , V_123 ) ;
if ( V_28 < 0 )
goto error;
if ( V_8 == V_37 -> V_44 && V_5 -> V_38 && V_5 -> V_38 -> V_124 )
V_28 = V_5 -> V_38 -> V_124 ( V_8 , V_123 ) ;
if ( V_28 < 0 )
F_68 ( V_8 ) ;
error:
return V_28 ;
}
static int F_69 ( struct V_12 * V_8 )
{
int V_28 = 0 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_36 * V_37 = V_5 -> V_37 ;
bool V_125 = ( V_8 == V_37 -> V_44 && V_5 -> V_38 && V_5 -> V_38 -> V_126 ) ;
if ( V_125 )
V_28 = V_5 -> V_38 -> V_126 ( V_8 ) ;
if ( V_28 < 0 )
goto V_42;
V_28 = F_68 ( V_8 ) ;
if ( V_28 < 0 && V_125 )
V_5 -> V_38 -> V_124 ( V_8 , V_127 ) ;
V_42:
return V_28 ;
}
