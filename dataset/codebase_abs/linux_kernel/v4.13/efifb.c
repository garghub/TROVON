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
V_57 . V_58 = V_23 . V_43 ;
V_57 . V_59 = V_23 . V_27 ;
V_57 . V_60 = V_23 . V_26 ;
V_55 . V_61 = V_23 . V_25 ;
V_35 = V_57 . V_60 * V_55 . V_61 ;
V_37 = V_23 . V_62 ;
if ( V_37 < V_35 )
V_37 = V_35 ;
V_36 = V_35 * 2 ;
if ( V_36 > V_37 )
V_36 = V_37 ;
if ( V_36 % V_63 )
V_36 += V_63 - ( V_36 % V_63 ) ;
V_55 . V_64 = V_36 ;
if ( F_14 ( V_55 . V_56 , V_36 , L_7 ) ) {
V_16 = true ;
} else {
F_15 ( L_10 ,
V_55 . V_56 ) ;
}
V_7 = F_16 ( sizeof( V_12 ) * 16 , & V_33 -> V_33 ) ;
if ( ! V_7 ) {
F_17 ( L_11 ) ;
V_34 = - V_65 ;
goto V_66;
}
F_18 ( V_33 , V_7 ) ;
V_7 -> V_13 = V_7 -> V_67 ;
V_7 -> V_67 = NULL ;
V_7 -> V_17 = F_19 ( 1 ) ;
if ( ! V_7 -> V_17 ) {
V_34 = - V_65 ;
goto V_68;
}
V_7 -> V_17 -> V_18 [ 0 ] . V_19 = V_55 . V_56 ;
V_7 -> V_17 -> V_18 [ 0 ] . V_20 = V_36 ;
if ( V_28 )
V_7 -> V_15 = F_20 ( V_55 . V_56 , V_55 . V_64 ) ;
else
V_7 -> V_15 = F_21 ( V_55 . V_56 , V_55 . V_64 ) ;
if ( ! V_7 -> V_15 ) {
F_17 ( L_12 ,
V_55 . V_64 , V_55 . V_56 ) ;
V_34 = - V_69 ;
goto V_68;
}
F_22 ( L_13 ,
V_55 . V_56 , V_36 / 1024 , V_37 / 1024 ) ;
F_22 ( L_14 ,
V_57 . V_59 , V_57 . V_60 ,
V_57 . V_58 , V_55 . V_61 ,
V_23 . V_44 ) ;
V_57 . V_70 = V_57 . V_59 ;
V_57 . V_71 = V_55 . V_64 /
V_55 . V_61 ;
F_22 ( L_15 ) ;
V_57 . V_71 = V_57 . V_60 ;
V_57 . V_72 = 10000000 / V_57 . V_59 *
1000 / V_57 . V_60 ;
V_57 . V_73 = ( V_57 . V_59 / 8 ) & 0xf8 ;
V_57 . V_74 = ( V_57 . V_59 / 8 ) & 0xf8 ;
V_57 . V_2 . V_14 = V_23 . V_52 ;
V_57 . V_2 . V_11 = V_23 . V_51 ;
V_57 . V_3 . V_14 = V_23 . V_50 ;
V_57 . V_3 . V_11 = V_23 . V_49 ;
V_57 . V_4 . V_14 = V_23 . V_48 ;
V_57 . V_4 . V_11 = V_23 . V_47 ;
V_57 . V_5 . V_14 = V_23 . V_54 ;
V_57 . V_5 . V_11 = V_23 . V_53 ;
F_22 ( L_16
L_17 ,
L_18 ,
V_23 . V_53 ,
V_23 . V_51 ,
V_23 . V_49 ,
V_23 . V_47 ,
V_23 . V_54 ,
V_23 . V_52 ,
V_23 . V_50 ,
V_23 . V_48 ) ;
V_55 . V_75 = 0 ;
V_55 . V_76 = 0 ;
V_7 -> V_77 = & V_78 ;
V_7 -> V_10 = V_57 ;
V_7 -> V_79 = V_55 ;
V_7 -> V_80 = V_81 | V_82 ;
V_34 = F_23 ( & V_33 -> V_33 . V_83 , V_84 ) ;
if ( V_34 ) {
F_17 ( L_19 ) ;
goto V_85;
}
V_34 = F_24 ( & V_7 -> V_8 , 256 , 0 ) ;
if ( V_34 < 0 ) {
F_17 ( L_20 ) ;
goto V_86;
}
V_34 = F_25 ( V_7 ) ;
if ( V_34 < 0 ) {
F_17 ( L_21 ) ;
goto V_87;
}
V_6 ( V_7 , L_22 , V_7 -> V_79 . V_88 ) ;
return 0 ;
V_87:
F_5 ( & V_7 -> V_8 ) ;
V_86:
F_26 ( & V_33 -> V_33 . V_83 , V_84 ) ;
V_85:
F_3 ( V_7 -> V_15 ) ;
V_68:
F_27 ( V_7 ) ;
V_66:
if ( V_16 )
F_4 ( V_55 . V_56 , V_37 ) ;
return V_34 ;
}
static int F_28 ( struct V_32 * V_89 )
{
struct V_6 * V_7 = F_29 ( V_89 ) ;
F_30 ( V_7 ) ;
F_26 ( & V_89 -> V_33 . V_83 , V_84 ) ;
F_27 ( V_7 ) ;
return 0 ;
}
static void F_31 ( struct V_90 * V_33 , int V_91 )
{
T_2 V_92 ;
V_93 = true ;
F_32 ( V_33 , V_94 , & V_92 ) ;
if ( ! ( V_92 & V_95 ) ) {
V_41 = true ;
F_33 ( & V_33 -> V_33 ,
L_23 ,
V_91 ) ;
return;
}
if ( F_34 ( V_33 , V_91 ) ) {
V_41 = true ;
F_33 ( & V_33 -> V_33 ,
L_24 , V_91 ) ;
return;
}
F_35 ( & V_33 -> V_33 , L_25 , V_91 ) ;
}
static void F_36 ( struct V_90 * V_33 )
{
T_1 V_19 = V_23 . V_24 ;
T_1 V_20 = V_23 . V_62 ;
int V_96 ;
if ( V_93 || V_23 . V_39 != V_40 )
return;
if ( V_23 . V_29 & V_30 )
V_19 |= ( T_1 ) V_23 . V_31 << 32 ;
if ( ! V_19 )
return;
for ( V_96 = 0 ; V_96 <= V_97 ; V_96 ++ ) {
struct V_98 * V_99 = & V_33 -> V_98 [ V_96 ] ;
if ( ! ( V_99 -> V_80 & V_100 ) )
continue;
if ( V_99 -> V_101 <= V_19 && V_99 -> V_102 >= V_19 + V_20 - 1 ) {
F_31 ( V_33 , V_96 ) ;
break;
}
}
}
