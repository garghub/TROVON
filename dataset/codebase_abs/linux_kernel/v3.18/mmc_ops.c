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
int V_5 ;
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
V_5 = F_4 ( V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
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
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_8 ) ;
V_7 . V_9 = V_43 ;
V_7 . V_11 = V_2 -> V_12 << 16 ;
V_7 . V_13 = V_15 | V_16 ;
V_5 = F_4 ( V_2 -> V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
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
void * V_53 ;
int V_54 ;
V_54 = F_18 ( V_45 ) ;
if ( V_54 ) {
V_53 = F_19 ( V_46 , V_55 ) ;
if ( ! V_53 )
return - V_56 ;
} else
V_53 = V_45 ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_27 | V_15 | V_57 ;
V_50 . V_58 = V_46 ;
V_50 . V_59 = 1 ;
V_50 . V_13 = V_60 ;
V_50 . V_52 = & V_52 ;
V_50 . V_61 = 1 ;
F_20 ( & V_52 , V_53 , V_46 ) ;
if ( V_9 == V_62 || V_9 == V_63 ) {
V_50 . V_64 = 0 ;
V_50 . V_65 = 64 ;
} else
F_21 ( & V_50 , V_2 ) ;
F_22 ( V_8 , & V_48 ) ;
if ( V_54 ) {
memcpy ( V_45 , V_53 , V_46 ) ;
F_23 ( V_53 ) ;
}
if ( V_7 . error )
return V_7 . error ;
if ( V_50 . error )
return V_50 . error ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , T_1 * V_66 )
{
int V_67 , V_33 ;
T_1 * V_68 ;
if ( ! F_3 ( V_2 -> V_8 ) )
return F_16 ( V_2 -> V_8 , V_2 -> V_12 << 16 ,
V_66 , V_62 ) ;
V_68 = F_19 ( 16 , V_55 ) ;
if ( ! V_68 )
return - V_56 ;
V_67 = F_17 ( V_2 , V_2 -> V_8 , V_62 , V_68 , 16 ) ;
if ( V_67 )
goto V_5;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_66 [ V_33 ] = F_25 ( V_68 [ V_33 ] ) ;
V_5:
F_23 ( V_68 ) ;
return V_67 ;
}
int F_26 ( struct V_20 * V_8 , T_1 * V_40 )
{
int V_67 , V_33 ;
T_1 * V_69 ;
if ( ! F_3 ( V_8 ) ) {
if ( ! V_8 -> V_2 )
return - V_70 ;
return F_16 ( V_8 , V_8 -> V_2 -> V_12 << 16 ,
V_40 , V_63 ) ;
}
V_69 = F_19 ( 16 , V_55 ) ;
if ( ! V_69 )
return - V_56 ;
V_67 = F_17 ( NULL , V_8 , V_63 , V_69 , 16 ) ;
if ( V_67 )
goto V_5;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_40 [ V_33 ] = F_25 ( V_69 [ V_33 ] ) ;
V_5:
F_23 ( V_69 ) ;
return V_67 ;
}
int F_27 ( struct V_1 * V_2 , T_2 * V_71 )
{
return F_17 ( V_2 , V_2 -> V_8 , V_72 ,
V_71 , 512 ) ;
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
int F_30 ( struct V_1 * V_2 , T_2 V_79 , T_2 V_80 , T_2 V_81 ,
unsigned int V_82 , bool V_83 , bool V_84 ,
bool V_4 )
{
struct V_20 * V_8 = V_2 -> V_8 ;
int V_5 ;
struct V_6 V_7 = { 0 } ;
unsigned long V_85 ;
T_1 V_3 = 0 ;
bool V_86 = V_83 ;
if ( V_82 && V_8 -> V_87 &&
( V_82 > V_8 -> V_87 ) )
V_86 = false ;
V_7 . V_9 = V_88 ;
V_7 . V_11 = ( V_89 << 24 ) |
( V_80 << 16 ) |
( V_81 << 8 ) |
V_79 ;
V_7 . V_13 = V_16 ;
if ( V_86 ) {
V_7 . V_13 |= V_90 | V_91 ;
V_7 . V_92 = V_82 ;
} else {
V_7 . V_13 |= V_27 | V_15 ;
}
if ( V_80 == V_93 )
V_7 . V_94 = true ;
V_5 = F_4 ( V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_83 )
return 0 ;
if ( ( V_8 -> V_95 & V_96 ) && V_86 )
V_4 = false ;
if ( ! V_82 )
V_82 = V_97 ;
V_85 = V_98 + F_31 ( V_82 ) ;
do {
if ( V_84 ) {
V_5 = F_1 ( V_2 , & V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
}
if ( ( V_8 -> V_95 & V_96 ) && V_86 )
break;
if ( F_3 ( V_8 ) )
break;
if ( ! V_84 ) {
F_12 ( V_82 ) ;
return 0 ;
}
if ( F_32 ( V_98 , V_85 ) ) {
F_33 ( L_1 ,
F_34 ( V_8 ) , V_99 ) ;
return - V_39 ;
}
} while ( F_35 ( V_3 ) == V_100 );
if ( F_3 ( V_8 ) ) {
if ( V_3 & V_101 )
return - V_102 ;
} else {
if ( V_3 & 0xFDFFA000 )
F_36 ( L_2 ,
F_34 ( V_8 ) , V_3 ) ;
if ( V_3 & V_103 )
return - V_102 ;
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 , T_2 V_79 , T_2 V_80 , T_2 V_81 ,
unsigned int V_82 )
{
return F_30 ( V_2 , V_79 , V_80 , V_81 , V_82 , true , true ,
false ) ;
}
static int
F_38 ( struct V_1 * V_2 , struct V_20 * V_8 , T_2 V_9 ,
T_2 V_46 )
{
struct V_47 V_48 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
T_2 * V_53 ;
T_2 * V_104 ;
int V_33 , V_5 ;
static T_2 V_105 [ 8 ] = { 0x55 , 0xaa , 0 , 0 , 0 , 0 , 0 , 0 } ;
static T_2 V_106 [ 4 ] = { 0x5a , 0 , 0 , 0 } ;
V_53 = F_19 ( V_46 , V_55 ) ;
if ( ! V_53 )
return - V_56 ;
if ( V_46 == 8 )
V_104 = V_105 ;
else if ( V_46 == 4 )
V_104 = V_106 ;
else {
F_33 ( L_3 ,
F_34 ( V_8 ) , V_46 ) ;
F_23 ( V_53 ) ;
return - V_70 ;
}
if ( V_9 == V_107 )
memcpy ( V_53 , V_104 , V_46 ) ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_27 | V_15 | V_57 ;
V_50 . V_58 = V_46 ;
V_50 . V_59 = 1 ;
if ( V_9 == V_108 )
V_50 . V_13 = V_60 ;
else
V_50 . V_13 = V_109 ;
V_50 . V_52 = & V_52 ;
V_50 . V_61 = 1 ;
F_21 ( & V_50 , V_2 ) ;
F_20 ( & V_52 , V_53 , V_46 ) ;
F_22 ( V_8 , & V_48 ) ;
V_5 = 0 ;
if ( V_9 == V_108 ) {
for ( V_33 = 0 ; V_33 < V_46 / 4 ; V_33 ++ )
if ( ( V_104 [ V_33 ] ^ V_53 [ V_33 ] ) != 0xff ) {
V_5 = - V_110 ;
break;
}
}
F_23 ( V_53 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_50 . error )
return V_50 . error ;
return V_5 ;
}
int F_39 ( struct V_1 * V_2 , T_2 V_111 )
{
int V_5 , V_112 ;
if ( V_111 == V_113 )
V_112 = 8 ;
else if ( V_111 == V_114 )
V_112 = 4 ;
else if ( V_111 == V_115 )
return 0 ;
else
return - V_70 ;
F_38 ( V_2 , V_2 -> V_8 , V_107 , V_112 ) ;
V_5 = F_38 ( V_2 , V_2 -> V_8 , V_108 , V_112 ) ;
return V_5 ;
}
int F_40 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_6 V_7 = { 0 } ;
unsigned int V_9 ;
int V_5 ;
if ( ! V_2 -> V_71 . V_116 ) {
F_36 ( L_4 ,
F_34 ( V_2 -> V_8 ) ) ;
return - V_70 ;
}
V_9 = V_2 -> V_71 . V_117 ;
if ( V_9 == V_118 )
V_7 . V_13 = V_91 | V_16 ;
else if ( V_9 == V_10 )
V_7 . V_13 = V_15 | V_16 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = V_2 -> V_12 << 16 | 1 ;
V_5 = F_4 ( V_2 -> V_8 , & V_7 , 0 ) ;
if ( V_5 ) {
F_36 ( L_5
L_6 , F_34 ( V_2 -> V_8 ) ,
V_5 , V_7 . V_19 [ 0 ] ) ;
return V_5 ;
}
if ( V_3 )
* V_3 = V_7 . V_19 [ 0 ] ;
return 0 ;
}
