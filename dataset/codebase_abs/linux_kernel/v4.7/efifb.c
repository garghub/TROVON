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
if ( V_20 && * V_20 ) {
while ( ( V_21 = F_7 ( & V_20 , L_1 ) ) != NULL ) {
if ( ! * V_21 ) continue;
F_8 ( & V_22 , V_21 ) ;
if ( ! strncmp ( V_21 , L_2 , 5 ) )
V_22 . V_23 = F_9 ( V_21 + 5 , NULL , 0 ) ;
else if ( ! strncmp ( V_21 , L_3 , 7 ) )
V_22 . V_24 = F_9 ( V_21 + 7 , NULL , 0 ) * 4 ;
else if ( ! strncmp ( V_21 , L_4 , 7 ) )
V_22 . V_25 = F_9 ( V_21 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_21 , L_5 , 6 ) )
V_22 . V_26 = F_9 ( V_21 + 6 , NULL , 0 ) ;
}
}
return 0 ;
}
static inline bool F_10 ( void )
{
if ( V_22 . V_23 )
return true ;
if ( ! ( V_22 . V_27 & V_28 ) )
return false ;
if ( V_22 . V_29 )
return true ;
return false ;
}
static int F_11 ( struct V_30 * V_31 )
{
struct V_6 * V_7 ;
int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
unsigned int V_35 ;
char * V_36 = NULL ;
if ( V_22 . V_37 != V_38 )
return - V_39 ;
if ( F_12 ( L_6 , & V_36 ) )
return - V_39 ;
F_6 ( V_36 ) ;
if ( ! V_22 . V_24 )
return - V_39 ;
if ( ! V_22 . V_40 )
V_22 . V_40 = 32 ;
if ( ! V_22 . V_41 )
V_22 . V_41 = 1 ;
if ( ! F_10 () ) {
F_13 ( V_42 L_7 ) ;
return - V_39 ;
}
F_13 ( V_43 L_8 ) ;
if ( ! V_22 . V_44 ) {
V_22 . V_44 = 8 ;
V_22 . V_45 = 0 ;
V_22 . V_46 = 8 ;
V_22 . V_47 = 8 ;
V_22 . V_48 = 8 ;
V_22 . V_49 = 16 ;
V_22 . V_50 = 8 ;
V_22 . V_51 = 24 ;
}
V_52 . V_53 = V_22 . V_23 ;
if ( V_22 . V_27 & V_28 ) {
T_1 V_29 ;
V_29 = ( T_1 ) ( unsigned long ) V_22 . V_29 << 32 ;
V_52 . V_53 |= V_29 ;
}
V_54 . V_55 = V_22 . V_40 ;
V_54 . V_56 = V_22 . V_26 ;
V_54 . V_57 = V_22 . V_25 ;
V_52 . V_58 = V_22 . V_24 ;
V_33 = V_54 . V_57 * V_52 . V_58 ;
V_35 = V_22 . V_59 ;
if ( V_35 < V_33 )
V_35 = V_33 ;
V_34 = V_33 * 2 ;
if ( V_34 > V_35 )
V_34 = V_35 ;
if ( V_34 % V_60 )
V_34 += V_60 - ( V_34 % V_60 ) ;
V_52 . V_61 = V_34 ;
if ( F_14 ( V_52 . V_53 , V_34 , L_6 ) ) {
V_15 = true ;
} else {
F_13 ( V_62
L_9 ,
V_52 . V_53 ) ;
}
V_7 = F_15 ( sizeof( V_10 ) * 16 , & V_31 -> V_31 ) ;
if ( ! V_7 ) {
F_13 ( V_63 L_10 ) ;
V_32 = - V_64 ;
goto V_65;
}
F_16 ( V_31 , V_7 ) ;
V_7 -> V_11 = V_7 -> V_66 ;
V_7 -> V_66 = NULL ;
V_7 -> V_16 = F_17 ( 1 ) ;
if ( ! V_7 -> V_16 ) {
V_32 = - V_64 ;
goto V_67;
}
V_7 -> V_16 -> V_17 [ 0 ] . V_18 = V_52 . V_53 ;
V_7 -> V_16 -> V_17 [ 0 ] . V_19 = V_34 ;
V_7 -> V_14 = F_18 ( V_52 . V_53 , V_52 . V_61 ) ;
if ( ! V_7 -> V_14 ) {
F_13 ( V_63 L_11
L_12 ,
V_52 . V_61 , V_52 . V_53 ) ;
V_32 = - V_68 ;
goto V_67;
}
F_13 ( V_43 L_13 ,
V_52 . V_53 , V_34 / 1024 , V_35 / 1024 ) ;
F_13 ( V_43 L_14 ,
V_54 . V_56 , V_54 . V_57 ,
V_54 . V_55 , V_52 . V_58 ,
V_22 . V_41 ) ;
V_54 . V_69 = V_54 . V_56 ;
V_54 . V_70 = V_52 . V_61 /
V_52 . V_58 ;
F_13 ( V_43 L_15 ) ;
V_54 . V_70 = V_54 . V_57 ;
V_54 . V_71 = 10000000 / V_54 . V_56 *
1000 / V_54 . V_57 ;
V_54 . V_72 = ( V_54 . V_56 / 8 ) & 0xf8 ;
V_54 . V_73 = ( V_54 . V_56 / 8 ) & 0xf8 ;
V_54 . V_2 . V_13 = V_22 . V_49 ;
V_54 . V_2 . V_74 = V_22 . V_48 ;
V_54 . V_3 . V_13 = V_22 . V_47 ;
V_54 . V_3 . V_74 = V_22 . V_46 ;
V_54 . V_4 . V_13 = V_22 . V_45 ;
V_54 . V_4 . V_74 = V_22 . V_44 ;
V_54 . V_5 . V_13 = V_22 . V_51 ;
V_54 . V_5 . V_74 = V_22 . V_50 ;
F_13 ( V_43 L_16
L_17 ,
L_18 ,
V_22 . V_50 ,
V_22 . V_48 ,
V_22 . V_46 ,
V_22 . V_44 ,
V_22 . V_51 ,
V_22 . V_49 ,
V_22 . V_47 ,
V_22 . V_45 ) ;
V_52 . V_75 = 0 ;
V_52 . V_76 = 0 ;
V_7 -> V_77 = & V_78 ;
V_7 -> V_12 = V_54 ;
V_7 -> V_79 = V_52 ;
V_7 -> V_80 = V_81 | V_82 ;
if ( ( V_32 = F_19 ( & V_7 -> V_8 , 256 , 0 ) ) < 0 ) {
F_13 ( V_63 L_19 ) ;
goto V_83;
}
if ( ( V_32 = F_20 ( V_7 ) ) < 0 ) {
F_13 ( V_63 L_20 ) ;
goto V_84;
}
V_6 ( V_7 , L_21 , V_7 -> V_79 . V_85 ) ;
return 0 ;
V_84:
F_5 ( & V_7 -> V_8 ) ;
V_83:
F_3 ( V_7 -> V_14 ) ;
V_67:
F_21 ( V_7 ) ;
V_65:
if ( V_15 )
F_4 ( V_52 . V_53 , V_35 ) ;
return V_32 ;
}
static int F_22 ( struct V_30 * V_86 )
{
struct V_6 * V_7 = F_23 ( V_86 ) ;
F_24 ( V_7 ) ;
F_21 ( V_7 ) ;
return 0 ;
}
