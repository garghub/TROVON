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
F_9 ( V_19 , V_23 , 0x04 ) ;
F_9 ( V_19 , V_24 , V_25 ) ;
F_9 ( V_19 , V_26 , V_27 ) ;
if ( F_10 ( V_14 -> V_28 ) ) {
V_22 = V_29 ;
V_21 = V_30 ;
} else if ( F_11 ( V_14 -> V_28 ) ) {
V_22 = V_29 ;
V_21 = V_31 ;
} else {
V_22 = V_32 ;
V_21 = V_30 ;
}
F_9 ( V_19 , V_33 , V_22 ) ;
F_9 ( V_19 , V_34 , V_21 ) ;
F_9 ( V_19 , V_35 , F_12 ( V_14 -> V_28 ) ) ;
F_9 ( V_19 , V_36 , V_14 -> V_37 ) ;
if ( V_14 -> V_37 == V_38 ) {
F_9 ( V_19 , V_39 , true ) ;
F_9 ( V_19 , V_40 , true ) ;
}
F_9 ( V_19 , V_41 , V_14 -> V_42 ) ;
F_9 ( V_19 , V_43 , V_12 -> V_5 . V_44 ) ;
if ( V_14 -> V_45 == V_46 )
F_13 ( V_19 , V_47 , V_48 ) ;
else if ( V_14 -> V_45 == V_49 )
F_13 ( V_19 , V_47 , V_50 ) ;
else if ( V_14 -> V_45 == V_51 )
F_13 ( V_19 , V_47 , V_52 ) ;
}
static void F_14 ( struct V_1 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_18 * V_19 = & V_14 -> V_20 ;
struct V_15 * V_16 = & V_14 -> V_17 ;
int V_53 ;
V_16 -> V_54 = V_55 |
V_56 |
V_57 |
V_58 |
V_59 |
V_60 |
V_61 |
V_62 |
V_63 |
V_64 ;
F_15 ( V_12 , V_65 ) ;
for ( V_53 = 0 ; V_53 < V_66 ; V_53 ++ )
F_16 ( V_19 , V_67 , V_53 , NULL ) ;
}
void F_17 ( struct V_1 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
struct V_18 * V_19 = & V_14 -> V_20 ;
T_1 V_53 ;
F_14 ( V_12 ) ;
F_18 ( V_19 ) ;
for ( V_53 = 0 ; V_53 < 32 ; V_53 ++ )
V_16 -> V_68 [ V_53 ] = F_2 ( V_12 , V_69 + V_53 ) & 0x3f ;
}
void
F_19 (
struct V_1 * V_12
)
{
bool V_70 = false ;
bool V_71 = true ;
T_1 V_72 = false ;
T_1 V_73 = false ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = & V_14 -> V_17 ;
V_73 = V_12 -> V_73 ;
if ( V_73 == false )
goto V_74;
V_70 = V_12 -> V_75 . V_70 ;
V_71 = F_20 ( V_12 ) ;
if ( ! V_70 && V_71 ) {
if ( F_21 ( & V_12 -> V_76 , V_77 ) ) {
V_16 -> V_68 [ 0 ] = F_2 ( V_12 , V_69 ) & 0x3f ;
} else {
T_1 V_53 ;
for ( V_53 = 1 ; V_53 < ( V_12 -> V_78 . V_79 + 1 ) ; V_53 ++ )
V_16 -> V_68 [ V_53 ] = F_2 ( V_12 , ( V_69 + V_53 ) ) & 0x3f ;
}
}
if ( F_22 ( V_12 ) )
V_72 = true ;
F_13 ( & V_14 -> V_20 , V_80 , V_72 ) ;
F_23 ( V_12 ) ;
V_74:
F_1 ( V_12 ) ;
}
