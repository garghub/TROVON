static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , L_1 , V_3 & 0x0FFF , ( V_3 >> 16 ) & 0x0FFF ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , L_2 , V_3 & 0x07FF , ( V_3 >> 16 ) & 0x07FF ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_4 * V_5 , T_1 V_3 )
{
if ( V_5 -> V_6 . V_7 == V_3 )
F_2 ( V_2 , L_3 , V_5 -> V_6 . V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_4 * V_5 , T_1 V_3 )
{
if ( V_5 -> V_9 == V_3 )
F_2 ( V_2 , L_3 , V_5 -> V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_4 * V_5 = (struct V_4 * ) V_13 -> V_15 -> V_11 ;
struct V_16 * V_17 = V_13 -> V_18 -> V_17 ;
int V_19 ;
V_19 = F_7 ( & V_17 -> V_20 ) ;
if ( V_19 )
return V_19 ;
F_2 ( V_2 , L_4 ,
F_8 ( & V_5 -> V_21 ) , V_5 -> V_22 ) ;
F_9 ( V_23 ) ;
F_9 ( V_24 ) ;
F_1 ( V_2 , F_10 ( V_5 -> V_22 + V_24 ) ) ;
F_9 ( V_25 ) ;
F_4 ( V_2 , V_5 , F_10 ( V_5 -> V_22 + V_25 ) ) ;
F_9 ( V_26 ) ;
F_9 ( V_27 ) ;
F_3 ( V_2 , F_10 ( V_5 -> V_22 + V_27 ) ) ;
F_9 ( V_28 ) ;
F_5 ( V_2 , V_5 , F_10 ( V_5 -> V_22 + V_28 ) ) ;
F_9 ( V_29 ) ;
F_9 ( V_30 ) ;
F_11 ( V_2 , L_5 ) ;
F_12 ( & V_17 -> V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_31 * V_18 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_14 ( V_33 ) ; V_32 ++ )
V_33 [ V_32 ] . V_11 = V_5 ;
return F_15 ( V_33 ,
F_14 ( V_33 ) ,
V_18 -> V_34 , V_18 ) ;
}
static void F_16 ( struct V_4 * V_5 , T_1 * V_35 )
{
T_2 * V_36 = V_5 -> V_6 . V_8 ;
unsigned int V_32 , V_37 ;
T_1 V_38 , V_39 , V_40 , V_41 ;
for ( V_32 = 0 ; V_32 < V_5 -> V_42 ; V_32 ++ ) {
for ( V_37 = 0 ; V_37 < V_5 -> V_43 ; V_37 ++ ) {
V_38 = ( * V_35 >> 30 ) & 3 ;
V_39 = ( * V_35 >> 22 ) & 3 ;
V_40 = ( * V_35 >> 14 ) & 3 ;
V_41 = ( * V_35 >> 6 ) & 3 ;
* V_36 = V_38 << 6 | V_39 << 4 | V_40 << 2 | V_41 ;
V_35 ++ ;
V_36 ++ ;
}
}
}
static void F_17 ( struct V_4 * V_5 )
{
unsigned short * V_8 = V_5 -> V_10 ;
unsigned int V_38 , V_39 , V_40 , V_41 ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ )
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ )
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ )
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ )
* V_8 ++ = ( V_38 * 5 ) << 12 |
( V_39 * 5 ) << 8 |
( V_40 * 5 ) << 4 |
( V_41 * 5 ) ;
}
static int F_18 ( struct V_44 * V_44 ,
struct V_45 * V_46 )
{
struct V_47 * V_21 = F_19 ( V_44 ) ;
struct V_4 * V_5 = F_20 ( V_21 ) ;
struct V_48 * V_49 = V_46 -> V_49 ;
struct V_50 * V_51 = V_46 -> V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_56 , V_57 , V_58 , V_59 ;
int V_60 , V_61 ;
if ( ! V_49 || ! V_51 )
return 0 ;
V_53 = F_21 ( V_46 -> V_46 , V_49 ) ;
V_55 = & V_53 -> V_55 ;
V_56 = V_46 -> V_62 ;
V_57 = V_46 -> V_63 ;
V_58 = F_22 ( V_46 -> V_64 , 0 , V_55 -> V_65 - V_56 ) ;
V_59 = F_22 ( V_46 -> V_66 , 0 , V_55 -> V_67 - V_57 ) ;
V_60 = V_46 -> V_60 >> 16 ;
V_61 = V_46 -> V_61 >> 16 ;
if ( V_60 < V_68 ||
V_61 < V_68 ||
V_60 > V_69 ||
V_61 > V_69 ) {
F_23 ( L_6 ,
V_60 , V_61 ) ;
return - V_70 ;
}
if ( ! V_5 -> V_6 . V_8 ||
( V_5 -> V_43 != V_60 ) ||
( V_5 -> V_42 != V_61 ) ) {
V_5 -> V_43 = V_60 ;
V_5 -> V_42 = V_61 ;
if ( V_5 -> V_6 . V_8 )
F_24 ( V_5 -> V_17 , V_5 -> V_6 . V_71 ,
V_5 -> V_6 . V_8 , V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_71 = V_5 -> V_43 * V_5 -> V_42 ;
V_5 -> V_6 . V_8 = F_25 ( V_5 -> V_17 ,
V_5 -> V_6 . V_71 ,
& V_5 -> V_6 . V_7 ,
V_72 | V_73 ) ;
if ( ! V_5 -> V_6 . V_8 ) {
F_23 ( L_7 ) ;
return - V_70 ;
}
}
if ( ! F_26 ( V_51 , 0 ) ) {
F_23 ( L_8 ) ;
return - V_70 ;
}
F_27 ( L_9 ,
V_49 -> V_8 . V_74 , F_28 ( F_29 ( V_49 ) ) ,
V_44 -> V_8 . V_74 , F_8 ( V_21 ) ) ;
F_27 ( L_10 , V_58 , V_59 , V_56 , V_57 ) ;
return 0 ;
}
static void F_30 ( struct V_44 * V_44 ,
struct V_45 * V_75 )
{
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_47 * V_21 = F_19 ( V_44 ) ;
struct V_4 * V_5 = F_20 ( V_21 ) ;
struct V_48 * V_49 = V_46 -> V_49 ;
struct V_50 * V_51 = V_46 -> V_51 ;
struct V_54 * V_55 ;
int V_56 , V_57 ;
struct V_76 * V_77 ;
T_1 V_78 , V_79 ;
T_1 V_3 ;
if ( ! V_49 || ! V_51 )
return;
V_55 = & V_49 -> V_55 ;
V_56 = V_46 -> V_62 ;
V_57 = V_46 -> V_63 ;
V_77 = F_26 ( V_51 , 0 ) ;
F_16 ( V_5 , ( T_1 * ) V_77 -> V_80 ) ;
V_78 = F_31 ( * V_55 , 0 ) ;
V_79 = F_32 ( * V_55 , 0 ) ;
V_3 = V_78 << 16 | V_79 ;
F_33 ( V_3 , V_5 -> V_22 + V_29 ) ;
V_78 = F_31 ( * V_55 , V_55 -> V_81 - 1 ) ;
V_79 = F_32 ( * V_55 , V_55 -> V_82 - 1 ) ;
V_3 = V_78 << 16 | V_79 ;
F_33 ( V_3 , V_5 -> V_22 + V_30 ) ;
F_33 ( V_5 -> V_6 . V_7 , V_5 -> V_22 + V_25 ) ;
F_33 ( V_5 -> V_43 , V_5 -> V_22 + V_26 ) ;
F_33 ( V_5 -> V_42 << 16 | V_5 -> V_43 , V_5 -> V_22 + V_27 ) ;
V_78 = F_31 ( * V_55 , V_57 ) ;
V_79 = F_32 ( * V_55 , V_56 ) ;
F_33 ( ( V_78 << 16 ) | V_79 , V_5 -> V_22 + V_24 ) ;
F_33 ( V_5 -> V_9 , V_5 -> V_22 + V_28 ) ;
F_33 ( V_83 , V_5 -> V_22 + V_23 ) ;
F_34 ( V_21 , true , false ) ;
V_21 -> V_84 = V_85 ;
}
static void F_35 ( struct V_44 * V_44 ,
struct V_45 * V_75 )
{
struct V_47 * V_21 = F_19 ( V_44 ) ;
if ( ! V_44 -> V_49 ) {
F_36 ( L_11 ,
V_44 -> V_8 . V_74 ) ;
return;
}
F_36 ( L_9 ,
V_44 -> V_49 -> V_8 . V_74 ,
F_28 ( F_29 ( V_44 -> V_49 ) ) ,
V_44 -> V_8 . V_74 , F_8 ( V_21 ) ) ;
V_21 -> V_84 = V_86 ;
}
struct V_44 * F_37 ( struct V_16 * V_87 ,
struct V_88 * V_17 , int V_89 ,
void T_3 * V_90 ,
unsigned int V_91 )
{
struct V_4 * V_5 ;
T_4 V_71 ;
int V_92 ;
V_5 = F_38 ( V_17 , sizeof( * V_5 ) , V_72 ) ;
if ( ! V_5 ) {
F_23 ( L_12 ) ;
return NULL ;
}
V_71 = 0x100 * sizeof( unsigned short ) ;
V_5 -> V_10 = F_25 ( V_17 , V_71 , & V_5 -> V_9 ,
V_72 | V_73 ) ;
if ( ! V_5 -> V_10 ) {
F_23 ( L_13 ) ;
goto V_93;
}
V_5 -> V_17 = V_17 ;
V_5 -> V_22 = V_90 ;
V_5 -> V_21 . V_89 = V_89 ;
V_5 -> V_21 . V_84 = V_94 ;
F_17 ( V_5 ) ;
V_92 = F_39 ( V_87 , & V_5 -> V_21 . V_44 ,
V_91 ,
& V_95 ,
V_96 ,
F_14 ( V_96 ) ,
V_97 , NULL ) ;
if ( V_92 ) {
F_23 ( L_14 ) ;
goto V_98;
}
F_40 ( & V_5 -> V_21 . V_44 ,
& V_99 ) ;
F_41 ( & V_5 -> V_21 , V_97 ) ;
if ( F_13 ( V_5 , V_87 -> V_100 ) )
F_23 ( L_15 ) ;
return & V_5 -> V_21 . V_44 ;
V_98:
F_24 ( V_17 , V_71 , V_5 -> V_10 , V_5 -> V_9 ) ;
V_93:
F_42 ( V_17 , V_5 ) ;
return NULL ;
}
