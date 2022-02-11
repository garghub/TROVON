static int F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 ,
struct V_6 * V_7 )
{
if ( V_1 >= V_7 -> V_8 . V_9 )
return 1 ;
if ( V_1 < 16 ) {
V_2 >>= 8 ;
V_3 >>= 8 ;
V_4 >>= 8 ;
( ( V_10 * ) ( V_7 -> V_11 ) ) [ V_1 ] =
( V_2 << V_7 -> V_12 . V_2 . V_13 ) |
( V_3 << V_7 -> V_12 . V_3 . V_13 ) |
( V_4 << V_7 -> V_12 . V_4 . V_13 ) ;
}
return 0 ;
}
static void F_2 ( struct V_6 * V_7 )
{
if ( V_7 -> V_14 )
F_3 ( V_7 -> V_14 ) ;
if ( V_15 )
F_4 ( V_7 -> V_16 -> V_17 [ 0 ] . V_18 ,
V_7 -> V_16 -> V_17 [ 0 ] . V_19 ) ;
F_5 ( & V_7 -> V_8 ) ;
}
static int F_6 ( char * V_20 )
{
char * V_21 ;
int V_22 ;
if ( V_20 && * V_20 ) {
while ( ( V_21 = F_7 ( & V_20 , L_1 ) ) != NULL ) {
if ( ! * V_21 ) continue;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_24 [ V_22 ] . V_18 != 0 &&
! strcmp ( V_21 , V_24 [ V_22 ] . V_25 ) ) {
V_26 . V_27 = V_24 [ V_22 ] . V_18 ;
V_26 . V_28 = V_24 [ V_22 ] . V_29 ;
V_26 . V_30 = V_24 [ V_22 ] . V_31 ;
V_26 . V_32 = V_24 [ V_22 ] . V_33 ;
}
}
if ( ! strncmp ( V_21 , L_2 , 5 ) )
V_26 . V_27 = F_8 ( V_21 + 5 , NULL , 0 ) ;
else if ( ! strncmp ( V_21 , L_3 , 7 ) )
V_26 . V_28 = F_8 ( V_21 + 7 , NULL , 0 ) * 4 ;
else if ( ! strncmp ( V_21 , L_4 , 7 ) )
V_26 . V_32 = F_8 ( V_21 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_21 , L_5 , 6 ) )
V_26 . V_30 = F_8 ( V_21 + 6 , NULL , 0 ) ;
}
}
return 0 ;
}
static inline bool F_9 ( void )
{
if ( V_26 . V_27 )
return true ;
if ( ! ( V_26 . V_34 & V_35 ) )
return false ;
if ( V_26 . V_36 )
return true ;
return false ;
}
static int F_10 ( struct V_37 * V_38 )
{
struct V_6 * V_7 ;
int V_39 ;
unsigned int V_40 ;
unsigned int V_41 ;
unsigned int V_42 ;
char * V_43 = NULL ;
if ( V_26 . V_44 != V_45 )
return - V_46 ;
if ( F_11 ( L_6 , & V_43 ) )
return - V_46 ;
F_6 ( V_43 ) ;
if ( ! V_26 . V_28 )
return - V_46 ;
if ( ! V_26 . V_47 )
V_26 . V_47 = 32 ;
if ( ! V_26 . V_48 )
V_26 . V_48 = 1 ;
if ( ! F_9 () ) {
F_12 ( V_49 L_7 ) ;
return - V_46 ;
}
F_12 ( V_50 L_8 ) ;
if ( ! V_26 . V_51 ) {
V_26 . V_51 = 8 ;
V_26 . V_52 = 0 ;
V_26 . V_53 = 8 ;
V_26 . V_54 = 8 ;
V_26 . V_55 = 8 ;
V_26 . V_56 = 16 ;
V_26 . V_57 = 8 ;
V_26 . V_58 = 24 ;
}
V_59 . V_60 = V_26 . V_27 ;
if ( V_26 . V_34 & V_35 ) {
T_1 V_36 ;
V_36 = ( T_1 ) ( unsigned long ) V_26 . V_36 << 32 ;
V_59 . V_60 |= V_36 ;
}
V_61 . V_62 = V_26 . V_47 ;
V_61 . V_63 = V_26 . V_30 ;
V_61 . V_64 = V_26 . V_32 ;
V_59 . V_65 = V_26 . V_28 ;
V_40 = V_61 . V_64 * V_59 . V_65 ;
V_42 = V_26 . V_66 ;
if ( V_42 < V_40 )
V_42 = V_40 ;
V_41 = V_40 * 2 ;
if ( V_41 > V_42 )
V_41 = V_42 ;
if ( V_41 % V_67 )
V_41 += V_67 - ( V_41 % V_67 ) ;
V_59 . V_68 = V_41 ;
if ( F_13 ( V_59 . V_60 , V_41 , L_6 ) ) {
V_15 = true ;
} else {
F_12 ( V_69
L_9 ,
V_59 . V_60 ) ;
}
V_7 = F_14 ( sizeof( V_10 ) * 16 , & V_38 -> V_38 ) ;
if ( ! V_7 ) {
F_12 ( V_70 L_10 ) ;
V_39 = - V_71 ;
goto V_72;
}
F_15 ( V_38 , V_7 ) ;
V_7 -> V_11 = V_7 -> V_73 ;
V_7 -> V_73 = NULL ;
V_7 -> V_16 = F_16 ( 1 ) ;
if ( ! V_7 -> V_16 ) {
V_39 = - V_71 ;
goto V_74;
}
V_7 -> V_16 -> V_17 [ 0 ] . V_18 = V_59 . V_60 ;
V_7 -> V_16 -> V_17 [ 0 ] . V_19 = V_41 ;
V_7 -> V_14 = F_17 ( V_59 . V_60 , V_59 . V_68 ) ;
if ( ! V_7 -> V_14 ) {
F_12 ( V_70 L_11
L_12 ,
V_59 . V_68 , V_59 . V_60 ) ;
V_39 = - V_75 ;
goto V_74;
}
F_12 ( V_50 L_13
L_14 ,
V_59 . V_60 , V_7 -> V_14 ,
V_41 / 1024 , V_42 / 1024 ) ;
F_12 ( V_50 L_15 ,
V_61 . V_63 , V_61 . V_64 ,
V_61 . V_62 , V_59 . V_65 ,
V_26 . V_48 ) ;
V_61 . V_76 = V_61 . V_63 ;
V_61 . V_77 = V_59 . V_68 /
V_59 . V_65 ;
F_12 ( V_50 L_16 ) ;
V_61 . V_77 = V_61 . V_64 ;
V_61 . V_78 = 10000000 / V_61 . V_63 *
1000 / V_61 . V_64 ;
V_61 . V_79 = ( V_61 . V_63 / 8 ) & 0xf8 ;
V_61 . V_80 = ( V_61 . V_63 / 8 ) & 0xf8 ;
V_61 . V_2 . V_13 = V_26 . V_56 ;
V_61 . V_2 . V_81 = V_26 . V_55 ;
V_61 . V_3 . V_13 = V_26 . V_54 ;
V_61 . V_3 . V_81 = V_26 . V_53 ;
V_61 . V_4 . V_13 = V_26 . V_52 ;
V_61 . V_4 . V_81 = V_26 . V_51 ;
V_61 . V_5 . V_13 = V_26 . V_58 ;
V_61 . V_5 . V_81 = V_26 . V_57 ;
F_12 ( V_50 L_17
L_18 ,
L_19 ,
V_26 . V_57 ,
V_26 . V_55 ,
V_26 . V_53 ,
V_26 . V_51 ,
V_26 . V_58 ,
V_26 . V_56 ,
V_26 . V_54 ,
V_26 . V_52 ) ;
V_59 . V_82 = 0 ;
V_59 . V_83 = 0 ;
V_7 -> V_84 = & V_85 ;
V_7 -> V_12 = V_61 ;
V_7 -> V_86 = V_59 ;
V_7 -> V_87 = V_88 | V_89 ;
if ( ( V_39 = F_18 ( & V_7 -> V_8 , 256 , 0 ) ) < 0 ) {
F_12 ( V_70 L_20 ) ;
goto V_90;
}
if ( ( V_39 = F_19 ( V_7 ) ) < 0 ) {
F_12 ( V_70 L_21 ) ;
goto V_91;
}
V_6 ( V_7 , L_22 , V_7 -> V_86 . V_92 ) ;
return 0 ;
V_91:
F_5 ( & V_7 -> V_8 ) ;
V_90:
F_3 ( V_7 -> V_14 ) ;
V_74:
F_20 ( V_7 ) ;
V_72:
if ( V_15 )
F_4 ( V_59 . V_60 , V_42 ) ;
return V_39 ;
}
static int F_21 ( struct V_37 * V_93 )
{
struct V_6 * V_7 = F_22 ( V_93 ) ;
F_23 ( V_7 ) ;
F_20 ( V_7 ) ;
return 0 ;
}
