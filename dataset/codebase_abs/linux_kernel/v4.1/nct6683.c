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
F_10 ( struct V_9 * V_10 , struct V_11 * V_12 ,
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
for ( V_25 = 0 ; V_25 < V_65 ; V_25 ++ ) {
if ( ! ( V_53 -> V_66 & ( 1 << V_25 ) ) )
continue;
V_53 -> V_67 [ V_25 ] = F_18 ( V_53 , F_34 ( V_25 ) ) ;
}
}
static struct V_52 * F_35 ( struct V_9 * V_10 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_25 , V_26 ;
F_36 ( & V_53 -> V_68 ) ;
if ( F_37 ( V_69 , V_53 -> V_70 + V_71 ) || ! V_53 -> V_72 ) {
for ( V_25 = 0 ; V_25 < V_53 -> V_73 ; V_25 ++ ) {
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
int V_2 = F_23 ( V_53 , V_26 , V_25 ) ;
if ( V_2 >= 0 )
V_53 -> V_74 [ V_26 ] [ V_25 ] =
F_18 ( V_53 , V_2 ) ;
}
}
for ( V_25 = 0 ; V_25 < V_53 -> V_75 ; V_25 ++ ) {
T_2 V_60 = V_53 -> V_64 [ V_25 ] ;
V_53 -> V_76 [ V_25 ] = F_21 ( V_53 ,
F_24 ( V_60 ) ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
int V_2 = F_27 ( V_53 , V_26 , V_25 ) ;
if ( V_2 >= 0 )
V_53 -> V_77 [ V_26 ] [ V_25 ] =
F_18 ( V_53 , V_2 ) ;
}
}
for ( V_25 = 0 ; V_25 < F_38 ( V_53 -> V_78 ) ; V_25 ++ ) {
if ( ! ( V_53 -> V_79 & ( 1 << V_25 ) ) )
continue;
V_53 -> V_78 [ V_25 ] = F_21 ( V_53 ,
F_39 ( V_25 ) ) ;
V_53 -> V_80 [ V_25 ] = F_21 ( V_53 ,
F_40 ( V_25 ) ) ;
}
F_32 ( V_10 ) ;
V_53 -> V_70 = V_69 ;
V_53 -> V_72 = true ;
}
F_41 ( & V_53 -> V_68 ) ;
return V_53 ;
}
static T_4
F_42 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_16 * V_83 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_39 = V_83 -> V_41 ;
return sprintf ( V_82 , L_1 , V_84 [ V_53 -> V_85 [ V_39 ] ] ) ;
}
static T_4
F_44 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_14 * V_83 = F_45 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_41 = V_83 -> V_41 ;
int V_39 = V_83 -> V_39 ;
return sprintf ( V_82 , L_2 ,
F_14 ( V_53 -> V_74 [ V_41 ] [ V_39 ] , V_53 -> V_61 [ V_41 ] ) ) ;
}
static T_5 F_46 ( struct V_86 * V_87 ,
struct V_23 * V_35 , int V_41 )
{
struct V_9 * V_10 = F_47 ( V_87 , struct V_9 , V_87 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_39 = V_41 % 4 ;
if ( ( V_39 == 2 || V_39 == 3 ) &&
V_53 -> V_62 == V_63 )
return 0 ;
return V_35 -> V_42 ;
}
static T_4
F_48 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_16 * V_83 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
return sprintf ( V_82 , L_3 , V_53 -> V_78 [ V_83 -> V_41 ] ) ;
}
static T_4
F_49 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_52 * V_53 = F_35 ( V_10 ) ;
struct V_16 * V_83 = F_43 ( V_35 ) ;
int V_39 = V_83 -> V_41 ;
return sprintf ( V_82 , L_3 , V_53 -> V_80 [ V_39 ] ) ;
}
static T_4
F_50 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_16 * V_83 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
return sprintf ( V_82 , L_3 ,
( ( V_53 -> V_88 [ V_83 -> V_41 ] >> 5 ) & 0x03 ) + 1 ) ;
}
static T_5 F_51 ( struct V_86 * V_87 ,
struct V_23 * V_35 , int V_41 )
{
struct V_9 * V_10 = F_47 ( V_87 , struct V_9 , V_87 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_89 = V_41 / 3 ;
int V_39 = V_41 % 3 ;
if ( ! ( V_53 -> V_79 & ( 1 << V_89 ) ) )
return 0 ;
if ( V_39 == 2 && V_53 -> V_62 == V_63 )
return 0 ;
return V_35 -> V_42 ;
}
static T_4
F_52 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_16 * V_83 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_39 = V_83 -> V_41 ;
return sprintf ( V_82 , L_1 , V_84 [ V_53 -> V_90 [ V_39 ] ] ) ;
}
static T_4
F_53 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_14 * V_83 = F_45 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_41 = V_83 -> V_41 ;
int V_39 = V_83 -> V_39 ;
return sprintf ( V_82 , L_3 , V_53 -> V_77 [ V_41 ] [ V_39 ] * 1000 ) ;
}
static T_4
F_54 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_16 * V_83 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_39 = V_83 -> V_41 ;
int V_77 = V_53 -> V_77 [ 1 ] [ V_39 ] - V_53 -> V_77 [ 2 ] [ V_39 ] ;
return sprintf ( V_82 , L_3 , V_77 * 1000 ) ;
}
static T_4
F_55 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_16 * V_83 = F_43 ( V_35 ) ;
struct V_52 * V_53 = F_35 ( V_10 ) ;
int V_41 = V_83 -> V_41 ;
return sprintf ( V_82 , L_3 , ( V_53 -> V_76 [ V_41 ] / 128 ) * 500 ) ;
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
F_57 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_52 * V_53 = F_35 ( V_10 ) ;
struct V_16 * V_83 = F_43 ( V_35 ) ;
int V_39 = V_83 -> V_41 ;
return sprintf ( V_82 , L_3 , F_56 ( V_53 -> V_90 [ V_39 ] ) ) ;
}
static T_5 F_58 ( struct V_86 * V_87 ,
struct V_23 * V_35 , int V_41 )
{
struct V_9 * V_10 = F_47 ( V_87 , struct V_9 , V_87 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_77 = V_41 / 7 ;
int V_39 = V_41 % 7 ;
if ( ( V_39 == 2 || V_39 == 4 ) &&
V_53 -> V_62 == V_63 )
return 0 ;
if ( V_39 == 6 && F_56 ( V_53 -> V_90 [ V_77 ] ) == 0 )
return 0 ;
return V_35 -> V_42 ;
}
static T_4
F_59 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_52 * V_53 = F_35 ( V_10 ) ;
struct V_14 * V_83 = F_45 ( V_35 ) ;
int V_41 = V_83 -> V_41 ;
return sprintf ( V_82 , L_3 , V_53 -> V_67 [ V_41 ] ) ;
}
static T_5 F_60 ( struct V_86 * V_87 ,
struct V_23 * V_35 , int V_41 )
{
struct V_9 * V_10 = F_47 ( V_87 , struct V_9 , V_87 ) ;
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_67 = V_41 ;
if ( ! ( V_53 -> V_66 & ( 1 << V_67 ) ) )
return 0 ;
return V_35 -> V_42 ;
}
static T_4
F_61 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_91 ;
T_2 V_2 ;
F_36 ( & V_53 -> V_68 ) ;
V_91 = F_6 ( V_53 -> V_92 ) ;
if ( V_91 )
goto error;
F_5 ( V_53 -> V_92 , V_93 ) ;
V_2 = F_3 ( V_53 -> V_92 , V_94 ) ;
F_8 ( V_53 -> V_92 ) ;
F_41 ( & V_53 -> V_68 ) ;
return sprintf ( V_82 , L_4 , ! ! ( V_2 & V_95 ) ) ;
error:
F_41 ( & V_53 -> V_68 ) ;
return V_91 ;
}
static T_4
F_62 ( struct V_9 * V_10 , struct V_81 * V_35 ,
const char * V_82 , T_6 V_27 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
unsigned long V_3 ;
T_2 V_2 ;
int V_91 ;
if ( F_63 ( V_82 , 10 , & V_3 ) || ( V_3 != 0 && V_3 != 1 ) )
return - V_28 ;
F_36 ( & V_53 -> V_68 ) ;
V_91 = F_6 ( V_53 -> V_92 ) ;
if ( V_91 ) {
V_27 = V_91 ;
goto error;
}
F_5 ( V_53 -> V_92 , V_93 ) ;
V_2 = F_3 ( V_53 -> V_92 , V_94 ) ;
if ( V_3 )
V_2 |= V_95 ;
else
V_2 &= ~ V_95 ;
F_1 ( V_53 -> V_92 , V_94 , V_2 ) ;
F_8 ( V_53 -> V_92 ) ;
error:
F_41 ( & V_53 -> V_68 ) ;
return V_27 ;
}
static T_4
F_64 ( struct V_9 * V_10 , struct V_81 * V_35 , char * V_82 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
int V_91 ;
T_2 V_2 ;
F_36 ( & V_53 -> V_68 ) ;
V_91 = F_6 ( V_53 -> V_92 ) ;
if ( V_91 )
goto error;
F_5 ( V_53 -> V_92 , V_96 ) ;
V_2 = F_3 ( V_53 -> V_92 , V_97 ) ;
F_8 ( V_53 -> V_92 ) ;
F_41 ( & V_53 -> V_68 ) ;
return sprintf ( V_82 , L_4 , ! ( V_2 & V_98 ) ) ;
error:
F_41 ( & V_53 -> V_68 ) ;
return V_91 ;
}
static T_4
F_65 ( struct V_9 * V_10 , struct V_81 * V_35 ,
const char * V_82 , T_6 V_27 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
unsigned long V_3 ;
T_2 V_2 ;
int V_91 ;
if ( F_63 ( V_82 , 10 , & V_3 ) || V_3 != 0 )
return - V_28 ;
F_36 ( & V_53 -> V_68 ) ;
V_91 = F_6 ( V_53 -> V_92 ) ;
if ( V_91 ) {
V_27 = V_91 ;
goto error;
}
F_5 ( V_53 -> V_92 , V_96 ) ;
V_2 = F_3 ( V_53 -> V_92 , V_97 ) ;
V_2 |= V_98 ;
F_1 ( V_53 -> V_92 , V_97 , V_2 ) ;
V_2 &= ~ V_98 ;
F_1 ( V_53 -> V_92 , V_97 , V_2 ) ;
F_8 ( V_53 -> V_92 ) ;
V_53 -> V_72 = false ;
error:
F_41 ( & V_53 -> V_68 ) ;
return V_27 ;
}
static inline void F_66 ( struct V_52 * V_53 )
{
T_2 V_99 ;
V_99 = F_18 ( V_53 , V_100 ) ;
if ( ! ( V_99 & 0x80 ) )
F_22 ( V_53 , V_100 , V_99 | 0x80 ) ;
}
static void
F_67 ( struct V_52 * V_53 )
{
int V_25 ;
T_2 V_2 ;
for ( V_25 = 0 ; V_25 < V_101 ; V_25 ++ ) {
V_2 = F_18 ( V_53 , F_68 ( V_25 ) ) ;
if ( V_2 & 0x80 )
V_53 -> V_79 |= 1 << V_25 ;
V_53 -> V_88 [ V_25 ] = V_2 ;
}
for ( V_25 = 0 ; V_25 < V_65 ; V_25 ++ ) {
V_2 = F_18 ( V_53 , F_69 ( V_25 ) ) ;
if ( V_2 & 0x80 )
V_53 -> V_66 |= 1 << V_25 ;
V_53 -> V_102 [ V_25 ] = V_2 ;
}
}
static void F_70 ( struct V_52 * V_53 )
{
T_2 V_2 ;
int V_25 ;
V_53 -> V_75 = 0 ;
V_53 -> V_73 = 0 ;
for ( V_25 = 0 ; V_25 < V_103 ; V_25 ++ ) {
V_2 = F_18 ( V_53 , F_71 ( V_25 ) ) & 0x7f ;
if ( V_2 >= V_104 )
continue;
if ( V_84 [ V_2 ] == NULL )
continue;
if ( V_2 < V_105 ) {
V_53 -> V_64 [ V_53 -> V_75 ] = V_25 ;
V_53 -> V_90 [ V_53 -> V_75 ] = V_2 ;
V_53 -> V_75 ++ ;
} else {
V_53 -> V_61 [ V_53 -> V_73 ] = V_25 ;
V_53 -> V_85 [ V_53 -> V_73 ] = V_2 ;
V_53 -> V_73 ++ ;
}
}
}
static int F_72 ( struct V_106 * V_107 )
{
struct V_9 * V_10 = & V_107 -> V_10 ;
struct V_108 * V_109 = V_10 -> V_110 ;
struct V_8 * V_22 ;
struct V_52 * V_53 ;
struct V_9 * V_111 ;
struct V_112 * V_54 ;
int V_113 = 0 ;
V_54 = F_73 ( V_107 , V_114 , 0 ) ;
if ( ! F_74 ( V_10 , V_54 -> V_115 , V_116 , V_6 ) )
return - V_7 ;
V_53 = F_12 ( V_10 , sizeof( struct V_52 ) , V_30 ) ;
if ( ! V_53 )
return - V_31 ;
V_53 -> V_117 = V_109 -> V_117 ;
V_53 -> V_92 = V_109 -> V_92 ;
V_53 -> V_55 = V_54 -> V_115 ;
F_75 ( & V_53 -> V_68 ) ;
F_76 ( V_107 , V_53 ) ;
V_53 -> V_62 = F_21 ( V_53 , V_118 ) ;
F_66 ( V_53 ) ;
F_67 ( V_53 ) ;
F_70 ( V_53 ) ;
if ( V_53 -> V_66 ) {
V_22 = F_10 ( V_10 ,
& V_119 ,
F_77 ( V_53 -> V_66 ) ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
V_53 -> V_113 [ V_113 ++ ] = V_22 ;
}
if ( V_53 -> V_73 ) {
V_22 = F_10 ( V_10 ,
& V_120 ,
V_53 -> V_73 ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
V_53 -> V_113 [ V_113 ++ ] = V_22 ;
}
if ( V_53 -> V_79 ) {
V_22 = F_10 ( V_10 ,
& V_121 ,
F_77 ( V_53 -> V_79 ) ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
V_53 -> V_113 [ V_113 ++ ] = V_22 ;
}
if ( V_53 -> V_75 ) {
V_22 = F_10 ( V_10 ,
& V_122 ,
V_53 -> V_75 ) ;
if ( F_78 ( V_22 ) )
return F_79 ( V_22 ) ;
V_53 -> V_113 [ V_113 ++ ] = V_22 ;
}
V_53 -> V_113 [ V_113 ++ ] = & V_123 ;
F_80 ( V_10 , L_5 ,
V_124 [ V_53 -> V_117 ] ,
F_18 ( V_53 , V_125 ) ,
F_18 ( V_53 , V_126 ) ,
F_18 ( V_53 , V_127 ) ,
F_18 ( V_53 , V_128 ) ,
F_18 ( V_53 , V_129 ) ) ;
V_111 = F_81 ( V_10 ,
V_130 [ V_53 -> V_117 ] , V_53 , V_53 -> V_113 ) ;
return F_82 ( V_111 ) ;
}
static int F_83 ( struct V_9 * V_10 )
{
struct V_52 * V_53 = F_35 ( V_10 ) ;
F_36 ( & V_53 -> V_68 ) ;
V_53 -> V_131 = F_18 ( V_53 , V_100 ) ;
F_41 ( & V_53 -> V_68 ) ;
return 0 ;
}
static int F_84 ( struct V_9 * V_10 )
{
struct V_52 * V_53 = F_33 ( V_10 ) ;
F_36 ( & V_53 -> V_68 ) ;
F_22 ( V_53 , V_100 , V_53 -> V_131 ) ;
V_53 -> V_72 = false ;
F_41 ( & V_53 -> V_68 ) ;
return 0 ;
}
static int T_7 F_85 ( int V_132 , struct V_108 * V_109 )
{
const char * V_133 ;
int V_55 ;
T_1 V_3 ;
int V_134 ;
if ( ! V_135 ) {
V_133 = F_86 ( V_136 ) ;
if ( ! V_133 || strcmp ( V_133 , L_6 ) )
return - V_137 ;
}
V_134 = F_6 ( V_132 ) ;
if ( V_134 )
return V_134 ;
V_3 = ( F_3 ( V_132 , V_138 ) << 8 )
| F_3 ( V_132 , V_138 + 1 ) ;
switch ( V_3 & V_139 ) {
case V_140 :
V_109 -> V_117 = V_141 ;
break;
default:
if ( V_3 != 0xffff )
F_87 ( L_7 , V_3 ) ;
goto V_142;
}
F_5 ( V_132 , V_93 ) ;
V_3 = ( F_3 ( V_132 , V_143 ) << 8 )
| F_3 ( V_132 , V_143 + 1 ) ;
V_55 = V_3 & V_144 ;
if ( V_55 == 0 ) {
F_88 ( L_8 ) ;
goto V_142;
}
V_3 = F_3 ( V_132 , V_145 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_88 ( L_9 ) ;
goto V_142;
}
F_8 ( V_132 ) ;
F_89 ( L_10 ,
V_124 [ V_109 -> V_117 ] , V_132 , V_55 ) ;
V_109 -> V_92 = V_132 ;
return V_55 ;
V_142:
F_8 ( V_132 ) ;
return - V_137 ;
}
static int T_7 F_90 ( void )
{
struct V_108 V_109 ;
int V_132 [ 2 ] = { 0x2e , 0x4e } ;
struct V_112 V_54 ;
bool V_146 = false ;
int V_147 ;
int V_25 , V_134 ;
V_134 = F_91 ( & V_148 ) ;
if ( V_134 )
return V_134 ;
for ( V_25 = 0 ; V_25 < F_38 ( V_107 ) ; V_25 ++ ) {
V_147 = F_85 ( V_132 [ V_25 ] , & V_109 ) ;
if ( V_147 <= 0 )
continue;
V_146 = true ;
V_107 [ V_25 ] = F_92 ( V_6 , V_147 ) ;
if ( ! V_107 [ V_25 ] ) {
V_134 = - V_31 ;
goto V_149;
}
V_134 = F_93 ( V_107 [ V_25 ] , & V_109 ,
sizeof( struct V_108 ) ) ;
if ( V_134 )
goto V_150;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_33 = V_6 ;
V_54 . V_115 = V_147 + V_151 ;
V_54 . V_152 = V_147 + V_151 + V_116 - 1 ;
V_54 . V_153 = V_114 ;
V_134 = F_94 ( & V_54 ) ;
if ( V_134 ) {
F_95 ( V_107 [ V_25 ] ) ;
V_107 [ V_25 ] = NULL ;
continue;
}
V_134 = F_96 ( V_107 [ V_25 ] , & V_54 , 1 ) ;
if ( V_134 )
goto V_150;
V_134 = F_97 ( V_107 [ V_25 ] ) ;
if ( V_134 )
goto V_150;
}
if ( ! V_146 ) {
V_134 = - V_137 ;
goto V_154;
}
return 0 ;
V_150:
F_95 ( V_107 [ V_25 ] ) ;
V_149:
while ( -- V_25 >= 0 ) {
if ( V_107 [ V_25 ] )
F_98 ( V_107 [ V_25 ] ) ;
}
V_154:
F_99 ( & V_148 ) ;
return V_134 ;
}
static void T_8 F_100 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_38 ( V_107 ) ; V_25 ++ ) {
if ( V_107 [ V_25 ] )
F_98 ( V_107 [ V_25 ] ) ;
}
F_99 ( & V_148 ) ;
}
