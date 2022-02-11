static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_1 * V_6 , int V_7 )
{
int V_8 ;
V_8 = F_2 ( V_2 -> V_9 ,
F_3 ( V_2 -> V_9 , 0 ) ,
V_3 ,
V_10 | V_11 ,
V_4 , V_5 , V_6 , V_7 ,
2000 ) ;
if ( V_8 < 0 ) {
F_4 ( L_1 , V_8 ) ;
V_8 = - V_12 ;
} else
V_8 = 0 ;
F_5 ( L_2 , V_3 , V_4 , V_5 ) ;
F_6 ( V_6 , V_7 , F_5 ) ;
return V_8 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , int V_7 )
{
int V_8 ;
F_8 ( & V_2 -> V_13 ) ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
F_9 ( & V_2 -> V_13 ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_1 * V_6 , int V_7 )
{
int V_8 ;
F_5 ( L_3 , V_3 , V_4 , V_5 ) ;
F_6 ( V_6 , V_7 , F_5 ) ;
if ( ( V_8 = F_2 ( V_2 -> V_9 ,
F_11 ( V_2 -> V_9 , 0 ) ,
V_3 ,
V_10 | V_14 ,
V_4 , V_5 , V_6 , V_7 ,
2000 ) ) != V_7 ) {
F_4 ( L_4 , V_8 ) ;
return - V_12 ;
} else
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , int V_7 )
{
int V_8 ;
F_8 ( & V_2 -> V_13 ) ;
V_8 = F_10 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
F_9 ( & V_2 -> V_13 ) ;
return V_8 ;
}
int F_13 ( struct V_1 * V_2 , T_1 * V_15 , int V_16 , T_1 * V_17 , int V_18 , int V_19 )
{
int V_8 ;
if ( ( V_8 = F_14 ( & V_2 -> V_13 ) ) )
return V_8 ;
V_8 = F_10 ( V_2 , V_20 , 0 , 0 , V_15 , V_16 ) ;
F_15 ( V_19 ) ;
V_8 = F_1 ( V_2 , V_21 , 0 , 0 , V_17 , V_18 ) ;
F_9 ( & V_2 -> V_13 ) ;
return V_8 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_22 , T_1 * V_15 ,
int V_16 , T_1 * V_17 , int V_18 , int V_19 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
int V_8 = 0 ;
T_1 * V_26 ;
int V_27 = F_17 ( V_16 + 2 , V_18 + 1 ) ;
V_8 = F_14 ( & V_24 -> V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_27 > V_24 -> V_29 ) {
V_26 = F_18 ( V_27 , V_30 ) ;
if ( ! V_26 ) {
F_9 ( & V_24 -> V_28 ) ;
return - V_31 ;
}
F_19 ( L_5 ) ;
F_20 ( V_24 -> V_26 ) ;
V_24 -> V_26 = V_26 ;
V_24 -> V_29 = V_27 ;
} else {
V_26 = V_24 -> V_26 ;
}
V_26 [ 0 ] = 0x00 ;
V_26 [ 1 ] = V_22 ;
memcpy ( & V_26 [ 2 ] , V_15 , V_16 ) ;
V_8 = F_13 ( V_2 , V_26 , V_16 + 2 , V_26 , V_18 + 1 , V_19 ) ;
if ( V_8 == 0 )
memcpy ( V_17 , & V_26 [ 1 ] , V_18 ) ;
F_9 ( & V_24 -> V_28 ) ;
return V_8 ;
}
static int F_21 ( struct V_32 * V_33 , T_1 V_34 )
{
int V_8 ;
struct V_23 * V_24 = V_33 -> V_35 -> V_25 ;
T_1 * V_26 ;
F_8 ( & V_24 -> V_28 ) ;
V_26 = V_24 -> V_26 ;
memset ( V_26 , 0 , 16 ) ;
V_8 = F_7 ( V_33 -> V_35 , 0xe0 , ( V_34 << 8 ) | 0x0e ,
0 , V_26 , 16 ) ;
F_9 ( & V_24 -> V_28 ) ;
return V_8 ;
}
static int F_22 ( struct V_32 * V_33 , T_1 V_36 )
{
int V_8 ;
struct V_23 * V_24 = V_33 -> V_35 -> V_25 ;
T_1 * V_26 ;
F_8 ( & V_24 -> V_28 ) ;
V_26 = V_24 -> V_26 ;
memset ( V_26 , 0 , 16 ) ;
V_8 = F_7 ( V_33 -> V_35 , 0xe0 , ( V_36 << 8 ) | 0x0f ,
0 , V_26 , 16 ) ;
F_9 ( & V_24 -> V_28 ) ;
return V_8 ;
}
static int F_23 ( struct V_32 * V_33 , T_2 V_37 , T_1 V_38 , int V_39 )
{
struct V_40 * V_24 = V_33 -> V_25 ;
struct V_23 * V_41 = V_33 -> V_35 -> V_25 ;
T_1 * V_26 ;
if ( V_39 )
V_24 -> V_42 |= ( 1 << V_38 ) ;
else {
V_24 -> V_42 &= ~ ( 1 << V_38 ) ;
V_37 = 0xffff ;
}
V_38 = 0x10 + V_38 * 2 ;
F_22 ( V_33 , V_24 -> V_42 ) ;
F_8 ( & V_41 -> V_28 ) ;
V_26 = V_41 -> V_26 ;
memset ( V_26 , 0 , 16 ) ;
F_7 ( V_33 -> V_35 , 0xe0 , ( ( ( V_37 >> 8 ) & 0xff ) << 8 ) | ( V_38 ) , 0 , V_26 , 16 ) ;
F_7 ( V_33 -> V_35 , 0xe0 , ( ( ( V_37 ) & 0xff ) << 8 ) | ( V_38 + 1 ) , 0 , V_26 , 16 ) ;
F_9 ( & V_41 -> V_28 ) ;
return 0 ;
}
static int F_24 ( struct V_32 * V_33 )
{
struct V_40 * V_24 = V_33 -> V_25 ;
struct V_23 * V_41 = V_33 -> V_35 -> V_25 ;
int V_17 ;
T_1 * V_6 ;
V_24 -> V_43 = 8 ;
V_24 -> V_44 = 1 ;
V_24 -> V_42 = 0x00 ;
F_21 ( V_33 , 1 ) ;
for ( V_17 = 0 ; V_17 < V_24 -> V_43 ; V_17 ++ )
F_23 ( V_33 , 0xffff , V_17 , 1 ) ;
F_8 ( & V_41 -> V_28 ) ;
V_6 = V_41 -> V_26 ;
memset ( V_6 , 0 , 10 ) ;
F_7 ( V_33 -> V_35 , 0xb5 , 3 , 0 , V_6 , 10 ) ;
F_7 ( V_33 -> V_35 , 0xb5 , 0 , 0 , V_6 , 10 ) ;
F_7 ( V_33 -> V_35 , 0xb5 , 1 , 0 , V_6 , 10 ) ;
F_9 ( & V_41 -> V_28 ) ;
return 0 ;
}
static int F_25 ( struct V_32 * V_33 , int V_39 )
{
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_3 * V_45 , int * V_36 )
{
T_1 * V_46 ;
int V_17 ;
return 0 ;
V_46 = F_18 ( 10 , V_30 ) ;
if ( ! V_46 )
return - V_31 ;
F_7 ( V_2 , V_47 , 0 , 0 , V_46 , 10 ) ;
F_27 ( L_6 , V_46 [ 1 ] , V_46 [ 1 ] ) ;
if ( V_46 [ 1 ] == 0x44 ) {
* V_36 = V_48 ;
F_20 ( V_46 ) ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < F_28 ( V_49 ) ; V_17 ++ )
if ( F_29 ( & V_49 [ V_17 ] ) == V_46 [ 1 ] ) {
* V_36 = V_50 ;
* V_45 = V_49 [ V_17 ] . V_51 ;
break;
}
F_20 ( V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_52 [ 6 ] )
{
T_1 V_17 , * V_26 ;
struct V_23 * V_24 = V_2 -> V_25 ;
F_8 ( & V_24 -> V_28 ) ;
V_26 = V_24 -> V_26 ;
for ( V_17 = 6 ; V_17 < 12 ; V_17 ++ )
F_7 ( V_2 , V_53 , V_17 , 1 , & V_26 [ V_17 - 6 ] , 1 ) ;
memcpy ( V_52 , V_26 , 6 ) ;
F_9 ( & V_24 -> V_28 ) ;
return 0 ;
}
static int F_31 ( struct V_32 * V_33 )
{
T_1 V_26 [ 10 ] = { 0 } ;
F_12 ( V_33 -> V_35 , V_54 , 0 , 7 , NULL , 0 ) ;
if ( F_16 ( V_33 -> V_35 , V_55 , NULL , 0 ,
V_26 , 10 , 10 ) )
return - V_12 ;
V_26 [ 9 ] = '\0' ;
F_19 ( L_7 , & V_26 [ 1 ] ) ;
F_24 ( V_33 ) ;
V_33 -> V_56 [ 0 ] . V_57 = F_32 ( V_33 -> V_35 ) ;
F_12 ( V_33 -> V_35 , V_54 , 1 , 7 , NULL , 0 ) ;
return 0 ;
}
static int F_33 ( struct V_58 * V_59 ,
const struct V_60 * V_38 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_8 ;
V_8 = F_34 ( V_59 , & V_61 ,
V_62 , & V_2 , V_63 ) ;
if ( V_8 )
goto V_64;
V_24 = V_2 -> V_25 ;
V_24 -> V_29 = 16 ;
V_24 -> V_26 = F_18 ( V_24 -> V_29 , V_30 ) ;
if ( ! V_24 -> V_26 ) {
V_8 = - V_31 ;
F_35 ( V_59 ) ;
goto V_64;
}
F_36 ( & V_24 -> V_28 ) ;
V_64:
return V_8 ;
}
static void F_37 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_38 ( V_59 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
F_8 ( & V_24 -> V_28 ) ;
F_20 ( V_24 -> V_26 ) ;
F_9 ( & V_24 -> V_28 ) ;
F_35 ( V_59 ) ;
}
