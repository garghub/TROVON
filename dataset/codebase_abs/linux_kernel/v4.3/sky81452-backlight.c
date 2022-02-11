static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 =
F_2 ( V_2 -> V_5 . V_6 ) ;
const unsigned int V_7 = ( unsigned int ) V_2 -> V_8 . V_7 ;
struct V_9 * V_9 = F_3 ( V_2 ) ;
int V_10 ;
if ( V_7 > 0 ) {
V_10 = F_4 ( V_9 , V_11 , V_7 - 1 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_5 ( V_9 , V_12 , V_13 ,
V_4 -> V_14 << F_6 ( V_13 ) ) ;
}
return F_5 ( V_9 , V_12 , V_13 , 0 ) ;
}
static T_1 F_7 ( struct V_15 * V_5 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_19 )
{
struct V_9 * V_9 = F_3 ( F_8 ( V_5 ) ) ;
unsigned long V_20 ;
int V_10 ;
V_10 = F_9 ( V_18 , 16 , & V_20 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_9 , V_12 , V_13 ,
V_20 << F_6 ( V_13 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return V_19 ;
}
static T_1 F_10 ( struct V_15 * V_5 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_9 * V_9 = F_3 ( F_8 ( V_5 ) ) ;
unsigned int V_21 , V_20 = 0 ;
char V_22 [ 3 ] ;
int V_23 , V_10 ;
V_21 = ! strcmp ( V_17 -> V_17 . V_24 , L_1 ) ? V_25 : V_26 ;
V_10 = F_11 ( V_9 , V_21 , & V_20 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_20 & V_27 ) {
* V_18 = 0 ;
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ ) {
if ( V_20 & 0x01 ) {
sprintf ( V_22 , L_2 , V_23 + 1 ) ;
strcat ( V_18 , V_22 ) ;
}
V_20 >>= 1 ;
}
strcat ( V_18 , L_3 ) ;
} else {
strcpy ( V_18 , L_4 ) ;
}
return strlen ( V_18 ) ;
}
static T_1 F_12 ( struct V_15 * V_5 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_9 * V_9 = F_3 ( F_8 ( V_5 ) ) ;
unsigned int V_20 = 0 ;
int V_10 ;
V_10 = F_11 ( V_9 , V_26 , & V_20 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_18 = 0 ;
if ( V_20 & V_28 )
strcat ( V_18 , L_5 ) ;
if ( V_20 & V_29 )
strcat ( V_18 , L_6 ) ;
strcat ( V_18 , L_3 ) ;
return strlen ( V_18 ) ;
}
static struct V_3 * F_13 (
struct V_15 * V_5 )
{
struct V_30 * V_31 = F_14 ( V_5 -> V_32 ) ;
struct V_3 * V_4 ;
int V_33 ;
unsigned int V_34 [ 6 ] ;
int V_10 ;
if ( ! V_31 ) {
F_15 ( V_5 , L_7 ) ;
return F_16 ( - V_35 ) ;
}
V_4 = F_17 ( V_5 , sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 ) {
F_18 ( V_31 ) ;
return F_16 ( - V_37 ) ;
}
F_19 ( V_31 , L_8 , & V_4 -> V_24 ) ;
V_4 -> V_38 = F_20 ( V_31 , L_9 ) ;
V_4 -> V_39 = F_20 ( V_31 , L_10 ) ;
V_4 -> V_40 = F_20 ( V_31 , L_11 ) ;
V_4 -> V_41 = F_21 ( V_31 , 0 ) ;
V_10 = F_22 ( V_31 , L_12 ) ;
if ( V_10 < 0 ) {
V_4 -> V_14 = V_13 >> F_6 ( V_13 ) ;
} else {
V_33 = V_10 ;
if ( V_33 > 6 )
V_33 = 6 ;
V_10 = F_23 ( V_31 , L_12 , V_34 ,
V_33 ) ;
if ( V_10 < 0 ) {
F_15 ( V_5 , L_13 ) ;
return F_16 ( - V_42 ) ;
}
V_4 -> V_14 = 0 ;
while ( -- V_33 )
V_4 -> V_14 |= ( 1 << V_34 [ V_33 ] ) ;
}
V_10 = F_24 ( V_31 ,
L_14 ,
& V_4 -> V_43 ) ;
if ( V_10 < 0 )
V_4 -> V_43 = 7 ;
V_10 = F_24 ( V_31 , L_15 ,
& V_4 -> V_44 ) ;
if ( V_10 < 0 )
V_4 -> V_44 = 2750 ;
F_18 ( V_31 ) ;
return V_4 ;
}
static struct V_3 * F_13 (
struct V_15 * V_5 )
{
return F_16 ( - V_42 ) ;
}
static int F_25 ( struct V_9 * V_9 ,
struct V_3 * V_4 )
{
unsigned int V_20 ;
V_20 = V_4 -> V_38 ? V_45 : 0 ;
V_20 |= V_4 -> V_39 ? V_46 : 0 ;
V_20 |= V_4 -> V_40 ? 0 : V_47 ;
if ( V_4 -> V_44 == 2300 )
V_20 |= V_48 ;
else if ( V_4 -> V_44 != 2750 )
return - V_42 ;
if ( V_4 -> V_43 < 4 ||
V_4 -> V_43 > 7 )
return - V_42 ;
V_20 |= ( 7 - V_4 -> V_43 ) << F_6 ( V_49 ) ;
return F_4 ( V_9 , V_50 , V_20 ) ;
}
static int F_26 ( struct V_51 * V_52 )
{
struct V_15 * V_5 = & V_52 -> V_5 ;
struct V_9 * V_9 = F_27 ( V_5 -> V_6 ) ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_1 * V_2 ;
struct V_53 V_8 ;
const char * V_24 ;
int V_10 ;
if ( ! V_4 ) {
V_4 = F_13 ( V_5 ) ;
if ( F_28 ( V_4 ) )
return F_29 ( V_4 ) ;
}
if ( F_30 ( V_4 -> V_41 ) ) {
V_10 = F_31 ( V_5 , V_4 -> V_41 ,
V_54 , L_16 ) ;
if ( V_10 < 0 ) {
F_15 ( V_5 , L_17 , V_10 ) ;
return V_10 ;
}
}
V_10 = F_25 ( V_9 , V_4 ) ;
if ( V_10 < 0 ) {
F_15 ( V_5 , L_18 , V_10 ) ;
return V_10 ;
}
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_55 = V_56 ,
V_24 = V_4 -> V_24 ? V_4 -> V_24 : V_57 ;
V_2 = F_32 ( V_5 , V_24 , V_5 , V_9 ,
& V_58 , & V_8 ) ;
if ( F_28 ( V_2 ) ) {
F_15 ( V_5 , L_19 , F_29 ( V_2 ) ) ;
return F_29 ( V_2 ) ;
}
F_33 ( V_52 , V_2 ) ;
V_10 = F_34 ( & V_2 -> V_5 . V_59 , & V_60 ) ;
if ( V_10 < 0 ) {
F_15 ( V_5 , L_20 , V_10 ) ;
return V_10 ;
}
return V_10 ;
}
static int F_35 ( struct V_51 * V_52 )
{
const struct V_3 * V_4 =
F_2 ( & V_52 -> V_5 ) ;
struct V_1 * V_2 = F_36 ( V_52 ) ;
F_37 ( & V_2 -> V_5 . V_59 , & V_60 ) ;
V_2 -> V_8 . V_61 = V_62 ;
V_2 -> V_8 . V_7 = 0 ;
F_38 ( V_2 ) ;
if ( F_30 ( V_4 -> V_41 ) )
F_39 ( V_4 -> V_41 , 0 ) ;
return 0 ;
}
