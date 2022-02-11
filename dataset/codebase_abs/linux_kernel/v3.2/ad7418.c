static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 , V_6 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 , L_1 ) ;
} else {
F_5 ( & V_2 -> V_7 , L_2 ) ;
F_6 ( V_2 , V_6 , V_5 & 0xfe ) ;
if ( V_4 -> type == V_8 || V_4 -> type == V_9 )
F_6 ( V_2 ,
V_10 , 0x00 ) ;
}
}
static struct V_3 * F_7 ( struct V_11 * V_7 )
{
struct V_1 * V_2 = F_8 ( V_7 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( & V_4 -> V_12 ) ;
if ( F_10 ( V_13 , V_4 -> V_14 + V_15 + V_15 / 2 )
|| ! V_4 -> V_16 ) {
T_1 V_17 ;
int V_18 , V_19 ;
V_17 = F_3 ( V_2 , V_6 ) ;
V_17 &= 0x1F ;
F_6 ( V_2 , V_6 ,
V_17 | V_20 ) ;
F_11 ( 30 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
V_4 -> V_21 [ V_18 ] =
F_12 ( V_2 ,
V_22 [ V_18 ] ) ;
}
for ( V_18 = 0 , V_19 = 4 ; V_18 < V_4 -> V_23 ; V_18 ++ , V_19 -- ) {
F_6 ( V_2 ,
V_6 ,
V_17 | F_13 ( V_19 ) ) ;
F_11 ( 15 ) ;
V_4 -> V_24 [ V_4 -> V_23 - 1 - V_18 ] =
F_12 ( V_2 ,
V_25 ) ;
}
F_14 ( V_2 , V_6 , V_17 ) ;
V_4 -> V_14 = V_13 ;
V_4 -> V_16 = 1 ;
}
F_15 ( & V_4 -> V_12 ) ;
return V_4 ;
}
static T_2 F_16 ( struct V_11 * V_7 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_17 ( V_27 ) ;
struct V_3 * V_4 = F_7 ( V_7 ) ;
return sprintf ( V_28 , L_3 ,
F_18 ( V_4 -> V_21 [ V_30 -> V_31 ] ) ) ;
}
static T_2 F_19 ( struct V_11 * V_7 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_17 ( V_27 ) ;
struct V_3 * V_4 = F_7 ( V_7 ) ;
return sprintf ( V_28 , L_3 ,
( ( V_4 -> V_24 [ V_30 -> V_31 ] >> 6 ) * 2500 + 512 ) / 1024 ) ;
}
static T_2 F_20 ( struct V_11 * V_7 , struct V_26 * V_27 ,
const char * V_28 , T_3 V_32 )
{
struct V_29 * V_30 = F_17 ( V_27 ) ;
struct V_1 * V_2 = F_8 ( V_7 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
long V_21 = F_21 ( V_28 , NULL , 10 ) ;
F_9 ( & V_4 -> V_12 ) ;
V_4 -> V_21 [ V_30 -> V_31 ] = F_22 ( V_21 ) ;
F_14 ( V_2 ,
V_22 [ V_30 -> V_31 ] ,
V_4 -> V_21 [ V_30 -> V_31 ] ) ;
F_15 ( & V_4 -> V_12 ) ;
return V_32 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_33 * V_34 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_3 * V_4 ;
int V_37 ;
if ( ! F_24 ( V_36 , V_38 |
V_39 ) ) {
V_37 = - V_40 ;
goto exit;
}
if ( ! ( V_4 = F_25 ( sizeof( struct V_3 ) , V_41 ) ) ) {
V_37 = - V_42 ;
goto exit;
}
F_26 ( V_2 , V_4 ) ;
F_27 ( & V_4 -> V_12 ) ;
V_4 -> type = V_34 -> V_43 ;
switch ( V_4 -> type ) {
case V_44 :
V_4 -> V_23 = 0 ;
V_4 -> V_45 . V_45 = V_46 ;
break;
case V_8 :
V_4 -> V_23 = 4 ;
V_4 -> V_45 . V_45 = V_47 ;
break;
case V_9 :
V_4 -> V_23 = 1 ;
V_4 -> V_45 . V_45 = V_48 ;
break;
}
F_5 ( & V_2 -> V_7 , L_4 , V_2 -> V_49 ) ;
F_1 ( V_2 ) ;
if ( ( V_37 = F_28 ( & V_2 -> V_7 . V_50 , & V_4 -> V_45 ) ) )
goto V_51;
V_4 -> V_52 = F_29 ( & V_2 -> V_7 ) ;
if ( F_30 ( V_4 -> V_52 ) ) {
V_37 = F_31 ( V_4 -> V_52 ) ;
goto V_53;
}
return 0 ;
V_53:
F_32 ( & V_2 -> V_7 . V_50 , & V_4 -> V_45 ) ;
V_51:
F_33 ( V_4 ) ;
exit:
return V_37 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_35 ( V_4 -> V_52 ) ;
F_32 ( & V_2 -> V_7 . V_50 , & V_4 -> V_45 ) ;
F_33 ( V_4 ) ;
return 0 ;
}
static int T_4 F_36 ( void )
{
return F_37 ( & V_54 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_54 ) ;
}
