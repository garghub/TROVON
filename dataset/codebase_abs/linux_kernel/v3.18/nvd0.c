static int
F_1 ( struct V_1 * V_2 , int line )
{
T_1 V_3 = F_2 ( V_2 , 0x00d610 + ( line * 0x04 ) ) ;
switch ( V_3 & 0x000000c0 ) {
case 0x00000000 :
case 0x00000040 :
switch ( V_3 & 0x0000001f ) {
case 0x00 : return 2 ;
case 0x19 : return 1 ;
case 0x1c : return 0 ;
case 0x1e : return 2 ;
default:
break;
}
default:
break;
}
F_3 ( V_2 , L_1 , line , V_3 ) ;
return - V_4 ;
}
static int
F_4 ( struct V_1 * V_2 , int line , bool V_5 )
{
T_1 V_6 = V_5 ? 0x00000040 : 0x00000000 ;
int V_7 = F_1 ( V_2 , line ) ;
if ( V_7 < 0 )
return V_7 ;
else if ( V_7 < 2 )
F_5 ( V_2 , 0x00d610 + ( line * 0x04 ) , 0x000000c0 , V_6 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , int line , T_1 * V_8 , T_1 * V_9 )
{
int V_7 = F_1 ( V_2 , line ) ;
if ( V_7 < 0 )
return V_7 ;
else if ( V_7 < 2 ) {
if ( F_2 ( V_2 , 0x00d610 + ( line * 0x04 ) ) & 0x00000040 ) {
* V_8 = F_2 ( V_2 , 0x00e114 + ( V_7 * 8 ) ) ;
* V_9 = F_2 ( V_2 , 0x00e118 + ( V_7 * 8 ) ) ;
return 0 ;
}
} else if ( V_7 == 2 ) {
* V_8 = F_2 ( V_2 , 0x0200d8 ) & 0x1fff ;
* V_9 = F_2 ( V_2 , 0x0200dc ) & 0x1fff ;
return 0 ;
}
return - V_10 ;
}
static int
F_7 ( struct V_1 * V_2 , int line , T_1 V_8 , T_1 V_9 )
{
int V_7 = F_1 ( V_2 , line ) ;
if ( V_7 < 0 )
return V_7 ;
else if ( V_7 < 2 ) {
F_8 ( V_2 , 0x00e114 + ( V_7 * 8 ) , V_8 ) ;
F_8 ( V_2 , 0x00e118 + ( V_7 * 8 ) , V_9 | 0x80000000 ) ;
} else if ( V_7 == 2 ) {
F_5 ( V_2 , 0x0200d8 , 0x1fff , V_8 ) ;
F_8 ( V_2 , 0x0200dc , V_9 | 0x40000000 ) ;
}
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , int line )
{
int V_7 = F_1 ( V_2 , line ) ;
if ( V_7 < 0 )
return 0 ;
else if ( V_7 < 2 )
return ( F_10 ( V_2 ) -> V_11 * 1000 ) / 20 ;
else
return F_10 ( V_2 ) -> V_11 * 1000 / 10 ;
}
int
F_11 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = ( void * ) V_13 ;
int V_16 ;
V_16 = F_12 ( & V_15 -> V_17 . V_17 ) ;
if ( V_16 )
return V_16 ;
F_5 ( V_15 , 0x00e720 , 0x00000003 , 0x00000002 ) ;
if ( V_15 -> V_17 . V_18 -> V_19 . V_20 != V_21 ) {
F_5 ( V_15 , 0x00d79c , 0x000000ff , V_15 -> V_17 . V_18 -> V_19 . line ) ;
F_8 ( V_15 , 0x00e724 , F_10 ( V_15 ) -> V_11 * 1000 ) ;
F_5 ( V_15 , 0x00e720 , 0x00000001 , 0x00000001 ) ;
}
F_5 ( V_15 , 0x00e720 , 0x00000002 , 0x00000000 ) ;
return 0 ;
}
static int
F_13 ( struct V_12 * V_22 ,
struct V_12 * V_23 ,
struct V_24 * V_25 , void * V_6 , T_1 V_26 ,
struct V_12 * * V_27 )
{
struct V_14 * V_15 ;
int V_16 ;
V_16 = F_14 ( V_22 , V_23 , V_25 , & V_15 ) ;
* V_27 = F_15 ( V_15 ) ;
if ( V_16 )
return V_16 ;
F_16 ( & V_15 -> V_17 . V_17 ) ;
V_15 -> V_17 . V_17 . V_28 = F_4 ;
V_15 -> V_17 . V_17 . V_29 = F_6 ;
V_15 -> V_17 . V_17 . V_30 = F_7 ;
V_15 -> V_17 . V_17 . V_31 = F_9 ;
V_15 -> V_17 . V_17 . V_32 = V_33 ;
V_15 -> V_17 . V_17 . V_34 = V_35 ;
V_15 -> V_17 . V_36 . V_37 = V_38 ;
return F_17 ( & V_15 -> V_17 . V_17 ) ;
}
