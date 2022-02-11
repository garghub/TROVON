static int F_1 ( struct V_1 * V_1 ,
int V_2 )
{
static T_1 V_3 [ 2 ] [ 12 ] = {
{ 0xc6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0x20 , 0 , 0 , 0 } ,
{ 0xd3 , 0 , 0 , 0 , 0 , 0 , 0 , 0x01 , 0 , 0 , 0 , 0 } ,
} ;
memcpy ( V_1 -> V_4 , V_3 [ V_2 ] , 12 ) ;
return F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 |
V_9 , 0 , 0 , V_1 -> V_4 ,
12 , V_10 ) ;
}
static void F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_5 = F_5 ( V_12 , struct V_13 , V_11 ) ;
struct V_1 * V_1 = & V_5 -> V_1 ;
struct V_14 * V_14 = V_1 -> V_14 [ 0 ] ;
T_1 * V_15 = V_14 -> V_16 ;
int V_17 = 0 ;
int V_18 ;
F_6 ( & V_1 -> V_19 ) ;
F_7 ( & V_1 -> V_19 ) ;
F_8 ( V_20 , L_1 ) ;
V_21:
while ( V_1 -> V_22 && V_1 -> V_23 ) {
F_6 ( & V_1 -> V_19 ) ;
V_17 = F_1 ( V_1 , 1 ) ;
F_7 ( & V_1 -> V_19 ) ;
if ( V_17 < 0 )
break;
if ( ! V_1 -> V_22 || ! V_1 -> V_23 )
break;
for (; ; ) {
V_17 = F_9 ( V_1 -> V_5 ,
V_14 -> V_24 ,
V_15 ,
V_25 ,
& V_18 , V_10 ) ;
if ( V_17 < 0 ) {
goto V_21;
}
if ( ! V_1 -> V_22 || ! V_1 -> V_23 )
goto V_26;
if ( V_18 < V_25 ||
( V_15 [ V_18 - 2 ] == 0xff &&
V_15 [ V_18 - 1 ] == 0xd9 ) ) {
F_10 ( V_1 , V_27 ,
V_15 , V_18 ) ;
break;
}
F_10 ( V_1 ,
V_1 -> V_28
== V_27
? V_29 : V_30 ,
V_15 , V_18 ) ;
}
F_11 ( V_31 ) ;
}
V_26:
F_8 ( V_20 , L_2 ) ;
}
static int F_12 ( struct V_1 * V_1 ,
const struct V_32 * V_33 )
{
struct V_13 * V_5 = (struct V_13 * ) V_1 ;
struct V_34 * V_34 = & V_1 -> V_34 ;
V_34 -> V_35 = V_36 ;
V_34 -> V_37 = 1 ;
V_34 -> V_38 = 1 ;
V_34 -> V_39 = V_25 ;
F_13 ( & V_5 -> V_11 , F_4 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_13 * V_5 = (struct V_13 * ) V_1 ;
int V_17 , V_18 ;
V_17 = F_1 ( V_1 , 0 ) ;
if ( V_17 < 0 ) {
F_16 ( L_3 , V_17 ) ;
return V_17 ;
}
V_17 = F_9 ( V_1 -> V_5 ,
V_1 -> V_14 [ 0 ] -> V_24 ,
V_1 -> V_14 [ 0 ] -> V_16 ,
V_25 , & V_18 ,
V_10 ) ;
if ( V_17 < 0 ) {
F_16 ( L_4 , V_17 ) ;
return V_17 ;
}
V_17 = F_1 ( V_1 , 1 ) ;
if ( V_17 < 0 ) {
F_16 ( L_5 , V_17 ) ;
return V_17 ;
}
F_17 ( V_1 -> V_5 , V_1 -> V_14 [ 0 ] -> V_24 ) ;
V_5 -> V_40 = F_18 ( V_41 ) ;
F_19 ( V_5 -> V_40 , & V_5 -> V_11 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_13 * V_5 = (struct V_13 * ) V_1 ;
F_7 ( & V_1 -> V_19 ) ;
F_21 ( V_5 -> V_40 ) ;
F_6 ( & V_1 -> V_19 ) ;
V_5 -> V_40 = NULL ;
}
static int F_22 ( struct V_42 * V_43 ,
const struct V_32 * V_33 )
{
return F_23 ( V_43 , V_33 ,
& V_44 ,
sizeof( struct V_13 ) ,
V_45 ) ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_46 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_46 ) ;
}
