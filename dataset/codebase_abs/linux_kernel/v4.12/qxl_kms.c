static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 != 0x4f525851 ) {
F_2 ( L_1 , V_4 -> V_5 ) ;
return false ;
}
F_3 ( L_2 , V_4 -> V_6 , V_4 -> V_7 ) ;
F_3 ( L_3 , V_4 -> V_8 ,
V_4 -> V_9 ) ;
F_3 ( L_4 ,
V_4 -> V_10 , V_4 -> V_11 ) ;
F_3 ( L_5 ,
V_4 -> V_12 , V_4 -> V_13 ) ;
V_2 -> V_14 = V_4 -> V_12 ;
F_3 ( L_6 , V_4 -> V_15 ) ;
return true ;
}
static void F_4 ( struct V_1 * V_2 , int V_16 ,
struct V_17 * V_18 )
{
V_2 -> V_19 -> V_20 . V_21 = V_18 -> V_22 ;
V_2 -> V_19 -> V_20 . V_23 = V_18 -> V_24 ;
F_5 ( V_2 , V_16 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_25 ,
unsigned long V_22 , unsigned long V_24 )
{
T_2 V_26 ;
struct V_17 * V_18 ;
T_1 V_16 ;
V_16 = V_2 -> V_4 -> V_27 + V_25 ;
V_18 = & V_2 -> V_28 [ V_16 ] ;
V_18 -> V_22 = V_22 ;
V_18 -> V_24 = V_24 ;
F_4 ( V_2 , V_16 , V_18 ) ;
V_18 -> V_29 = V_2 -> V_4 -> V_30 ;
V_26 = V_16 << V_2 -> V_31 ;
V_26 |= V_18 -> V_29 ;
V_26 <<= ( 64 - ( V_2 -> V_31 + V_2 -> V_32 ) ) ;
V_18 -> V_26 = V_26 ;
return V_16 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_2 -> V_33 , & V_2 -> V_28 [ V_2 -> V_33 ] ) ;
F_4 ( V_2 , V_2 -> V_34 , & V_2 -> V_28 [ V_2 -> V_34 ] ) ;
}
static void F_8 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_9 ( V_36 , struct V_1 , V_37 ) ;
F_10 ( V_2 ) ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
int V_42 , V_43 ;
V_42 = F_12 ( & V_2 -> V_44 , V_39 , & V_41 -> V_45 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_44 . V_41 = V_41 ;
F_13 ( V_41 , & V_2 -> V_44 ) ;
V_2 -> V_44 . V_46 = V_2 ;
F_14 ( & V_2 -> V_47 . V_48 ) ;
F_14 ( & V_2 -> V_49 ) ;
F_14 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_51 ) ;
F_15 ( V_2 ) ;
V_2 -> V_52 = F_16 ( V_41 , 2 ) ;
V_2 -> V_53 = F_17 ( V_41 , 2 ) ;
V_2 -> V_54 = F_16 ( V_41 , 0 ) ;
V_2 -> V_55 = F_16 ( V_41 , 3 ) ;
V_2 -> V_56 = F_18 ( V_2 -> V_54 , F_17 ( V_41 , 0 ) ) ;
if ( F_17 ( V_41 , 4 ) > 0 ) {
V_43 = 4 ;
V_2 -> V_57 = F_16 ( V_41 , V_43 ) ;
V_2 -> V_58 = F_17 ( V_41 , V_43 ) ;
V_2 -> V_59 =
F_18 ( V_2 -> V_57 ,
V_2 -> V_58 ) ;
}
if ( V_2 -> V_59 == NULL ) {
V_43 = 1 ;
V_2 -> V_57 = F_16 ( V_41 , V_43 ) ;
V_2 -> V_58 = F_17 ( V_41 , V_43 ) ;
V_2 -> V_59 =
F_18 ( V_2 -> V_57 ,
V_2 -> V_58 ) ;
}
F_19 ( L_7 ,
( unsigned long long ) V_2 -> V_54 ,
( unsigned long long ) F_20 ( V_41 , 0 ) ,
( int ) F_17 ( V_41 , 0 ) / 1024 / 1024 ,
( int ) F_17 ( V_41 , 0 ) / 1024 ,
( unsigned long long ) V_2 -> V_57 ,
( unsigned long long ) F_20 ( V_41 , V_43 ) ,
( int ) V_2 -> V_58 / 1024 / 1024 ,
( int ) V_2 -> V_58 / 1024 ,
( V_43 == 4 ) ? L_8 : L_9 ) ;
V_2 -> V_4 = F_21 ( V_2 -> V_52 , V_2 -> V_53 ) ;
if ( ! V_2 -> V_4 ) {
F_22 ( L_10 ) ;
return - V_60 ;
}
F_1 ( V_2 ) ;
V_42 = F_23 ( V_2 ) ;
if ( V_42 ) {
F_2 ( L_11 , V_42 ) ;
return V_42 ;
}
V_2 -> V_19 = F_21 ( V_2 -> V_54 +
V_2 -> V_4 -> V_15 ,
sizeof( * V_2 -> V_19 ) ) ;
V_2 -> V_61 = F_24 ( & ( V_2 -> V_19 -> V_62 ) ,
sizeof( struct V_63 ) ,
V_64 ,
V_2 -> V_55 + V_65 ,
false ,
& V_2 -> V_66 ) ;
V_2 -> V_67 = F_24 (
& ( V_2 -> V_19 -> V_68 ) ,
sizeof( struct V_63 ) ,
V_69 ,
V_2 -> V_55 + V_65 ,
false ,
& V_2 -> V_70 ) ;
V_2 -> V_71 = F_24 (
& ( V_2 -> V_19 -> V_72 ) ,
sizeof( T_2 ) ,
V_73 , 0 , true ,
NULL ) ;
V_2 -> V_74 = V_2 -> V_4 -> V_75 ;
V_2 -> V_31 = V_2 -> V_4 -> V_31 ;
V_2 -> V_32 = V_2 -> V_4 -> V_32 ;
V_2 -> V_76 =
( ~ ( T_2 ) 0 ) >> ( V_2 -> V_32 + V_2 -> V_31 ) ;
V_2 -> V_28 =
F_25 ( V_2 -> V_74 * sizeof( struct V_17 ) ,
V_77 ) ;
F_26 ( & V_2 -> V_78 ) ;
F_27 ( & V_2 -> V_79 ) ;
F_27 ( & V_2 -> V_80 ) ;
F_26 ( & V_2 -> V_81 ) ;
F_27 ( & V_2 -> V_82 ) ;
F_14 ( & V_2 -> V_83 ) ;
F_28 ( V_2 ) ;
V_42 = F_29 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_33 = F_6 ( V_2 , 0 ,
( unsigned long ) V_2 -> V_54 ,
( unsigned long ) V_2 -> V_54 + V_2 -> V_4 -> V_15 ) ;
V_2 -> V_34 = F_6 ( V_2 , 1 ,
( unsigned long ) V_2 -> V_57 ,
( unsigned long ) V_2 -> V_57 + V_2 -> V_58 ) ;
F_3 ( L_12 ,
V_2 -> V_33 ,
( unsigned long ) V_2 -> V_54 , V_2 -> V_4 -> V_15 ) ;
F_3 ( L_13 ,
V_2 -> V_34 ,
( unsigned long ) V_2 -> V_57 ,
( unsigned long ) V_2 -> V_58 ) ;
F_30 ( & V_2 -> V_37 , F_8 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_84 [ 0 ] )
F_32 ( & V_2 -> V_84 [ 0 ] ) ;
if ( V_2 -> V_84 [ 1 ] )
F_32 ( & V_2 -> V_84 [ 1 ] ) ;
F_33 ( & V_2 -> V_37 ) ;
F_34 ( V_2 -> V_61 ) ;
F_34 ( V_2 -> V_67 ) ;
F_34 ( V_2 -> V_71 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 -> V_59 ) ;
F_37 ( V_2 -> V_56 ) ;
F_38 ( V_2 -> V_19 ) ;
F_38 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
