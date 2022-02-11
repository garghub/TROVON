static inline int F_1 ( unsigned char * V_1 , int V_2 )
{
int V_3 ;
if ( ( V_1 [ 0 ] != 0x00 ) || ( V_1 [ 1 ] != 0x01 ) )
return 0 ;
for ( V_3 = 2 ; V_3 < V_2 ; V_3 ++ )
if ( V_1 [ V_3 ] != 0xFF )
break;
if ( V_3 < 10 || V_3 == V_2 )
return 0 ;
if ( V_1 [ V_3 ] != 0x00 )
return 0 ;
return 1 ;
}
static inline int F_2 ( unsigned char * V_1 , int V_2 )
{
int V_3 ;
if ( ( V_1 [ 0 ] != 0x00 ) || ( V_1 [ 1 ] != 0x02 ) )
return 0 ;
for ( V_3 = 2 ; V_3 < V_2 ; V_3 ++ )
if ( V_1 [ V_3 ] == 0x00 )
break;
if ( ( V_3 < 10 ) || ( V_3 == V_2 ) )
return 0 ;
if ( V_1 [ V_3 ] != 0x00 )
return 0 ;
return 1 ;
}
static int F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
static struct V_10 V_11 = {
. type = 0x06 ,
. V_12 = 0x00000058 ,
. V_13 = { 0x01 , 0x00 , 0x43 , 0x43 , 0x41 , 0x2D , 0x41 , 0x50 ,
0x50 , 0x4C , 0x20 , 0x20 , 0x20 , 0x01 , 0x01 , 0x01 } ,
. V_14 = { 'P' , 'K' } ,
} ;
static struct V_15 V_16 = {
. V_14 = { 'P' , 'K' } ,
. V_17 = F_4 ( 10 ) ,
. V_18 = { 'P' , 'K' , 'C' , 'S' , '-' , '1' , '.' , '2' }
} ;
struct {
struct V_10 V_19 ;
struct V_20 V_21 ;
struct V_15 V_22 ;
unsigned short V_2 ;
char V_23 [ 0 ] ;
} V_24 ( ( V_25 ) ) * V_26 = V_7 -> V_27 ;
int V_28 , V_29 , V_30 ;
if ( F_5 ( V_26 -> V_23 , V_9 -> V_31 , V_9 -> V_32 ) )
return - V_33 ;
if ( F_1 ( V_26 -> V_23 , V_9 -> V_32 ) )
return - V_34 ;
V_26 -> V_19 = V_11 ;
V_26 -> V_22 = V_16 ;
if ( F_2 ( V_26 -> V_23 , V_9 -> V_32 ) ) {
V_29 = F_6 ( V_26 -> V_23 + 2 , V_9 -> V_32 - 2 ) + 3 ;
if ( V_29 <= 9 || V_29 >= V_9 -> V_32 )
return - V_35 ;
V_28 = V_9 -> V_32 - V_29 ;
memmove ( V_26 -> V_23 , V_26 -> V_23 + V_29 , V_28 ) ;
V_26 -> V_2 = F_7 ( V_28 + 2 ) ;
V_30 = F_8 ( V_9 , V_26 -> V_23 + V_28 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 += sizeof( * V_26 ) + V_28 ;
} else {
V_28 = V_9 -> V_32 ;
V_26 -> V_2 = F_7 ( 2 + V_28 ) ;
V_26 -> V_19 . V_14 [ 1 ] = 'D' ;
V_26 -> V_22 . V_14 [ 1 ] = 'D' ;
V_30 = F_9 ( V_9 , V_26 -> V_23 + V_28 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 += sizeof( * V_26 ) + V_28 ;
}
V_26 -> V_19 . V_36 = ( V_30 - sizeof( V_26 -> V_19 ) + 3 ) & - 4 ;
V_26 -> V_19 . V_37 = V_38 - sizeof( V_26 -> V_19 ) ;
V_26 -> V_21 = V_39 ;
V_26 -> V_21 . V_40 [ 0 ] = F_10 ( V_5 -> V_41 -> V_42 ) ;
V_26 -> V_21 . V_43 = F_7 ( V_30 - sizeof( V_26 -> V_19 ) -
sizeof( V_26 -> V_21 ) ) ;
V_26 -> V_21 . V_44 = F_7 ( V_26 -> V_19 . V_37 ) ;
V_7 -> V_2 = ( V_30 + 3 ) & - 4 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_45 * V_46 )
{
static struct V_10 V_11 = {
. type = 0x06 ,
. V_12 = 0x00000058 ,
. V_13 = { 0x01 , 0x00 , 0x43 , 0x43 , 0x41 , 0x2D , 0x41 , 0x50 ,
0x50 , 0x4C , 0x20 , 0x20 , 0x20 , 0x01 , 0x01 , 0x01 } ,
. V_14 = { 'P' , 'D' } ,
} ;
static struct V_15 V_47 = {
. V_14 = { 'P' , 'D' } ,
. V_17 = F_4 ( 10 ) ,
. V_18 = { 'P' , 'K' , 'C' , 'S' , '-' , '1' , '.' , '2' }
} ;
struct {
struct V_10 V_19 ;
struct V_20 V_21 ;
struct V_15 V_22 ;
unsigned short V_2 ;
char V_23 [ 0 ] ;
} V_24 ( ( V_25 ) ) * V_26 = V_7 -> V_27 ;
int V_30 ;
V_26 -> V_2 = F_7 ( 2 + V_46 -> V_32 ) ;
if ( F_5 ( V_26 -> V_23 , V_46 -> V_31 , V_46 -> V_32 ) )
return - V_33 ;
if ( F_1 ( V_26 -> V_23 , V_46 -> V_32 ) )
return - V_34 ;
V_30 = F_12 ( V_46 , V_26 -> V_23 + V_46 -> V_32 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 += sizeof( * V_26 ) + V_46 -> V_32 ;
V_26 -> V_19 = V_11 ;
V_26 -> V_19 . V_36 = ( V_30 - sizeof( V_26 -> V_19 ) + 3 ) & - 4 ;
V_26 -> V_19 . V_37 = V_38 - sizeof( V_26 -> V_19 ) ;
V_26 -> V_21 = V_39 ;
V_26 -> V_21 . V_40 [ 0 ] = F_10 ( V_5 -> V_41 -> V_42 ) ;
V_26 -> V_21 . V_43 = V_26 -> V_21 . V_44 =
F_7 ( V_30 - sizeof( V_26 -> V_19 ) - sizeof( V_26 -> V_21 ) ) ;
V_26 -> V_22 = V_47 ;
V_7 -> V_2 = ( V_30 + 3 ) & - 4 ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_6 * V_48 ,
char T_1 * V_49 ,
unsigned int V_50 )
{
static unsigned char V_51 [] = {
0x00 , 0x02 ,
0x1B , 0x7B , 0x5D , 0xB5 , 0x75 , 0x01 , 0x3D , 0xFD ,
0x8D , 0xD1 , 0xC7 , 0x03 , 0x2D , 0x09 , 0x23 , 0x57 ,
0x89 , 0x49 , 0xB9 , 0x3F , 0xBB , 0x99 , 0x41 , 0x5B ,
0x75 , 0x21 , 0x7B , 0x9D , 0x3B , 0x6B , 0x51 , 0x39 ,
0xBB , 0x0D , 0x35 , 0xB9 , 0x89 , 0x0F , 0x93 , 0xA5 ,
0x0B , 0x47 , 0xF1 , 0xD3 , 0xBB , 0xCB , 0xF1 , 0x9D ,
0x23 , 0x73 , 0x71 , 0xFF , 0xF3 , 0xF5 , 0x45 , 0xFB ,
0x61 , 0x29 , 0x23 , 0xFD , 0xF1 , 0x29 , 0x3F , 0x7F ,
0x17 , 0xB7 , 0x1B , 0xA9 , 0x19 , 0xBD , 0x57 , 0xA9 ,
0xD7 , 0x95 , 0xA3 , 0xCB , 0xED , 0x1D , 0xDB , 0x45 ,
0x7D , 0x11 , 0xD1 , 0x51 , 0x1B , 0xED , 0x71 , 0xE9 ,
0xB1 , 0xD1 , 0xAB , 0xAB , 0x21 , 0x2B , 0x1B , 0x9F ,
0x3B , 0x9F , 0xF7 , 0xF7 , 0xBD , 0x63 , 0xEB , 0xAD ,
0xDF , 0xB3 , 0x6F , 0x5B , 0xDB , 0x8D , 0xA9 , 0x5D ,
0xE3 , 0x7D , 0x77 , 0x49 , 0x47 , 0xF5 , 0xA7 , 0xFD ,
0xAB , 0x2F , 0x27 , 0x35 , 0x77 , 0xD3 , 0x49 , 0xC9 ,
0x09 , 0xEB , 0xB1 , 0xF9 , 0xBF , 0x4B , 0xCB , 0x2B ,
0xEB , 0xEB , 0x05 , 0xFF , 0x7D , 0xC7 , 0x91 , 0x8B ,
0x09 , 0x83 , 0xB9 , 0xB9 , 0x69 , 0x33 , 0x39 , 0x6B ,
0x79 , 0x75 , 0x19 , 0xBF , 0xBB , 0x07 , 0x1D , 0xBD ,
0x29 , 0xBF , 0x39 , 0x95 , 0x93 , 0x1D , 0x35 , 0xC7 ,
0xC9 , 0x4D , 0xE5 , 0x97 , 0x0B , 0x43 , 0x9B , 0xF1 ,
0x16 , 0x93 , 0x03 , 0x1F , 0xA5 , 0xFB , 0xDB , 0xF3 ,
0x27 , 0x4F , 0x27 , 0x61 , 0x05 , 0x1F , 0xB9 , 0x23 ,
0x2F , 0xC3 , 0x81 , 0xA9 , 0x23 , 0x71 , 0x55 , 0x55 ,
0xEB , 0xED , 0x41 , 0xE5 , 0xF3 , 0x11 , 0xF1 , 0x43 ,
0x69 , 0x03 , 0xBD , 0x0B , 0x37 , 0x0F , 0x51 , 0x8F ,
0x0B , 0xB5 , 0x89 , 0x5B , 0x67 , 0xA9 , 0xD9 , 0x4F ,
0x01 , 0xF9 , 0x21 , 0x77 , 0x37 , 0x73 , 0x79 , 0xC5 ,
0x7F , 0x51 , 0xC1 , 0xCF , 0x97 , 0xA1 , 0x75 , 0xAD ,
0x35 , 0x9D , 0xD3 , 0xD3 , 0xA7 , 0x9D , 0x5D , 0x41 ,
0x6F , 0x65 , 0x1B , 0xCF , 0xA9 , 0x87 , 0x91 , 0x09
} ;
struct V_52 * V_26 = V_48 -> V_27 ;
unsigned short V_53 , V_54 ;
unsigned int V_55 , V_29 ;
char * V_56 ;
V_53 = F_14 ( V_26 -> V_21 . V_57 ) ;
if ( F_15 ( V_53 != 0 ) ) {
V_54 = F_14 ( V_26 -> V_21 . V_58 ) ;
if ( V_53 == 8 && V_54 == 66 )
return - V_34 ;
if ( V_53 == 8 && V_54 == 65 )
return - V_34 ;
if ( V_53 == 8 && V_54 == 770 ) {
V_5 -> V_59 = V_60 ;
return - V_61 ;
}
if ( V_53 == 8 && V_54 == 783 ) {
V_5 -> V_59 = V_60 ;
return - V_61 ;
}
if ( V_53 == 8 && V_54 == 72 )
return - V_34 ;
V_5 -> V_62 = 0 ;
return - V_61 ;
}
V_56 = V_26 -> V_23 ;
V_55 = F_14 ( V_26 -> V_2 ) - 2 ;
if ( V_55 > V_50 )
return - V_34 ;
V_29 = V_50 - V_55 ;
if ( V_29 > 0 ) {
if ( V_29 < 10 )
return - V_34 ;
if ( F_16 ( V_49 , V_51 , V_29 - 1 ) )
return - V_33 ;
if ( F_17 ( 0 , V_49 + V_29 - 1 ) )
return - V_33 ;
}
if ( F_16 ( V_49 + V_29 , V_56 , V_55 ) )
return - V_33 ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_6 * V_48 ,
char T_1 * V_49 ,
unsigned int V_50 )
{
struct V_52 * V_26 = V_48 -> V_27 ;
switch ( V_26 -> V_19 . type ) {
case V_63 :
case V_64 :
return F_19 ( V_5 , V_48 ) ;
case V_65 :
if ( V_26 -> V_19 . V_66 )
return F_19 ( V_5 , V_48 ) ;
if ( V_26 -> V_21 . V_67 == 0x01 )
return F_13 ( V_5 , V_48 ,
V_49 , V_50 ) ;
default:
V_5 -> V_62 = 0 ;
return - V_61 ;
}
}
static void F_20 ( struct V_68 * V_41 ,
struct V_6 * V_26 ,
struct V_6 * V_48 )
{
static struct V_69 V_70 = {
. type = V_63 ,
. V_66 = V_71 ,
} ;
struct V_52 * V_72 ;
int V_2 ;
if ( F_21 ( V_48 ) ) {
memcpy ( V_26 -> V_27 , & V_70 , sizeof( V_70 ) ) ;
goto V_73;
}
V_72 = V_48 -> V_27 ;
if ( V_72 -> V_19 . type == V_65 &&
V_72 -> V_21 . V_67 == 0x01 ) {
V_2 = sizeof( struct V_52 ) + V_72 -> V_2 - 2 ;
V_2 = F_22 ( V_38 , V_2 ) ;
memcpy ( V_26 -> V_27 , V_48 -> V_27 , V_2 ) ;
} else
memcpy ( V_26 -> V_27 , V_48 -> V_27 , sizeof V_70 ) ;
V_73:
F_23 ( (struct V_74 * ) V_26 -> V_75 ) ;
}
static long F_24 ( struct V_4 * V_5 ,
struct V_8 * V_9 )
{
struct V_6 V_7 ;
struct V_74 V_76 ;
int V_77 ;
F_25 ( & V_7 ) ;
V_7 . V_27 = ( void * ) F_26 ( V_78 ) ;
if ( ! V_7 . V_27 )
return - V_79 ;
V_7 . V_2 = V_80 ;
V_7 . V_81 = ( ( ( unsigned long long ) V_82 -> V_83 ) << 32 ) +
F_27 ( & V_84 ) ;
V_7 . V_75 = & V_76 ;
V_77 = F_3 ( V_5 , & V_7 , V_9 ) ;
if ( V_77 )
goto V_85;
F_28 ( & V_76 ) ;
F_29 ( V_5 -> V_41 , & V_7 ) ;
V_77 = F_30 ( & V_76 ) ;
if ( V_77 == 0 )
V_77 = F_18 ( V_5 , & V_7 , V_9 -> V_49 ,
V_9 -> V_50 ) ;
else
F_31 ( V_5 -> V_41 , & V_7 ) ;
V_85:
F_32 ( ( unsigned long ) V_7 . V_27 ) ;
return V_77 ;
}
static long F_33 ( struct V_4 * V_5 ,
struct V_45 * V_46 )
{
struct V_6 V_7 ;
struct V_74 V_76 ;
int V_77 ;
F_25 ( & V_7 ) ;
V_7 . V_27 = ( void * ) F_26 ( V_78 ) ;
if ( ! V_7 . V_27 )
return - V_79 ;
V_7 . V_2 = V_80 ;
V_7 . V_81 = ( ( ( unsigned long long ) V_82 -> V_83 ) << 32 ) +
F_27 ( & V_84 ) ;
V_7 . V_75 = & V_76 ;
V_77 = F_11 ( V_5 , & V_7 , V_46 ) ;
if ( V_77 )
goto V_85;
F_28 ( & V_76 ) ;
F_29 ( V_5 -> V_41 , & V_7 ) ;
V_77 = F_30 ( & V_76 ) ;
if ( V_77 == 0 )
V_77 = F_18 ( V_5 , & V_7 , V_46 -> V_49 ,
V_46 -> V_50 ) ;
else
F_31 ( V_5 -> V_41 , & V_7 ) ;
V_85:
F_32 ( ( unsigned long ) V_7 . V_27 ) ;
return V_77 ;
}
static int F_34 ( struct V_68 * V_41 )
{
struct V_4 * V_5 ;
int V_77 ;
V_5 = F_35 ( V_38 ) ;
if ( ! V_5 )
return - V_79 ;
V_5 -> V_41 = V_41 ;
V_5 -> V_86 = & V_87 ;
V_5 -> V_62 = 1 ;
V_5 -> V_88 = V_89 ;
V_5 -> V_90 = L_1 ;
V_5 -> V_91 = V_92 ;
V_5 -> V_59 = V_93 ;
V_5 -> V_94 = V_95 ;
V_5 -> V_96 = V_93 ;
V_41 -> V_48 = & V_5 -> V_48 ;
V_41 -> V_75 = V_5 ;
V_77 = F_36 ( V_5 ) ;
if ( V_77 )
goto V_85;
return 0 ;
V_85:
V_41 -> V_75 = NULL ;
F_37 ( V_5 ) ;
return V_77 ;
}
static void F_38 ( struct V_68 * V_41 )
{
struct V_4 * V_5 = V_41 -> V_75 ;
F_39 ( V_5 ) ;
}
int T_2 F_40 ( void )
{
return F_41 ( & V_97 , V_98 , L_2 ) ;
}
void F_42 ( void )
{
F_43 ( & V_97 ) ;
}
