static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
V_2 , V_3 , NULL , 0 ,
V_10 ) ;
if ( V_4 < 0 ) {
F_4 ( L_1 , V_11 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
int V_12 )
{
int V_4 ;
V_4 = F_2 ( V_1 -> V_5 ,
F_6 ( V_1 -> V_5 , 0 ) ,
V_6 ,
V_13 | V_8 | V_9 ,
V_2 , V_3 , V_1 -> V_14 , V_12 ,
V_10 ) ;
if ( V_4 < 0 ) {
F_4 ( L_1 , V_11 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_5 = F_8 ( V_16 , struct V_17 , V_15 ) ;
struct V_1 * V_1 = & V_5 -> V_1 ;
int V_18 ;
int V_19 ;
int V_20 ;
int V_21 ;
int V_4 ;
T_2 * V_22 ;
V_22 = F_9 ( V_23 , V_24 | V_25 ) ;
if ( ! V_22 ) {
F_4 ( L_2 ) ;
goto V_26;
}
while ( V_1 -> V_27 && V_1 -> V_28 ) {
#ifdef F_10
if ( V_1 -> V_29 )
break;
#endif
V_4 = F_11 ( V_1 -> V_5 ,
F_12 ( V_1 -> V_5 , 0x81 ) ,
V_22 , V_30 , & V_20 ,
V_31 ) ;
F_13 ( V_32 ,
L_3 ,
V_20 , V_30 ) ;
if ( V_4 < 0 || V_20 < V_30 )
goto V_26;
V_18 = V_22 [ 0x40 ] | ( V_22 [ 0x41 ] << 8 ) | ( V_22 [ 0x42 ] << 16 )
| ( V_22 [ 0x43 ] << 24 ) ;
F_13 ( V_32 , L_4 , V_18 ) ;
V_21 = V_33 ;
F_14 ( V_1 , V_21 ,
V_22 , V_30 ) ;
while ( V_18 > 0 && V_1 -> V_27 ) {
V_19 = V_18 > V_23 ?
V_23 : V_18 ;
V_4 = F_11 ( V_1 -> V_5 ,
F_12 ( V_1 -> V_5 , 0x81 ) ,
V_22 , V_19 , & V_20 ,
V_31 ) ;
if ( V_4 < 0 || V_20 < V_19 )
goto V_26;
F_13 ( V_32 ,
L_5 ,
V_19 , V_18 ) ;
V_18 -= V_19 ;
if ( V_18 == 0 )
V_21 = V_34 ;
else
V_21 = V_35 ;
F_14 ( V_1 , V_21 ,
V_22 , V_19 ) ;
}
}
V_26:
if ( V_1 -> V_27 ) {
F_15 ( & V_1 -> V_36 ) ;
F_1 ( V_1 , V_37 , 0 ) ;
F_16 ( & V_1 -> V_36 ) ;
}
F_17 ( V_22 ) ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_38 * V_39 )
{
struct V_40 * V_40 = & V_1 -> V_40 ;
struct V_17 * V_5 = (struct V_17 * ) V_1 ;
int V_4 ;
F_13 ( V_41 ,
L_6
L_7 , V_39 -> V_42 , V_39 -> V_43 ) ;
V_4 = F_1 ( V_1 , V_44 , 0 ) ;
if ( V_4 < 0 ) {
F_19 ( L_8 ) ;
return V_4 ;
}
V_4 = F_5 ( V_1 , 0xf5 , 0 , 20 ) ;
if ( V_4 < 0 ) {
F_19 ( L_9 ) ;
return V_4 ;
}
F_13 ( V_41 ,
L_10 ,
V_1 -> V_14 [ 3 ] , 6 , V_1 -> V_14 + 14 ) ;
V_40 -> V_45 = V_46 ;
V_40 -> V_47 = 2 ;
if ( V_1 -> V_14 [ 15 ] == 0 )
V_40 -> V_47 = 1 ;
V_40 -> V_48 = 32 ;
V_40 -> V_49 = 1 ;
F_20 ( & V_5 -> V_15 , F_7 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_17 * V_5 = (struct V_17 * ) V_1 ;
F_16 ( & V_1 -> V_36 ) ;
F_22 ( V_5 -> V_50 ) ;
V_5 -> V_50 = NULL ;
F_15 ( & V_1 -> V_36 ) ;
}
static int F_23 ( struct V_1 * V_1 )
{
int V_4 ;
V_4 = F_1 ( V_1 , V_37 , 0 ) ;
return V_4 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_17 * V_5 = (struct V_17 * ) V_1 ;
int V_4 ;
V_5 -> V_51 = V_1 -> V_40 . V_45 ;
switch ( V_1 -> V_52 ) {
case 640 :
F_13 ( V_32 , L_11 ) ;
V_5 -> V_51 ++ ;
V_4 = F_1 ( V_1 , V_53 ,
V_54 ) ;
break;
default:
F_13 ( V_32 , L_12 ) ;
V_4 = F_1 ( V_1 , V_55 ,
V_54 ) ;
}
if ( V_4 < 0 ) {
F_19 ( L_13 ) ;
return V_4 ;
}
V_5 -> V_50 = F_25 ( V_56 ) ;
F_26 ( V_5 -> V_50 , & V_5 -> V_15 ) ;
return 0 ;
}
static int F_27 ( struct V_57 * V_58 ,
const struct V_38 * V_39 )
{
return F_28 ( V_58 , V_39 ,
& V_59 ,
sizeof( struct V_17 ) ,
V_60 ) ;
}
