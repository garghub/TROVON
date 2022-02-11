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
F_6 ( 0x0000 + V_12 + V_11 , V_16 -> V_18 + 2 ) ;
F_7 ( 10 ) ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_10 = F_8 ( V_16 -> V_18 ) ;
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
F_6 ( V_7 [ V_8 ] , V_16 -> V_18 ) ;
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
if ( V_6 -> V_8 != 2 )
return - V_22 ;
F_4 ( & V_16 -> V_17 ) ;
F_5 () ;
V_10 = F_8 ( V_16 -> V_23 ) ;
F_7 ( 10 ) ;
V_7 [ 1 ] = V_10 ;
V_7 [ 0 ] = V_4 -> V_24 ;
F_10 ( & V_16 -> V_17 ) ;
return 2 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_22 ;
F_4 ( & V_16 -> V_17 ) ;
if ( V_7 [ 0 ] ) {
V_4 -> V_24 &= ~ V_7 [ 0 ] ;
V_4 -> V_24 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_5 () ;
F_6 ( V_4 -> V_24 , V_16 -> V_23 ) ;
F_7 ( 10 ) ;
}
V_7 [ 1 ] = V_4 -> V_24 ;
F_10 ( & V_16 -> V_17 ) ;
return 2 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 ;
struct V_27 * V_28 ;
unsigned int V_29 , V_30 ;
int V_31 , V_32 ;
F_4 ( & V_33 ) ;
if ( F_15 ( V_2 , sizeof( struct V_34 ) ) < 0 ) {
F_9 ( V_35 L_1
L_3 ) ;
F_10 ( & V_33 ) ;
return - V_36 ;
}
V_29 = V_26 -> V_37 [ 0 ] ;
V_30 = V_26 -> V_37 [ 1 ] ;
V_2 -> V_38 = V_14 -> V_39 ;
V_2 -> V_40 = 0 ;
for ( V_28 = F_16 ( V_41 , V_41 , NULL ) ;
V_28 != NULL ;
V_28 = F_16 ( V_41 , V_41 , V_28 ) ) {
V_31 = - 1 ;
for ( V_32 = 0 ; V_32 < F_17 ( V_42 ) ; ++ V_32 ) {
if ( ( V_28 -> V_43 == V_44 ) &&
( V_28 -> V_45 == V_42 [ V_32 ] . V_46 ) ) {
V_31 = V_32 ;
break;
}
}
if ( V_31 < 0 )
continue;
if ( V_29 || V_30 ) {
if ( V_29 != V_28 -> V_47 -> V_48
|| V_30 != F_18 ( V_28 -> V_49 ) )
continue;
}
goto V_50;
}
F_9 ( V_35 L_4 ) ;
F_10 ( & V_33 ) ;
return - V_51 ;
V_50:
if ( ! V_28 ) {
if ( V_29 || V_30 ) {
F_9 ( V_35 L_1
L_5 ,
V_29 , V_30 ) ;
} else {
F_9 ( V_35 L_1
L_6 ) ;
}
F_10 ( & V_33 ) ;
return - V_51 ;
}
if ( F_19 ( V_28 , V_52 ) ) {
F_9 ( V_35 L_1
L_7 ) ;
F_10 ( & V_33 ) ;
return - V_51 ;
}
F_20 ( & V_16 -> V_17 ) ;
V_2 -> V_53 = & V_42 [ V_31 ] ;
V_16 -> V_27 = V_28 ;
F_9 ( V_54 L_8 ) ;
V_16 -> V_55 = F_21 ( V_28 , 0 ) ;
V_16 -> V_56 = F_21 ( V_28 , 1 ) ;
V_16 -> V_18 = F_21 ( V_28 , 2 ) ;
V_16 -> V_23 = F_21 ( V_28 , 3 ) ;
V_16 -> V_57 = F_21 ( V_28 , 4 ) ;
V_16 -> V_58 = F_21 ( V_28 , 5 ) ;
if ( F_22 ( V_2 , 4 ) < 0 ) {
F_9 ( V_35 L_1
L_9 ) ;
F_10 ( & V_33 ) ;
return - V_36 ;
}
V_4 = V_2 -> V_59 + 0 ;
V_4 -> type = V_60 ;
V_4 -> V_61 = V_62 | V_63 | V_64 ;
V_4 -> V_65 = V_14 -> V_66 ;
V_4 -> V_67 = 0x0FFF ;
V_4 -> V_68 = V_14 -> V_69 ;
V_4 -> V_70 = 16 ;
V_4 -> V_71 = F_1 ;
V_4 = V_2 -> V_59 + 1 ;
V_4 -> type = V_72 ;
V_4 -> V_61 = V_73 ;
V_4 -> V_65 = V_14 -> V_74 ;
V_4 -> V_67 = 0x0FFF ;
V_4 -> V_68 = V_14 -> V_75 ;
V_4 -> V_70 = 16 ;
V_4 -> V_76 = F_11 ;
V_4 = V_2 -> V_59 + 2 ;
V_4 -> type = V_77 ;
V_4 -> V_61 = V_62 | V_63 ;
V_4 -> V_65 = V_14 -> V_78 ;
V_4 -> V_67 = 1 ;
V_4 -> V_68 = & V_79 ;
V_4 -> V_70 = V_14 -> V_78 ;
V_4 -> V_80 = F_12 ;
V_4 = V_2 -> V_59 + 3 ;
V_4 -> type = V_81 ;
V_4 -> V_61 = V_73 | V_63 ;
V_4 -> V_65 = V_14 -> V_82 ;
V_4 -> V_67 = 1 ;
V_4 -> V_68 = & V_79 ;
V_4 -> V_70 = V_14 -> V_82 ;
V_4 -> V_24 = 0 ;
V_4 -> V_80 = F_13 ;
V_16 -> V_83 = 1 ;
F_10 ( & V_33 ) ;
F_9 ( V_54 L_10 ,
V_42 [ V_31 ] . V_39 ) ;
return 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_16 && V_16 -> V_27 ) {
F_24 ( V_16 -> V_27 ) ;
F_25 ( & V_16 -> V_17 ) ;
}
}
static int T_2 F_26 ( struct V_27 * V_2 ,
const struct V_84 * V_85 )
{
return F_27 ( V_2 , & V_86 ) ;
}
static void T_3 F_28 ( struct V_27 * V_2 )
{
F_29 ( V_2 ) ;
}
