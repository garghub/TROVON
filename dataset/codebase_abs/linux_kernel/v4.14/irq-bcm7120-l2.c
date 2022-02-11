static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_9 ;
F_4 ( V_8 , V_2 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_10 ; V_9 ++ ) {
int V_11 = V_9 * V_12 ;
struct V_13 * V_14 =
F_5 ( V_6 -> V_15 , V_11 ) ;
unsigned long V_16 ;
int V_17 ;
F_6 ( V_14 ) ;
V_16 = F_7 ( V_14 , V_6 -> V_18 [ V_9 ] ) &
V_14 -> V_19 &
V_4 -> V_20 [ V_9 ] ;
F_8 ( V_14 ) ;
F_9 (hwirq, &pending, IRQS_PER_WORD) {
F_10 ( F_11 ( V_6 -> V_15 ,
V_11 + V_17 ) ) ;
}
}
F_12 ( V_8 , V_2 ) ;
}
static void F_13 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_21 ;
struct V_22 * V_23 = V_14 -> V_24 ;
F_6 ( V_14 ) ;
if ( V_6 -> V_25 )
F_14 ( V_14 , V_14 -> V_19 | V_14 -> V_26 ,
V_23 -> V_27 . V_28 ) ;
F_8 ( V_14 ) ;
}
static void F_15 ( struct V_13 * V_14 )
{
struct V_22 * V_23 = V_14 -> V_24 ;
F_6 ( V_14 ) ;
F_14 ( V_14 , V_14 -> V_19 , V_23 -> V_27 . V_28 ) ;
F_8 ( V_14 ) ;
}
static int F_16 ( struct V_29 * V_30 ,
struct V_5 * V_4 ,
int V_31 , T_1 * V_32 )
{
struct V_3 * V_33 = & V_4 -> V_33 [ V_31 ] ;
int V_34 ;
unsigned int V_9 ;
V_34 = F_17 ( V_30 , V_31 ) ;
if ( ! V_34 ) {
F_18 ( L_1 , V_31 ) ;
return - V_35 ;
}
for ( V_9 = 0 ; V_9 < V_4 -> V_10 ; V_9 ++ ) {
if ( V_4 -> V_36 ) {
V_33 -> V_20 [ V_9 ] |=
F_19 ( V_4 -> V_36 +
V_31 * V_4 -> V_10 + V_9 ) ;
} else {
V_33 -> V_20 [ V_9 ] = 0xffffffff ;
}
V_32 [ V_9 ] |= V_33 -> V_20 [ V_9 ] ;
}
V_33 -> V_6 = V_4 ;
F_20 ( V_34 ,
F_1 , V_33 ) ;
return 0 ;
}
static int T_2 F_21 ( struct V_29 * V_30 ,
struct V_5 * V_4 )
{
int V_37 ;
V_4 -> V_38 [ 0 ] = F_22 ( V_30 , 0 ) ;
if ( ! V_4 -> V_38 [ 0 ] ) {
F_18 ( L_2 ) ;
return - V_39 ;
}
V_4 -> V_40 [ 0 ] = V_4 -> V_38 [ 0 ] ;
V_4 -> V_41 [ 0 ] = V_42 ;
V_4 -> V_18 [ 0 ] = V_43 ;
V_4 -> V_10 = 1 ;
V_37 = F_23 ( V_30 , L_3 ,
V_4 -> V_44 , V_4 -> V_10 ) ;
if ( V_37 != 0 && V_37 != - V_35 ) {
F_18 ( L_4 ) ;
return - V_35 ;
}
V_4 -> V_36 = F_24 ( V_30 , L_5 , & V_37 ) ;
if ( ! V_4 -> V_36 ||
( V_37 != ( sizeof( V_45 ) * V_4 -> V_46 * V_4 -> V_10 ) ) ) {
F_18 ( L_6 ) ;
return - V_35 ;
}
return 0 ;
}
static int T_2 F_25 ( struct V_29 * V_30 ,
struct V_5 * V_4 )
{
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
unsigned int V_49 = V_47 * 2 ;
void T_3 * V_50 = F_22 ( V_30 , V_49 + 0 ) ;
void T_3 * V_51 = F_22 ( V_30 , V_49 + 1 ) ;
void T_3 * V_11 = F_26 ( V_50 , V_51 ) ;
V_4 -> V_38 [ V_49 + 0 ] = V_50 ;
V_4 -> V_38 [ V_49 + 1 ] = V_51 ;
if ( ! V_11 )
break;
V_4 -> V_40 [ V_47 ] = V_11 ;
V_4 -> V_41 [ V_47 ] = V_50 - V_11 ;
V_4 -> V_18 [ V_47 ] = V_51 - V_11 ;
}
if ( ! V_47 ) {
F_18 ( L_2 ) ;
return - V_35 ;
}
V_4 -> V_10 = V_47 ;
return 0 ;
}
static int T_2 F_27 ( struct V_29 * V_30 ,
struct V_29 * V_52 ,
int (* F_28)( struct V_29 * ,
struct V_5 * ) ,
const char * V_53 )
{
unsigned int V_54 = V_55 | V_56 | V_57 ;
struct V_5 * V_4 ;
struct V_13 * V_14 ;
struct V_22 * V_23 ;
int V_37 = 0 ;
unsigned int V_9 , V_31 , V_58 ;
T_1 V_32 [ V_48 ] = { } ;
V_4 = F_29 ( sizeof( * V_4 ) , V_59 ) ;
if ( ! V_4 )
return - V_39 ;
V_4 -> V_46 = F_30 ( V_30 ) ;
if ( V_4 -> V_46 <= 0 ) {
F_18 ( L_7 ) ;
V_37 = - V_39 ;
goto V_60;
}
V_4 -> V_33 = F_31 ( V_4 -> V_46 , sizeof( * V_4 -> V_33 ) ,
V_59 ) ;
if ( ! V_4 -> V_33 ) {
V_37 = - V_39 ;
goto V_61;
}
V_37 = F_28 ( V_30 , V_4 ) ;
if ( V_37 < 0 )
goto V_61;
for ( V_31 = 0 ; V_31 < V_4 -> V_46 ; V_31 ++ ) {
V_37 = F_16 ( V_30 , V_4 , V_31 , V_32 ) ;
if ( V_37 )
goto V_61;
}
V_4 -> V_15 = F_32 ( V_30 , V_12 * V_4 -> V_10 ,
& V_62 , NULL ) ;
if ( ! V_4 -> V_15 ) {
V_37 = - V_39 ;
goto V_61;
}
V_58 = V_63 ;
if ( F_33 ( V_64 ) && F_33 ( V_65 ) )
V_58 |= V_66 ;
V_37 = F_34 ( V_4 -> V_15 , V_12 , 1 ,
V_30 -> V_67 , V_68 , V_54 , 0 , V_58 ) ;
if ( V_37 ) {
F_18 ( L_8 ) ;
goto V_69;
}
if ( F_35 ( V_30 , L_9 ) )
V_4 -> V_25 = true ;
for ( V_9 = 0 ; V_9 < V_4 -> V_10 ; V_9 ++ ) {
V_31 = V_9 * V_12 ;
V_14 = F_5 ( V_4 -> V_15 , V_31 ) ;
V_14 -> V_70 = 0xffffffff & ~ V_32 [ V_9 ] ;
V_14 -> V_21 = V_4 ;
V_23 = V_14 -> V_24 ;
V_14 -> V_71 = V_4 -> V_40 [ V_9 ] ;
V_23 -> V_27 . V_28 = V_4 -> V_41 [ V_9 ] ;
F_14 ( V_14 , V_4 -> V_44 [ V_9 ] ,
V_4 -> V_41 [ V_9 ] ) ;
V_23 -> V_8 . V_72 = V_73 ;
V_23 -> V_8 . V_74 = V_75 ;
V_23 -> V_8 . V_76 = V_77 ;
V_14 -> V_78 = F_13 ;
V_14 -> V_79 = F_15 ;
V_14 -> V_19 = F_7 ( V_14 , V_23 -> V_27 . V_28 ) ;
if ( V_4 -> V_25 ) {
V_14 -> V_80 = 0xffffffff ;
V_14 -> V_80 &= ~ V_14 -> V_70 ;
V_23 -> V_8 . V_81 = V_82 ;
}
}
F_36 ( L_10 ,
V_53 , V_4 -> V_38 [ 0 ] , V_4 -> V_46 ) ;
return 0 ;
V_69:
F_37 ( V_4 -> V_15 ) ;
V_61:
F_38 ( V_4 -> V_33 ) ;
V_60:
for ( V_9 = 0 ; V_9 < V_83 ; V_9 ++ ) {
if ( V_4 -> V_38 [ V_9 ] )
F_39 ( V_4 -> V_38 [ V_9 ] ) ;
}
F_38 ( V_4 ) ;
return V_37 ;
}
static int T_2 F_40 ( struct V_29 * V_30 ,
struct V_29 * V_52 )
{
return F_27 ( V_30 , V_52 , F_21 ,
L_11 ) ;
}
static int T_2 F_41 ( struct V_29 * V_30 ,
struct V_29 * V_52 )
{
return F_27 ( V_30 , V_52 , F_25 ,
L_12 ) ;
}
