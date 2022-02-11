static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 , V_8 ;
int V_9 , V_10 ;
for ( V_10 = F_2 ( V_11 ) - 1 ; V_10 >= 0 ; V_10 -- )
if ( V_2 -> V_12 == V_11 [ V_10 ] . V_12 )
break;
if ( V_10 < 0 )
return - V_13 ;
V_7 = V_2 -> V_14 . V_15 ;
V_8 = V_7 + V_11 [ V_10 ] . V_16 ;
V_6 = F_3 ( 0 ) ;
if ( ! V_6 )
return - V_17 ;
if ( ! F_4 ( V_8 , V_18 * 2 , V_19 ) ) {
F_5 ( V_6 ) ;
return - V_20 ;
}
if ( ( V_9 = F_6 ( V_6 , V_7 , V_11 [ V_10 ] . V_21 ,
F_7 ( V_8 ) ) ) ) {
F_8 ( V_8 , V_18 * 2 ) ;
F_5 ( V_6 ) ;
return V_9 ;
}
F_9 ( V_2 , V_6 ) ;
return 0 ;
}
static int T_1 F_6 ( struct V_5 * V_6 ,
unsigned long V_7 , const char * V_21 ,
unsigned long V_8 )
{
int V_10 ;
int V_9 ;
unsigned char V_22 [ 32 ] ;
int V_23 , V_24 ;
static T_2 V_25 [ 16 ] = {
0x00 , 0x02 , 0x04 , 0x06 , 0x08 , 0x0a , 0x0c , 0x0e ,
0x10 , 0x12 , 0x14 , 0x16 , 0x18 , 0x1a , 0x1c , 0x1e ,
} ;
{
unsigned long V_26 = V_27 ;
F_10 ( F_11 ( V_8 + V_28 ) , V_8 + V_28 ) ;
while ( ( F_11 ( V_8 + V_29 ) & V_30 ) == 0 )
if ( F_12 ( V_27 , V_26 + 2 * V_31 / 100 ) ) {
F_13 ( V_32 L_1 ) ;
return - V_13 ;
}
F_10 ( 0xff , V_8 + V_29 ) ;
}
{
struct {
T_2 V_33 ;
T_2 V_16 ;
} V_34 [] = {
{ V_35 + V_36 + V_37 , V_38 } ,
{ 0x48 , V_39 } ,
{ 0x00 , V_40 } ,
{ 0x00 , V_41 } ,
{ 0x00 , V_42 } ,
{ 0xFF , V_29 } ,
{ V_43 , V_44 } ,
{ V_45 , V_46 } ,
{ 32 , V_40 } ,
{ 0x00 , V_41 } ,
{ 0x00 , V_47 } ,
{ 0x00 , V_48 } ,
{ V_49 + V_50 , V_38 } ,
} ;
for ( V_10 = 0 ; V_10 < F_2 ( V_34 ) ; V_10 ++ ) {
F_10 ( V_34 [ V_10 ] . V_33 , V_8 + V_34 [ V_10 ] . V_16 ) ;
}
}
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ ) {
V_22 [ V_10 ] = F_11 ( V_8 + V_51 ) ;
( void ) F_11 ( V_8 + V_51 ) ;
}
F_10 ( 0x49 , V_8 + V_39 ) ;
V_23 = V_52 ;
V_24 = V_53 ;
V_6 -> V_54 = V_8 ;
V_6 -> V_55 = V_56 ;
V_10 = F_14 ( V_56 , V_57 , V_58 , V_19 , V_6 ) ;
if ( V_10 ) return V_10 ;
for( V_10 = 0 ; V_10 < V_59 ; V_10 ++ )
V_6 -> V_60 [ V_10 ] = V_22 [ V_10 ] ;
#ifdef F_15
F_13 ( L_2 , V_6 -> V_60 ) ;
#endif
V_61 . V_21 = V_21 ;
V_61 . V_62 = V_23 ;
V_61 . V_24 = V_24 ;
V_61 . V_63 = 1 ;
V_61 . V_64 = V_23 + V_65 ;
V_61 . V_66 = & V_67 ;
V_61 . V_68 = & V_69 ;
V_61 . V_70 = & V_71 ;
V_61 . V_72 = & V_73 ;
V_61 . V_74 = V_25 ;
V_6 -> V_75 = & V_76 ;
F_16 ( V_6 , 0 ) ;
V_9 = F_17 ( V_6 ) ;
if ( V_9 ) {
F_18 ( V_56 , V_6 ) ;
return V_9 ;
}
F_13 ( V_77 L_3 ,
V_6 -> V_21 , V_21 , V_7 , V_6 -> V_60 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 )
{
F_20 ( V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
if ( V_78 > 1 )
F_13 ( V_79 L_4 , V_6 -> V_21 ) ;
F_22 ( V_6 ) ;
return 0 ;
}
static void V_67 ( struct V_5 * V_6 )
{
unsigned long V_26 = V_27 ;
if ( V_78 > 1 )
F_13 ( V_79 L_5 , V_27 ) ;
F_10 ( F_11 ( V_80 + V_28 ) , V_80 + V_28 ) ;
V_61 . V_81 = 0 ;
V_61 . V_82 = 0 ;
while ( ( F_11 ( V_80 + V_29 ) & V_30 ) == 0 )
if ( F_12 ( V_27 , V_26 + 2 * V_31 / 100 ) ) {
F_13 ( V_32 L_6 ,
V_6 -> V_21 ) ;
break;
}
F_10 ( V_30 , V_80 + V_29 ) ;
}
static void V_73 ( struct V_5 * V_6 ,
struct V_83 * V_84 , int V_85 )
{
int V_86 = V_6 -> V_54 ;
int V_87 ;
short * V_88 ;
if ( V_61 . V_82 ) {
F_13 ( V_89 L_7
L_8 , V_6 -> V_21 , V_61 . V_82 ,
V_61 . V_90 ) ;
return;
}
V_61 . V_82 |= 0x01 ;
F_10 ( V_35 + V_36 + V_50 , V_86 + V_38 ) ;
F_10 ( V_91 , V_86 + V_29 ) ;
F_10 ( sizeof( struct V_83 ) , V_86 + V_40 ) ;
F_10 ( 0 , V_86 + V_41 ) ;
F_10 ( 0 , V_86 + V_47 ) ;
F_10 ( V_85 , V_86 + V_48 ) ;
F_10 ( V_49 + V_50 , V_86 + V_38 ) ;
V_88 = ( short * ) V_84 ;
for ( V_87 = 0 ; V_87 < ( sizeof( struct V_83 ) >> 1 ) ; V_87 ++ )
* V_88 ++ = F_23 ( V_80 + V_51 ) ;
F_10 ( V_91 , V_86 + V_29 ) ;
V_84 -> V_92 = F_24 ( V_84 -> V_92 ) ;
V_61 . V_82 &= ~ 0x01 ;
}
static void V_69 ( struct V_5 * V_6 , int V_92 ,
struct V_93 * V_94 , int V_95 )
{
int V_86 = V_6 -> V_54 ;
char * V_96 = V_94 -> V_97 ;
short * V_88 ;
int V_87 ;
if ( V_61 . V_82 ) {
F_13 ( V_89 L_9
L_8 ,
V_6 -> V_21 , V_61 . V_82 , V_61 . V_90 ) ;
return;
}
V_61 . V_82 |= 0x01 ;
F_10 ( V_35 + V_36 + V_50 , V_86 + V_38 ) ;
F_10 ( V_91 , V_86 + V_29 ) ;
F_10 ( V_92 & 0xff , V_86 + V_40 ) ;
F_10 ( V_92 >> 8 , V_86 + V_41 ) ;
F_10 ( V_95 & 0xff , V_86 + V_47 ) ;
F_10 ( V_95 >> 8 , V_86 + V_48 ) ;
F_10 ( V_49 + V_50 , V_86 + V_38 ) ;
V_88 = ( short * ) V_96 ;
for ( V_87 = 0 ; V_87 < ( V_92 >> 1 ) ; V_87 ++ )
* V_88 ++ = F_23 ( V_80 + V_51 ) ;
if ( V_92 & 0x01 )
V_96 [ V_92 - 1 ] = F_11 ( V_80 + V_51 ) ;
F_10 ( V_91 , V_86 + V_29 ) ;
V_61 . V_82 &= ~ 0x01 ;
}
static void V_71 ( struct V_5 * V_6 , int V_92 ,
const unsigned char * V_96 ,
const int V_23 )
{
int V_86 = V_80 ;
unsigned long V_98 ;
short * V_88 ;
int V_87 ;
if ( V_92 & 0x01 )
V_92 ++ ;
if ( V_61 . V_82 ) {
F_13 ( V_89 L_10
L_11 , V_6 -> V_21 , V_61 . V_82 ,
V_61 . V_90 ) ;
return;
}
V_61 . V_82 |= 0x01 ;
F_10 ( V_36 + V_50 + V_35 , V_86 + V_38 ) ;
F_10 ( V_91 , V_86 + V_29 ) ;
F_10 ( V_92 & 0xff , V_86 + V_40 ) ;
F_10 ( V_92 >> 8 , V_86 + V_41 ) ;
F_10 ( 0x00 , V_86 + V_47 ) ;
F_10 ( V_23 , V_86 + V_48 ) ;
F_10 ( V_99 + V_50 , V_86 + V_38 ) ;
V_88 = ( short * ) V_96 ;
for ( V_87 = 0 ; V_87 < V_92 > > 1 ; V_87 ++ )
F_25 ( * V_88 ++ , V_80 + V_51 ) ;
V_98 = V_27 ;
while ( ( F_11 ( V_80 + V_29 ) & V_91 ) == 0 )
if ( F_12 ( V_27 , V_98 + 2 * V_31 / 100 ) ) {
F_13 ( V_89 L_12 ,
V_6 -> V_21 ) ;
V_67 ( V_6 ) ;
F_16 ( V_6 , 1 ) ;
break;
}
F_10 ( V_91 , V_86 + V_29 ) ;
V_61 . V_82 &= ~ 0x01 ;
}
static void T_3 F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_28 ( V_6 ) ;
F_18 ( V_56 , V_6 ) ;
F_8 ( F_29 ( V_6 -> V_54 ) , V_18 * 2 ) ;
F_5 ( V_6 ) ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_100 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_100 ) ;
}
