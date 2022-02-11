static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 ;
return F_1 ( V_2 ) ;
}
static void F_6 ( struct V_7 * V_3 )
{
F_7 ( F_8 ( V_3 ) ) ;
}
static T_1 F_9 ( unsigned long V_8 , T_1 V_9 )
{
F_10 ( V_9 , V_8 + 4 ) ;
F_11 ( 20 ) ;
V_9 = F_12 ( V_8 + 5 ) ;
F_11 ( 20 ) ;
return V_9 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_7 * V_3 ,
struct V_1 * * V_12 )
{
struct V_1 * V_2 ;
unsigned long V_13 ;
T_1 V_14 , V_15 , V_16 = 0 ;
T_2 V_17 ;
void T_3 * V_18 ;
int V_19 ;
static struct V_20 V_21 = {
. V_22 = F_5 ,
} ;
* V_12 = NULL ;
V_19 = F_14 ( V_3 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_23 ) ;
if ( V_2 == NULL ) {
F_3 ( V_3 ) ;
return - V_24 ;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_3 = V_3 ;
V_19 = F_16 ( V_3 , L_1 ) ;
if ( V_19 < 0 ) {
F_4 ( V_2 ) ;
F_3 ( V_3 ) ;
return V_19 ;
}
V_2 -> V_25 = F_17 ( V_3 , 0 ) ;
V_18 = F_18 ( V_3 , 0 ) ;
if ( V_18 == NULL ) {
F_1 ( V_2 ) ;
return - V_26 ;
}
V_17 = F_19 ( V_18 + 0x18 ) ;
F_20 ( V_18 ) ;
V_13 = 0x220 + 0x20 * ( V_17 & 3 ) ;
if ( V_17 & ( 1 << 2 ) )
F_21 ( V_11 -> V_27 , L_2 , V_13 ) ;
else {
F_22 ( V_11 -> V_27 , L_3 ) ;
F_1 ( V_2 ) ;
return - V_28 ;
}
if ( V_17 & ( 1 << 5 ) )
F_21 ( V_11 -> V_27 , L_4 ) ;
else if ( V_17 & ( 1 << 6 ) )
F_21 ( V_11 -> V_27 , L_5 ) ;
V_14 = F_9 ( V_13 , 0x80 ) & 0x0F ;
V_15 = F_9 ( V_13 , 0x81 ) ;
if ( V_15 & 0x20 )
V_16 = 5 ;
else if ( V_15 & 0x40 )
V_16 = 6 ;
else if ( V_15 & 0x80 )
V_16 = 7 ;
else {
F_22 ( V_11 -> V_27 , L_6 ) ;
F_1 ( V_2 ) ;
return - V_28 ;
}
if ( V_15 & 0x01 )
V_15 = 0 ;
else if ( V_15 & 02 )
V_15 = 1 ;
else if ( V_15 & 0x08 )
V_15 = 3 ;
else {
F_22 ( V_11 -> V_27 , L_7 ) ;
F_1 ( V_2 ) ;
return - V_28 ;
}
if ( V_14 & 1 )
V_14 = 9 ;
else if ( V_14 & 2 )
V_14 = 5 ;
else if ( V_14 & 4 )
V_14 = 7 ;
else if ( V_14 & 8 )
V_14 = 10 ;
else {
F_22 ( V_11 -> V_27 , L_8 ) ;
F_1 ( V_2 ) ;
return - V_28 ;
}
F_21 ( V_11 -> V_27 , L_9 , V_14 , V_15 , V_16 ) ;
V_19 = F_23 ( V_11 , V_13 , V_14 , V_29 , V_15 ,
V_16 , V_30 , & V_2 -> V_31 ) ;
if ( V_19 < 0 ) {
F_22 ( V_11 -> V_27 , L_10 ) ;
F_1 ( V_2 ) ;
return V_19 ;
}
V_19 = F_24 ( V_2 -> V_31 , 0 ) ;
if ( V_19 < 0 ) {
F_22 ( V_11 -> V_27 , L_11 ) ;
F_1 ( V_2 ) ;
return V_19 ;
}
V_19 = F_25 ( V_2 -> V_31 ) ;
if ( V_19 < 0 ) {
F_22 ( V_11 -> V_27 , L_12 ) ;
F_1 ( V_2 ) ;
return V_19 ;
}
V_19 = F_26 ( V_11 , V_32 , V_2 , & V_21 ) ;
if ( V_19 < 0 ) {
F_1 ( V_2 ) ;
return V_19 ;
}
* V_12 = V_2 ;
return 0 ;
}
static int F_27 ( struct V_7 * V_3 ,
const struct V_33 * V_34 )
{
static int V_27 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = NULL ;
int V_19 ;
if ( V_27 >= V_35 )
return - V_28 ;
if ( ! V_36 [ V_27 ] ) {
V_27 ++ ;
return - V_37 ;
}
V_19 = F_28 ( & V_3 -> V_27 , V_38 [ V_27 ] , V_39 [ V_27 ] , V_40 ,
0 , & V_11 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_13 ( V_11 , V_3 , & V_2 ) ;
if ( V_19 < 0 ) {
F_7 ( V_11 ) ;
return V_19 ;
}
strcpy ( V_11 -> V_41 , L_1 ) ;
strcpy ( V_11 -> V_42 , L_13 ) ;
sprintf ( V_11 -> V_43 , L_14 , V_11 -> V_42 , V_2 -> V_25 ) ;
V_19 = F_29 ( V_11 ) ;
if ( V_19 < 0 ) {
F_7 ( V_11 ) ;
return V_19 ;
}
F_30 ( V_3 , V_11 ) ;
V_27 ++ ;
return 0 ;
}
