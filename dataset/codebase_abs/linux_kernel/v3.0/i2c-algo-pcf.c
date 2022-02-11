static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_3 L_1 ) ) ;
F_4 ( V_2 , 1 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( L_2 ) ) ;
F_4 ( V_2 , 1 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( L_3 ) ) ;
F_4 ( V_2 , 1 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , const int * V_7 )
{
F_8 ( F_3 ( V_8
L_4 ,
* V_7 ) ) ;
F_4 ( V_2 , 1 , V_9 ) ;
F_4 ( V_2 , 1 , V_10 ) ;
if ( V_2 -> V_11 )
F_9 ( V_2 -> V_11 ) ;
F_8 ( F_3 ( V_8
L_5 ,
F_10 ( V_2 , 1 ) ) ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_12 = V_13 ;
int V_7 ;
V_7 = F_10 ( V_2 , 1 ) ;
while ( ! ( V_7 & V_14 ) && -- V_12 ) {
F_12 ( 100 ) ;
V_7 = F_10 ( V_2 , 1 ) ;
}
if ( V_12 == 0 ) {
F_3 ( V_15 L_6 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_7 )
{
int V_12 = V_13 ;
* V_7 = F_10 ( V_2 , 1 ) ;
while ( ( * V_7 & V_9 ) && -- V_12 ) {
V_2 -> V_17 ( V_2 -> V_18 ) ;
* V_7 = F_10 ( V_2 , 1 ) ;
}
if ( * V_7 & V_19 ) {
F_7 ( V_2 , V_7 ) ;
return - V_20 ;
}
if ( V_12 == 0 )
return - V_16 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned char V_21 ;
F_15 ( F_3 ( V_3 L_7 ,
F_10 ( V_2 , 1 ) ) ) ;
F_4 ( V_2 , 1 , V_9 ) ;
if ( ( ( V_21 = F_10 ( V_2 , 1 ) ) & 0x7f ) != ( 0 ) ) {
F_8 ( F_3 ( V_15 L_8 , V_21 ) ) ;
return - V_22 ;
}
F_16 ( V_2 , F_17 ( V_2 ) ) ;
if ( ( V_21 = F_18 ( V_2 ) ) != F_17 ( V_2 ) ) {
F_8 ( F_3 ( V_15 L_9 , V_21 ) ) ;
return - V_22 ;
}
F_4 ( V_2 , 1 , V_9 | V_23 ) ;
if ( ( ( V_21 = F_10 ( V_2 , 1 ) ) & 0x7f ) != V_23 ) {
F_8 ( F_3 ( V_15 L_10 , V_21 ) ) ;
return - V_22 ;
}
F_16 ( V_2 , F_19 ( V_2 ) ) ;
if ( ( ( V_21 = F_18 ( V_2 ) ) & 0x1f ) != F_19 ( V_2 ) ) {
F_8 ( F_3 ( V_15 L_11 , V_21 ) ) ;
return - V_22 ;
}
F_4 ( V_2 , 1 , V_24 ) ;
if ( ( V_21 = F_10 ( V_2 , 1 ) ) != ( V_9 | V_14 ) ) {
F_8 ( F_3 ( V_15 L_12 , V_21 ) ) ;
return - V_22 ;
}
F_3 ( V_3 L_13 ) ;
return 0 ;
}
static int F_20 ( struct V_25 * V_26 , const char * V_27 ,
int V_28 , int V_29 )
{
struct V_1 * V_2 = V_26 -> V_30 ;
int V_31 , V_7 , V_12 ;
for ( V_31 = 0 ; V_31 < V_28 ; ++ V_31 ) {
F_8 ( F_21 ( & V_26 -> V_32 , L_14 ,
V_27 [ V_31 ] & 0xff ) ) ;
F_16 ( V_2 , V_27 [ V_31 ] ) ;
V_12 = F_13 ( V_2 , & V_7 ) ;
if ( V_12 ) {
if ( V_12 == - V_20 )
return - V_20 ;
F_6 ( V_2 ) ;
F_22 ( & V_26 -> V_32 , L_15 ) ;
return - V_33 ;
}
if ( V_7 & V_34 ) {
F_6 ( V_2 ) ;
F_22 ( & V_26 -> V_32 , L_16 ) ;
return - V_33 ;
}
}
if ( V_29 )
F_6 ( V_2 ) ;
else
F_5 ( V_2 ) ;
return V_31 ;
}
static int F_23 ( struct V_25 * V_26 , char * V_27 ,
int V_28 , int V_29 )
{
int V_35 , V_7 ;
struct V_1 * V_2 = V_26 -> V_30 ;
int V_36 ;
for ( V_35 = 0 ; V_35 <= V_28 ; V_35 ++ ) {
if ( ( V_36 = F_13 ( V_2 , & V_7 ) ) ) {
if ( V_36 == - V_20 )
return - V_20 ;
F_6 ( V_2 ) ;
F_22 ( & V_26 -> V_32 , L_17 ) ;
return - 1 ;
}
if ( ( V_7 & V_34 ) && ( V_35 != V_28 ) ) {
F_6 ( V_2 ) ;
F_22 ( & V_26 -> V_32 , L_18 ) ;
return - 1 ;
}
if ( V_35 == V_28 - 1 ) {
F_4 ( V_2 , 1 , V_10 ) ;
} else if ( V_35 == V_28 ) {
if ( V_29 )
F_6 ( V_2 ) ;
else
F_5 ( V_2 ) ;
}
if ( V_35 )
V_27 [ V_35 - 1 ] = F_18 ( V_2 ) ;
else
F_18 ( V_2 ) ;
}
return V_35 - 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
unsigned short V_39 = V_38 -> V_39 ;
unsigned char V_40 ;
V_40 = V_38 -> V_40 << 1 ;
if ( V_39 & V_41 )
V_40 |= 1 ;
if ( V_39 & V_42 )
V_40 ^= 1 ;
F_16 ( V_2 , V_40 ) ;
return 0 ;
}
static int F_25 ( struct V_25 * V_26 ,
struct V_37 * V_43 ,
int V_44 )
{
struct V_1 * V_2 = V_26 -> V_30 ;
struct V_37 * V_45 ;
int V_35 ;
int V_46 = 0 , V_12 , V_7 ;
if ( V_2 -> V_47 )
V_2 -> V_47 ( V_2 -> V_18 ) ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_8 (printk(KERN_ERR L_19
L_20);)
V_35 = - V_48 ;
goto V_49;
}
for ( V_35 = 0 ; V_46 >= 0 && V_35 < V_44 ; V_35 ++ ) {
V_45 = & V_43 [ V_35 ] ;
F_8 (printk(KERN_DEBUG L_21,
pmsg->flags & I2C_M_RD ? L_22 : L_23,
pmsg->len, pmsg->addr, i + 1, num);)
V_46 = F_24 ( V_2 , V_45 ) ;
if ( V_35 == 0 )
F_1 ( V_2 ) ;
V_12 = F_13 ( V_2 , & V_7 ) ;
if ( V_12 ) {
if ( V_12 == - V_20 ) {
V_35 = - V_20 ;
goto V_49;
}
F_6 ( V_2 ) ;
F_8 (printk(KERN_ERR L_24
L_25);)
V_35 = - V_33 ;
goto V_49;
}
if ( V_7 & V_34 ) {
F_6 ( V_2 ) ;
F_8 (printk(KERN_ERR L_26);)
V_35 = - V_33 ;
goto V_49;
}
F_15 (printk(KERN_DEBUG L_27,
i, msgs[i].addr, msgs[i].flags, msgs[i].len);)
if ( V_45 -> V_39 & V_41 ) {
V_46 = F_23 ( V_26 , V_45 -> V_27 , V_45 -> V_50 ,
( V_35 + 1 == V_44 ) ) ;
if ( V_46 != V_45 -> V_50 ) {
F_8 ( F_3 ( V_3 L_28
L_29 , V_46 ) ) ;
} else {
F_8 ( F_3 ( V_3 L_30 , V_46 ) ) ;
}
} else {
V_46 = F_20 ( V_26 , V_45 -> V_27 , V_45 -> V_50 ,
( V_35 + 1 == V_44 ) ) ;
if ( V_46 != V_45 -> V_50 ) {
F_8 ( F_3 ( V_3 L_28
L_31 , V_46 ) ) ;
} else {
F_8 ( F_3 ( V_3 L_32 , V_46 ) ) ;
}
}
}
V_49:
if ( V_2 -> V_51 )
V_2 -> V_51 ( V_2 -> V_18 ) ;
return V_35 ;
}
static T_1 F_26 ( struct V_25 * V_2 )
{
return V_52 | V_53 |
V_54 ;
}
int F_27 ( struct V_25 * V_2 )
{
struct V_1 * V_55 = V_2 -> V_30 ;
int V_56 ;
F_8 ( F_21 ( & V_2 -> V_32 , L_33 ) ) ;
V_2 -> V_57 = & V_58 ;
if ( ( V_56 = F_14 ( V_55 ) ) )
return V_56 ;
V_56 = F_28 ( V_2 ) ;
return V_56 ;
}
