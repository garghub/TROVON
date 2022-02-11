static const char * F_1 ( int V_1 , T_1 * V_2 , T_2 V_3 )
{
T_2 V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ , V_2 ++ ) {
if ( V_2 -> V_5 == V_1 )
return V_2 -> V_6 ;
}
return L_1 ;
}
static int F_2 ( T_3 * V_7 , int V_8 ,
const unsigned char * V_9 , T_2 V_10 ,
T_2 V_11 , T_1 * V_2 , T_2 V_3 )
{
int V_1 ;
if ( V_10 % V_11 )
return 0 ;
while ( V_10 ) {
V_1 = V_9 [ 0 ] ;
if ( V_11 == 2 )
V_1 = ( V_1 << 8 ) | V_9 [ 1 ] ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_2 , F_1 ( V_1 , V_2 , V_3 ) , V_1 ) ;
V_9 += V_11 ;
V_10 -= V_11 ;
}
return 1 ;
}
static void F_5 ( T_3 * V_7 , int V_8 , const char * V_6 ,
const unsigned char * V_9 , T_2 V_10 )
{
T_2 V_4 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_3 , V_6 , ( int ) V_10 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
F_4 ( V_7 , L_4 , V_9 [ V_4 ] ) ;
F_6 ( V_7 , L_5 ) ;
}
static int F_7 ( T_3 * V_7 , int V_8 ,
const char * V_6 , T_2 V_12 ,
const unsigned char * * V_13 , T_2 * V_14 )
{
T_2 V_15 ;
const unsigned char * V_16 = * V_13 ;
if ( * V_14 < V_12 )
return 0 ;
V_15 = V_16 [ 0 ] ;
if ( V_12 > 1 )
V_15 = ( V_15 << 8 ) | V_16 [ 1 ] ;
if ( * V_14 < V_12 + V_15 )
return 0 ;
V_16 += V_12 ;
F_5 ( V_7 , V_8 , V_6 , V_16 , V_15 ) ;
* V_13 += V_15 + V_12 ;
* V_14 -= V_15 + V_12 ;
return 1 ;
}
static int F_8 ( T_3 * V_7 , int V_8 , const char * V_6 ,
const unsigned char * * V_13 , T_2 * V_14 )
{
int V_17 ;
if ( * V_14 < 2 )
return 0 ;
V_17 = ( ( * V_13 ) [ 0 ] << 8 ) | ( * V_13 ) [ 1 ] ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_6 ,
V_6 , V_17 , F_9 ( V_17 , V_18 ) ) ;
* V_13 += 2 ;
* V_14 -= 2 ;
return 1 ;
}
static int F_10 ( T_3 * V_7 , int V_8 ,
const unsigned char * * V_13 , T_2 * V_14 )
{
unsigned int V_19 ;
const unsigned char * V_16 = * V_13 ;
if ( * V_14 < 32 )
return 0 ;
V_19 = ( V_16 [ 0 ] << 24 ) | ( V_16 [ 1 ] << 16 ) | ( V_16 [ 2 ] << 8 ) | V_16 [ 3 ] ;
V_16 += 4 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_6 ( V_7 , L_7 ) ;
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_8 , V_19 ) ;
F_5 ( V_7 , V_8 + 2 , L_9 , V_16 , 28 ) ;
* V_13 += 32 ;
* V_14 -= 32 ;
return 1 ;
}
static int F_11 ( T_3 * V_7 , int V_8 , T_4 * V_20 ,
const unsigned char * * V_13 , T_2 * V_14 )
{
if ( * V_14 < 2 )
return 0 ;
if ( F_12 ( V_20 ) ) {
const unsigned char * V_16 = * V_13 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_10 ,
F_9 ( V_16 [ 0 ] , V_21 ) ,
F_9 ( V_16 [ 1 ] , V_22 ) , V_16 [ 0 ] , V_16 [ 1 ] ) ;
* V_13 += 2 ;
* V_14 -= 2 ;
}
return F_7 ( V_7 , V_8 , L_11 , 2 , V_13 , V_14 ) ;
}
static int F_13 ( T_3 * V_7 , int V_8 , int V_23 , int V_24 ,
const unsigned char * V_25 , T_2 V_26 )
{
T_2 V_27 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_12 ,
F_9 ( V_24 , V_28 ) , V_24 , ( int ) V_26 ) ;
switch ( V_24 ) {
case V_29 :
if ( V_26 < 1 )
return 0 ;
V_27 = V_25 [ 0 ] ;
if ( V_26 != V_27 + 1 )
return 0 ;
return F_14 ( V_7 , V_8 + 2 ,
V_25 + 1 , V_27 , 1 , V_30 ) ;
case V_31 :
if ( V_26 < 2 )
return 0 ;
V_27 = ( V_25 [ 0 ] << 8 ) | V_25 [ 1 ] ;
if ( V_26 != V_27 + 2 )
return 0 ;
return F_14 ( V_7 , V_8 + 2 ,
V_25 + 2 , V_27 , 2 , V_32 ) ;
case V_33 :
if ( V_26 < 2 )
return 0 ;
V_27 = ( V_25 [ 0 ] << 8 ) | V_25 [ 1 ] ;
if ( V_26 != V_27 + 2 )
return 0 ;
if ( V_27 & 1 )
return 0 ;
V_25 += 2 ;
while ( V_27 > 0 ) {
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_13 ,
F_9 ( V_25 [ 0 ] , V_21 ) ,
F_9 ( V_25 [ 1 ] , V_22 ) , V_25 [ 0 ] , V_25 [ 1 ] ) ;
V_27 -= 2 ;
V_25 += 2 ;
}
break;
case V_34 :
if ( V_26 < 1 )
return 0 ;
V_27 = V_25 [ 0 ] ;
if ( V_27 + 1 != V_26 )
return 0 ;
V_25 ++ ;
if ( V_27 ) {
if ( V_23 ) {
if ( V_27 & 1 )
return 0 ;
V_27 >>= 1 ;
}
F_5 ( V_7 , V_8 + 4 , L_14 , V_25 , V_27 ) ;
if ( V_23 ) {
V_25 += V_27 ;
F_5 ( V_7 , V_8 + 4 ,
L_15 , V_25 , V_27 ) ;
}
} else {
F_3 ( V_7 , V_8 + 4 , 80 ) ;
F_6 ( V_7 , L_16 ) ;
}
break;
case V_35 :
if ( V_26 != 1 )
return 0 ;
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_17 ,
F_9 ( V_25 [ 0 ] , V_36 ) ) ;
break;
case V_37 :
if ( V_26 != 0 )
F_5 ( V_7 , V_8 + 4 , L_18 , V_25 , V_26 ) ;
break;
default:
F_15 ( V_7 , ( char * ) V_25 , V_26 , V_8 + 2 ) ;
}
return 1 ;
}
static int F_16 ( T_3 * V_7 , int V_8 , int V_23 ,
const unsigned char * V_9 , T_2 V_10 )
{
T_2 V_38 ;
F_3 ( V_7 , V_8 , 80 ) ;
if ( V_10 == 0 ) {
F_6 ( V_7 , L_19 ) ;
return 1 ;
}
V_38 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
if ( V_38 != V_10 - 2 )
return 0 ;
V_9 += 2 ;
V_10 = V_38 ;
F_4 ( V_7 , L_20 , ( int ) V_10 ) ;
while ( V_10 > 0 ) {
int V_24 ;
T_2 V_26 ;
if ( V_10 < 4 )
return 0 ;
V_24 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
V_26 = ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ;
if ( V_10 < V_26 + 4 )
return 0 ;
V_9 += 4 ;
if ( ! F_13 ( V_7 , V_8 + 2 , V_23 ,
V_24 , V_9 , V_26 ) )
return 0 ;
V_9 += V_26 ;
V_10 -= V_26 + 4 ;
}
return 1 ;
}
static int F_17 ( T_3 * V_7 , T_4 * V_39 , int V_8 ,
const unsigned char * V_9 , T_2 V_10 )
{
T_2 V_40 ;
unsigned int V_41 ;
if ( ! F_8 ( V_7 , V_8 , L_21 , & V_9 , & V_10 ) )
return 0 ;
if ( ! F_10 ( V_7 , V_8 , & V_9 , & V_10 ) )
return 0 ;
if ( ! F_7 ( V_7 , V_8 , L_22 , 1 , & V_9 , & V_10 ) )
return 0 ;
if ( F_18 ( V_39 ) ) {
if ( ! F_7 ( V_7 , V_8 , L_23 , 1 , & V_9 , & V_10 ) )
return 0 ;
}
if ( V_10 < 2 )
return 0 ;
V_40 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
V_9 += 2 ;
V_10 -= 2 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_24 , ( int ) V_40 ) ;
if ( V_10 < V_40 || V_40 & 1 )
return 0 ;
while ( V_40 > 0 ) {
V_41 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_25 ,
V_9 [ 0 ] , V_9 [ 1 ] , F_9 ( V_41 , V_42 ) ) ;
V_9 += 2 ;
V_10 -= 2 ;
V_40 -= 2 ;
}
if ( V_10 < 1 )
return 0 ;
V_40 = V_9 [ 0 ] ;
V_9 ++ ;
V_10 -- ;
if ( V_10 < V_40 )
return 0 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_26 , ( int ) V_40 ) ;
while ( V_40 > 0 ) {
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_27 ,
F_9 ( V_9 [ 0 ] , V_43 ) , V_9 [ 0 ] ) ;
V_9 ++ ;
V_10 -- ;
V_40 -- ;
}
if ( ! F_16 ( V_7 , V_8 , 0 , V_9 , V_10 ) )
return 0 ;
return 1 ;
}
static int F_19 ( T_3 * V_7 , int V_8 ,
const unsigned char * V_9 ,
T_2 V_10 )
{
if ( ! F_8 ( V_7 , V_8 , L_28 , & V_9 , & V_10 ) )
return 0 ;
if ( ! F_7 ( V_7 , V_8 , L_23 , 1 , & V_9 , & V_10 ) )
return 0 ;
return 1 ;
}
static int F_20 ( T_3 * V_7 , int V_8 ,
const unsigned char * V_9 , T_2 V_10 )
{
unsigned int V_41 ;
if ( ! F_8 ( V_7 , V_8 , L_28 , & V_9 , & V_10 ) )
return 0 ;
if ( ! F_10 ( V_7 , V_8 , & V_9 , & V_10 ) )
return 0 ;
if ( ! F_7 ( V_7 , V_8 , L_22 , 1 , & V_9 , & V_10 ) )
return 0 ;
if ( V_10 < 2 )
return 0 ;
V_41 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_29 ,
V_9 [ 0 ] , V_9 [ 1 ] , F_9 ( V_41 , V_42 ) ) ;
V_9 += 2 ;
V_10 -= 2 ;
if ( V_10 < 1 )
return 0 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_30 ,
F_9 ( V_9 [ 0 ] , V_43 ) , V_9 [ 0 ] ) ;
V_9 ++ ;
V_10 -- ;
if ( ! F_16 ( V_7 , V_8 , 1 , V_9 , V_10 ) )
return 0 ;
return 1 ;
}
static int F_21 ( const char * * V_44 , T_4 * V_39 )
{
unsigned long V_45 = V_39 -> V_46 -> V_47 . V_48 -> V_49 ;
if ( V_45 & V_50 ) {
* V_44 = L_31 ;
return V_50 ;
}
if ( V_45 & V_51 ) {
* V_44 = L_32 ;
return V_51 ;
}
if ( V_45 & V_52 ) {
* V_44 = L_33 ;
return V_52 ;
}
if ( V_45 & V_53 ) {
* V_44 = L_34 ;
return V_53 ;
}
if ( V_45 & V_54 ) {
* V_44 = L_35 ;
return V_54 ;
}
if ( V_45 & V_55 ) {
* V_44 = L_36 ;
return V_55 ;
}
if ( V_45 & V_56 ) {
* V_44 = L_37 ;
return V_56 ;
}
if ( V_45 & V_57 ) {
* V_44 = L_38 ;
return V_57 ;
}
if ( V_45 & V_58 ) {
* V_44 = L_39 ;
return V_58 ;
}
if ( V_45 & V_59 ) {
* V_44 = L_40 ;
return V_59 ;
}
if ( V_45 & V_60 ) {
* V_44 = L_41 ;
return V_60 ;
}
* V_44 = L_1 ;
return 0 ;
}
static int F_22 ( T_3 * V_7 , int V_8 , T_4 * V_39 ,
const unsigned char * V_9 , T_2 V_10 )
{
const char * V_61 ;
int V_62 ;
V_62 = F_21 ( & V_61 , V_39 ) ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_42 , V_61 ) ;
switch ( V_62 ) {
case V_50 :
if ( F_23 ( V_39 ) == V_63 ) {
F_5 ( V_7 , V_8 + 2 ,
L_43 , V_9 , V_10 ) ;
} else {
if ( ! F_7 ( V_7 , V_8 + 2 ,
L_43 , 2 ,
& V_9 , & V_10 ) )
return 0 ;
}
break;
case V_52 :
case V_51 :
if ( V_10 == 0 ) {
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_6 ( V_7 , L_44 ) ;
break;
}
case V_54 :
if ( ! F_7 ( V_7 , V_8 + 2 , L_45 , 2 , & V_9 , & V_10 ) )
return 0 ;
break;
case V_56 :
case V_57 :
if ( V_10 == 0 ) {
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_6 ( V_7 , L_44 ) ;
break;
}
case V_55 :
if ( ! F_7 ( V_7 , V_8 + 2 , L_46 , 1 , & V_9 , & V_10 ) )
return 0 ;
break;
}
return 1 ;
}
static int F_24 ( T_3 * V_7 , int V_8 , T_4 * V_39 ,
const unsigned char * V_9 , T_2 V_10 )
{
const char * V_61 ;
int V_62 ;
V_62 = F_21 ( & V_61 , V_39 ) ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_42 , V_61 ) ;
switch ( V_62 ) {
case V_52 :
case V_51 :
case V_56 :
case V_57 :
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_47 ) ;
break;
case V_50 :
if ( ! F_7 ( V_7 , V_8 + 2 , L_48 , 2 ,
& V_9 , & V_10 ) )
return 0 ;
if ( ! F_7 ( V_7 , V_8 + 2 , L_49 , 2 ,
& V_9 , & V_10 ) )
return 0 ;
break;
case V_54 :
if ( ! F_7 ( V_7 , V_8 + 2 , L_50 , 2 , & V_9 , & V_10 ) )
return 0 ;
if ( ! F_7 ( V_7 , V_8 + 2 , L_51 , 2 , & V_9 , & V_10 ) )
return 0 ;
if ( ! F_7 ( V_7 , V_8 + 2 , L_52 , 2 , & V_9 , & V_10 ) )
return 0 ;
break;
case V_55 :
if ( V_10 < 1 )
return 0 ;
F_3 ( V_7 , V_8 + 2 , 80 ) ;
if ( V_9 [ 0 ] == V_64 )
F_6 ( V_7 , L_53 ) ;
else if ( V_9 [ 0 ] == V_65 )
F_6 ( V_7 , L_54 ) ;
else if ( V_9 [ 0 ] == V_66 ) {
int V_67 ;
if ( V_10 < 3 )
return 0 ;
V_67 = ( V_9 [ 1 ] << 8 ) | V_9 [ 2 ] ;
F_4 ( V_7 , L_55 ,
F_9 ( V_67 , V_32 ) , V_67 ) ;
V_9 += 3 ;
V_10 -= 3 ;
if ( ! F_7 ( V_7 , V_8 + 2 , L_56 , 1 , & V_9 , & V_10 ) )
return 0 ;
}
break;
}
return F_11 ( V_7 , V_8 , V_39 , & V_9 , & V_10 ) ;
}
static int F_25 ( T_3 * V_7 , int V_8 ,
const unsigned char * * V_13 , T_2 * V_14 )
{
T_2 V_10 = * V_14 ;
T_2 V_68 ;
T_5 * V_69 ;
const unsigned char * V_16 = * V_13 , * V_70 ;
if ( V_10 < 3 )
return 0 ;
V_68 = ( V_16 [ 0 ] << 16 ) | ( V_16 [ 1 ] << 8 ) | V_16 [ 2 ] ;
if ( V_10 < V_68 + 3 )
return 0 ;
V_70 = V_16 + 3 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_57 , ( int ) V_68 ) ;
V_69 = F_26 ( NULL , & V_70 , V_68 ) ;
if ( ! V_69 )
F_6 ( V_7 , L_58 ) ;
else {
F_6 ( V_7 , L_59 ) ;
F_27 ( V_7 , V_69 , V_71 , 0 ) ;
F_28 ( V_7 , V_69 ) ;
F_6 ( V_7 , L_60 ) ;
F_29 ( V_69 ) ;
}
if ( V_70 != V_16 + 3 + V_68 ) {
F_6 ( V_7 , L_61 ) ;
}
* V_13 += V_68 + 3 ;
* V_14 -= V_68 + 3 ;
return 1 ;
}
static int F_30 ( T_3 * V_7 , int V_8 ,
const unsigned char * V_9 , T_2 V_10 )
{
T_2 V_68 ;
if ( V_10 < 3 )
return 0 ;
V_68 = ( V_9 [ 0 ] << 16 ) | ( V_9 [ 1 ] << 8 ) | V_9 [ 2 ] ;
if ( V_10 != V_68 + 3 )
return 0 ;
V_9 += 3 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_62 , ( int ) V_68 ) ;
while ( V_68 > 0 ) {
if ( ! F_25 ( V_7 , V_8 + 2 , & V_9 , & V_68 ) )
return 0 ;
}
return 1 ;
}
static int F_31 ( T_3 * V_7 , int V_8 , T_4 * V_20 ,
const unsigned char * V_9 , T_2 V_10 )
{
T_2 V_27 ;
if ( V_10 < 1 )
return 0 ;
V_27 = V_9 [ 0 ] ;
if ( V_10 < V_27 + 1 )
return 0 ;
V_9 ++ ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_63 , ( int ) V_27 ) ;
if ( ! F_14 ( V_7 , V_8 + 2 , V_9 , V_27 , 1 , V_72 ) )
return 0 ;
V_9 += V_27 ;
V_10 -= V_27 + 1 ;
if ( ! F_12 ( V_20 ) )
goto V_73;
if ( V_10 < 2 )
return 0 ;
V_27 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
if ( V_10 < V_27 + 2 || ( V_27 & 1 ) )
return 0 ;
V_9 += 2 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_64 , ( int ) V_27 ) ;
while ( V_27 > 0 ) {
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_13 ,
F_9 ( V_9 [ 0 ] , V_21 ) ,
F_9 ( V_9 [ 1 ] , V_22 ) , V_9 [ 0 ] , V_9 [ 1 ] ) ;
V_27 -= 2 ;
V_9 += 2 ;
}
V_9 += V_27 ;
V_10 -= V_27 + 2 ;
V_73:
V_27 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
F_3 ( V_7 , V_8 , 80 ) ;
if ( V_10 < V_27 + 2 )
return 0 ;
V_9 += 2 ;
V_10 -= 2 ;
F_4 ( V_7 , L_65 , ( int ) V_27 ) ;
while ( V_27 > 0 ) {
T_2 V_74 ;
T_6 * V_75 ;
const unsigned char * V_16 ;
if ( V_27 < 2 )
return 0 ;
V_74 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
if ( V_27 < V_74 + 2 )
return 0 ;
V_9 += 2 ;
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_66 , ( int ) V_74 ) ;
V_16 = V_9 ;
V_75 = F_32 ( NULL , & V_16 , V_74 ) ;
if ( ! V_75 ) {
F_6 ( V_7 , L_67 ) ;
} else {
F_33 ( V_7 , V_75 , 0 , V_71 ) ;
F_6 ( V_7 , L_5 ) ;
F_34 ( V_75 ) ;
}
V_27 -= V_74 + 2 ;
V_9 += V_74 ;
}
return 1 ;
}
static int F_35 ( T_3 * V_7 , int V_8 ,
const unsigned char * V_9 , T_2 V_10 )
{
unsigned int V_76 ;
if ( V_10 == 0 ) {
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_6 ( V_7 , L_68 ) ;
return 1 ;
}
if ( V_10 < 4 )
return 0 ;
V_76 = ( V_9 [ 0 ] << 24 ) | ( V_9 [ 1 ] << 16 ) | ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ;
V_10 -= 4 ;
V_9 += 4 ;
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_4 ( V_7 , L_69 , V_76 ) ;
if ( ! F_7 ( V_7 , V_8 + 2 , L_18 , 2 , & V_9 , & V_10 ) )
return 0 ;
if ( V_10 )
return 0 ;
return 1 ;
}
static int F_36 ( T_3 * V_7 , T_4 * V_39 ,
const unsigned char * V_9 , T_2 V_10 ,
int V_8 )
{
T_2 V_77 ;
unsigned char V_78 ;
if ( V_10 < 4 )
return 0 ;
V_78 = V_9 [ 0 ] ;
V_77 = ( V_9 [ 1 ] << 16 ) | ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_70 ,
F_9 ( V_78 , V_79 ) , ( int ) V_77 ) ;
V_9 += 4 ;
V_10 -= 4 ;
if ( F_18 ( V_39 ) ) {
if ( V_10 < 8 )
return 0 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_71
L_72 ,
( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ,
( V_9 [ 2 ] << 16 ) | ( V_9 [ 3 ] << 8 ) | V_9 [ 4 ] ,
( V_9 [ 5 ] << 16 ) | ( V_9 [ 6 ] << 8 ) | V_9 [ 7 ] ) ;
V_9 += 8 ;
V_10 -= 8 ;
}
if ( V_10 < V_77 )
return 0 ;
switch ( V_78 ) {
case V_80 :
if ( ! F_17 ( V_7 , V_39 , V_8 + 2 , V_9 , V_10 ) )
return 0 ;
break;
case V_81 :
if ( ! F_19 ( V_7 , V_8 + 2 , V_9 , V_10 ) )
return 0 ;
break;
case V_82 :
if ( ! F_20 ( V_7 , V_8 + 2 , V_9 , V_10 ) )
return 0 ;
break;
case V_83 :
if ( ! F_24 ( V_7 , V_8 + 2 , V_39 , V_9 , V_10 ) )
return 0 ;
break;
case V_84 :
if ( ! F_22 ( V_7 , V_8 + 2 , V_39 , V_9 , V_10 ) )
return 0 ;
break;
case V_85 :
if ( ! F_30 ( V_7 , V_8 + 2 , V_9 , V_10 ) )
return 0 ;
break;
case V_86 :
if ( ! F_11 ( V_7 , V_8 + 2 , V_39 , & V_9 , & V_10 ) )
return 0 ;
break;
case V_87 :
if ( ! F_31 ( V_7 , V_8 + 2 , V_39 , V_9 , V_10 ) )
return 0 ;
break;
case V_88 :
F_5 ( V_7 , V_8 + 2 , L_73 , V_9 , V_10 ) ;
break;
case V_89 :
if ( V_10 != 0 )
F_5 ( V_7 , V_8 + 2 , L_74 , V_9 , V_10 ) ;
break;
case V_90 :
if ( ! F_35 ( V_7 , V_8 + 2 , V_9 , V_10 ) )
return 0 ;
break;
default:
F_3 ( V_7 , V_8 + 2 , 80 ) ;
F_6 ( V_7 , L_75 ) ;
F_15 ( V_7 , ( char * ) V_9 , V_10 , V_8 + 4 ) ;
}
return 1 ;
}
static int F_37 ( T_3 * V_7 , int V_8 ,
const unsigned char * V_9 , T_2 V_10 )
{
if ( V_10 < 3 )
return 0 ;
F_3 ( V_7 , V_8 , 80 ) ;
F_4 ( V_7 , L_76 ,
F_9 ( V_9 [ 0 ] , V_91 ) ) ;
V_9 ++ ;
V_10 -- ;
if ( ! F_7 ( V_7 , V_8 , L_77 , 2 , & V_9 , & V_10 ) )
return 0 ;
F_5 ( V_7 , V_8 , L_78 , V_9 , V_10 ) ;
return 1 ;
}
const char * F_38 ( const T_7 * V_92 )
{
if ( V_92 -> V_93 & V_94 )
return NULL ;
return F_9 ( V_92 -> V_62 & 0xFFFF , V_42 ) ;
}
void F_39 ( int V_95 , int V_96 , int V_97 ,
const void * V_98 , T_2 V_10 , T_4 * V_39 , void * V_99 )
{
const unsigned char * V_9 = V_98 ;
T_3 * V_7 = V_99 ;
if ( V_95 == 2 ) {
F_6 ( V_7 , L_79 ) ;
F_5 ( V_7 , 0 ,
F_9 ( V_97 , V_100 ) ,
V_9 , V_10 ) ;
return;
}
switch ( V_97 ) {
case V_101 :
{
int V_102 = V_9 [ 1 ] << 8 | V_9 [ 2 ] ;
F_6 ( V_7 , V_95 ? L_80 : L_81 ) ;
F_4 ( V_7 , L_82 ,
F_9 ( V_102 , V_18 ) , V_102 ) ;
if ( F_18 ( V_39 ) ) {
F_4 ( V_7 ,
L_83 ,
( V_9 [ 3 ] << 8 | V_9 [ 4 ] ) ,
( V_9 [ 5 ] << 8 | V_9 [ 6 ] ) ,
( V_9 [ 7 ] << 8 | V_9 [ 8 ] ) , ( V_9 [ 9 ] << 8 | V_9 [ 10 ] ) ) ;
# if 0
BIO_printf(bio, "(%s)\n",
ssl_trace_str(msg[msglen], ssl_handshake_tbl));
# endif
}
F_4 ( V_7 , L_84 ,
F_9 ( V_9 [ 0 ] , V_103 ) , V_9 [ 0 ] ,
V_9 [ V_10 - 2 ] << 8 | V_9 [ V_10 - 1 ] ) ;
}
break;
case V_104 :
if ( ! F_36 ( V_7 , V_39 , V_9 , V_10 , 4 ) )
F_4 ( V_7 , L_85 ) ;
break;
case V_105 :
if ( V_10 == 1 && V_9 [ 0 ] == 1 )
F_6 ( V_7 , L_86 ) ;
else
F_5 ( V_7 , 4 , L_87 , V_9 , V_10 ) ;
break;
case V_106 :
if ( V_10 != 2 )
F_6 ( V_7 , L_88 ) ;
else {
F_4 ( V_7 , L_89 ,
F_40 ( V_9 [ 0 ] << 8 ) ,
V_9 [ 0 ] , F_41 ( V_9 [ 1 ] ) , V_9 [ 1 ] ) ;
}
case V_107 :
F_37 ( V_7 , 4 , V_9 , V_10 ) ;
break;
}
F_6 ( V_7 , L_5 ) ;
}
