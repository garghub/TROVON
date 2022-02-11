static int F_1 ( struct V_1 * V_2 ,
unsigned short V_3 , void * * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_9 ) {
F_3 ( & V_6 -> V_8 ) ;
return - V_10 ;
}
V_6 -> V_9 ++ ;
F_3 ( & V_6 -> V_8 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned short V_3 , void * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( & V_6 -> V_8 ) ;
V_6 -> V_9 -- ;
F_3 ( & V_6 -> V_8 ) ;
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
void * V_4 ,
struct V_11 * V_11 , char T_2 * V_12 ,
T_3 V_13 , T_4 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
char * V_15 ;
V_15 = F_6 ( V_13 ) ;
if ( ! V_15 )
return - V_16 ;
F_7 ( V_6 , V_15 , V_14 , V_13 ) ;
if ( F_8 ( V_12 , V_15 , V_13 ) ) {
F_9 ( V_15 ) ;
return - V_17 ;
}
F_9 ( V_15 ) ;
return V_13 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
void * V_4 ,
struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
char * V_15 ;
V_15 = F_6 ( V_13 ) ;
if ( ! V_15 )
return - V_16 ;
if ( F_11 ( V_15 , V_12 , V_13 ) ) {
F_9 ( V_15 ) ;
return - V_17 ;
}
F_12 ( V_6 , V_15 , V_14 , V_13 ) ;
F_9 ( V_15 ) ;
return V_13 ;
}
int F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_6 -> V_18 , L_1 , V_6 -> V_18 -> V_19 ) ;
if ( V_2 ) {
if ( V_6 -> V_20 < V_21 ) {
V_2 -> V_3 |= V_22 ;
V_2 -> V_23 = 4 * 1024 * 1024 ;
} else {
V_2 -> V_23 = 1 * 1024 * 1024 ;
}
V_2 -> V_24 = V_25 ;
V_2 -> V_26 . V_27 = & V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_7 = V_6 ;
if ( F_15 ( V_2 ) < 0 ) {
F_16 ( V_2 ) ;
V_2 = NULL ;
}
}
V_6 -> V_31 = V_2 ;
return 0 ;
}
void F_17 ( struct V_5 * V_6 )
{
F_16 ( V_6 -> V_31 ) ;
}
