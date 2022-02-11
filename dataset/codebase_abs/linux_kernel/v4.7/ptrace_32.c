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
case V_24 :
break;
case V_25 :
if ( V_14 && ( V_14 & 3 ) != 3 )
return - V_26 ;
break;
case V_27 :
if ( V_14 && ( V_14 & 3 ) != 3 )
return - V_26 ;
break;
case V_28 :
case V_29 :
if ( V_14 && ( V_14 & 3 ) != 3 )
return - V_26 ;
V_14 &= 0xffff ;
break;
case V_30 :
case V_31 :
if ( ( V_14 & 3 ) != 3 )
return - V_26 ;
V_14 &= 0xffff ;
break;
case V_32 :
V_14 &= V_33 ;
V_12 -> V_34 . V_35 . V_35 . V_36 [ V_37 ] |= V_14 ;
return 0 ;
default :
F_8 ( L_6 , V_13 ) ;
}
V_12 -> V_34 . V_35 . V_35 . V_36 [ V_38 [ V_13 ] ] = V_14 ;
return 0 ;
}
int F_9 ( struct V_1 * V_12 , long V_6 , long V_39 )
{
if ( ( V_6 & 3 ) || V_6 < 0 )
return - V_26 ;
if ( V_6 < V_40 )
return F_7 ( V_12 , V_6 , V_39 ) ;
else if ( ( V_6 >= F_10 ( struct V_41 , V_42 [ 0 ] ) ) &&
( V_6 <= F_10 ( struct V_41 , V_42 [ 7 ] ) ) ) {
V_6 -= F_10 ( struct V_41 , V_42 [ 0 ] ) ;
V_6 = V_6 >> 2 ;
if ( ( V_6 == 4 ) || ( V_6 == 5 ) )
return - V_26 ;
V_12 -> V_34 . V_43 . V_44 [ V_6 ] = V_39 ;
return 0 ;
}
return - V_26 ;
}
unsigned long F_11 ( struct V_1 * V_12 , int V_13 )
{
unsigned long V_45 = ~ 0UL ;
V_13 >>= 2 ;
switch ( V_13 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
V_45 = 0xffff ;
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
case V_32 :
case V_24 :
break;
default:
F_8 ( L_7 , V_13 ) ;
}
return V_45 & V_12 -> V_34 . V_35 . V_35 . V_36 [ V_38 [ V_13 ] ] ;
}
int F_12 ( struct V_1 * V_12 , long V_6 , long V_39 )
{
unsigned long V_46 ;
if ( ( V_6 & 3 ) || V_6 < 0 )
return - V_26 ;
V_46 = 0 ;
if ( V_6 < V_40 ) {
V_46 = F_11 ( V_12 , V_6 ) ;
}
else if ( ( V_6 >= F_10 ( struct V_41 , V_42 [ 0 ] ) ) &&
( V_6 <= F_10 ( struct V_41 , V_42 [ 7 ] ) ) ) {
V_6 -= F_10 ( struct V_41 , V_42 [ 0 ] ) ;
V_6 = V_6 >> 2 ;
V_46 = V_12 -> V_34 . V_43 . V_44 [ V_6 ] ;
}
return F_13 ( V_46 , ( unsigned long V_9 * ) V_39 ) ;
}
static int F_14 ( struct V_47 V_9 * V_48 , struct V_1 * V_12 )
{
int V_3 , V_8 , V_49 = ( (struct V_50 * ) V_12 -> V_51 ) -> V_49 ;
struct V_47 V_52 ;
V_3 = F_15 ( V_53 [ V_49 ] ,
( unsigned long * ) & V_52 ) ;
if ( V_3 )
return V_3 ;
V_8 = F_16 ( V_48 , & V_52 , sizeof( V_52 ) ) ;
if( V_8 > 0 )
return - V_54 ;
return V_8 ;
}
static int F_17 ( struct V_47 V_9 * V_48 , struct V_1 * V_12 )
{
int V_8 , V_49 = ( (struct V_50 * ) V_12 -> V_51 ) -> V_49 ;
struct V_47 V_52 ;
V_8 = F_5 ( & V_52 , V_48 , sizeof( V_52 ) ) ;
if ( V_8 > 0 )
return - V_54 ;
return F_18 ( V_53 [ V_49 ] ,
( unsigned long * ) & V_52 ) ;
}
static int F_19 ( struct V_55 V_9 * V_48 , struct V_1 * V_12 )
{
int V_3 , V_8 , V_49 = ( (struct V_50 * ) V_12 -> V_51 ) -> V_49 ;
struct V_55 V_52 ;
V_3 = F_20 ( V_53 [ V_49 ] , ( unsigned long * ) & V_52 ) ;
if ( V_3 )
return V_3 ;
V_8 = F_16 ( V_48 , & V_52 , sizeof( V_52 ) ) ;
if( V_8 > 0 )
return - V_54 ;
return V_8 ;
}
static int F_21 ( struct V_55 V_9 * V_48 , struct V_1 * V_12 )
{
int V_8 , V_49 = ( (struct V_50 * ) V_12 -> V_51 ) -> V_49 ;
struct V_55 V_52 ;
V_8 = F_5 ( & V_52 , V_48 , sizeof( V_52 ) ) ;
if ( V_8 > 0 )
return - V_54 ;
return F_22 ( V_53 [ V_49 ] ,
( unsigned long * ) & V_52 ) ;
}
long F_23 ( struct V_1 * V_12 , long V_56 ,
unsigned long V_6 , unsigned long V_39 )
{
int V_57 = - V_26 ;
void V_9 * V_58 = ( void V_9 * ) V_39 ;
switch ( V_56 ) {
case V_59 :
V_57 = F_14 ( V_58 , V_12 ) ;
break;
case V_60 :
V_57 = F_17 ( V_58 , V_12 ) ;
break;
case V_61 :
V_57 = F_19 ( V_58 , V_12 ) ;
break;
case V_62 :
V_57 = F_21 ( V_58 , V_12 ) ;
break;
default:
V_57 = - V_26 ;
}
return V_57 ;
}
