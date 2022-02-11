static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
F_3 ( 0x01 , V_2 -> V_4 + V_5 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_6 -> V_7 [ V_3 ] = 0x8000 ;
F_3 ( V_6 -> V_7 [ V_3 ] , V_2 -> V_4 + F_4 ( V_3 ) ) ;
V_6 -> V_8 [ V_3 ] = 0 ;
F_3 ( ( ( V_6 -> V_8 [ V_3 ] << 4 ) | V_3 ) ,
V_9 ) ;
}
F_3 ( 0 , V_2 -> V_4 + V_10 ) ;
F_3 ( 0 , V_2 -> V_4 + V_11 ) ;
F_3 ( 0 , V_2 -> V_4 + V_5 ) ;
F_2 ( L_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
int V_17 , V_18 ;
V_18 = F_6 ( V_15 -> V_19 ) ;
F_2 ( L_3 ) ;
for ( V_17 = 0 ; V_17 < V_15 -> V_17 ; V_17 ++ )
V_16 [ V_17 ] = V_6 -> V_7 [ V_18 ] ;
return V_17 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
int V_17 , V_18 ;
V_18 = F_6 ( V_15 -> V_19 ) ;
F_2 ( L_4 ) ;
for ( V_17 = 0 ; V_17 < V_15 -> V_17 ; V_17 ++ ) {
V_6 -> V_7 [ V_18 ] = V_16 [ V_17 ] ;
F_3 ( V_16 [ V_17 ] , V_2 -> V_4 + F_4 ( V_18 ) ) ;
}
return V_17 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
unsigned int V_20 ;
unsigned int V_21 ;
unsigned short V_22 ;
V_20 = 1 << F_6 ( V_15 -> V_19 ) ;
if ( V_20 & 0x00FF )
V_21 = 0x00FF ;
else
V_21 = 0xFF00 ;
switch ( V_16 [ 0 ] ) {
case V_23 :
V_13 -> V_24 &= ~ V_21 ;
break;
case V_25 :
V_13 -> V_24 |= V_21 ;
break;
case V_26 :
V_16 [ 1 ] = ( V_13 -> V_24 & V_21 ) ? V_27 : V_28 ;
return V_15 -> V_17 ;
default:
return - V_29 ;
}
V_22 = 0x0000 ;
if ( ( V_13 -> V_24 & 0x00FF ) == 0 )
V_22 |= 0x0001 ;
if ( ( V_13 -> V_24 & 0xFF00 ) == 0 )
V_22 |= 0x0002 ;
F_3 ( V_22 , V_2 -> V_4 + V_30 ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
if ( V_16 [ 0 ] ) {
V_13 -> V_31 &= ~ V_16 [ 0 ] ;
V_13 -> V_31 |= ( V_16 [ 0 ] & V_16 [ 1 ] ) ;
F_3 ( V_13 -> V_31 , V_2 -> V_4 + V_32 ) ;
}
V_16 [ 1 ] = F_10 ( V_2 -> V_4 + V_33 ) ;
return 2 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_12 * V_13 ;
int V_36 , V_37 , V_38 ;
struct V_39 * V_40 ;
unsigned int V_4 ;
unsigned char V_41 , V_42 , V_43 ;
int V_44 , V_45 ;
const char * V_46 ;
F_12 ( V_47 L_5 ,
V_2 -> V_48 , V_49 -> V_50 ) ;
V_44 = V_35 -> V_51 [ 0 ] ;
V_45 = V_35 -> V_51 [ 1 ] ;
V_36 = F_13 ( V_2 , sizeof( struct V_52 ) ) ;
if ( V_36 < 0 ) {
F_12 ( L_6 ) ;
return - V_53 ;
}
V_46 = L_7 ;
V_40 = NULL ;
while ( NULL != ( V_40 =
F_14 ( V_54 ,
V_49 -> V_55 , V_40 ) ) ) {
if ( V_44 || V_45 ) {
if ( V_44 != V_40 -> V_56 -> V_57
|| V_45 != F_15 ( V_40 -> V_58 ) )
continue;
}
if ( F_16 ( V_40 , L_8 ) ) {
V_46 =
L_9 ;
continue;
}
break;
}
if ( ! V_40 ) {
if ( V_44 || V_45 ) {
F_12 ( V_47 L_10 ,
V_44 , V_45 , V_46 ) ;
} else {
F_12 ( V_47 L_11 , V_46 ) ;
}
return - V_59 ;
}
V_41 = V_40 -> V_56 -> V_57 ;
V_42 = F_15 ( V_40 -> V_58 ) ;
V_43 = F_17 ( V_40 -> V_58 ) ;
V_4 = F_18 ( V_40 , 2 ) ;
F_12 ( V_47 L_12 ,
V_41 , V_42 , V_43 , V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_60 = V_49 -> V_50 ;
V_6 -> V_40 = V_40 ;
V_38 = 0 ;
if ( V_49 -> V_61 )
V_38 ++ ;
if ( V_49 -> V_62 )
V_38 ++ ;
V_36 = F_19 ( V_2 , V_38 ) ;
if ( V_36 < 0 ) {
F_12 ( L_6 ) ;
return V_36 ;
}
F_1 ( V_2 ) ;
V_37 = 0 ;
if ( V_49 -> V_61 ) {
V_13 = V_2 -> V_63 + V_37 ;
V_2 -> V_64 = V_13 ;
V_13 -> type = V_65 ;
V_13 -> V_66 = V_67 | V_68 | V_69 ;
V_13 -> V_70 = V_49 -> V_61 ;
V_13 -> V_71 = V_49 -> V_72 ;
V_13 -> V_73 = V_49 -> V_61 ;
V_13 -> V_74 = V_49 -> V_75 ;
V_13 -> V_76 = F_7 ;
V_13 -> V_77 = F_5 ;
switch ( F_10 ( V_2 -> V_4 + V_78 )
& 0x03 ) {
case 0x00 :
V_13 -> V_24 = 0xFFFF ;
break;
case 0x01 :
V_13 -> V_24 = 0xFF00 ;
break;
case 0x02 :
V_13 -> V_24 = 0x00FF ;
break;
case 0x03 :
V_13 -> V_24 = 0x0000 ;
break;
}
V_13 -> V_31 = F_10 ( V_2 -> V_4 + V_33 ) ;
V_37 ++ ;
}
if ( V_49 -> V_62 ) {
V_13 = V_2 -> V_63 + V_37 ;
V_13 -> type = V_79 ;
V_13 -> V_66 =
V_80 | V_81 | V_68 | V_69 ;
V_13 -> V_70 = V_49 -> V_62 ;
V_13 -> V_71 = 1 ;
V_13 -> V_73 = V_49 -> V_62 ;
V_13 -> V_74 = & V_82 ;
V_13 -> V_83 = F_8 ;
V_13 -> V_84 = F_9 ;
V_37 ++ ;
}
V_6 -> V_85 = 1 ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_86 ) {
if ( V_6 -> V_85 )
F_1 ( V_2 ) ;
if ( V_6 -> V_40 ) {
if ( V_2 -> V_4 )
F_21 ( V_6 -> V_40 ) ;
F_22 ( V_6 -> V_40 ) ;
}
}
}
static int T_1 F_23 ( struct V_39 * V_2 ,
const struct V_87 * V_88 )
{
return F_24 ( V_2 , & V_89 ) ;
}
static void T_2 F_25 ( struct V_39 * V_2 )
{
F_26 ( V_2 ) ;
}
