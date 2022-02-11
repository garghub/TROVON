static int F_1 ( unsigned V_1 , unsigned long * V_2 )
{
return F_2 ( V_3 , V_1 , V_2 ) ;
}
static int F_3 ( unsigned V_1 , unsigned long V_2 )
{
return F_4 ( V_3 , V_1 , V_2 ) ;
}
static int F_5 ( unsigned V_1 , unsigned long * V_2 )
{
unsigned V_4 = ( V_1 / V_5 ) * V_6 ;
unsigned V_7 = ( V_1 % V_5 ) * V_6 ;
unsigned long V_8 = F_6 ( V_3 + V_9 ) ;
unsigned long V_10 ;
if ( ( V_8 & F_7 ( V_1 ) ) == 0 )
return F_2 ( V_3 , V_1 , V_2 ) ;
V_10 = F_6 ( V_11 + V_12 + V_4 ) ;
* V_2 = ( V_10 >> V_7 ) & V_13 ;
* V_2 |= V_14 ;
return 0 ;
}
static int F_8 ( unsigned V_1 , unsigned long V_2 )
{
unsigned V_4 = ( V_1 / V_5 ) * V_6 ;
unsigned V_7 = ( V_1 % V_5 ) * V_6 ;
unsigned long V_8 = F_6 ( V_3 + V_9 ) ;
unsigned long V_10 ;
if ( ( V_2 & V_14 ) == 0 ) {
F_9 ( V_8 & ~ F_7 ( V_1 ) , V_3 + V_9 ) ;
return F_4 ( V_3 , V_1 , V_2 ) ;
}
F_9 ( V_8 | F_7 ( V_1 ) , V_3 + V_9 ) ;
V_10 = F_6 ( V_11 + V_12 + V_4 ) ;
V_10 &= ~ ( V_13 << V_7 ) ;
V_10 |= ( V_2 & V_13 ) << V_7 ;
F_9 ( V_10 , V_11 + V_12 + V_4 ) ;
return 0 ;
}
static int F_10 ( unsigned V_1 , unsigned long * V_2 )
{
unsigned long V_15 = F_6 ( V_16 ) ;
unsigned long V_17 ;
switch ( V_1 ) {
case 24 :
V_17 = V_18 ;
break;
case 40 :
V_17 = V_19 ;
break;
case 46 :
V_17 = V_20 ;
break;
case 58 :
V_17 = V_21 ;
break;
case 62 :
V_17 = V_22 ;
break;
default:
return - V_23 ;
}
* V_2 = ( ( V_15 & V_17 ) != 0 ) ;
return 0 ;
}
static int F_11 ( unsigned V_1 , unsigned long V_2 )
{
unsigned long V_15 = F_6 ( V_16 ) ;
unsigned long V_17 ;
switch ( V_1 ) {
case 24 :
V_17 = V_18 ;
break;
case 40 :
V_17 = V_19 ;
break;
case 46 :
V_17 = V_20 ;
break;
case 58 :
V_17 = V_21 ;
break;
case 62 :
V_17 = V_22 ;
break;
default:
return - V_23 ;
}
V_15 &= ~ V_17 ;
if ( V_2 )
V_15 |= V_17 ;
F_9 ( V_15 , V_16 ) ;
return 0 ;
}
static int F_12 ( unsigned V_1 , unsigned long * V_2 )
{
unsigned int V_24 ;
F_13 ( V_25 , V_26 , & V_24 ) ;
* V_2 = ( ( V_24 & V_27 ) != 0 ) ;
return 0 ;
}
static int F_14 ( unsigned V_1 , unsigned long V_2 )
{
F_15 ( V_25 , V_26 ,
V_27 ,
( V_2 ) ? V_27 : 0 ) ;
return 0 ;
}
static int F_16 ( unsigned V_1 , unsigned long * V_2 )
{
unsigned long V_8 = F_6 ( V_3 + V_9 ) ;
* V_2 = ( ( V_8 & V_28 ) != 0 ) ;
return 0 ;
}
static int F_17 ( unsigned V_1 , unsigned long V_2 )
{
unsigned long V_8 = F_6 ( V_3 + V_9 ) ;
V_8 &= ~ V_28 ;
if ( V_2 )
V_8 |= V_28 ;
F_9 ( V_8 , V_3 + V_9 ) ;
return 0 ;
}
static int F_18 ( unsigned V_1 , unsigned long * V_2 )
{
unsigned int V_15 = F_6 ( V_16 ) ;
unsigned int V_29 ;
unsigned int V_24 ;
unsigned int V_30 ;
F_13 ( V_25 , V_31 , & V_29 ) ;
F_13 ( V_25 , V_26 , & V_24 ) ;
F_13 ( V_25 , V_32 , & V_30 ) ;
* V_2 = 0 ;
if ( V_15 & V_33 )
* V_2 |= F_7 ( 3 ) ;
if ( V_29 & V_34 )
* V_2 |= F_7 ( 2 ) ;
if ( V_24 & V_35 )
* V_2 |= F_7 ( 1 ) ;
if ( V_30 & V_36 )
* V_2 |= F_7 ( 0 ) ;
if ( ( * V_2 & F_7 ( 3 ) ) == 0 )
* V_2 &= ~ ( F_7 ( 2 ) | F_7 ( 0 ) ) ;
if ( ( * V_2 & F_7 ( 1 ) ) == 0 )
* V_2 &= ~ F_7 ( 0 ) ;
return 0 ;
}
static int F_19 ( unsigned V_1 , unsigned long V_2 )
{
unsigned int V_15 = F_6 ( V_16 ) ;
V_15 &= ~ V_33 ;
if ( V_2 & F_7 ( 3 ) )
V_15 |= V_33 ;
F_9 ( V_15 , V_16 ) ;
F_15 ( V_25 , V_31 ,
V_34 ,
( V_2 & F_7 ( 2 ) ) ? V_34 : 0 ) ;
F_15 ( V_25 , V_26 ,
V_35 ,
( V_2 & F_7 ( 1 ) ) ? V_35 : 0 ) ;
F_15 ( V_25 , V_32 ,
V_36 ,
( V_2 & F_7 ( 0 ) ) ? V_36 : 0 ) ;
return 0 ;
}
static int F_20 ( unsigned V_1 )
{
unsigned long V_2 ;
F_18 ( V_1 , & V_2 ) ;
switch ( V_2 ) {
case 0x02 :
case 0x0e :
if ( V_1 >= 56 )
return 0 ;
return - V_37 ;
case 0x08 :
case 0x0b :
if ( V_1 <= 55 )
return 0 ;
return - V_37 ;
case 0x0a :
return 0 ;
}
return - V_37 ;
}
static int F_21 ( unsigned V_1 , bool V_38 )
{
if ( V_1 < 52 || V_1 > 57 )
return - V_37 ;
return 0 ;
}
static int F_22 ( unsigned V_1 , unsigned long * V_2 )
{
unsigned int V_39 ;
unsigned int V_30 ;
F_13 ( V_25 , V_40 , & V_39 ) ;
F_13 ( V_25 , V_32 , & V_30 ) ;
* V_2 = 0 ;
if ( V_39 & V_41 )
* V_2 = 1 ;
else if ( V_30 & V_42 )
* V_2 = 2 ;
else if ( V_30 & V_43 )
* V_2 = 3 ;
return 0 ;
}
static int F_23 ( unsigned V_1 , unsigned long V_2 )
{
unsigned int V_39 = 0 ;
unsigned int V_30 = 0 ;
switch ( V_2 ) {
case 1 :
V_39 = V_41 ;
break;
case 2 :
V_30 = V_42 ;
break;
case 3 :
V_30 = V_43 ;
break;
}
F_15 ( V_25 , V_40 ,
V_41 ,
V_39 ) ;
F_15 ( V_25 , V_32 ,
V_42 | V_43 ,
V_30 ) ;
return 0 ;
}
static int F_24 ( struct V_44 * V_45 )
{
struct V_46 * V_47 , * V_48 ;
struct V_46 V_49 ;
const struct V_50 * V_51 =
F_25 ( V_52 , & V_45 -> V_53 ) ;
V_45 -> V_53 . V_54 = ( void * ) V_51 -> V_55 ;
V_56 = F_26 ( & V_45 -> V_53 , NULL ) ;
if ( F_27 ( V_56 ) ) {
F_28 ( & V_45 -> V_53 , L_1 ) ;
return F_29 ( V_56 ) ;
}
F_30 ( V_56 ) ;
V_48 = F_31 ( V_45 , V_57 , 0 ) ;
V_3 = F_32 ( & V_45 -> V_53 , V_48 ) ;
if ( F_27 ( V_3 ) )
return F_29 ( V_3 ) ;
memcpy ( & V_49 , V_48 , sizeof( struct V_46 ) ) ;
V_49 . V_58 = 0 ;
V_47 = F_31 ( V_45 , V_57 , 1 ) ;
if ( ! V_47 ) {
F_33 ( & V_45 -> V_53 , L_2 ) ;
F_34 ( & V_49 ,
( V_48 -> V_58 & V_59 ) + V_60 , 0x4 ) ;
V_47 = & V_49 ;
}
V_16 = F_32 ( & V_45 -> V_53 , V_47 ) ;
if ( F_27 ( V_16 ) )
return F_29 ( V_16 ) ;
V_47 = F_31 ( V_45 , V_57 , 2 ) ;
if ( ! V_47 ) {
F_33 ( & V_45 -> V_53 , L_3 ) ;
F_34 ( & V_49 ,
( V_48 -> V_58 & V_59 ) + V_61 , 0x8 ) ;
V_47 = & V_49 ;
}
V_11 = F_32 ( & V_45 -> V_53 , V_47 ) ;
if ( F_27 ( V_11 ) )
return F_29 ( V_11 ) ;
V_25 = F_35 ( L_4 ) ;
if ( F_27 ( V_25 ) ) {
void T_1 * V_62 ;
F_33 ( & V_45 -> V_53 , L_5 ) ;
F_34 ( & V_49 ,
( V_48 -> V_58 & V_59 ) + V_63 , 0x14 ) ;
V_62 = F_32 ( & V_45 -> V_53 , & V_49 ) ;
if ( F_27 ( V_62 ) )
return F_29 ( V_62 ) ;
V_25 = F_36 ( & V_45 -> V_53 ,
V_62 , & V_64 ) ;
if ( F_27 ( V_25 ) )
return F_29 ( V_25 ) ;
}
if ( V_49 . V_58 )
F_33 ( & V_45 -> V_53 , V_65 L_6 ) ;
return F_37 ( V_45 ) ;
}
static int F_38 ( struct V_44 * V_45 )
{
int V_66 ;
V_66 = F_39 ( V_45 ) ;
if ( ! F_27 ( V_56 ) )
F_40 ( V_56 ) ;
return V_66 ;
}
