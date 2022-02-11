static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline unsigned int F_3 ( const T_1 * V_4 )
{
unsigned int V_5 ;
V_5 = F_4 ( ( const struct V_6 * ) V_4 ) ;
V_5 ^= V_5 >> 16 ;
V_5 ^= V_5 >> 8 ;
V_5 &= V_7 - 1 ;
return V_5 ;
}
static inline unsigned int F_5 ( T_2 V_8 )
{
return V_8 % V_9 ;
}
static struct V_10 * F_6 ( struct V_2 * V_2 , const T_1 * V_11 )
{
struct V_1 * V_12 = F_1 ( V_2 ) ;
struct V_10 * V_13 ;
F_7 (x6spi,
&xfrm6_tn->spi_byaddr[xfrm6_tunnel_spi_hash_byaddr(saddr)],
list_byaddr) {
if ( F_8 ( & V_13 -> V_4 , V_11 ) )
return V_13 ;
}
return NULL ;
}
T_3 F_9 ( struct V_2 * V_2 , const T_1 * V_11 )
{
struct V_10 * V_13 ;
T_2 V_8 ;
F_10 () ;
V_13 = F_6 ( V_2 , V_11 ) ;
V_8 = V_13 ? V_13 -> V_8 : 0 ;
F_11 () ;
return F_12 ( V_8 ) ;
}
static int F_13 ( struct V_2 * V_2 , T_2 V_8 )
{
struct V_1 * V_12 = F_1 ( V_2 ) ;
struct V_10 * V_13 ;
int V_14 = F_5 ( V_8 ) ;
F_14 (x6spi,
&xfrm6_tn->spi_byspi[index],
list_byspi) {
if ( V_13 -> V_8 == V_8 )
return - 1 ;
}
return V_14 ;
}
static T_2 F_15 ( struct V_2 * V_2 , T_1 * V_11 )
{
struct V_1 * V_12 = F_1 ( V_2 ) ;
T_2 V_8 ;
struct V_10 * V_13 ;
int V_14 ;
if ( V_12 -> V_8 < V_15 ||
V_12 -> V_8 >= V_16 )
V_12 -> V_8 = V_15 ;
else
V_12 -> V_8 ++ ;
for ( V_8 = V_12 -> V_8 ; V_8 <= V_16 ; V_8 ++ ) {
V_14 = F_13 ( V_2 , V_8 ) ;
if ( V_14 >= 0 )
goto V_17;
}
for ( V_8 = V_15 ; V_8 < V_12 -> V_8 ; V_8 ++ ) {
V_14 = F_13 ( V_2 , V_8 ) ;
if ( V_14 >= 0 )
goto V_17;
}
V_8 = 0 ;
goto V_18;
V_17:
V_12 -> V_8 = V_8 ;
V_13 = F_16 ( V_19 , V_20 ) ;
if ( ! V_13 )
goto V_18;
memcpy ( & V_13 -> V_4 , V_11 , sizeof( V_13 -> V_4 ) ) ;
V_13 -> V_8 = V_8 ;
F_17 ( & V_13 -> V_21 , 1 ) ;
F_18 ( & V_13 -> V_22 , & V_12 -> V_23 [ V_14 ] ) ;
V_14 = F_3 ( V_11 ) ;
F_18 ( & V_13 -> V_24 , & V_12 -> V_25 [ V_14 ] ) ;
V_18:
return V_8 ;
}
T_3 F_19 ( struct V_2 * V_2 , T_1 * V_11 )
{
struct V_10 * V_13 ;
T_2 V_8 ;
F_20 ( & V_26 ) ;
V_13 = F_6 ( V_2 , V_11 ) ;
if ( V_13 ) {
F_21 ( & V_13 -> V_21 ) ;
V_8 = V_13 -> V_8 ;
} else
V_8 = F_15 ( V_2 , V_11 ) ;
F_22 ( & V_26 ) ;
return F_12 ( V_8 ) ;
}
static void F_23 ( struct V_27 * V_28 )
{
F_24 ( V_19 ,
F_25 ( V_28 , struct V_10 , V_27 ) ) ;
}
static void F_26 ( struct V_2 * V_2 , T_1 * V_11 )
{
struct V_1 * V_12 = F_1 ( V_2 ) ;
struct V_10 * V_13 ;
struct V_29 * V_30 ;
F_20 ( & V_26 ) ;
F_27 (x6spi, n,
&xfrm6_tn->spi_byaddr[xfrm6_tunnel_spi_hash_byaddr(saddr)],
list_byaddr)
{
if ( F_8 ( & V_13 -> V_4 , V_11 ) ) {
if ( F_28 ( & V_13 -> V_21 ) ) {
F_29 ( & V_13 -> V_24 ) ;
F_29 ( & V_13 -> V_22 ) ;
F_30 ( & V_13 -> V_27 , F_23 ) ;
break;
}
}
}
F_22 ( & V_26 ) ;
}
static int F_31 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
F_32 ( V_34 , - F_33 ( V_34 ) ) ;
return 0 ;
}
static int F_34 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
return F_35 ( V_34 ) [ F_36 ( V_34 ) -> V_35 ] ;
}
static int F_37 ( struct V_33 * V_34 )
{
struct V_2 * V_2 = F_38 ( V_34 -> V_36 ) ;
const struct V_37 * V_38 = F_39 ( V_34 ) ;
T_3 V_8 ;
V_8 = F_9 ( V_2 , ( const T_1 * ) & V_38 -> V_11 ) ;
return F_40 ( V_34 , V_39 , V_8 ) ;
}
static int F_41 ( struct V_33 * V_34 , struct V_40 * V_41 ,
T_4 type , T_4 V_42 , int V_43 , T_3 V_44 )
{
switch ( type ) {
case V_45 :
switch ( V_42 ) {
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
default:
break;
}
break;
case V_51 :
break;
case V_52 :
switch ( V_42 ) {
case V_53 :
break;
case V_54 :
default:
break;
}
break;
case V_55 :
switch ( V_42 ) {
case V_56 : break;
case V_57 : break;
case V_58 : break;
}
break;
default:
break;
}
return 0 ;
}
static int F_42 ( struct V_31 * V_32 )
{
if ( V_32 -> V_59 . V_60 != V_61 )
return - V_62 ;
if ( V_32 -> V_63 )
return - V_62 ;
V_32 -> V_59 . V_64 = sizeof( struct V_37 ) ;
return 0 ;
}
static void F_43 ( struct V_31 * V_32 )
{
struct V_2 * V_2 = F_44 ( V_32 ) ;
F_26 ( V_2 , ( T_1 * ) & V_32 -> V_59 . V_11 ) ;
}
static int T_5 F_45 ( struct V_2 * V_2 )
{
struct V_1 * V_12 = F_1 ( V_2 ) ;
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_7 ; V_65 ++ )
F_46 ( & V_12 -> V_25 [ V_65 ] ) ;
for ( V_65 = 0 ; V_65 < V_9 ; V_65 ++ )
F_46 ( & V_12 -> V_23 [ V_65 ] ) ;
V_12 -> V_8 = 0 ;
return 0 ;
}
static void T_6 F_47 ( struct V_2 * V_2 )
{
}
static int T_7 F_48 ( void )
{
int V_66 ;
V_19 = F_49 ( L_1 ,
sizeof( struct V_10 ) ,
0 , V_67 ,
NULL ) ;
if ( ! V_19 )
return - V_68 ;
V_66 = F_50 ( & V_69 ) ;
if ( V_66 < 0 )
goto V_70;
V_66 = F_51 ( & V_71 , V_72 ) ;
if ( V_66 < 0 )
goto V_73;
V_66 = F_52 ( & V_74 , V_72 ) ;
if ( V_66 < 0 )
goto V_75;
V_66 = F_52 ( & V_76 , V_77 ) ;
if ( V_66 < 0 )
goto V_78;
return 0 ;
V_78:
F_53 ( & V_74 , V_72 ) ;
V_75:
F_54 ( & V_71 , V_72 ) ;
V_73:
F_55 ( & V_69 ) ;
V_70:
F_56 ( V_19 ) ;
return V_66 ;
}
static void T_8 F_57 ( void )
{
F_53 ( & V_76 , V_77 ) ;
F_53 ( & V_74 , V_72 ) ;
F_54 ( & V_71 , V_72 ) ;
F_55 ( & V_69 ) ;
F_56 ( V_19 ) ;
}
