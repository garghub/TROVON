static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 [ 1 ] ;
unsigned long V_7 ;
F_2 ( & V_2 -> V_8 ) ;
if ( V_4 -> V_9 ) {
V_5 = F_3 ( V_2 -> V_10 , V_4 -> args , V_4 -> V_9 ) ;
if ( V_5 < 0 ) {
goto V_11;
} else if ( V_5 != V_4 -> V_9 ) {
V_5 = - V_12 ;
goto V_11;
}
}
#define F_4 80
V_7 = V_13 + F_5 ( F_4 ) ;
while ( ! F_6 ( V_13 , V_7 ) ) {
V_5 = F_7 ( V_2 -> V_10 , V_6 , 1 ) ;
if ( V_5 < 0 ) {
goto V_11;
} else if ( V_5 != 1 ) {
V_5 = - V_12 ;
goto V_11;
}
if ( ( V_6 [ 0 ] >> 7 ) & 0x01 )
break;
}
F_8 ( & V_2 -> V_10 -> V_14 , L_1 , V_15 ,
F_9 ( V_13 ) -
( F_9 ( V_7 ) - F_4 ) ) ;
if ( ! ( ( V_6 [ 0 ] >> 7 ) & 0x01 ) ) {
V_5 = - V_16 ;
goto V_11;
} else {
V_5 = 0 ;
}
V_11:
F_10 ( & V_2 -> V_8 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_8 ( & V_2 -> V_10 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_8 ( & V_2 -> V_10 -> V_14 , L_3 , V_15 ) ;
V_2 -> V_21 = true ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_8 ( & V_2 -> V_10 -> V_14 , L_3 , V_15 ) ;
V_2 -> V_21 = false ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_22 * V_23 = & V_19 -> V_24 ;
int V_5 ;
struct V_3 V_4 ;
F_8 ( & V_2 -> V_10 -> V_14 ,
L_4 ,
V_15 , V_23 -> V_25 , V_23 -> V_26 ,
V_23 -> V_27 ) ;
if ( ! V_2 -> V_21 ) {
V_5 = - V_28 ;
goto V_17;
}
V_4 . args [ 0 ] = 0xc0 ;
V_4 . args [ 1 ] = 0x00 ;
V_4 . args [ 2 ] = 0x0c ;
V_4 . args [ 3 ] = 0x00 ;
V_4 . args [ 4 ] = 0x00 ;
V_4 . args [ 5 ] = 0x01 ;
V_4 . args [ 6 ] = 0x01 ;
V_4 . args [ 7 ] = 0x01 ;
V_4 . args [ 8 ] = 0x01 ;
V_4 . args [ 9 ] = 0x01 ;
V_4 . args [ 10 ] = 0x01 ;
V_4 . args [ 11 ] = 0x02 ;
V_4 . args [ 12 ] = 0x00 ;
V_4 . args [ 13 ] = 0x00 ;
V_4 . args [ 14 ] = 0x01 ;
V_4 . V_9 = 15 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_4 . args [ 0 ] = 0x02 ;
V_4 . V_9 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_4 . args [ 0 ] = 0x01 ;
V_4 . args [ 1 ] = 0x01 ;
V_4 . V_9 = 2 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_4 . args [ 0 ] = 0x41 ;
V_4 . args [ 1 ] = 0x00 ;
V_4 . args [ 2 ] = 0x00 ;
V_4 . args [ 3 ] = 0x00 ;
V_4 . args [ 4 ] = ( V_23 -> V_26 >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( V_23 -> V_26 >> 8 ) & 0xff ;
V_4 . args [ 6 ] = ( V_23 -> V_26 >> 16 ) & 0xff ;
V_4 . args [ 7 ] = ( V_23 -> V_26 >> 24 ) & 0xff ;
V_4 . V_9 = 8 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_8 ( & V_2 -> V_10 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_14 ( struct V_29 * V_10 ,
const struct V_30 * V_31 )
{
struct V_32 * V_33 = V_10 -> V_14 . V_34 ;
struct V_18 * V_19 = V_33 -> V_19 ;
struct V_1 * V_2 ;
struct V_3 V_4 ;
int V_5 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_35 ) ;
if ( ! V_2 ) {
V_5 = - V_36 ;
F_16 ( & V_10 -> V_14 , L_5 , V_37 ) ;
goto V_17;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_19 = V_33 -> V_19 ;
F_17 ( & V_2 -> V_8 ) ;
V_4 . V_9 = 0 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_19 -> V_20 = V_2 ;
memcpy ( & V_19 -> V_38 . V_39 , & V_40 ,
sizeof( struct V_41 ) ) ;
F_18 ( V_10 , V_2 ) ;
F_19 ( & V_2 -> V_10 -> V_14 ,
L_6 ,
V_37 ) ;
return 0 ;
V_17:
F_8 ( & V_10 -> V_14 , L_2 , V_15 , V_5 ) ;
F_20 ( V_2 ) ;
return V_5 ;
}
static int F_21 ( struct V_29 * V_10 )
{
struct V_1 * V_2 = F_22 ( V_10 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_8 ( & V_10 -> V_14 , L_3 , V_15 ) ;
memset ( & V_19 -> V_38 . V_39 , 0 , sizeof( struct V_41 ) ) ;
V_19 -> V_20 = NULL ;
F_20 ( V_2 ) ;
return 0 ;
}
