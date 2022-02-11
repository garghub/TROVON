void F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
return;
if ( V_3 != - V_4 )
F_3 ( V_5 L_1
L_2 , - V_3 ) ;
else
F_3 ( V_5 L_3 ) ;
}
int F_4 ( unsigned long V_6 )
{
unsigned short V_7 ;
int V_8 ;
V_8 = F_5 ( & V_7 , ( void V_9 * ) V_6 , sizeof( V_7 ) ) ;
if ( V_8 ) {
V_8 = F_6 ( V_10 , V_6 , & V_7 , sizeof( V_7 ) , 0 ) ;
if ( V_8 != sizeof( V_7 ) ) {
F_3 ( V_11 L_4
L_5 , V_6 ) ;
return 1 ;
}
}
return ( V_7 == 0x80cd ) || ( V_7 == 0x340f ) ;
}
int F_7 ( struct V_1 * V_12 , int V_13 , unsigned long V_14 )
{
V_13 >>= 2 ;
switch ( V_13 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
break;
case V_24 :
if ( V_14 && ( V_14 & 3 ) != 3 )
return - V_25 ;
break;
case V_26 :
if ( V_14 && ( V_14 & 3 ) != 3 )
return - V_25 ;
break;
case V_27 :
case V_28 :
if ( V_14 && ( V_14 & 3 ) != 3 )
return - V_25 ;
V_14 &= 0xffff ;
break;
case V_29 :
case V_30 :
if ( ( V_14 & 3 ) != 3 )
return - V_25 ;
V_14 &= 0xffff ;
break;
case V_31 :
V_14 &= V_32 ;
V_12 -> V_33 . V_34 . V_34 . V_35 [ V_36 ] |= V_14 ;
return 0 ;
case V_37 :
V_12 -> V_33 . V_34 . V_34 . V_38 = V_14 ;
return 0 ;
default :
F_8 ( L_6 , V_13 ) ;
}
V_12 -> V_33 . V_34 . V_34 . V_35 [ V_39 [ V_13 ] ] = V_14 ;
return 0 ;
}
int F_9 ( struct V_1 * V_12 , long V_6 , long V_40 )
{
if ( ( V_6 & 3 ) || V_6 < 0 )
return - V_25 ;
if ( V_6 < V_41 )
return F_7 ( V_12 , V_6 , V_40 ) ;
else if ( ( V_6 >= F_10 ( struct V_42 , V_43 [ 0 ] ) ) &&
( V_6 <= F_10 ( struct V_42 , V_43 [ 7 ] ) ) ) {
V_6 -= F_10 ( struct V_42 , V_43 [ 0 ] ) ;
V_6 = V_6 >> 2 ;
if ( ( V_6 == 4 ) || ( V_6 == 5 ) )
return - V_25 ;
V_12 -> V_33 . V_44 . V_45 [ V_6 ] = V_40 ;
return 0 ;
}
return - V_25 ;
}
unsigned long F_11 ( struct V_1 * V_12 , int V_13 )
{
unsigned long V_46 = ~ 0UL ;
V_13 >>= 2 ;
switch ( V_13 ) {
case V_37 :
return V_12 -> V_33 . V_34 . V_34 . V_38 ;
case V_24 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_46 = 0xffff ;
break;
case V_22 :
case V_23 :
case V_21 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_31 :
break;
default:
F_8 ( L_7 , V_13 ) ;
}
return V_46 & V_12 -> V_33 . V_34 . V_34 . V_35 [ V_39 [ V_13 ] ] ;
}
int F_12 ( struct V_1 * V_12 , long V_6 , long V_40 )
{
unsigned long V_47 ;
if ( ( V_6 & 3 ) || V_6 < 0 )
return - V_25 ;
V_47 = 0 ;
if ( V_6 < V_41 ) {
V_47 = F_11 ( V_12 , V_6 ) ;
}
else if ( ( V_6 >= F_10 ( struct V_42 , V_43 [ 0 ] ) ) &&
( V_6 <= F_10 ( struct V_42 , V_43 [ 7 ] ) ) ) {
V_6 -= F_10 ( struct V_42 , V_43 [ 0 ] ) ;
V_6 = V_6 >> 2 ;
V_47 = V_12 -> V_33 . V_44 . V_45 [ V_6 ] ;
}
return F_13 ( V_47 , ( unsigned long V_9 * ) V_40 ) ;
}
static int F_14 ( struct V_48 V_9 * V_49 , struct V_1 * V_12 )
{
int V_3 , V_8 , V_50 = ( (struct V_51 * ) V_12 -> V_52 ) -> V_50 ;
struct V_48 V_53 ;
V_3 = F_15 ( V_54 [ V_50 ] , ( unsigned long * ) & V_53 ) ;
if ( V_3 )
return V_3 ;
V_8 = F_16 ( V_49 , & V_53 , sizeof( V_53 ) ) ;
if( V_8 > 0 )
return - V_55 ;
return V_8 ;
}
static int F_17 ( struct V_48 V_9 * V_49 , struct V_1 * V_12 )
{
int V_8 , V_50 = ( (struct V_51 * ) V_12 -> V_52 ) -> V_50 ;
struct V_48 V_53 ;
V_8 = F_5 ( & V_53 , V_49 , sizeof( V_53 ) ) ;
if ( V_8 > 0 )
return - V_55 ;
return F_18 ( V_54 [ V_50 ] ,
( unsigned long * ) & V_53 ) ;
}
static int F_19 ( struct V_56 V_9 * V_49 , struct V_1 * V_12 )
{
int V_3 , V_8 , V_50 = ( (struct V_51 * ) V_12 -> V_52 ) -> V_50 ;
struct V_56 V_53 ;
V_3 = F_20 ( V_54 [ V_50 ] , ( unsigned long * ) & V_53 ) ;
if ( V_3 )
return V_3 ;
V_8 = F_16 ( V_49 , & V_53 , sizeof( V_53 ) ) ;
if( V_8 > 0 )
return - V_55 ;
return V_8 ;
}
static int F_21 ( struct V_56 V_9 * V_49 , struct V_1 * V_12 )
{
int V_8 , V_50 = ( (struct V_51 * ) V_12 -> V_52 ) -> V_50 ;
struct V_56 V_53 ;
V_8 = F_5 ( & V_53 , V_49 , sizeof( V_53 ) ) ;
if ( V_8 > 0 )
return - V_55 ;
return F_22 ( V_54 [ V_50 ] ,
( unsigned long * ) & V_53 ) ;
}
long F_23 ( struct V_1 * V_12 , long V_57 ,
unsigned long V_6 , unsigned long V_40 )
{
int V_58 = - V_25 ;
void V_9 * V_59 = ( void V_9 * ) V_40 ;
switch ( V_57 ) {
case V_60 :
V_58 = F_14 ( V_59 , V_12 ) ;
break;
case V_61 :
V_58 = F_17 ( V_59 , V_12 ) ;
break;
case V_62 :
V_58 = F_19 ( V_59 , V_12 ) ;
break;
case V_63 :
V_58 = F_21 ( V_59 , V_12 ) ;
break;
default:
V_58 = - V_25 ;
}
return V_58 ;
}
