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
int
F_8 ( struct V_5 * V_6 , bool * V_17 )
{
struct V_18 * V_19 = V_6 -> V_20 -> clock ;
T_1 V_21 [ V_22 ] , V_23 [ 7 ] ;
unsigned int V_24 ;
int V_11 = 0 ;
* V_17 = false ;
if ( V_19 ) {
V_11 = V_19 -> V_25 ( V_6 , & V_24 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_1 , V_11 ) ;
goto V_15;
}
if ( V_24 >= V_19 -> V_27 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_2 ,
V_24 , V_19 -> V_27 - 1 ) ;
V_11 = - V_28 ;
goto V_15;
}
if ( strncmp ( V_19 -> V_29 [ V_24 ] , V_30 ,
strlen ( V_30 ) ) == 0 )
* V_17 = true ;
goto V_15;
}
if ( V_6 -> V_31 < 0 ) {
* V_17 = true ;
goto V_15;
}
F_10 ( V_21 , V_32 ,
V_6 -> V_31 ) ;
V_11 = F_11 ( V_6 -> V_12 , V_21 , V_23 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_3 ,
V_6 -> V_31 , V_11 ) ;
goto V_15;
}
if ( V_23 [ 0 ] == 0xff ) {
* V_17 = true ;
goto V_15;
}
* V_17 = ( ( V_23 [ 0 ] == V_33 ) &&
( V_23 [ 1 ] == V_34 ) &&
( V_23 [ 2 ] == 0x0c ) &&
( V_23 [ 3 ] == 0x00 ) ) ;
V_15:
return V_11 ;
}
static unsigned int
F_12 ( struct V_5 * V_6 , struct V_35 * V_36 )
{
unsigned int V_37 , V_38 , V_39 , V_40 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 , V_45 , V_46 ;
T_1 * V_47 , V_21 [ V_22 ] , type ;
enum V_48 V_49 ;
int V_11 ;
V_47 = F_13 ( 256 , V_50 ) ;
if ( V_47 == NULL )
return - V_51 ;
if ( V_36 == & V_6 -> V_52 )
V_49 = V_33 ;
else
V_49 = V_32 ;
F_14 ( V_21 , V_49 , V_53 , 0 ) ;
V_11 = F_15 ( V_6 -> V_12 , V_21 , V_47 , 256 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_4 ,
( V_49 == V_32 ) ? L_5 : L_6 ,
V_11 ) ;
goto V_15;
}
V_46 = 0 ;
V_41 = 0 ;
V_42 = 0 ;
V_38 = V_47 [ V_46 ++ ] ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
F_14 ( V_21 , V_49 ,
V_53 , 0 ) ;
V_11 = F_16 ( V_6 -> V_12 , V_21 ,
V_37 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_7 ,
( V_49 == V_32 ) ? L_5 :
L_6 ,
V_11 ) ;
goto V_15;
}
if ( type == 0xff ) {
V_11 = - V_54 ;
goto V_15;
}
V_40 = V_47 [ V_46 ++ ] ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_44 = V_47 [ V_46 ++ ] - 1 ;
V_45 = V_47 [ V_46 ++ ] - 1 ;
if ( V_45 >= V_40 )
V_45 = V_39 ;
switch ( type ) {
case 0x0a :
if ( ( V_42 > 0 ) && ( V_44 != V_42 ) ) {
V_11 = - V_54 ;
goto V_15;
}
V_36 -> V_55 = V_44 ;
V_42 = V_44 ;
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
V_43 = V_41 + V_45 ;
if ( V_43 >= V_56 ) {
V_11 = - V_54 ;
goto V_15;
}
V_36 -> V_57 [ V_43 ] = V_44 ;
break;
}
}
if ( type != 0x0a )
V_41 += V_40 ;
else
V_42 += V_40 ;
}
V_15:
F_17 ( V_47 ) ;
return V_11 ;
}
static int
F_18 ( struct V_5 * V_6 )
{
int V_11 ;
V_11 = F_19 ( & V_6 -> V_58 ,
V_6 -> V_12 , V_59 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_19 ( & V_6 -> V_60 ,
V_6 -> V_12 , V_61 , 0 ) ;
if ( V_11 < 0 )
F_20 ( & V_6 -> V_58 ) ;
V_15:
return V_11 ;
}
static int
F_21 ( struct V_5 * V_6 , struct V_35 * V_36 )
{
struct V_62 * V_63 ;
bool V_64 ;
int V_11 ;
if ( V_36 == & V_6 -> V_52 )
V_63 = & V_6 -> V_60 ;
else
V_63 = & V_6 -> V_58 ;
V_11 = F_22 ( V_63 , & V_64 ) ;
if ( ( V_11 >= 0 ) && V_64 && ! F_23 ( V_36 ) ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_8 ,
( V_63 -> V_65 == V_61 ) ? 'o' : 'i' ,
V_63 -> V_66 ) ;
V_11 = - V_67 ;
}
return V_11 ;
}
static int
F_24 ( struct V_5 * V_6 , unsigned int V_1 )
{
int V_68 , V_69 , V_70 , V_11 = 0 ;
if ( V_6 -> V_71 )
goto V_15;
V_68 = F_1 ( V_1 ) ;
V_69 = V_6 -> V_72 [ V_68 ] . V_41 ;
V_70 = V_6 -> V_72 [ V_68 ] . V_42 ;
F_25 ( & V_6 -> V_52 ,
V_1 , V_69 , V_70 * 8 ) ;
V_69 = V_6 -> V_73 [ V_68 ] . V_41 ;
V_70 = V_6 -> V_73 [ V_68 ] . V_42 ;
F_25 ( & V_6 -> V_74 ,
V_1 , V_69 , V_70 * 8 ) ;
V_11 = F_26 ( & V_6 -> V_60 ,
F_27 ( & V_6 -> V_52 ) ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_26 ( & V_6 -> V_58 ,
F_27 ( & V_6 -> V_74 ) ) ;
if ( V_11 < 0 ) {
F_28 ( & V_6 -> V_60 ) ;
goto V_15;
}
V_6 -> V_71 = true ;
V_15:
return V_11 ;
}
static void
F_29 ( struct V_5 * V_6 )
{
F_28 ( & V_6 -> V_58 ) ;
F_28 ( & V_6 -> V_60 ) ;
V_6 -> V_71 = false ;
if ( V_6 -> V_75 != NULL )
F_7 ( 200 ) ;
}
static void
F_30 ( struct V_5 * V_6 )
{
F_29 ( V_6 ) ;
F_20 ( & V_6 -> V_58 ) ;
F_20 ( & V_6 -> V_60 ) ;
}
static int
F_31 ( struct V_5 * V_6 , enum V_76 * V_77 )
{
* V_77 = V_78 ;
return 0 ;
}
static int
F_32 ( struct V_5 * V_6 , struct V_35 * V_79 ,
unsigned int V_1 )
{
struct V_62 * V_63 ;
int V_11 = 0 ;
if ( V_79 == & V_6 -> V_74 )
V_63 = & V_6 -> V_58 ;
else
V_63 = & V_6 -> V_60 ;
if ( V_6 -> V_75 == NULL ) {
V_11 = F_12 ( V_6 , V_79 ) ;
if ( V_11 < 0 )
goto V_15;
}
V_11 = F_33 ( V_79 ,
V_63 -> V_80 . V_81 ,
V_63 -> V_82 ) ;
V_15:
return V_11 ;
}
int F_34 ( struct V_5 * V_6 )
{
int V_11 ;
V_11 = F_18 ( V_6 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_35 ( & V_6 -> V_52 , V_6 -> V_12 ,
V_83 , V_84 ) ;
if ( V_11 < 0 ) {
F_36 ( & V_6 -> V_52 ) ;
F_30 ( V_6 ) ;
goto V_15;
}
F_37 ( & V_6 -> V_85 ) ;
V_6 -> V_52 . V_86 |= V_87 ;
if ( V_6 -> V_75 )
V_6 -> V_52 . V_86 |= V_88 ;
V_11 = F_35 ( & V_6 -> V_74 , V_6 -> V_12 ,
V_89 , V_84 ) ;
if ( V_11 < 0 ) {
F_36 ( & V_6 -> V_52 ) ;
F_36 ( & V_6 -> V_74 ) ;
F_30 ( V_6 ) ;
}
V_15:
return V_11 ;
}
int F_38 ( struct V_5 * V_6 , unsigned int V_1 )
{
struct V_90 * V_91 = V_6 -> V_20 -> V_1 ;
struct V_35 * V_92 , * V_93 ;
T_2 * V_94 ;
enum V_76 V_77 ;
unsigned int V_7 ;
bool V_95 = false ;
int V_11 = 0 ;
if ( F_39 ( & V_6 -> V_52 ) ) {
if ( F_40 ( & V_6 -> V_85 ) )
F_41 ( & V_6 -> V_85 ) ;
V_95 = ( F_42 (
& V_6 -> V_85 ,
F_43 ( V_96 ) ) > 0 ) ;
}
F_44 ( & V_6 -> V_97 ) ;
if ( F_45 ( & V_6 -> V_98 ) == 0 &&
F_45 ( & V_6 -> V_99 ) == 0 )
goto V_15;
V_11 = F_31 ( V_6 , & V_77 ) ;
if ( V_11 < 0 )
goto V_15;
if ( V_77 == V_78 ) {
V_92 = & V_6 -> V_52 ;
V_93 = & V_6 -> V_74 ;
V_94 = & V_6 -> V_98 ;
} else {
V_92 = & V_6 -> V_74 ;
V_93 = & V_6 -> V_52 ;
V_94 = & V_6 -> V_99 ;
}
V_11 = F_21 ( V_6 , V_92 ) ;
if ( V_11 < 0 )
goto V_15;
if ( F_39 ( V_92 ) )
F_46 ( V_92 ) ;
if ( F_39 ( V_93 ) )
F_46 ( V_93 ) ;
if ( ! V_95 &&
! F_23 ( V_92 ) && ! F_23 ( V_93 ) )
F_29 ( V_6 ) ;
V_11 = V_91 -> V_25 ( V_6 , & V_7 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_9 , V_11 ) ;
goto V_15;
}
if ( V_1 == 0 )
V_1 = V_7 ;
if ( V_1 != V_7 ) {
F_46 ( V_92 ) ;
F_46 ( V_93 ) ;
F_29 ( V_6 ) ;
}
if ( ! F_23 ( V_92 ) ) {
F_47 ( V_77 , V_92 , V_93 ) ;
V_6 -> V_92 = V_92 ;
if ( V_6 -> V_75 == NULL ) {
V_11 = V_91 -> V_100 ( V_6 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_10 ,
V_11 ) ;
goto V_15;
}
}
V_11 = F_24 ( V_6 , V_1 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_32 ( V_6 , V_92 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_11 , V_11 ) ;
F_29 ( V_6 ) ;
goto V_15;
}
if ( V_6 -> V_75 != NULL ) {
V_11 = V_91 -> V_100 ( V_6 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_12 ,
V_11 ) ;
F_46 ( V_92 ) ;
F_29 ( V_6 ) ;
goto V_15;
}
}
if ( ! F_48 ( V_92 , V_101 ) ) {
F_46 ( V_92 ) ;
F_29 ( V_6 ) ;
V_11 = - V_102 ;
goto V_15;
}
}
if ( F_45 ( V_94 ) > 0 && ! F_23 ( V_93 ) ) {
V_11 = F_32 ( V_6 , V_93 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_13 , V_11 ) ;
F_46 ( V_92 ) ;
F_29 ( V_6 ) ;
goto V_15;
}
if ( ! F_48 ( V_93 , V_101 ) ) {
F_46 ( V_93 ) ;
F_46 ( V_92 ) ;
F_29 ( V_6 ) ;
V_11 = - V_102 ;
}
}
V_15:
F_49 ( & V_6 -> V_97 ) ;
return V_11 ;
}
void F_50 ( struct V_5 * V_6 )
{
struct V_35 * V_92 , * V_93 ;
T_2 * V_103 , * V_94 ;
if ( V_6 -> V_92 == & V_6 -> V_74 ) {
V_93 = & V_6 -> V_52 ;
V_92 = & V_6 -> V_74 ;
V_94 = & V_6 -> V_99 ;
V_103 = & V_6 -> V_98 ;
} else {
V_93 = & V_6 -> V_74 ;
V_92 = & V_6 -> V_52 ;
V_94 = & V_6 -> V_98 ;
V_103 = & V_6 -> V_99 ;
}
F_44 ( & V_6 -> V_97 ) ;
if ( F_45 ( V_94 ) == 0 ) {
F_51 ( V_93 ) ;
F_46 ( V_93 ) ;
if ( F_45 ( V_103 ) == 0 ) {
F_51 ( V_92 ) ;
F_46 ( V_92 ) ;
F_29 ( V_6 ) ;
}
}
F_49 ( & V_6 -> V_97 ) ;
}
void F_52 ( struct V_5 * V_6 )
{
F_44 ( & V_6 -> V_97 ) ;
if ( ( F_53 ( & V_6 -> V_58 ) < 0 ) ||
( F_53 ( & V_6 -> V_60 ) < 0 ) ) {
F_51 ( & V_6 -> V_74 ) ;
F_51 ( & V_6 -> V_52 ) ;
F_46 ( & V_6 -> V_74 ) ;
F_46 ( & V_6 -> V_52 ) ;
F_29 ( V_6 ) ;
} else {
F_54 ( & V_6 -> V_74 ) ;
F_54 ( & V_6 -> V_52 ) ;
}
if ( ! F_40 ( & V_6 -> V_85 ) )
F_55 ( & V_6 -> V_85 ) ;
F_49 ( & V_6 -> V_97 ) ;
}
void F_56 ( struct V_5 * V_6 )
{
F_44 ( & V_6 -> V_97 ) ;
F_51 ( & V_6 -> V_74 ) ;
F_51 ( & V_6 -> V_52 ) ;
F_46 ( & V_6 -> V_74 ) ;
F_46 ( & V_6 -> V_52 ) ;
F_36 ( & V_6 -> V_74 ) ;
F_36 ( & V_6 -> V_52 ) ;
F_30 ( V_6 ) ;
F_49 ( & V_6 -> V_97 ) ;
}
static int
F_57 ( T_1 * V_47 , unsigned int V_104 ,
struct V_105 * V_106 )
{
unsigned int V_2 , V_107 , V_40 , V_108 ;
if ( ( V_47 [ 0 ] != 0x90 ) || ( V_47 [ 1 ] != 0x40 ) )
return - V_54 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_109 ) ; V_2 ++ ) {
if ( V_47 [ 2 ] == V_109 [ V_2 ] )
break;
}
if ( V_2 == F_2 ( V_109 ) )
return - V_54 ;
memset ( & V_106 [ V_2 ] , 0 , sizeof( struct V_105 ) ) ;
for ( V_107 = 0 ; V_107 < V_47 [ 4 ] ; V_107 ++ ) {
V_40 = V_47 [ 5 + V_107 * 2 ] ;
V_108 = V_47 [ 6 + V_107 * 2 ] ;
switch ( V_108 ) {
case 0x00 :
case 0x06 :
V_106 [ V_2 ] . V_41 += V_40 ;
break;
case 0x0d :
V_106 [ V_2 ] . V_42 += V_40 ;
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
return - V_54 ;
}
}
if ( V_106 [ V_2 ] . V_41 > V_56 ||
V_106 [ V_2 ] . V_42 > V_110 )
return - V_54 ;
return 0 ;
}
static int
F_58 ( struct V_5 * V_6 , enum V_48 V_49 ,
unsigned short V_111 )
{
T_1 * V_47 ;
struct V_105 * V_112 ;
unsigned int V_104 , V_113 ;
T_1 V_21 [ V_22 ] ;
int V_11 ;
V_47 = F_59 ( V_114 , V_50 ) ;
if ( V_47 == NULL )
return - V_51 ;
if ( V_49 == V_32 )
V_112 = V_6 -> V_73 ;
else
V_112 = V_6 -> V_72 ;
for ( V_113 = 0 ; V_113 < V_115 ; V_113 ++ ) {
V_104 = V_114 ;
F_14 ( V_21 , V_49 ,
V_53 , V_111 ) ;
V_11 = F_60 ( V_6 -> V_12 , V_21 , V_47 ,
& V_104 , V_113 ) ;
if ( V_11 == - V_4 && V_113 > 0 ) {
V_11 = 0 ;
break;
} else if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_14 ,
V_113 ,
( V_49 == V_32 ) ? L_5 :
L_6 ,
V_111 , V_11 ) ;
break;
}
V_11 = F_57 ( V_47 , V_104 , V_112 ) ;
if ( V_11 < 0 )
break;
}
F_17 ( V_47 ) ;
return V_11 ;
}
static int
F_61 ( struct V_5 * V_6 )
{
T_1 V_116 [ V_117 ] , V_21 [ V_22 ] ;
unsigned int V_2 ;
enum V_118 type ;
int V_11 ;
V_11 = F_62 ( V_6 -> V_12 , 0x0c , 0x00 , 0x00 , V_116 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_15 ,
V_11 ) ;
goto V_15;
}
V_6 -> V_31 = - 1 ;
for ( V_2 = 0 ; V_2 < V_116 [ 0 ] ; V_2 ++ ) {
F_10 ( V_21 , V_32 , V_2 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_16 ,
V_2 , V_11 ) ;
goto V_15;
}
if ( type == V_119 ) {
V_6 -> V_31 = V_2 ;
break;
}
}
V_15:
return V_11 ;
}
int F_64 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 -> clock ;
T_1 V_116 [ V_117 ] , V_21 [ V_22 ] ;
enum V_118 type ;
unsigned int V_2 ;
int V_11 ;
V_11 = F_62 ( V_6 -> V_12 , 0x1f , 0x07 , 0x00 , V_116 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_17 ,
V_11 ) ;
goto V_15;
}
if ( ( V_116 [ 0 ] == 0 ) || ( V_116 [ 1 ] == 0 ) ) {
V_11 = - V_54 ;
goto V_15;
}
F_14 ( V_21 , V_32 ,
V_53 , 0 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_18 , V_11 ) ;
goto V_15;
} else if ( type != V_120 ) {
V_11 = - V_54 ;
goto V_15;
}
V_11 = F_58 ( V_6 , V_32 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
F_14 ( V_21 , V_33 ,
V_53 , 0 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_19 , V_11 ) ;
goto V_15;
} else if ( type != V_120 ) {
V_11 = - V_54 ;
goto V_15;
}
V_11 = F_58 ( V_6 , V_33 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_6 -> V_121 = 0 ;
for ( V_2 = 0 ; V_2 < V_116 [ 2 ] ; V_2 ++ ) {
F_14 ( V_21 , V_32 ,
V_122 , V_2 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_20 ,
V_2 , V_11 ) ;
goto V_15;
} else if ( type == V_123 ) {
V_6 -> V_121 ++ ;
}
}
V_6 -> V_124 = 0 ;
for ( V_2 = 0 ; V_2 < V_116 [ 3 ] ; V_2 ++ ) {
F_14 ( V_21 , V_33 ,
V_122 , V_2 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_21 ,
V_2 , V_11 ) ;
goto V_15;
} else if ( type == V_123 ) {
V_6 -> V_124 ++ ;
}
}
if ( ! V_19 )
V_11 = F_61 ( V_6 ) ;
V_15:
return V_11 ;
}
void F_65 ( struct V_5 * V_6 )
{
V_6 -> V_125 = true ;
F_66 ( & V_6 -> V_126 ) ;
}
int F_67 ( struct V_5 * V_6 )
{
int V_11 ;
F_68 ( & V_6 -> V_127 ) ;
if ( V_6 -> V_128 < 0 ) {
V_11 = - V_67 ;
goto V_15;
}
if ( V_6 -> V_128 ++ == 0 )
F_65 ( V_6 ) ;
V_11 = 0 ;
V_15:
F_69 ( & V_6 -> V_127 ) ;
return V_11 ;
}
void F_70 ( struct V_5 * V_6 )
{
F_68 ( & V_6 -> V_127 ) ;
if ( F_71 ( V_6 -> V_128 <= 0 ) )
goto V_15;
if ( -- V_6 -> V_128 == 0 )
F_65 ( V_6 ) ;
V_15:
F_69 ( & V_6 -> V_127 ) ;
}
