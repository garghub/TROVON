static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_7 , V_2 , L_1 , V_4 ) ;
F_4 ( F_5 ( V_8 + V_9 ) , V_8 + V_9 ) ;
V_10 . V_11 = 0 ;
V_10 . V_12 = 0 ;
while ( ( F_5 ( V_8 + V_13 ) & V_14 ) == 0 )
if ( F_6 ( V_4 , V_3 + 2 * V_15 / 100 ) ) {
F_7 ( V_2 , L_2 , V_16 ) ;
break;
}
F_4 ( V_14 , V_8 + V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_17 * V_18 , int V_19 )
{
int V_20 = V_2 -> V_21 ;
int V_22 ;
short * V_23 ;
if ( V_10 . V_12 ) {
F_7 ( V_2 ,
L_3 ,
V_16 , V_10 . V_12 , V_10 . V_24 ) ;
return;
}
V_10 . V_12 |= 0x01 ;
F_4 ( V_25 + V_26 + V_27 , V_20 + V_28 ) ;
F_4 ( V_29 , V_20 + V_13 ) ;
F_4 ( sizeof( struct V_17 ) , V_20 + V_30 ) ;
F_4 ( 0 , V_20 + V_31 ) ;
F_4 ( 0 , V_20 + V_32 ) ;
F_4 ( V_19 , V_20 + V_33 ) ;
F_4 ( V_34 + V_27 , V_20 + V_28 ) ;
V_23 = ( short * ) V_18 ;
for ( V_22 = 0 ; V_22 < sizeof( struct V_17 ) >> 1 ; V_22 ++ )
* V_23 ++ = F_9 ( V_8 + V_35 ) ;
F_4 ( V_29 , V_20 + V_13 ) ;
V_18 -> V_36 = F_10 ( V_18 -> V_36 ) ;
V_10 . V_12 &= ~ 0x01 ;
}
static void F_11 ( struct V_1 * V_2 , int V_36 ,
struct V_37 * V_38 , int V_39 )
{
int V_20 = V_2 -> V_21 ;
char * V_40 = V_38 -> V_41 ;
short * V_23 ;
int V_22 ;
if ( V_10 . V_12 ) {
F_12 ( V_2 , L_3 ,
V_16 , V_10 . V_12 , V_10 . V_24 ) ;
return;
}
V_10 . V_12 |= 0x01 ;
F_4 ( V_25 + V_26 + V_27 , V_20 + V_28 ) ;
F_4 ( V_29 , V_20 + V_13 ) ;
F_4 ( V_36 & 0xff , V_20 + V_30 ) ;
F_4 ( V_36 >> 8 , V_20 + V_31 ) ;
F_4 ( V_39 & 0xff , V_20 + V_32 ) ;
F_4 ( V_39 >> 8 , V_20 + V_33 ) ;
F_4 ( V_34 + V_27 , V_20 + V_28 ) ;
V_23 = ( short * ) V_40 ;
for ( V_22 = 0 ; V_22 < V_36 > > 1 ; V_22 ++ )
* V_23 ++ = F_9 ( V_8 + V_35 ) ;
if ( V_36 & 0x01 )
V_40 [ V_36 - 1 ] = F_5 ( V_8 + V_35 ) ;
F_4 ( V_29 , V_20 + V_13 ) ;
V_10 . V_12 &= ~ 0x01 ;
}
static void F_13 ( struct V_1 * V_2 , int V_36 ,
const unsigned char * V_40 ,
const int V_42 )
{
int V_20 = V_8 ;
unsigned long V_43 ;
short * V_23 ;
int V_22 ;
if ( V_36 & 0x01 )
V_36 ++ ;
if ( V_10 . V_12 ) {
F_12 ( V_2 , L_3 ,
V_16 , V_10 . V_12 , V_10 . V_24 ) ;
return;
}
V_10 . V_12 |= 0x01 ;
F_4 ( V_26 + V_27 + V_25 , V_20 + V_28 ) ;
F_4 ( V_29 , V_20 + V_13 ) ;
F_4 ( V_36 & 0xff , V_20 + V_30 ) ;
F_4 ( V_36 >> 8 , V_20 + V_31 ) ;
F_4 ( 0x00 , V_20 + V_32 ) ;
F_4 ( V_42 , V_20 + V_33 ) ;
F_4 ( V_44 + V_27 , V_20 + V_28 ) ;
V_23 = ( short * ) V_40 ;
for ( V_22 = 0 ; V_22 < V_36 > > 1 ; V_22 ++ )
F_14 ( * V_23 ++ , V_8 + V_35 ) ;
V_43 = V_4 ;
while ( ( F_5 ( V_8 + V_13 ) & V_29 ) == 0 )
if ( F_6 ( V_4 , V_43 + 2 * V_15 / 100 ) ) {
F_7 ( V_2 , L_4 ) ;
F_1 ( V_2 ) ;
F_15 ( V_2 , 1 ) ;
break;
}
F_4 ( V_29 , V_20 + V_13 ) ;
V_10 . V_12 &= ~ 0x01 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_45 , V_2 , L_5 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static void F_20 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_21 ( V_47 ) ;
F_22 ( V_2 ) ;
F_23 ( V_48 , V_2 ) ;
F_24 ( F_25 ( V_2 -> V_21 ) , V_49 * 2 ) ;
F_26 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_50 ,
const char * V_51 , void T_1 * V_52 )
{
int V_53 ;
int V_54 ;
unsigned char V_55 [ 32 ] ;
int V_42 , V_56 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
static T_2 V_57 [ 16 ] = {
0x00 , 0x02 , 0x04 , 0x06 , 0x08 , 0x0a , 0x0c , 0x0e ,
0x10 , 0x12 , 0x14 , 0x16 , 0x18 , 0x1a , 0x1c , 0x1e ,
} ;
{
unsigned long V_3 = V_4 ;
F_4 ( F_5 ( V_52 + V_9 ) , V_52 + V_9 ) ;
while ( ( F_5 ( V_52 + V_13 ) & V_14 ) == 0 )
if ( F_6 ( V_4 ,
V_3 + 2 * V_15 / 100 ) ) {
F_7 ( V_2 , L_6 ) ;
return - V_58 ;
}
F_4 ( 0xff , V_52 + V_13 ) ;
}
{
static const struct {
T_2 V_59 ;
T_2 V_60 ;
} V_61 [] = {
{ V_25 + V_26 + V_62 , V_28 } ,
{ 0x48 , V_63 } ,
{ 0x00 , V_30 } ,
{ 0x00 , V_31 } ,
{ 0x00 , V_64 } ,
{ 0xFF , V_13 } ,
{ V_65 , V_66 } ,
{ V_67 , V_68 } ,
{ 32 , V_30 } ,
{ 0x00 , V_31 } ,
{ 0x00 , V_32 } ,
{ 0x00 , V_33 } ,
{ V_34 + V_27 , V_28 } ,
} ;
for ( V_53 = 0 ; V_53 < F_28 ( V_61 ) ; V_53 ++ )
F_4 ( V_61 [ V_53 ] . V_59 ,
V_52 + V_61 [ V_53 ] . V_60 ) ;
}
for ( V_53 = 0 ; V_53 < 16 ; V_53 ++ ) {
V_55 [ V_53 ] = F_5 ( V_52 + V_35 ) ;
( void ) F_5 ( V_52 + V_35 ) ;
}
F_4 ( 0x49 , V_52 + V_63 ) ;
V_42 = V_69 ;
V_56 = V_70 ;
V_2 -> V_21 = ( unsigned long ) V_52 ;
V_2 -> V_71 = V_48 ;
V_53 = F_29 ( V_48 , V_72 ,
V_73 , V_74 , V_2 ) ;
if ( V_53 )
return V_53 ;
for ( V_53 = 0 ; V_53 < V_75 ; V_53 ++ )
V_2 -> V_76 [ V_53 ] = V_55 [ V_53 ] ;
F_30 ( L_7 , V_2 -> V_76 ) ;
V_10 . V_51 = V_51 ;
V_10 . V_77 = V_42 ;
V_10 . V_56 = V_56 ;
V_10 . V_78 = 1 ;
V_10 . V_79 = V_42 + V_80 ;
V_10 . V_81 = F_1 ;
V_10 . V_82 = F_11 ;
V_10 . V_83 = F_13 ;
V_10 . V_84 = F_8 ;
V_10 . V_85 = V_57 ;
V_2 -> V_86 = & V_87 ;
F_15 ( V_2 , 0 ) ;
V_6 -> V_88 = V_89 ;
V_54 = F_31 ( V_2 ) ;
if ( V_54 ) {
F_23 ( V_48 , V_2 ) ;
return V_54 ;
}
F_32 ( V_2 , L_8 ,
V_51 , V_50 , V_2 -> V_76 ) ;
return 0 ;
}
static int F_33 ( struct V_46 * V_47 ,
const struct V_90 * V_91 )
{
struct V_1 * V_2 ;
unsigned long V_50 , V_52 ;
int V_54 , V_53 ;
for ( V_53 = F_28 ( V_92 ) - 1 ; V_53 >= 0 ; V_53 -- )
if ( V_47 -> V_93 == V_92 [ V_53 ] . V_93 )
break;
if ( V_53 < 0 )
return - V_58 ;
V_50 = V_47 -> V_94 . V_95 ;
V_52 = V_50 + V_92 [ V_53 ] . V_60 ;
V_2 = F_34 ( 0 ) ;
if ( ! V_2 )
return - V_96 ;
if ( ! F_35 ( V_52 , V_49 * 2 , V_74 ) ) {
F_26 ( V_2 ) ;
return - V_97 ;
}
V_54 = F_27 ( V_2 , V_50 , V_92 [ V_53 ] . V_51 , F_36 ( V_52 ) ) ;
if ( V_54 ) {
F_24 ( V_52 , V_49 * 2 ) ;
F_26 ( V_2 ) ;
return V_54 ;
}
F_37 ( V_47 , V_2 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_98 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_98 ) ;
}
