static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_6 == V_7 )
V_2 -> V_8 [ V_4 -> V_9 ] = V_4 ;
else
V_2 -> V_10 [ V_4 -> V_9 ] = V_4 ;
F_3 ( & V_2 -> V_5 ) ;
}
static void
F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_11 ;
F_5 ( & V_2 -> V_5 , V_11 ) ;
if ( V_4 -> V_6 == V_7 )
V_2 -> V_8 [ V_4 -> V_9 ] = NULL ;
else
V_2 -> V_10 [ V_4 -> V_9 ] = NULL ;
F_6 ( & V_2 -> V_5 , V_11 ) ;
}
static int
F_7 ( struct V_3 * * V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
if ( V_12 [ V_13 ] != NULL )
return 0 ;
return 1 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_13 , V_15 ;
F_9 ( L_1 , V_16 , V_2 ) ;
if ( V_2 -> V_17 )
return - V_18 ;
memset ( V_2 -> V_8 , 0 , sizeof( V_2 -> V_8 ) ) ;
memset ( V_2 -> V_10 , 0 , sizeof( V_2 -> V_10 ) ) ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 4 ;
V_2 -> V_17 = 1 ;
V_2 -> V_22 = 0 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_15 = F_10 ( V_2 -> V_24 [ V_13 ] , V_25 ) ;
if ( V_15 ) {
log ( L_2 , V_13 , V_15 ) ;
V_2 -> V_17 = 0 ;
return - V_26 ;
}
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_13 ;
F_9 ( L_1 , V_16 , V_2 ) ;
if ( ! V_2 -> V_17 )
return;
V_2 -> V_17 = 0 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
F_12 ( V_2 -> V_24 [ V_13 ] ) ;
F_12 ( V_2 -> V_27 [ V_13 ] ) ;
}
}
static int F_13 ( struct V_3 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_9 ( L_1 , V_16 , V_28 ) ;
V_28 -> V_29 -> V_30 = V_2 -> V_31 ;
F_15 ( V_28 -> V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_9 ( L_1 , V_16 , V_28 ) ;
if ( F_7 ( V_2 -> V_8 ) &&
F_7 ( V_2 -> V_10 ) ) {
F_11 ( V_2 ) ;
V_2 -> V_31 . V_32 = V_2 -> V_33 ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_34 * V_35 )
{
F_9 ( L_1 , V_16 , V_4 ) ;
return F_18 ( V_4 , F_19 ( V_35 ) ) ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( V_4 ) ;
F_9 ( L_1 , V_16 , V_4 ) ;
F_4 ( V_2 , V_4 ) ;
return F_21 ( V_4 ) ;
}
static int F_22 ( struct V_3 * V_28 )
{
int V_36 , V_37 , V_15 , V_13 ;
int V_38 = V_28 -> V_9 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_39 * V_29 = V_28 -> V_29 ;
F_9 ( L_1 , V_16 , V_28 ) ;
if ( V_28 -> V_6 == V_7 ) {
int V_40 ;
switch ( V_2 -> V_41 . V_42 ) {
case 0 :
case 2 :
V_40 = V_43 + 1 ;
break;
case 3 :
default:
V_40 = 0 ;
break;
}
V_2 -> V_44 [ V_38 ] = V_40 ;
V_2 -> V_45 [ V_38 ] = V_40 ;
} else {
int V_46 ;
switch ( V_2 -> V_41 . V_42 ) {
case 0 :
V_46 = V_43 + 2 ;
break;
case 2 :
V_46 = V_43 ;
break;
case 3 :
default:
V_46 = 0 ;
break;
}
V_2 -> V_47 [ V_38 ] = V_46 ;
V_2 -> V_48 [ V_38 ] = V_46 ;
}
if ( V_2 -> V_17 )
return 0 ;
for ( V_13 = 0 ; V_13 < F_23 ( V_32 ) ; V_13 ++ )
if ( V_29 -> V_49 == V_32 [ V_13 ] )
V_2 -> V_31 . V_32 = 1 << V_13 ;
F_15 ( V_29 ) ;
V_36 = V_43 ;
if ( V_2 -> V_41 . V_42 >= 2 )
V_36 ++ ;
V_37 = ( ( V_29 -> V_49 / 8000 ) + V_50 )
* V_36 * V_51 * V_2 -> V_52 ;
if ( V_37 > V_53 )
V_37 = V_53 ;
V_15 = F_24 ( V_2 , V_29 -> V_49 ,
V_29 -> V_54 , V_37 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_8 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_55 = 0 ;
F_25 ( V_2 -> V_56 , V_2 -> V_55 , V_57 ) ;
if ( ! V_2 -> V_55 ) {
F_11 ( V_2 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_26 ( struct V_3 * V_4 , int V_58 )
{
struct V_1 * V_2 = F_14 ( V_4 ) ;
F_9 ( L_3 , V_16 , V_4 , V_58 ) ;
switch ( V_58 ) {
case V_59 :
case V_60 :
F_1 ( V_2 , V_4 ) ;
break;
case V_61 :
case V_62 :
F_4 ( V_2 , V_4 ) ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static T_1
F_27 ( struct V_3 * V_4 )
{
int V_38 = V_4 -> V_9 ;
struct V_1 * V_2 = F_14 ( V_4 ) ;
T_1 V_63 ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_19 || V_2 -> V_20 )
V_63 = V_64 ;
if ( V_4 -> V_6 == V_7 )
V_63 = F_28 ( V_4 -> V_29 ,
V_2 -> V_45 [ V_38 ] ) ;
else
V_63 = F_28 ( V_4 -> V_29 ,
V_2 -> V_48 [ V_38 ] ) ;
F_3 ( & V_2 -> V_5 ) ;
return V_63 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * * V_12 )
{
int V_6 , V_65 , * V_66 ;
struct V_3 * V_4 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_52 ; V_6 ++ ) {
V_4 = V_12 [ V_6 ] ;
if ( ! V_4 )
continue;
V_65 = F_30 ( V_4 ) ;
V_66 = ( V_4 -> V_6 == V_7 ) ?
& V_2 -> V_44 [ V_6 ] :
& V_2 -> V_47 [ V_6 ] ;
if ( * V_66 >= V_65 ) {
F_31 ( V_4 ) ;
* V_66 %= V_65 ;
}
}
}
static void F_32 ( struct V_1 * V_2 ,
const struct V_67 * V_67 ,
const struct V_68 * V_69 )
{
unsigned char * V_70 = V_67 -> V_71 + V_69 -> V_72 ;
struct V_3 * V_4 ;
int V_6 , V_13 ;
if ( F_7 ( V_2 -> V_10 ) )
return;
for ( V_13 = 0 ; V_13 < V_69 -> V_73 ; ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_52 ; V_6 ++ , V_13 ++ ) {
V_4 = V_2 -> V_10 [ V_6 ] ;
if ( V_4 ) {
struct V_39 * V_74 = V_4 -> V_29 ;
char * V_75 = V_74 -> V_76 ;
int V_77 = F_33 ( V_74 , V_74 -> V_78 ) ;
V_75 [ V_2 -> V_48 [ V_6 ] ++ ]
= V_70 [ V_13 ] ;
V_2 -> V_47 [ V_6 ] ++ ;
if ( V_2 -> V_48 [ V_6 ] == V_77 )
V_2 -> V_48 [ V_6 ] = 0 ;
}
}
}
}
static void F_34 ( struct V_1 * V_2 ,
const struct V_67 * V_67 ,
const struct V_68 * V_69 )
{
unsigned char * V_70 = V_67 -> V_71 + V_69 -> V_72 ;
unsigned char V_79 ;
struct V_3 * V_4 ;
int V_6 , V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_73 ; ) {
if ( V_13 % ( V_2 -> V_52 * V_80 ) == 0 ) {
for ( V_6 = 0 ;
V_6 < V_2 -> V_52 ;
V_6 ++ , V_13 ++ ) {
if ( V_2 -> V_21 )
continue;
V_79 = F_35 ( V_2 , V_6 , V_13 ) ;
if ( ( V_70 [ V_13 ] & 0x3f ) != V_79 )
V_2 -> V_19 = 1 ;
if ( V_70 [ V_13 ] & 0x80 )
V_2 -> V_20 = 1 ;
}
}
V_2 -> V_21 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_52 ; V_6 ++ , V_13 ++ ) {
V_4 = V_2 -> V_10 [ V_6 ] ;
if ( V_2 -> V_19 )
V_70 [ V_13 ] = 0 ;
if ( V_4 ) {
struct V_39 * V_74 = V_4 -> V_29 ;
char * V_75 = V_74 -> V_76 ;
int V_77 = F_33 ( V_74 , V_74 -> V_78 ) ;
V_75 [ V_2 -> V_48 [ V_6 ] ++ ] =
V_70 [ V_13 ] ;
V_2 -> V_47 [ V_6 ] ++ ;
if ( V_2 -> V_48 [ V_6 ] == V_77 )
V_2 -> V_48 [ V_6 ] = 0 ;
}
}
}
}
static void F_36 ( struct V_1 * V_2 ,
const struct V_67 * V_67 ,
const struct V_68 * V_69 )
{
unsigned char * V_70 = V_67 -> V_71 + V_69 -> V_72 ;
int V_6 , V_13 ;
if ( V_69 -> V_73 % ( V_80 * V_51 ) )
return;
for ( V_13 = 0 ; V_13 < V_69 -> V_73 ; ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_52 ; V_6 ++ ) {
struct V_3 * V_4 = V_2 -> V_10 [ V_6 ] ;
char * V_75 = NULL ;
int V_81 , V_82 , V_77 = 0 ;
if ( V_4 && ! V_2 -> V_19 ) {
struct V_39 * V_74 = V_4 -> V_29 ;
V_75 = V_74 -> V_76 ;
V_77 = F_33 ( V_74 , V_74 -> V_78 ) ;
}
for ( V_81 = 0 ; V_81 < V_51 ; V_81 ++ ) {
if ( V_75 ) {
for ( V_82 = 0 ; V_82 < V_43 ; V_82 ++ ) {
V_75 [ V_2 -> V_48 [ V_6 ] ++ ] = V_70 [ V_13 + V_82 ] ;
if ( V_2 -> V_48 [ V_6 ] == V_77 )
V_2 -> V_48 [ V_6 ] = 0 ;
}
V_2 -> V_47 [ V_6 ] += V_43 ;
}
V_13 += V_43 ;
if ( V_70 [ V_13 ] != ( ( V_6 << 1 ) | V_81 ) &&
! V_2 -> V_21 ) {
if ( ! V_2 -> V_19 )
F_37 ( L_4 ,
( ( V_6 << 1 ) | V_81 ) , V_70 [ V_13 ] , V_81 , V_6 , V_13 ) ;
V_2 -> V_19 = 1 ;
}
V_13 ++ ;
}
}
}
if ( V_2 -> V_21 > 0 )
V_2 -> V_21 -- ;
}
static void F_38 ( struct V_1 * V_2 ,
const struct V_67 * V_67 ,
const struct V_68 * V_69 )
{
if ( ! V_2 -> V_17 )
return;
if ( V_69 -> V_73 < V_2 -> V_37 )
return;
switch ( V_2 -> V_41 . V_42 ) {
case 0 :
F_32 ( V_2 , V_67 , V_69 ) ;
break;
case 2 :
F_34 ( V_2 , V_67 , V_69 ) ;
break;
case 3 :
F_36 ( V_2 , V_67 , V_69 ) ;
break;
}
if ( ( V_2 -> V_19 || V_2 -> V_20 ) && ! V_2 -> V_22 ) {
F_9 ( L_5 ,
V_2 -> V_19 ? L_6 : L_7 ,
V_2 -> V_20 ? L_8 : L_7 ) ;
V_2 -> V_22 = 1 ;
}
}
static void F_39 ( struct V_1 * V_2 ,
struct V_67 * V_67 ,
const struct V_68 * V_69 )
{
unsigned char * V_70 = V_67 -> V_71 + V_69 -> V_72 ;
struct V_3 * V_4 ;
int V_6 , V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_83 ; ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_52 ; V_6 ++ , V_13 ++ ) {
V_4 = V_2 -> V_8 [ V_6 ] ;
if ( V_4 ) {
struct V_39 * V_74 = V_4 -> V_29 ;
char * V_75 = V_74 -> V_76 ;
int V_77 = F_33 ( V_74 , V_74 -> V_78 ) ;
V_70 [ V_13 ] =
V_75 [ V_2 -> V_45 [ V_6 ] ] ;
V_2 -> V_44 [ V_6 ] ++ ;
V_2 -> V_45 [ V_6 ] ++ ;
if ( V_2 -> V_45 [ V_6 ] == V_77 )
V_2 -> V_45 [ V_6 ] = 0 ;
} else
V_70 [ V_13 ] = 0 ;
}
if ( V_2 -> V_41 . V_42 == 2 &&
V_13 % ( V_2 -> V_52 * V_80 ) ==
( V_2 -> V_52 * V_51 ) )
for ( V_6 = 0 ; V_6 < V_2 -> V_52 ; V_6 ++ , V_13 ++ )
V_70 [ V_13 ] = F_35 ( V_2 , V_6 , V_13 ) ;
}
}
static void F_40 ( struct V_1 * V_2 ,
struct V_67 * V_67 ,
const struct V_68 * V_69 )
{
unsigned char * V_70 = V_67 -> V_71 + V_69 -> V_72 ;
int V_6 , V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_83 ; ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_52 ; V_6 ++ ) {
struct V_3 * V_4 = V_2 -> V_8 [ V_6 ] ;
char * V_75 = NULL ;
int V_81 , V_82 , V_77 = 0 ;
if ( V_4 ) {
struct V_39 * V_74 = V_4 -> V_29 ;
V_75 = V_74 -> V_76 ;
V_77 = F_33 ( V_74 , V_74 -> V_78 ) ;
}
for ( V_81 = 0 ; V_81 < V_51 ; V_81 ++ ) {
for ( V_82 = 0 ; V_82 < V_43 ; V_82 ++ ) {
if ( V_75 ) {
V_70 [ V_13 + V_82 ] = V_75 [ V_2 -> V_45 [ V_6 ] ++ ] ;
if ( V_2 -> V_45 [ V_6 ] == V_77 )
V_2 -> V_45 [ V_6 ] = 0 ;
} else {
V_70 [ V_13 + V_82 ] = 0 ;
}
}
if ( V_75 )
V_2 -> V_44 [ V_6 ] += V_43 ;
V_13 += V_43 ;
V_70 [ V_13 ++ ] = ( V_6 << 1 ) | V_81 ;
}
}
}
}
static inline void F_41 ( struct V_1 * V_2 ,
struct V_67 * V_67 ,
const struct V_68 * V_69 )
{
switch ( V_2 -> V_41 . V_42 ) {
case 0 :
case 2 :
F_39 ( V_2 , V_67 , V_69 ) ;
break;
case 3 :
F_40 ( V_2 , V_67 , V_69 ) ;
break;
}
}
static void F_42 ( struct V_67 * V_67 )
{
struct V_84 * V_85 = V_67 -> V_86 ;
struct V_1 * V_2 ;
struct V_67 * V_87 ;
int V_88 , V_89 , V_90 = 0 , V_91 = 0 ;
if ( V_67 -> V_92 || ! V_85 )
return;
V_2 = V_85 -> V_2 ;
if ( ! V_2 -> V_17 )
return;
V_87 = V_2 -> V_27 [ V_85 -> V_38 ] ;
for ( V_88 = 0 ; V_88 < V_93 ; V_88 ++ ) {
if ( V_67 -> V_94 [ V_88 ] . V_92 )
continue;
V_89 = V_67 -> V_94 [ V_91 ] . V_73 ;
V_87 -> V_94 [ V_91 ] . V_83 = V_89 ;
V_87 -> V_94 [ V_91 ] . V_73 = 0 ;
V_87 -> V_94 [ V_91 ] . V_72 = V_95 * V_88 ;
if ( V_89 > 0 ) {
F_2 ( & V_2 -> V_5 ) ;
F_41 ( V_2 , V_87 , & V_87 -> V_94 [ V_91 ] ) ;
F_38 ( V_2 , V_67 , & V_67 -> V_94 [ V_88 ] ) ;
F_3 ( & V_2 -> V_5 ) ;
F_29 ( V_2 , V_2 -> V_8 ) ;
F_29 ( V_2 , V_2 -> V_10 ) ;
V_90 = 1 ;
}
V_91 ++ ;
}
if ( V_90 ) {
V_87 -> V_96 = V_93 ;
V_87 -> V_97 = V_98 ;
F_10 ( V_87 , V_25 ) ;
}
for ( V_88 = 0 ; V_88 < V_93 ; V_88 ++ ) {
V_67 -> V_94 [ V_88 ] . V_72 = V_95 * V_88 ;
V_67 -> V_94 [ V_88 ] . V_83 = V_95 ;
V_67 -> V_94 [ V_88 ] . V_73 = 0 ;
}
V_67 -> V_96 = V_93 ;
V_67 -> V_97 = V_98 ;
F_10 ( V_67 , V_25 ) ;
}
static void F_43 ( struct V_67 * V_67 )
{
struct V_84 * V_85 = V_67 -> V_86 ;
struct V_1 * V_2 = V_85 -> V_2 ;
if ( ! V_2 -> V_55 ) {
V_2 -> V_55 = 1 ;
F_44 ( & V_2 -> V_56 ) ;
}
}
static struct V_67 * * F_45 ( struct V_1 * V_2 , int V_99 , int * V_15 )
{
int V_13 , V_88 ;
struct V_67 * * V_100 ;
struct V_101 * V_102 = V_2 -> V_103 . V_2 ;
unsigned int V_104 ;
V_104 = ( V_99 == V_7 ) ?
F_46 ( V_102 , V_105 ) :
F_47 ( V_102 , V_106 ) ;
V_100 = F_48 ( V_23 * sizeof( * V_100 ) , V_107 ) ;
if ( ! V_100 ) {
log ( L_9 ) ;
* V_15 = - V_108 ;
return NULL ;
}
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_100 [ V_13 ] = F_49 ( V_93 , V_107 ) ;
if ( ! V_100 [ V_13 ] ) {
log ( L_10 ) ;
* V_15 = - V_108 ;
return V_100 ;
}
V_100 [ V_13 ] -> V_71 =
F_48 ( V_93 * V_95 , V_107 ) ;
if ( ! V_100 [ V_13 ] -> V_71 ) {
log ( L_11 ) ;
* V_15 = - V_108 ;
return V_100 ;
}
for ( V_88 = 0 ; V_88 < V_93 ; V_88 ++ ) {
struct V_68 * V_69 =
& V_100 [ V_13 ] -> V_94 [ V_88 ] ;
V_69 -> V_72 = V_95 * V_88 ;
V_69 -> V_83 = V_95 ;
}
V_100 [ V_13 ] -> V_2 = V_102 ;
V_100 [ V_13 ] -> V_104 = V_104 ;
V_100 [ V_13 ] -> V_109 = V_93
* V_95 ;
V_100 [ V_13 ] -> V_86 = & V_2 -> V_110 [ V_13 ] ;
V_100 [ V_13 ] -> V_111 = 1 ;
V_100 [ V_13 ] -> V_97 = V_98 ;
V_100 [ V_13 ] -> V_96 = V_93 ;
V_100 [ V_13 ] -> V_112 = ( V_99 == V_113 ) ?
F_42 : F_43 ;
}
* V_15 = 0 ;
return V_100 ;
}
static void F_50 ( struct V_67 * * V_100 )
{
int V_13 ;
if ( ! V_100 )
return;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
if ( ! V_100 [ V_13 ] )
continue;
F_12 ( V_100 [ V_13 ] ) ;
F_51 ( V_100 [ V_13 ] -> V_71 ) ;
F_52 ( V_100 [ V_13 ] ) ;
}
F_51 ( V_100 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_13 , V_15 ;
V_2 -> V_114 = F_54 ( V_2 -> V_41 . V_115 ,
V_2 -> V_41 . V_116 ) /
V_51 ;
V_2 -> V_117 = F_54 ( V_2 -> V_41 . V_118 ,
V_2 -> V_41 . V_119 ) /
V_51 ;
V_2 -> V_52 = F_54 ( V_2 -> V_114 , V_2 -> V_117 ) ;
F_9 ( L_12 , V_2 -> V_114 ) ;
F_9 ( L_13 , V_2 -> V_117 ) ;
F_9 ( L_14 , V_2 -> V_52 ) ;
if ( V_2 -> V_52 > V_14 ) {
log ( L_15 ) ;
return - V_18 ;
}
V_15 = F_55 ( V_2 -> V_103 . V_120 , V_2 -> V_121 , 0 ,
V_2 -> V_117 , V_2 -> V_114 , & V_2 -> V_122 ) ;
if ( V_15 < 0 ) {
log ( L_16 , V_15 ) ;
return V_15 ;
}
V_2 -> V_122 -> V_123 = V_2 ;
F_56 ( V_2 -> V_122 -> V_124 , V_2 -> V_121 , sizeof( V_2 -> V_122 -> V_124 ) ) ;
memset ( V_2 -> V_8 , 0 , sizeof( V_2 -> V_8 ) ) ;
memset ( V_2 -> V_10 , 0 , sizeof( V_2 -> V_10 ) ) ;
memcpy ( & V_2 -> V_31 , & V_125 ,
sizeof( V_125 ) ) ;
V_2 -> V_33 = V_2 -> V_31 . V_32 ;
switch ( V_2 -> V_103 . V_126 ) {
case F_57 ( V_127 , V_128 ) :
case F_57 ( V_127 , V_129 ) :
case F_57 ( V_127 , V_130 ) :
case F_57 ( V_127 , V_131 ) :
V_2 -> V_33 |= V_132 ;
case F_57 ( V_127 , V_133 ) :
case F_57 ( V_127 , V_134 ) :
case F_57 ( V_127 , V_135 ) :
case F_57 ( V_127 , V_136 ) :
V_2 -> V_33 |= V_137 ;
break;
}
F_58 ( V_2 -> V_122 , V_7 ,
& V_138 ) ;
F_58 ( V_2 -> V_122 , V_113 ,
& V_138 ) ;
F_59 ( V_2 -> V_122 ,
V_139 ,
F_60 ( V_107 ) ,
V_140 , V_140 ) ;
V_2 -> V_110 =
F_48 ( sizeof( struct V_84 ) * V_23 ,
V_107 ) ;
if ( ! V_2 -> V_110 )
return - V_108 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_2 -> V_110 [ V_13 ] . V_2 = V_2 ;
V_2 -> V_110 [ V_13 ] . V_38 = V_13 ;
}
V_2 -> V_24 = F_45 ( V_2 , V_113 , & V_15 ) ;
if ( V_15 < 0 ) {
F_51 ( V_2 -> V_110 ) ;
F_50 ( V_2 -> V_24 ) ;
return V_15 ;
}
V_2 -> V_27 = F_45 ( V_2 , V_7 , & V_15 ) ;
if ( V_15 < 0 ) {
F_51 ( V_2 -> V_110 ) ;
F_50 ( V_2 -> V_24 ) ;
F_50 ( V_2 -> V_27 ) ;
return V_15 ;
}
return 0 ;
}
void F_61 ( struct V_1 * V_2 )
{
F_9 ( L_1 , V_16 , V_2 ) ;
F_11 ( V_2 ) ;
F_50 ( V_2 -> V_24 ) ;
F_50 ( V_2 -> V_27 ) ;
F_51 ( V_2 -> V_110 ) ;
}
