static inline T_1 F_1 ( T_1 V_1 )
{
if ( V_1 & 1 )
return V_1 - 1 + V_2 ;
return V_1 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return V_1 ;
}
void F_3 ( T_1 V_3 , T_1 V_1 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) F_1 ( V_1 ) ;
* V_4 = F_4 ( V_3 ) ;
}
T_3 F_5 ( T_1 V_1 )
{
T_2 * V_4 , V_3 ;
V_4 = ( T_2 * ) F_1 ( V_1 ) ;
V_3 = * V_4 ;
return ( T_3 ) ( F_4 ( V_3 ) & 0xff ) ;
}
void F_6 ( T_1 V_1 , void * V_5 , int V_6 )
{
T_2 * V_4 , V_3 ;
T_3 * V_7 ;
V_7 = ( T_3 * ) V_5 ;
V_4 = ( T_2 * ) F_2 ( V_1 ) ;
for (; ( V_6 > 0 ) ; V_6 -- ) {
V_3 = * V_4 ;
* V_7 ++ = F_4 ( V_3 ) ;
}
}
void F_7 ( T_1 V_1 , void * V_5 , int V_6 )
{
volatile T_4 * V_4 ;
T_4 V_8 , * V_7 ;
V_7 = ( T_4 * ) V_5 ;
V_4 = ( volatile T_4 * ) F_2 ( V_1 ) ;
for (; ( V_6 > 0 ) ; V_6 -- ) {
V_8 = * V_4 ;
* V_7 ++ = F_8 ( V_8 ) ;
}
}
void F_9 ( T_1 V_1 , const void * V_5 , int V_6 )
{
T_2 * V_4 , V_3 ;
T_3 * V_7 ;
V_7 = ( T_3 * ) V_5 ;
V_4 = ( T_2 * ) F_2 ( V_1 ) ;
for (; ( V_6 > 0 ) ; V_6 -- ) {
V_3 = * V_7 ++ ;
* V_4 = F_4 ( V_3 ) ;
}
}
void F_10 ( T_1 V_1 , const void * V_5 , int V_6 )
{
volatile T_4 * V_4 ;
T_4 V_8 , * V_7 ;
V_7 = ( T_4 * ) V_5 ;
V_4 = ( volatile T_4 * ) F_2 ( V_1 ) ;
for (; ( V_6 > 0 ) ; V_6 -- ) {
V_8 = * V_7 ++ ;
* V_4 = F_8 ( V_8 ) ;
}
}
static void F_11 ( struct V_9 * V_10 )
{
unsigned long V_11 = V_12 ;
T_1 V_1 = V_10 -> V_13 ;
struct V_14 * V_15 = F_12 ( V_10 ) ;
F_13 ( V_15 , V_16 , V_10 , L_1 , V_12 ) ;
F_3 ( F_5 ( V_1 + V_17 ) , V_1 + V_17 ) ;
V_18 . V_19 = 0 ;
V_18 . V_20 = 0 ;
while ( ( F_5 ( V_1 + V_21 ) & V_22 ) == 0 ) {
if ( F_14 ( V_12 , V_11 + 2 * V_23 / 100 ) ) {
F_15 ( V_10 , L_2 , V_24 ) ;
break;
}
}
F_3 ( V_22 , V_1 + V_21 ) ;
}
static void F_16 ( const char * V_25 , struct V_9 * V_10 ,
struct V_14 * V_15 )
{
F_17 ( V_10 , L_3 ,
V_25 , V_15 -> V_20 , V_15 -> V_26 ) ;
}
static void F_18 ( struct V_9 * V_10 ,
struct V_27 * V_28 , int V_29 )
{
struct V_14 * V_15 = F_12 ( V_10 ) ;
T_1 V_1 = V_10 -> V_13 ;
if ( V_15 -> V_20 ) {
F_16 ( V_24 , V_10 , V_15 ) ;
return;
}
V_15 -> V_20 |= 0x01 ;
F_3 ( V_30 + V_31 + V_32 , V_1 + V_33 ) ;
F_3 ( V_34 , V_1 + V_21 ) ;
F_3 ( sizeof( struct V_27 ) , V_1 + V_35 ) ;
F_3 ( 0 , V_1 + V_36 ) ;
F_3 ( 0 , V_1 + V_37 ) ;
F_3 ( V_29 , V_1 + V_38 ) ;
F_3 ( V_39 + V_32 , V_1 + V_33 ) ;
F_7 ( V_1 + V_40 , V_28 , sizeof( struct V_27 ) >> 1 ) ;
F_19 ( V_34 , V_1 + V_21 ) ;
V_15 -> V_20 &= ~ 0x01 ;
V_28 -> V_41 = F_20 ( V_28 -> V_41 ) ;
}
static void F_21 ( struct V_9 * V_10 , int V_41 ,
struct V_42 * V_43 , int V_44 )
{
struct V_14 * V_15 = F_12 ( V_10 ) ;
T_1 V_1 = V_10 -> V_13 ;
char * V_7 = V_43 -> V_45 ;
if ( V_15 -> V_20 ) {
F_16 ( V_24 , V_10 , V_15 ) ;
return;
}
V_15 -> V_20 |= 0x01 ;
F_3 ( V_30 + V_31 + V_32 , V_1 + V_33 ) ;
F_3 ( V_34 , V_1 + V_21 ) ;
F_3 ( V_41 & 0xff , V_1 + V_35 ) ;
F_3 ( V_41 >> 8 , V_1 + V_36 ) ;
F_3 ( V_44 & 0xff , V_1 + V_37 ) ;
F_3 ( V_44 >> 8 , V_1 + V_38 ) ;
F_3 ( V_39 + V_32 , V_1 + V_33 ) ;
F_7 ( V_1 + V_40 , V_7 , V_41 >> 1 ) ;
if ( V_41 & 1 )
V_7 [ V_41 - 1 ] = F_5 ( V_1 + V_40 ) ;
F_3 ( V_34 , V_1 + V_21 ) ;
V_15 -> V_20 &= ~ 0x01 ;
}
static void F_22 ( struct V_9 * V_10 , int V_41 ,
const unsigned char * V_7 ,
const int V_46 )
{
struct V_14 * V_15 = F_12 ( V_10 ) ;
T_1 V_1 = V_10 -> V_13 ;
unsigned long V_47 ;
if ( V_41 & 0x1 )
V_41 ++ ;
if ( V_15 -> V_20 ) {
F_16 ( V_24 , V_10 , V_15 ) ;
return;
}
V_15 -> V_20 |= 0x01 ;
F_3 ( V_31 + V_32 + V_30 , V_1 + V_33 ) ;
F_3 ( V_34 , V_1 + V_21 ) ;
F_3 ( V_41 & 0xff , V_1 + V_35 ) ;
F_3 ( V_41 >> 8 , V_1 + V_36 ) ;
F_3 ( 0x00 , V_1 + V_37 ) ;
F_3 ( V_46 , V_1 + V_38 ) ;
F_3 ( V_48 + V_32 , V_1 + V_33 ) ;
F_10 ( V_1 + V_40 , V_7 , V_41 >> 1 ) ;
V_47 = V_12 ;
while ( ( F_5 ( V_1 + V_21 ) & V_34 ) == 0 ) {
if ( F_14 ( V_12 , V_47 + 2 * V_23 / 100 ) ) {
F_15 ( V_10 , L_4 ) ;
F_11 ( V_10 ) ;
F_23 ( V_10 , 1 ) ;
break;
}
}
F_3 ( V_34 , V_1 + V_21 ) ;
V_15 -> V_20 &= ~ 0x01 ;
}
static int F_24 ( struct V_9 * V_10 )
{
static T_1 V_49 [] = {
0x00 , 0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 ,
0x08 , 0x09 , 0x0a , 0x0b , 0x0c , 0x0d , 0x0e , 0x0f ,
} ;
struct V_14 * V_15 = F_12 ( V_10 ) ;
unsigned char V_50 [ 32 ] ;
T_1 V_1 = V_10 -> V_13 ;
int V_46 , V_51 ;
int V_52 , V_53 ;
F_11 ( V_10 ) ;
{
static const struct {
T_1 V_54 ;
T_1 V_55 ;
} V_56 [] = {
{ V_30 + V_31 + V_57 , V_33 } ,
{ 0x48 , V_58 } ,
{ 0x00 , V_35 } ,
{ 0x00 , V_36 } ,
{ 0x00 , V_59 } ,
{ 0xFF , V_21 } ,
{ V_60 , V_61 } ,
{ V_62 , V_63 } ,
{ 32 , V_35 } ,
{ 0x00 , V_36 } ,
{ 0x00 , V_37 } ,
{ 0x00 , V_38 } ,
{ V_39 + V_32 , V_33 } ,
} ;
for ( V_52 = 0 ; V_52 < F_25 ( V_56 ) ; V_52 ++ ) {
F_3 ( V_56 [ V_52 ] . V_54 ,
V_1 + V_56 [ V_52 ] . V_55 ) ;
}
}
for ( V_52 = 0 ; V_52 < 16 ; V_52 ++ ) {
V_50 [ V_52 ] = F_5 ( V_1 + V_40 ) ;
F_5 ( V_1 + V_40 ) ;
}
F_3 ( 0x49 , V_1 + V_58 ) ;
V_46 = V_64 ;
V_51 = V_65 ;
V_53 = F_26 ( V_10 -> V_66 , V_67 , 0 , V_10 -> V_68 , V_10 ) ;
if ( V_53 )
return V_53 ;
for ( V_52 = 0 ; V_52 < V_69 ; V_52 ++ )
V_10 -> V_70 [ V_52 ] = V_50 [ V_52 ] ;
F_27 ( V_10 , L_5 , V_10 -> V_70 ) ;
V_15 -> V_68 = L_6 ;
V_15 -> V_71 = V_46 ;
V_15 -> V_51 = V_51 ;
V_15 -> V_72 = 1 ;
V_15 -> V_73 = V_46 + V_74 ;
V_15 -> V_75 = F_11 ;
V_15 -> V_76 = F_21 ;
V_15 -> V_77 = F_22 ;
V_15 -> V_78 = F_18 ;
V_15 -> V_79 = V_49 ;
V_10 -> V_80 = & V_81 ;
F_23 ( V_10 , 0 ) ;
V_53 = F_28 ( V_10 ) ;
if ( V_53 ) {
F_29 ( V_10 -> V_66 , V_10 ) ;
return V_53 ;
}
F_30 ( V_10 , L_7 ,
V_1 , V_10 -> V_66 , V_10 -> V_70 ) ;
return 0 ;
}
static int F_31 ( struct V_82 * V_83 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_84 * V_85 , * V_66 ;
T_5 V_86 ;
int V_53 ;
V_66 = F_32 ( V_83 , V_87 , 0 ) ;
if ( V_66 == NULL ) {
F_33 ( & V_83 -> V_10 , L_8 ) ;
return - V_88 ;
}
V_85 = F_32 ( V_83 , V_89 , 0 ) ;
if ( V_85 == NULL ) {
F_33 ( & V_83 -> V_10 , L_9 ) ;
return - V_88 ;
}
V_86 = F_34 ( V_85 ) ;
if ( ! F_35 ( V_85 -> V_90 , V_86 , V_83 -> V_68 ) )
return - V_91 ;
V_10 = F_36 ( 0 ) ;
if ( V_10 == NULL ) {
F_37 ( V_85 -> V_90 , V_86 ) ;
return - V_92 ;
}
F_38 ( V_10 , & V_83 -> V_10 ) ;
F_39 ( V_83 , V_10 ) ;
V_15 = F_12 ( V_10 ) ;
V_15 -> V_93 = V_94 ;
V_10 -> V_66 = V_66 -> V_90 ;
V_10 -> V_13 = V_85 -> V_90 ;
V_53 = F_24 ( V_10 ) ;
if ( V_53 ) {
F_37 ( V_85 -> V_90 , V_86 ) ;
F_40 ( V_10 ) ;
return V_53 ;
}
return 0 ;
}
static int F_41 ( struct V_82 * V_83 )
{
struct V_9 * V_10 = F_42 ( V_83 ) ;
struct V_84 * V_85 ;
F_43 ( V_10 ) ;
V_85 = F_32 ( V_83 , V_89 , 0 ) ;
if ( V_85 )
F_37 ( V_85 -> V_90 , F_34 ( V_85 ) ) ;
F_40 ( V_10 ) ;
return 0 ;
}
