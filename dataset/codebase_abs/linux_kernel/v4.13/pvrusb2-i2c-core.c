static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_4 ,
T_2 V_5 )
{
int V_6 ;
if ( ! V_4 ) V_5 = 0 ;
if ( V_5 > ( sizeof( V_2 -> V_7 ) - 3 ) ) {
F_2 ( V_8 ,
L_1 ,
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
F_5 ( L_2 ,
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
L_3 ,
V_3 ,
V_13 , ( unsigned int ) ( sizeof( V_2 -> V_7 ) - 4 ) ) ;
return - V_9 ;
}
if ( V_14 && ( V_15 > ( sizeof( V_2 -> V_7 ) - 1 ) ) ) {
F_2 ( V_8 ,
L_4 ,
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
F_5 ( L_5 ,
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
L_6 ) ;
F_2 ( V_8 ,
L_7 ) ;
F_2 ( V_8 ,
L_8 ) ;
V_2 -> V_30 [ 0x44 ] = NULL ;
F_13 ( V_2 ) ;
goto V_28;
}
F_2 ( V_31 , L_9 ) ;
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
F_5 ( L_10 ) ;
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
F_5 ( L_11 ,
( V_35 [ 0 ] . V_43 & V_44 ) ,
( V_35 [ 1 ] . V_43 & V_44 ) ) ;
}
} else {
F_5 ( L_12 , V_36 ) ;
}
V_40:
if ( V_51 & V_52 ) {
unsigned int V_53 , V_47 , V_54 ;
for ( V_53 = 0 ; V_53 < V_36 ; V_53 ++ ) {
V_54 = V_35 [ V_53 ] . V_48 ;
F_15 ( V_55
L_13 ,
V_53 + 1 , V_36 ,
V_35 [ V_53 ] . V_41 ,
V_54 ,
( V_35 [ V_53 ] . V_43 & V_44 ?
L_14 : L_15 ) ) ;
if ( ( V_6 > 0 ) || ! ( V_35 [ V_53 ] . V_43 & V_44 ) ) {
if ( V_54 > 8 ) V_54 = 8 ;
F_15 ( V_56 L_16 ) ;
for ( V_47 = 0 ; V_47 < V_54 ; V_47 ++ ) {
if ( V_47 ) F_15 ( V_56 L_17 ) ;
F_15 ( V_56 L_18 , V_35 [ V_53 ] . V_49 [ V_47 ] ) ;
}
if ( V_47 < V_54 ) F_15 ( V_56 L_19 ) ;
F_15 ( V_56 L_20 ) ;
}
if ( V_53 + 1 == V_36 ) {
F_15 ( V_56 L_21 , V_6 ) ;
}
F_15 ( V_56 L_22 ) ;
}
if ( ! V_36 ) {
F_15 ( V_55
L_23 ,
V_6 ) ;
}
}
return V_6 ;
}
static T_4 F_16 ( struct V_32 * V_57 )
{
return V_58 | V_59 ;
}
static int F_17 ( struct V_1 * V_2 , int V_41 )
{
struct V_34 V_60 [ 1 ] ;
int V_61 ;
V_60 [ 0 ] . V_41 = 0 ;
V_60 [ 0 ] . V_43 = V_44 ;
V_60 [ 0 ] . V_48 = 0 ;
V_60 [ 0 ] . V_49 = NULL ;
V_60 [ 0 ] . V_41 = V_41 ;
V_61 = F_18 ( & V_2 -> V_33 , V_60 , F_19 ( V_60 ) ) ;
return V_61 == 1 ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_62 ;
F_15 ( V_55 L_24 , V_2 -> V_63 ) ;
for ( V_62 = 0 ; V_62 < 128 ; V_62 ++ ) {
if ( F_17 ( V_2 , V_62 ) ) {
F_15 ( V_55 L_25 ,
V_2 -> V_63 , V_62 ) ;
}
}
F_15 ( V_55 L_26 , V_2 -> V_63 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_64 V_65 ;
struct V_66 * V_67 = & V_2 -> V_68 ;
if ( V_69 ) {
F_2 ( V_70 ,
L_27 ) ;
return;
}
memset ( & V_65 , 0 , sizeof( struct V_64 ) ) ;
switch ( V_2 -> V_71 ) {
case V_72 :
case V_73 :
V_67 -> V_74 = V_75 ;
V_67 -> V_76 = V_77 ;
V_67 -> type = V_78 ;
V_67 -> V_63 = V_2 -> V_79 -> V_80 ;
V_67 -> V_81 = 100 ;
V_65 . V_41 = 0x18 ;
V_65 . V_82 = V_67 ;
F_22 ( V_65 . type , L_28 , V_83 ) ;
F_2 ( V_70 , L_29 ,
V_65 . type , V_65 . V_41 ) ;
F_23 ( & V_2 -> V_33 , & V_65 ) ;
break;
case V_84 :
case V_85 :
V_67 -> V_74 = V_75 ;
V_67 -> V_76 = V_86 ;
V_67 -> type = V_78 | V_87 |
V_88 ;
V_67 -> V_63 = V_2 -> V_79 -> V_80 ;
V_65 . V_41 = 0x71 ;
V_65 . V_82 = V_67 ;
F_22 ( V_65 . type , L_30 , V_83 ) ;
F_2 ( V_70 , L_29 ,
V_65 . type , V_65 . V_41 ) ;
F_23 ( & V_2 -> V_33 , & V_65 ) ;
V_65 . V_41 = 0x70 ;
V_65 . V_82 = V_67 ;
F_22 ( V_65 . type , L_31 , V_83 ) ;
F_2 ( V_70 , L_29 ,
V_65 . type , V_65 . V_41 ) ;
F_23 ( & V_2 -> V_33 , & V_65 ) ;
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
if ( V_89 [ V_2 -> V_90 ] == 0 ) {
F_15 ( V_55 L_32 , V_2 -> V_63 ) ;
V_2 -> V_30 [ 0x18 ] = F_11 ;
} else if ( V_89 [ V_2 -> V_90 ] == 1 ) {
if ( V_2 -> V_71 == V_72 ) {
V_2 -> V_30 [ 0x18 ] = F_9 ;
}
}
if ( V_2 -> V_79 -> V_91 ) {
V_2 -> V_30 [ 0x44 ] = F_12 ;
}
if ( V_2 -> V_79 -> V_92 ) {
V_2 -> V_30 [ 0x1b ] = F_10 ;
}
V_2 -> V_33 = V_93 ;
V_2 -> V_94 = V_95 ;
F_22 ( V_2 -> V_33 . V_63 , V_2 -> V_63 , sizeof( V_2 -> V_33 . V_63 ) ) ;
V_2 -> V_33 . V_96 . V_97 = & V_2 -> V_98 -> V_96 ;
V_2 -> V_33 . V_99 = & V_2 -> V_94 ;
V_2 -> V_33 . V_38 = V_2 ;
V_2 -> V_100 = ! 0 ;
F_25 ( & V_2 -> V_33 , & V_2 -> V_101 ) ;
F_26 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_30 [ 0x18 ] == F_9 ) {
if ( F_17 ( V_2 , 0x71 ) ) {
F_2 ( V_70 ,
L_33 ) ;
V_2 -> V_30 [ 0x18 ] = NULL ;
V_2 -> V_71 = V_85 ;
}
}
if ( V_102 ) F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_100 ) {
F_28 ( & V_2 -> V_33 ) ;
V_2 -> V_100 = 0 ;
}
}
