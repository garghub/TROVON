static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 , V_5 ) ;
F_3 ( V_2 -> V_3 , V_6 ,
V_7 , V_7 ) ;
F_2 ( V_2 -> V_3 , V_8 , 0 ) ;
}
static void F_4 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
if ( V_10 -> V_11 -> V_12 == 1 )
F_3 ( V_2 -> V_3 , V_13 ,
V_14 ,
V_14 ) ;
F_3 ( V_2 -> V_3 , V_13 ,
V_15 , V_15 ) ;
F_3 ( V_2 -> V_3 , V_16 ,
V_17 , V_17 ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_18 , V_18 ) ;
}
static void F_5 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_3 ( V_2 -> V_3 , V_13 ,
V_15 , 0 ) ;
F_3 ( V_2 -> V_3 , V_16 ,
V_17 , 0 ) ;
F_3 ( V_2 -> V_3 , V_4 ,
V_18 , 0 ) ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = V_10 -> V_23 ;
struct V_1 * V_2 = F_7 ( V_22 -> V_20 ) ;
if ( V_10 -> V_24 != V_25 )
return - V_26 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_27 * V_28 ,
struct V_19 * V_20 )
{
int V_29 = 0 ;
int V_30 ;
unsigned long V_31 = F_9 ( V_28 ) ;
T_1 V_32 = 0 ;
unsigned int V_33 = 0 ;
T_1 V_34 ;
struct V_1 * V_2 = F_7 ( V_20 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
switch ( F_10 ( V_28 ) ) {
case 1 :
case 2 :
V_30 = 0 ;
break;
case 4 :
V_30 = V_37 ;
break;
default:
return - V_26 ;
}
switch ( F_11 ( V_28 ) ) {
case V_38 :
V_30 |= V_39 ;
break;
case V_40 :
V_30 |= V_41 ;
break;
case V_42 :
V_30 |= V_43 ;
break;
default:
return - V_26 ;
}
switch ( V_31 ) {
case 22050 :
case 44100 :
case 88200 :
case 176400 :
V_33 = 22579200 ;
break;
case 24000 :
case 32000 :
case 48000 :
case 96000 :
case 192000 :
V_33 = 24576000 ;
break;
default:
return - V_26 ;
}
V_29 = F_12 ( V_2 -> V_44 , V_33 ) ;
if ( V_29 < 0 ) {
F_13 ( & V_36 -> V_45 ,
L_1 , V_33 ) ;
return V_29 ;
}
F_3 ( V_2 -> V_3 , V_6 ,
V_46 , V_46 ) ;
switch ( V_31 ) {
case 22050 :
case 24000 :
V_32 = 8 ;
break;
case 32000 :
V_32 = 6 ;
break;
case 44100 :
case 48000 :
V_32 = 4 ;
break;
case 88200 :
case 96000 :
V_32 = 2 ;
break;
case 176400 :
case 192000 :
V_32 = 1 ;
break;
default:
return - V_26 ;
}
V_34 = 0 ;
V_34 |= V_47 ;
V_34 |= V_30 ;
V_34 |= V_48 ;
V_34 |= F_14 ( V_32 - 1 ) ;
F_2 ( V_2 -> V_3 , V_13 , V_34 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 , int V_49 ,
struct V_19 * V_50 )
{
int V_29 = 0 ;
struct V_1 * V_2 = F_7 ( V_50 ) ;
if ( V_10 -> V_24 != V_25 )
return - V_26 ;
switch ( V_49 ) {
case V_51 :
case V_52 :
case V_53 :
F_4 ( V_10 , V_2 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
F_5 ( V_10 , V_2 ) ;
break;
default:
V_29 = - V_26 ;
break;
}
return V_29 ;
}
static int F_16 ( struct V_19 * V_50 )
{
struct V_1 * V_2 = F_7 ( V_50 ) ;
F_17 ( V_50 , & V_2 -> V_57 , NULL ) ;
return 0 ;
}
static int F_18 ( struct V_58 * V_45 )
{
struct V_1 * V_2 = F_19 ( V_45 ) ;
F_20 ( V_2 -> V_44 ) ;
F_20 ( V_2 -> V_59 ) ;
return 0 ;
}
static int F_21 ( struct V_58 * V_45 )
{
struct V_1 * V_2 = F_19 ( V_45 ) ;
F_22 ( V_2 -> V_44 ) ;
F_22 ( V_2 -> V_59 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_60 * V_61 ;
int V_29 ;
void T_2 * V_62 ;
F_24 ( & V_36 -> V_45 , L_2 , V_63 ) ;
V_2 = F_25 ( & V_36 -> V_45 , sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 )
return - V_65 ;
V_2 -> V_36 = V_36 ;
memcpy ( & V_2 -> V_66 , & V_67 , sizeof( V_67 ) ) ;
V_2 -> V_66 . V_68 = F_26 ( & V_36 -> V_45 ) ;
V_61 = F_27 ( V_36 , V_69 , 0 ) ;
V_62 = F_28 ( & V_36 -> V_45 , V_61 ) ;
if ( F_29 ( V_62 ) )
return F_30 ( V_62 ) ;
V_2 -> V_3 = F_31 ( & V_36 -> V_45 , V_62 ,
& V_70 ) ;
V_2 -> V_59 = F_32 ( & V_36 -> V_45 , L_3 ) ;
if ( F_29 ( V_2 -> V_59 ) ) {
F_13 ( & V_36 -> V_45 , L_4 ) ;
return F_30 ( V_2 -> V_59 ) ;
}
V_2 -> V_44 = F_32 ( & V_36 -> V_45 , L_5 ) ;
if ( F_29 ( V_2 -> V_44 ) ) {
F_13 ( & V_36 -> V_45 , L_6 ) ;
V_29 = F_30 ( V_2 -> V_44 ) ;
goto V_71;
}
V_2 -> V_57 . V_72 = V_61 -> V_73 + V_74 ;
V_2 -> V_57 . V_75 = 4 ;
V_2 -> V_57 . V_76 = V_77 ;
F_33 ( V_36 , V_2 ) ;
V_29 = F_34 ( & V_36 -> V_45 ,
& V_78 , & V_67 , 1 ) ;
if ( V_29 )
goto V_71;
F_35 ( & V_36 -> V_45 ) ;
if ( ! F_36 ( & V_36 -> V_45 ) ) {
V_29 = F_21 ( & V_36 -> V_45 ) ;
if ( V_29 )
goto V_79;
}
V_29 = F_37 ( & V_36 -> V_45 , NULL , 0 ) ;
if ( V_29 )
goto V_80;
return 0 ;
V_80:
if ( ! F_38 ( & V_36 -> V_45 ) )
F_18 ( & V_36 -> V_45 ) ;
V_79:
F_39 ( & V_36 -> V_45 ) ;
F_40 ( & V_36 -> V_45 ) ;
V_71:
F_20 ( V_2 -> V_59 ) ;
return V_29 ;
}
static int F_41 ( struct V_35 * V_36 )
{
F_39 ( & V_36 -> V_45 ) ;
if ( ! F_38 ( & V_36 -> V_45 ) )
F_18 ( & V_36 -> V_45 ) ;
F_42 ( & V_36 -> V_45 ) ;
F_40 ( & V_36 -> V_45 ) ;
return 0 ;
}
