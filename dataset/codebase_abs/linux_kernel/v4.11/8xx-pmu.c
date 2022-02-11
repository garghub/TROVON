static T_1 F_1 ( void )
{
int V_1 ;
unsigned long V_2 ;
do {
V_1 = F_2 ( & V_3 ) ;
V_2 = F_3 ( V_4 ) ;
} while ( V_1 != F_2 ( & V_3 ) );
return ( ( T_1 ) V_1 << 16 ) | ( V_2 >> 16 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 . type ) {
case V_8 :
if ( V_6 -> V_7 . V_9 == V_10 )
return V_11 ;
if ( V_6 -> V_7 . V_9 == V_12 )
return V_13 ;
break;
case V_14 :
if ( V_6 -> V_7 . V_9 == V_15 )
return V_16 ;
if ( V_6 -> V_7 . V_9 == V_17 )
return V_18 ;
break;
case V_19 :
break;
default:
return - V_20 ;
}
return - V_21 ;
}
static int F_5 ( struct V_5 * V_6 )
{
int type = F_4 ( V_6 ) ;
if ( type < 0 )
return type ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 , int V_22 )
{
int type = F_4 ( V_6 ) ;
T_1 V_23 = 0 ;
if ( type < 0 )
return type ;
switch ( type ) {
case V_11 :
V_23 = F_7 () ;
break;
case V_13 :
if ( F_8 ( & V_24 ) == 1 )
F_9 ( V_25 , 0xc0080007 ) ;
V_23 = F_1 () ;
break;
case V_16 :
V_23 = V_26 ;
break;
case V_18 :
V_23 = V_27 ;
break;
}
F_10 ( & V_6 -> V_28 . V_29 , V_23 ) ;
return 0 ;
}
static void F_11 ( struct V_5 * V_6 )
{
int type = F_4 ( V_6 ) ;
T_1 V_30 , V_23 = 0 , V_31 = 0 ;
if ( type < 0 )
return;
do {
V_30 = F_12 ( & V_6 -> V_28 . V_29 ) ;
switch ( type ) {
case V_11 :
V_23 = F_7 () ;
V_31 = 16 * ( V_23 - V_30 ) ;
break;
case V_13 :
V_23 = F_1 () ;
V_31 = V_30 - V_23 ;
if ( V_31 < 0 )
V_31 += 0x1000000000000LL ;
break;
case V_16 :
V_23 = V_26 ;
V_31 = ( T_1 ) ( ( V_32 ) V_23 - ( V_32 ) V_30 ) ;
break;
case V_18 :
V_23 = V_27 ;
V_31 = ( T_1 ) ( ( V_32 ) V_23 - ( V_32 ) V_30 ) ;
break;
}
} while ( F_13 ( & V_6 -> V_28 . V_29 , V_30 , V_23 ) != V_30 );
F_14 ( V_31 , & V_6 -> V_33 ) ;
}
static void F_15 ( struct V_5 * V_6 , int V_22 )
{
F_11 ( V_6 ) ;
if ( F_4 ( V_6 ) != V_13 )
return;
if ( F_16 ( & V_24 ) == 0 )
F_9 ( V_25 , 7 ) ;
}
static int F_17 ( void )
{
F_9 ( V_25 , 7 ) ;
F_9 ( V_34 , 0 ) ;
F_9 ( V_4 , 0xffff ) ;
return F_18 ( & V_35 , L_1 , V_19 ) ;
}
