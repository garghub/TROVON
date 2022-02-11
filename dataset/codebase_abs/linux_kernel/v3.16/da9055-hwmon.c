static int F_1 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
int V_4 ;
unsigned short V_5 ;
unsigned short V_6 ;
unsigned char V_7 ;
struct V_8 * V_8 = V_2 -> V_8 ;
if ( V_3 > V_9 )
return - V_10 ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = V_12 [ V_3 ] | V_13 ;
V_4 = F_3 ( V_8 , V_14 , V_7 ) ;
if ( V_4 < 0 )
goto V_15;
if ( ! F_4 ( & V_2 -> V_16 ,
F_5 ( 500 ) ) ) {
F_6 ( V_8 -> V_17 ,
L_1 ) ;
V_4 = - V_18 ;
goto V_15;
}
V_4 = F_7 ( V_8 , V_19 ) ;
if ( V_4 < 0 )
goto V_15;
V_5 = ( unsigned short ) V_4 ;
V_6 = V_5 << 2 ;
V_4 = F_7 ( V_8 , V_20 ) ;
if ( V_4 < 0 )
goto V_15;
V_5 = ( unsigned short ) ( V_4 & V_21 ) ;
V_6 |= V_5 ;
V_4 = V_6 ;
V_15:
F_8 ( & V_2 -> V_11 ) ;
return V_4 ;
}
static T_1 F_9 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
F_10 ( & V_2 -> V_16 ) ;
return V_24 ;
}
static inline int F_11 ( int V_25 , int V_3 )
{
if ( V_3 == V_26 )
return F_12 ( V_25 * 1000 , V_27 ) + 2500 ;
else
return F_12 ( V_25 * 1000 , V_28 ) ;
}
static int F_13 ( struct V_8 * V_8 , int V_3 )
{
return F_14 ( V_8 , V_29 , 1 << V_3 ,
1 << V_3 ) ;
}
static int F_15 ( struct V_8 * V_8 , int V_3 )
{
return F_14 ( V_8 , V_29 , 1 << V_3 , 0 ) ;
}
static T_2 F_16 ( struct V_30 * V_17 ,
struct V_31 * V_32 , char * V_33 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
int V_4 , V_34 ;
int V_3 = F_18 ( V_32 ) -> V_35 ;
F_2 ( & V_2 -> V_36 ) ;
V_4 = F_13 ( V_2 -> V_8 , V_3 ) ;
if ( V_4 < 0 )
goto V_37;
F_19 ( 10000 , 10500 ) ;
V_34 = F_7 ( V_2 -> V_8 , V_38 + V_3 ) ;
if ( V_34 < 0 ) {
V_4 = V_34 ;
goto V_39;
}
V_4 = F_15 ( V_2 -> V_8 , V_3 ) ;
if ( V_4 < 0 )
goto V_37;
F_8 ( & V_2 -> V_36 ) ;
return sprintf ( V_33 , L_2 , F_11 ( V_34 , V_3 ) ) ;
V_39:
F_15 ( V_2 -> V_8 , V_3 ) ;
V_37:
F_8 ( & V_2 -> V_36 ) ;
return V_4 ;
}
static T_2 F_20 ( struct V_30 * V_17 ,
struct V_31 * V_32 , char * V_33 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
int V_40 ;
int V_41 ;
V_40 = F_1 ( V_2 , V_9 ) ;
if ( V_40 < 0 )
return V_40 ;
V_41 = F_7 ( V_2 -> V_8 , V_42 ) ;
if ( V_41 < 0 )
return V_41 ;
return sprintf ( V_33 , L_2 , F_12 ( - 4084 * ( V_40 - V_41 )
+ 3076332 , 10000 ) ) ;
}
static T_2 F_21 ( struct V_30 * V_17 ,
struct V_31 * V_32 ,
char * V_33 )
{
return sprintf ( V_33 , L_3 ) ;
}
static T_2 F_22 ( struct V_30 * V_17 ,
struct V_31 * V_32 , char * V_33 )
{
return sprintf ( V_33 , L_4 ,
V_43 [ F_18 ( V_32 ) -> V_35 ] ) ;
}
static int F_23 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_46 , V_4 ;
V_2 = F_24 ( & V_45 -> V_17 , sizeof( struct V_1 ) ,
V_47 ) ;
if ( ! V_2 )
return - V_48 ;
F_25 ( & V_2 -> V_36 ) ;
F_25 ( & V_2 -> V_11 ) ;
F_26 ( & V_2 -> V_16 ) ;
V_2 -> V_8 = F_17 ( V_45 -> V_17 . V_49 ) ;
F_27 ( V_45 , V_2 ) ;
V_46 = F_28 ( V_45 , L_5 ) ;
if ( V_46 < 0 )
return V_46 ;
V_4 = F_29 ( & V_45 -> V_17 , V_46 ,
NULL , F_9 ,
V_50 | V_51 ,
L_6 , V_2 ) ;
if ( V_4 != 0 ) {
F_6 ( V_2 -> V_8 -> V_17 , L_7 ,
V_4 ) ;
return V_4 ;
}
V_4 = F_30 ( & V_45 -> V_17 . V_52 , & V_53 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_54 = F_31 ( & V_45 -> V_17 ) ;
if ( F_32 ( V_2 -> V_54 ) ) {
V_4 = F_33 ( V_2 -> V_54 ) ;
goto V_15;
}
return 0 ;
V_15:
F_34 ( & V_45 -> V_17 . V_52 , & V_53 ) ;
return V_4 ;
}
static int F_35 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_36 ( V_45 ) ;
F_34 ( & V_45 -> V_17 . V_52 , & V_53 ) ;
F_37 ( V_2 -> V_54 ) ;
return 0 ;
}
