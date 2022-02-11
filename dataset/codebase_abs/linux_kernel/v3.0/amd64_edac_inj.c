static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return sprintf ( V_3 , L_1 , V_5 -> V_7 . V_8 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
const char * V_9 , T_2 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_11 ;
int V_12 = 0 ;
V_12 = F_3 ( V_9 , 10 , & V_11 ) ;
if ( V_12 != - V_13 ) {
if ( V_11 > 3 ) {
F_4 ( L_2 , V_14 , V_11 ) ;
return - V_13 ;
}
V_5 -> V_7 . V_8 = ( V_15 ) V_11 ;
return V_10 ;
}
return V_12 ;
}
static T_1 F_5 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return sprintf ( V_3 , L_1 , V_5 -> V_7 . V_16 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
const char * V_9 , T_2 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_11 ;
int V_12 = 0 ;
V_12 = F_3 ( V_9 , 10 , & V_11 ) ;
if ( V_12 != - V_13 ) {
if ( V_11 > 8 ) {
F_4 ( L_3 , V_14 , V_11 ) ;
return - V_13 ;
}
V_5 -> V_7 . V_16 = ( V_15 ) V_11 ;
return V_10 ;
}
return V_12 ;
}
static T_1 F_7 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return sprintf ( V_3 , L_1 , V_5 -> V_7 . V_17 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
const char * V_9 , T_2 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_11 ;
int V_12 = 0 ;
V_12 = F_3 ( V_9 , 16 , & V_11 ) ;
if ( V_12 != - V_13 ) {
if ( V_11 & 0xFFFF0000 ) {
F_4 ( L_4 ,
V_14 , V_11 ) ;
return - V_13 ;
}
V_5 -> V_7 . V_17 = ( V_15 ) V_11 ;
return V_10 ;
}
return V_12 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
const char * V_9 , T_2 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_11 ;
V_15 V_8 , V_18 ;
int V_12 = 0 ;
V_12 = F_3 ( V_9 , 10 , & V_11 ) ;
if ( V_12 != - V_13 ) {
V_8 = V_19 |
F_10 ( V_5 -> V_7 . V_8 ) ;
F_11 ( V_5 -> V_20 , V_21 , V_8 ) ;
V_18 = F_12 ( V_5 -> V_7 . V_16 ,
V_5 -> V_7 . V_17 ) ;
F_11 ( V_5 -> V_20 , V_22 , V_18 ) ;
F_13 ( L_5 , V_8 , V_18 ) ;
return V_10 ;
}
return V_12 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
const char * V_9 , T_2 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_11 ;
V_15 V_8 , V_18 ;
int V_12 = 0 ;
V_12 = F_3 ( V_9 , 10 , & V_11 ) ;
if ( V_12 != - V_13 ) {
V_8 = V_19 |
F_10 ( V_5 -> V_7 . V_8 ) ;
F_11 ( V_5 -> V_20 , V_21 , V_8 ) ;
V_18 = F_15 ( V_5 -> V_7 . V_16 ,
V_5 -> V_7 . V_17 ) ;
F_11 ( V_5 -> V_20 , V_22 , V_18 ) ;
F_13 ( L_5 , V_8 , V_18 ) ;
return V_10 ;
}
return V_12 ;
}
