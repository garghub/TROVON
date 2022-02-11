static inline int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
bool V_4 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_8 ) ;
V_7 . V_9 = V_10 ;
if ( ! F_3 ( V_2 -> V_8 ) )
V_7 . V_11 = V_2 -> V_12 << 16 ;
V_7 . V_13 = V_14 | V_15 | V_16 ;
if ( V_4 )
V_7 . V_13 &= ~ V_17 ;
V_5 = F_4 ( V_2 -> V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
if ( V_3 )
* V_3 = V_7 . V_19 [ 0 ] ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 * V_3 )
{
return F_1 ( V_2 , V_3 , false ) ;
}
static int F_6 ( struct V_20 * V_8 , struct V_1 * V_2 )
{
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_8 ) ;
V_7 . V_9 = V_21 ;
if ( V_2 ) {
V_7 . V_11 = V_2 -> V_12 << 16 ;
V_7 . V_13 = V_15 | V_16 ;
} else {
V_7 . V_11 = 0 ;
V_7 . V_13 = V_22 | V_16 ;
}
return F_4 ( V_8 , & V_7 , V_18 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
return F_6 ( V_2 -> V_8 , V_2 ) ;
}
int F_8 ( struct V_20 * V_8 )
{
return F_6 ( V_8 , NULL ) ;
}
int F_9 ( struct V_20 * V_8 )
{
struct V_6 V_7 = { 0 } ;
V_7 . V_9 = V_23 ;
V_7 . V_11 = ( V_8 -> V_24 << 16 ) | 0xffff ;
V_7 . V_13 = V_22 | V_16 ;
return F_4 ( V_8 , & V_7 , V_18 ) ;
}
int F_10 ( struct V_20 * V_8 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
if ( ! F_3 ( V_8 ) ) {
F_11 ( V_8 , V_25 ) ;
F_12 ( 1 ) ;
}
V_7 . V_9 = V_26 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_27 | V_22 | V_28 ;
V_5 = F_4 ( V_8 , & V_7 , 0 ) ;
F_12 ( 1 ) ;
if ( ! F_3 ( V_8 ) ) {
F_11 ( V_8 , V_29 ) ;
F_12 ( 1 ) ;
}
V_8 -> V_30 = 0 ;
return V_5 ;
}
int F_13 ( struct V_20 * V_8 , T_1 V_31 , T_1 * V_32 )
{
struct V_6 V_7 = { 0 } ;
int V_33 , V_5 = 0 ;
F_2 ( ! V_8 ) ;
V_7 . V_9 = V_34 ;
V_7 . V_11 = F_3 ( V_8 ) ? 0 : V_31 ;
V_7 . V_13 = V_27 | V_35 | V_36 ;
for ( V_33 = 100 ; V_33 ; V_33 -- ) {
V_5 = F_4 ( V_8 , & V_7 , 0 ) ;
if ( V_5 )
break;
if ( V_31 == 0 )
break;
if ( F_3 ( V_8 ) ) {
if ( ! ( V_7 . V_19 [ 0 ] & V_37 ) )
break;
} else {
if ( V_7 . V_19 [ 0 ] & V_38 )
break;
}
V_5 = - V_39 ;
F_12 ( 10 ) ;
}
if ( V_32 && ! F_3 ( V_8 ) )
* V_32 = V_7 . V_19 [ 0 ] ;
return V_5 ;
}
int F_14 ( struct V_20 * V_8 , T_1 * V_40 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_8 ) ;
F_2 ( ! V_40 ) ;
V_7 . V_9 = V_41 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_42 | V_36 ;
V_5 = F_4 ( V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_40 , V_7 . V_19 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_8 ) ;
V_7 . V_9 = V_43 ;
V_7 . V_11 = V_2 -> V_12 << 16 ;
V_7 . V_13 = V_15 | V_16 ;
return F_4 ( V_2 -> V_8 , & V_7 , V_18 ) ;
}
static int
F_16 ( struct V_20 * V_8 , T_1 V_11 , T_1 * V_44 , int V_9 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_8 ) ;
F_2 ( ! V_44 ) ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = V_11 ;
V_7 . V_13 = V_42 | V_16 ;
V_5 = F_4 ( V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_44 , V_7 . V_19 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_20 * V_8 ,
T_1 V_9 , void * V_45 , unsigned V_46 )
{
struct V_47 V_48 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_27 | V_15 | V_53 ;
V_50 . V_54 = V_46 ;
V_50 . V_55 = 1 ;
V_50 . V_13 = V_56 ;
V_50 . V_52 = & V_52 ;
V_50 . V_57 = 1 ;
F_18 ( & V_52 , V_45 , V_46 ) ;
if ( V_9 == V_58 || V_9 == V_59 ) {
V_50 . V_60 = 0 ;
V_50 . V_61 = 64 ;
} else
F_19 ( & V_50 , V_2 ) ;
F_20 ( V_8 , & V_48 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_50 . error )
return V_50 . error ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , T_1 * V_62 )
{
int V_63 , V_33 ;
T_1 * V_64 ;
if ( ! F_3 ( V_2 -> V_8 ) )
return F_16 ( V_2 -> V_8 , V_2 -> V_12 << 16 ,
V_62 , V_58 ) ;
V_64 = F_22 ( 16 , V_65 ) ;
if ( ! V_64 )
return - V_66 ;
V_63 = F_17 ( V_2 , V_2 -> V_8 , V_58 , V_64 , 16 ) ;
if ( V_63 )
goto V_5;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_62 [ V_33 ] = F_23 ( V_64 [ V_33 ] ) ;
V_5:
F_24 ( V_64 ) ;
return V_63 ;
}
int F_25 ( struct V_20 * V_8 , T_1 * V_40 )
{
int V_63 , V_33 ;
T_1 * V_67 ;
if ( ! F_3 ( V_8 ) ) {
if ( ! V_8 -> V_2 )
return - V_68 ;
return F_16 ( V_8 , V_8 -> V_2 -> V_12 << 16 ,
V_40 , V_59 ) ;
}
V_67 = F_22 ( 16 , V_65 ) ;
if ( ! V_67 )
return - V_66 ;
V_63 = F_17 ( NULL , V_8 , V_59 , V_67 , 16 ) ;
if ( V_63 )
goto V_5;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_40 [ V_33 ] = F_23 ( V_67 [ V_33 ] ) ;
V_5:
F_24 ( V_67 ) ;
return V_63 ;
}
int F_26 ( struct V_1 * V_2 , T_2 * * V_69 )
{
int V_5 ;
T_2 * V_70 ;
if ( ! V_2 || ! V_69 )
return - V_68 ;
if ( ! F_27 ( V_2 ) )
return - V_71 ;
V_70 = F_22 ( 512 , V_65 ) ;
if ( ! V_70 )
return - V_66 ;
V_5 = F_17 ( V_2 , V_2 -> V_8 , V_72 , V_70 ,
512 ) ;
if ( V_5 )
F_24 ( V_70 ) ;
else
* V_69 = V_70 ;
return V_5 ;
}
int F_28 ( struct V_20 * V_8 , int V_73 , T_1 * V_74 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_9 = V_75 ;
V_7 . V_11 = V_73 ? ( 1 << 30 ) : 0 ;
V_7 . V_13 = V_76 ;
V_5 = F_4 ( V_8 , & V_7 , 0 ) ;
* V_74 = V_7 . V_19 [ 1 ] ;
return V_5 ;
}
int F_29 ( struct V_20 * V_8 , int V_77 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_9 = V_78 ;
V_7 . V_13 = V_27 ;
V_7 . V_11 = V_77 ;
V_5 = F_4 ( V_8 , & V_7 , 0 ) ;
if ( ! V_5 )
V_8 -> V_30 = V_77 ;
return V_5 ;
}
int F_30 ( struct V_20 * V_8 , T_1 V_3 )
{
if ( F_3 ( V_8 ) ) {
if ( V_3 & V_79 )
return - V_80 ;
} else {
if ( V_3 & 0xFDFFA000 )
F_31 ( L_1 ,
F_32 ( V_8 ) , V_3 ) ;
if ( V_3 & V_81 )
return - V_80 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_82 , T_2 V_83 , T_2 V_84 ,
unsigned int V_85 , bool V_86 , bool V_87 ,
bool V_4 )
{
struct V_20 * V_8 = V_2 -> V_8 ;
int V_5 ;
struct V_6 V_7 = { 0 } ;
unsigned long V_88 ;
T_1 V_3 = 0 ;
bool V_89 = V_86 ;
bool V_90 = false ;
F_34 ( V_8 ) ;
if ( V_85 && V_8 -> V_91 &&
( V_85 > V_8 -> V_91 ) )
V_89 = false ;
V_7 . V_9 = V_92 ;
V_7 . V_11 = ( V_93 << 24 ) |
( V_83 << 16 ) |
( V_84 << 8 ) |
V_82 ;
V_7 . V_13 = V_16 ;
if ( V_89 ) {
V_7 . V_13 |= V_94 | V_95 ;
V_7 . V_96 = V_85 ;
} else {
V_7 . V_13 |= V_27 | V_15 ;
}
if ( V_83 == V_97 )
V_7 . V_98 = true ;
V_5 = F_4 ( V_8 , & V_7 , V_18 ) ;
if ( V_5 )
goto V_99;
if ( ! V_86 )
goto V_99;
if ( ( V_8 -> V_100 & V_101 ) && V_89 )
V_4 = false ;
if ( ! V_85 )
V_85 = V_102 ;
V_88 = V_103 + F_35 ( V_85 ) ;
do {
if ( V_87 ) {
V_90 = F_36 ( V_103 , V_88 ) ;
V_5 = F_1 ( V_2 , & V_3 , V_4 ) ;
if ( V_5 )
goto V_99;
}
if ( ( V_8 -> V_100 & V_101 ) && V_89 )
break;
if ( F_3 ( V_8 ) )
break;
if ( ! V_87 ) {
F_12 ( V_85 ) ;
goto V_99;
}
if ( V_90 && F_37 ( V_3 ) == V_104 ) {
F_38 ( L_2 ,
F_32 ( V_8 ) , V_105 ) ;
V_5 = - V_39 ;
goto V_99;
}
} while ( F_37 ( V_3 ) == V_104 );
V_5 = F_30 ( V_8 , V_3 ) ;
V_99:
F_39 ( V_8 ) ;
return V_5 ;
}
int F_40 ( struct V_1 * V_2 , T_2 V_82 , T_2 V_83 , T_2 V_84 ,
unsigned int V_85 )
{
return F_33 ( V_2 , V_82 , V_83 , V_84 , V_85 , true , true ,
false ) ;
}
int F_41 ( struct V_20 * V_8 , T_1 V_9 , int * V_106 )
{
struct V_47 V_48 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
struct V_107 * V_108 = & V_8 -> V_108 ;
const T_2 * V_109 ;
int V_110 , V_5 = 0 ;
T_2 * V_111 ;
if ( V_108 -> V_112 == V_113 ) {
V_109 = V_114 ;
V_110 = sizeof( V_114 ) ;
} else if ( V_108 -> V_112 == V_115 ) {
V_109 = V_116 ;
V_110 = sizeof( V_116 ) ;
} else
return - V_68 ;
V_111 = F_22 ( V_110 , V_65 ) ;
if ( ! V_111 )
return - V_66 ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_9 = V_9 ;
V_7 . V_13 = V_15 | V_53 ;
V_50 . V_54 = V_110 ;
V_50 . V_55 = 1 ;
V_50 . V_13 = V_56 ;
V_50 . V_60 = 150 * V_117 ;
V_50 . V_52 = & V_52 ;
V_50 . V_57 = 1 ;
F_18 ( & V_52 , V_111 , V_110 ) ;
F_20 ( V_8 , & V_48 ) ;
if ( V_106 )
* V_106 = V_7 . error ;
if ( V_7 . error ) {
V_5 = V_7 . error ;
goto V_99;
}
if ( V_50 . error ) {
V_5 = V_50 . error ;
goto V_99;
}
if ( memcmp ( V_111 , V_109 , V_110 ) )
V_5 = - V_118 ;
V_99:
F_24 ( V_111 ) ;
return V_5 ;
}
static int
F_42 ( struct V_1 * V_2 , struct V_20 * V_8 , T_2 V_9 ,
T_2 V_46 )
{
struct V_47 V_48 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
T_2 * V_111 ;
T_2 * V_119 ;
int V_33 , V_5 ;
static T_2 V_120 [ 8 ] = { 0x55 , 0xaa , 0 , 0 , 0 , 0 , 0 , 0 } ;
static T_2 V_121 [ 4 ] = { 0x5a , 0 , 0 , 0 } ;
V_111 = F_43 ( V_46 , V_65 ) ;
if ( ! V_111 )
return - V_66 ;
if ( V_46 == 8 )
V_119 = V_120 ;
else if ( V_46 == 4 )
V_119 = V_121 ;
else {
F_38 ( L_3 ,
F_32 ( V_8 ) , V_46 ) ;
F_24 ( V_111 ) ;
return - V_68 ;
}
if ( V_9 == V_122 )
memcpy ( V_111 , V_119 , V_46 ) ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_27 | V_15 | V_53 ;
V_50 . V_54 = V_46 ;
V_50 . V_55 = 1 ;
if ( V_9 == V_123 )
V_50 . V_13 = V_56 ;
else
V_50 . V_13 = V_124 ;
V_50 . V_52 = & V_52 ;
V_50 . V_57 = 1 ;
F_19 ( & V_50 , V_2 ) ;
F_18 ( & V_52 , V_111 , V_46 ) ;
F_20 ( V_8 , & V_48 ) ;
V_5 = 0 ;
if ( V_9 == V_123 ) {
for ( V_33 = 0 ; V_33 < V_46 / 4 ; V_33 ++ )
if ( ( V_119 [ V_33 ] ^ V_111 [ V_33 ] ) != 0xff ) {
V_5 = - V_118 ;
break;
}
}
F_24 ( V_111 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_50 . error )
return V_50 . error ;
return V_5 ;
}
int F_44 ( struct V_1 * V_2 , T_2 V_112 )
{
int V_125 ;
if ( V_112 == V_113 )
V_125 = 8 ;
else if ( V_112 == V_115 )
V_125 = 4 ;
else if ( V_112 == V_126 )
return 0 ;
else
return - V_68 ;
F_42 ( V_2 , V_2 -> V_8 , V_122 , V_125 ) ;
return F_42 ( V_2 , V_2 -> V_8 , V_123 , V_125 ) ;
}
int F_45 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_6 V_7 = { 0 } ;
unsigned int V_9 ;
int V_5 ;
if ( ! V_2 -> V_70 . V_127 ) {
F_31 ( L_4 ,
F_32 ( V_2 -> V_8 ) ) ;
return - V_68 ;
}
V_9 = V_2 -> V_70 . V_128 ;
if ( V_9 == V_129 )
V_7 . V_13 = V_95 | V_16 ;
else if ( V_9 == V_10 )
V_7 . V_13 = V_15 | V_16 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = V_2 -> V_12 << 16 | 1 ;
V_5 = F_4 ( V_2 -> V_8 , & V_7 , 0 ) ;
if ( V_5 ) {
F_31 ( L_5
L_6 , F_32 ( V_2 -> V_8 ) ,
V_5 , V_7 . V_19 [ 0 ] ) ;
return V_5 ;
}
if ( V_3 )
* V_3 = V_7 . V_19 [ 0 ] ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
return ( V_2 && V_2 -> V_62 . V_130 > V_131 ) ;
}
