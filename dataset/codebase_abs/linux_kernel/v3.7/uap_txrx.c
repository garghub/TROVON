static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_3 * V_11 ;
struct V_12 * V_13 ;
int V_14 ;
struct V_15 V_16 ;
T_1 V_17 [ V_18 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
V_8 = (struct V_7 * ) ( V_4 -> V_19 ) ;
V_10 = ( void * ) V_8 + F_2 ( V_8 -> V_20 ) ;
if ( ( F_3 ( & V_6 -> V_21 ) >=
V_22 ) ) {
F_4 ( V_2 -> V_6 -> V_23 ,
L_1 ) ;
F_5 ( V_4 ) ;
return;
}
if ( ! memcmp ( & V_10 -> V_24 ,
V_17 , sizeof( V_17 ) ) )
V_14 = ( T_1 * ) V_25 - ( T_1 * ) V_8 ;
else
V_14 = ( T_1 * ) & V_10 -> V_26 - ( T_1 * ) V_8 ;
F_6 ( V_4 , V_14 ) ;
if ( F_7 ( V_4 ) < V_27 ) {
F_8 ( V_2 -> V_6 -> V_23 ,
L_2 ,
F_7 ( V_4 ) ) ;
V_11 =
F_9 ( V_4 , V_27 ) ;
if ( F_10 ( ! V_11 ) ) {
F_4 ( V_2 -> V_6 -> V_23 ,
L_3 ) ;
F_5 ( V_4 ) ;
V_2 -> V_28 . V_29 ++ ;
return;
}
F_5 ( V_4 ) ;
V_4 = V_11 ;
F_8 ( V_2 -> V_6 -> V_23 , L_4 ,
F_7 ( V_4 ) ) ;
}
V_13 = F_11 ( V_4 ) ;
V_13 -> V_30 = V_2 -> V_30 ;
V_13 -> V_31 = V_2 -> V_31 ;
V_13 -> V_32 |= V_33 ;
F_12 ( & V_16 ) ;
V_4 -> V_34 = F_13 ( V_16 ) ;
F_14 ( V_2 , V_4 ) ;
F_15 ( & V_6 -> V_35 ) ;
F_15 ( & V_6 -> V_21 ) ;
if ( ( F_3 ( & V_6 -> V_35 ) >= V_36 ) ) {
F_16 ( V_2 -> V_37 ) ;
F_17 ( V_2 -> V_37 , V_2 -> V_6 ) ;
}
return;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
T_1 V_38 [ V_18 ] ;
struct V_3 * V_39 ;
V_8 = (struct V_7 * ) ( V_4 -> V_19 ) ;
V_10 = ( void * ) V_8 + F_2 ( V_8 -> V_20 ) ;
if ( ! V_2 -> V_40 ) {
F_4 ( V_6 -> V_23 , L_5 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
memcpy ( V_38 , V_10 -> V_26 . V_41 , V_18 ) ;
if ( F_20 ( V_38 ) ) {
V_39 = F_21 ( V_4 , V_42 ) ;
F_1 ( V_2 , V_39 ) ;
} else {
if ( F_22 ( V_2 , V_38 ) ) {
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
}
return F_23 ( V_6 , V_4 ) ;
}
int F_24 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
int V_43 ;
struct V_7 * V_8 ;
struct V_44 * V_45 = F_25 ( V_4 ) ;
struct V_9 * V_10 ;
T_2 V_46 ;
T_1 V_47 [ V_18 ] , V_48 ;
struct V_49 * V_50 ;
struct V_1 * V_2 =
F_26 ( V_6 , V_45 -> V_30 ,
V_45 -> V_31 ) ;
if ( ! V_2 )
return - 1 ;
V_8 = (struct V_7 * ) ( V_4 -> V_19 ) ;
V_46 = F_2 ( V_8 -> V_46 ) ;
V_10 = ( void * ) V_8 + F_2 ( V_8 -> V_20 ) ;
if ( ( F_2 ( V_8 -> V_20 ) +
F_2 ( V_8 -> V_51 ) ) > ( T_2 ) V_4 -> V_52 ) {
F_4 ( V_6 -> V_23 ,
L_6 ,
V_4 -> V_52 , F_2 ( V_8 -> V_20 ) ,
F_2 ( V_8 -> V_51 ) ) ;
V_2 -> V_28 . V_53 ++ ;
if ( V_6 -> V_54 . V_55 )
V_6 -> V_54 . V_55 ( V_6 , V_4 ) ;
else
F_19 ( V_4 ) ;
return 0 ;
}
if ( F_2 ( V_8 -> V_46 ) == V_56 ) {
struct V_57 V_58 ;
struct V_3 * V_59 ;
F_27 ( & V_58 ) ;
F_6 ( V_4 , F_2 ( V_8 -> V_20 ) ) ;
F_28 ( V_4 , F_2 ( V_8 -> V_51 ) ) ;
F_29 ( V_4 , & V_58 , V_2 -> V_60 ,
V_2 -> V_61 -> V_62 , 0 , false ) ;
while ( ! F_30 ( & V_58 ) ) {
V_59 = F_31 ( & V_58 ) ;
V_43 = F_32 ( V_6 , V_59 ) ;
if ( V_43 )
F_4 ( V_6 -> V_23 ,
L_7 ) ;
}
return 0 ;
} else if ( V_46 == V_63 ) {
V_43 = F_33 ( V_6 , V_4 ) ;
if ( V_43 )
F_4 ( V_6 -> V_23 , L_8 ) ;
F_19 ( V_4 ) ;
return V_43 ;
}
memcpy ( V_47 , V_10 -> V_26 . V_64 , V_18 ) ;
if ( V_46 != V_65 && V_8 -> V_66 < V_67 ) {
V_50 = F_22 ( V_2 , V_47 ) ;
if ( V_50 )
V_50 -> V_68 [ V_8 -> V_66 ] =
F_2 ( V_8 -> V_69 ) ;
}
if ( ! V_2 -> V_70 ||
( ! F_34 ( V_2 , V_8 -> V_66 , V_47 ) &&
( F_2 ( V_8 -> V_46 ) != V_56 ) ) ) {
V_43 = F_18 ( V_2 , V_4 ) ;
return V_43 ;
}
V_48 = ( T_1 ) F_2 ( V_8 -> V_46 ) ;
V_43 = F_35 ( V_2 , F_2 ( V_8 -> V_69 ) ,
V_8 -> V_66 , V_47 , V_48 ,
V_4 ) ;
if ( V_43 || ( V_46 == V_65 ) ) {
if ( V_6 -> V_54 . V_55 )
V_6 -> V_54 . V_55 ( V_6 , V_4 ) ;
else
F_19 ( V_4 ) ;
}
if ( V_43 )
V_2 -> V_28 . V_53 ++ ;
return V_43 ;
}
void * F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_71 * V_72 ;
struct V_12 * V_13 = F_11 ( V_4 ) ;
int V_73 , V_52 ;
T_2 V_48 ;
if ( ! V_4 -> V_52 ) {
F_4 ( V_6 -> V_23 , L_9 , V_4 -> V_52 ) ;
V_13 -> V_74 = - 1 ;
return V_4 -> V_19 ;
}
V_48 = F_37 ( V_4 ) ? V_63 : 0 ;
V_73 = ( 4 - ( ( ( void * ) V_4 -> V_19 - NULL ) & 0x3 ) ) % 4 ;
V_52 = sizeof( * V_72 ) + V_73 ;
F_38 ( F_7 ( V_4 ) < V_52 + V_75 ) ;
F_39 ( V_4 , V_52 ) ;
V_72 = (struct V_71 * ) V_4 -> V_19 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_30 = V_2 -> V_30 ;
V_72 -> V_31 = V_2 -> V_31 ;
V_72 -> V_76 = F_40 ( ( T_2 ) ( V_4 -> V_52 - V_52 ) ) ;
V_72 -> V_66 = ( T_1 ) V_4 -> V_66 ;
V_72 -> V_77 = F_41 ( V_2 , V_4 ) ;
if ( V_72 -> V_66 < F_42 ( V_2 -> V_78 . V_79 ) )
V_72 -> V_80 =
F_43 ( V_2 -> V_78 . V_79 [ V_72 -> V_66 ] ) ;
if ( V_48 == V_63 ) {
V_72 -> V_81 = F_40 ( V_48 ) ;
V_52 += V_82 ;
}
V_72 -> V_83 = F_40 ( V_52 ) ;
F_39 ( V_4 , V_75 ) ;
if ( ! V_72 -> V_80 )
V_72 -> V_80 = F_43 ( V_2 -> V_84 ) ;
return V_4 -> V_19 ;
}
