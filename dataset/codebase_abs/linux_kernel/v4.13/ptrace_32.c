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
V_8 = F_6 ( V_10 , V_6 , & V_7 , sizeof( V_7 ) ,
V_11 ) ;
if ( V_8 != sizeof( V_7 ) ) {
F_3 ( V_12 L_4
L_5 , V_6 ) ;
return 1 ;
}
}
return ( V_7 == 0x80cd ) || ( V_7 == 0x340f ) ;
}
int F_7 ( struct V_1 * V_13 , int V_14 , unsigned long V_15 )
{
V_14 >>= 2 ;
switch ( V_14 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
break;
case V_25 :
F_8 ( & V_13 -> V_26 . V_27 . V_27 ) = V_15 ;
break;
case V_28 :
if ( V_15 && ( V_15 & 3 ) != 3 )
return - V_29 ;
break;
case V_30 :
if ( V_15 && ( V_15 & 3 ) != 3 )
return - V_29 ;
break;
case V_31 :
case V_32 :
if ( V_15 && ( V_15 & 3 ) != 3 )
return - V_29 ;
V_15 &= 0xffff ;
break;
case V_33 :
case V_34 :
if ( ( V_15 & 3 ) != 3 )
return - V_29 ;
V_15 &= 0xffff ;
break;
case V_35 :
V_15 &= V_36 ;
V_13 -> V_26 . V_27 . V_27 . V_37 [ V_38 ] |= V_15 ;
return 0 ;
default :
F_9 ( L_6 , V_14 ) ;
}
V_13 -> V_26 . V_27 . V_27 . V_37 [ V_39 [ V_14 ] ] = V_15 ;
return 0 ;
}
int F_10 ( struct V_1 * V_13 , long V_6 , long V_40 )
{
if ( ( V_6 & 3 ) || V_6 < 0 )
return - V_29 ;
if ( V_6 < V_41 )
return F_7 ( V_13 , V_6 , V_40 ) ;
else if ( ( V_6 >= F_11 ( struct V_42 , V_43 [ 0 ] ) ) &&
( V_6 <= F_11 ( struct V_42 , V_43 [ 7 ] ) ) ) {
V_6 -= F_11 ( struct V_42 , V_43 [ 0 ] ) ;
V_6 = V_6 >> 2 ;
if ( ( V_6 == 4 ) || ( V_6 == 5 ) )
return - V_29 ;
V_13 -> V_26 . V_44 . V_45 [ V_6 ] = V_40 ;
return 0 ;
}
return - V_29 ;
}
unsigned long F_12 ( struct V_1 * V_13 , int V_14 )
{
unsigned long V_46 = ~ 0UL ;
V_14 >>= 2 ;
switch ( V_14 ) {
case V_28 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
V_46 = 0xffff ;
break;
case V_23 :
case V_24 :
case V_22 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_35 :
case V_25 :
break;
default:
F_9 ( L_7 , V_14 ) ;
}
return V_46 & V_13 -> V_26 . V_27 . V_27 . V_37 [ V_39 [ V_14 ] ] ;
}
int F_13 ( struct V_1 * V_13 , long V_6 , long V_40 )
{
unsigned long V_47 ;
if ( ( V_6 & 3 ) || V_6 < 0 )
return - V_29 ;
V_47 = 0 ;
if ( V_6 < V_41 ) {
V_47 = F_12 ( V_13 , V_6 ) ;
}
else if ( ( V_6 >= F_11 ( struct V_42 , V_43 [ 0 ] ) ) &&
( V_6 <= F_11 ( struct V_42 , V_43 [ 7 ] ) ) ) {
V_6 -= F_11 ( struct V_42 , V_43 [ 0 ] ) ;
V_6 = V_6 >> 2 ;
V_47 = V_13 -> V_26 . V_44 . V_45 [ V_6 ] ;
}
return F_14 ( V_47 , ( unsigned long V_9 * ) V_40 ) ;
}
static int F_15 ( struct V_48 V_9 * V_49 , struct V_1 * V_13 )
{
int V_3 , V_8 , V_50 = F_16 ( V_13 ) ;
struct V_48 V_51 ;
V_3 = F_17 ( V_52 [ V_50 ] ,
( unsigned long * ) & V_51 ) ;
if ( V_3 )
return V_3 ;
V_8 = F_18 ( V_49 , & V_51 , sizeof( V_51 ) ) ;
if( V_8 > 0 )
return - V_53 ;
return V_8 ;
}
static int F_19 ( struct V_48 V_9 * V_49 , struct V_1 * V_13 )
{
int V_8 , V_50 = F_16 ( V_13 ) ;
struct V_48 V_51 ;
V_8 = F_5 ( & V_51 , V_49 , sizeof( V_51 ) ) ;
if ( V_8 > 0 )
return - V_53 ;
return F_20 ( V_52 [ V_50 ] ,
( unsigned long * ) & V_51 ) ;
}
static int F_21 ( struct V_54 V_9 * V_49 , struct V_1 * V_13 )
{
int V_3 , V_8 , V_50 = F_16 ( V_13 ) ;
struct V_54 V_51 ;
V_3 = F_22 ( V_52 [ V_50 ] , ( unsigned long * ) & V_51 ) ;
if ( V_3 )
return V_3 ;
V_8 = F_18 ( V_49 , & V_51 , sizeof( V_51 ) ) ;
if( V_8 > 0 )
return - V_53 ;
return V_8 ;
}
static int F_23 ( struct V_54 V_9 * V_49 , struct V_1 * V_13 )
{
int V_8 , V_50 = F_16 ( V_13 ) ;
struct V_54 V_51 ;
V_8 = F_5 ( & V_51 , V_49 , sizeof( V_51 ) ) ;
if ( V_8 > 0 )
return - V_53 ;
return F_24 ( V_52 [ V_50 ] ,
( unsigned long * ) & V_51 ) ;
}
long F_25 ( struct V_1 * V_13 , long V_55 ,
unsigned long V_6 , unsigned long V_40 )
{
int V_56 = - V_29 ;
void V_9 * V_57 = ( void V_9 * ) V_40 ;
switch ( V_55 ) {
case V_58 :
V_56 = F_15 ( V_57 , V_13 ) ;
break;
case V_59 :
V_56 = F_19 ( V_57 , V_13 ) ;
break;
case V_60 :
V_56 = F_21 ( V_57 , V_13 ) ;
break;
case V_61 :
V_56 = F_23 ( V_57 , V_13 ) ;
break;
default:
V_56 = - V_29 ;
}
return V_56 ;
}
