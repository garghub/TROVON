int F_1 ( int V_1 , int V_2 , int V_3 )
{
return V_1 * V_2 * V_3 ;
}
int F_2 ( struct V_4 * V_5 )
{
int V_1 ;
V_1 = F_3 ( F_4 ( V_5 ) ) ;
if ( V_1 < 0 )
return V_1 ;
return F_1 ( V_1 , F_5 ( V_5 ) ,
1 ) ;
}
int F_6 ( int V_6 , int V_1 , int V_2 , int V_3 )
{
return V_6 * F_1 ( V_1 , V_2 , V_3 ) ;
}
int F_7 ( struct V_4 * V_5 )
{
int V_7 ;
V_7 = F_2 ( V_5 ) ;
if ( V_7 > 0 )
return V_7 * F_8 ( V_5 ) ;
else
return V_7 ;
}
int F_9 ( struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_11 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_11 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
int F_14 ( struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_15 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_15 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
int F_16 ( struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_17 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_17 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
int F_18 ( struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_19 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_19 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
int F_20 ( struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_21 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_21 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
int F_22 ( struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_23 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_23 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
int F_24 ( struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_25 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_25 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
int F_26 ( struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_27 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_27 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
int F_28 (
struct V_8 * V_9 ,
const char * V_10 )
{
struct V_11 * V_12 =
F_10 ( V_9 ) ;
char * V_13 ;
int V_7 ;
if ( ! V_9 -> V_14 )
return F_29 ( V_12 , V_10 ) ;
V_13 = F_12 ( V_15 , L_1 , V_9 -> V_14 , V_10 ) ;
if ( ! V_13 )
return - V_16 ;
V_7 = F_29 ( V_12 , V_13 ) ;
F_13 ( V_13 ) ;
return V_7 ;
}
static int F_30 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
if ( ! V_20 -> V_22 -> V_23 )
F_31 ( V_18 , & V_24 ) ;
return 0 ;
}
int F_32 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 == & V_28 )
return 1 ;
return 0 ;
}
static int F_33 ( struct V_29 * V_30 )
{
int V_7 ;
V_7 = F_34 ( & V_30 -> V_31 , & V_32 , & V_28 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_35 ( & V_30 -> V_31 , & V_33 ) ;
if ( V_7 < 0 ) {
F_36 ( & V_30 -> V_31 ) ;
return V_7 ;
}
return V_7 ;
}
static int F_37 ( struct V_29 * V_30 )
{
F_38 ( & V_30 -> V_31 ) ;
F_36 ( & V_30 -> V_31 ) ;
return 0 ;
}
int T_1 F_39 ( void )
{
int V_7 ;
V_34 =
F_40 ( L_2 , - 1 , NULL , 0 ) ;
if ( F_41 ( V_34 ) )
return F_42 ( V_34 ) ;
V_7 = F_43 ( & V_35 ) ;
if ( V_7 != 0 )
F_44 ( V_34 ) ;
return V_7 ;
}
void T_2 F_45 ( void )
{
F_44 ( V_34 ) ;
F_46 ( & V_35 ) ;
}
