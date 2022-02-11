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
V_6 = F_7 ( V_2 , 0x02 ) ;
while ( V_10 ) {
F_8 ( V_18 , V_19 ) ;
V_8 = F_9 ( V_20 , V_10 , V_11 ) ;
memcpy ( V_4 , V_3 -> V_14 + V_9 , V_8 ) ;
V_5 = F_10 ( V_2 , V_6 , V_4 , V_8 ,
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
F_11 ( V_4 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned char * V_21 )
{
int V_22 , V_6 = 0 ;
char * V_23 ;
V_23 = F_4 ( sizeof( * V_23 ) , V_12 ) ;
if ( ! V_23 )
return - V_13 ;
V_6 = F_13 ( V_2 , 0 ) ;
V_22 = F_6 ( V_2 , V_6 , V_24 ,
V_16 | V_25 , 0 , 0 ,
V_23 , sizeof( * V_23 ) , V_17 ) ;
* V_21 = * V_23 ;
F_11 ( V_23 ) ;
return V_22 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
int V_22 , V_6 = 0 ;
struct V_26 * V_23 ;
const int V_8 = sizeof( * V_23 ) ;
V_23 = F_4 ( V_8 , V_12 ) ;
if ( ! V_23 )
return - V_13 ;
V_6 = F_13 ( V_2 , 0 ) ;
V_22 = F_6 ( V_2 , V_6 , V_28 ,
V_16 | V_25 , 0 , 0 ,
V_23 , V_8 , V_17 ) ;
memcpy ( V_27 , V_23 , V_8 ) ;
F_11 ( V_23 ) ;
return V_22 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_3 * V_3 )
{
T_1 * V_4 ;
int V_5 , V_6 , V_7 , V_8 , V_10 , V_9 = 0 ;
int V_22 ;
V_10 = V_3 -> V_8 ;
V_4 = F_4 ( V_11 , V_12 ) ;
if ( ! V_4 ) {
F_5 ( L_2 ) ;
return - V_13 ;
}
V_8 = F_9 ( V_20 , V_10 , V_29 ) ;
memcpy ( V_4 , V_3 -> V_14 , V_8 ) ;
V_6 = F_3 ( V_2 , 0 ) ;
V_22 = F_6 ( V_2 , V_6 , V_30 ,
V_16 , 0 , 0 , V_4 ,
V_8 , V_17 ) ;
if ( V_22 < 0 ) {
F_5 ( L_3 ) ;
F_11 ( V_4 ) ;
return V_22 ;
}
V_9 += V_8 ;
V_10 -= V_8 ;
V_6 = F_7 ( V_2 , 0x02 ) ;
while ( V_10 ) {
F_8 ( V_18 , V_19 ) ;
V_8 = F_9 ( V_20 , V_10 , V_11 ) ;
memcpy ( V_4 , V_3 -> V_14 + V_9 , V_8 ) ;
V_5 = F_10 ( V_2 , V_6 , V_4 , V_8 ,
& V_7 , 3000 ) ;
if ( V_5 || ( V_7 != V_8 ) ) {
F_5 ( L_4
L_5 , V_5 , V_7 , V_8 ) ;
F_11 ( V_4 ) ;
return V_5 ;
}
V_9 += V_8 ;
V_10 -= V_8 ;
}
F_11 ( V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
V_6 = F_3 ( V_2 , 0 ) ;
return F_6 ( V_2 , V_6 , V_31 ,
V_16 , 0 , 0 ,
NULL , 0 , V_17 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned char V_32 ;
int V_6 = 0 , V_22 ;
V_22 = F_12 ( V_2 , & V_32 ) ;
if ( V_22 < 0 ) {
F_5 ( L_6 ) ;
return V_22 ;
}
if ( ( V_32 & V_33 ) == V_34 ) {
F_2 ( L_7 ) ;
return 0 ;
}
V_6 = F_3 ( V_2 , 0 ) ;
return F_6 ( V_2 , V_6 , V_35 ,
V_16 , 0 , 0 ,
NULL , 0 , V_17 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned char V_32 ;
char V_36 [ V_37 ] = { 0 } ;
const struct V_3 * V_3 ;
struct V_26 V_38 ;
T_2 V_39 , V_40 ;
int V_22 ;
V_22 = F_12 ( V_2 , & V_32 ) ;
if ( V_22 < 0 ) {
F_5 ( L_8 ) ;
return V_22 ;
}
if ( V_32 & V_41 ) {
F_2 ( L_9 ) ;
return 0 ;
}
V_22 = F_14 ( V_2 , & V_38 ) ;
if ( V_22 < 0 ) {
F_5 ( L_10 ) ;
return V_22 ;
}
snprintf ( V_36 , V_37 , L_11 ,
F_19 ( V_38 . V_42 ) ) ;
V_22 = F_20 ( & V_3 , V_36 , & V_2 -> V_43 ) ;
if ( V_22 < 0 ) {
F_5 ( L_12 , V_36 ) ;
return V_22 ;
}
V_39 = F_21 ( V_3 -> V_14 +
V_3 -> V_8 - 8 ) ;
V_40 = F_21 ( V_3 -> V_14 +
V_3 -> V_8 - 4 ) ;
if ( V_39 != F_19 ( V_38 . V_42 ) ||
V_40 <= F_19 ( V_38 . V_44 ) ) {
F_5 ( L_13 ) ;
F_22 ( V_3 ) ;
return - V_45 ;
}
V_22 = F_15 ( V_2 , V_3 ) ;
F_22 ( V_3 ) ;
return V_22 ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned char V_32 ;
char V_36 [ V_37 ] = { 0 } ;
const struct V_3 * V_3 ;
struct V_26 V_38 ;
int V_46 , V_22 ;
V_22 = F_12 ( V_2 , & V_32 ) ;
if ( V_22 < 0 ) {
F_5 ( L_14 ) ;
return - V_47 ;
}
V_22 = F_14 ( V_2 , & V_38 ) ;
if ( V_22 < 0 ) {
F_5 ( L_10 ) ;
return V_22 ;
}
switch ( V_38 . V_48 ) {
case V_49 :
V_46 = 26 ;
break;
case V_50 :
V_46 = 40 ;
break;
case V_51 :
V_46 = 19 ;
break;
default:
V_46 = 0 ;
break;
}
snprintf ( V_36 , V_37 , L_15 ,
F_19 ( V_38 . V_42 ) , V_46 , L_16 ) ;
V_22 = F_20 ( & V_3 , V_36 , & V_2 -> V_43 ) ;
if ( V_22 < 0 ) {
F_5 ( L_17 , V_36 ) ;
return V_22 ;
}
V_22 = F_15 ( V_2 , V_3 ) ;
F_22 ( V_3 ) ;
return V_22 ;
}
static int F_24 ( struct V_52 * V_53 ,
const struct V_54 * V_55 )
{
const struct V_3 * V_3 ;
struct V_1 * V_2 = F_25 ( V_53 ) ;
int V_22 ;
F_2 ( L_18 , V_53 , V_55 ) ;
if ( V_53 -> V_56 -> V_57 . V_58 != 0 )
return - V_59 ;
if ( ! V_55 -> V_60 ) {
const struct V_54 * V_61 ;
V_61 = F_26 ( V_53 , V_62 ) ;
if ( V_61 )
V_55 = V_61 ;
}
if ( V_55 -> V_60 & V_63 ) {
if ( F_27 ( V_2 -> V_64 . V_65 ) > 0x0001 )
return - V_59 ;
V_22 = F_18 ( V_2 ) ;
if ( V_22 < 0 ) {
F_5 ( L_19 ) ;
return V_22 ;
}
V_22 = F_23 ( V_2 ) ;
if ( V_22 < 0 ) {
F_5 ( L_20 ) ;
return V_22 ;
}
V_22 = F_17 ( V_2 ) ;
if ( V_22 < 0 ) {
F_5 ( L_21 ) ;
return V_22 ;
}
F_16 ( V_2 ) ;
return 0 ;
}
V_22 = F_20 ( & V_3 , V_66 , & V_2 -> V_43 ) ;
if ( V_22 < 0 ) {
if ( V_22 == - V_67 )
F_5 ( L_22 ,
V_66 ) ;
else
F_5 ( L_23 ,
V_66 , V_22 ) ;
return V_22 ;
}
V_22 = F_1 ( V_2 , V_3 ) ;
F_22 ( V_3 ) ;
return V_22 ;
}
static void F_28 ( struct V_52 * V_53 )
{
F_2 ( L_24 , V_53 ) ;
}
