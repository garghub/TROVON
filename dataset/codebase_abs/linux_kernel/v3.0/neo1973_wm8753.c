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
V_13 = F_4 ( V_9 ,
V_19 | V_20 |
V_21 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_4 ( V_10 ,
V_19 | V_20 |
V_21 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_9 , V_22 , V_11 ,
V_23 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_10 , V_24 ,
V_25 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_9 , V_26 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_10 , V_27 ,
F_7 ( 4 , 4 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_8 ( V_9 , V_28 , 0 ,
V_14 / 4 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
return F_8 ( V_9 , V_28 , 0 , 0 , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_29 = 0 ;
int V_13 = 0 ;
unsigned long V_14 ;
V_14 = F_2 () ;
if ( F_3 ( V_4 ) != 8000 )
return - V_30 ;
if ( F_11 ( V_4 ) != 1 )
return - V_30 ;
V_29 = V_31 ;
V_13 = F_4 ( V_9 , V_32 |
V_20 | V_33 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_9 , V_34 , 12288000 ,
V_23 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_9 , V_35 , V_29 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_8 ( V_9 , V_36 , 0 ,
V_14 / 4 , 12288000 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
return F_8 ( V_9 , V_36 , 0 , 0 , 0 ) ;
}
static int F_13 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
V_41 = V_40 -> V_42 . integer . V_42 [ 0 ] ;
F_14 ( V_43 , ! V_41 ) ;
return 0 ;
}
static int F_15 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
V_40 -> V_42 . integer . V_42 [ 0 ] = V_41 ;
return 0 ;
}
static int F_16 ( struct V_44 * V_45 ,
struct V_37 * V_46 , int V_47 )
{
F_14 ( V_48 , F_17 ( V_47 ) ) ;
return 0 ;
}
static int F_18 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_50 -> V_52 ;
int V_13 ;
V_13 = F_19 ( V_52 , V_53 ,
F_20 ( V_53 ) ) ;
if ( V_13 )
return V_13 ;
V_13 = F_21 ( V_52 , V_54 ,
F_20 ( V_54 ) ) ;
if ( V_13 )
return V_13 ;
V_13 = F_22 ( V_50 , V_55 ,
F_20 ( V_55 ) ) ;
if ( V_13 )
return V_13 ;
F_23 ( V_52 , L_1 ) ;
F_23 ( V_52 , L_2 ) ;
F_24 ( V_52 , L_1 ) ;
F_24 ( V_52 , L_2 ) ;
return 0 ;
}
static int F_18 ( struct V_56 * V_50 ) { return 0 ; }
static int F_25 ( struct V_5 * V_6 )
{
struct V_49 * V_50 = V_6 -> V_50 ;
struct V_51 * V_52 = & V_50 -> V_52 ;
int V_13 ;
if ( F_26 () ) {
F_27 ( V_52 , L_3 ) ;
F_27 ( V_52 , L_4 ) ;
}
F_27 ( V_52 , L_5 ) ;
F_27 ( V_52 , L_6 ) ;
F_27 ( V_52 , L_7 ) ;
F_27 ( V_52 , L_8 ) ;
V_13 = F_19 ( V_52 , V_57 ,
F_20 ( V_57 ) ) ;
if ( V_13 )
return V_13 ;
V_13 = F_22 ( V_50 , V_58 ,
F_20 ( V_58 ) ) ;
if ( V_13 )
return V_13 ;
V_13 = F_21 ( V_52 , V_59 ,
F_20 ( V_59 ) ) ;
if ( V_13 )
return V_13 ;
F_23 ( V_52 , L_9 ) ;
F_23 ( V_52 , L_10 ) ;
F_23 ( V_52 , L_11 ) ;
F_23 ( V_52 , L_12 ) ;
F_24 ( V_52 , L_9 ) ;
F_24 ( V_52 , L_10 ) ;
F_24 ( V_52 , L_11 ) ;
F_24 ( V_52 , L_12 ) ;
if ( F_28 () ) {
V_13 = F_18 ( V_50 ) ;
if ( V_13 )
return V_13 ;
}
F_29 ( V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_51 * V_52 )
{
int V_13 ;
V_13 = F_19 ( V_52 , V_60 ,
F_20 ( V_60 ) ) ;
if ( V_13 )
return V_13 ;
V_13 = F_21 ( V_52 , V_61 ,
F_20 ( V_61 ) ) ;
if ( V_13 )
return V_13 ;
F_24 ( V_52 , L_1 ) ;
F_24 ( V_52 , L_2 ) ;
F_24 ( V_52 , L_13 ) ;
F_29 ( V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_51 * V_52 ) { return 0 ; }
static int T_1 F_31 ( void )
{
int V_13 ;
if ( ! F_26 () && ! F_28 () )
return - V_62 ;
if ( F_28 () ) {
V_63 . V_64 = L_14 ;
V_63 . V_65 = 1 ;
V_13 = F_32 ( V_66 ,
F_20 ( V_66 ) ) ;
if ( V_13 )
return V_13 ;
}
V_67 = F_33 ( L_15 , - 1 ) ;
if ( ! V_67 ) {
V_13 = - V_68 ;
goto V_69;
}
F_34 ( V_67 , & V_63 ) ;
V_13 = F_35 ( V_67 ) ;
if ( V_13 )
goto V_70;
return 0 ;
V_70:
F_36 ( V_67 ) ;
V_69:
if ( F_28 () ) {
F_37 ( V_66 ,
F_20 ( V_66 ) ) ;
}
return V_13 ;
}
static void T_2 F_38 ( void )
{
F_39 ( V_67 ) ;
if ( F_28 () ) {
F_37 ( V_66 ,
F_20 ( V_66 ) ) ;
}
}
