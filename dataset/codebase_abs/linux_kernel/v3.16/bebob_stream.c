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
if ( V_11 < 0 )
F_9 ( & V_6 -> V_12 -> V_26 ,
L_1 , V_11 ) ;
else if ( strncmp ( V_19 -> V_27 [ V_24 ] , V_28 ,
strlen ( V_28 ) ) == 0 )
* V_17 = true ;
goto V_15;
}
if ( V_6 -> V_29 < 0 ) {
* V_17 = true ;
goto V_15;
}
F_10 ( V_21 , V_30 ,
V_6 -> V_29 ) ;
V_11 = F_11 ( V_6 -> V_12 , V_21 , V_23 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_2 ,
V_6 -> V_29 , V_11 ) ;
goto V_15;
}
if ( V_23 [ 0 ] == 0xff ) {
* V_17 = true ;
goto V_15;
}
* V_17 = ( ( V_23 [ 0 ] == V_31 ) &&
( V_23 [ 1 ] == V_32 ) &&
( V_23 [ 2 ] == 0x0c ) &&
( V_23 [ 3 ] == 0x00 ) ) ;
V_15:
return V_11 ;
}
static unsigned int
F_12 ( struct V_5 * V_6 , struct V_33 * V_34 )
{
unsigned int V_35 , V_36 , V_37 , V_38 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
T_1 * V_45 , V_21 [ V_22 ] , type ;
enum V_46 V_47 ;
int V_11 ;
V_45 = F_13 ( 256 , V_48 ) ;
if ( V_45 == NULL )
return - V_49 ;
if ( V_34 == & V_6 -> V_50 )
V_47 = V_31 ;
else
V_47 = V_30 ;
F_14 ( V_21 , V_47 , V_51 , 0 ) ;
V_11 = F_15 ( V_6 -> V_12 , V_21 , V_45 , 256 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_3 ,
( V_47 == V_30 ) ? L_4 : L_5 ,
V_11 ) ;
goto V_15;
}
V_44 = 0 ;
V_39 = 0 ;
V_40 = 0 ;
V_36 = V_45 [ V_44 ++ ] ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
F_14 ( V_21 , V_47 ,
V_51 , 0 ) ;
V_11 = F_16 ( V_6 -> V_12 , V_21 ,
V_35 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_6 ,
( V_47 == V_30 ) ? L_4 :
L_5 ,
V_11 ) ;
goto V_15;
}
if ( type == 0xff ) {
V_11 = - V_52 ;
goto V_15;
}
V_38 = V_45 [ V_44 ++ ] ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_42 = V_45 [ V_44 ++ ] - 1 ;
V_43 = V_45 [ V_44 ++ ] - 1 ;
if ( V_43 >= V_38 )
V_43 = V_37 ;
switch ( type ) {
case 0x0a :
if ( ( V_40 > 0 ) && ( V_42 != V_40 ) ) {
V_11 = - V_52 ;
goto V_15;
}
V_34 -> V_53 = V_42 ;
V_40 = V_42 ;
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
V_41 = V_39 + V_43 ;
if ( V_41 >= V_54 ) {
V_11 = - V_52 ;
goto V_15;
}
V_34 -> V_55 [ V_41 ] = V_42 ;
break;
}
}
if ( type != 0x0a )
V_39 += V_38 ;
else
V_40 += V_38 ;
}
V_15:
F_17 ( V_45 ) ;
return V_11 ;
}
static int
F_18 ( struct V_5 * V_6 )
{
int V_11 ;
V_11 = F_19 ( & V_6 -> V_56 ,
V_6 -> V_12 , V_57 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_19 ( & V_6 -> V_58 ,
V_6 -> V_12 , V_59 , 0 ) ;
if ( V_11 < 0 )
F_20 ( & V_6 -> V_56 ) ;
V_15:
return V_11 ;
}
static int
F_21 ( struct V_5 * V_6 , struct V_33 * V_34 )
{
struct V_60 * V_61 ;
bool V_62 ;
int V_11 ;
if ( V_34 == & V_6 -> V_50 )
V_61 = & V_6 -> V_58 ;
else
V_61 = & V_6 -> V_56 ;
V_11 = F_22 ( V_61 , & V_62 ) ;
if ( ( V_11 >= 0 ) && V_62 && ! F_23 ( V_34 ) ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_7 ,
( V_61 -> V_63 == V_59 ) ? 'o' : 'i' ,
V_61 -> V_64 ) ;
V_11 = - V_65 ;
}
return V_11 ;
}
static int
F_24 ( struct V_5 * V_6 , unsigned int V_1 )
{
int V_66 , V_67 , V_68 , V_11 = 0 ;
if ( V_6 -> V_69 )
goto V_15;
V_66 = F_1 ( V_1 ) ;
V_67 = V_6 -> V_70 [ V_66 ] . V_39 ;
V_68 = V_6 -> V_70 [ V_66 ] . V_40 ;
F_25 ( & V_6 -> V_50 ,
V_1 , V_67 , V_68 * 8 ) ;
V_67 = V_6 -> V_71 [ V_66 ] . V_39 ;
V_68 = V_6 -> V_71 [ V_66 ] . V_40 ;
F_25 ( & V_6 -> V_72 ,
V_1 , V_67 , V_68 * 8 ) ;
V_11 = F_26 ( & V_6 -> V_58 ,
F_27 ( & V_6 -> V_50 ) ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_26 ( & V_6 -> V_56 ,
F_27 ( & V_6 -> V_72 ) ) ;
if ( V_11 < 0 ) {
F_28 ( & V_6 -> V_58 ) ;
goto V_15;
}
V_6 -> V_69 = true ;
V_15:
return V_11 ;
}
static void
F_29 ( struct V_5 * V_6 )
{
F_28 ( & V_6 -> V_56 ) ;
F_28 ( & V_6 -> V_58 ) ;
V_6 -> V_69 = false ;
if ( V_6 -> V_73 != NULL )
F_7 ( 200 ) ;
}
static void
F_30 ( struct V_5 * V_6 )
{
F_29 ( V_6 ) ;
F_20 ( & V_6 -> V_56 ) ;
F_20 ( & V_6 -> V_58 ) ;
}
static int
F_31 ( struct V_5 * V_6 , enum V_74 * V_75 )
{
* V_75 = V_76 ;
return 0 ;
}
static int
F_32 ( struct V_5 * V_6 , struct V_33 * V_77 ,
unsigned int V_1 )
{
struct V_60 * V_61 ;
int V_11 = 0 ;
if ( V_77 == & V_6 -> V_72 )
V_61 = & V_6 -> V_56 ;
else
V_61 = & V_6 -> V_58 ;
if ( V_6 -> V_73 == NULL ) {
V_11 = F_12 ( V_6 , V_77 ) ;
if ( V_11 < 0 )
goto V_15;
}
V_11 = F_33 ( V_77 ,
V_61 -> V_78 . V_79 ,
V_61 -> V_80 ) ;
V_15:
return V_11 ;
}
int F_34 ( struct V_5 * V_6 )
{
int V_11 ;
V_11 = F_18 ( V_6 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_35 ( & V_6 -> V_50 , V_6 -> V_12 ,
V_81 , V_82 ) ;
if ( V_11 < 0 ) {
F_36 ( & V_6 -> V_50 ) ;
F_30 ( V_6 ) ;
goto V_15;
}
F_37 ( & V_6 -> V_83 ) ;
V_6 -> V_50 . V_84 |= V_85 ;
if ( V_6 -> V_73 )
V_6 -> V_50 . V_84 |= V_86 ;
V_11 = F_35 ( & V_6 -> V_72 , V_6 -> V_12 ,
V_87 , V_82 ) ;
if ( V_11 < 0 ) {
F_36 ( & V_6 -> V_50 ) ;
F_36 ( & V_6 -> V_72 ) ;
F_30 ( V_6 ) ;
}
if ( V_6 -> V_20 == & V_88 ||
V_6 -> V_20 == & V_89 )
V_6 -> V_72 . V_90 = 8 ;
V_15:
return V_11 ;
}
int F_38 ( struct V_5 * V_6 , unsigned int V_1 )
{
struct V_91 * V_92 = V_6 -> V_20 -> V_1 ;
struct V_33 * V_93 , * V_94 ;
T_2 * V_95 ;
enum V_74 V_75 ;
unsigned int V_7 ;
bool V_96 = false ;
int V_11 = 0 ;
if ( F_39 ( & V_6 -> V_50 ) ) {
if ( F_40 ( & V_6 -> V_83 ) )
F_41 ( & V_6 -> V_83 ) ;
V_96 = ( F_42 (
& V_6 -> V_83 ,
F_43 ( V_97 ) ) > 0 ) ;
}
F_44 ( & V_6 -> V_98 ) ;
if ( F_45 ( & V_6 -> V_99 ) == 0 &&
F_45 ( & V_6 -> V_100 ) == 0 )
goto V_15;
V_11 = F_31 ( V_6 , & V_75 ) ;
if ( V_11 < 0 )
goto V_15;
if ( V_75 == V_76 ) {
V_93 = & V_6 -> V_50 ;
V_94 = & V_6 -> V_72 ;
V_95 = & V_6 -> V_99 ;
} else {
V_93 = & V_6 -> V_72 ;
V_94 = & V_6 -> V_50 ;
V_95 = & V_6 -> V_100 ;
}
V_11 = F_21 ( V_6 , V_93 ) ;
if ( V_11 < 0 )
goto V_15;
if ( F_39 ( V_93 ) )
F_46 ( V_93 ) ;
if ( F_39 ( V_94 ) )
F_46 ( V_94 ) ;
if ( ! V_96 &&
! F_23 ( V_93 ) && ! F_23 ( V_94 ) )
F_29 ( V_6 ) ;
V_11 = V_92 -> V_25 ( V_6 , & V_7 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_8 , V_11 ) ;
goto V_15;
}
if ( V_1 == 0 )
V_1 = V_7 ;
if ( V_1 != V_7 ) {
F_46 ( V_93 ) ;
F_46 ( V_94 ) ;
F_29 ( V_6 ) ;
}
if ( ! F_23 ( V_93 ) ) {
F_47 ( V_75 , V_93 , V_94 ) ;
V_6 -> V_93 = V_93 ;
if ( V_6 -> V_73 == NULL ) {
V_11 = V_92 -> V_101 ( V_6 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_9 ,
V_11 ) ;
goto V_15;
}
}
V_11 = F_24 ( V_6 , V_1 ) ;
if ( V_11 < 0 )
goto V_15;
V_11 = F_32 ( V_6 , V_93 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_10 , V_11 ) ;
F_29 ( V_6 ) ;
goto V_15;
}
if ( V_6 -> V_73 != NULL ) {
V_11 = V_92 -> V_101 ( V_6 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_11 ,
V_11 ) ;
F_46 ( V_93 ) ;
F_29 ( V_6 ) ;
goto V_15;
}
}
if ( ! F_48 ( V_93 , V_102 ) ) {
F_46 ( V_93 ) ;
F_29 ( V_6 ) ;
V_11 = - V_103 ;
goto V_15;
}
}
if ( F_45 ( V_95 ) > 0 && ! F_23 ( V_94 ) ) {
V_11 = F_32 ( V_6 , V_94 , V_1 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_12 , V_11 ) ;
F_46 ( V_93 ) ;
F_29 ( V_6 ) ;
goto V_15;
}
if ( ! F_48 ( V_94 , V_102 ) ) {
F_46 ( V_94 ) ;
F_46 ( V_93 ) ;
F_29 ( V_6 ) ;
V_11 = - V_103 ;
}
}
V_15:
F_49 ( & V_6 -> V_98 ) ;
return V_11 ;
}
void F_50 ( struct V_5 * V_6 )
{
struct V_33 * V_93 , * V_94 ;
T_2 * V_104 , * V_95 ;
if ( V_6 -> V_93 == & V_6 -> V_72 ) {
V_94 = & V_6 -> V_50 ;
V_93 = & V_6 -> V_72 ;
V_95 = & V_6 -> V_100 ;
V_104 = & V_6 -> V_99 ;
} else {
V_94 = & V_6 -> V_72 ;
V_93 = & V_6 -> V_50 ;
V_95 = & V_6 -> V_99 ;
V_104 = & V_6 -> V_100 ;
}
F_44 ( & V_6 -> V_98 ) ;
if ( F_45 ( V_95 ) == 0 ) {
F_51 ( V_94 ) ;
F_46 ( V_94 ) ;
if ( F_45 ( V_104 ) == 0 ) {
F_51 ( V_93 ) ;
F_46 ( V_93 ) ;
F_29 ( V_6 ) ;
}
}
F_49 ( & V_6 -> V_98 ) ;
}
void F_52 ( struct V_5 * V_6 )
{
F_44 ( & V_6 -> V_98 ) ;
if ( ( F_53 ( & V_6 -> V_56 ) < 0 ) ||
( F_53 ( & V_6 -> V_58 ) < 0 ) ) {
F_51 ( & V_6 -> V_72 ) ;
F_51 ( & V_6 -> V_50 ) ;
F_46 ( & V_6 -> V_72 ) ;
F_46 ( & V_6 -> V_50 ) ;
F_29 ( V_6 ) ;
} else {
F_54 ( & V_6 -> V_72 ) ;
F_54 ( & V_6 -> V_50 ) ;
}
if ( ! F_40 ( & V_6 -> V_83 ) )
F_55 ( & V_6 -> V_83 ) ;
F_49 ( & V_6 -> V_98 ) ;
}
void F_56 ( struct V_5 * V_6 )
{
F_44 ( & V_6 -> V_98 ) ;
F_51 ( & V_6 -> V_72 ) ;
F_51 ( & V_6 -> V_50 ) ;
F_46 ( & V_6 -> V_72 ) ;
F_46 ( & V_6 -> V_50 ) ;
F_36 ( & V_6 -> V_72 ) ;
F_36 ( & V_6 -> V_50 ) ;
F_30 ( V_6 ) ;
F_49 ( & V_6 -> V_98 ) ;
}
static int
F_57 ( T_1 * V_45 , unsigned int V_105 ,
struct V_106 * V_107 )
{
unsigned int V_2 , V_108 , V_38 , V_109 ;
if ( ( V_45 [ 0 ] != 0x90 ) || ( V_45 [ 1 ] != 0x40 ) )
return - V_52 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_110 ) ; V_2 ++ ) {
if ( V_45 [ 2 ] == V_110 [ V_2 ] )
break;
}
if ( V_2 == F_2 ( V_110 ) )
return - V_52 ;
memset ( & V_107 [ V_2 ] , 0 , sizeof( struct V_106 ) ) ;
for ( V_108 = 0 ; V_108 < V_45 [ 4 ] ; V_108 ++ ) {
V_38 = V_45 [ 5 + V_108 * 2 ] ;
V_109 = V_45 [ 6 + V_108 * 2 ] ;
switch ( V_109 ) {
case 0x00 :
case 0x06 :
V_107 [ V_2 ] . V_39 += V_38 ;
break;
case 0x0d :
V_107 [ V_2 ] . V_40 += V_38 ;
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
return - V_52 ;
}
}
if ( V_107 [ V_2 ] . V_39 > V_54 ||
V_107 [ V_2 ] . V_40 > V_111 )
return - V_52 ;
return 0 ;
}
static int
F_58 ( struct V_5 * V_6 , enum V_46 V_47 ,
unsigned short V_112 )
{
T_1 * V_45 ;
struct V_106 * V_113 ;
unsigned int V_105 , V_114 ;
T_1 V_21 [ V_22 ] ;
int V_11 ;
V_45 = F_59 ( V_115 , V_48 ) ;
if ( V_45 == NULL )
return - V_49 ;
if ( V_47 == V_30 )
V_113 = V_6 -> V_71 ;
else
V_113 = V_6 -> V_70 ;
for ( V_114 = 0 ; V_114 < V_116 ; V_114 ++ ) {
V_105 = V_115 ;
F_14 ( V_21 , V_47 ,
V_51 , V_112 ) ;
V_11 = F_60 ( V_6 -> V_12 , V_21 , V_45 ,
& V_105 , V_114 ) ;
if ( V_11 == - V_4 && V_114 > 0 ) {
V_11 = 0 ;
break;
} else if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_13 ,
V_114 ,
( V_47 == V_30 ) ? L_4 :
L_5 ,
V_112 , V_11 ) ;
break;
}
V_11 = F_57 ( V_45 , V_105 , V_113 ) ;
if ( V_11 < 0 )
break;
}
F_17 ( V_45 ) ;
return V_11 ;
}
static int
F_61 ( struct V_5 * V_6 )
{
T_1 V_117 [ V_118 ] , V_21 [ V_22 ] ;
unsigned int V_2 ;
enum V_119 type ;
int V_11 ;
V_11 = F_62 ( V_6 -> V_12 , 0x0c , 0x00 , 0x00 , V_117 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_14 ,
V_11 ) ;
goto V_15;
}
V_6 -> V_29 = - 1 ;
for ( V_2 = 0 ; V_2 < V_117 [ 0 ] ; V_2 ++ ) {
F_10 ( V_21 , V_30 , V_2 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_15 ,
V_2 , V_11 ) ;
goto V_15;
}
if ( type == V_120 ) {
V_6 -> V_29 = V_2 ;
break;
}
}
V_15:
return V_11 ;
}
int F_64 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 -> clock ;
T_1 V_117 [ V_118 ] , V_21 [ V_22 ] ;
enum V_119 type ;
unsigned int V_2 ;
int V_11 ;
V_11 = F_62 ( V_6 -> V_12 , 0x1f , 0x07 , 0x00 , V_117 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_16 ,
V_11 ) ;
goto V_15;
}
if ( ( V_117 [ 0 ] == 0 ) || ( V_117 [ 1 ] == 0 ) ) {
V_11 = - V_52 ;
goto V_15;
}
F_14 ( V_21 , V_30 ,
V_51 , 0 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_17 , V_11 ) ;
goto V_15;
} else if ( type != V_121 ) {
V_11 = - V_52 ;
goto V_15;
}
V_11 = F_58 ( V_6 , V_30 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
F_14 ( V_21 , V_31 ,
V_51 , 0 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_18 , V_11 ) ;
goto V_15;
} else if ( type != V_121 ) {
V_11 = - V_52 ;
goto V_15;
}
V_11 = F_58 ( V_6 , V_31 , 0 ) ;
if ( V_11 < 0 )
goto V_15;
V_6 -> V_122 = 0 ;
for ( V_2 = 0 ; V_2 < V_117 [ 2 ] ; V_2 ++ ) {
F_14 ( V_21 , V_30 ,
V_123 , V_2 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_19 ,
V_2 , V_11 ) ;
goto V_15;
} else if ( type == V_124 ) {
V_6 -> V_122 ++ ;
}
}
V_6 -> V_125 = 0 ;
for ( V_2 = 0 ; V_2 < V_117 [ 3 ] ; V_2 ++ ) {
F_14 ( V_21 , V_31 ,
V_123 , V_2 ) ;
V_11 = F_63 ( V_6 -> V_12 , V_21 , & type ) ;
if ( V_11 < 0 ) {
F_9 ( & V_6 -> V_12 -> V_26 ,
L_20 ,
V_2 , V_11 ) ;
goto V_15;
} else if ( type == V_124 ) {
V_6 -> V_125 ++ ;
}
}
if ( ! V_19 )
V_11 = F_61 ( V_6 ) ;
V_15:
return V_11 ;
}
void F_65 ( struct V_5 * V_6 )
{
V_6 -> V_126 = true ;
F_66 ( & V_6 -> V_127 ) ;
}
int F_67 ( struct V_5 * V_6 )
{
int V_11 ;
F_68 ( & V_6 -> V_128 ) ;
if ( V_6 -> V_129 < 0 ) {
V_11 = - V_65 ;
goto V_15;
}
if ( V_6 -> V_129 ++ == 0 )
F_65 ( V_6 ) ;
V_11 = 0 ;
V_15:
F_69 ( & V_6 -> V_128 ) ;
return V_11 ;
}
void F_70 ( struct V_5 * V_6 )
{
F_68 ( & V_6 -> V_128 ) ;
if ( F_71 ( V_6 -> V_129 <= 0 ) )
goto V_15;
if ( -- V_6 -> V_129 == 0 )
F_65 ( V_6 ) ;
V_15:
F_69 ( & V_6 -> V_128 ) ;
}
