static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( F_3 ( V_2 , V_3 ) ) ;
}
static inline int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_5 ( V_2 , V_3 , F_2 ( V_4 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
int V_3 = F_8 ( V_2 , V_7 ) ;
if ( V_3 < 0 ) {
F_9 ( & V_2 -> V_8 , L_1 ) ;
} else {
F_10 ( & V_2 -> V_8 , L_2 ) ;
F_11 ( V_2 , V_7 , V_3 & 0xfe ) ;
if ( V_6 -> type == V_9 || V_6 -> type == V_10 )
F_11 ( V_2 ,
V_11 , 0x00 ) ;
}
}
static struct V_5 * F_12 ( struct V_12 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 ) ;
struct V_5 * V_6 = F_7 ( V_2 ) ;
F_14 ( & V_6 -> V_13 ) ;
if ( F_15 ( V_14 , V_6 -> V_15 + V_16 + V_16 / 2 )
|| ! V_6 -> V_17 ) {
T_1 V_18 ;
int V_19 , V_20 ;
V_18 = F_8 ( V_2 , V_7 ) ;
V_18 &= 0x1F ;
F_11 ( V_2 , V_7 ,
V_18 | V_21 ) ;
F_16 ( 30 ) ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
V_6 -> V_22 [ V_19 ] = F_1 ( V_2 , V_23 [ V_19 ] ) ;
}
for ( V_19 = 0 , V_20 = 4 ; V_19 < V_6 -> V_24 ; V_19 ++ , V_20 -- ) {
F_11 ( V_2 ,
V_7 ,
V_18 | F_17 ( V_20 ) ) ;
F_16 ( 15 ) ;
V_6 -> V_25 [ V_6 -> V_24 - 1 - V_19 ] =
F_1 ( V_2 , V_26 ) ;
}
F_4 ( V_2 , V_7 , V_18 ) ;
V_6 -> V_15 = V_14 ;
V_6 -> V_17 = 1 ;
}
F_18 ( & V_6 -> V_13 ) ;
return V_6 ;
}
static T_3 F_19 ( struct V_12 * V_8 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_20 ( V_28 ) ;
struct V_5 * V_6 = F_12 ( V_8 ) ;
return sprintf ( V_29 , L_3 ,
F_21 ( V_6 -> V_22 [ V_31 -> V_32 ] ) ) ;
}
static T_3 F_22 ( struct V_12 * V_8 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_20 ( V_28 ) ;
struct V_5 * V_6 = F_12 ( V_8 ) ;
return sprintf ( V_29 , L_3 ,
( ( V_6 -> V_25 [ V_31 -> V_32 ] >> 6 ) * 2500 + 512 ) / 1024 ) ;
}
static T_3 F_23 ( struct V_12 * V_8 , struct V_27 * V_28 ,
const char * V_29 , T_4 V_33 )
{
struct V_30 * V_31 = F_20 ( V_28 ) ;
struct V_1 * V_2 = F_13 ( V_8 ) ;
struct V_5 * V_6 = F_7 ( V_2 ) ;
long V_22 = F_24 ( V_29 , NULL , 10 ) ;
F_14 ( & V_6 -> V_13 ) ;
V_6 -> V_22 [ V_31 -> V_32 ] = F_25 ( V_22 ) ;
F_4 ( V_2 , V_23 [ V_31 -> V_32 ] , V_6 -> V_22 [ V_31 -> V_32 ] ) ;
F_18 ( & V_6 -> V_13 ) ;
return V_33 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_34 * V_35 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
struct V_5 * V_6 ;
int V_38 ;
if ( ! F_27 ( V_37 , V_39 |
V_40 ) ) {
V_38 = - V_41 ;
goto exit;
}
if ( ! ( V_6 = F_28 ( sizeof( struct V_5 ) , V_42 ) ) ) {
V_38 = - V_43 ;
goto exit;
}
F_29 ( V_2 , V_6 ) ;
F_30 ( & V_6 -> V_13 ) ;
V_6 -> type = V_35 -> V_44 ;
switch ( V_6 -> type ) {
case V_45 :
V_6 -> V_24 = 0 ;
V_6 -> V_46 . V_46 = V_47 ;
break;
case V_9 :
V_6 -> V_24 = 4 ;
V_6 -> V_46 . V_46 = V_48 ;
break;
case V_10 :
V_6 -> V_24 = 1 ;
V_6 -> V_46 . V_46 = V_49 ;
break;
}
F_10 ( & V_2 -> V_8 , L_4 , V_2 -> V_50 ) ;
F_6 ( V_2 ) ;
if ( ( V_38 = F_31 ( & V_2 -> V_8 . V_51 , & V_6 -> V_46 ) ) )
goto V_52;
V_6 -> V_53 = F_32 ( & V_2 -> V_8 ) ;
if ( F_33 ( V_6 -> V_53 ) ) {
V_38 = F_34 ( V_6 -> V_53 ) ;
goto V_54;
}
return 0 ;
V_54:
F_35 ( & V_2 -> V_8 . V_51 , & V_6 -> V_46 ) ;
V_52:
F_36 ( V_6 ) ;
exit:
return V_38 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
F_38 ( V_6 -> V_53 ) ;
F_35 ( & V_2 -> V_8 . V_51 , & V_6 -> V_46 ) ;
F_36 ( V_6 ) ;
return 0 ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_55 ) ;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_55 ) ;
}
