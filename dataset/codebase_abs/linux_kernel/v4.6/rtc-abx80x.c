static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_2 -> V_5 ,
L_1 ) ;
return V_3 ;
}
return ( V_3 & V_6 ) ? 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_7 )
{
int V_8 ;
V_8 = F_5 ( V_2 , V_9 ,
V_10 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_2 ) ;
return - V_11 ;
}
V_8 = F_5 ( V_2 , V_12 ,
V_13 |
V_7 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_3 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_14 * V_5 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
unsigned char V_17 [ 8 ] ;
int V_8 , V_3 , V_18 = 0 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( ! V_18 ) {
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 & V_19 ) {
F_3 ( V_5 , L_4 ) ;
return - V_20 ;
}
}
V_8 = F_8 ( V_2 , V_21 ,
sizeof( V_17 ) , V_17 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_5 ) ;
return - V_11 ;
}
V_16 -> V_22 = F_9 ( V_17 [ V_23 ] & 0x7F ) ;
V_16 -> V_24 = F_9 ( V_17 [ V_25 ] & 0x7F ) ;
V_16 -> V_26 = F_9 ( V_17 [ V_27 ] & 0x3F ) ;
V_16 -> V_28 = V_17 [ V_29 ] & 0x7 ;
V_16 -> V_30 = F_9 ( V_17 [ V_31 ] & 0x3F ) ;
V_16 -> V_32 = F_9 ( V_17 [ V_33 ] & 0x1F ) - 1 ;
V_16 -> V_34 = F_9 ( V_17 [ V_35 ] ) + 100 ;
V_8 = F_10 ( V_16 ) ;
if ( V_8 < 0 )
F_3 ( & V_2 -> V_5 , L_6 ) ;
return V_8 ;
}
static int F_11 ( struct V_14 * V_5 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
unsigned char V_17 [ 8 ] ;
int V_8 , V_3 ;
if ( V_16 -> V_34 < 100 )
return - V_20 ;
V_17 [ V_21 ] = 0 ;
V_17 [ V_23 ] = F_12 ( V_16 -> V_22 ) ;
V_17 [ V_25 ] = F_12 ( V_16 -> V_24 ) ;
V_17 [ V_27 ] = F_12 ( V_16 -> V_26 ) ;
V_17 [ V_31 ] = F_12 ( V_16 -> V_30 ) ;
V_17 [ V_33 ] = F_12 ( V_16 -> V_32 + 1 ) ;
V_17 [ V_35 ] = F_12 ( V_16 -> V_34 - 100 ) ;
V_17 [ V_29 ] = V_16 -> V_28 ;
V_8 = F_13 ( V_2 , V_21 ,
sizeof( V_17 ) , V_17 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_7 ) ;
return - V_11 ;
}
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_8 = F_5 ( V_2 , V_4 ,
V_3 & ~ V_19 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_8 ) ;
return V_8 ;
}
return 0 ;
}
static T_2 F_14 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
struct V_38 * V_39 = F_15 ( V_2 ) ;
int V_40 ;
V_40 = F_2 ( V_2 , V_41 ) ;
if ( V_40 < 0 )
return V_42 ;
if ( V_40 & V_43 )
F_16 ( V_39 , 1 , V_44 | V_45 ) ;
F_5 ( V_2 , V_41 , 0 ) ;
return V_46 ;
}
static int F_17 ( struct V_14 * V_5 , struct V_47 * V_48 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
unsigned char V_17 [ 7 ] ;
int V_49 , V_8 ;
if ( V_2 -> V_36 <= 0 )
return - V_20 ;
V_8 = F_8 ( V_2 , V_50 ,
sizeof( V_17 ) , V_17 ) ;
if ( V_8 )
return V_8 ;
V_49 = F_2 ( V_2 , V_51 ) ;
if ( V_49 < 0 )
return V_49 ;
V_48 -> time . V_22 = F_9 ( V_17 [ 0 ] & 0x7F ) ;
V_48 -> time . V_24 = F_9 ( V_17 [ 1 ] & 0x7F ) ;
V_48 -> time . V_26 = F_9 ( V_17 [ 2 ] & 0x3F ) ;
V_48 -> time . V_30 = F_9 ( V_17 [ 3 ] & 0x3F ) ;
V_48 -> time . V_32 = F_9 ( V_17 [ 4 ] & 0x1F ) - 1 ;
V_48 -> time . V_28 = V_17 [ 5 ] & 0x7 ;
V_48 -> V_52 = ! ! ( V_49 & V_53 ) ;
V_48 -> V_54 = ( V_17 [ 6 ] & V_43 ) && V_48 -> V_52 ;
return V_8 ;
}
static int F_18 ( struct V_14 * V_5 , struct V_47 * V_48 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
T_1 V_55 [ 6 ] ;
int V_8 ;
if ( V_2 -> V_36 <= 0 )
return - V_20 ;
V_55 [ 0 ] = 0x0 ;
V_55 [ 1 ] = F_12 ( V_48 -> time . V_22 ) ;
V_55 [ 2 ] = F_12 ( V_48 -> time . V_24 ) ;
V_55 [ 3 ] = F_12 ( V_48 -> time . V_26 ) ;
V_55 [ 4 ] = F_12 ( V_48 -> time . V_30 ) ;
V_55 [ 5 ] = F_12 ( V_48 -> time . V_32 + 1 ) ;
V_8 = F_13 ( V_2 , V_56 ,
sizeof( V_55 ) , V_55 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_9 ) ;
return - V_11 ;
}
if ( V_48 -> V_52 ) {
V_8 = F_5 ( V_2 , V_51 ,
( V_57 |
V_53 ) ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_19 ( struct V_14 * V_5 ,
int V_58 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
int V_59 , V_3 = 0 ;
if ( ( V_58 != 0 ) && ( V_58 != 1024 ) &&
( V_58 != 512 ) ) {
F_3 ( V_5 , L_10 ) ;
return - V_20 ;
}
V_3 = F_2 ( V_2 , V_60 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_58 == 0 ) {
V_3 &= ~ ( V_61 | V_62 ) ;
} else if ( V_58 == 1024 ) {
V_3 |= V_62 ;
V_3 &= ~ ( V_61 ) ;
} else {
V_3 |= ( V_62 | V_61 ) ;
}
V_59 = F_5 ( V_2 , V_9 ,
V_63 ) ;
if ( V_59 < 0 ) {
F_3 ( V_5 , L_11 ) ;
return V_59 ;
}
V_59 = F_5 ( V_2 , V_60 , V_3 ) ;
return V_59 ;
}
static int F_20 ( struct V_14 * V_5 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
int V_3 = 0 , V_58 ;
V_3 = F_2 ( V_2 , V_60 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 & V_61 )
V_58 = 512 ;
else if ( V_3 & V_62 )
V_58 = 1024 ;
else
V_58 = 0 ;
return V_58 ;
}
static T_3 F_21 ( struct V_14 * V_5 ,
struct V_64 * V_65 ,
const char * V_17 , T_4 V_66 )
{
int V_59 ;
unsigned long V_58 = 0 ;
V_59 = F_22 ( V_17 , 10 , & V_58 ) ;
if ( V_59 < 0 ) {
F_3 ( V_5 , L_12 ) ;
return - V_20 ;
}
V_59 = F_19 ( V_5 , V_58 ) ;
return V_59 ? V_59 : V_66 ;
}
static T_3 F_23 ( struct V_14 * V_5 ,
struct V_64 * V_65 , char * V_17 )
{
int V_58 = 0 ;
V_58 = F_20 ( V_5 ) ;
if ( V_58 < 0 ) {
F_3 ( V_5 , L_13 ) ;
sprintf ( V_17 , L_14 ) ;
return V_58 ;
}
return sprintf ( V_17 , L_15 , V_58 ) ;
}
static T_3 F_24 ( struct V_14 * V_5 ,
struct V_64 * V_65 ,
const char * V_17 , T_4 V_66 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
int V_59 , V_3 , V_18 = 0 ;
if ( strncmp ( V_17 , L_16 , 2 ) == 0 ) {
V_18 = 1 ;
} else if ( strncmp ( V_17 , L_17 , 4 ) == 0 ) {
V_18 = 0 ;
} else {
F_3 ( V_5 , L_18 ) ;
return - V_20 ;
}
V_3 = F_2 ( V_2 , V_60 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_18 == 0 )
V_3 &= ~ ( V_67 ) ;
else
V_3 |= ( V_67 ) ;
V_59 = F_5 ( V_2 , V_9 ,
V_63 ) ;
if ( V_59 < 0 ) {
F_3 ( V_5 , L_11 ) ;
return V_59 ;
}
V_59 = F_5 ( V_2 , V_60 , V_3 ) ;
if ( V_59 < 0 ) {
F_3 ( V_5 , L_19 ) ;
return V_59 ;
}
return V_59 ? V_59 : V_66 ;
}
static T_3 F_25 ( struct V_14 * V_5 ,
struct V_64 * V_65 , char * V_17 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_7 ( V_5 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 < 0 ) {
F_3 ( V_5 , L_20 ) ;
sprintf ( V_17 , L_21 ) ;
return V_18 ;
}
if ( V_18 )
return sprintf ( V_17 , L_22 ) ;
else
return sprintf ( V_17 , L_23 ) ;
}
static int F_26 ( struct V_14 * V_5 , unsigned int V_52 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
int V_8 ;
if ( V_52 )
V_8 = F_5 ( V_2 , V_51 ,
( V_57 |
V_53 ) ) ;
else
V_8 = F_5 ( V_2 , V_51 ,
V_57 ) ;
return V_8 ;
}
static int F_27 ( struct V_68 * V_69 )
{
const char * V_70 ;
int V_7 = 0 ;
int V_71 , V_72 ;
T_5 V_73 ;
V_72 = F_28 ( V_69 , L_24 , & V_70 ) ;
if ( V_72 )
return V_72 ;
if ( ! strcmp ( V_70 , L_25 ) )
V_7 |= V_74 ;
else if ( ! strcmp ( V_70 , L_26 ) )
V_7 |= V_75 ;
else
return - V_20 ;
V_72 = F_29 ( V_69 , L_27 , & V_73 ) ;
if ( V_72 )
return V_72 ;
for ( V_71 = 0 ; V_71 < sizeof( V_76 ) ; V_71 ++ )
if ( V_76 [ V_71 ] == V_73 )
break;
if ( V_71 == sizeof( V_76 ) )
return - V_20 ;
return ( V_7 | V_71 ) ;
}
static void F_30 ( void * V_77 )
{
struct V_14 * V_5 = V_77 ;
F_31 ( & V_5 -> V_78 , & V_79 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
struct V_68 * V_69 = V_2 -> V_5 . V_82 ;
struct V_38 * V_39 ;
int V_71 , V_83 , V_8 , V_7 = - V_20 ;
char V_17 [ 7 ] ;
unsigned int V_84 = V_81 -> V_85 ;
unsigned int V_86 ;
unsigned int V_87 , V_88 ;
unsigned int V_89 ;
unsigned int V_90 ;
unsigned int V_91 ;
if ( ! F_33 ( V_2 -> V_92 , V_93 ) )
return - V_94 ;
V_8 = F_8 ( V_2 , V_95 ,
sizeof( V_17 ) , V_17 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_28 ) ;
return - V_11 ;
}
V_86 = ( V_17 [ 0 ] << 8 ) | V_17 [ 1 ] ;
V_87 = V_17 [ 2 ] >> 3 ;
V_88 = V_17 [ 2 ] & 0x7 ;
V_89 = ( ( V_17 [ 4 ] & 0x80 ) << 2 ) | ( ( V_17 [ 6 ] & 0x80 ) << 1 ) | V_17 [ 3 ] ;
V_91 = ( ( V_17 [ 4 ] & 0x7f ) << 8 ) | V_17 [ 5 ] ;
V_90 = ( V_17 [ 6 ] & 0x7c ) >> 2 ;
F_34 ( & V_2 -> V_5 , L_29 ,
V_86 , V_87 , V_88 , V_89 , V_90 , V_91 ) ;
V_83 = F_2 ( V_2 , V_96 ) ;
if ( V_83 < 0 ) {
F_3 ( & V_2 -> V_5 , L_30 ) ;
return - V_11 ;
}
V_8 = F_5 ( V_2 , V_96 ,
( ( V_83 & ~ ( V_97 |
V_98 ) ) |
V_99 ) ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_31 ) ;
return - V_11 ;
}
if ( V_84 == V_100 ) {
for ( V_71 = 0 ; V_101 [ V_71 ] . V_102 ; V_71 ++ )
if ( V_86 == V_101 [ V_71 ] . V_102 )
break;
if ( V_101 [ V_71 ] . V_102 == 0 ) {
F_3 ( & V_2 -> V_5 , L_32 ,
V_86 ) ;
return - V_20 ;
}
V_84 = V_71 ;
}
if ( V_86 != V_101 [ V_84 ] . V_102 ) {
F_3 ( & V_2 -> V_5 , L_33 ,
V_86 , V_101 [ V_84 ] . V_102 ) ;
return - V_20 ;
}
if ( V_69 && V_101 [ V_84 ] . V_103 )
V_7 = F_27 ( V_69 ) ;
if ( V_7 > 0 ) {
F_34 ( & V_2 -> V_5 , L_34 ,
V_7 ) ;
F_4 ( V_2 , V_7 ) ;
}
V_8 = F_5 ( V_2 , V_104 ,
F_35 ( 2 ) ) ;
if ( V_8 )
return V_8 ;
V_39 = F_36 ( & V_2 -> V_5 , L_35 ,
& V_105 , V_106 ) ;
if ( F_37 ( V_39 ) )
return F_38 ( V_39 ) ;
F_39 ( V_2 , V_39 ) ;
if ( V_2 -> V_36 > 0 ) {
F_34 ( & V_2 -> V_5 , L_36 , V_2 -> V_36 ) ;
V_8 = F_40 ( & V_2 -> V_5 , V_2 -> V_36 , NULL ,
F_14 ,
V_107 | V_108 ,
L_35 ,
V_2 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_5 , L_37 ) ;
V_2 -> V_36 = 0 ;
}
}
V_8 = F_41 ( & ( & V_2 -> V_5 ) -> V_78 , & V_79 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_5 , L_38 ,
V_8 ) ;
return V_8 ;
}
V_8 = F_42 ( & V_2 -> V_5 , F_30 ,
& V_2 -> V_5 ) ;
if ( V_8 ) {
F_30 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_5 ,
L_39 ,
V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
return 0 ;
}
