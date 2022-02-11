static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 , struct
V_6 , V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return F_4 ( V_9 -> V_10 , V_3 ) ;
}
static void F_5 ( struct V_8 * V_9 , unsigned int V_11 )
{
T_1 V_12 = F_6 ( V_9 -> V_13 + V_14 ) ;
if ( F_7 ( V_9 -> V_15 [ 0 ] . V_5 . V_2 . V_16 + V_11 ) )
V_12 &= ~ F_8 ( V_11 ) ;
else
V_12 |= F_8 ( V_11 ) ;
F_9 ( V_12 , V_9 -> V_13 + V_14 ) ;
}
static void F_10 ( T_1 V_17 , struct V_18 * V_19 )
{
struct V_8 * V_9 = F_11 ( V_17 ) ;
struct V_20 * V_21 = F_12 ( V_19 ) ;
T_1 V_22 = F_13 ( V_9 -> V_13 + V_23 ) ;
while ( V_22 ) {
int V_24 = F_14 ( V_22 ) - 1 ;
int V_25 = F_4 ( V_9 -> V_10 , V_24 ) ;
F_15 ( V_25 ) ;
V_22 &= ~ F_8 ( V_24 ) ;
if ( ( F_16 ( V_25 ) & V_26 )
== V_27 )
F_5 ( V_9 , V_24 ) ;
}
if ( V_21 -> V_28 )
V_21 -> V_28 ( F_17 ( V_19 ) ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_19 ( V_30 ) ;
struct V_8 * V_9 = V_32 -> V_33 ;
struct V_4 * V_5 = & V_9 -> V_15 [ 0 ] . V_5 ;
unsigned long V_34 ;
T_1 V_35 ;
F_20 ( & V_5 -> V_36 , V_34 ) ;
V_35 = F_6 ( V_9 -> V_13 + V_37 ) ;
V_35 |= F_8 ( V_30 -> V_24 ) ;
F_9 ( V_35 , V_9 -> V_13 + V_37 ) ;
F_21 ( & V_5 -> V_36 , V_34 ) ;
}
static void F_22 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_19 ( V_30 ) ;
struct V_8 * V_9 = V_32 -> V_33 ;
struct V_4 * V_5 = & V_9 -> V_15 [ 0 ] . V_5 ;
unsigned long V_34 ;
T_1 V_35 ;
F_20 ( & V_5 -> V_36 , V_34 ) ;
V_35 = F_6 ( V_9 -> V_13 + V_37 ) ;
V_35 &= ~ F_8 ( V_30 -> V_24 ) ;
F_9 ( V_35 , V_9 -> V_13 + V_37 ) ;
F_21 ( & V_5 -> V_36 , V_34 ) ;
}
static int F_23 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_19 ( V_30 ) ;
struct V_8 * V_9 = V_32 -> V_33 ;
struct V_4 * V_5 = & V_9 -> V_15 [ 0 ] . V_5 ;
if ( F_24 ( & V_5 -> V_2 , F_25 ( V_30 ) ) ) {
F_26 ( V_9 -> V_38 , L_1 ,
F_25 ( V_30 ) ) ;
return - V_39 ;
}
return 0 ;
}
static void F_27 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_19 ( V_30 ) ;
struct V_8 * V_9 = V_32 -> V_33 ;
struct V_4 * V_5 = & V_9 -> V_15 [ 0 ] . V_5 ;
F_28 ( & V_5 -> V_2 , F_25 ( V_30 ) ) ;
}
static int F_29 ( struct V_29 * V_30 , T_1 type )
{
struct V_31 * V_32 = F_19 ( V_30 ) ;
struct V_8 * V_9 = V_32 -> V_33 ;
struct V_4 * V_5 = & V_9 -> V_15 [ 0 ] . V_5 ;
int V_40 = V_30 -> V_24 ;
unsigned long V_41 , V_42 , V_34 ;
if ( type & ~ ( V_43 | V_44 |
V_45 | V_46 ) )
return - V_39 ;
F_20 ( & V_5 -> V_36 , V_34 ) ;
V_41 = F_6 ( V_9 -> V_13 + V_47 ) ;
V_42 = F_6 ( V_9 -> V_13 + V_14 ) ;
switch ( type ) {
case V_27 :
V_41 |= F_8 ( V_40 ) ;
F_5 ( V_9 , V_40 ) ;
break;
case V_43 :
V_41 |= F_8 ( V_40 ) ;
V_42 |= F_8 ( V_40 ) ;
break;
case V_44 :
V_41 |= F_8 ( V_40 ) ;
V_42 &= ~ F_8 ( V_40 ) ;
break;
case V_45 :
V_41 &= ~ F_8 ( V_40 ) ;
V_42 |= F_8 ( V_40 ) ;
break;
case V_46 :
V_41 &= ~ F_8 ( V_40 ) ;
V_42 &= ~ F_8 ( V_40 ) ;
break;
}
F_30 ( V_30 , type ) ;
F_9 ( V_41 , V_9 -> V_13 + V_47 ) ;
F_9 ( V_42 , V_9 -> V_13 + V_14 ) ;
F_21 ( & V_5 -> V_36 , V_34 ) ;
return 0 ;
}
static void F_31 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_5 . V_2 ;
struct V_48 * V_49 = V_2 -> V_50 ;
struct V_31 * V_51 ;
unsigned int V_24 , V_52 = V_2 -> V_52 ;
struct V_53 * V_54 ;
int V_55 , V_17 , V_56 ;
V_17 = F_32 ( V_49 , 0 ) ;
if ( ! V_17 ) {
F_33 ( V_9 -> V_38 , L_2 ,
V_7 -> V_5 . V_2 . V_50 -> V_57 ) ;
return;
}
V_9 -> V_10 = F_34 ( V_49 , V_52 ,
& V_58 , V_9 ) ;
if ( ! V_9 -> V_10 )
return;
V_55 = F_35 ( V_9 -> V_10 , V_52 , 2 ,
L_3 , V_59 ,
V_60 , 0 ,
V_61 ) ;
if ( V_55 ) {
F_36 ( V_9 -> V_38 , L_4 ) ;
F_37 ( V_9 -> V_10 ) ;
V_9 -> V_10 = NULL ;
return;
}
V_51 = F_38 ( V_9 -> V_10 , 0 ) ;
if ( ! V_51 ) {
F_37 ( V_9 -> V_10 ) ;
V_9 -> V_10 = NULL ;
return;
}
V_51 -> V_62 = V_9 -> V_13 ;
V_51 -> V_33 = V_9 ;
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
V_54 = & V_51 -> V_63 [ V_56 ] ;
V_54 -> V_21 . V_64 = V_65 ;
V_54 -> V_21 . V_66 = V_67 ;
V_54 -> V_21 . V_68 = V_69 ;
V_54 -> V_21 . V_70 = F_29 ;
V_54 -> V_21 . V_71 = F_18 ;
V_54 -> V_21 . V_72 = F_22 ;
V_54 -> V_21 . V_73 = F_23 ;
V_54 -> V_21 . V_74 = F_27 ;
V_54 -> V_13 . V_75 = V_76 ;
V_54 -> V_13 . V_77 = V_78 ;
V_54 -> type = V_79 ;
}
V_51 -> V_63 [ 0 ] . type = V_79 ;
V_51 -> V_63 [ 1 ] . type = V_27 ;
V_51 -> V_63 [ 1 ] . V_80 = V_81 ;
F_39 ( V_17 , F_10 ) ;
F_40 ( V_17 , V_9 ) ;
for ( V_24 = 0 ; V_24 < V_52 ; V_24 ++ )
F_41 ( V_9 -> V_10 , V_24 ) ;
V_7 -> V_5 . V_2 . V_82 = F_1 ;
}
static void F_42 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = & V_9 -> V_15 [ 0 ] ;
struct V_1 * V_2 = & V_7 -> V_5 . V_2 ;
unsigned int V_52 = V_2 -> V_52 ;
T_2 V_24 ;
if ( ! V_9 -> V_10 )
return;
for ( V_24 = 0 ; V_24 < V_52 ; V_24 ++ )
F_43 ( F_4 ( V_9 -> V_10 , V_24 ) ) ;
F_37 ( V_9 -> V_10 ) ;
V_9 -> V_10 = NULL ;
}
static int F_44 ( struct V_8 * V_9 ,
struct V_48 * V_83 ,
unsigned int V_11 )
{
struct V_6 * V_7 ;
T_1 V_84 , V_52 ;
void T_3 * V_85 , * V_86 , * V_87 ;
int V_55 ;
if ( F_45 ( V_83 , L_5 , & V_84 ) ||
V_84 >= V_88 ) {
F_26 ( V_9 -> V_38 , L_6 ,
V_83 -> V_57 ) ;
return - V_39 ;
}
V_7 = & V_9 -> V_15 [ V_11 ] ;
V_7 -> V_9 = V_9 ;
if ( F_45 ( V_83 , L_7 , & V_52 ) ) {
F_36 ( V_9 -> V_38 , L_8 ,
V_83 -> V_57 ) ;
V_52 = 32 ;
}
V_85 = V_9 -> V_13 + V_89 + ( V_84 * V_90 ) ;
V_86 = V_9 -> V_13 + V_91 + ( V_84 * V_92 ) ;
V_87 = V_9 -> V_13 + V_93 +
( V_84 * V_94 ) ;
V_55 = F_46 ( & V_7 -> V_5 , V_9 -> V_38 , 4 , V_85 , V_86 , NULL , V_87 ,
NULL , false ) ;
if ( V_55 ) {
F_26 ( V_9 -> V_38 , L_9 ,
V_83 -> V_57 ) ;
return V_55 ;
}
V_7 -> V_5 . V_2 . V_52 = V_52 ;
V_7 -> V_5 . V_2 . V_50 = V_83 ;
if ( V_84 == 0 &&
F_47 ( V_83 , L_10 ) )
F_31 ( V_9 , V_7 ) ;
V_55 = F_48 ( & V_7 -> V_5 . V_2 ) ;
if ( V_55 )
F_26 ( V_9 -> V_38 , L_11 ,
V_83 -> V_57 ) ;
else
V_7 -> V_95 = true ;
return V_55 ;
}
static void F_49 ( struct V_8 * V_9 )
{
unsigned int V_96 ;
for ( V_96 = 0 ; V_96 < V_9 -> V_97 ; ++ V_96 )
if ( V_9 -> V_15 [ V_96 ] . V_95 )
F_50 ( F_51 ( & V_9 -> V_15 [ V_96 ] . V_5 . V_2 ) ) ;
}
static int F_52 ( struct V_98 * V_99 )
{
struct V_100 * V_101 ;
struct V_8 * V_9 ;
struct V_48 * V_102 ;
int V_55 ;
unsigned int V_11 = 0 ;
V_9 = F_53 ( & V_99 -> V_38 , sizeof( * V_9 ) , V_103 ) ;
if ( ! V_9 )
return - V_104 ;
V_9 -> V_38 = & V_99 -> V_38 ;
V_9 -> V_97 = F_54 ( V_99 -> V_38 . V_50 ) ;
if ( ! V_9 -> V_97 ) {
V_55 = - V_39 ;
goto V_105;
}
V_9 -> V_15 = F_53 ( & V_99 -> V_38 , V_9 -> V_97 *
sizeof( * V_9 -> V_15 ) , V_103 ) ;
if ( ! V_9 -> V_15 ) {
V_55 = - V_104 ;
goto V_105;
}
V_101 = F_55 ( V_99 , V_106 , 0 ) ;
V_9 -> V_13 = F_56 ( & V_99 -> V_38 , V_101 ) ;
if ( F_57 ( V_9 -> V_13 ) ) {
V_55 = F_58 ( V_9 -> V_13 ) ;
goto V_105;
}
F_59 (pdev->dev.of_node, np) {
V_55 = F_44 ( V_9 , V_102 , V_11 ++ ) ;
if ( V_55 )
goto V_107;
}
F_60 ( V_99 , V_9 ) ;
return 0 ;
V_107:
F_49 ( V_9 ) ;
F_42 ( V_9 ) ;
V_105:
return V_55 ;
}
static int F_61 ( struct V_98 * V_99 )
{
struct V_8 * V_9 = F_62 ( V_99 ) ;
F_49 ( V_9 ) ;
F_42 ( V_9 ) ;
return 0 ;
}
