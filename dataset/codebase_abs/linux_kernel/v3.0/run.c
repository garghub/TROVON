void F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
if ( V_4 ) {
switch( V_2 ) {
case 0 :
V_4 -> V_5 . V_6 = V_1 -> V_6 ;
V_4 -> V_5 . V_7 = V_1 -> V_7 ;
break;
case 1 :
V_4 -> V_5 . V_8 = V_1 -> V_8 ;
V_4 -> V_5 . V_9 = V_1 -> V_9 ;
break;
case 2 :
break;
}
F_2 () ;
F_3 ( & V_4 -> V_10 ) ;
}
}
int F_4 ( struct V_3 * V_4 , T_1 * V_11 )
{
T_2 V_12 ;
T_1 V_13 ;
V_13 = V_14 | V_15 |
V_16 | V_17 ;
V_18:
* V_11 = V_4 -> V_19 -> V_20 ( V_4 ) ;
if ( * V_11 & V_13 ) {
if ( * V_11 & V_21 )
goto V_18;
return 1 ;
}
if ( F_5 ( V_22 , & V_4 -> V_23 ) )
return 1 ;
V_12 = V_4 -> V_5 . V_8 ;
if ( V_12 & ( V_24 | V_25 ) )
return 1 ;
if ( V_4 -> V_5 . V_6 )
return 1 ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 )
{
int V_26 ;
T_2 T_3 * V_27 ;
T_2 V_28 ;
T_1 V_29 ;
unsigned long V_30 ;
const T_1 V_31 = V_21
| V_32 | V_33 ;
V_26 = - V_34 ;
if ( ! V_35 )
goto V_36;
F_7 ( V_4 ) ;
V_27 = & V_4 -> V_1 -> V_37 -> V_38 ;
V_30 = V_39 + V_40 ;
F_8 ( V_27 , V_41 ) ;
while ( ( F_9 ( V_27 ) & V_42 )
!= V_43 ) {
if ( F_10 ( V_39 , V_30 ) ) {
F_11 ( V_44 L_1 ,
V_45 ) ;
V_26 = - V_46 ;
goto V_36;
}
F_12 () ;
}
F_8 ( V_27 , 0 ) ;
V_28 = F_13 ( V_4 -> V_1 ) ;
V_28 &= ~ V_47 ;
F_14 ( V_4 -> V_1 , V_28 ) ;
V_4 -> V_19 -> V_48 ( V_4 , ( unsigned long ) V_35 >> 32 ) ;
V_4 -> V_19 -> V_49 ( V_4 ,
( unsigned long ) V_35 & 0xffffffff ) ;
V_4 -> V_19 -> V_50 ( V_4 ,
V_51 | V_52 ) ;
V_26 = 0 ;
V_30 = V_39 + V_40 ;
while ( ( ( V_29 = V_4 -> V_19 -> V_20 ( V_4 ) ) & V_31 ) ==
V_31 ) {
if ( F_10 ( V_39 , V_30 ) ) {
F_11 ( V_44 L_2 ,
V_45 ) ;
V_26 = - V_46 ;
goto V_53;
}
F_12 () ;
}
if ( ! ( V_29 & V_21 ) ) {
F_15 ( L_3 , V_45 ) ;
V_4 -> V_19 -> V_50 ( V_4 , V_51 ) ;
V_26 = - V_54 ;
goto V_53;
}
if ( ! ( V_29 & V_32 ) ) {
F_15 ( L_4 , V_45 ) ;
V_4 -> V_19 -> V_50 ( V_4 , V_55 ) ;
V_26 = - V_56 ;
goto V_53;
}
V_53:
V_28 |= V_47 ;
F_14 ( V_4 -> V_1 , V_28 ) ;
V_36:
return V_26 ;
}
static int F_16 ( struct V_3 * V_4 , T_1 * V_57 )
{
unsigned long V_58 = V_51 ;
int V_26 ;
F_17 ( V_4 , V_59 ) ;
if ( V_4 -> V_60 & V_61 ) {
if ( V_4 -> V_62 == V_63 ) {
V_26 = F_18 ( V_4 , 0 ) ;
if ( V_26 )
return V_26 ;
}
}
if ( V_4 -> V_60 & V_64 ) {
if ( ! ( V_4 -> V_19 -> V_20 ( V_4 ) & V_32 ) ) {
V_26 = F_6 ( V_4 ) ;
if ( V_26 )
return V_26 ;
}
V_58 = V_4 -> V_19 -> V_65 ( V_4 ) &
( V_51 | V_52 ) ;
if ( V_58 == 0 )
V_58 = V_51 ;
} else {
unsigned long V_66 ;
if ( F_19 ( V_67 ) )
V_66 = V_68 ;
else
V_66 = V_69 ;
V_4 -> V_19 -> V_70 ( V_4 , V_66 ) ;
V_4 -> V_19 -> V_71 ( V_4 , * V_57 ) ;
}
V_4 -> V_19 -> V_50 ( V_4 , V_58 ) ;
if ( V_4 -> V_60 & V_61 ) {
F_17 ( V_4 , V_72 ) ;
} else {
if ( V_4 -> V_62 == V_63 ) {
V_26 = F_18 ( V_4 , 0 ) ;
if ( V_26 )
return V_26 ;
} else {
F_17 ( V_4 , V_72 ) ;
}
}
F_20 ( V_73 , & V_4 -> V_23 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 , T_1 * V_57 ,
T_1 * V_29 )
{
int V_26 = 0 ;
F_22 ( V_4 ) ;
* V_29 = V_4 -> V_19 -> V_20 ( V_4 ) ;
* V_57 = V_4 -> V_19 -> V_74 ( V_4 ) ;
F_17 ( V_4 , V_75 ) ;
F_23 ( V_73 , & V_4 -> V_23 ) ;
F_24 ( NULL , V_4 , V_76 , * V_29 ) ;
F_25 ( V_4 ) ;
if ( F_26 ( V_77 ) )
V_26 = - V_78 ;
return V_26 ;
}
static int F_27 ( struct V_3 * V_4 , long * V_79 ,
unsigned int * V_57 )
{
int V_26 ;
switch ( * V_79 ) {
case - V_78 :
case - V_80 :
* V_57 -= 8 ;
V_26 = - V_78 ;
break;
case - V_81 :
case - V_82 :
* V_79 = - V_83 ;
V_26 = - V_78 ;
break;
default:
F_11 ( V_84 L_5 ,
V_45 , * V_79 ) ;
V_26 = 0 ;
}
return V_26 ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_85 V_86 ;
T_1 V_87 , V_57 ;
void T_3 * V_88 ;
long V_79 ;
int V_26 ;
V_57 = V_4 -> V_19 -> V_74 ( V_4 ) & ~ 3 ;
V_88 = ( void T_3 * ) V_4 -> V_19 -> V_89 ( V_4 ) ;
V_87 = F_29 ( V_88 + V_57 ) ;
if ( V_87 > ( V_90 - sizeof( V_86 ) ) )
return - V_91 ;
F_30 ( & V_86 , V_88 + V_87 , sizeof( V_86 ) ) ;
V_26 = 0 ;
V_79 = - V_92 ;
V_57 += 4 ;
if ( V_86 . V_93 < V_94 ) {
F_25 ( V_4 ) ;
V_79 = F_31 ( & V_86 ) ;
if ( V_79 <= - V_78 ) {
V_26 = F_27 ( V_4 , & V_79 , & V_57 ) ;
}
F_32 ( & V_4 -> V_95 ) ;
if ( V_26 == - V_78 )
return V_26 ;
}
V_88 = ( void T_3 * ) V_4 -> V_19 -> V_89 ( V_4 ) ;
F_33 ( V_88 + V_87 , & V_79 , sizeof( V_79 ) ) ;
V_4 -> V_19 -> V_71 ( V_4 , V_57 ) ;
V_4 -> V_19 -> V_50 ( V_4 , V_51 ) ;
return V_26 ;
}
long F_34 ( struct V_3 * V_4 , T_1 * V_57 , T_1 * V_96 )
{
int V_26 ;
struct V_1 * V_1 ;
T_1 V_29 ;
if ( F_35 ( & V_4 -> V_97 ) )
return - V_78 ;
V_4 -> V_98 = 0 ;
V_26 = F_36 ( V_4 ) ;
if ( V_26 )
goto V_99;
F_37 ( V_4 ) ;
F_38 ( V_4 ) ;
V_26 = F_16 ( V_4 , V_57 ) ;
if ( V_26 ) {
F_25 ( V_4 ) ;
goto V_36;
}
do {
V_26 = F_39 ( V_4 -> V_10 , F_4 ( V_4 , & V_29 ) ) ;
if ( F_40 ( V_26 ) ) {
F_32 ( & V_4 -> V_95 ) ;
break;
}
V_1 = V_4 -> V_1 ;
if ( F_40 ( F_41 ( V_22 ,
& V_4 -> V_23 ) ) ) {
if ( ! ( V_29 & V_17 ) ) {
F_42 ( V_1 , V_4 ) ;
continue;
}
}
F_17 ( V_4 , V_59 ) ;
if ( ( V_29 & V_17 ) &&
( V_29 >> V_100 == 0x2104 ) ) {
V_26 = F_28 ( V_4 ) ;
if ( V_26 )
break;
V_29 &= ~ V_17 ;
}
V_26 = F_43 ( V_4 ) ;
if ( V_26 )
break;
V_26 = F_44 ( V_4 ) ;
if ( V_26 )
break;
if ( F_26 ( V_77 ) )
V_26 = - V_78 ;
} while ( ! V_26 && ! ( V_29 & ( V_17 |
V_16 |
V_15 ) ) );
F_45 ( V_4 ) ;
V_26 = F_21 ( V_4 , V_57 , & V_29 ) ;
F_46 ( V_4 ) ;
if ( ( V_29 & V_17 ) &&
( ( ( V_29 >> V_100 ) & 0x3f00 ) == 0x2100 ) )
V_4 -> V_101 . V_102 ++ ;
if ( ( V_26 == 0 ) ||
( ( V_26 == - V_78 ) &&
( ( V_29 & V_16 ) ||
( V_29 & V_15 ) ||
( ( V_29 & V_17 ) &&
( V_29 >> V_100 != 0x2104 ) ) ) ) )
V_26 = V_29 ;
if ( F_40 ( V_29 & V_15 ) )
V_26 = - V_78 ;
else if ( F_40 ( ( V_29 & V_17 )
&& ( V_29 >> V_100 ) == 0x3fff ) ) {
F_47 ( V_103 , V_77 ) ;
V_26 = - V_78 ;
}
V_36:
* V_96 = V_4 -> V_98 ;
V_99:
F_48 ( & V_4 -> V_97 ) ;
return V_26 ;
}
