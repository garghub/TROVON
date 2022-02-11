static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_3 = V_3 | V_5 ;
V_4 = F_2 ( V_2 , V_3 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_3 = V_3 | V_5 | V_6 ;
V_4 = F_4 ( V_2 , V_3 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
T_1 V_8 [ 2 ] = { V_3 , V_7 } ;
return F_6 ( V_2 , V_8 , sizeof( V_8 ) ) ;
}
static T_2 F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_4 , V_7 , V_16 = 0 ;
T_3 V_17 , V_18 ;
V_17 = V_15 -> V_19 ;
F_5 ( V_2 , V_20 ,
( V_21 | V_22 | V_17 ) ) ;
V_4 = F_1 ( V_2 , V_20 ) ;
V_18 = ( ( V_4 & V_21 ) >> V_23 ) ;
while ( ( V_16 < 2 ) && V_18 ) {
V_16 ++ ;
V_4 = F_1 ( V_2 , V_20 ) ;
V_18 = ( ( V_4 & V_21 ) >> V_23 ) ;
F_10 ( 1 ) ;
}
if ( V_18 == 0 ) {
V_7 = F_3 ( V_2 , V_24 ) ;
V_7 = ( ( V_7 >> 2 ) * 25000 ) / 8192 ;
return sprintf ( V_13 , L_1 , V_7 ) ;
} else {
return - 1 ;
}
}
static T_2 F_11 ( struct V_9 * V_10 ,
struct V_11 * V_25 , char * V_13 )
{
return sprintf ( V_13 , L_2 , F_8 ( V_10 ) -> V_26 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_4 , V_27 ;
T_3 V_7 ;
struct V_28 * V_29 ;
F_13 ( & V_2 -> V_10 , L_3 ) ;
V_2 -> V_30 = ( V_31 ) ;
V_2 -> V_32 = 8 ;
F_14 ( V_2 ) ;
F_5 ( V_2 , V_33 , 0 ) ;
F_5 ( V_2 , V_34 , 0 ) ;
V_7 = ( V_35 | V_36 | V_37 | V_38 ) ;
F_5 ( V_2 , V_39 , V_7 ) ;
V_4 = F_1 ( V_2 , V_39 ) ;
F_13 ( & V_2 -> V_10 , L_4 , V_7 , V_4 ) ;
if ( V_7 != V_4 )
return - V_40 ;
V_29 = F_15 ( & V_2 -> V_10 , sizeof( struct V_28 ) ,
V_41 ) ;
if ( ! V_29 )
return - V_42 ;
V_27 = F_16 ( & V_2 -> V_10 . V_43 , & V_44 ) ;
if ( V_27 < 0 )
return V_27 ;
F_17 ( V_2 , V_29 ) ;
V_29 -> V_45 = F_18 ( & V_2 -> V_10 ) ;
if ( F_19 ( V_29 -> V_45 ) ) {
V_27 = F_20 ( V_29 -> V_45 ) ;
goto V_46;
}
return 0 ;
V_46:
F_21 ( & V_2 -> V_10 . V_43 , & V_44 ) ;
return V_27 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_23 ( V_2 ) ;
F_24 ( V_29 -> V_45 ) ;
F_21 ( & V_2 -> V_10 . V_43 , & V_44 ) ;
return 0 ;
}
