static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 ;
if ( V_5 > 1 )
F_2 ( V_2 , L_1 , V_4 ) ;
F_3 ( F_4 ( V_6 + V_7 ) , V_6 + V_7 ) ;
V_8 . V_9 = 0 ;
V_8 . V_10 = 0 ;
while ( ( F_4 ( V_6 + V_11 ) & V_12 ) == 0 )
if ( F_5 ( V_4 , V_3 + 2 * V_13 / 100 ) ) {
F_6 ( V_2 , L_2 , V_14 ) ;
break;
}
F_3 ( V_12 , V_6 + V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_17 )
{
int V_18 = V_2 -> V_19 ;
int V_20 ;
short * V_21 ;
if ( V_8 . V_10 ) {
F_8 ( V_2 , L_3 ,
V_14 , V_8 . V_10 , V_8 . V_22 ) ;
return;
}
V_8 . V_10 |= 0x01 ;
F_3 ( V_23 + V_24 + V_25 , V_18 + V_26 ) ;
F_3 ( V_27 , V_18 + V_11 ) ;
F_3 ( sizeof( struct V_15 ) , V_18 + V_28 ) ;
F_3 ( 0 , V_18 + V_29 ) ;
F_3 ( 0 , V_18 + V_30 ) ;
F_3 ( V_17 , V_18 + V_31 ) ;
F_3 ( V_32 + V_25 , V_18 + V_26 ) ;
V_21 = ( short * ) V_16 ;
for ( V_20 = 0 ; V_20 < sizeof( struct V_15 ) >> 1 ; V_20 ++ )
* V_21 ++ = F_9 ( V_6 + V_33 ) ;
F_3 ( V_27 , V_18 + V_11 ) ;
V_16 -> V_34 = F_10 ( V_16 -> V_34 ) ;
V_8 . V_10 &= ~ 0x01 ;
}
static void F_11 ( struct V_1 * V_2 , int V_34 ,
struct V_35 * V_36 , int V_37 )
{
int V_18 = V_2 -> V_19 ;
char * V_38 = V_36 -> V_39 ;
short * V_21 ;
int V_20 ;
if ( V_8 . V_10 ) {
F_8 ( V_2 , L_3 ,
V_14 , V_8 . V_10 , V_8 . V_22 ) ;
return;
}
V_8 . V_10 |= 0x01 ;
F_3 ( V_23 + V_24 + V_25 , V_18 + V_26 ) ;
F_3 ( V_27 , V_18 + V_11 ) ;
F_3 ( V_34 & 0xff , V_18 + V_28 ) ;
F_3 ( V_34 >> 8 , V_18 + V_29 ) ;
F_3 ( V_37 & 0xff , V_18 + V_30 ) ;
F_3 ( V_37 >> 8 , V_18 + V_31 ) ;
F_3 ( V_32 + V_25 , V_18 + V_26 ) ;
V_21 = ( short * ) V_38 ;
for ( V_20 = 0 ; V_20 < V_34 > > 1 ; V_20 ++ )
* V_21 ++ = F_9 ( V_6 + V_33 ) ;
if ( V_34 & 0x01 )
V_38 [ V_34 - 1 ] = F_4 ( V_6 + V_33 ) ;
F_3 ( V_27 , V_18 + V_11 ) ;
V_8 . V_10 &= ~ 0x01 ;
}
static void F_12 ( struct V_1 * V_2 , int V_34 ,
const unsigned char * V_38 ,
const int V_40 )
{
int V_18 = V_6 ;
unsigned long V_41 ;
short * V_21 ;
int V_20 ;
if ( V_34 & 0x01 )
V_34 ++ ;
if ( V_8 . V_10 ) {
F_8 ( V_2 , L_3 ,
V_14 , V_8 . V_10 , V_8 . V_22 ) ;
return;
}
V_8 . V_10 |= 0x01 ;
F_3 ( V_24 + V_25 + V_23 , V_18 + V_26 ) ;
F_3 ( V_27 , V_18 + V_11 ) ;
F_3 ( V_34 & 0xff , V_18 + V_28 ) ;
F_3 ( V_34 >> 8 , V_18 + V_29 ) ;
F_3 ( 0x00 , V_18 + V_30 ) ;
F_3 ( V_40 , V_18 + V_31 ) ;
F_3 ( V_42 + V_25 , V_18 + V_26 ) ;
V_21 = ( short * ) V_38 ;
for ( V_20 = 0 ; V_20 < V_34 > > 1 ; V_20 ++ )
F_13 ( * V_21 ++ , V_6 + V_33 ) ;
V_41 = V_4 ;
while ( ( F_4 ( V_6 + V_11 ) & V_27 ) == 0 )
if ( F_5 ( V_4 , V_41 + 2 * V_13 / 100 ) ) {
F_8 ( V_2 , L_4 ) ;
F_1 ( V_2 ) ;
F_14 ( V_2 , 1 ) ;
break;
}
F_3 ( V_27 , V_18 + V_11 ) ;
V_8 . V_10 &= ~ 0x01 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
if ( V_5 > 1 )
F_2 ( V_2 , L_5 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static void T_1 F_19 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
F_21 ( V_2 ) ;
F_22 ( V_45 , V_2 ) ;
F_23 ( F_24 ( V_2 -> V_19 ) , V_46 * 2 ) ;
F_25 ( V_2 ) ;
}
static int T_2 F_26 ( struct V_1 * V_2 ,
unsigned long V_47 , const char * V_48 ,
unsigned long V_49 )
{
int V_50 ;
int V_51 ;
unsigned char V_52 [ 32 ] ;
int V_40 , V_53 ;
static T_3 V_54 [ 16 ] = {
0x00 , 0x02 , 0x04 , 0x06 , 0x08 , 0x0a , 0x0c , 0x0e ,
0x10 , 0x12 , 0x14 , 0x16 , 0x18 , 0x1a , 0x1c , 0x1e ,
} ;
{
unsigned long V_3 = V_4 ;
F_3 ( F_4 ( V_49 + V_7 ) , V_49 + V_7 ) ;
while ( ( F_4 ( V_49 + V_11 ) & V_12 ) == 0 )
if ( F_5 ( V_4 ,
V_3 + 2 * V_13 / 100 ) ) {
F_6 ( V_2 , L_6 ) ;
return - V_55 ;
}
F_3 ( 0xff , V_49 + V_11 ) ;
}
{
static const struct {
T_3 V_56 ;
T_3 V_57 ;
} V_58 [] = {
{ V_23 + V_24 + V_59 , V_26 } ,
{ 0x48 , V_60 } ,
{ 0x00 , V_28 } ,
{ 0x00 , V_29 } ,
{ 0x00 , V_61 } ,
{ 0xFF , V_11 } ,
{ V_62 , V_63 } ,
{ V_64 , V_65 } ,
{ 32 , V_28 } ,
{ 0x00 , V_29 } ,
{ 0x00 , V_30 } ,
{ 0x00 , V_31 } ,
{ V_32 + V_25 , V_26 } ,
} ;
for ( V_50 = 0 ; V_50 < F_27 ( V_58 ) ; V_50 ++ )
F_3 ( V_58 [ V_50 ] . V_56 ,
V_49 + V_58 [ V_50 ] . V_57 ) ;
}
for ( V_50 = 0 ; V_50 < 16 ; V_50 ++ ) {
V_52 [ V_50 ] = F_4 ( V_49 + V_33 ) ;
( void ) F_4 ( V_49 + V_33 ) ;
}
F_3 ( 0x49 , V_49 + V_60 ) ;
V_40 = V_66 ;
V_53 = V_67 ;
V_2 -> V_19 = V_49 ;
V_2 -> V_68 = V_45 ;
V_50 = F_28 ( V_45 , V_69 ,
V_70 , V_71 , V_2 ) ;
if ( V_50 )
return V_50 ;
for ( V_50 = 0 ; V_50 < V_72 ; V_50 ++ )
V_2 -> V_73 [ V_50 ] = V_52 [ V_50 ] ;
F_29 ( L_7 , V_2 -> V_73 ) ;
V_8 . V_48 = V_48 ;
V_8 . V_74 = V_40 ;
V_8 . V_53 = V_53 ;
V_8 . V_75 = 1 ;
V_8 . V_76 = V_40 + V_77 ;
V_8 . V_78 = F_1 ;
V_8 . V_79 = F_11 ;
V_8 . V_80 = F_12 ;
V_8 . V_81 = F_7 ;
V_8 . V_82 = V_54 ;
V_2 -> V_83 = & V_84 ;
F_14 ( V_2 , 0 ) ;
V_51 = F_30 ( V_2 ) ;
if ( V_51 ) {
F_22 ( V_45 , V_2 ) ;
return V_51 ;
}
F_31 ( V_2 , L_8 ,
V_48 , V_47 , V_2 -> V_73 ) ;
return 0 ;
}
static int T_2 F_32 ( struct V_43 * V_44 ,
const struct V_85 * V_86 )
{
struct V_1 * V_2 ;
unsigned long V_47 , V_49 ;
int V_51 , V_50 ;
for ( V_50 = F_27 ( V_87 ) - 1 ; V_50 >= 0 ; V_50 -- )
if ( V_44 -> V_88 == V_87 [ V_50 ] . V_88 )
break;
if ( V_50 < 0 )
return - V_55 ;
V_47 = V_44 -> V_89 . V_90 ;
V_49 = V_47 + V_87 [ V_50 ] . V_57 ;
V_2 = F_33 ( 0 ) ;
if ( ! V_2 )
return - V_91 ;
if ( ! F_34 ( V_49 , V_46 * 2 , V_71 ) ) {
F_25 ( V_2 ) ;
return - V_92 ;
}
V_51 = F_26 ( V_2 , V_47 , V_87 [ V_50 ] . V_48 , F_35 ( V_49 ) ) ;
if ( V_51 ) {
F_23 ( V_49 , V_46 * 2 ) ;
F_25 ( V_2 ) ;
return V_51 ;
}
F_36 ( V_44 , V_2 ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
return F_38 ( & V_93 ) ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_93 ) ;
}
