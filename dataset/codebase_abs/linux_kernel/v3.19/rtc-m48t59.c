static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_4 ( V_4 , V_8 -> V_9 + V_3 ) ;
}
static T_2
F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
return F_6 ( V_8 -> V_9 + V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_14 ;
T_2 V_4 ;
F_9 ( & V_8 -> V_15 , V_14 ) ;
F_10 ( V_16 , V_17 ) ;
V_11 -> V_18 = F_11 ( F_12 ( V_19 ) ) ;
V_11 -> V_20 = F_11 ( F_12 ( V_21 ) ) - 1 ;
V_11 -> V_22 = F_11 ( F_12 ( V_23 ) ) ;
V_4 = F_12 ( V_24 ) ;
if ( ( V_13 -> type == V_25 ) &&
( V_4 & V_26 ) && ( V_4 & V_27 ) ) {
F_13 ( V_2 , L_1 ) ;
V_11 -> V_18 += 100 ;
}
#ifdef F_14
V_11 -> V_18 += 68 ;
#endif
V_11 -> V_28 = F_11 ( V_4 & 0x07 ) ;
V_11 -> V_29 = F_11 ( F_12 ( V_30 ) & 0x3F ) ;
V_11 -> V_31 = F_11 ( F_12 ( V_32 ) & 0x7F ) ;
V_11 -> V_33 = F_11 ( F_12 ( V_34 ) & 0x7F ) ;
F_15 ( V_16 , V_17 ) ;
F_16 ( & V_8 -> V_15 , V_14 ) ;
F_13 ( V_2 , L_2 ,
V_11 -> V_18 + 1900 , V_11 -> V_20 , V_11 -> V_22 ,
V_11 -> V_29 , V_11 -> V_31 , V_11 -> V_33 ) ;
return F_17 ( V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_14 ;
T_2 V_4 = 0 ;
int V_35 = V_11 -> V_18 ;
#ifdef F_14
V_35 -= 68 ;
#endif
F_13 ( V_2 , L_3 ,
V_35 + 1900 , V_11 -> V_20 , V_11 -> V_22 ,
V_11 -> V_29 , V_11 -> V_31 , V_11 -> V_33 ) ;
if ( V_35 < 0 )
return - V_36 ;
F_9 ( & V_8 -> V_15 , V_14 ) ;
F_10 ( V_37 , V_17 ) ;
F_19 ( ( F_20 ( V_11 -> V_33 ) & 0x7F ) , V_34 ) ;
F_19 ( ( F_20 ( V_11 -> V_31 ) & 0x7F ) , V_32 ) ;
F_19 ( ( F_20 ( V_11 -> V_29 ) & 0x3F ) , V_30 ) ;
F_19 ( ( F_20 ( V_11 -> V_22 ) & 0x3F ) , V_23 ) ;
F_19 ( ( F_20 ( V_11 -> V_20 + 1 ) & 0x1F ) , V_21 ) ;
F_19 ( F_20 ( V_35 % 100 ) , V_19 ) ;
if ( V_13 -> type == V_25 && ( V_35 / 100 ) )
V_4 = ( V_26 | V_27 ) ;
V_4 |= ( F_20 ( V_11 -> V_28 ) & 0x07 ) ;
F_19 ( V_4 , V_24 ) ;
F_15 ( V_37 , V_17 ) ;
F_16 ( & V_8 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_10 * V_11 = & V_39 -> time ;
unsigned long V_14 ;
T_2 V_4 ;
if ( V_8 -> V_40 == V_41 )
return - V_42 ;
F_9 ( & V_8 -> V_15 , V_14 ) ;
F_10 ( V_16 , V_17 ) ;
V_11 -> V_18 = F_11 ( F_12 ( V_19 ) ) ;
#ifdef F_14
V_11 -> V_18 += 68 ;
#endif
V_11 -> V_20 = F_11 ( F_12 ( V_21 ) ) - 1 ;
V_4 = F_12 ( V_24 ) ;
if ( ( V_4 & V_26 ) && ( V_4 & V_27 ) )
V_11 -> V_18 += 100 ;
V_11 -> V_22 = F_11 ( F_12 ( V_43 ) ) ;
V_11 -> V_29 = F_11 ( F_12 ( V_44 ) ) ;
V_11 -> V_31 = F_11 ( F_12 ( V_45 ) ) ;
V_11 -> V_33 = F_11 ( F_12 ( V_46 ) ) ;
F_15 ( V_16 , V_17 ) ;
F_16 ( & V_8 -> V_15 , V_14 ) ;
F_13 ( V_2 , L_4 ,
V_11 -> V_18 + 1900 , V_11 -> V_20 , V_11 -> V_22 ,
V_11 -> V_29 , V_11 -> V_31 , V_11 -> V_33 ) ;
return F_17 ( V_11 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_10 * V_11 = & V_39 -> time ;
T_2 V_47 , V_48 , V_49 , V_50 ;
unsigned long V_14 ;
int V_35 = V_11 -> V_18 ;
#ifdef F_14
V_35 -= 68 ;
#endif
if ( V_8 -> V_40 == V_41 )
return - V_42 ;
if ( V_35 < 0 )
return - V_36 ;
V_47 = V_11 -> V_22 ;
V_47 = ( V_47 >= 1 && V_47 <= 31 ) ? F_20 ( V_47 ) : 0xff ;
if ( V_47 == 0xff )
V_47 = F_12 ( V_23 ) ;
V_48 = V_11 -> V_29 ;
V_48 = ( V_48 < 24 ) ? F_20 ( V_48 ) : 0x00 ;
V_49 = V_11 -> V_31 ;
V_49 = ( V_49 < 60 ) ? F_20 ( V_49 ) : 0x00 ;
V_50 = V_11 -> V_33 ;
V_50 = ( V_50 < 60 ) ? F_20 ( V_50 ) : 0x00 ;
F_9 ( & V_8 -> V_15 , V_14 ) ;
F_10 ( V_37 , V_17 ) ;
F_19 ( V_47 , V_43 ) ;
F_19 ( V_48 , V_44 ) ;
F_19 ( V_49 , V_45 ) ;
F_19 ( V_50 , V_46 ) ;
F_15 ( V_37 , V_17 ) ;
F_16 ( & V_8 -> V_15 , V_14 ) ;
F_13 ( V_2 , L_5 ,
V_35 + 1900 , V_11 -> V_20 , V_11 -> V_22 ,
V_11 -> V_29 , V_11 -> V_31 , V_11 -> V_33 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_14 ;
F_9 ( & V_8 -> V_15 , V_14 ) ;
if ( V_51 )
F_19 ( V_52 , V_53 ) ;
else
F_19 ( 0x00 , V_53 ) ;
F_16 ( & V_8 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_14 ;
T_2 V_4 ;
F_9 ( & V_8 -> V_15 , V_14 ) ;
V_4 = F_12 ( V_56 ) ;
F_16 ( & V_8 -> V_15 , V_14 ) ;
F_25 ( V_55 , L_6 ,
( V_4 & V_57 ) ? L_7 : L_8 ) ;
return 0 ;
}
static T_3 F_26 ( int V_40 , void * V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_2 V_59 ;
F_27 ( & V_8 -> V_15 ) ;
V_59 = F_12 ( V_56 ) ;
F_28 ( & V_8 -> V_15 ) ;
if ( V_59 & V_60 ) {
F_29 ( V_8 -> V_61 , 1 , ( V_62 | V_63 ) ) ;
return V_64 ;
}
return V_65 ;
}
static T_4 F_30 ( struct V_66 * V_67 , struct V_68 * V_69 ,
struct V_70 * V_71 ,
char * V_72 , T_5 V_73 , T_6 V_74 )
{
struct V_1 * V_2 = F_31 ( V_69 , struct V_1 , V_69 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_4 V_75 = 0 ;
unsigned long V_14 ;
for (; V_74 > 0 && V_73 < V_13 -> V_76 ; V_75 ++ , V_74 -- ) {
F_9 ( & V_8 -> V_15 , V_14 ) ;
* V_72 ++ = F_12 ( V_75 ) ;
F_16 ( & V_8 -> V_15 , V_14 ) ;
}
return V_75 ;
}
static T_4 F_32 ( struct V_66 * V_67 , struct V_68 * V_69 ,
struct V_70 * V_71 ,
char * V_72 , T_5 V_73 , T_6 V_74 )
{
struct V_1 * V_2 = F_31 ( V_69 , struct V_1 , V_69 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_4 V_75 = 0 ;
unsigned long V_14 ;
for (; V_74 > 0 && V_73 < V_13 -> V_76 ; V_75 ++ , V_74 -- ) {
F_9 ( & V_8 -> V_15 , V_14 ) ;
F_19 ( * V_72 ++ , V_75 ) ;
F_16 ( & V_8 -> V_15 , V_14 ) ;
}
return V_75 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_8 ( & V_6 -> V_2 ) ;
struct V_7 * V_8 = NULL ;
struct V_77 * V_78 ;
int V_79 = - V_80 ;
char * V_81 ;
const struct V_82 * V_83 ;
V_78 = F_34 ( V_6 , V_84 , 0 ) ;
if ( ! V_78 ) {
V_78 = F_34 ( V_6 , V_85 , 0 ) ;
if ( ! V_78 )
return - V_36 ;
}
if ( V_78 -> V_14 & V_85 ) {
if ( ! V_13 || ! V_13 -> V_86 || ! V_13 -> V_87 )
return - V_36 ;
} else if ( V_78 -> V_14 & V_84 ) {
if ( ! V_13 ) {
V_13 = F_35 ( & V_6 -> V_2 , sizeof( * V_13 ) ,
V_88 ) ;
if ( ! V_13 )
return - V_80 ;
V_6 -> V_2 . V_89 = V_13 ;
}
if ( ! V_13 -> type )
V_13 -> type = V_25 ;
if ( ! V_13 -> V_86 )
V_13 -> V_86 = F_1 ;
if ( ! V_13 -> V_87 )
V_13 -> V_87 = F_5 ;
}
V_8 = F_35 ( & V_6 -> V_2 , sizeof( * V_8 ) , V_88 ) ;
if ( ! V_8 )
return - V_80 ;
V_8 -> V_9 = V_13 -> V_9 ;
if ( ! V_8 -> V_9 ) {
V_8 -> V_9 = F_36 ( & V_6 -> V_2 , V_78 -> V_90 ,
F_37 ( V_78 ) ) ;
if ( ! V_8 -> V_9 )
return V_79 ;
}
V_8 -> V_40 = F_38 ( V_6 , 0 ) ;
if ( V_8 -> V_40 <= 0 )
V_8 -> V_40 = V_41 ;
if ( V_8 -> V_40 != V_41 ) {
V_79 = F_39 ( & V_6 -> V_2 , V_8 -> V_40 ,
F_26 , V_91 ,
L_9 , & V_6 -> V_2 ) ;
if ( V_79 )
return V_79 ;
}
switch ( V_13 -> type ) {
case V_25 :
V_81 = L_10 ;
V_83 = & V_92 ;
V_13 -> V_76 = 0x1ff0 ;
break;
case V_93 :
V_81 = L_11 ;
V_83 = & V_94 ;
V_13 -> V_76 = 0x7f0 ;
break;
case V_95 :
V_81 = L_12 ;
V_83 = & V_94 ;
V_13 -> V_76 = 0x1ff0 ;
break;
default:
F_40 ( & V_6 -> V_2 , L_13 ) ;
return - V_96 ;
}
F_41 ( & V_8 -> V_15 ) ;
F_42 ( V_6 , V_8 ) ;
V_8 -> V_61 = F_43 ( & V_6 -> V_2 , V_81 , V_83 ,
V_97 ) ;
if ( F_44 ( V_8 -> V_61 ) )
return F_45 ( V_8 -> V_61 ) ;
V_98 . V_74 = V_13 -> V_76 ;
V_79 = F_46 ( & V_6 -> V_2 . V_69 , & V_98 ) ;
if ( V_79 )
return V_79 ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 )
{
F_48 ( & V_6 -> V_2 . V_69 , & V_98 ) ;
return 0 ;
}
