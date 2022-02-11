static void F_1 ( int V_1 )
{
F_2 ( V_2 -> V_3 . V_4 , V_5 , 0 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_5 , 1 ) ;
F_4 ( 2 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_6 , 0 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_6 , 1 ) ;
F_4 ( 2 ) ;
F_5 ( V_2 , V_1 , 0 ) ;
F_4 ( 5 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_7 , 0 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_7 , 1 ) ;
F_4 ( 10 ) ;
F_6 ( 0x01 , V_2 -> V_8 + V_9 ) ;
F_6 ( 6 , V_2 -> V_8 + V_10 ) ;
F_6 ( ( 0x04 | 0x01 ) , V_2 -> V_8 + V_9 ) ;
F_4 ( 10 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_11 , 0 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_11 , 1 ) ;
}
static void F_7 ( int V_1 )
{
F_6 ( 0x06 , V_2 -> V_8 + V_9 ) ;
F_4 ( 1 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_5 , 0 ) ;
F_4 ( 110 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_7 , 0 ) ;
F_4 ( 700 ) ;
F_6 ( 0 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_11 , 0 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_6 , 0 ) ;
}
void F_8 ( int V_12 )
{
int V_1 = V_13 . V_1 ;
unsigned long V_14 ;
F_9 ( V_14 ) ;
if ( ! V_2 ) {
F_10 ( V_14 ) ;
return;
}
if ( V_1 == - 1 && F_11 () )
V_1 = 128 ;
if ( V_1 == - 1 && F_12 () )
V_1 = 118 ;
if ( V_12 )
F_1 ( V_1 ) ;
else
F_7 ( V_1 ) ;
F_10 ( V_14 ) ;
}
static int F_13 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_18 . V_19 ;
if ( V_16 -> V_18 . V_20 != V_21 )
V_17 = 0 ;
if ( V_16 -> V_18 . V_22 != V_21 )
V_17 = 0 ;
if ( V_23 & V_24 )
V_17 = 0 ;
switch ( V_17 ) {
case 0 :
F_14 ( V_2 , 0 , 0 , 161 ) ;
break;
case 1 :
F_14 ( V_2 , 117 , 0 , 161 ) ;
break;
case 2 :
F_14 ( V_2 , 163 , 0 , 148 ) ;
break;
case 3 :
F_14 ( V_2 , 194 , 0 , 161 ) ;
break;
case 4 :
F_14 ( V_2 , 194 , 1 , 161 ) ;
break;
default:
return - V_25 ;
}
V_26 = V_17 ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 )
{
return V_26 ;
}
static int F_16 ( struct V_27 * V_3 , T_1 V_28 )
{
V_23 |= V_24 ;
F_13 ( V_29 ) ;
return 0 ;
}
static int F_17 ( struct V_27 * V_3 )
{
V_23 &= ~ V_24 ;
F_13 ( V_29 ) ;
return 0 ;
}
static int F_18 ( struct V_27 * V_30 )
{
struct V_31 V_18 ;
unsigned long V_14 ;
F_9 ( V_14 ) ;
V_2 = V_30 ;
F_2 ( V_30 -> V_3 . V_4 , V_32 , 0 ) ;
if ( F_12 () )
F_8 ( 1 ) ;
F_10 ( V_14 ) ;
memset ( & V_18 , 0 , sizeof( struct V_31 ) ) ;
V_18 . type = V_33 ;
V_18 . V_34 = 4 ;
V_29 = F_19 ( L_1 ,
& V_30 -> V_3 , NULL ,
& V_35 , & V_18 ) ;
if ( F_20 ( V_29 ) )
return F_21 ( V_29 ) ;
V_29 -> V_18 . V_19 = 2 ;
F_13 ( V_29 ) ;
return 0 ;
}
static int F_22 ( struct V_27 * V_3 )
{
unsigned long V_14 ;
V_29 -> V_18 . V_19 = 0 ;
V_29 -> V_18 . V_20 = 0 ;
F_13 ( V_29 ) ;
F_23 ( V_29 ) ;
F_9 ( V_14 ) ;
V_2 = NULL ;
F_10 ( V_14 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_36 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_36 ) ;
}
