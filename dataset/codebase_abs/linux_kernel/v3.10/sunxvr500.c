static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , L_1 , 0 ) ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 , L_2 , 0 ) ;
V_2 -> V_6 = F_2 ( V_2 -> V_4 , L_3 , 8 ) ;
if ( ! V_2 -> V_3 || ! V_2 -> V_5 ) {
F_3 ( V_7 L_4 ,
F_4 ( V_2 -> V_8 ) ) ;
return - V_9 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , int V_10 , T_1 V_11 )
{
void T_2 * V_12 = V_2 -> V_12 ;
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_7 ( V_10 , V_12 + V_15 ) ;
F_7 ( V_11 , V_12 + V_16 ) ;
F_8 ( & V_2 -> V_14 , V_13 ) ;
}
static int F_9 ( unsigned V_17 ,
unsigned V_18 , unsigned V_19 , unsigned V_20 ,
unsigned V_21 , struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
T_1 V_25 , V_26 , V_27 ;
T_1 V_28 , V_29 , V_30 ;
T_1 V_31 ;
if ( V_17 >= 256 )
return 1 ;
V_25 = V_18 >> 8 ;
V_26 = V_19 >> 8 ;
V_27 = V_20 >> 8 ;
V_31 = ( V_27 << 24 ) | ( V_26 << 16 ) | ( V_25 << 8 ) ;
if ( V_23 -> V_32 . V_33 == V_34 && V_17 < 16 )
( ( T_1 * ) V_23 -> V_35 ) [ V_17 ] = V_31 ;
V_28 = V_18 >> 6 ;
V_29 = V_19 >> 6 ;
V_30 = V_20 >> 6 ;
V_31 = ( V_30 << 20 ) | ( V_29 << 10 ) | ( V_28 << 0 ) ;
F_5 ( V_2 , V_17 , V_31 ) ;
return 0 ;
}
static void F_10 ( struct V_22 * V_23 , const struct V_36 * V_37 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_11 ( V_23 , V_37 ) ;
V_23 -> V_38 += V_2 -> V_39 ;
F_11 ( V_23 , V_37 ) ;
V_23 -> V_38 -= V_2 -> V_39 ;
F_8 ( & V_2 -> V_14 , V_13 ) ;
}
static void F_12 ( struct V_22 * V_23 , const struct V_40 * V_41 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_13 ( V_23 , V_41 ) ;
V_23 -> V_38 += V_2 -> V_39 ;
F_13 ( V_23 , V_41 ) ;
V_23 -> V_38 -= V_2 -> V_39 ;
F_8 ( & V_2 -> V_14 , V_13 ) ;
}
static void F_14 ( struct V_22 * V_23 , const struct V_42 * V_43 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_15 ( V_23 , V_43 ) ;
V_23 -> V_38 += V_2 -> V_39 ;
F_15 ( V_23 , V_43 ) ;
V_23 -> V_38 -= V_2 -> V_39 ;
F_8 ( & V_2 -> V_14 , V_13 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_44 * V_45 = & V_23 -> V_45 ;
V_23 -> V_13 = V_46 ;
V_23 -> V_47 = & V_48 ;
V_23 -> V_38 = V_2 -> V_49 ;
V_23 -> V_50 = V_2 -> V_51 ;
V_23 -> V_35 = V_2 -> V_35 ;
F_17 ( V_23 -> V_32 . V_52 , L_5 , sizeof( V_23 -> V_32 . V_52 ) ) ;
V_23 -> V_32 . V_53 = V_2 -> V_54 ;
V_23 -> V_32 . V_55 = V_2 -> V_51 ;
V_23 -> V_32 . type = V_56 ;
if ( V_2 -> V_6 == 32 || V_2 -> V_6 == 24 )
V_23 -> V_32 . V_33 = V_34 ;
else
V_23 -> V_32 . V_33 = V_57 ;
V_45 -> V_58 = V_2 -> V_3 ;
V_45 -> V_59 = V_2 -> V_5 ;
V_45 -> V_60 = V_45 -> V_58 ;
V_45 -> V_61 = V_45 -> V_59 ;
V_45 -> V_62 = V_2 -> V_6 ;
V_45 -> V_18 . V_63 = 8 ;
V_45 -> V_18 . V_64 = 8 ;
V_45 -> V_19 . V_63 = 16 ;
V_45 -> V_19 . V_64 = 8 ;
V_45 -> V_20 . V_63 = 24 ;
V_45 -> V_20 . V_64 = 8 ;
V_45 -> V_21 . V_63 = 0 ;
V_45 -> V_21 . V_64 = 0 ;
if ( F_18 ( & V_23 -> V_65 , 256 , 0 ) ) {
F_3 ( V_7 L_6 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_19 ( struct V_67 * V_8 ,
const struct V_68 * V_69 )
{
struct V_70 * V_4 ;
const char * V_71 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
unsigned int V_72 ;
int V_73 ;
V_4 = F_20 ( V_8 ) ;
if ( ! V_4 ) {
F_3 ( V_7 L_7 ,
F_4 ( V_8 ) ) ;
return - V_74 ;
}
V_71 = F_21 ( V_4 , L_8 , NULL ) ;
if ( ! V_71 ) {
F_3 ( V_75 L_9
L_10 , F_4 ( V_8 ) ) ;
return - V_74 ;
}
V_73 = F_22 ( V_8 ) ;
if ( V_73 < 0 ) {
F_3 ( V_7 L_11 ,
F_4 ( V_8 ) ) ;
goto V_76;
}
V_23 = F_23 ( sizeof( struct V_1 ) , & V_8 -> V_77 ) ;
if ( ! V_23 ) {
F_3 ( V_7 L_12 ) ;
V_73 = - V_66 ;
goto V_78;
}
V_2 = V_23 -> V_24 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_8 = V_8 ;
F_24 ( & V_2 -> V_14 ) ;
V_2 -> V_4 = V_4 ;
F_25 ( V_8 , V_79 ,
& V_2 -> V_80 ) ;
V_2 -> V_80 &= V_81 ;
V_2 -> V_82 = F_26 ( V_8 , 1 ) ;
V_73 = F_27 ( V_8 , 1 , L_13 ) ;
if ( V_73 < 0 ) {
F_3 ( L_14 ,
F_4 ( V_8 ) ) ;
goto V_83;
}
V_2 -> V_12 = F_28 ( V_2 -> V_82 + 0x8000 , 0x1000 ) ;
if ( ! V_2 -> V_12 ) {
V_73 = - V_66 ;
goto V_84;
}
V_2 -> V_85 = F_29 ( V_2 -> V_12 + V_86 ) ;
V_2 -> V_85 -= V_2 -> V_80 ;
V_2 -> V_87 = F_29 ( V_2 -> V_12 + V_88 ) ;
V_2 -> V_87 -= V_2 -> V_80 ;
V_2 -> V_39 = V_2 -> V_87 - V_2 -> V_85 ;
V_2 -> V_54 = F_26 ( V_8 , 0 ) ;
V_2 -> V_54 += V_2 -> V_85 ;
V_73 = F_27 ( V_8 , 0 , L_15 ) ;
if ( V_73 < 0 ) {
F_3 ( L_16 ,
F_4 ( V_8 ) ) ;
goto V_89;
}
V_73 = F_1 ( V_2 ) ;
if ( V_73 )
goto V_90;
V_72 = ( F_29 ( V_2 -> V_12 + V_91 ) >> 16 ) & 0xff ;
V_72 = 1 << V_72 ;
switch ( V_2 -> V_6 ) {
case 8 :
V_23 -> V_32 . V_72 = V_72 ;
break;
case 16 :
V_23 -> V_32 . V_72 = V_72 * 2 ;
break;
case 24 :
V_23 -> V_32 . V_72 = V_72 * 3 ;
break;
case 32 :
V_23 -> V_32 . V_72 = V_72 * 4 ;
break;
}
V_2 -> V_51 = V_23 -> V_32 . V_72 * V_2 -> V_5 ;
V_2 -> V_49 = F_28 ( V_2 -> V_54 , V_2 -> V_51 ) ;
if ( ! V_2 -> V_49 ) {
V_73 = - V_66 ;
goto V_90;
}
V_73 = F_16 ( V_2 ) ;
if ( V_73 )
goto V_92;
F_30 ( V_8 , V_23 ) ;
F_3 ( L_17 , F_4 ( V_8 ) ) ;
V_73 = F_31 ( V_23 ) ;
if ( V_73 < 0 ) {
F_3 ( V_7 L_18 ,
F_4 ( V_8 ) ) ;
goto V_93;
}
return 0 ;
V_93:
F_32 ( & V_23 -> V_65 ) ;
V_92:
F_33 ( V_2 -> V_49 ) ;
V_90:
F_34 ( V_8 , 0 ) ;
V_89:
F_33 ( V_2 -> V_12 ) ;
V_84:
F_34 ( V_8 , 1 ) ;
V_83:
F_35 ( V_23 ) ;
V_78:
F_36 ( V_8 ) ;
V_76:
return V_73 ;
}
static void F_37 ( struct V_67 * V_8 )
{
struct V_22 * V_23 = F_38 ( V_8 ) ;
struct V_1 * V_2 = V_23 -> V_24 ;
F_39 ( V_23 ) ;
F_33 ( V_2 -> V_12 ) ;
F_33 ( V_2 -> V_49 ) ;
F_34 ( V_8 , 0 ) ;
F_34 ( V_8 , 1 ) ;
F_32 ( & V_23 -> V_65 ) ;
F_35 ( V_23 ) ;
F_36 ( V_8 ) ;
}
static int T_3 F_40 ( void )
{
if ( F_41 ( L_5 , NULL ) )
return - V_74 ;
return F_42 ( & V_94 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_94 ) ;
}
