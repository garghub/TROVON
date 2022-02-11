static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 )
{
T_1 V_5 ;
T_2 V_6 = V_7 ;
T_2 V_8 ;
V_5 = F_4 ( V_4 -> V_9 , & V_6 , 1 , & V_8 , 1 ) ;
if ( V_5 < 0 ) {
F_5 ( & V_4 -> V_9 -> V_10 , L_1 ,
( int ) V_5 ) ;
return V_5 ;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_4 )
{
T_2 V_6 = V_11 ;
int V_12 ;
T_2 V_8 ;
V_12 = F_4 ( V_4 -> V_9 , & V_6 , 1 , & V_8 , 1 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_4 -> V_9 -> V_10 , L_2 , V_12 ) ;
return V_12 ;
}
return V_8 ;
}
static int F_7 ( struct V_1 * V_4 , T_2 V_8 )
{
V_4 -> V_13 [ 0 ] = V_14 ;
V_4 -> V_13 [ 1 ] = V_8 ;
return F_8 ( V_4 -> V_9 , V_4 -> V_13 , 2 ) ;
}
static inline int F_9 ( struct V_1 * V_4 )
{
T_2 V_6 = V_15 ;
return F_4 ( V_4 -> V_9 , & V_6 , 1 , NULL , 0 ) ;
}
static inline int F_10 ( struct V_1 * V_4 )
{
T_2 V_6 = V_16 ;
return F_4 ( V_4 -> V_9 , & V_6 , 1 , NULL , 0 ) ;
}
static inline int F_11 ( struct V_1 * V_4 , T_3 V_17 , int V_18 )
{
int V_19 ;
bool V_20 = false ;
switch ( F_12 ( V_17 ) ) {
case V_21 :
V_20 = true ;
case V_22 :
case 0xEF :
if ( V_20 )
F_9 ( V_4 ) ;
V_4 -> V_13 [ 0 ] = V_18 ? V_23 : V_24 ;
V_19 = F_8 ( V_4 -> V_9 , V_4 -> V_13 , 1 ) ;
if ( V_20 )
F_10 ( V_4 ) ;
return V_19 ;
default:
V_4 -> V_13 [ 0 ] = V_25 ;
V_4 -> V_13 [ 1 ] = V_18 << 7 ;
return F_8 ( V_4 -> V_9 , V_4 -> V_13 , 2 ) ;
}
}
static int F_13 ( struct V_1 * V_4 )
{
unsigned long V_26 ;
int V_27 ;
V_26 = V_28 + V_29 ;
do {
if ( ( V_27 = F_3 ( V_4 ) ) < 0 )
break;
else if ( ! ( V_27 & V_30 ) )
return 0 ;
F_14 () ;
} while ( ! F_15 ( V_28 , V_26 ) );
return 1 ;
}
static int F_16 ( struct V_1 * V_4 , T_4 V_8 )
{
V_4 -> V_13 [ 0 ] = V_14 ;
V_4 -> V_13 [ 1 ] = V_8 & 0xff ;
V_4 -> V_13 [ 2 ] = ( V_8 >> 8 ) ;
return F_8 ( V_4 -> V_9 , V_4 -> V_13 , 3 ) ;
}
static int F_17 ( struct V_1 * V_4 )
{
int V_12 , V_8 ;
T_2 V_31 [ 2 ] ;
V_31 [ 0 ] = V_14 ;
V_8 = F_3 ( V_4 ) ;
V_31 [ 1 ] = V_8 | V_32 ;
F_9 ( V_4 ) ;
F_8 ( V_4 -> V_9 , & V_31 , 2 ) ;
if ( F_13 ( V_4 ) )
return 1 ;
V_12 = F_3 ( V_4 ) ;
if ( ! ( V_12 > 0 && ( V_12 & V_32 ) ) ) {
F_5 ( & V_4 -> V_9 -> V_10 , L_3 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_4 )
{
int V_12 ;
int V_34 = V_35 << 8 ;
F_9 ( V_4 ) ;
V_12 = F_16 ( V_4 , V_34 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_4 -> V_9 -> V_10 ,
L_4 ) ;
return - V_33 ;
}
V_12 = F_6 ( V_4 ) ;
if ( ! ( V_12 > 0 && ( V_12 & V_35 ) ) ) {
F_5 ( & V_4 -> V_9 -> V_10 , L_5 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_4 , T_3 V_17 )
{
int V_19 ;
switch ( F_12 ( V_17 ) ) {
case V_22 :
V_19 = F_17 ( V_4 ) ;
if ( V_19 ) {
F_5 ( & V_4 -> V_9 -> V_10 ,
L_6 ) ;
return - V_33 ;
}
return V_19 ;
default:
V_19 = F_18 ( V_4 ) ;
if ( V_19 ) {
F_5 ( & V_4 -> V_9 -> V_10 ,
L_7 ) ;
return - V_33 ;
}
return V_19 ;
}
}
static int F_20 ( struct V_1 * V_4 )
{
F_21 ( L_8 , F_22 ( & V_4 -> V_9 -> V_10 ) , V_36 ,
( long long ) ( V_4 -> V_3 . V_37 >> 10 ) ) ;
if ( F_13 ( V_4 ) )
return 1 ;
F_9 ( V_4 ) ;
V_4 -> V_13 [ 0 ] = V_38 ;
F_8 ( V_4 -> V_9 , V_4 -> V_13 , 1 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_4 , unsigned int V_39 , T_2 * V_31 )
{
V_31 [ 1 ] = V_39 >> ( V_4 -> V_40 * 8 - 8 ) ;
V_31 [ 2 ] = V_39 >> ( V_4 -> V_40 * 8 - 16 ) ;
V_31 [ 3 ] = V_39 >> ( V_4 -> V_40 * 8 - 24 ) ;
V_31 [ 4 ] = V_39 >> ( V_4 -> V_40 * 8 - 32 ) ;
}
static int F_24 ( struct V_1 * V_4 )
{
return 1 + V_4 -> V_40 ;
}
static int F_25 ( struct V_1 * V_4 , T_3 V_41 )
{
F_21 ( L_9 , F_22 ( & V_4 -> V_9 -> V_10 ) ,
V_36 , V_4 -> V_3 . V_42 / 1024 , V_41 ) ;
if ( F_13 ( V_4 ) )
return 1 ;
F_9 ( V_4 ) ;
V_4 -> V_13 [ 0 ] = V_4 -> V_43 ;
F_23 ( V_4 , V_41 , V_4 -> V_13 ) ;
F_8 ( V_4 -> V_9 , V_4 -> V_13 , F_24 ( V_4 ) ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_44 * V_45 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_39 , V_46 ;
T_5 V_47 ;
F_21 ( L_10 , F_22 ( & V_4 -> V_9 -> V_10 ) ,
V_36 , ( long long ) V_45 -> V_39 ,
( long long ) V_45 -> V_46 ) ;
F_27 ( V_45 -> V_46 , V_3 -> V_42 , & V_47 ) ;
if ( V_47 )
return - V_33 ;
V_39 = V_45 -> V_39 ;
V_46 = V_45 -> V_46 ;
F_28 ( & V_4 -> V_48 ) ;
if ( V_46 == V_4 -> V_3 . V_37 ) {
if ( F_20 ( V_4 ) ) {
V_45 -> V_49 = V_50 ;
F_29 ( & V_4 -> V_48 ) ;
return - V_51 ;
}
} else {
while ( V_46 ) {
if ( F_25 ( V_4 , V_39 ) ) {
V_45 -> V_49 = V_50 ;
F_29 ( & V_4 -> V_48 ) ;
return - V_51 ;
}
V_39 += V_3 -> V_42 ;
V_46 -= V_3 -> V_42 ;
}
}
F_29 ( & V_4 -> V_48 ) ;
V_45 -> V_49 = V_52 ;
F_30 ( V_45 ) ;
return 0 ;
}
static inline int F_31 ( struct V_1 * V_4 )
{
switch ( V_4 -> V_53 ) {
case V_54 :
case V_55 :
return 1 ;
case V_56 :
return 0 ;
default:
F_5 ( & V_4 -> V_9 -> V_10 , L_11 ) ;
return - 1 ;
}
}
static inline unsigned int F_32 ( const struct V_1 * V_4 )
{
switch ( V_4 -> V_53 ) {
case V_55 :
return 4 ;
default:
return 0 ;
}
}
static int F_33 ( struct V_2 * V_3 , T_6 V_57 , T_7 V_46 ,
T_7 * V_58 , T_8 * V_59 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_60 V_61 [ 2 ] ;
struct V_62 V_63 ;
T_9 V_64 ;
int V_65 ;
F_21 ( L_12 , F_22 ( & V_4 -> V_9 -> V_10 ) ,
V_36 , ( T_3 ) V_57 , V_46 ) ;
F_34 ( & V_63 ) ;
memset ( V_61 , 0 , ( sizeof V_61 ) ) ;
V_65 = F_31 ( V_4 ) ;
if ( V_65 < 0 ) {
F_5 ( & V_4 -> V_9 -> V_10 , L_13 ) ;
return - V_33 ;
}
V_61 [ 0 ] . V_66 = V_4 -> V_13 ;
V_61 [ 0 ] . V_46 = F_24 ( V_4 ) + V_65 ;
F_35 ( & V_61 [ 0 ] , & V_63 ) ;
V_61 [ 1 ] . V_67 = V_59 ;
V_61 [ 1 ] . V_68 = F_32 ( V_4 ) ;
V_61 [ 1 ] . V_46 = V_46 ;
F_35 ( & V_61 [ 1 ] , & V_63 ) ;
F_28 ( & V_4 -> V_48 ) ;
if ( F_13 ( V_4 ) ) {
F_29 ( & V_4 -> V_48 ) ;
return 1 ;
}
V_64 = V_4 -> V_69 ;
V_4 -> V_13 [ 0 ] = V_64 ;
F_23 ( V_4 , V_57 , V_4 -> V_13 ) ;
F_36 ( V_4 -> V_9 , & V_63 ) ;
* V_58 = V_63 . V_70 - F_24 ( V_4 ) - V_65 ;
F_29 ( & V_4 -> V_48 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , T_6 V_71 , T_7 V_46 ,
T_7 * V_58 , const T_8 * V_59 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_72 , V_73 ;
struct V_60 V_61 [ 2 ] ;
struct V_62 V_63 ;
F_21 ( L_14 , F_22 ( & V_4 -> V_9 -> V_10 ) ,
V_36 , ( T_3 ) V_71 , V_46 ) ;
F_34 ( & V_63 ) ;
memset ( V_61 , 0 , ( sizeof V_61 ) ) ;
V_61 [ 0 ] . V_66 = V_4 -> V_13 ;
V_61 [ 0 ] . V_46 = F_24 ( V_4 ) ;
F_35 ( & V_61 [ 0 ] , & V_63 ) ;
V_61 [ 1 ] . V_66 = V_59 ;
F_35 ( & V_61 [ 1 ] , & V_63 ) ;
F_28 ( & V_4 -> V_48 ) ;
if ( F_13 ( V_4 ) ) {
F_29 ( & V_4 -> V_48 ) ;
return 1 ;
}
F_9 ( V_4 ) ;
V_4 -> V_13 [ 0 ] = V_4 -> V_74 ;
F_23 ( V_4 , V_71 , V_4 -> V_13 ) ;
V_72 = V_71 & ( V_4 -> V_73 - 1 ) ;
if ( V_72 + V_46 <= V_4 -> V_73 ) {
V_61 [ 1 ] . V_46 = V_46 ;
F_36 ( V_4 -> V_9 , & V_63 ) ;
* V_58 = V_63 . V_70 - F_24 ( V_4 ) ;
} else {
T_3 V_75 ;
V_73 = V_4 -> V_73 - V_72 ;
V_61 [ 1 ] . V_46 = V_73 ;
F_36 ( V_4 -> V_9 , & V_63 ) ;
* V_58 = V_63 . V_70 - F_24 ( V_4 ) ;
for ( V_75 = V_73 ; V_75 < V_46 ; V_75 += V_73 ) {
V_73 = V_46 - V_75 ;
if ( V_73 > V_4 -> V_73 )
V_73 = V_4 -> V_73 ;
F_23 ( V_4 , V_71 + V_75 , V_4 -> V_13 ) ;
V_61 [ 1 ] . V_66 = V_59 + V_75 ;
V_61 [ 1 ] . V_46 = V_73 ;
F_13 ( V_4 ) ;
F_9 ( V_4 ) ;
F_36 ( V_4 -> V_9 , & V_63 ) ;
* V_58 += V_63 . V_70 - F_24 ( V_4 ) ;
}
}
F_29 ( & V_4 -> V_48 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , T_6 V_71 , T_7 V_46 ,
T_7 * V_58 , const T_8 * V_59 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_60 V_61 [ 2 ] ;
struct V_62 V_63 ;
T_7 V_76 ;
int V_77 , V_12 ;
F_21 ( L_14 , F_22 ( & V_4 -> V_9 -> V_10 ) ,
V_36 , ( T_3 ) V_71 , V_46 ) ;
F_34 ( & V_63 ) ;
memset ( V_61 , 0 , ( sizeof V_61 ) ) ;
V_61 [ 0 ] . V_66 = V_4 -> V_13 ;
V_61 [ 0 ] . V_46 = F_24 ( V_4 ) ;
F_35 ( & V_61 [ 0 ] , & V_63 ) ;
V_61 [ 1 ] . V_66 = V_59 ;
F_35 ( & V_61 [ 1 ] , & V_63 ) ;
F_28 ( & V_4 -> V_48 ) ;
V_12 = F_13 ( V_4 ) ;
if ( V_12 )
goto V_78;
F_9 ( V_4 ) ;
V_76 = V_71 % 2 ;
if ( V_76 ) {
V_4 -> V_13 [ 0 ] = V_79 ;
F_23 ( V_4 , V_71 , V_4 -> V_13 ) ;
V_61 [ 1 ] . V_46 = 1 ;
F_36 ( V_4 -> V_9 , & V_63 ) ;
V_12 = F_13 ( V_4 ) ;
if ( V_12 )
goto V_78;
* V_58 += V_63 . V_70 - F_24 ( V_4 ) ;
}
V_71 += V_76 ;
V_4 -> V_13 [ 0 ] = V_80 ;
F_23 ( V_4 , V_71 , V_4 -> V_13 ) ;
V_77 = F_24 ( V_4 ) ;
for (; V_76 < V_46 - 1 ; V_76 += 2 ) {
V_61 [ 0 ] . V_46 = V_77 ;
V_61 [ 1 ] . V_46 = 2 ;
V_61 [ 1 ] . V_66 = V_59 + V_76 ;
F_36 ( V_4 -> V_9 , & V_63 ) ;
V_12 = F_13 ( V_4 ) ;
if ( V_12 )
goto V_78;
* V_58 += V_63 . V_70 - V_77 ;
V_77 = 1 ;
V_71 += 2 ;
}
F_10 ( V_4 ) ;
V_12 = F_13 ( V_4 ) ;
if ( V_12 )
goto V_78;
if ( V_76 != V_46 ) {
F_9 ( V_4 ) ;
V_4 -> V_13 [ 0 ] = V_79 ;
F_23 ( V_4 , V_71 , V_4 -> V_13 ) ;
V_61 [ 0 ] . V_46 = F_24 ( V_4 ) ;
V_61 [ 1 ] . V_46 = 1 ;
V_61 [ 1 ] . V_66 = V_59 + V_76 ;
F_36 ( V_4 -> V_9 , & V_63 ) ;
V_12 = F_13 ( V_4 ) ;
if ( V_12 )
goto V_78;
* V_58 += V_63 . V_70 - F_24 ( V_4 ) ;
F_10 ( V_4 ) ;
}
V_78:
F_29 ( & V_4 -> V_48 ) ;
return V_12 ;
}
static int F_39 ( struct V_2 * V_3 , T_6 V_81 , T_10 V_46 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_41 = V_81 ;
T_9 V_82 , V_83 ;
int V_84 = 0 ;
F_28 ( & V_4 -> V_48 ) ;
if ( F_13 ( V_4 ) ) {
V_84 = 1 ;
goto V_85;
}
V_82 = F_3 ( V_4 ) ;
if ( V_41 < V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 2 ) )
V_83 = V_82 | V_86 | V_87 | V_88 ;
else if ( V_41 < V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 4 ) )
V_83 = ( V_82 & ~ V_88 ) | V_86 | V_87 ;
else if ( V_41 < V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 8 ) )
V_83 = ( V_82 & ~ V_87 ) | V_86 | V_88 ;
else if ( V_41 < V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 16 ) )
V_83 = ( V_82 & ~ ( V_88 | V_87 ) ) | V_86 ;
else if ( V_41 < V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 32 ) )
V_83 = ( V_82 & ~ V_86 ) | V_87 | V_88 ;
else if ( V_41 < V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 64 ) )
V_83 = ( V_82 & ~ ( V_86 | V_88 ) ) | V_87 ;
else
V_83 = ( V_82 & ~ ( V_86 | V_87 ) ) | V_88 ;
if ( ( V_83 & ( V_86 | V_87 | V_88 ) ) >
( V_82 & ( V_86 | V_87 | V_88 ) ) ) {
F_9 ( V_4 ) ;
if ( F_7 ( V_4 , V_83 ) < 0 ) {
V_84 = 1 ;
goto V_85;
}
}
V_85: F_29 ( & V_4 -> V_48 ) ;
return V_84 ;
}
static int F_40 ( struct V_2 * V_3 , T_6 V_81 , T_10 V_46 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_5 V_41 = V_81 ;
T_9 V_82 , V_83 ;
int V_84 = 0 ;
F_28 ( & V_4 -> V_48 ) ;
if ( F_13 ( V_4 ) ) {
V_84 = 1 ;
goto V_85;
}
V_82 = F_3 ( V_4 ) ;
if ( V_41 + V_46 > V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 64 ) )
V_83 = V_82 & ~ ( V_86 | V_87 | V_88 ) ;
else if ( V_41 + V_46 > V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 32 ) )
V_83 = ( V_82 & ~ ( V_86 | V_87 ) ) | V_88 ;
else if ( V_41 + V_46 > V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 16 ) )
V_83 = ( V_82 & ~ ( V_86 | V_88 ) ) | V_87 ;
else if ( V_41 + V_46 > V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 8 ) )
V_83 = ( V_82 & ~ V_86 ) | V_87 | V_88 ;
else if ( V_41 + V_46 > V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 4 ) )
V_83 = ( V_82 & ~ ( V_88 | V_87 ) ) | V_86 ;
else if ( V_41 + V_46 > V_4 -> V_3 . V_37 - ( V_4 -> V_3 . V_37 / 2 ) )
V_83 = ( V_82 & ~ V_87 ) | V_86 | V_88 ;
else
V_83 = ( V_82 & ~ V_88 ) | V_86 | V_87 ;
if ( ( V_83 & ( V_86 | V_87 | V_88 ) ) <
( V_82 & ( V_86 | V_87 | V_88 ) ) ) {
F_9 ( V_4 ) ;
if ( F_7 ( V_4 , V_83 ) < 0 ) {
V_84 = 1 ;
goto V_85;
}
}
V_85: F_29 ( & V_4 -> V_48 ) ;
return V_84 ;
}
static const struct V_89 * F_41 ( struct V_90 * V_9 )
{
int V_91 ;
T_2 V_6 = V_92 ;
T_2 V_93 [ 5 ] ;
T_3 V_94 ;
T_4 V_95 ;
struct V_96 * V_97 ;
V_91 = F_4 ( V_9 , & V_6 , 1 , V_93 , 5 ) ;
if ( V_91 < 0 ) {
F_21 ( L_15 ,
F_22 ( & V_9 -> V_10 ) , V_91 ) ;
return F_42 ( V_91 ) ;
}
V_94 = V_93 [ 0 ] ;
V_94 = V_94 << 8 ;
V_94 |= V_93 [ 1 ] ;
V_94 = V_94 << 8 ;
V_94 |= V_93 [ 2 ] ;
V_95 = V_93 [ 3 ] << 8 | V_93 [ 4 ] ;
for ( V_91 = 0 ; V_91 < F_43 ( V_98 ) - 1 ; V_91 ++ ) {
V_97 = ( void * ) V_98 [ V_91 ] . V_99 ;
if ( V_97 -> V_17 == V_94 ) {
if ( V_97 -> V_100 != 0 && V_97 -> V_100 != V_95 )
continue;
return & V_98 [ V_91 ] ;
}
}
F_5 ( & V_9 -> V_10 , L_16 , V_94 ) ;
return F_42 ( - V_101 ) ;
}
static int F_44 ( struct V_90 * V_9 )
{
const struct V_89 * V_93 = F_45 ( V_9 ) ;
struct V_102 * V_103 ;
struct V_1 * V_4 ;
struct V_96 * V_97 ;
unsigned V_75 ;
struct V_104 V_105 ;
struct V_106 * V_107 = V_9 -> V_10 . V_108 ;
int V_12 ;
V_103 = F_46 ( & V_9 -> V_10 ) ;
if ( V_103 && V_103 -> type ) {
const struct V_89 * V_109 ;
for ( V_75 = 0 ; V_75 < F_43 ( V_98 ) - 1 ; V_75 ++ ) {
V_109 = & V_98 [ V_75 ] ;
if ( strcmp ( V_103 -> type , V_109 -> V_110 ) )
continue;
break;
}
if ( V_75 < F_43 ( V_98 ) - 1 )
V_93 = V_109 ;
else
F_47 ( & V_9 -> V_10 , L_17 , V_103 -> type ) ;
}
V_97 = ( void * ) V_93 -> V_99 ;
if ( V_97 -> V_17 ) {
const struct V_89 * V_111 ;
V_111 = F_41 ( V_9 ) ;
if ( F_48 ( V_111 ) ) {
return F_49 ( V_111 ) ;
} else if ( V_111 != V_93 ) {
F_47 ( & V_9 -> V_10 , L_18 ,
V_111 -> V_110 , V_93 -> V_110 ) ;
V_93 = V_111 ;
V_97 = ( void * ) V_111 -> V_99 ;
}
}
V_4 = F_50 ( & V_9 -> V_10 , sizeof( * V_4 ) , V_112 ) ;
if ( ! V_4 )
return - V_113 ;
V_4 -> V_13 = F_50 ( & V_9 -> V_10 , V_114 , V_112 ) ;
if ( ! V_4 -> V_13 )
return - V_113 ;
V_4 -> V_9 = V_9 ;
F_51 ( & V_4 -> V_48 ) ;
F_52 ( V_9 , V_4 ) ;
if ( F_12 ( V_97 -> V_17 ) == V_115 ||
F_12 ( V_97 -> V_17 ) == V_116 ||
F_12 ( V_97 -> V_17 ) == V_117 ) {
F_9 ( V_4 ) ;
F_7 ( V_4 , 0 ) ;
}
if ( V_103 && V_103 -> V_110 )
V_4 -> V_3 . V_110 = V_103 -> V_110 ;
else
V_4 -> V_3 . V_110 = F_22 ( & V_9 -> V_10 ) ;
V_4 -> V_3 . type = V_118 ;
V_4 -> V_3 . V_119 = 1 ;
V_4 -> V_3 . V_120 = V_121 ;
V_4 -> V_3 . V_37 = V_97 -> V_122 * V_97 -> V_123 ;
V_4 -> V_3 . V_124 = F_26 ;
V_4 -> V_3 . V_125 = F_33 ;
if ( F_12 ( V_97 -> V_17 ) == V_21 ) {
V_4 -> V_3 . V_126 = F_39 ;
V_4 -> V_3 . V_127 = F_40 ;
}
if ( V_97 -> V_120 & V_128 )
V_4 -> V_3 . V_129 = F_38 ;
else
V_4 -> V_3 . V_129 = F_37 ;
if ( V_97 -> V_120 & V_130 ) {
V_4 -> V_43 = V_131 ;
V_4 -> V_3 . V_42 = 4096 ;
} else if ( V_97 -> V_120 & V_132 ) {
V_4 -> V_43 = V_133 ;
V_4 -> V_3 . V_42 = 4096 ;
} else {
V_4 -> V_43 = V_134 ;
V_4 -> V_3 . V_42 = V_97 -> V_122 ;
}
if ( V_97 -> V_120 & V_135 )
V_4 -> V_3 . V_120 |= V_136 ;
V_105 . V_108 = V_9 -> V_10 . V_108 ;
V_4 -> V_3 . V_10 . V_137 = & V_9 -> V_10 ;
V_4 -> V_73 = V_97 -> V_73 ;
V_4 -> V_3 . V_138 = V_4 -> V_73 ;
if ( V_107 ) {
if ( F_53 ( V_107 , L_19 ) )
V_4 -> V_53 = V_54 ;
else
V_4 -> V_53 = V_56 ;
} else {
V_4 -> V_53 = V_54 ;
}
if ( V_97 -> V_120 & V_139 )
V_4 -> V_53 = V_56 ;
if ( V_9 -> V_140 & V_141 && V_97 -> V_120 & V_142 ) {
V_12 = F_19 ( V_4 , V_97 -> V_17 ) ;
if ( V_12 ) {
F_5 ( & V_4 -> V_9 -> V_10 , L_20 ) ;
return V_12 ;
}
V_4 -> V_53 = V_55 ;
}
switch ( V_4 -> V_53 ) {
case V_55 :
V_4 -> V_69 = V_143 ;
break;
case V_54 :
V_4 -> V_69 = V_144 ;
break;
case V_56 :
V_4 -> V_69 = V_145 ;
break;
default:
F_5 ( & V_4 -> V_9 -> V_10 , L_21 ) ;
return - V_33 ;
}
V_4 -> V_74 = V_146 ;
if ( V_97 -> V_40 )
V_4 -> V_40 = V_97 -> V_40 ;
else if ( V_4 -> V_3 . V_37 > 0x1000000 ) {
V_4 -> V_40 = 4 ;
if ( F_12 ( V_97 -> V_17 ) == V_147 ) {
switch ( V_4 -> V_53 ) {
case V_55 :
V_4 -> V_69 = V_148 ;
break;
case V_54 :
V_4 -> V_69 = V_149 ;
break;
case V_56 :
V_4 -> V_69 = V_150 ;
break;
}
V_4 -> V_74 = V_151 ;
V_4 -> V_43 = V_152 ;
V_4 -> V_3 . V_42 = V_97 -> V_122 ;
} else
F_11 ( V_4 , V_97 -> V_17 , 1 ) ;
} else {
V_4 -> V_40 = 3 ;
}
F_54 ( & V_9 -> V_10 , L_22 , V_93 -> V_110 ,
( long long ) V_4 -> V_3 . V_37 >> 10 ) ;
F_21 ( L_23
L_24 ,
V_4 -> V_3 . V_110 ,
( long long ) V_4 -> V_3 . V_37 , ( long long ) ( V_4 -> V_3 . V_37 >> 20 ) ,
V_4 -> V_3 . V_42 , V_4 -> V_3 . V_42 / 1024 ,
V_4 -> V_3 . V_153 ) ;
if ( V_4 -> V_3 . V_153 )
for ( V_75 = 0 ; V_75 < V_4 -> V_3 . V_153 ; V_75 ++ )
F_21 ( L_25
L_26
L_27 ,
V_75 , ( long long ) V_4 -> V_3 . V_154 [ V_75 ] . V_41 ,
V_4 -> V_3 . V_154 [ V_75 ] . V_42 ,
V_4 -> V_3 . V_154 [ V_75 ] . V_42 / 1024 ,
V_4 -> V_3 . V_154 [ V_75 ] . V_155 ) ;
return F_55 ( & V_4 -> V_3 , NULL , & V_105 ,
V_103 ? V_103 -> V_156 : NULL ,
V_103 ? V_103 -> V_157 : 0 ) ;
}
static int F_56 ( struct V_90 * V_9 )
{
struct V_1 * V_4 = F_57 ( V_9 ) ;
return F_58 ( & V_4 -> V_3 ) ;
}
