static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_5 ;
}
static inline int F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 V_10 )
{
struct V_11 * V_12 ;
T_2 V_13 ;
V_12 = F_3 ( V_7 -> V_14 , V_7 -> V_15 ) ;
if ( F_4 ( ! V_12 ) )
return - V_16 ;
V_13 = F_5 ( V_7 -> V_17 ,
V_12 -> V_18 ,
V_7 -> V_15 ,
V_19 ) ;
if ( F_4 ( F_6 ( V_7 -> V_17 , V_13 ) ) )
goto V_20;
F_7 ( V_12 , V_21 ) ;
* ( ( T_2 * ) V_12 -> V_22 ) = V_13 ;
V_9 -> V_18 . V_23 = F_8 ( V_13 + V_21 ) ;
V_7 -> V_12 [ V_10 ] = V_12 ;
return 0 ;
V_20:
F_9 ( V_12 ) ;
return - V_16 ;
}
bool F_10 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = & V_7 -> V_25 ;
if ( F_4 ( ! F_11 ( V_26 , & V_7 -> V_27 ) ) )
return false ;
while ( ! F_12 ( V_25 ) ) {
struct V_8 * V_9 = F_13 ( V_25 , V_25 -> V_28 ) ;
if ( F_4 ( F_2 ( V_7 , V_9 , V_25 -> V_28 ) ) )
break;
F_14 ( V_25 , F_15 ( V_9 -> V_29 . V_30 ) ) ;
}
F_16 () ;
F_17 ( V_25 ) ;
return ! F_12 ( V_25 ) ;
}
static void F_18 ( struct V_11 * V_12 , struct V_31 * V_32 )
{
struct V_33 * V_34 = (struct V_33 * ) ( V_12 -> V_18 ) ;
struct V_35 * V_36 = (struct V_35 * ) ( V_12 -> V_18 + V_37 ) ;
struct V_38 * V_39 = (struct V_38 * ) ( V_12 -> V_18 + V_37 ) ;
struct V_40 * V_41 ;
T_3 V_42 = F_19 ( V_32 ) ;
int V_43 = ( ( V_44 == V_42 ) ||
( V_45 == V_42 ) ) ;
T_1 V_46 = F_20 ( V_32 -> V_47 ) - V_37 ;
if ( V_34 -> V_48 == F_21 ( V_49 ) ) {
V_41 = (struct V_40 * ) ( V_12 -> V_18 + V_37 +
sizeof( struct V_35 ) ) ;
V_39 = NULL ;
F_22 ( V_12 ) -> V_50 = V_51 ;
} else {
V_41 = (struct V_40 * ) ( V_12 -> V_18 + V_37 +
sizeof( struct V_38 ) ) ;
V_36 = NULL ;
F_22 ( V_12 ) -> V_50 = V_52 ;
}
if ( F_23 ( V_32 ) )
V_41 -> V_53 = 1 ;
if ( V_43 ) {
V_41 -> V_54 = 1 ;
V_41 -> V_55 = V_32 -> V_56 ;
V_41 -> V_57 = V_32 -> V_58 ;
}
if ( V_36 ) {
V_36 -> V_59 = V_32 -> V_60 ;
V_36 -> V_46 = F_24 ( V_46 ) ;
V_36 -> V_61 = 0 ;
V_36 -> V_61 = F_25 ( ( unsigned char * ) V_36 ,
V_36 -> V_62 ) ;
} else {
V_39 -> V_63 = V_32 -> V_60 ;
V_39 -> V_64 = F_24 ( V_46 -
sizeof( struct V_38 ) ) ;
}
}
static inline void F_26 ( struct V_31 * V_32 ,
struct V_11 * V_12 )
{
T_3 V_65 = V_32 -> V_66 ;
int V_67 = ( V_65 & V_68 ) ? V_69 :
( V_65 & V_70 ) ? V_71 :
V_72 ;
F_27 ( V_12 , F_20 ( V_32 -> V_73 ) , V_67 ) ;
}
static inline bool F_28 ( struct V_11 * V_12 )
{
T_4 V_74 = ( (struct V_33 * ) V_12 -> V_18 ) -> V_48 ;
return ( V_74 == F_21 ( V_49 ) || V_74 == F_21 ( V_75 ) ) ;
}
static inline void F_29 ( struct V_76 * V_14 ,
struct V_31 * V_32 ,
struct V_6 * V_7 ,
struct V_11 * V_12 ,
bool V_77 )
{
if ( F_4 ( ! ( V_14 -> V_78 & V_79 ) ) )
goto V_80;
if ( V_77 ) {
V_12 -> V_81 = V_82 ;
} else if ( F_30 ( F_28 ( V_12 ) ) ) {
V_12 -> V_81 = V_83 ;
V_12 -> V_84 = F_31 ( ( V_85 V_86 ) V_32 -> V_87 ) ;
V_7 -> V_88 . V_89 ++ ;
} else {
goto V_80;
}
return;
V_80:
V_12 -> V_81 = V_90 ;
V_7 -> V_88 . V_80 ++ ;
}
static inline void F_32 ( struct V_31 * V_32 ,
struct V_6 * V_7 ,
struct V_11 * V_12 )
{
struct V_76 * V_14 = V_7 -> V_14 ;
T_5 V_91 = F_20 ( V_32 -> V_47 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_92 ;
F_33 ( V_12 , V_91 ) ;
V_92 = F_20 ( V_32 -> V_93 ) >> 24 ;
if ( V_92 > 1 ) {
F_18 ( V_12 , V_32 ) ;
F_22 ( V_12 ) -> V_94 = F_34 ( V_91 , V_92 ) ;
V_7 -> V_88 . V_95 ++ ;
V_7 -> V_88 . V_96 += V_91 ;
}
if ( F_4 ( F_1 ( V_2 ) ) )
F_35 ( V_2 , F_36 ( V_32 ) , F_37 ( V_12 ) ) ;
F_29 ( V_14 , V_32 , V_7 , V_12 , ! ! V_92 ) ;
V_12 -> V_97 = F_38 ( V_12 , V_14 ) ;
F_39 ( V_12 , V_7 -> V_10 ) ;
if ( F_30 ( V_14 -> V_78 & V_98 ) )
F_26 ( V_32 , V_12 ) ;
if ( F_40 ( V_32 ) )
F_41 ( V_12 , F_21 ( V_99 ) ,
F_15 ( V_32 -> V_100 ) ) ;
V_12 -> V_101 = F_20 ( V_32 -> V_102 ) & V_103 ;
}
int F_42 ( struct V_104 * V_105 , int V_106 )
{
struct V_6 * V_7 = F_43 ( V_105 , struct V_6 , V_105 ) ;
int V_107 ;
for ( V_107 = 0 ; V_107 < V_106 ; V_107 ++ ) {
struct V_8 * V_9 ;
struct V_31 * V_32 ;
struct V_11 * V_12 ;
T_4 V_108 ;
T_1 V_109 ;
V_32 = F_44 ( V_105 ) ;
if ( ! V_32 )
break;
F_45 ( & V_105 -> V_25 ) ;
V_108 = V_32 -> V_109 ;
V_109 = F_15 ( V_108 ) ;
V_9 = F_13 ( & V_7 -> V_25 , V_109 ) ;
V_12 = V_7 -> V_12 [ V_109 ] ;
F_46 ( V_12 -> V_18 ) ;
V_7 -> V_12 [ V_109 ] = NULL ;
F_47 ( V_7 -> V_17 ,
* ( ( T_2 * ) V_12 -> V_22 ) ,
V_7 -> V_15 ,
V_19 ) ;
if ( F_4 ( ( V_32 -> V_110 >> 4 ) != V_111 ) ) {
V_7 -> V_88 . V_112 ++ ;
F_9 ( V_12 ) ;
goto V_113;
}
F_32 ( V_32 , V_7 , V_12 ) ;
V_7 -> V_88 . V_114 ++ ;
V_7 -> V_88 . V_115 += F_20 ( V_32 -> V_47 ) ;
F_48 ( V_105 -> V_116 , V_12 ) ;
V_113:
F_49 ( & V_7 -> V_25 , V_108 ,
& V_9 -> V_29 . V_30 ) ;
}
F_50 ( & V_105 -> V_25 ) ;
F_51 () ;
return V_107 ;
}
