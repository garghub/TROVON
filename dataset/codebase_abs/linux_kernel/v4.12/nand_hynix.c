static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 [ 6 ] = { } ;
int V_6 = 0 ;
V_2 -> V_7 ( V_4 , V_8 , 0x40 , - 1 ) ;
for ( V_6 = 0 ; V_6 < 5 ; V_6 ++ )
V_5 [ V_6 ] = V_2 -> V_9 ( V_4 ) ;
return ! strcmp ( L_1 , V_5 ) ;
}
static int F_3 ( struct V_3 * V_4 , int V_10 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_11 * V_12 = F_5 ( V_2 ) ;
const T_1 * V_13 ;
int V_14 ;
int V_6 ;
V_13 = V_12 -> V_15 -> V_13 +
( V_10 * V_12 -> V_15 -> V_16 ) ;
V_2 -> V_7 ( V_4 , V_17 , - 1 , - 1 ) ;
for ( V_6 = 0 ; V_6 < V_12 -> V_15 -> V_16 ; V_6 ++ ) {
int V_18 = V_12 -> V_15 -> V_19 [ V_6 ] ;
V_18 |= V_18 << 8 ;
V_2 -> V_7 ( V_4 , V_20 , V_18 , - 1 ) ;
V_2 -> V_21 ( V_4 , V_13 [ V_6 ] ) ;
}
V_2 -> V_7 ( V_4 , V_22 , - 1 , - 1 ) ;
V_14 = V_2 -> V_23 ( V_4 , V_2 ) ;
if ( V_14 & V_24 )
return - V_25 ;
return 0 ;
}
static int F_6 ( const T_1 * V_26 , int V_27 , T_1 * V_28 )
{
int V_6 , V_29 , V_30 = V_27 / 2 ;
for ( V_6 = 0 ; V_6 < V_30 ; V_6 ++ ) {
int V_31 = 0 ;
T_1 V_32 = V_26 [ V_6 ] ;
for ( V_29 = V_6 + 1 ; V_29 < V_27 ; V_29 ++ ) {
if ( V_26 [ V_29 ] == V_32 )
V_31 ++ ;
}
if ( V_31 > V_30 ) {
* V_28 = V_32 ;
return 0 ;
}
}
return - V_25 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_33 * V_34 ,
void * V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_2 -> V_7 ( V_4 , V_36 , - 1 , - 1 ) ;
V_2 -> V_7 ( V_4 , V_17 , - 1 , - 1 ) ;
for ( V_6 = 0 ; V_6 < V_34 -> V_16 ; V_6 ++ ) {
int V_18 = V_34 -> V_19 [ V_6 ] ;
V_18 |= V_18 << 8 ;
V_2 -> V_7 ( V_4 , V_20 , V_18 , - 1 ) ;
V_2 -> V_21 ( V_4 , V_34 -> V_13 [ V_6 ] ) ;
}
V_2 -> V_7 ( V_4 , V_22 , - 1 , - 1 ) ;
V_2 -> V_7 ( V_4 , 0x17 , - 1 , - 1 ) ;
V_2 -> V_7 ( V_4 , 0x04 , - 1 , - 1 ) ;
V_2 -> V_7 ( V_4 , 0x19 , - 1 , - 1 ) ;
V_2 -> V_7 ( V_4 , V_37 , 0x0 , V_34 -> V_38 ) ;
V_2 -> V_39 ( V_4 , V_35 , V_34 -> V_40 ) ;
V_2 -> V_7 ( V_4 , V_36 , - 1 , - 1 ) ;
V_2 -> V_7 ( V_4 , V_17 , 0x38 , - 1 ) ;
V_2 -> V_21 ( V_4 , 0x0 ) ;
V_2 -> V_7 ( V_4 , V_22 , - 1 , - 1 ) ;
V_2 -> V_7 ( V_4 , V_37 , 0x0 , - 1 ) ;
return 0 ;
}
static int F_8 ( const T_1 * V_35 , int V_41 , int V_16 ,
int V_42 , int V_43 , bool V_44 , T_1 * V_32 )
{
T_1 V_45 [ V_46 ] ;
int V_47 = ( V_42 * V_16 ) + V_43 ;
int V_48 = V_41 * V_16 ;
int V_6 , V_49 ;
for ( V_6 = 0 ; V_6 < V_46 ; V_6 ++ ) {
int V_50 = F_9 ( V_6 , V_48 , V_44 ) ;
V_45 [ V_6 ] = V_35 [ V_47 + V_50 ] ;
}
V_49 = F_6 ( V_45 , V_46 , V_32 ) ;
if ( V_49 )
return V_49 ;
if ( V_44 )
* V_32 = ~ * V_32 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_33 * V_34 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_51 * V_52 = NULL ;
int V_49 , V_6 , V_29 ;
T_1 V_16 , V_41 ;
T_1 * V_35 ;
V_35 = F_11 ( V_34 -> V_40 , V_53 ) ;
if ( ! V_35 )
return - V_54 ;
V_49 = F_7 ( V_2 , V_34 , V_35 ) ;
if ( V_49 )
goto V_28;
V_49 = F_6 ( V_35 , V_46 ,
& V_41 ) ;
if ( V_49 )
goto V_28;
V_49 = F_6 ( V_35 + V_46 ,
V_46 ,
& V_16 ) ;
if ( V_49 )
goto V_28;
V_52 = F_12 ( sizeof( * V_52 ) + ( V_16 * V_41 ) , V_53 ) ;
if ( ! V_52 ) {
V_49 = - V_54 ;
goto V_28;
}
for ( V_6 = 0 ; V_6 < V_41 ; V_6 ++ ) {
for ( V_29 = 0 ; V_29 < V_16 ; V_29 ++ ) {
T_1 * V_32 = V_52 -> V_13 + ( V_6 * V_16 ) ;
V_49 = F_8 ( V_35 , V_41 , V_16 , V_6 , V_29 ,
false , V_32 ) ;
if ( ! V_49 )
continue;
V_49 = F_8 ( V_35 , V_41 , V_16 , V_6 , V_29 ,
true , V_32 ) ;
if ( V_49 )
goto V_28;
}
}
V_52 -> V_16 = V_16 ;
V_52 -> V_19 = V_55 ;
V_12 -> V_15 = V_52 ;
V_2 -> V_56 = F_3 ;
V_2 -> V_57 = V_41 ;
V_28:
F_13 ( V_35 ) ;
if ( V_49 )
F_13 ( V_52 ) ;
return V_49 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_6 , V_49 = 0 ;
bool V_58 ;
V_58 = F_1 ( V_2 ) ;
if ( V_58 ) {
T_1 V_59 = V_2 -> V_60 . V_61 [ 5 ] >> 4 ;
if ( V_59 == 4 ) {
for ( V_6 = 0 ; V_6 < F_15 ( V_62 ) ;
V_6 ++ ) {
V_49 = F_10 ( V_2 ,
V_62 ) ;
if ( ! V_49 )
break;
}
}
}
if ( V_49 )
F_16 ( L_2 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
bool V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_63 ;
V_63 = ( ( V_2 -> V_60 . V_61 [ 3 ] >> 2 ) & 0x3 ) |
( ( V_2 -> V_60 . V_61 [ 3 ] >> 4 ) & 0x4 ) ;
if ( V_58 ) {
switch ( V_63 ) {
case 0 :
V_4 -> V_63 = 2048 ;
break;
case 1 :
V_4 -> V_63 = 1664 ;
break;
case 2 :
V_4 -> V_63 = 1024 ;
break;
case 3 :
V_4 -> V_63 = 640 ;
break;
default:
F_18 ( 1 , L_3 ) ;
break;
}
} else {
switch ( V_63 ) {
case 0 :
V_4 -> V_63 = 128 ;
break;
case 1 :
V_4 -> V_63 = 224 ;
break;
case 2 :
V_4 -> V_63 = 448 ;
break;
case 3 :
V_4 -> V_63 = 64 ;
break;
case 4 :
V_4 -> V_63 = 32 ;
break;
case 5 :
V_4 -> V_63 = 16 ;
break;
case 6 :
V_4 -> V_63 = 640 ;
break;
default:
F_18 ( 1 , L_3 ) ;
break;
}
}
}
static void F_19 ( struct V_1 * V_2 ,
bool V_58 )
{
T_1 V_64 = ( V_2 -> V_60 . V_61 [ 4 ] >> 4 ) & 0x7 ;
if ( V_58 ) {
V_2 -> V_65 = 1024 ;
switch ( V_64 ) {
case 0 :
V_2 -> V_65 = 0 ;
V_2 -> V_66 = 0 ;
break;
case 1 :
V_2 -> V_66 = 4 ;
break;
case 2 :
V_2 -> V_66 = 24 ;
break;
case 3 :
V_2 -> V_66 = 32 ;
break;
case 4 :
V_2 -> V_66 = 40 ;
break;
case 5 :
V_2 -> V_66 = 50 ;
break;
case 6 :
V_2 -> V_66 = 60 ;
break;
default:
F_18 ( 1 , L_4 ) ;
}
} else {
T_1 V_59 = V_2 -> V_60 . V_61 [ 5 ] & 0x3 ;
if ( V_59 < 3 ) {
if ( V_64 < 5 ) {
V_2 -> V_65 = 512 ;
V_2 -> V_66 = 1 << V_64 ;
} else if ( V_64 < 7 ) {
if ( V_64 == 5 )
V_2 -> V_65 = 2048 ;
else
V_2 -> V_65 = 1024 ;
V_2 -> V_66 = 24 ;
} else {
F_18 ( 1 , L_4 ) ;
}
} else {
if ( ! V_64 ) {
V_2 -> V_65 = 0 ;
V_2 -> V_66 = 0 ;
} else if ( V_64 < 5 ) {
V_2 -> V_65 = 512 ;
V_2 -> V_66 = 1 << ( V_64 - 1 ) ;
} else {
V_2 -> V_65 = 1024 ;
V_2 -> V_66 = 24 +
( 8 * ( V_64 - 5 ) ) ;
}
}
}
}
static void F_20 ( struct V_1 * V_2 ,
bool V_58 )
{
T_1 V_59 ;
if ( V_2 -> V_67 > 2 )
V_2 -> V_68 |= V_69 ;
if ( V_58 ) {
V_59 = V_2 -> V_60 . V_61 [ 5 ] >> 4 ;
if ( V_59 > 0 )
V_2 -> V_68 |= V_69 ;
} else {
V_59 = V_2 -> V_60 . V_61 [ 5 ] & 0x3 ;
if ( V_59 > 2 )
V_2 -> V_68 |= V_69 ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_58 ;
T_1 V_45 ;
if ( V_2 -> V_60 . V_70 < 6 || F_22 ( V_2 ) ) {
F_23 ( V_2 ) ;
return;
}
V_4 -> V_71 = 2048 << ( V_2 -> V_60 . V_61 [ 3 ] & 0x03 ) ;
V_45 = ( V_2 -> V_60 . V_61 [ 3 ] >> 4 ) & 0x3 ;
if ( V_2 -> V_60 . V_61 [ 3 ] & 0x80 )
V_4 -> V_72 = V_73 << V_45 ;
else if ( V_45 == 3 )
V_4 -> V_72 = V_74 + V_75 ;
else
V_4 -> V_72 = V_76 << V_45 ;
V_58 = F_1 ( V_2 ) ;
F_17 ( V_2 , V_58 ) ;
F_19 ( V_2 , V_58 ) ;
F_20 ( V_2 , V_58 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
if ( ! V_12 )
return;
F_13 ( V_12 -> V_15 ) ;
F_13 ( V_12 ) ;
F_25 ( V_2 , NULL ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_49 ;
if ( ! F_22 ( V_2 ) )
V_2 -> V_77 |= V_78 ;
else
V_2 -> V_77 |= V_79 ;
V_12 = F_12 ( sizeof( * V_12 ) , V_53 ) ;
if ( ! V_12 )
return - V_54 ;
F_25 ( V_2 , V_12 ) ;
V_49 = F_14 ( V_2 ) ;
if ( V_49 )
F_24 ( V_2 ) ;
return V_49 ;
}
