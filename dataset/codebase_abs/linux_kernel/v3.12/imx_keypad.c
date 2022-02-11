static void F_1 ( struct V_1 * V_2 ,
unsigned short * V_3 )
{
int V_4 ;
unsigned short V_5 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( ( V_2 -> V_7 & ( 1 << V_4 ) ) == 0 )
continue;
V_5 = F_2 ( V_2 -> V_8 + V_9 ) ;
V_5 |= 0xff00 ;
F_3 ( V_5 , V_2 -> V_8 + V_9 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_10 ) ;
V_5 &= ~ ( ( V_2 -> V_7 & 0xff ) << 8 ) ;
F_3 ( V_5 , V_2 -> V_8 + V_10 ) ;
F_4 ( 2 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_10 ) ;
V_5 |= ( V_2 -> V_7 & 0xff ) << 8 ;
F_3 ( V_5 , V_2 -> V_8 + V_10 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_9 ) ;
V_5 &= ~ ( 1 << ( 8 + V_4 ) ) ;
F_3 ( V_5 , V_2 -> V_8 + V_9 ) ;
F_4 ( 5 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_9 ) ;
V_3 [ V_4 ] = ( ~ V_5 ) & V_2 -> V_11 ;
}
V_5 = F_2 ( V_2 -> V_8 + V_9 ) ;
V_5 &= 0x00ff ;
F_3 ( V_5 , V_2 -> V_8 + V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned short * V_3 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
int V_13 , V_4 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
unsigned short V_14 ;
int V_15 ;
if ( ( V_2 -> V_7 & ( 1 << V_4 ) ) == 0 )
continue;
V_14 = V_2 -> V_16 [ V_4 ] ^
V_3 [ V_4 ] ;
if ( V_14 == 0 )
continue;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
if ( ( V_2 -> V_11 & ( 1 << V_13 ) ) == 0 )
continue;
if ( ( V_14 & ( 1 << V_13 ) ) == 0 )
continue;
V_15 = F_6 ( V_13 , V_4 , V_18 ) ;
F_7 ( V_12 , V_19 , V_20 , V_15 ) ;
F_8 ( V_12 , V_2 -> V_21 [ V_15 ] ,
V_3 [ V_4 ] & ( 1 << V_13 ) ) ;
F_9 ( & V_12 -> V_22 , L_1 ,
V_2 -> V_21 [ V_15 ] ,
V_3 [ V_4 ] & ( 1 << V_13 ) ) ;
}
}
F_10 ( V_12 ) ;
}
static void F_11 ( unsigned long V_23 )
{
struct V_1 * V_2 = (struct V_1 * ) V_23 ;
unsigned short V_3 [ V_6 ] ;
unsigned short V_5 ;
bool V_24 , V_25 ;
int V_26 ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
F_1 ( V_2 , V_3 ) ;
V_24 = false ;
for ( V_26 = 0 ; V_26 < V_6 ; V_26 ++ ) {
if ( ( V_2 -> V_7 & ( 1 << V_26 ) ) == 0 )
continue;
if ( V_2 -> V_27 [ V_26 ] ^ V_3 [ V_26 ] ) {
V_24 = true ;
break;
}
}
if ( V_24 ) {
memcpy ( V_2 -> V_27 , V_3 ,
sizeof( V_3 ) ) ;
V_2 -> V_28 = 0 ;
} else
V_2 -> V_28 ++ ;
if ( V_2 -> V_28 < V_29 ) {
F_12 ( & V_2 -> V_30 ,
V_31 + F_13 ( 10 ) ) ;
return;
}
if ( V_2 -> V_28 == V_29 ) {
F_5 ( V_2 , V_3 ) ;
memcpy ( V_2 -> V_16 , V_3 ,
sizeof( V_3 ) ) ;
}
V_25 = true ;
for ( V_26 = 0 ; V_26 < V_6 ; V_26 ++ ) {
if ( V_3 [ V_26 ] != 0 ) {
V_25 = false ;
break;
}
}
if ( V_25 ) {
V_5 = F_2 ( V_2 -> V_8 + V_32 ) ;
V_5 |= V_33 | V_34 ;
F_3 ( V_5 , V_2 -> V_8 + V_32 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_32 ) ;
V_5 |= V_35 ;
V_5 &= ~ V_36 ;
F_3 ( V_5 , V_2 -> V_8 + V_32 ) ;
} else {
F_12 ( & V_2 -> V_30 ,
V_31 + F_13 ( 60 ) ) ;
V_5 = F_2 ( V_2 -> V_8 + V_32 ) ;
V_5 |= V_37 | V_38 ;
F_3 ( V_5 , V_2 -> V_8 + V_32 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_32 ) ;
V_5 |= V_36 ;
V_5 &= ~ V_35 ;
F_3 ( V_5 , V_2 -> V_8 + V_32 ) ;
}
}
static T_1 F_14 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
unsigned short V_5 ;
V_5 = F_2 ( V_2 -> V_8 + V_32 ) ;
V_5 &= ~ ( V_36 | V_35 ) ;
V_5 |= V_37 | V_33 ;
F_3 ( V_5 , V_2 -> V_8 + V_32 ) ;
if ( V_2 -> V_41 ) {
V_2 -> V_28 = 0 ;
F_12 ( & V_2 -> V_30 ,
V_31 + F_13 ( 2 ) ) ;
}
return V_42 ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned short V_5 ;
V_5 = F_2 ( V_2 -> V_8 + V_10 ) ;
V_5 |= V_2 -> V_11 & 0xff ;
V_5 |= ( V_2 -> V_7 & 0xff ) << 8 ;
F_3 ( V_5 , V_2 -> V_8 + V_10 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_9 ) ;
V_5 &= 0x00ff ;
F_3 ( V_5 , V_2 -> V_8 + V_9 ) ;
F_3 ( 0xff00 , V_2 -> V_8 + V_43 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_32 ) ;
V_5 |= V_37 | V_33 |
V_34 | V_38 ;
F_3 ( V_5 , V_2 -> V_8 + V_32 ) ;
V_5 |= V_35 ;
V_5 &= ~ V_36 ;
F_3 ( V_5 , V_2 -> V_8 + V_32 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
unsigned short V_5 ;
V_5 = F_2 ( V_2 -> V_8 + V_32 ) ;
V_5 &= ~ ( V_36 | V_35 ) ;
V_5 |= V_37 | V_33 ;
F_3 ( V_5 , V_2 -> V_8 + V_32 ) ;
V_5 = ( V_2 -> V_7 & 0xff ) << 8 ;
F_3 ( V_5 , V_2 -> V_8 + V_10 ) ;
}
static void F_17 ( struct V_12 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
F_9 ( & V_22 -> V_22 , L_2 , V_44 ) ;
V_2 -> V_41 = false ;
F_19 ( V_2 -> V_39 ) ;
F_20 ( & V_2 -> V_30 ) ;
F_16 ( V_2 ) ;
F_21 ( V_2 -> V_45 ) ;
}
static int F_22 ( struct V_12 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int error ;
F_9 ( & V_22 -> V_22 , L_2 , V_44 ) ;
error = F_23 ( V_2 -> V_45 ) ;
if ( error )
return error ;
V_2 -> V_41 = true ;
F_15 ( V_2 ) ;
if ( ( F_2 ( V_2 -> V_8 + V_9 ) & V_2 -> V_11 ) == 0 ) {
F_24 ( & V_22 -> V_22 ,
L_3 ) ;
goto V_46;
}
return 0 ;
V_46:
F_17 ( V_22 ) ;
return - V_47 ;
}
static int F_25 ( struct V_48 * V_49 )
{
const struct V_50 * V_51 = V_49 -> V_22 . V_52 ;
struct V_1 * V_2 ;
struct V_12 * V_12 ;
struct V_53 * V_54 ;
int V_39 , error , V_26 , V_13 , V_4 ;
if ( ! V_51 && ! V_49 -> V_22 . V_55 ) {
F_24 ( & V_49 -> V_22 , L_4 ) ;
return - V_56 ;
}
V_39 = F_26 ( V_49 , 0 ) ;
if ( V_39 < 0 ) {
F_24 ( & V_49 -> V_22 , L_5 ) ;
return - V_56 ;
}
V_12 = F_27 ( & V_49 -> V_22 ) ;
if ( ! V_12 ) {
F_24 ( & V_49 -> V_22 , L_6 ) ;
return - V_57 ;
}
V_2 = F_28 ( & V_49 -> V_22 , sizeof( struct V_1 ) ,
V_58 ) ;
if ( ! V_2 ) {
F_24 ( & V_49 -> V_22 , L_7 ) ;
return - V_57 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_28 = 0 ;
F_29 ( & V_2 -> V_30 ,
F_11 , ( unsigned long ) V_2 ) ;
V_54 = F_30 ( V_49 , V_59 , 0 ) ;
V_2 -> V_8 = F_31 ( & V_49 -> V_22 , V_54 ) ;
if ( F_32 ( V_2 -> V_8 ) )
return F_33 ( V_2 -> V_8 ) ;
V_2 -> V_45 = F_34 ( & V_49 -> V_22 , NULL ) ;
if ( F_32 ( V_2 -> V_45 ) ) {
F_24 ( & V_49 -> V_22 , L_8 ) ;
return F_33 ( V_2 -> V_45 ) ;
}
V_12 -> V_60 = V_49 -> V_60 ;
V_12 -> V_61 . V_62 = V_63 ;
V_12 -> V_22 . V_64 = & V_49 -> V_22 ;
V_12 -> V_65 = F_22 ;
V_12 -> V_66 = F_17 ;
error = F_35 ( V_51 , NULL ,
V_17 ,
V_6 ,
V_2 -> V_21 , V_12 ) ;
if ( error ) {
F_24 ( & V_49 -> V_22 , L_9 ) ;
return error ;
}
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
V_26 = F_6 ( V_13 , V_4 , V_18 ) ;
if ( V_2 -> V_21 [ V_26 ] != V_67 ) {
V_2 -> V_11 |= 1 << V_13 ;
V_2 -> V_7 |= 1 << V_4 ;
}
}
}
F_9 ( & V_49 -> V_22 , L_10 , V_2 -> V_11 ) ;
F_9 ( & V_49 -> V_22 , L_11 , V_2 -> V_7 ) ;
F_36 ( V_68 , V_12 -> V_69 ) ;
F_37 ( V_12 , V_19 , V_20 ) ;
F_38 ( V_12 , V_2 ) ;
F_23 ( V_2 -> V_45 ) ;
F_16 ( V_2 ) ;
F_21 ( V_2 -> V_45 ) ;
error = F_39 ( & V_49 -> V_22 , V_39 , F_14 , 0 ,
V_49 -> V_60 , V_2 ) ;
if ( error ) {
F_24 ( & V_49 -> V_22 , L_12 ) ;
return error ;
}
error = F_40 ( V_12 ) ;
if ( error ) {
F_24 ( & V_49 -> V_22 , L_13 ) ;
return error ;
}
F_41 ( V_49 , V_2 ) ;
F_42 ( & V_49 -> V_22 , 1 ) ;
return 0 ;
}
static int F_43 ( struct V_70 * V_22 )
{
struct V_48 * V_49 = F_44 ( V_22 ) ;
struct V_1 * V_71 = F_45 ( V_49 ) ;
struct V_12 * V_12 = V_71 -> V_12 ;
F_46 ( & V_12 -> V_72 ) ;
if ( V_12 -> V_73 )
F_21 ( V_71 -> V_45 ) ;
F_47 ( & V_12 -> V_72 ) ;
if ( F_48 ( & V_49 -> V_22 ) )
F_49 ( V_71 -> V_39 ) ;
return 0 ;
}
static int F_50 ( struct V_70 * V_22 )
{
struct V_48 * V_49 = F_44 ( V_22 ) ;
struct V_1 * V_71 = F_45 ( V_49 ) ;
struct V_12 * V_12 = V_71 -> V_12 ;
int V_74 = 0 ;
if ( F_48 ( & V_49 -> V_22 ) )
F_51 ( V_71 -> V_39 ) ;
F_46 ( & V_12 -> V_72 ) ;
if ( V_12 -> V_73 ) {
V_74 = F_23 ( V_71 -> V_45 ) ;
if ( V_74 )
goto V_75;
}
V_75:
F_47 ( & V_12 -> V_72 ) ;
return V_74 ;
}
