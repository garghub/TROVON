static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = & V_3 [ 0 ] ;
while ( V_4 -> V_5 ) {
if ( V_4 -> V_5 == V_2 -> V_5 &&
V_4 -> V_6 == V_2 -> V_7 &&
V_4 -> V_8 == V_2 -> V_9 )
return 1 ;
V_4 ++ ;
}
return 0 ;
}
static int F_2 ( struct V_10 * V_11 )
{
return 0x40 + ( 4 * V_11 -> V_12 -> V_13 -> V_14 ) + ( 2 * V_11 -> V_15 ) ;
}
static int F_3 ( struct V_10 * V_11 )
{
struct V_16 * V_13 = V_11 -> V_12 -> V_13 ;
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_19 = 0x40 ;
T_1 V_20 ;
F_5 ( V_17 , 0x54 , & V_20 ) ;
if ( V_20 & 0x40000000 )
V_19 = 0x70 ;
return V_19 + ( 8 * V_13 -> V_14 ) + ( 4 * V_11 -> V_15 ) ;
}
static int F_6 ( struct V_16 * V_13 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
T_2 V_21 ;
F_7 ( V_17 , 0x50 + 2 * V_13 -> V_14 , & V_21 ) ;
if ( ( V_21 & 0x8000 ) && ! F_1 ( V_17 ) )
return V_22 ;
return V_23 ;
}
static int F_8 ( struct V_16 * V_13 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
T_3 V_21 ;
F_9 ( V_17 , 0x48 , & V_21 ) ;
V_21 >>= V_13 -> V_14 ;
if ( ( V_21 & 0x10 ) && ! F_1 ( V_17 ) )
return V_22 ;
return V_23 ;
}
static int F_10 ( struct V_24 * V_12 , unsigned long V_25 )
{
static const struct V_26 V_27 [] = {
{ 0x4aU , 1U , 0x02UL , 0x02UL } ,
{ 0x4aU , 1U , 0x04UL , 0x04UL } ,
} ;
struct V_16 * V_13 = V_12 -> V_13 ;
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
if ( ! F_11 ( V_17 , & V_27 [ V_13 -> V_14 ] ) )
return - V_28 ;
F_12 ( V_17 , 0x4B , 0 ) ;
return F_13 ( V_12 , V_25 ) ;
}
static void F_14 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
T_3 V_29 ;
T_3 V_30 = 0x11 ;
V_30 <<= ( 2 * V_13 -> V_14 ) ;
V_30 <<= V_11 -> V_15 ;
F_9 ( V_17 , 0x4B , & V_29 ) ;
V_29 &= ~ V_30 ;
if ( V_11 -> V_31 == V_32 )
V_29 |= V_30 ;
F_12 ( V_17 , 0x4B , V_29 ) ;
}
static void F_15 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_19 = F_2 ( V_11 ) ;
T_3 V_33 , V_34 ;
int V_35 = V_11 -> V_36 - V_37 ;
static const T_3 V_38 [] = { 0x00 , 0x07 , 0x04 , 0x03 , 0x01 } ;
static const T_3 V_39 [] = { 0x00 , 0x06 , 0x04 , 0x03 , 0x03 } ;
F_14 ( V_13 , V_11 ) ;
F_9 ( V_17 , V_19 , & V_33 ) ;
F_9 ( V_17 , V_19 + 1 , & V_34 ) ;
V_33 &= ~ 0x0F ;
V_34 &= ~ 0x07 ;
V_33 |= V_38 [ V_35 ] ;
V_34 |= V_39 [ V_35 ] ;
F_12 ( V_17 , V_19 , V_33 ) ;
F_12 ( V_17 , V_19 + 1 , V_34 ) ;
}
static void F_16 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_19 = F_2 ( V_11 ) ;
int V_35 = V_11 -> V_36 - V_37 ;
static const T_3 V_40 [] = { 0x00 , 0x67 , 0x44 , 0x33 , 0x31 } ;
F_14 ( V_13 , V_11 ) ;
F_12 ( V_17 , V_19 , V_40 [ V_35 ] ) ;
}
static void F_17 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_19 ;
T_1 V_33 ;
int V_35 = V_11 -> V_36 - V_37 ;
static const T_1 V_41 [] = {
0x28269000 ,
0x0C266000 ,
0x04263000 ,
0x0C0A3000 ,
0x05093000
} ;
static const T_1 V_42 [] = {
0x1E1C6000 ,
0x091C4000 ,
0x031C2000 ,
0x09072000 ,
0x04062000
} ;
F_14 ( V_13 , V_11 ) ;
V_19 = F_3 ( V_11 ) ;
F_5 ( V_17 , V_19 , & V_33 ) ;
V_33 &= 0xC0C00FFF ;
if ( V_33 & 0x08 )
V_33 |= V_41 [ V_35 ] ;
else
V_33 |= V_42 [ V_35 ] ;
F_12 ( V_17 , V_19 , V_33 ) ;
}
static void F_18 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_35 = V_11 -> V_43 - V_44 ;
int V_45 = F_2 ( V_11 ) ;
T_2 V_46 ;
static const T_2 V_47 [] = { 0x008 , 0x302 , 0x301 } ;
static const T_2 V_48 [] = { 0xE000 , 0xC000 , 0xA000 } ;
F_7 ( V_17 , V_45 , & V_46 ) ;
if ( V_11 -> V_43 < V_49 ) {
V_46 &= ~ 0x870F ;
V_46 |= V_47 [ V_35 ] ;
} else {
V_35 = V_11 -> V_43 - V_49 ;
V_46 &= ~ 0x6000 ;
V_46 |= V_48 [ V_35 ] ;
}
F_19 ( V_17 , V_45 , V_46 ) ;
}
static void F_20 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_35 = V_11 -> V_43 - V_44 ;
int V_45 = F_2 ( V_11 ) ;
T_2 V_46 ;
static const T_2 V_47 [] = { 0x008 , 0x302 , 0x301 } ;
static const T_2 V_48 [] = { 0xF000 , 0xD000 , 0xB000 , 0xA000 , 0x9000 , 0x8000 } ;
F_7 ( V_17 , V_45 , & V_46 ) ;
if ( V_11 -> V_43 < V_49 ) {
V_46 &= ~ 0x870F ;
V_46 |= V_47 [ V_35 ] ;
} else {
V_35 = V_11 -> V_43 - V_49 ;
V_46 &= ~ 0xF000 ;
V_46 |= V_48 [ V_35 ] ;
}
F_19 ( V_17 , V_45 , V_46 ) ;
}
static void F_21 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_35 = V_11 -> V_43 - V_44 ;
int V_45 = F_2 ( V_11 ) ;
T_3 V_46 ;
static const T_3 V_48 [] = { 0x8B , 0x87 , 0x85 , 0x83 , 0x82 , 0x81 } ;
F_9 ( V_17 , V_45 + 1 , & V_46 ) ;
if ( V_11 -> V_43 < V_49 ) {
} else {
V_35 = V_11 -> V_43 - V_49 ;
V_46 &= ~ 0x8F ;
V_46 |= V_48 [ V_35 ] ;
}
F_12 ( V_17 , V_45 + 1 , V_46 ) ;
}
static void F_22 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_35 = V_11 -> V_43 - V_44 ;
int V_45 = F_2 ( V_11 ) ;
T_3 V_46 ;
static const T_3 V_48 [] = { 0x8F , 0x8A , 0x87 , 0x85 , 0x83 , 0x82 , 0x81 } ;
F_9 ( V_17 , V_45 + 1 , & V_46 ) ;
if ( V_11 -> V_43 < V_49 ) {
} else {
V_35 = V_11 -> V_43 - V_49 ;
V_46 &= ~ 0x8F ;
V_46 |= V_48 [ V_35 ] ;
}
F_12 ( V_17 , V_45 + 1 , V_46 ) ;
}
static void F_23 ( struct V_16 * V_13 , struct V_10 * V_11 )
{
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_19 ;
T_1 V_33 ;
V_19 = F_3 ( V_11 ) ;
F_5 ( V_17 , V_19 , & V_33 ) ;
if ( V_11 -> V_43 < V_49 ) {
static const T_1 V_50 [] = { 0x19154000 , 0x06072000 , 0x04062000 } ;
static const T_1 V_51 [] = { 0x221C6000 , 0x0C0A3000 , 0x05093000 } ;
int V_35 = V_11 -> V_43 - V_44 ;
V_33 &= 0xC0C00FFF ;
V_33 &= ~ 0x00000004 ;
if ( V_33 & 0x08 )
V_33 |= V_51 [ V_35 ] ;
else
V_33 |= V_50 [ V_35 ] ;
} else {
static const T_1 V_50 [] = { 0x6B0 , 0x470 , 0x350 , 0x140 , 0x120 , 0x110 , 0x000 } ;
static const T_1 V_51 [] = { 0x9F0 , 0x6A0 , 0x470 , 0x250 , 0x230 , 0x220 , 0x210 } ;
int V_35 = V_11 -> V_43 - V_49 ;
V_33 &= ~ 0x00000FF0 ;
V_33 |= 0x00000004 ;
if ( V_33 & 0x08 )
V_33 |= V_51 [ V_35 ] ;
else
V_33 |= V_50 [ V_35 ] ;
}
F_24 ( V_17 , V_19 , V_33 ) ;
}
static unsigned long F_25 ( struct V_10 * V_11 , unsigned long V_30 )
{
struct V_16 * V_13 = V_11 -> V_12 -> V_13 ;
struct V_1 * V_17 = F_4 ( V_13 -> V_18 -> V_2 ) ;
int V_19 = F_3 ( V_11 ) ;
T_1 V_33 ;
F_5 ( V_17 , V_19 , & V_33 ) ;
if ( ! ( V_33 & 0x08 ) )
V_30 &= ~ ( 0xC0 << V_52 ) ;
return V_30 ;
}
static void F_26 ( struct V_1 * V_17 , struct V_53 * V_54 )
{
T_2 V_55 ;
T_3 V_56 ;
if ( V_54 -> V_57 == & V_58 ) {
F_7 ( V_17 , 0x50 , & V_55 ) ;
if ( V_55 & 0x08 )
F_19 ( V_17 , 0x50 , V_55 & ~ 0x08 ) ;
F_7 ( V_17 , 0x52 , & V_55 ) ;
if ( V_55 & 0x08 )
F_19 ( V_17 , 0x52 , V_55 & ~ 0x08 ) ;
return;
}
if ( V_54 -> V_57 == & V_59 || V_54 -> V_57 == & V_60 ) {
F_12 ( V_17 , V_61 , 0x80 ) ;
F_9 ( V_17 , 0x49 , & V_56 ) ;
if ( ! ( V_56 & 0x01 ) )
F_12 ( V_17 , 0x49 , V_56 | 0x01 ) ;
return;
}
if ( V_54 -> V_57 == & V_62 || V_54 -> V_57 == & V_63 ) {
F_12 ( V_17 , V_61 , 0x80 ) ;
F_9 ( V_17 , 0x52 , & V_56 ) ;
if ( ! ( V_56 & 0x04 ) )
F_12 ( V_17 , 0x52 , V_56 | 0x04 ) ;
return;
}
if ( V_54 -> V_57 == & V_64 ) {
F_9 ( V_17 , V_65 , & V_56 ) ;
if ( ( V_56 & 0x0F ) != 0x00 )
F_12 ( V_17 , V_65 , V_56 & 0xF0 ) ;
}
if ( V_54 -> V_57 == & V_66 || V_54 -> V_57 == & V_64 ) {
F_9 ( V_17 , 0x52 , & V_56 ) ;
if ( ! ( V_56 & 0x08 ) )
F_12 ( V_17 , 0x52 , V_56 | 0x08 ) ;
return;
}
F_27 () ;
}
static int F_28 ( struct V_1 * V_17 , const struct V_67 * V_68 )
{
const struct V_69 * V_70 [] = { NULL , NULL } ;
struct V_1 * V_18 = NULL ;
struct V_53 * V_71 = NULL ;
struct V_53 * V_72 ;
int V_73 ;
static struct V_53 V_74 [] = {
{ 0x0968 , & V_58 } ,
{ 0x0966 , & V_58 } ,
{ 0x0965 , & V_58 } ,
{ 0x0745 , & V_60 } ,
{ 0x0735 , & V_60 } ,
{ 0x0733 , & V_60 } ,
{ 0x0635 , & V_60 } ,
{ 0x0633 , & V_60 } ,
{ 0x0730 , & V_63 } ,
{ 0x0550 , & V_63 } ,
{ 0x0640 , & V_62 } ,
{ 0x0630 , & V_62 } ,
{ 0x0620 , & V_62 } ,
{ 0x0540 , & V_62 } ,
{ 0x0530 , & V_62 } ,
{ 0x5600 , & V_64 } ,
{ 0x5598 , & V_64 } ,
{ 0x5597 , & V_64 } ,
{ 0x5591 , & V_64 } ,
{ 0x5582 , & V_64 } ,
{ 0x5581 , & V_64 } ,
{ 0x5596 , & V_66 } ,
{ 0x5571 , & V_66 } ,
{ 0x5517 , & V_66 } ,
{ 0x5511 , & V_66 } ,
{ 0 }
} ;
static struct V_53 V_75 = {
0x0 , & V_59
} ;
static struct V_53 V_76 = {
0x0 , & V_58
} ;
static struct V_53 V_77 = {
0x0 , & V_63
} ;
static struct V_53 V_78 = {
0x0 , & V_60
} ;
F_29 ( & V_17 -> V_2 , V_79 ) ;
V_73 = F_30 ( V_17 ) ;
if ( V_73 )
return V_73 ;
for ( V_72 = & V_74 [ 0 ] ; V_72 -> V_5 ; V_72 ++ ) {
V_18 = F_31 ( V_80 , V_72 -> V_5 , NULL ) ;
if ( V_18 != NULL ) {
V_71 = V_72 ;
if ( V_72 -> V_5 == 0x630 ) {
if ( V_18 -> V_81 >= 0x30 )
V_71 = & V_77 ;
}
break;
}
}
if ( V_71 == NULL ) {
T_1 V_82 ;
T_2 V_83 ;
F_5 ( V_17 , 0x54 , & V_82 ) ;
F_24 ( V_17 , 0x54 , V_82 & 0x7fffffff ) ;
F_7 ( V_17 , V_84 , & V_83 ) ;
F_24 ( V_17 , 0x54 , V_82 ) ;
switch( V_83 ) {
case 0x5518 :
F_32 ( & V_17 -> V_2 ,
L_1 ) ;
V_71 = & V_76 ;
if ( ( V_82 & 0x40000000 ) == 0 ) {
F_24 ( V_17 , 0x54 , V_82 | 0x40000000 ) ;
F_32 ( & V_17 -> V_2 ,
L_2 ) ;
}
break;
case 0x0180 :
V_71 = & V_76 ;
break;
case 0x1180 :
V_71 = & V_76 ;
break;
}
}
if ( V_71 == NULL ) {
struct V_1 * V_85 ;
T_2 V_83 ;
T_3 V_86 ;
T_3 V_87 ;
F_9 ( V_17 , 0x4a , & V_87 ) ;
F_12 ( V_17 , 0x4a , V_87 | 0x10 ) ;
F_7 ( V_17 , V_84 , & V_83 ) ;
F_12 ( V_17 , 0x4a , V_87 ) ;
switch( V_83 ) {
case 0x5517 :
V_85 = F_33 ( V_17 -> V_88 , 0x10 ) ;
if ( V_85 == NULL )
break;
F_9 ( V_17 , 0x49 , & V_86 ) ;
F_34 ( V_85 ) ;
if ( V_85 -> V_81 == 0x10 && ( V_86 & 0x80 ) ) {
V_71 = & V_75 ;
break;
}
V_71 = & V_78 ;
break;
}
}
F_34 ( V_18 ) ;
if ( V_71 == NULL )
return - V_89 ;
V_70 [ 0 ] = V_71 -> V_57 ;
F_26 ( V_17 , V_71 ) ;
return F_35 ( V_17 , V_70 , & V_90 , V_71 , 0 ) ;
}
static int F_36 ( struct V_1 * V_17 )
{
struct V_91 * V_18 = F_37 ( V_17 ) ;
int V_73 ;
V_73 = F_38 ( V_17 ) ;
if ( V_73 )
return V_73 ;
F_26 ( V_17 , V_18 -> V_92 ) ;
F_39 ( V_18 ) ;
return 0 ;
}
