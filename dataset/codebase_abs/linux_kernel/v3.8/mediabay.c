static T_1
F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 , V_3 ) >> 12 ) & 7 ;
}
static T_1
F_3 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 , V_4 ) >> 12 ) & 7 ;
}
static T_1
F_4 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_5 ( V_2 , V_6 ) & V_7 ;
if ( V_5 ) {
V_2 -> V_8 = V_5 ;
return V_9 ;
} else if ( V_2 -> V_8 != V_5 ) {
F_6 ( V_2 , V_10 , V_11 ) ;
( void ) F_2 ( V_2 , V_10 ) ;
F_7 ( 5 ) ;
F_8 ( V_2 , V_10 , 0x0000000F ) ;
( void ) F_2 ( V_2 , V_10 ) ;
F_7 ( 5 ) ;
V_2 -> V_8 = V_5 ;
}
return ( F_2 ( V_2 , V_10 ) >> 4 ) & 7 ;
}
static void
F_9 ( struct V_1 * V_2 , int V_12 )
{
if ( V_12 ) {
F_8 ( V_2 , V_13 , V_14 ) ;
F_8 ( V_2 , V_13 , V_15 ) ;
} else {
F_8 ( V_2 , V_13 , V_16 ) ;
F_8 ( V_2 , V_13 , V_17 ) ;
F_6 ( V_2 , V_13 , V_15 ) ;
F_6 ( V_2 , V_13 , V_14 ) ;
F_6 ( V_2 , V_13 , V_18 ) ;
}
F_8 ( V_2 , V_3 , 0x00000F00 ) ;
}
static void
F_10 ( struct V_1 * V_2 , int V_12 )
{
if ( V_12 ) {
F_8 ( V_2 , V_19 , V_20 ) ;
F_8 ( V_2 , V_19 , V_21 ) ;
} else {
F_8 ( V_2 , V_19 , V_22 ) ;
F_8 ( V_2 , V_19 , V_23 ) ;
F_6 ( V_2 , V_19 , V_21 ) ;
F_6 ( V_2 , V_19 , V_20 ) ;
F_6 ( V_2 , V_19 , V_24 ) ;
}
F_8 ( V_2 , V_4 , 0x00000F00 ) ;
}
static void
F_11 ( struct V_1 * V_2 , int V_12 )
{
if ( V_12 ) {
F_8 ( V_2 , V_10 , V_25 ) ;
F_8 ( V_2 , V_10 , V_26 ) ;
} else {
F_8 ( V_2 , V_10 , V_27 ) ;
F_8 ( V_2 , V_28 , V_29 ) ;
F_6 ( V_2 , V_10 , V_26 ) ;
F_6 ( V_2 , V_10 , V_25 ) ;
F_6 ( V_2 , V_28 , V_30 ) ;
}
F_8 ( V_2 , V_10 , 0x0000000F ) ;
}
static int
F_12 ( struct V_1 * V_2 , T_1 V_31 )
{
switch( V_31 ) {
case V_32 :
case V_33 :
F_6 ( V_2 , V_13 , V_34 ) ;
F_6 ( V_2 , V_13 , V_17 ) ;
return 0 ;
case V_35 :
F_8 ( V_2 , V_13 , V_18 ) ;
F_6 ( V_2 , V_13 , V_36 ) ;
return 0 ;
case V_37 :
F_6 ( V_2 , V_13 , V_38 ) ;
return 0 ;
}
return - V_39 ;
}
static int
F_13 ( struct V_1 * V_2 , T_1 V_31 )
{
switch( V_31 ) {
case V_32 :
case V_33 :
F_6 ( V_2 , V_19 , V_40 ) ;
F_6 ( V_2 , V_19 , V_23 ) ;
return 0 ;
case V_35 :
F_8 ( V_2 , V_19 , V_24 ) ;
F_6 ( V_2 , V_19 , V_41 ) ;
return 0 ;
case V_37 :
F_6 ( V_2 , V_19 , V_42 ) ;
return 0 ;
}
return - V_39 ;
}
static int
F_14 ( struct V_1 * V_2 , T_1 V_31 )
{
switch( V_31 ) {
case V_35 :
F_6 ( V_2 , V_10 , V_43 ) ;
F_8 ( V_2 , V_28 , V_30 ) ;
F_6 ( V_2 , V_28 , V_29 ) ;
return 0 ;
case V_37 :
F_6 ( V_2 , V_10 , V_44 ) ;
return 0 ;
case V_45 :
F_6 ( V_2 , V_10 , V_46 ) ;
return 0 ;
}
return - V_39 ;
}
static void
F_15 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_13 , V_14 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_10 , V_11 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_19 , V_20 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_10 , V_25 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_13 , V_18 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_19 , V_24 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_28 , V_30 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , int V_47 )
{
if ( V_47 ) {
V_2 -> V_48 -> V_49 ( V_2 , 1 ) ;
V_2 -> V_50 = V_51 ;
F_23 ( L_1 , V_2 -> V_52 ) ;
} else {
V_2 -> V_48 -> V_49 ( V_2 , 0 ) ;
V_2 -> V_50 = V_53 ;
F_23 ( L_2 , V_2 -> V_52 ) ;
}
V_2 -> V_54 = F_24 ( V_55 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_56 = V_2 -> V_48 -> V_57 ( V_2 ) ;
static char * V_58 [] = {
L_3 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
} ;
if ( V_56 != V_2 -> V_59 ) {
V_2 -> V_59 = V_56 ;
V_2 -> V_60 = 0 ;
return;
}
if ( V_56 == V_2 -> V_61 )
return;
V_2 -> V_60 += F_24 ( V_62 ) ;
if ( V_2 -> V_60 >= F_24 ( V_63 ) ) {
if ( ( V_56 != V_9 ) && ( V_2 -> V_61 != V_9 ) ) {
V_56 = V_9 ;
F_23 ( L_8 , V_2 -> V_52 ) ;
}
F_23 ( L_9 , V_2 -> V_52 , V_56 ) ;
F_22 ( V_2 , V_56 != V_9 ) ;
V_2 -> V_61 = V_56 ;
if ( V_56 >= V_9 || V_56 < 0 )
F_26 ( V_64 L_10 , V_2 -> V_52 ) ;
else
F_26 ( V_64 L_11 ,
V_2 -> V_52 , V_58 [ V_56 ] ) ;
}
}
int F_27 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
int V_56 ;
if ( V_66 == NULL )
return V_9 ;
V_2 = F_28 ( V_66 ) ;
if ( V_2 == NULL )
return V_9 ;
V_56 = V_2 -> V_61 ;
if ( V_2 -> V_50 != V_67 )
return V_9 ;
if ( V_56 == V_33 )
return V_32 ;
return V_56 ;
}
void F_29 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
if ( V_66 == NULL )
return;
V_2 = F_28 ( V_66 ) ;
if ( V_2 == NULL )
return;
F_30 ( & V_2 -> V_68 ) ;
V_2 -> V_69 = 1 ;
}
void F_31 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
if ( V_66 == NULL )
return;
V_2 = F_28 ( V_66 ) ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_69 ) {
V_2 -> V_69 = 0 ;
F_32 ( & V_2 -> V_68 ) ;
}
}
static int F_33 ( struct V_70 * V_71 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_65 * V_73 ;
struct V_74 * V_75 ;
int V_50 ;
if ( V_71 -> V_76 != & V_77 )
return 0 ;
V_50 = V_2 -> V_50 == V_67 ? V_2 -> V_61 : V_9 ;
if ( V_50 == V_33 )
V_50 = V_32 ;
V_73 = F_34 ( V_71 ) ;
V_75 = F_35 ( V_71 -> V_78 ) ;
if ( V_71 -> V_78 && V_75 -> V_79 )
V_75 -> V_79 ( V_73 , V_50 ) ;
return 0 ;
}
static void F_36 ( int V_80 )
{
struct V_1 * V_2 = & V_81 [ V_80 ] ;
if ( V_2 -> V_50 != V_53 )
F_25 ( V_2 ) ;
if ( V_2 -> V_54 != 0 ) {
V_2 -> V_54 -= F_24 ( V_62 ) ;
if ( V_2 -> V_54 > 0 )
return;
V_2 -> V_54 = 0 ;
}
switch( V_2 -> V_50 ) {
case V_51 :
if ( V_2 -> V_48 -> V_82 ( V_2 , V_2 -> V_59 ) < 0 ) {
F_23 ( L_12 ,
V_80 , V_2 -> V_61 ) ;
F_22 ( V_2 , 0 ) ;
break;
}
V_2 -> V_54 = F_24 ( V_83 ) ;
V_2 -> V_50 = V_84 ;
F_23 ( L_13 , V_80 , V_2 -> V_61 ) ;
break;
case V_84 :
V_2 -> V_48 -> V_85 ( V_2 ) ;
V_2 -> V_54 = F_24 ( V_86 ) ;
V_2 -> V_50 = V_87 ;
F_23 ( L_14 ,
V_80 , V_2 -> V_61 ) ;
break;
case V_87 :
if ( V_2 -> V_61 != V_35 ) {
F_23 ( L_15 , V_80 ,
V_2 -> V_61 ) ;
V_2 -> V_50 = V_67 ;
F_37 ( & V_2 -> V_73 -> V_88 . V_71 ,
V_2 , F_33 ) ;
break;
}
F_23 ( L_16 ,
V_80 , V_2 -> V_61 ) ;
V_2 -> V_48 -> V_89 ( V_2 ) ;
V_2 -> V_54 = F_24 ( V_90 ) ;
V_2 -> V_50 = V_91 ;
break;
case V_91 :
F_23 ( L_15 , V_80 , V_2 -> V_61 ) ;
V_2 -> V_50 = V_67 ;
F_37 ( & V_2 -> V_73 -> V_88 . V_71 ,
V_2 , F_33 ) ;
break;
case V_53 :
V_2 -> V_50 = V_92 ;
F_37 ( & V_2 -> V_73 -> V_88 . V_71 ,
V_2 , F_33 ) ;
F_23 ( L_17 , V_80 ) ;
break;
}
}
static int F_38 ( void * V_93 )
{
int V_80 ;
while ( ! F_39 () ) {
for ( V_80 = 0 ; V_80 < V_94 ; ++ V_80 ) {
F_30 ( & V_81 [ V_80 ] . V_68 ) ;
if ( ! V_81 [ V_80 ] . V_95 )
F_36 ( V_80 ) ;
F_32 ( & V_81 [ V_80 ] . V_68 ) ;
}
F_40 ( V_62 ) ;
}
return 0 ;
}
static int F_41 ( struct V_65 * V_73 ,
const struct V_96 * V_97 )
{
struct V_1 * V_2 ;
T_2 T_3 * V_98 ;
struct V_99 * V_100 ;
unsigned long V_101 ;
int V_80 ;
V_100 = V_73 -> V_88 . V_71 . V_102 ;
if ( F_42 ( V_73 ) < 1 )
return - V_39 ;
if ( F_43 ( V_73 , L_18 ) )
return - V_103 ;
V_101 = F_44 ( V_73 , 0 ) & 0xffff0000u ;
V_98 = ( T_2 T_3 * ) F_45 ( V_101 , 0x100 ) ;
if ( V_98 == NULL ) {
F_46 ( V_73 ) ;
return - V_104 ;
}
V_80 = V_94 ++ ;
V_2 = & V_81 [ V_80 ] ;
V_2 -> V_73 = V_73 ;
V_2 -> V_101 = V_98 ;
V_2 -> V_52 = V_80 ;
V_2 -> V_48 = V_97 -> V_72 ;
V_2 -> V_95 = 0 ;
F_47 ( & V_2 -> V_68 ) ;
if ( V_2 -> V_48 -> V_105 )
V_2 -> V_48 -> V_105 ( V_2 ) ;
F_26 ( V_64 L_19 , V_80 , V_2 -> V_48 -> V_106 ) ;
F_22 ( V_2 , 0 ) ;
F_48 ( V_55 ) ;
V_2 -> V_61 = V_9 ;
V_2 -> V_59 = V_2 -> V_48 -> V_57 ( V_2 ) ;
V_2 -> V_60 = F_24 ( V_63 ) ;
V_2 -> V_50 = V_92 ;
F_49 ( V_73 , V_2 ) ;
if ( V_80 == 0 )
F_50 ( F_38 , NULL , L_18 ) ;
return 0 ;
}
static int F_51 ( struct V_65 * V_73 , T_4 V_50 )
{
struct V_1 * V_2 = F_28 ( V_73 ) ;
if ( V_50 . V_107 != V_73 -> V_88 . V_71 . V_49 . V_108 . V_107
&& ( V_50 . V_107 & V_109 ) ) {
F_30 ( & V_2 -> V_68 ) ;
V_2 -> V_95 = 1 ;
F_22 ( V_2 , 0 ) ;
F_32 ( & V_2 -> V_68 ) ;
F_48 ( V_62 ) ;
V_73 -> V_88 . V_71 . V_49 . V_108 = V_50 ;
}
return 0 ;
}
static int F_52 ( struct V_65 * V_73 )
{
struct V_1 * V_2 = F_28 ( V_73 ) ;
if ( V_73 -> V_88 . V_71 . V_49 . V_108 . V_107 != V_110 ) {
V_73 -> V_88 . V_71 . V_49 . V_108 = V_111 ;
F_30 ( & V_2 -> V_68 ) ;
F_22 ( V_2 , 0 ) ;
F_48 ( V_55 ) ;
if ( V_2 -> V_48 -> V_57 ( V_2 ) != V_2 -> V_61 ) {
F_26 ( L_20 , V_2 -> V_52 ) ;
F_32 ( & V_2 -> V_68 ) ;
return 0 ;
}
F_22 ( V_2 , 1 ) ;
V_2 -> V_59 = V_2 -> V_61 ;
V_2 -> V_60 = F_24 ( V_63 ) ;
V_2 -> V_54 = F_24 ( V_55 ) ;
do {
F_48 ( V_62 ) ;
F_36 ( V_2 -> V_52 ) ;
} while( ( V_2 -> V_50 != V_92 ) &&
( V_2 -> V_50 != V_67 ) );
V_2 -> V_95 = 0 ;
F_32 ( & V_2 -> V_68 ) ;
}
return 0 ;
}
static int T_5 F_53 ( void )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_112 ; V_80 ++ ) {
memset ( ( char * ) & V_81 [ V_80 ] , 0 , sizeof( struct V_1 ) ) ;
V_81 [ V_80 ] . V_61 = - 1 ;
}
if ( ! F_54 ( V_113 ) )
return 0 ;
F_55 ( & V_114 ) ;
return 0 ;
}
