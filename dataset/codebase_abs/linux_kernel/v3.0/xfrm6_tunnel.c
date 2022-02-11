static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline unsigned F_3 ( const T_1 * V_4 )
{
unsigned V_5 ;
V_5 = ( V_6 V_7 ) ( V_4 -> V_8 [ 0 ] ^ V_4 -> V_8 [ 1 ] ^ V_4 -> V_8 [ 2 ] ^ V_4 -> V_8 [ 3 ] ) ;
V_5 ^= V_5 >> 16 ;
V_5 ^= V_5 >> 8 ;
V_5 &= V_9 - 1 ;
return V_5 ;
}
static inline unsigned F_4 ( V_7 V_10 )
{
return V_10 % V_11 ;
}
static struct V_12 * F_5 ( struct V_2 * V_2 , const T_1 * V_13 )
{
struct V_1 * V_14 = F_1 ( V_2 ) ;
struct V_12 * V_15 ;
struct V_16 * V_17 ;
F_6 (x6spi, pos,
&xfrm6_tn->spi_byaddr[xfrm6_tunnel_spi_hash_byaddr(saddr)],
list_byaddr) {
if ( memcmp ( & V_15 -> V_4 , V_13 , sizeof( V_15 -> V_4 ) ) == 0 )
return V_15 ;
}
return NULL ;
}
T_2 F_7 ( struct V_2 * V_2 , const T_1 * V_13 )
{
struct V_12 * V_15 ;
V_7 V_10 ;
F_8 () ;
V_15 = F_5 ( V_2 , V_13 ) ;
V_10 = V_15 ? V_15 -> V_10 : 0 ;
F_9 () ;
return F_10 ( V_10 ) ;
}
static int F_11 ( struct V_2 * V_2 , V_7 V_10 )
{
struct V_1 * V_14 = F_1 ( V_2 ) ;
struct V_12 * V_15 ;
int V_18 = F_4 ( V_10 ) ;
struct V_16 * V_17 ;
F_12 (x6spi, pos,
&xfrm6_tn->spi_byspi[index],
list_byspi) {
if ( V_15 -> V_10 == V_10 )
return - 1 ;
}
return V_18 ;
}
static V_7 F_13 ( struct V_2 * V_2 , T_1 * V_13 )
{
struct V_1 * V_14 = F_1 ( V_2 ) ;
V_7 V_10 ;
struct V_12 * V_15 ;
int V_18 ;
if ( V_14 -> V_10 < V_19 ||
V_14 -> V_10 >= V_20 )
V_14 -> V_10 = V_19 ;
else
V_14 -> V_10 ++ ;
for ( V_10 = V_14 -> V_10 ; V_10 <= V_20 ; V_10 ++ ) {
V_18 = F_11 ( V_2 , V_10 ) ;
if ( V_18 >= 0 )
goto V_21;
}
for ( V_10 = V_19 ; V_10 < V_14 -> V_10 ; V_10 ++ ) {
V_18 = F_11 ( V_2 , V_10 ) ;
if ( V_18 >= 0 )
goto V_21;
}
V_10 = 0 ;
goto V_22;
V_21:
V_14 -> V_10 = V_10 ;
V_15 = F_14 ( V_23 , V_24 ) ;
if ( ! V_15 )
goto V_22;
memcpy ( & V_15 -> V_4 , V_13 , sizeof( V_15 -> V_4 ) ) ;
V_15 -> V_10 = V_10 ;
F_15 ( & V_15 -> V_25 , 1 ) ;
F_16 ( & V_15 -> V_26 , & V_14 -> V_27 [ V_18 ] ) ;
V_18 = F_3 ( V_13 ) ;
F_16 ( & V_15 -> V_28 , & V_14 -> V_29 [ V_18 ] ) ;
V_22:
return V_10 ;
}
T_2 F_17 ( struct V_2 * V_2 , T_1 * V_13 )
{
struct V_12 * V_15 ;
V_7 V_10 ;
F_18 ( & V_30 ) ;
V_15 = F_5 ( V_2 , V_13 ) ;
if ( V_15 ) {
F_19 ( & V_15 -> V_25 ) ;
V_10 = V_15 -> V_10 ;
} else
V_10 = F_13 ( V_2 , V_13 ) ;
F_20 ( & V_30 ) ;
return F_10 ( V_10 ) ;
}
static void F_21 ( struct V_31 * V_32 )
{
F_22 ( V_23 ,
F_23 ( V_32 , struct V_12 , V_31 ) ) ;
}
static void F_24 ( struct V_2 * V_2 , T_1 * V_13 )
{
struct V_1 * V_14 = F_1 ( V_2 ) ;
struct V_12 * V_15 ;
struct V_16 * V_17 , * V_33 ;
F_18 ( & V_30 ) ;
F_25 (x6spi, pos, n,
&xfrm6_tn->spi_byaddr[xfrm6_tunnel_spi_hash_byaddr(saddr)],
list_byaddr)
{
if ( memcmp ( & V_15 -> V_4 , V_13 , sizeof( V_15 -> V_4 ) ) == 0 ) {
if ( F_26 ( & V_15 -> V_25 ) ) {
F_27 ( & V_15 -> V_28 ) ;
F_27 ( & V_15 -> V_26 ) ;
F_28 ( & V_15 -> V_31 , F_21 ) ;
break;
}
}
}
F_20 ( & V_30 ) ;
}
static int F_29 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
F_30 ( V_37 , - F_31 ( V_37 ) ) ;
return 0 ;
}
static int F_32 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
return F_33 ( V_37 ) [ F_34 ( V_37 ) -> V_38 ] ;
}
static int F_35 ( struct V_36 * V_37 )
{
struct V_2 * V_2 = F_36 ( V_37 -> V_39 ) ;
const struct V_40 * V_41 = F_37 ( V_37 ) ;
T_2 V_10 ;
V_10 = F_7 ( V_2 , ( const T_1 * ) & V_41 -> V_13 ) ;
return F_38 ( V_37 , V_42 , V_10 ) ;
}
static int F_39 ( struct V_36 * V_37 , struct V_43 * V_44 ,
T_3 type , T_3 V_45 , int V_46 , T_2 V_47 )
{
switch ( type ) {
case V_48 :
switch ( V_45 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
default:
break;
}
break;
case V_54 :
break;
case V_55 :
switch ( V_45 ) {
case V_56 :
break;
case V_57 :
default:
break;
}
break;
case V_58 :
switch ( V_45 ) {
case V_59 : break;
case V_60 : break;
case V_61 : break;
}
break;
default:
break;
}
return 0 ;
}
static int F_40 ( struct V_34 * V_35 )
{
if ( V_35 -> V_62 . V_63 != V_64 )
return - V_65 ;
if ( V_35 -> V_66 )
return - V_65 ;
V_35 -> V_62 . V_67 = sizeof( struct V_40 ) ;
return 0 ;
}
static void F_41 ( struct V_34 * V_35 )
{
struct V_2 * V_2 = F_42 ( V_35 ) ;
F_24 ( V_2 , ( T_1 * ) & V_35 -> V_62 . V_13 ) ;
}
static int T_4 F_43 ( struct V_2 * V_2 )
{
struct V_1 * V_14 = F_1 ( V_2 ) ;
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_9 ; V_68 ++ )
F_44 ( & V_14 -> V_29 [ V_68 ] ) ;
for ( V_68 = 0 ; V_68 < V_11 ; V_68 ++ )
F_44 ( & V_14 -> V_27 [ V_68 ] ) ;
V_14 -> V_10 = 0 ;
return 0 ;
}
static void T_5 F_45 ( struct V_2 * V_2 )
{
}
static int T_6 F_46 ( void )
{
int V_69 ;
V_23 = F_47 ( L_1 ,
sizeof( struct V_12 ) ,
0 , V_70 ,
NULL ) ;
if ( ! V_23 )
return - V_71 ;
V_69 = F_48 ( & V_72 ) ;
if ( V_69 < 0 )
goto V_73;
V_69 = F_49 ( & V_74 , V_75 ) ;
if ( V_69 < 0 )
goto V_76;
V_69 = F_50 ( & V_77 , V_75 ) ;
if ( V_69 < 0 )
goto V_78;
V_69 = F_50 ( & V_79 , V_80 ) ;
if ( V_69 < 0 )
goto V_81;
return 0 ;
V_81:
F_51 ( & V_77 , V_75 ) ;
V_78:
F_52 ( & V_74 , V_75 ) ;
V_76:
F_53 ( & V_72 ) ;
V_73:
F_54 ( V_23 ) ;
return V_69 ;
}
static void T_7 F_55 ( void )
{
F_51 ( & V_79 , V_80 ) ;
F_51 ( & V_77 , V_75 ) ;
F_52 ( & V_74 , V_75 ) ;
F_53 ( & V_72 ) ;
F_54 ( V_23 ) ;
}
