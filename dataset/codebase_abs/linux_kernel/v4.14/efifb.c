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
else if ( ! strcmp ( V_22 , L_6 ) )
V_28 = true ;
}
}
return 0 ;
}
static inline bool F_10 ( void )
{
if ( V_23 . V_24 )
return true ;
if ( ! ( V_23 . V_29 & V_30 ) )
return false ;
if ( V_23 . V_31 )
return true ;
return false ;
}
static int F_11 ( struct V_32 * V_33 )
{
struct V_6 * V_7 ;
int V_34 ;
unsigned int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
char * V_38 = NULL ;
if ( V_23 . V_39 != V_40 || V_41 )
return - V_42 ;
if ( F_12 ( L_7 , & V_38 ) )
return - V_42 ;
F_6 ( V_38 ) ;
if ( ! V_23 . V_25 )
return - V_42 ;
if ( ! V_23 . V_43 )
V_23 . V_43 = 32 ;
if ( ! V_23 . V_44 )
V_23 . V_44 = 1 ;
if ( ! F_10 () ) {
F_13 ( V_45 L_8 ) ;
return - V_42 ;
}
F_13 ( V_46 L_9 ) ;
if ( ! V_23 . V_47 ) {
V_23 . V_47 = 8 ;
V_23 . V_48 = 0 ;
V_23 . V_49 = 8 ;
V_23 . V_50 = 8 ;
V_23 . V_51 = 8 ;
V_23 . V_52 = 16 ;
V_23 . V_53 = 8 ;
V_23 . V_54 = 24 ;
}
V_55 . V_56 = V_23 . V_24 ;
if ( V_23 . V_29 & V_30 ) {
T_1 V_31 ;
V_31 = ( T_1 ) ( unsigned long ) V_23 . V_31 << 32 ;
V_55 . V_56 |= V_31 ;
}
if ( V_57 &&
V_57 -> V_58 + V_59 != V_55 . V_56 ) {
F_14 ( & V_60 -> V_33 ,
L_10 ) ;
V_55 . V_56 = V_57 -> V_58 + V_59 ;
}
V_61 . V_62 = V_23 . V_43 ;
V_61 . V_63 = V_23 . V_27 ;
V_61 . V_64 = V_23 . V_26 ;
V_55 . V_65 = V_23 . V_25 ;
V_35 = V_61 . V_64 * V_55 . V_65 ;
V_37 = V_23 . V_66 ;
if ( V_37 < V_35 )
V_37 = V_35 ;
V_36 = V_35 * 2 ;
if ( V_36 > V_37 )
V_36 = V_37 ;
if ( V_36 % V_67 )
V_36 += V_67 - ( V_36 % V_67 ) ;
V_55 . V_68 = V_36 ;
if ( F_15 ( V_55 . V_56 , V_36 , L_7 ) ) {
V_16 = true ;
} else {
F_16 ( L_11 ,
V_55 . V_56 ) ;
}
V_7 = F_17 ( sizeof( V_12 ) * 16 , & V_33 -> V_33 ) ;
if ( ! V_7 ) {
F_18 ( L_12 ) ;
V_34 = - V_69 ;
goto V_70;
}
F_19 ( V_33 , V_7 ) ;
V_7 -> V_13 = V_7 -> V_71 ;
V_7 -> V_71 = NULL ;
V_7 -> V_17 = F_20 ( 1 ) ;
if ( ! V_7 -> V_17 ) {
V_34 = - V_69 ;
goto V_72;
}
V_7 -> V_17 -> V_18 [ 0 ] . V_19 = V_55 . V_56 ;
V_7 -> V_17 -> V_18 [ 0 ] . V_20 = V_36 ;
if ( V_28 )
V_7 -> V_15 = F_21 ( V_55 . V_56 , V_55 . V_68 ) ;
else
V_7 -> V_15 = F_22 ( V_55 . V_56 , V_55 . V_68 ) ;
if ( ! V_7 -> V_15 ) {
F_18 ( L_13 ,
V_55 . V_68 , V_55 . V_56 ) ;
V_34 = - V_73 ;
goto V_72;
}
F_23 ( L_14 ,
V_55 . V_56 , V_36 / 1024 , V_37 / 1024 ) ;
F_23 ( L_15 ,
V_61 . V_63 , V_61 . V_64 ,
V_61 . V_62 , V_55 . V_65 ,
V_23 . V_44 ) ;
V_61 . V_74 = V_61 . V_63 ;
V_61 . V_75 = V_55 . V_68 /
V_55 . V_65 ;
F_23 ( L_16 ) ;
V_61 . V_75 = V_61 . V_64 ;
V_61 . V_76 = 10000000 / V_61 . V_63 *
1000 / V_61 . V_64 ;
V_61 . V_77 = ( V_61 . V_63 / 8 ) & 0xf8 ;
V_61 . V_78 = ( V_61 . V_63 / 8 ) & 0xf8 ;
V_61 . V_2 . V_14 = V_23 . V_52 ;
V_61 . V_2 . V_11 = V_23 . V_51 ;
V_61 . V_3 . V_14 = V_23 . V_50 ;
V_61 . V_3 . V_11 = V_23 . V_49 ;
V_61 . V_4 . V_14 = V_23 . V_48 ;
V_61 . V_4 . V_11 = V_23 . V_47 ;
V_61 . V_5 . V_14 = V_23 . V_54 ;
V_61 . V_5 . V_11 = V_23 . V_53 ;
F_23 ( L_17
L_18 ,
L_19 ,
V_23 . V_53 ,
V_23 . V_51 ,
V_23 . V_49 ,
V_23 . V_47 ,
V_23 . V_54 ,
V_23 . V_52 ,
V_23 . V_50 ,
V_23 . V_48 ) ;
V_55 . V_79 = 0 ;
V_55 . V_80 = 0 ;
V_7 -> V_81 = & V_82 ;
V_7 -> V_10 = V_61 ;
V_7 -> V_83 = V_55 ;
V_7 -> V_84 = V_85 | V_86 ;
V_34 = F_24 ( & V_33 -> V_33 . V_87 , V_88 ) ;
if ( V_34 ) {
F_18 ( L_20 ) ;
goto V_89;
}
V_34 = F_25 ( & V_7 -> V_8 , 256 , 0 ) ;
if ( V_34 < 0 ) {
F_18 ( L_21 ) ;
goto V_90;
}
V_34 = F_26 ( V_7 ) ;
if ( V_34 < 0 ) {
F_18 ( L_22 ) ;
goto V_91;
}
V_6 ( V_7 , L_23 , V_7 -> V_83 . V_92 ) ;
return 0 ;
V_91:
F_5 ( & V_7 -> V_8 ) ;
V_90:
F_27 ( & V_33 -> V_33 . V_87 , V_88 ) ;
V_89:
F_3 ( V_7 -> V_15 ) ;
V_72:
F_28 ( V_7 ) ;
V_70:
if ( V_16 )
F_4 ( V_55 . V_56 , V_37 ) ;
return V_34 ;
}
static int F_29 ( struct V_32 * V_93 )
{
struct V_6 * V_7 = F_30 ( V_93 ) ;
F_31 ( V_7 ) ;
F_27 ( & V_93 -> V_33 . V_87 , V_88 ) ;
F_28 ( V_7 ) ;
return 0 ;
}
static void F_32 ( struct V_94 * V_33 , int V_95 , T_1 V_14 )
{
T_2 V_96 ;
V_60 = V_33 ;
F_33 ( V_33 , V_97 , & V_96 ) ;
if ( ! ( V_96 & V_98 ) ) {
V_41 = true ;
F_34 ( & V_33 -> V_33 ,
L_24 ,
V_95 ) ;
return;
}
V_57 = & V_33 -> V_99 [ V_95 ] ;
V_59 = V_14 ;
F_14 ( & V_33 -> V_33 , L_25 , V_95 ) ;
}
static void F_35 ( struct V_94 * V_33 )
{
T_1 V_19 = V_23 . V_24 ;
T_1 V_20 = V_23 . V_66 ;
int V_100 ;
if ( V_60 || V_23 . V_39 != V_40 )
return;
if ( V_23 . V_29 & V_30 )
V_19 |= ( T_1 ) V_23 . V_31 << 32 ;
if ( ! V_19 )
return;
for ( V_100 = 0 ; V_100 <= V_101 ; V_100 ++ ) {
struct V_99 * V_102 = & V_33 -> V_99 [ V_100 ] ;
if ( ! ( V_102 -> V_84 & V_103 ) )
continue;
if ( V_102 -> V_58 <= V_19 && V_102 -> V_104 >= V_19 + V_20 - 1 ) {
F_32 ( V_33 , V_100 , V_19 - V_102 -> V_58 ) ;
break;
}
}
}
