static unsigned int
F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
if ( V_3 [ V_2 ] == V_1 )
return V_2 ;
}
return - V_4 ;
}
int
F_3 ( struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 , V_9 , V_10 ;
int V_11 ;
V_10 = 0 ;
do {
V_11 = F_4 ( V_6 -> V_12 , & V_8 ,
V_13 , 0 ) ;
} while ( V_11 == - V_14 && ++ V_10 < 3 );
if ( V_11 < 0 )
goto V_15;
V_10 = 0 ;
do {
V_11 = F_4 ( V_6 -> V_12 , & V_9 ,
V_16 , 0 ) ;
} while ( V_11 == - V_14 && ++ V_10 < 3 );
if ( V_11 < 0 )
goto V_15;
* V_7 = V_9 ;
if ( V_9 == V_8 )
goto V_15;
V_11 = F_5 ( V_6 -> V_12 , V_9 ,
V_16 , 0 ) ;
V_15:
return V_11 ;
}
int
F_6 ( struct V_5 * V_6 , unsigned int V_1 )
{
int V_11 ;
V_11 = F_5 ( V_6 -> V_12 , V_1 ,
V_13 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_5 ( V_6 -> V_12 , V_1 ,
V_16 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
F_7 ( 300 ) ;
V_15:
return V_11 ;
}
int F_8 ( struct V_5 * V_6 ,
enum V_17 * V_18 )
{
const struct V_19 * V_20 = V_6 -> V_21 -> clock ;
T_1 V_22 [ V_23 ] , V_24 [ 7 ] ;
unsigned int V_25 ;
enum V_26 type ;
int V_11 = 0 ;
if ( V_20 ) {
V_11 = V_20 -> V_27 ( V_6 , & V_25 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_1 , V_11 ) ;
goto V_15;
}
if ( V_25 >= V_20 -> V_29 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_2 ,
V_25 , V_20 -> V_29 - 1 ) ;
V_11 = - V_30 ;
goto V_15;
}
* V_18 = V_20 -> V_31 [ V_25 ] ;
goto V_15;
}
if ( V_6 -> V_32 < 0 ) {
* V_18 = V_33 ;
goto V_15;
}
F_10 ( V_22 , V_34 ,
V_6 -> V_32 ) ;
V_11 = F_11 ( V_6 -> V_12 , V_22 , V_24 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_3 ,
V_6 -> V_32 , V_11 ) ;
goto V_15;
}
if ( V_24 [ 0 ] == 0xff ) {
* V_18 = V_33 ;
goto V_15;
}
if ( V_24 [ 0 ] == V_35 ) {
if ( V_24 [ 1 ] == V_36 &&
V_24 [ 2 ] == 0x0c ) {
* V_18 = V_33 ;
goto V_15;
}
} else if ( V_24 [ 1 ] == V_37 ) {
if ( V_24 [ 2 ] == V_38 ) {
if ( V_24 [ 3 ] == 0x00 ) {
* V_18 = V_39 ;
goto V_15;
} else {
* V_18 = V_40 ;
goto V_15;
}
} else if ( V_24 [ 2 ] == V_41 ) {
F_12 ( V_22 ,
V_34 ,
V_41 ,
V_24 [ 3 ] ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 ,
& type ) ;
if ( V_11 < 0 )
goto V_15;
if ( type == V_42 ) {
* V_18 = V_40 ;
goto V_15;
} else if ( type == V_43 ) {
* V_18 = V_40 ;
goto V_15;
} else if ( type == V_44 ) {
* V_18 = V_33 ;
goto V_15;
}
}
}
V_11 = - V_30 ;
V_15:
return V_11 ;
}
static unsigned int
F_14 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
unsigned int V_47 , V_48 , V_49 , V_50 ;
unsigned int V_51 , V_52 , V_53 ;
unsigned int V_54 , V_55 , V_56 ;
T_1 * V_57 , V_22 [ V_23 ] , type ;
enum V_58 V_59 ;
int V_11 ;
V_57 = F_15 ( 256 , V_60 ) ;
if ( V_57 == NULL )
return - V_61 ;
if ( V_46 == & V_6 -> V_62 )
V_59 = V_35 ;
else
V_59 = V_34 ;
F_12 ( V_22 , V_59 , V_38 , 0 ) ;
V_11 = F_16 ( V_6 -> V_12 , V_22 , V_57 , 256 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_4 ,
( V_59 == V_34 ) ? L_5 : L_6 ,
V_11 ) ;
goto V_15;
}
V_56 = 0 ;
V_51 = 0 ;
V_52 = 0 ;
V_48 = V_57 [ V_56 ++ ] ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
F_12 ( V_22 , V_59 ,
V_38 , 0 ) ;
V_11 = F_17 ( V_6 -> V_12 , V_22 ,
V_47 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_7 ,
( V_59 == V_34 ) ? L_5 :
L_6 ,
V_11 ) ;
goto V_15;
}
if ( type == 0xff ) {
V_11 = - V_63 ;
goto V_15;
}
V_50 = V_57 [ V_56 ++ ] ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
V_54 = V_57 [ V_56 ++ ] - 1 ;
V_55 = V_57 [ V_56 ++ ] - 1 ;
if ( V_55 >= V_50 )
V_55 = V_49 ;
switch ( type ) {
case 0x0a :
if ( ( V_52 > 0 ) && ( V_54 != V_52 ) ) {
V_11 = - V_63 ;
goto V_15;
}
F_18 ( V_46 , V_54 ) ;
V_52 = V_54 ;
break;
case 0x01 :
case 0x02 :
case 0x03 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
default:
V_53 = V_51 + V_55 ;
if ( V_53 >= V_64 ) {
V_11 = - V_63 ;
goto V_15;
}
F_19 ( V_46 , V_53 ,
V_54 ) ;
break;
}
}
if ( type != 0x0a )
V_51 += V_50 ;
else
V_52 += V_50 ;
}
V_15:
F_20 ( V_57 ) ;
return V_11 ;
}
static int
F_21 ( struct V_5 * V_6 )
{
int V_11 ;
V_11 = F_22 ( & V_6 -> V_65 ,
V_6 -> V_12 , V_66 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_22 ( & V_6 -> V_67 ,
V_6 -> V_12 , V_68 , 0 ) ;
if ( V_11 < 0 )
F_23 ( & V_6 -> V_65 ) ;
V_15:
return V_11 ;
}
static int
F_24 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
struct V_69 * V_70 ;
bool V_71 ;
int V_11 ;
if ( V_46 == & V_6 -> V_62 )
V_70 = & V_6 -> V_67 ;
else
V_70 = & V_6 -> V_65 ;
V_11 = F_25 ( V_70 , & V_71 ) ;
if ( ( V_11 >= 0 ) && V_71 && ! F_26 ( V_46 ) ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_8 ,
( V_70 -> V_72 == V_68 ) ? 'o' : 'i' ,
V_70 -> V_73 ) ;
V_11 = - V_74 ;
}
return V_11 ;
}
static int
F_27 ( struct V_5 * V_6 , unsigned int V_1 )
{
int V_75 , V_76 , V_77 , V_11 = 0 ;
if ( V_6 -> V_78 )
goto V_15;
V_75 = F_1 ( V_1 ) ;
V_76 = V_6 -> V_79 [ V_75 ] . V_51 ;
V_77 = V_6 -> V_79 [ V_75 ] . V_52 ;
V_11 = F_28 ( & V_6 -> V_62 , V_1 ,
V_76 , V_77 * 8 ,
false ) ;
if ( V_11 < 0 )
goto V_15;
V_76 = V_6 -> V_80 [ V_75 ] . V_51 ;
V_77 = V_6 -> V_80 [ V_75 ] . V_52 ;
V_11 = F_28 ( & V_6 -> V_81 , V_1 ,
V_76 , V_77 * 8 ,
false ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_29 ( & V_6 -> V_67 ,
F_30 ( & V_6 -> V_62 ) ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_29 ( & V_6 -> V_65 ,
F_30 ( & V_6 -> V_81 ) ) ;
if ( V_11 < 0 ) {
F_31 ( & V_6 -> V_67 ) ;
goto V_15;
}
V_6 -> V_78 = true ;
V_15:
return V_11 ;
}
static void
F_32 ( struct V_5 * V_6 )
{
F_31 ( & V_6 -> V_65 ) ;
F_31 ( & V_6 -> V_67 ) ;
V_6 -> V_78 = false ;
if ( V_6 -> V_82 != NULL )
F_7 ( 200 ) ;
}
static void
F_33 ( struct V_5 * V_6 )
{
F_23 ( & V_6 -> V_65 ) ;
F_23 ( & V_6 -> V_67 ) ;
}
static int
F_34 ( struct V_5 * V_6 , enum V_83 * V_84 )
{
enum V_17 V_18 ;
int V_11 ;
V_11 = F_8 ( V_6 , & V_18 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_18 ) {
case V_33 :
case V_40 :
* V_84 = V_85 ;
break;
default:
case V_39 :
* V_84 = 0 ;
break;
}
return 0 ;
}
static int
F_35 ( struct V_5 * V_6 , struct V_45 * V_86 ,
unsigned int V_1 )
{
struct V_69 * V_70 ;
int V_11 = 0 ;
if ( V_86 == & V_6 -> V_81 )
V_70 = & V_6 -> V_65 ;
else
V_70 = & V_6 -> V_67 ;
if ( V_6 -> V_82 == NULL ) {
V_11 = F_14 ( V_6 , V_86 ) ;
if ( V_11 < 0 )
goto V_15;
}
V_11 = F_36 ( V_86 ,
V_70 -> V_87 . V_88 ,
V_70 -> V_89 ) ;
V_15:
return V_11 ;
}
int F_37 ( struct V_5 * V_6 )
{
int V_11 ;
V_11 = F_21 ( V_6 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_38 ( & V_6 -> V_62 , V_6 -> V_12 ,
V_90 , V_91 ) ;
if ( V_11 < 0 ) {
F_39 ( & V_6 -> V_62 ) ;
F_33 ( V_6 ) ;
goto V_15;
}
F_40 ( & V_6 -> V_92 ) ;
V_6 -> V_62 . V_93 |= V_94 ;
if ( V_6 -> V_95 > 2 )
V_6 -> V_62 . V_93 |= V_96 |
V_97 ;
if ( V_6 -> V_82 )
V_6 -> V_62 . V_93 |= V_96 ;
V_11 = F_38 ( & V_6 -> V_81 , V_6 -> V_12 ,
V_98 , V_91 ) ;
if ( V_11 < 0 ) {
F_39 ( & V_6 -> V_62 ) ;
F_39 ( & V_6 -> V_81 ) ;
F_33 ( V_6 ) ;
}
V_15:
return V_11 ;
}
int F_41 ( struct V_5 * V_6 , unsigned int V_1 )
{
const struct V_99 * V_100 = V_6 -> V_21 -> V_1 ;
struct V_45 * V_101 , * V_102 ;
enum V_83 V_84 ;
unsigned int V_7 ;
bool V_103 = false ;
int V_11 = 0 ;
if ( F_42 ( & V_6 -> V_62 ) ) {
if ( F_43 ( & V_6 -> V_92 ) )
F_44 ( & V_6 -> V_92 ) ;
V_103 = ( F_45 (
& V_6 -> V_92 ,
F_46 ( V_104 ) ) > 0 ) ;
}
F_47 ( & V_6 -> V_105 ) ;
if ( F_48 ( & V_6 -> V_106 ) == 0 )
goto V_15;
V_11 = F_34 ( V_6 , & V_84 ) ;
if ( V_11 < 0 )
goto V_15;
if ( V_84 == V_85 ) {
V_101 = & V_6 -> V_62 ;
V_102 = & V_6 -> V_81 ;
} else {
V_101 = & V_6 -> V_81 ;
V_102 = & V_6 -> V_62 ;
}
V_11 = F_24 ( V_6 , V_101 ) ;
if ( V_11 < 0 )
goto V_15;
if ( F_42 ( V_101 ) )
F_49 ( V_101 ) ;
if ( F_42 ( V_102 ) )
F_49 ( V_102 ) ;
if ( ! V_103 &&
! F_26 ( V_101 ) && ! F_26 ( V_102 ) )
F_32 ( V_6 ) ;
V_11 = V_100 -> V_27 ( V_6 , & V_7 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_9 , V_11 ) ;
goto V_15;
}
if ( V_1 == 0 )
V_1 = V_7 ;
if ( V_1 != V_7 ) {
F_49 ( V_101 ) ;
F_49 ( V_102 ) ;
F_32 ( V_6 ) ;
}
if ( ! F_26 ( V_101 ) ) {
F_50 ( V_84 , V_101 , V_102 ) ;
V_6 -> V_101 = V_101 ;
if ( V_6 -> V_82 == NULL ) {
V_11 = V_100 -> V_107 ( V_6 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_10 ,
V_11 ) ;
goto V_15;
}
}
V_11 = F_27 ( V_6 , V_1 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_35 ( V_6 , V_101 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_11 , V_11 ) ;
F_32 ( V_6 ) ;
goto V_15;
}
if ( V_6 -> V_82 != NULL ) {
V_11 = V_100 -> V_107 ( V_6 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_12 ,
V_11 ) ;
F_49 ( V_101 ) ;
F_32 ( V_6 ) ;
goto V_15;
}
}
if ( ! F_51 ( V_101 , V_108 ) ) {
F_49 ( V_101 ) ;
F_32 ( V_6 ) ;
V_11 = - V_109 ;
goto V_15;
}
}
if ( ! F_26 ( V_102 ) ) {
V_11 = F_35 ( V_6 , V_102 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_13 , V_11 ) ;
F_49 ( V_101 ) ;
F_32 ( V_6 ) ;
goto V_15;
}
if ( ! F_51 ( V_102 , V_108 ) ) {
F_49 ( V_102 ) ;
F_49 ( V_101 ) ;
F_32 ( V_6 ) ;
V_11 = - V_109 ;
}
}
V_15:
F_52 ( & V_6 -> V_105 ) ;
return V_11 ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_45 * V_101 , * V_102 ;
if ( V_6 -> V_101 == & V_6 -> V_81 ) {
V_102 = & V_6 -> V_62 ;
V_101 = & V_6 -> V_81 ;
} else {
V_102 = & V_6 -> V_81 ;
V_101 = & V_6 -> V_62 ;
}
F_47 ( & V_6 -> V_105 ) ;
if ( F_48 ( & V_6 -> V_106 ) == 0 ) {
F_54 ( V_101 ) ;
F_49 ( V_101 ) ;
F_54 ( V_102 ) ;
F_49 ( V_102 ) ;
F_32 ( V_6 ) ;
}
F_52 ( & V_6 -> V_105 ) ;
}
void F_55 ( struct V_5 * V_6 )
{
F_47 ( & V_6 -> V_105 ) ;
if ( ( F_56 ( & V_6 -> V_65 ) < 0 ) ||
( F_56 ( & V_6 -> V_67 ) < 0 ) ) {
F_54 ( & V_6 -> V_81 ) ;
F_54 ( & V_6 -> V_62 ) ;
F_49 ( & V_6 -> V_81 ) ;
F_49 ( & V_6 -> V_62 ) ;
F_32 ( V_6 ) ;
} else {
F_57 ( & V_6 -> V_81 ) ;
F_57 ( & V_6 -> V_62 ) ;
}
if ( ! F_43 ( & V_6 -> V_92 ) )
F_58 ( & V_6 -> V_92 ) ;
F_52 ( & V_6 -> V_105 ) ;
}
void F_59 ( struct V_5 * V_6 )
{
F_39 ( & V_6 -> V_81 ) ;
F_39 ( & V_6 -> V_62 ) ;
F_33 ( V_6 ) ;
}
static int
F_60 ( T_1 * V_57 , unsigned int V_110 ,
struct V_111 * V_112 )
{
unsigned int V_2 , V_113 , V_50 , V_114 ;
if ( ( V_57 [ 0 ] != 0x90 ) || ( V_57 [ 1 ] != 0x40 ) )
return - V_63 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_115 ) ; V_2 ++ ) {
if ( V_57 [ 2 ] == V_115 [ V_2 ] )
break;
}
if ( V_2 == F_2 ( V_115 ) )
return - V_63 ;
memset ( & V_112 [ V_2 ] , 0 , sizeof( struct V_111 ) ) ;
for ( V_113 = 0 ; V_113 < V_57 [ 4 ] ; V_113 ++ ) {
V_50 = V_57 [ 5 + V_113 * 2 ] ;
V_114 = V_57 [ 6 + V_113 * 2 ] ;
switch ( V_114 ) {
case 0x00 :
case 0x06 :
V_112 [ V_2 ] . V_51 += V_50 ;
break;
case 0x0d :
V_112 [ V_2 ] . V_52 += V_50 ;
break;
case 0x01 :
case 0x02 :
case 0x03 :
case 0x04 :
case 0x05 :
case 0x07 :
case 0x0c :
case 0x08 :
case 0x09 :
case 0x0a :
case 0x0b :
case 0x40 :
case 0xff :
default:
return - V_63 ;
}
}
if ( V_112 [ V_2 ] . V_51 > V_64 ||
V_112 [ V_2 ] . V_52 > V_116 )
return - V_63 ;
return 0 ;
}
static int
F_61 ( struct V_5 * V_6 , enum V_58 V_59 ,
unsigned short V_117 )
{
T_1 * V_57 ;
struct V_111 * V_118 ;
unsigned int V_110 , V_119 ;
T_1 V_22 [ V_23 ] ;
int V_11 ;
V_57 = F_62 ( V_120 , V_60 ) ;
if ( V_57 == NULL )
return - V_61 ;
if ( V_59 == V_34 )
V_118 = V_6 -> V_80 ;
else
V_118 = V_6 -> V_79 ;
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ ) {
V_110 = V_120 ;
F_12 ( V_22 , V_59 ,
V_38 , V_117 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_22 , V_57 ,
& V_110 , V_119 ) ;
if ( V_11 == - V_4 && V_119 > 0 ) {
V_11 = 0 ;
break;
} else if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_14 ,
V_119 ,
( V_59 == V_34 ) ? L_5 :
L_6 ,
V_117 , V_11 ) ;
break;
}
V_11 = F_60 ( V_57 , V_110 , V_118 ) ;
if ( V_11 < 0 )
break;
}
F_20 ( V_57 ) ;
return V_11 ;
}
static int
F_64 ( struct V_5 * V_6 )
{
T_1 V_122 [ V_123 ] , V_22 [ V_23 ] ;
unsigned int V_2 ;
enum V_26 type ;
int V_11 ;
V_11 = F_65 ( V_6 -> V_12 , 0x0c , 0x00 , 0x00 , V_122 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_15 ,
V_11 ) ;
goto V_15;
}
V_6 -> V_32 = - 1 ;
for ( V_2 = 0 ; V_2 < V_122 [ 0 ] ; V_2 ++ ) {
F_10 ( V_22 , V_34 , V_2 ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_16 ,
V_2 , V_11 ) ;
goto V_15;
}
if ( type == V_43 ) {
V_6 -> V_32 = V_2 ;
break;
}
}
V_15:
return V_11 ;
}
int F_66 ( struct V_5 * V_6 )
{
const struct V_19 * V_20 = V_6 -> V_21 -> clock ;
T_1 V_122 [ V_123 ] , V_22 [ V_23 ] ;
enum V_26 type ;
unsigned int V_2 ;
int V_11 ;
V_11 = F_65 ( V_6 -> V_12 , 0x1f , 0x07 , 0x00 , V_122 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_17 ,
V_11 ) ;
goto V_15;
}
if ( ( V_122 [ 0 ] == 0 ) || ( V_122 [ 1 ] == 0 ) ) {
V_11 = - V_63 ;
goto V_15;
}
F_12 ( V_22 , V_34 ,
V_38 , 0 ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_18 , V_11 ) ;
goto V_15;
} else if ( type != V_124 ) {
V_11 = - V_63 ;
goto V_15;
}
V_11 = F_61 ( V_6 , V_34 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
F_12 ( V_22 , V_35 ,
V_38 , 0 ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_19 , V_11 ) ;
goto V_15;
} else if ( type != V_124 ) {
V_11 = - V_63 ;
goto V_15;
}
V_11 = F_61 ( V_6 , V_35 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_6 -> V_125 = 0 ;
for ( V_2 = 0 ; V_2 < V_122 [ 2 ] ; V_2 ++ ) {
F_12 ( V_22 , V_34 ,
V_41 , V_2 ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_20 ,
V_2 , V_11 ) ;
goto V_15;
} else if ( type == V_126 ) {
V_6 -> V_125 ++ ;
}
}
V_6 -> V_127 = 0 ;
for ( V_2 = 0 ; V_2 < V_122 [ 3 ] ; V_2 ++ ) {
F_12 ( V_22 , V_35 ,
V_41 , V_2 ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_21 ,
V_2 , V_11 ) ;
goto V_15;
} else if ( type == V_126 ) {
V_6 -> V_127 ++ ;
}
}
if ( ! V_20 )
V_11 = F_64 ( V_6 ) ;
V_15:
return V_11 ;
}
void F_67 ( struct V_5 * V_6 )
{
V_6 -> V_128 = true ;
F_68 ( & V_6 -> V_129 ) ;
}
int F_69 ( struct V_5 * V_6 )
{
int V_11 ;
F_70 ( & V_6 -> V_130 ) ;
if ( V_6 -> V_131 < 0 ) {
V_11 = - V_74 ;
goto V_15;
}
if ( V_6 -> V_131 ++ == 0 )
F_67 ( V_6 ) ;
V_11 = 0 ;
V_15:
F_71 ( & V_6 -> V_130 ) ;
return V_11 ;
}
void F_72 ( struct V_5 * V_6 )
{
F_70 ( & V_6 -> V_130 ) ;
if ( F_73 ( V_6 -> V_131 <= 0 ) )
goto V_15;
if ( -- V_6 -> V_131 == 0 )
F_67 ( V_6 ) ;
V_15:
F_71 ( & V_6 -> V_130 ) ;
}
