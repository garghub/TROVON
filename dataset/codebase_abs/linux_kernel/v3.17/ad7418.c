static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( & V_4 -> V_7 ) ;
if ( F_4 ( V_8 , V_4 -> V_9 + V_10 + V_10 / 2 )
|| ! V_4 -> V_11 ) {
T_1 V_12 ;
int V_13 , V_14 ;
V_12 = F_5 ( V_6 , V_15 ) ;
V_12 &= 0x1F ;
F_6 ( V_6 , V_15 ,
V_12 | V_16 ) ;
F_7 ( 30 ) ;
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_4 -> V_17 [ V_13 ] =
F_8 ( V_6 ,
V_18 [ V_13 ] ) ;
}
for ( V_13 = 0 , V_14 = 4 ; V_13 < V_4 -> V_19 ; V_13 ++ , V_14 -- ) {
F_6 ( V_6 ,
V_15 ,
V_12 | F_9 ( V_14 ) ) ;
F_7 ( 15 ) ;
V_4 -> V_20 [ V_4 -> V_19 - 1 - V_13 ] =
F_8 ( V_6 ,
V_21 ) ;
}
F_10 ( V_6 , V_15 , V_12 ) ;
V_4 -> V_9 = V_8 ;
V_4 -> V_11 = 1 ;
}
F_11 ( & V_4 -> V_7 ) ;
return V_4 ;
}
static T_2 F_12 ( struct V_2 * V_3 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_13 ( V_23 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_24 , L_1 ,
F_14 ( V_4 -> V_17 [ V_26 -> V_27 ] ) ) ;
}
static T_2 F_15 ( struct V_2 * V_3 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_13 ( V_23 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_24 , L_1 ,
( ( V_4 -> V_20 [ V_26 -> V_27 ] >> 6 ) * 2500 + 512 ) / 1024 ) ;
}
static T_2 F_16 ( struct V_2 * V_3 , struct V_22 * V_23 ,
const char * V_24 , T_3 V_28 )
{
struct V_25 * V_26 = F_13 ( V_23 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_17 ;
int V_29 = F_17 ( V_24 , 10 , & V_17 ) ;
if ( V_29 < 0 )
return V_29 ;
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_17 [ V_26 -> V_27 ] = F_18 ( V_17 ) ;
F_10 ( V_6 ,
V_18 [ V_26 -> V_27 ] ,
V_4 -> V_17 [ V_26 -> V_27 ] ) ;
F_11 ( & V_4 -> V_7 ) ;
return V_28 ;
}
static void F_19 ( struct V_5 * V_6 )
{
struct V_1 * V_4 = F_20 ( V_6 ) ;
int V_30 = F_5 ( V_6 , V_15 ) ;
if ( V_30 < 0 ) {
F_21 ( & V_6 -> V_3 , L_2 ) ;
} else {
F_22 ( & V_6 -> V_3 , L_3 ) ;
F_6 ( V_6 , V_15 , V_30 & 0xfe ) ;
if ( V_4 -> type == V_31 || V_4 -> type == V_32 )
F_6 ( V_6 ,
V_33 , 0x00 ) ;
}
}
static int F_23 ( struct V_5 * V_6 ,
const struct V_34 * V_35 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_36 * V_37 = V_6 -> V_37 ;
struct V_1 * V_4 ;
struct V_2 * V_38 ;
const struct V_39 * * V_40 = NULL ;
if ( ! F_24 ( V_37 , V_41 |
V_42 ) )
return - V_43 ;
V_4 = F_25 ( V_3 , sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
F_26 ( V_6 , V_4 ) ;
F_27 ( & V_4 -> V_7 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> type = V_35 -> V_46 ;
switch ( V_4 -> type ) {
case V_47 :
V_4 -> V_19 = 0 ;
V_40 = V_48 ;
break;
case V_31 :
V_4 -> V_19 = 4 ;
V_40 = V_49 ;
break;
case V_32 :
V_4 -> V_19 = 1 ;
V_40 = V_50 ;
break;
}
F_22 ( V_3 , L_4 , V_6 -> V_51 ) ;
F_19 ( V_6 ) ;
V_38 = F_28 ( V_3 ,
V_6 -> V_51 ,
V_4 , V_40 ) ;
return F_29 ( V_38 ) ;
}
