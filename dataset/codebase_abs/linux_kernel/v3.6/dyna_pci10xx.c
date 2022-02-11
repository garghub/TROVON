static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 , V_9 ;
T_1 V_10 = 0 ;
unsigned int V_11 , V_12 ;
V_11 = F_2 ( V_6 -> V_13 ) ;
V_12 = V_14 -> V_15 [ F_3 ( ( V_6 -> V_13 ) ) ] ;
F_4 ( & V_16 -> V_17 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_5 () ;
F_6 ( 0x0000 + V_12 + V_11 , V_2 -> V_18 + 2 ) ;
F_7 ( 10 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_10 = F_8 ( V_2 -> V_18 ) ;
if ( V_10 & ( 1 << 15 ) )
goto V_20;
}
V_7 [ V_8 ] = 0 ;
F_9 ( V_21 L_1
L_2 ) ;
continue;
V_20:
V_10 &= 0x0FFF ;
V_7 [ V_8 ] = V_10 ;
}
F_10 ( & V_16 -> V_17 ) ;
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
unsigned int V_11 , V_12 ;
V_11 = F_2 ( V_6 -> V_13 ) ;
V_12 = V_14 -> V_15 [ F_3 ( ( V_6 -> V_13 ) ) ] ;
F_4 ( & V_16 -> V_17 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_5 () ;
F_6 ( V_7 [ V_8 ] , V_2 -> V_18 ) ;
F_7 ( 10 ) ;
}
F_10 ( & V_16 -> V_17 ) ;
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
T_1 V_10 = 0 ;
F_4 ( & V_16 -> V_17 ) ;
F_5 () ;
V_10 = F_8 ( V_16 -> V_22 ) ;
F_7 ( 10 ) ;
V_7 [ 1 ] = V_10 ;
V_7 [ 0 ] = V_4 -> V_23 ;
F_10 ( & V_16 -> V_17 ) ;
return V_6 -> V_8 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
F_4 ( & V_16 -> V_17 ) ;
if ( V_7 [ 0 ] ) {
V_4 -> V_23 &= ~ V_7 [ 0 ] ;
V_4 -> V_23 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_5 () ;
F_6 ( V_4 -> V_23 , V_16 -> V_22 ) ;
F_7 ( 10 ) ;
}
V_7 [ 1 ] = V_4 -> V_23 ;
F_10 ( & V_16 -> V_17 ) ;
return V_6 -> V_8 ;
}
static struct V_24 * F_14 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_24 * V_27 = NULL ;
int V_28 = V_26 -> V_29 [ 0 ] ;
int V_30 = V_26 -> V_29 [ 1 ] ;
int V_31 ;
F_15 (pcidev) {
if ( V_28 || V_30 ) {
if ( V_28 != V_27 -> V_28 -> V_32 ||
V_30 != F_16 ( V_27 -> V_33 ) )
continue;
}
if ( V_27 -> V_34 != V_35 )
continue;
for ( V_31 = 0 ; V_31 < F_17 ( V_36 ) ; ++ V_31 ) {
if ( V_27 -> V_37 != V_36 [ V_31 ] . V_38 )
continue;
V_2 -> V_39 = & V_36 [ V_31 ] ;
return V_27 ;
}
}
F_18 ( V_2 -> V_40 ,
L_3 ,
V_28 , V_30 ) ;
return NULL ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_24 * V_27 ;
struct V_3 * V_4 ;
int V_41 ;
if ( F_20 ( V_2 , sizeof( struct V_42 ) ) < 0 ) {
F_9 ( V_43 L_1
L_4 ) ;
return - V_44 ;
}
V_27 = F_14 ( V_2 , V_26 ) ;
if ( ! V_27 )
return - V_45 ;
F_21 ( V_2 , & V_27 -> V_2 ) ;
V_2 -> V_46 = V_14 -> V_47 ;
V_2 -> V_48 = 0 ;
if ( F_22 ( V_27 , V_49 ) ) {
F_9 ( V_43 L_1
L_5 ) ;
return - V_45 ;
}
F_23 ( & V_16 -> V_17 ) ;
F_9 ( V_50 L_6 ) ;
V_2 -> V_18 = F_24 ( V_27 , 2 ) ;
V_16 -> V_22 = F_24 ( V_27 , 3 ) ;
V_41 = F_25 ( V_2 , 4 ) ;
if ( V_41 )
return V_41 ;
V_4 = V_2 -> V_51 + 0 ;
V_4 -> type = V_52 ;
V_4 -> V_53 = V_54 | V_55 | V_56 ;
V_4 -> V_57 = V_14 -> V_58 ;
V_4 -> V_59 = 0x0FFF ;
V_4 -> V_60 = V_14 -> V_61 ;
V_4 -> V_62 = 16 ;
V_4 -> V_63 = F_1 ;
V_4 = V_2 -> V_51 + 1 ;
V_4 -> type = V_64 ;
V_4 -> V_53 = V_65 ;
V_4 -> V_57 = V_14 -> V_66 ;
V_4 -> V_59 = 0x0FFF ;
V_4 -> V_60 = V_14 -> V_67 ;
V_4 -> V_62 = 16 ;
V_4 -> V_68 = F_11 ;
V_4 = V_2 -> V_51 + 2 ;
V_4 -> type = V_69 ;
V_4 -> V_53 = V_54 | V_55 ;
V_4 -> V_57 = V_14 -> V_70 ;
V_4 -> V_59 = 1 ;
V_4 -> V_60 = & V_71 ;
V_4 -> V_62 = V_14 -> V_70 ;
V_4 -> V_72 = F_12 ;
V_4 = V_2 -> V_51 + 3 ;
V_4 -> type = V_73 ;
V_4 -> V_53 = V_65 | V_55 ;
V_4 -> V_57 = V_14 -> V_74 ;
V_4 -> V_59 = 1 ;
V_4 -> V_60 = & V_71 ;
V_4 -> V_62 = V_14 -> V_74 ;
V_4 -> V_23 = 0 ;
V_4 -> V_72 = F_13 ;
F_9 ( V_50 L_7 ,
V_14 -> V_47 ) ;
return 1 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_24 * V_27 = F_27 ( V_2 ) ;
if ( V_16 )
F_28 ( & V_16 -> V_17 ) ;
if ( V_27 ) {
if ( V_2 -> V_18 )
F_29 ( V_27 ) ;
F_30 ( V_27 ) ;
}
}
static int T_2 F_31 ( struct V_24 * V_2 ,
const struct V_75 * V_76 )
{
return F_32 ( V_2 , & V_77 ) ;
}
static void T_3 F_33 ( struct V_24 * V_2 )
{
F_34 ( V_2 ) ;
}
