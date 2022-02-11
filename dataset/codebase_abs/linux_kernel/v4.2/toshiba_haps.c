static int F_1 ( T_1 V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 , L_1 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_2 ) ;
return - V_3 ;
}
return 0 ;
}
static int F_5 ( T_1 V_1 , int V_4 )
{
T_2 V_2 ;
V_2 = F_6 ( V_1 , L_3 , V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_4 ) ;
return - V_3 ;
}
F_7 ( L_5 , V_4 ) ;
return 0 ;
}
static T_3 F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_6 , V_11 -> V_12 ) ;
}
static T_3 F_10 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_4 V_13 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_4 ;
int V_14 ;
V_14 = F_11 ( V_9 , 0 , & V_4 ) ;
if ( V_14 )
return V_14 ;
if ( V_4 < 0 || V_4 > 3 )
return - V_15 ;
V_14 = F_5 ( V_11 -> V_16 -> V_1 , V_4 ) ;
if ( V_14 != 0 )
return V_14 ;
V_11 -> V_12 = V_4 ;
return V_13 ;
}
static T_3 F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_4 V_13 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_17 ;
int V_14 ;
V_14 = F_11 ( V_9 , 0 , & V_17 ) ;
if ( V_14 )
return V_14 ;
if ( V_17 != 1 )
return - V_15 ;
V_14 = F_1 ( V_11 -> V_16 -> V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
return V_13 ;
}
static void F_13 ( struct V_18 * V_5 , T_5 V_19 )
{
F_7 ( L_7 , V_19 ) ;
F_14 ( V_5 -> V_20 . V_21 ,
F_15 ( & V_5 -> V_6 ) ,
V_19 , 0 ) ;
}
static int F_16 ( struct V_18 * V_5 )
{
F_17 ( & V_5 -> V_6 . V_22 , & V_23 ) ;
if ( V_24 )
V_24 = NULL ;
return 0 ;
}
static int F_18 ( T_1 V_1 )
{
T_2 V_2 ;
T_6 V_25 ;
V_2 = F_19 ( V_1 , L_8 , NULL ,
& V_25 ) ;
if ( F_3 ( V_2 ) || ! V_25 ) {
F_7 ( L_9 ) ;
return 0 ;
}
return 1 ;
}
static int F_20 ( struct V_18 * V_16 )
{
struct V_10 * V_11 ;
int V_14 ;
if ( V_24 )
return - V_26 ;
if ( ! F_18 ( V_16 -> V_1 ) )
return - V_27 ;
F_7 ( L_10 ) ;
V_11 = F_21 ( sizeof( struct V_10 ) , V_28 ) ;
if ( ! V_11 )
return - V_29 ;
V_11 -> V_16 = V_16 ;
V_11 -> V_12 = 2 ;
V_16 -> V_30 = V_11 ;
F_22 ( & V_16 -> V_6 , V_11 ) ;
V_14 = F_5 ( V_16 -> V_1 , 2 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_23 ( & V_16 -> V_6 . V_22 , & V_23 ) ;
if ( V_14 )
return V_14 ;
V_24 = V_11 ;
return 0 ;
}
static int F_24 ( struct V_5 * V_5 )
{
struct V_10 * V_11 ;
int V_14 ;
V_11 = F_25 ( F_26 ( V_5 ) ) ;
V_14 = F_5 ( V_11 -> V_16 -> V_1 , 0 ) ;
return V_14 ;
}
static int F_27 ( struct V_5 * V_5 )
{
struct V_10 * V_11 ;
int V_14 ;
V_11 = F_25 ( F_26 ( V_5 ) ) ;
V_14 = F_5 ( V_11 -> V_16 -> V_1 ,
V_11 -> V_12 ) ;
V_14 = F_1 ( V_11 -> V_16 -> V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
return V_14 ;
}
