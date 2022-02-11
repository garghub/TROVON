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
if ( V_23 . V_38 != V_39 )
return - V_40 ;
if ( F_12 ( L_6 , & V_37 ) )
return - V_40 ;
F_6 ( V_37 ) ;
if ( ! V_23 . V_25 )
return - V_40 ;
if ( ! V_23 . V_41 )
V_23 . V_41 = 32 ;
if ( ! V_23 . V_42 )
V_23 . V_42 = 1 ;
if ( ! F_10 () ) {
F_13 ( V_43 L_7 ) ;
return - V_40 ;
}
F_13 ( V_44 L_8 ) ;
if ( ! V_23 . V_45 ) {
V_23 . V_45 = 8 ;
V_23 . V_46 = 0 ;
V_23 . V_47 = 8 ;
V_23 . V_48 = 8 ;
V_23 . V_49 = 8 ;
V_23 . V_50 = 16 ;
V_23 . V_51 = 8 ;
V_23 . V_52 = 24 ;
}
V_53 . V_54 = V_23 . V_24 ;
if ( V_23 . V_28 & V_29 ) {
T_1 V_30 ;
V_30 = ( T_1 ) ( unsigned long ) V_23 . V_30 << 32 ;
V_53 . V_54 |= V_30 ;
}
V_55 . V_56 = V_23 . V_41 ;
V_55 . V_57 = V_23 . V_27 ;
V_55 . V_58 = V_23 . V_26 ;
V_53 . V_59 = V_23 . V_25 ;
V_34 = V_55 . V_58 * V_53 . V_59 ;
V_36 = V_23 . V_60 ;
if ( V_36 < V_34 )
V_36 = V_34 ;
V_35 = V_34 * 2 ;
if ( V_35 > V_36 )
V_35 = V_36 ;
if ( V_35 % V_61 )
V_35 += V_61 - ( V_35 % V_61 ) ;
V_53 . V_62 = V_35 ;
if ( F_14 ( V_53 . V_54 , V_35 , L_6 ) ) {
V_16 = true ;
} else {
F_15 ( L_9 ,
V_53 . V_54 ) ;
}
V_7 = F_16 ( sizeof( V_12 ) * 16 , & V_32 -> V_32 ) ;
if ( ! V_7 ) {
F_17 ( L_10 ) ;
V_33 = - V_63 ;
goto V_64;
}
F_18 ( V_32 , V_7 ) ;
V_7 -> V_13 = V_7 -> V_65 ;
V_7 -> V_65 = NULL ;
V_7 -> V_17 = F_19 ( 1 ) ;
if ( ! V_7 -> V_17 ) {
V_33 = - V_63 ;
goto V_66;
}
V_7 -> V_17 -> V_18 [ 0 ] . V_19 = V_53 . V_54 ;
V_7 -> V_17 -> V_18 [ 0 ] . V_20 = V_35 ;
V_7 -> V_15 = F_20 ( V_53 . V_54 , V_53 . V_62 ) ;
if ( ! V_7 -> V_15 ) {
F_17 ( L_11 ,
V_53 . V_62 , V_53 . V_54 ) ;
V_33 = - V_67 ;
goto V_66;
}
F_21 ( L_12 ,
V_53 . V_54 , V_35 / 1024 , V_36 / 1024 ) ;
F_21 ( L_13 ,
V_55 . V_57 , V_55 . V_58 ,
V_55 . V_56 , V_53 . V_59 ,
V_23 . V_42 ) ;
V_55 . V_68 = V_55 . V_57 ;
V_55 . V_69 = V_53 . V_62 /
V_53 . V_59 ;
F_21 ( L_14 ) ;
V_55 . V_69 = V_55 . V_58 ;
V_55 . V_70 = 10000000 / V_55 . V_57 *
1000 / V_55 . V_58 ;
V_55 . V_71 = ( V_55 . V_57 / 8 ) & 0xf8 ;
V_55 . V_72 = ( V_55 . V_57 / 8 ) & 0xf8 ;
V_55 . V_2 . V_14 = V_23 . V_50 ;
V_55 . V_2 . V_11 = V_23 . V_49 ;
V_55 . V_3 . V_14 = V_23 . V_48 ;
V_55 . V_3 . V_11 = V_23 . V_47 ;
V_55 . V_4 . V_14 = V_23 . V_46 ;
V_55 . V_4 . V_11 = V_23 . V_45 ;
V_55 . V_5 . V_14 = V_23 . V_52 ;
V_55 . V_5 . V_11 = V_23 . V_51 ;
F_21 ( L_15
L_16 ,
L_17 ,
V_23 . V_51 ,
V_23 . V_49 ,
V_23 . V_47 ,
V_23 . V_45 ,
V_23 . V_52 ,
V_23 . V_50 ,
V_23 . V_48 ,
V_23 . V_46 ) ;
V_53 . V_73 = 0 ;
V_53 . V_74 = 0 ;
V_7 -> V_75 = & V_76 ;
V_7 -> V_10 = V_55 ;
V_7 -> V_77 = V_53 ;
V_7 -> V_78 = V_79 | V_80 ;
V_33 = F_22 ( & V_32 -> V_32 . V_81 , V_82 ) ;
if ( V_33 ) {
F_17 ( L_18 ) ;
goto V_83;
}
V_33 = F_23 ( & V_7 -> V_8 , 256 , 0 ) ;
if ( V_33 < 0 ) {
F_17 ( L_19 ) ;
goto V_84;
}
V_33 = F_24 ( V_7 ) ;
if ( V_33 < 0 ) {
F_17 ( L_20 ) ;
goto V_85;
}
V_6 ( V_7 , L_21 , V_7 -> V_77 . V_86 ) ;
return 0 ;
V_85:
F_5 ( & V_7 -> V_8 ) ;
V_84:
F_25 ( & V_32 -> V_32 . V_81 , V_82 ) ;
V_83:
F_3 ( V_7 -> V_15 ) ;
V_66:
F_26 ( V_7 ) ;
V_64:
if ( V_16 )
F_4 ( V_53 . V_54 , V_36 ) ;
return V_33 ;
}
static int F_27 ( struct V_31 * V_87 )
{
struct V_6 * V_7 = F_28 ( V_87 ) ;
F_29 ( V_7 ) ;
F_25 ( & V_87 -> V_32 . V_81 , V_82 ) ;
F_26 ( V_7 ) ;
return 0 ;
}
