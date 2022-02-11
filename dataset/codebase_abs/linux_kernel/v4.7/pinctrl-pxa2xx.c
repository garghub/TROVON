static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 + V_6 ;
return V_8 -> V_10 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_6 ,
const unsigned * * V_11 ,
unsigned * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 + V_6 ;
* V_11 = ( unsigned * ) & V_8 -> V_13 ;
* V_12 = 1 ;
return 0 ;
}
static struct V_14 *
F_5 ( struct V_3 * V_4 , const char * V_15 ,
const char * V_16 )
{
int V_17 ;
struct V_14 * V_18 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_19 ; V_17 ++ ) {
const struct V_20 * V_13 = V_4 -> V_21 + V_17 ;
if ( ! strcmp ( V_13 -> V_13 . V_10 , V_15 ) )
for ( V_18 = V_13 -> V_22 ; V_18 -> V_10 ; V_18 ++ )
if ( ! strcmp ( V_18 -> V_10 , V_16 ) )
return V_18 ;
}
return NULL ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
unsigned V_13 ,
bool V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_26 ;
T_1 V_27 ;
void T_2 * V_28 ;
V_28 = V_4 -> V_29 [ V_13 / 32 ] ;
F_7 ( V_4 -> V_30 , L_1 ,
V_13 , ! V_25 ) ;
F_8 ( & V_4 -> V_31 , V_26 ) ;
V_27 = F_9 ( V_28 ) ;
V_27 = ( V_27 & ~ F_10 ( V_13 % 32 ) ) | ( V_25 ? 0 : F_10 ( V_13 % 32 ) ) ;
F_11 ( V_27 , V_28 ) ;
F_12 ( & V_4 -> V_31 , V_26 ) ;
return 0 ;
}
static const char * F_13 ( struct V_1 * V_2 ,
unsigned V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_4 -> V_22 + V_32 ;
return V_34 -> V_10 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_35 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_32 ,
const char * const * * V_9 ,
unsigned * const V_36 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_4 -> V_22 + V_32 ;
* V_9 = V_34 -> V_9 ;
* V_36 = V_34 -> V_5 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_32 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 + V_6 ;
struct V_14 * V_18 ;
int V_13 , V_37 ;
unsigned long V_26 ;
void T_2 * V_38 , * V_28 ;
T_3 V_27 ;
V_18 = F_5 ( V_4 , V_8 -> V_10 ,
( V_4 -> V_22 + V_32 ) -> V_10 ) ;
if ( ! V_18 )
return - V_39 ;
V_13 = V_8 -> V_13 ;
V_38 = V_4 -> V_40 [ V_13 / 16 ] ;
V_28 = V_4 -> V_29 [ V_13 / 32 ] ;
V_37 = ( V_13 % 16 ) << 1 ;
F_7 ( V_4 -> V_30 , L_2 ,
V_13 , V_18 -> V_41 >> 1 , V_18 -> V_41 & 0x1 ) ;
F_8 ( & V_4 -> V_31 , V_26 ) ;
V_27 = F_9 ( V_38 ) ;
V_27 = ( V_27 & ~ ( 0x3 << V_37 ) ) | ( ( V_18 -> V_41 >> 1 ) << V_37 ) ;
F_11 ( V_27 , V_38 ) ;
V_27 = F_9 ( V_28 ) ;
V_27 = ( V_27 & ~ F_10 ( V_13 % 32 ) ) | ( ( V_18 -> V_41 & 1 ) ? F_10 ( V_13 % 32 ) : 0 ) ;
F_11 ( V_27 , V_28 ) ;
F_12 ( & V_4 -> V_31 , V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_8 ,
unsigned long * V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_43 = V_4 -> V_9 + V_8 ;
unsigned long V_26 ;
unsigned V_13 = V_43 -> V_13 ;
void T_2 * V_44 = V_4 -> V_45 [ V_13 / 32 ] ;
T_3 V_27 ;
F_8 ( & V_4 -> V_31 , V_26 ) ;
V_27 = F_9 ( V_44 ) & F_10 ( V_13 % 32 ) ;
* V_42 = V_27 ? V_46 : 0 ;
F_12 ( & V_4 -> V_31 , V_26 ) ;
F_7 ( V_4 -> V_30 , L_3 ,
V_13 , ! ! V_27 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_8 ,
unsigned long * V_47 ,
unsigned V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_43 = V_4 -> V_9 + V_8 ;
unsigned long V_26 ;
unsigned V_13 = V_43 -> V_13 ;
void T_2 * V_44 = V_4 -> V_45 [ V_13 / 32 ] ;
int V_17 , V_49 = 0 ;
T_3 V_27 ;
for ( V_17 = 0 ; V_17 < V_48 ; V_17 ++ ) {
switch ( F_19 ( V_47 [ V_17 ] ) ) {
case V_46 :
V_49 = F_20 ( V_47 [ V_17 ] ) ;
break;
default:
return - V_39 ;
}
}
F_7 ( V_4 -> V_30 , L_4 ,
V_13 , V_49 ) ;
F_8 ( & V_4 -> V_31 , V_26 ) ;
V_27 = F_9 ( V_44 ) ;
V_27 = ( V_27 & ~ F_10 ( V_13 % 32 ) ) | ( V_49 ? F_10 ( V_13 % 32 ) : 0 ) ;
F_11 ( V_27 , V_44 ) ;
F_12 ( & V_4 -> V_31 , V_26 ) ;
return 0 ;
}
static const struct V_33 *
F_21 ( struct V_3 * V_4 , const char * V_50 ,
const struct V_33 * V_22 )
{
const struct V_33 * V_51 ;
for ( V_51 = V_22 ; V_51 -> V_10 ; V_51 ++ )
if ( ! strcmp ( V_50 , V_51 -> V_10 ) )
return V_51 ;
return NULL ;
}
static int F_22 ( struct V_3 * V_4 )
{
int V_17 ;
struct V_33 * V_22 ;
struct V_14 * V_18 ;
V_22 = F_23 ( V_4 -> V_30 , V_4 -> V_19 * 6 ,
sizeof( * V_22 ) , V_52 ) ;
if ( ! V_22 )
return - V_53 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_19 ; V_17 ++ )
for ( V_18 = V_4 -> V_21 [ V_17 ] . V_22 ; V_18 -> V_10 ; V_18 ++ )
if ( ! F_21 ( V_4 , V_18 -> V_10 , V_22 ) )
( V_22 + V_4 -> V_35 ++ ) -> V_10 = V_18 -> V_10 ;
V_4 -> V_22 = F_24 ( V_4 -> V_30 , V_22 ,
V_4 -> V_35 * sizeof( * V_22 ) ,
V_52 ) ;
if ( ! V_4 -> V_22 )
return - V_53 ;
F_25 ( V_4 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 )
{
int V_17 , V_54 , V_5 ;
struct V_33 * V_51 ;
struct V_14 * V_18 ;
char * * V_55 ;
V_55 = F_27 ( V_4 -> V_30 , V_4 -> V_19 , sizeof( * V_55 ) ,
V_52 ) ;
if ( ! V_55 )
return - V_53 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_35 ; V_17 ++ ) {
V_5 = 0 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_19 ; V_54 ++ )
for ( V_18 = V_4 -> V_21 [ V_54 ] . V_22 ; V_18 -> V_10 ;
V_18 ++ )
if ( ! strcmp ( V_4 -> V_22 [ V_17 ] . V_10 ,
V_18 -> V_10 ) )
V_55 [ V_5 ++ ] = ( char * )
V_4 -> V_21 [ V_54 ] . V_13 . V_10 ;
V_51 = V_4 -> V_22 + V_17 ;
V_51 -> V_5 = V_5 ;
V_51 -> V_9 =
F_27 ( V_4 -> V_30 , V_5 ,
sizeof( char * ) , V_52 ) ;
if ( ! V_51 -> V_9 )
return - V_53 ;
memcpy ( V_51 -> V_9 , V_55 , V_5 * sizeof( * V_55 ) ) ;
}
F_25 ( V_4 -> V_30 , V_55 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 ,
const struct V_20 * V_21 , int V_19 )
{
struct V_7 * V_8 ;
struct V_56 * V_11 ;
int V_57 , V_17 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_21 = V_21 ;
V_4 -> V_5 = V_19 ;
V_4 -> V_58 . V_19 = V_19 ;
V_11 = F_23 ( V_4 -> V_30 , V_19 , sizeof( * V_11 ) , V_52 ) ;
if ( ! V_11 )
return - V_53 ;
V_4 -> V_58 . V_11 = V_11 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
V_11 [ V_17 ] = V_21 [ V_17 ] . V_13 ;
V_4 -> V_9 = F_27 ( V_4 -> V_30 , V_4 -> V_5 ,
sizeof( * V_4 -> V_9 ) , V_52 ) ;
if ( ! V_4 -> V_9 )
return - V_53 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
V_8 = V_4 -> V_9 + V_17 ;
V_8 -> V_10 = V_21 [ V_17 ] . V_13 . V_10 ;
V_8 -> V_13 = V_21 [ V_17 ] . V_13 . V_59 ;
}
V_57 = F_22 ( V_4 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_26 ( V_4 ) ;
if ( V_57 )
return V_57 ;
return 0 ;
}
int F_29 ( struct V_60 * V_61 ,
const struct V_20 * V_21 , int V_19 ,
void T_2 * V_40 [] , void T_2 * V_29 [] ,
void T_2 * V_45 [] )
{
struct V_3 * V_4 ;
int V_57 , V_17 , V_62 = 0 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
V_62 = F_30 ( int , V_21 [ V_17 ] . V_13 . V_59 , V_62 ) ;
V_4 = F_31 ( & V_61 -> V_30 , sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_40 = F_23 ( & V_61 -> V_30 , F_32 ( V_62 , 16 ) ,
sizeof( * V_4 -> V_40 ) , V_52 ) ;
V_4 -> V_29 = F_23 ( & V_61 -> V_30 , F_32 ( V_62 , 32 ) ,
sizeof( * V_4 -> V_29 ) , V_52 ) ;
V_4 -> V_45 = F_23 ( & V_61 -> V_30 , F_32 ( V_62 , 32 ) ,
sizeof( * V_4 -> V_45 ) , V_52 ) ;
if ( ! V_4 -> V_40 || ! V_4 -> V_29 || ! V_4 -> V_45 )
return - V_53 ;
F_33 ( V_61 , V_4 ) ;
F_34 ( & V_4 -> V_31 ) ;
V_4 -> V_30 = & V_61 -> V_30 ;
V_4 -> V_58 = V_63 ;
V_4 -> V_58 . V_10 = F_35 ( & V_61 -> V_30 ) ;
V_4 -> V_58 . V_64 = V_65 ;
for ( V_17 = 0 ; V_17 < F_32 ( V_62 , 16 ) ; V_17 += 16 )
V_4 -> V_40 [ V_17 / 16 ] = V_40 [ V_17 / 16 ] ;
for ( V_17 = 0 ; V_17 < F_32 ( V_62 , 32 ) ; V_17 += 32 ) {
V_4 -> V_29 [ V_17 / 32 ] = V_29 [ V_17 / 32 ] ;
V_4 -> V_45 [ V_17 / 32 ] = V_45 [ V_17 / 32 ] ;
}
V_57 = F_28 ( V_4 , V_21 , V_19 ) ;
if ( V_57 )
return V_57 ;
V_4 -> V_66 = F_36 ( & V_61 -> V_30 , & V_4 -> V_58 , V_4 ) ;
if ( F_37 ( V_4 -> V_66 ) ) {
F_38 ( & V_61 -> V_30 , L_5 ) ;
return F_39 ( V_4 -> V_66 ) ;
}
F_40 ( & V_61 -> V_30 , L_6 ) ;
return 0 ;
}
int F_41 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = F_42 ( V_61 ) ;
F_43 ( V_4 -> V_66 ) ;
return 0 ;
}
