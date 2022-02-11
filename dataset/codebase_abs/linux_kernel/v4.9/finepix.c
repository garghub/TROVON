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
F_6 ( V_19 , L_1 ) ;
V_20:
while ( V_1 -> V_21 && V_1 -> V_22 ) {
#ifdef F_7
if ( V_1 -> V_23 )
break;
#endif
F_8 ( & V_1 -> V_24 ) ;
V_17 = F_1 ( V_1 , 1 ) ;
F_9 ( & V_1 -> V_24 ) ;
if ( V_17 < 0 )
break;
#ifdef F_7
if ( V_1 -> V_23 )
break;
#endif
if ( ! V_1 -> V_21 || ! V_1 -> V_22 )
break;
for (; ; ) {
V_17 = F_10 ( V_1 -> V_5 ,
V_14 -> V_25 ,
V_15 ,
V_26 ,
& V_18 , V_10 ) ;
if ( V_17 < 0 ) {
goto V_20;
}
#ifdef F_7
if ( V_1 -> V_23 )
goto V_27;
#endif
if ( ! V_1 -> V_21 || ! V_1 -> V_22 )
goto V_27;
if ( V_18 < V_26 ||
( V_15 [ V_18 - 2 ] == 0xff &&
V_15 [ V_18 - 1 ] == 0xd9 ) ) {
F_11 ( V_1 , V_28 ,
V_15 , V_18 ) ;
break;
}
F_11 ( V_1 ,
V_1 -> V_29
== V_28
? V_30 : V_31 ,
V_15 , V_18 ) ;
}
F_12 ( V_32 ) ;
}
V_27:
F_6 ( V_19 , L_2 ) ;
}
static int F_13 ( struct V_1 * V_1 ,
const struct V_33 * V_34 )
{
struct V_13 * V_5 = (struct V_13 * ) V_1 ;
struct V_35 * V_35 = & V_1 -> V_35 ;
V_35 -> V_36 = V_37 ;
V_35 -> V_38 = 1 ;
V_35 -> V_39 = 1 ;
V_35 -> V_40 = V_26 ;
F_14 ( & V_5 -> V_11 , F_4 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_13 * V_5 = (struct V_13 * ) V_1 ;
int V_17 , V_18 ;
V_17 = F_1 ( V_1 , 0 ) ;
if ( V_17 < 0 ) {
F_17 ( L_3 , V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_1 -> V_5 ,
V_1 -> V_14 [ 0 ] -> V_25 ,
V_1 -> V_14 [ 0 ] -> V_16 ,
V_26 , & V_18 ,
V_10 ) ;
if ( V_17 < 0 ) {
F_17 ( L_4 , V_17 ) ;
return V_17 ;
}
V_17 = F_1 ( V_1 , 1 ) ;
if ( V_17 < 0 ) {
F_17 ( L_5 , V_17 ) ;
return V_17 ;
}
F_18 ( V_1 -> V_5 , V_1 -> V_14 [ 0 ] -> V_25 ) ;
F_19 ( & V_5 -> V_11 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_13 * V_5 = (struct V_13 * ) V_1 ;
F_9 ( & V_1 -> V_24 ) ;
F_21 ( & V_5 -> V_11 ) ;
F_8 ( & V_1 -> V_24 ) ;
}
static int F_22 ( struct V_41 * V_42 ,
const struct V_33 * V_34 )
{
return F_23 ( V_42 , V_34 ,
& V_43 ,
sizeof( struct V_13 ) ,
V_44 ) ;
}
