static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , ! V_7 -> V_9 . V_10 . V_11 -> V_12 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 > 1 )
return - V_17 ;
if ( V_7 -> V_9 . V_10 . V_11 -> V_12 == V_15 ) {
V_16 = F_5 ( V_7 -> V_9 . V_10 . V_11 , V_15 ) ;
if ( V_16 )
V_14 = V_16 ;
} else {
F_6 ( V_18 , L_2 , V_15 ) ;
}
return V_14 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_19 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
T_3 V_20 ;
V_20 = F_8 ( & V_7 -> V_9 . V_10 ) ;
V_19 = sprintf ( V_5 , L_1 , V_20 ) ;
return V_19 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_16 ;
unsigned long V_15 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_10 ( & V_7 -> V_9 . V_10 , V_15 ) ;
if ( V_16 )
V_14 = V_16 ;
return V_14 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
T_4 V_20 ;
int V_19 ;
V_20 = V_7 -> V_9 . V_10 . V_21 ;
V_19 = sprintf ( V_5 , L_3 , V_20 ) ;
return V_19 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
T_4 V_15 ;
int V_16 ;
V_16 = F_13 ( V_13 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_14 ( & V_7 -> V_9 . V_10 , V_15 ) ;
if ( V_16 )
V_14 = V_16 ;
return V_14 ;
}
static int F_15 ( struct V_22 * V_23 , void * V_24 )
{
struct V_6 * V_7 = V_23 -> V_25 ;
return F_16 ( & V_7 -> V_9 . V_10 , V_23 ) ;
}
static T_1 F_17 ( struct V_26 * V_26 ,
const char T_5 * V_5 ,
T_2 V_19 , T_6 * V_27 )
{
struct V_22 * V_23 = V_26 -> V_28 ;
struct V_6 * V_7 = V_23 -> V_25 ;
struct V_29 * V_10 = & V_7 -> V_9 . V_10 ;
F_18 ( & V_10 -> V_30 ) ;
return V_19 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_29 * V_10 = & V_7 -> V_9 . V_10 ;
return sprintf ( V_5 , L_4 , V_10 -> V_31 ) ;
}
void F_20 ( struct V_32 * V_33 )
{
V_33 -> V_34 = & V_35 ;
V_33 -> V_36 = V_37 ;
}
