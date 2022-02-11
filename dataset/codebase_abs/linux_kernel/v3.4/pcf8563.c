unsigned char
F_1 ( int V_1 )
{
unsigned char V_2 = F_2 ( V_1 ) ;
switch ( V_1 ) {
case V_3 :
case V_4 :
V_2 &= 0x7F ;
break;
case V_5 :
case V_6 :
V_2 &= 0x3F ;
break;
case V_7 :
V_2 &= 0x07 ;
break;
case V_8 :
V_2 &= 0x1F ;
break;
case V_9 :
V_2 &= 0xA8 ;
break;
case V_10 :
V_2 &= 0x1F ;
break;
case V_11 :
case V_12 :
V_2 &= 0x83 ;
break;
}
return V_2 ;
}
void
F_3 ( int V_1 , unsigned char V_13 )
{
F_4 ( V_1 , V_13 ) ;
}
void
F_5 ( struct V_14 * V_15 )
{
V_15 -> V_16 = F_2 ( V_3 ) ;
V_15 -> V_17 = F_2 ( V_4 ) ;
V_15 -> V_18 = F_2 ( V_5 ) ;
V_15 -> V_19 = F_2 ( V_6 ) ;
V_15 -> V_20 = F_2 ( V_7 ) ;
V_15 -> V_21 = F_2 ( V_8 ) ;
V_15 -> V_22 = F_2 ( V_23 ) ;
if ( V_15 -> V_16 & 0x80 ) {
F_6 ( V_24 L_1
L_2 , V_25 ) ;
}
V_15 -> V_22 = F_7 ( V_15 -> V_22 ) +
( ( V_15 -> V_21 & 0x80 ) ? 100 : 0 ) ;
V_15 -> V_16 &= 0x7F ;
V_15 -> V_17 &= 0x7F ;
V_15 -> V_18 &= 0x3F ;
V_15 -> V_19 &= 0x3F ;
V_15 -> V_20 &= 0x07 ;
V_15 -> V_21 &= 0x1F ;
V_15 -> V_16 = F_7 ( V_15 -> V_16 ) ;
V_15 -> V_17 = F_7 ( V_15 -> V_17 ) ;
V_15 -> V_18 = F_7 ( V_15 -> V_18 ) ;
V_15 -> V_19 = F_7 ( V_15 -> V_19 ) ;
V_15 -> V_21 = F_7 ( V_15 -> V_21 ) ;
V_15 -> V_21 -- ;
}
int T_1
F_8 ( void )
{
static int V_2 ;
static int V_26 = 1 ;
if ( ! V_26 )
return V_2 ;
V_26 = 0 ;
V_2 = F_9 () ;
if ( V_2 < 0 ) {
F_6 ( V_27 L_3 ) ;
return V_2 ;
}
if ( F_4 ( V_9 , 0x00 ) < 0 )
goto V_28;
if ( F_4 ( V_10 , 0x00 ) < 0 )
goto V_28;
if ( F_4 ( V_11 , 0x00 ) < 0 )
goto V_28;
if ( F_4 ( V_12 , 0x03 ) < 0 )
goto V_28;
if ( F_4 ( V_29 , 0x80 ) < 0 )
goto V_28;
if ( F_4 ( V_30 , 0x80 ) < 0 )
goto V_28;
if ( F_4 ( V_31 , 0x80 ) < 0 )
goto V_28;
if ( F_4 ( V_32 , 0x80 ) < 0 )
goto V_28;
if ( F_2 ( V_3 ) & 0x80 ) {
V_33 = 1 ;
F_6 ( V_34 L_4
L_5 ,
V_25 ) ;
}
return V_2 ;
V_28:
F_6 ( V_35 L_6 , V_25 ) ;
V_2 = - 1 ;
return V_2 ;
}
void T_2
F_10 ( void )
{
F_11 ( V_36 , V_37 ) ;
}
static int F_12 ( struct V_38 * V_39 , unsigned int V_40 , unsigned long V_41 )
{
if ( F_13 ( V_40 ) != V_42 )
return - V_43 ;
if ( F_14 ( V_40 ) > V_44 )
return - V_43 ;
switch ( V_40 ) {
case V_45 :
{
struct V_14 V_15 ;
F_15 ( & V_46 ) ;
memset ( & V_15 , 0 , sizeof V_15 ) ;
F_5 ( & V_15 ) ;
if ( F_16 ( (struct V_14 * ) V_41 , & V_15 ,
sizeof V_15 ) ) {
F_17 ( & V_46 ) ;
return - V_47 ;
}
F_17 ( & V_46 ) ;
return 0 ;
}
case V_48 :
{
int V_49 ;
int V_50 ;
int V_51 ;
struct V_14 V_15 ;
memset ( & V_15 , 0 , sizeof V_15 ) ;
if ( ! F_18 ( V_52 ) )
return - V_53 ;
if ( F_19 ( & V_15 , (struct V_14 * ) V_41 , sizeof V_15 ) )
return - V_47 ;
V_15 . V_22 += 1900 ;
V_15 . V_21 += 1 ;
V_50 = V_15 . V_22 ;
V_49 = ( V_15 . V_21 == 2 ) &&
( ( V_50 % 4 == 0 && V_50 % 100 != 0 ) || V_50 % 400 == 0 ) ;
if ( ( V_15 . V_22 < 1970 ) ||
( V_15 . V_21 > 12 ) ||
( V_15 . V_19 == 0 ) ||
( V_15 . V_19 > V_54 [ V_15 . V_21 ] + V_49 ) ||
( V_15 . V_20 >= 7 ) ||
( V_15 . V_18 >= 24 ) ||
( V_15 . V_17 >= 60 ) ||
( V_15 . V_16 >= 60 ) )
return - V_55 ;
V_51 = ( V_15 . V_22 >= 2000 ) ? 0x80 : 0 ;
V_15 . V_22 = V_15 . V_22 % 100 ;
V_15 . V_22 = F_20 ( V_15 . V_22 ) ;
V_15 . V_21 = F_20 ( V_15 . V_21 ) ;
V_15 . V_19 = F_20 ( V_15 . V_19 ) ;
V_15 . V_18 = F_20 ( V_15 . V_18 ) ;
V_15 . V_17 = F_20 ( V_15 . V_17 ) ;
V_15 . V_16 = F_20 ( V_15 . V_16 ) ;
V_15 . V_21 |= V_51 ;
F_15 ( & V_46 ) ;
F_4 ( V_23 , V_15 . V_22 ) ;
F_4 ( V_8 , V_15 . V_21 ) ;
F_4 ( V_7 , V_15 . V_20 ) ;
F_4 ( V_6 , V_15 . V_19 ) ;
F_4 ( V_5 , V_15 . V_18 ) ;
F_4 ( V_4 , V_15 . V_17 ) ;
F_4 ( V_3 , V_15 . V_16 ) ;
F_17 ( & V_46 ) ;
return 0 ;
}
case V_56 :
if ( V_33 ) {
F_6 ( V_24 L_7
L_8
L_9 , V_25 ) ;
}
if ( F_16 ( ( int * ) V_41 , & V_33 , sizeof( int ) ) )
return - V_47 ;
return 0 ;
case V_57 :
{
int V_58 = F_2 ( V_3 ) ;
F_4 ( V_3 , ( V_58 & 0x7F ) ) ;
V_33 = 0 ;
return 0 ;
}
default:
return - V_43 ;
}
return 0 ;
}
static long F_21 ( struct V_38 * V_39 , unsigned int V_40 , unsigned long V_41 )
{
int V_58 ;
F_15 ( & V_59 ) ;
V_58 = F_12 ( V_39 , V_40 , V_41 ) ;
F_17 ( & V_59 ) ;
return V_58 ;
}
static int T_1 F_22 ( void )
{
if ( F_8 () < 0 ) {
F_6 ( V_35 L_10
L_11 , V_25 , V_60 ) ;
return - 1 ;
}
if ( F_23 ( V_36 , V_37 , & V_61 ) < 0 ) {
F_6 ( V_35 L_12 ,
V_25 , V_36 ) ;
return - 1 ;
}
F_6 ( V_35 L_13 , V_25 ,
V_60 ) ;
if ( V_33 ) {
F_6 ( V_34 L_1
L_2 , V_25 ) ;
}
return 0 ;
}
