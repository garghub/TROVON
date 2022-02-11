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
struct V_19 * V_20 = V_6 -> V_21 -> clock ;
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
V_46 -> V_64 = V_54 ;
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
if ( V_53 >= V_65 ) {
V_11 = - V_63 ;
goto V_15;
}
V_46 -> V_66 [ V_53 ] = V_54 ;
break;
}
}
if ( type != 0x0a )
V_51 += V_50 ;
else
V_52 += V_50 ;
}
V_15:
F_18 ( V_57 ) ;
return V_11 ;
}
static int
F_19 ( struct V_5 * V_6 )
{
int V_11 ;
V_11 = F_20 ( & V_6 -> V_67 ,
V_6 -> V_12 , V_68 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_20 ( & V_6 -> V_69 ,
V_6 -> V_12 , V_70 , 0 ) ;
if ( V_11 < 0 )
F_21 ( & V_6 -> V_67 ) ;
V_15:
return V_11 ;
}
static int
F_22 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
struct V_71 * V_72 ;
bool V_73 ;
int V_11 ;
if ( V_46 == & V_6 -> V_62 )
V_72 = & V_6 -> V_69 ;
else
V_72 = & V_6 -> V_67 ;
V_11 = F_23 ( V_72 , & V_73 ) ;
if ( ( V_11 >= 0 ) && V_73 && ! F_24 ( V_46 ) ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_8 ,
( V_72 -> V_74 == V_70 ) ? 'o' : 'i' ,
V_72 -> V_75 ) ;
V_11 = - V_76 ;
}
return V_11 ;
}
static int
F_25 ( struct V_5 * V_6 , unsigned int V_1 )
{
int V_77 , V_78 , V_79 , V_11 = 0 ;
if ( V_6 -> V_80 )
goto V_15;
V_77 = F_1 ( V_1 ) ;
V_78 = V_6 -> V_81 [ V_77 ] . V_51 ;
V_79 = V_6 -> V_81 [ V_77 ] . V_52 ;
F_26 ( & V_6 -> V_62 ,
V_1 , V_78 , V_79 * 8 ) ;
V_78 = V_6 -> V_82 [ V_77 ] . V_51 ;
V_79 = V_6 -> V_82 [ V_77 ] . V_52 ;
F_26 ( & V_6 -> V_83 ,
V_1 , V_78 , V_79 * 8 ) ;
V_11 = F_27 ( & V_6 -> V_69 ,
F_28 ( & V_6 -> V_62 ) ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_27 ( & V_6 -> V_67 ,
F_28 ( & V_6 -> V_83 ) ) ;
if ( V_11 < 0 ) {
F_29 ( & V_6 -> V_69 ) ;
goto V_15;
}
V_6 -> V_80 = true ;
V_15:
return V_11 ;
}
static void
F_30 ( struct V_5 * V_6 )
{
F_29 ( & V_6 -> V_67 ) ;
F_29 ( & V_6 -> V_69 ) ;
V_6 -> V_80 = false ;
if ( V_6 -> V_84 != NULL )
F_7 ( 200 ) ;
}
static void
F_31 ( struct V_5 * V_6 )
{
F_21 ( & V_6 -> V_67 ) ;
F_21 ( & V_6 -> V_69 ) ;
}
static int
F_32 ( struct V_5 * V_6 , enum V_85 * V_86 )
{
enum V_17 V_18 ;
int V_11 ;
V_11 = F_8 ( V_6 , & V_18 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_18 ) {
case V_33 :
case V_40 :
* V_86 = V_87 ;
break;
default:
case V_39 :
* V_86 = 0 ;
break;
}
return 0 ;
}
static int
F_33 ( struct V_5 * V_6 , struct V_45 * V_88 ,
unsigned int V_1 )
{
struct V_71 * V_72 ;
int V_11 = 0 ;
if ( V_88 == & V_6 -> V_83 )
V_72 = & V_6 -> V_67 ;
else
V_72 = & V_6 -> V_69 ;
if ( V_6 -> V_84 == NULL ) {
V_11 = F_14 ( V_6 , V_88 ) ;
if ( V_11 < 0 )
goto V_15;
}
V_11 = F_34 ( V_88 ,
V_72 -> V_89 . V_90 ,
V_72 -> V_91 ) ;
V_15:
return V_11 ;
}
int F_35 ( struct V_5 * V_6 )
{
int V_11 ;
V_11 = F_19 ( V_6 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_36 ( & V_6 -> V_62 , V_6 -> V_12 ,
V_92 , V_93 ) ;
if ( V_11 < 0 ) {
F_37 ( & V_6 -> V_62 ) ;
F_31 ( V_6 ) ;
goto V_15;
}
F_38 ( & V_6 -> V_94 ) ;
V_6 -> V_62 . V_95 |= V_96 ;
if ( V_6 -> V_97 > 2 )
V_6 -> V_62 . V_95 |= V_98 |
V_99 ;
if ( V_6 -> V_84 )
V_6 -> V_62 . V_95 |= V_98 ;
V_11 = F_36 ( & V_6 -> V_83 , V_6 -> V_12 ,
V_100 , V_93 ) ;
if ( V_11 < 0 ) {
F_37 ( & V_6 -> V_62 ) ;
F_37 ( & V_6 -> V_83 ) ;
F_31 ( V_6 ) ;
}
V_15:
return V_11 ;
}
int F_39 ( struct V_5 * V_6 , unsigned int V_1 )
{
struct V_101 * V_102 = V_6 -> V_21 -> V_1 ;
struct V_45 * V_103 , * V_104 ;
enum V_85 V_86 ;
unsigned int V_7 ;
bool V_105 = false ;
int V_11 = 0 ;
if ( F_40 ( & V_6 -> V_62 ) ) {
if ( F_41 ( & V_6 -> V_94 ) )
F_42 ( & V_6 -> V_94 ) ;
V_105 = ( F_43 (
& V_6 -> V_94 ,
F_44 ( V_106 ) ) > 0 ) ;
}
F_45 ( & V_6 -> V_107 ) ;
if ( F_46 ( & V_6 -> V_108 ) == 0 )
goto V_15;
V_11 = F_32 ( V_6 , & V_86 ) ;
if ( V_11 < 0 )
goto V_15;
if ( V_86 == V_87 ) {
V_103 = & V_6 -> V_62 ;
V_104 = & V_6 -> V_83 ;
} else {
V_103 = & V_6 -> V_83 ;
V_104 = & V_6 -> V_62 ;
}
V_11 = F_22 ( V_6 , V_103 ) ;
if ( V_11 < 0 )
goto V_15;
if ( F_40 ( V_103 ) )
F_47 ( V_103 ) ;
if ( F_40 ( V_104 ) )
F_47 ( V_104 ) ;
if ( ! V_105 &&
! F_24 ( V_103 ) && ! F_24 ( V_104 ) )
F_30 ( V_6 ) ;
V_11 = V_102 -> V_27 ( V_6 , & V_7 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_9 , V_11 ) ;
goto V_15;
}
if ( V_1 == 0 )
V_1 = V_7 ;
if ( V_1 != V_7 ) {
F_47 ( V_103 ) ;
F_47 ( V_104 ) ;
F_30 ( V_6 ) ;
}
if ( ! F_24 ( V_103 ) ) {
F_48 ( V_86 , V_103 , V_104 ) ;
V_6 -> V_103 = V_103 ;
if ( V_6 -> V_84 == NULL ) {
V_11 = V_102 -> V_109 ( V_6 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_10 ,
V_11 ) ;
goto V_15;
}
}
V_11 = F_25 ( V_6 , V_1 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_33 ( V_6 , V_103 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_11 , V_11 ) ;
F_30 ( V_6 ) ;
goto V_15;
}
if ( V_6 -> V_84 != NULL ) {
V_11 = V_102 -> V_109 ( V_6 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_12 ,
V_11 ) ;
F_47 ( V_103 ) ;
F_30 ( V_6 ) ;
goto V_15;
}
}
if ( ! F_49 ( V_103 , V_110 ) ) {
F_47 ( V_103 ) ;
F_30 ( V_6 ) ;
V_11 = - V_111 ;
goto V_15;
}
}
if ( ! F_24 ( V_104 ) ) {
V_11 = F_33 ( V_6 , V_104 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_13 , V_11 ) ;
F_47 ( V_103 ) ;
F_30 ( V_6 ) ;
goto V_15;
}
if ( ! F_49 ( V_104 , V_110 ) ) {
F_47 ( V_104 ) ;
F_47 ( V_103 ) ;
F_30 ( V_6 ) ;
V_11 = - V_111 ;
}
}
V_15:
F_50 ( & V_6 -> V_107 ) ;
return V_11 ;
}
void F_51 ( struct V_5 * V_6 )
{
struct V_45 * V_103 , * V_104 ;
if ( V_6 -> V_103 == & V_6 -> V_83 ) {
V_104 = & V_6 -> V_62 ;
V_103 = & V_6 -> V_83 ;
} else {
V_104 = & V_6 -> V_83 ;
V_103 = & V_6 -> V_62 ;
}
F_45 ( & V_6 -> V_107 ) ;
if ( F_46 ( & V_6 -> V_108 ) == 0 ) {
F_52 ( V_103 ) ;
F_47 ( V_103 ) ;
F_52 ( V_104 ) ;
F_47 ( V_104 ) ;
F_30 ( V_6 ) ;
}
F_50 ( & V_6 -> V_107 ) ;
}
void F_53 ( struct V_5 * V_6 )
{
F_45 ( & V_6 -> V_107 ) ;
if ( ( F_54 ( & V_6 -> V_67 ) < 0 ) ||
( F_54 ( & V_6 -> V_69 ) < 0 ) ) {
F_52 ( & V_6 -> V_83 ) ;
F_52 ( & V_6 -> V_62 ) ;
F_47 ( & V_6 -> V_83 ) ;
F_47 ( & V_6 -> V_62 ) ;
F_30 ( V_6 ) ;
} else {
F_55 ( & V_6 -> V_83 ) ;
F_55 ( & V_6 -> V_62 ) ;
}
if ( ! F_41 ( & V_6 -> V_94 ) )
F_56 ( & V_6 -> V_94 ) ;
F_50 ( & V_6 -> V_107 ) ;
}
void F_57 ( struct V_5 * V_6 )
{
F_37 ( & V_6 -> V_83 ) ;
F_37 ( & V_6 -> V_62 ) ;
F_31 ( V_6 ) ;
}
static int
F_58 ( T_1 * V_57 , unsigned int V_112 ,
struct V_113 * V_114 )
{
unsigned int V_2 , V_115 , V_50 , V_116 ;
if ( ( V_57 [ 0 ] != 0x90 ) || ( V_57 [ 1 ] != 0x40 ) )
return - V_63 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_117 ) ; V_2 ++ ) {
if ( V_57 [ 2 ] == V_117 [ V_2 ] )
break;
}
if ( V_2 == F_2 ( V_117 ) )
return - V_63 ;
memset ( & V_114 [ V_2 ] , 0 , sizeof( struct V_113 ) ) ;
for ( V_115 = 0 ; V_115 < V_57 [ 4 ] ; V_115 ++ ) {
V_50 = V_57 [ 5 + V_115 * 2 ] ;
V_116 = V_57 [ 6 + V_115 * 2 ] ;
switch ( V_116 ) {
case 0x00 :
case 0x06 :
V_114 [ V_2 ] . V_51 += V_50 ;
break;
case 0x0d :
V_114 [ V_2 ] . V_52 += V_50 ;
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
if ( V_114 [ V_2 ] . V_51 > V_65 ||
V_114 [ V_2 ] . V_52 > V_118 )
return - V_63 ;
return 0 ;
}
static int
F_59 ( struct V_5 * V_6 , enum V_58 V_59 ,
unsigned short V_119 )
{
T_1 * V_57 ;
struct V_113 * V_120 ;
unsigned int V_112 , V_121 ;
T_1 V_22 [ V_23 ] ;
int V_11 ;
V_57 = F_60 ( V_122 , V_60 ) ;
if ( V_57 == NULL )
return - V_61 ;
if ( V_59 == V_34 )
V_120 = V_6 -> V_82 ;
else
V_120 = V_6 -> V_81 ;
for ( V_121 = 0 ; V_121 < V_123 ; V_121 ++ ) {
V_112 = V_122 ;
F_12 ( V_22 , V_59 ,
V_38 , V_119 ) ;
V_11 = F_61 ( V_6 -> V_12 , V_22 , V_57 ,
& V_112 , V_121 ) ;
if ( V_11 == - V_4 && V_121 > 0 ) {
V_11 = 0 ;
break;
} else if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_14 ,
V_121 ,
( V_59 == V_34 ) ? L_5 :
L_6 ,
V_119 , V_11 ) ;
break;
}
V_11 = F_58 ( V_57 , V_112 , V_120 ) ;
if ( V_11 < 0 )
break;
}
F_18 ( V_57 ) ;
return V_11 ;
}
static int
F_62 ( struct V_5 * V_6 )
{
T_1 V_124 [ V_125 ] , V_22 [ V_23 ] ;
unsigned int V_2 ;
enum V_26 type ;
int V_11 ;
V_11 = F_63 ( V_6 -> V_12 , 0x0c , 0x00 , 0x00 , V_124 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_15 ,
V_11 ) ;
goto V_15;
}
V_6 -> V_32 = - 1 ;
for ( V_2 = 0 ; V_2 < V_124 [ 0 ] ; V_2 ++ ) {
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
int F_64 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_21 -> clock ;
T_1 V_124 [ V_125 ] , V_22 [ V_23 ] ;
enum V_26 type ;
unsigned int V_2 ;
int V_11 ;
V_11 = F_63 ( V_6 -> V_12 , 0x1f , 0x07 , 0x00 , V_124 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_17 ,
V_11 ) ;
goto V_15;
}
if ( ( V_124 [ 0 ] == 0 ) || ( V_124 [ 1 ] == 0 ) ) {
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
} else if ( type != V_126 ) {
V_11 = - V_63 ;
goto V_15;
}
V_11 = F_59 ( V_6 , V_34 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
F_12 ( V_22 , V_35 ,
V_38 , 0 ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_19 , V_11 ) ;
goto V_15;
} else if ( type != V_126 ) {
V_11 = - V_63 ;
goto V_15;
}
V_11 = F_59 ( V_6 , V_35 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_6 -> V_127 = 0 ;
for ( V_2 = 0 ; V_2 < V_124 [ 2 ] ; V_2 ++ ) {
F_12 ( V_22 , V_34 ,
V_41 , V_2 ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_20 ,
V_2 , V_11 ) ;
goto V_15;
} else if ( type == V_128 ) {
V_6 -> V_127 ++ ;
}
}
V_6 -> V_129 = 0 ;
for ( V_2 = 0 ; V_2 < V_124 [ 3 ] ; V_2 ++ ) {
F_12 ( V_22 , V_35 ,
V_41 , V_2 ) ;
V_11 = F_13 ( V_6 -> V_12 , V_22 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_28 ,
L_21 ,
V_2 , V_11 ) ;
goto V_15;
} else if ( type == V_128 ) {
V_6 -> V_129 ++ ;
}
}
if ( ! V_20 )
V_11 = F_62 ( V_6 ) ;
V_15:
return V_11 ;
}
void F_65 ( struct V_5 * V_6 )
{
V_6 -> V_130 = true ;
F_66 ( & V_6 -> V_131 ) ;
}
int F_67 ( struct V_5 * V_6 )
{
int V_11 ;
F_68 ( & V_6 -> V_132 ) ;
if ( V_6 -> V_133 < 0 ) {
V_11 = - V_76 ;
goto V_15;
}
if ( V_6 -> V_133 ++ == 0 )
F_65 ( V_6 ) ;
V_11 = 0 ;
V_15:
F_69 ( & V_6 -> V_132 ) ;
return V_11 ;
}
void F_70 ( struct V_5 * V_6 )
{
F_68 ( & V_6 -> V_132 ) ;
if ( F_71 ( V_6 -> V_133 <= 0 ) )
goto V_15;
if ( -- V_6 -> V_133 == 0 )
F_65 ( V_6 ) ;
V_15:
F_69 ( & V_6 -> V_132 ) ;
}
