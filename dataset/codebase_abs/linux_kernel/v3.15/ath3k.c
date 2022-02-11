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
V_5 = F_6 ( V_2 , V_6 , V_15 , V_16 ,
0 , 0 , V_4 , 20 , V_17 ) ;
if ( V_5 < 0 ) {
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
int V_20 , V_6 = 0 ;
char * V_21 ;
V_21 = F_4 ( sizeof( * V_21 ) , V_12 ) ;
if ( ! V_21 )
return - V_13 ;
V_6 = F_12 ( V_2 , 0 ) ;
V_20 = F_6 ( V_2 , V_6 , V_22 ,
V_16 | V_23 , 0 , 0 ,
V_21 , sizeof( * V_21 ) , V_17 ) ;
* V_19 = * V_21 ;
F_10 ( V_21 ) ;
return V_20 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_20 , V_6 = 0 ;
struct V_24 * V_21 ;
const int V_8 = sizeof( * V_21 ) ;
V_21 = F_4 ( V_8 , V_12 ) ;
if ( ! V_21 )
return - V_13 ;
V_6 = F_12 ( V_2 , 0 ) ;
V_20 = F_6 ( V_2 , V_6 , V_26 ,
V_16 | V_23 , 0 , 0 ,
V_21 , V_8 , V_17 ) ;
memcpy ( V_25 , V_21 , V_8 ) ;
F_10 ( V_21 ) ;
return V_20 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_3 )
{
T_1 * V_4 ;
int V_5 , V_6 , V_7 , V_8 , V_10 , V_9 = 0 ;
int V_20 ;
V_10 = V_3 -> V_8 ;
V_4 = F_4 ( V_11 , V_12 ) ;
if ( ! V_4 ) {
F_5 ( L_2 ) ;
return - V_13 ;
}
V_8 = F_7 ( V_18 , V_10 , V_27 ) ;
memcpy ( V_4 , V_3 -> V_14 , V_8 ) ;
V_6 = F_3 ( V_2 , 0 ) ;
V_20 = F_6 ( V_2 , V_6 , V_28 ,
V_16 , 0 , 0 , V_4 ,
V_8 , V_17 ) ;
if ( V_20 < 0 ) {
F_5 ( L_3 ) ;
F_10 ( V_4 ) ;
return V_20 ;
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
return F_6 ( V_2 , V_6 , V_29 ,
V_16 , 0 , 0 ,
NULL , 0 , V_17 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned char V_30 ;
int V_6 = 0 , V_20 ;
V_20 = F_11 ( V_2 , & V_30 ) ;
if ( V_20 < 0 ) {
F_5 ( L_6 ) ;
return V_20 ;
}
if ( ( V_30 & V_31 ) == V_32 ) {
F_2 ( L_7 ) ;
return 0 ;
}
V_6 = F_3 ( V_2 , 0 ) ;
return F_6 ( V_2 , V_6 , V_33 ,
V_16 , 0 , 0 ,
NULL , 0 , V_17 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned char V_30 ;
char V_34 [ V_35 ] = { 0 } ;
const struct V_3 * V_3 ;
struct V_24 V_36 , V_37 ;
int V_20 ;
V_20 = F_11 ( V_2 , & V_30 ) ;
if ( V_20 < 0 ) {
F_5 ( L_8 ) ;
return V_20 ;
}
if ( V_30 & V_38 ) {
F_2 ( L_9 ) ;
return 0 ;
}
V_20 = F_13 ( V_2 , & V_36 ) ;
if ( V_20 < 0 ) {
F_5 ( L_10 ) ;
return V_20 ;
}
snprintf ( V_34 , V_35 , L_11 ,
F_18 ( V_36 . V_39 ) ) ;
V_20 = F_19 ( & V_3 , V_34 , & V_2 -> V_40 ) ;
if ( V_20 < 0 ) {
F_5 ( L_12 , V_34 ) ;
return V_20 ;
}
V_37 . V_39 = * ( int * ) ( V_3 -> V_14 + V_3 -> V_8 - 8 ) ;
V_37 . V_41 = * ( int * )
( V_3 -> V_14 + V_3 -> V_8 - 4 ) ;
if ( ( V_37 . V_39 != V_36 . V_39 ) ||
( V_37 . V_41 <= V_36 . V_41 ) ) {
F_5 ( L_13 ) ;
F_20 ( V_3 ) ;
return - V_42 ;
}
V_20 = F_14 ( V_2 , V_3 ) ;
F_20 ( V_3 ) ;
return V_20 ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned char V_30 ;
char V_34 [ V_35 ] = { 0 } ;
const struct V_3 * V_3 ;
struct V_24 V_36 ;
int V_43 , V_20 ;
V_20 = F_11 ( V_2 , & V_30 ) ;
if ( V_20 < 0 ) {
F_5 ( L_14 ) ;
return - V_44 ;
}
V_20 = F_13 ( V_2 , & V_36 ) ;
if ( V_20 < 0 ) {
F_5 ( L_10 ) ;
return V_20 ;
}
switch ( V_36 . V_45 ) {
case V_46 :
V_43 = 26 ;
break;
case V_47 :
V_43 = 40 ;
break;
case V_48 :
V_43 = 19 ;
break;
default:
V_43 = 0 ;
break;
}
snprintf ( V_34 , V_35 , L_15 ,
F_18 ( V_36 . V_39 ) , V_43 , L_16 ) ;
V_20 = F_19 ( & V_3 , V_34 , & V_2 -> V_40 ) ;
if ( V_20 < 0 ) {
F_5 ( L_17 , V_34 ) ;
return V_20 ;
}
V_20 = F_14 ( V_2 , V_3 ) ;
F_20 ( V_3 ) ;
return V_20 ;
}
static int F_22 ( struct V_49 * V_50 ,
const struct V_51 * V_52 )
{
const struct V_3 * V_3 ;
struct V_1 * V_2 = F_23 ( V_50 ) ;
int V_20 ;
F_2 ( L_18 , V_50 , V_52 ) ;
if ( V_50 -> V_53 -> V_54 . V_55 != 0 )
return - V_56 ;
if ( ! V_52 -> V_57 ) {
const struct V_51 * V_58 ;
V_58 = F_24 ( V_50 , V_59 ) ;
if ( V_58 )
V_52 = V_58 ;
}
if ( V_52 -> V_57 & V_60 ) {
if ( F_25 ( V_2 -> V_61 . V_62 ) > 0x0001 )
return - V_56 ;
V_20 = F_17 ( V_2 ) ;
if ( V_20 < 0 ) {
F_5 ( L_19 ) ;
return V_20 ;
}
V_20 = F_21 ( V_2 ) ;
if ( V_20 < 0 ) {
F_5 ( L_20 ) ;
return V_20 ;
}
V_20 = F_16 ( V_2 ) ;
if ( V_20 < 0 ) {
F_5 ( L_21 ) ;
return V_20 ;
}
F_15 ( V_2 ) ;
return 0 ;
}
V_20 = F_19 ( & V_3 , V_63 , & V_2 -> V_40 ) ;
if ( V_20 < 0 ) {
if ( V_20 == - V_64 )
F_5 ( L_22 ,
V_63 ) ;
else
F_5 ( L_23 ,
V_63 , V_20 ) ;
return V_20 ;
}
V_20 = F_1 ( V_2 , V_3 ) ;
F_20 ( V_3 ) ;
return V_20 ;
}
static void F_26 ( struct V_49 * V_50 )
{
F_2 ( L_24 , V_50 ) ;
}
