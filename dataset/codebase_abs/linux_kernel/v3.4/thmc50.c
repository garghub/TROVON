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
int V_12 ;
unsigned long V_13 ;
int V_14 ;
V_14 = F_6 ( V_5 , 10 , & V_13 ) ;
if ( V_14 )
return V_14 ;
F_7 ( & V_7 -> V_15 ) ;
V_7 -> V_8 = F_8 ( V_13 , 0 , 255 ) ;
F_9 ( V_11 , V_16 ,
V_7 -> V_8 ) ;
V_12 = F_10 ( V_11 , V_17 ) ;
if ( V_7 -> V_8 == 0 )
V_12 &= ~ V_18 ;
else
V_12 |= V_18 ;
F_9 ( V_11 , V_17 , V_12 ) ;
F_11 ( & V_7 -> V_15 ) ;
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
int V_19 = F_14 ( V_4 ) -> V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_21 [ V_19 ] * 1000 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_19 = F_14 ( V_4 ) -> V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_22 [ V_19 ] * 1000 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_9 )
{
int V_19 = F_14 ( V_4 ) -> V_20 ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_5 ( V_11 ) ;
long V_23 ;
int V_14 ;
V_14 = F_17 ( V_5 , 10 , & V_23 ) ;
if ( V_14 )
return V_14 ;
F_7 ( & V_7 -> V_15 ) ;
V_7 -> V_22 [ V_19 ] = F_8 ( V_23 / 1000 , - 128 , 127 ) ;
F_9 ( V_11 , V_24 [ V_19 ] ,
V_7 -> V_22 [ V_19 ] ) ;
F_11 ( & V_7 -> V_15 ) ;
return V_9 ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_19 = F_14 ( V_4 ) -> V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_25 [ V_19 ] * 1000 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_9 )
{
int V_19 = F_14 ( V_4 ) -> V_20 ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_5 ( V_11 ) ;
long V_23 ;
int V_14 ;
V_14 = F_17 ( V_5 , 10 , & V_23 ) ;
if ( V_14 )
return V_14 ;
F_7 ( & V_7 -> V_15 ) ;
V_7 -> V_25 [ V_19 ] = F_8 ( V_23 / 1000 , - 128 , 127 ) ;
F_9 ( V_11 , V_26 [ V_19 ] ,
V_7 -> V_25 [ V_19 ] ) ;
F_11 ( & V_7 -> V_15 ) ;
return V_9 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_19 = F_14 ( V_4 ) -> V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_27 [ V_19 ] * 1000 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_20 = F_14 ( V_4 ) -> V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_3 , ( V_7 -> V_28 >> V_20 ) & 1 ) ;
}
static int F_22 ( struct V_10 * V_11 ,
struct V_29 * V_30 )
{
unsigned V_31 ;
unsigned V_32 ;
unsigned V_12 ;
struct V_33 * V_34 = V_11 -> V_34 ;
const char * V_35 ;
if ( ! F_23 ( V_34 , V_36 ) ) {
F_24 ( L_4
L_5 ) ;
return - V_37 ;
}
F_24 ( L_6 ,
V_11 -> V_38 , F_25 ( V_11 -> V_34 ) ) ;
V_31 = F_10 ( V_11 , V_39 ) ;
V_32 = F_10 ( V_11 , V_40 ) ;
V_12 = F_10 ( V_11 , V_17 ) ;
if ( V_32 < 0xc0 || ( V_12 & 0x10 ) )
return - V_37 ;
if ( V_31 == 0x41 ) {
int V_41 = F_25 ( V_11 -> V_34 ) ;
int V_42 ;
V_35 = L_7 ;
for ( V_42 = 0 ; V_42 + 1 < V_43 ; V_42 += 2 )
if ( V_44 [ V_42 ] == V_41 &&
V_44 [ V_42 + 1 ] == V_11 -> V_38 ) {
V_12 |= ( 1 << 7 ) ;
F_9 ( V_11 ,
V_17 ,
V_12 ) ;
break;
}
} else if ( V_31 == 0x49 ) {
V_35 = L_8 ;
} else {
F_24 ( L_9 ) ;
return - V_37 ;
}
F_24 ( L_10 ,
V_35 , ( V_32 >> 4 ) - 0xc , V_32 & 0xf ) ;
F_26 ( V_30 -> type , V_35 , V_45 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 ,
const struct V_46 * V_41 )
{
struct V_6 * V_7 ;
int V_14 ;
V_7 = F_28 ( sizeof( struct V_6 ) , V_47 ) ;
if ( ! V_7 ) {
F_24 ( L_11 ) ;
V_14 = - V_48 ;
goto exit;
}
F_29 ( V_11 , V_7 ) ;
V_7 -> type = V_41 -> V_49 ;
F_30 ( & V_7 -> V_15 ) ;
F_31 ( V_11 ) ;
V_14 = F_32 ( & V_11 -> V_2 . V_50 , & V_51 ) ;
if ( V_14 )
goto V_52;
if ( V_7 -> V_53 ) {
V_14 = F_32 ( & V_11 -> V_2 . V_50 , & V_54 ) ;
if ( V_14 )
goto V_55;
}
V_7 -> V_56 = F_33 ( & V_11 -> V_2 ) ;
if ( F_34 ( V_7 -> V_56 ) ) {
V_14 = F_35 ( V_7 -> V_56 ) ;
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
return V_14 ;
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
int V_12 ;
V_7 -> V_8 = F_10 ( V_11 ,
V_16 ) ;
if ( V_7 -> V_8 == 0 ) {
V_7 -> V_8 = 1 ;
F_9 ( V_11 , V_16 ,
V_7 -> V_8 ) ;
}
V_12 = F_10 ( V_11 , V_17 ) ;
V_12 |= 0x1 ;
if ( V_7 -> type == V_58 && ( V_12 & ( 1 << 7 ) ) )
V_7 -> V_53 = 1 ;
F_9 ( V_11 , V_17 , V_12 ) ;
}
static struct V_6 * F_2 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_6 * V_7 = F_5 ( V_11 ) ;
int V_59 = V_60 / 5 + ( V_7 -> type == V_61 ? V_60 : 0 ) ;
F_7 ( & V_7 -> V_15 ) ;
if ( F_40 ( V_62 , V_7 -> V_63 + V_59 )
|| ! V_7 -> V_64 ) {
int V_65 = V_7 -> V_53 ? 3 : 2 ;
int V_42 ;
int V_66 = F_10 ( V_11 , V_17 ) ;
V_66 &= V_67 ;
for ( V_42 = 0 ; V_42 < V_65 ; V_42 ++ ) {
V_7 -> V_21 [ V_42 ] = F_10 ( V_11 ,
V_68 [ V_42 ] ) ;
V_7 -> V_25 [ V_42 ] = F_10 ( V_11 ,
V_26 [ V_42 ] ) ;
V_7 -> V_22 [ V_42 ] = F_10 ( V_11 ,
V_24 [ V_42 ] ) ;
V_7 -> V_27 [ V_42 ] =
F_10 ( V_11 ,
V_66 ? V_69 [ V_42 ]
: V_70 [ V_42 ] ) ;
}
V_7 -> V_8 =
F_10 ( V_11 , V_16 ) ;
V_7 -> V_28 =
F_10 ( V_11 , V_71 ) ;
V_7 -> V_63 = V_62 ;
V_7 -> V_64 = 1 ;
}
F_11 ( & V_7 -> V_15 ) ;
return V_7 ;
}
