static inline bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , int V_7 )
{
if ( V_4 -> V_8 != V_2 -> V_9 . V_10 )
return false ;
if ( V_6 -> V_11 != V_2 -> V_9 . V_12 )
return false ;
if ( V_2 -> V_7 != V_7 )
return false ;
return true ;
}
int F_2 ( struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 = V_14 -> V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_16 V_17 ;
int V_18 = 0 ;
T_1 V_19 = 0 ;
T_2 V_20 = 0 ;
T_2 V_21 = 1 ;
T_2 * V_22 = NULL ;
T_1 V_23 = 0 ;
T_2 V_24 = 0 ;
if ( F_1 ( V_2 , V_4 , V_6 , V_25 ) ) {
V_19 = V_6 -> V_26 ;
if ( V_19 == 2 ) {
return 0 ;
} else if ( V_19 == 4 ) {
if ( V_6 -> V_26 >= 2 )
V_23 = V_6 -> V_27 [ 0 ] << 8 | V_6 -> V_27 [ 1 ] ;
else if ( V_6 -> V_26 == 1 )
V_23 = V_6 -> V_27 [ 0 ] ;
switch ( V_23 ) {
case 0x0000 :
V_24 = 1 ;
V_2 -> V_28 = 1 ;
break;
case 0x000D :
case 0x0001 :
case 0x0002 :
case 0x0003 :
V_24 = 1 ;
break;
default:
if ( V_2 -> V_28 )
V_24 = 1 ;
break;
}
if ( V_24 ) {
F_3 ( 1 ,
L_1 ,
V_6 -> V_11 , V_6 -> V_26 , V_23 ) ;
return V_2 -> V_29 ( V_2 ,
V_6 -> V_11 ,
V_6 -> V_27 ,
V_6 -> V_26 ) ;
}
}
V_21 = 1 ;
V_19 -= V_21 ;
V_22 = ( T_2 * ) ( V_6 -> V_27 + 1 ) ;
do {
V_17 . V_30 = V_6 -> V_11 ;
V_17 . V_31 = V_6 -> V_32 ;
V_17 . V_21 = V_21 ;
V_17 . V_33 = V_6 -> V_27 [ 0 ] ;
V_17 . V_34 = V_19 > 16 ? 16 : V_19 ;
V_17 . V_35 = ( T_2 * ) ( V_22 + V_20 * 16 ) ;
V_4 -> V_36 = ( V_19 > 16 ) ? 1 : 0 ;
V_4 -> V_37 = ( V_20 == 0 ) ? 0 : 1 ;
V_18 = V_2 -> V_38 ( V_4 , & V_17 ) ;
V_20 ++ ;
if ( V_19 >= 16 )
V_19 -= 16 ;
else
V_19 = 0 ;
} while ( V_19 > 0 );
V_4 -> V_36 = 0 ;
V_4 -> V_37 = 0 ;
} else {
V_17 . V_30 = V_6 -> V_11 ;
V_17 . V_31 = V_6 -> V_32 ;
V_17 . V_21 = 0 ;
V_17 . V_33 = 0 ;
V_17 . V_34 = V_6 -> V_26 ;
V_17 . V_35 = V_6 -> V_27 ;
V_18 = V_2 -> V_38 ( V_4 , & V_17 ) ;
}
return V_18 < 0 ? V_18 : 0 ;
}
static int F_4 ( struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 = V_14 -> V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_16 V_17 ;
int V_18 = 0 ;
T_1 V_23 = 0 ;
T_2 V_24 = 0 ;
if ( F_1 ( V_2 , V_4 , V_6 , V_25 ) ) {
if ( V_6 -> V_26 == 2 )
V_23 = V_6 -> V_27 [ 0 ] << 8 | V_6 -> V_27 [ 1 ] ;
else if ( V_6 -> V_26 == 1 )
V_23 = V_6 -> V_27 [ 0 ] ;
if ( V_2 -> V_28 ) {
switch ( V_23 ) {
case 0x0009 :
F_3 ( 1 ,
L_2 ) ;
V_6 -> V_27 [ 0 ] = 0 ;
if ( V_6 -> V_26 == 2 )
V_6 -> V_27 [ 1 ] = 0 ;
return 0 ;
case 0x0004 :
V_24 = 1 ;
break;
}
if ( V_24 ) {
F_3 ( 1 ,
L_3 ,
V_6 -> V_11 , V_6 -> V_26 ,
V_6 -> V_27 [ 0 ] << 8 | V_6 -> V_27 [ 1 ] ) ;
V_18 =
V_2 -> V_29 ( V_2 , V_6 -> V_11 ,
V_6 -> V_27 ,
V_6 -> V_26 ) ;
V_18 =
V_2 -> V_39 ( V_2 , V_6 -> V_11 ,
V_6 -> V_27 ,
V_6 -> V_26 ) ;
return V_18 ;
}
}
V_17 . V_30 = V_6 -> V_11 ;
V_17 . V_31 = V_6 -> V_32 ;
V_17 . V_21 = V_6 -> V_26 ;
V_17 . V_33 = V_6 -> V_27 [ 0 ] << 8 | V_6 -> V_27 [ 1 ] ;
V_17 . V_34 = V_6 -> V_26 ;
V_17 . V_35 = V_6 -> V_27 ;
V_18 = V_2 -> V_38 ( V_4 , & V_17 ) ;
} else {
V_17 . V_30 = V_6 -> V_11 ;
V_17 . V_31 = V_6 -> V_32 ;
V_17 . V_21 = 0 ;
V_17 . V_33 = 0 ;
V_17 . V_34 = V_6 -> V_26 ;
V_17 . V_35 = V_6 -> V_27 ;
V_18 = V_2 -> V_38 ( V_4 , & V_17 ) ;
}
return V_18 < 0 ? V_18 : 0 ;
}
static int F_5 ( struct V_13 * V_14 ,
const struct V_5 * V_40 ,
const struct V_5 * V_41 )
{
struct V_3 * V_4 = V_14 -> V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_16 V_17 ;
int V_18 = 0 ;
T_1 V_23 = 0 ;
T_2 V_24 = 0 ;
if ( V_40 -> V_26 == 2 )
V_23 = V_40 -> V_27 [ 0 ] << 8 | V_40 -> V_27 [ 1 ] ;
else if ( V_40 -> V_26 == 1 )
V_23 = V_40 -> V_27 [ 0 ] ;
if ( F_1 ( V_2 , V_4 , V_41 , V_25 ) ) {
if ( ( V_41 -> V_26 < 16 ) ) {
F_3 ( 1 ,
L_4 ,
V_41 -> V_11 , V_41 -> V_26 , V_23 , V_40 -> V_26 ) ;
switch ( V_23 ) {
case 0x0008 :
V_24 = 1 ;
break;
case 0x0004 :
V_24 = 1 ;
break;
}
if ( V_24 ) {
V_18 =
V_2 -> V_29 ( V_2 , V_40 -> V_11 ,
V_40 -> V_27 ,
V_40 -> V_26 ) ;
V_18 =
V_2 -> V_39 ( V_2 , V_41 -> V_11 ,
V_41 -> V_27 ,
V_41 -> V_26 ) ;
return V_18 ;
}
}
}
V_17 . V_30 = V_41 -> V_11 ;
V_17 . V_31 = V_41 -> V_32 ;
V_17 . V_21 = V_40 -> V_26 ;
V_17 . V_33 = V_23 ;
V_17 . V_34 = V_41 -> V_26 ;
V_17 . V_35 = V_41 -> V_27 ;
V_18 = V_2 -> V_38 ( V_4 , & V_17 ) ;
return V_18 < 0 ? V_18 : 0 ;
}
static int F_6 ( struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 = V_14 -> V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_16 V_17 ;
int V_18 = 0 ;
V_17 . V_30 = V_6 -> V_11 ;
V_17 . V_31 = V_6 -> V_32 ;
V_17 . V_21 = 0 ;
V_17 . V_33 = 0 ;
V_17 . V_34 = 0 ;
V_17 . V_35 = NULL ;
V_18 = V_2 -> V_38 ( V_4 , & V_17 ) ;
return V_18 < 0 ? V_18 : 0 ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_5 V_42 [] , int V_43 )
{
struct V_3 * V_4 = V_14 -> V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_11 , V_44 , V_45 , V_46 ;
if ( V_43 <= 0 )
return 0 ;
F_8 ( & V_2 -> V_47 ) ;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
V_11 = V_42 [ V_45 ] . V_11 >> 1 ;
F_9 ( 2 , L_5 ,
( V_42 [ V_45 ] . V_32 & V_48 ) ? L_6 : L_7 ,
V_45 == V_43 - 1 ? L_8 : L_9 , V_11 , V_42 [ V_45 ] . V_26 ) ;
if ( ! V_42 [ V_45 ] . V_26 ) {
V_44 = F_6 ( V_14 , & V_42 [ V_45 ] ) ;
if ( V_44 < 0 ) {
F_9 ( 2 , L_10 ) ;
F_10 ( & V_2 -> V_47 ) ;
return V_44 ;
}
} else if ( V_42 [ V_45 ] . V_32 & V_48 ) {
V_44 = F_4 ( V_14 , & V_42 [ V_45 ] ) ;
if ( V_49 >= 2 ) {
for ( V_46 = 0 ; V_46 < V_42 [ V_45 ] . V_26 ; V_46 ++ )
F_11 ( L_11 , V_42 [ V_45 ] . V_27 [ V_46 ] ) ;
}
} else if ( V_45 + 1 < V_43 && ( V_42 [ V_45 + 1 ] . V_32 & V_48 ) &&
V_42 [ V_45 ] . V_11 == V_42 [ V_45 + 1 ] . V_11
&& ( V_42 [ V_45 ] . V_26 <= 2 ) && ( V_4 -> V_8 < 3 ) ) {
V_44 = F_5 ( V_14 ,
& V_42 [ V_45 ] ,
& V_42 [ V_45 + 1 ] ) ;
if ( V_49 >= 2 ) {
for ( V_46 = 0 ; V_46 < V_42 [ V_45 ] . V_26 ; V_46 ++ )
F_11 ( L_11 , V_42 [ V_45 ] . V_27 [ V_46 ] ) ;
}
V_45 ++ ;
} else {
if ( V_49 >= 2 ) {
for ( V_46 = 0 ; V_46 < V_42 [ V_45 ] . V_26 ; V_46 ++ )
F_11 ( L_11 , V_42 [ V_45 ] . V_27 [ V_46 ] ) ;
}
V_44 = F_2 ( V_14 , & V_42 [ V_45 ] ) ;
}
if ( V_44 < 0 )
goto V_50;
if ( V_49 >= 2 )
F_11 ( L_12 ) ;
}
F_10 ( & V_2 -> V_47 ) ;
return V_43 ;
V_50:
F_9 ( 2 , L_13 , V_44 ) ;
F_10 ( & V_2 -> V_47 ) ;
return V_44 ;
}
static T_3 F_12 ( struct V_13 * V_51 )
{
return V_52 | V_53 ;
}
void F_13 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
unsigned char V_27 ;
int V_45 , V_44 ;
F_14 ( L_14 ) ;
for ( V_45 = 0 ; V_45 < 128 ; V_45 ++ ) {
V_55 -> V_11 = V_45 ;
V_44 = F_15 ( V_55 , & V_27 , 0 ) ;
if ( V_44 < 0 )
continue;
F_14 ( L_15 ,
V_2 -> V_56 , V_45 << 1 ,
V_57 [ V_45 ] ? V_57 [ V_45 ] : L_16 ) ;
}
F_14 ( L_17 ) ;
}
int F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_17 ( ! V_2 -> V_38 ) ;
V_4 -> V_14 = V_58 ;
V_4 -> V_54 = V_59 ;
V_4 -> V_14 . V_2 . V_60 = & V_2 -> V_61 -> V_2 ;
F_18 ( V_4 -> V_14 . V_56 , V_4 -> V_2 -> V_56 , sizeof( V_4 -> V_14 . V_56 ) ) ;
V_4 -> V_14 . V_15 = V_4 ;
F_19 ( & V_4 -> V_14 , & V_2 -> V_62 ) ;
F_20 ( & V_4 -> V_14 ) ;
V_4 -> V_54 . V_63 = & V_4 -> V_14 ;
if ( 0 == V_4 -> V_64 ) {
if ( V_65 )
F_13 ( V_2 , & V_4 -> V_54 ) ;
} else
F_21 ( L_18 ,
V_2 -> V_56 , V_4 -> V_8 ) ;
return V_4 -> V_64 ;
}
int F_22 ( struct V_3 * V_4 )
{
F_23 ( & V_4 -> V_14 ) ;
return 0 ;
}
