int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 )
{
return F_2 ( & V_2 -> V_6 , V_4 ) ;
}
static int F_3 ( struct V_3 * V_4 ,
unsigned long V_7 , void * V_8 )
{
unsigned char * V_9 = ( unsigned char * ) V_8 ;
if ( V_7 != V_10 )
return V_11 ;
F_4 ( V_12 L_1 , V_7 ) ;
F_5 ( V_12 , L_2 , V_13 , 16 , 1 ,
V_9 , V_9 [ 1 ] + 2 , true ) ;
return V_14 ;
}
static struct V_15 * F_6 ( struct V_1 * V_2 ,
enum V_16 V_17 )
{
int V_18 = ( V_17 == V_19 ) ? ( V_20 / 4 ) : 0 ;
for (; V_18 < V_20 ; V_18 ++ ) {
if ( F_7 ( & V_2 -> V_21 [ V_18 ] . V_22 , 1 ) == 0 ) {
F_8 ( V_2 -> V_23 , L_3 , V_18 ) ;
return & V_2 -> V_21 [ V_18 ] ;
}
}
F_9 ( V_2 -> V_23 , L_4 ,
( V_17 == V_19 ) ? L_5 : L_6 ) ;
return NULL ;
}
inline void F_10 ( struct V_1 * V_2 , struct V_15 * V_9 )
{
if ( V_9 != & V_2 -> V_24 )
F_8 ( V_2 -> V_23 , L_7 , V_9 - V_2 -> V_21 ) ;
F_11 ( & V_9 -> V_22 , 0 ) ;
}
static bool F_12 ( struct V_15 * V_9 )
{
return V_9 -> V_8 [ 0 ] >> 7 ;
}
static T_1 F_13 ( struct V_15 * V_9 )
{
bool V_25 = F_12 ( V_9 ) ;
int V_26 = ( V_9 -> V_8 [ 0 ] & 0x60 ) >> 5 ;
if ( ! V_25 || V_26 == V_27 )
return ( V_9 -> V_28 || V_9 -> V_29 ) ? ( V_9 -> V_8 [ 1 ] + 2 ) : 0 ;
else if ( V_26 == V_30 )
return 2 ;
else if ( V_26 == V_31 )
return 3 ;
else
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_32 )
{
F_15 ( V_2 -> V_23 , L_8 ,
F_16 ( V_2 -> V_33 ) , V_32 ) ;
F_17 ( V_2 -> V_33 , V_32 ) ;
}
int F_18 ( struct V_1 * V_2 , const unsigned char * V_8 ,
short V_29 )
{
struct V_15 * V_9 ;
unsigned long V_34 ;
V_9 = F_6 ( V_2 , V_19 ) ;
if ( V_9 == NULL )
return - V_35 ;
V_9 -> V_8 [ 0 ] = V_29 ;
memcpy ( V_9 -> V_8 + 1 , V_8 , V_29 ) ;
V_9 -> V_29 = V_29 + 1 ;
F_19 ( & V_2 -> V_36 , V_34 ) ;
F_20 ( & V_9 -> V_37 , & V_2 -> V_38 ) ;
F_21 ( & V_2 -> V_36 , V_34 ) ;
F_22 ( V_2 -> V_39 , & V_2 -> V_40 ) ;
return 0 ;
}
struct V_15 * F_23 ( struct V_1 * V_2 ,
const unsigned char * V_8 , short V_29 )
{
struct V_15 * V_9 ;
F_24 ( & V_2 -> V_41 ) ;
V_2 -> V_42 = ( V_8 [ 1 ] << 8 ) + V_8 [ 0 ] ;
if ( F_18 ( V_2 , V_8 , V_29 ) < 0 )
return NULL ;
F_15 ( V_2 -> V_23 , L_9 ,
V_2 -> V_42 ) ;
if ( ! ( F_25 ( & V_2 -> V_43 ,
F_26 ( 2000 ) ) ) ) {
F_27 ( V_2 -> V_23 , L_10 ) ;
F_28 ( & V_2 -> V_41 ) ;
return NULL ;
}
F_15 ( V_2 -> V_23 , L_11 ) ;
V_9 = V_2 -> V_44 ;
F_28 ( & V_2 -> V_41 ) ;
return V_9 ;
}
static void F_29 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_30 ( V_46 , struct V_1 , V_40 ) ;
unsigned long V_34 ;
long V_47 ;
struct V_15 * V_9 ;
F_19 ( & V_2 -> V_36 , V_34 ) ;
while ( ! F_31 ( & V_2 -> V_38 ) ) {
V_9 = F_32 ( & V_2 -> V_38 , struct V_15 , V_37 ) ;
F_21 ( & V_2 -> V_36 , V_34 ) ;
F_14 ( V_2 , 0 ) ;
V_47 = F_33 (
& V_2 -> V_48 , F_26 ( 5000 ) ) ;
if ( V_47 == 0 ) {
F_27 ( V_2 -> V_23 , L_12 ) ;
F_14 ( V_2 , 1 ) ;
V_9 -> V_28 = 0 ;
}
F_19 ( & V_2 -> V_36 , V_34 ) ;
if ( V_47 > 0 ) {
F_34 ( & V_9 -> V_37 ) ;
F_10 ( V_2 , V_9 ) ;
}
}
F_21 ( & V_2 -> V_36 , V_34 ) ;
}
static int F_35 ( struct V_1 * V_2 , struct V_15 * V_9 )
{
if ( ( V_9 -> V_8 [ 0 ] & 1 << 7 ) == 0 && V_9 -> V_8 [ 3 ] ) {
F_9 ( V_2 -> V_23 , L_13 ,
V_9 -> V_8 [ 0 ] , V_9 -> V_8 [ 1 ] , V_9 -> V_8 [ 2 ] , V_9 -> V_8 [ 3 ] ) ;
return - V_49 ;
}
if ( ( V_9 -> V_8 [ 0 ] >> 7 ) == 1 && ( V_9 -> V_8 [ 0 ] & 0x0f ) == 5 )
F_5 ( V_12 , L_14 ,
V_13 , 16 , 1 , V_9 -> V_8 ,
V_9 -> V_8 [ 1 ] + 2 , true ) ;
F_36 ( & V_2 -> V_6 , V_9 -> V_8 [ 0 ] & 0x8f ,
V_9 -> V_8 ) ;
return 0 ;
}
static void F_37 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_30 ( V_46 , struct V_1 , V_50 ) ;
unsigned long V_34 ;
struct V_15 * V_9 ;
F_19 ( & V_2 -> V_51 , V_34 ) ;
while ( ! F_31 ( & V_2 -> V_52 ) ) {
V_9 = F_32 ( & V_2 -> V_52 , struct V_15 , V_37 ) ;
F_34 ( & V_9 -> V_37 ) ;
F_21 ( & V_2 -> V_51 , V_34 ) ;
if ( V_2 -> V_42 ==
( V_9 -> V_8 [ 2 ] << 8 ) + V_9 -> V_8 [ 0 ] ) {
F_15 ( V_2 -> V_23 , L_15 ) ;
V_2 -> V_42 = 0 ;
V_2 -> V_44 = V_9 ;
F_38 ( & V_2 -> V_43 ) ;
} else {
F_35 ( V_2 , V_9 ) ;
F_10 ( V_2 , V_9 ) ;
}
F_19 ( & V_2 -> V_51 , V_34 ) ;
}
F_21 ( & V_2 -> V_51 , V_34 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 -> V_28 != V_2 -> V_53 -> V_29 ) {
F_9 ( V_2 -> V_23 , L_16 ) ;
V_2 -> V_53 -> V_28 = 0 ;
F_14 ( V_2 , 0 ) ;
} else {
V_2 -> V_54 = 0 ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_55 -> V_28 != F_13 ( V_2 -> V_55 ) ) {
F_9 ( V_2 -> V_23 , L_17 ,
( V_56 ) F_13 ( V_2 -> V_55 ) ,
( V_56 ) V_2 -> V_55 -> V_28 ) ;
F_10 ( V_2 , V_2 -> V_55 ) ;
V_2 -> V_54 = 0 ;
if ( V_2 -> V_55 -> V_8 [ 0 ] == V_57 )
F_38 ( & V_2 -> V_48 ) ;
return;
}
F_41 ( & V_2 -> V_51 ) ;
F_20 ( & V_2 -> V_55 -> V_37 , & V_2 -> V_52 ) ;
F_42 ( & V_2 -> V_51 ) ;
V_2 -> V_54 = 0 ;
if ( ! F_12 ( V_2 -> V_55 ) )
F_38 ( & V_2 -> V_48 ) ;
F_22 ( V_2 -> V_39 , & V_2 -> V_50 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_58 ,
bool V_59 )
{
F_9 ( V_2 -> V_23 , L_18 ,
V_58 , V_2 -> V_54 ) ;
if ( V_59 )
V_2 -> V_54 = 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_36 ) ;
if ( F_31 ( & V_2 -> V_38 ) ) {
F_9 ( V_2 -> V_23 , L_19 ) ;
memcpy ( V_2 -> V_24 . V_8 , L_20 , 3 ) ;
V_2 -> V_24 . V_29 = 3 ;
V_2 -> V_24 . V_28 = 0 ;
V_2 -> V_53 = & V_2 -> V_24 ;
F_20 ( & V_2 -> V_53 -> V_37 , & V_2 -> V_38 ) ;
} else {
V_2 -> V_53 = F_32 ( & V_2 -> V_38 , struct V_15 ,
V_37 ) ;
V_2 -> V_53 -> V_28 = 0 ;
}
F_42 ( & V_2 -> V_36 ) ;
F_15 ( V_2 -> V_23 , L_21 ,
( V_56 ) V_2 -> V_53 -> V_29 , V_2 -> V_53 -> V_8 [ 1 ] ) ;
}
static T_2 F_45 ( int V_60 , void * V_23 )
{
unsigned long V_58 ;
unsigned int V_61 = 0 ;
unsigned char V_62 = 0xff ;
const unsigned long V_63 = V_64 | V_65 | V_66 | V_67 ;
struct V_1 * V_2 = V_23 ;
unsigned int V_54 = V_2 -> V_54 ;
V_58 = F_46 ( V_2 -> V_68 + V_69 ) ;
if ( ( V_58 & V_63 ) == 0 && ( V_58 & ~ V_63 ) != 0 ) {
F_9 ( V_2 -> V_23 , L_22 , V_58 ) ;
return V_70 ;
}
if ( ( V_58 & V_64 ) == 0 ) {
F_9 ( V_2 -> V_23 , L_23 ) ;
return V_70 ;
}
if ( ( V_58 & V_67 ) == 0 ) {
V_61 = F_46 ( V_2 -> V_68 + V_71 ) ;
if ( V_58 & V_66 )
F_47 ( 0 , V_2 -> V_68 + V_71 ) ;
}
if ( V_58 == ( V_64 | V_66 ) )
V_2 -> V_54 = 0 ;
switch ( V_2 -> V_54 ) {
case 0 :
if ( V_58 != ( V_64 | V_66 ) )
F_43 ( V_2 , V_58 , false ) ;
break;
case 1 :
if ( V_58 != V_64 ) {
F_43 ( V_2 , V_58 , true ) ;
} else {
V_2 -> V_55 = F_6 ( V_2 , V_72 ) ;
if ( F_48 ( V_2 -> V_55 == NULL ) ) {
V_2 -> V_54 = 0 ;
break;
}
V_2 -> V_55 -> V_8 [ 0 ] = V_61 ;
V_2 -> V_55 -> V_28 = 1 ;
V_2 -> V_54 = 2 ;
}
break;
case 2 :
if ( V_58 == ( V_64 | V_67 | V_66 ) ) {
F_49 ( 33 ) ;
if ( V_2 -> V_55 -> V_8 [ 0 ] != 0x01 ) {
F_9 ( V_2 -> V_23 ,
L_24 ) ;
V_2 -> V_54 = 0 ;
break;
}
F_10 ( V_2 , V_2 -> V_55 ) ;
V_2 -> V_54 = 3 ;
F_44 ( V_2 ) ;
F_50 ( V_2 -> V_53 -> V_29 < 1 ) ;
V_62 = V_2 -> V_53 -> V_8 [ 0 ] ;
V_2 -> V_53 -> V_28 = 1 ;
} else if ( V_58 == ( V_64 ) ) {
F_50 ( V_2 -> V_55 == NULL ) ;
V_2 -> V_55 -> V_8 [ 1 ] = V_61 ;
V_2 -> V_55 -> V_28 = 2 ;
V_2 -> V_54 = 4 ;
} else {
F_43 ( V_2 , V_58 , true ) ;
}
break;
case 3 :
if ( V_58 & V_65 ) {
F_39 ( V_2 ) ;
} else if ( ( V_58 & V_67 ) == 0 || ( V_58 & V_66 ) ) {
F_43 ( V_2 , V_58 , true ) ;
} else if ( V_2 -> V_53 && V_2 -> V_53 -> V_28 < V_2 -> V_53 -> V_29 ) {
V_62 = V_2 -> V_53 -> V_8 [ V_2 -> V_53 -> V_28 ++ ] ;
} else {
F_9 ( V_2 -> V_23 , L_25 ,
V_2 -> V_53 ,
( V_56 ) ( V_2 -> V_53 ? V_2 -> V_53 -> V_28 : 0 ) ,
( V_56 ) ( V_2 -> V_53 ? V_2 -> V_53 -> V_29 : 0 ) ) ;
V_2 -> V_54 = 0 ;
}
break;
case 4 :
if ( ( V_58 & ( V_65 | V_67 ) ) == V_65 )
F_40 ( V_2 ) ;
else if ( V_58 & ( V_67 | V_66 ) )
F_43 ( V_2 , V_58 , true ) ;
else if ( V_2 -> V_55 && V_2 -> V_55 -> V_28 < V_73 )
V_2 -> V_55 -> V_8 [ V_2 -> V_55 -> V_28 ++ ] = V_61 ;
else
F_9 ( V_2 -> V_23 ,
L_26
L_27 ,
V_2 -> V_55 , V_2 -> V_55 -> V_28 , V_73 ) ;
break;
default:
V_2 -> V_54 = 0 ;
}
if ( ( V_58 & ( V_66 | V_67 ) ) == V_66 ) {
if ( V_61 != V_2 -> V_74 )
F_9 ( V_2 -> V_23 ,
L_28 ,
V_61 , V_2 -> V_74 ) ;
V_2 -> V_54 = 1 ;
}
if ( ( V_58 & ( V_67 | V_65 ) ) == V_67 )
F_47 ( V_62 , V_2 -> V_68 + V_71 ) ;
if ( V_58 == ( V_64 | V_67 | V_66 ) )
F_14 ( V_2 , 1 ) ;
F_15 ( V_2 -> V_23 ,
L_29 ,
( V_58 & V_67 ) == 0 ? L_30 : L_31 ,
V_61 ,
( V_58 & ( V_67 | V_65 ) ) ? L_32 : L_33 ,
V_62 ,
V_54 ,
V_58 & V_65 ? L_34 : L_35 ,
V_58 & V_66 ? L_36 : L_35 ,
V_58 & V_67 ? L_37 : L_35 ) ;
F_49 ( 100 ) ;
return V_70 ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_3 V_75 ;
F_52 ( V_2 -> V_76 ) ;
F_53 ( V_2 -> V_76 ) ;
F_49 ( 2 ) ;
F_54 ( V_2 -> V_76 ) ;
V_75 = V_77 | V_78 |
( 0x2 << V_79 ) ;
F_47 ( V_75 , V_2 -> V_68 + V_80 ) ;
F_55 ( V_2 -> V_76 , 8 * 80000 ) ;
F_47 ( V_81 , V_2 -> V_68 + V_82 ) ;
F_47 ( 0x1E , V_2 -> V_68 + V_83 ) ;
F_47 ( V_2 -> V_74 >> 1 , V_2 -> V_68 + V_84 ) ;
F_47 ( 0 , V_2 -> V_68 + V_85 ) ;
F_56 ( V_2 -> V_60 ) ;
F_57 ( V_2 -> V_76 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 -> V_60 ) ;
F_47 ( V_81 | V_86 , V_2 -> V_68 + V_82 ) ;
F_57 ( V_2 -> V_76 ) ;
}
static void F_60 ( void )
{
F_18 ( V_87 , V_88 , 3 ) ;
F_18 ( V_87 , L_38 , 2 ) ;
}
static int T_4 F_61 ( struct V_89 * V_90 )
{
int V_47 , V_91 ;
struct V_92 * V_76 ;
struct V_93 * V_94 = V_90 -> V_23 . V_95 ;
struct V_1 * V_2 ;
struct V_15 * V_9 ;
struct V_96 * V_97 ;
struct V_96 * V_98 ;
void T_5 * V_68 ;
V_2 = F_62 ( sizeof( struct V_1 ) , V_99 ) ;
if ( V_2 == NULL ) {
F_9 ( & V_90 -> V_23 , L_39 ) ;
return - V_35 ;
}
F_63 ( V_90 , V_2 ) ;
V_2 -> V_23 = & V_90 -> V_23 ;
if ( V_94 ) {
V_2 -> V_33 = V_94 -> V_33 ;
V_2 -> V_74 = V_94 -> V_74 ;
} else if ( V_2 -> V_23 -> V_100 ) {
V_2 -> V_33 = F_64 ( V_2 -> V_23 -> V_100 , L_40 , 0 ) ;
if ( V_2 -> V_33 < 0 ) {
F_9 ( & V_90 -> V_23 , L_41 ) ;
goto V_101;
}
if ( F_65 ( V_2 -> V_23 -> V_100 , L_42 , & V_2 -> V_74 ) ) {
F_9 ( & V_90 -> V_23 , L_43 ) ;
goto V_101;
}
} else {
F_9 ( & V_90 -> V_23 , L_44 ) ;
goto V_101;
}
V_97 = F_66 ( V_90 , V_102 , 0 ) ;
if ( ! V_97 ) {
F_9 ( & V_90 -> V_23 , L_45 ) ;
return - V_103 ;
}
V_98 = F_67 ( V_97 -> V_104 , F_68 ( V_97 ) , V_90 -> V_105 ) ;
if ( ! V_98 ) {
F_9 ( & V_90 -> V_23 , L_46 ) ;
return - V_106 ;
}
V_68 = F_69 ( V_98 -> V_104 , F_68 ( V_98 ) ) ;
if ( ! V_68 ) {
F_9 ( & V_90 -> V_23 , L_47 ) ;
return - V_35 ;
}
V_97 = F_66 ( V_90 , V_107 , 0 ) ;
if ( ! V_97 ) {
F_9 ( & V_90 -> V_23 , L_48 ) ;
V_91 = - V_103 ;
goto V_108;
}
V_76 = F_70 ( L_49 , NULL ) ;
if ( F_71 ( V_76 ) ) {
F_9 ( V_2 -> V_23 , L_50 ) ;
goto V_108;
}
V_2 -> V_68 = V_68 ;
V_2 -> V_60 = V_97 -> V_104 ;
V_2 -> V_76 = V_76 ;
V_2 -> V_55 = & V_2 -> V_21 [ 0 ] ;
V_47 = F_72 ( V_2 -> V_33 , L_51 ) ;
if ( V_47 < 0 )
F_9 ( V_2 -> V_23 , L_52 ) ;
F_73 ( & V_2 -> V_6 ) ;
F_74 ( & V_2 -> V_43 ) ;
F_74 ( & V_2 -> V_48 ) ;
F_75 ( & V_2 -> V_41 ) ;
F_76 ( & V_2 -> V_36 ) ;
F_76 ( & V_2 -> V_51 ) ;
F_77 ( & V_2 -> V_52 ) ;
F_77 ( & V_2 -> V_38 ) ;
F_78 ( & V_2 -> V_50 , F_37 ) ;
F_78 ( & V_2 -> V_40 , F_29 ) ;
V_2 -> V_39 = F_79 ( L_53 , V_109 , 2 ) ;
V_47 = F_80 ( V_2 -> V_60 , F_45 , 0 , L_53 , V_2 ) ;
if ( V_47 ) {
F_9 ( V_2 -> V_23 , L_54 ) ;
goto V_101;
}
F_59 ( V_2 -> V_60 ) ;
F_51 ( V_2 ) ;
F_52 ( V_76 ) ;
F_81 ( V_2 -> V_33 , 1 ) ;
F_17 ( V_2 -> V_33 , 1 ) ;
F_18 ( V_2 , V_110 ,
sizeof( V_110 ) ) ;
V_2 -> F_3 . V_111 = F_3 ;
F_1 ( V_2 , & V_2 -> F_3 , 0 ) ;
V_87 = V_2 ;
V_112 = F_60 ;
V_9 = F_23 ( V_2 , V_113 ,
sizeof( V_113 ) ) ;
if ( V_9 ) {
F_27 ( V_2 -> V_23 , L_55 ,
V_9 -> V_8 [ 4 ] , V_9 -> V_8 [ 5 ] , V_9 -> V_8 [ 6 ] , V_9 -> V_8 [ 7 ] ) ;
F_10 ( V_2 , V_9 ) ;
}
V_91 = F_82 ( V_2 -> V_23 , - 1 , V_114 ,
F_83 ( V_114 ) , V_68 , 0 ) ;
if ( V_91 )
F_9 ( V_2 -> V_23 , L_56 ) ;
F_18 ( V_2 , L_57 , 4 ) ;
F_18 ( V_2 , L_58 , 7 ) ;
F_18 ( V_2 , L_59 , 7 ) ;
return 0 ;
V_108:
F_84 ( V_68 ) ;
V_101:
F_85 ( V_2 ) ;
return - V_35 ;
}
static int T_6 F_86 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_87 ( V_90 ) ;
F_18 ( V_2 , V_88 , 3 ) ;
F_88 ( V_2 -> V_23 ) ;
F_89 ( V_2 -> V_60 , & F_45 ) ;
F_84 ( V_2 -> V_68 ) ;
F_90 ( V_2 -> V_33 ) ;
F_91 ( V_2 -> V_39 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_89 * V_90 , T_7 V_54 )
{
struct V_1 * V_2 = F_87 ( V_90 ) ;
struct V_15 * V_9 ;
F_15 ( V_2 -> V_23 , L_60 ) ;
V_9 = F_23 ( V_2 , V_88 , 3 ) ;
F_10 ( V_2 , V_9 ) ;
V_9 = F_23 ( V_2 , L_61 , 2 ) ;
F_10 ( V_2 , V_9 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static int F_93 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_87 ( V_90 ) ;
F_15 ( V_2 -> V_23 , L_62 ) ;
F_51 ( V_2 ) ;
F_18 ( V_2 , V_110 , 3 ) ;
return 0 ;
}
static int T_8 F_94 ( void )
{
return F_95 ( & V_115 ) ;
}
