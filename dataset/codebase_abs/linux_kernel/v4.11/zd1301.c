static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 , V_12 ;
F_3 ( & V_2 -> V_13 ) ;
memcpy ( & V_8 -> V_14 , V_3 , V_4 ) ;
F_4 ( & V_10 -> V_8 , L_1 , V_4 , V_8 -> V_14 ) ;
V_11 = F_5 ( V_2 -> V_15 , F_6 ( V_2 -> V_15 , 0x04 ) , V_8 -> V_14 ,
V_4 , & V_12 , 1000 ) ;
if ( V_11 ) {
F_7 ( & V_10 -> V_8 , L_2 , V_11 ) ;
goto V_16;
}
if ( V_6 ) {
V_11 = F_5 ( V_2 -> V_15 , F_8 ( V_2 -> V_15 , 0x83 ) ,
V_8 -> V_14 , V_6 , & V_12 , 1000 ) ;
if ( V_11 ) {
F_7 ( & V_10 -> V_8 ,
L_3 , V_11 ) ;
goto V_16;
}
F_4 ( & V_10 -> V_8 , L_4 , V_12 , V_8 -> V_14 ) ;
if ( V_12 != V_6 ) {
F_4 ( & V_10 -> V_8 , L_5 ) ;
V_11 = F_5 ( V_2 -> V_15 ,
F_8 ( V_2 -> V_15 , 0x83 ) ,
V_8 -> V_14 , V_6 , & V_12 ,
1000 ) ;
if ( V_11 ) {
F_7 ( & V_10 -> V_8 ,
L_6 , V_11 ) ;
goto V_16;
}
F_4 ( & V_10 -> V_8 ,
L_4 , V_12 , V_8 -> V_14 ) ;
}
memcpy ( V_5 , V_8 -> V_14 , V_6 ) ;
}
V_16:
F_9 ( & V_2 -> V_13 ) ;
return V_11 ;
}
static int F_10 ( void * V_17 , T_2 V_18 , T_1 V_19 )
{
struct V_1 * V_2 = V_17 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
T_1 V_14 [ 7 ] = { 0x07 , 0x00 , 0x03 , 0x01 ,
( V_18 >> 0 ) & 0xff , ( V_18 >> 8 ) & 0xff , V_19 } ;
V_11 = F_1 ( V_2 , V_14 , 7 , NULL , 0 ) ;
if ( V_11 )
goto V_20;
return 0 ;
V_20:
F_4 ( & V_10 -> V_8 , L_7 , V_11 ) ;
return V_11 ;
}
static int F_11 ( void * V_17 , T_2 V_18 , T_1 * V_19 )
{
struct V_1 * V_2 = V_17 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
T_1 V_14 [ 7 ] = { 0x07 , 0x00 , 0x04 , 0x01 ,
( V_18 >> 0 ) & 0xff , ( V_18 >> 8 ) & 0xff , 0 } ;
V_11 = F_1 ( V_2 , V_14 , 7 , V_14 , 7 ) ;
if ( V_11 )
goto V_20;
* V_19 = V_14 [ 6 ] ;
return 0 ;
V_20:
F_4 ( & V_10 -> V_8 , L_7 , V_11 ) ;
return V_11 ;
}
static int F_12 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_7 * V_8 = F_14 ( V_22 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_11 ;
F_4 ( & V_10 -> V_8 , L_8 ) ;
V_8 -> V_33 . V_17 = V_2 ;
V_8 -> V_33 . V_34 = F_11 ;
V_8 -> V_33 . V_35 = F_10 ;
F_15 ( L_9 , L_10 ) ;
V_24 = F_16 ( & V_10 -> V_8 ,
L_10 ,
V_36 ,
& V_8 -> V_33 ,
sizeof( V_8 -> V_33 ) ) ;
if ( F_17 ( V_24 ) ) {
V_11 = F_18 ( V_24 ) ;
goto V_20;
}
if ( ! V_24 -> V_8 . V_37 ) {
V_11 = - V_38 ;
goto V_20;
}
if ( ! F_19 ( V_24 -> V_8 . V_37 -> V_39 ) ) {
V_11 = - V_38 ;
goto V_40;
}
V_30 = F_20 ( V_24 ) ;
V_32 = F_21 ( V_24 ) ;
if ( ! V_30 || ! V_32 ) {
V_11 = - V_38 ;
goto V_41;
}
V_8 -> V_42 . V_43 = 9 ;
V_8 -> V_42 . V_31 = V_32 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
F_22 ( V_28 . type , L_11 , V_44 ) ;
V_28 . V_45 = 0x60 ;
V_28 . V_46 = & V_8 -> V_42 ;
F_15 ( L_9 , L_11 ) ;
V_26 = F_23 ( V_30 , & V_28 ) ;
if ( ! V_26 || ! V_26 -> V_8 . V_37 ) {
V_11 = - V_38 ;
goto V_41;
}
if ( ! F_19 ( V_26 -> V_8 . V_37 -> V_39 ) ) {
V_11 = - V_38 ;
goto V_47;
}
V_8 -> V_48 = V_24 ;
V_8 -> V_49 = V_26 ;
V_22 -> V_50 [ 0 ] = V_32 ;
return 0 ;
V_47:
F_24 ( V_26 ) ;
V_41:
F_25 ( V_24 -> V_8 . V_37 -> V_39 ) ;
V_40:
F_26 ( V_24 ) ;
V_20:
F_4 ( & V_10 -> V_8 , L_7 , V_11 ) ;
return V_11 ;
}
static int F_27 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
F_4 ( & V_10 -> V_8 , L_8 ) ;
V_26 = V_8 -> V_49 ;
V_24 = V_8 -> V_48 ;
if ( V_26 ) {
F_25 ( V_26 -> V_8 . V_37 -> V_39 ) ;
F_24 ( V_26 ) ;
}
if ( V_24 ) {
F_25 ( V_24 -> V_8 . V_37 -> V_39 ) ;
F_26 ( V_24 ) ;
}
return 0 ;
}
static int F_28 ( struct V_31 * V_50 , int V_51 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
T_1 V_14 [ 3 ] = { 0x03 , 0x00 , V_51 ? 0x07 : 0x08 } ;
F_4 ( & V_10 -> V_8 , L_12 , V_51 ) ;
V_11 = F_1 ( V_2 , V_14 , 3 , NULL , 0 ) ;
if ( V_11 )
goto V_20;
return 0 ;
V_20:
F_4 ( & V_10 -> V_8 , L_7 , V_11 ) ;
return V_11 ;
}
