static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3
* V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 =
( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static inline unsigned int F_11 ( int V_10 )
{
return ( ( unsigned int ) 1 << V_10 ) - 1 ;
}
static int F_12 ( struct V_11 * V_2 , struct V_12 * V_13 )
{
struct V_14 * V_15 ;
int V_16 ;
if ( F_13 ( V_2 , sizeof( struct V_17 ) ) < 0 )
return - V_18 ;
V_16 = F_14 ( V_2 , V_13 ) ;
if ( V_16 )
return V_16 ;
F_15 ( L_1 , V_2 -> V_19 , V_20 -> V_9 ) ;
V_2 -> V_21 = V_20 -> V_9 ;
if ( F_16 ( V_2 , 2 ) < 0 )
return - V_18 ;
V_15 = V_2 -> V_22 + 0 ;
V_15 -> type = V_23 ;
V_15 -> V_24 = V_25 | V_26 ;
V_15 -> V_27 = V_20 -> V_28 ;
V_15 -> V_29 = F_11 ( V_20 -> V_30 ) ;
if ( V_13 -> V_31 [ 2 ] )
V_15 -> V_32 = & V_33 ;
else
V_15 -> V_32 = & V_34 ;
V_15 -> V_35 = & V_36 ;
V_15 -> V_37 = & V_38 ;
V_15 = V_2 -> V_22 + 1 ;
if ( V_20 -> V_39 ) {
switch ( V_20 -> V_40 ) {
case V_41 :
F_17 ( V_2 , V_15 , NULL , V_42 -> V_43 ) ;
V_42 -> V_44 = 1 ;
break;
case V_45 :
default:
F_15 ( L_2 ) ;
return - V_46 ;
break;
}
} else {
V_15 -> type = V_47 ;
}
V_42 -> V_48 = 1 ;
F_15 ( L_3 ) ;
return 1 ;
}
static int F_18 ( struct V_11 * V_2 )
{
if ( V_42 ) {
if ( V_2 -> V_22 && V_42 -> V_44 ) {
F_19 ( V_2 , V_2 -> V_22 + 2 ) ;
V_42 -> V_44 = 0 ;
}
if ( V_42 -> V_1 ) {
if ( V_42 -> V_49 )
F_20 ( V_42 -> V_1 ) ;
F_21 ( V_42 -> V_1 ) ;
}
if ( V_42 -> V_48 && V_20 )
F_15 ( L_4 , V_2 -> V_19 ,
V_20 -> V_9 ) ;
}
return 0 ;
}
static int V_36 ( struct V_11 * V_2 , struct V_14 * V_15 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
int V_53 ;
int V_54 = F_22 ( V_51 -> V_55 ) ;
unsigned long V_56 = V_42 -> V_49 + V_54 * 2 ;
for ( V_53 = 0 ; V_53 < V_51 -> V_57 ; V_53 ++ ) {
F_23 ( ( char ) ( V_52 [ V_53 ] & 0x00ff ) , V_56 ) ;
F_23 ( ( char ) ( V_52 [ V_53 ] >> 8 & 0x00ff ) , V_56 + 1 ) ;
V_42 -> V_58 [ V_54 ] = V_52 [ V_53 ] ;
}
return V_53 ;
}
static int V_38 ( struct V_11 * V_2 , struct V_14 * V_15 ,
struct V_50 * V_51 , unsigned int * V_52 )
{
int V_53 ;
int V_54 = F_22 ( V_51 -> V_55 ) ;
for ( V_53 = 0 ; V_53 < V_51 -> V_57 ; V_53 ++ ) {
F_24 ( V_42 -> V_49 + V_54 * 2 ) ;
V_52 [ V_53 ] = V_42 -> V_58 [ V_54 ] ;
}
return V_53 ;
}
static int F_14 ( struct V_11 * V_2 , const struct V_12 * V_13 )
{
struct V_1 * V_59 = NULL ;
int V_60 ;
unsigned long V_49 ;
F_25 (pcidev) {
if ( V_59 -> V_61 != V_62 )
continue;
for ( V_60 = 0 ; V_60 < F_26 ( V_63 ) ; V_60 ++ ) {
if ( V_63 [ V_60 ] . V_64 != V_59 -> V_65 )
continue;
if ( V_13 -> V_31 [ 0 ] || V_13 -> V_31 [ 1 ] ) {
if ( V_59 -> V_66 -> V_67 != V_13 -> V_31 [ 0 ] ||
F_27 ( V_59 -> V_68 ) != V_13 -> V_31 [ 1 ] ) {
continue;
}
}
V_42 -> V_1 = V_59 ;
V_2 -> V_69 = V_63 + V_60 ;
if ( F_28 ( V_59 , V_20 -> V_9 ) ) {
F_15
( L_5 ) ;
return - V_70 ;
}
V_49 =
F_29 ( V_42 -> V_1 ,
V_71 ) ;
V_42 -> V_49 = V_49 ;
V_42 -> V_43
= V_42 -> V_49 + V_20 -> V_72 ;
return 0 ;
}
}
F_15 ( L_6
L_7 ) ;
return - V_73 ;
}
