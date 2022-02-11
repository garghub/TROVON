static inline void F_1 ( unsigned char V_1 , unsigned char V_2 )
{
if ( V_3 . V_4 == V_5 )
F_2 ( V_1 , V_3 . V_6 + V_2 ) ;
else
F_3 ( V_1 , V_3 . V_7 + V_3 . V_6 + V_2 ) ;
}
static inline unsigned char F_4 ( unsigned char V_2 )
{
if ( V_3 . V_4 == V_5 )
return F_5 ( V_3 . V_6 + V_2 ) ;
else
return F_6 ( V_3 . V_7 + V_3 . V_6 + V_2 ) ;
}
static inline void F_7 ( unsigned char V_1 , unsigned char V_2 )
{
if ( V_3 . V_4 == V_5 )
F_2 ( V_1 , V_3 . V_8 + V_2 ) ;
else
F_3 ( V_1 , V_3 . V_7 + V_3 . V_9 + V_2 ) ;
}
static inline unsigned char F_8 ( unsigned char V_2 )
{
if ( V_3 . V_4 == V_5 )
return F_5 ( V_3 . V_8 + V_2 ) ;
else
return F_6 ( V_3 . V_7 + V_3 . V_9 + V_2 ) ;
}
static int F_9 ( struct V_10 * V_11 , int V_12 )
{
int V_13 ;
int V_14 = 0 ;
int V_15 ;
if ( V_12 ) {
for ( V_15 = 0 ; V_15 < 4096 ; V_15 ++ ) {
V_13 = F_4 ( V_16 ) ;
if ( V_13 == 0xff ) {
if ( V_14 == 5 )
break;
else
V_14 ++ ;
}
}
}
V_15 = 0 ;
do {
V_13 = F_4 ( V_17 ) ;
V_13 = F_4 ( V_18 ) ;
V_15 ++ ;
if ( V_15 == V_19 )
return - V_20 ;
} while ( ( V_13 & ( 1 << V_21 ) ) != 0 );
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , int V_22 )
{
int V_13 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_13 = F_4 ( V_18 ) ;
if ( V_13 & 1 << V_22 )
break;
F_11 ( V_23 ) ;
}
if ( V_15 == V_19 ) {
if ( V_22 == V_24 )
F_12 ( & V_11 -> V_25 , L_1 ) ;
if ( V_22 == V_21 )
F_12 ( & V_11 -> V_25 , L_2 ) ;
return - V_20 ;
}
return 0 ;
}
static void F_13 ( struct V_10 * V_11 , T_1 V_26 )
{
F_10 ( V_11 , V_24 ) ;
F_1 ( V_26 , V_16 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
V_27 ++ ;
F_15 ( & V_11 -> V_25 , L_3 ,
V_27 , V_28 ) ;
F_13 ( V_11 , V_29 ) ;
F_13 ( V_11 , V_30 ) ;
F_13 ( V_11 , 0x00 ) ;
F_13 ( V_11 , 0x00 ) ;
F_11 ( V_31 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
F_15 ( & V_11 -> V_25 , L_4 ) ;
F_13 ( V_11 , V_29 ) ;
F_13 ( V_11 , V_32 ) ;
F_13 ( V_11 , 0x00 ) ;
F_13 ( V_11 , 0x00 ) ;
V_27 = 0 ;
F_11 ( V_31 ) ;
}
static int F_17 ( struct V_10 * V_11 , T_1 * V_33 , T_2 V_34 )
{
int V_15 ;
int V_35 ;
T_3 V_36 = 0 ;
V_27 = 0 ;
V_37:
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_35 = F_10 ( V_11 , V_21 ) ;
if ( V_35 )
return - V_20 ;
V_33 [ V_15 ] = F_4 ( V_17 ) ;
}
if ( V_33 [ 0 ] != V_29 ) {
F_12 ( & V_11 -> V_25 ,
L_5 ) ;
return - V_20 ;
}
if ( V_33 [ 1 ] == V_38 ) {
V_36 = ( ( V_33 [ 2 ] << 8 ) | V_33 [ 3 ] ) ;
for ( V_15 = 0 ; V_15 < V_36 ; V_15 ++ ) {
F_10 ( V_11 , V_21 ) ;
V_33 [ V_15 ] = F_4 ( V_17 ) ;
}
if ( ( V_36 == 0x6D00 ) && ( V_33 [ 1 ] == 0x80 ) ) {
F_12 ( & V_11 -> V_25 , L_6 ) ;
return - V_20 ;
}
for ( V_15 = 0 ; V_15 < V_36 ; V_15 ++ )
V_33 [ V_15 ] = V_33 [ V_15 + 6 ] ;
V_36 = V_36 - 6 ;
return V_36 ;
}
if ( V_33 [ 1 ] == V_30 ) {
F_15 ( & V_11 -> V_25 , L_7 ) ;
if ( V_27 < V_28 ) {
F_14 ( V_11 ) ;
goto V_37;
} else {
F_16 ( V_11 ) ;
goto V_37;
}
}
if ( V_33 [ 1 ] == V_39 ) {
F_15 ( & V_11 -> V_25 , L_8 ) ;
return V_36 ;
}
if ( V_33 [ 1 ] == V_40 ) {
F_12 ( & V_11 -> V_25 , L_9 ) ;
if ( V_33 [ 4 ] == V_41 )
F_12 ( & V_11 -> V_25 ,
L_10
L_11 ) ;
return - V_20 ;
}
return - V_20 ;
}
static int F_18 ( struct V_10 * V_11 , T_1 * V_33 , T_2 V_34 )
{
int V_15 ;
int V_35 ;
T_1 V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ;
F_1 ( V_48 , V_49 ) ;
V_35 = F_9 ( V_11 , 1 ) ;
if ( V_35 ) {
F_12 ( & V_11 -> V_25 , L_12 ) ;
return - V_20 ;
}
V_35 = F_10 ( V_11 , V_24 ) ;
if ( V_35 )
return - V_20 ;
V_44 = ( V_34 & 0xff000000 ) >> 24 ;
V_45 = ( V_34 & 0x00ff0000 ) >> 16 ;
V_46 = ( V_34 & 0x0000ff00 ) >> 8 ;
V_47 = ( V_34 & 0x000000ff ) ;
V_42 = ( ( V_34 + 6 ) & 0xffffff00 ) >> 8 ;
V_43 = ( ( V_34 + 6 ) & 0x000000ff ) ;
F_13 ( V_11 , V_29 ) ;
F_13 ( V_11 , V_38 ) ;
F_13 ( V_11 , V_42 ) ;
F_13 ( V_11 , V_43 ) ;
F_13 ( V_11 , V_29 ) ;
F_13 ( V_11 , V_50 ) ;
F_13 ( V_11 , V_44 ) ;
F_13 ( V_11 , V_45 ) ;
F_13 ( V_11 , V_46 ) ;
F_13 ( V_11 , V_47 ) ;
for ( V_15 = 0 ; V_15 < V_34 ; V_15 ++ ) {
F_13 ( V_11 , V_33 [ V_15 ] ) ;
}
return V_34 ;
}
static void F_19 ( struct V_10 * V_11 )
{
}
static T_1 F_20 ( struct V_10 * V_11 )
{
return F_4 ( V_18 ) ;
}
static int F_21 ( struct V_51 * V_25 ,
const struct V_52 * V_53 )
{
int V_54 = 0 ;
T_1 V_55 , V_56 ;
int V_57 [ 2 ] ;
int V_58 [ 2 ] ;
int V_59 [ 2 ] ;
const char * V_60 ;
struct V_10 * V_11 ;
if ( F_22 ( V_25 , 0 ) && F_22 ( V_25 , 1 ) &&
! ( F_23 ( V_25 , 0 ) & V_61 ) ) {
V_3 . V_4 = V_5 ;
V_3 . V_8 = F_24 ( V_25 , 0 ) ;
V_3 . V_62 = F_25 ( V_25 , 0 ) ;
V_3 . V_6 = F_24 ( V_25 , 1 ) ;
V_3 . V_63 = F_25 ( V_25 , 1 ) ;
if ( ( V_3 . V_63 < 4 ) || ( V_3 . V_62 < 2 ) ) {
V_54 = - V_64 ;
goto V_65;
}
F_15 ( & V_25 -> V_25 , L_13 ,
V_25 -> V_66 , V_53 -> V_67 ) ;
if ( ! ( ( V_3 . V_6 >> 8 ) & 0xff ) ) {
V_54 = - V_64 ;
goto V_65;
}
if ( F_26 ( V_3 . V_6 , V_3 . V_63 ,
L_14 ) == NULL ) {
V_54 = - V_64 ;
goto V_65;
}
if ( F_26 ( V_3 . V_8 , V_3 . V_62 ,
L_14 ) == NULL ) {
F_27 ( V_3 . V_6 , V_3 . V_63 ) ;
V_54 = - V_64 ;
goto V_65;
}
} else if ( F_28 ( V_25 , 0 ) &&
! ( F_29 ( V_25 , 0 ) & V_61 ) ) {
V_3 . V_4 = V_68 ;
V_3 . V_69 = F_30 ( V_25 , 0 ) ;
V_3 . V_70 = F_31 ( V_25 , 0 ) ;
F_15 ( & V_25 -> V_25 , L_13 ,
V_25 -> V_66 , V_53 -> V_67 ) ;
if ( F_32 ( V_3 . V_69 , V_3 . V_70 ,
L_14 ) == NULL ) {
V_54 = - V_64 ;
goto V_65;
}
V_3 . V_7 = F_33 ( V_3 . V_69 , V_3 . V_70 ) ;
if ( V_3 . V_7 == NULL ) {
F_34 ( V_3 . V_69 , V_3 . V_70 ) ;
V_54 = - V_64 ;
goto V_65;
}
V_3 . V_9 = V_71 ;
V_3 . V_6 = 0x0 ;
} else {
V_54 = - V_64 ;
goto V_65;
}
F_7 ( V_72 , V_73 ) ;
F_7 ( V_74 , V_73 ) ;
V_57 [ 1 ] = F_8 ( V_75 ) ;
F_7 ( V_76 , V_73 ) ;
V_57 [ 0 ] = F_8 ( V_75 ) ;
F_7 ( V_77 , V_73 ) ;
V_59 [ 1 ] = F_8 ( V_75 ) ;
F_7 ( V_78 , V_73 ) ;
V_59 [ 0 ] = F_8 ( V_75 ) ;
F_7 ( V_79 , V_73 ) ;
V_58 [ 1 ] = F_8 ( V_75 ) ;
F_7 ( V_80 , V_73 ) ;
V_58 [ 0 ] = F_8 ( V_75 ) ;
switch ( ( V_59 [ 0 ] << 8 ) | V_59 [ 1 ] ) {
case 6 :
V_60 = L_15 ;
break;
case 11 :
V_60 = L_16 ;
break;
default:
V_60 = L_17 ;
break;
}
if ( ( V_57 [ 0 ] << 8 | V_57 [ 1 ] ) == ( V_81 ) ) {
F_7 ( V_82 , V_73 ) ;
F_7 ( ( V_3 . V_6 >> 8 ) & 0xff , V_75 ) ;
F_7 ( V_83 , V_73 ) ;
F_7 ( ( V_3 . V_6 & 0xff ) , V_75 ) ;
F_7 ( V_82 , V_73 ) ;
V_56 = F_8 ( V_75 ) ;
F_7 ( V_83 , V_73 ) ;
V_55 = F_8 ( V_75 ) ;
if ( ( V_56 << 8 | V_55 ) != V_3 . V_6 ) {
F_12 ( & V_25 -> V_25 ,
L_18 ,
V_3 . V_6 ) ;
V_54 = - V_20 ;
goto V_84;
}
F_7 ( V_85 , V_73 ) ;
F_7 ( 0x01 , V_75 ) ;
F_7 ( V_86 , V_73 ) ;
F_1 ( V_48 , V_49 ) ;
F_15 ( & V_25 -> V_25 , L_19
L_20
L_21
L_22
L_23
L_24
L_25 ,
V_3 . V_4 == V_5 ?
V_3 . V_8 :
V_3 . V_69 + V_3 . V_9 ,
V_3 . V_4 == V_5 ?
V_3 . V_6 :
V_3 . V_69 + V_3 . V_6 ,
V_58 [ 0 ] , V_58 [ 1 ] ,
V_57 [ 0 ] , V_57 [ 1 ] ,
V_59 [ 0 ] , V_59 [ 1 ] , V_60 ) ;
V_11 = F_35 ( & V_25 -> V_25 , & V_87 ) ;
if ( F_36 ( V_11 ) ) {
V_54 = F_37 ( V_11 ) ;
goto V_84;
}
V_54 = F_38 ( V_11 ) ;
if ( V_54 )
goto V_84;
return 0 ;
} else {
V_54 = - V_88 ;
goto V_84;
}
V_84:
if ( V_3 . V_4 == V_5 ) {
F_27 ( V_3 . V_6 , V_3 . V_63 ) ;
F_27 ( V_3 . V_8 , V_3 . V_62 ) ;
} else {
F_39 ( V_3 . V_7 ) ;
F_34 ( V_3 . V_69 , V_3 . V_70 ) ;
}
V_65:
return V_54 ;
}
static void F_40 ( struct V_51 * V_25 )
{
struct V_10 * V_11 = F_41 ( V_25 ) ;
F_42 ( V_11 ) ;
if ( V_3 . V_4 == V_5 ) {
F_27 ( V_3 . V_6 , V_3 . V_63 ) ;
F_27 ( V_3 . V_8 ,
V_3 . V_62 ) ;
} else {
F_39 ( V_3 . V_7 ) ;
F_34 ( V_3 . V_69 , V_3 . V_70 ) ;
}
}
static int F_43 ( struct V_89 * V_25 )
{
F_7 ( V_72 , V_73 ) ;
F_7 ( V_82 , V_73 ) ;
F_7 ( ( V_3 . V_6 >> 8 ) & 0xff , V_75 ) ;
F_7 ( V_83 , V_73 ) ;
F_7 ( ( V_3 . V_6 & 0xff ) , V_75 ) ;
F_7 ( V_85 , V_73 ) ;
F_7 ( 0x01 , V_75 ) ;
F_7 ( V_86 , V_73 ) ;
F_1 ( V_48 , V_49 ) ;
return F_44 ( V_25 ) ;
}
