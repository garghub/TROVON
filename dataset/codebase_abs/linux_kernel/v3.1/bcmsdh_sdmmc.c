static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
T_2 V_5 ;
F_2 ( ( L_1 , V_6 ) ) ;
V_2 -> V_7 = F_3 ( V_2 , V_8 ) ;
V_2 -> V_9 [ 0 ] = V_2 -> V_7 ;
F_4 ( ( L_2 , V_6 ,
V_2 -> V_7 ) ) ;
for ( V_4 = F_5 ( 1 ) , V_5 = 1 ;
V_5 <= V_2 -> V_10 ; V_5 ++ , V_4 += V_11 ) {
V_2 -> V_9 [ V_5 ] =
F_3 ( V_2 , V_12 + V_4 ) ;
F_4 ( ( L_3 , V_6 , V_5 ,
V_2 -> V_9 [ V_5 ] ) ) ;
}
V_2 -> V_9 [ 0 ] = V_2 -> V_7 ;
F_4 ( ( L_2 , V_6 ,
V_2 -> V_7 ) ) ;
F_6 ( V_13 -> V_5 [ 1 ] ) ;
V_3 = F_7 ( V_13 -> V_5 [ 1 ] ) ;
F_8 ( V_13 -> V_5 [ 1 ] ) ;
if ( V_3 ) {
F_9 ( ( L_4
L_5 , V_3 ) ) ;
}
return false ;
}
struct V_1 * F_10 ( void * V_14 , T_3 V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_2 ( ( L_1 , V_6 ) ) ;
if ( V_13 == NULL ) {
F_9 ( ( L_6 , V_6 ) ) ;
return NULL ;
}
V_2 = F_11 ( sizeof( struct V_1 ) , V_16 ) ;
if ( V_2 == NULL ) {
F_9 ( ( L_7 ) ) ;
return NULL ;
}
if ( F_12 ( V_2 ) != 0 ) {
F_9 ( ( L_8 , V_6 ) ) ;
F_13 ( V_2 ) ;
return NULL ;
}
V_2 -> V_10 = 2 ;
V_2 -> V_17 = true ;
V_2 -> V_18 [ 0 ] = 64 ;
V_13 -> V_2 = V_2 ;
F_6 ( V_13 -> V_5 [ 1 ] ) ;
V_2 -> V_18 [ 1 ] = 64 ;
V_3 = F_14 ( V_13 -> V_5 [ 1 ] , 64 ) ;
if ( V_3 )
F_9 ( ( L_9 ) ) ;
F_8 ( V_13 -> V_5 [ 1 ] ) ;
if ( V_13 -> V_5 [ 2 ] ) {
F_6 ( V_13 -> V_5 [ 2 ] ) ;
V_2 -> V_18 [ 2 ] = V_19 ;
V_3 =
F_14 ( V_13 -> V_5 [ 2 ] , V_19 ) ;
if ( V_3 )
F_9 ( ( L_10
L_11 , V_19 ) ) ;
F_8 ( V_13 -> V_5 [ 2 ] ) ;
}
F_1 ( V_2 ) ;
F_2 ( ( L_12 , V_6 ) ) ;
return V_2 ;
}
extern int F_15 ( struct V_1 * V_2 )
{
F_2 ( ( L_1 , V_6 ) ) ;
if ( V_2 ) {
F_6 ( V_13 -> V_5 [ 2 ] ) ;
F_16 ( V_13 -> V_5 [ 2 ] ) ;
F_8 ( V_13 -> V_5 [ 2 ] ) ;
F_6 ( V_13 -> V_5 [ 1 ] ) ;
F_16 ( V_13 -> V_5 [ 1 ] ) ;
F_8 ( V_13 -> V_5 [ 1 ] ) ;
F_17 ( V_2 ) ;
F_13 ( V_2 ) ;
}
return 0 ;
}
extern int
F_18 ( struct V_1 * V_2 , void (* F_19)( void * ) ,
void * V_20 )
{
F_2 ( ( L_13 , V_6 ) ) ;
if ( F_19 == NULL ) {
F_9 ( ( L_14 ,
V_6 ) ) ;
return - V_21 ;
}
V_2 -> V_22 = F_19 ;
V_2 -> V_23 = V_20 ;
V_2 -> V_24 = true ;
if ( V_13 -> V_5 [ 2 ] ) {
F_6 ( V_13 -> V_5 [ 2 ] ) ;
F_20 ( V_13 -> V_5 [ 2 ] , V_25 ) ;
F_8 ( V_13 -> V_5 [ 2 ] ) ;
}
if ( V_13 -> V_5 [ 1 ] ) {
F_6 ( V_13 -> V_5 [ 1 ] ) ;
F_20 ( V_13 -> V_5 [ 1 ] , V_26 ) ;
F_8 ( V_13 -> V_5 [ 1 ] ) ;
}
return 0 ;
}
extern int F_21 ( struct V_1 * V_2 )
{
F_2 ( ( L_13 , V_6 ) ) ;
if ( V_13 -> V_5 [ 1 ] ) {
F_6 ( V_13 -> V_5 [ 1 ] ) ;
F_22 ( V_13 -> V_5 [ 1 ] ) ;
F_8 ( V_13 -> V_5 [ 1 ] ) ;
}
if ( V_13 -> V_5 [ 2 ] ) {
F_6 ( V_13 -> V_5 [ 2 ] ) ;
F_22 ( V_13 -> V_5 [ 2 ] ) ;
F_8 ( V_13 -> V_5 [ 2 ] ) ;
}
V_2 -> V_24 = false ;
V_2 -> V_22 = NULL ;
V_2 -> V_23 = NULL ;
return 0 ;
}
int
F_23 ( struct V_1 * V_27 , const char * V_28 ,
void * V_29 , int V_30 , void * V_31 , int V_32 , bool V_33 )
{
const struct V_34 * V_35 = NULL ;
int V_36 = 0 ;
int V_37 ;
T_4 V_38 = 0 ;
bool V_39 ;
T_1 V_40 ;
if ( V_28 == NULL || V_32 <= 0 )
return - V_21 ;
if ( V_33 && ( V_29 || V_30 ) )
return - V_21 ;
if ( ! V_33 && ! ( V_31 && V_32 ) )
return - V_21 ;
F_2 ( ( L_15 , V_6 , ( V_33 ? L_16 : L_17 ) ,
V_28 ) ) ;
V_35 = F_24 ( V_41 , V_28 ) ;
if ( V_35 == NULL ) {
V_36 = - V_42 ;
goto exit;
}
V_36 = F_25 ( V_35 , V_31 , V_32 , V_33 ) ;
if ( V_36 != 0 )
goto exit;
if ( V_29 == NULL ) {
V_29 = V_31 ;
V_30 = V_32 ;
}
if ( V_35 -> type == V_43 )
V_37 = 0 ;
else if ( V_35 -> type == V_44 )
V_37 = V_32 ;
else
V_37 = sizeof( int ) ;
if ( V_30 >= ( int ) sizeof( V_38 ) )
memcpy ( & V_38 , V_29 , sizeof( V_38 ) ) ;
V_39 = ( V_38 != 0 ) ? true : false ;
V_40 = V_33 ? F_26 ( V_35 -> V_45 ) : F_27 ( V_35 -> V_45 ) ;
switch ( V_40 ) {
case F_27 ( V_46 ) :
V_38 = ( T_4 ) V_47 ;
memcpy ( V_31 , & V_38 , V_37 ) ;
break;
case F_26 ( V_46 ) :
V_47 = V_38 ;
break;
case F_27 ( V_48 ) :
if ( ( T_1 ) V_38 > V_27 -> V_10 ) {
V_36 = - V_21 ;
break;
}
V_38 = ( T_4 ) V_27 -> V_18 [ V_38 ] ;
memcpy ( V_31 , & V_38 , V_37 ) ;
break;
case F_26 ( V_48 ) :
{
T_3 V_5 = ( ( T_1 ) V_38 >> 16 ) ;
T_3 V_49 = ( V_50 ) V_38 ;
T_3 V_51 ;
if ( V_5 > V_27 -> V_10 ) {
V_36 = - V_21 ;
break;
}
switch ( V_5 ) {
case 0 :
V_51 = 32 ;
break;
case 1 :
V_51 = V_52 ;
break;
case 2 :
V_51 = V_53 ;
break;
default:
V_51 = 0 ;
}
if ( V_49 > V_51 ) {
V_36 = - V_21 ;
break;
}
if ( ! V_49 )
V_49 = V_51 ;
V_27 -> V_18 [ V_5 ] = V_49 ;
break;
}
case F_27 ( V_54 ) :
V_38 = false ;
memcpy ( V_31 , & V_38 , V_37 ) ;
break;
case F_27 ( V_55 ) :
V_38 = ( T_4 ) V_27 -> V_17 ;
memcpy ( V_31 , & V_38 , V_37 ) ;
break;
case F_26 ( V_55 ) :
V_27 -> V_17 = ( bool ) V_38 ;
if ( V_27 -> V_17 )
V_27 -> V_56 |= V_57 ;
else
V_27 -> V_56 &= ~ V_57 ;
break;
case F_27 ( V_58 ) :
V_38 = ( T_4 ) V_27 -> V_59 ;
memcpy ( V_31 , & V_38 , V_37 ) ;
break;
case F_27 ( V_60 ) :
{
struct V_61 * V_62 =
(struct V_61 * ) V_29 ;
T_2 V_63 = 0 ;
if ( F_28
( V_27 , V_62 -> V_5 , V_62 -> V_64 , & V_63 ) ) {
V_36 = - V_65 ;
break;
}
V_38 = ( int ) V_63 ;
memcpy ( V_31 , & V_38 , sizeof( V_38 ) ) ;
break;
}
case F_26 ( V_60 ) :
{
struct V_61 * V_62 =
(struct V_61 * ) V_29 ;
T_2 V_63 = ( T_2 ) V_62 -> V_66 ;
if ( F_29
( V_27 , V_62 -> V_5 , V_62 -> V_64 , & V_63 ) ) {
V_36 = - V_65 ;
break;
}
break;
}
default:
V_36 = - V_42 ;
break;
}
exit:
return V_36 ;
}
extern int
F_28 ( struct V_1 * V_2 , T_3 V_67 , T_1 V_68 , T_2 * V_63 )
{
int V_69 ;
V_69 = F_30 ( V_2 , V_70 , V_67 , V_68 , V_63 ) ;
return V_69 ;
}
extern int
F_29 ( struct V_1 * V_2 , T_3 V_67 , T_1 V_68 , T_2 * V_63 )
{
int V_69 ;
V_69 = F_30 ( V_2 , V_71 , V_67 , V_68 , V_63 ) ;
return V_69 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_72 )
{
int V_73 ;
T_1 V_74 , V_75 ;
T_2 * V_76 = ( T_2 * ) & V_74 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ ) {
if ( ( F_31 ( V_2 , 0 , V_72 , 1 , & V_75 ) ) !=
V_77 )
F_9 ( ( L_18 , V_6 ) ) ;
* V_76 ++ = ( T_2 ) V_75 ;
V_72 ++ ;
}
V_74 = F_32 ( V_74 ) ;
V_74 &= 0x0001FFFF ;
return V_74 ;
}
extern int
F_33 ( struct V_1 * V_2 , T_3 V_5 , T_2 * V_78 , T_1 V_79 )
{
T_1 V_80 ;
int V_64 ;
T_1 V_81 ;
T_2 * V_82 = V_78 ;
F_2 ( ( L_19 , V_6 , V_5 ) ) ;
if ( ! V_2 -> V_9 [ V_5 ] ) {
memset ( V_82 , 0 , V_79 ) ;
F_9 ( ( L_20 , V_6 , V_5 ) ) ;
return - V_42 ;
}
F_9 ( ( L_21 , V_6 , V_5 ,
V_2 -> V_9 [ V_5 ] ) ) ;
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_64 = V_2 -> V_9 [ V_5 ] + V_80 ;
if ( F_31 ( V_2 , 0 , V_64 , 1 , & V_81 ) < 0 ) {
F_9 ( ( L_22 ,
V_6 ) ) ;
return - V_65 ;
}
* V_82 = ( T_2 ) ( V_81 & 0xff ) ;
V_82 ++ ;
}
return 0 ;
}
extern int
F_30 ( struct V_1 * V_2 , T_3 V_83 , T_3 V_5 ,
T_3 V_72 , T_2 * V_84 )
{
int V_3 ;
F_4 ( ( L_23 , V_6 , V_83 , V_5 ,
V_72 ) ) ;
F_34 ( V_85 ) ;
F_35 ( - V_65 ) ;
if ( V_83 ) {
if ( V_5 == 0 ) {
if ( V_72 == V_86 ) {
if ( V_13 -> V_5 [ 2 ] ) {
F_6 ( V_13 -> V_5 [ 2 ] ) ;
if ( * V_84 & V_87 ) {
V_3 =
F_7
( V_13 -> V_5 [ 2 ] ) ;
if ( V_3 )
F_9 ( ( L_24
L_25
L_26 ,
V_3 ) ) ;
} else {
V_3 =
F_16
( V_13 -> V_5 [ 2 ] ) ;
if ( V_3 )
F_9 ( ( L_24
L_27
L_26 ,
V_3 ) ) ;
}
F_8 ( V_13 -> V_5 [ 2 ] ) ;
}
}
else if ( V_72 == V_88 ) {
F_6 ( V_13 -> V_5 [ V_5 ] ) ;
F_36 ( V_13 -> V_5 [ V_5 ] , * V_84 ,
V_72 , & V_3 ) ;
F_8 ( V_13 -> V_5 [ V_5 ] ) ;
} else if ( V_72 < 0xF0 ) {
F_9 ( ( L_28
L_29 , V_72 ) ) ;
} else {
F_6 ( V_13 -> V_5 [ V_5 ] ) ;
F_37 ( V_13 -> V_5 [ V_5 ] , * V_84 ,
V_72 , & V_3 ) ;
F_8 ( V_13 -> V_5 [ V_5 ] ) ;
}
} else {
F_6 ( V_13 -> V_5 [ V_5 ] ) ;
F_36 ( V_13 -> V_5 [ V_5 ] , * V_84 , V_72 ,
& V_3 ) ;
F_8 ( V_13 -> V_5 [ V_5 ] ) ;
}
} else {
F_6 ( V_13 -> V_5 [ V_5 ] ) ;
if ( V_5 == 0 ) {
* V_84 =
F_38 ( V_13 -> V_5 [ V_5 ] , V_72 ,
& V_3 ) ;
} else {
* V_84 =
F_39 ( V_13 -> V_5 [ V_5 ] , V_72 ,
& V_3 ) ;
}
F_8 ( V_13 -> V_5 [ V_5 ] ) ;
}
if ( V_3 )
F_9 ( ( L_30
L_31 , V_83 ? L_32 : L_33 , V_5 , V_72 ,
* V_84 , V_3 ) ) ;
return V_3 ;
}
extern int
F_40 ( struct V_1 * V_2 , T_3 V_89 , T_3 V_83 ,
T_3 V_5 , T_3 V_68 , T_1 * V_90 , T_3 V_91 )
{
int V_3 = - V_65 ;
if ( V_5 == 0 ) {
F_9 ( ( L_34 , V_6 ) ) ;
return - V_21 ;
}
F_4 ( ( L_35 ,
V_6 , V_89 , V_83 , V_5 , V_68 , V_91 ) ) ;
F_34 ( V_92 ) ;
F_35 ( - V_65 ) ;
F_6 ( V_13 -> V_5 [ V_5 ] ) ;
if ( V_83 ) {
if ( V_91 == 4 ) {
F_41 ( V_13 -> V_5 [ V_5 ] , * V_90 , V_68 ,
& V_3 ) ;
} else if ( V_91 == 2 ) {
F_42 ( V_13 -> V_5 [ V_5 ] , ( * V_90 & 0xFFFF ) ,
V_68 , & V_3 ) ;
} else {
F_9 ( ( L_36 , V_6 , V_91 ) ) ;
}
} else {
if ( V_91 == 4 ) {
* V_90 =
F_43 ( V_13 -> V_5 [ V_5 ] , V_68 , & V_3 ) ;
} else if ( V_91 == 2 ) {
* V_90 =
F_44 ( V_13 -> V_5 [ V_5 ] , V_68 ,
& V_3 ) & 0xFFFF ;
} else {
F_9 ( ( L_36 , V_6 , V_91 ) ) ;
}
}
F_8 ( V_13 -> V_5 [ V_5 ] ) ;
if ( V_3 ) {
F_9 ( ( L_37 ,
V_83 ? L_32 : L_33 , V_3 ) ) ;
}
return V_3 ;
}
static int
F_45 ( struct V_1 * V_2 , T_3 V_93 , T_3 V_94 ,
T_3 V_5 , T_3 V_68 , struct V_95 * V_96 )
{
bool V_97 = ( V_93 == V_98 ) ;
T_1 V_99 = 0 ;
int V_3 = 0 ;
struct V_95 * V_100 ;
F_2 ( ( L_38 , V_6 ) ) ;
F_34 ( V_101 ) ;
F_35 ( - V_65 ) ;
F_6 ( V_13 -> V_5 [ V_5 ] ) ;
for ( V_100 = V_96 ; V_100 ; V_100 = V_100 -> V_102 ) {
T_3 V_103 = V_100 -> V_32 ;
V_103 += 3 ;
V_103 &= 0xFFFFFFFC ;
if ( ( V_94 ) && ( ! V_97 ) ) {
V_3 = F_46 ( V_13 -> V_5 [ V_5 ] , V_68 ,
( ( T_2 * ) ( V_100 -> V_63 ) ) ,
V_103 ) ;
} else if ( V_94 ) {
V_3 = F_46 ( V_13 -> V_5 [ V_5 ] , V_68 ,
( ( T_2 * ) ( V_100 -> V_63 ) ) ,
V_103 ) ;
} else if ( V_97 ) {
V_3 = F_47 ( V_13 -> V_5 [ V_5 ] ,
( ( T_2 * ) ( V_100 -> V_63 ) ) ,
V_68 , V_103 ) ;
} else {
V_3 = F_48 ( V_13 -> V_5 [ V_5 ] ,
( ( T_2 * ) ( V_100 -> V_63 ) ) ,
V_68 , V_103 ) ;
}
if ( V_3 ) {
F_9 ( ( L_39
L_40 , V_6 ,
( V_94 ) ? L_41 : L_42 ,
V_100 , V_99 , V_68 , V_103 , V_3 ) ) ;
} else {
F_2 ( ( L_43 ,
V_6 ,
( V_94 ) ? L_41 : L_42 ,
V_100 , V_99 , V_68 , V_103 ) ) ;
}
if ( ! V_97 )
V_68 += V_103 ;
V_99 ++ ;
}
F_8 ( V_13 -> V_5 [ V_5 ] ) ;
F_2 ( ( L_44 , V_6 ) ) ;
return V_3 ;
}
extern int
F_49 ( struct V_1 * V_2 , T_3 V_104 , T_3 V_93 ,
T_3 V_94 , T_3 V_5 , T_3 V_68 , T_3 V_105 ,
T_3 V_106 , T_2 * V_107 , struct V_95 * V_96 )
{
int V_108 ;
struct V_95 * V_109 = NULL ;
F_2 ( ( L_38 , V_6 ) ) ;
F_34 ( V_110 ) ;
F_35 ( - V_65 ) ;
if ( V_96 == NULL ) {
F_50 ( ( L_45 ,
V_6 , V_94 ? L_41 : L_42 , V_106 ) ) ;
V_109 = F_51 ( V_106 ) ;
if ( ! V_109 ) {
F_9 ( ( L_46 ,
V_6 , V_106 ) ) ;
return - V_65 ;
}
if ( V_94 )
memcpy ( V_109 -> V_63 , V_107 , V_106 ) ;
V_108 = F_45 ( V_2 , V_93 , V_94 , V_5 ,
V_68 , V_109 ) ;
if ( ! V_94 )
memcpy ( V_107 , V_109 -> V_63 , V_106 ) ;
F_52 ( V_109 ) ;
} else if ( ( ( V_111 ) ( V_96 -> V_63 ) & V_112 ) != 0 ) {
F_50 ( ( L_47 ,
V_6 , V_94 ? L_41 : L_42 , V_96 -> V_32 ) ) ;
V_109 = F_51 ( V_96 -> V_32 ) ;
if ( ! V_109 ) {
F_9 ( ( L_46 ,
V_6 , V_96 -> V_32 ) ) ;
return - V_65 ;
}
if ( V_94 )
memcpy ( V_109 -> V_63 , V_96 -> V_63 , V_96 -> V_32 ) ;
V_108 = F_45 ( V_2 , V_93 , V_94 , V_5 ,
V_68 , V_109 ) ;
if ( ! V_94 )
memcpy ( V_96 -> V_63 , V_109 -> V_63 , V_109 -> V_32 ) ;
F_52 ( V_109 ) ;
} else {
F_50 ( ( L_48 ,
V_6 , V_94 ? L_49 : L_50 ) ) ;
V_108 = F_45 ( V_2 , V_93 , V_94 , V_5 ,
V_68 , V_96 ) ;
}
return V_108 ;
}
extern int F_53 ( struct V_1 * V_2 , T_3 V_5 )
{
char V_113 = ( char ) V_5 ;
F_2 ( ( L_38 , V_6 ) ) ;
F_30 ( V_2 , V_71 , V_114 , V_88 ,
& V_113 ) ;
F_2 ( ( L_44 , V_6 ) ) ;
return 0 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_2 ( ( L_51 , V_6 , V_2 -> V_17 ) ) ;
V_2 -> V_56 &= ~ V_57 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_2 ( ( L_51 , V_6 , V_2 -> V_17 ) ) ;
V_2 -> V_56 |= V_57 ;
}
int
F_31 ( struct V_1 * V_2 , int V_5 , T_1 V_72 ,
int V_115 , T_1 * V_63 )
{
if ( ( V_5 == 0 ) || ( V_115 == 1 ) ) {
T_2 V_116 = 0 ;
F_30 ( V_2 , V_70 , V_5 , V_72 , & V_116 ) ;
* V_63 = V_116 ;
* V_63 &= 0xff ;
F_50 ( ( L_52 , V_6 , * V_63 ) ) ;
} else {
F_40 ( V_2 , 0 , V_70 , V_5 , V_72 , V_63 ,
V_115 ) ;
if ( V_115 == 2 )
* V_63 &= 0xffff ;
F_50 ( ( L_53 , V_6 , * V_63 ) ) ;
}
return V_77 ;
}
static void V_26 ( struct V_117 * V_5 )
{
struct V_1 * V_2 ;
F_2 ( ( L_54 ) ) ;
V_2 = V_13 -> V_2 ;
F_8 ( V_13 -> V_5 [ 0 ] ) ;
if ( V_2 -> V_17 ) {
V_2 -> V_59 ++ ;
( V_2 -> V_22 ) ( V_2 -> V_23 ) ;
} else {
F_9 ( ( L_54 ) ) ;
F_9 ( ( L_55 ,
V_6 , V_2 -> V_118 , V_2 -> V_22 ) ) ;
}
F_6 ( V_13 -> V_5 [ 0 ] ) ;
}
static void V_25 ( struct V_117 * V_5 )
{
struct V_1 * V_2 ;
F_2 ( ( L_56 ) ) ;
V_2 = V_13 -> V_2 ;
}
static int F_56 ( struct V_117 * V_5 ,
const struct V_119 * V_120 )
{
int V_121 = 0 ;
static struct V_117 V_122 ;
F_2 ( ( L_57 , V_6 ) ) ;
F_2 ( ( L_58 , V_5 -> V_123 ) ) ;
F_2 ( ( L_59 , V_5 -> V_124 ) ) ;
F_2 ( ( L_60 , V_5 -> V_125 ) ) ;
F_2 ( ( L_61 , V_5 -> V_126 ) ) ;
if ( V_5 -> V_126 == 1 ) {
V_122 . V_126 = 0 ;
V_122 . V_127 = V_5 -> V_127 ;
V_13 -> V_5 [ 0 ] = & V_122 ;
if ( V_5 -> V_125 == 0x4 ) {
V_13 -> V_5 [ 2 ] = NULL ;
F_2 ( ( L_62 ) ) ;
V_121 = F_57 ( & V_128 ) ;
}
}
V_13 -> V_5 [ V_5 -> V_126 ] = V_5 ;
if ( V_5 -> V_126 == 2 ) {
F_58 ( V_5 ) ;
F_2 ( ( L_63 ) ) ;
V_121 = F_57 ( & V_128 ) ;
}
return V_121 ;
}
static void F_59 ( struct V_117 * V_5 )
{
F_2 ( ( L_64 , V_6 ) ) ;
F_4 ( ( L_65 , V_5 -> V_123 ) ) ;
F_4 ( ( L_59 , V_5 -> V_124 ) ) ;
F_4 ( ( L_60 , V_5 -> V_125 ) ) ;
F_4 ( ( L_61 , V_5 -> V_126 ) ) ;
if ( V_5 -> V_126 == 2 ) {
F_2 ( ( L_66 ) ) ;
F_60 ( & V_128 ) ;
}
}
static int F_61 ( struct V_125 * V_129 )
{
T_5 V_130 ;
int V_121 = 0 ;
F_2 ( ( L_1 , V_6 ) ) ;
V_130 = F_62 ( V_13 -> V_5 [ 1 ] ) ;
if ( ! ( V_130 & V_131 ) ) {
F_9 ( ( L_67 ) ) ;
return - V_21 ;
}
V_121 = F_63 ( V_13 -> V_5 [ 1 ] , V_131 ) ;
if ( V_121 ) {
F_9 ( ( L_68 ) ) ;
return V_121 ;
}
F_64 ( false ) ;
return V_121 ;
}
static int F_65 ( struct V_125 * V_129 )
{
F_64 ( true ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_132 * V_133 ;
V_133 = F_66 ( sizeof( struct V_132 ) , V_16 ) ;
V_2 -> V_132 = ( void * ) V_133 ;
if ( V_133 == NULL )
return - V_134 ;
V_133 -> V_2 = V_2 ;
F_67 ( & V_133 -> V_135 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_132 * V_133 ;
V_133 = (struct V_132 * ) V_2 -> V_132 ;
F_13 ( V_133 ) ;
}
int F_68 ( struct V_1 * V_2 , bool V_136 )
{
unsigned long V_137 ;
struct V_132 * V_133 ;
F_2 ( ( L_69 , V_6 , V_136 ? L_70 : L_71 ) ) ;
V_133 = (struct V_132 * ) V_2 -> V_132 ;
if ( V_136 && ! ( V_2 -> V_22 && V_2 -> V_23 ) ) {
F_9 ( ( L_72 ,
V_6 ) ) ;
return - V_21 ;
}
F_69 ( & V_133 -> V_135 , V_137 ) ;
V_2 -> V_118 = V_136 ;
if ( V_136 )
F_55 ( V_2 ) ;
else
F_54 ( V_2 ) ;
F_70 ( & V_133 -> V_135 , V_137 ) ;
return 0 ;
}
int F_71 ( void )
{
int error = 0 ;
F_2 ( ( L_73 , V_6 ) ) ;
V_13 = F_11 ( sizeof( struct V_138 ) , V_139 ) ;
if ( ! V_13 )
return - V_134 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
error = F_72 ( & V_140 ) ;
return error ;
}
void F_73 ( void )
{
F_2 ( ( L_64 , V_6 ) ) ;
F_74 ( & V_140 ) ;
F_13 ( V_13 ) ;
}
