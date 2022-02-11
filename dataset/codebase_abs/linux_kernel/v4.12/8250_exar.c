static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , unsigned int V_6 ,
struct V_7 * V_8 )
{
const struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
if ( ! F_2 ( V_4 ) [ V_11 ] && ! F_3 ( V_4 , V_11 , 0 ) )
return - V_12 ;
V_8 -> V_8 . V_13 = V_14 ;
V_8 -> V_8 . V_15 = F_4 ( V_4 , V_11 ) + V_6 ;
V_8 -> V_8 . V_16 = F_2 ( V_4 ) [ V_11 ] + V_6 ;
V_8 -> V_8 . V_17 = V_10 -> V_18 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , int V_5 )
{
unsigned int V_6 = V_5 * 0x200 ;
unsigned int V_19 = 1843200 ;
T_1 T_2 * V_20 ;
int V_21 ;
V_8 -> V_8 . V_22 |= V_23 ;
V_8 -> V_8 . V_24 = V_19 * 16 ;
V_21 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
if ( V_21 )
return V_21 ;
V_20 = V_8 -> V_8 . V_16 ;
F_6 ( 0x00 , V_20 + V_25 ) ;
F_6 ( V_26 , V_20 + V_27 ) ;
F_6 ( 32 , V_20 + V_28 ) ;
F_6 ( 32 , V_20 + V_29 ) ;
if ( V_5 == 0 ) {
switch ( V_4 -> V_30 ) {
case V_31 :
case V_32 :
F_6 ( 0x78 , V_20 + V_33 ) ;
F_6 ( 0x00 , V_20 + V_34 ) ;
F_6 ( 0x00 , V_20 + V_35 ) ;
break;
case V_36 :
case V_37 :
F_6 ( 0x00 , V_20 + V_33 ) ;
F_6 ( 0xc0 , V_20 + V_34 ) ;
F_6 ( 0xc0 , V_20 + V_35 ) ;
break;
}
F_6 ( 0x00 , V_20 + V_38 ) ;
F_6 ( 0x00 , V_20 + V_39 ) ;
F_6 ( 0x00 , V_20 + V_40 ) ;
}
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , int V_5 )
{
unsigned int V_6 = V_5 * 0x200 ;
unsigned int V_19 = 1843200 ;
V_8 -> V_8 . V_24 = V_19 * 16 ;
return F_1 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , int V_5 )
{
unsigned int V_6 = V_5 * 0x200 ;
unsigned int V_19 = 921600 ;
V_8 -> V_8 . V_24 = V_19 * 16 ;
return F_1 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
}
static void F_9 ( T_1 T_2 * V_20 )
{
F_6 ( 0x00 , V_20 + V_38 ) ;
F_6 ( 0x00 , V_20 + V_33 ) ;
F_6 ( 0x00 , V_20 + V_39 ) ;
F_6 ( 0x00 , V_20 + V_34 ) ;
F_6 ( 0x00 , V_20 + V_35 ) ;
F_6 ( 0x00 , V_20 + V_40 ) ;
F_6 ( 0x00 , V_20 + V_41 ) ;
F_6 ( 0x00 , V_20 + V_42 ) ;
F_6 ( 0x00 , V_20 + V_43 ) ;
F_6 ( 0x00 , V_20 + V_44 ) ;
F_6 ( 0x00 , V_20 + V_45 ) ;
F_6 ( 0x00 , V_20 + V_46 ) ;
}
static void *
F_10 ( struct V_3 * V_4 )
{
struct V_47 * V_48 ;
V_48 = F_11 ( L_1 , V_49 ) ;
if ( ! V_48 )
return NULL ;
F_12 ( V_48 , V_4 ) ;
if ( F_13 ( V_48 ) < 0 ) {
F_14 ( V_48 ) ;
return NULL ;
}
return V_48 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , int V_5 )
{
const struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int V_6 = V_5 * 0x400 ;
unsigned int V_19 = 7812500 ;
T_1 T_2 * V_20 ;
int V_50 ;
V_8 -> V_8 . V_24 = V_19 * 16 ;
if ( V_10 -> V_51 && V_5 >= 8 )
V_8 -> V_8 . V_24 /= 2 ;
V_50 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
if ( V_50 )
return V_50 ;
V_20 = V_8 -> V_8 . V_16 ;
F_6 ( 0x00 , V_20 + V_25 ) ;
F_6 ( V_26 , V_20 + V_27 ) ;
F_6 ( 128 , V_20 + V_28 ) ;
F_6 ( 128 , V_20 + V_29 ) ;
if ( V_5 == 0 ) {
F_9 ( V_20 ) ;
V_8 -> V_8 . V_52 = F_10 ( V_4 ) ;
}
return 0 ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
struct V_7 * V_8 = F_18 ( V_2 -> line [ 0 ] ) ;
struct V_47 * V_48 = V_8 -> V_8 . V_52 ;
F_19 ( V_48 ) ;
V_8 -> V_8 . V_52 = NULL ;
}
static int
F_20 ( struct V_3 * V_4 , const struct V_53 * V_54 )
{
unsigned int V_55 , V_56 , V_11 = 0 , V_57 ;
struct V_9 * V_10 ;
struct V_7 V_58 ;
struct V_1 * V_2 ;
int V_59 ;
V_10 = (struct V_9 * ) V_54 -> V_60 ;
if ( ! V_10 )
return - V_61 ;
V_59 = F_21 ( V_4 ) ;
if ( V_59 )
return V_59 ;
V_57 = F_22 ( V_4 , V_11 ) >> ( V_10 -> V_18 + 3 ) ;
V_55 = V_10 -> V_62 ? V_10 -> V_62 : V_4 -> V_30 & 0x0f ;
V_2 = F_23 ( & V_4 -> V_63 , sizeof( * V_2 ) +
sizeof( unsigned int ) * V_55 ,
V_64 ) ;
if ( ! V_2 )
return - V_12 ;
V_2 -> V_10 = V_10 ;
F_24 ( V_4 ) ;
V_59 = F_25 ( V_4 , 1 , 1 , V_65 ) ;
if ( V_59 < 0 )
return V_59 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_8 . V_22 = V_66 | V_67 | V_68
| V_23 ;
V_58 . V_8 . V_69 = F_26 ( V_4 , 0 ) ;
V_58 . V_8 . V_63 = & V_4 -> V_63 ;
for ( V_56 = 0 ; V_56 < V_55 && V_56 < V_57 ; V_56 ++ ) {
V_59 = V_10 -> V_70 ( V_2 , V_4 , & V_58 , V_56 ) ;
if ( V_59 ) {
F_27 ( & V_4 -> V_63 , L_2 , V_56 ) ;
break;
}
F_28 ( & V_4 -> V_63 , L_3 ,
V_58 . V_8 . V_71 , V_58 . V_8 . V_69 , V_58 . V_8 . V_13 ) ;
V_2 -> line [ V_56 ] = F_29 ( & V_58 ) ;
if ( V_2 -> line [ V_56 ] < 0 ) {
F_27 ( & V_4 -> V_63 ,
L_4 ,
V_58 . V_8 . V_71 , V_58 . V_8 . V_69 ,
V_58 . V_8 . V_13 , V_2 -> line [ V_56 ] ) ;
break;
}
}
V_2 -> V_72 = V_56 ;
F_30 ( V_4 , V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_72 ; V_56 ++ )
F_32 ( V_2 -> line [ V_56 ] ) ;
if ( V_2 -> V_10 -> exit )
V_2 -> V_10 -> exit ( V_4 ) ;
}
static int T_3 F_33 ( struct V_30 * V_63 )
{
struct V_3 * V_4 = F_34 ( V_63 ) ;
struct V_1 * V_2 = F_17 ( V_4 ) ;
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_72 ; V_56 ++ )
if ( V_2 -> line [ V_56 ] >= 0 )
F_35 ( V_2 -> line [ V_56 ] ) ;
if ( V_2 -> V_10 -> exit )
V_2 -> V_10 -> exit ( V_4 ) ;
return 0 ;
}
static int T_3 F_36 ( struct V_30 * V_63 )
{
struct V_3 * V_4 = F_34 ( V_63 ) ;
struct V_1 * V_2 = F_17 ( V_4 ) ;
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_72 ; V_56 ++ )
if ( V_2 -> line [ V_56 ] >= 0 )
F_37 ( V_2 -> line [ V_56 ] ) ;
return 0 ;
}
