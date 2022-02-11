static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_3 )
{
T_1 * V_4 ;
int V_5 , V_6 , V_7 , V_8 , V_9 = 0 ;
int V_10 = V_3 -> V_8 ;
F_2 ( L_1 , V_2 ) ;
V_6 = F_3 ( V_2 , 0 ) ;
V_4 = F_4 ( V_11 , V_12 ) ;
if ( ! V_4 ) {
F_5 ( L_2 ) ;
return - V_13 ;
}
memcpy ( V_4 , V_3 -> V_14 , 20 ) ;
if ( ( V_5 = F_6 ( V_2 , V_6 ,
V_15 ,
V_16 , 0 , 0 ,
V_4 , 20 , V_17 ) ) < 0 ) {
F_5 ( L_3 ) ;
goto error;
}
V_9 += 20 ;
V_10 -= 20 ;
while ( V_10 ) {
V_8 = F_7 ( V_18 , V_10 , V_11 ) ;
V_6 = F_8 ( V_2 , 0x02 ) ;
memcpy ( V_4 , V_3 -> V_14 + V_9 , V_8 ) ;
V_5 = F_9 ( V_2 , V_6 , V_4 , V_8 ,
& V_7 , 3000 ) ;
if ( V_5 || ( V_7 != V_8 ) ) {
F_5 ( L_4
L_5 , V_5 , V_7 , V_8 ) ;
goto error;
}
V_9 += V_8 ;
V_10 -= V_8 ;
}
error:
F_10 ( V_4 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned char * V_19 )
{
int V_6 = 0 ;
V_6 = F_12 ( V_2 , 0 ) ;
return F_6 ( V_2 , V_6 , V_20 ,
V_16 | V_21 , 0 , 0 ,
V_19 , 0x01 , V_17 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
int V_6 = 0 ;
V_6 = F_12 ( V_2 , 0 ) ;
return F_6 ( V_2 , V_6 , V_24 ,
V_16 | V_21 , 0 , 0 , V_23 ,
sizeof( struct V_22 ) ,
V_17 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_3 )
{
T_1 * V_4 ;
int V_5 , V_6 , V_7 , V_8 , V_10 , V_9 = 0 ;
int V_25 ;
V_10 = V_3 -> V_8 ;
V_4 = F_4 ( V_11 , V_12 ) ;
if ( ! V_4 ) {
F_5 ( L_2 ) ;
return - V_13 ;
}
V_8 = F_7 ( V_18 , V_10 , V_26 ) ;
memcpy ( V_4 , V_3 -> V_14 , V_8 ) ;
V_6 = F_3 ( V_2 , 0 ) ;
V_25 = F_6 ( V_2 , V_6 , V_27 ,
V_16 , 0 , 0 , V_4 ,
V_8 , V_17 ) ;
if ( V_25 < 0 ) {
F_5 ( L_3 ) ;
F_10 ( V_4 ) ;
return V_25 ;
}
V_9 += V_8 ;
V_10 -= V_8 ;
while ( V_10 ) {
V_8 = F_7 ( V_18 , V_10 , V_11 ) ;
V_6 = F_8 ( V_2 , 0x02 ) ;
memcpy ( V_4 , V_3 -> V_14 + V_9 , V_8 ) ;
V_5 = F_9 ( V_2 , V_6 , V_4 , V_8 ,
& V_7 , 3000 ) ;
if ( V_5 || ( V_7 != V_8 ) ) {
F_5 ( L_4
L_5 , V_5 , V_7 , V_8 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
V_9 += V_8 ;
V_10 -= V_8 ;
}
F_10 ( V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
V_6 = F_3 ( V_2 , 0 ) ;
return F_6 ( V_2 , V_6 , V_28 ,
V_16 , 0 , 0 ,
NULL , 0 , V_17 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned char V_29 ;
int V_6 = 0 , V_25 ;
V_25 = F_11 ( V_2 , & V_29 ) ;
if ( V_25 < 0 ) {
F_5 ( L_6 ) ;
return V_25 ;
}
if ( ( V_29 & V_30 ) == V_31 ) {
F_2 ( L_7 ) ;
return 0 ;
}
V_6 = F_3 ( V_2 , 0 ) ;
return F_6 ( V_2 , V_6 , V_32 ,
V_16 , 0 , 0 ,
NULL , 0 , V_17 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned char V_29 ;
char V_33 [ V_34 ] = { 0 } ;
const struct V_3 * V_3 ;
struct V_22 V_35 , V_36 ;
int V_25 ;
V_25 = F_11 ( V_2 , & V_29 ) ;
if ( V_25 < 0 ) {
F_5 ( L_8 ) ;
return V_25 ;
}
if ( V_29 & V_37 ) {
F_2 ( L_9 ) ;
return 0 ;
}
V_25 = F_13 ( V_2 , & V_35 ) ;
if ( V_25 < 0 ) {
F_5 ( L_10 ) ;
return V_25 ;
}
snprintf ( V_33 , V_34 , L_11 ,
V_35 . V_38 ) ;
V_25 = F_18 ( & V_3 , V_33 , & V_2 -> V_39 ) ;
if ( V_25 < 0 ) {
F_5 ( L_12 , V_33 ) ;
return V_25 ;
}
V_36 . V_38 = * ( int * ) ( V_3 -> V_14 + V_3 -> V_8 - 8 ) ;
V_36 . V_40 = * ( int * )
( V_3 -> V_14 + V_3 -> V_8 - 4 ) ;
if ( ( V_36 . V_38 != V_35 . V_38 ) ||
( V_36 . V_40 <= V_35 . V_40 ) ) {
F_5 ( L_13 ) ;
F_19 ( V_3 ) ;
return - V_41 ;
}
V_25 = F_14 ( V_2 , V_3 ) ;
F_19 ( V_3 ) ;
return V_25 ;
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned char V_29 ;
char V_33 [ V_34 ] = { 0 } ;
const struct V_3 * V_3 ;
struct V_22 V_35 ;
int V_42 , V_25 ;
V_25 = F_11 ( V_2 , & V_29 ) ;
if ( V_25 < 0 ) {
F_5 ( L_14 ) ;
return - V_43 ;
}
V_25 = F_13 ( V_2 , & V_35 ) ;
if ( V_25 < 0 ) {
F_5 ( L_10 ) ;
return V_25 ;
}
switch ( V_35 . V_44 ) {
case V_45 :
V_42 = 26 ;
break;
case V_46 :
V_42 = 40 ;
break;
case V_47 :
V_42 = 19 ;
break;
default:
V_42 = 0 ;
break;
}
snprintf ( V_33 , V_34 , L_15 ,
V_35 . V_38 , V_42 , L_16 ) ;
V_25 = F_18 ( & V_3 , V_33 , & V_2 -> V_39 ) ;
if ( V_25 < 0 ) {
F_5 ( L_17 , V_33 ) ;
return V_25 ;
}
V_25 = F_14 ( V_2 , V_3 ) ;
F_19 ( V_3 ) ;
return V_25 ;
}
static int F_21 ( struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
const struct V_3 * V_3 ;
struct V_1 * V_2 = F_22 ( V_49 ) ;
int V_25 ;
F_2 ( L_18 , V_49 , V_51 ) ;
if ( V_49 -> V_52 -> V_53 . V_54 != 0 )
return - V_55 ;
if ( ! V_51 -> V_56 ) {
const struct V_50 * V_57 ;
V_57 = F_23 ( V_49 , V_58 ) ;
if ( V_57 )
V_51 = V_57 ;
}
if ( V_51 -> V_56 & V_59 ) {
if ( F_24 ( V_2 -> V_60 . V_61 ) > 0x0001 )
return - V_55 ;
V_25 = F_17 ( V_2 ) ;
if ( V_25 < 0 ) {
F_5 ( L_19 ) ;
return V_25 ;
}
V_25 = F_20 ( V_2 ) ;
if ( V_25 < 0 ) {
F_5 ( L_20 ) ;
return V_25 ;
}
V_25 = F_16 ( V_2 ) ;
if ( V_25 < 0 ) {
F_5 ( L_21 ) ;
return V_25 ;
}
F_15 ( V_2 ) ;
return 0 ;
}
V_25 = F_18 ( & V_3 , V_62 , & V_2 -> V_39 ) ;
if ( V_25 < 0 ) {
if ( V_25 == - V_63 )
F_5 ( L_22 ,
V_62 ) ;
else
F_5 ( L_23 ,
V_62 , V_25 ) ;
return V_25 ;
}
V_25 = F_1 ( V_2 , V_3 ) ;
F_19 ( V_3 ) ;
return V_25 ;
}
static void F_25 ( struct V_48 * V_49 )
{
F_2 ( L_24 , V_49 ) ;
}
