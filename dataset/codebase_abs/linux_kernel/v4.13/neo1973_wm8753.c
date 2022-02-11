static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 = 0 , V_12 = 0 ;
int V_13 = 0 ;
unsigned long V_14 ;
V_14 = F_2 () ;
switch ( F_3 ( V_4 ) ) {
case 8000 :
case 16000 :
V_11 = 12288000 ;
break;
case 48000 :
V_12 = V_15 ;
V_11 = 12288000 ;
break;
case 96000 :
V_12 = V_16 ;
V_11 = 12288000 ;
break;
case 11025 :
V_12 = V_17 ;
V_11 = 11289600 ;
break;
case 22050 :
V_12 = V_18 ;
V_11 = 11289600 ;
break;
case 44100 :
V_12 = V_15 ;
V_11 = 11289600 ;
break;
case 88200 :
V_12 = V_16 ;
V_11 = 11289600 ;
break;
}
V_13 = F_4 ( V_9 , V_19 , V_11 ,
V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_10 , V_21 ,
V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_9 , V_23 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_10 , V_24 ,
F_6 ( 4 , 4 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_9 , V_25 , 0 ,
V_14 / 4 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
return F_7 ( V_9 , V_25 , 0 , 0 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_26 = 0 ;
int V_13 = 0 ;
unsigned long V_14 ;
V_14 = F_2 () ;
if ( F_3 ( V_4 ) != 8000 )
return - V_27 ;
if ( F_10 ( V_4 ) != 1 )
return - V_27 ;
V_26 = V_28 ;
V_13 = F_4 ( V_9 , V_29 , 12288000 ,
V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_9 , V_30 , V_26 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_9 , V_31 , 0 ,
V_14 / 4 , 12288000 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
return F_7 ( V_9 , V_31 , 0 , 0 , 0 ) ;
}
static int F_12 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_36 = V_35 -> V_37 . integer . V_37 [ 0 ] ;
F_13 ( F_14 ( 2 ) , ! V_36 ) ;
return 0 ;
}
static int F_15 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_37 . integer . V_37 [ 0 ] = V_36 ;
return 0 ;
}
static int F_16 ( struct V_38 * V_39 ,
struct V_32 * V_40 , int V_41 )
{
F_13 ( F_14 ( 1 ) , F_17 ( V_41 ) ) ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_42 * V_43 = V_6 -> V_43 ;
F_19 ( & V_43 -> V_44 , L_1 ) ;
F_19 ( & V_43 -> V_44 , L_2 ) ;
F_19 ( & V_43 -> V_44 , L_3 ) ;
F_19 ( & V_43 -> V_44 , L_4 ) ;
F_19 ( & V_43 -> V_44 , L_5 ) ;
F_19 ( & V_43 -> V_44 , L_6 ) ;
F_20 ( & V_43 -> V_44 , L_1 ) ;
F_20 ( & V_43 -> V_44 , L_2 ) ;
F_20 ( & V_43 -> V_44 , L_3 ) ;
F_20 ( & V_43 -> V_44 , L_4 ) ;
F_20 ( & V_43 -> V_44 , L_5 ) ;
F_20 ( & V_43 -> V_44 , L_6 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
int V_13 ;
if ( ! F_22 () )
return - V_45 ;
if ( F_22 () ) {
V_46 . V_47 = L_7 ;
V_46 . V_48 = 1 ;
V_13 = F_23 ( V_49 ,
F_24 ( V_49 ) ) ;
if ( V_13 )
return V_13 ;
}
V_50 = F_25 ( L_8 , - 1 ) ;
if ( ! V_50 ) {
V_13 = - V_51 ;
goto V_52;
}
F_26 ( V_50 , & V_46 ) ;
V_13 = F_27 ( V_50 ) ;
if ( V_13 )
goto V_53;
return 0 ;
V_53:
F_28 ( V_50 ) ;
V_52:
if ( F_22 () ) {
F_29 ( V_49 ,
F_24 ( V_49 ) ) ;
}
return V_13 ;
}
static void T_2 F_30 ( void )
{
F_31 ( V_50 ) ;
if ( F_22 () ) {
F_29 ( V_49 ,
F_24 ( V_49 ) ) ;
}
}
