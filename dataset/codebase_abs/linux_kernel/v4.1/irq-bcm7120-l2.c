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
V_15 = F_7 ( V_13 , V_5 -> V_17 [ V_8 ] ) &
V_13 -> V_18 ;
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
struct V_21 * V_22 = F_15 ( V_20 ) ;
struct V_4 * V_5 = V_13 -> V_23 ;
F_6 ( V_13 ) ;
if ( V_5 -> V_24 )
F_16 ( V_13 , V_13 -> V_18 | V_13 -> V_25 ,
V_22 -> V_26 . V_27 ) ;
F_8 ( V_13 ) ;
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_12 * V_13 = F_14 ( V_20 ) ;
struct V_21 * V_22 = F_15 ( V_20 ) ;
F_6 ( V_13 ) ;
F_16 ( V_13 , V_13 -> V_18 , V_22 -> V_26 . V_27 ) ;
F_8 ( V_13 ) ;
}
static int F_18 ( struct V_28 * V_29 ,
struct V_4 * V_30 ,
int V_1 )
{
int V_31 ;
unsigned int V_8 ;
V_31 = F_19 ( V_29 , V_1 ) ;
if ( ! V_31 ) {
F_20 ( L_1 , V_1 ) ;
return - V_32 ;
}
for ( V_8 = 0 ; V_8 < V_30 -> V_9 ; V_8 ++ ) {
if ( V_30 -> V_33 ) {
V_30 -> V_34 [ V_8 ] |=
F_21 ( V_30 -> V_33 +
V_1 * V_30 -> V_9 + V_8 ) ;
} else {
V_30 -> V_34 [ V_8 ] = 0xffffffff ;
}
}
F_22 ( V_31 , V_30 ) ;
F_23 ( V_31 , F_1 ) ;
return 0 ;
}
static int T_1 F_24 ( struct V_28 * V_29 ,
struct V_4 * V_30 )
{
int V_35 ;
V_30 -> V_36 [ 0 ] = F_25 ( V_29 , 0 ) ;
if ( ! V_30 -> V_36 [ 0 ] ) {
F_20 ( L_2 ) ;
return - V_37 ;
}
V_30 -> V_38 [ 0 ] = V_30 -> V_36 [ 0 ] ;
V_30 -> V_39 [ 0 ] = V_40 ;
V_30 -> V_17 [ 0 ] = V_41 ;
V_30 -> V_9 = 1 ;
V_35 = F_26 ( V_29 , L_3 ,
V_30 -> V_42 , V_30 -> V_9 ) ;
if ( V_35 != 0 && V_35 != - V_32 ) {
F_20 ( L_4 ) ;
return - V_32 ;
}
V_30 -> V_33 = F_27 ( V_29 , L_5 , & V_35 ) ;
if ( ! V_30 -> V_33 ||
( V_35 != ( sizeof( V_43 ) * V_30 -> V_44 * V_30 -> V_9 ) ) ) {
F_20 ( L_6 ) ;
return - V_32 ;
}
return 0 ;
}
static int T_1 F_28 ( struct V_28 * V_29 ,
struct V_4 * V_30 )
{
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
unsigned int V_47 = V_45 * 2 ;
void T_2 * V_48 = F_25 ( V_29 , V_47 + 0 ) ;
void T_2 * V_49 = F_25 ( V_29 , V_47 + 1 ) ;
void T_2 * V_10 = F_29 ( V_48 , V_49 ) ;
V_30 -> V_36 [ V_47 + 0 ] = V_48 ;
V_30 -> V_36 [ V_47 + 1 ] = V_49 ;
if ( ! V_10 )
break;
V_30 -> V_38 [ V_45 ] = V_10 ;
V_30 -> V_39 [ V_45 ] = V_48 - V_10 ;
V_30 -> V_17 [ V_45 ] = V_49 - V_10 ;
}
if ( ! V_45 ) {
F_20 ( L_2 ) ;
return - V_32 ;
}
V_30 -> V_9 = V_45 ;
return 0 ;
}
int T_1 F_30 ( struct V_28 * V_29 ,
struct V_28 * V_50 ,
int (* F_31)( struct V_28 * ,
struct V_4 * ) ,
const char * V_51 )
{
unsigned int V_52 = V_53 | V_54 | V_55 ;
struct V_4 * V_30 ;
struct V_12 * V_13 ;
struct V_21 * V_22 ;
int V_35 = 0 ;
unsigned int V_8 , V_1 , V_56 ;
V_30 = F_32 ( sizeof( * V_30 ) , V_57 ) ;
if ( ! V_30 )
return - V_37 ;
V_30 -> V_44 = F_33 ( V_29 ) ;
if ( V_30 -> V_44 <= 0 ) {
F_20 ( L_7 ) ;
V_35 = - V_37 ;
goto V_58;
}
V_35 = F_31 ( V_29 , V_30 ) ;
if ( V_35 < 0 )
goto V_58;
for ( V_8 = 0 ; V_8 < V_30 -> V_9 ; V_8 ++ ) {
F_34 ( V_30 -> V_42 [ V_8 ] ,
V_30 -> V_38 [ V_8 ] +
V_30 -> V_39 [ V_8 ] ) ;
}
for ( V_1 = 0 ; V_1 < V_30 -> V_44 ; V_1 ++ ) {
V_35 = F_18 ( V_29 , V_30 , V_1 ) ;
if ( V_35 )
goto V_58;
}
V_30 -> V_14 = F_35 ( V_29 , V_11 * V_30 -> V_9 ,
& V_59 , NULL ) ;
if ( ! V_30 -> V_14 ) {
V_35 = - V_37 ;
goto V_58;
}
V_56 = V_60 ;
if ( F_36 ( V_61 ) && F_36 ( V_62 ) )
V_56 |= V_63 ;
V_35 = F_37 ( V_30 -> V_14 , V_11 , 1 ,
V_29 -> V_64 , V_65 , V_52 , 0 , V_56 ) ;
if ( V_35 ) {
F_20 ( L_8 ) ;
goto V_66;
}
if ( F_38 ( V_29 , L_9 ) )
V_30 -> V_24 = true ;
for ( V_8 = 0 ; V_8 < V_30 -> V_9 ; V_8 ++ ) {
V_1 = V_8 * V_11 ;
V_13 = F_5 ( V_30 -> V_14 , V_1 ) ;
V_13 -> V_67 = 0xffffffff & ~ V_30 -> V_34 [ V_8 ] ;
V_13 -> V_23 = V_30 ;
V_22 = V_13 -> V_68 ;
V_13 -> V_69 = V_30 -> V_38 [ V_8 ] ;
V_22 -> V_26 . V_27 = V_30 -> V_39 [ V_8 ] ;
V_22 -> V_7 . V_70 = V_71 ;
V_22 -> V_7 . V_72 = V_73 ;
V_22 -> V_7 . V_74 = V_75 ;
V_22 -> V_7 . V_76 = F_13 ;
V_22 -> V_7 . V_77 = F_17 ;
if ( V_30 -> V_24 ) {
V_13 -> V_78 = 0xffffffff ;
V_13 -> V_78 &= ~ V_13 -> V_67 ;
V_22 -> V_7 . V_79 = V_80 ;
}
}
F_39 ( L_10 ,
V_51 , V_30 -> V_36 [ 0 ] , V_30 -> V_44 ) ;
return 0 ;
V_66:
F_40 ( V_30 -> V_14 ) ;
V_58:
for ( V_8 = 0 ; V_8 < V_81 ; V_8 ++ ) {
if ( V_30 -> V_36 [ V_8 ] )
F_41 ( V_30 -> V_36 [ V_8 ] ) ;
}
F_42 ( V_30 ) ;
return V_35 ;
}
int T_1 F_43 ( struct V_28 * V_29 ,
struct V_28 * V_50 )
{
return F_30 ( V_29 , V_50 , F_24 ,
L_11 ) ;
}
int T_1 F_44 ( struct V_28 * V_29 ,
struct V_28 * V_50 )
{
return F_30 ( V_29 , V_50 , F_28 ,
L_12 ) ;
}
