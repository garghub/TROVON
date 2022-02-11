static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 , V_9 -> V_11 . V_12 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
int V_16 = 0 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 != - V_17 ) {
if ( V_15 > 3 ) {
F_5 ( L_2 , V_18 , V_15 ) ;
return - V_17 ;
}
V_9 -> V_11 . V_12 = ( V_19 ) V_15 ;
return V_14 ;
}
return V_16 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 , V_9 -> V_11 . V_20 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
int V_16 = 0 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 != - V_17 ) {
if ( V_15 > 8 ) {
F_5 ( L_3 , V_18 , V_15 ) ;
return - V_17 ;
}
V_9 -> V_11 . V_20 = ( V_19 ) V_15 ;
return V_14 ;
}
return V_16 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 , V_9 -> V_11 . V_21 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
int V_16 = 0 ;
V_16 = F_4 ( V_13 , 16 , & V_15 ) ;
if ( V_16 != - V_17 ) {
if ( V_15 & 0xFFFF0000 ) {
F_5 ( L_4 ,
V_18 , V_15 ) ;
return - V_17 ;
}
V_9 -> V_11 . V_21 = ( V_19 ) V_15 ;
return V_14 ;
}
return V_16 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
V_19 V_12 , V_22 ;
int V_16 = 0 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 != - V_17 ) {
V_12 = V_23 |
F_11 ( V_9 -> V_11 . V_12 ) ;
F_12 ( V_9 -> V_24 , V_25 , V_12 ) ;
V_22 = F_13 ( V_9 -> V_11 . V_20 ,
V_9 -> V_11 . V_21 ) ;
F_12 ( V_9 -> V_24 , V_26 , V_22 ) ;
F_14 ( 0 , L_5 ,
V_12 , V_22 ) ;
return V_14 ;
}
return V_16 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
V_19 V_12 , V_22 ;
int V_16 = 0 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 != - V_17 ) {
V_12 = V_23 |
F_11 ( V_9 -> V_11 . V_12 ) ;
F_12 ( V_9 -> V_24 , V_25 , V_12 ) ;
V_22 = F_16 ( V_9 -> V_11 . V_20 ,
V_9 -> V_11 . V_21 ) ;
F_12 ( V_9 -> V_24 , V_26 , V_22 ) ;
F_14 ( 0 , L_5 ,
V_12 , V_22 ) ;
return V_14 ;
}
return V_16 ;
}
int F_17 ( struct V_6 * V_7 )
{
int V_27 ;
V_27 = F_18 ( & V_7 -> V_2 , & V_28 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_18 ( & V_7 -> V_2 , & V_29 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_18 ( & V_7 -> V_2 , & V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_18 ( & V_7 -> V_2 , & V_31 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_18 ( & V_7 -> V_2 , & V_32 ) ;
if ( V_27 < 0 )
return V_27 ;
return 0 ;
}
void F_19 ( struct V_6 * V_7 )
{
F_20 ( & V_7 -> V_2 , & V_28 ) ;
F_20 ( & V_7 -> V_2 , & V_29 ) ;
F_20 ( & V_7 -> V_2 , & V_30 ) ;
F_20 ( & V_7 -> V_2 , & V_31 ) ;
F_20 ( & V_7 -> V_2 , & V_32 ) ;
}
