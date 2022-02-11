static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
T_2 V_8 ;
V_7 = F_2 ( V_2 -> V_9 , V_2 -> V_10 ) ;
if ( F_3 ( ! V_7 ) )
return - V_11 ;
V_8 = F_4 ( V_2 -> V_12 ,
V_7 -> V_13 ,
V_2 -> V_10 ,
V_14 ) ;
if ( F_3 ( F_5 ( V_2 -> V_12 , V_8 ) ) )
goto V_15;
F_6 ( V_7 , V_16 ) ;
* ( ( T_2 * ) V_7 -> V_17 ) = V_8 ;
V_4 -> V_13 . V_18 = F_7 ( V_8 + V_16 ) ;
V_2 -> V_7 [ V_5 ] = V_7 ;
return 0 ;
V_15:
F_8 ( V_7 ) ;
return - V_11 ;
}
bool F_9 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
if ( F_3 ( ! F_10 ( V_21 , & V_2 -> V_22 ) ) )
return false ;
while ( ! F_11 ( V_20 ) ) {
struct V_3 * V_4 = F_12 ( V_20 , V_20 -> V_23 ) ;
if ( F_3 ( F_1 ( V_2 , V_4 , V_20 -> V_23 ) ) )
break;
F_13 ( V_20 , F_14 ( V_4 -> V_24 . V_25 ) ) ;
}
F_15 () ;
F_16 ( V_20 ) ;
return ! F_11 ( V_20 ) ;
}
static void F_17 ( struct V_6 * V_7 , struct V_26 * V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) ( V_7 -> V_13 ) ;
struct V_30 * V_31 = (struct V_30 * ) ( V_7 -> V_13 + V_32 ) ;
struct V_33 * V_34 = (struct V_33 * ) ( V_7 -> V_13 + V_32 ) ;
struct V_35 * V_36 ;
T_3 V_37 = F_18 ( V_27 ) ;
int V_38 = ( ( V_39 == V_37 ) ||
( V_40 == V_37 ) ) ;
T_1 V_41 = F_19 ( V_27 -> V_42 ) - V_32 ;
if ( V_29 -> V_43 == F_20 ( V_44 ) ) {
V_36 = (struct V_35 * ) ( V_7 -> V_13 + V_32 +
sizeof( struct V_30 ) ) ;
V_34 = NULL ;
} else {
V_36 = (struct V_35 * ) ( V_7 -> V_13 + V_32 +
sizeof( struct V_33 ) ) ;
V_31 = NULL ;
}
if ( F_21 ( V_27 ) )
V_36 -> V_45 = 1 ;
if ( V_38 ) {
V_36 -> V_46 = 1 ;
V_36 -> V_47 = V_27 -> V_48 ;
V_36 -> V_49 = V_27 -> V_50 ;
}
if ( V_31 ) {
V_31 -> V_51 = V_27 -> V_52 ;
V_31 -> V_41 = F_22 ( V_41 ) ;
V_31 -> V_53 = 0 ;
V_31 -> V_53 = F_23 ( ( unsigned char * ) V_31 ,
V_31 -> V_54 ) ;
} else {
V_34 -> V_55 = V_27 -> V_52 ;
V_34 -> V_56 = F_22 ( V_41 -
sizeof( struct V_33 ) ) ;
}
}
static inline void F_24 ( struct V_26 * V_27 ,
struct V_6 * V_7 )
{
T_3 V_57 = V_27 -> V_58 ;
int V_59 = ( V_57 & V_60 ) ? V_61 :
( V_57 & V_62 ) ? V_63 :
V_64 ;
F_25 ( V_7 , F_19 ( V_27 -> V_65 ) , V_59 ) ;
}
static inline void F_26 ( struct V_26 * V_27 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_66 * V_9 = V_2 -> V_9 ;
T_4 V_67 = F_19 ( V_27 -> V_42 ) ;
int V_68 ;
F_27 ( V_7 , V_67 ) ;
V_68 = F_19 ( V_27 -> V_69 ) >> 24 ;
if ( V_68 > 1 ) {
F_17 ( V_7 , V_27 ) ;
F_28 ( V_7 ) -> V_70 = V_71 ;
V_2 -> V_72 . V_73 ++ ;
V_2 -> V_72 . V_74 += V_67 ;
}
if ( F_29 ( V_9 -> V_75 & V_76 ) &&
( V_27 -> V_77 & V_78 ) &&
( V_27 -> V_77 & V_79 ) &&
( V_27 -> V_77 & V_80 ) ) {
V_7 -> V_81 = V_82 ;
} else {
V_7 -> V_81 = V_83 ;
V_2 -> V_72 . V_84 ++ ;
}
V_7 -> V_85 = F_30 ( V_7 , V_9 ) ;
F_31 ( V_7 , V_2 -> V_5 ) ;
if ( F_29 ( V_9 -> V_75 & V_86 ) )
F_24 ( V_27 , V_7 ) ;
if ( F_32 ( V_27 ) )
F_33 ( V_7 , F_20 ( V_87 ) ,
F_14 ( V_27 -> V_88 ) ) ;
}
bool F_34 ( struct V_89 * V_90 , int V_91 )
{
struct V_1 * V_2 = F_35 ( V_90 , struct V_1 , V_90 ) ;
int V_92 ;
if ( ! F_36 ( V_93 , & V_90 -> V_94 ) )
return false ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
struct V_3 * V_4 ;
struct V_26 * V_27 ;
struct V_6 * V_7 ;
T_5 V_95 ;
T_1 V_96 ;
V_27 = F_37 ( V_90 ) ;
if ( ! V_27 )
break;
F_38 ( & V_90 -> V_20 ) ;
V_95 = V_27 -> V_96 ;
V_96 = F_14 ( V_95 ) ;
V_4 = F_12 ( & V_2 -> V_20 , V_96 ) ;
V_7 = V_2 -> V_7 [ V_96 ] ;
F_39 ( V_7 -> V_13 ) ;
V_2 -> V_7 [ V_96 ] = NULL ;
F_40 ( V_2 -> V_12 ,
* ( ( T_2 * ) V_7 -> V_17 ) ,
V_2 -> V_10 ,
V_14 ) ;
if ( F_3 ( ( V_27 -> V_97 >> 4 ) != V_98 ) ) {
V_2 -> V_72 . V_99 ++ ;
F_8 ( V_7 ) ;
goto V_100;
}
F_26 ( V_27 , V_2 , V_7 ) ;
V_2 -> V_72 . V_101 ++ ;
F_41 ( V_90 -> V_102 , V_7 ) ;
V_100:
F_42 ( & V_2 -> V_20 , V_95 ,
& V_4 -> V_24 . V_25 ) ;
}
F_43 ( & V_90 -> V_20 ) ;
F_44 () ;
if ( V_92 == V_91 ) {
F_45 ( V_93 , & V_90 -> V_94 ) ;
return true ;
}
return false ;
}
