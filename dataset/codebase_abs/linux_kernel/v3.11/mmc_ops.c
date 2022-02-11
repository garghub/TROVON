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
int F_6 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
if ( ! F_7 ( V_2 ) ) {
F_8 ( V_2 , V_17 ) ;
F_9 ( 1 ) ;
}
V_7 . V_8 = V_18 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_19 | V_15 | V_20 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
F_9 ( 1 ) ;
if ( ! F_7 ( V_2 ) ) {
F_8 ( V_2 , V_21 ) ;
F_9 ( 1 ) ;
}
V_2 -> V_22 = 0 ;
return V_5 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_23 , T_1 * V_24 )
{
struct V_6 V_7 = { 0 } ;
int V_25 , V_5 = 0 ;
F_2 ( ! V_2 ) ;
V_7 . V_8 = V_26 ;
V_7 . V_10 = F_7 ( V_2 ) ? 0 : V_23 ;
V_7 . V_12 = V_19 | V_27 | V_28 ;
for ( V_25 = 100 ; V_25 ; V_25 -- ) {
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
if ( V_5 )
break;
if ( V_23 == 0 )
break;
if ( F_7 ( V_2 ) ) {
if ( ! ( V_7 . V_29 [ 0 ] & V_30 ) )
break;
} else {
if ( V_7 . V_29 [ 0 ] & V_31 )
break;
}
V_5 = - V_32 ;
F_9 ( 10 ) ;
}
if ( V_24 && ! F_7 ( V_2 ) )
* V_24 = V_7 . V_29 [ 0 ] ;
return V_5 ;
}
int F_11 ( struct V_1 * V_2 , T_1 * V_33 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_33 ) ;
V_7 . V_8 = V_34 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_35 | V_28 ;
V_5 = F_3 ( V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_33 , V_7 . V_29 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_4 ) ;
F_2 ( ! V_4 -> V_2 ) ;
V_7 . V_8 = V_36 ;
V_7 . V_10 = V_4 -> V_11 << 16 ;
V_7 . V_12 = V_13 | V_14 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , T_1 V_10 , T_1 * V_37 , int V_8 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_37 ) ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = V_10 ;
V_7 . V_12 = V_35 | V_14 ;
V_5 = F_3 ( V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_37 , V_7 . V_29 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int
F_14 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_1 V_8 , void * V_38 , unsigned V_39 )
{
struct V_40 V_41 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_42 V_43 = { 0 } ;
struct V_44 V_45 ;
void * V_46 ;
int V_47 ;
V_47 = F_15 ( V_38 ) ;
if ( V_47 ) {
V_46 = F_16 ( V_39 , V_48 ) ;
if ( ! V_46 )
return - V_49 ;
} else
V_46 = V_38 ;
V_41 . V_7 = & V_7 ;
V_41 . V_43 = & V_43 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_19 | V_13 | V_50 ;
V_43 . V_51 = V_39 ;
V_43 . V_52 = 1 ;
V_43 . V_12 = V_53 ;
V_43 . V_45 = & V_45 ;
V_43 . V_54 = 1 ;
F_17 ( & V_45 , V_46 , V_39 ) ;
if ( V_8 == V_55 || V_8 == V_56 ) {
V_43 . V_57 = 0 ;
V_43 . V_58 = 64 ;
} else
F_18 ( & V_43 , V_4 ) ;
F_19 ( V_2 , & V_41 ) ;
if ( V_47 ) {
memcpy ( V_38 , V_46 , V_39 ) ;
F_20 ( V_46 ) ;
}
if ( V_7 . error )
return V_7 . error ;
if ( V_43 . error )
return V_43 . error ;
return 0 ;
}
int F_21 ( struct V_3 * V_4 , T_1 * V_59 )
{
int V_60 , V_25 ;
T_1 * V_61 ;
if ( ! F_7 ( V_4 -> V_2 ) )
return F_13 ( V_4 -> V_2 , V_4 -> V_11 << 16 ,
V_59 , V_55 ) ;
V_61 = F_16 ( 16 , V_48 ) ;
if ( ! V_61 )
return - V_49 ;
V_60 = F_14 ( V_4 , V_4 -> V_2 , V_55 , V_61 , 16 ) ;
if ( V_60 )
goto V_5;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
V_59 [ V_25 ] = F_22 ( V_61 [ V_25 ] ) ;
V_5:
F_20 ( V_61 ) ;
return V_60 ;
}
int F_23 ( struct V_1 * V_2 , T_1 * V_33 )
{
int V_60 , V_25 ;
T_1 * V_62 ;
if ( ! F_7 ( V_2 ) ) {
if ( ! V_2 -> V_4 )
return - V_63 ;
return F_13 ( V_2 , V_2 -> V_4 -> V_11 << 16 ,
V_33 , V_56 ) ;
}
V_62 = F_16 ( 16 , V_48 ) ;
if ( ! V_62 )
return - V_49 ;
V_60 = F_14 ( NULL , V_2 , V_56 , V_62 , 16 ) ;
if ( V_60 )
goto V_5;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
V_33 [ V_25 ] = F_22 ( V_62 [ V_25 ] ) ;
V_5:
F_20 ( V_62 ) ;
return V_60 ;
}
int F_24 ( struct V_3 * V_4 , T_2 * V_64 )
{
return F_14 ( V_4 , V_4 -> V_2 , V_65 ,
V_64 , 512 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_66 , T_1 * V_67 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_8 = V_68 ;
V_7 . V_10 = V_66 ? ( 1 << 30 ) : 0 ;
V_7 . V_12 = V_69 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
* V_67 = V_7 . V_29 [ 1 ] ;
return V_5 ;
}
int F_26 ( struct V_1 * V_2 , int V_70 )
{
struct V_6 V_7 = { 0 } ;
int V_5 ;
V_7 . V_8 = V_71 ;
V_7 . V_12 = V_19 ;
V_7 . V_10 = V_70 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
if ( ! V_5 )
V_2 -> V_22 = V_70 ;
return V_5 ;
}
int F_27 ( struct V_3 * V_4 , T_2 V_72 , T_2 V_73 , T_2 V_74 ,
unsigned int V_75 , bool V_76 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
unsigned long V_77 ;
T_1 V_78 ;
F_2 ( ! V_4 ) ;
F_2 ( ! V_4 -> V_2 ) ;
V_7 . V_8 = V_79 ;
V_7 . V_10 = ( V_80 << 24 ) |
( V_73 << 16 ) |
( V_74 << 8 ) |
V_72 ;
V_7 . V_12 = V_14 ;
if ( V_76 )
V_7 . V_12 |= V_81 | V_82 ;
else
V_7 . V_12 |= V_19 | V_13 ;
V_7 . V_83 = V_75 ;
if ( V_73 == V_84 )
V_7 . V_85 = true ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_76 )
return 0 ;
V_77 = V_86 + F_28 ( V_87 ) ;
do {
V_5 = F_29 ( V_4 , & V_78 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 -> V_2 -> V_88 & V_89 )
break;
if ( F_7 ( V_4 -> V_2 ) )
break;
if ( F_30 ( V_86 , V_77 ) ) {
F_31 ( L_1 ,
F_32 ( V_4 -> V_2 ) , V_90 ) ;
return - V_32 ;
}
} while ( F_33 ( V_78 ) == V_91 );
if ( F_7 ( V_4 -> V_2 ) ) {
if ( V_78 & V_92 )
return - V_93 ;
} else {
if ( V_78 & 0xFDFFA000 )
F_34 ( L_2
L_3 , F_32 ( V_4 -> V_2 ) , V_78 ) ;
if ( V_78 & V_94 )
return - V_93 ;
}
return 0 ;
}
int F_35 ( struct V_3 * V_4 , T_2 V_72 , T_2 V_73 , T_2 V_74 ,
unsigned int V_75 )
{
return F_27 ( V_4 , V_72 , V_73 , V_74 , V_75 , true ) ;
}
int F_29 ( struct V_3 * V_4 , T_1 * V_78 )
{
int V_5 ;
struct V_6 V_7 = { 0 } ;
F_2 ( ! V_4 ) ;
F_2 ( ! V_4 -> V_2 ) ;
V_7 . V_8 = V_95 ;
if ( ! F_7 ( V_4 -> V_2 ) )
V_7 . V_10 = V_4 -> V_11 << 16 ;
V_7 . V_12 = V_96 | V_13 | V_14 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , V_16 ) ;
if ( V_5 )
return V_5 ;
if ( V_78 )
* V_78 = V_7 . V_29 [ 0 ] ;
return 0 ;
}
static int
F_36 ( struct V_3 * V_4 , struct V_1 * V_2 , T_2 V_8 ,
T_2 V_39 )
{
struct V_40 V_41 = { NULL } ;
struct V_6 V_7 = { 0 } ;
struct V_42 V_43 = { 0 } ;
struct V_44 V_45 ;
T_2 * V_46 ;
T_2 * V_97 ;
int V_25 , V_5 ;
static T_2 V_98 [ 8 ] = { 0x55 , 0xaa , 0 , 0 , 0 , 0 , 0 , 0 } ;
static T_2 V_99 [ 4 ] = { 0x5a , 0 , 0 , 0 } ;
V_46 = F_16 ( V_39 , V_48 ) ;
if ( ! V_46 )
return - V_49 ;
if ( V_39 == 8 )
V_97 = V_98 ;
else if ( V_39 == 4 )
V_97 = V_99 ;
else {
F_31 ( L_4 ,
F_32 ( V_2 ) , V_39 ) ;
F_20 ( V_46 ) ;
return - V_63 ;
}
if ( V_8 == V_100 )
memcpy ( V_46 , V_97 , V_39 ) ;
V_41 . V_7 = & V_7 ;
V_41 . V_43 = & V_43 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = 0 ;
V_7 . V_12 = V_19 | V_13 | V_50 ;
V_43 . V_51 = V_39 ;
V_43 . V_52 = 1 ;
if ( V_8 == V_101 )
V_43 . V_12 = V_53 ;
else
V_43 . V_12 = V_102 ;
V_43 . V_45 = & V_45 ;
V_43 . V_54 = 1 ;
F_17 ( & V_45 , V_46 , V_39 ) ;
F_19 ( V_2 , & V_41 ) ;
V_5 = 0 ;
if ( V_8 == V_101 ) {
for ( V_25 = 0 ; V_25 < V_39 / 4 ; V_25 ++ )
if ( ( V_97 [ V_25 ] ^ V_46 [ V_25 ] ) != 0xff ) {
V_5 = - V_103 ;
break;
}
}
F_20 ( V_46 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_43 . error )
return V_43 . error ;
return V_5 ;
}
int F_37 ( struct V_3 * V_4 , T_2 V_104 )
{
int V_5 , V_105 ;
if ( V_104 == V_106 )
V_105 = 8 ;
else if ( V_104 == V_107 )
V_105 = 4 ;
else if ( V_104 == V_108 )
return 0 ;
else
return - V_63 ;
F_36 ( V_4 , V_4 -> V_2 , V_100 , V_105 ) ;
V_5 = F_36 ( V_4 , V_4 -> V_2 , V_101 , V_105 ) ;
return V_5 ;
}
int F_38 ( struct V_3 * V_4 , T_1 * V_78 )
{
struct V_6 V_7 = { 0 } ;
unsigned int V_8 ;
int V_5 ;
if ( ! V_4 -> V_64 . V_109 ) {
F_34 ( L_5 ,
F_32 ( V_4 -> V_2 ) ) ;
return - V_63 ;
}
V_8 = V_4 -> V_64 . V_110 ;
if ( V_8 == V_111 )
V_7 . V_12 = V_82 | V_14 ;
else if ( V_8 == V_95 )
V_7 . V_12 = V_13 | V_14 ;
V_7 . V_8 = V_8 ;
V_7 . V_10 = V_4 -> V_11 << 16 | 1 ;
V_5 = F_3 ( V_4 -> V_2 , & V_7 , 0 ) ;
if ( V_5 ) {
F_39 ( L_6
L_7 , F_32 ( V_4 -> V_2 ) ,
V_5 , V_7 . V_29 [ 0 ] ) ;
return V_5 ;
}
if ( V_78 )
* V_78 = V_7 . V_29 [ 0 ] ;
return 0 ;
}
