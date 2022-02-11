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
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_15 ;
T_2 V_4 ;
F_8 ( & V_8 -> V_16 , V_15 ) ;
F_9 ( V_17 , V_18 ) ;
V_11 -> V_19 = F_10 ( F_11 ( V_20 ) ) ;
V_11 -> V_21 = F_10 ( F_11 ( V_22 ) ) - 1 ;
V_11 -> V_23 = F_10 ( F_11 ( V_24 ) ) ;
V_4 = F_11 ( V_25 ) ;
if ( ( V_13 -> type == V_26 ) &&
( V_4 & V_27 ) && ( V_4 & V_28 ) ) {
F_12 ( V_2 , L_1 ) ;
V_11 -> V_19 += 100 ;
}
#ifdef F_13
V_11 -> V_19 += 68 ;
#endif
V_11 -> V_29 = F_10 ( V_4 & 0x07 ) ;
V_11 -> V_30 = F_10 ( F_11 ( V_31 ) & 0x3F ) ;
V_11 -> V_32 = F_10 ( F_11 ( V_33 ) & 0x7F ) ;
V_11 -> V_34 = F_10 ( F_11 ( V_35 ) & 0x7F ) ;
F_14 ( V_17 , V_18 ) ;
F_15 ( & V_8 -> V_16 , V_15 ) ;
F_12 ( V_2 , L_2 ,
V_11 -> V_19 + 1900 , V_11 -> V_21 , V_11 -> V_23 ,
V_11 -> V_30 , V_11 -> V_32 , V_11 -> V_34 ) ;
return F_16 ( V_11 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_15 ;
T_2 V_4 = 0 ;
int V_36 = V_11 -> V_19 ;
#ifdef F_13
V_36 -= 68 ;
#endif
F_12 ( V_2 , L_3 ,
V_36 + 1900 , V_11 -> V_21 , V_11 -> V_23 ,
V_11 -> V_30 , V_11 -> V_32 , V_11 -> V_34 ) ;
if ( V_36 < 0 )
return - V_37 ;
F_8 ( & V_8 -> V_16 , V_15 ) ;
F_9 ( V_38 , V_18 ) ;
F_18 ( ( F_19 ( V_11 -> V_34 ) & 0x7F ) , V_35 ) ;
F_18 ( ( F_19 ( V_11 -> V_32 ) & 0x7F ) , V_33 ) ;
F_18 ( ( F_19 ( V_11 -> V_30 ) & 0x3F ) , V_31 ) ;
F_18 ( ( F_19 ( V_11 -> V_23 ) & 0x3F ) , V_24 ) ;
F_18 ( ( F_19 ( V_11 -> V_21 + 1 ) & 0x1F ) , V_22 ) ;
F_18 ( F_19 ( V_36 % 100 ) , V_20 ) ;
if ( V_13 -> type == V_26 && ( V_36 / 100 ) )
V_4 = ( V_27 | V_28 ) ;
V_4 |= ( F_19 ( V_11 -> V_29 ) & 0x07 ) ;
F_18 ( V_4 , V_25 ) ;
F_14 ( V_38 , V_18 ) ;
F_15 ( & V_8 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_10 * V_11 = & V_40 -> time ;
unsigned long V_15 ;
T_2 V_4 ;
if ( V_8 -> V_41 == V_42 )
return - V_43 ;
F_8 ( & V_8 -> V_16 , V_15 ) ;
F_9 ( V_17 , V_18 ) ;
V_11 -> V_19 = F_10 ( F_11 ( V_20 ) ) ;
#ifdef F_13
V_11 -> V_19 += 68 ;
#endif
V_11 -> V_21 = F_10 ( F_11 ( V_22 ) ) - 1 ;
V_4 = F_11 ( V_25 ) ;
if ( ( V_4 & V_27 ) && ( V_4 & V_28 ) )
V_11 -> V_19 += 100 ;
V_11 -> V_23 = F_10 ( F_11 ( V_44 ) ) ;
V_11 -> V_30 = F_10 ( F_11 ( V_45 ) ) ;
V_11 -> V_32 = F_10 ( F_11 ( V_46 ) ) ;
V_11 -> V_34 = F_10 ( F_11 ( V_47 ) ) ;
F_14 ( V_17 , V_18 ) ;
F_15 ( & V_8 -> V_16 , V_15 ) ;
F_12 ( V_2 , L_4 ,
V_11 -> V_19 + 1900 , V_11 -> V_21 , V_11 -> V_23 ,
V_11 -> V_30 , V_11 -> V_32 , V_11 -> V_34 ) ;
return F_16 ( V_11 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_10 * V_11 = & V_40 -> time ;
T_2 V_48 , V_49 , V_50 , V_51 ;
unsigned long V_15 ;
int V_36 = V_11 -> V_19 ;
#ifdef F_13
V_36 -= 68 ;
#endif
if ( V_8 -> V_41 == V_42 )
return - V_43 ;
if ( V_36 < 0 )
return - V_37 ;
V_48 = V_11 -> V_23 ;
V_48 = ( V_48 >= 1 && V_48 <= 31 ) ? F_19 ( V_48 ) : 0xff ;
if ( V_48 == 0xff )
V_48 = F_11 ( V_24 ) ;
V_49 = V_11 -> V_30 ;
V_49 = ( V_49 < 24 ) ? F_19 ( V_49 ) : 0x00 ;
V_50 = V_11 -> V_32 ;
V_50 = ( V_50 < 60 ) ? F_19 ( V_50 ) : 0x00 ;
V_51 = V_11 -> V_34 ;
V_51 = ( V_51 < 60 ) ? F_19 ( V_51 ) : 0x00 ;
F_8 ( & V_8 -> V_16 , V_15 ) ;
F_9 ( V_38 , V_18 ) ;
F_18 ( V_48 , V_44 ) ;
F_18 ( V_49 , V_45 ) ;
F_18 ( V_50 , V_46 ) ;
F_18 ( V_51 , V_47 ) ;
F_14 ( V_38 , V_18 ) ;
F_15 ( & V_8 -> V_16 , V_15 ) ;
F_12 ( V_2 , L_5 ,
V_36 + 1900 , V_11 -> V_21 , V_11 -> V_23 ,
V_11 -> V_30 , V_11 -> V_32 , V_11 -> V_34 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_52 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_15 ;
F_8 ( & V_8 -> V_16 , V_15 ) ;
if ( V_52 )
F_18 ( V_53 , V_54 ) ;
else
F_18 ( 0x00 , V_54 ) ;
F_15 ( & V_8 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_15 ;
T_2 V_4 ;
F_8 ( & V_8 -> V_16 , V_15 ) ;
V_4 = F_11 ( V_57 ) ;
F_15 ( & V_8 -> V_16 , V_15 ) ;
F_24 ( V_56 , L_6 ,
( V_4 & V_58 ) ? L_7 : L_8 ) ;
return 0 ;
}
static T_3 F_25 ( int V_41 , void * V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_2 V_60 ;
F_26 ( & V_8 -> V_16 ) ;
V_60 = F_11 ( V_57 ) ;
F_27 ( & V_8 -> V_16 ) ;
if ( V_60 & V_61 ) {
F_28 ( V_8 -> V_62 , 1 , ( V_63 | V_64 ) ) ;
return V_65 ;
}
return V_66 ;
}
static T_4 F_29 ( struct V_67 * V_68 , struct V_69 * V_70 ,
struct V_71 * V_72 ,
char * V_73 , T_5 V_74 , T_6 V_75 )
{
struct V_1 * V_2 = F_30 ( V_70 , struct V_1 , V_70 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_4 V_76 = 0 ;
unsigned long V_15 ;
for (; V_75 > 0 && V_74 < V_13 -> V_77 ; V_76 ++ , V_75 -- ) {
F_8 ( & V_8 -> V_16 , V_15 ) ;
* V_73 ++ = F_11 ( V_76 ) ;
F_15 ( & V_8 -> V_16 , V_15 ) ;
}
return V_76 ;
}
static T_4 F_31 ( struct V_67 * V_68 , struct V_69 * V_70 ,
struct V_71 * V_72 ,
char * V_73 , T_5 V_74 , T_6 V_75 )
{
struct V_1 * V_2 = F_30 ( V_70 , struct V_1 , V_70 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_4 V_76 = 0 ;
unsigned long V_15 ;
for (; V_75 > 0 && V_74 < V_13 -> V_77 ; V_76 ++ , V_75 -- ) {
F_8 ( & V_8 -> V_16 , V_15 ) ;
F_18 ( * V_73 ++ , V_76 ) ;
F_15 ( & V_8 -> V_16 , V_15 ) ;
}
return V_76 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_2 . V_14 ;
struct V_7 * V_8 = NULL ;
struct V_78 * V_79 ;
int V_80 = - V_81 ;
char * V_82 ;
const struct V_83 * V_84 ;
V_79 = F_33 ( V_6 , V_85 , 0 ) ;
if ( ! V_79 ) {
V_79 = F_33 ( V_6 , V_86 , 0 ) ;
if ( ! V_79 )
return - V_37 ;
}
if ( V_79 -> V_15 & V_86 ) {
if ( ! V_13 || ! V_13 -> V_87 || ! V_13 -> V_88 )
return - V_37 ;
} else if ( V_79 -> V_15 & V_85 ) {
if ( ! V_13 ) {
V_13 = F_34 ( & V_6 -> V_2 , sizeof( * V_13 ) ,
V_89 ) ;
if ( ! V_13 )
return - V_81 ;
V_6 -> V_2 . V_14 = V_13 ;
}
if ( ! V_13 -> type )
V_13 -> type = V_26 ;
if ( ! V_13 -> V_87 )
V_13 -> V_87 = F_1 ;
if ( ! V_13 -> V_88 )
V_13 -> V_88 = F_5 ;
}
V_8 = F_34 ( & V_6 -> V_2 , sizeof( * V_8 ) , V_89 ) ;
if ( ! V_8 )
return - V_81 ;
V_8 -> V_9 = V_13 -> V_9 ;
if ( ! V_8 -> V_9 ) {
V_8 -> V_9 = F_35 ( & V_6 -> V_2 , V_79 -> V_90 ,
F_36 ( V_79 ) ) ;
if ( ! V_8 -> V_9 )
return V_80 ;
}
V_8 -> V_41 = F_37 ( V_6 , 0 ) ;
if ( V_8 -> V_41 <= 0 )
V_8 -> V_41 = V_42 ;
if ( V_8 -> V_41 != V_42 ) {
V_80 = F_38 ( & V_6 -> V_2 , V_8 -> V_41 ,
F_25 , V_91 ,
L_9 , & V_6 -> V_2 ) ;
if ( V_80 )
return V_80 ;
}
switch ( V_13 -> type ) {
case V_26 :
V_82 = L_10 ;
V_84 = & V_92 ;
V_13 -> V_77 = 0x1ff0 ;
break;
case V_93 :
V_82 = L_11 ;
V_84 = & V_94 ;
V_13 -> V_77 = 0x7f0 ;
break;
case V_95 :
V_82 = L_12 ;
V_84 = & V_94 ;
V_13 -> V_77 = 0x1ff0 ;
break;
default:
F_39 ( & V_6 -> V_2 , L_13 ) ;
return - V_96 ;
}
F_40 ( & V_8 -> V_16 ) ;
F_41 ( V_6 , V_8 ) ;
V_8 -> V_62 = F_42 ( & V_6 -> V_2 , V_82 , V_84 ,
V_97 ) ;
if ( F_43 ( V_8 -> V_62 ) )
return F_44 ( V_8 -> V_62 ) ;
V_98 . V_75 = V_13 -> V_77 ;
V_80 = F_45 ( & V_6 -> V_2 . V_70 , & V_98 ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
F_47 ( & V_6 -> V_2 . V_70 , & V_98 ) ;
return 0 ;
}
