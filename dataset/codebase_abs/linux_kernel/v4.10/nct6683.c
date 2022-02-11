static inline void
F_1 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static inline int
F_3 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_4 ( V_1 + 1 ) ;
}
static inline void
F_5 ( int V_1 , int V_4 )
{
F_2 ( V_5 , V_1 ) ;
F_2 ( V_4 , V_1 + 1 ) ;
}
static inline int
F_6 ( int V_1 )
{
if ( ! F_7 ( V_1 , 2 , V_6 ) )
return - V_7 ;
F_2 ( 0x87 , V_1 ) ;
F_2 ( 0x87 , V_1 ) ;
return 0 ;
}
static inline void
F_8 ( int V_1 )
{
F_2 ( 0xaa , V_1 ) ;
F_2 ( 0x02 , V_1 ) ;
F_2 ( 0x02 , V_1 + 1 ) ;
F_9 ( V_1 , 2 ) ;
}
static struct V_8 *
F_10 ( struct V_9 * V_10 ,
const struct V_11 * V_12 ,
int V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * * V_19 ;
struct V_20 * V_21 ;
struct V_8 * V_22 ;
struct V_23 * * V_24 ;
int V_25 , V_26 , V_27 ;
if ( V_13 <= 0 )
return F_11 ( - V_28 ) ;
V_19 = V_12 -> V_29 ;
for ( V_27 = 0 ; * V_19 ; V_19 ++ , V_27 ++ )
;
if ( V_27 == 0 )
return F_11 ( - V_28 ) ;
V_22 = F_12 ( V_10 , sizeof( * V_22 ) , V_30 ) ;
if ( V_22 == NULL )
return F_11 ( - V_31 ) ;
V_24 = F_12 ( V_10 , sizeof( * V_24 ) * ( V_13 * V_27 + 1 ) ,
V_30 ) ;
if ( V_24 == NULL )
return F_11 ( - V_31 ) ;
V_21 = F_12 ( V_10 , sizeof( * V_21 ) * V_13 * V_27 ,
V_30 ) ;
if ( V_21 == NULL )
return F_11 ( - V_31 ) ;
V_22 -> V_24 = V_24 ;
V_22 -> V_32 = V_12 -> V_32 ;
for ( V_25 = 0 ; V_25 < V_13 ; V_25 ++ ) {
V_19 = V_12 -> V_29 ;
for ( V_26 = 0 ; * V_19 != NULL ; V_26 ++ ) {
snprintf ( V_21 -> V_33 , sizeof( V_21 -> V_33 ) ,
( * V_19 ) -> V_34 . V_35 . V_33 , V_12 -> V_36 + V_25 ) ;
if ( ( * V_19 ) -> V_37 ) {
V_15 = & V_21 -> V_38 . V_15 ;
F_13 ( & V_15 -> V_34 . V_35 ) ;
V_15 -> V_34 . V_35 . V_33 = V_21 -> V_33 ;
V_15 -> V_39 = ( * V_19 ) -> V_38 . V_40 . V_39 + V_25 ;
V_15 -> V_41 = ( * V_19 ) -> V_38 . V_40 . V_41 ;
V_15 -> V_34 . V_35 . V_42 =
( * V_19 ) -> V_34 . V_35 . V_42 ;
V_15 -> V_34 . V_43 = ( * V_19 ) -> V_34 . V_43 ;
V_15 -> V_34 . V_44 = ( * V_19 ) -> V_34 . V_44 ;
* V_24 = & V_15 -> V_34 . V_35 ;
} else {
V_17 = & V_21 -> V_38 . V_45 ;
F_13 ( & V_17 -> V_34 . V_35 ) ;
V_17 -> V_34 . V_35 . V_33 = V_21 -> V_33 ;
V_17 -> V_41 = ( * V_19 ) -> V_38 . V_41 + V_25 ;
V_17 -> V_34 . V_35 . V_42 =
( * V_19 ) -> V_34 . V_35 . V_42 ;
V_17 -> V_34 . V_43 = ( * V_19 ) -> V_34 . V_43 ;
V_17 -> V_34 . V_44 = ( * V_19 ) -> V_34 . V_44 ;
* V_24 = & V_17 -> V_34 . V_35 ;
}
V_24 ++ ;
V_21 ++ ;
V_19 ++ ;
}
}
return V_22 ;
}
static inline long F_14 ( T_1 V_2 , T_2 V_46 )
{
int V_47 = 16 ;
if ( V_46 == V_48 || V_46 == V_49 || V_46 == V_50 ||
V_46 == V_51 )
V_47 <<= 1 ;
return V_2 * V_47 ;
}
static inline T_1 F_15 ( T_3 V_3 , T_2 V_46 )
{
int V_47 = 16 ;
if ( V_46 == V_48 || V_46 == V_49 || V_46 == V_50 ||
V_46 == V_51 )
V_47 <<= 1 ;
return F_16 ( F_17 ( V_3 , V_47 ) , 0 , 127 ) ;
}
static T_1 F_18 ( struct V_52 * V_53 , T_1 V_2 )
{
int V_54 ;
F_19 ( 0xff , V_53 -> V_55 + V_56 ) ;
F_19 ( V_2 >> 8 , V_53 -> V_55 + V_56 ) ;
F_19 ( V_2 & 0xff , V_53 -> V_55 + V_57 ) ;
V_54 = F_20 ( V_53 -> V_55 + V_58 ) ;
return V_54 ;
}
static T_1 F_21 ( struct V_52 * V_53 , T_1 V_2 )
{
return ( F_18 ( V_53 , V_2 ) << 8 ) | F_18 ( V_53 , V_2 + 1 ) ;
}
static void F_22 ( struct V_52 * V_53 , T_1 V_2 , T_1 V_59 )
{
F_19 ( 0xff , V_53 -> V_55 + V_56 ) ;
F_19 ( V_2 >> 8 , V_53 -> V_55 + V_56 ) ;
F_19 ( V_2 & 0xff , V_53 -> V_55 + V_57 ) ;
F_19 ( V_59 & 0xff , V_53 -> V_55 + V_58 ) ;
}
static int F_23 ( struct V_52 * V_53 , int V_39 , int V_41 )
{
int V_60 = V_53 -> V_61 [ V_41 ] ;
int V_2 = - V_28 ;
switch ( V_39 ) {
case 0 :
V_2 = F_24 ( V_60 ) ;
break;
case 1 :
if ( V_53 -> V_62 != V_63 )
V_2 = F_25 ( V_60 ) ;
break;
case 2 :
if ( V_53 -> V_62 != V_63 )
V_2 = F_26 ( V_60 ) ;
break;
default:
break;
}
return V_2 ;
}
static int F_27 ( struct V_52 * V_53 , int V_39 , int V_41 )
{
int V_60 = V_53 -> V_64 [ V_41 ] ;
int V_2 = - V_28 ;
switch ( V_53 -> V_62 ) {
case V_63 :
switch ( V_39 ) {
default:
case 1 :
V_2 = F_28 ( V_60 ) ;
break;
case 3 :
V_2 = F_29 ( V_60 ) ;
break;
}
break;
case V_65 :
default:
switch ( V_39 ) {
default:
case 0 :
V_2 = F_25 ( V_60 ) ;
break;
case 1 :
V_2 = F_30 ( V_60 ) ;
break;
case 2 :
V_2 = F_31 ( V_60 ) ;
break;
case 3 :
V_2 = F_26 ( V_60 ) ;
break;
}
break;
}
return V_2 ;
}
static void F_32 ( struct V_9 * V_10 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_66 ; V_25 ++ ) {
if ( ! ( V_53 -> V_67 & ( 1 << V_25 ) ) )
continue;
V_53 -> V_68 [ V_25 ] = F_18 ( V_53 , F_34 ( V_25 ) ) ;
}
}
static struct V_52 * F_35 ( struct V_9 * V_10 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_25 , V_26 ;
F_36 ( & V_53 -> V_69 ) ;
if ( F_37 ( V_70 , V_53 -> V_71 + V_72 ) || ! V_53 -> V_73 ) {
for ( V_25 = 0 ; V_25 < V_53 -> V_74 ; V_25 ++ ) {
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
int V_2 = F_23 ( V_53 , V_26 , V_25 ) ;
if ( V_2 >= 0 )
V_53 -> V_75 [ V_26 ] [ V_25 ] =
F_18 ( V_53 , V_2 ) ;
}
}
for ( V_25 = 0 ; V_25 < V_53 -> V_76 ; V_25 ++ ) {
T_2 V_60 = V_53 -> V_64 [ V_25 ] ;
V_53 -> V_77 [ V_25 ] = F_21 ( V_53 ,
F_24 ( V_60 ) ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
int V_2 = F_27 ( V_53 , V_26 , V_25 ) ;
if ( V_2 >= 0 )
V_53 -> V_78 [ V_26 ] [ V_25 ] =
F_18 ( V_53 , V_2 ) ;
}
}
for ( V_25 = 0 ; V_25 < F_38 ( V_53 -> V_79 ) ; V_25 ++ ) {
if ( ! ( V_53 -> V_80 & ( 1 << V_25 ) ) )
continue;
V_53 -> V_79 [ V_25 ] = F_21 ( V_53 ,
F_39 ( V_25 ) ) ;
V_53 -> V_81 [ V_25 ] = F_21 ( V_53 ,
F_40 ( V_25 ) ) ;
}
F_32 ( V_10 ) ;
V_53 -> V_71 = V_70 ;
V_53 -> V_73 = true ;
}
F_41 ( & V_53 -> V_69 ) ;
return V_53 ;
}
static T_4
F_42 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_16 * V_84 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_39 = V_84 -> V_41 ;
return sprintf ( V_83 , L_1 , V_85 [ V_53 -> V_86 [ V_39 ] ] ) ;
}
static T_4
F_44 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_14 * V_84 = F_45 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_41 = V_84 -> V_41 ;
int V_39 = V_84 -> V_39 ;
return sprintf ( V_83 , L_2 ,
F_14 ( V_53 -> V_75 [ V_41 ] [ V_39 ] , V_53 -> V_61 [ V_41 ] ) ) ;
}
static T_5 F_46 ( struct V_87 * V_88 ,
struct V_23 * V_35 , int V_41 )
{
struct V_9 * V_10 = F_47 ( V_88 , struct V_9 , V_88 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_39 = V_41 % 4 ;
if ( ( V_39 == 2 || V_39 == 3 ) &&
V_53 -> V_62 == V_63 )
return 0 ;
return V_35 -> V_42 ;
}
static T_4
F_48 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_16 * V_84 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
return sprintf ( V_83 , L_3 , V_53 -> V_79 [ V_84 -> V_41 ] ) ;
}
static T_4
F_49 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_52 * V_53 = F_35 ( V_10 ) ;
struct V_16 * V_84 = F_43 ( V_35 ) ;
int V_39 = V_84 -> V_41 ;
return sprintf ( V_83 , L_3 , V_53 -> V_81 [ V_39 ] ) ;
}
static T_4
F_50 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_16 * V_84 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
return sprintf ( V_83 , L_3 ,
( ( V_53 -> V_89 [ V_84 -> V_41 ] >> 5 ) & 0x03 ) + 1 ) ;
}
static T_5 F_51 ( struct V_87 * V_88 ,
struct V_23 * V_35 , int V_41 )
{
struct V_9 * V_10 = F_47 ( V_88 , struct V_9 , V_88 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_90 = V_41 / 3 ;
int V_39 = V_41 % 3 ;
if ( ! ( V_53 -> V_80 & ( 1 << V_90 ) ) )
return 0 ;
if ( V_39 == 2 && V_53 -> V_62 == V_63 )
return 0 ;
return V_35 -> V_42 ;
}
static T_4
F_52 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_16 * V_84 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_39 = V_84 -> V_41 ;
return sprintf ( V_83 , L_1 , V_85 [ V_53 -> V_91 [ V_39 ] ] ) ;
}
static T_4
F_53 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_14 * V_84 = F_45 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_41 = V_84 -> V_41 ;
int V_39 = V_84 -> V_39 ;
return sprintf ( V_83 , L_3 , V_53 -> V_78 [ V_41 ] [ V_39 ] * 1000 ) ;
}
static T_4
F_54 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_16 * V_84 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_39 = V_84 -> V_41 ;
int V_78 = V_53 -> V_78 [ 1 ] [ V_39 ] - V_53 -> V_78 [ 2 ] [ V_39 ] ;
return sprintf ( V_83 , L_3 , V_78 * 1000 ) ;
}
static T_4
F_55 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_16 * V_84 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_41 = V_84 -> V_41 ;
return sprintf ( V_83 , L_3 , ( V_53 -> V_77 [ V_41 ] / 128 ) * 500 ) ;
}
static int F_56 ( T_2 V_46 )
{
if ( V_46 >= 0x02 && V_46 <= 0x07 )
return 3 ;
else if ( V_46 >= 0x08 && V_46 <= 0x18 )
return 4 ;
else if ( V_46 >= 0x20 && V_46 <= 0x2b )
return 6 ;
else if ( V_46 >= 0x42 && V_46 <= 0x49 )
return 5 ;
return 0 ;
}
static T_4
F_57 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_52 * V_53 = F_35 ( V_10 ) ;
struct V_16 * V_84 = F_43 ( V_35 ) ;
int V_39 = V_84 -> V_41 ;
return sprintf ( V_83 , L_3 , F_56 ( V_53 -> V_91 [ V_39 ] ) ) ;
}
static T_5 F_58 ( struct V_87 * V_88 ,
struct V_23 * V_35 , int V_41 )
{
struct V_9 * V_10 = F_47 ( V_88 , struct V_9 , V_88 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_78 = V_41 / 7 ;
int V_39 = V_41 % 7 ;
if ( ( V_39 == 2 || V_39 == 4 ) &&
V_53 -> V_62 == V_63 )
return 0 ;
if ( V_39 == 6 && F_56 ( V_53 -> V_91 [ V_78 ] ) == 0 )
return 0 ;
return V_35 -> V_42 ;
}
static T_4
F_59 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_52 * V_53 = F_35 ( V_10 ) ;
struct V_14 * V_84 = F_45 ( V_35 ) ;
int V_41 = V_84 -> V_41 ;
return sprintf ( V_83 , L_3 , V_53 -> V_68 [ V_41 ] ) ;
}
static T_4
F_60 ( struct V_9 * V_10 , struct V_82 * V_35 , const char * V_83 ,
T_6 V_27 )
{
struct V_14 * V_84 = F_45 ( V_35 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_41 = V_84 -> V_41 ;
unsigned long V_3 ;
if ( F_61 ( V_83 , 10 , & V_3 ) || V_3 > 255 )
return - V_28 ;
F_36 ( & V_53 -> V_69 ) ;
F_22 ( V_53 , V_92 , V_93 ) ;
F_62 ( 1000 , 2000 ) ;
F_22 ( V_53 , F_63 ( V_41 ) , V_3 ) ;
F_22 ( V_53 , V_92 , V_94 ) ;
F_41 ( & V_53 -> V_69 ) ;
return V_27 ;
}
static T_5 F_64 ( struct V_87 * V_88 ,
struct V_23 * V_35 , int V_41 )
{
struct V_9 * V_10 = F_47 ( V_88 , struct V_9 , V_88 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_68 = V_41 ;
if ( ! ( V_53 -> V_67 & ( 1 << V_68 ) ) )
return 0 ;
if ( V_53 -> V_62 == V_65 )
return V_35 -> V_42 | V_95 ;
return V_35 -> V_42 ;
}
static T_4
F_65 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_96 ;
T_2 V_2 ;
F_36 ( & V_53 -> V_69 ) ;
V_96 = F_6 ( V_53 -> V_97 ) ;
if ( V_96 )
goto error;
F_5 ( V_53 -> V_97 , V_98 ) ;
V_2 = F_3 ( V_53 -> V_97 , V_99 ) ;
F_8 ( V_53 -> V_97 ) ;
F_41 ( & V_53 -> V_69 ) ;
return sprintf ( V_83 , L_4 , ! ! ( V_2 & V_100 ) ) ;
error:
F_41 ( & V_53 -> V_69 ) ;
return V_96 ;
}
static T_4
F_66 ( struct V_9 * V_10 , struct V_82 * V_35 ,
const char * V_83 , T_6 V_27 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
unsigned long V_3 ;
T_2 V_2 ;
int V_96 ;
if ( F_61 ( V_83 , 10 , & V_3 ) || ( V_3 != 0 && V_3 != 1 ) )
return - V_28 ;
F_36 ( & V_53 -> V_69 ) ;
V_96 = F_6 ( V_53 -> V_97 ) ;
if ( V_96 ) {
V_27 = V_96 ;
goto error;
}
F_5 ( V_53 -> V_97 , V_98 ) ;
V_2 = F_3 ( V_53 -> V_97 , V_99 ) ;
if ( V_3 )
V_2 |= V_100 ;
else
V_2 &= ~ V_100 ;
F_1 ( V_53 -> V_97 , V_99 , V_2 ) ;
F_8 ( V_53 -> V_97 ) ;
error:
F_41 ( & V_53 -> V_69 ) ;
return V_27 ;
}
static T_4
F_67 ( struct V_9 * V_10 , struct V_82 * V_35 , char * V_83 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_96 ;
T_2 V_2 ;
F_36 ( & V_53 -> V_69 ) ;
V_96 = F_6 ( V_53 -> V_97 ) ;
if ( V_96 )
goto error;
F_5 ( V_53 -> V_97 , V_101 ) ;
V_2 = F_3 ( V_53 -> V_97 , V_102 ) ;
F_8 ( V_53 -> V_97 ) ;
F_41 ( & V_53 -> V_69 ) ;
return sprintf ( V_83 , L_4 , ! ( V_2 & V_103 ) ) ;
error:
F_41 ( & V_53 -> V_69 ) ;
return V_96 ;
}
static T_4
F_68 ( struct V_9 * V_10 , struct V_82 * V_35 ,
const char * V_83 , T_6 V_27 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
unsigned long V_3 ;
T_2 V_2 ;
int V_96 ;
if ( F_61 ( V_83 , 10 , & V_3 ) || V_3 != 0 )
return - V_28 ;
F_36 ( & V_53 -> V_69 ) ;
V_96 = F_6 ( V_53 -> V_97 ) ;
if ( V_96 ) {
V_27 = V_96 ;
goto error;
}
F_5 ( V_53 -> V_97 , V_101 ) ;
V_2 = F_3 ( V_53 -> V_97 , V_102 ) ;
V_2 |= V_103 ;
F_1 ( V_53 -> V_97 , V_102 , V_2 ) ;
V_2 &= ~ V_103 ;
F_1 ( V_53 -> V_97 , V_102 , V_2 ) ;
F_8 ( V_53 -> V_97 ) ;
V_53 -> V_73 = false ;
error:
F_41 ( & V_53 -> V_69 ) ;
return V_27 ;
}
static inline void F_69 ( struct V_52 * V_53 )
{
T_2 V_104 ;
V_104 = F_18 ( V_53 , V_105 ) ;
if ( ! ( V_104 & 0x80 ) )
F_22 ( V_53 , V_105 , V_104 | 0x80 ) ;
}
static void
F_70 ( struct V_52 * V_53 )
{
int V_25 ;
T_2 V_2 ;
for ( V_25 = 0 ; V_25 < V_106 ; V_25 ++ ) {
V_2 = F_18 ( V_53 , F_71 ( V_25 ) ) ;
if ( V_2 & 0x80 )
V_53 -> V_80 |= 1 << V_25 ;
V_53 -> V_89 [ V_25 ] = V_2 ;
}
for ( V_25 = 0 ; V_25 < V_66 ; V_25 ++ ) {
V_2 = F_18 ( V_53 , F_72 ( V_25 ) ) ;
if ( V_2 & 0x80 )
V_53 -> V_67 |= 1 << V_25 ;
V_53 -> V_107 [ V_25 ] = V_2 ;
}
}
static void F_73 ( struct V_52 * V_53 )
{
T_2 V_2 ;
int V_25 ;
V_53 -> V_76 = 0 ;
V_53 -> V_74 = 0 ;
for ( V_25 = 0 ; V_25 < V_108 ; V_25 ++ ) {
V_2 = F_18 ( V_53 , F_74 ( V_25 ) ) & 0x7f ;
if ( V_2 >= V_109 )
continue;
if ( V_85 [ V_2 ] == NULL )
continue;
if ( V_2 < V_110 ) {
V_53 -> V_64 [ V_53 -> V_76 ] = V_25 ;
V_53 -> V_91 [ V_53 -> V_76 ] = V_2 ;
V_53 -> V_76 ++ ;
} else {
V_53 -> V_61 [ V_53 -> V_74 ] = V_25 ;
V_53 -> V_86 [ V_53 -> V_74 ] = V_2 ;
V_53 -> V_74 ++ ;
}
}
}
static int F_75 ( struct V_111 * V_112 )
{
struct V_9 * V_10 = & V_112 -> V_10 ;
struct V_113 * V_114 = V_10 -> V_115 ;
struct V_8 * V_22 ;
struct V_52 * V_53 ;
struct V_9 * V_116 ;
struct V_117 * V_54 ;
int V_118 = 0 ;
char V_119 [ 16 ] ;
V_54 = F_76 ( V_112 , V_120 , 0 ) ;
if ( ! F_77 ( V_10 , V_54 -> V_121 , V_122 , V_6 ) )
return - V_7 ;
V_53 = F_12 ( V_10 , sizeof( struct V_52 ) , V_30 ) ;
if ( ! V_53 )
return - V_31 ;
V_53 -> V_123 = V_114 -> V_123 ;
V_53 -> V_97 = V_114 -> V_97 ;
V_53 -> V_55 = V_54 -> V_121 ;
F_78 ( & V_53 -> V_69 ) ;
F_79 ( V_112 , V_53 ) ;
V_53 -> V_62 = F_21 ( V_53 , V_124 ) ;
switch ( V_53 -> V_62 ) {
case V_63 :
break;
case V_65 :
break;
default:
if ( ! V_125 )
return - V_126 ;
}
F_69 ( V_53 ) ;
F_70 ( V_53 ) ;
F_73 ( V_53 ) ;
if ( V_53 -> V_67 ) {
V_22 = F_10 ( V_10 ,
& V_127 ,
F_80 ( V_53 -> V_67 ) ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
V_53 -> V_118 [ V_118 ++ ] = V_22 ;
}
if ( V_53 -> V_74 ) {
V_22 = F_10 ( V_10 ,
& V_128 ,
V_53 -> V_74 ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
V_53 -> V_118 [ V_118 ++ ] = V_22 ;
}
if ( V_53 -> V_80 ) {
V_22 = F_10 ( V_10 ,
& V_129 ,
F_80 ( V_53 -> V_80 ) ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
V_53 -> V_118 [ V_118 ++ ] = V_22 ;
}
if ( V_53 -> V_76 ) {
V_22 = F_10 ( V_10 ,
& V_130 ,
V_53 -> V_76 ) ;
if ( F_81 ( V_22 ) )
return F_82 ( V_22 ) ;
V_53 -> V_118 [ V_118 ++ ] = V_22 ;
}
V_53 -> V_118 [ V_118 ++ ] = & V_131 ;
if ( V_53 -> V_62 == V_63 )
F_83 ( V_119 , sizeof( V_119 ) , L_5 ,
F_18 ( V_53 , V_132 ) ,
F_18 ( V_53 , V_133 ) ,
F_18 ( V_53 , V_134 ) ) ;
else
F_83 ( V_119 , sizeof( V_119 ) , L_6 ,
F_18 ( V_53 , V_132 ) ,
F_18 ( V_53 , V_133 ) ,
F_18 ( V_53 , V_134 ) ) ;
F_84 ( V_10 , L_7 ,
V_135 [ V_53 -> V_123 ] ,
F_18 ( V_53 , V_136 ) ,
F_18 ( V_53 , V_137 ) ,
V_119 ) ;
V_116 = F_85 ( V_10 ,
V_138 [ V_53 -> V_123 ] , V_53 , V_53 -> V_118 ) ;
return F_86 ( V_116 ) ;
}
static int F_87 ( struct V_9 * V_10 )
{
struct V_52 * V_53 = F_35 ( V_10 ) ;
F_36 ( & V_53 -> V_69 ) ;
V_53 -> V_139 = F_18 ( V_53 , V_105 ) ;
F_41 ( & V_53 -> V_69 ) ;
return 0 ;
}
static int F_88 ( struct V_9 * V_10 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
F_36 ( & V_53 -> V_69 ) ;
F_22 ( V_53 , V_105 , V_53 -> V_139 ) ;
V_53 -> V_73 = false ;
F_41 ( & V_53 -> V_69 ) ;
return 0 ;
}
static int T_7 F_89 ( int V_140 , struct V_113 * V_114 )
{
int V_55 ;
T_1 V_3 ;
int V_141 ;
V_141 = F_6 ( V_140 ) ;
if ( V_141 )
return V_141 ;
V_3 = ( F_3 ( V_140 , V_142 ) << 8 )
| F_3 ( V_140 , V_142 + 1 ) ;
switch ( V_3 & V_143 ) {
case V_144 :
V_114 -> V_123 = V_145 ;
break;
default:
if ( V_3 != 0xffff )
F_90 ( L_8 , V_3 ) ;
goto V_146;
}
F_5 ( V_140 , V_98 ) ;
V_3 = ( F_3 ( V_140 , V_147 ) << 8 )
| F_3 ( V_140 , V_147 + 1 ) ;
V_55 = V_3 & V_148 ;
if ( V_55 == 0 ) {
F_91 ( L_9 ) ;
goto V_146;
}
V_3 = F_3 ( V_140 , V_149 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_91 ( L_10 ) ;
goto V_146;
}
F_8 ( V_140 ) ;
F_92 ( L_11 ,
V_135 [ V_114 -> V_123 ] , V_140 , V_55 ) ;
V_114 -> V_97 = V_140 ;
return V_55 ;
V_146:
F_8 ( V_140 ) ;
return - V_126 ;
}
static int T_7 F_93 ( void )
{
struct V_113 V_114 ;
int V_140 [ 2 ] = { 0x2e , 0x4e } ;
struct V_117 V_54 ;
bool V_150 = false ;
int V_151 ;
int V_25 , V_141 ;
V_141 = F_94 ( & V_152 ) ;
if ( V_141 )
return V_141 ;
for ( V_25 = 0 ; V_25 < F_38 ( V_112 ) ; V_25 ++ ) {
V_151 = F_89 ( V_140 [ V_25 ] , & V_114 ) ;
if ( V_151 <= 0 )
continue;
V_150 = true ;
V_112 [ V_25 ] = F_95 ( V_6 , V_151 ) ;
if ( ! V_112 [ V_25 ] ) {
V_141 = - V_31 ;
goto V_153;
}
V_141 = F_96 ( V_112 [ V_25 ] , & V_114 ,
sizeof( struct V_113 ) ) ;
if ( V_141 )
goto V_154;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_33 = V_6 ;
V_54 . V_121 = V_151 + V_155 ;
V_54 . V_156 = V_151 + V_155 + V_122 - 1 ;
V_54 . V_157 = V_120 ;
V_141 = F_97 ( & V_54 ) ;
if ( V_141 ) {
F_98 ( V_112 [ V_25 ] ) ;
V_112 [ V_25 ] = NULL ;
continue;
}
V_141 = F_99 ( V_112 [ V_25 ] , & V_54 , 1 ) ;
if ( V_141 )
goto V_154;
V_141 = F_100 ( V_112 [ V_25 ] ) ;
if ( V_141 )
goto V_154;
}
if ( ! V_150 ) {
V_141 = - V_126 ;
goto V_158;
}
return 0 ;
V_154:
F_98 ( V_112 [ V_25 ] ) ;
V_153:
while ( -- V_25 >= 0 ) {
if ( V_112 [ V_25 ] )
F_101 ( V_112 [ V_25 ] ) ;
}
V_158:
F_102 ( & V_152 ) ;
return V_141 ;
}
static void T_8 F_103 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_38 ( V_112 ) ; V_25 ++ ) {
if ( V_112 [ V_25 ] )
F_101 ( V_112 [ V_25 ] ) ;
}
F_102 ( & V_152 ) ;
}
