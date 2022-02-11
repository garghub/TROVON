static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( & V_4 -> V_7 ) ;
if ( F_4 ( V_8 , V_4 -> V_9 + V_10 ) || ! V_4 -> V_11 ) {
V_4 -> V_12 . V_13 = F_5 ( V_6 , V_14 ) ;
V_4 -> V_12 . V_15 = F_5 ( V_6 ,
V_16 ) ;
V_4 -> V_12 . V_17 = F_5 ( V_6 , V_18 ) ;
V_4 -> V_12 . V_19 = F_5 ( V_6 , V_20 ) ;
V_4 -> V_11 = 1 ;
}
F_6 ( & V_4 -> V_7 ) ;
return V_4 ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
V_24 = sprintf ( V_23 , L_1 , F_8 ( V_4 -> V_12 . V_13 & V_25 ,
V_4 -> V_26 ) ) ;
return V_24 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_21 * V_22 , const char * V_23 ,
T_2 V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_13 , V_28 ;
unsigned long V_29 ;
int V_30 ;
V_30 = F_10 ( V_23 , 10 , & V_29 ) ;
if ( V_30 )
return V_30 ;
V_29 /= 25 ;
V_29 *= 25 ;
V_13 = F_11 ( V_29 , V_4 -> V_26 ) ;
if ( V_13 < 0 ) {
F_12 ( V_3 , L_2 ) ;
return V_13 ;
}
if ( V_4 -> V_12 . V_13 & V_31 )
V_28 = V_4 -> V_12 . V_13 & V_25 ;
else
V_28 = V_4 -> V_12 . V_15 ;
if ( V_13 == V_28 )
return V_27 ;
F_13 ( V_3 , L_3 , ( int ) V_29 , V_13 ) ;
if ( V_28 > V_13 ) {
for (; V_28 >= V_13 ; V_28 -- )
F_14 ( V_6 ,
V_14 , V_28 | V_31 ) ;
} else {
for (; V_28 <= V_13 ; V_28 ++ )
F_14 ( V_6 ,
V_14 , V_28 | V_31 ) ;
}
V_4 -> V_11 = 0 ;
return V_27 ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_21 * V_22 ,
char * V_23 )
{
int V_24 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
V_24 = sprintf ( V_23 , L_4 , V_4 -> V_12 . V_17 & V_32 ) ;
return V_24 ;
}
static T_1 F_16 ( struct V_2 * V_3 , struct V_21 * V_22 ,
const char * V_23 , T_2 V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_33 ;
int V_30 ;
V_30 = F_10 ( V_23 , 16 , & V_33 ) ;
if ( V_30 )
return V_30 ;
V_33 &= V_32 ;
if ( V_33 != ( V_4 -> V_12 . V_17 & V_32 ) ) {
F_17 ( V_3 , L_5 , ( unsigned int ) V_33 ) ;
F_14 ( V_6 , V_18 , V_33 ) ;
V_4 -> V_11 = 0 ;
}
return V_27 ;
}
static T_1 F_18 ( struct V_2 * V_3 , struct V_21 * V_22 ,
char * V_23 )
{
int V_24 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
V_24 = sprintf ( V_23 , L_4 , V_4 -> V_12 . V_19 ) ;
return V_24 ;
}
static T_1 F_19 ( struct V_2 * V_3 , struct V_21 * V_22 ,
const char * V_23 , T_2 V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_33 ;
int V_30 ;
V_30 = F_10 ( V_23 , 16 , & V_33 ) ;
if ( V_30 )
return V_30 ;
V_33 &= 0xff ;
if ( V_33 != V_4 -> V_12 . V_19 ) {
F_17 ( V_3 , L_5 , ( unsigned int ) V_33 ) ;
F_14 ( V_6 , V_20 , V_33 ) ;
V_4 -> V_11 = 0 ;
}
return V_27 ;
}
static int F_20 ( struct V_5 * V_6 ,
const struct V_34 * V_35 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_36 ;
V_4 = F_21 ( V_3 , sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_4 )
return - V_38 ;
V_4 -> V_26 = F_22 () ;
if ( V_4 -> V_26 != 90 && V_4 -> V_26 != 91 ) {
F_12 ( V_3 , L_6 ,
V_4 -> V_26 / 10 , V_4 -> V_26 % 10 ) ;
return - V_39 ;
}
V_4 -> V_6 = V_6 ;
F_23 ( & V_4 -> V_7 ) ;
V_36 = F_24 ( V_3 , V_6 -> V_40 ,
V_4 ,
V_41 ) ;
if ( F_25 ( V_36 ) )
return F_26 ( V_36 ) ;
F_17 ( V_3 , L_7 , V_4 -> V_26 / 10 , V_4 -> V_26 % 10 ) ;
return 0 ;
}
