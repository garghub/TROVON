static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
V_4 -> V_8 = F_3 ( & V_4 -> V_9 -> V_2 ,
( V_10 *
sizeof( struct V_11 ) ) ,
& V_4 -> V_12 , V_13 ) ;
if ( ! V_4 -> V_8 )
return - V_14 ;
V_4 -> V_15 = F_3 ( & V_4 -> V_9 -> V_2 ,
V_10 * V_16 ,
& V_4 -> V_17 , V_13 ) ;
if ( ! V_4 -> V_15 ) {
F_4 ( & V_4 -> V_9 -> V_2 ,
V_10 * sizeof( struct V_11 ) ,
V_4 -> V_8 , V_4 -> V_12 ) ;
V_4 -> V_8 = NULL ;
return - V_14 ;
}
V_5 = V_4 -> V_17 ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
V_4 -> V_8 [ V_7 ] . V_5 = V_5 ;
V_4 -> V_8 [ V_7 ] . V_18 = 0 ;
V_5 += V_16 ;
}
V_4 -> V_8 [ V_10 - 1 ] . V_5 |= F_5 ( V_19 ) ;
V_4 -> V_20 = 0 ;
F_6 ( V_4 , V_21 , V_4 -> V_12 ) ;
V_6 = F_7 ( V_4 , V_22 ) ;
F_6 ( V_4 , V_22 , V_6 | F_5 ( V_23 ) | F_5 ( V_24 ) ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_6 ;
int V_25 ;
V_6 = F_7 ( V_4 , V_22 ) ;
F_6 ( V_4 , V_22 , V_6 | F_5 ( V_26 ) ) ;
F_9 ( V_4 ) ;
V_25 = F_1 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_6 ( V_4 , V_27 , F_5 ( V_28 ) |
F_5 ( V_29 ) |
F_5 ( V_30 ) |
F_5 ( V_31 ) |
F_5 ( V_32 ) |
F_5 ( V_33 ) |
F_5 ( V_34 ) ) ;
F_10 ( V_4 -> V_35 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_7 ( V_4 , V_22 ) ;
F_6 ( V_4 , V_22 , V_6 & ~ ( F_5 ( V_24 ) | F_5 ( V_23 ) ) ) ;
F_6 ( V_4 , V_36 , F_5 ( V_28 ) |
F_5 ( V_29 ) |
F_5 ( V_30 ) |
F_5 ( V_31 ) |
F_5 ( V_32 ) |
F_5 ( V_33 ) |
F_5 ( V_34 ) ) ;
F_13 ( V_2 ) ;
F_4 ( & V_4 -> V_9 -> V_2 ,
V_10 * sizeof( struct V_11 ) ,
V_4 -> V_8 , V_4 -> V_12 ) ;
V_4 -> V_8 = NULL ;
F_4 ( & V_4 -> V_9 -> V_2 ,
V_10 * V_16 ,
V_4 -> V_15 , V_4 -> V_17 ) ;
V_4 -> V_15 = NULL ;
return 0 ;
}
static int F_14 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_7 ( V_4 , V_39 ) & F_5 ( V_40 ) ) {
F_13 ( V_2 ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_41 = V_38 -> V_42 ;
V_4 -> V_43 = F_15 ( NULL , V_38 -> V_44 , V_38 -> V_42 ,
V_45 ) ;
F_6 ( V_4 , V_46 , V_4 -> V_43 ) ;
F_6 ( V_4 , V_47 , V_38 -> V_42 ) ;
} else {
F_16 ( V_2 , L_1 , V_48 ) ;
return V_49 ;
}
return V_50 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char * V_51 ;
struct V_37 * V_38 ;
unsigned int V_52 ;
while ( V_4 -> V_8 [ V_4 -> V_20 ] . V_5 & F_5 ( V_53 ) ) {
V_51 = V_4 -> V_15 + V_4 -> V_20 * V_16 ;
V_52 = F_18 ( V_54 , V_4 -> V_8 [ V_4 -> V_20 ] . V_18 ) ;
V_38 = F_19 ( V_2 , V_52 + 2 ) ;
if ( V_38 ) {
F_20 ( V_38 , 2 ) ;
memcpy ( F_21 ( V_38 , V_52 ) , V_51 , V_52 ) ;
V_38 -> V_55 = F_22 ( V_38 , V_2 ) ;
V_4 -> V_56 . V_57 ++ ;
V_4 -> V_56 . V_58 += V_52 ;
F_23 ( V_38 ) ;
} else {
V_4 -> V_56 . V_59 ++ ;
}
if ( V_4 -> V_8 [ V_4 -> V_20 ] . V_18 & F_5 ( V_60 ) )
V_4 -> V_56 . V_61 ++ ;
V_4 -> V_8 [ V_4 -> V_20 ] . V_5 &= ~ F_5 ( V_53 ) ;
if ( V_4 -> V_20 == V_10 - 1 )
V_4 -> V_20 = 0 ;
else
V_4 -> V_20 ++ ;
}
}
static T_3 F_24 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_64 , V_6 ;
V_64 = F_7 ( V_4 , V_65 ) ;
if ( V_64 & F_5 ( V_28 ) )
F_17 ( V_2 ) ;
if ( V_64 & F_5 ( V_32 ) ) {
if ( V_64 & ( F_5 ( V_30 ) | F_5 ( V_31 ) ) )
V_4 -> V_56 . V_66 ++ ;
if ( V_4 -> V_38 ) {
F_25 ( V_4 -> V_38 ) ;
V_4 -> V_38 = NULL ;
F_26 ( NULL , V_4 -> V_43 , V_4 -> V_41 , V_45 ) ;
V_4 -> V_56 . V_67 ++ ;
V_4 -> V_56 . V_68 += V_4 -> V_41 ;
}
F_27 ( V_2 ) ;
}
if ( V_64 & F_5 ( V_29 ) ) {
V_6 = F_7 ( V_4 , V_22 ) ;
F_6 ( V_4 , V_22 , V_6 & ~ F_5 ( V_23 ) ) ;
F_6 ( V_4 , V_22 , V_6 | F_5 ( V_23 ) ) ;
}
if ( V_64 & F_5 ( V_33 ) )
F_16 ( V_2 , L_2 ) ;
return V_69 ;
}
static void F_28 ( struct V_1 * V_2 )
{
unsigned long V_70 ;
F_29 ( V_70 ) ;
F_24 ( V_2 -> V_62 , V_2 ) ;
F_30 ( V_70 ) ;
}
static int T_4 F_31 ( struct V_71 * V_9 )
{
struct V_72 * V_73 = V_9 -> V_2 . V_74 ;
struct V_75 * V_76 ;
struct V_1 * V_2 ;
struct V_77 * V_78 ;
struct V_79 * V_79 ;
struct V_3 * V_4 ;
int V_80 ;
T_2 V_81 ;
const char * V_82 ;
V_76 = F_32 ( V_9 , V_83 , 0 ) ;
if ( ! V_76 )
return - V_84 ;
V_79 = F_33 ( & V_9 -> V_2 ) ;
if ( F_34 ( V_79 ) ) {
V_80 = F_35 ( V_79 ) ;
if ( V_80 == - V_85 )
return V_80 ;
F_36 ( & V_9 -> V_2 , L_3 ) ;
}
V_2 = F_37 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 )
return - V_14 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_2 = V_2 ;
F_38 ( & V_4 -> V_86 ) ;
V_2 -> V_87 = V_76 -> V_88 ;
V_4 -> V_76 = F_39 ( & V_9 -> V_2 , V_76 -> V_88 , F_40 ( V_76 ) ) ;
if ( ! V_4 -> V_76 ) {
V_80 = - V_14 ;
goto V_89;
}
V_4 -> V_90 = F_41 ( & V_9 -> V_2 , L_4 ) ;
if ( F_34 ( V_4 -> V_90 ) ) {
V_80 = F_35 ( V_4 -> V_90 ) ;
goto V_89;
}
F_42 ( V_4 -> V_90 ) ;
V_2 -> V_62 = F_43 ( V_9 , 0 ) ;
V_80 = F_44 ( & V_9 -> V_2 , V_2 -> V_62 , F_24 , 0 , V_2 -> V_91 , V_2 ) ;
if ( V_80 )
goto V_92;
F_45 ( V_2 ) ;
V_2 -> V_93 = & V_94 ;
V_2 -> V_95 = & V_96 ;
F_46 ( V_9 , V_2 ) ;
F_47 ( V_2 , & V_9 -> V_2 ) ;
V_82 = F_48 ( V_9 -> V_2 . V_97 ) ;
if ( V_82 )
memcpy ( V_4 -> V_2 -> V_98 , V_82 , V_99 ) ;
else
F_49 ( V_4 ) ;
V_80 = F_50 ( V_9 -> V_2 . V_97 ) ;
if ( V_80 < 0 ) {
if ( V_73 && V_73 -> V_100 )
V_4 -> V_101 = V_102 ;
else
V_4 -> V_101 = V_103 ;
} else {
V_4 -> V_101 = V_80 ;
}
F_6 ( V_4 , V_22 , 0 ) ;
V_81 = F_18 ( V_104 , V_105 ) | F_5 ( V_106 ) ;
if ( V_4 -> V_101 == V_102 )
V_81 |= F_5 ( V_107 ) ;
F_6 ( V_4 , V_108 , V_81 ) ;
V_80 = F_51 ( V_2 ) ;
if ( V_80 )
goto V_92;
V_80 = F_52 ( V_4 ) ;
if ( V_80 )
goto V_109;
F_53 ( V_2 ) ;
V_78 = V_4 -> V_35 ;
F_54 ( V_2 , L_5 ,
V_78 -> V_110 -> V_91 , F_55 ( & V_78 -> V_2 ) ,
V_78 -> V_62 ) ;
F_54 ( V_2 , L_6 ,
V_2 -> V_87 , V_2 -> V_62 , V_2 -> V_98 ) ;
return 0 ;
V_109:
F_56 ( V_2 ) ;
V_92:
F_57 ( V_4 -> V_90 ) ;
V_89:
F_58 ( V_2 ) ;
return V_80 ;
}
static int F_59 ( struct V_71 * V_9 )
{
struct V_1 * V_2 = F_60 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_35 )
F_61 ( V_4 -> V_35 ) ;
F_62 ( V_4 -> V_111 ) ;
F_63 ( V_4 -> V_111 -> V_62 ) ;
F_64 ( V_4 -> V_111 ) ;
F_56 ( V_2 ) ;
F_57 ( V_4 -> V_90 ) ;
F_58 ( V_2 ) ;
F_46 ( V_9 , NULL ) ;
return 0 ;
}
static int F_65 ( struct V_71 * V_9 , T_5 V_112 )
{
struct V_1 * V_113 = F_60 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_113 ) ;
if ( F_66 ( V_113 ) ) {
F_13 ( V_113 ) ;
F_67 ( V_113 ) ;
F_57 ( V_4 -> V_90 ) ;
}
return 0 ;
}
static int F_68 ( struct V_71 * V_9 )
{
struct V_1 * V_113 = F_60 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_113 ) ;
if ( F_66 ( V_113 ) ) {
F_42 ( V_4 -> V_90 ) ;
F_69 ( V_113 ) ;
F_11 ( V_113 ) ;
}
return 0 ;
}
