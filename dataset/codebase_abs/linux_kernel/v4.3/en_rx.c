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
F_21 ( V_7 ) -> V_45 = V_46 ;
} else {
V_36 = (struct V_35 * ) ( V_7 -> V_13 + V_32 +
sizeof( struct V_33 ) ) ;
V_31 = NULL ;
F_21 ( V_7 ) -> V_45 = V_47 ;
}
if ( F_22 ( V_27 ) )
V_36 -> V_48 = 1 ;
if ( V_38 ) {
V_36 -> V_49 = 1 ;
V_36 -> V_50 = V_27 -> V_51 ;
V_36 -> V_52 = V_27 -> V_53 ;
}
if ( V_31 ) {
V_31 -> V_54 = V_27 -> V_55 ;
V_31 -> V_41 = F_23 ( V_41 ) ;
V_31 -> V_56 = 0 ;
V_31 -> V_56 = F_24 ( ( unsigned char * ) V_31 ,
V_31 -> V_57 ) ;
} else {
V_34 -> V_58 = V_27 -> V_55 ;
V_34 -> V_59 = F_23 ( V_41 -
sizeof( struct V_33 ) ) ;
}
}
static inline void F_25 ( struct V_26 * V_27 ,
struct V_6 * V_7 )
{
T_3 V_60 = V_27 -> V_61 ;
int V_62 = ( V_60 & V_63 ) ? V_64 :
( V_60 & V_65 ) ? V_66 :
V_67 ;
F_26 ( V_7 , F_19 ( V_27 -> V_68 ) , V_62 ) ;
}
static inline bool F_27 ( struct V_6 * V_7 )
{
T_4 V_69 = ( (struct V_28 * ) V_7 -> V_13 ) -> V_43 ;
return ( V_69 == F_20 ( V_44 ) || V_69 == F_20 ( V_70 ) ) ;
}
static inline void F_28 ( struct V_71 * V_9 ,
struct V_26 * V_27 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
if ( F_3 ( ! ( V_9 -> V_72 & V_73 ) ) )
goto V_74;
if ( F_29 ( V_27 -> V_75 & V_76 ) ) {
V_7 -> V_77 = V_78 ;
} else if ( F_27 ( V_7 ) ) {
V_7 -> V_77 = V_79 ;
V_7 -> V_80 = F_30 ( ( V_81 V_82 ) V_27 -> V_83 ) ;
V_2 -> V_84 . V_85 ++ ;
} else {
goto V_74;
}
return;
V_74:
V_7 -> V_77 = V_86 ;
V_2 -> V_84 . V_74 ++ ;
}
static inline void F_31 ( struct V_26 * V_27 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_71 * V_9 = V_2 -> V_9 ;
T_5 V_87 = F_19 ( V_27 -> V_42 ) ;
int V_88 ;
F_32 ( V_7 , V_87 ) ;
V_88 = F_19 ( V_27 -> V_89 ) >> 24 ;
if ( V_88 > 1 ) {
F_17 ( V_7 , V_27 ) ;
F_21 ( V_7 ) -> V_90 = F_33 ( V_87 , V_88 ) ;
V_2 -> V_84 . V_91 ++ ;
V_2 -> V_84 . V_92 += V_87 ;
}
F_28 ( V_9 , V_27 , V_2 , V_7 ) ;
V_7 -> V_93 = F_34 ( V_7 , V_9 ) ;
F_35 ( V_7 , V_2 -> V_5 ) ;
if ( F_29 ( V_9 -> V_72 & V_94 ) )
F_25 ( V_27 , V_7 ) ;
if ( F_36 ( V_27 ) )
F_37 ( V_7 , F_20 ( V_95 ) ,
F_14 ( V_27 -> V_96 ) ) ;
}
bool F_38 ( struct V_97 * V_98 , int V_99 )
{
struct V_1 * V_2 = F_39 ( V_98 , struct V_1 , V_98 ) ;
int V_100 ;
if ( ! F_40 ( V_101 , & V_98 -> V_102 ) )
return false ;
for ( V_100 = 0 ; V_100 < V_99 ; V_100 ++ ) {
struct V_3 * V_4 ;
struct V_26 * V_27 ;
struct V_6 * V_7 ;
T_4 V_103 ;
T_1 V_104 ;
V_27 = F_41 ( V_98 ) ;
if ( ! V_27 )
break;
F_42 ( & V_98 -> V_20 ) ;
V_103 = V_27 -> V_104 ;
V_104 = F_14 ( V_103 ) ;
V_4 = F_12 ( & V_2 -> V_20 , V_104 ) ;
V_7 = V_2 -> V_7 [ V_104 ] ;
F_43 ( V_7 -> V_13 ) ;
V_2 -> V_7 [ V_104 ] = NULL ;
F_44 ( V_2 -> V_12 ,
* ( ( T_2 * ) V_7 -> V_17 ) ,
V_2 -> V_10 ,
V_14 ) ;
if ( F_3 ( ( V_27 -> V_105 >> 4 ) != V_106 ) ) {
V_2 -> V_84 . V_107 ++ ;
F_8 ( V_7 ) ;
goto V_108;
}
F_31 ( V_27 , V_2 , V_7 ) ;
V_2 -> V_84 . V_109 ++ ;
F_45 ( V_98 -> V_110 , V_7 ) ;
V_108:
F_46 ( & V_2 -> V_20 , V_103 ,
& V_4 -> V_24 . V_25 ) ;
}
F_47 ( & V_98 -> V_20 ) ;
F_48 () ;
if ( V_100 == V_99 ) {
F_49 ( V_101 , & V_98 -> V_102 ) ;
return true ;
}
return false ;
}
