static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( ! V_3 || ! F_2 ( V_3 -> V_4 , V_3 -> V_5 -> V_6 ) )
return;
F_3 ( V_3 -> V_5 , V_3 -> V_4 , 0 ) ;
F_4 ( V_3 -> V_5 ) ;
}
static void F_5 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_1 V_7 = V_3 -> V_8 ;
T_2 V_9 ;
T_2 V_10 ;
T_3 V_11 ;
T_3 V_12 ;
switch ( V_3 -> V_13 ) {
case V_14 :
V_9 = V_7 & 0x3f ;
V_10 = ( V_7 >> 6 ) & 0x1f ;
V_11 = V_7 & 0x0800 ;
break;
case V_15 :
V_9 = V_7 & 0xff ;
V_10 = ( V_7 >> 8 ) & 0x1f ;
V_11 = V_7 & 0x8000 ;
break;
case V_16 :
V_9 = V_7 & 0x3f ;
V_10 = ( V_7 >> 6 ) & 0x1f ;
if ( ! ( V_7 & 0x1000 ) )
V_9 |= 0x40 ;
V_11 = V_7 & 0x0800 ;
break;
default:
F_6 ( L_1 , V_17 , V_3 -> V_13 ) ;
return;
}
F_7 ( V_3 -> V_5 , V_18 , V_19 , ( V_10 << 16 ) | V_9 ) ;
F_7 ( V_3 -> V_5 , V_18 , V_20 , V_9 ) ;
V_12 = V_3 -> V_21 [ V_9 ] ;
F_8 ( 16 , L_2 ,
V_17 , V_7 , V_10 , V_9 , V_12 ) ;
if ( ! ( V_3 -> V_22 & ( 1 << V_10 ) ) )
return;
if ( ! V_12 ) {
F_6 ( L_3 ,
V_17 , V_7 , V_10 , V_9 ) ;
return;
}
if ( F_9 ( & V_3 -> V_23 ) ) {
F_10 ( & V_3 -> V_23 ) ;
if ( V_3 -> V_4 != V_12 || V_11 != V_3 -> V_24 ) {
V_3 -> V_25 = 0 ;
F_7 ( V_3 -> V_5 , V_26 , V_3 -> V_4 , 0 ) ;
F_7 ( V_3 -> V_5 , V_26 , V_12 , 1 ) ;
F_4 ( V_3 -> V_5 ) ;
} else if ( V_3 -> V_25 ) {
F_7 ( V_3 -> V_5 , V_26 , V_12 , 2 ) ;
F_4 ( V_3 -> V_5 ) ;
}
} else {
V_3 -> V_25 = 0 ;
F_7 ( V_3 -> V_5 , V_26 , V_12 , 1 ) ;
F_4 ( V_3 -> V_5 ) ;
}
V_3 -> V_4 = V_12 ;
V_3 -> V_24 = V_11 ;
V_3 -> V_23 . V_27 = V_28 + V_29 ;
F_11 ( & V_3 -> V_23 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
int V_30 ;
F_13 ( V_26 , V_3 -> V_5 -> V_31 ) ;
F_13 ( V_32 , V_3 -> V_5 -> V_31 ) ;
F_13 ( V_18 , V_3 -> V_5 -> V_31 ) ;
F_13 ( V_19 , V_3 -> V_5 -> V_33 ) ;
F_13 ( V_20 , V_3 -> V_5 -> V_33 ) ;
memset ( V_3 -> V_5 -> V_34 , 0 , sizeof( V_3 -> V_5 -> V_34 ) ) ;
for ( V_30 = 0 ; V_30 < F_14 ( V_3 -> V_21 ) ; V_30 ++ ) {
if ( V_3 -> V_21 [ V_30 ] > V_35 )
V_3 -> V_21 [ V_30 ] = 0 ;
else if ( V_3 -> V_21 [ V_30 ] > V_36 )
F_13 ( V_3 -> V_21 [ V_30 ] , V_3 -> V_5 -> V_34 ) ;
}
V_3 -> V_5 -> V_12 = V_3 -> V_21 ;
V_3 -> V_5 -> V_37 = sizeof( V_3 -> V_21 [ 0 ] ) ;
V_3 -> V_5 -> V_38 = F_14 ( V_3 -> V_21 ) ;
}
static void F_15 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_25 = 1 ;
}
int F_16 ( struct V_39 * V_39 , int V_40 )
{
int V_30 ;
int V_41 = V_40 ;
int V_42 = - V_43 ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ )
if ( V_39 == V_45 [ V_30 ] )
break;
if ( V_30 < V_44 && V_39 ) {
if ( ( V_39 -> V_3 . V_13 & 1 ) != V_46 [ V_30 ] ||
V_39 -> V_3 . V_47 != V_48 [ V_30 ] )
V_41 = true ;
if ( V_41 ) {
if ( V_46 [ V_30 ] ) {
V_46 [ V_30 ] = 1 ;
V_39 -> V_3 . V_13 = V_15 ;
V_39 -> V_3 . V_49 = 0x0001 ;
} else if ( F_17 ( V_39 -> V_50 ) >= 0x2620 ) {
V_39 -> V_3 . V_13 = V_16 ;
V_39 -> V_3 . V_49 = 0x0002 ;
} else {
V_39 -> V_3 . V_13 = V_14 ;
V_39 -> V_3 . V_49 = 0x0000 ;
}
if ( V_48 [ V_30 ] ) {
V_48 [ V_30 ] = 1 ;
V_39 -> V_3 . V_49 |= 0x8000 ;
}
V_39 -> V_3 . V_47 = V_48 [ V_30 ] ;
V_42 = F_18 ( V_39 , V_51 , V_52 , 1 ,
V_39 -> V_3 . V_49 ) ;
} else
V_42 = 0 ;
if ( V_39 -> V_3 . V_22 != V_53 [ V_30 ] )
V_39 -> V_3 . V_22 = V_53 [ V_30 ] ;
}
return V_42 ;
}
static T_4 F_19 ( struct V_54 * V_54 , const char T_5 * V_55 ,
T_6 V_56 , T_7 * V_57 )
{
char * V_58 ;
T_1 V_49 ;
int V_59 = sizeof V_49 + sizeof V_45 [ 0 ] -> V_3 . V_21 ;
int V_30 ;
if ( V_56 < V_59 )
return - V_60 ;
V_58 = F_20 ( V_59 ) ;
if ( ! V_58 )
return - V_61 ;
if ( F_21 ( V_58 , V_55 , V_59 ) ) {
F_22 ( V_58 ) ;
return - V_62 ;
}
memcpy ( & V_49 , V_58 , sizeof V_49 ) ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ ) {
memcpy ( V_45 [ V_30 ] -> V_3 . V_21 , V_58 + sizeof V_49 ,
sizeof( V_45 [ V_30 ] -> V_3 . V_21 ) ) ;
V_46 [ V_30 ] = V_49 & 0x0001 ;
V_48 [ V_30 ] = V_49 & 0x8000 ? 1 : 0 ;
if ( V_49 & 0x4000 )
V_53 [ V_30 ] = 1 << ( ( V_49 >> 16 ) & 0x1f ) ;
else
V_53 [ V_30 ] = V_63 ;
F_16 ( V_45 [ V_30 ] , false ) ;
F_12 ( & V_45 [ V_30 ] -> V_3 ) ;
}
F_22 ( V_58 ) ;
return V_56 ;
}
static void F_23 ( struct V_39 * V_39 , T_1 V_7 )
{
F_8 ( 4 , L_4 , V_7 ) ;
V_39 -> V_3 . V_8 = V_7 ;
F_24 ( & V_39 -> V_3 . V_64 ) ;
}
int T_8 F_25 ( struct V_39 * V_39 )
{
struct V_5 * V_5 ;
static struct V_65 * V_66 ;
int V_67 ;
if ( V_44 >= F_14 ( V_45 ) )
return - V_68 ;
V_45 [ V_44 ++ ] = V_39 ;
F_16 ( V_39 , true ) ;
F_26 ( & V_39 -> V_3 . V_23 ) ;
V_39 -> V_3 . V_23 . V_69 = F_1 ;
V_39 -> V_3 . V_23 . V_9 = ( unsigned long ) & V_39 -> V_3 ;
V_5 = F_27 () ;
if ( ! V_5 )
return - V_61 ;
V_39 -> V_3 . V_5 = V_5 ;
snprintf ( V_39 -> V_3 . V_70 , sizeof( V_39 -> V_3 . V_70 ) ,
L_5 , F_28 ( V_39 -> V_71 -> V_72 ) ) ;
V_5 -> V_73 = L_6 ;
V_5 -> V_74 = V_39 -> V_3 . V_70 ;
V_5 -> V_75 . V_76 = V_77 ;
V_5 -> V_75 . V_78 = 2 ;
if ( V_39 -> V_71 -> V_72 -> V_79 ) {
V_5 -> V_75 . V_80 = V_39 -> V_71 -> V_72 -> V_79 ;
V_5 -> V_75 . V_81 = V_39 -> V_71 -> V_72 -> V_82 ;
} else {
V_5 -> V_75 . V_80 = V_39 -> V_71 -> V_72 -> V_80 ;
V_5 -> V_75 . V_81 = V_39 -> V_71 -> V_72 -> V_83 ;
}
V_5 -> V_71 . V_84 = & V_39 -> V_71 -> V_72 -> V_71 ;
memcpy ( V_39 -> V_3 . V_21 , V_85 , sizeof V_39 -> V_3 . V_21 ) ;
F_12 ( & V_39 -> V_3 ) ;
V_67 = F_29 ( V_5 ) ;
if ( V_67 ) {
F_30 ( V_5 ) ;
return V_67 ;
}
V_5 -> V_86 . V_69 = F_15 ;
V_5 -> V_86 . V_9 = ( unsigned long ) & V_39 -> V_3 ;
if ( V_44 == 1 ) {
V_66 = F_31 ( L_7 , V_87 , NULL , & V_88 ) ;
if ( V_66 )
V_66 -> V_59 = 4 + 256 * sizeof( T_3 ) ;
}
F_32 ( & V_39 -> V_3 . V_64 , F_5 , ( unsigned long ) & V_39 -> V_3 ) ;
V_39 -> V_3 . F_23 = F_23 ;
return 0 ;
}
void T_9 F_33 ( struct V_39 * V_39 )
{
int V_30 ;
if ( V_44 == 0 )
return;
F_34 ( & V_39 -> V_3 . V_23 ) ;
V_39 -> V_3 . F_23 = NULL ;
F_35 ( & V_39 -> V_3 . V_64 ) ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ )
if ( V_45 [ V_30 ] == V_39 ) {
V_45 [ V_30 ] = V_45 [ V_44 - 1 ] ;
V_45 [ V_44 - 1 ] = NULL ;
break;
}
if ( V_44 == 1 )
F_36 ( L_7 , NULL ) ;
F_37 ( V_39 -> V_3 . V_5 ) ;
V_44 -- ;
}
