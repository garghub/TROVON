static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_8 ;
F_4 ( V_7 , V_3 ) ;
for ( V_8 = 0 ; V_8 < V_5 -> V_9 ; V_8 ++ ) {
int V_10 = V_8 * V_11 ;
struct V_12 * V_13 =
F_5 ( V_5 -> V_14 , V_10 ) ;
unsigned long V_15 ;
int V_16 ;
F_6 ( V_13 ) ;
V_15 = F_7 ( V_13 , V_17 ) & V_13 -> V_18 ;
F_8 ( V_13 ) ;
F_9 (hwirq, &pending, IRQS_PER_WORD) {
F_10 ( F_11 ( V_5 -> V_14 ,
V_10 + V_16 ) ) ;
}
}
F_12 ( V_7 , V_3 ) ;
}
static void F_13 ( struct V_19 * V_20 )
{
struct V_12 * V_13 = F_14 ( V_20 ) ;
struct V_4 * V_5 = V_13 -> V_21 ;
F_6 ( V_13 ) ;
if ( V_5 -> V_22 )
F_15 ( V_13 , V_13 -> V_18 | V_13 -> V_23 , V_24 ) ;
F_8 ( V_13 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_12 * V_13 = F_14 ( V_20 ) ;
F_6 ( V_13 ) ;
F_15 ( V_13 , V_13 -> V_18 , V_24 ) ;
F_8 ( V_13 ) ;
}
static int F_17 ( struct V_25 * V_26 ,
struct V_4 * V_27 ,
int V_1 , const T_1 * V_28 )
{
int V_29 ;
unsigned int V_8 ;
V_29 = F_18 ( V_26 , V_1 ) ;
if ( ! V_29 ) {
F_19 ( L_1 , V_1 ) ;
return - V_30 ;
}
for ( V_8 = 0 ; V_8 < V_27 -> V_9 ; V_8 ++ )
V_27 -> V_31 [ V_8 ] |=
F_20 ( V_28 + V_1 * V_27 -> V_9 + V_8 ) ;
F_21 ( V_29 , V_27 ) ;
F_22 ( V_29 , F_1 ) ;
return 0 ;
}
int T_2 F_23 ( struct V_25 * V_26 ,
struct V_25 * V_32 )
{
unsigned int V_33 = V_34 | V_35 | V_36 ;
struct V_4 * V_27 ;
struct V_12 * V_13 ;
struct V_37 * V_38 ;
const T_1 * V_28 ;
int V_39 ;
int V_40 = 0 , V_41 ;
unsigned int V_8 , V_1 , V_42 ;
V_27 = F_24 ( sizeof( * V_27 ) , V_43 ) ;
if ( ! V_27 )
return - V_44 ;
for ( V_8 = 0 ; V_8 < V_45 ; V_8 ++ ) {
V_27 -> V_10 [ V_8 ] = F_25 ( V_26 , V_8 ) ;
if ( ! V_27 -> V_10 [ V_8 ] )
break;
V_27 -> V_9 = V_8 + 1 ;
}
if ( ! V_27 -> V_9 ) {
F_19 ( L_2 ) ;
V_40 = - V_44 ;
goto V_46;
}
V_40 = F_26 ( V_26 , L_3 ,
V_27 -> V_47 , V_27 -> V_9 ) ;
if ( V_40 == 0 || V_40 == - V_30 ) {
for ( V_8 = 0 ; V_8 < V_27 -> V_9 ; V_8 ++ )
F_27 ( V_27 -> V_47 [ V_8 ] ,
V_27 -> V_10 [ V_8 ] + V_24 ) ;
} else {
F_19 ( L_4 ) ;
V_40 = - V_30 ;
goto V_46;
}
V_39 = F_28 ( V_26 ) ;
if ( V_39 <= 0 ) {
F_19 ( L_5 ) ;
V_40 = - V_44 ;
goto V_46;
}
V_28 = F_29 ( V_26 , L_6 , & V_41 ) ;
if ( ! V_28 ||
( V_41 != ( sizeof( * V_28 ) * V_39 * V_27 -> V_9 ) ) ) {
F_19 ( L_7 ) ;
V_40 = - V_30 ;
goto V_46;
}
for ( V_1 = 0 ; V_1 < V_39 ; V_1 ++ ) {
V_40 = F_17 ( V_26 , V_27 , V_1 , V_28 ) ;
if ( V_40 )
goto V_46;
}
V_27 -> V_14 = F_30 ( V_26 , V_11 * V_27 -> V_9 ,
& V_48 , NULL ) ;
if ( ! V_27 -> V_14 ) {
V_40 = - V_44 ;
goto V_46;
}
V_42 = V_49 ;
if ( F_31 ( V_50 ) && F_31 ( V_51 ) )
V_42 |= V_52 ;
V_40 = F_32 ( V_27 -> V_14 , V_11 , 1 ,
V_26 -> V_53 , V_54 , V_33 , 0 , V_42 ) ;
if ( V_40 ) {
F_19 ( L_8 ) ;
goto V_55;
}
if ( F_33 ( V_26 , L_9 ) )
V_27 -> V_22 = true ;
for ( V_8 = 0 ; V_8 < V_27 -> V_9 ; V_8 ++ ) {
V_1 = V_8 * V_11 ;
V_13 = F_5 ( V_27 -> V_14 , V_1 ) ;
V_13 -> V_56 = 0xffffffff & ~ V_27 -> V_31 [ V_8 ] ;
V_13 -> V_57 = V_27 -> V_10 [ V_8 ] ;
V_13 -> V_21 = V_27 ;
V_38 = V_13 -> V_58 ;
V_38 -> V_59 . V_60 = V_24 ;
V_38 -> V_7 . V_61 = V_62 ;
V_38 -> V_7 . V_63 = V_64 ;
V_38 -> V_7 . V_65 = V_66 ;
V_38 -> V_7 . V_67 = F_13 ;
V_38 -> V_7 . V_68 = F_16 ;
if ( V_27 -> V_22 ) {
V_13 -> V_69 = 0xffffffff ;
V_13 -> V_69 &= ~ V_13 -> V_56 ;
V_38 -> V_7 . V_70 = V_71 ;
}
}
F_34 ( L_10 ,
V_27 -> V_10 [ 0 ] , V_39 ) ;
return 0 ;
V_55:
F_35 ( V_27 -> V_14 ) ;
V_46:
for ( V_8 = 0 ; V_8 < V_45 ; V_8 ++ ) {
if ( V_27 -> V_10 [ V_8 ] )
F_36 ( V_27 -> V_10 [ V_8 ] ) ;
}
F_37 ( V_27 ) ;
return V_40 ;
}
