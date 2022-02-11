static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_8 / 5 + ( V_4 -> type == V_9 ? V_8 : 0 ) ;
F_3 ( & V_4 -> V_10 ) ;
if ( F_4 ( V_11 , V_4 -> V_12 + V_7 )
|| ! V_4 -> V_13 ) {
int V_14 = V_4 -> V_15 ? 3 : 2 ;
int V_16 ;
int V_17 = F_5 ( V_6 , V_18 ) ;
V_17 &= V_19 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ ) {
V_4 -> V_20 [ V_16 ] = F_5 ( V_6 ,
V_21 [ V_16 ] ) ;
V_4 -> V_22 [ V_16 ] = F_5 ( V_6 ,
V_23 [ V_16 ] ) ;
V_4 -> V_24 [ V_16 ] = F_5 ( V_6 ,
V_25 [ V_16 ] ) ;
V_4 -> V_26 [ V_16 ] =
F_5 ( V_6 ,
V_17 ? V_27 [ V_16 ]
: V_28 [ V_16 ] ) ;
}
V_4 -> V_29 =
F_5 ( V_6 , V_30 ) ;
V_4 -> V_31 =
F_5 ( V_6 , V_32 ) ;
V_4 -> V_12 = V_11 ;
V_4 -> V_13 = 1 ;
}
F_6 ( & V_4 -> V_10 ) ;
return V_4 ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
struct V_33 * V_34 , char * V_35 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_35 , L_1 , V_4 -> V_29 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
const char * V_35 , T_2 V_36 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_37 ;
unsigned long V_38 ;
int V_39 ;
V_39 = F_9 ( V_35 , 10 , & V_38 ) ;
if ( V_39 )
return V_39 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_29 = F_10 ( V_38 , 0 , 255 ) ;
F_11 ( V_6 , V_30 ,
V_4 -> V_29 ) ;
V_37 = F_5 ( V_6 , V_18 ) ;
if ( V_4 -> V_29 == 0 )
V_37 &= ~ V_40 ;
else
V_37 |= V_40 ;
F_11 ( V_6 , V_18 , V_37 ) ;
F_6 ( & V_4 -> V_10 ) ;
return V_36 ;
}
static T_1 F_12 ( struct V_2 * V_3 , struct V_33 * V_34 ,
char * V_35 )
{
return sprintf ( V_35 , L_2 ) ;
}
static T_1 F_13 ( struct V_2 * V_3 , struct V_33 * V_34 ,
char * V_35 )
{
int V_41 = F_14 ( V_34 ) -> V_42 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_35 , L_1 , V_4 -> V_20 [ V_41 ] * 1000 ) ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_33 * V_34 ,
char * V_35 )
{
int V_41 = F_14 ( V_34 ) -> V_42 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_35 , L_1 , V_4 -> V_24 [ V_41 ] * 1000 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 , struct V_33 * V_34 ,
const char * V_35 , T_2 V_36 )
{
int V_41 = F_14 ( V_34 ) -> V_42 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_43 ;
int V_39 ;
V_39 = F_17 ( V_35 , 10 , & V_43 ) ;
if ( V_39 )
return V_39 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_24 [ V_41 ] = F_10 ( V_43 / 1000 , - 128 , 127 ) ;
F_11 ( V_6 , V_25 [ V_41 ] ,
V_4 -> V_24 [ V_41 ] ) ;
F_6 ( & V_4 -> V_10 ) ;
return V_36 ;
}
static T_1 F_18 ( struct V_2 * V_3 , struct V_33 * V_34 ,
char * V_35 )
{
int V_41 = F_14 ( V_34 ) -> V_42 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_35 , L_1 , V_4 -> V_22 [ V_41 ] * 1000 ) ;
}
static T_1 F_19 ( struct V_2 * V_3 , struct V_33 * V_34 ,
const char * V_35 , T_2 V_36 )
{
int V_41 = F_14 ( V_34 ) -> V_42 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_43 ;
int V_39 ;
V_39 = F_17 ( V_35 , 10 , & V_43 ) ;
if ( V_39 )
return V_39 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_22 [ V_41 ] = F_10 ( V_43 / 1000 , - 128 , 127 ) ;
F_11 ( V_6 , V_23 [ V_41 ] ,
V_4 -> V_22 [ V_41 ] ) ;
F_6 ( & V_4 -> V_10 ) ;
return V_36 ;
}
static T_1 F_20 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
char * V_35 )
{
int V_41 = F_14 ( V_34 ) -> V_42 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_35 , L_1 , V_4 -> V_26 [ V_41 ] * 1000 ) ;
}
static T_1 F_21 ( struct V_2 * V_3 , struct V_33 * V_34 ,
char * V_35 )
{
int V_42 = F_14 ( V_34 ) -> V_42 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_35 , L_3 , ( V_4 -> V_31 >> V_42 ) & 1 ) ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
unsigned V_46 ;
unsigned V_47 ;
unsigned V_37 ;
struct V_48 * V_49 = V_6 -> V_49 ;
const char * V_50 ;
if ( ! F_23 ( V_49 , V_51 ) ) {
F_24 ( L_4 ) ;
return - V_52 ;
}
F_24 ( L_5 ,
V_6 -> V_53 , F_25 ( V_6 -> V_49 ) ) ;
V_46 = F_5 ( V_6 , V_54 ) ;
V_47 = F_5 ( V_6 , V_55 ) ;
V_37 = F_5 ( V_6 , V_18 ) ;
if ( V_47 < 0xc0 || ( V_37 & 0x10 ) )
return - V_52 ;
if ( V_46 == 0x41 ) {
int V_56 = F_25 ( V_6 -> V_49 ) ;
int V_16 ;
V_50 = L_6 ;
for ( V_16 = 0 ; V_16 + 1 < V_57 ; V_16 += 2 )
if ( V_58 [ V_16 ] == V_56 &&
V_58 [ V_16 + 1 ] == V_6 -> V_53 ) {
V_37 |= ( 1 << 7 ) ;
F_11 ( V_6 ,
V_18 ,
V_37 ) ;
break;
}
} else if ( V_46 == 0x49 ) {
V_50 = L_7 ;
} else {
F_24 ( L_8 ) ;
return - V_52 ;
}
F_24 ( L_9 ,
V_50 , ( V_47 >> 4 ) - 0xc , V_47 & 0xf ) ;
F_26 ( V_45 -> type , V_50 , V_59 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_37 ;
V_4 -> V_29 = F_5 ( V_6 ,
V_30 ) ;
if ( V_4 -> V_29 == 0 ) {
V_4 -> V_29 = 1 ;
F_11 ( V_6 , V_30 ,
V_4 -> V_29 ) ;
}
V_37 = F_5 ( V_6 , V_18 ) ;
V_37 |= 0x1 ;
if ( V_4 -> type == V_60 && ( V_37 & ( 1 << 7 ) ) )
V_4 -> V_15 = 1 ;
F_11 ( V_6 , V_18 , V_37 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
const struct V_61 * V_56 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_62 ;
int V_63 = 0 ;
V_4 = F_29 ( V_3 , sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
V_4 -> V_6 = V_6 ;
V_4 -> type = V_56 -> V_66 ;
F_30 ( & V_4 -> V_10 ) ;
F_27 ( V_4 ) ;
V_4 -> V_67 [ V_63 ++ ] = & V_68 ;
if ( V_4 -> V_15 )
V_4 -> V_67 [ V_63 ++ ] = & V_69 ;
V_62 = F_31 ( V_3 , V_6 -> V_70 ,
V_4 , V_4 -> V_67 ) ;
return F_32 ( V_62 ) ;
}
