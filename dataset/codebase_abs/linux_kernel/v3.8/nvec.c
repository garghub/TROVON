int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 )
{
return F_2 ( & V_2 -> V_6 , V_4 ) ;
}
static int F_3 ( struct V_3 * V_4 ,
unsigned long V_7 , void * V_8 )
{
struct V_1 * V_2 = F_4 ( V_4 , struct V_1 ,
F_3 ) ;
unsigned char * V_9 = ( unsigned char * ) V_8 ;
if ( V_7 != V_10 )
return V_11 ;
F_5 ( V_2 -> V_12 , L_1 , V_7 ) ;
F_6 ( V_13 , L_2 , V_14 , 16 , 1 ,
V_9 , V_9 [ 1 ] + 2 , true ) ;
return V_15 ;
}
static struct V_16 * F_7 ( struct V_1 * V_2 ,
enum V_17 V_18 )
{
int V_19 = ( V_18 == V_20 ) ? ( V_21 / 4 ) : 0 ;
for (; V_19 < V_21 ; V_19 ++ ) {
if ( F_8 ( & V_2 -> V_22 [ V_19 ] . V_23 , 1 ) == 0 ) {
F_9 ( V_2 -> V_12 , L_3 , V_19 ) ;
return & V_2 -> V_22 [ V_19 ] ;
}
}
F_10 ( V_2 -> V_12 , L_4 ,
( V_18 == V_20 ) ? L_5 : L_6 ) ;
return NULL ;
}
inline void F_11 ( struct V_1 * V_2 , struct V_16 * V_9 )
{
if ( V_9 != & V_2 -> V_24 )
F_9 ( V_2 -> V_12 , L_7 , V_9 - V_2 -> V_22 ) ;
F_12 ( & V_9 -> V_23 , 0 ) ;
}
static bool F_13 ( struct V_16 * V_9 )
{
return V_9 -> V_8 [ 0 ] >> 7 ;
}
static T_1 F_14 ( struct V_16 * V_9 )
{
bool V_25 = F_13 ( V_9 ) ;
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
static void F_15 ( struct V_1 * V_2 , int V_32 )
{
F_16 ( V_2 -> V_12 , L_8 ,
F_17 ( V_2 -> V_33 ) , V_32 ) ;
F_18 ( V_2 -> V_33 , V_32 ) ;
}
int F_19 ( struct V_1 * V_2 , const unsigned char * V_8 ,
short V_29 )
{
struct V_16 * V_9 ;
unsigned long V_34 ;
V_9 = F_7 ( V_2 , V_20 ) ;
if ( V_9 == NULL )
return - V_35 ;
V_9 -> V_8 [ 0 ] = V_29 ;
memcpy ( V_9 -> V_8 + 1 , V_8 , V_29 ) ;
V_9 -> V_29 = V_29 + 1 ;
F_20 ( & V_2 -> V_36 , V_34 ) ;
F_21 ( & V_9 -> V_37 , & V_2 -> V_38 ) ;
F_22 ( & V_2 -> V_36 , V_34 ) ;
F_23 ( & V_2 -> V_39 ) ;
return 0 ;
}
struct V_16 * F_24 ( struct V_1 * V_2 ,
const unsigned char * V_8 , short V_29 )
{
struct V_16 * V_9 ;
F_25 ( & V_2 -> V_40 ) ;
V_2 -> V_41 = ( V_8 [ 1 ] << 8 ) + V_8 [ 0 ] ;
if ( F_19 ( V_2 , V_8 , V_29 ) < 0 ) {
F_26 ( & V_2 -> V_40 ) ;
return NULL ;
}
F_16 ( V_2 -> V_12 , L_9 ,
V_2 -> V_41 ) ;
if ( ! ( F_27 ( & V_2 -> V_42 ,
F_28 ( 2000 ) ) ) ) {
F_5 ( V_2 -> V_12 , L_10 ) ;
F_26 ( & V_2 -> V_40 ) ;
return NULL ;
}
F_16 ( V_2 -> V_12 , L_11 ) ;
V_9 = V_2 -> V_43 ;
F_26 ( & V_2 -> V_40 ) ;
return V_9 ;
}
static void F_29 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_4 ( V_45 , struct V_1 , V_39 ) ;
unsigned long V_34 ;
long V_46 ;
struct V_16 * V_9 ;
F_20 ( & V_2 -> V_36 , V_34 ) ;
while ( ! F_30 ( & V_2 -> V_38 ) ) {
V_9 = F_31 ( & V_2 -> V_38 , struct V_16 , V_37 ) ;
F_22 ( & V_2 -> V_36 , V_34 ) ;
F_15 ( V_2 , 0 ) ;
V_46 = F_32 (
& V_2 -> V_47 , F_28 ( 5000 ) ) ;
if ( V_46 == 0 ) {
F_5 ( V_2 -> V_12 , L_12 ) ;
F_15 ( V_2 , 1 ) ;
V_9 -> V_28 = 0 ;
}
F_20 ( & V_2 -> V_36 , V_34 ) ;
if ( V_46 > 0 ) {
F_33 ( & V_9 -> V_37 ) ;
F_11 ( V_2 , V_9 ) ;
}
}
F_22 ( & V_2 -> V_36 , V_34 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_16 * V_9 )
{
if ( ( V_9 -> V_8 [ 0 ] & 1 << 7 ) == 0 && V_9 -> V_8 [ 3 ] ) {
F_10 ( V_2 -> V_12 , L_13 , 4 , V_9 -> V_8 ) ;
return - V_48 ;
}
if ( ( V_9 -> V_8 [ 0 ] >> 7 ) == 1 && ( V_9 -> V_8 [ 0 ] & 0x0f ) == 5 )
F_6 ( V_13 , L_14 ,
V_14 , 16 , 1 , V_9 -> V_8 ,
V_9 -> V_8 [ 1 ] + 2 , true ) ;
F_35 ( & V_2 -> V_6 , V_9 -> V_8 [ 0 ] & 0x8f ,
V_9 -> V_8 ) ;
return 0 ;
}
static void F_36 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_4 ( V_45 , struct V_1 , V_49 ) ;
unsigned long V_34 ;
struct V_16 * V_9 ;
F_20 ( & V_2 -> V_50 , V_34 ) ;
while ( ! F_30 ( & V_2 -> V_51 ) ) {
V_9 = F_31 ( & V_2 -> V_51 , struct V_16 , V_37 ) ;
F_33 ( & V_9 -> V_37 ) ;
F_22 ( & V_2 -> V_50 , V_34 ) ;
if ( V_2 -> V_41 ==
( V_9 -> V_8 [ 2 ] << 8 ) + V_9 -> V_8 [ 0 ] ) {
F_16 ( V_2 -> V_12 , L_15 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_43 = V_9 ;
F_37 ( & V_2 -> V_42 ) ;
} else {
F_34 ( V_2 , V_9 ) ;
F_11 ( V_2 , V_9 ) ;
}
F_20 ( & V_2 -> V_50 , V_34 ) ;
}
F_22 ( & V_2 -> V_50 , V_34 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 -> V_28 != V_2 -> V_52 -> V_29 ) {
F_10 ( V_2 -> V_12 , L_16 ) ;
V_2 -> V_52 -> V_28 = 0 ;
F_15 ( V_2 , 0 ) ;
} else {
V_2 -> V_53 = 0 ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_54 -> V_28 != F_14 ( V_2 -> V_54 ) ) {
F_10 ( V_2 -> V_12 , L_17 ,
( V_55 ) F_14 ( V_2 -> V_54 ) ,
( V_55 ) V_2 -> V_54 -> V_28 ) ;
F_11 ( V_2 , V_2 -> V_54 ) ;
V_2 -> V_53 = 0 ;
if ( V_2 -> V_54 -> V_8 [ 0 ] == V_56 )
F_37 ( & V_2 -> V_47 ) ;
return;
}
F_40 ( & V_2 -> V_50 ) ;
F_21 ( & V_2 -> V_54 -> V_37 , & V_2 -> V_51 ) ;
F_41 ( & V_2 -> V_50 ) ;
V_2 -> V_53 = 0 ;
if ( ! F_13 ( V_2 -> V_54 ) )
F_37 ( & V_2 -> V_47 ) ;
F_23 ( & V_2 -> V_49 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_57 ,
bool V_58 )
{
F_10 ( V_2 -> V_12 , L_18 ,
V_57 , V_2 -> V_53 ) ;
if ( V_58 )
V_2 -> V_53 = 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_36 ) ;
if ( F_30 ( & V_2 -> V_38 ) ) {
F_10 ( V_2 -> V_12 , L_19 ) ;
memcpy ( V_2 -> V_24 . V_8 , L_20 , 3 ) ;
V_2 -> V_24 . V_29 = 3 ;
V_2 -> V_24 . V_28 = 0 ;
V_2 -> V_52 = & V_2 -> V_24 ;
F_21 ( & V_2 -> V_52 -> V_37 , & V_2 -> V_38 ) ;
} else {
V_2 -> V_52 = F_31 ( & V_2 -> V_38 , struct V_16 ,
V_37 ) ;
V_2 -> V_52 -> V_28 = 0 ;
}
F_41 ( & V_2 -> V_36 ) ;
F_16 ( V_2 -> V_12 , L_21 ,
( V_55 ) V_2 -> V_52 -> V_29 , V_2 -> V_52 -> V_8 [ 1 ] ) ;
}
static T_2 F_44 ( int V_59 , void * V_12 )
{
unsigned long V_57 ;
unsigned int V_60 = 0 ;
unsigned char V_61 = 0xff ;
const unsigned long V_62 = V_63 | V_64 | V_65 | V_66 ;
struct V_1 * V_2 = V_12 ;
unsigned int V_53 = V_2 -> V_53 ;
V_57 = F_45 ( V_2 -> V_67 + V_68 ) ;
if ( ( V_57 & V_62 ) == 0 && ( V_57 & ~ V_62 ) != 0 ) {
F_10 ( V_2 -> V_12 , L_22 , V_57 ) ;
return V_69 ;
}
if ( ( V_57 & V_63 ) == 0 ) {
F_10 ( V_2 -> V_12 , L_23 ) ;
return V_69 ;
}
if ( ( V_57 & V_66 ) == 0 ) {
V_60 = F_45 ( V_2 -> V_67 + V_70 ) ;
if ( V_57 & V_65 )
F_46 ( 0 , V_2 -> V_67 + V_70 ) ;
}
if ( V_57 == ( V_63 | V_65 ) )
V_2 -> V_53 = 0 ;
switch ( V_2 -> V_53 ) {
case 0 :
if ( V_57 != ( V_63 | V_65 ) )
F_42 ( V_2 , V_57 , false ) ;
break;
case 1 :
if ( V_57 != V_63 ) {
F_42 ( V_2 , V_57 , true ) ;
} else {
V_2 -> V_54 = F_7 ( V_2 , V_71 ) ;
if ( F_47 ( V_2 -> V_54 == NULL ) ) {
V_2 -> V_53 = 0 ;
break;
}
V_2 -> V_54 -> V_8 [ 0 ] = V_60 ;
V_2 -> V_54 -> V_28 = 1 ;
V_2 -> V_53 = 2 ;
}
break;
case 2 :
if ( V_57 == ( V_63 | V_66 | V_65 ) ) {
F_48 ( 33 ) ;
if ( V_2 -> V_54 -> V_8 [ 0 ] != 0x01 ) {
F_10 ( V_2 -> V_12 ,
L_24 ) ;
V_2 -> V_53 = 0 ;
break;
}
F_11 ( V_2 , V_2 -> V_54 ) ;
V_2 -> V_53 = 3 ;
F_43 ( V_2 ) ;
F_49 ( V_2 -> V_52 -> V_29 < 1 ) ;
V_61 = V_2 -> V_52 -> V_8 [ 0 ] ;
V_2 -> V_52 -> V_28 = 1 ;
} else if ( V_57 == ( V_63 ) ) {
F_49 ( V_2 -> V_54 == NULL ) ;
V_2 -> V_54 -> V_8 [ 1 ] = V_60 ;
V_2 -> V_54 -> V_28 = 2 ;
V_2 -> V_53 = 4 ;
} else {
F_42 ( V_2 , V_57 , true ) ;
}
break;
case 3 :
if ( V_57 & V_64 ) {
F_38 ( V_2 ) ;
} else if ( ( V_57 & V_66 ) == 0 || ( V_57 & V_65 ) ) {
F_42 ( V_2 , V_57 , true ) ;
} else if ( V_2 -> V_52 && V_2 -> V_52 -> V_28 < V_2 -> V_52 -> V_29 ) {
V_61 = V_2 -> V_52 -> V_8 [ V_2 -> V_52 -> V_28 ++ ] ;
} else {
F_10 ( V_2 -> V_12 , L_25 ,
V_2 -> V_52 ,
( V_55 ) ( V_2 -> V_52 ? V_2 -> V_52 -> V_28 : 0 ) ,
( V_55 ) ( V_2 -> V_52 ? V_2 -> V_52 -> V_29 : 0 ) ) ;
V_2 -> V_53 = 0 ;
}
break;
case 4 :
if ( ( V_57 & ( V_64 | V_66 ) ) == V_64 )
F_39 ( V_2 ) ;
else if ( V_57 & ( V_66 | V_65 ) )
F_42 ( V_2 , V_57 , true ) ;
else if ( V_2 -> V_54 && V_2 -> V_54 -> V_28 < V_72 )
V_2 -> V_54 -> V_8 [ V_2 -> V_54 -> V_28 ++ ] = V_60 ;
else
F_10 ( V_2 -> V_12 ,
L_26
L_27 ,
V_2 -> V_54 , V_2 -> V_54 -> V_28 , V_72 ) ;
break;
default:
V_2 -> V_53 = 0 ;
}
if ( ( V_57 & ( V_65 | V_66 ) ) == V_65 ) {
if ( V_60 != V_2 -> V_73 )
F_10 ( V_2 -> V_12 ,
L_28 ,
V_60 , V_2 -> V_73 ) ;
V_2 -> V_53 = 1 ;
}
if ( ( V_57 & ( V_66 | V_64 ) ) == V_66 )
F_46 ( V_61 , V_2 -> V_67 + V_70 ) ;
if ( V_57 == ( V_63 | V_66 | V_65 ) )
F_15 ( V_2 , 1 ) ;
F_16 ( V_2 -> V_12 ,
L_29 ,
( V_57 & V_66 ) == 0 ? L_30 : L_31 ,
V_60 ,
( V_57 & ( V_66 | V_64 ) ) ? L_32 : L_33 ,
V_61 ,
V_53 ,
V_57 & V_64 ? L_34 : L_35 ,
V_57 & V_65 ? L_36 : L_35 ,
V_57 & V_66 ? L_37 : L_35 ) ;
F_48 ( 100 ) ;
return V_69 ;
}
static void F_50 ( struct V_1 * V_2 )
{
T_3 V_74 ;
F_51 ( V_2 -> V_75 ) ;
F_52 ( V_2 -> V_75 ) ;
F_48 ( 2 ) ;
F_53 ( V_2 -> V_75 ) ;
V_74 = V_76 | V_77 |
( 0x2 << V_78 ) ;
F_46 ( V_74 , V_2 -> V_67 + V_79 ) ;
F_54 ( V_2 -> V_75 , 8 * 80000 ) ;
F_46 ( V_80 , V_2 -> V_67 + V_81 ) ;
F_46 ( 0x1E , V_2 -> V_67 + V_82 ) ;
F_46 ( V_2 -> V_73 >> 1 , V_2 -> V_67 + V_83 ) ;
F_46 ( 0 , V_2 -> V_67 + V_84 ) ;
F_55 ( V_2 -> V_59 ) ;
F_56 ( V_2 -> V_75 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_58 ( V_2 -> V_59 ) ;
F_46 ( V_80 | V_85 , V_2 -> V_67 + V_81 ) ;
F_56 ( V_2 -> V_75 ) ;
}
static void F_59 ( void )
{
F_19 ( V_86 , V_87 , 3 ) ;
F_19 ( V_86 , L_38 , 2 ) ;
}
static int F_60 ( struct V_88 * V_89 )
{
int V_46 , V_90 ;
struct V_91 * V_75 ;
struct V_92 * V_93 = V_89 -> V_12 . V_94 ;
struct V_1 * V_2 ;
struct V_16 * V_9 ;
struct V_95 * V_96 ;
void T_4 * V_67 ;
V_2 = F_61 ( & V_89 -> V_12 , sizeof( struct V_1 ) , V_97 ) ;
if ( V_2 == NULL ) {
F_10 ( & V_89 -> V_12 , L_39 ) ;
return - V_35 ;
}
F_62 ( V_89 , V_2 ) ;
V_2 -> V_12 = & V_89 -> V_12 ;
if ( V_93 ) {
V_2 -> V_33 = V_93 -> V_33 ;
V_2 -> V_73 = V_93 -> V_73 ;
} else if ( V_2 -> V_12 -> V_98 ) {
V_2 -> V_33 = F_63 ( V_2 -> V_12 -> V_98 ,
L_40 , 0 ) ;
if ( V_2 -> V_33 < 0 ) {
F_10 ( & V_89 -> V_12 , L_41 ) ;
return - V_99 ;
}
if ( F_64 ( V_2 -> V_12 -> V_98 ,
L_42 , & V_2 -> V_73 ) ) {
F_10 ( & V_89 -> V_12 , L_43 ) ;
return - V_99 ;
}
} else {
F_10 ( & V_89 -> V_12 , L_44 ) ;
return - V_99 ;
}
V_96 = F_65 ( V_89 , V_100 , 0 ) ;
if ( ! V_96 ) {
F_10 ( & V_89 -> V_12 , L_45 ) ;
return - V_99 ;
}
V_67 = F_66 ( & V_89 -> V_12 , V_96 ) ;
if ( ! V_67 ) {
F_10 ( & V_89 -> V_12 , L_46 ) ;
return - V_35 ;
}
V_96 = F_65 ( V_89 , V_101 , 0 ) ;
if ( ! V_96 ) {
F_10 ( & V_89 -> V_12 , L_47 ) ;
return - V_99 ;
}
V_75 = F_67 ( L_48 , L_49 ) ;
if ( F_68 ( V_75 ) ) {
F_10 ( V_2 -> V_12 , L_50 ) ;
return - V_99 ;
}
V_2 -> V_67 = V_67 ;
V_2 -> V_59 = V_96 -> V_102 ;
V_2 -> V_75 = V_75 ;
V_2 -> V_54 = & V_2 -> V_22 [ 0 ] ;
F_69 ( & V_2 -> V_6 ) ;
F_70 ( & V_2 -> V_42 ) ;
F_70 ( & V_2 -> V_47 ) ;
F_71 ( & V_2 -> V_40 ) ;
F_72 ( & V_2 -> V_36 ) ;
F_72 ( & V_2 -> V_50 ) ;
F_73 ( & V_2 -> V_51 ) ;
F_73 ( & V_2 -> V_38 ) ;
F_74 ( & V_2 -> V_49 , F_36 ) ;
F_74 ( & V_2 -> V_39 , F_29 ) ;
V_46 = F_75 ( & V_89 -> V_12 , V_2 -> V_33 , V_103 ,
L_51 ) ;
if ( V_46 < 0 ) {
F_10 ( V_2 -> V_12 , L_52 ) ;
return - V_99 ;
}
V_46 = F_76 ( & V_89 -> V_12 , V_2 -> V_59 , F_44 , 0 ,
L_53 , V_2 ) ;
if ( V_46 ) {
F_10 ( V_2 -> V_12 , L_54 ) ;
return - V_99 ;
}
F_58 ( V_2 -> V_59 ) ;
F_50 ( V_2 ) ;
F_51 ( V_75 ) ;
F_19 ( V_2 , V_104 ,
sizeof( V_104 ) ) ;
V_2 -> F_3 . V_105 = F_3 ;
F_1 ( V_2 , & V_2 -> F_3 , 0 ) ;
V_86 = V_2 ;
V_106 = F_59 ;
V_9 = F_24 ( V_2 , V_107 ,
sizeof( V_107 ) ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_12 , L_55 ,
V_9 -> V_8 [ 4 ] , V_9 -> V_8 [ 5 ] , V_9 -> V_8 [ 6 ] , V_9 -> V_8 [ 7 ] ) ;
F_11 ( V_2 , V_9 ) ;
}
V_90 = F_77 ( V_2 -> V_12 , - 1 , V_108 ,
F_78 ( V_108 ) , V_67 , 0 , NULL ) ;
if ( V_90 )
F_10 ( V_2 -> V_12 , L_56 ) ;
F_19 ( V_2 , L_57 , 4 ) ;
F_19 ( V_2 , L_58 , 7 ) ;
F_19 ( V_2 , L_59 , 7 ) ;
return 0 ;
}
static int F_79 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_80 ( V_89 ) ;
F_19 ( V_2 , V_87 , 3 ) ;
F_81 ( V_2 -> V_12 ) ;
F_82 ( & V_2 -> V_49 ) ;
F_82 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_83 ( struct V_109 * V_12 )
{
struct V_88 * V_89 = F_84 ( V_12 ) ;
struct V_1 * V_2 = F_80 ( V_89 ) ;
struct V_16 * V_9 ;
F_16 ( V_2 -> V_12 , L_60 ) ;
V_9 = F_24 ( V_2 , V_87 , 3 ) ;
F_11 ( V_2 , V_9 ) ;
V_9 = F_24 ( V_2 , L_61 , 2 ) ;
F_11 ( V_2 , V_9 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_109 * V_12 )
{
struct V_88 * V_89 = F_84 ( V_12 ) ;
struct V_1 * V_2 = F_80 ( V_89 ) ;
F_16 ( V_2 -> V_12 , L_62 ) ;
F_50 ( V_2 ) ;
F_19 ( V_2 , V_104 , 3 ) ;
return 0 ;
}
