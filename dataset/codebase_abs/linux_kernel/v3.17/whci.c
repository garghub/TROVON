static
T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = V_3 ;
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_7 == V_8
&& ( V_5 -> V_9 == 0x0c3b || V_5 -> V_9 == 0004 )
&& V_5 -> V_10 == 0x0d1010 ) {
switch ( F_2 ( V_3 ) ) {
case 0x80 :
V_3 |= 0x40 << 8 ; break;
case 0x02 :
V_3 &= ~ 0xffff ;
V_3 |= 0x2001 ;
break;
}
}
if ( V_4 != V_3 )
F_3 ( & V_5 -> V_11 ,
L_1
L_2 ,
V_5 -> V_7 , V_5 -> V_9 , V_5 -> V_10 ,
( unsigned ) F_2 ( V_3 ) ,
( unsigned long long ) V_4 ,
( unsigned long long ) V_3 ) ;
return V_3 ;
}
int F_4 ( struct V_9 * V_11 , T_2 T_3 * V_12 , T_2 V_13 , T_2 V_14 ,
unsigned long V_15 , const char * V_16 )
{
unsigned V_17 = 0 ;
T_2 V_18 ;
for (; ; ) {
V_18 = F_5 ( V_12 ) ;
if ( ( V_18 & V_13 ) == V_14 )
break;
if ( V_17 >= V_15 ) {
F_6 ( V_11 , L_3 , V_16 ) ;
return - V_19 ;
}
F_7 ( 10 ) ;
V_17 += 10 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_20 )
{
struct V_21 * V_22 ;
T_1 V_3 ;
int V_23 , V_24 ;
V_22 = F_9 ( & V_2 -> V_6 -> V_11 , V_20 ) ;
if ( V_22 == NULL )
return - V_25 ;
V_3 = F_10 ( V_2 -> V_26 + F_11 ( V_20 ) ) ;
V_23 = F_12 ( V_3 ) << 1 ;
V_3 = F_1 ( V_2 , V_3 ) ;
V_22 -> V_27 = F_13 ( V_3 ) ;
V_22 -> V_28 = V_20 == 0 ? 0 : F_2 ( V_3 ) ;
V_22 -> V_23 = V_23 ;
V_22 -> V_29 . V_30 = F_14 ( V_2 -> V_6 , V_23 )
+ F_15 ( V_3 ) ;
V_22 -> V_29 . V_31 = V_22 -> V_29 . V_30
+ ( V_20 == 0 ? 0x20 : F_16 ( V_3 ) ) - 1 ;
V_22 -> V_29 . V_32 = F_17 ( & V_22 -> V_11 ) ;
V_22 -> V_29 . V_33 = V_2 -> V_6 -> V_29 [ V_23 ] . V_33 ;
V_22 -> V_29 . V_34 = & V_2 -> V_6 -> V_29 [ V_23 ] ;
V_22 -> V_35 = V_2 -> V_6 -> V_35 ;
V_24 = F_18 ( V_22 ) ;
if ( V_24 < 0 )
goto error;
V_2 -> V_36 [ V_20 ] = V_22 ;
return 0 ;
error:
F_19 ( V_22 ) ;
return V_24 ;
}
static void F_20 ( struct V_1 * V_2 , int V_20 )
{
struct V_21 * V_22 = V_2 -> V_36 [ V_20 ] ;
if ( V_22 != NULL )
F_21 ( V_22 ) ;
}
static int F_22 ( struct V_5 * V_6 )
{
void T_3 * V_26 ;
T_1 V_37 ;
V_26 = F_23 ( V_6 , 0 , 8 ) ;
if ( ! V_26 )
return - V_25 ;
V_37 = F_10 ( V_26 + V_38 ) ;
F_24 ( V_6 , V_26 ) ;
return F_25 ( V_37 ) ;
}
static int F_26 ( struct V_5 * V_6 , const struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int V_24 , V_41 , V_20 ;
V_24 = F_27 ( V_6 ) ;
if ( V_24 < 0 )
goto error;
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
V_24 = - V_42 ;
if ( ! F_30 ( V_6 , F_31 ( 64 ) ) )
F_32 ( V_6 , F_31 ( 64 ) ) ;
else if ( ! F_30 ( V_6 , F_31 ( 32 ) ) )
F_32 ( V_6 , F_31 ( 32 ) ) ;
else
goto V_43;
V_24 = V_41 = F_22 ( V_6 ) ;
if ( V_41 < 0 )
goto V_44;
V_24 = - V_25 ;
V_2 = F_33 ( sizeof( struct V_1 )
+ sizeof( struct V_21 * ) * ( V_41 + 1 ) ,
V_45 ) ;
if ( V_2 == NULL )
goto V_46;
V_2 -> V_6 = V_6 ;
V_2 -> V_41 = V_41 ;
V_24 = - V_47 ;
if ( ! F_34 ( F_14 ( V_6 , 0 ) ,
F_35 ( V_2 -> V_41 ) ,
L_4 ) )
goto V_48;
V_24 = - V_25 ;
V_2 -> V_26 = F_23 ( V_6 , 0 , F_35 ( V_2 -> V_41 ) ) ;
if ( ! V_2 -> V_26 )
goto V_49;
for ( V_20 = 0 ; V_20 <= V_2 -> V_41 ; V_20 ++ ) {
V_24 = F_8 ( V_2 , V_20 ) ;
if ( V_24 < 0 && V_20 == 0 ) {
F_6 ( & V_6 -> V_11 , L_5
L_6 , V_24 ) ;
goto V_50;
}
if ( V_24 < 0 )
F_3 ( & V_6 -> V_11 , L_7
L_8 , V_20 , V_24 ) ;
}
F_36 ( V_6 , V_2 ) ;
return 0 ;
V_50:
F_24 ( V_6 , V_2 -> V_26 ) ;
V_49:
F_37 ( F_14 ( V_6 , 0 ) , F_35 ( V_2 -> V_41 ) ) ;
V_48:
F_19 ( V_2 ) ;
V_46:
V_44:
V_43:
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
error:
return V_24 ;
}
static void F_40 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_41 ( V_6 ) ;
int V_20 ;
F_36 ( V_6 , NULL ) ;
for ( V_20 = V_2 -> V_41 ; V_20 >= 0 ; V_20 -- )
F_20 ( V_2 , V_20 ) ;
F_24 ( V_6 , V_2 -> V_26 ) ;
F_37 ( F_14 ( V_6 , 0 ) , F_35 ( V_2 -> V_41 ) ) ;
F_19 ( V_2 ) ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
}
