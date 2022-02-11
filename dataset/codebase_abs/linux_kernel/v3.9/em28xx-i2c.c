static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_5 )
{
int V_6 ;
int V_7 ;
T_1 V_8 [ 6 ] ;
if ( V_5 < 1 || V_5 > 4 )
return - V_9 ;
F_2 ( V_5 < 1 || V_5 > 4 ) ;
V_8 [ 5 ] = 0x80 + V_5 - 1 ;
V_8 [ 4 ] = V_3 ;
V_8 [ 3 ] = V_4 [ 0 ] ;
if ( V_5 > 1 )
V_8 [ 2 ] = V_4 [ 1 ] ;
if ( V_5 > 2 )
V_8 [ 1 ] = V_4 [ 2 ] ;
if ( V_5 > 3 )
V_8 [ 0 ] = V_4 [ 3 ] ;
V_6 = V_2 -> V_10 ( V_2 , 4 - V_5 , & V_8 [ 4 - V_5 ] , 2 + V_5 ) ;
if ( V_6 != 2 + V_5 ) {
F_3 ( L_1
L_2 , V_3 , V_6 ) ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
for ( V_7 = V_12 ; V_7 > 0 ;
V_7 -= 5 ) {
V_6 = V_2 -> V_13 ( V_2 , 0x05 ) ;
if ( V_6 == 0x80 + V_5 - 1 ) {
return V_5 ;
} else if ( V_6 == 0x94 + V_5 - 1 ) {
return - V_14 ;
} else if ( V_6 < 0 ) {
F_3 ( L_3
L_4 , V_6 ) ;
return V_6 ;
}
F_4 ( 5 ) ;
}
F_3 ( L_5 , V_3 ) ;
return - V_11 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_5 )
{
T_1 V_15 [ 4 ] ;
int V_6 ;
int V_16 ;
int V_17 ;
if ( V_5 < 1 || V_5 > 4 )
return - V_9 ;
V_15 [ 1 ] = 0x84 + V_5 - 1 ;
V_15 [ 0 ] = V_3 ;
V_6 = V_2 -> V_10 ( V_2 , 0x04 , V_15 , 2 ) ;
if ( V_6 != 2 ) {
F_3 ( L_6
L_2 , V_3 , V_6 ) ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
for ( V_16 = V_12 ; V_16 > 0 ;
V_16 -= 5 ) {
V_6 = V_2 -> V_13 ( V_2 , 0x05 ) ;
if ( V_6 == 0x84 + V_5 - 1 ) {
break;
} else if ( V_6 == 0x94 + V_5 - 1 ) {
return - V_14 ;
} else if ( V_6 < 0 ) {
F_3 ( L_3
L_4 , V_6 ) ;
return V_6 ;
}
F_4 ( 5 ) ;
}
if ( V_6 != 0x84 + V_5 - 1 )
F_3 ( L_7 , V_3 ) ;
V_6 = V_2 -> V_18 ( V_2 , 0x00 , 4 - V_5 , V_15 , V_5 ) ;
if ( V_6 != V_5 ) {
F_3 ( L_8
L_9
L_2 , V_3 , V_6 ) ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
for ( V_17 = 0 ; V_17 < V_5 ; V_17 ++ )
V_4 [ V_17 ] = V_15 [ V_5 - 1 - V_17 ] ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_6 ;
V_6 = F_5 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 == 1 )
return 0 ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 , int V_19 )
{
int V_7 , V_6 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_9 ;
V_6 = V_2 -> V_20 ( V_2 , V_19 ? 2 : 3 , V_3 , V_4 , V_5 ) ;
if ( V_6 != V_5 ) {
if ( V_6 < 0 ) {
F_3 ( L_10
L_2 , V_3 , V_6 ) ;
return V_6 ;
} else {
F_3 ( L_11
L_12 ,
V_5 , V_3 , V_6 ) ;
return - V_11 ;
}
}
for ( V_7 = V_12 ; V_7 > 0 ;
V_7 -= 5 ) {
V_6 = V_2 -> V_13 ( V_2 , 0x05 ) ;
if ( V_6 == 0 ) {
return V_5 ;
} else if ( V_6 == 0x10 ) {
return - V_14 ;
} else if ( V_6 < 0 ) {
F_3 ( L_13
L_14 , V_6 ) ;
return V_6 ;
}
F_4 ( 5 ) ;
}
F_3 ( L_5 , V_3 ) ;
return - V_11 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , T_2 V_5 )
{
int V_6 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_9 ;
V_6 = V_2 -> V_18 ( V_2 , 2 , V_3 , V_4 , V_5 ) ;
if ( V_6 != V_5 ) {
if ( V_6 < 0 ) {
F_3 ( L_15
L_2 , V_3 , V_6 ) ;
return V_6 ;
} else {
F_3 ( L_16
L_17 ,
V_5 , V_3 , V_6 ) ;
return - V_11 ;
}
}
V_6 = V_2 -> V_13 ( V_2 , 0x05 ) ;
if ( V_6 < 0 ) {
F_3 ( L_13
L_14 , V_6 ) ;
return V_6 ;
}
if ( V_6 > 0 ) {
if ( V_6 == 0x10 ) {
return - V_14 ;
} else {
F_3 ( L_18 , V_6 ) ;
return - V_11 ;
}
}
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_6 ;
T_1 V_4 ;
V_6 = F_8 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 == 1 )
return 0 ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
static int F_10 ( struct V_21 * V_22 ,
struct V_23 V_24 [] , int V_25 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
int V_3 , V_27 , V_17 , V_28 ;
if ( V_25 <= 0 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_25 ; V_17 ++ ) {
V_3 = V_24 [ V_17 ] . V_3 << 1 ;
F_11 ( 2 , L_19 ,
( V_24 [ V_17 ] . V_29 & V_30 ) ? L_20 : L_21 ,
V_17 == V_25 - 1 ? L_22 : L_23 , V_3 , V_24 [ V_17 ] . V_5 ) ;
if ( ! V_24 [ V_17 ] . V_5 ) {
if ( V_2 -> V_31 . V_32 )
V_27 = F_6 ( V_2 , V_3 ) ;
else
V_27 = F_9 ( V_2 , V_3 ) ;
if ( V_27 == - V_14 ) {
if ( V_33 >= 2 )
F_12 ( L_24 ) ;
return V_27 ;
}
} else if ( V_24 [ V_17 ] . V_29 & V_30 ) {
if ( V_2 -> V_31 . V_32 )
V_27 = F_5 ( V_2 , V_3 ,
V_24 [ V_17 ] . V_4 ,
V_24 [ V_17 ] . V_5 ) ;
else
V_27 = F_8 ( V_2 , V_3 ,
V_24 [ V_17 ] . V_4 ,
V_24 [ V_17 ] . V_5 ) ;
if ( V_33 >= 2 ) {
for ( V_28 = 0 ; V_28 < V_24 [ V_17 ] . V_5 ; V_28 ++ )
F_12 ( L_25 , V_24 [ V_17 ] . V_4 [ V_28 ] ) ;
}
} else {
if ( V_33 >= 2 ) {
for ( V_28 = 0 ; V_28 < V_24 [ V_17 ] . V_5 ; V_28 ++ )
F_12 ( L_25 , V_24 [ V_17 ] . V_4 [ V_28 ] ) ;
}
if ( V_2 -> V_31 . V_32 )
V_27 = F_1 ( V_2 , V_3 ,
V_24 [ V_17 ] . V_4 ,
V_24 [ V_17 ] . V_5 ) ;
else
V_27 = F_7 ( V_2 , V_3 ,
V_24 [ V_17 ] . V_4 ,
V_24 [ V_17 ] . V_5 ,
V_17 == V_25 - 1 ) ;
}
if ( V_27 < 0 ) {
if ( V_33 >= 2 )
F_12 ( L_26 , V_27 ) ;
return V_27 ;
}
if ( V_33 >= 2 )
F_12 ( L_27 ) ;
}
return V_25 ;
}
static inline unsigned long F_13 ( char * V_4 , int V_34 , int V_35 )
{
unsigned long V_36 = 0 ;
unsigned long V_37 = 0 ;
int V_5 = 0 ;
unsigned char V_38 ;
do {
if ( V_5 == V_34 ) {
V_38 = ( char ) V_5 ;
V_5 = - 1 ;
} else
V_38 = * V_4 ++ ;
V_37 = ( V_37 << 8 ) | V_38 ;
V_5 ++ ;
if ( ( V_5 & ( 32 / 8 - 1 ) ) == 0 )
V_36 = ( ( V_36 ^ V_37 ) * 0x9e370001UL ) ;
} while ( V_5 );
return ( V_36 >> ( 32 - V_35 ) ) & 0xffffffffUL ;
}
static int F_14 ( struct V_1 * V_2 , unsigned char * V_39 , int V_5 )
{
unsigned char V_4 , * V_40 = V_39 ;
struct V_41 * V_42 = ( void * ) V_39 ;
int V_17 , V_43 , V_44 = V_5 , V_45 , V_46 ;
if ( V_2 -> V_47 == V_48 ||
V_2 -> V_47 == V_49 ||
V_2 -> V_47 == V_50 ) {
return 0 ;
}
V_2 -> V_51 . V_3 = 0xa0 >> 1 ;
V_43 = F_15 ( & V_2 -> V_51 , & V_4 , 0 ) ;
if ( V_43 < 0 ) {
F_16 ( L_28 ) ;
memset ( V_39 , 0 , V_5 ) ;
return - V_14 ;
}
V_4 = 0 ;
V_43 = F_17 ( & V_2 -> V_51 , & V_4 , 1 ) ;
if ( V_43 != 1 ) {
F_12 ( V_52 L_29 ,
V_2 -> V_53 , V_43 ) ;
return V_43 ;
}
if ( V_2 -> V_31 . V_32 )
V_46 = 4 ;
else
V_46 = 64 ;
while ( V_44 > 0 ) {
if ( V_44 > V_46 )
V_45 = V_46 ;
else
V_45 = V_44 ;
if ( V_45 !=
( V_43 = F_15 ( & V_2 -> V_51 , V_40 , V_45 ) ) ) {
F_12 ( V_54
L_30 ,
V_2 -> V_53 , V_43 ) ;
return V_43 ;
}
V_44 -= V_45 ;
V_40 += V_45 ;
}
for ( V_17 = 0 ; V_17 < V_5 ; V_17 ++ ) {
if ( 0 == ( V_17 % 16 ) )
F_12 ( V_52 L_31 , V_2 -> V_53 , V_17 ) ;
F_12 ( L_25 , V_39 [ V_17 ] ) ;
if ( 15 == ( V_17 % 16 ) )
F_12 ( L_27 ) ;
}
if ( V_42 -> V_55 == 0x9567eb1a )
V_2 -> V_36 = F_13 ( V_39 , V_5 , 32 ) ;
F_12 ( V_52 L_32 ,
V_2 -> V_53 , V_42 -> V_55 , V_2 -> V_36 ) ;
F_12 ( V_52 L_33 , V_2 -> V_53 ) ;
switch ( V_42 -> V_56 >> 4 & 0x3 ) {
case 0 :
F_12 ( V_52 L_34 , V_2 -> V_53 ) ;
break;
case 1 :
F_12 ( V_52 L_35 ,
V_2 -> V_53 ) ;
break;
case 2 :
F_12 ( V_52 L_36 ,
V_2 -> V_53 ) ;
break;
case 3 :
F_12 ( V_52 L_37 ,
V_2 -> V_53 ) ;
break;
}
if ( V_42 -> V_56 & 1 << 3 )
F_12 ( V_52 L_38 , V_2 -> V_53 ) ;
if ( V_42 -> V_56 & 1 << 2 )
F_12 ( V_52 L_39 , V_2 -> V_53 ) ;
switch ( V_42 -> V_56 & 0x3 ) {
case 0 :
F_12 ( V_52 L_40 , V_2 -> V_53 ) ;
break;
case 1 :
F_12 ( V_52 L_41 , V_2 -> V_53 ) ;
break;
case 2 :
F_12 ( V_52 L_42 , V_2 -> V_53 ) ;
break;
case 3 :
F_12 ( V_52 L_43 , V_2 -> V_53 ) ;
break;
}
F_12 ( V_52 L_44 ,
V_2 -> V_53 ,
V_42 -> V_57 ,
V_42 -> V_58 ,
V_42 -> V_59 ,
V_42 -> V_60 ) ;
return 0 ;
}
static T_3 F_18 ( struct V_21 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_26 ;
T_3 V_62 = V_63 | V_64 ;
if ( V_2 -> V_31 . V_32 )
V_62 &= ~ V_65 ;
return V_62 ;
}
void F_19 ( struct V_1 * V_2 )
{
T_1 V_66 [ 128 ] ;
unsigned char V_4 ;
int V_17 , V_27 ;
memset ( V_66 , 0 , F_20 ( V_66 ) ) ;
for ( V_17 = 0 ; V_17 < F_20 ( V_67 ) ; V_17 ++ ) {
V_2 -> V_51 . V_3 = V_17 ;
V_27 = F_15 ( & V_2 -> V_51 , & V_4 , 0 ) ;
if ( V_27 < 0 )
continue;
V_66 [ V_17 ] = V_17 ;
F_12 ( V_52 L_45 ,
V_2 -> V_53 , V_17 << 1 , V_67 [ V_17 ] ? V_67 [ V_17 ] : L_46 ) ;
}
V_2 -> V_68 = F_13 ( V_66 ,
F_20 ( V_66 ) , 32 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_69 ;
F_2 ( ! V_2 -> V_10 || ! V_2 -> V_13 ) ;
F_2 ( ! V_2 -> V_20 || ! V_2 -> V_70 ) ;
V_2 -> V_22 = V_71 ;
V_2 -> V_22 . V_2 . V_72 = & V_2 -> V_73 -> V_2 ;
strcpy ( V_2 -> V_22 . V_53 , V_2 -> V_53 ) ;
V_2 -> V_22 . V_26 = V_2 ;
F_22 ( & V_2 -> V_22 , & V_2 -> V_74 ) ;
V_69 = F_23 ( & V_2 -> V_22 ) ;
if ( V_69 < 0 ) {
F_16 ( L_47 ,
V_75 , V_69 ) ;
return V_69 ;
}
V_2 -> V_51 = V_76 ;
V_2 -> V_51 . V_77 = & V_2 -> V_22 ;
V_69 = F_14 ( V_2 , V_2 -> V_39 , sizeof( V_2 -> V_39 ) ) ;
if ( ( V_69 < 0 ) && ( V_69 != - V_14 ) ) {
F_16 ( L_48 ,
V_75 , V_69 ) ;
return V_69 ;
}
if ( V_78 )
F_19 ( V_2 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_22 ) ;
return 0 ;
}
