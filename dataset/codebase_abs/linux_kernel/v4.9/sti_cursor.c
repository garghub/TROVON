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
F_2 ( V_2 , L_4 ,
F_7 ( & V_5 -> V_16 ) , V_5 -> V_17 ) ;
F_8 ( V_18 ) ;
F_8 ( V_19 ) ;
F_1 ( V_2 , F_9 ( V_5 -> V_17 + V_19 ) ) ;
F_8 ( V_20 ) ;
F_4 ( V_2 , V_5 , F_9 ( V_5 -> V_17 + V_20 ) ) ;
F_8 ( V_21 ) ;
F_8 ( V_22 ) ;
F_3 ( V_2 , F_9 ( V_5 -> V_17 + V_22 ) ) ;
F_8 ( V_23 ) ;
F_5 ( V_2 , V_5 , F_9 ( V_5 -> V_17 + V_23 ) ) ;
F_8 ( V_24 ) ;
F_8 ( V_25 ) ;
F_10 ( V_2 , L_5 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_26 * V_27 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < F_12 ( V_29 ) ; V_28 ++ )
V_29 [ V_28 ] . V_11 = V_5 ;
return F_13 ( V_29 ,
F_12 ( V_29 ) ,
V_27 -> V_30 , V_27 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_1 * V_31 )
{
T_2 * V_32 = V_5 -> V_6 . V_8 ;
unsigned int V_28 , V_33 ;
T_1 V_34 , V_35 , V_36 , V_37 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_38 ; V_28 ++ ) {
for ( V_33 = 0 ; V_33 < V_5 -> V_39 ; V_33 ++ ) {
V_34 = ( * V_31 >> 30 ) & 3 ;
V_35 = ( * V_31 >> 22 ) & 3 ;
V_36 = ( * V_31 >> 14 ) & 3 ;
V_37 = ( * V_31 >> 6 ) & 3 ;
* V_32 = V_34 << 6 | V_35 << 4 | V_36 << 2 | V_37 ;
V_31 ++ ;
V_32 ++ ;
}
}
}
static void F_15 ( struct V_4 * V_5 )
{
unsigned short * V_8 = V_5 -> V_10 ;
unsigned int V_34 , V_35 , V_36 , V_37 ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ )
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ )
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
* V_8 ++ = ( V_34 * 5 ) << 12 |
( V_35 * 5 ) << 8 |
( V_36 * 5 ) << 4 |
( V_37 * 5 ) ;
}
static int F_16 ( struct V_40 * V_40 ,
struct V_41 * V_42 )
{
struct V_43 * V_16 = F_17 ( V_40 ) ;
struct V_4 * V_5 = F_18 ( V_16 ) ;
struct V_44 * V_45 = V_42 -> V_45 ;
struct V_46 * V_47 = V_42 -> V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
int V_52 , V_53 , V_54 , V_55 ;
int V_56 , V_57 ;
if ( ! V_45 || ! V_47 )
return 0 ;
V_49 = F_19 ( V_42 -> V_42 , V_45 ) ;
V_51 = & V_49 -> V_51 ;
V_52 = V_42 -> V_58 ;
V_53 = V_42 -> V_59 ;
V_54 = F_20 ( V_42 -> V_60 , 0 , V_51 -> V_61 - V_52 ) ;
V_55 = F_20 ( V_42 -> V_62 , 0 , V_51 -> V_63 - V_53 ) ;
V_56 = V_42 -> V_56 >> 16 ;
V_57 = V_42 -> V_57 >> 16 ;
if ( V_56 < V_64 ||
V_57 < V_64 ||
V_56 > V_65 ||
V_57 > V_65 ) {
F_21 ( L_6 ,
V_56 , V_57 ) ;
return - V_66 ;
}
if ( ! V_5 -> V_6 . V_8 ||
( V_5 -> V_39 != V_56 ) ||
( V_5 -> V_38 != V_57 ) ) {
V_5 -> V_39 = V_56 ;
V_5 -> V_38 = V_57 ;
if ( V_5 -> V_6 . V_8 )
F_22 ( V_5 -> V_67 , V_5 -> V_6 . V_68 ,
V_5 -> V_6 . V_8 , V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_68 = V_5 -> V_39 * V_5 -> V_38 ;
V_5 -> V_6 . V_8 = F_23 ( V_5 -> V_67 ,
V_5 -> V_6 . V_68 ,
& V_5 -> V_6 . V_7 ,
V_69 | V_70 ) ;
if ( ! V_5 -> V_6 . V_8 ) {
F_21 ( L_7 ) ;
return - V_66 ;
}
}
if ( ! F_24 ( V_47 , 0 ) ) {
F_21 ( L_8 ) ;
return - V_66 ;
}
F_25 ( L_9 ,
V_45 -> V_8 . V_71 , F_26 ( F_27 ( V_45 ) ) ,
V_40 -> V_8 . V_71 , F_7 ( V_16 ) ) ;
F_25 ( L_10 , V_54 , V_55 , V_52 , V_53 ) ;
return 0 ;
}
static void F_28 ( struct V_40 * V_40 ,
struct V_41 * V_72 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_43 * V_16 = F_17 ( V_40 ) ;
struct V_4 * V_5 = F_18 ( V_16 ) ;
struct V_44 * V_45 = V_42 -> V_45 ;
struct V_46 * V_47 = V_42 -> V_47 ;
struct V_50 * V_51 ;
int V_52 , V_53 ;
struct V_73 * V_74 ;
T_1 V_75 , V_76 ;
T_1 V_3 ;
if ( ! V_45 || ! V_47 )
return;
V_51 = & V_45 -> V_51 ;
V_52 = V_42 -> V_58 ;
V_53 = V_42 -> V_59 ;
V_74 = F_24 ( V_47 , 0 ) ;
F_14 ( V_5 , ( T_1 * ) V_74 -> V_77 ) ;
V_75 = F_29 ( * V_51 , 0 ) ;
V_76 = F_30 ( * V_51 , 0 ) ;
V_3 = V_75 << 16 | V_76 ;
F_31 ( V_3 , V_5 -> V_17 + V_24 ) ;
V_75 = F_29 ( * V_51 , V_51 -> V_78 - 1 ) ;
V_76 = F_30 ( * V_51 , V_51 -> V_79 - 1 ) ;
V_3 = V_75 << 16 | V_76 ;
F_31 ( V_3 , V_5 -> V_17 + V_25 ) ;
F_31 ( V_5 -> V_6 . V_7 , V_5 -> V_17 + V_20 ) ;
F_31 ( V_5 -> V_39 , V_5 -> V_17 + V_21 ) ;
F_31 ( V_5 -> V_38 << 16 | V_5 -> V_39 , V_5 -> V_17 + V_22 ) ;
V_75 = F_29 ( * V_51 , V_53 ) ;
V_76 = F_30 ( * V_51 , V_52 ) ;
F_31 ( ( V_75 << 16 ) | V_76 , V_5 -> V_17 + V_19 ) ;
F_31 ( V_5 -> V_9 , V_5 -> V_17 + V_23 ) ;
F_31 ( V_80 , V_5 -> V_17 + V_18 ) ;
F_32 ( V_16 , true , false ) ;
V_16 -> V_81 = V_82 ;
}
static void F_33 ( struct V_40 * V_40 ,
struct V_41 * V_72 )
{
struct V_43 * V_16 = F_17 ( V_40 ) ;
if ( ! V_72 -> V_45 ) {
F_34 ( L_11 ,
V_40 -> V_8 . V_71 ) ;
return;
}
F_34 ( L_9 ,
V_72 -> V_45 -> V_8 . V_71 ,
F_26 ( F_27 ( V_72 -> V_45 ) ) ,
V_40 -> V_8 . V_71 , F_7 ( V_16 ) ) ;
V_16 -> V_81 = V_83 ;
}
static void F_35 ( struct V_40 * V_40 )
{
F_34 ( L_5 ) ;
F_36 ( V_40 ) ;
F_37 ( V_40 ) ;
}
static int F_38 ( struct V_40 * V_40 )
{
struct V_43 * V_16 = F_17 ( V_40 ) ;
struct V_4 * V_5 = F_18 ( V_16 ) ;
return F_11 ( V_5 , V_40 -> V_67 -> V_84 ) ;
}
struct V_40 * F_39 ( struct V_85 * V_86 ,
struct V_87 * V_67 , int V_88 ,
void T_3 * V_89 ,
unsigned int V_90 )
{
struct V_4 * V_5 ;
T_4 V_68 ;
int V_91 ;
V_5 = F_40 ( V_67 , sizeof( * V_5 ) , V_69 ) ;
if ( ! V_5 ) {
F_21 ( L_12 ) ;
return NULL ;
}
V_68 = 0x100 * sizeof( unsigned short ) ;
V_5 -> V_10 = F_23 ( V_67 , V_68 , & V_5 -> V_9 ,
V_69 | V_70 ) ;
if ( ! V_5 -> V_10 ) {
F_21 ( L_13 ) ;
goto V_92;
}
V_5 -> V_67 = V_67 ;
V_5 -> V_17 = V_89 ;
V_5 -> V_16 . V_88 = V_88 ;
V_5 -> V_16 . V_81 = V_93 ;
F_15 ( V_5 ) ;
V_91 = F_41 ( V_86 , & V_5 -> V_16 . V_40 ,
V_90 ,
& V_94 ,
V_95 ,
F_12 ( V_95 ) ,
V_96 , NULL ) ;
if ( V_91 ) {
F_21 ( L_14 ) ;
goto V_97;
}
F_42 ( & V_5 -> V_16 . V_40 ,
& V_98 ) ;
F_43 ( & V_5 -> V_16 , V_96 ) ;
return & V_5 -> V_16 . V_40 ;
V_97:
F_22 ( V_67 , V_68 , V_5 -> V_10 , V_5 -> V_9 ) ;
V_92:
F_44 ( V_67 , V_5 ) ;
return NULL ;
}
