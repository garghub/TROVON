int F_1 ( void )
{
if ( V_1 -> V_2 == V_3 ) {
V_4 = V_5 ;
} else if ( V_1 -> V_2 == V_6 ) {
V_4 = V_7 ;
} else {
return - V_8 ;
}
V_9 = V_10 ;
return 0 ;
}
static int
F_2 ( void )
{
int V_11 ;
volatile struct V_12 V_13 ;
V_14 [ V_15 ] |= V_16 ;
V_14 [ V_17 ] = ( V_14 [ V_17 ] | V_16 ) & ~ V_18 ;
F_3 ( (struct V_12 * ) & V_13 , NULL , 2 , V_19 , V_20 ) ;
V_11 = 100000 ;
while ( ! V_13 . V_21 ) {
if ( -- V_11 < 0 ) {
F_4 ( V_22 L_1 ) ;
return - V_23 ;
}
F_5 ( 10 ) ;
F_6 () ;
}
V_11 = 100000 ;
V_24 [ 0 ] = 1 ;
while ( V_24 [ 0 ] || V_9 != V_10 ) {
if ( -- V_11 < 0 ) {
F_4 ( V_22 L_2 ) ;
return - V_23 ;
}
if ( V_9 == V_10 ) {
V_25 = 1 ;
F_7 ( 0 , NULL ) ;
}
F_6 () ;
F_5 ( 10 ) ;
}
F_3 ( (struct V_12 * ) & V_13 , NULL , 2 , V_19 ,
V_26 | V_27 | V_20 ) ;
V_11 = 100000 ;
while ( ! V_13 . V_21 ) {
if ( -- V_11 < 0 ) {
F_4 ( V_22 L_1 ) ;
return - V_23 ;
}
F_5 ( 10 ) ;
F_6 () ;
}
V_28 . V_21 = 1 ;
V_29 . V_21 = 1 ;
V_30 . V_21 = 1 ;
if ( F_8 ( V_31 , F_7 , 0 , L_3 ,
F_7 ) ) {
F_4 ( V_22 L_4 ,
V_31 ) ;
return - V_23 ;
}
if ( F_8 ( V_32 , F_7 , 0 , L_5 ,
F_7 ) ) {
F_4 ( V_22 L_4 ,
V_32 ) ;
F_9 ( V_31 , F_7 ) ;
return - V_23 ;
}
V_33 = 1 ;
F_10 ( 1 ) ;
F_4 ( L_6 ) ;
return 0 ;
}
int
F_11 ( void )
{
return V_4 ;
}
static int
F_12 ( struct V_12 * V_13 , int V_34 )
{
int V_35 , V_36 ;
if ( ! V_33 )
{
V_13 -> V_21 = 1 ;
return - V_37 ;
}
V_36 = - V_38 ;
switch ( V_13 -> V_39 [ 0 ] ) {
case V_40 :
for ( V_35 = 0 ; V_35 < V_13 -> V_41 - 1 ; ++ V_35 )
V_13 -> V_39 [ V_35 ] = V_13 -> V_39 [ V_35 + 1 ] ;
-- V_13 -> V_41 ;
if ( V_42 [ V_13 -> V_39 [ 0 ] ] [ 1 ] != 0 ) {
V_13 -> V_43 [ 0 ] = V_44 ;
V_13 -> V_45 = 1 ;
} else
V_13 -> V_45 = 0 ;
V_36 = F_13 ( V_13 ) ;
break;
case V_46 :
switch ( V_13 -> V_39 [ 1 ] ) {
case V_47 :
if ( V_13 -> V_41 != 2 )
break;
V_13 -> V_39 [ 0 ] = V_48 ;
V_13 -> V_41 = 1 ;
V_13 -> V_45 = 3 ;
V_13 -> V_43 [ 0 ] = V_46 ;
V_13 -> V_43 [ 1 ] = 0 ;
V_13 -> V_43 [ 2 ] = V_47 ;
V_36 = F_13 ( V_13 ) ;
break;
case V_49 :
if ( V_13 -> V_41 != 6 )
break;
V_13 -> V_39 [ 0 ] = V_50 ;
V_13 -> V_41 = 5 ;
for ( V_35 = 1 ; V_35 <= 4 ; ++ V_35 )
V_13 -> V_39 [ V_35 ] = V_13 -> V_39 [ V_35 + 1 ] ;
V_13 -> V_45 = 3 ;
V_13 -> V_43 [ 0 ] = V_46 ;
V_13 -> V_43 [ 1 ] = 0 ;
V_13 -> V_43 [ 2 ] = V_49 ;
V_36 = F_13 ( V_13 ) ;
break;
case V_51 :
if ( V_13 -> V_41 != 4 )
break;
V_13 -> V_39 [ 0 ] = V_52 ;
V_13 -> V_39 [ 1 ] = V_13 -> V_39 [ 2 ] ;
V_13 -> V_39 [ 2 ] = V_13 -> V_39 [ 3 ] ;
V_13 -> V_41 = 3 ;
V_13 -> V_45 = 3 ;
V_13 -> V_43 [ 0 ] = V_46 ;
V_13 -> V_43 [ 1 ] = 0 ;
V_13 -> V_43 [ 2 ] = V_51 ;
V_36 = F_13 ( V_13 ) ;
break;
case V_53 :
if ( V_13 -> V_41 != 5 )
break;
V_13 -> V_39 [ 0 ] = V_54 ;
V_13 -> V_39 [ 1 ] = V_13 -> V_39 [ 2 ] ;
V_13 -> V_39 [ 2 ] = V_13 -> V_39 [ 3 ] ;
V_13 -> V_39 [ 3 ] = V_13 -> V_39 [ 4 ] ;
V_13 -> V_41 = 4 ;
V_13 -> V_45 = 3 ;
V_13 -> V_43 [ 0 ] = V_46 ;
V_13 -> V_43 [ 1 ] = 0 ;
V_13 -> V_43 [ 2 ] = V_53 ;
V_36 = F_13 ( V_13 ) ;
break;
}
break;
case V_55 :
for ( V_35 = V_13 -> V_41 - 1 ; V_35 > 1 ; -- V_35 )
V_13 -> V_39 [ V_35 + 2 ] = V_13 -> V_39 [ V_35 ] ;
V_13 -> V_39 [ 3 ] = V_13 -> V_41 - 2 ;
V_13 -> V_39 [ 2 ] = V_56 ;
V_13 -> V_39 [ 0 ] = V_57 ;
V_13 -> V_41 += 2 ;
V_13 -> V_58 = 1 ;
V_13 -> V_45 = 0 ;
V_36 = F_13 ( V_13 ) ;
break;
}
if ( V_36 )
{
V_13 -> V_21 = 1 ;
return V_36 ;
}
if ( V_34 ) {
while ( ! V_13 -> V_21 )
F_6 () ;
}
return 0 ;
}
static int
F_14 ( int V_59 )
{
struct V_12 V_13 ;
if ( ! V_33 ) return - V_37 ;
if ( V_59 ) {
V_60 = V_59 ;
F_3 ( & V_13 , NULL , 5 , V_57 , 0 , 0x86 ,
V_60 >> 8 , V_60 ) ;
V_56 = 2 ;
} else {
F_3 ( & V_13 , NULL , 1 , V_61 ) ;
V_56 = 0 ;
}
while ( ! V_13 . V_21 )
F_6 () ;
return 0 ;
}
static int
F_15 ( void )
{
struct V_12 V_13 ;
long V_11 ;
int V_62 = V_60 ;
if ( ! V_33 ) return - V_37 ;
F_14 ( 0 ) ;
V_13 . V_41 = 5 ;
V_13 . V_63 = NULL ;
V_13 . V_39 [ 0 ] = V_57 ;
V_13 . V_39 [ 1 ] = 0 ;
V_13 . V_39 [ 2 ] = 3 ;
V_13 . V_39 [ 3 ] = 0 ;
V_13 . V_39 [ 4 ] = 0 ;
V_13 . V_45 = 0 ;
V_13 . V_58 = 1 ;
if ( F_13 ( & V_13 ) != 0 )
{
F_4 ( V_22 L_7 ) ;
return - V_64 ;
}
while ( ! V_13 . V_21 )
F_6 () ;
V_11 = 100000 ;
while ( ! V_13 . V_21 ) {
if ( -- V_11 < 0 ) {
F_4 ( V_22 L_8 ) ;
return - V_64 ;
}
F_5 ( 10 ) ;
F_6 () ;
}
if ( V_62 != 0 )
F_14 ( V_62 ) ;
return 0 ;
}
int
F_3 ( struct V_12 * V_13 , void (* V_63)( struct V_12 * ) ,
int V_41 , ... )
{
T_1 V_65 ;
int V_35 ;
if ( V_41 < 0 || V_41 > 32 ) {
F_4 ( V_22 L_9 , V_41 ) ;
V_13 -> V_21 = 1 ;
return - V_38 ;
}
V_13 -> V_41 = V_41 ;
V_13 -> V_63 = V_63 ;
va_start ( V_65 , V_41 ) ;
for ( V_35 = 0 ; V_35 < V_41 ; ++ V_35 )
V_13 -> V_39 [ V_35 ] = va_arg ( V_65 , int ) ;
va_end ( V_65 ) ;
if ( V_42 [ V_13 -> V_39 [ 0 ] ] [ 1 ] != 0 ) {
V_13 -> V_43 [ 0 ] = V_44 ;
V_13 -> V_45 = 1 ;
} else
V_13 -> V_45 = 0 ;
V_13 -> V_58 = 0 ;
return F_13 ( V_13 ) ;
}
int
F_13 ( struct V_12 * V_13 )
{
unsigned long V_66 ;
int V_67 ;
if ( V_13 -> V_41 <= 0 ) {
V_13 -> V_21 = 1 ;
return 0 ;
}
V_67 = V_42 [ V_13 -> V_39 [ 0 ] ] [ 0 ] ;
if ( V_67 >= 0 && V_13 -> V_41 != V_67 + 1 ) {
V_13 -> V_21 = 1 ;
return - V_38 ;
}
V_13 -> V_68 = NULL ;
V_13 -> V_69 = 0 ;
V_13 -> V_21 = 0 ;
F_16 ( V_66 ) ;
if ( V_70 != 0 ) {
V_71 -> V_68 = V_13 ;
V_71 = V_13 ;
} else {
V_70 = V_13 ;
V_71 = V_13 ;
if ( V_9 == V_10 )
F_17 () ;
}
F_18 ( V_66 ) ;
return 0 ;
}
static void
F_19 ( int V_72 )
{
V_73 [ V_74 ] |= V_75 ;
V_73 [ V_76 ] = V_72 ;
V_14 [ V_15 ] &= ~ V_16 ;
}
static void
F_20 ( void )
{
char V_77 ;
V_73 [ V_74 ] = ( V_73 [ V_74 ] | V_78 ) & ~ V_79 ;
V_77 = V_73 [ V_76 ] ;
V_14 [ V_15 ] &= ~ V_16 ;
}
static void
F_17 ( void )
{
unsigned long V_66 ;
struct V_12 * V_13 ;
F_16 ( V_66 ) ;
V_13 = V_70 ;
if ( V_13 == 0 || V_9 != V_10
|| ( V_13 -> V_58 && V_80 ) )
goto V_81;
V_9 = V_82 ;
V_83 = 1 ;
V_84 = V_42 [ V_13 -> V_39 [ 0 ] ] [ 0 ] ;
F_19 ( V_13 -> V_39 [ 0 ] ) ;
V_81:
F_18 ( V_66 ) ;
}
void
F_6 ( void )
{
unsigned long V_66 ;
F_16 ( V_66 ) ;
if ( V_73 [ V_85 ] & V_86 ) {
V_73 [ V_85 ] = V_86 ;
F_7 ( V_31 , NULL ) ;
}
if ( V_73 [ V_85 ] & V_87 ) {
V_73 [ V_85 ] = V_87 ;
F_7 ( V_32 , NULL ) ;
}
F_18 ( V_66 ) ;
}
static T_2
F_7 ( int V_88 , void * V_89 )
{
struct V_12 * V_13 ;
int V_11 , V_90 = 0 ;
#if 0
printk("pmu_interrupt: irq %d state %d acr %02X, b %02X data_index %d/%d adb_int_pending %d\n",
irq, pmu_state, (uint) via1[ACR], (uint) via2[B], data_index, data_len, adb_int_pending);
#endif
if ( V_88 == V_32 ) {
V_25 = 1 ;
} else if ( V_88 == V_31 ) {
if ( V_14 [ V_15 ] & V_18 ) {
F_4 ( V_91 L_10 , V_14 [ V_15 ] ) ;
}
if ( ( V_73 [ V_74 ] & V_79 ) == 0 ) V_90 = V_73 [ V_76 ] ;
V_14 [ V_15 ] |= V_16 ;
V_11 = 3200 ;
while ( ! ( V_14 [ V_15 ] & V_18 ) ) {
if ( -- V_11 < 0 ) {
F_4 ( V_22 L_11 ) ;
goto V_92;
}
F_5 ( 10 ) ;
}
switch ( V_9 ) {
case V_82 :
V_13 = V_70 ;
if ( V_84 < 0 ) {
V_84 = V_13 -> V_41 - 1 ;
F_19 ( V_84 ) ;
break;
}
if ( V_83 <= V_84 ) {
F_19 ( V_13 -> V_39 [ V_83 ++ ] ) ;
break;
}
V_13 -> V_69 = 1 ;
V_84 = V_42 [ V_13 -> V_39 [ 0 ] ] [ 1 ] ;
if ( V_84 == 0 ) {
V_9 = V_10 ;
V_70 = V_13 -> V_68 ;
if ( V_13 -> V_58 )
V_80 = V_13 ;
else
F_21 ( V_13 ) ;
} else {
V_9 = V_93 ;
V_83 = 0 ;
V_94 = V_13 -> V_43 + V_13 -> V_45 ;
F_20 () ;
}
break;
case V_95 :
V_83 = 0 ;
V_84 = - 1 ;
V_9 = V_96 ;
V_94 = V_24 ;
F_20 () ;
break;
case V_93 :
case V_96 :
if ( V_84 == - 1 ) {
V_84 = V_90 ;
if ( V_90 > 32 )
F_4 ( V_22 L_12 ,
V_90 ) ;
} else {
V_94 [ V_83 ++ ] = V_90 ;
}
if ( V_83 < V_84 ) {
F_20 () ;
break;
}
if ( V_9 == V_96 ) {
F_22 ( V_24 , V_83 ) ;
} else {
V_13 = V_70 ;
V_70 = V_13 -> V_68 ;
V_13 -> V_45 += V_83 ;
F_21 ( V_13 ) ;
}
V_9 = V_10 ;
break;
default:
F_4 ( V_22 L_13 ,
V_9 ) ;
}
}
V_92:
if ( V_9 == V_10 ) {
if ( V_25 ) {
V_9 = V_95 ;
F_19 ( V_97 ) ;
V_25 = 0 ;
} else if ( V_70 ) {
F_17 () ;
}
}
#if 0
printk("pmu_interrupt: exit state %d acr %02X, b %02X data_index %d/%d adb_int_pending %d\n",
pmu_state, (uint) via1[ACR], (uint) via2[B], data_index, data_len, adb_int_pending);
#endif
return V_98 ;
}
static void
F_21 ( struct V_12 * V_13 )
{
V_13 -> V_21 = 1 ;
if ( V_13 -> V_63 )
(* V_13 -> V_63 )( V_13 ) ;
}
static void
F_22 ( unsigned char * V_39 , int V_99 )
{
static int V_100 = 1 ;
V_101 = 0 ;
if ( V_99 < 1 ) {
V_25 = 0 ;
return;
}
if ( V_39 [ 0 ] & V_20 ) {
if ( ( V_39 [ 0 ] & V_26 ) == 0 ) {
struct V_12 * V_13 = V_80 ;
if ( V_13 == 0 ) {
F_4 ( V_22 L_14 ) ;
return;
}
V_80 = NULL ;
if ( V_99 <= 2 )
V_13 -> V_45 = 0 ;
else {
memcpy ( V_13 -> V_43 , V_39 + 1 , V_99 - 1 ) ;
V_13 -> V_45 = V_99 - 1 ;
}
F_21 ( V_13 ) ;
} else {
F_23 ( V_39 + 1 , V_99 - 1 , 1 ) ;
}
} else {
if ( V_39 [ 0 ] == 0x08 && V_99 == 3 ) {
F_24 ( V_39 [ 1 ] >> 3 ) ;
F_25 ( V_39 [ 2 ] ) ;
} else if ( V_100
&& ! ( V_39 [ 0 ] == V_102 && V_99 == 1 ) ) {
int V_35 ;
F_4 ( V_91 L_15 ) ;
for ( V_35 = 0 ; V_35 < V_99 ; ++ V_35 )
F_4 ( L_16 , V_39 [ V_35 ] ) ;
F_4 ( L_17 ) ;
}
}
}
static void
F_10 ( int V_103 )
{
struct V_12 V_13 ;
if ( V_103 ) {
if ( V_104 < 0 ) {
switch( V_4 ) {
case V_5 :
case V_7 :
F_3 ( & V_13 , NULL , 3 , V_52 , 0x14 , 0xe ) ;
while ( ! V_13 . V_21 )
F_6 () ;
F_4 ( V_91 L_18 , ( int ) V_13 . V_43 [ 1 ] ) ;
V_104 = V_13 . V_43 [ 1 ] ;
break;
default:
V_105 = 0 ;
return;
}
}
F_3 ( & V_13 , NULL , 2 , V_106 ,
F_26 ( V_104 ) ) ;
while ( ! V_13 . V_21 )
F_6 () ;
}
F_3 ( & V_13 , NULL , 2 , V_107 ,
V_108 | ( V_103 ? V_109 : V_110 ) ) ;
while ( ! V_13 . V_21 )
F_6 () ;
V_105 = V_103 ;
}
static void
F_24 ( int V_111 )
{
int V_112 ;
V_104 = V_111 ;
V_112 = F_26 ( V_111 ) ;
if ( ! V_105 )
return;
if ( V_28 . V_21 )
F_3 ( & V_28 , NULL , 2 , V_106 ,
V_112 ) ;
if ( V_29 . V_21 )
F_3 ( & V_29 , NULL , 2 , V_107 ,
V_108 | ( V_112 < 0x7f ? V_109 : V_110 ) ) ;
}
void
F_27 ( int V_103 )
{
struct V_12 V_13 ;
F_3 ( & V_13 , NULL , 2 , V_107 , V_113 |
( V_103 ? V_109 : V_110 ) ) ;
while ( ! V_13 . V_21 )
F_6 () ;
}
static void
F_25 ( int V_111 )
{
}
int
F_28 ( void )
{
return ( V_4 != V_114 ) ;
}
