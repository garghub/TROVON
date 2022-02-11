static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned long * V_4 )
{
unsigned V_5 = ( V_3 / V_6 ) * V_7 ;
unsigned V_8 = ( V_3 % V_6 ) * V_7 ;
unsigned long V_9 = F_2 ( V_2 -> V_10 + V_11 ) ;
unsigned long V_12 ;
if ( ( V_9 & F_3 ( V_3 ) ) == 0 )
return F_4 ( V_2 , V_3 , V_4 ) ;
V_12 = F_2 ( V_13 + V_14 + V_5 ) ;
* V_4 = ( V_12 >> V_8 ) & V_15 ;
* V_4 |= V_16 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned long V_4 )
{
unsigned V_5 = ( V_3 / V_6 ) * V_7 ;
unsigned V_8 = ( V_3 % V_6 ) * V_7 ;
unsigned long V_9 = F_2 ( V_2 -> V_10 + V_11 ) ;
unsigned long V_12 ;
if ( ( V_4 & V_16 ) == 0 ) {
F_6 ( V_9 & ~ F_3 ( V_3 ) , V_2 -> V_10 + V_11 ) ;
return F_7 ( V_2 , V_3 , V_4 ) ;
}
F_6 ( V_9 | F_3 ( V_3 ) , V_2 -> V_10 + V_11 ) ;
V_12 = F_2 ( V_13 + V_14 + V_5 ) ;
V_12 &= ~ ( V_15 << V_8 ) ;
V_12 |= ( V_4 & V_15 ) << V_8 ;
F_6 ( V_12 , V_13 + V_14 + V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long * V_4 )
{
unsigned long V_17 = F_2 ( V_18 ) ;
unsigned long V_19 ;
switch ( V_3 ) {
case 24 :
V_19 = V_20 ;
break;
case 40 :
V_19 = V_21 ;
break;
case 46 :
V_19 = V_22 ;
break;
case 58 :
V_19 = V_23 ;
break;
case 62 :
V_19 = V_24 ;
break;
default:
return - V_25 ;
}
* V_4 = ( ( V_17 & V_19 ) != 0 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long V_4 )
{
unsigned long V_17 = F_2 ( V_18 ) ;
unsigned long V_19 ;
switch ( V_3 ) {
case 24 :
V_19 = V_20 ;
break;
case 40 :
V_19 = V_21 ;
break;
case 46 :
V_19 = V_22 ;
break;
case 58 :
V_19 = V_23 ;
break;
case 62 :
V_19 = V_24 ;
break;
default:
return - V_25 ;
}
V_17 &= ~ V_19 ;
if ( V_4 )
V_17 |= V_19 ;
F_6 ( V_17 , V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long * V_4 )
{
unsigned int V_26 ;
F_11 ( V_27 , V_28 , & V_26 ) ;
* V_4 = ( ( V_26 & V_29 ) != 0 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long V_4 )
{
F_13 ( V_27 , V_28 ,
V_29 ,
( V_4 ) ? V_29 : 0 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long * V_4 )
{
unsigned long V_9 = F_2 ( V_2 -> V_10 + V_11 ) ;
* V_4 = ( ( V_9 & V_30 ) != 0 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long V_4 )
{
unsigned long V_9 = F_2 ( V_2 -> V_10 + V_11 ) ;
V_9 &= ~ V_30 ;
if ( V_4 )
V_9 |= V_30 ;
F_6 ( V_9 , V_2 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long * V_4 )
{
unsigned int V_17 = F_2 ( V_18 ) ;
unsigned int V_31 ;
unsigned int V_26 ;
unsigned int V_32 ;
F_11 ( V_27 , V_33 , & V_31 ) ;
F_11 ( V_27 , V_28 , & V_26 ) ;
F_11 ( V_27 , V_34 , & V_32 ) ;
* V_4 = 0 ;
if ( V_17 & V_35 )
* V_4 |= F_3 ( 3 ) ;
if ( V_31 & V_36 )
* V_4 |= F_3 ( 2 ) ;
if ( V_26 & V_37 )
* V_4 |= F_3 ( 1 ) ;
if ( V_32 & V_38 )
* V_4 |= F_3 ( 0 ) ;
if ( ( * V_4 & F_3 ( 3 ) ) == 0 )
* V_4 &= ~ ( F_3 ( 2 ) | F_3 ( 0 ) ) ;
if ( ( * V_4 & F_3 ( 1 ) ) == 0 )
* V_4 &= ~ F_3 ( 0 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long V_4 )
{
unsigned int V_17 = F_2 ( V_18 ) ;
V_17 &= ~ V_35 ;
if ( V_4 & F_3 ( 3 ) )
V_17 |= V_35 ;
F_6 ( V_17 , V_18 ) ;
F_13 ( V_27 , V_33 ,
V_36 ,
( V_4 & F_3 ( 2 ) ) ? V_36 : 0 ) ;
F_13 ( V_27 , V_28 ,
V_37 ,
( V_4 & F_3 ( 1 ) ) ? V_37 : 0 ) ;
F_13 ( V_27 , V_34 ,
V_38 ,
( V_4 & F_3 ( 0 ) ) ? V_38 : 0 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_3 )
{
unsigned long V_4 ;
F_16 ( V_2 , V_3 , & V_4 ) ;
switch ( V_4 ) {
case 0x02 :
case 0x0e :
if ( V_3 >= 56 )
return 0 ;
return - V_39 ;
case 0x08 :
case 0x0b :
if ( V_3 <= 55 )
return 0 ;
return - V_39 ;
case 0x0a :
return 0 ;
}
return - V_39 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_3 , bool V_40 )
{
if ( V_3 < 52 || V_3 > 57 )
return - V_39 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long * V_4 )
{
unsigned int V_41 ;
unsigned int V_32 ;
F_11 ( V_27 , V_42 , & V_41 ) ;
F_11 ( V_27 , V_34 , & V_32 ) ;
* V_4 = 0 ;
if ( V_41 & V_43 )
* V_4 = 1 ;
else if ( V_32 & V_44 )
* V_4 = 2 ;
else if ( V_32 & V_45 )
* V_4 = 3 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long V_4 )
{
unsigned int V_41 = 0 ;
unsigned int V_32 = 0 ;
switch ( V_4 ) {
case 1 :
V_41 = V_43 ;
break;
case 2 :
V_32 = V_44 ;
break;
case 3 :
V_32 = V_45 ;
break;
}
F_13 ( V_27 , V_42 ,
V_43 ,
V_41 ) ;
F_13 ( V_27 , V_34 ,
V_44 | V_45 ,
V_32 ) ;
return 0 ;
}
static int F_22 ( struct V_46 * V_47 )
{
struct V_48 * V_49 , * V_50 ;
struct V_48 V_51 ;
const struct V_52 * V_53 =
F_23 ( V_54 , & V_47 -> V_55 ) ;
struct V_1 * V_56 ;
void T_1 * V_10 ;
int V_57 ;
V_47 -> V_55 . V_58 = ( void * ) V_53 -> V_2 ;
V_59 = F_24 ( & V_47 -> V_55 , NULL ) ;
if ( F_25 ( V_59 ) ) {
F_26 ( & V_47 -> V_55 , L_1 ) ;
return F_27 ( V_59 ) ;
}
F_28 ( V_59 ) ;
V_50 = F_29 ( V_47 , V_60 , 0 ) ;
V_10 = F_30 ( & V_47 -> V_55 , V_50 ) ;
if ( F_25 ( V_10 ) )
return F_27 ( V_10 ) ;
V_56 = F_31 ( & V_47 -> V_55 , V_61 . V_62 ,
sizeof( * V_56 ) , V_63 ) ;
if ( ! V_56 )
return - V_64 ;
V_61 . V_65 = V_56 ;
for ( V_57 = 0 ; V_57 < F_32 ( V_66 ) ; V_57 ++ )
V_56 [ V_57 ] . V_10 = V_10 ;
memcpy ( & V_51 , V_50 , sizeof( struct V_48 ) ) ;
V_51 . V_67 = 0 ;
V_49 = F_29 ( V_47 , V_60 , 1 ) ;
if ( ! V_49 ) {
F_33 ( & V_47 -> V_55 , L_2 ) ;
F_34 ( & V_51 ,
( V_50 -> V_67 & V_68 ) + V_69 , 0x4 ) ;
V_49 = & V_51 ;
}
V_18 = F_30 ( & V_47 -> V_55 , V_49 ) ;
if ( F_25 ( V_18 ) )
return F_27 ( V_18 ) ;
V_49 = F_29 ( V_47 , V_60 , 2 ) ;
if ( ! V_49 ) {
F_33 ( & V_47 -> V_55 , L_3 ) ;
F_34 ( & V_51 ,
( V_50 -> V_67 & V_68 ) + V_70 , 0x8 ) ;
V_49 = & V_51 ;
}
V_13 = F_30 ( & V_47 -> V_55 , V_49 ) ;
if ( F_25 ( V_13 ) )
return F_27 ( V_13 ) ;
V_27 = F_35 ( L_4 ) ;
if ( F_25 ( V_27 ) ) {
void T_1 * V_71 ;
F_33 ( & V_47 -> V_55 , L_5 ) ;
F_34 ( & V_51 ,
( V_50 -> V_67 & V_68 ) + V_72 , 0x14 ) ;
V_71 = F_30 ( & V_47 -> V_55 , & V_51 ) ;
if ( F_25 ( V_71 ) )
return F_27 ( V_71 ) ;
V_27 = F_36 ( & V_47 -> V_55 ,
V_71 , & V_73 ) ;
if ( F_25 ( V_27 ) )
return F_27 ( V_27 ) ;
}
if ( V_51 . V_67 )
F_33 ( & V_47 -> V_55 , V_74 L_6 ) ;
return F_37 ( V_47 ) ;
}
