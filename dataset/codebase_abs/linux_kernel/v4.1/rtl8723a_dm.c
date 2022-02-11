static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 = false ;
if ( ! V_2 -> V_5 . V_6 )
return;
V_3 = F_2 ( V_2 , V_7 ) ;
V_3 |= ( V_8 ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
V_3 &= ~ ( V_8 ) ;
F_3 ( V_2 , V_9 , V_3 ) ;
V_3 = F_2 ( V_2 , V_7 ) ;
V_3 &= ~ ( V_8 ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
V_3 = F_2 ( V_2 , V_9 ) ;
if ( V_3 == 0xff )
return;
if ( V_3 & V_8 )
V_4 = true ;
if ( V_4 ) {
F_4 ( L_1 ) ;
if ( V_2 -> V_10 [ 0 ] == 0 ) {
return;
}
F_5 ( F_6 ( V_2 -> V_10 [ 0 ] ) , V_11 , 1 ) ;
}
}
void F_7 ( struct V_1 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
struct V_18 * V_19 = & V_14 -> V_20 ;
T_1 V_21 , V_22 ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_12 = V_12 ;
F_9 ( V_19 , V_23 , V_24 ) ;
if ( F_10 ( V_14 -> V_25 ) ) {
V_22 = V_26 ;
V_21 = V_27 ;
} else if ( F_11 ( V_14 -> V_25 ) ) {
V_22 = V_26 ;
V_21 = V_28 ;
} else {
V_22 = V_29 ;
V_21 = V_27 ;
}
F_9 ( V_19 , V_30 , V_22 ) ;
F_9 ( V_19 , V_31 , V_21 ) ;
F_9 ( V_19 , V_32 , F_12 ( V_14 -> V_25 ) ) ;
F_9 ( V_19 , V_33 , V_14 -> V_34 ) ;
if ( V_14 -> V_34 == V_35 ) {
F_9 ( V_19 , V_36 , true ) ;
F_9 ( V_19 , V_37 , true ) ;
}
F_9 ( V_19 , V_38 , V_12 -> V_5 . V_39 ) ;
}
static void F_13 ( struct V_1 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_18 * V_19 = & V_14 -> V_20 ;
struct V_15 * V_16 = & V_14 -> V_17 ;
int V_40 ;
V_16 -> V_41 = 0 ;
F_14 ( V_12 , V_42 ) ;
for ( V_40 = 0 ; V_40 < V_43 ; V_40 ++ )
F_15 ( V_19 , V_44 , V_40 , NULL ) ;
}
void F_16 ( struct V_1 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
struct V_18 * V_19 = & V_14 -> V_20 ;
T_1 V_40 ;
F_13 ( V_12 ) ;
F_17 ( V_19 ) ;
for ( V_40 = 0 ; V_40 < 32 ; V_40 ++ )
V_16 -> V_45 [ V_40 ] = F_2 ( V_12 , V_46 + V_40 ) & 0x3f ;
}
void
F_18 (
struct V_1 * V_12
)
{
bool V_47 = false ;
bool V_48 = true ;
T_1 V_49 = false ;
T_1 V_50 = false ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
V_50 = V_12 -> V_50 ;
if ( V_50 == false )
goto V_51;
V_47 = V_12 -> V_52 . V_47 ;
V_48 = F_19 ( V_12 ) ;
if ( ! V_47 && V_48 ) {
if ( F_20 ( & V_12 -> V_53 , V_54 ) ) {
V_16 -> V_45 [ 0 ] = F_2 ( V_12 , V_46 ) & 0x3f ;
} else {
T_1 V_40 ;
for ( V_40 = 1 ; V_40 < ( V_12 -> V_55 . V_56 + 1 ) ; V_40 ++ )
V_16 -> V_45 [ V_40 ] = F_2 ( V_12 , ( V_46 + V_40 ) ) & 0x3f ;
}
}
if ( F_21 ( V_12 ) )
V_49 = true ;
F_22 ( & V_14 -> V_20 , V_57 , V_49 ) ;
F_23 ( V_12 ) ;
V_51:
F_1 ( V_12 ) ;
}
