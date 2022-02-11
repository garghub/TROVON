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
V_53 = F_17 ( V_46 , V_54 ) ;
if ( V_53 == NULL )
return - V_55 ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_26 | V_13 | V_56 ;
V_50 . V_57 = V_46 ;
V_50 . V_58 = 1 ;
V_50 . V_12 = V_59 ;
V_50 . V_52 = & V_52 ;
V_50 . V_60 = 1 ;
F_18 ( & V_52 , V_53 , V_46 ) ;
if ( V_8 == V_61 || V_8 == V_62 ) {
V_50 . V_63 = 0 ;
V_50 . V_64 = 64 ;
} else
F_19 ( & V_50 , V_4 ) ;
F_20 ( V_2 , & V_48 ) ;
memcpy ( V_45 , V_53 , V_46 ) ;
F_21 ( V_53 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_50 . error )
return V_50 . error ;
return 0 ;
}
int F_22 ( struct V_3 * V_4 , T_1 * V_65 )
{
int V_66 , V_32 ;
if ( ! F_10 ( V_4 -> V_2 ) )
return F_15 ( V_4 -> V_2 , V_4 -> V_11 << 16 ,
V_65 , V_61 ) ;
V_66 = F_16 ( V_4 , V_4 -> V_2 , V_61 , V_65 , 16 ) ;
if ( V_66 )
return V_66 ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
V_65 [ V_32 ] = F_23 ( V_65 [ V_32 ] ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , T_1 * V_40 )
{
int V_66 , V_32 ;
if ( ! F_10 ( V_2 ) ) {
if ( ! V_2 -> V_4 )
return - V_67 ;
return F_15 ( V_2 , V_2 -> V_4 -> V_11 << 16 ,
V_40 , V_62 ) ;
}
V_66 = F_16 ( NULL , V_2 , V_62 , V_40 , 16 ) ;
if ( V_66 )
return V_66 ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
V_40 [ V_32 ] = F_23 ( V_40 [ V_32 ] ) ;
return 0 ;
}
int F_25 ( struct V_3 * V_4 , T_2 * V_22 )
{
return F_16 ( V_4 , V_4 -> V_2 , V_68 ,
V_22 , 512 ) ;
}
int F_26 ( struct V_1 * V_2 , int V_69 , T_1 * V_70 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_8 = V_71 ;
V_7 . V_10 = V_69 ? ( 1 << 30 ) : 0 ;
V_7 . V_12 = V_72 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
* V_70 = V_7 . V_36 [ 1 ] ;
return V_5 ;
}
int F_27 ( struct V_1 * V_2 , int V_73 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_8 = V_74 ;
V_7 . V_12 = V_26 ;
V_7 . V_10 = V_73 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
if ( ! V_5 )
V_2 -> V_29 = V_73 ;
return V_5 ;
}
int F_28 ( struct V_3 * V_4 , T_2 V_75 , T_2 V_76 , T_2 V_77 ,
unsigned int V_78 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
T_1 V_79 ;
F_2 ( ! V_4 ) ;
F_2 ( ! V_4 -> V_2 ) ;
V_7 . V_8 = V_80 ;
V_7 . V_10 = ( V_81 << 24 ) |
( V_76 << 16 ) |
( V_77 << 8 ) |
V_75 ;
V_7 . V_12 = V_82 | V_19 | V_14 ;
V_7 . V_83 = V_78 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
do {
V_5 = F_29 ( V_4 , & V_79 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 -> V_2 -> V_20 & V_21 )
break;
if ( F_10 ( V_4 -> V_2 ) )
break;
} while ( F_30 ( V_79 ) == V_84 );
if ( F_10 ( V_4 -> V_2 ) ) {
if ( V_79 & V_85 )
return - V_86 ;
} else {
if ( V_79 & 0xFDFFA000 )
F_31 ( L_1
L_2 , F_32 ( V_4 -> V_2 ) , V_79 ) ;
if ( V_79 & V_87 )
return - V_86 ;
}
return 0 ;
}
int F_29 ( struct V_3 * V_4 , T_1 * V_79 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_4 ) ;
F_2 ( ! V_4 -> V_2 ) ;
V_7 . V_8 = V_88 ;
if ( ! F_10 ( V_4 -> V_2 ) )
V_7 . V_10 = V_4 -> V_11 << 16 ;
V_7 . V_12 = V_89 | V_13 | V_14 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
if ( V_79 )
* V_79 = V_7 . V_36 [ 0 ] ;
return 0 ;
}
static int
F_33 ( struct V_3 * V_4 , struct V_1 * V_2 , T_2 V_8 ,
T_2 V_46 )
{
struct V_47 V_48 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
T_2 * V_53 ;
T_2 * V_90 ;
int V_32 , V_5 ;
static T_2 V_91 [ 8 ] = { 0x55 , 0xaa , 0 , 0 , 0 , 0 , 0 , 0 } ;
static T_2 V_92 [ 4 ] = { 0x5a , 0 , 0 , 0 } ;
V_53 = F_17 ( V_46 , V_54 ) ;
if ( ! V_53 )
return - V_55 ;
if ( V_46 == 8 )
V_90 = V_91 ;
else if ( V_46 == 4 )
V_90 = V_92 ;
else {
F_34 ( L_3 ,
F_32 ( V_2 ) , V_46 ) ;
F_21 ( V_53 ) ;
return - V_67 ;
}
if ( V_8 == V_93 )
memcpy ( V_53 , V_90 , V_46 ) ;
V_48 . V_7 = & V_7 ;
V_48 . V_50 = & V_50 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_26 | V_13 | V_56 ;
V_50 . V_57 = V_46 ;
V_50 . V_58 = 1 ;
if ( V_8 == V_94 )
V_50 . V_12 = V_59 ;
else
V_50 . V_12 = V_95 ;
V_50 . V_52 = & V_52 ;
V_50 . V_60 = 1 ;
F_18 ( & V_52 , V_53 , V_46 ) ;
F_20 ( V_2 , & V_48 ) ;
V_5 = 0 ;
if ( V_8 == V_94 ) {
for ( V_32 = 0 ; V_32 < V_46 / 4 ; V_32 ++ )
if ( ( V_90 [ V_32 ] ^ V_53 [ V_32 ] ) != 0xff ) {
V_5 = - V_96 ;
break;
}
}
F_21 ( V_53 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_50 . error )
return V_50 . error ;
return V_5 ;
}
int F_35 ( struct V_3 * V_4 , T_2 V_97 )
{
int V_5 , V_98 ;
if ( V_97 == V_99 )
V_98 = 8 ;
else if ( V_97 == V_100 )
V_98 = 4 ;
else if ( V_97 == V_101 )
return 0 ;
else
return - V_67 ;
F_33 ( V_4 , V_4 -> V_2 , V_93 , V_98 ) ;
V_5 = F_33 ( V_4 , V_4 -> V_2 , V_94 , V_98 ) ;
return V_5 ;
}
int F_36 ( struct V_3 * V_4 , T_1 * V_79 )
{
struct V_6 V_7 = { 0 } ;
unsigned int V_8 ;
int V_5 ;
if ( ! V_4 -> V_22 . V_102 ) {
F_31 ( L_4 ,
F_32 ( V_4 -> V_2 ) ) ;
return - V_67 ;
}
V_8 = V_4 -> V_22 . V_103 ;
if ( V_8 == V_104 )
V_7 . V_12 = V_19 | V_14 ;
else if ( V_8 == V_88 )
V_7 . V_12 = V_13 | V_14 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = V_4 -> V_11 << 16 | 1 ;
V_7 . V_83 = V_4 -> V_22 . V_105 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , 0 ) ;
if ( V_5 ) {
F_37 ( L_5
L_6 , F_32 ( V_4 -> V_2 ) ,
V_5 , V_7 . V_36 [ 0 ] ) ;
return V_5 ;
}
if ( V_79 )
* V_79 = V_7 . V_36 [ 0 ] ;
return 0 ;
}
