static int F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 ,
struct V_6 * V_7 )
{
if ( V_1 >= V_7 -> V_8 . V_9 )
return 1 ;
if ( V_1 < 16 ) {
V_2 >>= 16 - V_7 -> V_10 . V_2 . V_11 ;
V_3 >>= 16 - V_7 -> V_10 . V_3 . V_11 ;
V_4 >>= 16 - V_7 -> V_10 . V_4 . V_11 ;
( ( V_12 * ) ( V_7 -> V_13 ) ) [ V_1 ] =
( V_2 << V_7 -> V_10 . V_2 . V_14 ) |
( V_3 << V_7 -> V_10 . V_3 . V_14 ) |
( V_4 << V_7 -> V_10 . V_4 . V_14 ) ;
}
return 0 ;
}
static void F_2 ( struct V_6 * V_7 )
{
if ( V_7 -> V_15 )
F_3 ( V_7 -> V_15 ) ;
if ( V_16 )
F_4 ( V_7 -> V_17 -> V_18 [ 0 ] . V_19 ,
V_7 -> V_17 -> V_18 [ 0 ] . V_20 ) ;
F_5 ( & V_7 -> V_8 ) ;
}
static int F_6 ( char * V_21 )
{
char * V_22 ;
if ( V_21 && * V_21 ) {
while ( ( V_22 = F_7 ( & V_21 , L_1 ) ) != NULL ) {
if ( ! * V_22 ) continue;
F_8 ( & V_23 , V_22 ) ;
if ( ! strncmp ( V_22 , L_2 , 5 ) )
V_23 . V_24 = F_9 ( V_22 + 5 , NULL , 0 ) ;
else if ( ! strncmp ( V_22 , L_3 , 7 ) )
V_23 . V_25 = F_9 ( V_22 + 7 , NULL , 0 ) * 4 ;
else if ( ! strncmp ( V_22 , L_4 , 7 ) )
V_23 . V_26 = F_9 ( V_22 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_22 , L_5 , 6 ) )
V_23 . V_27 = F_9 ( V_22 + 6 , NULL , 0 ) ;
}
}
return 0 ;
}
static inline bool F_10 ( void )
{
if ( V_23 . V_24 )
return true ;
if ( ! ( V_23 . V_28 & V_29 ) )
return false ;
if ( V_23 . V_30 )
return true ;
return false ;
}
static int F_11 ( struct V_31 * V_32 )
{
struct V_6 * V_7 ;
int V_33 ;
unsigned int V_34 ;
unsigned int V_35 ;
unsigned int V_36 ;
char * V_37 = NULL ;
if ( V_23 . V_38 != V_39 || V_40 )
return - V_41 ;
if ( F_12 ( L_6 , & V_37 ) )
return - V_41 ;
F_6 ( V_37 ) ;
if ( ! V_23 . V_25 )
return - V_41 ;
if ( ! V_23 . V_42 )
V_23 . V_42 = 32 ;
if ( ! V_23 . V_43 )
V_23 . V_43 = 1 ;
if ( ! F_10 () ) {
F_13 ( V_44 L_7 ) ;
return - V_41 ;
}
F_13 ( V_45 L_8 ) ;
if ( ! V_23 . V_46 ) {
V_23 . V_46 = 8 ;
V_23 . V_47 = 0 ;
V_23 . V_48 = 8 ;
V_23 . V_49 = 8 ;
V_23 . V_50 = 8 ;
V_23 . V_51 = 16 ;
V_23 . V_52 = 8 ;
V_23 . V_53 = 24 ;
}
V_54 . V_55 = V_23 . V_24 ;
if ( V_23 . V_28 & V_29 ) {
T_1 V_30 ;
V_30 = ( T_1 ) ( unsigned long ) V_23 . V_30 << 32 ;
V_54 . V_55 |= V_30 ;
}
V_56 . V_57 = V_23 . V_42 ;
V_56 . V_58 = V_23 . V_27 ;
V_56 . V_59 = V_23 . V_26 ;
V_54 . V_60 = V_23 . V_25 ;
V_34 = V_56 . V_59 * V_54 . V_60 ;
V_36 = V_23 . V_61 ;
if ( V_36 < V_34 )
V_36 = V_34 ;
V_35 = V_34 * 2 ;
if ( V_35 > V_36 )
V_35 = V_36 ;
if ( V_35 % V_62 )
V_35 += V_62 - ( V_35 % V_62 ) ;
V_54 . V_63 = V_35 ;
if ( F_14 ( V_54 . V_55 , V_35 , L_6 ) ) {
V_16 = true ;
} else {
F_15 ( L_9 ,
V_54 . V_55 ) ;
}
V_7 = F_16 ( sizeof( V_12 ) * 16 , & V_32 -> V_32 ) ;
if ( ! V_7 ) {
F_17 ( L_10 ) ;
V_33 = - V_64 ;
goto V_65;
}
F_18 ( V_32 , V_7 ) ;
V_7 -> V_13 = V_7 -> V_66 ;
V_7 -> V_66 = NULL ;
V_7 -> V_17 = F_19 ( 1 ) ;
if ( ! V_7 -> V_17 ) {
V_33 = - V_64 ;
goto V_67;
}
V_7 -> V_17 -> V_18 [ 0 ] . V_19 = V_54 . V_55 ;
V_7 -> V_17 -> V_18 [ 0 ] . V_20 = V_35 ;
V_7 -> V_15 = F_20 ( V_54 . V_55 , V_54 . V_63 ) ;
if ( ! V_7 -> V_15 ) {
F_17 ( L_11 ,
V_54 . V_63 , V_54 . V_55 ) ;
V_33 = - V_68 ;
goto V_67;
}
F_21 ( L_12 ,
V_54 . V_55 , V_35 / 1024 , V_36 / 1024 ) ;
F_21 ( L_13 ,
V_56 . V_58 , V_56 . V_59 ,
V_56 . V_57 , V_54 . V_60 ,
V_23 . V_43 ) ;
V_56 . V_69 = V_56 . V_58 ;
V_56 . V_70 = V_54 . V_63 /
V_54 . V_60 ;
F_21 ( L_14 ) ;
V_56 . V_70 = V_56 . V_59 ;
V_56 . V_71 = 10000000 / V_56 . V_58 *
1000 / V_56 . V_59 ;
V_56 . V_72 = ( V_56 . V_58 / 8 ) & 0xf8 ;
V_56 . V_73 = ( V_56 . V_58 / 8 ) & 0xf8 ;
V_56 . V_2 . V_14 = V_23 . V_51 ;
V_56 . V_2 . V_11 = V_23 . V_50 ;
V_56 . V_3 . V_14 = V_23 . V_49 ;
V_56 . V_3 . V_11 = V_23 . V_48 ;
V_56 . V_4 . V_14 = V_23 . V_47 ;
V_56 . V_4 . V_11 = V_23 . V_46 ;
V_56 . V_5 . V_14 = V_23 . V_53 ;
V_56 . V_5 . V_11 = V_23 . V_52 ;
F_21 ( L_15
L_16 ,
L_17 ,
V_23 . V_52 ,
V_23 . V_50 ,
V_23 . V_48 ,
V_23 . V_46 ,
V_23 . V_53 ,
V_23 . V_51 ,
V_23 . V_49 ,
V_23 . V_47 ) ;
V_54 . V_74 = 0 ;
V_54 . V_75 = 0 ;
V_7 -> V_76 = & V_77 ;
V_7 -> V_10 = V_56 ;
V_7 -> V_78 = V_54 ;
V_7 -> V_79 = V_80 | V_81 ;
V_33 = F_22 ( & V_32 -> V_32 . V_82 , V_83 ) ;
if ( V_33 ) {
F_17 ( L_18 ) ;
goto V_84;
}
V_33 = F_23 ( & V_7 -> V_8 , 256 , 0 ) ;
if ( V_33 < 0 ) {
F_17 ( L_19 ) ;
goto V_85;
}
V_33 = F_24 ( V_7 ) ;
if ( V_33 < 0 ) {
F_17 ( L_20 ) ;
goto V_86;
}
V_6 ( V_7 , L_21 , V_7 -> V_78 . V_87 ) ;
return 0 ;
V_86:
F_5 ( & V_7 -> V_8 ) ;
V_85:
F_25 ( & V_32 -> V_32 . V_82 , V_83 ) ;
V_84:
F_3 ( V_7 -> V_15 ) ;
V_67:
F_26 ( V_7 ) ;
V_65:
if ( V_16 )
F_4 ( V_54 . V_55 , V_36 ) ;
return V_33 ;
}
static int F_27 ( struct V_31 * V_88 )
{
struct V_6 * V_7 = F_28 ( V_88 ) ;
F_29 ( V_7 ) ;
F_25 ( & V_88 -> V_32 . V_82 , V_83 ) ;
F_26 ( V_7 ) ;
return 0 ;
}
static void F_30 ( struct V_89 * V_32 , int V_90 )
{
T_2 V_91 ;
V_92 = true ;
F_31 ( V_32 , V_93 , & V_91 ) ;
if ( ! ( V_91 & V_94 ) ) {
V_40 = true ;
F_32 ( & V_32 -> V_32 ,
L_22 ,
V_90 ) ;
return;
}
if ( F_33 ( V_32 , V_90 ) ) {
V_40 = true ;
F_32 ( & V_32 -> V_32 ,
L_23 , V_90 ) ;
return;
}
F_34 ( & V_32 -> V_32 , L_24 , V_90 ) ;
}
static void F_35 ( struct V_89 * V_32 )
{
T_1 V_19 = V_23 . V_24 ;
T_1 V_20 = V_23 . V_61 ;
int V_95 ;
if ( V_92 || V_23 . V_38 != V_39 )
return;
if ( V_23 . V_28 & V_29 )
V_19 |= ( T_1 ) V_23 . V_30 << 32 ;
if ( ! V_19 )
return;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
struct V_97 * V_98 = & V_32 -> V_97 [ V_95 ] ;
if ( ! ( V_98 -> V_79 & V_99 ) )
continue;
if ( V_98 -> V_100 <= V_19 && V_98 -> V_101 >= V_19 + V_20 - 1 ) {
F_30 ( V_32 , V_95 ) ;
break;
}
}
}
