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
T_2 V_9 , V_10 ;
int V_31 = 0 ;
int V_78 ;
F_6 ( L_15 , V_1 , V_75 , V_30 , V_76 ) ;
if ( ( V_75 == NULL )
|| ( ( V_76 == NULL ) && ( V_30 != V_67 ) && ( V_30 != V_70 ) ) ) {
V_31 = - V_79 ;
F_7 ( L_16 , V_1 , V_31 ) ;
return V_31 ;
}
if ( V_30 == V_70 ) {
V_78 = F_27 ( V_75 -> V_80 ) ;
if ( V_78 < 0 ) {
V_31 = - V_79 ;
F_7 ( L_17 , V_1 , V_31 ) ;
return V_31 ;
} else
V_9 = ( T_2 ) V_78 ;
} else
V_9 = V_75 -> V_81 ;
V_9 = F_25 ( V_30 , V_9 ) ;
if ( V_9 == V_22 ) {
V_31 = - V_79 ;
F_7 ( L_18 , V_1 , V_31 ) ;
return V_31 ;
}
V_7 = V_75 -> V_41 ;
F_28 () ;
if ( ( V_7 -> V_16 == 2 ) || ( V_7 -> V_16 == 4 ) )
V_77 = F_29 ( V_7 -> V_18 . V_19 . V_82 , V_83 ) ;
V_31 = F_30 ( V_84 , V_7 , V_77 , & V_10 ) ;
if ( ! V_31 ) {
switch ( V_30 ) {
case V_67 :
V_75 -> V_41 -> V_10 = V_10 ;
V_75 -> V_10 = F_22 ( V_7 , V_77 , V_9 ) ;
V_31 = F_30 ( V_84 , V_7 , V_77 ,
& V_10 ) ;
if ( ! V_31 )
V_75 -> V_85 = F_22 ( V_7 , V_77 , V_9 + V_69 ) ;
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
V_75 -> V_86 = F_22 ( V_7 , V_77 , V_9 ) ;
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
case V_87 :
F_31 (pslot, &ibmphp_slot_head,
ibm_slot_list) {
V_9 = V_75 -> V_81 ;
V_31 = F_30 ( V_84 , V_7 ,
V_77 , & V_10 ) ;
if ( ! V_31 ) {
V_75 -> V_10 = F_22 ( V_7 , V_77 , V_9 ) ;
V_31 = F_30 ( V_84 ,
V_7 , V_77 , & V_10 ) ;
if ( ! V_31 )
V_75 -> V_85 =
F_22 ( V_7 , V_77 ,
V_9 + V_69 ) ;
} else {
F_7 ( L_19 , V_1 ) ;
V_31 = - V_79 ;
break;
}
}
break;
default:
V_31 = - V_79 ;
break;
}
}
if ( ( V_7 -> V_16 == 2 ) || ( V_7 -> V_16 == 4 ) )
F_32 ( V_77 ) ;
F_33 () ;
F_6 ( L_20 , V_1 , V_31 ) ;
return V_31 ;
}
int F_34 ( struct V_74 * V_75 , T_2 V_30 )
{
void T_3 * V_77 = NULL ;
struct V_6 * V_7 ;
T_2 V_9 , V_10 ;
int V_78 ;
T_2 V_88 ;
int V_31 = 0 ;
int V_89 ;
F_6 ( L_21 , V_1 , V_75 , V_30 ) ;
if ( V_75 == NULL ) {
V_31 = - V_79 ;
F_7 ( L_22 , V_1 , V_31 ) ;
return V_31 ;
}
if ( ( V_30 == V_59 ) || ( V_30 == V_60 ) ||
( V_30 == V_61 ) || ( V_30 == V_62 ) ||
( V_30 == V_63 ) ) {
V_78 = F_27 ( V_75 -> V_80 ) ;
if ( V_78 < 0 ) {
V_31 = - V_79 ;
F_7 ( L_17 , V_1 , V_31 ) ;
return V_31 ;
} else
V_9 = ( T_2 ) V_78 ;
} else
V_9 = V_75 -> V_81 ;
V_9 = F_24 ( V_30 , V_9 ) ;
if ( V_9 == V_22 ) {
V_31 = - V_79 ;
F_7 ( L_22 , V_1 , V_31 ) ;
return V_31 ;
}
V_7 = V_75 -> V_41 ;
F_28 () ;
if ( ( V_7 -> V_16 == 2 ) || ( V_7 -> V_16 == 4 ) ) {
V_77 = F_29 ( V_7 -> V_18 . V_19 . V_82 , V_83 ) ;
F_2 ( L_23 , V_1 ,
V_7 -> V_90 , ( V_91 ) ( V_7 -> V_18 . V_19 . V_82 ) , ( V_91 ) V_77 ,
V_7 -> V_18 . V_19 . V_20 ) ;
}
V_31 = F_30 ( V_84 , V_7 , V_77 , & V_10 ) ;
if ( ! V_31 ) {
F_23 ( V_7 , V_77 , V_9 , V_30 ) ;
V_89 = V_28 ;
V_88 = 0 ;
while ( ! V_88 ) {
V_31 = F_30 ( V_84 , V_7 , V_77 ,
& V_10 ) ;
if ( ! V_31 ) {
if ( F_35 ( V_30 ) ) {
if ( F_36 ( V_10 ) == V_92 )
V_88 = 1 ;
} else
V_88 = 1 ;
}
if ( ! V_88 ) {
F_10 ( 1000 ) ;
if ( V_89 < 1 ) {
V_88 = 1 ;
F_7 ( L_24 , V_1 ) ;
V_31 = - V_93 ;
} else
V_89 -- ;
}
}
V_7 -> V_10 = V_10 ;
}
if ( ( V_7 -> V_16 == 2 ) || ( V_7 -> V_16 == 4 ) )
F_32 ( V_77 ) ;
F_33 () ;
F_6 ( L_20 , V_1 , V_31 ) ;
return V_31 ;
}
static void F_28 ( void )
{
F_37 ( & V_2 ) ;
}
void F_33 ( void )
{
F_38 ( & V_2 ) ;
}
void F_39 ( void )
{
F_40 ( & V_3 ) ;
V_5 = 1 ;
}
void F_41 ( void )
{
F_2 ( L_1 , V_1 ) ;
F_42 ( & V_3 ) ;
V_5 = 0 ;
F_2 ( L_2 , V_1 ) ;
}
static int F_43 ( void * V_15 )
{
struct V_74 V_94 ;
struct V_74 * V_75 = NULL ;
int V_31 ;
int V_95 = V_96 ;
T_2 V_97 = 0x00 ;
T_2 V_98 = 0x00 ;
int V_99 = 0 ;
T_2 V_100 = 0x00 ;
F_2 ( L_1 , V_1 ) ;
while ( ! F_44 () ) {
F_40 ( & V_3 ) ;
switch ( V_95 ) {
case V_96 :
V_97 = V_98 ;
V_100 = 0x00 ;
F_31 (pslot, &ibmphp_slot_head,
ibm_slot_list) {
if ( V_100 >= F_45 () )
break;
if ( V_75 -> V_41 -> V_101 == V_100 ) {
V_100 ++ ;
if ( F_46 ( V_75 -> V_41 ) ) {
V_31 = F_26 ( V_75 ,
V_71 ,
& V_98 ) ;
if ( V_97 != V_98 )
F_47 ( V_97 ,
V_98 ,
V_75 -> V_41 ) ;
}
}
}
++ V_99 ;
V_95 = V_102 ;
break;
case V_103 :
F_31 (pslot, &ibmphp_slot_head,
ibm_slot_list) {
memcpy ( ( void * ) & V_94 , ( void * ) V_75 ,
sizeof( struct V_74 ) ) ;
V_31 = F_26 ( V_75 , V_67 , NULL ) ;
if ( ( V_94 . V_10 != V_75 -> V_10 )
|| ( V_94 . V_85 != V_75 -> V_85 ) )
F_48 ( V_75 , & V_94 ) ;
}
V_100 = 0x00 ;
F_31 (pslot, &ibmphp_slot_head,
ibm_slot_list) {
if ( V_100 >= F_45 () )
break;
if ( V_75 -> V_41 -> V_101 == V_100 ) {
V_100 ++ ;
if ( F_46 ( V_75 -> V_41 ) )
V_31 = F_26 ( V_75 ,
V_71 ,
& V_98 ) ;
}
}
++ V_99 ;
V_95 = V_102 ;
break;
case V_102 :
F_42 ( & V_3 ) ;
F_10 ( V_104 * 1000 ) ;
if ( F_44 () )
goto V_105;
F_40 ( & V_3 ) ;
if ( V_99 >= V_106 ) {
V_99 = 0 ;
V_95 = V_103 ;
} else
V_95 = V_96 ;
break;
}
F_42 ( & V_3 ) ;
V_105:
F_10 ( 100 ) ;
}
F_42 ( & V_4 ) ;
F_2 ( L_2 , V_1 ) ;
return 0 ;
}
static int F_48 ( struct V_74 * V_75 , struct V_74 * V_107 )
{
T_2 V_10 ;
int V_31 = 0 ;
T_2 V_108 = 0 ;
T_2 V_109 = 0 ;
F_2 ( L_25 , V_75 , V_107 ) ;
if ( ( V_75 -> V_10 & 0x01 ) != ( V_107 -> V_10 & 0x01 ) )
V_109 = 1 ;
if ( ( V_75 -> V_10 & 0x04 ) != ( V_107 -> V_10 & 0x04 ) )
V_109 = 1 ;
if ( ( ( V_75 -> V_10 & 0x08 ) != ( V_107 -> V_10 & 0x08 ) )
|| ( ( V_75 -> V_10 & 0x10 ) != ( V_107 -> V_10 & 0x10 ) ) )
V_109 = 1 ;
if ( ( V_75 -> V_10 & 0x20 ) != ( V_107 -> V_10 & 0x20 ) )
if ( ( V_107 -> V_10 & 0x20 ) && ( F_49 ( V_107 -> V_10 ) == V_110 ) && ( F_50 ( V_107 -> V_10 ) ) )
V_108 = 1 ;
if ( ( V_75 -> V_10 & 0x80 ) != ( V_107 -> V_10 & 0x80 ) ) {
V_109 = 1 ;
if ( V_75 -> V_10 & 0x80 ) {
if ( F_51 ( V_75 -> V_10 ) ) {
F_10 ( 1000 ) ;
V_31 = F_26 ( V_75 , V_66 , & V_10 ) ;
if ( F_51 ( V_10 ) )
V_109 = 1 ;
else
V_75 -> V_10 &= ~ V_111 ;
}
}
else if ( ( F_51 ( V_107 -> V_10 ) == V_112 )
&& ( F_49 ( V_107 -> V_10 ) == V_110 ) && ( F_50 ( V_107 -> V_10 ) ) ) {
V_108 = 1 ;
}
}
if ( ( V_75 -> V_85 & 0x08 ) != ( V_107 -> V_85 & 0x08 ) )
V_109 = 1 ;
if ( V_108 ) {
F_2 ( L_26 ) ;
V_75 -> V_113 = 0 ;
V_31 = F_52 ( V_75 ) ;
}
if ( V_109 || V_108 )
F_53 ( V_75 ) ;
F_2 ( L_27 , V_1 , V_31 , V_108 , V_109 ) ;
return V_31 ;
}
static int F_47 ( T_2 V_114 , T_2 V_115 , struct V_6 * V_41 )
{
struct V_74 V_94 , * V_75 ;
T_2 V_11 ;
T_2 V_116 ;
int V_31 = 0 ;
F_2 ( L_28 , V_1 , V_114 , V_115 ) ;
for ( V_11 = V_41 -> V_117 ; V_11 <= V_41 -> V_118 ; V_11 ++ ) {
V_116 = 0x01 << V_11 ;
if ( ( V_116 & V_114 ) != ( V_116 & V_115 ) ) {
V_75 = F_54 ( V_11 ) ;
if ( V_75 ) {
memcpy ( ( void * ) & V_94 , ( void * ) V_75 , sizeof( struct V_74 ) ) ;
V_31 = F_26 ( V_75 , V_67 , NULL ) ;
F_2 ( L_29 , V_1 , V_11 ) ;
F_48 ( V_75 , & V_94 ) ;
} else {
V_31 = - V_79 ;
F_7 ( L_30 , V_1 , V_11 ) ;
}
}
}
F_2 ( L_20 , V_1 , V_31 ) ;
return V_31 ;
}
int T_1 F_55 ( void )
{
F_2 ( L_1 , V_1 ) ;
V_119 = F_56 ( F_43 , NULL , L_31 ) ;
if ( F_57 ( V_119 ) ) {
F_7 ( L_32 , V_1 ) ;
return F_58 ( V_119 ) ;
}
return 0 ;
}
void T_5 F_59 ( void )
{
F_2 ( L_1 , V_1 ) ;
F_60 ( V_119 ) ;
F_2 ( L_33 ) ;
F_39 () ;
F_2 ( L_34 ) ;
F_2 ( L_35 ) ;
F_40 ( & V_4 ) ;
F_2 ( L_36 ) ;
F_2 ( L_37 ) ;
F_33 () ;
F_2 ( L_38 ) ;
F_41 () ;
F_2 ( L_39 ) ;
F_42 ( & V_4 ) ;
F_2 ( L_40 ) ;
F_2 ( L_2 , V_1 ) ;
}
static int F_30 ( int V_89 , struct V_6 * V_7 , void T_3 * V_77 ,
T_2 * V_76 )
{
int V_31 = 0 ;
T_2 V_88 = 0 ;
F_6 ( L_41 , V_89 ) ;
while ( ! V_88 ) {
* V_76 = F_22 ( V_7 , V_77 , V_120 ) ;
if ( * V_76 == V_22 ) {
V_31 = V_22 ;
V_88 = 1 ;
}
if ( F_61 ( * V_76 ) == V_121 )
V_88 = 1 ;
if ( ! V_88 ) {
F_10 ( 1000 ) ;
if ( V_89 < 1 ) {
V_88 = 1 ;
F_7 ( L_42 ) ;
V_31 = V_22 ;
} else
V_89 -- ;
}
}
F_6 ( L_43 , V_31 , * V_76 ) ;
return V_31 ;
}
