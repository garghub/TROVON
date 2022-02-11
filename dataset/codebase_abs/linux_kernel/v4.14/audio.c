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
struct V_16 * V_17 = F_9 ( V_2 ) ;
F_10 ( V_17 , L_1 , V_18 , V_2 ) ;
if ( V_2 -> V_19 )
return - V_20 ;
memset ( V_2 -> V_8 , 0 , sizeof( V_2 -> V_8 ) ) ;
memset ( V_2 -> V_10 , 0 , sizeof( V_2 -> V_10 ) ) ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 4 ;
V_2 -> V_19 = 1 ;
V_2 -> V_24 = 0 ;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
V_15 = F_11 ( V_2 -> V_26 [ V_13 ] , V_27 ) ;
if ( V_15 ) {
F_12 ( V_17 , L_2 ,
V_13 , V_15 ) ;
V_2 -> V_19 = 0 ;
return - V_28 ;
}
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_16 * V_17 = F_9 ( V_2 ) ;
F_10 ( V_17 , L_1 , V_18 , V_2 ) ;
if ( ! V_2 -> V_19 )
return;
V_2 -> V_19 = 0 ;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
F_14 ( V_2 -> V_26 [ V_13 ] ) ;
if ( F_15 ( V_13 , & V_2 -> V_29 ) )
F_14 ( V_2 -> V_30 [ V_13 ] ) ;
}
V_2 -> V_29 = 0 ;
}
static int F_16 ( struct V_3 * V_31 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
struct V_16 * V_17 = F_9 ( V_2 ) ;
F_10 ( V_17 , L_1 , V_18 , V_31 ) ;
V_31 -> V_32 -> V_33 = V_2 -> V_34 ;
F_18 ( V_31 -> V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_31 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
struct V_16 * V_17 = F_9 ( V_2 ) ;
F_10 ( V_17 , L_1 , V_18 , V_31 ) ;
if ( F_7 ( V_2 -> V_8 ) &&
F_7 ( V_2 -> V_10 ) ) {
F_13 ( V_2 ) ;
V_2 -> V_34 . V_35 = V_2 -> V_36 ;
}
return 0 ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_37 * V_38 )
{
return F_21 ( V_4 ,
F_22 ( V_38 ) ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
F_4 ( V_2 , V_4 ) ;
return F_24 ( V_4 ) ;
}
static int F_25 ( struct V_3 * V_31 )
{
int V_39 , V_40 , V_15 , V_13 ;
int V_41 = V_31 -> V_9 ;
struct V_1 * V_2 = F_17 ( V_31 ) ;
struct V_42 * V_32 = V_31 -> V_32 ;
struct V_16 * V_17 = F_9 ( V_2 ) ;
F_10 ( V_17 , L_1 , V_18 , V_31 ) ;
if ( V_31 -> V_6 == V_7 ) {
int V_43 ;
switch ( V_2 -> V_44 . V_45 ) {
case 0 :
case 2 :
V_43 = V_46 + 1 ;
break;
case 3 :
default:
V_43 = 0 ;
break;
}
V_2 -> V_47 [ V_41 ] = V_43 ;
V_2 -> V_48 [ V_41 ] = V_43 ;
} else {
int V_49 ;
switch ( V_2 -> V_44 . V_45 ) {
case 0 :
V_49 = V_46 + 2 ;
break;
case 2 :
V_49 = V_46 ;
break;
case 3 :
default:
V_49 = 0 ;
break;
}
V_2 -> V_50 [ V_41 ] = V_49 ;
V_2 -> V_51 [ V_41 ] = V_49 ;
}
if ( V_2 -> V_19 )
return 0 ;
for ( V_13 = 0 ; V_13 < F_26 ( V_35 ) ; V_13 ++ )
if ( V_32 -> V_52 == V_35 [ V_13 ] )
V_2 -> V_34 . V_35 = 1 << V_13 ;
F_18 ( V_32 ) ;
V_39 = V_46 ;
if ( V_2 -> V_44 . V_45 >= 2 )
V_39 ++ ;
V_40 = ( ( V_32 -> V_52 / 8000 ) + V_53 )
* V_39 * V_54 * V_2 -> V_55 ;
if ( V_40 > V_56 )
V_40 = V_56 ;
V_15 = F_27 ( V_2 , V_32 -> V_52 ,
V_32 -> V_57 , V_40 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_8 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_58 = 0 ;
F_28 ( V_2 -> V_59 , V_2 -> V_58 , V_60 ) ;
if ( ! V_2 -> V_58 ) {
F_13 ( V_2 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_29 ( struct V_3 * V_4 , int V_61 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
struct V_16 * V_17 = F_9 ( V_2 ) ;
F_10 ( V_17 , L_3 , V_18 , V_4 , V_61 ) ;
switch ( V_61 ) {
case V_62 :
case V_63 :
F_1 ( V_2 , V_4 ) ;
break;
case V_64 :
case V_65 :
F_4 ( V_2 , V_4 ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static T_1
F_30 ( struct V_3 * V_4 )
{
int V_41 = V_4 -> V_9 ;
struct V_1 * V_2 = F_17 ( V_4 ) ;
T_1 V_66 ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_21 || V_2 -> V_22 ) {
V_66 = V_67 ;
goto V_68;
}
if ( V_4 -> V_6 == V_7 )
V_66 = F_31 ( V_4 -> V_32 ,
V_2 -> V_48 [ V_41 ] ) ;
else
V_66 = F_31 ( V_4 -> V_32 ,
V_2 -> V_51 [ V_41 ] ) ;
V_68:
F_3 ( & V_2 -> V_5 ) ;
return V_66 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_3 * * V_12 )
{
int V_6 , V_69 , * V_70 ;
struct V_3 * V_4 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_55 ; V_6 ++ ) {
V_4 = V_12 [ V_6 ] ;
if ( ! V_4 )
continue;
V_69 = F_33 ( V_4 ) ;
V_70 = ( V_4 -> V_6 == V_7 ) ?
& V_2 -> V_47 [ V_6 ] :
& V_2 -> V_50 [ V_6 ] ;
if ( * V_70 >= V_69 ) {
F_34 ( V_4 ) ;
* V_70 %= V_69 ;
}
}
}
static void F_35 ( struct V_1 * V_2 ,
const struct V_71 * V_71 ,
const struct V_72 * V_73 )
{
unsigned char * V_74 = V_71 -> V_75 + V_73 -> V_76 ;
struct V_3 * V_4 ;
int V_6 , V_13 ;
if ( F_7 ( V_2 -> V_10 ) )
return;
for ( V_13 = 0 ; V_13 < V_73 -> V_77 ; ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_55 ; V_6 ++ , V_13 ++ ) {
V_4 = V_2 -> V_10 [ V_6 ] ;
if ( V_4 ) {
struct V_42 * V_78 = V_4 -> V_32 ;
char * V_79 = V_78 -> V_80 ;
int V_81 = F_36 ( V_78 , V_78 -> V_82 ) ;
V_79 [ V_2 -> V_51 [ V_6 ] ++ ]
= V_74 [ V_13 ] ;
V_2 -> V_50 [ V_6 ] ++ ;
if ( V_2 -> V_51 [ V_6 ] == V_81 )
V_2 -> V_51 [ V_6 ] = 0 ;
}
}
}
}
static void F_37 ( struct V_1 * V_2 ,
const struct V_71 * V_71 ,
const struct V_72 * V_73 )
{
unsigned char * V_74 = V_71 -> V_75 + V_73 -> V_76 ;
unsigned char V_83 ;
struct V_3 * V_4 ;
int V_6 , V_13 ;
for ( V_13 = 0 ; V_13 < V_73 -> V_77 ; ) {
if ( V_13 % ( V_2 -> V_55 * V_84 ) == 0 ) {
for ( V_6 = 0 ;
V_6 < V_2 -> V_55 ;
V_6 ++ , V_13 ++ ) {
if ( V_2 -> V_23 )
continue;
V_83 = F_38 ( V_2 , V_6 , V_13 ) ;
if ( ( V_74 [ V_13 ] & 0x3f ) != V_83 )
V_2 -> V_21 = 1 ;
if ( V_74 [ V_13 ] & 0x80 )
V_2 -> V_22 = 1 ;
}
}
V_2 -> V_23 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_55 ; V_6 ++ , V_13 ++ ) {
V_4 = V_2 -> V_10 [ V_6 ] ;
if ( V_2 -> V_21 )
V_74 [ V_13 ] = 0 ;
if ( V_4 ) {
struct V_42 * V_78 = V_4 -> V_32 ;
char * V_79 = V_78 -> V_80 ;
int V_81 = F_36 ( V_78 , V_78 -> V_82 ) ;
V_79 [ V_2 -> V_51 [ V_6 ] ++ ] =
V_74 [ V_13 ] ;
V_2 -> V_50 [ V_6 ] ++ ;
if ( V_2 -> V_51 [ V_6 ] == V_81 )
V_2 -> V_51 [ V_6 ] = 0 ;
}
}
}
}
static void F_39 ( struct V_1 * V_2 ,
const struct V_71 * V_71 ,
const struct V_72 * V_73 )
{
unsigned char * V_74 = V_71 -> V_75 + V_73 -> V_76 ;
struct V_16 * V_17 = F_9 ( V_2 ) ;
int V_6 , V_13 ;
if ( V_73 -> V_77 % ( V_84 * V_54 ) )
return;
for ( V_13 = 0 ; V_13 < V_73 -> V_77 ; ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_55 ; V_6 ++ ) {
struct V_3 * V_4 = V_2 -> V_10 [ V_6 ] ;
char * V_79 = NULL ;
int V_85 , V_86 , V_81 = 0 ;
if ( V_4 && ! V_2 -> V_21 ) {
struct V_42 * V_78 = V_4 -> V_32 ;
V_79 = V_78 -> V_80 ;
V_81 = F_36 ( V_78 , V_78 -> V_82 ) ;
}
for ( V_85 = 0 ; V_85 < V_54 ; V_85 ++ ) {
if ( V_79 ) {
for ( V_86 = 0 ; V_86 < V_46 ; V_86 ++ ) {
V_79 [ V_2 -> V_51 [ V_6 ] ++ ] = V_74 [ V_13 + V_86 ] ;
if ( V_2 -> V_51 [ V_6 ] == V_81 )
V_2 -> V_51 [ V_6 ] = 0 ;
}
V_2 -> V_50 [ V_6 ] += V_46 ;
}
V_13 += V_46 ;
if ( V_74 [ V_13 ] != ( ( V_6 << 1 ) | V_85 ) &&
! V_2 -> V_23 ) {
if ( ! V_2 -> V_21 )
F_40 ( V_17 , L_4 ,
( ( V_6 << 1 ) | V_85 ) , V_74 [ V_13 ] , V_85 , V_6 , V_13 ) ;
V_2 -> V_21 = 1 ;
}
V_13 ++ ;
}
}
}
if ( V_2 -> V_23 > 0 )
V_2 -> V_23 -- ;
}
static void F_41 ( struct V_1 * V_2 ,
const struct V_71 * V_71 ,
const struct V_72 * V_73 )
{
struct V_16 * V_17 = F_9 ( V_2 ) ;
if ( ! V_2 -> V_19 )
return;
if ( V_73 -> V_77 < V_2 -> V_40 )
return;
switch ( V_2 -> V_44 . V_45 ) {
case 0 :
F_35 ( V_2 , V_71 , V_73 ) ;
break;
case 2 :
F_37 ( V_2 , V_71 , V_73 ) ;
break;
case 3 :
F_39 ( V_2 , V_71 , V_73 ) ;
break;
}
if ( ( V_2 -> V_21 || V_2 -> V_22 ) && ! V_2 -> V_24 ) {
F_40 ( V_17 , L_5 ,
V_2 -> V_21 ? L_6 : L_7 ,
V_2 -> V_22 ? L_8 : L_7 ) ;
V_2 -> V_24 = 1 ;
}
}
static void F_42 ( struct V_1 * V_2 ,
struct V_71 * V_71 ,
const struct V_72 * V_73 )
{
unsigned char * V_74 = V_71 -> V_75 + V_73 -> V_76 ;
struct V_3 * V_4 ;
int V_6 , V_13 ;
for ( V_13 = 0 ; V_13 < V_73 -> V_87 ; ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_55 ; V_6 ++ , V_13 ++ ) {
V_4 = V_2 -> V_8 [ V_6 ] ;
if ( V_4 ) {
struct V_42 * V_78 = V_4 -> V_32 ;
char * V_79 = V_78 -> V_80 ;
int V_81 = F_36 ( V_78 , V_78 -> V_82 ) ;
V_74 [ V_13 ] =
V_79 [ V_2 -> V_48 [ V_6 ] ] ;
V_2 -> V_47 [ V_6 ] ++ ;
V_2 -> V_48 [ V_6 ] ++ ;
if ( V_2 -> V_48 [ V_6 ] == V_81 )
V_2 -> V_48 [ V_6 ] = 0 ;
} else
V_74 [ V_13 ] = 0 ;
}
if ( V_2 -> V_44 . V_45 == 2 &&
V_13 % ( V_2 -> V_55 * V_84 ) ==
( V_2 -> V_55 * V_54 ) )
for ( V_6 = 0 ; V_6 < V_2 -> V_55 ; V_6 ++ , V_13 ++ )
V_74 [ V_13 ] = F_38 ( V_2 , V_6 , V_13 ) ;
}
}
static void F_43 ( struct V_1 * V_2 ,
struct V_71 * V_71 ,
const struct V_72 * V_73 )
{
unsigned char * V_74 = V_71 -> V_75 + V_73 -> V_76 ;
int V_6 , V_13 ;
for ( V_13 = 0 ; V_13 < V_73 -> V_87 ; ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_55 ; V_6 ++ ) {
struct V_3 * V_4 = V_2 -> V_8 [ V_6 ] ;
char * V_79 = NULL ;
int V_85 , V_86 , V_81 = 0 ;
if ( V_4 ) {
struct V_42 * V_78 = V_4 -> V_32 ;
V_79 = V_78 -> V_80 ;
V_81 = F_36 ( V_78 , V_78 -> V_82 ) ;
}
for ( V_85 = 0 ; V_85 < V_54 ; V_85 ++ ) {
for ( V_86 = 0 ; V_86 < V_46 ; V_86 ++ ) {
if ( V_79 ) {
V_74 [ V_13 + V_86 ] = V_79 [ V_2 -> V_48 [ V_6 ] ++ ] ;
if ( V_2 -> V_48 [ V_6 ] == V_81 )
V_2 -> V_48 [ V_6 ] = 0 ;
} else {
V_74 [ V_13 + V_86 ] = 0 ;
}
}
if ( V_79 )
V_2 -> V_47 [ V_6 ] += V_46 ;
V_13 += V_46 ;
V_74 [ V_13 ++ ] = ( V_6 << 1 ) | V_85 ;
}
}
}
}
static inline void F_44 ( struct V_1 * V_2 ,
struct V_71 * V_71 ,
const struct V_72 * V_73 )
{
switch ( V_2 -> V_44 . V_45 ) {
case 0 :
case 2 :
F_42 ( V_2 , V_71 , V_73 ) ;
break;
case 3 :
F_43 ( V_2 , V_71 , V_73 ) ;
break;
}
}
static void F_45 ( struct V_71 * V_71 )
{
struct V_88 * V_89 = V_71 -> V_90 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_71 * V_91 = NULL ;
int V_13 , V_92 , V_93 , V_94 = 0 , V_95 = 0 ;
T_2 V_76 = 0 ;
if ( V_71 -> V_96 || ! V_89 )
return;
V_2 = V_89 -> V_2 ;
V_17 = F_9 ( V_2 ) ;
if ( ! V_2 -> V_19 )
return;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ )
if ( F_46 ( V_13 , & V_2 -> V_29 ) == 0 ) {
V_91 = V_2 -> V_30 [ V_13 ] ;
break;
}
if ( ! V_91 ) {
F_12 ( V_17 , L_9 ) ;
goto V_97;
}
for ( V_92 = 0 ; V_92 < V_98 ; V_92 ++ ) {
if ( V_71 -> V_99 [ V_92 ] . V_96 )
continue;
V_93 = V_71 -> V_99 [ V_95 ] . V_77 ;
V_91 -> V_99 [ V_95 ] . V_87 = V_93 ;
V_91 -> V_99 [ V_95 ] . V_77 = 0 ;
V_91 -> V_99 [ V_95 ] . V_76 = V_76 ;
V_76 += V_93 ;
if ( V_93 > 0 ) {
F_2 ( & V_2 -> V_5 ) ;
F_44 ( V_2 , V_91 , & V_91 -> V_99 [ V_95 ] ) ;
F_41 ( V_2 , V_71 , & V_71 -> V_99 [ V_92 ] ) ;
F_3 ( & V_2 -> V_5 ) ;
F_32 ( V_2 , V_2 -> V_8 ) ;
F_32 ( V_2 , V_2 -> V_10 ) ;
V_94 = 1 ;
}
V_95 ++ ;
}
if ( V_94 ) {
V_91 -> V_100 = V_95 ;
F_11 ( V_91 , V_27 ) ;
} else {
struct V_88 * V_101 = V_91 -> V_90 ;
F_47 ( V_101 -> V_41 , & V_2 -> V_29 ) ;
}
V_97:
for ( V_92 = 0 ; V_92 < V_98 ; V_92 ++ ) {
V_71 -> V_99 [ V_92 ] . V_76 = V_102 * V_92 ;
V_71 -> V_99 [ V_92 ] . V_87 = V_102 ;
V_71 -> V_99 [ V_92 ] . V_77 = 0 ;
}
V_71 -> V_100 = V_98 ;
F_11 ( V_71 , V_27 ) ;
}
static void F_48 ( struct V_71 * V_71 )
{
struct V_88 * V_89 = V_71 -> V_90 ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( ! V_2 -> V_58 ) {
V_2 -> V_58 = 1 ;
F_49 ( & V_2 -> V_59 ) ;
}
F_47 ( V_89 -> V_41 , & V_2 -> V_29 ) ;
}
static struct V_71 * * F_50 ( struct V_1 * V_2 , int V_103 , int * V_15 )
{
int V_13 , V_92 ;
struct V_71 * * V_104 ;
struct V_105 * V_106 = V_2 -> V_107 . V_17 ;
unsigned int V_108 ;
V_108 = ( V_103 == V_7 ) ?
F_51 ( V_106 , V_109 ) :
F_52 ( V_106 , V_110 ) ;
V_104 = F_53 ( V_25 * sizeof( * V_104 ) , V_111 ) ;
if ( ! V_104 ) {
* V_15 = - V_112 ;
return NULL ;
}
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
V_104 [ V_13 ] = F_54 ( V_98 , V_111 ) ;
if ( ! V_104 [ V_13 ] ) {
* V_15 = - V_112 ;
return V_104 ;
}
V_104 [ V_13 ] -> V_75 =
F_53 ( V_98 * V_102 , V_111 ) ;
if ( ! V_104 [ V_13 ] -> V_75 ) {
* V_15 = - V_112 ;
return V_104 ;
}
for ( V_92 = 0 ; V_92 < V_98 ; V_92 ++ ) {
struct V_72 * V_73 =
& V_104 [ V_13 ] -> V_99 [ V_92 ] ;
V_73 -> V_76 = V_102 * V_92 ;
V_73 -> V_87 = V_102 ;
}
V_104 [ V_13 ] -> V_17 = V_106 ;
V_104 [ V_13 ] -> V_108 = V_108 ;
V_104 [ V_13 ] -> V_113 = V_98
* V_102 ;
V_104 [ V_13 ] -> V_90 = & V_2 -> V_114 [ V_13 ] ;
V_104 [ V_13 ] -> V_115 = 1 ;
V_104 [ V_13 ] -> V_100 = V_98 ;
V_104 [ V_13 ] -> V_116 = ( V_103 == V_117 ) ?
F_45 : F_48 ;
}
* V_15 = 0 ;
return V_104 ;
}
static void F_55 ( struct V_71 * * V_104 )
{
int V_13 ;
if ( ! V_104 )
return;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
if ( ! V_104 [ V_13 ] )
continue;
F_14 ( V_104 [ V_13 ] ) ;
F_56 ( V_104 [ V_13 ] -> V_75 ) ;
F_57 ( V_104 [ V_13 ] ) ;
}
F_56 ( V_104 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_13 , V_15 ;
struct V_16 * V_17 = F_9 ( V_2 ) ;
V_2 -> V_118 = F_59 ( V_2 -> V_44 . V_119 ,
V_2 -> V_44 . V_120 ) /
V_54 ;
V_2 -> V_121 = F_59 ( V_2 -> V_44 . V_122 ,
V_2 -> V_44 . V_123 ) /
V_54 ;
V_2 -> V_55 = F_59 ( V_2 -> V_118 , V_2 -> V_121 ) ;
F_10 ( V_17 , L_10 , V_2 -> V_118 ) ;
F_10 ( V_17 , L_11 , V_2 -> V_121 ) ;
F_10 ( V_17 , L_12 , V_2 -> V_55 ) ;
if ( V_2 -> V_55 > V_14 ) {
F_12 ( V_17 , L_13 ) ;
return - V_20 ;
}
if ( V_2 -> V_55 < 1 ) {
F_12 ( V_17 , L_14 , V_2 -> V_55 ) ;
return - V_20 ;
}
V_15 = F_60 ( V_2 -> V_107 . V_124 , V_2 -> V_125 , 0 ,
V_2 -> V_121 , V_2 -> V_118 , & V_2 -> V_126 ) ;
if ( V_15 < 0 ) {
F_12 ( V_17 , L_15 , V_15 ) ;
return V_15 ;
}
V_2 -> V_126 -> V_127 = V_2 ;
F_61 ( V_2 -> V_126 -> V_128 , V_2 -> V_125 , sizeof( V_2 -> V_126 -> V_128 ) ) ;
memset ( V_2 -> V_8 , 0 , sizeof( V_2 -> V_8 ) ) ;
memset ( V_2 -> V_10 , 0 , sizeof( V_2 -> V_10 ) ) ;
memcpy ( & V_2 -> V_34 , & V_129 ,
sizeof( V_129 ) ) ;
V_2 -> V_36 = V_2 -> V_34 . V_35 ;
switch ( V_2 -> V_107 . V_130 ) {
case F_62 ( V_131 , V_132 ) :
case F_62 ( V_131 , V_133 ) :
case F_62 ( V_131 , V_134 ) :
case F_62 ( V_131 , V_135 ) :
V_2 -> V_36 |= V_136 ;
case F_62 ( V_131 , V_137 ) :
case F_62 ( V_131 , V_138 ) :
case F_62 ( V_131 , V_139 ) :
case F_62 ( V_131 , V_140 ) :
V_2 -> V_36 |= V_141 ;
break;
}
F_63 ( V_2 -> V_126 , V_7 ,
& V_142 ) ;
F_63 ( V_2 -> V_126 , V_117 ,
& V_142 ) ;
V_2 -> V_114 =
F_53 ( sizeof( struct V_88 ) * V_25 ,
V_111 ) ;
if ( ! V_2 -> V_114 )
return - V_112 ;
V_2 -> V_29 = 0 ;
F_64 ( V_25 > ( sizeof( V_2 -> V_29 ) * 8 ) ) ;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
V_2 -> V_114 [ V_13 ] . V_2 = V_2 ;
V_2 -> V_114 [ V_13 ] . V_41 = V_13 ;
}
V_2 -> V_26 = F_50 ( V_2 , V_117 , & V_15 ) ;
if ( V_15 < 0 ) {
F_56 ( V_2 -> V_114 ) ;
F_55 ( V_2 -> V_26 ) ;
return V_15 ;
}
V_2 -> V_30 = F_50 ( V_2 , V_7 , & V_15 ) ;
if ( V_15 < 0 ) {
F_56 ( V_2 -> V_114 ) ;
F_55 ( V_2 -> V_26 ) ;
F_55 ( V_2 -> V_30 ) ;
return V_15 ;
}
return 0 ;
}
void F_65 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_9 ( V_2 ) ;
F_10 ( V_17 , L_1 , V_18 , V_2 ) ;
F_13 ( V_2 ) ;
F_55 ( V_2 -> V_26 ) ;
F_55 ( V_2 -> V_30 ) ;
F_56 ( V_2 -> V_114 ) ;
}
