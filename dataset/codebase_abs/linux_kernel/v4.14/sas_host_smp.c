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
struct V_61 * V_62 ;
if ( V_4 >= V_2 -> V_9 ) {
V_3 [ 2 ] = V_10 ;
return;
}
V_62 = V_2 -> V_5 [ V_4 ] ;
switch ( V_55 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
break;
default:
V_3 [ 2 ] = V_70 ;
return;
}
V_60 . V_16 = V_57 ;
V_60 . V_18 = V_58 ;
if ( V_55 == V_64 && F_8 ( V_62 ) == 0 ) {
V_3 [ 2 ] = V_11 ;
return;
}
if ( V_38 -> V_43 -> V_71 ( V_62 , V_55 , & V_60 ) )
V_3 [ 2 ] = V_46 ;
else
V_3 [ 2 ] = V_11 ;
}
void F_9 ( struct V_72 * V_73 , struct V_74 * V_40 )
{
struct V_1 * V_2 = F_10 ( V_40 ) ;
T_1 * V_36 , * V_3 ;
unsigned int V_75 = 0 ;
int error = - V_76 ;
if ( V_73 -> V_77 . V_78 < 8 ||
V_73 -> V_79 . V_78 < 8 )
goto V_80;
error = - V_81 ;
V_36 = F_11 ( V_73 -> V_77 . V_78 , V_82 ) ;
if ( ! V_36 )
goto V_80;
F_12 ( V_73 -> V_77 . V_83 ,
V_73 -> V_77 . V_84 , V_36 ,
V_73 -> V_77 . V_78 ) ;
V_3 = F_11 ( V_58 ( V_73 -> V_79 . V_78 , 128U ) ,
V_82 ) ;
if ( ! V_3 )
goto V_85;
error = - V_76 ;
if ( V_36 [ 0 ] != V_86 )
goto V_87;
V_3 [ 0 ] = V_88 ;
V_3 [ 1 ] = V_36 [ 1 ] ;
V_3 [ 2 ] = V_45 ;
switch ( V_36 [ 1 ] ) {
case V_89 :
V_3 [ 2 ] = V_11 ;
V_3 [ 9 ] = V_2 -> V_9 ;
V_75 = 32 ;
break;
case V_90 :
V_3 [ 2 ] = V_11 ;
memcpy ( V_3 + 12 , V_40 -> V_91 -> V_92 ,
V_93 ) ;
memcpy ( V_3 + 20 , L_1 ,
V_94 ) ;
V_75 = 64 ;
break;
case V_95 :
break;
case V_96 :
if ( V_73 -> V_77 . V_78 < 16 )
goto V_87;
F_1 ( V_2 , V_3 , V_36 [ 9 ] ) ;
V_75 = 56 ;
break;
case V_97 :
break;
case V_98 :
if ( V_73 -> V_77 . V_78 < 16 )
goto V_87;
F_6 ( V_2 , V_3 , V_36 [ 9 ] ) ;
V_75 = 60 ;
break;
case V_99 :
break;
case V_100 : {
const int V_101 = 11 ;
int V_102 = V_36 [ 4 ] ;
if ( V_73 -> V_77 . V_78 <
V_101 + V_102 * 4 ) {
V_3 [ 2 ] = V_103 ;
break;
}
V_102 = F_4 ( V_2 , V_3 , V_36 [ 2 ] ,
V_36 [ 3 ] , V_102 , & V_36 [ 8 ] ) ;
V_75 = 8 ;
break;
}
case V_104 :
break;
case V_105 :
if ( V_73 -> V_77 . V_78 < 44 )
goto V_87;
F_7 ( V_2 , V_36 [ 9 ] , V_36 [ 10 ] ,
V_36 [ 32 ] >> 4 , V_36 [ 33 ] >> 4 ,
V_3 ) ;
V_75 = 8 ;
break;
case V_106 :
break;
default:
break;
}
F_13 ( V_73 -> V_79 . V_83 ,
V_73 -> V_79 . V_84 , V_3 ,
V_73 -> V_79 . V_78 ) ;
error = 0 ;
V_87:
F_14 ( V_3 ) ;
V_85:
F_14 ( V_36 ) ;
V_80:
F_15 ( V_73 , error , V_75 ) ;
}
