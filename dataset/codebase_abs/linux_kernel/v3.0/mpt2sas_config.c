static void
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
char * V_4 , T_2 * V_5 )
{
T_3 * V_6 ;
char * V_7 = NULL ;
if ( ! ( V_2 -> V_8 & V_9 ) )
return;
V_6 = F_2 ( V_2 , V_3 ) ;
switch ( V_6 -> V_10 . V_11 & V_12 ) {
case V_13 :
V_7 = L_1 ;
break;
case V_14 :
V_7 = L_2 ;
break;
case V_15 :
V_7 = L_3 ;
break;
case V_16 :
V_7 = L_4 ;
break;
case V_17 :
V_7 = L_5 ;
break;
case V_18 :
V_7 = L_6 ;
break;
case V_19 :
switch ( V_6 -> V_20 ) {
case V_21 :
V_7 = L_7 ;
break;
case V_22 :
V_7 = L_8 ;
break;
case V_23 :
V_7 = L_9 ;
break;
case V_24 :
V_7 = L_10 ;
break;
case V_25 :
V_7 = L_11 ;
break;
case V_26 :
V_7 = L_12 ;
break;
case V_27 :
V_7 = L_13 ;
break;
case V_28 :
V_7 = L_14 ;
break;
}
break;
}
if ( ! V_7 )
return;
F_3 ( V_29 L_15
L_16 , V_2 -> V_30 , V_4 , V_7 ,
V_6 -> V_10 . V_31 , V_6 -> V_32 ,
F_4 ( V_6 -> V_33 ) , V_3 ) ;
if ( ! V_5 )
return;
if ( V_5 -> V_34 || V_5 -> V_35 )
F_3 ( V_29
L_17 ,
V_2 -> V_30 , F_5 ( V_5 -> V_34 ) ,
F_4 ( V_5 -> V_35 ) ) ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_38 = 0 ;
if ( V_37 -> V_39 > V_2 -> V_40 ) {
V_37 -> V_41 = F_7 ( & V_2 -> V_42 -> V_43 , V_37 -> V_39 ,
& V_37 -> V_44 , V_45 ) ;
if ( ! V_37 -> V_41 ) {
F_3 ( V_46 L_18
L_19 ,
V_2 -> V_30 , V_47 , V_37 -> V_39 ) ;
V_38 = - V_48 ;
}
} else {
V_37 -> V_41 = V_2 -> V_49 ;
V_37 -> V_44 = V_2 -> V_50 ;
}
return V_38 ;
}
static void
F_8 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
if ( V_37 -> V_39 > V_2 -> V_40 )
F_9 ( & V_2 -> V_42 -> V_43 , V_37 -> V_39 , V_37 -> V_41 ,
V_37 -> V_44 ) ;
}
T_4
F_10 ( struct V_1 * V_2 , T_1 V_3 , T_4 V_51 ,
T_5 V_52 )
{
T_2 * V_5 ;
if ( V_2 -> V_53 . V_54 == V_55 )
return 1 ;
if ( V_2 -> V_53 . V_3 != V_3 )
return 1 ;
V_2 -> V_53 . V_54 |= V_56 ;
V_5 = F_11 ( V_2 , V_52 ) ;
if ( V_5 ) {
V_2 -> V_53 . V_54 |= V_57 ;
memcpy ( V_2 -> V_53 . V_52 , V_5 ,
V_5 -> V_58 * 4 ) ;
}
V_2 -> V_53 . V_54 &= ~ V_59 ;
#ifdef F_12
F_1 ( V_2 , V_3 , L_20 , V_5 ) ;
#endif
V_2 -> V_53 . V_3 = V_60 ;
F_13 ( & V_2 -> V_53 . V_61 ) ;
return 1 ;
}
static int
F_14 ( struct V_1 * V_2 , T_3
* V_6 , T_6 * V_5 , int V_62 ,
void * V_49 , T_1 V_40 )
{
T_1 V_3 ;
T_5 V_63 ;
unsigned long V_64 ;
T_3 * V_36 ;
int V_38 ;
T_4 V_65 , V_66 = 0 ;
T_1 V_67 ;
struct V_36 V_37 ;
F_15 ( & V_2 -> V_53 . V_68 ) ;
if ( V_2 -> V_53 . V_54 != V_55 ) {
F_3 ( V_46 L_21 ,
V_2 -> V_30 , V_47 ) ;
F_16 ( & V_2 -> V_53 . V_68 ) ;
return - V_69 ;
}
V_65 = 0 ;
memset ( & V_37 , 0 , sizeof( struct V_36 ) ) ;
V_6 -> V_70 = 0 ;
V_6 -> V_71 = 0 ;
if ( V_49 ) {
V_6 -> V_10 . V_72 = V_5 -> V_10 . V_72 ;
V_6 -> V_10 . V_31 = V_5 -> V_10 . V_31 ;
V_6 -> V_10 . V_11 = V_5 -> V_10 . V_11 ;
V_6 -> V_10 . V_73 = V_5 -> V_10 . V_73 ;
V_6 -> V_74 = V_5 -> V_74 ;
V_6 -> V_20 = V_5 -> V_20 ;
if ( V_6 -> V_10 . V_73 )
V_37 . V_39 = V_6 -> V_10 . V_73 * 4 ;
else
V_37 . V_39 = F_5 ( V_5 -> V_74 ) * 4 ;
V_38 = F_6 ( V_2 , & V_37 ) ;
if ( V_38 != 0 )
goto V_75;
if ( V_6 -> V_32 ==
V_76 ||
V_6 -> V_32 ==
V_77 ) {
V_2 -> V_78 ( & V_6 -> V_79 ,
V_80 | V_37 . V_39 ,
V_37 . V_44 ) ;
memcpy ( V_37 . V_41 , V_49 , F_17 ( T_1 , V_37 . V_39 ,
V_40 ) ) ;
} else {
memset ( V_49 , 0 , V_40 ) ;
V_2 -> V_78 ( & V_6 -> V_79 ,
V_81 | V_37 . V_39 , V_37 . V_44 ) ;
}
}
V_82:
if ( V_65 ) {
if ( V_65 > 2 ) {
V_38 = - V_83 ;
goto V_84;
}
F_3 ( V_29 L_22 ,
V_2 -> V_30 , V_47 , V_65 ) ;
}
V_67 = 0 ;
V_63 = F_18 ( V_2 , 1 ) ;
while ( V_63 != V_85 ) {
if ( V_67 ++ == V_86 ) {
F_3 ( V_46
L_23 ,
V_2 -> V_30 , V_47 ) ;
V_2 -> V_53 . V_54 = V_55 ;
V_38 = - V_83 ;
goto V_84;
}
F_19 ( 1 ) ;
V_63 = F_18 ( V_2 , 1 ) ;
F_3 ( V_29 L_24
L_25 , V_2 -> V_30 ,
V_47 , V_67 ) ;
}
if ( V_67 )
F_3 ( V_29 L_26 ,
V_2 -> V_30 , V_47 ) ;
V_3 = F_20 ( V_2 , V_2 -> V_87 ) ;
if ( ! V_3 ) {
F_3 ( V_46 L_27 ,
V_2 -> V_30 , V_47 ) ;
V_2 -> V_53 . V_54 = V_55 ;
V_38 = - V_69 ;
goto V_84;
}
V_38 = 0 ;
memset ( V_5 , 0 , sizeof( T_6 ) ) ;
V_2 -> V_53 . V_54 = V_59 ;
V_36 = F_2 ( V_2 , V_3 ) ;
V_2 -> V_53 . V_3 = V_3 ;
memcpy ( V_36 , V_6 , sizeof( T_3 ) ) ;
#ifdef F_12
F_1 ( V_2 , V_3 , L_28 , NULL ) ;
#endif
F_21 ( & V_2 -> V_53 . V_61 ) ;
F_22 ( V_2 , V_3 ) ;
V_64 = F_23 ( & V_2 -> V_53 . V_61 ,
V_62 * V_88 ) ;
if ( ! ( V_2 -> V_53 . V_54 & V_56 ) ) {
F_3 ( V_46 L_29 ,
V_2 -> V_30 , V_47 ) ;
F_24 ( V_6 ,
sizeof( T_3 ) / 4 ) ;
V_65 ++ ;
if ( V_2 -> V_53 . V_3 == V_3 )
F_25 ( V_2 , V_3 ) ;
if ( ( V_2 -> V_89 ) || ( V_2 -> V_53 . V_54 &
V_90 ) || V_2 -> V_91 )
goto V_82;
V_66 = 1 ;
V_38 = - V_83 ;
goto V_84;
}
if ( V_2 -> V_53 . V_54 & V_57 )
memcpy ( V_5 , V_2 -> V_53 . V_52 ,
sizeof( T_6 ) ) ;
if ( V_65 )
F_3 ( V_29 L_30 ,
V_2 -> V_30 , V_47 , V_65 ) ;
if ( V_49 && V_6 -> V_32 ==
V_92 )
memcpy ( V_49 , V_37 . V_41 , F_17 ( T_1 , V_37 . V_39 ,
V_40 ) ) ;
V_84:
if ( V_49 )
F_8 ( V_2 , & V_37 ) ;
V_75:
V_2 -> V_53 . V_54 = V_55 ;
F_16 ( & V_2 -> V_53 . V_68 ) ;
if ( V_66 )
F_26 ( V_2 , V_93 ,
V_94 ) ;
return V_38 ;
}
int
F_27 ( struct V_1 * V_2 ,
T_6 * V_5 , T_7 * V_49 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_17 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_98 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_29 ( struct V_1 * V_2 ,
T_6 * V_5 , T_8 * V_49 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_17 ;
V_6 . V_10 . V_31 = 10 ;
V_6 . V_10 . V_72 = V_98 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_30 ( struct V_1 * V_2 ,
T_6 * V_5 , T_9 * V_49 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_15 ;
V_6 . V_10 . V_31 = 2 ;
V_6 . V_10 . V_72 = V_99 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_31 ( struct V_1 * V_2 , T_6
* V_5 , T_10 * V_49 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_15 ;
V_6 . V_10 . V_31 = 3 ;
V_6 . V_10 . V_72 = V_100 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_32 ( struct V_1 * V_2 ,
T_6 * V_5 , T_11 * V_49 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_13 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_101 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_33 ( struct V_1 * V_2 ,
T_6 * V_5 , T_12 * V_49 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_13 ;
V_6 . V_10 . V_31 = 1 ;
V_6 . V_10 . V_72 = V_102 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_34 ( struct V_1 * V_2 ,
T_6 * V_5 , T_12 * V_49 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_13 ;
V_6 . V_10 . V_31 = 1 ;
V_6 . V_10 . V_72 = V_102 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_76 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_35 ( struct V_1 * V_2 ,
T_6 * V_5 , T_13 * V_49 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_14 ;
V_6 . V_10 . V_31 = 8 ;
V_6 . V_10 . V_72 = V_103 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_36 ( struct V_1 * V_2 , T_6
* V_5 , T_14 * V_49 , T_5 V_104 , T_5 V_105 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_23 ;
V_6 . V_10 . V_72 = V_106 ;
V_6 . V_10 . V_31 = 0 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 = F_37 ( V_104 | V_105 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_38 ( struct V_1 * V_2 , T_6
* V_5 , T_15 * V_49 , T_5 V_104 , T_5 V_105 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_23 ;
V_6 . V_10 . V_72 = V_107 ;
V_6 . V_10 . V_31 = 1 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 = F_37 ( V_104 | V_105 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_39 ( struct V_1 * V_2 , T_4 * V_108 )
{
T_3 V_6 ;
int V_38 ;
T_1 V_109 ;
T_6 V_5 ;
T_16 V_49 ;
* V_108 = 0 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_21 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_110 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , & V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , & V_5 ,
V_86 , & V_49 ,
sizeof( T_16 ) ) ;
if ( ! V_38 ) {
V_109 = F_5 ( V_5 . V_34 ) &
V_111 ;
if ( V_109 == V_112 )
* V_108 = V_49 . V_113 ;
}
V_75:
return V_38 ;
}
int
F_40 ( struct V_1 * V_2 , T_6
* V_5 , T_16 * V_49 , T_1 V_39 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_21 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_110 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 , V_39 ) ;
V_75:
return V_38 ;
}
int
F_41 ( struct V_1 * V_2 , T_6
* V_5 , T_17 * V_49 , T_1 V_39 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_21 ;
V_6 . V_10 . V_31 = 1 ;
V_6 . V_10 . V_72 = V_114 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 , V_39 ) ;
V_75:
return V_38 ;
}
int
F_42 ( struct V_1 * V_2 , T_6
* V_5 , T_17 * V_49 , T_1 V_39 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_21 ;
V_6 . V_10 . V_31 = 1 ;
V_6 . V_10 . V_72 = V_114 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_32 = V_76 ;
F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 , V_39 ) ;
V_6 . V_32 = V_77 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 , V_39 ) ;
V_75:
return V_38 ;
}
int
F_43 ( struct V_1 * V_2 , T_6
* V_5 , T_18 * V_49 , T_5 V_104 , T_5 V_105 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_22 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_115 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 = F_37 ( V_104 | V_105 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_44 ( struct V_1 * V_2 , T_6
* V_5 , T_19 * V_49 , T_5 V_116 ,
T_1 V_105 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_22 ;
V_6 . V_10 . V_31 = 1 ;
V_6 . V_10 . V_72 = V_117 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 =
F_37 ( V_118 |
( V_116 << V_119 ) | V_105 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_45 ( struct V_1 * V_2 , T_6
* V_5 , T_20 * V_49 , T_5 V_104 , T_5 V_105 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_26 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_120 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 = F_37 ( V_104 | V_105 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_46 ( struct V_1 * V_2 , T_6
* V_5 , T_21 * V_49 , T_5 V_116 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_24 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_121 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 =
F_37 ( V_122 | V_116 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_47 ( struct V_1 * V_2 , T_6
* V_5 , T_22 * V_49 , T_5 V_116 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_24 ;
V_6 . V_10 . V_31 = 1 ;
V_6 . V_10 . V_72 = V_123 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 =
F_37 ( V_122 | V_116 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_48 ( struct V_1 * V_2 ,
T_6 * V_5 , T_23 * V_49 , T_5 V_104 ,
T_5 V_105 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_16 ;
V_6 . V_10 . V_31 = 1 ;
V_6 . V_10 . V_72 = V_124 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 = F_37 ( V_104 | V_105 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_49 ( struct V_1 * V_2 , T_1 V_105 ,
T_4 * V_125 )
{
T_3 V_6 ;
T_24 V_49 ;
T_6 V_5 ;
int V_38 ;
T_1 V_109 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
* V_125 = 0 ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_16 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_126 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , & V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 =
F_37 ( V_127 | V_105 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , & V_5 ,
V_86 , & V_49 ,
sizeof( T_24 ) ) ;
if ( ! V_38 ) {
V_109 = F_5 ( V_5 . V_34 ) &
V_111 ;
if ( V_109 == V_112 )
* V_125 = V_49 . V_128 ;
}
V_75:
return V_38 ;
}
int
F_50 ( struct V_1 * V_2 ,
T_6 * V_5 , T_24 * V_49 , T_5 V_104 ,
T_5 V_105 , T_1 V_39 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_16 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_126 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 = F_37 ( V_104 | V_105 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 , V_39 ) ;
V_75:
return V_38 ;
}
int
F_51 ( struct V_1 * V_2 , T_6
* V_5 , T_25 * V_49 , T_5 V_104 ,
T_5 V_129 )
{
T_3 V_6 ;
int V_38 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_18 ;
V_6 . V_10 . V_31 = 0 ;
V_6 . V_10 . V_72 = V_130 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 = F_37 ( V_104 | V_129 ) ;
V_6 . V_32 = V_92 ;
V_38 = F_14 ( V_2 , & V_6 , V_5 ,
V_86 , V_49 ,
sizeof( * V_49 ) ) ;
V_75:
return V_38 ;
}
int
F_52 ( struct V_1 * V_2 , T_1 V_131 ,
T_1 * V_132 )
{
T_26 * V_49 = NULL ;
T_3 V_6 ;
T_6 V_5 ;
int V_38 , V_133 , V_40 ;
T_1 V_109 ;
* V_132 = 0 ;
memset ( & V_6 , 0 , sizeof( T_3 ) ) ;
V_6 . V_95 = V_96 ;
V_6 . V_32 = V_97 ;
V_6 . V_10 . V_11 = V_19 ;
V_6 . V_20 = V_27 ;
V_6 . V_10 . V_72 = V_134 ;
V_6 . V_10 . V_31 = 0 ;
F_28 ( V_2 , & V_6 . V_79 ) ;
V_38 = F_14 ( V_2 , & V_6 , & V_5 ,
V_86 , NULL , 0 ) ;
if ( V_38 )
goto V_75;
V_6 . V_33 =
F_37 ( V_135 ) ;
V_6 . V_32 = V_92 ;
V_40 = ( F_5 ( V_5 . V_74 ) * 4 ) ;
V_49 = F_53 ( V_40 , V_45 ) ;
if ( ! V_49 )
goto V_75;
V_38 = F_14 ( V_2 , & V_6 , & V_5 ,
V_86 , V_49 ,
V_40 ) ;
if ( V_38 )
goto V_75;
V_38 = - 1 ;
V_109 = F_5 ( V_5 . V_34 ) & V_111 ;
if ( V_109 != V_112 )
goto V_75;
for ( V_133 = 0 ; V_133 < V_49 -> V_136 ; V_133 ++ ) {
if ( ( F_5 ( V_49 -> V_137 [ V_133 ] . V_138 ) &
V_139 ) !=
V_140 )
continue;
if ( F_5 ( V_49 -> V_137 [ V_133 ] .
V_141 ) == V_131 ) {
* V_132 = F_5 ( V_49 ->
V_137 [ V_133 ] . V_142 ) ;
V_38 = 0 ;
goto V_75;
}
}
V_75:
F_54 ( V_49 ) ;
return V_38 ;
}
int
F_55 ( struct V_1 * V_2 , T_1 V_132 ,
T_27 * V_143 )
{
T_6 V_5 ;
T_23 V_144 ;
* V_143 = 0 ;
if ( ! ( F_48 ( V_2 , & V_5 ,
& V_144 , V_127 ,
V_132 ) ) ) {
* V_143 = F_56 ( V_144 . V_145 ) ;
return 0 ;
} else
return - 1 ;
}
