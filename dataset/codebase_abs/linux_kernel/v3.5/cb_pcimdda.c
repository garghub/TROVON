static inline unsigned int F_1 ( int V_1 )
{
return ( ( unsigned int ) 1 << V_1 ) - 1 ;
}
static int F_2 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
if ( F_3 ( V_3 , sizeof( struct V_9 ) ) < 0 )
return - V_10 ;
V_8 = F_4 ( V_3 , V_5 ) ;
if ( V_8 )
return V_8 ;
F_5 ( L_1 , V_3 -> V_11 , V_12 -> V_13 ) ;
V_3 -> V_14 = V_12 -> V_13 ;
if ( F_6 ( V_3 , 2 ) < 0 )
return - V_10 ;
V_7 = V_3 -> V_15 + 0 ;
V_7 -> type = V_16 ;
V_7 -> V_17 = V_18 | V_19 ;
V_7 -> V_20 = V_12 -> V_21 ;
V_7 -> V_22 = F_1 ( V_12 -> V_23 ) ;
if ( V_5 -> V_24 [ 2 ] )
V_7 -> V_25 = & V_26 ;
else
V_7 -> V_25 = & V_27 ;
V_7 -> V_28 = & V_29 ;
V_7 -> V_30 = & V_31 ;
V_7 = V_3 -> V_15 + 1 ;
if ( V_12 -> V_32 ) {
switch ( V_12 -> V_33 ) {
case V_34 :
F_7 ( V_3 , V_7 , NULL , V_35 -> V_36 ) ;
V_35 -> V_37 = 1 ;
break;
case V_38 :
default:
F_5 ( L_2 ) ;
return - V_39 ;
break;
}
} else {
V_7 -> type = V_40 ;
}
F_5 ( L_3 ) ;
return 1 ;
}
static void F_8 ( struct V_2 * V_3 )
{
if ( V_35 ) {
if ( V_3 -> V_15 && V_35 -> V_37 ) {
F_9 ( V_3 , V_3 -> V_15 + 2 ) ;
V_35 -> V_37 = 0 ;
}
if ( V_35 -> V_41 ) {
if ( V_35 -> V_42 )
F_10 ( V_35 -> V_41 ) ;
F_11 ( V_35 -> V_41 ) ;
}
}
}
static int V_29 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_43 * V_44 , unsigned int * V_45 )
{
int V_46 ;
int V_47 = F_12 ( V_44 -> V_48 ) ;
unsigned long V_49 = V_35 -> V_42 + V_47 * 2 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_50 ; V_46 ++ ) {
F_13 ( ( char ) ( V_45 [ V_46 ] & 0x00ff ) , V_49 ) ;
F_13 ( ( char ) ( V_45 [ V_46 ] >> 8 & 0x00ff ) , V_49 + 1 ) ;
V_35 -> V_51 [ V_47 ] = V_45 [ V_46 ] ;
}
return V_46 ;
}
static int V_31 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_43 * V_44 , unsigned int * V_45 )
{
int V_46 ;
int V_47 = F_12 ( V_44 -> V_48 ) ;
for ( V_46 = 0 ; V_46 < V_44 -> V_50 ; V_46 ++ ) {
F_14 ( V_35 -> V_42 + V_47 * 2 ) ;
V_45 [ V_46 ] = V_35 -> V_51 [ V_47 ] ;
}
return V_46 ;
}
static int F_4 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
struct V_41 * V_52 = NULL ;
int V_53 ;
unsigned long V_42 ;
F_15 (pcidev) {
if ( V_52 -> V_54 != V_55 )
continue;
for ( V_53 = 0 ; V_53 < F_16 ( V_56 ) ; V_53 ++ ) {
if ( V_56 [ V_53 ] . V_57 != V_52 -> V_58 )
continue;
if ( V_5 -> V_24 [ 0 ] || V_5 -> V_24 [ 1 ] ) {
if ( V_52 -> V_59 -> V_60 != V_5 -> V_24 [ 0 ] ||
F_17 ( V_52 -> V_61 ) != V_5 -> V_24 [ 1 ] ) {
continue;
}
}
V_35 -> V_41 = V_52 ;
V_3 -> V_62 = V_56 + V_53 ;
if ( F_18 ( V_52 , V_12 -> V_13 ) ) {
F_5
( L_4 ) ;
return - V_63 ;
}
V_42 =
F_19 ( V_35 -> V_41 ,
V_64 ) ;
V_35 -> V_42 = V_42 ;
V_35 -> V_36
= V_35 -> V_42 + V_12 -> V_65 ;
return 0 ;
}
}
F_5 ( L_5
L_6 ) ;
return - V_66 ;
}
static int T_1 F_20 ( struct V_41 * V_3 ,
const struct V_67 * V_68 )
{
return F_21 ( V_3 , & V_69 ) ;
}
static void T_2 F_22 ( struct V_41 * V_3 )
{
F_23 ( V_3 ) ;
}
