static int
F_1 ( unsigned int V_1 , unsigned int * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] == V_1 ) {
* V_2 = V_3 ;
return 0 ;
}
}
return - V_5 ;
}
int
F_3 ( struct V_6 * V_7 , unsigned int * V_8 )
{
unsigned int V_9 , V_10 , V_11 ;
int V_12 ;
V_11 = 0 ;
do {
V_12 = F_4 ( V_7 -> V_13 , & V_9 ,
V_14 , 0 ) ;
} while ( V_12 == - V_15 && ++ V_11 < 3 );
if ( V_12 < 0 )
goto V_16;
V_11 = 0 ;
do {
V_12 = F_4 ( V_7 -> V_13 , & V_10 ,
V_17 , 0 ) ;
} while ( V_12 == - V_15 && ++ V_11 < 3 );
if ( V_12 < 0 )
goto V_16;
* V_8 = V_10 ;
if ( V_10 == V_9 )
goto V_16;
V_12 = F_5 ( V_7 -> V_13 , V_10 ,
V_17 , 0 ) ;
V_16:
return V_12 ;
}
int
F_6 ( struct V_6 * V_7 , unsigned int V_1 )
{
int V_12 ;
V_12 = F_5 ( V_7 -> V_13 , V_1 ,
V_14 , 0 ) ;
if ( V_12 < 0 )
goto V_16;
V_12 = F_5 ( V_7 -> V_13 , V_1 ,
V_17 , 0 ) ;
if ( V_12 < 0 )
goto V_16;
F_7 ( 300 ) ;
V_16:
return V_12 ;
}
int F_8 ( struct V_6 * V_7 ,
enum V_18 * V_19 )
{
const struct V_20 * V_21 = V_7 -> V_22 -> clock ;
T_1 V_23 [ V_24 ] , V_25 [ 7 ] ;
unsigned int V_26 ;
enum V_27 type ;
int V_12 = 0 ;
if ( V_21 ) {
V_12 = V_21 -> V_28 ( V_7 , & V_26 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_1 , V_12 ) ;
goto V_16;
}
if ( V_26 >= V_21 -> V_30 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_2 ,
V_26 , V_21 -> V_30 - 1 ) ;
V_12 = - V_31 ;
goto V_16;
}
* V_19 = V_21 -> V_32 [ V_26 ] ;
goto V_16;
}
if ( V_7 -> V_33 < 0 ) {
* V_19 = V_34 ;
goto V_16;
}
F_10 ( V_23 , V_35 ,
V_7 -> V_33 ) ;
V_12 = F_11 ( V_7 -> V_13 , V_23 , V_25 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_3 ,
V_7 -> V_33 , V_12 ) ;
goto V_16;
}
if ( V_25 [ 0 ] == 0xff ) {
* V_19 = V_34 ;
goto V_16;
}
if ( V_25 [ 0 ] == V_36 ) {
if ( V_25 [ 1 ] == V_37 &&
V_25 [ 2 ] == 0x0c ) {
* V_19 = V_34 ;
goto V_16;
}
} else if ( V_25 [ 1 ] == V_38 ) {
if ( V_25 [ 2 ] == V_39 ) {
if ( V_25 [ 3 ] == 0x00 ) {
* V_19 = V_40 ;
goto V_16;
} else {
* V_19 = V_41 ;
goto V_16;
}
} else if ( V_25 [ 2 ] == V_42 ) {
F_12 ( V_23 ,
V_35 ,
V_42 ,
V_25 [ 3 ] ) ;
V_12 = F_13 ( V_7 -> V_13 , V_23 ,
& type ) ;
if ( V_12 < 0 )
goto V_16;
if ( type == V_43 ) {
* V_19 = V_41 ;
goto V_16;
} else if ( type == V_44 ) {
* V_19 = V_41 ;
goto V_16;
} else if ( type == V_45 ) {
* V_19 = V_34 ;
goto V_16;
}
}
}
V_12 = - V_31 ;
V_16:
return V_12 ;
}
static unsigned int
F_14 ( struct V_6 * V_7 , struct V_46 * V_47 )
{
unsigned int V_48 , V_49 , V_50 , V_51 ;
unsigned int V_52 , V_53 , V_54 ;
unsigned int V_55 , V_56 , V_57 ;
T_1 * V_58 , V_23 [ V_24 ] , type ;
enum V_59 V_60 ;
int V_12 ;
V_58 = F_15 ( 256 , V_61 ) ;
if ( V_58 == NULL )
return - V_62 ;
if ( V_47 == & V_7 -> V_63 )
V_60 = V_36 ;
else
V_60 = V_35 ;
F_12 ( V_23 , V_60 , V_39 , 0 ) ;
V_12 = F_16 ( V_7 -> V_13 , V_23 , V_58 , 256 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_4 ,
( V_60 == V_35 ) ? L_5 : L_6 ,
V_12 ) ;
goto V_16;
}
V_57 = 0 ;
V_52 = 0 ;
V_53 = 0 ;
V_49 = V_58 [ V_57 ++ ] ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
F_12 ( V_23 , V_60 ,
V_39 , 0 ) ;
V_12 = F_17 ( V_7 -> V_13 , V_23 ,
V_48 , & type ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_7 ,
( V_60 == V_35 ) ? L_5 :
L_6 ,
V_12 ) ;
goto V_16;
}
if ( type == 0xff ) {
V_12 = - V_64 ;
goto V_16;
}
V_51 = V_58 [ V_57 ++ ] ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
V_55 = V_58 [ V_57 ++ ] - 1 ;
V_56 = V_58 [ V_57 ++ ] - 1 ;
if ( V_56 >= V_51 )
V_56 = V_50 ;
switch ( type ) {
case 0x0a :
if ( ( V_53 > 0 ) && ( V_55 != V_53 ) ) {
V_12 = - V_64 ;
goto V_16;
}
F_18 ( V_47 , V_55 ) ;
V_53 = V_55 ;
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
V_54 = V_52 + V_56 ;
if ( V_54 >= V_65 ) {
V_12 = - V_64 ;
goto V_16;
}
F_19 ( V_47 , V_54 ,
V_55 ) ;
break;
}
}
if ( type != 0x0a )
V_52 += V_51 ;
else
V_53 += V_51 ;
}
V_16:
F_20 ( V_58 ) ;
return V_12 ;
}
static int
F_21 ( struct V_6 * V_7 )
{
int V_12 ;
V_12 = F_22 ( & V_7 -> V_66 ,
V_7 -> V_13 , V_67 , 0 ) ;
if ( V_12 < 0 )
goto V_16;
V_12 = F_22 ( & V_7 -> V_68 ,
V_7 -> V_13 , V_69 , 0 ) ;
if ( V_12 < 0 )
F_23 ( & V_7 -> V_66 ) ;
V_16:
return V_12 ;
}
static int
F_24 ( struct V_6 * V_7 , struct V_46 * V_47 )
{
struct V_70 * V_71 ;
bool V_72 ;
int V_12 ;
if ( V_47 == & V_7 -> V_63 )
V_71 = & V_7 -> V_68 ;
else
V_71 = & V_7 -> V_66 ;
V_12 = F_25 ( V_71 , & V_72 ) ;
if ( ( V_12 >= 0 ) && V_72 && ! F_26 ( V_47 ) ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_8 ,
( V_71 -> V_73 == V_69 ) ? 'o' : 'i' ,
V_71 -> V_74 ) ;
V_12 = - V_75 ;
}
return V_12 ;
}
static int
F_27 ( struct V_6 * V_7 , unsigned int V_1 )
{
int V_2 , V_76 , V_77 , V_12 = 0 ;
if ( V_7 -> V_78 )
goto V_16;
V_12 = F_1 ( V_1 , & V_2 ) ;
if ( V_12 < 0 )
goto V_16;
V_76 = V_7 -> V_79 [ V_2 ] . V_52 ;
V_77 = V_7 -> V_79 [ V_2 ] . V_53 ;
V_12 = F_28 ( & V_7 -> V_63 , V_1 ,
V_76 , V_77 * 8 ,
false ) ;
if ( V_12 < 0 )
goto V_16;
V_76 = V_7 -> V_80 [ V_2 ] . V_52 ;
V_77 = V_7 -> V_80 [ V_2 ] . V_53 ;
V_12 = F_28 ( & V_7 -> V_81 , V_1 ,
V_76 , V_77 * 8 ,
false ) ;
if ( V_12 < 0 )
goto V_16;
V_12 = F_29 ( & V_7 -> V_68 ,
F_30 ( & V_7 -> V_63 ) ) ;
if ( V_12 < 0 )
goto V_16;
V_12 = F_29 ( & V_7 -> V_66 ,
F_30 ( & V_7 -> V_81 ) ) ;
if ( V_12 < 0 ) {
F_31 ( & V_7 -> V_68 ) ;
goto V_16;
}
V_7 -> V_78 = true ;
V_16:
return V_12 ;
}
static void
F_32 ( struct V_6 * V_7 )
{
F_31 ( & V_7 -> V_66 ) ;
F_31 ( & V_7 -> V_68 ) ;
V_7 -> V_78 = false ;
if ( V_7 -> V_82 != NULL )
F_7 ( 200 ) ;
}
static void
F_33 ( struct V_6 * V_7 )
{
F_23 ( & V_7 -> V_66 ) ;
F_23 ( & V_7 -> V_68 ) ;
}
static int
F_34 ( struct V_6 * V_7 , enum V_83 * V_84 )
{
enum V_18 V_19 ;
int V_12 ;
V_12 = F_8 ( V_7 , & V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( V_19 ) {
case V_34 :
case V_41 :
* V_84 = V_85 ;
break;
default:
case V_40 :
* V_84 = 0 ;
break;
}
return 0 ;
}
static int
F_35 ( struct V_6 * V_7 , struct V_46 * V_86 ,
unsigned int V_1 )
{
struct V_70 * V_71 ;
int V_12 = 0 ;
if ( V_86 == & V_7 -> V_81 )
V_71 = & V_7 -> V_66 ;
else
V_71 = & V_7 -> V_68 ;
if ( V_7 -> V_82 == NULL ) {
V_12 = F_14 ( V_7 , V_86 ) ;
if ( V_12 < 0 )
goto V_16;
}
V_12 = F_36 ( V_86 ,
V_71 -> V_87 . V_88 ,
V_71 -> V_89 ) ;
V_16:
return V_12 ;
}
int F_37 ( struct V_6 * V_7 )
{
int V_12 ;
V_12 = F_21 ( V_7 ) ;
if ( V_12 < 0 )
goto V_16;
V_12 = F_38 ( & V_7 -> V_63 , V_7 -> V_13 ,
V_90 , V_91 ) ;
if ( V_12 < 0 ) {
F_39 ( & V_7 -> V_63 ) ;
F_33 ( V_7 ) ;
goto V_16;
}
F_40 ( & V_7 -> V_92 ) ;
V_7 -> V_63 . V_93 |= V_94 ;
if ( V_7 -> V_95 > 2 )
V_7 -> V_63 . V_93 |= V_96 |
V_97 ;
if ( V_7 -> V_82 )
V_7 -> V_63 . V_93 |= V_96 ;
V_12 = F_38 ( & V_7 -> V_81 , V_7 -> V_13 ,
V_98 , V_91 ) ;
if ( V_12 < 0 ) {
F_39 ( & V_7 -> V_63 ) ;
F_39 ( & V_7 -> V_81 ) ;
F_33 ( V_7 ) ;
}
V_16:
return V_12 ;
}
int F_41 ( struct V_6 * V_7 , unsigned int V_1 )
{
const struct V_99 * V_100 = V_7 -> V_22 -> V_1 ;
struct V_46 * V_101 , * V_102 ;
enum V_83 V_84 ;
unsigned int V_8 ;
bool V_103 = false ;
int V_12 = 0 ;
if ( F_42 ( & V_7 -> V_63 ) ) {
if ( F_43 ( & V_7 -> V_92 ) )
F_44 ( & V_7 -> V_92 ) ;
V_103 = ( F_45 (
& V_7 -> V_92 ,
F_46 ( V_104 ) ) > 0 ) ;
}
F_47 ( & V_7 -> V_105 ) ;
if ( F_48 ( & V_7 -> V_106 ) == 0 )
goto V_16;
V_12 = F_34 ( V_7 , & V_84 ) ;
if ( V_12 < 0 )
goto V_16;
if ( V_84 == V_85 ) {
V_101 = & V_7 -> V_63 ;
V_102 = & V_7 -> V_81 ;
} else {
V_101 = & V_7 -> V_81 ;
V_102 = & V_7 -> V_63 ;
}
V_12 = F_24 ( V_7 , V_101 ) ;
if ( V_12 < 0 )
goto V_16;
if ( F_42 ( V_101 ) )
F_49 ( V_101 ) ;
if ( F_42 ( V_102 ) )
F_49 ( V_102 ) ;
if ( ! V_103 &&
! F_26 ( V_101 ) && ! F_26 ( V_102 ) )
F_32 ( V_7 ) ;
V_12 = V_100 -> V_28 ( V_7 , & V_8 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_9 , V_12 ) ;
goto V_16;
}
if ( V_1 == 0 )
V_1 = V_8 ;
if ( V_1 != V_8 ) {
F_49 ( V_101 ) ;
F_49 ( V_102 ) ;
F_32 ( V_7 ) ;
}
if ( ! F_26 ( V_101 ) ) {
F_50 ( V_84 , V_101 , V_102 ) ;
V_7 -> V_101 = V_101 ;
if ( V_7 -> V_82 == NULL ) {
V_12 = V_100 -> V_107 ( V_7 , V_1 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_10 ,
V_12 ) ;
goto V_16;
}
}
V_12 = F_27 ( V_7 , V_1 ) ;
if ( V_12 < 0 )
goto V_16;
V_12 = F_35 ( V_7 , V_101 , V_1 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_11 , V_12 ) ;
F_32 ( V_7 ) ;
goto V_16;
}
if ( V_7 -> V_82 != NULL ) {
V_12 = V_100 -> V_107 ( V_7 , V_1 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_12 ,
V_12 ) ;
F_49 ( V_101 ) ;
F_32 ( V_7 ) ;
goto V_16;
}
}
if ( ! F_51 ( V_101 , V_108 ) ) {
F_49 ( V_101 ) ;
F_32 ( V_7 ) ;
V_12 = - V_109 ;
goto V_16;
}
}
if ( ! F_26 ( V_102 ) ) {
V_12 = F_35 ( V_7 , V_102 , V_1 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_13 , V_12 ) ;
F_49 ( V_101 ) ;
F_32 ( V_7 ) ;
goto V_16;
}
if ( ! F_51 ( V_102 , V_108 ) ) {
F_49 ( V_102 ) ;
F_49 ( V_101 ) ;
F_32 ( V_7 ) ;
V_12 = - V_109 ;
}
}
V_16:
F_52 ( & V_7 -> V_105 ) ;
return V_12 ;
}
void F_53 ( struct V_6 * V_7 )
{
struct V_46 * V_101 , * V_102 ;
if ( V_7 -> V_101 == & V_7 -> V_81 ) {
V_102 = & V_7 -> V_63 ;
V_101 = & V_7 -> V_81 ;
} else {
V_102 = & V_7 -> V_81 ;
V_101 = & V_7 -> V_63 ;
}
F_47 ( & V_7 -> V_105 ) ;
if ( F_48 ( & V_7 -> V_106 ) == 0 ) {
F_54 ( V_101 ) ;
F_49 ( V_101 ) ;
F_54 ( V_102 ) ;
F_49 ( V_102 ) ;
F_32 ( V_7 ) ;
}
F_52 ( & V_7 -> V_105 ) ;
}
void F_55 ( struct V_6 * V_7 )
{
F_47 ( & V_7 -> V_105 ) ;
if ( ( F_56 ( & V_7 -> V_66 ) < 0 ) ||
( F_56 ( & V_7 -> V_68 ) < 0 ) ) {
F_54 ( & V_7 -> V_81 ) ;
F_54 ( & V_7 -> V_63 ) ;
F_49 ( & V_7 -> V_81 ) ;
F_49 ( & V_7 -> V_63 ) ;
F_32 ( V_7 ) ;
} else {
F_57 ( & V_7 -> V_81 ) ;
F_57 ( & V_7 -> V_63 ) ;
}
if ( ! F_43 ( & V_7 -> V_92 ) )
F_58 ( & V_7 -> V_92 ) ;
F_52 ( & V_7 -> V_105 ) ;
}
void F_59 ( struct V_6 * V_7 )
{
F_39 ( & V_7 -> V_81 ) ;
F_39 ( & V_7 -> V_63 ) ;
F_33 ( V_7 ) ;
}
static int
F_60 ( T_1 * V_58 , unsigned int V_110 ,
struct V_111 * V_112 )
{
unsigned int V_3 , V_113 , V_51 , V_114 ;
if ( ( V_58 [ 0 ] != 0x90 ) || ( V_58 [ 1 ] != 0x40 ) )
return - V_64 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_115 ) ; V_3 ++ ) {
if ( V_58 [ 2 ] == V_115 [ V_3 ] )
break;
}
if ( V_3 == F_2 ( V_115 ) )
return - V_64 ;
memset ( & V_112 [ V_3 ] , 0 , sizeof( struct V_111 ) ) ;
for ( V_113 = 0 ; V_113 < V_58 [ 4 ] ; V_113 ++ ) {
V_51 = V_58 [ 5 + V_113 * 2 ] ;
V_114 = V_58 [ 6 + V_113 * 2 ] ;
switch ( V_114 ) {
case 0x00 :
case 0x06 :
V_112 [ V_3 ] . V_52 += V_51 ;
break;
case 0x0d :
V_112 [ V_3 ] . V_53 += V_51 ;
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
return - V_64 ;
}
}
if ( V_112 [ V_3 ] . V_52 > V_65 ||
V_112 [ V_3 ] . V_53 > V_116 )
return - V_64 ;
return 0 ;
}
static int
F_61 ( struct V_6 * V_7 , enum V_59 V_60 ,
unsigned short V_117 )
{
T_1 * V_58 ;
struct V_111 * V_118 ;
unsigned int V_110 , V_119 ;
T_1 V_23 [ V_24 ] ;
int V_12 ;
V_58 = F_62 ( V_120 , V_61 ) ;
if ( V_58 == NULL )
return - V_62 ;
if ( V_60 == V_35 )
V_118 = V_7 -> V_80 ;
else
V_118 = V_7 -> V_79 ;
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ ) {
V_110 = V_120 ;
F_12 ( V_23 , V_60 ,
V_39 , V_117 ) ;
V_12 = F_63 ( V_7 -> V_13 , V_23 , V_58 ,
& V_110 , V_119 ) ;
if ( V_12 == - V_5 && V_119 > 0 ) {
V_12 = 0 ;
break;
} else if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_14 ,
V_119 ,
( V_60 == V_35 ) ? L_5 :
L_6 ,
V_117 , V_12 ) ;
break;
}
V_12 = F_60 ( V_58 , V_110 , V_118 ) ;
if ( V_12 < 0 )
break;
}
F_20 ( V_58 ) ;
return V_12 ;
}
static int
F_64 ( struct V_6 * V_7 )
{
T_1 V_122 [ V_123 ] , V_23 [ V_24 ] ;
unsigned int V_3 ;
enum V_27 type ;
int V_12 ;
V_12 = F_65 ( V_7 -> V_13 , 0x0c , 0x00 , 0x00 , V_122 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_15 ,
V_12 ) ;
goto V_16;
}
V_7 -> V_33 = - 1 ;
for ( V_3 = 0 ; V_3 < V_122 [ 0 ] ; V_3 ++ ) {
F_10 ( V_23 , V_35 , V_3 ) ;
V_12 = F_13 ( V_7 -> V_13 , V_23 , & type ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_16 ,
V_3 , V_12 ) ;
goto V_16;
}
if ( type == V_44 ) {
V_7 -> V_33 = V_3 ;
break;
}
}
V_16:
return V_12 ;
}
int F_66 ( struct V_6 * V_7 )
{
const struct V_20 * V_21 = V_7 -> V_22 -> clock ;
T_1 V_122 [ V_123 ] , V_23 [ V_24 ] ;
enum V_27 type ;
unsigned int V_3 ;
int V_12 ;
V_12 = F_65 ( V_7 -> V_13 , 0x1f , 0x07 , 0x00 , V_122 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_17 ,
V_12 ) ;
goto V_16;
}
if ( ( V_122 [ 0 ] == 0 ) || ( V_122 [ 1 ] == 0 ) ) {
V_12 = - V_64 ;
goto V_16;
}
F_12 ( V_23 , V_35 ,
V_39 , 0 ) ;
V_12 = F_13 ( V_7 -> V_13 , V_23 , & type ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_18 , V_12 ) ;
goto V_16;
} else if ( type != V_124 ) {
V_12 = - V_64 ;
goto V_16;
}
V_12 = F_61 ( V_7 , V_35 , 0 ) ;
if ( V_12 < 0 )
goto V_16;
F_12 ( V_23 , V_36 ,
V_39 , 0 ) ;
V_12 = F_13 ( V_7 -> V_13 , V_23 , & type ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_19 , V_12 ) ;
goto V_16;
} else if ( type != V_124 ) {
V_12 = - V_64 ;
goto V_16;
}
V_12 = F_61 ( V_7 , V_36 , 0 ) ;
if ( V_12 < 0 )
goto V_16;
V_7 -> V_125 = 0 ;
for ( V_3 = 0 ; V_3 < V_122 [ 2 ] ; V_3 ++ ) {
F_12 ( V_23 , V_35 ,
V_42 , V_3 ) ;
V_12 = F_13 ( V_7 -> V_13 , V_23 , & type ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_20 ,
V_3 , V_12 ) ;
goto V_16;
} else if ( type == V_126 ) {
V_7 -> V_125 ++ ;
}
}
V_7 -> V_127 = 0 ;
for ( V_3 = 0 ; V_3 < V_122 [ 3 ] ; V_3 ++ ) {
F_12 ( V_23 , V_36 ,
V_42 , V_3 ) ;
V_12 = F_13 ( V_7 -> V_13 , V_23 , & type ) ;
if ( V_12 < 0 ) {
F_9 ( & V_7 -> V_13 -> V_29 ,
L_21 ,
V_3 , V_12 ) ;
goto V_16;
} else if ( type == V_126 ) {
V_7 -> V_127 ++ ;
}
}
if ( ! V_21 )
V_12 = F_64 ( V_7 ) ;
V_16:
return V_12 ;
}
void F_67 ( struct V_6 * V_7 )
{
V_7 -> V_128 = true ;
F_68 ( & V_7 -> V_129 ) ;
}
int F_69 ( struct V_6 * V_7 )
{
int V_12 ;
F_70 ( & V_7 -> V_130 ) ;
if ( V_7 -> V_131 < 0 ) {
V_12 = - V_75 ;
goto V_16;
}
if ( V_7 -> V_131 ++ == 0 )
F_67 ( V_7 ) ;
V_12 = 0 ;
V_16:
F_71 ( & V_7 -> V_130 ) ;
return V_12 ;
}
void F_72 ( struct V_6 * V_7 )
{
F_70 ( & V_7 -> V_130 ) ;
if ( F_73 ( V_7 -> V_131 <= 0 ) )
goto V_16;
if ( -- V_7 -> V_131 == 0 )
F_67 ( V_7 ) ;
V_16:
F_71 ( & V_7 -> V_130 ) ;
}
