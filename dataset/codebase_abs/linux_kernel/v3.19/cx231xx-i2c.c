static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 1 )
return V_2 -> V_4 ? V_5 : V_6 ;
return V_3 ;
}
static inline bool F_2 ( struct V_1 * V_2 , struct V_7 * V_8 ,
const struct V_9 * V_10 , int V_11 )
{
int V_12 = F_1 ( V_2 , V_8 -> V_13 ) ;
if ( V_12 != V_2 -> V_14 . V_15 )
return false ;
if ( V_10 -> V_16 != V_2 -> V_14 . V_17 )
return false ;
if ( V_2 -> V_11 != V_11 )
return false ;
return true ;
}
static int F_3 ( struct V_18 * V_19 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_21 V_22 ;
int V_23 = 0 ;
T_1 V_24 = 0 ;
T_2 V_25 = 0 ;
T_2 V_26 = 1 ;
T_2 * V_27 = NULL ;
T_1 V_28 = 0 ;
T_2 V_29 = 0 ;
if ( F_2 ( V_2 , V_8 , V_10 , V_30 ) ) {
V_24 = V_10 -> V_31 ;
if ( V_24 == 2 ) {
return 0 ;
} else if ( V_24 == 4 ) {
if ( V_10 -> V_31 >= 2 )
V_28 = V_10 -> V_32 [ 0 ] << 8 | V_10 -> V_32 [ 1 ] ;
else if ( V_10 -> V_31 == 1 )
V_28 = V_10 -> V_32 [ 0 ] ;
switch ( V_28 ) {
case 0x0000 :
V_29 = 1 ;
V_2 -> V_33 = 1 ;
break;
case 0x000D :
case 0x0001 :
case 0x0002 :
case 0x0003 :
V_29 = 1 ;
break;
default:
if ( V_2 -> V_33 )
V_29 = 1 ;
break;
}
if ( V_29 ) {
F_4 ( 1 ,
L_1 ,
V_10 -> V_16 , V_10 -> V_31 , V_28 ) ;
return V_2 -> V_34 ( V_2 ,
V_10 -> V_16 ,
V_10 -> V_32 ,
V_10 -> V_31 ) ;
}
}
V_26 = 1 ;
V_24 -= V_26 ;
V_27 = ( T_2 * ) ( V_10 -> V_32 + 1 ) ;
do {
V_22 . V_35 = V_10 -> V_16 ;
V_22 . V_36 = V_10 -> V_37 ;
V_22 . V_26 = V_26 ;
V_22 . V_38 = V_10 -> V_32 [ 0 ] ;
V_22 . V_39 = V_24 > 16 ? 16 : V_24 ;
V_22 . V_40 = ( T_2 * ) ( V_27 + V_25 * 16 ) ;
V_8 -> V_41 = ( V_24 > 16 ) ? 1 : 0 ;
V_8 -> V_42 = ( V_25 == 0 ) ? 0 : 1 ;
V_23 = V_2 -> V_43 ( V_8 , & V_22 ) ;
V_25 ++ ;
if ( V_24 >= 16 )
V_24 -= 16 ;
else
V_24 = 0 ;
} while ( V_24 > 0 );
V_8 -> V_41 = 0 ;
V_8 -> V_42 = 0 ;
} else {
V_22 . V_35 = V_10 -> V_16 ;
V_22 . V_36 = V_10 -> V_37 ;
V_22 . V_26 = 0 ;
V_22 . V_38 = 0 ;
V_22 . V_39 = V_10 -> V_31 ;
V_22 . V_40 = V_10 -> V_32 ;
V_23 = V_2 -> V_43 ( V_8 , & V_22 ) ;
}
return V_23 < 0 ? V_23 : 0 ;
}
static int F_5 ( struct V_18 * V_19 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_21 V_22 ;
int V_23 = 0 ;
T_1 V_28 = 0 ;
T_2 V_29 = 0 ;
if ( F_2 ( V_2 , V_8 , V_10 , V_30 ) ) {
if ( V_10 -> V_31 == 2 )
V_28 = V_10 -> V_32 [ 0 ] << 8 | V_10 -> V_32 [ 1 ] ;
else if ( V_10 -> V_31 == 1 )
V_28 = V_10 -> V_32 [ 0 ] ;
if ( V_2 -> V_33 ) {
switch ( V_28 ) {
case 0x0009 :
F_4 ( 1 ,
L_2 ) ;
V_10 -> V_32 [ 0 ] = 0 ;
if ( V_10 -> V_31 == 2 )
V_10 -> V_32 [ 1 ] = 0 ;
return 0 ;
case 0x0004 :
V_29 = 1 ;
break;
}
if ( V_29 ) {
F_4 ( 1 ,
L_3 ,
V_10 -> V_16 , V_10 -> V_31 ,
V_10 -> V_32 [ 0 ] << 8 | V_10 -> V_32 [ 1 ] ) ;
V_23 =
V_2 -> V_34 ( V_2 , V_10 -> V_16 ,
V_10 -> V_32 ,
V_10 -> V_31 ) ;
V_23 =
V_2 -> V_44 ( V_2 , V_10 -> V_16 ,
V_10 -> V_32 ,
V_10 -> V_31 ) ;
return V_23 ;
}
}
V_22 . V_35 = V_10 -> V_16 ;
V_22 . V_36 = V_10 -> V_37 ;
V_22 . V_26 = V_10 -> V_31 ;
V_22 . V_38 = V_10 -> V_32 [ 0 ] << 8 | V_10 -> V_32 [ 1 ] ;
V_22 . V_39 = V_10 -> V_31 ;
V_22 . V_40 = V_10 -> V_32 ;
V_23 = V_2 -> V_43 ( V_8 , & V_22 ) ;
} else {
V_22 . V_35 = V_10 -> V_16 ;
V_22 . V_36 = V_10 -> V_37 ;
V_22 . V_26 = 0 ;
V_22 . V_38 = 0 ;
V_22 . V_39 = V_10 -> V_31 ;
V_22 . V_40 = V_10 -> V_32 ;
V_23 = V_2 -> V_43 ( V_8 , & V_22 ) ;
}
return V_23 < 0 ? V_23 : 0 ;
}
static int F_6 ( struct V_18 * V_19 ,
const struct V_9 * V_45 ,
const struct V_9 * V_46 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_21 V_22 ;
int V_23 = 0 ;
T_1 V_28 = 0 ;
T_2 V_29 = 0 ;
if ( V_45 -> V_31 == 2 )
V_28 = V_45 -> V_32 [ 0 ] << 8 | V_45 -> V_32 [ 1 ] ;
else if ( V_45 -> V_31 == 1 )
V_28 = V_45 -> V_32 [ 0 ] ;
if ( F_2 ( V_2 , V_8 , V_46 , V_30 ) ) {
if ( ( V_46 -> V_31 < 16 ) ) {
F_4 ( 1 ,
L_4 ,
V_46 -> V_16 , V_46 -> V_31 , V_28 , V_45 -> V_31 ) ;
switch ( V_28 ) {
case 0x0008 :
V_29 = 1 ;
break;
case 0x0004 :
V_29 = 1 ;
break;
}
if ( V_29 ) {
V_23 =
V_2 -> V_34 ( V_2 , V_45 -> V_16 ,
V_45 -> V_32 ,
V_45 -> V_31 ) ;
V_23 =
V_2 -> V_44 ( V_2 , V_46 -> V_16 ,
V_46 -> V_32 ,
V_46 -> V_31 ) ;
return V_23 ;
}
}
}
V_22 . V_35 = V_46 -> V_16 ;
V_22 . V_36 = V_46 -> V_37 ;
V_22 . V_26 = V_45 -> V_31 ;
V_22 . V_38 = V_28 ;
V_22 . V_39 = V_46 -> V_31 ;
V_22 . V_40 = V_46 -> V_32 ;
V_23 = V_2 -> V_43 ( V_8 , & V_22 ) ;
return V_23 < 0 ? V_23 : 0 ;
}
static int F_7 ( struct V_18 * V_19 ,
const struct V_9 * V_10 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_21 V_22 ;
int V_23 = 0 ;
T_2 V_32 [ 1 ] ;
V_22 . V_35 = V_10 -> V_16 ;
V_22 . V_36 = V_47 ;
V_22 . V_26 = 0 ;
V_22 . V_38 = 0 ;
V_22 . V_39 = 1 ;
V_22 . V_40 = V_32 ;
V_23 = V_2 -> V_43 ( V_8 , & V_22 ) ;
return V_23 < 0 ? V_23 : 0 ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_9 V_48 [] , int V_49 )
{
struct V_7 * V_8 = V_19 -> V_20 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_16 , V_50 , V_51 , V_52 ;
if ( V_49 <= 0 )
return 0 ;
F_9 ( & V_2 -> V_53 ) ;
for ( V_51 = 0 ; V_51 < V_49 ; V_51 ++ ) {
V_16 = V_48 [ V_51 ] . V_16 ;
F_10 ( 2 , L_5 ,
( V_48 [ V_51 ] . V_37 & V_47 ) ? L_6 : L_7 ,
V_51 == V_49 - 1 ? L_8 : L_9 , V_16 , V_48 [ V_51 ] . V_31 ) ;
if ( ! V_48 [ V_51 ] . V_31 ) {
V_50 = F_7 ( V_19 , & V_48 [ V_51 ] ) ;
if ( V_50 < 0 ) {
F_10 ( 2 , L_10 ) ;
F_11 ( & V_2 -> V_53 ) ;
return V_50 ;
}
} else if ( V_48 [ V_51 ] . V_37 & V_47 ) {
V_50 = F_5 ( V_19 , & V_48 [ V_51 ] ) ;
if ( V_54 >= 2 ) {
for ( V_52 = 0 ; V_52 < V_48 [ V_51 ] . V_31 ; V_52 ++ )
F_12 ( V_55 L_11 , V_48 [ V_51 ] . V_32 [ V_52 ] ) ;
}
} else if ( V_51 + 1 < V_49 && ( V_48 [ V_51 + 1 ] . V_37 & V_47 ) &&
V_48 [ V_51 ] . V_16 == V_48 [ V_51 + 1 ] . V_16
&& ( V_48 [ V_51 ] . V_31 <= 2 ) && ( V_8 -> V_13 < 3 ) ) {
if ( V_54 >= 2 ) {
for ( V_52 = 0 ; V_52 < V_48 [ V_51 ] . V_31 ; V_52 ++ )
F_12 ( V_55 L_11 , V_48 [ V_51 ] . V_32 [ V_52 ] ) ;
F_12 ( V_55 L_12 ) ;
}
F_10 ( 2 , L_13 ,
( V_48 [ V_51 + 1 ] . V_37 & V_47 ) ? L_6 : L_7 ,
V_51 + 1 == V_49 - 1 ? L_8 : L_9 , V_16 , V_48 [ V_51 + 1 ] . V_31 ) ;
V_50 = F_6 ( V_19 ,
& V_48 [ V_51 ] ,
& V_48 [ V_51 + 1 ] ) ;
if ( V_54 >= 2 ) {
for ( V_52 = 0 ; V_52 < V_48 [ V_51 + 1 ] . V_31 ; V_52 ++ )
F_12 ( V_55 L_11 , V_48 [ V_51 + 1 ] . V_32 [ V_52 ] ) ;
}
V_51 ++ ;
} else {
if ( V_54 >= 2 ) {
for ( V_52 = 0 ; V_52 < V_48 [ V_51 ] . V_31 ; V_52 ++ )
F_12 ( V_55 L_11 , V_48 [ V_51 ] . V_32 [ V_52 ] ) ;
}
V_50 = F_3 ( V_19 , & V_48 [ V_51 ] ) ;
}
if ( V_50 < 0 )
goto V_56;
if ( V_54 >= 2 )
F_12 ( V_55 L_12 ) ;
}
F_11 ( & V_2 -> V_53 ) ;
return V_49 ;
V_56:
F_10 ( 2 , L_14 , V_50 ) ;
F_11 ( & V_2 -> V_53 ) ;
return V_50 ;
}
static T_3 F_13 ( struct V_18 * V_57 )
{
return V_58 | V_59 ;
}
void F_14 ( struct V_1 * V_2 , int V_12 )
{
unsigned char V_32 ;
int V_51 , V_50 ;
struct V_60 V_61 ;
if ( ! V_62 )
return;
V_2 -> V_63 = true ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_64 = F_15 ( V_2 , V_12 ) ;
for ( V_51 = 0 ; V_51 < 128 ; V_51 ++ ) {
V_61 . V_16 = V_51 ;
V_50 = F_16 ( & V_61 , & V_32 , 0 ) ;
if ( V_50 < 0 )
continue;
F_17 ( V_2 -> V_2 ,
L_15 ,
V_12 ,
V_51 << 1 ,
V_65 [ V_51 ] ? V_65 [ V_51 ] : L_16 ) ;
}
V_2 -> V_63 = false ;
}
int F_18 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_19 ( ! V_2 -> V_43 ) ;
V_8 -> V_19 = V_66 ;
V_8 -> V_19 . V_2 . V_67 = V_2 -> V_2 ;
snprintf ( V_8 -> V_19 . V_68 , sizeof( V_8 -> V_19 . V_68 ) , L_17 , V_8 -> V_2 -> V_68 , V_8 -> V_13 ) ;
V_8 -> V_19 . V_20 = V_8 ;
F_20 ( & V_8 -> V_19 , & V_2 -> V_69 ) ;
F_21 ( & V_8 -> V_19 ) ;
if ( 0 != V_8 -> V_70 )
F_22 ( V_2 -> V_2 ,
L_18 , V_8 -> V_13 ) ;
return V_8 -> V_70 ;
}
int F_23 ( struct V_7 * V_8 )
{
F_24 ( & V_8 -> V_19 ) ;
return 0 ;
}
static int F_25 ( struct V_18 * V_57 ,
void * V_71 , T_3 V_72 )
{
struct V_1 * V_2 = V_71 ;
return F_26 ( V_2 , V_72 ) ;
}
int F_27 ( struct V_1 * V_2 , int V_73 )
{
struct V_18 * V_74 = & V_2 -> V_75 [ 1 ] . V_19 ;
struct V_76 * V_77 = V_2 -> V_2 ;
V_2 -> V_78 [ V_73 ] = F_28 ( V_74 ,
V_77 ,
V_2 ,
0 ,
V_73 ,
0 ,
& F_25 ,
NULL ) ;
if ( ! V_2 -> V_78 [ V_73 ] )
F_22 ( V_2 -> V_2 ,
L_19 , V_73 ) ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 , int V_73 )
{
F_30 ( V_2 -> V_78 [ V_73 ] ) ;
V_2 -> V_78 [ V_73 ] = NULL ;
}
struct V_18 * F_15 ( struct V_1 * V_2 , int V_12 )
{
switch ( V_12 ) {
case V_79 :
return & V_2 -> V_75 [ 0 ] . V_19 ;
case V_80 :
return & V_2 -> V_75 [ 1 ] . V_19 ;
case V_81 :
return & V_2 -> V_75 [ 2 ] . V_19 ;
case V_6 :
return V_2 -> V_78 [ 0 ] ;
case V_5 :
return V_2 -> V_78 [ 1 ] ;
default:
return NULL ;
}
}
