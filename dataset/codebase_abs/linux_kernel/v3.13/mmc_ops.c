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
int V_5 ;
struct V_6 V_7 = { 0 } ;
if ( ! F_3 ( V_8 ) ) {
F_10 ( V_8 , V_23 ) ;
F_11 ( 1 ) ;
}
V_7 . V_9 = V_24 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_25 | V_22 | V_26 ;
V_5 = F_4 ( V_8 , & V_7 , 0 ) ;
F_11 ( 1 ) ;
if ( ! F_3 ( V_8 ) ) {
F_10 ( V_8 , V_27 ) ;
F_11 ( 1 ) ;
}
V_8 -> V_28 = 0 ;
return V_5 ;
}
int F_12 ( struct V_20 * V_8 , T_1 V_29 , T_1 * V_30 )
{
struct V_6 V_7 = { 0 } ;
int V_31 , V_5 = 0 ;
F_2 ( ! V_8 ) ;
V_7 . V_9 = V_32 ;
V_7 . V_11 = F_3 ( V_8 ) ? 0 : V_29 ;
V_7 . V_13 = V_25 | V_33 | V_34 ;
for ( V_31 = 100 ; V_31 ; V_31 -- ) {
V_5 = F_4 ( V_8 , & V_7 , 0 ) ;
if ( V_5 )
break;
if ( V_29 == 0 )
break;
if ( F_3 ( V_8 ) ) {
if ( ! ( V_7 . V_19 [ 0 ] & V_35 ) )
break;
} else {
if ( V_7 . V_19 [ 0 ] & V_36 )
break;
}
V_5 = - V_37 ;
F_11 ( 10 ) ;
}
if ( V_30 && ! F_3 ( V_8 ) )
* V_30 = V_7 . V_19 [ 0 ] ;
return V_5 ;
}
int F_13 ( struct V_20 * V_8 , T_1 * V_38 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_8 ) ;
F_2 ( ! V_38 ) ;
V_7 . V_9 = V_39 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_40 | V_34 ;
V_5 = F_4 ( V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_38 , V_7 . V_19 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_8 ) ;
V_7 . V_9 = V_41 ;
V_7 . V_11 = V_2 -> V_12 << 16 ;
V_7 . V_13 = V_15 | V_16 ;
V_5 = F_4 ( V_2 -> V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int
F_15 ( struct V_20 * V_8 , T_1 V_11 , T_1 * V_42 , int V_9 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_8 ) ;
F_2 ( ! V_42 ) ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = V_11 ;
V_7 . V_13 = V_40 | V_16 ;
V_5 = F_4 ( V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_42 , V_7 . V_19 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_20 * V_8 ,
T_1 V_9 , void * V_43 , unsigned V_44 )
{
struct V_45 V_46 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_47 V_48 = { 0 } ;
struct V_49 V_50 ;
void * V_51 ;
int V_52 ;
V_52 = F_17 ( V_43 ) ;
if ( V_52 ) {
V_51 = F_18 ( V_44 , V_53 ) ;
if ( ! V_51 )
return - V_54 ;
} else
V_51 = V_43 ;
V_46 . V_7 = & V_7 ;
V_46 . V_48 = & V_48 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_25 | V_15 | V_55 ;
V_48 . V_56 = V_44 ;
V_48 . V_57 = 1 ;
V_48 . V_13 = V_58 ;
V_48 . V_50 = & V_50 ;
V_48 . V_59 = 1 ;
F_19 ( & V_50 , V_51 , V_44 ) ;
if ( V_9 == V_60 || V_9 == V_61 ) {
V_48 . V_62 = 0 ;
V_48 . V_63 = 64 ;
} else
F_20 ( & V_48 , V_2 ) ;
F_21 ( V_8 , & V_46 ) ;
if ( V_52 ) {
memcpy ( V_43 , V_51 , V_44 ) ;
F_22 ( V_51 ) ;
}
if ( V_7 . error )
return V_7 . error ;
if ( V_48 . error )
return V_48 . error ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , T_1 * V_64 )
{
int V_65 , V_31 ;
T_1 * V_66 ;
if ( ! F_3 ( V_2 -> V_8 ) )
return F_15 ( V_2 -> V_8 , V_2 -> V_12 << 16 ,
V_64 , V_60 ) ;
V_66 = F_18 ( 16 , V_53 ) ;
if ( ! V_66 )
return - V_54 ;
V_65 = F_16 ( V_2 , V_2 -> V_8 , V_60 , V_66 , 16 ) ;
if ( V_65 )
goto V_5;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ )
V_64 [ V_31 ] = F_24 ( V_66 [ V_31 ] ) ;
V_5:
F_22 ( V_66 ) ;
return V_65 ;
}
int F_25 ( struct V_20 * V_8 , T_1 * V_38 )
{
int V_65 , V_31 ;
T_1 * V_67 ;
if ( ! F_3 ( V_8 ) ) {
if ( ! V_8 -> V_2 )
return - V_68 ;
return F_15 ( V_8 , V_8 -> V_2 -> V_12 << 16 ,
V_38 , V_61 ) ;
}
V_67 = F_18 ( 16 , V_53 ) ;
if ( ! V_67 )
return - V_54 ;
V_65 = F_16 ( NULL , V_8 , V_61 , V_67 , 16 ) ;
if ( V_65 )
goto V_5;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ )
V_38 [ V_31 ] = F_24 ( V_67 [ V_31 ] ) ;
V_5:
F_22 ( V_67 ) ;
return V_65 ;
}
int F_26 ( struct V_1 * V_2 , T_2 * V_69 )
{
return F_16 ( V_2 , V_2 -> V_8 , V_70 ,
V_69 , 512 ) ;
}
int F_27 ( struct V_20 * V_8 , int V_71 , T_1 * V_72 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_9 = V_73 ;
V_7 . V_11 = V_71 ? ( 1 << 30 ) : 0 ;
V_7 . V_13 = V_74 ;
V_5 = F_4 ( V_8 , & V_7 , 0 ) ;
* V_72 = V_7 . V_19 [ 1 ] ;
return V_5 ;
}
int F_28 ( struct V_20 * V_8 , int V_75 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_9 = V_76 ;
V_7 . V_13 = V_25 ;
V_7 . V_11 = V_75 ;
V_5 = F_4 ( V_8 , & V_7 , 0 ) ;
if ( ! V_5 )
V_8 -> V_28 = V_75 ;
return V_5 ;
}
int F_29 ( struct V_1 * V_2 , T_2 V_77 , T_2 V_78 , T_2 V_79 ,
unsigned int V_80 , bool V_81 , bool V_82 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
unsigned long V_83 ;
T_1 V_3 = 0 ;
bool V_4 = false ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_8 ) ;
V_7 . V_9 = V_84 ;
V_7 . V_11 = ( V_85 << 24 ) |
( V_78 << 16 ) |
( V_79 << 8 ) |
V_77 ;
V_7 . V_13 = V_16 ;
if ( V_81 )
V_7 . V_13 |= V_86 | V_87 ;
else
V_7 . V_13 |= V_25 | V_15 ;
V_7 . V_88 = V_80 ;
if ( V_78 == V_89 )
V_7 . V_90 = true ;
V_5 = F_4 ( V_2 -> V_8 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_81 )
return 0 ;
if ( V_78 == V_91 &&
! ( V_2 -> V_8 -> V_92 & V_93 ) )
V_4 = true ;
V_83 = V_94 + F_30 ( V_95 ) ;
do {
if ( V_82 ) {
V_5 = F_1 ( V_2 , & V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_2 -> V_8 -> V_92 & V_93 )
break;
if ( F_3 ( V_2 -> V_8 ) )
break;
if ( ! V_82 ) {
F_11 ( V_80 ) ;
return 0 ;
}
if ( F_31 ( V_94 , V_83 ) ) {
F_32 ( L_1 ,
F_33 ( V_2 -> V_8 ) , V_96 ) ;
return - V_37 ;
}
} while ( F_34 ( V_3 ) == V_97 );
if ( F_3 ( V_2 -> V_8 ) ) {
if ( V_3 & V_98 )
return - V_99 ;
} else {
if ( V_3 & 0xFDFFA000 )
F_35 ( L_2
L_3 , F_33 ( V_2 -> V_8 ) , V_3 ) ;
if ( V_3 & V_100 )
return - V_99 ;
}
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_77 , T_2 V_78 , T_2 V_79 ,
unsigned int V_80 )
{
return F_29 ( V_2 , V_77 , V_78 , V_79 , V_80 , true , true ) ;
}
static int
F_37 ( struct V_1 * V_2 , struct V_20 * V_8 , T_2 V_9 ,
T_2 V_44 )
{
struct V_45 V_46 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_47 V_48 = { 0 } ;
struct V_49 V_50 ;
T_2 * V_51 ;
T_2 * V_101 ;
int V_31 , V_5 ;
static T_2 V_102 [ 8 ] = { 0x55 , 0xaa , 0 , 0 , 0 , 0 , 0 , 0 } ;
static T_2 V_103 [ 4 ] = { 0x5a , 0 , 0 , 0 } ;
V_51 = F_18 ( V_44 , V_53 ) ;
if ( ! V_51 )
return - V_54 ;
if ( V_44 == 8 )
V_101 = V_102 ;
else if ( V_44 == 4 )
V_101 = V_103 ;
else {
F_32 ( L_4 ,
F_33 ( V_8 ) , V_44 ) ;
F_22 ( V_51 ) ;
return - V_68 ;
}
if ( V_9 == V_104 )
memcpy ( V_51 , V_101 , V_44 ) ;
V_46 . V_7 = & V_7 ;
V_46 . V_48 = & V_48 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_25 | V_15 | V_55 ;
V_48 . V_56 = V_44 ;
V_48 . V_57 = 1 ;
if ( V_9 == V_105 )
V_48 . V_13 = V_58 ;
else
V_48 . V_13 = V_106 ;
V_48 . V_50 = & V_50 ;
V_48 . V_59 = 1 ;
F_20 ( & V_48 , V_2 ) ;
F_19 ( & V_50 , V_51 , V_44 ) ;
F_21 ( V_8 , & V_46 ) ;
V_5 = 0 ;
if ( V_9 == V_105 ) {
for ( V_31 = 0 ; V_31 < V_44 / 4 ; V_31 ++ )
if ( ( V_101 [ V_31 ] ^ V_51 [ V_31 ] ) != 0xff ) {
V_5 = - V_107 ;
break;
}
}
F_22 ( V_51 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_48 . error )
return V_48 . error ;
return V_5 ;
}
int F_38 ( struct V_1 * V_2 , T_2 V_108 )
{
int V_5 , V_109 ;
if ( V_108 == V_110 )
V_109 = 8 ;
else if ( V_108 == V_111 )
V_109 = 4 ;
else if ( V_108 == V_112 )
return 0 ;
else
return - V_68 ;
F_37 ( V_2 , V_2 -> V_8 , V_104 , V_109 ) ;
V_5 = F_37 ( V_2 , V_2 -> V_8 , V_105 , V_109 ) ;
return V_5 ;
}
int F_39 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_6 V_7 = { 0 } ;
unsigned int V_9 ;
int V_5 ;
if ( ! V_2 -> V_69 . V_113 ) {
F_35 ( L_5 ,
F_33 ( V_2 -> V_8 ) ) ;
return - V_68 ;
}
V_9 = V_2 -> V_69 . V_114 ;
if ( V_9 == V_115 )
V_7 . V_13 = V_87 | V_16 ;
else if ( V_9 == V_10 )
V_7 . V_13 = V_15 | V_16 ;
V_7 . V_9 = V_9 ;
V_7 . V_11 = V_2 -> V_12 << 16 | 1 ;
V_5 = F_4 ( V_2 -> V_8 , & V_7 , 0 ) ;
if ( V_5 ) {
F_40 ( L_6
L_7 , F_33 ( V_2 -> V_8 ) ,
V_5 , V_7 . V_19 [ 0 ] ) ;
return V_5 ;
}
if ( V_3 )
* V_3 = V_7 . V_19 [ 0 ] ;
return 0 ;
}
