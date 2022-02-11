void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
T_1 V_9 ;
T_1 V_10 ;
F_2 ( & V_2 -> V_11 , V_8 ) ;
V_7 = V_2 -> V_12 ;
V_9 = V_7 -> V_9 ;
if ( V_9 >= ( unsigned ) V_2 -> V_13 . V_14 ) {
V_9 = V_2 -> V_13 . V_14 ;
V_10 = 0 ;
} else
V_10 = V_9 + 1 ;
if ( F_3 ( V_10 == V_7 -> V_15 ) ) {
F_4 ( & V_2 -> V_11 , V_8 ) ;
if ( V_2 -> V_13 . V_16 ) {
struct V_17 V_18 ;
V_18 . V_19 = V_2 -> V_13 . V_19 ;
V_18 . V_20 . V_2 = & V_2 -> V_13 ;
V_18 . V_21 = V_22 ;
V_2 -> V_13 . V_16 ( & V_18 , V_2 -> V_13 . V_23 ) ;
}
return;
}
if ( V_2 -> V_24 ) {
V_7 -> V_25 [ V_9 ] . V_26 = V_4 -> V_26 ;
V_7 -> V_25 [ V_9 ] . V_27 = V_4 -> V_27 ;
V_7 -> V_25 [ V_9 ] . V_28 = V_4 -> V_28 ;
V_7 -> V_25 [ V_9 ] . V_29 = V_4 -> V_29 ;
V_7 -> V_25 [ V_9 ] . V_30 = V_4 -> V_30 ;
V_7 -> V_25 [ V_9 ] . V_31 . V_32 = ( V_33 V_34 ) V_4 -> V_31 . V_32 ;
V_7 -> V_25 [ V_9 ] . V_35 = V_4 -> V_36 -> V_35 ;
V_7 -> V_25 [ V_9 ] . V_37 = V_4 -> V_37 ;
V_7 -> V_25 [ V_9 ] . V_38 = V_4 -> V_38 ;
V_7 -> V_25 [ V_9 ] . V_39 = V_4 -> V_39 ;
V_7 -> V_25 [ V_9 ] . V_40 = V_4 -> V_40 ;
V_7 -> V_25 [ V_9 ] . V_41 = V_4 -> V_41 ;
V_7 -> V_25 [ V_9 ] . V_42 = V_4 -> V_42 ;
V_7 -> V_25 [ V_9 ] . V_43 = V_4 -> V_43 ;
F_5 () ;
} else
V_7 -> V_44 [ V_9 ] = * V_4 ;
V_7 -> V_9 = V_10 ;
if ( V_2 -> V_45 == V_46 ||
( V_2 -> V_45 == V_47 && V_5 ) ) {
V_2 -> V_45 = V_48 ;
V_2 -> V_49 ++ ;
F_6 ( & V_2 -> V_50 ) ;
}
F_4 ( & V_2 -> V_11 , V_8 ) ;
if ( V_4 -> V_27 != V_51 )
F_7 ( V_2 -> V_13 . V_19 ) -> V_52 ++ ;
}
int F_8 ( struct V_53 * V_13 , int V_54 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_55 ;
T_1 V_15 ;
if ( V_2 -> V_24 ) {
V_55 = - V_56 ;
goto V_57;
}
F_2 ( & V_2 -> V_11 , V_8 ) ;
V_7 = V_2 -> V_12 ;
V_15 = V_7 -> V_15 ;
if ( V_15 > ( T_1 ) V_2 -> V_13 . V_14 )
V_15 = ( T_1 ) V_2 -> V_13 . V_14 ;
for ( V_55 = 0 ; V_55 < V_54 ; ++ V_55 , ++ V_4 ) {
if ( V_15 == V_7 -> V_9 )
break;
* V_4 = V_7 -> V_44 [ V_15 ] ;
if ( V_15 >= V_2 -> V_13 . V_14 )
V_15 = 0 ;
else
V_15 ++ ;
}
V_7 -> V_15 = V_15 ;
F_4 ( & V_2 -> V_11 , V_8 ) ;
V_57:
return V_55 ;
}
static void F_10 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
for (; ; ) {
T_2 V_49 = V_2 -> V_49 ;
V_2 -> V_13 . V_59 ( & V_2 -> V_13 , V_2 -> V_13 . V_23 ) ;
if ( V_2 -> V_49 == V_49 )
return;
}
}
struct V_53 * F_11 ( struct V_60 * V_61 , int V_62 , int V_63 ,
struct V_64 * V_65 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 = F_7 ( V_61 ) ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_53 * V_70 ;
T_1 V_71 ;
if ( V_62 < 1 || V_62 > V_72 ) {
V_70 = F_12 ( - V_56 ) ;
goto V_73;
}
V_2 = F_13 ( sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 ) {
V_70 = F_12 ( - V_75 ) ;
goto V_73;
}
V_71 = sizeof( * V_7 ) ;
if ( V_67 && V_67 -> V_76 >= sizeof( V_77 ) )
V_71 += sizeof( struct V_78 ) * ( V_62 + 1 ) ;
else
V_71 += sizeof( struct V_3 ) * ( V_62 + 1 ) ;
V_7 = F_14 ( V_71 ) ;
if ( ! V_7 ) {
V_70 = F_12 ( - V_75 ) ;
goto V_79;
}
if ( V_67 && V_67 -> V_76 >= sizeof( V_77 ) ) {
int V_80 ;
V_2 -> V_24 = F_15 ( V_69 , V_71 , V_65 , V_7 ) ;
if ( ! V_2 -> V_24 ) {
V_70 = F_12 ( - V_75 ) ;
goto V_81;
}
V_80 = F_16 ( V_67 , & V_2 -> V_24 -> V_82 ,
sizeof( V_2 -> V_24 -> V_82 ) ) ;
if ( V_80 ) {
V_70 = F_12 ( V_80 ) ;
goto V_83;
}
} else
V_2 -> V_24 = NULL ;
F_17 ( & V_69 -> V_84 ) ;
if ( V_69 -> V_85 == V_86 ) {
F_18 ( & V_69 -> V_84 ) ;
V_70 = F_12 ( - V_75 ) ;
goto V_83;
}
V_69 -> V_85 ++ ;
F_18 ( & V_69 -> V_84 ) ;
if ( V_2 -> V_24 ) {
F_19 ( & V_69 -> V_87 ) ;
F_20 ( & V_2 -> V_24 -> V_88 , & V_69 -> V_88 ) ;
F_21 ( & V_69 -> V_87 ) ;
}
V_2 -> V_13 . V_14 = V_62 ;
V_2 -> V_45 = V_48 ;
V_2 -> V_49 = 0 ;
F_22 ( & V_2 -> V_11 ) ;
F_23 ( & V_2 -> V_50 , F_10 , ( unsigned long ) V_2 ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_15 = 0 ;
V_2 -> V_12 = V_7 ;
V_70 = & V_2 -> V_13 ;
goto V_73;
V_83:
F_24 ( V_2 -> V_24 ) ;
V_81:
F_25 ( V_7 ) ;
V_79:
F_24 ( V_2 ) ;
V_73:
return V_70 ;
}
int F_26 ( struct V_53 * V_13 )
{
struct V_68 * V_69 = F_7 ( V_13 -> V_19 ) ;
struct V_1 * V_2 = F_9 ( V_13 ) ;
F_27 ( & V_2 -> V_50 ) ;
F_17 ( & V_69 -> V_84 ) ;
V_69 -> V_85 -- ;
F_18 ( & V_69 -> V_84 ) ;
if ( V_2 -> V_24 )
F_28 ( & V_2 -> V_24 -> V_89 , V_90 ) ;
else
F_25 ( V_2 -> V_12 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
int F_29 ( struct V_53 * V_13 , enum V_91 V_92 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
unsigned long V_8 ;
int V_70 = 0 ;
F_2 ( & V_2 -> V_11 , V_8 ) ;
if ( V_2 -> V_45 != V_46 )
V_2 -> V_45 = V_92 & V_93 ;
if ( ( V_92 & V_94 ) &&
V_2 -> V_12 -> V_9 != V_2 -> V_12 -> V_15 )
V_70 = 1 ;
F_4 ( & V_2 -> V_11 , V_8 ) ;
return V_70 ;
}
int F_30 ( struct V_53 * V_13 , int V_14 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_6 * V_95 ;
struct V_6 * V_7 ;
T_1 V_9 , V_15 , V_96 ;
int V_70 ;
T_1 V_71 ;
if ( V_14 < 1 || V_14 > V_72 ) {
V_70 = - V_56 ;
goto V_57;
}
V_71 = sizeof( * V_7 ) ;
if ( V_67 && V_67 -> V_76 >= sizeof( V_77 ) )
V_71 += sizeof( struct V_78 ) * ( V_14 + 1 ) ;
else
V_71 += sizeof( struct V_3 ) * ( V_14 + 1 ) ;
V_7 = F_14 ( V_71 ) ;
if ( ! V_7 ) {
V_70 = - V_75 ;
goto V_57;
}
if ( V_67 && V_67 -> V_76 >= sizeof( V_77 ) ) {
V_77 V_82 = 0 ;
V_70 = F_16 ( V_67 , & V_82 , sizeof( V_82 ) ) ;
if ( V_70 )
goto V_97;
}
F_19 ( & V_2 -> V_11 ) ;
V_95 = V_2 -> V_12 ;
V_9 = V_95 -> V_9 ;
if ( V_9 > ( T_1 ) V_2 -> V_13 . V_14 )
V_9 = ( T_1 ) V_2 -> V_13 . V_14 ;
V_15 = V_95 -> V_15 ;
if ( V_15 > ( T_1 ) V_2 -> V_13 . V_14 )
V_15 = ( T_1 ) V_2 -> V_13 . V_14 ;
if ( V_9 < V_15 )
V_96 = V_2 -> V_13 . V_14 + 1 + V_9 - V_15 ;
else
V_96 = V_9 - V_15 ;
if ( F_3 ( ( T_1 ) V_14 < V_96 ) ) {
V_70 = - V_56 ;
goto V_98;
}
for ( V_96 = 0 ; V_15 != V_9 ; V_96 ++ ) {
if ( V_2 -> V_24 )
V_7 -> V_25 [ V_96 ] = V_95 -> V_25 [ V_15 ] ;
else
V_7 -> V_44 [ V_96 ] = V_95 -> V_44 [ V_15 ] ;
if ( V_15 == ( T_1 ) V_2 -> V_13 . V_14 )
V_15 = 0 ;
else
V_15 ++ ;
}
V_2 -> V_13 . V_14 = V_14 ;
V_7 -> V_9 = V_96 ;
V_7 -> V_15 = 0 ;
V_2 -> V_12 = V_7 ;
F_21 ( & V_2 -> V_11 ) ;
F_25 ( V_95 ) ;
if ( V_2 -> V_24 ) {
struct V_68 * V_69 = F_7 ( V_13 -> V_19 ) ;
struct V_99 * V_24 = V_2 -> V_24 ;
F_31 ( V_69 , V_24 , V_71 , V_7 ) ;
if ( V_67 && V_67 -> V_76 >= sizeof( V_77 ) ) {
V_70 = F_16 ( V_67 , & V_24 -> V_82 ,
sizeof( V_24 -> V_82 ) ) ;
if ( V_70 )
goto V_57;
}
F_19 ( & V_69 -> V_87 ) ;
if ( F_32 ( & V_24 -> V_88 ) )
F_20 ( & V_24 -> V_88 , & V_69 -> V_88 ) ;
F_21 ( & V_69 -> V_87 ) ;
}
V_70 = 0 ;
goto V_57;
V_98:
F_21 ( & V_2 -> V_11 ) ;
V_97:
F_25 ( V_7 ) ;
V_57:
return V_70 ;
}
