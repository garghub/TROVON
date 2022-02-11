T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_7 V_8 ;
struct V_9 * V_10 = V_6 -> V_11 . V_10 ;
bool V_12 ;
unsigned V_13 ;
int V_14 ;
int V_15 ;
if ( V_6 -> V_16 )
return - V_17 ;
if ( V_3 < sizeof( * V_10 ) )
return 0 ;
V_3 = sizeof( * V_10 ) * ( V_3 / sizeof( * V_10 ) ) ;
if ( F_3 ( & V_6 -> V_18 ) )
return - V_19 ;
if ( V_6 -> V_20 &&
V_1 -> V_21 != V_6 -> V_20 ) {
F_4 ( & V_6 -> V_18 ) ;
return - V_22 ;
}
if ( V_6 -> V_20 == NULL ) {
F_5 ( V_6 ) ;
V_6 -> V_20 = V_1 -> V_21 ;
}
V_23:
F_6 ( & V_8 ) ;
V_12 = V_8 . V_24 % 10 >= 5 ;
if ( V_6 -> V_25 == 0 ||
V_6 -> V_26 != V_12 ) {
V_6 -> V_26 = V_12 ;
F_5 ( V_6 ) ;
}
V_8 = F_7 ( V_8 , V_6 -> V_27 ) ;
V_13 = V_8 . V_24 * 100 + V_8 . V_28 / 10000000 ;
V_13 = ( V_13 * V_29 ) / 500 ;
if ( V_13 >= V_6 -> V_25 + V_29 )
V_6 -> V_25 = V_13 - V_29 + 1 ;
if ( V_13 == V_6 -> V_25 || ! V_6 -> V_30 ||
( V_6 -> V_31 && ! ( V_6 -> V_32 & V_33 ) ) ||
abs ( V_6 -> V_34 ) > 200 ) {
F_4 ( & V_6 -> V_18 ) ;
if ( V_1 -> V_35 & V_36 )
return - V_37 ;
if ( F_8 ( 20 ) && F_9 ( V_38 ) )
return - V_39 ;
if ( F_3 ( & V_6 -> V_18 ) )
return - V_19 ;
goto V_23;
}
V_14 = abs ( V_6 -> V_34 ) / 4 ;
for ( V_15 = 0 ; V_15 < V_3 && V_13 > V_6 -> V_25 ;
V_6 -> V_25 ++ ) {
unsigned V_40 = V_6 -> V_25 % V_29 ;
struct V_9 V_41 = V_10 [ V_40 ] ;
if ( V_40 == 0 && V_6 -> V_31 )
F_5 ( V_6 ) ;
if ( V_14 && F_10 ( 100 ) < V_14 ) {
switch ( F_10 ( 4 ) ) {
case 0 :
V_41 . V_42 |= V_43 ;
break;
case 1 :
V_41 . V_42 |= V_44 ;
break;
case 2 :
V_41 . V_42 |= V_45 ;
V_41 . V_46 = F_10 ( 256 ) ;
V_41 . V_47 = F_10 ( 256 ) ;
break;
case 3 :
if ( V_15 )
continue;
break;
}
}
if ( F_11 ( V_2 + V_15 , & V_41 , sizeof( V_41 ) ) ) {
V_15 = - V_48 ;
break;
}
V_15 += sizeof( V_41 ) ;
}
F_4 ( & V_6 -> V_18 ) ;
return V_15 ;
}
unsigned int F_12 ( struct V_1 * V_1 , struct V_49 * V_50 )
{
return V_51 | V_52 | F_13 ( V_1 , V_50 ) ;
}
int F_14 ( struct V_1 * V_1 , void * V_53 , struct V_54 * V_55 )
{
if ( V_55 -> V_56 != 0 )
return - V_17 ;
if ( V_55 -> V_57 >= V_58 )
return - V_17 ;
* V_55 = V_59 [ V_55 -> V_57 ] ;
return 0 ;
}
int F_15 ( struct V_1 * V_1 , void * V_53 , const struct V_60 * V_61 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
unsigned V_62 , V_63 ;
unsigned V_64 ;
unsigned V_65 ;
unsigned V_55 ;
if ( V_61 -> V_56 )
return - V_17 ;
if ( V_61 -> V_66 && V_6 -> V_67 == V_68 )
return - V_17 ;
if ( ! V_61 -> V_66 && V_6 -> V_67 == V_69 )
return - V_17 ;
if ( ! V_61 -> V_70 ^ ! V_61 -> V_71 )
return - V_17 ;
if ( V_1 -> V_35 & V_36 )
return - V_37 ;
if ( V_61 -> V_70 ) {
for ( V_55 = 0 ; V_55 < V_58 ; V_55 ++ )
if ( V_61 -> V_70 >= V_59 [ V_55 ] . V_70 &&
V_61 -> V_71 <= V_59 [ V_55 ] . V_71 )
break;
if ( V_55 == V_58 )
return - V_17 ;
if ( ! V_6 -> V_72 &&
( V_61 -> V_70 != V_59 [ V_55 ] . V_70 ||
V_61 -> V_71 != V_59 [ V_55 ] . V_71 ) )
return - V_17 ;
V_62 = V_61 -> V_70 ;
V_63 = V_61 -> V_71 ;
} else {
for ( V_55 = 0 ; V_55 < V_58 ; V_55 ++ )
if ( V_6 -> V_73 >= V_59 [ V_55 ] . V_70 &&
V_6 -> V_73 <= V_59 [ V_55 ] . V_71 )
break;
V_62 = V_59 [ V_55 ] . V_70 ;
V_63 = V_59 [ V_55 ] . V_71 ;
}
V_65 = V_55 == V_74 ? 1600 : 16000 ;
V_64 = F_16 ( V_6 -> V_73 , V_62 , V_63 ) ;
if ( V_61 -> V_75 ) {
V_64 = V_65 * ( V_64 / V_65 ) + V_65 ;
if ( V_64 > V_63 ) {
if ( ! V_61 -> V_66 )
return - V_76 ;
V_64 = V_65 * ( V_62 / V_65 ) + V_65 ;
if ( V_64 >= V_6 -> V_73 )
return - V_76 ;
}
} else {
V_64 = V_65 * ( ( V_64 + V_65 - 1 ) / V_65 ) - V_65 ;
if ( V_64 < V_62 ) {
if ( ! V_61 -> V_66 )
return - V_76 ;
V_64 = V_65 * ( ( V_63 + V_65 - 1 ) / V_65 ) - V_65 ;
if ( V_64 <= V_6 -> V_73 )
return - V_76 ;
}
}
return 0 ;
}
int F_17 ( struct V_1 * V_1 , void * V_53 , struct V_77 * V_78 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
int V_79 = 800 ;
int V_80 ;
if ( V_78 -> V_57 > 0 )
return - V_17 ;
F_18 ( V_78 -> V_81 , L_1 , sizeof( V_78 -> V_81 ) ) ;
V_78 -> V_82 = V_83 | V_84 |
V_85 | V_86 |
( V_6 -> V_16 ?
V_87 :
V_88 ) |
( V_6 -> V_72 ?
V_89 : 0 ) ;
switch ( V_6 -> V_67 ) {
case V_68 :
V_78 -> V_82 |= V_90 ;
break;
case V_69 :
V_78 -> V_82 |= V_91 ;
break;
case V_92 :
V_78 -> V_82 |= V_91 |
V_90 ;
break;
}
V_78 -> V_70 = V_93 ;
V_78 -> V_71 = V_94 ;
V_80 = V_6 -> V_34 ;
V_78 -> signal = abs ( V_80 ) > V_79 ? 0 :
0xffff - ( abs ( V_80 ) * 0xffff ) / V_79 ;
V_78 -> V_95 = V_80 > V_79 ? 0 : V_80 ;
if ( abs ( V_80 ) > V_79 )
V_78 -> V_96 = 0 ;
else if ( V_6 -> V_73 < V_97 || V_78 -> signal < 0x8000 )
V_78 -> V_96 = V_98 ;
else if ( V_6 -> V_31 && ! ( V_6 -> V_32 & V_99 ) )
V_78 -> V_96 = V_98 ;
else
V_78 -> V_96 = V_99 ;
if ( V_6 -> V_30 &&
( ! V_6 -> V_31 || ( V_6 -> V_32 & V_33 ) ) &&
V_6 -> V_73 >= V_97 && V_78 -> signal >= 0xc000 )
V_78 -> V_96 |= V_33 ;
if ( V_6 -> V_16 )
F_5 ( V_6 ) ;
V_78 -> V_100 = V_6 -> V_101 ;
return 0 ;
}
int F_19 ( struct V_1 * V_1 , void * V_53 , const struct V_77 * V_78 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_78 -> V_57 )
return - V_17 ;
V_6 -> V_101 = V_78 -> V_100 >= V_102 ;
return 0 ;
}
