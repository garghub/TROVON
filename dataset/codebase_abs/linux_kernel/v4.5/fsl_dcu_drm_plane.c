static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned int V_7 = V_4 -> V_8 -> V_7 ;
unsigned int V_9 ;
V_9 = F_2 ( V_2 ) ;
if ( V_9 < V_7 )
return V_7 - V_9 - 1 ;
F_3 ( V_4 -> V_5 , L_1 ) ;
return - V_10 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
switch ( V_14 -> V_15 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return 0 ;
default:
return - V_10 ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned int V_23 ;
int V_9 , V_24 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
return;
V_24 = F_6 ( V_4 -> V_25 , F_7 ( V_9 , 4 ) , & V_23 ) ;
if ( V_24 )
F_3 ( V_4 -> V_5 , L_2 ) ;
V_23 &= ~ V_26 ;
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 4 ) , V_23 ) ;
if ( V_24 )
F_3 ( V_4 -> V_5 , L_3 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_11 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_12 -> V_14 ;
struct V_27 * V_28 ;
unsigned int V_29 , V_30 ;
int V_9 , V_24 ;
if ( ! V_14 )
return;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
return;
V_28 = F_10 ( V_14 , 0 ) ;
switch ( V_14 -> V_15 ) {
case V_16 :
V_30 = V_31 ;
V_29 = 0xff ;
break;
case V_17 :
V_30 = V_32 ;
V_29 = 0xff ;
break;
case V_18 :
V_30 = V_33 ;
V_29 = 0xff ;
break;
case V_19 :
V_30 = V_34 ;
V_29 = 0xff ;
break;
case V_20 :
V_30 = V_35 ;
V_29 = 0xff ;
break;
case V_21 :
V_30 = V_36 ;
V_29 = 0xff ;
break;
default:
return;
}
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 1 ) ,
F_11 ( V_12 -> V_37 ) |
F_12 ( V_12 -> V_38 ) ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 2 ) ,
F_13 ( V_12 -> V_40 ) |
F_14 ( V_12 -> V_41 ) ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 ,
F_7 ( V_9 , 3 ) , V_28 -> V_42 ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 4 ) ,
V_26 |
F_15 ( V_29 ) |
F_16 ( V_30 ) |
F_17 ( 0 ) ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 5 ) ,
F_18 ( 0xFF ) |
F_19 ( 0xFF ) |
F_20 ( 0xFF ) ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 6 ) ,
F_21 ( 0 ) |
F_22 ( 0 ) |
F_23 ( 0 ) ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 7 ) , 0 ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 8 ) ,
F_24 ( 0 ) ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 9 ) ,
F_25 ( 0 ) ) ;
if ( V_24 )
goto V_39;
if ( ! strcmp ( V_4 -> V_8 -> V_43 , L_4 ) ) {
V_24 = F_8 ( V_4 -> V_25 , F_7 ( V_9 , 10 ) ,
F_26 ( 0 ) |
F_27 ( 0 ) ) ;
if ( V_24 )
goto V_39;
}
V_24 = F_28 ( V_4 -> V_25 , V_44 ,
V_45 ,
F_29 ( V_46 ) ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_25 ,
V_47 , V_48 ) ;
if ( V_24 )
goto V_39;
return;
V_39:
F_3 ( V_4 -> V_5 , L_3 ) ;
}
static void
F_30 ( struct V_1 * V_2 ,
const struct V_11 * V_49 )
{
}
static int
F_31 ( struct V_1 * V_2 ,
const struct V_11 * V_49 )
{
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
}
struct V_1 * F_34 ( struct V_50 * V_5 )
{
struct V_1 * V_51 ;
int V_24 ;
V_51 = F_35 ( sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 ) {
F_36 ( L_5 ) ;
return NULL ;
}
V_24 = F_37 ( V_5 , V_51 , 0 ,
& V_53 ,
V_54 ,
F_38 ( V_54 ) ,
V_55 , NULL ) ;
if ( V_24 ) {
F_39 ( V_51 ) ;
V_51 = NULL ;
}
F_40 ( V_51 , & V_56 ) ;
return V_51 ;
}
