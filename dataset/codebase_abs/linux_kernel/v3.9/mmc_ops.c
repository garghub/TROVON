static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
V_7 . V_8 = V_9 ;
if ( V_4 ) {
V_7 . V_10 = V_4 -> V_11 << 16 ;
V_7 . V_12 = V_13 | V_14 ;
} else {
V_7 . V_10 = 0 ;
V_7 . V_12 = V_15 | V_14 ;
}
V_5 = F_3 ( V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
int F_4 ( struct V_3 * V_4 )
{
F_2 ( ! V_4 ) ;
return F_1 ( V_4 -> V_2 , V_4 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , NULL ) ;
}
int F_6 ( struct V_1 * V_2 , int V_17 )
{
struct V_6 V_7 = { 0 } ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
if ( V_17 )
F_5 ( V_2 ) ;
V_7 . V_8 = V_18 ;
V_7 . V_10 = V_4 -> V_11 << 16 ;
if ( V_17 )
V_7 . V_10 |= 1 << 15 ;
V_7 . V_12 = V_19 | V_14 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_2 -> V_20 & V_21 ) )
F_7 ( F_8 ( V_4 -> V_22 . V_23 , 10000 ) ) ;
if ( ! V_17 )
V_5 = F_4 ( V_4 ) ;
return V_5 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
if ( ! F_10 ( V_2 ) ) {
F_11 ( V_2 , V_24 ) ;
F_7 ( 1 ) ;
}
V_7 . V_8 = V_25 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_26 | V_15 | V_27 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
F_7 ( 1 ) ;
if ( ! F_10 ( V_2 ) ) {
F_11 ( V_2 , V_28 ) ;
F_7 ( 1 ) ;
}
V_2 -> V_29 = 0 ;
return V_5 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_30 , T_1 * V_31 )
{
struct V_6 V_7 = { 0 } ;
int V_32 , V_5 = 0 ;
F_2 ( ! V_2 ) ;
V_7 . V_8 = V_33 ;
V_7 . V_10 = F_10 ( V_2 ) ? 0 : V_30 ;
V_7 . V_12 = V_26 | V_34 | V_35 ;
for ( V_32 = 100 ; V_32 ; V_32 -- ) {
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
if ( V_5 )
break;
if ( V_30 == 0 )
break;
if ( F_10 ( V_2 ) ) {
if ( ! ( V_7 . V_36 [ 0 ] & V_37 ) )
break;
} else {
if ( V_7 . V_36 [ 0 ] & V_38 )
break;
}
V_5 = - V_39 ;
F_7 ( 10 ) ;
}
if ( V_31 && ! F_10 ( V_2 ) )
* V_31 = V_7 . V_36 [ 0 ] ;
return V_5 ;
}
int F_13 ( struct V_1 * V_2 , T_1 * V_40 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_40 ) ;
V_7 . V_8 = V_41 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_42 | V_35 ;
V_5 = F_3 ( V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_40 , V_7 . V_36 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_4 ) ;
F_2 ( ! V_4 -> V_2 ) ;
V_7 . V_8 = V_43 ;
V_7 . V_10 = V_4 -> V_11 << 16 ;
V_7 . V_12 = V_13 | V_14 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , T_1 V_10 , T_1 * V_44 , int V_8 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_44 ) ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = V_10 ;
V_7 . V_12 = V_42 | V_14 ;
V_5 = F_3 ( V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_44 , V_7 . V_36 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int
F_16 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_1 V_8 , void * V_45 , unsigned V_46 )
{
struct V_47 V_48 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
void * V_53 ;
int V_54 ;
V_54 = F_17 ( V_45 ) ;
if ( V_54 ) {
V_53 = F_18 ( V_46 , V_55 ) ;
if ( ! V_53 )
return - V_56 ;
} else
V_53 = V_45 ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_26 | V_13 | V_57 ;
V_50 . V_58 = V_46 ;
V_50 . V_59 = 1 ;
V_50 . V_12 = V_60 ;
V_50 . V_52 = & V_52 ;
V_50 . V_61 = 1 ;
F_19 ( & V_52 , V_53 , V_46 ) ;
if ( V_8 == V_62 || V_8 == V_63 ) {
V_50 . V_64 = 0 ;
V_50 . V_65 = 64 ;
} else
F_20 ( & V_50 , V_4 ) ;
F_21 ( V_2 , & V_48 ) ;
if ( V_54 ) {
memcpy ( V_45 , V_53 , V_46 ) ;
F_22 ( V_53 ) ;
}
if ( V_7 . error )
return V_7 . error ;
if ( V_50 . error )
return V_50 . error ;
return 0 ;
}
int F_23 ( struct V_3 * V_4 , T_1 * V_66 )
{
int V_67 , V_32 ;
T_1 * V_68 ;
if ( ! F_10 ( V_4 -> V_2 ) )
return F_15 ( V_4 -> V_2 , V_4 -> V_11 << 16 ,
V_66 , V_62 ) ;
V_68 = F_18 ( 16 , V_55 ) ;
if ( ! V_68 )
return - V_56 ;
V_67 = F_16 ( V_4 , V_4 -> V_2 , V_62 , V_68 , 16 ) ;
if ( V_67 )
goto V_5;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
V_66 [ V_32 ] = F_24 ( V_68 [ V_32 ] ) ;
V_5:
F_22 ( V_68 ) ;
return V_67 ;
}
int F_25 ( struct V_1 * V_2 , T_1 * V_40 )
{
int V_67 , V_32 ;
T_1 * V_69 ;
if ( ! F_10 ( V_2 ) ) {
if ( ! V_2 -> V_4 )
return - V_70 ;
return F_15 ( V_2 , V_2 -> V_4 -> V_11 << 16 ,
V_40 , V_63 ) ;
}
V_69 = F_18 ( 16 , V_55 ) ;
if ( ! V_69 )
return - V_56 ;
V_67 = F_16 ( NULL , V_2 , V_63 , V_69 , 16 ) ;
if ( V_67 )
goto V_5;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
V_40 [ V_32 ] = F_24 ( V_69 [ V_32 ] ) ;
V_5:
F_22 ( V_69 ) ;
return V_67 ;
}
int F_26 ( struct V_3 * V_4 , T_2 * V_22 )
{
return F_16 ( V_4 , V_4 -> V_2 , V_71 ,
V_22 , 512 ) ;
}
int F_27 ( struct V_1 * V_2 , int V_72 , T_1 * V_73 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_8 = V_74 ;
V_7 . V_10 = V_72 ? ( 1 << 30 ) : 0 ;
V_7 . V_12 = V_75 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
* V_73 = V_7 . V_36 [ 1 ] ;
return V_5 ;
}
int F_28 ( struct V_1 * V_2 , int V_76 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_8 = V_77 ;
V_7 . V_12 = V_26 ;
V_7 . V_10 = V_76 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
if ( ! V_5 )
V_2 -> V_29 = V_76 ;
return V_5 ;
}
int F_29 ( struct V_3 * V_4 , T_2 V_78 , T_2 V_79 , T_2 V_80 ,
unsigned int V_81 , bool V_82 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
unsigned long V_83 ;
T_1 V_84 ;
F_2 ( ! V_4 ) ;
F_2 ( ! V_4 -> V_2 ) ;
V_7 . V_8 = V_85 ;
V_7 . V_10 = ( V_86 << 24 ) |
( V_79 << 16 ) |
( V_80 << 8 ) |
V_78 ;
V_7 . V_12 = V_14 ;
if ( V_82 )
V_7 . V_12 |= V_87 | V_19 ;
else
V_7 . V_12 |= V_26 | V_13 ;
V_7 . V_88 = V_81 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_82 )
return 0 ;
V_83 = V_89 + F_30 ( V_90 ) ;
do {
V_5 = F_31 ( V_4 , & V_84 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 -> V_2 -> V_20 & V_21 )
break;
if ( F_10 ( V_4 -> V_2 ) )
break;
if ( F_32 ( V_89 , V_83 ) ) {
F_33 ( L_1 ,
F_34 ( V_4 -> V_2 ) , V_91 ) ;
return - V_39 ;
}
} while ( F_35 ( V_84 ) == V_92 );
if ( F_10 ( V_4 -> V_2 ) ) {
if ( V_84 & V_93 )
return - V_94 ;
} else {
if ( V_84 & 0xFDFFA000 )
F_36 ( L_2
L_3 , F_34 ( V_4 -> V_2 ) , V_84 ) ;
if ( V_84 & V_95 )
return - V_94 ;
}
return 0 ;
}
int F_37 ( struct V_3 * V_4 , T_2 V_78 , T_2 V_79 , T_2 V_80 ,
unsigned int V_81 )
{
return F_29 ( V_4 , V_78 , V_79 , V_80 , V_81 , true ) ;
}
int F_31 ( struct V_3 * V_4 , T_1 * V_84 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_4 ) ;
F_2 ( ! V_4 -> V_2 ) ;
V_7 . V_8 = V_96 ;
if ( ! F_10 ( V_4 -> V_2 ) )
V_7 . V_10 = V_4 -> V_11 << 16 ;
V_7 . V_12 = V_97 | V_13 | V_14 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
if ( V_84 )
* V_84 = V_7 . V_36 [ 0 ] ;
return 0 ;
}
static int
F_38 ( struct V_3 * V_4 , struct V_1 * V_2 , T_2 V_8 ,
T_2 V_46 )
{
struct V_47 V_48 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
T_2 * V_53 ;
T_2 * V_98 ;
int V_32 , V_5 ;
static T_2 V_99 [ 8 ] = { 0x55 , 0xaa , 0 , 0 , 0 , 0 , 0 , 0 } ;
static T_2 V_100 [ 4 ] = { 0x5a , 0 , 0 , 0 } ;
V_53 = F_18 ( V_46 , V_55 ) ;
if ( ! V_53 )
return - V_56 ;
if ( V_46 == 8 )
V_98 = V_99 ;
else if ( V_46 == 4 )
V_98 = V_100 ;
else {
F_33 ( L_4 ,
F_34 ( V_2 ) , V_46 ) ;
F_22 ( V_53 ) ;
return - V_70 ;
}
if ( V_8 == V_101 )
memcpy ( V_53 , V_98 , V_46 ) ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_26 | V_13 | V_57 ;
V_50 . V_58 = V_46 ;
V_50 . V_59 = 1 ;
if ( V_8 == V_102 )
V_50 . V_12 = V_60 ;
else
V_50 . V_12 = V_103 ;
V_50 . V_52 = & V_52 ;
V_50 . V_61 = 1 ;
F_19 ( & V_52 , V_53 , V_46 ) ;
F_21 ( V_2 , & V_48 ) ;
V_5 = 0 ;
if ( V_8 == V_102 ) {
for ( V_32 = 0 ; V_32 < V_46 / 4 ; V_32 ++ )
if ( ( V_98 [ V_32 ] ^ V_53 [ V_32 ] ) != 0xff ) {
V_5 = - V_104 ;
break;
}
}
F_22 ( V_53 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_50 . error )
return V_50 . error ;
return V_5 ;
}
int F_39 ( struct V_3 * V_4 , T_2 V_105 )
{
int V_5 , V_106 ;
if ( V_105 == V_107 )
V_106 = 8 ;
else if ( V_105 == V_108 )
V_106 = 4 ;
else if ( V_105 == V_109 )
return 0 ;
else
return - V_70 ;
F_38 ( V_4 , V_4 -> V_2 , V_101 , V_106 ) ;
V_5 = F_38 ( V_4 , V_4 -> V_2 , V_102 , V_106 ) ;
return V_5 ;
}
int F_40 ( struct V_3 * V_4 , T_1 * V_84 )
{
struct V_6 V_7 = { 0 } ;
unsigned int V_8 ;
int V_5 ;
if ( ! V_4 -> V_22 . V_110 ) {
F_36 ( L_5 ,
F_34 ( V_4 -> V_2 ) ) ;
return - V_70 ;
}
V_8 = V_4 -> V_22 . V_111 ;
if ( V_8 == V_112 )
V_7 . V_12 = V_19 | V_14 ;
else if ( V_8 == V_96 )
V_7 . V_12 = V_13 | V_14 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = V_4 -> V_11 << 16 | 1 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , 0 ) ;
if ( V_5 ) {
F_41 ( L_6
L_7 , F_34 ( V_4 -> V_2 ) ,
V_5 , V_7 . V_36 [ 0 ] ) ;
return V_5 ;
}
if ( V_84 )
* V_84 = V_7 . V_36 [ 0 ] ;
return 0 ;
}
