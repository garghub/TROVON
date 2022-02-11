void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
char * V_5 ;
int V_6 ;
struct V_7 * V_8 ;
#define F_2 ((__u8[6]) { 1, 0x10, 0x18, 1, 0, 2 })
static T_1 V_9 [ V_10 ] = F_2 ;
V_4 = F_3 ( sizeof( struct V_7 ) ) ;
if ( ! V_4 )
return;
V_6 = sizeof( * V_8 ) ;
V_5 = ( char * ) V_4 -> V_11 ;
V_8 = (struct V_7 * ) V_5 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_4 ( V_8 -> V_12 . V_13 , V_2 -> V_14 ) ;
F_4 ( V_8 -> V_12 . V_15 , V_9 ) ;
V_8 -> V_12 . V_16 = F_5 ( V_17 ) ;
V_8 -> V_18 . V_19 = F_6 ( V_20 ) ;
V_8 -> V_18 . V_21 = F_5 ( V_22 ) ;
V_8 -> V_18 . V_23 = V_24 ;
V_8 -> V_18 . V_25 = F_5 ( sizeof( V_8 -> V_26 ) / V_27 ) ;
V_8 -> V_26 . V_14 . V_28 . V_29 = V_30 ;
V_8 -> V_26 . V_14 . V_28 . V_31 = sizeof( V_8 -> V_26 . V_14 ) / V_27 ;
F_4 ( V_8 -> V_26 . V_14 . V_32 , V_2 -> V_14 ) ;
V_8 -> V_26 . V_33 . V_28 . V_29 = V_34 ;
V_8 -> V_26 . V_33 . V_28 . V_31 = sizeof( V_8 -> V_26 . V_33 ) / V_27 ;
F_7 ( V_2 -> V_35 -> V_33 , & V_8 -> V_26 . V_33 . V_36 ) ;
F_8 ( V_4 , sizeof( * V_8 ) ) ;
V_4 -> V_37 = F_5 ( V_17 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
F_11 ( & ( V_2 -> V_38 ) , V_39 , L_1
L_2 ) ;
if ( F_12 ( & V_2 -> V_40 ) != V_41 ) {
F_13 ( & ( V_2 -> V_38 ) , L_3
L_4 ) ;
F_14 ( V_4 ) ;
return;
}
V_42 -> V_43 -> V_44 ( V_2 -> V_45 , V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_46 * V_47 ;
struct V_48 * V_26 ;
T_2 V_49 = 0 ;
T_3 V_50 ;
T_4 V_51 ;
V_47 = (struct V_46 * ) ( ( ( void * ) V_4 -> V_11 ) + 2 * V_10 + 2 ) ;
V_50 = F_16 ( V_47 -> V_25 ) * 4 ;
V_26 = (struct V_48 * ) ( V_47 + 1 ) ;
while ( V_50 > 0 ) {
V_51 = V_26 -> V_31 * V_27 ;
switch ( V_26 -> V_29 ) {
case V_52 :
V_49 = F_16 ( ( (struct V_53 * ) V_26 ) -> V_54 ) ;
break;
}
V_26 = (struct V_48 * ) ( ( char * ) V_26 + V_51 ) ;
V_50 -= V_51 ;
}
F_11 ( & ( V_2 -> V_38 ) , V_39 , L_5
L_6 , V_49 ) ;
if ( V_49 > 0 && V_2 -> V_55 != V_49 ) {
F_17 ( V_2 , V_49 ) ;
if ( ! F_18 ( & V_2 -> V_56 ) )
F_19 ( & V_2 -> V_56 ) ;
}
}
void F_20 ( struct V_57 * V_18 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_21 ( V_18 , struct V_1 , V_58 ) ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_46 * V_47 ;
T_2 V_63 , V_64 = 0 ;
T_1 V_65 ;
if ( ! F_22 ( V_66 , & V_2 -> V_67 ) ) {
F_13 ( & ( V_2 -> V_38 ) , L_7 ) ;
F_14 ( V_4 ) ;
return;
}
V_47 = (struct V_46 * ) ( ( void * ) V_4 -> V_11 + 2 * V_10 + 2 ) ;
V_60 = (struct V_59 * ) F_23 ( V_4 ) ;
V_63 = F_16 ( V_47 -> V_21 ) ;
V_65 = V_47 -> V_23 ;
if ( ! V_2 -> V_68 ) {
V_62 = (struct V_61 * ) F_24 ( V_4 , sizeof( * V_62 )
- sizeof( * V_60 ) ) ;
memcpy ( V_62 , V_60 , 2 * V_10 ) ;
V_62 -> V_69 = F_5 ( V_70 ) ;
V_62 -> V_71 = V_60 -> V_16 ;
V_62 -> V_72 = V_64 = F_5 ( V_2 -> V_55 ) ;
}
V_60 = (struct V_59 * ) F_23 ( V_4 ) ;
F_11 ( & ( V_2 -> V_38 ) , V_73 , L_8
L_9 , V_60 -> V_15 , V_63 , V_65 ,
F_16 ( V_64 ) ) ;
if ( V_74 )
F_25 ( V_75 , L_10 , V_76 , 16 , 1 ,
V_4 -> V_11 , V_4 -> V_77 , false ) ;
V_42 -> V_43 -> V_44 ( V_2 -> V_45 , V_4 ) ;
}
void F_26 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_59 * V_60 ;
struct V_46 * V_47 ;
struct V_48 * V_26 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
T_4 V_50 , V_51 ;
T_5 V_84 ;
T_6 V_85 [ V_10 ] ;
T_2 V_63 ;
T_1 V_65 ;
V_60 = (struct V_59 * ) F_23 ( V_4 ) ;
V_47 = (struct V_46 * ) ( ( void * ) V_4 -> V_11 + 2 * V_10 + 2 ) ;
V_63 = F_16 ( V_47 -> V_21 ) ;
V_65 = V_47 -> V_23 ;
F_11 ( & ( V_2 -> V_38 ) , V_73 , L_11
L_12 , V_4 , V_47 ,
V_60 -> V_13 , V_63 , V_65 ) ;
if ( V_74 )
F_25 ( V_75 , L_10 , V_76 , 16 , 1 ,
V_4 -> V_11 , V_4 -> V_77 , false ) ;
if ( V_63 == V_22 && V_65 == V_86 ) {
F_15 ( V_2 , V_4 ) ;
V_2 -> V_68 = 0 ;
F_14 ( V_4 ) ;
} else if ( V_63 == V_87 && V_65 == V_88 ) {
F_11 ( & ( V_2 -> V_38 ) , V_39 , L_13
L_14 ) ;
if ( V_2 -> V_58 . V_89 == NULL ) {
F_11 ( & ( V_2 -> V_38 ) , V_39 ,
L_15
L_16 ) ;
return;
}
V_84 = 0 ;
memset ( V_85 , 0 , V_10 ) ;
V_50 = F_16 ( V_47 -> V_25 ) * V_27 ;
V_26 = (struct V_48 * ) ( V_47 + 1 ) ;
while ( V_50 >= sizeof( * V_26 ) ) {
V_51 = V_26 -> V_31 * V_27 ;
switch ( V_26 -> V_29 ) {
case V_30 :
V_79 = (struct V_78 * ) V_26 ;
F_11 ( & ( V_2 -> V_38 ) , V_73 ,
L_17 , V_79 -> V_32 ) ;
F_4 ( V_85 , V_79 -> V_32 ) ;
break;
case V_34 :
V_81 = (struct V_80 * ) V_26 ;
F_11 ( & ( V_2 -> V_38 ) , V_73 ,
L_18 ,
F_27 ( & V_81 -> V_36 ) ) ;
break;
case V_90 :
V_83 = (struct V_82 * ) V_26 ;
F_11 ( & ( V_2 -> V_38 ) , V_73 ,
L_19 , F_28 ( V_83 -> V_91 ) ) ;
V_84 = F_28 ( V_83 -> V_91 ) ;
break;
default:
break;
}
V_26 = (struct V_48 * ) ( ( char * ) V_26 + V_51 ) ;
V_50 -= V_51 ;
}
F_11 ( & ( V_2 -> V_38 ) , V_73 ,
L_20 , V_84 ,
V_85 ) ;
if ( V_84 == V_2 -> V_35 -> V_92 &&
F_29 ( V_85 ,
V_2 -> V_58 . V_89 -> V_93 ) ) {
F_30 ( & V_2 -> V_58 ) ;
F_31 ( V_2 ) ;
F_32 ( & V_2 -> V_58 ) ;
}
F_14 ( V_4 ) ;
} else {
F_33 ( V_4 , V_94 ) ;
F_34 ( & V_2 -> V_58 , V_4 ) ;
}
}
void F_35 ( struct V_95 * V_35 , T_1 * V_96 )
{
struct V_1 * V_2 = F_36 ( V_35 ) ;
F_11 ( & ( V_2 -> V_38 ) , V_39 ,
L_21 , V_96 ) ;
F_4 ( V_2 -> V_97 , V_96 ) ;
}
T_1 * F_37 ( struct V_95 * V_35 )
{
T_1 V_14 [ V_10 ] ;
T_1 V_92 [ 3 ] ;
struct V_1 * V_2 = F_36 ( V_35 ) ;
if ( F_38 ( V_2 -> V_97 ) ) {
F_39 ( V_92 , V_35 -> V_92 ) ;
F_40 ( V_14 , V_92 ) ;
V_2 -> V_58 . V_98 ( V_35 , V_14 ) ;
}
return V_2 -> V_97 ;
}
