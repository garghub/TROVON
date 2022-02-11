void T_1 F_1 ( void )
{
F_2 ( L_1 , V_1 ) ;
F_3 ( & V_2 ) ;
F_4 ( & V_3 , 1 ) ;
F_4 ( & V_4 , 0 ) ;
V_5 = 0 ;
F_2 ( L_2 , V_1 ) ;
}
static T_2 F_5 ( struct V_6 * V_7 , void T_3 * V_8 , T_2 V_9 )
{
T_2 V_10 ;
int V_11 ;
void T_3 * V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_15 ;
F_6 ( L_3 , V_1 , V_8 , V_9 ) ;
if ( V_7 -> V_16 == 0x02 ) {
V_15 = V_17 ;
V_14 = ( unsigned long ) V_7 -> V_18 . V_19 . V_20 ;
V_14 = V_14 >> 1 ;
V_15 |= ( V_14 << 8 ) ;
V_15 |= ( unsigned long ) V_9 ;
} else if ( V_7 -> V_16 == 0x04 ) {
V_15 = V_21 ;
V_14 = ( unsigned long ) V_9 ;
V_14 = V_14 << 8 ;
V_15 |= V_14 ;
} else {
F_7 ( L_4 ) ;
return V_22 ;
}
V_13 = F_8 ( V_15 ) ;
V_12 = V_8 + V_23 ;
F_9 ( V_13 , V_12 ) ;
V_15 = 0x00000000 ;
V_13 = F_8 ( V_15 ) ;
V_12 = V_8 + V_24 ;
F_9 ( V_13 , V_12 ) ;
V_15 = V_25 ;
V_13 = F_8 ( V_15 ) ;
V_12 = V_8 + V_26 + V_27 ;
F_9 ( V_13 , V_12 ) ;
V_11 = V_28 ;
while ( V_11 ) {
F_10 ( 10 ) ;
V_12 = V_8 + V_26 ;
V_13 = F_11 ( V_12 ) ;
V_15 = F_8 ( V_13 ) ;
if ( ! ( V_15 & V_25 ) )
break;
V_11 -- ;
}
if ( V_11 == 0 ) {
F_2 ( L_5 , V_1 ) ;
return V_22 ;
}
V_11 = V_28 ;
while ( V_11 ) {
F_10 ( 10 ) ;
V_12 = V_8 + V_29 ;
V_13 = F_11 ( V_12 ) ;
V_15 = F_8 ( V_13 ) ;
if ( F_12 ( V_15 ) )
break;
V_11 -- ;
}
if ( V_11 == 0 ) {
F_2 ( L_6 ) ;
return V_22 ;
}
V_12 = V_8 + V_24 ;
V_13 = F_11 ( V_12 ) ;
V_15 = F_8 ( V_13 ) ;
V_10 = ( T_2 ) V_15 ;
F_6 ( L_7 , V_1 , V_9 , V_10 ) ;
return ( V_10 ) ;
}
static T_2 F_13 ( struct V_6 * V_7 , void T_3 * V_8 , T_2 V_9 , T_2 V_30 )
{
T_2 V_31 ;
void T_3 * V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_15 ;
int V_11 ;
F_6 ( L_8 , V_1 , V_8 , V_9 , V_30 ) ;
V_31 = 0 ;
V_15 = 0x00000000 ;
if ( V_7 -> V_16 == 0x02 ) {
V_15 = V_32 ;
V_14 = ( unsigned long ) V_7 -> V_18 . V_19 . V_20 ;
V_14 = V_14 >> 1 ;
V_15 |= ( V_14 << 8 ) ;
V_15 |= ( unsigned long ) V_9 ;
} else if ( V_7 -> V_16 == 0x04 ) {
V_15 = V_33 ;
V_14 = ( unsigned long ) V_9 ;
V_14 = V_14 << 8 ;
V_15 |= V_14 ;
} else {
F_7 ( L_4 ) ;
return V_22 ;
}
V_13 = F_8 ( V_15 ) ;
V_12 = V_8 + V_23 ;
F_9 ( V_13 , V_12 ) ;
V_15 = 0x00000000 | ( unsigned long ) V_30 ;
V_13 = F_8 ( V_15 ) ;
V_12 = V_8 + V_24 ;
F_9 ( V_13 , V_12 ) ;
V_15 = V_25 ;
V_13 = F_8 ( V_15 ) ;
V_12 = V_8 + V_26 + V_27 ;
F_9 ( V_13 , V_12 ) ;
V_11 = V_28 ;
while ( V_11 ) {
F_10 ( 10 ) ;
V_12 = V_8 + V_26 ;
V_13 = F_11 ( V_12 ) ;
V_15 = F_8 ( V_13 ) ;
if ( ! ( V_15 & V_25 ) )
break;
V_11 -- ;
}
if ( V_11 == 0 ) {
F_2 ( L_9 , V_1 ) ;
V_31 = V_22 ;
}
V_11 = V_28 ;
while ( V_11 ) {
F_10 ( 10 ) ;
V_12 = V_8 + V_29 ;
V_13 = F_11 ( V_12 ) ;
V_15 = F_8 ( V_13 ) ;
if ( F_12 ( V_15 ) )
break;
V_11 -- ;
}
if ( V_11 == 0 ) {
F_2 ( L_10 ) ;
V_31 = V_22 ;
}
F_6 ( L_11 , V_1 , V_31 ) ;
return ( V_31 ) ;
}
static T_2 F_14 ( struct V_6 * V_7 , T_2 V_34 )
{
T_4 V_35 ;
T_4 V_36 ;
T_2 V_15 ;
V_35 = V_7 -> V_18 . V_37 . V_38 ;
V_36 = V_7 -> V_18 . V_37 . V_39 ;
V_15 = F_15 ( V_35 + V_34 ) ;
return V_15 ;
}
static void F_16 ( struct V_6 * V_7 , T_2 V_34 , T_2 V_15 )
{
T_4 V_35 ;
T_4 V_40 ;
V_35 = V_7 -> V_18 . V_37 . V_38 ;
V_40 = V_35 + ( T_4 ) V_34 ;
F_17 ( V_15 , V_40 ) ;
}
static T_2 F_18 ( struct V_6 * V_41 , T_2 V_34 )
{
T_2 V_15 = 0x00 ;
F_2 ( L_12 ) ;
if ( V_41 -> V_42 )
F_19 ( V_41 -> V_42 , V_43 + V_34 , & V_15 ) ;
return V_15 ;
}
static T_2 F_20 ( struct V_6 * V_41 , T_2 V_34 , T_2 V_15 )
{
T_2 V_31 = - V_44 ;
F_2 ( L_13 ) ;
if ( V_41 -> V_42 ) {
F_21 ( V_41 -> V_42 , V_43 + V_34 , V_15 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static T_2 F_22 ( struct V_6 * V_45 , void T_3 * V_46 , T_2 V_34 )
{
T_2 V_31 ;
switch ( V_45 -> V_16 ) {
case 0 :
V_31 = F_14 ( V_45 , V_34 ) ;
break;
case 1 :
V_31 = F_18 ( V_45 , V_34 ) ;
break;
case 2 :
case 4 :
V_31 = F_5 ( V_45 , V_46 , V_34 ) ;
break;
default:
return - V_44 ;
}
return V_31 ;
}
static T_2 F_23 ( struct V_6 * V_45 , void T_3 * V_46 , T_2 V_34 , T_2 V_15 )
{
T_2 V_31 = 0 ;
switch ( V_45 -> V_16 ) {
case 0 :
F_16 ( V_45 , V_34 , V_15 ) ;
break;
case 1 :
V_31 = F_20 ( V_45 , V_34 , V_15 ) ;
break;
case 2 :
case 4 :
V_31 = F_13 ( V_45 , V_46 , V_34 , V_15 ) ;
break;
default:
return - V_44 ;
}
return V_31 ;
}
static T_2 F_24 ( T_2 V_30 , T_2 V_9 )
{
T_2 V_31 ;
switch ( V_30 ) {
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_31 = 0x0F ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
V_31 = V_9 ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_31 = V_9 + V_64 - 1 ;
break;
default:
F_7 ( L_14 , V_30 ) ;
V_31 = V_22 ;
}
return V_31 ;
}
static T_2 F_25 ( T_2 V_30 , T_2 V_9 )
{
T_2 V_31 ;
switch ( V_30 ) {
case V_65 :
V_31 = 0x0F ;
break;
case V_66 :
case V_67 :
V_31 = V_9 ;
break;
case V_68 :
V_31 = V_9 + V_69 ;
break;
case V_70 :
V_31 = V_9 + V_64 - 1 ;
break;
case V_71 :
V_31 = 0x28 ;
break;
case V_72 :
V_31 = 0x25 ;
break;
case V_73 :
V_31 = 0x27 ;
break;
default:
V_31 = V_22 ;
}
return V_31 ;
}
int F_26 ( struct V_74 * V_75 , T_2 V_30 , T_2 * V_76 )
{
void T_3 * V_77 = NULL ;
struct V_6 * V_7 ;
struct V_78 * V_79 ;
T_2 V_9 , V_10 ;
int V_31 = 0 ;
int V_80 ;
F_6 ( L_15 , V_1 , V_75 , V_30 , V_76 ) ;
if ( ( V_75 == NULL )
|| ( ( V_76 == NULL ) && ( V_30 != V_67 ) && ( V_30 != V_70 ) ) ) {
V_31 = - V_81 ;
F_7 ( L_16 , V_1 , V_31 ) ;
return V_31 ;
}
if ( V_30 == V_70 ) {
V_80 = F_27 ( V_75 -> V_82 ) ;
if ( V_80 < 0 ) {
V_31 = - V_81 ;
F_7 ( L_17 , V_1 , V_31 ) ;
return V_31 ;
} else
V_9 = ( T_2 ) V_80 ;
} else
V_9 = V_75 -> V_83 ;
V_9 = F_25 ( V_30 , V_9 ) ;
if ( V_9 == V_22 ) {
V_31 = - V_81 ;
F_7 ( L_18 , V_1 , V_31 ) ;
return V_31 ;
}
V_7 = V_75 -> V_41 ;
F_28 () ;
if ( ( V_7 -> V_16 == 2 ) || ( V_7 -> V_16 == 4 ) )
V_77 = F_29 ( V_7 -> V_18 . V_19 . V_84 , V_85 ) ;
V_31 = F_30 ( V_86 , V_7 , V_77 , & V_10 ) ;
if ( ! V_31 ) {
switch ( V_30 ) {
case V_67 :
V_75 -> V_41 -> V_10 = V_10 ;
V_75 -> V_10 = F_22 ( V_7 , V_77 , V_9 ) ;
V_31 = F_30 ( V_86 , V_7 , V_77 ,
& V_10 ) ;
if ( ! V_31 )
V_75 -> V_87 = F_22 ( V_7 , V_77 , V_9 + V_69 ) ;
break;
case V_66 :
* V_76 = F_22 ( V_7 , V_77 , V_9 ) ;
break;
case V_68 :
* V_76 = F_22 ( V_7 , V_77 , V_9 ) ;
break;
case V_65 :
* V_76 = V_10 ;
break;
case V_70 :
V_75 -> V_88 = F_22 ( V_7 , V_77 , V_9 ) ;
break;
case V_72 :
* V_76 = F_22 ( V_7 , V_77 , V_9 ) ;
break;
case V_73 :
* V_76 = F_22 ( V_7 , V_77 , V_9 ) ;
break;
case V_71 :
* V_76 = F_22 ( V_7 , V_77 , V_9 ) ;
break;
case V_89 :
F_31 (pslotlist, &ibmphp_slot_head) {
V_75 = F_32 ( V_79 , struct V_74 , V_90 ) ;
V_9 = V_75 -> V_83 ;
V_31 = F_30 ( V_86 , V_7 ,
V_77 , & V_10 ) ;
if ( ! V_31 ) {
V_75 -> V_10 = F_22 ( V_7 , V_77 , V_9 ) ;
V_31 = F_30 ( V_86 ,
V_7 , V_77 , & V_10 ) ;
if ( ! V_31 )
V_75 -> V_87 =
F_22 ( V_7 , V_77 ,
V_9 + V_69 ) ;
} else {
F_7 ( L_19 , V_1 ) ;
V_31 = - V_81 ;
break;
}
}
break;
default:
V_31 = - V_81 ;
break;
}
}
if ( ( V_7 -> V_16 == 2 ) || ( V_7 -> V_16 == 4 ) )
F_33 ( V_77 ) ;
F_34 () ;
F_6 ( L_20 , V_1 , V_31 ) ;
return V_31 ;
}
int F_35 ( struct V_74 * V_75 , T_2 V_30 )
{
void T_3 * V_77 = NULL ;
struct V_6 * V_7 ;
T_2 V_9 , V_10 ;
int V_80 ;
T_2 V_91 ;
int V_31 = 0 ;
int V_92 ;
F_6 ( L_21 , V_1 , V_75 , V_30 ) ;
if ( V_75 == NULL ) {
V_31 = - V_81 ;
F_7 ( L_22 , V_1 , V_31 ) ;
return V_31 ;
}
if ( ( V_30 == V_59 ) || ( V_30 == V_60 ) ||
( V_30 == V_61 ) || ( V_30 == V_62 ) ||
( V_30 == V_63 ) ) {
V_80 = F_27 ( V_75 -> V_82 ) ;
if ( V_80 < 0 ) {
V_31 = - V_81 ;
F_7 ( L_17 , V_1 , V_31 ) ;
return V_31 ;
} else
V_9 = ( T_2 ) V_80 ;
} else
V_9 = V_75 -> V_83 ;
V_9 = F_24 ( V_30 , V_9 ) ;
if ( V_9 == V_22 ) {
V_31 = - V_81 ;
F_7 ( L_22 , V_1 , V_31 ) ;
return V_31 ;
}
V_7 = V_75 -> V_41 ;
F_28 () ;
if ( ( V_7 -> V_16 == 2 ) || ( V_7 -> V_16 == 4 ) ) {
V_77 = F_29 ( V_7 -> V_18 . V_19 . V_84 , V_85 ) ;
F_2 ( L_23 , V_1 ,
V_7 -> V_93 , ( V_94 ) ( V_7 -> V_18 . V_19 . V_84 ) , ( V_94 ) V_77 ,
V_7 -> V_18 . V_19 . V_20 ) ;
}
V_31 = F_30 ( V_86 , V_7 , V_77 , & V_10 ) ;
if ( ! V_31 ) {
F_23 ( V_7 , V_77 , V_9 , V_30 ) ;
V_92 = V_28 ;
V_91 = 0 ;
while ( ! V_91 ) {
V_31 = F_30 ( V_86 , V_7 , V_77 ,
& V_10 ) ;
if ( ! V_31 ) {
if ( F_36 ( V_30 ) ) {
if ( F_37 ( V_10 ) == V_95 )
V_91 = 1 ;
} else
V_91 = 1 ;
}
if ( ! V_91 ) {
F_10 ( 1000 ) ;
if ( V_92 < 1 ) {
V_91 = 1 ;
F_7 ( L_24 , V_1 ) ;
V_31 = - V_96 ;
} else
V_92 -- ;
}
}
V_7 -> V_10 = V_10 ;
}
if ( ( V_7 -> V_16 == 2 ) || ( V_7 -> V_16 == 4 ) )
F_33 ( V_77 ) ;
F_34 () ;
F_6 ( L_20 , V_1 , V_31 ) ;
return V_31 ;
}
static void F_28 ( void )
{
F_38 ( & V_2 ) ;
}
void F_34 ( void )
{
F_39 ( & V_2 ) ;
}
void F_40 ( void )
{
F_41 ( & V_3 ) ;
V_5 = 1 ;
}
void F_42 ( void )
{
F_2 ( L_1 , V_1 ) ;
F_43 ( & V_3 ) ;
V_5 = 0 ;
F_2 ( L_2 , V_1 ) ;
}
static int F_44 ( void * V_15 )
{
struct V_74 V_97 ;
struct V_74 * V_75 = NULL ;
struct V_78 * V_79 ;
int V_31 ;
int V_98 = V_99 ;
T_2 V_100 = 0x00 ;
T_2 V_101 = 0x00 ;
int V_102 = 0 ;
T_2 V_103 = 0x00 ;
F_2 ( L_1 , V_1 ) ;
while ( ! F_45 () ) {
F_41 ( & V_3 ) ;
switch ( V_98 ) {
case V_99 :
V_100 = V_101 ;
V_103 = 0x00 ;
F_31 (pslotlist, &ibmphp_slot_head) {
if ( V_103 >= F_46 () )
break;
V_75 = F_32 ( V_79 , struct V_74 , V_90 ) ;
if ( V_75 -> V_41 -> V_104 == V_103 ) {
V_103 ++ ;
if ( F_47 ( V_75 -> V_41 ) ) {
V_31 = F_26 ( V_75 ,
V_71 ,
& V_101 ) ;
if ( V_100 != V_101 )
F_48 ( V_100 ,
V_101 ,
V_75 -> V_41 ) ;
}
}
}
++ V_102 ;
V_98 = V_105 ;
break;
case V_106 :
F_31 (pslotlist, &ibmphp_slot_head) {
V_75 = F_32 ( V_79 , struct V_74 , V_90 ) ;
memcpy ( ( void * ) & V_97 , ( void * ) V_75 ,
sizeof ( struct V_74 ) ) ;
V_31 = F_26 ( V_75 , V_67 , NULL ) ;
if ( ( V_97 . V_10 != V_75 -> V_10 )
|| ( V_97 . V_87 != V_75 -> V_87 ) )
F_49 ( V_75 , & V_97 ) ;
}
V_103 = 0x00 ;
F_31 (pslotlist, &ibmphp_slot_head) {
if ( V_103 >= F_46 () )
break;
V_75 = F_32 ( V_79 , struct V_74 , V_90 ) ;
if ( V_75 -> V_41 -> V_104 == V_103 ) {
V_103 ++ ;
if ( F_47 ( V_75 -> V_41 ) )
V_31 = F_26 ( V_75 ,
V_71 ,
& V_101 ) ;
}
}
++ V_102 ;
V_98 = V_105 ;
break;
case V_105 :
F_43 ( & V_3 ) ;
F_10 ( V_107 * 1000 ) ;
if ( F_45 () )
goto V_108;
F_41 ( & V_3 ) ;
if ( V_102 >= V_109 ) {
V_102 = 0 ;
V_98 = V_106 ;
} else
V_98 = V_99 ;
break;
}
F_43 ( & V_3 ) ;
V_108:
F_10 ( 100 ) ;
}
F_43 ( & V_4 ) ;
F_2 ( L_2 , V_1 ) ;
return 0 ;
}
static int F_49 ( struct V_74 * V_75 , struct V_74 * V_110 )
{
T_2 V_10 ;
int V_31 = 0 ;
T_2 V_111 = 0 ;
T_2 V_112 = 0 ;
F_2 ( L_25 , V_75 , V_110 ) ;
if ( ( V_75 -> V_10 & 0x01 ) != ( V_110 -> V_10 & 0x01 ) )
V_112 = 1 ;
if ( ( V_75 -> V_10 & 0x04 ) != ( V_110 -> V_10 & 0x04 ) )
V_112 = 1 ;
if ( ( ( V_75 -> V_10 & 0x08 ) != ( V_110 -> V_10 & 0x08 ) )
|| ( ( V_75 -> V_10 & 0x10 ) != ( V_110 -> V_10 & 0x10 ) ) )
V_112 = 1 ;
if ( ( V_75 -> V_10 & 0x20 ) != ( V_110 -> V_10 & 0x20 ) )
if ( ( V_110 -> V_10 & 0x20 ) && ( F_50 ( V_110 -> V_10 ) == V_113 ) && ( F_51 ( V_110 -> V_10 ) ) )
V_111 = 1 ;
if ( ( V_75 -> V_10 & 0x80 ) != ( V_110 -> V_10 & 0x80 ) ) {
V_112 = 1 ;
if ( V_75 -> V_10 & 0x80 ) {
if ( F_52 ( V_75 -> V_10 ) ) {
F_10 ( 1000 ) ;
V_31 = F_26 ( V_75 , V_66 , & V_10 ) ;
if ( F_52 ( V_10 ) )
V_112 = 1 ;
else
V_75 -> V_10 &= ~ V_114 ;
}
}
else if ( ( F_52 ( V_110 -> V_10 ) == V_115 )
&& ( F_50 ( V_110 -> V_10 ) == V_113 ) && ( F_51 ( V_110 -> V_10 ) ) ) {
V_111 = 1 ;
}
}
if ( ( V_75 -> V_87 & 0x08 ) != ( V_110 -> V_87 & 0x08 ) )
V_112 = 1 ;
if ( V_111 ) {
F_2 ( L_26 ) ;
V_75 -> V_116 = 0 ;
V_31 = F_53 ( V_75 ) ;
}
if ( V_112 || V_111 ) {
F_54 ( V_75 ) ;
}
F_2 ( L_27 , V_1 , V_31 , V_111 , V_112 ) ;
return V_31 ;
}
static int F_48 ( T_2 V_117 , T_2 V_118 , struct V_6 * V_41 )
{
struct V_74 V_97 , * V_75 ;
T_2 V_11 ;
T_2 V_119 ;
int V_31 = 0 ;
F_2 ( L_28 , V_1 , V_117 , V_118 ) ;
for ( V_11 = V_41 -> V_120 ; V_11 <= V_41 -> V_121 ; V_11 ++ ) {
V_119 = 0x01 << V_11 ;
if ( ( V_119 & V_117 ) != ( V_119 & V_118 ) ) {
V_75 = F_55 ( V_11 ) ;
if ( V_75 ) {
memcpy ( ( void * ) & V_97 , ( void * ) V_75 , sizeof ( struct V_74 ) ) ;
V_31 = F_26 ( V_75 , V_67 , NULL ) ;
F_2 ( L_29 , V_1 , V_11 ) ;
F_49 ( V_75 , & V_97 ) ;
} else {
V_31 = - V_81 ;
F_7 ( L_30 , V_1 , V_11 ) ;
}
}
}
F_2 ( L_20 , V_1 , V_31 ) ;
return V_31 ;
}
int T_1 F_56 ( void )
{
F_2 ( L_1 , V_1 ) ;
V_122 = F_57 ( F_44 , NULL , L_31 ) ;
if ( F_58 ( V_122 ) ) {
F_7 ( L_32 , V_1 ) ;
return F_59 ( V_122 ) ;
}
return 0 ;
}
void T_5 F_60 ( void )
{
F_2 ( L_1 , V_1 ) ;
F_61 ( V_122 ) ;
F_2 ( L_33 ) ;
F_40 () ;
F_2 ( L_34 ) ;
F_2 ( L_35 ) ;
F_41 ( & V_4 ) ;
F_2 ( L_36 ) ;
F_2 ( L_37 ) ;
F_34 () ;
F_2 ( L_38 ) ;
F_42 () ;
F_2 ( L_39 ) ;
F_43 ( & V_4 ) ;
F_2 ( L_40 ) ;
F_2 ( L_2 , V_1 ) ;
}
static int F_30 ( int V_92 , struct V_6 * V_7 , void T_3 * V_77 ,
T_2 * V_76 )
{
int V_31 = 0 ;
T_2 V_91 = 0 ;
F_6 ( L_41 , V_92 ) ;
while ( ! V_91 ) {
* V_76 = F_22 ( V_7 , V_77 , V_123 ) ;
if ( * V_76 == V_22 ) {
V_31 = V_22 ;
V_91 = 1 ;
}
if ( F_62 ( * V_76 ) == V_124 )
V_91 = 1 ;
if ( ! V_91 ) {
F_10 ( 1000 ) ;
if ( V_92 < 1 ) {
V_91 = 1 ;
F_7 ( L_42 ) ;
V_31 = V_22 ;
} else
V_92 -- ;
}
}
F_6 ( L_43 , V_31 , * V_76 ) ;
return V_31 ;
}
