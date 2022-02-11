static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_9 )
{
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_5 ( V_11 ) ;
int V_12 = F_6 ( V_5 , NULL , 10 ) ;
int V_13 ;
F_7 ( & V_7 -> V_14 ) ;
V_7 -> V_8 = F_8 ( V_12 , 0 , 255 ) ;
F_9 ( V_11 , V_15 ,
V_7 -> V_8 ) ;
V_13 = F_10 ( V_11 , V_16 ) ;
if ( V_7 -> V_8 == 0 )
V_13 &= ~ V_17 ;
else
V_13 |= V_17 ;
F_9 ( V_11 , V_16 , V_13 ) ;
F_11 ( & V_7 -> V_14 ) ;
return V_9 ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_18 = F_14 ( V_4 ) -> V_19 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_20 [ V_18 ] * 1000 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_18 = F_14 ( V_4 ) -> V_19 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_21 [ V_18 ] * 1000 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_9 )
{
int V_18 = F_14 ( V_4 ) -> V_19 ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_5 ( V_11 ) ;
int V_22 = F_17 ( V_5 , NULL , 10 ) ;
F_7 ( & V_7 -> V_14 ) ;
V_7 -> V_21 [ V_18 ] = F_8 ( V_22 / 1000 , - 128 , 127 ) ;
F_9 ( V_11 , V_23 [ V_18 ] ,
V_7 -> V_21 [ V_18 ] ) ;
F_11 ( & V_7 -> V_14 ) ;
return V_9 ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_18 = F_14 ( V_4 ) -> V_19 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_24 [ V_18 ] * 1000 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_9 )
{
int V_18 = F_14 ( V_4 ) -> V_19 ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_5 ( V_11 ) ;
int V_22 = F_17 ( V_5 , NULL , 10 ) ;
F_7 ( & V_7 -> V_14 ) ;
V_7 -> V_24 [ V_18 ] = F_8 ( V_22 / 1000 , - 128 , 127 ) ;
F_9 ( V_11 , V_25 [ V_18 ] ,
V_7 -> V_24 [ V_18 ] ) ;
F_11 ( & V_7 -> V_14 ) ;
return V_9 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_18 = F_14 ( V_4 ) -> V_19 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_26 [ V_18 ] * 1000 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_19 = F_14 ( V_4 ) -> V_19 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_3 , ( V_7 -> V_27 >> V_19 ) & 1 ) ;
}
static int F_22 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
unsigned V_30 ;
unsigned V_31 ;
unsigned V_13 ;
struct V_32 * V_33 = V_11 -> V_33 ;
const char * V_34 ;
if ( ! F_23 ( V_33 , V_35 ) ) {
F_24 ( L_4
L_5 ) ;
return - V_36 ;
}
F_24 ( L_6 ,
V_11 -> V_37 , F_25 ( V_11 -> V_33 ) ) ;
V_30 = F_10 ( V_11 , V_38 ) ;
V_31 = F_10 ( V_11 , V_39 ) ;
V_13 = F_10 ( V_11 , V_16 ) ;
if ( V_31 < 0xc0 || ( V_13 & 0x10 ) )
return - V_36 ;
if ( V_30 == 0x41 ) {
int V_40 = F_25 ( V_11 -> V_33 ) ;
int V_41 ;
V_34 = L_7 ;
for ( V_41 = 0 ; V_41 + 1 < V_42 ; V_41 += 2 )
if ( V_43 [ V_41 ] == V_40 &&
V_43 [ V_41 + 1 ] == V_11 -> V_37 ) {
V_13 |= ( 1 << 7 ) ;
F_9 ( V_11 ,
V_16 ,
V_13 ) ;
break;
}
} else if ( V_30 == 0x49 ) {
V_34 = L_8 ;
} else {
F_24 ( L_9 ) ;
return - V_36 ;
}
F_24 ( L_10 ,
V_34 , ( V_31 >> 4 ) - 0xc , V_31 & 0xf ) ;
F_26 ( V_29 -> type , V_34 , V_44 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 ,
const struct V_45 * V_40 )
{
struct V_6 * V_7 ;
int V_46 ;
V_7 = F_28 ( sizeof( struct V_6 ) , V_47 ) ;
if ( ! V_7 ) {
F_24 ( L_11 ) ;
V_46 = - V_48 ;
goto exit;
}
F_29 ( V_11 , V_7 ) ;
V_7 -> type = V_40 -> V_49 ;
F_30 ( & V_7 -> V_14 ) ;
F_31 ( V_11 ) ;
if ( ( V_46 = F_32 ( & V_11 -> V_2 . V_50 , & V_51 ) ) )
goto V_52;
if ( V_7 -> V_53 )
if ( ( V_46 = F_32 ( & V_11 -> V_2 . V_50 ,
& V_54 ) ) )
goto V_55;
V_7 -> V_56 = F_33 ( & V_11 -> V_2 ) ;
if ( F_34 ( V_7 -> V_56 ) ) {
V_46 = F_35 ( V_7 -> V_56 ) ;
goto V_57;
}
return 0 ;
V_57:
if ( V_7 -> V_53 )
F_36 ( & V_11 -> V_2 . V_50 , & V_54 ) ;
V_55:
F_36 ( & V_11 -> V_2 . V_50 , & V_51 ) ;
V_52:
F_37 ( V_7 ) ;
exit:
return V_46 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_5 ( V_11 ) ;
F_39 ( V_7 -> V_56 ) ;
F_36 ( & V_11 -> V_2 . V_50 , & V_51 ) ;
if ( V_7 -> V_53 )
F_36 ( & V_11 -> V_2 . V_50 , & V_54 ) ;
F_37 ( V_7 ) ;
return 0 ;
}
static void F_31 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_5 ( V_11 ) ;
int V_13 ;
V_7 -> V_8 = F_10 ( V_11 ,
V_15 ) ;
if ( V_7 -> V_8 == 0 ) {
V_7 -> V_8 = 1 ;
F_9 ( V_11 , V_15 ,
V_7 -> V_8 ) ;
}
V_13 = F_10 ( V_11 , V_16 ) ;
V_13 |= 0x1 ;
if ( V_7 -> type == V_58 && ( V_13 & ( 1 << 7 ) ) )
V_7 -> V_53 = 1 ;
F_9 ( V_11 , V_16 , V_13 ) ;
}
static struct V_6 * F_2 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_5 ( V_11 ) ;
int V_59 = V_60 / 5 + ( V_7 -> type == V_61 ? V_60 : 0 ) ;
F_7 ( & V_7 -> V_14 ) ;
if ( F_40 ( V_62 , V_7 -> V_63 + V_59 )
|| ! V_7 -> V_64 ) {
int V_65 = V_7 -> V_53 ? 3 : 2 ;
int V_41 ;
int V_66 = F_10 ( V_11 , V_16 ) ;
V_66 &= V_67 ;
for ( V_41 = 0 ; V_41 < V_65 ; V_41 ++ ) {
V_7 -> V_20 [ V_41 ] = F_10 ( V_11 ,
V_68 [ V_41 ] ) ;
V_7 -> V_24 [ V_41 ] = F_10 ( V_11 ,
V_25 [ V_41 ] ) ;
V_7 -> V_21 [ V_41 ] = F_10 ( V_11 ,
V_23 [ V_41 ] ) ;
V_7 -> V_26 [ V_41 ] =
F_10 ( V_11 ,
V_66 ? V_69 [ V_41 ]
: V_70 [ V_41 ] ) ;
}
V_7 -> V_8 =
F_10 ( V_11 , V_15 ) ;
V_7 -> V_27 =
F_10 ( V_11 , V_71 ) ;
V_7 -> V_63 = V_62 ;
V_7 -> V_64 = 1 ;
}
F_11 ( & V_7 -> V_14 ) ;
return V_7 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_72 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_72 ) ;
}
