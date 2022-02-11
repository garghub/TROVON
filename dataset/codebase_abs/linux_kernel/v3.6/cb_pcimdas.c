static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = NULL ;
int V_7 = V_5 -> V_8 [ 0 ] ;
int V_9 = V_5 -> V_8 [ 1 ] ;
int V_10 ;
F_2 (pcidev) {
if ( V_7 || V_9 ) {
if ( V_7 != V_6 -> V_7 -> V_11 ||
V_9 != F_3 ( V_6 -> V_12 ) )
continue;
}
if ( V_6 -> V_13 != V_14 )
continue;
for ( V_10 = 0 ; V_10 < F_4 ( V_15 ) ; V_10 ++ ) {
if ( V_15 [ V_10 ] . V_16 != V_6 -> V_17 )
continue;
V_3 -> V_18 = V_15 + V_10 ;
return V_6 ;
}
}
F_5 ( V_3 -> V_19 ,
L_1 ,
V_7 , V_9 ) ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_20 * V_21 ;
unsigned long V_22 ;
int V_23 ;
if ( F_7 ( V_3 , sizeof( struct V_24 ) ) < 0 )
return - V_25 ;
V_6 = F_1 ( V_3 , V_5 ) ;
if ( ! V_6 )
return - V_26 ;
F_8 ( V_3 , & V_6 -> V_3 ) ;
switch ( V_27 -> V_16 ) {
case 0x56 :
break;
default:
F_9 ( V_3 -> V_19 , L_2 ) ;
F_9 ( V_3 -> V_19 ,
L_3 ) ;
}
if ( F_10 ( V_6 , L_4 ) ) {
F_5 ( V_3 -> V_19 ,
L_5 ) ;
return - V_26 ;
}
V_3 -> V_28 = F_11 ( V_6 , 2 ) ;
V_29 -> V_30 = F_11 ( V_6 , 3 ) ;
V_22 = F_11 ( V_6 , 4 ) ;
V_3 -> V_31 = V_27 -> V_32 ;
V_23 = F_12 ( V_3 , 3 ) ;
if ( V_23 )
return V_23 ;
V_21 = V_3 -> V_33 + 0 ;
V_21 -> type = V_34 ;
V_21 -> V_35 = V_36 | V_37 ;
V_21 -> V_38 = V_27 -> V_39 ;
V_21 -> V_40 = ( 1 << V_27 -> V_41 ) - 1 ;
V_21 -> V_42 = & V_43 ;
V_21 -> V_44 = 1 ;
V_21 -> V_45 = V_46 ;
V_21 = V_3 -> V_33 + 1 ;
V_21 -> type = V_47 ;
V_21 -> V_35 = V_48 ;
V_21 -> V_38 = V_27 -> V_49 ;
V_21 -> V_40 = 1 << V_27 -> V_50 ;
V_21 -> V_42 = & V_43 ;
V_21 -> V_51 = & V_52 ;
V_21 -> V_45 = & V_53 ;
V_21 = V_3 -> V_33 + 2 ;
if ( V_27 -> V_54 )
F_13 ( V_3 , V_21 , NULL , V_22 ) ;
else
V_21 -> type = V_55 ;
return 1 ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_15 ( V_3 ) ;
if ( V_3 -> V_56 )
F_16 ( V_3 -> V_56 , V_3 ) ;
if ( V_6 ) {
if ( V_3 -> V_28 )
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
}
}
static int V_46 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
struct V_57 * V_58 , unsigned int * V_59 )
{
int V_60 , V_10 ;
unsigned int V_61 ;
unsigned int V_62 ;
int V_63 = F_19 ( V_58 -> V_64 ) ;
unsigned short V_65 ;
int V_66 ;
if ( ( F_20 ( V_29 -> V_30 + 2 ) & 0x20 ) == 0 )
V_66 = V_27 -> V_67 ;
else
V_66 = V_27 -> V_39 ;
if ( V_63 > ( V_66 - 1 ) )
return - V_68 ;
V_61 = F_20 ( V_29 -> V_30 + 5 ) ;
if ( ( V_61 & 0x03 ) > 0 ) {
V_61 = V_61 & 0xfd ;
F_21 ( V_61 , V_29 -> V_30 + 5 ) ;
}
F_21 ( 0x01 , V_29 -> V_30 + 6 ) ;
F_21 ( 0x00 , V_29 -> V_30 + 7 ) ;
V_65 = V_63 | ( V_63 << 4 ) ;
F_21 ( V_65 , V_29 -> V_30 + 0 ) ;
for ( V_60 = 0 ; V_60 < V_58 -> V_60 ; V_60 ++ ) {
F_22 ( 0 , V_3 -> V_28 + 0 ) ;
#define F_23 1000
for ( V_10 = 0 ; V_10 < F_23 ; V_10 ++ ) {
V_62 = F_20 ( V_29 -> V_30 + 2 ) & 0x80 ;
if ( ! V_62 )
break;
}
if ( V_10 == F_23 ) {
F_24 ( L_6 ) ;
return - V_68 ;
}
V_61 = F_25 ( V_3 -> V_28 + 0 ) ;
V_59 [ V_60 ] = V_61 ;
}
return V_60 ;
}
static int V_52 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
struct V_57 * V_58 , unsigned int * V_59 )
{
int V_10 ;
int V_63 = F_19 ( V_58 -> V_64 ) ;
for ( V_10 = 0 ; V_10 < V_58 -> V_60 ; V_10 ++ ) {
switch ( V_63 ) {
case 0 :
F_22 ( V_59 [ V_10 ] & 0x0FFF , V_3 -> V_28 + V_69 ) ;
break;
case 1 :
F_22 ( V_59 [ V_10 ] & 0x0FFF , V_3 -> V_28 + V_70 ) ;
break;
default:
return - 1 ;
}
V_29 -> V_71 [ V_63 ] = V_59 [ V_10 ] ;
}
return V_10 ;
}
static int V_53 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
struct V_57 * V_58 , unsigned int * V_59 )
{
int V_10 ;
int V_63 = F_19 ( V_58 -> V_64 ) ;
for ( V_10 = 0 ; V_10 < V_58 -> V_60 ; V_10 ++ )
V_59 [ V_10 ] = V_29 -> V_71 [ V_63 ] ;
return V_10 ;
}
static int T_1 F_26 ( struct V_1 * V_3 ,
const struct V_72 * V_73 )
{
return F_27 ( V_3 , & V_74 ) ;
}
static void T_2 F_28 ( struct V_1 * V_3 )
{
F_29 ( V_3 ) ;
}
