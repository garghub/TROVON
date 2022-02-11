static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_4 ,
T_2 V_5 )
{
int V_6 ;
if ( ! V_4 ) V_5 = 0 ;
if ( V_5 > ( sizeof( V_2 -> V_7 ) - 3 ) ) {
F_2 ( V_8 ,
L_1
L_2 ,
V_3 ,
V_5 , ( unsigned int ) ( sizeof( V_2 -> V_7 ) - 3 ) ) ;
return - V_9 ;
}
F_3 ( V_2 -> V_10 ) ;
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
V_2 -> V_7 [ 0 ] = V_11 ;
V_2 -> V_7 [ 1 ] = V_3 ;
V_2 -> V_7 [ 2 ] = V_5 ;
if ( V_5 ) memcpy ( V_2 -> V_7 + 3 , V_4 , V_5 ) ;
V_6 = F_4 ( V_2 ,
V_2 -> V_7 ,
V_5 + 3 ,
V_2 -> V_7 ,
1 ) ;
if ( ! V_6 ) {
if ( V_2 -> V_7 [ 0 ] != 8 ) {
V_6 = - V_12 ;
if ( V_2 -> V_7 [ 0 ] != 7 ) {
F_5 ( L_3
L_4 ,
V_3 , V_2 -> V_7 [ 0 ] ) ;
}
}
}
F_6 ( V_2 -> V_10 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_4 ,
T_2 V_13 ,
T_1 * V_14 ,
T_2 V_15 )
{
int V_6 ;
if ( ! V_4 ) V_13 = 0 ;
if ( V_13 > ( sizeof( V_2 -> V_7 ) - 4 ) ) {
F_2 ( V_8 ,
L_5
L_2 ,
V_3 ,
V_13 , ( unsigned int ) ( sizeof( V_2 -> V_7 ) - 4 ) ) ;
return - V_9 ;
}
if ( V_14 && ( V_15 > ( sizeof( V_2 -> V_7 ) - 1 ) ) ) {
F_2 ( V_8 ,
L_6
L_2 ,
V_3 ,
V_15 , ( unsigned int ) ( sizeof( V_2 -> V_7 ) - 1 ) ) ;
return - V_9 ;
}
F_3 ( V_2 -> V_10 ) ;
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
V_2 -> V_7 [ 0 ] = V_16 ;
V_2 -> V_7 [ 1 ] = V_13 ;
V_2 -> V_7 [ 2 ] = V_15 ;
V_2 -> V_7 [ 3 ] = V_3 ;
if ( V_13 ) memcpy ( V_2 -> V_7 + 4 , V_4 , V_13 ) ;
V_6 = F_4 ( V_2 ,
V_2 -> V_7 ,
4 + V_13 ,
V_2 -> V_7 ,
V_15 + 1 ) ;
if ( ! V_6 ) {
if ( V_2 -> V_7 [ 0 ] != 8 ) {
V_6 = - V_12 ;
if ( V_2 -> V_7 [ 0 ] != 7 ) {
F_5 ( L_3
L_7 ,
V_3 , V_2 -> V_7 [ 0 ] ) ;
}
}
}
if ( V_14 && V_15 ) {
if ( V_6 ) {
memset ( V_14 , 0 , V_15 ) ;
} else {
memcpy ( V_14 , V_2 -> V_7 + 1 , V_15 ) ;
}
}
F_6 ( V_2 -> V_10 ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_17 ,
T_2 V_18 ,
T_1 * V_19 ,
T_2 V_15 )
{
if ( ! V_19 ) V_15 = 0 ;
if ( ! V_17 ) V_18 = 0 ;
if ( V_15 || ! V_18 ) {
return F_7 ( V_2 , V_3 , V_17 , V_18 , V_19 , V_15 ) ;
} else {
return F_1 ( V_2 , V_3 , V_17 , V_18 ) ;
}
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_17 , T_2 V_18 , T_1 * V_19 , T_2 V_15 )
{
T_1 V_20 [ 4 ] ;
unsigned int V_21 ;
if ( ! ( V_15 || V_18 ) ) {
return 0 ;
}
if ( ( V_18 != 0 ) || ( V_15 == 0 ) ) return - V_12 ;
if ( V_15 < 3 ) {
if ( V_15 > 0 ) V_19 [ 0 ] = 0 ;
if ( V_15 > 1 ) V_19 [ 1 ] = 0 ;
return 0 ;
}
F_3 ( V_2 -> V_10 ) ; do {
V_2 -> V_7 [ 0 ] = V_22 ;
V_21 = F_4 ( V_2 ,
V_2 -> V_7 , 1 ,
V_2 -> V_7 , 4 ) ;
V_20 [ 0 ] = V_2 -> V_7 [ 0 ] ;
V_20 [ 1 ] = V_2 -> V_7 [ 1 ] ;
V_20 [ 2 ] = V_2 -> V_7 [ 2 ] ;
V_20 [ 3 ] = V_2 -> V_7 [ 3 ] ;
} while ( 0 ); F_6 ( V_2 -> V_10 ) ;
if ( V_21 != 0 ) return V_21 ;
V_19 [ 2 ] = 0xc1 ;
if ( V_20 [ 0 ] != 1 ) {
V_19 [ 0 ] = 0 ;
V_19 [ 1 ] = 0 ;
} else {
T_2 V_23 ;
V_23 = V_20 [ 1 ] ;
V_23 <<= 8 ;
V_23 |= V_20 [ 2 ] ;
V_23 >>= 1 ;
V_23 &= ~ 0x0003 ;
V_23 |= 0x8000 ;
V_19 [ 0 ] = ( V_23 >> 8 ) & 0xffu ;
V_19 [ 1 ] = V_23 & 0xffu ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_17 , T_2 V_18 , T_1 * V_19 , T_2 V_15 )
{
if ( ! ( V_15 || V_18 ) ) {
return 0 ;
}
return F_8 ( V_2 , V_3 , V_17 , V_18 , V_19 , V_15 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_17 , T_2 V_18 , T_1 * V_19 , T_2 V_15 )
{
return - V_12 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_17 , T_2 V_18 , T_1 * V_19 , T_2 V_15 )
{
int V_6 ;
unsigned int V_24 ;
T_1 V_25 [ 2 ] ;
int V_26 = V_2 -> V_27 ;
if ( ! ( V_15 || V_18 ) ) {
return 0 ;
}
if ( V_26 == 3 ) {
return F_8 ( V_2 , V_3 , V_17 , V_18 , V_19 , V_15 ) ;
}
if ( V_18 == 0 ) {
switch ( V_26 ) {
case 1 : V_24 = 0x0100 ; break;
case 2 : V_24 = 0x0101 ; break;
default: goto V_28;
}
} else if ( V_18 == 2 ) {
V_24 = ( V_17 [ 0 ] << 8 ) | V_17 [ 1 ] ;
switch ( V_24 ) {
case 0x0100 : V_26 = 1 ; break;
case 0x0101 : V_26 = 2 ; break;
default: goto V_28;
}
} else {
goto V_28;
}
if ( ! V_15 ) goto V_29;
V_26 = 0 ;
if ( V_15 != 1 ) goto V_28;
V_25 [ 0 ] = V_24 >> 8 ;
V_25 [ 1 ] = V_24 ;
V_6 = F_8 ( V_2 , V_3 , V_25 , 2 , V_19 , V_15 ) ;
if ( ( V_6 != 0 ) || ( * V_19 == 0x04 ) || ( * V_19 == 0x0a ) ) {
F_2 ( V_8 ,
L_8
L_9 ) ;
F_2 ( V_8 ,
L_10 ) ;
F_2 ( V_8 ,
L_11
L_12 ) ;
V_2 -> V_30 [ 0x44 ] = NULL ;
F_13 ( V_2 ) ;
goto V_28;
}
F_2 ( V_31 , L_13 ) ;
V_26 = 3 ;
V_29:
V_2 -> V_27 = V_26 ;
return 0 ;
V_28:
V_2 -> V_27 = V_26 ;
return - V_12 ;
}
static int F_14 ( struct V_32 * V_33 ,
struct V_34 V_35 [] ,
int V_36 )
{
int V_6 = - V_9 ;
T_3 V_37 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) ( V_33 -> V_38 ) ;
if ( ! V_36 ) {
V_6 = - V_39 ;
goto V_40;
}
if ( V_35 [ 0 ] . V_41 < V_42 ) {
V_37 = V_2 -> V_30 [ V_35 [ 0 ] . V_41 ] ;
}
if ( ! V_37 ) {
V_6 = - V_12 ;
goto V_40;
}
if ( V_36 == 1 ) {
if ( V_35 [ 0 ] . V_43 & V_44 ) {
T_2 V_45 , V_46 , V_47 ;
if ( ! V_35 [ 0 ] . V_48 ) {
if ( V_37 ( V_2 , V_35 [ 0 ] . V_41 , NULL , 0 , NULL , 0 ) ) {
V_6 = - V_12 ;
goto V_40;
}
V_6 = 1 ;
goto V_40;
}
V_45 = V_35 [ 0 ] . V_48 ;
V_47 = 0 ;
while ( V_45 ) {
V_46 = V_45 ;
if ( V_46 > sizeof( V_2 -> V_7 ) - 1 ) {
V_46 = sizeof( V_2 -> V_7 ) - 1 ;
}
if ( V_37 ( V_2 , V_35 [ 0 ] . V_41 , NULL , 0 ,
V_35 [ 0 ] . V_49 + V_47 , V_46 ) ) {
V_6 = - V_12 ;
goto V_40;
}
V_47 += V_46 ;
V_45 -= V_46 ;
}
V_6 = 1 ;
goto V_40;
} else {
V_6 = 1 ;
if ( V_37 ( V_2 , V_35 [ 0 ] . V_41 ,
V_35 [ 0 ] . V_49 , V_35 [ 0 ] . V_48 , NULL , 0 ) ) {
V_6 = - V_12 ;
}
goto V_40;
}
} else if ( V_36 == 2 ) {
if ( V_35 [ 0 ] . V_41 != V_35 [ 1 ] . V_41 ) {
F_5 ( L_14
L_15 ) ;
V_6 = - V_9 ;
goto V_40;
}
if ( ( ! ( ( V_35 [ 0 ] . V_43 & V_44 ) ) ) &&
( V_35 [ 1 ] . V_43 & V_44 ) ) {
T_2 V_45 , V_46 , V_50 , V_47 ;
V_45 = V_35 [ 1 ] . V_48 ;
V_50 = V_35 [ 0 ] . V_48 ;
V_47 = 0 ;
while ( V_45 || V_50 ) {
V_46 = V_45 ;
if ( V_46 > sizeof( V_2 -> V_7 ) - 1 ) {
V_46 = sizeof( V_2 -> V_7 ) - 1 ;
}
if ( V_37 ( V_2 , V_35 [ 0 ] . V_41 ,
V_35 [ 0 ] . V_49 , V_50 ,
V_35 [ 1 ] . V_49 + V_47 , V_46 ) ) {
V_6 = - V_12 ;
goto V_40;
}
V_47 += V_46 ;
V_45 -= V_46 ;
V_50 = 0 ;
}
V_6 = 2 ;
goto V_40;
} else {
F_5 ( L_16
L_17 ,
( V_35 [ 0 ] . V_43 & V_44 ) ,
( V_35 [ 1 ] . V_43 & V_44 ) ) ;
}
} else {
F_5 ( L_18 , V_36 ) ;
}
V_40:
if ( V_51 & V_52 ) {
unsigned int V_53 , V_47 , V_54 ;
for ( V_53 = 0 ; V_53 < V_36 ; V_53 ++ ) {
V_54 = V_35 [ V_53 ] . V_48 ;
F_15 ( V_55
L_19
L_20 ,
V_53 + 1 , V_36 ,
V_35 [ V_53 ] . V_41 ,
V_54 ,
( V_35 [ V_53 ] . V_43 & V_44 ?
L_21 : L_22 ) ) ;
if ( ( V_6 > 0 ) || ! ( V_35 [ V_53 ] . V_43 & V_44 ) ) {
if ( V_54 > 8 ) V_54 = 8 ;
F_15 ( L_23 ) ;
for ( V_47 = 0 ; V_47 < ( V_54 > 8 ? 8 : V_54 ) ; V_47 ++ ) {
if ( V_47 ) F_15 ( L_24 ) ;
F_15 ( L_25 , V_35 [ V_53 ] . V_49 [ V_47 ] ) ;
}
if ( V_47 < V_54 ) F_15 ( L_26 ) ;
F_15 ( L_27 ) ;
}
if ( V_53 + 1 == V_36 ) {
F_15 ( L_28 , V_6 ) ;
}
F_15 ( L_29 ) ;
}
if ( ! V_36 ) {
F_15 ( V_55
L_30 ,
V_6 ) ;
}
}
return V_6 ;
}
static T_4 F_16 ( struct V_32 * V_56 )
{
return V_57 | V_58 ;
}
static int F_17 ( struct V_1 * V_2 , int V_41 )
{
struct V_34 V_59 [ 1 ] ;
int V_60 ;
V_59 [ 0 ] . V_41 = 0 ;
V_59 [ 0 ] . V_43 = V_44 ;
V_59 [ 0 ] . V_48 = 0 ;
V_59 [ 0 ] . V_49 = NULL ;
V_59 [ 0 ] . V_41 = V_41 ;
V_60 = F_18 ( & V_2 -> V_33 , V_59 , F_19 ( V_59 ) ) ;
return V_60 == 1 ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_61 ;
F_15 ( V_55 L_31 , V_2 -> V_62 ) ;
for ( V_61 = 0 ; V_61 < 128 ; V_61 ++ ) {
if ( F_17 ( V_2 , V_61 ) ) {
F_15 ( V_55 L_32 ,
V_2 -> V_62 , V_61 ) ;
}
}
F_15 ( V_55 L_33 , V_2 -> V_62 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_63 V_64 ;
struct V_65 * V_66 = & V_2 -> V_67 ;
if ( V_68 ) {
F_2 ( V_69 ,
L_34 ) ;
return;
}
memset ( & V_64 , 0 , sizeof( struct V_63 ) ) ;
switch ( V_2 -> V_70 ) {
case V_71 :
case V_72 :
V_66 -> V_73 = V_74 ;
V_66 -> V_75 = V_76 ;
V_66 -> type = V_77 ;
V_66 -> V_62 = V_2 -> V_78 -> V_79 ;
V_66 -> V_80 = 100 ;
V_64 . V_41 = 0x18 ;
V_64 . V_81 = V_66 ;
F_22 ( V_64 . type , L_35 , V_82 ) ;
F_2 ( V_69 , L_36 ,
V_64 . type , V_64 . V_41 ) ;
F_23 ( & V_2 -> V_33 , & V_64 ) ;
break;
case V_83 :
case V_84 :
V_66 -> V_73 = V_74 ;
V_66 -> V_75 = V_85 ;
V_66 -> type = V_77 | V_86 |
V_87 ;
V_66 -> V_62 = V_2 -> V_78 -> V_79 ;
V_64 . V_41 = 0x71 ;
V_64 . V_81 = V_66 ;
F_22 ( V_64 . type , L_37 , V_82 ) ;
F_2 ( V_69 , L_36 ,
V_64 . type , V_64 . V_41 ) ;
F_23 ( & V_2 -> V_33 , & V_64 ) ;
V_64 . V_41 = 0x70 ;
V_64 . V_81 = V_66 ;
F_22 ( V_64 . type , L_38 , V_82 ) ;
F_2 ( V_69 , L_36 ,
V_64 . type , V_64 . V_41 ) ;
F_23 ( & V_2 -> V_33 , & V_64 ) ;
break;
default:
break;
}
}
void F_24 ( struct V_1 * V_2 )
{
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_42 ; V_53 ++ ) {
V_2 -> V_30 [ V_53 ] = F_8 ;
}
if ( V_88 [ V_2 -> V_89 ] == 0 ) {
F_15 ( V_55 L_39 , V_2 -> V_62 ) ;
V_2 -> V_30 [ 0x18 ] = F_11 ;
} else if ( V_88 [ V_2 -> V_89 ] == 1 ) {
if ( V_2 -> V_70 == V_71 ) {
V_2 -> V_30 [ 0x18 ] = F_9 ;
}
}
if ( V_2 -> V_78 -> V_90 ) {
V_2 -> V_30 [ 0x44 ] = F_12 ;
}
if ( V_2 -> V_78 -> V_91 ) {
V_2 -> V_30 [ 0x1b ] = F_10 ;
}
V_2 -> V_33 = V_92 ;
V_2 -> V_93 = V_94 ;
F_22 ( V_2 -> V_33 . V_62 , V_2 -> V_62 , sizeof( V_2 -> V_33 . V_62 ) ) ;
V_2 -> V_33 . V_95 . V_96 = & V_2 -> V_97 -> V_95 ;
V_2 -> V_33 . V_98 = & V_2 -> V_93 ;
V_2 -> V_33 . V_38 = V_2 ;
V_2 -> V_99 = ! 0 ;
F_25 ( & V_2 -> V_33 , & V_2 -> V_100 ) ;
F_26 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_30 [ 0x18 ] == F_9 ) {
if ( F_17 ( V_2 , 0x71 ) ) {
F_2 ( V_69 ,
L_40
L_41 ) ;
V_2 -> V_30 [ 0x18 ] = NULL ;
V_2 -> V_70 = V_84 ;
}
}
if ( V_101 ) F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_99 ) {
F_28 ( & V_2 -> V_33 ) ;
V_2 -> V_99 = 0 ;
}
}
