static void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( V_4 >= V_2 -> V_9 ) {
V_3 [ 2 ] = V_10 ;
return;
}
V_3 [ 2 ] = V_11 ;
V_6 = V_2 -> V_5 [ V_4 ] -> V_6 ;
V_3 [ 9 ] = V_4 ;
V_3 [ 13 ] = V_6 -> V_12 ;
memcpy ( V_3 + 16 , V_2 -> V_13 , V_14 ) ;
memcpy ( V_3 + 24 , V_2 -> V_5 [ V_4 ] -> V_15 ,
V_14 ) ;
V_3 [ 40 ] = ( V_6 -> V_16 << 4 ) |
V_6 -> V_17 ;
V_3 [ 41 ] = ( V_6 -> V_18 << 4 ) |
V_6 -> V_19 ;
if ( ! V_2 -> V_5 [ V_4 ] -> V_20 ||
! V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 )
return;
V_8 = V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 -> V_8 ;
V_3 [ 12 ] = V_8 -> V_22 . V_23 << 4 ;
V_3 [ 14 ] = V_8 -> V_22 . V_24 ;
V_3 [ 15 ] = V_8 -> V_22 . V_25 ;
}
static T_1 * F_2 ( unsigned int V_26 , T_1 * V_27 , T_1 V_28 , T_1 V_29 , T_1 * V_30 )
{
unsigned int V_31 ;
T_1 V_32 ;
if ( V_28 == 0 )
return NULL ;
V_28 -- ;
if ( V_26 < V_28 * 32 )
return NULL ;
V_26 -= V_28 * 32 ;
V_31 = V_26 >> 5 ;
if ( V_31 >= V_29 )
return NULL ;
V_26 &= ( 1 << 5 ) - 1 ;
V_32 = 3 - ( V_26 >> 3 ) ;
* V_30 = V_26 & ( ( 1 << 3 ) - 1 ) ;
return & V_27 [ V_31 * 4 + V_32 ] ;
}
int F_3 ( unsigned int V_26 , T_1 * V_27 , T_1 V_28 , T_1 V_29 )
{
T_1 * V_32 ;
T_1 V_30 ;
V_32 = F_2 ( V_26 , V_27 , V_28 , V_29 , & V_30 ) ;
if ( ! V_32 )
return - 1 ;
return ( * V_32 >> V_30 ) & 1 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_33 , T_1 V_34 , T_1 V_35 ,
T_1 * V_36 )
{
struct V_37 * V_38 = F_5 ( V_2 -> V_39 . V_40 -> V_41 ) ;
int V_42 ;
if ( V_38 -> V_43 -> V_44 == NULL ) {
V_3 [ 2 ] = V_45 ;
return 0 ;
}
V_42 = V_38 -> V_43 -> V_44 ( V_2 , V_33 , V_34 ,
V_35 , V_36 ) ;
if ( V_42 < 0 ) {
V_3 [ 2 ] = V_46 ;
V_42 = 0 ;
} else
V_3 [ 2 ] = V_11 ;
return V_42 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_4 )
{
struct V_7 * V_8 ;
struct V_47 * V_48 ;
int V_38 ;
if ( V_4 >= V_2 -> V_9 ) {
V_3 [ 2 ] = V_10 ;
return;
}
V_3 [ 2 ] = V_49 ;
if ( ! V_2 -> V_5 [ V_4 ] -> V_20 )
return;
V_8 = V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 -> V_8 ;
V_48 = (struct V_47 * )
V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 -> V_50 ;
if ( V_8 -> V_22 . V_25 != V_51 )
return;
V_3 [ 2 ] = V_11 ;
V_3 [ 9 ] = V_4 ;
memcpy ( V_3 + 16 , V_2 -> V_5 [ V_4 ] -> V_15 ,
V_14 ) ;
if ( V_48 -> V_52 != 0x34 )
return;
for ( V_38 = 0 ; V_38 < 20 ; V_38 += 4 ) {
T_1 * V_53 = V_3 + 24 + V_38 , * V_54 =
& V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 -> V_50 [ V_38 ] ;
V_53 [ 0 ] = V_54 [ 3 ] ;
V_53 [ 1 ] = V_54 [ 2 ] ;
V_53 [ 2 ] = V_54 [ 1 ] ;
V_53 [ 3 ] = V_54 [ 0 ] ;
}
}
static void F_7 ( struct V_1 * V_2 , T_1 V_4 ,
T_1 V_55 , enum V_56 V_57 ,
enum V_56 V_58 , T_1 * V_3 )
{
struct V_37 * V_38 =
F_5 ( V_2 -> V_39 . V_40 -> V_41 ) ;
struct V_59 V_60 ;
if ( V_4 >= V_2 -> V_9 ) {
V_3 [ 2 ] = V_10 ;
return;
}
switch ( V_55 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
break;
default:
V_3 [ 2 ] = V_68 ;
return;
}
V_60 . V_16 = V_57 ;
V_60 . V_18 = V_58 ;
if ( V_38 -> V_43 -> V_69 ( V_2 -> V_5 [ V_4 ] , V_55 , & V_60 ) )
V_3 [ 2 ] = V_46 ;
else
V_3 [ 2 ] = V_11 ;
}
int F_8 ( struct V_70 * V_40 , struct V_71 * V_72 ,
struct V_71 * V_73 )
{
T_1 * V_36 = NULL , * V_3 = NULL , * V_74 ;
struct V_1 * V_2 = F_9 ( V_40 ) ;
int error = - V_75 ;
if ( F_10 ( V_72 ) < 8 || F_10 ( V_73 ) < 8 )
goto V_76;
if ( F_11 ( V_72 -> V_77 ) + F_10 ( V_72 ) > V_78 ||
F_11 ( V_73 -> V_77 ) + F_10 ( V_73 ) > V_78 ) {
F_12 ( V_79 , V_40 ,
L_1 ) ;
goto V_76;
}
V_36 = F_13 ( F_10 ( V_72 ) , V_80 ) ;
V_3 = F_13 ( V_58 ( F_10 ( V_73 ) , 128U ) , V_80 ) ;
if ( ! V_36 || ! V_3 ) {
error = - V_81 ;
goto V_76;
}
F_14 () ;
V_74 = F_15 ( F_16 ( V_72 -> V_77 ) , V_82 ) + F_11 ( V_72 -> V_77 ) ;
memcpy ( V_36 , V_74 , F_10 ( V_72 ) ) ;
F_17 ( V_74 - F_11 ( V_72 -> V_77 ) , V_82 ) ;
F_18 () ;
if ( V_36 [ 0 ] != V_83 )
goto V_76;
error = 0 ;
V_3 [ 0 ] = V_84 ;
V_3 [ 1 ] = V_36 [ 1 ] ;
V_3 [ 2 ] = V_45 ;
switch ( V_36 [ 1 ] ) {
case V_85 :
V_72 -> V_86 -= 8 ;
V_73 -> V_86 -= 32 ;
V_3 [ 2 ] = V_11 ;
V_3 [ 9 ] = V_2 -> V_9 ;
break;
case V_87 :
V_72 -> V_86 -= 8 ;
V_73 -> V_86 -= 64 ;
V_3 [ 2 ] = V_11 ;
memcpy ( V_3 + 12 , V_40 -> V_88 -> V_89 ,
V_90 ) ;
memcpy ( V_3 + 20 , L_2 ,
V_91 ) ;
break;
case V_92 :
break;
case V_93 :
V_72 -> V_86 -= 16 ;
if ( ( int ) V_72 -> V_86 < 0 ) {
V_72 -> V_86 = 0 ;
error = - V_75 ;
goto V_76;
}
V_73 -> V_86 -= 56 ;
F_1 ( V_2 , V_3 , V_36 [ 9 ] ) ;
break;
case V_94 :
break;
case V_95 :
V_72 -> V_86 -= 16 ;
if ( ( int ) V_72 -> V_86 < 0 ) {
V_72 -> V_86 = 0 ;
error = - V_75 ;
goto V_76;
}
V_73 -> V_86 -= 60 ;
F_6 ( V_2 , V_3 , V_36 [ 9 ] ) ;
break;
case V_96 :
break;
case V_97 : {
const int V_98 = 11 ;
int V_99 = V_36 [ 4 ] ;
if ( F_10 ( V_72 ) < V_98 + V_99 * 4 ||
V_72 -> V_86 < V_98 + V_99 * 4 ) {
V_3 [ 2 ] = V_100 ;
break;
}
V_99 = F_4 ( V_2 , V_3 , V_36 [ 2 ] ,
V_36 [ 3 ] , V_99 , & V_36 [ 8 ] ) ;
V_72 -> V_86 -= V_98 + V_99 * 4 ;
V_73 -> V_86 -= 8 ;
break;
}
case V_101 :
break;
case V_102 :
V_72 -> V_86 -= 44 ;
if ( ( int ) V_72 -> V_86 < 0 ) {
V_72 -> V_86 = 0 ;
error = - V_75 ;
goto V_76;
}
V_73 -> V_86 -= 8 ;
F_7 ( V_2 , V_36 [ 9 ] , V_36 [ 10 ] ,
V_36 [ 32 ] >> 4 , V_36 [ 33 ] >> 4 ,
V_3 ) ;
break;
case V_103 :
break;
default:
break;
}
F_14 () ;
V_74 = F_15 ( F_16 ( V_73 -> V_77 ) , V_82 ) + F_11 ( V_73 -> V_77 ) ;
memcpy ( V_74 , V_3 , F_10 ( V_73 ) ) ;
F_19 ( F_16 ( V_73 -> V_77 ) ) ;
F_17 ( V_74 - F_11 ( V_73 -> V_77 ) , V_82 ) ;
F_18 () ;
V_76:
F_20 ( V_36 ) ;
F_20 ( V_3 ) ;
return error ;
}
