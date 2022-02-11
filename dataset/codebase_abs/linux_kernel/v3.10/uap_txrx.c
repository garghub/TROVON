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
return F_23 ( V_2 , V_4 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_43 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
T_2 V_44 ;
T_1 V_45 [ V_18 ] , V_46 ;
struct V_47 * V_48 ;
V_8 = (struct V_7 * ) ( V_4 -> V_19 ) ;
V_44 = F_2 ( V_8 -> V_44 ) ;
V_10 = ( void * ) V_8 + F_2 ( V_8 -> V_20 ) ;
if ( ( F_2 ( V_8 -> V_20 ) +
F_2 ( V_8 -> V_49 ) ) > ( T_2 ) V_4 -> V_50 ) {
F_4 ( V_6 -> V_23 ,
L_6 ,
V_4 -> V_50 , F_2 ( V_8 -> V_20 ) ,
F_2 ( V_8 -> V_49 ) ) ;
V_2 -> V_28 . V_51 ++ ;
if ( V_6 -> V_52 . V_53 )
V_6 -> V_52 . V_53 ( V_6 , V_4 ) ;
else
F_19 ( V_4 ) ;
return 0 ;
}
if ( F_2 ( V_8 -> V_44 ) == V_54 ) {
struct V_55 V_56 ;
struct V_3 * V_57 ;
F_25 ( & V_56 ) ;
F_6 ( V_4 , F_2 ( V_8 -> V_20 ) ) ;
F_26 ( V_4 , F_2 ( V_8 -> V_49 ) ) ;
F_27 ( V_4 , & V_56 , V_2 -> V_58 ,
V_2 -> V_59 -> V_60 , 0 , false ) ;
while ( ! F_28 ( & V_56 ) ) {
V_57 = F_29 ( & V_56 ) ;
V_43 = F_30 ( V_2 , V_57 ) ;
if ( V_43 )
F_4 ( V_6 -> V_23 ,
L_7 ) ;
}
return 0 ;
} else if ( V_44 == V_61 ) {
V_43 = F_31 ( V_2 , V_4 ) ;
if ( V_43 )
F_4 ( V_6 -> V_23 , L_8 ) ;
F_19 ( V_4 ) ;
return V_43 ;
}
memcpy ( V_45 , V_10 -> V_26 . V_62 , V_18 ) ;
if ( V_44 != V_63 && V_8 -> V_64 < V_65 ) {
V_48 = F_22 ( V_2 , V_45 ) ;
if ( V_48 )
V_48 -> V_66 [ V_8 -> V_64 ] =
F_2 ( V_8 -> V_67 ) ;
}
if ( ! V_2 -> V_68 ||
( ! F_32 ( V_2 , V_8 -> V_64 , V_45 ) &&
( F_2 ( V_8 -> V_44 ) != V_54 ) ) ) {
V_43 = F_18 ( V_2 , V_4 ) ;
return V_43 ;
}
V_46 = ( T_1 ) F_2 ( V_8 -> V_44 ) ;
V_43 = F_33 ( V_2 , F_2 ( V_8 -> V_67 ) ,
V_8 -> V_64 , V_45 , V_46 ,
V_4 ) ;
if ( V_43 || ( V_44 == V_63 ) ) {
if ( V_6 -> V_52 . V_53 )
V_6 -> V_52 . V_53 ( V_6 , V_4 ) ;
else
F_19 ( V_4 ) ;
}
if ( V_43 )
V_2 -> V_28 . V_51 ++ ;
return V_43 ;
}
void * F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_69 * V_70 ;
struct V_12 * V_13 = F_11 ( V_4 ) ;
int V_71 , V_50 ;
T_2 V_46 ;
if ( ! V_4 -> V_50 ) {
F_4 ( V_6 -> V_23 , L_9 , V_4 -> V_50 ) ;
V_13 -> V_72 = - 1 ;
return V_4 -> V_19 ;
}
V_46 = F_35 ( V_4 ) ? V_61 : 0 ;
V_71 = ( 4 - ( ( ( void * ) V_4 -> V_19 - NULL ) & 0x3 ) ) % 4 ;
V_50 = sizeof( * V_70 ) + V_71 ;
F_36 ( F_7 ( V_4 ) < V_50 + V_73 ) ;
F_37 ( V_4 , V_50 ) ;
V_70 = (struct V_69 * ) V_4 -> V_19 ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
V_70 -> V_30 = V_2 -> V_30 ;
V_70 -> V_31 = V_2 -> V_31 ;
V_70 -> V_74 = F_38 ( ( T_2 ) ( V_4 -> V_50 - V_50 ) ) ;
V_70 -> V_64 = ( T_1 ) V_4 -> V_64 ;
V_70 -> V_75 = F_39 ( V_2 , V_4 ) ;
if ( V_70 -> V_64 < F_40 ( V_2 -> V_76 . V_77 ) )
V_70 -> V_78 =
F_41 ( V_2 -> V_76 . V_77 [ V_70 -> V_64 ] ) ;
if ( V_46 == V_61 ) {
V_70 -> V_79 = F_38 ( V_46 ) ;
V_50 += V_80 ;
}
V_70 -> V_81 = F_38 ( V_50 ) ;
F_37 ( V_4 , V_73 ) ;
if ( ! V_70 -> V_78 )
V_70 -> V_78 = F_41 ( V_2 -> V_82 ) ;
return V_4 -> V_19 ;
}
